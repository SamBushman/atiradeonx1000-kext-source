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
IOReturn IOATIR5002DContext::declare_image(UInt32 unused, unsigned int address, UInt32 length, unsigned int*outUserAddr) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *shared;
  SInt32 iVar1;
  UInt32 result;
  
  if ((length == 0) || (address == 0)) {
    result = 0xe00002c2;
  }
  else {
    GH_IOLockLock(M<UInt32>(M<SInt32>(self + 0x94) + 0x840));
    shared = M<UInt8 *>(self + 0x88);
    if (shared == (UInt8 *)0x0) {
      iVar1 = this->create_shared();
      if (iVar1 == 0) {
        GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 0x94) + 0x840));
        return 0xe00002be;
      }
      shared = M<UInt8 *>(self + 0x88);
    }
    iVar1 = (SInt32)((IOATIR500Shared *)(shared))->new_agp_texture(address, length, (unsigned int *)(outUserAddr));
    GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 0x94) + 0x840));
    result = 0;
    if (iVar1 == 0) {
      result = 0xe00002bd;
    }
  }
  return result;
}
