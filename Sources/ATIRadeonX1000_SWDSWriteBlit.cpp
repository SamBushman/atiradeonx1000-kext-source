/*
 * ATIRadeonX1000_SWDSWriteBlit.cpp
 *
 * RESOLVED (ledger pass): ATIRadeonX1000::SWDSWriteBlitToCmdBuf (real addr 0x23320, 4040 bytes): emits the software display scaler
 * blit (per-panel surface, 3D blit state packet or pcl_CopyPix for tall surfaces) into a command buffer and returns the new
 * dword count.
 * Mechanically ported from the Ghidra decompile of the shipped kext (Tools/port_fn.py); the resolved data references
 * (metaClass / page_shift / page_size / plane symbols) come from the kext relocation table.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/GhidraExterns.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

extern "C" UInt32 GH_IOFreeAligned(...) asm("_IOFreeAligned");
extern "C" UInt32 GH_IOMallocAligned(...) asm("_IOMallocAligned");
extern "C" UInt32 GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(...) asm("__ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass");
extern "C" UInt32 GH_ZN18IOMemoryDescriptor11withAddressEPvm11IODirection(...) asm("__ZN18IOMemoryDescriptor11withAddressEPvm11IODirection");
extern "C" UInt32 GH_ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_(...) asm("__ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_E");
extern "C" UInt32 GH_ZN8OSObjectnwEm(...) asm("__ZN8OSObjectnwEm");
extern "C" UInt32 GH_ZN8OSSymbol17withCStringNoCopyEPKc(...) asm("__ZN8OSSymbol17withCStringNoCopyEPKc");
extern "C" UInt32 GH_ZN9IOServiceC1Ev(...) asm("__ZN9IOServiceC1Ev");
extern "C" UInt32 GH_memcpy(...) asm("_memcpy");
extern "C" UInt32 GH_memset(...) asm("_memset");

struct pcl_ParamsR500_t;
UInt32 *pcl_CopyPix(UInt32 *cmd, pcl_ParamsR500_t *params, bool flipHorizontally, bool flipVertically);
extern "C" const r500_3d_blit_state_packet_struct g_r500_3d_blit_state_packet;

/* real addr 0x23320 */
UInt32 ATIRadeonX1000::SWDSWriteBlitToCmdBuf(UInt32 *buffer, UInt32 wordCount, bool flag, UInt32 panel) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt8 AVar2;
  UInt16 uVar3;
  UInt16 uVar4;
  float fVar5;
  float fVar6;
  UInt32 uVar7;
  UInt32 uVar8;
  SInt32 packetEnd;
  SInt32 baseOffset;
  SInt32 regValueIndex;
  UInt32 uVar10;
  UInt32 uVar11;
  UInt32 blkFormatFieldE4;
  UInt32 uVar12;
  UInt32 in_register_00000018;
  UInt32 uVar13;
  SInt32 iVar14;
  UInt32 uVar15;
  SInt32 rotation;
  SInt32 pitch;
  SInt32 endAddress;
  UInt32 uVar17;
  UInt32 packetFormatFieldE4;
  UInt32 blkFormatFieldE0;
  UInt32 uVar18;
  UInt32 uVar19;
  UInt32 uVar20;
  UInt32 *blitPacket;
  UInt32 widthUnits;
  UInt32 pitchUnits;
  UInt32 lastColumn;
  UInt32 lastRow;
  UInt32 bufferFormatWord;
  UInt32 blk[35];   /* the pcl_ParamsR500_t block on the shipped stack: 0x8c bytes at sp+0x40 (Ghidra blk[0] .. blk[34]) */
  UInt16 rect[4];   /* the 8-byte rectangle at sp+0x38 (Ghidra rect[0] .. rect[3]) */
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  UInt32 local_a8;
  UInt32 uStack_a4;
  UInt32 local_a0;
  UInt32 uStack_9c;
  UInt32 local_98;
  UInt32 uStack_94;
  UInt32 local_90;
  UInt32 uStack_8c;
  
  dVar25 = DOUBLE_0004c3b0;
  uStack_a4 = (UInt32)M<UInt16>(self + panel * 0x78 + 0x9d8);
  rotation = M<SInt32>(self + panel * 4 + 0xb5c);
  local_a8 = 0x43300000;
  uStack_9c = (UInt32)M<UInt16>(self + panel * 0x78 + 0x9da);
  local_a0 = 0x43300000;
  M<UInt32>(self + kIOATIR500Accelerator_unknown_0x78) = 0;
  BF(blk[23]) = (float)((double)CONCAT44d(0x43300000,uStack_a4) - dVar25);
  dVar24 = (double)BF(blk[23]);
  BF(blk[24]) = (float)((double)CONCAT44d(0x43300000,uStack_9c) - dVar25);
  dVar25 = (double)BF(blk[24]);
  if (((UInt32)flag) != 0) {
    uVar3 = M<UInt16>(self + panel * 0x78 + 0x9da);
    buffer[wordCount] = 0x5c8;
    buffer[wordCount + 1] = 0x70000;
    if (panel == 0) {
      buffer[wordCount + 2] = 0x194e;
      buffer[wordCount + 3] = ((UInt32)uVar3 & ~M<UInt32>(self + kIOATIR500Accelerator_display1Enabled)) << 0x10 | 0x80000000;
      buffer[wordCount + 4] = 0x5c8;
      regValueIndex = wordCount + 5;
      wordCount = wordCount + 6;
      buffer[regValueIndex] = 8;
    }
    else {
      buffer[wordCount + 2] = 0x1b4e;
      buffer[wordCount + 3] = ((UInt32)uVar3 & ~M<UInt32>(self + kIOATIR500Accelerator_display2Enabled)) << 0x10 | 0x80000000;
      buffer[wordCount + 4] = 0x5c8;
      regValueIndex = wordCount + 5;
      wordCount = wordCount + 6;
      buffer[regValueIndex] = 0x80000008;
    }
  }
  if (0x1000 < M<UInt16>(self + panel * 0x78 + 0x148)) {
    rect[0] = 0;
    rect[1] = 1;
    blk[17] = blk[17] | 0xf8000000;
    widthUnits = 0;
    rect[2] = M<UInt16>(self + panel * 0x78 + 0x148);
    blk[10] = M<UInt32>(self + kIOATIR500Accelerator_gbTileConfig);
    rect[3] = M<UInt16>(self + panel * 0x78 + 0x14a);
    uStack_94 = (UInt32)M<UInt16>(self + panel * 0x78 + 0x148);
    blk[11] = (UInt32)(UInt8)self[panel * 0x78 + 0x166];
    blk[12] = (UInt32)(UInt8)self[panel * 0x78 + 0x9f6];
    local_98 = 0x43300000;
    uStack_8c = (UInt32)M<UInt16>(self + panel * 0x78 + 0x14a);
    blk[4] = 0x1492;
    blk[8] = 0;
    local_90 = 0x43300000;
    blk[18] = 1;
    blk[20] = (UInt32)rect;
    blk[19] = 0;
    blk[26] = 0;
    blk[32] = 0x3f800000;
    blk[34] = 0;
    blk[21] = 0;
    blk[22] = 0;
    blk[25] = 0;
    blk[29] = 0x3f800000;
    blk[30] = 0x3f800000;
    blk[31] = 0x3f800000;
    BF(blk[27]) = (float)((double)CONCAT44d(0x43300000,uStack_94) - DOUBLE_0004c3b0);
    BF(blk[28]) = (float)((double)CONCAT44d(0x43300000,uStack_8c) - DOUBLE_0004c3b0);
    blk[6] = (UInt32)M<UInt16>(self + panel * 0x78 + 0x9dc) *
                M<SInt32>(self + panel * 0x78 + 0x9fc) + M<SInt32>(self + panel * 0x78 + 0x9c4) &
                0xffffffe0;
    if ((M<UInt32>(self + panel * 0x78 + 0x9f8) & 0xf00000) != 0) {
      widthUnits = (UInt32)M<UInt16>(self + panel * 0x78 + 0x9d0) /
               (M<UInt32>(self + panel * 0x78 + 0x9f8) >> 0x14 & 0xf);
    }
    pitchUnits = 0x20 / M<UInt16>(self + panel * 0x78 + 0x9d2);
    if (0x20 / M<UInt16>(self + panel * 0x78 + 0x9d2) <= widthUnits) {
      pitchUnits = widthUnits;
    }
    blkFormatFieldE0 = FormatTableLookup_0x0004d2e0((UInt32)(UInt8)self[panel * 0x78 + 0x9f6] * 0x1c);
    blk[5] = pitchUnits & 0x3ffe | ((UInt8)self[panel * 0x78 + 0x9f4] & 1) << 0x10 |
                ((UInt8)self[panel * 0x78 + 0x9f4] & 6) << 0x10 |
                ((UInt8)self[panel * 0x78 + 0x9f5] & 3) << 0x13 |
                FormatTableLookup_0x0004d2e0((UInt32)(UInt8)self[panel * 0x78 + 0x9f6] * 0x1c) >> 1 &
                0x1e00000;
    blk[7] = (blkFormatFieldE0 & 0x600) << 5 |
                (blkFormatFieldE0 & 0x1800) << 1 |
                blkFormatFieldE0 >> 3 & 0xc00 | blkFormatFieldE0 >> 7 & 0x300 | blkFormatFieldE0 >> 0x11 & 0x1f;
    if (((M<UInt32>(self + panel * 0x78 + 0x9f8) & 0xf00000) == 0) ||
       (uVar10 = (UInt32)M<UInt16>(self + panel * 0x78 + 0x9d8) /
                 (M<UInt32>(self + panel * 0x78 + 0x9f8) >> 0x14 & 0xf), lastColumn = uVar10 - 1,
       uVar10 == 0)) {
      lastColumn = 0;
    }
    lastRow = 0;
    if (M<UInt16>(self + panel * 0x78 + 0x9da) != 0) {
      lastRow = M<UInt16>(self + panel * 0x78 + 0x9da) - 1;
    }
    blk[9] = lastColumn & 0x1fff | (lastRow & 0x1fff) << 0xd;
    blk[0] = ((UInt8)self[panel * 0x78 + 0x164] & 7) << 2 |
                (UInt32)M<UInt16>(self + panel * 0x78 + 0x14c) *
                M<SInt32>(self + panel * 0x78 + 0x16c) + M<SInt32>(self + panel * 0x78 + 0x134) &
                0xffffffe0;
    if (((M<UInt32>(self + panel * 0x78 + 0x168) & 0xf00000) == 0) ||
       (uVar10 = (UInt32)M<UInt16>(self + panel * 0x78 + 0x148) /
                 (M<UInt32>(self + panel * 0x78 + 0x168) >> 0x14 & 0xf), lastColumn = uVar10 - 1,
       uVar10 == 0)) {
      lastColumn = 0;
    }
    lastRow = 0;
    if (M<UInt16>(self + panel * 0x78 + 0x14a) != 0) {
      lastRow = M<UInt16>(self + panel * 0x78 + 0x14a) - 1;
    }
    blkFormatFieldE4 = FormatTableLookup_0x0004d2e4((UInt32)(UInt8)self[panel * 0x78 + 0x166] * 0x1c);
    blk[1] = lastColumn & 0x7ff | (lastRow & 0x7ff) << 0xb | 0x80000000;
    blk[2] = blkFormatFieldE4 >> 0x13 & 0x1f | (blkFormatFieldE4 & 0x40) << 0x10 | blkFormatFieldE4 >> 7 & 0xe00 |
                blkFormatFieldE4 >> 1 & 0x7000 | (blkFormatFieldE4 & 0x1c00) << 5 | (blkFormatFieldE4 & 0x380) << 0xb;
    bufferFormatWord = M<UInt32>(self + panel * 0x78 + 0x168);
    bVar1 = (bufferFormatWord & 0xf00000) == 0;
    if (bVar1) {
      widthUnits = 0;
    }
    else {
      widthUnits = (UInt32)M<UInt16>(self + panel * 0x78 + 0x140) / (bufferFormatWord >> 0x14 & 0xf);
    }
    pitchUnits = 0x20 / M<UInt16>(self + panel * 0x78 + 0x142);
    if (0x20 / M<UInt16>(self + panel * 0x78 + 0x142) <= widthUnits) {
      pitchUnits = widthUnits;
    }
    if ((bVar1) ||
       (uVar10 = (UInt32)M<UInt16>(self + panel * 0x78 + 0x148) / (bufferFormatWord >> 0x14 & 0xf),
       lastColumn = uVar10 - 1, uVar10 == 0)) {
      lastColumn = 0;
    }
    lastRow = 0;
    if (M<UInt16>(self + panel * 0x78 + 0x14a) != 0) {
      lastRow = M<UInt16>(self + panel * 0x78 + 0x14a) - 1;
    }
    blk[3] = pitchUnits - 1 & 0x3fff | (lastColumn & 0x800) << 4 | (lastRow & 0x800) << 5;
    if (((M<UInt32>(self + panel * 0x78 + 0x168) & 0xf00000) == 0) ||
       (blk[13] = (UInt32)M<UInt16>(self + panel * 0x78 + 0x148) /
                    (M<UInt32>(self + panel * 0x78 + 0x168) >> 0x14 & 0xf), blk[13] == 0)) {
      blk[13] = 1;
    }
    blk[14] = (UInt32)M<UInt16>(self + panel * 0x78 + 0x14a);
    if (blk[14] == 0) {
      blk[14] = 1;
    }
    blk[15] = (UInt32)M<UInt16>(self + panel * 0x78 + 0x140) *
                (UInt32)M<UInt16>(self + panel * 0x78 + 0x142);
    if (blk[15] < 0x20) {
      blk[15] = 0x20;
    }
    blk[33] = M<UInt32>(self + kIOATIR500Accelerator_tearingWideBlit);
    blk[16] = (UInt32)M<UInt16>(self + panel * 0x78 + 0x14c) *
                M<SInt32>(self + panel * 0x78 + 0x16c) + M<SInt32>(self + panel * 0x78 + 0x134);
    if (rotation == 0xb4) {
      endAddress = (SInt32)pcl_CopyPix(buffer + wordCount,(pcl_ParamsR500_t *)&blk[0],true,true);
      return endAddress - (SInt32)buffer >> 2;
    }
    endAddress = (SInt32)pcl_CopyPix(buffer + wordCount,(pcl_ParamsR500_t *)&blk[0],false,false);
    return endAddress - (SInt32)buffer >> 2;
  }
  blitPacket = buffer + wordCount;
  GH_memcpy(blitPacket,&g_r500_3d_blit_state_packet,0x2f4);
  iVar14 = (UInt32)(UInt8)self[panel * 0x78 + 0x9f6] * 0x1c;
  packetEnd = (SInt32)blitPacket + (0x2f4 - (SInt32)buffer) >> 2;
  widthUnits = 0;
  blitPacket[0x9a] =
       (UInt32)M<UInt16>(self + panel * 0x78 + 0x9dc) * M<SInt32>(self + panel * 0x78 + 0x9fc) +
       M<SInt32>(self + panel * 0x78 + 0x9c4) & 0xffffffe0;
  if ((M<UInt32>(self + panel * 0x78 + 0x9f8) & 0xf00000) != 0) {
    widthUnits = (UInt32)M<UInt16>(self + panel * 0x78 + 0x9d0) /
             (M<UInt32>(self + panel * 0x78 + 0x9f8) >> 0x14 & 0xf);
  }
  pitchUnits = 0x20 / M<UInt16>(self + panel * 0x78 + 0x9d2);
  if (0x20 / M<UInt16>(self + panel * 0x78 + 0x9d2) <= widthUnits) {
    pitchUnits = widthUnits;
  }
  uVar7 = blitPacket[0x8a];
  blitPacket[0x9c] =
       pitchUnits & 0x3ffe | ((UInt8)self[panel * 0x78 + 0x9f4] & 1) << 0x10 |
       ((UInt8)self[panel * 0x78 + 0x9f4] & 6) << 0x10 |
       ((UInt8)self[panel * 0x78 + 0x9f5] & 3) << 0x13 |
       FormatTableLookup_0x0004d2e0((UInt32)(UInt8)self[panel * 0x78 + 0x9f6] * 0x1c) >> 1 & 0x1e00000;
  uVar17 = FormatTableLookup_0x0004d2e0(iVar14) >> 0x11 & 0x1f;
  blitPacket[0x8a] = uVar17 | uVar7 & 0xffffffe0;
  uVar10 = FormatTableLookup_0x0004d2e0(iVar14) >> 7 & 0x300;
  blitPacket[0x8a] = uVar10 | uVar17 | uVar7 & 0xfffffce0;
  uVar11 = FormatTableLookup_0x0004d2e0(iVar14) >> 3 & 0xc00;
  blitPacket[0x8a] = uVar11 | uVar10 | uVar17 | uVar7 & 0xfffff0e0;
  uVar13 = (FormatTableLookup_0x0004d2e0(iVar14) & 0x1800) << 1;
  blitPacket[0x8a] = uVar13 | uVar11 | uVar10 | uVar17 | uVar7 & 0xffffc0e0;
  blitPacket[0x8a] =
       (FormatTableLookup_0x0004d2e0(iVar14) & 0x600) << 5 |
       uVar13 | uVar11 | uVar10 | uVar17 | uVar7 & 0xffff00e0;
  if (((M<UInt32>(self + panel * 0x78 + 0x9f8) & 0xf00000) == 0) ||
     (uVar10 = (UInt32)M<UInt16>(self + panel * 0x78 + 0x9d8) /
               (M<UInt32>(self + panel * 0x78 + 0x9f8) >> 0x14 & 0xf), lastColumn = uVar10 - 1,
     uVar10 == 0)) {
    lastColumn = 0;
  }
  lastRow = 0;
  if (M<UInt16>(self + panel * 0x78 + 0x9da) != 0) {
    lastRow = M<UInt16>(self + panel * 0x78 + 0x9da) - 1;
  }
  blitPacket[0xb3] = lastColumn & 0x1fff | (lastRow & 0x1fff) << 0xd;
  AVar2 = self[panel * 0x78 + 0x166];
  blitPacket[0xa0] =
       ((UInt8)self[panel * 0x78 + 0x164] & 7) << 2 |
       (UInt32)M<UInt16>(self + panel * 0x78 + 0x14c) * M<SInt32>(self + panel * 0x78 + 0x16c) +
       M<SInt32>(self + panel * 0x78 + 0x134) & 0xffffffe0;
  if (((M<UInt32>(self + panel * 0x78 + 0x168) & 0xf00000) == 0) ||
     (uVar10 = (UInt32)M<UInt16>(self + panel * 0x78 + 0x148) /
               (M<UInt32>(self + panel * 0x78 + 0x168) >> 0x14 & 0xf), lastColumn = uVar10 - 1,
     uVar10 == 0)) {
    lastColumn = 0;
  }
  lastRow = 0;
  if (M<UInt16>(self + panel * 0x78 + 0x14a) != 0) {
    lastRow = M<UInt16>(self + panel * 0x78 + 0x14a) - 1;
  }
  blitPacket[0xa6] = lastColumn & 0x7ff | (lastRow & 0x7ff) << 0xb | 0x80000000;
  packetFormatFieldE4 = FormatTableLookup_0x0004d2e4((UInt32)(UInt8)AVar2 * 0x1c);
  blitPacket[0xa8] =
       packetFormatFieldE4 >> 0x13 & 0x1f | (packetFormatFieldE4 & 0x40) << 0x10 | packetFormatFieldE4 >> 7 & 0xe00 | packetFormatFieldE4 >> 1 & 0x7000
       | (packetFormatFieldE4 & 0x1c00) << 5 | (packetFormatFieldE4 & 0x380) << 0xb;
  bufferFormatWord = M<UInt32>(self + panel * 0x78 + 0x168);
  bVar1 = (bufferFormatWord & 0xf00000) == 0;
  if (bVar1) {
    widthUnits = 0;
  }
  else {
    widthUnits = (UInt32)M<UInt16>(self + panel * 0x78 + 0x140) / (bufferFormatWord >> 0x14 & 0xf);
  }
  pitchUnits = 0x20 / M<UInt16>(self + panel * 0x78 + 0x142);
  if (0x20 / M<UInt16>(self + panel * 0x78 + 0x142) <= widthUnits) {
    pitchUnits = widthUnits;
  }
  if ((bVar1) ||
     (uVar10 = (UInt32)M<UInt16>(self + panel * 0x78 + 0x148) / (bufferFormatWord >> 0x14 & 0xf),
     lastColumn = uVar10 - 1, uVar10 == 0)) {
    lastColumn = 0;
  }
  lastRow = 0;
  if (M<UInt16>(self + panel * 0x78 + 0x14a) != 0) {
    lastRow = M<UInt16>(self + panel * 0x78 + 0x14a) - 1;
  }
  blitPacket[0xaa] = pitchUnits - 1 & 0x3fff | (lastColumn & 0x800) << 4 | (lastRow & 0x800) << 5;
  uVar15 = M<UInt32>(self + kIOATIR500Accelerator_gbTileConfig);
  blitPacket[0xa2] = blitPacket[0xa2] & 0xffffe1ff | 0x1400;
  blitPacket[5] = 0x30000;
  blitPacket[0xb] = uVar15;
  if (M<UInt16>(self + panel * 0x78 + 0x14a) < 0x1001) {
LAB_00023ca0:
    if (rotation == 0xb4) {
      uVar20 = 0x3f800000;
      uVar18 = 0;
      uVar15 = 0x3f800000;
      uVar19 = 0;
    }
    else {
      if (rotation == 0x10e) goto LAB_00023c68;
      if (rotation == 0x5a) goto LAB_00023c18;
      uVar20 = 0;
      uVar18 = 0x3f800000;
      uVar15 = 0;
      uVar19 = 0x3f800000;
    }
  }
  else {
    if (((M<UInt32>(self + panel * 0x78 + 0x168) & 0xf00000) == 0) ||
       (uVar17 = (UInt32)M<UInt16>(self + panel * 0x78 + 0x148) /
                 (M<UInt32>(self + panel * 0x78 + 0x168) >> 0x14 & 0xf), uVar10 = uVar17 - 1,
       uVar17 == 0)) {
      uVar10 = 0;
    }
    blitPacket[0xa6] = uVar10 & 0x7ff | 0x803ff800;
    if (rotation == 0x5a) {
      uVar17 = 0;
      if (M<UInt16>(self + panel * 0x78 + 0x9da) != 0) {
        uVar17 = M<UInt16>(self + panel * 0x78 + 0x9da) - 1;
      }
      blitPacket[0xb3] = (uVar17 & 0x1fff) << 0xd | 0xfff;
LAB_00023c18:
      uVar17 = blitPacket[0x98];
      uVar19 = 0;
      uVar18 = 0x3f800000;
    }
    else {
      if (rotation != 0x10e) goto LAB_00023ca0;
      if (((M<UInt32>(self + panel * 0x78 + 0x9f8) & 0xf00000) == 0) ||
         (uVar10 = (UInt32)M<UInt16>(self + panel * 0x78 + 0x9d8) /
                   (M<UInt32>(self + panel * 0x78 + 0x9f8) >> 0x14 & 0xf),
         uVar17 = uVar10 - 0x1001, uVar10 == 0)) {
        uVar17 = 0xfffff000;
      }
      blitPacket[0xb2] = uVar17 & 0x1fff;
LAB_00023c68:
      uVar17 = blitPacket[0x98];
      uVar19 = 0x3f800000;
      uVar18 = 0;
    }
    blitPacket[0x98] = uVar17 & 0xfffff000 | 1;
    uVar15 = uVar18;
    uVar20 = uVar19;
  }
  if (0x1000 < M<UInt16>(self + panel * 0x78 + 0x14a)) {
    if (rotation == 0x5a) {
      dVar23 = (double)FLOAT_0004c37c;
      iVar14 = packetEnd * 4 + 0x30 >> 2;
      fVar5 = (float)(dVar25 + (double)FLOAT_0004c370) * FLOAT_0004c380;
      buffer[packetEnd] = 0x31080;
      buffer[packetEnd + 5] = 0x1087;
      buffer[packetEnd + 7] = 0xc0033500;
      buffer[packetEnd + 8] = 0x10031;
      buffer[packetEnd + 9] = 0x45000000;
      buffer[packetEnd + 10] = FBITS(fVar5);
      buffer[packetEnd + 1] = uVar20;
      buffer[packetEnd + 2] = uVar19;
      buffer[packetEnd + 3] = uVar18;
      buffer[packetEnd + 4] = uVar15;
      buffer[packetEnd + 0xb] = 0;
      buffer[packetEnd + 6] = (SInt32)(dVar25 * dVar23) | 0x60000000;
      goto LAB_00023f44;
    }
    if (rotation == 0x10e) {
      dVar23 = (double)FLOAT_0004c37c;
      dVar22 = (double)FLOAT_0004c378;
      iVar14 = packetEnd * 4 + 0x30 >> 2;
      fVar5 = (float)(dVar25 + (double)FLOAT_0004c370) * FLOAT_0004c380;
      fVar6 = (float)(dVar24 + (double)(float)(dVar24 - dVar22)) * FLOAT_0004c380;
      buffer[packetEnd] = 0x31080;
      buffer[packetEnd + 7] = 0xc0033500;
      buffer[packetEnd + 5] = 0x1087;
      buffer[packetEnd + 8] = 0x10031;
      buffer[packetEnd + 9] = FBITS(fVar6);
      buffer[packetEnd + 10] = FBITS(fVar5);
      buffer[packetEnd + 0xb] = 0;
      buffer[packetEnd + 1] = uVar20;
      buffer[packetEnd + 2] = uVar19;
      buffer[packetEnd + 3] = uVar18;
      buffer[packetEnd + 4] = uVar15;
      buffer[packetEnd + 6] =
           (SInt32)((double)(float)(dVar24 - (double)(float)(dVar24 - dVar22)) * dVar23) << 0x10 |
           (SInt32)(dVar25 * dVar23);
      goto LAB_00023f44;
    }
  }
  dVar23 = (double)FLOAT_0004c37c;
  fVar5 = (float)(dVar25 + (double)FLOAT_0004c370) * FLOAT_0004c380;
  fVar6 = (float)(dVar24 + (double)FLOAT_0004c370) * FLOAT_0004c380;
  buffer[packetEnd] = 0x31080;
  buffer[packetEnd + 7] = 0xc0033500;
  buffer[packetEnd + 8] = 0x10031;
  buffer[packetEnd + 5] = 0x1087;
  buffer[packetEnd + 9] = FBITS(fVar6);
  buffer[packetEnd + 10] = FBITS(fVar5);
  buffer[packetEnd + 1] = uVar20;
  buffer[packetEnd + 2] = uVar19;
  buffer[packetEnd + 3] = uVar18;
  buffer[packetEnd + 4] = uVar15;
  buffer[packetEnd + 0xb] = 0;
  buffer[packetEnd + 6] = (SInt32)(dVar24 * dVar23) << 0x10 | (SInt32)(dVar25 * dVar23);
  iVar14 = packetEnd * 4 + 0x30 >> 2;
LAB_00023f44:
  uVar17 = (UInt32)M<UInt16>(self + panel * 0x78 + 0x14a);
  if (0x1000 < uVar17) {
    if (rotation == 0x5a) {
      pitch = M<SInt32>(self + panel * 0x78 + 0x16c);
      uVar3 = M<UInt16>(self + panel * 0x78 + 0x14c);
      uVar4 = M<UInt16>(self + panel * 0x78 + 0x144);
      baseOffset = M<SInt32>(self + panel * 0x78 + 0x134);
      uVar7 = blitPacket[0xa0];
      uVar13 = blitPacket[0xa6];
      uVar11 = blitPacket[0xb2];
      uVar10 = blitPacket[0xb3];
      if (((M<UInt32>(self + panel * 0x78 + 0x9f8) & 0xf00000) == 0) ||
         (uVar12 = (UInt32)M<UInt16>(self + panel * 0x78 + 0x9d8) /
                   (M<UInt32>(self + panel * 0x78 + 0x9f8) >> 0x14 & 0xf), uVar8 = uVar12 - 1,
         uVar12 == 0)) {
        uVar8 = 0;
      }
      buffer[iVar14] = 0x1150;
      buffer[iVar14 + 1] =
           (UInt32)uVar3 * pitch + baseOffset + (UInt32)uVar4 * 0x1000 & 0xffffffe0 | uVar7 & 0x1f;
      buffer[iVar14 + 2] = 0x1120;
      buffer[iVar14 + 3] = (uVar17 - 0x1001) * 0x800 & 0x3ff800 | uVar13 & 0xffc007ff;
      buffer[iVar14 + 4] = 0x10f8;
      buffer[iVar14 + 5] = uVar11 & 0xffffe000 | 0xfff;
      buffer[iVar14 + 6] = 0x10f9;
      buffer[iVar14 + 7] = uVar8 & 0x1fff | uVar10 & 0xffffe000;
      dVar23 = (double)FLOAT_0004c378;
      dVar22 = (double)FLOAT_0004c37c;
      fVar5 = (float)(dVar24 + dVar23) * FLOAT_0004c380;
      fVar6 = (float)(dVar25 + (double)FLOAT_0004c370) * FLOAT_0004c380;
      buffer[iVar14 + 8] = 0x31080;
      buffer[iVar14 + 0xd] = 0x1087;
      buffer[iVar14 + 9] = uVar20;
      buffer[iVar14 + 10] = uVar19;
      buffer[iVar14 + 0xb] = uVar18;
      buffer[iVar14 + 0xc] = uVar15;
      buffer[iVar14 + 0xf] = 0xc0033500;
      buffer[iVar14 + 0x10] = 0x10031;
      buffer[iVar14 + 0x11] = FBITS(fVar5);
      buffer[iVar14 + 0x12] = FBITS(fVar6);
      buffer[iVar14 + 0x13] = 0;
      buffer[iVar14 + 0xe] =
           (SInt32)((double)(float)(dVar24 - dVar23) * dVar22) << 0x10 | (SInt32)(dVar25 * dVar22);
      iVar14 = (iVar14 + 8) * 4 + 0x30 >> 2;
    }
    else if (rotation == 0x10e) {
      pitch = M<SInt32>(self + panel * 0x78 + 0x16c);
      uVar3 = M<UInt16>(self + panel * 0x78 + 0x14c);
      uVar4 = M<UInt16>(self + panel * 0x78 + 0x144);
      baseOffset = M<SInt32>(self + panel * 0x78 + 0x134);
      uVar7 = blitPacket[0xa0];
      uVar13 = blitPacket[0xa6];
      uVar11 = blitPacket[0xb2];
      uVar10 = blitPacket[0xb3];
      if (((M<UInt32>(self + panel * 0x78 + 0x9f8) & 0xf00000) == 0) ||
         (uVar12 = (UInt32)M<UInt16>(self + panel * 0x78 + 0x9d8) /
                   (M<UInt32>(self + panel * 0x78 + 0x9f8) >> 0x14 & 0xf), uVar8 = uVar12 - 0x1001
         , uVar12 == 0)) {
        uVar8 = 0xfffff000;
      }
      buffer[iVar14] = 0x1150;
      buffer[iVar14 + 1] =
           (UInt32)uVar3 * pitch + baseOffset + (UInt32)uVar4 * 0x1000 & 0xffffffe0 | uVar7 & 0x1f;
      buffer[iVar14 + 2] = 0x1120;
      buffer[iVar14 + 3] = (uVar17 - 0x1001) * 0x800 & 0x3ff800 | uVar13 & 0xffc007ff;
      buffer[iVar14 + 4] = 0x10f8;
      buffer[iVar14 + 5] = uVar11 & 0xffffe000;
      buffer[iVar14 + 6] = 0x10f9;
      buffer[iVar14 + 7] = uVar8 & 0x1fff | uVar10 & 0xffffe000;
      dVar23 = (double)FLOAT_0004c37c;
      dVar22 = (double)FLOAT_0004c378;
      fVar5 = (float)(dVar25 + (double)FLOAT_0004c370) * FLOAT_0004c380;
      fVar6 = (float)((double)(float)(dVar24 - dVar22) + (double)FLOAT_0004c370) * FLOAT_0004c380;
      buffer[iVar14 + 8] = 0x31080;
      buffer[iVar14 + 0xd] = 0x1087;
      buffer[iVar14 + 9] = uVar20;
      buffer[iVar14 + 10] = uVar19;
      buffer[iVar14 + 0xb] = uVar18;
      buffer[iVar14 + 0xc] = uVar15;
      buffer[iVar14 + 0xf] = 0xc0033500;
      buffer[iVar14 + 0x10] = 0x10031;
      buffer[iVar14 + 0x11] = FBITS(fVar6);
      buffer[iVar14 + 0x12] = FBITS(fVar5);
      buffer[iVar14 + 0x13] = 0;
      buffer[iVar14 + 0xe] =
           (SInt32)((double)(float)(dVar24 - dVar22) * dVar23) << 0x10 | (SInt32)(dVar25 * dVar23);
      iVar14 = (iVar14 + 8) * 4 + 0x30 >> 2;
    }
  }
  buffer[iVar14] = 0x1393;
  buffer[iVar14 + 1] = 10;
  return iVar14 + 2;
}

