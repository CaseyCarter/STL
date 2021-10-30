// Copyright (c) Microsoft Corporation.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include <algorithm>
#include <array>
#include <cassert>
#include <ranges>
#include <span>
#include <utility>
#include <vector>

#include <range_algorithm_support.hpp>

using namespace std;

constexpr void smoke_test() {
    using ranges::find_end, ranges::iterator_t, ranges::subrange;
    using P = pair<int, int>;

    // Validate dangling story
    STATIC_ASSERT(same_as<decltype(find_end(borrowed<false>{}, array<int, 42>{})), ranges::dangling>);
    STATIC_ASSERT(same_as<decltype(find_end(borrowed<true>{}, array<int, 42>{})), subrange<int*>>);

    const array pairs = {P{0, 42}, P{1, 42}, P{0, 42}, P{1, 42}, P{0, 42}, P{1, 42}, P{0, 42}};

    const auto pred = [](const int x, const int y) { return x == y + 1; };

    const array good_needle = {-1, 0};
    {
        // Validate range overload [found case]
        const auto result = find_end(pairs, good_needle, pred, get_first);
        STATIC_ASSERT(same_as<decltype(result), const subrange<iterator_t<decltype(pairs)>>>);
        assert(result.size() == 2);
        assert(result.begin() == pairs.begin() + 4);
        assert(result.end() == pairs.begin() + 6);
    }
    {
        // Validate iterator + sentinel overload [found case]
        const auto result =
            find_end(pairs.begin(), pairs.end(), good_needle.begin(), good_needle.end(), pred, get_first);
        STATIC_ASSERT(same_as<decltype(result), const subrange<iterator_t<decltype(pairs)>>>);
        assert(result.size() == 2);
        assert(result.begin() == pairs.begin() + 4);
        assert(result.end() == pairs.begin() + 6);
    }

    const array bad_needle = {0, 0};
    {
        // Validate range overload [not found case]
        const auto result = find_end(pairs, bad_needle, pred, get_first);
        STATIC_ASSERT(same_as<decltype(result), const subrange<iterator_t<decltype(pairs)>>>);
        assert(result.empty());
        assert(result.begin() == pairs.end());
        assert(result.end() == pairs.end());
    }
    {
        // Validate range overload [not found case]
        const auto result = find_end(pairs.begin(), pairs.end(), bad_needle.begin(), bad_needle.end(), pred, get_first);
        STATIC_ASSERT(same_as<decltype(result), const subrange<iterator_t<decltype(pairs)>>>);
        assert(result.empty());
        assert(result.begin() == pairs.end());
        assert(result.end() == pairs.end());
    }

    {
        // Validate the memcmp optimization
        const int haystack[] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
        const int needle[]   = {1, 2, 3};
        const auto result    = find_end(haystack, span<const int>{needle});
        STATIC_ASSERT(same_as<decltype(result), const subrange<const int*>>);
        assert(result.begin() == haystack + 6);
        assert(result.end() == haystack + 9);
    }
}

constexpr void test_devcom_1559808() {
    // Regression test for DevCom-1559808, an interaction between vector and the
    // use of structured bindings in the constexpr evaluator.

    vector<int> haystack(33, 42); // No particular significance to any numbers in this function
    vector<int> needle(8, 42);
    using size_type = vector<int>::size_type;

    auto result = ranges::find_end(haystack, needle);
    assert(static_cast<size_type>(result.begin() - haystack.begin()) == haystack.size() - needle.size());
    assert(result.end() == haystack.end());

    needle.assign(6, 1729);
    result = ranges::find_end(haystack, needle);
    assert(result.begin() == haystack.end());
    assert(result.end() == haystack.end());
}

int main() {
    STATIC_ASSERT((smoke_test(), true));
    smoke_test();

    STATIC_ASSERT((test_devcom_1559808(), true));
    test_devcom_1559808();
}

#ifndef _PREFAST_ // TRANSITION, GH-1030
struct instantiator {
    template <class Fwd1, class Fwd2>
    static void call() {
        if constexpr (!is_permissive) { // These fail to compile in C1XX's permissive mode due to VSO-566808
            using ranges::iterator_t;

            Fwd1 fwd1{span<const int, 0>{}};
            Fwd2 fwd2{span<const int, 0>{}};

            (void) ranges::find_end(fwd1, fwd2);
            (void) ranges::find_end(ranges::begin(fwd1), ranges::end(fwd1), ranges::begin(fwd2), ranges::end(fwd2));

            BinaryPredicateFor<iterator_t<Fwd1>, iterator_t<Fwd2>> pred{};
            (void) ranges::find_end(fwd1, fwd2, pred);
            (void) ranges::find_end(
                ranges::begin(fwd1), ranges::end(fwd1), ranges::begin(fwd2), ranges::end(fwd2), pred);

            HalfProjectedBinaryPredicateFor<iterator_t<Fwd2>> halfpred{};
            ProjectionFor<iterator_t<Fwd1>> halfproj{};
            (void) ranges::find_end(fwd1, fwd2, halfpred, halfproj);
            (void) ranges::find_end(
                ranges::begin(fwd1), ranges::end(fwd1), ranges::begin(fwd2), ranges::end(fwd2), halfpred, halfproj);

            ProjectedBinaryPredicate<0, 1> projpred{};
            ProjectionFor<iterator_t<Fwd1>, 0> proj1{};
            ProjectionFor<iterator_t<Fwd2>, 1> proj2{};
            (void) ranges::find_end(fwd1, fwd2, projpred, proj1, proj2);
            (void) ranges::find_end(
                ranges::begin(fwd1), ranges::end(fwd1), ranges::begin(fwd2), ranges::end(fwd2), projpred, proj1, proj2);
        }
    }
};

template void test_fwd_fwd<instantiator, const int, const int>();
#endif // TRANSITION, GH-1030
