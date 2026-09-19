/*
 * IOATIR500GLContext_purge_texture_Port.cpp
 *
 * IOATIR500GLContext::purge_texture (real addr 0x9840, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x9840 */
IOReturn IOATIR500GLContext::purge_texture(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + 200) + 0x840));
  if ((param_1 < M<UInt32>(M<SInt32>(self + 0x88) + 0x14)) &&
     (iVar1 = M<SInt32>(param_1 * 4 + M<SInt32>(M<SInt32>(self + 0x88) + 0x10)), iVar1 != 0)) {
    if (M<SInt32>(iVar1 + 0x48) != 0) {
      VCALL(*M<SInt32 *>(self + 200), 0x524)(M<SInt32 *>(self + 200));
      M<UInt8>(M<SInt32>(iVar1 + 0x14) + 0x14) = 1;
      M<UInt16>(M<SInt32>(iVar1 + 0x14) + 0x28) = 0;
      M<UInt16>(M<SInt32>(iVar1 + 0x14) + 0x2a) = 0;
      M<UInt16>(M<SInt32>(iVar1 + 0x14) + 0x2c) = 0;
      M<UInt16>(M<SInt32>(iVar1 + 0x14) + 0x2e) = 0;
      M<UInt16>(M<SInt32>(iVar1 + 0x14) + 0x30) = 0;
      M<UInt16>(M<SInt32>(iVar1 + 0x14) + 0x32) = 0;
    }
    M<UInt32>(M<SInt32>(iVar1 + 0x24) + 0x28) = M<UInt32>(iVar1 + 0x28);
    M<UInt32>(M<SInt32>(iVar1 + 0x28) + 0x24) = M<UInt32>(iVar1 + 0x24);
    M<SInt32>(iVar1 + 0x24) = iVar1;
    M<SInt32>(iVar1 + 0x28) = iVar1;
    GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 200) + 0x840));
    return 0;
  }
  GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 200) + 0x840));
  return 0xe00002c2;
}
