/*
 * Copyright 2026 @yourgh
 * SPDX-License-Identifier: Apache-2.0
 *
 * Minimum-viable example for the chip_template Tier 2 driver.
 * Builds on native_sim/native/64 via:
 *
 *   west -C ../alp-sdk build -b native_sim/native/64 \
 *        ../alp-sdk-community/chips/chip_template/samples/chip-template-basic
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "alp/peripheral.h"
#include "alp/e1m_pinout.h"
#include "chip_template.h"

int main(void)
{
    printk("chip_template Tier 2 demo\n");

    alp_i2c_t *bus = alp_i2c_open(&(alp_i2c_config_t){
        .bus_id     = E1M_I2C0,
        .bitrate_hz = 400000,
    });
    if (bus == NULL) {
        printk("FAIL: alp_i2c_open returned NULL\n");
        return 1;
    }

    chip_template_t dev;
    alp_status_t    s = chip_template_init(&dev, bus, 0x48);
    if (s != ALP_OK) {
        printk("INFO: chip_template_init returned %d (expected on emul bus)\n", s);
    }
    chip_template_deinit(&dev);
    alp_i2c_close(bus);
    return 0;
}
