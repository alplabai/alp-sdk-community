/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 *
 * Tier 2 alp-sdk-community driver for Solomon Systech SSD1351 128x128 16-bit colour OLED controller (SPI).
 * See include/ssd1351.h.
 */

#include <string.h>
#include <stdint.h>

#include "ssd1351.h"

alp_status_t ssd1351_init(ssd1351_t *dev, alp_spi_t *spi, alp_gpio_t *nreset)
{
    if (dev == NULL || spi == NULL) return ALP_ERR_INVAL;
    memset(dev, 0, sizeof(*dev));
    dev->bus         = spi;
    dev->nreset      = nreset;
    dev->initialised = true;
    return ALP_OK;
}

void ssd1351_deinit(ssd1351_t *dev)
{
    if (dev == NULL) return;
    dev->initialised = false;
    dev->bus         = NULL;
    dev->nreset      = NULL;
}
