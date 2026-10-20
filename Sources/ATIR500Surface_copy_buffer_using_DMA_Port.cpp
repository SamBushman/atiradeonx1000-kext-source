/*
 * ATIR500Surface_copy_buffer_using_DMA_Port.cpp
 *
 * ATIR500Surface::copy_buffer_using_DMA (real addr 0x42a80, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


UInt32 write_3dtexquad_cmds_for_copy_buffer_using_DMA(ATIRadeonX1000 *accel, UInt32 *cmd, UInt32 depthWords, UInt32 a3,
    UInt32 srcAddr, UInt32 srcPitch, UInt32 srcPitchShifted, UInt32 srcHeight, UInt32 srcSampleA, UInt32 srcShift,
    unsigned char srcBytes, UInt32 srcFormat, UInt32 dstAddr, UInt32 dstPitch, UInt32 dstPitchShifted, UInt32 dstSampleB,
    UInt32 dstShift, unsigned char dstBytes, long dstX, long dstY, long srcX, long srcY, UInt32 w, UInt32 h, bool flip);

/* real addr 0x42a80 */
UInt32 ATIR500Surface::copy_buffer_using_DMA(SInt32 x, SInt32 y, SInt32 w, SInt32 h, UInt32 index, UInt32 level, ATIR500SurfaceBuffer *buffer, VendorTransferBuffer *transfer, UInt32 offset, UInt32 pitch, IODirection direction, UInt32 flags) {   /* Ghidra numbers the 12 real parameters 1-10, 12, 13 (slot 11 is skipped) */
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);
    UInt8 *transferBytes = reinterpret_cast<UInt8 *>(transfer);
    PanelRecord *rec0 = PANEL_RECORD(self, 0);     /* the surface's first panel: batch in entries[0], submit slots in entries[1..4] */

  bool hzClear;
  UInt16 bufferHeight;
  bool needsMapping;
  bool inSwapRange;
  bool synchronous;
  unsigned int slot;
  bool condOk;
  bool isWrite;
  SInt16 useCount;
  unsigned int hzFlag;
  unsigned int alignedHeight;
  unsigned int quadWords;
  int *transferMap;
  UInt32 wordCount;
  unsigned int paddedWordCount;
  UInt32 submitStamp;
  int accel;
  int gartBase;
  int mapBase;
  int levelOffset;
  int srcY;
  int gartOffset;
  UInt8 *accelBytes;
  int transferGartOffset;
  int bufferGpuBase;
  int allocResult;
  int counterDelta;
  UInt8 backingFlag;
  UInt8 writeBits;
  UInt32 srcSampleA;
  UInt32 srcFormat;
  UInt32 formatIndex;
  UInt32 dstSampleB;
  int shiftOffsetSrc;
  int shiftOffsetDst;
  int *accelObj;
  int counterBefore;
  UInt32 *cmd;
  UInt8 syncBits;
  UInt8 hzClearBits;
  UInt32 srcPitch;
  UInt32 dstPitchRaw [3];
  void *mappedAddress;
  UInt32 transferSpan;
  int flipVertically;
  UInt32 dstAddress;
  UInt32 srcAddress;
  long srcX;
  int dstY;
  long dstX;
  unsigned int dstBytes;
  unsigned int srcBytes;
  UInt32 dstPitch;
  UInt32 srcWidth;
  
  accel = M<int>(self + kIOATIR500Surface_accelerator);
  transferSpan = (h - 1) * pitch + M<UInt16>(bufferBytes + 0x16) * w;
  if (M<char>(accel + kIOATIR500Accelerator_active) == '\0') {
    return 0;
  }
  hzFlag = M<unsigned int>(bufferBytes + 0x3c) >> 0xb & 1;
  if ((bufferBytes < self + kIOATIR500Surface_buffer10) || (inSwapRange = true, self + kIOATIR500Surface_buffer14 < bufferBytes)) {
    inSwapRange = false;
  }
  if (bufferBytes == (UInt8 *)(self + kIOATIR500Surface_buffer9)) {
    return 0;
  }
  hzClear = hzFlag == 0;
  hzClearBits = hzClear << 1;
  backingFlag = (UInt8)hzFlag ^ 1;
  if ((!hzClear) && ((M<unsigned int>(self + kIOATIR500Surface_modeBits) & 0x7c0000) != 0)) {
    return 0;
  }
  if (((flags & 2) == 0) || (flipVertically = 1, (M<unsigned int>(self + kIOATIR500Surface_modeBits) & 0x70000000) != 0)) {
    flipVertically = 0;
  }
  synchronous = (flags & 1) == 0;
  syncBits = synchronous << 1;
  if (synchronous) {
    if (!hzClear) {
      condOk = (M<unsigned int>(self + kIOATIR500Surface_modeBits) & 0x7c0000) == 0;
joined_r0x00042bb8:
      if (!condOk) {
        return 0;
      }
    }
LAB_00042bcc:
    backingFlag = 1;
  }
  else if (direction != 1) {
    condOk = hzClear;
    if (M<char>(M<int>(bufferBytes + 0x24) + 0x58) != '\0') goto joined_r0x00042bb8;
    goto LAB_00042bcc;
  }
  isWrite = direction != 1;
  if (isWrite) {
    if (direction != 2) goto LAB_00042bf0;
  }
  else if ((M<unsigned int>(accel + kIOATIR500Accelerator_hwCapabilityBits) >> 3 & 1) == 0) {
LAB_00042bf0:
    needsMapping = false;
    goto LAB_00042bf4;
  }
  needsMapping = true;
LAB_00042bf4:
  if (((M<unsigned int>(accel + kIOATIR500Accelerator_hwCapabilityBits) & 0x20000) != 0) && (!needsMapping)) {
    return 0;
  }
  if ((hzClear) || (synchronous)) {
    if ((inSwapRange) && ((M<int>(self + kATIR500Surface_deintMode) != 0 && (!synchronous)))) {
      w = (UInt32)M<UInt16>(bufferBytes + 0x14);
    }
  }
  else {
    w = (UInt32)M<UInt16>(bufferBytes + 0x14);
    if ((h & 0x1f) != 0) {
      h = (((int)h >> 5) + (unsigned int)((int)h < 0 && (h & 0x1f) != 0)) * 0x20 +
                0x20;
    }
  }
  if (M<int>(bufferBytes + 0x24) != 0) {
    M<UInt8>(M<int>(bufferBytes + 0x24) + 0x58) = backingFlag;
    accel = M<int>(self + kIOATIR500Surface_accelerator);
  }
  if (!needsMapping) {
    gartBase = M<int>(accel + kIOATIR500Accelerator_vramSizeProgrammed);
    writeBits = (direction == 2) << 1;
    transferMap = (int *)0x0;
    mappedAddress = (void *)0x0;
  }
  else {
    transferMap = (int *)VCALL(*M<int *>(transferBytes + 8), 0x14c)
                               (M<int *>(transferBytes + 8),GH_kernel_task,0,
                                M<unsigned int>(accel + kIOATIR500Accelerator_commandBufferMemoryOptions) | 1,0,0);
    if (transferMap == (int *)0x0) {
      return 0;
    }
    writeBits = (direction == 2) << 1;
    mapBase = VCALL(*transferMap, 0xd0)(transferMap);
    mappedAddress = (void *)(mapBase + offset);
    if ((bool)(writeBits >> 1 & 1)) {
      accelBytes = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
      if ((M<unsigned int>(accelBytes + kIOATIR500Accelerator_hwCapabilityBits) & 0x80) != 0) {
        ((IOATIR500Accelerator *)(accelBytes))->flush_memory_for_out((const void *)(mappedAddress), pitch * h);
        accelBytes = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
      }
    }
    else {
      accelBytes = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
      if ((M<unsigned int>(accelBytes + kIOATIR500Accelerator_hwCapabilityBits) & 0x80) != 0) {
        ((IOATIR500Accelerator *)(accelBytes))->flush_memory_for_in((const void *)(mappedAddress), transferSpan);
        accelBytes = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
      }
    }
    gartBase = M<int>(accelBytes + kIOATIR500Accelerator_vramSizeProgrammed);
  }
  transferGartOffset = M<int>(transferBytes + 4);
  if (transferGartOffset == 0) {
    ((IOATIR500Surface *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(transferBytes));
    transferGartOffset = M<int>(transferBytes + 4);
  }
  if (flipVertically != 0) {
    if ((int)M<SInt16>(self + kIOATIR500Surface_height) == (int)M<SInt16>(self + kIOATIR500Surface_committedHeight)) {
      y = ((unsigned int)M<UInt16>(bufferBytes + 0x1e) - y) - h;
    }
    else {
      y = (M<SInt16>(self + kIOATIR500Surface_committedHeight) - y) - h;
    }
  }
  if ((bool)(writeBits >> 1 & 1)) {
    formatIndex = (UInt32)(UInt8)bufferBytes[0x3a];
    srcPitch = pitch;
    shiftOffsetSrc = formatIndex * 0x1c;
    srcAddress = gartBase + offset + transferGartOffset;
    srcWidth = (int)pitch >> (FormatTableLookup_0x0004d2dc(shiftOffsetSrc) >> 0xc & 7);
    if ((bool)(hzClearBits >> 1 & 1)) {
      alignedHeight = (unsigned int)M<UInt16>(bufferBytes + 0x1e);
    }
    else {
      bufferHeight = M<UInt16>(bufferBytes + 0x1e);
      alignedHeight = (unsigned int)bufferHeight;
      if ((bufferHeight & 0x1f) != 0) {
        alignedHeight = (bufferHeight & 0xffffffe0) + 0x20;
      }
    }
    srcBytes = (unsigned int)(UInt8)bufferBytes[0x39];
    bufferGpuBase = M<int>(bufferBytes + 8);
    srcSampleA = 0;
    srcX = x;
    levelOffset = VCALL(M<int>(self), 0x5f0)(self,bufferBytes,index,level,0,0,dstPitchRaw);
    srcFormat = (UInt32)(UInt8)bufferBytes[0x3a];
    dstSampleB = (UInt32)(UInt8)bufferBytes[0x38];
    dstAddress = bufferGpuBase + levelOffset;
    dstBytes = 0;
    shiftOffsetDst = srcFormat * 0x1c;
    dstX = 0;
    dstY = 0;
    dstPitch = (int)dstPitchRaw[0] >> (FormatTableLookup_0x0004d2dc(shiftOffsetDst) >> 0xc & 7);
    srcY = y;
  }
  else {
    dstPitchRaw[0] = pitch;
    srcFormat = (UInt32)(UInt8)bufferBytes[0x3a];
    shiftOffsetDst = srcFormat * 0x1c;
    bufferGpuBase = M<int>(bufferBytes + 8);
    dstAddress = gartBase + offset + transferGartOffset;
    dstPitch = (int)pitch >> (FormatTableLookup_0x0004d2dc(shiftOffsetDst) >> 0xc & 7);
    dstBytes = (unsigned int)(UInt8)bufferBytes[0x39];
    levelOffset = VCALL(M<int>(self), 0x5f0)(self,bufferBytes,index,level,0,0,&srcPitch);
    srcAddress = bufferGpuBase + levelOffset;
    if ((bool)(hzClearBits >> 1 & 1)) {
      alignedHeight = (unsigned int)M<UInt16>(bufferBytes + 0x1e);
    }
    else {
      bufferHeight = M<UInt16>(bufferBytes + 0x1e);
      alignedHeight = (unsigned int)bufferHeight;
      if ((bufferHeight & 0x1f) != 0) {
        alignedHeight = (bufferHeight & 0xffffffe0) + 0x20;
      }
    }
    formatIndex = (UInt32)(UInt8)bufferBytes[0x3a];
    srcSampleA = (UInt32)(UInt8)bufferBytes[0x38];
    dstSampleB = 0;
    srcBytes = 0;
    shiftOffsetSrc = formatIndex * 0x1c;
    srcY = 0;
    srcX = 0;
    srcWidth = (int)srcPitch >> (FormatTableLookup_0x0004d2dc(shiftOffsetSrc) >> 0xc & 7);
    dstY = y;
    dstX = x;
  }
  if ((!(bool)(syncBits >> 1 & 1)) && (!(bool)(hzClearBits >> 1 & 1))) {
    srcSampleA = 0;
    dstSampleB = 0;
  }
  M<unsigned int>((int)Vol(rec0->entries[0].header) + 0x1c) = M<unsigned int>((int)Vol(rec0->entries[0].header) + 0x1c) | 1;
  slot = Vol(rec0->slotIndex) + 1 & 3;
  Vol(rec0->slotIndex) = (UInt16)slot;
  if ((int)Vol(rec0->entries[1 + slot].memory) == 0) {
    allocResult = ((IOATIR500Surface *)((UInt8 *)self))->allocAllSlaveSwapBuffers(0,Vol(rec0->swapBufferSize));
    if (allocResult == 0) {
      return 0;
    }
  }
  else {
    accelObj = M<int *>(self + kIOATIR500Surface_accelerator);
    counterBefore = accelObj[0x1e2];
    counterDelta = VCALL(*accelObj, 0x54c)(accelObj,Vol(rec0->entries[1 + slot].stamp));
    accelObj[0x1e2] = counterBefore + counterDelta;
  }
  cmd = (UInt32 *)((int)Vol(rec0->entries[1 + slot].header) + 0x20);
  if ((isWrite) || ((bool)((hzClearBits & 2) >> 1))) {
    wordCount = 0;
  }
  else {
    wordCount = this->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)(bufferBytes),0,(UInt32 *)(cmd));
  }
  quadWords = write_3dtexquad_cmds_for_copy_buffer_using_DMA
                    (M<ATIRadeonX1000 *>(self + kIOATIR500Surface_accelerator),(UInt32 *)cmd,wordCount,formatIndex,srcAddress,srcPitch,
                     srcWidth,alignedHeight,srcSampleA,FormatTableLookup_0x0004d2dc(shiftOffsetSrc) >> 0xc & 7,
                     (UInt8)srcBytes,srcFormat,dstAddress,dstPitchRaw[0],dstPitch,dstSampleB,
                     FormatTableLookup_0x0004d2dc(shiftOffsetDst) >> 0xc & 7,(UInt8)dstBytes,dstX,dstY,
                     srcX,srcY,w,h,SUB41m(flipVertically,0));
  if (!(bool)(syncBits >> 1 & 1)) {
    M<UInt32>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb90) = 1;
  }
  M<UInt32>(M<int>(self + kIOATIR500Surface_accelerator) + 0x78) = 0;
  paddedWordCount = quadWords;
  if ((quadWords & 1) != 0) {
    paddedWordCount = quadWords + 1;
    cmd[quadWords] = 0x80000000;
  }
  M<unsigned int>((int)Vol(rec0->entries[1 + slot].header) + 0x14) = paddedWordCount;
  gartOffset = (int)Vol(rec0->entries[1 + slot].gartOffset);
  useCount = M<SInt16>(transferBytes + 0xe) + 1;
  M<SInt16>(transferBytes + 0xe) = useCount;
  if (gartOffset == 0) {
    ((IOATIR500Surface *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)&rec0->entries[1 + slot]));
    useCount = M<SInt16>(transferBytes + 0xe);
    gartOffset = (int)Vol(rec0->entries[1 + slot].gartOffset);
  }
  M<SInt16>(transferBytes + 0xe) = useCount + -1;
  submitStamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500Surface_accelerator)))->submit_buffer((UInt32 *)((int)Vol(rec0->entries[1 + slot].header) + 0x20),gartOffset + 0x20,
                      M<UInt32>((int)Vol(rec0->entries[1 + slot].header) + 0x14));
  M<UInt32>(self + kIOATIR500Surface_stamp) = submitStamp;
  Vol(rec0->entries[1 + slot].stamp) = submitStamp;
  if ((bool)(syncBits >> 1 & 1)) {
    VCALL(*M<int *>(self + kIOATIR500Surface_accelerator), 0x54c)(M<int *>(self + kIOATIR500Surface_accelerator),submitStamp);
    VCALL(*M<int *>(self + kIOATIR500Surface_accelerator), 0x5ac)(M<int *>(self + kIOATIR500Surface_accelerator),transferBytes);
    if (((needsMapping) && (!isWrite)) &&
       ((M<unsigned int>(M<UInt8 *>(self + kIOATIR500Surface_accelerator) + 0x98) & 0x80) != 0)) {
      ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500Surface_accelerator)))->flush_memory_for_in((const void *)(mappedAddress),transferSpan);
    }
  }
  else {
    M<UInt32>(M<int>(transferBytes + 0x14) + 8) = submitStamp;
  }
  if (transferMap != (int *)0x0) {
    VCALL(*transferMap, 0x18)(transferMap);
    return 1;
  }
  return 1;
}
