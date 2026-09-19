/*
 * IOATIR500Surface_setupFullScreen_Port.cpp
 *
 * IOATIR500Surface::setupFullScreen (real addr 0x13900, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x13900 */
void IOATIR500Surface::setupFullScreen() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt32 uVar2;
  
  iVar1 = VCALL(M<SInt32>(self), 0x5dc)(self);
  if (iVar1 != 0) {
    uVar2 = M<UInt32>(self + 0xc14);
    if ((1 << (uVar2 & 0x3f) & M<UInt32>(M<SInt32>(self + 0xd50) + 0xd0)) != 0) {
      M<UInt16>(self + uVar2 * 0x94 + 0xcae) = M<SInt16>(self + uVar2 * 0x94 + 0xcae) + 1U & 3;
      VCALL(M<SInt32>(self), 0x5e0)(self,M<UInt32>(self + 0xc14),0,0);
      M<SInt32>(M<SInt32>(self + 0xd50) + 0x74c) = M<SInt32>(M<SInt32>(self + 0xd50) + 0x74c) + 1;
    }
  }
  return;
}
