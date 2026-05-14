# chip_template

One-paragraph description of your chip: vendor, MPN, what it does,
what bus it drives.  Cite the datasheet.

## Public API

`#include "chip_template.h"`.  See `include/chip_template.h` for the
full Doxygen-annotated surface.

## Samples

- `samples/chip-template-basic/` -- minimum-viable usage example.

## Verification

`metadata.yaml` reports `verification: hil_silicon: untested`.
The driver compiles on native_sim and passes the NULL-arg-guard
smoke test in `samples/chip-template-basic/`.  Bump to `verified`
in your follow-up PR once you can attach HiL evidence under
`samples/chip-template-basic/hw_verification.md`.

## Author

@yourgh
