/*
 * ATIR500Surface_SubmitSwapBuffer.cpp
 *
 * RESOLVED (ledger pass): ATIR500Surface::submit_swap_buffer, both overloads (vtable +0x5d8 and +0x5d4), real addrs
 * 0x3b310 (GL: panel, eDoSwap, context) and 0x3ba80 (panel, flags). Each turns the pending swap-write batch of one
 * panel into a command buffer and submits it:
 *   - switch to the next of the panel's four 0x1c-byte submit slots when the batch is dirty (waiting on the slot's
 *     previous stamp through accelerator vtable +0x54c, or allocating the slot buffers on first use),
 *   - copy the batch header and words, prefixed with a small PM4 preamble (0x1393 ... / 0x194e or 0x1b4e window
 *     select) and, for the GL overload, the clipped destination rectangle words,
 *   - append the software-dual-screen blit through ATIRadeonX1000::SWDSWriteBlitToCmdBuf, pad to an even word
 *     count with a 0x80000000 NOP, and submit_buffer the slot,
 *   - record the stamp in the slot, the surface (+0x80) and the accelerator's per-panel stamp tables.
 *
 * Fields (this): +0x80 last swap stamp, +0xbed / +0xbee flags, +0xd50 accelerator, +0xd54 last submitting GL
 * context, +0xd60+panel*8 per-panel region record, +0xdb4 flag; per panel (stride 0x94 from +0xc34): +0xc34 pending
 * batch header, +0xc38 rect-word index, +0xc3c.. four 0x1c-byte submit slots (+0 xfer buffer, +4 gart offset, +0x10
 * stamp, +0x14 header buffer), +0xcad swap mode byte, +0xcae slot index (u16), +0xcb0 slave-buffer size.
 * Accelerator: +0x78 last submitter, +0x710 byte counter, +0x788 wait accumulator, +0x894 dual-screen flag,
 * +0x898/+0x89c per-panel masks, +0x9b0 SWDS active, +0xad4 per-panel stamps, +0xb10 per-panel state (stride 0x18).
 */

#include "../Headers/ATIR500Surface.h"
#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
inline SInt16  S16At(void *base, int offset) { return static_cast<SInt16>(U16At(base, offset)); }
typedef SInt32 (*StampFn)(void *, UInt32);

/* the 6- or 10-word window-select preamble; returns its length in words */
UInt32 WritePreamble(UInt32 *w, UInt8 *accel, UInt32 panel) {
    UInt32 mask = U16At(accel, panel * 0x78 + 0x14a) & 0xfff;
    w[0] = 0x1393; w[1] = 10; w[2] = 0xd0b; w[3] = 5; w[4] = 0x5c8; w[5] = 0x70000;
    if (panel == 0 && U32At(accel, 0x894) == 0) {
        w[6] = 0x194e;
        w[7] = ((mask & ~U32At(accel, 0x898)) << 0x10) | 0x80000000;
        w[8] = 0x5c8;
        w[9] = 8;
        return 10;
    }
    if (panel == 1 || U32At(accel, 0x894) != 0) {
        w[6] = 0x1b4e;
        w[7] = ((mask & ~U32At(accel, 0x89c)) << 0x10) | 0x80000000;
        w[8] = 0x5c8;
        w[9] = 0x80000008;
        return 10;
    }
    return 6;
}

/* ring an exhausted-slot wait, or allocate the slot buffers on first use; false = allocation failed */
bool PrepareSlot(ATIR500Surface *surface, UInt8 *self, UInt32 panel, UInt32 slotOffset) {
    if (U32At(self, slotOffset + 0xc44) == 0) {
        return surface->allocAllSlaveSwapBuffers(panel, U32At(self, panel * 0x94 + 0xcb0)) != 0;
    }
    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
    UInt32 waited = U32At(accel, 0x788);
    SInt32 delta = (*reinterpret_cast<StampFn *>(*reinterpret_cast<UInt8 **>(accel) + 0x54c))(accel, U32At(self, slotOffset + 0xc4c));
    U32At(accel, 0x788) = waited + delta;
    return true;
}

void CopyHeader(UInt8 *dst, UInt8 *src) {
    for (int i = 0; i < 8; ++i) {
        U32At(dst, i * 4) = U32At(src, i * 4);
    }
}

/* after the stamp is known: record it and, with SWDS active and a pending flag, in the accelerator's per-panel table */
void RecordSubmit(UInt8 *self, UInt8 *pV, UInt32 panel, UInt32 stamp, bool checkFlag) {
    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
    U32At(pV, 0x10) = stamp;
    U32At(self, 0x80) = stamp;
    U32At(accel, panel * 0x20 + 0xec) = stamp;
    accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
    if (U8At(accel, 0x9b0) != 0 && (!checkFlag || U32At(reinterpret_cast<void *>(U32At(pV, 0x14)), 0) != 0)) {
        if (U32At(accel, panel * 0x18 + 0xb10) == 0) {
            if (U32At(accel, 0x894) != 0 && U32At(accel, (panel == 0 ? 1u : 0u) * 0x18 + 0xb10) != 0) {
                U32At(accel, (panel == 0 ? 1u : 0u) * 4 + 0xad4) = U32At(self, 0x80);
                U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), 0x78) = 0;
            }
        } else {
            U32At(accel, panel * 4 + 0xad4) = U32At(self, 0x80);
            U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), 0x78) = 0;
        }
    }
}
} // namespace

void ATIR500Surface::submit_swap_buffer(UInt32 panel, eDoSwap doSwapEnum, IOATIR500GLContext *context) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 doSwap = static_cast<UInt32>(doSwapEnum);
    UInt8 *ctx = reinterpret_cast<UInt8 *>(context);
    UInt8 *accel;
    UInt32 off = panel * 0x94;
    UInt8 *pV;
    UInt32 slotOffset;

    if (U16At(self, 0xdb4) != 0) {
        U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), 0x78) = 0;
    }
    if (U32At(self, 0xd54) == reinterpret_cast<UInt32>(context)) {
        if (doSwap != U8At(self, off + 0xcad)) {
            U8At(self, off + 0xcad) = static_cast<UInt8>(doSwap);
            U32At(reinterpret_cast<void *>(U32At(self, off + 0xc34)), 0x1c) |= 1;
        }
    } else {
        U32At(self, 0xd54) = reinterpret_cast<UInt32>(context);
        U32At(reinterpret_cast<void *>(U32At(self, off + 0xc34)), 0x1c) |= 1;
    }
    UInt8 *header = reinterpret_cast<UInt8 *>(U32At(self, off + 0xc34));
    if ((U32At(header, 0x1c) & 1) == 0) {
        slotOffset = U16At(self, off + 0xcae) * 0x1c + off;
        pV = self + slotOffset + 0xc3c;
        if (U32At(self, slotOffset + 0xc44) == 0 && allocAllSlaveSwapBuffers(panel, U32At(self, off + 0xcb0)) == 0) {
            return;
        }
    } else {
        bool swapOne = (doSwap == 1);
        UInt32 count;
        UInt32 *src;
        if (doSwap == 1) {
            count = U32At(header, 0x18);
            src = reinterpret_cast<UInt32 *>(header + 0x20);
        } else if (doSwap == 2) {
            count = U32At(header, 0x14) - U32At(header, 0x18);
            src = reinterpret_cast<UInt32 *>(header + 0x20 + U32At(header, 0x18) * 4);
        } else {
            count = U32At(header, 0x14);
            src = reinterpret_cast<UInt32 *>(header + 0x20);
        }
        if (count == 0) {
            return;
        }
        UInt32 idx = (U16At(self, off + 0xcae) + 1) & 3;
        U16At(self, off + 0xcae) = static_cast<UInt16>(idx);
        slotOffset = idx * 0x1c + off;
        pV = self + slotOffset + 0xc3c;
        if (!PrepareSlot(this, self, panel, slotOffset)) {
            return;
        }
        UInt8 *dst = reinterpret_cast<UInt8 *>(U32At(self, slotOffset + 0xc50));
        CopyHeader(dst, reinterpret_cast<UInt8 *>(U32At(self, off + 0xc34)));
        UInt32 *w = reinterpret_cast<UInt32 *>(dst + 0x20);
        accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
        UInt32 words;
        if (swapOne || context == nullptr || S16At(ctx, 0x98) < 1 ||
            (U8At(accel, 0x9b0) != 0 && U32At(accel, panel * 0x18 + 0xb10) != 0)) {
            words = 0;
        } else {
            words = WritePreamble(w, accel, panel);
        }
        for (UInt32 i = 0; i < count; ++i) {
            w[words + i] = src[i];
        }
        words += count;
        if (!(swapOne || S16At(ctx, 0x94) == 0)) {
            /* clipped destination rectangle words, placed at the batch's recorded rect index */
            UInt32 entry = panel * 0x78;
            UInt32 divisor = U16At(accel, entry + 0x144);
            UInt32 row = 0;
            if (divisor != 0) {
                row = (U32At(accel, entry + 0x134) & 0x3ff) / divisor;
            }
            SInt32 column = 0;
            if (U16At(accel, entry + 0x142) != 0) {
                column = static_cast<SInt32>((U32At(accel, entry + 0x134) & 0x3ff) - row * divisor) /
                         static_cast<SInt32>(U16At(accel, entry + 0x142));
            }
            SInt32 index = static_cast<SInt32>(U32At(self, off + 0xc38));
            if (doSwap == 2) {
                index -= static_cast<SInt32>(U32At(reinterpret_cast<void *>(U32At(self, off + 0xc34)), 0x18));
            }
            SInt32 x0 = S16At(ctx, 0x90);
            UInt8 *region = reinterpret_cast<UInt8 *>(U32At(self, panel * 8 + 0xd60));
            SInt32 h = S16At(region, 10);
            SInt32 top = h - (S16At(ctx, 0x92) + S16At(ctx, 0x96));
            SInt32 left = x0;
            if (x0 < 0) {
                left = 0;
            }
            if (top < 0) {
                top = 0;
            }
            SInt32 right = x0 + S16At(ctx, 0x94);
            SInt32 bottom = h - S16At(ctx, 0x92);
            SInt32 dx = column + S16At(region, 4);
            SInt32 dy = static_cast<SInt32>(row) + S16At(region, 6);
            if (S16At(region, 8) < right) {
                right = S16At(region, 8);
            }
            if (h < bottom) {
                bottom = h;
            }
            w[index] = ((left + dx) & 0x1fff) | (((top + dy) * 0x2000) & 0x3ffe000);
            w[index + 1] = ((right + dx) - 1u & 0x1fff) | (((bottom + dy - 1) * 0x2000) & 0x3ffe000);
        }
        bool haveRect = !(U8At(self, 0xbed) == 0 && (swapOne || context == nullptr || S16At(ctx, 0x98) < 1));
        UInt32 flag;
        if (U8At(accel, 0x9b0) == 0 || !haveRect) {
            flag = 0;
        } else if (U32At(accel, panel * 0x18 + 0xb10) == 0) {
            if (U32At(accel, 0x894) == 0 || U32At(accel, (panel == 0 ? 1u : 0u) * 0x18 + 0xb10) == 0) {
                flag = 0;
            } else {
                words = reinterpret_cast<ATIRadeonX1000 *>(accel)->SWDSWriteBlitToCmdBuf(w, words, true, panel == 0 ? 1u : 0u);
                flag = 1;
            }
        } else {
            words = reinterpret_cast<ATIRadeonX1000 *>(accel)->SWDSWriteBlitToCmdBuf(w, words, true, panel);
            flag = 1;
        }
        U32At(reinterpret_cast<void *>(U32At(self, slotOffset + 0xc50)), 0) = flag;
        UInt32 total = words;
        if ((words & 1) != 0) {
            total = words + 1;
            w[words] = 0x80000000;
        }
        U32At(reinterpret_cast<void *>(U32At(self, slotOffset + 0xc50)), 0x14) = total;
        U32At(reinterpret_cast<void *>(U32At(self, off + 0xc34)), 0x1c) &= 0xfffffffe;
    }

    UInt8 *buffer = reinterpret_cast<UInt8 *>(U32At(pV, 0x14));
    if (U32At(buffer, 0x14) != 0) {
        if (U32At(pV, 4) == 0) {
            map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(pV));
            buffer = reinterpret_cast<UInt8 *>(U32At(pV, 0x14));
        }
        U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), 0x710) += U32At(buffer, 0x14) * 4;
        accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
        UInt32 stamp = reinterpret_cast<ATIRadeonX1000 *>(accel)->submit_buffer(
            reinterpret_cast<UInt32 *>(U32At(pV, 0x14) + 0x20), U32At(pV, 4) + 0x20, U32At(reinterpret_cast<void *>(U32At(pV, 0x14)), 0x14));
        RecordSubmit(self, pV, panel, stamp, true);
    }
}

void ATIR500Surface::submit_swap_buffer(UInt32 panel, UInt32 flags) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel;
    UInt32 off = panel * 0x94;
    UInt8 *pV;
    UInt32 slotOffset;

    if (U16At(self, 0xdb4) != 0) {
        U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), 0x78) = 0;
    }
    if (U32At(self, 0xd54) != 0) {
        U32At(self, 0xd54) = 0;
        U32At(reinterpret_cast<void *>(U32At(self, off + 0xc34)), 0x1c) |= 1;
    }
    if ((U32At(reinterpret_cast<void *>(U32At(self, off + 0xc34)), 0x1c) & 1) == 0) {
        slotOffset = U16At(self, off + 0xcae) * 0x1c + off;
        pV = self + slotOffset + 0xc3c;
        if (U32At(self, slotOffset + 0xc44) == 0 && allocAllSlaveSwapBuffers(panel, U32At(self, off + 0xcb0)) == 0) {
            return;
        }
    } else {
        UInt32 idx = (U16At(self, off + 0xcae) + 1) & 3;
        U16At(self, off + 0xcae) = static_cast<UInt16>(idx);
        slotOffset = idx * 0x1c + off;
        pV = self + slotOffset + 0xc3c;
        if (!PrepareSlot(this, self, panel, slotOffset)) {
            return;
        }
        UInt8 *dst = reinterpret_cast<UInt8 *>(U32At(self, slotOffset + 0xc50));
        CopyHeader(dst, reinterpret_cast<UInt8 *>(U32At(self, off + 0xc34)));
        UInt32 *w = reinterpret_cast<UInt32 *>(dst + 0x20);
        accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
        UInt32 words;
        if ((flags & 0x18) == 0 || U16At(self, 0xbee) != 0 ||
            (U8At(accel, 0x9b0) != 0 && U32At(accel, panel * 0x18 + 0xb10) != 0)) {
            words = 0;
        } else {
            words = WritePreamble(w, accel, panel);
        }
        UInt8 *header = reinterpret_cast<UInt8 *>(U32At(self, off + 0xc34));
        UInt32 count = U32At(header, 0x14) - U32At(header, 0x18);
        UInt32 *src = reinterpret_cast<UInt32 *>(header + 0x20 + U32At(header, 0x18) * 4);
        if (count != 0) {
            for (UInt32 i = 0; i < count; ++i) {
                w[words + i] = src[i];
            }
            words += count;
        }
        UInt32 flag;
        accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
        if (U8At(accel, 0x9b0) == 0) {
            flag = 0;
        } else if (U32At(accel, 0x894) == 0 || U32At(accel, 0xb28) == 0) {
            if (U32At(accel, panel * 0x18 + 0xb10) == 0) {
                words = reinterpret_cast<ATIRadeonX1000 *>(accel)->SWDSWriteBlitToCmdBuf(w, words, true, panel == 0 ? 1u : 0u);
                flag = 1;
            } else {
                words = reinterpret_cast<ATIRadeonX1000 *>(accel)->SWDSWriteBlitToCmdBuf(w, words, true, panel);
                flag = 1;
            }
        } else {
            words = reinterpret_cast<ATIRadeonX1000 *>(accel)->SWDSWriteBlitToCmdBuf(w, words, true, 1);
            flag = 1;
        }
        U32At(reinterpret_cast<void *>(U32At(self, slotOffset + 0xc50)), 0) = flag;
        UInt32 total = words;
        if ((words & 1) != 0) {
            total = words + 1;
            w[words] = 0x80000000;
        }
        U32At(reinterpret_cast<void *>(U32At(self, slotOffset + 0xc50)), 0x14) = total;
        U32At(reinterpret_cast<void *>(U32At(self, off + 0xc34)), 0x1c) &= 0xfffffffe;
    }

    if (U32At(pV, 4) == 0) {
        map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(pV));
    }
    U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), 0x710) +=
        U32At(reinterpret_cast<void *>(U32At(pV, 0x14)), 0x14) * 4;
    accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
    UInt32 stamp = reinterpret_cast<ATIRadeonX1000 *>(accel)->submit_buffer(
        reinterpret_cast<UInt32 *>(U32At(pV, 0x14) + 0x20), U32At(pV, 4) + 0x20, U32At(reinterpret_cast<void *>(U32At(pV, 0x14)), 0x14));
    RecordSubmit(self, pV, panel, stamp, true);
}
