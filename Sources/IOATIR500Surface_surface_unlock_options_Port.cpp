/*
 * IOATIR500Surface_surface_unlock_options_Port.cpp
 *
 * IOATIR500Surface::surface_unlock_options (real addr 0x14f60, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x14f60 */
IOReturn IOATIR500Surface::surface_unlock_options(eLockType lockType, UInt32 unlockOptions) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *selfBytes = reinterpret_cast<UInt8 *>(this);

  UInt8 lockState;
  int *memory;
  UInt8 *lockStatePtr;
  UInt32 result;
  int surfaceBuffer;
  
  lockStatePtr = self + kIOATIR500Surface_lockFlags;
  if (lockType != 1) {
    lockStatePtr = self + kIOATIR500Surface_writeLockHeld;
  }
  GH_IOLockLock(M<UInt32>(M<int>(self + kIOATIR500Surface_accelerator) + 0x840));
  lockState = *lockStatePtr;
  if (lockState == 0x0) {
    result = 0xe00002cc;
  }
  else {
    surfaceBuffer = M<int>(self + kIOATIR500Surface_attachmentBuffers);
    if (lockState == 0x3) {
      if (M<int>(self + kIOATIR500Surface_orphanedBacking) == 0) {
        if ((M<int>(surfaceBuffer + 0x24) != 0) &&
           (memory = M<int *>(M<int>(surfaceBuffer + 0x24) + 0x10), memory != (int *)0x0)) {
          VCALL(*memory, 0x18)(memory);
          M<UInt32>(M<int>(surfaceBuffer + 0x24) + 0x10) = 0;
        }
      }
      else {
        this->free_buffer_backing_orphans();
      }
    }
    else if ((lockState == 0x1) && (M<int>(surfaceBuffer + 8) != 0)) {
      VCALL(M<int>(self), 0x600)(self,surfaceBuffer);
    }
    result = 0;
    *lockStatePtr = 0x0;
  }
  GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500Surface_accelerator) + 0x840));
  return result;
}
