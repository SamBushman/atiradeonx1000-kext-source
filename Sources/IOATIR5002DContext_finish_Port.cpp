/*
 * IOATIR5002DContext_finish_Port.cpp
 *
 * IOATIR5002DContext::finish (real addr 0xbdc0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0xbdc0 */
IOReturn IOATIR5002DContext::finish(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  code *pcVar1;
  SInt32 *piVar2;
  SInt32 iVar3;
  
  if (param_1 == 1) {
    piVar2 = M<SInt32 *>(self + 0x94);
    iVar3 = piVar2[0x14];
    pcVar1 = M<code *>(*piVar2 + 0x55c);
  }
  else {
    if (param_1 == 0) {
      iVar3 = VCALL(*M<SInt32 *>(self + 0x94), 0x55c)
                        (M<SInt32 *>(self + 0x94),M<UInt32>(self + 0x7c));
      if (iVar3 == -1) {
        return 0xe00002d6;
      }
      M<SInt32>(M<SInt32>(self + 0x94) + 0x7a4) = iVar3 + M<SInt32>(M<SInt32>(self + 0x94) + 0x7a4);
      return 0;
    }
    if (param_1 != 2) {
      return 0xe00002c2;
    }
    piVar2 = M<SInt32 *>(self + 0x94);
    iVar3 = piVar2[0x14];
    pcVar1 = M<code *>(*piVar2 + 0x558);
  }
  iVar3 = (*pcVar1)(piVar2,iVar3 + -1);
  if (iVar3 == -1) {
    return 0xe00002d6;
  }
  M<SInt32>(M<SInt32>(self + 0x94) + 0x7a0) = iVar3 + M<SInt32>(M<SInt32>(self + 0x94) + 0x7a0);
  return 0;
}
