/*
 * ATIR500DVDContext_dvd_enable_overlay_Port.cpp
 *
 * ATIR500DVDContext::dvd_enable_overlay (real addr 0x34f30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x34f30 */
IOReturn ATIR500DVDContext::dvd_enable_overlay(int enable) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 accel;
  UInt32 result;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x840));
  accel = M<SInt32>(self + kIOATIR500DVDContext_accelerator);
  if (M<char>(accel + 0x80) == '\0') {
    result = 0xe00002d8;
  }
  else if (M<SInt32>(self + kIOATIR500DVDContext_boundSurface) == 0) {
    result = 0xe00002bc;
  }
  else if (enable == 0) {
    ((ATIR500Surface *)(M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface)))->disable_overlay();
    accel = M<SInt32>(self + kIOATIR500DVDContext_accelerator);
    result = 0;
  }
  else {
    ((ATIR500Surface *)(M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface)))->enable_overlay();
    accel = M<SInt32>(self + kIOATIR500DVDContext_accelerator);
    result = 0;
  }
  GH_IOLockUnlock(M<UInt32>(accel + 0x840));
  return result;
}
