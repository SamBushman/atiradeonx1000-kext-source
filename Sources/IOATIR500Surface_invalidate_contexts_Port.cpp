/*
 * IOATIR500Surface_invalidate_contexts_Port.cpp
 *
 * IOATIR500Surface::invalidate_contexts (real addr 0x12050, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x12050 */
void IOATIR500Surface::invalidate_contexts() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 *piVar1;
  
  M<UInt32>(M<SInt32>(self + 0xd50) + 0x78) = 0;
  for (piVar1 = M<SInt32 *>(self + 0x8c); piVar1 != (SInt32 *)0x0; piVar1 = (SInt32 *)piVar1[0x21]) {
    VCALL(*piVar1, 0x5a4)(piVar1);
  }
  for (piVar1 = M<SInt32 *>(self + 0x88); piVar1 != (SInt32 *)0x0; piVar1 = (SInt32 *)piVar1[0x21]) {
    VCALL(*piVar1, 0x5a4)(piVar1);
  }
  if (M<SInt32 *>(self + 0x90) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(self + 0x90), 0x5a4)(M<SInt32 *>(self + 0x90));
  }
  return;
}
