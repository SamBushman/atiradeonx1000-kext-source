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
  UInt8 byteValue;
  UInt16 bytesPerPixel;
  bool kernelMapped;
  UInt32 dmaFlags;
  unsigned int rowsFit;
  unsigned int sampleScaleX;
  unsigned int row;
  UInt32 word;
  int copied;
  UInt64 *srcRowEnd;
  UInt64 *texelDst;
  UInt64 *srcCursor;
  UInt64 *surfaceRowEnd;
  unsigned int backingBytes;
  unsigned int sampleScaleY;
  int bytesLeft;
  int xScaled;
  int waited;
  int transferAddress;
  int dmaResult;
  int offsetAdjust;
  int *transferMap;
  int mappedBase;
  int heightRows;
  int rowOffset;
  int rowBytes;
  int endY;
  int sampleOffset;
  int texelBytesLeft;
  UInt8 *texelSrc;
  unsigned int tilingBits;
  UInt64 *rowEnd;
  UInt64 *dstCursor;
  unsigned int levelPitchPixels;
  int levelHeight;
  int sampleX;
  UInt64 *srcByteCursor;
  UInt64 *transferRow;
  int *backingMap;
  int *accel;
  int byteIndex;
  int surfaceY;
  int waitTotal;
  UInt64 *surfaceRow;
  UInt8 *backing;
  unsigned int rowPitch;
  UInt8 noBackingMap;
  UInt8 kernelPathBits;
  UInt8 hasColumns;
  
  dmaFlags = flags;
  backing = M<UInt8 *>(bufferBytes + 0x24);
  synchronous = (flags & 1) == 0;
  if (synchronous) {
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
      offsetAdjust = VCALL(M<int>(self), 0x5f0)(self,bufferBytes,index,level,0,0,&pitch);
      offset = offset + offsetAdjust;
    }
copyViaDMA:
    dmaResult = this->copy_buffer_using_DMA(x,y,w,h,index,level,(ATIR500SurfaceBuffer *)(bufferBytes),(VendorTransferBuffer *)(transferBytes),
                        offset,pitch,(IODirection)1,dmaFlags);
    if (dmaResult != 0) {
      return;
    }
    if (synchronous) goto mapTransferBuffer;
    transferMap = M<int *>(backing + 8);
  }
  transferMap = (int *)VCALL(*transferMap, 0x150)
                             (transferMap,M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0x82c) | 1);
  if (transferMap == (int *)0x0) {
    return;
  }
  transferAddress = VCALL(*transferMap, 0xd0)(transferMap);
  accel = M<int *>(self + kIOATIR500Surface_accelerator);
  transferRow = (UInt64 *)(transferAddress + offset);
  waitTotal = accel[0x1ed];
  waited = VCALL(*accel, 0x558)(accel,stamp);
  accel[0x1ed] = waitTotal + waited;
  if (((synchronous) && (sampleScaleX = M<unsigned int>(bufferBytes + 0x3c), (sampleScaleX & 0x800) != 0)) &&
     ((M<unsigned int>(self + kIOATIR500Surface_modeBits) & 0xc0000) != 0)) {
    sampleScaleY = sampleScaleX >> 0xc & 0xf;
    sampleScaleX = sampleScaleX >> 0x10 & 0xf;
  }
  else {
    sampleScaleX = 1;
    sampleScaleY = 1;
  }
  xScaled = sampleScaleX * x;
  surfaceY = sampleScaleY * y;
  if (((synchronous) && (backing != (UInt8 *)0x0)) &&
     (M<int>(backing + 0x54) == M<int>(self + kIOATIR500Surface_stamp))) {
    backingMap = (int *)VCALL(*M<int *>(backing + 8), 0x150)
                               (M<int *>(backing + 8),M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0x82c) | 1
                               );
    noBackingMap = (backingMap == (int *)0x0) << 1;
    if (backingMap == (int *)0x0) goto unmapAndRelease;
    mappedBase = VCALL(*backingMap, 0xd0)(backingMap);
    tilingBits = M<unsigned int>(bufferBytes + 0x3c);
    kernelMapped = false;
    rowPitch = (unsigned int)M<UInt16>(backing + 0x52);
    bytesPerPixel = M<UInt16>(bufferBytes + 0x16);
    mappedBase = mappedBase + (unsigned int)M<UInt16>(backing + 0x50);
  }
  else {
    tilingBits = M<unsigned int>(bufferBytes + 0x3c);
    levelPitchPixels = 0;
    mappedBase = M<int>(bufferBytes + 8) + M<int>(self + kIOATIR500Surface_kernelMapAddress);
    if ((tilingBits & 0xf00000) != 0) {
      levelPitchPixels = (int)((SInt32)M<UInt16>(bufferBytes + 0x14) / (SInt32)(tilingBits >> 0x14 & 0xf)) >> (level & 0x3f)
      ;
    }
    bytesPerPixel = M<UInt16>(bufferBytes + 0x16);
    rowPitch = 0x20 / bytesPerPixel;
    if (rowPitch <= levelPitchPixels) {
      rowPitch = levelPitchPixels;
    }
    backingMap = (int *)0x0;
    rowPitch = rowPitch * bytesPerPixel;
    kernelMapped = true;
    noBackingMap = 2;
  }
  levelHeight = (int)(unsigned int)M<UInt16>(bufferBytes + 0x1e) >> (level & 0x3f);
  surfaceRow = (UInt64 *)
            (mappedBase + M<int>(bufferBytes + level * 4 + 0x40) * (unsigned int)M<UInt16>(bufferBytes + 0x20) +
                      index * (M<int>(bufferBytes + level * 4 + 0x44) -
                                M<int>(bufferBytes + level * 4 + 0x40)));
  heightRows = 1;
  if (levelHeight != 0) {
    heightRows = levelHeight;
  }
  if ((synchronous) && ((M<unsigned int>(self + kIOATIR500Surface_modeBits) & 0x70000000) == 0)) {
    if ((int)M<SInt16>(self + kIOATIR500Surface_height) != (int)M<SInt16>(self + kIOATIR500Surface_committedHeight)) {
      heightRows = (int)M<SInt16>(self + kIOATIR500Surface_committedHeight);
    }
    surfaceY = (heightRows - surfaceY) - sampleScaleY;
  }
  if (((tilingBits & 0xf00000) == 0x100000) || (!synchronous)) {
    rowOffset = surfaceY * rowPitch;
    rowPitch = -rowPitch;
    surfaceRow = (UInt64 *)((int)surfaceRow + rowOffset + xScaled * (unsigned int)bytesPerPixel);
    if (synchronous) goto checkRowFlip;
flipRowPitch:
    rowPitch = -rowPitch;
  }
  else {
checkRowFlip:
    if ((M<unsigned int>(self + kIOATIR500Surface_modeBits) & 0x70000000) != 0) goto flipRowPitch;
  }
  kernelPathBits = !kernelMapped << 1;
  rowBytes = sampleScaleX * (unsigned int)bytesPerPixel * w;
  if (kernelMapped) {
    VCALL(M<int>(self), 0x5fc)(self,bufferBytes);
    tilingBits = M<unsigned int>(bufferBytes + 0x3c);
  }
  if (synchronous) {
    if ((tilingBits >> 0x14 & 0xf) < 2) goto copyRows;
    endY = surfaceY - h;
    if (endY < surfaceY) {
      hasColumns = (xScaled < xScaled + w) << 3;
      do {
        sampleX = xScaled;
        texelDst = transferRow;
        if ((bool)(hasColumns >> 3 & 1)) {
          do {
            sampleOffset = get_offset_of_sample_0((ATIR500SurfaceBuffer *)bufferBytes,sampleX,surfaceY);
            texelSrc = (UInt8 *)(sampleOffset + (int)surfaceRow);
            if (texelDst < (UInt64 *)((int)texelDst + (unsigned int)M<UInt16>(bufferBytes + 0x16))) {
              texelBytesLeft = (int)((int)texelDst + (unsigned int)M<UInt16>(bufferBytes + 0x16)) - (int)texelDst;
              copied = 0;
              do {
                byteValue = *texelSrc;
                texelSrc = texelSrc + 1;
                M<UInt8>((int)texelDst + copied) = byteValue;
                copied = copied + 1;
                texelBytesLeft = texelBytesLeft + -1;
              } while (texelBytesLeft != 0);
              texelDst = (UInt64 *)((int)texelDst + copied);
            }
            sampleX = sampleX + 1;
          } while (sampleX < xScaled + w);
        }
        surfaceY = surfaceY + -1;
        transferRow = (UInt64 *)((int)transferRow + pitch);
      } while (endY < surfaceY);
    }
  }
  else {
    if (1 < (tilingBits >> 0x14 & 0xf)) {
      M<UInt8>(M<int>(bufferBytes + 0x24) + 0x58) = 0;
    }
copyRows:
    if (sampleScaleX == 1) {
      if (0 < h) {
        row = 0;
        do {
          rowEnd = (UInt64 *)((int)transferRow + rowBytes);
          srcCursor = surfaceRow;
          dstCursor = transferRow;
          if ((transferRow < rowEnd) && (((unsigned int)transferRow & 7) != 0)) {
            srcRowEnd = (UInt64 *)((int)surfaceRow + ((int)rowEnd - (int)transferRow));
            bytesLeft = (int)srcRowEnd - (int)surfaceRow;
            srcByteCursor = surfaceRow;
            do {
              byteValue = M<UInt8>(srcByteCursor);
              srcByteCursor = (UInt64 *)((int)srcByteCursor + 1);
              M<UInt8>(dstCursor) = byteValue;
              dstCursor = (UInt64 *)((int)dstCursor + 1);
              bytesLeft = bytesLeft + -1;
              srcCursor = srcRowEnd;
              if (bytesLeft == 0) break;
              srcCursor = srcByteCursor;
            } while (((unsigned int)dstCursor & 7) != 0);
          }
          while (dstCursor + 4 <= rowEnd) {
            *dstCursor = *srcCursor;
            dstCursor[1] = srcCursor[1];
            dstCursor[2] = srcCursor[2];
            dstCursor[3] = srcCursor[3];
            srcCursor = srcCursor + 4;
            dstCursor = dstCursor + 4;
          }
          while ((UInt64 *)((int)dstCursor + 4) <= rowEnd) {
            word = M<UInt32>(srcCursor);
            srcCursor = (UInt64 *)((int)srcCursor + 4);
            M<UInt32>(dstCursor) = word;
            dstCursor = (UInt64 *)((int)dstCursor + 4);
          }
          if (dstCursor < rowEnd) {
            bytesLeft = (int)rowEnd - (int)dstCursor;
            byteIndex = 0;
            do {
              byteValue = M<UInt8>(srcCursor);
              srcCursor = (UInt64 *)((int)srcCursor + 1);
              M<UInt8>(byteIndex + (int)dstCursor) = byteValue;
              byteIndex = byteIndex + 1;
              bytesLeft = bytesLeft + -1;
            } while (bytesLeft != 0);
          }
          row = row + 1;
          surfaceRow = (UInt64 *)((int)surfaceRow + sampleScaleY * rowPitch);
          transferRow = (UInt64 *)((int)transferRow + pitch);
        } while (h != row);
      }
    }
    else if (0 < h) {
      row = 0;
      do {
        surfaceRowEnd = (UInt64 *)((int)surfaceRow + rowBytes);
        if (surfaceRow < surfaceRowEnd) {
          tilingBits = (unsigned int)M<UInt16>(bufferBytes + 0x16);
          srcCursor = surfaceRow;
          dstCursor = transferRow;
          do {
            if (dstCursor < (UInt64 *)((int)dstCursor + tilingBits)) {
              bytesLeft = (int)((int)dstCursor + tilingBits) - (int)dstCursor;
              byteIndex = 0;
              do {
                byteValue = M<UInt8>(srcCursor);
                srcCursor = (UInt64 *)((int)srcCursor + 1);
                M<UInt8>(byteIndex + (int)dstCursor) = byteValue;
                byteIndex = byteIndex + 1;
                bytesLeft = bytesLeft + -1;
              } while (bytesLeft != 0);
              tilingBits = (unsigned int)M<UInt16>(bufferBytes + 0x16);
              dstCursor = (UInt64 *)((int)dstCursor + byteIndex);
            }
            srcCursor = (UInt64 *)((int)srcCursor + tilingBits);
          } while (srcCursor < surfaceRowEnd);
        }
        row = row + 1;
        surfaceRow = (UInt64 *)((int)surfaceRow + sampleScaleY * rowPitch);
        transferRow = (UInt64 *)((int)transferRow + pitch);
      } while (h != row);
    }
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
