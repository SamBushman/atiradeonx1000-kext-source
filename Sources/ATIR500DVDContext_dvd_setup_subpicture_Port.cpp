/*
 * ATIR500DVDContext_dvd_setup_subpicture_Port.cpp
 *
 * ATIR500DVDContext::dvd_setup_subpicture (real addr 0x34e50, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x34e50 */
IOReturn ATIR500DVDContext::dvd_setup_subpicture(int unknownArg1, int unknownArg2, int unknownArg3, int unknownArg4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(this);

  int accel;
  UInt32 result;
  
  GH_IOLockLock(M<UInt32>(M<int>(self + 0x8c) + 0x840));
  accel = M<int>(self + 0x8c);
  if (M<char>(accel + 0x80) == '\0') {
    result = 0xe00002d8;
  }
  else if (M<int>(self + 0xf8) == 0) {
    result = 0xe00002bc;
  }
  else {
    result = 0;
    ((ATIR500Surface *)(M<int>(self + 0xf8)))->dvd_setup_subpicture(unknownArg1, unknownArg2, unknownArg3, unknownArg4);   /* r7 (the 4th explicit argument) is passed on untouched */
    accel = M<int>(self + 0x8c);
  }
  GH_IOLockUnlock(M<UInt32>(accel + 0x840));
  return result;
}
