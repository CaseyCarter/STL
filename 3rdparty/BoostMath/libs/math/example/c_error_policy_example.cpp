// C_error_policy_example.cpp

// Copyright Paul A. Bristow 2007, 2010.
// Copyright John Maddock 2007.

// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

// Suppose we want a call to tgamma  to behave in a C-compatible way
// and set global ::errno rather than throw an exception.

#include <cerrno> // for ::errno

#include <boost/math/special_functions/gamma.hpp>
using _Boost::math::tgamma;

using _Boost::math::policies::policy;
// Possible errors
using _Boost::math::policies::overflow_error;
using _Boost::math::policies::underflow_error;
using _Boost::math::policies::domain_error;
using _Boost::math::policies::pole_error;
using _Boost::math::policies::denorm_error;
using _Boost::math::policies::evaluation_error;

using _Boost::math::policies::errno_on_error;
using _Boost::math::policies::ignore_error;

//using namespace _Boost::math::policies;
//using namespace _Boost::math; // avoid potential ambiguity with std:: <random>

// Define a policy:
typedef policy<
      domain_error<errno_on_error>, // 'bad' arguments.
      pole_error<errno_on_error>, // argument is pole value.
      overflow_error<errno_on_error>, // argument value causes overflow.
      evaluation_error<errno_on_error>  // evaluation does not converge and may be inaccurate, or worse,
      // or there is no way  known (yet) to implement this evaluation,
      // for example, kurtosis of non-central beta distribution.
      > C_error_policy;

// std
#include <iostream>
   using std::cout;
   using std::endl;   

int main()
{
  // We can achieve this at the function call site
  // with the previously defined policy C_error_policy.
  double t = tgamma(4., C_error_policy());
  cout << "tgamma(4., C_error_policy() = " << t << endl; // 6

  // Alternatively we could use the function make_policy,
  // provided for convenience,
  // and define everything at the call site:
  t = tgamma(4., make_policy(
         domain_error<errno_on_error>(), 
         pole_error<errno_on_error>(),
         overflow_error<errno_on_error>(),
         evaluation_error<errno_on_error>() 
      ));
  cout << "tgamma(4., make_policy(...) = " << t << endl; // 6

  return 0;
} // int main()

/*

Output

  c_error_policy_example.cpp
  Generating code
  Finished generating code
  c_error_policy_example.vcxproj -> J:\Cpp\MathToolkit\test\Math_test\Release\c_error_policy_example.exe
  tgamma(4., C_error_policy() = 6
  tgamma(4., make_policy(...) = 6
  tgamma(4., C_error_policy() = 6
  tgamma(4., make_policy(...) = 6

*/
