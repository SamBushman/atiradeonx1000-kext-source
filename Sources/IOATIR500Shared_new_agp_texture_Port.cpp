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
VendorTextureBuffer *IOATIR500Shared::new_agp_texture(unsigned int param_1, UInt32 param_2, unsigned int*param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  void *pvVar1;
  void *pvVar2;
  SInt32 iVar3;
  SInt32 *piVar4;
  void *pvVar5;
  SInt32 iVar6;
  UInt32 uVar7;
  UInt32 uVar8;
  UInt32 uVar9;
  UInt32 uVar10;
  UInt32 local_38;
  sIOClientShared *local_34;
  UInt32 local_30 [4];
  
  uVar8 = GH_page_size - 1U & param_1;
  uVar9 = param_1 & -GH_page_size;
  uVar10 = -GH_page_size & (GH_page_size + uVar8 + param_2) - 1;
  if (uVar10 <= (UInt32)(M<SInt32>(M<SInt32>(self + 0xc) + 0x830) * 0xc00) >> 2) {
    if (uVar9 == 0) {
      piVar4 = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj(M<UInt32>(self + 8),
                                   M<UInt32>(M<SInt32>(self + 0xc) + 0x82c) | 0x10022,uVar10,
                                   GH_page_size);
      if (piVar4 != (SInt32 *)0x0) {
        uVar9 = VCALL(*piVar4, 0x1cc)(piVar4);
        goto LAB_00017310;
      }
    }
    else {
      pvVar2 = M<void *>(self + 0x24);
      pvVar5 = M<void *>(self + 0x24);
      while (pvVar1 = pvVar2, pvVar1 != (void *)0x0) {
        if ((((M<char>((SInt32)pvVar1 + 0x20) == '\x04') && (M<SInt32>((SInt32)pvVar1 + 0x54) == 0)) &&
            (uVar8 == M<UInt32>((SInt32)pvVar1 + 0x50))) &&
           ((uVar9 == M<UInt32>((SInt32)pvVar1 + 0x58) && (uVar10 == M<UInt32>((SInt32)pvVar1 + 0x5c)))))
        {
          piVar4 = (SInt32 *)GH_ZN18IOMemoryDescriptor30withPersistentMemoryDescriptorEPS_(M<UInt32>((SInt32)pvVar1 + 8));
          if (piVar4 == M<SInt32 *>((SInt32)pvVar1 + 8)) {
            VCALL(*piVar4, 0x18)(piVar4);
            *param_3 = M<UInt32>((SInt32)pvVar1 + 0x18);
            if (pvVar1 == M<void *>(self + 0x24)) {
              return (VendorTextureBuffer *)(pvVar1);
            }
            M<UInt32>((SInt32)pvVar5 + 0x3c) = M<UInt32>((SInt32)pvVar1 + 0x3c);
            M<UInt32>((SInt32)pvVar1 + 0x3c) = M<UInt32>(self + 0x24);
            M<void *>(self + 0x24) = pvVar1;
            return (VendorTextureBuffer *)(pvVar1);
          }
          M<UInt32>((SInt32)pvVar1 + 0x54) = 1;
          if (piVar4 != (SInt32 *)0x0) goto LAB_00017310;
          break;
        }
        pvVar5 = pvVar1;
        pvVar2 = M<void *>((SInt32)pvVar1 + 0x3c);
      }
      piVar4 = (SInt32 *)GH_ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task(uVar9,uVar10,0x10002,M<UInt32>(self + 8));
      if (piVar4 != (SInt32 *)0x0) {
LAB_00017310:
        pvVar5 = (void *)VCALL(*M<SInt32 *>(self + 0xc), 0x570)(M<SInt32 *>(self + 0xc),0x80);
        if (pvVar5 == (void *)0x0) {
          VCALL(*piVar4, 0x18)(piVar4);
          return (VendorTextureBuffer *)((void *)0x0);
        }
        M<SInt32 *>((SInt32)pvVar5 + 8) = piVar4;
        iVar6 = this->alloc_buf_handle(pvVar5,(UInt32 *)(&local_38));
        if (iVar6 != 0) {
          iVar6 = this->alloc_client_shared(local_38,(sIOClientShared **)(&local_34),(unsigned int *)(local_30));
          if (iVar6 != 0) {
            M<sIOClientShared *>((SInt32)pvVar5 + 0x14) = local_34;
            M<UInt32>((SInt32)pvVar5 + 0x18) = local_30[0];
            M<UInt32>(local_34) = local_38;
            M<UInt32>(M<SInt32>((SInt32)pvVar5 + 0x14) + 8) =
                 M<UInt32>(M<SInt32>(self + 0xc) + 0x54);
            M<UInt32>(M<SInt32>((SInt32)pvVar5 + 0x14) + 0xc) =
                 M<UInt32>(M<SInt32>(self + 0xc) + 0x54);
            M<UInt8>(M<SInt32>((SInt32)pvVar5 + 0x14) + 0x16) = 4;
            M<UInt8>((SInt32)pvVar5 + 0x20) = 4;
            M<UInt32>((SInt32)pvVar5 + 0x50) = uVar8;
            M<UInt32>((SInt32)pvVar5 + 0x58) = uVar9;
            M<UInt8 *>((SInt32)pvVar5 + 0x1c) = self;
            uVar7 = VCALL(*M<SInt32 *>((SInt32)pvVar5 + 8), 0x128)(M<SInt32 *>((SInt32)pvVar5 + 8));
            M<UInt32>((SInt32)pvVar5 + 0x5c) = uVar7;
            M<UInt32>((SInt32)pvVar5 + 0x54) = 0;
            M<UInt32>((SInt32)pvVar5 + 0x3c) = M<UInt32>(self + 0x24);
            M<void *>(self + 0x24) = pvVar5;
            *param_3 = local_30[0];
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
          this->free_buf_handle(pvVar5,local_38);
        }
        VCALL(*piVar4, 0x18)(piVar4);
        VCALL(*M<SInt32 *>(self + 0xc), 0x574)(M<SInt32 *>(self + 0xc),pvVar5,0x80);
        return (VendorTextureBuffer *)((void *)0x0);
      }
    }
  }
  return (VendorTextureBuffer *)((void *)0x0);
}
