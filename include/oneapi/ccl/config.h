#pragma once

#ifdef _MSC_VER
#   define CCL_FORCEINLINE __forceinline
#   define CCL_FORCENOINLINE __declspec(noinline)
#   define CCL_DEPRECATED __declspec(deprecated)
#   define CCL_DEPRECATED_ENUM_FIELD __declspec(deprecated)
#else // for __GNUC__ and __clang__
#   define CCL_FORCEINLINE   inline __attribute__((always_inline))
#   define CCL_FORCENOINLINE __attribute__((noinline))
#   if (__GNUC__ >= 6) || defined(__clang__)
#       define CCL_DEPRECATED_ENUM_FIELD __attribute__((deprecated))
#   else
#       define CCL_DEPRECATED_ENUM_FIELD
#   endif

#   if defined(__GNUC__) || defined(__clang__)
#       define CCL_DEPRECATED __attribute__((deprecated))
#   else
#       define CCL_DEPRECATED
#   endif
#endif

/* All symbols shall be internal unless marked as CCL_API */
#if defined(__linux__)
#   if __GNUC__ >= 4
#       define CCL_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
#   else
#       define CCL_HELPER_DLL_EXPORT
#   endif
#elif defined(_WIN32)
#   if defined(CCL_DLL_EXPORTS)
#       define CCL_HELPER_DLL_EXPORT __declspec(dllexport)
#   else
#       define CCL_HELPER_DLL_EXPORT __declspec(dllimport)
#   endif
#else // Other OSes
#   define CCL_HELPER_DLL_EXPORT
#endif

#define CCL_API CCL_HELPER_DLL_EXPORT

#define ONECCL_SPEC_VERSION "1.0"

#define CCL_MAJOR_VERSION           2021
#define CCL_MINOR_VERSION           16
#define CCL_UPDATE_VERSION          0
#define CCL_PRODUCT_STATUS     "Gold"
#define CCL_PRODUCT_BUILD_DATE "2025-09-01T 03:04:03Z"
#define CCL_PRODUCT_FULL       "Gold-2021.16.0 2025-09-01T 03:04:03Z (master/b5a4144)"

#if defined(SYCL_LANGUAGE_VERSION) && defined (__INTEL_LLVM_COMPILER)
#define CCL_ENABLE_SYCL
#define CCL_ENABLE_ZE
#endif
