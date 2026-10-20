/*
 * IOATIR500Surface_get_state_Port.cpp
 *
 * IOATIR500Surface::get_state (real addr 0x10f30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x10f30 */
IOReturn IOATIR500Surface::get_state(eIOAccelSurfaceStateBits *outStateBits) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *outStateBitsBytes = reinterpret_cast<UInt8 *>(outStateBits);

  SInt32 isIdle;
  
  isIdle = VCALL(*M<SInt32 *>(self + kIOATIR500Surface_accelerator), 0x520)(M<SInt32 *>(self + kIOATIR500Surface_accelerator));
  if (isIdle == 0) {
    M<UInt32>(outStateBitsBytes) = 0;
  }
  else {
    M<UInt32>(outStateBitsBytes) = 1;
  }
  return 0;
}
