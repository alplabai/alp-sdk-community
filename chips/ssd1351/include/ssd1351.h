/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file ssd1351.h
 * @brief Solomon Systech SSD1351 128x128 16-bit colour OLED controller (SPI)
 *
 * Tier 2 alp-sdk-community contribution.
 *
 * @par ABI status: [ABI-EXPERIMENTAL]
 * @par Verification status: [UNTESTED]
 *
 * Datasheet: Solomon Systech SSD1351 datasheet v1.4 (Aug 2014).
 */

#ifndef SSD1351_H
#define SSD1351_H

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
} ssd1351_t;

/** @brief Bind context to caller-opened SPI + optional reset GPIO. */
alp_status_t ssd1351_init(ssd1351_t *dev, alp_spi_t *spi, alp_gpio_t *nreset);

/** @brief Release driver context.  NULL is tolerated. */
void ssd1351_deinit(ssd1351_t *dev);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* SSD1351_H */
