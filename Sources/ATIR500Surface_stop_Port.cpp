/*
 * ATIR500Surface_stop_Port.cpp
 *
 * ATIR500Surface::stop (real addr 0x3b0c0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x3b0c0 */
void ATIR500Surface::stop(IOService *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  bool bVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  UInt8 *pAVar6;
  UInt8 *pAVar7;
  UInt32 *puVar8;
  
  iVar5 = 0;
  pAVar6 = self + 0xa8;
  GH_IOLockLock(M<UInt32>(param_1 + 0x840));
  pAVar7 = self;
  do {
    if (pAVar7[0xdf] != 0xff) {
      VCALL(M<SInt32>(self), 0x600)(self,pAVar6);
    }
    bVar1 = iVar5 != 0x16;
    pAVar6 = pAVar6 + 0x78;
    pAVar7 = pAVar7 + 0x78;
    iVar5 = iVar5 + 1;
  } while (bVar1);
  if (((param_1[0x80] != 0x0) && (M<SInt32>(self + 0xc14) != 0xffff)) &&
     (M<UInt8 *>(param_1 + M<SInt32>(self + 0xc14) * 0x20 + 0xe8) == self)) {
    iVar3 = M<SInt32>(param_1 + 0x238);
    puVar8 = (UInt32 *)(iVar3 + 0x120);
    VCALL(M<SInt32>(param_1), 0x54c)(param_1,M<UInt32>(param_1 + 0x234));
    param_1[M<SInt32>(self + 0xc14) * 0x78 + 0x164] = SUB41m(M<UInt32>(self + 0xdb8),0);
    iVar5 = VCALL(M<SInt32>(self), 0x5dc)(self);
    if ((iVar5 == 0) || (M<UInt8 *>(self + 0xb74) == self + 0x120)) {
      uVar4 = 0;
    }
    else {
      iVar5 = M<SInt32>(self + 0xc14);
      uVar4 = 0x1844;
      if (iVar5 != 0) {
        uVar4 = 0x1a44;
      }
      *puVar8 = uVar4;
      M<UInt32>(iVar3 + 0x124) = M<UInt32>(param_1 + iVar5 * 0x78 + 0x134);
      uVar4 = 2;
      M<UInt8 *>(self + 0xb74) = self + 0x120;
    }
    uVar2 = ((ATIRadeonX1000 *)((UInt8 *)param_1))->submit_buffer((UInt32 *)(puVar8),M<SInt32>(param_1 + 0x228) + 0x120,uVar4);
    M<UInt32>(param_1 + 0x234) = uVar2;
  }
  if (self[0xbf0] != 0x0) {
    this->free_overlay();
    self[0xbf0] = 0x0;
  }
  if (M<SInt32>(param_1 + 0x8b8) != 0) {
    VCALL(M<SInt32>(param_1), 0x5ac)(param_1,param_1 + 0x8a8);
    VCALL(*M<SInt32 *>(param_1 + 0x8b0), 0x18)(M<SInt32 *>(param_1 + 0x8b0));
    M<UInt32>(param_1 + 0x8b8) = 0;
  }
  IOATIR500Surface::stop(real_param_1);
  GH_IOLockUnlock(M<UInt32>(param_1 + 0x840));
  return;
}
