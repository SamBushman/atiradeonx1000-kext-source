/*
 * IOATIR500Surface_set_scaling_Port.cpp
 *
 * IOATIR500Surface::set_scaling (real addr 0x11640, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x11640 */
IOReturn IOATIR500Surface::set_scaling(UInt32 flags, IOAccelSurfaceScaling *scaling) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *scalingBytes = reinterpret_cast<UInt8 *>(scaling);

  bool scalingDisabled;
  UInt16 width;
  UInt16 height;
  UInt32 result;
  SInt32 iVar5;
  UInt32 local_28;
  UInt32 local_24;
  UInt32 local_20;
  UInt32 local_1c;
  
  scalingDisabled = (flags >> 1 & 1) == 0;
  if ((scalingDisabled) || (scalingBytes != (UInt8 *)0x0)) {
    self[0xbee] = ((UInt8)flags & 1);
    self[0xbf1] = ((UInt8)flags & 0xf0);
    self[0xbed] = SUB41m(-(M<UInt32>(self + kIOATIR500Surface_scalingState) & 0xffff00) >> 0x1f,0);
    if (scalingDisabled) {
      self[0xbec] = 0x0;
      width = M<UInt16>(M<SInt32>(self + kIOATIR500Surface_regionRecords) + 8);
      M<UInt16>(self + kIOATIR500Surface_width) = width;
      height = M<UInt16>(M<SInt32>(self + kIOATIR500Surface_regionRecords) + 10);
      M<UInt16>(self + kIOATIR500Surface_scalingBufferX) = 0;
      M<UInt16>(self + kIOATIR500Surface_scalingBufferY) = 0;
      M<UInt16>(self + kIOATIR500Surface_scalingSourceWidth) = width;
      M<UInt16>(self + kIOATIR500Surface_scalingSourceHeight) = height;
      M<UInt16>(self + kIOATIR500Surface_height) = height;
    }
    else if ((M<UInt32>(self + kIOATIR500Surface_modeBits) & 0x20) != 0) {
      self[0xbec] = 0x1;
      M<UInt16>(self + kIOATIR500Surface_width) = M<UInt16>(scalingBytes + 4);
      M<UInt16>(self + kIOATIR500Surface_height) = M<UInt16>(scalingBytes + 6);
      M<UInt16>(self + kIOATIR500Surface_scalingBufferX) = M<UInt16>(scalingBytes);
      M<UInt16>(self + kIOATIR500Surface_scalingBufferY) = M<UInt16>(scalingBytes + 2);
      M<UInt16>(self + kIOATIR500Surface_scalingSourceWidth) = M<UInt16>(scalingBytes + 8);
      M<UInt16>(self + kIOATIR500Surface_scalingSourceHeight) = M<UInt16>(scalingBytes + 10);
    }
    M<UInt16>(self + kIOATIR500Surface_committedHeight) = M<UInt16>(self + kIOATIR500Surface_height);
    M<UInt16>(self + kIOATIR500Surface_committedWidth) = M<UInt16>(self + kIOATIR500Surface_width);
    VCALL(M<SInt32>(self), 0x5c8)(self);
    this->update_contexts();
    M<UInt32>(self + kIOATIR500Surface_stateBits) = M<UInt32>(self + kIOATIR500Surface_stateBits) & 0xdfffffff;
    iVar5 = VCALL(M<SInt32>(self), 0x5b0)
                      (self,(SInt32)M<SInt16>(self + kIOATIR500Surface_width),(SInt32)M<SInt16>(self + kIOATIR500Surface_height));
    if (iVar5 != 0) {
      local_1c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      iVar5 = VCALL(*M<SInt32 *>(self + kIOATIR500Surface_accelerator), 0x540)
                        (M<SInt32 *>(self + kIOATIR500Surface_accelerator),&local_28,
                         M<UInt32>(M<SInt32>(self + kIOATIR500Surface_attachmentBuffers) + 0x10),0x1000);
      if (iVar5 != 0) {
        VCALL(*M<SInt32 *>(self + kIOATIR500Surface_accelerator), 0x544)(M<SInt32 *>(self + kIOATIR500Surface_accelerator),&local_28);
        return 0;
      }
    }
    result = 0xe00002be;
    M<UInt32>(self + kIOATIR500Surface_stateBits) = M<UInt32>(self + kIOATIR500Surface_stateBits) | 0x20000000;
  }
  else {
    result = 0xe00002c2;
  }
  return result;
}
