/*
 * ATIR500Surface_submit_swap_buffer_Port.cpp
 *
 * ATIR500Surface::submit_swap_buffer (real addr 0x3ba80, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3ba80 */
void ATIR500Surface::submit_swap_buffer(UInt32 panel, UInt32 swapArg) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  int dualMode;
  UInt32 cmdWord;
  UInt32 *pendingBatch;
  UInt32 *dstCursor;
  int allocResult;
  int counterDelta;
  int slotHeaderAddr;
  int batchHeaderAddr;
  int copiedCount;
  UInt8 *accelerator;
  int accelAddr;
  unsigned int nextSlot;
  unsigned int wordIndex;
  unsigned int swapValue;
  unsigned int paddedWords;
  UInt32 batchWord3;
  UInt32 batchWord6;
  UInt32 swdsFlag;
  UInt32 submitStamp;
  int counterBefore;
  int wordsLeft;
  UInt32 *slotHeader;
  UInt32 *srcCursor;
  UInt32 batchWord2;
  UInt32 batchWord5;
  UInt32 batchWord1;
  UInt32 batchWord4;
  int *accelObj;
  UInt32 *cmd;
  UInt8 *slotBytes;
  
  if (M<SInt16>(self + kATIR500Surface_swapBatchBuilt) != 0) {
    M<UInt32>(M<int>(self + kIOATIR500Surface_accelerator) + 0x78) = 0;
  }
  if (M<int>(self + kIOATIR500Surface_flipContext) != 0) {
    M<UInt32>(self + kIOATIR500Surface_flipContext) = 0;
    M<unsigned int>((int)Vol(PANEL_RECORD(self, panel)->entries[0].header) + 0x1c) =
         M<unsigned int>((int)Vol(PANEL_RECORD(self, panel)->entries[0].header) + 0x1c) | 1;
  }
  PanelRecord *rec = PANEL_RECORD(self, panel);
  SwapBufferEntry *slot;     /* the submit slot in use: entries[1 + slotIndex] */
  if ((M<unsigned int>((int)Vol(rec->entries[0].header) + 0x1c) & 1) == 0) {
    slot = &rec->entries[1 + (unsigned int)Vol(rec->slotIndex)];
    slotBytes = (UInt8 *)slot;
    if (((int)Vol(slot->memory) == 0) &&
       (allocResult = ((IOATIR500Surface *)((UInt8 *)self))->allocAllSlaveSwapBuffers(panel,Vol(rec->swapBufferSize)),
       allocResult == 0)) {
      return;
    }
    goto submitSlot;
  }
  nextSlot = Vol(rec->slotIndex) + 1 & 3;
  Vol(rec->slotIndex) = (UInt16)nextSlot;
  slot = &rec->entries[1 + nextSlot];
  slotBytes = (UInt8 *)slot;
  if ((int)Vol(slot->memory) == 0) {
    allocResult = ((IOATIR500Surface *)((UInt8 *)self))->allocAllSlaveSwapBuffers(panel,Vol(rec->swapBufferSize));
    if (allocResult == 0) {
      return;
    }
  }
  else {
    accelObj = M<int *>(self + kIOATIR500Surface_accelerator);
    counterBefore = accelObj[0x1e2];
    counterDelta = VCALL(*accelObj, 0x54c)(accelObj,Vol(slot->stamp));
    accelObj[0x1e2] = counterBefore + counterDelta;
  }
  slotHeader = (UInt32 *)Vol(slot->header);
  pendingBatch = (UInt32 *)Vol(rec->entries[0].header);
  batchWord1 = pendingBatch[1];
  batchWord2 = pendingBatch[2];
  batchWord3 = pendingBatch[3];
  *slotHeader = *pendingBatch;
  slotHeader[1] = batchWord1;
  slotHeader[2] = batchWord2;
  slotHeader[3] = batchWord3;
  batchWord4 = pendingBatch[4];
  batchWord5 = pendingBatch[5];
  batchWord6 = pendingBatch[6];
  slotHeader[7] = pendingBatch[7];
  slotHeader[4] = batchWord4;
  slotHeader[5] = batchWord5;
  slotHeader[6] = batchWord6;
  slotHeaderAddr = (int)Vol(slot->header);
  cmd = (UInt32 *)(slotHeaderAddr + 0x20);
  if ((((swapArg & 0x18) == 0) || (M<SInt16>(self + kIOATIR500Surface_scalingFlags) != 0)) ||
     ((accelAddr = M<int>(self + kIOATIR500Surface_accelerator), M<char>(accelAddr + 0x9b0) != '\0' &&
      (M<int>(panel * 0x18 + accelAddr + 0xb10) != 0)))) {
    wordIndex = 0;
  }
  else {
    swapValue = M<UInt16>(panel * 0x78 + accelAddr + 0x14a) & 0xfff;
    *cmd = 0x1393;
    M<UInt32>(slotHeaderAddr + 0x24) = 10;
    M<UInt32>(slotHeaderAddr + 0x28) = 0xd0b;
    M<UInt32>(slotHeaderAddr + 0x2c) = 5;
    M<UInt32>(slotHeaderAddr + 0x30) = 0x5c8;
    M<UInt32>(slotHeaderAddr + 0x34) = 0x70000;
    if (panel == 0) {
      dualMode = M<int>(accelAddr + 0x894);
      if (dualMode == 0) {
        M<UInt32>(slotHeaderAddr + 0x38) = 0x194e;
        M<unsigned int>(slotHeaderAddr + 0x3c) = (swapValue & ~M<unsigned int>(accelAddr + 0x898)) << 0x10 | 0x80000000;
        M<UInt32>(slotHeaderAddr + 0x40) = 0x5c8;
        M<UInt32>(slotHeaderAddr + 0x44) = 8;
        wordIndex = 10;
      }
      else {
checkDualMode:
        wordIndex = 6;
        if (dualMode != 0) goto writePanel1SwapRegs;
      }
    }
    else {
      if (panel != 1) {
        dualMode = M<int>(accelAddr + 0x894);
        goto checkDualMode;
      }
writePanel1SwapRegs:
      wordIndex = 10;
      M<UInt32>(slotHeaderAddr + 0x38) = 0x1b4e;
      M<unsigned int>(slotHeaderAddr + 0x3c) = (swapValue & ~M<unsigned int>(accelAddr + 0x89c)) << 0x10 | 0x80000000;
      M<UInt32>(slotHeaderAddr + 0x40) = 0x5c8;
      M<UInt32>(slotHeaderAddr + 0x44) = 0x80000008;
    }
  }
  batchHeaderAddr = (int)Vol(rec->entries[0].header);
  wordsLeft = M<int>(batchHeaderAddr + 0x14) - M<int>(batchHeaderAddr + 0x18);
  srcCursor = (UInt32 *)(batchHeaderAddr + 0x20 + M<int>(batchHeaderAddr + 0x18) * 4);
  if (wordsLeft != 0) {
    copiedCount = 0;
    dstCursor = cmd + wordIndex;
    do {
      cmdWord = *srcCursor;
      copiedCount = copiedCount + 1;
      srcCursor = srcCursor + 1;
      *dstCursor = cmdWord;
      dstCursor = dstCursor + 1;
      wordsLeft = wordsLeft + -1;
    } while (wordsLeft != 0);
    wordIndex = wordIndex + copiedCount;
  }
  accelerator = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
  if (accelerator[0x9b0] == 0x0) {
    swdsFlag = 0;
  }
  else if ((M<int>(accelerator + kIOATIR500Accelerator_scanoutOverlapsVram) == 0) || (M<int>(accelerator + kIOATIR500Accelerator_swdsPanel1Flag) == 0)) {
    if (M<int>(accelerator + panel * 0x18 + kIOATIR500Accelerator_swdsPanel0Flag) == 0) {
      wordIndex = ((ATIRadeonX1000 *)(accelerator))->SWDSWriteBlitToCmdBuf((UInt32 *)(cmd), wordIndex, true, (unsigned int)(panel == 0));
      swdsFlag = 1;
    }
    else {
      wordIndex = ((ATIRadeonX1000 *)(accelerator))->SWDSWriteBlitToCmdBuf((UInt32 *)(cmd), wordIndex, true, panel);
      swdsFlag = 1;
    }
  }
  else {
    wordIndex = ((ATIRadeonX1000 *)(accelerator))->SWDSWriteBlitToCmdBuf((UInt32 *)(cmd), wordIndex, true, 1);
    swdsFlag = 1;
  }
  *(UInt32 *)Vol(slot->header) = swdsFlag;
  paddedWords = wordIndex;
  if ((wordIndex & 1) != 0) {
    paddedWords = wordIndex + 1;
    cmd[wordIndex] = 0x80000000;
  }
  M<unsigned int>((int)Vol(slot->header) + 0x14) = paddedWords;
  M<unsigned int>((int)Vol(rec->entries[0].header) + 0x1c) =
       M<unsigned int>((int)Vol(rec->entries[0].header) + 0x1c) & 0xfffffffe;
submitSlot:
  if (M<int>(slotBytes + 4) == 0) {
    ((IOATIR500Surface *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(slotBytes));
  }
  M<int>(M<int>(self + kIOATIR500Surface_accelerator) + 0x710) =
       M<int>(M<int>(slotBytes + 0x14) + 0x14) * 4 + M<int>(M<int>(self + kIOATIR500Surface_accelerator) + 0x710);
  accelerator = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
  submitStamp = ((ATIRadeonX1000 *)(accelerator))->submit_buffer((UInt32 *)(M<int>(slotBytes + 0x14) + 0x20),M<int>(slotBytes + 4) + 0x20
                      ,M<UInt32>(M<int>(slotBytes + 0x14) + 0x14));
  M<UInt32>(slotBytes + 0x10) = submitStamp;
  M<UInt32>(self + kIOATIR500Surface_submittedStamp) = submitStamp;
  M<UInt32>(accelerator + panel * 0x20 + kIOATIR500Accelerator_framebuffer0SubmitStamp) = submitStamp;
  accelAddr = M<int>(self + kIOATIR500Surface_accelerator);
  if ((M<char>(accelAddr + 0x9b0) != '\0') && (*M<int *>(slotBytes + 0x14) != 0)) {
    if (M<int>(panel * 0x18 + accelAddr + 0xb10) == 0) {
      if ((M<int>(accelAddr + 0x894) != 0) &&
         (M<int>((unsigned int)(panel == 0) * 0x18 + accelAddr + 0xb10) != 0)) {
        M<UInt32>((unsigned int)(panel == 0) * 4 + accelAddr + 0xad4) = M<UInt32>(self + kIOATIR500Surface_submittedStamp);
        M<UInt32>(M<int>(self + kIOATIR500Surface_accelerator) + 0x78) = 0;
      }
    }
    else {
      M<UInt32>(panel * 4 + accelAddr + 0xad4) = M<UInt32>(self + kIOATIR500Surface_submittedStamp);
      M<UInt32>(M<int>(self + kIOATIR500Surface_accelerator) + 0x78) = 0;
    }
  }
  return;
}
