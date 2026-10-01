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

/* (re-ported mechanically: see ATIR500Surface_copy_buffer_using_DMA_Port.cpp) */


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

/* (re-ported mechanically: see ATIR500Surface_copy_to_buffer_Port.cpp) */


/* (re-ported mechanically: see ATIR500Surface_copy_from_buffer_Port.cpp) */

