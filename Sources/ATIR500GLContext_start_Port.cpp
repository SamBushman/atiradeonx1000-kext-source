/*
 * ATIR500GLContext_start_Port.cpp
 *
 * ATIR500GLContext::start (real addr 0x28540, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern const VendorExternalMethod kGLSpecialMethod20;   /* IOATIR500GLContext_ExternalMethods.cpp */

extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");


/* real addr 0x28540 */
bool ATIR500GLContext::start(IOService *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt16 uVar1;
  UInt8 *pAVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  UInt8 *pAVar5;
  
  GH_IOLockLock(M<UInt32>(param_1 + 0x840));
  iVar3 = IOATIR500GLContext::start(real_param_1);
  if (iVar3 == 0) {
    GH_IOLockUnlock(M<UInt32>(param_1 + 0x840));
    uVar4 = 0;
  }
  else {
    M<UInt32>(self + 0x3bc) = 0;
    M<UInt32>(self + 0x34c) = 0;
    M<UInt32>(self + 0x350) = 0;
    M<UInt32>(self + 0x354) = 0;
    M<UInt32>(self + 0x358) = 0;
    pAVar5 = self + 0x3f0;
    iVar3 = 6;
    pAVar2 = self;
    do {
      M<UInt16>(pAVar2 + 0x3d4) = 0;
      M<UInt16>(pAVar2 + 0x3d6) = 0;
      M<UInt16>(pAVar2 + 0x3d8) = 0;
      M<UInt16>(pAVar2 + 0x3dc) = 0;
      M<UInt16>(pAVar2 + 0x3de) = 0;
      M<UInt16>(pAVar2 + 0x3e0) = 1;
      M<UInt16>(pAVar2 + 0x3e2) = 1;
      pAVar2[0x3f4] = 0x0;
      pAVar2[0x3f5] = 0x0;
      pAVar2[0x3f6] = 0x0;
      pAVar2[0x3f7] = 0xff;
      pAVar2[0x3f8] = 0x0;
      pAVar2[0x3f9] = 0x0;
      pAVar2[0x3fb] = 0x6;
      pAVar2[0x3fc] = 0x0;
      M<UInt32>(pAVar2 + 0x3c0) = 0;
      M<UInt32>(pAVar2 + 0x3c4) = 0;
      M<UInt32>(pAVar2 + 0x3c8) = 0;
      M<UInt32>(pAVar2 + 0x3cc) = 0;
      M<UInt32>(pAVar2 + 0x3d0) = 0;
      M<UInt32>(pAVar2 + 0x3e4) = 0;
      M<UInt32>(pAVar2 + 1000) = 0xffffffff;
      M<UInt32>(pAVar2 + 0x3ec) = 0;
      M<UInt32>(pAVar2 + 0x3f0) = 0;
      M<UInt32>(pAVar5 + 0xc) = M<UInt32>(pAVar5 + 0xc) & 0xff0007ff | 0x111000;
      M<UInt32>(pAVar2 + 0x400) = 0;
      pAVar5 = pAVar5 + 0x78;
      M<UInt32>(pAVar2 + 0x404) = 0;
      pAVar2 = pAVar2 + 0x78;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    uVar1 = M<UInt16>(self + 0xac);
    iVar3 = 4;
    pAVar2 = self;
    do {
      M<UInt16>(pAVar2 + 0x3b2) = 0;
      M<UInt16>(pAVar2 + 0x3aa) = uVar1;
      pAVar2 = pAVar2 + 2;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    M<UInt16>(self + 0x3a8) = 1;
    M<UInt32>(M<SInt32>(self + 0xe0) + 0x1c) = 9;
    M<UInt32>(M<SInt32>(self + 0xe0) + 0x40) = 0x1000000;
    M<UInt8 **>(self + 0x360) = (UInt8 **)&kGLSpecialMethod20; /* ATIR500GLContext::start(IOService*)::methodDescs */
    GH_IOLockUnlock(M<UInt32>(param_1 + 0x840));
    uVar4 = 1;
  }
  return uVar4;
}
