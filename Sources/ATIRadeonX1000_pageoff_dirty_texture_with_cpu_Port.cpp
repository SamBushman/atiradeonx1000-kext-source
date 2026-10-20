/*
 * ATIRadeonX1000_pageoff_dirty_texture_with_cpu_Port.cpp
 *
 * ATIRadeonX1000::pageoff_dirty_texture_with_cpu (real addr 0x1e500, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 global_dummy_read_back_a_register;   /* ATIRadeonX1000_DataTables.cpp */

extern "C" UInt32 GH_memcpy(...) asm("_memcpy");


/* real addr 0x1e500 */
void ATIRadeonX1000::pageoff_dirty_texture_with_cpu(VendorTextureBuffer *texture, ATITextureBufferHeader *hwInfo) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);
    UInt8 *hwInfoBytes = reinterpret_cast<UInt8 *>(hwInfo);

  UInt8 faceCount;
  UInt8 *regPtr;
  UInt32 saved0;
  UInt32 saved1;
  UInt32 saved2;
  SInt32 surfaceInfoOffset;
  SInt32 surfaceLowerOffset;
  bool macroTiled;
  UInt8 tileFlags;
  UInt32 levelDepth;
  SInt32 tileRowShift;
  UInt32 lastLevel;
  UInt32 pixelShift;
  UInt8 *destination;
  SInt32 vramSource;
  UInt8 pixelShiftByte;
  SInt32 surfaceUpperOffset;
  SInt32 registerWindow;
  SInt32 rowGranularity;
  SInt32 flushBytes;
  UInt32 baseLevel;
  SInt32 mmioBase;
  UInt32 vramOffset;
  SInt32 macroTileWidthShift;
  UInt32 level;
  UInt32 levelHeight;
  SInt32 repeat;
  UInt32 levelWidth;
  SInt32 rowCount;
  UInt8 *tileRecord;
  UInt32 srcPitch;
  UInt32 face;
  SInt32 bytesCopied;
  SInt32 macroTileHeightShift;
  SInt32 *innerMapping;
  UInt32 slotsLeft;
  SInt32 negTileBits;
  SInt32 textureInfo;
  SInt32 slotOffset;
  UInt32 freeSlot;
  UInt32 repeatCount;
  UInt32 macroTileFlag;
  UInt32 tilingBits;
  UInt32 endAddress;
  UInt32 cacheLine;
  SInt32 flushOffset;
  SInt32 rowIndex;
  SInt32 destPitch;
  
  textureInfo = M<SInt32>(textureBytes + 0x14);
  baseLevel = (UInt32)M<UInt8>(textureInfo + 0x17);
  lastLevel = (baseLevel + M<UInt8>(textureInfo + 0x35)) - 1;
  faceCount = M<UInt8>(textureInfo + 0x34);
  VCALL(M<SInt32>(self), 0x558)(self,M<SInt32>(self + kIOATIR500Accelerator_submitStamp) + -1);
  slotsLeft = (UInt32)(UInt8)self[0x990];
  if ((slotsLeft == 0) || ((M<UInt32>(self + kIOATIR500Accelerator_vramPreparedMask) & 1) == 0)) {
LAB_0001e594:
    slotOffset = 0;
  }
  else {
    freeSlot = 0;
    do {
      freeSlot = freeSlot + 1;
      slotsLeft = slotsLeft - 1;
      if (slotsLeft == 0) goto LAB_0001e594;
    } while ((M<UInt32>(self + kIOATIR500Accelerator_vramPreparedMask) & 1 << (freeSlot & 0x3f)) != 0);
    slotOffset = freeSlot * 4;
  }
  mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  surfaceInfoOffset = (slotOffset + 0x2c3) * 4;
  /* the three registers are read as words (lwbrx) and written back later (stwbrx), exactly as the shipped code does: four single-byte reads would be a different access on the bus */
  saved0 = loadWordByteReversed(reinterpret_cast<UInt8 *>(mmioBase + surfaceInfoOffset));
  surfaceLowerOffset = (slotOffset + 0x2c1) * 4;
  saved1 = loadWordByteReversed(reinterpret_cast<UInt8 *>(mmioBase + surfaceLowerOffset));
  surfaceUpperOffset = (slotOffset + 0x2c2) * 4;
  saved2 = loadWordByteReversed(reinterpret_cast<UInt8 *>(mmioBase + surfaceUpperOffset));
  tileFlags = M<UInt8>(M<SInt32>(textureBytes + 0x14) + 0x15) >> 3;
  negTileBits = -(tileFlags & 3);
  if ((tileFlags & 2) == 0) {
    if (-1 < negTileBits) {
      macroTiled = false;
      goto LAB_0001e61c;
    }
    pixelShiftByte = hwInfoBytes[0x1a];
    macroTiled = pixelShiftByte == 0x0;
LAB_0001e624:
    if ((UInt8)pixelShiftByte < 4) {
      if (macroTiled) {
        tileRowShift = 2;
        macroTileWidthShift = 3;
        macroTileHeightShift = 2;
      }
      else {
        tileRowShift = 1;
        macroTileWidthShift = 4;
        macroTileHeightShift = 1;
      }
      goto LAB_0001e668;
    }
  }
  else {
    macroTiled = true;
LAB_0001e61c:
    if (negTileBits < 0) {
      pixelShiftByte = hwInfoBytes[0x1a];
      goto LAB_0001e624;
    }
  }
  tileRowShift = 0;
  macroTileWidthShift = 5;
  macroTileHeightShift = 0;
LAB_0001e668:
  if (faceCount == 0) {
    innerMapping = (SInt32 *)0x0;
    bytesCopied = 0;
  }
  else {
    face = 0;
    innerMapping = (SInt32 *)0x0;
    bytesCopied = 0;
    do {
      levelWidth = (UInt32)M<UInt16>(hwInfoBytes + 0x14);
      levelHeight = (UInt32)M<UInt16>(hwInfoBytes + 0x16);
      levelDepth = (UInt32)M<UInt16>(hwInfoBytes + 0x18);
      srcPitch = M<UInt32>(hwInfoBytes + 0xc);
      destPitch = M<SInt32>(hwInfoBytes + 0x10);
      if (baseLevel <= lastLevel) {
        tileRecord = hwInfoBytes + (face * 0xd + baseLevel) * 0x20 + 0x42;
        level = baseLevel;
        do {
          repeatCount = (UInt32)M<UInt16>(tileRecord);
          if ((repeatCount != 0) && (rowCount = (SInt32)(levelHeight * levelDepth) / (SInt32)repeatCount, repeatCount != 0)) {
            repeat = 0;
            do {
              if (textureBytes[0x20] == 0x7) {
                innerMapping = (SInt32 *)VCALL(*M<SInt32 *>(M<SInt32>(textureBytes + 0x58) + 8), 0x14c)
                                            (M<SInt32 *>(M<SInt32>(textureBytes + 0x58) + 8),
                                             GH_kernel_task,0,1,0,0);
                if (innerMapping == (SInt32 *)0x0) {
                  return;
                }
                destination = (UInt8 *)VCALL(*innerMapping, 0xd0)(innerMapping);
              }
              else {
                destination = hwInfoBytes + M<SInt32>(tileRecord + 2);
              }
              destination = destination + repeat * M<SInt32>(tileRecord + 10);
              vramSource = M<SInt32>(self + kIOATIR500Accelerator_vramApertureBase) + M<SInt32>(textureBytes + 0x48) + M<SInt32>(tileRecord + 6) +
                       repeat * M<SInt32>(tileRecord + 0xe);
              if ((((SInt32)srcPitch < 1 << macroTileWidthShift + 3) || ((SInt32)levelHeight < 1 << macroTileHeightShift + 3)) ||
                 ((M<UInt8>(M<SInt32>(textureBytes + 0x14) + 0x15) & 4) == 0)) {
                macroTiled = false;
                macroTileFlag = 0;
              }
              else {
                macroTiled = true;
                macroTileFlag = 1;
              }
              switch(macroTileHeightShift << 1 | macroTileFlag) {
              default:
                tilingBits = 0;
                break;
              case 1:
                tilingBits = 0x10000;
                break;
              case 2:
                tilingBits = 0x20000;
                break;
              case 3:
                tilingBits = 0x30000;
                break;
              case 4:
                tilingBits = 0x60000;
                break;
              case 5:
                tilingBits = 0x70000;
              }
              rowGranularity = 8;
              if (!macroTiled) {
                rowGranularity = 1;
              }
              rowGranularity = rowGranularity * (1 << tileRowShift);
              vramOffset = vramSource - M<SInt32>(self + kIOATIR500Accelerator_vramApertureBase);
              registerWindow = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
              M<UInt32>(registerWindow + surfaceInfoOffset) =
                   (srcPitch >> 3) << 0x18 | (srcPitch >> 3 & 0x1f00) << 8 |
                   (tilingBits | ((UInt8)hwInfoBytes[0x1b] & 3) << 0x14 | ((UInt8)hwInfoBytes[0x1b] & 3) << 0x16)
                   >> 8;
              enforceInOrderExecutionIO();
              M<UInt32>(registerWindow + surfaceLowerOffset) =
                   vramOffset * 0x1000000 | (vramOffset & 0xff00) << 8 | vramOffset >> 8 & 0xff00 |
                   vramOffset >> 0x18;
              enforceInOrderExecutionIO();
              endAddress = (vramOffset + rowGranularity * srcPitch * ((rowCount + rowGranularity + -1) / rowGranularity)) - 1;
              M<UInt32>(registerWindow + surfaceUpperOffset) =
                   endAddress * 0x1000000 | (endAddress & 0xff00) << 8 | endAddress >> 8 & 0xff00 |
                   endAddress >> 0x18;
              enforceInOrderExecutionIO();
              regPtr = (UInt8 *)(registerWindow + surfaceUpperOffset);
              global_dummy_read_back_a_register =
                   loadWordByteReversed(regPtr);
              if (rowCount < 1) {
                pixelShift = (UInt32)(UInt8)hwInfoBytes[0x1a];
              }
              else {
                pixelShift = (UInt32)(UInt8)hwInfoBytes[0x1a];
                rowIndex = 0;
                do {
                  GH_memcpy(destination,vramSource,levelWidth << (pixelShift & 0x3f));
                  if ((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 0x80) == 0) {
                    pixelShiftByte = hwInfoBytes[0x1a];
                  }
                  else {
                    cacheLine = (UInt32)(UInt8)self[0x84];
                    pixelShiftByte = hwInfoBytes[0x1a];
                    flushOffset = 0;
                    flushBytes = ((levelWidth << ((UInt8)pixelShiftByte & 0x3f)) + ((UInt32)destination & cacheLine - 1)) -
                             cacheLine;
                    if (0 < flushBytes) {
                      flushOffset = 0;
                      do {
                        dataCacheBlockStore((-cacheLine & (UInt32)destination) + flushOffset);
                        flushOffset = flushOffset + cacheLine;
                      } while (flushOffset < flushBytes);
                    }
                    ppcSync();
                    instructionSynchronize();
                    dataCacheBlockFlush((-cacheLine & (UInt32)destination) + flushOffset);
                    ppcSync();
                    instructionSynchronize();
                    instructionSynchronize();
                  }
                  pixelShift = (UInt32)(UInt8)pixelShiftByte;
                  rowIndex = rowIndex + 1;
                  destination = destination + destPitch;
                  vramSource = vramSource + srcPitch;
                } while (rowCount != rowIndex);
              }
              repeat = repeat + 1;
              bytesCopied = bytesCopied + rowCount * (levelWidth << (pixelShift & 0x3f));
            } while (repeat < (SInt32)(UInt32)M<UInt16>(tileRecord));
          }
          if (((1 >= levelWidth) && (levelHeight < 2)) && (levelDepth < 2)) break;
          if (0x20 < destPitch) {
            destPitch = destPitch >> 1;
          }
          if (1 << macroTileWidthShift < (SInt32)srcPitch) {
            srcPitch = (SInt32)srcPitch >> 1;
          }
          if (1 < levelWidth) {
            levelWidth = (SInt32)levelWidth >> 1;
          }
          if (1 < levelHeight) {
            levelHeight = (SInt32)levelHeight >> 1;
          }
          if (1 < levelDepth) {
            levelDepth = (SInt32)levelDepth >> 1;
          }
          level = level + 1;
          tileRecord = tileRecord + 0x20;
        } while (level <= lastLevel);
      }
      face = face + 1;
    } while (face < faceCount);
    mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  }
  M<SInt32>(self + kIOATIR500Accelerator_texturePageOutBytesPerSample) = bytesCopied + M<SInt32>(self + kIOATIR500Accelerator_texturePageOutBytesPerSample);
  storeWordByteReversed(reinterpret_cast<UInt8 *>(mmioBase + surfaceInfoOffset), saved0);
  enforceInOrderExecutionIO();
  storeWordByteReversed(reinterpret_cast<UInt8 *>(mmioBase + surfaceLowerOffset), saved1);
  enforceInOrderExecutionIO();
  storeWordByteReversed(reinterpret_cast<UInt8 *>(mmioBase + surfaceUpperOffset), saved2);
  enforceInOrderExecutionIO();
  if (innerMapping != (SInt32 *)0x0) {
    VCALL(*innerMapping, 0x18)(innerMapping);
  }
  return;
}
