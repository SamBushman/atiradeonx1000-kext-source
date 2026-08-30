/*
 * ATIR500GLContext_TextureLoad.cpp
 *
 * PARTIALLY RESOLVED (issue #5): get_texture, alloc_and_load_texture,
 * and compact_current_textures - three of the four remaining declared-
 * but-bodyless internal helpers - fully decompiled and transcribed this
 * pass (real kext offsets 0x2b5f0, 0x2a3d0, 0x29dd0 respectively).
 * load_texture (0x29480) was read but deliberately deferred - see
 * Headers/ATIR500GLContext.h's declaration and GAPS.md.
 *
 * Confidence: CONFIRMED for control flow and every field offset/call
 * touched - transcribed directly from complete real decompiles, not
 * summarized. Several sub-calls reached through raw vtable-offset casts
 * (accelerator vtable +0x524/+0x528, IOATIR500Surface vtable +0x5c4/
 * +0x5cc/+0x5d0) have real, confirmed-to-exist targets but UNKNOWN real
 * names - called opaquely per this project's no-shortcuts standard,
 * same as elsewhere. get_texture's atomic decrement loop was verified
 * against raw PPC disassembly (lwarx/stwcx.), not just Ghidra's
 * decompile, since the decompiler couldn't fully resolve it into clean
 * C on its own.
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"

/*
 * get_texture - CONFIRMED, fully transcribed (real kext offset 0x2b5f0).
 * Real, previously-guessed-at behavior now confirmed: on a real "needs
 * reload" flag (texture's mip record + 0x14, a byte), submits a real
 * backward-indexed PM4 header + `record` payload via
 * ATIRadeonX1000::submit_buffer, then calls alloc_and_load_texture and,
 * if the accelerator is mid-pageoff (accel+0xb90 != 0), calls
 * restore_state_destroyed_by_pageoff. Otherwise (or after), if
 * this+0xd0 is still unset, calls map_transfer_to_GART.
 *
 * Real, notable finding: an ATOMIC decrement-by-0xffff (PPC lwarx/
 * stwcx. retry loop, not a plain load-modify-store - Ghidra's own
 * decompile couldn't resolve this into clean C, represented via
 * pseudo-registers instead) on a 32-bit word at the mip record's own
 * +0x10 field, unconditional (runs whether or not the reload branch
 * above ran). -0xffff = -0x10000+1, i.e. this simultaneously decrements
 * a count packed in the high 16 bits and increments one in the low 16
 * bits - real evidence of a packed dual-counter field, exact meaning of
 * either half UNKNOWN.
 *
 * Finally, if the texture has a nonzero value at +0x48, splices it out
 * of whatever real doubly-linked list it's currently on and re-inserts
 * it at the head of a real list embedded in the accelerator object
 * (head pointer at accelerator+0x600, an embedded sentinel node at
 * accelerator+0x5dc) - a real, previously-undocumented accelerator-
 * level structure (plausibly the orphan-texture list
 * IOATIR500Accelerator::addOrphanTexture already references
 * conceptually; not confirmed to be the same list this pass).
 */
void ATIR500GLContext::get_texture(UInt32 *record, VendorTextureBuffer *texture, UInt32 *pLocal388,
                                    UInt32 *pLocal384, UInt32 *pLocal380, register_tracking_state *scratch) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *tex = reinterpret_cast<UInt8 *>(texture);
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);

    UInt8 *mip = *reinterpret_cast<UInt8 **>(tex + 0x14);
    if (*reinterpret_cast<char *>(mip + 0x14) != 0) {
        if (*pLocal384 != 0) {
            UInt32 backDistance = record[-1] >> 2;
            if (backDistance > 4) {
                UInt32 exitDescriptor = 0x80000000u;
                if (backDistance != 5) {
                    exitDescriptor = (backDistance - 6) * 0x10000u | 0xc0001000u;
                }
                record[-static_cast<SInt32>(backDistance)] = exitDescriptor;
            }
            record[-4] = 0x1393;
            record[-3] = 0;
            record[-2] = 0x5c8;
            record[-1] = 0x20000;

            *reinterpret_cast<UInt32 *>(accel + 0x704) += *pLocal384 * 4;
            *reinterpret_cast<UInt32 *>(accel + 0xb94) = 1;

            *reinterpret_cast<UInt32 *>(self + 0xdc) = accelerator->submit_buffer(
                reinterpret_cast<UInt32 *>((*pLocal380 & 0xfffffffcu) +
                                            *reinterpret_cast<UInt32 *>(self + 0xe0) + 0x20),
                *pLocal380 + *reinterpret_cast<UInt32 *>(self + 0xd0) + 0x20,
                *pLocal384);

            *pLocal380 = *pLocal384 * 4 + *pLocal380;
            *pLocal384 = 0;
            *pLocal388 = 0;
        }

        alloc_and_load_texture(texture);

        if (*reinterpret_cast<UInt32 *>(accel + 0xb90) != 0) {
            *reinterpret_cast<UInt32 **>(reinterpret_cast<UInt8 *>(scratch) + 0x140) = record;
            restore_state_destroyed_by_pageoff(scratch);
        }
        if (*reinterpret_cast<UInt32 *>(self + 0xd0) == 0) {
            map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(self + 0xcc));
        }
        mip = *reinterpret_cast<UInt8 **>(tex + 0x14); /* real: reloaded fresh either way */
    }

    /*
     * Real atomic add of -0xffff (i.e. -0x10000+1: decrement a count
     * packed in the high 16 bits, increment one in the low 16 bits) on
     * mip+0x10 - a real PPC lwarx/add/stwcx.-with-retry sequence
     * (0x2b768-0x2b77c in the raw disassembly), expressed here via the
     * equivalent GCC/Clang atomic-fetch-add builtin rather than hand-
     * unrolling the retry loop.
     */
    __sync_fetch_and_add(reinterpret_cast<SInt32 *>(mip + 0x10), static_cast<SInt32>(-0xffff));

    if (*reinterpret_cast<UInt32 *>(tex + 0x48) != 0) {
        UInt8 *prevNode = *reinterpret_cast<UInt8 **>(tex + 0x24);
        UInt8 *nextNode = *reinterpret_cast<UInt8 **>(tex + 0x28);
        *reinterpret_cast<UInt32 *>(prevNode + 0x28) = reinterpret_cast<UInt32>(nextNode);
        *reinterpret_cast<UInt32 *>(nextNode + 0x24) = reinterpret_cast<UInt32>(prevNode);

        *reinterpret_cast<UInt32 *>(tex + 0x24) = *reinterpret_cast<UInt32 *>(accel + 0x600);
        *reinterpret_cast<UInt32 *>(tex + 0x28) = reinterpret_cast<UInt32>(accel + 0x5dc);
        *reinterpret_cast<VendorTextureBuffer **>(accel + 0x600) = texture;
        UInt8 *newPrev = *reinterpret_cast<UInt8 **>(tex + 0x24);
        *reinterpret_cast<UInt32 *>(newPrev + 0x28) = reinterpret_cast<UInt32>(texture);
    }
}

/*
 * A small real helper this function's four near-identical branches all
 * call before splicing a buffer into the accelerator's transfer-buffer
 * list (accelerator+0x6d0 head / +0x69c sentinel - the SAME real
 * circular-doubly-linked-list shape get_texture uses on the texture
 * list at +0x600/+0x5dc, just a different instance for transfer
 * buffers). Real address 0x2a864; not independently decompiled this
 * pass - called opaquely, like the raw vtable calls elsewhere in this
 * function.
 */
extern void FUN_0002a864(void *transferBuffer);

/*
 * Two more real, confirmed-to-exist accelerator vtable calls
 * alloc_and_load_texture makes - real names UNKNOWN, called through raw
 * vtable-offset casts rather than invented named methods, matching this
 * project's no-shortcuts standard elsewhere (e.g.
 * Sources/ATIR500GLContext_ProcessCommandBuffer.cpp).
 */
static inline int callAcceleratorVtable0x528(void *accelObj, void *texture) {
    typedef int (*Fn)(void *, void *);
    return (*reinterpret_cast<Fn *>(*reinterpret_cast<void ***>(accelObj) + (0x528 / 4)))(accelObj, texture);
}
static inline void callAcceleratorVtable0x524(void *accelObj) {
    typedef void (*Fn)(void *);
    (*reinterpret_cast<Fn *>(*reinterpret_cast<void ***>(accelObj) + (0x524 / 4)))(accelObj);
}

/*
 * alloc_and_load_texture - RESOLVED (issue #5), fully transcribed (real
 * kext offset 0x2a3d0). REAL RETURN TYPE CORRECTED to `void` (was
 * declared `IOReturn`) - see ATIR500GLContext.h.
 *
 * An 8-way dispatch on the texture's own type-discriminant byte
 * (`texture+0x20` - the same real discriminant
 * Sources/IOATIR500GLContext_TextureStream.cpp's header already
 * documents at least six values for; this function is real evidence
 * for values 0/1/2/3/6/7/8 specifically). Real per-type behavior:
 *   - 0 (surface-backed): resolves/caches the real IOATIR500Surface via
 *     find_surface_for_id if not already cached, checks two real bitmask
 *     gates, and on a real mask hit calls IOATIR500Surface::
 *     alloc_surfaces_keep then compact_current_textures.
 *   - 1 (chained/aliased reference): real, direct RECURSION - calls
 *     itself on the real linked texture at +0x50 (confirms this
 *     project's earlier characterization of type 1 as "recursive").
 *   - 2, 6, 8: near-identical real "ensure GART-mapped, then splice
 *     into the accelerator's transfer-buffer list" bodies (via the real
 *     but unresolved FUN_0002a864 helper above).
 *   - 3, 7: real "free VRAM for this texture, then compact" paths -
 *     type 7 additionally handles a real "already pending eviction" bit
 *     (texture's mip-record byte, bit 1) before retrying.
 *   - default: no-op.
 * Falls through to `load_texture` (this issue's other resolved
 * function) whenever the type-specific path doesn't return early.
 */
void ATIR500GLContext::alloc_and_load_texture(VendorTextureBuffer *texture) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *tex = reinterpret_cast<UInt8 *>(texture);
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);
    UInt32 discriminant = *reinterpret_cast<UInt32 *>(tex + 0x20);

    auto spliceIntoTransferList = [&](UInt8 *node) {
        FUN_0002a864(node + 0x2c);
        UInt8 *prevNode = *reinterpret_cast<UInt8 **>(node + 0x34);
        UInt8 *nextNode = *reinterpret_cast<UInt8 **>(node + 0x38);
        *reinterpret_cast<UInt32 *>(prevNode + 0x38) = reinterpret_cast<UInt32>(nextNode);
        *reinterpret_cast<UInt32 *>(nextNode + 0x34) = reinterpret_cast<UInt32>(prevNode);
        *reinterpret_cast<UInt32 *>(node + 0x34) = *reinterpret_cast<UInt32 *>(accel + 0x6d0);
        *reinterpret_cast<UInt32 *>(node + 0x38) = reinterpret_cast<UInt32>(accel + 0x69c);
        *reinterpret_cast<UInt32 *>(accel + 0x6d0) = reinterpret_cast<UInt32>(node);
        UInt8 *newPrev = *reinterpret_cast<UInt8 **>(node + 0x34);
        *reinterpret_cast<UInt32 *>(newPrev + 0x38) = reinterpret_cast<UInt32>(node);
    };

    if (discriminant == 3) {
        if (*reinterpret_cast<UInt32 *>(tex + 0x48) == 0 &&
            callAcceleratorVtable0x528(accel, tex) == 0 &&
            accelerator->freeToAllocTextureVRAM(
                *reinterpret_cast<IOATIR500Surface **>(self + 0x290),
                reinterpret_cast<VendorTextureBuffer **>(self + 0x2a4), 0x2a, texture) == 0 &&
            compact_current_textures(texture) == 0) {
            return;
        }
        load_texture(texture);
        *reinterpret_cast<UInt8 *>(*reinterpret_cast<UInt32 *>(tex + 0x14) + 0x14) = 0;
        return;
    }

    if (discriminant == 2) {
        if (*reinterpret_cast<UInt32 *>(tex + 4) != 0) {
            spliceIntoTransferList(tex);
        } else {
            map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(texture));
            if (*reinterpret_cast<UInt32 *>(tex + 4) != 0) spliceIntoTransferList(tex);
        }
        *reinterpret_cast<UInt8 *>(*reinterpret_cast<UInt32 *>(tex + 0x14) + 0x14) = 0;
        return;
    }

    if (discriminant == 6) {
        UInt8 *inner = *reinterpret_cast<UInt8 **>(tex + 0x54);
        if (*reinterpret_cast<UInt32 *>(inner + 4) != 0) {
            spliceIntoTransferList(inner);
        } else {
            map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(inner));
            if (*reinterpret_cast<UInt32 *>(inner + 4) != 0) spliceIntoTransferList(inner);
        }
        *reinterpret_cast<UInt8 *>(*reinterpret_cast<UInt32 *>(tex + 0x14) + 0x14) = 0;
        *reinterpret_cast<UInt8 *>(*reinterpret_cast<UInt32 *>(inner + 0x14) + 0x14) = 0;
        return;
    }

    if (discriminant == 7) {
        bool retry = true;
        if (*reinterpret_cast<UInt32 *>(tex + 0x48) != 0) {
            if ((*reinterpret_cast<UInt8 *>(*reinterpret_cast<UInt32 *>(tex + 0x14) + 0x14) & 2) != 0) {
                callAcceleratorVtable0x524(accel);
                UInt8 *mip = *reinterpret_cast<UInt8 **>(tex + 0x14);
                mip[0x14] = 1;
                *reinterpret_cast<UInt16 *>(mip + 0x28) = 0;
                *reinterpret_cast<UInt16 *>(mip + 0x2a) = 0;
                *reinterpret_cast<UInt16 *>(mip + 0x2c) = 0;
                *reinterpret_cast<UInt16 *>(mip + 0x2e) = 0;
                *reinterpret_cast<UInt16 *>(mip + 0x30) = 0;
                *reinterpret_cast<UInt16 *>(mip + 0x32) = 0;
                *reinterpret_cast<UInt32 *>(tex + 0x50) = *reinterpret_cast<UInt32 *>(mip + 0x18);
                retry = (*reinterpret_cast<UInt32 *>(tex + 0x48) == 0);
            } else {
                retry = false;
            }
        }
        if (retry) {
            if (callAcceleratorVtable0x528(accel, tex) == 0 &&
                accelerator->freeToAllocTextureVRAM(
                    *reinterpret_cast<IOATIR500Surface **>(self + 0x290),
                    reinterpret_cast<VendorTextureBuffer **>(self + 0x2a4), 0x2a, texture) == 0 &&
                compact_current_textures(texture) == 0) {
                UInt8 *prevNode = *reinterpret_cast<UInt8 **>(tex + 0x24);
                UInt8 *nextNode = *reinterpret_cast<UInt8 **>(tex + 0x28);
                *reinterpret_cast<UInt32 *>(prevNode + 0x28) = reinterpret_cast<UInt32>(nextNode);
                *reinterpret_cast<UInt32 *>(tex + 0x28) = reinterpret_cast<UInt32>(texture);
                *reinterpret_cast<UInt32 *>(nextNode + 0x24) = reinterpret_cast<UInt32>(texture);
                *reinterpret_cast<UInt32 *>(tex + 0x24) = reinterpret_cast<UInt32>(texture);
                return;
            }
        }
        load_texture(texture);
        *reinterpret_cast<UInt8 *>(*reinterpret_cast<UInt32 *>(tex + 0x14) + 0x14) = 0;
        return;
    }

    if (discriminant == 0) {
        IOATIR500Surface *surface = *reinterpret_cast<IOATIR500Surface **>(tex + 0x50);
        if (surface == nullptr) {
            surface = reinterpret_cast<IOATIR500Surface *>(
                accelerator->find_surface_for_id(*reinterpret_cast<UInt32 *>(tex + 0x5c)));
            *reinterpret_cast<IOATIR500Surface **>(tex + 0x50) = surface;
            if (surface == nullptr) return;
            UInt8 *surf = reinterpret_cast<UInt8 *>(surface);
            *reinterpret_cast<UInt32 *>(tex + 0x54) = *reinterpret_cast<UInt32 *>(surf + 0xbcc);
            *reinterpret_cast<UInt32 *>(surf + 0xbcc) = reinterpret_cast<UInt32>(texture);
        }
        UInt8 *surf = reinterpret_cast<UInt8 *>(surface);
        if ((*reinterpret_cast<UInt32 *>(surf + 0xbf8) & 0x20000000u) != 0) return;

        UInt32 mask[6] = {};
        surface->surface_buffer_idx_mask(*reinterpret_cast<UInt32 *>(tex + 0x58), mask);
        *reinterpret_cast<UInt8 *>(*reinterpret_cast<UInt32 *>(tex + 0x14) + 0x14) = 0;
        if ((mask[0] & *reinterpret_cast<UInt32 *>(surf + 0xc18) & *reinterpret_cast<UInt32 *>(surf + 0xbf8)) == 0) {
            return;
        }
        UInt32 ok = surface->alloc_surfaces_keep(
            *reinterpret_cast<IOATIR500Surface **>(self + 0x290),
            reinterpret_cast<VendorTextureBuffer **>(self + 0x2a4), 0x2a, mask[0]);
        bool compacted = false;
        if (ok != 0) {
            compacted = (compact_current_textures(texture) == 0);
        }
        UInt8 *mipFlag = reinterpret_cast<UInt8 *>(*reinterpret_cast<UInt32 *>(tex + 0x14) + 0x14);
        *mipFlag = (1 - static_cast<UInt8>(!compacted)) | *mipFlag;
        return;
    }

    if (discriminant == 1) {
        VendorTextureBuffer *chained = *reinterpret_cast<VendorTextureBuffer **>(tex + 0x50);
        if (chained == nullptr) return;
        alloc_and_load_texture(chained); /* real, direct recursion */
        return;
    }

    if (discriminant == 8) {
        bool needSplice;
        if (*reinterpret_cast<UInt32 *>(tex + 0x48) == 0 && *reinterpret_cast<UInt32 *>(tex + 8) != 0) {
            if (*reinterpret_cast<UInt32 *>(tex + 4) != 0) {
                needSplice = true;
            } else {
                map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(texture));
                needSplice = (*reinterpret_cast<UInt32 *>(tex + 4) != 0);
            }
        } else {
            needSplice = (*reinterpret_cast<UInt32 *>(tex + 4) != 0);
        }
        if (needSplice) spliceIntoTransferList(tex);
        return;
    }

    /* default: real no-op for any other discriminant value */
}

/*
 * Three more real IOATIR500Surface vtable calls compact_current_textures
 * makes - real names UNKNOWN, called through raw vtable-offset casts.
 */
static inline void callSurfaceVtable0x5cc(void *surfaceObj, UInt32 arg) {
    typedef void (*Fn)(void *, UInt32);
    (*reinterpret_cast<Fn *>(*reinterpret_cast<void ***>(surfaceObj) + (0x5cc / 4)))(surfaceObj, arg);
}
static inline void callSurfaceVtable0x5c4(void *surfaceObj) {
    typedef void (*Fn)(void *);
    (*reinterpret_cast<Fn *>(*reinterpret_cast<void ***>(surfaceObj) + (0x5c4 / 4)))(surfaceObj);
}
static inline UInt32 callSurfaceVtable0x5d0(void *surfaceObj, void *surfaceBuffer) {
    typedef UInt32 (*Fn)(void *, void *);
    return (*reinterpret_cast<Fn *>(*reinterpret_cast<void ***>(surfaceObj) + (0x5d0 / 4)))(surfaceObj, surfaceBuffer);
}

/*
 * A real, shared eviction-scan sub-routine compact_current_textures
 * inlines twice for two different surfaces (once per already-bound slot
 * being evicted, once for the newly-requested texture's own surface).
 * Real body: walks a real 0x17-entry (23) `ATIR500SurfaceBuffer`-sized
 * (0x78 stride) array at `surface+0xa8`, and for each entry whose real
 * gating condition holds (a mix of `surface+0xc14 == 0xffff`, an index
 * range check, `entry+8 != 0`, and a `surface+0xbd0` high-word/pointer-
 * identity check), either moves it to backing store or calls the real
 * vtable+0x5cc method with a "reason" code - then, after the whole
 * scan, calls the real vtable+0x5c4 method once. Extracted here as a
 * named helper purely for this reconstruction's own readability - the
 * real binary has it inlined at both real call sites, not factored out.
 */
static void evictSurfaceBuffers(IOATIR500Surface *surface, UInt32 reasonCode) {
    UInt8 *surf = reinterpret_cast<UInt8 *>(surface);
    UInt8 *entry = surf + 0xa8;
    for (UInt32 i = 0; i <= 0x16; i++, entry += 0x78) {
        bool indexGate = (*reinterpret_cast<SInt32 *>(surf + 0xc14) == 0xffff) ||
                          (i > 1 && (i - 4) > 1);
        bool entryLive = *reinterpret_cast<UInt32 *>(entry + 8) != 0;
        bool identityGate = (*reinterpret_cast<UInt32 *>(surf + 0xbd0) & 0xffff0000u) == 0 ||
                             (reinterpret_cast<void *>(entry) != *reinterpret_cast<void **>(surf + 0xb70));
        if (indexGate && entryLive && identityGate) {
            if (*reinterpret_cast<UInt32 *>(surf + 0xd48) == 0) {
                surface->move_buffer_to_backing_store(reinterpret_cast<ATIR500SurfaceBuffer *>(entry));
            } else {
                callSurfaceVtable0x5cc(surf, reasonCode);
            }
        }
    }
    callSurfaceVtable0x5c4(surf);
}

/*
 * compact_current_textures - RESOLVED (issue #5), fully transcribed
 * (real kext offset 0x29dd0). REAL RETURN TYPE CORRECTED to a real
 * value (was declared `void`) - see ATIR500GLContext.h.
 *
 * Real structure: a 42-entry (0x2a) scan over the texture-slot array at
 * this+0x2a4 (the SAME array IOATIR500GLContext::start zero-initializes
 * - see issue #10's Sources/IOATIR500GLContext_Start.cpp), evicting
 * every currently-bound texture's surface buffers (via the shared
 * evictSurfaceBuffers helper above) and unlinking each from a real
 * doubly-linked list at its mip-record's own +0x24/+0x28 fields. If the
 * requested texture (`texture`) wasn't itself found in that scan, it
 * gets the same eviction-and-unlink treatment on its own. Then calls
 * `invalidate()` (RESOLVED issue #12.1), advances a real 4-bit rotating
 * ring-buffer-slot index (this+0x28c), and re-walks the SAME 42-entry
 * array a second time to rebuild and resubmit a real vertex/texture
 * offset table via WriteTextureOffset/WriteVertexArrayOffset/
 * ATIRadeonX1000::submit_buffer - reloading each surviving texture from
 * its own backing store (or calling `load_texture`) along the way.
 * Finally ensures the originally-requested texture's own surface is
 * reloaded before returning success/failure.
 */
IOReturn ATIR500GLContext::compact_current_textures(VendorTextureBuffer *texture) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);
    UInt8 *tex = reinterpret_cast<UInt8 *>(texture);
    UInt32 *slots = reinterpret_cast<UInt32 *>(self + 0x2a4);
    UInt32 mask[7] = {};

    bool foundInScan = false;
    for (UInt32 i = 0; i <= 0x29; i++) {
        UInt8 *boundTex = reinterpret_cast<UInt8 *>(slots[i]);
        if (boundTex == nullptr) continue;

        if (*reinterpret_cast<UInt32 *>(boundTex + 0x48) == 0) {
            if (*reinterpret_cast<char *>(boundTex + 0x20) != 0) {
                continue; /* real: goto LAB_00029f5c - skip unlink for this slot */
            }
            IOATIR500Surface *surface = *reinterpret_cast<IOATIR500Surface **>(boundTex + 0x50);
            evictSurfaceBuffers(surface, i);
        } else {
            callAcceleratorVtable0x524(accel);
        }

        UInt8 *mip = *reinterpret_cast<UInt8 **>(boundTex + 0x14);
        mip[0x14] = 1;
        *reinterpret_cast<UInt16 *>(mip + 0x28) = 0;
        *reinterpret_cast<UInt16 *>(mip + 0x2a) = 0;
        *reinterpret_cast<UInt16 *>(mip + 0x2c) = 0;
        *reinterpret_cast<UInt16 *>(mip + 0x2e) = 0;
        *reinterpret_cast<UInt16 *>(mip + 0x30) = 0;
        *reinterpret_cast<UInt16 *>(mip + 0x32) = 0;

        UInt8 *prevNode = *reinterpret_cast<UInt8 **>(boundTex + 0x24);
        UInt8 *nextNode = *reinterpret_cast<UInt8 **>(boundTex + 0x28);
        *reinterpret_cast<UInt32 *>(prevNode + 0x28) = reinterpret_cast<UInt32>(nextNode);
        *reinterpret_cast<UInt32 *>(nextNode + 0x24) = reinterpret_cast<UInt32>(prevNode);
        *reinterpret_cast<UInt32 *>(boundTex + 0x28) = reinterpret_cast<UInt32>(boundTex);
        *reinterpret_cast<UInt32 *>(boundTex + 0x24) = reinterpret_cast<UInt32>(boundTex);

        if (texture == reinterpret_cast<VendorTextureBuffer *>(boundTex)) foundInScan = true;
    }

    if (*reinterpret_cast<UInt32 *>(tex + 0x20) == 0) { /* real: param_1[0x20], the same discriminant byte alloc_and_load_texture reads */
        IOATIR500Surface *surface = *reinterpret_cast<IOATIR500Surface **>(tex + 0x50);
        evictSurfaceBuffers(surface, 0x2a);

        UInt8 *mip = *reinterpret_cast<UInt8 **>(tex + 0x14);
        mip[0x14] = 1;
        *reinterpret_cast<UInt16 *>(mip + 0x28) = 0;
        *reinterpret_cast<UInt16 *>(mip + 0x2a) = 0;
        *reinterpret_cast<UInt16 *>(mip + 0x2c) = 0;
        *reinterpret_cast<UInt16 *>(mip + 0x2e) = 0;
        *reinterpret_cast<UInt16 *>(mip + 0x30) = 0;
        *reinterpret_cast<UInt16 *>(mip + 0x32) = 0;

        UInt8 *prevNode = *reinterpret_cast<UInt8 **>(tex + 0x24);
        *reinterpret_cast<UInt32 *>(prevNode + 0x28) = reinterpret_cast<UInt32>(texture);
        UInt8 *nextNode = *reinterpret_cast<UInt8 **>(tex + 0x28);
        *reinterpret_cast<UInt32 *>(tex + 0x28) = reinterpret_cast<UInt32>(texture);
        *reinterpret_cast<UInt32 *>(nextNode + 0x24) = reinterpret_cast<UInt32>(texture);
        *reinterpret_cast<UInt32 *>(tex + 0x24) = reinterpret_cast<UInt32>(texture);
    }

    invalidate(); /* RESOLVED (issue #12.1): real name of vtable+0x5a4 */

    UInt32 ringSlot = (*reinterpret_cast<UInt32 *>(self + 0x28c) + 1) & 0xf;
    *reinterpret_cast<UInt32 *>(self + 0x28c) = ringSlot;
    UInt8 *ringBase = self + ringSlot * 0x18;

    /* real: accumulates a completion-stamp delta via a real accelerator
     * vtable call at +0x54c, same call restore_state_destroyed_by_pageoff
     * makes (Sources/ATIR500GLContext_RestoreState.cpp) */
    typedef UInt32 (*StampFn)(void *, UInt32);
    UInt32 stampDelta = (*reinterpret_cast<StampFn *>(*reinterpret_cast<void ***>(accel) + (0x54c / 4)))(
        accel, *reinterpret_cast<UInt32 *>(ringBase + 0x11c));
    *reinterpret_cast<UInt32 *>(accel + 0x780) += stampDelta;

    UInt32 *outBuf = reinterpret_cast<UInt32 *>(*reinterpret_cast<UInt32 *>(ringBase + 0x120) + 0x20);
    UInt32 outCount = 0, byteOffset = 0;
    for (UInt32 i = 0; i <= 0x29; i++) {
        UInt8 *boundTex = reinterpret_cast<UInt8 *>(slots[i]);
        if (boundTex == nullptr) { outCount++; continue; }
        UInt32 disc = *reinterpret_cast<UInt32 *>(boundTex + 0x20);
        if (disc != 3 && disc != 0 && disc != 7) { outCount++; continue; }

        if (*reinterpret_cast<UInt32 *>(boundTex + 0x48) == 0) {
            if (disc == 0) {
                IOATIR500Surface *surface = *reinterpret_cast<IOATIR500Surface **>(boundTex + 0x50);
                UInt32 idx = surface->surface_buffer_idx_mask(*reinterpret_cast<UInt32 *>(boundTex + 0x58), mask);
                UInt8 *entry = reinterpret_cast<UInt8 *>(surface) + idx * 4 + 0xb70;
                UInt8 *surfaceBuffer = *reinterpret_cast<UInt8 **>(entry);
                callSurfaceVtable0x5d0(surface, surfaceBuffer);
                surface->copy_buffer_from_backing_store(reinterpret_cast<ATIR500SurfaceBuffer *>(surfaceBuffer));
            } else {
                if (callAcceleratorVtable0x528(accel, boundTex) != 0) {
                    load_texture(reinterpret_cast<VendorTextureBuffer *>(boundTex));
                }
            }
            *reinterpret_cast<UInt8 *>(*reinterpret_cast<UInt32 *>(boundTex + 0x14) + 0x14) = 0;
        }
        if (outCount < 0x10) {
            UInt32 written = WriteTextureOffset(outCount, outBuf, byteOffset,
                                                 reinterpret_cast<VendorTextureBuffer *>(boundTex));
            byteOffset += written;
        }
        outCount++;
    }

    UInt32 vertexWritten = WriteVertexArrayOffset(outBuf, byteOffset);
    UInt32 totalDwords = vertexWritten + byteOffset;
    if ((totalDwords & 1) != 0) {
        outBuf[totalDwords] = 0x80000000u;
        totalDwords += 1;
    }

    if (*reinterpret_cast<UInt32 *>(ringBase + 0x110) == 0) {
        map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(ringBase + 0x10c));
    }

    *reinterpret_cast<UInt32 *>(accel + 0x704) += totalDwords * 4;
    *reinterpret_cast<UInt32 *>(accel + 0xb94) = 1;
    *reinterpret_cast<UInt32 *>(ringBase + 0x11c) = accelerator->submit_buffer(
        outBuf, *reinterpret_cast<UInt32 *>(ringBase + 0x110) + 0x20, totalDwords);

    if (*reinterpret_cast<UInt32 *>(tex + 0x20) == 0) {
        IOATIR500Surface *surface = *reinterpret_cast<IOATIR500Surface **>(tex + 0x50);
        UInt32 idx = surface->surface_buffer_idx_mask(*reinterpret_cast<UInt32 *>(tex + 0x58), mask);
        UInt8 *surfaceBuffer = *reinterpret_cast<UInt8 **>(reinterpret_cast<UInt8 *>(surface) + idx * 4 + 0xb70);
        if (callSurfaceVtable0x5d0(surface, surfaceBuffer) != 0 &&
            surface->copy_buffer_from_backing_store(reinterpret_cast<ATIR500SurfaceBuffer *>(surfaceBuffer)) != 0) {
            return 1;
        }
        return 0;
    }
    return static_cast<IOReturn>(callAcceleratorVtable0x528(accel, tex));
}

/*
 * submit_context_buffer - RESOLVED (issue #5), fully transcribed (real
 * kext offset 0x2a8b0). Real structure: first walks the SAME 42-entry
 * texture-slot array (this+0x2a4) as compact_current_textures, reloading
 * (alloc_and_load_texture + invalidate()) any texture whose mip record
 * is flagged dirty, then re-links any texture with a nonzero +0x48 into
 * the accelerator's texture list (accelerator+0x600/+0x5dc - the same
 * real list get_texture uses).
 *
 * Then checks the dirty bit `invalidate()` sets (this+0x108's own +0x1c,
 * bit 0) - RESOLVED cross-reference confirming exactly what that bit is
 * for: if clear, just reuses the current ring-buffer slot's existing
 * buffer pointer; if set, this is the real "flush" path - advances the
 * 4-bit rotating ring-buffer slot (same pattern as
 * compact_current_textures), copies an 8-dword header plus a real
 * variable-length payload out of the pending-writes queue object at
 * this+0x108 into the new ring slot's buffer, calls
 * write_kernel_context_buffer_regs to append the live register state,
 * walks the FIRST 16 (not all 42) texture slots writing their offsets,
 * appends a real trailing PM4 header (`0x1040`/`0`) plus alignment
 * padding, records the real dword count on the ring slot's own buffer
 * object, then clears the dirty bit.
 *
 * Either way, ensures the ring slot is GART-mapped and submits it via
 * ATIRadeonX1000::submit_buffer, recording the result both on the ring
 * slot (+0x11c) and on this+0x7c (a field this project has not
 * independently named).
 */
void ATIR500GLContext::submit_context_buffer() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);
    UInt32 *slots = reinterpret_cast<UInt32 *>(self + 0x2a4);

    *reinterpret_cast<UInt32 *>(accel + 0xb90) = 0;

    for (UInt32 i = 0; i <= 0x29; i++) {
        UInt8 *boundTex = reinterpret_cast<UInt8 *>(slots[i]);
        if (boundTex == nullptr) continue;

        if (*reinterpret_cast<char *>(*reinterpret_cast<UInt32 *>(boundTex + 0x14) + 0x14) != 0) {
            alloc_and_load_texture(reinterpret_cast<VendorTextureBuffer *>(boundTex));
            invalidate(); /* RESOLVED (issue #12.1): real name of vtable+0x5a4 */
            boundTex = reinterpret_cast<UInt8 *>(slots[i]); /* real: reloaded fresh */
        }

        if (*reinterpret_cast<UInt32 *>(boundTex + 0x48) != 0) {
            UInt8 *prevNode = *reinterpret_cast<UInt8 **>(boundTex + 0x24);
            UInt8 *nextNode = *reinterpret_cast<UInt8 **>(boundTex + 0x28);
            *reinterpret_cast<UInt32 *>(prevNode + 0x28) = reinterpret_cast<UInt32>(nextNode);
            *reinterpret_cast<UInt32 *>(nextNode + 0x24) = reinterpret_cast<UInt32>(prevNode);
            *reinterpret_cast<UInt32 *>(boundTex + 0x24) = *reinterpret_cast<UInt32 *>(accel + 0x600);
            *reinterpret_cast<UInt32 *>(boundTex + 0x28) = reinterpret_cast<UInt32>(accel + 0x5dc);
            *reinterpret_cast<UInt32 *>(accel + 0x600) = reinterpret_cast<UInt32>(boundTex);
            UInt8 *newPrev = *reinterpret_cast<UInt8 **>(boundTex + 0x24);
            *reinterpret_cast<UInt32 *>(newPrev + 0x28) = reinterpret_cast<UInt32>(boundTex);
        }
    }

    UInt8 *pendingQueue = *reinterpret_cast<UInt8 **>(self + 0x108);
    UInt8 *ringBase;

    if ((*reinterpret_cast<UInt32 *>(pendingQueue + 0x1c) & 1) == 0) {
        ringBase = self + *reinterpret_cast<UInt32 *>(self + 0x28c) * 0x18;
    } else {
        UInt32 ringSlot = (*reinterpret_cast<UInt32 *>(self + 0x28c) + 1) & 0xf;
        *reinterpret_cast<UInt32 *>(self + 0x28c) = ringSlot;
        ringBase = self + ringSlot * 0x18;

        typedef UInt32 (*StampFn)(void *, UInt32);
        UInt32 stampDelta = (*reinterpret_cast<StampFn *>(*reinterpret_cast<void ***>(accel) + (0x54c / 4)))(
            accel, *reinterpret_cast<UInt32 *>(ringBase + 0x11c));
        *reinterpret_cast<UInt32 *>(accel + 0x780) += stampDelta;

        UInt32 *headerSrc = reinterpret_cast<UInt32 *>(pendingQueue);
        UInt32 *slotBuf = *reinterpret_cast<UInt32 **>(ringBase + 0x120);
        /* real: an 8-dword header copy, transcribed in the same order
         * (not a plain loop in the real decompile) */
        slotBuf[0] = headerSrc[0];
        slotBuf[1] = headerSrc[1];
        slotBuf[2] = headerSrc[2];
        slotBuf[3] = headerSrc[3];
        slotBuf[7] = headerSrc[7];
        slotBuf[4] = headerSrc[4];
        slotBuf[5] = headerSrc[5];
        slotBuf[6] = headerSrc[6];

        UInt32 payloadCount = reinterpret_cast<UInt32 *>(pendingQueue)[5];
        UInt32 *payloadDst = reinterpret_cast<UInt32 *>(*reinterpret_cast<UInt32 *>(ringBase + 0x120) + 0x20);
        if (payloadCount != 0) {
            UInt32 *payloadSrc = reinterpret_cast<UInt32 *>(pendingQueue + 0x20);
            for (UInt32 i = 0; i < payloadCount; i++) payloadDst[i] = payloadSrc[i];
        }

        UInt32 regsWritten = write_kernel_context_buffer_regs(
            payloadDst, payloadCount,
            reinterpret_cast<UInt32 *>(pendingQueue)[0], reinterpret_cast<UInt32 *>(pendingQueue)[1]);

        UInt32 dwordCount = regsWritten;
        for (UInt32 i = 0; i <= 0xf; i++) {
            UInt8 *slotTex = reinterpret_cast<UInt8 *>(slots[i]);
            if (slotTex != nullptr) {
                dwordCount += WriteTextureOffset(i, payloadDst, dwordCount,
                                                  reinterpret_cast<VendorTextureBuffer *>(slotTex));
            }
        }
        dwordCount += WriteVertexArrayOffset(payloadDst, dwordCount);

        payloadDst[dwordCount] = 0x1040;
        UInt32 finalCount = dwordCount + 2;
        payloadDst[dwordCount + 1] = 0;
        if ((finalCount & 1) != 0) {
            finalCount = dwordCount + 3;
            payloadDst[dwordCount + 2] = 0x80000000u;
        }
        *reinterpret_cast<UInt32 *>(*reinterpret_cast<UInt32 *>(ringBase + 0x120) + 0x14) = finalCount;
        *reinterpret_cast<UInt32 *>(pendingQueue + 0x1c) &= 0xfffffffeu;
    }

    if (*reinterpret_cast<UInt32 *>(ringBase + 0x110) == 0) {
        map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(ringBase + 0x10c));
    }
    *reinterpret_cast<UInt32 *>(accel + 0x704) +=
        *reinterpret_cast<UInt32 *>(*reinterpret_cast<UInt32 *>(ringBase + 0x120) + 0x14) * 4;

    UInt32 submitResult = accelerator->submit_buffer(
        reinterpret_cast<UInt32 *>(*reinterpret_cast<UInt32 *>(ringBase + 0x120) + 0x20),
        *reinterpret_cast<UInt32 *>(ringBase + 0x110) + 0x20,
        *reinterpret_cast<UInt32 *>(*reinterpret_cast<UInt32 *>(ringBase + 0x120) + 0x14));
    *reinterpret_cast<UInt32 *>(ringBase + 0x11c) = submitResult;
    *reinterpret_cast<UInt32 *>(self + 0x7c) = submitResult;
}
