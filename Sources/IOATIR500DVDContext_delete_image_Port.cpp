/*
 * IOATIR500DVDContext_delete_image_Port.cpp
 *
 * IOATIR500DVDContext::delete_image (real addr 0x104f0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x104f0 */
IOReturn IOATIR500DVDContext::delete_image(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *this_00;
  UInt8 *pVVar1;
  UInt32 uVar2;
  
  GH_IOLockLock(M<UInt32>(M<int>(self + 0x8c) + 0x840));
  this_00 = M<UInt8 *>(self + 0x84);
  if (this_00 == (UInt8 *)0x0) {
    uVar2 = 0xe00002be;
    GH_IOLockUnlock(M<UInt32>(M<int>(self + 0x8c) + 0x840));
  }
  else {
    if ((param_1 < M<unsigned int>(this_00 + 0x14)) &&
       (pVVar1 = M<UInt8 *>(param_1 * 4 + M<int>(this_00 + 0x10)),
       pVVar1 != (UInt8 *)0x0)) {
      uVar2 = ((IOATIR500Shared *)(this_00))->delete_texture((VendorTextureBuffer *)(pVVar1));
      GH_IOLockUnlock(M<UInt32>(M<int>(self + 0x8c) + 0x840));
      return uVar2;
    }
    uVar2 = 0xe00002c2;
    GH_IOLockUnlock(M<UInt32>(M<int>(self + 0x8c) + 0x840));
  }
  return uVar2;
}
