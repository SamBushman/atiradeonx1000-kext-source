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
extern "C" UInt32 GH_IOSleep(...) asm("_IOSleep");
extern "C" UInt32 GH_OSDecrementAtomic(...) asm("_OSDecrementAtomic");
extern "C" UInt32 GH_OSIncrementAtomic(...) asm("_OSIncrementAtomic");
extern "C" UInt32 GH_absolutetime_to_nanoseconds(...) asm("_absolutetime_to_nanoseconds");
extern "C" UInt32 GH_assert_wait_timeout(...) asm("_assert_wait_timeout");
extern "C" UInt32 GH_clock_get_uptime(...) asm("_clock_get_uptime");
extern "C" UInt32 GH_thread_block(...) asm("_thread_block");


/* real addr 0x1e100 */
void ATIRadeonX1000::GPUSensorFunc(OSObject *owner, IOTimerEventSource *source) {
    UInt8 *ownerBytes = reinterpret_cast<UInt8 *>(owner);

  UInt8 *ringReadPointerAddress;
  SInt32 mmioBase;
  
  GH_IOLockLock(M<UInt32>(ownerBytes + 0x840));
  if (ownerBytes[0x80] != 0x0) {
    ringReadPointerAddress = (UInt8 *)(M<SInt32>(ownerBytes + 0x90c) + M<SInt32>(ownerBytes + 0x910));
    if (((loadWordByteReversed(ringReadPointerAddress))
         == M<UInt32>(ownerBytes + 0x914)) &&
       (mmioBase = M<SInt32>(ownerBytes + 0x860),
       -1 < (SInt32)(loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40))))) {
      if ((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x10000) != 0) {
        if ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x60000) == 0) {
          if (((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x20000) != 0) && ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x380000) == 0)) {
            M<SInt32>(ownerBytes + 0x99c) = M<SInt32>(ownerBytes + 0x99c) + 1;
          }
        }
      }
    }
    M<SInt32>(ownerBytes + 0x9a0) = M<SInt32>(ownerBytes + 0x9a0) + 1;
    VCALL(*M<SInt32 *>(ownerBytes + 0x9a8), 300)
              (M<SInt32 *>(ownerBytes + 0x9a8),M<UInt32>(ownerBytes + 0x998));
  }
  GH_IOLockUnlock(M<UInt32>(ownerBytes + 0x840));
  return;
}

/* real addr 0x1e210 */
void ATIRadeonX1000::system_did_change_speed() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 previousDepth;
  SInt32 *period;
  
  previousDepth = GH_OSDecrementAtomic(self + kIOATIR500Accelerator_displayChangeDepth);
  if (previousDepth == 1) {
    if (M<SInt32>(self + kIOATIR500Accelerator_gpuSensorProvider) != 0) {
      period = (SInt32 *)this->getPeriodValue("polling-period");
      if (period != (SInt32 *)0x0) {
        M<UInt32>(self + kIOATIR500Accelerator_swdsPeriodMsA) = *period * 1000 + (UInt32)period[1] / 1000000;
      }
      period = (SInt32 *)this->getPeriodValue("sample-period");
      if (period != (SInt32 *)0x0) {
        M<UInt32>(self + kIOATIR500Accelerator_gpuSensorPeriodMs) = *period * 1000 + (UInt32)period[1] / 1000000;
      }
      ((ATIRadeonX1000 *)(self))->enable_GPUSensor();
    }
    GH_IOLockUnlock(M<UInt32>(self + kIOATIR500Accelerator_commandLock));
  }
  return;
}

/* real addr 0x1f1e0 */
void ATIRadeonX1000::system_will_change_speed() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool loopContinues;
  UInt32 ringIndex;
  SInt32 triesLeft;
  UInt32 nextRingIndex;
  SInt32 ringMemory;
  SInt32 previousDepth;
  SInt32 ringIndexOld;
  SInt32 mmioBase;
  
  previousDepth = GH_OSIncrementAtomic(self + kIOATIR500Accelerator_displayChangeDepth);
  if (previousDepth == 0) {
    GH_IOLockLock(M<UInt32>(self + kIOATIR500Accelerator_commandLock));
    if (M<SInt32>(self + kIOATIR500Accelerator_gpuSensorProvider) != 0) {
      ((ATIRadeonX1000 *)(self))->disable_GPUSensor();
    }
    if (self[0x80] != 0x0) {
      ringIndexOld = M<SInt32>(self + kIOATIR500Accelerator_ringIndex);
      ringMemory = M<SInt32>(self + kIOATIR500Accelerator_mainRingMemory);
      M<UInt32>(ringMemory + ringIndexOld * 4) = 0x5c8;
      ringIndex = ringIndexOld + 1U & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = ringIndex;
      M<UInt32>(ringMemory + ringIndex * 4) = 0x70000;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = ringIndex;
      M<UInt32>(ringMemory + ringIndex * 4) = 0x578;
      ringIndex = ringIndex + 1 & 0x7ff;
      nextRingIndex = ringIndex + 1;
      M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = nextRingIndex;
      M<UInt32>(ringMemory + ringIndex * 4) = M<UInt32>(self + kIOATIR500Accelerator_submitStamp);
      M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = nextRingIndex & 0x7ff;
      ((ATIRadeonX1000 *)(self))->submit_ring_data();
      VCALL(M<SInt32>(self), 0x54c)(self,M<UInt32>(self + kIOATIR500Accelerator_submitStamp));
      M<SInt32>(self + kIOATIR500Accelerator_submitStamp) = M<SInt32>(self + kIOATIR500Accelerator_submitStamp) + 1;
      if (M<SInt32>(self + kIOATIR500Accelerator_xdctEngineRunning) != 0) {
        VCALL(M<SInt32>(self), 0x5ec)(self,M<SInt32>(self + kIOATIR500Accelerator_idctSubmitBaseCounter) + -1);
        enforceInOrderExecutionIO();
        mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
        if (-1 < (SInt32)(loadWordByteReversed(&M<UInt8>(mmioBase + 0x1fb4)))) {
          triesLeft = 999;
          do {
            GH_IODelay(0x32);
            mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
            if ((SInt32)(loadWordByteReversed(&M<UInt8>(mmioBase + 0x1fb4))) < 0) {
              return;
            }
            loopContinues = triesLeft != 0;
            triesLeft = triesLeft + -1;
          } while (loopContinues);
        }
      }
    }
  }
  return;
}

