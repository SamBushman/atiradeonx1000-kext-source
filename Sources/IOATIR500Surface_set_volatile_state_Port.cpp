/*
 * IOATIR500Surface_set_volatile_state_Port.cpp
 *
 * IOATIR500Surface::set_volatile_state (real addr 0x15b70, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x15b70 */
void IOATIR500Surface::set_volatile_state(eSurfaceVolatileState param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  int iVar1;
  int iVar2;
  int iVar3;
  
  GH_IOLockLock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
  M<int>(self + 0xd48) = param_2;
  if (param_2 == 1) {
    iVar2 = M<int>(self + 0xd50);
    if (self != M<UInt8 *>(iVar2 + 0x5c)) {
      iVar3 = M<int>(self + 0x9c);
      M<UInt32>(iVar3 + 0xa0) = M<UInt32>(self + 0xa0);
      M<int>(M<int>(self + 0xa0) + 0x9c) = iVar3;
      iVar1 = M<int>(iVar2 + 0x5c);
      iVar3 = M<int>(iVar1 + 0xa0);
      M<int>(self + 0x9c) = iVar1;
      M<int>(self + 0xa0) = iVar3;
      M<UInt8 *>(iVar3 + 0x9c) = self;
      M<UInt8 *>(iVar1 + 0xa0) = self;
      M<UInt8 *>(iVar2 + 0x5c) = self;
      iVar2 = M<int>(self + 0xd50);
    }
    M<int>(iVar2 + 0x21c) = M<int>(iVar2 + 0x21c) + 1;
    iVar2 = M<int>(self + 0xd50);
  }
  else {
    iVar2 = M<int>(self + 0xd50);
    if (self != M<UInt8 *>(iVar2 + 0x5c)) {
      iVar3 = M<int>(self + 0x9c);
      M<UInt32>(iVar3 + 0xa0) = M<UInt32>(self + 0xa0);
      M<int>(M<int>(self + 0xa0) + 0x9c) = iVar3;
      iVar1 = M<int>(iVar2 + 0x5c);
      iVar3 = M<int>(iVar1 + 0xa0);
      M<int>(self + 0x9c) = iVar1;
      M<int>(self + 0xa0) = iVar3;
      M<UInt8 *>(iVar3 + 0x9c) = self;
      M<UInt8 *>(iVar1 + 0xa0) = self;
      M<UInt8 *>(iVar2 + 0x5c) = self;
      M<UInt32>(M<int>(self + 0xd50) + 0x5c) = M<UInt32>(self + 0x9c);
      iVar2 = M<int>(self + 0xd50);
    }
    if (M<int>(iVar2 + 0x21c) != 0) {
      M<int>(iVar2 + 0x21c) = M<int>(iVar2 + 0x21c) + -1;
      iVar2 = M<int>(self + 0xd50);
    }
  }
  GH_IOLockUnlock(M<UInt32>(iVar2 + 0x840));
  return;
}
