/* NOTE 2026-09-19: 3 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * IOATIR500Accelerator_VRAMReclaim.cpp
 *
 * RESOLVED (issue #31): `IOATIR500Accelerator::freeToAllocTextureVRAM`
 * (real addr 0x3f60), `IOATIR500Accelerator::freeToAllocSurfaceVRAM`
 * (real addr 0x45a0), and `IOATIR500Accelerator::tossSurfacesForVRAM`
 * (real addr 0x3d60) - by far the densest three of this issue's real
 * functions (`freeToAllocTextureVRAM` in particular is comparable in
 * size/density to `allocAllSlaveSwapBuffers`, issue #28's own densest
 * target), grouped in one file since all three cooperate on the same
 * real VRAM-reclamation problem and share real field/list conventions.
 *
 * `freeToAllocTextureVRAM` is transcribed AS LITERALLY AS POSSIBLE,
 * preserving the real decompile's own Ghidra-assigned label names
 * (`LAB_00004040` etc.) and variable names as real C++ `goto` labels/
 * locals verbatim, rather than force-restructuring them into "clean"
 * control flow - the same discipline `IOATIR500Surface_
 * AllocAllSlaveSwapBuffers.cpp` already established for a function this
 * dense, and doubly important here: an earlier draft of this exact
 * function that DID try to restructure/rename the goto-diamond into
 * cleaner code introduced at least one fabricated function name and
 * several unverifiable label-correspondence guesses before being
 * discarded in favor of this literal version. Keeping Ghidra's own
 * label/variable names makes every line mechanically auditable against
 * the original decompile.
 *
 * Real shared structure across all three: a real doubly-linked circular
 * list of `VendorTextureBuffer`-shaped nodes (own `+0x24`/`+0x28`
 * prev/next fields - matching this project's already-established
 * `surfaceOrFormatInfo`/`listNext` fields exactly; Ghidra's own
 * `-noanalysis` decompile mistypes these list nodes as
 * `IOATIR500Accelerator*` due to poor type propagation from the two
 * list-head fields' own declared type - transcribed here as raw `UInt8*`
 * instead), rooted at two real accelerator fields: `this+0x5dc`
 * (sentinel)/`this+0x604` ("active" list head) and `this+0x600`
 * ("deferred"/secondary list head) - real roles beyond "two related
 * eviction-candidate rings" not independently confirmed.
 * `freeToAllocTextureVRAM` surfaced an entire real, previously
 * undocumented family of accelerator-owned STATISTICS COUNTERS
 * (`this+0x7cc` through `this+0x7f4`, plus a literal `this+2000`
 * (`0x7d0`) - each simply incremented at a real decision point in the
 * eviction search) - real per-counter MEANING inferred only from its own
 * increment site, not independently confirmed against any debug/
 * telemetry interface.
 *
 * `tossSurfacesForVRAM`/`freeToAllocSurfaceVRAM` additionally walk the
 * real live-surface list via a `+0xa0` "next" pointer - NOTE this is a
 * DIFFERENT real offset than `+0x9c`, this project's own already-
 * established `nextLiveSurface` field (`IOATIR500Accelerator_
 * SetupStereo.cpp`) - transcribed exactly as decompiled rather than
 * assumed to be the same field; real relationship between the two
 * (a second distinct list vs. a real transcription slip in either this
 * or the earlier function) not investigated this pass.
 *
 * Confidence: CONFIRMED for control flow and every real offset AS GIVEN
 * BY Ghidra's own C decompile (trustworthy per this project's long-
 * standing "class-typed pointer already byte-scaled" convention - these
 * three functions are unusually clean in that respect, with almost no
 * genuinely ambiguous pointer arithmetic despite their size) but NOT
 * independently re-traced against raw disassembly instruction-by-
 * instruction given their sheer size - several field roles (the
 * statistics counters, the `+0xa0` list, a handful of vtable slots with
 * no established name: `+0x554`, `+0x56c`/`+0x5d0`'s exact real target)
 * remain UNKNOWN beyond what's directly inferable from their own call
 * site. No C++ compiler was available in the sandboxed environment this
 * was written in (same standing limitation as every other file in this
 * project).
 */

#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt8  &B(void *p, int o)  { return *(reinterpret_cast<UInt8 *>(p) + o); }
inline UInt16 &H(void *p, int o)  { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(p) + o); }
inline SInt32 &SW(void *p, int o) { return *reinterpret_cast<SInt32 *>(reinterpret_cast<UInt8 *>(p) + o); }
inline UInt32 &W(void *p, int o)  { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(p) + o); }

/* real vtable +0x554 on IOATIR500Accelerator - no established name/role;
   called here with a real per-node stamp value (mip[0xc]), same real
   argument shape as the already-named waitForTimeStamp (+0x54c) one
   slot over - plausibly a sibling fence-wait variant, not confirmed. */
typedef UInt32 (*Fn0x554)(void *, UInt32);
inline UInt32 CallVtable0x554(void *accel, UInt32 arg) {
    void **vtable = *reinterpret_cast<void ***>(accel);
    return reinterpret_cast<Fn0x554>(vtable[0x554 / 4])(accel, arg);
}
} // namespace

/* (re-ported mechanically: see IOATIR500Accelerator_freeToAllocTextureVRAM_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Accelerator_freeToAllocSurfaceVRAM_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Accelerator_tossSurfacesForVRAM_Port.cpp) */

