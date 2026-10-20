/*
 * ATIR500GLContext_write_kernel_context_buffer_regs_Port.cpp
 *
 * ATIR500GLContext::write_kernel_context_buffer_regs (real addr 0x288e0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x288e0 */
UInt32 ATIR500GLContext::write_kernel_context_buffer_regs(UInt32*outputBuffer, UInt32 wordIndex, UInt32 headerWord0, UInt32 headerWord1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  int attachmentRecords [4];
  int attachmentBuffers [4];
  UInt32 attachmentAddresses [4];
  UInt32 attachmentPitchWords [4];
  int lodBlendWeight;
  int nextMipLevel;
  UInt8 depthFlags1;
  UInt8 depthFlags;
  UInt8 depthFormatId;
  bool notFourPipes;
  UInt8 colorFlags;
  bool hasSamples;
  int hzAlignment;
  int loopLevelOffset0;
  int loopFormatOffset;
  int clearOffset;
  int slotByteOffset;
  int attachmentIndex;
  int numPipes;
  int levelOffset1;
  int accelerator;
  int colorSlotOffset;
  int boundSurface;
  int attachmentOffset;
  int levelOffset0;
  int colorBuffer;
  int colorBaseAddress;
  int clearCount;
  int hzAlignment2;
  int outputSlotOffset;
  int statePacketWord;
  UInt8 *slotCursor;
  UInt8 *depthRecord;
  UInt8 *depthBuffer;
  UInt8 *slotPtr;
  unsigned int colorMinPitch;
  unsigned int depthMinPitch;
  unsigned int loopMinPitch;
  unsigned int hzMinPitch;
  unsigned int recordMinPitch;
  unsigned int loopWidthPerSample;
  unsigned int hzPitch;
  UInt32 hzBlockOffset2;
  UInt32 depthWord2c;
  UInt32 hzEnableWord;
  UInt32 hzAlignedPitch;
  unsigned int recordWidthPerSample;
  unsigned int colorLoopCount;
  unsigned int depthSampleInfo;
  unsigned int hzWidthPerSample;
  UInt32 recordWord30;
  UInt32 depthBaseAddress;
  UInt32 zbBwCntl;
  UInt32 scHyperzEn;
  UInt32 sizeWord;
  UInt32 recordAlignedPitch;
  UInt32 hzBlockOffset0;
  unsigned int mipLevel;
  unsigned int attachmentsLeft2;
  unsigned int mipHeight;
  UInt32 hzAlignedPitch2;
  UInt16 slotBufferIndex;
  UInt16 colorPitchBytes;
  UInt16 colorBytesPerPixel;
  unsigned int attachmentsLeft;
  unsigned int colorWidthPerSample;
  unsigned int colorTiledBit;
  unsigned int depthWidthPerSample;
  unsigned int hzBlockOffset1;
  unsigned int widthField;
  
  clearCount = 4;
  clearOffset = 0;
  do {
    M<UInt32>((int)attachmentRecords + clearOffset) = 0;
    M<UInt32>((int)attachmentBuffers + clearOffset) = 0;
    M<UInt32>((int)attachmentAddresses + clearOffset) = 0;
    M<UInt32>((int)attachmentPitchWords + clearOffset) = 0;
    clearOffset = clearOffset + 4;
    clearCount = clearCount + -1;
  } while (clearCount != 0);
  if (M<int>(self + kATIR500GLContext_renderToTexture) == 0) {
    attachmentsLeft = (unsigned int)M<UInt16>(self + kATIR500GLContext_attachmentCount);
    lodBlendWeight = M<int>(self + kIOATIR500GLContext_surfaceIndex);
    mipLevel = M<unsigned int>(self + kIOATIR500GLContext_mipLevel);
    if (attachmentsLeft == 0) {
      boundSurface = M<int>(self + kIOATIR500GLContext_boundSurface);
    }
    else {
      boundSurface = M<int>(self + kIOATIR500GLContext_boundSurface);
      slotByteOffset = 0;
      slotCursor = self;
      do {
        slotBufferIndex = M<UInt16>(slotCursor + 0x3aa);
        slotCursor = slotCursor + 2;
        M<unsigned int>((int)attachmentRecords + slotByteOffset) = (unsigned int)slotBufferIndex * 0x78 + boundSurface + kIOATIR500Surface_buffers;
        M<UInt32>((int)attachmentBuffers + slotByteOffset) = M<UInt32>((unsigned int)slotBufferIndex * 4 + boundSurface + kIOATIR500Surface_attachmentBuffers);
        slotByteOffset = slotByteOffset + 4;
        attachmentsLeft = attachmentsLeft - 1;
      } while (attachmentsLeft != 0);
    }
    nextMipLevel = mipLevel + 1;
    depthBuffer = M<UInt8 *>((unsigned int)M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) * 4 + boundSurface + kIOATIR500Surface_attachmentBuffers);
    depthRecord = (UInt8 *)((unsigned int)M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) * 0x78 + boundSurface + kIOATIR500Surface_buffers);
  }
  else {
    attachmentsLeft2 = (unsigned int)M<UInt16>(self + kATIR500GLContext_attachmentCount);
    if (attachmentsLeft2 != 0) {
      attachmentIndex = 0;
      outputSlotOffset = 0;
      slotCursor = self;
      do {
        attachmentOffset = attachmentIndex * 0x78;
        attachmentIndex = attachmentIndex + 1;
        M<UInt8 *>((int)attachmentRecords + outputSlotOffset) = self + attachmentOffset + 0x3c0;
        slotPtr = slotCursor + 0x3b2;
        slotCursor = slotCursor + 2;
        M<UInt8 *>((int)attachmentBuffers + outputSlotOffset) =
             self + (unsigned int)M<UInt16>(slotPtr) * 0x78 + 0x3c0;
        outputSlotOffset = outputSlotOffset + 4;
        attachmentsLeft2 = attachmentsLeft2 - 1;
      } while (attachmentsLeft2 != 0);
    }
    depthBuffer = self + kATIR500GLContext_textureDepthBuffer;
    lodBlendWeight = 0;
    mipLevel = 0;
    nextMipLevel = 1;
    depthRecord = depthBuffer;
  }
  outputBuffer[wordIndex] = 0x13c6;
  outputBuffer[wordIndex + 1] = 3;
  outputBuffer[wordIndex + 2] = 0xd0b;
  outputBuffer[wordIndex + 3] = 5;
  outputBuffer[wordIndex + 4] = 0x1393;
  outputBuffer[wordIndex + 5] = 10;
  outputBuffer[wordIndex + 6] = 0x1006;
  statePacketWord = wordIndex + 8;
  accelerator = M<int>(self + kIOATIR500GLContext_accelerator);
  outputBuffer[wordIndex + 7] = M<UInt32>(accelerator + kIOATIR500Accelerator_gbTileConfig);
  colorWidthPerSample = 0;
  levelOffset0 = M<int>(mipLevel * 4 + attachmentBuffers[0] + 0x40);
  levelOffset1 = M<int>(nextMipLevel * 4 + attachmentBuffers[0] + 0x40);
  colorPitchBytes = M<UInt16>(attachmentBuffers[0] + 0x20);
  colorBaseAddress = M<int>(attachmentBuffers[0] + 8);
  if ((M<unsigned int>(attachmentBuffers[0] + 0x3c) & 0xf00000) != 0) {
    colorWidthPerSample = (unsigned int)M<UInt16>(attachmentBuffers[0] + 0x14) / (M<unsigned int>(attachmentBuffers[0] + 0x3c) >> 0x14 & 0xf);
  }
  colorBytesPerPixel = M<UInt16>(attachmentBuffers[0] + 0x16);
  colorMinPitch = 0x20 / colorBytesPerPixel;
  if (colorMinPitch <= colorWidthPerSample) {
    colorMinPitch = colorWidthPerSample;
  }
  colorFlags = M<UInt8>(attachmentBuffers[0] + 0x38);
  colorTiledBit = 0x80000000;
  if (colorFlags < 2) {
    colorTiledBit = 0;
  }
  recordWidthPerSample = 0;
  recordWord30 = M<UInt32>(attachmentRecords[0] + 0x30);
  if ((M<unsigned int>(attachmentRecords[0] + 0x3c) & 0xf00000) != 0) {
    recordWidthPerSample = (unsigned int)M<UInt16>(attachmentRecords[0] + 0x14) / (M<unsigned int>(attachmentRecords[0] + 0x3c) >> 0x14 & 0xf);
  }
  recordMinPitch = 0x20 / M<UInt16>(attachmentRecords[0] + 0x16);
  if (recordMinPitch <= recordWidthPerSample) {
    recordMinPitch = recordWidthPerSample;
  }
  hzAlignment = 0x20;
  if (M<int>(accelerator + kIOATIR500Accelerator_numPipes) == 4) {
alignRecordPitch:
    recordAlignedPitch = hzAlignment * ((int)(recordMinPitch + hzAlignment + -1) / hzAlignment);
  }
  else {
    hzAlignment = M<int>(accelerator + kIOATIR500Accelerator_numPipes) << 4;
    recordAlignedPitch = 0;
    if (hzAlignment != 0) goto alignRecordPitch;
  }
  hzBlockOffset2 = HZMEM_GetBlockOffset((_HZDATA *)((UInt8 *)(accelerator + kIOATIR500Accelerator_hzmem)),M<UInt32>(attachmentRecords[0] + 0x28),2);
  if (((((M<unsigned int>(attachmentRecords[0] + 0x28) & 0x3ff00000) == 0x3ff00000) ||
       (M<char>(attachmentRecords[0] + 0x36) == '\0')) ||
      ((M<unsigned int>(M<int>(self + kIOATIR500GLContext_boundSurface) + 0xbe8) & 0x700000) == 0)) ||
     (hzEnableWord = 0x600, M<SInt16>(self + kIOATIR500GLContext_colorBufferIndex) != 9)) {
    hzEnableWord = 0;
  }
  colorLoopCount = (unsigned int)M<UInt16>(self + kATIR500GLContext_attachmentCount);
  if (colorLoopCount != 0) {
    colorSlotOffset = 0;
    if (colorLoopCount == 0) {
      colorLoopCount = 1;
    }
    do {
      colorBuffer = M<int>((int)attachmentBuffers + colorSlotOffset);
      loopWidthPerSample = 0;
      loopLevelOffset0 = M<int>(mipLevel * 4 + colorBuffer + 0x40);
      M<unsigned int>((int)attachmentAddresses + colorSlotOffset) =
           loopLevelOffset0 * (unsigned int)M<UInt16>(colorBuffer + 0x20) +
           lodBlendWeight * (M<int>(nextMipLevel * 4 + colorBuffer + 0x40) - loopLevelOffset0) + M<int>(colorBuffer + 8);
      loopFormatOffset = (unsigned int)M<UInt8>(colorBuffer + 0x3a) * 0x1c;
      if ((M<unsigned int>(colorBuffer + 0x3c) & 0xf00000) != 0) {
        loopWidthPerSample = (int)((unsigned int)M<UInt16>(colorBuffer + 0x14) / (M<unsigned int>(colorBuffer + 0x3c) >> 0x14 & 0xf))
                 >> (mipLevel & 0x3f);
      }
      loopMinPitch = 0x20 / M<UInt16>(colorBuffer + 0x16);
      if (loopMinPitch <= loopWidthPerSample) {
        loopMinPitch = loopWidthPerSample;
      }
      M<unsigned int>((int)attachmentPitchWords + colorSlotOffset) =
           FormatTableLookup_0x0004d2e0(loopFormatOffset) >> 1 & 0x1e00000 |
           (FormatTableLookup_0x0004d2dc(loopFormatOffset) & 0xc00) << 9 |
           (M<UInt8>(colorBuffer + 0x38) & 6) << 0x10 |
           (M<UInt8>(colorBuffer + 0x38) & 1) << 0x10 | loopMinPitch & 0x3ffe;
      colorSlotOffset = colorSlotOffset + 4;
      colorLoopCount = colorLoopCount - 1;
    } while (colorLoopCount != 0);
  }
  outputBuffer[statePacketWord] = 0x50b;
  outputBuffer[wordIndex + 9] =
       colorTiledBit | levelOffset0 * (unsigned int)colorPitchBytes + lodBlendWeight * (levelOffset1 - levelOffset0) + colorBaseAddress >> 10 |
               colorMinPitch * colorBytesPerPixel * 0x10000 & 0x3fc00000 | (colorFlags & 1) << 0x1e;
  outputBuffer[wordIndex + 10] = 0x3138a;
  outputBuffer[wordIndex + 0xb] = attachmentAddresses[0];
  outputBuffer[wordIndex + 0xc] = attachmentAddresses[1];
  outputBuffer[wordIndex + 0xd] = attachmentAddresses[2];
  outputBuffer[wordIndex + 0xe] = attachmentAddresses[3];
  outputBuffer[wordIndex + 0xf] = 0x3138e;
  outputBuffer[wordIndex + 0x10] = attachmentPitchWords[0];
  outputBuffer[wordIndex + 0x11] = attachmentPitchWords[1];
  outputBuffer[wordIndex + 0x12] = attachmentPitchWords[2];
  outputBuffer[wordIndex + 0x13] = attachmentPitchWords[3];
  outputBuffer[wordIndex + 0x14] = 0x1380;
  outputBuffer[wordIndex + 0x15] = hzEnableWord;
  outputBuffer[wordIndex + 0x16] = 0x1385;
  outputBuffer[wordIndex + 0x17] = recordWord30;
  outputBuffer[wordIndex + 0x18] = 0x1395;
  outputBuffer[wordIndex + 0x19] = hzBlockOffset2;
  outputBuffer[wordIndex + 0x1a] = 0x1399;
  outputBuffer[wordIndex + 0x1b] = recordAlignedPitch;
  depthBaseAddress = M<UInt32>(depthRecord + 8);
  depthWidthPerSample = 0;
  if ((M<unsigned int>(depthBuffer + 0x3c) & 0xf00000) != 0) {
    depthWidthPerSample = (unsigned int)M<UInt16>(depthBuffer + 0x14) / (M<unsigned int>(depthBuffer + 0x3c) >> 0x14 & 0xf);
  }
  depthMinPitch = 0x20 / M<UInt16>(depthBuffer + 0x16);
  if (0x20 / M<UInt16>(depthBuffer + 0x16) <= depthWidthPerSample) {
    depthMinPitch = depthWidthPerSample;
  }
  depthFlags1 = depthBuffer[0x39];
  depthFlags = depthBuffer[0x38];
  depthFormatId = depthRecord[0x3a];
  depthWord2c = M<UInt32>(depthRecord + 0x2c);
  hzBlockOffset0 = HZMEM_GetBlockOffset
                     ((_HZDATA *)((UInt8 *)(M<int>(self + kIOATIR500GLContext_accelerator) + 0x870)),M<UInt32>(depthRecord + 0x28),0);
  hzBlockOffset1 = HZMEM_GetBlockOffset
                    ((_HZDATA *)((UInt8 *)(M<int>(self + kIOATIR500GLContext_accelerator) + 0x870)),M<UInt32>(depthRecord + 0x28),1);
  numPipes = M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0xb98);
  notFourPipes = numPipes != 4;
  if (!notFourPipes) {
    hzBlockOffset1 = hzBlockOffset1 >> 1;
  }
  depthSampleInfo = M<unsigned int>(depthRecord + 0x3c);
  hasSamples = (depthSampleInfo & 0xf00000) != 0;
  if (hasSamples) {
    hzPitch = (unsigned int)M<UInt16>(depthRecord + 0x14) / (depthSampleInfo >> 0x14 & 0xf);
  }
  else {
    hzPitch = 0;
  }
  hzMinPitch = 0x20 / M<UInt16>(depthRecord + 0x16);
  if (hzPitch < hzMinPitch) {
    hzPitch = hzMinPitch;
  }
  if (notFourPipes) {
    hzAlignment2 = numPipes << 4;
    hzAlignedPitch = 0;
    if (hzAlignment2 != 0) goto alignHzPitch;
  }
  else {
    hzAlignment2 = 0x20;
alignHzPitch:
    hzAlignedPitch = ((int)(hzPitch + hzAlignment2 + -1) / hzAlignment2) * hzAlignment2;
  }
  if (hasSamples) {
    hzWidthPerSample = (unsigned int)M<UInt16>(depthRecord + 0x14) / (depthSampleInfo >> 0x14 & 0xf);
  }
  else {
    hzWidthPerSample = 0;
  }
  if (hzMinPitch <= hzWidthPerSample) {
    hzMinPitch = hzWidthPerSample;
  }
  if (notFourPipes) {
    numPipes = numPipes << 4;
    hzAlignedPitch2 = 0;
    if (numPipes == 0) goto hzPitchDone;
  }
  else {
    numPipes = 0x20;
  }
  hzAlignedPitch2 = ((int)(hzMinPitch + numPipes + -1) / numPipes) * numPipes;
hzPitchDone:
  outputBuffer[wordIndex + 0x1c] = 0x113c8;
  outputBuffer[wordIndex + 0x1d] = depthBaseAddress;
  outputBuffer[wordIndex + 0x1e] =
       ((UInt8)depthFlags & 6) << 0x10 |
       ((UInt8)depthFlags & 1) << 0x10 | ((UInt8)depthFlags1 & 3) << 0x13 | depthMinPitch & 0x3ffc;
  outputBuffer[wordIndex + 0x1f] = 0x13d8;
  outputBuffer[wordIndex + 0x20] = 0;
  outputBuffer[wordIndex + 0x21] = 0x13c4;
  outputBuffer[wordIndex + 0x22] = -((UInt8)depthFormatId ^ 0x10) >> 0x1e & 2;
  outputBuffer[wordIndex + 0x23] = 0x13ca;
  outputBuffer[wordIndex + 0x24] = depthWord2c;
  outputBuffer[wordIndex + 0x25] = 0x13c7;
  zbBwCntl = this->compute_zb_bw_cntl(headerWord1);
  outputBuffer[wordIndex + 0x26] = zbBwCntl;
  outputBuffer[wordIndex + 0x27] = 0x13cc;
  outputBuffer[wordIndex + 0x28] = hzBlockOffset0;
  outputBuffer[wordIndex + 0x29] = 0x13cd;
  outputBuffer[wordIndex + 0x2a] = hzAlignedPitch;
  outputBuffer[wordIndex + 0x2b] = 0x10e9;
  scHyperzEn = this->compute_sc_hyperz_en(headerWord0);
  outputBuffer[wordIndex + 0x2c] = scHyperzEn;
  outputBuffer[wordIndex + 0x2d] = 0x13d1;
  outputBuffer[wordIndex + 0x2e] = hzBlockOffset1;
  outputBuffer[wordIndex + 0x2f] = 0x13d5;
  outputBuffer[wordIndex + 0x30] = hzAlignedPitch2;
  if (M<int>(self + kATIR500GLContext_renderToTexture) == 0) {
    if ((attachmentBuffers[0] == M<int>(self + kIOATIR500GLContext_boundSurface) + 0x4e0) &&
       ((M<unsigned int>(M<int>(self + kIOATIR500GLContext_boundSurface) + 0xbe8) & 0x700000) != 0)) {
      if ((M<unsigned int>(attachmentBuffers[0] + 0x3c) & 0xf00000) == 0) {
        widthField = 0;
      }
      else {
        widthField = (unsigned int)M<UInt16>(attachmentBuffers[0] + 0x1c) /
                (M<unsigned int>(attachmentBuffers[0] + 0x3c) >> 0x14 & 0xf) & 0x1fff;
      }
    }
    else {
      if (((M<unsigned int>(attachmentBuffers[0] + 0x3c) & 0xf00000) == 0) ||
         (widthField = (int)((unsigned int)M<UInt16>(attachmentBuffers[0] + 0x1c) /
                       (M<unsigned int>(attachmentBuffers[0] + 0x3c) >> 0x14 & 0xf)) >> (mipLevel & 0x3f), widthField == 0
         )) {
        widthField = 1;
      }
      widthField = widthField & 0x1fff;
    }
    mipHeight = (int)(unsigned int)M<UInt16>(attachmentBuffers[0] + 0x1e) >> (mipLevel & 0x3f);
    if (mipHeight == 0) {
      mipHeight = 1;
    }
    sizeWord = (mipHeight & 0x1fff) << 0xd | widthField;
  }
  else {
    sizeWord = (M<UInt16>(attachmentRecords[0] + 0x1e) & 0x1fff) << 0xd |
             M<UInt16>(attachmentRecords[0] + 0x1c) & 0x1fff;
  }
  outputBuffer[wordIndex + 0x31] = 0x110ec   /* PM4 type-0 header word (1 register at 0x10ec); Ghidra labels the constant as a data address */;
  outputBuffer[wordIndex + 0x32] = 0;
  outputBuffer[wordIndex + 0x33] = sizeWord;
  outputBuffer[wordIndex + 0x34] = 0x10f4;
  outputBuffer[wordIndex + 0x35] = 0xaaaa;
  outputBuffer[wordIndex + 0x36] = 0x105bb;
  outputBuffer[wordIndex + 0x37] = M<UInt32>(self + kATIR500GLContext_scissorY);
  outputBuffer[wordIndex + 0x38] = M<UInt32>(self + kATIR500GLContext_scissorX);
  return wordIndex + 0x39;
}
