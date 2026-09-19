/*
 * IOATIR500Surface_surface_buffer_idx_mask_Port.cpp
 *
 * IOATIR500Surface::surface_buffer_idx_mask (real addr 0x13ac0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x13ac0 */
UInt32 IOATIR500Surface::surface_buffer_idx_mask(UInt32 param_1, UInt32*param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  switch(param_1) {
  case 1:
switchD_00013ae0_caseD_1:
    if (M<UInt8 *>(self + 0xb70) == self + 0xa8) {
      *param_2 = 1;
      return 0;
    }
    *param_2 = 2;
    return 0;
  case 2:
    if (M<UInt8 *>(self + 0xb80) == self + 0x300) {
      *param_2 = 0x20;
      return 4;
    }
    *param_2 = 0x10;
    return 4;
  case 3:
    if (M<UInt8 *>(self + 0xb84) == self + 0x300) {
      *param_2 = 0x20;
      return 5;
    }
    *param_2 = 0x10;
    return 5;
  case 4:
    *param_2 = 0x40;
    return 6;
  case 7:
    *param_2 = 4;
    return 2;
  case 8:
    *param_2 = 8;
    return 3;
  case 10:
    *param_2 = 0x80;
    return 7;
  case 0xb:
    *param_2 = 0x100;
    return 8;
  case 0x11:
    if ((M<UInt32>(self + 0xc18) & 2) == 0) {
      if ((M<UInt32>(self + 0xc18) & 1) == 0) {
        *param_2 = 0;
        return 0;
      }
      goto switchD_00013ae0_caseD_1;
    }
  }
  if (M<UInt8 *>(self + 0xb74) == self + 0xa8) {
    *param_2 = 1;
    return 1;
  }
  *param_2 = 2;
  return 1;
}
