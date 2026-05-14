/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file dhtxx.h
 * @brief Aosong DHT11 / DHT22 temperature + humidity sensor (1-wire bit-banged)
 *
 * Tier 2 alp-sdk-community contribution.  Bit-banged GPIO protocol;
 * timing-sensitive lifecycle.
 *
 * @par ABI status: [ABI-EXPERIMENTAL]
 * @par Verification status: [UNTESTED]
 *
 * Datasheet: Aosong DHT11 / DHT22 datasheets.
 */

#ifndef DHTXX_H
#define DHTXX_H

#include <stdint.h>
#include <stdbool.h>

#include "alp/peripheral.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    alp_gpio_t *data;
    bool        initialised;
} dhtxx_t;

/** @brief Bind context to caller-opened data GPIO. */
alp_status_t dhtxx_init(dhtxx_t *dev, alp_gpio_t *data_gpio);

/** @brief Release driver context.  NULL is tolerated. */
void dhtxx_deinit(dhtxx_t *dev);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* DHTXX_H */
