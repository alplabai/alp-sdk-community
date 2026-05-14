/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 *
 * Tier 2 alp-sdk-community driver for NXP PCF8574 8-bit I2C GPIO expander (8 quasi-bidir pins).
 * See include/pcf8574.h.
 */

#include <string.h>
#include <stdint.h>

#include "pcf8574.h"

#define PCF8574_REG_CHIP_ID     0x00u
#define PCF8574_CHIP_ID         0xFFu
#define PCF8574_REG_SOFT_RESET  0x00u
#define PCF8574_SOFT_RESET_VAL  0xFFu

alp_status_t pcf8574_init(pcf8574_t *dev, alp_i2c_t *bus, uint8_t i2c_addr)
{
    if (dev == NULL || bus == NULL) return ALP_ERR_INVAL;
    if (i2c_addr == 0) return ALP_ERR_INVAL;
    memset(dev, 0, sizeof(*dev));
    dev->bus  = bus;
    dev->addr = i2c_addr;

    /* Chip has no ID register; rely on bus-level ACK for liveness. */
    dev->initialised = true;
    return ALP_OK;
}

alp_status_t pcf8574_soft_reset(pcf8574_t *dev)
{
    if (dev == NULL || !dev->initialised) return ALP_ERR_NOT_READY;
    uint8_t buf[2] = {PCF8574_REG_SOFT_RESET, PCF8574_SOFT_RESET_VAL};
    return alp_i2c_write(dev->bus, dev->addr, buf, sizeof(buf));
}

void pcf8574_deinit(pcf8574_t *dev)
{
    if (dev == NULL) return;
    dev->initialised = false;
    dev->bus         = NULL;
}
