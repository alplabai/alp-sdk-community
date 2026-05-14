# pca9685

NXP PCA9685 16-channel 12-bit PWM driver (I2C; servo-controller standard)

Vendor: nxp
MPNs: PCA9685PW
Datasheet: NXP PCA9685 datasheet v4.0 (Apr 2015).

## Public API

`#include "pca9685.h"`.  See `include/pca9685.h` for the full
Doxygen-annotated surface.

## Samples

- `samples/pca9685-basic/` -- minimum-viable usage example
  (builds on `native_sim/native/64`).

## Verification

`metadata.yaml` reports `verification: hil_silicon: untested`.
The driver compiles and passes its NULL-arg smoke; no HiL silicon
bring-up yet.

## Author

Initial port: @alpCaner (alp-sdk maintainer).  Per
[`alp-sdk/docs/contributing-tier-2.md`](https://github.com/alplabai/alp-sdk/blob/main/docs/contributing-tier-2.md#verified-promotion-path),
ownership transfers to community contributors over time.
