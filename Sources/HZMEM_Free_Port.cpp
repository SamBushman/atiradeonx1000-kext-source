/*
 * HZMEM_Free_Port.cpp
 *
 * HZMEM_Free (real addr 0x45680, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x45680 */
UInt32 HZMEM_Free(_HZDATA *real_param_1, UInt32 param_2, UInt32 param_3) {
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt32 uVar1;
  SInt32 iVar2;
  UInt8 *puVar3;
  UInt32 uVar4;
  UInt32 uVar5;
  UInt32 *puVar6;
  
  if (param_1 != (UInt8 *)0x0) {
    puVar6 = M<UInt32 *>(param_1 + param_3 * 4 + 0x10);
    if (puVar6 != (UInt32 *)0x0) {
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
      if ((uVar1 != 0x3ff) && (puVar6 + uVar1 * 4 + 5 != (UInt32 *)0x0)) {
        uVar5 = puVar6[1];
        if (uVar5 == 0) {
          uVar4 = 0;
          uVar5 = 0;
        }
        else {
          uVar4 = puVar6[uVar1 * 4 + 6] / uVar5;
          uVar5 = uVar4 + puVar6[uVar1 * 4 + 7] / uVar5;
          if (*puVar6 < uVar5) {
            return 1;
          }
        }
        if (puVar6[3] != 0) {
          if (uVar4 < uVar5) {
            iVar2 = uVar5 - uVar4;
            puVar3 = (UInt8 *)(uVar4 + puVar6[3]);
            do {
              *puVar3 = 0;
              puVar3 = puVar3 + 1;
              iVar2 = iVar2 + -1;
            } while (iVar2 != 0);
          }
          puVar6[uVar1 * 4 + 5] = 0;
          M<SInt32>(M<SInt32>(param_1 + param_3 * 4 + 0x10) + 0x10) =
               M<SInt32>(M<SInt32>(param_1 + param_3 * 4 + 0x10) + 0x10) + -1;
          return 0;
        }
      }
    }
  }
  return 1;
}
