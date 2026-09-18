# Feature-parity test harness (issue #42)

A plain userspace Tiger program that drives the real ATIRadeonX1000
accelerator's external methods via IOKit exactly the way a real client
(the GL/2D/VA userspace bundles) does, so results can be recorded and
compared between the currently-installed stock driver and this project's
own rebuilt kext.

This is **not** a kext and needs none of the `-fapple-kext`/kernel-header
build machinery the driver itself does - it's a normal Mac OS X
application, built with the stock system `gcc` and linked against
`IOKit.framework`/`CoreFoundation.framework`.

## Status

**Full coverage reached** (2026-09-18): all 81 external methods across
all 4 context classes are represented in `test_gl_context.c`/
`test_2d_context.c`/`test_dvd_context.c`/`test_surface_context.c`, each
with a real-shape citation or an explicit unverified flag. See the
safety section below for why most of them are intentionally not
executed live.

The methodology changed significantly partway through this work - the
original plan (trust this project's own `VendorExternalMethod` kernel-
table dump for argument counts) turned out not to work: every GL call
built from that table's assumed count semantics came back
`kIOReturnBadArgument` against the live stock driver, across every
combination tried. The real, reliable source of truth turned out to be
**call-site cross-referencing** - disassembling the real vendor
userspace bundles (`ATIRadeonX1000GLDriver.bundle`,
`ATIRadeonX1000GA.plugin`, `ATIRadeonX1000VADriver.bundle`) and reading
the literal register values passed to the raw `io_connect_method_*` MIG
stubs they call directly. This recovered real, call-site-CONFIRMED
shapes for all 21 GL selectors, and roughly half of the 2D/DVD
selectors; the rest fall back to the class headers' own declared C++
signatures, explicitly flagged as unverified. See each test file's own
per-method comments for the citation (binary + address) or the
unverified flag.

## SAFETY - read before extending this harness

A broad, automated sweep of many call shapes against the live driver
(this project's own earlier `Tests/diag_shape_scan.c`, deliberately not
committed) **triggered a real kernel panic in Apple's stock driver**,
root-caused via static Ghidra analysis to `ATIR500Surface::
submit_swap_buffer` - a real internal GPU command-submission path that
does unguarded pointer-chasing assuming a properly-locked/allocated
surface. The G5 hard-hung and needed a physical restart (it recovered
cleanly - issue #41's recovery plan, now validated for real). Full
writeup: issue #43's comment thread.

**Only a deliberately-selected subset of methods is actually invoked
live** - global, ID-less, side-effect-free queries, plus a handful of
methods with a project-CONFIRMED no-op or pure-check body. Everything
else (anything touching surface/swap/lock/buffer-submission machinery,
anything ID-indexed into per-resource bookkeeping, anything needing a
real Apple `IOAccelSurfaceData`/`IOAccelSurfaceScaling`/
`IOAccelDeviceRegion` struct this project hasn't reconstructed, and
anything whose real behavior is simply uncertain) is recorded with its
best-available shape via `report_skipped()` and never called. See
`Tests/common.h`'s top-of-file note for the exact policy. **Do not
"upgrade" a skipped test to a live one without first establishing a
real, valid setup sequence** (an actually-created/bound surface, etc.) -
that is exactly what the #43 incident was missing.

## Confidence tiers (load-bearing for interpreting results)

- **GL context**: all 21 selectors have real, call-site-CONFIRMED wire
  shapes (see `test_gl_context.c`'s header note for how the one
  cross-connection ambiguity - selector 7 turning out to belong to a
  second, Surface-typed connection the GL bundle also opens - was
  resolved via static register tracing, not live testing). This
  superseded the ORIGINAL, wrong assumption that the kernel-side
  `VendorExternalMethod` table's count fields could be read positionally
  as input/output/other - they can't; see the corrected comment on that
  struct in `Headers/ATIRadeonX1000Types.h`.
- **2D, DVD contexts**: roughly half of each class's selectors have
  real call-site-CONFIRMED shapes from `ATIRadeonX1000GA.plugin`/
  `ATIRadeonX1000VADriver.bundle`; the rest fall back to the header's
  declared C++ signature and are flagged UNVERIFIED. Several real
  discrepancies were found even where a call site WAS available (e.g.
  DVD's `set_surface`/`set_macrovision` real argument counts don't match
  their headers' declared signatures) - these are noted per-method as
  follow-up candidates, not silently corrected.
- **Surface context**: no vendor bundle in this project's possession
  calls Surface directly except one real cross-connection call found
  inside the GL bundle (selector 7/`set_id_mode`). Every other selector
  falls back to the header signature and is UNVERIFIED; several also
  need real, unreconstructed Apple struct types this project has
  deliberately left alone.

## What "pass" means at this stage

This harness does not yet assert a single hard-coded expected `IOReturn`
per method for most calls - `common.h`'s `report()` helper accepts an
optional list of sane outcomes and otherwise just records whatever the
kernel returned. At this "prove out the structure" stage, the thing
being validated is the **round trip itself**: that a real `IOReturn`
comes back promptly (not a hang, not a panic, not a wildly out-of-range
value) for a call shape (selector index, scalar in/out counts, struct
sizes) built from this project's own understanding of the real driver.
That is direct evidence the selector/count transcription is right.
Building out specific expected-value assertions per method (e.g. "a
bogus texture ID must return exactly X") is part of the full-coverage
pass, informed by what the stock driver's real live responses turn out
to be.

## Building and running (on the G5, Tiger 10.4.11)

```
cd "/Volumes/Test HD/atiradeonx1000-kext-source/Tests"
make
./parity_test_harness
```

Run this against the stock Apple driver first to validate the harness
itself (its calls should behave sanely against a known-good driver
before being trusted to evaluate this project's own rebuild). Re-run
unchanged against this project's own installed kext once issue #41's
install procedure exists and has been exercised, and diff the two runs'
output.

## Full method inventory

**81 external methods total** across the 4 context classes (this
corrects an earlier miscount of 78 in this file, which undercounted the
2D subclass's 3 extra selectors) - see each class's own header for the
authoritative list with real selector numbers:

- `Headers/IOATIR500GLContext.h` (selectors 0-19) +
  `Headers/ATIR500GLContext.h` (selector 20) - 21 methods
- `Headers/IOATIR5002DContext.h` (selectors 0-15) +
  `Headers/ATIR5002DContext.h` (selectors 16-18) - 19 methods
- `Headers/IOATIR500DVDContext.h` (selectors 0-9) +
  `Headers/ATIR500DVDContext.h` (selectors 10-21) - 22 methods
- `Headers/IOATIR500Surface.h` + `Headers/ATIR500Surface.h`
  (selectors 0-18) - 19 methods

Live run against the stock driver (2026-09-18): 24 of 81 methods
actually invoked (all global/side-effect-free queries or
project-confirmed no-op/pure-check bodies), 0 unexpected results, 57
recorded with a real or best-available shape and deliberately skipped
per the safety policy above.

PM4 opcode-level coverage (the command-buffer opcode dispatchers each
context's `process_command_buffer`-style methods handle internally,
once a command/context buffer is actually submitted) is a distinct,
larger piece of #42's scope, out of scope for this scalar-external-
method harness - tracked separately.
