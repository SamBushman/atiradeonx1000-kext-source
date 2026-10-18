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
  UInt8 AVar2;
  bool bVar3;
  UInt8 bVar4;
  unsigned int uVar5;
  unsigned int baseLevel;
  unsigned int lastLevel;
  SInt16 sVar10;
  int iVar8;
  unsigned int uVar9;
  int repeat;
  UInt32 stamp;
  UInt32 wordCount;
  UInt8 *tileRecord;
  int iVar15;
  UInt8 *tileOut;
  UInt8 type;
  unsigned int uVar18;
  unsigned int uVar19;
  int iVar20;
  unsigned int face;
  unsigned int uVar22;
  unsigned int uVar23;
  int vramOffset;
  UInt8 *record;
  unsigned int uVar26;
  unsigned int level;
  int iVar28;
  UInt8 *innerBuffer;
  int gartOffset;
  int size;
  
  iVar15 = M<int>(textureBytes + 0x14);
  vramOffset = M<int>(textureBytes + 0x48);
  baseLevel = (unsigned int)M<UInt8>(iVar15 + 0x17);
  faceCount = M<UInt8>(iVar15 + 0x34);
  lastLevel = (baseLevel + M<UInt8>(iVar15 + 0x35)) - 1;
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
      iVar15 = VCALL(M<int>(self), 0x5a8)(self, textureBytes);
      if ((iVar15 == 0) &&
         (iVar15 = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                              (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                              (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),
                              (VendorTransferBuffer *)((UInt8 *)textureBytes)), iVar15 == 0)) {
        VCALL(M<int>(self), 0x54c)(self,M<int>(self + kIOATIR500Accelerator_submitStamp) + -1);
        iVar15 = VCALL(M<int>(self), 0x5a8)(self,textureBytes);
        if ((iVar15 == 0) &&
           (iVar15 = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                                (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                                (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),
                                (VendorTransferBuffer *)((UInt8 *)textureBytes)), iVar15 == 0)) {
          return 0;
        }
      }
      iVar15 = M<int>(textureBytes + 0x14);
      type = textureBytes[0x20];
    }
  }
  else {
    if (textureBytes[0x20] != 0x7) {
      return 0;
    }
    innerBuffer = M<UInt8 *>(textureBytes + 0x58);
    if (((M<int>(innerBuffer + 4) == 0) &&
        (iVar15 = VCALL(M<int>(self), 0x5a8)(self,innerBuffer), iVar15 == 0)) &&
       (iVar15 = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                            (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                            (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),(VendorTransferBuffer *)(innerBuffer)), iVar15 == 0)) {
      VCALL(M<int>(self), 0x54c)(self,M<int>(self + kIOATIR500Accelerator_submitStamp) + -1);
      iVar15 = VCALL(M<int>(self), 0x5a8)(self,innerBuffer);
      if ((iVar15 == 0) &&
         (iVar15 = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                              (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                              (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),(VendorTransferBuffer *)(innerBuffer)), iVar15 == 0))
      {
        return 0;
      }
    }
    iVar15 = M<int>(textureBytes + 4);
    sVar10 = M<SInt16>(innerBuffer + 0xe) + 1;
    M<SInt16>(innerBuffer + 0xe) = sVar10;
    if (iVar15 == 0) {
      iVar15 = VCALL(M<int>(self), 0x5a8)(self,textureBytes);
      if ((iVar15 == 0) &&
         (iVar15 = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                              (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                              (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),
                              (VendorTransferBuffer *)((UInt8 *)textureBytes)), iVar15 == 0)) {
        VCALL(M<int>(self), 0x54c)(self,M<int>(self + kIOATIR500Accelerator_submitStamp) + -1);
        iVar15 = VCALL(M<int>(self), 0x5a8)(self,textureBytes);
        if ((iVar15 == 0) &&
           (iVar15 = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                                (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                                (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),
                                (VendorTransferBuffer *)((UInt8 *)textureBytes)), iVar15 == 0)) {
          M<SInt16>(innerBuffer + 0xe) = M<SInt16>(innerBuffer + 0xe) + -1;
          return 0;
        }
      }
      sVar10 = M<SInt16>(innerBuffer + 0xe);
    }
    iVar15 = M<int>(textureBytes + 0x14);
    type = textureBytes[0x20];
    M<SInt16>(innerBuffer + 0xe) = sVar10 + -1;
  }
  if (type == 0x7) {
    size = M<int>(textureBytes + 0x50);
    gartOffset = M<int>(M<int>(textureBytes + 0x58) + 4);
  }
  else {
    size = M<int>(textureBytes + 0x50);
    gartOffset = M<int>(textureBytes + 4);
  }
  iVar28 = M<int>(self + kIOATIR500Accelerator_texturePageOutWaitTime);
  iVar15 = VCALL(M<int>(self), 0x54c)(self,M<UInt32>(iVar15 + 0xc));
  iVar8 = M<int>(self + kIOATIR500Accelerator_vramSizeProgrammed);
  M<int>(self + kIOATIR500Accelerator_texturePageOutWaitTime) = iVar28 + iVar15;
  record = hwInfoBytes + M<int>(hwInfoBytes + 4) * 4 + 0xa00;
  M<UInt32>(record + 0x2c) = M<UInt32>(self + kIOATIR500Accelerator_gbTileConfig);
  iVar28 = M<int>(textureBytes + 0x14);
  bVar4 = M<UInt8>(iVar28 + 0x15) >> 3;
  iVar15 = -(bVar4 & 3);
  if ((bVar4 & 2) == 0) {
    if (-1 < iVar15) {
      bVar3 = false;
      goto LAB_000214a0;
    }
    uVar18 = (unsigned int)(UInt8)hwInfoBytes[0x1a];
    bVar3 = uVar18 == 0;
LAB_000214a8:
    if (uVar18 < 4) {
      if (bVar3) {
        iVar20 = 2;
        iVar15 = 3;
      }
      else {
        iVar20 = 1;
        iVar15 = 4;
      }
      goto LAB_000214e0;
    }
  }
  else {
    bVar3 = true;
LAB_000214a0:
    if (iVar15 < 0) {
      uVar18 = (unsigned int)(UInt8)hwInfoBytes[0x1a];
      goto LAB_000214a8;
    }
    uVar18 = (unsigned int)(UInt8)hwInfoBytes[0x1a];
  }
  iVar20 = 0;
  iVar15 = 5;
LAB_000214e0:
  face = 0;
  uVar23 = 1 << (iVar15 - uVar18 & 0x3f);
  uVar22 = 0x20 >> (uVar18 & 0x3f);
  if (faceCount != 0) {
    while( true ) {
      uVar26 = (unsigned int)M<UInt8>(iVar28 + 0x15);
      uVar19 = M<unsigned int>(hwInfoBytes + 0x10) >> (uVar18 & 0x3f);
      uVar18 = M<unsigned int>(hwInfoBytes + 0xc) >> (uVar18 & 0x3f);
      if (baseLevel <= lastLevel) {
        tileRecord = hwInfoBytes + baseLevel * 0x20 + face * 0x1a0 + 0x40;
        level = baseLevel;
        do {
          tileOut = record + (unsigned int)M<UInt16>(tileRecord + 0x18) * 4;
          if ((uVar26 & 4) != 0) {
            uVar5 = (int)(unsigned int)M<UInt16>(hwInfoBytes + 0x16) >> (level & 0x3f);
            uVar9 = 1 << iVar20;
            if (1 << iVar20 < (int)uVar5) {
              uVar9 = uVar5;
            }
            if ((uVar18 < uVar23 << 3) || (iVar15 = 1, uVar9 < (unsigned int)(1 << iVar20 + 3))) {
              iVar15 = 0;
            }
            uVar26 = iVar15 << 2 | uVar26 & 0xfffffffb;
          }
          iVar15 = M<int>(tileRecord + 4);
          iVar28 = M<int>(tileRecord + 8);
          uVar9 = uVar19 >> 1;
          M<UInt32>(tileOut) = 0x138a;
          if (M<SInt16>(tileRecord + 2) != 0) {
            repeat = 0;
            do {
              uVar19 = M<unsigned int>(tileOut + 0xc);
              repeat = repeat + 1;
              M<int>(tileOut + 4) = iVar15 + gartOffset + iVar8;
              M<unsigned int>(tileOut + 0xc) = uVar19 & 0xfff8ffff;
              AVar2 = hwInfoBytes[0x1b];
              M<unsigned int>(tileOut + 0x24) =
                   uVar18 - 1 & 0x3fff | M<unsigned int>(tileOut + 0x24) & 0xffffc000;
              M<unsigned int>(tileOut + 0x14) =
                   iVar28 + vramOffset & 0xffffffe0U | (uVar26 >> 3 & 3) << 3 | (uVar26 >> 2 & 1) << 2;
              M<unsigned int>(tileOut + 0xc) =
                   (uVar9 & 0x1fff) << 1 | ((UInt8)AVar2 & 3) << 0x13 | uVar19 & 0xffe0c001;
              tileOut = tileOut + 0x74;
              iVar15 = iVar15 + M<int>(tileRecord + 0xc);
              iVar28 = iVar28 + M<int>(tileRecord + 0x10);
            } while (repeat < (int)(unsigned int)M<UInt16>(tileRecord + 2));
          }
          uVar19 = uVar22;
          if (uVar22 < uVar9) {
            uVar19 = uVar9;
          }
          uVar9 = uVar18 >> 1;
          uVar18 = uVar23;
          if (uVar23 < uVar9) {
            uVar18 = uVar9;
          }
          level = level + 1;
          tileRecord = tileRecord + 0x20;
        } while (level <= lastLevel);
      }
      face = face + 1;
      if (faceCount <= face) break;
      iVar28 = M<int>(textureBytes + 0x14);
      uVar18 = (unsigned int)(UInt8)hwInfoBytes[0x1a];
    }
  }
  wordCount = M<UInt32>(hwInfoBytes + 8);
  M<UInt32>(self + kIOATIR500Accelerator_stateDestroyedByPageoff) = 1;
  M<UInt32>(self + kIOATIR500Accelerator_unknown_0x78) = 0;
  if ((wordCount & 1) != 0) {
    iVar15 = wordCount * 4;
    wordCount = wordCount + 1;
    M<UInt32>(record + iVar15) = 0x80000000;
  }
  M<UInt32>(self + kIOATIR500Accelerator_commandGLBytesPerSample) = wordCount * 4 + M<int>(self + kIOATIR500Accelerator_commandGLBytesPerSample);
  M<int>(self + kIOATIR500Accelerator_texturePageOutBytesPerSample) = size + M<int>(self + kIOATIR500Accelerator_texturePageOutBytesPerSample);
  iVar15 = M<int>(textureBytes + 0x14);
  stamp = this->submit_buffer((UInt32 *)record,
                         M<int>(hwInfoBytes + 4) * 4 + M<int>(textureBytes + 4) + 0xa00,wordCount);
  M<UInt32>(iVar15 + 0xc) = stamp;
  if (textureBytes[0x20] == 0x7) {
    M<UInt32>(M<int>(M<int>(textureBytes + 0x58) + 0x14) + 8) =
         M<UInt32>(M<int>(textureBytes + 0x14) + 0xc);
  }
  stamp = M<UInt32>(M<int>(textureBytes + 0x14) + 0xc);
  M<unsigned int>(hwInfoBytes + 0x20) = M<unsigned int>(hwInfoBytes + 0x20) | 0x10000000;
  M<UInt32>(hwInfoBytes + 0x1c) = stamp;
  return 1;
}
