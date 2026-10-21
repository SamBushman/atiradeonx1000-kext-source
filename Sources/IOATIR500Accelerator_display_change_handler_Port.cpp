/*
 * IOATIR500Accelerator_display_change_handler_Port.cpp
 *
 * IOATIR500Accelerator::display_change_handler (real addr 0x370, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_OSDecrementAtomic(...) asm("_OSDecrementAtomic");
extern "C" UInt32 GH_OSIncrementAtomic(...) asm("_OSIncrementAtomic");


extern "C" UInt32 GH_OSIncrementAtomic(...) asm("_OSIncrementAtomic");
extern "C" UInt32 GH_OSDecrementAtomic(...) asm("_OSDecrementAtomic");

/* real addr 0x370 */
IOReturn IOATIR500Accelerator::display_change_handler(OSObject *owner, void *ref, IOFramebuffer *framebuffer, SInt32 event, void *info) {
    UInt8 *ownerBytes = reinterpret_cast<UInt8 *>(owner);
    UInt8 *framebufferBytes = reinterpret_cast<UInt8 *>(framebuffer);

  int prevOutstanding;
  int modeChangeStatus;
  
  ((IOATIR500Accelerator *)ownerBytes)->getVRAMDescriptor((UInt32)ref);   /* stub 0x534 -> local 0x290; r3/r4 are the untouched arguments */
  switch(event) {
  default:
    goto failUnsupported;
  case 1:
    goto beginModeChange;
  case 3:
    if (info != (void *)0x0) {
      VCALL(M<int>(ownerBytes), 0x5bc)(ownerBytes);
      return 0;
    }
beginModeChange:
    prevOutstanding = GH_OSIncrementAtomic(ownerBytes + 200);
    if (prevOutstanding == 0) {
      modeChangeStatus = VCALL(M<int>(ownerBytes), 0x5b4)(ownerBytes,event);
checkModeChangeStatus:
      if (modeChangeStatus == 0) {
failUnsupported:
        return 0xe00002bc;
      }
    }
    return 0;
  case 4:
    if (info != (void *)0x0) {
      VCALL(M<int>(ownerBytes), 0x5c0)(ownerBytes);
      return 0;
    }
  case 2:
    prevOutstanding = GH_OSDecrementAtomic(ownerBytes + 200);
    if (prevOutstanding != 1) {
      return 0;
    }
    modeChangeStatus = VCALL(M<int>(ownerBytes), 0x5b8)(ownerBytes);
    goto checkModeChangeStatus;
  case 9:
    VCALL(M<int>(ownerBytes), 0x5c4)(ownerBytes);
    return 0;
  case 10:
    VCALL(M<int>(ownerBytes), 0x5c8)(ownerBytes);
    return 0;
  }
}
