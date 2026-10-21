/*
 * ATIRadeonX1000_freeToAllocTextureCPUVisibleVRAM_Port.cpp
 *
 * ATIRadeonX1000::freeToAllocTextureCPUVisibleVRAM (real addr 0x1e320, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x1e320 */
UInt32 ATIRadeonX1000::freeToAllocTextureCPUVisibleVRAM(VendorTextureBuffer *texture, UInt32 size) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);

  UInt16 *nextFaceMaskPtr;
  UInt16 *nextFaceDirtyPtr;
  UInt32 faceCount;
  SInt32 infoCursor;
  UInt32 faceIndex;
  SInt32 prevEntry;
  UInt8 *candidate;
  UInt32 facesLeft;
  SInt32 nextEntry;
  SInt32 allocResult;
  
  VCALL(M<SInt32>(self), 0x558)(self,M<SInt32>(self + kIOATIR500Accelerator_submitStamp) + -1);
  candidate = M<UInt8 *>(self + kIOATIR500Accelerator_textureVramListFirst);
  do {
    while( true ) {
      if (self + kIOATIR500Accelerator_textureVramListSentinel == candidate) {
        return 0;
      }
      if (M<UInt32>(candidate + 0x48) < M<UInt32>(self + kIOATIR500Accelerator_usableVramSize)) break;
nextCandidate:
      candidate = M<UInt8 *>(candidate + 0x28);
    }
    infoCursor = M<SInt32>(candidate + 0x14);
    if (infoCursor == 0) {
evictCandidate:
      VCALL(M<SInt32>(self), 0x524)(self,candidate);
      M<UInt8>(M<SInt32>(candidate + 0x14) + 0x14) = 1;
      M<UInt16>(M<SInt32>(candidate + 0x14) + 0x28) = 0;
      M<UInt16>(M<SInt32>(candidate + 0x14) + 0x2a) = 0;
      M<UInt16>(M<SInt32>(candidate + 0x14) + 0x2c) = 0;
      M<UInt16>(M<SInt32>(candidate + 0x14) + 0x2e) = 0;
      M<UInt16>(M<SInt32>(candidate + 0x14) + 0x30) = 0;
      M<UInt16>(M<SInt32>(candidate + 0x14) + 0x32) = 0;
      prevEntry = M<SInt32>(candidate + 0x24);
      M<UInt32>(prevEntry + 0x28) = M<UInt32>(candidate + 0x28);
      nextEntry = M<SInt32>(candidate + 0x28);
      M<UInt8 *>(candidate + 0x28) = candidate;
      M<SInt32>(nextEntry + 0x24) = prevEntry;
      M<UInt8 *>(candidate + 0x24) = candidate;
      M<SInt32>(self + kIOATIR500Accelerator_vramScanEvictedCount) = M<SInt32>(self + kIOATIR500Accelerator_vramScanEvictedCount) + 1;
      allocResult = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPool)))->alloc((GLKMemoryElement *)((UInt8 *)(textureBytes + 0x40)),
                         size,0x1000,0,M<UInt32>(self + kIOATIR500Accelerator_usableVramSize));
      if (allocResult != 0) {
        return 1;
      }
      goto nextCandidate;
    }
    faceCount = (UInt32)M<UInt8>(infoCursor + 0x34);
    faceIndex = 0;
    if (faceCount == 0) {
checkAllFacesFree:
      if (faceIndex == faceCount) goto evictCandidate;
    }
    else if ((M<UInt16>(infoCursor + 0x28) & ~M<UInt16>(infoCursor + 0x1c)) == 0) {
      faceIndex = 0;
      facesLeft = faceCount;
      if (faceCount == 0) {
        facesLeft = 1;
      }
      do {
        faceIndex = faceIndex + 1;
        facesLeft = facesLeft - 1;
        if (facesLeft == 0) goto checkAllFacesFree;
        nextFaceMaskPtr = (UInt16 *)(infoCursor + 0x2a);
        nextFaceDirtyPtr = (UInt16 *)(infoCursor + 0x1e);
        infoCursor = infoCursor + 2;
      } while ((*nextFaceMaskPtr & ~*nextFaceDirtyPtr) == 0);
    }
  } while( true );
}
