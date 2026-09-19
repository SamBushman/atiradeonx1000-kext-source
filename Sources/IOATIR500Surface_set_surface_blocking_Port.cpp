/*
 * IOATIR500Surface_set_surface_blocking_Port.cpp
 *
 * IOATIR500Surface::set_surface_blocking (real addr 0x15ac0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 GH_IOLockWakeup(...) asm("_IOLockWakeup");


/* real addr 0x15ac0 */
IOReturn IOATIR500Surface::set_surface_blocking(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  GH_IOLockLock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
  GH_IOLockLock(M<UInt32>(self + 0xc04));
  self[0xbf6] = (param_1 != 0);
  if (param_1 == 0) {
    GH_IOLockWakeup(M<UInt32>(self + 0xc04),self,0);
  }
  GH_IOLockUnlock(M<UInt32>(self + 0xc04));
  GH_IOLockUnlock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
  return 0;
}
