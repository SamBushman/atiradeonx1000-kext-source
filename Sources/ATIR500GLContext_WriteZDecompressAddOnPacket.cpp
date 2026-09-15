/*
 * ATIR500GLContext_WriteZDecompressAddOnPacket.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real body for
 * `ATIR500GLContext::write_r500_zdecompress_restore_add_on_packet` -
 * real addr 0x28780. See the method's own header comment in
 * `Headers/ATIR500GLContext.h` and `r500_zdecompress_restore_add_on_
 * packet_struct`'s own header comment in `Headers/ATIRadeonX1000Types.h`
 * (a real struct-size bug fixed alongside this transcription).
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant - a real, complete, standalone decompile.
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Registers.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

void ATIR500GLContext::write_r500_zdecompress_restore_add_on_packet(r500_zdecompress_restore_add_on_packet_struct *packet) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *pkt = reinterpret_cast<UInt8 *>(packet);

    ATIR500SurfaceBuffer *srcBuf = reinterpret_cast<ATIR500SurfaceBuffer *>(self + 0x5a0);
    if (U32At(self, 0x3bc) == 0) {
        UInt16 surfIdx = U16At(self, 0xae);
        UInt8 *boundSurf = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
        srcBuf = *reinterpret_cast<ATIR500SurfaceBuffer **>(boundSurf + surfIdx * 4 + 0xb70);
    }

    U32At(pkt, 4) = (srcBuf->formatTableIndex != 0x10) ? 2u : 0u;
    U32At(pkt, 0xc) = srcBuf->gpuBaseAddress;

    UInt32 rowsCandidate = 0;
    if ((srcBuf->tilingDegreeBits & 0xf00000u) != 0) {
        rowsCandidate = static_cast<UInt32>(srcBuf->width) / ((srcBuf->tilingDegreeBits >> 0x14) & 0xfu);
    }
    UInt32 minRows = 0x20u / srcBuf->bytesPerRow;
    if (minRows <= rowsCandidate) {
        minRows = rowsCandidate;
    }

    U32At(pkt, 0x10) = (static_cast<UInt32>(srcBuf->tilingConfigByte0 & 6) << 0x10) |
                        (static_cast<UInt32>(srcBuf->tilingConfigByte0 & 1) << 0x10) |
                        (static_cast<UInt32>(srcBuf->tilingConfigByte1 & 3) << 0x13) |
                        (minRows & 0x3ffcu);

    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));
    UInt32 divisor = U32At(accel, 0xb98);
    UInt32 blockSize;
    if (divisor == 4) {
        blockSize = 0x20u * ((0x20u + minRows - 1) / 0x20u);
    } else {
        UInt32 scaled = divisor << 4;
        blockSize = 0;
        if (scaled != 0) {
            blockSize = scaled * ((scaled + minRows - 1) / scaled);
        }
    }
    U32At(pkt, 0x18) = blockSize;

    U32At(pkt, 0x20) = HZMEM_GetBlockOffset(reinterpret_cast<_HZDATA *>(accel + 0x870), srcBuf->hzBlockField, 0);
    U32At(pkt, 0x28) = srcBuf->hzBlockExtra;
}
