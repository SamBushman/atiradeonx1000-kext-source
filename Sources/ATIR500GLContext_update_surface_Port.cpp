/*
 * ATIR500GLContext_update_surface_Port.cpp
 *
 * ATIR500GLContext::update_surface (real addr 0x27fd0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x27fd0 */
void ATIR500GLContext::update_surface() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  SInt32 iVar2;
  UInt32 uVar3;
  
  if (M<SInt32>(self + 0x290) != 0) {
    iVar2 = M<SInt32>(self + 0x35c);
    uVar3 = M<UInt32>(M<SInt32>(self + 0x290) + 0xbe8);
    if ((iVar2 == 1) || ((iVar2 == 0 && ((uVar3 & 0x400) == 0)))) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (((uVar3 & 0x7c0000) == 0) || (!bVar1)) {
      M<SInt16>(self + 0x3aa) = (SInt16)iVar2;
      M<SInt16>(self + 0xac) = (SInt16)iVar2;
    }
    else {
      M<UInt16>(self + 0x3aa) = 9;
      M<UInt16>(self + 0xac) = 9;
    }
    this->build_scissor();
  }
  VCALL(M<SInt32>(self), 0x5a4)(self);
  M<UInt32>(M<SInt32>(self + 200) + 0x78) = 0;
  return;
}
