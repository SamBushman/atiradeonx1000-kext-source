/*
 * ATIRadeonX1000_DisplayMode.cpp
 *
 * RESOLVED (ledger pass): display_mode_did_change / display_mode_will_change.
 * Mechanically ported from the Ghidra decompile of the shipped kext (Tools/port_fn.py); real addresses in the markers.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/GhidraExterns.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

extern "C" UInt32 gl_assert_wait_timeout_event;
extern "C" UInt32 global_dummy_read_back_a_register;
extern "C" UInt32 GH_IODelay(...) asm("_IODelay");
extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");
extern "C" UInt32 GH_IOLog(...) asm("_IOLog");
extern "C" UInt32 GH_IOSleep(...) asm("_IOSleep");
extern "C" UInt32 GH_OSDecrementAtomic(...) asm("_OSDecrementAtomic");
extern "C" UInt32 GH_OSIncrementAtomic(...) asm("_OSIncrementAtomic");
extern "C" UInt32 GH_absolutetime_to_nanoseconds(...) asm("_absolutetime_to_nanoseconds");
extern "C" UInt32 GH_assert_wait_timeout(...) asm("_assert_wait_timeout");
extern "C" UInt32 GH_clock_get_uptime(...) asm("_clock_get_uptime");
extern "C" UInt32 GH_thread_block(...) asm("_thread_block");


/* real addr 0x24e40 */
bool ATIRadeonX1000::display_mode_did_change() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  SInt32 iVar2;
  SInt32 iVar3;
  SInt32 *piVar4;
  UInt32 uVar5;
  UInt32 uVar6;
  
  GH_IOLockLock(M<UInt32>(self + 0x840));
  iVar2 = startupPCIeGART();
  if (iVar2 != -1) {
    pageOnPCIeGART();
    iVar2 = initialize_hardware();
    iVar3 = SWDSIsRequired();
    if (iVar3 != 0) {
      iVar3 = SWDSInit();
      if ((iVar3 == 0) || (iVar2 == 0)) {
        iVar2 = 0;
      }
      else {
        uVar5 = 0;
        do {
          this->SWDSEnableCLUT(uVar5);
          bVar1 = uVar5 != 1;
          uVar5 = uVar5 + 1;
        } while (bVar1);
        iVar2 = 1;
      }
    }
    if (M<SInt32>(self + 0x9a4) != 0) {
      piVar4 = (SInt32 *)this->getPeriodValue("polling-period");
      if (piVar4 != (SInt32 *)0x0) {
        M<UInt32>(self + 0x994) = *piVar4 * 1000 + (UInt32)piVar4[1] / 1000000;
      }
      piVar4 = (SInt32 *)this->getPeriodValue("sample-period");
      if (piVar4 != (SInt32 *)0x0) {
        M<UInt32>(self + 0x998) = *piVar4 * 1000 + (UInt32)piVar4[1] / 1000000;
      }
      this->enable_GPUSensor();
    }
    iVar3 = ((IOATIR500Accelerator *)(self))->disp_mode_did_change();
    if ((iVar3 != 0) && (uVar6 = 1, iVar2 != 0)) goto LAB_00024fa4;
  }
  uVar6 = 0;
LAB_00024fa4:
  GH_IOLockUnlock(M<UInt32>(self + 0x840));
  return uVar6;
}

/* real addr 0x25f00 */
bool ATIRadeonX1000::display_mode_will_change(SInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  SInt32 iVar4;
  UInt32 uVar5;
  SInt32 iVar6;
  UInt32 uVar7;
  UInt8 *pGVar8;
  UInt8 *pAVar9;
  
  GH_IOLockLock(M<UInt32>(self + 0x840));
  if (M<SInt32>(self + 0x9a4) != 0) {
    this->disable_GPUSensor();
  }
  iVar4 = ((IOATIR500Accelerator *)(self))->disp_mode_will_change(param_1);
  SWDSShutdown();
  if (M<SInt32>(self + 3000) != 0) {
    iVar3 = M<SInt32>(self + 0x914);
    iVar6 = M<SInt32>(self + 0x900);
    M<UInt32>(iVar6 + iVar3 * 4) = 0x5c8;
    uVar2 = iVar3 + 1U & 0x7ff;
    M<UInt32>(self + 0x914) = uVar2;
    M<UInt32>(iVar6 + uVar2 * 4) = 0x30000;
    uVar2 = uVar2 + 1 & 0x7ff;
    M<UInt32>(self + 0x914) = uVar2;
    M<UInt32>(iVar6 + uVar2 * 4) = 0x578;
    uVar2 = uVar2 + 1 & 0x7ff;
    uVar5 = uVar2 + 1;
    M<UInt32>(self + 0x914) = uVar5;
    M<UInt32>(iVar6 + uVar2 * 4) = M<UInt32>(self + 0x50);
    M<UInt32>(self + 0x914) = uVar5 & 0x7ff;
    this->submit_ring_data();
    M<SInt32>(self + 0x50) = M<SInt32>(self + 0x50) + 1;
    VCALL(M<SInt32>(self), 0x54c)(self);
  }
  if (M<SInt32>(self + 0x8bc) != 0) {
    VCALL(M<SInt32>(self), 0x5ec)(self,M<SInt32>(self + 0x854) + -1);
    enforceInOrderExecutionIO();
    iVar3 = M<SInt32>(self + 0x860);
    if (-1 < (SInt32)((UInt32)M<UInt8>(iVar3 + 0x1fb7) << 0x18 | (UInt32)M<UInt8>(iVar3 + 0x1fb6) << 0x10
                   | (UInt32)M<UInt8>(iVar3 + 0x1fb5) << 8 | (UInt32)M<UInt8>(iVar3 + 0x1fb4))) {
      iVar3 = 999;
      do {
        GH_IODelay(100);
        iVar6 = M<SInt32>(self + 0x860);
        if ((SInt32)((UInt32)M<UInt8>(iVar6 + 0x1fb7) << 0x18 | (UInt32)M<UInt8>(iVar6 + 0x1fb6) << 0x10
                  | (UInt32)M<UInt8>(iVar6 + 0x1fb5) << 8 | (UInt32)M<UInt8>(iVar6 + 0x1fb4)) < 0)
        break;
        bVar1 = iVar3 != 0;
        iVar3 = iVar3 + -1;
      } while (bVar1);
    }
    iVar3 = stop_xdct_engine();
    if ((iVar3 == 0) || (iVar4 == 0)) {
      iVar4 = 0;
    }
    else {
      iVar4 = 1;
    }
  }
  iVar3 = stop_promo4_engine();
  if ((iVar3 == 0) || (uVar7 = 1, iVar4 == 0)) {
    uVar7 = 0;
  }
  this->shutdownPCIeGART();
  M<UInt32>(self + 3000) = 0;
  if ((M<SInt32>(self + 0x8e0) != 0) && (M<SInt32>(self + 0x8dc) != 0)) {
    ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->dealloc((GLKMemoryElement *)(self + 0x8dc));
  }
  if ((M<SInt32>(self + 0x8f0) != 0) && (M<SInt32>(self + 0x8ec) != 0)) {
    ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->dealloc((GLKMemoryElement *)(self + 0x8ec));
  }
  iVar4 = 0;
  pGVar8 = (self + 300);
  pAVar9 = self;
  do {
    if ((M<SInt32>(pAVar9 + 0x130) != 0) && (M<SInt32>(pAVar9 + 300) != 0)) {
      ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->dealloc((GLKMemoryElement *)pGVar8);
    }
    bVar1 = iVar4 != 1;
    pGVar8 = pGVar8 + 0x78;
    pAVar9 = pAVar9 + 0x78;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->init_pool(0);
  GH_IOLockUnlock(M<UInt32>(self + 0x840));
  return uVar7;
}
