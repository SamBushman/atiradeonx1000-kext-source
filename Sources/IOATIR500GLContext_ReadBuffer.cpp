/*
 * IOATIR500GLContext_ReadBuffer.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real body for
 * `IOATIR500GLContext::read_buffer` - real addr 0x8d10, the real
 * glReadPixels-style "copy hardware framebuffer to a userspace-mapped
 * buffer" external method.
 *
 * HONEST NOTE on the real decompile's own parameter list: Ghidra
 * mis-detected the calling convention as `__stdcall` and renders only
 * two visible parameters (`sIOGLContextReadBufferData *param_1, ulong
 * param_2`) - but every real field access inside the body reads
 * `param_1+200`/`+0x290`/etc. as this class's own already-established
 * `self+0xc8`(accelerator)/`self+0x290`(boundSurface) fields, proving
 * `param_1` is really the implicit `this`, not a real data parameter.
 * The real `readData` struct pointer is Ghidra's own `param_2`
 * (rendered as `ulong` - the same real pointer-degraded-to-integer
 * artifact this project already documents for `sATIDVDIDCTParams`).
 * This function's own real body never reads a third value, so the
 * class's own already-declared `structSize` parameter (required by the
 * real external linkage signature, confirmed via `nm`) is accepted for
 * ABI correctness but genuinely unused here - another instance of this
 * project's established "argument accepted but not read" pattern.
 *
 * Real body: translates the caller's requested buffer-type tag (a
 * 10-way switch) to an internal buffer-family index, locks the
 * accelerator's commandLock, waits (via the already-established
 * `IOLockSleep`) for a real surface to become bound if the bound
 * surface's own ID (`+0xa4`) hasn't been assigned yet, resolves a real
 * per-format buffer-pointer-table entry (the SAME `boundSurf+idx*4+
 * 0xb70` table `write_r500_3d_blit_state_packet` already establishes,
 * with a real alternate lookup through the accelerator's own
 * `+idx*0x20+0xe8` array when the surface's own `+0xc14` cross-
 * reference applies), gates on the surface's own `+0xbf8` state-bits
 * field (allocating on demand via `alloc_surfaces_retry` when needed),
 * clips the caller's requested rectangle to the surface's own real
 * bounds (`+0xbd4`/`+0xbd6`), allocates a real userspace-mapped
 * `IOMemoryDescriptor` via the already-confirmed
 * `IOMemoryDescriptor::withAddress` for the clipped region, calls the
 * real per-tile blit vtable slot (`+0x5e8`, already established in
 * `IOATIR500Surface_CopyBufferToBackingStore.cpp`) once for the whole
 * clipped rectangle, propagates a real "generation stamp" bump to any
 * other cached slot referencing the same buffer (the SAME fixed
 * 23-entry `+0xa0/+0x78`-stride array shape `alloc_surfaces_pageq`
 * already establishes, here read from the bound surface directly), and
 * - if a real flag was set - releases a real transfer buffer back to
 * GART before releasing the memory descriptor and unlocking.
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant - a real, complete, standalone decompile.
 */

#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline SInt16 &S16At(void *base, int offset) { return *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8 &U8At(void *base, int offset) { return *reinterpret_cast<UInt8 *>(reinterpret_cast<UInt8 *>(base) + offset); }
typedef void (*BlitTileFn)(void *, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, void *, UInt32, UInt32, UInt32, UInt32, UInt32);
typedef void (*ReleaseFn)(void *);

/* the real 16-byte on-stack record handed to the tile-blit slot (+0x5e8) and,
 * if the blit flags it, released via accelerator vtable +0x5ac. Real layout
 * per raw decompile (local_48/local_44/local_40/local_3c/local_3a, contiguous):
 * {word0=0, needsRelease=0, memDesc, u16 kind=3, u16 0}. Corrected in issue
 * #58's cross-check against surface_read (same record). */
struct ReadBufferXferRecord {
    UInt32 word0;
    UInt32 needsRelease;
    void *memDesc;
    UInt16 kind;
    UInt16 pad;
};
} // namespace

extern "C" void ReadBuffer_mutex_lock(void *lockPtr) asm("_mutex_lock");
extern "C" void ReadBuffer_mutex_unlock(void *lockPtr) asm("_mutex_unlock_rwcmb");
extern "C" void ReadBuffer_IOLockSleep(void *lockPtr, void *event, UInt32 zero) asm("_IOLockSleep");
extern "C" void *ReadBuffer_withAddress(UInt32 address, UInt32 length, UInt32 direction, void *task) asm("__ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task");
extern "C" int _ASICSupportsAGP;

IOReturn IOATIR500GLContext::read_buffer(sIOGLContextReadBufferData *readData, UInt32 structSize) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *data = reinterpret_cast<UInt8 *>(readData);

    SInt32 x = static_cast<SInt32>(U32At(data, 0x00));
    SInt32 y = static_cast<SInt32>(U32At(data, 0x04));
    SInt32 w = static_cast<SInt32>(U32At(data, 0x08));
    SInt32 h = static_cast<SInt32>(U32At(data, 0x0c));
    UInt32 destBase = U32At(data, 0x14);

    UInt32 bufferKindIndex;
    switch (U32At(data, 0x10)) {
        case 0: bufferKindIndex = 1; break;
        case 1: bufferKindIndex = 0; break;
        case 2: bufferKindIndex = 4; break;
        case 3: bufferKindIndex = 5; break;
        case 4: bufferKindIndex = 6; break;
        case 7: bufferKindIndex = 2; break;
        case 8: bufferKindIndex = 3; break;
        case 10: bufferKindIndex = 7; break;
        case 0xb: bufferKindIndex = 8; break;
        default: return 0xe00002c2;
    }

    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));
    void *commandLock = *reinterpret_cast<void **>(accel + 0x840);
    ReadBuffer_mutex_lock(commandLock);

    UInt8 *surface = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
    if (surface == nullptr) {
        ReadBuffer_mutex_unlock(commandLock);
        return 0xe00002cc;
    }

    if (U32At(surface, 0xa4) > 0xff && U8At(accel, 0x80) == 0) {
        do {
            ReadBuffer_IOLockSleep(*reinterpret_cast<void **>(accel + 0x840), accel, 0);
        } while (U8At(accel, 0x80) == 0);
        surface = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
        if (surface == nullptr) {
            ReadBuffer_mutex_unlock(commandLock);
            return 0xe00002cc;
        }
    }

    UInt8 *bufferOwner;
    if (bufferKindIndex != 0 || U32At(surface, 0xc14) == 0xffff ||
        (bufferOwner = *reinterpret_cast<UInt8 **>(accel + U32At(surface, 0xc14) * 0x20 + 0xe8), bufferOwner == nullptr) ||
        surface == bufferOwner) {
        bufferOwner = surface + bufferKindIndex * 4;
    }

    UInt8 *bufRec = *reinterpret_cast<UInt8 **>(bufferOwner + 0xb70);
    UInt32 mask = 0x40000000;
    UInt32 slotIdx = static_cast<UInt32>((static_cast<SInt32>(reinterpret_cast<UInt32>(bufRec)) -
                                           static_cast<SInt32>(reinterpret_cast<UInt32>(surface + 0xa8))) >> 3) *
                     static_cast<UInt32>(-0x11111111);
    if (slotIdx < 0x17) {
        mask = (1u << (slotIdx & 0x3f)) & U32At(self, 0x8c);
        if (mask == 0) {
            ReadBuffer_mutex_unlock(commandLock);
            return 0xe00002cc;
        }
    }

    if ((U32At(surface, 0xbf8) & mask) != 0) {
        if (U32At(bufRec, 0x24) == 0) {
            ReadBuffer_mutex_unlock(commandLock);
            return 0;
        }
        if (U8At(accel, 0x80) != 0 && U8At(reinterpret_cast<void *>(U32At(bufRec, 0x24)), 0x58) == 0) {
            IOReturn allocResult = reinterpret_cast<IOATIR500Surface *>(surface)->alloc_surfaces_retry(mask, 0);
            if (allocResult != 0) {
                ReadBuffer_mutex_unlock(commandLock);
                return 0xe00002cc;
            }
            surface = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
            bufRec = *reinterpret_cast<UInt8 **>(surface + bufferKindIndex * 4 + 0xb70);
            goto haveGeometry;
        }
        /* real: falls through to re-run the SAME "mask not set" gate below
         * (goto LAB_00008f60 in the raw decompile) - not a duplicate, the
         * genuine shared check both paths converge on. */
    }

    if ((U32At(surface, 0xbf8) & 0x20000000u) != 0 || U32At(bufRec, 0x10) == 0) {
        ReadBuffer_mutex_unlock(commandLock);
        return 0xe00002cc;
    }

haveGeometry:
    {
        SInt32 xEnd = x + w;
        SInt32 yEnd = y + h;
        SInt16 surfW = S16At(surface, 0xbd4);
        SInt16 surfH = S16At(surface, 0xbd6);
        if (!(xEnd > 0 && yEnd > 0 && x < surfW && y < surfH)) {
            ReadBuffer_mutex_unlock(commandLock);
            return 0;
        }

        SInt32 destStride = static_cast<SInt32>(U32At(data, 0x18));
        SInt32 byteOffset = 0;
        SInt32 clipX = x, clipY = y, clipW = w, clipH = h;

        if (x < 0) {
            byteOffset = -(static_cast<SInt32>(U16At(bufRec, 0x16)) * x);
            clipX = 0;
            clipW = xEnd;
        }
        if (y < 0) {
            byteOffset -= destStride * y;
            clipY = 0;
            clipH = yEnd;
        }
        if (surfW < xEnd) {
            clipW = surfW - clipX;
        }
        if (surfH < yEnd) {
            clipH = surfH - clipY;
        }

        UInt32 addr = destBase + byteOffset;
        UInt32 addrLow = addr & (static_cast<UInt32>(_ASICSupportsAGP) - 1);
        UInt32 alignedAddr = addr & static_cast<UInt32>(-_ASICSupportsAGP);
        UInt32 length = static_cast<UInt32>(-_ASICSupportsAGP) &
                        ((static_cast<UInt32>(_ASICSupportsAGP) +
                          destStride * (clipH - 1) +
                          static_cast<UInt32>(U16At(bufRec, 0x16)) * clipW + addrLow) - 1);

        void *memDesc = ReadBuffer_withAddress(alignedAddr, length, 0, reinterpret_cast<void *>(U32At(self, 0x78)));
        IOReturn result;
        if (memDesc == nullptr) {
            result = 0xe00002be;
        } else {
            UInt8 *boundSurf = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
            UInt32 stampBefore = *reinterpret_cast<UInt32 *>(boundSurf + 0x7c);
            void **vtable = *reinterpret_cast<void ***>(boundSurf);
            ReadBufferXferRecord xfer;
            xfer.word0 = 0;
            xfer.needsRelease = 0;
            xfer.memDesc = memDesc;
            xfer.kind = 3;
            xfer.pad = 0;
            (*reinterpret_cast<BlitTileFn *>(vtable + (0x5e8 / 4)))(
                boundSurf, static_cast<UInt32>(clipX), static_cast<UInt32>(clipY),
                static_cast<UInt32>(clipW), static_cast<UInt32>(clipH),
                U32At(self, 0x298), U32At(self, 0x29c), bufRec, U32At(self, 0x7c),
                reinterpret_cast<UInt32>(&xfer), addrLow, static_cast<UInt32>(destStride), 2);

            UInt8 *slotBase = boundSurf + 0xa0;
            for (int i = 0x17; i != 0; i--) {
                UInt8 *slotBuf = *reinterpret_cast<UInt8 **>(slotBase + 0x2c);
                if (slotBuf != nullptr && stampBefore == U32At(slotBuf, 0x54)) {
                    U32At(slotBuf, 0x54) = U32At(boundSurf, 0x7c);
                }
                slotBase += 0x78;
            }

            /* real: local_44 - set by the blit slot when a transfer buffer
             * must be handed back; live, not dead (corrected, issue #58). */
            if (xfer.needsRelease != 0) {
                ReadBuffer_mutex_unlock(commandLock);
                UInt8 *accel2 = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));
                void **accelVtable = *reinterpret_cast<void ***>(accel2);
                typedef SInt32 (*Fn0x55c)(void *, UInt32);
                SInt32 prevCounter = *reinterpret_cast<SInt32 *>(accel2 + 0x7b4);
                SInt32 delta = (*reinterpret_cast<Fn0x55c *>(accelVtable + (0x55c / 4)))(accel2, U32At(boundSurf, 0x7c));
                *reinterpret_cast<SInt32 *>(accel2 + 0x7b4) = prevCounter + delta;
                ReadBuffer_mutex_lock(commandLock);
                (*reinterpret_cast<void (**)(void *, void *)>(accelVtable + (0x5ac / 4)))(accel2, &xfer);
            }

            result = 0;
            (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(memDesc) + (0x18 / 4)))(memDesc);
        }

        ReadBuffer_mutex_unlock(commandLock);
        return result;
    }
}
