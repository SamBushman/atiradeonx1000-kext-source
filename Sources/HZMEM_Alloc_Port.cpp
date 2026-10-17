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
UInt32 HZMEM_Alloc(_HZDATA *hizData, UInt32 surfaceHzField, UInt32 blockKind, UInt32 tileDim, UInt32 size) {
    UInt8 *hizDataBytes = reinterpret_cast<UInt8 *>(hizData);

  SInt32 kindOffset;
  SInt32 iVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  SInt32 *piVar5;
  SInt32 iVar6;
  UInt8 *puVar7;
  UInt32 blockSlot;
  SInt32 *pool;
  UInt32 uVar10;
  UInt32 uVar11;
  SInt32 iVar12;
  UInt32 poolLimit;
  UInt32 uVar14;
  SInt32 iVar15;
  
  if (hizDataBytes == (UInt8 *)0x0) {
    return 0xffffffff;
  }
  kindOffset = blockKind * 4;
  pool = M<SInt32 *>(hizDataBytes + kindOffset + 0x10);
  if (pool == (SInt32 *)0x0) {
    return 0xffffffff;
  }
  if (2 < blockKind) {
    return 0xffffffff;
  }
  uVar11 = M<UInt32>(hizDataBytes + 4);
  if (tileDim != (tileDim / uVar11) * uVar11) {
    return 0xffffffff;
  }
  uVar4 = M<UInt32>(hizDataBytes + 8);
  if (size != (size / uVar4) * uVar4) {
    return 0xffffffff;
  }
  if ((uVar11 == 0) || (uVar4 == 0)) {
    uVar11 = 0;
  }
  else {
    uVar11 = (tileDim / uVar11) * (size / uVar4);
  }
  uVar4 = pool[1];
  poolLimit = pool[2];
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
  if ((UInt32)pool[4] < 0x100) {
    piVar5 = pool + 5;
    blockSlot = 0;
    iVar2 = 0x100;
    do {
      if (*piVar5 == 0) {
        iVar2 = *pool;
        uVar14 = uVar11;
        if (iVar2 == 0) goto LAB_000454ac;
        uVar10 = 0;
        iVar3 = 0;
        iVar12 = 0;
        goto LAB_00045460;
      }
      blockSlot = blockSlot + 1;
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
  if (M<char>(iVar12 + pool[3]) == '\x01') {
    iVar3 = iVar12 + 1;
    uVar10 = 0;
  }
  if (uVar10 != uVar11) goto code_r0x00045488;
  if (uVar11 != 0) {
    puVar7 = (UInt8 *)(iVar3 + pool[3]);
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
    pool[blockSlot * 4 + 6] = iVar3;
    pool[blockSlot * 4 + 8] = uVar11 * uVar4;
    pool[blockSlot * 4 + 7] = uVar4 * uVar14;
    pool[blockSlot * 4 + 5] = 1;
    M<SInt32>(M<SInt32>(hizDataBytes + kindOffset + 0x10) + 0x10) =
         M<SInt32>(M<SInt32>(hizDataBytes + kindOffset + 0x10) + 0x10) + 1;
    goto LAB_0004543c;
  }
LAB_000454ac:
  piVar5 = M<SInt32 *>(hizDataBytes + kindOffset + 0x10);
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
  if ((iVar3 != -1) && (uVar4 * (iVar3 + uVar11) <= poolLimit)) {
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
  blockSlot = 0xffffffff;
LAB_0004543c:
  if (blockKind == 1) {
    return surfaceHzField & 0x3ff | (blockSlot & 0x3ff) << 10 | surfaceHzField & 0x3ff00000;
  }
  if (blockKind != 0) {
    if (blockKind != 2) {
      return 0xffffffff;
    }
    return surfaceHzField & 0xfffff | (blockSlot & 0x3ff) << 0x14;
  }
  return blockSlot & 0x3ff | surfaceHzField & 0xffc00 | surfaceHzField & 0x3ff00000;
}
