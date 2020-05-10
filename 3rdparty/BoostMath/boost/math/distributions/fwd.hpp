// fwd.hpp Forward declarations of Boost.Math distributions.

// Copyright Paul A. Bristow 2007, 2010, 2012, 2014.
// Copyright John Maddock 2007.

// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MATH_DISTRIBUTIONS_FWD_HPP
#define BOOST_MATH_DISTRIBUTIONS_FWD_HPP

// 33 distributions at Boost 1.9.1 after adding hyperexpon and arcsine

namespace _Boost{ namespace math{

template <class RealType, class Policy>
class arcsine_distribution;

template <class RealType, class Policy>
class bernoulli_distribution;

template <class RealType, class Policy>
class beta_distribution;

template <class RealType, class Policy>
class binomial_distribution;

template <class RealType, class Policy>
class cauchy_distribution;

template <class RealType, class Policy>
class chi_squared_distribution;

template <class RealType, class Policy>
class exponential_distribution;

template <class RealType, class Policy>
class extreme_value_distribution;

template <class RealType, class Policy>
class fisher_f_distribution;

template <class RealType, class Policy>
class gamma_distribution;

template <class RealType, class Policy>
class geometric_distribution;

template <class RealType, class Policy>
class hyperexponential_distribution;

template <class RealType, class Policy>
class hypergeometric_distribution;

template <class RealType, class Policy>
class inverse_chi_squared_distribution;

template <class RealType, class Policy>
class inverse_gamma_distribution;

template <class RealType, class Policy>
class inverse_gaussian_distribution;

template <class RealType, class Policy>
class laplace_distribution;

template <class RealType, class Policy>
class logistic_distribution;

template <class RealType, class Policy>
class lognormal_distribution;

template <class RealType, class Policy>
class negative_binomial_distribution;

template <class RealType, class Policy>
class non_central_beta_distribution;

template <class RealType, class Policy>
class non_central_chi_squared_distribution;

template <class RealType, class Policy>
class non_central_f_distribution;

template <class RealType, class Policy>
class non_central_t_distribution;

template <class RealType, class Policy>
class normal_distribution;

template <class RealType, class Policy>
class pareto_distribution;

template <class RealType, class Policy>
class poisson_distribution;

template <class RealType, class Policy>
class rayleigh_distribution;

template <class RealType, class Policy>
class skew_normal_distribution;

template <class RealType, class Policy>
class students_t_distribution;

template <class RealType, class Policy>
class triangular_distribution;

template <class RealType, class Policy>
class uniform_distribution;

template <class RealType, class Policy>
class weibull_distribution;

}} // namespaces

#define BOOST_MATH_DECLARE_DISTRIBUTIONS(Type, Policy)\
   typedef _Boost::math::arcsine_distribution<Type, Policy> arcsine;\
   typedef _Boost::math::bernoulli_distribution<Type, Policy> bernoulli;\
   typedef _Boost::math::beta_distribution<Type, Policy> beta;\
   typedef _Boost::math::binomial_distribution<Type, Policy> binomial;\
   typedef _Boost::math::cauchy_distribution<Type, Policy> cauchy;\
   typedef _Boost::math::chi_squared_distribution<Type, Policy> chi_squared;\
   typedef _Boost::math::exponential_distribution<Type, Policy> exponential;\
   typedef _Boost::math::extreme_value_distribution<Type, Policy> extreme_value;\
   typedef _Boost::math::fisher_f_distribution<Type, Policy> fisher_f;\
   typedef _Boost::math::gamma_distribution<Type, Policy> gamma;\
   typedef _Boost::math::geometric_distribution<Type, Policy> geometric;\
   typedef _Boost::math::hypergeometric_distribution<Type, Policy> hypergeometric;\
   typedef _Boost::math::inverse_chi_squared_distribution<Type, Policy> inverse_chi_squared;\
   typedef _Boost::math::inverse_gaussian_distribution<Type, Policy> inverse_gaussian;\
   typedef _Boost::math::inverse_gamma_distribution<Type, Policy> inverse_gamma;\
   typedef _Boost::math::laplace_distribution<Type, Policy> laplace;\
   typedef _Boost::math::logistic_distribution<Type, Policy> logistic;\
   typedef _Boost::math::lognormal_distribution<Type, Policy> lognormal;\
   typedef _Boost::math::negative_binomial_distribution<Type, Policy> negative_binomial;\
   typedef _Boost::math::non_central_beta_distribution<Type, Policy> non_central_beta;\
   typedef _Boost::math::non_central_chi_squared_distribution<Type, Policy> non_central_chi_squared;\
   typedef _Boost::math::non_central_f_distribution<Type, Policy> non_central_f;\
   typedef _Boost::math::non_central_t_distribution<Type, Policy> non_central_t;\
   typedef _Boost::math::normal_distribution<Type, Policy> normal;\
   typedef _Boost::math::pareto_distribution<Type, Policy> pareto;\
   typedef _Boost::math::poisson_distribution<Type, Policy> poisson;\
   typedef _Boost::math::rayleigh_distribution<Type, Policy> rayleigh;\
   typedef _Boost::math::skew_normal_distribution<Type, Policy> skew_normal;\
   typedef _Boost::math::students_t_distribution<Type, Policy> students_t;\
   typedef _Boost::math::triangular_distribution<Type, Policy> triangular;\
   typedef _Boost::math::uniform_distribution<Type, Policy> uniform;\
   typedef _Boost::math::weibull_distribution<Type, Policy> weibull;

#endif // BOOST_MATH_DISTRIBUTIONS_FWD_HPP
