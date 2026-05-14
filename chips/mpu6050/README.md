# mpu6050

InvenSense MPU-6050 6-axis IMU (I2C; classic accel + gyro)

Vendor: invensense
MPNs: MPU-6050
Datasheet: InvenSense MPU-6050 datasheet v3.4 (Aug 2013).

## Public API

`#include "mpu6050.h"`.  See `include/mpu6050.h` for the full
Doxygen-annotated surface.

## Samples

- `samples/mpu6050-basic/` -- minimum-viable usage example
  (builds on `native_sim/native/64`).

## Verification

`metadata.yaml` reports `verification: hil_silicon: untested`.
The driver compiles and passes its NULL-arg smoke; no HiL silicon
bring-up yet.

## Author

Initial port: @alpCaner (alp-sdk maintainer).  Per
[`alp-sdk/docs/contributing-tier-2.md`](https://github.com/alplabai/alp-sdk/blob/main/docs/contributing-tier-2.md#verified-promotion-path),
ownership transfers to community contributors over time.
