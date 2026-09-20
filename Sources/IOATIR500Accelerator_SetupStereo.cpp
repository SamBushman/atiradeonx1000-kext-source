/* NOTE 2026-09-19: 1 function body formerly in this file has been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * IOATIR500Accelerator_SetupStereo.cpp
 *
 * RESOLVED: `IOATIR500Accelerator::setup_stereo`'s real body, real addr
 * 0x5460. Real per-panel (`param1`) stereo-mode state machine.
 *
 * Real structure: if a real "already initialized" flag (`this+0x81`,
 * a single byte) is set, just stores the new mode bits into a real
 * per-panel array (`this+param1*4+0x124`) and returns - a real
 * fast-path once the subsystem is up. Otherwise: no-ops if the new mode
 * already equals the current one (`this+param1*4+0x11c`). If the
 * requested mode doesn't have its own real "stereo enabled" bit (bit 0)
 * clear... [bit 1 gets force-cleared]; if it DOES have bit 0 set and a
 * real per-panel scratch record (`this+param1*0x78+0x1ac`) isn't already
 * allocated, copies a real per-panel default template into it
 * (`FUN_000056f8`, RESOLVED issue #50 via live kxld-resolved `/dev/kmem`
 * read - real target `_memmove`/`_memcpy`; NOT a zero-init as this
 * project's prior account had guessed from the call shape alone - the
 * real second argument is a source POINTER, `self+param1*0x78+300`, not
 * a fill value) and allocates real backing VRAM for it via a real
 * vtable `+0x56c` call then `freeToAllocSurfaceVRAM` (own body not
 * decompiled this pass, real addr `0x45a0`) as a fallback. If the real
 * "stereo bit" of old vs. new mode differs, calls `waitForTimeStamp`
 * then a real vtable `+0x5cc` method (own identity UNKNOWN - not the
 * already-resolved `IOATIR500Surface::+0x5cc`, a DIFFERENT class's
 * vtable); on failure, force-clears stereo mode and frees the scratch
 * record's VRAM via `ATIR500Memory::dealloc` (RESOLVED elsewhere).
 * Finally, if the real per-panel STATE (not just requested mode) changed,
 * walks every live surface (`liveSurfaceListHead`, `+0x5c`) calling three
 * real, already-named-but-undecompiled methods:
 * `IOATIR500Surface::freeAllSwapBuffers`,
 * `IOATIR500Surface::allocMasterSwapBuffer`,
 * `IOATIR500Surface::allocAllSlaveSwapBuffers` (RESOLVED, issue #28 - the
 * one with the confirmed real infinite-loop bug in its own failure path).
 *
 * Confidence: CONFIRMED for control flow and every real offset - a real,
 * complete, standalone decompile. `freeToAllocSurfaceVRAM` (RESOLVED,
 * issue #31, and its own call here FIXED from a placeholder free
 * function taking an explicit accelerator pointer to a real member call
 * - see Sources/IOATIR500Accelerator_VRAMReclaim.cpp),
 * `freeAllSwapBuffers`/`allocMasterSwapBuffer` (also RESOLVED, issue #31
 * - see Sources/IOATIR500Surface_SwapBuffers.cpp), and the real `+0x56c`/
 * `+0x5cc` vtable slot identities remain otherwise as documented. No C++
 * compiler was available in the sandboxed environment this was written
 * in (same standing limitation as every other file in this project).
 */

#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000Types.h"
#include "../Headers/ATIR500Memory.h"

extern "C" void FUN_000056f8(void *dest, const void *src, UInt32 size) asm("_memmove"); /* RESOLVED, issue #50 */

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/* FIXED (issue #1, first build attempt): return type was SInt32,
 * mismatching the header's own declared IOReturn - on this exact
 * toolchain/SDK the two are distinct underlying types (kern_return_t vs
 * SInt32), so gcc treated this as a second, non-overloadable
 * declaration rather than the same function's definition. Matched to
 * the header's real declared type. */
/* (re-ported mechanically: see IOATIR500Accelerator_setup_stereo_Port.cpp) */

