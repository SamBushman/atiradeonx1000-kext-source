/*
 * ATIR500GLContext_GetTextureOffset_Port.cpp
 *
 * ATIR500GLContext::GetTextureOffset (real addr 0x280c0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x280c0 */
UInt32 ATIR500GLContext::GetTextureOffset(VendorTextureBuffer *real_param_1, bool param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt8 VVar1;
  SInt32 iVar2;
  UInt32 in_register_00000014;
  UInt8 *this_00;
  UInt32 auStack_28 [8];
  
  VVar1 = param_1[0x20];
  if ((VVar1 == 0x3) || (VVar1 == 0x7)) {
    iVar2 = 0;
    if (((UInt32)param_2) == 0) {
      iVar2 = M<SInt32>(param_1 + 0x60);
    }
    iVar2 = iVar2 + M<SInt32>(param_1 + 0x48);
  }
  else {
    if (VVar1 == 0x6) {
      if (M<SInt32>(M<SInt32>(param_1 + 0x54) + 4) != 0) {
        iVar2 = 0;
        if (((UInt32)param_2) == 0) {
          iVar2 = M<SInt32>(param_1 + 0x60);
        }
        return *(SInt32 *)(M<SInt32>(param_1 + 0x54) + 4) +
               iVar2 + M<SInt32>(param_1 + 0x50) + M<SInt32>(M<SInt32>(self + 200) + 0x8a4);
      }
    }
    else if ((VVar1 == 0x0) &&
            (this_00 = M<UInt8 *>(param_1 + 0x50), this_00 != (UInt8 *)0x0))
    {
      iVar2 = ((IOATIR500Surface *)(this_00))->surface_buffer_idx_mask(M<UInt32>(param_1 + 0x58),(UInt32 *)(auStack_28));
      iVar2 = M<SInt32>(this_00 + iVar2 * 4 + 0xb70);
      return (UInt32)M<UInt16>(iVar2 + 0x20) * M<SInt32>(M<SInt32>(param_1 + 0x60) * 4 + iVar2 + 0x40)
             + M<SInt32>(iVar2 + 8);
    }
    iVar2 = 0;
  }
  return iVar2;
}
