/*
 * ATIR500Surface_getTargetAndMethodForIndex_Port.cpp
 *
 * ATIR500Surface::getTargetAndMethodForIndex (real addr 0x3ac80, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3ac80 */
IOExternalMethod *ATIR500Surface::getTargetAndMethodForIndex(IOService**param_1, UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  *param_1 = reinterpret_cast<IOService *>(this);
  if (0x12 < param_2) {
    return 0;
  }
  return (IOExternalMethod *)(param_2 * 0x18 + M<SInt32>(self + 0xd5c));
}
