/*
 * ATIR500Surface_getFramebufferIndex_Port.cpp
 *
 * ATIR500Surface::getFramebufferIndex (real addr 0x3a7a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3a7a0 */
UInt32 ATIR500Surface::getFramebufferIndex() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  SInt32 iVar2;
  SInt32 iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    if (((M<SInt32>(self + 0xd64) != 0) && (M<SInt16>(M<SInt32>(self + 0xd60) + 8) != 0)) &&
       (M<SInt16>(M<SInt32>(self + 0xd60) + 10) != 0)) {
      iVar3 = iVar2;
    }
    bVar1 = iVar2 != 1;
    self = self + 8;
    iVar2 = iVar2 + 1;
  } while (bVar1);
  return iVar3;
}
