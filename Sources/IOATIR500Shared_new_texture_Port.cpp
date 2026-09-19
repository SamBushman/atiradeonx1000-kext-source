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
VendorTextureBuffer *IOATIR500Shared::new_texture(UInt32 param_1, UInt32 param_2, unsigned int param_3, UInt32 param_4, unsigned int *real_param_5, unsigned int *real_param_6) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    unsigned int *param_5 = real_param_5;
    unsigned int *param_6 = real_param_6;

  int iVar1;
  UInt8 *pVVar2;
  int *piVar3;
  void *pvVar4;
  int *piVar5;
  int iVar6;
  char cVar7;
  unsigned int uVar8;
  UInt32 local_48;
  sIOClientShared *local_44;
  unsigned int local_40;
  unsigned int auStack_3c [6];
  
  if ((param_3 == 0) || (param_4 == 0)) {
    if (param_2 == 0) {
      pVVar2 = (UInt8 *)0x0;
      cVar7 = '\x02';
      iVar6 = 0x80;
    }
    else {
      pVVar2 = (UInt8 *)0x0;
      cVar7 = '\x03';
      iVar6 = 0xa00;
    }
  }
  else {
    pVVar2 = (UInt8 *)this->new_agp_texture(param_3,param_4,(unsigned int *)(auStack_3c));
    if (pVVar2 == (UInt8 *)0x0) {
      return (VendorTextureBuffer *)((void *)0x0);
    }
    cVar7 = '\a';
    iVar6 = 0xa00;
  }
  piVar3 = M<int *>(self + 0xc);
  uVar8 = iVar6 + param_1 + GH_page_size + 7 & -GH_page_size;
  if (uVar8 <= (unsigned int)(piVar3[0x20c] * 0xc00) >> 2) {
    pvVar4 = (void *)VCALL(*piVar3, 0x570)(piVar3,0x80);
    if (pvVar4 == (void *)0x0) {
      if (pVVar2 == (UInt8 *)0x0) {
        return (VendorTextureBuffer *)((void *)0x0);
      }
      if (M<int>(M<int>(pVVar2 + 0x14) + 0x10) != 0) {
        return (VendorTextureBuffer *)((void *)0x0);
      }
      this->delete_texture((VendorTextureBuffer *)(pVVar2));
      return (VendorTextureBuffer *)((void *)0x0);
    }
    piVar3 = (int *)GH_ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj(M<UInt32>(self + 8),
                                 M<unsigned int>(M<int>(self + 0xc) + 0x82c) | 0x10022,uVar8,
                                 GH_page_size);
    if (piVar3 != (int *)0x0) {
      M<int *>((int)pvVar4 + 8) = piVar3;
      iVar6 = this->alloc_buf_handle(pvVar4,(UInt32 *)(&local_48));
      if (iVar6 != 0) {
        iVar6 = this->alloc_client_shared(local_48,(sIOClientShared **)(&local_44),(unsigned int *)(&local_40));
        if (iVar6 != 0) {
          M<sIOClientShared *>((int)pvVar4 + 0x14) = local_44;
          M<unsigned int>((int)pvVar4 + 0x18) = local_40;
          M<UInt32>(local_44) = local_48;
          M<UInt32>(M<int>((int)pvVar4 + 0x14) + 8) =
               M<UInt32>(M<int>(self + 0xc) + 0x54);
          M<UInt32>(M<int>((int)pvVar4 + 0x14) + 0xc) =
               M<UInt32>(M<int>(self + 0xc) + 0x54);
          M<char>(M<int>((int)pvVar4 + 0x14) + 0x16) = cVar7;
          M<char>((int)pvVar4 + 0x20) = cVar7;
          M<UInt8 *>((int)pvVar4 + 0x1c) = self;
          piVar5 = (int *)VCALL(*piVar3, 0x14c)
                                    (piVar3,M<UInt32>(self + 8),0,
                                     M<unsigned int>(M<int>(self + 0xc) + 0x82c) | 1,0,0);
          if (piVar5 != (int *)0x0) {
            M<int *>((int)pvVar4 + 0x10) = piVar5;
            if (cVar7 == '\x03') {
              M<UInt32>((int)pvVar4 + 0x50) = param_2;
            }
            else if (cVar7 != '\x02') {
              M<UInt32>((int)pvVar4 + 0x50) = param_2;
              M<UInt8 *>((int)pvVar4 + 0x58) = pVVar2;
              GH_OSIncrementAtomic(M<int>(pVVar2 + 0x14) + 0x10);
            }
            M<UInt32>((int)pvVar4 + 0x3c) = M<UInt32>(self + 0x24);
            M<void *>(self + 0x24) = pvVar4;
            uVar8 = VCALL(*piVar5, 0xd0)(piVar5);
            *param_5 = uVar8;
            *param_6 = local_40;
            M<int>(M<int>(self + 0xc) + 0x72c) = M<int>(M<int>(self + 0xc) + 0x72c) + 1;
            iVar6 = M<int>(self + 0xc);
            if (self == M<UInt8 *>(iVar6 + 0x6c)) {
              iVar1 = M<int>(iVar6 + 0x70);
              M<int>(M<int>((int)pvVar4 + 0x14) + 4) = iVar1;
              M<int>(iVar6 + 0x70) = iVar1 + 1;
              return (VendorTextureBuffer *)(pvVar4);
            }
            return (VendorTextureBuffer *)(pvVar4);
          }
          this->free_buf_handle(pvVar4,*M<UInt32 *>((int)pvVar4 + 0x14));
          VCALL(*piVar3, 0x18)(piVar3);
          M<UInt32>((int)pvVar4 + 8) = 0;
          goto joined_r0x0001834c;
        }
        this->free_buf_handle(pvVar4,local_48);
      }
      VCALL(*piVar3, 0x18)(piVar3);
      M<UInt32>((int)pvVar4 + 8) = 0;
    }
    if ((pVVar2 != (UInt8 *)0x0) && (M<int>(M<int>(pVVar2 + 0x14) + 0x10) == 0)) {
      this->delete_texture((VendorTextureBuffer *)(pVVar2));
    }
    VCALL(*M<int *>(self + 0xc), 0x574)(M<int *>(self + 0xc),pvVar4,0x80);
    return (VendorTextureBuffer *)((void *)0x0);
  }
joined_r0x0001834c:
  if ((pVVar2 != (UInt8 *)0x0) && (M<int>(M<int>(pVVar2 + 0x14) + 0x10) == 0)) {
    this->delete_texture((VendorTextureBuffer *)(pVVar2));
    return (VendorTextureBuffer *)((void *)0x0);
  }
  return (VendorTextureBuffer *)((void *)0x0);
}
