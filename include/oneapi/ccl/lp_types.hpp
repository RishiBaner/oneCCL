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
#include <cmath>
#include <utility>

// Use #pragma pack, which is supported by MSVC, GCC, and Clang for portability.
#pragma pack(push, 1)

namespace ccl {
namespace v1 {
/**
 * @brief A 16-bit half-precision floating-point type.
 *
 * This type has 1 sign bit, 5 exponent bits, and 10 mantissa bits.
 * It provides basic conversion to and from 32-bit float.
 */
struct float16 {
    uint16_t data;

    float16() = default;

    /**
     * @brief Constructs a float16 from a 32-bit float.
     * This conversion truncates the mantissa and flushes subnormals to zero.
     * @param val The float value to convert.
     */
    explicit float16(float val) {
        uint32_t f_bits;
        std::memcpy(&f_bits, &val, sizeof(f_bits));

        uint16_t h_sign = (f_bits >> 16) & 0x8000;
        int32_t f_exp = (f_bits >> 23) & 0xFF;
        uint32_t f_mant = f_bits & 0x7FFFFF;

        if (f_exp == 0xFF) { // Infinity or NaN
            data = h_sign | 0x7C00 | (f_mant ? 0x0200 : 0);
            return;
        }

        // Unbias the float exponent
        f_exp -= 127;

        if (f_exp > 15) { // Overflow to infinity
            data = h_sign | 0x7C00;
        } else if (f_exp < -14) { // Underflow to zero (subnormals are flushed)
            data = h_sign;
        } else { // Normalized half
            data = h_sign | ((f_exp + 15) << 10) | (f_mant >> 13);
        }
    }

    /**
     * @brief Converts a float16 back to a 32-bit float.
     * @return The converted float value.
     */
    operator float() const {
        uint32_t h_sign = (data & 0x8000);
        uint32_t h_exp = (data >> 10) & 0x1F;
        uint32_t h_mant = data & 0x03FF;

        uint32_t f_bits;

        if (h_exp == 0) { // Zero or denormalized
            if (h_mant == 0) {
                f_bits = h_sign << 16; // Zero
            } else {
                // Denormalized half to normalized float
                int32_t exp = 1 - 15; // Unbias denormal exponent
                while ((h_mant & 0x0400) == 0) {
                    h_mant <<= 1;
                    exp--;
                }
                h_mant &= ~0x0400; // Remove implicit 1
                f_bits = (h_sign << 16) | ((exp + 127) << 23) | (h_mant << 13);
            }
        } else if (h_exp == 0x1F) { // Infinity or NaN
            f_bits = (h_sign << 16) | 0x7F800000 | (h_mant << 13);
        } else { // Normalized
            f_bits = (h_sign << 16) | ((h_exp - 15 + 127) << 23) | (h_mant << 13);
        }

        float f_val;
        std::memcpy(&f_val, &f_bits, sizeof(float));
        return f_val;
    }
};

/**
 * @brief A 16-bit brain floating-point type.
 *
 * This type has 1 sign bit, 8 exponent bits, and 7 mantissa bits.
 * It has the same dynamic range as a 32-bit float, but with less precision.
 */
struct bfloat16 {
    uint16_t data;

    bfloat16() = default;

    /**
     * @brief Constructs a bfloat16 from a 32-bit float.
     *
     * The conversion is done by taking the upper 16 bits of the float's
     * 32-bit representation (truncation). This is a common and fast method.
     *
     * @param val The float value to convert.
     */
    explicit bfloat16(float val) {
        uint32_t val_uint;
        std::memcpy(&val_uint, &val, sizeof(uint32_t));
        data = static_cast<uint16_t>(val_uint >> 16);
    }

    /**
     * @brief Converts a bfloat16 back to a 32-bit float.
     *
     * The lower 16 bits of the float's mantissa are filled with zeros.
     *
     * @return The converted float value.
     */
    operator float() const {
        uint32_t res_uint = static_cast<uint32_t>(data) << 16;
        float res_float;
        std::memcpy(&res_float, &res_uint, sizeof(float));
        return res_float;
    }
};

} // namespace v1
} // namespace ccl

#pragma pack(pop)
