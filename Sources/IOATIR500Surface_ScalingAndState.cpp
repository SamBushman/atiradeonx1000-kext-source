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
IOReturn IOATIR500Surface::set_scaling(UInt32 flags, IOAccelSurfaceScaling *scaling) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    bool scalingDisabled = ((flags >> 1) & 1) == 0;
    if (!scalingDisabled && scaling == nullptr) {
        return 0xe00002c2;
    }

    UInt8 *scale = reinterpret_cast<UInt8 *>(scaling);
    U8At(self, 0xbee) = static_cast<UInt8>(flags & 1);
    U8At(self, 0xbf1) = static_cast<UInt8>(flags & 0xf0);
    U8At(self, 0xbed) = static_cast<UInt8>(static_cast<SInt32>((U32At(self, 0xbec) & 0xffff00) * -1) >> 0x1f);

    if (scalingDisabled) {
        U8At(self, 0xbec) = 0;
        void *geom = *reinterpret_cast<void **>(self + 0xd60);
        UInt16 w = U16At(geom, 8);
        UInt16 h = U16At(geom, 10);
        U16At(self, 0xbd4) = w;
        U16At(self, 0xbdc) = 0;
        U16At(self, 0xbde) = 0;
        U16At(self, 0xbe0) = w;
        U16At(self, 0xbe2) = h;
        U16At(self, 0xbd6) = h;
    } else if ((U32At(self, 0xbe8) & 0x20) != 0) {
        U8At(self, 0xbec) = 1;
        U16At(self, 0xbd4) = U16At(scale, 4);
        U16At(self, 0xbd6) = U16At(scale, 6);
        U16At(self, 0xbdc) = U16At(scale, 0);
        U16At(self, 0xbde) = U16At(scale, 2);
        U16At(self, 0xbe0) = U16At(scale, 8);
        U16At(self, 0xbe2) = U16At(scale, 10);
    }
    U16At(self, 0xbda) = U16At(self, 0xbd6);
    U16At(self, 0xbd8) = U16At(self, 0xbd4);

    shape_surface();
    update_contexts();
    U32At(self, 0xbf8) &= 0xdfffffff;

    SInt32 sizeOk = is_surface_size_supported(S16At(self, 0xbd4), S16At(self, 0xbd6));
    if (sizeOk != 0) {
        UInt32 record[4] = {};
        typedef SInt32 (*Fn0x540)(void *, UInt32 *, UInt32, UInt32);
        typedef void (*Fn0x544)(void *, UInt32 *);
        void *accel = *reinterpret_cast<void **>(self + 0xd50);
        SInt32 resolved = (*reinterpret_cast<Fn0x540 *>(*reinterpret_cast<void ***>(accel) + (0x540 / 4)))(
            accel, record, U32At(*reinterpret_cast<void **>(self + 0xb70), 0x10), 0x1000);
        if (resolved != 0) {
            (*reinterpret_cast<Fn0x544 *>(*reinterpret_cast<void ***>(accel) + (0x544 / 4)))(accel, record);
            return 0;
        }
    }
    U32At(self, 0xbf8) |= 0x20000000;
    return 0xe00002be;
}

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

void IOATIR500Surface::set_volatile_state(eSurfaceVolatileState stateE) {
    UInt32 state = static_cast<UInt32>(stateE);
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
    GLSurface_mutex_lock(*reinterpret_cast<void **>(accel + 0x840));

    U32At(self, 0xd48) = state;
    if (state == 1) {
        accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
        if (reinterpret_cast<UInt8 *>(this) != *reinterpret_cast<UInt8 **>(accel + 0x5c)) {
            UInt8 *prev = *reinterpret_cast<UInt8 **>(self + 0x9c);
            UInt8 *next = *reinterpret_cast<UInt8 **>(self + 0xa0);
            U32At(prev, 0xa0) = reinterpret_cast<UInt32>(next);
            U32At(next, 0x9c) = reinterpret_cast<UInt32>(prev);
            UInt8 *headOld = *reinterpret_cast<UInt8 **>(accel + 0x5c);
            UInt8 *headNext = *reinterpret_cast<UInt8 **>(headOld + 0xa0);
            *reinterpret_cast<UInt8 **>(self + 0x9c) = headOld;
            *reinterpret_cast<UInt8 **>(self + 0xa0) = headNext;
            U32At(headNext, 0x9c) = reinterpret_cast<UInt32>(self);
            U32At(headOld, 0xa0) = reinterpret_cast<UInt32>(self);
            *reinterpret_cast<UInt8 **>(accel + 0x5c) = self;
            accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
        }
        U32At(accel, 0x21c) += 1;
    } else {
        accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
        if (reinterpret_cast<UInt8 *>(this) != *reinterpret_cast<UInt8 **>(accel + 0x5c)) {
            UInt8 *prev = *reinterpret_cast<UInt8 **>(self + 0x9c);
            UInt8 *next = *reinterpret_cast<UInt8 **>(self + 0xa0);
            U32At(prev, 0xa0) = reinterpret_cast<UInt32>(next);
            U32At(next, 0x9c) = reinterpret_cast<UInt32>(prev);
            UInt8 *headOld = *reinterpret_cast<UInt8 **>(accel + 0x5c);
            UInt8 *headNext = *reinterpret_cast<UInt8 **>(headOld + 0xa0);
            *reinterpret_cast<UInt8 **>(self + 0x9c) = headOld;
            *reinterpret_cast<UInt8 **>(self + 0xa0) = headNext;
            U32At(headNext, 0x9c) = reinterpret_cast<UInt32>(self);
            U32At(headOld, 0xa0) = reinterpret_cast<UInt32>(self);
            *reinterpret_cast<UInt8 **>(accel + 0x5c) = self;
            U32At(*reinterpret_cast<void **>(self + 0xd50), 0x5c) = U32At(self, 0x9c);
            accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
        }
        if (U32At(accel, 0x21c) != 0) {
            U32At(accel, 0x21c) -= 1;
            accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
        }
    }
    GLSurface_mutex_unlock(*reinterpret_cast<void **>(accel + 0x840));
}

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
UInt32 IOATIR500Surface::surface_buffer_idx_mask(UInt32 attachmentType, UInt32 *outIndex) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    switch (attachmentType) {
    case 1:
    case1:
        if (*reinterpret_cast<UInt8 **>(self + 0xb70) == self + 0xa8) {
            *outIndex = 1;
            return 0;
        }
        *outIndex = 2;
        return 0;
    case 2:
        if (*reinterpret_cast<UInt8 **>(self + 0xb80) == self + 0x300) {
            *outIndex = 0x20;
            return 4;
        }
        *outIndex = 0x10;
        return 4;
    case 3:
        if (*reinterpret_cast<UInt8 **>(self + 0xb84) == self + 0x300) {
            *outIndex = 0x20;
            return 5;
        }
        *outIndex = 0x10;
        return 5;
    case 4:
        *outIndex = 0x40;
        return 6;
    case 7:
        *outIndex = 4;
        return 2;
    case 8:
        *outIndex = 8;
        return 3;
    case 10:
        *outIndex = 0x80;
        return 7;
    case 0xb:
        *outIndex = 0x100;
        return 8;
    case 0x11:
        if ((U32At(self, 0xc18) & 2) == 0) {
            if ((U32At(self, 0xc18) & 1) == 0) {
                *outIndex = 0;
                return 0;
            }
            goto case1;
        }
        break;
    default:
        break;
    }
    if (*reinterpret_cast<UInt8 **>(self + 0xb74) == self + 0xa8) {
        *outIndex = 1;
        return 1;
    }
    *outIndex = 2;
    return 1;
}
