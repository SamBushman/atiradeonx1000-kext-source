/*
 * IOATIR5002DContext_scale_surface_Port.cpp
 *
 * IOATIR5002DContext::scale_surface (real addr 0xcb90, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0xcb90 */
IOReturn IOATIR5002DContext::scale_surface(UInt32 param_1, UInt32 param_2, UInt32 param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  UInt16 local_48;
  UInt16 local_46;
  UInt16 local_44;
  UInt16 local_42;
  UInt16 local_40;
  UInt16 local_3e;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + 0x94) + 0x840));
  if ((M<UInt8 *>(self + 0x100) == (UInt8 *)0x0) || ((param_1 & 1) == 0)) {
    uVar1 = 0xe00002c7;
  }
  else {
    local_44 = (UInt16)param_2;
    local_42 = (UInt16)param_3;
    local_46 = 0;
    local_48 = 0;
    local_40 = local_44;
    local_3e = local_42;
    uVar1 = ((IOATIR500Surface *)(M<UInt8 *>(self + 0x100)))->set_scaling(param_1 >> 2 & 1 | param_1 & 2,
                       (IOAccelSurfaceScaling *)&local_48);
  }
  GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 0x94) + 0x840));
  return uVar1;
}
