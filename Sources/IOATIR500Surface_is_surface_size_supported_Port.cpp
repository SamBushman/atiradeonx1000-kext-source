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
SInt32 IOATIR500Surface::is_surface_size_supported(short width, short height) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  /* #157 FIX: the mechanical port reconstructed the caller's full-register width/height via
   * CONCAT22(in_register_..., param_N) - Ghidra's placeholder for "upper 16 bits came from a
   * register whose origin wasn't traced" - but ported it as a genuinely UNINITIALIZED C++ local,
   * not the caller's actual (already sign-extended) value. Confirmed live (issue #157): with
   * width=height=4 and the real max-size fields both 0x1000, this returned 0 (should be 1) -
   * the uninitialized upper bits were corrupting the comparison. Stock's real disassembly
   * (0x13fb0, cmpw on the full raw register) relies on the caller having already placed a clean
   * sign-extended value there, which set_shape_backing_length_ext's own call site does via
   * `(int)M<SInt16>(...)` - ordinary C++ integer promotion of `short` to `SInt32` reproduces that
   * exact value with no UB, so no CONCAT22/in_register reconstruction is needed at all. */
  if (((SInt32)width <=
       (SInt32)(UInt32)M<UInt16>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0xa8)) &&
     ((SInt32)height <=
      (SInt32)(UInt32)M<UInt16>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0xaa))) {
    return 1;
  }
  return 0;
}
