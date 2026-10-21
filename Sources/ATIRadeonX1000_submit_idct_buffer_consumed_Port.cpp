/*
 * ATIRadeonX1000_submit_idct_buffer_consumed_Port.cpp
 *
 * ATIRadeonX1000::submit_idct_buffer_consumed (real addr 0x1eb30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x1eb30 */
UInt32 ATIRadeonX1000::submit_idct_buffer_consumed(UInt32*buffer, UInt32 gartOffset, sATIDVDIDCTInfo *info) {
    static UInt32 u32Dummy;   /* real function-local static: submit_idct_buffer_consumed(unsigned long*, unsigned long, sATIDVDIDCTInfo*)::u32Dummy */
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *infoBytes = reinterpret_cast<UInt8 *>(info);

  SInt32 stamp;
  SInt32 gartBase;
  SInt32 bufferFlushEnd;
  UInt32 ringLineStart;
  UInt32 ringIndex;
  UInt32 cacheLine;
  UInt32 ringCacheLine;
  SInt32 writeIndex;
  SInt32 ringBase;
  SInt32 spinCount;
  SInt32 rptrBase;
  SInt32 rptrOffset;
  UInt32 ringAddress;
  UInt32 nextIndex;
  SInt32 ringFlushEnd;
  SInt32 startIndex;
  SInt32 flushOffset;
  
  startIndex = M<SInt32>(self + kIOATIR500Accelerator_idctRingCursor);
  if ((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 0x80) == 0) {
    ppcSync();
    instructionSynchronize();
  }
  else {
    cacheLine = (UInt32)(UInt8)self[0x84];
    flushOffset = 0;
    bufferFlushEnd = (M<SInt32>(infoBytes + 0x10) * 4 + ((UInt32)buffer & cacheLine - 1)) - cacheLine;
    if (0 < bufferFlushEnd) {
      do {
        dataCacheBlockStoreIndexed((-cacheLine & (UInt32)buffer), flushOffset);
        flushOffset = flushOffset + cacheLine;
      } while (flushOffset < bufferFlushEnd);
    }
    ppcSync();
    instructionSynchronize();
    dataCacheBlockFlushIndexed((-cacheLine & (UInt32)buffer), flushOffset);
    ppcSync();
    instructionSynchronize();
    touchWordIndexed((-cacheLine & (UInt32)buffer), flushOffset);
    instructionSynchronize();
  }
  if (M<SInt32>(self + kIOATIR500Accelerator_transferMappedFlag) != 0) {
    this->submit_empty_buffer();
  }
  gartBase = M<SInt32>(self + kIOATIR500Accelerator_vramSizeProgrammed);
  if (M<SInt32>(self + kIOATIR500Accelerator_xdctEngineRunning) != 0) {
    writeIndex = M<SInt32>(self + kIOATIR500Accelerator_idctRingCursor);
    spinCount = 0;
    rptrBase = M<SInt32>(self + kIOATIR500Accelerator_idctPointerBase);
    rptrOffset = M<SInt32>(self + kIOATIR500Accelerator_idctPointerOffset);
    while (((loadWordByteReversedIndexed(rptrBase, rptrOffset) - writeIndex) - 1 & 0x7ff) < 0x20) {
      spinCount = spinCount + 1;
      if (spinCount == 0xf4241) goto dumpHangState;
      do {
        u32Dummy =
             u32Dummy +
             1;
      } while ((u32Dummy
               & 0xf) != 0);
    }
    if (spinCount != 0xf4241) {
      ringBase = M<SInt32>(self + kIOATIR500Accelerator_idctRingMemory);
      M<UInt32>(ringBase + writeIndex * 4) = 0x80001fe0;
      ringIndex = writeIndex + 1U & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<UInt32>(ringBase + ringIndex * 4) = M<UInt32>(infoBytes + 0x2c);
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = 0x80001fe4;
      ringIndex = nextIndex + 1 & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<UInt32>(ringBase + ringIndex * 4) = M<UInt32>(infoBytes + 0x30);
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = 0x80001fec;
      ringIndex = nextIndex + 1 & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<UInt32>(ringBase + ringIndex * 4) = M<UInt32>(infoBytes + 0x1c);
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = 0x80001ff0;
      ringIndex = nextIndex + 1 & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<UInt32>(ringBase + ringIndex * 4) = M<UInt32>(infoBytes + 0x20);
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = 0x80001f8c;
      ringIndex = nextIndex + 1 & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<UInt32>(ringBase + ringIndex * 4) = M<UInt32>(infoBytes + 0x10);
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = 0x80001ffc;
      ringIndex = nextIndex + 1 & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<UInt32>(ringBase + ringIndex * 4) = M<UInt32>(infoBytes + 0x24);
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = 0x80001ff8;
      ringIndex = nextIndex + 1 & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<UInt32>(ringBase + ringIndex * 4) = M<UInt32>(infoBytes + 0x28);
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = gartOffset + gartBase >> 1 & 0x7ffffff0;
      ringIndex = nextIndex + 1 & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<UInt32>(ringBase + ringIndex * 4) = M<UInt32>(infoBytes + 0x14);
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = 0x80001fa8;
      stamp = M<SInt32>(self + kIOATIR500Accelerator_idctSubmitBaseCounter);
      ringIndex = nextIndex + 1 & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<SInt32>(ringBase + ringIndex * 4) = stamp;
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = 0x80001fac;
      ringIndex = nextIndex + 1 & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<UInt32>(ringBase + ringIndex * 4) = M<UInt32>(infoBytes + 0x18);
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = 0x80001fb4;
      ringIndex = nextIndex + 1 & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0x80001fb4;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0x80001fb4;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0x80001fb4;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0x80001fb4;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0x80001fb4;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0;
      ringIndex = ringIndex + 1;
      M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = ringIndex & 0x7ff;
      if ((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 0x80) == 0) {
        ppcSync();
        instructionSynchronize();
      }
      else {
        ringCacheLine = (UInt32)(UInt8)self[0x84];
        flushOffset = 0;
        ringAddress = startIndex * 4 + ringBase;
        ringLineStart = -ringCacheLine & ringAddress;
        ringFlushEnd = ((ringAddress & ringCacheLine - 1) + 0x80) - ringCacheLine;
        if (0 < ringFlushEnd) {
          do {
            dataCacheBlockStoreIndexed(ringLineStart, flushOffset);
            flushOffset = flushOffset + ringCacheLine;
          } while (flushOffset < ringFlushEnd);
        }
        ppcSync();
        instructionSynchronize();
        dataCacheBlockFlushIndexed(ringLineStart, flushOffset);
        ppcSync();
        instructionSynchronize();
        touchWordIndexed(ringLineStart, flushOffset);
        instructionSynchronize();
      }
      storeWordByteReversed(&M<UInt8>(M<SInt32>(self + kIOATIR500Accelerator_mmioBase) + 0x1fa0), ringIndex & 0x7ff);
      enforceInOrderExecutionIO();
      M<SInt32>(self + kIOATIR500Accelerator_idctSubmitBaseCounter) = stamp + 1;
      return stamp;
    }
dumpHangState:
    this->DumpASICHangState();
  }
  return *(SInt32 *)(self + kIOATIR500Accelerator_idctSubmitBaseCounter) + -1;
}
