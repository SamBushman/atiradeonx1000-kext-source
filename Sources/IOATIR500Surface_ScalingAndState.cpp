/* NOTE 2026-09-19: 3 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * IOATIR500Surface_ScalingAndState.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real bodies for
 * `set_scaling`, `set_volatile_state`, and `surface_buffer_idx_mask` -
 * three real IOATIR500Surface base-class methods, found via Ghidra
 * decompile at each function's own real, substantial address (every
 * other match is a trivial self-recursive stub/thunk artifact, not
 * real content).
 *
 * Confidence: CONFIRMED for control flow and every real struct offset.
 * Several vtable slots are already independently named elsewhere in
 * this project (shape_surface +0x5c8, is_surface_size_supported
 * +0x5b0); the real +0x540/+0x544 "resolve"/"commit" pair (already
 * seen unnamed in get_config/get_status) is called via this project's
 * established raw vtable-cast idiom.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline SInt16 &S16At(void *base, int offset) { return *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/*
 * set_scaling - CONFIRMED, transcribed faithfully. Real body: rejects
 * outright unless either "scaling disabled" (bit 1 of `flags` clear)
 * or a real `IOAccelSurfaceScaling*` was supplied. Stores real
 * mode/filter bytes (+0xbee/+0xbf1/+0xbed, the last a real sign-derived
 * flag from the current scale numerator's own high bit), then either
 * resets to a real 1:1 identity scale sourced from a real
 * `+0xd60`-pointed geometry record (disable path) or, for a real
 * "non-standard-format" surface only (+0xbe8 & 0x20), copies the
 * caller's own six real UInt16 scale fields directly. Always
 * re-derives the mirrored dest rect (+0xbd8/+0xbda from +0xbd4/+0xbd6),
 * re-shapes, invalidates every referencing context, clears a real
 * "scaling applied" flag (+0xbf8 bit 0x20000000), and validates the
 * new size via `is_surface_size_supported` - on success, additionally
 * resolves+commits a real per-surface record via the same unnamed
 * +0x540/+0x544 vtable pair `get_config`/`get_status` already
 * establish elsewhere in this file set.
 */
/* (re-ported mechanically: see IOATIR500Surface_set_scaling_Port.cpp) */


/*
 * set_volatile_state - CONFIRMED, transcribed faithfully. Real body:
 * stores the new state at +0xd48, then splices this surface into (real
 * state 1) or out of (any other state) the accelerator's own
 * doubly-linked "volatile surface" list (head at accelerator+0x5c,
 * each node's own +0x9c/+0xa0 prev/next links), incrementing or
 * decrementing the accelerator's own live-count at +0x21c to match.
 * Real signature CORRECTED (issue #1, get-it-linking pass): was
 * declared `UInt32 *state` - the real confirmed body takes the state
 * value directly, never dereferences a pointer.
 */
extern "C" void GLSurface_mutex_lock(void *) asm("_IOLockLock");
extern "C" void GLSurface_mutex_unlock(void *) asm("_IOLockUnlock");

/* (re-ported mechanically: see IOATIR500Surface_set_volatile_state_Port.cpp) */


/*
 * surface_buffer_idx_mask - CONFIRMED, transcribed faithfully. Real
 * body: a real dispatch from an "attachment type" selector (matching
 * the same 0/1/2/3/4/7/8/10/11-style enum family this project already
 * established for opcode 0x2a/0x29's attachment tables) to a real
 * (per-format-mask, per-format-index) pair, resolved against this
 * surface's own current buffer-selection pointers
 * (+0xb70/+0xb80/+0xb84, the same real slots `prune_buffers` already
 * establishes) for the handful of types with a real "which physical
 * slot is this logically pointing at" ambiguity. Type 0x11 is a real
 * fallthrough gate on this surface's own requirement bits (+0xc18):
 * bit 2 set falls through to the shared default tail below; bit 1 set
 * (bit 2 clear) redirects to the SAME case-1 logic; neither set
 * returns a real zero mask/index pair directly.
 */
/* (re-ported mechanically: see IOATIR500Surface_surface_buffer_idx_mask_Port.cpp) */

