/*
 * Copyright (c) 2017-2018, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SST_OBJECT_SYSTEM_H__
#define __SST_OBJECT_SYSTEM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <inttypes.h>
#include "tfm_sst_defs.h"

/**
 * \brief Prepares the secure storage system for usage, populating internal
 *        structures.
 *        It identifies and validates the system metadata.
 *
 * \return Returns PSA_SST_ERR_SUCCESS or PSA_SST_ERR_INIT_FAILED
 */
enum psa_sst_err_t sst_system_prepare(void);

/**
 * \brief Creates a new object with given object UUID.
 *
 * \param[in] uuid     Object UUID
 * \param[in] s_token  Pointer to the asset's token \ref tfm_sst_token_t
 * \param[in] type     Object type
 * \param[in] size     Object size
 *
 * \return Returns error code specified in \ref psa_sst_err_t
 */
enum psa_sst_err_t sst_object_create(uint32_t uuid,
                                     const struct tfm_sst_token_t *s_token,
                                     uint32_t type, uint32_t size);

/**
 * \brief Gets object's data referenced by object UUID, and stores it
 *        in the data buffer.
 *
 * \param[in]  uuid     Object UUID
 * \param[in]  s_token  Pointer to the asset's token \ref tfm_sst_token_t
 * \param[out] data     Data buffer to store the object data
 * \param[in]  offset   Offset from where the read is going to start
 * \param[in]  size     Data buffer size
 *
 * \return Returns error code specified in \ref psa_sst_err_t
 */
enum psa_sst_err_t sst_object_read(uint32_t uuid,
                                   const struct tfm_sst_token_t *s_token,
                                   uint8_t *data, uint32_t offset,
                                   uint32_t size);
/**
 * \brief Writes data into the object referenced by object UUID.
 *
 * \param[in] uuid     Object UUID
 * \param[in] s_token  Pointer to the asset's token \ref tfm_sst_token_t
 * \param[in] data     Data buffer to write into object object
 * \param[in] offset   Offset from where the write is going to start
 * \param[in] size     Data buffer size
 *
 * \return Returns number of bytes read or a relevant error \ref psa_sst_err_t
 */
enum psa_sst_err_t sst_object_write(uint32_t uuid,
                                    const struct tfm_sst_token_t *s_token,
                                    const uint8_t *data, uint32_t offset,
                                    uint32_t size);
/**
 * \brief Deletes the object referenced by object UUID.
 *
 * \param[in] uuid  Object UUID
 * \param[in] s_token  Pointer to the asset's token \ref tfm_sst_token_t
 *
 * \return Returns error code specified in \ref psa_sst_err_t
 */
enum psa_sst_err_t sst_object_delete(uint32_t uuid,
                                     const struct tfm_sst_token_t *s_token);

/**
 * \brief Gets the object information referenced by object UUID.
 *
 * \param[in]  uuid     Object UUID
 * \param[in]  s_token  Pointer to the asset's token \ref tfm_sst_token_t
 * \param[out] info     Pointer to store the object's information
 *                      \ref struct psa_sst_asset_info_t
 *
 * \return Returns error code specified in \ref psa_sst_err_t
 */
enum psa_sst_err_t sst_object_get_info(uint32_t uuid,
                                       const struct tfm_sst_token_t *s_token,
                                       struct psa_sst_asset_info_t *info);

/**
 * \brief Gets the object attributes referenced by object UUID.
 *
 * \param[in]  uuid     Object UUID
 * \param[in]  s_token  Pointer to the asset's token \ref tfm_sst_token_t
 * \param[out] attrs    Pointer to store the object's attributes
 *                      \ref psa_sst_asset_attrs_t
 *
 * \return Returns error code as specified in \ref psa_sst_err_t
 */
enum psa_sst_err_t sst_object_get_attributes(uint32_t uuid,
                                          const struct tfm_sst_token_t *s_token,
                                          struct psa_sst_asset_attrs_t *attrs);
/**
 * \brief Sets the specific object attributes referenced by object UUID.
 *
 * \param[in] uuid     Object UUID \ref tfm_sst_token_t
 * \param[in] s_token  Pointer to the asset's token \ref tfm_sst_token_t
 * \param[in] attrs    Pointer to new the object's attributes
 *                     \ref psa_sst_asset_attrs_t
 *
 * \return Returns error code as specified in \ref psa_sst_err_t
 */
enum psa_sst_err_t sst_object_set_attributes(uint32_t uuid,
                                     const struct tfm_sst_token_t *s_token,
                                     const struct psa_sst_asset_attrs_t *attrs);

/**
 * \brief Wipes secure storage system and all object data.
 *
 * \return Returns error code specified in \ref sst_errno_t
 */
enum psa_sst_err_t sst_system_wipe_all(void);

#ifdef __cplusplus
}
#endif

#endif /* __SST_OBJECT_SYSTEM_H__ */
