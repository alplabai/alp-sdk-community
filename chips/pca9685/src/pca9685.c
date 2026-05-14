/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 *
 * Tier 2 alp-sdk-community driver for NXP PCA9685 16-channel 12-bit PWM driver (I2C; servo-controller standard).
 * See include/pca9685.h.
 */

#include <string.h>
#include <stdint.h>

#include "pca9685.h"

#define PCA9685_REG_CHIP_ID     0xFEu
#define PCA9685_CHIP_ID         0x1Eu
#define PCA9685_REG_SOFT_RESET  0x00u
#define PCA9685_SOFT_RESET_VAL  0x80u

alp_status_t pca9685_init(pca9685_t *dev, alp_i2c_t *bus, uint8_t i2c_addr)
{
    if (dev == NULL || bus == NULL) return ALP_ERR_INVAL;
    if (i2c_addr == 0) return ALP_ERR_INVAL;
    memset(dev, 0, sizeof(*dev));
    dev->bus  = bus;
    dev->addr = i2c_addr;

    uint8_t reg = PCA9685_REG_CHIP_ID;
    uint8_t id  = 0;
    alp_status_t s = alp_i2c_write_read(bus, i2c_addr, &reg, 1, &id, 1);
    if (s != ALP_OK) return s;
    if (id != PCA9685_CHIP_ID) return ALP_ERR_IO;

    dev->initialised = true;
    return ALP_OK;
}

alp_status_t pca9685_soft_reset(pca9685_t *dev)
{
    if (dev == NULL || !dev->initialised) return ALP_ERR_NOT_READY;
    uint8_t buf[2] = {PCA9685_REG_SOFT_RESET, PCA9685_SOFT_RESET_VAL};
    return alp_i2c_write(dev->bus, dev->addr, buf, sizeof(buf));
}

void pca9685_deinit(pca9685_t *dev)
{
    if (dev == NULL) return;
    dev->initialised = false;
    dev->bus         = NULL;
}
