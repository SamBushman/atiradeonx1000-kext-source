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

/* PERF NOTE (NOT APPLIED). Estimated cycles rebuilt/stock 1.10-1.13 (1.30 before the float/divide/halfword-store fixes). Cause: the shipped code builds its
 * register images with 18 rlwimi (bitfield insert); gcc 4.0.1 does not form rlwimi from the `a & mask | b & mask` chains used here. Closing it: write the
 * format and pitch words as bitfield structs with the real register layouts (needs the layouts; the named locals stay). */
/* real addr 0x3c130 */
void ATIR500Surface::shape_surface() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool notLast;
  bool notFirstLevel;
  bool isLast;
  SInt16 surfaceWidth16;
  SInt16 overlayRight;
  UInt16 bufferWidth16;
  UInt16 pitch16;
  UInt16 height16;
  UInt8 fmtBitsB;
  UInt16 overlayWidth16;
  UInt16 heightField;
  UInt16 scaledHeight16;
  UInt32 scaleCode;
  UInt32 formatEntry1;
  UInt32 modeBitsNow;
  UInt32 faceCount;
  UInt32 mipWidth;
  UInt32 bytesPerPixelOv;
  UInt32 levelCount;
  UInt32 levelPitch;
  SInt32 widthPixels;
  SInt32 buffer9Storage;
  SInt32 storageSize;
  UInt32 levelAlign;
  UInt32 levelAlignedHeight;
  SInt32 *mipSource;
  SInt32 *framebufferRecord;
  UInt8 bufferFormatIndex;
  UInt8 tilingMode;
  UInt8 overlayAllocated;
  UInt32 baseHeight;
  UInt32 reqBits;
  UInt32 mipIndex;
  SInt32 surfaceWidth;
  UInt8 *mipOffsetCursor;
  UInt8 *bufferRecordPtr;
  SInt32 ovFormatOffset;
  SInt32 formatIdx;
  SInt32 loopIndex;
  SInt32 atiFormatIndex;
  SInt16 surfaceHeight16;
  SInt16 overlayLeft;
  UInt32 levelIndex;
  UInt32 bufferIdLocal;
  UInt32 levelHeight;
  UInt32 overlayHeightLow;
  UInt32 bufferListIndex;
  UInt16 heightValue;
  UInt16 bytesPerPixel16;
  UInt16 overlayHeight16;
  UInt16 halfScaledHeight16;
  UInt8 bufferTilingByte;
  UInt8 fmtBitsA;
  SInt32 panelAccel;
  SInt32 alignUnit;
  SInt32 overlayWidth;
  SInt32 bufferRecord;
  SInt32 overlayHeightPx;
  SInt32 framebufferIndex;
  UInt32 alignedHeight9;
  UInt32 bufferRowBytes;
  UInt32 alignedWidth;
  SInt32 mipOffset;
  UInt32 mipCount;
  SInt32 bufferRecordOffset;
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
    scaleCode = windowMode & 0x700000;
    if (scaleCode == 0) {
      scaleCode = windowMode & 0xc0000;
      if (scaleCode == 0) goto LAB_0003c260;
      if (scaleCode == 0x40000) {
        widthScale = 1;
        heightScale = 2;
      }
      else if (scaleCode == 0x80000) {
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
    else if (scaleCode == 0x200000) {
      widthScale = 4;
      heightScale = 1;
    }
    else if (scaleCode == 0x400000) {
      widthScale = 6;
      heightScale = 1;
    }
    else {
      if (scaleCode != 0x100000) goto LAB_0003c260;
      widthScale = 2;
      heightScale = 1;
    }
  }
  if ((shapeMask & 0x1c0) != 0) {
    if (((windowMode & 0x30000) == 0x20000) || ((windowMode & 0x30000) == 0x30000)) {
      bufferFormatIndex = 0x29;
      bufferTilingByte = 0x3;
      formatIdx = 0x29;
    }
    else {
      bufferFormatIndex = 0x10;
      bufferTilingByte = 0x5;
      formatIdx = 0x10;
    }
    formatEntry1 = FormatTableLookup_0x0004d2dc(formatIdx * 0x1c);
    bytesPerPixel = 1 << (formatEntry1 >> 0xc & 7);
    if (M<SInt16>(self + kIOATIR500Surface_height) < 0x20) {
      if (bufferTilingByte == 0x5) {
        bufferTilingByte = 0x4;
      }
      else {
        bufferTilingByte = 0x2;
      }
    }
    loopIndex = 0;
    bufferIds[0] = 6;
    bufferIds[1] = 7;
    bufferIds[2] = 8;
    do {
      bufferSlot = (UInt32)bufferIds[loopIndex];
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
            storeHalf(&M<UInt16>(self + bufferRecordOffset + 0xbc), (rowBytes / bytesPerPixel));
          }
          storeHalf(&M<UInt16>(self + bufferRecordOffset + 0xc0), rowBytes);
          storeHalf(&M<UInt16>(self + bufferRecordOffset + 0xbe), bytesPerPixel);
          storeHalf(&M<UInt16>(self + bufferRecordOffset + 0xc4), (SInt16)bufferWidthScale * M<SInt16>(self + kIOATIR500Surface_width));
          storeHalf(&M<UInt16>(self + bufferRecordOffset + 0xc6), (SInt16)bufferHeightScale * M<SInt16>(self + kIOATIR500Surface_height));
        }
        self[bufferRecordOffset + 0xe0] = bufferTilingByte;
        self[bufferRecordOffset + 0xe1] = ((UInt8)(formatEntry1 >> 10) & 3);
        self[bufferRecordOffset + 0xe3] = ((UInt8)(formatEntry1 >> 3) & 0x1f);
        self[bufferRecordOffset + 0xe2] = bufferFormatIndex;
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
      notLast = loopIndex != 2;
      loopIndex = loopIndex + 1;
    } while (notLast);
  }
  if ((windowMode & 0xf) < 0xe) {
    formatBit = 1 << (windowMode & 0xf);
    if ((formatBit & 0x1c18) == 0) {
      if (((formatBit & 0x2000) == 0) ||
         (tilingMode = 0x1, M<SInt16>(self + kIOATIR500Surface_height) < 0x10)) goto LAB_0003c52c;
    }
    else {
      tilingMode = ((0xf < M<SInt16>(self + kIOATIR500Surface_height)) + '\x02');
    }
  }
  else {
LAB_0003c52c:
    tilingMode = 0x0;
  }
  if ((M<SInt32>(self + kIOATIR500Surface_panel) != 0xffff) && ((shapeMask & 2) != 0)) {
    M<UInt8>(M<SInt32>(self + kIOATIR500Surface_panel) * 0x78 + M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x164) = tilingMode;
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
  modeBitsNow = M<UInt32>(self + kIOATIR500Surface_modeBits);
  atiFormatIndex = window_mode_to_ati_format(modeBitsNow & 0xf);
  formatEntry = FormatTableLookup_0x0004d2dc(atiFormatIndex * 0x1c);
  fmtBitsA = ((UInt8)(formatEntry >> 10) & 3);
  fmtBitsB = ((UInt8)(formatEntry >> 3) & 0x1f);
  bytesPerPixel = 1 << (formatEntry >> 0xc & 7);
  if ((shapeMask & 0x200) != 0) {
    if (((bytesPerPixel != M<UInt16>(self + kIOATIR500Surface_buffer9BytesPerPixel)) ||
        ((UInt32)M<UInt16>(self + kIOATIR500Surface_buffer9Width) != widthScale * M<SInt16>(self + kIOATIR500Surface_width))) ||
       ((UInt32)M<UInt16>(self + kIOATIR500Surface_buffer9Height) != heightScale * (SInt32)M<SInt16>(self + kIOATIR500Surface_height))) {
      if (M<SInt32>(self + kIOATIR500Surface_buffer9BackingStore) != 0) {
        ((IOATIR500Surface *)((UInt8 *)self))->free_buffer_backing_store((ATIR500SurfaceBuffer *)((UInt8 *)(self + kIOATIR500Surface_buffer9)));
        modeBitsNow = M<UInt32>(self + kIOATIR500Surface_modeBits);
      }
      surfaceWidth16 = M<SInt16>(self + kIOATIR500Surface_width);
      widthPixels = (SInt32)surfaceWidth16;
      if ((modeBitsNow & 0x700000) != 0) {
        widthPixels = widthPixels + 0x18;
      }
      pitchBytes = widthPixels * bytesPerPixel;
      if ((pitchBytes & 0xff) != 0) {
        pitchBytes = (pitchBytes & 0xffffff00) + 0x100;
      }
      surfaceHeight16 = M<SInt16>(self + kIOATIR500Surface_height);
      pitchBytes = widthScale * pitchBytes;
      alignedHeight9 = (UInt32)surfaceHeight16;
      if ((alignedHeight9 & 0x1f) != 0) {
        alignedHeight9 = (alignedHeight9 - (SInt32)(SInt16)(surfaceHeight16 + (SInt16)(((SInt32)alignedHeight9 >> 5) +
                                                        (UInt32)((SInt32)alignedHeight9 < 0 &&
                                                              (alignedHeight9 & 0x1f) != 0)) * -0x20)) +
                 0x20;
      }
      buffer9Storage = pitchBytes * heightScale * alignedHeight9;
      if (buffer9Storage != M<SInt32>(self + kIOATIR500Surface_buffer9StorageBytes)) {
        VCALL(M<SInt32>(self), 0x5cc)(self,9);
        M<SInt32>(self + kIOATIR500Surface_buffer9StorageBytes) = buffer9Storage;
        modeBitsNow = M<UInt32>(self + kIOATIR500Surface_modeBits);
        surfaceWidth16 = M<SInt16>(self + kIOATIR500Surface_width);
        surfaceHeight16 = M<SInt16>(self + kIOATIR500Surface_height);
      }
      if (bytesPerPixel == 0) {
        M<UInt16>(self + kIOATIR500Surface_buffer9PitchPixels) = 0;
      }
      else {
        storeHalf(&M<UInt16>(self + kIOATIR500Surface_buffer9PitchPixels), (pitchBytes / bytesPerPixel));
      }
      storeHalf(&M<UInt16>(self + kIOATIR500Surface_buffer9PitchBytes), pitchBytes);
      storeHalf(&M<UInt16>(self + kIOATIR500Surface_buffer9BytesPerPixel), bytesPerPixel);
      storeHalf(&M<UInt16>(self + kIOATIR500Surface_buffer9Width), (SInt16)widthScale * surfaceWidth16);
      storeHalf(&M<UInt16>(self + kIOATIR500Surface_buffer9Height), (SInt16)heightScale * surfaceHeight16);
    }
    self[0x518] = tilingMode;
    self[0x519] = fmtBitsA;
    self[0x51b] = fmtBitsB;
    self[0x51a] = SUB41m(atiFormatIndex,0);
    if ((modeBitsNow & 0x700000) == 0) {
      if ((modeBitsNow & 0xc0000) == 0) {
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
    mipCount = 0;
    faceCount = 1;
    levelCount = 1;
    panelAccel = M<SInt32>(self + kIOATIR500Surface_panel) * 0x78 + M<SInt32>(self + kIOATIR500Surface_accelerator);
    storageSize = M<SInt32>(panelAccel + 0x13c);
    bufferRowBytes = (UInt32)M<UInt16>(panelAccel + 0x144);
  }
  else if ((modeBits & 0x70000000) == 0) {
    bufferRowBytes = bytesPerPixel * (SInt32)M<SInt16>(self + kIOATIR500Surface_width);
    if ((bufferRowBytes & 0xff) != 0) {
      bufferRowBytes = (bufferRowBytes & 0xffffff00) + 0x100;
    }
    alignedHeight = (UInt32)M<SInt16>(self + kIOATIR500Surface_height);
    if ((alignedHeight & 0x1f) != 0) {
      alignedHeight = (alignedHeight - (SInt32)(SInt16)(M<SInt16>(self + kIOATIR500Surface_height) +
                                     (SInt16)(((SInt32)alignedHeight >> 5) +
                                            (UInt32)((SInt32)alignedHeight < 0 && (alignedHeight & 0x1f) != 0)) * -0x20
                                     )) + 0x20;
    }
    storageSize = bufferRowBytes * alignedHeight;
    mipCount = 0;
    faceCount = 1;
    levelCount = 1;
  }
  else {
    mipWidth = (UInt32)M<SInt16>(self + kIOATIR500Surface_width);
    levelPitch = bytesPerPixel * mipWidth;
    bufferRowBytes = levelPitch;
    if ((levelPitch & 0xff) != 0) {
      bufferRowBytes = (levelPitch & 0xffffff00) + 0x100;
    }
    baseHeight = (UInt32)M<SInt16>(self + kIOATIR500Surface_height);
    mipCount = modeBits >> 0x18 & 0xf;
    storageSize = 0;
    levelIndex = 0;
    levelHeight = baseHeight;
    while( true ) {
      notFirstLevel = levelIndex != 0;
      mipOffsets[levelIndex] = storageSize;
      if (notFirstLevel) {
        levelAlign = 0x20;
      }
      else {
        levelAlign = 0x100;
      }
      if (levelPitch != (levelPitch / levelAlign) * levelAlign) {
        if (notFirstLevel) {
          levelAlign = 0x20;
          alignUnit = 0x20;
        }
        else {
          levelAlign = 0x100;
          alignUnit = 0x100;
        }
        levelPitch = alignUnit + (levelPitch / levelAlign) * levelAlign;
      }
      levelAlignedHeight = levelHeight;
      if ((!notFirstLevel) && ((levelHeight & 0x1f) != 0)) {
        levelAlignedHeight = (levelHeight & 0xffffffe0) + 0x20;
      }
      storageSize = storageSize + levelPitch * levelAlignedHeight;
      if (1 < mipWidth) {
        mipWidth = mipWidth >> 1;
      }
      if (1 < levelHeight) {
        levelHeight = levelHeight >> 1;
      }
      levelIndex = levelIndex + 1;
      if (mipCount < levelIndex) break;
      levelPitch = bytesPerPixel * mipWidth;
    }
    levelCount = mipCount + 1;
    faceCount = 6;
    mipOffsets[levelIndex] = storageSize;
    if ((modeBits & 0x70000000) != 0x30000000) {
      faceCount = 1;
    }
    storageSize = storageSize * faceCount;
    if (bytesPerPixel == 0x10) {
      if (levelCount == 1) {
        if (faceCount == 1) {
          if ((SInt32)baseHeight < 0x10) {
            tilingMode = 0x0;
            faceCount = 1;
          }
          else {
            tilingMode = 0x1;
            faceCount = 1;
            levelCount = 1;
          }
        }
        else {
LAB_0003c9c4:
          tilingMode = 0x0;
          levelCount = 1;
        }
      }
      else {
LAB_0003c9d0:
        tilingMode = 0x0;
      }
    }
    else {
      if (levelCount != 1) goto LAB_0003c9d0;
      if (faceCount != 1) goto LAB_0003c9c4;
      if ((SInt32)baseHeight < 0x10) {
        tilingMode = 0x2;
        faceCount = 1;
      }
      else {
        tilingMode = 0x3;
        faceCount = 1;
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
    overlayWidth = (SInt32)M<SInt16>(self + kATIR500Surface_overlayRight) - (SInt32)M<SInt16>(self + kATIR500Surface_overlayLeft);
    overlayHeight = (SInt32)M<SInt16>(self + kATIR500Surface_overlayBottom) - (SInt32)M<SInt16>(self + kATIR500Surface_overlayTop);
    if (overlayWidth == 0) {
      overlayWidth = 0x300;
      overlayWidth16 = 0x300;
    }
    else {
      overlayWidth16 = (UInt16)overlayWidth;
    }
    if (overlayHeight == 0) {
      overlayHeight = 0x240;
      overlayHeightLow = 0;
      overlayHeight16 = 0x240;
    }
    else {
      overlayHeightLow = overlayHeight & 0xf;
      overlayHeight16 = (UInt16)overlayHeight;
    }
    bufferRowBytes = overlayWidth * bytesPerPixel;
    if ((bufferRowBytes & 0xff) != 0) {
      bufferRowBytes = (bufferRowBytes & 0xffffff00) + 0x100;
    }
    if (overlayHeightLow != 0) {
      overlayHeight = (overlayHeight & 0xfffffff0) + 0x10;
    }
    storageSize = bufferRowBytes * overlayHeight;
    M<UInt16>(self + kIOATIR500Surface_scalingSourceWidth) = overlayWidth16;
    M<UInt16>(self + kIOATIR500Surface_scalingSourceHeight) = overlayHeight16;
    self[0xbec] = 0x1;
    M<UInt16>(self + kIOATIR500Surface_width) = overlayWidth16;
    M<UInt16>(self + kIOATIR500Surface_height) = overlayHeight16;
    bufferCount = 2;
  }
  reqBits = M<UInt32>(self + kIOATIR500Surface_contextReqBits);
  bufferListIndex = 0;
  do {
    bufferIdLocal = (UInt32)bufferIds[bufferListIndex];
    if ((reqBits >> (bufferIdLocal & 0x3f) & 1) != 0) {
      bufferRecord = bufferIdLocal * 0x78;
      if (((bytesPerPixel != M<UInt16>(self + bufferRecord + 0xbe)) ||
          ((UInt32)M<UInt16>(self + bufferRecord + 0xc4) != (SInt32)M<SInt16>(self + kIOATIR500Surface_width))) ||
         (((UInt32)M<UInt16>(self + bufferRecord + 0xc6) != (SInt32)M<SInt16>(self + kIOATIR500Surface_height) ||
          ((faceCount != M<UInt16>(self + bufferRecord + 200) ||
           (levelCount != M<UInt16>(self + bufferRecord + 0xca))))))) {
        if (M<SInt32>(self + bufferRecord + 0xcc) != 0) {
          ((IOATIR500Surface *)((UInt8 *)self))->free_buffer_backing_store((ATIR500SurfaceBuffer *)((UInt8 *)(self + bufferRecord + 0xa8)));
        }
        if (storageSize != M<SInt32>(self + bufferRecord + 0xb8)) {
          VCALL(M<SInt32>(self), 0x5cc)(self,bufferIdLocal);
          M<SInt32>(self + bufferRecord + 0xb8) = storageSize;
        }
        if (bytesPerPixel == 0) {
          M<UInt16>(self + bufferRecord + 0xbc) = 0;
        }
        else {
          storeHalf(&M<UInt16>(self + bufferRecord + 0xbc), (bufferRowBytes / bytesPerPixel));
        }
        mipIndex = 0;
        storeHalf(&M<UInt16>(self + bufferRecord + 0xbe), bytesPerPixel);
        storeHalf(&M<UInt16>(self + bufferRecord + 0xc0), bufferRowBytes);
        mipOffsetCursor = self + bufferRecord + 0xe8;
        M<UInt16>(self + bufferRecord + 0xc4) = M<UInt16>(self + kIOATIR500Surface_width);
        heightField = M<UInt16>(self + kIOATIR500Surface_height);
        storeHalf(&M<UInt16>(self + bufferRecord + 0xca), levelCount);
        storeHalf(&M<UInt16>(self + bufferRecord + 200), faceCount);
        M<UInt16>(self + bufferRecord + 0xc6) = heightField;
        mipSource = mipOffsets;
        do {
          mipIndex = mipIndex + 1;
          mipOffset = *mipSource;
          mipSource = mipSource + 1;
          M<SInt32>(mipOffsetCursor) = mipOffset;
          mipOffsetCursor = mipOffsetCursor + 4;
        } while (mipIndex <= mipCount + 1);
      }
      self[bufferRecord + 0xe2] = SUB41m(atiFormatIndex,0);
      self[bufferRecord + 0xe0] = tilingMode;
      self[bufferRecord + 0xe1] = fmtBitsA;
      self[bufferRecord + 0xe3] = fmtBitsB;
      reqBits = M<UInt32>(self + kIOATIR500Surface_contextReqBits);
    }
    bufferListIndex = bufferListIndex + 1;
  } while (bufferListIndex < bufferCount);
  if ((reqBits & 0x7ffc00) == 0) {
    return;
  }
  if (M<SInt32>(self + kIOATIR500Surface_boundDVDContext) == 0) {
    return;
  }
  overlayRight = M<SInt16>(self + kATIR500Surface_overlayRight);
  overlayLeft = M<SInt16>(self + kATIR500Surface_overlayLeft);
  bufferId = 10;
  overlayHeightPx = (SInt32)M<SInt16>(self + kATIR500Surface_overlayBottom) - (SInt32)M<SInt16>(self + kATIR500Surface_overlayTop);
  scaledHeight = overlayHeightPx * 3;
  scaledHeight16 = (UInt16)scaledHeight;
  halfScaledHeight16 = (UInt16)(scaledHeight >> 1);
  bufferRecordPtr = self;
  while( true ) {
    if ((1 << (bufferId & 0x3f) & reqBits) != 0) {
      if (M<SInt32>(bufferRecordPtr + 0x57c) != 0) {
        ((IOATIR500Surface *)((UInt8 *)self))->free_buffer_backing_store((ATIR500SurfaceBuffer *)((UInt8 *)(self + bufferId * 0x78 + 0xa8)));
      }
      storeHalf(&M<UInt16>(bufferRecordPtr + 0x574), overlayRight - overlayLeft);
      heightValue = halfScaledHeight16;
      if ((((M<SInt32>(self + kATIR500Surface_deintMode) != 0) && (9 < bufferId)) && (bufferId < 0xf)) &&
         ((heightValue = scaledHeight16, M<SInt32>(bufferRecordPtr + 0x560) != 0 &&
          ((UInt32)M<UInt16>(bufferRecordPtr + 0x576) != (scaledHeight & 0xffff))))) {
        ((IOATIR500Surface *)((UInt8 *)self))->copy_buffer_to_backing_store((ATIR500SurfaceBuffer *)((UInt8 *)(self + bufferId * 0x78 + 0xa8)));
      }
      M<UInt16>(bufferRecordPtr + 0x576) = heightValue;
      if (bufferId == 0x11) {
        self[0x8da] = 0x2e;
      }
      else if (bufferId == 0x10) {
        M<UInt16>(self + kIOATIR500Surface_buffer16Width) = 0x2d0;
        if ((overlayHeightPx == 0x240) || (overlayHeightPx == 0x120)) {
          M<UInt16>(self + kIOATIR500Surface_buffer16Height) = 0x240;
        }
        else {
          M<UInt16>(self + kIOATIR500Surface_buffer16Height) = 0x1e0;
        }
        self[0x862] = 0xb;
      }
      else if (bufferId == 0x12) {
        storeHalf(&M<UInt16>(self + kIOATIR500Surface_buffer18Height), overlayHeightPx);
        self[0x952] = 0xb;
      }
      else {
        bufferRecordPtr[0x592] = 0x2d;
      }
      bufferWidth16 = M<UInt16>(bufferRecordPtr + 0x574);
      alignedWidth = (UInt32)bufferWidth16;
      ovFormatOffset = (UInt32)(UInt8)bufferRecordPtr[0x592] * 0x1c;
      bufferRecordPtr[0x593] = ((UInt8)(FormatTableLookup_0x0004d2dc(ovFormatOffset) >> 3) & 0x1f);
      bytesPerPixelOv = 1 << (FormatTableLookup_0x0004d2dc(ovFormatOffset) >> 0xc & 7);
      bytesPerPixel16 = (UInt16)bytesPerPixelOv;
      M<UInt16>(bufferRecordPtr + 0x56e) = bytesPerPixel16;
      bufferRecordPtr[0x591] = ((UInt8)(FormatTableLookup_0x0004d2dc(ovFormatOffset) >> 10) & 3);
      if ((bufferWidth16 & 0xff) != 0) {
        alignedWidth = (bufferWidth16 & 0xffffff00) + 0x100;
      }
      bytesPerPixelOv = bytesPerPixelOv & 0xffff;
      storeHalf(&M<UInt16>(bufferRecordPtr + 0x570), (alignedWidth * bytesPerPixelOv));
      if (bytesPerPixelOv == 0) {
        M<UInt16>(bufferRecordPtr + 0x56c) = bytesPerPixel16;
      }
      else {
        storeHalf(&M<UInt16>(bufferRecordPtr + 0x56c), ((alignedWidth * bytesPerPixelOv & 0xffff) / bytesPerPixelOv));
      }
      if (bufferId == 0x12) {
        self[0x950] = tilingMode;
      }
      else {
        bufferRecordPtr[0x590] = 0x0;
      }
      pitch16 = M<UInt16>(bufferRecordPtr + 0x570);
      height16 = M<UInt16>(bufferRecordPtr + 0x576);
      if ((UInt32)pitch16 * (UInt32)height16 != M<SInt32>(bufferRecordPtr + 0x568)) {
        VCALL(M<SInt32>(self), 0x5cc)(self,bufferId);
        M<UInt32>(bufferRecordPtr + 0x568) = (UInt32)pitch16 * (UInt32)height16;
      }
    }
    isLast = bufferId == 0x16;
    bufferRecordPtr = bufferRecordPtr + 0x78;
    bufferId = bufferId + 1;
    if (isLast) break;
    reqBits = M<UInt32>(self + kIOATIR500Surface_contextReqBits);
  }
  if (M<SInt32>(self + kATIR500Surface_overlayExists) != 0) {
    if (self[0xbf0] != 0x0) goto LAB_0003ce90;
    overlayAllocated = this->alloc_overlay();
    self[0xbf0] = overlayAllocated;
  }
  if (self[0xbf0] == 0x0) {
    return;
  }
LAB_0003ce90:
  framebufferIndex = this->getFramebufferIndex();
  framebufferRecord = M<SInt32 *>(self + framebufferIndex * 8 + 0xd60);
  if (((*framebufferRecord != 0) && (M<SInt16>(framebufferRecord + 4) != 0)) && (M<SInt16>((SInt32)framebufferRecord + 0x12) != 0))
  {
    setup_overlay();
  }
  return;
}
