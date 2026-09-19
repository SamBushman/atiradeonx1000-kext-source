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
IOReturn ATIR500DVDContext::wait_for_stamps(UInt32 param_1, UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  if (param_1 != 0) {
    VCALL(*M<SInt32 *>(self + 0x8c), 0x5fc)(M<SInt32 *>(self + 0x8c));
  }
  if (param_2 != 0) {
    VCALL(*M<SInt32 *>(self + 0x8c), 0x558)(M<SInt32 *>(self + 0x8c),param_2);
  }
  return 0;
}
