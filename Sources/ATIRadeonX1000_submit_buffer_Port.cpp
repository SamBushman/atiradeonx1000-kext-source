/*
 * ATIRadeonX1000_submit_buffer_Port.cpp
 *
 * ATIRadeonX1000::submit_buffer (real addr 0x20980, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
 * Tools/port_fn.py); replaces the earlier hand-written body, which the callee/atomics comparison (Tools/callee_compare.py) showed had
 * dropped or simplified parts of the original.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIR5002DContext.h"
#include "../Headers/ATIR500DVDContext.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/GhidraExterns.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

extern "C" UInt32 GH_IOLog(...) asm("_IOLog");
extern "C" UInt32 GH_IOSleep(...) asm("_IOSleep");


/* real addr 0x20980 */
UInt32 ATIRadeonX1000::submit_buffer(UInt32*bufferStart, UInt32 gartOffset, UInt32 dwordCount) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 freeSpace;
  UInt32 stamp;
  SInt32 mmioBase;
  UInt32 writeIndex;
  SInt32 rptrOffset;
  UInt32 nextIndex;
  SInt32 vramBase;
  SInt32 spinCount;
  SInt32 cacheBytes;
  SInt32 ringPointerBase;
  SInt32 ringMemory;
  SInt32 submittedStamp;
  SInt32 waitTries;
  SInt32 flushOffset;
  UInt32 cacheLineSize;
  
  for (; (dwordCount & 7) != 0; dwordCount = dwordCount + 1) {
    bufferStart[dwordCount] = 0x80000000;
  }
  ringPointerBase = M<SInt32>(self + kIOATIR500Accelerator_ringPointerBase);
  rptrOffset = M<SInt32>(self + kIOATIR500Accelerator_ringWritePointerOffset);
  writeIndex = M<UInt32>(self + kIOATIR500Accelerator_ringIndex);
  waitTries = 0;
  if ((SInt32)((((loadWordByteReversed((UInt8 *)(ringPointerBase + rptrOffset)) & 0xffff) - writeIndex) -
             1 & 0x7ff) - 7) < 5) {
    do {
      waitTries = waitTries + 1;
      GH_IOSleep(1);
      ringPointerBase = M<SInt32>(self + kIOATIR500Accelerator_ringPointerBase);
      rptrOffset = M<SInt32>(self + kIOATIR500Accelerator_ringWritePointerOffset);
      writeIndex = M<UInt32>(self + kIOATIR500Accelerator_ringIndex);
      freeSpace = (((loadWordByteReversed((UInt8 *)(ringPointerBase + rptrOffset)) & 0xffff) - writeIndex)
               - 1 & 0x7ff) - 7;
      if (4 < freeSpace) goto accountAndFlush;
    } while (waitTries != 1000);
  }
  else {
accountAndFlush:
    M<UInt32>(self + kIOATIR500Accelerator_commandBytesPerSample) = dwordCount * 4 + M<SInt32>(self + kIOATIR500Accelerator_commandBytesPerSample);
    if ((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 0x80) == 0) {
      ppcSync();
      instructionSynchronize();
    }
    else {
      cacheLineSize = (UInt32)(UInt8)self[0x84];
      flushOffset = 0;
      cacheBytes = (dwordCount * 4 + ((UInt32)bufferStart & cacheLineSize - 1)) - cacheLineSize;
      if (0 < cacheBytes) {
        flushOffset = 0;
        do {
          dataCacheBlockStoreIndexed((-cacheLineSize & (UInt32)bufferStart), flushOffset);
          flushOffset = flushOffset + cacheLineSize;
        } while (flushOffset < cacheBytes);
      }
      ppcSync();
      instructionSynchronize();
      dataCacheBlockFlushIndexed((-cacheLineSize & (UInt32)bufferStart), flushOffset);
      ppcSync();
      instructionSynchronize();
      touchWordIndexed((-cacheLineSize & (UInt32)bufferStart), flushOffset);
      instructionSynchronize();
    }
    if (M<SInt32>(self + kIOATIR500Accelerator_transferMappedFlag) != 0) {
      this->submit_empty_buffer();
      ringPointerBase = M<SInt32>(self + kIOATIR500Accelerator_ringPointerBase);
      rptrOffset = M<SInt32>(self + kIOATIR500Accelerator_ringWritePointerOffset);
      writeIndex = M<UInt32>(self + kIOATIR500Accelerator_ringIndex);
    }
    vramBase = M<SInt32>(self + kIOATIR500Accelerator_vramSizeProgrammed);
    spinCount = 0;
    if (4 < (SInt32)((((loadWordByteReversed((UInt8 *)(ringPointerBase + rptrOffset)) & 0xffff) -
                   writeIndex) - 1 & 0x7ff) - 7)) {
emitStamp:
      if (M<SInt32>(self + kIOATIR500Accelerator_stampPageMemory) == 0) {
        ringMemory = M<SInt32>(self + kIOATIR500Accelerator_mainRingMemory);
        M<UInt32>(ringMemory + writeIndex * 4) = 0x57f;
        stamp = M<UInt32>(self + kIOATIR500Accelerator_submitStamp);
        nextIndex = writeIndex + 1 & 0x7ff;
        writeIndex = nextIndex + 1;
        M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = writeIndex;
        M<UInt32>(ringMemory + nextIndex * 4) = stamp;
        writeIndex = writeIndex & 0x7ff;
        M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = writeIndex;
      }
      else {
        ringMemory = M<SInt32>(self + kIOATIR500Accelerator_mainRingMemory);
        stamp = M<UInt32>(self + kIOATIR500Accelerator_submitStamp);
      }
      M<UInt32>(ringMemory + writeIndex * 4) = 0x101ce;
      writeIndex = writeIndex + 1 & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = writeIndex;
      M<UInt32>(ringMemory + writeIndex * 4) = gartOffset + vramBase & 0xfffffffc;
      writeIndex = writeIndex + 1 & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = writeIndex;
      M<UInt32>(ringMemory + writeIndex * 4) = dwordCount & 0x7fffff;
      writeIndex = writeIndex + 1 & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = writeIndex;
      M<UInt32>(ringMemory + writeIndex * 4) = 0x578;
      writeIndex = writeIndex + 1 & 0x7ff;
      nextIndex = writeIndex + 1;
      M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = nextIndex;
      M<UInt32>(ringMemory + writeIndex * 4) = stamp;
      M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = nextIndex & 0x7ff;
      this->submit_ring_data();
      if (M<SInt32>(self + kIOATIR500Accelerator_stampPageMemory) != 0) {
        M<UInt32>(M<SInt32>(self + kIOATIR500Accelerator_stampPageMemory) + 0x20) = M<UInt32>(self + kIOATIR500Accelerator_submitStamp);
      }
      submittedStamp = M<SInt32>(self + kIOATIR500Accelerator_submitStamp);
      M<SInt32>(self + kIOATIR500Accelerator_submitStamp) = submittedStamp + 1;
      return submittedStamp;
    }
    do {
      spinCount = spinCount + 1;
      GH_IOSleep(1);
      writeIndex = M<UInt32>(self + kIOATIR500Accelerator_ringIndex);
      freeSpace = (((loadWordByteReversed((UInt8 *)(M<SInt32>(self + kIOATIR500Accelerator_ringPointerBase) + M<SInt32>(self + kIOATIR500Accelerator_ringWritePointerOffset))) & 0xffff) - writeIndex)
               - 1 & 0x7ff) - 7;
      if (4 < freeSpace) goto emitStamp;
    } while (spinCount != 1000);
  }
  mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  GH_IOLog("ATIRadeon::wait_for_rb_space: Overflowed block waiting for FIFO space.   Have %lu, need %lu. RBBM_STATUS 0x%08x\n"
               ,freeSpace,5,loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)));
  this->DumpASICHangState();
  return *(SInt32 *)(self + kIOATIR500Accelerator_submitStamp) + -1;
}
