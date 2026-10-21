/*
 * ATIR500Surface_resolve_fsaa_buffer_Port.cpp
 *
 * ATIR500Surface::resolve_fsaa_buffer (real addr 0x43e60, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_memcpy(...) asm("_memcpy");


/* real addr 0x43e60 */
void* ATIR500Surface::resolve_fsaa_buffer(UInt32 surfaceIndex, UInt32 formatCode, UInt32*packet, bool clearFlag, SInt32 x, SInt32 y, SInt32 width, SInt32 height) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool untiled;
  float xLeftF;
  float xRightF;
  float invWidthF;
  float yBottomF;
  float lit380;
  float yTopF;
  UInt8 fixedFormat;
  UInt16 formatPitchPixels;
  UInt32 fieldD;
  float invHeightF;
  float lit37c;
  SInt32 formatOffset;
  SInt32 tileAlignment;
  UInt32 savedWord;
  UInt32 minPitch;
  UInt32 fieldB;
  UInt32 widthDiv;
  UInt32 lastY;
  UInt32 pitchPerDegree;
  UInt32 fieldC;
  UInt32 hzBlockOffset;
  UInt32 fieldA;
  UInt32 lastX;
  UInt32 formatBitsB;
  UInt32 tilingBits;
  UInt32 samplesEntry;
  UInt32 formatGpuBase;
  UInt32 blockCount;
  UInt32 alignedPitch;
  UInt32 fixedWord30;
  SInt32 formatBuffer;
  SInt32 fixedBuffer;
  UInt32 *nextCursor;
  UInt32 *outCursor;
  
  fixedBuffer = M<SInt32>(self + kIOATIR500Surface_fixedSurfaceBuffer);
  formatBuffer = M<SInt32>(self + formatCode * 4 + 0xb70);
  GH_memcpy(packet,&g_r500_3d_blit_state_packet,0x2f4);
  packet[0xb] = M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0xb74);
  if ((M<UInt32>(self + kIOATIR500Surface_modeBits) & 0x700000) == 0) {
    pitchPerDegree = 0;
    formatOffset = (UInt32)M<UInt8>(formatBuffer + 0x3a) * 0x1c;
    packet[0x9a] =
         (UInt32)M<UInt16>(formatBuffer + 0x20) * M<SInt32>(formatBuffer + 0x40) + M<SInt32>(formatBuffer + 8) &
         0xffffffe0;
    if ((M<UInt32>(formatBuffer + 0x3c) & 0xf00000) != 0) {
      pitchPerDegree = (SInt32)M<UInt16>(formatBuffer + 0x14) / (SInt32)(M<UInt32>(formatBuffer + 0x3c) >> 0x14 & 0xf);
    }
    minPitch = 0x20 / M<UInt16>(formatBuffer + 0x16);
    if (minPitch <= pitchPerDegree) {
      minPitch = pitchPerDegree;
    }
    savedWord = packet[0x8a];
    packet[0x9c] =
         minPitch & 0x3ffe | (M<UInt8>(formatBuffer + 0x38) & 1) << 0x10 |
         (M<UInt8>(formatBuffer + 0x38) & 6) << 0x10 | (M<UInt8>(formatBuffer + 0x39) & 3) << 0x13 |
         FormatTableLookup_0x0004d2e0((UInt32)M<UInt8>(formatBuffer + 0x3a) * 0x1c) >> 1 & 0x1e00000;
    fieldA = FormatTableLookup_0x0004d2e0(formatOffset) >> 0x11 & 0x1f;
    packet[0x8a] = fieldA | savedWord & 0xffffffe0;
    fieldB = FormatTableLookup_0x0004d2e0(formatOffset) >> 7 & 0x300;
    packet[0x8a] = fieldB | fieldA | savedWord & 0xfffffce0;
    fieldC = FormatTableLookup_0x0004d2e0(formatOffset) >> 3 & 0xc00;
    packet[0x8a] = fieldC | fieldB | fieldA | savedWord & 0xfffff0e0;
    fieldD = (FormatTableLookup_0x0004d2e0(formatOffset) & 0x1800) << 1;
    packet[0x8a] = fieldD | fieldC | fieldB | fieldA | savedWord & 0xffffc0e0;
    packet[0x8a] =
         (FormatTableLookup_0x0004d2e0(formatOffset) & 0x600) << 5 |
         fieldD | fieldC | fieldB | fieldA | savedWord & 0xffff00e0;
    if (((M<UInt32>(formatBuffer + 0x3c) & 0xf00000) == 0) ||
       (widthDiv = (SInt32)M<UInt16>(formatBuffer + 0x1c) / (SInt32)(M<UInt32>(formatBuffer + 0x3c) >> 0x14 & 0xf),
       lastX = widthDiv - 1, widthDiv == 0)) {
      lastX = 0;
    }
    lastY = 0;
    if (M<UInt16>(formatBuffer + 0x1e) != 0) {
      lastY = M<UInt16>(formatBuffer + 0x1e) - 1;
    }
    packet[0xb3] = lastX & 0x1fff | (lastY & 0x1fff) << 0xd;
    fixedFormat = M<UInt8>(fixedBuffer + 0x3a);
    packet[0xa0] =
         (M<UInt8>(fixedBuffer + 0x38) & 7) << 2 |
         (UInt32)M<UInt16>(fixedBuffer + 0x20) * M<SInt32>(fixedBuffer + 0x40) + M<SInt32>(fixedBuffer + 8) &
         0xffffffe0;
    if (((M<UInt32>(fixedBuffer + 0x3c) & 0xf00000) == 0) ||
       (widthDiv = (SInt32)M<UInt16>(fixedBuffer + 0x1c) / (SInt32)(M<UInt32>(fixedBuffer + 0x3c) >> 0x14 & 0xf),
       lastX = widthDiv - 1, widthDiv == 0)) {
      lastX = 0;
    }
    lastY = 0;
    if (M<UInt16>(fixedBuffer + 0x1e) != 0) {
      lastY = M<UInt16>(fixedBuffer + 0x1e) - 1;
    }
    packet[0xa6] = lastX & 0x7ff | (lastY & 0x7ff) << 0xb | 0x80000000;
    formatBitsB = FormatTableLookup_0x0004d2e4((UInt32)fixedFormat * 0x1c);
    packet[0xa8] =
         formatBitsB >> 0x13 & 0x1f | (formatBitsB & 0x40) << 0x10 | formatBitsB >> 7 & 0xe00 |
         formatBitsB >> 1 & 0x7000 | (formatBitsB & 0x1c00) << 5 | (formatBitsB & 0x380) << 0xb;
    tilingBits = M<UInt32>(fixedBuffer + 0x3c);
    untiled = (tilingBits & 0xf00000) == 0;
    if (untiled) {
      pitchPerDegree = 0;
    }
    else {
      pitchPerDegree = (SInt32)M<UInt16>(fixedBuffer + 0x14) / (SInt32)(tilingBits >> 0x14 & 0xf);
    }
    minPitch = 0x20 / M<UInt16>(fixedBuffer + 0x16);
    if (minPitch <= pitchPerDegree) {
      minPitch = pitchPerDegree;
    }
    if ((untiled) ||
       (widthDiv = (SInt32)M<UInt16>(fixedBuffer + 0x1c) / (SInt32)(tilingBits >> 0x14 & 0xf), lastX = widthDiv - 1,
       widthDiv == 0)) {
      lastX = 0;
    }
    lastY = 0;
    if (M<UInt16>(fixedBuffer + 0x1e) != 0) {
      lastY = M<UInt16>(fixedBuffer + 0x1e) - 1;
    }
    packet[0xaa] = minPitch - 1 & 0x3fff | (lastX & 0x800) << 4 | (lastY & 0x800) << 5;
    packet[0x1e] = packet[0x1e] & 0xfffffffc | 2;
    packet[0xa2] = packet[0xa2] & 0xffffe1ff | 0x1400;
    lit380 = FLOAT_0004c380;
    lit37c = FLOAT_0004c37c;
    invWidthF = FLOAT_0004c370;
    if (M<UInt16>(formatBuffer + 0x1c) != 0) {
      invWidthF = FLOAT_0004c374 /
              (float)(SInt32)(M<UInt16>(formatBuffer + 0x1c));
    }
    invHeightF = FLOAT_0004c370;
    if (M<UInt16>(formatBuffer + 0x1e) != 0) {
      invHeightF = FLOAT_0004c374 /
              (float)(SInt32)(M<UInt16>(formatBuffer + 0x1e));
    }
    outCursor = packet + 0xcb;
    packet[0xc2] = 0x1087;
    packet[0xc4] = 0xc0033500;
    packet[0xbd] = 0x31080;
    packet[200] = 0;
    packet[0xc5] = 0x10031;
    packet[0xc9] = 0x1393;
    packet[0xca] = 10;
    xLeftF = (float)(SInt32)(x);
    xRightF = (float)(SInt32)(x + width);
    packet[0xc0] = FBITS((invWidthF * xRightF));
    packet[0xbe] = FBITS((invWidthF * xLeftF));
    packet[0xc6] = FBITS(((xLeftF + xRightF) * lit380));
    yBottomF = (float)(SInt32)(y + height);
    yTopF = (float)(SInt32)(y);
    packet[0xbf] = FBITS((invHeightF * yBottomF));
    packet[0xc1] = FBITS((invHeightF * yTopF));
    packet[199] = FBITS(((yTopF + yBottomF) * lit380));
    packet[0xc3] = (SInt32)((xRightF - xLeftF) * lit37c) << 0x10 | (SInt32)((yBottomF - yTopF) * lit37c);
    goto finishResolve;
  }
  pitchPerDegree = 0;
  packet[0xa9] = 0xc0001000;
  packet[0x9d] = 0xc0001000;
  packet[0x9f] = 0xc0001000;
  packet[0xa1] = 0xc0001000;
  packet[0xa3] = 0xc0001000;
  packet[0xa5] = 0xc0001000;
  packet[0xa7] = 0xc0001000;
  packet[0x9a] = M<UInt32>(fixedBuffer + 8);
  if ((M<UInt32>(fixedBuffer + 0x3c) & 0xf00000) != 0) {
    pitchPerDegree = (SInt32)M<UInt16>(fixedBuffer + 0x14) / (SInt32)(M<UInt32>(fixedBuffer + 0x3c) >> 0x14 & 0xf);
  }
  minPitch = 0x20 / M<UInt16>(fixedBuffer + 0x16);
  if (minPitch <= pitchPerDegree) {
    minPitch = pitchPerDegree;
  }
  packet[0x9c] =
       minPitch & 0x3ffe | (M<UInt8>(formatBuffer + 0x38) & 1) << 0x10 |
       (M<UInt8>(formatBuffer + 0x38) & 6) << 0x10 | (M<UInt8>(fixedBuffer + 0x39) & 3) << 0x13 |
       FormatTableLookup_0x0004d2e0((UInt32)M<UInt8>(fixedBuffer + 0x3a) * 0x1c) >> 1 & 0x1e00000;
  if (((M<UInt32>(fixedBuffer + 0x28) & 0x3ff00000) == 0x3ff00000) || (M<char>(fixedBuffer + 0x36) == '\0'))
  {
    packet[0x20] = 0;
  }
  else {
    packet[0x20] = 0x600;
  }
  tilingBits = M<UInt32>(fixedBuffer + 0x3c);
  packet[0x3c] = 0;
  packet[0x42] = packet[0x4e];
  packet[0x26] = 0;
  packet[0x44] = packet[0x50];
  packet[0x46] = packet[0x52];
  samplesEntry = SamplesTableLookup(tilingBits >> 0x12 & 0x3c);
  packet[0x48] = packet[0x54];
  packet[0x4a] = packet[0x56];
  packet[0x4c] = packet[0x58];
  packet[0x7e] = 0;
  packet[0x86] = 0;
  packet[0x24] = 3;
  packet[0x84] = 0;
  packet[0x88] = 0;
  packet[0x82] = 0;
  packet[0x92] = 0x80;
  packet[0x98] = 0x50000000;
  packet[0x10] = (samplesEntry & 3) << 1 | 1;
  packet[0x96] = 0x10000;
  if (((M<UInt32>(formatBuffer + 0x3c) & 0xf00000) == 0) ||
     (widthDiv = (SInt32)M<UInt16>(formatBuffer + 0x1c) / (SInt32)(M<UInt32>(formatBuffer + 0x3c) >> 0x14 & 0xf),
     lastX = widthDiv - 1, widthDiv == 0)) {
    lastX = 0;
  }
  lastY = 0;
  if (M<UInt16>(formatBuffer + 0x1e) != 0) {
    lastY = M<UInt16>(formatBuffer + 0x1e) - 1;
  }
  packet[0xb3] = lastX & 0x1fff | (lastY & 0x1fff) << 0xd;
  hzBlockOffset = HZMEM_GetBlockOffset
                     ((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x870)),M<UInt32>(fixedBuffer + 0x28),2);
  pitchPerDegree = 0;
  if ((M<UInt32>(fixedBuffer + 0x3c) & 0xf00000) != 0) {
    pitchPerDegree = (SInt32)M<UInt16>(fixedBuffer + 0x14) / (SInt32)(M<UInt32>(fixedBuffer + 0x3c) >> 0x14 & 0xf);
  }
  minPitch = 0x20 / M<UInt16>(fixedBuffer + 0x16);
  if (minPitch <= pitchPerDegree) {
    minPitch = pitchPerDegree;
  }
  tileAlignment = 0x20;
  if (M<SInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0xb98) == 4) {
roundTilePitch:
    alignedPitch = tileAlignment * ((SInt32)(tileAlignment + minPitch + -1) / tileAlignment);
  }
  else {
    tileAlignment = M<SInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0xb98) << 4;
    alignedPitch = 0;
    if (tileAlignment != 0) goto roundTilePitch;
  }
  packet[0xc0] = alignedPitch;
  packet[0xbe] = hzBlockOffset;
  packet[0xbd] = 0x1395;
  packet[0xbf] = 0x1399;
  packet[0xc1] = 0x13a2;
  packet[0xc2] = 5;
  packet[0xc3] = 0x13a0;
  outCursor = packet + 0xc9;
  formatGpuBase = M<UInt32>(formatBuffer + 8);
  packet[0xc5] = 0x13a1;
  packet[0xc4] = formatGpuBase & 0xffffffe0;
  formatPitchPixels = M<UInt16>(formatBuffer + 0x14);
  packet[199] = 0x1087;
  packet[200] = width * 0x60000 | height * 6 & 0xffffU;
  packet[0xc6] = formatPitchPixels & 0x3ffe;
  if ((((M<UInt32>(fixedBuffer + 0x28) & 0x3ff00000) != 0x3ff00000) && (M<char>(fixedBuffer + 0x36) != '\0')
      ) && (M<UInt8>(formatBuffer + 0x38) < 2)) {
    outCursor = packet + 0xcb;
    packet[0xc9] = 0x1392;
    packet[0xca] = 0x400300;
  }
  lit380 = FLOAT_0004c380;
  nextCursor = outCursor + 0xb;
  *outCursor = 0xc0033500;
  outCursor[1] = 0x10031;
  outCursor[2] = FBITS(((float)(SInt32)(width + x * 2) * lit380));
  outCursor[4] = 0;
  outCursor[3] = FBITS(((float)(SInt32)(height + y * 2) * lit380));
  outCursor[5] = 0x1393;
  outCursor[6] = 10;
  outCursor[7] = 0x13c6;
  outCursor[8] = 3;
  outCursor[9] = 0x13a2;
  outCursor[10] = 0;
  if ((((M<UInt32>(fixedBuffer + 0x28) & 0x3ff00000) != 0x3ff00000) && (M<char>(fixedBuffer + 0x36) != '\0')
      ) && (M<UInt8>(formatBuffer + 0x38) < 2)) {
    nextCursor = outCursor + 0xd;
    outCursor[0xb] = 0x1392;
    outCursor[0xc] = 0x300;
  }
  outCursor = nextCursor;
  if ((((UInt32)clearFlag) != 0) &&
     ((M<UInt32>(fixedBuffer + 0x28) & 0x3ff00000) != 0x3ff00000)) {
    blockCount = HZMEM_GetBlockCount((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x870)),
                                 M<UInt32>(fixedBuffer + 0x28),2);
    *nextCursor = 0x1385;
    outCursor = nextCursor + 6;
    fixedWord30 = M<UInt32>(fixedBuffer + 0x30);
    nextCursor[2] = 0xc0023800;
    nextCursor[3] = hzBlockOffset;
    nextCursor[1] = fixedWord30;
    formatBuffer = M<SInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0xb98);
    nextCursor[5] = 0;
    nextCursor[4] = blockCount / (UInt32)(formatBuffer << 4);
    if (surfaceIndex == 9) {
      nextCursor[6] = 0x1380;
      nextCursor[7] = 0x600;
      outCursor = nextCursor + 8;
    }
    M<UInt8>(fixedBuffer + 0x36) = 1;
  }
finishResolve:
  M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x78) = 0;
  return outCursor;
}
