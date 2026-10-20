/*
 * ATIR500GLContext_load_texture_Port.cpp
 *
 * ATIR500GLContext::load_texture (real addr 0x29480, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOGetTime(...) asm("_IOGetTime");


/* real addr 0x29480 */
void ATIR500GLContext::load_texture(VendorTextureBuffer *texture) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);

  UInt16 loadedBits;
  UInt16 dirtyBits;
  SInt32 *mapping;
  SInt32 *hwInfo;
  SInt32 nextMipLevel;
  SInt32 waited;
  UInt32 *record;
  UInt32 *tileCursor;
  SInt32 gartAddress;
  SInt32 gartOffset;
  SInt32 nextNode;
  UInt8 *currentSurfaceBuffer;
  SInt32 textureOffset;
  SInt32 lodBlendWeight;
  UInt32 lastLevel;
  SInt32 *accelerator;
  SInt32 mipLevel;
  SInt32 waitTotal;
  UInt8 *innerBuffer;
  SInt32 payloadByteLen;
  SInt32 header;
  SInt32 recordIndex;
  UInt32 faceCount;
  UInt32 samplePitch;
  UInt32 totalWords;
  UInt32 firstLevel;
  UInt32 pitchPixels;
  UInt32 paddedWords;
  UInt32 macroTileFlag;
  UInt32 faceIndex;
  UInt32 blockShift;
  UInt32 curWidth;
  UInt32 halfHeight;
  UInt32 minDim;
  UInt32 halfWidth;
  UInt32 levelIndex;
  UInt32 minHeight;
  UInt32 sliceCount;
  UInt32 tileFace;
  UInt32 slotIndex;
  UInt32 minWidth;
  SInt32 levelRecord;
  SInt32 blockLog2;
  SInt32 faceBitsOffset;
  SInt32 faceBits;
  SInt32 negTileMode;
  SInt32 tileSizeLog2;
  SInt32 levelRecordOffset;
  SInt32 gartLevelOffset;
  SInt32 gartSlot;
  SInt32 bigTileFlag;
  SInt32 textureLevelCursor;
  SInt32 offsetSlot;
  SInt32 sliceIndex;
  SInt32 headerBase;
  SInt32 faceHeader;
  SInt32 gartLevelCursor;
  UInt8 tileModeBits;
  UInt8 swizzleBits;
  bool needsLoad;
  bool useSmallBlock;
  UInt32 submitStamp;
  UInt32 levelDim;
  UInt32 tileFlags;
  UInt32 levelHeight;
  UInt32 mipIndex;
  SInt32 textureLevelOffset;
  
  header = M<SInt32>(textureBytes + 0x14);
  textureOffset = M<SInt32>(textureBytes + 0x48);
  faceCount = (UInt32)M<UInt8>(header + 0x34);
  firstLevel = (UInt32)M<UInt8>(header + 0x17);
  lastLevel = (firstLevel + M<UInt8>(header + 0x35)) - 1;
  if (faceCount == 0) {
    return;
  }
  faceIndex = 0;
  needsLoad = false;
  do {
    if (firstLevel <= lastLevel) {
      levelIndex = firstLevel;
      do {
        if ((((UInt32)M<UInt16>(header + 0x1c) & ~(UInt32)M<UInt16>(header + 0x28)) >>
             (levelIndex & 0x3f) & 1) != 0) {
          needsLoad = true;
        }
        levelIndex = levelIndex + 1;
      } while (levelIndex <= lastLevel);
    }
    faceIndex = faceIndex + 1;
    header = header + 2;
  } while (faceIndex < faceCount);
  if (!needsLoad) {
    return;
  }
  mapping = (SInt32 *)VCALL(*M<SInt32 *>(textureBytes + 8), 0x14c)
                            (M<SInt32 *>(textureBytes + 8),GH_kernel_task,0,
                             M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x82c) | 1,0,0);
  if (mapping == (SInt32 *)0x0) {
    return;
  }
  hwInfo = (SInt32 *)VCALL(*mapping, 0xd0)(mapping);
  if (textureBytes[0x20] == 0x3) {
    if ((M<SInt32>(textureBytes + 4) != 0) ||
       (((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)textureBytes)),
       M<SInt32>(textureBytes + 4) != 0)) {
      GH_IOGetTime(textureBytes + 0x2c);
      nextNode = M<SInt32>(textureBytes + 0x34);
      M<UInt32>(nextNode + 0x38) = M<UInt32>(textureBytes + 0x38);
      M<SInt32>(M<SInt32>(textureBytes + 0x38) + 0x34) = nextNode;
      M<UInt32>(textureBytes + 0x34) = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x6d0);
      M<SInt32>(textureBytes + 0x38) = M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x69c;
      M<UInt8 *>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x6d0) = textureBytes;
      M<UInt8 *>(M<SInt32>(textureBytes + 0x34) + 0x38) = textureBytes;
    }
checkInnerTransfer:
    if (textureBytes[0x20] != 0x7) goto ownTransfer;
    payloadByteLen = M<SInt32>(textureBytes + 0x50);
    gartAddress = M<SInt32>(M<SInt32>(textureBytes + 0x58) + 4);
  }
  else {
    if (textureBytes[0x20] == 0x7) {
      innerBuffer = M<UInt8 *>(textureBytes + 0x58);
      if (M<SInt32>(innerBuffer + 4) == 0) {
        ((IOATIR500GLContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(innerBuffer));
      }
      if (M<SInt32>(textureBytes + 4) == 0) {
        M<SInt16>(innerBuffer + 0xe) = M<SInt16>(innerBuffer + 0xe) + 1;
        ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)textureBytes));
        gartOffset = M<SInt32>(textureBytes + 4);
        M<SInt16>(innerBuffer + 0xe) = M<SInt16>(innerBuffer + 0xe) + -1;
        if (gartOffset != 0) goto moveToListHead;
      }
      else {
moveToListHead:
        GH_IOGetTime(textureBytes + 0x2c);
        nextNode = M<SInt32>(textureBytes + 0x34);
        M<UInt32>(nextNode + 0x38) = M<UInt32>(textureBytes + 0x38);
        M<SInt32>(M<SInt32>(textureBytes + 0x38) + 0x34) = nextNode;
        M<UInt32>(textureBytes + 0x34) = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x6d0);
        M<SInt32>(textureBytes + 0x38) = M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x69c;
        M<UInt8 *>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x6d0) = textureBytes;
        M<UInt8 *>(M<SInt32>(textureBytes + 0x34) + 0x38) = textureBytes;
      }
      if (M<SInt32>(innerBuffer + 4) != 0) {
        GH_IOGetTime(innerBuffer + 0x2c);
        nextNode = M<SInt32>(innerBuffer + 0x34);
        M<UInt32>(nextNode + 0x38) = M<UInt32>(innerBuffer + 0x38);
        M<SInt32>(M<SInt32>(innerBuffer + 0x38) + 0x34) = nextNode;
        M<UInt32>(innerBuffer + 0x34) = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x6d0);
        M<SInt32>(innerBuffer + 0x38) = M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x69c;
        M<UInt8 *>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x6d0) = innerBuffer;
        M<UInt8 *>(M<SInt32>(innerBuffer + 0x34) + 0x38) = innerBuffer;
      }
      goto checkInnerTransfer;
    }
ownTransfer:
    payloadByteLen = M<SInt32>(textureBytes + 0x50);
    gartAddress = M<SInt32>(textureBytes + 4);
  }
  accelerator = M<SInt32 *>(self + kIOATIR500GLContext_accelerator);
  waitTotal = accelerator[0x1d5];
  waited = VCALL(*accelerator, 0x54c)(accelerator,M<UInt32>(M<SInt32>(textureBytes + 0x14) + 0xc));
  record = (UInt32 *)(hwInfo + 0x280);
  accelerator[0x1d5] = waitTotal + waited;
  gartAddress = gartAddress + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x8a4);
  if (hwInfo[8] < 0) {
    if (M<SInt32>(textureBytes + 100) == 2) {
      hwInfo[0x285] = 1;
      faceIndex = 0;
    }
    else {
      faceIndex = 0;
      if (M<SInt32>(textureBytes + 100) == 4) {
        hwInfo[0x285] = 2;
        faceIndex = 0;
      }
    }
    do {
      if (lastLevel < firstLevel) {
        headerBase = M<SInt32>(textureBytes + 0x14);
        faceBitsOffset = faceIndex << 1;
      }
      else {
        headerBase = M<SInt32>(textureBytes + 0x14);
        faceBitsOffset = faceIndex * 2;
        loadedBits = M<UInt16>(faceBitsOffset + headerBase + 0x28);
        dirtyBits = M<UInt16>(faceBitsOffset + headerBase + 0x1c);
        levelIndex = firstLevel;
        do {
          levelRecord = faceIndex * 0xd + levelIndex;
          slotIndex = (UInt32)M<UInt16>(hwInfo + levelRecord * 8 + 0x10);
          sliceCount = (UInt32)M<UInt16>((SInt32)hwInfo + levelRecord * 0x20 + 0x42);
          gartLevelOffset = hwInfo[levelRecord * 8 + 0x11];
          gartSlot = slotIndex + 4;
          offsetSlot = slotIndex + 7;
          textureLevelOffset = hwInfo[levelRecord * 8 + 0x12];
          if (sliceCount == 0) {
            sliceCount = 1;
          }
          while( true ) {
            if ((((UInt32)dirtyBits & ~(UInt32)loadedBits) >> (levelIndex & 0x3f) & 1) == 0) {
              record[slotIndex] = 0xc0101000;
            }
            else {
              record[slotIndex] = 0x80000000;
              record[gartSlot] = gartLevelOffset + gartAddress;
              record[offsetSlot] = textureLevelOffset + textureOffset;
            }
            sliceCount = sliceCount - 1;
            if (sliceCount == 0) break;
            slotIndex = slotIndex + 0x12;
            gartSlot = gartSlot + 0x12;
            offsetSlot = offsetSlot + 0x12;
            gartLevelOffset = gartLevelOffset + hwInfo[levelRecord * 8 + 0x13];
            textureLevelOffset = textureLevelOffset + hwInfo[levelRecord * 8 + 0x14];
          }
          levelIndex = levelIndex + 1;
        } while (levelIndex <= lastLevel);
      }
      faceBits = faceBitsOffset + headerBase;
      faceIndex = faceIndex + 1;
      M<UInt16>(faceBits + 0x28) = M<UInt16>(faceBits + 0x28) | M<UInt16>(faceBits + 0x1c);
    } while (faceIndex < faceCount);
    recordIndex = *hwInfo;
    record[recordIndex] = 0x50b;
    if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
      mipLevel = M<SInt32>(self + kIOATIR500GLContext_mipLevel);
      lodBlendWeight = M<SInt32>(self + kIOATIR500GLContext_surfaceIndex);
      nextMipLevel = mipLevel + 1;
      currentSurfaceBuffer = *(UInt8 **)
                 ((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
    }
    else {
      lodBlendWeight = 0;
      mipLevel = 0;
      nextMipLevel = 1;
      currentSurfaceBuffer = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
    }
    samplePitch = 0;
    if ((M<UInt32>(currentSurfaceBuffer + 0x3c) & 0xf00000) != 0) {
      samplePitch = (UInt32)M<UInt16>(currentSurfaceBuffer + 0x14) / (M<UInt32>(currentSurfaceBuffer + 0x3c) >> 0x14 & 0xf);
    }
    pitchPixels = 0x20 / M<UInt16>(currentSurfaceBuffer + 0x16);
    if (pitchPixels <= samplePitch) {
      pitchPixels = samplePitch;
    }
    macroTileFlag = 0x80000000;
    if ((UInt8)currentSurfaceBuffer[0x38] < 2) {
      macroTileFlag = 0;
    }
    totalWords = recordIndex + 2;
    record[recordIndex + 1] =
         macroTileFlag | M<SInt32>(currentSurfaceBuffer + mipLevel * 4 + 0x40) * (UInt32)M<UInt16>(currentSurfaceBuffer + 0x20) +
                  lodBlendWeight * (M<SInt32>(currentSurfaceBuffer + nextMipLevel * 4 + 0x40) -
                           M<SInt32>(currentSurfaceBuffer + mipLevel * 4 + 0x40)) + M<SInt32>(currentSurfaceBuffer + 8) >> 10 |
                  pitchPixels * M<UInt16>(currentSurfaceBuffer + 0x16) * 0x10000 & 0x3fc00000 |
                  ((UInt8)currentSurfaceBuffer[0x38] & 1) << 0x1e;
    goto submitPacket;
  }
  record = record + hwInfo[1];
  record[0xb] = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
  faceHeader = M<SInt32>(textureBytes + 0x14);
  tileModeBits = M<UInt8>(faceHeader + 0x15) >> 3;
  negTileMode = -(tileModeBits & 3);
  if ((tileModeBits & 2) == 0) {
    if (-1 < negTileMode) {
      useSmallBlock = false;
      goto tileModeKnown;
    }
    blockShift = (UInt32)M<UInt8>((SInt32)hwInfo + 0x1a);
    useSmallBlock = blockShift == 0;
pickBlockSizes:
    if (3 < blockShift) goto largeBlocks;
    if (useSmallBlock) {
      blockLog2 = 2;
      tileSizeLog2 = 3;
    }
    else {
      blockLog2 = 1;
      tileSizeLog2 = 4;
    }
  }
  else {
    useSmallBlock = true;
tileModeKnown:
    if (negTileMode < 0) {
      blockShift = (UInt32)M<UInt8>((SInt32)hwInfo + 0x1a);
      goto pickBlockSizes;
    }
    blockShift = (UInt32)M<UInt8>((SInt32)hwInfo + 0x1a);
largeBlocks:
    blockLog2 = 0;
    tileSizeLog2 = 5;
  }
  tileFace = 0;
  minHeight = 0x20 >> (blockShift & 0x3f);
  minWidth = 1 << (tileSizeLog2 - blockShift & 0x3f);
  while( true ) {
    tileFlags = (UInt32)M<UInt8>(faceHeader + 0x15);
    levelHeight = (UInt32)hwInfo[4] >> (blockShift & 0x3f);
    curWidth = (UInt32)hwInfo[3] >> (blockShift & 0x3f);
    if (firstLevel <= lastLevel) {
      mipIndex = firstLevel;
      while( true ) {
        levelRecord = tileFace * 0xd + mipIndex;
        levelRecordOffset = levelRecord * 0x20;
        tileCursor = record + M<UInt16>(hwInfo + levelRecord * 8 + 0x16);
        if ((tileFlags & 4) != 0) {
          levelDim = (SInt32)(UInt32)M<UInt16>((SInt32)hwInfo + 0x16) >> (mipIndex & 0x3f);
          minDim = 1 << blockLog2;
          if (1 << blockLog2 < (SInt32)levelDim) {
            minDim = levelDim;
          }
          if ((curWidth < minWidth << 3) || (bigTileFlag = 1, minDim < (UInt32)(1 << blockLog2 + 3))) {
            bigTileFlag = 0;
          }
          tileFlags = bigTileFlag << 2 | tileFlags & 0xfffffffb;
        }
        faceHeader = tileFace * 2 + faceHeader;
        if ((((UInt32)M<UInt16>(faceHeader + 0x1c) & ~(UInt32)M<UInt16>(faceHeader + 0x28)) >>
             (mipIndex & 0x3f) & 1) == 0) {
          *tileCursor = ((UInt32)M<UInt16>((SInt32)hwInfo + levelRecordOffset + 0x42) * 0x1d + -2) * 0x10000 |
                     0xc0001000;
        }
        else {
          gartLevelCursor = hwInfo[levelRecord * 8 + 0x11];
          textureLevelCursor = hwInfo[levelRecord * 8 + 0x12];
          *tileCursor = 0x138a;
          if (M<SInt16>((SInt32)hwInfo + levelRecordOffset + 0x42) != 0) {
            sliceIndex = 0;
            do {
              sliceIndex = sliceIndex + 1;
              tileCursor[1] = textureLevelCursor + textureOffset;
              tileCursor[3] = (curWidth >> 1 & 0x1fff) << 1 |
                           (tileFlags >> 3 & 3) << 0x11 |
                           (tileFlags >> 2 & 1) << 0x10 | tileCursor[3] & 0xffe0c001;
              swizzleBits = M<UInt8>((SInt32)hwInfo + 0x1b);
              tileCursor[9] = levelHeight - 1 & 0x3fff | tileCursor[9] & 0xffffc000;
              tileCursor[5] = gartLevelCursor + gartAddress & 0xffffffe0U | swizzleBits & 3;
              tileCursor = tileCursor + 0x1d;
              gartLevelCursor = gartLevelCursor + hwInfo[levelRecord * 8 + 0x13];
              textureLevelCursor = textureLevelCursor + hwInfo[levelRecord * 8 + 0x14];
            } while (sliceIndex < (SInt32)(UInt32)M<UInt16>((SInt32)hwInfo + levelRecordOffset + 0x42));
          }
        }
        halfWidth = curWidth >> 1;
        halfHeight = levelHeight >> 1;
        levelHeight = minHeight;
        if (minHeight < halfHeight) {
          levelHeight = halfHeight;
        }
        curWidth = minWidth;
        if (minWidth < halfWidth) {
          curWidth = halfWidth;
        }
        mipIndex = mipIndex + 1;
        if (lastLevel < mipIndex) break;
        faceHeader = M<SInt32>(textureBytes + 0x14);
      }
      faceHeader = M<SInt32>(textureBytes + 0x14);
    }
    faceHeader = tileFace * 2 + faceHeader;
    tileFace = tileFace + 1;
    M<UInt16>(faceHeader + 0x28) = M<UInt16>(faceHeader + 0x28) | M<UInt16>(faceHeader + 0x1c);
    if (faceCount <= tileFace) break;
    faceHeader = M<SInt32>(textureBytes + 0x14);
    blockShift = (UInt32)M<UInt8>((SInt32)hwInfo + 0x1a);
  }
  totalWords = hwInfo[2];
  M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb90) = 1;
submitPacket:
  paddedWords = totalWords;
  if ((totalWords & 1) != 0) {
    paddedWords = totalWords + 1;
    record[totalWords] = 0x80000000;
  }
  M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) = paddedWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
  M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x71c) = payloadByteLen + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x71c);
  if (hwInfo[8] < 0) {
    header = M<SInt32>(textureBytes + 0x14);
    submitStamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)(record),M<SInt32>(textureBytes + 4) + 0xa00,paddedWords);
    M<UInt32>(header + 0xc) = submitStamp;
  }
  else {
    header = M<SInt32>(textureBytes + 0x14);
    submitStamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)(record),
                       hwInfo[1] * 4 + M<SInt32>(textureBytes + 4) + 0xa00,paddedWords);
    M<UInt32>(header + 0xc) = submitStamp;
  }
  if (textureBytes[0x20] == 0x7) {
    M<UInt32>(M<SInt32>(M<SInt32>(textureBytes + 0x58) + 0x14) + 8) =
         M<UInt32>(M<SInt32>(textureBytes + 0x14) + 0xc);
  }
  VCALL(*mapping, 0x18)(mapping);
  return;
}
