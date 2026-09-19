/*
 * ATIR500Memory_alloc_Port_195f0.cpp
 *
 * ATIR500Memory::alloc (real addr 0x195f0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x195f0 */
UInt32 ATIR500Memory::alloc(GLKMemoryElement *real_param_1, UInt32 param_2, UInt32 param_3, UInt32 param_4, UInt32 param_5) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt32 uVar1;
  SInt32 iVar2;
  UInt32 uVar3;
  UInt32 uVar4;
  UInt32 *puVar5;
  UInt32 uVar6;
  UInt32 *puVar7;
  UInt32 *puVar8;
  
  if ((M<SInt32>(self + 0xc) != 0) || (iVar2 = this->add_to_stack(), iVar2 != 0)) {
    uVar3 = 0;
    if (param_3 != 0) {
      uVar3 = param_3 - 1;
    }
    puVar7 = *(UInt32 **)*M<UInt32 *>(self + 8);
    while (puVar7 != (UInt32 *)0x0) {
      while (puVar8 = puVar7, puVar7 = (UInt32 *)*puVar8, (SInt32)puVar8[3] < 0) {
        uVar6 = param_4;
        if (param_4 <= (UInt32)puVar8[2]) {
          uVar6 = uVar3 + puVar8[2] & ~uVar3;
        }
        uVar4 = param_2 + uVar6;
        if (uVar4 <= (UInt32)puVar7[2]) {
          if (param_4 + param_5 < uVar4) {
            return 0;
          }
          M<UInt32>(param_1 + 8) = uVar6;
          puVar5 = (UInt32 *)puVar8[1];
          M<UInt32>(param_1 + 0xc) = uVar3 & 0xffff;
          if (uVar6 == puVar8[2]) {
            if (uVar4 != puVar7[2]) {
              M<UInt32 *>(param_1) = puVar8;
              M<UInt32 *>(param_1 + 4) = puVar5;
              puVar8[2] = uVar4;
              *puVar5 = (UInt32)(param_1);
              puVar8[1] = (UInt32)(param_1);
              return 1;
            }
            M<UInt32 *>(param_1) = puVar7;
            M<UInt32 *>(param_1 + 4) = puVar5;
            *puVar5 = (UInt32)(param_1);
            puVar7[1] = (UInt32)(param_1);
            uVar1 = M<UInt32>(self + 0xc);
            puVar8[3] = 0;
            puVar8[1] = 0;
            puVar8[2] = 0;
            *puVar8 = uVar1;
            M<UInt32 *>(self + 0xc) = puVar8;
            return 1;
          }
          if (puVar7[2] == uVar4) {
            M<UInt32 *>(param_1) = puVar7;
            M<UInt32 *>(param_1 + 4) = puVar8;
            *puVar8 = (UInt32)(param_1);
            puVar7[1] = (UInt32)(param_1);
            return 1;
          }
          puVar5 = M<UInt32 *>(self + 0xc);
          M<UInt32>(self + 0xc) = *puVar5;
          *puVar5 = (UInt32)(puVar7);
          puVar7[1] = (UInt32)(puVar5);
          M<UInt32 *>(param_1) = puVar5;
          puVar5[1] = (UInt32)(param_1);
          puVar5[3] = 0x80000000;
          puVar5[2] = uVar4;
          *puVar8 = (UInt32)(param_1);
          M<UInt32 *>(param_1 + 4) = puVar8;
          return 1;
        }
      }
    }
  }
  return 0;
}
