/*
 * IOATIR500GLContext_set_stereo_Port.cpp
 *
 * IOATIR500GLContext::set_stereo (real addr 0x99a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x99a0 */
IOReturn IOATIR500GLContext::set_stereo(UInt32 param_1, UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + 200) + 0x840));
  uVar1 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->setup_stereo(param_2, param_1)
  ;
  GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 200) + 0x840));
  return uVar1;
}
