/*
 * ATIR500Surface_start_Port.cpp
 *
 * ATIR500Surface::start (real addr 0x3d3f0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x3d3f0 */
bool ATIR500Surface::start(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *providerBytes = reinterpret_cast<UInt8 *>(provider);

  SInt32 started;
  
  GH_IOLockLock(M<UInt32>(providerBytes + 0x840));
  started = IOATIR500Surface::start(provider);
  if (started != 0) {
    M<UInt16>(self + kATIR500Surface_swapBatchBuilt) = 0;
    self[0xdb7] = 0x0;
    self[0xdb6] = 0x0;
    M<UInt32>(self + kATIR500Surface_currentBufferIndex) = 0;
    M<UInt32>(self + kATIR500Surface_overlayHandle) = 0;
    M<UInt32>(self + kATIR500Surface_overlayExists) = 0;
    M<UInt32>(self + kATIR500Surface_unknown_0xda8) = 0;
    M<UInt32>(self + kATIR500Surface_deintMode) = 0;
    M<UInt32>(self + kATIR500Surface_panelSide) = 1;
    GH_IOLockUnlock(M<UInt32>(providerBytes + 0x840));
  }
  else {
    GH_IOLockUnlock(M<UInt32>(providerBytes + 0x840));
  }
  return started != 0;
}
