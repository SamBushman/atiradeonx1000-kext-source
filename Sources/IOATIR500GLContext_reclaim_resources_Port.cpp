/*
 * IOATIR500GLContext_reclaim_resources_Port.cpp
 *
 * IOATIR500GLContext::reclaim_resources (real addr 0x83c0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");


/* real addr 0x83c0 */
IOReturn IOATIR500GLContext::reclaim_resources() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *buffer;
  UInt32 pooledCount;
  UInt8 *accel;
  SInt32 iVar3;
  UInt8 *nextBuffer;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x840));
  M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5c8) = 0x20000;
  M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5d8) = 0x10000;
  nextBuffer = M<UInt8 *>(self + kIOATIR500GLContext_dataBufferListHead);
  while (buffer = nextBuffer, buffer != (UInt8 *)0x0) {
    accel = M<UInt8 *>(self + kIOATIR500GLContext_accelerator);
    nextBuffer = M<UInt8 *>(buffer + 0x3c);
    if (M<UInt32>(accel + 0x5d4) < 0x10) {
      if (M<SInt32>(accel + 0x5d0) == 0) {
        M<UInt8 *>(accel + 0x5cc) = buffer;
        M<UInt8 *>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5d0) = buffer;
        M<UInt32>(buffer + 0x3c) = 0;
      }
      else {
        M<UInt8 *>(M<SInt32>(accel + 0x5d0) + 0x3c) = buffer;
        M<UInt8 *>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5d0) = buffer;
        M<UInt32>(buffer + 0x3c) = 0;
      }
      M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5d4) = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5d4) + 1;
      buffer[0x54] = 0x0;
      if (M<SInt32 *>(buffer + 0x10) != (SInt32 *)0x0) {
        VCALL(*M<SInt32 *>(buffer + 0x10), 0x18)(M<SInt32 *>(buffer + 0x10));
        M<UInt32>(buffer + 0x10) = 0;
      }
    }
    else {
      ((IOATIR500Accelerator *)(accel))->freeOneDataBuffer((VendorTextureBuffer *)(buffer));
    }
  }
  iVar3 = M<SInt32>(self + kIOATIR500GLContext_accelerator);
  M<UInt32>(self + kIOATIR500GLContext_dataBufferCount) = 0;
  M<UInt32>(self + kIOATIR500GLContext_dataBufferListHead) = 0;
  M<UInt32>(self + kIOATIR500GLContext_dataBufferListTail) = 0;
  pooledCount = M<UInt32>(iVar3 + 0x5d4);
  while (0xf < pooledCount) {
    nextBuffer = M<UInt8 *>(iVar3 + 0x5cc);
    M<UInt32>(iVar3 + 0x5cc) = M<UInt32>(nextBuffer + 0x3c);
    M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5d4) = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5d4) + -1;
    ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->freeOneDataBuffer((VendorTextureBuffer *)(nextBuffer));
    iVar3 = M<SInt32>(self + kIOATIR500GLContext_accelerator);
    pooledCount = M<UInt32>(iVar3 + 0x5d4);
  }
  GH_IOLockUnlock(M<UInt32>(iVar3 + 0x840));
  return 0;
}
