/*
 * HZMEM_GetBlockCount_Port.cpp
 *
 * HZMEM_GetBlockCount (real addr 0x45810, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x45810 */
UInt32 HZMEM_GetBlockCount(_HZDATA *real_param_1, UInt32 param_2, UInt32 param_3) {
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt32 uVar1;
  SInt32 iVar2;
  
  if ((param_1 != (UInt8 *)0x0) && (M<SInt32>(param_1 + param_3 * 4 + 0x10) != 0)) {
    if (param_3 == 1) {
      uVar1 = param_2 >> 10 & 0x3ff;
    }
    else {
      uVar1 = param_2 & 0x3ff;
      if (param_3 != 0) {
        if (param_3 != 2) {
          return 1;
        }
        uVar1 = param_2 >> 0x14 & 0x3ff;
      }
    }
    if (uVar1 != 0x3ff) {
      iVar2 = uVar1 * 0x10 + M<SInt32>(param_1 + param_3 * 4 + 0x10);
      if (iVar2 != -0x14) {
        return *(UInt32 *)(iVar2 + 0x1c);
      }
      return 0xfffffffe;
    }
  }
  return 1;
}
