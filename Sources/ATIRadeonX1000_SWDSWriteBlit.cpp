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

  bool noFormatBits;
  UInt8 dstFormat;
  UInt16 dstRow;
  UInt16 dstColumnUnits;
  UInt32 lastColumnRot;
  SInt32 packetEnd;
  SInt32 baseOffset;
  SInt32 regValueIndex;
  UInt32 blkFormatFieldE4;
  UInt32 columnCountRot;
  SInt32 packetWordIndex;
  UInt32 texCoordWord4;
  SInt32 rotation;
  SInt32 pitch;
  SInt32 endAddress;
  UInt32 dstHeight;
  UInt32 packetFormatFieldE4;
  UInt32 blkFormatFieldE0;
  UInt32 texCoordWord3;
  UInt32 texCoordWord2;
  UInt32 texCoordWord1;
  UInt32 *blitPacket;
  UInt32 widthUnits;
  UInt32 pitchUnits;
  UInt32 lastColumn;
  UInt32 lastRow;
  UInt32 bufferFormatWord;
  SInt32 formatTableOffset;
  UInt16 panelHeight16;
  float vertexY1;
  float vertexX1;
  float vertexX2;
  float vertexY2;
  UInt32 tileConfig;
  UInt32 packetWord8a;
  UInt32 packetWordA0;
  UInt32 formatField0;
  UInt32 dstColumnCount;
  UInt32 lastRowRot;
  UInt32 packetWord98;
  UInt32 columnOffsetRot;
  UInt32 columnCount;
  UInt32 formatField1;
  UInt32 lastColumnLarge;
  UInt32 columnCountWrap;
  UInt32 packetWordB3;
  UInt32 formatField2;
  UInt32 packetWordB2;
  UInt32 formatField3;
  UInt32 packetWordA6;
  UInt32 blk[35];   /* the pcl_ParamsR500_t block on the shipped stack: 0x8c bytes at sp+0x40 (Ghidra blk[0] .. blk[34]) */
  UInt16 rect[4];   /* the 8-byte rectangle at sp+0x38 (Ghidra rect[0] .. rect[3]) */
  double widthD;
  double heightD;
  UInt32 magicHi0;
  UInt32 widthLo;
  UInt32 magicHi1;
  UInt32 heightLo;
  UInt32 magicHi2;
  UInt32 dstWidthLo;
  UInt32 magicHi3;
  UInt32 dstHeightLo;
  double magicBias;
  double vertexScaleA;
  double vertexBiasA;
  double vertexScaleB;
  double vertexBiasB;
  
  magicBias = DOUBLE_0004c3b0;
  widthLo = (UInt32)M<UInt16>(self + panel * 0x78 + 0x9d8);
  rotation = M<SInt32>(self + panel * 4 + 0xb5c);
  magicHi0 = 0x43300000;
  heightLo = (UInt32)M<UInt16>(self + panel * 0x78 + 0x9da);
  magicHi1 = 0x43300000;
  M<UInt32>(self + kIOATIR500Accelerator_unknown_0x78) = 0;
  BF(blk[23]) = (float)((double)CONCAT44d(0x43300000,widthLo) - magicBias);
  widthD = (double)BF(blk[23]);
  BF(blk[24]) = (float)((double)CONCAT44d(0x43300000,heightLo) - magicBias);
  heightD = (double)BF(blk[24]);
  if (((UInt32)flag) != 0) {
    panelHeight16 = M<UInt16>(self + panel * 0x78 + 0x9da);
    buffer[wordCount] = 0x5c8;
    buffer[wordCount + 1] = 0x70000;
    if (panel == 0) {
      buffer[wordCount + 2] = 0x194e;
      buffer[wordCount + 3] = ((UInt32)panelHeight16 & ~M<UInt32>(self + kIOATIR500Accelerator_display1Enabled)) << 0x10 | 0x80000000;
      buffer[wordCount + 4] = 0x5c8;
      regValueIndex = wordCount + 5;
      wordCount = wordCount + 6;
      buffer[regValueIndex] = 8;
    }
    else {
      buffer[wordCount + 2] = 0x1b4e;
      buffer[wordCount + 3] = ((UInt32)panelHeight16 & ~M<UInt32>(self + kIOATIR500Accelerator_display2Enabled)) << 0x10 | 0x80000000;
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
    dstWidthLo = (UInt32)M<UInt16>(self + panel * 0x78 + 0x148);
    blk[11] = (UInt32)(UInt8)self[panel * 0x78 + 0x166];
    blk[12] = (UInt32)(UInt8)self[panel * 0x78 + 0x9f6];
    magicHi2 = 0x43300000;
    dstHeightLo = (UInt32)M<UInt16>(self + panel * 0x78 + 0x14a);
    blk[4] = 0x1492;
    blk[8] = 0;
    magicHi3 = 0x43300000;
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
    BF(blk[27]) = (float)((double)CONCAT44d(0x43300000,dstWidthLo) - DOUBLE_0004c3b0);
    BF(blk[28]) = (float)((double)CONCAT44d(0x43300000,dstHeightLo) - DOUBLE_0004c3b0);
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
       (columnCount = (UInt32)M<UInt16>(self + panel * 0x78 + 0x9d8) /
                 (M<UInt32>(self + panel * 0x78 + 0x9f8) >> 0x14 & 0xf), lastColumn = columnCount - 1,
       columnCount == 0)) {
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
       (columnCount = (UInt32)M<UInt16>(self + panel * 0x78 + 0x148) /
                 (M<UInt32>(self + panel * 0x78 + 0x168) >> 0x14 & 0xf), lastColumn = columnCount - 1,
       columnCount == 0)) {
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
    noFormatBits = (bufferFormatWord & 0xf00000) == 0;
    if (noFormatBits) {
      widthUnits = 0;
    }
    else {
      widthUnits = (UInt32)M<UInt16>(self + panel * 0x78 + 0x140) / (bufferFormatWord >> 0x14 & 0xf);
    }
    pitchUnits = 0x20 / M<UInt16>(self + panel * 0x78 + 0x142);
    if (0x20 / M<UInt16>(self + panel * 0x78 + 0x142) <= widthUnits) {
      pitchUnits = widthUnits;
    }
    if ((noFormatBits) ||
       (columnCount = (UInt32)M<UInt16>(self + panel * 0x78 + 0x148) / (bufferFormatWord >> 0x14 & 0xf),
       lastColumn = columnCount - 1, columnCount == 0)) {
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
  formatTableOffset = (UInt32)(UInt8)self[panel * 0x78 + 0x9f6] * 0x1c;
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
  packetWord8a = blitPacket[0x8a];
  blitPacket[0x9c] =
       pitchUnits & 0x3ffe | ((UInt8)self[panel * 0x78 + 0x9f4] & 1) << 0x10 |
       ((UInt8)self[panel * 0x78 + 0x9f4] & 6) << 0x10 |
       ((UInt8)self[panel * 0x78 + 0x9f5] & 3) << 0x13 |
       FormatTableLookup_0x0004d2e0((UInt32)(UInt8)self[panel * 0x78 + 0x9f6] * 0x1c) >> 1 & 0x1e00000;
  formatField0 = FormatTableLookup_0x0004d2e0(formatTableOffset) >> 0x11 & 0x1f;
  blitPacket[0x8a] = formatField0 | packetWord8a & 0xffffffe0;
  formatField1 = FormatTableLookup_0x0004d2e0(formatTableOffset) >> 7 & 0x300;
  blitPacket[0x8a] = formatField1 | formatField0 | packetWord8a & 0xfffffce0;
  formatField2 = FormatTableLookup_0x0004d2e0(formatTableOffset) >> 3 & 0xc00;
  blitPacket[0x8a] = formatField2 | formatField1 | formatField0 | packetWord8a & 0xfffff0e0;
  formatField3 = (FormatTableLookup_0x0004d2e0(formatTableOffset) & 0x1800) << 1;
  blitPacket[0x8a] = formatField3 | formatField2 | formatField1 | formatField0 | packetWord8a & 0xffffc0e0;
  blitPacket[0x8a] =
       (FormatTableLookup_0x0004d2e0(formatTableOffset) & 0x600) << 5 |
       formatField3 | formatField2 | formatField1 | formatField0 | packetWord8a & 0xffff00e0;
  if (((M<UInt32>(self + panel * 0x78 + 0x9f8) & 0xf00000) == 0) ||
     (columnCount = (UInt32)M<UInt16>(self + panel * 0x78 + 0x9d8) /
               (M<UInt32>(self + panel * 0x78 + 0x9f8) >> 0x14 & 0xf), lastColumn = columnCount - 1,
     columnCount == 0)) {
    lastColumn = 0;
  }
  lastRow = 0;
  if (M<UInt16>(self + panel * 0x78 + 0x9da) != 0) {
    lastRow = M<UInt16>(self + panel * 0x78 + 0x9da) - 1;
  }
  blitPacket[0xb3] = lastColumn & 0x1fff | (lastRow & 0x1fff) << 0xd;
  dstFormat = self[panel * 0x78 + 0x166];
  blitPacket[0xa0] =
       ((UInt8)self[panel * 0x78 + 0x164] & 7) << 2 |
       (UInt32)M<UInt16>(self + panel * 0x78 + 0x14c) * M<SInt32>(self + panel * 0x78 + 0x16c) +
       M<SInt32>(self + panel * 0x78 + 0x134) & 0xffffffe0;
  if (((M<UInt32>(self + panel * 0x78 + 0x168) & 0xf00000) == 0) ||
     (columnCount = (UInt32)M<UInt16>(self + panel * 0x78 + 0x148) /
               (M<UInt32>(self + panel * 0x78 + 0x168) >> 0x14 & 0xf), lastColumn = columnCount - 1,
     columnCount == 0)) {
    lastColumn = 0;
  }
  lastRow = 0;
  if (M<UInt16>(self + panel * 0x78 + 0x14a) != 0) {
    lastRow = M<UInt16>(self + panel * 0x78 + 0x14a) - 1;
  }
  blitPacket[0xa6] = lastColumn & 0x7ff | (lastRow & 0x7ff) << 0xb | 0x80000000;
  packetFormatFieldE4 = FormatTableLookup_0x0004d2e4((UInt32)(UInt8)dstFormat * 0x1c);
  blitPacket[0xa8] =
       packetFormatFieldE4 >> 0x13 & 0x1f | (packetFormatFieldE4 & 0x40) << 0x10 | packetFormatFieldE4 >> 7 & 0xe00 | packetFormatFieldE4 >> 1 & 0x7000
       | (packetFormatFieldE4 & 0x1c00) << 5 | (packetFormatFieldE4 & 0x380) << 0xb;
  bufferFormatWord = M<UInt32>(self + panel * 0x78 + 0x168);
  noFormatBits = (bufferFormatWord & 0xf00000) == 0;
  if (noFormatBits) {
    widthUnits = 0;
  }
  else {
    widthUnits = (UInt32)M<UInt16>(self + panel * 0x78 + 0x140) / (bufferFormatWord >> 0x14 & 0xf);
  }
  pitchUnits = 0x20 / M<UInt16>(self + panel * 0x78 + 0x142);
  if (0x20 / M<UInt16>(self + panel * 0x78 + 0x142) <= widthUnits) {
    pitchUnits = widthUnits;
  }
  if ((noFormatBits) ||
     (columnCount = (UInt32)M<UInt16>(self + panel * 0x78 + 0x148) / (bufferFormatWord >> 0x14 & 0xf),
     lastColumn = columnCount - 1, columnCount == 0)) {
    lastColumn = 0;
  }
  lastRow = 0;
  if (M<UInt16>(self + panel * 0x78 + 0x14a) != 0) {
    lastRow = M<UInt16>(self + panel * 0x78 + 0x14a) - 1;
  }
  blitPacket[0xaa] = pitchUnits - 1 & 0x3fff | (lastColumn & 0x800) << 4 | (lastRow & 0x800) << 5;
  tileConfig = M<UInt32>(self + kIOATIR500Accelerator_gbTileConfig);
  blitPacket[0xa2] = blitPacket[0xa2] & 0xffffe1ff | 0x1400;
  blitPacket[5] = 0x30000;
  blitPacket[0xb] = tileConfig;
  if (M<UInt16>(self + panel * 0x78 + 0x14a) < 0x1001) {
LAB_00023ca0:
    if (rotation == 0xb4) {
      texCoordWord1 = 0x3f800000;
      texCoordWord3 = 0;
      texCoordWord4 = 0x3f800000;
      texCoordWord2 = 0;
    }
    else {
      if (rotation == 0x10e) goto LAB_00023c68;
      if (rotation == 0x5a) goto LAB_00023c18;
      texCoordWord1 = 0;
      texCoordWord3 = 0x3f800000;
      texCoordWord4 = 0;
      texCoordWord2 = 0x3f800000;
    }
  }
  else {
    if (((M<UInt32>(self + panel * 0x78 + 0x168) & 0xf00000) == 0) ||
       (dstColumnCount = (UInt32)M<UInt16>(self + panel * 0x78 + 0x148) /
                 (M<UInt32>(self + panel * 0x78 + 0x168) >> 0x14 & 0xf), lastColumnLarge = dstColumnCount - 1,
       dstColumnCount == 0)) {
      lastColumnLarge = 0;
    }
    blitPacket[0xa6] = lastColumnLarge & 0x7ff | 0x803ff800;
    if (rotation == 0x5a) {
      lastRowRot = 0;
      if (M<UInt16>(self + panel * 0x78 + 0x9da) != 0) {
        lastRowRot = M<UInt16>(self + panel * 0x78 + 0x9da) - 1;
      }
      blitPacket[0xb3] = (lastRowRot & 0x1fff) << 0xd | 0xfff;
LAB_00023c18:
      packetWord98 = blitPacket[0x98];
      texCoordWord2 = 0;
      texCoordWord3 = 0x3f800000;
    }
    else {
      if (rotation != 0x10e) goto LAB_00023ca0;
      if (((M<UInt32>(self + panel * 0x78 + 0x9f8) & 0xf00000) == 0) ||
         (columnCountWrap = (UInt32)M<UInt16>(self + panel * 0x78 + 0x9d8) /
                   (M<UInt32>(self + panel * 0x78 + 0x9f8) >> 0x14 & 0xf),
         columnOffsetRot = columnCountWrap - 0x1001, columnCountWrap == 0)) {
        columnOffsetRot = 0xfffff000;
      }
      blitPacket[0xb2] = columnOffsetRot & 0x1fff;
LAB_00023c68:
      packetWord98 = blitPacket[0x98];
      texCoordWord2 = 0x3f800000;
      texCoordWord3 = 0;
    }
    blitPacket[0x98] = packetWord98 & 0xfffff000 | 1;
    texCoordWord4 = texCoordWord3;
    texCoordWord1 = texCoordWord2;
  }
  if (0x1000 < M<UInt16>(self + panel * 0x78 + 0x14a)) {
    if (rotation == 0x5a) {
      vertexScaleA = (double)FLOAT_0004c37c;
      packetWordIndex = packetEnd * 4 + 0x30 >> 2;
      vertexY1 = (float)(heightD + (double)FLOAT_0004c370) * FLOAT_0004c380;
      buffer[packetEnd] = 0x31080;
      buffer[packetEnd + 5] = 0x1087;
      buffer[packetEnd + 7] = 0xc0033500;
      buffer[packetEnd + 8] = 0x10031;
      buffer[packetEnd + 9] = 0x45000000;
      buffer[packetEnd + 10] = FBITS(vertexY1);
      buffer[packetEnd + 1] = texCoordWord1;
      buffer[packetEnd + 2] = texCoordWord2;
      buffer[packetEnd + 3] = texCoordWord3;
      buffer[packetEnd + 4] = texCoordWord4;
      buffer[packetEnd + 0xb] = 0;
      buffer[packetEnd + 6] = (SInt32)(heightD * vertexScaleA) | 0x60000000;
      goto LAB_00023f44;
    }
    if (rotation == 0x10e) {
      vertexScaleA = (double)FLOAT_0004c37c;
      vertexBiasB = (double)FLOAT_0004c378;
      packetWordIndex = packetEnd * 4 + 0x30 >> 2;
      vertexY1 = (float)(heightD + (double)FLOAT_0004c370) * FLOAT_0004c380;
      vertexX2 = (float)(widthD + (double)(float)(widthD - vertexBiasB)) * FLOAT_0004c380;
      buffer[packetEnd] = 0x31080;
      buffer[packetEnd + 7] = 0xc0033500;
      buffer[packetEnd + 5] = 0x1087;
      buffer[packetEnd + 8] = 0x10031;
      buffer[packetEnd + 9] = FBITS(vertexX2);
      buffer[packetEnd + 10] = FBITS(vertexY1);
      buffer[packetEnd + 0xb] = 0;
      buffer[packetEnd + 1] = texCoordWord1;
      buffer[packetEnd + 2] = texCoordWord2;
      buffer[packetEnd + 3] = texCoordWord3;
      buffer[packetEnd + 4] = texCoordWord4;
      buffer[packetEnd + 6] =
           (SInt32)((double)(float)(widthD - (double)(float)(widthD - vertexBiasB)) * vertexScaleA) << 0x10 |
           (SInt32)(heightD * vertexScaleA);
      goto LAB_00023f44;
    }
  }
  vertexScaleA = (double)FLOAT_0004c37c;
  vertexY1 = (float)(heightD + (double)FLOAT_0004c370) * FLOAT_0004c380;
  vertexX2 = (float)(widthD + (double)FLOAT_0004c370) * FLOAT_0004c380;
  buffer[packetEnd] = 0x31080;
  buffer[packetEnd + 7] = 0xc0033500;
  buffer[packetEnd + 8] = 0x10031;
  buffer[packetEnd + 5] = 0x1087;
  buffer[packetEnd + 9] = FBITS(vertexX2);
  buffer[packetEnd + 10] = FBITS(vertexY1);
  buffer[packetEnd + 1] = texCoordWord1;
  buffer[packetEnd + 2] = texCoordWord2;
  buffer[packetEnd + 3] = texCoordWord3;
  buffer[packetEnd + 4] = texCoordWord4;
  buffer[packetEnd + 0xb] = 0;
  buffer[packetEnd + 6] = (SInt32)(widthD * vertexScaleA) << 0x10 | (SInt32)(heightD * vertexScaleA);
  packetWordIndex = packetEnd * 4 + 0x30 >> 2;
LAB_00023f44:
  dstHeight = (UInt32)M<UInt16>(self + panel * 0x78 + 0x14a);
  if (0x1000 < dstHeight) {
    if (rotation == 0x5a) {
      pitch = M<SInt32>(self + panel * 0x78 + 0x16c);
      dstRow = M<UInt16>(self + panel * 0x78 + 0x14c);
      dstColumnUnits = M<UInt16>(self + panel * 0x78 + 0x144);
      baseOffset = M<SInt32>(self + panel * 0x78 + 0x134);
      packetWordA0 = blitPacket[0xa0];
      packetWordA6 = blitPacket[0xa6];
      packetWordB2 = blitPacket[0xb2];
      packetWordB3 = blitPacket[0xb3];
      if (((M<UInt32>(self + panel * 0x78 + 0x9f8) & 0xf00000) == 0) ||
         (columnCountRot = (UInt32)M<UInt16>(self + panel * 0x78 + 0x9d8) /
                   (M<UInt32>(self + panel * 0x78 + 0x9f8) >> 0x14 & 0xf), lastColumnRot = columnCountRot - 1,
         columnCountRot == 0)) {
        lastColumnRot = 0;
      }
      buffer[packetWordIndex] = 0x1150;
      buffer[packetWordIndex + 1] =
           (UInt32)dstRow * pitch + baseOffset + (UInt32)dstColumnUnits * 0x1000 & 0xffffffe0 | packetWordA0 & 0x1f;
      buffer[packetWordIndex + 2] = 0x1120;
      buffer[packetWordIndex + 3] = (dstHeight - 0x1001) * 0x800 & 0x3ff800 | packetWordA6 & 0xffc007ff;
      buffer[packetWordIndex + 4] = 0x10f8;
      buffer[packetWordIndex + 5] = packetWordB2 & 0xffffe000 | 0xfff;
      buffer[packetWordIndex + 6] = 0x10f9;
      buffer[packetWordIndex + 7] = lastColumnRot & 0x1fff | packetWordB3 & 0xffffe000;
      vertexBiasA = (double)FLOAT_0004c378;
      vertexScaleB = (double)FLOAT_0004c37c;
      vertexX1 = (float)(widthD + vertexBiasA) * FLOAT_0004c380;
      vertexY2 = (float)(heightD + (double)FLOAT_0004c370) * FLOAT_0004c380;
      buffer[packetWordIndex + 8] = 0x31080;
      buffer[packetWordIndex + 0xd] = 0x1087;
      buffer[packetWordIndex + 9] = texCoordWord1;
      buffer[packetWordIndex + 10] = texCoordWord2;
      buffer[packetWordIndex + 0xb] = texCoordWord3;
      buffer[packetWordIndex + 0xc] = texCoordWord4;
      buffer[packetWordIndex + 0xf] = 0xc0033500;
      buffer[packetWordIndex + 0x10] = 0x10031;
      buffer[packetWordIndex + 0x11] = FBITS(vertexX1);
      buffer[packetWordIndex + 0x12] = FBITS(vertexY2);
      buffer[packetWordIndex + 0x13] = 0;
      buffer[packetWordIndex + 0xe] =
           (SInt32)((double)(float)(widthD - vertexBiasA) * vertexScaleB) << 0x10 | (SInt32)(heightD * vertexScaleB);
      packetWordIndex = (packetWordIndex + 8) * 4 + 0x30 >> 2;
    }
    else if (rotation == 0x10e) {
      pitch = M<SInt32>(self + panel * 0x78 + 0x16c);
      dstRow = M<UInt16>(self + panel * 0x78 + 0x14c);
      dstColumnUnits = M<UInt16>(self + panel * 0x78 + 0x144);
      baseOffset = M<SInt32>(self + panel * 0x78 + 0x134);
      packetWordA0 = blitPacket[0xa0];
      packetWordA6 = blitPacket[0xa6];
      packetWordB2 = blitPacket[0xb2];
      packetWordB3 = blitPacket[0xb3];
      if (((M<UInt32>(self + panel * 0x78 + 0x9f8) & 0xf00000) == 0) ||
         (columnCountRot = (UInt32)M<UInt16>(self + panel * 0x78 + 0x9d8) /
                   (M<UInt32>(self + panel * 0x78 + 0x9f8) >> 0x14 & 0xf), lastColumnRot = columnCountRot - 0x1001
         , columnCountRot == 0)) {
        lastColumnRot = 0xfffff000;
      }
      buffer[packetWordIndex] = 0x1150;
      buffer[packetWordIndex + 1] =
           (UInt32)dstRow * pitch + baseOffset + (UInt32)dstColumnUnits * 0x1000 & 0xffffffe0 | packetWordA0 & 0x1f;
      buffer[packetWordIndex + 2] = 0x1120;
      buffer[packetWordIndex + 3] = (dstHeight - 0x1001) * 0x800 & 0x3ff800 | packetWordA6 & 0xffc007ff;
      buffer[packetWordIndex + 4] = 0x10f8;
      buffer[packetWordIndex + 5] = packetWordB2 & 0xffffe000;
      buffer[packetWordIndex + 6] = 0x10f9;
      buffer[packetWordIndex + 7] = lastColumnRot & 0x1fff | packetWordB3 & 0xffffe000;
      vertexScaleA = (double)FLOAT_0004c37c;
      vertexBiasB = (double)FLOAT_0004c378;
      vertexY1 = (float)(heightD + (double)FLOAT_0004c370) * FLOAT_0004c380;
      vertexX2 = (float)((double)(float)(widthD - vertexBiasB) + (double)FLOAT_0004c370) * FLOAT_0004c380;
      buffer[packetWordIndex + 8] = 0x31080;
      buffer[packetWordIndex + 0xd] = 0x1087;
      buffer[packetWordIndex + 9] = texCoordWord1;
      buffer[packetWordIndex + 10] = texCoordWord2;
      buffer[packetWordIndex + 0xb] = texCoordWord3;
      buffer[packetWordIndex + 0xc] = texCoordWord4;
      buffer[packetWordIndex + 0xf] = 0xc0033500;
      buffer[packetWordIndex + 0x10] = 0x10031;
      buffer[packetWordIndex + 0x11] = FBITS(vertexX2);
      buffer[packetWordIndex + 0x12] = FBITS(vertexY1);
      buffer[packetWordIndex + 0x13] = 0;
      buffer[packetWordIndex + 0xe] =
           (SInt32)((double)(float)(widthD - vertexBiasB) * vertexScaleA) << 0x10 | (SInt32)(heightD * vertexScaleA);
      packetWordIndex = (packetWordIndex + 8) * 4 + 0x30 >> 2;
    }
  }
  buffer[packetWordIndex] = 0x1393;
  buffer[packetWordIndex + 1] = 10;
  return packetWordIndex + 2;
}

