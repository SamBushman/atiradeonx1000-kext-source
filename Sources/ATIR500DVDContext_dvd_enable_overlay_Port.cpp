/*
 * ATIR500DVDContext_dvd_enable_overlay_Port.cpp
 *
 * ATIR500DVDContext::dvd_enable_overlay (real addr 0x34f30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x34f30 */
IOReturn ATIR500DVDContext::dvd_enable_overlay(int param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt32 uVar2;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + 0x8c) + 0x840));
  iVar1 = M<SInt32>(self + 0x8c);
  if (M<char>(iVar1 + 0x80) == '\0') {
    uVar2 = 0xe00002d8;
  }
  else if (M<SInt32>(self + 0xf8) == 0) {
    uVar2 = 0xe00002bc;
  }
  else if (param_1 == 0) {
    ((ATIR500Surface *)(M<UInt8 *>(self + 0xf8)))->disable_overlay();
    iVar1 = M<SInt32>(self + 0x8c);
    uVar2 = 0;
  }
  else {
    ((ATIR500Surface *)(M<UInt8 *>(self + 0xf8)))->enable_overlay();
    iVar1 = M<SInt32>(self + 0x8c);
    uVar2 = 0;
  }
  GH_IOLockUnlock(M<UInt32>(iVar1 + 0x840));
  return uVar2;
}
