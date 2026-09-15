/*
 * ATIR500GLContext_WriteR500BlitStatePacket.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real body for
 * `ATIR500GLContext::write_r500_3d_blit_state_packet` - real addr
 * 0x2ac10. See the method's own header comment in
 * `Headers/ATIR500GLContext.h` for the full real-structure summary.
 *
 * Both source-buffer-selection branches converge on an
 * `ATIR500SurfaceBuffer`-shaped record (`Headers/ATIRadeonX1000Types.h`)
 * - every field access below uses that struct's own already-established
 * names (`gpuBaseAddress`/`width`/`bytesPerRow`/`basePitch`/
 * `tilingConfigByte0`/`tilingConfigByte1`/`formatTableIndex`/
 * `tilingDegreeBits`/`mipOffsets`/`fsaaResolvedFlag`), confirmed by
 * exact-offset cross-check against the real decompile's own `+0x8/
 * +0x14/+0x16/+0x20/+0x38/+0x39/+0x3a/+0x3c/+0x40../+0x36` reads.
 *
 * `param_1` (`r500_3d_blit_state_packet_struct*`) is a flat
 * `UInt32 dwords[0x2f4/4]` buffer (no per-field names assigned project-
 * wide yet - see that struct's own header comment) - accessed here by
 * raw byte offset, matching every other reader of this same struct type
 * in this project.
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant - a real, complete, standalone decompile.
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/IOATIR500Surface.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8 &U8At(void *base, int offset) { return *reinterpret_cast<UInt8 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

void ATIR500GLContext::write_r500_3d_blit_state_packet(r500_3d_blit_state_packet_struct *packet) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *pkt = reinterpret_cast<UInt8 *>(packet);

    ATIR500SurfaceBuffer *srcBuf;
    UInt32 mipDelta = 0; /* the branch-1-only "next mip offset" delta multiplier accumulator */
    UInt32 mipIndex = 0;
    UInt32 rowsCandidate;
    UInt8 fmtIdx, tileByte0, tileByte1;

    if (U32At(self, 0x3bc) == 0) {
        mipIndex = static_cast<UInt32>(U32At(self, 0x29c));
        UInt16 surfIdx = U16At(self, 0xac);
        UInt8 *boundSurf = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
        ATIR500SurfaceBuffer *tableEntry = *reinterpret_cast<ATIR500SurfaceBuffer **>(boundSurf + surfIdx * 4 + 0xb70);
        srcBuf = reinterpret_cast<ATIR500SurfaceBuffer *>(boundSurf + surfIdx * 0x78 + 0xa8);

        UInt32 off0 = tableEntry->mipOffsets[mipIndex];
        UInt32 off1 = tableEntry->mipOffsets[mipIndex + 1];
        U32At(pkt, 0x268) = (off0 * tableEntry->basePitch + (off1 - off0) * U32At(self, 0x298) +
                              tableEntry->gpuBaseAddress) & 0xffffffe0u;

        if ((tableEntry->tilingDegreeBits & 0xf00000u) != 0) {
            mipDelta = (static_cast<UInt32>(tableEntry->width) / ((tableEntry->tilingDegreeBits >> 0x14) & 0xfu)) >> (mipIndex & 0x3f);
        }
        rowsCandidate = 0x20u / tableEntry->bytesPerRow;
        if (mipDelta < rowsCandidate) {
            mipDelta = rowsCandidate;
        }
        fmtIdx = tableEntry->formatTableIndex;
        tileByte0 = tableEntry->tilingConfigByte0;
        tileByte1 = tableEntry->tilingConfigByte1;
    } else {
        UInt16 altSlot = U16At(self, 0x3b2);
        srcBuf = reinterpret_cast<ATIR500SurfaceBuffer *>(self + altSlot * 0x78 + 0x3c0);

        U32At(pkt, 0x268) = (static_cast<UInt32>(srcBuf->basePitch) * srcBuf->mipOffsets[0] +
                              srcBuf->gpuBaseAddress) & 0xffffffe0u;

        if ((srcBuf->tilingDegreeBits & 0xf00000u) != 0) {
            mipDelta = static_cast<UInt32>(srcBuf->width) / ((srcBuf->tilingDegreeBits >> 0x14) & 0xfu);
        }
        rowsCandidate = 0x20u / srcBuf->bytesPerRow;
        if (rowsCandidate <= mipDelta) {
            rowsCandidate = mipDelta;
        }
        mipDelta = rowsCandidate;
        fmtIdx = srcBuf->formatTableIndex;
        tileByte0 = srcBuf->tilingConfigByte0;
        tileByte1 = srcBuf->tilingConfigByte1;
    }

    UInt32 fmtByteOff = static_cast<UInt32>(fmtIdx) * 0x1c;
    UInt32 origReg228 = U32At(pkt, 0x228);

    U32At(pkt, 0x270) = (mipDelta & 0x3ffeu) | (static_cast<UInt32>(tileByte0 & 1) << 0x10) |
                         (static_cast<UInt32>(tileByte0 & 6) << 0x10) |
                         (static_cast<UInt32>(tileByte1 & 3) << 0x13) |
                         ((FormatTableLookup_0x0004d2e0(fmtByteOff) >> 1) & 0x1e00000u);

    UInt32 bits1 = (FormatTableLookup_0x0004d2e0(fmtByteOff) >> 0x11) & 0x1f;
    U32At(pkt, 0x228) = bits1 | (origReg228 & 0xffffffe0u);
    UInt32 bits2 = (FormatTableLookup_0x0004d2e0(fmtByteOff) >> 7) & 0x300;
    U32At(pkt, 0x228) = bits2 | bits1 | (origReg228 & 0xfffffce0u);
    UInt32 bits3 = (FormatTableLookup_0x0004d2e0(fmtByteOff) >> 3) & 0xc00;
    U32At(pkt, 0x228) = bits3 | bits2 | bits1 | (origReg228 & 0xfffff0e0u);
    UInt32 bits4 = (FormatTableLookup_0x0004d2e0(fmtByteOff) & 0x1800) << 1;
    U32At(pkt, 0x228) = bits4 | bits3 | bits2 | bits1 | (origReg228 & 0xffffc0e0u);
    UInt32 bits5 = (FormatTableLookup_0x0004d2e0(fmtByteOff) & 0x600) << 5;
    U32At(pkt, 0x228) = bits5 | bits4 | bits3 | bits2 | bits1 | (origReg228 & 0xffff00e0u);

    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0xc8));
    UInt32 accelField = U32At(accel, 0xb74);
    U32At(pkt, 0x2b0) = 0xaaaa;
    U32At(pkt, 0x2c) = accelField;
    U32At(pkt, 0x48) = compute_sc_hyperz_en(U32At(pkt, 0x48));
    U32At(pkt, 0x50) = compute_zb_bw_cntl(U32At(pkt, 0x50));

    UInt8 *boundSurfForFlag = reinterpret_cast<UInt8 *>(U32At(self, 0x290));
    if ((srcBuf->tilingDegreeBits & 0x3ff00000u) == 0x3ff00000u ||
        srcBuf->fsaaResolvedFlag == 0 ||
        (U32At(boundSurfForFlag, 0xbe8) & 0x700000u) == 0 ||
        U16At(self, 0xac) != 9) {
        U32At(pkt, 0x80) = 0;
    } else {
        U32At(pkt, 0x80) = 0x600;
    }

    VendorTextureBuffer *texture = reinterpret_cast<VendorTextureBuffer *>(U32At(self, 0x2a4));
    if (texture == nullptr) {
        U32At(pkt, 0x27c) = 0xc0001000;
    } else {
        UInt8 *tex = reinterpret_cast<UInt8 *>(texture);
        UInt8 flagByte = U8At(reinterpret_cast<void *>(U32At(tex, 0x14)), 0x15);
        UInt32 texOffset = GetTextureOffset(texture, false);
        U32At(pkt, 0x280) = (flagByte & 0x1f) | (texOffset & 0xffffffe0u);
    }
}
