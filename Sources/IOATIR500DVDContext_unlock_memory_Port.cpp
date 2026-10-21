/*
 * IOATIR500DVDContext_unlock_memory_Port.cpp
 *
 * IOATIR500DVDContext::unlock_memory (real addr 0xff20, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0xff20 */
IOReturn IOATIR500DVDContext::unlock_memory(UInt32 lockType, UInt32*outTag) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 surface;
  SInt32 result;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x840));
  surface = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
  if (surface == 0) {
    result = -0x1ffffd3e;
  }
  else {
    result = 0;
    storeHalf(&M<UInt16>(surface + kIOATIR500Surface_memoryLockCount), M<SInt16>(surface + kIOATIR500Surface_memoryLockCount) + -1);
  }
  GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x840));
  if ((result == 0) && ((SInt32)lockType < 0)) {
    *outTag = 0;
  }
  else {
    *outTag = 0;
  }
  return result;
}
