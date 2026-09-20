# ATIRadeonX1000.kext - source reconstruction and full transcription of the Tiger X1900 driver stack

A C++ reconstruction of Apple's `ATIRadeonX1000.kext` (the Tiger IOKit driver for the ATI Radeon X1900 / R580) built from Ghidra decompilation
of the shipped binary, plus a machine-generated transcription of the driver's userspace binaries. The kext is built with Apple gcc 4.0.1 on the
Tiger G5 and checked function by function against the shipped kext; the userspace binaries (GLDriver bundle, GA plugin, VA driver, libGL,
libGLProgrammability) are transcribed to C corpora and checked the same way.

Context: this began as a side project of [`g5-h264-gpu-decode`](https://github.com/SamBushman/g5-h264-gpu-decode) (whose decoder deliberately talks to
Apple's unmodified kext from userspace); it is standalone. See that repo's `promo4-client/reveng/` for the register maps and command-language notes.

## Status (2026-09-19)

| what | state |
|---|---|
| kext builds and links | yes - `sh Tools/remote_build.sh` (copies the tree to the G5, builds with Apple gcc 4.0.1, prints failures + link summary). The only undefined symbols are the expected kernel/IOKit imports and the two stock-undefined `ATIRadeonX1000::system_will_sleep/did_wake` |
| every shipped kext function is transcribed | yes - `Ledger/kext_ppc_ledger.tsv`: 2116 functions, 506 methods DONE (249104 bytes), 0 MISSING; 470 of 470 named C++ methods present (`Tests/function_coverage.md`) |
| vtables match the shipped kext | yes - `sh Tools/check_ledger.sh G5` reports 0 differing vtable lines (only stock's `___cxa_pure_virtual` slots differ by construction) |
| fidelity checks | per-method callee comparison at -O0 (`Tools/callee_compare.py`), atomics, immediates, size at -O1 (ours 248268 vs stock 249104 bytes) |
| kext data | every stock data symbol is defined under the stock's own name and no stock data content is missing (`Tools/audit_kext_data.py`, `Ledger/data/`) |
| userspace binaries (PPC) | `Userspace/` - 4033 / 80 / 120 / 897 / 1799 functions (GLDriver / GA / VA / libGL / libGLProgrammability), all compile as C, callee-verified against the stock binaries; every byte of every code section is accounted for; all data sections transcribed. See `Userspace/README.md` |
| runs on hardware | **not yet for the rebuilt kext.** The rebuilt kext has never been loaded; the mechanically re-ported methods have only been checked statically. `Tests/` (a userspace harness) drives the *stock* driver. Issues #41-45 track the load/test process, #32 a real Apple bug |
| i386 slices | not transcribed (not required) |

## How the code was produced (read this before trusting a file)

Each method is in one of three provenance classes; the file banner says which:

1. **Mechanical port** - `Sources/<Class>_<method>_Port.cpp`, generated from the Ghidra decompile of the shipped kext by `Tools/replace_fn.py` /
   `Tools/port_fn.py` (control flow and arithmetic are Ghidra's; only types, `this`, base-class calls, atomics and data references are rewritten).
   This is now the source of truth for every method of 150 bytes or more and for most smaller ones (238 methods were re-ported after an audit found
   real defects in earlier hand-written bodies: non-atomic stand-ins for `lwarx/stwcx.`, dropped calls, wrong out-parameter layouts).
2. **Hand-verified body** - 38 tiny tail-forwarders and base-class thunks whose Ghidra decompile drops register arguments (`f()` with no arguments),
   so they were kept as bodies verified against the disassembly (`Tools/restore_old.py` restores them if a re-port is attempted).
3. **Generated** - compiler-generated members (metaclass, constructors, static-init) and the data tables.

Old hand-written source files keep their analysis comments as history. Where a function body was later replaced, the file carries a
`(re-ported mechanically: see X_Port.cpp)` marker at that spot; the prose above it describes the earlier hand-written analysis, not the current code.
Confidence tags in comments (`CONFIRMED` / `INFERRED` / `UNKNOWN`) describe *names and semantics* of fields and calls, not whether the machine
code was transcribed - that is now complete.

## Layout

- `Headers/` - class headers, shared types (`ATIRadeonX1000Types.h`), the R5xx register map, PPC intrinsics (`ATIRadeonX1000PPCIntrinsics.h`: real
  `lwarx/stwcx.` atomics), Ghidra compatibility shims (`GhidraCompat.h`, `GhidraExterns.h`, `GhidraLiterals.h`).
- `Sources/` - implementations (`*_Port.cpp` = mechanical ports; other files = older analysis + data tables + hand-verified bodies).
- `Ledger/` - the completeness ledger (`kext_ppc_ledger.tsv`), vtable listing, work list, `data/` (the kext's data sections), `ghidra/` (the
  archived kext decompile dump).
- `Userspace/` - the userspace transcription (see its README); `Resources/Info.plist` - the kext's personality.
- `Tools/` - build, ledger, port and comparison tools; `Tools/userspace/` - the userspace pipeline (`pipeline/README.md` = how to reproduce it).
- `Tests/` - the userspace feature-parity harness for the stock driver (issue #42) and its recorded baseline.
- `GAPS.md` - the running log of what was found and resolved, plus the list of what is still open.

## Working with it

    sh Tools/remote_build.sh                  # build on the G5 (OPT=-O0 for the callee comparison, LINES_MAX=N for more output)
    sh Tools/check_ledger.sh G5               # regenerate the ledger + vtable diff (expect 0 MISSING)
    python3 Tools/callee_compare.py STOCK.dis OURS.dis   # per-method callee multiset diff (build with OPT=-O0)
    NOEXACT=1 python3 Tools/replace_fn.py 0xADDR ...     # re-port a method from the archived decompile (override table: Tools/replace_fn_overrides.tsv)
    python3 Tools/audit_cast_types.py         # must print 0 flagged after any replace_fn batch (scalar-pointer params aliased as bytes)
    python3 Tools/audit_kext_data.py STOCK OURS          # data symbol comparison

The Tiger G5 is reached as `ssh G5`; large PPC builds need ld64 on PATH. Live tests on the G5 need explicit per-step authorization (never scan
`/dev/kmem`, never fuzz `IOConnect*`).

## What is not done

See `GAPS.md` ("Open items" at the top). In short: running the rebuilt kext on hardware (issues #41-45), the differential run of the
recompiled GLSL compiler against the stock one, linking the userspace corpora into loadable binaries, and the i386 slices.
