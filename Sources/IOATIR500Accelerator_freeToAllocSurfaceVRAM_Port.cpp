/*
 * IOATIR500Accelerator_freeToAllocSurfaceVRAM_Port.cpp
 *
 * IOATIR500Accelerator::freeToAllocSurfaceVRAM (real addr 0x45a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x45a0 */
UInt32 IOATIR500Accelerator::freeToAllocSurfaceVRAM(IOATIR500Surface *excludeA, IOATIR500Surface *excludeB, VendorTextureBuffer**excludeList, SInt32 excludeCount, ATIR500SurfaceBuffer *needed) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *excludeABytes = reinterpret_cast<UInt8 *>(excludeA);
    UInt8 *excludeBBytes = reinterpret_cast<UInt8 *>(excludeB);
    UInt8 *neededBytes = reinterpret_cast<UInt8 *>(needed);

  UInt16 *faceFieldAPtr;
  UInt16 *faceFieldBPtr;
  bool secondPass;
  UInt8 *excludedTexture;
  int nextNode;
  UInt8 **excludeCursor;
  unsigned int faceIndex;
  UInt8 *surfaceListHead;
  UInt8 *surfaceBuffer;
  UInt8 *texture;
  UInt8 *surface;
  UInt8 excludeAIsNull;
  UInt8 excludeFlags;
  long excludeLeft;
  unsigned int facesLeft;
  int allocStatus;
  int excludeIndex;
  int faceCursor;
  int prevNode;
  unsigned int bufferIndex;
  unsigned int faceCount;
  
  excludeAIsNull = (excludeABytes == (UInt8 *)0x0) << 1;
  secondPass = false;
  do {
    while( true ) {
      if ((bool)(excludeAIsNull >> 1 & 1)) {
        allocStatus = VCALL(M<int>(self), 0x56c)(self,neededBytes);
      }
      else {
        allocStatus = VCALL(M<int>(excludeABytes), 0x5d0)(excludeABytes,neededBytes);
      }
      if (allocStatus == 1) break;
      texture = M<UInt8 *>(self + kIOATIR500Accelerator_textureVramListFirst);
      do {
        do {
          while( true ) {
            if (self + kIOATIR500Accelerator_textureVramListSentinel == texture) goto afterTextureScan;
            if (excludeCount < 1) break;
            if (texture != (UInt8 *)*excludeList) {
              excludeIndex = 0;
              excludeLeft = excludeCount;
              do {
                excludeIndex = excludeIndex + 1;
                excludeLeft = excludeLeft + -1;
                if (excludeLeft == 0) goto examineTexture;
              } while (texture != (UInt8 *)excludeList[excludeIndex]);
            }
nextTexture:
            texture = M<UInt8 *>(texture + 0x28);
          }
        } while (excludeCount != 0);
examineTexture:
        if ((secondPass) || (faceCursor = M<int>(texture + 0x14), faceCursor == 0)) break;
        faceCount = (unsigned int)M<UInt8>(faceCursor + 0x34);
        faceIndex = 0;
        if (faceCount != 0) {
          if ((M<UInt16>(faceCursor + 0x28) & ~M<UInt16>(faceCursor + 0x1c)) == 0) {
            faceIndex = 0;
            facesLeft = faceCount;
            if (faceCount == 0) {
              facesLeft = 1;
            }
            do {
              faceIndex = faceIndex + 1;
              facesLeft = facesLeft - 1;
              if (facesLeft == 0) goto facesDone;
              faceFieldAPtr = (UInt16 *)(faceCursor + 0x1e);
              faceFieldBPtr = (UInt16 *)(faceCursor + 0x2a);
              faceCursor = faceCursor + 2;
            } while ((*faceFieldBPtr & ~*faceFieldAPtr) == 0);
          }
          goto nextTexture;
        }
facesDone: ;
      } while (faceIndex != faceCount);
      if (M<int>(texture + 0x48) != 0) {
        VCALL(M<int>(self), 0x524)(self,texture);
        M<UInt8>(M<int>(texture + 0x14) + 0x14) = 1;
        M<UInt16>(M<int>(texture + 0x14) + 0x28) = 0;
        M<UInt16>(M<int>(texture + 0x14) + 0x2a) = 0;
        M<UInt16>(M<int>(texture + 0x14) + 0x2c) = 0;
        M<UInt16>(M<int>(texture + 0x14) + 0x2e) = 0;
        M<UInt16>(M<int>(texture + 0x14) + 0x30) = 0;
        M<UInt16>(M<int>(texture + 0x14) + 0x32) = 0;
      }
      prevNode = M<int>(texture + 0x24);
      M<UInt32>(prevNode + 0x28) = M<UInt32>(texture + 0x28);
      nextNode = M<int>(texture + 0x28);
      M<UInt8 *>(texture + 0x28) = texture;
      M<int>(nextNode + 0x24) = prevNode;
      M<UInt8 *>(texture + 0x24) = texture;
    }
afterTextureScan:
    if (M<int>(neededBytes + 8) != 0) {
      return 1;
    }
    if (secondPass) {
      return 0;
    }
    surfaceListHead = M<UInt8 *>(self + kIOATIR500Accelerator_liveSurfaceListHead);
    if (surfaceListHead != (UInt8 *)0x0) {
      excludeFlags = (0 < excludeCount) << 2 | (excludeCount == 0) << 1;
      surface = surfaceListHead;
      do {
        surface = M<UInt8 *>(surface + 0xa0);
        if ((excludeABytes != surface) && (surface != excludeBBytes)) {
          excludeCursor = (UInt8 **)excludeList;
          excludeLeft = excludeCount;
          if ((bool)(excludeFlags >> 2 & 1)) {
            do {
              excludedTexture = *excludeCursor;
              excludeCursor = excludeCursor + 1;
              if (((excludedTexture != (UInt8 *)0x0) &&
                  (excludedTexture[0x20] == 0x0)) &&
                 (surface == M<UInt8 *>(excludedTexture + 0x50))) goto nextSurface;
              excludeLeft = excludeLeft + -1;
            } while (excludeLeft != 0);
          }
          else if (!(bool)(excludeFlags >> 1 & 1)) goto nextSurface;
          bufferIndex = 0;
          surfaceBuffer = (UInt8 *)(surface + 0xa8);
          do {
            if ((((M<int>(surface + 0xc14) == 0xffff) || ((1 < bufferIndex && (1 < bufferIndex - 4)))) &&
                (M<int>(surfaceBuffer + 8) != 0)) &&
               (((M<unsigned int>(surface + 0xbd0) & 0xffff0000) == 0 ||
                (surfaceBuffer != M<UInt8 *>(surface + 0xb70))))) {
              if (M<int>(surface + 0xd48) == 0) {
                ((IOATIR500Surface *)(surface))->move_buffer_to_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer));
              }
              else {
                VCALL(M<int>(surface), 0x5cc)(surface,bufferIndex);
              }
              if ((bool)(excludeAIsNull >> 1 & 1)) {
                VCALL(M<int>(self), 0x56c)(self,neededBytes);
              }
              else {
                VCALL(M<int>(excludeABytes), 0x5d0)(excludeABytes,neededBytes);
              }
              if (M<int>(neededBytes + 8) != 0) {
                return 1;
              }
            }
            secondPass = bufferIndex != 0x16;
            surfaceBuffer = surfaceBuffer + 0x78;
            bufferIndex = bufferIndex + 1;
          } while (secondPass);
          surfaceListHead = M<UInt8 *>(self + kIOATIR500Accelerator_liveSurfaceListHead);
        }
nextSurface: ;
      } while (surface != surfaceListHead);
    }
    secondPass = true;
  } while( true );
}
