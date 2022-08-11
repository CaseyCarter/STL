// Copyright (c) Microsoft Corporation.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include <algorithm>
#include <cassert>
#include <ranges>

#include <range_algorithm_support.hpp>

using namespace std;

struct instantiator {
    template <ranges::output_range<const int&> Out>
    static constexpr void call() {
        using ranges::generate_n, ranges::equal, ranges::iterator_t;

        const auto iota_gen = [val = 0]() mutable { return val++; };

        {
            int output[] = {13, 42, 1367};
            Out out_wrapper{output};
            using D                              = ranges::range_difference_t<Out>;
            const auto n                         = static_cast<D>(ranges::size(output));
            same_as<iterator_t<Out>> auto result = generate_n(out_wrapper.begin(), n, iota_gen);
            assert(result == out_wrapper.end());
            for (D i = 0; i < n; ++i) {
                assert(i == output[i]);
            }
        }

        constexpr int expected_output[] = {13, 42, 1367};
        int output[]                    = {13, 42, 1367};
        {
            Out out_wrapper{output};
            same_as<iterator_t<Out>> auto result = generate_n(out_wrapper.begin(), 0, iota_gen);
            assert(result.peek() == output);
            assert(equal(output, expected_output));
        }
        {
            Out out_wrapper{output};
            same_as<iterator_t<Out>> auto result = generate_n(out_wrapper.begin(), -1, iota_gen);
            assert(result.peek() == output);
            assert(equal(output, expected_output));
        }
    }
};

int main() {
    STATIC_ASSERT((test_out<instantiator, int>(), true));
    test_out<instantiator, int>();
}
