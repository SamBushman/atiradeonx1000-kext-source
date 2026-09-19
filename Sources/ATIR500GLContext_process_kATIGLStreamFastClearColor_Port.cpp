/*
 * ATIR500GLContext_process_kATIGLStreamFastClearColor_Port.cpp
 *
 * ATIR500GLContext::process_kATIGLStreamFastClearColor (real addr 0x292a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x292a0 */
void ATIR500GLContext::process_kATIGLStreamFastClearColor(UInt32*param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 bVar1;
  UInt16 uVar2;
  UInt32 uVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  UInt32 uVar6;
  SInt32 iVar7;
  SInt32 iVar8;
  SInt32 iVar9;
  SInt32 iVar10;
  SInt32 iVar11;
  UInt32 uVar12;
  SInt32 iVar13;
  UInt32 uVar14;
  UInt32 uVar15;
  UInt32 uVar16;
  UInt32 uVar17;
  SInt32 iVar18;
  
  uVar17 = param_1[1];
  iVar9 = M<SInt32>(self + 0x290);
  uVar16 = M<UInt32>(self + 0x29c);
  iVar7 = M<SInt32>(self + 0x298);
  iVar5 = M<SInt32>((UInt32)M<UInt16>(self + 0xac) * 4 + iVar9 + 0xb70);
  iVar13 = (UInt32)M<UInt16>(self + 0xae) * 0x78 + iVar9;
  iVar18 = M<SInt32>((UInt32)M<UInt16>(self + 0xae) * 4 + iVar9 + 0xb70);
  iVar10 = uVar16 * 4 + iVar5;
  uVar2 = M<UInt16>(iVar5 + 0x20);
  uVar14 = 0x10;
  iVar9 = M<SInt32>(iVar10 + 0x40);
  iVar10 = M<SInt32>(iVar10 + 0x44);
  iVar11 = M<SInt32>(iVar5 + 8);
  iVar8 = (SInt32)(UInt32)M<UInt16>(iVar5 + 0x1e) >> (uVar16 & 0x3f);
  if (iVar8 != 0) {
    uVar14 = iVar8 + 0xf;
  }
  uVar12 = 0;
  iVar8 = (UInt32)M<UInt8>(iVar5 + 0x3a) * 0x1c;
  if ((M<UInt32>(iVar5 + 0x3c) & 0xf00000) != 0) {
    uVar12 = (SInt32)((UInt32)M<UInt16>(iVar5 + 0x14) / (M<UInt32>(iVar5 + 0x3c) >> 0x14 & 0xf)) >>
             (uVar16 & 0x3f);
  }
  uVar16 = 0x20 / M<UInt16>(iVar5 + 0x16);
  if (uVar16 <= uVar12) {
    uVar16 = uVar12;
  }
  bVar1 = M<UInt8>(iVar5 + 0x38);
  uVar12 = FormatTableLookup_0x0004d2dc(iVar8);
  uVar15 = FormatTableLookup_0x0004d2e0(iVar8);
  *param_1 = 0x13c8;
  uVar6 = 0;
  uVar12 = (uVar12 & 0xc00) << 9;
  uVar15 = uVar15 >> 1 & 0x1e00000;
  uVar4 = (uVar16 & 0x3ffe) >> 1;
  uVar3 = uVar15 | uVar12 | uVar16 & 0x3ffe;
  param_1[1] = iVar9 * (UInt32)uVar2 + (iVar10 - iVar9) * iVar7 + iVar11 +
               (uVar14 & 0xfffffff0) * uVar4 * 4;
  param_1[7] = uVar3;
  param_1[3] = uVar3;
  param_1[5] = (((uVar14 & 0xfffffff0) >> 1) - 1) * 0x2000 & 0x3ffe000 | uVar4 * 2 - 1 & 0x1fff;
  param_1[uVar17] = M<UInt32>(iVar13 + 0xb0);
  if ((M<UInt32>(iVar18 + 0x3c) & 0xf00000) != 0) {
    uVar6 = (UInt32)M<UInt16>(iVar18 + 0x14) / (M<UInt32>(iVar18 + 0x3c) >> 0x14 & 0xf);
  }
  uVar14 = 0x20 / M<UInt16>(iVar18 + 0x16);
  if (uVar14 <= uVar6) {
    uVar14 = uVar6;
  }
  param_1[uVar17 + 2] =
       (M<UInt8>(iVar18 + 0x38) & 6) << 0x10 |
       (M<UInt8>(iVar18 + 0x38) & 1) << 0x10 |
       (M<UInt8>(iVar18 + 0x39) & 3) << 0x13 | uVar14 & 0x3ffc;
  param_1[uVar17 + 4] =
       uVar15 | uVar12 | (bVar1 & 6) << 0x10 | (bVar1 & 1) << 0x10 | uVar16 & 0x3ffe;
  param_1[uVar17 + 6] = -(M<UInt8>(iVar13 + 0xe2) ^ 0x10) >> 0x1e & 2;
  return;
}
