/*
 * ATIR500Surface_resolve_fsaa_buffer_Port.cpp
 *
 * ATIR500Surface::resolve_fsaa_buffer (real addr 0x43e60, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_memcpy(...) asm("_memcpy");


/* real addr 0x43e60 */
void* ATIR500Surface::resolve_fsaa_buffer(UInt32 param_1, UInt32 param_2, UInt32*param_3, bool param_4, SInt32 param_5, SInt32 param_6, SInt32 param_7, SInt32 param_8) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  UInt8 bVar6;
  UInt16 uVar7;
  UInt32 uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  double dVar12;
  SInt32 iVar13;
  UInt32 uVar14;
  UInt32 uVar15;
  UInt32 uVar16;
  UInt32 uVar17;
  UInt32 in_register_0000001c;
  UInt32 uVar18;
  UInt32 uVar19;
  UInt32 *puVar20;
  SInt32 iVar21;
  SInt32 iVar22;
  UInt32 *puVar23;
  
  iVar22 = M<SInt32>(self + 0xb94);
  iVar21 = M<SInt32>(self + param_2 * 4 + 0xb70);
  GH_memcpy(param_3,&g_r500_3d_blit_state_packet,0x2f4);
  param_3[0xb] = M<UInt32>(M<SInt32>(self + 0xd50) + 0xb74);
  if ((M<UInt32>(self + 0xbe8) & 0x700000) == 0) {
    uVar18 = 0;
    iVar13 = (UInt32)M<UInt8>(iVar21 + 0x3a) * 0x1c;
    param_3[0x9a] =
         (UInt32)M<UInt16>(iVar21 + 0x20) * M<SInt32>(iVar21 + 0x40) + M<SInt32>(iVar21 + 8) &
         0xffffffe0;
    if ((M<UInt32>(iVar21 + 0x3c) & 0xf00000) != 0) {
      uVar18 = (UInt32)M<UInt16>(iVar21 + 0x14) / (M<UInt32>(iVar21 + 0x3c) >> 0x14 & 0xf);
    }
    uVar15 = 0x20 / M<UInt16>(iVar21 + 0x16);
    if (uVar15 <= uVar18) {
      uVar15 = uVar18;
    }
    uVar14 = param_3[0x8a];
    param_3[0x9c] =
         uVar15 & 0x3ffe | (M<UInt8>(iVar21 + 0x38) & 1) << 0x10 |
         (M<UInt8>(iVar21 + 0x38) & 6) << 0x10 | (M<UInt8>(iVar21 + 0x39) & 3) << 0x13 |
         FormatTableLookup_0x0004d2e0((UInt32)M<UInt8>(iVar21 + 0x3a) * 0x1c) >> 1 & 0x1e00000;
    uVar18 = FormatTableLookup_0x0004d2e0(iVar13) >> 0x11 & 0x1f;
    param_3[0x8a] = uVar18 | uVar14 & 0xffffffe0;
    uVar15 = FormatTableLookup_0x0004d2e0(iVar13) >> 7 & 0x300;
    param_3[0x8a] = uVar15 | uVar18 | uVar14 & 0xfffffce0;
    uVar16 = FormatTableLookup_0x0004d2e0(iVar13) >> 3 & 0xc00;
    param_3[0x8a] = uVar16 | uVar15 | uVar18 | uVar14 & 0xfffff0e0;
    uVar8 = (FormatTableLookup_0x0004d2e0(iVar13) & 0x1800) << 1;
    param_3[0x8a] = uVar8 | uVar16 | uVar15 | uVar18 | uVar14 & 0xffffc0e0;
    param_3[0x8a] =
         (FormatTableLookup_0x0004d2e0(iVar13) & 0x600) << 5 |
         uVar8 | uVar16 | uVar15 | uVar18 | uVar14 & 0xffff00e0;
    if (((M<UInt32>(iVar21 + 0x3c) & 0xf00000) == 0) ||
       (uVar15 = (UInt32)M<UInt16>(iVar21 + 0x1c) / (M<UInt32>(iVar21 + 0x3c) >> 0x14 & 0xf),
       uVar18 = uVar15 - 1, uVar15 == 0)) {
      uVar18 = 0;
    }
    uVar15 = 0;
    if (M<UInt16>(iVar21 + 0x1e) != 0) {
      uVar15 = M<UInt16>(iVar21 + 0x1e) - 1;
    }
    param_3[0xb3] = uVar18 & 0x1fff | (uVar15 & 0x1fff) << 0xd;
    bVar6 = M<UInt8>(iVar22 + 0x3a);
    param_3[0xa0] =
         (M<UInt8>(iVar22 + 0x38) & 7) << 2 |
         (UInt32)M<UInt16>(iVar22 + 0x20) * M<SInt32>(iVar22 + 0x40) + M<SInt32>(iVar22 + 8) &
         0xffffffe0;
    if (((M<UInt32>(iVar22 + 0x3c) & 0xf00000) == 0) ||
       (uVar15 = (UInt32)M<UInt16>(iVar22 + 0x1c) / (M<UInt32>(iVar22 + 0x3c) >> 0x14 & 0xf),
       uVar18 = uVar15 - 1, uVar15 == 0)) {
      uVar18 = 0;
    }
    uVar15 = 0;
    if (M<UInt16>(iVar22 + 0x1e) != 0) {
      uVar15 = M<UInt16>(iVar22 + 0x1e) - 1;
    }
    param_3[0xa6] = uVar18 & 0x7ff | (uVar15 & 0x7ff) << 0xb | 0x80000000;
    uVar18 = FormatTableLookup_0x0004d2e4((UInt32)bVar6 * 0x1c);
    param_3[0xa8] =
         uVar18 >> 0x13 & 0x1f | (uVar18 & 0x40) << 0x10 | uVar18 >> 7 & 0xe00 |
         uVar18 >> 1 & 0x7000 | (uVar18 & 0x1c00) << 5 | (uVar18 & 0x380) << 0xb;
    uVar18 = M<UInt32>(iVar22 + 0x3c);
    bVar1 = (uVar18 & 0xf00000) == 0;
    if (bVar1) {
      uVar15 = 0;
    }
    else {
      uVar15 = (UInt32)M<UInt16>(iVar22 + 0x14) / (uVar18 >> 0x14 & 0xf);
    }
    uVar16 = 0x20 / M<UInt16>(iVar22 + 0x16);
    if (uVar16 <= uVar15) {
      uVar16 = uVar15;
    }
    if ((bVar1) ||
       (uVar15 = (UInt32)M<UInt16>(iVar22 + 0x1c) / (uVar18 >> 0x14 & 0xf), uVar18 = uVar15 - 1,
       uVar15 == 0)) {
      uVar18 = 0;
    }
    uVar15 = 0;
    if (M<UInt16>(iVar22 + 0x1e) != 0) {
      uVar15 = M<UInt16>(iVar22 + 0x1e) - 1;
    }
    param_3[0xaa] = uVar16 - 1 & 0x3fff | (uVar18 & 0x800) << 4 | (uVar15 & 0x800) << 5;
    param_3[0x1e] = param_3[0x1e] & 0xfffffffc | 2;
    param_3[0xa2] = param_3[0xa2] & 0xffffe1ff | 0x1400;
    dVar12 = DOUBLE_0004c3a8;
    fVar11 = FLOAT_0004c380;
    fVar10 = FLOAT_0004c37c;
    fVar4 = FLOAT_0004c370;
    if (M<UInt16>(iVar21 + 0x1c) != 0) {
      fVar4 = FLOAT_0004c374 /
              (float)((double)CONCAT44d(0x43300000,M<UInt16>(iVar21 + 0x1c) ^ 0x80000000) -
                     DOUBLE_0004c3a8);
    }
    fVar9 = FLOAT_0004c370;
    if (M<UInt16>(iVar21 + 0x1e) != 0) {
      fVar9 = FLOAT_0004c374 /
              (float)((double)CONCAT44d(0x43300000,M<UInt16>(iVar21 + 0x1e) ^ 0x80000000) -
                     DOUBLE_0004c3a8);
    }
    puVar20 = param_3 + 0xcb;
    param_3[0xc2] = 0x1087;
    param_3[0xc4] = 0xc0033500;
    param_3[0xbd] = 0x31080;
    param_3[200] = 0;
    param_3[0xc5] = 0x10031;
    param_3[0xc9] = 0x1393;
    param_3[0xca] = 10;
    fVar2 = (float)((double)CONCAT44d(0x43300000,param_5 ^ 0x80000000) - dVar12);
    fVar3 = (float)((double)CONCAT44d(0x43300000,param_5 + param_7 ^ 0x80000000) - dVar12);
    param_3[0xc0] = (UInt32)(fVar4 * fVar3);
    param_3[0xbe] = (UInt32)(fVar4 * fVar2);
    param_3[0xc6] = (UInt32)((fVar2 + fVar3) * fVar11);
    fVar4 = (float)((double)CONCAT44d(0x43300000,param_6 + param_8 ^ 0x80000000) - dVar12);
    fVar5 = (float)((double)CONCAT44d(0x43300000,param_6 ^ 0x80000000) - dVar12);
    param_3[0xbf] = (UInt32)(fVar9 * fVar4);
    param_3[0xc1] = (UInt32)(fVar9 * fVar5);
    param_3[199] = (UInt32)((fVar5 + fVar4) * fVar11);
    param_3[0xc3] = (SInt32)((fVar3 - fVar2) * fVar10) << 0x10 | (SInt32)((fVar4 - fVar5) * fVar10);
    goto LAB_0004481c;
  }
  uVar18 = 0;
  param_3[0xa9] = 0xc0001000;
  param_3[0x9d] = 0xc0001000;
  param_3[0x9f] = 0xc0001000;
  param_3[0xa1] = 0xc0001000;
  param_3[0xa3] = 0xc0001000;
  param_3[0xa5] = 0xc0001000;
  param_3[0xa7] = 0xc0001000;
  param_3[0x9a] = M<UInt32>(iVar22 + 8);
  if ((M<UInt32>(iVar22 + 0x3c) & 0xf00000) != 0) {
    uVar18 = (UInt32)M<UInt16>(iVar22 + 0x14) / (M<UInt32>(iVar22 + 0x3c) >> 0x14 & 0xf);
  }
  uVar15 = 0x20 / M<UInt16>(iVar22 + 0x16);
  if (uVar15 <= uVar18) {
    uVar15 = uVar18;
  }
  param_3[0x9c] =
       uVar15 & 0x3ffe | (M<UInt8>(iVar21 + 0x38) & 1) << 0x10 |
       (M<UInt8>(iVar21 + 0x38) & 6) << 0x10 | (M<UInt8>(iVar22 + 0x39) & 3) << 0x13 |
       FormatTableLookup_0x0004d2e0((UInt32)M<UInt8>(iVar22 + 0x3a) * 0x1c) >> 1 & 0x1e00000;
  if (((M<UInt32>(iVar22 + 0x28) & 0x3ff00000) == 0x3ff00000) || (M<char>(iVar22 + 0x36) == '\0'))
  {
    param_3[0x20] = 0;
  }
  else {
    param_3[0x20] = 0x600;
  }
  uVar18 = M<UInt32>(iVar22 + 0x3c);
  param_3[0x3c] = 0;
  param_3[0x42] = param_3[0x4e];
  param_3[0x26] = 0;
  param_3[0x44] = param_3[0x50];
  param_3[0x46] = param_3[0x52];
  uVar18 = SamplesTableLookup(uVar18 >> 0x12 & 0x3c);
  param_3[0x48] = param_3[0x54];
  param_3[0x4a] = param_3[0x56];
  param_3[0x4c] = param_3[0x58];
  param_3[0x7e] = 0;
  param_3[0x86] = 0;
  param_3[0x24] = 3;
  param_3[0x84] = 0;
  param_3[0x88] = 0;
  param_3[0x82] = 0;
  param_3[0x92] = 0x80;
  param_3[0x98] = 0x50000000;
  param_3[0x10] = (uVar18 & 3) << 1 | 1;
  param_3[0x96] = 0x10000;
  if (((M<UInt32>(iVar21 + 0x3c) & 0xf00000) == 0) ||
     (uVar15 = (UInt32)M<UInt16>(iVar21 + 0x1c) / (M<UInt32>(iVar21 + 0x3c) >> 0x14 & 0xf),
     uVar18 = uVar15 - 1, uVar15 == 0)) {
    uVar18 = 0;
  }
  uVar15 = 0;
  if (M<UInt16>(iVar21 + 0x1e) != 0) {
    uVar15 = M<UInt16>(iVar21 + 0x1e) - 1;
  }
  param_3[0xb3] = uVar18 & 0x1fff | (uVar15 & 0x1fff) << 0xd;
  uVar17 = HZMEM_GetBlockOffset
                     ((_HZDATA *)((UInt8 *)(M<SInt32>(self + 0xd50) + 0x870)),M<UInt32>(iVar22 + 0x28),2);
  uVar18 = 0;
  if ((M<UInt32>(iVar22 + 0x3c) & 0xf00000) != 0) {
    uVar18 = (UInt32)M<UInt16>(iVar22 + 0x14) / (M<UInt32>(iVar22 + 0x3c) >> 0x14 & 0xf);
  }
  uVar15 = 0x20 / M<UInt16>(iVar22 + 0x16);
  if (uVar15 <= uVar18) {
    uVar15 = uVar18;
  }
  iVar13 = 0x20;
  if (M<SInt32>(M<SInt32>(self + 0xd50) + 0xb98) == 4) {
LAB_00044100:
    uVar19 = iVar13 * ((SInt32)(iVar13 + uVar15 + -1) / iVar13);
  }
  else {
    iVar13 = M<SInt32>(M<SInt32>(self + 0xd50) + 0xb98) << 4;
    uVar19 = 0;
    if (iVar13 != 0) goto LAB_00044100;
  }
  param_3[0xc0] = uVar19;
  param_3[0xbe] = uVar17;
  param_3[0xbd] = 0x1395;
  param_3[0xbf] = 0x1399;
  param_3[0xc1] = 0x13a2;
  param_3[0xc2] = 5;
  param_3[0xc3] = 0x13a0;
  puVar20 = param_3 + 0xc9;
  uVar18 = M<UInt32>(iVar21 + 8);
  param_3[0xc5] = 0x13a1;
  param_3[0xc4] = uVar18 & 0xffffffe0;
  uVar7 = M<UInt16>(iVar21 + 0x14);
  param_3[199] = 0x1087;
  param_3[200] = param_7 * 0x60000 | param_8 * 6 & 0xffffU;
  param_3[0xc6] = uVar7 & 0x3ffe;
  if ((((M<UInt32>(iVar22 + 0x28) & 0x3ff00000) != 0x3ff00000) && (M<char>(iVar22 + 0x36) != '\0')
      ) && (M<UInt8>(iVar21 + 0x38) < 2)) {
    puVar20 = param_3 + 0xcb;
    param_3[0xc9] = 0x1392;
    param_3[0xca] = 0x400300;
  }
  dVar12 = DOUBLE_0004c3a8;
  fVar4 = FLOAT_0004c380;
  puVar23 = puVar20 + 0xb;
  *puVar20 = 0xc0033500;
  puVar20[1] = 0x10031;
  puVar20[2] = (UInt32)((float)((double)CONCAT44d(0x43300000,param_7 + param_5 * 2 ^ 0x80000000) -
                              dVar12) * fVar4);
  puVar20[4] = 0;
  puVar20[3] = (UInt32)((float)((double)CONCAT44d(0x43300000,param_8 + param_6 * 2 ^ 0x80000000) -
                              dVar12) * fVar4);
  puVar20[5] = 0x1393;
  puVar20[6] = 10;
  puVar20[7] = 0x13c6;
  puVar20[8] = 3;
  puVar20[9] = 0x13a2;
  puVar20[10] = 0;
  if ((((M<UInt32>(iVar22 + 0x28) & 0x3ff00000) != 0x3ff00000) && (M<char>(iVar22 + 0x36) != '\0')
      ) && (M<UInt8>(iVar21 + 0x38) < 2)) {
    puVar23 = puVar20 + 0xd;
    puVar20[0xb] = 0x1392;
    puVar20[0xc] = 0x300;
  }
  puVar20 = puVar23;
  if ((((UInt32)param_4) != 0) &&
     ((M<UInt32>(iVar22 + 0x28) & 0x3ff00000) != 0x3ff00000)) {
    uVar18 = HZMEM_GetBlockCount((_HZDATA *)((UInt8 *)(M<SInt32>(self + 0xd50) + 0x870)),
                                 M<UInt32>(iVar22 + 0x28),2);
    *puVar23 = 0x1385;
    puVar20 = puVar23 + 6;
    uVar19 = M<UInt32>(iVar22 + 0x30);
    puVar23[2] = 0xc0023800;
    puVar23[3] = uVar17;
    puVar23[1] = uVar19;
    iVar21 = M<SInt32>(M<SInt32>(self + 0xd50) + 0xb98);
    puVar23[5] = 0;
    puVar23[4] = uVar18 / (UInt32)(iVar21 << 4);
    if (param_1 == 9) {
      puVar23[6] = 0x1380;
      puVar23[7] = 0x600;
      puVar20 = puVar23 + 8;
    }
    M<UInt8>(iVar22 + 0x36) = 1;
  }
LAB_0004481c:
  M<UInt32>(M<SInt32>(self + 0xd50) + 0x78) = 0;
  return puVar20;
}
