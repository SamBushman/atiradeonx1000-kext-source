/*
 * ATIRadeonX1000_disable_GPUSensor_Port.cpp
 *
 * ATIRadeonX1000::disable_GPUSensor (real addr 0x19fd0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x19fd0 */
void ATIRadeonX1000::disable_GPUSensor() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  if (M<SInt32 *>(self + 0x9a8) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(self + 0x9a8), 0x158)(M<SInt32 *>(self + 0x9a8));
    VCALL(*M<SInt32 *>(self + 0x9a8), 0xf0)(M<SInt32 *>(self + 0x9a8));
  }
  return;
}
