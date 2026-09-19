/*
 * ATIR500DVDContext_IDCT.cpp
 *
 * doIDCT - THE real external entry point for this GPU's independent
 * hardware IDCT engine (real kext offset 0x35540), directly relevant to
 * this project's H.264 GPU-decode goal. CONFIRMED, fully decoded this
 * session (stage5-iouserclient-external-method-api-complete.md).
 *
 * This is transcribed close to the real decompiled control flow (raw
 * offset arithmetic, matching field names where this project's struct
 * reconstruction is confident - see Headers/ATIRadeonX1000Types.h's
 * sATIDVDIDCTInfo/sATIDVDIDCTParams - and raw UInt8* arithmetic with
 * inline comments where a couple of VendorTransferBuffer fields this
 * function touches (a real "resident size" field at +0x10) were not
 * independently added to that struct's confirmed field list this pass).
 *
 * Confidence: CONFIRMED for control flow and every register/field this
 * project already named; the two fields called out above are a real,
 * narrow, honestly-marked gap.
 */

#include "../Headers/ATIR500DVDContext.h"
#include "../Headers/ATIRadeonX1000.h"

extern "C" void IDCT_lock(void *) asm("_IOLockLock");
extern "C" void IDCT_unlock(void *) asm("_IOLockUnlock");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/*
 * CORRECTED (ledger pass): the shipped signature is doIDCT(sATIDVDIDCTInfo *info, unsigned long size) - a real
 * member function. The stock decompile shows `this` typed as the first parameter, and the earlier transcription of
 * this file therefore treated `info` (the caller's parameter block, layout sATIDVDIDCTParams here) as the context
 * object and the object's own fields as a parameter block. Rewritten with `this` as the context and `info` as the
 * caller's block. Also restored: the initial waitForTimeStamp(this+0x7c), the accelerator command lock around the
 * body, and the shipped code's own lock LEAK: a planeSelector other than 0/1 returns kIOReturnBadArgument with the
 * command lock still held (faithful; the next locker of that accelerator will block).
 */
IOReturn ATIR500DVDContext::doIDCT(sATIDVDIDCTInfo *infoIn, UInt32 infoSize) {
    (void)infoSize;
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *p = reinterpret_cast<UInt8 *>(infoIn);   /* caller's block, layout sATIDVDIDCTParams */
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);

    accelerator->waitForTimeStamp(U32At(self, 0x7c));
    if (boundSurface == nullptr || U8At(accel, 0x80) == 0 || U32At(accel, 0x8bc) == 0) {
        return 0xe00002d8;
    }
    IDCT_lock(reinterpret_cast<void *>(U32At(accel, 0x840)));

    UInt8 *surface = reinterpret_cast<UInt8 *>(boundSurface);
    SInt32 fieldHeight = static_cast<SInt32>(static_cast<SInt16>(U16At(surface, 0x9a))) -
                         static_cast<SInt32>(static_cast<SInt16>(U16At(surface, 0x94)));
    UInt8 *buffer;
    UInt8 *plane;
    if (U32At(p, 0xc) == 0) {
        buffer = self + 0x168;
        if (U32At(self, 0x164) != 0) {
            buffer = self + 0x184;
        }
        plane = surface + U32At(p, 8) * 0x78 + 0x558;
    } else {
        if (U32At(p, 0xc) != 1) {
            return 0xe00002c2;
        }
        buffer = self + 0x1a4;
        if (U32At(self, 0x1a0) != 0) {
            buffer = self + 0x1c0;
        }
        plane = surface + 0x8a0;
    }
    UInt32 pitch = U16At(plane, 0x18);
    UInt32 stride = (U32At(p, 0) == 0) ? pitch : pitch << 1;
    if (U32At(p, 4) == 0) {
        U32At(p, 0x2c) = U32At(plane, 8);
        U32At(p, 0x30) = fieldHeight * U16At(plane, 0x18) + U32At(plane, 8);
    } else {
        U32At(p, 0x2c) = pitch + U32At(plane, 8);
        U32At(p, 0x30) = U16At(plane, 0x18) + fieldHeight * U16At(plane, 0x18) + U32At(plane, 8);
    }
    U32At(p, 0x1c) = stride * fieldHeight - 1;
    U32At(p, 0x28) = stride | (stride << 16);
    U32At(p, 0x20) = stride * (static_cast<UInt32>(fieldHeight) >> 1) - 1;
    if (U32At(p, 0x2c) != 0) {
        UInt32 gart = U32At(buffer, 4);
        if (gart == 0) {
            map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(buffer));
            gart = U32At(buffer, 4);
        }
        UInt32 priorConsumed = U32At(accel, 0x854);
        UInt32 tag = accelerator->submit_idct_buffer_consumed(
            reinterpret_cast<UInt32 *>(U32At(buffer, 0x14) + 0x20), gart + 0x20, infoIn);
        U32At(self, 0x150) = tag;
        if (priorConsumed <= tag) {
            U32At(buffer, 0x10) = tag;
            if (U32At(p, 0xc) == 0) {
                U32At(self, 0x154) = U32At(self, 0x150);
            }
            IDCT_unlock(reinterpret_cast<void *>(U32At(accel, 0x840)));
            return 0;
        }
    }
    IDCT_unlock(reinterpret_cast<void *>(U32At(accel, 0x840)));
    return 0xe00002d8;
}
