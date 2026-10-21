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
  bool flagsClear;
  bool kernelMapped;
  UInt32 dmaFlags;
  unsigned int rowsFit;
  unsigned int bytesPerPixel;
  unsigned int backingBytes;
  unsigned int row;
  int levelOffset;
  int dmaResult;
  int mapAddress;
  int counterDelta;
  int surfaceBase;
  int blocksLeft;
  int *transferMap;
  UInt32 *srcBlock;
  UInt32 *dstBlock;
  int *accelPtr;
  int *backingMap;
  int counterBefore;
  UInt32 *surfaceRow;
  UInt8 *backing;
  UInt32 *transferRow;
  UInt8 noBackingMap;
  UInt8 kernelPathBits;
  
  dmaFlags = flags;
  backing = M<UInt8 *>(bufferBytes + 0x24);
  flagsClear = (flags & 1) == 0;
  noBackingMap = flagsClear << 1;
  if (flagsClear) {
    if ((backing == (UInt8 *)0x0) ||
       (M<int>(backing + 0x54) != M<int>(self + kIOATIR500Surface_stamp))) goto copyViaDMA;
mapTransferBuffer:
    transferMap = M<int *>(transferBytes + 8);
  }
  else {
    pitch = (UInt32)M<UInt16>(backing + 0x52);
    offset = (UInt32)M<UInt16>(backing + 0x50);
    backingBytes = VCALL(*M<int *>(backing + 8), 0x128)(M<int *>(backing + 8));
    rowsFit = 0;
    if (pitch != 0) {
      rowsFit = backingBytes / pitch;
    }
    if ((int)rowsFit < h) {
      h = rowsFit;
    }
    transferBytes = backing;
    if ((M<unsigned int>(self + kIOATIR500Surface_modeBits) & 0x70000000) != 0) {
      levelOffset = VCALL(M<int>(self), 0x5f0)(self,bufferBytes,index,level,0,0,&pitch);
      offset = offset + levelOffset;
    }
copyViaDMA:
    dmaResult = this->copy_buffer_using_DMA(x,y,w,h,index,level,(ATIR500SurfaceBuffer *)(bufferBytes),(VendorTransferBuffer *)(transferBytes),offset
                       ,pitch,(IODirection)2,dmaFlags);
    if (dmaResult != 0) {
      return;
    }
    if ((bool)(noBackingMap >> 1 & 1)) goto mapTransferBuffer;
    transferMap = M<int *>(backing + 8);
  }
  transferMap = (int *)VCALL(*transferMap, 0x150)
                            (transferMap,M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0x82c) | 1);
  if (transferMap == (int *)0x0) {
    return;
  }
  mapAddress = VCALL(*transferMap, 0xd0)(transferMap);
  accelPtr = M<int *>(self + kIOATIR500Surface_accelerator);
  transferRow = (UInt32 *)(mapAddress + offset);
  counterBefore = accelPtr[0x1ec];
  counterDelta = VCALL(*accelPtr, 0x558)(accelPtr,stamp);
  accelPtr[0x1ec] = counterBefore + counterDelta;
  if ((((bool)(noBackingMap >> 1 & 1)) && (backing != (UInt8 *)0x0)) &&
     (M<int>(backing + 0x54) == M<int>(self + kIOATIR500Surface_stamp))) {
    backingMap = (int *)VCALL(*M<int *>(backing + 8), 0x150)
                               (M<int *>(backing + 8),M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0x82c) | 1
                               );
    noBackingMap = (backingMap == (int *)0x0) << 1;
    if (backingMap == (int *)0x0) goto unmapAndRelease;
    surfaceBase = VCALL(*backingMap, 0xd0)(backingMap);
    kernelMapped = false;
    surfaceBase = surfaceBase + (unsigned int)M<UInt16>(backing + 0x50);
  }
  else {
    backingMap = (int *)0x0;
    kernelMapped = true;
    noBackingMap = 2;
    surfaceBase = M<int>(bufferBytes + 8) + M<int>(self + kIOATIR500Surface_kernelMapAddress);
  }
  bufferPitchPixels = M<UInt16>(bufferBytes + 0x14);
  bytesPerPixel = (unsigned int)M<UInt16>(bufferBytes + 0x16);
  surfaceRow = (UInt32 *)(surfaceBase + bytesPerPixel * ((unsigned int)bufferPitchPixels * y + x));
  if (bytesPerPixel == 2) {
    w = w + 7 >> 3;
  }
  else if (bytesPerPixel < 3) {
    if (bytesPerPixel == 1) {
      w = w + 0xf >> 4;
    }
    else {
blockWidth4:
      w = w + 3 >> 2;
    }
  }
  else if (bytesPerPixel == 8) {
    w = w + 1 >> 1;
  }
  else if (bytesPerPixel != 0x10) goto blockWidth4;
  kernelPathBits = !kernelMapped << 1;
  if (kernelMapped) {
    VCALL(M<int>(self), 0x5fc)(self,bufferBytes);
  }
  if (0 < h) {
    row = 0;
    do {
      srcBlock = transferRow;
      dstBlock = surfaceRow;
      blocksLeft = w;
      if (0 < w) {
        do {
          *dstBlock = *srcBlock;
          dstBlock[1] = srcBlock[1];
          dstBlock[2] = srcBlock[2];
          dstBlock[3] = srcBlock[3];
          blocksLeft = blocksLeft + -1;
          srcBlock = srcBlock + 4;
          dstBlock = dstBlock + 4;
        } while (blocksLeft != 0);
      }
      row = row + 1;
      surfaceRow = (UInt32 *)((int)surfaceRow + bufferPitchPixels * bytesPerPixel);
      transferRow = (UInt32 *)((int)transferRow + pitch);
    } while (row != h);
  }
  if (!(bool)(kernelPathBits >> 1 & 1)) {
    VCALL(M<int>(self), 0x600)(self,bufferBytes);
  }
unmapAndRelease:
  VCALL(*transferMap, 0x18)(transferMap);
  if (!(bool)(noBackingMap >> 1 & 1)) {
    VCALL(*backingMap, 0x18)(backingMap);
  }
  return;
}
