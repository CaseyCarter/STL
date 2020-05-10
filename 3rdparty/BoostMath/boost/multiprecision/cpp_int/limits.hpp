///////////////////////////////////////////////////////////////
//  Copyright 2012 John Maddock. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt
//
// Comparison operators for cpp_int_backend:
//
#ifndef BOOST_MP_CPP_INT_LIM_HPP
#define BOOST_MP_CPP_INT_LIM_HPP

namespace std {

namespace detail {

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4307)
#endif

template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
inline BOOST_CXX14_CONSTEXPR_IF_DETECTION _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates>
get_min(const _Boost::mpl::true_&, const _Boost::mpl::true_&, const _Boost::mpl::true_&)
{
   // Bounded, signed, and no allocator.
   typedef _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates>                                                result_type;
   typedef _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MaxBits, MaxBits, _Boost::multiprecision::unsigned_magnitude, _Boost::multiprecision::unchecked>, ExpressionTemplates> ui_type;
#ifdef BOOST_MP_NO_CONSTEXPR_DETECTION
   static
#else
   constexpr
#endif
   const result_type                                                                                                                                                                          val = -result_type(~ui_type(0));
   return val;
}

template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
inline _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates>
get_min(const _Boost::mpl::true_&, const _Boost::mpl::true_&, const _Boost::mpl::false_&)
{
   // Bounded, signed, and an allocator (can't be constexpr).
   typedef _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates>                                                result_type;
   typedef _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MaxBits, MaxBits, _Boost::multiprecision::unsigned_magnitude, _Boost::multiprecision::unchecked>, ExpressionTemplates> ui_type;
   static const result_type                                                                                                                                                                          val = -result_type(~ui_type(0));
   return val;
}

template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
inline BOOST_CXX14_CONSTEXPR_IF_DETECTION _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates>
get_min(const _Boost::mpl::true_&, const _Boost::mpl::false_&, const _Boost::mpl::true_&)
{
   // Bounded, unsigned, no allocator (can be constexpr):
#ifdef BOOST_MP_NO_CONSTEXPR_DETECTION
   static
#else
   constexpr
#endif
   const _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> val(0u);
   return val;
}

template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
inline _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates>
get_min(const _Boost::mpl::true_&, const _Boost::mpl::false_&, const _Boost::mpl::false_&)
{
   // Bounded and unsigned with allocator (no constexpr):
   static const _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> val(0u);
   return val;
}

template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates, bool has_allocator>
inline _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates>
get_min(const _Boost::mpl::false_&, const _Boost::mpl::true_&, const _Boost::mpl::bool_<has_allocator>&)
{
   // Unbounded and signed, never constexpr because there must be an allocator.
   // There is no minimum value, just return 0:
   static const _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> val(0u);
   return val;
}

template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates, bool has_allocator>
inline _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates>
get_min(const _Boost::mpl::false_&, const _Boost::mpl::false_&, const _Boost::mpl::bool_<has_allocator>&)
{
   // Unbound and unsigned, never constexpr because there must be an allocator.
   static const _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> val(0u);
   return val;
}

template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
inline BOOST_CXX14_CONSTEXPR_IF_DETECTION _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates>
get_max(const _Boost::mpl::true_&, const _Boost::mpl::true_&, const _Boost::mpl::true_&)
{
   // Bounded and signed, no allocator, can be constexpr.
   typedef _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates>                                                result_type;
   typedef _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MaxBits, MaxBits, _Boost::multiprecision::unsigned_magnitude, _Boost::multiprecision::unchecked>, ExpressionTemplates> ui_type;
#ifdef BOOST_MP_NO_CONSTEXPR_DETECTION
   static
#else
   constexpr
#endif
   const result_type                                                                                                                                                                          val = ~ui_type(0);
   return val;
}

template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
inline _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates>
get_max(const _Boost::mpl::true_&, const _Boost::mpl::true_&, const _Boost::mpl::false_&)
{
   // Bounded and signed, has an allocator, never constexpr.
   typedef _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates>                                                result_type;
   typedef _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MaxBits, MaxBits, _Boost::multiprecision::unsigned_magnitude, _Boost::multiprecision::unchecked>, ExpressionTemplates> ui_type;
   static const result_type                                                                                                                                                                          val = ~ui_type(0);
   return val;
}

template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
inline BOOST_CXX14_CONSTEXPR_IF_DETECTION _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates>
get_max(const _Boost::mpl::true_&, const _Boost::mpl::false_&, const _Boost::mpl::true_&)
{
   // Bound and unsigned, no allocator so can be constexpr:
   typedef _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates>                                                           result_type;
   typedef _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, _Boost::multiprecision::unsigned_magnitude, _Boost::multiprecision::unchecked, Allocator>, ExpressionTemplates> ui_type;
#ifdef BOOST_MP_NO_CONSTEXPR_DETECTION
   static
#else
   constexpr
#endif
   const result_type                                                                                                                                                                                     val = ~ui_type(0);
   return val;
}

template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
inline _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates>
get_max(const _Boost::mpl::true_&, const _Boost::mpl::false_&, const _Boost::mpl::false_&)
{
   // Bound and unsigned, has an allocator so can never be constexpr:
   typedef _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates>                                                           result_type;
   typedef _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, _Boost::multiprecision::unsigned_magnitude, _Boost::multiprecision::unchecked, Allocator>, ExpressionTemplates> ui_type;
   static const result_type                                                                                                                                                                                     val = ~ui_type(0);
   return val;
}

template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates, bool has_allocator>
inline _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates>
get_max(const _Boost::mpl::false_&, const _Boost::mpl::true_&, const _Boost::mpl::bool_<has_allocator>&)
{
   // Unbounded and signed.
   // There is no maximum value, just return 0:
   static const _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> val(0u);
   return val;
}

template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates, bool has_allocator>
inline _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates>
get_max(const _Boost::mpl::false_&, const _Boost::mpl::false_&, const _Boost::mpl::bool_<has_allocator>&)
{
   // Unbound and unsigned:
   static const _Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> val(0u);
   return val;
}

} // namespace detail

template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
class numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >
{
   typedef _Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator> backend_type;
   typedef _Boost::multiprecision::number<backend_type, ExpressionTemplates>                       number_type;

   struct inititializer
   {
      BOOST_CXX14_CONSTEXPR_IF_DETECTION inititializer()
      {
         (std::numeric_limits<number_type>::max)();
         (std::numeric_limits<number_type>::min)();
      }
      BOOST_CXX14_CONSTEXPR_IF_DETECTION void do_nothing() const {}
   };

   static const inititializer init;

 public:
   BOOST_STATIC_CONSTEXPR bool is_specialized = true;
   //
   // Largest and smallest numbers are bounded only by available memory, set
   // to zero:
   //
   static BOOST_CXX14_CONSTEXPR_IF_DETECTION number_type(min)()
   {
      init.do_nothing();
      return detail::get_min<MinBits, MaxBits, SignType, Checked, Allocator, ExpressionTemplates>(_Boost::multiprecision::backends::is_fixed_precision<backend_type>(), _Boost::multiprecision::is_signed_number<backend_type>(), _Boost::mpl::bool_<_Boost::is_void<Allocator>::value>());
   }
   static BOOST_CXX14_CONSTEXPR_IF_DETECTION number_type(max)()
   {
      init.do_nothing();
      return detail::get_max<MinBits, MaxBits, SignType, Checked, Allocator, ExpressionTemplates>(_Boost::multiprecision::backends::is_fixed_precision<backend_type>(), _Boost::multiprecision::is_signed_number<backend_type>(), _Boost::mpl::bool_<_Boost::is_void<Allocator>::value>());
   }
   static BOOST_CXX14_CONSTEXPR_IF_DETECTION number_type          lowest() { return (min)(); }
   BOOST_STATIC_CONSTEXPR int  digits       = _Boost::multiprecision::backends::max_precision<backend_type>::value == UINT_MAX ? INT_MAX : _Boost::multiprecision::backends::max_precision<backend_type>::value;
   BOOST_STATIC_CONSTEXPR int  digits10     = (digits > INT_MAX / 301) ? (digits / 1000) * 301L : (digits * 301) / 1000;
   BOOST_STATIC_CONSTEXPR int  max_digits10 = digits10 + 3;
   BOOST_STATIC_CONSTEXPR bool is_signed    = _Boost::multiprecision::is_signed_number<backend_type>::value;
   BOOST_STATIC_CONSTEXPR bool is_integer   = true;
   BOOST_STATIC_CONSTEXPR bool is_exact     = true;
   BOOST_STATIC_CONSTEXPR int  radix        = 2;
   static BOOST_CXX14_CONSTEXPR_IF_DETECTION number_type          epsilon() { return 0; }
   static BOOST_CXX14_CONSTEXPR_IF_DETECTION number_type          round_error() { return 0; }
   BOOST_STATIC_CONSTEXPR int  min_exponent                  = 0;
   BOOST_STATIC_CONSTEXPR int  min_exponent10                = 0;
   BOOST_STATIC_CONSTEXPR int  max_exponent                  = 0;
   BOOST_STATIC_CONSTEXPR int  max_exponent10                = 0;
   BOOST_STATIC_CONSTEXPR bool has_infinity                  = false;
   BOOST_STATIC_CONSTEXPR bool has_quiet_NaN                 = false;
   BOOST_STATIC_CONSTEXPR bool has_signaling_NaN             = false;
   BOOST_STATIC_CONSTEXPR float_denorm_style has_denorm      = denorm_absent;
   BOOST_STATIC_CONSTEXPR bool               has_denorm_loss = false;
   static BOOST_CXX14_CONSTEXPR_IF_DETECTION number_type                        infinity() { return 0; }
   static BOOST_CXX14_CONSTEXPR_IF_DETECTION number_type                        quiet_NaN() { return 0; }
   static BOOST_CXX14_CONSTEXPR_IF_DETECTION number_type                        signaling_NaN() { return 0; }
   static BOOST_CXX14_CONSTEXPR_IF_DETECTION number_type                        denorm_min() { return 0; }
   BOOST_STATIC_CONSTEXPR bool               is_iec559       = false;
   BOOST_STATIC_CONSTEXPR bool               is_bounded      = _Boost::multiprecision::backends::is_fixed_precision<backend_type>::value;
   BOOST_STATIC_CONSTEXPR bool               is_modulo       = (_Boost::multiprecision::backends::is_fixed_precision<backend_type>::value && (Checked == _Boost::multiprecision::unchecked));
   BOOST_STATIC_CONSTEXPR bool               traps           = false;
   BOOST_STATIC_CONSTEXPR bool               tinyness_before = false;
   BOOST_STATIC_CONSTEXPR float_round_style round_style      = round_toward_zero;
};

template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
const typename numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::inititializer numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::init;

#ifndef BOOST_NO_INCLASS_MEMBER_INITIALIZATION

template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST int numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::digits;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST int numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::digits10;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST int numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::max_digits10;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST bool numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::is_signed;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST bool numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::is_integer;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST bool numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::is_exact;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST int numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::radix;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST int numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::min_exponent;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST int numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::min_exponent10;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST int numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::max_exponent;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST int numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::max_exponent10;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST bool numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::has_infinity;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST bool numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::has_quiet_NaN;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST bool numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::has_signaling_NaN;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST float_denorm_style numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::has_denorm;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST bool numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::has_denorm_loss;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST bool numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::is_iec559;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST bool numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::is_bounded;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST bool numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::is_modulo;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST bool numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::traps;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST bool numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::tinyness_before;
template <unsigned MinBits, unsigned MaxBits, _Boost::multiprecision::cpp_integer_type SignType, _Boost::multiprecision::cpp_int_check_type Checked, class Allocator, _Boost::multiprecision::expression_template_option ExpressionTemplates>
BOOST_CONSTEXPR_OR_CONST float_round_style numeric_limits<_Boost::multiprecision::number<_Boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ExpressionTemplates> >::round_style;

#endif
#ifdef _MSC_VER
#pragma warning(pop)
#endif

} // namespace std

#endif
