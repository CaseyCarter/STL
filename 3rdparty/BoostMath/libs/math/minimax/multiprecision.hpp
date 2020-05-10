//  (C) Copyright John Maddock 2015.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_REMEZ_MULTIPRECISION_HPP
#define BOOST_REMEZ_MULTIPRECISION_HPP

#include <boost/multiprecision/cpp_bin_float.hpp>

#ifdef USE_NTL
#include <boost/math/bindings/rr.hpp>
namespace std {
   using _Boost::math::ntl::pow;
} // workaround for spirit parser.

typedef _Boost::math::ntl::RR mp_type;

inline void set_working_precision(int n)
{
   NTL::RR::SetPrecision(working_precision);
}

inline int get_working_precision()
{
   return mp_type::precision(working_precision);
}

inline void set_output_precision(int n)
{
   NTL::RR::SetOutputPrecision(n);
}

inline mp_type round_to_precision(mp_type m, int bits)
{
   return NTL::RoundToPrecision(m.value(), bits);
}


namespace _Boost {
   namespace math {
      namespace tools {

         template <>
         inline _Boost::multiprecision::cpp_bin_float_double_extended real_cast<_Boost::multiprecision::cpp_bin_float_double_extended, mp_type>(mp_type val)
         {
            unsigned p = NTL::RR::OutputPrecision();
            NTL::RR::SetOutputPrecision(20);
            _Boost::multiprecision::cpp_bin_float_double_extended r = _Boost::lexical_cast<_Boost::multiprecision::cpp_bin_float_double_extended>(val);
            NTL::RR::SetOutputPrecision(p);
            return r;
         }
         template <>
         inline _Boost::multiprecision::cpp_bin_float_quad real_cast<_Boost::multiprecision::cpp_bin_float_quad, mp_type>(mp_type val)
         {
            unsigned p = NTL::RR::OutputPrecision();
            NTL::RR::SetOutputPrecision(35);
            _Boost::multiprecision::cpp_bin_float_quad r = _Boost::lexical_cast<_Boost::multiprecision::cpp_bin_float_quad>(val);
            NTL::RR::SetOutputPrecision(p);
            return r;
         }

      }
   }
}

#elif defined(USE_CPP_BIN_FLOAT_100)

#include <boost/multiprecision/cpp_bin_float.hpp>

typedef _Boost::multiprecision::cpp_bin_float_100 mp_type;

inline void set_working_precision(int n)
{
}

inline void set_output_precision(int n)
{
   std::cout << std::setprecision(n);
   std::cerr << std::setprecision(n);
}

inline mp_type round_to_precision(mp_type m, int bits)
{
   int i;
   mp_type f = frexp(m, &i);
   f = ldexp(f, bits);
   i -= bits;
   f = floor(f);
   return ldexp(f, i);
}

inline int get_working_precision()
{
   return std::numeric_limits<mp_type>::digits;
}

namespace _Boost {
   namespace math {
      namespace tools {

         template <>
         inline _Boost::multiprecision::cpp_bin_float_double_extended real_cast<_Boost::multiprecision::cpp_bin_float_double_extended, mp_type>(mp_type val)
         {
            return _Boost::multiprecision::cpp_bin_float_double_extended(val);
         }
         template <>
         inline _Boost::multiprecision::cpp_bin_float_quad real_cast<_Boost::multiprecision::cpp_bin_float_quad, mp_type>(mp_type val)
         {
            return _Boost::multiprecision::cpp_bin_float_quad(val);
         }

      }
   }
}


#elif defined(USE_MPFR_100)

#include <boost/multiprecision/mpfr.hpp>

typedef _Boost::multiprecision::mpfr_float_100 mp_type;

inline void set_working_precision(int n)
{
}

inline void set_output_precision(int n)
{
   std::cout << std::setprecision(n);
   std::cerr << std::setprecision(n);
}

inline mp_type round_to_precision(mp_type m, int bits)
{
   mpfr_prec_round(m.backend().data(), bits, MPFR_RNDN);
   return m;
}

inline int get_working_precision()
{
   return std::numeric_limits<mp_type>::digits;
}

namespace _Boost {
   namespace math {
      namespace tools {

         template <>
         inline _Boost::multiprecision::cpp_bin_float_double_extended real_cast<_Boost::multiprecision::cpp_bin_float_double_extended, mp_type>(mp_type val)
         {
            return _Boost::multiprecision::cpp_bin_float_double_extended(val);
         }
         template <>
         inline _Boost::multiprecision::cpp_bin_float_quad real_cast<_Boost::multiprecision::cpp_bin_float_quad, mp_type>(mp_type val)
         {
            return _Boost::multiprecision::cpp_bin_float_quad(val);
         }

      }
   }
}


#else

#include <boost/multiprecision/mpfr.hpp>

typedef _Boost::multiprecision::mpfr_float mp_type;

inline void set_working_precision(int n)
{
   _Boost::multiprecision::mpfr_float::default_precision(_Boost::multiprecision::detail::digits2_2_10(n));
}

inline void set_output_precision(int n)
{
   std::cout << std::setprecision(n);
   std::cerr << std::setprecision(n);
}

inline mp_type round_to_precision(mp_type m, int bits)
{
   mpfr_prec_round(m.backend().data(), bits, MPFR_RNDN);
   return m;
}

inline int get_working_precision()
{
   return mp_type::default_precision();
}

namespace _Boost {
   namespace math {
      namespace tools {

         template <>
         inline _Boost::multiprecision::cpp_bin_float_double_extended real_cast<_Boost::multiprecision::cpp_bin_float_double_extended, mp_type>(mp_type val)
         {
            return _Boost::multiprecision::cpp_bin_float_double_extended(val);
         }
         template <>
         inline _Boost::multiprecision::cpp_bin_float_quad real_cast<_Boost::multiprecision::cpp_bin_float_quad, mp_type>(mp_type val)
         {
            return _Boost::multiprecision::cpp_bin_float_quad(val);
         }

      }
   }
}



#endif




#endif // BOOST_REMEZ_MULTIPRECISION_HPP





