/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 *
 * Tier 2 alp-sdk-community driver for Maxim DS18B20 1-Wire programmable-resolution digital thermometer.
 * See include/ds18b20.h.
 */

#include <string.h>
#include <stdint.h>

#include "ds18b20.h"

alp_status_t ds18b20_init(ds18b20_t *dev, alp_gpio_t *data_gpio)
{
    if (dev == NULL || data_gpio == NULL) return ALP_ERR_INVAL;
    memset(dev, 0, sizeof(*dev));
    dev->data        = data_gpio;
    dev->initialised = true;
    return ALP_OK;
}

void ds18b20_deinit(ds18b20_t *dev)
{
    if (dev == NULL) return;
    dev->initialised = false;
    dev->data        = NULL;
}
