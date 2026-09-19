/*
 * IOATIR500Accelerator_getVRAMDescriptor_Port.cpp
 *
 * IOATIR500Accelerator::getVRAMDescriptor (real addr 0x290, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x290 */
UInt32 IOATIR500Accelerator::getVRAMDescriptor(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 *piVar1;
  UInt32 uVar2;
  UInt32 uVar3;
  
  uVar3 = 1;
  if (M<SInt32>(self + param_1 * 0x20 + 0xdc) == 0) {
    piVar1 = (SInt32 *)VCALL(*M<SInt32 *>(self + param_1 * 0x20 + 0xd4), 0x5d0)(M<SInt32 *>(self + param_1 * 0x20 + 0xd4));
    uVar3 = 0;
    M<SInt32 *>(self + param_1 * 0x20 + 0xdc) = piVar1;
    if (piVar1 != (SInt32 *)0x0) {
      piVar1 = (SInt32 *)VCALL(*piVar1, 0x150)(piVar1,0x101);
      M<SInt32 *>(self + param_1 * 0x20 + 0xe0) = piVar1;
      if (piVar1 == (SInt32 *)0x0) {
        VCALL(*M<SInt32 *>(self + param_1 * 0x20 + 0xdc), 0x18)(M<SInt32 *>(self + param_1 * 0x20 + 0xdc));
        M<UInt32>(self + param_1 * 0x20 + 0xdc) = 0;
        uVar3 = 0;
      }
      else {
        uVar2 = VCALL(*piVar1, 0xd0)(piVar1);
        uVar3 = 1;
        M<UInt32>(self + param_1 * 0x20 + 0xe4) = uVar2;
      }
    }
  }
  return uVar3;
}
