/*
 * IOATIR500Shared_free_handles_Port.cpp
 *
 * IOATIR500Shared::free_handles (real addr 0x16b30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOFree(...) asm("_IOFree");


/* real addr 0x16b30 */
void IOATIR500Shared::free_handles() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  
  GH_IOFree(M<UInt32>(self + 0x10),
               M<UInt32>(self + 0x14) * 4 + (M<UInt32>(self + 0x14) >> 3));
  iVar1 = M<SInt32>(self + 0xc);
  if (iVar1 != 0) {
    M<UInt32>(iVar1 + 0x808) =
         M<SInt32>(iVar1 + 0x808) - (M<UInt32>(self + 0x14) * 4 + (M<UInt32>(self + 0x14) >> 3));
  }
  return;
}
