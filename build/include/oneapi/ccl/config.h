#pragma once

/* CMake-configured feature macros */
#define CCL_ENABLE_ZE 0
#define CCL_ENABLE_SYCL 0

/* Platform macros */
#if defined(_WIN32) || defined(_WIN64)
  #define CCL_PLATFORM_WINDOWS
#elif defined(__APPLE__)
  #include <TargetConditionals.h>
  #define CCL_PLATFORM_POSIX
  #if TARGET_OS_MAC
    #define CCL_PLATFORM_MACOS
  #endif
#else
  #define CCL_PLATFORM_POSIX
#endif

/* Compiler macros */
#if defined(_MSC_VER)
  #define CCL_COMPILER_MSVC
#elif defined(__clang__)
  #define CCL_COMPILER_CLANG
#elif defined(__GNUC__)
  #define CCL_COMPILER_GCC
#else
  #error "Unsupported compiler"
#endif

/* C++ version check */
#if defined(_MSC_VER) && !defined(__clang__)
  #if _MSVC_LANG < 201103L
    #error "C++11 or higher is required"
  #endif
#elif __cplusplus < 201103L
    #error "C++11 or higher is required"
#endif

/* Debug mode */
#ifndef NDEBUG
  #define CCL_DEBUG_MODE
#else
  #define CCL_RELEASE_MODE
#endif
