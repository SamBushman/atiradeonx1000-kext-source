/*
 * IOATIR500Surface_buffer_map_offset_Port.cpp
 *
 * IOATIR500Surface::buffer_map_offset (real addr 0x14010, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x14010 */
SInt32 IOATIR500Surface::buffer_map_offset(ATIR500SurfaceBuffer *real_param_1, UInt32 param_2, UInt32 param_3, SInt32*param_4, SInt32*param_5, SInt32*param_6) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt16 uVar1;
  UInt16 uVar2;
  UInt16 uVar3;
  
  uVar1 = M<UInt16>(param_1 + 0x14);
  uVar2 = M<UInt16>(param_1 + 0x16);
  uVar3 = M<UInt16>(param_1 + 0x1e);
  if (param_4 != (long *)0x0) {
    *param_4 = (UInt32)M<UInt16>(param_1 + 0x1c);
  }
  if (param_5 != (long *)0x0) {
    *param_5 = (UInt32)uVar3;
  }
  if (param_6 != (long *)0x0) {
    *param_6 = (UInt32)uVar2 * (UInt32)uVar1;
  }
  return 0;
}
