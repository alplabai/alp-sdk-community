/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 *
 * Tier 2 alp-sdk-community minimum-viable example for pca9685.
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "alp/peripheral.h"
#include "alp/e1m_pinout.h"
#include "pca9685.h"

int main(void)
{
    printk("pca9685 Tier 2 demo\n");
    alp_i2c_t *bus = alp_i2c_open(&(alp_i2c_config_t){
        .bus_id     = E1M_I2C0,
        .bitrate_hz = 400000,
    });
    if (bus == NULL) {
        printk("FAIL: alp_i2c_open returned NULL\n");
        return 1;
    }
    pca9685_t dev;
    alp_status_t s = pca9685_init(&dev, bus, PCA9685_I2C_ADDR_DEFAULT);
    printk("init returned %d\n", s);
    pca9685_deinit(&dev);
    alp_i2c_close(bus);
    return 0;
}
