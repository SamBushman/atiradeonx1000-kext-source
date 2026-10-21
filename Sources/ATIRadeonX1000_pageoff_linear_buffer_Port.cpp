/*
 * ATIRadeonX1000_pageoff_linear_buffer_Port.cpp
 *
 * ATIRadeonX1000::pageoff_linear_buffer (real addr 0x217a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x217a0 */
UInt32 ATIRadeonX1000::pageoff_linear_buffer(VendorTextureBuffer *texture, ATITextureBufferHeader *hwInfo) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);
    UInt8 *hwInfoBytes = reinterpret_cast<UInt8 *>(hwInfo);

  SInt16 mapCount;
  int vramBase;
  int burstsLeft;
  int textureInfo;
  int gartOffsetInBurst;
  UInt32 stamp;
  UInt8 *record;
  UInt32 wordCount;
  int vramWordIndex;
  int gartWordIndex;
  UInt8 type;
  unsigned int burstIndex;
  int vramStride;
  int vramOffsetInBurst;
  int gartStride;
  UInt8 *innerBuffer;
  int gartOffset;
  int vramOffset;
  int mapResult;
  int bufferGartOffset;
  int size;
  int waitStampResult;
  int waitTimeBefore;
  
  if (textureBytes[0x20] == 0x3) {
    type = 0x3;
    if (M<int>(textureBytes + 4) == 0) {
      /* #153: real disassembly (addr 0x217d8) confirms this first 0x5a8 call explicitly loads
       * only r3 (this) - r4 (textureBytes) is unclobbered since function entry, so it's still the real
       * buffer value here. The retry at this function's second 0x5a8 call (below) DOES reload r4
       * explicitly in the real binary, because the intervening freeToAllocGART call clobbers it -
       * that one was already correctly ported with the textureBytes argument; only this first, bare
       * occurrence was missing it. */
      mapResult = VCALL(M<int>(self), 0x5a8)(self, textureBytes);
      if ((mapResult == 0) &&
         (mapResult = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                             (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                             (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),
                             (VendorTransferBuffer *)((UInt8 *)textureBytes)), mapResult == 0)) {
        VCALL(M<int>(self), 0x54c)(self,M<int>(self + kIOATIR500Accelerator_submitStamp) + -1);
        mapResult = VCALL(M<int>(self), 0x5a8)(self,textureBytes);
        if ((mapResult == 0) &&
           (mapResult = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                               (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                               (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),
                               (VendorTransferBuffer *)((UInt8 *)textureBytes)), mapResult == 0)) {
          return 0;
        }
      }
      type = textureBytes[0x20];
    }
  }
  else {
    if (textureBytes[0x20] != 0x7) {
      return 0;
    }
    innerBuffer = M<UInt8 *>(textureBytes + 0x58);
    if (((M<int>(innerBuffer + 4) == 0) &&
        (mapResult = VCALL(M<int>(self), 0x5a8)(self,innerBuffer), mapResult == 0)) &&
       (mapResult = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                           (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                           (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),(VendorTransferBuffer *)(innerBuffer)), mapResult == 0)) {
      VCALL(M<int>(self), 0x54c)(self,M<int>(self + kIOATIR500Accelerator_submitStamp) + -1);
      mapResult = VCALL(M<int>(self), 0x5a8)(self,innerBuffer);
      if ((mapResult == 0) &&
         (mapResult = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                             (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                             (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),(VendorTransferBuffer *)(innerBuffer)), mapResult == 0)) {
        return 0;
      }
    }
    bufferGartOffset = M<int>(textureBytes + 4);
    mapCount = M<SInt16>(innerBuffer + 0xe) + 1;
    storeHalf(&M<UInt16>(innerBuffer + 0xe), mapCount);
    if (bufferGartOffset == 0) {
      mapResult = VCALL(M<int>(self), 0x5a8)(self,textureBytes);
      if ((mapResult == 0) &&
         (mapResult = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                             (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                             (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),
                             (VendorTransferBuffer *)((UInt8 *)textureBytes)), mapResult == 0)) {
        VCALL(M<int>(self), 0x54c)(self,M<int>(self + kIOATIR500Accelerator_submitStamp) + -1);
        mapResult = VCALL(M<int>(self), 0x5a8)(self,textureBytes);
        if ((mapResult == 0) &&
           (mapResult = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                               (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                               (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),
                               (VendorTransferBuffer *)((UInt8 *)textureBytes)), mapResult == 0)) {
          storeHalf(&M<UInt16>(innerBuffer + 0xe), M<SInt16>(innerBuffer + 0xe) + -1);
          return 0;
        }
      }
      mapCount = M<SInt16>(innerBuffer + 0xe);
    }
    type = textureBytes[0x20];
    storeHalf(&M<UInt16>(innerBuffer + 0xe), mapCount + -1);
  }
  if (type == 0x7) {
    size = M<int>(textureBytes + 0x50);
    gartOffset = M<int>(M<int>(textureBytes + 0x58) + 4);
  }
  else {
    gartOffset = M<int>(textureBytes + 4);
    size = M<int>(textureBytes + 0x50);
  }
  waitTimeBefore = M<int>(self + kIOATIR500Accelerator_texturePageOutWaitTime);
  waitStampResult = VCALL(M<int>(self), 0x54c)(self,M<UInt32>(M<int>(textureBytes + 0x14) + 0xc));
  vramBase = M<int>(self + kIOATIR500Accelerator_vramSizeProgrammed);
  record = hwInfoBytes + 0xa00;
  M<int>(self + kIOATIR500Accelerator_texturePageOutWaitTime) = waitTimeBefore + waitStampResult;
  burstIndex = (unsigned int)M<UInt16>(hwInfoBytes + 0x40);
  gartOffsetInBurst = M<int>(hwInfoBytes + 0x44);
  vramOffsetInBurst = M<int>(hwInfoBytes + 0x48);
  vramWordIndex = burstIndex + 4;
  gartWordIndex = burstIndex + 7;
  M<UInt32>(record + burstIndex * 4) = 0x80000000;
  vramOffset = M<int>(textureBytes + 0x48);
  M<int>(record + vramWordIndex * 4) = vramOffsetInBurst + vramOffset;
  M<int>(record + gartWordIndex * 4) = gartOffset + vramBase + gartOffsetInBurst;
  if (1 < M<UInt16>(hwInfoBytes + 0x42)) {
    burstsLeft = M<UInt16>(hwInfoBytes + 0x42) - 1;
    vramStride = M<int>(hwInfoBytes + 0x50);
    gartStride = M<int>(hwInfoBytes + 0x4c);
    do {
      burstIndex = burstIndex + 0x12;
      vramWordIndex = vramWordIndex + 0x12;
      gartWordIndex = gartWordIndex + 0x12;
      gartOffsetInBurst = gartOffsetInBurst + gartStride;
      vramOffsetInBurst = vramOffsetInBurst + vramStride;
      M<UInt32>(record + burstIndex * 4) = 0x80000000;
      M<int>(record + vramWordIndex * 4) = vramOffsetInBurst + vramOffset;
      M<int>(record + gartWordIndex * 4) = gartOffset + vramBase + gartOffsetInBurst;
      burstsLeft = burstsLeft + -1;
    } while (burstsLeft != 0);
  }
  gartOffset = M<int>(textureBytes + 0x14);
  M<UInt16>(gartOffset + 0x1c) = M<UInt16>(gartOffset + 0x1c) | M<UInt16>(gartOffset + 0x28);
  wordCount = M<UInt32>(hwInfoBytes);
  if ((wordCount & 1) != 0) {
    gartOffset = wordCount * 4;
    wordCount = wordCount + 1;
    M<UInt32>(record + gartOffset) = 0x80000000;
  }
  M<UInt32>(self + kIOATIR500Accelerator_commandGLBytesPerSample) = wordCount * 4 + M<int>(self + kIOATIR500Accelerator_commandGLBytesPerSample);
  M<int>(self + kIOATIR500Accelerator_texturePageOutBytesPerSample) = size + M<int>(self + kIOATIR500Accelerator_texturePageOutBytesPerSample);
  textureInfo = M<int>(textureBytes + 0x14);
  stamp = this->submit_buffer((UInt32 *)record,M<int>(textureBytes + 4) + 0xa00,wordCount);
  M<UInt32>(textureInfo + 0xc) = stamp;
  if (textureBytes[0x20] == 0x7) {
    M<UInt32>(M<int>(M<int>(textureBytes + 0x58) + 0x14) + 8) =
         M<UInt32>(M<int>(textureBytes + 0x14) + 0xc);
  }
  stamp = M<UInt32>(M<int>(textureBytes + 0x14) + 0xc);
  M<unsigned int>(hwInfoBytes + 0x20) = M<unsigned int>(hwInfoBytes + 0x20) | 0x10000000;
  M<UInt32>(hwInfoBytes + 0x1c) = stamp;
  return 1;
}
