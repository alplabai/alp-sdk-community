/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 *
 * Tier 2 alp-sdk-community driver for HopeRF RFM95W LoRa transceiver module (SX1276 in a HopeRF can).
 * See include/rfm95w.h.
 */

#include <string.h>
#include <stdint.h>

#include "rfm95w.h"

alp_status_t rfm95w_init(rfm95w_t *dev, alp_spi_t *spi, alp_gpio_t *nreset)
{
    if (dev == NULL || spi == NULL) return ALP_ERR_INVAL;
    memset(dev, 0, sizeof(*dev));
    dev->bus         = spi;
    dev->nreset      = nreset;
    dev->initialised = true;
    return ALP_OK;
}

void rfm95w_deinit(rfm95w_t *dev)
{
    if (dev == NULL) return;
    dev->initialised = false;
    dev->bus         = NULL;
    dev->nreset      = NULL;
}
