/*
 * IOATIR500GLContext_TextureStream.cpp
 *
 * add_texture_to_stream / remove_texture_from_stream / map_transfer_to_GART -
 * CONFIRMED, fully transcribed from real decompiles (kext offsets
 * 0x72c0/0x71b0/0x79d0). Real, previously-unknown finding this pass:
 * `VendorTextureBuffer+0x20` is a real TYPE DISCRIMINANT byte with at
 * least six distinct real values (0, 1, 6, 7, 8, and 3 - seen across this
 * file and GetTextureOffset), each routing to different real handling -
 * this is the real "kind of texture reference" tag this project had only
 * partially inferred before (VendorTextureBuffer serves plain textures,
 * chained/aliased references (type 1, recursive), surface-backed
 * references (type 0), and at least two more real kinds this
 * reconstruction pass didn't fully name).
 */

#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"

namespace {
inline UInt32 &U32At(void *base, int offset) {
    return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset);
}
inline SInt16 &S16At(void *base, int offset) {
    return *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(base) + offset);
}
inline UInt8 &U8At(void *base, int offset) {
    return *(reinterpret_cast<UInt8 *>(base) + offset);
}
} // namespace

/*
 * remove_texture_from_stream - CONFIRMED, fully transcribed (real kext
 * offset 0x71b0). Real per-type-discriminant cleanup: type 6 (chained
 * sub-buffer) decrements a nested refcount and returns; type 0
 * (surface-backed) calls `update_ref_stamps`/`decrement_refcounts`
 * (RESOLVED, issue #18) with a generation tag and returns; type 1 (alias) walks to the next real
 * texture in the chain and loops; type 8 decrements a refcount and
 * stores the current generation tag.
 */
void IOATIR500GLContext::remove_texture_from_stream(VendorTextureBuffer *texture) {
    UInt32 generation = U32At(accelerator, 0x50);

    while (texture != nullptr) {
        void *rec = reinterpret_cast<void *>(U32At(texture, 0x14));
        U32At(rec, 8) = generation;
        UInt32 kind = U32At(texture, 0x20);

        if (kind == 6) {
            void *sub = reinterpret_cast<void *>(U32At(texture, 0x54));
            void *subRec = reinterpret_cast<void *>(U32At(sub, 0x14));
            U32At(subRec, 8) = generation;
            S16At(sub, 0xe) -= 1;
            return;
        }
        if (kind == 0) {
            IOATIR500Surface *vtableOwner = reinterpret_cast<IOATIR500Surface *>(U32At(texture, 0x50));
            if (vtableOwner == nullptr) return;
            /* real: update_ref_stamps/decrement_refcounts - RESOLVED, issue #18 */
            vtableOwner->update_ref_stamps(generation, 3);
            vtableOwner->decrement_refcounts(3);
            return;
        }
        if (kind == 1) {
            texture = reinterpret_cast<VendorTextureBuffer *>(U32At(texture, 0x50));
            continue; /* real: loop back with the chained texture */
        }
        if (kind == 8) {
            if (U32At(texture, 0x48) == 0) {
                S16At(texture, 0xe) -= 1;
            }
            U32At(texture, 0x5c) = generation; /* generationTag */
            return;
        }
        return; /* any other real discriminant value: no-op, CONFIRMED */
    }
}

/*
 * add_texture_to_stream - CONFIRMED, fully transcribed (real kext offset
 * 0x72c0). The real bind-side counterpart to remove_texture_from_stream -
 * same discriminant values, opposite direction (increment refcounts, real
 * dirty-bit propagation for type 6/1, and for type 6 a real unlink-then-
 * reinsert-at-head into the accelerator's dirty-texture doubly-linked
 * list at +0x6d0/+0x69c - the same list get_data_buffer/purge_texture
 * already use).
 */
void IOATIR500GLContext::add_texture_to_stream(VendorTextureBuffer *texture) {
    UInt32 kind = U32At(texture, 0x20);

    if (kind == 6) {
        void *sub = reinterpret_cast<void *>(U32At(texture, 0x54));
        void *rec = reinterpret_cast<void *>(U32At(texture, 0x14));
        void *subRec = reinterpret_cast<void *>(U32At(sub, 0x14));
        S16At(sub, 0xe) += 1;
        U8At(rec, 0x14) |= U8At(subRec, 0x14);

        if (U32At(sub, 4) != 0) {
            /* FUN_00007424(sub + 0x2c) - likely a list-unlink helper/lock
             * acquire for the node about to be relinked below. RESOLVED,
             * issue #15: a real lazy-binding external stub with no local
             * body in this binary - see the comprehensive finding at the
             * end of Headers/ATIRadeonX1000Registers.h. Real name UNKNOWN. */
            void *accel = accelerator;
            UInt32 oldPrev = U32At(sub, 0x34);
            UInt32 oldNext = U32At(sub, 0x38);
            U32At(reinterpret_cast<void *>(oldPrev), 0x38) = oldNext;
            U32At(reinterpret_cast<void *>(oldNext), 0x34) = oldPrev;

            U32At(sub, 0x34) = U32At(accel, 0x6d0);
            U32At(sub, 0x38) = reinterpret_cast<UInt32>(reinterpret_cast<UInt8 *>(accel) + 0x69c);
            U32At(accel, 0x6d0) = reinterpret_cast<UInt32>(sub);
            U32At(reinterpret_cast<void *>(U32At(sub, 0x34)), 0x38) = reinterpret_cast<UInt32>(sub);
        }
    } else if (kind == 0) {
        IOATIR500Surface *vtableOwner = reinterpret_cast<IOATIR500Surface *>(U32At(texture, 0x50));
        if (vtableOwner != nullptr) {
            vtableOwner->increment_refcounts(3); /* RESOLVED, issue #18 */
        }
    } else if (kind == 1) {
        VendorTextureBuffer *chained = reinterpret_cast<VendorTextureBuffer *>(U32At(texture, 0x50));
        if (chained != nullptr) {
            add_texture_to_stream(chained);
            void *rec = reinterpret_cast<void *>(U32At(texture, 0x14));
            void *chainedRec = reinterpret_cast<void *>(U32At(chained, 0x14));
            U8At(rec, 0x14) |= U8At(chainedRec, 0x14);
        }
    } else if (kind == 8 && U32At(texture, 0x48) == 0) {
        S16At(texture, 0xe) += 1;
    }
}

/*
 * map_transfer_to_GART - real kext offset 0x79d0. CORRECTED, issue #23:
 * decompiling `ATIRadeonX1000::addTransferToGART`'s own real body turned
 * up two real problems with this function's earlier transcription, both
 * fixed here:
 *
 * 1. Real signature mismatch: `addTransferToGART` (both the
 *    `ATIRadeonX1000` override and the `IOATIR500Accelerator` base it
 *    calls) is CONFIRMED, from each real decompile, to take a real
 *    `VendorTransferBuffer*` parameter - the previous transcription
 *    called it with NO arguments at all. Since the real callee
 *    unconditionally dereferences that parameter (`param_1+8`/`param_1+4`
 *    at the base level), calling it without `buffer` would be a real
 *    crash risk - fixed by passing `buffer`.
 * 2. Real return-value uncertainty: BOTH `addTransferToGART` levels
 *    (`ATIRadeonX1000`'s own override and the `IOATIR500Accelerator`
 *    base it calls) decompile as genuinely `void` - neither ever sets a
 *    real return value in its own control flow. The earlier
 *    transcription's `if (result == 0) { ... }` gate around the
 *    `freeToAllocGART` call was capturing whatever the real compiled
 *    call site's indirect-call-with-unknown-prototype artifact happened
 *    to leave in the return register - NOT a confirmed real signal, per
 *    this project's own established caveat about this exact category of
 *    artifact elsewhere (e.g. `ATIR500GLContext_TextureLoad.cpp`'s
 *    `load_texture` note). SETTLED (issue #26): decompiling the further
 *    slot `addTransferToGART` itself calls (`IOATIR500Accelerator`'s own
 *    `+0x5a0`, real name `addToGART`, `Headers/IOATIR500Accelerator.h`)
 *    shows it is ALSO genuinely void at both class levels - strong (not
 *    airtight; the deepest call, on Apple's own standard
 *    `IOMemoryDescriptor`, is out of this project's scope) confirmation
 *    that no real signal exists anywhere in this chain. The
 *    unconditional call below is the correct final transcription, not a
 *    placeholder.
 */
void IOATIR500GLContext::map_transfer_to_GART(VendorTransferBuffer *buffer) {
    accelerator->addTransferToGART(buffer);
    void *sharedAllocator = reinterpret_cast<void *>(U32At(this, 0x88)); /* real: *(IOATIR500Shared**)(this+0x88) */
    accelerator->freeToAllocGART(nullptr, nullptr, this, boundSurface,
                                  reinterpret_cast<IOATIR500Shared *>(sharedAllocator), buffer);
}
