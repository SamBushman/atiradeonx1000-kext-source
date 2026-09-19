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
bool ATIR500Surface::start(IOService *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  SInt32 iVar1;
  
  GH_IOLockLock(M<UInt32>(param_1 + 0x840));
  iVar1 = IOATIR500Surface::start(real_param_1);
  if (iVar1 != 0) {
    M<UInt16>(self + 0xdb4) = 0;
    self[0xdb7] = 0x0;
    self[0xdb6] = 0x0;
    M<UInt32>(self + 0xd90) = 0;
    M<UInt32>(self + 0xd94) = 0;
    M<UInt32>(self + 0xda4) = 0;
    M<UInt32>(self + 0xda8) = 0;
    M<UInt32>(self + 0xdac) = 0;
    M<UInt32>(self + 0xdb8) = 1;
    GH_IOLockUnlock(M<UInt32>(param_1 + 0x840));
  }
  else {
    GH_IOLockUnlock(M<UInt32>(param_1 + 0x840));
  }
  return iVar1 != 0;
}
