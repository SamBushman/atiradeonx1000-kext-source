/*
 * IOATIR500GLContext_set_surface_Port.cpp
 *
 * IOATIR500GLContext::set_surface (real addr 0x87b0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x87b0 */
IOReturn IOATIR500GLContext::set_surface(UInt32 surfaceID, eIOGLContextModeBits modeBits, UInt32 unknown_0x298, UInt32 mipLevel) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool detach;
  int compatible;
  unsigned int surfaceBits;
  UInt32 result;
  UInt8 *surface;
  unsigned int contextBits;
  unsigned int surfaceModeBits [7];
  
  GH_IOLockLock(M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x840));
  if (surfaceID == 0) {
    result = 0;
    surface = (UInt8 *)0x0;
    detach = true;
  }
  else {
    surface = (UInt8 *)
              ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->find_surface_for_id(surfaceID);
    detach = surface == (UInt8 *)0x0;
    if (detach) {
      result = 0xe00002c2;
    }
    else {
      result = 0;
    }
  }
  if (M<UInt8 *>(self + kIOATIR500GLContext_boundSurface) != (UInt8 *)0x0) {
    ((IOATIR500Surface *)(M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)))->remove_gl_context_from_list((IOATIR500GLContext *)(self));
    if (surface != M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)) {
      ((IOATIR500Surface *)(M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)))->prune_buffers();
    }
  }
  if (detach) {
    M<UInt8 *>(self + kIOATIR500GLContext_mipLevel) = surface;
    M<UInt8 *>(self + kIOATIR500GLContext_boundSurface) = surface;
    M<UInt8 *>(self + kIOATIR500GLContext_surfaceIndex) = surface;
  }
  else {
    surfaceModeBits[0] = M<unsigned int>(surface + 0xbe8);
    if (surface != M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)) {
      ((IOATIR500Surface *)(surface))->reset_req_bits();
    }
    if (((M<int>(surface + 0x90) == 0) && (M<int>(surface + 0x8c) == 0)) &&
       ((M<UInt8 *>(surface + 0x88) == (UInt8 *)0x0 ||
        ((self == M<UInt8 *>(surface + 0x88) && (M<int>(self + kIOATIR500GLContext_nextContext) == 0)))))) {
      surfaceModeBits[0] = surfaceModeBits[0] & 0x803f | modeBits & 0xffffc03f;
    }
    else if ((((M<unsigned int>(surface + 0xc18) & 4) != 0) &&
             (((modeBits & 0x300) != 0 &&
              ((M<unsigned int>(surface + 0xc18) >> 7 & 1) != (modeBits >> 0xd & 1))))) ||
            (compatible = VCALL(M<int>(self), 0x5ac)(self,surfaceModeBits,modeBits), compatible == 0)) {
      if (surface == M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)) {
        ((IOATIR500Surface *)(surface))->prune_buffers();
      }
      M<UInt32>(self + kIOATIR500GLContext_boundSurface) = 0;
      result = 0xe00002c2;
      goto LAB_00008ad0;
    }
    M<unsigned int>(surface + 0xbe8) = surfaceModeBits[0];
    M<UInt32>(self + kIOATIR500GLContext_surfaceFlagsBitmask) = 0x20000000;
    if ((modeBits & 0x400) != 0) {
      M<UInt32>(self + kIOATIR500GLContext_surfaceFlagsBitmask) = 0x20000002;
    }
    if ((modeBits & 0x800) == 0) {
      contextBits = M<unsigned int>(self + kIOATIR500GLContext_surfaceFlagsBitmask);
    }
    else {
      contextBits = M<unsigned int>(self + kIOATIR500GLContext_surfaceFlagsBitmask) | 1;
      M<unsigned int>(self + kIOATIR500GLContext_surfaceFlagsBitmask) = contextBits;
    }
    if ((M<unsigned int>(surface + 0xbe8) & 0x10) != 0) {
      if ((contextBits & 1) != 0) {
        contextBits = contextBits | 0x20;
        M<unsigned int>(self + kIOATIR500GLContext_surfaceFlagsBitmask) = contextBits;
      }
      if ((contextBits & 2) != 0) {
        contextBits = contextBits | 0x10;
        M<unsigned int>(self + kIOATIR500GLContext_surfaceFlagsBitmask) = contextBits;
      }
    }
    surfaceBits = VCALL(M<int>(surface), 0x5ac)(surface);
    M<unsigned int>(self + kIOATIR500GLContext_surfaceFlagsBitmask) = contextBits | surfaceBits;
    if ((modeBits & 0x40) != 0) {
      M<unsigned int>(self + kIOATIR500GLContext_surfaceFlagsBitmask) = contextBits | surfaceBits | 0x40;
    }
    if ((modeBits & 0x1000) != 0) {
      M<unsigned int>(self + kIOATIR500GLContext_surfaceFlagsBitmask) = M<unsigned int>(self + kIOATIR500GLContext_surfaceFlagsBitmask) | 0x200;
    }
    if (0xff < (modeBits & 0x300)) {
      detach = (modeBits & 0x2000) != 0;
      contextBits = M<unsigned int>(self + kIOATIR500GLContext_surfaceFlagsBitmask);
      M<unsigned int>(self + kIOATIR500GLContext_surfaceFlagsBitmask) = contextBits | 4;
      if (detach) {
        M<unsigned int>(self + kIOATIR500GLContext_surfaceFlagsBitmask) = contextBits | 0x84;
      }
      if (0x1ff < (modeBits & 0x300)) {
        contextBits = M<unsigned int>(self + kIOATIR500GLContext_surfaceFlagsBitmask);
        M<unsigned int>(self + kIOATIR500GLContext_surfaceFlagsBitmask) = contextBits | 8;
        if (detach) {
          M<unsigned int>(self + kIOATIR500GLContext_surfaceFlagsBitmask) = contextBits | 0x108;
        }
      }
    }
    VCALL(M<int>(self), 0x5bc)(self,modeBits);
    ((IOATIR500Surface *)(surface))->add_gl_context_to_list((IOATIR500GLContext *)(self));
    M<UInt8 *>(self + kIOATIR500GLContext_boundSurface) = surface;
    ((IOATIR500Surface *)(surface))->prune_buffers();
  }
LAB_00008ad0:
  if (self == M<UInt8 *>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x78)) {
    M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x78) = 0;
  }
  M<UInt32>(self + kIOATIR500GLContext_surfaceIndex) = unknown_0x298;
  M<UInt32>(self + kIOATIR500GLContext_mipLevel) = mipLevel;
  VCALL(M<int>(self), 0x5a8)(self);
  GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x840));
  return result;
}
