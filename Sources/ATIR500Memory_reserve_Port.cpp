/*
 * ATIR500Memory_reserve_Port.cpp
 *
 * ATIR500Memory::reserve (real addr 0x19270, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x19270 */
UInt32 ATIR500Memory::reserve(GLKMemoryElement *real_param_1, UInt32 param_2, UInt32 param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt32 *puVar1;
  SInt32 iVar2;
  UInt32 uVar3;
  SInt32 *piVar4;
  SInt32 *piVar5;
  
  if ((M<SInt32>(self + 0xc) != 0) || (iVar2 = this->add_to_stack(), iVar2 != 0)) {
    uVar3 = param_2 + param_3;
    piVar4 = *(SInt32 **)*M<UInt32 *>(self + 8);
joined_r0x000192c4:
    if (piVar4 != (SInt32 *)0x0) {
      while (piVar5 = piVar4, piVar5[3] < 0) {
        piVar4 = (SInt32 *)*piVar5;
        if (param_2 < (UInt32)piVar5[2]) goto joined_r0x000192c4;
        if (uVar3 <= (UInt32)piVar4[2]) {
          M<UInt32>(param_1 + 8) = param_2;
          puVar1 = (UInt32 *)piVar5[1];
          M<UInt32>(param_1 + 0xc) = 0;
          if (param_2 != piVar5[2]) {
            if (piVar4[2] == uVar3) {
              M<SInt32 *>(param_1) = piVar4;
              M<SInt32 *>(param_1 + 4) = piVar5;
              *piVar5 = (SInt32)param_1;
              piVar4[1] = (SInt32)param_1;
              return 1;
            }
            puVar1 = M<UInt32 *>(self + 0xc);
            M<UInt32>(self + 0xc) = *puVar1;
            *puVar1 = (UInt32)(piVar4);
            piVar4[1] = (SInt32)puVar1;
            M<UInt32 *>(param_1) = puVar1;
            puVar1[1] = (UInt32)(param_1);
            puVar1[3] = 0x80000000;
            puVar1[2] = uVar3;
            *piVar5 = (SInt32)param_1;
            M<SInt32 *>(param_1 + 4) = piVar5;
            return 1;
          }
          if (uVar3 == piVar4[2]) {
            M<SInt32 *>(param_1) = piVar4;
            M<UInt32 *>(param_1 + 4) = puVar1;
            *puVar1 = (UInt32)(param_1);
            piVar4[1] = (SInt32)param_1;
            iVar2 = M<SInt32>(self + 0xc);
            piVar5[3] = 0;
            piVar5[1] = 0;
            piVar5[2] = 0;
            *piVar5 = iVar2;
            M<SInt32 *>(self + 0xc) = piVar5;
            return 1;
          }
          M<SInt32 *>(param_1) = piVar5;
          M<UInt32 *>(param_1 + 4) = puVar1;
          piVar5[2] = uVar3;
          *puVar1 = (UInt32)(param_1);
          piVar5[1] = (SInt32)param_1;
          return 1;
        }
      }
      piVar4 = (SInt32 *)*piVar5;
      goto joined_r0x000192c4;
    }
  }
  return 0;
}
