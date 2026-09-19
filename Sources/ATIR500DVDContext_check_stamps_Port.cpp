/*
 * ATIR500DVDContext_check_stamps_Port.cpp
 *
 * ATIR500DVDContext::check_stamps (real addr 0x341a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x341a0 */
IOReturn ATIR500DVDContext::check_stamps(UInt32 param_1, UInt32 param_2, UInt32*param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  SInt32 iVar2;
  SInt32 iVar3;
  
  iVar3 = 1;
  if (param_1 != 0) {
    iVar3 = VCALL(*M<SInt32 *>(self + 0x8c), 0x5f4)(M<SInt32 *>(self + 0x8c));
  }
  iVar2 = 1;
  if (param_2 != 0) {
    iVar2 = VCALL(*M<SInt32 *>(self + 0x8c), 0x554)(M<SInt32 *>(self + 0x8c),param_2);
  }
  if ((iVar3 == 0) || (uVar1 = 1, iVar2 == 0)) {
    uVar1 = 0;
  }
  *param_3 = uVar1;
  return 0;
}
