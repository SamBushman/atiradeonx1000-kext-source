/*
 * IOATIR500DVDContext_create_shared_Port.cpp
 *
 * IOATIR500DVDContext::create_shared (real addr 0xee60, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_ZN8OSObjectnwEm(...) asm("__ZN8OSObjectnwEm");


/* real addr 0xee60 */
bool IOATIR500DVDContext::create_shared() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *this_00;
  UInt32 uVar1;
  SInt32 iVar2;
  UInt8 bVar3;
  
  this_00 = (UInt8 *)new IOATIR500Shared();   /* real: OSObject::operator new(0x28) + the IOATIR500Shared constructor */
  bVar3 = (this_00 == (UInt8 *)0x0) << 1;
  M<UInt8 *>(self + 0x84) = this_00;
  if ((bool)(bVar3 >> 1 & 1)) {
    uVar1 = 0;
  }
  else {
    iVar2 = VCALL(M<SInt32>(this_00), 0x48)(this_00);
    if (iVar2 == 0) {
      VCALL(*M<SInt32 *>(self + 0x84), 0x18)(M<SInt32 *>(self + 0x84));
      uVar1 = 0;
      M<UInt32>(self + 0x84) = 0;
    }
    else {
      uVar1 = 1;
      M<UInt32>(M<SInt32>(self + 0x84) + 0xc) = M<UInt32>(self + 0x8c);
      M<UInt32>(M<SInt32>(self + 0x84) + 8) = M<UInt32>(self + 0x78);
    }
  }
  return uVar1;
}
