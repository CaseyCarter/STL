#include <generator>
//
#include <algorithm>
#include <array>
#include <cassert>
#include <cstdlib>
#include <forward_list>
#include <random>
#include <ranges>
#include <sstream>
#include <vector>

namespace ranges = std::ranges;

static_assert(ranges::input_range<std::generator<int>>);
static_assert(!ranges::forward_range<std::generator<int>>);

static_assert(std::same_as<ranges::range_value_t<std::generator<int>>, int>);
static_assert(std::same_as<ranges::range_difference_t<std::generator<int>>, std::ptrdiff_t>);
static_assert(std::same_as<ranges::range_reference_t<std::generator<int>>, const int&>);
static_assert(std::same_as<ranges::range_rvalue_reference_t<std::generator<int>>, const int&&>);

static_assert(std::same_as<ranges::range_value_t<std::generator<int, const int&>>, int>);
static_assert(std::same_as<ranges::range_difference_t<std::generator<int, const int&>>, std::ptrdiff_t>);
static_assert(std::same_as<ranges::range_reference_t<std::generator<int, const int&>>, const int&>);
static_assert(std::same_as<ranges::range_rvalue_reference_t<std::generator<int, const int&>>, const int&&>);

static_assert(std::same_as<ranges::range_value_t<std::generator<int, int>>, int>);
static_assert(std::same_as<ranges::range_difference_t<std::generator<int, int>>, std::ptrdiff_t>);
static_assert(std::same_as<ranges::range_reference_t<std::generator<int, int>>, int&&>);
static_assert(std::same_as<ranges::range_rvalue_reference_t<std::generator<int, int>>, int&&>);

static_assert(sizeof(std::generator<int>) == sizeof(void*));
static_assert(sizeof(std::generator<int>::promise_type) == 3 * sizeof(void*));
static_assert(sizeof(decltype(std::declval<std::generator<int>&>().begin())) == sizeof(void*));

// From the proposal:
std::generator<int> iota(int start = 0) {
    while (true)
        co_yield start++;
}

void f(std::ostream& os) {
    os << '"';
    for (auto i : iota() | std::views::take(3))
        os << i << ' '; // prints "0 1 2 "
    os << "\"\n";
}

template <ranges::input_range Rng1, ranges::input_range Rng2>
std::generator<std::tuple<ranges::range_reference_t<Rng1>, ranges::range_reference_t<Rng2>>,
    std::tuple<ranges::range_value_t<Rng1>, ranges::range_value_t<Rng2>>>
    zip(Rng1 r1, Rng2 r2) {
    auto it1        = ranges::begin(r1);
    auto it2        = ranges::begin(r2);
    const auto end1 = ranges::end(r1);
    const auto end2 = ranges::end(r2);
    for (; it1 != end1 && it2 != end2; ++it1, ++it2) {
        co_yield {*it1, *it2};
    }
}

// Not from the proposal:
template <class Reference = const int&>
std::generator<int, Reference> meow(const int hi) {
    for (int i = 0; i < hi; ++i) {
        co_yield i;
    }
}

template <ranges::input_range R>
void dump(std::ostream& os, R&& r) {
    os << '{';
    bool first = true;
    for (auto&& e : r) {
        if (first) {
            first = false;
        } else {
            os << ", ";
        }
        os << e;
    }
    os << "}\n";
}

template <class T>
struct stateless_alloc {
    using value_type = T;

    stateless_alloc() = default;

    template <class U>
    constexpr stateless_alloc(const stateless_alloc<U>&) noexcept {}

    T* allocate(const std::size_t n) {
        // std::cerr << "stateless_alloc::allocate(" << n << " * " << sizeof(T) << " == " << n * sizeof(T) << ") = ";

        void* vp;
        if constexpr (alignof(T) > __STDCPP_DEFAULT_NEW_ALIGNMENT__) {
            vp = ::_aligned_malloc(n * sizeof(T), alignof(T));
        } else {
            vp = std::malloc(n * sizeof(T));
        }

        if (vp) {
            // std::cerr << vp << '\n';
            return static_cast<T*>(vp);
        }

        // std::cerr << "bad_alloc\n";
        throw std::bad_alloc{};
    }

    void deallocate(void* const vp, [[maybe_unused]] const std::size_t n) noexcept {
        // std::cerr << "stateless_alloc::deallocate(" << n << " * " << sizeof(T) << " == " << n * sizeof(T) << ")\n";

        if constexpr (alignof(T) > __STDCPP_DEFAULT_NEW_ALIGNMENT__) {
            ::_aligned_free(vp);
        } else {
            std::free(vp);
        }
    }

    template <class U>
    constexpr bool operator==(const stateless_alloc<U>&) noexcept {
        return true;
    }
};
static_assert(std::default_initializable<stateless_alloc<int>>);

template <class T>
struct stateful_alloc {
    using value_type = T;

    int domain;

    explicit stateful_alloc(int dom) noexcept : domain{dom} {}

    template <class U>
    constexpr stateful_alloc(const stateful_alloc<U>& that) noexcept : domain{that.domain} {}

    T* allocate(const std::size_t n) {
        // std::cerr << "stateful_alloc{" << domain << "}::allocate(" << n << " * " << sizeof(T) << " == "
        //           << n * sizeof(T) << ") = ";

        void* vp;
        if constexpr (alignof(T) > __STDCPP_DEFAULT_NEW_ALIGNMENT__) {
            vp = ::_aligned_malloc(n * sizeof(T), alignof(T));
        } else {
            vp = std::malloc(n * sizeof(T));
        }

        if (vp) {
            // std::cerr << vp << '\n';
            return static_cast<T*>(vp);
        }

        // std::cerr << "bad_alloc\n";
        throw std::bad_alloc{};
    }

    void deallocate(void* const vp, [[maybe_unused]] const std::size_t n) noexcept {
        // std::cerr << "stateful_alloc{" << domain << "}::deallocate(" << n << " * " << sizeof(T)
        //           << " == " << n * sizeof(T) << ")\n";

        if constexpr (alignof(T) > __STDCPP_DEFAULT_NEW_ALIGNMENT__) {
            ::_aligned_free(vp);
        } else {
            std::free(vp);
        }
    }

    template <class U>
    constexpr bool operator==(const stateful_alloc<U>& that) noexcept {
        return this->domain == that.domain;
    }
};
static_assert(!std::default_initializable<stateful_alloc<int>>);

void static_allocator_test() {
    // std::cerr << "static_allocator_test:\n";

    {
        auto g = [](const int hi) -> std::generator<int, const int&, stateless_alloc<char>> {
            constexpr std::size_t n = 64;
            int some_ints[n];
            for (int i = 0; i < hi; ++i) {
                co_yield some_ints[i % n] = i;
            }
        };

        assert(ranges::equal(g(1024), ranges::views::iota(0, 1024)));
    }

    {
        auto g = [](std::allocator_arg_t, stateless_alloc<int>,
                     const int hi) -> std::generator<int, const int&, stateless_alloc<char>> {
            constexpr std::size_t n = 64;
            int some_ints[n];
            for (int i = 0; i < hi; ++i) {
                co_yield some_ints[i % n] = i;
            }
        };

        assert(ranges::equal(g(std::allocator_arg, {}, 1024), ranges::views::iota(0, 1024)));
    }

    {
        auto g = [](std::allocator_arg_t, stateful_alloc<int>,
                     const int hi) -> std::generator<int, const int&, stateful_alloc<char>> {
            constexpr std::size_t n = 64;
            int some_ints[n];
            for (int i = 0; i < hi; ++i) {
                co_yield some_ints[i % n] = i;
            }
        };

        assert(ranges::equal(g(std::allocator_arg, stateful_alloc<int>{42}, 1024), ranges::views::iota(0, 1024)));
    }
}

void dynamic_allocator_test() {
    // std::cerr << "dynamic_allocator_test:\n";

    auto g = [](std::allocator_arg_t, const auto&, const int hi) -> std::generator<int> {
        constexpr std::size_t n = 64;
        int some_ints[n];
        for (int i = 0; i < hi; ++i) {
            co_yield some_ints[i % n] = i;
        }
    };

    assert(ranges::equal(g(std::allocator_arg, std::allocator<float>{}, 1024), ranges::views::iota(0, 1024)));
    assert(ranges::equal(g(std::allocator_arg, stateless_alloc<float>{}, 1024), ranges::views::iota(0, 1024)));
    assert(ranges::equal(g(std::allocator_arg, stateful_alloc<float>{1729}, 1024), ranges::views::iota(0, 1024)));
}

void zip_example() {
    int length = 0;
    for (auto&& x : zip(std::array{1, 2, 3}, std::vector{10, 20, 30, 40, 50})) {
        assert(std::get<0>(x) * 10 == std::get<1>(x));
        ++length;
    }
    assert(length == 3);
}

std::generator<int> iota_repeater(const int hi, const int depth) {
    if (depth > 0) {
        co_yield ranges::elements_of(iota_repeater(hi, depth - 1));
        co_yield ranges::elements_of(iota_repeater(hi, depth - 1));
    } else {
        co_yield ranges::elements_of(meow(hi));
    }
}

void recursive_test() {
    struct some_error {};

    static constexpr auto might_throw = []() -> std::generator<int> {
        co_yield 0;
        throw some_error{};
    };

    static constexpr auto nested_ints = []() -> std::generator<int> {
        try {
            co_yield ranges::elements_of(might_throw());
        } catch (const some_error&) {
        }
        co_yield 1;
    };

    assert(ranges::equal(iota_repeater(3, 2), std::array{0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2}));
    assert(ranges::equal(nested_ints(), std::array{0, 1}));
}

void arbitrary_range_test() {
    auto yield_arbitrary_ranges = []() -> std::generator<int> {
        co_yield ranges::elements_of(std::vector<int>{40, 30, 20, 10});
        co_yield ranges::elements_of(ranges::views::iota(0, 4));
        std::forward_list<int> fl{500, 400, 300};
        co_yield ranges::elements_of(fl);
    };

    assert(ranges::equal(yield_arbitrary_ranges(), std::array{40, 30, 20, 10, 0, 1, 2, 3, 500, 400, 300}));
}

int main() {
    {
        std::stringstream ss;
        f(ss);
        assert(ss.str() == "\"0 1 2 \"\n");
    }
    assert(ranges::equal(meow(6), ranges::views::iota(0, 6)));

    {
        // test with mutable lvalue reference type
        auto r   = meow<int&>(32);
        auto pos = r.begin();
        for (int i = 0; i < 16; ++i, ++*pos, ++pos) {
            assert(pos != r.end());
            assert(*pos == 2 * i);
        }
        assert(pos == r.end());
    }

    {
        // test with mutable xvalue reference type
        auto woof = [](std::size_t size, std::size_t count) -> std::generator<std::vector<int>, std::vector<int>> {
            std::random_device rd{};
            std::uniform_int_distribution dist{0, 99};
            std::vector<int> vec;
            while (count-- > 0) {
                vec.resize(size);
                ranges::generate(vec, [&] { return dist(rd); });
                co_yield std::move(vec);
            }
        };

        constexpr size_t size  = 16;
        constexpr size_t count = 4;
        auto r                 = woof(size, count);
        for (auto i = r.begin(); i != r.end(); ++i) {
            std::vector<int> vec = *i;
            assert(vec.size() == size);
            assert((*i).empty());
        }
    }

    static_allocator_test();
    dynamic_allocator_test();

    zip_example();
    recursive_test();
    arbitrary_range_test();
}
