/*
 * ATIR500Surface_SubmitFlipBuffer.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): `ATIR500Surface::
 * submit_flip_buffer`'s real body, real addr 0x3e5c0 - the concrete
 * subclass override of the base class's own confirmed-placeholder
 * `+0x5e0` vtable slot (see IOATIR500Surface.h's own note - the base
 * is now pure virtual). Real caller: `resetFullScreen`
 * (Sources/ATIR500Surface_ResetFullScreen.cpp).
 *
 * This is the real "submit a PM4 buffer-swap/flip command stream"
 * path - the most complex single function this pass decompiled. It
 * advances a 4-entry per-surface ring of pre-built swap-buffer records
 * (the same real ring this project's own `dealloc_surface`/`shape_surface`
 * already established, stride 0x1c, base `this+0xc3c`), allocates a
 * fresh slave swap-buffer set on demand, copies a real 8-dword PM4
 * template header into the record's own scratch buffer, patches in a
 * real HyperZ/tiling-config packet when a texture parameter (`param3`)
 * is supplied, then appends a real, variable-length sequence of
 * register-write packets (surface pitch/tiling-state pairs for up to
 * two real render targets, a real "generation stamp" triple, and a
 * real HyperZ-clear-color pair) before submitting the whole thing via
 * `ATIRadeonX1000::submit_buffer`.
 *
 * One real ambiguity, flagged honestly rather than guessed at: several
 * sites read `param_2[param_1 + 0xdb6]` in the raw decompile, where
 * `param_2` is a real `IOATIR500GLContext*` - this cannot be genuine
 * pointer-array indexing (an `IOATIR500GLContext` object is nowhere
 * near `this+0xdb6` bytes in size), and no other real field in this
 * project has ever been read this way. This matches this project's own
 * already-documented "int*-scaling trap" Ghidra artifact category
 * (see reference_ppc_kext_decompile_techniques) - modeled here as a
 * real byte flag at the fixed absolute offset `this+0xdb6`
 * (unrelated to `param_2`'s own value beyond the null-check gating
 * each of these sites), the reading that makes every surrounding use
 * self-consistent (each site tests it as a boolean gate, matching a
 * real "some GL context is currently bound to this surface" flag).
 *
 * Confidence: CONFIRMED for the real PM4 template constants, real
 * struct offsets, and overall control flow (direct Ghidra decompile of
 * the real kext). The `param_2[this+0xdb6]` sites are the one real,
 * disclosed uncertainty - everything else transcribed exactly as
 * decompiled, preserving the raw control flow (including its own
 * forward jumps) rather than restructured, to minimize transcription
 * risk in a function this size.
 */

#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000Registers.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline SInt16 &S16At(void *base, int offset) { return *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

void ATIR500Surface::submit_flip_buffer(UInt32 id, IOATIR500GLContext *context, UInt32 flag) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = *reinterpret_cast<UInt8 **>(self + 0xd50);

    if (S16At(self, 0xdb4) != 0) {
        U32At(accel, 0x78) = 0;
    }
    if (U32At(self, 0xd54) != flag) {
        U32At(self, 0xd54) = flag;
        UInt8 *slotRec = self + static_cast<UInt32>(reinterpret_cast<intptr_t>(context)) * 0x94 + 0xc34;
        U32At(slotRec, 0x1c) |= 1;
    }

    UInt8 *ctxBase = self + static_cast<UInt32>(reinterpret_cast<intptr_t>(context)) * 0x94;
    VendorTransferBuffer *buffer;
    UInt32 *record;
    UInt32 opIdx;
    UInt8 *accelBase;

    if ((U32At(*reinterpret_cast<void **>(ctxBase + 0xc34), 0x1c) & 1) == 0) {
        UInt8 *slot = ctxBase + U16At(ctxBase, 0xcae) * 0x1c;
        buffer = reinterpret_cast<VendorTransferBuffer *>(slot + 0xc3c);
        if (U32At(slot, 0xc44) == 0 &&
            allocAllSlaveSwapBuffers(reinterpret_cast<UInt32>(context), U32At(ctxBase, 0xcb0)) == 0) {
            return;
        }
        goto submit;
    }

    {
        UInt16 slotIdx = static_cast<UInt16>((U16At(ctxBase, 0xcae) + 1) & 3);
        U16At(ctxBase, 0xcae) = slotIdx;
        UInt8 *slot = ctxBase + slotIdx * 0x1c;
        buffer = reinterpret_cast<VendorTransferBuffer *>(slot + 0xc3c);
        if (U32At(slot, 0xc44) == 0) {
            if (allocAllSlaveSwapBuffers(reinterpret_cast<UInt32>(context), U32At(ctxBase, 0xcb0)) == 0) {
                return;
            }
        } else {
            ATIRadeonX1000 *accelObj = *reinterpret_cast<ATIRadeonX1000 **>(self + 0xd50);
            UInt8 *accelBytes = reinterpret_cast<UInt8 *>(accelObj);
            UInt32 before = U32At(accelBytes, 0x788);
            UInt32 delta = accelObj->waitForTimeStamp(U32At(slot, 0xc4c));
            U32At(accelBytes, 0x788) = before + delta;
        }

        record = *reinterpret_cast<UInt32 **>(slot + 0xc50);
        UInt32 *scratchHeader = *reinterpret_cast<UInt32 **>(ctxBase + 0xc34);
        record[0] = scratchHeader[0];
        record[1] = scratchHeader[1];
        record[2] = scratchHeader[2];
        record[3] = scratchHeader[3];
        record[5] = scratchHeader[5];
        record[7] = scratchHeader[7];
        record[4] = scratchHeader[4];
        record[6] = scratchHeader[6];

        UInt8 *pkt = *reinterpret_cast<UInt8 **>(slot + 0xc50);
        UInt32 *pktW = reinterpret_cast<UInt32 *>(pkt + 0x20);
        pktW[0] = 0xd0b;
        pktW[1] = 5;
        pktW[2] = 0x1393;
        pktW[3] = 10;
        pktW[4] = 0x5c8;
        pktW[5] = 0x30000;

        SInt16 genStamp;
        if (flag == 0) {
            opIdx = 6;
            genStamp = 0;
        } else {
            UInt8 *mipRec = *reinterpret_cast<UInt8 **>(self + U16At(reinterpret_cast<void *>(flag), 0xac) * 4 + 0xb70);
            UInt32 v40 = U32At(mipRec, 0x40);
            UInt16 v20 = U16At(mipRec, 0x20);
            UInt32 v3c = U32At(mipRec, 0x3c);
            UInt32 v08 = U32At(mipRec, 8);
            bool has0f00000 = (v3c & 0xf00000) != 0;
            UInt32 tmp16 = has0f00000 ? (U16At(mipRec, 0x14) / ((v3c >> 0x14) & 0xf)) : 0;
            UInt16 v16 = U16At(mipRec, 0x16);
            UInt32 floor15 = 0x20 / v16;
            if (tmp16 < floor15) tmp16 = floor15;
            UInt8 v38 = U8At(mipRec, 0x38);
            UInt32 bit31 = (v38 < 2) ? 0 : 0x80000000u;
            UInt32 tableOff = static_cast<UInt32>(U8At(mipRec, 0x3a)) * 0x1c;
            UInt32 tmp13 = has0f00000 ? (U16At(mipRec, 0x14) / ((v3c >> 0x14) & 0xf)) : 0;
            if (tmp13 < floor15) tmp13 = floor15;
            /* real: `&DAT_0004d2dc`/`&DAT_0004d2e0` - the SAME real format
             * table this project already reconstructed and exposed via
             * FormatTableLookup_0x0004d2dc/e0 (ATIRadeonX1000Registers.h,
             * issue #14), indexed by the same real per-format byte at
             * `+0x3a` this project already established for that table's
             * own selfIndex field. */
            UInt32 fmtDC = FormatTableLookup_0x0004d2dc(tableOff);
            UInt32 fmtE0 = FormatTableLookup_0x0004d2e0(tableOff);
            pktW[6] = 0x50b;
            pktW[7] = bit31 | ((v08 + v20 * v40) >> 10) | ((tmp16 * v16 * 0x10000) & 0x3fc00000) | (static_cast<UInt32>(v38 & 1) << 0x1e);
            pktW[8] = 0x138a;
            reinterpret_cast<SInt32 *>(pktW)[9] = static_cast<SInt32>(v08);
            pktW[10] = 0x138e;
            pktW[11] = ((fmtE0 >> 1) & 0x1e00000) | ((fmtDC & 0xc00) << 9) | (static_cast<UInt32>(v38 & 6) << 0x10) | (static_cast<UInt32>(v38 & 1) << 0x10) | (tmp13 & 0x3ffe);
            genStamp = S16At(reinterpret_cast<void *>(flag), 0x98);
            opIdx = 0xc;
        }

        accelBase = *reinterpret_cast<UInt8 **>(self + 0xd50);
        bool haveContext = (U8At(self, 0xdb6) != 0); /* real: `param_2[this+0xdb6]` - see file header note */

        U32At(accelBase, 0xb78) = (U32At(accelBase, 0xb78) & 0xffdfffff) | (static_cast<UInt32>(U8At(*reinterpret_cast<void **>(self + 0xb70), 0x38) & 1) << 0x15);
        U32At(accelBase, 0xb78) = (static_cast<UInt32>(U8At(*reinterpret_cast<void **>(self + 0xb70), 0x38) > 1) * 0x100000) | (U32At(accelBase, 0xb78) & 0xffefffff);
        U32At(accelBase, 0xb80) = static_cast<UInt32>(genStamp == 0) | (U32At(accelBase, 0xb80) & 0xfffffffe);

        UInt32 texBits;
        if (!haveContext) {
            texBits = 0;
            U32At(accelBase, 0xb88) &= 0xfeffffff;
        } else {
            texBits = U16At(*reinterpret_cast<void **>(self + 0xb70), 0x14) & 0x3fff;
            U32At(accelBase, 0xb88) = (U32At(accelBase, 0xb88) & 0xfeffffff) | 0x1000000;
            U32At(accelBase, 0xb88) &= 0xfffffeff;
            U32At(accelBase, 0xb88) &= 0xfffeffff;
        }

        U32At(accelBase, 0xb7c) = (U32At(accelBase, 0xb7c) & 0xffdfffff) | (static_cast<UInt32>(U8At(*reinterpret_cast<void **>(self + 0xb70), 0x38) & 1) << 0x15);
        U32At(accelBase, 0xb7c) = (static_cast<UInt32>(U8At(*reinterpret_cast<void **>(self + 0xb70), 0x38) > 1) * 0x100000) | (U32At(accelBase, 0xb7c) & 0xffefffff);
        U32At(accelBase, 0xb84) = static_cast<UInt32>(genStamp == 0) | (U32At(accelBase, 0xb84) & 0xfffffffe);
        if (!haveContext) {
            U32At(accelBase, 0xb8c) &= 0xfeffffff;
        } else {
            texBits = U16At(*reinterpret_cast<void **>(self + 0xb70), 0x14) & 0x3fff;
            U32At(accelBase, 0xb8c) = (U32At(accelBase, 0xb8c) & 0xfeffffff) | 0x1000000;
            U32At(accelBase, 0xb8c) &= 0xfffffeff;
            U32At(accelBase, 0xb8c) &= 0xfffeffff;
        }

        accelBase = *reinterpret_cast<UInt8 **>(self + 0xd50);
        if (U32At(accelBase, 0x894) != 0) {
            U32At(accelBase, 0xb80) = (U32At(accelBase, 0xb80) & 0xfffffffe) | 1;
            accelBase = *reinterpret_cast<UInt8 **>(self + 0xd50);
        }

        bool isRT0 = (context == nullptr);
        if (isRT0 || U32At(accelBase, 0x894) != 0) {
            if (haveContext) {
                pktW[opIdx] = 0x1848;
                pktW[opIdx + 1] = texBits;
                opIdx += 2;
            }
            pktW[opIdx] = 0x1841;
            pktW[opIdx + 1] = U32At(accelBase, 0xb78);
            pktW[opIdx + 2] = 0x1852;
            pktW[opIdx + 3] = U32At(accelBase, 0xb80);
            pktW[opIdx + 4] = 0x1831;
            pktW[opIdx + 5] = U32At(accelBase, 0xb88);
            opIdx += 6;
        }
        bool isRT1 = (reinterpret_cast<intptr_t>(context) == 1);
        if (isRT1 || U32At(accelBase, 0x894) != 0) {
            if (haveContext) {
                pktW[opIdx] = 0x1a48;
                pktW[opIdx + 1] = texBits;
                opIdx += 2;
            }
            pktW[opIdx] = 0x1a41;
            pktW[opIdx + 1] = U32At(accelBase, 0xb7c);
            pktW[opIdx + 2] = 0x1a52;
            pktW[opIdx + 3] = U32At(accelBase, 0xb84);
            pktW[opIdx + 4] = 0x1a31;
            pktW[opIdx + 5] = U32At(accelBase, 0xb8c);
            opIdx += 6;
        }

        UInt32 genValue = U32At(*reinterpret_cast<void **>(self + 0xb70), 8);
        if (isRT0 || U32At(accelBase, 0x894) != 0) {
            pktW[opIdx] = 0x1844;
            pktW[opIdx + 1] = genValue;
            pktW[opIdx + 2] = 0x1844;
            pktW[opIdx + 3] = genValue;
            pktW[opIdx + 4] = 0x1844;
            pktW[opIdx + 5] = genValue;
            UInt32 next = opIdx + 6;
            if (haveContext) {
                pktW[next] = 0x1846;
                pktW[opIdx + 7] = U32At(*reinterpret_cast<void **>(self + 0xb84), 8);
                next = opIdx + 8;
            }
            opIdx = next;
        }
        if (isRT1 || U32At(accelBase, 0x894) != 0) {
            pktW[opIdx] = 0x1a44;
            pktW[opIdx + 1] = genValue;
            pktW[opIdx + 2] = 0x1a44;
            pktW[opIdx + 3] = genValue;
            pktW[opIdx + 4] = 0x1a44;
            pktW[opIdx + 5] = genValue;
            UInt32 next = opIdx + 6;
            if (haveContext) {
                pktW[next] = 0x1a46;
                pktW[opIdx + 7] = U32At(*reinterpret_cast<void **>(self + 0xb84), 8);
                next = opIdx + 8;
            }
            opIdx = next;
        }

        bool wroteHz = false;
        if (U8At(accelBase, 0x9b0) == 0) {
            if (isRT0) {
                pktW[opIdx] = 0x5c8;
                pktW[opIdx + 1] = 1;
                opIdx += 2;
            } else if (isRT1) {
                pktW[opIdx] = 0x5c8;
                pktW[opIdx + 1] = 0x80000001;
                opIdx += 2;
            }
            wroteHz = true;
        } else if (U32At(accelBase + static_cast<UInt32>(reinterpret_cast<intptr_t>(context)) * 0x18, 0xb10) == 0) {
            if (U32At(accelBase, 0x894) != 0) {
                UInt32 hzOff = isRT0 ? 0xb18 : 0xb00;
                if (U32At(accelBase + hzOff, 0x10) != 0) {
                    wroteHz = true;
                }
            }
            if (!wroteHz && !(isRT0 || isRT1)) {
                /* real: falls through to the same "no HZ clear" tail as the
                 * `U8At(accelBase,0x9b0)==0` case's own real fallthrough
                 * when NEITHER RT0 nor RT1 applies - nothing more to write. */
            } else if (!wroteHz) {
                if (isRT0) {
                    pktW[opIdx] = 0x5c8;
                    pktW[opIdx + 1] = 1;
                    opIdx += 2;
                } else {
                    pktW[opIdx] = 0x5c8;
                    pktW[opIdx + 1] = 0x80000001;
                    opIdx += 2;
                }
            }
        }

        if ((opIdx & 7) != 0) {
            pktW[opIdx] = 0x80000000;
            opIdx += 1;
        }
        U32At(*reinterpret_cast<void **>(slot + 0xc50), 0x14) = opIdx;
    }

submit:
    if (U32At(buffer, 4) == 0) {
        map_transfer_to_GART(buffer);
    }
    UInt8 *header = *reinterpret_cast<UInt8 **>(buffer + 0x14);
    accelBase = *reinterpret_cast<UInt8 **>(self + 0xd50);
    U32At(accelBase, 0x710) += U32At(header, 0x14) * 4;
    ATIRadeonX1000 *accelObj = *reinterpret_cast<ATIRadeonX1000 **>(self + 0xd50);
    UInt32 submitResult = accelObj->submit_buffer(reinterpret_cast<UInt32 *>(header + 0x20), U32At(buffer, 4) + 0x20, U32At(header, 0x14));
    U32At(buffer, 0x10) = submitResult;
    U32At(self, 0x80) = submitResult;
    U32At(reinterpret_cast<UInt8 *>(accelObj) + static_cast<UInt32>(reinterpret_cast<intptr_t>(context)) * 0x20, 0xec) = submitResult;
}
