//  Copyright John Maddock 2006.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Basic sanity check that header <boost/math/tools/test.hpp>
// #includes all the files that it needs to.
//
#include <boost/math/tools/test.hpp>
#include <boost/array.hpp>
//
// Note this header includes no other headers, this is
// important if this test is to be meaningful:
//
inline void check_result_imp(_Boost::math::tools::test_result<double>, _Boost::math::tools::test_result<double>){}

#include "test_compile_result.hpp"


void compile_and_link_test()
{
   check_result<float>(_Boost::math::tools::relative_error<float>(f, f));

   #define A _Boost::array<_Boost::array<double, 2>, 2>
   typedef double (*F1)(const _Boost::array<double, 2>&);
   typedef F1 F2;
   A a;
   F1 f1 = 0;
   F2 f2 = 0;

   check_result<_Boost::math::tools::test_result<
      _Boost::math::tools::calculate_result_type<A>::value_type> >
      (_Boost::math::tools::test<A, F1, F2>(a, f1, f2));

}

