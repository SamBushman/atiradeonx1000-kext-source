/*
 * IOATIR500Surface_surface_unlock_options_Port.cpp
 *
 * IOATIR500Surface::surface_unlock_options (real addr 0x14f60, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x14f60 */
IOReturn IOATIR500Surface::surface_unlock_options(eLockType param_2, UInt32 param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(this);

  UInt8 IVar1;
  int *piVar2;
  UInt8 *pIVar3;
  UInt32 uVar4;
  int iVar5;
  
  pIVar3 = self + 0xbd0;
  if (param_2 != 1) {
    pIVar3 = self + 0xbd1;
  }
  GH_IOLockLock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
  IVar1 = *pIVar3;
  if (IVar1 == 0x0) {
    uVar4 = 0xe00002cc;
  }
  else {
    iVar5 = M<int>(self + 0xb70);
    if (IVar1 == 0x3) {
      if (M<int>(self + 0xd8c) == 0) {
        if ((M<int>(iVar5 + 0x24) != 0) &&
           (piVar2 = M<int *>(M<int>(iVar5 + 0x24) + 0x10), piVar2 != (int *)0x0)) {
          VCALL(*piVar2, 0x18)(piVar2);
          M<UInt32>(M<int>(iVar5 + 0x24) + 0x10) = 0;
        }
      }
      else {
        this->free_buffer_backing_orphans();
      }
    }
    else if ((IVar1 == 0x1) && (M<int>(iVar5 + 8) != 0)) {
      VCALL(M<int>(self), 0x600)(self,iVar5);
    }
    uVar4 = 0;
    *pIVar3 = 0x0;
  }
  GH_IOLockUnlock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
  return uVar4;
}
