/*
 * IOATIR500GLContext_get_surface_size_Port.cpp
 *
 * IOATIR500GLContext::get_surface_size (real addr 0x7ca0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x7ca0 */
IOReturn IOATIR500GLContext::get_surface_size(SInt32*param_1, SInt32*param_2, SInt32*param_3, SInt32*param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  SInt32 iVar4;
  UInt32 uVar5;
  UInt32 uVar6;
  
  iVar4 = M<SInt32>(self + 0x290);
  if (iVar4 != 0) {
    iVar3 = M<SInt32>(self + 0x29c);
    if (M<SInt32>(iVar4 + 0xbd8) == M<SInt32>(iVar4 + 0xbd4)) {
      uVar2 = (UInt32)M<UInt16>(M<SInt32>(iVar4 + 0xb70) + 0x1e);
      uVar1 = (UInt32)M<UInt16>(M<SInt32>(iVar4 + 0xb70) + 0x1c);
      uVar5 = uVar1;
      uVar6 = uVar2;
      if (0 < iVar3) {
        do {
          if (1 < uVar1) {
            uVar1 = (SInt32)uVar1 >> 1;
          }
          if (1 < uVar2) {
            uVar2 = (SInt32)uVar2 >> 1;
          }
          iVar3 = iVar3 + -1;
          uVar5 = uVar1;
          uVar6 = uVar2;
        } while (iVar3 != 0);
      }
    }
    else {
      uVar2 = (UInt32)M<SInt16>(iVar4 + 0xbda);
      uVar1 = (UInt32)M<SInt16>(iVar4 + 0xbd4);
      uVar5 = (SInt32)M<SInt16>(iVar4 + 0xbd8);
      uVar6 = (SInt32)M<SInt16>(iVar4 + 0xbd6);
    }
    *param_1 = uVar5;
    *param_2 = uVar2;
    *param_3 = uVar1;
    *param_4 = uVar6;
    return 0;
  }
  return 0xe00002bc;
}
