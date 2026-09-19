/*
 * IOATIR500Surface_is_surface_size_supported_Port.cpp
 *
 * IOATIR500Surface::is_surface_size_supported (real addr 0x13fb0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x13fb0 */
SInt32 IOATIR500Surface::is_surface_size_supported(short param_1, short param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt16 in_register_00000010;
  UInt16 in_register_00000014;
  
  if ((CONCAT22(in_register_00000010,param_1) <=
       (SInt32)(UInt32)M<UInt16>(M<SInt32>(self + 0xd50) + 0xa8)) &&
     (CONCAT22(in_register_00000014,param_2) <=
      (SInt32)(UInt32)M<UInt16>(M<SInt32>(self + 0xd50) + 0xaa))) {
    return 1;
  }
  return 0;
}
