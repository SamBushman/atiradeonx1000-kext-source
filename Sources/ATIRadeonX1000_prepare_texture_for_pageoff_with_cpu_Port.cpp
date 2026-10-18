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
  bool bVar2;
  UInt8 bVar3;
  UInt32 uVar4;
  UInt32 uVar5;
  SInt32 iVar6;
  UInt32 stamp;
  SInt32 repeat;
  UInt8 *tileRecord;
  UInt8 *tileOut;
  UInt32 uVar11;
  UInt32 mipFlags;
  SInt32 iVar13;
  UInt32 baseLevel;
  UInt32 face;
  UInt32 lastLevel;
  UInt32 uVar17;
  UInt8 *record;
  UInt32 oldVramOffset;
  SInt32 newVramOffset;
  UInt32 uVar21;
  UInt32 uVar22;
  UInt32 level;
  UInt8 oldElement[28];
  
  oldVramOffset = M<UInt32>(textureBytes + 0x48);
  if (oldVramOffset < M<UInt32>(self + kIOATIR500Accelerator_usableVramSize)) {
    return 1;
  }
  if ((textureBytes[0x20] != 0x3) && (textureBytes[0x20] != 0x7)) {
    return 0;
  }
  uVar22 = M<UInt32>(textureBytes + 0x50);
  GH_memcpy(oldElement,(UInt8 *)(textureBytes + 0x40),0x10);
  iVar6 = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool)))->alloc((GLKMemoryElement *)((UInt8 *)(textureBytes + 0x40)),uVar22,
                     0x1000,0,M<UInt32>(self + kIOATIR500Accelerator_usableVramSize));
  if ((iVar6 == 0) && (iVar6 = this->freeToAllocTextureCPUVisibleVRAM((VendorTextureBuffer *)(textureBytes),uVar22), iVar6 == 0)) {
    return 0;
  }
  newVramOffset = M<SInt32>(textureBytes + 0x48);
  record = hwInfoBytes + M<SInt32>(hwInfoBytes + 4) * 4 + 0xa00;
  M<UInt32>(record + 0x2c) = M<UInt32>(self + kIOATIR500Accelerator_gbTileConfig);
  iVar6 = M<SInt32>(textureBytes + 0x14);
  mipFlags = (UInt32)M<UInt8>(iVar6 + 0x15);
  baseLevel = (UInt32)M<UInt8>(iVar6 + 0x17);
  faceCount = M<UInt8>(iVar6 + 0x34);
  bVar3 = M<UInt8>(iVar6 + 0x15) >> 3;
  lastLevel = (baseLevel + M<UInt8>(iVar6 + 0x35)) - 1;
  iVar6 = -(bVar3 & 3);
  if ((bVar3 & 2) == 0) {
    if (-1 < iVar6) {
      bVar2 = false;
      goto LAB_00020e40;
    }
    uVar11 = (UInt32)(UInt8)hwInfoBytes[0x1a];
    bVar2 = uVar11 == 0;
LAB_00020e48:
    if (uVar11 < 4) {
      if (bVar2) {
        iVar13 = 2;
        iVar6 = 3;
      }
      else {
        iVar13 = 1;
        iVar6 = 4;
      }
      goto LAB_00020e80;
    }
  }
  else {
    bVar2 = true;
LAB_00020e40:
    if (iVar6 < 0) {
      uVar11 = (UInt32)(UInt8)hwInfoBytes[0x1a];
      goto LAB_00020e48;
    }
    uVar11 = (UInt32)(UInt8)hwInfoBytes[0x1a];
  }
  iVar13 = 0;
  iVar6 = 5;
LAB_00020e80:
  face = 0;
  uVar17 = 1 << (iVar6 - uVar11 & 0x3f);
  if (faceCount != 0) {
    while( true ) {
      uVar11 = M<UInt32>(hwInfoBytes + 0xc) >> (uVar11 & 0x3f);
      if (baseLevel <= lastLevel) {
        tileRecord = hwInfoBytes + baseLevel * 0x20 + face * 0x1a0 + 0x40;
        level = baseLevel;
        do {
          tileOut = record + (UInt32)M<UInt16>(tileRecord + 0x18) * 4;
          if ((mipFlags & 4) != 0) {
            uVar4 = (SInt32)(UInt32)M<UInt16>(hwInfoBytes + 0x16) >> (level & 0x3f);
            uVar5 = 1 << iVar13;
            if (1 << iVar13 < (SInt32)uVar4) {
              uVar5 = uVar4;
            }
            if ((uVar11 < uVar17 << 3) || (iVar6 = 1, uVar5 < (UInt32)(1 << iVar13 + 3))) {
              iVar6 = 0;
            }
            mipFlags = iVar6 << 2 | mipFlags & 0xfffffffb;
          }
          iVar6 = M<SInt32>(tileRecord + 8);
          M<UInt32>(tileOut) = 0x138a;
          uVar5 = uVar11 >> 1;
          if (M<SInt16>(tileRecord + 2) != 0) {
            uVar4 = mipFlags >> 2 & 1;
            uVar21 = mipFlags >> 3 & 3;
            repeat = 0;
            do {
              repeat = repeat + 1;
              M<SInt32>(tileOut + 4) = iVar6 + newVramOffset;
              M<UInt32>(tileOut + 0x24) =
                   uVar11 - 1 & 0x3fff | M<UInt32>(tileOut + 0x24) & 0xffffc000;
              M<UInt32>(tileOut + 0xc) =
                   (uVar5 & 0x1fff) << 1 |
                   uVar21 << 0x11 | uVar4 << 0x10 | M<UInt32>(tileOut + 0xc) & 0xffe0c001;
              M<UInt32>(tileOut + 0x14) = iVar6 + oldVramOffset & 0xffffffe0 | uVar21 << 3 | uVar4 << 2;
              tileOut = tileOut + 0x74;
              iVar6 = iVar6 + M<SInt32>(tileRecord + 0x10);
            } while (repeat < (SInt32)(UInt32)M<UInt16>(tileRecord + 2));
          }
          uVar11 = uVar17;
          if (uVar17 < uVar5) {
            uVar11 = uVar5;
          }
          level = level + 1;
          tileRecord = tileRecord + 0x20;
        } while (level <= lastLevel);
      }
      face = face + 1;
      if (faceCount <= face) break;
      uVar11 = (UInt32)(UInt8)hwInfoBytes[0x1a];
    }
  }
  uVar22 = M<UInt32>(hwInfoBytes + 8);
  M<UInt32>(self + kIOATIR500Accelerator_stateDestroyedByPageoff) = 1;
  if ((uVar22 & 1) != 0) {
    iVar6 = uVar22 * 4;
    uVar22 = uVar22 + 1;
    M<UInt32>(record + iVar6) = 0x80000000;
  }
  M<UInt32>(self + kIOATIR500Accelerator_commandGLBytesPerSample) = uVar22 * 4 + M<SInt32>(self + kIOATIR500Accelerator_commandGLBytesPerSample);
  iVar6 = M<SInt32>(textureBytes + 0x14);
  stamp = this->submit_buffer((UInt32 *)record,
                        M<SInt32>(hwInfoBytes + 4) * 4 + M<SInt32>(textureBytes + 4) + 0xa00,uVar22);
  M<UInt32>(iVar6 + 0xc) = stamp;
  VCALL(M<SInt32>(self), 0x54c)(self,M<UInt32>(M<SInt32>(textureBytes + 0x14) + 0xc));
  ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool)))->dealloc((GLKMemoryElement *)(oldElement));
  return 1;
}
