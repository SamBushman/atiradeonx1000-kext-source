/*
 * ATIRadeonX1000_enable_GPUSensor_Port.cpp
 *
 * ATIRadeonX1000::enable_GPUSensor (real addr 0x19f30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* PERF NOTE (NOT APPLIED). Estimated cycles rebuilt/stock 1.11-1.12 (52 against 58). Cause: 6 nops that gcc 4.0.1 inserts for G5 dispatch groups after a
 * volatile access; the shipped build places them elsewhere. Same instruction mix otherwise. No source change closes it short of reordering code. */
/* real addr 0x19f30 */
void ATIRadeonX1000::enable_GPUSensor() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 *sensorTimer;
  
  M<UInt32>(self + kIOATIR500Accelerator_gpuSensorSampleCount) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gpuSensorBusyCount) = 0;
  sensorTimer = M<SInt32 *>(self + kIOATIR500Accelerator_gpuSensorTimer);
  if (sensorTimer != (SInt32 *)0x0) {
    VCALL(*sensorTimer, 300)(sensorTimer,M<UInt32>(self + kIOATIR500Accelerator_gpuSensorPeriodMs));
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_gpuSensorTimer), 0xec)(M<SInt32 *>(self + kIOATIR500Accelerator_gpuSensorTimer));
  }
  return;
}
