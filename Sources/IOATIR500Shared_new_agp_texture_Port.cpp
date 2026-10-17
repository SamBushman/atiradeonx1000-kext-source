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
VendorTextureBuffer *IOATIR500Shared::new_agp_texture(unsigned int address, UInt32 length, unsigned int*param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  void *candidate;
  void *pvVar2;
  SInt32 iVar3;
  SInt32 *memory;
  void *pvVar5;
  SInt32 iVar6;
  UInt32 descriptorLength;
  UInt32 pageOffset;
  UInt32 uVar9;
  UInt32 roundedLength;
  UInt32 handle;
  sIOClientShared *clientShared;
  UInt32 clientUserAddr [4];
  
  pageOffset = GH_page_size - 1U & address;
  uVar9 = address & -GH_page_size;
  roundedLength = -GH_page_size & (GH_page_size + pageOffset + length) - 1;
  if (roundedLength <= (UInt32)(M<SInt32>(M<SInt32>(self + 0xc) + 0x830) * 0xc00) >> 2) {
    if (uVar9 == 0) {
      memory = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj(M<UInt32>(self + 8),
                                   M<UInt32>(M<SInt32>(self + 0xc) + 0x82c) | 0x10022,roundedLength,
                                   GH_page_size);
      if (memory != (SInt32 *)0x0) {
        uVar9 = VCALL(*memory, 0x1cc)(memory);
        goto LAB_00017310;
      }
    }
    else {
      pvVar2 = M<void *>(self + 0x24);
      pvVar5 = M<void *>(self + 0x24);
      while (candidate = pvVar2, candidate != (void *)0x0) {
        if ((((M<char>((SInt32)candidate + 0x20) == '\x04') && (M<SInt32>((SInt32)candidate + 0x54) == 0)) &&
            (pageOffset == M<UInt32>((SInt32)candidate + 0x50))) &&
           ((uVar9 == M<UInt32>((SInt32)candidate + 0x58) && (roundedLength == M<UInt32>((SInt32)candidate + 0x5c)))))
        {
          memory = (SInt32 *)GH_ZN18IOMemoryDescriptor30withPersistentMemoryDescriptorEPS_(M<UInt32>((SInt32)candidate + 8));
          if (memory == M<SInt32 *>((SInt32)candidate + 8)) {
            VCALL(*memory, 0x18)(memory);
            *param_3 = M<UInt32>((SInt32)candidate + 0x18);
            if (candidate == M<void *>(self + 0x24)) {
              return (VendorTextureBuffer *)(candidate);
            }
            M<UInt32>((SInt32)pvVar5 + 0x3c) = M<UInt32>((SInt32)candidate + 0x3c);
            M<UInt32>((SInt32)candidate + 0x3c) = M<UInt32>(self + 0x24);
            M<void *>(self + 0x24) = candidate;
            return (VendorTextureBuffer *)(candidate);
          }
          M<UInt32>((SInt32)candidate + 0x54) = 1;
          if (memory != (SInt32 *)0x0) goto LAB_00017310;
          break;
        }
        pvVar5 = candidate;
        pvVar2 = M<void *>((SInt32)candidate + 0x3c);
      }
      memory = (SInt32 *)GH_ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task(uVar9,roundedLength,0x10002,M<UInt32>(self + 8));
      if (memory != (SInt32 *)0x0) {
LAB_00017310:
        pvVar5 = (void *)VCALL(*M<SInt32 *>(self + 0xc), 0x570)(M<SInt32 *>(self + 0xc),0x80);
        if (pvVar5 == (void *)0x0) {
          VCALL(*memory, 0x18)(memory);
          return (VendorTextureBuffer *)((void *)0x0);
        }
        M<SInt32 *>((SInt32)pvVar5 + 8) = memory;
        iVar6 = this->alloc_buf_handle(pvVar5,(UInt32 *)(&handle));
        if (iVar6 != 0) {
          iVar6 = this->alloc_client_shared(handle,(sIOClientShared **)(&clientShared),(unsigned int *)(clientUserAddr));
          if (iVar6 != 0) {
            M<sIOClientShared *>((SInt32)pvVar5 + 0x14) = clientShared;
            M<UInt32>((SInt32)pvVar5 + 0x18) = clientUserAddr[0];
            M<UInt32>(clientShared) = handle;
            M<UInt32>(M<SInt32>((SInt32)pvVar5 + 0x14) + 8) =
                 M<UInt32>(M<SInt32>(self + 0xc) + 0x54);
            M<UInt32>(M<SInt32>((SInt32)pvVar5 + 0x14) + 0xc) =
                 M<UInt32>(M<SInt32>(self + 0xc) + 0x54);
            M<UInt8>(M<SInt32>((SInt32)pvVar5 + 0x14) + 0x16) = 4;
            M<UInt8>((SInt32)pvVar5 + 0x20) = 4;
            M<UInt32>((SInt32)pvVar5 + 0x50) = pageOffset;
            M<UInt32>((SInt32)pvVar5 + 0x58) = uVar9;
            M<UInt8 *>((SInt32)pvVar5 + 0x1c) = self;
            descriptorLength = VCALL(*M<SInt32 *>((SInt32)pvVar5 + 8), 0x128)(M<SInt32 *>((SInt32)pvVar5 + 8));
            M<UInt32>((SInt32)pvVar5 + 0x5c) = descriptorLength;
            M<UInt32>((SInt32)pvVar5 + 0x54) = 0;
            M<UInt32>((SInt32)pvVar5 + 0x3c) = M<UInt32>(self + 0x24);
            M<void *>(self + 0x24) = pvVar5;
            *param_3 = clientUserAddr[0];
            M<SInt32>(M<SInt32>(self + 0xc) + 0x72c) = M<SInt32>(M<SInt32>(self + 0xc) + 0x72c) + 1;
            iVar6 = M<SInt32>(self + 0xc);
            if (self != M<UInt8 *>(iVar6 + 0x6c)) {
              return (VendorTextureBuffer *)(pvVar5);
            }
            iVar3 = M<SInt32>(iVar6 + 0x70);
            M<SInt32>(M<SInt32>((SInt32)pvVar5 + 0x14) + 4) = iVar3;
            M<SInt32>(iVar6 + 0x70) = iVar3 + 1;
            return (VendorTextureBuffer *)(pvVar5);
          }
          this->free_buf_handle(pvVar5,handle);
        }
        VCALL(*memory, 0x18)(memory);
        VCALL(*M<SInt32 *>(self + 0xc), 0x574)(M<SInt32 *>(self + 0xc),pvVar5,0x80);
        return (VendorTextureBuffer *)((void *)0x0);
      }
    }
  }
  return (VendorTextureBuffer *)((void *)0x0);
}
