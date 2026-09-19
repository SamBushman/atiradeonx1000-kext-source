/*
 * ATIR5002DContext_write_2_regs_Port.cpp
 *
 * ATIR5002DContext::write_2_regs (real addr 0x325d0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x325d0 */
IOReturn ATIR5002DContext::write_2_regs(UInt32 param_1, UInt32 param_2, UInt32*param_3, UInt32 param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  SInt32 iVar2;
  UInt32 uVar3;
  SInt32 iVar4;
  UInt32 uVar5;
  
  iVar4 = M<SInt32>(M<SInt32>(self + 0x94) + 0x860);
  if ((param_4 & 7) == 0) {
    GH_IOLockLock(M<UInt32>(M<SInt32>(self + 0x94) + 0x840));
    iVar2 = M<SInt32>(self + 0x94);
    if (M<char>(iVar2 + 0x80) == '\0') {
      uVar5 = 0xe00002d8;
    }
    else {
      if (param_4 >> 3 != 0) {
        uVar3 = 0;
        do {
          uVar1 = *param_3;
          M<UInt32>(iVar4 + (param_1 & 0x1ffc)) =
               uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 | uVar1 >> 0x18;
          uVar1 = param_3[1];
          M<UInt32>(iVar4 + (param_2 & 0x1ffc)) =
               uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 | uVar1 >> 0x18;
          uVar3 = uVar3 + 2;
          param_3 = param_3 + 2;
        } while (uVar3 < param_4 >> 3);
      }
      uVar5 = 0;
    }
    GH_IOLockUnlock(M<UInt32>(iVar2 + 0x840));
  }
  else {
    uVar5 = 0xe00002c2;
  }
  return uVar5;
}
