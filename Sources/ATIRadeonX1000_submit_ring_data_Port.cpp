/*
 * ATIRadeonX1000_submit_ring_data_Port.cpp
 *
 * ATIRadeonX1000::submit_ring_data (real addr 0x1f030, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x1f030 */
void ATIRadeonX1000::submit_ring_data() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  UInt32 headLineBase;
  UInt32 submittedIndex;
  UInt32 writeIndex;
  UInt32 uVar3;
  UInt32 rangeStart;
  UInt32 nextIndex;
  SInt32 flushEnd;
  UInt32 uVar5;
  UInt32 ringBase;
  UInt32 cacheLine;
  SInt32 iVar6;
  SInt32 flushOffset;
  SInt32 ringPtr;
  UInt32 uVar7;
  UInt32 lineSize;
  UInt32 lineBase;
  UInt32 tailLineBase;
  
  writeIndex = M<UInt32>(self + kIOATIR500Accelerator_ringIndex);
  submittedIndex = M<UInt32>(self + kIOATIR500Accelerator_mainRingCursor);
  if (writeIndex != submittedIndex) {
    if ((writeIndex & 7) != 0) {
      ringPtr = M<SInt32>(self + kIOATIR500Accelerator_mainRingMemory);
      do {
        nextIndex = writeIndex + 1;
        M<UInt32>(ringPtr + writeIndex * 4) = 0x80000000;
        writeIndex = nextIndex & 0x7ff;
      } while ((nextIndex & 7) != 0);
      M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = writeIndex;
    }
    if ((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 0x80) == 0) {
      ppcSync();
      instructionSynchronize();
    }
    else if (submittedIndex < writeIndex) {
      cacheLine = (UInt32)(UInt8)self[0x84];
      rangeStart = submittedIndex * 4 + M<SInt32>(self + kIOATIR500Accelerator_mainRingMemory);
      lineBase = -cacheLine & rangeStart;
      flushOffset = 0;
      flushEnd = ((writeIndex - submittedIndex) * 4 + (rangeStart & cacheLine - 1)) - cacheLine;
      if (0 < flushEnd) {
        do {
          dataCacheBlockStore(lineBase + flushOffset);
          flushOffset = flushOffset + cacheLine;
        } while (flushOffset < flushEnd);
      }
      ppcSync();
      instructionSynchronize();
      dataCacheBlockFlush(lineBase + flushOffset);
      ppcSync();
      instructionSynchronize();
      instructionSynchronize();
    }
    else {
      lineSize = (UInt32)(UInt8)self[0x84];
      ringBase = M<UInt32>(self + kIOATIR500Accelerator_mainRingMemory);
      rangeStart = ringBase + submittedIndex * 4;
      tailLineBase = -lineSize & rangeStart;
      flushOffset = 0;
      flushEnd = ((0x800 - submittedIndex) * 4 + (rangeStart & lineSize - 1)) - lineSize;
      if (0 < flushEnd) {
        do {
          dataCacheBlockStore(tailLineBase + flushOffset);
          flushOffset = flushOffset + lineSize;
        } while (flushOffset < flushEnd);
      }
      ppcSync();
      instructionSynchronize();
      dataCacheBlockFlush(tailLineBase + flushOffset);
      ppcSync();
      instructionSynchronize();
      instructionSynchronize();
      headLineBase = -lineSize & ringBase;
      flushOffset = 0;
      flushEnd = (writeIndex * 4 + (lineSize - 1 & ringBase)) - lineSize;
      if (0 < flushEnd) {
        do {
          dataCacheBlockStore(headLineBase + flushOffset);
          flushOffset = flushOffset + lineSize;
        } while (flushOffset < flushEnd);
      }
      ppcSync();
      instructionSynchronize();
      dataCacheBlockFlush(headLineBase + flushOffset);
      ppcSync();
      instructionSynchronize();
      instructionSynchronize();
    }
    M<UInt32>(M<SInt32>(self + kIOATIR500Accelerator_mmioBase) + 0x714) = writeIndex << 0x18 | (writeIndex & 0x700) << 8;
    enforceInOrderExecutionIO();
    M<UInt32>(self + kIOATIR500Accelerator_mainRingCursor) = writeIndex;
    return;
  }
  return;
}
