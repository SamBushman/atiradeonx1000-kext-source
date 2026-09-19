/*
 * ATIRadeonX1000_TimeStamps.cpp
 *
 * RESOLVED (ledger pass): wait/sleep-for timestamp members.
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


/* real addr 0x25080 */
IOReturn ATIRadeonX1000::waitForRetiredTimeStamp(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *pbVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  bool bVar4;
  UInt32 local_48;
  SInt32 local_44;
  SInt32 local_40;
  UInt32 local_3c;
  SInt32 local_38;
  UInt32 local_34;
  
  local_48 = 0;
  local_44 = 0;
  if ((SInt32)(param_1 - M<SInt32>(self + 0x858)) < 1) {
    local_44 = 0;
  }
  else {
    GH_clock_get_uptime(&local_40);
    pbVar1 = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x868));
    uVar2 = (UInt32)pbVar1[3] << 0x18 | (UInt32)pbVar1[2] << 0x10 | (UInt32)pbVar1[1] << 8 | (UInt32)*pbVar1
    ;
    M<UInt32>(self + 0x858) = uVar2;
    if (0 < (SInt32)(param_1 - uVar2)) {
      iVar3 = 1;
      do {
        GH_assert_wait_timeout(&gl_assert_wait_timeout_event,0,100,1000);
        GH_thread_block(0);
        pbVar1 = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x868));
        uVar2 = (UInt32)pbVar1[3] << 0x18 | (UInt32)pbVar1[2] << 0x10 | (UInt32)pbVar1[1] << 8 |
                (UInt32)*pbVar1;
        M<UInt32>(self + 0x858) = uVar2;
        if ((SInt32)(param_1 - uVar2) < 1) break;
        iVar3 = iVar3 + 1;
      } while (iVar3 != 0xc351);
    }
    GH_clock_get_uptime(&local_38);
    bVar4 = local_34 < local_3c;
    local_34 = local_34 - local_3c;
    local_38 = local_38 - (local_40 + (UInt32)bVar4);
    GH_absolutetime_to_nanoseconds(local_38,local_34,&local_48);
    M<SInt32>(self + 0x760) = M<SInt32>(self + 0x760) + local_44;
  }
  return local_44;
}

/* real addr 0x25360 */
UInt32 ATIRadeonX1000::waitForTimeStampNoLock(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *pbVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  bool bVar4;
  UInt32 local_38;
  SInt32 local_34;
  SInt32 local_30;
  UInt32 local_2c;
  SInt32 local_28;
  UInt32 local_24;
  
  local_38 = 0;
  local_34 = 0;
  if ((SInt32)(param_1 - M<SInt32>(self + 0x54)) < 1) {
    local_34 = 0;
  }
  else {
    GH_clock_get_uptime(&local_30);
    pbVar1 = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x86c));
    uVar2 = (UInt32)pbVar1[3] << 0x18 | (UInt32)pbVar1[2] << 0x10 | (UInt32)pbVar1[1] << 8 | (UInt32)*pbVar1
    ;
    M<UInt32>(self + 0x54) = uVar2;
    iVar3 = 0;
    if (0 < (SInt32)(param_1 - uVar2)) {
      iVar3 = 1;
      do {
        GH_assert_wait_timeout(&gl_assert_wait_timeout_event,0,100,1000);
        GH_thread_block(0);
        pbVar1 = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x86c));
        uVar2 = (UInt32)pbVar1[3] << 0x18 | (UInt32)pbVar1[2] << 0x10 | (UInt32)pbVar1[1] << 8 |
                (UInt32)*pbVar1;
        M<UInt32>(self + 0x54) = uVar2;
        if ((SInt32)(param_1 - uVar2) < 1) break;
        iVar3 = iVar3 + 1;
      } while (iVar3 != 0xc351);
    }
    GH_clock_get_uptime(&local_28);
    bVar4 = local_24 < local_2c;
    local_24 = local_24 - local_2c;
    local_28 = local_28 - (local_30 + (UInt32)bVar4);
    GH_absolutetime_to_nanoseconds(local_28,local_24,&local_38);
    M<SInt32>(self + 0x760) = M<SInt32>(self + 0x760) + local_34;
    if (iVar3 == 0xc351) {
      return -1;
    }
  }
  return local_34;
}

/* real addr 0x25660 */
UInt32 ATIRadeonX1000::sleepForConsumedIDCTTimeStamp(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  bool bVar4;
  UInt32 local_38;
  SInt32 local_34;
  SInt32 local_30;
  UInt32 local_2c;
  SInt32 local_28;
  UInt32 local_24;
  
  local_38 = 0;
  local_34 = 0;
  if ((SInt32)(param_1 - M<SInt32>(self + 0x85c)) < 1) {
    local_34 = 0;
  }
  else {
    GH_clock_get_uptime(&local_30);
    iVar1 = M<SInt32>(self + 0x860);
    uVar2 = (UInt32)M<UInt8>(iVar1 + 0x1fab) << 0x18 | (UInt32)M<UInt8>(iVar1 + 0x1faa) << 0x10 |
            (UInt32)M<UInt8>(iVar1 + 0x1fa9) << 8 | (UInt32)M<UInt8>(iVar1 + 0x1fa8);
    M<UInt32>(self + 0x85c) = uVar2;
    iVar1 = 0;
    if (0 < (SInt32)(param_1 - uVar2)) {
      iVar1 = 1;
      do {
        GH_assert_wait_timeout(&gl_assert_wait_timeout_event,0,100,1000);
        GH_thread_block(0);
        iVar3 = M<SInt32>(self + 0x860);
        uVar2 = (UInt32)M<UInt8>(iVar3 + 0x1fab) << 0x18 | (UInt32)M<UInt8>(iVar3 + 0x1faa) << 0x10 |
                (UInt32)M<UInt8>(iVar3 + 0x1fa9) << 8 | (UInt32)M<UInt8>(iVar3 + 0x1fa8);
        M<UInt32>(self + 0x85c) = uVar2;
        if ((SInt32)(param_1 - uVar2) < 1) break;
        iVar1 = iVar1 + 1;
      } while (iVar1 != 0xc351);
    }
    GH_clock_get_uptime(&local_28);
    bVar4 = local_24 < local_2c;
    local_24 = local_24 - local_2c;
    local_28 = local_28 - (local_30 + (UInt32)bVar4);
    GH_absolutetime_to_nanoseconds(local_28,local_24,&local_38);
    M<SInt32>(self + 0x760) = M<SInt32>(self + 0x760) + local_34;
    if (iVar1 == 0xc351) {
      return -1;
    }
  }
  return local_34;
}

/* real addr 0x257e0 */
UInt32 ATIRadeonX1000::sleepForRetiredTimeStamp(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *pbVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  bool bVar4;
  UInt32 local_38;
  SInt32 local_34;
  SInt32 local_30;
  UInt32 local_2c;
  SInt32 local_28;
  UInt32 local_24;
  
  local_38 = 0;
  local_34 = 0;
  if ((SInt32)(param_1 - M<SInt32>(self + 0x858)) < 1) {
    local_34 = 0;
  }
  else {
    GH_clock_get_uptime(&local_30);
    pbVar1 = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x868));
    uVar2 = (UInt32)pbVar1[3] << 0x18 | (UInt32)pbVar1[2] << 0x10 | (UInt32)pbVar1[1] << 8 | (UInt32)*pbVar1
    ;
    M<UInt32>(self + 0x858) = uVar2;
    iVar3 = 0;
    if (0 < (SInt32)(param_1 - uVar2)) {
      iVar3 = 1;
      do {
        GH_assert_wait_timeout(&gl_assert_wait_timeout_event,0,100,1000);
        GH_thread_block(0);
        pbVar1 = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x868));
        uVar2 = (UInt32)pbVar1[3] << 0x18 | (UInt32)pbVar1[2] << 0x10 | (UInt32)pbVar1[1] << 8 |
                (UInt32)*pbVar1;
        M<UInt32>(self + 0x858) = uVar2;
        if ((SInt32)(param_1 - uVar2) < 1) break;
        iVar3 = iVar3 + 1;
      } while (iVar3 != 0xc351);
    }
    GH_clock_get_uptime(&local_28);
    bVar4 = local_24 < local_2c;
    local_24 = local_24 - local_2c;
    local_28 = local_28 - (local_30 + (UInt32)bVar4);
    GH_absolutetime_to_nanoseconds(local_28,local_24,&local_38);
    M<SInt32>(self + 0x760) = M<SInt32>(self + 0x760) + local_34;
    if (iVar3 == 0xc351) {
      return -1;
    }
  }
  return local_34;
}

/* real addr 0x25ae0 */
UInt32 ATIRadeonX1000::sleepForTimeStampNoLock(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *pbVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  bool bVar4;
  UInt32 local_38;
  SInt32 local_34;
  SInt32 local_30;
  UInt32 local_2c;
  SInt32 local_28;
  UInt32 local_24;
  
  local_38 = 0;
  local_34 = 0;
  if ((SInt32)(param_1 - M<SInt32>(self + 0x54)) < 1) {
    local_34 = 0;
  }
  else {
    GH_clock_get_uptime(&local_30);
    pbVar1 = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x86c));
    uVar2 = (UInt32)pbVar1[3] << 0x18 | (UInt32)pbVar1[2] << 0x10 | (UInt32)pbVar1[1] << 8 | (UInt32)*pbVar1
    ;
    M<UInt32>(self + 0x54) = uVar2;
    iVar3 = 0;
    if (0 < (SInt32)(param_1 - uVar2)) {
      iVar3 = 1;
      do {
        GH_assert_wait_timeout(&gl_assert_wait_timeout_event,0,100,1000);
        GH_thread_block(0);
        pbVar1 = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x86c));
        uVar2 = (UInt32)pbVar1[3] << 0x18 | (UInt32)pbVar1[2] << 0x10 | (UInt32)pbVar1[1] << 8 |
                (UInt32)*pbVar1;
        M<UInt32>(self + 0x54) = uVar2;
        if ((SInt32)(param_1 - uVar2) < 1) break;
        iVar3 = iVar3 + 1;
      } while (iVar3 != 0xc351);
    }
    GH_clock_get_uptime(&local_28);
    bVar4 = local_24 < local_2c;
    local_24 = local_24 - local_2c;
    local_28 = local_28 - (local_30 + (UInt32)bVar4);
    GH_absolutetime_to_nanoseconds(local_28,local_24,&local_38);
    M<SInt32>(self + 0x760) = M<SInt32>(self + 0x760) + local_34;
    if (iVar3 == 0xc351) {
      return -1;
    }
  }
  return local_34;
}

