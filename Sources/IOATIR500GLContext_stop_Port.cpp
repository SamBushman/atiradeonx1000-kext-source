/*
 * IOATIR500GLContext_stop_Port.cpp
 *
 * IOATIR500GLContext::stop (real addr 0x7fa0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_OSDecrementAtomic(...) asm("_OSDecrementAtomic");


/* real addr 0x7fa0 */
void IOATIR500GLContext::stop(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *providerBytes = reinterpret_cast<UInt8 *>(provider);

  UInt8 *pIVar1;
  UInt32 pooledCount;
  SInt32 iVar3;
  SInt32 *accelWords;
  UInt8 *accel;
  UInt8 *nextBuffer;
  SInt32 iVar6;
  UInt8 *buffer;
  UInt8 *pIVar8;
  
  M<UInt32>(self + kIOATIR500GLContext_started) = 0;
  accelWords = M<SInt32 *>(self + kIOATIR500GLContext_accelerator);
  pIVar8 = (UInt8 *)accelWords[0x18];
  if (self == (UInt8 *)accelWords[0x18]) {
    accelWords[0x18] = M<SInt32>(self + kIOATIR500GLContext_nextLiveContext);
    accelWords = M<SInt32 *>(self + kIOATIR500GLContext_accelerator);
    if ((accelWords[0x18] == 0) && (accelWords[0x1a] == 0)) {
      VCALL(*accelWords, 0x538)(accelWords);
      accelWords = M<SInt32 *>(self + kIOATIR500GLContext_accelerator);
    }
  }
  else {
    do {
      pIVar1 = pIVar8;
      pIVar8 = M<UInt8 *>(pIVar1 + 0x80);
      if (pIVar8 == (UInt8 *)0x0) break;
    } while (self != pIVar8);
    M<UInt32>(pIVar1 + 0x80) = M<UInt32>(self + kIOATIR500GLContext_nextLiveContext);
  }
  accelWords[0x1ce] = accelWords[0x1ce] + -1;
  M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5c8) = 0x20000;
  this->freeCommandBuffer();
  M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5d8) = 0x10000;
  accel = M<UInt8 *>(self + kIOATIR500GLContext_accelerator);
  iVar6 = M<SInt32>(accel + kIOATIR500Accelerator_dataBufferCacheHead);
  if (iVar6 != 0) {
    do {
      if ((M<SInt32 *>(iVar6 + 0x10) != (SInt32 *)0x0) &&
         (iVar3 = VCALL(*M<SInt32 *>(iVar6 + 0x10), 0xdc)(M<SInt32 *>(iVar6 + 0x10)), iVar3 == M<SInt32>(self + kIOATIR500GLContext_task)))
      {
        VCALL(*M<SInt32 *>(iVar6 + 0x10), 0x18)(M<SInt32 *>(iVar6 + 0x10));
        M<UInt32>(iVar6 + 0x10) = 0;
      }
      iVar6 = M<SInt32>(iVar6 + 0x3c);
    } while (iVar6 != 0);
    accel = M<UInt8 *>(self + kIOATIR500GLContext_accelerator);
  }
  buffer = M<UInt8 *>(self + kIOATIR500GLContext_dataBufferListHead);
  if (buffer != (UInt8 *)0x0) {
    while( true ) {
      nextBuffer = M<UInt8 *>(buffer + 0x3c);
      if (M<UInt32>(accel + kIOATIR500Accelerator_dataBufferCacheCount) < 0x10) {
        if (M<SInt32>(accel + kIOATIR500Accelerator_dataBufferCacheTail) == 0) {
          M<UInt8 *>(accel + kIOATIR500Accelerator_dataBufferCacheHead) = buffer;
          M<UInt8 *>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5d0) = buffer;
          M<UInt32>(buffer + 0x3c) = 0;
        }
        else {
          M<UInt8 *>(M<SInt32>(accel + kIOATIR500Accelerator_dataBufferCacheTail) + 0x3c) = buffer;
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
      if (nextBuffer == (UInt8 *)0x0) break;
      accel = M<UInt8 *>(self + kIOATIR500GLContext_accelerator);
      buffer = nextBuffer;
    }
    accel = M<UInt8 *>(self + kIOATIR500GLContext_accelerator);
  }
  M<UInt32>(self + kIOATIR500GLContext_dataBufferCount) = 0;
  M<UInt32>(self + kIOATIR500GLContext_dataBufferListHead) = 0;
  M<UInt32>(self + kIOATIR500GLContext_dataBufferListTail) = 0;
  pooledCount = M<UInt32>(accel + kIOATIR500Accelerator_dataBufferCacheCount);
  while (0xf < pooledCount) {
    buffer = M<UInt8 *>(accel + kIOATIR500Accelerator_dataBufferCacheHead);
    M<UInt32>(accel + kIOATIR500Accelerator_dataBufferCacheHead) = M<UInt32>(buffer + 0x3c);
    M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5d4) = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5d4) + -1;
    ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->freeOneDataBuffer((VendorTextureBuffer *)(buffer));
    accel = M<UInt8 *>(self + kIOATIR500GLContext_accelerator);
    pooledCount = M<UInt32>(accel + kIOATIR500Accelerator_dataBufferCacheCount);
  }
  if (M<SInt32>(self + kIOATIR500GLContext_contextBufferDescriptor) != 0) {
    this->freeAllContextBuffers();
  }
  if (M<SInt32>(self + kIOATIR500GLContext_commandBufferDescriptor) != 0) {
    ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->freeCommandBuffer((VendorCommandBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
  }
  if (M<SInt32 *>(self + kIOATIR500GLContext_statusDescriptor) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(self + kIOATIR500GLContext_statusDescriptor), 0x18)(M<SInt32 *>(self + kIOATIR500GLContext_statusDescriptor));
  }
  if (self == M<UInt8 *>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x78)) {
    M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x78) = 0;
  }
  if (M<UInt8 *>(self + kIOATIR500GLContext_boundSurface) != (UInt8 *)0x0) {
    ((IOATIR500Surface *)(M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)))->remove_gl_context_from_list((IOATIR500GLContext *)(self));
    ((IOATIR500Surface *)(M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)))->prune_buffers();
    M<UInt32>(self + kIOATIR500GLContext_boundSurface) = 0;
  }
  if (M<SInt32>(self + kIOATIR500GLContext_clientHandle) != 0) {
    pIVar8 = self;
    do {
      if (M<SInt32>(pIVar8 + 0x2a4) != 0) {
        iVar6 = GH_OSDecrementAtomic(M<SInt32>(M<SInt32>(pIVar8 + 0x2a4) + 0x14) + 0x10);
        if (iVar6 == 1) {
          ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)(M<UInt8 *>(pIVar8 + 0x2a4)));
        }
        M<UInt32>(pIVar8 + 0x2a4) = 0;
      }
      pIVar8 = pIVar8 + 4;
    } while (self + 0xa8 != pIVar8);
    VCALL(*M<SInt32 *>(self + kIOATIR500GLContext_clientHandle), 0x18)(M<SInt32 *>(self + kIOATIR500GLContext_clientHandle));
    M<UInt32>(self + kIOATIR500GLContext_clientHandle) = 0;
  }
  IOUserClient::stop(provider);
  return;
}
