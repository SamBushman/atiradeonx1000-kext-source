/*
 * ATIR500Surface_copy_from_buffer_Port.cpp
 *
 * ATIR500Surface::copy_from_buffer (real addr 0x43730, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


int get_offset_of_sample_0(ATIR500SurfaceBuffer *buffer, int x, int y);   /* Sources/ATIR500Surface_CopyBuffers.cpp */

/* real addr 0x43730 */
void ATIR500Surface::copy_from_buffer(SInt32 x, SInt32 y, SInt32 w, SInt32 h, UInt32 index, UInt32 level, ATIR500SurfaceBuffer *buffer, UInt32 stamp, VendorTransferBuffer *transfer, UInt32 offset, UInt32 pitch, UInt32 flags) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);
    UInt8 *transferBytes = reinterpret_cast<UInt8 *>(transfer);

  bool synchronous;
  UInt8 uVar2;
  UInt16 bytesPerRow;
  bool bVar4;
  UInt32 uVar5;
  unsigned int uVar6;
  UInt32 uVar7;
  int iVar8;
  UInt64 *puVar9;
  UInt64 *puVar10;
  unsigned int uVar11;
  int iVar12;
  int xScaled;
  int waited;
  int transferAddress;
  int dmaResult;
  int offsetAdjust;
  int *transferMap;
  int iVar14;
  int iVar15;
  UInt8 *puVar16;
  unsigned int tilingBits;
  UInt64 *puVar18;
  unsigned int uVar19;
  UInt64 *puVar20;
  int iVar21;
  UInt64 *puVar22;
  UInt64 *transferRow;
  int *piVar24;
  int *backingMap;
  int *accel;
  int iVar25;
  int surfaceY;
  int waitTotal;
  UInt64 *surfaceRow;
  UInt8 *backing;
  unsigned int uVar28;
  UInt8 bVar29;
  UInt8 bVar30;
  UInt8 bVar31;
  
  uVar5 = flags;
  backing = M<UInt8 *>(bufferBytes + 0x24);
  synchronous = (flags & 1) == 0;
  if (synchronous) {
    if ((backing == (UInt8 *)0x0) ||
       (M<int>(backing + 0x54) != M<int>(self + 0x7c))) goto LAB_00043834;
LAB_00043888:
    transferMap = M<int *>(transferBytes + 8);
  }
  else {
    pitch = (UInt32)M<UInt16>(backing + 0x52);
    offset = (UInt32)M<UInt16>(backing + 0x50);
    uVar11 = VCALL(*M<int *>(backing + 8), 0x128)(M<int *>(backing + 8));
    uVar6 = 0;
    if (pitch != 0) {
      uVar6 = uVar11 / pitch;
    }
    if ((int)uVar6 < h) {
      h = uVar6;
    }
    transferBytes = backing;
    if ((M<unsigned int>(self + 0xbe8) & 0x70000000) != 0) {
      offsetAdjust = VCALL(M<int>(self), 0x5f0)(self,bufferBytes,index,level,0,0,&pitch);
      offset = offset + offsetAdjust;
    }
LAB_00043834:
    dmaResult = this->copy_buffer_using_DMA(x,y,w,h,index,level,(ATIR500SurfaceBuffer *)(bufferBytes),(VendorTransferBuffer *)(transferBytes),
                        offset,pitch,(IODirection)1,uVar5);
    if (dmaResult != 0) {
      return;
    }
    if (synchronous) goto LAB_00043888;
    transferMap = M<int *>(backing + 8);
  }
  transferMap = (int *)VCALL(*transferMap, 0x150)
                             (transferMap,M<unsigned int>(M<int>(self + 0xd50) + 0x82c) | 1);
  if (transferMap == (int *)0x0) {
    return;
  }
  transferAddress = VCALL(*transferMap, 0xd0)(transferMap);
  accel = M<int *>(self + 0xd50);
  transferRow = (UInt64 *)(transferAddress + offset);
  waitTotal = accel[0x1ed];
  waited = VCALL(*accel, 0x558)(accel,stamp);
  accel[0x1ed] = waitTotal + waited;
  if (((synchronous) && (uVar6 = M<unsigned int>(bufferBytes + 0x3c), (uVar6 & 0x800) != 0)) &&
     ((M<unsigned int>(self + 0xbe8) & 0xc0000) != 0)) {
    uVar11 = uVar6 >> 0xc & 0xf;
    uVar6 = uVar6 >> 0x10 & 0xf;
  }
  else {
    uVar6 = 1;
    uVar11 = 1;
  }
  xScaled = uVar6 * x;
  surfaceY = uVar11 * y;
  if (((synchronous) && (backing != (UInt8 *)0x0)) &&
     (M<int>(backing + 0x54) == M<int>(self + 0x7c))) {
    backingMap = (int *)VCALL(*M<int *>(backing + 8), 0x150)
                               (M<int *>(backing + 8),M<unsigned int>(M<int>(self + 0xd50) + 0x82c) | 1
                               );
    bVar29 = (backingMap == (int *)0x0) << 1;
    if (backingMap == (int *)0x0) goto LAB_00043db4;
    iVar14 = VCALL(*backingMap, 0xd0)(backingMap);
    tilingBits = M<unsigned int>(bufferBytes + 0x3c);
    bVar4 = false;
    uVar28 = (unsigned int)M<UInt16>(backing + 0x52);
    bytesPerRow = M<UInt16>(bufferBytes + 0x16);
    iVar14 = iVar14 + (unsigned int)M<UInt16>(backing + 0x50);
  }
  else {
    tilingBits = M<unsigned int>(bufferBytes + 0x3c);
    uVar19 = 0;
    iVar14 = M<int>(bufferBytes + 8) + M<int>(self + 0xc10);
    if ((tilingBits & 0xf00000) != 0) {
      uVar19 = (int)((unsigned int)M<UInt16>(bufferBytes + 0x14) / (tilingBits >> 0x14 & 0xf)) >> (level & 0x3f)
      ;
    }
    bytesPerRow = M<UInt16>(bufferBytes + 0x16);
    uVar28 = 0x20 / bytesPerRow;
    if (uVar28 <= uVar19) {
      uVar28 = uVar19;
    }
    backingMap = (int *)0x0;
    uVar28 = uVar28 * bytesPerRow;
    bVar4 = true;
    bVar29 = 2;
  }
  iVar21 = (int)(unsigned int)M<UInt16>(bufferBytes + 0x1e) >> (level & 0x3f);
  surfaceRow = (UInt64 *)
            (iVar14 + M<int>(bufferBytes + level * 4 + 0x40) * (unsigned int)M<UInt16>(bufferBytes + 0x20) +
                      index * (M<int>(bufferBytes + level * 4 + 0x44) -
                                M<int>(bufferBytes + level * 4 + 0x40)));
  iVar14 = 1;
  if (iVar21 != 0) {
    iVar14 = iVar21;
  }
  if ((synchronous) && ((M<unsigned int>(self + 0xbe8) & 0x70000000) == 0)) {
    if ((int)M<SInt16>(self + 0xbd6) != (int)M<SInt16>(self + 0xbda)) {
      iVar14 = (int)M<SInt16>(self + 0xbda);
    }
    surfaceY = (iVar14 - surfaceY) - uVar11;
  }
  if (((tilingBits & 0xf00000) == 0x100000) || (!synchronous)) {
    iVar14 = surfaceY * uVar28;
    uVar28 = -uVar28;
    surfaceRow = (UInt64 *)((int)surfaceRow + iVar14 + xScaled * (unsigned int)bytesPerRow);
    if (synchronous) goto LAB_00043ac4;
LAB_00043ad0:
    uVar28 = -uVar28;
  }
  else {
LAB_00043ac4:
    if ((M<unsigned int>(self + 0xbe8) & 0x70000000) != 0) goto LAB_00043ad0;
  }
  bVar30 = !bVar4 << 1;
  iVar14 = uVar6 * (unsigned int)bytesPerRow * w;
  if (bVar4) {
    VCALL(M<int>(self), 0x5fc)(self,bufferBytes);
    tilingBits = M<unsigned int>(bufferBytes + 0x3c);
  }
  if (synchronous) {
    if ((tilingBits >> 0x14 & 0xf) < 2) goto LAB_00043b24;
    iVar14 = surfaceY - h;
    if (iVar14 < surfaceY) {
      bVar31 = (xScaled < xScaled + w) << 3;
      do {
        iVar21 = xScaled;
        puVar10 = transferRow;
        if ((bool)(bVar31 >> 3 & 1)) {
          do {
            iVar15 = get_offset_of_sample_0((ATIR500SurfaceBuffer *)bufferBytes,iVar21,surfaceY);
            puVar16 = (UInt8 *)(iVar15 + (int)surfaceRow);
            if (puVar10 < (UInt64 *)((int)puVar10 + (unsigned int)M<UInt16>(bufferBytes + 0x16))) {
              iVar15 = (int)((int)puVar10 + (unsigned int)M<UInt16>(bufferBytes + 0x16)) - (int)puVar10;
              iVar8 = 0;
              do {
                uVar2 = *puVar16;
                puVar16 = puVar16 + 1;
                M<UInt8>((int)puVar10 + iVar8) = uVar2;
                iVar8 = iVar8 + 1;
                iVar15 = iVar15 + -1;
              } while (iVar15 != 0);
              puVar10 = (UInt64 *)((int)puVar10 + iVar8);
            }
            iVar21 = iVar21 + 1;
          } while (iVar21 < xScaled + w);
        }
        surfaceY = surfaceY + -1;
        transferRow = (UInt64 *)((int)transferRow + pitch);
      } while (iVar14 < surfaceY);
    }
  }
  else {
    if (1 < (tilingBits >> 0x14 & 0xf)) {
      M<UInt8>(M<int>(bufferBytes + 0x24) + 0x58) = 0;
    }
LAB_00043b24:
    if (uVar6 == 1) {
      if (0 < h) {
        uVar6 = 0;
        do {
          puVar18 = (UInt64 *)((int)transferRow + iVar14);
          puVar10 = surfaceRow;
          puVar20 = transferRow;
          if ((transferRow < puVar18) && (((unsigned int)transferRow & 7) != 0)) {
            puVar9 = (UInt64 *)((int)surfaceRow + ((int)puVar18 - (int)transferRow));
            iVar12 = (int)puVar9 - (int)surfaceRow;
            puVar22 = surfaceRow;
            do {
              uVar2 = M<UInt8>(puVar22);
              puVar22 = (UInt64 *)((int)puVar22 + 1);
              M<UInt8>(puVar20) = uVar2;
              puVar20 = (UInt64 *)((int)puVar20 + 1);
              iVar12 = iVar12 + -1;
              puVar10 = puVar9;
              if (iVar12 == 0) break;
              puVar10 = puVar22;
            } while (((unsigned int)puVar20 & 7) != 0);
          }
          while (puVar20 + 4 <= puVar18) {
            *puVar20 = *puVar10;
            puVar20[1] = puVar10[1];
            puVar20[2] = puVar10[2];
            puVar20[3] = puVar10[3];
            puVar10 = puVar10 + 4;
            puVar20 = puVar20 + 4;
          }
          while ((UInt64 *)((int)puVar20 + 4) <= puVar18) {
            uVar7 = M<UInt32>(puVar10);
            puVar10 = (UInt64 *)((int)puVar10 + 4);
            M<UInt32>(puVar20) = uVar7;
            puVar20 = (UInt64 *)((int)puVar20 + 4);
          }
          if (puVar20 < puVar18) {
            iVar12 = (int)puVar18 - (int)puVar20;
            iVar25 = 0;
            do {
              uVar2 = M<UInt8>(puVar10);
              puVar10 = (UInt64 *)((int)puVar10 + 1);
              M<UInt8>(iVar25 + (int)puVar20) = uVar2;
              iVar25 = iVar25 + 1;
              iVar12 = iVar12 + -1;
            } while (iVar12 != 0);
          }
          uVar6 = uVar6 + 1;
          surfaceRow = (UInt64 *)((int)surfaceRow + uVar11 * uVar28);
          transferRow = (UInt64 *)((int)transferRow + pitch);
        } while (h != uVar6);
      }
    }
    else if (0 < h) {
      uVar6 = 0;
      do {
        puVar10 = (UInt64 *)((int)surfaceRow + iVar14);
        if (surfaceRow < puVar10) {
          tilingBits = (unsigned int)M<UInt16>(bufferBytes + 0x16);
          puVar20 = surfaceRow;
          puVar18 = transferRow;
          do {
            if (puVar18 < (UInt64 *)((int)puVar18 + tilingBits)) {
              iVar12 = (int)((int)puVar18 + tilingBits) - (int)puVar18;
              iVar25 = 0;
              do {
                uVar2 = M<UInt8>(puVar20);
                puVar20 = (UInt64 *)((int)puVar20 + 1);
                M<UInt8>(iVar25 + (int)puVar18) = uVar2;
                iVar25 = iVar25 + 1;
                iVar12 = iVar12 + -1;
              } while (iVar12 != 0);
              tilingBits = (unsigned int)M<UInt16>(bufferBytes + 0x16);
              puVar18 = (UInt64 *)((int)puVar18 + iVar25);
            }
            puVar20 = (UInt64 *)((int)puVar20 + tilingBits);
          } while (puVar20 < puVar10);
        }
        uVar6 = uVar6 + 1;
        surfaceRow = (UInt64 *)((int)surfaceRow + uVar11 * uVar28);
        transferRow = (UInt64 *)((int)transferRow + pitch);
      } while (h != uVar6);
    }
  }
  if (!(bool)(bVar30 >> 1 & 1)) {
    VCALL(M<int>(self), 0x600)(self,bufferBytes);
  }
LAB_00043db4:
  VCALL(*transferMap, 0x18)(transferMap);
  if (!(bool)(bVar29 >> 1 & 1)) {
    VCALL(*backingMap, 0x18)(backingMap);
  }
  return;
}
