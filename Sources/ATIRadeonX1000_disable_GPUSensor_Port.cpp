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



/* PERF NOTE (NOT APPLIED). Estimated cycles rebuilt/stock 1.13-1.14 (400 against 454 over the sampled seeds). Cause: 18 more loads than stock, from volatile
 * re-reads of the sensor register and accelerator fields that the shipped code reads once. Closing it: read each into a local once, which must keep the
 * register access sequence identical (difftest compares it strictly). A few cycles per call; not worth distorting the register sequence. */
/* real addr 0x19fd0 */
void ATIRadeonX1000::disable_GPUSensor() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  if (M<SInt32 *>(self + kIOATIR500Accelerator_gpuSensorTimer) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_gpuSensorTimer), 0x158)(M<SInt32 *>(self + kIOATIR500Accelerator_gpuSensorTimer));
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_gpuSensorTimer), 0xf0)(M<SInt32 *>(self + kIOATIR500Accelerator_gpuSensorTimer));
  }
  return;
}
