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
UInt32 ATIRadeonX1000::submit_buffer_retired(UInt32 *bufferStart, UInt32 gartOffset, UInt32 dwordCount) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    static UInt32 u32Dummy;

  SInt32 registers;
  SInt32 flushOffset;
  SInt32 writeIndex;
  SInt32 flushEnd;
  UInt32 nextIndex;
  UInt32 ringIndex;
  UInt32 freeDwords;
  UInt32 cacheLine;
  SInt32 ringBase;
  SInt32 spinCount;
  SInt32 rptrBase;
  SInt32 rptrOffset;
  SInt32 gartBase;
  SInt32 stamp;
  
  M<UInt32>(self + kIOATIR500Accelerator_commandBytesPerSample) = dwordCount * 4 + M<SInt32>(self + kIOATIR500Accelerator_commandBytesPerSample);
  if ((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 0x80) == 0) {
    ppcSync();
    instructionSynchronize();
  }
  else {
    cacheLine = (UInt32)(UInt8)self[0x84];
    flushOffset = 0;
    flushEnd = (dwordCount * 4 + ((UInt32)bufferStart & cacheLine - 1)) - cacheLine;
    if (0 < flushEnd) {
      flushOffset = 0;
      do {
        dataCacheBlockStoreIndexed((-cacheLine & (UInt32)bufferStart), flushOffset);
        flushOffset = flushOffset + cacheLine;
      } while (flushOffset < flushEnd);
    }
    ppcSync();
    instructionSynchronize();
    dataCacheBlockFlushIndexed((-cacheLine & (UInt32)bufferStart), flushOffset);
    ppcSync();
    instructionSynchronize();
    touchWordIndexed((-cacheLine & (UInt32)bufferStart), flushOffset);
    instructionSynchronize();
  }
  gartBase = M<SInt32>(self + kIOATIR500Accelerator_vramSizeProgrammed);
  spinCount = 0;
  writeIndex = M<SInt32>(self + kIOATIR500Accelerator_ringIndex);
  rptrBase = M<SInt32>(self + kIOATIR500Accelerator_ringPointerBase);
  rptrOffset = M<SInt32>(self + kIOATIR500Accelerator_ringWritePointerOffset);
  while (freeDwords = ((loadWordByteReversedIndexed(rptrBase, rptrOffset) - writeIndex) - 1 & 0x7ff) - 7, freeDwords < 8) {
    spinCount = spinCount + 1;
    if (spinCount == 0xf4241) goto reportFifoOverflow;
    do {
      u32Dummy =
           u32Dummy + 1;
    } while ((u32Dummy & 0xf) !=
             0);
  }
  if (spinCount == 0xf4241) {
reportFifoOverflow:
    registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
    GH_IOLog("ATIRadeon::submit_buffer: Overflowed block waiting for FIFO space.   Have %lu, need %lu. RBBM_STATUS 0x%08x\n"
                 ,freeDwords,8,loadWordByteReversed(&M<UInt8>(registers + 0xe40)));
    ((ATIRadeonX1000 *)(self))->DumpASICHangState();
    stamp = M<SInt32>(self + kIOATIR500Accelerator_retiredStampCounter) + -1;
  }
  else {
    ringBase = M<SInt32>(self + kIOATIR500Accelerator_mainRingMemory);
    M<UInt32>(ringBase + writeIndex * 4) = 0x101ce;
    ringIndex = writeIndex + 1U & 0x7ff;
    M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = ringIndex;
    M<UInt32>(ringBase + ringIndex * 4) = gartOffset + gartBase & 0xfffffffc;
    ringIndex = ringIndex + 1 & 0x7ff;
    M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = ringIndex;
    M<UInt32>(ringBase + ringIndex * 4) = dwordCount & 0x7fffff;
    ringIndex = ringIndex + 1 & 0x7ff;
    M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = ringIndex;
    M<UInt32>(ringBase + ringIndex * 4) = 0x394;
    ringIndex = ringIndex + 1 & 0x7ff;
    M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = ringIndex;
    M<UInt32>(ringBase + ringIndex * 4) = 1;
    ringIndex = ringIndex + 1 & 0x7ff;
    M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = ringIndex;
    M<UInt32>(ringBase + ringIndex * 4) = 0x579;
    ringIndex = ringIndex + 1 & 0x7ff;
    nextIndex = ringIndex + 1;
    M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = nextIndex;
    M<UInt32>(ringBase + ringIndex * 4) = M<UInt32>(self + kIOATIR500Accelerator_retiredStampCounter);
    nextIndex = nextIndex & 0x7ff;
    M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = nextIndex;
    M<UInt32>(ringBase + nextIndex * 4) = 0x80000000;
    M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = nextIndex + 1 & 0x7ff;
    ((ATIRadeonX1000 *)(self))->submit_ring_data();
    stamp = M<SInt32>(self + kIOATIR500Accelerator_retiredStampCounter);
    M<SInt32>(self + kIOATIR500Accelerator_retiredStampCounter) = stamp + 1;
  }
  return stamp;
}

