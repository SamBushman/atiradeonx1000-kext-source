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
extern "C" UInt32 GH_IOSleep(...) asm("_IOSleep");
extern "C" UInt32 GH_OSDecrementAtomic(...) asm("_OSDecrementAtomic");
extern "C" UInt32 GH_OSIncrementAtomic(...) asm("_OSIncrementAtomic");
extern "C" UInt32 GH_absolutetime_to_nanoseconds(...) asm("_absolutetime_to_nanoseconds");
extern "C" UInt32 GH_assert_wait_timeout(...) asm("_assert_wait_timeout");
extern "C" UInt32 GH_clock_get_uptime(...) asm("_clock_get_uptime");
extern "C" UInt32 GH_thread_block(...) asm("_thread_block");


/* real addr 0x25080 */
IOReturn ATIRadeonX1000::waitForRetiredTimeStamp(UInt32 tag) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *stampAddress;
  UInt32 currentStamp;
  SInt32 pollCount;
  bool borrow;
  UInt32 startTime[2], endTime[2], elapsedNs[2];   /* 8-byte results of clock_get_uptime / absolutetime_to_nanoseconds: hi word first (Ghidra shows them as two adjacent locals) */
  
  elapsedNs[0] = 0;
  elapsedNs[1] = 0;
  if ((SInt32)(tag - M<SInt32>(self + 0x858)) < 1) {
    elapsedNs[1] = 0;
  }
  else {
    GH_clock_get_uptime(&startTime[0]);
    stampAddress = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x868));
    currentStamp = loadWordByteReversed(stampAddress)
    ;
    M<UInt32>(self + 0x858) = currentStamp;
    if (0 < (SInt32)(tag - currentStamp)) {
      pollCount = 1;
      do {
        GH_assert_wait_timeout(&gl_assert_wait_timeout_event,0,100,1000);
        GH_thread_block(0);
        stampAddress = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x868));
        currentStamp = loadWordByteReversed(stampAddress);
        M<UInt32>(self + 0x858) = currentStamp;
        if ((SInt32)(tag - currentStamp) < 1) break;
        pollCount = pollCount + 1;
      } while (pollCount != 0xc351);
    }
    GH_clock_get_uptime(&endTime[0]);
    borrow = endTime[1] < startTime[1];
    endTime[1] = endTime[1] - startTime[1];
    endTime[0] = endTime[0] - (startTime[0] + (UInt32)borrow);
    GH_absolutetime_to_nanoseconds(endTime[0],endTime[1],&elapsedNs[0]);
    M<SInt32>(self + 0x760) = M<SInt32>(self + 0x760) + elapsedNs[1];
  }
  return elapsedNs[1];
}

/* real addr 0x25360 */
UInt32 ATIRadeonX1000::waitForTimeStampNoLock(UInt32 tag) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *stampAddress;
  UInt32 currentStamp;
  SInt32 pollCount;
  bool borrow;
  UInt32 startTime[2], endTime[2], elapsedNs[2];   /* 8-byte results of clock_get_uptime / absolutetime_to_nanoseconds: hi word first (Ghidra shows them as two adjacent locals) */
  
  elapsedNs[0] = 0;
  elapsedNs[1] = 0;
  if ((SInt32)(tag - M<SInt32>(self + 0x54)) < 1) {
    elapsedNs[1] = 0;
  }
  else {
    GH_clock_get_uptime(&startTime[0]);
    stampAddress = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x86c));
    currentStamp = loadWordByteReversed(stampAddress)
    ;
    M<UInt32>(self + 0x54) = currentStamp;
    pollCount = 0;
    if (0 < (SInt32)(tag - currentStamp)) {
      pollCount = 1;
      do {
        GH_assert_wait_timeout(&gl_assert_wait_timeout_event,0,100,1000);
        GH_thread_block(0);
        stampAddress = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x86c));
        currentStamp = loadWordByteReversed(stampAddress);
        M<UInt32>(self + 0x54) = currentStamp;
        if ((SInt32)(tag - currentStamp) < 1) break;
        pollCount = pollCount + 1;
      } while (pollCount != 0xc351);
    }
    GH_clock_get_uptime(&endTime[0]);
    borrow = endTime[1] < startTime[1];
    endTime[1] = endTime[1] - startTime[1];
    endTime[0] = endTime[0] - (startTime[0] + (UInt32)borrow);
    GH_absolutetime_to_nanoseconds(endTime[0],endTime[1],&elapsedNs[0]);
    M<SInt32>(self + 0x760) = M<SInt32>(self + 0x760) + elapsedNs[1];
    if (pollCount == 0xc351) {
      return -1;
    }
  }
  return elapsedNs[1];
}

/* real addr 0x25660 */
UInt32 ATIRadeonX1000::sleepForConsumedIDCTTimeStamp(UInt32 tag) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt32 currentStamp;
  SInt32 mmioBase;
  bool borrow;
  UInt32 startTime[2], endTime[2], elapsedNs[2];   /* 8-byte results of clock_get_uptime / absolutetime_to_nanoseconds: hi word first (Ghidra shows them as two adjacent locals) */
  
  elapsedNs[0] = 0;
  elapsedNs[1] = 0;
  if ((SInt32)(tag - M<SInt32>(self + 0x85c)) < 1) {
    elapsedNs[1] = 0;
  }
  else {
    GH_clock_get_uptime(&startTime[0]);
    iVar1 = M<SInt32>(self + 0x860);
    currentStamp = loadWordByteReversed(&M<UInt8>(iVar1 + 0x1fa8));
    M<UInt32>(self + 0x85c) = currentStamp;
    iVar1 = 0;
    if (0 < (SInt32)(tag - currentStamp)) {
      iVar1 = 1;
      do {
        GH_assert_wait_timeout(&gl_assert_wait_timeout_event,0,100,1000);
        GH_thread_block(0);
        mmioBase = M<SInt32>(self + 0x860);
        currentStamp = loadWordByteReversed(&M<UInt8>(mmioBase + 0x1fa8));
        M<UInt32>(self + 0x85c) = currentStamp;
        if ((SInt32)(tag - currentStamp) < 1) break;
        iVar1 = iVar1 + 1;
      } while (iVar1 != 0xc351);
    }
    GH_clock_get_uptime(&endTime[0]);
    borrow = endTime[1] < startTime[1];
    endTime[1] = endTime[1] - startTime[1];
    endTime[0] = endTime[0] - (startTime[0] + (UInt32)borrow);
    GH_absolutetime_to_nanoseconds(endTime[0],endTime[1],&elapsedNs[0]);
    M<SInt32>(self + 0x760) = M<SInt32>(self + 0x760) + elapsedNs[1];
    if (iVar1 == 0xc351) {
      return -1;
    }
  }
  return elapsedNs[1];
}

/* real addr 0x257e0 */
UInt32 ATIRadeonX1000::sleepForRetiredTimeStamp(UInt32 tag) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *stampAddress;
  UInt32 currentStamp;
  SInt32 pollCount;
  bool borrow;
  UInt32 startTime[2], endTime[2], elapsedNs[2];   /* 8-byte results of clock_get_uptime / absolutetime_to_nanoseconds: hi word first (Ghidra shows them as two adjacent locals) */
  
  elapsedNs[0] = 0;
  elapsedNs[1] = 0;
  if ((SInt32)(tag - M<SInt32>(self + 0x858)) < 1) {
    elapsedNs[1] = 0;
  }
  else {
    GH_clock_get_uptime(&startTime[0]);
    stampAddress = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x868));
    currentStamp = loadWordByteReversed(stampAddress)
    ;
    M<UInt32>(self + 0x858) = currentStamp;
    pollCount = 0;
    if (0 < (SInt32)(tag - currentStamp)) {
      pollCount = 1;
      do {
        GH_assert_wait_timeout(&gl_assert_wait_timeout_event,0,100,1000);
        GH_thread_block(0);
        stampAddress = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x868));
        currentStamp = loadWordByteReversed(stampAddress);
        M<UInt32>(self + 0x858) = currentStamp;
        if ((SInt32)(tag - currentStamp) < 1) break;
        pollCount = pollCount + 1;
      } while (pollCount != 0xc351);
    }
    GH_clock_get_uptime(&endTime[0]);
    borrow = endTime[1] < startTime[1];
    endTime[1] = endTime[1] - startTime[1];
    endTime[0] = endTime[0] - (startTime[0] + (UInt32)borrow);
    GH_absolutetime_to_nanoseconds(endTime[0],endTime[1],&elapsedNs[0]);
    M<SInt32>(self + 0x760) = M<SInt32>(self + 0x760) + elapsedNs[1];
    if (pollCount == 0xc351) {
      return -1;
    }
  }
  return elapsedNs[1];
}

/* real addr 0x25ae0 */
UInt32 ATIRadeonX1000::sleepForTimeStampNoLock(UInt32 tag) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *stampAddress;
  UInt32 currentStamp;
  SInt32 pollCount;
  bool borrow;
  UInt32 startTime[2], endTime[2], elapsedNs[2];   /* 8-byte results of clock_get_uptime / absolutetime_to_nanoseconds: hi word first (Ghidra shows them as two adjacent locals) */
  
  elapsedNs[0] = 0;
  elapsedNs[1] = 0;
  if ((SInt32)(tag - M<SInt32>(self + 0x54)) < 1) {
    elapsedNs[1] = 0;
  }
  else {
    GH_clock_get_uptime(&startTime[0]);
    stampAddress = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x86c));
    currentStamp = loadWordByteReversed(stampAddress)
    ;
    M<UInt32>(self + 0x54) = currentStamp;
    pollCount = 0;
    if (0 < (SInt32)(tag - currentStamp)) {
      pollCount = 1;
      do {
        GH_assert_wait_timeout(&gl_assert_wait_timeout_event,0,100,1000);
        GH_thread_block(0);
        stampAddress = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x86c));
        currentStamp = loadWordByteReversed(stampAddress);
        M<UInt32>(self + 0x54) = currentStamp;
        if ((SInt32)(tag - currentStamp) < 1) break;
        pollCount = pollCount + 1;
      } while (pollCount != 0xc351);
    }
    GH_clock_get_uptime(&endTime[0]);
    borrow = endTime[1] < startTime[1];
    endTime[1] = endTime[1] - startTime[1];
    endTime[0] = endTime[0] - (startTime[0] + (UInt32)borrow);
    GH_absolutetime_to_nanoseconds(endTime[0],endTime[1],&elapsedNs[0]);
    M<SInt32>(self + 0x760) = M<SInt32>(self + 0x760) + elapsedNs[1];
    if (pollCount == 0xc351) {
      return -1;
    }
  }
  return elapsedNs[1];
}

/* real addr 0x251e0 */
UInt32 ATIRadeonX1000::waitForTimeStamp(UInt32 tag) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *stampAddress;
  UInt32 currentStamp;
  SInt32 pollCount;
  bool borrow;
  UInt32 startTime[2], endTime[2], elapsedNs[2];   /* 8-byte results of clock_get_uptime / absolutetime_to_nanoseconds: hi word first (Ghidra shows them as two adjacent locals) */
  
  elapsedNs[0] = 0;
  elapsedNs[1] = 0;
  if ((SInt32)(tag - M<SInt32>(self + 0x54)) < 1) {
    elapsedNs[1] = 0;
  }
  else {
    GH_clock_get_uptime(&startTime[0]);
    stampAddress = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x86c));
    currentStamp = loadWordByteReversed(stampAddress)
    ;
    M<UInt32>(self + 0x54) = currentStamp;
    pollCount = 0;
    if (0 < (SInt32)(tag - currentStamp)) {
      pollCount = 1;
      do {
        GH_assert_wait_timeout(&gl_assert_wait_timeout_event,0,100,1000);
        GH_thread_block(0);
        stampAddress = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x86c));
        currentStamp = loadWordByteReversed(stampAddress);
        M<UInt32>(self + 0x54) = currentStamp;
        if ((SInt32)(tag - currentStamp) < 1) break;
        pollCount = pollCount + 1;
      } while (pollCount != 0xc351);
    }
    GH_clock_get_uptime(&endTime[0]);
    borrow = endTime[1] < startTime[1];
    endTime[1] = endTime[1] - startTime[1];
    endTime[0] = endTime[0] - (startTime[0] + (UInt32)borrow);
    GH_absolutetime_to_nanoseconds(endTime[0],endTime[1],&elapsedNs[0]);
    M<SInt32>(self + 0x760) = M<SInt32>(self + 0x760) + elapsedNs[1];
    if (pollCount == 0xc351) {
      return -1;
    }
  }
  return elapsedNs[1];
}

/* real addr 0x254e0 */
IOReturn ATIRadeonX1000::waitForConsumedIDCTTimeStamp(UInt32 tag) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt32 currentStamp;
  SInt32 mmioBase;
  bool borrow;
  UInt32 startTime[2], endTime[2], elapsedNs[2];   /* 8-byte results of clock_get_uptime / absolutetime_to_nanoseconds: hi word first (Ghidra shows them as two adjacent locals) */
  
  elapsedNs[0] = 0;
  elapsedNs[1] = 0;
  if ((SInt32)(tag - M<SInt32>(self + 0x85c)) < 1) {
    elapsedNs[1] = 0;
  }
  else {
    GH_clock_get_uptime(&startTime[0]);
    iVar1 = M<SInt32>(self + 0x860);
    currentStamp = loadWordByteReversed(&M<UInt8>(iVar1 + 0x1fa8));
    M<UInt32>(self + 0x85c) = currentStamp;
    iVar1 = 0;
    if (0 < (SInt32)(tag - currentStamp)) {
      iVar1 = 1;
      do {
        GH_assert_wait_timeout(&gl_assert_wait_timeout_event,0,100,1000);
        GH_thread_block(0);
        mmioBase = M<SInt32>(self + 0x860);
        currentStamp = loadWordByteReversed(&M<UInt8>(mmioBase + 0x1fa8));
        M<UInt32>(self + 0x85c) = currentStamp;
        if ((SInt32)(tag - currentStamp) < 1) break;
        iVar1 = iVar1 + 1;
      } while (iVar1 != 0xc351);
    }
    GH_clock_get_uptime(&endTime[0]);
    borrow = endTime[1] < startTime[1];
    endTime[1] = endTime[1] - startTime[1];
    endTime[0] = endTime[0] - (startTime[0] + (UInt32)borrow);
    GH_absolutetime_to_nanoseconds(endTime[0],endTime[1],&elapsedNs[0]);
    M<SInt32>(self + 0x760) = M<SInt32>(self + 0x760) + elapsedNs[1];
    if (iVar1 == 0xc351) {
      return -1;
    }
  }
  return elapsedNs[1];
}

/* real addr 0x25960 */
UInt32 ATIRadeonX1000::sleepForTimeStamp(UInt32 tag) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *stampAddress;
  UInt32 currentStamp;
  SInt32 pollCount;
  bool borrow;
  UInt32 startTime[2], endTime[2], elapsedNs[2];   /* 8-byte results of clock_get_uptime / absolutetime_to_nanoseconds: hi word first (Ghidra shows them as two adjacent locals) */
  
  elapsedNs[0] = 0;
  elapsedNs[1] = 0;
  if ((SInt32)(tag - M<SInt32>(self + 0x54)) < 1) {
    elapsedNs[1] = 0;
  }
  else {
    GH_clock_get_uptime(&startTime[0]);
    stampAddress = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x86c));
    currentStamp = loadWordByteReversed(stampAddress)
    ;
    M<UInt32>(self + 0x54) = currentStamp;
    pollCount = 0;
    if (0 < (SInt32)(tag - currentStamp)) {
      pollCount = 1;
      do {
        GH_assert_wait_timeout(&gl_assert_wait_timeout_event,0,100,1000);
        GH_thread_block(0);
        stampAddress = (UInt8 *)(M<SInt32>(self + 0x864) + M<SInt32>(self + 0x86c));
        currentStamp = loadWordByteReversed(stampAddress);
        M<UInt32>(self + 0x54) = currentStamp;
        if ((SInt32)(tag - currentStamp) < 1) break;
        pollCount = pollCount + 1;
      } while (pollCount != 0xc351);
    }
    GH_clock_get_uptime(&endTime[0]);
    borrow = endTime[1] < startTime[1];
    endTime[1] = endTime[1] - startTime[1];
    endTime[0] = endTime[0] - (startTime[0] + (UInt32)borrow);
    GH_absolutetime_to_nanoseconds(endTime[0],endTime[1],&elapsedNs[0]);
    M<SInt32>(self + 0x760) = M<SInt32>(self + 0x760) + elapsedNs[1];
    if (pollCount == 0xc351) {
      return -1;
    }
  }
  return elapsedNs[1];
}
