/*
 * ATIR500GLContext_WriteTextureOffset_Port.cpp
 *
 * ATIR500GLContext::WriteTextureOffset (real addr 0x28420, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x28420 */
UInt32 ATIR500GLContext::WriteTextureOffset(UInt32 unit, UInt32*outputBuffer, UInt32 index, VendorTextureBuffer *texture) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);

  UInt8 formatBits;
  UInt32 uVar2;
  SInt32 nextIndex;
  UInt32 packedOffset;
  
  while (textureBytes[0x20] == 0x1) {
    textureBytes = M<UInt8 *>(textureBytes + 0x50);
    if (textureBytes == (UInt8 *)0x0) {
      return 0;
    }
  }
  formatBits = M<UInt8>(M<SInt32>(textureBytes + 0x14) + 0x15);
  uVar2 = this->GetTextureOffset((VendorTextureBuffer *)(textureBytes),false);
  packedOffset = formatBits & 0x1f | uVar2 & 0xffffffe0;
  outputBuffer[index] = unit + 0x1150;
  nextIndex = index + 2;
  outputBuffer[index + 1] = packedOffset;
  uVar2 = M<UInt32>(textureBytes + 0x68);
  if ((uVar2 & 0xc0000000) == 0) {
    outputBuffer[nextIndex] = 0x80000000;
    return 3;
  }
  if (unit < 8) {
    outputBuffer[nextIndex] = unit + 0x1158;
    outputBuffer[index + 3] = packedOffset + (uVar2 & 0x3fffff) * 0x20;
    return 4;
  }
  outputBuffer[nextIndex] = 0xc0001000;
  return 4;
}
