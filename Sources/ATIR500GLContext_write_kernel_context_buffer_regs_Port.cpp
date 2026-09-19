/*
 * ATIR500GLContext_write_kernel_context_buffer_regs_Port.cpp
 *
 * ATIR500GLContext::write_kernel_context_buffer_regs (real addr 0x288e0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x288e0 */
UInt32 ATIR500GLContext::write_kernel_context_buffer_regs(UInt32*param_1, UInt32 param_2, UInt32 param_3, UInt32 param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt8 bVar2;
  UInt8 AVar3;
  UInt8 AVar4;
  UInt8 AVar5;
  UInt16 uVar6;
  UInt16 uVar7;
  bool bVar8;
  unsigned int uVar9;
  unsigned int uVar10;
  int iVar11;
  unsigned int uVar12;
  int iVar13;
  int iVar14;
  unsigned int uVar15;
  int iVar16;
  UInt32 uVar17;
  UInt32 uVar18;
  int iVar19;
  int iVar20;
  UInt8 *pAVar21;
  int iVar22;
  unsigned int uVar23;
  UInt32 uVar24;
  UInt32 uVar25;
  unsigned int uVar26;
  UInt8 *pAVar27;
  UInt32 uVar28;
  int iVar29;
  int local_98 [4];
  int local_88 [4];
  UInt32 local_78 [4];
  UInt32 local_68 [4];
  int local_58;
  
  iVar29 = 4;
  iVar13 = 0;
  do {
    M<UInt32>((int)local_98 + iVar13) = 0;
    M<UInt32>((int)local_88 + iVar13) = 0;
    M<UInt32>((int)local_78 + iVar13) = 0;
    M<UInt32>((int)local_68 + iVar13) = 0;
    iVar13 = iVar13 + 4;
    iVar29 = iVar29 + -1;
  } while (iVar29 != 0);
  if (M<int>(self + 0x3bc) == 0) {
    uVar9 = (unsigned int)M<UInt16>(self + 0x3a8);
    iVar29 = M<int>(self + 0x298);
    uVar26 = M<unsigned int>(self + 0x29c);
    if (uVar9 == 0) {
      iVar19 = M<int>(self + 0x290);
    }
    else {
      iVar19 = M<int>(self + 0x290);
      iVar13 = 0;
      pAVar21 = self;
      do {
        uVar6 = M<UInt16>(pAVar21 + 0x3aa);
        pAVar21 = pAVar21 + 2;
        M<unsigned int>((int)local_98 + iVar13) = (unsigned int)uVar6 * 0x78 + iVar19 + 0xa8;
        M<UInt32>((int)local_88 + iVar13) = M<UInt32>((unsigned int)uVar6 * 4 + iVar19 + 0xb70);
        iVar13 = iVar13 + 4;
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
    }
    iVar13 = uVar26 + 1;
    pAVar27 = M<UInt8 *>((unsigned int)M<UInt16>(self + 0xae) * 4 + iVar19 + 0xb70);
    pAVar21 = (UInt8 *)((unsigned int)M<UInt16>(self + 0xae) * 0x78 + iVar19 + 0xa8);
  }
  else {
    uVar26 = (unsigned int)M<UInt16>(self + 0x3a8);
    if (uVar26 != 0) {
      iVar13 = 0;
      iVar29 = 0;
      pAVar21 = self;
      do {
        iVar19 = iVar13 * 0x78;
        iVar13 = iVar13 + 1;
        M<UInt8 *>((int)local_98 + iVar29) = self + iVar19 + 0x3c0;
        pAVar27 = pAVar21 + 0x3b2;
        pAVar21 = pAVar21 + 2;
        M<UInt8 *>((int)local_88 + iVar29) =
             self + (unsigned int)M<UInt16>(pAVar27) * 0x78 + 0x3c0;
        iVar29 = iVar29 + 4;
        uVar26 = uVar26 - 1;
      } while (uVar26 != 0);
    }
    pAVar27 = self + 0x5a0;
    iVar29 = 0;
    uVar26 = 0;
    iVar13 = 1;
    pAVar21 = pAVar27;
  }
  param_1[param_2] = 0x13c6;
  param_1[param_2 + 1] = 3;
  param_1[param_2 + 2] = 0xd0b;
  param_1[param_2 + 3] = 5;
  param_1[param_2 + 4] = 0x1393;
  param_1[param_2 + 5] = 10;
  param_1[param_2 + 6] = 0x1006;
  local_58 = param_2 + 8;
  iVar16 = M<int>(self + 200);
  param_1[param_2 + 7] = M<UInt32>(iVar16 + 0xb74);
  uVar9 = 0;
  iVar19 = M<int>(uVar26 * 4 + local_88[0] + 0x40);
  iVar14 = M<int>(iVar13 * 4 + local_88[0] + 0x40);
  uVar6 = M<UInt16>(local_88[0] + 0x20);
  iVar22 = M<int>(local_88[0] + 8);
  if ((M<unsigned int>(local_88[0] + 0x3c) & 0xf00000) != 0) {
    uVar9 = (unsigned int)M<UInt16>(local_88[0] + 0x14) / (M<unsigned int>(local_88[0] + 0x3c) >> 0x14 & 0xf);
  }
  uVar7 = M<UInt16>(local_88[0] + 0x16);
  uVar10 = 0x20 / uVar7;
  if (uVar10 <= uVar9) {
    uVar10 = uVar9;
  }
  bVar2 = M<UInt8>(local_88[0] + 0x38);
  uVar9 = 0x80000000;
  if (bVar2 < 2) {
    uVar9 = 0;
  }
  uVar23 = 0;
  uVar24 = M<UInt32>(local_98[0] + 0x30);
  if ((M<unsigned int>(local_98[0] + 0x3c) & 0xf00000) != 0) {
    uVar23 = (unsigned int)M<UInt16>(local_98[0] + 0x14) / (M<unsigned int>(local_98[0] + 0x3c) >> 0x14 & 0xf);
  }
  uVar15 = 0x20 / M<UInt16>(local_98[0] + 0x16);
  if (uVar15 <= uVar23) {
    uVar15 = uVar23;
  }
  iVar11 = 0x20;
  if (M<int>(iVar16 + 0xb98) == 4) {
LAB_00028bac:
    uVar25 = iVar11 * ((int)(uVar15 + iVar11 + -1) / iVar11);
  }
  else {
    iVar11 = M<int>(iVar16 + 0xb98) << 4;
    uVar25 = 0;
    if (iVar11 != 0) goto LAB_00028bac;
  }
  uVar17 = HZMEM_GetBlockOffset((_HZDATA *)((UInt8 *)(iVar16 + 0x870)),M<UInt32>(local_98[0] + 0x28),2);
  if (((((M<unsigned int>(local_98[0] + 0x28) & 0x3ff00000) == 0x3ff00000) ||
       (M<char>(local_98[0] + 0x36) == '\0')) ||
      ((M<unsigned int>(M<int>(self + 0x290) + 0xbe8) & 0x700000) == 0)) ||
     (uVar18 = 0x600, M<SInt16>(self + 0xac) != 9)) {
    uVar18 = 0;
  }
  uVar23 = (unsigned int)M<UInt16>(self + 0x3a8);
  if (uVar23 != 0) {
    iVar16 = 0;
    if (uVar23 == 0) {
      uVar23 = 1;
    }
    do {
      iVar20 = M<int>((int)local_88 + iVar16);
      uVar15 = 0;
      iVar11 = M<int>(uVar26 * 4 + iVar20 + 0x40);
      M<unsigned int>((int)local_78 + iVar16) =
           iVar11 * (unsigned int)M<UInt16>(iVar20 + 0x20) +
           iVar29 * (M<int>(iVar13 * 4 + iVar20 + 0x40) - iVar11) + M<int>(iVar20 + 8);
      iVar11 = (unsigned int)M<UInt8>(iVar20 + 0x3a) * 0x1c;
      if ((M<unsigned int>(iVar20 + 0x3c) & 0xf00000) != 0) {
        uVar15 = (int)((unsigned int)M<UInt16>(iVar20 + 0x14) / (M<unsigned int>(iVar20 + 0x3c) >> 0x14 & 0xf))
                 >> (uVar26 & 0x3f);
      }
      uVar12 = 0x20 / M<UInt16>(iVar20 + 0x16);
      if (uVar12 <= uVar15) {
        uVar12 = uVar15;
      }
      M<unsigned int>((int)local_68 + iVar16) =
           FormatTableLookup_0x0004d2e0(iVar11) >> 1 & 0x1e00000 |
           (FormatTableLookup_0x0004d2dc(iVar11) & 0xc00) << 9 |
           (M<UInt8>(iVar20 + 0x38) & 6) << 0x10 |
           (M<UInt8>(iVar20 + 0x38) & 1) << 0x10 | uVar12 & 0x3ffe;
      iVar16 = iVar16 + 4;
      uVar23 = uVar23 - 1;
    } while (uVar23 != 0);
  }
  param_1[local_58] = 0x50b;
  param_1[param_2 + 9] =
       uVar9 | iVar19 * (unsigned int)uVar6 + iVar29 * (iVar14 - iVar19) + iVar22 >> 10 |
               uVar10 * uVar7 * 0x10000 & 0x3fc00000 | (bVar2 & 1) << 0x1e;
  param_1[param_2 + 10] = 0x3138a;
  param_1[param_2 + 0xb] = local_78[0];
  param_1[param_2 + 0xc] = local_78[1];
  param_1[param_2 + 0xd] = local_78[2];
  param_1[param_2 + 0xe] = local_78[3];
  param_1[param_2 + 0xf] = 0x3138e;
  param_1[param_2 + 0x10] = local_68[0];
  param_1[param_2 + 0x11] = local_68[1];
  param_1[param_2 + 0x12] = local_68[2];
  param_1[param_2 + 0x13] = local_68[3];
  param_1[param_2 + 0x14] = 0x1380;
  param_1[param_2 + 0x15] = uVar18;
  param_1[param_2 + 0x16] = 0x1385;
  param_1[param_2 + 0x17] = uVar24;
  param_1[param_2 + 0x18] = 0x1395;
  param_1[param_2 + 0x19] = uVar17;
  param_1[param_2 + 0x1a] = 0x1399;
  param_1[param_2 + 0x1b] = uVar25;
  uVar24 = M<UInt32>(pAVar21 + 8);
  uVar9 = 0;
  if ((M<unsigned int>(pAVar27 + 0x3c) & 0xf00000) != 0) {
    uVar9 = (unsigned int)M<UInt16>(pAVar27 + 0x14) / (M<unsigned int>(pAVar27 + 0x3c) >> 0x14 & 0xf);
  }
  uVar10 = 0x20 / M<UInt16>(pAVar27 + 0x16);
  if (0x20 / M<UInt16>(pAVar27 + 0x16) <= uVar9) {
    uVar10 = uVar9;
  }
  AVar3 = pAVar27[0x39];
  AVar4 = pAVar27[0x38];
  AVar5 = pAVar21[0x3a];
  uVar17 = M<UInt32>(pAVar21 + 0x2c);
  uVar25 = HZMEM_GetBlockOffset
                     ((_HZDATA *)((UInt8 *)(M<int>(self + 200) + 0x870)),M<UInt32>(pAVar21 + 0x28),0);
  uVar9 = HZMEM_GetBlockOffset
                    ((_HZDATA *)((UInt8 *)(M<int>(self + 200) + 0x870)),M<UInt32>(pAVar21 + 0x28),1);
  iVar13 = M<int>(M<int>(self + 200) + 0xb98);
  bVar1 = iVar13 != 4;
  if (!bVar1) {
    uVar9 = uVar9 >> 1;
  }
  uVar23 = M<unsigned int>(pAVar21 + 0x3c);
  bVar8 = (uVar23 & 0xf00000) != 0;
  if (bVar8) {
    uVar15 = (unsigned int)M<UInt16>(pAVar21 + 0x14) / (uVar23 >> 0x14 & 0xf);
  }
  else {
    uVar15 = 0;
  }
  uVar12 = 0x20 / M<UInt16>(pAVar21 + 0x16);
  if (uVar15 < uVar12) {
    uVar15 = uVar12;
  }
  if (bVar1) {
    iVar29 = iVar13 << 4;
    uVar18 = 0;
    if (iVar29 != 0) goto LAB_00028f3c;
  }
  else {
    iVar29 = 0x20;
LAB_00028f3c:
    uVar18 = ((int)(uVar15 + iVar29 + -1) / iVar29) * iVar29;
  }
  if (bVar8) {
    uVar23 = (unsigned int)M<UInt16>(pAVar21 + 0x14) / (uVar23 >> 0x14 & 0xf);
  }
  else {
    uVar23 = 0;
  }
  if (uVar12 <= uVar23) {
    uVar12 = uVar23;
  }
  if (bVar1) {
    iVar13 = iVar13 << 4;
    uVar28 = 0;
    if (iVar13 == 0) goto LAB_00028fac;
  }
  else {
    iVar13 = 0x20;
  }
  uVar28 = ((int)(uVar12 + iVar13 + -1) / iVar13) * iVar13;
LAB_00028fac:
  param_1[param_2 + 0x1c] = 0x113c8;
  param_1[param_2 + 0x1d] = uVar24;
  param_1[param_2 + 0x1e] =
       ((UInt8)AVar4 & 6) << 0x10 |
       ((UInt8)AVar4 & 1) << 0x10 | ((UInt8)AVar3 & 3) << 0x13 | uVar10 & 0x3ffc;
  param_1[param_2 + 0x1f] = 0x13d8;
  param_1[param_2 + 0x20] = 0;
  param_1[param_2 + 0x21] = 0x13c4;
  param_1[param_2 + 0x22] = -((UInt8)AVar5 ^ 0x10) >> 0x1e & 2;
  param_1[param_2 + 0x23] = 0x13ca;
  param_1[param_2 + 0x24] = uVar17;
  param_1[param_2 + 0x25] = 0x13c7;
  uVar24 = this->compute_zb_bw_cntl(param_4);
  param_1[param_2 + 0x26] = uVar24;
  param_1[param_2 + 0x27] = 0x13cc;
  param_1[param_2 + 0x28] = uVar25;
  param_1[param_2 + 0x29] = 0x13cd;
  param_1[param_2 + 0x2a] = uVar18;
  param_1[param_2 + 0x2b] = 0x10e9;
  uVar24 = this->compute_sc_hyperz_en(param_3);
  param_1[param_2 + 0x2c] = uVar24;
  param_1[param_2 + 0x2d] = 0x13d1;
  param_1[param_2 + 0x2e] = uVar9;
  param_1[param_2 + 0x2f] = 0x13d5;
  param_1[param_2 + 0x30] = uVar28;
  if (M<int>(self + 0x3bc) == 0) {
    if ((local_88[0] == M<int>(self + 0x290) + 0x4e0) &&
       ((M<unsigned int>(M<int>(self + 0x290) + 0xbe8) & 0x700000) != 0)) {
      if ((M<unsigned int>(local_88[0] + 0x3c) & 0xf00000) == 0) {
        uVar9 = 0;
      }
      else {
        uVar9 = (unsigned int)M<UInt16>(local_88[0] + 0x1c) /
                (M<unsigned int>(local_88[0] + 0x3c) >> 0x14 & 0xf) & 0x1fff;
      }
    }
    else {
      if (((M<unsigned int>(local_88[0] + 0x3c) & 0xf00000) == 0) ||
         (uVar9 = (int)((unsigned int)M<UInt16>(local_88[0] + 0x1c) /
                       (M<unsigned int>(local_88[0] + 0x3c) >> 0x14 & 0xf)) >> (uVar26 & 0x3f), uVar9 == 0
         )) {
        uVar9 = 1;
      }
      uVar9 = uVar9 & 0x1fff;
    }
    uVar26 = (int)(unsigned int)M<UInt16>(local_88[0] + 0x1e) >> (uVar26 & 0x3f);
    if (uVar26 == 0) {
      uVar26 = 1;
    }
    uVar24 = (uVar26 & 0x1fff) << 0xd | uVar9;
  }
  else {
    uVar24 = (M<UInt16>(local_98[0] + 0x1e) & 0x1fff) << 0xd |
             M<UInt16>(local_98[0] + 0x1c) & 0x1fff;
  }
  param_1[param_2 + 0x31] = 0x110ec   /* PM4 type-0 header word (1 register at 0x10ec); Ghidra labels the constant as a data address */;
  param_1[param_2 + 0x32] = 0;
  param_1[param_2 + 0x33] = uVar24;
  param_1[param_2 + 0x34] = 0x10f4;
  param_1[param_2 + 0x35] = 0xaaaa;
  param_1[param_2 + 0x36] = 0x105bb;
  param_1[param_2 + 0x37] = M<UInt32>(self + 0x354);
  param_1[param_2 + 0x38] = M<UInt32>(self + 0x358);
  return param_2 + 0x39;
}
