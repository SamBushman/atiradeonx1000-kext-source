/*
 * ATIR500GLContext_build_surface_from_texture_Port.cpp
 *
 * ATIR500GLContext::build_surface_from_texture (real addr 0x28200, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x28200 */
void ATIR500GLContext::build_surface_from_texture(VendorTextureBuffer *texture, ATIR500SurfaceBuffer *surfaceBuffer, UInt16 width, UInt16 height, UInt8 formatIndex, UInt32 baseOffset, UInt16 pitch) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);
    UInt8 *surfaceBufferBytes = reinterpret_cast<UInt8 *>(surfaceBuffer);

  SInt32 formatByteOffset;
  UInt32 in_register_00000020;
  UInt8 tileBits;
  UInt8 tilingMode;
  UInt32 textureWord4c;
  UInt32 textureWord40;
  UInt32 textureWord44;
  UInt32 formatInfo;
  UInt32 bytesPerPixelMasked;
  UInt32 bytesPerPixel;
  UInt16 bytesPerPixel16;
  SInt32 blockRows;
  
  surfaceBufferBytes[0x3c] = 0x0;
  surfaceBufferBytes[0x37] = 0xff;
  surfaceBufferBytes[0x3b] = 0x6;
  M<UInt32>(surfaceBufferBytes + 0x44) = 0;
  M<UInt32>(surfaceBufferBytes) = 0;
  M<UInt32>(surfaceBufferBytes + 4) = 0;
  M<UInt32>(surfaceBufferBytes + 8) = 0;
  M<UInt32>(surfaceBufferBytes + 0xc) = 0;
  M<UInt32>(surfaceBufferBytes + 0x10) = 0;
  M<UInt16>(surfaceBufferBytes + 0x14) = 0;
  M<UInt16>(surfaceBufferBytes + 0x16) = 0;
  M<UInt32>(surfaceBufferBytes + 0x24) = 0;
  M<UInt32>(surfaceBufferBytes + 0x28) = 0xffffffff;
  M<UInt32>(surfaceBufferBytes + 0x2c) = 0;
  M<UInt32>(surfaceBufferBytes + 0x30) = 0;
  M<UInt16>(surfaceBufferBytes + 0x1c) = width;
  M<UInt16>(surfaceBufferBytes + 0x1e) = height;
  M<UInt16>(surfaceBufferBytes + 0x18) = 0;
  surfaceBufferBytes[0x34] = 0x0;
  surfaceBufferBytes[0x35] = 0x0;
  surfaceBufferBytes[0x36] = 0x0;
  surfaceBufferBytes[0x38] = 0x0;
  surfaceBufferBytes[0x39] = 0x0;
  M<UInt16>(surfaceBufferBytes + 0x22) = 1;
  M<UInt16>(surfaceBufferBytes + 0x20) = 1;
  M<UInt32>(surfaceBufferBytes + 0x40) = 0;
  M<UInt32>(surfaceBufferBytes + 0x3c) = M<UInt32>(surfaceBufferBytes + 0x3c) & 0xff0007ff | 0x111000;
  if (textureBytes[0x20] == 0x6) {
    formatByteOffset = this->GetTextureOffset((VendorTextureBuffer *)(textureBytes),true);
    M<UInt32>(surfaceBufferBytes + 8) = formatByteOffset + baseOffset;
  }
  else {
    M<UInt32>(surfaceBufferBytes + 8) = baseOffset + M<SInt32>(textureBytes + 0x48);
  }
  textureWord4c = M<UInt32>(textureBytes + 0x4c);
  textureWord40 = M<UInt32>(textureBytes + 0x40);
  textureWord44 = M<UInt32>(textureBytes + 0x44);
  M<UInt16>(surfaceBufferBytes + 0x18) = pitch;
  surfaceBufferBytes[0x3a] = formatIndex;
  M<UInt32>(surfaceBufferBytes + 0xc) = textureWord4c;
  M<UInt32>(surfaceBufferBytes) = textureWord40;
  M<UInt32>(surfaceBufferBytes + 4) = textureWord44;
  formatByteOffset = ((UInt32)formatIndex) * 0x1c;
  tileBits = M<UInt8>(M<SInt32>(textureBytes + 0x14) + 0x15) >> 2;
  tilingMode = (tileBits & 7);
  surfaceBufferBytes[0x38] = tilingMode;
  formatInfo = FormatTableLookup_0x0004d2dc(formatByteOffset);
  if ((UInt8)tilingMode < 2) {
    blockRows = 1;
  }
  else {
    blockRows = 1 << (formatInfo >> 8 & 3);
  }
  if (((UInt32)M<UInt16>(surfaceBufferBytes + 0x18) < (UInt32)((0x20 >> (formatInfo >> 8 & 3)) << 3)) ||
     ((UInt32)M<UInt16>(surfaceBufferBytes + 0x1e) < (UInt32)(blockRows << 3))) {
    surfaceBufferBytes[0x38] = (tileBits & 6);
    formatInfo = FormatTableLookup_0x0004d2dc(formatByteOffset);
  }
  bytesPerPixel = 1 << (formatInfo >> 0xc & 7);
  bytesPerPixelMasked = bytesPerPixel & 0xffff;
  bytesPerPixel16 = (UInt16)bytesPerPixel;
  M<UInt16>(surfaceBufferBytes + 0x16) = bytesPerPixel16;
  if (bytesPerPixelMasked == 0) {
    M<UInt16>(surfaceBufferBytes + 0x14) = bytesPerPixel16;
  }
  else {
    M<SInt16>(surfaceBufferBytes + 0x14) = (SInt16)(M<UInt16>(surfaceBufferBytes + 0x18) / bytesPerPixelMasked);
  }
  M<UInt32>(surfaceBufferBytes + 0x28) = M<UInt32>(textureBytes + 0x6c);
  surfaceBufferBytes[0x34] = SUB21(M<UInt16>(textureBytes + 0x7a),0);
  surfaceBufferBytes[0x35] = SUB21((UInt16)M<UInt16>(textureBytes + 0x7a) >> 8,0);
  return;
}
