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

  bool bVar1;
  UInt16 uVar2;
  bool bVar3;
  bool bVar4;
  bool synchronous;
  unsigned int slot;
  bool bVar7;
  SInt16 sVar8;
  unsigned int uVar9;
  int *transferMap;
  UInt32 wordCount;
  unsigned int paddedWordCount;
  UInt32 submitStamp;
  int iVar14;
  UInt8 *this_00;
  int iVar15;
  UInt8 bVar16;
  UInt32 uVar17;
  UInt32 uVar18;
  UInt32 uVar19;
  UInt32 uVar20;
  int iVar21;
  int iVar22;
  int *piVar23;
  int iVar24;
  UInt32 *cmd;
  UInt8 bVar26;
  UInt8 bVar27;
  UInt32 local_98;
  UInt32 local_94 [3];
  void *mappedAddress;
  UInt32 transferSpan;
  int flipVertically;
  UInt32 dstAddress;
  UInt32 srcAddress;
  long srcX;
  int dstY;
  long dstX;
  unsigned int local_68;
  unsigned int local_64;
  UInt32 dstPitch;
  UInt32 srcWidth;
  
  iVar14 = M<int>(self + 0xd50);
  transferSpan = (h - 1) * pitch + M<UInt16>(bufferBytes + 0x16) * w;
  if (M<char>(iVar14 + 0x80) == '\0') {
    return 0;
  }
  uVar9 = M<unsigned int>(bufferBytes + 0x3c) >> 0xb & 1;
  if ((bufferBytes < self + 0x558) || (bVar4 = true, self + 0x738 < bufferBytes)) {
    bVar4 = false;
  }
  if (bufferBytes == (UInt8 *)(self + 0x4e0)) {
    return 0;
  }
  bVar1 = uVar9 == 0;
  bVar27 = bVar1 << 1;
  bVar16 = (UInt8)uVar9 ^ 1;
  if ((!bVar1) && ((M<unsigned int>(self + 0xbe8) & 0x7c0000) != 0)) {
    return 0;
  }
  if (((flags & 2) == 0) || (flipVertically = 1, (M<unsigned int>(self + 0xbe8) & 0x70000000) != 0)) {
    flipVertically = 0;
  }
  synchronous = (flags & 1) == 0;
  bVar26 = synchronous << 1;
  if (synchronous) {
    if (!bVar1) {
      bVar7 = (M<unsigned int>(self + 0xbe8) & 0x7c0000) == 0;
joined_r0x00042bb8:
      if (!bVar7) {
        return 0;
      }
    }
LAB_00042bcc:
    bVar16 = 1;
  }
  else if (direction != 1) {
    bVar7 = bVar1;
    if (M<char>(M<int>(bufferBytes + 0x24) + 0x58) != '\0') goto joined_r0x00042bb8;
    goto LAB_00042bcc;
  }
  bVar7 = direction != 1;
  if (bVar7) {
    if (direction != 2) goto LAB_00042bf0;
  }
  else if ((M<unsigned int>(iVar14 + 0x98) >> 3 & 1) == 0) {
LAB_00042bf0:
    bVar3 = false;
    goto LAB_00042bf4;
  }
  bVar3 = true;
LAB_00042bf4:
  if (((M<unsigned int>(iVar14 + 0x98) & 0x20000) != 0) && (!bVar3)) {
    return 0;
  }
  if ((bVar1) || (synchronous)) {
    if ((bVar4) && ((M<int>(self + 0xdac) != 0 && (!synchronous)))) {
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
    M<UInt8>(M<int>(bufferBytes + 0x24) + 0x58) = bVar16;
    iVar14 = M<int>(self + 0xd50);
  }
  if (!bVar3) {
    iVar14 = M<int>(iVar14 + 0x8a4);
    bVar16 = (direction == 2) << 1;
    transferMap = (int *)0x0;
    mappedAddress = (void *)0x0;
  }
  else {
    transferMap = (int *)VCALL(*M<int *>(transferBytes + 8), 0x14c)
                               (M<int *>(transferBytes + 8),GH_kernel_task,0,
                                M<unsigned int>(iVar14 + 0x82c) | 1,0,0);
    if (transferMap == (int *)0x0) {
      return 0;
    }
    bVar16 = (direction == 2) << 1;
    iVar14 = VCALL(*transferMap, 0xd0)(transferMap);
    mappedAddress = (void *)(iVar14 + offset);
    if ((bool)(bVar16 >> 1 & 1)) {
      this_00 = M<UInt8 *>(self + 0xd50);
      if ((M<unsigned int>(this_00 + 0x98) & 0x80) != 0) {
        ((IOATIR500Accelerator *)(this_00))->flush_memory_for_out((const void *)(mappedAddress), pitch * h);
        this_00 = M<UInt8 *>(self + 0xd50);
      }
    }
    else {
      this_00 = M<UInt8 *>(self + 0xd50);
      if ((M<unsigned int>(this_00 + 0x98) & 0x80) != 0) {
        ((IOATIR500Accelerator *)(this_00))->flush_memory_for_in((const void *)(mappedAddress), transferSpan);
        this_00 = M<UInt8 *>(self + 0xd50);
      }
    }
    iVar14 = M<int>(this_00 + 0x8a4);
  }
  iVar15 = M<int>(transferBytes + 4);
  if (iVar15 == 0) {
    ((IOATIR500Surface *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(transferBytes));
    iVar15 = M<int>(transferBytes + 4);
  }
  if (flipVertically != 0) {
    if ((int)M<SInt16>(self + 0xbd6) == (int)M<SInt16>(self + 0xbda)) {
      y = ((unsigned int)M<UInt16>(bufferBytes + 0x1e) - y) - h;
    }
    else {
      y = (M<SInt16>(self + 0xbda) - y) - h;
    }
  }
  if ((bool)(bVar16 >> 1 & 1)) {
    uVar19 = (UInt32)(UInt8)bufferBytes[0x3a];
    local_98 = pitch;
    iVar21 = uVar19 * 0x1c;
    srcAddress = iVar14 + offset + iVar15;
    srcWidth = (int)pitch >> (FormatTableLookup_0x0004d2dc(iVar21) >> 0xc & 7);
    if ((bool)(bVar27 >> 1 & 1)) {
      uVar9 = (unsigned int)M<UInt16>(bufferBytes + 0x1e);
    }
    else {
      uVar2 = M<UInt16>(bufferBytes + 0x1e);
      uVar9 = (unsigned int)uVar2;
      if ((uVar2 & 0x1f) != 0) {
        uVar9 = (uVar2 & 0xffffffe0) + 0x20;
      }
    }
    local_64 = (unsigned int)(UInt8)bufferBytes[0x39];
    iVar15 = M<int>(bufferBytes + 8);
    uVar17 = 0;
    srcX = x;
    iVar14 = VCALL(M<int>(self), 0x5f0)(self,bufferBytes,index,level,0,0,local_94);
    uVar18 = (UInt32)(UInt8)bufferBytes[0x3a];
    uVar20 = (UInt32)(UInt8)bufferBytes[0x38];
    dstAddress = iVar15 + iVar14;
    local_68 = 0;
    iVar22 = uVar18 * 0x1c;
    dstX = 0;
    dstY = 0;
    dstPitch = (int)local_94[0] >> (FormatTableLookup_0x0004d2dc(iVar22) >> 0xc & 7);
    iVar14 = y;
  }
  else {
    local_94[0] = pitch;
    uVar18 = (UInt32)(UInt8)bufferBytes[0x3a];
    iVar22 = uVar18 * 0x1c;
    iVar21 = M<int>(bufferBytes + 8);
    dstAddress = iVar14 + offset + iVar15;
    dstPitch = (int)pitch >> (FormatTableLookup_0x0004d2dc(iVar22) >> 0xc & 7);
    local_68 = (unsigned int)(UInt8)bufferBytes[0x39];
    iVar14 = VCALL(M<int>(self), 0x5f0)(self,bufferBytes,index,level,0,0,&local_98);
    srcAddress = iVar21 + iVar14;
    if ((bool)(bVar27 >> 1 & 1)) {
      uVar9 = (unsigned int)M<UInt16>(bufferBytes + 0x1e);
    }
    else {
      uVar2 = M<UInt16>(bufferBytes + 0x1e);
      uVar9 = (unsigned int)uVar2;
      if ((uVar2 & 0x1f) != 0) {
        uVar9 = (uVar2 & 0xffffffe0) + 0x20;
      }
    }
    uVar19 = (UInt32)(UInt8)bufferBytes[0x3a];
    uVar17 = (UInt32)(UInt8)bufferBytes[0x38];
    uVar20 = 0;
    local_64 = 0;
    iVar21 = uVar19 * 0x1c;
    iVar14 = 0;
    srcX = 0;
    srcWidth = (int)local_98 >> (FormatTableLookup_0x0004d2dc(iVar21) >> 0xc & 7);
    dstY = y;
    dstX = x;
  }
  if ((!(bool)(bVar26 >> 1 & 1)) && (!(bool)(bVar27 >> 1 & 1))) {
    uVar17 = 0;
    uVar20 = 0;
  }
  M<unsigned int>((int)Vol(rec0->entries[0].header) + 0x1c) = M<unsigned int>((int)Vol(rec0->entries[0].header) + 0x1c) | 1;
  slot = Vol(rec0->slotIndex) + 1 & 3;
  Vol(rec0->slotIndex) = (UInt16)slot;
  if ((int)Vol(rec0->entries[1 + slot].memory) == 0) {
    iVar15 = ((IOATIR500Surface *)((UInt8 *)self))->allocAllSlaveSwapBuffers(0,Vol(rec0->swapBufferSize));
    if (iVar15 == 0) {
      return 0;
    }
  }
  else {
    piVar23 = M<int *>(self + 0xd50);
    iVar24 = piVar23[0x1e2];
    iVar15 = VCALL(*piVar23, 0x54c)(piVar23,Vol(rec0->entries[1 + slot].stamp));
    piVar23[0x1e2] = iVar24 + iVar15;
  }
  cmd = (UInt32 *)((int)Vol(rec0->entries[1 + slot].header) + 0x20);
  if ((bVar7) || ((bool)((bVar27 & 2) >> 1))) {
    wordCount = 0;
  }
  else {
    wordCount = this->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)(bufferBytes),0,(UInt32 *)(cmd));
  }
  uVar9 = write_3dtexquad_cmds_for_copy_buffer_using_DMA
                    (M<ATIRadeonX1000 *>(self + 0xd50),(UInt32 *)cmd,wordCount,uVar19,srcAddress,local_98,
                     srcWidth,uVar9,uVar17,FormatTableLookup_0x0004d2dc(iVar21) >> 0xc & 7,
                     (UInt8)local_64,uVar18,dstAddress,local_94[0],dstPitch,uVar20,
                     FormatTableLookup_0x0004d2dc(iVar22) >> 0xc & 7,(UInt8)local_68,dstX,dstY,
                     srcX,iVar14,w,h,SUB41m(flipVertically,0));
  if (!(bool)(bVar26 >> 1 & 1)) {
    M<UInt32>(M<int>(self + 0xd50) + 0xb90) = 1;
  }
  M<UInt32>(M<int>(self + 0xd50) + 0x78) = 0;
  paddedWordCount = uVar9;
  if ((uVar9 & 1) != 0) {
    paddedWordCount = uVar9 + 1;
    cmd[uVar9] = 0x80000000;
  }
  M<unsigned int>((int)Vol(rec0->entries[1 + slot].header) + 0x14) = paddedWordCount;
  iVar14 = (int)Vol(rec0->entries[1 + slot].gartOffset);
  sVar8 = M<SInt16>(transferBytes + 0xe) + 1;
  M<SInt16>(transferBytes + 0xe) = sVar8;
  if (iVar14 == 0) {
    ((IOATIR500Surface *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)&rec0->entries[1 + slot]));
    sVar8 = M<SInt16>(transferBytes + 0xe);
    iVar14 = (int)Vol(rec0->entries[1 + slot].gartOffset);
  }
  M<SInt16>(transferBytes + 0xe) = sVar8 + -1;
  submitStamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 0xd50)))->submit_buffer((UInt32 *)((int)Vol(rec0->entries[1 + slot].header) + 0x20),iVar14 + 0x20,
                      M<UInt32>((int)Vol(rec0->entries[1 + slot].header) + 0x14));
  M<UInt32>(self + 0x7c) = submitStamp;
  Vol(rec0->entries[1 + slot].stamp) = submitStamp;
  if ((bool)(bVar26 >> 1 & 1)) {
    VCALL(*M<int *>(self + 0xd50), 0x54c)(M<int *>(self + 0xd50),submitStamp);
    VCALL(*M<int *>(self + 0xd50), 0x5ac)(M<int *>(self + 0xd50),transferBytes);
    if (((bVar3) && (!bVar7)) &&
       ((M<unsigned int>(M<UInt8 *>(self + 0xd50) + 0x98) & 0x80) != 0)) {
      ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0xd50)))->flush_memory_for_in((const void *)(mappedAddress),transferSpan);
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
