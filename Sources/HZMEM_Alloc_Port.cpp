/*
 * HZMEM_Alloc_Port.cpp
 *
 * HZMEM_Alloc (real addr 0x45350, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x45350 */
UInt32 HZMEM_Alloc(_HZDATA *real_param_1, UInt32 param_2, UInt32 param_3, UInt32 param_4, UInt32 param_5) {
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  SInt32 iVar1;
  SInt32 iVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  SInt32 *piVar5;
  SInt32 iVar6;
  UInt8 *puVar7;
  UInt32 uVar8;
  SInt32 *piVar9;
  UInt32 uVar10;
  UInt32 uVar11;
  SInt32 iVar12;
  UInt32 uVar13;
  UInt32 uVar14;
  SInt32 iVar15;
  
  if (param_1 == (UInt8 *)0x0) {
    return 0xffffffff;
  }
  iVar1 = param_3 * 4;
  piVar9 = M<SInt32 *>(param_1 + iVar1 + 0x10);
  if (piVar9 == (SInt32 *)0x0) {
    return 0xffffffff;
  }
  if (2 < param_3) {
    return 0xffffffff;
  }
  uVar11 = M<UInt32>(param_1 + 4);
  if (param_4 != (param_4 / uVar11) * uVar11) {
    return 0xffffffff;
  }
  uVar4 = M<UInt32>(param_1 + 8);
  if (param_5 != (param_5 / uVar4) * uVar4) {
    return 0xffffffff;
  }
  if ((uVar11 == 0) || (uVar4 == 0)) {
    uVar11 = 0;
  }
  else {
    uVar11 = (param_4 / uVar11) * (param_5 / uVar4);
  }
  uVar4 = piVar9[1];
  uVar13 = piVar9[2];
  iVar2 = uVar11 - (uVar11 / uVar4) * uVar4;
  if (iVar2 != 0) {
    uVar11 = uVar4 + (uVar11 - iVar2);
  }
  if (uVar4 == 0) {
    uVar11 = 0;
  }
  else {
    uVar11 = uVar11 / uVar4;
  }
  if ((UInt32)piVar9[4] < 0x100) {
    piVar5 = piVar9 + 5;
    uVar8 = 0;
    iVar2 = 0x100;
    do {
      if (*piVar5 == 0) {
        iVar2 = *piVar9;
        uVar14 = uVar11;
        if (iVar2 == 0) goto LAB_000454ac;
        uVar10 = 0;
        iVar3 = 0;
        iVar12 = 0;
        goto LAB_00045460;
      }
      uVar8 = uVar8 + 1;
      piVar5 = piVar5 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  goto LAB_00045438;
code_r0x00045488:
  iVar12 = iVar12 + 1;
  iVar2 = iVar2 + -1;
  if (iVar2 == 0) goto LAB_000454ac;
LAB_00045460:
  uVar10 = uVar10 + 1;
  if (M<char>(iVar12 + piVar9[3]) == '\x01') {
    iVar3 = iVar12 + 1;
    uVar10 = 0;
  }
  if (uVar10 != uVar11) goto code_r0x00045488;
  if (uVar11 != 0) {
    puVar7 = (UInt8 *)(iVar3 + piVar9[3]);
    uVar10 = uVar11;
    do {
      *puVar7 = 1;
      puVar7 = puVar7 + 1;
      uVar10 = uVar10 - 1;
    } while (uVar10 != 0);
  }
  if (iVar3 != -1) {
    iVar3 = uVar4 * iVar3;
LAB_00045584:
    piVar9[uVar8 * 4 + 6] = iVar3;
    piVar9[uVar8 * 4 + 8] = uVar11 * uVar4;
    piVar9[uVar8 * 4 + 7] = uVar4 * uVar14;
    piVar9[uVar8 * 4 + 5] = 1;
    M<SInt32>(M<SInt32>(param_1 + iVar1 + 0x10) + 0x10) =
         M<SInt32>(M<SInt32>(param_1 + iVar1 + 0x10) + 0x10) + 1;
    goto LAB_0004543c;
  }
LAB_000454ac:
  piVar5 = M<SInt32 *>(param_1 + iVar1 + 0x10);
  if (((piVar5 == (SInt32 *)0x0) || (iVar2 = piVar5[3], iVar2 == 0)) || (iVar12 = *piVar5, iVar12 < 1))
  {
    iVar3 = 0;
    goto LAB_00045584;
  }
  iVar3 = iVar12 + -1;
  if (M<char>(iVar2 + iVar3) != '\0') goto LAB_00045438;
  iVar6 = iVar12 + -2;
  if ((iVar6 < 0) || (M<char>(iVar2 + iVar6) == '\x01')) {
    uVar14 = 1;
  }
  else {
    uVar14 = 2;
    if (2 < uVar11) {
      iVar6 = iVar2 + iVar6;
      iVar15 = iVar3;
      do {
        iVar3 = iVar3 + -1;
        iVar15 = iVar15 + -1;
        if ((iVar15 == 0) || (M<char>(iVar6 + -1) == '\x01')) break;
        uVar14 = uVar14 + 1;
        iVar6 = iVar6 + -1;
      } while (uVar14 != uVar11);
    }
  }
  if ((iVar3 != -1) && (uVar4 * (iVar3 + uVar11) <= uVar13)) {
    if (iVar3 < iVar12) {
      iVar12 = iVar12 - iVar3;
      puVar7 = (UInt8 *)(iVar3 + iVar2);
      do {
        *puVar7 = 1;
        puVar7 = puVar7 + 1;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
    }
    iVar3 = uVar4 * iVar3;
    goto LAB_00045584;
  }
LAB_00045438:
  uVar8 = 0xffffffff;
LAB_0004543c:
  if (param_3 == 1) {
    return param_2 & 0x3ff | (uVar8 & 0x3ff) << 10 | param_2 & 0x3ff00000;
  }
  if (param_3 != 0) {
    if (param_3 != 2) {
      return 0xffffffff;
    }
    return param_2 & 0xfffff | (uVar8 & 0x3ff) << 0x14;
  }
  return uVar8 & 0x3ff | param_2 & 0xffc00 | param_2 & 0x3ff00000;
}
