/*
 * IOATIR500Accelerator_freeWaitToAllocGART_Port.cpp
 *
 * IOATIR500Accelerator::freeWaitToAllocGART (real addr 0x37f0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x37f0 */
bool IOATIR500Accelerator::freeWaitToAllocGART(IOATIR5002DContext *exclude2D, IOATIR500DVDContext *excludeDVD, IOATIR500GLContext *excludeGL, IOATIR500Surface *excludeSurface, IOATIR500Shared *excludeShared, VendorTransferBuffer *needed, bool aggressive) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *exclude2DBytes = reinterpret_cast<UInt8 *>(exclude2D);
    UInt8 *excludeDVDBytes = reinterpret_cast<UInt8 *>(excludeDVD);
    UInt8 *excludeGLBytes = reinterpret_cast<UInt8 *>(excludeGL);
    UInt8 *excludeSurfaceBytes = reinterpret_cast<UInt8 *>(excludeSurface);
    UInt8 *excludeSharedBytes = reinterpret_cast<UInt8 *>(excludeShared);
    UInt8 *neededBytes = reinterpret_cast<UInt8 *>(needed);

  UInt16 ringEntryCount;
  UInt8 *surfaceListHead;
  SInt32 iVar3;
  UInt8 *shared;
  UInt32 ringIndex;
  UInt32 in_register_00000028;
  UInt32 visited;
  UInt8 *context2D;
  UInt8 *contextDVD;
  UInt8 *contextGL;
  UInt8 *surface;
  UInt8 *dataBuffer;
  
  if (M<UInt8 *>(self + kIOATIR500Accelerator_orphanTextureList_next) != self + kIOATIR500Accelerator_orphanTextureList) {
    this->freeOrphanTexture(aggressive);
    iVar3 = VCALL(M<SInt32>(self), 0x5a8)(self,neededBytes);
    if (iVar3 != 0) {
      return 1;
    }
  }
  for (context2D = M<UInt8 *>(self + kIOATIR500Accelerator_live2DContextListHead); context2D != (UInt8 *)0x0;
      context2D = M<UInt8 *>(context2D + 0x80)) {
    if (context2D != exclude2DBytes) {
      shared = M<UInt8 *>(context2D + 0x88);
      if (((shared != (UInt8 *)0x0) && (excludeSharedBytes != shared)) &&
         (iVar3 = ((IOATIR500Shared *)(shared))->freeToAllocGART((VendorTransferBuffer *)(neededBytes), aggressive), iVar3 != 0)) {
        return 1;
      }
      iVar3 = ((IOATIR5002DContext *)(context2D))->freeToAllocGART((VendorTransferBuffer *)(neededBytes), aggressive);
      if (iVar3 != 0) {
        return 1;
      }
    }
  }
  for (contextDVD = M<UInt8 *>(self + kIOATIR500Accelerator_liveDVDContextListHead); contextDVD != (UInt8 *)0x0;
      contextDVD = M<UInt8 *>(contextDVD + 0x80)) {
    if (contextDVD != excludeDVDBytes) {
      shared = M<UInt8 *>(contextDVD + 0x84);
      if (((shared != (UInt8 *)0x0) && (excludeSharedBytes != shared)) &&
         (iVar3 = ((IOATIR500Shared *)(shared))->freeToAllocGART((VendorTransferBuffer *)(neededBytes), aggressive), iVar3 != 0)) {
        return 1;
      }
      iVar3 = ((IOATIR500DVDContext *)(contextDVD))->freeToAllocGART((VendorTransferBuffer *)(neededBytes), aggressive);
      if (iVar3 != 0) {
        return 1;
      }
    }
  }
  for (contextGL = M<UInt8 *>(self + kIOATIR500Accelerator_liveGLContextListHead); contextGL != (UInt8 *)0x0;
      contextGL = M<UInt8 *>(contextGL + 0x80)) {
    if (contextGL != excludeGLBytes) {
      if ((excludeSharedBytes != M<UInt8 *>(contextGL + 0x88)) &&
         (iVar3 = ((IOATIR500Shared *)(M<UInt8 *>(contextGL + 0x88)))->freeToAllocGART((VendorTransferBuffer *)(neededBytes),aggressive), iVar3 != 0)) {
        return 1;
      }
      iVar3 = ((IOATIR500GLContext *)(contextGL))->freeToAllocGART((VendorTransferBuffer *)(neededBytes), aggressive);
      if (iVar3 != 0) {
        return 1;
      }
    }
  }
  surfaceListHead = M<UInt8 *>(self + kIOATIR500Accelerator_liveSurfaceListHead);
  surface = surfaceListHead;
  if (surfaceListHead != (UInt8 *)0x0) {
    do {
      surface = M<UInt8 *>(surface + 0xa0);
      if (excludeSurfaceBytes != surface) {
        iVar3 = ((IOATIR500Surface *)(surface))->freeToAllocGART((VendorTransferBuffer *)(neededBytes), aggressive);
        if (iVar3 != 0) {
          return 1;
        }
        surfaceListHead = M<UInt8 *>(self + kIOATIR500Accelerator_liveSurfaceListHead);
      }
    } while (surface != surfaceListHead);
  }
  if ((excludeSharedBytes == (UInt8 *)0x0) ||
     (iVar3 = ((IOATIR500Shared *)(excludeSharedBytes))->freeToAllocGART((VendorTransferBuffer *)(neededBytes), aggressive), iVar3 == 0)) {
    if (((UInt32)aggressive) == 0) {
      ringEntryCount = M<UInt16>(self + kIOATIR500Accelerator_commandBufferRing1Count);
      ringIndex = (UInt32)M<UInt16>(self + kIOATIR500Accelerator_commandBufferRing1Head);
      if (ringEntryCount != 0) {
        visited = 0;
        do {
          ringIndex = ringIndex - 1 & ringEntryCount - 1;
          iVar3 = this->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + ringIndex * 0x1c + 0x404)),(VendorTransferBuffer *)(neededBytes),
                             M<UInt32>(self + ringIndex * 0x1c + 0x414),false);
          if (iVar3 != 0) {
            return 1;
          }
          visited = visited + 1;
        } while (visited < M<UInt16>(self + kIOATIR500Accelerator_commandBufferRing1Count));
      }
      ringEntryCount = M<UInt16>(self + kIOATIR500Accelerator_commandBufferRing0Count);
      ringIndex = (UInt32)M<UInt16>(self + kIOATIR500Accelerator_commandBufferRing0Head);
      if (ringEntryCount != 0) {
        visited = 0;
        do {
          ringIndex = ringIndex - 1 & ringEntryCount - 1;
          iVar3 = this->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + ringIndex * 0x1c + 0x240)),(VendorTransferBuffer *)(neededBytes),
                             M<UInt32>(self + ringIndex * 0x1c + 0x250),false);
          if (iVar3 != 0) {
            return 1;
          }
          visited = visited + 1;
        } while (visited < M<UInt16>(self + kIOATIR500Accelerator_commandBufferRing0Count));
      }
    }
    else {
      ringEntryCount = M<UInt16>(self + kIOATIR500Accelerator_commandBufferRing1Count);
      ringIndex = (UInt32)M<UInt16>(self + kIOATIR500Accelerator_commandBufferRing1Head);
      if (ringEntryCount != 0) {
        visited = 0;
        do {
          ringIndex = ringIndex & ringEntryCount - 1;
          iVar3 = ringIndex * 0x1c;
          iVar3 = this->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + iVar3 + 0x404)),(VendorTransferBuffer *)(neededBytes),
                             M<UInt32>(self + iVar3 + 0x414),true);
          if (iVar3 != 0) {
            return 1;
          }
          visited = visited + 1;
          ringIndex = ringIndex + 1;
        } while (visited < M<UInt16>(self + kIOATIR500Accelerator_commandBufferRing1Count));
      }
      ringEntryCount = M<UInt16>(self + kIOATIR500Accelerator_commandBufferRing0Count);
      ringIndex = (UInt32)M<UInt16>(self + kIOATIR500Accelerator_commandBufferRing0Head);
      if (ringEntryCount != 0) {
        visited = 0;
        do {
          ringIndex = ringIndex & ringEntryCount - 1;
          iVar3 = ringIndex * 0x1c;
          iVar3 = this->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + iVar3 + 0x240)),(VendorTransferBuffer *)(neededBytes),
                             M<UInt32>(self + iVar3 + 0x250),true);
          if (iVar3 != 0) {
            return 1;
          }
          visited = visited + 1;
          ringIndex = ringIndex + 1;
        } while (visited < M<UInt16>(self + kIOATIR500Accelerator_commandBufferRing0Count));
      }
    }
    for (dataBuffer = M<UInt8 *>(self + kIOATIR500Accelerator_dataBufferCacheHead); dataBuffer != (UInt8 *)0x0;
        dataBuffer = M<UInt8 *>(dataBuffer + 0x3c)) {
      iVar3 = this->freeTransferToAllocGART((VendorTransferBuffer *)(dataBuffer),(VendorTransferBuffer *)(neededBytes),M<UInt32>(dataBuffer + 0x5c),aggressive);
      if (iVar3 != 0) {
        return 1;
      }
    }
    if (((((exclude2DBytes == (UInt8 *)0x0) ||
          (iVar3 = ((IOATIR5002DContext *)(exclude2DBytes))->freeToAllocGART((VendorTransferBuffer *)(neededBytes), aggressive), iVar3 == 0)) &&
         ((excludeDVDBytes == (UInt8 *)0x0 ||
          (iVar3 = ((IOATIR500DVDContext *)(excludeDVDBytes))->freeToAllocGART((VendorTransferBuffer *)(neededBytes), aggressive), iVar3 == 0)))) &&
        ((excludeGLBytes == (UInt8 *)0x0 ||
         (iVar3 = ((IOATIR500GLContext *)(excludeGLBytes))->freeToAllocGART((VendorTransferBuffer *)(neededBytes), aggressive), iVar3 == 0)))) &&
       ((excludeSurfaceBytes == (UInt8 *)0x0 ||
        (iVar3 = ((IOATIR500Surface *)(excludeSurfaceBytes))->freeToAllocGART((VendorTransferBuffer *)(neededBytes), aggressive), iVar3 == 0)))) {
      return 0;
    }
  }
  return 1;
}
