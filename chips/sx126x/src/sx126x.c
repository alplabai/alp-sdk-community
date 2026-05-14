/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 *
 * Tier 2 alp-sdk-community driver for Semtech SX126x LoRa / FSK transceiver family (host-side SPI probe stub).
 * See include/sx126x.h.
 */

#include <string.h>
#include <stdint.h>

#include "sx126x.h"

alp_status_t sx126x_init(sx126x_t *dev, alp_spi_t *spi, alp_gpio_t *nreset)
{
    if (dev == NULL || spi == NULL) return ALP_ERR_INVAL;
    memset(dev, 0, sizeof(*dev));
    dev->bus         = spi;
    dev->nreset      = nreset;
    dev->initialised = true;
    return ALP_OK;
}

void sx126x_deinit(sx126x_t *dev)
{
    if (dev == NULL) return;
    dev->initialised = false;
    dev->bus         = NULL;
    dev->nreset      = NULL;
}
