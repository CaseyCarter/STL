//  Copyright John Maddock 2007.
//  Copyright Paul A> Bristow 2010
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
using std::cout; using std::endl;
#include <cerrno> // for ::errno

//[policy_eg_1

#include <boost/math/special_functions/gamma.hpp>
using _Boost::math::tgamma;

// Define the policy to use:
using namespace _Boost::math::policies; // may be convenient, or

using _Boost::math::policies::policy;
// Types of error whose action can be altered by policies:.
using _Boost::math::policies::evaluation_error;
using _Boost::math::policies::domain_error;
using _Boost::math::policies::overflow_error;
using _Boost::math::policies::domain_error;
using _Boost::math::policies::pole_error;
// Actions on error (in enum error_policy_type):
using _Boost::math::policies::errno_on_error;
using _Boost::math::policies::ignore_error;
using _Boost::math::policies::throw_on_error;
using _Boost::math::policies::user_error;

typedef policy<
   domain_error<errno_on_error>,
   pole_error<errno_on_error>,
   overflow_error<errno_on_error>,
   evaluation_error<errno_on_error> 
> c_policy;
//
// Now use the policy when calling tgamma:

// http://msdn.microsoft.com/en-us/library/t3ayayh1.aspx 
// Microsoft errno declared in STDLIB.H as "extern int errno;" 

int main()
{
   errno = 0; // Reset.
   cout << "Result of tgamma(30000) is: " 
      << tgamma(30000, c_policy()) << endl; // Too big parameter
   cout << "errno = " << errno << endl; // errno 34 Numerical result out of range.
   cout << "Result of tgamma(-10) is: " 
      << _Boost::math::tgamma(-10, c_policy()) << endl; // Negative parameter.
   cout << "errno = " << errno << endl; // error 33 Numerical argument out of domain.
} // int main()

//]

/* Output

policy_eg_1.cpp
  Generating code
  Finished generating code
  policy_eg_1.vcxproj -> J:\Cpp\MathToolkit\test\Math_test\Release\policy_eg_1.exe
  Result of tgamma(30000) is: 1.#INF
  errno = 34
  Result of tgamma(-10) is: 1.#QNAN
  errno = 33

*/


