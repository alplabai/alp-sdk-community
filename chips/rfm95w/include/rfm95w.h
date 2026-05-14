/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file rfm95w.h
 * @brief HopeRF RFM95W LoRa transceiver module (SX1276 in a HopeRF can)
 *
 * Tier 2 alp-sdk-community contribution.
 *
 * @par ABI status: [ABI-EXPERIMENTAL]
 * @par Verification status: [UNTESTED]
 *
 * Datasheet: HopeRF RFM95W datasheet v2.0 (Mar 2017).
 */

#ifndef RFM95W_H
#define RFM95W_H

#include <stdint.h>
#include <stdbool.h>

#include "alp/peripheral.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    alp_spi_t  *bus;
    alp_gpio_t *nreset;
    bool        initialised;
} rfm95w_t;

/** @brief Bind context to caller-opened SPI + optional reset GPIO. */
alp_status_t rfm95w_init(rfm95w_t *dev, alp_spi_t *spi, alp_gpio_t *nreset);

/** @brief Release driver context.  NULL is tolerated. */
void rfm95w_deinit(rfm95w_t *dev);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* RFM95W_H */
