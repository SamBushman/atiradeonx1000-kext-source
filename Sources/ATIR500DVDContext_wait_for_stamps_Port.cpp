/*
 * ATIR500DVDContext_wait_for_stamps_Port.cpp
 *
 * ATIR500DVDContext::wait_for_stamps (real addr 0x34120, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x34120 */
IOReturn ATIR500DVDContext::wait_for_stamps(UInt32 waitMain, UInt32 waitIDCT) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  if (waitMain != 0) {
    /* #171: stock 0x34148 passes waitMain (incoming r4, untouched since entry) to sleepForConsumedIDCTTimeStamp(unsigned long); the port dropped it */
    VCALL(*M<SInt32 *>(self + kIOATIR500DVDContext_accelerator), 0x5fc)(M<SInt32 *>(self + kIOATIR500DVDContext_accelerator),waitMain);
  }
  if (waitIDCT != 0) {
    VCALL(*M<SInt32 *>(self + kIOATIR500DVDContext_accelerator), 0x558)(M<SInt32 *>(self + kIOATIR500DVDContext_accelerator),waitIDCT);
  }
  return 0;
}
