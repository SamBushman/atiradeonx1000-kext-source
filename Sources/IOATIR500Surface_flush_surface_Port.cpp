/*
 * IOATIR500Surface_flush_surface_Port.cpp
 *
 * IOATIR500Surface::flush_surface (real addr 0x10fa0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x10fa0 */
void IOATIR500Surface::flush_surface(UInt32 param_1, UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt32 uVar2;
  UInt8 *pIVar3;
  
  if ((self[0xbed] == 0x0) ||
     (iVar1 = VCALL(*M<SInt32 *>(self + 0xd50), 0x554)
                        (M<SInt32 *>(self + 0xd50),M<UInt32>(self + 0x80)), iVar1 != 0)) {
    if ((M<UInt32>(self + 0xbf8) & M<UInt32>(self + 0xc1c) & 0x10000000) != 0) {
      VCALL(M<SInt32>(self), 0x5c0)(self);
      M<UInt32>(self + 0xbf8) = M<UInt32>(self + 0xbf8) & 0xefffffff;
    }
    iVar1 = M<SInt32>(self + 0xd50);
    M<UInt32>(self + 0x84) = M<UInt32>(self + 0x80);
    if (M<SInt32>(iVar1 + 0xcc) != 0) {
      uVar2 = 0;
      pIVar3 = self;
      do {
        if (((1 << (uVar2 & 0x3f) & param_1) != 0) && (pIVar3[0xcac] != 0x0)) {
          VCALL(M<SInt32>(self), 0x5d4)(self,uVar2,param_2);
          M<SInt32>(M<SInt32>(self + 0xd50) + 0x74c) = M<SInt32>(M<SInt32>(self + 0xd50) + 0x74c) + 1;
          iVar1 = M<SInt32>(self + 0xd50);
        }
        uVar2 = uVar2 + 1;
        pIVar3 = pIVar3 + 0x94;
      } while (uVar2 < M<UInt32>(iVar1 + 0xcc));
    }
    M<UInt32>(iVar1 + 0x78) = 0;
  }
  return;
}
