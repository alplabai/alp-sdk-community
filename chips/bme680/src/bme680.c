/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 *
 * Tier 2 alp-sdk-community driver for Bosch BME680 air-quality + temp + pressure + humidity (I2C; chip-ID probe + soft reset).
 * See include/bme680.h.
 */

#include <string.h>
#include <stdint.h>

#include "bme680.h"

#define BME680_REG_CHIP_ID     0xD0u
#define BME680_CHIP_ID         0x61u
#define BME680_REG_SOFT_RESET  0xE0u
#define BME680_SOFT_RESET_VAL  0xB6u

alp_status_t bme680_init(bme680_t *dev, alp_i2c_t *bus, uint8_t i2c_addr)
{
    if (dev == NULL || bus == NULL) return ALP_ERR_INVAL;
    if (i2c_addr == 0) return ALP_ERR_INVAL;
    memset(dev, 0, sizeof(*dev));
    dev->bus  = bus;
    dev->addr = i2c_addr;

    uint8_t reg = BME680_REG_CHIP_ID;
    uint8_t id  = 0;
    alp_status_t s = alp_i2c_write_read(bus, i2c_addr, &reg, 1, &id, 1);
    if (s != ALP_OK) return s;
    if (id != BME680_CHIP_ID) return ALP_ERR_IO;

    dev->initialised = true;
    return ALP_OK;
}

alp_status_t bme680_soft_reset(bme680_t *dev)
{
    if (dev == NULL || !dev->initialised) return ALP_ERR_NOT_READY;
    uint8_t buf[2] = {BME680_REG_SOFT_RESET, BME680_SOFT_RESET_VAL};
    return alp_i2c_write(dev->bus, dev->addr, buf, sizeof(buf));
}

void bme680_deinit(bme680_t *dev)
{
    if (dev == NULL) return;
    dev->initialised = false;
    dev->bus         = NULL;
}
