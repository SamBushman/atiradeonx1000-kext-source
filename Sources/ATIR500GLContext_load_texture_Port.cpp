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

  UInt8 bVar1;
  UInt16 loadedBits;
  UInt16 dirtyBits;
  bool bVar4;
  SInt32 iVar5;
  SInt32 *mapping;
  SInt32 *hwInfo;
  SInt32 iVar8;
  SInt32 nextMipLevel;
  SInt32 waited;
  UInt32 uVar9;
  UInt32 *record;
  SInt32 iVar11;
  SInt32 iVar12;
  SInt32 iVar13;
  UInt32 uVar14;
  SInt32 iVar15;
  UInt32 *tileCursor;
  SInt32 iVar17;
  SInt32 gartAddress;
  SInt32 gartOffset;
  SInt32 nextNode;
  UInt32 uVar18;
  UInt32 uVar19;
  UInt32 uVar20;
  UInt32 uVar21;
  UInt8 *currentSurfaceBuffer;
  UInt32 uVar23;
  UInt32 uVar24;
  UInt32 uVar25;
  SInt32 textureOffset;
  SInt32 lodBlendWeight;
  UInt32 lastLevel;
  UInt32 uVar28;
  UInt32 uVar29;
  SInt32 *accelerator;
  UInt32 uVar31;
  SInt32 iVar32;
  SInt32 mipLevel;
  SInt32 waitTotal;
  UInt8 *innerBuffer;
  SInt32 payloadByteLen;
  
  iVar17 = M<SInt32>(textureBytes + 0x14);
  textureOffset = M<SInt32>(textureBytes + 0x48);
  uVar24 = (UInt32)M<UInt8>(iVar17 + 0x34);
  uVar25 = (UInt32)M<UInt8>(iVar17 + 0x17);
  lastLevel = (uVar25 + M<UInt8>(iVar17 + 0x35)) - 1;
  if (uVar24 == 0) {
    return;
  }
  uVar20 = 0;
  bVar4 = false;
  do {
    if (uVar25 <= lastLevel) {
      uVar18 = uVar25;
      do {
        if ((((UInt32)M<UInt16>(iVar17 + 0x1c) & ~(UInt32)M<UInt16>(iVar17 + 0x28)) >>
             (uVar18 & 0x3f) & 1) != 0) {
          bVar4 = true;
        }
        uVar18 = uVar18 + 1;
      } while (uVar18 <= lastLevel);
    }
    uVar20 = uVar20 + 1;
    iVar17 = iVar17 + 2;
  } while (uVar20 < uVar24);
  if (!bVar4) {
    return;
  }
  mapping = (SInt32 *)VCALL(*M<SInt32 *>(textureBytes + 8), 0x14c)
                            (M<SInt32 *>(textureBytes + 8),GH_kernel_task,0,
                             M<UInt32>(M<SInt32>(self + 200) + 0x82c) | 1,0,0);
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
      M<UInt32>(textureBytes + 0x34) = M<UInt32>(M<SInt32>(self + 200) + 0x6d0);
      M<SInt32>(textureBytes + 0x38) = M<SInt32>(self + 200) + 0x69c;
      M<UInt8 *>(M<SInt32>(self + 200) + 0x6d0) = textureBytes;
      M<UInt8 *>(M<SInt32>(textureBytes + 0x34) + 0x38) = textureBytes;
    }
LAB_00029704:
    if (textureBytes[0x20] != 0x7) goto LAB_00029724;
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
        if (gartOffset != 0) goto LAB_00029660;
      }
      else {
LAB_00029660:
        GH_IOGetTime(textureBytes + 0x2c);
        nextNode = M<SInt32>(textureBytes + 0x34);
        M<UInt32>(nextNode + 0x38) = M<UInt32>(textureBytes + 0x38);
        M<SInt32>(M<SInt32>(textureBytes + 0x38) + 0x34) = nextNode;
        M<UInt32>(textureBytes + 0x34) = M<UInt32>(M<SInt32>(self + 200) + 0x6d0);
        M<SInt32>(textureBytes + 0x38) = M<SInt32>(self + 200) + 0x69c;
        M<UInt8 *>(M<SInt32>(self + 200) + 0x6d0) = textureBytes;
        M<UInt8 *>(M<SInt32>(textureBytes + 0x34) + 0x38) = textureBytes;
      }
      if (M<SInt32>(innerBuffer + 4) != 0) {
        GH_IOGetTime(innerBuffer + 0x2c);
        nextNode = M<SInt32>(innerBuffer + 0x34);
        M<UInt32>(nextNode + 0x38) = M<UInt32>(innerBuffer + 0x38);
        M<SInt32>(M<SInt32>(innerBuffer + 0x38) + 0x34) = nextNode;
        M<UInt32>(innerBuffer + 0x34) = M<UInt32>(M<SInt32>(self + 200) + 0x6d0);
        M<SInt32>(innerBuffer + 0x38) = M<SInt32>(self + 200) + 0x69c;
        M<UInt8 *>(M<SInt32>(self + 200) + 0x6d0) = innerBuffer;
        M<UInt8 *>(M<SInt32>(innerBuffer + 0x34) + 0x38) = innerBuffer;
      }
      goto LAB_00029704;
    }
LAB_00029724:
    payloadByteLen = M<SInt32>(textureBytes + 0x50);
    gartAddress = M<SInt32>(textureBytes + 4);
  }
  accelerator = M<SInt32 *>(self + 200);
  waitTotal = accelerator[0x1d5];
  waited = VCALL(*accelerator, 0x54c)(accelerator,M<UInt32>(M<SInt32>(textureBytes + 0x14) + 0xc));
  record = (UInt32 *)(hwInfo + 0x280);
  accelerator[0x1d5] = waitTotal + waited;
  gartAddress = gartAddress + M<SInt32>(M<SInt32>(self + 200) + 0x8a4);
  if (hwInfo[8] < 0) {
    if (M<SInt32>(textureBytes + 100) == 2) {
      hwInfo[0x285] = 1;
      uVar20 = 0;
    }
    else {
      uVar20 = 0;
      if (M<SInt32>(textureBytes + 100) == 4) {
        hwInfo[0x285] = 2;
        uVar20 = 0;
      }
    }
    do {
      if (lastLevel < uVar25) {
        iVar32 = M<SInt32>(textureBytes + 0x14);
        iVar8 = uVar20 << 1;
      }
      else {
        iVar32 = M<SInt32>(textureBytes + 0x14);
        iVar8 = uVar20 * 2;
        loadedBits = M<UInt16>(iVar8 + iVar32 + 0x28);
        dirtyBits = M<UInt16>(iVar8 + iVar32 + 0x1c);
        uVar18 = uVar25;
        do {
          iVar5 = uVar20 * 0xd + uVar18;
          uVar21 = (UInt32)M<UInt16>(hwInfo + iVar5 * 8 + 0x10);
          uVar14 = (UInt32)M<UInt16>((SInt32)hwInfo + iVar5 * 0x20 + 0x42);
          iVar11 = hwInfo[iVar5 * 8 + 0x11];
          iVar12 = uVar21 + 4;
          iVar13 = uVar21 + 7;
          iVar15 = hwInfo[iVar5 * 8 + 0x12];
          if (uVar14 == 0) {
            uVar14 = 1;
          }
          while( true ) {
            if ((((UInt32)dirtyBits & ~(UInt32)loadedBits) >> (uVar18 & 0x3f) & 1) == 0) {
              record[uVar21] = 0xc0101000;
            }
            else {
              record[uVar21] = 0x80000000;
              record[iVar12] = iVar11 + gartAddress;
              record[iVar13] = iVar15 + textureOffset;
            }
            uVar14 = uVar14 - 1;
            if (uVar14 == 0) break;
            uVar21 = uVar21 + 0x12;
            iVar12 = iVar12 + 0x12;
            iVar13 = iVar13 + 0x12;
            iVar11 = iVar11 + hwInfo[iVar5 * 8 + 0x13];
            iVar15 = iVar15 + hwInfo[iVar5 * 8 + 0x14];
          }
          uVar18 = uVar18 + 1;
        } while (uVar18 <= lastLevel);
      }
      iVar8 = iVar8 + iVar32;
      uVar20 = uVar20 + 1;
      M<UInt16>(iVar8 + 0x28) = M<UInt16>(iVar8 + 0x28) | M<UInt16>(iVar8 + 0x1c);
    } while (uVar20 < uVar24);
    iVar17 = *hwInfo;
    record[iVar17] = 0x50b;
    if (M<SInt32>(self + 0x3bc) == 0) {
      mipLevel = M<SInt32>(self + 0x29c);
      lodBlendWeight = M<SInt32>(self + 0x298);
      nextMipLevel = mipLevel + 1;
      currentSurfaceBuffer = *(UInt8 **)
                 ((UInt32)M<UInt16>(self + 0xac) * 4 + M<SInt32>(self + 0x290) + 0xb70);
    }
    else {
      lodBlendWeight = 0;
      mipLevel = 0;
      nextMipLevel = 1;
      currentSurfaceBuffer = self + (UInt32)M<UInt16>(self + 0x3b2) * 0x78 + 0x3c0;
    }
    uVar24 = 0;
    if ((M<UInt32>(currentSurfaceBuffer + 0x3c) & 0xf00000) != 0) {
      uVar24 = (UInt32)M<UInt16>(currentSurfaceBuffer + 0x14) / (M<UInt32>(currentSurfaceBuffer + 0x3c) >> 0x14 & 0xf);
    }
    uVar25 = 0x20 / M<UInt16>(currentSurfaceBuffer + 0x16);
    if (uVar25 <= uVar24) {
      uVar25 = uVar24;
    }
    lastLevel = 0x80000000;
    if ((UInt8)currentSurfaceBuffer[0x38] < 2) {
      lastLevel = 0;
    }
    uVar24 = iVar17 + 2;
    record[iVar17 + 1] =
         lastLevel | M<SInt32>(currentSurfaceBuffer + mipLevel * 4 + 0x40) * (UInt32)M<UInt16>(currentSurfaceBuffer + 0x20) +
                  lodBlendWeight * (M<SInt32>(currentSurfaceBuffer + nextMipLevel * 4 + 0x40) -
                           M<SInt32>(currentSurfaceBuffer + mipLevel * 4 + 0x40)) + M<SInt32>(currentSurfaceBuffer + 8) >> 10 |
                  uVar25 * M<UInt16>(currentSurfaceBuffer + 0x16) * 0x10000 & 0x3fc00000 |
                  ((UInt8)currentSurfaceBuffer[0x38] & 1) << 0x1e;
    goto LAB_00029cb4;
  }
  record = record + hwInfo[1];
  record[0xb] = M<UInt32>(M<SInt32>(self + 200) + 0xb74);
  iVar32 = M<SInt32>(textureBytes + 0x14);
  bVar1 = M<UInt8>(iVar32 + 0x15) >> 3;
  iVar8 = -(bVar1 & 3);
  if ((bVar1 & 2) == 0) {
    if (-1 < iVar8) {
      bVar4 = false;
      goto LAB_00029a5c;
    }
    uVar20 = (UInt32)M<UInt8>((SInt32)hwInfo + 0x1a);
    bVar4 = uVar20 == 0;
LAB_00029a64:
    if (3 < uVar20) goto LAB_00029a94;
    if (bVar4) {
      iVar5 = 2;
      iVar8 = 3;
    }
    else {
      iVar5 = 1;
      iVar8 = 4;
    }
  }
  else {
    bVar4 = true;
LAB_00029a5c:
    if (iVar8 < 0) {
      uVar20 = (UInt32)M<UInt8>((SInt32)hwInfo + 0x1a);
      goto LAB_00029a64;
    }
    uVar20 = (UInt32)M<UInt8>((SInt32)hwInfo + 0x1a);
LAB_00029a94:
    iVar5 = 0;
    iVar8 = 5;
  }
  uVar14 = 0;
  uVar18 = 0x20 >> (uVar20 & 0x3f);
  uVar21 = 1 << (iVar8 - uVar20 & 0x3f);
  while( true ) {
    uVar28 = (UInt32)M<UInt8>(iVar32 + 0x15);
    uVar29 = (UInt32)hwInfo[4] >> (uVar20 & 0x3f);
    uVar20 = (UInt32)hwInfo[3] >> (uVar20 & 0x3f);
    if (uVar25 <= lastLevel) {
      uVar31 = uVar25;
      while( true ) {
        iVar11 = uVar14 * 0xd + uVar31;
        iVar8 = iVar11 * 0x20;
        tileCursor = record + M<UInt16>(hwInfo + iVar11 * 8 + 0x16);
        if ((uVar28 & 4) != 0) {
          uVar19 = (SInt32)(UInt32)M<UInt16>((SInt32)hwInfo + 0x16) >> (uVar31 & 0x3f);
          uVar23 = 1 << iVar5;
          if (1 << iVar5 < (SInt32)uVar19) {
            uVar23 = uVar19;
          }
          if ((uVar20 < uVar21 << 3) || (iVar12 = 1, uVar23 < (UInt32)(1 << iVar5 + 3))) {
            iVar12 = 0;
          }
          uVar28 = iVar12 << 2 | uVar28 & 0xfffffffb;
        }
        iVar32 = uVar14 * 2 + iVar32;
        if ((((UInt32)M<UInt16>(iVar32 + 0x1c) & ~(UInt32)M<UInt16>(iVar32 + 0x28)) >>
             (uVar31 & 0x3f) & 1) == 0) {
          *tileCursor = ((UInt32)M<UInt16>((SInt32)hwInfo + iVar8 + 0x42) * 0x1d + -2) * 0x10000 |
                     0xc0001000;
        }
        else {
          iVar32 = hwInfo[iVar11 * 8 + 0x11];
          iVar12 = hwInfo[iVar11 * 8 + 0x12];
          *tileCursor = 0x138a;
          if (M<SInt16>((SInt32)hwInfo + iVar8 + 0x42) != 0) {
            iVar13 = 0;
            do {
              iVar13 = iVar13 + 1;
              tileCursor[1] = iVar12 + textureOffset;
              tileCursor[3] = (uVar20 >> 1 & 0x1fff) << 1 |
                           (uVar28 >> 3 & 3) << 0x11 |
                           (uVar28 >> 2 & 1) << 0x10 | tileCursor[3] & 0xffe0c001;
              bVar1 = M<UInt8>((SInt32)hwInfo + 0x1b);
              tileCursor[9] = uVar29 - 1 & 0x3fff | tileCursor[9] & 0xffffc000;
              tileCursor[5] = iVar32 + gartAddress & 0xffffffe0U | bVar1 & 3;
              tileCursor = tileCursor + 0x1d;
              iVar32 = iVar32 + hwInfo[iVar11 * 8 + 0x13];
              iVar12 = iVar12 + hwInfo[iVar11 * 8 + 0x14];
            } while (iVar13 < (SInt32)(UInt32)M<UInt16>((SInt32)hwInfo + iVar8 + 0x42));
          }
        }
        uVar23 = uVar20 >> 1;
        uVar20 = uVar29 >> 1;
        uVar29 = uVar18;
        if (uVar18 < uVar20) {
          uVar29 = uVar20;
        }
        uVar20 = uVar21;
        if (uVar21 < uVar23) {
          uVar20 = uVar23;
        }
        uVar31 = uVar31 + 1;
        if (lastLevel < uVar31) break;
        iVar32 = M<SInt32>(textureBytes + 0x14);
      }
      iVar32 = M<SInt32>(textureBytes + 0x14);
    }
    iVar32 = uVar14 * 2 + iVar32;
    uVar14 = uVar14 + 1;
    M<UInt16>(iVar32 + 0x28) = M<UInt16>(iVar32 + 0x28) | M<UInt16>(iVar32 + 0x1c);
    if (uVar24 <= uVar14) break;
    iVar32 = M<SInt32>(textureBytes + 0x14);
    uVar20 = (UInt32)M<UInt8>((SInt32)hwInfo + 0x1a);
  }
  uVar24 = hwInfo[2];
  M<UInt32>(M<SInt32>(self + 200) + 0xb90) = 1;
LAB_00029cb4:
  uVar25 = uVar24;
  if ((uVar24 & 1) != 0) {
    uVar25 = uVar24 + 1;
    record[uVar24] = 0x80000000;
  }
  M<UInt32>(M<SInt32>(self + 200) + 0x704) = uVar25 * 4 + M<SInt32>(M<SInt32>(self + 200) + 0x704);
  M<SInt32>(M<SInt32>(self + 200) + 0x71c) = payloadByteLen + M<SInt32>(M<SInt32>(self + 200) + 0x71c);
  if (hwInfo[8] < 0) {
    iVar17 = M<SInt32>(textureBytes + 0x14);
    uVar9 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 200)))->submit_buffer((UInt32 *)(record),M<SInt32>(textureBytes + 4) + 0xa00,uVar25);
    M<UInt32>(iVar17 + 0xc) = uVar9;
  }
  else {
    iVar17 = M<SInt32>(textureBytes + 0x14);
    uVar9 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 200)))->submit_buffer((UInt32 *)(record),
                       hwInfo[1] * 4 + M<SInt32>(textureBytes + 4) + 0xa00,uVar25);
    M<UInt32>(iVar17 + 0xc) = uVar9;
  }
  if (textureBytes[0x20] == 0x7) {
    M<UInt32>(M<SInt32>(M<SInt32>(textureBytes + 0x58) + 0x14) + 8) =
         M<UInt32>(M<SInt32>(textureBytes + 0x14) + 0xc);
  }
  VCALL(*mapping, 0x18)(mapping);
  return;
}
