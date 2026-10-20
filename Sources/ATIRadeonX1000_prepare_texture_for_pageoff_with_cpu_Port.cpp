/*
 * ATIRadeonX1000_prepare_texture_for_pageoff_with_cpu_Port.cpp
 *
 * ATIRadeonX1000::prepare_texture_for_pageoff_with_cpu (real addr 0x20d30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_memcpy(...) asm("_memcpy");


/* real addr 0x20d30 */
UInt32 ATIRadeonX1000::prepare_texture_for_pageoff_with_cpu(VendorTextureBuffer *texture, ATITextureBufferHeader *hwInfo) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);
    UInt8 *hwInfoBytes = reinterpret_cast<UInt8 *>(hwInfo);

  UInt8 faceCount;
  bool macroTiled;
  UInt8 tileFlags;
  UInt32 heightAtLevel;
  UInt32 heightRows;
  UInt32 stamp;
  SInt32 repeat;
  UInt8 *tileRecord;
  UInt8 *tileOut;
  UInt32 levelWidth;
  UInt32 mipFlags;
  SInt32 macroTileHeightShift;
  UInt32 baseLevel;
  UInt32 face;
  UInt32 lastLevel;
  UInt32 minWidth;
  UInt8 *record;
  UInt32 oldVramOffset;
  SInt32 newVramOffset;
  UInt32 microTiling;
  UInt32 wordCount;
  UInt32 level;
  UInt8 oldElement[28];
  SInt32 allocResult;
  SInt32 textureInfo;
  SInt32 negTileBits;
  SInt32 macroTileWidthShift;
  SInt32 macroTileBit;
  SInt32 tileOffset;
  SInt32 emptyWordOffset;
  UInt32 macroBit;
  UInt32 halfWidth;
  UInt32 pixelShift;
  UInt32 textureSize;
  
  oldVramOffset = M<UInt32>(textureBytes + 0x48);
  if (oldVramOffset < M<UInt32>(self + kIOATIR500Accelerator_usableVramSize)) {
    return 1;
  }
  if ((textureBytes[0x20] != 0x3) && (textureBytes[0x20] != 0x7)) {
    return 0;
  }
  textureSize = M<UInt32>(textureBytes + 0x50);
  GH_memcpy(oldElement,(UInt8 *)(textureBytes + 0x40),0x10);
  allocResult = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPool)))->alloc((GLKMemoryElement *)((UInt8 *)(textureBytes + 0x40)),textureSize,
                     0x1000,0,M<UInt32>(self + kIOATIR500Accelerator_usableVramSize));
  if ((allocResult == 0) && (allocResult = this->freeToAllocTextureCPUVisibleVRAM((VendorTextureBuffer *)(textureBytes),textureSize), allocResult == 0)) {
    return 0;
  }
  newVramOffset = M<SInt32>(textureBytes + 0x48);
  record = hwInfoBytes + M<SInt32>(hwInfoBytes + 4) * 4 + 0xa00;
  M<UInt32>(record + 0x2c) = M<UInt32>(self + kIOATIR500Accelerator_gbTileConfig);
  textureInfo = M<SInt32>(textureBytes + 0x14);
  mipFlags = (UInt32)M<UInt8>(textureInfo + 0x15);
  baseLevel = (UInt32)M<UInt8>(textureInfo + 0x17);
  faceCount = M<UInt8>(textureInfo + 0x34);
  tileFlags = M<UInt8>(textureInfo + 0x15) >> 3;
  lastLevel = (baseLevel + M<UInt8>(textureInfo + 0x35)) - 1;
  negTileBits = -(tileFlags & 3);
  if ((tileFlags & 2) == 0) {
    if (-1 < negTileBits) {
      macroTiled = false;
      goto LAB_00020e40;
    }
    pixelShift = (UInt32)(UInt8)hwInfoBytes[0x1a];
    macroTiled = pixelShift == 0;
LAB_00020e48:
    if (pixelShift < 4) {
      if (macroTiled) {
        macroTileHeightShift = 2;
        macroTileWidthShift = 3;
      }
      else {
        macroTileHeightShift = 1;
        macroTileWidthShift = 4;
      }
      goto LAB_00020e80;
    }
  }
  else {
    macroTiled = true;
LAB_00020e40:
    if (negTileBits < 0) {
      pixelShift = (UInt32)(UInt8)hwInfoBytes[0x1a];
      goto LAB_00020e48;
    }
    pixelShift = (UInt32)(UInt8)hwInfoBytes[0x1a];
  }
  macroTileHeightShift = 0;
  macroTileWidthShift = 5;
LAB_00020e80:
  face = 0;
  minWidth = 1 << (macroTileWidthShift - pixelShift & 0x3f);
  if (faceCount != 0) {
    while( true ) {
      levelWidth = M<UInt32>(hwInfoBytes + 0xc) >> (pixelShift & 0x3f);
      if (baseLevel <= lastLevel) {
        tileRecord = hwInfoBytes + baseLevel * 0x20 + face * 0x1a0 + 0x40;
        level = baseLevel;
        do {
          tileOut = record + (UInt32)M<UInt16>(tileRecord + 0x18) * 4;
          if ((mipFlags & 4) != 0) {
            heightAtLevel = (SInt32)(UInt32)M<UInt16>(hwInfoBytes + 0x16) >> (level & 0x3f);
            heightRows = 1 << macroTileHeightShift;
            if (1 << macroTileHeightShift < (SInt32)heightAtLevel) {
              heightRows = heightAtLevel;
            }
            if ((levelWidth < minWidth << 3) || (macroTileBit = 1, heightRows < (UInt32)(1 << macroTileHeightShift + 3))) {
              macroTileBit = 0;
            }
            mipFlags = macroTileBit << 2 | mipFlags & 0xfffffffb;
          }
          tileOffset = M<SInt32>(tileRecord + 8);
          M<UInt32>(tileOut) = 0x138a;
          halfWidth = levelWidth >> 1;
          if (M<SInt16>(tileRecord + 2) != 0) {
            macroBit = mipFlags >> 2 & 1;
            microTiling = mipFlags >> 3 & 3;
            repeat = 0;
            do {
              repeat = repeat + 1;
              M<SInt32>(tileOut + 4) = tileOffset + newVramOffset;
              M<UInt32>(tileOut + 0x24) =
                   levelWidth - 1 & 0x3fff | M<UInt32>(tileOut + 0x24) & 0xffffc000;
              M<UInt32>(tileOut + 0xc) =
                   (halfWidth & 0x1fff) << 1 |
                   microTiling << 0x11 | macroBit << 0x10 | M<UInt32>(tileOut + 0xc) & 0xffe0c001;
              M<UInt32>(tileOut + 0x14) = tileOffset + oldVramOffset & 0xffffffe0 | microTiling << 3 | macroBit << 2;
              tileOut = tileOut + 0x74;
              tileOffset = tileOffset + M<SInt32>(tileRecord + 0x10);
            } while (repeat < (SInt32)(UInt32)M<UInt16>(tileRecord + 2));
          }
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
      pixelShift = (UInt32)(UInt8)hwInfoBytes[0x1a];
    }
  }
  wordCount = M<UInt32>(hwInfoBytes + 8);
  M<UInt32>(self + kIOATIR500Accelerator_stateDestroyedByPageoff) = 1;
  if ((wordCount & 1) != 0) {
    emptyWordOffset = wordCount * 4;
    wordCount = wordCount + 1;
    M<UInt32>(record + emptyWordOffset) = 0x80000000;
  }
  M<UInt32>(self + kIOATIR500Accelerator_commandGLBytesPerSample) = wordCount * 4 + M<SInt32>(self + kIOATIR500Accelerator_commandGLBytesPerSample);
  textureInfo = M<SInt32>(textureBytes + 0x14);
  stamp = this->submit_buffer((UInt32 *)record,
                        M<SInt32>(hwInfoBytes + 4) * 4 + M<SInt32>(textureBytes + 4) + 0xa00,wordCount);
  M<UInt32>(textureInfo + 0xc) = stamp;
  VCALL(M<SInt32>(self), 0x54c)(self,M<UInt32>(M<SInt32>(textureBytes + 0x14) + 0xc));
  ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPool)))->dealloc((GLKMemoryElement *)(oldElement));
  return 1;
}
