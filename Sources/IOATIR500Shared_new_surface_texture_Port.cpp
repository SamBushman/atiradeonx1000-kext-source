/*
 * IOATIR500Shared_new_surface_texture_Port.cpp
 *
 * IOATIR500Shared::new_surface_texture (real addr 0x17520, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x17520 */
VendorTextureBuffer *IOATIR500Shared::new_surface_texture(UInt32 param_1, UInt32 param_2, UInt32 param_3, unsigned int*param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt8 *this_00;
  void *pvVar2;
  SInt32 iVar3;
  UInt32 local_38;
  sIOClientShared *local_34;
  UInt32 local_30 [4];
  
  this_00 = (UInt8 *)
            ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0xc)))->find_surface_for_id(param_1);
  if ((this_00 != (UInt8 *)0x0) &&
     (pvVar2 = (void *)VCALL(*M<SInt32 *>(self + 0xc), 0x570)(M<SInt32 *>(self + 0xc),0x80),
     pvVar2 != (void *)0x0)) {
    M<UInt32>((SInt32)pvVar2 + 8) = 0;
    iVar3 = this->alloc_buf_handle(pvVar2,(UInt32 *)(&local_38));
    if (iVar3 != 0) {
      iVar3 = this->alloc_client_shared(local_38,(sIOClientShared **)(&local_34),(unsigned int *)(local_30));
      if (iVar3 != 0) {
        M<sIOClientShared *>((SInt32)pvVar2 + 0x14) = local_34;
        M<UInt32>(local_34) = local_38;
        M<UInt32>(M<SInt32>((SInt32)pvVar2 + 0x14) + 8) =
             M<UInt32>(M<SInt32>(self + 0xc) + 0x54);
        M<UInt32>(M<SInt32>((SInt32)pvVar2 + 0x14) + 0xc) =
             M<UInt32>(M<SInt32>(self + 0xc) + 0x54);
        M<UInt8>(M<SInt32>((SInt32)pvVar2 + 0x14) + 0x16) = 0;
        M<char>(M<SInt32>((SInt32)pvVar2 + 0x14) + 0x34) = (char)param_3;
        M<UInt8>((SInt32)pvVar2 + 0x20) = 0;
        M<UInt32>((SInt32)pvVar2 + 0x10) = 0;
        M<UInt32>((SInt32)pvVar2 + 0x58) = param_2;
        M<UInt32>((SInt32)pvVar2 + 0x5c) = param_1;
        M<UInt8 *>((SInt32)pvVar2 + 0x1c) = self;
        M<UInt8 *>((SInt32)pvVar2 + 0x50) = this_00;
        M<UInt32>((SInt32)pvVar2 + 0x3c) = M<UInt32>(self + 0x24);
        M<void *>(self + 0x24) = pvVar2;
        *param_4 = local_30[0];
        M<UInt32>((SInt32)pvVar2 + 0x54) = M<UInt32>(this_00 + 0xbcc);
        M<void *>(this_00 + 0xbcc) = pvVar2;
        ((IOATIR500Surface *)(this_00))->reset_req_bits();
        ((IOATIR500Surface *)(this_00))->prune_buffers();
        M<SInt32>(M<SInt32>(self + 0xc) + 0x72c) = M<SInt32>(M<SInt32>(self + 0xc) + 0x72c) + 1;
        iVar3 = M<SInt32>(self + 0xc);
        if (self != M<UInt8 *>(iVar3 + 0x6c)) {
          return (VendorTextureBuffer *)(pvVar2);
        }
        iVar1 = M<SInt32>(iVar3 + 0x70);
        M<SInt32>(M<SInt32>((SInt32)pvVar2 + 0x14) + 4) = iVar1;
        M<SInt32>(iVar3 + 0x70) = iVar1 + 1;
        return (VendorTextureBuffer *)(pvVar2);
      }
      this->free_buf_handle(pvVar2,local_38);
    }
    VCALL(*M<SInt32 *>(self + 0xc), 0x574)(M<SInt32 *>(self + 0xc),pvVar2,0x80);
    return (VendorTextureBuffer *)((void *)0x0);
  }
  return (VendorTextureBuffer *)((void *)0x0);
}
