/*
 * ATIR500Memory_total_free_Port.cpp
 *
 * ATIR500Memory::total_free (real addr 0x19910, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x19910 */
int ATIR500Memory::total_free() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 *piVar1;
  SInt32 iVar2;
  SInt32 *piVar3;
  
  iVar2 = 0;
  piVar3 = *(SInt32 **)*M<UInt32 *>(self + 8);
  while (piVar1 = piVar3, piVar3 = (SInt32 *)*piVar1, piVar3 != (SInt32 *)0x0) {
    if (piVar1[3] < 0) {
      iVar2 = iVar2 + (piVar3[2] - piVar1[2]);
    }
  }
  return iVar2;
}
