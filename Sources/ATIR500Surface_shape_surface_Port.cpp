/*
 * ATIR500Surface_shape_surface_Port.cpp
 *
 * ATIR500Surface::shape_surface (real addr 0x3c130, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


extern "C" UInt32 window_mode_to_ati_format(UInt32 windowModeBits) asm("__Z25window_mode_to_ati_formatm");
extern const UInt32 kShapeSurfaceDefaultMipTable[14] asm("__ZZN14ATIR500Surface13shape_surfaceEvE5C.146");   /* shape_surface()::C.146 (real 0x4c284, 0x38 bytes, all zero), defined in ATIR500Surface_ShapeSurface.cpp */

/* real addr 0x3c130 */
void ATIR500Surface::shape_surface() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  SInt16 sVar2;
  UInt16 uVar3;
  UInt16 uVar4;
  UInt8 AVar5;
  UInt16 uVar6;
  UInt32 uVar7;
  UInt32 uVar8;
  SInt32 iVar9;
  UInt32 uVar10;
  SInt32 *piVar11;
  UInt8 AVar12;
  UInt32 uVar13;
  SInt32 surfaceWidth;
  UInt8 *pAVar15;
  SInt32 iVar16;
  SInt16 sVar18;
  UInt32 uVar17;
  UInt32 uVar19;
  UInt16 uVar20;
  UInt16 uVar21;
  UInt8 AVar22;
  SInt32 iVar23;
  UInt32 uVar24;
  SInt32 iVar25;
  UInt32 uVar26;
  SInt32 bufferRecordOffset;
  UInt32 uVar28;
  UInt32 uVar29;
  UInt8 bufferIds [8];
  SInt32 mipOffsets [14];
  UInt32 heightScale;
  UInt32 rowBytes;
  UInt32 formatBit;
  UInt32 pendingMask;
  UInt32 formatEntry;
  UInt32 scaledHeight;
  UInt32 bufferHeightScale;
  UInt32 pitchBytes;
  UInt32 modeBits;
  UInt32 bufferCount;
  UInt32 bufferId;
  UInt32 bytesPerPixel;
  UInt32 windowMode;
  UInt32 shapeMask;
  UInt32 alignedHeight;
  UInt32 overlayHeight;
  SInt32 widthScale;
  UInt32 bufferSlot;
  SInt32 bufferWidthScale;
  SInt32 rowWidth;
  UInt32 surfaceHeight;
  SInt32 storageBytes;
  
  M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0xb94) = 1;
  windowMode = M<UInt32>(self + kIOATIR500Surface_modeBits);
  if ((windowMode & 0x70000000) == 0) {
    shapeMask = M<UInt32>(self + kIOATIR500Surface_contextReqBits);
  }
  else {
    windowMode = windowMode & 0xff83ffff;
    M<UInt32>(self + kIOATIR500Surface_modeBits) = windowMode;
    shapeMask = M<UInt32>(self + kIOATIR500Surface_contextReqBits) & 0xfffffdff;
    M<UInt32>(self + kIOATIR500Surface_contextReqBits) = shapeMask;
  }
  if ((windowMode & 0x7c0000) == 0) {
LAB_0003c260:
    widthScale = 1;
    heightScale = 1;
  }
  else {
    uVar7 = windowMode & 0x700000;
    if (uVar7 == 0) {
      uVar7 = windowMode & 0xc0000;
      if (uVar7 == 0) goto LAB_0003c260;
      if (uVar7 == 0x40000) {
        widthScale = 1;
        heightScale = 2;
      }
      else if (uVar7 == 0x80000) {
        widthScale = 2;
        heightScale = 2;
      }
      else {
        widthScale = 1;
        heightScale = 1;
      }
      if (0x1000 < (UInt32)(widthScale * M<SInt16>(self + kIOATIR500Surface_width))) {
        widthScale = 1;
      }
      if (0x1000 < heightScale * (SInt32)M<SInt16>(self + kIOATIR500Surface_height)) {
        heightScale = 1;
      }
    }
    else if (uVar7 == 0x200000) {
      widthScale = 4;
      heightScale = 1;
    }
    else if (uVar7 == 0x400000) {
      widthScale = 6;
      heightScale = 1;
    }
    else {
      if (uVar7 != 0x100000) goto LAB_0003c260;
      widthScale = 2;
      heightScale = 1;
    }
  }
  if ((shapeMask & 0x1c0) != 0) {
    if (((windowMode & 0x30000) == 0x20000) || ((windowMode & 0x30000) == 0x30000)) {
      AVar12 = 0x29;
      AVar22 = 0x3;
      iVar16 = 0x29;
    }
    else {
      AVar12 = 0x10;
      AVar22 = 0x5;
      iVar16 = 0x10;
    }
    uVar7 = FormatTableLookup_0x0004d2dc(iVar16 * 0x1c);
    bytesPerPixel = 1 << (uVar7 >> 0xc & 7);
    if (M<SInt16>(self + kIOATIR500Surface_height) < 0x20) {
      if (AVar22 == 0x5) {
        AVar22 = 0x4;
      }
      else {
        AVar22 = 0x2;
      }
    }
    iVar16 = 0;
    bufferIds[0] = 6;
    bufferIds[1] = 7;
    bufferIds[2] = 8;
    do {
      bufferSlot = (UInt32)bufferIds[iVar16];
      if ((shapeMask >> (bufferSlot & 0x3f) & 1) != 0) {
        bufferHeightScale = heightScale;
        bufferWidthScale = widthScale;
        if (bufferSlot != 6) {
          bufferHeightScale = 1;
          bufferWidthScale = 1;
        }
        surfaceWidth = (SInt32)M<SInt16>(self + kIOATIR500Surface_width);
        rowWidth = surfaceWidth;
        if (((windowMode & 0x700000) != 0) && (bufferSlot == 6)) {
          rowWidth = surfaceWidth + 0x18;
        }
        rowBytes = rowWidth * bytesPerPixel;
        if ((rowBytes & 0xff) != 0) {
          rowBytes = (rowBytes & 0xffffff00) + 0x100;
        }
        surfaceHeight = (UInt32)M<SInt16>(self + kIOATIR500Surface_height);
        rowBytes = bufferWidthScale * rowBytes;
        alignedHeight = surfaceHeight;
        if ((surfaceHeight & 0x1f) != 0) {
          alignedHeight = (surfaceHeight - (SInt32)(SInt16)(M<SInt16>(self + kIOATIR500Surface_height) +
                                        (SInt16)(((SInt32)surfaceHeight >> 5) +
                                               (UInt32)((SInt32)surfaceHeight < 0 && (surfaceHeight & 0x1f) != 0)) *
                                        -0x20)) + 0x20;
        }
        bufferRecordOffset = bufferSlot * 0x78;
        storageBytes = bufferHeightScale * alignedHeight * rowBytes;
        if (((bytesPerPixel != M<UInt16>(self + bufferRecordOffset + 0xbe)) ||
            ((UInt32)M<UInt16>(self + bufferRecordOffset + 0xc4) != bufferWidthScale * surfaceWidth)) ||
           ((UInt32)M<UInt16>(self + bufferRecordOffset + 0xc6) != bufferHeightScale * surfaceHeight)) {
          if (M<SInt32>(self + bufferRecordOffset + 0xcc) != 0) {
            ((IOATIR500Surface *)((UInt8 *)self))->free_buffer_backing_store((ATIR500SurfaceBuffer *)((UInt8 *)(self + bufferRecordOffset + 0xa8)));
          }
          if (storageBytes != M<SInt32>(self + bufferRecordOffset + 0xb8)) {
            VCALL(M<SInt32>(self), 0x5cc)(self,bufferSlot);
            M<SInt32>(self + bufferRecordOffset + 0xb8) = storageBytes;
          }
          if (bytesPerPixel == 0) {
            M<UInt16>(self + bufferRecordOffset + 0xbc) = 0;
          }
          else {
            M<SInt16>(self + bufferRecordOffset + 0xbc) = (SInt16)(rowBytes / bytesPerPixel);
          }
          M<SInt16>(self + bufferRecordOffset + 0xc0) = (SInt16)rowBytes;
          M<SInt16>(self + bufferRecordOffset + 0xbe) = (SInt16)bytesPerPixel;
          M<SInt16>(self + bufferRecordOffset + 0xc4) = (SInt16)bufferWidthScale * M<SInt16>(self + kIOATIR500Surface_width);
          M<SInt16>(self + bufferRecordOffset + 0xc6) = (SInt16)bufferHeightScale * M<SInt16>(self + kIOATIR500Surface_height);
        }
        self[bufferRecordOffset + 0xe0] = AVar22;
        self[bufferRecordOffset + 0xe1] = ((UInt8)(uVar7 >> 10) & 3);
        self[bufferRecordOffset + 0xe3] = ((UInt8)(uVar7 >> 3) & 0x1f);
        self[bufferRecordOffset + 0xe2] = AVar12;
        if ((M<UInt32>(self + kIOATIR500Surface_modeBits) & 0x700000) == 0) {
          if ((M<UInt32>(self + kIOATIR500Surface_modeBits) & 0xc0000) == 0) {
            M<UInt32>(self + bufferRecordOffset + 0xe4) =
                 M<UInt32>(self + bufferRecordOffset + 0xe4) & 0xff000fff | 0x111000;
          }
          else {
            M<UInt32>(self + bufferRecordOffset + 0xe4) =
                 (bufferHeightScale & 0xf) << 0xc |
                 bufferWidthScale << 0x10 | M<UInt32>(self + bufferRecordOffset + 0xe4) & 0xff000fff | 0x100000;
          }
        }
        else {
          M<UInt32>(self + bufferRecordOffset + 0xe4) =
               bufferWidthScale << 0x14 | M<UInt32>(self + bufferRecordOffset + 0xe4) & 0xff000fff | 0x11000;
        }
        M<UInt32>(self + bufferRecordOffset + 0xe4) = M<UInt32>(self + bufferRecordOffset + 0xe4) | 0x800;
        windowMode = M<UInt32>(self + kIOATIR500Surface_modeBits);
        shapeMask = M<UInt32>(self + kIOATIR500Surface_contextReqBits);
      }
      bVar1 = iVar16 != 2;
      iVar16 = iVar16 + 1;
    } while (bVar1);
  }
  if ((windowMode & 0xf) < 0xe) {
    formatBit = 1 << (windowMode & 0xf);
    if ((formatBit & 0x1c18) == 0) {
      if (((formatBit & 0x2000) == 0) ||
         (AVar12 = 0x1, M<SInt16>(self + kIOATIR500Surface_height) < 0x10)) goto LAB_0003c52c;
    }
    else {
      AVar12 = ((0xf < M<SInt16>(self + kIOATIR500Surface_height)) + '\x02');
    }
  }
  else {
LAB_0003c52c:
    AVar12 = 0x0;
  }
  if ((M<SInt32>(self + kIOATIR500Surface_panel) != 0xffff) && ((shapeMask & 2) != 0)) {
    M<UInt8>(M<SInt32>(self + kIOATIR500Surface_panel) * 0x78 + M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x164) = AVar12;
    shapeMask = M<UInt32>(self + kIOATIR500Surface_contextReqBits);
  }
  if (M<SInt32>(self + kIOATIR500Surface_boundDVDContext) == 0) {
    pendingMask = shapeMask & 0x23f;
  }
  else {
    pendingMask = shapeMask & 0x7ffc03;
  }
  if (pendingMask == 0) {
    return;
  }
  uVar7 = M<UInt32>(self + kIOATIR500Surface_modeBits);
  iVar16 = window_mode_to_ati_format(uVar7 & 0xf);
  formatEntry = FormatTableLookup_0x0004d2dc(iVar16 * 0x1c);
  AVar22 = ((UInt8)(formatEntry >> 10) & 3);
  AVar5 = ((UInt8)(formatEntry >> 3) & 0x1f);
  bytesPerPixel = 1 << (formatEntry >> 0xc & 7);
  if ((shapeMask & 0x200) != 0) {
    if (((bytesPerPixel != M<UInt16>(self + kIOATIR500Surface_buffer9BytesPerRow)) ||
        ((UInt32)M<UInt16>(self + kIOATIR500Surface_buffer9HeightOrRows) != widthScale * M<SInt16>(self + kIOATIR500Surface_width))) ||
       ((UInt32)M<UInt16>(self + kIOATIR500Surface_buffer9Extra1e) != heightScale * (SInt32)M<SInt16>(self + kIOATIR500Surface_height))) {
      if (M<SInt32>(self + kIOATIR500Surface_buffer9BackingStore) != 0) {
        ((IOATIR500Surface *)((UInt8 *)self))->free_buffer_backing_store((ATIR500SurfaceBuffer *)((UInt8 *)(self + kIOATIR500Surface_buffer9)));
        uVar7 = M<UInt32>(self + kIOATIR500Surface_modeBits);
      }
      sVar2 = M<SInt16>(self + kIOATIR500Surface_width);
      iVar9 = (SInt32)sVar2;
      if ((uVar7 & 0x700000) != 0) {
        iVar9 = iVar9 + 0x18;
      }
      pitchBytes = iVar9 * bytesPerPixel;
      if ((pitchBytes & 0xff) != 0) {
        pitchBytes = (pitchBytes & 0xffffff00) + 0x100;
      }
      sVar18 = M<SInt16>(self + kIOATIR500Surface_height);
      pitchBytes = widthScale * pitchBytes;
      uVar24 = (UInt32)sVar18;
      if ((uVar24 & 0x1f) != 0) {
        uVar24 = (uVar24 - (SInt32)(SInt16)(sVar18 + (SInt16)(((SInt32)uVar24 >> 5) +
                                                        (UInt32)((SInt32)uVar24 < 0 &&
                                                              (uVar24 & 0x1f) != 0)) * -0x20)) +
                 0x20;
      }
      iVar9 = pitchBytes * heightScale * uVar24;
      if (iVar9 != M<SInt32>(self + kIOATIR500Surface_buffer9Storage)) {
        VCALL(M<SInt32>(self), 0x5cc)(self,9);
        M<SInt32>(self + kIOATIR500Surface_buffer9Storage) = iVar9;
        uVar7 = M<UInt32>(self + kIOATIR500Surface_modeBits);
        sVar2 = M<SInt16>(self + kIOATIR500Surface_width);
        sVar18 = M<SInt16>(self + kIOATIR500Surface_height);
      }
      if (bytesPerPixel == 0) {
        M<UInt16>(self + kIOATIR500Surface_buffer9Width) = 0;
      }
      else {
        M<SInt16>(self + kIOATIR500Surface_buffer9Width) = (SInt16)(pitchBytes / bytesPerPixel);
      }
      M<SInt16>(self + kIOATIR500Surface_buffer9Pitch) = (SInt16)pitchBytes;
      M<SInt16>(self + kIOATIR500Surface_buffer9BytesPerRow) = (SInt16)bytesPerPixel;
      M<SInt16>(self + kIOATIR500Surface_buffer9HeightOrRows) = (SInt16)widthScale * sVar2;
      M<SInt16>(self + kIOATIR500Surface_buffer9Extra1e) = (SInt16)heightScale * sVar18;
    }
    self[0x518] = AVar12;
    self[0x519] = AVar22;
    self[0x51b] = AVar5;
    self[0x51a] = SUB41m(iVar16,0);
    if ((uVar7 & 0x700000) == 0) {
      if ((uVar7 & 0xc0000) == 0) {
        M<UInt32>(self + kIOATIR500Surface_buffer9TilingDegreeBits) = M<UInt32>(self + kIOATIR500Surface_buffer9TilingDegreeBits) & 0xff000fff | 0x111000;
      }
      else {
        M<UInt32>(self + kIOATIR500Surface_buffer9TilingDegreeBits) =
             (heightScale & 0xf) << 0xc |
             widthScale << 0x10 | M<UInt32>(self + kIOATIR500Surface_buffer9TilingDegreeBits) & 0xff000fff | 0x100000;
      }
    }
    else {
      M<UInt32>(self + kIOATIR500Surface_buffer9TilingDegreeBits) = widthScale << 0x14 | M<UInt32>(self + kIOATIR500Surface_buffer9TilingDegreeBits) & 0xff000fff | 0x11000;
    }
  }
  GH_memcpy(mipOffsets,kShapeSurfaceDefaultMipTable,0x38);
  modeBits = M<UInt32>(self + kIOATIR500Surface_modeBits);
  if ((modeBits & 0x20) == 0) {
    uVar26 = 0;
    uVar7 = 1;
    uVar8 = 1;
    iVar23 = M<SInt32>(self + kIOATIR500Surface_panel) * 0x78 + M<SInt32>(self + kIOATIR500Surface_accelerator);
    iVar9 = M<SInt32>(iVar23 + 0x13c);
    uVar24 = (UInt32)M<UInt16>(iVar23 + 0x144);
  }
  else if ((modeBits & 0x70000000) == 0) {
    uVar24 = bytesPerPixel * (SInt32)M<SInt16>(self + kIOATIR500Surface_width);
    if ((uVar24 & 0xff) != 0) {
      uVar24 = (uVar24 & 0xffffff00) + 0x100;
    }
    alignedHeight = (UInt32)M<SInt16>(self + kIOATIR500Surface_height);
    if ((alignedHeight & 0x1f) != 0) {
      alignedHeight = (alignedHeight - (SInt32)(SInt16)(M<SInt16>(self + kIOATIR500Surface_height) +
                                     (SInt16)(((SInt32)alignedHeight >> 5) +
                                            (UInt32)((SInt32)alignedHeight < 0 && (alignedHeight & 0x1f) != 0)) * -0x20
                                     )) + 0x20;
    }
    iVar9 = uVar24 * alignedHeight;
    uVar26 = 0;
    uVar7 = 1;
    uVar8 = 1;
  }
  else {
    uVar7 = (UInt32)M<SInt16>(self + kIOATIR500Surface_width);
    uVar8 = bytesPerPixel * uVar7;
    uVar24 = uVar8;
    if ((uVar8 & 0xff) != 0) {
      uVar24 = (uVar8 & 0xffffff00) + 0x100;
    }
    uVar13 = (UInt32)M<SInt16>(self + kIOATIR500Surface_height);
    uVar26 = modeBits >> 0x18 & 0xf;
    iVar9 = 0;
    uVar17 = 0;
    uVar19 = uVar13;
    while( true ) {
      bVar1 = uVar17 != 0;
      mipOffsets[uVar17] = iVar9;
      if (bVar1) {
        uVar10 = 0x20;
      }
      else {
        uVar10 = 0x100;
      }
      if (uVar8 != (uVar8 / uVar10) * uVar10) {
        if (bVar1) {
          uVar10 = 0x20;
          iVar23 = 0x20;
        }
        else {
          uVar10 = 0x100;
          iVar23 = 0x100;
        }
        uVar8 = iVar23 + (uVar8 / uVar10) * uVar10;
      }
      uVar10 = uVar19;
      if ((!bVar1) && ((uVar19 & 0x1f) != 0)) {
        uVar10 = (uVar19 & 0xffffffe0) + 0x20;
      }
      iVar9 = iVar9 + uVar8 * uVar10;
      if (1 < uVar7) {
        uVar7 = uVar7 >> 1;
      }
      if (1 < uVar19) {
        uVar19 = uVar19 >> 1;
      }
      uVar17 = uVar17 + 1;
      if (uVar26 < uVar17) break;
      uVar8 = bytesPerPixel * uVar7;
    }
    uVar8 = uVar26 + 1;
    uVar7 = 6;
    mipOffsets[uVar17] = iVar9;
    if ((modeBits & 0x70000000) != 0x30000000) {
      uVar7 = 1;
    }
    iVar9 = iVar9 * uVar7;
    if (bytesPerPixel == 0x10) {
      if (uVar8 == 1) {
        if (uVar7 == 1) {
          if ((SInt32)uVar13 < 0x10) {
            AVar12 = 0x0;
            uVar7 = 1;
          }
          else {
            AVar12 = 0x1;
            uVar7 = 1;
            uVar8 = 1;
          }
        }
        else {
LAB_0003c9c4:
          AVar12 = 0x0;
          uVar8 = 1;
        }
      }
      else {
LAB_0003c9d0:
        AVar12 = 0x0;
      }
    }
    else {
      if (uVar8 != 1) goto LAB_0003c9d0;
      if (uVar7 != 1) goto LAB_0003c9c4;
      if ((SInt32)uVar13 < 0x10) {
        AVar12 = 0x2;
        uVar7 = 1;
      }
      else {
        AVar12 = 0x3;
        uVar7 = 1;
      }
    }
  }
  bufferIds[0] = 0;
  bufferIds[1] = 1;
  if (M<SInt32>(self + kIOATIR500Surface_boundDVDContext) == 0) {
    bufferCount = 6;
    bufferIds[2] = 5;
    bufferIds[3] = 4;
    bufferIds[4] = 2;
    bufferIds[5] = 3;
  }
  else {
    iVar23 = (SInt32)M<SInt16>(self + kATIR500Surface_overlayLeft) - (SInt32)M<SInt16>(self + kATIR500Surface_overlayRight);
    overlayHeight = (SInt32)M<SInt16>(self + kATIR500Surface_overlayBottom) - (SInt32)M<SInt16>(self + kATIR500Surface_overlayTop);
    if (iVar23 == 0) {
      iVar23 = 0x300;
      uVar6 = 0x300;
    }
    else {
      uVar6 = (UInt16)iVar23;
    }
    if (overlayHeight == 0) {
      overlayHeight = 0x240;
      uVar19 = 0;
      uVar21 = 0x240;
    }
    else {
      uVar19 = overlayHeight & 0xf;
      uVar21 = (UInt16)overlayHeight;
    }
    uVar24 = iVar23 * bytesPerPixel;
    if ((uVar24 & 0xff) != 0) {
      uVar24 = (uVar24 & 0xffffff00) + 0x100;
    }
    if (uVar19 != 0) {
      overlayHeight = (overlayHeight & 0xfffffff0) + 0x10;
    }
    iVar9 = uVar24 * overlayHeight;
    M<UInt16>(self + kIOATIR500Surface_scalingSourceWidth) = uVar6;
    M<UInt16>(self + kIOATIR500Surface_scalingSourceHeight) = uVar21;
    self[0xbec] = 0x1;
    M<UInt16>(self + kIOATIR500Surface_width) = uVar6;
    M<UInt16>(self + kIOATIR500Surface_height) = uVar21;
    bufferCount = 2;
  }
  uVar13 = M<UInt32>(self + kIOATIR500Surface_contextReqBits);
  uVar19 = 0;
  do {
    uVar17 = (UInt32)bufferIds[uVar19];
    if ((uVar13 >> (uVar17 & 0x3f) & 1) != 0) {
      iVar23 = uVar17 * 0x78;
      if (((bytesPerPixel != M<UInt16>(self + iVar23 + 0xbe)) ||
          ((UInt32)M<UInt16>(self + iVar23 + 0xc4) != (SInt32)M<SInt16>(self + kIOATIR500Surface_width))) ||
         (((UInt32)M<UInt16>(self + iVar23 + 0xc6) != (SInt32)M<SInt16>(self + kIOATIR500Surface_height) ||
          ((uVar7 != M<UInt16>(self + iVar23 + 200) ||
           (uVar8 != M<UInt16>(self + iVar23 + 0xca))))))) {
        if (M<SInt32>(self + iVar23 + 0xcc) != 0) {
          ((IOATIR500Surface *)((UInt8 *)self))->free_buffer_backing_store((ATIR500SurfaceBuffer *)((UInt8 *)(self + iVar23 + 0xa8)));
        }
        if (iVar9 != M<SInt32>(self + iVar23 + 0xb8)) {
          VCALL(M<SInt32>(self), 0x5cc)(self,uVar17);
          M<SInt32>(self + iVar23 + 0xb8) = iVar9;
        }
        if (bytesPerPixel == 0) {
          M<UInt16>(self + iVar23 + 0xbc) = 0;
        }
        else {
          M<SInt16>(self + iVar23 + 0xbc) = (SInt16)(uVar24 / bytesPerPixel);
        }
        uVar13 = 0;
        M<SInt16>(self + iVar23 + 0xbe) = (SInt16)bytesPerPixel;
        M<SInt16>(self + iVar23 + 0xc0) = (SInt16)uVar24;
        pAVar15 = self + iVar23 + 0xe8;
        M<UInt16>(self + iVar23 + 0xc4) = M<UInt16>(self + kIOATIR500Surface_width);
        uVar6 = M<UInt16>(self + kIOATIR500Surface_height);
        M<SInt16>(self + iVar23 + 0xca) = (SInt16)uVar8;
        M<SInt16>(self + iVar23 + 200) = (SInt16)uVar7;
        M<UInt16>(self + iVar23 + 0xc6) = uVar6;
        piVar11 = mipOffsets;
        do {
          uVar13 = uVar13 + 1;
          iVar25 = *piVar11;
          piVar11 = piVar11 + 1;
          M<SInt32>(pAVar15) = iVar25;
          pAVar15 = pAVar15 + 4;
        } while (uVar13 <= uVar26 + 1);
      }
      self[iVar23 + 0xe2] = SUB41m(iVar16,0);
      self[iVar23 + 0xe0] = AVar12;
      self[iVar23 + 0xe1] = AVar22;
      self[iVar23 + 0xe3] = AVar5;
      uVar13 = M<UInt32>(self + kIOATIR500Surface_contextReqBits);
    }
    uVar19 = uVar19 + 1;
  } while (uVar19 < bufferCount);
  if ((uVar13 & 0x7ffc00) == 0) {
    return;
  }
  if (M<SInt32>(self + kIOATIR500Surface_boundDVDContext) == 0) {
    return;
  }
  sVar2 = M<SInt16>(self + kATIR500Surface_overlayLeft);
  sVar18 = M<SInt16>(self + kATIR500Surface_overlayRight);
  bufferId = 10;
  iVar23 = (SInt32)M<SInt16>(self + kATIR500Surface_overlayBottom) - (SInt32)M<SInt16>(self + kATIR500Surface_overlayTop);
  scaledHeight = iVar23 * 3;
  uVar6 = (UInt16)scaledHeight;
  uVar21 = (UInt16)(scaledHeight >> 1);
  pAVar15 = self;
  while( true ) {
    if ((1 << (bufferId & 0x3f) & uVar13) != 0) {
      if (M<SInt32>(pAVar15 + 0x57c) != 0) {
        ((IOATIR500Surface *)((UInt8 *)self))->free_buffer_backing_store((ATIR500SurfaceBuffer *)((UInt8 *)(self + bufferId * 0x78 + 0xa8)));
      }
      M<SInt16>(pAVar15 + 0x574) = sVar2 - sVar18;
      uVar20 = uVar21;
      if ((((M<SInt32>(self + kATIR500Surface_deintMode) != 0) && (9 < bufferId)) && (bufferId < 0xf)) &&
         ((uVar20 = uVar6, M<SInt32>(pAVar15 + 0x560) != 0 &&
          ((UInt32)M<UInt16>(pAVar15 + 0x576) != (scaledHeight & 0xffff))))) {
        ((IOATIR500Surface *)((UInt8 *)self))->copy_buffer_to_backing_store((ATIR500SurfaceBuffer *)((UInt8 *)(self + bufferId * 0x78 + 0xa8)));
      }
      M<UInt16>(pAVar15 + 0x576) = uVar20;
      if (bufferId == 0x11) {
        self[0x8da] = 0x2e;
      }
      else if (bufferId == 0x10) {
        M<UInt16>(self + kIOATIR500Surface_buffer16HeightOrRows) = 0x2d0;
        if ((iVar23 == 0x240) || (iVar23 == 0x120)) {
          M<UInt16>(self + kIOATIR500Surface_buffer16Extra1e) = 0x240;
        }
        else {
          M<UInt16>(self + kIOATIR500Surface_buffer16Extra1e) = 0x1e0;
        }
        self[0x862] = 0xb;
      }
      else if (bufferId == 0x12) {
        M<SInt16>(self + kIOATIR500Surface_buffer18Extra1e) = (SInt16)iVar23;
        self[0x952] = 0xb;
      }
      else {
        pAVar15[0x592] = 0x2d;
      }
      uVar3 = M<UInt16>(pAVar15 + 0x574);
      uVar24 = (UInt32)uVar3;
      iVar16 = (UInt32)(UInt8)pAVar15[0x592] * 0x1c;
      pAVar15[0x593] = ((UInt8)(FormatTableLookup_0x0004d2dc(iVar16) >> 3) & 0x1f);
      uVar7 = 1 << (FormatTableLookup_0x0004d2dc(iVar16) >> 0xc & 7);
      uVar20 = (UInt16)uVar7;
      M<UInt16>(pAVar15 + 0x56e) = uVar20;
      pAVar15[0x591] = ((UInt8)(FormatTableLookup_0x0004d2dc(iVar16) >> 10) & 3);
      if ((uVar3 & 0xff) != 0) {
        uVar24 = (uVar3 & 0xffffff00) + 0x100;
      }
      uVar7 = uVar7 & 0xffff;
      M<SInt16>(pAVar15 + 0x570) = (SInt16)(uVar24 * uVar7);
      if (uVar7 == 0) {
        M<UInt16>(pAVar15 + 0x56c) = uVar20;
      }
      else {
        M<SInt16>(pAVar15 + 0x56c) = (SInt16)((uVar24 * uVar7 & 0xffff) / uVar7);
      }
      if (bufferId == 0x12) {
        self[0x950] = AVar12;
      }
      else {
        pAVar15[0x590] = 0x0;
      }
      uVar3 = M<UInt16>(pAVar15 + 0x570);
      uVar4 = M<UInt16>(pAVar15 + 0x576);
      if ((UInt32)uVar3 * (UInt32)uVar4 != M<SInt32>(pAVar15 + 0x568)) {
        VCALL(M<SInt32>(self), 0x5cc)(self,bufferId);
        M<UInt32>(pAVar15 + 0x568) = (UInt32)uVar3 * (UInt32)uVar4;
      }
    }
    bVar1 = bufferId == 0x16;
    pAVar15 = pAVar15 + 0x78;
    bufferId = bufferId + 1;
    if (bVar1) break;
    uVar13 = M<UInt32>(self + kIOATIR500Surface_contextReqBits);
  }
  if (M<SInt32>(self + kATIR500Surface_overlayExists) != 0) {
    if (self[0xbf0] != 0x0) goto LAB_0003ce90;
    AVar12 = this->alloc_overlay();
    self[0xbf0] = AVar12;
  }
  if (self[0xbf0] == 0x0) {
    return;
  }
LAB_0003ce90:
  iVar23 = this->getFramebufferIndex();
  piVar11 = M<SInt32 *>(self + iVar23 * 8 + 0xd60);
  if (((*piVar11 != 0) && (M<SInt16>(piVar11 + 4) != 0)) && (M<SInt16>((SInt32)piVar11 + 0x12) != 0))
  {
    setup_overlay();
  }
  return;
}
