/*
 * IOATIR500GLContext_wait_for_stamp_Port.cpp
 *
 * IOATIR500GLContext::wait_for_stamp (real addr 0x7de0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x7de0 */
IOReturn IOATIR500GLContext::wait_for_stamp(UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = self;   /* Ghidra's param_1 IS `this` (r3); the stamp (r4) is its param_2, forwarded to the accelerator's wait (#86) */

  SInt32 iVar1;
  UInt32 uVar2;
  
  /* CORRECTED (found by the live T2 test: wait_for_stamp(0x7fffffff) returned Timeout on stock): the shipped body leaves r4 - the caller's stamp - untouched, so the
   * stamp IS the second argument of the accelerator's wait (vtable +0x550); the decompile dropped it and #86's first fix wrongly called it unused. */
  iVar1 = VCALL(*M<SInt32 *>(param_1 + 200), 0x550)(M<SInt32 *>(param_1 + 200),param_2);
  if (iVar1 == -1) {
    uVar2 = 0xe00002d6;
  }
  else {
    uVar2 = 0;
    M<SInt32>(M<SInt32>(param_1 + 200) + 0x768) = iVar1 + M<SInt32>(M<SInt32>(param_1 + 200) + 0x768);
  }
  return uVar2;
}
