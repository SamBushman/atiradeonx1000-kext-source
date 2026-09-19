/*
 * ATIRadeonX1000_SubmitBufferRetired.cpp
 *
 * RESOLVED (ledger pass): submit_buffer_retired.
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


/* real addr 0x20700 */
UInt32 ATIRadeonX1000::submit_buffer_retired(UInt32 *param_1, UInt32 param_2, UInt32 param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    static UInt32 u32Dummy;

  SInt32 iVar1;
  SInt32 iVar2;
  UInt32 uVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  
  M<UInt32>(self + 0x6fc) = param_3 * 4 + M<SInt32>(self + 0x6fc);
  if ((M<UInt32>(self + 0x98) & 0x80) == 0) {
    ppcSync();
    instructionSynchronize();
  }
  else {
    uVar4 = (UInt32)(UInt8)self[0x84];
    iVar1 = 0;
    iVar2 = (param_3 * 4 + ((UInt32)param_1 & uVar4 - 1)) - uVar4;
    if (0 < iVar2) {
      iVar1 = 0;
      do {
        dataCacheBlockStore((-uVar4 & (UInt32)param_1) + iVar1);
        iVar1 = iVar1 + uVar4;
      } while (iVar1 < iVar2);
    }
    ppcSync();
    instructionSynchronize();
    dataCacheBlockFlush((-uVar4 & (UInt32)param_1) + iVar1);
    ppcSync();
    instructionSynchronize();
    instructionSynchronize();
  }
  iVar1 = M<SInt32>(self + 0x8a4);
  iVar5 = 0;
  iVar2 = M<SInt32>(self + 0x914);
  while (uVar4 = (((UInt32)CONCAT11(((UInt8 *)(M<SInt32>(self + 0x90c) + M<SInt32>(self + 0x910)))
                                  [1],*(UInt8 *)
                                       (M<SInt32>(self + 0x90c) + M<SInt32>(self + 0x910))) - iVar2) -
                  1 & 0x7ff) - 7, uVar4 < 8) {
    iVar5 = iVar5 + 1;
    if (iVar5 == 0xf4241) goto LAB_000208e8;
    do {
      u32Dummy =
           u32Dummy + 1;
    } while ((u32Dummy & 0xf) !=
             0);
  }
  if (iVar5 == 0xf4241) {
LAB_000208e8:
    iVar1 = M<SInt32>(self + 0x860);
    GH_IOLog("ATIRadeon::submit_buffer: Overflowed block waiting for FIFO space.   Have %lu, need %lu. RBBM_STATUS 0x%08x\n"
                 ,uVar4,8,(UInt32)M<UInt8>(iVar1 + 0xe43) << 0x18 |
                          (UInt32)M<UInt8>(iVar1 + 0xe42) << 0x10 |
                          (UInt32)M<UInt8>(iVar1 + 0xe41) << 8 | (UInt32)M<UInt8>(iVar1 + 0xe40));
    ((ATIRadeonX1000 *)(self))->DumpASICHangState();
    iVar1 = M<SInt32>(self + 0x850) + -1;
  }
  else {
    iVar5 = M<SInt32>(self + 0x900);
    M<UInt32>(iVar5 + iVar2 * 4) = 0x101ce;
    uVar4 = iVar2 + 1U & 0x7ff;
    M<UInt32>(self + 0x914) = uVar4;
    M<UInt32>(iVar5 + uVar4 * 4) = param_2 + iVar1 & 0xfffffffc;
    uVar4 = uVar4 + 1 & 0x7ff;
    M<UInt32>(self + 0x914) = uVar4;
    M<UInt32>(iVar5 + uVar4 * 4) = param_3 & 0x7fffff;
    uVar4 = uVar4 + 1 & 0x7ff;
    M<UInt32>(self + 0x914) = uVar4;
    M<UInt32>(iVar5 + uVar4 * 4) = 0x394;
    uVar4 = uVar4 + 1 & 0x7ff;
    M<UInt32>(self + 0x914) = uVar4;
    M<UInt32>(iVar5 + uVar4 * 4) = 1;
    uVar4 = uVar4 + 1 & 0x7ff;
    M<UInt32>(self + 0x914) = uVar4;
    M<UInt32>(iVar5 + uVar4 * 4) = 0x579;
    uVar4 = uVar4 + 1 & 0x7ff;
    uVar3 = uVar4 + 1;
    M<UInt32>(self + 0x914) = uVar3;
    M<UInt32>(iVar5 + uVar4 * 4) = M<UInt32>(self + 0x850);
    uVar3 = uVar3 & 0x7ff;
    M<UInt32>(self + 0x914) = uVar3;
    M<UInt32>(iVar5 + uVar3 * 4) = 0x80000000;
    M<UInt32>(self + 0x914) = uVar3 + 1 & 0x7ff;
    ((ATIRadeonX1000 *)(self))->submit_ring_data();
    iVar1 = M<SInt32>(self + 0x850);
    M<SInt32>(self + 0x850) = iVar1 + 1;
  }
  return iVar1;
}

