# ssd1351

Solomon Systech SSD1351 128x128 16-bit colour OLED controller (SPI)

Vendor: solomon_systech
MPNs: SSD1351
Datasheet: Solomon Systech SSD1351 datasheet v1.4 (Aug 2014).

## Public API

`#include "ssd1351.h"`.  See `include/ssd1351.h` for the full
Doxygen-annotated surface.

## Samples

- `samples/ssd1351-basic/` -- minimum-viable usage example
  (builds on `native_sim/native/64`).

## Verification

`metadata.yaml` reports `verification: hil_silicon: untested`.
The driver compiles and passes its NULL-arg smoke; no HiL silicon
bring-up yet.

## Author

Initial port: @alpCaner (alp-sdk maintainer).  Per
[`alp-sdk/docs/contributing-tier-2.md`](https://github.com/alplabai/alp-sdk/blob/main/docs/contributing-tier-2.md#verified-promotion-path),
ownership transfers to community contributors over time.
