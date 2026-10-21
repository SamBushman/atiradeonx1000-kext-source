/*
 * ATIRadeonX1000_pageoff_dirty_texture_with_gpu_Port.cpp
 *
 * ATIRadeonX1000::pageoff_dirty_texture_with_gpu (real addr 0x210f0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x210f0 */
UInt32 ATIRadeonX1000::pageoff_dirty_texture_with_gpu(VendorTextureBuffer *texture, ATITextureBufferHeader *hwInfo) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);
    UInt8 *hwInfoBytes = reinterpret_cast<UInt8 *>(hwInfo);

  UInt8 faceCount;
  UInt8 formatBits;
  bool macroTiled;
  UInt8 tileFlags;
  unsigned int heightAtLevel;
  unsigned int baseLevel;
  unsigned int lastLevel;
  SInt16 mapCount;
  int vramBase;
  unsigned int halfWidth;
  int repeat;
  UInt32 stamp;
  UInt32 wordCount;
  UInt8 *tileRecord;
  int waitStampResult;
  UInt8 *tileOut;
  UInt8 type;
  unsigned int levelWidth;
  unsigned int levelHeight;
  int macroTileHeightShift;
  unsigned int face;
  unsigned int minHeight;
  unsigned int minWidth;
  int vramOffset;
  UInt8 *record;
  unsigned int texFlags;
  unsigned int level;
  int tileVramOffset;
  UInt8 *innerBuffer;
  int gartOffset;
  int size;
  int textureInfo;
  int mapResult;
  int bufferGartOffset;
  int negTileBits;
  int macroTileWidthShift;
  int macroTileBit;
  int tileGartAddress;
  int emptyWordOffset;
  int waitTimeBefore;
  int infoBlock;
  unsigned int heightRows;
  unsigned int halfHeight;
  unsigned int packetWord;
  unsigned int pixelShift;
  
  textureInfo = M<int>(textureBytes + 0x14);
  vramOffset = M<int>(textureBytes + 0x48);
  baseLevel = (unsigned int)M<UInt8>(textureInfo + 0x17);
  faceCount = M<UInt8>(textureInfo + 0x34);
  lastLevel = (baseLevel + M<UInt8>(textureInfo + 0x35)) - 1;
  if (textureBytes[0x20] == 0x3) {
    type = 0x3;
    if (M<int>(textureBytes + 4) == 0) {
      /* #153: real disassembly (addr 0x21158) confirms this first 0x5a8 call explicitly loads
       * only r3 (this) - r4 (textureBytes) is unclobbered since function entry, so it's still the real
       * buffer value here. The retry below (second 0x5a8 call) DOES reload r4 explicitly in the
       * real binary, because the intervening freeToAllocGART call clobbers it - that one was
       * already correctly ported with the textureBytes argument; only this first, bare occurrence
       * was missing it (same defect class as pageoff_linear_buffer and the four
       * map_transfer_to_GART overrides). */
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
      textureInfo = M<int>(textureBytes + 0x14);
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
                              (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),(VendorTransferBuffer *)(innerBuffer)), mapResult == 0))
      {
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
    textureInfo = M<int>(textureBytes + 0x14);
    type = textureBytes[0x20];
    storeHalf(&M<UInt16>(innerBuffer + 0xe), mapCount + -1);
  }
  if (type == 0x7) {
    size = M<int>(textureBytes + 0x50);
    gartOffset = M<int>(M<int>(textureBytes + 0x58) + 4);
  }
  else {
    size = M<int>(textureBytes + 0x50);
    gartOffset = M<int>(textureBytes + 4);
  }
  waitTimeBefore = M<int>(self + kIOATIR500Accelerator_texturePageOutWaitTime);
  waitStampResult = VCALL(M<int>(self), 0x54c)(self,M<UInt32>(textureInfo + 0xc));
  vramBase = M<int>(self + kIOATIR500Accelerator_vramSizeProgrammed);
  M<int>(self + kIOATIR500Accelerator_texturePageOutWaitTime) = waitTimeBefore + waitStampResult;
  record = hwInfoBytes + M<int>(hwInfoBytes + 4) * 4 + 0xa00;
  M<UInt32>(record + 0x2c) = M<UInt32>(self + kIOATIR500Accelerator_gbTileConfig);
  infoBlock = M<int>(textureBytes + 0x14);
  tileFlags = M<UInt8>(infoBlock + 0x15) >> 3;
  negTileBits = -(tileFlags & 3);
  if ((tileFlags & 2) == 0) {
    if (-1 < negTileBits) {
      macroTiled = false;
      goto LAB_000214a0;
    }
    pixelShift = (unsigned int)(UInt8)hwInfoBytes[0x1a];
    macroTiled = pixelShift == 0;
LAB_000214a8:
    if (pixelShift < 4) {
      if (macroTiled) {
        macroTileHeightShift = 2;
        macroTileWidthShift = 3;
      }
      else {
        macroTileHeightShift = 1;
        macroTileWidthShift = 4;
      }
      goto LAB_000214e0;
    }
  }
  else {
    macroTiled = true;
LAB_000214a0:
    if (negTileBits < 0) {
      pixelShift = (unsigned int)(UInt8)hwInfoBytes[0x1a];
      goto LAB_000214a8;
    }
    pixelShift = (unsigned int)(UInt8)hwInfoBytes[0x1a];
  }
  macroTileHeightShift = 0;
  macroTileWidthShift = 5;
LAB_000214e0:
  face = 0;
  minWidth = 1 << (macroTileWidthShift - pixelShift & 0x3f);
  minHeight = 0x20 >> (pixelShift & 0x3f);
  if (faceCount != 0) {
    while( true ) {
      texFlags = (unsigned int)M<UInt8>(infoBlock + 0x15);
      levelHeight = M<unsigned int>(hwInfoBytes + 0x10) >> (pixelShift & 0x3f);
      levelWidth = M<unsigned int>(hwInfoBytes + 0xc) >> (pixelShift & 0x3f);
      if (baseLevel <= lastLevel) {
        tileRecord = hwInfoBytes + baseLevel * 0x20 + face * 0x1a0 + 0x40;
        level = baseLevel;
        do {
          tileOut = record + (unsigned int)M<UInt16>(tileRecord + 0x18) * 4;
          if ((texFlags & 4) != 0) {
            heightAtLevel = (int)(unsigned int)M<UInt16>(hwInfoBytes + 0x16) >> (level & 0x3f);
            heightRows = 1 << macroTileHeightShift;
            if (1 << macroTileHeightShift < (int)heightAtLevel) {
              heightRows = heightAtLevel;
            }
            if ((levelWidth < minWidth << 3) || (macroTileBit = 1, heightRows < (unsigned int)(1 << macroTileHeightShift + 3))) {
              macroTileBit = 0;
            }
            texFlags = macroTileBit << 2 | texFlags & 0xfffffffb;
          }
          tileGartAddress = M<int>(tileRecord + 4);
          tileVramOffset = M<int>(tileRecord + 8);
          halfHeight = levelHeight >> 1;
          M<UInt32>(tileOut) = 0x138a;
          if (M<SInt16>(tileRecord + 2) != 0) {
            repeat = 0;
            do {
              packetWord = M<unsigned int>(tileOut + 0xc);
              repeat = repeat + 1;
              M<int>(tileOut + 4) = tileGartAddress + gartOffset + vramBase;
              M<unsigned int>(tileOut + 0xc) = packetWord & 0xfff8ffff;
              formatBits = hwInfoBytes[0x1b];
              M<unsigned int>(tileOut + 0x24) =
                   levelWidth - 1 & 0x3fff | M<unsigned int>(tileOut + 0x24) & 0xffffc000;
              M<unsigned int>(tileOut + 0x14) =
                   tileVramOffset + vramOffset & 0xffffffe0U | (texFlags >> 3 & 3) << 3 | (texFlags >> 2 & 1) << 2;
              M<unsigned int>(tileOut + 0xc) =
                   (halfHeight & 0x1fff) << 1 | ((UInt8)formatBits & 3) << 0x13 | packetWord & 0xffe0c001;
              tileOut = tileOut + 0x74;
              tileGartAddress = tileGartAddress + M<int>(tileRecord + 0xc);
              tileVramOffset = tileVramOffset + M<int>(tileRecord + 0x10);
            } while (repeat < (int)(unsigned int)M<UInt16>(tileRecord + 2));
          }
          levelHeight = minHeight;
          if (minHeight < halfHeight) {
            levelHeight = halfHeight;
          }
          halfWidth = levelWidth >> 1;
          levelWidth = minWidth;
          if (minWidth < halfWidth) {
            levelWidth = halfWidth;
          }
          level = level + 1;
          tileRecord = tileRecord + 0x20;
        } while (level <= lastLevel);
      }
      face = face + 1;
      if (faceCount <= face) break;
      infoBlock = M<int>(textureBytes + 0x14);
      pixelShift = (unsigned int)(UInt8)hwInfoBytes[0x1a];
    }
  }
  wordCount = M<UInt32>(hwInfoBytes + 8);
  M<UInt32>(self + kIOATIR500Accelerator_stateDestroyedByPageoff) = 1;
  M<UInt32>(self + kIOATIR500Accelerator_unknown_0x78) = 0;
  if ((wordCount & 1) != 0) {
    emptyWordOffset = wordCount * 4;
    wordCount = wordCount + 1;
    M<UInt32>(record + emptyWordOffset) = 0x80000000;
  }
  M<UInt32>(self + kIOATIR500Accelerator_commandGLBytesPerSample) = wordCount * 4 + M<int>(self + kIOATIR500Accelerator_commandGLBytesPerSample);
  M<int>(self + kIOATIR500Accelerator_texturePageOutBytesPerSample) = size + M<int>(self + kIOATIR500Accelerator_texturePageOutBytesPerSample);
  textureInfo = M<int>(textureBytes + 0x14);
  stamp = this->submit_buffer((UInt32 *)record,
                         M<int>(hwInfoBytes + 4) * 4 + M<int>(textureBytes + 4) + 0xa00,wordCount);
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
