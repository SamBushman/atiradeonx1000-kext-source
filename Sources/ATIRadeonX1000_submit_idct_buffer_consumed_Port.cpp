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

  SInt32 iVar1;
  SInt32 stamp;
  SInt32 gartBase;
  SInt32 bufferFlushEnd;
  UInt32 uVar2;
  UInt32 uVar3;
  UInt32 ringIndex;
  UInt32 cacheLine;
  UInt32 uVar4;
  SInt32 iVar5;
  SInt32 writeIndex;
  SInt32 iVar6;
  SInt32 ringBase;
  SInt32 spinCount;
  UInt32 uVar7;
  UInt32 ringAddress;
  UInt32 nextIndex;
  SInt32 iVar8;
  SInt32 ringFlushEnd;
  SInt32 startIndex;
  SInt32 flushOffset;
  
  startIndex = M<SInt32>(self + 0x930);
  if ((M<UInt32>(self + 0x98) & 0x80) == 0) {
    ppcSync();
    instructionSynchronize();
  }
  else {
    cacheLine = (UInt32)(UInt8)self[0x84];
    flushOffset = 0;
    bufferFlushEnd = (M<SInt32>(infoBytes + 0x10) * 4 + ((UInt32)buffer & cacheLine - 1)) - cacheLine;
    if (0 < bufferFlushEnd) {
      do {
        dataCacheBlockStore((-cacheLine & (UInt32)buffer) + flushOffset);
        flushOffset = flushOffset + cacheLine;
      } while (flushOffset < bufferFlushEnd);
    }
    ppcSync();
    instructionSynchronize();
    dataCacheBlockFlush((-cacheLine & (UInt32)buffer) + flushOffset);
    ppcSync();
    instructionSynchronize();
    instructionSynchronize();
  }
  if (M<SInt32>(self + 0x8a0) != 0) {
    this->submit_empty_buffer();
  }
  gartBase = M<SInt32>(self + 0x8a4);
  if (M<SInt32>(self + 0x8bc) != 0) {
    writeIndex = M<SInt32>(self + 0x930);
    spinCount = 0;
    while ((((UInt32)(loadWordByteReversed((UInt8 *)(M<SInt32>(self + 0x928) + M<SInt32>(self + 0x92c))) & 0xffff) -
            writeIndex) - 1 & 0x7ff) < 0x20) {
      spinCount = spinCount + 1;
      if (spinCount == 0xf4241) goto LAB_0001ef58;
      do {
        u32Dummy =
             u32Dummy +
             1;
      } while ((u32Dummy
               & 0xf) != 0);
    }
    if (spinCount != 0xf4241) {
      ringBase = M<SInt32>(self + 0x91c);
      M<UInt32>(ringBase + writeIndex * 4) = 0x80001fe0;
      ringIndex = writeIndex + 1U & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + 0x930) = nextIndex;
      M<UInt32>(ringBase + ringIndex * 4) = M<UInt32>(infoBytes + 0x2c);
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + 0x930) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = 0x80001fe4;
      ringIndex = nextIndex + 1 & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + 0x930) = nextIndex;
      M<UInt32>(ringBase + ringIndex * 4) = M<UInt32>(infoBytes + 0x30);
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + 0x930) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = 0x80001fec;
      ringIndex = nextIndex + 1 & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + 0x930) = nextIndex;
      M<UInt32>(ringBase + ringIndex * 4) = M<UInt32>(infoBytes + 0x1c);
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + 0x930) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = 0x80001ff0;
      ringIndex = nextIndex + 1 & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + 0x930) = nextIndex;
      M<UInt32>(ringBase + ringIndex * 4) = M<UInt32>(infoBytes + 0x20);
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + 0x930) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = 0x80001f8c;
      ringIndex = nextIndex + 1 & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + 0x930) = nextIndex;
      M<UInt32>(ringBase + ringIndex * 4) = M<UInt32>(infoBytes + 0x10);
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + 0x930) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = 0x80001ffc;
      ringIndex = nextIndex + 1 & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + 0x930) = nextIndex;
      M<UInt32>(ringBase + ringIndex * 4) = M<UInt32>(infoBytes + 0x24);
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + 0x930) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = 0x80001ff8;
      ringIndex = nextIndex + 1 & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + 0x930) = nextIndex;
      M<UInt32>(ringBase + ringIndex * 4) = M<UInt32>(infoBytes + 0x28);
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + 0x930) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = gartOffset + gartBase >> 1 & 0x7ffffff0;
      ringIndex = nextIndex + 1 & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + 0x930) = nextIndex;
      M<UInt32>(ringBase + ringIndex * 4) = M<UInt32>(infoBytes + 0x14);
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + 0x930) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = 0x80001fa8;
      stamp = M<SInt32>(self + 0x854);
      ringIndex = nextIndex + 1 & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + 0x930) = nextIndex;
      M<SInt32>(ringBase + ringIndex * 4) = stamp;
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + 0x930) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = 0x80001fac;
      ringIndex = nextIndex + 1 & 0x7ff;
      nextIndex = ringIndex + 1;
      M<UInt32>(self + 0x930) = nextIndex;
      M<UInt32>(ringBase + ringIndex * 4) = M<UInt32>(infoBytes + 0x18);
      nextIndex = nextIndex & 0x7ff;
      M<UInt32>(self + 0x930) = nextIndex;
      M<UInt32>(ringBase + nextIndex * 4) = 0x80001fb4;
      ringIndex = nextIndex + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0x80001fb4;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0x80001fb4;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0x80001fb4;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0x80001fb4;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0x80001fb4;
      ringIndex = ringIndex + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = ringIndex;
      M<UInt32>(ringBase + ringIndex * 4) = 0;
      ringIndex = ringIndex + 1;
      M<UInt32>(self + 0x930) = ringIndex & 0x7ff;
      if ((M<UInt32>(self + 0x98) & 0x80) == 0) {
        ppcSync();
        instructionSynchronize();
      }
      else {
        uVar4 = (UInt32)(UInt8)self[0x84];
        flushOffset = 0;
        ringAddress = startIndex * 4 + ringBase;
        uVar2 = -uVar4 & ringAddress;
        ringFlushEnd = ((ringAddress & uVar4 - 1) + 0x80) - uVar4;
        if (0 < ringFlushEnd) {
          do {
            dataCacheBlockStore(uVar2 + flushOffset);
            flushOffset = flushOffset + uVar4;
          } while (flushOffset < ringFlushEnd);
        }
        ppcSync();
        instructionSynchronize();
        dataCacheBlockFlush(uVar2 + flushOffset);
        ppcSync();
        instructionSynchronize();
        instructionSynchronize();
      }
      M<UInt32>(M<SInt32>(self + 0x860) + 0x1fa0) = ringIndex * 0x1000000 | (ringIndex & 0x700) << 8;
      enforceInOrderExecutionIO();
      M<SInt32>(self + 0x854) = stamp + 1;
      return stamp;
    }
LAB_0001ef58:
    this->DumpASICHangState();
  }
  return *(SInt32 *)(self + 0x854) + -1;
}
