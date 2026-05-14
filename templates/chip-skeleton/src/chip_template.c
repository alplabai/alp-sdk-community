/*
 * Copyright 2026 @yourgh
 * SPDX-License-Identifier: Apache-2.0
 *
 * Tier 2 alp-sdk-community chip-skeleton template.  See the header
 * for the rename-and-fill-in workflow.
 */

#include <string.h>
#include <stdint.h>

#include "chip_template.h"

alp_status_t chip_template_init(chip_template_t *dev,
                                alp_i2c_t       *bus,
                                uint8_t          i2c_addr)
{
    if (dev == NULL || bus == NULL) return ALP_ERR_INVAL;
    if (i2c_addr == 0) return ALP_ERR_INVAL;
    memset(dev, 0, sizeof(*dev));
    dev->bus         = bus;
    dev->addr        = i2c_addr;
    dev->initialised = true;
    return ALP_OK;
}

void chip_template_deinit(chip_template_t *dev)
{
    if (dev == NULL) return;
    dev->initialised = false;
    dev->bus         = NULL;
}
