/*
 * ATIR500GLContext_WriteVertexArrayOffset_Port.cpp
 *
 * ATIR500GLContext::WriteVertexArrayOffset (real addr 0x27470, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x27470 */
UInt32 ATIR500GLContext::WriteVertexArrayOffset(UInt32*outputBuffer, UInt32 startIndex) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool more;
  UInt32 arrayOffset;
  SInt32 slotA;
  UInt32 packetHeader;
  SInt32 pairIndex;
  UInt8 *extraOffsetA;
  UInt8 *extraOffsetB;
  SInt32 slotB;
  SInt32 byteOffsetB;
  SInt32 byteOffsetA;
  UInt8 bVar11;
  
  pairIndex = 1;
  packetHeader = 0x832;
  extraOffsetB = self + 4;
  byteOffsetA = startIndex * 4 + 4;
  bVar11 = (M<SInt32>(self + kATIR500GLContext_vertexArrayParam) == 0) << 1;
  extraOffsetA = self;
  byteOffsetB = startIndex * 4 + 8;
  do {
    if ((bool)(bVar11 >> 1 & 1)) {
      slotA = 0x10;
      slotB = 0x10;
    }
    else {
      slotA = pairIndex + 0xf;
      slotB = pairIndex + 0x10;
    }
    outputBuffer[startIndex] = packetHeader | 0x10000;
    arrayOffset = this->GetVertexArrayOffset((VendorTextureBuffer *)(M<UInt8 *>(self + slotA * 4 + 0x2a4)),
                       M<UInt32>(extraOffsetA + 0x368));
    M<UInt32>((SInt32)outputBuffer + byteOffsetA) = arrayOffset;
    startIndex = startIndex + 3;
    byteOffsetA = byteOffsetA + 0xc;
    arrayOffset = this->GetVertexArrayOffset((VendorTextureBuffer *)(M<UInt8 *>(self + slotB * 4 + 0x2a4)),
                       M<UInt32>(extraOffsetB + 0x368));
    M<UInt32>((SInt32)outputBuffer + byteOffsetB) = arrayOffset;
    more = pairIndex != 0xf;
    extraOffsetB = extraOffsetB + 8;
    extraOffsetA = extraOffsetA + 8;
    packetHeader = packetHeader + 3;
    pairIndex = pairIndex + 2;
    byteOffsetB = byteOffsetB + 0xc;
  } while (more);
  return 0x18;
}
