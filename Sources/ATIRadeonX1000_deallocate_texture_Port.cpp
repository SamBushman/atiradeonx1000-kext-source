/*
 * ATIRadeonX1000_deallocate_texture_Port.cpp
 *
 * ATIRadeonX1000::deallocate_texture (real addr 0x1a620, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x1a620 */
void ATIRadeonX1000::deallocate_texture(VendorTextureBuffer *texture) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);

  UInt16 *nextFaceMaskPtr;
  UInt16 *nextFaceDirtyPtr;
  UInt8 type;
  UInt32 hzHandle;
  UInt32 faceCount;
  SInt32 infoCursor;
  UInt32 faceIndex;
  UInt32 facesLeft;
  
  type = textureBytes[0x20];
  if ((type == 0x3) || (type == 0x7)) {
    infoCursor = M<SInt32>(textureBytes + 0x14);
    faceCount = (UInt32)M<UInt8>(infoCursor + 0x34);
    if (faceCount != 0) {
      if ((M<UInt16>(infoCursor + 0x28) & ~M<UInt16>(infoCursor + 0x1c)) == 0) {
        faceIndex = 0;
        facesLeft = faceCount;
        if (faceCount == 0) {
          facesLeft = 1;
        }
        do {
          faceIndex = faceIndex + 1;
          facesLeft = facesLeft - 1;
          if (facesLeft == 0) {
            if (faceCount == faceIndex) goto freeHzHandles;
            break;
          }
          nextFaceMaskPtr = (UInt16 *)(infoCursor + 0x2a);
          nextFaceDirtyPtr = (UInt16 *)(infoCursor + 0x1e);
          infoCursor = infoCursor + 2;
        } while ((*nextFaceMaskPtr & ~*nextFaceDirtyPtr) == 0);
      }
      VCALL(M<SInt32>(self), 0x52c)(self,textureBytes,0xffffffff,0xffffffff);
    }
  }
  else if (type == 0x8) {
    if (textureBytes[0x54] == 0x0) {
      if (M<SInt32 *>(textureBytes + 0x10) != (SInt32 *)0x0) {
        VCALL(*M<SInt32 *>(textureBytes + 0x10), 0x18)(M<SInt32 *>(textureBytes + 0x10));
        M<UInt32>(textureBytes + 0x10) = 0;
      }
    }
    else {
      ((IOATIR500Accelerator *)(self))->pageOffDataBuffer((VendorTextureBuffer *)(textureBytes));
    }
  }
freeHzHandles:
  hzHandle = M<UInt32>(textureBytes + 0x6c);
  if (hzHandle != 0xffffffff) {
    if ((hzHandle & 0x3ff) != 0x3ff) {
      HZMEM_Free((_HZDATA *)((UInt8 *)(self + kIOATIR500Accelerator_hzmem)),hzHandle,0);
      hzHandle = M<UInt32>(textureBytes + 0x6c);
    }
    if ((hzHandle & 0xffc00) != 0xffc00) {
      HZMEM_Free((_HZDATA *)((UInt8 *)(self + kIOATIR500Accelerator_hzmem)),hzHandle,1);
    }
    M<UInt16>(textureBytes + 0x72) = 0;
    M<UInt16>(textureBytes + 0x7a) = 0;
    M<UInt32>(textureBytes + 0x6c) = 0xffffffff;
    M<UInt16>(textureBytes + 0x70) = 0;
    M<UInt32>(textureBytes + 0x74) = 0;
    M<UInt16>(textureBytes + 0x78) = 0;
  }
  ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPool)))->dealloc((GLKMemoryElement *)((UInt8 *)(textureBytes + 0x40)));
  return;
}
