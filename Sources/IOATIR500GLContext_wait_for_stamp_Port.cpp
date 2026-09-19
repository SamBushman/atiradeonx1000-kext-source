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
IOReturn IOATIR500GLContext::wait_for_stamp(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt32 uVar2;
  
  iVar1 = VCALL(*M<SInt32 *>(param_1 + 200), 0x550)(M<SInt32 *>(param_1 + 200));
  if (iVar1 == -1) {
    uVar2 = 0xe00002d6;
  }
  else {
    uVar2 = 0;
    M<SInt32>(M<SInt32>(param_1 + 200) + 0x768) = iVar1 + M<SInt32>(M<SInt32>(param_1 + 200) + 0x768);
  }
  return uVar2;
}
