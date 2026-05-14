# dhtxx

Aosong DHT11 / DHT22 temperature + humidity sensor (1-wire bit-banged)

Vendor: aosong
MPNs: DHT11, DHT22 / AM2302
Datasheet: Aosong DHT11 / DHT22 datasheets.

## Public API

`#include "dhtxx.h"`.  See `include/dhtxx.h` for the full
Doxygen-annotated surface.

## Samples

- `samples/dhtxx-basic/` -- minimum-viable usage example
  (builds on `native_sim/native/64`).

## Verification

`metadata.yaml` reports `verification: hil_silicon: untested`.
The driver compiles and passes its NULL-arg smoke; no HiL silicon
bring-up yet.

## Author

Initial port: @alpCaner (alp-sdk maintainer).  Per
[`alp-sdk/docs/contributing-tier-2.md`](https://github.com/alplabai/alp-sdk/blob/main/docs/contributing-tier-2.md#verified-promotion-path),
ownership transfers to community contributors over time.
