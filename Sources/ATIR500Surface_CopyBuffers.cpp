/*
 * ATIR500Surface_CopyBuffers.cpp
 *
 * RESOLVED (ledger pass): the three surface<->client-memory copy virtuals of ATIR500Surface that had no body in the
 * rebuild (real addrs in parentheses):
 *   copy_buffer_using_DMA (0x42a80)  copy_to_buffer (0x43340, vtable +0x5ec)  copy_from_buffer (0x43730, +0x5e8)
 * Parameters (both public entry points): x, y, w, h, index, level, buffer, stamp, transfer buffer, offset,
 * pitch, flags. flags bit 0 selects the direct-copy path (client memory mapped through the transfer buffer's
 * descriptor) instead of the GPU DMA path, bit 1 (DMA path) asks for the vertically flipped copy.
 *
 * copy_buffer_using_DMA returns 1 when it handled the request (a blit was submitted) and 0 when the caller must
 * fall back to the CPU copy. Its 25-argument callee is write_3dtexquad_cmds_for_copy_buffer_using_DMA.
 *
 * Buffer record (ATIR500SurfaceBuffer) fields: +8 base address, +0x14/+0x16 pitch words / bytes per pixel,
 * +0x1c/+0x1e width/height, +0x20 slice size, +0x24 backing-store record, +0x38..+0x3b format flags (+0x3a = format
 * index into ati_format_info_table), +0x3c mode flags (bit 11 = tiled/multisample surface, bits 20-23 sample count,
 * bits 12-19 sample grid), +0x40+level*4 / +0x44+level*4 mip offsets. Backing-store record: +8 descriptor,
 * +0x50/+0x52 client offset / pitch, +0x54 stamp, +0x58 busy flag.
 *
 * The client-memory mappings use IOMemoryDescriptor vtable +0x14c (map into kernel_task) / +0x150 (map with the
 * accelerator's option word | 1), IOMemoryMap +0xd0 (getVirtualAddress) and +0x18 (release).
 */

#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Accelerator.h"

extern "C" UInt32 FormatTableLookup_0x0004d2dc(UInt32 byteOffset);
extern "C" int kernelTaskRef asm("_kernel_task");
int get_offset_of_sample_0(ATIR500SurfaceBuffer *buffer, int x, int y);
UInt32 write_3dtexquad_cmds_for_copy_buffer_using_DMA(ATIRadeonX1000 *accel, UInt32 *cmd, UInt32 depthWords, UInt32 a3,
    UInt32 srcAddr, UInt32 srcPitch, UInt32 srcPitchShifted, UInt32 srcHeight, UInt32 srcSampleA, UInt32 srcShift,
    unsigned char srcBytes, UInt32 srcFormat, UInt32 dstAddr, UInt32 dstPitch, UInt32 dstPitchShifted, UInt32 dstSampleB,
    UInt32 dstShift, unsigned char dstBytes, long dstX, long dstY, long srcX, long srcY, UInt32 w, UInt32 h, bool flip);

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef void *(*MapKernelFn)(void *, int task, UInt32 address, UInt32 options, UInt32 offset, UInt32 length);
typedef void *(*MapFn)(void *, UInt32 options);
typedef UInt32 (*GetVAFn)(void *);
typedef UInt32 (*GetLengthFn)(void *);
typedef void (*ReleaseFn)(void *);
typedef SInt32 (*StampFn)(void *, UInt32);
typedef void (*VoidFn)(void *, void *);
inline UInt32 FormatShift(UInt32 format) { return (FormatTableLookup_0x0004d2dc(format * 0x1c) >> 12) & 7; }
inline void *Slot(void *obj, int off) { return *reinterpret_cast<void **>(*reinterpret_cast<UInt8 **>(obj) + off); }
inline void Release(void *obj) { reinterpret_cast<ReleaseFn>(Slot(obj, 0x18))(obj); }
} // namespace

UInt32 ATIR500Surface::copy_buffer_using_DMA(SInt32 x, SInt32 y, SInt32 w, SInt32 h, UInt32 index, UInt32 level,
                                             ATIR500SurfaceBuffer *bufferIn, VendorTransferBuffer *transfer,
                                             UInt32 offset, UInt32 pitch, IODirection direction, UInt32 flags) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *buffer = reinterpret_cast<UInt8 *>(bufferIn);
    UInt8 *xfer = reinterpret_cast<UInt8 *>(transfer);
    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
    UInt32 wUnsigned = static_cast<UInt32>(w);
    UInt32 hUnsigned = static_cast<UInt32>(h);
    UInt32 xferSpan = (hUnsigned - 1) * pitch + U16At(buffer, 0x16) * wUnsigned;   /* local_84 */
    if (U8At(accel, 0x80) == 0) {
        return 0;
    }
    UInt32 tiled = (U32At(buffer, 0x3c) >> 11) & 1;
    bool inSwapRange = !(buffer < self + 0x558 || self + 0x738 < buffer);            /* bVar4 */
    if (buffer == self + 0x4e0) {
        return 0;
    }
    bool notTiled = (tiled == 0);                                                    /* bVar1 */
    UInt8 busyFlag = static_cast<UInt8>(tiled ^ 1);                                  /* bVar16 */
    if (!notTiled && (U32At(self, 0xbe8) & 0x7c0000) != 0) {
        return 0;
    }
    SInt32 flipRequested = 0;                                                        /* local_80 */
    if ((flags & 2) != 0 && (U32At(self, 0xbe8) & 0x70000000) == 0) {
        flipRequested = 1;
    }
    bool directPath = (flags & 1) == 0;                                              /* bVar5 */
    if (directPath) {
        if (!notTiled && (U32At(self, 0xbe8) & 0x7c0000) != 0) {
            return 0;
        }
        busyFlag = 1;
    } else if (direction != 1) {
        if (U8At(reinterpret_cast<void *>(U32At(buffer, 0x24)), 0x58) != 0 && !notTiled) {
            return 0;
        }
        busyFlag = 1;
    }
    bool notIn = (direction != 1);                                                   /* bVar7 */
    bool mapClient;                                                                  /* bVar3 */
    if (notIn) {
        mapClient = (direction == 2);
    } else {
        mapClient = ((U32At(accel, 0x98) >> 3) & 1) != 0;
    }
    if ((U32At(accel, 0x98) & 0x20000) != 0 && !mapClient) {
        return 0;
    }
    if (notTiled || directPath) {
        if (inSwapRange && U32At(self, 0xdac) != 0 && !directPath) {
            wUnsigned = U16At(buffer, 0x14);
        }
    } else {
        wUnsigned = U16At(buffer, 0x14);
        if ((hUnsigned & 0x1f) != 0) {
            hUnsigned = ((static_cast<SInt32>(hUnsigned) >> 5) + ((static_cast<SInt32>(hUnsigned) < 0 && (hUnsigned & 0x1f) != 0) ? 1 : 0)) * 0x20 + 0x20;
        }
    }
    if (U32At(buffer, 0x24) != 0) {
        U8At(reinterpret_cast<void *>(U32At(buffer, 0x24)), 0x58) = busyFlag;
        accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
    }

    void *clientMap;
    UInt32 clientAddress;                                                            /* local_88 */
    UInt32 accelBase;                                                                /* iVar14 */
    bool out = (direction == 2);
    if (!mapClient) {
        accelBase = U32At(accel, 0x8a4);
        clientMap = nullptr;
        clientAddress = 0;
    } else {
        void *memory = reinterpret_cast<void *>(U32At(xfer, 8));
        clientMap = (*reinterpret_cast<MapKernelFn>(Slot(memory, 0x14c)))(memory, kernelTaskRef, 0,
                                                                         U32At(accel, 0x82c) | 1, 0, 0);
        if (clientMap == nullptr) {
            return 0;
        }
        clientAddress = reinterpret_cast<GetVAFn>(Slot(clientMap, 0xd0))(clientMap) + offset;
        IOATIR500Accelerator *a = reinterpret_cast<IOATIR500Accelerator *>(U32At(self, 0xd50));
        if (out) {
            if ((U32At(a, 0x98) & 0x80) != 0) {
                a->flush_memory_for_out(reinterpret_cast<const void *>(clientAddress), pitch * hUnsigned);
                a = reinterpret_cast<IOATIR500Accelerator *>(U32At(self, 0xd50));
            }
        } else {
            if ((U32At(a, 0x98) & 0x80) != 0) {
                a->flush_memory_for_in(reinterpret_cast<const void *>(clientAddress), xferSpan);
                a = reinterpret_cast<IOATIR500Accelerator *>(U32At(self, 0xd50));
            }
        }
        accelBase = U32At(a, 0x8a4);
    }
    UInt32 gart = U32At(xfer, 4);
    if (gart == 0) {
        map_transfer_to_GART(transfer);
        gart = U32At(xfer, 4);
    }
    if (flipRequested != 0) {
        if (static_cast<SInt16>(U16At(self, 0xbd6)) == static_cast<SInt16>(U16At(self, 0xbda))) {
            y = static_cast<SInt32>(U16At(buffer, 0x1e) - y - hUnsigned);
        } else {
            y = static_cast<SInt32>(static_cast<SInt16>(U16At(self, 0xbda)) - y - hUnsigned);
        }
    }

    UInt32 dstPitch, srcPitch, dstPitchShifted, srcPitchShifted;                     /* local_94[0], local_98, local_60, local_5c */
    UInt32 srcAddr, dstAddr;                                                         /* local_78, local_7c */
    UInt32 srcHeight;                                                                /* uVar9 */
    UInt32 fmtA, fmtB, sampleA, sampleB;                                             /* uVar19, uVar18, uVar17, uVar20 */
    UInt32 dstBytes, srcBytes;                                                       /* local_64, local_68 */
    SInt32 dstX, dstY, srcX, srcY;                                                   /* local_6c, local_70, local_74, iVar14 */
    if (out) {
        fmtA = U8At(buffer, 0x3a);
        srcPitch = pitch;
        srcAddr = accelBase + offset + gart;
        srcPitchShifted = static_cast<SInt32>(pitch) >> FormatShift(fmtA);
        {
            UInt32 heightWord = U16At(buffer, 0x1e);
            srcHeight = heightWord;
            if (!notTiled && (heightWord & 0x1f) != 0) {
                srcHeight = (heightWord & 0xffffffe0) + 0x20;
            }
        }
        dstBytes = U8At(buffer, 0x39);
        UInt32 bufferBase = U32At(buffer, 8);
        sampleA = 0;
        srcX = x;
        SInt32 mapped = this->buffer_map_offset(bufferIn, index, level, nullptr, nullptr, reinterpret_cast<SInt32 *>(&dstPitch));
        fmtB = U8At(buffer, 0x3a);
        sampleB = U8At(buffer, 0x38);
        dstAddr = bufferBase + mapped;
        srcBytes = 0;
        dstX = 0;
        dstY = 0;
        dstPitchShifted = static_cast<SInt32>(dstPitch) >> FormatShift(fmtB);
        srcY = y;
    } else {
        dstPitch = pitch;
        fmtB = U8At(buffer, 0x3a);
        UInt32 bufferBase = U32At(buffer, 8);
        dstAddr = accelBase + offset + gart;
        dstPitchShifted = static_cast<SInt32>(pitch) >> FormatShift(fmtB);
        srcBytes = U8At(buffer, 0x39);
        SInt32 mapped = this->buffer_map_offset(bufferIn, index, level, nullptr, nullptr, reinterpret_cast<SInt32 *>(&srcPitch));
        srcAddr = bufferBase + mapped;
        {
            UInt32 heightWord = U16At(buffer, 0x1e);
            srcHeight = heightWord;
            if (!notTiled && (heightWord & 0x1f) != 0) {
                srcHeight = (heightWord & 0xffffffe0) + 0x20;
            }
        }
        fmtA = U8At(buffer, 0x3a);
        sampleA = U8At(buffer, 0x38);
        sampleB = 0;
        dstBytes = 0;
        srcX = 0;
        srcPitchShifted = static_cast<SInt32>(srcPitch) >> FormatShift(fmtA);
        dstY = y;
        dstX = x;
        srcY = 0;
    }
    if (!directPath && !notTiled) {
        sampleA = 0;
        sampleB = 0;
    }

    /* claim the next of the four slave swap slots and build the copy into it */
    U32At(reinterpret_cast<void *>(U32At(self, 0xc34)), 0x1c) |= 1;
    UInt32 slot = (U16At(self, 0xcae) + 1) & 3;
    U16At(self, 0xcae) = static_cast<UInt16>(slot);
    if (U32At(self, slot * 0x1c + 0xc44) == 0) {
        if (allocAllSlaveSwapBuffers(0, U32At(self, 0xcb0)) == 0) {
            return 0;
        }
    } else {
        UInt8 *a = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
        UInt32 waited = U32At(a, 0x788);
        SInt32 delta = reinterpret_cast<StampFn>(Slot(a, 0x54c))(a, U32At(self, slot * 0x1c + 0xc4c));
        U32At(a, 0x788) = waited + delta;
    }
    UInt32 *cmd = reinterpret_cast<UInt32 *>(U32At(self, slot * 0x1c + 0xc50) + 0x20);
    UInt32 depthWords;
    if (notIn || notTiled) {
        depthWords = 0;
    } else {
        depthWords = decompress_and_flush_depth_buffer(bufferIn, 0, cmd);
    }
    UInt32 words = write_3dtexquad_cmds_for_copy_buffer_using_DMA(
        reinterpret_cast<ATIRadeonX1000 *>(U32At(self, 0xd50)), cmd, depthWords, fmtA, srcAddr, srcPitch, srcPitchShifted,
        srcHeight, sampleA, FormatShift(fmtA), static_cast<unsigned char>(dstBytes), fmtB, dstAddr, dstPitch, dstPitchShifted,
        sampleB, FormatShift(fmtB), static_cast<unsigned char>(srcBytes), dstX, dstY, srcX, srcY, wUnsigned, hUnsigned,
        flipRequested != 0);
    if (!directPath) {
        U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), 0xb90) = 1;
    }
    U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), 0x78) = 0;
    UInt32 total = words;
    if ((words & 1) != 0) {
        total = words + 1;
        cmd[words] = 0x80000000;
    }
    U32At(reinterpret_cast<void *>(U32At(self, slot * 0x1c + 0xc50)), 0x14) = total;
    UInt32 slotGart = U32At(self, slot * 0x1c + 0xc40);
    UInt16 refs = U16At(xfer, 0xe) + 1;
    U16At(xfer, 0xe) = refs;
    if (slotGart == 0) {
        map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(self + slot * 0x1c + 0xc3c));
        refs = U16At(xfer, 0xe);
        slotGart = U32At(self, slot * 0x1c + 0xc40);
    }
    U16At(xfer, 0xe) = refs - 1;
    UInt32 stamp = reinterpret_cast<ATIRadeonX1000 *>(U32At(self, 0xd50))->submit_buffer(
        reinterpret_cast<UInt32 *>(U32At(self, slot * 0x1c + 0xc50) + 0x20), slotGart + 0x20,
        U32At(reinterpret_cast<void *>(U32At(self, slot * 0x1c + 0xc50)), 0x14));
    U32At(self, 0x7c) = stamp;
    U32At(self, slot * 0x1c + 0xc4c) = stamp;
    if (directPath) {
        UInt8 *a = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
        reinterpret_cast<StampFn>(Slot(a, 0x54c))(a, stamp);
        reinterpret_cast<VoidFn>(Slot(a, 0x5ac))(a, xfer);
        if (mapClient && !notIn && (U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), 0x98) & 0x80) != 0) {
            reinterpret_cast<IOATIR500Accelerator *>(U32At(self, 0xd50))->flush_memory_for_in(
                reinterpret_cast<const void *>(clientAddress), xferSpan);
        }
    } else {
        U32At(reinterpret_cast<void *>(U32At(xfer, 0x14)), 8) = stamp;
    }
    if (clientMap != nullptr) {
        Release(clientMap);
    }
    return 1;
}

/* Byte offset of sample 0 of pixel (x, y) inside a multisampled surface's interleaved sample layout. */
int get_offset_of_sample_0(ATIR500SurfaceBuffer *bufferIn, int x, int y) {
    UInt8 *buffer = reinterpret_cast<UInt8 *>(bufferIn);
    UInt32 flags = U32At(buffer, 0x3c);
    UInt32 samples = (flags >> 0x14) & 0xf;
    int bytesShift;
    int scale;
    if (static_cast<SInt16>(U16At(buffer, 0x16)) == 2) {
        scale = 1;
        bytesShift = 1;
    } else {
        scale = 2;
        bytesShift = 2;
    }
    int rowBase = 0;
    if ((flags & 0xf00000) != 0) {
        rowBase = (y >> 3) * scale * static_cast<int>(samples) * (static_cast<int>(U16At(buffer, 0x14) / samples) >> 2) * 2;
    }
    UInt32 bitX = (static_cast<UInt32>(x) >> 1) & 1;
    UInt32 bitY = (static_cast<UInt32>(y) >> 1) & 1;
    UInt32 swizzle;
    if (samples == 2) {
        swizzle = (bitY << 4) | (bitX << 3);
    } else if (samples == 4 && scale == 2) {
        swizzle = ((bitY ^ ((x >> 2) & 1U)) << 5) | (bitX << 4);
    } else if (samples == 6 && scale == 2) {
        swizzle = (bitX | (bitY << 1)) * 0x18;
    } else {
        swizzle = (bitY << 5) | (bitX << 4);
    }
    return (rowBase + scale * static_cast<int>(samples) * (((x >> 2) << 1) | static_cast<int>((static_cast<UInt32>(y) >> 2) & 1))) * 0x20 +
           static_cast<int>((swizzle | ((static_cast<UInt32>(y) & 1U) << 1) | (static_cast<UInt32>(x) & 1U)) << bytesShift);
}

namespace {
/* the client-memory address the copy reads from or writes to: through the transfer buffer's own mapped descriptor
 * (backing store, when it is current) or mapped with the accelerator's option word */
struct ClientSide {
    void *map1;
    void *map2;
};

inline void CopyBytes(UInt8 *dst, const UInt8 *src, UInt32 count) {
    for (UInt32 i = 0; i < count; ++i) {
        dst[i] = src[i];
    }
}
}

void ATIR500Surface::copy_to_buffer(SInt32 x, SInt32 y, SInt32 w, SInt32 h, UInt32 index, UInt32 level,
                                    ATIR500SurfaceBuffer *bufferIn, UInt32 stamp, VendorTransferBuffer *transfer,
                                    UInt32 offset, UInt32 pitch, UInt32 flags) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *buffer = reinterpret_cast<UInt8 *>(bufferIn);
    UInt8 *xfer = reinterpret_cast<UInt8 *>(transfer);
    UInt8 *backing = reinterpret_cast<UInt8 *>(U32At(buffer, 0x24));
    bool direct = (flags & 1) == 0;
    void *memory;
    if (direct) {
        if (backing == nullptr || U32At(backing, 0x54) != U32At(self, 0x7c)) {
            goto dma;
        }
        memory = reinterpret_cast<void *>(U32At(xfer, 8));
    } else {
        pitch = U16At(backing, 0x52);
        offset = U16At(backing, 0x50);
        {
            void *desc = reinterpret_cast<void *>(U32At(backing, 8));
            UInt32 length = reinterpret_cast<GetLengthFn>(Slot(desc, 0x128))(desc);
            UInt32 rows = 0;
            if (pitch != 0) {
                rows = length / pitch;
            }
            if (static_cast<SInt32>(rows) < h) {
                h = static_cast<SInt32>(rows);
            }
        }
        xfer = backing;
        transfer = reinterpret_cast<VendorTransferBuffer *>(backing);
        if ((U32At(self, 0xbe8) & 0x70000000) != 0) {
            SInt32 rowBytes = static_cast<SInt32>(pitch);
            SInt32 mapped = this->buffer_map_offset(bufferIn, index, level, nullptr, nullptr, &rowBytes);
            pitch = static_cast<UInt32>(rowBytes);
            offset += mapped;
        }
    dma:
        if (copy_buffer_using_DMA(x, y, w, h, index, level, bufferIn, transfer, offset, pitch,
                                  static_cast<IODirection>(2), flags) != 0) {
            return;
        }
        if (direct) {
            memory = reinterpret_cast<void *>(U32At(xfer, 8));
        } else {
            memory = reinterpret_cast<void *>(U32At(backing, 8));
        }
    }
    void *mapA = reinterpret_cast<MapFn>(Slot(memory, 0x150))(memory, U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), 0x82c) | 1);
    if (mapA == nullptr) {
        return;
    }
    {
        UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
        UInt8 *src = reinterpret_cast<UInt8 *>(reinterpret_cast<GetVAFn>(Slot(mapA, 0xd0))(mapA) + offset);
        UInt32 waited = U32At(accel, 0x7b0);
        SInt32 delta = reinterpret_cast<StampFn>(Slot(accel, 0x558))(accel, stamp);
        U32At(accel, 0x7b0) = waited + delta;

        void *mapB;
        bool fromClientBuffer;   /* bVar2: the destination is the surface's own memory, not the backing store */
        UInt32 dstBase;
        if (direct && backing != nullptr && U32At(backing, 0x54) == U32At(self, 0x7c)) {
            void *desc = reinterpret_cast<void *>(U32At(backing, 8));
            mapB = reinterpret_cast<MapFn>(Slot(desc, 0x150))(desc, U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), 0x82c) | 1);
            if (mapB == nullptr) {
                goto done;
            }
            fromClientBuffer = false;
            dstBase = reinterpret_cast<GetVAFn>(Slot(mapB, 0xd0))(mapB) + U16At(backing, 0x50);
        } else {
            mapB = nullptr;
            fromClientBuffer = true;
            dstBase = U32At(buffer, 8) + U32At(self, 0xc10);
        }
        UInt32 pitchWords = U16At(buffer, 0x14);
        UInt32 bytesPerPixel = U16At(buffer, 0x16);
        UInt32 *dst = reinterpret_cast<UInt32 *>(dstBase + bytesPerPixel * (pitchWords * static_cast<UInt32>(y) + static_cast<UInt32>(x)));
        UInt32 units = static_cast<UInt32>(w);
        if (bytesPerPixel == 2) {
            units = (units + 7) >> 3;
        } else if (bytesPerPixel < 3) {
            if (bytesPerPixel == 1) {
                units = (units + 0xf) >> 4;
            } else {
                units = (units + 3) >> 2;
            }
        } else if (bytesPerPixel == 8) {
            units = (units + 1) >> 1;
        } else if (bytesPerPixel != 0x10) {
            units = (units + 3) >> 2;
        }
        if (fromClientBuffer) {
            prepare_vram(bufferIn);
        }
        UInt32 *srcWords = reinterpret_cast<UInt32 *>(src);
        for (SInt32 row = 0; row < h; ++row) {
            UInt32 *s = srcWords;
            UInt32 *d = dst;
            for (UInt32 i = 0; i < units; ++i) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
                d[3] = s[3];
                s += 4;
                d += 4;
            }
            dst = reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(dst) + pitchWords * bytesPerPixel);
            srcWords = reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(srcWords) + pitch);
        }
        if (fromClientBuffer) {
            complete_vram(bufferIn);
        }
        if (mapB != nullptr) {
            Release(mapA);
            Release(mapB);
            return;
        }
    }
done:
    Release(mapA);
}

void ATIR500Surface::copy_from_buffer(SInt32 x, SInt32 y, SInt32 w, SInt32 h, UInt32 index, UInt32 level,
                                      ATIR500SurfaceBuffer *bufferIn, UInt32 stamp, VendorTransferBuffer *transfer,
                                      UInt32 offset, UInt32 pitch, UInt32 flags) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *buffer = reinterpret_cast<UInt8 *>(bufferIn);
    UInt8 *xfer = reinterpret_cast<UInt8 *>(transfer);
    UInt8 *backing = reinterpret_cast<UInt8 *>(U32At(buffer, 0x24));
    bool direct = (flags & 1) == 0;
    void *memory;
    if (direct) {
        if (backing == nullptr || U32At(backing, 0x54) != U32At(self, 0x7c)) {
            goto dma;
        }
        memory = reinterpret_cast<void *>(U32At(xfer, 8));
    } else {
        pitch = U16At(backing, 0x52);
        offset = U16At(backing, 0x50);
        {
            void *desc = reinterpret_cast<void *>(U32At(backing, 8));
            UInt32 length = reinterpret_cast<GetLengthFn>(Slot(desc, 0x128))(desc);
            UInt32 rows = 0;
            if (pitch != 0) {
                rows = length / pitch;
            }
            if (static_cast<SInt32>(rows) < h) {
                h = static_cast<SInt32>(rows);
            }
        }
        xfer = backing;
        transfer = reinterpret_cast<VendorTransferBuffer *>(backing);
        if ((U32At(self, 0xbe8) & 0x70000000) != 0) {
            SInt32 rowBytes = static_cast<SInt32>(pitch);
            SInt32 mapped = this->buffer_map_offset(bufferIn, index, level, nullptr, nullptr, &rowBytes);
            pitch = static_cast<UInt32>(rowBytes);
            offset += mapped;
        }
    dma:
        if (copy_buffer_using_DMA(x, y, w, h, index, level, bufferIn, transfer, offset, pitch,
                                  static_cast<IODirection>(1), flags) != 0) {
            return;
        }
        if (direct) {
            memory = reinterpret_cast<void *>(U32At(xfer, 8));
        } else {
            memory = reinterpret_cast<void *>(U32At(backing, 8));
        }
    }
    void *mapA = reinterpret_cast<MapFn>(Slot(memory, 0x150))(memory, U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), 0x82c) | 1);
    if (mapA == nullptr) {
        return;
    }
    {
        UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
        UInt8 *dst = reinterpret_cast<UInt8 *>(reinterpret_cast<GetVAFn>(Slot(mapA, 0xd0))(mapA) + offset);
        UInt32 waited = U32At(accel, 0x7b4);
        SInt32 delta = reinterpret_cast<StampFn>(Slot(accel, 0x558))(accel, stamp);
        U32At(accel, 0x7b4) = waited + delta;

        UInt32 modeFlags = U32At(buffer, 0x3c);
        UInt32 sampX, sampY;
        if (direct && (modeFlags & 0x800) != 0 && (U32At(self, 0xbe8) & 0xc0000) != 0) {
            sampY = (modeFlags >> 12) & 0xf;
            sampX = (modeFlags >> 16) & 0xf;
        } else {
            sampX = 1;
            sampY = 1;
        }
        SInt32 px = static_cast<SInt32>(sampX) * x;
        SInt32 py = static_cast<SInt32>(sampY) * y;

        void *mapB;
        bool surfaceSide;    /* bVar4: source is the surface's own memory */
        UInt32 srcBase;
        UInt32 rowPitch;     /* uVar28 */
        UInt32 bpp;          /* uVar3 */
        if (direct && backing != nullptr && U32At(backing, 0x54) == U32At(self, 0x7c)) {
            void *desc = reinterpret_cast<void *>(U32At(backing, 8));
            mapB = reinterpret_cast<MapFn>(Slot(desc, 0x150))(desc, U32At(reinterpret_cast<void *>(U32At(self, 0xd50)), 0x82c) | 1);
            if (mapB == nullptr) {
                goto done;
            }
            modeFlags = U32At(buffer, 0x3c);
            surfaceSide = false;
            rowPitch = U16At(backing, 0x52);
            bpp = U16At(buffer, 0x16);
            srcBase = reinterpret_cast<GetVAFn>(Slot(mapB, 0xd0))(mapB) + U16At(backing, 0x50);
        } else {
            modeFlags = U32At(buffer, 0x3c);
            UInt32 levelWidth = 0;
            srcBase = U32At(buffer, 8) + U32At(self, 0xc10);
            if ((modeFlags & 0xf00000) != 0) {
                levelWidth = static_cast<UInt32>(static_cast<SInt32>(U16At(buffer, 0x14) / ((modeFlags >> 0x14) & 0xf)) >> (level & 0x3f));
            }
            bpp = U16At(buffer, 0x16);
            rowPitch = 0x20 / bpp;
            if (rowPitch <= levelWidth) {
                rowPitch = levelWidth;
            }
            mapB = nullptr;
            rowPitch = rowPitch * bpp;
            surfaceSide = true;
        }
        SInt32 levelHeight = static_cast<SInt32>(U16At(buffer, 0x1e)) >> (level & 0x3f);
        UInt8 *src = reinterpret_cast<UInt8 *>(srcBase + U32At(buffer, level * 4 + 0x40) * U16At(buffer, 0x20) +
                                              index * (U32At(buffer, level * 4 + 0x44) - U32At(buffer, level * 4 + 0x40)));
        SInt32 heightAdjust = (levelHeight != 0) ? levelHeight : 1;
        if (direct && (U32At(self, 0xbe8) & 0x70000000) == 0) {
            if (static_cast<SInt16>(U16At(self, 0xbd6)) != static_cast<SInt16>(U16At(self, 0xbda))) {
                heightAdjust = static_cast<SInt16>(U16At(self, 0xbda));
            }
            py = (heightAdjust - py) - static_cast<SInt32>(sampY);
        }
        if ((modeFlags & 0xf00000) == 0x100000 || !direct) {
            SInt32 rowOffset = py * static_cast<SInt32>(rowPitch);
            rowPitch = -rowPitch;
            src += rowOffset + px * static_cast<SInt32>(bpp);
            if (direct) {
                if ((U32At(self, 0xbe8) & 0x70000000) != 0) {
                    rowPitch = -rowPitch;
                }
            } else {
                rowPitch = -rowPitch;
            }
        } else if ((U32At(self, 0xbe8) & 0x70000000) != 0) {
            rowPitch = -rowPitch;
        }
        UInt32 rowBytes = sampX * bpp * static_cast<UInt32>(w);
        if (surfaceSide) {
            prepare_vram(bufferIn);
            modeFlags = U32At(buffer, 0x3c);
        }
        bool sampled = ((modeFlags >> 0x14) & 0xf) >= 2;
        if (direct && sampled) {
            /* multisampled surface, direct path: gather sample 0 of every pixel */
            SInt32 limit = py - h;
            if (limit < py) {
                bool anyPixels = px < px + w;
                do {
                    UInt8 *out = dst;
                    if (anyPixels) {
                        SInt32 column = px;
                        do {
                            int sampleOffset = get_offset_of_sample_0(bufferIn, column, py);
                            const UInt8 *pixel = src + sampleOffset;
                            CopyBytes(out, pixel, U16At(buffer, 0x16));
                            out += U16At(buffer, 0x16);
                            ++column;
                        } while (column < px + w);
                    }
                    --py;
                    dst += pitch;
                } while (limit < py);
            }
        } else {
            if (!direct && sampled) {
                U8At(reinterpret_cast<void *>(U32At(buffer, 0x24)), 0x58) = 0;
            }
            if (sampX == 1) {
                for (SInt32 row = 0; row < h; ++row) {
                    CopyBytes(dst, src, rowBytes);
                    src += sampY * static_cast<SInt32>(rowPitch);
                    dst += pitch;
                }
            } else {
                for (SInt32 row = 0; row < h; ++row) {
                    UInt8 *lineEnd = src + rowBytes;
                    if (src < lineEnd) {
                        UInt32 pixel = U16At(buffer, 0x16);
                        UInt8 *s = src;
                        UInt8 *d = dst;
                        do {
                            CopyBytes(d, s, pixel);
                            s += pixel;
                            d += pixel;
                            pixel = U16At(buffer, 0x16);
                            s += pixel;
                        } while (s < lineEnd);
                    }
                    src += sampY * static_cast<SInt32>(rowPitch);
                    dst += pitch;
                }
            }
        }
        if (surfaceSide) {
            complete_vram(bufferIn);
        }
        if (mapB != nullptr) {
            Release(mapA);
            Release(mapB);
            return;
        }
    }
done:
    Release(mapA);
}
