/*
 * IOATIR500GLContext_set_surface_Port.cpp
 *
 * IOATIR500GLContext::set_surface (real addr 0x87b0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x87b0 */
IOReturn IOATIR500GLContext::set_surface(UInt32 param_1, eIOGLContextModeBits param_3, UInt32 param_4, UInt32 param_5) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  int iVar2;
  unsigned int uVar3;
  UInt32 uVar4;
  UInt8 *this_00;
  unsigned int uVar5;
  unsigned int local_38 [7];
  
  GH_IOLockLock(M<UInt32>(M<int>(self + 200) + 0x840));
  if (param_1 == 0) {
    uVar4 = 0;
    this_00 = (UInt8 *)0x0;
    bVar1 = true;
  }
  else {
    this_00 = (UInt8 *)
              ((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->find_surface_for_id(param_1);
    bVar1 = this_00 == (UInt8 *)0x0;
    if (bVar1) {
      uVar4 = 0xe00002c2;
    }
    else {
      uVar4 = 0;
    }
  }
  if (M<UInt8 *>(self + 0x290) != (UInt8 *)0x0) {
    ((IOATIR500Surface *)(M<UInt8 *>(self + 0x290)))->remove_gl_context_from_list((IOATIR500GLContext *)(self));
    if (this_00 != M<UInt8 *>(self + 0x290)) {
      ((IOATIR500Surface *)(M<UInt8 *>(self + 0x290)))->prune_buffers();
    }
  }
  if (bVar1) {
    M<UInt8 *>(self + 0x29c) = this_00;
    M<UInt8 *>(self + 0x290) = this_00;
    M<UInt8 *>(self + 0x298) = this_00;
  }
  else {
    local_38[0] = M<unsigned int>(this_00 + 0xbe8);
    if (this_00 != M<UInt8 *>(self + 0x290)) {
      ((IOATIR500Surface *)(this_00))->reset_req_bits();
    }
    if (((M<int>(this_00 + 0x90) == 0) && (M<int>(this_00 + 0x8c) == 0)) &&
       ((M<UInt8 *>(this_00 + 0x88) == (UInt8 *)0x0 ||
        ((self == M<UInt8 *>(this_00 + 0x88) && (M<int>(self + 0x84) == 0)))))) {
      local_38[0] = local_38[0] & 0x803f | param_3 & 0xffffc03f;
    }
    else if ((((M<unsigned int>(this_00 + 0xc18) & 4) != 0) &&
             (((param_3 & 0x300) != 0 &&
              ((M<unsigned int>(this_00 + 0xc18) >> 7 & 1) != (param_3 >> 0xd & 1))))) ||
            (iVar2 = VCALL(M<int>(self), 0x5ac)(self,local_38,param_3), iVar2 == 0)) {
      if (this_00 == M<UInt8 *>(self + 0x290)) {
        ((IOATIR500Surface *)(this_00))->prune_buffers();
      }
      M<UInt32>(self + 0x290) = 0;
      uVar4 = 0xe00002c2;
      goto LAB_00008ad0;
    }
    M<unsigned int>(this_00 + 0xbe8) = local_38[0];
    M<UInt32>(self + 0x8c) = 0x20000000;
    if ((param_3 & 0x400) != 0) {
      M<UInt32>(self + 0x8c) = 0x20000002;
    }
    if ((param_3 & 0x800) == 0) {
      uVar5 = M<unsigned int>(self + 0x8c);
    }
    else {
      uVar5 = M<unsigned int>(self + 0x8c) | 1;
      M<unsigned int>(self + 0x8c) = uVar5;
    }
    if ((M<unsigned int>(this_00 + 0xbe8) & 0x10) != 0) {
      if ((uVar5 & 1) != 0) {
        uVar5 = uVar5 | 0x20;
        M<unsigned int>(self + 0x8c) = uVar5;
      }
      if ((uVar5 & 2) != 0) {
        uVar5 = uVar5 | 0x10;
        M<unsigned int>(self + 0x8c) = uVar5;
      }
    }
    uVar3 = VCALL(M<int>(this_00), 0x5ac)(this_00);
    M<unsigned int>(self + 0x8c) = uVar5 | uVar3;
    if ((param_3 & 0x40) != 0) {
      M<unsigned int>(self + 0x8c) = uVar5 | uVar3 | 0x40;
    }
    if ((param_3 & 0x1000) != 0) {
      M<unsigned int>(self + 0x8c) = M<unsigned int>(self + 0x8c) | 0x200;
    }
    if (0xff < (param_3 & 0x300)) {
      bVar1 = (param_3 & 0x2000) != 0;
      uVar5 = M<unsigned int>(self + 0x8c);
      M<unsigned int>(self + 0x8c) = uVar5 | 4;
      if (bVar1) {
        M<unsigned int>(self + 0x8c) = uVar5 | 0x84;
      }
      if (0x1ff < (param_3 & 0x300)) {
        uVar5 = M<unsigned int>(self + 0x8c);
        M<unsigned int>(self + 0x8c) = uVar5 | 8;
        if (bVar1) {
          M<unsigned int>(self + 0x8c) = uVar5 | 0x108;
        }
      }
    }
    VCALL(M<int>(self), 0x5bc)(self,param_3);
    ((IOATIR500Surface *)(this_00))->add_gl_context_to_list((IOATIR500GLContext *)(self));
    M<UInt8 *>(self + 0x290) = this_00;
    ((IOATIR500Surface *)(this_00))->prune_buffers();
  }
LAB_00008ad0:
  if (self == M<UInt8 *>(M<int>(self + 200) + 0x78)) {
    M<UInt32>(M<int>(self + 200) + 0x78) = 0;
  }
  M<UInt32>(self + 0x298) = param_4;
  M<UInt32>(self + 0x29c) = param_5;
  VCALL(M<int>(self), 0x5a8)(self);
  GH_IOLockUnlock(M<UInt32>(M<int>(self + 200) + 0x840));
  return uVar4;
}
