/*
 * IOATIR500Surface_Start.cpp
 *
 * RESOLVED (issue #58, completing the external-method dispatch chain
 * issue #42 started): real body for `IOATIR500Surface::start`, real addr
 * 0x119f0. THE real function that populates `methodTable` (`this+0xd5c`,
 * `ATIR500Surface::getTargetAndMethodForIndex`'s own dispatch pointer) -
 * without this, the dispatch mechanism this project already implemented
 * (Sources/ATIR500Surface_ExternalMethods.cpp) would read an
 * uninitialized/zero pointer at runtime.
 *
 * Real structure: calls the real superclass `IOUserClient::start(provider)`
 * first (Ghidra's own decompile shows this call with zero visible
 * arguments - the same "argument-dropped" artifact already catalogued
 * throughout this project; the real provider argument is passed, matching
 * the identical already-established pattern in every other context
 * class's own start() override, e.g. Sources/ATIR500GLContext_Start.cpp).
 * `provider` here really is the accelerator itself (real client of the
 * accelerator's own device-tree node) - this function's very next line
 * stores it as `this+0xd50`, the SAME real `accelerator` field every
 * other Surface method already reads.
 *
 * Real per-slot array initialization (CONFIRMED, cross-validated against
 * already-established fields elsewhere in this project): a 23-iteration
 * loop (real count `0x17`, matching `prune_buffers`' own already-
 * documented "23 real per-format records" and `dealloc_surface`'s own
 * `0..0x16` range) zeroes/defaults a stride-`0x78` array starting at
 * `this+0` - its own `+0xa8..+0xd8` sub-range is the FIRST 0x30 bytes of
 * the SEPARATE, already-named `this+0xa8`-based `surfaceBuffersByFormat`
 * array (Headers/IOATIR500Surface.h) for the SAME slot index (confirmed:
 * this loop also writes `surfaceBuffersByFormat[i] = this+0xa8+i*0x78`
 * directly), and its own `+0x28+0x14` (`this+i*0x78+0x3c`) sub-field
 * masks in a real `0x111000` bit pattern - real per-field roles beyond
 * their raw offsets are UNKNOWN, transcribed literally.
 *
 * A second, 2-iteration loop (real count fixed at 2, matching the
 * already-established "two alternating buffer slots" pattern this
 * project has seen throughout `submit_swap_buffer`/`set_id_mode`/
 * `is_flip_allowed` - `this+id*8+0xd60/+0xd64` and `this+id*0x94+0xcac`
 * range) zeroes both slots' own small per-ID tracking records and a
 * nested 4-entry sub-array at `this+id*0x94+0xc3c` (stride `0x1c`).
 *
 * Real VRAM/swap-buffer bring-up: if the accelerator has zero real VRAM
 * heads (`accelerator+0xcc == 0`), just calls the accelerator's own
 * already-established real `getVRAMDescriptors()`. Otherwise, for each
 * real accelerator VRAM head (`0..accelerator->0xcc-1`), allocates a
 * real 12-byte per-ID tracking record (`IOMallocAligned(0xc, 0x20)`,
 * the SAME real allocator/size this project's own `set_id_mode` already
 * establishes) and calls the already-established real
 * `allocMasterSwapBuffer(id, 0x9000)` - a real, fixed 0x9000-byte size.
 * Either path's failure still falls through to real table/list setup
 * below (not an early return) - only the final `bVar1`/success flag
 * differs, gating whether `this+0xd58` gets set and whether a real
 * `stop(provider)` call happens at the very end (real cleanup-on-failure,
 * not a a bail-out).
 *
 * Real table/list setup (runs on EVERY path, success or failure): sets
 * `methodTable` to the real static table's own absolute address (see
 * Sources/ATIR500Surface_ExternalMethods.cpp), then splices this surface
 * into the accelerator's own real doubly-linked surface list
 * (`accelerator+0x5c` head, this surface's own `+0x9c`/`+0xa0`
 * next/prev links - a real, standard intrusive doubly-linked-list
 * insertion, self-linked if the list was empty), and increments a real
 * accelerator-owned surface-count field (`accelerator+0x730`).
 *
 * Confidence: CONFIRMED for control flow and every real offset/constant -
 * a real, complete, standalone decompile, cross-validated against this
 * project's own already-established fields wherever they overlap (see
 * above). Many per-slot sub-fields (`+0xbc`/`+0xbe`/`+0xc0`/`+0xc4`/
 * `+0xc6`/`+0xc8`/`+0xca`/`+0xdc`..`+0xe4` per 0x78-stride slot) have no
 * established real name/role beyond their raw offsets - transcribed
 * literally, not guessed at.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"

extern "C" void *SurfStart_IOMallocAligned(UInt32 size, UInt32 align) asm("_IOMallocAligned");

/* real table, Sources/ATIR500Surface_ExternalMethods.cpp */
extern const VendorExternalMethod kSurfaceMethods[19] asm("__ZZN16IOATIR500Surface5startEP9IOServiceE11methodDescs");

/* FUN_00011e38 - RESOLVED (issue #58): a kxld-patched lazy-binding stub
 * whose live target is `IOLockAlloc` (kernel 0x2b2704, exact offset-0 match
 * in `nm /mach_kernel`). Creates this surface's own per-object lock at
 * +0xc04, later used by set_surface_blocking. Resolved via the live
 * per-segment-slide read of the loaded kext (slide validated first against
 * `get_state`, whose live bytes match the static file exactly). */
extern "C" void *SurfStart_IOLockAlloc(void) asm("_IOLockAlloc");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/* (re-ported mechanically: see IOATIR500Surface_start_Port.cpp) */

