# rfm95w

HopeRF RFM95W LoRa transceiver module (SX1276 in a HopeRF can)

Vendor: hoperf
MPNs: RFM95W-868S2, RFM95W-915S2
Datasheet: HopeRF RFM95W datasheet v2.0 (Mar 2017).

## Public API

`#include "rfm95w.h"`.  See `include/rfm95w.h` for the full
Doxygen-annotated surface.

## Samples

- `samples/rfm95w-basic/` -- minimum-viable usage example
  (builds on `native_sim/native/64`).

## Verification

`metadata.yaml` reports `verification: hil_silicon: untested`.
The driver compiles and passes its NULL-arg smoke; no HiL silicon
bring-up yet.

## Author

Initial port: @alpCaner (alp-sdk maintainer).  Per
[`alp-sdk/docs/contributing-tier-2.md`](https://github.com/alplabai/alp-sdk/blob/main/docs/contributing-tier-2.md#verified-promotion-path),
ownership transfers to community contributors over time.
