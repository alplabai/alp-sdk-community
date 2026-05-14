# ds18b20

Maxim DS18B20 1-Wire programmable-resolution digital thermometer

Vendor: adi_maxim
MPNs: DS18B20
Datasheet: Maxim DS18B20 datasheet Rev 4 (Dec 2008).

## Public API

`#include "ds18b20.h"`.  See `include/ds18b20.h` for the full
Doxygen-annotated surface.

## Samples

- `samples/ds18b20-basic/` -- minimum-viable usage example
  (builds on `native_sim/native/64`).

## Verification

`metadata.yaml` reports `verification: hil_silicon: untested`.
The driver compiles and passes its NULL-arg smoke; no HiL silicon
bring-up yet.

## Author

Initial port: @alpCaner (alp-sdk maintainer).  Per
[`alp-sdk/docs/contributing-tier-2.md`](https://github.com/alplabai/alp-sdk/blob/main/docs/contributing-tier-2.md#verified-promotion-path),
ownership transfers to community contributors over time.
