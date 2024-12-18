// __msvc_sanitizer_annotate_container.hpp internal header

// Copyright (c) Microsoft Corporation.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef __MSVC_SANITIZER_ANNOTATE_CONTAINER_HPP
#define __MSVC_SANITIZER_ANNOTATE_CONTAINER_HPP
#include <yvals_core.h>
#if _STL_COMPILER_PREPROCESSOR

#pragma pack(push, _CRT_PACKING)
#pragma warning(push, _STL_WARNING_LEVEL)
#pragma warning(disable : _STL_DISABLED_WARNINGS)
_STL_DISABLE_CLANG_WARNINGS
#pragma push_macro("new")
#undef new

// By default, Standard Library ASan annotations are enabled when compiling with ASan instrumentation
// (`/fsanitize=address`) on supported platforms and disabled otherwise. The following macros are available to control
// ASan annotations:
//   - _DISABLE_STL_ANNOTATION: Disable all ASan annotations.
//     + _DISABLE_STRING_ANNOTATION: Disable annotations for `basic_string`
//     + _DISABLE_VECTOR_ANNOTATION: Disable annotations for `vector`
//   - _ENABLE_STL_ANNOTATION_ON_UNSUPPORTED_PLATFORMS: Even on unsupported platforms, enable ASan annotations if
//     instrumentation is enabled.
//   - _ANNOTATE_STL: Enable ASan annotations even when ASan instrumentation is disabled.
//     This is useful when building static libraries which may be linked against both ASan and non-ASan binaries.
//     + _ANNOTATE_STRING: same, but only for `basic_string`
//     + _ANNOTATE_VECTOR: same, but only for `vector`
//
// The more specific `_ANNOTATE_MEOW` macros take precedence over general `_DISABLE_STL_ANNOTATION`. Likewise
// `_DISABLE_MEOW_ANNOTATION` takes precedence over `_ANNOTATE_STL`.

#if defined(_DISABLE_STL_ANNOTATION) && defined(_ANNOTATE_STL)
#error _DISABLE_STL_ANNOTATION and _ANNOTATE_STL are mutually exclusive
#endif // ^^^ defined(_DISABLE_STL_ANNOTATION) && defined(_ANNOTATE_STL) ^^^

#if !defined(_DISABLE_STL_ANNOTATION) && !defined(_ENABLE_STL_ANNOTATION_ON_UNSUPPORTED_PLATFORMS)

#if defined(_M_ARM64EC) || defined(_M_ARM64) || defined(_M_ARM) || defined(_M_CEE_PURE)
#define _DISABLE_STL_ANNOTATION
#endif // ^^^ unsupported platform ^^^

#endif // ^^^ !defined(_DISABLE_STL_ANNOTATION) && !defined(_ENABLE_STL_ANNOTATION_ON_UNSUPPORTED_PLATFORMS) ^^^

#ifdef _DISABLE_STL_ANNOTATION

#ifdef _ENABLE_STL_ANNOTATION_ON_UNSUPPORTED_PLATFORMS
#error _ENABLE_STL_ANNOTATION_ON_UNSUPPORTED_PLATFORMS and _DISABLE_STL_ANNOTATION are mutually exclusive
#endif // ^^^ defined(_ENABLE_STL_ANNOTATION_ON_UNSUPPORTED_PLATFORMS) ^^^

#ifndef _DISABLE_STRING_ANNOTATION
#define _DISABLE_STRING_ANNOTATION
#endif // ^^^ !defined(_DISABLE_STRING_ANNOTATION) ^^^
#ifndef _DISABLE_VECTOR_ANNOTATION
#define _DISABLE_VECTOR_ANNOTATION
#endif // ^^^ !defined(_DISABLE_VECTOR_ANNOTATION) ^^^

#endif // ^^^ defined(_DISABLE_STL_ANNOTATION) ^^^

#ifdef _ANNOTATE_STL

#ifdef _DISABLE_STL_ANNOTATION
#error _ANNOTATE_STL and _DISABLE_STL_ANNOTATION are mutually exclusive
#endif // ^^^ defined(_DISABLE_STL_ANNOTATION) ^^^

#ifndef _ANNOTATE_STRING
#define _ANNOTATE_STRING
#endif // ^^^ !defined(_ANNOTATE_STRING) ^^^

#ifndef _ANNOTATE_VECTOR
#define _ANNOTATE_VECTOR
#endif // ^^^ !defined(_ANNOTATE_VECTOR) ^^^

#endif // ^^^ defined(_ANNOTATE_STL) ^^^

#ifdef __SANITIZE_ADDRESS__

#define _ACTIVATE_STRING_ANNOTATION
#define _INSERT_STRING_ANNOTATION
#define _ACTIVATE_VECTOR_ANNOTATION
#define _INSERT_VECTOR_ANNOTATION

#elif defined(__clang__) // ^^^ defined(__SANITIZE_ADDRESS__) / defined(__clang__) vvv

#if __has_feature(address_sanitizer)
#define _ACTIVATE_STRING_ANNOTATION
#define _INSERT_STRING_ANNOTATION
#define _ACTIVATE_VECTOR_ANNOTATION
#define _INSERT_VECTOR_ANNOTATION
#pragma comment(linker, "/INFERASANLIBS")
#endif // __has_feature(address_sanitizer)

#endif // ^^^ defined(__clang__) ^^^


#ifdef _DISABLE_STRING_ANNOTATION
#undef _ACTIVATE_STRING_ANNOTATION
#undef _INSERT_STRING_ANNOTATION
#endif // ^^^ defined(_DISABLE_STRING_ANNOTATION) ^^^
#ifdef _DISABLE_VECTOR_ANNOTATION
#undef _ACTIVATE_VECTOR_ANNOTATION
#undef _INSERT_VECTOR_ANNOTATION
#endif // ^^^ defined(_DISABLE_VECTOR_ANNOTATION) ^^^

#ifdef _ANNOTATE_STRING
#define _INSERT_STRING_ANNOTATION
#endif // ^^^ defined(_ANNOTATE_STRING) ^^^
#ifdef _ANNOTATE_VECTOR
#define _INSERT_VECTOR_ANNOTATION
#endif // ^^^ defined(_ANNOTATE_VECTOR) ^^^


#ifndef _INSERT_STRING_ANNOTATION
#pragma detect_mismatch("annotate_string", "0")
#endif // ^^^ !defined(_INSERT_STRING_ANNOTATION) ^^^
#ifndef _INSERT_VECTOR_ANNOTATION
#pragma detect_mismatch("annotate_vector", "0")
#endif // ^^^ !defined(_INSERT_VECTOR_ANNOTATION) ^^^

#ifdef _ACTIVATE_STRING_ANNOTATION
#pragma comment(lib, "stl_asan")
#pragma detect_mismatch("annotate_string", "1")
#undef _ACTIVATE_STRING_ANNOTATION
#endif // ^^^ defined(_ACTIVATE_STRING_ANNOTATION) ^^^

#ifdef _ACTIVATE_VECTOR_ANNOTATION
#pragma comment(lib, "stl_asan")
#pragma detect_mismatch("annotate_vector", "1")
#undef _ACTIVATE_VECTOR_ANNOTATION
#endif // ^^^ defined(_ACTIVATE_VECTOR_ANNOTATION) ^^^

#if defined(_INSERT_STRING_ANNOTATION) || defined(_INSERT_VECTOR_ANNOTATION)
#ifdef _M_ARM64EC
#define _STL_NATIVE_SYMBOL_PREFIX "#"
#define _STL_HYBRID_SYMBOL_PREFIX ""
#elif defined(_M_HYBRID)
#define _STL_NATIVE_SYMBOL_PREFIX "#"
#define _STL_HYBRID_SYMBOL_PREFIX "_"
#elif defined(_M_IX86)
#define _STL_NATIVE_SYMBOL_PREFIX "_"
#elif defined(_M_X64) || defined(_M_ARM) || defined(_M_ARM64)
#define _STL_NATIVE_SYMBOL_PREFIX ""
#else // ^^^ known architecture / unknown architecture vvv
#error Unknown architecture
#endif // ^^^ unknown architecture ^^^

#ifdef _STL_HYBRID_SYMBOL_PREFIX
#define _STL_DATA_ALIAS(alias, target) \
    __pragma(comment(linker, "/ALTERNATENAME:" _STL_HYBRID_SYMBOL_PREFIX #alias "=" _STL_HYBRID_SYMBOL_PREFIX #target))
// "Hybrid" architectures have different symbols for native and hybrid function flavors, we need aliases for both.
#define _STL_CODE_ALIAS(alias, target) \
    _STL_DATA_ALIAS(alias, target)     \
    __pragma(comment(linker, "/ALTERNATENAME:" _STL_NATIVE_SYMBOL_PREFIX #alias "=" _STL_NATIVE_SYMBOL_PREFIX #target))
#else
#define _STL_DATA_ALIAS(alias, target) \
    __pragma(comment(linker, "/ALTERNATENAME:" _STL_NATIVE_SYMBOL_PREFIX #alias "=" _STL_NATIVE_SYMBOL_PREFIX #target))
// Non-hybrid architectures only need one alias per function symbol.
#define _STL_CODE_ALIAS(alias, target) _STL_DATA_ALIAS(alias, target)
#endif

extern "C" {
#ifdef _INSERT_STRING_ANNOTATION
extern const bool _Asan_string_should_annotate;
_STL_DATA_ALIAS(_Asan_string_should_annotate, _Asan_string_should_annotate_default)
#endif

#ifdef _INSERT_VECTOR_ANNOTATION
extern const bool _Asan_vector_should_annotate;
_STL_DATA_ALIAS(_Asan_vector_should_annotate, _Asan_vector_should_annotate_default)
#endif

// This must match ASan's primary declaration, which isn't marked `noexcept`.
void __cdecl __sanitizer_annotate_contiguous_container(
    const void* _First, const void* _End, const void* _Old_last, const void* _New_last);

_STL_CODE_ALIAS(__sanitizer_annotate_contiguous_container, __sanitizer_annotate_contiguous_container_default)
} // extern "C"

#undef _STL_CODE_ALIAS
#undef _STL_DATA_ALIAS
#undef _STL_HYBRID_SYMBOL_PREFIX
#undef _STL_NATIVE_SYMBOL_PREFIX
#endif // ^^^ insert ASan annotations ^^^

#pragma pop_macro("new")
_STL_RESTORE_CLANG_WARNINGS
#pragma warning(pop)
#pragma pack(pop)

#endif // _STL_COMPILER_PREPROCESSOR
#endif // __MSVC_SANITIZER_ANNOTATE_CONTAINER_HPP
