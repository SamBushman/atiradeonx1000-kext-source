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
  SInt32 colorBuffer;
  UInt32 depthRowTiles;
  SInt32 lodBlendWeight;
  SInt32 formatByteOffset;
  SInt32 mipOffset;
  SInt32 surface;
  SInt32 gpuBaseAddress;
  SInt32 depthRecord;
  UInt32 clearWordIndex;
  SInt32 depthBuffer;
  UInt32 halfPitch;
  SInt32 mipEntry;
  SInt32 nextMipOffset;
  UInt32 samplePitch;
  UInt32 formatInfo;
  UInt32 formatBitsA;
  UInt32 tileRows16;
  UInt32 depthMinPitch;
  UInt32 formatInfoB;
  UInt32 formatBitsB;
  UInt32 mipLevel;
  UInt32 pitchPixels;
  UInt32 colorTilingBits;
  UInt32 depthTilingBits;
  
  clearWordIndex = record[1];
  surface = M<SInt32>(self + kIOATIR500GLContext_boundSurface);
  mipLevel = M<UInt32>(self + kIOATIR500GLContext_mipLevel);
  lodBlendWeight = M<SInt32>(self + kIOATIR500GLContext_surfaceIndex);
  colorBuffer = M<SInt32>((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) * 4 + surface + kIOATIR500Surface_attachmentBuffers);
  depthRecord = (UInt32)M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) * 0x78 + surface;
  depthBuffer = M<SInt32>((UInt32)M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) * 4 + surface + kIOATIR500Surface_attachmentBuffers);
  mipEntry = mipLevel * 4 + colorBuffer;
  basePitch = M<UInt16>(colorBuffer + 0x20);
  tileRows16 = 0x10;
  mipOffset = M<SInt32>(mipEntry + 0x40);
  nextMipOffset = M<SInt32>(mipEntry + 0x44);
  gpuBaseAddress = M<SInt32>(colorBuffer + 8);
  formatByteOffset = (SInt32)(UInt32)M<UInt16>(colorBuffer + 0x1e) >> mipLevel;
  if (formatByteOffset != 0) {
    tileRows16 = formatByteOffset + 0xf;
  }
  samplePitch = 0;
  formatByteOffset = (UInt32)M<UInt8>(colorBuffer + 0x3a) * 0x1c;
  colorTilingBits = M<UInt32>(colorBuffer + 0x3c);
  if ((colorTilingBits & 0xf00000) != 0) {
    samplePitch = (SInt32)M<UInt16>(colorBuffer + 0x14) / (SInt32)(colorTilingBits >> 0x14 & 0xf) >> mipLevel;
  }
  pitchPixels = (SInt32)0x20 / (SInt32)M<UInt16>(colorBuffer + 0x16);
  if (pitchPixels <= samplePitch) {
    pitchPixels = samplePitch;
  }
  colorTilingByte0 = M<UInt8>(colorBuffer + 0x38);
  formatInfo = FormatTableLookup_0x0004d2dc(formatByteOffset);
  formatInfoB = FormatTableLookup_0x0004d2e0(formatByteOffset);
  *record = 0x13c8;
  depthRowTiles = 0;
  formatBitsA = (formatInfo & 0xc00) << 9;
  formatBitsB = formatInfoB >> 1 & 0x1e00000;
  halfPitch = (pitchPixels & 0x3ffe) >> 1;
  colorPitchWord = formatBitsB | formatBitsA | pitchPixels & 0x3ffe;
  record[1] = mipOffset * (UInt32)basePitch + (nextMipOffset - mipOffset) * lodBlendWeight + gpuBaseAddress +
               (tileRows16 & 0xfffffff0) * halfPitch * 4;
  record[7] = colorPitchWord;
  record[3] = colorPitchWord;
  record[5] = (((tileRows16 & 0xfffffff0) >> 1) - 1) * 0x2000 & 0x3ffe000 | halfPitch * 2 - 1 & 0x1fff;
  record[clearWordIndex] = M<UInt32>(depthRecord + 0xb0);
  depthTilingBits = M<UInt32>(depthBuffer + 0x3c);
  if ((depthTilingBits & 0xf00000) != 0) {
    depthRowTiles = (SInt32)M<UInt16>(depthBuffer + 0x14) / (SInt32)(depthTilingBits >> 0x14 & 0xf);
  }
  depthMinPitch = (SInt32)0x20 / (SInt32)M<UInt16>(depthBuffer + 0x16);
  if (depthMinPitch <= depthRowTiles) {
    depthMinPitch = depthRowTiles;
  }
  record[clearWordIndex + 2] =
       (M<UInt8>(depthBuffer + 0x38) & 6) << 0x10 |
       (M<UInt8>(depthBuffer + 0x38) & 1) << 0x10 |
       (M<UInt8>(depthBuffer + 0x39) & 3) << 0x13 | depthMinPitch & 0x3ffc;
  record[clearWordIndex + 4] =
       formatBitsB | formatBitsA | (colorTilingByte0 & 6) << 0x10 | (colorTilingByte0 & 1) << 0x10 | pitchPixels & 0x3ffe;
  record[clearWordIndex + 6] = -(M<UInt8>(depthRecord + 0xe2) ^ 0x10) >> 0x1e & 2;
  return;
}
