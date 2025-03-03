/*
 *  Declaration of context structures for use with the PSA driver wrapper
 *  interface. This file contains the context structures for 'primitive'
 *  operations, i.e. those operations which do not rely on other contexts.
 *
 *  Warning: This file will be auto-generated in the future.
 *
 * \note This file may not be included directly. Applications must
 * include psa/crypto.h.
 *
 * \note This header and its content is not part of the Mbed TLS API and
 * applications must not depend on it. Its main purpose is to define the
 * multi-part state objects of the PSA drivers included in the cryptographic
 * library. The definition of these objects are then used by crypto_struct.h
 * to define the implementation-defined types of PSA multi-part state objects.
 */
/*  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef PSA_CRYPTO_DRIVER_CONTEXTS_PRIMITIVES_H
#define PSA_CRYPTO_DRIVER_CONTEXTS_PRIMITIVES_H

#include "common.h"

#include "psa/crypto_driver_common.h"

/* Include the context structure definitions for those drivers that were
 * declared during the autogeneration process. */
#if defined(PSA_CRYPTO_DRIVER_CC3XX)
#include "cc3xx_crypto_primitives.h"
#endif /* PSA_CRYPTO_DRIVER_CC3XX */

#if defined(PSA_CRYPTO_DRIVER_HAS_CIPHER_SUPPORT_OBERON)
#include "oberon_cipher.h"
#endif
#if defined(PSA_CRYPTO_DRIVER_HAS_HASH_SUPPORT_OBERON)
#include "oberon_hash.h"
#endif


/* Include the context structure definitions for the Mbed TLS software drivers */
#include "psa/crypto_builtin_primitives.h"

/* Define the context to be used for an operation that is executed through the
 * PSA Driver wrapper layer as the union of all possible driver's contexts.
 *
 * The union members are the driver's context structures, and the member names
 * are formatted as `'drivername'_ctx`. This allows for procedural generation
 * of both this file and the content of psa_crypto_driver_wrappers.c */

typedef union {
    unsigned dummy; /* Make sure this union is always non-empty */
#if defined(MBEDTLS_PSA_BUILTIN_HAS_HASH_SUPPORT)
    mbedtls_psa_hash_operation_t mbedtls_ctx;
#endif
#if defined(PSA_CRYPTO_DRIVER_CC3XX)
    cc3xx_hash_operation_t cc3xx_driver_ctx;
#endif
#if defined(PSA_CRYPTO_DRIVER_HAS_HASH_SUPPORT_OBERON)
    oberon_hash_operation_t oberon_driver_ctx;
#endif
} psa_driver_hash_context_t;

typedef union {
    unsigned dummy; /* Make sure this union is always non-empty */
#if defined(MBEDTLS_PSA_BUILTIN_HAS_CIPHER_SUPPORT)
    mbedtls_psa_cipher_operation_t mbedtls_ctx;
#endif
#if defined(PSA_CRYPTO_DRIVER_CC3XX)
    cc3xx_cipher_operation_t cc3xx_driver_ctx;
#endif /* PSA_CRYPTO_DRIVER_CC3XX */
#if defined(PSA_CRYPTO_DRIVER_HAS_CIPHER_SUPPORT_OBERON)
    oberon_cipher_operation_t oberon_driver_ctx;
#endif /* PSA_CRYPTO_DRIVER_CC3XX */

} psa_driver_cipher_context_t;

#endif /* PSA_CRYPTO_DRIVER_CONTEXTS_PRIMITIVES_H */
/* End of automatically generated file. */
