/*
 * IOATIR500Accelerator_allocMoreCommandBuffers_Port.cpp
 *
 * IOATIR500Accelerator::allocMoreCommandBuffers (real addr 0x24a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x24a0 */
bool IOATIR500Accelerator::allocMoreCommandBuffers(UInt32 recordIndex, UInt32 size) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt16 oldCount16;
  UInt32 result;
  UInt32 newCount;
  SInt32 recordOffset;
  UInt32 currentCount;
  UInt32 bufferIndex;
  UInt8 *commandBuffer;
  UInt8 *allocatedBuffer;
  SInt32 freeIndex;
  SInt32 allocStatus;
  
  recordOffset = recordIndex * 0x1c4;
  oldCount16 = M<UInt16>(self + recordOffset + 0x402);
  currentCount = (UInt32)oldCount16;
  if (currentCount == 0x10) {
returnFailure:
    result = 0;
  }
  else {
    newCount = 1;
    if (currentCount != 0) {
      newCount = currentCount << 1;
    }
    if (currentCount < newCount) {
      commandBuffer = (UInt8 *)(self + currentCount * 0x1c + recordOffset + 0x240);
      bufferIndex = currentCount;
      do {
        allocStatus = this->allocCommandBuffer((VendorCommandBuffer *)(commandBuffer),size);
        if (allocStatus == 0) {
          freeIndex = bufferIndex - 1;
          if ((SInt32)currentCount <= freeIndex) {
            allocatedBuffer = self + freeIndex * 0x1c + recordOffset + 0x240;
            do {
              freeIndex = freeIndex + -1;
              this->freeCommandBuffer((VendorCommandBuffer *)((UInt8 *)allocatedBuffer));
              allocatedBuffer = (UInt8 *)(allocatedBuffer + -0x1c);
            } while ((SInt32)currentCount <= freeIndex);
          }
          goto returnFailure;
        }
        bufferIndex = bufferIndex + 1;
        commandBuffer = commandBuffer + 0x1c;
      } while (newCount != bufferIndex);
    }
    result = 1;
    storeHalf(&M<UInt16>(self + recordOffset + 0x402), newCount);
    M<UInt16>(self + recordOffset + 0x400) = oldCount16;
  }
  return result;
}
