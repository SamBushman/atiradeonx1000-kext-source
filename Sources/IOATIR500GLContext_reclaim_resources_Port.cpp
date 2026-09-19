/*
 * IOATIR500GLContext_reclaim_resources_Port.cpp
 *
 * IOATIR500GLContext::reclaim_resources (real addr 0x83c0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x83c0 */
IOReturn IOATIR500GLContext::reclaim_resources() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *pVVar1;
  UInt32 uVar2;
  UInt8 *this_00;
  SInt32 iVar3;
  UInt8 *pVVar4;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + 200) + 0x840));
  M<UInt32>(M<SInt32>(self + 200) + 0x5c8) = 0x20000;
  M<UInt32>(M<SInt32>(self + 200) + 0x5d8) = 0x10000;
  pVVar4 = M<UInt8 *>(self + 0xe8);
  while (pVVar1 = pVVar4, pVVar1 != (UInt8 *)0x0) {
    this_00 = M<UInt8 *>(self + 200);
    pVVar4 = M<UInt8 *>(pVVar1 + 0x3c);
    if (M<UInt32>(this_00 + 0x5d4) < 0x10) {
      if (M<SInt32>(this_00 + 0x5d0) == 0) {
        M<UInt8 *>(this_00 + 0x5cc) = pVVar1;
        M<UInt8 *>(M<SInt32>(self + 200) + 0x5d0) = pVVar1;
        M<UInt32>(pVVar1 + 0x3c) = 0;
      }
      else {
        M<UInt8 *>(M<SInt32>(this_00 + 0x5d0) + 0x3c) = pVVar1;
        M<UInt8 *>(M<SInt32>(self + 200) + 0x5d0) = pVVar1;
        M<UInt32>(pVVar1 + 0x3c) = 0;
      }
      M<SInt32>(M<SInt32>(self + 200) + 0x5d4) = M<SInt32>(M<SInt32>(self + 200) + 0x5d4) + 1;
      pVVar1[0x54] = 0x0;
      if (M<SInt32 *>(pVVar1 + 0x10) != (SInt32 *)0x0) {
        VCALL(*M<SInt32 *>(pVVar1 + 0x10), 0x18)(M<SInt32 *>(pVVar1 + 0x10));
        M<UInt32>(pVVar1 + 0x10) = 0;
      }
    }
    else {
      ((IOATIR500Accelerator *)(this_00))->freeOneDataBuffer((VendorTextureBuffer *)(pVVar1));
    }
  }
  iVar3 = M<SInt32>(self + 200);
  M<UInt32>(self + 0xf0) = 0;
  M<UInt32>(self + 0xe8) = 0;
  M<UInt32>(self + 0xec) = 0;
  uVar2 = M<UInt32>(iVar3 + 0x5d4);
  while (0xf < uVar2) {
    pVVar4 = M<UInt8 *>(iVar3 + 0x5cc);
    M<UInt32>(iVar3 + 0x5cc) = M<UInt32>(pVVar4 + 0x3c);
    M<SInt32>(M<SInt32>(self + 200) + 0x5d4) = M<SInt32>(M<SInt32>(self + 200) + 0x5d4) + -1;
    ((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->freeOneDataBuffer((VendorTextureBuffer *)(pVVar4));
    iVar3 = M<SInt32>(self + 200);
    uVar2 = M<UInt32>(iVar3 + 0x5d4);
  }
  GH_IOLockUnlock(M<UInt32>(iVar3 + 0x840));
  return 0;
}
