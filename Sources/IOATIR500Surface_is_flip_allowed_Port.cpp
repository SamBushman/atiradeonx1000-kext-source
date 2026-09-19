/*
 * IOATIR500Surface_is_flip_allowed_Port.cpp
 *
 * IOATIR500Surface::is_flip_allowed (real addr 0x13f60, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x13f60 */
SInt32 IOATIR500Surface::is_flip_allowed() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  
  if (((M<char>(M<SInt32>(self + 0xd50) + 0x80) == '\0') || (M<SInt32>(self + 0xc14) == 0xffff)) ||
     (uVar1 = 1,
     self != M<UInt8 *>(M<SInt32>(self + 0xc14) * 0x20 + M<SInt32>(self + 0xd50) + 0xe8)))
  {
    uVar1 = 0;
  }
  return uVar1;
}
