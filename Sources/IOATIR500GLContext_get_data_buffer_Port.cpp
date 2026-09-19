/*
 * IOATIR500GLContext_get_data_buffer_Port.cpp
 *
 * IOATIR500GLContext::get_data_buffer (real addr 0x9a30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");


/* real addr 0x9a30 */
IOReturn IOATIR500GLContext::get_data_buffer(unsigned int*param_1, UInt32*param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  int iVar1;
  UInt8 *pIVar2;
  unsigned int uVar3;
  int *piVar4;
  int iVar5;
  UInt8 *pVVar6;
  
  GH_IOLockLock(M<UInt32>(M<int>(self + 200) + 0x840));
  if (M<int>(self + 0xec) != 0) {
    uVar3 = M<int>(M<int>(self + 0x108) + 0xc) * 4;
    if (((unsigned int)(M<int>(M<int>(self + 0xec) + 0x50) - GH_page_size) < uVar3) &&
       (M<unsigned int>(self + 0xb4) < 0x80000)) {
      M<unsigned int>(self + 0xb4) = M<unsigned int>(self + 0xb4) << 1;
    }
    M<unsigned int>(M<int>(self + 200) + 0x70c) = uVar3 + M<int>(M<int>(self + 200) + 0x70c);
  }
  pIVar2 = M<UInt8 *>(self + 200);
  if (M<unsigned int>(pIVar2 + 0x5d8) < M<unsigned int>(self + 0xb4)) {
    M<unsigned int>(pIVar2 + 0x5d8) = M<unsigned int>(self + 0xb4);
    pIVar2 = M<UInt8 *>(self + 200);
  }
  pVVar6 = M<UInt8 *>(pIVar2 + 0x5cc);
  if (pVVar6 == (UInt8 *)0x0) {
    pVVar6 = (UInt8 *)
             ((IOATIR500Accelerator *)(pIVar2))->allocOneDataBuffer(M<UInt32>(pIVar2 + 0x5d8), true);
    if (pVVar6 == (UInt8 *)0x0) {
      GH_IOLockUnlock(M<UInt32>(M<int>(self + 200) + 0x840));
      *param_1 = 0;
      *param_2 = 0;
      return 0xe00002be;
    }
  }
  else {
    iVar1 = VCALL(M<int>(pIVar2), 0x554)(pIVar2,M<UInt32>(pVVar6 + 0x5c));
    if ((iVar1 == 0) &&
       (pVVar6 = (UInt8 *)
                 ((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->allocOneDataBuffer(M<UInt32>(M<UInt8 *>(self + 200) + 0x5d8),true),
       pVVar6 == (UInt8 *)0x0)) {
      piVar4 = M<int *>(self + 200);
      pVVar6 = (UInt8 *)piVar4[0x173];
      iVar5 = piVar4[0x1de];
      iVar1 = VCALL(*piVar4, 0x54c)(piVar4,M<UInt32>(pVVar6 + 0x5c));
      piVar4[0x1de] = iVar5 + iVar1;
    }
  }
  if (pVVar6 != M<UInt8 *>(M<int>(self + 200) + 0x5cc)) goto LAB_00009fd0;
  M<UInt32>(M<int>(self + 200) + 0x5cc) = M<UInt32>(pVVar6 + 0x3c);
  if (M<int>(pVVar6 + 0x3c) == 0) {
    M<UInt32>(M<int>(self + 200) + 0x5d0) = 0;
  }
  else {
    M<UInt32>(pVVar6 + 0x3c) = 0;
  }
  M<int>(M<int>(self + 200) + 0x5d4) = M<int>(M<int>(self + 200) + 0x5d4) + -1;
  pIVar2 = M<UInt8 *>(self + 200);
  if (M<int>(pVVar6 + 0x50) != M<int>(pIVar2 + 0x5d8)) {
    piVar4 = M<int *>(pVVar6 + 8);
    if (piVar4 != (int *)0x0) {
      if (M<int>(pVVar6 + 4) != 0) {
        VCALL(M<int>(pIVar2), 0x5ac)(pIVar2,pVVar6);
        piVar4 = M<int *>(pVVar6 + 8);
      }
      VCALL(*piVar4, 0x18)(piVar4);
      M<UInt32>(pVVar6 + 8) = 0;
    }
    if (M<int>(pVVar6 + 0x48) != 0) {
      VCALL(*M<int *>(self + 200), 0x524)(M<int *>(self + 200),pVVar6);
      iVar5 = M<int>(pVVar6 + 0x24);
      M<UInt32>(iVar5 + 0x28) = M<UInt32>(pVVar6 + 0x28);
      iVar1 = M<int>(pVVar6 + 0x28);
      M<UInt8 *>(pVVar6 + 0x28) = pVVar6;
      M<int>(iVar1 + 0x24) = iVar5;
      M<UInt8 *>(pVVar6 + 0x24) = pVVar6;
    }
    if (M<int *>(pVVar6 + 0x10) != (int *)0x0) {
      VCALL(*M<int *>(pVVar6 + 0x10), 0x18)(M<int *>(pVVar6 + 0x10));
      M<UInt32>(pVVar6 + 0x10) = 0;
    }
    M<UInt32>(pVVar6 + 0x50) = M<UInt32>(M<int>(self + 200) + 0x5d8);
    pIVar2 = M<UInt8 *>(self + 200);
  }
  if (pIVar2[0x80] == 0x0) {
    if (M<int>(pVVar6 + 8) == 0) {
      iVar1 = ((IOATIR500Accelerator *)(pIVar2))->allocDataBufferBacking((VendorTextureBuffer *)(pVVar6));
      if (iVar1 == 0) {
LAB_00009e94:
        ((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->freeOneDataBuffer((VendorTextureBuffer *)(pVVar6));
        GH_IOLockUnlock(M<UInt32>(M<int>(self + 200) + 0x840));
        *param_1 = 0;
        *param_2 = 0;
        return 0xe00002be;
      }
      if (M<int>(pVVar6 + 0x48) != 0) {
        if (M<int *>(pVVar6 + 0x10) != (int *)0x0) {
          iVar1 = VCALL(*M<int *>(pVVar6 + 0x10), 0xdc)(M<int *>(pVVar6 + 0x10));
          if (iVar1 == M<int>(self + 0x78)) {
            VCALL(*M<int *>(pVVar6 + 0x10), 0xf0)
                      (M<int *>(pVVar6 + 0x10),M<UInt32>(pVVar6 + 8),0x400,0);
          }
          else {
            VCALL(*M<int *>(pVVar6 + 0x10), 0x18)(M<int *>(pVVar6 + 0x10));
            M<UInt32>(pVVar6 + 0x10) = 0;
          }
        }
        VCALL(*M<int *>(self + 200), 0x524)(M<int *>(self + 200),pVVar6);
        iVar5 = M<int>(pVVar6 + 0x24);
        M<UInt32>(iVar5 + 0x28) = M<UInt32>(pVVar6 + 0x28);
        iVar1 = M<int>(pVVar6 + 0x28);
        M<UInt8 *>(pVVar6 + 0x28) = pVVar6;
        M<int>(iVar1 + 0x24) = iVar5;
        M<UInt8 *>(pVVar6 + 0x24) = pVVar6;
      }
      goto LAB_00009fd0;
    }
  }
  else if (M<int>(pVVar6 + 0x48) == 0) {
    iVar1 = VCALL(M<int>(pIVar2), 0x528)(pIVar2,pVVar6);
    if (iVar1 != 0) {
      if (M<int>(pVVar6 + 0x48) != 0) {
        iVar1 = M<int>(pVVar6 + 0x24);
        M<UInt32>(iVar1 + 0x28) = M<UInt32>(pVVar6 + 0x28);
        M<int>(M<int>(pVVar6 + 0x28) + 0x24) = iVar1;
        M<UInt32>(pVVar6 + 0x24) = M<UInt32>(M<int>(self + 200) + 0x600);
        M<int>(pVVar6 + 0x28) = M<int>(self + 200) + 0x5dc;
        M<UInt8 *>(M<int>(self + 200) + 0x600) = pVVar6;
        M<UInt8 *>(M<int>(pVVar6 + 0x24) + 0x28) = pVVar6;
      }
      piVar4 = M<int *>(self + 200);
      VCALL(*piVar4, 0x54c)(piVar4,piVar4[0x14] + -1);
      if (M<int>(pVVar6 + 8) != 0) {
        if (M<int *>(pVVar6 + 0x10) != (int *)0x0) {
          iVar1 = VCALL(*M<int *>(pVVar6 + 0x10), 0xdc)(M<int *>(pVVar6 + 0x10));
          if (iVar1 == M<int>(self + 0x78)) {
            VCALL(*M<int *>(pVVar6 + 0x10), 0xf0)
                      (M<int *>(pVVar6 + 0x10),M<UInt32>(M<int>(self + 200) + 0xdc),0x400,
                       M<UInt32>(pVVar6 + 0x48));
          }
          else {
            VCALL(*M<int *>(pVVar6 + 0x10), 0x18)(M<int *>(pVVar6 + 0x10));
            M<UInt32>(pVVar6 + 0x10) = 0;
          }
        }
        if (M<int>(pVVar6 + 4) != 0) {
          VCALL(*M<int *>(self + 200), 0x5ac)(M<int *>(self + 200),pVVar6);
        }
        VCALL(*M<int *>(pVVar6 + 8), 0x18)(M<int *>(pVVar6 + 8));
        M<UInt32>(pVVar6 + 8) = 0;
      }
      goto LAB_00009fd0;
    }
    if (M<int>(pVVar6 + 8) == 0) {
      iVar1 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->allocDataBufferBacking((VendorTextureBuffer *)(pVVar6));
      if (iVar1 == 0) goto LAB_00009e94;
      goto LAB_00009fd0;
    }
  }
  if ((M<int *>(pVVar6 + 0x10) != (int *)0x0) &&
     (iVar1 = VCALL(*M<int *>(pVVar6 + 0x10), 0xdc)(M<int *>(pVVar6 + 0x10)), iVar1 != M<int>(self + 0x78))) {
    VCALL(*M<int *>(pVVar6 + 0x10), 0x18)(M<int *>(pVVar6 + 0x10));
    M<UInt32>(pVVar6 + 0x10) = 0;
  }
LAB_00009fd0:
  pVVar6[0x54] = 0x1;
  if (M<int>(self + 0xec) == 0) {
    M<UInt8 *>(self + 0xe8) = pVVar6;
    M<UInt8 *>(self + 0xec) = pVVar6;
  }
  else {
    M<UInt8 *>(M<int>(self + 0xec) + 0x3c) = pVVar6;
    M<UInt8 *>(self + 0xec) = pVVar6;
  }
  M<int>(self + 0xf0) = M<int>(self + 0xf0) + 1;
  M<UInt32>(pVVar6 + 0x5c) = M<UInt32>(self + 0x7c);
  M<UInt8 *>(M<int>(self + 0x108) + 8) = pVVar6;
  piVar4 = M<int *>(pVVar6 + 0x10);
  if (piVar4 == (int *)0x0) {
    if (M<int>(pVVar6 + 0x48) == 0) {
      piVar4 = (int *)VCALL(*M<int *>(pVVar6 + 8), 0x14c)
                                (M<int *>(pVVar6 + 8),M<UInt32>(self + 0x78),0,0x4000401,0,
                                 M<UInt32>(pVVar6 + 0x50));
    }
    else {
      piVar4 = (int *)VCALL(*M<int *>(M<int>(self + 200) + 0xdc), 0x14c)
                                (M<int *>(M<int>(self + 200) + 0xdc),M<UInt32>(self + 0x78)
                                 ,0,0x4000401,M<int>(pVVar6 + 0x48),M<UInt32>(pVVar6 + 0x50)
                                );
    }
    if (piVar4 == (int *)0x0) {
      *param_1 = 0;
      *param_2 = 0;
      return 0xe00002be;
    }
    M<int *>(pVVar6 + 0x10) = piVar4;
  }
  uVar3 = VCALL(*piVar4, 0xd0)(piVar4);
  *param_1 = uVar3;
  *param_2 = M<UInt32>(pVVar6 + 0x50);
  GH_IOLockUnlock(M<UInt32>(M<int>(self + 200) + 0x840));
  return 0;
}
