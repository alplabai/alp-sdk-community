# bme680

Bosch BME680 air-quality + temp + pressure + humidity (I2C; chip-ID probe + soft reset)

Vendor: bosch
MPNs: BME680
Datasheet: Bosch BME680 datasheet v1.8 (Sep 2021).

## Public API

`#include "bme680.h"`.  See `include/bme680.h` for the full
Doxygen-annotated surface.

## Samples

- `samples/bme680-basic/` -- minimum-viable usage example
  (builds on `native_sim/native/64`).

## Verification

`metadata.yaml` reports `verification: hil_silicon: untested`.
The driver compiles and passes its NULL-arg smoke; no HiL silicon
bring-up yet.

## Author

Initial port: @alpCaner (alp-sdk maintainer).  Per
[`alp-sdk/docs/contributing-tier-2.md`](https://github.com/alplabai/alp-sdk/blob/main/docs/contributing-tier-2.md#verified-promotion-path),
ownership transfers to community contributors over time.
