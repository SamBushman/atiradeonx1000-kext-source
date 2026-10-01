/*
 * ATIR500Surface_get_surf_desc_regs_Port.cpp
 *
 * ATIR500Surface::get_surf_desc_regs (real addr 0x39f30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x39f30 */
void ATIR500Surface::get_surf_desc_regs(OverlaySurfaceInfo *real_param_1, UInt32*param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  UInt32 uVar5;
  unsigned int uVar6;
  int iVar7;
  unsigned int uVar8;
  int iVar9;
  UInt32 uVar10;
  UInt8 *pOVar11;
  unsigned int uVar12;
  int iVar13;
  int iVar14;
  unsigned int uVar15;
  int iVar16;
  int iVar17;
  unsigned int uVar18;
  int iVar19;
  int local_e8 [6];
  int local_d0 [6];
  unsigned int local_b8 [4];
  int local_a8;
  int local_a4;
  UInt32 local_98;
  unsigned int uStack_94;
  UInt32 local_90;
  UInt32 uStack_8c;
  SInt64 local_88;
  SInt64 local_80;
  UInt32 local_78;
  unsigned int uStack_74;
  SInt64 local_70;
  SInt64 local_68;
  UInt32 local_60;
  unsigned int uStack_5c;
  UInt32 local_58;
  UInt32 uStack_54;
  SInt64 local_50;
  SInt64 local_48;
  UInt32 local_40;
  unsigned int uStack_3c;
  SInt64 local_38;
  SInt64 local_30;
  
  if (M<int>(param_1 + 0x3c) - 9U < 2) {
    uVar10 = M<UInt32>(param_1 + 0x40);
    iVar17 = M<int>(param_1 + 0xe0);
    iVar14 = 0;
    iVar19 = 6;
    pOVar11 = param_1;
    do {
      uVar5 = M<UInt32>(self + M<int>(self + 0xd90) * 0x78 + 0x560);
      M<UInt32>(pOVar11 + 0x70) = uVar10;
      M<UInt32>(pOVar11 + 0x88) = 0;
      M<UInt32>(pOVar11 + 0x58) = uVar5;
      M<int>((int)local_e8 + iVar14) = iVar17;
      pOVar11 = pOVar11 + 4;
      M<UInt32>((int)local_d0 + iVar14) = 0;
      iVar14 = iVar14 + 4;
      iVar19 = iVar19 + -1;
    } while (iVar19 != 0);
    if (iVar17 == 0) {
      uVar6 = M<unsigned int>(param_1 + 0xd4);
      uVar8 = M<unsigned int>(param_1 + 0xd8);
      uVar12 = M<unsigned int>(param_1 + 0xdc);
      local_b8[0] = ((int)uVar6 >> 4) + (unsigned int)((int)uVar6 < 0 && (uVar6 & 0xf) != 0);
      local_b8[1] = ((int)uVar8 >> 4) + (unsigned int)((int)uVar8 < 0 && (uVar8 & 0xf) != 0);
      local_b8[2] = ((int)uVar12 >> 4) + (unsigned int)((int)uVar12 < 0 && (uVar12 & 0xf) != 0);
      local_b8[3] = local_b8[0];
      local_a8 = local_b8[1];
      local_a4 = local_b8[2];
    }
    else {
      uVar6 = M<unsigned int>(param_1 + 0xd4);
      uVar8 = M<unsigned int>(param_1 + 0xd8);
      uVar12 = M<unsigned int>(param_1 + 0xdc);
      local_b8[0] = ((int)uVar6 >> 4) + (unsigned int)((int)uVar6 < 0 && (uVar6 & 0xf) != 0);
      local_b8[1] = ((int)uVar8 >> 4) + (unsigned int)((int)uVar8 < 0 && (uVar8 & 0xf) != 0);
      local_b8[2] = ((int)uVar12 >> 4) + (unsigned int)((int)uVar12 < 0 && (uVar12 & 0xf) != 0);
    }
    M<UInt32>(param_1 + 0x90) = 1;
    M<UInt32>(param_1 + 0x98) = 1;
    M<UInt32>(param_1 + 0x8c) = 1;
    M<UInt32>(param_1 + 0x9c) = 1;
  }
  else {
    uVar6 = M<unsigned int>(param_1 + 0x10);
    uVar15 = M<unsigned int>(param_1 + 0x14);
    uVar12 = 0;
    local_40 = 0x43300000;
    local_60 = 0x43300000;
    iVar14 = 0;
    local_78 = 0x43300000;
    local_98 = 0x43300000;
    fVar1 = M<float>(param_1 + 0x30);
    iVar17 = M<int>(param_1 + 0xe0);
    uVar10 = M<UInt32>(param_1 + 0x40);
    uVar18 = M<unsigned int>(param_1 + 0x54);
    uStack_3c = (int)uVar6 >> 0x1f & -uVar6 ^ 0x80000000;
    uVar8 = (int)uVar15 >> 0x1f & -uVar15 ^ 0x80000000;
    uStack_5c = uVar8;
    iVar19 = 6;
    uStack_74 = (int)(uVar6 / M<unsigned int>(param_1 + 0x50)) >> 0x1f &
                -(uVar6 / M<unsigned int>(param_1 + 0x50)) ^ 0x80000000;
    fVar2 = (float)((double)CONCAT44d(0x43300000,uStack_3c) - 4503601774854144.0) *
            M<float>(param_1 + 0x34);
    uVar6 = (int)(uVar15 / M<unsigned int>(param_1 + 0x4c)) >> 0x1f &
            -(uVar15 / M<unsigned int>(param_1 + 0x4c)) ^ 0x80000000;
    uStack_94 = uVar6;
    fVar3 = (float)((double)CONCAT44d(0x43300000,uStack_74) - 4503601774854144.0) *
            M<float>(param_1 + 0x34);
    pOVar11 = param_1;
    do {
      M<int>((int)local_e8 + iVar14) = iVar17;
      uVar5 = M<UInt32>(self + 0x128);
      M<UInt32>(pOVar11 + 0x70) = uVar10;
      M<UInt32>(pOVar11 + 0x88) = 0;
      M<UInt32>(pOVar11 + 0xa0) = 0;
      M<UInt32>(pOVar11 + 0xb8) = 0;
      M<UInt32>(pOVar11 + 0x58) = uVar5;
      if ((uVar18 >> (uVar12 & 0x3f) & 1) == 0) {
        local_58 = 0x43300000;
        uStack_54 = M<UInt32>(param_1 + 0x44);
        fVar4 = (float)((double)CONCAT44d(0x43300000,uVar8) - 4503601774854144.0) * fVar1 *
                (float)((double)CONCAT44d(0x43300000,M<UInt32>(param_1 + 0x44)) -
                       4503599627370496.0);
        if (2.1474836e+09 <= fVar4) {
          local_48 = (SInt64)(int)(fVar4 - 2.1474836e+09);
          iVar16 = (int)(fVar4 - 2.1474836e+09) + -0x80000000;
        }
        else {
          iVar16 = (int)fVar4;
          local_50 = (SInt64)iVar16;
        }
        iVar16 = iVar16 + M<int>(pOVar11 + 0xa0);
        if (2.1474836e+09 <= fVar2) {
          local_30 = (SInt64)(int)(fVar2 - 2.1474836e+09);
          iVar13 = (int)(fVar2 - 2.1474836e+09) + -0x80000000;
        }
        else {
          iVar13 = (int)fVar2;
          local_38 = (SInt64)iVar13;
        }
      }
      else {
        local_90 = 0x43300000;
        uStack_8c = M<UInt32>(param_1 + 0x48);
        fVar4 = (float)((double)CONCAT44d(0x43300000,uVar6) - 4503601774854144.0) * fVar1 *
                (float)((double)CONCAT44d(0x43300000,M<UInt32>(param_1 + 0x48)) -
                       4503599627370496.0);
        if (2.1474836e+09 <= fVar4) {
          local_80 = (SInt64)(int)(fVar4 - 2.1474836e+09);
          iVar16 = (int)(fVar4 - 2.1474836e+09) + -0x80000000;
        }
        else {
          iVar16 = (int)fVar4;
          local_88 = (SInt64)iVar16;
        }
        iVar16 = iVar16 + M<int>(pOVar11 + 0xa0);
        if (2.1474836e+09 <= fVar3) {
          local_68 = (SInt64)(int)(fVar3 - 2.1474836e+09);
          iVar13 = (int)(fVar3 - 2.1474836e+09) + -0x80000000;
        }
        else {
          iVar13 = (int)fVar3;
          local_70 = (SInt64)iVar13;
        }
      }
      if (iVar17 == 0) {
        iVar7 = M<int>(pOVar11 + 0x70);
        iVar9 = M<int>(pOVar11 + 0x58);
        M<UInt32>((int)local_d0 + iVar14) = 0;
        iVar9 = iVar13 * iVar7 + iVar9;
      }
      else {
        iVar7 = M<int>(pOVar11 + 0x70);
        iVar9 = M<int>(pOVar11 + 0x58);
        M<UInt32>((int)local_d0 + iVar14) = 0;
        iVar9 = iVar13 * iVar7 + iVar9;
      }
      uVar12 = uVar12 + 1;
      pOVar11 = pOVar11 + 4;
      M<unsigned int>((int)local_b8 + iVar14) = (unsigned int)(iVar16 + iVar9) >> 4;
      iVar14 = iVar14 + 4;
      iVar19 = iVar19 + -1;
    } while (iVar19 != 0);
  }
  iVar14 = 0;
  iVar17 = 6;
  do {
    pOVar11 = param_1 + 0x88;
    param_1 = param_1 + 4;
    M<unsigned int>((int)param_2 + iVar14) =
         M<int>((int)local_e8 + iVar14) << 1 | M<unsigned int>(pOVar11) |
         M<int>((int)local_b8 + iVar14) << 4 | M<int>((int)local_d0 + iVar14) << 0x1b;
    iVar14 = iVar14 + 4;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  return;
}
