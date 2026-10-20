/*
 * IOATIR500Accelerator_pageOffDataBuffer_Port.cpp
 *
 * IOATIR500Accelerator::pageOffDataBuffer (real addr 0x3140, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3140 */
void IOATIR500Accelerator::pageOffDataBuffer(VendorTextureBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  UInt32 wordIndex;
  SInt32 backingStatus;
  SInt32 nextNode;
  SInt32 mappedAddress;
  SInt32 prevNode;
  SInt32 byteOffset;
  SInt32 *backingObject;
  SInt32 *cpuMapping;
  
  backingStatus = this->allocDataBufferBacking((VendorTextureBuffer *)(bufferBytes));
  if (backingStatus == 0) {
    VCALL(M<SInt32>(self), 0x524)(self,bufferBytes);
    prevNode = M<SInt32>(bufferBytes + 0x24);
    M<UInt32>(prevNode + 0x28) = M<UInt32>(bufferBytes + 0x28);
    nextNode = M<SInt32>(bufferBytes + 0x28);
    M<UInt8 *>(bufferBytes + 0x28) = bufferBytes;
    M<SInt32>(nextNode + 0x24) = prevNode;
    M<UInt8 *>(bufferBytes + 0x24) = bufferBytes;
  }
  else {
    backingObject = M<SInt32 *>(bufferBytes + 0x10);
    if (backingObject != (SInt32 *)0x0) {
      VCALL(*backingObject, 0xf0)(backingObject,0,0x400,0);
    }
    cpuMapping = (SInt32 *)VCALL(*M<SInt32 *>(bufferBytes + 8), 0x14c)
                              (M<SInt32 *>(bufferBytes + 8),GH_kernel_task,0,0x401,0,0);
    if (cpuMapping != (SInt32 *)0x0) {
      mappedAddress = VCALL(*cpuMapping, 0xd0)(cpuMapping);
      if (M<UInt32>(bufferBytes + 0x50) >> 2 != 0) {
        wordIndex = 0;
        byteOffset = 0;
        do {
          wordIndex = wordIndex + 1;
          M<UInt32>(byteOffset + mappedAddress) =
               M<UInt32>(M<SInt32>(self + kIOATIR500Accelerator_vramApertureBase) + byteOffset + M<SInt32>(bufferBytes + 0x48));
          byteOffset = byteOffset + 4;
        } while (wordIndex < M<UInt32>(bufferBytes + 0x50) >> 2);
      }
      VCALL(*cpuMapping, 0x18)(cpuMapping);
    }
    backingObject = M<SInt32 *>(bufferBytes + 0x10);
    if (backingObject != (SInt32 *)0x0) {
      VCALL(*backingObject, 0xf0)(backingObject,M<UInt32>(bufferBytes + 8),0x400,0);
    }
  }
  return;
}
