/*
 * IOATIR5002DContext_create_image_Port.cpp
 *
 * IOATIR5002DContext::create_image (real addr 0xd130, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0xd130 */
IOReturn IOATIR5002DContext::create_image(UInt32 size, UInt32 auxValue, unsigned int*outDataAddress, unsigned int*outSharedUserAddr) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 result;
  UInt8 *shared;
  SInt32 iVar2;
  SInt32 sharedCreated;
  SInt32 newTextureResult;
  
  if (size == 0) {
    result = 0xe00002c2;
  }
  else {
    GH_IOLockLock(M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x840));
    shared = M<UInt8 *>(self + kIOATIR5002DContext_sharedAllocator);
    if (shared == (UInt8 *)0x0) {
      sharedCreated = this->create_shared();
      if (sharedCreated == 0) {
        GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x840));
        return 0xe00002be;
      }
      shared = M<UInt8 *>(self + kIOATIR5002DContext_sharedAllocator);
    }
    newTextureResult = (SInt32)((IOATIR500Shared *)(shared))->new_texture(size, auxValue, 0, 0, (unsigned int *)(outDataAddress), (unsigned int *)(outSharedUserAddr));
    GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x840));
    result = 0;
    if (newTextureResult == 0) {
      result = 0xe00002bd;
    }
  }
  return result;
}
