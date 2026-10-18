/*
 * ATIR500Surface_copy_to_buffer_Port.cpp
 *
 * ATIR500Surface::copy_to_buffer (real addr 0x43340, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

/* real addr 0x43340 */
void ATIR500Surface::copy_to_buffer(SInt32 x, SInt32 y, SInt32 w, SInt32 h, UInt32 index, UInt32 level, ATIR500SurfaceBuffer *buffer, UInt32 stamp, VendorTransferBuffer *transfer, UInt32 offset, UInt32 pitch, UInt32 flags) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);
    UInt8 *transferBytes = reinterpret_cast<UInt8 *>(transfer);

  UInt16 bufferPitchPixels;
  bool bVar2;
  UInt32 uVar3;
  unsigned int uVar4;
  unsigned int uVar5;
  int iVar6;
  int *transferMap;
  UInt32 *srcBlock;
  UInt32 *dstBlock;
  int *piVar10;
  int iVar11;
  UInt32 *surfaceRow;
  UInt8 *backing;
  UInt32 *transferRow;
  UInt8 bVar15;
  UInt8 bVar16;
  
  uVar3 = flags;
  backing = M<UInt8 *>(bufferBytes + 0x24);
  bVar2 = (flags & 1) == 0;
  bVar15 = bVar2 << 1;
  if (bVar2) {
    if ((backing == (UInt8 *)0x0) ||
       (M<int>(backing + 0x54) != M<int>(self + kIOATIR500Surface_stamp))) goto LAB_00043444;
LAB_00043494:
    transferMap = M<int *>(transferBytes + 8);
  }
  else {
    pitch = (UInt32)M<UInt16>(backing + 0x52);
    offset = (UInt32)M<UInt16>(backing + 0x50);
    uVar5 = VCALL(*M<int *>(backing + 8), 0x128)(M<int *>(backing + 8));
    uVar4 = 0;
    if (pitch != 0) {
      uVar4 = uVar5 / pitch;
    }
    if ((int)uVar4 < h) {
      h = uVar4;
    }
    transferBytes = backing;
    if ((M<unsigned int>(self + kIOATIR500Surface_modeBits) & 0x70000000) != 0) {
      iVar6 = VCALL(M<int>(self), 0x5f0)(self,bufferBytes,index,level,0,0,&pitch);
      offset = offset + iVar6;
    }
LAB_00043444:
    iVar6 = this->copy_buffer_using_DMA(x,y,w,h,index,level,(ATIR500SurfaceBuffer *)(bufferBytes),(VendorTransferBuffer *)(transferBytes),offset
                       ,pitch,(IODirection)2,uVar3);
    if (iVar6 != 0) {
      return;
    }
    if ((bool)(bVar15 >> 1 & 1)) goto LAB_00043494;
    transferMap = M<int *>(backing + 8);
  }
  transferMap = (int *)VCALL(*transferMap, 0x150)
                            (transferMap,M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0x82c) | 1);
  if (transferMap == (int *)0x0) {
    return;
  }
  iVar6 = VCALL(*transferMap, 0xd0)(transferMap);
  piVar10 = M<int *>(self + kIOATIR500Surface_accelerator);
  transferRow = (UInt32 *)(iVar6 + offset);
  iVar11 = piVar10[0x1ec];
  iVar6 = VCALL(*piVar10, 0x558)(piVar10,stamp);
  piVar10[0x1ec] = iVar11 + iVar6;
  if ((((bool)(bVar15 >> 1 & 1)) && (backing != (UInt8 *)0x0)) &&
     (M<int>(backing + 0x54) == M<int>(self + kIOATIR500Surface_stamp))) {
    piVar10 = (int *)VCALL(*M<int *>(backing + 8), 0x150)
                               (M<int *>(backing + 8),M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0x82c) | 1
                               );
    bVar15 = (piVar10 == (int *)0x0) << 1;
    if (piVar10 == (int *)0x0) goto LAB_000436cc;
    iVar6 = VCALL(*piVar10, 0xd0)(piVar10);
    bVar2 = false;
    iVar6 = iVar6 + (unsigned int)M<UInt16>(backing + 0x50);
  }
  else {
    piVar10 = (int *)0x0;
    bVar2 = true;
    bVar15 = 2;
    iVar6 = M<int>(bufferBytes + 8) + M<int>(self + kIOATIR500Surface_kernelMapAddress);
  }
  bufferPitchPixels = M<UInt16>(bufferBytes + 0x14);
  uVar4 = (unsigned int)M<UInt16>(bufferBytes + 0x16);
  surfaceRow = (UInt32 *)(iVar6 + uVar4 * ((unsigned int)bufferPitchPixels * y + x));
  if (uVar4 == 2) {
    w = w + 7 >> 3;
  }
  else if (uVar4 < 3) {
    if (uVar4 == 1) {
      w = w + 0xf >> 4;
    }
    else {
LAB_000435cc:
      w = w + 3 >> 2;
    }
  }
  else if (uVar4 == 8) {
    w = w + 1 >> 1;
  }
  else if (uVar4 != 0x10) goto LAB_000435cc;
  bVar16 = !bVar2 << 1;
  if (bVar2) {
    VCALL(M<int>(self), 0x5fc)(self,bufferBytes);
  }
  if (0 < h) {
    uVar5 = 0;
    do {
      srcBlock = transferRow;
      dstBlock = surfaceRow;
      iVar6 = w;
      if (0 < w) {
        do {
          *dstBlock = *srcBlock;
          dstBlock[1] = srcBlock[1];
          dstBlock[2] = srcBlock[2];
          dstBlock[3] = srcBlock[3];
          iVar6 = iVar6 + -1;
          srcBlock = srcBlock + 4;
          dstBlock = dstBlock + 4;
        } while (iVar6 != 0);
      }
      uVar5 = uVar5 + 1;
      surfaceRow = (UInt32 *)((int)surfaceRow + bufferPitchPixels * uVar4);
      transferRow = (UInt32 *)((int)transferRow + pitch);
    } while (uVar5 != h);
  }
  if (!(bool)(bVar16 >> 1 & 1)) {
    VCALL(M<int>(self), 0x600)(self,bufferBytes);
  }
LAB_000436cc:
  VCALL(*transferMap, 0x18)(transferMap);
  if (!(bool)(bVar15 >> 1 & 1)) {
    VCALL(*piVar10, 0x18)(piVar10);
  }
  return;
}
