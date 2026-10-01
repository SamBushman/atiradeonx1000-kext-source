/*
 * ATIR500Surface_submit_swap_buffer_Port_3b310.cpp
 *
 * ATIR500Surface::submit_swap_buffer (real addr 0x3b310, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3b310 */
void ATIR500Surface::submit_swap_buffer(UInt32 param_1, eDoSwap param_3, IOATIR500GLContext *real_param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    /* Ghidra numbers the real arguments by register slot: panel = param_1 (r4), doSwap = param_3 (r5), context = param_4 (r6) */
    UInt32 param_4 = reinterpret_cast<UInt32>(real_param_4);

  bool bVar1;
  int iVar2;
  UInt32 uVar3;
  UInt32 *puVar4;
  UInt32 *puVar5;
  int iVar6;
  UInt8 *pAVar7;
  int iVar8;
  unsigned int uVar9;
  int iVar10;
  UInt32 uVar11;
  int iVar12;
  int iVar13;
  UInt32 *puVar14;
  UInt32 uVar15;
  int iVar16;
  int iVar17;
  UInt32 uVar18;
  unsigned int uVar19;
  UInt32 *puVar20;
  int iVar21;
  int iVar22;
  int *piVar23;
  unsigned int uVar24;
  int iVar25;
  UInt32 *puVar26;
  UInt8 *pVVar27;
  UInt8 bVar28;
  
  if (M<SInt16>(self + 0xdb4) != 0) {
    M<UInt32>(M<int>(self + 0xd50) + 0x78) = 0;
  }
  if (M<int>(self + 0xd54) == param_4) {
    if (param_3 != (UInt8)self[param_1 * 0x94 + 0xcad]) {
      self[param_1 * 0x94 + 0xcad] = SUB41m(param_3,0);
      M<unsigned int>(M<int>(self + param_1 * 0x94 + 0xc34) + 0x1c) =
           M<unsigned int>(M<int>(self + param_1 * 0x94 + 0xc34) + 0x1c) | 1;
    }
  }
  else {
    M<int>(self + 0xd54) = param_4;
    M<unsigned int>(M<int>(self + param_1 * 0x94 + 0xc34) + 0x1c) =
         M<unsigned int>(M<int>(self + param_1 * 0x94 + 0xc34) + 0x1c) | 1;
  }
  iVar22 = param_1 * 0x94;
  iVar17 = M<int>(self + iVar22 + 0xc34);
  if ((M<unsigned int>(iVar17 + 0x1c) & 1) == 0) {
    iVar17 = (unsigned int)M<UInt16>(self + iVar22 + 0xcae) * 0x1c + iVar22;
    pVVar27 = (UInt8 *)(self + iVar17 + 0xc3c);
    if ((M<int>(self + iVar17 + 0xc44) == 0) &&
       (iVar17 = ((IOATIR500Surface *)((UInt8 *)self))->allocAllSlaveSwapBuffers(param_1,M<UInt32>(self + iVar22 + 0xcb0)),
       iVar17 == 0)) {
      return;
    }
    goto LAB_0003b900;
  }
  bVar28 = (param_3 == 1) << 1;
  if (param_3 == 1) {
    iVar21 = M<int>(iVar17 + 0x18);
    puVar20 = (UInt32 *)(iVar17 + 0x20);
  }
  else if (param_3 == 2) {
    iVar21 = M<int>(iVar17 + 0x14) - M<int>(iVar17 + 0x18);
    puVar20 = (UInt32 *)(iVar17 + 0x20 + M<int>(iVar17 + 0x18) * 4);
  }
  else {
    iVar21 = M<int>(iVar17 + 0x14);
    puVar20 = (UInt32 *)(iVar17 + 0x20);
  }
  if (iVar21 == 0) {
    return;
  }
  uVar9 = M<UInt16>(self + iVar22 + 0xcae) + 1 & 3;
  M<SInt16>(self + iVar22 + 0xcae) = (SInt16)uVar9;
  iVar17 = uVar9 * 0x1c + iVar22;
  pVVar27 = (UInt8 *)(self + iVar17 + 0xc3c);
  if (M<int>(self + iVar17 + 0xc44) == 0) {
    iVar6 = ((IOATIR500Surface *)((UInt8 *)self))->allocAllSlaveSwapBuffers(param_1,M<UInt32>(self + iVar22 + 0xcb0));
    if (iVar6 == 0) {
      return;
    }
  }
  else {
    piVar23 = M<int *>(self + 0xd50);
    iVar12 = piVar23[0x1e2];
    iVar6 = VCALL(*piVar23, 0x54c)(piVar23,M<UInt32>(self + iVar17 + 0xc4c));
    piVar23[0x1e2] = iVar12 + iVar6;
  }
  puVar14 = M<UInt32 *>(self + iVar17 + 0xc50);
  puVar4 = M<UInt32 *>(self + iVar22 + 0xc34);
  uVar18 = puVar4[1];
  uVar15 = puVar4[2];
  uVar11 = puVar4[3];
  *puVar14 = *puVar4;
  puVar14[1] = uVar18;
  puVar14[2] = uVar15;
  puVar14[3] = uVar11;
  uVar18 = puVar4[4];
  uVar15 = puVar4[5];
  uVar11 = puVar4[6];
  puVar14[7] = puVar4[7];
  puVar14[4] = uVar18;
  puVar14[5] = uVar15;
  puVar14[6] = uVar11;
  iVar6 = M<int>(self + iVar17 + 0xc50);
  puVar26 = (UInt32 *)(iVar6 + 0x20);
  if (((((bool)(bVar28 >> 1 & 1)) || (param_4 == 0)) || (M<SInt16>(param_4 + 0x98) < 1)) ||
     ((iVar12 = M<int>(self + 0xd50), M<char>(iVar12 + 0x9b0) != '\0' &&
      (M<int>(param_1 * 0x18 + iVar12 + 0xb10) != 0)))) {
    iVar8 = 0;
  }
  else {
    uVar9 = M<UInt16>(param_1 * 0x78 + iVar12 + 0x14a) & 0xfff;
    *puVar26 = 0x1393;
    M<UInt32>(iVar6 + 0x24) = 10;
    M<UInt32>(iVar6 + 0x28) = 0xd0b;
    M<UInt32>(iVar6 + 0x2c) = 5;
    M<UInt32>(iVar6 + 0x30) = 0x5c8;
    M<UInt32>(iVar6 + 0x34) = 0x70000;
    if (param_1 == 0) {
      iVar2 = M<int>(iVar12 + 0x894);
      if (iVar2 == 0) {
        M<UInt32>(iVar6 + 0x38) = 0x194e;
        M<unsigned int>(iVar6 + 0x3c) = (uVar9 & ~M<unsigned int>(iVar12 + 0x898)) << 0x10 | 0x80000000;
        M<UInt32>(iVar6 + 0x40) = 0x5c8;
        M<UInt32>(iVar6 + 0x44) = 8;
        iVar8 = 10;
      }
      else {
LAB_0003b5e0:
        iVar8 = 6;
        if (iVar2 != 0) goto LAB_0003b5ec;
      }
    }
    else {
      if (param_1 != 1) {
        iVar2 = M<int>(iVar12 + 0x894);
        goto LAB_0003b5e0;
      }
LAB_0003b5ec:
      iVar8 = 10;
      M<UInt32>(iVar6 + 0x38) = 0x1b4e;
      M<unsigned int>(iVar6 + 0x3c) = (uVar9 & ~M<unsigned int>(iVar12 + 0x89c)) << 0x10 | 0x80000000;
      M<UInt32>(iVar6 + 0x40) = 0x5c8;
      M<UInt32>(iVar6 + 0x44) = 0x80000008;
    }
  }
  iVar6 = 0;
  puVar5 = puVar26 + iVar8;
  do {
    uVar3 = *puVar20;
    iVar6 = iVar6 + 1;
    puVar20 = puVar20 + 1;
    *puVar5 = uVar3;
    puVar5 = puVar5 + 1;
    iVar21 = iVar21 + -1;
  } while (iVar21 != 0);
  uVar9 = iVar8 + iVar6;
  if (((bool)(bVar28 >> 1 & 1)) || (M<SInt16>(param_4 + 0x94) == 0)) {
    pAVar7 = M<UInt8 *>(self + 0xd50);
  }
  else {
    pAVar7 = M<UInt8 *>(self + 0xd50);
    iVar21 = param_1 * 0x78;
    uVar24 = 0;
    uVar19 = (unsigned int)M<UInt16>(pAVar7 + iVar21 + 0x144);
    if (uVar19 != 0) {
      uVar24 = (M<unsigned int>(pAVar7 + iVar21 + 0x134) & 0x3ff) / uVar19;
    }
    iVar6 = 0;
    if (M<UInt16>(pAVar7 + iVar21 + 0x142) != 0) {
      iVar6 = (int)((M<unsigned int>(pAVar7 + iVar21 + 0x134) & 0x3ff) - uVar24 * uVar19) /
              (int)(unsigned int)M<UInt16>(pAVar7 + iVar21 + 0x142);
    }
    iVar21 = M<int>(self + iVar22 + 0xc38);
    if (param_3 == 2) {
      iVar21 = iVar21 - M<int>(M<int>(self + iVar22 + 0xc34) + 0x18);
    }
    iVar12 = (int)M<SInt16>(param_4 + 0x90);
    iVar2 = M<int>(self + param_1 * 8 + 0xd60);
    iVar13 = (int)M<SInt16>(iVar2 + 10);
    iVar16 = iVar13 - ((int)M<SInt16>(param_4 + 0x92) + (int)M<SInt16>(param_4 + 0x96));
    iVar8 = iVar12;
    if (iVar12 < 0) {
      iVar8 = 0;
    }
    if (iVar16 < 0) {
      iVar16 = 0;
    }
    iVar12 = iVar12 + M<SInt16>(param_4 + 0x94);
    iVar10 = iVar13 - M<SInt16>(param_4 + 0x92);
    iVar6 = iVar6 + M<SInt16>(iVar2 + 4);
    iVar25 = uVar24 + (int)M<SInt16>(iVar2 + 6);
    if (M<SInt16>(iVar2 + 8) < iVar12) {
      iVar12 = (int)M<SInt16>(iVar2 + 8);
    }
    if (iVar13 < iVar10) {
      iVar10 = iVar13;
    }
    puVar26[iVar21] = iVar8 + iVar6 & 0x1fffU | (iVar16 + iVar25) * 0x2000 & 0x3ffe000U;
    puVar26[iVar21 + 1] =
         (iVar12 + iVar6) - 1U & 0x1fff | (iVar10 + iVar25 + -1) * 0x2000 & 0x3ffe000U;
  }
  if ((self[0xbed] == 0x0) &&
     ((((bool)(bVar28 >> 1 & 1) || (param_4 == 0)) || (M<SInt16>(param_4 + 0x98) < 1)))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((pAVar7[0x9b0] == 0x0) || (!bVar1)) {
LAB_0003b870:
    uVar11 = 0;
  }
  else if (M<int>(pAVar7 + param_1 * 0x18 + 0xb10) == 0) {
    if ((M<int>(pAVar7 + 0x894) == 0) ||
       (M<int>(pAVar7 + (unsigned int)(param_1 == 0) * 0x18 + 0xb10) == 0)) goto LAB_0003b870;
    uVar9 = ((ATIRadeonX1000 *)(pAVar7))->SWDSWriteBlitToCmdBuf((UInt32 *)(puVar26), uVar9, true, (unsigned int)(param_1 == 0));
    uVar11 = 1;
  }
  else {
    uVar9 = ((ATIRadeonX1000 *)(pAVar7))->SWDSWriteBlitToCmdBuf((UInt32 *)(puVar26), uVar9, true, param_1);
    uVar11 = 1;
  }
  *M<UInt32 *>(self + iVar17 + 0xc50) = uVar11;
  uVar19 = uVar9;
  if ((uVar9 & 1) != 0) {
    uVar19 = uVar9 + 1;
    puVar26[uVar9] = 0x80000000;
  }
  M<unsigned int>(M<int>(self + iVar17 + 0xc50) + 0x14) = uVar19;
  M<unsigned int>(M<int>(self + iVar22 + 0xc34) + 0x1c) =
       M<unsigned int>(M<int>(self + iVar22 + 0xc34) + 0x1c) & 0xfffffffe;
LAB_0003b900:
  iVar17 = M<int>(pVVar27 + 0x14);
  if (M<int>(iVar17 + 0x14) != 0) {
    if (M<int>(pVVar27 + 4) == 0) {
      ((IOATIR500Surface *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar27));
      iVar17 = M<int>(pVVar27 + 0x14);
    }
    M<int>(M<int>(self + 0xd50) + 0x710) =
         M<int>(iVar17 + 0x14) * 4 + M<int>(M<int>(self + 0xd50) + 0x710);
    pAVar7 = M<UInt8 *>(self + 0xd50);
    uVar11 = ((ATIRadeonX1000 *)(pAVar7))->submit_buffer((UInt32 *)(M<int>(pVVar27 + 0x14) + 0x20),
                        M<int>(pVVar27 + 4) + 0x20,M<UInt32>(M<int>(pVVar27 + 0x14) + 0x14));
    M<UInt32>(pVVar27 + 0x10) = uVar11;
    M<UInt32>(self + 0x80) = uVar11;
    M<UInt32>(pAVar7 + param_1 * 0x20 + 0xec) = uVar11;
    iVar17 = M<int>(self + 0xd50);
    if ((M<char>(iVar17 + 0x9b0) != '\0') && (*M<int *>(pVVar27 + 0x14) != 0)) {
      if (M<int>(param_1 * 0x18 + iVar17 + 0xb10) == 0) {
        if ((M<int>(iVar17 + 0x894) != 0) &&
           (M<int>((unsigned int)(param_1 == 0) * 0x18 + iVar17 + 0xb10) != 0)) {
          M<UInt32>((unsigned int)(param_1 == 0) * 4 + iVar17 + 0xad4) = M<UInt32>(self + 0x80);
          M<UInt32>(M<int>(self + 0xd50) + 0x78) = 0;
        }
      }
      else {
        M<UInt32>(param_1 * 4 + iVar17 + 0xad4) = M<UInt32>(self + 0x80);
        M<UInt32>(M<int>(self + 0xd50) + 0x78) = 0;
      }
    }
  }
  return;
}
