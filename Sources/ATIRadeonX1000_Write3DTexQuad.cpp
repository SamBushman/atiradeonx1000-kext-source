/*
 * ATIRadeonX1000_Write3DTexQuad.cpp
 *
 * RESOLVED (ledger pass): write_3dtexquad_cmds_for_copy_buffer_using_DMA (real addr 0x41150, 6360 bytes), the free
 * function ATIR500Surface::copy_buffer_using_DMA calls to build the 3D textured-quad blit that copies a surface buffer
 * to or from client memory through the GART: it copies the r500 3D-blit state packet into the command stream, patches
 * in the source texture and destination colour-buffer descriptors (address, size, pitch, format from the three
 * function-local tables below), emits the viewport/scissor words and one or two textured quads (large or scaled copies
 * are split into strips), and returns the new command-stream length in words.
 *
 * Transcribed mechanically from the shipped kext's decompile with Tools/ghidra2cpp.py (see Headers/GhidraCompat.h and
 * ATIR500Surface_BuildSwap.cpp for the conventions). The rectangle {x, y, w, h} that Ghidra shows as the four stack
 * shorts local_368/sStack_366/local_364/sStack_362 is (param_19, param_20, param_23, param_24) truncated to 16 bits;
 * param_25 is the "flip vertically" flag (the decompile's stack overflow slot _in_stack_00000078).
 *
 * BUG FIXED (2026-10-12, issue #158, second attempt - a first attempt, f74bc27, was a no-op and is superseded):
 * every texcoord (0xbe/0xbf/0xc0/0xc1) and vertex-position (0xc6/0xc7=199, and their per-sub-quad equivalents
 * puVar33[5/6/7/8/0xd/0xe]) word in this function was written as `(UInt32)(some_float_expr)` - a real C++ numeric
 * cast, which TRUNCATES the float to an integer value. The real stock PPC code stores these words with `stfs`
 * (store-float-single: the raw IEEE bit pattern, unconverted) - confirmed both by re-disassembling the real
 * binary (every one of these words corresponds to an `stfs`, never `fctiwz`+`stw`) and by live-testing: a 4-pixel
 * point size that should store the float bits of `2.0` (`0x40000000`) was instead storing the truncated integer
 * value `2` (`0x00000002`), collapsing the GPU's point-sprite blit to a tiny/degenerate size. Ghidra's own decompile
 * shows this exact pattern as `(ulong)(float_expr)` for every one of these stores - that's the decompiler's idiom
 * for "a float stored through an integer-typed pointer" (i.e. a raw bit-level store), not an instruction to
 * numerically convert; the original mechanical port mistranslated it as a literal C-style value cast. Fixed by
 * using this project's existing `FBITS()` helper (Headers/GhidraCompat.h - a bit-reinterpreting cast, exactly the
 * tool already used elsewhere in this project for the identical idiom) in place of every `(UInt32)(float)` cast
 * that targets one of these word slots. The point-size encoding itself (0xc3, two packed 16-bit integers) is a
 * genuine value truncation and was NOT changed - confirmed correct both via live output (24,24 for a 4x4 copy at
 * the 6x scale factor) and via the real disassembly (`stw`, not `stfs`, for that one word).
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

extern "C" const r500_3d_blit_state_packet_struct g_r500_3d_blit_state_packet;

/* real addr 0x41150 */
UInt32 write_3dtexquad_cmds_for_copy_buffer_using_DMA(ATIRadeonX1000 *accelerator, UInt32 *cmd, UInt32 wordCount,
    UInt32 formatIndex, UInt32 srcAddress, UInt32 unused6, UInt32 srcWidth, UInt32 srcHeight, UInt32 srcTileFlags, UInt32 srcShift,
    unsigned char srcLowBits, UInt32 unused12, UInt32 dstAddress, UInt32 unused14, UInt32 dstPitch, UInt32 dstTileFlags,
    UInt32 dstShift, unsigned char unknown_param18, long dstX, long dstY, long srcX, long srcY,
    UInt32 width, UInt32 height, bool flip) {
    UInt8 *acceleratorBytes = reinterpret_cast<UInt8 *>(accelerator);
    static UInt32 out_fmt[5] = { 0x00000001, 0x00000000, 0x00000001, 0x00000005, 0x00000015 };
    static UInt32 rb3d_dst_format[5] = { 0x00000009, 0x0000000f, 0x00000006, 0x0000000a, 0x00000007 };
    static UInt32 texture_type[5] = { 0x00000000, 0x0000000a, 0x0000000c, 0x0000000e, 0x0000001d };

  float scaledHeightB;
  float srcYAtDstTop;
  float dstYMax;
  float dstYMin;
  SInt32 packetEndIndex;
  SInt32 nextPacketIndex;
  UInt32 firstRow;
  UInt32 *quadPacket;
  UInt32 firstColumn;
  UInt32 columnWidthLeft;
  SInt32 cmdEndIndex;
  UInt32 chunkLeft;
  UInt32 srcLeft;
  UInt32 dstTileBits;
  UInt32 srcTileBits;
  UInt32 *chunkPacket;
  UInt32 srcTop;
  UInt32 lastColumn;
  UInt32 chunkH;
  UInt32 rowIndex;
  UInt32 chunkTop;
  UInt32 *packet;
  UInt32 columnsLeft;
  float rectRightD;
  float yFirstDC;
  float ySecondDC;
  SInt16 rectX;
  SInt16 rectY;
  SInt16 rectWidth;
  SInt16 rectHeight;
  UInt32 srcTextureOffsetReg;
  UInt32 srcTextureSizeReg;
  UInt32 srcTextureFormatReg;
  UInt32 srcTexturePitchReg;
  UInt32 packetBits0xa92;
  UInt32 dstColorPitchReg;
  UInt32 dstColorOffsetReg;
  UInt32 outputFormatReg;
  UInt32 scissorTopLeftReg;
  UInt32 scissorBottomRightReg;
  UInt32 acceleratorWord0xb74;
  UInt32 formatIndexSaved;
  UInt32 paramsWord30;
  UInt32 paramsWord44;
  UInt32 paramsWord48;
  UInt32 paramsWord4c;
  SInt16 *rectPtr;
  float quadLeft;
  float quadTop;
  float quadWidth;
  float paramsFloat64;
  float paramsFloat68;
  float srcWidthF;
  float srcHeightF;
  UInt32 paramsWord74;
  UInt32 paramsWord78;
  UInt32 paramsWord7c;
  UInt32 paramsWord80;
  UInt32 paramsWord84;
  SInt32 paramsFlag88;
  UInt32 magicHi0;
  UInt32 srcXBiased;
  UInt32 magicHi1;
  UInt32 srcYBiased;
  UInt32 magicHi2;
  SInt32 srcRightEdge;
  UInt32 magicHi3;
  SInt32 srcBottomEdge;
  UInt32 magicHi4;
  UInt32 widthLo;
  UInt32 magicHi5;
  UInt32 heightLo;
  UInt32 magicHi6;
  UInt32 srcWidthLo;
  UInt32 magicHi7;
  UInt32 srcHeightLo;
  SInt64 fctiwzSpill0;
  SInt64 fctiwzSpill1;
  SInt64 fctiwzSpill2;
  SInt64 fctiwzSpill3;
  SInt64 fctiwzSpill4;
  SInt64 fctiwzSpill5;
  SInt64 fctiwzSpill6;
  SInt64 fctiwzSpill7;
  UInt32 srcRight;
  UInt32 srcBottom;
  UInt32 columnChunks;
  UInt32 rowChunks;
  UInt32 chunkCount;
  UInt32 copyWidth;
  UInt32 copyHeight;
  UInt32 texturePitchWord;
  UInt32 textureOffsetWord;
  float quadRight;
  float quadBottom;
  float srcPerQuadX;
  float srcPerQuadY;
  float scaledQuadLeft;
  float srcOffsetX;
  float rectYF;
  float srcOffsetY;
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
  float chunkLeftF;
  float invCopyWidth;
  float invCopyHeight;
  float srcRightD;
  float srcRightRoundedD;
  float srcTopD;
  float srcLeftD;
  float srcTopRoundedD;
  float srcBottomD;
  float srcLeftRoundedD;
  float srcBottomRoundedD;
  float srcWidthD;
  float srcHeightD;
  float invSrcHeightD;
  float quadHeight;
  float quadBottomB;
  float invSrcWidthD;
  float chunkLeftD;
  float yFirstD1;
  float yFirstD2;
  float ySecondD1;
  float ySecondD2;
  float rectXD;
  float vertexScale;
  float halfWidthPlus2F;
  float rectRightF;
  float centerXB1;
  float invWidth2;
  float texRight2;
  float invHalfWidth;
  float texLeft;
  float secondHalfWidthF;
  float leftEdgeF;
  float centerXB2;
  float srcXAtLeft;
  float chunkMaxX;
  float chunkMinX;
  float dstXMax;
  float scaledWidthB;
  float halfConst;
  float texRight1;
  float texLeft2;
  float chunkMinY;
  float dstXFirst;
  float vertexCenterY;
  float chunkMaxY;
  float srcXAtDstMin;
  float clampedMinX;
  float clampTmpMaxX;
  float dstYFirst;
  float dstXMin;
  float clampTmpMaxY;
  float srcYAtDstMin;
  float clampedMinY;
  UInt32 alignedWidthLimit;
  UInt32 rowCandidate;
  UInt32 widthMinusOne;
  UInt32 srcMaxXInt;
  UInt32 microTiling;
  UInt32 rightLimit;
  UInt32 yFirstB1;
  UInt32 macroTileBit;
  UInt32 formatInfoB;
  UInt32 stateWordA6B;
  UInt32 formatInfo;
  UInt32 bppShift;
  UInt32 stateWordA6;
  UInt32 rectRight;
  UInt32 chunkW;
  UInt32 chunkLeftBiased;
  UInt32 halfWidthAligned;
  UInt32 yBottomB2;
  UInt32 halfWidthPlus2;
  UInt32 ySecondB1;
  UInt32 leftMax;
  UInt32 yTopB2;
  UInt32 columnEnd;
  UInt32 heightMinusOne;
  UInt32 srcMaxYInt;
  UInt32 rectX3;
  UInt32 rowEnd;
  UInt32 rowsLeft;
  UInt32 chunkTopRow;
  UInt32 chunkWidthWord;
  UInt32 stateWordA0;
  UInt32 columnCandidate;
  UInt32 alignedHeightLimit;
  UInt32 columnBase;
  UInt32 rowBase;
  UInt32 secondHalfWidth;
  UInt32 rectX2;
  SInt32 columnIndex;
  SInt32 formatTableOffset;
  SInt32 tileBiasB;
  SInt32 leftByteOffset;
  SInt32 tileBias;
  SInt32 columnByteOffset;
  SInt32 leftUnits;
  SInt32 unbiasedInt;
  SInt32 rowOffset;
  SInt32 quadWordCount;
  SInt32 packetIndex;
  
  srcRightEdge = srcX + width;
  srcBottomEdge = srcY + height;
  srcXBiased = srcX ^ 0x80000000;
  srcYBiased = srcY ^ 0x80000000;
  magicHi0 = 0x43300000;
  magicHi1 = 0x43300000;
  magicHi2 = 0x43300000;
  rectX = (SInt16)dstX;
  rectHeight = (SInt16)height;
  rectY = (SInt16)dstY;
  rectWidth = (SInt16)width;
  magicHi3 = 0x43300000;
  acceleratorWord0xb74 = M<UInt32>(acceleratorBytes + 0xb74);
  packetBits0xa92 = 0xa92;
  heightLo = height;
  magicHi4 = 0x43300000;
  magicHi5 = 0x43300000;
  magicHi6 = 0x43300000;
  widthLo = width;
  paramsWord30 = unused12;
  rectPtr = &rectX;
  magicHi7 = 0x43300000;
  paramsWord44 = paramsWord44 | 0xf8000000;
  paramsFloat68 = FLOAT_0004c370;
  paramsWord48 = 1;
  paramsWord4c = 0;
  srcRightD = (double)(UInt32)(srcRightEdge);
  quadLeft = FLOAT_0004c370;
  quadTop = FLOAT_0004c370;
  paramsFloat64 = FLOAT_0004c370;
  paramsWord80 = 0x3f800000;
  srcTileBits = 0;
  paramsWord84 = 1;
  paramsFlag88 = 0;
  srcWidthF = (float)(UInt32)(srcWidth);
  paramsWord74 = 0x3f800000;
  paramsWord78 = 0x3f800000;
  quadWidth = (float)(UInt32)(width);
  paramsWord7c = 0x3f800000;
  quadHeight = (float)(UInt32)(height);
  srcRightRoundedD = srcRightD;
  srcTopD = (double)(SInt32)(srcYBiased ^ 0x80000000);
  srcLeftD = (double)(SInt32)(srcXBiased ^ 0x80000000);
  srcTopRoundedD = srcTopD;
  srcBottomD = (double)(UInt32)(srcBottomEdge);
  srcLeftRoundedD = srcLeftD;
  srcBottomRoundedD = srcBottomD;
  srcHeightF = (float)(UInt32)(srcHeight);
  if (srcShift != 4) {
    srcTileBits = (srcTileFlags & 6) << 2;
  }
  lastColumn = srcWidth - 1;
  srcTextureSizeReg = lastColumn & 0x7ff | (srcHeight - 1) * 0x800 & 0x3ff800 | 0x80000000;
  srcTextureOffsetReg = srcTileBits | (srcTileFlags & 1) << 2 | srcLowBits & 3 | srcAddress & 0xffffffe0;
  dstColorOffsetReg = dstAddress & 0xffffffe0;
  srcTexturePitchReg = lastColumn & 0x3fff | lastColumn * 0x10 & 0x8000 | (srcHeight - 1) * 0x20 & 0x10000;
  srcTextureFormatReg = (UInt32)(srcShift != 0) * 0x2000 |
              (UInt32)texture_type[srcShift] & 0x1f | 0x8600;
  dstTileBits = 0;
  if (dstShift != 4) {
    dstTileBits = (dstTileFlags & 6) << 0x10;
  }
  dstColorPitchReg = dstTileBits | (dstTileFlags & 1) << 0x10 | dstPitch & 0x3ffe | (unknown_param18 & 3) << 0x13 |
              (rb3d_dst_format[srcShift] & 0xf) << 0x15;
  outputFormatReg = out_fmt[srcShift] & 0x1f | 0x1b00;
  if (DOUBLE_0004c3c8 <= srcLeftRoundedD) {
    unbiasedInt = (SInt32)(srcLeftRoundedD - DOUBLE_0004c3c8);
    fctiwzSpill1 = (SInt64)unbiasedInt;
    srcLeft = unbiasedInt + 0x80000000;
  }
  else {
    srcLeft = (UInt32)srcLeftD;
    fctiwzSpill0 = (SInt64)(SInt32)srcLeft;
  }
  if (DOUBLE_0004c3c8 <= srcTopRoundedD) {
    unbiasedInt = (SInt32)(srcTopRoundedD - DOUBLE_0004c3c8);
    fctiwzSpill3 = (SInt64)unbiasedInt;
    srcTop = unbiasedInt + 0x80000000;
  }
  else {
    srcTop = (UInt32)srcTopD;
    fctiwzSpill2 = (SInt64)(SInt32)srcTop;
  }
  scissorTopLeftReg = srcLeft & 0x1fff | (srcTop & 0x1fff) << 0xd;
  if (DOUBLE_0004c3c8 <= srcRightRoundedD) {
    unbiasedInt = (SInt32)(srcRightRoundedD - DOUBLE_0004c3c8);
    fctiwzSpill5 = (SInt64)unbiasedInt;
    srcRight = unbiasedInt + 0x80000000;
  }
  else {
    srcRight = (UInt32)srcRightD;
    fctiwzSpill4 = (SInt64)(SInt32)srcRight;
  }
  if (DOUBLE_0004c3c8 <= srcBottomRoundedD) {
    unbiasedInt = (SInt32)(srcBottomRoundedD - DOUBLE_0004c3c8);
    fctiwzSpill7 = (SInt64)unbiasedInt;
    srcBottom = unbiasedInt + 0x80000000;
  }
  else {
    srcBottom = (UInt32)srcBottomD;
    fctiwzSpill6 = (SInt64)(SInt32)srcBottom;
  }
  srcWidthD = srcWidthF;
  srcHeightD = srcHeightF;
  scissorBottomRightReg = srcRight & 0x1fff | (srcBottom & 0x1fff) << 0xd;
  invSrcWidthD = FLOAT_0004c370;
  packet = cmd + wordCount;
  if (srcWidthD != invSrcWidthD) {
    invSrcWidthD = (FLOAT_0004c374 / srcWidthD);
  }
  invSrcHeightD = FLOAT_0004c370;
  if (srcHeightD != invSrcHeightD) {
    invSrcHeightD = (FLOAT_0004c374 / srcHeightD);
  }
  formatIndexSaved = formatIndex;
  srcWidthLo = srcWidth;
  srcHeightLo = srcHeight;
  GCopy(packet,(&g_r500_3d_blit_state_packet),0x2f4);
  packet[0xaa] = srcTexturePitchReg;
  packet[0xa0] = srcTextureOffsetReg;
  packetIndex = 0xbd;
  packet[0xa6] = srcTextureSizeReg;
  packet[0xa8] = srcTextureFormatReg;
  packet[0x9c] = dstColorPitchReg;
  packet[0x9a] = dstColorOffsetReg;
  packet[0x8a] = outputFormatReg;
  packet[0xb2] = scissorTopLeftReg;
  packet[0xb3] = scissorBottomRightReg;
  packet[0xb] = acceleratorWord0xb74;
  packet[0xa2] = packetBits0xa92 & 0x1800 | packetBits0xa92 & 0x600 | packet[0xa2] & 0xffffe1ff;
  if (paramsFlag88 != 0) {
    packet[0x1e] = packet[0x1e] & 0xfffffffc | 2;
  }
  halfConst = FLOAT_0004c380;
  vertexScale = FLOAT_0004c37c;
  invHalfWidth = FLOAT_0004c370;
  if ((FLOAT_0004c378 < srcWidthD) || (FLOAT_0004c378 < srcHeightD)) {
    if (srcWidthD <= FLOAT_0004c378) {
      quadRight = quadLeft + quadWidth;
      quadBottom = quadTop + quadHeight;
      srcPerQuadX = FLOAT_0004c370;
      if (quadWidth != FLOAT_0004c370) {
        srcPerQuadX = (float)(SInt32)((SInt32)rectWidth)
                / quadWidth;
      }
      scaledQuadLeft = quadLeft * srcPerQuadX;
      srcOffsetX = (float)(SInt32)((SInt32)rectX) -
              scaledQuadLeft;
      srcPerQuadY = FLOAT_0004c370;
      if (quadHeight != FLOAT_0004c370) {
        srcPerQuadY = (float)(SInt32)((SInt32)rectHeight)
                / quadHeight;
      }
      rectYF = (float)(SInt32)((SInt32)rectY);
      srcOffsetY = -(quadTop * srcPerQuadY - rectYF);
      if (flip != 0) {
        srcPerQuadY = -srcPerQuadY;
        srcOffsetY = (float)(SInt32)((SInt32)rectY + (SInt32)rectHeight) - (srcOffsetY - rectYF);
      }
      copyWidth = (SInt32)srcWidthD & 0xffff;
      copyHeight = (SInt32)srcHeightD & 0xffff;
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
        srcYAtDstTop = srcPerQuadY * quadTop + srcOffsetY;
        srcMaxY = srcPerQuadY * quadBottom + srcOffsetY;
        srcXAtLeft = scaledQuadLeft + srcOffsetX;
        srcMaxX = quadRight * srcPerQuadX + srcOffsetX;
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
        alignedWidthLimit = (SInt32)srcWidthD & 0xfe00;
        columnCandidate = (SInt32)srcMinX - 1;
        columnCandidate = (((SInt32)columnCandidate >> 9) + (UInt32)((SInt32)columnCandidate < 0 && (columnCandidate & 0x1ff) != 0)) * 0x200;
        firstColumn = 0;
        if ((-1 < (SInt32)columnCandidate) && (firstColumn = alignedWidthLimit, (SInt32)columnCandidate <= (SInt32)alignedWidthLimit)) {
          firstColumn = columnCandidate & 0xfe00;
        }
        alignedHeightLimit = 0x40;
        if ((0x40 < copyHeight) && (alignedHeightLimit = (SInt32)srcHeightD & 0xffc0, (SInt32)(copyHeight - alignedHeightLimit) < 0x40)) {
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
      quadPacket = packet + 0xbd;
      if (chunkCount != 0) {
        dstPerSrcX = FLOAT_0004c370;
        if (srcPerQuadX != FLOAT_0004c370) {
          dstPerSrcX = FLOAT_0004c374 / srcPerQuadX;
        }
        dstPerSrcY = FLOAT_0004c370;
        if (srcPerQuadY != FLOAT_0004c370) {
          dstPerSrcY = FLOAT_0004c374 / srcPerQuadY;
        }
        if (rowChunks != 0) {
          rowsLeft = copyHeight - firstRow;
          rowIndex = 0;
          rowOffset = 0;
          chunkPacket = quadPacket;
          chunkTopRow = firstRow;
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
                clampedMinY = chunkMinY;
                if (chunkMinY - srcMinY < 0.0) {
                  clampedMinY = srcMinY;
                }
                clampTmpMaxY = srcMaxY;
                if (chunkMaxY - srcMaxY < 0.0) {
                  clampTmpMaxY = chunkMaxY;
                }
                clampedMinX = chunkMinX;
                if (chunkMinX - srcMinX < 0.0) {
                  clampedMinX = srcMinX;
                }
                clampTmpMaxX = srcMaxX;
                if (chunkMaxX - srcMaxX < 0.0) {
                  clampTmpMaxX = chunkMaxX;
                }
                if (-(chunkMinY - srcMinY) < 0.0) {
                  clampedMinY = chunkMinY;
                }
                if (-(chunkMaxY - srcMaxY) < 0.0) {
                  chunkMaxY = clampTmpMaxY;
                }
                if (-(chunkMinX - srcMinX) < 0.0) {
                  clampedMinX = chunkMinX;
                }
                if (-(chunkMaxX - srcMaxX) < 0.0) {
                  chunkMaxX = clampTmpMaxX;
                }
                dstYFirst = dstPerSrcY * clampedMinY + dstPerSrcY * -srcOffsetY;
                dstYMax = dstPerSrcY * chunkMaxY + dstPerSrcY * -srcOffsetY;
                dstXFirst = dstPerSrcX * clampedMinX + dstPerSrcX * -srcOffsetX;
                dstXMax = dstPerSrcX * chunkMaxX + dstPerSrcX * -srcOffsetX;
                srcYAtDstMin = chunkMaxY;
                dstYMin = dstYFirst;
                if (dstYMax < dstYFirst) {
                  srcYAtDstMin = clampedMinY;
                  clampedMinY = chunkMaxY;
                  dstYMin = dstYMax;
                  dstYMax = dstYFirst;
                }
                srcXAtDstMin = chunkMaxX;
                dstXMin = dstXFirst;
                if (dstXMax < dstXFirst) {
                  srcXAtDstMin = clampedMinX;
                  clampedMinX = chunkMaxX;
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
                          (float)((double)(SInt32)(chunkH)
                                 );
                }
                chunkLeftBiased = chunkLeft ^ 0x80000000;
                columnIndex = columnIndex + 1;
                chunkLeft = chunkLeft + 0xc00;
                columnWidthLeft = columnWidthLeft - 0xc00;
                scaledHeight = (dstYMax - dstYMin) * FLOAT_0004c37c;
                scaledWidth = (dstXMax - dstXMin) * FLOAT_0004c37c;
                centerY = (dstYMax + dstYMin) * FLOAT_0004c380;
                centerX = (dstXMax + dstXMin) * FLOAT_0004c380;
                chunkLeftD = (double)(SInt32)(chunkLeftBiased ^ 0x80000000);
                chunkPacket[4] = 0x31080;
                chunkPacket[6] = FBITS(invChunkHeight * (srcYAtDstMin - chunkTopF));
                chunkPacket[8] = FBITS(invChunkHeight * (clampedMinY - chunkTopF));
                chunkPacket[0xb] = 0xc0033500;
                chunkPacket[0xc] = 0x10031;
                chunkPacket[0xd] = FBITS(centerX);
                chunkLeftF = (float)chunkLeftD;
                chunkPacket[0xe] = FBITS(centerY);
                chunkPacket[9] = 0x1087;
                chunkPacket[10] = (SInt32)scaledWidth << 0x10 | (SInt32)scaledHeight;
                chunkPacket[0xf] = 0;
                chunkPacket[7] = FBITS(invChunkWidth * (srcXAtDstMin - chunkLeftF));
                chunkPacket[5] = FBITS(invChunkWidth * (clampedMinX - chunkLeftF));
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
        scaledWidth = (quadRight - quadLeft) * FLOAT_0004c37c;
        scaledHeight = (quadBottom - quadTop) * FLOAT_0004c37c;
        centerY = (quadTop + quadBottom) * FLOAT_0004c380;
        centerX = (quadLeft + quadRight) * FLOAT_0004c380;
        *quadPacket = 0x31080;
        packet[0xbe] = FBITS(invCopyWidth * (scaledQuadLeft + srcOffsetX));
        packet[0xbf] = FBITS(invCopyHeight * (srcPerQuadY * quadBottom + srcOffsetY));
        packet[0xc0] = FBITS(invCopyWidth * (quadRight * srcPerQuadX + srcOffsetX));
        packet[0xc1] = FBITS(invCopyHeight * (srcPerQuadY * quadTop + srcOffsetY));
        packet[0xc4] = 0xc0033500;
        packet[0xc5] = 0x10031;
        packet[0xc6] = FBITS(centerX);
        packet[199] = FBITS(centerY);
        packet[0xc2] = 0x1087;
        packet[0xc3] = (SInt32)scaledWidth << 0x10 | (SInt32)scaledHeight;
        packet[200] = 0;
      }
      texturePitchWord = packet[0xaa];
      textureOffsetWord = packet[0xa0];
      microTiling = textureOffsetWord >> 3 & 3;
      macroTileBit = textureOffsetWord >> 2 & 1;
      if (chunkCount != 0) {
        if (chunkCount == 0) {
          quadWordCount = 0;
        }
        else {
          formatTableOffset = (formatIndexSaved & 0xff) * 0x1c;
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
                         macroTileBit << 2 | microTiling << 3;
            chunkWidthWord = chunkPacket[2];
            stateWordA6 = packet[0xa6];
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
        quadPacket = packet + 0xc9;
      }
      packetEndIndex = (SInt32)quadPacket - (SInt32)packet >> 2;
    }
    else {
      stateWordA0 = packet[0xa0];
      formatTableOffset = (formatIndexSaved & 0xff) * 0x1c;
      halfWidthAligned = (SInt32)srcWidthD >> 1 & 0xfffffe00;
      secondHalfWidth = (SInt32)srcWidthD - halfWidthAligned;
      halfWidthPlus2 = halfWidthAligned + 2;
      if ((stateWordA0 & 0x18) == 0) {
        formatInfoB = FormatTableLookup_0x0004d2dc(formatTableOffset);
        tileBiasB = 0;
      }
      else {
        formatInfoB = FormatTableLookup_0x0004d2dc(formatTableOffset);
        tileBiasB = -(formatInfoB >> 8 & 3);
      }
      leftUnits = (SInt32)halfWidthAligned >> ((tileBiasB - (formatInfoB >> 0xc & 7)) + 5 & 0x3f);
      leftByteOffset = leftUnits << 5;
      if ((stateWordA0 >> 2 & 1) != 0) {
        leftByteOffset = (leftUnits << 0xc) >> 3;
      }
      stateWordA6B = halfWidthAligned + 1 & 0x7ff | packet[0xa6] & 0xfffff800;
      packet[0xa6] = stateWordA6B;
      halfWidthPlus2F = (float)(SInt32)(halfWidthPlus2);
      if (halfWidthPlus2F != invHalfWidth) {
        invHalfWidth = FLOAT_0004c374 / halfWidthPlus2F;
      }
      rectX3 = (UInt32)rectX;
      rectRight = rectX3 + (SInt32)rectWidth;
      rightLimit = halfWidthPlus2;
      if ((SInt32)rectRight < (SInt32)halfWidthPlus2) {
        rightLimit = rectRight;
      }
      if ((SInt32)halfWidthPlus2 < (SInt32)rectRight) {
        rectRightF = (float)(SInt32)(halfWidthPlus2 - rectX3)
        ;
      }
      else {
        rectRightF = quadLeft + quadWidth;
      }
      texRight1 = invHalfWidth * (float)(SInt32)(rightLimit);
      texLeft = invHalfWidth * (float)(SInt32)(rectX3);
      if (flip == 0) {
        yFirstB1 = (UInt32)rectY;
        ySecondB1 = yFirstB1 + (SInt32)rectHeight;
      }
      else {
        ySecondB1 = (UInt32)rectY;
        yFirstB1 = ySecondB1 + (SInt32)rectHeight;
      }
      yFirstD1 = (double)(SInt32)(yFirstB1);
      ySecondD1 = (double)(SInt32)(ySecondB1);
      quadBottomB = quadTop + quadHeight;
      if (texLeft < texRight1) {
        scaledHeightB = (quadBottomB - quadTop) * FLOAT_0004c37c;
        scaledWidthB = (rectRightF - quadLeft) * FLOAT_0004c37c;
        centerXB1 = (rectRightF + quadLeft) * FLOAT_0004c380;
        vertexCenterY = (quadTop + quadBottomB) * FLOAT_0004c380;
        packet[0xbd] = 0x31080;
        packet[0xbe] = FBITS(texLeft);
        packet[0xc2] = 0x1087;
        packet[0xbf] = FBITS((float)(invSrcHeightD * ySecondD1));
        packet[0xc0] = FBITS(texRight1);
        packet[0xc1] = FBITS((float)(invSrcHeightD * yFirstD1));
        packet[0xc4] = 0xc0033500;
        packet[0xc5] = 0x10031;
        packet[0xc6] = FBITS(centerXB1);
        packet[199] = FBITS(vertexCenterY);
        packet[200] = 0;
        packet[0xc3] = (SInt32)scaledWidthB << 0x10 | (SInt32)scaledHeightB;
        packetIndex = 0xc9;
        stateWordA0 = packet[0xa0];
        stateWordA6B = packet[0xa6];
      }
      packet[packetIndex] = 0x1150;
      packet[packetIndex + 1] = stateWordA0 + leftByteOffset;
      packet[packetIndex + 2] = 0x1120;
      nextPacketIndex = packetIndex + 4;
      packet[packetIndex + 3] = secondHalfWidth - 1 & 0x7ff | stateWordA6B & 0xfffff800;
      secondHalfWidthF = (float)(SInt32)(secondHalfWidth);
      invWidth2 = FLOAT_0004c370;
      if (secondHalfWidthF != FLOAT_0004c370) {
        invWidth2 = FLOAT_0004c374 / secondHalfWidthF;
      }
      rectX2 = (UInt32)rectX;
      leftMax = halfWidthAligned;
      if ((SInt32)rectX2 > (SInt32)halfWidthAligned) {
        leftMax = rectX2;
      }
      leftEdgeF = quadLeft;
      if ((SInt32)rectX2 <= (SInt32)halfWidthAligned) {
        leftEdgeF = (float)(SInt32)(halfWidthAligned - rectX2)
        ;
      }
      texLeft2 = invWidth2 * ((float)(SInt32)(leftMax) -
                      (float)(SInt32)(halfWidthAligned));
      texRight2 = invWidth2 * (float)(SInt32)((rectX2 + (SInt32)rectWidth) - halfWidthAligned);
      if (flip == 0) {
        yTopB2 = (UInt32)rectY;
        yBottomB2 = yTopB2 + (SInt32)rectHeight;
      }
      else {
        yBottomB2 = (UInt32)rectY;
        yTopB2 = yBottomB2 + (SInt32)rectHeight;
      }
      yFirstD2 = (double)(SInt32)(yTopB2);
      ySecondD2 = (double)(SInt32)(yBottomB2);
      packetEndIndex = nextPacketIndex;
      if (texLeft2 < texRight2) {
        scaledWidthB = ((quadLeft + quadWidth) - leftEdgeF) * FLOAT_0004c37c;
        scaledHeightB = (quadBottomB - quadTop) * FLOAT_0004c37c;
        packetEndIndex = nextPacketIndex * 4 + 0x30 >> 2;
        vertexCenterY = (quadTop + quadBottomB) * FLOAT_0004c380;
        centerXB2 = (leftEdgeF + quadLeft + quadWidth) * FLOAT_0004c380;
        packet[nextPacketIndex] = 0x31080;
        packet[packetIndex + 5] = FBITS(texLeft2);
        packet[packetIndex + 6] = FBITS((float)(invSrcHeightD * ySecondD2));
        packet[packetIndex + 7] = FBITS(texRight2);
        packet[packetIndex + 9] = 0x1087;
        packet[packetIndex + 8] = FBITS((float)(invSrcHeightD * yFirstD2));
        packet[packetIndex + 0xb] = 0xc0033500;
        packet[packetIndex + 0xc] = 0x10031;
        packet[packetIndex + 0xd] = FBITS(centerXB2);
        packet[packetIndex + 0xe] = FBITS(vertexCenterY);
        packet[packetIndex + 0xf] = 0;
        packet[packetIndex + 10] = (SInt32)scaledWidthB << 0x10 | (SInt32)scaledHeightB;
      }
    }
  }
  else {
    rectXD = (double)(SInt32)((SInt32)rectX);
    rectRightD = (double)(SInt32)((SInt32)rectX + (SInt32)rectWidth);
    if (flip == 0) {
      yTopB2 = (UInt32)rectY;
      yBottomB2 = yTopB2 + (SInt32)rectHeight;
    }
    else {
      yBottomB2 = (UInt32)rectY;
      yTopB2 = yBottomB2 + (SInt32)rectHeight;
    }
    yFirstDC = (double)(SInt32)(yTopB2);
    ySecondDC = (double)(SInt32)(yBottomB2);
    packet[0xbd] = 0x31080;
    packet[0xbe] = FBITS((float)(invSrcWidthD * rectXD));
    packet[0xbf] = FBITS((float)(invSrcHeightD * ySecondDC));
    packet[0xc0] = FBITS((float)(invSrcWidthD * rectRightD));
    packet[0xc1] = FBITS((float)(invSrcHeightD * yFirstDC));
    packet[0xc2] = 0x1087;
    packet[0xc4] = 0xc0033500;
    packet[0xc5] = 0x10031;
    packet[0xc6] = FBITS((quadLeft + quadLeft + quadWidth) * FLOAT_0004c380);
    packet[199] = FBITS((quadTop + quadTop + quadHeight) * FLOAT_0004c380);
    packet[200] = 0;
    packet[0xc3] =
         (SInt32)(((quadLeft + quadWidth) - quadLeft) * FLOAT_0004c37c) << 0x10 |
         (SInt32)(((quadTop + quadHeight) - quadTop) * FLOAT_0004c37c);
    packetEndIndex = 0xc9;
  }
  packet[packetEndIndex] = 0x1393;
  packet[packetEndIndex + 1] = 10;
  cmdEndIndex = (SInt32)packet + ((packetEndIndex + 2) * 4 - (SInt32)cmd) >> 2;
  cmd[cmdEndIndex] = 0x1393;
  cmd[cmdEndIndex + 1] = 10;
  cmd[cmdEndIndex + 2] = 0x5c8;
  cmd[cmdEndIndex + 3] = 0x20000;
  return cmdEndIndex + 4;
}
