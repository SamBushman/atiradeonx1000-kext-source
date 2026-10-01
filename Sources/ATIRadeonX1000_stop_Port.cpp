/*
 * ATIRadeonX1000_stop_Port.cpp
 *
 * ATIRadeonX1000::stop (real addr 0x26250, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOFreeAligned(...) asm("_IOFreeAligned");

UInt32 HZMEM_Destroy(_HZDATA *hz);

/* real addr 0x26250 */
void ATIRadeonX1000::stop(IOService *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  bool bVar1;
  int iVar2;
  unsigned int uVar3;
  int iVar4;
  UInt8 *pGVar5;
  UInt8 *pAVar6;
  int iVar7;
  
  if (M<int>(self + 0x9a8) != 0) {
    VCALL(*M<int *>(self + 0xb4), 0xe8)(M<int *>(self + 0xb4));
    VCALL(*M<int *>(self + 0x9a8), 0x18)(M<int *>(self + 0x9a8));
    M<UInt32>(self + 0x9a8) = 0;
  }
  if (M<int>(self + 0x9b8) != 0) {
    VCALL(*M<int *>(self + 0xb4), 0xe8)(M<int *>(self + 0xb4));
    VCALL(*M<int *>(self + 0x9b8), 0x18)(M<int *>(self + 0x9b8));
    M<UInt32>(self + 0x9b8) = 0;
  }
  iVar4 = 0;
  pGVar5 = (UInt8 *)(self + 0x9bc);
  VCALL(*M<int *>(self + 0x74), 0x17c)(M<int *>(self + 0x74),"ATIFEDSInfo");
  pAVar6 = self;
  do {
    if ((M<int>(pAVar6 + 0x9c0) != 0) && (M<int>(pAVar6 + 0x9bc) != 0)) {
      ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->dealloc((GLKMemoryElement *)(pGVar5));
    }
    bVar1 = iVar4 != 1;
    pGVar5 = pGVar5 + 0x78;
    pAVar6 = pAVar6 + 0x78;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  if (M<int>(self + 0xae8) != 0) {
    ((IOATIR500Accelerator *)((UInt8 *)self))->freeCommandBuffer((VendorCommandBuffer *)((UInt8 *)(self + 0xae0)));
  }
  if ((M<int>(self + 0x8e0) != 0) && (M<int>(self + 0x8dc) != 0)) {
    ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->dealloc((GLKMemoryElement *)((UInt8 *)(self + 0x8dc)));
  }
  if ((M<int>(self + 0x8f0) != 0) && (M<int>(self + 0x8ec) != 0)) {
    ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->dealloc((GLKMemoryElement *)((UInt8 *)(self + 0x8ec)));
  }
  iVar4 = 0;
  pGVar5 = (UInt8 *)(self + 300);
  pAVar6 = self;
  do {
    if ((M<int>(pAVar6 + 0x130) != 0) && (M<int>(pAVar6 + 300) != 0)) {
      ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->dealloc((GLKMemoryElement *)(pGVar5));
    }
    bVar1 = iVar4 != 1;
    pGVar5 = pGVar5 + 0x78;
    pAVar6 = pAVar6 + 0x78;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  VCALL(M<int>(self), 0x54c)(self,M<int>(self + 0x50) + -1);
  if (M<int>(self + 0x8bc) != 0) {
    this->stop_xdct_engine();
  }
  this->stop_promo4_engine();
  if (M<int>(self + 0xb10) != 0) {
    uVar3 = M<unsigned int>(self + 0xb08);
    iVar4 = M<int>(self + 0x860);
    M<unsigned int>(iVar4 + 0x6110) =
         uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
    enforceInOrderExecutionIO();
    uVar3 = M<unsigned int>(self + 0xb0c);
    M<UInt32>(self + 0xb08) = 0;
    M<unsigned int>(iVar4 + 0x6120) =
         uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
    enforceInOrderExecutionIO();
    M<UInt32>(self + 0xb10) = 0;
    M<UInt32>(self + 0xb0c) = 0;
  }
  if (M<int>(self + 0xb28) != 0) {
    uVar3 = M<unsigned int>(self + 0xb20);
    iVar4 = M<int>(self + 0x860);
    M<unsigned int>(iVar4 + 0x6910) =
         uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
    enforceInOrderExecutionIO();
    uVar3 = M<unsigned int>(self + 0xb24);
    M<UInt32>(self + 0xb20) = 0;
    M<unsigned int>(iVar4 + 0x6920) =
         uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
    enforceInOrderExecutionIO();
    M<UInt32>(self + 0xb28) = 0;
    M<UInt32>(self + 0xb24) = 0;
  }
  HZMEM_Destroy((_HZDATA *)((UInt8 *)(self + 0x870)));
  if (M<int>(self + 0x8d0) != 0) {
    M<UInt32>(self + 0x868) = 0x15e4;
    M<UInt32>(self + 0x86c) = 0x15e0;
    M<int>(self + 0x864) = M<int>(self + 0x860);
    M<UInt32>(M<int>(self + 0x860) + 0x770) = 0;
    enforceInOrderExecutionIO();
    VCALL(M<int>(self), 0x5a4)
              (self,M<UInt32>(self + 0x8d8),M<UInt32>(self + 0x8d4));
    VCALL(*M<int *>(self + 0x8d8), 0x18)(M<int *>(self + 0x8d8));
    GH_IOFreeAligned(M<UInt32>(self + 0x8d0),GH_page_size);
    M<UInt32>(self + 0x8d0) = 0;
  }
  if (M<int>(self + 0x900) != 0) {
    if (M<int>(self + 0xba0) != 0) {
      uVar3 = 0;
      do {
        VCALL(M<int>(self), 0x598)(self,uVar3 + M<int>(self + 0x904) + 0x1000000);
        uVar3 = uVar3 + GH_page_size;
      } while (uVar3 < M<unsigned int>(self + 0xba0));
    }
    VCALL(M<int>(self), 0x5a4)
              (self,M<UInt32>(self + 0x908),M<UInt32>(self + 0x904));
    GH_IOFreeAligned(M<UInt32>(self + 0x900),M<UInt32>(self + 0xba0));
    M<UInt32>(self + 0x900) = 0;
  }
  if (M<int>(self + 0x91c) != 0) {
    iVar4 = 0;
    do {
      VCALL(M<int>(self), 0x598)(self,iVar4 + M<int>(self + 0x920) + 0x1000000);
      iVar4 = iVar4 + GH_page_size;
    } while (iVar4 < 0x2000);
    VCALL(M<int>(self), 0x5a4)
              (self,M<UInt32>(self + 0x924),M<UInt32>(self + 0x920));
    GH_IOFreeAligned(M<UInt32>(self + 0x91c),0x2000);
    M<UInt32>(self + 0x91c) = 0;
  }
  if (M<int>(self + 0x938) != 0) {
    if (M<int>(self + 0x8c8) == 0) {
      if (((UInt8)self[0x8cc] != 0) && (iVar4 = (UInt8)self[0x8cc] - 1, 0 < iVar4)) {
        iVar7 = 0;
        do {
          iVar2 = iVar4 - iVar7;
          iVar7 = iVar7 + 1;
          VCALL(M<int>(self), 0x5a4)
                    (self,M<UInt32>(self + 0x22c),iVar2 << (GH_page_size & 0x3f));
        } while (iVar4 != iVar7);
      }
    }
    else {
      iVar4 = (unsigned int)(UInt8)self[0x8cc] * 2;
      while (iVar7 = iVar4 + -2, 0 < iVar7) {
        VCALL(M<int>(self), 0x598)(self,iVar4 + -1 << (GH_page_size & 0x3f));
        VCALL(M<int>(self), 0x5a4)
                  (self,M<UInt32>(self + 0x22c),iVar7 << (GH_page_size & 0x3f));
        iVar4 = iVar7;
      }
      VCALL(M<int>(self), 0x598)(self,1 << (GH_page_size & 0x3f));
    }
    VCALL(M<int>(self), 0x5a4)
              (self,M<UInt32>(self + 0x22c),M<UInt32>(self + 0x228));
  }
  if (M<int *>(self + 0x9ac) != (int *)0x0) {
    VCALL(*M<int *>(self + 0x9ac), 0x18)(M<int *>(self + 0x9ac));
    M<UInt32>(self + 0x9ac) = 0;
  }
  this->shutdownPCIeGART();
  M<UInt32>(self + 3000) = 0;
  if (M<int>(self + 0xc4c) != 0) {
    GH_IOFreeAligned(M<int>(self + 0xc4c),M<UInt32>(self + 0x830));
    M<UInt32>(self + 0xc4c) = 0;
  }
  if (M<int *>(self + 0x934) != (int *)0x0) {
    VCALL(*M<int *>(self + 0x934), 0x18)(M<int *>(self + 0x934));
    M<UInt32>(self + 0x934) = 0;
    M<UInt32>(self + 0x860) = 0;
  }
  if (M<int>(self + 0x8b8) != 0) {
    VCALL(M<int>(self), 0x5ac)(self,self + 0x8a8);
    M<UInt32>(self + 0x8b0) = 0;
    GH_IOFreeAligned(M<UInt32>(self + 0x8b8),0x2000);
    M<UInt32>(self + 0x8b8) = 0;
  }
  if (M<int>(self + 0xac) != 0) {
    M<UInt32>(self + 0xac) = 0;
  }
  if (M<int *>(self + 0x93c) != (int *)0x0) {
    VCALL(*M<int *>(self + 0x93c), 0x18)(M<int *>(self + 0x93c));
    M<UInt32>(self + 0x93c) = 0;
  }
  ((IOATIR500Accelerator *)(self))->stop((IOService *)(param_1));
  return;
}
