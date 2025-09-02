/*
 Copyright 2016-2020 Intel Corporation
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
     http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#pragma once

#include <cstdint>
#include "oneapi/ccl/types.hpp"
#include "oneapi/ccl/lp_types.hpp"

namespace ccl {

// C++11 and later guarantee these types are in the std namespace via <cstdint>
using int8 = std::int8_t;
using uint8 = std::uint8_t;
using int16 = std::int16_t;
using uint16 = std::uint16_t;
using int32 = std::int32_t;
using uint32 = std::uint32_t;
using int64 = std::int64_t;
using uint64 = std::uint64_t;

// Forward declaration of template class
template <typename T>
struct type_info;

// Base template for unsupported types
template <typename T>
struct type_info : ccl_type_info_export<T, 0, datatype::int8, false, false> {};

// Specializations for supported types
template <>
struct type_info<ccl::int8>
        : ccl_type_info_export<ccl::int8, sizeof(ccl::int8), datatype::int8, false, true> {};
template <>
struct type_info<ccl::uint8>
        : ccl_type_info_export<ccl::uint8, sizeof(ccl::uint8), datatype::uint8, false, true> {};
template <>
struct type_info<ccl::int16>
        : ccl_type_info_export<ccl::int16, sizeof(ccl::int16), datatype::int16, false, true> {};
template <>
struct type_info<ccl::uint16>
        : ccl_type_info_export<ccl::uint16, sizeof(ccl::uint16), datatype::uint16, false, true> {};
template <>
struct type_info<ccl::int32>
        : ccl_type_info_export<ccl::int32, sizeof(ccl::int32), datatype::int32, false, true> {};
template <>
struct type_info<ccl::uint32>
        : ccl_type_info_export<ccl::uint32, sizeof(ccl::uint32), datatype::uint32, false, true> {};
template <>
struct type_info<ccl::int64>
        : ccl_type_info_export<ccl::int64, sizeof(ccl::int64), datatype::int64, false, true> {};
template <>
struct type_info<ccl::uint64>
        : ccl_type_info_export<ccl::uint64, sizeof(ccl::uint64), datatype::uint64, false, true> {};

template <>
struct type_info<float> : ccl_type_info_export<float, sizeof(float), datatype::float32, false, true> {};
template <>
struct type_info<double>
        : ccl_type_info_export<double, sizeof(double), datatype::float64, false, true> {};

template <>
struct type_info<ccl::v1::float16>
        : ccl_type_info_export<ccl::v1::float16, sizeof(ccl::v1::float16), datatype::float16, true, true> {};
template <>
struct type_info<ccl::v1::bfloat16>
        : ccl_type_info_export<ccl::v1::bfloat16, sizeof(ccl::v1::bfloat16), datatype::bfloat16, true, true> {};

// Type support checkers
template <class T>
constexpr bool is_native_type_supported() {
    return type_info<T>::is_supported && !type_info<T>::is_class;
}

template <class T>
constexpr bool is_class_supported() {
    return type_info<T>::is_supported && type_info<T>::is_class;
}

} // namespace ccl
