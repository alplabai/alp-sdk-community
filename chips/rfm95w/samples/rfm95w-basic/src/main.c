/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 *
 * Tier 2 alp-sdk-community minimum-viable example for rfm95w.
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "alp/peripheral.h"
#include "rfm95w.h"

int main(void)
{
    printk("rfm95w Tier 2 demo (init-only)\n");
    rfm95w_t dev;
    alp_status_t s = rfm95w_init(&dev, NULL, NULL);  /* NULL-arg path */
    printk("init returned %d (expected ALP_ERR_INVAL)\n", s);
    rfm95w_deinit(&dev);
    return 0;
}
