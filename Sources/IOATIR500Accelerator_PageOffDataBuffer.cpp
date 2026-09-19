/*
 * IOATIR500Accelerator_PageOffDataBuffer.cpp
 *
 * RESOLVED (issue #28): `IOATIR500Accelerator::pageOffDataBuffer`'s real
 * body, real addr 0x3140.
 *
 * Real behavior: tries `allocDataBufferBacking(buffer)` first.
 *
 * On FAILURE (0): calls `deallocate_texture(buffer)` (virtual dispatch -
 * RESOLVED, issue #28 addendum, see `Headers/IOATIR500Accelerator.h`),
 * then unlinks `buffer` from whatever real doubly-linked list it
 * currently sits in via its own `surfaceOrFormatInfo`/`listNext`
 * (`+0x24`/`+0x28`) fields, and sets both back to point at itself - the
 * real "detached, empty single-node list" idiom this project has not
 * previously named but is a real, recognizable C doubly-linked-list
 * pattern.
 *
 * On SUCCESS (nonzero): a real "temporarily redirect the GART mapping,
 * copy hardware descriptor data, restore it" sequence -
 *   1. If `buffer->gartMapping` (`+0x10`) is non-null, calls its own
 *      real, unidentified vtable slot `+0xf0` with args `(0, 0x400, 0)` -
 *      an Apple `IOMemoryMap`-family method this project does not
 *      reverse-engineer further (out of scope, same category as other
 *      external Apple vtable calls elsewhere in this project).
 *   2. The same real `+0x14c`/`+0xd0` "prepare mapping, then get real
 *      hardware-info pointer" vtable chain `load_texture` already
 *      establishes, called on `buffer->memoryDescriptor` (`+0x08`) with
 *      a different real flags value (`0x401` vs. `load_texture`'s own
 *      `accelerator+0x82c | 1`).
 *   3. If `buffer->poolSizeClass >> 2` (`+0x50`) is nonzero, copies that
 *      many dwords from `*(this+0xe4) + buffer->transferBufferFlag`
 *      (`+0x48`) into the real hardware-info pointer from step 2 - a
 *      real, previously-unknown use of `transferBufferFlag` as a byte
 *      offset rather than a pure boolean gate (this project's own prior
 *      documentation of that field as just a gate stands for its OTHER
 *      call sites; this is additional real evidence of a richer role).
 *      `this+0xe4` (accelerator-owned) is a real, not-yet-named pointer
 *      field - role UNKNOWN beyond this one use.
 *   4. Releases the real hardware-info object from step 2 (vtable
 *      `+0x18` - the same real `OSObject::release()` pattern issue #20
 *      resolved).
 *   5. Re-issues the same `+0xf0` call from step 1 on `gartMapping`, this
 *      time with args `(buffer->memoryDescriptor, 0x400, 0)` - restoring
 *      whatever step 1 temporarily redirected.
 *
 * Confidence: CONFIRMED for control flow and every real offset - a real,
 * complete, standalone decompile. The exact real semantics of the
 * `+0xf0` Apple vtable calls and the `this+0xe4` field are UNKNOWN
 * beyond what's described above. No C++ compiler was available in the
 * sandboxed environment this was written in (same standing limitation as
 * every other file in this project) - checked by careful, repeated
 * manual re-reading against the raw decompile instead.
 */

#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/ATIRadeonX1000Types.h"

extern "C" int kernelTaskRef asm("_kernel_task"); /* kernel_task pointer value; the Ghidra label "_ASICSupportsAGP" hid this real relocation target (issue #58 follow-up) */

/* (re-ported mechanically: see IOATIR500Accelerator_pageOffDataBuffer_Port.cpp) */

