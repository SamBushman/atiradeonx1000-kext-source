/*
 * IOATIR500DVDContext_set_surface_Port.cpp
 *
 * IOATIR500DVDContext::set_surface (real addr 0xfa40, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0xfa40 */
IOReturn IOATIR500DVDContext::set_surface(UInt32 param_1, eIODVDContextModeBits param_3, int param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  unsigned int uVar2;
  unsigned int uVar3;
  int iVar4;
  unsigned int uVar5;
  UInt32 uVar6;
  UInt8 *this_00;
  unsigned int local_38 [8];
  
  GH_IOLockLock(M<UInt32>(M<int>(self + 0x8c) + 0x840));
  if (param_1 == 0) {
    uVar6 = 0;
    this_00 = (UInt8 *)0x0;
    bVar1 = true;
  }
  else {
    this_00 = (UInt8 *)
              ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0x8c)))->find_surface_for_id(param_1);
    bVar1 = this_00 == (UInt8 *)0x0;
    if (bVar1) {
      uVar6 = 0xe00002c2;
    }
    else {
      uVar6 = 0;
    }
  }
  if (M<UInt8 *>(self + 0xf8) != (UInt8 *)0x0) {
    ((IOATIR500Surface *)(M<UInt8 *>(self + 0xf8)))->remove_dvd_context((IOATIR500DVDContext *)(self));
    if (this_00 != M<UInt8 *>(self + 0xf8)) {
      ((IOATIR500Surface *)(M<UInt8 *>(self + 0xf8)))->prune_buffers();
    }
  }
  if ((bVar1) ||
     ((M<UInt8 *>(this_00 + 0x90) != (UInt8 *)0x0 &&
      (self != M<UInt8 *>(this_00 + 0x90))))) {
    M<UInt32>(self + 0xf8) = 0;
  }
  else {
    local_38[0] = M<unsigned int>(this_00 + 0xbe8);
    if (this_00 != M<UInt8 *>(self + 0xf8)) {
      ((IOATIR500Surface *)(this_00))->reset_req_bits();
    }
    if ((M<int>(this_00 + 0x88) == 0) && (M<int>(this_00 + 0x8c) == 0)) {
      local_38[0] = local_38[0] & 0x803f | param_3 & 0xffffbfff;
    }
    else {
      iVar4 = VCALL(M<int>(self), 0x5ac)(self,local_38,param_3);
      if (iVar4 == 0) {
        if (this_00 == M<UInt8 *>(self + 0xf8)) {
          ((IOATIR500Surface *)(this_00))->prune_buffers();
        }
        M<UInt32>(self + 0xf8) = 0;
        uVar6 = 0xe00002c2;
        goto LAB_0000fc30;
      }
    }
    M<unsigned int>(this_00 + 0xbe8) = local_38[0];
    if (0 < param_4) {
      uVar5 = M<unsigned int>(self + 0x88);
      uVar3 = 0;
      do {
        uVar2 = uVar3 & 0x3f;
        uVar3 = uVar3 + 1;
        uVar5 = uVar5 | 0x400 << uVar2;
        param_4 = param_4 + -1;
      } while (param_4 != 0);
      M<unsigned int>(self + 0x88) = uVar5;
    }
    ((IOATIR500Surface *)(this_00))->set_dvd_context((IOATIR500DVDContext *)(self));
    M<UInt8 *>(self + 0xf8) = this_00;
    ((IOATIR500Surface *)(this_00))->prune_buffers();
  }
LAB_0000fc30:
  if (self == M<UInt8 *>(M<int>(self + 0x8c) + 0x78)) {
    M<UInt32>(M<int>(self + 0x8c) + 0x78) = 0;
  }
  VCALL(M<int>(self), 0x5a8)(self);
  GH_IOLockUnlock(M<UInt32>(M<int>(self + 0x8c) + 0x840));
  return uVar6;
}
