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

UInt32 write_3dtexquad_cmds_for_copy_buffer_using_DMA(ATIRadeonX1000 *accelerator, UInt32 *cmd, UInt32 wordCount,
    UInt32 formatIndex, UInt32 srcAddress, UInt32 unused6, UInt32 srcWidth, UInt32 srcHeight, UInt32 srcTileFlags, UInt32 srcShift,
    unsigned char srcLowBits, UInt32 unused12, UInt32 dstAddress, UInt32 unused14, UInt32 dstPitch, UInt32 dstTileFlags,
    UInt32 dstShift, unsigned char unknown_param18, long dstX, long dstY, long srcX, long srcY,
    UInt32 width, UInt32 height, bool flip) {
    UInt8 *acceleratorBytes = reinterpret_cast<UInt8 *>(accelerator);
    static UInt32 out_fmt[5] = { 0x00000001, 0x00000000, 0x00000001, 0x00000005, 0x00000015 };
    static UInt32 rb3d_dst_format[5] = { 0x00000009, 0x0000000f, 0x00000006, 0x0000000a, 0x00000007 };
    static UInt32 texture_type[5] = { 0x00000000, 0x0000000a, 0x0000000c, 0x0000000e, 0x0000001d };

  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  SInt32 iVar22;
  SInt32 iVar23;
  UInt32 uVar24;
  UInt32 firstRow;
  UInt32 uVar25;
  UInt32 uVar26;
  UInt32 *quadPacket;
  UInt32 uVar28;
  UInt32 firstColumn;
  UInt32 columnWidthLeft;
  SInt32 iVar30;
  UInt32 chunkLeft;
  UInt32 uVar32;
  UInt32 srcLeft;
  UInt32 dstTileBits;
  UInt32 srcTileBits;
  UInt32 *chunkPacket;
  UInt32 uVar34;
  UInt32 srcTop;
  UInt32 lastColumn;
  UInt32 uVar35;
  UInt32 uVar36;
  UInt32 uVar37;
  UInt32 rowIndex;
  UInt32 uVar39;
  UInt32 chunkTop;
  UInt32 *packet;
  UInt32 uVar42;
  UInt32 columnsLeft;
  double dVar44;
  double dVar45;
  double dVar46;
  double dVar47;
  double dVar48;
  double dVar49;
  double dVar50;
  double dVar51;
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
  UInt32 local_330;
  UInt32 local_31c;
  UInt32 local_318;
  UInt32 local_314;
  SInt16 *local_310;
  float quadLeft;
  float quadTop;
  float quadWidth;
  float local_300;
  float local_2fc;
  float local_2f8;
  float srcWidthF;
  float srcHeightF;
  UInt32 local_2ec;
  UInt32 local_2e8;
  UInt32 local_2e4;
  UInt32 local_2e0;
  UInt32 local_2dc;
  SInt32 local_2d8;
  UInt32 local_2c8;
  UInt32 srcXBiased;
  UInt32 local_2c0;
  UInt32 srcYBiased;
  UInt32 local_2b8;
  SInt32 srcRightEdge;
  UInt32 local_2b0;
  SInt32 srcBottomEdge;
  UInt32 local_2a8;
  UInt32 uStack_2a4;
  UInt32 local_2a0;
  UInt32 uStack_29c;
  UInt32 local_298;
  UInt32 uStack_294;
  UInt32 local_290;
  UInt32 uStack_28c;
  SInt64 local_288;
  SInt64 local_280;
  SInt64 local_278;
  SInt64 local_270;
  SInt64 local_268;
  SInt64 local_260;
  SInt64 local_258;
  SInt64 local_250;
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
  float halfHeight;
  float halfWidth;
  float centerY;
  float centerX;
  float chunkLeftF;
  float invCopyWidth;
  float invCopyHeight;
  double srcRightD;
  double srcRightRoundedD;
  double srcTopD;
  double srcLeftD;
  double srcTopRoundedD;
  double srcBottomD;
  double srcLeftRoundedD;
  double srcBottomRoundedD;
  double srcWidthD;
  double srcHeightD;
  double invSrcHeightD;
  double intToFloatBias;
  
  srcRightEdge = srcX + width;
  srcBottomEdge = srcY + height;
  srcXBiased = srcX ^ 0x80000000;
  srcYBiased = srcY ^ 0x80000000;
  local_2c8 = 0x43300000;
  local_2c0 = 0x43300000;
  local_2b8 = 0x43300000;
  rectX = (SInt16)dstX;
  rectHeight = (SInt16)height;
  rectY = (SInt16)dstY;
  rectWidth = (SInt16)width;
  local_2b0 = 0x43300000;
  acceleratorWord0xb74 = M<UInt32>(acceleratorBytes + 0xb74);
  packetBits0xa92 = 0xa92;
  uStack_29c = height;
  local_2a8 = 0x43300000;
  local_2a0 = 0x43300000;
  local_298 = 0x43300000;
  uStack_2a4 = width;
  local_330 = unused12;
  local_310 = &rectX;
  local_290 = 0x43300000;
  local_31c = local_31c | 0xf8000000;
  local_2f8 = FLOAT_0004c370;
  local_318 = 1;
  local_314 = 0;
  srcRightD = (double)CONCAT44d(0x43300000,srcRightEdge) - DOUBLE_0004c3b0;
  quadLeft = FLOAT_0004c370;
  quadTop = FLOAT_0004c370;
  local_2fc = FLOAT_0004c370;
  local_2e0 = 0x3f800000;
  srcTileBits = 0;
  local_2dc = 1;
  local_2d8 = 0;
  srcWidthF = (float)((double)CONCAT44d(0x43300000,srcWidth) - DOUBLE_0004c3b0);
  local_2ec = 0x3f800000;
  local_2e8 = 0x3f800000;
  quadWidth = (float)((double)CONCAT44d(0x43300000,width) - DOUBLE_0004c3b0);
  local_2e4 = 0x3f800000;
  local_300 = (float)((double)CONCAT44d(0x43300000,height) - DOUBLE_0004c3b0);
  srcRightRoundedD = (double)(float)srcRightD;
  srcTopD = (double)CONCAT44d(0x43300000,srcYBiased) - DOUBLE_0004c3a8;
  srcLeftD = (double)CONCAT44d(0x43300000,srcXBiased) - DOUBLE_0004c3a8;
  srcTopRoundedD = (double)(float)srcTopD;
  srcBottomD = (double)CONCAT44d(0x43300000,srcBottomEdge) - DOUBLE_0004c3b0;
  srcLeftRoundedD = (double)(float)srcLeftD;
  srcBottomRoundedD = (double)(float)srcBottomD;
  srcHeightF = (float)((double)CONCAT44d(0x43300000,srcHeight) - DOUBLE_0004c3b0);
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
    iVar30 = (SInt32)(srcLeftRoundedD - DOUBLE_0004c3c8);
    local_280 = (SInt64)iVar30;
    srcLeft = iVar30 + 0x80000000;
  }
  else {
    srcLeft = (UInt32)srcLeftD;
    local_288 = (SInt64)(SInt32)srcLeft;
  }
  if (DOUBLE_0004c3c8 <= srcTopRoundedD) {
    iVar30 = (SInt32)(srcTopRoundedD - DOUBLE_0004c3c8);
    local_270 = (SInt64)iVar30;
    srcTop = iVar30 + 0x80000000;
  }
  else {
    srcTop = (UInt32)srcTopD;
    local_278 = (SInt64)(SInt32)srcTop;
  }
  scissorTopLeftReg = srcLeft & 0x1fff | (srcTop & 0x1fff) << 0xd;
  if (DOUBLE_0004c3c8 <= srcRightRoundedD) {
    iVar30 = (SInt32)(srcRightRoundedD - DOUBLE_0004c3c8);
    local_260 = (SInt64)iVar30;
    srcRight = iVar30 + 0x80000000;
  }
  else {
    srcRight = (UInt32)srcRightD;
    local_268 = (SInt64)(SInt32)srcRight;
  }
  if (DOUBLE_0004c3c8 <= srcBottomRoundedD) {
    iVar30 = (SInt32)(srcBottomRoundedD - DOUBLE_0004c3c8);
    local_250 = (SInt64)iVar30;
    srcBottom = iVar30 + 0x80000000;
  }
  else {
    srcBottom = (UInt32)srcBottomD;
    local_258 = (SInt64)(SInt32)srcBottom;
  }
  srcWidthD = (double)srcWidthF;
  srcHeightD = (double)srcHeightF;
  scissorBottomRightReg = srcRight & 0x1fff | (srcBottom & 0x1fff) << 0xd;
  dVar44 = (double)FLOAT_0004c370;
  packet = cmd + wordCount;
  if (srcWidthD != dVar44) {
    dVar44 = (double)(float)((double)FLOAT_0004c374 / srcWidthD);
  }
  invSrcHeightD = (double)FLOAT_0004c370;
  if (srcHeightD != invSrcHeightD) {
    invSrcHeightD = (double)(float)((double)FLOAT_0004c374 / srcHeightD);
  }
  formatIndexSaved = formatIndex;
  uStack_294 = srcWidth;
  uStack_28c = srcHeight;
  GCopy(packet,(&g_r500_3d_blit_state_packet),0x2f4);
  packet[0xaa] = srcTexturePitchReg;
  packet[0xa0] = srcTextureOffsetReg;
  iVar30 = 0xbd;
  packet[0xa6] = srcTextureSizeReg;
  packet[0xa8] = srcTextureFormatReg;
  packet[0x9c] = dstColorPitchReg;
  packet[0x9a] = dstColorOffsetReg;
  packet[0x8a] = outputFormatReg;
  packet[0xb2] = scissorTopLeftReg;
  packet[0xb3] = scissorBottomRightReg;
  packet[0xb] = acceleratorWord0xb74;
  packet[0xa2] = packetBits0xa92 & 0x1800 | packetBits0xa92 & 0x600 | packet[0xa2] & 0xffffe1ff;
  if (local_2d8 != 0) {
    packet[0x1e] = packet[0x1e] & 0xfffffffc | 2;
  }
  intToFloatBias = DOUBLE_0004c3a8;
  fVar5 = FLOAT_0004c380;
  fVar1 = FLOAT_0004c37c;
  fVar2 = FLOAT_0004c370;
  if (((double)FLOAT_0004c378 < srcWidthD) || ((double)FLOAT_0004c378 < srcHeightD)) {
    if (srcWidthD <= (double)FLOAT_0004c378) {
      quadRight = quadLeft + quadWidth;
      quadBottom = quadTop + local_300;
      srcPerQuadX = FLOAT_0004c370;
      if (quadWidth != FLOAT_0004c370) {
        srcPerQuadX = (float)((double)CONCAT44d(0x43300000,(SInt32)rectWidth ^ 0x80000000) - DOUBLE_0004c3a8)
                / quadWidth;
      }
      scaledQuadLeft = quadLeft * srcPerQuadX;
      srcOffsetX = (float)((double)CONCAT44d(0x43300000,(SInt32)rectX ^ 0x80000000) - DOUBLE_0004c3a8) -
              scaledQuadLeft;
      srcPerQuadY = FLOAT_0004c370;
      if (local_300 != FLOAT_0004c370) {
        srcPerQuadY = (float)((double)CONCAT44d(0x43300000,(SInt32)rectHeight ^ 0x80000000) - DOUBLE_0004c3a8)
                / local_300;
      }
      rectYF = (float)((double)CONCAT44d(0x43300000,(SInt32)rectY ^ 0x80000000) - DOUBLE_0004c3a8);
      srcOffsetY = -(quadTop * srcPerQuadY - rectYF);
      if (flip != 0) {
        srcPerQuadY = -srcPerQuadY;
        srcOffsetY = (float)((double)CONCAT44d(0x43300000,(SInt32)rectY + (SInt32)rectHeight ^ 0x80000000)
                        - DOUBLE_0004c3a8) - (srcOffsetY - rectYF);
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
        fVar11 = srcPerQuadY * quadTop + srcOffsetY;
        srcMaxY = srcPerQuadY * quadBottom + srcOffsetY;
        fVar3 = scaledQuadLeft + srcOffsetX;
        srcMaxX = quadRight * srcPerQuadX + srcOffsetX;
        srcMinY = fVar11;
        if (srcMaxY < fVar11) {
          srcMinY = srcMaxY;
          srcMaxY = fVar11;
        }
        srcMinX = fVar3;
        if (srcMaxX < fVar3) {
          srcMinX = srcMaxX;
          srcMaxX = fVar3;
        }
        uVar25 = (SInt32)srcWidthD & 0xfe00;
        uVar42 = (SInt32)srcMinX - 1;
        uVar42 = (((SInt32)uVar42 >> 9) + (UInt32)((SInt32)uVar42 < 0 && (uVar42 & 0x1ff) != 0)) * 0x200;
        firstColumn = 0;
        if ((-1 < (SInt32)uVar42) && (firstColumn = uVar25, (SInt32)uVar42 <= (SInt32)uVar25)) {
          firstColumn = uVar42 & 0xfe00;
        }
        uVar42 = 0x40;
        if ((0x40 < copyHeight) && (uVar42 = (SInt32)srcHeightD & 0xffc0, (SInt32)(copyHeight - uVar42) < 0x40)) {
          uVar42 = uVar42 - 0x40;
        }
        firstRow = 0;
        uVar25 = (SInt32)srcMinY - 1;
        uVar25 = (((SInt32)uVar25 >> 6) + (UInt32)((SInt32)uVar25 < 0 && (uVar25 & 0x3f) != 0)) * 0x40;
        if ((-1 < (SInt32)uVar25) && (firstRow = uVar42 & 0xffff, (SInt32)uVar25 <= (SInt32)uVar42)) {
          firstRow = uVar25 & 0xffc0;
        }
        uVar42 = 0x200;
        if (0x1ff < firstColumn) {
          uVar42 = firstColumn;
        }
        uVar25 = copyWidth - 1;
        uVar35 = (((SInt32)uVar25 >> 9) + (UInt32)((SInt32)uVar25 < 0 && (uVar25 & 0x1ff) != 0)) * 0x200;
        uVar25 = (UInt32)srcMaxX;
        if ((FLOAT_0004c370 < srcMaxX) &&
           ((float)((double)CONCAT44d(0x43300000,uVar25 ^ 0x80000000) - DOUBLE_0004c3a8) < srcMaxX)) {
          uVar25 = uVar25 + 1;
        }
        if ((SInt32)uVar25 <= (SInt32)uVar35) {
          uVar35 = uVar25;
        }
        columnChunks = 1;
        if ((SInt32)uVar42 < (SInt32)uVar35) {
          columnChunks = (SInt32)((uVar35 - uVar42) + 0xbff) / 0xc00 & 0xff;
        }
        uVar42 = 0x40;
        if (0x3f < firstRow) {
          uVar42 = firstRow;
        }
        uVar35 = copyHeight - 1;
        uVar37 = (((SInt32)uVar35 >> 6) + (UInt32)((SInt32)uVar35 < 0 && (uVar35 & 0x3f) != 0)) * 0x40;
        uVar35 = (UInt32)srcMaxY;
        if ((FLOAT_0004c370 < srcMaxY) &&
           ((float)((double)CONCAT44d(0x43300000,uVar35 ^ 0x80000000) - DOUBLE_0004c3a8) < srcMaxY)) {
          uVar35 = uVar35 + 1;
        }
        if ((SInt32)uVar35 <= (SInt32)uVar37) {
          uVar37 = uVar35;
        }
        rowChunks = 1;
        if ((SInt32)uVar42 < (SInt32)uVar37) {
          rowChunks = (SInt32)((uVar37 - uVar42) + 0xf7f) / 0xf80 & 0xff;
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
          uVar37 = copyHeight - firstRow;
          rowIndex = 0;
          iVar30 = 0;
          chunkPacket = quadPacket;
          uVar39 = firstRow;
          do {
            if (columnChunks != 0) {
              chunkTop = firstRow + iVar30;
              columnWidthLeft = copyWidth - firstColumn;
              iVar22 = 0;
              chunkTopF = (float)((double)CONCAT44d(0x43300000,chunkTop ^ 0x80000000) - DOUBLE_0004c3a8);
              chunkLeft = firstColumn;
              columnsLeft = columnChunks;
              do {
                *chunkPacket = chunkLeft;
                chunkPacket[1] = uVar39;
                uVar26 = columnWidthLeft;
                if ((SInt32)(chunkLeft + 0x1000) <= (SInt32)copyWidth) {
                  uVar26 = 0x1000;
                }
                uVar36 = uVar37;
                if ((SInt32)(chunkTop + 0x1000) <= (SInt32)copyHeight) {
                  uVar36 = 0x1000;
                }
                chunkPacket[2] = uVar26;
                chunkPacket[3] = uVar36;
                fVar4 = srcMinX;
                if (iVar22 != 0) {
                  fVar4 = (float)((double)CONCAT44d(0x43300000,chunkLeft + 0x200 ^ 0x80000000) -
                                 DOUBLE_0004c3a8);
                }
                fVar7 = srcMinY;
                if (rowIndex != 0) {
                  fVar7 = (float)((double)CONCAT44d(0x43300000,chunkTop + 0x40 ^ 0x80000000) -
                                 DOUBLE_0004c3a8);
                }
                fVar3 = srcMaxX;
                if (iVar22 != columnChunks - 1) {
                  fVar3 = (float)((double)CONCAT44d(0x43300000,chunkLeft + 0xe00 ^ 0x80000000) -
                                 DOUBLE_0004c3a8);
                }
                fVar9 = srcMaxY;
                if (rowIndex != rowChunks - 1) {
                  fVar9 = (float)((double)CONCAT44d(0x43300000,chunkTop + 0xfc0 ^ 0x80000000) -
                                 DOUBLE_0004c3a8);
                }
                fVar15 = fVar7;
                if (fVar7 - srcMinY < 0.0) {
                  fVar15 = srcMinY;
                }
                fVar14 = srcMaxY;
                if (fVar9 - srcMaxY < 0.0) {
                  fVar14 = fVar9;
                }
                fVar10 = fVar4;
                if (fVar4 - srcMinX < 0.0) {
                  fVar10 = srcMinX;
                }
                fVar12 = srcMaxX;
                if (fVar3 - srcMaxX < 0.0) {
                  fVar12 = fVar3;
                }
                if (-(fVar7 - srcMinY) < 0.0) {
                  fVar15 = fVar7;
                }
                if (-(fVar9 - srcMaxY) < 0.0) {
                  fVar9 = fVar14;
                }
                if (-(fVar4 - srcMinX) < 0.0) {
                  fVar10 = fVar4;
                }
                if (-(fVar3 - srcMaxX) < 0.0) {
                  fVar3 = fVar12;
                }
                fVar12 = dstPerSrcY * fVar15 + dstPerSrcY * -srcOffsetY;
                fVar16 = dstPerSrcY * fVar9 + dstPerSrcY * -srcOffsetY;
                fVar7 = dstPerSrcX * fVar10 + dstPerSrcX * -srcOffsetX;
                fVar4 = dstPerSrcX * fVar3 + dstPerSrcX * -srcOffsetX;
                fVar14 = fVar9;
                fVar19 = fVar12;
                if (fVar16 < fVar12) {
                  fVar14 = fVar15;
                  fVar15 = fVar9;
                  fVar19 = fVar16;
                  fVar16 = fVar12;
                }
                fVar9 = fVar3;
                fVar12 = fVar7;
                if (fVar4 < fVar7) {
                  fVar9 = fVar10;
                  fVar10 = fVar3;
                  fVar12 = fVar4;
                  fVar4 = fVar7;
                }
                invChunkWidth = FLOAT_0004c370;
                if (uVar26 != 0) {
                  invChunkWidth = FLOAT_0004c374 /
                          (float)((double)CONCAT44d(0x43300000,uVar26 ^ 0x80000000) - DOUBLE_0004c3a8
                                 );
                }
                invChunkHeight = FLOAT_0004c370;
                if (uVar36 != 0) {
                  invChunkHeight = FLOAT_0004c374 /
                          (float)((double)CONCAT44d(0x43300000,uVar36 ^ 0x80000000) - DOUBLE_0004c3a8
                                 );
                }
                uVar26 = chunkLeft ^ 0x80000000;
                iVar22 = iVar22 + 1;
                chunkLeft = chunkLeft + 0xc00;
                columnWidthLeft = columnWidthLeft - 0xc00;
                halfHeight = (fVar16 - fVar19) * FLOAT_0004c37c;
                halfWidth = (fVar4 - fVar12) * FLOAT_0004c37c;
                centerY = (fVar16 + fVar19) * FLOAT_0004c380;
                centerX = (fVar4 + fVar12) * FLOAT_0004c380;
                dVar44 = (double)CONCAT44d(0x43300000,uVar26) - DOUBLE_0004c3a8;
                chunkPacket[4] = 0x31080;
                chunkPacket[6] = FBITS(invChunkHeight * (fVar14 - chunkTopF));
                chunkPacket[8] = FBITS(invChunkHeight * (fVar15 - chunkTopF));
                chunkPacket[0xb] = 0xc0033500;
                chunkPacket[0xc] = 0x10031;
                chunkPacket[0xd] = FBITS(centerX);
                chunkLeftF = (float)dVar44;
                chunkPacket[0xe] = FBITS(centerY);
                chunkPacket[9] = 0x1087;
                chunkPacket[10] = (SInt32)halfWidth << 0x10 | (SInt32)halfHeight;
                chunkPacket[0xf] = 0;
                chunkPacket[7] = FBITS(invChunkWidth * (fVar9 - chunkLeftF));
                chunkPacket[5] = FBITS(invChunkWidth * (fVar10 - chunkLeftF));
                chunkPacket = chunkPacket + 0x10;
                columnsLeft = columnsLeft - 1;
              } while (columnsLeft != 0);
            }
            rowIndex = rowIndex + 1;
            iVar30 = iVar30 + 0xf80;
            uVar37 = uVar37 - 0xf80;
            uVar39 = uVar39 + 0xf80;
          } while (rowIndex != rowChunks);
        }
      }
      else {
        invCopyWidth = FLOAT_0004c370;
        if (copyWidth != 0) {
          invCopyWidth = FLOAT_0004c374 /
                  (float)((double)CONCAT44d(0x43300000,copyWidth ^ 0x80000000) - DOUBLE_0004c3a8);
        }
        invCopyHeight = FLOAT_0004c370;
        if (copyHeight != 0) {
          invCopyHeight = FLOAT_0004c374 /
                  (float)((double)CONCAT44d(0x43300000,copyHeight ^ 0x80000000) - DOUBLE_0004c3a8);
        }
        halfWidth = (quadRight - quadLeft) * FLOAT_0004c37c;
        halfHeight = (quadBottom - quadTop) * FLOAT_0004c37c;
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
        packet[0xc3] = (SInt32)halfWidth << 0x10 | (SInt32)halfHeight;
        packet[200] = 0;
      }
      texturePitchWord = packet[0xaa];
      textureOffsetWord = packet[0xa0];
      uVar25 = textureOffsetWord >> 3 & 3;
      uVar28 = textureOffsetWord >> 2 & 1;
      if (chunkCount != 0) {
        if (chunkCount == 0) {
          iVar30 = 0;
        }
        else {
          iVar22 = (formatIndexSaved & 0xff) * 0x1c;
          iVar30 = 0;
          chunkPacket = quadPacket;
          do {
            if (uVar25 == 0) {
              uVar24 = FormatTableLookup_0x0004d2dc(iVar22);
              iVar23 = 0;
            }
            else {
              uVar24 = FormatTableLookup_0x0004d2dc(iVar22);
              iVar23 = -(uVar24 >> 8 & 3);
            }
            uVar24 = uVar24 >> 0xc & 7;
            iVar23 = (SInt32)*chunkPacket >> ((iVar23 - uVar24) + 5 & 0x3f);
            if (uVar28 == 0) {
              iVar23 = iVar23 << 5;
            }
            else {
              iVar23 = (iVar23 << 0xc) >> 3;
            }
            iVar30 = iVar30 + 1;
            *chunkPacket = 0x1150;
            chunkPacket[1] = (textureOffsetWord & 0xffffffe0) +
                         iVar23 + (((texturePitchWord & 0x3fff) + 1) * chunkPacket[1] << uVar24) & 0xffffffe0 |
                         uVar28 << 2 | uVar25 << 3;
            uVar39 = chunkPacket[2];
            uVar24 = packet[0xa6];
            chunkPacket[2] = 0x1120;
            chunkPacket[3] = (chunkPacket[3] - 1) * 0x800 & 0x3ff800 |
                         uVar39 - 1 & 0x7ff | uVar24 & 0xffc00000;
            chunkPacket = chunkPacket + 0x10;
            chunkCount = chunkCount - 1;
          } while (chunkCount != 0);
          iVar30 = iVar30 * 0x10;
        }
        quadPacket = quadPacket + iVar30;
      }
      else {
        quadPacket = packet + 0xc9;
      }
      iVar22 = (SInt32)quadPacket - (SInt32)packet >> 2;
    }
    else {
      uVar39 = packet[0xa0];
      iVar22 = (formatIndexSaved & 0xff) * 0x1c;
      uVar32 = (SInt32)srcWidthD >> 1 & 0xfffffe00;
      uVar42 = (SInt32)srcWidthD - uVar32;
      uVar34 = uVar32 + 2;
      if ((uVar39 & 0x18) == 0) {
        uVar28 = FormatTableLookup_0x0004d2dc(iVar22);
        iVar22 = 0;
      }
      else {
        uVar28 = FormatTableLookup_0x0004d2dc(iVar22);
        iVar22 = -(uVar28 >> 8 & 3);
      }
      iVar23 = (SInt32)uVar32 >> ((iVar22 - (uVar28 >> 0xc & 7)) + 5 & 0x3f);
      iVar22 = iVar23 << 5;
      if ((uVar39 >> 2 & 1) != 0) {
        iVar22 = (iVar23 << 0xc) >> 3;
      }
      uVar28 = uVar32 + 1 & 0x7ff | packet[0xa6] & 0xfffff800;
      packet[0xa6] = uVar28;
      fVar1 = (float)((double)CONCAT44d(0x43300000,uVar34 ^ 0x80000000) - intToFloatBias);
      if (fVar1 != fVar2) {
        fVar2 = FLOAT_0004c374 / fVar1;
      }
      uVar35 = (UInt32)rectX;
      uVar24 = uVar35 + (SInt32)rectWidth;
      uVar25 = uVar34;
      if ((SInt32)uVar24 < (SInt32)uVar34) {
        uVar25 = uVar24;
      }
      if ((SInt32)uVar34 < (SInt32)uVar24) {
        fVar1 = (float)((double)CONCAT44d(0x43300000,uVar34 - uVar35 ^ 0x80000000) - DOUBLE_0004c3a8)
        ;
      }
      else {
        fVar1 = quadLeft + quadWidth;
      }
      fVar5 = fVar2 * (float)((double)CONCAT44d(0x43300000,uVar25 ^ 0x80000000) - DOUBLE_0004c3a8);
      fVar2 = fVar2 * (float)((double)CONCAT44d(0x43300000,uVar35 ^ 0x80000000) - DOUBLE_0004c3a8);
      if (flip == 0) {
        uVar25 = (UInt32)rectY;
        uVar34 = uVar25 + (SInt32)rectHeight;
      }
      else {
        uVar34 = (UInt32)rectY;
        uVar25 = uVar34 + (SInt32)rectHeight;
      }
      dVar44 = (double)CONCAT44d(0x43300000,uVar25 ^ 0x80000000) - DOUBLE_0004c3a8;
      dVar45 = (double)CONCAT44d(0x43300000,uVar34 ^ 0x80000000) - DOUBLE_0004c3a8;
      local_300 = quadTop + local_300;
      if (fVar2 < fVar5) {
        fVar6 = (local_300 - quadTop) * FLOAT_0004c37c;
        fVar4 = (fVar1 - quadLeft) * FLOAT_0004c37c;
        fVar1 = (fVar1 + quadLeft) * FLOAT_0004c380;
        fVar7 = (quadTop + local_300) * FLOAT_0004c380;
        packet[0xbd] = 0x31080;
        packet[0xbe] = FBITS(fVar2);
        packet[0xc2] = 0x1087;
        packet[0xbf] = FBITS((float)(invSrcHeightD * (double)(float)dVar45));
        packet[0xc0] = FBITS(fVar5);
        packet[0xc1] = FBITS((float)(invSrcHeightD * (double)(float)dVar44));
        packet[0xc4] = 0xc0033500;
        packet[0xc5] = 0x10031;
        packet[0xc6] = FBITS(fVar1);
        packet[199] = FBITS(fVar7);
        packet[200] = 0;
        packet[0xc3] = (SInt32)fVar4 << 0x10 | (SInt32)fVar6;
        iVar30 = 0xc9;
        uVar39 = packet[0xa0];
        uVar28 = packet[0xa6];
      }
      packet[iVar30] = 0x1150;
      packet[iVar30 + 1] = uVar39 + iVar22;
      packet[iVar30 + 2] = 0x1120;
      iVar23 = iVar30 + 4;
      packet[iVar30 + 3] = uVar42 - 1 & 0x7ff | uVar28 & 0xfffff800;
      fVar2 = (float)((double)CONCAT44d(0x43300000,uVar42 ^ 0x80000000) - DOUBLE_0004c3a8);
      fVar1 = FLOAT_0004c370;
      if (fVar2 != FLOAT_0004c370) {
        fVar1 = FLOAT_0004c374 / fVar2;
      }
      uVar42 = (UInt32)rectX;
      uVar34 = uVar32;
      if ((SInt32)uVar42 > (SInt32)uVar32) {
        uVar34 = uVar42;
      }
      fVar2 = quadLeft;
      if ((SInt32)uVar42 <= (SInt32)uVar32) {
        fVar2 = (float)((double)CONCAT44d(0x43300000,uVar32 - uVar42 ^ 0x80000000) - DOUBLE_0004c3a8)
        ;
      }
      fVar5 = fVar1 * ((float)((double)CONCAT44d(0x43300000,uVar34 ^ 0x80000000) - DOUBLE_0004c3a8) -
                      (float)((double)CONCAT44d(0x43300000,uVar32 ^ 0x80000000) - DOUBLE_0004c3a8));
      fVar1 = fVar1 * (float)((double)CONCAT44d(0x43300000,
                                               (uVar42 + (SInt32)rectWidth) - uVar32 ^ 0x80000000) -
                             DOUBLE_0004c3a8);
      if (flip == 0) {
        uVar34 = (UInt32)rectY;
        uVar32 = uVar34 + (SInt32)rectHeight;
      }
      else {
        uVar32 = (UInt32)rectY;
        uVar34 = uVar32 + (SInt32)rectHeight;
      }
      dVar44 = (double)CONCAT44d(0x43300000,uVar34 ^ 0x80000000) - DOUBLE_0004c3a8;
      dVar45 = (double)CONCAT44d(0x43300000,uVar32 ^ 0x80000000) - DOUBLE_0004c3a8;
      iVar22 = iVar23;
      if (fVar5 < fVar1) {
        fVar4 = ((quadLeft + quadWidth) - fVar2) * FLOAT_0004c37c;
        fVar6 = (local_300 - quadTop) * FLOAT_0004c37c;
        iVar22 = iVar23 * 4 + 0x30 >> 2;
        fVar7 = (quadTop + local_300) * FLOAT_0004c380;
        fVar2 = (fVar2 + quadLeft + quadWidth) * FLOAT_0004c380;
        packet[iVar23] = 0x31080;
        packet[iVar30 + 5] = FBITS(fVar5);
        packet[iVar30 + 6] = FBITS((float)(invSrcHeightD * (double)(float)dVar45));
        packet[iVar30 + 7] = FBITS(fVar1);
        packet[iVar30 + 9] = 0x1087;
        packet[iVar30 + 8] = FBITS((float)(invSrcHeightD * (double)(float)dVar44));
        packet[iVar30 + 0xb] = 0xc0033500;
        packet[iVar30 + 0xc] = 0x10031;
        packet[iVar30 + 0xd] = FBITS(fVar2);
        packet[iVar30 + 0xe] = FBITS(fVar7);
        packet[iVar30 + 0xf] = 0;
        packet[iVar30 + 10] = (SInt32)fVar4 << 0x10 | (SInt32)fVar6;
      }
    }
  }
  else {
    dVar45 = (double)CONCAT44d(0x43300000,(SInt32)rectX ^ 0x80000000) - DOUBLE_0004c3a8;
    dVar46 = (double)CONCAT44d(0x43300000,(SInt32)rectX + (SInt32)rectWidth ^ 0x80000000) -
             DOUBLE_0004c3a8;
    if (flip == 0) {
      uVar34 = (UInt32)rectY;
      uVar32 = uVar34 + (SInt32)rectHeight;
    }
    else {
      uVar32 = (UInt32)rectY;
      uVar34 = uVar32 + (SInt32)rectHeight;
    }
    dVar48 = (double)CONCAT44d(0x43300000,uVar34 ^ 0x80000000) - DOUBLE_0004c3a8;
    dVar49 = (double)CONCAT44d(0x43300000,uVar32 ^ 0x80000000) - DOUBLE_0004c3a8;
    packet[0xbd] = 0x31080;
    packet[0xbe] = FBITS((float)(dVar44 * (double)(float)dVar45));
    packet[0xbf] = FBITS((float)(invSrcHeightD * (double)(float)dVar49));
    packet[0xc0] = FBITS((float)(dVar44 * (double)(float)dVar46));
    packet[0xc1] = FBITS((float)(invSrcHeightD * (double)(float)dVar48));
    packet[0xc2] = 0x1087;
    packet[0xc4] = 0xc0033500;
    packet[0xc5] = 0x10031;
    packet[0xc6] = FBITS((quadLeft + quadLeft + quadWidth) * FLOAT_0004c380);
    packet[199] = FBITS((quadTop + quadTop + local_300) * FLOAT_0004c380);
    packet[200] = 0;
    packet[0xc3] =
         (SInt32)(((quadLeft + quadWidth) - quadLeft) * FLOAT_0004c37c) << 0x10 |
         (SInt32)(((quadTop + local_300) - quadTop) * FLOAT_0004c37c);
    iVar22 = 0xc9;
  }
  packet[iVar22] = 0x1393;
  packet[iVar22 + 1] = 10;
  iVar30 = (SInt32)packet + ((iVar22 + 2) * 4 - (SInt32)cmd) >> 2;
  cmd[iVar30] = 0x1393;
  cmd[iVar30 + 1] = 10;
  cmd[iVar30 + 2] = 0x5c8;
  cmd[iVar30 + 3] = 0x20000;
  return iVar30 + 4;
}
