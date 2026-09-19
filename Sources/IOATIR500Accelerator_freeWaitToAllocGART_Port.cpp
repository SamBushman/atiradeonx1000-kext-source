/*
 * IOATIR500Accelerator_freeWaitToAllocGART_Port.cpp
 *
 * IOATIR500Accelerator::freeWaitToAllocGART (real addr 0x37f0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x37f0 */
bool IOATIR500Accelerator::freeWaitToAllocGART(IOATIR5002DContext *real_param_1, IOATIR500DVDContext *real_param_2, IOATIR500GLContext *real_param_3, IOATIR500Surface *real_param_4, IOATIR500Shared *real_param_5, VendorTransferBuffer *real_param_6, bool param_7) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);
    UInt8 *param_2 = reinterpret_cast<UInt8 *>(real_param_2);
    UInt8 *param_3 = reinterpret_cast<UInt8 *>(real_param_3);
    UInt8 *param_4 = reinterpret_cast<UInt8 *>(real_param_4);
    UInt8 *param_5 = reinterpret_cast<UInt8 *>(real_param_5);
    UInt8 *param_6 = reinterpret_cast<UInt8 *>(real_param_6);

  UInt16 uVar1;
  UInt8 *pIVar2;
  SInt32 iVar3;
  UInt8 *pIVar4;
  UInt32 uVar5;
  UInt32 in_register_00000028;
  UInt32 uVar6;
  UInt8 *this_00;
  UInt8 *this_01;
  UInt8 *this_02;
  UInt8 *this_03;
  UInt8 *pVVar7;
  
  if (M<UInt8 *>(self + 0x664) != self + 0x63c) {
    this->freeOrphanTexture(param_7);
    iVar3 = VCALL(M<SInt32>(self), 0x5a8)(self,param_6);
    if (iVar3 != 0) {
      return 1;
    }
  }
  for (this_00 = M<UInt8 *>(self + 100); this_00 != (UInt8 *)0x0;
      this_00 = M<UInt8 *>(this_00 + 0x80)) {
    if (this_00 != param_1) {
      pIVar4 = M<UInt8 *>(this_00 + 0x88);
      if (((pIVar4 != (UInt8 *)0x0) && (param_5 != pIVar4)) &&
         (iVar3 = ((IOATIR500Shared *)(pIVar4))->freeToAllocGART((VendorTransferBuffer *)(param_6), param_7), iVar3 != 0)) {
        return 1;
      }
      iVar3 = ((IOATIR5002DContext *)(this_00))->freeToAllocGART((VendorTransferBuffer *)(param_6), param_7);
      if (iVar3 != 0) {
        return 1;
      }
    }
  }
  for (this_01 = M<UInt8 *>(self + 0x68); this_01 != (UInt8 *)0x0;
      this_01 = M<UInt8 *>(this_01 + 0x80)) {
    if (this_01 != param_2) {
      pIVar4 = M<UInt8 *>(this_01 + 0x84);
      if (((pIVar4 != (UInt8 *)0x0) && (param_5 != pIVar4)) &&
         (iVar3 = ((IOATIR500Shared *)(pIVar4))->freeToAllocGART((VendorTransferBuffer *)(param_6), param_7), iVar3 != 0)) {
        return 1;
      }
      iVar3 = ((IOATIR500DVDContext *)(this_01))->freeToAllocGART((VendorTransferBuffer *)(param_6), param_7);
      if (iVar3 != 0) {
        return 1;
      }
    }
  }
  for (this_02 = M<UInt8 *>(self + 0x60); this_02 != (UInt8 *)0x0;
      this_02 = M<UInt8 *>(this_02 + 0x80)) {
    if (this_02 != param_3) {
      if ((param_5 != M<UInt8 *>(this_02 + 0x88)) &&
         (iVar3 = ((IOATIR500Shared *)(M<UInt8 *>(this_02 + 0x88)))->freeToAllocGART((VendorTransferBuffer *)(param_6),param_7), iVar3 != 0)) {
        return 1;
      }
      iVar3 = ((IOATIR500GLContext *)(this_02))->freeToAllocGART((VendorTransferBuffer *)(param_6), param_7);
      if (iVar3 != 0) {
        return 1;
      }
    }
  }
  pIVar2 = M<UInt8 *>(self + 0x5c);
  this_03 = pIVar2;
  if (pIVar2 != (UInt8 *)0x0) {
    do {
      this_03 = M<UInt8 *>(this_03 + 0xa0);
      if (param_4 != this_03) {
        iVar3 = ((IOATIR500Surface *)(this_03))->freeToAllocGART((VendorTransferBuffer *)(param_6), param_7);
        if (iVar3 != 0) {
          return 1;
        }
        pIVar2 = M<UInt8 *>(self + 0x5c);
      }
    } while (this_03 != pIVar2);
  }
  if ((param_5 == (UInt8 *)0x0) ||
     (iVar3 = ((IOATIR500Shared *)(param_5))->freeToAllocGART((VendorTransferBuffer *)(param_6), param_7), iVar3 == 0)) {
    if (((UInt32)param_7) == 0) {
      uVar1 = M<UInt16>(self + 0x5c6);
      uVar5 = (UInt32)M<UInt16>(self + 0x5c4);
      if (uVar1 != 0) {
        uVar6 = 0;
        do {
          uVar5 = uVar5 - 1 & uVar1 - 1;
          iVar3 = this->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + uVar5 * 0x1c + 0x404)),(VendorTransferBuffer *)(param_6),
                             M<UInt32>(self + uVar5 * 0x1c + 0x414),false);
          if (iVar3 != 0) {
            return 1;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < M<UInt16>(self + 0x5c6));
      }
      uVar1 = M<UInt16>(self + 0x402);
      uVar5 = (UInt32)M<UInt16>(self + 0x400);
      if (uVar1 != 0) {
        uVar6 = 0;
        do {
          uVar5 = uVar5 - 1 & uVar1 - 1;
          iVar3 = this->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + uVar5 * 0x1c + 0x240)),(VendorTransferBuffer *)(param_6),
                             M<UInt32>(self + uVar5 * 0x1c + 0x250),false);
          if (iVar3 != 0) {
            return 1;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < M<UInt16>(self + 0x402));
      }
    }
    else {
      uVar1 = M<UInt16>(self + 0x5c6);
      uVar5 = (UInt32)M<UInt16>(self + 0x5c4);
      if (uVar1 != 0) {
        uVar6 = 0;
        do {
          uVar5 = uVar5 & uVar1 - 1;
          iVar3 = uVar5 * 0x1c;
          iVar3 = this->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + iVar3 + 0x404)),(VendorTransferBuffer *)(param_6),
                             M<UInt32>(self + iVar3 + 0x414),true);
          if (iVar3 != 0) {
            return 1;
          }
          uVar6 = uVar6 + 1;
          uVar5 = uVar5 + 1;
        } while (uVar6 < M<UInt16>(self + 0x5c6));
      }
      uVar1 = M<UInt16>(self + 0x402);
      uVar5 = (UInt32)M<UInt16>(self + 0x400);
      if (uVar1 != 0) {
        uVar6 = 0;
        do {
          uVar5 = uVar5 & uVar1 - 1;
          iVar3 = uVar5 * 0x1c;
          iVar3 = this->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + iVar3 + 0x240)),(VendorTransferBuffer *)(param_6),
                             M<UInt32>(self + iVar3 + 0x250),true);
          if (iVar3 != 0) {
            return 1;
          }
          uVar6 = uVar6 + 1;
          uVar5 = uVar5 + 1;
        } while (uVar6 < M<UInt16>(self + 0x402));
      }
    }
    for (pVVar7 = M<UInt8 *>(self + 0x5cc); pVVar7 != (UInt8 *)0x0;
        pVVar7 = M<UInt8 *>(pVVar7 + 0x3c)) {
      iVar3 = this->freeTransferToAllocGART((VendorTransferBuffer *)(pVVar7),(VendorTransferBuffer *)(param_6),M<UInt32>(pVVar7 + 0x5c),param_7);
      if (iVar3 != 0) {
        return 1;
      }
    }
    if (((((param_1 == (UInt8 *)0x0) ||
          (iVar3 = ((IOATIR5002DContext *)(param_1))->freeToAllocGART((VendorTransferBuffer *)(param_6), param_7), iVar3 == 0)) &&
         ((param_2 == (UInt8 *)0x0 ||
          (iVar3 = ((IOATIR500DVDContext *)(param_2))->freeToAllocGART((VendorTransferBuffer *)(param_6), param_7), iVar3 == 0)))) &&
        ((param_3 == (UInt8 *)0x0 ||
         (iVar3 = ((IOATIR500GLContext *)(param_3))->freeToAllocGART((VendorTransferBuffer *)(param_6), param_7), iVar3 == 0)))) &&
       ((param_4 == (UInt8 *)0x0 ||
        (iVar3 = ((IOATIR500Surface *)(param_4))->freeToAllocGART((VendorTransferBuffer *)(param_6), param_7), iVar3 == 0)))) {
      return 0;
    }
  }
  return 1;
}
