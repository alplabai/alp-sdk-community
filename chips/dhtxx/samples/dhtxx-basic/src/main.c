/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 *
 * Tier 2 alp-sdk-community minimum-viable example for dhtxx.
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "alp/peripheral.h"
#include "dhtxx.h"

int main(void)
{
    printk("dhtxx Tier 2 demo (init-only)\n");
    dhtxx_t dev;
    alp_status_t s = dhtxx_init(&dev, NULL);
    printk("init returned %d (expected ALP_ERR_INVAL)\n", s);
    dhtxx_deinit(&dev);
    return 0;
}
