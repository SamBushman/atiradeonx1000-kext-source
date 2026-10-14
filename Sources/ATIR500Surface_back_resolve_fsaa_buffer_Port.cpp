/*
 * ATIR500Surface_back_resolve_fsaa_buffer_Port.cpp
 *
 * ATIR500Surface::back_resolve_fsaa_buffer (real addr 0x44880, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x44880 */
void *ATIR500Surface::back_resolve_fsaa_buffer(UInt32 param_1, UInt32 param_2, UInt32*param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  UInt8 bVar5;
  UInt16 uVar6;
  UInt16 uVar7;
  UInt32 uVar8;
  float fVar9;
  float fVar10;
  double dVar11;
  UInt32 uVar12;
  SInt32 iVar13;
  UInt32 uVar14;
  UInt32 uVar15;
  UInt32 uVar16;
  SInt32 iVar17;
  SInt32 iVar18;
  
  iVar17 = M<SInt32>(self + param_2 * 4 + 0xb70);
  iVar18 = M<SInt32>(self + 0xb94);
  GH_memcpy(param_3,&g_r500_3d_blit_state_packet,0x2f4);
  uVar16 = 0;
  param_3[0xb] = M<UInt32>(M<SInt32>(self + 0xd50) + 0xb74);
  iVar13 = (UInt32)M<UInt8>(iVar18 + 0x3a) * 0x1c;
  param_3[0x9a] =
       (UInt32)M<UInt16>(iVar18 + 0x20) * M<SInt32>(iVar18 + 0x40) + M<SInt32>(iVar18 + 8) &
       0xffffffe0;
  if ((M<UInt32>(iVar18 + 0x3c) & 0xf00000) != 0) {
    uVar16 = (UInt32)M<UInt16>(iVar18 + 0x14) / (M<UInt32>(iVar18 + 0x3c) >> 0x14 & 0xf);
  }
  uVar14 = 0x20 / M<UInt16>(iVar18 + 0x16);
  if (uVar14 <= uVar16) {
    uVar14 = uVar16;
  }
  uVar12 = param_3[0x8a];
  param_3[0x9c] =
       uVar14 & 0x3ffe | (M<UInt8>(iVar18 + 0x38) & 1) << 0x10 |
       (M<UInt8>(iVar18 + 0x38) & 6) << 0x10 | (M<UInt8>(iVar18 + 0x39) & 3) << 0x13 |
       FormatTableLookup_0x0004d2e0((UInt32)M<UInt8>(iVar18 + 0x3a) * 0x1c) >> 1 & 0x1e00000;
  uVar16 = FormatTableLookup_0x0004d2e0(iVar13) >> 0x11 & 0x1f;
  param_3[0x8a] = uVar16 | uVar12 & 0xffffffe0;
  uVar14 = FormatTableLookup_0x0004d2e0(iVar13) >> 7 & 0x300;
  param_3[0x8a] = uVar14 | uVar16 | uVar12 & 0xfffffce0;
  uVar15 = FormatTableLookup_0x0004d2e0(iVar13) >> 3 & 0xc00;
  param_3[0x8a] = uVar15 | uVar14 | uVar16 | uVar12 & 0xfffff0e0;
  uVar8 = (FormatTableLookup_0x0004d2e0(iVar13) & 0x1800) << 1;
  param_3[0x8a] = uVar8 | uVar15 | uVar14 | uVar16 | uVar12 & 0xffffc0e0;
  param_3[0x8a] =
       (FormatTableLookup_0x0004d2e0(iVar13) & 0x600) << 5 |
       uVar8 | uVar15 | uVar14 | uVar16 | uVar12 & 0xffff00e0;
  if (((M<UInt32>(iVar18 + 0x3c) & 0xf00000) == 0) ||
     (uVar14 = (UInt32)M<UInt16>(iVar18 + 0x1c) / (M<UInt32>(iVar18 + 0x3c) >> 0x14 & 0xf),
     uVar16 = uVar14 - 1, uVar14 == 0)) {
    uVar16 = 0;
  }
  uVar14 = 0;
  if (M<UInt16>(iVar18 + 0x1e) != 0) {
    uVar14 = M<UInt16>(iVar18 + 0x1e) - 1;
  }
  param_3[0xb3] = uVar16 & 0x1fff | (uVar14 & 0x1fff) << 0xd;
  bVar5 = M<UInt8>(iVar17 + 0x3a);
  param_3[0xa0] =
       (M<UInt8>(iVar17 + 0x38) & 7) << 2 |
       (UInt32)M<UInt16>(iVar17 + 0x20) * M<SInt32>(iVar17 + 0x40) + M<SInt32>(iVar17 + 8) &
       0xffffffe0;
  if (((M<UInt32>(iVar17 + 0x3c) & 0xf00000) == 0) ||
     (uVar14 = (UInt32)M<UInt16>(iVar17 + 0x1c) / (M<UInt32>(iVar17 + 0x3c) >> 0x14 & 0xf),
     uVar16 = uVar14 - 1, uVar14 == 0)) {
    uVar16 = 0;
  }
  uVar14 = 0;
  if (M<UInt16>(iVar17 + 0x1e) != 0) {
    uVar14 = M<UInt16>(iVar17 + 0x1e) - 1;
  }
  param_3[0xa6] = uVar16 & 0x7ff | (uVar14 & 0x7ff) << 0xb | 0x80000000;
  uVar16 = FormatTableLookup_0x0004d2e4((UInt32)bVar5 * 0x1c);
  param_3[0xa8] =
       uVar16 >> 0x13 & 0x1f | (uVar16 & 0x40) << 0x10 | uVar16 >> 7 & 0xe00 | uVar16 >> 1 & 0x7000
       | (uVar16 & 0x1c00) << 5 | (uVar16 & 0x380) << 0xb;
  uVar16 = M<UInt32>(iVar17 + 0x3c);
  bVar1 = (uVar16 & 0xf00000) == 0;
  if (bVar1) {
    uVar14 = 0;
  }
  else {
    uVar14 = (UInt32)M<UInt16>(iVar17 + 0x14) / (uVar16 >> 0x14 & 0xf);
  }
  uVar15 = 0x20 / M<UInt16>(iVar17 + 0x16);
  if (uVar15 <= uVar14) {
    uVar15 = uVar14;
  }
  if ((bVar1) ||
     (uVar14 = (UInt32)M<UInt16>(iVar17 + 0x1c) / (uVar16 >> 0x14 & 0xf), uVar16 = uVar14 - 1,
     uVar14 == 0)) {
    uVar16 = 0;
  }
  uVar14 = 0;
  if (M<UInt16>(iVar17 + 0x1e) != 0) {
    uVar14 = M<UInt16>(iVar17 + 0x1e) - 1;
  }
  param_3[0xaa] = uVar15 - 1 & 0x3fff | (uVar16 & 0x800) << 4 | (uVar14 & 0x800) << 5;
  if ((M<UInt32>(self + 0xbe8) & 0x700000) != 0) {
    param_3[0xf] = 0xc0001000;
  }
  dVar11 = DOUBLE_0004c3a8;
  fVar10 = FLOAT_0004c380;
  fVar9 = FLOAT_0004c37c;
  fVar4 = FLOAT_0004c370;
  uVar16 = M<UInt32>(iVar18 + 0x3c);
  if ((uVar16 & 0xf00000) == 0) {
    uVar6 = M<UInt16>(iVar18 + 0x1e);
    param_3[0xc5] = 0x10031;
    param_3[0xc0] = 0x3f800000;
    param_3[0xbd] = 0x31080;
    param_3[200] = 0;
    param_3[0xbf] = 0x3f800000;
    fVar10 = FLOAT_0004c370;
    param_3[0xc2] = 0x1087;
    dVar11 = DOUBLE_0004c3b0;
    param_3[0xc4] = 0xc0033500;
    param_3[0xbe] = (UInt32)fVar10;
    param_3[0xc1] = (UInt32)fVar10;
    param_3[0xc6] = (UInt32)fVar10;
    fVar4 = (float)((double)CONCAT44d(0x43300000,(UInt32)uVar6) - dVar11);
    fVar9 = fVar4 * FLOAT_0004c37c;
    param_3[199] = (UInt32)((fVar4 + fVar10) * FLOAT_0004c380);
    param_3[0xc3] = (SInt32)fVar9;
  }
  else {
    uVar6 = M<UInt16>(iVar18 + 0x1c);
    uVar7 = M<UInt16>(iVar18 + 0x1e);
    param_3[0xbd] = 0x31080;
    param_3[0xc0] = 0x3f800000;
    param_3[0xc2] = 0x1087;
    param_3[0xc4] = 0xc0033500;
    param_3[0xc5] = 0x10031;
    param_3[200] = 0;
    param_3[0xbe] = (UInt32)fVar4;
    param_3[0xbf] = 0x3f800000;
    param_3[0xc1] = (UInt32)fVar4;
    fVar2 = (float)((double)CONCAT44d(0x43300000,(UInt32)uVar6 / (uVar16 >> 0x14 & 0xf) ^ 0x80000000) -
                   dVar11);
    fVar3 = (float)((double)CONCAT44d(0x43300000,(UInt32)uVar7) - DOUBLE_0004c3b0);
    param_3[0xc6] = (UInt32)((fVar2 + fVar4) * fVar10);
    param_3[199] = (UInt32)((fVar3 + fVar4) * fVar10);
    param_3[0xc3] = (SInt32)(fVar2 * fVar9) << 0x10 | (SInt32)(fVar3 * fVar9);
  }
  param_3[0xc9] = 0x1393;
  param_3[0xca] = 10;
  M<UInt32>(M<SInt32>(self + 0xd50) + 0x78) = 0;
  return (void *)(param_3 + 0xcb);
}
