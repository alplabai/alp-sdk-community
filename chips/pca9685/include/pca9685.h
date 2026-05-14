/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file pca9685.h
 * @brief NXP PCA9685 16-channel 12-bit PWM driver (I2C; servo-controller standard)
 *
 * Tier 2 alp-sdk-community contribution.  See
 * alp-sdk/docs/contributing-tier-2.md for the per-contribution
 * workflow.
 *
 * @par ABI status: [ABI-EXPERIMENTAL]
 * @par Verification status: [UNTESTED] — driver compiles + passes
 *   NULL-arg smokes; no HiL silicon bring-up yet.
 *
 * Datasheet: NXP PCA9685 datasheet v4.0 (Apr 2015).
 */

#ifndef PCA9685_H
#define PCA9685_H

#include <stdint.h>
#include <stdbool.h>

#include "alp/peripheral.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PCA9685_I2C_ADDR_DEFAULT 0x40u
#define PCA9685_I2C_ADDR_ALT     0x70u

typedef struct {
    alp_i2c_t *bus;
    uint8_t    addr;
    bool       initialised;
} pca9685_t;

/** @brief Bind context to an open I²C bus.  Verifies CHIP_ID register matches the expected silicon ID. */
alp_status_t pca9685_init(pca9685_t *dev, alp_i2c_t *bus, uint8_t i2c_addr);

/** @brief Issue a software reset. */
alp_status_t pca9685_soft_reset(pca9685_t *dev);

/** @brief Release driver context.  NULL is tolerated. */
void pca9685_deinit(pca9685_t *dev);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* PCA9685_H */
