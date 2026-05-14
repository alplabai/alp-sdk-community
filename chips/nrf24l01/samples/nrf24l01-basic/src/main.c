/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 *
 * Tier 2 alp-sdk-community minimum-viable example for nrf24l01.
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "alp/peripheral.h"
#include "nrf24l01.h"

int main(void)
{
    printk("nrf24l01 Tier 2 demo (init-only)\n");
    nrf24l01_t dev;
    alp_status_t s = nrf24l01_init(&dev, NULL, NULL);  /* NULL-arg path */
    printk("init returned %d (expected ALP_ERR_INVAL)\n", s);
    nrf24l01_deinit(&dev);
    return 0;
}
