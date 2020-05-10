//  Copyright John Maddock 2006.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Basic sanity check that header <boost/math/distributions/gamma.hpp>
// #includes all the files that it needs to.
//
#include <boost/math/distributions/gamma.hpp>
//
// Note this header includes no other headers, this is
// important if this test is to be meaningful:
//
#include "test_compile_result.hpp"

void compile_and_link_test()
{
   TEST_DIST_FUNC(gamma)
}

template class _Boost::math::gamma_distribution<float, _Boost::math::policies::policy<> >;
template class _Boost::math::gamma_distribution<double, _Boost::math::policies::policy<> >;
#ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
template class _Boost::math::gamma_distribution<long double, _Boost::math::policies::policy<> >;
#endif
