/*
 * Copyright 2026 ALP Lab AB
 * SPDX-License-Identifier: Apache-2.0
 *
 * Tier 2 alp-sdk-community driver for Nordic nRF24L01+ 2.4 GHz radio transceiver (SPI; register R/W shell).
 * See include/nrf24l01.h.
 */

#include <string.h>
#include <stdint.h>

#include "nrf24l01.h"

alp_status_t nrf24l01_init(nrf24l01_t *dev, alp_spi_t *spi, alp_gpio_t *nreset)
{
    if (dev == NULL || spi == NULL) return ALP_ERR_INVAL;
    memset(dev, 0, sizeof(*dev));
    dev->bus         = spi;
    dev->nreset      = nreset;
    dev->initialised = true;
    return ALP_OK;
}

void nrf24l01_deinit(nrf24l01_t *dev)
{
    if (dev == NULL) return;
    dev->initialised = false;
    dev->bus         = NULL;
    dev->nreset      = NULL;
}
