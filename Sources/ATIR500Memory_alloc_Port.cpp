/*
 * ATIR500Memory_alloc_Port.cpp
 *
 * ATIR500Memory::alloc (real addr 0x19430, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x19430 */
UInt32 ATIR500Memory::alloc(GLKMemoryElement *real_param_1, UInt32 param_2, UInt32 param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt32 uVar1;
  UInt32 *puVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  UInt32 uVar5;
  UInt32 uVar6;
  UInt32 *puVar7;
  UInt32 *puVar8;
  UInt32 uVar9;
  
  uVar9 = 0;
  if (param_3 != 0) {
    uVar9 = param_3 - 1;
  }
  if (((M<SInt32>(self + 0xc) == 0) && (iVar3 = this->add_to_stack(), iVar3 == 0)) ||
     (*(UInt32 **)*M<UInt32 *>(self + 8) == (UInt32 *)0x0)) {
LAB_000195bc:
    uVar4 = 0;
  }
  else {
    puVar7 = *(UInt32 **)*M<UInt32 *>(self + 8);
    do {
      while (puVar8 = puVar7, -1 < (SInt32)puVar8[3]) {
        puVar7 = (UInt32 *)*puVar8;
        if ((UInt32 *)*puVar8 == (UInt32 *)0x0) goto LAB_000195bc;
      }
      puVar7 = (UInt32 *)*puVar8;
      uVar6 = uVar9 + puVar8[2] & ~uVar9;
      uVar5 = param_2 + uVar6;
    } while ((UInt32)puVar7[2] < uVar5);
    M<UInt32>(param_1 + 8) = uVar6;
    M<UInt32>(param_1 + 0xc) = uVar9 & 0xffff;
    puVar2 = (UInt32 *)puVar8[1];
    if (puVar8[2] == uVar6) {
      if (uVar5 == puVar7[2]) {
        M<UInt32 *>(param_1) = puVar7;
        M<UInt32 *>(param_1 + 4) = puVar2;
        uVar4 = 1;
        *puVar2 = (UInt32)(param_1);
        puVar7[1] = (UInt32)(param_1);
        uVar1 = M<UInt32>(self + 0xc);
        puVar8[3] = 0;
        puVar8[1] = 0;
        puVar8[2] = 0;
        *puVar8 = uVar1;
        M<UInt32 *>(self + 0xc) = puVar8;
      }
      else {
        uVar4 = 1;
        M<UInt32 *>(param_1) = puVar8;
        M<UInt32 *>(param_1 + 4) = puVar2;
        puVar8[2] = uVar5;
        *puVar2 = (UInt32)(param_1);
        puVar8[1] = (UInt32)(param_1);
      }
    }
    else if (puVar7[2] == uVar5) {
      uVar4 = 1;
      M<UInt32 *>(param_1) = puVar7;
      M<UInt32 *>(param_1 + 4) = puVar8;
      *puVar8 = (UInt32)(param_1);
      puVar7[1] = (UInt32)(param_1);
    }
    else {
      puVar2 = M<UInt32 *>(self + 0xc);
      uVar4 = 1;
      M<UInt32>(self + 0xc) = *puVar2;
      *puVar2 = (UInt32)(puVar7);
      puVar7[1] = (UInt32)(puVar2);
      M<UInt32 *>(param_1) = puVar2;
      puVar2[1] = (UInt32)(param_1);
      puVar2[3] = 0x80000000;
      puVar2[2] = uVar5;
      *puVar8 = (UInt32)(param_1);
      M<UInt32 *>(param_1 + 4) = puVar8;
    }
  }
  return uVar4;
}
