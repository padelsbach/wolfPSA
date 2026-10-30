/* x509_crt.h
 *
 * Copyright (C) 2026 wolfSSL Inc.
 *
 * This file is part of wolfPSA.
 *
 * wolfPSA is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * wolfPSA is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335, USA
 */

#ifndef MBEDTLS_X509_CRT_H
#define MBEDTLS_X509_CRT_H

#include "mbedtls/x509.h"

#include <stddef.h>

#ifdef __cplusplus
    extern "C" {
#endif /* __cplusplus */

/* Each node contains one certificate, DER */
typedef struct mbedtls_x509_crt {
    mbedtls_x509_buf raw;
    struct mbedtls_x509_crt* next;
} mbedtls_x509_crt;

typedef struct mbedtls_x509_crl mbedtls_x509_crl;

void wolfSSL_mbedtls_x509_crt_init(mbedtls_x509_crt* crt);
void wolfSSL_mbedtls_x509_crt_free(mbedtls_x509_crt* crt);
int wolfSSL_mbedtls_x509_crt_parse(mbedtls_x509_crt* chain,
    const unsigned char* buf, size_t buflen);
int wolfSSL_mbedtls_x509_crt_parse_der(mbedtls_x509_crt* chain,
    const unsigned char* buf, size_t buflen);
int wolfSSL_mbedtls_x509_crt_parse_file(mbedtls_x509_crt* chain,
    const char* path);

/* Exported as wolfSSL_ names, as the OpenSSL compatibility layer does */
#define mbedtls_x509_crt_init        wolfSSL_mbedtls_x509_crt_init
#define mbedtls_x509_crt_free        wolfSSL_mbedtls_x509_crt_free
#define mbedtls_x509_crt_parse       wolfSSL_mbedtls_x509_crt_parse
#define mbedtls_x509_crt_parse_der   wolfSSL_mbedtls_x509_crt_parse_der
#define mbedtls_x509_crt_parse_file  wolfSSL_mbedtls_x509_crt_parse_file

#ifdef __cplusplus
    } /* extern "C" */
#endif /* __cplusplus */

#endif /* MBEDTLS_X509_CRT_H */
