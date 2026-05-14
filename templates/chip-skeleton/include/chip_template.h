/*
 * Copyright 2026 @yourgh
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file chip_template.h
 * @brief Public API for the chip_template Tier 2 driver.
 *
 * Rename the file + every identifier below to match your chip's
 * natural prefix (e.g. `bme680_*`, not `alp_bme680_*`).  Tier 2
 * follows the same naming convention as Tier 1: `alp_` is reserved
 * for SDK abstractions only.
 *
 * @par ABI status: [ABI-EXPERIMENTAL]
 * @par Verification status: [UNTESTED] — bump to [VERIFIED] in a
 *   follow-up PR once HiL evidence lands under
 *   `samples/<sample>/hw_verification.md`.
 */

#ifndef CHIP_TEMPLATE_H
#define CHIP_TEMPLATE_H

#include <stdint.h>
#include <stdbool.h>

#include "alp/peripheral.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    alp_i2c_t *bus;
    uint8_t    addr;
    bool       initialised;
} chip_template_t;

/**
 * @brief Bind a driver context to an open I²C bus and verify chip ID.
 *
 * @param dev       Output: caller-allocated driver context.
 * @param bus       I²C bus handle from `alp_i2c_open`.
 * @param i2c_addr  7-bit I²C address.
 * @return `ALP_OK` on success.
 */
alp_status_t chip_template_init(chip_template_t *dev,
                                alp_i2c_t       *bus,
                                uint8_t          i2c_addr);

/** @brief Release the driver context.  NULL is tolerated. */
void chip_template_deinit(chip_template_t *dev);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CHIP_TEMPLATE_H */
