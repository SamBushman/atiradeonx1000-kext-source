/*
 * IOATIR500DVDContext_stop_Port.cpp
 *
 * IOATIR500DVDContext::stop (real addr 0xe3a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 GH_ZN12IOUserClient26removeMappingForDescriptorEP18IOMemoryDesc(...) asm("__ZN12IOUserClient26removeMappingForDescriptorEP18IOMemoryDescriptor");


/* real addr 0xe3a0 */
void IOATIR500DVDContext::stop(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *providerBytes = reinterpret_cast<UInt8 *>(provider);

  UInt8 *previous;
  int *piVar2;
  int iVar3;
  int iVar4;
  UInt8 *pIVar5;
  int *accelWords;
  int *mapping;
  UInt8 *liveContext;
  UInt8 *slotCursor;
  int textureRefCount;
  int accelAddr;
  int clientNode;
  
  M<UInt32>(self + kIOATIR500DVDContext_started) = 0;
  accelWords = M<int *>(self + kIOATIR500DVDContext_accelerator);
  liveContext = (UInt8 *)accelWords[0x1a];
  if (self == (UInt8 *)accelWords[0x1a]) {
    accelWords[0x1a] = M<int>(self + kIOATIR500DVDContext_nextLiveContext);
    accelWords = M<int *>(self + kIOATIR500DVDContext_accelerator);
    if ((accelWords[0x1a] == 0) && (accelWords[0x18] == 0)) {
      VCALL(*accelWords, 0x538)(accelWords);
      accelWords = M<int *>(self + kIOATIR500DVDContext_accelerator);
    }
  }
  else {
    do {
      previous = liveContext;
      liveContext = M<UInt8 *>(previous + 0x80);
      if (liveContext == (UInt8 *)0x0) break;
    } while (self != liveContext);
    M<UInt32>(previous + 0x80) = M<UInt32>(self + kIOATIR500DVDContext_nextLiveContext);
  }
  accelWords[0x1cf] = accelWords[0x1cf] + -1;
  M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x5c8) = 0x20000;
  if (M<int>(self + kIOATIR500DVDContext_commandBufferDescriptor) != 0) {
    accelAddr = M<int>(self + kIOATIR500DVDContext_accelerator);
    clientNode = M<int>(accelAddr + kIOATIR500Accelerator_liveGLContextListHead);
    if (clientNode == 0) {
      if (M<int>(accelAddr + kIOATIR500Accelerator_liveDVDContextListHead) == 0) goto LAB_0000e548;
    }
    else {
      while( true ) {
        if (M<unsigned int>(accelAddr + kIOATIR500Accelerator_cachedBufferSizeThreshold) < M<unsigned int>(clientNode + 0xb0)) {
          M<unsigned int>(accelAddr + kIOATIR500Accelerator_cachedBufferSizeThreshold) = M<unsigned int>(clientNode + 0xb0);
        }
        mapping = (int *)GH_ZN12IOUserClient26removeMappingForDescriptorEP18IOMemoryDesc(clientNode,M<UInt32>(self + kIOATIR500DVDContext_commandBufferDescriptor));
        if (mapping != (int *)0x0) {
          VCALL(*mapping, 0x18)(mapping);
        }
        clientNode = M<int>(clientNode + 0x80);
        if (clientNode == 0) break;
        accelAddr = M<int>(self + kIOATIR500DVDContext_accelerator);
      }
      accelAddr = M<int>(self + kIOATIR500DVDContext_accelerator);
    }
    clientNode = M<int>(accelAddr + kIOATIR500Accelerator_liveDVDContextListHead);
    if (clientNode != 0) {
      while( true ) {
        if (M<unsigned int>(accelAddr + kIOATIR500Accelerator_cachedBufferSizeThreshold) < 0x80000) {
          M<UInt32>(accelAddr + kIOATIR500Accelerator_cachedBufferSizeThreshold) = 0x80000;
        }
        mapping = (int *)GH_ZN12IOUserClient26removeMappingForDescriptorEP18IOMemoryDesc(clientNode,M<UInt32>(self + kIOATIR500DVDContext_commandBufferDescriptor));
        if (mapping != (int *)0x0) {
          VCALL(*mapping, 0x18)(mapping);
        }
        clientNode = M<int>(clientNode + 0x80);
        if (clientNode == 0) break;
        accelAddr = M<int>(self + kIOATIR500DVDContext_accelerator);
      }
    }
  }
LAB_0000e548:
  if (M<int>(self + kIOATIR500DVDContext_contextBufferDescriptor) != 0) {
    this->freeAllContextBuffers();
  }
  if (M<int>(self + kIOATIR500DVDContext_commandBufferDescriptor) != 0) {
    ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500DVDContext_accelerator)))->freeCommandBuffer((VendorCommandBuffer *)((UInt8 *)(self + kIOATIR500DVDContext_commandBuffer)));
  }
  if (self == M<UInt8 *>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x78)) {
    M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x78) = 0;
  }
  if (M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface) != (UInt8 *)0x0) {
    ((IOATIR500Surface *)(M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface)))->remove_dvd_context((IOATIR500DVDContext *)(self));
    ((IOATIR500Surface *)(M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface)))->prune_buffers();
    M<UInt32>(self + kIOATIR500DVDContext_boundSurface) = 0;
  }
  if (M<int>(self + kIOATIR500DVDContext_sharedAllocator) != 0) {
    slotCursor = self;
    do {
      if (M<int>(slotCursor + 0x104) != 0) {
        textureRefCount = GH_OSDecrementAtomic(M<int>(M<int>(slotCursor + 0x104) + 0x14) + 0x10);
        if (textureRefCount == 1) {
          ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500DVDContext_sharedAllocator)))->delete_texture((VendorTextureBuffer *)(M<UInt8 *>(slotCursor + 0x104)));
        }
        M<UInt32>(slotCursor + 0x104) = 0;
      }
      slotCursor = slotCursor + 4;
    } while (slotCursor != self + 0x48);
    VCALL(*M<int *>(self + kIOATIR500DVDContext_sharedAllocator), 0x18)(M<int *>(self + kIOATIR500DVDContext_sharedAllocator));
    M<UInt32>(self + kIOATIR500DVDContext_sharedAllocator) = 0;
  }
  IOUserClient::stop(provider);   /* the shipped body tail-calls the base class (SUB_60000000 = its lazy-binding stub) */
  return;
}
