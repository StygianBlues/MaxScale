/*
 * Copyright (c) 2018 MariaDB Corporation Ab
 *
 * Use of this software is governed by the Business Source License included
 * in the LICENSE.TXT file and at www.mariadb.com/bsl11.
 *
 * Change Date: 2024-01-15
 *
 * On the date above, in accordance with the Business Source License, use
 * of this software will be governed by version 2 or later of the General
 * Public License.
 */
#pragma once

#include <maxscale/ccdefs.hh>
#include <maxscale/config2.hh>
#include "cache_storage_api.hh"

enum cache_selects_t
{
    CACHE_SELECTS_ASSUME_CACHEABLE,
    CACHE_SELECTS_VERIFY_CACHEABLE,
};

const cache_selects_t CACHE_DEFAULT_SELECTS = CACHE_SELECTS_ASSUME_CACHEABLE;

enum cache_in_trxs_t
{
    // Do NOT change the order. Code relies upon NEVER < READ_ONLY < ALL.
    CACHE_IN_TRXS_NEVER,
    CACHE_IN_TRXS_READ_ONLY,
    CACHE_IN_TRXS_ALL,
};

enum cache_users_t
{
    CACHE_USERS_ISOLATED,
    CACHE_USERS_MIXED
};

const cache_thread_model_t CACHE_DEFAULT_THREAD_MODEL = CACHE_THREAD_MODEL_ST;

class CacheConfig : public config::Configuration
{
public:
    CacheConfig(const std::string& name);
    ~CacheConfig();

    CacheConfig(const CacheConfig&) = delete;
    CacheConfig& operator=(const CacheConfig&) = delete;

    using milliseconds = std::chrono::milliseconds;

    config::String                     storage;
    config::String                     storage_options;
    config::Duration<milliseconds>     hard_ttl;
    config::Duration<milliseconds>     soft_ttl;
    config::Count                      max_resultset_rows;
    config::Size                       max_resultset_size;
    config::Count                      max_count;
    config::Size                       max_size;
    config::Path                       rules;
    config::BitMask                    debug;
    config::Enum<cache_thread_model_t> thread_model;
    config::Enum<cache_selects_t>      selects;
    config::Enum<cache_in_trxs_t>      cache_in_trxs;
    config::Bool                       enabled;
    config::Enum<cache_invalidate_t>   invalidate;
    config::Bool                       clear_cache_on_parse_errors;
    config::Enum<cache_users_t>        users;

    static const config::Specification& specification()
    {
        return s_specification;
    }

private:
    bool post_configure(const mxs::ConfigParameters& params) override;

private:
    static config::Specification s_specification;

    static config::ParamString                     s_storage;
    static config::ParamString                     s_storage_options;
    static config::ParamDuration<milliseconds>     s_hard_ttl;
    static config::ParamDuration<milliseconds>     s_soft_ttl;
    static config::ParamCount                      s_max_resultset_rows;
    static config::ParamSize                       s_max_resultset_size;
    static config::ParamCount                      s_max_count;
    static config::ParamSize                       s_max_size;
    static config::ParamPath                       s_rules;
    static config::ParamBitMask                    s_debug;
    static config::ParamEnum<cache_thread_model_t> s_thread_model;
    static config::ParamEnum<cache_selects_t>      s_selects;
    static config::ParamEnum<cache_in_trxs_t>      s_cache_in_trxs;
    static config::ParamBool                       s_enabled;
    static config::ParamEnum<cache_invalidate_t>   s_invalidate;
    static config::ParamBool                       s_clear_cache_on_parse_errors;
    static config::ParamEnum<cache_users_t>        s_users;
};