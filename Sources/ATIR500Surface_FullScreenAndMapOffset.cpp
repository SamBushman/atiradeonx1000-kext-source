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

void ATIR500Surface::setupFullScreen() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 side = U8At(self, 0x158);
    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
    UInt32 panel = U32At(self, 0xc14);
    U32At(self, 0xdb8) = U8At(accel + panel * 0x78, 0x164);
    U8At(accel + panel * 0x78, 0x164) = side;
    if ((U32At(self, 0xbe8) & 0x10) != 0) {
        U8At(self, U32At(self, 0xc14) + 0xdb6) = 1;
    }
    accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
    if (U8At(accel, 0x9b0) != 0) {
        panel = U32At(self, 0xc14);
        UInt32 other = 0;
        bool touchOther = false;
        if (U32At(accel, panel * 0x18 + 0xb10) == 0) {
            if (U32At(accel, 0x894) != 0) {
                other = (panel == 0) ? 1u : 0u;
                if (U32At(accel, other * 0x18 + 0xb10) != 0) {
                    touchOther = true;
                }
            }
            if (touchOther) {
                UInt8 *rec = accel + other * 0x78;
                U8At(rec, 0x9f4) = side;
                U8At(rec, 0x164) = side;
            }
        } else {
            U8At(accel + panel * 0x78, 0x9f4) = side;
            accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
            if (U32At(accel, 0x894) != 0) {
                other = (U32At(self, 0xc14) == 0) ? 1u : 0u;
                UInt8 *rec = accel + other * 0x78;
                if (U32At(accel, other * 0x18 + 0xb10) == 0) {
                    U8At(rec, 0x164) = side;
                } else {
                    U8At(rec, 0x9f4) = side;
                    U8At(rec, 0x164) = side;
                }
            }
        }
    }

    if (is_flip_allowed() == 0) {
        accel = reinterpret_cast<UInt8 *>(U32At(self, 0xd50));
        UInt8 *mmio = reinterpret_cast<UInt8 *>(U32At(accel, 0x860));
        UInt8 b7 = U8At(mmio, 0x6107);
        UInt8 b5 = U8At(mmio, 0x6105);
        UInt8 b4 = U8At(mmio, 0x6104);
        panel = U32At(self, 0xc14);
        UInt32 field6 = (U8At(mmio, 0x6106) & 0xffcfu) << 0x10;
        UInt32 sideAtPanel = U8At(accel + panel * 0x78, 0x164);
        UInt32 bit1 = (sideAtPanel & 1u) << 0x15;
        UInt32 bit2 = (sideAtPanel > 1) ? 0x100000u : 0u;
        UInt32 regOffset = (panel == 0) ? 0x6104u : 0x6904u;
        UInt32 value = (static_cast<UInt32>(b4) << 0x18) | (static_cast<UInt32>(b5) << 0x10) |
                       ((bit2 | field6 | bit1) >> 8) | static_cast<UInt32>(b7);
        U32At(mmio, regOffset) = value;
        enforceInOrderExecutionIO();
        if (U32At(accel, 0x894) != 0) {
            UInt32 otherRegOffset = (panel == 0) ? 0x6904u : 0x6104u;
            U32At(mmio, otherRegOffset) = value;
            enforceInOrderExecutionIO();
        }
    }
    IOATIR500Surface::setupFullScreen();
}

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
