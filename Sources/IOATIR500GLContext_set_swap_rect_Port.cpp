/*
 * IOATIR500GLContext_set_swap_rect_Port.cpp
 *
 * IOATIR500GLContext::set_swap_rect (real addr 0x7ba0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x7ba0 */
IOReturn IOATIR500GLContext::set_swap_rect(SInt32 param_1, SInt32 param_2, SInt32 param_3, SInt32 param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 *piVar1;
  
  M<SInt16>(self + 0x90) = (SInt16)param_1;
  M<SInt16>(self + 0x92) = (SInt16)param_2;
  M<SInt16>(self + 0x94) = (SInt16)param_3;
  M<SInt16>(self + 0x96) = (SInt16)param_4;
  piVar1 = M<SInt32 *>(self + 0x290);
  if (piVar1 != (SInt32 *)0x0) {
    VCALL(*piVar1, 0x5c4)(piVar1);
  }
  return 0;
}
