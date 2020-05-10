//  Copyright Nick Thompson 2017.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include <boost/math/concepts/std_real_concept.hpp>
#include <boost/math/quadrature/sinh_sinh.hpp>


void compile_and_link_test()
{
    auto f = [](_Boost::math::concepts::std_real_concept x) { return x; };
    _Boost::math::quadrature::sinh_sinh<_Boost::math::concepts::std_real_concept> integrator;
    integrator.integrate(f);
}
