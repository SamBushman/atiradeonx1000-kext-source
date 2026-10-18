/*
 * IOATIR500Accelerator_allocOneDataBuffer_Port.cpp
 *
 * IOATIR500Accelerator::allocOneDataBuffer (real addr 0x6960, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x6960 */
VendorTextureBuffer *IOATIR500Accelerator::allocOneDataBuffer(UInt32 sizeClass, bool forWrite) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *dataBuffer;
  SInt32 iVar2;
  UInt32 in_register_00000014;
  SInt32 prevNode;
  
  dataBuffer = (UInt8 *)VCALL(M<SInt32>(self), 0x570)(self,0xc0);
  if (dataBuffer != (UInt8 *)0x0) {
    M<UInt32>(dataBuffer + 0x50) = sizeClass;
    M<UInt8 *>(dataBuffer + 0x14) = dataBuffer + 0x80;
    dataBuffer[0x20] = 0x8;
    if ((((UInt32)forWrite) == 0) ||
       (iVar2 = VCALL(M<SInt32>(self), 0x528)(self,dataBuffer), iVar2 == 0)) {
      iVar2 = this->allocDataBufferBacking((VendorTextureBuffer *)(dataBuffer));
      if (iVar2 == 0) {
        VCALL(M<SInt32>(self), 0x574)(self,dataBuffer,0xc0);
        return (VendorTextureBuffer *)((UInt8 *)0x0);
      }
    }
    else {
      if (M<SInt32>(dataBuffer + 0x48) != 0) {
        prevNode = M<SInt32>(dataBuffer + 0x24);
        M<UInt32>(prevNode + 0x28) = M<UInt32>(dataBuffer + 0x28);
        iVar2 = M<SInt32>(dataBuffer + 0x28);
        M<UInt8 *>(dataBuffer + 0x28) = self + kIOATIR500Accelerator_textureVramListSentinel;
        M<SInt32>(iVar2 + 0x24) = prevNode;
        M<UInt32>(dataBuffer + 0x24) = M<UInt32>(self + kIOATIR500Accelerator_vramBufferList_prev);
        M<UInt8 *>(self + kIOATIR500Accelerator_vramBufferList_prev) = dataBuffer;
        M<UInt8 *>(M<SInt32>(dataBuffer + 0x24) + 0x28) = dataBuffer;
      }
      VCALL(M<SInt32>(self), 0x54c)(self,M<SInt32>(self + kIOATIR500Accelerator_submitStamp) + -1);
    }
    M<SInt32>(self + kIOATIR500Accelerator_dataBufferCount) = M<SInt32>(self + kIOATIR500Accelerator_dataBufferCount) + 1;
  }
  return (VendorTextureBuffer *)(dataBuffer);
}
