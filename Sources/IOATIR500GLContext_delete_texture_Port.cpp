/*
 * IOATIR500GLContext_delete_texture_Port.cpp
 *
 * IOATIR500GLContext::delete_texture (real addr 0x9570, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x9570 */
IOReturn IOATIR500GLContext::delete_texture(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *this_00;
  UInt32 uVar1;
  UInt8 *pVVar2;
  
  GH_IOLockLock(M<UInt32>(M<int>(self + 200) + 0x840));
  this_00 = M<UInt8 *>(self + 0x88);
  if ((param_1 < M<unsigned int>(this_00 + 0x14)) &&
     (pVVar2 = M<UInt8 *>(param_1 * 4 + M<int>(this_00 + 0x10)),
     pVVar2 != (UInt8 *)0x0)) {
    uVar1 = ((IOATIR500Shared *)(this_00))->delete_texture((VendorTextureBuffer *)(pVVar2));
    GH_IOLockUnlock(M<UInt32>(M<int>(self + 200) + 0x840));
    return uVar1;
  }
  GH_IOLockUnlock(M<UInt32>(M<int>(self + 200) + 0x840));
  return 0xe00002c2;
}
