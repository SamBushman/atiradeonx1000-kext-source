/*
 * ATIR500Surface_BuildSwap.cpp
 *
 * RESOLVED (ledger pass): ATIR500Surface::build_swap (real addr 0x3eec0, vtable +0x5c0, 8704 bytes) - the routine that
 * turns a surface's pending swap into the per-panel command stream: for each active display panel it builds (in the
 * panel's pending-write batch at this+0xc34+panel*0x94) the 3D-blit state packet copy, the source/destination surface
 * descriptors, the viewport/scissor floats and the textured-quad vertices for scaled swaps, and the 0x1393/0x194e/
 * 0x1b4e window-select preambles, choosing per-panel between a plain copy and the scaled-blit path.
 *
 * Transcribed mechanically from the shipped kext's decompile with Tools/ghidra2cpp.py (Headers/GhidraCompat.h): the
 * arithmetic, control flow and variable names of the decompile are kept as they are (the pseudo-C is the transcription),
 * with these conventions:
 *   M<T>(addr)          typed memory access (`*(T *)addr`);  self = this as a byte pointer (Ghidra models the class as
 *                       one byte, so `this + 0xd50` is byte arithmetic)
 *   FBITS(f)            a float written into a raw UInt32 slot (Ghidra prints it as `slot = (float)x`)
 *   CONCAT44d(a, b)     the int/uint -> double conversion idiom (0x43300000:x minus the 2^52 bias constant)
 *   FormatTableLookup_* words of the kext's ati_format_info_table (0x4d2d0, 0x1c-byte entries) at the given field
 * Object layout used: this+0xd50 accelerator, +0xd60 per-panel region records, +0xc34+panel*0x94 pending batch header,
 * +0xb70/+0xb74 current / previous buffer record, +0xbe8 mode bits, +0xa8.. buffer records (0x78 stride).
 */

#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

extern "C" UInt32 FormatTableLookup_0x0004d2d8(UInt32 byteOffset);
extern "C" UInt32 FormatTableLookup_0x0004d2dc(UInt32 byteOffset);
extern "C" UInt32 FormatTableLookup_0x0004d2e0(UInt32 byteOffset);
extern "C" UInt32 FormatTableLookup_0x0004d2e4(UInt32 byteOffset);
extern "C" const r500_3d_blit_state_packet_struct g_r500_3d_blit_state_packet;

void ATIR500Surface::build_swap() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool useBuffer1;
  bool buffer1Untiled;
  bool formatsDiffer;
  bool dstUntiled;
  bool srcUntiled;
  float edgeDelta;
  float columnOffsetB;
  float bufferWidthFloat;
  float halfF;
  float columnOffsetA;
  UInt8 buffer1FormatIndex;
  UInt8 dstTilingByte1;
  UInt8 srcTilingByte0;
  float widthRatio;
  SInt16 regionX;
  SInt16 regionWidth;
  SInt16 surfaceWidth;
  SInt16 surfaceHeight;
  UInt32 savedWord250;
  UInt32 hwWordB74;
  UInt32 gbTileConfig;
  UInt32 fieldC;
  UInt32 minPitch;
  UInt32 panelHeight;
  UInt32 formatIndexSrc;
  UInt32 fmtE4;
  UInt32 firstHeightPlus1;
  UInt32 halfWidthPlus2;
  SInt32 overlapFlag;
  SInt32 dstBaseAddr;
  UInt32 fieldB;
  UInt32 columnDivA;
  UInt32 pitchPerDegreeB;
  UInt32 columnDivB;
  UInt32 lastRowB;
  UInt32 scissorEnd;
  UInt32 dstFormatIndex;
  UInt32 fmtE0;
  UInt32 fmtDC;
  UInt32 secondWidth;
  UInt32 dstPitchUnits;
  UInt32 srcLastColumn;
  UInt32 srcLastColumnCopy;
  SInt32 packetCursor;
  SInt32 *regionArray;
  SInt32 *regionCursor;
  UInt32 fieldA;
  UInt32 fmtE4B;
  UInt32 tilingBitsB;
  UInt32 lastColumnB;
  UInt32 scissorStart;
  UInt32 savedWordAA;
  UInt32 srcFormatIndex;
  UInt32 srcPitchUnits;
  SInt32 accelBase;
  SInt32 panelAccel;
  SInt32 mip0Offset;
  SInt32 stripCursor;
  SInt32 tileShift;
  SInt32 texOffsetDelta;
  SInt32 lengthIndex;
  SInt32 columnCursor;
  SInt32 rectCursor;
  SInt32 srcGpuBase;
  SInt32 regionCount;
  SInt32 scalingMode;
  SInt32 stripsLeft;
  SInt32 columnsLeft;
  SInt32 formatOffset;
  SInt32 nextIndex;
  SInt32 accelerator;
  SInt32 rectPacketIndex;
  UInt16 bufferOriginY;
  UInt16 panelOriginY;
  UInt32 bufferHeight;
  UInt32 widthUnits;
  UInt32 pitchUnits;
  UInt32 lastColumn;
  UInt32 lastRow;
  UInt32 srcWidthUnits;
  UInt32 srcLastRow;
  UInt32 srcLastRowCopy;
  UInt32 dstWidthUnits;
  UInt32 scissorRight;
  UInt32 scissorWidthUnits;
  UInt32 scissorBottom;
  SwapBufferEntry *batchEntry;     /* entries[0] of the panel being built: its `header` is the pending swap-write batch */
  PanelRecord *panelRec;
  UInt32 regionY;
  UInt32 savedWordA2;
  UInt32 firstHeight;
  UInt32 halfWidth;
  UInt32 bufferWidthInt;
  UInt32 *batchWords;
  UInt32 regionHeight;
  UInt32 halfHeightRaw;
  UInt32 savedWordA6;
  UInt32 halfWidthRaw;
  float heightRatio;
  UInt32 fieldD;
  UInt32 secondHeight;
  SInt32 tearingWideBlit;
  SInt32 regionsLeft;
  SInt32 tileUnits;
  UInt32 *blitPacket;
  UInt8 isPanel0Bits;
  UInt8 dstTilingByte0;
  float surfaceWidthF;
  float splitThreshold;
  float lit37c;
  float surfaceHeightF;
  float columnCenterX;
  float half;
  float one;
  float zero;
  float secondColumnBiasX;
  float secondStripBiasY;
  float stripCenterY;
  UInt8 *panelSlotCursor;
  UInt32 panel;
  SInt32 *regionDataPtr;
  SInt32 surfaceBuffer;
  SInt32 packetIndex;
  SInt32 textureOffsetWord;
  SInt32 batchHeader;
  SInt32 batchIndex;
  SInt32 pitch;
  UInt32 bufferWidth;
  float regionXF;
  float regionYF;
  float sourceScaleX;
  float sourceScaleY;
  float bufferWidthF;
  float bufferHeightF;
  float regionWidthF;
  float regionHeightF;
  float invBufferWidthD;
  float invBufferHeightD;
  float scalingBufferXF;
  float scalingBufferYF;
  float firstStripRight;
  float firstStripBottom;
  float firstStripRectLeftF;
  float firstStripRectTopF;
  float firstStripRectRightF;
  float firstStripRectBottomF;
  float firstStripClipLeft;
  float firstStripClipTop;
  float firstStripClipRight;
  float firstStripClipBottom;
  float firstStripHeightF;
  float secondStripTop;
  float regionRightF;
  float regionBottomF;
  float secondStripRectLeftF;
  float secondStripRectTopF;
  float secondStripRectRightF;
  float secondStripRectBottomF;
  float secondStripClipLeft;
  float secondStripClipTop;
  float secondStripClipRight;
  float secondStripClipBottom;
  float firstColumnWidthF;
  float firstColumnRight;
  float firstColumnBottom;
  float firstColumnRectLeftF;
  float firstColumnRectTopF;
  float firstColumnRectRightF;
  float firstColumnRectBottomF;
  float firstColumnClipLeft;
  float firstColumnClipTop;
  float firstColumnClipRight;
  float firstColumnClipBottom;
  float secondColumnLeft;
  float secondColumnRectLeftF;
  float secondColumnRectTopF;
  float secondColumnRectRightF;
  float secondColumnRectBottomF;
  float secondColumnClipLeft;
  float secondColumnClipTop;
  float secondColumnClipRight;
  float secondColumnClipBottom;
  float rectLeftF;
  float rectTopF;
  float rectRightF;
  float rectBottomF;
  float clipLeft;
  float clipTop;
  float clipRight;
  float clipBottom;
  
  M<UInt16>(self + kATIR500Surface_swapBatchBuilt) = 0;
  accelBase = M<SInt32>(self + kIOATIR500Surface_accelerator);
  if (M<SInt32>(accelBase + kIOATIR500Accelerator_displayCount) != 0) {
    panel = 0;
    zero = FLOAT_0004c370;
    one = FLOAT_0004c374;
    half = FLOAT_0004c380;
    panelRec = PANEL_RECORD(self, 0);
    panelSlotCursor = self;
    do {
      useBuffer1 = (M<UInt32>(self + kIOATIR500Surface_modeBits) & 0x20) == 0;
      if (useBuffer1) {
        surfaceBuffer = M<SInt32>(self + kIOATIR500Surface_attachmentBuffer1);
      }
      else {
        surfaceBuffer = M<SInt32>(self + kIOATIR500Surface_attachmentBuffers);
      }
      panelAccel = panel * 0x78 + accelBase;
      if ((self[0xbf1] == 0x10) ||
         ((self[0xbf1] != 0x20 && (M<SInt32>(self + kIOATIR500Surface_scalingSourceWidth) == M<SInt32>(self + kIOATIR500Surface_regionWidth))
          ))) {
        scalingMode = 1;
      }
      else {
        scalingMode = 2;
      }
      regionArray = M<SInt32 *>(panelSlotCursor + 0xd60);
      regionCount = *regionArray;
      regionDataPtr = regionArray + 3;
      if (regionCount == 0) {
        regionDataPtr = regionArray + 1;
        regionCount = 1;
      }
      regionHeight = (UInt32)M<SInt16>((SInt32)regionArray + 10);
      regionX = M<SInt16>(regionArray + 1);
      regionY = (UInt32)M<SInt16>((SInt32)regionArray + 6);
      regionWidth = M<SInt16>(regionArray + 2);
      if ((M<SInt32>(self + kIOATIR500Surface_boundDVDContext) != 0) && (M<SInt32>(self + kATIR500Surface_overlayExists) != 0)) {
        if ((SInt32)regionWidth == 0) {
          return;
        }
        if (regionHeight == 0) {
          return;
        }
      }
      batchHeader = (SInt32)Vol(panelRec->entries[0].header);
      batchEntry = &panelRec->entries[0];
      isPanel0Bits = (panel == 0) << 1;
      batchWords = (UInt32 *)(batchHeader + 0x20);
      if (((panel != 0) || (M<SInt32>(self + kIOATIR500Surface_attachmentBuffers) == M<SInt32>(self + kIOATIR500Surface_attachmentBuffer1))) || (useBuffer1)) {
        batchIndex = 0;
      }
      else {
        *batchWords = 0xd0b;
        M<UInt32>(batchHeader + 0x24) = 5;
        GCopy(batchHeader + 0x28,(&g_r500_3d_blit_state_packet),0x2f4);
        rectPacketIndex = (batchHeader + 0x31c) - (SInt32)batchWords >> 2;
        formatOffset = (UInt32)(UInt8)self[0xe2] * 0x1c;
        widthUnits = 0;
        M<UInt32>(batchHeader + 0x290) =
             (UInt32)M<UInt16>(self + 200) * M<SInt32>(self + kIOATIR500Surface_buffer0MipOffset0) + M<SInt32>(self + kIOATIR500Surface_buffer0GpuBase) &
             0xffffffe0;
        if ((M<UInt32>(self + kIOATIR500Surface_buffer0TilingDegreeBits) & 0xf00000) != 0) {
          widthUnits = (SInt32)M<UInt16>(self + kIOATIR500Surface_buffer0PitchPixels) / (SInt32)(M<UInt32>(self + kIOATIR500Surface_buffer0TilingDegreeBits) >> 0x14 & 0xf);
        }
        pitchUnits = 0x20 / M<UInt16>(self + kIOATIR500Surface_buffer0BytesPerPixel);
        if (pitchUnits <= widthUnits) {
          pitchUnits = widthUnits;
        }
        savedWord250 = M<UInt32>(batchHeader + 0x250);
        M<UInt32>(batchHeader + 0x298) =
             pitchUnits & 0x3ffe | ((UInt8)self[0xe0] & 1) << 0x10 | ((UInt8)self[0xe0] & 6) << 0x10 |
             ((UInt8)self[0xe1] & 3) << 0x13 |
             FormatTableLookup_0x0004d2e0((UInt32)(UInt8)self[0xe2] * 0x1c) >> 1 & 0x1e00000;
        fieldA = FormatTableLookup_0x0004d2e0(formatOffset) >> 0x11 & 0x1f;
        M<UInt32>(batchHeader + 0x250) = fieldA | savedWord250 & 0xffffffe0;
        fieldB = FormatTableLookup_0x0004d2e0(formatOffset) >> 7 & 0x300;
        M<UInt32>(batchHeader + 0x250) = fieldB | fieldA | savedWord250 & 0xfffffce0;
        fieldC = FormatTableLookup_0x0004d2e0(formatOffset) >> 3 & 0xc00;
        M<UInt32>(batchHeader + 0x250) = fieldC | fieldB | fieldA | savedWord250 & 0xfffff0e0;
        fieldD = (FormatTableLookup_0x0004d2e0(formatOffset) & 0x1800) << 1;
        M<UInt32>(batchHeader + 0x250) = fieldD | fieldC | fieldB | fieldA | savedWord250 & 0xffffc0e0;
        M<UInt32>(batchHeader + 0x250) =
             (FormatTableLookup_0x0004d2e0(formatOffset) & 0x600) << 5 |
             fieldD | fieldC | fieldB | fieldA | savedWord250 & 0xffff00e0;
        if (((M<UInt32>(self + kIOATIR500Surface_buffer0TilingDegreeBits) & 0xf00000) == 0) ||
           (columnDivA = (SInt32)M<UInt16>(self + kIOATIR500Surface_buffer0Width) / (SInt32)(M<UInt32>(self + kIOATIR500Surface_buffer0TilingDegreeBits) >> 0x14 & 0xf),
           lastColumn = columnDivA - 1, columnDivA == 0)) {
          lastColumn = 0;
        }
        lastRow = 0;
        if (M<UInt16>(self + kIOATIR500Surface_buffer0Height) != 0) {
          lastRow = M<UInt16>(self + kIOATIR500Surface_buffer0Height) - 1;
        }
        M<UInt32>(batchHeader + 0x2f4) = lastColumn & 0x1fff | (lastRow & 0x1fff) << 0xd;
        buffer1FormatIndex = self[0x15a];
        M<UInt32>(batchHeader + 0x2a8) =
             ((UInt8)self[0x158] & 7) << 2 |
             (UInt32)M<UInt16>(self + kIOATIR500Surface_buffer1BasePitch) * M<SInt32>(self + kIOATIR500Surface_buffer1MipOffset0) + M<SInt32>(self + kIOATIR500Surface_buffer1GpuBase) &
             0xffffffe0;
        if (((M<UInt32>(self + kIOATIR500Surface_buffer1TilingDegreeBits) & 0xf00000) == 0) ||
           (columnDivA = (SInt32)M<UInt16>(self + kIOATIR500Surface_buffer1Width) / (SInt32)(M<UInt32>(self + kIOATIR500Surface_buffer1TilingDegreeBits) >> 0x14 & 0xf),
           lastColumn = columnDivA - 1, columnDivA == 0)) {
          lastColumn = 0;
        }
        lastRow = 0;
        if (M<UInt16>(self + kIOATIR500Surface_buffer1Height) != 0) {
          lastRow = M<UInt16>(self + kIOATIR500Surface_buffer1Height) - 1;
        }
        M<UInt32>(batchHeader + 0x2c0) = lastColumn & 0x7ff | (lastRow & 0x7ff) << 0xb | 0x80000000;
        fmtE4B = FormatTableLookup_0x0004d2e4((UInt32)(UInt8)buffer1FormatIndex * 0x1c);
        M<UInt32>(batchHeader + 0x2c8) =
             fmtE4B >> 0x13 & 0x1f | (fmtE4B & 0x40) << 0x10 | fmtE4B >> 7 & 0xe00 |
             fmtE4B >> 1 & 0x7000 | (fmtE4B & 0x1c00) << 5 | (fmtE4B & 0x380) << 0xb;
        tilingBitsB = M<UInt32>(self + kIOATIR500Surface_buffer1TilingDegreeBits);
        buffer1Untiled = (tilingBitsB & 0xf00000) == 0;
        if (buffer1Untiled) {
          pitchPerDegreeB = 0;
        }
        else {
          pitchPerDegreeB = (SInt32)M<UInt16>(self + kIOATIR500Surface_buffer1PitchPixels) / (SInt32)(tilingBitsB >> 0x14 & 0xf);
        }
        minPitch = 0x20 / M<UInt16>(self + kIOATIR500Surface_buffer1BytesPerPixel);
        if (minPitch <= pitchPerDegreeB) {
          minPitch = pitchPerDegreeB;
        }
        if ((buffer1Untiled) ||
           (columnDivB = (SInt32)M<UInt16>(self + kIOATIR500Surface_buffer1Width) / (SInt32)(tilingBitsB >> 0x14 & 0xf), lastColumnB = columnDivB - 1,
           columnDivB == 0)) {
          lastColumnB = 0;
        }
        lastRowB = 0;
        if (M<UInt16>(self + kIOATIR500Surface_buffer1Height) != 0) {
          lastRowB = M<UInt16>(self + kIOATIR500Surface_buffer1Height) - 1;
        }
        M<UInt32>(batchHeader + 0x2d0) =
             minPitch - 1 & 0x3fff | (lastColumnB & 0x800) << 4 | (lastRowB & 0x800) << 5;
        lit37c = FLOAT_0004c37c;
        nextIndex = rectPacketIndex * 4 + 0x30 >> 2;
        hwWordB74 = M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0xb74);
        M<UInt32>(batchHeader + 0x2b0) = M<UInt32>(batchHeader + 0x2b0) & 0xffffe1ff | 0x1400;
        M<UInt32>(batchHeader + 0x3c) = 0x70000;
        M<UInt32>(batchHeader + 0x54) = hwWordB74;
        surfaceWidth = M<SInt16>(self + kIOATIR500Surface_width);
        surfaceHeight = M<SInt16>(self + kIOATIR500Surface_height);
        batchWords[rectPacketIndex] = 0x31080;
        batchWords[rectPacketIndex + 5] = 0x1087;
        batchWords[rectPacketIndex + 1] = FBITS((float)zero);
        batchWords[rectPacketIndex + 2] = FBITS((float)one);
        batchWords[rectPacketIndex + 3] = FBITS((float)one);
        batchWords[rectPacketIndex + 4] = FBITS((float)zero);
        surfaceWidthF = (SInt32)((SInt32)surfaceWidth);
        surfaceHeightF = (SInt32)((SInt32)surfaceHeight);
        batchWords[rectPacketIndex + 7] = 0xc0033500;
        batchWords[rectPacketIndex + 8] = 0x10031;
        batchWords[rectPacketIndex + 9] = FBITS((float)((surfaceWidthF + zero) * half));
        batchWords[rectPacketIndex + 10] = FBITS((float)((surfaceHeightF + zero) * half));
        batchWords[rectPacketIndex + 0xb] = 0;
        batchWords[rectPacketIndex + 6] = (SInt32)(surfaceWidthF * lit37c) << 0x10 | (SInt32)(surfaceHeightF * lit37c);
        batchWords[nextIndex] = 0x1393;
        batchWords[nextIndex + 1] = 10;
        batchWords[nextIndex + 2] = 0x5c8;
        batchIndex = nextIndex + 4;
        batchWords[nextIndex + 3] = 0x70000;
      }
      M<SInt32>((SInt32)Vol(batchEntry->header) + 0x18) = batchIndex;
      if (panelRec->active != 0x0) {
        packetCursor = batchIndex;
        if (self[0xbed] == 0x0) {
          accelerator = M<SInt32>(self + kIOATIR500Surface_accelerator);
        }
        else {
          accelerator = M<SInt32>(self + kIOATIR500Surface_accelerator);
          if ((M<char>(accelerator + 0x9b0) == '\0') ||
             (M<SInt32>(panel * 0x18 + accelerator + kIOATIR500Accelerator_swdsPanel0Flag) == 0)) {
            if ((SInt32)regionY < 0) {
              scissorStart = 0;
              scissorEnd = regionHeight;
            }
            else {
              scissorStart = regionY;
              scissorEnd = regionY + regionHeight;
            }
            panelHeight = (UInt32)M<UInt16>(panelAccel + 0x14a);
            if (panelHeight < scissorStart) {
              scissorStart = panelHeight;
            }
            if (panelHeight < scissorEnd) {
              scissorEnd = panelHeight;
            }
            batchWords[batchIndex] = 0x1393;
            batchWords[batchIndex + 1] = 10;
            batchWords[batchIndex + 2] = 0xd0b;
            batchWords[batchIndex + 3] = 5;
            batchWords[batchIndex + 4] = 0x5c8;
            packetCursor = batchIndex + 6;
            batchWords[batchIndex + 5] = 0x70000;
            if ((bool)(isPanel0Bits >> 1 & 1)) {
              overlapFlag = M<SInt32>(accelerator + kIOATIR500Accelerator_scanoutOverlapsVram);
              if (overlapFlag == 0) {
                batchWords[packetCursor] = 0x194e;
                batchWords[batchIndex + 7] =
                     scissorStart & ~M<UInt32>(accelerator + kIOATIR500Accelerator_display1Enabled) |
                     (scissorEnd & ~M<UInt32>(accelerator + kIOATIR500Accelerator_display1Enabled)) << 0x10 | 0x80000000;
                batchWords[batchIndex + 8] = 0x5c8;
                packetCursor = batchIndex + 10;
                batchWords[batchIndex + 9] = 8;
              }
              else {
LAB_0003f644:
                if (overlapFlag != 0) goto LAB_0003f654;
              }
            }
            else {
              if (panel != 1) {
                overlapFlag = M<SInt32>(accelerator + kIOATIR500Accelerator_scanoutOverlapsVram);
                goto LAB_0003f644;
              }
LAB_0003f654:
              batchWords[packetCursor] = 0x1b4e;
              batchWords[batchIndex + 7] =
                   scissorStart & ~M<UInt32>(accelerator + kIOATIR500Accelerator_display2Enabled) |
                   (scissorEnd & ~M<UInt32>(accelerator + kIOATIR500Accelerator_display2Enabled)) << 0x10 | 0x80000000;
              batchWords[batchIndex + 8] = 0x5c8;
              batchWords[batchIndex + 9] = 0x80000008;
              packetCursor = batchIndex + 10;
            }
          }
        }
        if (M<SInt32>(self + kIOATIR500Surface_scalingSourceWidth) == M<SInt32>(self + kIOATIR500Surface_regionWidth)) {
          heightRatio = 1.0;
          widthRatio = 1.0;
        }
        else {
          widthRatio = FLOAT_0004c370;
          if ((SInt32)M<SInt16>(self + kIOATIR500Surface_regionWidth) != 0) {
            widthRatio = (float)(SInt32)((SInt32)M<SInt16>(self + kIOATIR500Surface_scalingSourceWidth)) /
                    (float)(SInt32)((SInt32)M<SInt16>(self + kIOATIR500Surface_regionWidth));
          }
          heightRatio = 0.0;
          if ((SInt32)M<SInt16>(self + kIOATIR500Surface_regionHeight) != 0) {
            heightRatio = (float)(SInt32)((SInt32)M<SInt16>(self + kIOATIR500Surface_scalingSourceHeight)) /
                     (float)(SInt32)((SInt32)M<SInt16>(self + kIOATIR500Surface_regionHeight));
          }
        }
        srcFormatIndex = (UInt32)M<UInt8>(surfaceBuffer + 0x3a);
        dstFormatIndex = (UInt32)M<UInt8>(panelAccel + 0x166);
        gbTileConfig = M<UInt32>(accelerator + kIOATIR500Accelerator_gbTileConfig);
        if (srcFormatIndex == dstFormatIndex) {
          formatsDiffer = false;
          formatIndexSrc = dstFormatIndex;
        }
        else {
          formatsDiffer = ((FormatTableLookup_0x0004d2d8(dstFormatIndex * 0x1c) ^
                   FormatTableLookup_0x0004d2d8(srcFormatIndex * 0x1c)) & 0xffffc000) != 0;
          formatIndexSrc = srcFormatIndex;
        }
        bufferHeight = (UInt32)M<UInt16>(surfaceBuffer + 0x1e);
        bufferWidth = (UInt32)M<UInt16>(surfaceBuffer + 0x1c);
        pitch = M<SInt32>(panelAccel + 0x16c);
        panelOriginY = M<UInt16>(panelAccel + 0x14c);
        dstBaseAddr = M<SInt32>(panelAccel + 0x134);
        dstUntiled = (M<UInt32>(panelAccel + 0x168) & 0xf00000) == 0;
        if (dstUntiled) {
          dstWidthUnits = 0;
        }
        else {
          dstWidthUnits = (SInt32)M<UInt16>(panelAccel + 0x140) / (SInt32)(M<UInt32>(panelAccel + 0x168) >> 0x14 & 0xf);
        }
        dstPitchUnits = 0x20 / M<UInt16>(panelAccel + 0x142);
        if (dstPitchUnits <= dstWidthUnits) {
          dstPitchUnits = dstWidthUnits;
        }
        fmtE0 = FormatTableLookup_0x0004d2e0(dstFormatIndex * 0x1c);
        dstTilingByte0 = M<UInt8>(panelAccel + 0x164);
        dstTilingByte1 = M<UInt8>(panelAccel + 0x165);
        if ((dstUntiled) ||
           (scissorWidthUnits = (SInt32)M<UInt16>(panelAccel + 0x148) / (SInt32)(M<UInt32>(panelAccel + 0x168) >> 0x14 & 0xf),
           scissorRight = scissorWidthUnits - 1, scissorWidthUnits == 0)) {
          scissorRight = 0;
        }
        scissorBottom = 0;
        if (M<UInt16>(panelAccel + 0x14a) != 0) {
          scissorBottom = M<UInt16>(panelAccel + 0x14a) - 1;
        }
        bufferOriginY = M<UInt16>(surfaceBuffer + 0x20);
        mip0Offset = M<SInt32>(surfaceBuffer + 0x40);
        srcGpuBase = M<SInt32>(surfaceBuffer + 8);
        srcTilingByte0 = M<UInt8>(surfaceBuffer + 0x38);
        srcUntiled = (M<UInt32>(surfaceBuffer + 0x3c) & 0xf00000) == 0;
        if ((srcUntiled) ||
           (srcWidthUnits = (SInt32)bufferWidth / (SInt32)(M<UInt32>(surfaceBuffer + 0x3c) >> 0x14 & 0xf), srcLastColumn = srcWidthUnits - 1,
           srcWidthUnits == 0)) {
          srcLastColumn = 0;
        }
        if (bufferHeight != 0) {
          srcLastRow = bufferHeight - 1;
        }
        else {
          srcLastRow = 0;
        }
        fmtE4 = FormatTableLookup_0x0004d2e4(formatIndexSrc * 0x1c);
        if (srcUntiled) {
          srcWidthUnits = 0;
        }
        else {
          srcWidthUnits = (SInt32)M<UInt16>(surfaceBuffer + 0x14) / (SInt32)(M<UInt32>(surfaceBuffer + 0x3c) >> 0x14 & 0xf);
        }
        srcPitchUnits = 0x20 / M<UInt16>(surfaceBuffer + 0x16);
        if (srcPitchUnits <= srcWidthUnits) {
          srcPitchUnits = srcWidthUnits;
        }
        if ((srcUntiled) ||
           (columnDivB = (SInt32)bufferWidth / (SInt32)(M<UInt32>(surfaceBuffer + 0x3c) >> 0x14 & 0xf), srcLastColumnCopy = columnDivB - 1,
           columnDivB == 0)) {
          srcLastColumnCopy = 0;
        }
        if (bufferHeight != 0) {
          srcLastRowCopy = bufferHeight - 1;
        }
        else {
          srcLastRowCopy = 0;
        }
        bufferWidthF = (UInt32)(bufferWidth);
        regionXF = (SInt32)((SInt32)regionX);
        regionYF = (SInt32)(regionY);
        regionWidthF = (SInt32)((SInt32)regionWidth);
        invBufferWidthD = FLOAT_0004c370;
        blitPacket = batchWords + packetCursor;
        regionHeightF = (SInt32)(regionHeight);
        bufferHeightF = (UInt32)(bufferHeight);
        scalingBufferXF = (SInt32)((SInt32)M<SInt16>(self + kIOATIR500Surface_scalingBufferX));
        scalingBufferYF = (SInt32)((SInt32)M<SInt16>(self + kIOATIR500Surface_scalingBufferY));
        sourceScaleX = widthRatio;
        sourceScaleY = heightRatio;
        tearingWideBlit = M<SInt32>(accelerator + kIOATIR500Accelerator_tearingWideBlit);
        if (bufferWidthF != invBufferWidthD) {
          invBufferWidthD = (one / bufferWidthF);
        }
        invBufferHeightD = FLOAT_0004c370;
        if (bufferHeightF != invBufferHeightD) {
          invBufferHeightD = (one / bufferHeightF);
        }
        packetCursor = 0xbd;
        GCopy(blitPacket,(&g_r500_3d_blit_state_packet),0x2f4);
        savedWordA2 = blitPacket[0xa2];
        blitPacket[0xa0] = (srcTilingByte0 & 7) << 2 | (UInt32)bufferOriginY * mip0Offset + srcGpuBase & 0xffffffe0;
        blitPacket[0xa6] = srcLastColumn & 0x7ff | (srcLastRow & 0x7ff) << 0xb | 0x80000000;
        blitPacket[0xa8] =
             fmtE4 >> 0x13 & 0x1f | (fmtE4 & 0x40) << 0x10 | fmtE4 >> 7 & 0xe00 |
             fmtE4 >> 1 & 0x7000 | (fmtE4 & 0x1c00) << 5 | (fmtE4 & 0x380) << 0xb;
        blitPacket[0xaa] = srcPitchUnits - 1 & 0x3fff | (srcLastColumnCopy & 0x800) << 4 | (srcLastRowCopy & 0x800) << 5;
        blitPacket[0x9c] =
             dstPitchUnits & 0x3ffe | (dstTilingByte0 & 1) << 0x10 | (dstTilingByte0 & 6) << 0x10 | (dstTilingByte1 & 3) << 0x13 |
             fmtE0 >> 1 & 0x1e00000;
        blitPacket[0x9a] = (UInt32)panelOriginY * pitch + dstBaseAddr & 0xffffffe0;
        blitPacket[0x8a] =
             (fmtE0 & 0x600) << 5 |
             (fmtE0 & 0x1800) << 1 |
             fmtE0 >> 3 & 0xc00 | fmtE0 >> 7 & 0x300 | fmtE0 >> 0x11 & 0x1f;
        blitPacket[0xb2] = 0;
        blitPacket[0xb3] = scissorRight & 0x1fff | (scissorBottom & 0x1fff) << 0xd;
        blitPacket[0xb] = gbTileConfig;
        blitPacket[0xa2] = scalingMode << 9 | savedWordA2 & 0xfffff9ff;
        blitPacket[0xa2] = scalingMode << 0xb | scalingMode << 9 | savedWordA2 & 0xffffe1ff;
        if (formatsDiffer) {
          blitPacket[0x1e] = blitPacket[0x1e] & 0xfffffffc | 2;
        }
        splitThreshold = FLOAT_0004c378;
        if (((splitThreshold < bufferWidthF) && (tearingWideBlit != 0)) || (splitThreshold < bufferHeightF)) {
          if (bufferWidthF <= FLOAT_0004c378) {
            fmtDC = FormatTableLookup_0x0004d2dc(srcFormatIndex * 0x1c);
            savedWordAA = blitPacket[0xaa];
            halfHeightRaw = (SInt32)bufferHeightF >> 1;
            firstHeight = halfHeightRaw & 0xffffffc0;
            secondHeight = (SInt32)bufferHeightF - firstHeight;
            firstHeightPlus1 = firstHeight + 1;
            stripCenterY = regionYF;
            if (sourceScaleY != zero) {
              stripCenterY = (regionYF + (((SInt32)(firstHeight + firstHeightPlus1) * half + scalingBufferYF) / sourceScaleY));
            }
            if (stripCenterY <= zero) {
              stripCenterY = stripCenterY - half;
            }
            else {
              stripCenterY = stripCenterY + half;
            }
            firstStripHeightF = ((SInt32)((SInt32)stripCenterY) - regionYF);
            blitPacket[0xa6] = (halfHeightRaw & 0x7c0) << 0xb | blitPacket[0xa6] & 0xffc007ff;
            blitPacket[0xbd] = 0x1040;
            stripCursor = 0xbf;
            blitPacket[0xbe] = 0;
            halfF = FLOAT_0004c380;
            heightRatio = FLOAT_0004c37c;
            widthRatio = FLOAT_0004c370;
            if (firstHeightPlus1 != 0) {
              widthRatio = (float)(one / (SInt32)(firstHeightPlus1));
            }
            if (regionCount != 0) {
              firstStripRight = (regionXF + regionWidthF);
              firstStripBottom = (regionYF + firstStripHeightF);
              packetIndex = stripCursor;
              regionCursor = regionDataPtr;
              stripsLeft = regionCount;
              do {
                firstStripRectLeftF = (SInt32)((SInt32)M<SInt16>(regionCursor));
                edgeDelta = (float)(regionXF - firstStripRectLeftF);
                firstStripClipLeft = regionXF;
                if (edgeDelta < 0.0) {
                  firstStripClipLeft = firstStripRectLeftF;
                }
                if (-edgeDelta < 0.0) {
                  firstStripClipLeft = regionXF;
                }
                firstStripRectTopF = (SInt32)((SInt32)(SInt16)*regionCursor);
                edgeDelta = (float)(regionYF - firstStripRectTopF);
                firstStripClipTop = regionYF;
                if (edgeDelta < 0.0) {
                  firstStripClipTop = firstStripRectTopF;
                }
                if (-edgeDelta < 0.0) {
                  firstStripClipTop = regionYF;
                }
                firstStripRectRightF = (SInt32)((SInt32)M<SInt16>(regionCursor) + (SInt32)M<SInt16>(regionCursor + 1));
                edgeDelta = (float)(firstStripRectRightF - firstStripRight);
                firstStripClipRight = firstStripRight;
                if (edgeDelta < 0.0) {
                  firstStripClipRight = firstStripRectRightF;
                }
                if (-edgeDelta < 0.0) {
                  firstStripClipRight = firstStripRight;
                }
                firstStripRectBottomF = (SInt32)((SInt32)(SInt16)*regionCursor + (SInt32)M<SInt16>((SInt32)regionCursor + 6));
                edgeDelta = (float)(firstStripRectBottomF - firstStripBottom);
                firstStripClipBottom = firstStripBottom;
                if (edgeDelta < 0.0) {
                  firstStripClipBottom = firstStripRectBottomF;
                }
                if (-edgeDelta < 0.0) {
                  firstStripClipBottom = firstStripBottom;
                }
                stripCursor = packetIndex;
                if ((FLOAT_0004c370 < (float)(firstStripClipRight - firstStripClipLeft)) &&
                   (FLOAT_0004c370 < (float)(firstStripClipBottom - firstStripClipTop))) {
                  blitPacket[packetIndex] = 0x31080;
                  blitPacket[packetIndex + 5] = 0x1087;
                  stripCursor = packetIndex * 4 + 0x30 >> 2;
                  blitPacket[packetIndex + 1] = FBITS((float)(invBufferWidthD * (sourceScaleX * (firstStripClipLeft - regionXF) -
                                                       scalingBufferXF)));
                  blitPacket[packetIndex + 2] =
                       FBITS(widthRatio * (float)(sourceScaleY * (firstStripClipBottom - regionYF) - scalingBufferYF));
                  blitPacket[packetIndex + 3] = FBITS((float)(invBufferWidthD * (sourceScaleX * (firstStripClipRight - regionXF) -
                                                       scalingBufferXF)));
                  blitPacket[packetIndex + 4] =
                       FBITS(widthRatio * (float)(sourceScaleY * (firstStripClipTop - regionYF) - scalingBufferYF));
                  blitPacket[packetIndex + 7] = 0xc0033500;
                  blitPacket[packetIndex + 9] = FBITS((float)(firstStripClipLeft + firstStripClipRight) * halfF);
                  blitPacket[packetIndex + 10] = FBITS((float)(firstStripClipTop + firstStripClipBottom) * halfF);
                  blitPacket[packetIndex + 8] = 0x10031;
                  blitPacket[packetIndex + 0xb] = 0;
                  blitPacket[packetIndex + 6] =
                       (SInt32)((float)(firstStripClipRight - firstStripClipLeft) * heightRatio) << 0x10 |
                       (SInt32)((float)(firstStripClipBottom - firstStripClipTop) * heightRatio);
                }
                regionCursor = regionCursor + 2;
                stripsLeft = stripsLeft + -1;
                packetIndex = stripCursor;
              } while (stripsLeft != 0);
            }
            textureOffsetWord = blitPacket[0xa0];
            blitPacket[stripCursor] = 0x1150;
            blitPacket[stripCursor + 1] =
                 textureOffsetWord + (firstHeight * ((savedWordAA & 0x3fff) + 1) << (fmtDC >> 0xc & 7) & 0xffffffe0);
            savedWordA6 = blitPacket[0xa6];
            blitPacket[stripCursor + 2] = 0x1120;
            blitPacket[stripCursor + 3] = (secondHeight - 1) * 0x800 & 0x3ff800 | savedWordA6 & 0xffc007ff;
            blitPacket[stripCursor + 4] = 0x1040;
            packetCursor = stripCursor + 6;
            blitPacket[stripCursor + 5] = 0;
            halfF = FLOAT_0004c380;
            heightRatio = FLOAT_0004c37c;
            widthRatio = FLOAT_0004c370;
            if (secondHeight != 0) {
              widthRatio = (float)(one / (SInt32)(secondHeight));
            }
            secondStripBiasY = (scalingBufferYF + (SInt32)(firstHeight));
            if (regionCount != 0) {
              secondStripTop = (regionYF + firstStripHeightF);
              regionRightF = (regionXF + regionWidthF);
              regionBottomF = (regionYF + regionHeightF);
              stripCursor = packetCursor;
              regionsLeft = regionCount;
              do {
                secondStripRectLeftF = (SInt32)((SInt32)M<SInt16>(regionDataPtr));
                edgeDelta = (float)(regionXF - secondStripRectLeftF);
                secondStripClipLeft = regionXF;
                if (edgeDelta < 0.0) {
                  secondStripClipLeft = secondStripRectLeftF;
                }
                if (-edgeDelta < 0.0) {
                  secondStripClipLeft = regionXF;
                }
                secondStripRectTopF = (SInt32)((SInt32)(SInt16)*regionDataPtr);
                edgeDelta = (float)(secondStripRectTopF - secondStripTop);
                if (edgeDelta < 0.0) {
                  secondStripRectTopF = secondStripTop;
                }
                secondStripClipTop = secondStripTop;
                if (-edgeDelta < 0.0) {
                  secondStripClipTop = secondStripRectTopF;
                }
                secondStripRectRightF = (SInt32)((SInt32)M<SInt16>(regionDataPtr) + (SInt32)M<SInt16>(regionDataPtr + 1));
                edgeDelta = (float)(secondStripRectRightF - regionRightF);
                secondStripClipRight = regionRightF;
                if (edgeDelta < 0.0) {
                  secondStripClipRight = secondStripRectRightF;
                }
                if (-edgeDelta < 0.0) {
                  secondStripClipRight = regionRightF;
                }
                secondStripRectBottomF = (SInt32)((SInt32)(SInt16)*regionDataPtr + (SInt32)M<SInt16>((SInt32)regionDataPtr + 6));
                edgeDelta = (float)(secondStripRectBottomF - regionBottomF);
                secondStripClipBottom = regionBottomF;
                if (edgeDelta < 0.0) {
                  secondStripClipBottom = secondStripRectBottomF;
                }
                if (-edgeDelta < 0.0) {
                  secondStripClipBottom = regionBottomF;
                }
                packetCursor = stripCursor;
                if ((FLOAT_0004c370 < (float)(secondStripClipRight - secondStripClipLeft)) &&
                   (FLOAT_0004c370 < (float)(secondStripClipBottom - secondStripClipTop))) {
                  blitPacket[stripCursor] = 0x31080;
                  blitPacket[stripCursor + 5] = 0x1087;
                  packetCursor = stripCursor * 4 + 0x30 >> 2;
                  blitPacket[stripCursor + 1] = FBITS((float)(invBufferWidthD * (sourceScaleX * (secondStripClipLeft - regionXF) -
                                                       scalingBufferXF)));
                  blitPacket[stripCursor + 2] =
                       FBITS(widthRatio * (float)(sourceScaleY * (secondStripClipBottom - regionYF) - secondStripBiasY));
                  blitPacket[stripCursor + 3] = FBITS((float)(invBufferWidthD * (sourceScaleX * (secondStripClipRight - regionXF) -
                                                       scalingBufferXF)));
                  blitPacket[stripCursor + 4] =
                       FBITS(widthRatio * (float)(sourceScaleY * (secondStripClipTop - regionYF) - secondStripBiasY));
                  blitPacket[stripCursor + 7] = 0xc0033500;
                  blitPacket[stripCursor + 9] = FBITS((float)(secondStripClipLeft + secondStripClipRight) * halfF);
                  blitPacket[stripCursor + 10] = FBITS((float)(secondStripClipTop + secondStripClipBottom) * halfF);
                  blitPacket[stripCursor + 8] = 0x10031;
                  blitPacket[stripCursor + 0xb] = 0;
                  blitPacket[stripCursor + 6] =
                       (SInt32)((float)(secondStripClipRight - secondStripClipLeft) * heightRatio) << 0x10 |
                       (SInt32)((float)(secondStripClipBottom - secondStripClipTop) * heightRatio);
                }
                regionDataPtr = regionDataPtr + 2;
                regionsLeft = regionsLeft + -1;
                stripCursor = packetCursor;
              } while (regionsLeft != 0);
            }
          }
          else {
            halfWidth = (SInt32)bufferWidthF >> 1 & 0xfffffe00;
            secondWidth = (SInt32)bufferWidthF - halfWidth;
            halfWidthPlus2 = halfWidth + 2;
            if ((blitPacket[0xa0] & 0x18) == 0) {
              fmtDC = FormatTableLookup_0x0004d2dc(srcFormatIndex * 0x1c);
              tileShift = 0;
            }
            else {
              fmtDC = FormatTableLookup_0x0004d2dc(srcFormatIndex * 0x1c);
              tileShift = -(fmtDC >> 8 & 3);
            }
            tileUnits = (SInt32)halfWidth >> ((tileShift - (fmtDC >> 0xc & 7)) + 5 & 0x3f);
            texOffsetDelta = tileUnits << 5;
            if (((UInt32)blitPacket[0xa0] >> 2 & 1) != 0) {
              texOffsetDelta = (tileUnits << 0xc) >> 3;
            }
            columnCenterX = regionXF;
            if (sourceScaleX != zero) {
              columnCenterX = (regionXF + (((SInt32)(halfWidth + halfWidthPlus2) * half + scalingBufferXF) / sourceScaleX));
            }
            if (columnCenterX <= zero) {
              columnCenterX = columnCenterX - half;
            }
            else {
              columnCenterX = columnCenterX + half;
            }
            firstColumnWidthF = ((SInt32)((SInt32)columnCenterX) - regionXF);
            blitPacket[0xa6] = halfWidth + 1 & 0x7ff | blitPacket[0xa6] & 0xfffff800;
            halfF = FLOAT_0004c380;
            heightRatio = FLOAT_0004c37c;
            widthRatio = FLOAT_0004c370;
            if (halfWidthPlus2 != 0) {
              widthRatio = (float)(one / (SInt32)(halfWidthPlus2));
            }
            if (regionCount != 0) {
              firstColumnRight = (regionXF + firstColumnWidthF);
              firstColumnBottom = (regionYF + regionHeightF);
              regionCursor = regionDataPtr;
              packetIndex = packetCursor;
              columnsLeft = regionCount;
              do {
                firstColumnRectLeftF = (SInt32)((SInt32)M<SInt16>(regionCursor));
                edgeDelta = (float)(regionXF - firstColumnRectLeftF);
                firstColumnClipLeft = regionXF;
                if (edgeDelta < 0.0) {
                  firstColumnClipLeft = firstColumnRectLeftF;
                }
                if (-edgeDelta < 0.0) {
                  firstColumnClipLeft = regionXF;
                }
                firstColumnRectTopF = (SInt32)((SInt32)(SInt16)*regionCursor);
                edgeDelta = (float)(regionYF - firstColumnRectTopF);
                firstColumnClipTop = regionYF;
                if (edgeDelta < 0.0) {
                  firstColumnClipTop = firstColumnRectTopF;
                }
                if (-edgeDelta < 0.0) {
                  firstColumnClipTop = regionYF;
                }
                firstColumnRectRightF = (SInt32)((SInt32)M<SInt16>(regionCursor) + (SInt32)M<SInt16>(regionCursor + 1));
                edgeDelta = (float)(firstColumnRectRightF - firstColumnRight);
                firstColumnClipRight = firstColumnRight;
                if (edgeDelta < 0.0) {
                  firstColumnClipRight = firstColumnRectRightF;
                }
                if (-edgeDelta < 0.0) {
                  firstColumnClipRight = firstColumnRight;
                }
                firstColumnRectBottomF = (SInt32)((SInt32)(SInt16)*regionCursor + (SInt32)M<SInt16>((SInt32)regionCursor + 6));
                edgeDelta = (float)(firstColumnBottom - firstColumnRectBottomF);
                if (edgeDelta < 0.0) {
                  firstColumnRectBottomF = firstColumnBottom;
                }
                firstColumnClipBottom = firstColumnBottom;
                if (-edgeDelta < 0.0) {
                  firstColumnClipBottom = firstColumnRectBottomF;
                }
                packetCursor = packetIndex;
                if ((FLOAT_0004c370 < (float)(firstColumnClipRight - firstColumnClipLeft)) &&
                   (FLOAT_0004c370 < (float)(firstColumnClipBottom - firstColumnClipTop))) {
                  blitPacket[packetIndex] = 0x31080;
                  blitPacket[packetIndex + 5] = 0x1087;
                  packetCursor = packetIndex * 4 + 0x30 >> 2;
                  blitPacket[packetIndex + 1] =
                       FBITS(widthRatio * (float)(sourceScaleX * (firstColumnClipLeft - regionXF) - scalingBufferXF));
                  blitPacket[packetIndex + 2] = FBITS((float)(invBufferHeightD * (sourceScaleY * (firstColumnClipBottom - regionYF) -
                                                       scalingBufferYF)));
                  blitPacket[packetIndex + 3] =
                       FBITS(widthRatio * (float)(sourceScaleX * (firstColumnClipRight - regionXF) - scalingBufferXF));
                  blitPacket[packetIndex + 4] = FBITS((float)(invBufferHeightD * (sourceScaleY * (firstColumnClipTop - regionYF) -
                                                       scalingBufferYF)));
                  blitPacket[packetIndex + 7] = 0xc0033500;
                  blitPacket[packetIndex + 9] = FBITS((float)(firstColumnClipLeft + firstColumnClipRight) * halfF);
                  blitPacket[packetIndex + 10] = FBITS((float)(firstColumnClipTop + firstColumnClipBottom) * halfF);
                  blitPacket[packetIndex + 8] = 0x10031;
                  blitPacket[packetIndex + 0xb] = 0;
                  blitPacket[packetIndex + 6] =
                       (SInt32)((float)(firstColumnClipRight - firstColumnClipLeft) * heightRatio) << 0x10 |
                       (SInt32)((float)(firstColumnClipBottom - firstColumnClipTop) * heightRatio);
                }
                regionCursor = regionCursor + 2;
                columnsLeft = columnsLeft + -1;
                packetIndex = packetCursor;
              } while (columnsLeft != 0);
            }
            textureOffsetWord = blitPacket[0xa0];
            blitPacket[packetCursor] = 0x1150;
            blitPacket[packetCursor + 1] = textureOffsetWord + texOffsetDelta;
            savedWordA6 = blitPacket[0xa6];
            blitPacket[packetCursor + 2] = 0x1120;
            lengthIndex = packetCursor + 3;
            packetCursor = packetCursor + 4;
            blitPacket[lengthIndex] = secondWidth - 1 & 0x7ff | savedWordA6 & 0xfffff800;
            halfF = FLOAT_0004c380;
            heightRatio = FLOAT_0004c37c;
            widthRatio = FLOAT_0004c370;
            if (secondWidth != 0) {
              widthRatio = (float)(one / (SInt32)(secondWidth));
            }
            secondColumnBiasX = (scalingBufferXF + (SInt32)(halfWidth));
            if (regionCount != 0) {
              secondColumnLeft = (regionXF + firstColumnWidthF);
              regionRightF = (regionXF + regionWidthF);
              regionBottomF = (regionYF + regionHeightF);
              columnCursor = packetCursor;
              regionsLeft = regionCount;
              do {
                secondColumnRectLeftF = (SInt32)((SInt32)M<SInt16>(regionDataPtr));
                edgeDelta = (float)(secondColumnLeft - secondColumnRectLeftF);
                secondColumnClipLeft = secondColumnLeft;
                if (edgeDelta < 0.0) {
                  secondColumnClipLeft = secondColumnRectLeftF;
                }
                if (-edgeDelta < 0.0) {
                  secondColumnClipLeft = secondColumnLeft;
                }
                secondColumnRectTopF = (SInt32)((SInt32)(SInt16)*regionDataPtr);
                edgeDelta = (float)(regionYF - secondColumnRectTopF);
                secondColumnClipTop = regionYF;
                if (edgeDelta < 0.0) {
                  secondColumnClipTop = secondColumnRectTopF;
                }
                if (-edgeDelta < 0.0) {
                  secondColumnClipTop = regionYF;
                }
                secondColumnRectRightF = (SInt32)((SInt32)M<SInt16>(regionDataPtr) + (SInt32)M<SInt16>(regionDataPtr + 1));
                edgeDelta = (float)(regionRightF - secondColumnRectRightF);
                if (edgeDelta < 0.0) {
                  secondColumnRectRightF = regionRightF;
                }
                secondColumnClipRight = regionRightF;
                if (-edgeDelta < 0.0) {
                  secondColumnClipRight = secondColumnRectRightF;
                }
                secondColumnRectBottomF = (SInt32)((SInt32)(SInt16)*regionDataPtr + (SInt32)M<SInt16>((SInt32)regionDataPtr + 6));
                edgeDelta = (float)(regionBottomF - secondColumnRectBottomF);
                if (edgeDelta < 0.0) {
                  secondColumnRectBottomF = regionBottomF;
                }
                secondColumnClipBottom = regionBottomF;
                if (-edgeDelta < 0.0) {
                  secondColumnClipBottom = secondColumnRectBottomF;
                }
                packetCursor = columnCursor;
                if ((FLOAT_0004c370 < (float)(secondColumnClipRight - secondColumnClipLeft)) &&
                   (FLOAT_0004c370 < (float)(secondColumnClipBottom - secondColumnClipTop))) {
                  blitPacket[columnCursor] = 0x31080;
                  blitPacket[columnCursor + 5] = 0x1087;
                  packetCursor = columnCursor * 4 + 0x30 >> 2;
                  blitPacket[columnCursor + 1] =
                       FBITS(widthRatio * (float)(sourceScaleX * (secondColumnClipLeft - regionXF) - secondColumnBiasX));
                  blitPacket[columnCursor + 2] = FBITS((float)(invBufferHeightD * (sourceScaleY * (secondColumnClipBottom - regionYF) -
                                                       scalingBufferYF)));
                  blitPacket[columnCursor + 3] =
                       FBITS(widthRatio * (float)(sourceScaleX * (secondColumnClipRight - regionXF) - secondColumnBiasX));
                  blitPacket[columnCursor + 4] = FBITS((float)(invBufferHeightD * (sourceScaleY * (secondColumnClipTop - regionYF) -
                                                       scalingBufferYF)));
                  blitPacket[columnCursor + 7] = 0xc0033500;
                  blitPacket[columnCursor + 9] = FBITS((float)(secondColumnClipLeft + secondColumnClipRight) * halfF);
                  blitPacket[columnCursor + 10] = FBITS((float)(secondColumnClipTop + secondColumnClipBottom) * halfF);
                  blitPacket[columnCursor + 8] = 0x10031;
                  blitPacket[columnCursor + 0xb] = 0;
                  blitPacket[columnCursor + 6] =
                       (SInt32)((float)(secondColumnClipRight - secondColumnClipLeft) * heightRatio) << 0x10 |
                       (SInt32)((float)(secondColumnClipBottom - secondColumnClipTop) * heightRatio);
                }
                regionDataPtr = regionDataPtr + 2;
                regionsLeft = regionsLeft + -1;
                columnCursor = packetCursor;
              } while (regionsLeft != 0);
            }
          }
        }
        else {
          if (splitThreshold < bufferWidthF) {
            bufferWidthInt = (UInt32)bufferWidthF;
            halfWidthRaw = (SInt32)bufferWidthInt >> 1 & 0xfffffe00;
            halfWidthPlus2 = halfWidthRaw + 2;
            secondWidth = bufferWidthInt - halfWidthRaw;
            if ((blitPacket[0xa0] & 0x18) == 0) {
              fmtDC = FormatTableLookup_0x0004d2dc(srcFormatIndex * 0x1c);
              tileShift = 0;
            }
            else {
              fmtDC = FormatTableLookup_0x0004d2dc(srcFormatIndex * 0x1c);
              tileShift = -(fmtDC >> 8 & 3);
            }
            tileUnits = (SInt32)halfWidthRaw >> ((tileShift - (fmtDC >> 0xc & 7)) + 5 & 0x3f);
            texOffsetDelta = tileUnits << 5;
            if (((UInt32)blitPacket[0xa0] >> 2 & 1) != 0) {
              texOffsetDelta = (tileUnits << 0xc) >> 3;
            }
            widthRatio = FLOAT_0004c370;
            if (halfWidthPlus2 != 0) {
              widthRatio = (float)(SInt32)(bufferWidthInt) /
                      (float)(SInt32)(halfWidthPlus2);
            }
            heightRatio = FLOAT_0004c370;
            if (secondWidth != 0) {
              heightRatio = (float)(SInt32)(bufferWidthInt) /
                       (float)(SInt32)(secondWidth);
            }
            columnOffsetA = FLOAT_0004c3a0;
            columnOffsetB = FLOAT_0004c3a0;
            if (bufferWidthInt != 0) {
              bufferWidthFloat = (float)(SInt32)(bufferWidthInt);
              columnOffsetA = -((float)(SInt32)(halfWidthRaw) / bufferWidthFloat);
              columnOffsetB = -((float)((SInt32)(halfWidthRaw + halfWidthPlus2) * half) / bufferWidthFloat);
            }
            blitPacket[0xdb] = 0x1040;
            blitPacket[0xcf] = 0x1101;
            blitPacket[0xc0] = FBITS(widthRatio);
            blitPacket[0xd1] = 0x1111;
            blitPacket[0xc4] = 0x3f800000;
            blitPacket[0xd3] = 0x1121;
            blitPacket[200] = FBITS(heightRatio * columnOffsetA);
            blitPacket[0xc6] = FBITS(heightRatio);
            blitPacket[0xce] = FBITS(columnOffsetB);
            blitPacket[0xc2] = 0x3f800000;
            blitPacket[0xdc] = 0;
            blitPacket[0xbf] = 0x1095;
            blitPacket[0xc1] = 0x1095;
            blitPacket[0xc3] = 0x1095;
            blitPacket[0xc5] = 0x1095;
            blitPacket[199] = 0x1095;
            blitPacket[0xc9] = 0x1095;
            blitPacket[0xca] = 0;
            blitPacket[0xcb] = 0x1095;
            blitPacket[0xcc] = 0;
            blitPacket[0xd5] = 0x1131;
            blitPacket[0xd7] = 0x1141;
            blitPacket[0xbd] = 0x1094;
            blitPacket[0xd9] = 0x1151;
            blitPacket[0xbe] = 0x10000;
            blitPacket[0xcd] = 0x1095;
            blitPacket[0xd0] = blitPacket[0xa2];
            blitPacket[0xd2] = blitPacket[0xa4];
            packetCursor = 0xdd;
            blitPacket[0xd4] = blitPacket[0xa6];
            blitPacket[0xd6] = blitPacket[0xa8];
            blitPacket[0xd0] = blitPacket[0xa2] & 0xfffffff | 0x10000000;
            blitPacket[0xd8] = blitPacket[0xaa];
            blitPacket[0xda] = blitPacket[0xa0] + texOffsetDelta;
            blitPacket[0x3c] = 3;
            blitPacket[0xa6] = halfWidthRaw + 1 & 0x7ff | blitPacket[0xa6] & 0xfffff800;
            blitPacket[0xd4] = secondWidth - 1 & 0x7ff | blitPacket[0xd4] & 0xfffff800;
            blitPacket[0x42] = 0x7800;
            blitPacket[0x4c] = 0x1c490010;
            blitPacket[0x48] = 0x442220;
            blitPacket[0x4a] = 0xc00000;
            blitPacket[0x46] = 0x10100000;
            blitPacket[0x54] = 0x29a220;
            blitPacket[0x40] = 0;
            blitPacket[0x41] = 0x1095;
            blitPacket[0x43] = 0x1095;
            blitPacket[0x45] = 0x1095;
            blitPacket[0x47] = 0x1095;
            blitPacket[0x4e] = 0x3800;
            blitPacket[0x50] = 0x10140000;
            blitPacket[0x3f] = 0x1094;
            blitPacket[0x44] = 0x40000;
            blitPacket[0x49] = 0x1095;
            blitPacket[0x52] = 0x40000;
            blitPacket[0x56] = 0x810000;
            blitPacket[0x4b] = 0x1095;
            blitPacket[0x4d] = 0x1095;
            blitPacket[0x4f] = 0x1095;
            blitPacket[0x51] = 0x1095;
            blitPacket[0x53] = 0x1095;
            blitPacket[0x55] = 0x1095;
            blitPacket[0x58] = 0x20222020;
            blitPacket[0x5e] = 0xe401e401;
            blitPacket[0x6a] = 0xe402e402;
            blitPacket[0x72] = 0x78105;
            blitPacket[0x76] = 0x100800;
            blitPacket[0x57] = 0x1095;
            blitPacket[0x59] = 0x1095;
            blitPacket[0x5b] = 0x1095;
            blitPacket[0x5d] = 0x1095;
            blitPacket[0x5f] = 0x1095;
            blitPacket[0x60] = 0;
            blitPacket[0x61] = 0x1095;
            blitPacket[0x62] = 0;
            blitPacket[99] = 0x1095;
            blitPacket[100] = 0;
            blitPacket[0x65] = 0x1095;
            blitPacket[0x67] = 0x1095;
            blitPacket[0x69] = 0x1095;
            blitPacket[0x6b] = 0x1095;
            blitPacket[0x6c] = 0;
            blitPacket[0x6d] = 0x1095;
            blitPacket[0x5a] = 0x7c03;
            blitPacket[0x5c] = 0x2400000;
            blitPacket[0x66] = 0x7c07;
            blitPacket[0x68] = 0x2410000;
            blitPacket[0x6e] = 0;
            blitPacket[0x6f] = 0x1095;
            blitPacket[0x83] = 0x118d;
            blitPacket[0x85] = 0x118e;
            blitPacket[0x70] = 0;
            blitPacket[0x71] = 0x1095;
            blitPacket[0x73] = 0x1095;
            blitPacket[0x74] = 0x100800;
            blitPacket[0x75] = 0x1095;
            blitPacket[0x77] = 0x1095;
            blitPacket[0x78] = 0x444221;
            blitPacket[0x7a] = 0x70d006;
            blitPacket[0x7c] = 0x1836c008;
            blitPacket[0x79] = 0x1095;
            blitPacket[0x7b] = 0x1095;
            blitPacket[0x84] = 0x40000;
            blitPacket[0x86] = 0;
            blitPacket[0x88] = 0x40000;
            blitPacket[0x87] = 0x118c;
            blitPacket[0x82] = 2;
          }
          heightRatio = FLOAT_0004c380;
          widthRatio = FLOAT_0004c37c;
          if (regionCount != 0) {
            regionRightF = (regionXF + regionWidthF);
            regionBottomF = (regionYF + regionHeightF);
            rectCursor = packetCursor;
            regionsLeft = regionCount;
            do {
              rectLeftF = (SInt32)((SInt32)M<SInt16>(regionDataPtr));
              edgeDelta = (float)(regionXF - rectLeftF);
              clipLeft = regionXF;
              if (edgeDelta < 0.0) {
                clipLeft = rectLeftF;
              }
              if (-edgeDelta < 0.0) {
                clipLeft = regionXF;
              }
              rectTopF = (SInt32)((SInt32)(SInt16)*regionDataPtr);
              edgeDelta = (float)(regionYF - rectTopF);
              clipTop = regionYF;
              if (edgeDelta < 0.0) {
                clipTop = rectTopF;
              }
              if (-edgeDelta < 0.0) {
                clipTop = regionYF;
              }
              rectRightF = (SInt32)((SInt32)M<SInt16>(regionDataPtr) + (SInt32)M<SInt16>(regionDataPtr + 1));
              edgeDelta = (float)(rectRightF - regionRightF);
              clipRight = regionRightF;
              if (edgeDelta < 0.0) {
                clipRight = rectRightF;
              }
              if (-edgeDelta < 0.0) {
                clipRight = regionRightF;
              }
              rectBottomF = (SInt32)((SInt32)(SInt16)*regionDataPtr + (SInt32)M<SInt16>((SInt32)regionDataPtr + 6));
              edgeDelta = (float)(rectBottomF - regionBottomF);
              clipBottom = regionBottomF;
              if (edgeDelta < 0.0) {
                clipBottom = rectBottomF;
              }
              if (-edgeDelta < 0.0) {
                clipBottom = regionBottomF;
              }
              packetCursor = rectCursor;
              if ((FLOAT_0004c370 < (float)(clipRight - clipLeft)) &&
                 (FLOAT_0004c370 < (float)(clipBottom - clipTop))) {
                blitPacket[rectCursor] = 0x31080;
                blitPacket[rectCursor + 5] = 0x1087;
                packetCursor = rectCursor * 4 + 0x30 >> 2;
                blitPacket[rectCursor + 1] = FBITS((float)(invBufferWidthD * (sourceScaleX * (clipLeft - regionXF) -
                                                     scalingBufferXF)));
                blitPacket[rectCursor + 2] = FBITS((float)(invBufferHeightD * (sourceScaleY * (clipBottom - regionYF) -
                                                     scalingBufferYF)));
                blitPacket[rectCursor + 3] = FBITS((float)(invBufferWidthD * (sourceScaleX * (clipRight - regionXF) -
                                                     scalingBufferXF)));
                blitPacket[rectCursor + 4] = FBITS((float)(invBufferHeightD * (sourceScaleY * (clipTop - regionYF) -
                                                     scalingBufferYF)));
                blitPacket[rectCursor + 7] = 0xc0033500;
                blitPacket[rectCursor + 9] = FBITS((float)(clipLeft + clipRight) * heightRatio);
                blitPacket[rectCursor + 10] = FBITS((float)(clipTop + clipBottom) * heightRatio);
                blitPacket[rectCursor + 8] = 0x10031;
                blitPacket[rectCursor + 0xb] = 0;
                blitPacket[rectCursor + 6] =
                     (SInt32)((float)(clipRight - clipLeft) * widthRatio) << 0x10 |
                     (SInt32)((float)(clipBottom - clipTop) * widthRatio);
              }
              regionDataPtr = regionDataPtr + 2;
              regionsLeft = regionsLeft + -1;
              rectCursor = packetCursor;
            } while (regionsLeft != 0);
          }
        }
        blitPacket[packetCursor] = 0x1393;
        blitPacket[packetCursor + 1] = 10;
        Vol(panelRec->entries[0].rectWordIndex) = (SInt32)blitPacket + (0x2c8 - (SInt32)batchWords) >> 2;
        batchIndex = (SInt32)blitPacket + ((packetCursor + 2) * 4 - (SInt32)batchWords) >> 2;
      }
      panelRec = panelRec + 1;
      panel = panel + 1;
      M<SInt32>((SInt32)Vol(batchEntry->header) + 0xc) = regionCount;
      panelSlotCursor = panelSlotCursor + 8;
      M<SInt32>((SInt32)Vol(batchEntry->header) + 0x14) = batchIndex;
      M<UInt32>((SInt32)Vol(batchEntry->header) + 0x1c) = M<UInt32>((SInt32)Vol(batchEntry->header) + 0x1c) | 1;
      M<UInt16>(self + kATIR500Surface_swapBatchBuilt) = 1;
      accelBase = M<SInt32>(self + kIOATIR500Surface_accelerator);
    } while (panel < M<UInt32>(accelBase + kIOATIR500Accelerator_displayCount));
  }
  return;
}
