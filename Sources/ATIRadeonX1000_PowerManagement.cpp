/*
 * ATIRadeonX1000_PowerManagement.cpp
 *
 * RESOLVED (ledger pass): GPUSensorFunc (timer), system_did_change_speed, system_will_change_speed.
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


/* real addr 0x1e100 */
void ATIRadeonX1000::GPUSensorFunc(OSObject *real_param_1, IOTimerEventSource *param_2) {
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt8 *pbVar1;
  SInt32 iVar2;
  
  GH_IOLockLock(M<UInt32>(param_1 + 0x840));
  if (param_1[0x80] != 0x0) {
    pbVar1 = (UInt8 *)(M<SInt32>(param_1 + 0x90c) + M<SInt32>(param_1 + 0x910));
    if ((((UInt32)pbVar1[3] << 0x18 | (UInt32)pbVar1[2] << 0x10 | (UInt32)pbVar1[1] << 8 | (UInt32)*pbVar1)
         == M<UInt32>(param_1 + 0x914)) &&
       (iVar2 = M<SInt32>(param_1 + 0x860),
       -1 < (SInt32)((UInt32)M<UInt8>(iVar2 + 0xe43) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0xe42) << 0x10 |
                  (UInt32)M<UInt8>(iVar2 + 0xe41) << 8 | (UInt32)M<UInt8>(iVar2 + 0xe40)))) {
      if ((M<UInt8>(iVar2 + 0x1722) & 1) != 0) {
        if ((M<UInt8>(iVar2 + 0xe42) & 6) == 0) {
          if (((M<UInt8>(iVar2 + 0x1722) & 2) != 0) && ((M<UInt8>(iVar2 + 0xe42) & 0x38) == 0)) {
            M<SInt32>(param_1 + 0x99c) = M<SInt32>(param_1 + 0x99c) + 1;
          }
        }
      }
    }
    M<SInt32>(param_1 + 0x9a0) = M<SInt32>(param_1 + 0x9a0) + 1;
    VCALL(*M<SInt32 *>(param_1 + 0x9a8), 300)
              (M<SInt32 *>(param_1 + 0x9a8),M<UInt32>(param_1 + 0x998));
  }
  GH_IOLockUnlock(M<UInt32>(param_1 + 0x840));
  return;
}

/* real addr 0x1e210 */
void ATIRadeonX1000::system_did_change_speed() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  SInt32 *piVar2;
  
  iVar1 = GH_OSDecrementAtomic(self + 200);
  if (iVar1 == 1) {
    if (M<SInt32>(self + 0x9a4) != 0) {
      piVar2 = (SInt32 *)this->getPeriodValue("polling-period");
      if (piVar2 != (SInt32 *)0x0) {
        M<UInt32>(self + 0x994) = *piVar2 * 1000 + (UInt32)piVar2[1] / 1000000;
      }
      piVar2 = (SInt32 *)this->getPeriodValue("sample-period");
      if (piVar2 != (SInt32 *)0x0) {
        M<UInt32>(self + 0x998) = *piVar2 * 1000 + (UInt32)piVar2[1] / 1000000;
      }
      ((ATIRadeonX1000 *)(self))->enable_GPUSensor();
    }
    GH_IOLockUnlock(M<UInt32>(self + 0x840));
  }
  return;
}

/* real addr 0x1f1e0 */
void ATIRadeonX1000::system_will_change_speed() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  
  iVar3 = GH_OSIncrementAtomic(self + 200);
  if (iVar3 == 0) {
    GH_IOLockLock(M<UInt32>(self + 0x840));
    if (M<SInt32>(self + 0x9a4) != 0) {
      ((ATIRadeonX1000 *)(self))->disable_GPUSensor();
    }
    if (self[0x80] != 0x0) {
      iVar3 = M<SInt32>(self + 0x914);
      iVar5 = M<SInt32>(self + 0x900);
      M<UInt32>(iVar5 + iVar3 * 4) = 0x5c8;
      uVar2 = iVar3 + 1U & 0x7ff;
      M<UInt32>(self + 0x914) = uVar2;
      M<UInt32>(iVar5 + uVar2 * 4) = 0x70000;
      uVar2 = uVar2 + 1 & 0x7ff;
      M<UInt32>(self + 0x914) = uVar2;
      M<UInt32>(iVar5 + uVar2 * 4) = 0x578;
      uVar2 = uVar2 + 1 & 0x7ff;
      uVar4 = uVar2 + 1;
      M<UInt32>(self + 0x914) = uVar4;
      M<UInt32>(iVar5 + uVar2 * 4) = M<UInt32>(self + 0x50);
      M<UInt32>(self + 0x914) = uVar4 & 0x7ff;
      ((ATIRadeonX1000 *)(self))->submit_ring_data();
      VCALL(M<SInt32>(self), 0x54c)(self,M<UInt32>(self + 0x50));
      M<SInt32>(self + 0x50) = M<SInt32>(self + 0x50) + 1;
      if (M<SInt32>(self + 0x8bc) != 0) {
        VCALL(M<SInt32>(self), 0x5ec)(self,M<SInt32>(self + 0x854) + -1);
        enforceInOrderExecutionIO();
        iVar3 = M<SInt32>(self + 0x860);
        if (-1 < (SInt32)((UInt32)M<UInt8>(iVar3 + 0x1fb7) << 0x18 |
                       (UInt32)M<UInt8>(iVar3 + 0x1fb6) << 0x10 |
                       (UInt32)M<UInt8>(iVar3 + 0x1fb5) << 8 | (UInt32)M<UInt8>(iVar3 + 0x1fb4))) {
          iVar3 = 999;
          do {
            GH_IODelay(0x32);
            iVar5 = M<SInt32>(self + 0x860);
            if ((SInt32)((UInt32)M<UInt8>(iVar5 + 0x1fb7) << 0x18 |
                      (UInt32)M<UInt8>(iVar5 + 0x1fb6) << 0x10 | (UInt32)M<UInt8>(iVar5 + 0x1fb5) << 8
                     | (UInt32)M<UInt8>(iVar5 + 0x1fb4)) < 0) {
              return;
            }
            bVar1 = iVar3 != 0;
            iVar3 = iVar3 + -1;
          } while (bVar1);
        }
      }
    }
  }
  return;
}

