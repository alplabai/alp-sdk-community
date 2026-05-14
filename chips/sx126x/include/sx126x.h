/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file sx126x.h
 * @brief Semtech SX126x LoRa / FSK transceiver family (host-side SPI probe stub)
 *
 * Tier 2 alp-sdk-community contribution.
 *
 * @par ABI status: [ABI-EXPERIMENTAL]
 * @par Verification status: [UNTESTED]
 *
 * Datasheet: Semtech SX126x v2.1 (May 2021).
 */

#ifndef SX126X_H
#define SX126X_H

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
} sx126x_t;

/** @brief Bind context to caller-opened SPI + optional reset GPIO. */
alp_status_t sx126x_init(sx126x_t *dev, alp_spi_t *spi, alp_gpio_t *nreset);

/** @brief Release driver context.  NULL is tolerated. */
void sx126x_deinit(sx126x_t *dev);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* SX126X_H */
