/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file pcf8574.h
 * @brief NXP PCF8574 8-bit I2C GPIO expander (8 quasi-bidir pins)
 *
 * Tier 2 alp-sdk-community contribution.  See
 * alp-sdk/docs/contributing-tier-2.md for the per-contribution
 * workflow.
 *
 * @par ABI status: [ABI-EXPERIMENTAL]
 * @par Verification status: [UNTESTED] — driver compiles + passes
 *   NULL-arg smokes; no HiL silicon bring-up yet.
 *
 * Datasheet: NXP PCF8574 datasheet v8 (Mar 2013).
 */

#ifndef PCF8574_H
#define PCF8574_H

#include <stdint.h>
#include <stdbool.h>

#include "alp/peripheral.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PCF8574_I2C_ADDR_DEFAULT 0x20u
#define PCF8574_I2C_ADDR_ALT     0x27u

typedef struct {
    alp_i2c_t *bus;
    uint8_t    addr;
    bool       initialised;
} pcf8574_t;

/** @brief Bind context to an open I²C bus. */
alp_status_t pcf8574_init(pcf8574_t *dev, alp_i2c_t *bus, uint8_t i2c_addr);

/** @brief Issue a software reset. */
alp_status_t pcf8574_soft_reset(pcf8574_t *dev);

/** @brief Release driver context.  NULL is tolerated. */
void pcf8574_deinit(pcf8574_t *dev);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* PCF8574_H */
