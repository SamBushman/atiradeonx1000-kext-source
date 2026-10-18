/*
 * IOATIR500DVDContext_set_surface_Port.cpp
 *
 * IOATIR500DVDContext::set_surface (real addr 0xfa40, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");


/* real addr 0xfa40 */
IOReturn IOATIR500DVDContext::set_surface(UInt32 surfaceID, eIODVDContextModeBits modeBits, int flagCount) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool unbind;
  unsigned int uVar2;
  unsigned int uVar3;
  int accepted;
  unsigned int bufferMask;
  UInt32 result;
  UInt8 *newSurface;
  unsigned int currentModeBits [8];
  
  GH_IOLockLock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
  if (surfaceID == 0) {
    result = 0;
    newSurface = (UInt8 *)0x0;
    unbind = true;
  }
  else {
    newSurface = (UInt8 *)
              ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500DVDContext_accelerator)))->find_surface_for_id(surfaceID);
    unbind = newSurface == (UInt8 *)0x0;
    if (unbind) {
      result = 0xe00002c2;
    }
    else {
      result = 0;
    }
  }
  if (M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface) != (UInt8 *)0x0) {
    ((IOATIR500Surface *)(M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface)))->remove_dvd_context((IOATIR500DVDContext *)(self));
    if (newSurface != M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface)) {
      ((IOATIR500Surface *)(M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface)))->prune_buffers();
    }
  }
  if ((unbind) ||
     ((M<UInt8 *>(newSurface + 0x90) != (UInt8 *)0x0 &&
      (self != M<UInt8 *>(newSurface + 0x90))))) {
    M<UInt32>(self + kIOATIR500DVDContext_boundSurface) = 0;
  }
  else {
    currentModeBits[0] = M<unsigned int>(newSurface + 0xbe8);
    if (newSurface != M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface)) {
      ((IOATIR500Surface *)(newSurface))->reset_req_bits();
    }
    if ((M<int>(newSurface + 0x88) == 0) && (M<int>(newSurface + 0x8c) == 0)) {
      currentModeBits[0] = currentModeBits[0] & 0x803f | modeBits & 0xffffbfff;
    }
    else {
      accepted = VCALL(M<int>(self), 0x5ac)(self,currentModeBits,modeBits);
      if (accepted == 0) {
        if (newSurface == M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface)) {
          ((IOATIR500Surface *)(newSurface))->prune_buffers();
        }
        M<UInt32>(self + kIOATIR500DVDContext_boundSurface) = 0;
        result = 0xe00002c2;
        goto LAB_0000fc30;
      }
    }
    M<unsigned int>(newSurface + 0xbe8) = currentModeBits[0];
    if (0 < flagCount) {
      bufferMask = M<unsigned int>(self + kIOATIR500DVDContext_surfaceFlagsBitmask);
      uVar3 = 0;
      do {
        uVar2 = uVar3 & 0x3f;
        uVar3 = uVar3 + 1;
        bufferMask = bufferMask | 0x400 << uVar2;
        flagCount = flagCount + -1;
      } while (flagCount != 0);
      M<unsigned int>(self + kIOATIR500DVDContext_surfaceFlagsBitmask) = bufferMask;
    }
    ((IOATIR500Surface *)(newSurface))->set_dvd_context((IOATIR500DVDContext *)(self));
    M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface) = newSurface;
    ((IOATIR500Surface *)(newSurface))->prune_buffers();
  }
LAB_0000fc30:
  if (self == M<UInt8 *>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x78)) {
    M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x78) = 0;
  }
  VCALL(M<int>(self), 0x5a8)(self);
  GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
  return result;
}
