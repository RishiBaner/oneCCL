#
# Copyright 2016-2020 Intel Corporation
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
#common CMakeList.txt to build CCL, ATL, tests

# === Modified CMakeLists.txt for oneCCL on Windows (MSVC) and Linux ===

cmake_minimum_required(VERSION 3.10)
project(oneCCL LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Detect MSVC and apply Windows-specific settings
if (MSVC)
    message(STATUS "Building with MSVC on Windows")
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
else()
    message(STATUS "Building on Unix-like OS")
    add_compile_options(-Wall -Wextra -Wno-implicit-fallthrough)
endif()

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include source directory and headers
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

# Add subdirectories if needed
add_subdirectory(src)

# Define your library target
file(GLOB_RECURSE CCL_SRC
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_library(ccl_objects STATIC ${CCL_SRC})

# If you need to link against other libraries:
# target_link_libraries(ccl_objects some_external_lib)

# Install rules
install(TARGETS ccl_objects
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include)

# Optional definitions (controlled by config.h.in)
option(CCL_ENABLE_ZE "Enable Level Zero" OFF)
option(CCL_ENABLE_SYCL "Enable SYCL" OFF)

configure_file(${PROJECT_SOURCE_DIR}/include/oneapi/ccl/config.h.in
               ${PROJECT_BINARY_DIR}/include/oneapi/ccl/config.h)

include_directories(${PROJECT_BINARY_DIR}/include)
