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
#include "oneapi/ccl/types.hpp"
#include "oneapi/ccl/aliases.hpp"
#include "oneapi/ccl/types_policy.hpp"
#include "oneapi/ccl/coll_attr_ids.hpp"
#include "oneapi/ccl/coll_attr_ids_traits.hpp"
#include "oneapi/ccl/coll_attr.hpp"

// Core file with PIMPL implementation
#include "coll/attr/ccl_attrs.hpp"

namespace ccl {

namespace v1 {

#define API_FORCE_INSTANTIATION_SET(class_name, IN_attrType, IN_attrId, IN_Value) \
    template CCL_API \
        typename detail::ccl_api_type_attr_traits<IN_attrType, IN_attrId>::return_type \
        class_name::set<IN_attrId, IN_Value>(const IN_Value& v);

#define API_FORCE_INSTANTIATION_GET(class_name, IN_attrType, IN_attrId) \
    template CCL_API const typename detail::ccl_api_type_attr_traits<IN_attrType, \
                                                                     IN_attrId>::return_type& \
    class_name::get<IN_attrId>() const;

#define API_FORCE_INSTANTIATION(class_name, IN_attrType, IN_attrId, IN_Value) \
    API_FORCE_INSTANTIATION_SET(class_name, IN_attrType, IN_attrId, IN_Value) \
    API_FORCE_INSTANTIATION_GET(class_name, IN_attrType, IN_attrId)

#define COMMON_API_FORCE_INSTANTIATION(class_name) \
    API_FORCE_INSTANTIATION( \
        class_name, operation_attr_id, operation_attr_id::version, ccl::library_version) \
\
    API_FORCE_INSTANTIATION_SET( \
        class_name, operation_attr_id, operation_attr_id::priority, size_t) \
    API_FORCE_INSTANTIATION_SET(class_name, operation_attr_id, operation_attr_id::priority, int) \
    API_FORCE_INSTANTIATION_SET( \
        class_name, operation_attr_id, operation_attr_id::priority, unsigned int) \
    API_FORCE_INSTANTIATION_GET(class_name, operation_attr_id, operation_attr_id::priority) \
\
    API_FORCE_INSTANTIATION(class_name, operation_attr_id, operation_attr_id::synchronous, bool) \
    API_FORCE_INSTANTIATION(class_name, operation_attr_id, operation_attr_id::to_cache, bool) \
    API_FORCE_INSTANTIATION( \
        class_name, operation_attr_id, operation_attr_id::match_id, ccl::string_class)

// Template method definitions

// allgather_attr
template <allgather_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<allgather_attr_id, attrId>::return_type
allgather_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<allgather_attr_id, attrId>{});
}

template <operation_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type
allgather_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

template <allgather_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<allgather_attr_id, attrId>::return_type&
allgather_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<allgather_attr_id, attrId>{});
}

template <operation_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type&
allgather_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

// allgatherv_attr
template <allgatherv_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<allgatherv_attr_id, attrId>::return_type
allgatherv_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<allgatherv_attr_id, attrId>{});
}

template <operation_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type
allgatherv_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

template <allgatherv_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<allgatherv_attr_id, attrId>::return_type&
allgatherv_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<allgatherv_attr_id, attrId>{});
}

template <operation_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type&
allgatherv_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

// allreduce_attr
template <allreduce_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<allreduce_attr_id, attrId>::return_type
allreduce_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<allreduce_attr_id, attrId>{});
}

template <operation_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type
allreduce_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

template <allreduce_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<allreduce_attr_id, attrId>::return_type&
allreduce_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<allreduce_attr_id, attrId>{});
}

template <operation_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type&
allreduce_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

// alltoall_attr
template <alltoall_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<alltoall_attr_id, attrId>::return_type
alltoall_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<alltoall_attr_id, attrId>{});
}

template <operation_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type
alltoall_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

template <alltoall_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<alltoall_attr_id, attrId>::return_type&
alltoall_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<alltoall_attr_id, attrId>{});
}

template <operation_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type&
alltoall_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

// alltoallv_attr
template <alltoallv_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<alltoallv_attr_id, attrId>::return_type
alltoallv_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<alltoallv_attr_id, attrId>{});
}

template <operation_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type
alltoallv_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

template <alltoallv_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<alltoallv_attr_id, attrId>::return_type&
alltoallv_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<alltoallv_attr_id, attrId>{});
}

template <operation_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type&
alltoallv_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

// barrier_attr
template <barrier_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<barrier_attr_id, attrId>::return_type
barrier_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<barrier_attr_id, attrId>{});
}

template <operation_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type
barrier_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

template <barrier_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<barrier_attr_id, attrId>::return_type&
barrier_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<barrier_attr_id, attrId>{});
}

template <operation_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type&
barrier_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

// broadcast_attr
template <broadcast_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<broadcast_attr_id, attrId>::return_type
broadcast_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<broadcast_attr_id, attrId>{});
}

template <operation_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type
broadcast_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

template <broadcast_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<broadcast_attr_id, attrId>::return_type&
broadcast_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<broadcast_attr_id, attrId>{});
}

template <operation_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type&
broadcast_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

// pt2pt_attr
template <pt2pt_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<pt2pt_attr_id, attrId>::return_type
pt2pt_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<pt2pt_attr_id, attrId>{});
}

template <operation_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type
pt2pt_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

template <pt2pt_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<pt2pt_attr_id, attrId>::return_type&
pt2pt_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<pt2pt_attr_id, attrId>{});
}

template <operation_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type&
pt2pt_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

// reduce_attr
template <reduce_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<reduce_attr_id, attrId>::return_type
reduce_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<reduce_attr_id, attrId>{});
}

template <operation_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type
reduce_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

template <reduce_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<reduce_attr_id, attrId>::return_type&
reduce_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<reduce_attr_id, attrId>{});
}

template <operation_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type&
reduce_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

// reduce_scatter_attr
template <reduce_scatter_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<reduce_scatter_attr_id, attrId>::return_type
reduce_scatter_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<reduce_scatter_attr_id, attrId>{});
}

template <operation_attr_id attrId, class Value>
typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type
reduce_scatter_attr::set(const Value& v) {
    return get_impl()->set_attribute_value(
        v, detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

template <reduce_scatter_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<reduce_scatter_attr_id, attrId>::return_type&
reduce_scatter_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<reduce_scatter_attr_id, attrId>{});
}

template <operation_attr_id attrId>
const typename detail::ccl_api_type_attr_traits<operation_attr_id, attrId>::return_type&
reduce_scatter_attr::get() const {
    return get_impl()->get_attribute_value(
        detail::ccl_api_type_attr_traits<operation_attr_id, attrId>{});
}

/**
 * allgather coll attributes
 */
CCL_API allgather_attr::allgather_attr(allgather_attr&& src) : base_t(std::move(src)) {}

CCL_API allgather_attr::allgather_attr(const allgather_attr& src) : base_t(src) {}

CCL_API allgather_attr::allgather_attr(
    const typename detail::ccl_api_type_attr_traits<operation_attr_id,
                                                    operation_attr_id::version>::type& version)
        : base_t(impl_value_t(new impl_t(version))) {}

CCL_API allgather_attr& allgather_attr::operator=(allgather_attr&& src) noexcept {
    this->acc_policy_t::create(this, std::move(src));
    return *this;
}

CCL_API allgather_attr& allgather_attr::operator=(const allgather_attr& src) {
    this->acc_policy_t::create(this, src);
    return *this;
}

CCL_API allgather_attr::~allgather_attr() {}

/**
 * allgatherv coll attributes
 */
CCL_API allgatherv_attr::allgatherv_attr(allgatherv_attr&& src) : base_t(std::move(src)) {}

CCL_API allgatherv_attr::allgatherv_attr(const allgatherv_attr& src) : base_t(src) {}

CCL_API allgatherv_attr::allgatherv_attr(
    const typename detail::ccl_api_type_attr_traits<operation_attr_id,
                                                    operation_attr_id::version>::type& version)
        : base_t(impl_value_t(new impl_t(version))) {}

CCL_API allgatherv_attr& allgatherv_attr::operator=(allgatherv_attr&& src) noexcept {
    this->acc_policy_t::create(this, std::move(src));
    return *this;
}

CCL_API allgatherv_attr& allgatherv_attr::operator=(const allgatherv_attr& src) {
    this->acc_policy_t::create(this, src);
    return *this;
}

CCL_API allgatherv_attr::~allgatherv_attr() {}

/**
 * allreduce coll attributes
 */
CCL_API allreduce_attr::allreduce_attr(allreduce_attr&& src) : base_t(std::move(src)) {}

CCL_API allreduce_attr::allreduce_attr(const allreduce_attr& src) : base_t(src) {}

CCL_API allreduce_attr::allreduce_attr(
    const typename detail::ccl_api_type_attr_traits<operation_attr_id,
                                                    operation_attr_id::version>::type& version)
        : base_t(impl_value_t(new impl_t(version))) {}

CCL_API allreduce_attr& allreduce_attr::operator=(allreduce_attr&& src) noexcept {
    this->acc_policy_t::create(this, std::move(src));
    return *this;
}

CCL_API allreduce_attr& allreduce_attr::operator=(const allreduce_attr& src) {
    this->acc_policy_t::create(this, src);
    return *this;
}

CCL_API allreduce_attr::~allreduce_attr() {}

/**
 * alltoall coll attributes
 */
CCL_API alltoall_attr::alltoall_attr(alltoall_attr&& src) : base_t(std::move(src)) {}

CCL_API alltoall_attr::alltoall_attr(const alltoall_attr& src) : base_t(src) {}

CCL_API alltoall_attr::alltoall_attr(
    const typename detail::ccl_api_type_attr_traits<operation_attr_id,
                                                    operation_attr_id::version>::type& version)
        : base_t(impl_value_t(new impl_t(version))) {}

CCL_API alltoall_attr& alltoall_attr::operator=(alltoall_attr&& src) noexcept {
    this->acc_policy_t::create(this, std::move(src));
    return *this;
}

CCL_API alltoall_attr& alltoall_attr::operator=(const alltoall_attr& src) {
    this->acc_policy_t::create(this, src);
    return *this;
}

CCL_API alltoall_attr::~alltoall_attr() {}

/**
 * alltoallv coll attributes
 */
CCL_API alltoallv_attr::alltoallv_attr(alltoallv_attr&& src) : base_t(std::move(src)) {}

CCL_API alltoallv_attr::alltoallv_attr(const alltoallv_attr& src) : base_t(src) {}

CCL_API alltoallv_attr::alltoallv_attr(
    const typename detail::ccl_api_type_attr_traits<operation_attr_id,
                                                    operation_attr_id::version>::type& version)
        : base_t(impl_value_t(new impl_t(version))) {}

CCL_API alltoallv_attr& alltoallv_attr::operator=(alltoallv_attr&& src) noexcept {
    this->acc_policy_t::create(this, std::move(src));
    return *this;
}

CCL_API alltoallv_attr& alltoallv_attr::operator=(const alltoallv_attr& src) {
    this->acc_policy_t::create(this, src);
    return *this;
}

CCL_API alltoallv_attr::~alltoallv_attr() {}

/**
 * barrier coll attributes
 */
CCL_API barrier_attr::barrier_attr(barrier_attr&& src) : base_t(std::move(src)) {}

CCL_API barrier_attr::barrier_attr(const barrier_attr& src) : base_t(src) {}

CCL_API barrier_attr::barrier_attr(
    const typename detail::ccl_api_type_attr_traits<operation_attr_id,
                                                    operation_attr_id::version>::type& version)
        : base_t(impl_value_t(new impl_t(version))) {}

CCL_API barrier_attr& barrier_attr::operator=(barrier_attr&& src) noexcept {
    this->acc_policy_t::create(this, std::move(src));
    return *this;
}

CCL_API barrier_attr& barrier_attr::operator=(const barrier_attr& src) {
    this->acc_policy_t::create(this, src);
    return *this;
}

CCL_API barrier_attr::~barrier_attr() {}

/**
 * broadcast coll attributes
 */
CCL_API broadcast_attr::broadcast_attr(broadcast_attr&& src) : base_t(std::move(src)) {}

CCL_API broadcast_attr::broadcast_attr(const broadcast_attr& src) : base_t(src) {}

CCL_API broadcast_attr::broadcast_attr(
    const typename detail::ccl_api_type_attr_traits<operation_attr_id,
                                                    operation_attr_id::version>::type& version)
        : base_t(impl_value_t(new impl_t(version))) {}

CCL_API broadcast_attr& broadcast_attr::operator=(broadcast_attr&& src) noexcept {
    this->acc_policy_t::create(this, std::move(src));
    return *this;
}

CCL_API broadcast_attr& broadcast_attr::operator=(const broadcast_attr& src) {
    this->acc_policy_t::create(this, src);
    return *this;
}

CCL_API broadcast_attr::~broadcast_attr() {}

/**
 * point to point operation attributes
 */
CCL_API pt2pt_attr::pt2pt_attr(pt2pt_attr&& src) : base_t(std::move(src)) {}

CCL_API pt2pt_attr::pt2pt_attr(const pt2pt_attr& src) : base_t(src) {}

CCL_API pt2pt_attr::pt2pt_attr(
    const typename detail::ccl_api_type_attr_traits<operation_attr_id,
                                                    operation_attr_id::version>::type& version)
        : base_t(impl_value_t(new impl_t(version))) {}

CCL_API pt2pt_attr& pt2pt_attr::operator=(pt2pt_attr&& src) noexcept {
    this->acc_policy_t::create(this, std::move(src));
    return *this;
}

CCL_API pt2pt_attr& pt2pt_attr::operator=(const pt2pt_attr& src) {
    this->acc_policy_t::create(this, src);
    return *this;
}

CCL_API pt2pt_attr::~pt2pt_attr() {}

/**
 * reduce coll attributes
 */
CCL_API reduce_attr::reduce_attr(reduce_attr&& src) : base_t(std::move(src)) {}

CCL_API reduce_attr::reduce_attr(const reduce_attr& src) : base_t(src) {}

CCL_API reduce_attr::reduce_attr(
    const typename detail::ccl_api_type_attr_traits<operation_attr_id,
                                                    operation_attr_id::version>::type& version)
        : base_t(impl_value_t(new impl_t(version))) {}

CCL_API reduce_attr& reduce_attr::operator=(reduce_attr&& src) noexcept {
    this->acc_policy_t::create(this, std::move(src));
    return *this;
}

CCL_API reduce_attr& reduce_attr::operator=(const reduce_attr& src) {
    this->acc_policy_t::create(this, src);
    return *this;
}

CCL_API reduce_attr::~reduce_attr() {}

/**
 * reduce_scatter coll attributes
 */
CCL_API reduce_scatter_attr::reduce_scatter_attr(reduce_scatter_attr&& src)
        : base_t(std::move(src)) {}

CCL_API reduce_scatter_attr::reduce_scatter_attr(const reduce_scatter_attr& src) : base_t(src) {}

CCL_API reduce_scatter_attr::reduce_scatter_attr(
    const typename detail::ccl_api_type_attr_traits<operation_attr_id,
                                                    operation_attr_id::version>::type& version)
        : base_t(impl_value_t(new impl_t(version))) {}

CCL_API reduce_scatter_attr& reduce_scatter_attr::operator=(reduce_scatter_attr&& src) noexcept {
    this->acc_policy_t::create(this, std::move(src));
    return *this;
}

CCL_API reduce_scatter_attr& reduce_scatter_attr::operator=(const reduce_scatter_attr& src) {
    this->acc_policy_t::create(this, src);
    return *this;
}

CCL_API reduce_scatter_attr::~reduce_scatter_attr() {}

/**
 * Force instantiations
 */
COMMON_API_FORCE_INSTANTIATION(allgather_attr)
COMMON_API_FORCE_INSTANTIATION(allgatherv_attr)
COMMON_API_FORCE_INSTANTIATION(allreduce_attr)
COMMON_API_FORCE_INSTANTIATION(alltoall_attr)
COMMON_API_FORCE_INSTANTIATION(alltoallv_attr)
COMMON_API_FORCE_INSTANTIATION(barrier_attr)
COMMON_API_FORCE_INSTANTIATION(broadcast_attr)
COMMON_API_FORCE_INSTANTIATION(pt2pt_attr)
COMMON_API_FORCE_INSTANTIATION(reduce_attr)
COMMON_API_FORCE_INSTANTIATION(reduce_scatter_attr)

API_FORCE_INSTANTIATION(allreduce_attr,
                        allreduce_attr_id,
                        allreduce_attr_id::reduction_fn,
                        ccl::reduction_fn)
API_FORCE_INSTANTIATION(reduce_attr,
                        reduce_attr_id,
                        reduce_attr_id::reduction_fn,
                        ccl::reduction_fn)
API_FORCE_INSTANTIATION(reduce_scatter_attr,
                        reduce_scatter_attr_id,
                        reduce_scatter_attr_id::reduction_fn,
                        ccl::reduction_fn)
API_FORCE_INSTANTIATION(pt2pt_attr,
                        pt2pt_attr_id,
                        pt2pt_attr_id::group_id,
                        int /*type of group id*/)

#undef API_FORCE_INSTANTIATION
#undef COMMON_API_FORCE_INSTANTIATION
#undef COMMA

} // namespace v1

} // namespace ccl
