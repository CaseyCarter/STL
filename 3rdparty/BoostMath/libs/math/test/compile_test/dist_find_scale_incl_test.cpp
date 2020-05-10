//  Copyright John Maddock 2006.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Basic sanity check that header <boost/math/distributions/find_scale.hpp>
// #includes all the files that it needs to.
//
#include <boost/math/distributions/find_scale.hpp>
//
// Note this header includes no other headers, this is
// important if this test is to be meaningful:
//
#include "test_compile_result.hpp"

template <class T, class Policy = _Boost::math::policies::policy<> >
class test_distribution
{
public:
   typedef T value_type;
   typedef Policy policy_type;
   test_distribution(){}
};

template <class T, class Policy>
T quantile(const test_distribution<T, Policy>&, T)
{
   return 0;
}

template <class T, class Policy>
T quantile(const _Boost::math::complemented2_type<test_distribution<T, Policy>, T>&)
{
   return 0;
}

namespace _Boost{ namespace math{ namespace tools{

   template <class T, class Policy> struct is_distribution<test_distribution<T, Policy> > : public true_type{};
   template <class T, class Policy> struct is_scaled_distribution<test_distribution<T, Policy> > : public true_type{};

}}}

void compile_and_link_test()
{
   check_result<float>(_Boost::math::find_scale<test_distribution<float> >(f, f, f, _Boost::math::policies::policy<>()));
   check_result<double>(_Boost::math::find_scale<test_distribution<double> >(d, d, d, _Boost::math::policies::policy<>()));
   check_result<long double>(_Boost::math::find_scale<test_distribution<long double> >(l, l, l, _Boost::math::policies::policy<>()));

   check_result<float>(_Boost::math::find_scale<test_distribution<float> >(f, f, f));
   check_result<double>(_Boost::math::find_scale<test_distribution<double> >(d, d, d));
   check_result<long double>(_Boost::math::find_scale<test_distribution<long double> >(l, l, l));

   check_result<float>(_Boost::math::find_scale<test_distribution<float> >(_Boost::math::complement(f, f, f, _Boost::math::policies::policy<>())));
   check_result<double>(_Boost::math::find_scale<test_distribution<double> >(_Boost::math::complement(d, d, d, _Boost::math::policies::policy<>())));
   check_result<long double>(_Boost::math::find_scale<test_distribution<long double> >(_Boost::math::complement(l, l, l, _Boost::math::policies::policy<>())));

   check_result<float>(_Boost::math::find_scale<test_distribution<float> >(_Boost::math::complement(f, f, f)));
   check_result<double>(_Boost::math::find_scale<test_distribution<double> >(_Boost::math::complement(d, d, d)));
   check_result<long double>(_Boost::math::find_scale<test_distribution<long double> >(_Boost::math::complement(l, l, l)));
}

