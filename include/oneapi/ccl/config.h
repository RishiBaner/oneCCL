#pragma once


#define CCL_ENABLE_ZE 0
#define CCL_ENABLE_SYCL 0


#if defined(_WIN32) || defined(_WIN64)
#define CCL_PLATFORM_WINDOWS
#else
#define CCL_PLATFORM_POSIX
#endif




// === File: helpers.cmake ===
//# Helper cmake module (partial excerpt)


if (MSVC)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /EHsc /W4 /wd4668 /wd4251 /wd4275 /wd4996 -DCCL_ENABLE_ITT=1 -DCCL_ENABLE_PROFILING=1 -DCCL_ENABLE_PMIX=1 -DCCL_ENABLE_UMF=1 -DCCL_ENABLE_STUB_BACKEND=1 -openmp -DCCL_ENABLE_OMP=1 -DCCL_ENABLE_SYCL_INTEROP_EVENT=1 /bigobj")
else()
add_compile_options(-Wall -Wextra -Wno-implicit-fallthrough)
endif()




// === File: CMakeLists.txt (Top-Level Patch Snippet) ===
# Add this near top after project(...) or in global config section


if (MSVC)
message(STATUS "Configuring build for MSVC")
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /EHsc /W4 /wd4668 /wd4251 /wd4275 /wd4996 -DCCL_ENABLE_ITT=1 -DCCL_ENABLE_PROFILING=1 -DCCL_ENABLE_PMIX=1 -DCCL_ENABLE_UMF=1 -DCCL_ENABLE_STUB_BACKEND=1 -openmp -DCCL_ENABLE_OMP=1 -DCCL_ENABLE_SYCL_INTEROP_EVENT=1 /bigobj")
endif()


# Remove or guard lines like:
# add_compile_options(-Wno-implicit-fallthrough)
# Because these are not MSVC-compatible
