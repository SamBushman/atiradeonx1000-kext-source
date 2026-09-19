/*
 * IOATIR500Shared_new_global_texture_Port.cpp
 *
 * IOATIR500Shared::new_global_texture (real addr 0x17740, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x17740 */
VendorTextureBuffer *IOATIR500Shared::new_global_texture(UInt32 param_1, unsigned int *real_param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    unsigned int *param_2 = reinterpret_cast<unsigned int *>(real_param_2);

  UInt8 *pIVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  UInt32 local_28;
  sIOClientShared *local_24;
  unsigned int local_20 [4];
  
  if (param_1 != 0) {
    piVar2 = M<int *>(self + 0xc);
    pIVar1 = (UInt8 *)piVar2[0x1b];
    if ((pIVar1 != (UInt8 *)0x0) && (self != pIVar1)) {
      for (iVar5 = M<int>(pIVar1 + 0x24); iVar5 != 0; iVar5 = M<int>(iVar5 + 0x3c)) {
        if (param_1 == M<UInt32>(M<int>(iVar5 + 0x14) + 4)) {
          pvVar3 = (void *)VCALL(*piVar2, 0x570)(piVar2,0x80);
          if (pvVar3 == (void *)0x0) {
            return (VendorTextureBuffer *)((void *)0x0);
          }
          iVar4 = this->alloc_buf_handle(pvVar3,(UInt32 *)(&local_28));
          if (iVar4 != 0) {
            iVar4 = this->alloc_client_shared(local_28,(sIOClientShared **)(&local_24),(unsigned int *)(local_20));
            if (iVar4 != 0) {
              M<UInt32>((int)pvVar3 + 8) = 0;
              M<sIOClientShared *>((int)pvVar3 + 0x14) = local_24;
              M<UInt32>(local_24) = local_28;
              M<UInt32>(M<int>((int)pvVar3 + 0x14) + 8) =
                   M<UInt32>(M<int>(self + 0xc) + 0x54);
              M<UInt32>(M<int>((int)pvVar3 + 0x14) + 0xc) =
                   M<UInt32>(M<int>(self + 0xc) + 0x54);
              M<UInt8>(M<int>((int)pvVar3 + 0x14) + 0x16) = 1;
              M<UInt8>((int)pvVar3 + 0x20) = 1;
              M<UInt32>((int)pvVar3 + 0x10) = 0;
              M<UInt8 *>((int)pvVar3 + 0x1c) = self;
              M<int>((int)pvVar3 + 0x50) = iVar5;
              GH_OSIncrementAtomic(M<int>(iVar5 + 0x14) + 0x10);
              VCALL(*M<int *>(M<int>(self + 0xc) + 0x6c), 0x14)(M<int *>(M<int>(self + 0xc) + 0x6c));
              M<UInt32>((int)pvVar3 + 0x3c) = M<UInt32>(self + 0x24);
              M<void *>(self + 0x24) = pvVar3;
              *param_2 = local_20[0];
              M<int>(M<int>(self + 0xc) + 0x72c) = M<int>(M<int>(self + 0xc) + 0x72c) + 1;
              return (VendorTextureBuffer *)(pvVar3);
            }
            this->free_buf_handle(pvVar3,local_28);
          }
          VCALL(*M<int *>(self + 0xc), 0x574)(M<int *>(self + 0xc),pvVar3,0x80);
          return (VendorTextureBuffer *)((void *)0x0);
        }
      }
    }
  }
  return (VendorTextureBuffer *)((void *)0x0);
}
