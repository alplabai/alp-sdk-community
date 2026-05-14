/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 *
 * Tier 2 alp-sdk-community minimum-viable example for ssd1351.
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "alp/peripheral.h"
#include "ssd1351.h"

int main(void)
{
    printk("ssd1351 Tier 2 demo (init-only)\n");
    ssd1351_t dev;
    alp_status_t s = ssd1351_init(&dev, NULL, NULL);  /* NULL-arg path */
    printk("init returned %d (expected ALP_ERR_INVAL)\n", s);
    ssd1351_deinit(&dev);
    return 0;
}
