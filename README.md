# alp-sdk-community

Community-contributed chip drivers + libraries for the
[alp-sdk](https://github.com/alplabai/alp-sdk).  This is Tier 2 of
the ecosystem.

## What's in here

```
alp-sdk-community/
├── README.md                # you are here
├── LICENSE                  # Apache-2.0 (umbrella)
├── registry.yaml            # INDEX of all contributions
├── west.yml                 # consumable as a project from alp-sdk's workspace
├── chips/<name>/            # community chip drivers
├── libraries/<name>/        # community libraries
├── templates/
│   ├── chip-skeleton/       # `cp -r templates/chip-skeleton chips/foo`
│   └── library-skeleton/
└── .github/
    ├── workflows/
    │   ├── pr-build-contribution.yml
    │   ├── pr-metadata-validate.yml
    │   └── pr-lint.yml
    └── CODEOWNERS
```

## How to contribute

Full walk-through in
[`alp-sdk/docs/contributing-tier-2.md`](https://github.com/alplabai/alp-sdk/blob/main/docs/contributing-tier-2.md).
TL;DR:

1. `gh repo fork alplabai/alp-sdk-community` to your own fork.
2. `cp -r templates/chip-skeleton chips/<your-chip>` (or
   `templates/library-skeleton libraries/<your-lib>`).
3. Fill in `metadata.yaml`, write your driver, at least one sample.
4. Add an entry to `registry.yaml` that matches your metadata.yaml.
5. Open a PR.  CI runs `pr-metadata-validate` + `pr-build-contribution`
   + `pr-lint`; reviewer is auto-assigned from CODEOWNERS.

## Quality bar

Tier 2 quality bar is intentionally lower than Tier 1:

- Permissive licences only (Apache-2.0 / MIT / BSD-2-Clause /
  BSD-3-Clause).  GPL is rejected at CI time.
- `pr-build-contribution` runs `west build -b native_sim/native/64`
  on the touched contribution's first sample -- it has to compile;
  warnings are tolerated.
- `pr-metadata-validate` runs the contribution's `metadata.yaml`
  against
  [`alp-sdk/metadata/schemas/contribution-v1.schema.json`](https://github.com/alplabai/alp-sdk/blob/main/metadata/schemas/contribution-v1.schema.json).
- `pr-lint` runs `clang-format-diff` (warnings, not errors) +
  Apache/MIT/BSD license-header check + registry.yaml
  consistency check.

Contributions ship with a `verification: hil_silicon: untested`
badge unless the author demonstrates real-silicon bring-up under
`samples/<sample>/hw_verification.md`.

## Customer integration

See [`alp-sdk/docs/contributing-tier-2.md`](https://github.com/alplabai/alp-sdk/blob/main/docs/contributing-tier-2.md#customer-integration-patterns)
for the three patterns: pull-everything / per-contribution / search-
then-clone.

## License

Each contribution is licensed under its own choice of
Apache-2.0 / MIT / BSD.  The umbrella `LICENSE` file in this repo
covers the infrastructure (CI workflows, templates, registry.yaml)
under Apache-2.0.

## Code of conduct + governance

Bug reports + features: file an issue.

For broader governance questions, contact the maintainers
([alplabai/*](https://github.com/orgs/alplabai/people)).
