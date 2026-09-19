/*
 * IOATIR500Surface_reset_access_Port.cpp
 *
 * IOATIR500Surface::reset_access (real addr 0x10de0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x10de0 */
void IOATIR500Surface::reset_access() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 *piVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  
  iVar3 = M<SInt32>(self + 0xc00);
  VCALL(M<SInt32>(self), 0x604)(self);
  if (iVar3 != M<SInt32>(self + 0xc00)) {
    if (M<SInt32 *>(self + 0xd84) != (SInt32 *)0x0) {
      VCALL(*M<SInt32 *>(self + 0xd84), 0x18)(M<SInt32 *>(self + 0xd84));
    }
    if (M<SInt32 *>(self + 0xd88) != (SInt32 *)0x0) {
      VCALL(*M<SInt32 *>(self + 0xd88), 0x18)(M<SInt32 *>(self + 0xd88));
    }
    M<UInt32>(self + 0xc0c) = 0;
    M<UInt32>(self + 0xc10) = 0;
    piVar1 = (SInt32 *)VCALL(*M<SInt32 *>(self + 0xc00), 0x150)(M<SInt32 *>(self + 0xc00),1);
    M<SInt32 *>(self + 0xd88) = piVar1;
    if (piVar1 != (SInt32 *)0x0) {
      uVar2 = VCALL(*piVar1, 0xd0)(piVar1);
      M<UInt32>(self + 0xc10) = uVar2;
    }
    if (self[0xbf4] != 0x0) {
      piVar1 = (SInt32 *)VCALL(*M<SInt32 *>(self + 0xc00), 0x14c)
                                (M<SInt32 *>(self + 0xc00),M<UInt32>(self + 0x78),0,1,0,0);
      M<SInt32 *>(self + 0xd84) = piVar1;
      if (piVar1 != (SInt32 *)0x0) {
        uVar2 = VCALL(*piVar1, 0xd0)(piVar1);
        M<UInt32>(self + 0xc0c) = uVar2;
      }
    }
  }
  return;
}
