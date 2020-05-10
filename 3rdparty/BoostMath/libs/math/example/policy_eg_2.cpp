//  Copyright John Maddock 2007.
//  Copyright Paul A. Bristow 2010
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
using std::cout; using std::endl;
#include <cerrno> // for ::errno

//[policy_eg_2

#include <boost/math/special_functions/gamma.hpp>
using _Boost::math::tgamma;

int main()
{
   // using namespace _Boost::math::policies; // or
   using _Boost::math::policies::errno_on_error;
   using _Boost::math::policies::make_policy;
   using _Boost::math::policies::pole_error;
   using _Boost::math::policies::domain_error;
   using _Boost::math::policies::overflow_error;
   using _Boost::math::policies::evaluation_error;

   errno = 0;
   std::cout << "Result of tgamma(30000) is: " 
      << _Boost::math::tgamma(
         30000, 
         make_policy(
            domain_error<errno_on_error>(),
            pole_error<errno_on_error>(),
            overflow_error<errno_on_error>(),
            evaluation_error<errno_on_error>() 
         )
      ) << std::endl;
   // Check errno was set:
   std::cout << "errno = " << errno << std::endl;
   // and again with evaluation at a pole:
   std::cout << "Result of tgamma(-10) is: " 
      << _Boost::math::tgamma(
         -10, 
         make_policy(
            domain_error<errno_on_error>(),
            pole_error<errno_on_error>(),
            overflow_error<errno_on_error>(),
            evaluation_error<errno_on_error>() 
         )
      ) << std::endl;
   // Check errno was set:
   std::cout << "errno = " << errno << std::endl;
}

//] //[/policy_eg_2]

/*

Output:

  Result of tgamma(30000) is: 1.#INF
  errno = 34
  Result of tgamma(-10) is: 1.#QNAN
  errno = 33
*/

