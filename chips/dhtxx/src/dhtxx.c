/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 *
 * Tier 2 alp-sdk-community driver for Aosong DHT11 / DHT22 temperature + humidity sensor (1-wire bit-banged).
 * See include/dhtxx.h.
 */

#include <string.h>
#include <stdint.h>

#include "dhtxx.h"

alp_status_t dhtxx_init(dhtxx_t *dev, alp_gpio_t *data_gpio)
{
    if (dev == NULL || data_gpio == NULL) return ALP_ERR_INVAL;
    memset(dev, 0, sizeof(*dev));
    dev->data        = data_gpio;
    dev->initialised = true;
    return ALP_OK;
}

void dhtxx_deinit(dhtxx_t *dev)
{
    if (dev == NULL) return;
    dev->initialised = false;
    dev->data        = NULL;
}
