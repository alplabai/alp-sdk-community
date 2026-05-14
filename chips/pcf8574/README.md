# pcf8574

NXP PCF8574 8-bit I2C GPIO expander (8 quasi-bidir pins)

Vendor: nxp
MPNs: PCF8574T
Datasheet: NXP PCF8574 datasheet v8 (Mar 2013).

## Public API

`#include "pcf8574.h"`.  See `include/pcf8574.h` for the full
Doxygen-annotated surface.

## Samples

- `samples/pcf8574-basic/` -- minimum-viable usage example
  (builds on `native_sim/native/64`).

## Verification

`metadata.yaml` reports `verification: hil_silicon: untested`.
The driver compiles and passes its NULL-arg smoke; no HiL silicon
bring-up yet.

## Author

Initial port: @alpCaner (alp-sdk maintainer).  Per
[`alp-sdk/docs/contributing-tier-2.md`](https://github.com/alplabai/alp-sdk/blob/main/docs/contributing-tier-2.md#verified-promotion-path),
ownership transfers to community contributors over time.
