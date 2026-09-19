/*
 * IOATIR500Surface_AllocRetryAndOrphans.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real bodies for
 * `alloc_surfaces_retry`, `attach_buffer_backing_store`,
 * `free_buffer_backing_orphans` (IOATIR500Surface), and
 * `addOrphanTexture` (IOATIR500Accelerator) - found via Ghidra
 * decompile at each function's own real, substantial address (every
 * other match is a trivial self-recursive stub/thunk artifact).
 *
 * Confidence: CONFIRMED for control flow and every real struct offset.
 * `+0x570` is already independently named elsewhere in this project
 * (allocVendorTextureBuffer). The two real "brief unlock, yield twice,
 * relock" helper calls in `alloc_surfaces_retry`'s own retry loop
 * (real addresses, each taking a single literal argument) are not
 * independently identified - pinned by address per this project's own
 * established convention for a genuinely unidentified local helper.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

extern "C" void GLSurfaceRetry_mutex_lock(void *) asm("_IOLockLock");
extern "C" void GLSurfaceRetry_mutex_unlock(void *) asm("_IOLockUnlock");
/* RESOLVED (issue #58 follow-up): FUN_000149f4 = thread_block (0x32eec),
 * FUN_000149e4 = IOSleep (0x2b255c) - a yield then a 1 ms sleep, live kxld read. */
extern "C" void GLSurfaceRetry_thread_block(UInt32 continuation) asm("_thread_block");
extern "C" void GLSurfaceRetry_IOSleep(UInt32 milliseconds) asm("_IOSleep");

/*
 * alloc_surfaces_retry - CONFIRMED, transcribed faithfully. Real body:
 * an up-to-0x3e9-iteration retry loop. `lockType==0` (write) requires
 * the accelerator's own +0x80 "ready" flag; `lockType==1`/`2` (the two
 * real per-lock-type slots, +0xbd0/+0xbd1) instead short-circuit
 * success immediately if that slot is already non-zero. Otherwise
 * tries `alloc_surfaces_pageq` against the caller's own format mask;
 * a real "would need eviction" result (2) fails outright, a real
 * "nothing to do" result (0) succeeds outright, and any other result
 * retries after a brief unlock/yield/relock. After 0x3e9 failed
 * retries, falls back to a real last-resort attempt against just this
 * surface's own persistent bits (+0xc1c & 3).
 */
/* (re-ported mechanically: see IOATIR500Surface_alloc_surfaces_retry_Port.cpp) */


/*
 * attach_buffer_backing_store - CONFIRMED, transcribed faithfully.
 * Real body: allocates a real fixed-size (0xc0-byte) tracking record
 * via the accelerator's own `allocVendorTextureBuffer` (+0x570,
 * already named elsewhere in this project), zero-initializes a real
 * ~0x30-byte sub-record embedded at its own +0x14, wires the caller's
 * real memory descriptor and alignment/pitch fields in, and - if this
 * surface has a real "notify on attach" flag (+0xbf7) and the target
 * buffer already has its own live descriptor - issues one more real
 * "set cache mode" vtable call (+0xdc, mode 2, the same real shape
 * already established for `connect_buffer_backing_store`).
 */
/* (re-ported mechanically: see IOATIR500Surface_attach_buffer_backing_store_Port.cpp) */


/*
 * free_buffer_backing_orphans - CONFIRMED, simple: releases the
 * pending-eviction slot's (+0xd8c) own inner memory-mapping handle if
 * set, then deletes the backing itself via `delete_buffer_backing`
 * and clears the slot.
 */
/* (re-ported mechanically: see IOATIR500Surface_free_buffer_backing_orphans_Port.cpp) */


/*
 * addOrphanTexture - CONFIRMED, transcribed faithfully. Real body:
 * splices the buffer onto the accelerator's own real doubly-linked
 * orphan-texture list (head at +0x660, each node's own +0x24/+0x28
 * prev/next links, the list's own sentinel node embedded at
 * accelerator+0x63c), and if the accelerator's own "orphan sweep
 * scheduled" flag (+0x82) is clear, schedules one via a real
 * `IOService::setTimeoutMS`-shaped vtable call (+300/0x12c on the
 * accelerator's own +0xb8 provider object) with a real 100ms delay,
 * setting the flag so it isn't scheduled again until the sweep runs.
 */
/* (re-ported mechanically: see IOATIR500Accelerator_addOrphanTexture_Port.cpp) */

