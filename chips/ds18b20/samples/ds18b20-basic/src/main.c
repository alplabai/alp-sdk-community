/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 *
 * Tier 2 alp-sdk-community minimum-viable example for ds18b20.
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "alp/peripheral.h"
#include "ds18b20.h"

int main(void)
{
    printk("ds18b20 Tier 2 demo (init-only)\n");
    ds18b20_t dev;
    alp_status_t s = ds18b20_init(&dev, NULL);
    printk("init returned %d (expected ALP_ERR_INVAL)\n", s);
    ds18b20_deinit(&dev);
    return 0;
}
