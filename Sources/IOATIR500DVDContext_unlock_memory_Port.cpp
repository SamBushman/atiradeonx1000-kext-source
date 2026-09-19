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
IOReturn IOATIR500DVDContext::unlock_memory(UInt32 param_1, UInt32*param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  SInt32 iVar2;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + 0x8c) + 0x840));
  iVar1 = M<SInt32>(self + 0xf8);
  if (iVar1 == 0) {
    iVar2 = -0x1ffffd3e;
  }
  else {
    iVar2 = 0;
    M<SInt16>(iVar1 + 0xbd2) = M<SInt16>(iVar1 + 0xbd2) + -1;
  }
  GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 0x8c) + 0x840));
  if ((iVar2 == 0) && ((SInt32)param_1 < 0)) {
    *param_2 = 0;
  }
  else {
    *param_2 = 0;
  }
  return iVar2;
}
