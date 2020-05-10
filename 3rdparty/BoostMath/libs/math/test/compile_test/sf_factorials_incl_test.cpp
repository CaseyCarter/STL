//  Copyright John Maddock 2006.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Basic sanity check that header <boost/math/special_functions/factorials.hpp>
// #includes all the files that it needs to.
//
#include <boost/math/special_functions/factorials.hpp>
//
// Note this header includes no other headers, this is
// important if this test is to be meaningful:
//
#include "test_compile_result.hpp"

void compile_and_link_test()
{
   check_result<float>(_Boost::math::factorial<float>(u));
   check_result<double>(_Boost::math::factorial<double>(u));
#ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
   check_result<long double>(_Boost::math::factorial<long double>(u));
#endif

   check_result<float>(_Boost::math::double_factorial<float>(u));
   check_result<double>(_Boost::math::double_factorial<double>(u));
#ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
   check_result<long double>(_Boost::math::double_factorial<long double>(u));
#endif

   check_result<float>(_Boost::math::rising_factorial<float>(f, i));
   check_result<double>(_Boost::math::rising_factorial<double>(d, i));
#ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
   check_result<long double>(_Boost::math::rising_factorial<long double>(l, i));
#endif

   check_result<float>(_Boost::math::falling_factorial<float>(f, u));
   check_result<double>(_Boost::math::falling_factorial<double>(d, u));
#ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
   check_result<long double>(_Boost::math::falling_factorial<long double>(l, u));
#endif

   //
   // Add constexpr tests here:
   //
#ifdef BOOST_MATH_HAVE_CONSTEXPR_TABLES
   constexpr float ce_f = _Boost::math::unchecked_factorial<float>(2);
   constexpr double ce_d = _Boost::math::unchecked_factorial<double>(2);
   constexpr long double ce_l = _Boost::math::unchecked_factorial<long double>(2);
   check_result<float>(ce_f);
   check_result<double>(ce_d);
   check_result<long double>(ce_l);
#ifdef BOOST_MATH_USE_FLOAT128
   constexpr __float128 ce_q = _Boost::math::unchecked_factorial<__float128>(2);
   check_result<__float128>(ce_q);
#endif
#endif
}

