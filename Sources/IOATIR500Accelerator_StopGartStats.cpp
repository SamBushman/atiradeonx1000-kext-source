/*
 * IOATIR500Accelerator_StopGartStats.cpp
 *
 * RESOLVED (ledger pass): IOATIR500Accelerator::stop (0x65c0, vtable +0x34c), addToMinMaxGART (0x5fe0, +0x590) and
 * writePerformanceStats (0xac0, +0x568), transcribed mechanically from the shipped kext's decompile (Tools/port_fn.py,
 * Headers/GhidraCompat.h; conventions as in ATIR500Surface_BuildSwap.cpp). The `_ASICSupportsAGP` labels in
 * addToMinMaxGART are page_shift / page_size loads (relocation table). `stop` ends by chaining to IOAccelerator::stop.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/GhidraExterns.h"

#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

static inline void GH_FreeTexvert(void *accelerator, void *texture) { IOATIR500Shared::free_texvert(reinterpret_cast<IOATIR500Accelerator *>(accelerator), reinterpret_cast<IOTextureBuffer *>(texture)); }

extern "C" UInt32 GH_IOLockFree(...) asm("_IOLockFree");
extern "C" UInt32 GH_ZN8OSNumber10withNumberEyj(...) asm("__ZN8OSNumber10withNumberEyj");

/* real addr 0x65c0 */
void IOATIR500Accelerator::stop(IOService *param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  
  SInt32 iVar3;
  SInt32 *piVar4;
  SInt32 iVar5;
  UInt8 *pIVar6;
  UInt32 uVar7;
  UInt32 uVar8;
  UInt8 *pIVar9;
  
  VCALL(M<SInt32>(self), 0x54c)(self,M<SInt32>(self + 0x50) + -1);
  if (M<SInt32>(self + 0xbc) != 0) {
    VCALL(*M<SInt32 *>(self + 0xb4), 0xe8)(M<SInt32 *>(self + 0xb4));
    VCALL(*M<SInt32 *>(self + 0xbc), 0x18)(M<SInt32 *>(self + 0xbc));
    M<UInt32>(self + 0xbc) = 0;
  }
  if (M<SInt32>(self + 0xb8) != 0) {
    VCALL(*M<SInt32 *>(self + 0xb4), 0xe8)(M<SInt32 *>(self + 0xb4));
    VCALL(*M<SInt32 *>(self + 0xb8), 0x18)(M<SInt32 *>(self + 0xb8));
    M<UInt32>(self + 0xb8) = 0;
  }
  pIVar6 = M<UInt8 *>(self + 0x664);
  while (pIVar6 != (UInt8 *)(self + 0x63c)) {
    iVar5 = M<SInt32>(pIVar6 + 0x24);
    M<UInt32>(iVar5 + 0x28) = M<UInt32>(pIVar6 + 0x28);
    iVar3 = M<SInt32>(pIVar6 + 0x28);
    M<UInt8 *>(pIVar6 + 0x28) = pIVar6;
    M<SInt32>(iVar3 + 0x24) = iVar5;
    M<UInt8 *>(pIVar6 + 0x24) = pIVar6;
    GH_FreeTexvert(self,pIVar6);
    pIVar6 = M<UInt8 *>(self + 0x664);
  }
  self[0x89] = 0x0;
  if (M<SInt32>(self + 0xc4) != 0) {
    VCALL(*M<SInt32 *>(self + 0xb4), 0xe8)(M<SInt32 *>(self + 0xb4));
    VCALL(*M<SInt32 *>(self + 0xc4), 0x18)(M<SInt32 *>(self + 0xc4));
    M<UInt32>(self + 0xc4) = 0;
  }
  if (M<SInt32>(self + 0xc0) != 0) {
    VCALL(*M<SInt32 *>(self + 0xb4), 0xe8)(M<SInt32 *>(self + 0xb4));
    VCALL(*M<SInt32 *>(self + 0xc0), 0x18)(M<SInt32 *>(self + 0xc0));
    M<UInt32>(self + 0xc0) = 0;
  }
  if (M<SInt32 *>(self + 0xb4) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(self + 0xb4), 0x18)(M<SInt32 *>(self + 0xb4));
    M<UInt32>(self + 0xb4) = 0;
  }
  uVar8 = 0;
  do {
    ((IOATIR500Accelerator *)(self))->freeAllCommandBuffers(uVar8);
    bVar1 = uVar8 != 1;
    uVar8 = uVar8 + 1;
  } while (bVar1);
  ((IOATIR500Accelerator *)(self))->freeAllDataBuffers();
  if ((M<UInt32>(self + 0x98) & 1) != 0) {
    piVar4 = M<SInt32 *>(self + 0x22c);
    if (piVar4 == (SInt32 *)0x0) goto LAB_000067e8;
    VCALL(*piVar4, 0x148)(piVar4,3);
  }
  if (M<SInt32>(self + 0x22c) != 0) {
    ((IOATIR500Accelerator *)(self))->freeCommandBuffer((VendorCommandBuffer *)(self + 0x224));
  }
LAB_000067e8:
  if (M<SInt32>(self + 0xcc) != 0) {
    uVar7 = 0;
    pIVar9 = self;
    do {
      if (M<SInt32 *>(pIVar9 + 0xd8) != (SInt32 *)0x0) {
        VCALL(*M<SInt32 *>(pIVar9 + 0xd8), 0xd0)(M<SInt32 *>(pIVar9 + 0xd8));
      }
      if (M<SInt32 *>(pIVar9 + 0xe0) != (SInt32 *)0x0) {
        VCALL(*M<SInt32 *>(pIVar9 + 0xe0), 0x18)(M<SInt32 *>(pIVar9 + 0xe0));
      }
      if (M<SInt32 *>(pIVar9 + 0xdc) != (SInt32 *)0x0) {
        VCALL(*M<SInt32 *>(pIVar9 + 0xdc), 0x18)(M<SInt32 *>(pIVar9 + 0xdc));
      }
      uVar7 = uVar7 + 1;
      pIVar9 = pIVar9 + 0x20;
    } while (uVar7 < M<UInt32>(self + 0xcc));
  }
  if (M<SInt32 *>(self + 0x7c) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(self + 0x7c), 0x18)(M<SInt32 *>(self + 0x7c));
    M<UInt32>(self + 0x7c) = 0;
  }
  VCALL(M<SInt32>(self), 0x584)(self,param_1);
  if (M<SInt32>(self + 0x840) != 0) {
    GH_IOLockFree();
    M<UInt32>(self + 0x840) = 0;
  }
  
  M<UInt32>(self + 0x74) = 0;
  IOAccelerator::stop(param_1);
  return;
}

/* real addr 0x5fe0 */
IOReturn IOATIR500Accelerator::addToMinMaxGART(IOMemoryDescriptor *real_param_1, UInt32 *param_2, UInt32 param_3, UInt32 param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt32 uVar1;
  SInt32 iVar2;
  UInt32 uVar3;
  UInt32 uVar4;
  UInt32 uVar5;
  SInt32 iVar6;
  UInt32 uVar7;
  UInt32 uVar8;
  UInt32 local_48 [9];
  
  *param_2 = 0;
  uVar3 = VCALL(M<SInt32>(param_1), 0x128)(param_1);
  uVar3 = uVar3 >> (GH_page_shift & 0x3f);
  uVar7 = param_3 >> (GH_page_shift & 0x3f);
  uVar1 = (M<UInt32>(self + 0x830) >> 2) << (GH_page_shift & 0x3f);
  if (uVar1 <= param_4) {
    param_4 = uVar1 - GH_page_size;
  }
  uVar1 = param_4 >> (GH_page_shift & 0x3f);
  iVar6 = uVar7 << 2;
  uVar8 = 0;
  iVar2 = (uVar1 - uVar7) + 1;
  if ((uVar1 < uVar7) || (uVar1 == 0)) {
    iVar2 = 1;
  }
  do {
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) {
      if (uVar3 != uVar8) {
        return 0;
      }
      goto LAB_000060d8;
    }
    if ((M<SInt32>(iVar6 + M<SInt32>(self + 0x83c)) == M<SInt32>(self + 0x844)) &&
       ((uVar8 != 0 || ((uVar7 & 1) == 0)))) {
      uVar8 = uVar8 + 1;
    }
    else {
      uVar8 = 0;
    }
    uVar7 = uVar7 + 1;
    iVar6 = iVar6 + 4;
  } while (uVar8 != uVar3);
  uVar7 = uVar7 - uVar3;
LAB_000060d8:
  iVar6 = VCALL(M<SInt32>(param_1), 0x144)(param_1,3);
  if (iVar6 == 0) {
    if (((M<UInt32>(self + 0x98) & 2) == 0) ||
       (iVar6 = VCALL(M<SInt32>(self), 0x588)
                          (self,param_1,uVar7 << (GH_page_shift & 0x3f),0), iVar6 == 0)) {
      iVar6 = 0;
      *param_2 = uVar7 << (GH_page_shift & 0x3f);
      while (uVar5 = VCALL(M<SInt32>(param_1), 0x13c)(param_1,iVar6,local_48),
            uVar1 = GH_page_size, uVar5 != 0) {
        iVar6 = iVar6 + local_48[0];
        if (GH_page_size <= local_48[0]) {
          iVar2 = M<SInt32>(self + 0x83c);
          do {
            M<UInt32>(iVar2 + uVar7 * 4) =
                 uVar5 << 0x18 | (uVar5 & 0xff00) << 8 | uVar5 >> 8 & 0xff00 | uVar5 >> 0x18;
            local_48[0] = local_48[0] - uVar1;
            uVar5 = uVar5 + uVar1;
            uVar7 = uVar7 + 1;
          } while (uVar1 <= local_48[0]);
        }
      }
      VCALL(M<SInt32>(self), 0x59c)(self,uVar7 - uVar8,uVar3);
      uVar4 = 1;
      M<UInt32>(self + 0x714) = (uVar3 << (GH_page_shift & 0x3f)) + M<SInt32>(self + 0x714);
      M<UInt32>(self + 0xa0) = (uVar3 << (GH_page_shift & 0x3f)) + M<SInt32>(self + 0xa0);
    }
    else {
      VCALL(M<SInt32>(param_1), 0x148)(param_1,3);
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}

/* real addr 0xac0 */
void IOATIR500Accelerator::writePerformanceStats(OSDictionary *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  SInt32 *piVar1;
  
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x6fc),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"commandBytesPerSample",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x6fc) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x700),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"command2DBytesPerSample",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x700) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x704),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"commandGLBytesPerSample",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x704) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x708),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"commandDVDBytesPerSample",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x708) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x70c),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"dataGLBytesPerSample",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x70c) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x710),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"swapBytesPerSample",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x710) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x714),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"gartMapInBytesPerSample",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x714) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x718),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"gartMapOutBytesPerSample",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x718) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x71c),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"texturePageInBytesPerSample",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x71c) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x720),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"texturePageOutBytesPerSample",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x720) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x724),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"surfacePageInBytesPerSample",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x724) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x728),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"surfacePageOutBytesPerSample",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x728) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x72c),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"textureCount",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x730),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"surfaceCount",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x734),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"context2DCount",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x738),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"contextGLCount",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x73c),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"contextDVDCount",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x740),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"contextGLSwitchCount",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x740) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x744),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"context2DSwitchCount",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x744) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x748),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"contextDVDSwitchCount",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x748) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x74c),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"bufferSwapCount",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x74c) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x750),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"dataBufferCount",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x750) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x754),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"texturePageInWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x754) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x758),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"texturePageOutWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x758) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x75c),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"textureWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x75c) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x760),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"hardwareWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x760) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x764),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"hardwareSubmitWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x764) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x768),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"clientGLWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x768) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x76c),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"freeCommandBuffer2DWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x76c) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x770),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"freeCommandBufferGLWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x770) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x774),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"freeCommandBufferDVDWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x774) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x778),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"freeDataBufferGLWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x778) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x77c),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"freeContextBuffer2DWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x77c) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x780),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"freeContextBufferGLWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x780) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x784),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"freeContextBufferDVDWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x784) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x788),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"freeSurfaceSwapBufferWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x788) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x78c),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"freeSurfaceBackingWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x78c) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x790),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"removeFromGARTWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x790) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x794),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"swapComplete2DWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x794) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x798),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"swapCompleteGLWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x798) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x79c),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"swapCompleteDVDWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x79c) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x7a0),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"finishAll2DWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x7a0) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x7a4),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"finish2DWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x7a4) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x7a8),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"finishGLWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x7a8) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x7ac),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"finishDVDWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x7ac) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x7b0),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"surfaceCopyInWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x7b0) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x7b4),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"surfaceCopyOutWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x7b4) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x7b8),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"surfaceReadLockIdleWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x7b8) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x7bc),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"surfaceWriteLockIdleWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x7bc) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x7c0),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"surfaceSetShapeIdleWaitTime",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  M<UInt32>(self + 0x7c0) = 0;
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x21c),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"volatileSurfaceCount",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0xa0),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"gartUsedBytes",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<SInt32>(self + 0x830) * 0x400 - M<SInt32>(self + 0xa0),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"gartFreeBytes",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<SInt32>(self + 0x830) << 10,0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"gartSizeBytes",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0xa4),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"gartCacheBytes",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x50),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"submitStamp",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  piVar1 = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x54),0x20);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(param_1), 300)(param_1,"lastReadStamp",piVar1);
    VCALL(*piVar1, 0x18)(piVar1);
  }
  return;
}
