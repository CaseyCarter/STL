//  Copyright John Maddock 2007-8.
//  Copyright Paul A. Bristow 2009, 2011

//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//
// This tests two things: that _Boost::math::ntl::RR meets our
// conceptual requirements, and that we can instantiate
// all our distributions and special functions on this type.
//

#ifdef _MSC_VER
#  pragma warning (disable : 4100) // unreferenced formal parameter
#endif



#define BOOST_MATH_ASSERT_UNDEFINED_POLICY false

#include <boost/math/bindings/rr.hpp>
#include <boost/math/concepts/real_type_concept.hpp>
#include "compile_test/instantiate.hpp"

void foo()
{
   instantiate(_Boost::math::ntl::RR());
}

int main()
{
   BOOST_CONCEPT_ASSERT((_Boost::math::concepts::RealTypeConcept<_Boost::math::ntl::RR>));
}

