/*
 * ATIR500GLContext_process_kATIGLStreamFastClearColor_Port.cpp
 *
 * ATIR500GLContext::process_kATIGLStreamFastClearColor (real addr 0x292a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x292a0 */
void ATIR500GLContext::process_kATIGLStreamFastClearColor(UInt32*record) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 colorTilingByte0;
  UInt16 basePitch;
  UInt32 colorPitchWord;
  UInt32 uVar4;
  SInt32 colorBuffer;
  UInt32 depthRowTiles;
  SInt32 lodBlendWeight;
  SInt32 formatByteOffset;
  SInt32 iVar9;
  SInt32 mipOffset;
  SInt32 surface;
  SInt32 iVar10;
  SInt32 gpuBaseAddress;
  UInt32 uVar12;
  SInt32 depthRecord;
  UInt32 uVar14;
  UInt32 uVar15;
  UInt32 uVar16;
  UInt32 clearWordIndex;
  SInt32 depthBuffer;
  
  clearWordIndex = record[1];
  surface = M<SInt32>(self + kIOATIR500GLContext_boundSurface);
  uVar16 = M<UInt32>(self + kIOATIR500GLContext_mipLevel);
  lodBlendWeight = M<SInt32>(self + kIOATIR500GLContext_surfaceIndex);
  colorBuffer = M<SInt32>((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) * 4 + surface + kIOATIR500Surface_attachmentBuffers);
  depthRecord = (UInt32)M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) * 0x78 + surface;
  depthBuffer = M<SInt32>((UInt32)M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) * 4 + surface + kIOATIR500Surface_attachmentBuffers);
  iVar10 = uVar16 * 4 + colorBuffer;
  basePitch = M<UInt16>(colorBuffer + 0x20);
  uVar14 = 0x10;
  mipOffset = M<SInt32>(iVar10 + 0x40);
  iVar10 = M<SInt32>(iVar10 + 0x44);
  gpuBaseAddress = M<SInt32>(colorBuffer + 8);
  formatByteOffset = (SInt32)(UInt32)M<UInt16>(colorBuffer + 0x1e) >> (uVar16 & 0x3f);
  if (formatByteOffset != 0) {
    uVar14 = formatByteOffset + 0xf;
  }
  uVar12 = 0;
  formatByteOffset = (UInt32)M<UInt8>(colorBuffer + 0x3a) * 0x1c;
  if ((M<UInt32>(colorBuffer + 0x3c) & 0xf00000) != 0) {
    uVar12 = (SInt32)((UInt32)M<UInt16>(colorBuffer + 0x14) / (M<UInt32>(colorBuffer + 0x3c) >> 0x14 & 0xf)) >>
             (uVar16 & 0x3f);
  }
  uVar16 = 0x20 / M<UInt16>(colorBuffer + 0x16);
  if (uVar16 <= uVar12) {
    uVar16 = uVar12;
  }
  colorTilingByte0 = M<UInt8>(colorBuffer + 0x38);
  uVar12 = FormatTableLookup_0x0004d2dc(formatByteOffset);
  uVar15 = FormatTableLookup_0x0004d2e0(formatByteOffset);
  *record = 0x13c8;
  depthRowTiles = 0;
  uVar12 = (uVar12 & 0xc00) << 9;
  uVar15 = uVar15 >> 1 & 0x1e00000;
  uVar4 = (uVar16 & 0x3ffe) >> 1;
  colorPitchWord = uVar15 | uVar12 | uVar16 & 0x3ffe;
  record[1] = mipOffset * (UInt32)basePitch + (iVar10 - mipOffset) * lodBlendWeight + gpuBaseAddress +
               (uVar14 & 0xfffffff0) * uVar4 * 4;
  record[7] = colorPitchWord;
  record[3] = colorPitchWord;
  record[5] = (((uVar14 & 0xfffffff0) >> 1) - 1) * 0x2000 & 0x3ffe000 | uVar4 * 2 - 1 & 0x1fff;
  record[clearWordIndex] = M<UInt32>(depthRecord + 0xb0);
  if ((M<UInt32>(depthBuffer + 0x3c) & 0xf00000) != 0) {
    depthRowTiles = (UInt32)M<UInt16>(depthBuffer + 0x14) / (M<UInt32>(depthBuffer + 0x3c) >> 0x14 & 0xf);
  }
  uVar14 = 0x20 / M<UInt16>(depthBuffer + 0x16);
  if (uVar14 <= depthRowTiles) {
    uVar14 = depthRowTiles;
  }
  record[clearWordIndex + 2] =
       (M<UInt8>(depthBuffer + 0x38) & 6) << 0x10 |
       (M<UInt8>(depthBuffer + 0x38) & 1) << 0x10 |
       (M<UInt8>(depthBuffer + 0x39) & 3) << 0x13 | uVar14 & 0x3ffc;
  record[clearWordIndex + 4] =
       uVar15 | uVar12 | (colorTilingByte0 & 6) << 0x10 | (colorTilingByte0 & 1) << 0x10 | uVar16 & 0x3ffe;
  record[clearWordIndex + 6] = -(M<UInt8>(depthRecord + 0xe2) ^ 0x10) >> 0x1e & 2;
  return;
}
