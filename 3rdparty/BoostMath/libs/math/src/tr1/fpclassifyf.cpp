//  Copyright John Maddock 2008.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0.  (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#  include <pch.hpp>
#ifndef BOOST_MATH_TR1_SOURCE
#  define BOOST_MATH_TR1_SOURCE
#endif
#include <boost/math/tr1.hpp>
#include <boost/math/special_functions/fpclassify.hpp>
#include <boost/math/special_functions/sign.hpp>
#include "c_policy.hpp"

#if defined (_MSC_VER)
#  pragma warning(push)
#  pragma warning (disable: 4800) // 'int' : forcing value to bool 'true' or 'false' (performance warning)
#endif

namespace _Boost{ namespace math{ namespace tr1{

template<> bool BOOST_MATH_TR1_DECL signbit<float> BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{
   return static_cast<bool>((_Boost::math::signbit)(x));
}

template<> int BOOST_MATH_TR1_DECL fpclassify<float> BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{
   return (_Boost::math::fpclassify)(x);
}

template<> bool BOOST_MATH_TR1_DECL isfinite<float> BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{
   return (_Boost::math::isfinite)(x);
}

template<> bool BOOST_MATH_TR1_DECL isinf<float> BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{
   return (_Boost::math::isinf)(x);
}

template<> bool BOOST_MATH_TR1_DECL isnan<float> BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{
   return (_Boost::math::isnan)(x);
}

template<> bool BOOST_MATH_TR1_DECL isnormal<float> BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{
   return (_Boost::math::isnormal)(x);
}

}}} // namespace _Boost{ namespace math{ namespace tr1{

#if defined (_MSC_VER)
#  pragma warning(pop)
#endif


