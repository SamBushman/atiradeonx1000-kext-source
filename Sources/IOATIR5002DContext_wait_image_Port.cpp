/*
 * IOATIR5002DContext_wait_image_Port.cpp
 *
 * IOATIR5002DContext::wait_image (real addr 0xd5c0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0xd5c0 */
IOReturn IOATIR5002DContext::wait_image(UInt32 textureID) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt32 result;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x840));
  iVar1 = M<SInt32>(self + kIOATIR5002DContext_sharedAllocator);
  if (iVar1 == 0) {
    GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x840));
    result = 0xe00002be;
  }
  else {
    if ((textureID < M<UInt32>(iVar1 + 0x14)) &&
       (iVar1 = M<SInt32>(textureID * 4 + M<SInt32>(iVar1 + 0x10)), iVar1 != 0)) {
      GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x840));
      iVar1 = VCALL(*M<SInt32 *>(self + kIOATIR5002DContext_accelerator), 0x550)
                        (M<SInt32 *>(self + kIOATIR5002DContext_accelerator),M<UInt32>(M<SInt32>(iVar1 + 0x14) + 8));
      if (iVar1 == -1) {
        return 0xe00002d6;
      }
      M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x75c) = iVar1 + M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x75c);
      return 0;
    }
    GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x840));
    result = 0xe00002c2;
  }
  return result;
}
