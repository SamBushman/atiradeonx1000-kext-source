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

/* (re-ported mechanically: see ATIR500Surface_submit_swap_buffer_Port.cpp) */


/* (re-ported mechanically: see ATIR500Surface_submit_swap_buffer_Port.cpp) */

