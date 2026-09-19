/*
 * IOATIR500Surface_dealloc_surface_Port.cpp
 *
 * IOATIR500Surface::dealloc_surface (real addr 0x12580, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x12580 */
UInt32 IOATIR500Surface::dealloc_surface(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  
  if (M<SInt32>(self + param_1 * 0x78 + 0xb0) != 0) {
    if ((3 >> (param_1 & 0x3f) & 1U) != 0) {
      for (iVar1 = M<SInt32>(self + 0xbcc); iVar1 != 0; iVar1 = M<SInt32>(iVar1 + 0x54)) {
        M<UInt8>(M<SInt32>(iVar1 + 0x14) + 0x14) = 1;
      }
    }
    ((ATIR500Memory *)(M<UInt8 *>(M<SInt32>(self + 0xd50) + 0x7c)))->dealloc((GLKMemoryElement *)((UInt8 *)(self + param_1 * 0x78 + 0xa8)));
  }
  M<UInt32>(self + 0xbf8) = 1 << (param_1 & 0x3f) | M<UInt32>(self + 0xbf8);
  return 1;
}
