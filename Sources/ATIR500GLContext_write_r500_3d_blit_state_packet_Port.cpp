/*
 * ATIR500GLContext_write_r500_3d_blit_state_packet_Port.cpp
 *
 * ATIR500GLContext::write_r500_3d_blit_state_packet (real addr 0x2ac10, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
 * Tools/port_fn.py); replaces the earlier hand-written body, which the callee/atomics comparison (Tools/callee_compare.py) showed had
 * dropped or simplified parts of the original.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIR5002DContext.h"
#include "../Headers/ATIR500DVDContext.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/GhidraExterns.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"



/* real addr 0x2ac10 */
void ATIR500GLContext::write_r500_3d_blit_state_packet(r500_3d_blit_state_packet_struct *packet) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *packetBytes = reinterpret_cast<UInt8 *>(packet);

  UInt8 formatIndex;
  UInt8 formatIndexCopy;
  UInt8 tilingByte0;
  UInt8 tilingByte1;
  SInt32 colorBuffer;
  UInt8 *colorRecord;
  UInt32 mipLevel;
  UInt32 minPitch;
  UInt32 sampledPitch;
  UInt32 fmtField1;
  UInt32 pitchPixels;
  UInt32 fmtField0;
  UInt32 slot0Offset;
  UInt32 fmtField2;
  UInt32 fmtField3;
  UInt32 oldFormatWord;
  SInt32 sliceOffset;
  SInt32 formatTableOffset;
  SInt32 mipOffsetEntry;
  UInt32 stateWord;
  UInt32 hyperzEnable;
  UInt32 zbBwCntl;
  UInt8 *slot0Texture;
  UInt8 textureFormatByte;
  
  if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
    mipLevel = M<UInt32>(self + kIOATIR500GLContext_mipLevel);
    colorBuffer = M<SInt32>((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
    colorRecord = (UInt8 *)
              ((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) * 0x78 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xa8);
    mipOffsetEntry = mipLevel * 4 + colorBuffer;
    sliceOffset = M<SInt32>(mipOffsetEntry + 0x40);
    formatIndex = M<UInt8>(colorBuffer + 0x3a);
    pitchPixels = 0;
    M<UInt32>(packetBytes + 0x268) =
         sliceOffset * (UInt32)M<UInt16>(colorBuffer + 0x20) +
         (M<SInt32>(mipOffsetEntry + 0x44) - sliceOffset) * M<SInt32>(self + kIOATIR500GLContext_surfaceIndex) + M<SInt32>(colorBuffer + 8) &
         0xffffffe0;
    if ((M<UInt32>(colorBuffer + 0x3c) & 0xf00000) != 0) {
      pitchPixels = (SInt32)((UInt32)M<UInt16>(colorBuffer + 0x14) / (M<UInt32>(colorBuffer + 0x3c) >> 0x14 & 0xf)) >>
               (mipLevel & 0x3f);
    }
    minPitch = 0x20 / M<UInt16>(colorBuffer + 0x16);
    if (pitchPixels < minPitch) {
      pitchPixels = minPitch;
    }
    formatIndexCopy = M<UInt8>(colorBuffer + 0x3a);
    tilingByte0 = M<UInt8>(colorBuffer + 0x38);
    tilingByte1 = M<UInt8>(colorBuffer + 0x39);
  }
  else {
    sampledPitch = 0;
    colorRecord = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
    formatIndex = colorRecord[0x3a];
    M<UInt32>(packetBytes + 0x268) =
         (UInt32)M<UInt16>(colorRecord + 0x20) * M<SInt32>(colorRecord + 0x40) + M<SInt32>(colorRecord + 8) &
         0xffffffe0;
    if ((M<UInt32>(colorRecord + 0x3c) & 0xf00000) != 0) {
      sampledPitch = (UInt32)M<UInt16>(colorRecord + 0x14) / (M<UInt32>(colorRecord + 0x3c) >> 0x14 & 0xf);
    }
    pitchPixels = 0x20 / M<UInt16>(colorRecord + 0x16);
    if (0x20 / M<UInt16>(colorRecord + 0x16) <= sampledPitch) {
      pitchPixels = sampledPitch;
    }
    formatIndexCopy = colorRecord[0x3a];
    tilingByte0 = colorRecord[0x38];
    tilingByte1 = colorRecord[0x39];
  }
  formatTableOffset = (UInt32)(UInt8)formatIndex * 0x1c;
  oldFormatWord = M<UInt32>(packetBytes + 0x228);
  M<UInt32>(packetBytes + 0x270) =
       pitchPixels & 0x3ffe | ((UInt8)tilingByte0 & 1) << 0x10 | ((UInt8)tilingByte0 & 6) << 0x10 |
       ((UInt8)tilingByte1 & 3) << 0x13 |
       FormatTableLookup_0x0004d2e0((UInt32)(UInt8)formatIndexCopy * 0x1c) >> 1 & 0x1e00000;
  fmtField0 = FormatTableLookup_0x0004d2e0(formatTableOffset) >> 0x11 & 0x1f;
  M<UInt32>(packetBytes + 0x228) = fmtField0 | oldFormatWord & 0xffffffe0;
  fmtField1 = FormatTableLookup_0x0004d2e0(formatTableOffset) >> 7 & 0x300;
  M<UInt32>(packetBytes + 0x228) = fmtField1 | fmtField0 | oldFormatWord & 0xfffffce0;
  fmtField2 = FormatTableLookup_0x0004d2e0(formatTableOffset) >> 3 & 0xc00;
  M<UInt32>(packetBytes + 0x228) = fmtField2 | fmtField1 | fmtField0 | oldFormatWord & 0xfffff0e0;
  fmtField3 = (FormatTableLookup_0x0004d2e0(formatTableOffset) & 0x1800) << 1;
  M<UInt32>(packetBytes + 0x228) = fmtField3 | fmtField2 | fmtField1 | fmtField0 | oldFormatWord & 0xffffc0e0;
  M<UInt32>(packetBytes + 0x228) =
       (FormatTableLookup_0x0004d2e0(formatTableOffset) & 0x600) << 5 |
       fmtField3 | fmtField2 | fmtField1 | fmtField0 | oldFormatWord & 0xffff00e0;
  stateWord = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
  M<UInt32>(packetBytes + 0x2b0) = 0xaaaa;
  M<UInt32>(packetBytes + 0x2c) = stateWord;
  hyperzEnable = this->compute_sc_hyperz_en(M<UInt32>(packetBytes + 0x48));
  M<UInt32>(packetBytes + 0x48) = hyperzEnable;
  zbBwCntl = this->compute_zb_bw_cntl(M<UInt32>(packetBytes + 0x50));
  M<UInt32>(packetBytes + 0x50) = zbBwCntl;
  if (((((M<UInt32>(colorRecord + 0x28) & 0x3ff00000) == 0x3ff00000) ||
       (colorRecord[0x36] == 0x0)) ||
      ((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xbe8) & 0x700000) == 0)) ||
     (M<SInt16>(self + kIOATIR500GLContext_colorBufferIndex) != 9)) {
    M<UInt32>(packetBytes + 0x80) = 0;
  }
  else {
    M<UInt32>(packetBytes + 0x80) = 0x600;
  }
  slot0Texture = M<UInt8 *>(self + kATIR500GLContext_textureSlots);
  if (slot0Texture == (UInt8 *)0x0) {
    M<UInt32>(packetBytes + 0x27c) = 0xc0001000;
  }
  else {
    textureFormatByte = M<UInt8>(M<SInt32>(slot0Texture + 0x14) + 0x15);
    slot0Offset = this->GetTextureOffset((VendorTextureBuffer *)(slot0Texture),false);
    M<UInt32>(packetBytes + 0x280) = textureFormatByte & 0x1f | slot0Offset & 0xffffffe0;
  }
  return;
}
