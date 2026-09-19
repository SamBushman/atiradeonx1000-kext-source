/*
 * IOATIR500Surface_surface_write_lock_int_Port.cpp
 *
 * IOATIR500Surface::surface_write_lock_int (real addr 0x114a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x114a0 */
void IOATIR500Surface::surface_write_lock_int(UInt32 param_1, UInt32*param_2, UInt32*param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 *piVar1;
  SInt32 iVar2;
  SInt32 iVar3;
  
  iVar2 = M<SInt32>(self + param_1 * 4 + 0xb70);
  VCALL(M<SInt32>(self), 0x5fc)(self,iVar2);
  *param_2 = M<UInt32>(iVar2 + 8);
  *param_3 = (UInt32)M<UInt16>(iVar2 + 0x18);
  piVar1 = M<SInt32 *>(self + 0xd50);
  iVar3 = piVar1[0x1ef];
  iVar2 = VCALL(*piVar1, 0x558)(piVar1,piVar1[0x14] + -1);
  piVar1[0x1ef] = iVar3 + iVar2;
  return;
}
