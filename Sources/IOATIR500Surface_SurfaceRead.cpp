/*
 * IOATIR500Surface_SurfaceRead.cpp
 *
 * RESOLVED (issue #58): real body for `IOATIR500Surface::surface_read` -
 * external method selector 5, real addr 0x14a30. The Surface-side twin of
 * `IOATIR500GLContext::read_buffer` (real addr 0x8d10): a clipped readback
 * of this surface's own current buffer into a caller-supplied userspace
 * range, wrapped in a real `IOMemoryDescriptor` and handed to the real
 * per-tile blit vtable slot (+0x5e8).
 *
 * WHAT WAS BLOCKING IT, and how it was resolved: the body was fully
 * decompiled long ago; the only holdout was one call, `FUN_00014e28`, a
 * kxld-patched lazy-binding stub (`lis r12,0 / ori r12,r12,0 / mtspr CTR /
 * bctr` - zero immediates on disk). Resolved by a live, single-address
 * read of the loaded kext on the G5 (read-only /dev/kmem, no scan): the
 * live immediates decode to kernel 0x2d617c, an exact offset-0 match in
 * `nm /mach_kernel` for `IOMemoryDescriptor::withAddress(unsigned long,
 * unsigned long, IODirection, task*)` - the same symbol
 * `IOATIR500GLContext::read_buffer` and `IOATIR500Shared`'s texture
 * allocator already call. The two lock stubs used here were re-verified the
 * same way (0x14e58 -> `mutex_lock`, 0x14e38 -> `mutex_unlock_rwcmb`).
 * Slide used: this kext is a single unnamed LC_SEGMENT at vmaddr 0; the
 * live Mach-O header (read at kextstat's address 0x588000) reports
 * vmaddr 0x589000, i.e. live = 0x589000 + Ghidra address. Validated first
 * against `get_state` (0x10f30): live prologue bytes identical to static.
 * (The issue's earlier "formula doesn't hold" observation was a slide of
 * kextstat's address, one page short of the real segment base - not a
 * flaw in the technique.)
 *
 * Real body: identical in shape to read_buffer, minus the buffer-kind
 * translation (this surface always reads its own `+0xb70` primary buffer
 * record) and with the real "transfer buffer" bookkeeping live rather
 * than dead: the tile-blit call is handed a real 16-byte on-stack record
 * {word0=0, word1(needs-release flag)=0, memDesc, u16 kind=3, u16 0}
 * (stack slots 0x5c..0x6b in the raw disassembly, confirmed contiguous),
 * and afterwards, if the blit set word1, the record is released back to
 * the accelerator via its `+0x5ac` vtable slot.
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant - a real, complete, standalone decompile, stack layout of the
 * on-stack record checked against raw disassembly.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"

extern "C" void SurfRead_mutex_lock(void *lockPtr) asm("_mutex_lock");
extern "C" void SurfRead_mutex_unlock(void *lockPtr) asm("_mutex_unlock_rwcmb");
extern "C" void *SurfRead_withAddress(UInt32 address, UInt32 length, UInt32 direction, void *task) asm("__ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task");
extern "C" int kernelPageSize asm("_page_size"); /* kernel page_size (0x1000). Ghidra labels every zero-immediate data relocation in this kext "_ASICSupportsAGP"; the real target of each site comes from the Mach-O relocation table (issue #58 follow-up) */

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline SInt16 &S16At(void *base, int offset) { return *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef void (*BlitTileFn)(void *, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, void *, UInt32, UInt32, UInt32, UInt32, UInt32);
typedef SInt32 (*QueryFn)(void *, UInt32, UInt32 *);
typedef SInt32 (*Fn0x55c)(void *, UInt32);
typedef void (*ReleaseFn)(void *);

/* the real on-stack record handed to the tile-blit slot and (if flagged)
 * released via accelerator vtable +0x5ac - see header comment */
struct SurfReadXferRecord {
    UInt32 word0;
    UInt32 needsRelease;
    void *memDesc;
    UInt16 kind;
    UInt16 pad;
};
} // namespace

IOReturn IOATIR500Surface::surface_read(IOAccelSurfaceReadData *readData, UInt32 structSize) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *data = reinterpret_cast<UInt8 *>(readData);

    SurfReadXferRecord xfer;
    xfer.word0 = 0;
    xfer.needsRelease = 0;
    xfer.memDesc = nullptr;
    xfer.kind = 3;
    xfer.pad = 0;
    UInt32 queryOut = 0;

    SInt32 x = static_cast<SInt32>(U32At(data, 0x00));
    SInt32 y = static_cast<SInt32>(U32At(data, 0x04));
    SInt32 w = static_cast<SInt32>(U32At(data, 0x08));
    SInt32 h = static_cast<SInt32>(U32At(data, 0x0c));
    UInt32 destBase = U32At(data, 0x10);

    void *commandLock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(U32At(self, 0xd50)) + 0x840);
    SurfRead_mutex_lock(commandLock);

    UInt8 *bufRec = reinterpret_cast<UInt8 *>(U32At(self, 0xb70));

    bool skipGate = false;
    if ((U32At(self, 0xc1c) & 3 & U32At(self, 0xbf8)) != 0) {
        UInt8 *xferBuf = reinterpret_cast<UInt8 *>(U32At(bufRec, 0x24));
        if (xferBuf == nullptr) {
            SurfRead_mutex_unlock(commandLock);
            return 0;
        }
        if (U8At(xferBuf, 0x58) == 0) {
            IOReturn allocResult = alloc_surfaces_retry(U32At(self, 0xc1c) & 3, 0);
            if (allocResult != 0) {
                SurfRead_mutex_unlock(commandLock);
                return 0xe00002cc;
            }
            bufRec = reinterpret_cast<UInt8 *>(U32At(self, 0xb70));
            skipGate = true; /* real: falls straight to the geometry code */
        }
        /* else: real goto LAB_00014ae0 - the shared "not usable" gate below */
    }

    if (!skipGate) {
        if ((U32At(self, 0xbf8) & 0x20000000u) != 0 || U32At(bufRec, 0x10) == 0) {
            SurfRead_mutex_unlock(commandLock);
            return 0xe00002cc;
        }
    }

    SInt32 xEnd = x + w;
    SInt32 yEnd = y + h;
    SInt16 surfW = S16At(self, 0xbd4);
    SInt16 surfH = S16At(self, 0xbd6);
    if (!(xEnd > 0 && yEnd > 0 && x < surfW && y < surfH)) {
        SurfRead_mutex_unlock(commandLock);
        return 0;
    }

    SInt32 destStride = static_cast<SInt32>(U32At(data, 0x14));
    SInt32 byteOffset = 0;
    if (x < 0) {
        byteOffset = -(static_cast<SInt32>(U16At(bufRec, 0x16)) * x);
        x = 0;
        w = xEnd;
    }
    if (y < 0) {
        byteOffset -= destStride * y;
        y = 0;
        h = yEnd;
    }
    if (surfW < xEnd) {
        w = surfW - x;
    }
    if (surfH < yEnd) {
        h = surfH - y;
    }

    UInt32 addr = destBase + byteOffset;
    UInt32 addrLow = addr & (static_cast<UInt32>(kernelPageSize) - 1);
    UInt32 alignedAddr = addr & static_cast<UInt32>(-kernelPageSize);
    UInt32 length = static_cast<UInt32>(-kernelPageSize) &
                    ((static_cast<UInt32>(kernelPageSize) +
                      destStride * (h - 1) +
                      static_cast<UInt32>(U16At(bufRec, 0x16)) * w + addrLow) - 1);

    void *memDesc = SurfRead_withAddress(alignedAddr, length, 0, reinterpret_cast<void *>(U32At(self, 0x78)));
    xfer.memDesc = memDesc;

    IOReturn result;
    if (memDesc == nullptr) {
        result = 0xe00002be;
    } else {
        UInt8 *xferBuf = reinterpret_cast<UInt8 *>(U32At(bufRec, 0x24));
        if (U8At(self, 0xbf7) != 0 && xferBuf != nullptr) {
            void *queryObj = *reinterpret_cast<void **>(xferBuf + 8);
            if (queryObj != nullptr) {
                void **queryVtable = *reinterpret_cast<void ***>(queryObj);
                SInt32 queryResult = (*reinterpret_cast<QueryFn *>(queryVtable + (0xdc / 4)))(queryObj, 2, &queryOut);
                if (queryResult == 0 && queryOut == 4) {
                    xferBuf = reinterpret_cast<UInt8 *>(U32At(bufRec, 0x24));
                    if (U32At(xferBuf, 4) != 0) {
                        SurfRead_mutex_unlock(commandLock);
                        UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
                        void **accelVtable = *reinterpret_cast<void ***>(accel);
                        SInt32 prevCounter = *reinterpret_cast<SInt32 *>(accel + 0x7b4);
                        SInt32 delta = (*reinterpret_cast<Fn0x55c *>(accelVtable + (0x55c / 4)))(accel, U32At(self, 0x7c));
                        *reinterpret_cast<SInt32 *>(accel + 0x7b4) = prevCounter + delta;
                        SurfRead_mutex_lock(commandLock);
                        accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
                        accelVtable = *reinterpret_cast<void ***>(accel);
                        (*reinterpret_cast<void (**)(void *, void *)>(accelVtable + (0x5ac / 4)))(
                            accel, reinterpret_cast<void *>(U32At(bufRec, 0x24)));
                        U32At(reinterpret_cast<void *>(U32At(bufRec, 0x24)), 4) = 0;
                        xferBuf = reinterpret_cast<UInt8 *>(U32At(bufRec, 0x24));
                    }
                    U32At(xferBuf, 0x54) = U32At(self, 0x7c) - 1;
                }
            }
        }

        UInt32 stampBefore = U32At(self, 0x7c);
        void **selfVtable = *reinterpret_cast<void ***>(self);
        (*reinterpret_cast<BlitTileFn *>(selfVtable + (0x5e8 / 4)))(
            this, static_cast<UInt32>(x), static_cast<UInt32>(y),
            static_cast<UInt32>(w), static_cast<UInt32>(h),
            0, 0, bufRec, stampBefore, reinterpret_cast<UInt32>(&xfer),
            addrLow, static_cast<UInt32>(destStride), 0);

        UInt8 *slotBase = self + 0xcc;
        for (int i = 0x17; i != 0; i--) {
            UInt8 *slotBuf = *reinterpret_cast<UInt8 **>(slotBase);
            slotBase += 0x78;
            if (slotBuf != nullptr && stampBefore == U32At(slotBuf, 0x54)) {
                U32At(slotBuf, 0x54) = U32At(self, 0x7c);
            }
        }

        if (xfer.needsRelease != 0) {
            SurfRead_mutex_unlock(commandLock);
            UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
            void **accelVtable = *reinterpret_cast<void ***>(accel);
            SInt32 prevCounter = *reinterpret_cast<SInt32 *>(accel + 0x7b4);
            SInt32 delta = (*reinterpret_cast<Fn0x55c *>(accelVtable + (0x55c / 4)))(accel, U32At(self, 0x7c));
            *reinterpret_cast<SInt32 *>(accel + 0x7b4) = prevCounter + delta;
            SurfRead_mutex_lock(commandLock);
            (*reinterpret_cast<void (**)(void *, void *)>(accelVtable + (0x5ac / 4)))(accel, &xfer);
        }

        result = 0;
        (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(memDesc) + (0x18 / 4)))(memDesc);
    }

    SurfRead_mutex_unlock(commandLock);
    return result;
}
