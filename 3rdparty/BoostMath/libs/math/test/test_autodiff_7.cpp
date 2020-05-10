//           Copyright Matthew Pulver 2018 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//      (See accompanying file LICENSE_1_0.txt or copy at
//           https://www.boost.org/LICENSE_1_0.txt)

#include "test_autodiff.hpp"

BOOST_AUTO_TEST_SUITE(test_autodiff_7)

BOOST_AUTO_TEST_CASE_TEMPLATE(expm1_hpp, T, all_float_types) {
  using _Boost::math::differentiation::detail::log;
  using _Boost::multiprecision::log;
  using std::log;
  using test_constants = test_constants_t<T>;
  static constexpr auto m = test_constants::order;
  test_detail::RandomSample<T> x_sampler{-log(T(2000)), log(T(2000))};
  for (auto i : _Boost::irange(test_constants::n_samples)) {
    std::ignore = i;
    auto x = x_sampler.next();
    BOOST_CHECK_CLOSE(_Boost::math::expm1(make_fvar<T, m>(x)).derivative(0u),
                      _Boost::math::expm1(x),
                      50 * test_constants::pct_epsilon());
  }
}

BOOST_AUTO_TEST_CASE_TEMPLATE(fpclassify_hpp, T, all_float_types) {
  using _Boost::math::fpclassify;
  using _Boost::math::isfinite;
  using _Boost::math::isinf;
  using _Boost::math::isnan;
  using _Boost::math::isnormal;
  using _Boost::multiprecision::fpclassify;
  using _Boost::multiprecision::isfinite;
  using _Boost::multiprecision::isinf;
  using _Boost::multiprecision::isnan;
  using _Boost::multiprecision::isnormal;

  using test_constants = test_constants_t<T>;
  static constexpr auto m = test_constants::order;
  test_detail::RandomSample<T> x_sampler{-1000, 1000};
  for (auto i : _Boost::irange(test_constants::n_samples)) {
    std::ignore = i;

    BOOST_CHECK_EQUAL(fpclassify(make_fvar<T, m>(0)), FP_ZERO);
    BOOST_CHECK_EQUAL(fpclassify(make_fvar<T, m>(10)), FP_NORMAL);
    BOOST_CHECK_EQUAL(
        fpclassify(make_fvar<T, m>(std::numeric_limits<T>::infinity())),
        FP_INFINITE);
    BOOST_CHECK_EQUAL(
        fpclassify(make_fvar<T, m>(std::numeric_limits<T>::quiet_NaN())),
        FP_NAN);
    if (std::numeric_limits<T>::has_denorm != std::denorm_absent) {
      BOOST_CHECK_EQUAL(
          fpclassify(make_fvar<T, m>(std::numeric_limits<T>::denorm_min())),
          FP_SUBNORMAL);
    }

    BOOST_CHECK(isfinite(make_fvar<T, m>(0)));
    BOOST_CHECK(isnormal(make_fvar<T, m>((std::numeric_limits<T>::min)())));
    BOOST_CHECK(
        !isnormal(make_fvar<T, m>(std::numeric_limits<T>::denorm_min())));
    BOOST_CHECK(isinf(make_fvar<T, m>(std::numeric_limits<T>::infinity())));
    BOOST_CHECK(isnan(make_fvar<T, m>(std::numeric_limits<T>::quiet_NaN())));
  }
}

BOOST_AUTO_TEST_SUITE_END()
