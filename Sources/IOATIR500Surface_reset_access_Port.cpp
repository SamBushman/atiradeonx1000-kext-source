/*
 * IOATIR500Surface_reset_access_Port.cpp
 *
 * IOATIR500Surface::reset_access (real addr 0x10de0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x10de0 */
void IOATIR500Surface::reset_access() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 *descriptor;
  UInt32 mapAddress;
  SInt32 previous;
  
  previous = M<SInt32>(self + kIOATIR500Surface_accessDescriptor);
  VCALL(M<SInt32>(self), 0x604)(self);
  if (previous != M<SInt32>(self + kIOATIR500Surface_accessDescriptor)) {
    if (M<SInt32 *>(self + kIOATIR500Surface_userMap) != (SInt32 *)0x0) {
      VCALL(*M<SInt32 *>(self + kIOATIR500Surface_userMap), 0x18)(M<SInt32 *>(self + kIOATIR500Surface_userMap));
    }
    if (M<SInt32 *>(self + kIOATIR500Surface_kernelMap) != (SInt32 *)0x0) {
      VCALL(*M<SInt32 *>(self + kIOATIR500Surface_kernelMap), 0x18)(M<SInt32 *>(self + kIOATIR500Surface_kernelMap));
    }
    M<UInt32>(self + kIOATIR500Surface_userMapAddress) = 0;
    M<UInt32>(self + kIOATIR500Surface_kernelMapAddress) = 0;
    descriptor = (SInt32 *)VCALL(*M<SInt32 *>(self + kIOATIR500Surface_accessDescriptor), 0x150)(M<SInt32 *>(self + kIOATIR500Surface_accessDescriptor),1);
    M<SInt32 *>(self + kIOATIR500Surface_kernelMap) = descriptor;
    if (descriptor != (SInt32 *)0x0) {
      mapAddress = VCALL(*descriptor, 0xd0)(descriptor);
      M<UInt32>(self + kIOATIR500Surface_kernelMapAddress) = mapAddress;
    }
    if (self[0xbf4] != 0x0) {
      descriptor = (SInt32 *)VCALL(*M<SInt32 *>(self + kIOATIR500Surface_accessDescriptor), 0x14c)
                                (M<SInt32 *>(self + kIOATIR500Surface_accessDescriptor),M<UInt32>(self + kIOATIR500Surface_task),0,1,0,0);
      M<SInt32 *>(self + kIOATIR500Surface_userMap) = descriptor;
      if (descriptor != (SInt32 *)0x0) {
        mapAddress = VCALL(*descriptor, 0xd0)(descriptor);
        M<UInt32>(self + kIOATIR500Surface_userMapAddress) = mapAddress;
      }
    }
  }
  return;
}
