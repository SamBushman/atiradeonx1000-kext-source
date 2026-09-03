/*
 * ATIR500GLContext_TextureLoad.cpp
 *
 * FULLY RESOLVED (issue #5): all six of this project's remaining
 * declared-but-bodyless internal helpers - get_texture,
 * alloc_and_load_texture, compact_current_textures, submit_context_buffer,
 * convertIOGLBufferToBufIdx (a real free function, see
 * ATIR500GLContext.h), and finally load_texture itself - are now fully
 * decompiled and transcribed (real kext offsets 0x2b5f0, 0x2a3d0, 0x29dd0,
 * 0x2a8b0, 0x26ce0, and 0x29480 respectively). load_texture was the one
 * deliberately deferred across an earlier pass (large/dense, ~380 lines)
 * - see its own header comment below for the full real structure.
 *
 * Confidence: CONFIRMED for control flow and every field offset/call
 * touched - transcribed directly from complete real decompiles, not
 * summarized. Several sub-calls reached through raw vtable-offset casts
 * (accelerator vtable +0x524/+0x528/+0x54c, IOATIR500Surface vtable
 * +0x5c4/+0x5cc/+0x5d0, and two more used only by load_texture at
 * +0x14c/+0xd0/+0x18 on a real "memory-descriptor-shaped" object - see
 * ATIR500GLContext_DiscardBuffer.cpp's matching cross-reference) have
 * real, confirmed-to-exist targets but UNKNOWN real names - called
 * opaquely per this project's no-shortcuts standard, same as elsewhere.
 * get_texture's atomic decrement loop was verified against raw PPC
 * disassembly (lwarx/stwcx.), not just Ghidra's decompile, since the
 * decompiler couldn't fully resolve it into clean C on its own.
 * load_texture's own deepest per-tile register-burst math (particularly
 * its "linear" tiling path's per-level hwShiftA/hwShiftB recurrence and
 * its LOD-bias computation's own `pAVar22`-shaped struct) is transcribed
 * faithfully but, like write_kernel_context_buffer_regs and
 * restore_state_destroyed_by_pageoff elsewhere in this project, dense
 * enough to warrant an independent spot-check before being fully trusted
 * bit-for-bit - see load_texture's own header comment for specifics.
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
 * buffers). Real address 0x2a864. CONFIRMED (issue #15 investigation, issue still open): a real
 * lazy-binding external stub with no local body in this binary at all -
 * see the comprehensive finding at the end of
 * Headers/ATIRadeonX1000Registers.h.
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

/*
 * load_texture - RESOLVED (issue #5), fully transcribed (real kext offset
 * 0x29480). This is the deferred function - see this file's own header
 * and GAPS.md for why it was split from its now-resolved siblings.
 *
 * Real structure, in order:
 *
 * 1. Dirty-mip scan: for each of the texture's `faceCount` faces (mip[0x34],
 *    a byte - almost certainly cubemap face count, 1 or 6 in practice) and
 *    each mip level in [baseLevel, baseLevel+levelCount-1] (mip[0x17],
 *    mip[0x35]), tests bit `level` of `(dirtyBits & ~loadedBits)` where
 *    dirtyBits/loadedBits are per-face UInt16 fields at `mip + face*2 +
 *    0x1c` / `mip + face*2 + 0x28` respectively - CONFIRMED CROSS-REFERENCE:
 *    the `+0x28` array (up to 6 UInt16 entries, one per face) is the exact
 *    same memory `alloc_and_load_texture`/`compact_current_textures` clear
 *    to zero via their six explicit `mip[0x28]..mip[0x32] = 0` writes during
 *    eviction. If no face/level combination is dirty-and-unloaded, returns
 *    immediately (nothing to do).
 *
 * 2. GART-mapping prep: calls a real vtable method at offset 0x14c on the
 *    texture's `memoryDescriptor` field (VendorTextureBuffer+0x08, per
 *    ATIRadeonX1000Types.h) - the SAME real vtable slot
 *    Sources/ATIR500GLContext_DiscardBuffer.cpp's header already flags as
 *    "a real vtable method... to (re)establish a real backing mapping" on
 *    opcode 0x3b's cleanup path (issue #12 item 3) - this is a second,
 *    independent real call site for that same slot, with concrete argument
 *    values, though still not independently named (opaque call, matching
 *    this project's no-shortcuts standard). Returns null on failure (early
 *    return). The resulting handle's own vtable+0xd0 (no extra args) then
 *    returns `hwInfo`, a heavily-indexed per-mip/tile hardware-tiling
 *    descriptor this function reads extensively - CONFIRMED this handle is
 *    released via vtable+0x18 right before returning (matches the
 *    `gartMapping`/`memoryDescriptor` struct comment's established
 *    "released via vtable+0x18" pattern).
 *
 * 3. Per-texture-type dispatch (type 3 / type 7 / anything else) computing
 *    `payloadByteLen` and an initial `tileXBase` value - types 3 and 7 both
 *    real-splice a transfer buffer into the accelerator's transfer-buffer
 *    list (accelerator+0x6d0/+0x69c, the SAME list alloc_and_load_texture's
 *    `spliceIntoTransferList` uses) via a SEPARATE, not-independently-
 *    decompiled small helper at real address 0x29da8 (own copy of the same
 *    unlink pattern as `FUN_0002a864` above - different address, same real
 *    shape, opaque call).
 *
 * 4. Real completion-stamp accumulation via accelerator vtable+0x54c
 *    (accelerator+0x744 += stamp(mip+0xc)) - the SAME real vtable call
 *    `compact_current_textures`/`restore_state_destroyed_by_pageoff` make
 *    against a different accumulator field (+0x780); this one is specific
 *    to texture loads. `record` (the PM4 burst output buffer) is then
 *    computed as `hwInfo + 0xa00` bytes - CONFIRMED CROSS-REFERENCE: this
 *    exact `+0xa00` constant reappears in both of this function's own
 *    `submit_buffer` calls at the tail (`tex+4 (GART address) + 0xa00`),
 *    confirming `hwInfo` is the kernel-mapped view of the same GART
 *    allocation the texture's own +4 field addresses.
 *
 * 5. A real two-way branch on `hwInfo[8]`'s sign bit (real offset 0x20,
 *    tested as `< 0`) - real evidence of two genuinely different tiling
 *    code paths (informally "macro-tiled" vs "linear" below, not real
 *    driver terminology, chosen for readability):
 *
 *    - Path A (hwInfo[8] < 0): walks all faces/levels again, building a
 *      3-field-per-tile register burst (an "enable" marker plus X/Y base
 *      addresses, or a "disabled" marker if the level is out of the
 *      dirty-and-unloaded set), reading a per-tile record at `hwInfo +
 *      tileIndex*0x20` (tileIndex = face*13+level) with fields at +0x40
 *      (UInt16, output DWORD slot), +0x42 (UInt16, repeat count), +0x44/
 *      +0x48 (SInt32 X/Y base), +0x4c/+0x50 (SInt32 X/Y stride). Marks
 *      each face's levels loaded (`loadedBits |= dirtyBits`) as it goes.
 *      Finishes with a real LOD-bias register computation read from a
 *      SEPARATE per-context "current surface buffer entry" pointer
 *      (`pAVar22` in the raw decompile) whose own real field layout
 *      (+0x08/+0x14/+0x16/+0x20/+0x38/+0x3c, plus a 2-entry SInt32 array at
 *      +0x40) is UNKNOWN beyond what this one computation implies -
 *      genuinely reached via two different real source expressions
 *      depending on `this+0x3bc`, both eventually indexing the same
 *      `surface+idx*4+0xb70`-shaped array `compact_current_textures`
 *      already uses for `ATIR500SurfaceBuffer` lookups (plausible, not
 *      confirmed, that `pAVar22` IS an `ATIR500SurfaceBuffer*`).
 *
 *    - Path B (hwInfo[8] >= 0): offsets `record` forward by `hwInfo[1]`
 *      dwords (a real "header size" - the matching `submit_buffer` call
 *      below re-adds the same offset when computing the GART address, a
 *      direct confirmation), writes one fixed dword (`record[0xb] =
 *      accelerator+0xb74`), then runs a real small state machine on
 *      `mip[0x15]`'s upper bits and `hwInfo[0x1a]` (a byte) to pick one of
 *      three `(tileMode, tileParam)` pairs - transcribed as clean
 *      structured code below; the raw decompile's own label soup
 *      (LAB_00029a5c/LAB_00029a64/LAB_00029a94) was verified by hand to
 *      collapse to exactly this if/else-if/else with no behavior change.
 *      Then a face/level double loop writes a real 5-field-per-repeat
 *      register burst per tile (fields at relative dword offsets +1/+3/+5/
 *      +9 within a 0x1d-dword stride, packing hwInfo[0x1b] and evolving
 *      per-level shift values `hwShiftA`/`hwShiftB` whose own recurrence -
 *      each level's value is `max(a fixed floor, half of the previous
 *      level's value)` - is transcribed exactly as decompiled but NOT
 *      independently re-verified against raw disassembly. Sets
 *      accelerator+0xb90 = 1 at the end - CONFIRMED CROSS-REFERENCE: this
 *      is the exact same "mid-pageoff" flag `get_texture` checks before
 *      calling `restore_state_destroyed_by_pageoff`, and that
 *      `submit_context_buffer` clears at its own start - Path B is the
 *      real producer of that flag.
 *
 * 6. Shared tail: pads `record` to an even dword count (writing a
 *    `0x80000000` terminator if needed), accumulates
 *    accelerator+0x704/+0x71c (byte-count and payload-length accumulators,
 *    the same +0x704 field `compact_current_textures`/
 *    `submit_context_buffer` also accumulate), submits via
 *    `ATIRadeonX1000::submit_buffer` (base GART address differs by
 *    `hwInfo[1]*4` between the two tiling paths, matching the Path-B-only
 *    forward offset applied to `record` above), stores the result on
 *    `mip+0xc` (the same field the completion-stamp call above reads), and
 *    for type 7 propagates that same value into a second, real but
 *    UNKNOWN-precision field reached through the type's own inner transfer
 *    buffer (two pointer indirections deep - arithmetic transcribed
 *    faithfully, exact struct identity not independently confirmed).
 *    Finally releases the GART-mapping handle from step 2 via vtable+0x18.
 *
 * Confidence: CONFIRMED for the overall structure, every real offset and
 * cross-referenced field, and both submit_buffer call sites. The Path A/
 * Path B per-tile register-burst payloads themselves (which exact bits go
 * where in the output PM4 stream) are transcribed faithfully from the real
 * decompile but, like `write_kernel_context_buffer_regs` and
 * `restore_state_destroyed_by_pageoff` elsewhere in this project, are
 * dense enough (particularly Path B's per-level hwShiftA/hwShiftB
 * recurrence) that a systematic line-by-line spot-check against the real
 * decompile - or, ideally, live hardware behavior - is worth doing before
 * fully trusting any single bit position here. Real per-tile struct field
 * names beyond what's cross-referenced above are UNKNOWN; kept as raw byte
 * offsets rather than invented names, per this project's standard.
 */
void ATIR500GLContext::load_texture(VendorTextureBuffer *texture) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *tex = reinterpret_cast<UInt8 *>(texture);
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);

    UInt8 *mip = *reinterpret_cast<UInt8 **>(tex + 0x14);
    SInt32 yOffset = *reinterpret_cast<SInt32 *>(tex + 0x48); /* real: also gates the type-3/7 splice paths as "pending" when nonzero, same field alloc_and_load_texture/compact_current_textures test as a boolean - here its actual VALUE is used as a pixel Y delta, consistent with "nonzero == suballocated within a shared region, and the value is the real offset within it" */
    UInt32 faceCount = *reinterpret_cast<UInt8 *>(mip + 0x34);
    UInt32 baseLevel = *reinterpret_cast<UInt8 *>(mip + 0x17);
    UInt32 lastLevel = baseLevel + *reinterpret_cast<UInt8 *>(mip + 0x35) - 1;
    if (faceCount == 0) return;

    bool needsReload = false;
    for (UInt32 face = 0; face < faceCount; face++) {
        UInt8 *faceMip = mip + face * 2;
        if (baseLevel <= lastLevel) {
            for (UInt32 level = baseLevel; level <= lastLevel; level++) {
                UInt16 dirtyBits = *reinterpret_cast<UInt16 *>(faceMip + 0x1c);
                UInt16 loadedBits = *reinterpret_cast<UInt16 *>(faceMip + 0x28);
                if (((static_cast<UInt32>(dirtyBits) & ~static_cast<UInt32>(loadedBits)) >> (level & 0x3f)) & 1) {
                    needsReload = true;
                }
            }
        }
    }
    if (!needsReload) return;

    /* Real vtable+0x14c call on the texture's memoryDescriptor (+0x08) -
     * see this function's own header comment. Args transcribed exactly;
     * `_ASICSupportsAGP` is Ghidra's own (plausibly misleading - it's used
     * elsewhere as a raw shift count, not just a boolean) auto-name for a
     * real global this project has not independently investigated. */
    extern int _ASICSupportsAGP;
    typedef void *(*PrepareMappingFn)(void *, int, int, UInt32, int, int);
    void *memoryDescriptor = *reinterpret_cast<void **>(tex + 8);
    void *memHandle = (*reinterpret_cast<PrepareMappingFn *>(
        *reinterpret_cast<void ***>(memoryDescriptor) + (0x14c / 4)))(
        memoryDescriptor, _ASICSupportsAGP, 0,
        *reinterpret_cast<UInt32 *>(accel + 0x82c) | 1, 0, 0);
    if (memHandle == nullptr) return;

    typedef UInt32 *(*GetHwInfoFn)(void *);
    UInt32 *hwInfo = (*reinterpret_cast<GetHwInfoFn *>(*reinterpret_cast<void ***>(memHandle) + (0xd0 / 4)))(memHandle);
    UInt8 *hwInfoBytes = reinterpret_cast<UInt8 *>(hwInfo);

    /* Own copy (real address 0x29da8) of the same unlink-then-splice-into-
     * accelerator-transfer-list pattern alloc_and_load_texture's
     * FUN_0002a864/spliceIntoTransferList already use. RESOLVED, issue
     * #15: a real lazy-binding external stub with no local body in this
     * binary - see the comprehensive finding at the end of
     * Headers/ATIRadeonX1000Registers.h. */
    extern void FUN_00029da8(void *node);
    auto spliceIntoAccelTransferList = [&](UInt8 *node) {
        FUN_00029da8(node + 0x2c);
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

    UInt32 discriminant = *reinterpret_cast<UInt32 *>(tex + 0x20);
    UInt32 payloadByteLen; /* real: local_54 */
    SInt32 tileXBase;      /* real: iVar17, first component - accel+0x8a4 added below */

    if (discriminant == 3) {
        if (*reinterpret_cast<UInt32 *>(tex + 4) != 0) {
            spliceIntoAccelTransferList(tex);
        } else {
            map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(texture));
            if (*reinterpret_cast<UInt32 *>(tex + 4) != 0) spliceIntoAccelTransferList(tex);
        }
        /* real: param_1[0x20] is still 3 here, so the raw decompile's own
         * "if (type != 7) goto LAB_00029724" always takes that branch -
         * collapsed directly, no dead re-check needed. */
        payloadByteLen = *reinterpret_cast<UInt32 *>(tex + 0x50);
        tileXBase = *reinterpret_cast<SInt32 *>(tex + 4);
    } else if (discriminant == 7) {
        UInt8 *inner = *reinterpret_cast<UInt8 **>(tex + 0x58); /* VendorTransferBuffer* */
        if (*reinterpret_cast<UInt32 *>(inner + 4) == 0) {
            map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(inner));
        }
        bool relinkTex;
        if (*reinterpret_cast<UInt32 *>(tex + 4) == 0) {
            /* real: temporary pin/refcount bump around the nested map call */
            *reinterpret_cast<SInt16 *>(inner + 0xe) += 1;
            map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(texture));
            UInt32 mappedNow = *reinterpret_cast<UInt32 *>(tex + 4);
            *reinterpret_cast<SInt16 *>(inner + 0xe) -= 1;
            relinkTex = (mappedNow != 0);
        } else {
            relinkTex = true;
        }
        if (relinkTex) spliceIntoAccelTransferList(tex);
        if (*reinterpret_cast<UInt32 *>(inner + 4) != 0) spliceIntoAccelTransferList(inner);

        payloadByteLen = *reinterpret_cast<UInt32 *>(tex + 0x50);
        tileXBase = *reinterpret_cast<SInt32 *>(*reinterpret_cast<UInt32 *>(tex + 0x58) + 4);
    } else {
        payloadByteLen = *reinterpret_cast<UInt32 *>(tex + 0x50);
        tileXBase = *reinterpret_cast<SInt32 *>(tex + 4);
    }

    /* Real completion-stamp accumulation - see header comment. */
    typedef UInt32 (*StampFn)(void *, UInt32);
    UInt32 stampDelta = (*reinterpret_cast<StampFn *>(*reinterpret_cast<void ***>(accel) + (0x54c / 4)))(
        accel, *reinterpret_cast<UInt32 *>(mip + 0xc));
    UInt32 *record = hwInfo + 0x280; /* real: hwInfo + 0xa00 bytes */
    *reinterpret_cast<UInt32 *>(accel + 0x744) += stampDelta;
    tileXBase += *reinterpret_cast<SInt32 *>(accel + 0x8a4);

    UInt32 finalDwordCount;

    if (static_cast<SInt32>(hwInfo[8]) < 0) {
        /* ---- Path A ("macro-tiled") ---- */
        if (*reinterpret_cast<SInt32 *>(tex + 100) == 2) {
            hwInfo[0x285] = 1;
        } else if (*reinterpret_cast<SInt32 *>(tex + 100) == 4) {
            hwInfo[0x285] = 2;
        }

        for (UInt32 face = 0; face < faceCount; face++) {
            UInt8 *faceMip = mip + face * 2;
            if (baseLevel <= lastLevel) {
                UInt16 loadedBits = *reinterpret_cast<UInt16 *>(faceMip + 0x28);
                UInt16 dirtyBits = *reinterpret_cast<UInt16 *>(faceMip + 0x1c);
                for (UInt32 level = baseLevel; level <= lastLevel; level++) {
                    UInt32 tileIndex = face * 0xd + level;
                    UInt8 *tile = hwInfoBytes + tileIndex * 0x20;
                    UInt32 outSlot = *reinterpret_cast<UInt16 *>(tile + 0x40);
                    UInt32 repeatCount = *reinterpret_cast<UInt16 *>(tile + 0x42);
                    SInt32 xBase = *reinterpret_cast<SInt32 *>(tile + 0x44);
                    SInt32 yBase = *reinterpret_cast<SInt32 *>(tile + 0x48);
                    SInt32 xStride = *reinterpret_cast<SInt32 *>(tile + 0x4c);
                    SInt32 yStride = *reinterpret_cast<SInt32 *>(tile + 0x50);
                    if (repeatCount == 0) repeatCount = 1;

                    UInt32 slot = outSlot;
                    for (UInt32 rep = 0; rep < repeatCount; rep++) {
                        if (((static_cast<UInt32>(dirtyBits) & ~static_cast<UInt32>(loadedBits)) >> (level & 0x3f) & 1) == 0) {
                            record[slot] = 0xc0101000u;
                        } else {
                            record[slot] = 0x80000000u;
                            record[slot + 4] = static_cast<UInt32>(xBase + tileXBase);
                            record[slot + 7] = static_cast<UInt32>(yBase + yOffset);
                        }
                        slot += 0x12;
                        xBase += xStride;
                        yBase += yStride;
                    }
                }
            }
            *reinterpret_cast<UInt16 *>(faceMip + 0x28) |= *reinterpret_cast<UInt16 *>(faceMip + 0x1c);
        }

        UInt32 outIndex = hwInfo[0];
        record[outIndex] = 0x50bu;

        SInt32 lodA, lodB, lodC; /* real: iVar32, iVar26, iVar8 */
        UInt8 *surfBufEntry;      /* real: pAVar22 */
        if (*reinterpret_cast<UInt32 *>(self + 0x3bc) == 0) {
            lodA = *reinterpret_cast<SInt32 *>(self + 0x29c);
            lodB = *reinterpret_cast<SInt32 *>(self + 0x298);
            lodC = lodA + 1;
            surfBufEntry = *reinterpret_cast<UInt8 **>(
                static_cast<UInt32>(*reinterpret_cast<UInt16 *>(self + 0xac)) * 4 +
                *reinterpret_cast<UInt32 *>(self + 0x290) + 0xb70);
        } else {
            lodB = 0;
            lodA = 0;
            lodC = 1;
            surfBufEntry = self + static_cast<UInt32>(*reinterpret_cast<UInt16 *>(self + 0x3b2)) * 0x78 + 0x3c0;
        }

        UInt32 lodBiasA = 0;
        if ((*reinterpret_cast<UInt32 *>(surfBufEntry + 0x3c) & 0xf00000u) != 0) {
            lodBiasA = static_cast<UInt32>(*reinterpret_cast<UInt16 *>(surfBufEntry + 0x14)) /
                       ((*reinterpret_cast<UInt32 *>(surfBufEntry + 0x3c) >> 0x14) & 0xf);
        }
        UInt32 lodBiasB = 0x20u / *reinterpret_cast<UInt16 *>(surfBufEntry + 0x16);
        if (lodBiasB <= lodBiasA) lodBiasB = lodBiasA;
        UInt32 highBit = (*reinterpret_cast<UInt8 *>(surfBufEntry + 0x38) < 2) ? 0u : 0x80000000u;

        SInt32 *lodTable = reinterpret_cast<SInt32 *>(surfBufEntry + 0x40);
        SInt32 term1 = (lodTable[lodA] * static_cast<SInt32>(*reinterpret_cast<UInt16 *>(surfBufEntry + 0x20)) +
                         lodB * (lodTable[lodC] - lodTable[lodA]) +
                         *reinterpret_cast<SInt32 *>(surfBufEntry + 8)) >> 10;
        UInt32 term2 = (lodBiasB * (*reinterpret_cast<UInt16 *>(surfBufEntry + 0x16)) * 0x10000u) & 0x3fc00000u;
        UInt32 term3 = static_cast<UInt32>(*reinterpret_cast<UInt8 *>(surfBufEntry + 0x38) & 1) << 0x1e;
        record[outIndex + 1] = highBit | static_cast<UInt32>(term1) | term2 | term3;

        finalDwordCount = outIndex + 2;
    } else {
        /* ---- Path B ("linear") ---- */
        record += hwInfo[1];
        record[0xb] = *reinterpret_cast<UInt32 *>(accel + 0xb74);

        UInt8 mipFlags = *reinterpret_cast<UInt8 *>(mip + 0x15) >> 3;
        UInt32 hwByte1a = *reinterpret_cast<UInt8 *>(hwInfoBytes + 0x1a);
        UInt32 tileMode;   /* real: iVar5 */
        SInt32 tileParam;  /* real: iVar8 */
        if ((mipFlags & 3) == 0) {
            tileMode = 0; tileParam = 5;
        } else {
            /* real: verified by hand that the raw decompile's
             * LAB_00029a5c/LAB_00029a64/LAB_00029a94 label soup collapses
             * to exactly this - see header comment. */
            bool exactMatch = ((mipFlags & 2) != 0) || (hwByte1a == 0);
            if (hwByte1a > 3) {
                tileMode = 0; tileParam = 5;
            } else if (exactMatch) {
                tileMode = 2; tileParam = 3;
            } else {
                tileMode = 1; tileParam = 4;
            }
        }

        UInt32 maxFloorA = 0x20u >> (hwByte1a & 0x3f);
        UInt32 maxFloorB = 1u << ((tileParam - static_cast<SInt32>(hwByte1a)) & 0x3f);

        for (UInt32 face = 0; face < faceCount; face++) {
            UInt8 *faceMip = mip + face * 2;
            UInt32 valA = hwInfo[4] >> (hwByte1a & 0x3f);
            hwByte1a = hwInfo[3] >> (hwByte1a & 0x3f);

            if (baseLevel <= lastLevel) {
                UInt32 fullMipFlags = *reinterpret_cast<UInt8 *>(mip + 0x15);
                for (UInt32 level = baseLevel; level <= lastLevel; level++) {
                    UInt32 tileIndex = face * 0xd + level;
                    UInt8 *tile = hwInfoBytes + tileIndex * 0x20;
                    UInt32 *dst = record + *reinterpret_cast<UInt16 *>(tile + 0x18);

                    if ((fullMipFlags & 4) != 0) {
                        SInt32 shifted = static_cast<SInt32>(
                            static_cast<UInt32>(*reinterpret_cast<UInt16 *>(hwInfoBytes + 0x16))) >> (level & 0x3f);
                        UInt32 clamped = 1u << tileMode;
                        if (static_cast<SInt32>(clamped) < shifted) clamped = static_cast<UInt32>(shifted);
                        /* real: the raw decompile expresses this via a comma
                         * operator with an embedded side effect (`iVar12 = 1,
                         * cond`) inside an `||`, which nets out to exactly
                         * this once traced by hand: iVar12 (-> bit 2 of
                         * fullMipFlags below) is 1 when BOTH of these hold,
                         * 0 if either fails. */
                        bool gate = (hwByte1a >= (maxFloorB << 3)) && (clamped >= (1u << (tileMode + 3)));
                        fullMipFlags = (gate ? 4u : 0u) | (fullMipFlags & ~4u);
                    }

                    UInt16 loadedBits = *reinterpret_cast<UInt16 *>(faceMip + 0x28);
                    UInt16 dirtyBits = *reinterpret_cast<UInt16 *>(faceMip + 0x1c);
                    if (((static_cast<UInt32>(dirtyBits) & ~static_cast<UInt32>(loadedBits)) >> (level & 0x3f) & 1) == 0) {
                        UInt32 repeatCount = *reinterpret_cast<UInt16 *>(tile + 0x42);
                        *dst = ((repeatCount * 0x1d) - 2) * 0x10000u | 0xc0001000u;
                    } else {
                        SInt32 xBase = *reinterpret_cast<SInt32 *>(tile + 0x44);
                        SInt32 yBase = *reinterpret_cast<SInt32 *>(tile + 0x48);
                        *dst = 0x138a;
                        UInt32 repeatCount = *reinterpret_cast<UInt16 *>(tile + 0x42);
                        for (UInt32 rep = 0; rep < repeatCount; rep++) {
                            dst[1] = static_cast<UInt32>(yBase + yOffset);
                            dst[3] = ((hwByte1a >> 1) & 0x1fffu) << 1 |
                                     ((fullMipFlags >> 3) & 3u) << 0x11 |
                                     ((fullMipFlags >> 2) & 1u) << 0x10 |
                                     (dst[3] & 0xffe0c001u);
                            UInt8 hwByte1b = hwInfoBytes[0x1b];
                            dst[9] = ((valA - 1) & 0x3fffu) | (dst[9] & 0xffffc000u);
                            dst[5] = (static_cast<UInt32>(xBase + tileXBase) & 0xffffffe0u) | (hwByte1b & 3u);
                            dst += 0x1d;
                            xBase += *reinterpret_cast<SInt32 *>(tile + 0x4c);
                            yBase += *reinterpret_cast<SInt32 *>(tile + 0x50);
                        }
                    }

                    /* real per-level recurrence - see header comment's
                     * caveat about this not being independently
                     * re-verified against raw disassembly. */
                    UInt32 halfB = hwByte1a >> 1;
                    hwByte1a = valA >> 1;
                    valA = (maxFloorA < hwByte1a) ? hwByte1a : maxFloorA;
                    hwByte1a = (maxFloorB < halfB) ? halfB : maxFloorB;
                }
            }
            *reinterpret_cast<UInt16 *>(faceMip + 0x28) |= *reinterpret_cast<UInt16 *>(faceMip + 0x1c);
        }

        finalDwordCount = hwInfo[2];
        *reinterpret_cast<UInt32 *>(accel + 0xb90) = 1; /* CONFIRMED CROSS-REFERENCE: the "mid-pageoff" flag get_texture/submit_context_buffer both reference - see header comment. */
    }

    UInt32 paddedCount = finalDwordCount;
    if ((finalDwordCount & 1) != 0) {
        paddedCount = finalDwordCount + 1;
        record[finalDwordCount] = 0x80000000u;
    }
    *reinterpret_cast<UInt32 *>(accel + 0x704) += paddedCount * 4;
    *reinterpret_cast<UInt32 *>(accel + 0x71c) += payloadByteLen;

    UInt32 submitResult;
    if (static_cast<SInt32>(hwInfo[8]) < 0) {
        submitResult = accelerator->submit_buffer(record, *reinterpret_cast<UInt32 *>(tex + 4) + 0xa00, paddedCount);
    } else {
        submitResult = accelerator->submit_buffer(
            record, hwInfo[1] * 4 + *reinterpret_cast<UInt32 *>(tex + 4) + 0xa00, paddedCount);
    }
    *reinterpret_cast<UInt32 *>(mip + 0xc) = submitResult;

    if (discriminant == 7) {
        /* real: two pointer indirections deep through the type's inner
         * transfer buffer - arithmetic transcribed faithfully, exact
         * struct identity UNKNOWN (see header comment). */
        UInt8 *inner = *reinterpret_cast<UInt8 **>(tex + 0x58);
        UInt8 *innerTarget = *reinterpret_cast<UInt8 **>(inner + 0x14);
        *reinterpret_cast<UInt32 *>(innerTarget + 8) = *reinterpret_cast<UInt32 *>(mip + 0xc);
    }

    typedef void (*ReleaseFn)(void *);
    (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(memHandle) + (0x18 / 4)))(memHandle);
}
