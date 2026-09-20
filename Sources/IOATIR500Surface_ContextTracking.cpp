/* NOTE 2026-09-19: 4 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * IOATIR500Surface_ContextTracking.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real bodies for
 * `update_contexts`, `reset_access`, `reset_req_bits`, and
 * `prune_buffers` - four real IOATIR500Surface base-class methods,
 * each found via Ghidra decompile at their own real, substantial
 * address (every other match for these names in the raw binary is a
 * trivial self-recursive stub/thunk artifact, not real content).
 *
 * `update_contexts`/`reset_req_bits` walk real per-surface linked
 * lists of referencing context objects rooted at this+0x88/this+0x8c
 * (a GL-context list and a second, differently-typed context list -
 * real element type NOT independently confirmed for either walk, so
 * both are modeled as raw `void*` nodes with a real, confirmed
 * `+0x84`-stride "next" link, called through their own vtables via
 * this project's established raw-cast idiom rather than guessed C++
 * types).
 *
 * Confidence: CONFIRMED for control flow and every real struct offset.
 * Several vtable slot identities used below are already independently
 * named elsewhere in this project (dealloc_surface +0x5cc,
 * shape_surface +0x5c8, invalidate +0x5a4 on the GL-context side);
 * others (+0x150, +0x14c on the accelerator, +0x5a8 on the second list
 * node type) are not, and are called via raw vtable casts.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/*
 * update_contexts - CONFIRMED. Clears the accelerator's own +0x78
 * "last bound GL context" cache, then invalidates every context on
 * this surface's own two real reference lists (GL-shaped list at
 * +0x8c via each node's own +0x5a4 slot, a second list at +0x88 via
 * +0x5a8), and finally a single extra "primary" reference at +0x90 if
 * set (same +0x5a8 slot).
 */
/* (re-ported mechanically: see IOATIR500Surface_update_contexts_Port.cpp) */


/*
 * reset_access - CONFIRMED. Real body: re-derives this surface's own
 * "read"/"write" access-descriptor pair (+0xd84/+0xd88, IOMemoryDescriptor-
 * shaped) whenever the accelerator's own current-tag field (+0xc00 on
 * this surface, aliasing accel-relative state) changes underneath it -
 * releases the old descriptors, asks the accelerator for a fresh
 * memory-descriptor handle via its own +0x150 vtable call (real
 * signature/identity not independently confirmed), and if this
 * surface's own +0xbf4 flag is set, a second descriptor via the
 * accelerator's own +0x14c call (the SAME real "prepare mapping" slot
 * this project already established elsewhere, e.g.
 * ATIR500GLContext_TextureLoad.cpp).
 */
/* (re-ported mechanically: see IOATIR500Surface_reset_access_Port.cpp) */


/*
 * reset_req_bits - CONFIRMED. Real body: rebuilds this surface's own
 * "requirements" bitmask (+0xc18, kept alongside a persistent-bits
 * mirror at +0xc1c masked to `0x30000020`) by OR-ing in every
 * referencing context's own per-context requirement bits (+0x8c on
 * each node of the same two real lists `update_contexts` above
 * walks), then walks a real, separately-linked "attached buffer" list
 * (+0xbcc head, own +0x54 next-link, stride/shape distinct from the
 * context lists above) OR-ing in either a fixed HyperZ-related bit
 * pair (real tag value 0x11) or the real per-format mask
 * `surface_buffer_idx_mask` already establishes elsewhere in this
 * project, and finally folds in one more real "primary" reference's
 * own +0x88 field if set.
 */
/* (re-ported mechanically: see IOATIR500Surface_reset_req_bits_Port.cpp) */


/*
 * prune_buffers - CONFIRMED, transcribed faithfully preserving the
 * real decompile's own forward jump. Real body: recomputes this
 * surface's own per-format buffer-selection pointers (+0xb70/+0xb74/
 * +0xb80/+0xb84, four real `ATIR500SurfaceBuffer*`-shaped slots
 * selecting among the surface's own fixed +0xa8/+0x120/+0x288/+0x300
 * per-format records) from its own real requirement bits (+0xc18),
 * with a distinct real short-circuit path when a "non-standard
 * format" bit (+0xbe8 & 0x20) is set. Then, for every one of the 23
 * real per-format records (0..0x16) NOT currently required, calls
 * this surface's own real `dealloc_surface` (+0x5cc) and - if that
 * record has a real backing store (+0xcc) or a real attachment handle
 * (+0xb8) - releases/zeroes it via `free_buffer_backing_store` and a
 * real ~40-byte block of per-record state reset. Finally re-shapes via
 * `shape_surface` and, if this surface is still the accelerator's own
 * currently-bound one, invalidates via a real, not-independently-named
 * `this`-own +0x5a4 vtable slot (NOT the same as GL's own +0x5a4
 * `invalidate` - a different class, a different real vtable).
 */
/* (re-ported mechanically: see IOATIR500Surface_prune_buffers_Port.cpp) */

