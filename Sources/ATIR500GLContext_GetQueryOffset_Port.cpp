/*
 * ATIR500GLContext_GetQueryOffset_Port.cpp
 *
 * ATIR500GLContext::GetQueryOffset (real addr 0x26f60, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x26f60 */
UInt32 ATIR500GLContext::GetQueryOffset(VendorTextureBuffer *real_param_1, UInt32 param_2, UInt32 param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  SInt32 iVar1;
  
  if (param_3 == 0) {
    iVar1 = param_2 * 0x20 + 0x210;
  }
  else {
    iVar1 = param_2 * 0x20 + 0x10;
  }
  return *(SInt32 *)(param_1 + 0x50) + M<SInt32>(M<SInt32>(param_1 + 0x54) + 4) + iVar1 +
         M<SInt32>(M<SInt32>(self + 200) + 0x8a4);
}
