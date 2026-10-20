/*
 * ATIR500GLContext_update_surface_Port.cpp
 *
 * ATIR500GLContext::update_surface (real addr 0x27fd0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x27fd0 */
void ATIR500GLContext::update_surface() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 unitIndex;
  UInt32 surfaceFlags;
  bool attachmentEligible;
  
  if (M<SInt32>(self + kIOATIR500GLContext_boundSurface) != 0) {
    unitIndex = M<SInt32>(self + kATIR500GLContext_renderBufferIndex);
    surfaceFlags = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xbe8);
    if ((unitIndex == 1) || ((unitIndex == 0 && ((surfaceFlags & 0x400) == 0)))) {
      attachmentEligible = true;
    }
    else {
      attachmentEligible = false;
    }
    if (((surfaceFlags & 0x7c0000) == 0) || (!attachmentEligible)) {
      M<SInt16>(self + kATIR500GLContext_attachmentBufferIds) = (SInt16)unitIndex;
      M<SInt16>(self + kIOATIR500GLContext_colorBufferIndex) = (SInt16)unitIndex;
    }
    else {
      M<UInt16>(self + kATIR500GLContext_attachmentBufferIds) = 9;
      M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) = 9;
    }
    this->build_scissor();
  }
  VCALL(M<SInt32>(self), 0x5a4)(self);
  M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x78) = 0;
  return;
}
