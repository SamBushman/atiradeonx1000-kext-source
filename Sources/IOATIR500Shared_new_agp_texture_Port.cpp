/*
 * IOATIR500Shared_new_agp_texture_Port.cpp
 *
 * IOATIR500Shared::new_agp_texture (real addr 0x17150, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task(...) asm("__ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task");
extern "C" UInt32 GH_ZN18IOMemoryDescriptor30withPersistentMemoryDescriptorEPS_(...) asm("__ZN18IOMemoryDescriptor30withPersistentMemoryDescriptorEPS_");
extern "C" UInt32 GH_ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj(...) asm("__ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj");


/* real addr 0x17150 */
VendorTextureBuffer *IOATIR500Shared::new_agp_texture(unsigned int address, UInt32 length, unsigned int*outClientAddress) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  void *candidate;
  void *nextCandidate;
  SInt32 textureIndex;
  SInt32 *memory;
  UInt32 descriptorLength;
  UInt32 pageOffset;
  UInt32 pageAddress;
  UInt32 roundedLength;
  UInt32 handle;
  sIOClientShared *clientShared;
  UInt32 clientUserAddr [4];
  void *prevCandidate;
  void *newTexture;
  SInt32 handleOk;
  SInt32 clientSharedOk;
  SInt32 acceleratorBytes;
  
  pageOffset = GH_page_size - 1U & address;
  pageAddress = address & -GH_page_size;
  roundedLength = -GH_page_size & (GH_page_size + pageOffset + length) - 1;
  if (roundedLength <= (UInt32)(M<SInt32>(M<SInt32>(self + kIOATIR500Shared_accelerator) + 0x830) * 0xc00) >> 2) {
    if (pageAddress == 0) {
      memory = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj(M<UInt32>(self + 8),
                                   M<UInt32>(M<SInt32>(self + kIOATIR500Shared_accelerator) + 0x82c) | 0x10022,roundedLength,
                                   GH_page_size);
      if (memory != (SInt32 *)0x0) {
        pageAddress = VCALL(*memory, 0x1cc)(memory);
        goto LAB_00017310;
      }
    }
    else {
      nextCandidate = M<void *>(self + kIOATIR500Shared_textureListHead);
      prevCandidate = M<void *>(self + kIOATIR500Shared_textureListHead);
      while (candidate = nextCandidate, candidate != (void *)0x0) {
        if ((((M<char>((SInt32)candidate + 0x20) == '\x04') && (M<SInt32>((SInt32)candidate + 0x54) == 0)) &&
            (pageOffset == M<UInt32>((SInt32)candidate + 0x50))) &&
           ((pageAddress == M<UInt32>((SInt32)candidate + 0x58) && (roundedLength == M<UInt32>((SInt32)candidate + 0x5c)))))
        {
          memory = (SInt32 *)GH_ZN18IOMemoryDescriptor30withPersistentMemoryDescriptorEPS_(M<UInt32>((SInt32)candidate + 8));
          if (memory == M<SInt32 *>((SInt32)candidate + 8)) {
            VCALL(*memory, 0x18)(memory);
            *outClientAddress = M<UInt32>((SInt32)candidate + 0x18);
            if (candidate == M<void *>(self + kIOATIR500Shared_textureListHead)) {
              return (VendorTextureBuffer *)(candidate);
            }
            M<UInt32>((SInt32)prevCandidate + 0x3c) = M<UInt32>((SInt32)candidate + 0x3c);
            M<UInt32>((SInt32)candidate + 0x3c) = M<UInt32>(self + kIOATIR500Shared_textureListHead);
            M<void *>(self + kIOATIR500Shared_textureListHead) = candidate;
            return (VendorTextureBuffer *)(candidate);
          }
          M<UInt32>((SInt32)candidate + 0x54) = 1;
          if (memory != (SInt32 *)0x0) goto LAB_00017310;
          break;
        }
        prevCandidate = candidate;
        nextCandidate = M<void *>((SInt32)candidate + 0x3c);
      }
      memory = (SInt32 *)GH_ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task(pageAddress,roundedLength,0x10002,M<UInt32>(self + 8));
      if (memory != (SInt32 *)0x0) {
LAB_00017310:
        newTexture = (void *)VCALL(*M<SInt32 *>(self + kIOATIR500Shared_accelerator), 0x570)(M<SInt32 *>(self + kIOATIR500Shared_accelerator),0x80);
        if (newTexture == (void *)0x0) {
          VCALL(*memory, 0x18)(memory);
          return (VendorTextureBuffer *)((void *)0x0);
        }
        M<SInt32 *>((SInt32)newTexture + 8) = memory;
        handleOk = this->alloc_buf_handle(newTexture,(UInt32 *)(&handle));
        if (handleOk != 0) {
          clientSharedOk = this->alloc_client_shared(handle,(sIOClientShared **)(&clientShared),(unsigned int *)(clientUserAddr));
          if (clientSharedOk != 0) {
            M<sIOClientShared *>((SInt32)newTexture + 0x14) = clientShared;
            M<UInt32>((SInt32)newTexture + 0x18) = clientUserAddr[0];
            M<UInt32>(clientShared) = handle;
            M<UInt32>(M<SInt32>((SInt32)newTexture + 0x14) + 8) =
                 M<UInt32>(M<SInt32>(self + kIOATIR500Shared_accelerator) + 0x54);
            M<UInt32>(M<SInt32>((SInt32)newTexture + 0x14) + 0xc) =
                 M<UInt32>(M<SInt32>(self + kIOATIR500Shared_accelerator) + 0x54);
            M<UInt8>(M<SInt32>((SInt32)newTexture + 0x14) + 0x16) = 4;
            M<UInt8>((SInt32)newTexture + 0x20) = 4;
            M<UInt32>((SInt32)newTexture + 0x50) = pageOffset;
            M<UInt32>((SInt32)newTexture + 0x58) = pageAddress;
            M<UInt8 *>((SInt32)newTexture + 0x1c) = self;
            descriptorLength = VCALL(*M<SInt32 *>((SInt32)newTexture + 8), 0x128)(M<SInt32 *>((SInt32)newTexture + 8));
            M<UInt32>((SInt32)newTexture + 0x5c) = descriptorLength;
            M<UInt32>((SInt32)newTexture + 0x54) = 0;
            M<UInt32>((SInt32)newTexture + 0x3c) = M<UInt32>(self + kIOATIR500Shared_textureListHead);
            M<void *>(self + kIOATIR500Shared_textureListHead) = newTexture;
            *outClientAddress = clientUserAddr[0];
            M<SInt32>(M<SInt32>(self + kIOATIR500Shared_accelerator) + 0x72c) = M<SInt32>(M<SInt32>(self + kIOATIR500Shared_accelerator) + 0x72c) + 1;
            acceleratorBytes = M<SInt32>(self + kIOATIR500Shared_accelerator);
            if (self != M<UInt8 *>(acceleratorBytes + kIOATIR500Accelerator_globalShared)) {
              return (VendorTextureBuffer *)(newTexture);
            }
            textureIndex = M<SInt32>(acceleratorBytes + kIOATIR500Accelerator_globalTextureCounter);
            M<SInt32>(M<SInt32>((SInt32)newTexture + 0x14) + 4) = textureIndex;
            M<SInt32>(acceleratorBytes + kIOATIR500Accelerator_globalTextureCounter) = textureIndex + 1;
            return (VendorTextureBuffer *)(newTexture);
          }
          this->free_buf_handle(newTexture,handle);
        }
        VCALL(*memory, 0x18)(memory);
        VCALL(*M<SInt32 *>(self + kIOATIR500Shared_accelerator), 0x574)(M<SInt32 *>(self + kIOATIR500Shared_accelerator),newTexture,0x80);
        return (VendorTextureBuffer *)((void *)0x0);
      }
    }
  }
  return (VendorTextureBuffer *)((void *)0x0);
}
