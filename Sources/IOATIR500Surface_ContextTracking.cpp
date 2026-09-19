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
void IOATIR500Surface::reset_access() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 prevTag = U32At(self, 0xc00);

    typedef void (*Fn0x604)(void *);
    (*reinterpret_cast<Fn0x604 *>(*reinterpret_cast<void ***>(self) + (0x604 / 4)))(self);

    if (prevTag == U32At(self, 0xc00)) {
        return;
    }

    typedef void (*ReleaseFn)(void *);
    void *oldA = *reinterpret_cast<void **>(self + 0xd84);
    if (oldA != nullptr) {
        (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(oldA) + (0x18 / 4)))(oldA);
    }
    void *oldB = *reinterpret_cast<void **>(self + 0xd88);
    if (oldB != nullptr) {
        (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(oldB) + (0x18 / 4)))(oldB);
    }
    U32At(self, 0xc0c) = 0;
    U32At(self, 0xc10) = 0;

    typedef void *(*Fn0x150)(void *, UInt32);
    void *accel = *reinterpret_cast<void **>(self + 0xc00);
    void *descB = (*reinterpret_cast<Fn0x150 *>(*reinterpret_cast<void ***>(accel) + (0x150 / 4)))(accel, 1);
    *reinterpret_cast<void **>(self + 0xd88) = descB;
    if (descB != nullptr) {
        typedef UInt32 (*Fn0xd0)(void *);
        U32At(self, 0xc10) = (*reinterpret_cast<Fn0xd0 *>(*reinterpret_cast<void ***>(descB) + (0xd0 / 4)))(descB);
    }

    if (U8At(self, 0xbf4) != 0) {
        typedef void *(*Fn0x14c)(void *, UInt32, UInt32, UInt32, UInt32, UInt32);
        accel = *reinterpret_cast<void **>(self + 0xc00);
        void *descA = (*reinterpret_cast<Fn0x14c *>(*reinterpret_cast<void ***>(accel) + (0x14c / 4)))(
            accel, U32At(self, 0x78), 0, 1, 0, 0);
        *reinterpret_cast<void **>(self + 0xd84) = descA;
        if (descA != nullptr) {
            typedef UInt32 (*Fn0xd0)(void *);
            U32At(self, 0xc0c) = (*reinterpret_cast<Fn0xd0 *>(*reinterpret_cast<void ***>(descA) + (0xd0 / 4)))(descA);
        }
    }
}

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
void IOATIR500Surface::reset_req_bits() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 bits = U32At(self, 0xc1c) & 0x30000020;
    U32At(self, 0xc1c) = bits;
    U32At(self, 0xc18) = bits;
    for (void *node = *reinterpret_cast<void **>(self + 0x88); node != nullptr; node = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(node) + 0x84)) {
        bits |= U32At(node, 0x8c);
        U32At(self, 0xc18) = bits;
    }
    for (void *node = *reinterpret_cast<void **>(self + 0x8c); node != nullptr; node = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(node) + 0x84)) {
        bits |= U32At(node, 0x8c);
        U32At(self, 0xc18) = bits;
    }
    for (void *node = *reinterpret_cast<void **>(self + 0xbcc); node != nullptr; node = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(node) + 0x54)) {
        if (U32At(node, 0x58) == 0x11) {
            if ((U32At(self, 0xbf8) & 2) == 0 || U32At(self, 0x144) != 0) {
                U32At(self, 0xc18) |= 2;
            } else if ((U32At(self, 0xbf8) & 1) == 0 || U32At(self, 0xcc) != 0) {
                U32At(self, 0xc18) |= 1;
            }
        } else {
            UInt32 mask[8] = {};
            surface_buffer_idx_mask(U32At(node, 0x58), mask);
            U32At(self, 0xc18) |= mask[0];
        }
    }
    if (U32At(self, 0x90) != 0) {
        U32At(self, 0xc18) |= U32At(*reinterpret_cast<void **>(self + 0x90), 0x88);
    }
}

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
void IOATIR500Surface::prune_buffers() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 reqBits;
    UInt32 persistBits = 0;

    if ((U32At(self, 0xbe8) & 0x20) == 0) {
        reqBits = U32At(self, 0xc18);
        if ((reqBits & 2) == 0) {
            *reinterpret_cast<UInt8 **>(self + 0xb84) = self + 0x300;
            *reinterpret_cast<UInt8 **>(self + 0xb80) = self + 0x300;
            UInt8 *rec = *reinterpret_cast<UInt8 **>(self + 0xd50) + U32At(self, 0xc14) * 0x78 + 300;
            *reinterpret_cast<UInt8 **>(self + 0xb70) = rec;
            *reinterpret_cast<UInt8 **>(self + 0xb74) = rec;
        } else if (U32At(self, 0xb74) == U32At(self, 0xb70)) {
            *reinterpret_cast<UInt8 **>(self + 0xb74) = self + 0x120;
            *reinterpret_cast<UInt8 **>(self + 0xb80) = self + 0x288;
        }
        goto sweep;
    }

    reqBits = U32At(self, 0xc18);
    if ((reqBits & 1) == 0) {
        if ((reqBits & 2) == 0) {
            persistBits = U32At(self, 0xbf8);
            if ((persistBits & 2) != 0) {
                U32At(self, 0xc1c) |= 1;
                goto merge;
            }
        } else {
            persistBits = U32At(self, 0xbf8);
        }
        U32At(self, 0xc1c) |= 2;
    } else {
        persistBits = U32At(self, 0xbf8);
        U32At(self, 0xc1c) |= 1;
    }
merge:
    reqBits |= U32At(self, 0xc1c);
    U32At(self, 0xc18) = reqBits;
    *reinterpret_cast<UInt8 **>(self + 0xb70) = self + ((reqBits & 1) == 0 ? 0x120 : 0xa8);
    *reinterpret_cast<UInt8 **>(self + 0xb74) = self + ((reqBits & 2) == 0 ? 0xa8 : 0x120);
    if ((U32At(self, 0xbe8) & 0x10) != 0) {
        *reinterpret_cast<UInt8 **>(self + 0xb84) = self + ((reqBits & 0x20) == 0 ? 0x288 : 0x300);
        *reinterpret_cast<UInt8 **>(self + 0xb80) = self + ((reqBits & 0x10) == 0 ? 0x300 : 0x288);
    }
    U32At(self, 0xbf8) = persistBits | 0x10000000;

sweep:
    UInt32 slotIdx = 0;
    UInt8 *rec = self;
    for (;;) {
        if (((1u << (slotIdx & 0x3f)) & reqBits) == 0) {
            dealloc_surface(slotIdx);
            if (U32At(rec, 0xcc) != 0) {
                free_buffer_backing_store(reinterpret_cast<ATIR500SurfaceBuffer *>(self + slotIdx * 0x78 + 0xa8));
            }
            if (U32At(rec, 0xb8) != 0) {
                U16At(rec, 0xbc) = 0;
                U16At(rec, 0xbe) = 0;
                U16At(rec, 0xc0) = 0;
                U16At(rec, 0xc4) = 0;
                U8At(rec, 0xe4) = 0;
                U8At(rec, 0xdc) = 0;
                U8At(rec, 0xdd) = 0;
                U8At(rec, 0xde) = 0;
                U8At(rec, 0xe0) = 0;
                U8At(rec, 0xe1) = 0;
                U8At(rec, 0xdf) = 0xff;
                U16At(rec, 0xc6) = 0;
                U16At(rec, 0xc8) = 1;
                U16At(rec, 0xca) = 1;
                U32At(rec, 0xa8) = 0;
                U32At(rec, 0xac) = 0;
                U32At(rec, 0xb0) = 0;
                U32At(rec, 0xb4) = 0;
                U32At(rec, 0xb8) = 0;
                U32At(rec, 0xcc) = 0;
                U32At(rec, 0xd0) = 0xffffffff;
                U32At(rec, 0xd4) = 0;
                U32At(rec, 0xd8) = 0;
                U8At(rec, 0xe3) = 6;
                U32At(self + slotIdx * 0x78, 0xe4) = (U32At(self + slotIdx * 0x78, 0xe4) & 0xff0007ff) | 0x111000;
                U32At(rec, 0xec) = 0;
                U32At(rec, 0xe8) = 0;
            }
        }
        bool atEnd = (slotIdx == 0x16);
        rec += 0x78;
        slotIdx += 1;
        if (atEnd) break;
        reqBits = U32At(self, 0xc18);
    }

    shape_surface();

    UInt8 *accel;
    if (U16At(self, 0xc14) == 0xffff) {
        accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
    } else {
        accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
        if (reinterpret_cast<UInt8 *>(this) == *reinterpret_cast<UInt8 **>(accel + U16At(self, 0xc14) * 0x20 + 0xe8)) {
            typedef void (*Fn0x5a4)(void *);
            (*reinterpret_cast<Fn0x5a4 *>(*reinterpret_cast<void ***>(self) + (0x5a4 / 4)))(self);
            accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
        }
    }
    U32At(accel, 0x78) = 0;
}
