// Copyright John Maddock 2010.

// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/math/constants/info.hpp>
#include <boost/math/concepts/real_concept.hpp>

int main()
{
   _Boost::math::constants::print_info_on_type<float>();
   _Boost::math::constants::print_info_on_type<double>();
   _Boost::math::constants::print_info_on_type<long double>();
   _Boost::math::constants::print_info_on_type<_Boost::math::concepts::real_concept>();

   return 0;
}

/*

------ Rebuild All started: Project: test_print_info_on_type, Configuration: Debug Win32 ------
  test_print_info_on_type.cpp
  test_print_info_on_type.vcxproj -> J:\Cpp\math_constants\Debug\test_print_info_on_type.exe
  Information on the Implementation and Handling of 
  Mathematical Constants for Type float
  
  Checking for std::numeric_limits<float> specialisation: yes
  std::numeric_limits<float>::digits reports that the precision is 
  24 binary digits.
  _Boost::math::policies::precision<float, Policy> reports that the compile time precision is 
  24 binary digits.
  The constant will be constructed from a float.
  
  Information on the Implementation and Handling of 
  Mathematical Constants for Type double
  
  Checking for std::numeric_limits<double> specialisation: yes
  std::numeric_limits<double>::digits reports that the precision is 
  53 binary digits.
  _Boost::math::policies::precision<double, Policy> reports that the compile time precision is 
  53 binary digits.
  The constant will be constructed from a double.
  
  Information on the Implementation and Handling of 
  Mathematical Constants for Type long double
  
  Checking for std::numeric_limits<long double> specialisation: yes
  std::numeric_limits<long double>::digits reports that the precision is 
  53 binary digits.
  _Boost::math::policies::precision<long double, Policy> reports that the compile time precision is 
  53 binary digits.
  The constant will be constructed from a double.
  
  Information on the Implementation and Handling of 
  Mathematical Constants for Type class _Boost::math::concepts::real_concept
  
  Checking for std::numeric_limits<class _Boost::math::concepts::real_concept> specialisation: no
  _Boost::math::policies::precision<class _Boost::math::concepts::real_concept, Policy> 
  reports that there is no compile type precision available.
  _Boost::math::tools::digits<class _Boost::math::concepts::real_concept>() 
  reports that the current runtime precision is 
  53 binary digits.
  No compile time precision is available, the construction method 
  will be decided at runtime and results will not be cached 
  - this may lead to poor runtime performance.
  Current runtime precision indicates that
  the constant will be constructed from a string on each call.
  
========== Rebuild All: 1 succeeded, 0 failed, 0 skipped ==========


*/

