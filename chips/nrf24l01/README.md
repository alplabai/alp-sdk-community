# nrf24l01

Nordic nRF24L01+ 2.4 GHz radio transceiver (SPI; register R/W shell)

Vendor: nordic
MPNs: nRF24L01P-LPCQ
Datasheet: Nordic nRF24L01+ Preliminary v1.0 (Mar 2008).

## Public API

`#include "nrf24l01.h"`.  See `include/nrf24l01.h` for the full
Doxygen-annotated surface.

## Samples

- `samples/nrf24l01-basic/` -- minimum-viable usage example
  (builds on `native_sim/native/64`).

## Verification

`metadata.yaml` reports `verification: hil_silicon: untested`.
The driver compiles and passes its NULL-arg smoke; no HiL silicon
bring-up yet.

## Author

Initial port: @alpCaner (alp-sdk maintainer).  Per
[`alp-sdk/docs/contributing-tier-2.md`](https://github.com/alplabai/alp-sdk/blob/main/docs/contributing-tier-2.md#verified-promotion-path),
ownership transfers to community contributors over time.
