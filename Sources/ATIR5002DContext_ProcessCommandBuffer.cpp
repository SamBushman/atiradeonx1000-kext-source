/*
 * ATIR5002DContext_ProcessCommandBuffer.cpp
 *
 * RESOLVED (issue #7): the 2D context's own embedded command-buffer
 * opcode language, fully transcribed from a complete real decompile
 * (kext offset 0x326d0). Same underlying mechanism as GL's - top-byte
 * opcode dispatch over a `this+0xac+0x1c`-based record stream, self-
 * consuming low-24-bit distance fields, `0x80000000`-sentinel exit
 * write - but real, distinct, much smaller opcode set (confirmed range
 * 0x2-0xe, 0x10-0x13), and small enough (unlike GL/DVD) that the real
 * binary keeps every opcode inline in this ONE function rather than
 * splitting into separate handler functions.
 *
 * Confidence: CONFIRMED for control flow and every field offset/call
 * touched - transcribed directly from the complete real decompile, not
 * summarized or sampled. A handful of shared "convergent goto" targets
 * in the real decompile (reached from two different real opcodes,
 * distinguished only by a leftover comparison-variable value) are
 * expressed here as explicit per-opcode branches instead - behaviorally
 * identical, just not a literal reproduction of that particular
 * compiler artifact. `FUN_000334cc` (a real "ensure GART-mapped"
 * helper, same idiom as GL's FUN_0002a864 and DVD's FUN_0003913c) is
 * called opaquely - not independently decompiled this pass.
 */

#include "../Headers/ATIR5002DContext.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"

inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }

extern void FUN_000334cc(void *transferBuffer);

/*
 * Real, shared "splice into accelerator+0x600/+0x5dc texture list"
 * helper - inlined at four real call sites in the raw decompile,
 * factored out here purely for this reconstruction's own readability
 * (matches the identical real list shape this project already
 * reconstructed for GL - issue #5).
 */
static void spliceIntoTextureList(void *accel, void *node) {
    void *prevNode = U32At(node, 0x24) ? reinterpret_cast<void *>(U32At(node, 0x24)) : nullptr;
    void *nextNode = U32At(node, 0x28) ? reinterpret_cast<void *>(U32At(node, 0x28)) : nullptr;
    U32At(prevNode, 0x28) = reinterpret_cast<UInt32>(nextNode);
    U32At(nextNode, 0x24) = reinterpret_cast<UInt32>(prevNode);
    U32At(node, 0x24) = U32At(accel, 0x600);
    U32At(node, 0x28) = reinterpret_cast<UInt32>(reinterpret_cast<UInt8 *>(accel) + 0x5dc);
    U32At(accel, 0x600) = reinterpret_cast<UInt32>(node);
    void *newPrev = reinterpret_cast<void *>(U32At(node, 0x24));
    U32At(newPrev, 0x28) = reinterpret_cast<UInt32>(node);
}

/*
 * Real, shared "ensure GART-mapped, then splice into accelerator+0x6d0/
 * +0x69c transfer list" helper - same list shape as the texture list
 * above, different real list instance for transfer buffers (matches
 * GL's own get_texture/alloc_and_load_texture - issue #5).
 */
static void spliceIntoTransferList(void *accel, void *node) {
    FUN_000334cc(reinterpret_cast<UInt8 *>(node) + 0x2c);
    void *prevNode = reinterpret_cast<void *>(U32At(node, 0x34));
    void *nextNode = reinterpret_cast<void *>(U32At(node, 0x38));
    U32At(prevNode, 0x38) = reinterpret_cast<UInt32>(nextNode);
    U32At(nextNode, 0x34) = reinterpret_cast<UInt32>(prevNode);
    U32At(node, 0x34) = U32At(accel, 0x6d0);
    U32At(node, 0x38) = reinterpret_cast<UInt32>(reinterpret_cast<UInt8 *>(accel) + 0x69c);
    U32At(accel, 0x6d0) = reinterpret_cast<UInt32>(node);
    void *newPrev = reinterpret_cast<void *>(U32At(node, 0x34));
    U32At(newPrev, 0x38) = reinterpret_cast<UInt32>(node);
}

IOReturn ATIR5002DContext::process_command_buffer(VendorCommandDescriptor *descriptor) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);

    UInt32 result = 0;
    UInt32 byteOffset = 0;      /* real: iVar14 */
    UInt32 recordCount = 0xffffffff; /* real: uVar15 */
    UInt32 *record = reinterpret_cast<UInt32 *>(U32At(self, 0xac) + 0x1c);

    /*
     * Real, shared "flush the pending batch (if any) then reload a
     * texture" sequence - the exact same three-step real pattern
     * (submit_buffer flush, alloc_and_load_image, conditional
     * map_transfer_to_GART) appears at SIX real call sites in this
     * function's raw decompile; factored out here for readability.
     */
    auto reloadTexture = [&](VendorTextureBuffer *texture) {
        if (recordCount != 0) { /* real: literal `!= 0` test, initial 0xffffffff sentinel intentionally not special-cased - matches GL's own established convention */
            U32At(accel, 0x700) += recordCount * 4;
            UInt32 bufBase = byteOffset + U32At(self, 0xac);
            UInt32 bufEnd = byteOffset + U32At(self, 0x9c);
            byteOffset += recordCount * 4;
            U32At(self, 0xa8) = accelerator->submit_buffer(
                reinterpret_cast<UInt32 *>(bufBase + 0x20), bufEnd + 0x20, recordCount);
        }
        recordCount = 0;
        alloc_and_load_image(texture);
        if (U32At(self, 0x9c) == 0) {
            map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(self + 0x98));
        }
    };

    /* Real: flush/clear this+0x114's currently-bound texture. */
    auto releaseLastBound = [&]() {
        if (U32At(self, 0x114) != 0) {
            U32At(reinterpret_cast<void *>(U32At(reinterpret_cast<void *>(U32At(self, 0x114)), 0x14)), 8) =
                U32At(accel, 0x50);
            U32At(self, 0x114) = 0;
        }
    };

    do {
        UInt32 raw = *record;
        UInt32 opcode = raw & 0xff000000u;
        UInt32 distance = raw & 0xffffffu; /* real default consumption - overridden per opcode below */
        bool abortToZero = false;          /* real: LAB_00033420 (recordCount=0, distance=0) */

        switch (opcode) {
        /* Opcode 0x2: sets the function's own overall return value to 1. */
        case 0x02000000u: {
            *record = 0x80000000u;
            result = 1;
            break;
        }

        /* Opcodes 0x3/0x4: real texture-bind family. */
        case 0x03000000u:
        case 0x04000000u: {
            releaseLastBound();
            UInt32 idx = record[1];
            if (idx >= U32At(sharedAllocator, 0x14)) { abortToZero = true; break; }
            UInt8 *tex = *reinterpret_cast<UInt8 **>(reinterpret_cast<UInt8 *>(U32At(sharedAllocator, 0x10)) + idx * 4);
            if (tex == nullptr) { abortToZero = true; break; }

            if (U8At(reinterpret_cast<void *>(U32At(tex, 0x14)), 0x14) != 0) {
                reloadTexture(reinterpret_cast<VendorTextureBuffer *>(tex));
            }
            if (U32At(tex, 0x48) != 0) spliceIntoTextureList(accel, tex);
            if (U32At(tex, 4) != 0) spliceIntoTransferList(accel, tex);

            UInt32 flagsField = U32At(tex, 0x48);
            if (opcode == 0x04000000u) {
                UInt8 hzByte = U8At(reinterpret_cast<void *>(U32At(tex, 0x14)), 0x15);
                *record = 0x1150;
                record[1] = ((static_cast<SInt32>(-((hzByte >> 3) & 3)) >> 0x1c) & 8) |
                            (flagsField & 0xffffffe0u) | (hzByte & 4);
            } else {
                *record = 0x80000000u;
                record[1] = 0x575;
                record[5] = (flagsField >> 10) | ((record[5] & 0x3fc0u) << 16);
            }
            distance = raw & 0xffffffu;
            U32At(self, 0x114) = reinterpret_cast<UInt32>(tex);
            break;
        }

        /* Opcode 0x5: releases the currently-bound texture and writes a plain sentinel. */
        case 0x05000000u: {
            releaseLastBound();
            *record = 0x80000000u;
            distance = raw & 0xffffffu;
            break;
        }

        /* Opcode 0x6: 8-dword sentinel pad, no other real effect. */
        case 0x06000000u: {
            for (int i = 0; i < 8; i++) record[i] = 0x80000000u;
            distance = raw & 0xffffffu;
            break;
        }

        /* Opcodes 0x7/0x8: a second real texture-bind family - sets the
         * pendingWriteQueue dirty bit (mirrors GL's invalidate()), and
         * (unlike 0x3/0x4) only reloads on an actually-dirty texture,
         * otherwise just ensures the transfer-list splice. */
        case 0x07000000u:
        case 0x08000000u: {
            U32At(pendingWriteQueue, 0x1c) |= 1;
            releaseLastBound();
            UInt32 idx = record[1];
            if (idx >= U32At(sharedAllocator, 0x14)) { abortToZero = true; break; }
            UInt8 *tex = *reinterpret_cast<UInt8 **>(reinterpret_cast<UInt8 *>(U32At(sharedAllocator, 0x10)) + idx * 4);
            if (tex == nullptr) { abortToZero = true; break; }

            if (U8At(reinterpret_cast<void *>(U32At(tex, 0x14)), 0x14) == 0) {
                if (U32At(tex, 4) != 0) spliceIntoTransferList(accel, tex);
            } else {
                reloadTexture(reinterpret_cast<VendorTextureBuffer *>(tex));
            }

            UInt32 uVar7 = U32At(tex, 4) + U32At(accel, 0x8a4);
            if (opcode == 0x07000000u) {
                *record = 0x80000000u;
                record[1] = 0x575;
                record[5] = (uVar7 >> 10) | ((record[5] & 0x3fc0u) << 16);
            } else {
                UInt32 uVar6 = record[2];
                UInt8 *mip = reinterpret_cast<UInt8 *>(U32At(tex, 0x14));
                if (record[4] != 0 && record[5] != 0) {
                    UInt32 formatIdx = (record[4] & 0xffu) * 0x1c;
                    UInt32 formatWord = FormatTableLookup_0x0004d2dc(formatIdx);
                    SInt32 base = ((U8At(mip, 0x15) & 0x18) == 0) ? 0 : -static_cast<SInt32>((formatWord >> 8) & 3);
                    SInt32 shiftAmt = (base - static_cast<SInt32>((formatWord >> 0xc) & 7) + 5) & 0x3f;
                    SInt32 shifted = static_cast<SInt32>(record[5]) >> shiftAmt;
                    SInt32 add = shifted << 5;
                    if ((U8At(mip, 0x15) >> 2 & 1) != 0) add = (shifted << 0xc) >> 3;
                    uVar7 += add;
                }
                if (record[3] != 0) uVar7 += record[3];
                record[0] = 0x80000000u; record[1] = 0x80000000u;
                record[2] = 0x80000000u; record[3] = 0x80000000u;
                record[4] = 0x1150;
                record[5] = ((static_cast<SInt32>(-((U8At(mip, 0x15) >> 3) & 3)) >> 0x1c) & 8) |
                            (uVar6 & 3) | (uVar7 & 0xffffffe0u) | (U8At(mip, 0x15) & 4);
            }
            distance = raw & 0xffffffu;
            U32At(self, 0x114) = reinterpret_cast<UInt32>(tex);
            if (tex != nullptr) U32At(reinterpret_cast<void *>(U32At(tex, 0x14)), 8) = U32At(accel, 0x50);
            break;
        }

        /*
         * Opcodes 0x9/0xa: a real "sampler basic write" pair sharing one
         * real per-mip lookup (accel+300, stride 0x78, index clamped
         * against accel+0xcc) - 0xa gets the short/simple 0x1150 write,
         * 0x9 gets the longer sentinel-plus-sampler-state write (the
         * same real output shape opcodes 0x3/0x7 use).
         */
        case 0x09000000u:
        case 0x0a000000u: {
            UInt32 idx = record[1];
            if (idx >= U32At(accel, 0xcc)) idx = 0;
            UInt8 *mip = accel + idx * 0x78 + 300;
            if (opcode == 0x0a000000u) {
                *record = 0x1150;
                UInt32 uVar6 = U32At(mip, 8);
                UInt8 bVar1 = U8At(mip, 0x38);
                record[1] = (uVar6 & 0xffffffe0u) | ((bVar1 & 1) << 2) | ((bVar1 & 6) << 2);
            } else {
                *record = 0x80000000u;
                record[1] = 0x575;
                UInt8 bVar1 = U8At(mip, 0x38);
                UInt16 uVar3 = U16At(mip, 0x18);
                UInt32 uVar6 = U32At(mip, 8);
                UInt32 uVar7 = (bVar1 < 2) ? 0 : 0x80000000u;
                record[5] = uVar7 | (uVar6 >> 10) | ((uVar3 & 0x3fc0u) << 16) | ((bVar1 & 1) << 0x1e);
            }
            distance = raw & 0xffffffu;
            break;
        }

        /*
         * Opcodes 0xb/0xc: same output-shape pair as 0x9/0xa, but the
         * mip record comes from a real find_surface_for_id lookup, with
         * a real alloc_surfaces_keep dance (bits 0/1 of the surface's
         * own state gating separate keep-alloc calls) when a pending
         * write batch needs flushing first.
         */
        case 0x0b000000u:
        case 0x0c000000u: {
            IOATIR500Surface *surface = reinterpret_cast<IOATIR500Surface *>(
                accelerator->find_surface_for_id(record[1]));
            UInt8 *mip;
            if (surface == nullptr) {
                mip = accel + 300;
            } else {
                UInt8 *surf = reinterpret_cast<UInt8 *>(surface);
                UInt32 stateBits = U32At(surf, 0xbf8);
                if ((stateBits & 0x20000000u) == 0) {
                    UInt32 gateBits = U32At(surf, 0xc18);
                    if ((stateBits & gateBits & 3) != 0) {
                        if (recordCount != 0) { /* real: literal `!= 0` test, initial 0xffffffff sentinel intentionally not special-cased - matches GL's own established convention */
                            U32At(accel, 0x700) += recordCount * 4;
                            UInt32 bufBase = byteOffset + U32At(self, 0xac);
                            UInt32 bufEnd = byteOffset + U32At(self, 0x9c);
                            byteOffset += recordCount * 4;
                            U32At(self, 0xa8) = accelerator->submit_buffer(
                                reinterpret_cast<UInt32 *>(bufBase + 0x20), bufEnd + 0x20, recordCount);
                            recordCount = 0;
                            stateBits = U32At(surf, 0xbf8);
                            gateBits = U32At(surf, 0xc18);
                        }
                        if ((gateBits & stateBits & 1) != 0) {
                            surface->alloc_surfaces_keep(boundSurface, nullptr, 0, 1);
                            stateBits = U32At(surf, 0xbf8);
                            gateBits = U32At(surf, 0xc18);
                        }
                        if ((gateBits & stateBits & 2) != 0) {
                            surface->alloc_surfaces_keep(boundSurface, nullptr, 0, 2);
                        }
                        if (U32At(self, 0x9c) == 0) {
                            map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(self + 0x98));
                        }
                    }
                    mip = reinterpret_cast<UInt8 *>(U32At(surf, 0xb70));
                    if (U32At(mip, 8) == 0) mip = accel + 300;
                } else {
                    mip = reinterpret_cast<UInt8 *>(U32At(surf, 0xb70));
                }
            }
            if (opcode == 0x0c000000u) {
                *record = 0x1150;
                UInt32 uVar6 = U32At(mip, 8);
                UInt8 bVar1 = U8At(mip, 0x38);
                record[1] = (uVar6 & 0xffffffe0u) | ((bVar1 & 1) << 2) | ((bVar1 & 6) << 2);
            } else {
                *record = 0x80000000u;
                record[1] = 0x575;
                UInt8 bVar1 = U8At(mip, 0x38);
                UInt16 uVar3 = U16At(mip, 0x18);
                UInt32 uVar6 = U32At(mip, 8);
                UInt32 uVar7 = (bVar1 < 2) ? 0 : 0x80000000u;
                record[5] = uVar7 | (uVar6 >> 10) | ((uVar3 & 0x3fc0u) << 16) | ((bVar1 & 1) << 0x1e);
            }
            distance = raw & 0xffffffu;
            break;
        }

        /*
         * Opcodes 0xd/0xe: same output-shape pair again, mip record
         * from `boundSurface` if bound, else the same fallback-index
         * lookup as 0x11/0x12 below.
         */
        case 0x0d000000u:
        case 0x0e000000u: {
            UInt8 *mip = (boundSurface == nullptr)
                ? (accel + U32At(self, 0x110) * 0x78 + 300)
                : reinterpret_cast<UInt8 *>(U32At(boundSurface, 0xb70));
            if (opcode == 0x0e000000u) {
                *record = 0x1150;
                UInt32 uVar6 = U32At(mip, 8);
                UInt8 bVar1 = U8At(mip, 0x38);
                record[1] = (uVar6 & 0xffffffe0u) | ((bVar1 & 1) << 2) | ((bVar1 & 6) << 2);
            } else {
                *record = 0x80000000u;
                record[1] = 0x575;
                UInt8 bVar1 = U8At(mip, 0x38);
                UInt16 uVar3 = U16At(mip, 0x18);
                UInt32 uVar6 = U32At(mip, 8);
                UInt32 uVar7 = (bVar1 < 2) ? 0 : 0x80000000u;
                record[5] = uVar7 | (uVar6 >> 10) | ((uVar3 & 0x3fc0u) << 16) | ((bVar1 & 1) << 0x1e);
            }
            distance = raw & 0xffffffu;
            break;
        }

        /* Opcode 0x11: real per-mip texture-descriptor register write (0x138a/0x138e family). */
        case 0x11000000u: {
            UInt8 *mip = accel + record[1] * 0x78;
            *record = 0x138a;
            record[1] = U32At(mip, 0x134) & 0xffffffe0u;
            record[2] = 0x138e;
            UInt8 bVar1 = U8At(mip, 0x165);
            UInt8 bVar2 = U8At(mip, 0x167);
            UInt32 uVar6 = (U16At(mip, 0x140) & 0x3ffeu) | ((U8At(mip, 0x164) & 1) << 0x10) |
                           ((U8At(mip, 0x164) & 6) << 0x10);
            record[3] = uVar6 | ((bVar1 & 3) << 0x13) | ((bVar2 & 0xf) << 0x15);
            distance = raw & 0xffffffu;
            break;
        }

        /* Opcode 0x12: same register write as 0x11, mip record from the
         * bound-surface-or-fallback-index lookup instead. */
        case 0x12000000u: {
            UInt8 *mip = (boundSurface == nullptr)
                ? (accel + U32At(self, 0x110) * 0x78 + 300)
                : reinterpret_cast<UInt8 *>(U32At(boundSurface, 0xb70));
            *record = 0x138a;
            record[1] = U32At(mip, 8) & 0xffffffe0u;
            record[2] = 0x138e;
            UInt8 bVar1 = U8At(mip, 0x39);
            UInt8 bVar2 = U8At(mip, 0x3b);
            UInt32 uVar6 = (U16At(mip, 0x14) & 0x3ffeu) | ((U8At(mip, 0x38) & 1) << 0x10) |
                           ((U8At(mip, 0x38) & 6) << 0x10);
            record[3] = uVar6 | ((bVar1 & 3) << 0x13) | ((bVar2 & 0xf) << 0x15);
            distance = raw & 0xffffffu;
            break;
        }

        /* Opcode 0x13: a third real texture-bind family - sets the
         * pendingWriteQueue dirty bit like 0x7/0x8, but writes the
         * 0x138a/0x138e register family like 0x11/0x12. */
        case 0x13000000u: {
            U32At(pendingWriteQueue, 0x1c) |= 1;
            releaseLastBound();
            UInt32 idx = record[1];
            if (idx >= U32At(sharedAllocator, 0x14)) { abortToZero = true; break; }
            UInt8 *tex = *reinterpret_cast<UInt8 **>(reinterpret_cast<UInt8 *>(U32At(sharedAllocator, 0x10)) + idx * 4);
            if (tex == nullptr) { abortToZero = true; break; }

            if (U8At(reinterpret_cast<void *>(U32At(tex, 0x14)), 0x14) == 0) {
                if (U32At(tex, 4) != 0) spliceIntoTransferList(accel, tex);
            } else {
                reloadTexture(reinterpret_cast<VendorTextureBuffer *>(tex));
            }

            UInt32 uVar6 = record[2];
            record[0] = 0x80000000u;
            record[1] = 0x80000000u;
            record[2] = 0x1151;
            UInt8 hzByte = U8At(reinterpret_cast<void *>(U32At(tex, 0x14)), 0x15);
            record[3] = ((static_cast<SInt32>(-((hzByte >> 3) & 3)) >> 0x1c) & 8) | (uVar6 & 3) |
                        ((U32At(tex, 4) + U32At(accel, 0x8a4)) & 0xffffffe0u) | (hzByte & 4);
            distance = raw & 0xffffffu;
            U32At(self, 0x114) = reinterpret_cast<UInt32>(tex);
            if (tex != nullptr) U32At(reinterpret_cast<void *>(U32At(tex, 0x14)), 8) = U32At(accel, 0x50);
            break;
        }

        /* Opcode 0x10: the fourth and last real texture-bind family -
         * same dirty-bit + reload dance as 0x13, but writes the
         * 0x138a/0x138e family into a DIFFERENT record than the one
         * consumed, keyed off record[1] via the same sharedAllocator
         * lookup as 0x3/0x4/0x7/0x8/0x13. */
        case 0x10000000u: {
            U32At(pendingWriteQueue, 0x1c) |= 1;
            UInt32 uVar6 = record[2];
            UInt32 uVar7 = record[3];
            releaseLastBound();
            UInt32 idx = record[1];
            if (idx >= U32At(sharedAllocator, 0x14)) { abortToZero = true; break; }
            UInt8 *tex = *reinterpret_cast<UInt8 **>(reinterpret_cast<UInt8 *>(U32At(sharedAllocator, 0x10)) + idx * 4);
            if (tex == nullptr) { abortToZero = true; break; }

            if (U8At(reinterpret_cast<void *>(U32At(tex, 0x14)), 0x14) == 0) {
                if (U32At(tex, 4) != 0) spliceIntoTransferList(accel, tex);
            } else {
                reloadTexture(reinterpret_cast<VendorTextureBuffer *>(tex));
            }

            *record = 0x138a;
            record[1] = U32At(tex, 0x48) & 0xffffffe0u;
            record[2] = 0x138e;
            UInt8 hzByte = U8At(reinterpret_cast<void *>(U32At(tex, 0x14)), 0x15);
            record[3] = ((static_cast<SInt32>(-((hzByte >> 3) & 3)) >> 0xe) & 0x20000) |
                        (uVar6 & 0x3ffeu) | ((hzByte & 4) << 0xe) | ((uVar7 & 0xfu) << 0x15);
            distance = raw & 0xffffffu;
            U32At(self, 0x114) = reinterpret_cast<UInt32>(tex);
            if (tex != nullptr) U32At(reinterpret_cast<void *>(U32At(tex, 0x14)), 8) = U32At(accel, 0x50);
            break;
        }

        default:
            /* Real: an unrecognized opcode value is a plain pass-through
             * (LAB_00032f54) - just consumes the record's own natural
             * distance, no other effect. This is DISTINCT from the
             * bounds-check-failure abort above (LAB_00033420, which
             * resets the whole accumulated record count to zero) -
             * confirmed by checking every real goto site in the raw
             * decompile: only the three real texture/surface lookup
             * failures above ever reach LAB_00033420; every other
             * "opcode not matched at this branch" path reaches
             * LAB_00032f54 instead. */
            break;
        }

        if (abortToZero) {
            recordCount = 0;
            distance = 0;
        }

        recordCount += distance;
        record += distance;
        if (distance == 0) {
            if ((recordCount & 1) != 0) {
                *record = 0x80000000u;
                record += 1;
                recordCount += 1;
            }
            descriptor->pendingBufferStart = reinterpret_cast<void *>(byteOffset + U32At(self, 0xac) + 0x20);
            descriptor->pendingBufferOffset = byteOffset + U32At(self, 0x9c) + 0x20;
            descriptor->pendingDwordCount = recordCount;
            descriptor->finalRecordCursor = record;
            return static_cast<IOReturn>(result);
        }
    } while (true);
}
