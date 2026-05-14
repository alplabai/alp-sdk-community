/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 *
 * Tier 2 alp-sdk-community minimum-viable example for sx126x.
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "alp/peripheral.h"
#include "sx126x.h"

int main(void)
{
    printk("sx126x Tier 2 demo (init-only)\n");
    sx126x_t dev;
    alp_status_t s = sx126x_init(&dev, NULL, NULL);  /* NULL-arg path */
    printk("init returned %d (expected ALP_ERR_INVAL)\n", s);
    sx126x_deinit(&dev);
    return 0;
}
