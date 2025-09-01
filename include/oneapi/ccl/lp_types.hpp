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


#if defined(_MSC_VER)
#pragma pack(push, 1)
#endif


namespace ccl {
namespace v1 {


struct float16 {
uint16_t data;
};


struct bfloat16 {
uint16_t data;
};


} // namespace v1
} // namespace ccl


#if defined(_MSC_VER)
#pragma pack(pop)
#else
__attribute__((packed))
#endif