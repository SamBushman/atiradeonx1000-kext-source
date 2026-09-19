/*
 * IOATIR500Shared_delete_texture_Port.cpp
 *
 * IOATIR500Shared::delete_texture (real addr 0x17950, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x17950 */
IOReturn IOATIR500Shared::delete_texture(VendorTextureBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt8 VVar1;
  UInt8 *pVVar2;
  int iVar3;
  UInt8 *pVVar4;
  int *piVar5;
  UInt32 uVar6;
  int iVar7;
  unsigned int uVar8;
  UInt8 *this_00;
  
  pVVar2 = M<UInt8 *>(self + 0x24);
  if (pVVar2 == param_1) {
    M<UInt32>(self + 0x24) = M<UInt32>(param_1 + 0x3c);
  }
  else {
    if (pVVar2 == (UInt8 *)0x0) {
      return 0xe00002bc;
    }
    for (pVVar4 = M<UInt8 *>(pVVar2 + 0x3c); param_1 != pVVar4;
        pVVar4 = M<UInt8 *>(pVVar4 + 0x3c)) {
      if (pVVar4 == (UInt8 *)0x0) {
        return 0xe00002bc;
      }
      pVVar2 = pVVar4;
    }
    M<UInt32>(pVVar2 + 0x3c) = M<UInt32>(param_1 + 0x3c);
  }
  iVar7 = M<int>(param_1 + 0x24);
  VVar1 = param_1[0x20];
  M<UInt32>(iVar7 + 0x28) = M<UInt32>(param_1 + 0x28);
  iVar3 = M<int>(param_1 + 0x28);
  M<UInt8 *>(param_1 + 0x28) = param_1;
  M<int>(iVar3 + 0x24) = iVar7;
  M<UInt8 *>(param_1 + 0x24) = param_1;
  if ((((UInt8)((char)VVar1 - 2U) < 2) || (VVar1 == 0x6)) ||
     (VVar1 == 0x7)) {
    if ((VVar1 == 0x3) || (VVar1 == 0x7)) {
      iVar3 = M<int>(param_1 + 0x14);
      uVar8 = 0;
      if (M<char>(iVar3 + 0x34) != '\0') {
        do {
          iVar7 = uVar8 * 2;
          uVar8 = uVar8 + 1;
          M<UInt16>(iVar7 + iVar3 + 0x28) = 0;
          iVar3 = M<int>(param_1 + 0x14);
        } while (uVar8 < M<UInt8>(iVar3 + 0x34));
      }
      if (M<int>(param_1 + 0x48) != 0) {
        VCALL(*M<int *>(self + 0xc), 0x524)(M<int *>(self + 0xc),param_1);
      }
    }
    if (M<int *>(param_1 + 0x10) != (int *)0x0) {
      VCALL(*M<int *>(param_1 + 0x10), 0x18)(M<int *>(param_1 + 0x10));
      M<UInt32>(param_1 + 0x10) = 0;
    }
    if (param_1[0x20] == 0x7) {
      pVVar2 = M<UInt8 *>(param_1 + 0x58);
      M<UInt32>(param_1 + 0x58) = 0;
LAB_00017ac4:
      iVar3 = GH_OSDecrementAtomic(M<int>(pVVar2 + 0x14) + 0x10);
      if (iVar3 == 1) {
        this->delete_texture((VendorTextureBuffer *)(pVVar2));
      }
    }
    else if (param_1[0x20] == 0x6) {
      pVVar2 = M<UInt8 *>(param_1 + 0x54);
      M<UInt32>(param_1 + 0x54) = 0;
      goto LAB_00017ac4;
    }
    if (M<int>(param_1 + 4) != 0) {
      piVar5 = M<int *>(self + 0xc);
      iVar3 = *piVar5;
      uVar6 = M<UInt32>(M<int>(param_1 + 0x14) + 0xc);
LAB_00017b60:
      iVar3 = VCALL(iVar3, 0x554)(piVar5,uVar6);
      if (iVar3 == 0) {
        ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0xc)))->addOrphanTexture((IOTextureBuffer *)((UInt8 *)param_1));
        goto LAB_00017cf0;
      }
      if (M<int>(param_1 + 4) != 0) {
        VCALL(*M<int *>(self + 0xc), 0x5ac)(M<int *>(self + 0xc),param_1);
      }
    }
LAB_00017ba0:
    this->free_buf_handle(param_1,*M<UInt32 *>(param_1 + 0x14));
    if (M<int *>(param_1 + 8) != (int *)0x0) {
      VCALL(*M<int *>(param_1 + 8), 0x18)(M<int *>(param_1 + 8));
      M<UInt32>(param_1 + 8) = 0;
    }
  }
  else {
    if (VVar1 == 0x4) {
      if (M<int *>(param_1 + 0x10) != (int *)0x0) {
        VCALL(*M<int *>(param_1 + 0x10), 0x18)(M<int *>(param_1 + 0x10));
        M<UInt32>(param_1 + 0x10) = 0;
      }
      if (M<int>(param_1 + 4) != 0) {
        piVar5 = M<int *>(self + 0xc);
        iVar3 = *piVar5;
        uVar6 = M<UInt32>(M<int>(param_1 + 0x14) + 8);
        goto LAB_00017b60;
      }
      goto LAB_00017ba0;
    }
    if (VVar1 == 0x0) {
      this_00 = M<UInt8 *>(param_1 + 0x50);
      if (this_00 != (UInt8 *)0x0) {
        pVVar2 = M<UInt8 *>(this_00 + 0xbcc);
        if (param_1 == M<UInt8 *>(this_00 + 0xbcc)) {
          M<UInt32>(this_00 + 0xbcc) = M<UInt32>(param_1 + 0x54);
        }
        else {
          do {
            pVVar4 = pVVar2;
            if (pVVar4 == (UInt8 *)0x0) break;
            pVVar2 = M<UInt8 *>(pVVar4 + 0x54);
          } while (param_1 != M<UInt8 *>(pVVar4 + 0x54));
          M<UInt32>(pVVar4 + 0x54) = M<UInt32>(param_1 + 0x54);
        }
        ((IOATIR500Surface *)(this_00))->reset_req_bits();
        ((IOATIR500Surface *)(this_00))->prune_buffers();
      }
    }
    else {
      if (VVar1 != 0x1) goto LAB_00017cf0;
      pVVar2 = M<UInt8 *>(param_1 + 0x50);
      if (pVVar2 != (UInt8 *)0x0) {
        iVar3 = GH_OSDecrementAtomic(M<int>(pVVar2 + 0x14) + 0x10);
        if (iVar3 == 1) {
          ((IOATIR500Shared *)(M<UInt8 *>(M<int>(self + 0xc) + 0x6c)))->delete_texture((VendorTextureBuffer *)pVVar2);
        }
        VCALL(*M<int *>(M<int>(self + 0xc) + 0x6c), 0x18)(M<int *>(M<int>(self + 0xc) + 0x6c));
        M<UInt32>(param_1 + 0x50) = 0;
      }
    }
    this->free_buf_handle(param_1,*M<UInt32 *>(param_1 + 0x14));
  }
  VCALL(*M<int *>(self + 0xc), 0x574)(M<int *>(self + 0xc),param_1,0x80);
LAB_00017cf0:
  M<int>(M<int>(self + 0xc) + 0x72c) = M<int>(M<int>(self + 0xc) + 0x72c) + -1;
  return 0;
}
