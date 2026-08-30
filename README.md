# ATIRadeonX1000.kext source reconstruction

A from-scratch, best-effort C++ reconstruction of Apple's `ATIRadeonX1000.kext` (the Tiger/Leopard
IOKit driver for the ATI Radeon X1900/R580), built entirely from Ghidra decompilation of the shipped
binary during the [`g5-h264-gpu-decode`](https://github.com/SamBushman/g5-h264-gpu-decode)
reverse-engineering effort - see that repo's `promo4-client/reveng/` directory for the full decompilation
notes (register maps, opcode-language traces, external-method tables, etc.) this reconstruction draws on.

## Why this exists, and how it relates to the other repo

This is a **separate, standalone effort** from the PROMO4 client-protocol work and the FFmpeg hook that
live in `g5-h264-gpu-decode`. That project's own plan explicitly chose a userspace-only approach
approach for the decoder (open a second connection to Apple's existing, unmodified, already-loaded kext
rather than writing or patching one) specifically to avoid kernel-space risk. This reconstruction doesn't
reverse that decision - it exists because having real, readable, buildable driver source is valuable on
its own (for understanding, for future reference, for potential targeted patching if ever justified) and
because it's productive work to do while the G5 itself is unreachable and no live testing is possible.

**This has never been compiled.** There is no Tiger/Leopard IOKit SDK, `Kernel.framework` headers, or
PowerPC kext toolchain available in the sandboxed environment this was written in. Every file here is
written as carefully and correctly as static analysis allows, following real Darwin/IOKit conventions
from this era, but **compiling it is the one remaining step that requires real hardware/toolchain
access** - specifically, a Tiger or Leopard machine (or a cross-toolchain with the matching
`IOAcceleratorFamily`/`IOKit` headers) to actually attempt a build and report the first error.

## Confidence levels

Everything here falls into one of three tiers, marked per-file and per-function in comments:

- **`CONFIRMED`**: directly read from a real Ghidra decompile this project produced, cross-referenced
  against real usage elsewhere (register documentation, other driver binaries, KolibriOS/other open
  reference drivers, or multiple independent call sites). High confidence the *behavior* is right; the
  exact C++ this project wrote to express that behavior is a reconstruction, not a byte-for-byte
  decompile - variable names, control-flow shape, and struct field names are this project's own choices
  made to produce clean, readable, plausible-to-compile code, not Ghidra's literal output.
- **`INFERRED`**: a reasonable, clearly-justified guess filling a real gap (an offset whose exact type
  was never nailed down, a field name chosen by convention rather than confirmed), called out inline.
- **`UNKNOWN`/`TODO`**: a real gap this project never closed - either not yet decompiled, or explicitly
  requiring live hardware tracing (per the standing project constraint that no hardware was available
  this session). Left as a stub with a comment explaining what's missing and how to close it.

## Layout

- `Headers/ATIRadeonX1000Types.h` - shared struct/type definitions used across every class.
- `Headers/ATIRadeonX1000Registers.h` - the real R5xx register map, as confirmed this project.
- `Headers/*.h` - one header per real class in the driver's hierarchy.
- `Sources/*.cpp` - reconstructed implementations, organized to mirror the header split.
- `Resources/Info.plist` - a best-effort `IOKitPersonalities` stub for the real PCI device IDs this
  project has referenced (X1900/R580), for whenever there's a real target to build/load this against.

## What to do when hardware is available again

1. Get a real Tiger or Leopard `Kernel.framework`/`IOKit.framework` header set (from the actual SDK on
   the G5, or a matching Xcode/CLT install) and a PowerPC kext-capable toolchain.
2. Attempt a build of `Headers/ATIRadeonX1000Types.h` + `Headers/ATIRadeonX1000Registers.h` alone first
   (no class bodies) - the fastest way to catch fundamental type mistakes before debugging real logic.
3. Build up class-by-class, starting with `ATIRadeonX1000` (the base hardware class) since everything
   else depends on it, then `IOATIR500GLContext`/`ATIR500GLContext` (the most completely reconstructed
   pair).
4. Cross-check every `TODO`/`UNKNOWN` marker against the real shipped kext with a live debugger, exactly
   as this project's `g5-ancient-gdb-technique` skill already documents for other purposes.
