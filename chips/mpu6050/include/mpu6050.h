/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file mpu6050.h
 * @brief InvenSense MPU-6050 6-axis IMU (I2C; classic accel + gyro)
 *
 * Tier 2 alp-sdk-community contribution.  See
 * alp-sdk/docs/contributing-tier-2.md for the per-contribution
 * workflow.
 *
 * @par ABI status: [ABI-EXPERIMENTAL]
 * @par Verification status: [UNTESTED] — driver compiles + passes
 *   NULL-arg smokes; no HiL silicon bring-up yet.
 *
 * Datasheet: InvenSense MPU-6050 datasheet v3.4 (Aug 2013).
 */

#ifndef MPU6050_H
#define MPU6050_H

#include <stdint.h>
#include <stdbool.h>

#include "alp/peripheral.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MPU6050_I2C_ADDR_DEFAULT 0x68u
#define MPU6050_I2C_ADDR_ALT     0x69u

typedef struct {
    alp_i2c_t *bus;
    uint8_t    addr;
    bool       initialised;
} mpu6050_t;

/** @brief Bind context to an open I²C bus.  Verifies CHIP_ID register matches the expected silicon ID. */
alp_status_t mpu6050_init(mpu6050_t *dev, alp_i2c_t *bus, uint8_t i2c_addr);

/** @brief Issue a software reset. */
alp_status_t mpu6050_soft_reset(mpu6050_t *dev);

/** @brief Release driver context.  NULL is tolerated. */
void mpu6050_deinit(mpu6050_t *dev);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MPU6050_H */
