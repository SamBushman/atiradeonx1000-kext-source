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

  UInt8 bVar1;
  UInt8 AVar2;
  UInt32 uVar3;
  SInt32 formatByteOffset;
  UInt32 uVar5;
  UInt32 uVar6;
  UInt16 uVar7;
  SInt32 iVar8;
  UInt32 in_register_00000020;
  UInt32 uVar9;
  UInt32 uVar10;
  
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
  uVar3 = M<UInt32>(textureBytes + 0x4c);
  uVar5 = M<UInt32>(textureBytes + 0x40);
  uVar9 = M<UInt32>(textureBytes + 0x44);
  M<UInt16>(surfaceBufferBytes + 0x18) = pitch;
  surfaceBufferBytes[0x3a] = formatIndex;
  M<UInt32>(surfaceBufferBytes + 0xc) = uVar3;
  M<UInt32>(surfaceBufferBytes) = uVar5;
  M<UInt32>(surfaceBufferBytes + 4) = uVar9;
  formatByteOffset = ((UInt32)formatIndex) * 0x1c;
  bVar1 = M<UInt8>(M<SInt32>(textureBytes + 0x14) + 0x15) >> 2;
  AVar2 = (bVar1 & 7);
  surfaceBufferBytes[0x38] = AVar2;
  if ((UInt8)AVar2 < 2) {
    uVar10 = FormatTableLookup_0x0004d2dc(formatByteOffset);
    iVar8 = 1;
  }
  else {
    uVar10 = FormatTableLookup_0x0004d2dc(formatByteOffset);
    iVar8 = 1 << (uVar10 >> 8 & 3);
  }
  if (((UInt32)M<UInt16>(surfaceBufferBytes + 0x18) < (UInt32)((0x20 >> (uVar10 >> 8 & 3)) << 3)) ||
     ((UInt32)M<UInt16>(surfaceBufferBytes + 0x1e) < (UInt32)(iVar8 << 3))) {
    surfaceBufferBytes[0x38] = (bVar1 & 6);
    uVar10 = FormatTableLookup_0x0004d2dc(formatByteOffset);
  }
  uVar6 = 1 << (uVar10 >> 0xc & 7);
  uVar10 = uVar6 & 0xffff;
  uVar7 = (UInt16)uVar6;
  M<UInt16>(surfaceBufferBytes + 0x16) = uVar7;
  if (uVar10 == 0) {
    M<UInt16>(surfaceBufferBytes + 0x14) = uVar7;
  }
  else {
    M<SInt16>(surfaceBufferBytes + 0x14) = (SInt16)(M<UInt16>(surfaceBufferBytes + 0x18) / uVar10);
  }
  M<UInt32>(surfaceBufferBytes + 0x28) = M<UInt32>(textureBytes + 0x6c);
  surfaceBufferBytes[0x34] = SUB21(M<UInt16>(textureBytes + 0x7a),0);
  surfaceBufferBytes[0x35] = SUB21((UInt16)M<UInt16>(textureBytes + 0x7a) >> 8,0);
  return;
}
