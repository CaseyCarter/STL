//  Copyright John Maddock 2006.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Basic sanity check that header <boost/math/tools/test_data.hpp>
// #includes all the files that it needs to.
//
#include <boost/math/tools/test_data.hpp>

#define T double

template _Boost::math::tools::parameter_info<T> _Boost::math::tools::make_random_param<T>(T start_range, T end_range, int n_points);
template _Boost::math::tools::parameter_info<T> _Boost::math::tools::make_periodic_param<T>(T start_range, T end_range, int n_points);
template _Boost::math::tools::parameter_info<T> _Boost::math::tools::make_power_param<T>(T basis, int start_exponent, int end_exponent);

template class _Boost::math::tools::test_data<T>;

template bool _Boost::math::tools::get_user_parameter_info<T>(_Boost::math::tools::parameter_info<T>& info, const char* param_name);


