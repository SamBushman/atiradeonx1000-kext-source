/*
 * IOATIR500Surface_surface_query_lock_Port.cpp
 *
 * IOATIR500Surface::surface_query_lock (real addr 0x151a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x151a0 */
IOReturn IOATIR500Surface::surface_query_lock() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 allocated;
  UInt32 result;
  UInt32 pendingBits;
  UInt32 bufferIndex;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x840));
  if (((M<UInt32>(self + kIOATIR500Surface_lockFlags) & 0xffff0000) == 0) &&
     (M<SInt32>(M<SInt32>(self + kIOATIR500Surface_attachmentBuffers) + 0x10) != 0)) {
    if ((M<UInt32>(self + kIOATIR500Surface_stateBits) & 0x20000000) == 0) {
      pendingBits = M<UInt32>(self + kIOATIR500Surface_stateBits) & M<UInt32>(self + kIOATIR500Surface_reqBits);
      if ((pendingBits & 3) != 0) {
        bufferIndex = pendingBits & 1 ^ 1;
        if ((M<SInt32>(self + bufferIndex * 0x78 + 0xb8) != 0) &&
           (M<SInt32>(self + bufferIndex * 0x78 + 0xb0) == 0)) {
          /* #171: stock 0x15210: r4 = this + idx*0x78 + 0xa8 (the buffer record), alloc_surface_buffer(ATIR500SurfaceBuffer*) */
          allocated = VCALL(M<SInt32>(self), 0x5d0)(self,self + bufferIndex * 0x78 + 0xa8);
          if (allocated != 0) {
            result = 0;
            VCALL(M<SInt32>(self), 0x5cc)(self,bufferIndex);
            goto unlockAndReturn;
          }
          goto failBusy;
        }
      }
      result = 0;
      goto unlockAndReturn;
    }
  }
failBusy:
  result = 0xe00002cc;
unlockAndReturn:
  GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x840));
  return result;
}
