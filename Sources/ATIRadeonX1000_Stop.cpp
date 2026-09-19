/*
 * ATIRadeonX1000_Stop.cpp
 *
 * RESOLVED (ledger pass): ATIRadeonX1000::stop (real addr 0x26250, 1620 bytes): tears down the timers, memory pools, GART pages, HZMEM and
 * PCIe GART, then calls IOATIR500Accelerator::stop.
 * Mechanically ported from the Ghidra decompile of the shipped kext (Tools/port_fn.py); the resolved data references
 * (metaClass / page_shift / page_size / plane symbols) come from the kext relocation table.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/GhidraExterns.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

extern "C" UInt32 GH_IOFreeAligned(...) asm("_IOFreeAligned");
extern "C" UInt32 GH_IOMallocAligned(...) asm("_IOMallocAligned");
extern "C" UInt32 GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(...) asm("__ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass");
extern "C" UInt32 GH_ZN18IOMemoryDescriptor11withAddressEPvm11IODirection(...) asm("__ZN18IOMemoryDescriptor11withAddressEPvm11IODirection");
extern "C" UInt32 GH_ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_(...) asm("__ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_E");
extern "C" UInt32 GH_ZN8OSObjectnwEm(...) asm("__ZN8OSObjectnwEm");
extern "C" UInt32 GH_ZN8OSSymbol17withCStringNoCopyEPKc(...) asm("__ZN8OSSymbol17withCStringNoCopyEPKc");
extern "C" UInt32 GH_ZN9IOServiceC1Ev(...) asm("__ZN9IOServiceC1Ev");
extern "C" UInt32 GH_memcpy(...) asm("_memcpy");
extern "C" UInt32 GH_memset(...) asm("_memset");

struct _HZDATA;
UInt32 HZMEM_Init(_HZDATA *hz, UInt32 param_2, UInt32 param_3, UInt32 param_4);
UInt32 HZMEM_Destroy(_HZDATA *hz);

/* real addr 0x26250 */
void ATIRadeonX1000::stop(IOService *param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  SInt32 iVar2;
  UInt32 uVar3;
  SInt32 iVar4;
  UInt8 *pGVar5;
  UInt8 *pAVar6;
  SInt32 iVar7;
  
  if (M<SInt32>(self + 0x9a8) != 0) {
    VCALL(*M<SInt32 *>(self + 0xb4), 0xe8)(M<SInt32 *>(self + 0xb4));
    VCALL(*M<SInt32 *>(self + 0x9a8), 0x18)(M<SInt32 *>(self + 0x9a8));
    M<UInt32>(self + 0x9a8) = 0;
  }
  if (M<SInt32>(self + 0x9b8) != 0) {
    VCALL(*M<SInt32 *>(self + 0xb4), 0xe8)(M<SInt32 *>(self + 0xb4));
    VCALL(*M<SInt32 *>(self + 0x9b8), 0x18)(M<SInt32 *>(self + 0x9b8));
    M<UInt32>(self + 0x9b8) = 0;
  }
  iVar4 = 0;
  pGVar5 = (self + 0x9bc);
  VCALL(*M<SInt32 *>(self + 0x74), 0x17c)(M<SInt32 *>(self + 0x74),"ATIFEDSInfo");
  pAVar6 = self;
  do {
    if ((M<SInt32>(pAVar6 + 0x9c0) != 0) && (M<SInt32>(pAVar6 + 0x9bc) != 0)) {
      ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->dealloc((GLKMemoryElement *)pGVar5);
    }
    bVar1 = iVar4 != 1;
    pGVar5 = pGVar5 + 0x78;
    pAVar6 = pAVar6 + 0x78;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  if (M<SInt32>(self + 0xae8) != 0) {
    IOATIR500Accelerator::freeCommandBuffer((VendorCommandBuffer *)(self + 0xae0));
  }
  if ((M<SInt32>(self + 0x8e0) != 0) && (M<SInt32>(self + 0x8dc) != 0)) {
    ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->dealloc((GLKMemoryElement *)(self + 0x8dc));
  }
  if ((M<SInt32>(self + 0x8f0) != 0) && (M<SInt32>(self + 0x8ec) != 0)) {
    ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->dealloc((GLKMemoryElement *)(self + 0x8ec));
  }
  iVar4 = 0;
  pGVar5 = (self + 300);
  pAVar6 = self;
  do {
    if ((M<SInt32>(pAVar6 + 0x130) != 0) && (M<SInt32>(pAVar6 + 300) != 0)) {
      ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->dealloc((GLKMemoryElement *)pGVar5);
    }
    bVar1 = iVar4 != 1;
    pGVar5 = pGVar5 + 0x78;
    pAVar6 = pAVar6 + 0x78;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  VCALL(M<SInt32>(self), 0x54c)(self,M<SInt32>(self + 0x50) + -1);
  if (M<SInt32>(self + 0x8bc) != 0) {
    this->stop_xdct_engine();
  }
  this->stop_promo4_engine();
  if (M<SInt32>(self + 0xb10) != 0) {
    uVar3 = M<UInt32>(self + 0xb08);
    iVar4 = M<SInt32>(self + 0x860);
    M<UInt32>(iVar4 + 0x6110) =
         uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
    enforceInOrderExecutionIO();
    uVar3 = M<UInt32>(self + 0xb0c);
    M<UInt32>(self + 0xb08) = 0;
    M<UInt32>(iVar4 + 0x6120) =
         uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
    enforceInOrderExecutionIO();
    M<UInt32>(self + 0xb10) = 0;
    M<UInt32>(self + 0xb0c) = 0;
  }
  if (M<SInt32>(self + 0xb28) != 0) {
    uVar3 = M<UInt32>(self + 0xb20);
    iVar4 = M<SInt32>(self + 0x860);
    M<UInt32>(iVar4 + 0x6910) =
         uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
    enforceInOrderExecutionIO();
    uVar3 = M<UInt32>(self + 0xb24);
    M<UInt32>(self + 0xb20) = 0;
    M<UInt32>(iVar4 + 0x6920) =
         uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
    enforceInOrderExecutionIO();
    M<UInt32>(self + 0xb28) = 0;
    M<UInt32>(self + 0xb24) = 0;
  }
  HZMEM_Destroy((_HZDATA *)(self + 0x870));
  if (M<SInt32>(self + 0x8d0) != 0) {
    M<UInt32>(self + 0x868) = 0x15e4;
    M<UInt32>(self + 0x86c) = 0x15e0;
    M<SInt32>(self + 0x864) = M<SInt32>(self + 0x860);
    M<UInt32>(M<SInt32>(self + 0x860) + 0x770) = 0;
    enforceInOrderExecutionIO();
    VCALL(M<SInt32>(self), 0x5a4)
              (self,M<UInt32>(self + 0x8d8),M<UInt32>(self + 0x8d4));
    VCALL(*M<SInt32 *>(self + 0x8d8), 0x18)(M<SInt32 *>(self + 0x8d8));
    GH_IOFreeAligned(M<UInt32>(self + 0x8d0),GH_page_size);
    M<UInt32>(self + 0x8d0) = 0;
  }
  if (M<SInt32>(self + 0x900) != 0) {
    if (M<SInt32>(self + 0xba0) != 0) {
      uVar3 = 0;
      do {
        VCALL(M<SInt32>(self), 0x598)(self,uVar3 + M<SInt32>(self + 0x904) + 0x1000000);
        uVar3 = uVar3 + GH_page_size;
      } while (uVar3 < M<UInt32>(self + 0xba0));
    }
    VCALL(M<SInt32>(self), 0x5a4)
              (self,M<UInt32>(self + 0x908),M<UInt32>(self + 0x904));
    GH_IOFreeAligned(M<UInt32>(self + 0x900),M<UInt32>(self + 0xba0));
    M<UInt32>(self + 0x900) = 0;
  }
  if (M<SInt32>(self + 0x91c) != 0) {
    iVar4 = 0;
    do {
      VCALL(M<SInt32>(self), 0x598)(self,iVar4 + M<SInt32>(self + 0x920) + 0x1000000);
      iVar4 = iVar4 + GH_page_size;
    } while (iVar4 < 0x2000);
    VCALL(M<SInt32>(self), 0x5a4)
              (self,M<UInt32>(self + 0x924),M<UInt32>(self + 0x920));
    GH_IOFreeAligned(M<UInt32>(self + 0x91c),0x2000);
    M<UInt32>(self + 0x91c) = 0;
  }
  if (M<SInt32>(self + 0x938) != 0) {
    if (M<SInt32>(self + 0x8c8) == 0) {
      if (((UInt8)self[0x8cc] != 0) && (iVar4 = (UInt8)self[0x8cc] - 1, 0 < iVar4)) {
        iVar7 = 0;
        do {
          iVar2 = iVar4 - iVar7;
          iVar7 = iVar7 + 1;
          VCALL(M<SInt32>(self), 0x5a4)
                    (self,M<UInt32>(self + 0x22c),iVar2 << (GH_page_shift & 0x3f));
        } while (iVar4 != iVar7);
      }
    }
    else {
      iVar4 = (UInt32)(UInt8)self[0x8cc] * 2;
      while (iVar7 = iVar4 + -2, 0 < iVar7) {
        VCALL(M<SInt32>(self), 0x598)(self,iVar4 + -1 << (GH_page_shift & 0x3f));
        VCALL(M<SInt32>(self), 0x5a4)
                  (self,M<UInt32>(self + 0x22c),iVar7 << (GH_page_shift & 0x3f));
        iVar4 = iVar7;
      }
      VCALL(M<SInt32>(self), 0x598)(self,1 << (GH_page_shift & 0x3f));
    }
    VCALL(M<SInt32>(self), 0x5a4)
              (self,M<UInt32>(self + 0x22c),M<UInt32>(self + 0x228));
  }
  if (M<SInt32 *>(self + 0x9ac) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(self + 0x9ac), 0x18)(M<SInt32 *>(self + 0x9ac));
    M<UInt32>(self + 0x9ac) = 0;
  }
  this->shutdownPCIeGART();
  M<UInt32>(self + 3000) = 0;
  if (M<SInt32>(self + 0xc4c) != 0) {
    GH_IOFreeAligned(M<SInt32>(self + 0xc4c),M<UInt32>(self + 0x830));
    M<UInt32>(self + 0xc4c) = 0;
  }
  if (M<SInt32 *>(self + 0x934) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(self + 0x934), 0x18)(M<SInt32 *>(self + 0x934));
    M<UInt32>(self + 0x934) = 0;
    M<UInt32>(self + 0x860) = 0;
  }
  if (M<SInt32>(self + 0x8b8) != 0) {
    VCALL(M<SInt32>(self), 0x5ac)(self,self + 0x8a8);
    M<UInt32>(self + 0x8b0) = 0;
    GH_IOFreeAligned(M<UInt32>(self + 0x8b8),0x2000);
    M<UInt32>(self + 0x8b8) = 0;
  }
  if (M<SInt32>(self + 0xac) != 0) {
    M<UInt32>(self + 0xac) = 0;
  }
  if (M<SInt32 *>(self + 0x93c) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(self + 0x93c), 0x18)(M<SInt32 *>(self + 0x93c));
    M<UInt32>(self + 0x93c) = 0;
  }
  IOATIR500Accelerator::stop(param_1);
  return;
}
