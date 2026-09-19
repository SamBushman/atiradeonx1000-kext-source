/*
 * ATIR500GLContext_GetVertexArrayOffset_Port.cpp
 *
 * ATIR500GLContext::GetVertexArrayOffset (real addr 0x26ed0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x26ed0 */
UInt32 ATIR500GLContext::GetVertexArrayOffset(VendorTextureBuffer *real_param_1, UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  if (param_1 != (UInt8 *)0x0) {
    if (param_2 == 0xffffffff) {
      param_2 = 0;
    }
    if (param_1[0x20] == 0x7) {
      if (M<SInt32>(param_1 + 0x48) == 0) {
        return 0;
      }
      return *(SInt32 *)(param_1 + 0x48) + param_2;
    }
    if (param_1[0x20] == 0x6) {
      if (M<SInt32>(M<SInt32>(param_1 + 0x54) + 4) == 0) {
        return 0;
      }
      return *(SInt32 *)(M<SInt32>(param_1 + 0x54) + 4) +
             param_2 + M<SInt32>(param_1 + 0x50) + M<SInt32>(M<SInt32>(self + 200) + 0x8a4);
    }
  }
  return 0;
}
