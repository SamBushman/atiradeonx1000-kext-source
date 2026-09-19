/*
 * IOATIR500GLContext_freeAllContextBuffers_Port.cpp
 *
 * IOATIR500GLContext::freeAllContextBuffers (real addr 0x7000, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x7000 */
void IOATIR500GLContext::freeAllContextBuffers() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  SInt32 iVar2;
  SInt32 iVar3;
  SInt32 *piVar4;
  SInt32 iVar5;
  UInt8 *pIVar6;
  UInt8 *pIVar7;
  
  pIVar6 = self + 0x10c;
  iVar3 = 0;
  piVar4 = M<SInt32 *>(self + 200);
  iVar5 = piVar4[0x1e0];
  iVar2 = VCALL(*piVar4, 0x54c)
                    (piVar4,M<UInt32>(self + M<SInt32>(self + 0x28c) * 0x18 + 0x11c));
  piVar4[0x1e0] = iVar5 + iVar2;
  pIVar7 = self;
  do {
    if (M<SInt32>(pIVar7 + 0x110) != 0) {
      VCALL(*M<SInt32 *>(self + 200), 0x5ac)(M<SInt32 *>(self + 200),pIVar6);
    }
    pIVar6 = pIVar6 + 0x18;
    VCALL(*M<SInt32 *>(pIVar7 + 0x114), 0x18)(M<SInt32 *>(pIVar7 + 0x114));
    bVar1 = iVar3 != 0xf;
    M<UInt32>(pIVar7 + 0x10c) = 0;
    M<UInt32>(pIVar7 + 0x110) = 0;
    M<UInt32>(pIVar7 + 0x114) = 0;
    M<UInt16>(pIVar7 + 0x11a) = 0;
    M<UInt16>(pIVar7 + 0x118) = 0;
    M<UInt32>(pIVar7 + 0x11c) = 0;
    M<UInt32>(pIVar7 + 0x120) = 0;
    iVar3 = iVar3 + 1;
    pIVar7 = pIVar7 + 0x18;
  } while (bVar1);
  VCALL(*M<SInt32 *>(self + 0xfc), 0x18)(M<SInt32 *>(self + 0xfc));
  M<UInt16>(self + 0x102) = 0;
  M<UInt16>(self + 0x100) = 0;
  M<UInt32>(self + 0x108) = 0;
  M<UInt32>(self + 0xf4) = 0;
  M<UInt32>(self + 0xf8) = 0;
  M<UInt32>(self + 0xfc) = 0;
  M<UInt32>(self + 0x104) = 0;
  return;
}
