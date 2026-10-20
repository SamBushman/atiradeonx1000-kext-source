/*
 * ATIR500Surface_get_surf_desc_regs_Port.cpp
 *
 * ATIR500Surface::get_surf_desc_regs (real addr 0x39f30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x39f30 */
void ATIR500Surface::get_surf_desc_regs(OverlaySurfaceInfo *info, UInt32*outRegs) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *infoBytes = reinterpret_cast<UInt8 *>(info);

  float heightScale;
  float widthScaled;
  float widthScaledAlt;
  float rowOffsetF;
  UInt32 gpuBase;
  unsigned int sizeD4;
  unsigned int srcWidth;
  unsigned int halfHeightBits;
  int rowPitch;
  unsigned int sizeD8;
  unsigned int heightBits;
  int planeBase;
  UInt32 infoField40;
  UInt8 *infoCursor;
  UInt8 *descWordSrc;
  unsigned int sizeDC;
  unsigned int planeIndex;
  int colOffset;
  int byteOffset;
  unsigned int srcHeight;
  int rowByteOffset;
  int planeSelectValue;
  int planesLeft;
  unsigned int altPlaneMask;
  int planeSelect[6];
  int highField[6];
  unsigned int baseAddr16[6];
  UInt32 doubleHi0;
  unsigned int doubleLo0;
  UInt32 doubleHi1;
  UInt32 doubleLo1;
  SInt64 fctiwTmp1;
  SInt64 fctiwTmp2;
  UInt32 doubleHi2;
  unsigned int doubleLo2;
  SInt64 fctiwTmp3;
  SInt64 fctiwTmp4;
  UInt32 doubleHi3;
  unsigned int doubleLo3;
  UInt32 doubleHi4;
  UInt32 doubleLo4;
  SInt64 fctiwTmp5;
  SInt64 fctiwTmp6;
  UInt32 doubleHi5;
  unsigned int doubleLo5;
  SInt64 fctiwTmp7;
  SInt64 fctiwTmp8;
  
  if (M<int>(infoBytes + 0x3c) - 9U < 2) {
    infoField40 = M<UInt32>(infoBytes + 0x40);
    planeSelectValue = M<int>(infoBytes + 0xe0);
    byteOffset = 0;
    planesLeft = 6;
    infoCursor = infoBytes;
    do {
      gpuBase = M<UInt32>(self + M<int>(self + kATIR500Surface_currentBufferIndex) * 0x78 + 0x560);
      M<UInt32>(infoCursor + 0x70) = infoField40;
      M<UInt32>(infoCursor + 0x88) = 0;
      M<UInt32>(infoCursor + 0x58) = gpuBase;
      M<int>((int)planeSelect + byteOffset) = planeSelectValue;
      infoCursor = infoCursor + 4;
      M<UInt32>((int)highField + byteOffset) = 0;
      byteOffset = byteOffset + 4;
      planesLeft = planesLeft + -1;
    } while (planesLeft != 0);
    if (planeSelectValue == 0) {
      sizeD4 = M<unsigned int>(infoBytes + 0xd4);
      sizeD8 = M<unsigned int>(infoBytes + 0xd8);
      sizeDC = M<unsigned int>(infoBytes + 0xdc);
      baseAddr16[0] = ((int)sizeD4 >> 4) + (unsigned int)((int)sizeD4 < 0 && (sizeD4 & 0xf) != 0);
      baseAddr16[1] = ((int)sizeD8 >> 4) + (unsigned int)((int)sizeD8 < 0 && (sizeD8 & 0xf) != 0);
      baseAddr16[2] = ((int)sizeDC >> 4) + (unsigned int)((int)sizeDC < 0 && (sizeDC & 0xf) != 0);
      baseAddr16[3] = baseAddr16[0];
      baseAddr16[4] = baseAddr16[1];
      baseAddr16[5] = baseAddr16[2];
    }
    else {
      sizeD4 = M<unsigned int>(infoBytes + 0xd4);
      sizeD8 = M<unsigned int>(infoBytes + 0xd8);
      sizeDC = M<unsigned int>(infoBytes + 0xdc);
      baseAddr16[0] = ((int)sizeD4 >> 4) + (unsigned int)((int)sizeD4 < 0 && (sizeD4 & 0xf) != 0);
      baseAddr16[1] = ((int)sizeD8 >> 4) + (unsigned int)((int)sizeD8 < 0 && (sizeD8 & 0xf) != 0);
      baseAddr16[2] = ((int)sizeDC >> 4) + (unsigned int)((int)sizeDC < 0 && (sizeDC & 0xf) != 0);
    }
    M<UInt32>(infoBytes + 0x90) = 1;
    M<UInt32>(infoBytes + 0x98) = 1;
    M<UInt32>(infoBytes + 0x8c) = 1;
    M<UInt32>(infoBytes + 0x9c) = 1;
  }
  else {
    srcWidth = M<unsigned int>(infoBytes + 0x10);
    srcHeight = M<unsigned int>(infoBytes + 0x14);
    planeIndex = 0;
    doubleHi5 = 0x43300000;
    doubleHi3 = 0x43300000;
    byteOffset = 0;
    doubleHi2 = 0x43300000;
    doubleHi0 = 0x43300000;
    heightScale = M<float>(infoBytes + 0x30);
    planeSelectValue = M<int>(infoBytes + 0xe0);
    infoField40 = M<UInt32>(infoBytes + 0x40);
    altPlaneMask = M<unsigned int>(infoBytes + 0x54);
    doubleLo5 = (int)srcWidth >> 0x1f & -srcWidth ^ 0x80000000;
    heightBits = (int)srcHeight >> 0x1f & -srcHeight ^ 0x80000000;
    doubleLo3 = heightBits;
    planesLeft = 6;
    doubleLo2 = (int)(srcWidth / M<unsigned int>(infoBytes + 0x50)) >> 0x1f &
                -(srcWidth / M<unsigned int>(infoBytes + 0x50)) ^ 0x80000000;
    widthScaled = (float)((double)CONCAT44d(0x43300000,doubleLo5) - 4503601774854144.0) *
            M<float>(infoBytes + 0x34);
    halfHeightBits = (int)(srcHeight / M<unsigned int>(infoBytes + 0x4c)) >> 0x1f &
            -(srcHeight / M<unsigned int>(infoBytes + 0x4c)) ^ 0x80000000;
    doubleLo0 = halfHeightBits;
    widthScaledAlt = (float)((double)CONCAT44d(0x43300000,doubleLo2) - 4503601774854144.0) *
            M<float>(infoBytes + 0x34);
    infoCursor = infoBytes;
    do {
      M<int>((int)planeSelect + byteOffset) = planeSelectValue;
      gpuBase = M<UInt32>(self + kIOATIR500Surface_buffer1GpuBase);
      M<UInt32>(infoCursor + 0x70) = infoField40;
      M<UInt32>(infoCursor + 0x88) = 0;
      M<UInt32>(infoCursor + 0xa0) = 0;
      M<UInt32>(infoCursor + 0xb8) = 0;
      M<UInt32>(infoCursor + 0x58) = gpuBase;
      if ((altPlaneMask >> (planeIndex & 0x3f) & 1) == 0) {
        doubleHi4 = 0x43300000;
        doubleLo4 = M<UInt32>(infoBytes + 0x44);
        rowOffsetF = (float)((double)CONCAT44d(0x43300000,heightBits) - 4503601774854144.0) * heightScale *
                (float)((double)CONCAT44d(0x43300000,M<UInt32>(infoBytes + 0x44)) -
                       4503599627370496.0);
        if (2147483648.0 <= rowOffsetF) {
          fctiwTmp6 = (SInt64)(int)(rowOffsetF - 2147483648.0);
          rowByteOffset = (int)(rowOffsetF - 2147483648.0) + -0x80000000;
        }
        else {
          rowByteOffset = (int)rowOffsetF;
          fctiwTmp5 = (SInt64)rowByteOffset;
        }
        rowByteOffset = rowByteOffset + M<int>(infoCursor + 0xa0);
        if (2147483648.0 <= widthScaled) {
          fctiwTmp8 = (SInt64)(int)(widthScaled - 2147483648.0);
          colOffset = (int)(widthScaled - 2147483648.0) + -0x80000000;
        }
        else {
          colOffset = (int)widthScaled;
          fctiwTmp7 = (SInt64)colOffset;
        }
      }
      else {
        doubleHi1 = 0x43300000;
        doubleLo1 = M<UInt32>(infoBytes + 0x48);
        rowOffsetF = (float)((double)CONCAT44d(0x43300000,halfHeightBits) - 4503601774854144.0) * heightScale *
                (float)((double)CONCAT44d(0x43300000,M<UInt32>(infoBytes + 0x48)) -
                       4503599627370496.0);
        if (2147483648.0 <= rowOffsetF) {
          fctiwTmp2 = (SInt64)(int)(rowOffsetF - 2147483648.0);
          rowByteOffset = (int)(rowOffsetF - 2147483648.0) + -0x80000000;
        }
        else {
          rowByteOffset = (int)rowOffsetF;
          fctiwTmp1 = (SInt64)rowByteOffset;
        }
        rowByteOffset = rowByteOffset + M<int>(infoCursor + 0xa0);
        if (2147483648.0 <= widthScaledAlt) {
          fctiwTmp4 = (SInt64)(int)(widthScaledAlt - 2147483648.0);
          colOffset = (int)(widthScaledAlt - 2147483648.0) + -0x80000000;
        }
        else {
          colOffset = (int)widthScaledAlt;
          fctiwTmp3 = (SInt64)colOffset;
        }
      }
      if (planeSelectValue == 0) {
        rowPitch = M<int>(infoCursor + 0x70);
        planeBase = M<int>(infoCursor + 0x58);
        M<UInt32>((int)highField + byteOffset) = 0;
        planeBase = colOffset * rowPitch + planeBase;
      }
      else {
        rowPitch = M<int>(infoCursor + 0x70);
        planeBase = M<int>(infoCursor + 0x58);
        M<UInt32>((int)highField + byteOffset) = 0;
        planeBase = colOffset * rowPitch + planeBase;
      }
      planeIndex = planeIndex + 1;
      infoCursor = infoCursor + 4;
      M<unsigned int>((int)baseAddr16 + byteOffset) = (unsigned int)(rowByteOffset + planeBase) >> 4;
      byteOffset = byteOffset + 4;
      planesLeft = planesLeft + -1;
    } while (planesLeft != 0);
  }
  byteOffset = 0;
  planesLeft = 6;
  do {
    descWordSrc = infoBytes + 0x88;
    infoBytes = infoBytes + 4;
    M<unsigned int>((int)outRegs + byteOffset) =
         M<int>((int)planeSelect + byteOffset) << 1 | M<unsigned int>(descWordSrc) |
         M<int>((int)baseAddr16 + byteOffset) << 4 | M<int>((int)highField + byteOffset) << 0x1b;
    byteOffset = byteOffset + 4;
    planesLeft = planesLeft + -1;
  } while (planesLeft != 0);
  return;
}
