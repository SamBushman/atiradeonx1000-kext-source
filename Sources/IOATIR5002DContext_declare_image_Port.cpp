/*
 * IOATIR5002DContext_declare_image_Port.cpp
 *
 * IOATIR5002DContext::declare_image (real addr 0xd020, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0xd020 */
IOReturn IOATIR5002DContext::declare_image(UInt32 param_1, unsigned int param_2, UInt32 param_3, unsigned int*param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *this_00;
  SInt32 iVar1;
  UInt32 uVar2;
  
  if ((param_3 == 0) || (param_2 == 0)) {
    uVar2 = 0xe00002c2;
  }
  else {
    GH_IOLockLock(M<UInt32>(M<SInt32>(self + 0x94) + 0x840));
    this_00 = M<UInt8 *>(self + 0x88);
    if (this_00 == (UInt8 *)0x0) {
      iVar1 = this->create_shared();
      if (iVar1 == 0) {
        GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 0x94) + 0x840));
        return 0xe00002be;
      }
      this_00 = M<UInt8 *>(self + 0x88);
    }
    iVar1 = (SInt32)((IOATIR500Shared *)(this_00))->new_agp_texture(param_2, param_3, (unsigned int *)(param_4));
    GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 0x94) + 0x840));
    uVar2 = 0;
    if (iVar1 == 0) {
      uVar2 = 0xe00002bd;
    }
  }
  return uVar2;
}
