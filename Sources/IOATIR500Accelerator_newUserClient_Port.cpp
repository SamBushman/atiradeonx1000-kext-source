/*
 * IOATIR500Accelerator_newUserClient_Port.cpp
 *
 * IOATIR500Accelerator::newUserClient (real addr 0x2070, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" void *g_kOSBooleanTrue asm("_kOSBooleanTrue");

extern "C" UInt32 GH_ZN12OSDictionary12withCapacityEj(...) asm("__ZN12OSDictionary12withCapacityEj");


/* real addr 0x2070 */
IOReturn IOATIR500Accelerator::newUserClient(task *real_param_1, void*param_2, UInt32 param_3, IOUserClient**param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  code *pcVar1;
  UInt8 *pIVar2;
  SInt32 iVar3;
  SInt32 *piVar4;
  UInt8 bVar5;
  
  *param_4 = (IOUserClient *)0x0;
  if (param_3 == 1) {
    pcVar1 = M<code *>(M<SInt32>(self) + 0x5e0);
  }
  else {
    if (param_3 == 0) {
      piVar4 = (SInt32 *)GH_ZN12OSDictionary12withCapacityEj(1);
      bVar5 = (piVar4 == (SInt32 *)0x0) << 1;
      if (piVar4 == (SInt32 *)0x0) {
        return 0xe00002be;
      }
      VCALL(*piVar4, 300)(piVar4,"IOUserClientCrossEndianCompatible",(UInt32)g_kOSBooleanTrue);
      pIVar2 = (UInt8 *)VCALL(M<SInt32>(self), 0x5d4)(self);
      if (pIVar2 == (UInt8 *)0x0) {
        VCALL(*piVar4, 0x18)(piVar4);
        return 0xe00002be;
      }
      M<task *>(pIVar2 + 0x78) = real_param_1;
      goto LAB_000021d0;
    }
    if (param_3 != 2) {
      if (param_3 != 3) {
        return 0xe00002c2;
      }
      pIVar2 = (UInt8 *)VCALL(M<SInt32>(self), 0x5dc)(self);
      if (pIVar2 == (UInt8 *)0x0) {
        return 0xe00002be;
      }
      M<task *>(pIVar2 + 0x78) = real_param_1;
      piVar4 = (SInt32 *)0x0;
      bVar5 = 2;
      goto LAB_000021d0;
    }
    pcVar1 = M<code *>(M<SInt32>(self) + 0x5d8);
  }
  /* #153 root cause: real disassembly (addr 0x2070; GL/2D branches at 0x2160/0x2170) confirms this
   * call explicitly loads only r2 (the vtable, to fetch the function pointer) - r3 (self/"this")
   * is never clobbered since function entry, so it is still self's value when the real compiled
   * code's bctrl executes. The naive 0-argument transcription dropped that implicit first
   * argument entirely; our own compiler has no reason to leave self in r3 for a call that
   * references no arguments at all in the C++ source. This is the actual cause of #153's
   * deterministic, build-independent crash: newUserClient is the very first thing called when
   * opening a GL (param_3==1) or 2D (param_3==2) user client, which is why the crash recurred
   * identically regardless of any GART/texture-buffer fix tried earlier. */
  pIVar2 = (UInt8 *)(*pcVar1)(self);
  if (pIVar2 == (UInt8 *)0x0) {
    return 0xe00002be;
  }
  piVar4 = (SInt32 *)0x0;
  M<task *>(pIVar2 + 0x78) = real_param_1;
  bVar5 = 2;
LAB_000021d0:
  iVar3 = VCALL(M<SInt32>(pIVar2), 0x150)(pIVar2,piVar4);
  if ((iVar3 != 0) && (iVar3 = VCALL(M<SInt32>(pIVar2), 0x3a4)(pIVar2,self), iVar3 != 0)) {
    iVar3 = VCALL(M<SInt32>(pIVar2), 0x348)(pIVar2,self);
    if (iVar3 != 0) {
      *param_4 = (IOUserClient *)pIVar2;
      if (!(bool)(bVar5 >> 1 & 1)) {
        VCALL(*piVar4, 0x18)(piVar4);
      }
      return 0;
    }
    VCALL(M<SInt32>(pIVar2), 0x3a8)(pIVar2,self);
  }
  VCALL(M<SInt32>(pIVar2), 0x18)(pIVar2);
  if (!(bool)(bVar5 >> 1 & 1)) {
    VCALL(*piVar4, 0x18)(piVar4);
  }
  return 0xe00002c9;
}
