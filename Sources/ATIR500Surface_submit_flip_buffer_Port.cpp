/*
 * ATIR500Surface_submit_flip_buffer_Port.cpp
 *
 * ATIR500Surface::submit_flip_buffer (real addr 0x3e5c0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3e5c0 */
void ATIR500Surface::submit_flip_buffer(UInt32 param_2, IOATIR500GLContext *real_param_3, UInt32 param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_3 = reinterpret_cast<UInt8 *>(real_param_3);

  bool bVar1;
  bool bVar2;
  UInt8 bVar3;
  UInt16 uVar4;
  UInt16 uVar5;
  int iVar6;
  SInt16 sVar7;
  int iVar8;
  UInt32 *puVar9;
  unsigned int uVar10;
  int iVar11;
  int iVar12;
  unsigned int uVar13;
  UInt32 uVar14;
  unsigned int uVar15;
  unsigned int uVar16;
  int iVar17;
  UInt32 *puVar18;
  int iVar19;
  UInt32 uVar20;
  UInt32 uVar21;
  unsigned int uVar22;
  UInt8 *pVVar23;
  int *piVar24;
  UInt8 *pAccel;
  
  if (M<SInt16>(self + 0xdb4) != 0) {
    M<UInt32>(M<int>(self + 0xd50) + 0x78) = 0;
  }
  if (M<UInt32>(self + 0xd54) != (UInt32)param_3) {
    M<UInt32>(self + 0xd54) = (UInt32)param_3;
    iVar17 = M<int>((int)param_2 * 0x94 + self + 0xc34);
    M<unsigned int>(iVar17 + 0x1c) = M<unsigned int>(iVar17 + 0x1c) | 1;
  }
  iVar11 = (int)param_2 * 0x94;
  iVar17 = iVar11 + (SInt32)self;
  if ((M<unsigned int>(M<int>(iVar17 + 0xc34) + 0x1c) & 1) == 0) {
    iVar11 = (unsigned int)M<UInt16>(iVar17 + 0xcae) * 0x1c + iVar11 + (SInt32)self;
    pVVar23 = (UInt8 *)(iVar11 + 0xc3c);
    if ((M<int>(iVar11 + 0xc44) == 0) &&
       (iVar17 = ((IOATIR500Surface *)((UInt8 *)self))->allocAllSlaveSwapBuffers((UInt32)param_2,M<UInt32>(iVar17 + 0xcb0)),
       iVar17 == 0)) {
      return;
    }
    goto LAB_0003ee00;
  }
  uVar13 = M<UInt16>(iVar17 + 0xcae) + 1 & 3;
  M<SInt16>(iVar17 + 0xcae) = (SInt16)uVar13;
  iVar8 = uVar13 * 0x1c + iVar11 + (SInt32)self;
  pVVar23 = (UInt8 *)(iVar8 + 0xc3c);
  if (M<int>(iVar8 + 0xc44) == 0) {
    iVar17 = ((IOATIR500Surface *)((UInt8 *)self))->allocAllSlaveSwapBuffers((UInt32)param_2,M<UInt32>(iVar17 + 0xcb0));
    if (iVar17 == 0) {
      return;
    }
  }
  else {
    piVar24 = M<int *>(self + 0xd50);
    iVar12 = piVar24[0x1e2];
    iVar17 = VCALL(*piVar24, 0x54c)(piVar24,M<UInt32>(iVar8 + 0xc4c));
    piVar24[0x1e2] = iVar12 + iVar17;
  }
  puVar18 = M<UInt32 *>(iVar8 + 0xc50);
  puVar9 = M<UInt32 *>(iVar11 + self + 0xc34);
  uVar21 = puVar9[1];
  uVar20 = puVar9[2];
  uVar14 = puVar9[3];
  *puVar18 = *puVar9;
  puVar18[1] = uVar21;
  puVar18[2] = uVar20;
  puVar18[3] = uVar14;
  uVar14 = puVar9[7];
  uVar21 = puVar9[4];
  uVar20 = puVar9[6];
  puVar18[5] = puVar9[5];
  puVar18[7] = uVar14;
  puVar18[4] = uVar21;
  puVar18[6] = uVar20;
  iVar17 = M<int>(iVar8 + 0xc50);
  puVar9 = (UInt32 *)(iVar17 + 0x20);
  *puVar9 = 0xd0b;
  M<UInt32>(iVar17 + 0x24) = 5;
  M<UInt32>(iVar17 + 0x28) = 0x1393;
  M<UInt32>(iVar17 + 0x2c) = 10;
  M<UInt32>(iVar17 + 0x30) = 0x5c8;
  M<UInt32>(iVar17 + 0x34) = 0x30000;
  if (param_3 == 0) {
    uVar13 = 6;
    sVar7 = 0;
  }
  else {
    iVar19 = M<int>((unsigned int)M<UInt16>(param_3 + 0xac) * 4 + self + 0xb70);
    iVar11 = M<int>(iVar19 + 0x40);
    uVar4 = M<UInt16>(iVar19 + 0x20);
    uVar13 = M<unsigned int>(iVar19 + 0x3c);
    iVar12 = M<int>(iVar19 + 8);
    bVar1 = (uVar13 & 0xf00000) != 0;
    if (bVar1) {
      uVar16 = (unsigned int)M<UInt16>(iVar19 + 0x14) / (uVar13 >> 0x14 & 0xf);
    }
    else {
      uVar16 = 0;
    }
    uVar5 = M<UInt16>(iVar19 + 0x16);
    uVar15 = 0x20 / uVar5;
    if (uVar16 < uVar15) {
      uVar16 = uVar15;
    }
    bVar3 = M<UInt8>(iVar19 + 0x38);
    uVar22 = 0x80000000;
    if (bVar3 < 2) {
      uVar22 = 0;
    }
    iVar6 = (unsigned int)M<UInt8>(iVar19 + 0x3a) * 0x1c;
    if (bVar1) {
      uVar13 = (unsigned int)M<UInt16>(iVar19 + 0x14) / (uVar13 >> 0x14 & 0xf);
    }
    else {
      uVar13 = 0;
    }
    if (uVar13 < uVar15) {
      uVar13 = uVar15;
    }
    uVar15 = FormatTableLookup_0x0004d2dc(iVar6);
    uVar10 = FormatTableLookup_0x0004d2e0(iVar6);
    M<UInt32>(iVar17 + 0x38) = 0x50b;
    M<unsigned int>(iVar17 + 0x3c) =
         uVar22 | iVar12 + (unsigned int)uVar4 * iVar11 >> 10 | uVar16 * uVar5 * 0x10000 & 0x3fc00000 |
                  (bVar3 & 1) << 0x1e;
    M<UInt32>(iVar17 + 0x40) = 0x138a;
    M<int>(iVar17 + 0x44) = iVar12;
    M<UInt32>(iVar17 + 0x48) = 0x138e;
    M<unsigned int>(iVar17 + 0x4c) =
         uVar10 >> 1 & 0x1e00000 |
         (uVar15 & 0xc00) << 9 | (bVar3 & 6) << 0x10 | (bVar3 & 1) << 0x10 | uVar13 & 0x3ffe;
    sVar7 = M<SInt16>(param_3 + 0x98);
    uVar13 = 0xc;
  }
  M<unsigned int>(M<int>(self + 0xd50) + 0xb78) =
       M<unsigned int>(M<int>(self + 0xd50) + 0xb78) & 0xffdfffff |
       (M<UInt8>(M<int>(self + 0xb70) + 0x38) & 1) << 0x15;
  M<unsigned int>(M<int>(self + 0xd50) + 0xb78) =
       (unsigned int)(1 < M<UInt8>(M<int>(self + 0xb70) + 0x38)) * 0x100000 |
       M<unsigned int>(M<int>(self + 0xd50) + 0xb78) & 0xffefffff;
  M<unsigned int>(M<int>(self + 0xd50) + 0xb80) =
       (unsigned int)(sVar7 == 0) | M<unsigned int>(M<int>(self + 0xd50) + 0xb80) & 0xfffffffe;
  if (param_2[self + 0xdb6] == 0x0) {
    uVar16 = 0;
    M<unsigned int>(M<int>(self + 0xd50) + 0xb88) =
         M<unsigned int>(M<int>(self + 0xd50) + 0xb88) & 0xfeffffff;
  }
  else {
    uVar16 = M<UInt16>(M<int>(self + 0xb70) + 0x14) & 0x3fff;
    M<unsigned int>(M<int>(self + 0xd50) + 0xb88) =
         M<unsigned int>(M<int>(self + 0xd50) + 0xb88) & 0xfeffffff | 0x1000000;
    M<unsigned int>(M<int>(self + 0xd50) + 0xb88) =
         M<unsigned int>(M<int>(self + 0xd50) + 0xb88) & 0xfffffeff;
    M<unsigned int>(M<int>(self + 0xd50) + 0xb88) =
         M<unsigned int>(M<int>(self + 0xd50) + 0xb88) & 0xfffeffff;
  }
  M<unsigned int>(M<int>(self + 0xd50) + 0xb7c) =
       M<unsigned int>(M<int>(self + 0xd50) + 0xb7c) & 0xffdfffff |
       (M<UInt8>(M<int>(self + 0xb70) + 0x38) & 1) << 0x15;
  M<unsigned int>(M<int>(self + 0xd50) + 0xb7c) =
       (unsigned int)(1 < M<UInt8>(M<int>(self + 0xb70) + 0x38)) * 0x100000 |
       M<unsigned int>(M<int>(self + 0xd50) + 0xb7c) & 0xffefffff;
  M<unsigned int>(M<int>(self + 0xd50) + 0xb84) =
       (unsigned int)(sVar7 == 0) | M<unsigned int>(M<int>(self + 0xd50) + 0xb84) & 0xfffffffe;
  if (param_2[self + 0xdb6] == 0x0) {
    M<unsigned int>(M<int>(self + 0xd50) + 0xb8c) =
         M<unsigned int>(M<int>(self + 0xd50) + 0xb8c) & 0xfeffffff;
  }
  else {
    uVar16 = M<UInt16>(M<int>(self + 0xb70) + 0x14) & 0x3fff;
    M<unsigned int>(M<int>(self + 0xd50) + 0xb8c) =
         M<unsigned int>(M<int>(self + 0xd50) + 0xb8c) & 0xfeffffff | 0x1000000;
    M<unsigned int>(M<int>(self + 0xd50) + 0xb8c) =
         M<unsigned int>(M<int>(self + 0xd50) + 0xb8c) & 0xfffffeff;
    M<unsigned int>(M<int>(self + 0xd50) + 0xb8c) =
         M<unsigned int>(M<int>(self + 0xd50) + 0xb8c) & 0xfffeffff;
  }
  iVar17 = M<int>(self + 0xd50);
  if (M<int>(iVar17 + 0x894) != 0) {
    M<unsigned int>(iVar17 + 0xb80) = M<unsigned int>(iVar17 + 0xb80) & 0xfffffffe | 1;
    iVar17 = M<int>(self + 0xd50);
  }
  bVar1 = param_2 == 0;
  if ((bVar1) || (M<int>(iVar17 + 0x894) != 0)) {
    if (param_2[self + 0xdb6] != 0x0) {
      puVar9[uVar13] = 0x1848;
      iVar11 = uVar13 + 1;
      uVar13 = uVar13 + 2;
      puVar9[iVar11] = uVar16;
    }
    puVar9[uVar13] = 0x1841;
    puVar9[uVar13 + 1] = M<UInt32>(iVar17 + 0xb78);
    puVar9[uVar13 + 2] = 0x1852;
    puVar9[uVar13 + 3] = M<UInt32>(iVar17 + 0xb80);
    puVar9[uVar13 + 4] = 0x1831;
    iVar11 = uVar13 + 5;
    uVar13 = uVar13 + 6;
    puVar9[iVar11] = M<UInt32>(iVar17 + 0xb88);
  }
  bVar2 = param_2 == 1;
  if ((bVar2) || (M<int>(iVar17 + 0x894) != 0)) {
    if (param_2[self + 0xdb6] != 0x0) {
      puVar9[uVar13] = 0x1a48;
      iVar11 = uVar13 + 1;
      uVar13 = uVar13 + 2;
      puVar9[iVar11] = uVar16;
    }
    puVar9[uVar13] = 0x1a41;
    puVar9[uVar13 + 1] = M<UInt32>(iVar17 + 0xb7c);
    puVar9[uVar13 + 2] = 0x1a52;
    puVar9[uVar13 + 3] = M<UInt32>(iVar17 + 0xb84);
    puVar9[uVar13 + 4] = 0x1a31;
    iVar11 = uVar13 + 5;
    uVar13 = uVar13 + 6;
    puVar9[iVar11] = M<UInt32>(iVar17 + 0xb8c);
  }
  uVar14 = M<UInt32>(M<int>(self + 0xb70) + 8);
  if ((bVar1) || (uVar16 = uVar13, M<int>(iVar17 + 0x894) != 0)) {
    puVar9[uVar13] = 0x1844;
    puVar9[uVar13 + 1] = uVar14;
    puVar9[uVar13 + 2] = 0x1844;
    puVar9[uVar13 + 3] = uVar14;
    puVar9[uVar13 + 4] = 0x1844;
    uVar16 = uVar13 + 6;
    puVar9[uVar13 + 5] = uVar14;
    if (param_2[self + 0xdb6] != 0x0) {
      puVar9[uVar16] = 0x1846;
      uVar16 = uVar13 + 8;
      puVar9[uVar13 + 7] = M<UInt32>(M<int>(self + 0xb84) + 8);
    }
  }
  if ((bVar2) || (uVar13 = uVar16, M<int>(iVar17 + 0x894) != 0)) {
    puVar9[uVar16] = 0x1a44;
    puVar9[uVar16 + 1] = uVar14;
    puVar9[uVar16 + 2] = 0x1a44;
    puVar9[uVar16 + 3] = uVar14;
    puVar9[uVar16 + 4] = 0x1a44;
    uVar13 = uVar16 + 6;
    puVar9[uVar16 + 5] = uVar14;
    if (param_2[self + 0xdb6] != 0x0) {
      puVar9[uVar13] = 0x1a46;
      uVar13 = uVar16 + 8;
      puVar9[uVar16 + 7] = M<UInt32>(M<int>(self + 0xb84) + 8);
    }
  }
  if (M<char>(iVar17 + 0x9b0) == '\0') {
LAB_0003ed40:
    if (bVar1) {
      puVar9[uVar13] = 0x5c8;
      iVar17 = uVar13 + 1;
      uVar13 = uVar13 + 2;
      puVar9[iVar17] = 1;
    }
    else if (bVar2) {
      puVar9[uVar13] = 0x5c8;
      iVar17 = uVar13 + 1;
      uVar13 = uVar13 + 2;
      puVar9[iVar17] = 0x80000001;
    }
  }
  else if (M<int>((int)param_2 * 0x18 + iVar17 + 0xb10) == 0) {
    if (M<int>(iVar17 + 0x894) != 0) {
      if (bVar1) {
        iVar11 = 0xb18;
      }
      else {
        iVar11 = 0xb00;
      }
      if (M<int>(iVar17 + iVar11 + 0x10) != 0) goto LAB_0003eda0;
    }
    goto LAB_0003ed40;
  }
LAB_0003eda0:
  uVar16 = uVar13;
  if ((uVar13 & 7) != 0) {
    uVar16 = uVar13 + 1;
    puVar9[uVar13] = 0x80000000;
  }
  M<unsigned int>(M<int>(iVar8 + 0xc50) + 0x14) = uVar16;
LAB_0003ee00:
  if (M<int>(pVVar23 + 4) == 0) {
    ((IOATIR500Surface *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar23));
  }
  M<int>(M<int>(self + 0xd50) + 0x710) =
       M<int>(M<int>(pVVar23 + 0x14) + 0x14) * 4 + M<int>(M<int>(self + 0xd50) + 0x710);
  pAccel = M<UInt8 *>(self + 0xd50);
  uVar14 = ((ATIRadeonX1000 *)pAccel)->submit_buffer
                     ((UInt32 *)(M<int>(pVVar23 + 0x14) + 0x20),M<int>(pVVar23 + 4) + 0x20,
                      M<UInt32>(M<int>(pVVar23 + 0x14) + 0x14));
  M<UInt32>(pVVar23 + 0x10) = uVar14;
  M<UInt32>(self + 0x80) = uVar14;
  M<UInt32>(pAccel + (int)param_2 * 0x20 + 0xec) = uVar14;
  return;
}
