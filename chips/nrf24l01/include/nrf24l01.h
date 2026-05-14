/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file nrf24l01.h
 * @brief Nordic nRF24L01+ 2.4 GHz radio transceiver (SPI; register R/W shell)
 *
 * Tier 2 alp-sdk-community contribution.
 *
 * @par ABI status: [ABI-EXPERIMENTAL]
 * @par Verification status: [UNTESTED]
 *
 * Datasheet: Nordic nRF24L01+ Preliminary v1.0 (Mar 2008).
 */

#ifndef NRF24L01_H
#define NRF24L01_H

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
} nrf24l01_t;

/** @brief Bind context to caller-opened SPI + optional reset GPIO. */
alp_status_t nrf24l01_init(nrf24l01_t *dev, alp_spi_t *spi, alp_gpio_t *nreset);

/** @brief Release driver context.  NULL is tolerated. */
void nrf24l01_deinit(nrf24l01_t *dev);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* NRF24L01_H */
