/*
 * IOATIR500Surface_LockOptions.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real bodies for
 * `surface_lock_options` and `surface_unlock_options` - the two real
 * IOATIR500Surface base-class methods backing every one of the six
 * real external-method thin-forward wrappers this project already
 * transcribed (surface_read_lock/_unlock, surface_write_lock/_unlock,
 * the read/write "_options" pair themselves). `surface_lock_options`
 * is the single most complex function in this whole file set - real,
 * substantial control flow with many real early-exit paths, found via
 * Ghidra decompile at its own real address (every other match for
 * both names is a trivial self-recursive stub/thunk artifact).
 *
 * Transcribed preserving the real decompile's own goto/label structure
 * rather than restructured into pure structured control flow, to
 * minimize transcription risk in a function this size and this
 * heavily label-driven.
 *
 * Real signature note: the header's own trailing `UInt32 size`
 * parameter on `surface_lock_options` is never referenced anywhere in
 * this real body at all - the real zero-init call at the top
 * (originally a real, address-pinned local helper, modeled here as a
 * plain `memset` - functionally identical for "zero N bytes", and this
 * project's own honest simplification given the real helper's own
 * identity wasn't independently pinned) always zeroes a fixed real
 * 0x44-byte span regardless of the caller-supplied size - matching
 * this project's own established "real parameter, confirmed unused"
 * precedent elsewhere.
 *
 * Confidence: CONFIRMED for control flow and every real struct offset.
 * Several vtable slots are already independently named elsewhere in
 * this project (dealloc_surface +0x5cc, prepare_vram +0x5fc); the real
 * +0x558 "release/flush timestamp" slot (seen 3 times, always on the
 * accelerator) is not independently named and is called via this
 * project's established raw vtable-cast idiom.
 *
 * ADDED (issue #42 test-harness pass): a real, byte-exact PARTIAL layout
 * for Apple's own `IOAccelSurfaceData` (`out`/`data` above), read directly
 * off every real write this function makes into it - useful for building
 * a same-shape scratch buffer to call this method's external-method
 * wrappers live, even though the struct is still not fully reconstructed:
 *   +0x00 (UInt32): a real computed base address (buffer's own `+8` field
 *          plus this surface's own `+0xc0c`, OR a resolved backing-store
 *          handle's own address plus a real `+0x50` halfword, depending
 *          which real path was taken)
 *   +0x10 (UInt32, UInt16-sourced): buffer's own `+0x18`, or a
 *          backing-store record's own `+0x52` - plausibly pitch/stride,
 *          not confirmed
 *   +0x14 (UInt32, UInt16-sourced): buffer's own `+0x1c` - plausibly width
 *   +0x18 (UInt32, UInt16-sourced): buffer's own `+0x1e` - plausibly height
 *   +0x1c (UInt32): a real pixel-format code derived from this surface's
 *          own `+0xbe8` mode-bits (`& 0xf`) - value 6 maps to the real
 *          FourCC `'yuvs'` (0x79757673), value 9 to `'2vuy'` (0x32767579,
 *          the real, industry-standard UYVY-422 FourCC), value 10 to the
 *          small integer 4, anything else passed through raw
 *   +0x20/+0x34/+0x38/+0x3c/+0x40 (UInt32 each): copies of this surface's
 *          own `+0xd70`/`+0xd74`/`+0xd78`/`+0xd7c`/`+0xd80`
 *   +0x24 (UInt32): a real fixed literal constant, `0x1cccc`
 * Bytes 0x04-0x0f and 0x28-0x33 are real (part of the same zeroed 0x44-byte
 * struct) but never written by this function - either genuinely always
 * zero here, or populated by some other real caller this project hasn't
 * decompiled. A real, byte-exact PARTIAL layout, not a complete Apple
 * struct reconstruction.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000Types.h"
#include <IOKit/IOTypes.h>
#include <string.h>

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

extern "C" void GLSurfaceLock_mutex_lock(void *) asm("_IOLockLock");
extern "C" void GLSurfaceLock_mutex_unlock(void *) asm("_IOLockUnlock");

/* (re-ported mechanically: see IOATIR500Surface_surface_lock_options_Port.cpp) */


/*
 * surface_unlock_options - CONFIRMED, transcribed faithfully. Real
 * body: reads the same real per-lock-type single-byte state
 * (+0xbd0/+0xbd1, matching surface_lock_options above) and, if set,
 * either releases a real CPU-visible mapping (state 3, real orphan-
 * drain deferred to `free_buffer_backing_orphans` when this surface's
 * own +0xd8c pending-eviction slot is occupied) or issues a real
 * `complete_vram` call (state 1, "was allocated"), clearing the state
 * byte either way.
 */
/* (re-ported mechanically: see IOATIR500Surface_surface_unlock_options_Port.cpp) */

