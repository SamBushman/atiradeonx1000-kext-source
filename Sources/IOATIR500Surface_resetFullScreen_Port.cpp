/*
 * IOATIR500Surface_resetFullScreen_Port.cpp
 *
 * IOATIR500Surface::resetFullScreen (real addr 0x139d0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x139d0 */
void IOATIR500Surface::resetFullScreen() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 flipAllowed;
  
  if (M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffers) == self + kIOATIR500Surface_buffer1) {
    M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffer1) = M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffers);
    M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffer4) = self + kIOATIR500Surface_buffer4;
    M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffer5) = self + kIOATIR500Surface_buffer5;
    M<SInt32>(self + kIOATIR500Surface_attachmentBuffers) = M<SInt32>(self + kIOATIR500Surface_panel) * 0x78 + M<SInt32>(self + kIOATIR500Surface_accelerator) + 300;
  }
  flipAllowed = VCALL(M<SInt32>(self), 0x5dc)(self);
  if (flipAllowed != 0) {
    if ((1 << (M<UInt32>(self + kIOATIR500Surface_panel) & 0x3f) & M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0xd0)) != 0) {
      VCALL(M<SInt32>(self), 0x5e0)(self,M<UInt32>(self + kIOATIR500Surface_panel),0,1);
      M<SInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x74c) = M<SInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x74c) + 1;
    }
  }
  return;
}
