//  Copyright John Maddock 2007.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Basic sanity check that header <boost/math/special_functions/expint.hpp>
// #includes all the files that it needs to.
//
#include <boost/math/special_functions/expint.hpp>
//
// Note this header includes no other headers, this is
// important if this test is to be meaningful:
//
#include "test_compile_result.hpp"

void compile_and_link_test()
{
   check_result<float>(_Boost::math::expint(f));
   check_result<double>(_Boost::math::expint(d));
#ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
   check_result<long double>(_Boost::math::expint(l));
#endif
   check_result<float>(_Boost::math::expint(u, f));
   check_result<double>(_Boost::math::expint(u, d));
#ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
   check_result<long double>(_Boost::math::expint(u, l));
#endif
}
