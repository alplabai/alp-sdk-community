/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file bme680.h
 * @brief Bosch BME680 air-quality + temp + pressure + humidity (I2C; chip-ID probe + soft reset)
 *
 * Tier 2 alp-sdk-community contribution.  See
 * alp-sdk/docs/contributing-tier-2.md for the per-contribution
 * workflow.
 *
 * @par ABI status: [ABI-EXPERIMENTAL]
 * @par Verification status: [UNTESTED] — driver compiles + passes
 *   NULL-arg smokes; no HiL silicon bring-up yet.
 *
 * Datasheet: Bosch BME680 datasheet v1.8 (Sep 2021).
 */

#ifndef BME680_H
#define BME680_H

#include <stdint.h>
#include <stdbool.h>

#include "alp/peripheral.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BME680_I2C_ADDR_DEFAULT 0x76u
#define BME680_I2C_ADDR_ALT     0x77u

typedef struct {
    alp_i2c_t *bus;
    uint8_t    addr;
    bool       initialised;
} bme680_t;

/** @brief Bind context to an open I²C bus.  Verifies CHIP_ID register matches the expected silicon ID. */
alp_status_t bme680_init(bme680_t *dev, alp_i2c_t *bus, uint8_t i2c_addr);

/** @brief Issue a software reset. */
alp_status_t bme680_soft_reset(bme680_t *dev);

/** @brief Release driver context.  NULL is tolerated. */
void bme680_deinit(bme680_t *dev);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* BME680_H */
