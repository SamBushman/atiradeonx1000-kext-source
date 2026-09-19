/*
 * IOATIR500GLContext_become_global_shared_Port.cpp
 *
 * IOATIR500GLContext::become_global_shared (real addr 0x9640, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x9640 */
IOReturn IOATIR500GLContext::become_global_shared(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  SInt32 iVar2;
  UInt32 uVar3;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + 200) + 0x840));
  if (param_1 == 0) {
    iVar1 = M<SInt32>(self + 200);
    iVar2 = M<SInt32>(iVar1 + 0x6c);
    if (((iVar2 != 0) && (iVar2 == M<SInt32>(self + 0x88))) && (M<SInt32>(iVar2 + 0x24) == 0)) {
      M<UInt32>(iVar1 + 0x6c) = 0;
      M<UInt32>(M<SInt32>(self + 200) + 0x70) = 0;
      iVar1 = M<SInt32>(self + 200);
      uVar3 = 0;
      goto LAB_000096f8;
    }
  }
  else {
    iVar1 = M<SInt32>(self + 200);
    if ((M<SInt32>(iVar1 + 0x6c) == 0) && (M<SInt32>(M<SInt32>(self + 0x88) + 0x24) == 0)) {
      M<SInt32>(iVar1 + 0x6c) = M<SInt32>(self + 0x88);
      uVar3 = 0;
      M<UInt32>(M<SInt32>(self + 200) + 0x70) = 1;
      iVar1 = M<SInt32>(self + 200);
      goto LAB_000096f8;
    }
  }
  uVar3 = 0xe00002cc;
LAB_000096f8:
  GH_IOLockUnlock(M<UInt32>(iVar1 + 0x840));
  return uVar3;
}
