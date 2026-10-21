/*
 * ATIR500Surface_submit_flip_buffer_Port.cpp
 *
 * ATIR500Surface::submit_flip_buffer (real addr 0x3e5c0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3e5c0 */
void ATIR500Surface::submit_flip_buffer(UInt32 panel, IOATIR500GLContext *context, UInt32 unused4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *contextBytes = reinterpret_cast<UInt8 *>(context);

  bool hasTiling;
  bool isPanel0;
  bool isPanel1;
  UInt8 tilingByte0;
  UInt16 pitchBaseField;
  UInt16 bytesPerPixel;
  int formatOffset;
  SInt16 contextField98;
  UInt32 *batchHeader;
  UInt32 *packet;
  unsigned int formatE0;
  int mip0Offset;
  int valueIndex;
  int counterBefore;
  int bufferGpuBase;
  unsigned int nextSlot;
  unsigned int tilingBits;
  unsigned int pitchPerDegree;
  UInt32 batchWord3;
  UInt32 batchWord7;
  UInt32 attachGpuBase;
  UInt32 submitStamp;
  unsigned int minPitchFloor;
  unsigned int formatDC;
  unsigned int minPitch;
  unsigned int scanoutPitch;
  unsigned int nextIndex;
  unsigned int paddedWordCount;
  int batchHeaderAddr;
  int allocResult;
  int markerValueIndex;
  int slotHeaderAddr;
  int waited;
  UInt32 *slotHeader;
  int attachBuffer;
  UInt32 batchWord2;
  UInt32 batchWord6;
  UInt32 batchWord1;
  UInt32 batchWord4;
  unsigned int msbFlag;
  UInt8 *slotBytes;
  int *accelObj;
  UInt8 *pAccel;
  unsigned int wordIndex;
  int otherPanelRecord;
  int accel;
  
  if (M<SInt16>(self + kATIR500Surface_swapBatchBuilt) != 0) {
    M<UInt32>(M<int>(self + kIOATIR500Surface_accelerator) + 0x78) = 0;
  }
  if (M<UInt32>(self + kIOATIR500Surface_flipContext) != (UInt32)contextBytes) {
    M<UInt32>(self + kIOATIR500Surface_flipContext) = (UInt32)contextBytes;
    batchHeaderAddr = (int)Vol(PANEL_RECORD(self, panel)->entries[0].header);
    M<unsigned int>(batchHeaderAddr + 0x1c) = M<unsigned int>(batchHeaderAddr + 0x1c) | 1;
  }
  PanelRecord *rec = PANEL_RECORD(self, panel);
  SwapBufferEntry *slot;     /* the submit slot in use: entries[1 + slotIndex] */
  if ((M<unsigned int>((int)Vol(rec->entries[0].header) + 0x1c) & 1) == 0) {
    slot = &rec->entries[1 + (unsigned int)Vol(rec->slotIndex)];
    slotBytes = (UInt8 *)slot;
    if (((int)Vol(slot->memory) == 0) &&
       (allocResult = ((IOATIR500Surface *)((UInt8 *)self))->allocAllSlaveSwapBuffers((UInt32)panel,Vol(rec->swapBufferSize)),
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
    allocResult = ((IOATIR500Surface *)((UInt8 *)self))->allocAllSlaveSwapBuffers((UInt32)panel,Vol(rec->swapBufferSize));
    if (allocResult == 0) {
      return;
    }
  }
  else {
    accelObj = M<int *>(self + kIOATIR500Surface_accelerator);
    counterBefore = accelObj[0x1e2];
    waited = VCALL(*accelObj, 0x54c)(accelObj,Vol(slot->stamp));
    accelObj[0x1e2] = counterBefore + waited;
  }
  slotHeader = (UInt32 *)Vol(slot->header);
  batchHeader = (UInt32 *)Vol(rec->entries[0].header);
  batchWord1 = batchHeader[1];
  batchWord2 = batchHeader[2];
  batchWord3 = batchHeader[3];
  *slotHeader = *batchHeader;
  slotHeader[1] = batchWord1;
  slotHeader[2] = batchWord2;
  slotHeader[3] = batchWord3;
  batchWord7 = batchHeader[7];
  batchWord4 = batchHeader[4];
  batchWord6 = batchHeader[6];
  slotHeader[5] = batchHeader[5];
  slotHeader[7] = batchWord7;
  slotHeader[4] = batchWord4;
  slotHeader[6] = batchWord6;
  slotHeaderAddr = (int)Vol(slot->header);
  packet = (UInt32 *)(slotHeaderAddr + 0x20);
  *packet = 0xd0b;
  M<UInt32>(slotHeaderAddr + 0x24) = 5;
  M<UInt32>(slotHeaderAddr + 0x28) = 0x1393;
  M<UInt32>(slotHeaderAddr + 0x2c) = 10;
  M<UInt32>(slotHeaderAddr + 0x30) = 0x5c8;
  M<UInt32>(slotHeaderAddr + 0x34) = 0x30000;
  if (contextBytes == 0) {
    wordIndex = 6;
    contextField98 = 0;
  }
  else {
    attachBuffer = M<int>((unsigned int)M<UInt16>(contextBytes + 0xac) * 4 + self + kIOATIR500Surface_attachmentBuffers);
    mip0Offset = M<int>(attachBuffer + 0x40);
    pitchBaseField = M<UInt16>(attachBuffer + 0x20);
    tilingBits = M<unsigned int>(attachBuffer + 0x3c);
    bufferGpuBase = M<int>(attachBuffer + 8);
    hasTiling = (tilingBits & 0xf00000) != 0;
    if (hasTiling) {
      minPitch = (SInt32)M<UInt16>(attachBuffer + 0x14) / (SInt32)(tilingBits >> 0x14 & 0xf);
    }
    else {
      minPitch = 0;
    }
    bytesPerPixel = M<UInt16>(attachBuffer + 0x16);
    minPitchFloor = 0x20 / bytesPerPixel;
    if (minPitch < minPitchFloor) {
      minPitch = minPitchFloor;
    }
    tilingByte0 = M<UInt8>(attachBuffer + 0x38);
    msbFlag = 0x80000000;
    if (tilingByte0 < 2) {
      msbFlag = 0;
    }
    formatOffset = (unsigned int)M<UInt8>(attachBuffer + 0x3a) * 0x1c;
    if (hasTiling) {
      pitchPerDegree = (SInt32)M<UInt16>(attachBuffer + 0x14) / (SInt32)(tilingBits >> 0x14 & 0xf);
    }
    else {
      pitchPerDegree = 0;
    }
    if (pitchPerDegree < minPitchFloor) {
      pitchPerDegree = minPitchFloor;
    }
    formatDC = FormatTableLookup_0x0004d2dc(formatOffset);
    formatE0 = FormatTableLookup_0x0004d2e0(formatOffset);
    M<UInt32>(slotHeaderAddr + 0x38) = 0x50b;
    M<unsigned int>(slotHeaderAddr + 0x3c) =
         msbFlag | bufferGpuBase + (unsigned int)pitchBaseField * mip0Offset >> 10 | minPitch * bytesPerPixel * 0x10000 & 0x3fc00000 |
                  (tilingByte0 & 1) << 0x1e;
    M<UInt32>(slotHeaderAddr + 0x40) = 0x138a;
    M<int>(slotHeaderAddr + 0x44) = bufferGpuBase;
    M<UInt32>(slotHeaderAddr + 0x48) = 0x138e;
    M<unsigned int>(slotHeaderAddr + 0x4c) =
         formatE0 >> 1 & 0x1e00000 |
         (formatDC & 0xc00) << 9 | (tilingByte0 & 6) << 0x10 | (tilingByte0 & 1) << 0x10 | pitchPerDegree & 0x3ffe;
    contextField98 = M<SInt16>(contextBytes + 0x98);
    wordIndex = 0xc;
  }
  M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb78) =
       M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb78) & 0xffdfffff |
       (M<UInt8>(M<int>(self + kIOATIR500Surface_attachmentBuffers) + 0x38) & 1) << 0x15;
  M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb78) =
       (unsigned int)(1 < M<UInt8>(M<int>(self + kIOATIR500Surface_attachmentBuffers) + 0x38)) * 0x100000 |
       M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb78) & 0xffefffff;
  M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb80) =
       (unsigned int)(contextField98 == 0) | M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb80) & 0xfffffffe;
  if (panel[self + 0xdb6] == 0x0) {
    scanoutPitch = 0;
    M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb88) =
         M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb88) & 0xfeffffff;
  }
  else {
    scanoutPitch = M<UInt16>(M<int>(self + kIOATIR500Surface_attachmentBuffers) + 0x14) & 0x3fff;
    M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb88) =
         M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb88) & 0xfeffffff | 0x1000000;
    M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb88) =
         M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb88) & 0xfffffeff;
    M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb88) =
         M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb88) & 0xfffeffff;
  }
  M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb7c) =
       M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb7c) & 0xffdfffff |
       (M<UInt8>(M<int>(self + kIOATIR500Surface_attachmentBuffers) + 0x38) & 1) << 0x15;
  M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb7c) =
       (unsigned int)(1 < M<UInt8>(M<int>(self + kIOATIR500Surface_attachmentBuffers) + 0x38)) * 0x100000 |
       M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb7c) & 0xffefffff;
  M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb84) =
       (unsigned int)(contextField98 == 0) | M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb84) & 0xfffffffe;
  if (panel[self + 0xdb6] == 0x0) {
    M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb8c) =
         M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb8c) & 0xfeffffff;
  }
  else {
    scanoutPitch = M<UInt16>(M<int>(self + kIOATIR500Surface_attachmentBuffers) + 0x14) & 0x3fff;
    M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb8c) =
         M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb8c) & 0xfeffffff | 0x1000000;
    M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb8c) =
         M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb8c) & 0xfffffeff;
    M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb8c) =
         M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb8c) & 0xfffeffff;
  }
  accel = M<int>(self + kIOATIR500Surface_accelerator);
  if (M<int>(accel + kIOATIR500Accelerator_scanoutOverlapsVram) != 0) {
    M<unsigned int>(accel + kIOATIR500Accelerator_savedD1Reg6148) = M<unsigned int>(accel + kIOATIR500Accelerator_savedD1Reg6148) & 0xfffffffe | 1;
    accel = M<int>(self + kIOATIR500Surface_accelerator);
  }
  isPanel0 = panel == 0;
  if ((isPanel0) || (M<int>(accel + kIOATIR500Accelerator_scanoutOverlapsVram) != 0)) {
    if (panel[self + 0xdb6] != 0x0) {
      packet[wordIndex] = 0x1848;
      valueIndex = wordIndex + 1;
      wordIndex = wordIndex + 2;
      packet[valueIndex] = scanoutPitch;
    }
    packet[wordIndex] = 0x1841;
    packet[wordIndex + 1] = M<UInt32>(accel + kIOATIR500Accelerator_savedD1Reg6104);
    packet[wordIndex + 2] = 0x1852;
    packet[wordIndex + 3] = M<UInt32>(accel + kIOATIR500Accelerator_savedD1Reg6148);
    packet[wordIndex + 4] = 0x1831;
    valueIndex = wordIndex + 5;
    wordIndex = wordIndex + 6;
    packet[valueIndex] = M<UInt32>(accel + kIOATIR500Accelerator_savedD1Reg60c4);
  }
  isPanel1 = panel == 1;
  if ((isPanel1) || (M<int>(accel + kIOATIR500Accelerator_scanoutOverlapsVram) != 0)) {
    if (panel[self + 0xdb6] != 0x0) {
      packet[wordIndex] = 0x1a48;
      valueIndex = wordIndex + 1;
      wordIndex = wordIndex + 2;
      packet[valueIndex] = scanoutPitch;
    }
    packet[wordIndex] = 0x1a41;
    packet[wordIndex + 1] = M<UInt32>(accel + kIOATIR500Accelerator_savedD2Reg6904);
    packet[wordIndex + 2] = 0x1a52;
    packet[wordIndex + 3] = M<UInt32>(accel + kIOATIR500Accelerator_savedD2Reg6948);
    packet[wordIndex + 4] = 0x1a31;
    valueIndex = wordIndex + 5;
    wordIndex = wordIndex + 6;
    packet[valueIndex] = M<UInt32>(accel + kIOATIR500Accelerator_savedD2Reg68c4);
  }
  attachGpuBase = M<UInt32>(M<int>(self + kIOATIR500Surface_attachmentBuffers) + 8);
  if ((isPanel0) || (nextIndex = wordIndex, M<int>(accel + kIOATIR500Accelerator_scanoutOverlapsVram) != 0)) {
    packet[wordIndex] = 0x1844;
    packet[wordIndex + 1] = attachGpuBase;
    packet[wordIndex + 2] = 0x1844;
    packet[wordIndex + 3] = attachGpuBase;
    packet[wordIndex + 4] = 0x1844;
    nextIndex = wordIndex + 6;
    packet[wordIndex + 5] = attachGpuBase;
    if (panel[self + 0xdb6] != 0x0) {
      packet[nextIndex] = 0x1846;
      nextIndex = wordIndex + 8;
      packet[wordIndex + 7] = M<UInt32>(M<int>(self + kIOATIR500Surface_attachmentBuffer5) + 8);
    }
  }
  if ((isPanel1) || (wordIndex = nextIndex, M<int>(accel + kIOATIR500Accelerator_scanoutOverlapsVram) != 0)) {
    packet[nextIndex] = 0x1a44;
    packet[nextIndex + 1] = attachGpuBase;
    packet[nextIndex + 2] = 0x1a44;
    packet[nextIndex + 3] = attachGpuBase;
    packet[nextIndex + 4] = 0x1a44;
    wordIndex = nextIndex + 6;
    packet[nextIndex + 5] = attachGpuBase;
    if (panel[self + 0xdb6] != 0x0) {
      packet[wordIndex] = 0x1a46;
      wordIndex = nextIndex + 8;
      packet[nextIndex + 7] = M<UInt32>(M<int>(self + kIOATIR500Surface_attachmentBuffer5) + 8);
    }
  }
  if (M<char>(accel + 0x9b0) == '\0') {
appendFlipMarker:
    if (isPanel0) {
      packet[wordIndex] = 0x5c8;
      markerValueIndex = wordIndex + 1;
      wordIndex = wordIndex + 2;
      packet[markerValueIndex] = 1;
    }
    else if (isPanel1) {
      packet[wordIndex] = 0x5c8;
      markerValueIndex = wordIndex + 1;
      wordIndex = wordIndex + 2;
      packet[markerValueIndex] = 0x80000001;
    }
  }
  else if (M<int>((int)panel * 0x18 + accel + kIOATIR500Accelerator_swdsPanel0Flag) == 0) {
    if (M<int>(accel + kIOATIR500Accelerator_scanoutOverlapsVram) != 0) {
      if (isPanel0) {
        otherPanelRecord = 0xb18;
      }
      else {
        otherPanelRecord = 0xb00;
      }
      if (M<int>(accel + otherPanelRecord + 0x10) != 0) goto padPacket;
    }
    goto appendFlipMarker;
  }
padPacket:
  paddedWordCount = wordIndex;
  if ((wordIndex & 7) != 0) {
    paddedWordCount = wordIndex + 1;
    packet[wordIndex] = 0x80000000;
  }
  M<unsigned int>((int)Vol(slot->header) + 0x14) = paddedWordCount;
submitSlot:
  if (M<int>(slotBytes + 4) == 0) {
    ((IOATIR500Surface *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(slotBytes));
  }
  M<int>(M<int>(self + kIOATIR500Surface_accelerator) + 0x710) =
       M<int>(M<int>(slotBytes + 0x14) + 0x14) * 4 + M<int>(M<int>(self + kIOATIR500Surface_accelerator) + 0x710);
  pAccel = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
  submitStamp = ((ATIRadeonX1000 *)pAccel)->submit_buffer
                     ((UInt32 *)(M<int>(slotBytes + 0x14) + 0x20),M<int>(slotBytes + 4) + 0x20,
                      M<UInt32>(M<int>(slotBytes + 0x14) + 0x14));
  M<UInt32>(slotBytes + 0x10) = submitStamp;
  M<UInt32>(self + kIOATIR500Surface_submittedStamp) = submitStamp;
  M<UInt32>(pAccel + (int)panel * 0x20 + kIOATIR500Accelerator_framebuffer0SubmitStamp) = submitStamp;
  return;
}
