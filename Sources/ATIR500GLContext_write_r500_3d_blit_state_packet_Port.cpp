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
  UInt8 bVar5;
  UInt32 uVar6;
  UInt32 uVar7;
  SInt32 iVar8;
  UInt32 uVar9;
  UInt32 uVar10;
  UInt32 uVar11;
  UInt8 *pVVar12;
  SInt32 colorBuffer;
  UInt32 uVar14;
  SInt32 iVar15;
  UInt8 *colorRecord;
  
  if (M<SInt32>(self + 0x3bc) == 0) {
    uVar14 = M<UInt32>(self + 0x29c);
    colorBuffer = M<SInt32>((UInt32)M<UInt16>(self + 0xac) * 4 + M<SInt32>(self + 0x290) + 0xb70);
    colorRecord = (UInt8 *)
              ((UInt32)M<UInt16>(self + 0xac) * 0x78 + M<SInt32>(self + 0x290) + 0xa8);
    iVar15 = uVar14 * 4 + colorBuffer;
    iVar8 = M<SInt32>(iVar15 + 0x40);
    formatIndex = M<UInt8>(colorBuffer + 0x3a);
    uVar11 = 0;
    M<UInt32>(packetBytes + 0x268) =
         iVar8 * (UInt32)M<UInt16>(colorBuffer + 0x20) +
         (M<SInt32>(iVar15 + 0x44) - iVar8) * M<SInt32>(self + 0x298) + M<SInt32>(colorBuffer + 8) &
         0xffffffe0;
    if ((M<UInt32>(colorBuffer + 0x3c) & 0xf00000) != 0) {
      uVar11 = (SInt32)((UInt32)M<UInt16>(colorBuffer + 0x14) / (M<UInt32>(colorBuffer + 0x3c) >> 0x14 & 0xf)) >>
               (uVar14 & 0x3f);
    }
    uVar14 = 0x20 / M<UInt16>(colorBuffer + 0x16);
    if (uVar11 < uVar14) {
      uVar11 = uVar14;
    }
    formatIndexCopy = M<UInt8>(colorBuffer + 0x3a);
    tilingByte0 = M<UInt8>(colorBuffer + 0x38);
    tilingByte1 = M<UInt8>(colorBuffer + 0x39);
  }
  else {
    uVar14 = 0;
    colorRecord = self + (UInt32)M<UInt16>(self + 0x3b2) * 0x78 + 0x3c0;
    formatIndex = colorRecord[0x3a];
    M<UInt32>(packetBytes + 0x268) =
         (UInt32)M<UInt16>(colorRecord + 0x20) * M<SInt32>(colorRecord + 0x40) + M<SInt32>(colorRecord + 8) &
         0xffffffe0;
    if ((M<UInt32>(colorRecord + 0x3c) & 0xf00000) != 0) {
      uVar14 = (UInt32)M<UInt16>(colorRecord + 0x14) / (M<UInt32>(colorRecord + 0x3c) >> 0x14 & 0xf);
    }
    uVar11 = 0x20 / M<UInt16>(colorRecord + 0x16);
    if (0x20 / M<UInt16>(colorRecord + 0x16) <= uVar14) {
      uVar11 = uVar14;
    }
    formatIndexCopy = colorRecord[0x3a];
    tilingByte0 = colorRecord[0x38];
    tilingByte1 = colorRecord[0x39];
  }
  iVar8 = (UInt32)(UInt8)formatIndex * 0x1c;
  uVar9 = M<UInt32>(packetBytes + 0x228);
  M<UInt32>(packetBytes + 0x270) =
       uVar11 & 0x3ffe | ((UInt8)tilingByte0 & 1) << 0x10 | ((UInt8)tilingByte0 & 6) << 0x10 |
       ((UInt8)tilingByte1 & 3) << 0x13 |
       FormatTableLookup_0x0004d2e0((UInt32)(UInt8)formatIndexCopy * 0x1c) >> 1 & 0x1e00000;
  uVar11 = FormatTableLookup_0x0004d2e0(iVar8) >> 0x11 & 0x1f;
  M<UInt32>(packetBytes + 0x228) = uVar11 | uVar9 & 0xffffffe0;
  uVar14 = FormatTableLookup_0x0004d2e0(iVar8) >> 7 & 0x300;
  M<UInt32>(packetBytes + 0x228) = uVar14 | uVar11 | uVar9 & 0xfffffce0;
  uVar6 = FormatTableLookup_0x0004d2e0(iVar8) >> 3 & 0xc00;
  M<UInt32>(packetBytes + 0x228) = uVar6 | uVar14 | uVar11 | uVar9 & 0xfffff0e0;
  uVar7 = (FormatTableLookup_0x0004d2e0(iVar8) & 0x1800) << 1;
  M<UInt32>(packetBytes + 0x228) = uVar7 | uVar6 | uVar14 | uVar11 | uVar9 & 0xffffc0e0;
  M<UInt32>(packetBytes + 0x228) =
       (FormatTableLookup_0x0004d2e0(iVar8) & 0x600) << 5 |
       uVar7 | uVar6 | uVar14 | uVar11 | uVar9 & 0xffff00e0;
  uVar10 = M<UInt32>(M<SInt32>(self + 200) + 0xb74);
  M<UInt32>(packetBytes + 0x2b0) = 0xaaaa;
  M<UInt32>(packetBytes + 0x2c) = uVar10;
  uVar10 = this->compute_sc_hyperz_en(M<UInt32>(packetBytes + 0x48));
  M<UInt32>(packetBytes + 0x48) = uVar10;
  uVar10 = this->compute_zb_bw_cntl(M<UInt32>(packetBytes + 0x50));
  M<UInt32>(packetBytes + 0x50) = uVar10;
  if (((((M<UInt32>(colorRecord + 0x28) & 0x3ff00000) == 0x3ff00000) ||
       (colorRecord[0x36] == 0x0)) ||
      ((M<UInt32>(M<SInt32>(self + 0x290) + 0xbe8) & 0x700000) == 0)) ||
     (M<SInt16>(self + 0xac) != 9)) {
    M<UInt32>(packetBytes + 0x80) = 0;
  }
  else {
    M<UInt32>(packetBytes + 0x80) = 0x600;
  }
  pVVar12 = M<UInt8 *>(self + 0x2a4);
  if (pVVar12 == (UInt8 *)0x0) {
    M<UInt32>(packetBytes + 0x27c) = 0xc0001000;
  }
  else {
    bVar5 = M<UInt8>(M<SInt32>(pVVar12 + 0x14) + 0x15);
    uVar11 = this->GetTextureOffset((VendorTextureBuffer *)(pVVar12),false);
    M<UInt32>(packetBytes + 0x280) = bVar5 & 0x1f | uVar11 & 0xffffffe0;
  }
  return;
}
