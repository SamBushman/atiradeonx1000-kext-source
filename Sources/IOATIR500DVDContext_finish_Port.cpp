/*
 * IOATIR500DVDContext_finish_Port.cpp
 *
 * IOATIR500DVDContext::finish (real addr 0xea30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0xea30 */
IOReturn IOATIR500DVDContext::finish() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 waited;
  UInt32 result;
  
  waited = VCALL(*M<SInt32 *>(self + kIOATIR500DVDContext_accelerator), 0x55c)
                    (M<SInt32 *>(self + kIOATIR500DVDContext_accelerator),M<UInt32>(self + kIOATIR500DVDContext_lastSubmitStamp));
  if (waited == -1) {
    result = 0xe00002d6;
  }
  else {
    result = 0;
    M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x7ac) = waited + M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x7ac);
  }
  return result;
}
