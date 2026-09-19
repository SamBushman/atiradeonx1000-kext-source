/*
 * ATIRadeonX1000_TexturePageoff.cpp
 *
 * RESOLVED (issue #30): the four real functions `ATIRadeonX1000::
 * pageoff_dirty_texture` (already resolved, `IOATIR500GLContext_
 * PageOffTexture.cpp`) branches into - `pageoff_linear_buffer` (real
 * addr 0x217a0), `pageoff_dirty_texture_with_gpu` (0x210f0),
 * `prepare_texture_for_pageoff_with_cpu` (0x20d30), and
 * `pageoff_dirty_texture_with_cpu` (0x1e500) - grouped in one file given
 * how tightly this real subsystem's four members share structure.
 *
 * Two real, disassembly-CONFIRMED shared building blocks factor out
 * cleanly (see the static helpers below):
 *
 * - `EnsureGARTMapped`/`ResolveKindAndEnsureMapped`: `pageoff_linear_
 *   buffer` and `pageoff_dirty_texture_with_gpu` open with an IDENTICAL
 *   real prologue - the texture's own `+0x20` "kind" byte is `3` (plain)
 *   or `7` (has a real companion `VendorTransferBuffer` at `+0x58`,
 *   itself refcounted at `+0xe` around this call), and either way calls
 *   the real vtable `+0x5a8` slot (`addTransferToGART`, already RESOLVED
 *   elsewhere) followed by a real check of `freeToAllocGART`'s own
 *   return, retrying once (with a `waitForTimeStamp`) on failure. The
 *   raw decompile shows `addTransferToGART`'s OWN "return value" being
 *   checked here too - this project has ALREADY established, from a
 *   full decompile of `addTransferToGART` and everything it calls
 *   (`Headers/IOATIR500Accelerator.h`'s own `addToGART` note), that this
 *   is a real calling-convention artifact with no meaningful signal (the
 *   function and everything beneath it are genuinely `void`) - the
 *   "conservative unconditional fix" already applied to `map_transfer_
 *   to_GART` is reapplied here: `addTransferToGART` is called
 *   unconditionally, and only `freeToAllocGART`'s own real `bool` return
 *   gates the retry.
 * - `ResolveTileShiftFactors`: `pageoff_dirty_texture_with_gpu` and
 *   `prepare_texture_for_pageoff_with_cpu` (and, in a slightly
 *   restructured but numerically identical form, `pageoff_dirty_
 *   texture_with_cpu`) all derive the same real pair of log2-scaled
 *   "tile shift" factors from the texture's own mip array's `+0x15`
 *   byte and a real per-`ATITextureBufferHeader` format-selector byte
 *   (`+0x1a`) via an identical real branch structure - real HARDWARE
 *   MEANING (almost certainly a compressed/tiled-texture block-size
 *   selection) not independently confirmed against R5xx register
 *   documentation, transcribed for its exact real bit-level behavior
 *   only.
 *
 * `ATITextureBufferHeader` remains an intentionally OPAQUE type in this
 * project (`Headers/ATIRadeonX1000.h`) - these four functions are, by a
 * wide margin, the densest real consumers of its own internal layout
 * this project has decompiled, but formalizing a full struct for it was
 * judged not worth the real risk of a transcription error given how
 * many of its fields' real roles remain genuinely unclear beyond their
 * bit position (tile/mip geometry tables, format selectors, PM4 scratch
 * buffer regions) - every access below is a raw, disassembly-consistent
 * byte offset instead, same as every other opaque type in this project.
 *
 * Confidence: CONFIRMED for control flow and every real offset in
 * `pageoff_linear_buffer` (independently cross-checked against raw PPC
 * disassembly in full, given it's the simplest of the four and a good
 * proxy for validating the shared prologue helpers above).
 * `pageoff_dirty_texture_with_gpu`/`prepare_texture_for_pageoff_with_cpu`/
 * `pageoff_dirty_texture_with_cpu` are CONFIRMED for control flow and
 * every real offset AS GIVEN BY Ghidra's own C decompile (trustworthy
 * per the same opaque-type byte-scaling precedent independently
 * verified for their simpler sibling above) but were NOT independently
 * re-traced against raw disassembly instruction-by-instruction given
 * their sheer size - real per-field HARDWARE semantics beyond "this bit
 * pattern feeds this PM4 register field" are UNKNOWN rather than
 * guessed. `pageoff_dirty_texture_with_cpu` additionally does real raw
 * MMIO register access with explicit PowerPC cache/memory-barrier
 * intrinsics (`dataCacheBlockStore`/`dataCacheBlockFlush`/`sync`/
 * `instructionSynchronize`/`enforceInOrderExecutionIO`) - real, standard
 * Apple/PPC kernel primitives, not previously used anywhere else in this
 * project. No C++ compiler was available in the sandboxed environment
 * this was written in (same standing limitation as every other file in
 * this project).
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h" /* dcbf/dcbst/eieio/isync, see that header */

extern "C" UInt32 global_dummy_read_back_a_register; /* real: a genuine global this function reads INTO after a register write - a real "force the write to actually land before continuing" pattern, distinct from the explicit barrier intrinsics also present */

extern "C" void FUN_000210d8(void *dest, void *src, UInt32 size) asm("_memmove"); /* RESOLVED, issue #50 (live kxld-resolved /dev/kmem read) */
extern "C" void FUN_0001eb18(void *dest, SInt32 byteOffset, UInt32 byteCount) asm("_memmove"); /* RESOLVED, issue #50 - same real target as FUN_000210d8; the real second argument (`byteOffset`, an SInt32 here rather than a pointer type) is passed through unchanged - this project's own prior "running byte offset" reading of this parameter is presumably really a raw VRAM-mapped address the caller already computed, not a plain relative offset, though that caller-side semantic question is unchanged by this linkage fix. */
extern "C" int kernelTaskRef asm("_kernel_task"); /* kernel_task pointer value; the Ghidra label "_ASICSupportsAGP" hid this real relocation target (issue #58 follow-up) */

namespace {
inline UInt8  &B(void *p, int o)  { return *(reinterpret_cast<UInt8 *>(p) + o); }
inline SInt16 &SH(void *p, int o) { return *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(p) + o); }
inline UInt16 &H(void *p, int o)  { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(p) + o); }
inline SInt32 &SW(void *p, int o) { return *reinterpret_cast<SInt32 *>(reinterpret_cast<UInt8 *>(p) + o); }
inline UInt32 &W(void *p, int o)  { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(p) + o); }

bool EnsureGARTMapped(ATIRadeonX1000 *accel, VendorTransferBuffer *buf) {
    accel->addTransferToGART(buf);
    if (accel->freeToAllocGART(nullptr, nullptr, nullptr, nullptr, nullptr, buf)) {
        return true;
    }
    accel->waitForTimeStamp(W(accel, 0x50) - 1);
    accel->addTransferToGART(buf);
    return accel->freeToAllocGART(nullptr, nullptr, nullptr, nullptr, nullptr, buf);
}

bool ResolveKindAndEnsureMapped(ATIRadeonX1000 *accel, VendorTextureBuffer *texture, UInt8 *outKind) {
    UInt8 *tex = reinterpret_cast<UInt8 *>(texture);
    UInt8 kind = B(tex, 0x20);

    if (kind == 3) {
        if (W(tex, 4) == 0) {
            if (!EnsureGARTMapped(accel, reinterpret_cast<VendorTransferBuffer *>(texture))) {
                return false;
            }
            kind = B(tex, 0x20);
        }
    } else if (kind == 7) {
        VendorTransferBuffer *aux = *reinterpret_cast<VendorTransferBuffer **>(tex + 0x58);
        UInt8 *auxBytes = reinterpret_cast<UInt8 *>(aux);
        if (W(auxBytes, 4) == 0) {
            if (!EnsureGARTMapped(accel, aux)) {
                return false;
            }
        }
        UInt32 hasBacking = W(tex, 4);
        SInt16 refcount = SH(auxBytes, 0xe) + 1;
        SH(auxBytes, 0xe) = refcount;
        if (hasBacking == 0) {
            if (!EnsureGARTMapped(accel, reinterpret_cast<VendorTransferBuffer *>(texture))) {
                SH(auxBytes, 0xe) -= 1;
                return false;
            }
            refcount = SH(auxBytes, 0xe);
        }
        kind = B(tex, 0x20);
        SH(auxBytes, 0xe) = refcount - 1;
    } else {
        return false;
    }

    *outKind = kind;
    return true;
}

/* real: derives the same two log2-scaled "tile shift" factors
   (`shiftA`/`shiftB`) and format-selector byte (`fmtSel`) that
   `pageoff_dirty_texture_with_gpu`/`prepare_texture_for_pageoff_with_cpu`
   each independently (but identically) compute - see this file's own
   header comment. */
void ResolveTileShiftFactors(UInt8 *mip, UInt8 *hw, int &shiftA, int &shiftB, UInt32 &fmtSel) {
    UInt8 shiftedFmt = B(mip, 0x15) >> 3;
    shiftA = -(shiftedFmt & 3);
    fmtSel = B(hw, 0x1a);
    bool zeroSel;
    if (shiftedFmt & 2) {
        zeroSel = true;
    } else if (shiftA < 0) {
        zeroSel = (fmtSel == 0);
    } else {
        zeroSel = false;
    }
    if (fmtSel < 4) {
        if (zeroSel) { shiftB = 2; shiftA = 3; }
        else         { shiftB = 1; shiftA = 4; }
    } else {
        shiftB = 0;
        shiftA = 5;
    }
}
} // namespace

UInt32 ATIRadeonX1000::pageoff_linear_buffer(VendorTextureBuffer *texture, ATITextureBufferHeader *hwInfo) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *tex = reinterpret_cast<UInt8 *>(texture);
    UInt8 *hw = reinterpret_cast<UInt8 *>(hwInfo);

    UInt8 kind;
    if (!ResolveKindAndEnsureMapped(this, texture, &kind)) {
        return 0;
    }

    UInt32 poolSizeClass = W(tex, 0x50);
    UInt32 companionOrBackingValue;
    if (kind == 7) {
        VendorTransferBuffer *aux = *reinterpret_cast<VendorTransferBuffer **>(tex + 0x58);
        companionOrBackingValue = W(aux, 4);
    } else {
        companionOrBackingValue = W(tex, 4);
    }

    UInt32 accelAccum = W(self, 0x758);
    UInt8 *mip = *reinterpret_cast<UInt8 **>(tex + 0x14);
    UInt32 stampDelta = waitForTimeStamp(W(mip, 0xc));
    UInt32 accelField0x8a4 = W(self, 0x8a4);
    W(self, 0x758) = accelAccum + stampDelta;

    UInt8 *pkt = hw + 0xa00;
    UInt32 mipIndexBase = H(hw, 0x40);
    UInt32 sizeA = W(hw, 0x44);
    UInt32 sizeB = W(hw, 0x48);
    UInt32 idx1 = mipIndexBase + 4;
    UInt32 idx2 = mipIndexBase + 7;
    W(pkt, mipIndexBase * 4) = 0x80000000;
    UInt32 transferBufferFlagVal = W(tex, 0x48);
    W(pkt, idx1 * 4) = sizeB + transferBufferFlagVal;
    W(pkt, idx2 * 4) = companionOrBackingValue + accelField0x8a4 + sizeA;

    if (H(hw, 0x42) > 1) {
        UInt32 count = H(hw, 0x42) - 1;
        UInt32 strideA = W(hw, 0x50);
        UInt32 strideB = W(hw, 0x4c);
        do {
            mipIndexBase += 0x12; idx1 += 0x12; idx2 += 0x12;
            sizeA += strideB;
            sizeB += strideA;
            W(pkt, mipIndexBase * 4) = 0x80000000;
            W(pkt, idx1 * 4) = sizeB + transferBufferFlagVal;
            W(pkt, idx2 * 4) = companionOrBackingValue + accelField0x8a4 + sizeA;
            count--;
        } while (count != 0);
    }

    UInt8 *mip2 = *reinterpret_cast<UInt8 **>(tex + 0x14);
    H(mip2, 0x1c) |= H(mip2, 0x28);

    UInt32 dwordCount = W(hw, 0);
    if (dwordCount & 1) {
        W(pkt, dwordCount * 4) = 0x80000000;
        dwordCount += 1;
    }
    W(self, 0x704) += dwordCount * 4;
    W(self, 0x720) += poolSizeClass;

    UInt8 *mip3 = *reinterpret_cast<UInt8 **>(tex + 0x14);
    UInt32 tag = submit_buffer(reinterpret_cast<UInt32 *>(pkt), W(tex, 4) + 0xa00, dwordCount);
    W(mip3, 0xc) = tag;

    if (kind == 7) {
        VendorTransferBuffer *aux = *reinterpret_cast<VendorTransferBuffer **>(tex + 0x58);
        W(*reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(aux) + 0x14), 8) =
            W(*reinterpret_cast<UInt8 **>(tex + 0x14), 0xc);
    }

    UInt32 finalTag = W(*reinterpret_cast<UInt8 **>(tex + 0x14), 0xc);
    W(hw, 0x20) |= 0x10000000;
    W(hw, 0x1c) = finalTag;
    return 1;
}

UInt32 ATIRadeonX1000::pageoff_dirty_texture_with_gpu(VendorTextureBuffer *texture, ATITextureBufferHeader *hwInfo) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *tex = reinterpret_cast<UInt8 *>(texture);
    UInt8 *hw = reinterpret_cast<UInt8 *>(hwInfo);

    UInt8 *mip0 = *reinterpret_cast<UInt8 **>(tex + 0x14);
    UInt32 mipStart = B(mip0, 0x17);
    UInt8 faceCount = B(mip0, 0x34);
    UInt32 mipEnd = (mipStart + B(mip0, 0x35)) - 1;

    UInt8 kind;
    if (!ResolveKindAndEnsureMapped(this, texture, &kind)) {
        return 0;
    }

    UInt32 poolSizeClass = W(tex, 0x50);
    UInt32 companionOrBackingValue;
    if (kind == 7) {
        VendorTransferBuffer *aux = *reinterpret_cast<VendorTransferBuffer **>(tex + 0x58);
        companionOrBackingValue = W(aux, 4);
    } else {
        companionOrBackingValue = W(tex, 4);
    }

    UInt32 accelAccum = W(self, 0x758);
    UInt8 *mip = *reinterpret_cast<UInt8 **>(tex + 0x14);
    UInt32 stampDelta = waitForTimeStamp(W(mip, 0xc));
    UInt32 accelField0x8a4 = W(self, 0x8a4);
    W(self, 0x758) = accelAccum + stampDelta;

    UInt8 *pkt = hw + W(hw, 4) * 4 + 0xa00;
    W(pkt, 0x2c) = W(self, 0xb74);

    mip = *reinterpret_cast<UInt8 **>(tex + 0x14);
    UInt32 transferBufferFlagVal = W(tex, 0x48);

    int shiftA, shiftB;
    UInt32 coord;
    ResolveTileShiftFactors(mip, hw, shiftA, shiftB, coord);

    UInt32 face = 0;
    UInt32 pass23 = 1u << ((shiftA - static_cast<SInt32>(coord)) & 0x3f);
    UInt32 pass22 = 0x20u >> (coord & 0x3f);

    if (faceCount != 0) {
        for (;;) {
            UInt32 mipFlags = B(mip, 0x15);
            UInt32 dimB = W(hw, 0x10) >> (coord & 0x3f);
            coord = W(hw, 0xc) >> (coord & 0x3f);
            if (mipStart <= mipEnd) {
                UInt8 *tileRec = hw + mipStart * 0x20 + face * 0x1a0 + 0x40;
                UInt32 level = mipStart;
                do {
                    UInt8 *outRec = pkt + H(tileRec, 0x18) * 4;
                    if (mipFlags & 4) {
                        SInt32 v5 = static_cast<SInt16>(H(hw, 0x16)) >> (level & 0x3f);
                        SInt32 v9 = 1 << shiftB;
                        if (v9 < v5) v9 = v5;
                        int gate;
                        if ((coord < (pass23 << 3)) || (v9 < static_cast<SInt32>(1u << (shiftB + 3)))) {
                            gate = 0;
                        } else {
                            gate = 1;
                        }
                        mipFlags = (gate << 2) | (mipFlags & 0xfffffffb);
                    }
                    SInt32 recA = SW(tileRec, 4);
                    SInt32 recB = SW(tileRec, 8);
                    UInt32 half = dimB >> 1;
                    W(outRec, 0) = 0x138a;
                    if (SH(tileRec, 2) != 0) {
                        SInt32 n = 0;
                        do {
                            UInt32 flagsWord = W(outRec, 0xc);
                            n++;
                            SW(outRec, 4) = recA + companionOrBackingValue + accelField0x8a4;
                            W(outRec, 0xc) = flagsWord & 0xfff8ffff;
                            UInt8 tilingBits = B(hw, 0x1b);
                            W(outRec, 0x24) = ((coord - 1) & 0x3fff) | (W(outRec, 0x24) & 0xffffc000);
                            W(outRec, 0x14) = ((static_cast<UInt32>(recB) + transferBufferFlagVal) & 0xffffffe0) |
                                               ((mipFlags >> 3 & 3) << 3) | ((mipFlags >> 2 & 1) << 2);
                            W(outRec, 0xc) = ((half & 0x1fff) << 1) | ((tilingBits & 3) << 0x13) | (flagsWord & 0xffe0c001);
                            outRec += 0x74;
                            recA += SW(tileRec, 0xc);
                            recB += SW(tileRec, 0x10);
                        } while (n < static_cast<SInt16>(H(tileRec, 2)));
                    }
                    UInt32 t1 = pass22;
                    if (pass22 < half) t1 = half;
                    UInt32 t2 = coord >> 1;
                    coord = pass23;
                    if (pass23 < t2) coord = t2;
                    (void)t1; /* real: computed but its own result (uVar19) is never read again before being overwritten at the top of the next tile iteration - matches the real decompile exactly */
                    level++;
                    tileRec += 0x20;
                } while (level <= mipEnd);
            }
            face++;
            if (faceCount <= face) break;
            mip = *reinterpret_cast<UInt8 **>(tex + 0x14);
            coord = B(hw, 0x1a);
        }
    }

    UInt32 dwordCount = W(hw, 8);
    W(self, 0xb90) = 1;
    W(self, 0x78) = 0;
    if (dwordCount & 1) {
        W(pkt, dwordCount * 4) = 0x80000000;
        dwordCount += 1;
    }
    W(self, 0x704) += dwordCount * 4;
    W(self, 0x720) += poolSizeClass;

    UInt8 *mipFinal = *reinterpret_cast<UInt8 **>(tex + 0x14);
    UInt32 tag = submit_buffer(reinterpret_cast<UInt32 *>(pkt), W(hw, 4) * 4 + W(tex, 4) + 0xa00, dwordCount);
    W(mipFinal, 0xc) = tag;

    if (kind == 7) {
        VendorTransferBuffer *aux = *reinterpret_cast<VendorTransferBuffer **>(tex + 0x58);
        W(*reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(aux) + 0x14), 8) =
            W(*reinterpret_cast<UInt8 **>(tex + 0x14), 0xc);
    }

    UInt32 finalTag = W(*reinterpret_cast<UInt8 **>(tex + 0x14), 0xc);
    W(hw, 0x20) |= 0x10000000;
    W(hw, 0x1c) = finalTag;
    return 1;
}

UInt32 ATIRadeonX1000::prepare_texture_for_pageoff_with_cpu(VendorTextureBuffer *texture, ATITextureBufferHeader *hwInfo) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *tex = reinterpret_cast<UInt8 *>(texture);
    UInt8 *hw = reinterpret_cast<UInt8 *>(hwInfo);

    UInt32 transferBufferFlagVal = W(tex, 0x48);
    if (transferBufferFlagVal < W(self, 0x84c)) {
        return 1;
    }
    UInt8 kind0 = B(tex, 0x20);
    if (kind0 != 3 && kind0 != 7) {
        return 0;
    }

    UInt32 poolSizeClass = W(tex, 0x50);
    /* real: `GLKMemoryElement aGStack_68[28]` in the raw decompile - a
       real stack-local BACKUP of the texture's own live `+0x40`
       GLKMemoryElement (opaque, real size unknown) taken via a real
       16-byte copy BEFORE that live field is overwritten by the
       `alloc` call below, then handed to `dealloc` afterward - a real
       "atomically replace this texture's VRAM element with a fresh
       CPU-visible one, then free the old one via this snapshot" pattern.
       Modeled as a raw byte buffer sized to the one real confirmed copy
       amount (16 bytes) rather than Ghidra's own guessed element count,
       since GLKMemoryElement's true size remains genuinely unknown
       elsewhere in this project too. */
    UInt8 scratch[0x10];
    FUN_000210d8(scratch, tex + 0x40, 0x10);
    ATIR500Memory *mem = *reinterpret_cast<ATIR500Memory **>(self + 0x7c);
    bool allocOk = mem->alloc(reinterpret_cast<GLKMemoryElement *>(tex + 0x40), poolSizeClass, 0x1000, 0, W(self, 0x84c)) != 0;
    if (!allocOk) {
        if (freeToAllocTextureCPUVisibleVRAM(texture, poolSizeClass) == 0) {
            return 0;
        }
    }

    UInt32 transferBufferFlagVal2 = W(tex, 0x48);
    UInt8 *pkt = hw + W(hw, 4) * 4 + 0xa00;
    W(pkt, 0x2c) = W(self, 0xb74);

    UInt8 *mip = *reinterpret_cast<UInt8 **>(tex + 0x14);
    UInt32 mipFlags = B(mip, 0x15);
    UInt32 mipStart = B(mip, 0x17);
    UInt8 faceCount = B(mip, 0x34);
    UInt32 mipEnd = (mipStart + B(mip, 0x35)) - 1;

    int shiftA, shiftB;
    UInt32 coord;
    ResolveTileShiftFactors(mip, hw, shiftA, shiftB, coord);

    UInt32 face = 0;
    UInt32 pass23 = 1u << ((shiftA - static_cast<SInt32>(coord)) & 0x3f);

    if (faceCount != 0) {
        for (;;) {
            coord = W(hw, 0xc) >> (coord & 0x3f);
            if (mipStart <= mipEnd) {
                UInt8 *tileRec = hw + mipStart * 0x20 + face * 0x1a0 + 0x40;
                UInt32 level = mipStart;
                do {
                    UInt8 *outRec = pkt + H(tileRec, 0x18) * 4;
                    SInt32 recB = SW(tileRec, 8);
                    W(outRec, 0) = 0x138a;
                    UInt32 half = coord >> 1; /* real: `uVar5 = uVar11 >> 1;` where uVar11 is THIS function's own "coord" at this point, unlike the GPU sibling which used its separate "dimB" - a genuine real difference between the two functions, not a transcription simplification */
                    if (SH(tileRec, 2) != 0) {
                        UInt32 bit16 = (mipFlags >> 2) & 1;
                        UInt32 bits17_18 = (mipFlags >> 3) & 3;
                        SInt32 n = 0;
                        do {
                            n++;
                            SW(outRec, 4) = recB + transferBufferFlagVal2;
                            W(outRec, 0x24) = ((coord - 1) & 0x3fff) | (W(outRec, 0x24) & 0xffffc000);
                            W(outRec, 0xc) = ((half & 0x1fff) << 1) | (bits17_18 << 0x11) | (bit16 << 0x10) |
                                              (W(outRec, 0xc) & 0xffe0c001);
                            W(outRec, 0x14) = (static_cast<UInt32>(recB) + poolSizeClass) & 0xffffffe0u |
                                               (bits17_18 << 3) | (bit16 << 2);
                            outRec += 0x74;
                            recB += SW(tileRec, 0x10);
                        } while (n < static_cast<SInt16>(H(tileRec, 2)));
                    }
                    coord = pass23;
                    if (pass23 < half) coord = half;
                    level++;
                    tileRec += 0x20;
                } while (level <= mipEnd);
            }
            face++;
            if (faceCount <= face) break;
            coord = B(hw, 0x1a);
        }
    }

    UInt32 dwordCount = W(hw, 8);
    W(self, 0xb90) = 1;
    if (dwordCount & 1) {
        W(pkt, dwordCount * 4) = 0x80000000;
        dwordCount += 1;
    }
    W(self, 0x704) += dwordCount * 4;

    UInt8 *mipFinal = *reinterpret_cast<UInt8 **>(tex + 0x14);
    UInt32 tag = submit_buffer(reinterpret_cast<UInt32 *>(pkt), W(hw, 4) * 4 + W(tex, 4) + 0xa00, dwordCount);
    W(mipFinal, 0xc) = tag;

    waitForTimeStamp(W(*reinterpret_cast<UInt8 **>(tex + 0x14), 0xc));
    mem->dealloc(reinterpret_cast<GLKMemoryElement *>(scratch));
    return 1;
}

void ATIRadeonX1000::pageoff_dirty_texture_with_cpu(VendorTextureBuffer *texture, ATITextureBufferHeader *hwInfo) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *tex = reinterpret_cast<UInt8 *>(texture);
    UInt8 *hw = reinterpret_cast<UInt8 *>(hwInfo);

    UInt8 *mip = *reinterpret_cast<UInt8 **>(tex + 0x14);
    UInt32 mipStart = B(mip, 0x17);
    UInt32 mipEnd = (mipStart + B(mip, 0x35)) - 1;
    UInt8 faceCount = B(mip, 0x34);

    sleepForTimeStamp(W(self, 0x50) - 1); /* real: raw vtable +0x558, already-established */

    /* real: finds a free "scratch register triple" slot by scanning the
       low `self[0x990]` bits of a real per-accelerator bitmask
       (`self+0x890`, the SAME real "in-use ID mask" field
       `ATIR500Surface_PrepareCompleteVRAM.cpp` already established,
       reused here for a completely different real purpose - picking one
       of several redundant scratch MMIO register triples so concurrent
       CPU-driven pageoffs don't stomp each other). */
    UInt32 limit = B(self, 0x990);
    UInt32 slotIndex = 0;
    if (limit != 0 && (W(self, 0x890) & 1) != 0) {
        UInt32 bit = 0;
        UInt32 remaining = limit;
        for (;;) {
            bit++;
            remaining--;
            if (remaining == 0) { slotIndex = 0; break; }
            if ((W(self, 0x890) & (1u << (bit & 0x3f))) == 0) { slotIndex = bit * 4; break; }
        }
    }

    UInt8 *mmio = *reinterpret_cast<UInt8 **>(self + 0x860);
    SInt32 regOffsetA = (slotIndex + 0x2c3) * 4;
    UInt8 *regA = mmio + regOffsetA;
    UInt8 savedA0 = regA[3], savedA1 = regA[2], savedA2 = regA[1], savedA3 = regA[0];
    SInt32 regOffsetB = (slotIndex + 0x2c1) * 4;
    UInt8 *regB = mmio + regOffsetB;
    UInt8 savedB0 = regB[3], savedB1 = regB[2], savedB2 = regB[1], savedB3 = regB[0];
    SInt32 regOffsetC = (slotIndex + 0x2c2) * 4;
    UInt8 *regC = mmio + regOffsetC;
    UInt8 savedC0 = regC[3], savedC1 = regC[2], savedC2 = regC[1], savedC3 = regC[0];

    int shiftA, shiftB, tileSel;
    {
        UInt8 shiftedFmt = B(mip, 0x15) >> 3;
        shiftA = -(shiftedFmt & 3);
        UInt8 fmtSel = B(hw, 0x1a);
        bool zeroSel;
        if (shiftedFmt & 2) {
            zeroSel = true;
        } else if (shiftA < 0) {
            zeroSel = (fmtSel == 0);
        } else {
            zeroSel = false;
        }
        if (fmtSel < 4) {
            if (zeroSel) { shiftA = 2; tileSel = 3; shiftB = 2; }
            else         { shiftA = 1; tileSel = 4; shiftB = 1; }
        } else {
            shiftA = 0; tileSel = 5; shiftB = 0;
        }
    }

    void *gartHandle = nullptr;
    SInt32 accelAccumDelta = 0;

    if (faceCount != 0) {
        for (UInt32 face = 0; face < faceCount; face++) {
            UInt32 blockW = H(hw, 0x14);
            UInt32 blockH = H(hw, 0x16);
            UInt32 blockD = H(hw, 0x18);
            UInt32 pitch = W(hw, 0xc);
            SInt32 rowBytes = SW(hw, 0x10);

            if (mipStart <= mipEnd) {
                UInt8 *tileRec = hw + (face * 0xd + mipStart) * 0x20 + 0x42;
                UInt32 level = mipStart;
                do {
                    UInt32 blockCount = H(tileRec, 0);
                    if (blockCount != 0) {
                        SInt32 subCount = static_cast<SInt32>(blockH * blockD) / static_cast<SInt32>(blockCount);
                        /* real: the outer loop bound is `blockCount` (tileRec[0],
                           re-read fresh each check in the raw decompile, though
                           it never actually changes) - NOT `subCount`. `subCount`
                           is a separate, inner loop bound used below for the
                           real CPU-copy do-while. Easy to conflate since both
                           ultimately read the same tileRec[0] field. */
                        for (SInt32 sub = 0; sub < static_cast<SInt32>(blockCount); sub++) {
                            UInt8 *cpuPtr;
                            if (B(tex, 0x20) == 7) {
                                /* FIXED (issue #1, first build attempt): added a UInt8*
                                 * cast before the `+ 8` - a bare `void *` doesn't support
                                 * pointer arithmetic in standard C++ (only as a GNU
                                 * extension this exact compiler doesn't allow here). */
                                void *desc = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(*reinterpret_cast<void **>(tex + 0x58)) + 8);
                                typedef void *(*MapFn)(void *, int, int, UInt32, int, int);
                                gartHandle = (*reinterpret_cast<MapFn *>(*reinterpret_cast<void ***>(desc) + (0x14c / 4)))(
                                    desc, kernelTaskRef, 0, 1, 0, 0);
                                if (gartHandle == nullptr) {
                                    return;
                                }
                                typedef void *(*GetPtrFn)(void *);
                                cpuPtr = reinterpret_cast<UInt8 *>((*reinterpret_cast<GetPtrFn *>(
                                    *reinterpret_cast<void ***>(gartHandle) + (0xd0 / 4)))(gartHandle));
                            } else {
                                cpuPtr = hw + SW(tileRec, 2);
                            }
                            cpuPtr += sub * SW(tileRec, 10);
                            SInt32 vramOffset = W(self, 0xe4) + W(tex, 0x48) + SW(tileRec, 6) + sub * SW(tileRec, 0xe);

                            bool tiled;
                            UInt32 tileBits;
                            if ((static_cast<SInt32>(pitch) < (1 << (tileSel + 3))) ||
                                (static_cast<SInt32>(blockH) < (1 << (shiftB + 3))) ||
                                ((B(mip, 0x15) & 4) == 0)) {
                                tiled = false;
                                tileBits = 0;
                            } else {
                                tiled = true;
                                tileBits = 1;
                            }
                            UInt32 modeSel;
                            switch ((shiftB << 1) | tileBits) {
                            case 1: modeSel = 0x10000; break;
                            case 2: modeSel = 0x20000; break;
                            case 3: modeSel = 0x30000; break;
                            case 4: modeSel = 0x60000; break;
                            case 5: modeSel = 0x70000; break;
                            default: modeSel = 0; break;
                            }
                            SInt32 granule = (tiled ? 8 : 1) << shiftA;
                            UInt32 vramBase = vramOffset - W(self, 0xe4);

                            mmio = *reinterpret_cast<UInt8 **>(self + 0x860);
                            W(mmio + regOffsetA, 0) =
                                ((pitch >> 3) << 0x18) | ((pitch >> 3 & 0x1f00) << 8) |
                                ((modeSel | ((B(hw, 0x1b) & 3) << 0x14) | ((B(hw, 0x1b) & 3) << 0x16)) >> 8);
                            enforceInOrderExecutionIO();
                            {
                                UInt32 v = vramBase;
                                W(mmio + regOffsetB, 0) = v * 0x1000000 | ((v & 0xff00) << 8) | ((v >> 8) & 0xff00) | (v >> 0x18);
                            }
                            enforceInOrderExecutionIO();
                            {
                                UInt32 v = (vramBase + granule * pitch * ((subCount + granule - 1) / granule)) - 1;
                                W(mmio + regOffsetC, 0) = v * 0x1000000 | ((v & 0xff00) << 8) | ((v >> 8) & 0xff00) | (v >> 0x18);
                            }
                            enforceInOrderExecutionIO();
                            /* real: the raw decompile reconstructs this dummy value from
                               individually-read bytes in a different lane order than the
                               write above used (an explicit un-byte-swap) - transcribed
                               here as a plain word read instead, since the reconstructed
                               VALUE is provably never used for anything (a real
                               "dummy" read whose only purpose is the read access itself,
                               forcing the write above to actually land on real MMIO
                               hardware before continuing) - the exact bit pattern stored
                               into it cannot affect real behavior either way. */
                            global_dummy_read_back_a_register = W(mmio + regOffsetC, 0);

                            if (subCount >= 1) {
                                UInt32 shiftVal = B(hw, 0x1a);
                                for (SInt32 i = 0; i < subCount; i++) {
                                    FUN_0001eb18(cpuPtr, vramOffset, blockW << (shiftVal & 0x3f));
                                    if ((W(self, 0x98) & 0x80) != 0) {
                                        UInt32 cacheLine = B(self, 0x84);
                                        shiftVal = B(hw, 0x1a);
                                        UInt32 span = (blockW << (shiftVal & 0x3f)) +
                                                      (reinterpret_cast<UInt32>(cpuPtr) & (cacheLine - 1)) - cacheLine;
                                        UInt32 off = 0;
                                        if (static_cast<SInt32>(span) > 0) {
                                            do {
                                                dataCacheBlockStore((reinterpret_cast<UInt32>(cpuPtr) & ~(cacheLine - 1)) + off);
                                                off += cacheLine;
                                            } while (off < span);
                                        }
                                        ppcSync();
                                        instructionSynchronize();
                                        dataCacheBlockFlush((reinterpret_cast<UInt32>(cpuPtr) & ~(cacheLine - 1)) + off);
                                        ppcSync();
                                        instructionSynchronize();
                                    } else {
                                        shiftVal = B(hw, 0x1a);
                                    }
                                    cpuPtr += rowBytes;
                                    vramOffset += pitch;
                                }
                            }
                            accelAccumDelta += subCount * (blockW << (B(hw, 0x1a) & 0x3f));
                        }
                    }
                    if (blockW <= 1 && blockH < 2 && blockD < 2) {
                        break;
                    }
                    if (rowBytes > 0x20) rowBytes >>= 1;
                    if ((1 << tileSel) < static_cast<SInt32>(pitch)) pitch = static_cast<UInt32>(static_cast<SInt32>(pitch) >> 1);
                    if (blockW > 1) blockW >>= 1;
                    if (blockH > 1) blockH >>= 1;
                    if (blockD > 1) blockD >>= 1;
                    level++;
                    tileRec += 0x20;
                } while (level <= mipEnd);
            }
        }
        mmio = *reinterpret_cast<UInt8 **>(self + 0x860);
    }

    W(self, 0x720) += accelAccumDelta;
    W(mmio + regOffsetA, 0) = (savedA3 << 0x18) | (savedA1 << 0x10) | (savedA2 << 8) | savedA0;
    /* NOTE: byte-order intentionally mirrors the raw decompile's own
       reconstruction, which reads back the FOUR saved bytes in a
       different lane order than they were originally captured in -
       transcribed exactly as decompiled rather than "fixed" to a more
       intuitive order, since this project doesn't invent corrections to
       real vendor code. */
    enforceInOrderExecutionIO();
    W(mmio + regOffsetB, 0) = (savedB3 << 0x18) | (savedB1 << 0x10) | (savedB2 << 8) | savedB0;
    enforceInOrderExecutionIO();
    W(mmio + regOffsetC, 0) = (savedC3 << 0x18) | (savedC1 << 0x10) | (savedC2 << 8) | savedC0;
    enforceInOrderExecutionIO();

    if (gartHandle != nullptr) {
        typedef void (*ReleaseFn)(void *);
        (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(gartHandle) + (0x18 / 4)))(gartHandle);
    }
}
