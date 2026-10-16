# ATIRadeonX1000.kext - source reconstruction of the Tiger X1900 driver stack

A C++ reconstruction of Apple's `ATIRadeonX1000.kext` (the Mac OS X 10.4 Tiger IOKit driver for the ATI Radeon X1900 / R580), built from a Ghidra
decompilation of the shipped binary, plus a machine-generated transcription of the driver's userspace binaries (GLDriver bundle, GA plugin, VA
driver, libGL, libGLProgrammability) to C corpora.

The goal is a source tree that compiles to a kext equivalent to the shipped one, so the driver can be studied, audited and modified.

Related project: [`g5-h264-gpu-decode`](https://github.com/SamBushman/g5-h264-gpu-decode) drives Apple's unmodified kext from userspace; its
`promo4-client/reveng/` directory holds register maps and command-language notes that complement this tree. This repository is standalone.

## What you need to build it

| requirement | notes |
|---|---|
| Mac OS X 10.4 Tiger, PowerPC | the kext is built natively; it is a Tiger-style `MH_OBJECT` kext, linked with `-static -nostdlib -r` against `libkmodc++`, `libkmod` and `libcc_kext` |
| Apple gcc 4.0.1 (Xcode 2.x) and the Kernel.framework headers | `powerpc-apple-darwin8` toolchain; see `Tools/build_kext.sh` for the exact flags (`-fapple-kext`, `-fno-rtti`, `-fno-exceptions`, `-mlongcall`) |
| `sh`, `otool`, `nm` | for the link check |
| Python 3 | the ledger and comparison tools in `Tools/` are Python; they read disassembly dumps, so they do not have to run on the Tiger machine |
| the shipped `ATIRadeonX1000.kext` binary | only for the verification tools (vtable diff, callee comparison, data audit). It is not included; extract it from your own Tiger 10.4.x install |

You do not need Ghidra to build the kext: the archived decompile is in `Ledger/ghidra/`. Ghidra 12.1.3 is only needed to regenerate the userspace
corpora (`Tools/userspace/pipeline/README.md`).

## Building

On the Tiger machine, from the repository root:

    sh Tools/build_kext.sh                    # builds ATIRadeonX1000.kext under $OUT
    sh Tools/link_check.sh                    # confirms it links, without loading it

Environment variables: `OUT` (build directory; set it explicitly), `KEXT_ID` (bundle identifier - use a different one for a trial build so it
cannot be confused with the system kext), `KEXT_VERSION`, `OPT` (default `-Os`; `OPT=` gives the unoptimized build that the callee comparison
expects). Large PowerPC links may need a newer linker (ld64) first on `PATH`.

The only undefined symbols in a correct build are the kernel/IOKit imports the shipped kext also imports, plus the two symbols the shipped kext
leaves undefined itself (`ATIRadeonX1000::system_will_sleep` / `did_wake`).

If you build from another machine and drive the Tiger box over SSH, `Tools/remote_build.sh [ssh-host]` and `Tools/check_ledger.sh [ssh-host]` do
the copy/build/pull for you; the host name is an argument.

## Verifying a build

`Tools/check_ledger.sh` regenerates the completeness ledger (`Ledger/kext_ppc_ledger.tsv`) and diffs the vtables against the shipped kext; set
`STOCK` to the path of the shipped kext binary. Further static checks are documented in `Tools/README.md`:

    python3 Tools/callee_compare.py STOCK.dis OURS.dis   # per-method callee multiset diff (build with OPT=)
    python3 Tools/this_register_check.py STOCK.dis OURS.dis
    python3 Tools/alloc_size_compare.py STOCK.dis OURS.dis
    python3 Tools/audit_kext_data.py STOCK OURS          # data symbol comparison
    python3 Tools/audit_cast_types.py                    # must print 0 flagged after any re-port

## Status

| what | state |
|---|---|
| every shipped kext function is transcribed | yes - `Ledger/kext_ppc_ledger.tsv`: 2116 functions, 506 methods DONE, 0 MISSING; 470 of 470 named C++ methods present (`Tests/function_coverage.md`) |
| vtables match the shipped kext | yes, apart from the shipped kext's own `___cxa_pure_virtual` slots |
| static fidelity checks | vtable diff, argument-register use, object sizes and member offsets (`Sources/LayoutChecks.cpp`), callee comparison, uninitialised-local scan; every remaining difference is classified in `Tests/body_triage.tsv`. These compare calls, sizes, registers and layouts - they do not prove each body is instruction-for-instruction equivalent |
| kext data | every shipped data symbol is defined under its own name (`Tools/audit_kext_data.py`, `Ledger/data/`) |
| userspace binaries (PPC) | `Userspace/` - 4033 / 80 / 120 / 897 / 1799 functions (GLDriver / GA / VA / libGL / libGLProgrammability); all compile as C and are callee-verified against the shipped binaries; see `Userspace/README.md` |
| running on hardware | `Tests/` is a userspace harness that exercises the driver through its IOKit external methods; validate any build of your own on a machine you can reset (see Safety) |
| i386 slices | not transcribed (not required) |

## How the code was produced (read this before trusting a file)

Each method is in one of three provenance classes; the file banner says which:

1. **Mechanical port** - `Sources/<Class>_<method>_Port.cpp`, generated from the Ghidra decompile of the shipped kext by `Tools/replace_fn.py` /
   `Tools/port_fn.py` (control flow and arithmetic are Ghidra's; only types, `this`, base-class calls, atomics and data references are rewritten).
   This is the source of truth for every method of 150 bytes or more and for most smaller ones.
2. **Hand-verified body** - tiny tail-forwarders and base-class thunks whose Ghidra decompile drops register arguments, kept as bodies verified
   against the disassembly (`Tools/restore_old.py` restores them if a re-port is attempted).
3. **Generated** - compiler-generated members (metaclass, constructors, static-init) and the data tables.

Older hand-written source files keep their analysis comments as history. Where a body was later replaced, the file carries a
`(re-ported mechanically: see X_Port.cpp)` marker; the prose above it describes the earlier analysis, not the current code. Confidence tags in
comments (`CONFIRMED` / `INFERRED` / `UNKNOWN`) describe the *names and semantics* of fields and calls, not whether the machine code was transcribed.

## Layout

- `Headers/` - class headers, shared types (`ATIRadeonX1000Types.h`), the R5xx register map, PPC intrinsics (`ATIRadeonX1000PPCIntrinsics.h`: real
  `lwarx/stwcx.` atomics), Ghidra compatibility shims (`GhidraCompat.h`, `GhidraExterns.h`, `GhidraLiterals.h`).
- `Sources/` - implementations (`*_Port.cpp` = mechanical ports; other files = older analysis, data tables, hand-verified bodies).
- `Ledger/` - the completeness ledger, vtable listing, work list, `data/` (the kext's data sections) and `ghidra/` (the archived decompile dump).
- `Userspace/` - the userspace transcription (see its README); `Resources/Info.plist` - the kext's personality.
- `Tools/` - build, ledger, port and comparison tools; `Tools/userspace/` - the userspace pipeline (`pipeline/README.md` is the recipe).
- `Tests/` - a userspace feature-parity harness for the driver's external methods and its recorded baseline.

## Safety

This is a kernel driver for real GPU hardware. A faulty build can hang or panic the machine, and a hard power-off can damage the filesystem. Test on
a machine you can afford to reset, keep a way in that does not depend on the display (SSH from a second machine), and keep the stock kext available
to restore. Do not scan kernel memory broadly and do not fuzz the IOKit external methods with arbitrary arguments; derive call shapes from the
disassembly first. `Tests/destructive/README.md` describes the protocol for the methods known to be hang- or panic-prone.

## What is not done

- Complete hardware validation of a rebuilt kext across every external method and workload.
- A differential run of the recompiled GLSL compiler (libGLProgrammability) against the shipped one on real shaders.
- The i386 slices (kext and userspace), which are not required.
- Known defects in Apple's own code (for example the infinite loop on the allocation-failure path of `allocAllSlaveSwapBuffers`) are reproduced
  as shipped, not fixed.

The development diary (`GAPS.md`) and the long analysis notes (IDCT engine findings, per-method deep-path traces, stability and performance plans)
were removed from the tree. Source comments that cite them refer to the repository history before the commit that removed them
(`git log --diff-filter=D -- GAPS.md`).
