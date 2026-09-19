/*
 * ATIR500DVDContext_set_macrovision_Port.cpp
 *
 * ATIR500DVDContext::set_macrovision (real addr 0x35010, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(...) asm("__ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass");


/* real addr 0x35010 */
IOReturn ATIR500DVDContext::set_macrovision(UInt32 param_1, UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  SInt32 *piVar2;
  UInt32 uVar3;
  UInt32 stack0x00000020; /* the shipped code spills its (undeclared) 3rd register argument here and passes the slot's address on */
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(param_1 + 0x8c) + 0x840));
  iVar1 = M<SInt32>(param_1 + 0x8c);
  if (M<char>(iVar1 + 0x80) == '\0') {
    uVar3 = 0xe00002d8;
  }
  else {
    iVar1 = ((ATIR500Surface *)(M<UInt8 *>(param_1 + 0xf8)))->getFramebufferIndex();
    piVar2 = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(M<UInt32>(iVar1 * 0x20 + M<SInt32>(param_1 + 0x8c) + 0xd4),
                                 (UInt32)&GH_IONDRVFramebuffer_metaClass);
    M<SInt32 *>(param_1 + 0x160) = piVar2;
    if (piVar2 == (SInt32 *)0x0) {
      iVar1 = M<SInt32>(param_1 + 0x8c);
      uVar3 = 0xe00002c0;
    }
    else {
      uVar3 = VCALL(*piVar2, 0x70c)(piVar2,param_2,&stack0x00000020);
      iVar1 = M<SInt32>(param_1 + 0x8c);
    }
  }
  GH_IOLockUnlock(M<UInt32>(iVar1 + 0x840));
  return uVar3;
}
