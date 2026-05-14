/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 *
 * Tier 2 alp-sdk-community driver for InvenSense MPU-6050 6-axis IMU (I2C; classic accel + gyro).
 * See include/mpu6050.h.
 */

#include <string.h>
#include <stdint.h>

#include "mpu6050.h"

#define MPU6050_REG_CHIP_ID     0x75u
#define MPU6050_CHIP_ID         0x68u
#define MPU6050_REG_SOFT_RESET  0x6Bu
#define MPU6050_SOFT_RESET_VAL  0x80u

alp_status_t mpu6050_init(mpu6050_t *dev, alp_i2c_t *bus, uint8_t i2c_addr)
{
    if (dev == NULL || bus == NULL) return ALP_ERR_INVAL;
    if (i2c_addr == 0) return ALP_ERR_INVAL;
    memset(dev, 0, sizeof(*dev));
    dev->bus  = bus;
    dev->addr = i2c_addr;

    uint8_t reg = MPU6050_REG_CHIP_ID;
    uint8_t id  = 0;
    alp_status_t s = alp_i2c_write_read(bus, i2c_addr, &reg, 1, &id, 1);
    if (s != ALP_OK) return s;
    if (id != MPU6050_CHIP_ID) return ALP_ERR_IO;

    dev->initialised = true;
    return ALP_OK;
}

alp_status_t mpu6050_soft_reset(mpu6050_t *dev)
{
    if (dev == NULL || !dev->initialised) return ALP_ERR_NOT_READY;
    uint8_t buf[2] = {MPU6050_REG_SOFT_RESET, MPU6050_SOFT_RESET_VAL};
    return alp_i2c_write(dev->bus, dev->addr, buf, sizeof(buf));
}

void mpu6050_deinit(mpu6050_t *dev)
{
    if (dev == NULL) return;
    dev->initialised = false;
    dev->bus         = NULL;
}
