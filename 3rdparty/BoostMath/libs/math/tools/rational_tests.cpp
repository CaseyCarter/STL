//  (C) Copyright John Maddock 2007.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/random.hpp>
#include <boost/math/tools/rational.hpp>
#include <iostream>
#include <fstream>
#include "mp_t.hpp"

int main()
{
   using namespace _Boost::math;
   using namespace _Boost::math::tools;

   std::cout << std::scientific << std::setprecision(40);

   _Boost::mt19937 rnd;
   _Boost::variate_generator<
      _Boost::mt19937, 
      _Boost::uniform_int<> > gen(rnd, _Boost::uniform_int<>(1, 12));

   for(unsigned i = 1; i < 12; ++i)
   {
      std::vector<int> coef;
      for(unsigned j = 0; j < i; ++j)
      {
         coef.push_back(gen());
      }
      std::cout << 
"   //\n"
"   // Polynomials of order " << i-1 << "\n"
"   //\n"
"   static const U n" << i << "c[" << i << "] = { ";
      for(unsigned j = 0; j < i; ++j)
      {
         if(j) 
            std::cout  << ", ";
         std::cout << coef[j];
      }
      std::cout << " };\n";
      std::cout <<
         "   static const _Boost::array<U, " << i << "> n" << i << "a = { ";
      for(unsigned j = 0; j < i; ++j)
      {
         if(j) 
            std::cout  << ", ";
         std::cout << coef[j];
      }
      std::cout << " };\n";

      mp_t r1 = _Boost::math::tools::evaluate_polynomial(&coef[0], mp_t(0.125), i);
      mp_t r2 = _Boost::math::tools::evaluate_polynomial(&coef[0], mp_t(0.25), i);
      mp_t r3 = _Boost::math::tools::evaluate_polynomial(&coef[0], mp_t(0.75), i);
      mp_t r4 = _Boost::math::tools::evaluate_polynomial(&coef[0], mp_t(1) - mp_t(1) / 64, i);

      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_polynomial(n" << i << "c, static_cast<T>(0.125), " << i << "),\n"
         "      static_cast<T>(" << r1 << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_polynomial(n" << i << "c, static_cast<T>(0.25), " << i << "),\n"
         "      static_cast<T>(" << r2 << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_polynomial(n" << i << "c, static_cast<T>(0.75), " << i << "),\n"
         "      static_cast<T>(" << r3 << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_polynomial(n" << i << "c, static_cast<T>(1.0f - 1.0f/64.0f), " << i << "),\n"
         "      static_cast<T>(" << r4 << "L),\n"
         "      tolerance);\n\n";

      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_polynomial(n" << i << "c, static_cast<T>(0.125)),\n"
         "      static_cast<T>(" << r1 << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_polynomial(n" << i << "c, static_cast<T>(0.25)),\n"
         "      static_cast<T>(" << r2 << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_polynomial(n" << i << "c, static_cast<T>(0.75)),\n"
         "      static_cast<T>(" << r3 << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_polynomial(n" << i << "c, static_cast<T>(1.0f - 1.0f/64.0f)),\n"
         "      static_cast<T>(" << r4 << "L),\n"
         "      tolerance);\n\n";

      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_polynomial(n" << i << "a, static_cast<T>(0.125)),\n"
         "      static_cast<T>(" << r1 << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_polynomial(n" << i << "a, static_cast<T>(0.25)),\n"
         "      static_cast<T>(" << r2 << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_polynomial(n" << i << "a, static_cast<T>(0.75)),\n"
         "      static_cast<T>(" << r3 << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_polynomial(n" << i << "a, static_cast<T>(1.0f - 1.0f/64.0f)),\n"
         "      static_cast<T>(" << r4 << "L),\n"
         "      tolerance);\n\n";

      r1 = _Boost::math::tools::evaluate_even_polynomial(&coef[0], mp_t(0.125), i);
      r2 = _Boost::math::tools::evaluate_even_polynomial(&coef[0], mp_t(0.25), i);
      r3 = _Boost::math::tools::evaluate_even_polynomial(&coef[0], mp_t(0.75), i);
      r4 = _Boost::math::tools::evaluate_even_polynomial(&coef[0], mp_t(1) - mp_t(1) / 64, i);

      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_even_polynomial(n" << i << "c, static_cast<T>(0.125), " << i << "),\n"
         "      static_cast<T>(" << r1 << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_even_polynomial(n" << i << "c, static_cast<T>(0.25), " << i << "),\n"
         "      static_cast<T>(" << r2 << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_even_polynomial(n" << i << "c, static_cast<T>(0.75), " << i << "),\n"
         "      static_cast<T>(" << r3 << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_even_polynomial(n" << i << "c, static_cast<T>(1.0f - 1.0f/64.0f), " << i << "),\n"
         "      static_cast<T>(" << r4 << "L),\n"
         "      tolerance);\n\n";

      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_even_polynomial(n" << i << "c, static_cast<T>(0.125)),\n"
         "      static_cast<T>(" << r1 << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_even_polynomial(n" << i << "c, static_cast<T>(0.25)),\n"
         "      static_cast<T>(" << r2 << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_even_polynomial(n" << i << "c, static_cast<T>(0.75)),\n"
         "      static_cast<T>(" << r3 << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_even_polynomial(n" << i << "c, static_cast<T>(1.0f - 1.0f/64.0f)),\n"
         "      static_cast<T>(" << r4 << "L),\n"
         "      tolerance);\n\n";

      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_even_polynomial(n" << i << "a, static_cast<T>(0.125)),\n"
         "      static_cast<T>(" << r1 << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_even_polynomial(n" << i << "a, static_cast<T>(0.25)),\n"
         "      static_cast<T>(" << r2 << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_even_polynomial(n" << i << "a, static_cast<T>(0.75)),\n"
         "      static_cast<T>(" << r3 << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_even_polynomial(n" << i << "a, static_cast<T>(1.0f - 1.0f/64.0f)),\n"
         "      static_cast<T>(" << r4 << "L),\n"
         "      tolerance);\n\n";

      if(i > 1)
      {
         r1 = _Boost::math::tools::evaluate_odd_polynomial(&coef[0], mp_t(0.125), i);
         r2 = _Boost::math::tools::evaluate_odd_polynomial(&coef[0], mp_t(0.25), i);
         r3 = _Boost::math::tools::evaluate_odd_polynomial(&coef[0], mp_t(0.75), i);
         r4 = _Boost::math::tools::evaluate_odd_polynomial(&coef[0], mp_t(1) - mp_t(1) / 64, i);

         std::cout <<
            "   BOOST_CHECK_CLOSE(\n"
            "      _Boost::math::tools::evaluate_odd_polynomial(n" << i << "c, static_cast<T>(0.125), " << i << "),\n"
            "      static_cast<T>(" << r1 << "L),\n"
            "      tolerance);\n";
         std::cout <<
            "   BOOST_CHECK_CLOSE(\n"
            "      _Boost::math::tools::evaluate_odd_polynomial(n" << i << "c, static_cast<T>(0.25), " << i << "),\n"
            "      static_cast<T>(" << r2 << "L),\n"
            "      tolerance);\n";
         std::cout <<
            "   BOOST_CHECK_CLOSE(\n"
            "      _Boost::math::tools::evaluate_odd_polynomial(n" << i << "c, static_cast<T>(0.75), " << i << "),\n"
            "      static_cast<T>(" << r3 << "L),\n"
            "      tolerance);\n";
         std::cout <<
            "   BOOST_CHECK_CLOSE(\n"
            "      _Boost::math::tools::evaluate_odd_polynomial(n" << i << "c, static_cast<T>(1.0f - 1.0f/64.0f), " << i << "),\n"
            "      static_cast<T>(" << r4 << "L),\n"
            "      tolerance);\n\n";

         std::cout <<
            "   BOOST_CHECK_CLOSE(\n"
            "      _Boost::math::tools::evaluate_odd_polynomial(n" << i << "c, static_cast<T>(0.125)),\n"
            "      static_cast<T>(" << r1 << "L),\n"
            "      tolerance);\n";
         std::cout <<
            "   BOOST_CHECK_CLOSE(\n"
            "      _Boost::math::tools::evaluate_odd_polynomial(n" << i << "c, static_cast<T>(0.25)),\n"
            "      static_cast<T>(" << r2 << "L),\n"
            "      tolerance);\n";
         std::cout <<
            "   BOOST_CHECK_CLOSE(\n"
            "      _Boost::math::tools::evaluate_odd_polynomial(n" << i << "c, static_cast<T>(0.75)),\n"
            "      static_cast<T>(" << r3 << "L),\n"
            "      tolerance);\n";
         std::cout <<
            "   BOOST_CHECK_CLOSE(\n"
            "      _Boost::math::tools::evaluate_odd_polynomial(n" << i << "c, static_cast<T>(1.0f - 1.0f/64.0f)),\n"
            "      static_cast<T>(" << r4 << "L),\n"
            "      tolerance);\n\n";

         std::cout <<
            "   BOOST_CHECK_CLOSE(\n"
            "      _Boost::math::tools::evaluate_odd_polynomial(n" << i << "a, static_cast<T>(0.125)),\n"
            "      static_cast<T>(" << r1 << "L),\n"
            "      tolerance);\n";
         std::cout <<
            "   BOOST_CHECK_CLOSE(\n"
            "      _Boost::math::tools::evaluate_odd_polynomial(n" << i << "a, static_cast<T>(0.25)),\n"
            "      static_cast<T>(" << r2 << "L),\n"
            "      tolerance);\n";
         std::cout <<
            "   BOOST_CHECK_CLOSE(\n"
            "      _Boost::math::tools::evaluate_odd_polynomial(n" << i << "a, static_cast<T>(0.75)),\n"
            "      static_cast<T>(" << r3 << "L),\n"
            "      tolerance);\n";
         std::cout <<
            "   BOOST_CHECK_CLOSE(\n"
            "      _Boost::math::tools::evaluate_odd_polynomial(n" << i << "a, static_cast<T>(1.0f - 1.0f/64.0f)),\n"
            "      static_cast<T>(" << r4 << "L),\n"
            "      tolerance);\n\n";
      }

      r1 = _Boost::math::tools::evaluate_polynomial(&coef[0], mp_t(0.125), i);
      r2 = _Boost::math::tools::evaluate_polynomial(&coef[0], mp_t(0.25), i);
      r3 = _Boost::math::tools::evaluate_polynomial(&coef[0], mp_t(0.75), i);
      r4 = _Boost::math::tools::evaluate_polynomial(&coef[0], mp_t(1) - mp_t(1) / 64, i);

      coef.clear();
      for(unsigned j = 0; j < i; ++j)
      {
         coef.push_back(gen());
      }
      std::cout << 
"   //\n"
"   // Rational functions of order " << i-1 << "\n"
"   //\n"
"   static const U d" << i << "c[" << i << "] = { ";
      for(unsigned j = 0; j < i; ++j)
      {
         if(j) 
            std::cout  << ", ";
         std::cout << coef[j];
      }
      std::cout << " };\n";
      std::cout <<
         "   static const _Boost::array<U, " << i << "> d" << i << "a = { ";
      for(unsigned j = 0; j < i; ++j)
      {
         if(j) 
            std::cout  << ", ";
         std::cout << coef[j];
      }
      std::cout << " };\n";

      mp_t r1d = _Boost::math::tools::evaluate_polynomial(&coef[0], mp_t(0.125), i);
      mp_t r2d = _Boost::math::tools::evaluate_polynomial(&coef[0], mp_t(0.25), i);
      mp_t r3d = _Boost::math::tools::evaluate_polynomial(&coef[0], mp_t(0.75), i);
      mp_t r4d = _Boost::math::tools::evaluate_polynomial(&coef[0], mp_t(1) - mp_t(1) / 64, i);

      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_rational(n" << i << "c, d" << i << "c, static_cast<T>(0.125), " << i << "),\n"
         "      static_cast<T>(" << r1/r1d << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_rational(n" << i << "c, d" << i << "c, static_cast<T>(0.25), " << i << "),\n"
         "      static_cast<T>(" << r2/r2d << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_rational(n" << i << "c, d" << i << "c, static_cast<T>(0.75), " << i << "),\n"
         "      static_cast<T>(" << r3/r3d << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_rational(n" << i << "c, d" << i << "c, static_cast<T>(1.0f - 1.0f/64.0f), " << i << "),\n"
         "      static_cast<T>(" << r4/r4d << "L),\n"
         "      tolerance);\n\n";

      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_rational(n" << i << "c, d" << i << "c, static_cast<T>(0.125)),\n"
         "      static_cast<T>(" << r1/r1d << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_rational(n" << i << "c, d" << i << "c, static_cast<T>(0.25)),\n"
         "      static_cast<T>(" << r2/r2d << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_rational(n" << i << "c, d" << i << "c, static_cast<T>(0.75)),\n"
         "      static_cast<T>(" << r3/r3d << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_rational(n" << i << "c, d" << i << "c, static_cast<T>(1.0f - 1.0f/64.0f)),\n"
         "      static_cast<T>(" << r4/r4d << "L),\n"
         "      tolerance);\n\n";

      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_rational(n" << i << "a, d" << i << "a, static_cast<T>(0.125)),\n"
         "      static_cast<T>(" << r1/r1d << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_rational(n" << i << "a, d" << i << "a, static_cast<T>(0.25)),\n"
         "      static_cast<T>(" << r2/r2d << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_rational(n" << i << "a, d" << i << "a, static_cast<T>(0.75)),\n"
         "      static_cast<T>(" << r3/r3d << "L),\n"
         "      tolerance);\n";
      std::cout <<
         "   BOOST_CHECK_CLOSE(\n"
         "      _Boost::math::tools::evaluate_rational(n" << i << "a, d" << i << "a, static_cast<T>(1.0f - 1.0f/64.0f)),\n"
         "      static_cast<T>(" << r4/r4d << "L),\n"
         "      tolerance);\n\n";
   }

   return 0;
}



