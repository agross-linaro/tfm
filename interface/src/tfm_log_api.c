/*
 * Copyright (c) 2018, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_log_defs.h"
#include "tfm_ns_lock.h"

enum tfm_log_err tfm_log_retrieve(uint32_t size,
                                  int32_t start,
                                  uint8_t *buffer,
                                  struct tfm_log_info *info)
{
    return tfm_ns_lock_svc_dispatch(SVC_TFM_LOG_RETRIEVE,
                                    size,
                                    (uint32_t)start,
                                    (uint32_t)buffer,
                                    (uint32_t)info);
}

enum tfm_log_err tfm_log_get_info(struct tfm_log_info *info)
{
    return tfm_ns_lock_svc_dispatch(SVC_TFM_LOG_GET_INFO,
                                    (uint32_t)info,
                                    0,
                                    0,
                                    0);
}

enum tfm_log_err tfm_log_delete_items(uint32_t num_items,
                                      uint32_t *rem_items)
{
    return tfm_ns_lock_svc_dispatch(SVC_TFM_LOG_DELETE_ITEMS,
                                    num_items,
                                    (uint32_t)rem_items,
                                    0,
                                    0);
}
