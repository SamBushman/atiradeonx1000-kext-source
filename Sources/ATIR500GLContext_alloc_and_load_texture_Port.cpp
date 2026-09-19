/*
 * ATIR500GLContext_alloc_and_load_texture_Port.cpp
 *
 * ATIR500GLContext::alloc_and_load_texture (real addr 0x2a3d0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOGetTime(...) asm("_IOGetTime");


/* real addr 0x2a3d0 */
void ATIR500GLContext::alloc_and_load_texture(VendorTextureBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt8 VVar1;
  bool bVar2;
  SInt32 iVar3;
  SInt32 iVar4;
  UInt8 *this_00;
  UInt8 *pVVar5;
  UInt32 local_28 [6];
  
  VVar1 = param_1[0x20];
  if (VVar1 == 0x3) {
    if ((((M<SInt32>(param_1 + 0x48) == 0) &&
         (iVar3 = VCALL(*M<SInt32 *>(self + 200), 0x528)(M<SInt32 *>(self + 200)), iVar3 == 0)) &&
        (iVar3 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->freeToAllocTextureVRAM((IOATIR500Surface *)(M<UInt8 *>(self + 0x290)),
                            (VendorTextureBuffer **)((UInt8 **)(self + 0x2a4)),0x2a,(VendorTextureBuffer *)(param_1)), iVar3 == 0)) &&
       (iVar3 = this->compact_current_textures((VendorTextureBuffer *)(param_1)), iVar3 == 0)) {
      return;
    }
    goto LAB_0002a650;
  }
  if (VVar1 == 0x2) {
    if ((M<SInt32>(param_1 + 4) != 0) ||
       (((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)param_1)),
       M<SInt32>(param_1 + 4) != 0)) {
      GH_IOGetTime(param_1 + 0x2c);
      iVar3 = M<SInt32>(param_1 + 0x34);
      M<UInt32>(iVar3 + 0x38) = M<UInt32>(param_1 + 0x38);
      M<SInt32>(M<SInt32>(param_1 + 0x38) + 0x34) = iVar3;
      M<UInt32>(param_1 + 0x34) = M<UInt32>(M<SInt32>(self + 200) + 0x6d0);
      M<SInt32>(param_1 + 0x38) = M<SInt32>(self + 200) + 0x69c;
      M<UInt8 *>(M<SInt32>(self + 200) + 0x6d0) = param_1;
      M<UInt8 *>(M<SInt32>(param_1 + 0x34) + 0x38) = param_1;
    }
    goto LAB_0002a65c;
  }
  if (VVar1 == 0x6) {
    pVVar5 = M<UInt8 *>(param_1 + 0x54);
    if ((M<SInt32>(pVVar5 + 4) != 0) ||
       (((IOATIR500GLContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar5)),
       M<SInt32>(pVVar5 + 4) != 0)) {
      GH_IOGetTime(pVVar5 + 0x2c);
      iVar3 = M<SInt32>(pVVar5 + 0x34);
      M<UInt32>(iVar3 + 0x38) = M<UInt32>(pVVar5 + 0x38);
      M<SInt32>(M<SInt32>(pVVar5 + 0x38) + 0x34) = iVar3;
      M<UInt32>(pVVar5 + 0x34) = M<UInt32>(M<SInt32>(self + 200) + 0x6d0);
      M<SInt32>(pVVar5 + 0x38) = M<SInt32>(self + 200) + 0x69c;
      M<UInt8 *>(M<SInt32>(self + 200) + 0x6d0) = pVVar5;
      M<UInt8 *>(M<SInt32>(pVVar5 + 0x34) + 0x38) = pVVar5;
    }
    M<UInt8>(M<SInt32>(param_1 + 0x14) + 0x14) = 0;
    M<UInt8>(M<SInt32>(pVVar5 + 0x14) + 0x14) = 0;
    return;
  }
  if (VVar1 != 0x7) {
    if (VVar1 == 0x0) {
      this_00 = M<UInt8 *>(param_1 + 0x50);
      if (this_00 == (UInt8 *)0x0) {
        this_00 = (UInt8 *)
                  ((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->find_surface_for_id(M<UInt32>(param_1 + 0x5c));
        M<UInt8 *>(param_1 + 0x50) = this_00;
        if (this_00 == (UInt8 *)0x0) {
          return;
        }
        M<UInt32>(param_1 + 0x54) = M<UInt32>(this_00 + 0xbcc);
        M<UInt8 *>(this_00 + 0xbcc) = param_1;
      }
      if ((M<UInt32>(this_00 + 0xbf8) & 0x20000000) != 0) {
        return;
      }
      ((IOATIR500Surface *)(this_00))->surface_buffer_idx_mask(M<UInt32>(param_1 + 0x58), (UInt32 *)(local_28));
      M<UInt8>(M<SInt32>(param_1 + 0x14) + 0x14) = 0;
      if ((local_28[0] & M<UInt32>(this_00 + 0xc18) & M<UInt32>(this_00 + 0xbf8)) == 0) {
        return;
      }
      iVar3 = ((IOATIR500Surface *)(this_00))->alloc_surfaces_keep((IOATIR500Surface *)(M<UInt8 *>(self + 0x290)),
                         (VendorTextureBuffer **)((UInt8 **)(self + 0x2a4)),0x2a,local_28[0]);
      bVar2 = false;
      if (iVar3 != 0) {
        iVar3 = this->compact_current_textures((VendorTextureBuffer *)(param_1));
        bVar2 = iVar3 == 0;
      }
      M<UInt8>(M<SInt32>(param_1 + 0x14) + 0x14) =
           1U - !bVar2 | M<UInt8>(M<SInt32>(param_1 + 0x14) + 0x14);
      return;
    }
    if (VVar1 == 0x1) {
      if (M<UInt8 *>(param_1 + 0x50) == (UInt8 *)0x0) {
        return;
      }
      this->alloc_and_load_texture((VendorTextureBuffer *)(M<UInt8 *>(param_1 + 0x50)));
      return;
    }
    if (VVar1 != 0x8) {
      return;
    }
    if ((M<SInt32>(param_1 + 0x48) == 0) && (M<SInt32>(param_1 + 8) != 0)) {
      if (M<SInt32>(param_1 + 4) != 0) goto LAB_0002a798;
      ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)param_1));
    }
    if (M<SInt32>(param_1 + 4) == 0) {
      return;
    }
LAB_0002a798:
    GH_IOGetTime(param_1 + 0x2c);
    iVar3 = M<SInt32>(param_1 + 0x34);
    M<UInt32>(iVar3 + 0x38) = M<UInt32>(param_1 + 0x38);
    M<SInt32>(M<SInt32>(param_1 + 0x38) + 0x34) = iVar3;
    M<UInt32>(param_1 + 0x34) = M<UInt32>(M<SInt32>(self + 200) + 0x6d0);
    M<SInt32>(param_1 + 0x38) = M<SInt32>(self + 200) + 0x69c;
    M<UInt8 *>(M<SInt32>(self + 200) + 0x6d0) = param_1;
    M<UInt8 *>(M<SInt32>(param_1 + 0x34) + 0x38) = param_1;
    return;
  }
  if (M<SInt32>(param_1 + 0x48) == 0) {
LAB_0002a5f4:
    iVar3 = VCALL(*M<SInt32 *>(self + 200), 0x528)(M<SInt32 *>(self + 200),param_1);
    if (((iVar3 == 0) &&
        (iVar3 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->freeToAllocTextureVRAM((IOATIR500Surface *)(M<UInt8 *>(self + 0x290)),
                            (VendorTextureBuffer **)((UInt8 **)(self + 0x2a4)),0x2a,(VendorTextureBuffer *)(param_1)), iVar3 == 0)) &&
       (iVar3 = this->compact_current_textures((VendorTextureBuffer *)(param_1)), iVar3 == 0)) {
      iVar3 = M<SInt32>(param_1 + 0x24);
      M<UInt32>(iVar3 + 0x28) = M<UInt32>(param_1 + 0x28);
      iVar4 = M<SInt32>(param_1 + 0x28);
      M<UInt8 *>(param_1 + 0x28) = param_1;
      M<SInt32>(iVar4 + 0x24) = iVar3;
      M<UInt8 *>(param_1 + 0x24) = param_1;
      return;
    }
  }
  else if ((M<UInt8>(M<SInt32>(param_1 + 0x14) + 0x14) & 2) != 0) {
    VCALL(*M<SInt32 *>(self + 200), 0x524)(M<SInt32 *>(self + 200));
    M<UInt8>(M<SInt32>(param_1 + 0x14) + 0x14) = 1;
    M<UInt16>(M<SInt32>(param_1 + 0x14) + 0x28) = 0;
    M<UInt16>(M<SInt32>(param_1 + 0x14) + 0x2a) = 0;
    M<UInt16>(M<SInt32>(param_1 + 0x14) + 0x2c) = 0;
    M<UInt16>(M<SInt32>(param_1 + 0x14) + 0x2e) = 0;
    M<UInt16>(M<SInt32>(param_1 + 0x14) + 0x30) = 0;
    M<UInt16>(M<SInt32>(param_1 + 0x14) + 0x32) = 0;
    M<UInt32>(param_1 + 0x50) = M<UInt32>(M<SInt32>(param_1 + 0x14) + 0x18);
    if (M<SInt32>(param_1 + 0x48) == 0) goto LAB_0002a5f4;
  }
LAB_0002a650:
  this->load_texture((VendorTextureBuffer *)(param_1));
LAB_0002a65c:
  M<UInt8>(M<SInt32>(param_1 + 0x14) + 0x14) = 0;
  return;
}
