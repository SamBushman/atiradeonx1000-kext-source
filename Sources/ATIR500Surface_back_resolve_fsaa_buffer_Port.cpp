/*
 * ATIR500Surface_back_resolve_fsaa_buffer_Port.cpp
 *
 * ATIR500Surface::back_resolve_fsaa_buffer (real addr 0x44880, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x44880 */
void *ATIR500Surface::back_resolve_fsaa_buffer(UInt32 unusedParam1, UInt32 formatCode, UInt32*packet) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool untiled;
  float scaledW;
  float scaledH;
  float lit370;
  float heightF;
  UInt8 formatIndex;
  UInt16 heightField;
  UInt16 widthField;
  UInt32 fieldD;
  float lit37c;
  float heightScaled;
  float lit380;
  double doubleBias;
  UInt32 savedWord;
  SInt32 formatOffset;
  UInt32 minPitch;
  UInt32 fieldB;
  UInt32 widthDiv;
  UInt32 lastY;
  UInt32 pitchPerDegree;
  UInt32 fieldC;
  UInt32 fieldA;
  UInt32 lastX;
  UInt32 formatBitsB;
  UInt32 tilingBits;
  SInt32 formatBuffer;
  SInt32 fixedBuffer;
  
  formatBuffer = M<SInt32>(self + formatCode * 4 + 0xb70);
  fixedBuffer = M<SInt32>(self + kIOATIR500Surface_fixedSurfaceBuffer);
  GH_memcpy(packet,&g_r500_3d_blit_state_packet,0x2f4);
  pitchPerDegree = 0;
  packet[0xb] = M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0xb74);
  formatOffset = (UInt32)M<UInt8>(fixedBuffer + 0x3a) * 0x1c;
  packet[0x9a] =
       (UInt32)M<UInt16>(fixedBuffer + 0x20) * M<SInt32>(fixedBuffer + 0x40) + M<SInt32>(fixedBuffer + 8) &
       0xffffffe0;
  if ((M<UInt32>(fixedBuffer + 0x3c) & 0xf00000) != 0) {
    pitchPerDegree = (UInt32)M<UInt16>(fixedBuffer + 0x14) / (M<UInt32>(fixedBuffer + 0x3c) >> 0x14 & 0xf);
  }
  minPitch = 0x20 / M<UInt16>(fixedBuffer + 0x16);
  if (minPitch <= pitchPerDegree) {
    minPitch = pitchPerDegree;
  }
  savedWord = packet[0x8a];
  packet[0x9c] =
       minPitch & 0x3ffe | (M<UInt8>(fixedBuffer + 0x38) & 1) << 0x10 |
       (M<UInt8>(fixedBuffer + 0x38) & 6) << 0x10 | (M<UInt8>(fixedBuffer + 0x39) & 3) << 0x13 |
       FormatTableLookup_0x0004d2e0((UInt32)M<UInt8>(fixedBuffer + 0x3a) * 0x1c) >> 1 & 0x1e00000;
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
  if (((M<UInt32>(fixedBuffer + 0x3c) & 0xf00000) == 0) ||
     (widthDiv = (UInt32)M<UInt16>(fixedBuffer + 0x1c) / (M<UInt32>(fixedBuffer + 0x3c) >> 0x14 & 0xf),
     lastX = widthDiv - 1, widthDiv == 0)) {
    lastX = 0;
  }
  lastY = 0;
  if (M<UInt16>(fixedBuffer + 0x1e) != 0) {
    lastY = M<UInt16>(fixedBuffer + 0x1e) - 1;
  }
  packet[0xb3] = lastX & 0x1fff | (lastY & 0x1fff) << 0xd;
  formatIndex = M<UInt8>(formatBuffer + 0x3a);
  packet[0xa0] =
       (M<UInt8>(formatBuffer + 0x38) & 7) << 2 |
       (UInt32)M<UInt16>(formatBuffer + 0x20) * M<SInt32>(formatBuffer + 0x40) + M<SInt32>(formatBuffer + 8) &
       0xffffffe0;
  if (((M<UInt32>(formatBuffer + 0x3c) & 0xf00000) == 0) ||
     (widthDiv = (UInt32)M<UInt16>(formatBuffer + 0x1c) / (M<UInt32>(formatBuffer + 0x3c) >> 0x14 & 0xf),
     lastX = widthDiv - 1, widthDiv == 0)) {
    lastX = 0;
  }
  lastY = 0;
  if (M<UInt16>(formatBuffer + 0x1e) != 0) {
    lastY = M<UInt16>(formatBuffer + 0x1e) - 1;
  }
  packet[0xa6] = lastX & 0x7ff | (lastY & 0x7ff) << 0xb | 0x80000000;
  formatBitsB = FormatTableLookup_0x0004d2e4((UInt32)formatIndex * 0x1c);
  packet[0xa8] =
       formatBitsB >> 0x13 & 0x1f | (formatBitsB & 0x40) << 0x10 | formatBitsB >> 7 & 0xe00 | formatBitsB >> 1 & 0x7000
       | (formatBitsB & 0x1c00) << 5 | (formatBitsB & 0x380) << 0xb;
  tilingBits = M<UInt32>(formatBuffer + 0x3c);
  untiled = (tilingBits & 0xf00000) == 0;
  if (untiled) {
    pitchPerDegree = 0;
  }
  else {
    pitchPerDegree = (UInt32)M<UInt16>(formatBuffer + 0x14) / (tilingBits >> 0x14 & 0xf);
  }
  minPitch = 0x20 / M<UInt16>(formatBuffer + 0x16);
  if (minPitch <= pitchPerDegree) {
    minPitch = pitchPerDegree;
  }
  if ((untiled) ||
     (widthDiv = (UInt32)M<UInt16>(formatBuffer + 0x1c) / (lastX >> 0x14 & 0xf), lastX = widthDiv - 1,
     widthDiv == 0)) {
    lastX = 0;
  }
  lastY = 0;
  if (M<UInt16>(formatBuffer + 0x1e) != 0) {
    lastY = M<UInt16>(formatBuffer + 0x1e) - 1;
  }
  packet[0xaa] = minPitch - 1 & 0x3fff | (lastX & 0x800) << 4 | (lastY & 0x800) << 5;
  if ((M<UInt32>(self + kIOATIR500Surface_modeBits) & 0x700000) != 0) {
    packet[0xf] = 0xc0001000;
  }
  doubleBias = DOUBLE_0004c3a8;
  lit380 = FLOAT_0004c380;
  lit37c = FLOAT_0004c37c;
  lit370 = FLOAT_0004c370;
  tilingBits = M<UInt32>(fixedBuffer + 0x3c);
  if ((tilingBits & 0xf00000) == 0) {
    heightField = M<UInt16>(fixedBuffer + 0x1e);
    packet[0xc5] = 0x10031;
    packet[0xc0] = 0x3f800000;
    packet[0xbd] = 0x31080;
    packet[200] = 0;
    packet[0xbf] = 0x3f800000;
    lit370 = FLOAT_0004c370;
    packet[0xc2] = 0x1087;
    doubleBias = DOUBLE_0004c3b0;
    packet[0xc4] = 0xc0033500;
    packet[0xbe] = FBITS(lit370);
    packet[0xc1] = FBITS(lit370);
    packet[0xc6] = FBITS(lit370);
    heightF = (float)((double)CONCAT44d(0x43300000,(UInt32)heightField) - doubleBias);
    heightScaled = heightF * FLOAT_0004c37c;
    packet[199] = FBITS(((heightF + lit370) * FLOAT_0004c380));
    packet[0xc3] = (SInt32)heightScaled;
  }
  else {
    widthField = M<UInt16>(fixedBuffer + 0x1c);
    heightField = M<UInt16>(fixedBuffer + 0x1e);
    packet[0xbd] = 0x31080;
    packet[0xc0] = 0x3f800000;
    packet[0xc2] = 0x1087;
    packet[0xc4] = 0xc0033500;
    packet[0xc5] = 0x10031;
    packet[200] = 0;
    packet[0xbe] = FBITS(lit370);
    packet[0xbf] = 0x3f800000;
    packet[0xc1] = FBITS(lit370);
    scaledW = (float)((double)CONCAT44d(0x43300000,(UInt32)widthField / (tilingBits >> 0x14 & 0xf) ^ 0x80000000) -
                   doubleBias);
    scaledH = (float)((double)CONCAT44d(0x43300000,(UInt32)heightField) - DOUBLE_0004c3b0);
    packet[0xc6] = FBITS(((scaledW + lit370) * lit380));
    packet[199] = FBITS(((scaledH + lit370) * lit380));
    packet[0xc3] = (SInt32)(scaledW * lit37c) << 0x10 | (SInt32)(scaledH * lit37c);
  }
  packet[0xc9] = 0x1393;
  packet[0xca] = 10;
  M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x78) = 0;
  return (void *)(packet + 0xcb);
}
