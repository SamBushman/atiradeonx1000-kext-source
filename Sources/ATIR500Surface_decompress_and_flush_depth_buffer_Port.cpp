/*
 * ATIR500Surface_decompress_and_flush_depth_buffer_Port.cpp
 *
 * ATIR500Surface::decompress_and_flush_depth_buffer (real addr 0x3db40, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3db40 */
UInt32 ATIR500Surface::decompress_and_flush_depth_buffer(ATIR500SurfaceBuffer *real_param_1, UInt32 param_2, UInt32*param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  SInt32 iVar1;
  
  M<UInt32>(M<SInt32>(self + 0xd50) + 0xb94) = 0;
  if (param_1[0x34] == 0x0) {
    param_3[param_2] = 0x1393;
    param_3[param_2 + 1] = 10;
    param_3[param_2 + 2] = 0x13c6;
    param_3[param_2 + 3] = 3;
    param_3[param_2 + 4] = 0x5c8;
    iVar1 = param_2 + 6;
    param_3[param_2 + 5] = 0x20000;
  }
  else {
    iVar1 = (SInt32)this->load_3d_blit((UInt32 *)(param_3 + param_2),(ATIR500SurfaceBuffer *)(param_1));
    iVar1 = iVar1 - (SInt32)param_3 >> 2;
    M<UInt32>(M<SInt32>(self + 0xd50) + 0xb90) = 1;
    M<UInt32>(M<SInt32>(self + 0xd50) + 0x78) = 0;
  }
  return iVar1;
}
