/*
 * IOATIR500Shared_new_texture_Port.cpp
 *
 * IOATIR500Shared::new_texture (real addr 0x18060, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_OSIncrementAtomic(...) asm("_OSIncrementAtomic");
extern "C" UInt32 GH_ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj(...) asm("__ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj");


/* real addr 0x18060 */
VendorTextureBuffer *IOATIR500Shared::new_texture(UInt32 size, UInt32 auxValue, unsigned int agpAddress, UInt32 agpLength, unsigned int *outDataAddress, unsigned int *outSharedUserAddr) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    unsigned int *outDataAddressAlias = outDataAddress;
    unsigned int *outSharedUserAddrAlias = outSharedUserAddr;

  int textureIndex;
  UInt8 *agpTexture;
  void *texture;
  int *memoryMap;
  char bufferType;
  UInt32 handle;
  sIOClientShared *clientShared;
  unsigned int clientUserAddr;
  unsigned int agpUserAddr [6];
  int *accelerator;
  int *bufferMemory;
  int extraBytes;
  int handleOk;
  int clientSharedOk;
  int acceleratorBytes;
  unsigned int allocSize;
  unsigned int dataAddress;
  
  if ((agpAddress == 0) || (agpLength == 0)) {
    if (auxValue == 0) {
      agpTexture = (UInt8 *)0x0;
      bufferType = '\x02';
      extraBytes = 0x80;
    }
    else {
      agpTexture = (UInt8 *)0x0;
      bufferType = '\x03';
      extraBytes = 0xa00;
    }
  }
  else {
    agpTexture = (UInt8 *)this->new_agp_texture(agpAddress,agpLength,(unsigned int *)(agpUserAddr));
    if (agpTexture == (UInt8 *)0x0) {
      return (VendorTextureBuffer *)((void *)0x0);
    }
    bufferType = '\a';
    extraBytes = 0xa00;
  }
  accelerator = M<int *>(self + kIOATIR500Shared_accelerator);
  allocSize = extraBytes + size + GH_page_size + 7 & -GH_page_size;
  if (allocSize <= (unsigned int)(accelerator[0x20c] * 0xc00) >> 2) {
    texture = (void *)VCALL(*accelerator, 0x570)(accelerator,0x80);
    if (texture == (void *)0x0) {
      if (agpTexture == (UInt8 *)0x0) {
        return (VendorTextureBuffer *)((void *)0x0);
      }
      if (M<int>(M<int>(agpTexture + 0x14) + 0x10) != 0) {
        return (VendorTextureBuffer *)((void *)0x0);
      }
      this->delete_texture((VendorTextureBuffer *)(agpTexture));
      return (VendorTextureBuffer *)((void *)0x0);
    }
    bufferMemory = (int *)GH_ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj(M<UInt32>(self + 8),
                                 M<unsigned int>(M<int>(self + kIOATIR500Shared_accelerator) + 0x82c) | 0x10022,allocSize,
                                 GH_page_size);
    if (bufferMemory != (int *)0x0) {
      M<int *>((int)texture + 8) = bufferMemory;
      handleOk = this->alloc_buf_handle(texture,(UInt32 *)(&handle));
      if (handleOk != 0) {
        clientSharedOk = this->alloc_client_shared(handle,(sIOClientShared **)(&clientShared),(unsigned int *)(&clientUserAddr));
        if (clientSharedOk != 0) {
          M<sIOClientShared *>((int)texture + 0x14) = clientShared;
          M<unsigned int>((int)texture + 0x18) = clientUserAddr;
          M<UInt32>(clientShared) = handle;
          M<UInt32>(M<int>((int)texture + 0x14) + 8) =
               M<UInt32>(M<int>(self + kIOATIR500Shared_accelerator) + 0x54);
          M<UInt32>(M<int>((int)texture + 0x14) + 0xc) =
               M<UInt32>(M<int>(self + kIOATIR500Shared_accelerator) + 0x54);
          M<char>(M<int>((int)texture + 0x14) + 0x16) = bufferType;
          M<char>((int)texture + 0x20) = bufferType;
          M<UInt8 *>((int)texture + 0x1c) = self;
          memoryMap = (int *)VCALL(*bufferMemory, 0x14c)
                                    (bufferMemory,M<UInt32>(self + 8),0,
                                     M<unsigned int>(M<int>(self + kIOATIR500Shared_accelerator) + 0x82c) | 1,0,0);
          if (memoryMap != (int *)0x0) {
            M<int *>((int)texture + 0x10) = memoryMap;
            if (bufferType == '\x03') {
              M<UInt32>((int)texture + 0x50) = auxValue;
            }
            else if (bufferType != '\x02') {
              M<UInt32>((int)texture + 0x50) = auxValue;
              M<UInt8 *>((int)texture + 0x58) = agpTexture;
              GH_OSIncrementAtomic(M<int>(agpTexture + 0x14) + 0x10);
            }
            M<UInt32>((int)texture + 0x3c) = M<UInt32>(self + kIOATIR500Shared_textureListHead);
            M<void *>(self + kIOATIR500Shared_textureListHead) = texture;
            dataAddress = VCALL(*memoryMap, 0xd0)(memoryMap);
            *outDataAddressAlias = dataAddress;
            *outSharedUserAddrAlias = clientUserAddr;
            M<int>(M<int>(self + kIOATIR500Shared_accelerator) + 0x72c) = M<int>(M<int>(self + kIOATIR500Shared_accelerator) + 0x72c) + 1;
            acceleratorBytes = M<int>(self + kIOATIR500Shared_accelerator);
            if (self == M<UInt8 *>(acceleratorBytes + kIOATIR500Accelerator_globalShared)) {
              textureIndex = M<int>(acceleratorBytes + kIOATIR500Accelerator_globalTextureCounter);
              M<int>(M<int>((int)texture + 0x14) + 4) = textureIndex;
              M<int>(acceleratorBytes + kIOATIR500Accelerator_globalTextureCounter) = textureIndex + 1;
              return (VendorTextureBuffer *)(texture);
            }
            return (VendorTextureBuffer *)(texture);
          }
          this->free_buf_handle(texture,*M<UInt32 *>((int)texture + 0x14));
          VCALL(*bufferMemory, 0x18)(bufferMemory);
          M<UInt32>((int)texture + 8) = 0;
          goto joined_r0x0001834c;
        }
        this->free_buf_handle(texture,handle);
      }
      VCALL(*bufferMemory, 0x18)(bufferMemory);
      M<UInt32>((int)texture + 8) = 0;
    }
    if ((agpTexture != (UInt8 *)0x0) && (M<int>(M<int>(agpTexture + 0x14) + 0x10) == 0)) {
      this->delete_texture((VendorTextureBuffer *)(agpTexture));
    }
    VCALL(*M<int *>(self + kIOATIR500Shared_accelerator), 0x574)(M<int *>(self + kIOATIR500Shared_accelerator),texture,0x80);
    return (VendorTextureBuffer *)((void *)0x0);
  }
joined_r0x0001834c:
  if ((agpTexture != (UInt8 *)0x0) && (M<int>(M<int>(agpTexture + 0x14) + 0x10) == 0)) {
    this->delete_texture((VendorTextureBuffer *)(agpTexture));
    return (VendorTextureBuffer *)((void *)0x0);
  }
  return (VendorTextureBuffer *)((void *)0x0);
}
