/*
 * IOATIR500Surface_surface_flush_Port.cpp
 *
 * IOATIR500Surface::surface_flush (real addr 0x14e70, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x14e70 */
IOReturn IOATIR500Surface::surface_flush(UInt32 param_1, UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  SInt32 iVar2;
  SInt32 *piVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + 0xd50) + 0x840));
  iVar1 = this->alloc_surfaces_retry(M<UInt32>(self + 0xc1c) & 3,(eLockType)(0));
  if (iVar1 == 0) {
    this->flush_surface(param_1,param_2);
  }
  uVar4 = M<UInt32>(self + 0x84);
  GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 0xd50) + 0x840));
  piVar3 = M<SInt32 *>(self + 0xd50);
  iVar5 = piVar3[0x1e6];
  iVar2 = VCALL(*piVar3, 0x54c)(piVar3,uVar4);
  piVar3[0x1e6] = iVar5 + iVar2;
  return iVar1;
}
