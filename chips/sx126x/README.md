# sx126x

Semtech SX126x LoRa / FSK transceiver family (host-side SPI probe stub)

Vendor: semtech
MPNs: SX1261IMLTRT, SX1268IMLTRT
Datasheet: Semtech SX126x v2.1 (May 2021).

## Public API

`#include "sx126x.h"`.  See `include/sx126x.h` for the full
Doxygen-annotated surface.

## Samples

- `samples/sx126x-basic/` -- minimum-viable usage example
  (builds on `native_sim/native/64`).

## Verification

`metadata.yaml` reports `verification: hil_silicon: untested`.
The driver compiles and passes its NULL-arg smoke; no HiL silicon
bring-up yet.

## Author

Initial port: @alpCaner (alp-sdk maintainer).  Per
[`alp-sdk/docs/contributing-tier-2.md`](https://github.com/alplabai/alp-sdk/blob/main/docs/contributing-tier-2.md#verified-promotion-path),
ownership transfers to community contributors over time.
