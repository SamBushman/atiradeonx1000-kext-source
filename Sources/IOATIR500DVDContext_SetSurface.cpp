/*
 * IOATIR500DVDContext_SetSurface.cpp
 *
 * RESOLVED (issue #42 test-harness pass): real body for
 * `IOATIR500DVDContext::set_surface`, real addr 0xfa40. Never previously
 * decompiled - the header had guessed a 4-param signature by analogy with
 * the GL context's own set_surface, which real wire-shape evidence (VA
 * bundle disassembly, 3 real scalar inputs) contradicted. The real
 * mangled symbol (__ZN19IOATIR500DVDContext11set_surfaceEm21eIODVDContextModeBitsi)
 * and this decompile both independently confirm exactly 3 real
 * parameters: `surfaceID` (unsigned long), `modeBits` (a real Apple enum
 * `eIODVDContextModeBits`, not reconstructed by name - kept UInt32-shaped
 * per this project's standing policy for un-reconstructed Apple enum
 * types), and `flagCount` (a real `int`).
 *
 * Real body: locks the accelerator's commandLock. If `surfaceID` is 0,
 * treats this as "unbind" (no target surface, result defaults to
 * success). Otherwise looks up the real surface via the accelerator's
 * own `find_surface_for_id` (already-established real bounds-checked
 * table lookup) - a miss sets a real kIOReturnBadArgument-family result
 * but does NOT early-return (the real decompile keeps going to properly
 * unbind whatever surface was previously bound, matching this project's
 * general practice: cleanup runs regardless of whether the new binding
 * itself succeeds).
 *
 * If a DVD context was already bound to a (possibly different) surface,
 * unconditionally calls that OLD surface's real `remove_dvd_context`, and
 * - if the NEW target surface differs from the old one - also calls the
 * old surface's `prune_buffers` (real per-format buffer bookkeeping
 * refresh, already established via `set_id_mode`). Both checks below
 * (`targetSurface != oldBoundSurface`) compare against the STILL-OLD
 * value of `boundSurface` - nothing writes to it until the real success
 * path further down, matching the real decompile's own instruction
 * order exactly.
 *
 * The real "can we actually (re)bind" gate: rejects (clearing
 * `boundSurface`) if the lookup failed OR if the target surface is
 * already exclusively owned by a DIFFERENT DVD context (the target's own
 * `boundDVDContext` field, non-null and not `this` - see
 * `Headers/IOATIR500Surface.h`'s newly-named `+0x90` field). Otherwise:
 * reads the target surface's own real mode-bits field (`+0xbe8`, the SAME
 * field `set_id_mode`/`set_shape_backing_length_ext` already establish)
 * into a local, and - for a genuinely fresh/unlinked surface (its own
 * `contextListHeadA`/`contextListHeadB` both null, see the same header's
 * newly-named `+0x88`/`+0x8c` fields) - masks in the caller's `modeBits`
 * directly (`existing & 0x803f | modeBits & 0xffffbfff`, the SAME real
 * `0x803f` mask `set_id_mode`'s own top-level validation gate uses). For
 * an ALREADY-linked surface, instead calls this DVD context's own real
 * vtable `+0x5ac` method (role INFERRED: "renegotiate/validate mode bits
 * against existing context state," given it's passed the local mode-bits
 * scratch AND the caller's raw `modeBits` and its failure path unwinds
 * the binding attempt with `kIOReturnBadArgument`) - NOT independently
 * confirmed beyond that inference.
 *
 * On a successful (re)bind: writes the updated mode-bits back to the
 * target surface's own `+0xbe8`; if `flagCount > 0`, accumulates
 * `0x400 << (n & 0x3f)` into this context's OWN real `+0x88` bitmask
 * (`surfaceFlagsBitmask`, a real field this pass promoted out of what
 * had been treated as padding - see `Headers/IOATIR500DVDContext.h` -
 * NOT the same offset as the surface's own unrelated `contextListHeadA`
 * field, they live on different classes) for each of `flagCount`
 * iterations; then calls the target surface's real `set_dvd_context
 * (this)`, stores the new `boundSurface`, and refreshes it via
 * `prune_buffers`.
 *
 * Real shared tail (runs on every path via a real forward-jump target):
 * if the accelerator's own real "last-touched DVD context" slot
 * (`accelerator+0x78`) still points at `this`, clears it - a real
 * "I'm no longer the active one" self-eviction. Finally calls this DVD
 * context's own real vtable `+0x5a8` method (role INFERRED:
 * "invalidate"/notify, matching the same-named-offset convention already
 * established for GL/Surface's own `+0x5a8` slots elsewhere in this
 * project, though NOT independently confirmed to be the identical real
 * method given each class has its own real vtable) with no further
 * arguments, releases the commandLock, and returns the accumulated
 * result.
 *
 * Confidence: CONFIRMED for control flow and every real offset/mask
 * constant - a real, complete, standalone decompile. The two vtable
 * calls (+0x5ac/+0x5a8) have their real target identities UNCONFIRMED
 * beyond the role inference above, consistent with this project's
 * treatment of similar unnamed vtable slots elsewhere.
 */

#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/ATIR500DVDContext.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"

extern "C" void DVDSetSurface_mutex_lock(void *) asm("_IOLockLock");
extern "C" void DVDSetSurface_mutex_unlock(void *) asm("_IOLockUnlock");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

IOReturn IOATIR500DVDContext::set_surface(UInt32 surfaceID, eIODVDContextModeBits modeBitsEnum, int flagCount) {
    UInt32 modeBits = static_cast<UInt32>(modeBitsEnum);
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);
    DVDSetSurface_mutex_lock(*reinterpret_cast<void **>(accel + 0x840));

    IOReturn result;
    IOATIR500Surface *targetSurface;
    bool lookupFailed;

    if (surfaceID == 0) {
        result = 0;
        targetSurface = nullptr;
        lookupFailed = true;
    } else {
        targetSurface = reinterpret_cast<IOATIR500Surface *>(accelerator->find_surface_for_id(surfaceID));
        lookupFailed = (targetSurface == nullptr);
        result = lookupFailed ? 0xe00002c2 : 0;
    }

    IOATIR500Surface *oldBoundSurface = reinterpret_cast<IOATIR500Surface *>(boundSurface);
    if (oldBoundSurface != nullptr) {
        oldBoundSurface->remove_dvd_context(this);
        if (targetSurface != oldBoundSurface) {
            oldBoundSurface->prune_buffers();
        }
    }

    if (lookupFailed ||
        (targetSurface->boundDVDContext != nullptr && this != targetSurface->boundDVDContext)) {
        boundSurface = nullptr;
    } else {
        UInt32 localModeBits = U32At(targetSurface, 0xbe8);
        if (targetSurface != oldBoundSurface) {
            targetSurface->reset_req_bits();
        }
        if (targetSurface->contextListHeadA == nullptr && targetSurface->contextListHeadB == nullptr) {
            localModeBits = (localModeBits & 0x803f) | (modeBits & 0xffffbfff);
        } else {
            typedef SInt32 (*Fn0x5ac)(void *, UInt32 *, UInt32);
            void **selfVtable = *reinterpret_cast<void ***>(self);
            SInt32 renegotiated = (*reinterpret_cast<Fn0x5ac *>(selfVtable + (0x5ac / 4)))(this, &localModeBits, modeBits);
            if (renegotiated == 0) {
                if (targetSurface == oldBoundSurface) {
                    targetSurface->prune_buffers();
                }
                boundSurface = nullptr;
                result = 0xe00002c2;
                goto sharedTail;
            }
        }
        U32At(targetSurface, 0xbe8) = localModeBits;
        if (flagCount > 0) {
            UInt32 bits = U32At(self, 0x88);
            UInt32 n = 0;
            do {
                bits |= 0x400u << (n & 0x3f);
                n++;
                flagCount--;
            } while (flagCount != 0);
            U32At(self, 0x88) = bits;
        }
        targetSurface->set_dvd_context(this);
        boundSurface = reinterpret_cast<ATIR500Surface *>(targetSurface);
        targetSurface->prune_buffers();
    }

sharedTail:
    if (this == *reinterpret_cast<IOATIR500DVDContext **>(accel + 0x78)) {
        *reinterpret_cast<IOATIR500DVDContext **>(accel + 0x78) = nullptr;
    }
    typedef void (*Fn0x5a8)(void *);
    void **selfVtable2 = *reinterpret_cast<void ***>(self);
    (*reinterpret_cast<Fn0x5a8 *>(selfVtable2 + (0x5a8 / 4)))(this);

    DVDSetSurface_mutex_unlock(*reinterpret_cast<void **>(accel + 0x840));
    return result;
}

/*
 * set_dvd_context / remove_dvd_context - RESOLVED (issue #42
 * test-harness pass), real addrs 0x10bc0 / 0x13de0 - the two small real
 * helpers `IOATIR500DVDContext::set_surface` above calls, decompiled
 * immediately after this project's own new declarations of them (in
 * `Headers/IOATIR500Surface.h`) would otherwise have left the project
 * with two new undefined symbols - real, complete, standalone decompiles,
 * not stubs.
 *
 * set_dvd_context: stores the new `boundDVDContext`, then folds the DVD
 * context's own `surfaceFlagsBitmask` (`+0x88` on `IOATIR500DVDContext`,
 * the same real field `set_surface`'s own flag-accumulation loop writes)
 * into this surface's own real requirement-bits field (`+0xc18`, the SAME
 * field `reset_req_bits`/`prune_buffers` already establish) - confirming
 * `surfaceFlagsBitmask` really does feed into the surface's own real
 * buffer-selection logic, not just sit inert on the DVD context.
 *
 * remove_dvd_context: clears `boundDVDContext` only if it still points at
 * the caller (a real "only remove if I'm still the owner" guard), then
 * unconditionally calls `reset_req_bits()` regardless of whether the
 * clear happened.
 *
 * Confidence: CONFIRMED - real, complete decompiles, no ambiguity.
 */
void IOATIR500Surface::set_dvd_context(IOATIR500DVDContext *context) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    boundDVDContext = context;
    U32At(self, 0xc18) |= U32At(context, 0x88);
}

void IOATIR500Surface::remove_dvd_context(IOATIR500DVDContext *context) {
    if (boundDVDContext == context) {
        boundDVDContext = nullptr;
    }
    reset_req_bits();
}
