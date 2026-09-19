/*
 * IOATIR500Shared_new_agpref_texture_Port.cpp
 *
 * IOATIR500Shared::new_agpref_texture (real addr 0x17df0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x17df0 */
VendorTextureBuffer *IOATIR500Shared::new_agpref_texture(unsigned int param_1, unsigned int param_2, UInt32 param_3, unsigned int*param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt8 *pVVar2;
  void *pvVar3;
  SInt32 iVar4;
  UInt32 uStack_38;
  UInt32 local_34;
  sIOClientShared *local_30;
  UInt32 local_2c [6];
  
  pVVar2 = (UInt8 *)this->new_agp_texture(param_2,param_3,(unsigned int *)(&uStack_38));
  if (pVVar2 != (UInt8 *)0x0) {
    pvVar3 = (void *)VCALL(*M<SInt32 *>(self + 0xc), 0x570)(M<SInt32 *>(self + 0xc),0x80);
    if (pvVar3 != (void *)0x0) {
      iVar4 = this->alloc_buf_handle(pvVar3,(UInt32 *)(&local_34));
      if (iVar4 != 0) {
        iVar4 = this->alloc_client_shared(local_34,(sIOClientShared **)(&local_30),(unsigned int *)(local_2c));
        if (iVar4 != 0) {
          iVar4 = 0;
          M<sIOClientShared *>((SInt32)pvVar3 + 0x14) = local_30;
          M<UInt32>((SInt32)pvVar3 + 0x18) = local_2c[0];
          M<UInt32>(local_30) = local_34;
          M<UInt32>(M<SInt32>((SInt32)pvVar3 + 0x14) + 8) =
               M<UInt32>(M<SInt32>(self + 0xc) + 0x54);
          M<UInt32>(M<SInt32>((SInt32)pvVar3 + 0x14) + 0xc) =
               M<UInt32>(M<SInt32>(self + 0xc) + 0x54);
          M<UInt8>(M<SInt32>((SInt32)pvVar3 + 0x14) + 0x16) = 6;
          M<UInt8>((SInt32)pvVar3 + 0x20) = 6;
          M<UInt8 *>((SInt32)pvVar3 + 0x1c) = self;
          if (param_1 != 0) {
            iVar4 = param_1 - M<SInt32>(pVVar2 + 0x58);
          }
          M<SInt32>((SInt32)pvVar3 + 0x50) = iVar4;
          M<UInt8 *>((SInt32)pvVar3 + 0x54) = pVVar2;
          GH_OSIncrementAtomic(M<SInt32>(pVVar2 + 0x14) + 0x10);
          M<UInt32>((SInt32)pvVar3 + 0x3c) = M<UInt32>(self + 0x24);
          M<void *>(self + 0x24) = pvVar3;
          *param_4 = local_2c[0];
          M<SInt32>(M<SInt32>(self + 0xc) + 0x72c) = M<SInt32>(M<SInt32>(self + 0xc) + 0x72c) + 1;
          iVar4 = M<SInt32>(self + 0xc);
          if (self != M<UInt8 *>(iVar4 + 0x6c)) {
            return (VendorTextureBuffer *)(pvVar3);
          }
          iVar1 = M<SInt32>(iVar4 + 0x70);
          M<SInt32>(M<SInt32>((SInt32)pvVar3 + 0x14) + 4) = iVar1;
          M<SInt32>(iVar4 + 0x70) = iVar1 + 1;
          return (VendorTextureBuffer *)(pvVar3);
        }
        this->free_buf_handle(pvVar3,local_34);
      }
      if (M<SInt32>(M<SInt32>(pVVar2 + 0x14) + 0x10) == 0) {
        this->delete_texture((VendorTextureBuffer *)(pVVar2));
      }
      VCALL(*M<SInt32 *>(self + 0xc), 0x574)(M<SInt32 *>(self + 0xc),pvVar3,0x80);
      return (VendorTextureBuffer *)((void *)0x0);
    }
    if (M<SInt32>(M<SInt32>(pVVar2 + 0x14) + 0x10) == 0) {
      this->delete_texture((VendorTextureBuffer *)(pVVar2));
      return (VendorTextureBuffer *)((void *)0x0);
    }
  }
  return (VendorTextureBuffer *)((void *)0x0);
}
