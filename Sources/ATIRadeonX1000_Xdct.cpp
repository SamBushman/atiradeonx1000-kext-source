/*
 * ATIRadeonX1000_Xdct.cpp
 *
 * RESOLVED (ledger pass): start_xdct_engine / stop_xdct_engine.
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


/* real addr 0x25c60 */
bool ATIRadeonX1000::start_xdct_engine() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt8 bVar2;
  UInt32 uVar3;
  SInt32 iVar4;
  SInt32 iVar5;
  UInt32 uVar6;
  
  iVar5 = M<SInt32>(self + 0x860);
  M<UInt32>(iVar5 + 0x1f80) = 0;
  enforceInOrderExecutionIO();
  enforceInOrderExecutionIO();
  uVar6 = (UInt32)M<UInt8>(iVar5 + 0x1f97) << 0x18 | (UInt32)M<UInt8>(iVar5 + 0x1f96) << 0x10 |
          (UInt32)M<UInt8>(iVar5 + 0x1f95) << 8;
  bVar2 = M<UInt8>(iVar5 + 0x1f94);
  M<UInt32>(iVar5 + 0x1f94) =
       (UInt32)bVar2 << 0x18 | (UInt32)M<UInt8>(iVar5 + 0x1f95) << 0x10 |
       (UInt32)M<UInt8>(iVar5 + 0x1f96) << 8 | (uVar6 | 0x88000000) >> 0x18;
  enforceInOrderExecutionIO();
  uVar3 = M<UInt32>(self + 0x930);
  M<UInt32>(iVar5 + 0x1f9c) =
       uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x1fa0) =
       uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
  enforceInOrderExecutionIO();
  iVar4 = M<SInt32>(self + 0x8a4);
  uVar3 = iVar4 + M<SInt32>(self + 0x228) + (M<SInt32>(self + 0x928) - M<SInt32>(self + 0x238));
  M<UInt32>(iVar5 + 0x1f98) =
       (uVar3 & 0xfffffffc) << 0x18 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
  enforceInOrderExecutionIO();
  uVar3 = iVar4 + M<SInt32>(self + 0x920);
  M<UInt32>(iVar5 + 0x1f90) =
       uVar3 * 0x1000000 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
  enforceInOrderExecutionIO();
  uVar6 = uVar6 & 0x67fcc0ff | (UInt32)bVar2 | 0x2002030a;
  M<UInt32>(iVar5 + 0x1f94) =
       uVar6 << 0x18 | (uVar6 & 0xff00) << 8 | uVar6 >> 8 & 0xff00 | uVar6 >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x1f80) = 0x40;
  enforceInOrderExecutionIO();
  uVar6 = M<SInt32>(self + 0x854) - 1;
  M<UInt32>(iVar5 + 0x1fa8) =
       uVar6 * 0x1000000 | (uVar6 & 0xff00) << 8 | uVar6 >> 8 & 0xff00 | uVar6 >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x1f80) = 0xa000580;
  enforceInOrderExecutionIO();
  if (((UInt32)M<UInt8>(iVar5 + 0x1f9f) << 0x18 | (UInt32)M<UInt8>(iVar5 + 0x1f9e) << 0x10 |
       (UInt32)M<UInt8>(iVar5 + 0x1f9d) << 8 | (UInt32)M<UInt8>(iVar5 + 0x1f9c)) <
      ((UInt32)M<UInt8>(iVar5 + 0x1fa3) << 0x18 | (UInt32)M<UInt8>(iVar5 + 0x1fa2) << 0x10 |
       (UInt32)M<UInt8>(iVar5 + 0x1fa1) << 8 | (UInt32)M<UInt8>(iVar5 + 0x1fa0))) {
    iVar4 = 0;
    do {
      GH_assert_wait_timeout(&gl_assert_wait_timeout_event,0,100,1000);
      GH_thread_block(0);
      iVar5 = M<SInt32>(self + 0x860);
      bVar1 = iVar4 == 10000;
      iVar4 = iVar4 + 1;
      if (bVar1) break;
    } while (((UInt32)M<UInt8>(iVar5 + 0x1f9f) << 0x18 | (UInt32)M<UInt8>(iVar5 + 0x1f9e) << 0x10 |
              (UInt32)M<UInt8>(iVar5 + 0x1f9d) << 8 | (UInt32)M<UInt8>(iVar5 + 0x1f9c)) <
             ((UInt32)M<UInt8>(iVar5 + 0x1fa3) << 0x18 | (UInt32)M<UInt8>(iVar5 + 0x1fa2) << 0x10 |
              (UInt32)M<UInt8>(iVar5 + 0x1fa1) << 8 | (UInt32)M<UInt8>(iVar5 + 0x1fa0)));
  }
  M<UInt32>(self + 0x8bc) = 1;
  return 1;
}

/* real addr 0x25df0 */
bool ATIRadeonX1000::stop_xdct_engine() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  SInt32 iVar2;
  SInt32 iVar3;
  
  iVar2 = M<SInt32>(self + 0x860);
  if (((UInt32)M<UInt8>(iVar2 + 0x1f9f) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x1f9e) << 0x10 |
       (UInt32)M<UInt8>(iVar2 + 0x1f9d) << 8 | (UInt32)M<UInt8>(iVar2 + 0x1f9c)) <
      ((UInt32)M<UInt8>(iVar2 + 0x1fa3) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x1fa2) << 0x10 |
       (UInt32)M<UInt8>(iVar2 + 0x1fa1) << 8 | (UInt32)M<UInt8>(iVar2 + 0x1fa0))) {
    iVar3 = 0;
    do {
      GH_assert_wait_timeout(&gl_assert_wait_timeout_event,0,100,1000);
      GH_thread_block(0);
      iVar2 = M<SInt32>(self + 0x860);
      bVar1 = iVar3 == 10000;
      iVar3 = iVar3 + 1;
      if (bVar1) break;
    } while (((UInt32)M<UInt8>(iVar2 + 0x1f9f) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x1f9e) << 0x10 |
              (UInt32)M<UInt8>(iVar2 + 0x1f9d) << 8 | (UInt32)M<UInt8>(iVar2 + 0x1f9c)) <
             ((UInt32)M<UInt8>(iVar2 + 0x1fa3) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x1fa2) << 0x10 |
              (UInt32)M<UInt8>(iVar2 + 0x1fa1) << 8 | (UInt32)M<UInt8>(iVar2 + 0x1fa0)));
  }
  enforceInOrderExecutionIO();
  M<UInt32>(iVar2 + 0x1f94) =
       (UInt32)M<UInt8>(iVar2 + 0x1f94) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x1f95) << 0x10 |
       (UInt32)M<UInt8>(iVar2 + 0x1f96) << 8 |
       ((UInt32)M<UInt8>(iVar2 + 0x1f97) << 0x18 | 0x88000000) >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar2 + 0x1f80) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar2 + 0x1f9c) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar2 + 0x1fa0) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(self + 0x8bc) = 0;
  return 1;
}

