/*
 * ATIRadeonX1000_PclCopyPix.cpp
 *
 * RESOLVED (ledger pass): pcl_CopyPix (real addr 0x21e30, 5260 bytes) - builds the R500 3D-blit command stream for a
 * software "copy pixels" request described by a pcl_ParamsR500_t (source/destination surface descriptors, rectangles,
 * flags): copies the r500 3D-blit state packet into `cmd`, patches in the destination colour buffer (address, pitch,
 * size, format) and source texture (address, size, pitch, format) words, emits the viewport/scissor floats and one or
 * more textured quads (large or scaled copies are split into strips), and returns the pointer one past the last word
 * written. flipHorizontally / flipVertically mirror the copy about the X / Y axis of the rectangle (the 180-degree case passes both).
 *
 * Transcribed mechanically from the decompile (Tools/ghidra2cpp.py, Headers/GhidraCompat.h; conventions as in
 * ATIR500Surface_BuildSwap.cpp). pcl_ParamsR500_t's layout was never recovered as a struct: the body reads it at raw
 * offsets through the byte pointer `params`.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

struct pcl_ParamsR500_t;
extern "C" const r500_3d_blit_state_packet_struct g_r500_3d_blit_state_packet;

/* PERF NOTE (NOT APPLIED). Estimated cycles rebuilt/stock 1.10-1.14. Cause: 79 loads against 49 in stock, because the volatile reads of the parameter block
 * are repeated where the shipped code reads each field once; 7 rlwimi (register image built by bitfield insert) that gcc 4.0.1 does not form from the
 * `a & mask | b & mask` form used here; 71 more nops over the sampled seeds. Closing it: read each pcl_ParamsR500_t field into a local once (keeps the names),
 * and model the blit-state words as bitfield structs with the real register layout (needs the layouts; not a mechanical rewrite). */
/* real addr 0x21e30 */
UInt32 *pcl_CopyPix(UInt32 *cmd, pcl_ParamsR500_t *params, bool flipHorizontally, bool flipVertically) {
    UInt8 *paramsBytes = reinterpret_cast<UInt8 *>(params);

  bool flipX;
  float scaledWidthB;
  float srcYAtDstTop;
  float dstYMax;
  float dstYMin;
  SInt32 leftUnits;
  UInt32 firstRow;
  UInt32 *quadPacket;
  UInt32 firstColumn;
  SInt32 packetIndex;
  SInt32 endIndex;
  UInt32 columnWidthLeft;
  UInt32 chunkLeft;
  UInt32 *chunkPacket;
  UInt32 chunkH;
  UInt32 chunkTop;
  UInt32 rowIndex;
  SInt16 *rect;
  UInt32 columnsLeft;
  float ySecondDC;
  float invScaleY;
  UInt32 columnChunks;
  UInt32 rowChunks;
  UInt32 chunkCount;
  UInt32 copyWidth;
  UInt32 copyHeight;
  UInt32 texturePitchWord;
  UInt32 textureOffsetWord;
  float dstX;
  float dstY;
  float dstRight;
  float dstBottom;
  float srcPerDstX;
  float srcPerDstY;
  float srcOffsetX;
  float srcOffsetY;
  float srcRectX;
  float srcRectY;
  float srcMinX;
  float srcMaxX;
  float srcMaxY;
  float srcMinY;
  float dstPerSrcX;
  float dstPerSrcY;
  float chunkTopF;
  float invChunkWidth;
  float invChunkHeight;
  float scaledHeight;
  float scaledWidth;
  float centerY;
  float centerX;
  float invCopyWidth;
  float invCopyHeight;
  float scaleX;
  float rectRightD;
  float scaleY;
  float ySecondD1;
  float ySecondD2;
  float rectXD;
  float invScaleX;
  float chunkLeftD;
  float yFirstD1;
  float yFirstD2;
  float yFirstDC;
  float vertexScale;
  float halfWidthPlus2F;
  float rectRightF;
  float centerYB1;
  float invWidth2;
  float texRight2;
  float chunkMaxX;
  float scaledHeightB;
  float dstWidth;
  float srcXAtLeft;
  float invHalfWidth;
  float texLeft;
  float secondHalfWidthF;
  float leftEdgeF;
  float centerXB2;
  float rectX;
  float dstXB;
  float centerXB1;
  float rectY;
  float dstHeight;
  float texRight1;
  float texLeft2;
  float rectW;
  float chunkMinX;
  float dstYB;
  float centerYB2;
  float rectH;
  float chunkMinY;
  float chunkLeftF;
  float dstHeightB;
  float halfConst;
  float chunkMaxY;
  float dstXMax;
  float clampTmpMinY;
  float dstXFirst;
  float clampedMaxY;
  float srcXAtDstMin;
  float clampTmpMinX;
  float srcYAtDstMin;
  float clampTmpMaxX;
  float dstYFirst;
  float dstXMin;
  UInt32 tilingBits;
  UInt32 halfWidthAligned;
  UInt32 yBottomB2;
  UInt32 stateWordA2;
  UInt32 secondHalfWidth;
  UInt32 leftMax;
  UInt32 yTopB2;
  UInt32 columnCandidate;
  UInt32 alignedHeightLimit;
  UInt32 columnBase;
  UInt32 rowBase;
  UInt32 halfWidthPlus2;
  UInt32 ySecondB1;
  UInt32 rectX2;
  UInt32 alignedWidthLimit;
  UInt32 rowCandidate;
  UInt32 widthMinusOne;
  UInt32 srcMaxXInt;
  UInt32 macroTileBit;
  UInt32 rightLimit;
  UInt32 yFirstB1;
  UInt32 columnEnd;
  UInt32 heightMinusOne;
  UInt32 srcMaxYInt;
  UInt32 rectX3;
  UInt32 rowEnd;
  UInt32 rowsLeft;
  UInt32 chunkTopRow;
  UInt32 chunkWidthWord;
  UInt32 stateWordA0;
  UInt32 formatInfo;
  UInt32 bppShift;
  UInt32 stateWordA6;
  UInt32 rectRight;
  UInt32 microTiling;
  UInt32 formatInfoB;
  UInt32 stateWordA6B;
  SInt32 tileBias;
  SInt32 columnByteOffset;
  SInt32 tileBiasB;
  SInt32 leftByteOffset;
  SInt32 nextPacketIndex;
  SInt32 columnIndex;
  SInt32 formatTableOffset;
  SInt32 flipV;
  SInt32 rowOffset;
  SInt32 quadWordCount;
  UInt32 chunkW;
  UInt32 chunkLeftBiased;
  
  flipV = ((UInt32)flipVertically);
  invScaleX = FLOAT_0004c370;
  scaleX = (double)M<float>(paramsBytes + 0x6c);
  rect = M<SInt16 *>(paramsBytes + 0x50);
  scaleY = (double)M<float>(paramsBytes + 0x70);
  if (scaleX != invScaleX) {
    invScaleX = (FLOAT_0004c374 / scaleX);
  }
  invScaleY = FLOAT_0004c370;
  if (scaleY != invScaleY) {
    invScaleY = (FLOAT_0004c374 / scaleY);
  }
  GCopy(cmd,(&g_r500_3d_blit_state_packet),0x2f4);
  stateWordA2 = cmd[0xa2];
  packetIndex = 0xbd;
  cmd[0xa0] = M<UInt32>(paramsBytes);
  cmd[0xa6] = M<UInt32>(paramsBytes + 4);
  cmd[0xa8] = M<UInt32>(paramsBytes + 8);
  cmd[0xaa] = M<UInt32>(paramsBytes + 0xc);
  cmd[0x9c] = M<UInt32>(paramsBytes + 0x14);
  cmd[0x9a] = M<UInt32>(paramsBytes + 0x18);
  cmd[0x8a] = M<UInt32>(paramsBytes + 0x1c);
  cmd[0xb2] = M<UInt32>(paramsBytes + 0x20);
  cmd[0xb3] = M<UInt32>(paramsBytes + 0x24);
  cmd[0xb] = M<UInt32>(paramsBytes + 0x28);
  tilingBits = M<UInt32>(paramsBytes + 0x10);
  cmd[0xa2] = tilingBits & 0x600 | stateWordA2 & 0xfffff9ff;
  cmd[0xa2] = M<UInt32>(paramsBytes + 0x10) & 0x1800 | tilingBits & 0x600 | stateWordA2 & 0xffffe1ff;
  if (M<SInt32>(paramsBytes + 0x88) != 0) {
    cmd[0x1e] = cmd[0x1e] & 0xfffffffc | 2;
  }
  vertexScale = FLOAT_0004c37c;
  invHalfWidth = FLOAT_0004c370;
  if ((FLOAT_0004c378 < scaleX) || (FLOAT_0004c378 < scaleY)) {
    flipX = ((UInt32)flipHorizontally) != 0;
    if ((flipX) || (scaleX <= FLOAT_0004c378)) {
      dstWidth = M<float>(paramsBytes + 0x5c);
      dstX = M<float>(paramsBytes + 0x54);
      dstY = M<float>(paramsBytes + 0x58);
      dstHeight = M<float>(paramsBytes + 0x60);
      dstRight = dstX + dstWidth;
      dstBottom = dstY + dstHeight;
      srcPerDstX = FLOAT_0004c370;
      if (dstWidth != FLOAT_0004c370) {
        srcPerDstX = (float)(SInt32)((SInt32)rect[2])
                / dstWidth;
      }
      srcRectX = (float)(SInt32)((SInt32)*rect);
      srcOffsetX = -(srcPerDstX * dstX - srcRectX);
      srcPerDstY = FLOAT_0004c370;
      if (dstHeight != FLOAT_0004c370) {
        srcPerDstY = (float)((double)(SInt32)((SInt32)rect[3])
                        ) / dstHeight;
      }
      srcRectY = (float)(SInt32)((SInt32)rect[1]);
      srcOffsetY = -(dstY * srcPerDstY - srcRectY);
      if (flipV != 0) {
        srcPerDstY = -srcPerDstY;
        srcOffsetY = (float)(SInt32)((SInt32)rect[1] + (SInt32)rect[3]) - (srcOffsetY - srcRectY);
      }
      if (flipX) {
        srcPerDstX = -srcPerDstX;
        srcOffsetX = (float)(SInt32)((SInt32)*rect + (SInt32)rect[2]) - (srcOffsetX - srcRectX);
      }
      copyWidth = (SInt32)scaleX & 0xffff;
      copyHeight = (SInt32)scaleY & 0xffff;
      if ((copyWidth < 0x1001) && (copyHeight < 0x1001)) {
        firstRow = 0;
        firstColumn = 0;
        rowChunks = 0;
        columnChunks = 0;
        chunkCount = 0;
        srcMinX = FLOAT_0004c370;
        srcMaxX = FLOAT_0004c370;
        srcMaxY = FLOAT_0004c370;
        srcMinY = FLOAT_0004c370;
      }
      else {
        srcYAtDstTop = srcPerDstY * dstY + srcOffsetY;
        srcMaxY = srcPerDstY * dstBottom + srcOffsetY;
        srcXAtLeft = dstX * srcPerDstX + srcOffsetX;
        srcMaxX = dstRight * srcPerDstX + srcOffsetX;
        srcMinY = srcYAtDstTop;
        if (srcMaxY < srcYAtDstTop) {
          srcMinY = srcMaxY;
          srcMaxY = srcYAtDstTop;
        }
        srcMinX = srcXAtLeft;
        if (srcMaxX < srcXAtLeft) {
          srcMinX = srcMaxX;
          srcMaxX = srcXAtLeft;
        }
        alignedWidthLimit = (SInt32)scaleX & 0xfe00;
        columnCandidate = (SInt32)srcMinX - 1;
        columnCandidate = (((SInt32)columnCandidate >> 9) + (UInt32)((SInt32)columnCandidate < 0 && (columnCandidate & 0x1ff) != 0)) * 0x200;
        firstColumn = 0;
        if ((-1 < (SInt32)columnCandidate) && (firstColumn = alignedWidthLimit, (SInt32)columnCandidate <= (SInt32)alignedWidthLimit)) {
          firstColumn = columnCandidate & 0xfe00;
        }
        alignedHeightLimit = 0x40;
        if ((0x40 < copyHeight) && (alignedHeightLimit = (SInt32)scaleY & 0xffc0, (SInt32)(copyHeight - alignedHeightLimit) < 0x40)) {
          alignedHeightLimit = alignedHeightLimit - 0x40;
        }
        firstRow = 0;
        rowCandidate = (SInt32)srcMinY - 1;
        rowCandidate = (((SInt32)rowCandidate >> 6) + (UInt32)((SInt32)rowCandidate < 0 && (rowCandidate & 0x3f) != 0)) * 0x40;
        if ((-1 < (SInt32)rowCandidate) && (firstRow = alignedHeightLimit & 0xffff, (SInt32)rowCandidate <= (SInt32)alignedHeightLimit)) {
          firstRow = rowCandidate & 0xffc0;
        }
        columnBase = 0x200;
        if (0x1ff < firstColumn) {
          columnBase = firstColumn;
        }
        widthMinusOne = copyWidth - 1;
        columnEnd = (((SInt32)widthMinusOne >> 9) + (UInt32)((SInt32)widthMinusOne < 0 && (widthMinusOne & 0x1ff) != 0)) * 0x200;
        srcMaxXInt = (UInt32)srcMaxX;
        if ((FLOAT_0004c370 < srcMaxX) &&
           ((float)(SInt32)(srcMaxXInt) < srcMaxX)) {
          srcMaxXInt = srcMaxXInt + 1;
        }
        if ((SInt32)srcMaxXInt <= (SInt32)columnEnd) {
          columnEnd = srcMaxXInt;
        }
        columnChunks = 1;
        if ((SInt32)columnBase < (SInt32)columnEnd) {
          columnChunks = (SInt32)((columnEnd - columnBase) + 0xbff) / 0xc00 & 0xff;
        }
        rowBase = 0x40;
        if (0x3f < firstRow) {
          rowBase = firstRow;
        }
        heightMinusOne = copyHeight - 1;
        rowEnd = (((SInt32)heightMinusOne >> 6) + (UInt32)((SInt32)heightMinusOne < 0 && (heightMinusOne & 0x3f) != 0)) * 0x40;
        srcMaxYInt = (UInt32)srcMaxY;
        if ((FLOAT_0004c370 < srcMaxY) &&
           ((float)(SInt32)(srcMaxYInt) < srcMaxY)) {
          srcMaxYInt = srcMaxYInt + 1;
        }
        if ((SInt32)srcMaxYInt <= (SInt32)rowEnd) {
          rowEnd = srcMaxYInt;
        }
        rowChunks = 1;
        if ((SInt32)rowBase < (SInt32)rowEnd) {
          rowChunks = (SInt32)((rowEnd - rowBase) + 0xf7f) / 0xf80 & 0xff;
        }
        chunkCount = rowChunks * columnChunks & 0xff;
      }
      quadPacket = cmd + 0xbd;
      if (chunkCount != 0) {
        dstPerSrcX = FLOAT_0004c370;
        if (srcPerDstX != FLOAT_0004c370) {
          dstPerSrcX = FLOAT_0004c374 / srcPerDstX;
        }
        dstPerSrcY = FLOAT_0004c370;
        if (srcPerDstY != FLOAT_0004c370) {
          dstPerSrcY = FLOAT_0004c374 / srcPerDstY;
        }
        if (rowChunks != 0) {
          rowsLeft = copyHeight - firstRow;
          rowIndex = 0;
          rowOffset = 0;
          chunkTopRow = firstRow;
          chunkPacket = quadPacket;
          do {
            if (columnChunks != 0) {
              chunkTop = firstRow + rowOffset;
              columnWidthLeft = copyWidth - firstColumn;
              columnIndex = 0;
              chunkTopF = (float)(SInt32)(chunkTop);
              chunkLeft = firstColumn;
              columnsLeft = columnChunks;
              do {
                *chunkPacket = chunkLeft;
                chunkPacket[1] = chunkTopRow;
                chunkW = columnWidthLeft;
                if ((SInt32)(chunkLeft + 0x1000) <= (SInt32)copyWidth) {
                  chunkW = 0x1000;
                }
                chunkH = rowsLeft;
                if ((SInt32)(chunkTop + 0x1000) <= (SInt32)copyHeight) {
                  chunkH = 0x1000;
                }
                chunkPacket[2] = chunkW;
                chunkPacket[3] = chunkH;
                chunkMinX = srcMinX;
                if (columnIndex != 0) {
                  chunkMinX = (float)(SInt32)(chunkLeft + 0x200);
                }
                chunkMinY = srcMinY;
                if (rowIndex != 0) {
                  chunkMinY = (float)(SInt32)(chunkTop + 0x40);
                }
                chunkMaxX = srcMaxX;
                if (columnIndex != columnChunks - 1) {
                  chunkMaxX = (float)(SInt32)(chunkLeft + 0xe00);
                }
                chunkMaxY = srcMaxY;
                if (rowIndex != rowChunks - 1) {
                  chunkMaxY = (float)(SInt32)(chunkTop + 0xfc0);
                }
                clampTmpMinY = srcMinY;
                if (srcMinY - chunkMinY < 0.0) {
                  clampTmpMinY = chunkMinY;
                }
                clampedMaxY = chunkMaxY;
                if (srcMaxY - chunkMaxY < 0.0) {
                  clampedMaxY = srcMaxY;
                }
                clampTmpMinX = srcMinX;
                if (srcMinX - chunkMinX < 0.0) {
                  clampTmpMinX = chunkMinX;
                }
                clampTmpMaxX = srcMaxX;
                if (chunkMaxX - srcMaxX < 0.0) {
                  clampTmpMaxX = chunkMaxX;
                }
                if (-(srcMinY - chunkMinY) < 0.0) {
                  chunkMinY = clampTmpMinY;
                }
                if (-(srcMaxY - chunkMaxY) < 0.0) {
                  clampedMaxY = chunkMaxY;
                }
                if (-(srcMinX - chunkMinX) < 0.0) {
                  chunkMinX = clampTmpMinX;
                }
                if (-(chunkMaxX - srcMaxX) < 0.0) {
                  chunkMaxX = clampTmpMaxX;
                }
                dstYFirst = dstPerSrcY * chunkMinY + dstPerSrcY * -srcOffsetY;
                dstYMax = dstPerSrcY * clampedMaxY + dstPerSrcY * -srcOffsetY;
                dstXFirst = dstPerSrcX * chunkMinX + dstPerSrcX * -srcOffsetX;
                dstXMax = dstPerSrcX * chunkMaxX + dstPerSrcX * -srcOffsetX;
                srcYAtDstMin = clampedMaxY;
                dstYMin = dstYFirst;
                if (dstYMax < dstYFirst) {
                  srcYAtDstMin = chunkMinY;
                  chunkMinY = clampedMaxY;
                  dstYMin = dstYMax;
                  dstYMax = dstYFirst;
                }
                srcXAtDstMin = chunkMaxX;
                dstXMin = dstXFirst;
                if (dstXMax < dstXFirst) {
                  srcXAtDstMin = chunkMinX;
                  chunkMinX = chunkMaxX;
                  dstXMin = dstXMax;
                  dstXMax = dstXFirst;
                }
                invChunkWidth = FLOAT_0004c370;
                if (chunkW != 0) {
                  invChunkWidth = FLOAT_0004c374 /
                          (float)((double)(SInt32)(chunkW)
                                 );
                }
                invChunkHeight = FLOAT_0004c370;
                if (chunkH != 0) {
                  invChunkHeight = FLOAT_0004c374 /
                           (float)(SInt32)(chunkH);
                }
                chunkLeftBiased = chunkLeft ^ 0x80000000;
                columnIndex = columnIndex + 1;
                chunkLeft = chunkLeft + 0xc00;
                columnWidthLeft = columnWidthLeft - 0xc00;
                scaledHeight = (dstYMax - dstYMin) * FLOAT_0004c37c;
                scaledWidth = (dstXMax - dstXMin) * FLOAT_0004c37c;
                centerY = (dstYMin + dstYMax) * FLOAT_0004c380;
                centerX = (dstXMin + dstXMax) * FLOAT_0004c380;
                chunkLeftD = (double)(SInt32)(chunkLeftBiased ^ 0x80000000);
                chunkPacket[4] = 0x31080;
                chunkPacket[6] = FBITS((invChunkHeight * (srcYAtDstMin - chunkTopF)));
                chunkPacket[8] = FBITS((invChunkHeight * (chunkMinY - chunkTopF)));
                chunkPacket[0xb] = 0xc0033500;
                chunkPacket[0xc] = 0x10031;
                chunkPacket[0xd] = FBITS(centerX);
                chunkLeftF = (float)chunkLeftD;
                chunkPacket[0xe] = FBITS(centerY);
                chunkPacket[9] = 0x1087;
                chunkPacket[10] = (SInt32)scaledWidth << 0x10 | (SInt32)scaledHeight;
                chunkPacket[0xf] = 0;
                chunkPacket[7] = FBITS((invChunkWidth * (srcXAtDstMin - chunkLeftF)));
                chunkPacket[5] = FBITS((invChunkWidth * (chunkMinX - chunkLeftF)));
                chunkPacket = chunkPacket + 0x10;
                columnsLeft = columnsLeft - 1;
              } while (columnsLeft != 0);
            }
            rowIndex = rowIndex + 1;
            rowOffset = rowOffset + 0xf80;
            rowsLeft = rowsLeft - 0xf80;
            chunkTopRow = chunkTopRow + 0xf80;
          } while (rowIndex != rowChunks);
        }
      }
      else {
        invCopyWidth = FLOAT_0004c370;
        if (copyWidth != 0) {
          invCopyWidth = FLOAT_0004c374 /
                  (float)(SInt32)(copyWidth);
        }
        invCopyHeight = FLOAT_0004c370;
        if (copyHeight != 0) {
          invCopyHeight = FLOAT_0004c374 /
                  (float)(SInt32)(copyHeight);
        }
        scaledWidth = (dstRight - dstX) * FLOAT_0004c37c;
        scaledHeight = (dstBottom - dstY) * FLOAT_0004c37c;
        centerY = (dstY + dstBottom) * FLOAT_0004c380;
        centerX = (dstX + dstRight) * FLOAT_0004c380;
        *quadPacket = 0x31080;
        cmd[0xbe] = FBITS((invCopyWidth * (dstX * srcPerDstX + srcOffsetX)));
        cmd[0xbf] = FBITS((invCopyHeight * (srcPerDstY * dstBottom + srcOffsetY)));
        cmd[0xc0] = FBITS((invCopyWidth * (dstRight * srcPerDstX + srcOffsetX)));
        cmd[0xc1] = FBITS((invCopyHeight * (srcPerDstY * dstY + srcOffsetY)));
        cmd[0xc4] = 0xc0033500;
        cmd[0xc5] = 0x10031;
        cmd[0xc6] = FBITS(centerX);
        cmd[199] = FBITS(centerY);
        cmd[0xc2] = 0x1087;
        cmd[0xc3] = (SInt32)scaledWidth << 0x10 | (SInt32)scaledHeight;
        cmd[200] = 0;
      }
      texturePitchWord = cmd[0xaa];
      textureOffsetWord = cmd[0xa0];
      macroTileBit = textureOffsetWord >> 2 & 1;
      microTiling = textureOffsetWord >> 3 & 3;
      if (chunkCount != 0) {
        if (chunkCount == 0) {
          quadWordCount = 0;
        }
        else {
          formatTableOffset = (M<UInt32>(paramsBytes + 0x2c) & 0xff) * 0x1c;
          quadWordCount = 0;
          chunkPacket = quadPacket;
          do {
            if (microTiling == 0) {
              formatInfo = FormatTableLookup_0x0004d2dc(formatTableOffset);
              tileBias = 0;
            }
            else {
              formatInfo = FormatTableLookup_0x0004d2dc(formatTableOffset);
              tileBias = -(formatInfo >> 8 & 3);
            }
            bppShift = formatInfo >> 0xc & 7;
            columnByteOffset = (SInt32)*chunkPacket >> ((tileBias - bppShift) + 5 & 0x3f);
            if (macroTileBit == 0) {
              columnByteOffset = columnByteOffset << 5;
            }
            else {
              columnByteOffset = (columnByteOffset << 0xc) >> 3;
            }
            quadWordCount = quadWordCount + 1;
            *chunkPacket = 0x1150;
            chunkPacket[1] = (textureOffsetWord & 0xffffffe0) +
                         columnByteOffset + (((texturePitchWord & 0x3fff) + 1) * chunkPacket[1] << bppShift) & 0xffffffe0 |
                         microTiling << 3 | macroTileBit << 2;
            chunkWidthWord = chunkPacket[2];
            stateWordA6 = cmd[0xa6];
            chunkPacket[2] = 0x1120;
            chunkPacket[3] = (chunkPacket[3] - 1) * 0x800 & 0x3ff800 |
                         chunkWidthWord - 1 & 0x7ff | stateWordA6 & 0xffc00000;
            chunkPacket = chunkPacket + 0x10;
            chunkCount = chunkCount - 1;
          } while (chunkCount != 0);
          quadWordCount = quadWordCount * 0x10;
        }
        quadPacket = quadPacket + quadWordCount;
      }
      else {
        quadPacket = cmd + 0xc9;
      }
      endIndex = (SInt32)quadPacket - (SInt32)cmd >> 2;
    }
    else {
      stateWordA0 = cmd[0xa0];
      halfWidthAligned = (SInt32)scaleX >> 1 & 0xfffffe00;
      secondHalfWidth = (SInt32)scaleX - halfWidthAligned;
      halfWidthPlus2 = halfWidthAligned + 2;
      if ((stateWordA0 & 0x18) == 0) {
        formatInfoB = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)paramsBytes[0x2f] * 0x1c);
        tileBiasB = 0;
      }
      else {
        formatInfoB = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)paramsBytes[0x2f] * 0x1c);
        tileBiasB = -(formatInfoB >> 8 & 3);
      }
      leftUnits = (SInt32)halfWidthAligned >> ((tileBiasB - (formatInfoB >> 0xc & 7)) + 5 & 0x3f);
      leftByteOffset = leftUnits << 5;
      if ((stateWordA0 >> 2 & 1) != 0) {
        leftByteOffset = (leftUnits << 0xc) >> 3;
      }
      stateWordA6B = halfWidthAligned + 1 & 0x7ff | cmd[0xa6] & 0xfffff800;
      cmd[0xa6] = stateWordA6B;
      halfWidthPlus2F = (float)(SInt32)(halfWidthPlus2);
      if (halfWidthPlus2F != invHalfWidth) {
        invHalfWidth = FLOAT_0004c374 / halfWidthPlus2F;
      }
      rectX3 = (UInt32)*rect;
      rectRight = rectX3 + (SInt32)rect[2];
      rightLimit = halfWidthPlus2;
      if ((SInt32)rectRight < (SInt32)halfWidthPlus2) {
        rightLimit = rectRight;
      }
      if ((SInt32)halfWidthPlus2 < (SInt32)rectRight) {
        dstXB = M<float>(paramsBytes + 0x54);
        rectRightF = (float)(SInt32)(halfWidthPlus2 - rectX3)
        ;
      }
      else {
        dstXB = M<float>(paramsBytes + 0x54);
        rectRightF = dstXB + M<float>(paramsBytes + 0x5c);
      }
      texRight1 = invHalfWidth * (float)(SInt32)(rightLimit);
      texLeft = invHalfWidth * (float)(SInt32)(rectX3);
      if (flipV == 0) {
        yFirstB1 = (UInt32)rect[1];
        ySecondB1 = yFirstB1 + (SInt32)rect[3];
      }
      else {
        ySecondB1 = (UInt32)rect[1];
        yFirstB1 = ySecondB1 + (SInt32)rect[3];
      }
      yFirstD1 = (double)(SInt32)(yFirstB1);
      ySecondD1 = (double)(SInt32)(ySecondB1);
      dstYB = M<float>(paramsBytes + 0x58);
      dstHeightB = M<float>(paramsBytes + 0x60);
      if (texLeft < texRight1) {
        scaledHeightB = ((dstYB + dstHeightB) - dstYB) * FLOAT_0004c37c;
        scaledWidthB = (rectRightF - dstXB) * FLOAT_0004c37c;
        centerXB1 = (rectRightF + dstXB) * FLOAT_0004c380;
        centerYB1 = (dstYB + dstYB + dstHeightB) * FLOAT_0004c380;
        cmd[0xbd] = 0x31080;
        cmd[0xbe] = FBITS(texLeft);
        cmd[0xc2] = 0x1087;
        cmd[0xbf] = FBITS((float)(invScaleY * ySecondD1));
        cmd[0xc0] = FBITS(texRight1);
        cmd[0xc1] = FBITS((float)(invScaleY * yFirstD1));
        cmd[0xc4] = 0xc0033500;
        cmd[0xc5] = 0x10031;
        cmd[0xc6] = FBITS(centerXB1);
        cmd[199] = FBITS(centerYB1);
        cmd[200] = 0;
        cmd[0xc3] = (SInt32)scaledWidthB << 0x10 | (SInt32)scaledHeightB;
        packetIndex = 0xc9;
        dstXB = M<float>(paramsBytes + 0x54);
        dstYB = M<float>(paramsBytes + 0x58);
        dstHeightB = M<float>(paramsBytes + 0x60);
        stateWordA0 = cmd[0xa0];
        stateWordA6B = cmd[0xa6];
      }
      cmd[packetIndex] = 0x1150;
      cmd[packetIndex + 1] = stateWordA0 + leftByteOffset;
      cmd[packetIndex + 2] = 0x1120;
      nextPacketIndex = packetIndex + 4;
      cmd[packetIndex + 3] = secondHalfWidth - 1 & 0x7ff | stateWordA6B & 0xfffff800;
      secondHalfWidthF = (float)(SInt32)(secondHalfWidth);
      invWidth2 = FLOAT_0004c370;
      if (secondHalfWidthF != FLOAT_0004c370) {
        invWidth2 = FLOAT_0004c374 / secondHalfWidthF;
      }
      rectX2 = (UInt32)*rect;
      leftMax = halfWidthAligned;
      if ((SInt32)rectX2 > (SInt32)halfWidthAligned) {
        leftMax = rectX2;
      }
      leftEdgeF = dstXB;
      if ((SInt32)rectX2 <= (SInt32)halfWidthAligned) {
        leftEdgeF = (float)(SInt32)(halfWidthAligned - rectX2)
        ;
      }
      texLeft2 = invWidth2 * ((float)(SInt32)(leftMax) -
                      (float)(SInt32)(halfWidthAligned));
      texRight2 = invWidth2 * (float)(SInt32)((rectX2 + (SInt32)rect[2]) - halfWidthAligned);
      if (flipV == 0) {
        yTopB2 = (UInt32)rect[1];
        yBottomB2 = yTopB2 + (SInt32)rect[3];
      }
      else {
        yBottomB2 = (UInt32)rect[1];
        yTopB2 = yBottomB2 + (SInt32)rect[3];
      }
      yFirstD2 = (double)(SInt32)(yTopB2);
      ySecondD2 = (double)(SInt32)(yBottomB2);
      endIndex = nextPacketIndex;
      if (texLeft2 < texRight2) {
        scaledWidthB = ((dstXB + M<float>(paramsBytes + 0x5c)) - leftEdgeF) * FLOAT_0004c37c;
        scaledHeightB = ((dstYB + dstHeightB) - dstYB) * FLOAT_0004c37c;
        endIndex = nextPacketIndex * 4 + 0x30 >> 2;
        centerYB2 = (dstYB + dstYB + dstHeightB) * FLOAT_0004c380;
        centerXB2 = (leftEdgeF + dstXB + M<float>(paramsBytes + 0x5c)) * FLOAT_0004c380;
        cmd[nextPacketIndex] = 0x31080;
        cmd[packetIndex + 5] = FBITS(texLeft2);
        cmd[packetIndex + 6] = FBITS((float)(invScaleY * ySecondD2));
        cmd[packetIndex + 7] = FBITS(texRight2);
        cmd[packetIndex + 9] = 0x1087;
        cmd[packetIndex + 8] = FBITS((float)(invScaleY * yFirstD2));
        cmd[packetIndex + 0xb] = 0xc0033500;
        cmd[packetIndex + 0xc] = 0x10031;
        cmd[packetIndex + 0xd] = FBITS(centerXB2);
        cmd[packetIndex + 0xe] = FBITS(centerYB2);
        cmd[packetIndex + 0xf] = 0;
        cmd[packetIndex + 10] = (SInt32)scaledWidthB << 0x10 | (SInt32)scaledHeightB;
      }
    }
  }
  else {
    rectXD = (double)(SInt32)((SInt32)*rect);
    rectRightD = (double)(SInt32)((SInt32)*rect + (SInt32)rect[2]);
    if (flipV == 0) {
      yTopB2 = (UInt32)rect[1];
      yBottomB2 = yTopB2 + (SInt32)rect[3];
    }
    else {
      yBottomB2 = (UInt32)rect[1];
      yTopB2 = yBottomB2 + (SInt32)rect[3];
    }
    yFirstDC = (double)(SInt32)(yTopB2);
    ySecondDC = (double)(SInt32)(yBottomB2);
    rectX = M<float>(paramsBytes + 0x54);
    rectY = M<float>(paramsBytes + 0x58);
    rectW = M<float>(paramsBytes + 0x5c);
    rectH = M<float>(paramsBytes + 0x60);
    cmd[0xbd] = 0x31080;
    halfConst = FLOAT_0004c380;
    cmd[0xbe] = FBITS((float)(invScaleX * rectXD));
    cmd[0xbf] = FBITS((float)(invScaleY * ySecondDC));
    cmd[0xc0] = FBITS((float)(invScaleX * rectRightD));
    cmd[0xc1] = FBITS((float)(invScaleY * yFirstDC));
    cmd[0xc2] = 0x1087;
    cmd[0xc4] = 0xc0033500;
    cmd[0xc5] = 0x10031;
    cmd[0xc6] = FBITS(((rectX + rectX + rectW) * halfConst));
    cmd[199] = FBITS(((rectY + rectY + rectH) * halfConst));
    cmd[200] = 0;
    cmd[0xc3] =
         (SInt32)(((rectX + rectW) - rectX) * vertexScale) << 0x10 | (SInt32)(((rectY + rectH) - rectY) * vertexScale)
    ;
    endIndex = 0xc9;
  }
  cmd[endIndex] = 0x1393;
  cmd[endIndex + 1] = 10;
  return cmd + endIndex + 2;
}
