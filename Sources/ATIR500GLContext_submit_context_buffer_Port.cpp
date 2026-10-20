/*
 * ATIR500GLContext_submit_context_buffer_Port.cpp
 *
 * ATIR500GLContext::submit_context_buffer (real addr 0x2a8b0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x2a8b0 */
void ATIR500GLContext::submit_context_buffer() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 *accelerator;
  UInt8 *slotCursor;
  UInt8 *ringEntry;
  SInt32 waited;
  SInt32 copyByteOffset;
  SInt32 wordsWritten;
  SInt32 endIndex;
  UInt32 copyTempA;
  UInt32 copyTempB;
  UInt32 copyTempC;
  UInt32 submitStamp;
  UInt32 regWordCount;
  UInt32 slotIndex;
  UInt32 regsLeft;
  UInt32 wordCount;
  UInt32 ringIndex;
  UInt32 paddedWords;
  UInt8 *texture;
  UInt32 *headerForCopy;
  UInt32 *headerForRegs;
  UInt32 *destHeader;
  UInt32 *commandWords;
  SInt32 waitTotal;
  bool notLastSlot;
  UInt32 unpaddedWords;
  UInt8 *writeCursor;
  
  M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb90) = 0;
  slotCursor = self;
  do {
    texture = M<UInt8 *>(slotCursor + 0x2a4);
    if (texture != (UInt8 *)0x0) {
      if (M<char>(M<SInt32>(texture + 0x14) + 0x14) != '\0') {
        this->alloc_and_load_texture((VendorTextureBuffer *)(texture));
        VCALL(M<SInt32>(self), 0x5a4)(self);
        texture = M<UInt8 *>(slotCursor + 0x2a4);
      }
      if (M<SInt32>(texture + 0x48) != 0) {
        M<UInt32>(M<SInt32>(texture + 0x24) + 0x28) = M<UInt32>(texture + 0x28);
        M<UInt32>(M<SInt32>(M<SInt32>(slotCursor + 0x2a4) + 0x28) + 0x24) =
             M<UInt32>(M<SInt32>(slotCursor + 0x2a4) + 0x24);
        M<UInt32>(M<SInt32>(slotCursor + 0x2a4) + 0x24) =
             M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x600);
        M<SInt32>(M<SInt32>(slotCursor + 0x2a4) + 0x28) = M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5dc;
        M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x600) = M<UInt32>(slotCursor + 0x2a4);
        M<SInt32>(M<SInt32>(M<SInt32>(slotCursor + 0x2a4) + 0x24) + 0x28) = M<SInt32>(slotCursor + 0x2a4);
      }
    }
    slotCursor = slotCursor + 4;
  } while (self + 0xa8 != slotCursor);
  if ((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_contextBufferHeader) + 0x1c) & 1) == 0) {
    ringEntry = self + M<SInt32>(self + kIOATIR500GLContext_contextBufferRingIndex) * 0x18;
  }
  else {
    accelerator = M<SInt32 *>(self + kIOATIR500GLContext_accelerator);
    ringIndex = M<SInt32>(self + kIOATIR500GLContext_contextBufferRingIndex) + 1U & 0xf;
    M<UInt32>(self + kIOATIR500GLContext_contextBufferRingIndex) = ringIndex;
    ringEntry = self + ringIndex * 0x18;
    waitTotal = accelerator[0x1e0];
    waited = VCALL(*accelerator, 0x54c)(accelerator,M<UInt32>(ringEntry + 0x11c));
    accelerator[0x1e0] = waitTotal + waited;
    headerForCopy = M<UInt32 *>(self + kIOATIR500GLContext_contextBufferHeader);
    destHeader = M<UInt32 *>(ringEntry + 0x120);
    copyTempA = headerForCopy[1];
    copyTempB = headerForCopy[2];
    copyTempC = headerForCopy[3];
    *destHeader = *headerForCopy;
    destHeader[1] = copyTempA;
    destHeader[2] = copyTempB;
    destHeader[3] = copyTempC;
    copyTempA = headerForCopy[4];
    copyTempB = headerForCopy[5];
    copyTempC = headerForCopy[6];
    destHeader[7] = headerForCopy[7];
    destHeader[4] = copyTempA;
    destHeader[5] = copyTempB;
    destHeader[6] = copyTempC;
    headerForRegs = M<UInt32 *>(self + kIOATIR500GLContext_contextBufferHeader);
    regWordCount = headerForRegs[5];
    commandWords = (UInt32 *)(M<SInt32>(ringEntry + 0x120) + 0x20);
    regsLeft = 0;
    if (regWordCount != 0) {
      copyByteOffset = 0;
      regsLeft = regWordCount;
      do {
        M<UInt32>((SInt32)commandWords + copyByteOffset) = M<UInt32>((SInt32)headerForRegs + copyByteOffset + 0x20);
        copyByteOffset = copyByteOffset + 4;
        regsLeft = regsLeft - 1;
      } while (regsLeft != 0);
      headerForRegs = M<UInt32 *>(self + kIOATIR500GLContext_contextBufferHeader);
      regsLeft = regWordCount;
    }
    slotIndex = 0;
    wordCount = this->write_kernel_context_buffer_regs((UInt32 *)(commandWords),regsLeft,*headerForRegs,headerForRegs[1]);
    writeCursor = self;
    do {
      if (M<UInt8 *>(writeCursor + 0x2a4) != (UInt8 *)0x0) {
        wordsWritten = this->WriteTextureOffset(slotIndex,(UInt32 *)(commandWords),wordCount,
                                   (VendorTextureBuffer *)(M<UInt8 *>(writeCursor + 0x2a4)));
        wordCount = wordCount + wordsWritten;
      }
      notLastSlot = slotIndex != 0xf;
      writeCursor = writeCursor + 4;
      slotIndex = slotIndex + 1;
    } while (notLastSlot);
    endIndex = this->WriteVertexArrayOffset((UInt32 *)(commandWords),wordCount);
    endIndex = wordCount + endIndex;
    commandWords[endIndex] = 0x1040;
    unpaddedWords = endIndex + 2;
    commandWords[endIndex + 1] = 0;
    paddedWords = unpaddedWords;
    if ((unpaddedWords & 1) != 0) {
      paddedWords = endIndex + 3;
      commandWords[unpaddedWords] = 0x80000000;
    }
    M<UInt32>(M<SInt32>(ringEntry + 0x120) + 0x14) = paddedWords;
    M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_contextBufferHeader) + 0x1c) = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_contextBufferHeader) + 0x1c) & 0xfffffffe
    ;
  }
  if (M<SInt32>(ringEntry + 0x110) == 0) {
    ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(ringEntry + 0x10c)));
  }
  M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) =
       M<SInt32>(M<SInt32>(ringEntry + 0x120) + 0x14) * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
  submitStamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)(M<SInt32>(ringEntry + 0x120) + 0x20),
                     M<SInt32>(ringEntry + 0x110) + 0x20,M<UInt32>(M<SInt32>(ringEntry + 0x120) + 0x14));
  M<UInt32>(ringEntry + 0x11c) = submitStamp;
  M<UInt32>(self + kIOATIR500GLContext_lastSubmitStamp) = submitStamp;
  return;
}
