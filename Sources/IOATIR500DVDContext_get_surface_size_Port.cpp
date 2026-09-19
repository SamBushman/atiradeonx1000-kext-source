/*
 * IOATIR500DVDContext_get_surface_size_Port.cpp
 *
 * IOATIR500DVDContext::get_surface_size (real addr 0xe9e0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0xe9e0 */
IOReturn IOATIR500DVDContext::get_surface_size(SInt32*param_1, SInt32*param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  if (M<SInt32>(self + 0xf8) == 0) {
    return 0xe00002bc;
  }
  *param_1 = (UInt32)M<UInt16>(M<SInt32>(M<SInt32>(self + 0xf8) + 0xb70) + 0x1c);
  *param_2 = (UInt32)M<UInt16>(M<SInt32>(M<SInt32>(self + 0xf8) + 0xb70) + 0x1e);
  return 0;
}
