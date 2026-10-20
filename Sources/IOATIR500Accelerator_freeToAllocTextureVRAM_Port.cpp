/*
 * IOATIR500Accelerator_freeToAllocTextureVRAM_Port.cpp
 *
 * IOATIR500Accelerator::freeToAllocTextureVRAM (real addr 0x3f60, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3f60 */
UInt32 IOATIR500Accelerator::freeToAllocTextureVRAM(IOATIR500Surface *surface, VendorTextureBuffer**excludeList, SInt32 excludeCount, VendorTextureBuffer *needed) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *surfaceBytes = reinterpret_cast<UInt8 *>(surface);
    UInt8 *neededBytes = reinterpret_cast<UInt8 *>(needed);

  UInt16 *faceFieldAPtr;
  UInt16 *faceFieldBPtr;
  bool tailAtSentinel;
  bool secondPass;
  UInt8 *node;
  UInt32 faceCount;
  UInt8 firstPassFlags;
  UInt8 walkEndFlags;
  long excludeLeft;
  SInt32 allocStatus;
  SInt32 tossStatus;
  SInt32 excludeIndex;
  SInt32 textureRecord;
  SInt32 stampReached;
  SInt32 nextNode;
  SInt32 faceCursor;
  SInt32 prevNode;
  UInt32 facesChecked;
  UInt32 facesLeft;
  UInt32 tailFacesChecked;
  UInt32 tailFacesLeft;
  UInt8 *tailSentinel;
  UInt8 *tailNode;
  UInt8 *listSentinel;
  UInt8 *firstSkipped;
  
  if (((M<SInt32>(self + kIOATIR500Accelerator_volatileSurfaceCount) == 0) ||
      (allocStatus = VCALL(M<SInt32>(self), 0x528)(self,neededBytes), allocStatus != 0)) ||
     (tossStatus = this->tossSurfacesForVRAM((IOATIR500Surface *)(surfaceBytes),(VendorTextureBuffer **)(excludeList),excludeCount,(VendorTextureBuffer *)(neededBytes),true), tossStatus == 0)) {
    secondPass = false;
LAB_00004450:
    allocStatus = VCALL(M<SInt32>(self), 0x528)(self,neededBytes);
    if (allocStatus == 0) {
      M<SInt32>(self + kIOATIR500Accelerator_textureVRAMAllocFailCount) = M<SInt32>(self + kIOATIR500Accelerator_textureVRAMAllocFailCount) + 1;
      if (surfaceBytes == (UInt8 *)0x0) {
        node = M<UInt8 *>(self + kIOATIR500Accelerator_textureVramListFirst);
      }
      else {
        node = M<UInt8 *>(self + kIOATIR500Accelerator_textureVramListFirst);
        tailSentinel = self + kIOATIR500Accelerator_textureVramListSentinel;
        if ((node == tailSentinel) ||
           (M<SInt32>(surfaceBytes + 0x84) - M<SInt32>(M<SInt32>(node + 0x14) + 8) < 1)) {
          tailNode = M<UInt8 *>(self + kIOATIR500Accelerator_vramBufferList_prev);
          firstPassFlags = !secondPass << 1;
          node = (UInt8 *)0x0;
          tailAtSentinel = tailNode == tailSentinel;
LAB_00004294:
          if ((!tailAtSentinel) && (walkEndFlags = (tailNode == node) << 1, tailNode != node)) {
            M<SInt32>(self + kIOATIR500Accelerator_vramScanTailExaminedCount) = M<SInt32>(self + kIOATIR500Accelerator_vramScanTailExaminedCount) + 1;
            if (excludeCount < 1) goto code_r0x00004264;
            if (tailNode != (UInt8 *)*excludeList) {
              excludeIndex = 0;
              excludeLeft = excludeCount;
              do {
                excludeIndex = excludeIndex + 1;
                excludeLeft = excludeLeft + -1;
                if (excludeLeft == 0) goto LAB_000042b8;
              } while ((UInt8 *)excludeList[excludeIndex] != tailNode);
            }
            M<SInt32>(self + kIOATIR500Accelerator_vramScanTailExcludedCount) = M<SInt32>(self + kIOATIR500Accelerator_vramScanTailExcludedCount) + 1;
            goto LAB_0000428c;
          }
          goto LAB_00004448;
        }
      }
      listSentinel = self + kIOATIR500Accelerator_textureVramListSentinel;
      firstPassFlags = !secondPass << 1;
      firstSkipped = (UInt8 *)0x0;
LAB_00004040:
      do {
        if ((node == listSentinel) || (walkEndFlags = (firstSkipped == node) << 1, firstSkipped == node))
        goto LAB_00004448;
        M<SInt32>(self + kIOATIR500Accelerator_vramScanExaminedCount) = M<SInt32>(self + kIOATIR500Accelerator_vramScanExaminedCount) + 1;
        if (excludeCount < 1) {
          if (excludeCount == 0) {
LAB_000040b8:
            if ((bool)(firstPassFlags >> 1 & 1)) {
              textureRecord = M<SInt32>(node + 0x14);
              if ((textureRecord == 0) || (faceCount = (UInt32)M<UInt8>(textureRecord + 0x34), faceCount == 0))
              goto LAB_00004124;
              if ((M<UInt16>(textureRecord + 0x28) & ~M<UInt16>(textureRecord + 0x1c)) == 0) {
                facesChecked = 0;
                faceCursor = textureRecord;
                facesLeft = faceCount;
                if (faceCount == 0) {
                  facesLeft = 1;
                }
                do {
                  facesChecked = facesChecked + 1;
                  facesLeft = facesLeft - 1;
                  if (facesLeft == 0) {
                    if (faceCount == facesChecked) goto LAB_00004124;
                    goto LAB_00004040;
                  }
                  faceFieldAPtr = (UInt16 *)(faceCursor + 0x1e);
                  faceFieldBPtr = (UInt16 *)(faceCursor + 0x2a);
                  faceCursor = faceCursor + 2;
                } while ((*faceFieldBPtr & ~*faceFieldAPtr) == 0);
              }
              M<SInt32>(self + kIOATIR500Accelerator_vramScanInUseCount) = M<SInt32>(self + kIOATIR500Accelerator_vramScanInUseCount) + 1;
            }
            else {
              textureRecord = M<SInt32>(node + 0x14);
LAB_00004124:
              stampReached = VCALL(M<SInt32>(self), 0x554)(self,M<UInt32>(textureRecord + 0xc));
              if (stampReached != 0) {
                if (M<SInt32>(node + 0x48) != 0) {
                  VCALL(M<SInt32>(self), 0x524)(self,node);
                  M<UInt8>(M<SInt32>(node + 0x14) + 0x14) = 1;
                  M<UInt16>(M<SInt32>(node + 0x14) + 0x28) = 0;
                  M<UInt16>(M<SInt32>(node + 0x14) + 0x2a) = 0;
                  M<UInt16>(M<SInt32>(node + 0x14) + 0x2c) = 0;
                  M<UInt16>(M<SInt32>(node + 0x14) + 0x2e) = 0;
                  M<UInt16>(M<SInt32>(node + 0x14) + 0x30) = 0;
                  M<UInt16>(M<SInt32>(node + 0x14) + 0x32) = 0;
                }
                prevNode = M<SInt32>(node + 0x24);
                M<UInt32>(prevNode + 0x28) = M<UInt32>(node + 0x28);
                nextNode = M<SInt32>(node + 0x28);
                M<UInt8 *>(node + 0x28) = node;
                M<SInt32>(nextNode + 0x24) = prevNode;
                M<UInt8 *>(node + 0x24) = node;
                M<SInt32>(self + kIOATIR500Accelerator_vramScanEvictedCount) = M<SInt32>(self + kIOATIR500Accelerator_vramScanEvictedCount) + 1;
                if (listSentinel != node) goto LAB_00004430;
                goto LAB_00004448;
              }
              M<SInt32>(self + kIOATIR500Accelerator_vramScanBusyCount) = M<SInt32>(self + kIOATIR500Accelerator_vramScanBusyCount) + 1;
            }
            if (firstSkipped == (UInt8 *)0x0) {
              firstSkipped = node;
            }
            if (M<SInt32>(node + 0x48) != 0) {
              prevNode = M<SInt32>(node + 0x24);
              M<UInt32>(prevNode + 0x28) = M<UInt32>(node + 0x28);
              nextNode = M<SInt32>(node + 0x28);
              M<UInt8 *>(node + 0x28) = listSentinel;
              M<SInt32>(nextNode + 0x24) = prevNode;
              M<UInt32>(node + 0x24) = M<UInt32>(self + kIOATIR500Accelerator_vramBufferList_prev);
              M<UInt8 *>(self + kIOATIR500Accelerator_vramBufferList_prev) = node;
              M<UInt8 *>(M<SInt32>(node + 0x24) + 0x28) = node;
            }
            node = M<UInt8 *>(node + 0x28);
          }
          goto LAB_00004040;
        }
        if ((UInt8 *)*excludeList != node) {
          excludeIndex = 0;
          excludeLeft = excludeCount;
          do {
            excludeIndex = excludeIndex + 1;
            excludeLeft = excludeLeft + -1;
            if (excludeLeft == 0) goto LAB_000040b8;
          } while ((UInt8 *)excludeList[excludeIndex] != node);
        }
        M<SInt32>(self + kIOATIR500Accelerator_vramScanExcludedCount) = M<SInt32>(self + kIOATIR500Accelerator_vramScanExcludedCount) + 1;
        node = M<UInt8 *>(node + 0x28);
      } while( true );
    }
LAB_00004474:
    if ((M<SInt32>(neededBytes + 0x48) == 0) &&
       (tossStatus = this->tossSurfacesForVRAM((IOATIR500Surface *)(surfaceBytes),(VendorTextureBuffer **)(excludeList),excludeCount,(VendorTextureBuffer *)(neededBytes),false), tossStatus == 0)) {
      return 0;
    }
  }
  return 1;
code_r0x00004264:
  if (excludeCount != 0) goto LAB_00004294;
LAB_000042b8:
  if ((bool)(firstPassFlags >> 1 & 1)) {
    textureRecord = M<SInt32>(tailNode + 0x14);
    if (textureRecord != 0) {
      faceCount = (UInt32)M<UInt8>(textureRecord + 0x34);
      tailFacesChecked = 0;
      if (faceCount != 0) {
        if ((M<UInt16>(textureRecord + 0x28) & ~M<UInt16>(textureRecord + 0x1c)) == 0) {
          tailFacesChecked = 0;
          faceCursor = textureRecord;
          tailFacesLeft = faceCount;
          if (faceCount == 0) {
            tailFacesLeft = 1;
          }
          do {
            tailFacesChecked = tailFacesChecked + 1;
            tailFacesLeft = tailFacesLeft - 1;
            if (tailFacesLeft == 0) goto LAB_00004314;
            faceFieldAPtr = (UInt16 *)(faceCursor + 0x1e);
            faceFieldBPtr = (UInt16 *)(faceCursor + 0x2a);
            faceCursor = faceCursor + 2;
          } while ((*faceFieldBPtr & ~*faceFieldAPtr) == 0);
        }
        M<SInt32>(self + kIOATIR500Accelerator_vramScanTailInUseCount) = M<SInt32>(self + kIOATIR500Accelerator_vramScanTailInUseCount) + 1;
        goto joined_r0x00004360;
      }
LAB_00004314:
      if (tailFacesChecked != faceCount) goto LAB_00004294;
    }
    stampReached = VCALL(M<SInt32>(self), 0x554)(self,M<UInt32>(textureRecord + 0xc));
    if (stampReached == 0) {
      M<SInt32>(self + kIOATIR500Accelerator_vramScanTailBusyCount) = M<SInt32>(self + kIOATIR500Accelerator_vramScanTailBusyCount) + 1;
joined_r0x00004360:
      if (node == (UInt8 *)0x0) {
        node = tailNode;
      }
      if (M<SInt32>(tailNode + 0x48) != 0) {
        prevNode = M<SInt32>(tailNode + 0x24);
        M<UInt32>(prevNode + 0x28) = M<UInt32>(tailNode + 0x28);
        nextNode = M<SInt32>(tailNode + 0x28);
        M<UInt32>(tailNode + 0x28) = M<UInt32>(self + kIOATIR500Accelerator_textureVramListFirst);
        M<UInt8 *>(self + kIOATIR500Accelerator_textureVramListFirst) = tailNode;
        M<SInt32>(nextNode + 0x24) = prevNode;
        M<UInt8 *>(tailNode + 0x24) = tailSentinel;
        M<UInt8 *>(M<SInt32>(tailNode + 0x28) + 0x24) = tailNode;
      }
LAB_0000428c:
      tailNode = M<UInt8 *>(tailNode + 0x24);
      tailAtSentinel = tailNode == tailSentinel;
      goto LAB_00004294;
    }
  }
  if (M<SInt32>(tailNode + 0x48) != 0) {
    VCALL(M<SInt32>(self), 0x524)(self,tailNode);
    M<UInt8>(M<SInt32>(tailNode + 0x14) + 0x14) = 1;
    M<UInt16>(M<SInt32>(tailNode + 0x14) + 0x28) = 0;
    M<UInt16>(M<SInt32>(tailNode + 0x14) + 0x2a) = 0;
    M<UInt16>(M<SInt32>(tailNode + 0x14) + 0x2c) = 0;
    M<UInt16>(M<SInt32>(tailNode + 0x14) + 0x2e) = 0;
    M<UInt16>(M<SInt32>(tailNode + 0x14) + 0x30) = 0;
    M<UInt16>(M<SInt32>(tailNode + 0x14) + 0x32) = 0;
  }
  prevNode = M<SInt32>(tailNode + 0x24);
  M<UInt32>(prevNode + 0x28) = M<UInt32>(tailNode + 0x28);
  nextNode = M<SInt32>(tailNode + 0x28);
  M<UInt8 *>(tailNode + 0x28) = tailNode;
  M<SInt32>(nextNode + 0x24) = prevNode;
  M<UInt8 *>(tailNode + 0x24) = tailNode;
  M<SInt32>(self + kIOATIR500Accelerator_vramScanTailEvictedCount) = M<SInt32>(self + kIOATIR500Accelerator_vramScanTailEvictedCount) + 1;
  if (tailSentinel != tailNode) goto LAB_00004430;
  goto LAB_00004448;
LAB_00004430:
  if ((bool)(walkEndFlags >> 1 & 1)) {
LAB_00004448:
    if (!(bool)(firstPassFlags >> 1 & 1)) goto LAB_00004474;
    secondPass = true;
  }
  goto LAB_00004450;
}
