/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file ds18b20.h
 * @brief Maxim DS18B20 1-Wire programmable-resolution digital thermometer
 *
 * Tier 2 alp-sdk-community contribution.  Bit-banged GPIO protocol;
 * timing-sensitive lifecycle.
 *
 * @par ABI status: [ABI-EXPERIMENTAL]
 * @par Verification status: [UNTESTED]
 *
 * Datasheet: Maxim DS18B20 datasheet Rev 4 (Dec 2008).
 */

#ifndef DS18B20_H
#define DS18B20_H

#include <stdint.h>
#include <stdbool.h>

#include "alp/peripheral.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    alp_gpio_t *data;
    bool        initialised;
} ds18b20_t;

/** @brief Bind context to caller-opened data GPIO. */
alp_status_t ds18b20_init(ds18b20_t *dev, alp_gpio_t *data_gpio);

/** @brief Release driver context.  NULL is tolerated. */
void ds18b20_deinit(ds18b20_t *dev);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* DS18B20_H */
