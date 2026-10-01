/*
 * ATIR500Surface_FullScreenAndMapOffset.cpp
 *
 * RESOLVED (ledger pass): two ATIR500Surface virtuals that had no body in the rebuild (real addrs in parentheses):
 *   setupFullScreen (0x3d200, vtable +0x5a4)   buffer_map_offset (0x3d150, vtable +0x5f0)
 *
 * setupFullScreen is the mirror image of ATIR500Surface::resetFullScreen (ATIR500Surface_ResetFullScreen.cpp):
 * it saves the panel's current "side" byte (accelerator record +0x164) into this+0xdb8 and installs this+0x158,
 * marks the panel in use (this+0xdb6+panel) when the mode bits ask for it, mirrors the value into the other
 * panel's record under the same nested conditions, reprograms the CRTC control register when the surface is not
 * flip-capable, and finally runs the base class's setupFullScreen.
 *
 * buffer_map_offset returns the byte offset of mip level `level` within a surface buffer and reports that level's
 * width, height and byte size through the optional out pointers.
 */

#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/* (re-ported mechanically: see ATIR500Surface_setupFullScreen_Port.cpp) */


SInt32 ATIR500Surface::buffer_map_offset(ATIR500SurfaceBuffer *bufferIn, UInt32 index, UInt32 level, SInt32 *outWidth,
                                          SInt32 *outHeight, SInt32 *outBytes) {
    UInt8 *buffer = reinterpret_cast<UInt8 *>(bufferIn);
    if (outWidth != nullptr) {
        UInt32 flags = U32At(buffer, 0x3c);
        SInt32 width;
        if ((flags & 0xf00000) == 0) {
            width = 1;
        } else {
            width = static_cast<SInt32>(U16At(buffer, 0x1c) / ((flags >> 0x14) & 0xf)) >> (level & 0x3f);
            if (width == 0) {
                width = 1;
            }
        }
        *outWidth = width * static_cast<SInt32>((flags >> 0x14) & 0xf);
    }
    if (outHeight != nullptr) {
        SInt32 height = static_cast<SInt32>(U16At(buffer, 0x1e)) >> (level & 0x3f);
        *outHeight = (height != 0) ? height : 1;
    }
    if (outBytes != nullptr) {
        UInt32 bytes = static_cast<UInt32>(static_cast<SInt32>(U16At(buffer, 0x14) * U16At(buffer, 0x16)) >> (level & 0x3f));
        *outBytes = (bytes > 0x1f) ? bytes : 0x20;
    }
    return static_cast<SInt32>(U32At(buffer, level * 4 + 0x40) * U16At(buffer, 0x20) +
                               index * (U32At(buffer, level * 4 + 0x44) - U32At(buffer, level * 4 + 0x40)));
}
