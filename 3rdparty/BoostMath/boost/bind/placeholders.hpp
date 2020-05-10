#ifndef BOOST_BIND_PLACEHOLDERS_HPP_INCLUDED
#define BOOST_BIND_PLACEHOLDERS_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  bind/placeholders.hpp - _N definitions
//
//  Copyright (c) 2002 Peter Dimov and Multi Media Ltd.
//  Copyright 2015 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//  See http://www.boost.org/libs/bind/bind.html for documentation.
//

#include <boost/bind/arg.hpp>
#include <boost/config.hpp>

namespace _Boost
{

namespace placeholders
{

#if defined(__BORLANDC__) || defined(__GNUC__) && (__GNUC__ < 4)

inline _Boost::arg<1> _1() { return _Boost::arg<1>(); }
inline _Boost::arg<2> _2() { return _Boost::arg<2>(); }
inline _Boost::arg<3> _3() { return _Boost::arg<3>(); }
inline _Boost::arg<4> _4() { return _Boost::arg<4>(); }
inline _Boost::arg<5> _5() { return _Boost::arg<5>(); }
inline _Boost::arg<6> _6() { return _Boost::arg<6>(); }
inline _Boost::arg<7> _7() { return _Boost::arg<7>(); }
inline _Boost::arg<8> _8() { return _Boost::arg<8>(); }
inline _Boost::arg<9> _9() { return _Boost::arg<9>(); }

#else

BOOST_STATIC_CONSTEXPR _Boost::arg<1> _1;
BOOST_STATIC_CONSTEXPR _Boost::arg<2> _2;
BOOST_STATIC_CONSTEXPR _Boost::arg<3> _3;
BOOST_STATIC_CONSTEXPR _Boost::arg<4> _4;
BOOST_STATIC_CONSTEXPR _Boost::arg<5> _5;
BOOST_STATIC_CONSTEXPR _Boost::arg<6> _6;
BOOST_STATIC_CONSTEXPR _Boost::arg<7> _7;
BOOST_STATIC_CONSTEXPR _Boost::arg<8> _8;
BOOST_STATIC_CONSTEXPR _Boost::arg<9> _9;

#endif

} // namespace placeholders

} // namespace _Boost

#endif // #ifndef BOOST_BIND_PLACEHOLDERS_HPP_INCLUDED
