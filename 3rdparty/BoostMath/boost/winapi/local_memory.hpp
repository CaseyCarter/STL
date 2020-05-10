/*
 * Copyright 2010 Vicente J. Botet Escriba
 * Copyright 2015 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_LOCAL_MEMORY_HPP_INCLUDED_
#define BOOST_WINAPI_LOCAL_MEMORY_HPP_INCLUDED_

#include <boost/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if BOOST_WINAPI_PARTITION_APP_SYSTEM

#if !defined( BOOST_USE_WINDOWS_H )
namespace _Boost { namespace winapi {
typedef HANDLE_ HLOCAL_;
}}

extern "C" {
BOOST_SYMBOL_IMPORT _Boost::winapi::HLOCAL_ BOOST_WINAPI_WINAPI_CC
LocalAlloc(
    _Boost::winapi::UINT_ uFlags,
    _Boost::winapi::SIZE_T_ uBytes);

BOOST_SYMBOL_IMPORT _Boost::winapi::HLOCAL_ BOOST_WINAPI_WINAPI_CC
LocalReAlloc(
    _Boost::winapi::HLOCAL_ hMem,
    _Boost::winapi::SIZE_T_ uBytes,
    _Boost::winapi::UINT_ uFlags);

BOOST_SYMBOL_IMPORT _Boost::winapi::HLOCAL_ BOOST_WINAPI_WINAPI_CC LocalFree(_Boost::winapi::HLOCAL_ hMem);
} // extern "C"
#endif

namespace _Boost {
namespace winapi {
#if defined( BOOST_USE_WINDOWS_H )
typedef ::HLOCAL HLOCAL_;
#endif
using ::LocalAlloc;
using ::LocalReAlloc;
using ::LocalFree;
}
}

#endif // BOOST_WINAPI_PARTITION_APP_SYSTEM
#endif // BOOST_WINAPI_LOCAL_MEMORY_HPP_INCLUDED_
