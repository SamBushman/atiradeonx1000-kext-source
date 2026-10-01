/*
 * ATIR500Surface_copy_from_buffer_Port.cpp
 *
 * ATIR500Surface::copy_from_buffer (real addr 0x43730, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


int get_offset_of_sample_0(ATIR500SurfaceBuffer *buffer, int x, int y);   /* Sources/ATIR500Surface_CopyBuffers.cpp */

/* real addr 0x43730 */
void ATIR500Surface::copy_from_buffer(SInt32 param_1, SInt32 param_2, SInt32 param_3, SInt32 param_4, UInt32 param_5, UInt32 param_6, ATIR500SurfaceBuffer *real_param_7, UInt32 param_8, VendorTransferBuffer *real_param_9, UInt32 param_10, UInt32 param_11, UInt32 param_12) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_7 = reinterpret_cast<UInt8 *>(real_param_7);
    UInt8 *param_9 = reinterpret_cast<UInt8 *>(real_param_9);

  bool bVar1;
  UInt8 uVar2;
  UInt16 uVar3;
  bool bVar4;
  UInt32 uVar5;
  unsigned int uVar6;
  UInt32 uVar7;
  int iVar8;
  UInt64 *puVar9;
  UInt64 *puVar10;
  unsigned int uVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  UInt8 *puVar16;
  unsigned int uVar17;
  UInt64 *puVar18;
  unsigned int uVar19;
  UInt64 *puVar20;
  int iVar21;
  UInt64 *puVar22;
  UInt64 *puVar23;
  int *piVar24;
  int iVar25;
  UInt64 *puVar26;
  UInt8 *pVVar27;
  unsigned int uVar28;
  UInt8 bVar29;
  UInt8 bVar30;
  UInt8 bVar31;
  
  uVar5 = param_12;
  pVVar27 = M<UInt8 *>(param_7 + 0x24);
  bVar1 = (param_12 & 1) == 0;
  if (bVar1) {
    if ((pVVar27 == (UInt8 *)0x0) ||
       (M<int>(pVVar27 + 0x54) != M<int>(self + 0x7c))) goto LAB_00043834;
LAB_00043888:
    piVar13 = M<int *>(param_9 + 8);
  }
  else {
    param_11 = (UInt32)M<UInt16>(pVVar27 + 0x52);
    param_10 = (UInt32)M<UInt16>(pVVar27 + 0x50);
    uVar11 = VCALL(*M<int *>(pVVar27 + 8), 0x128)(M<int *>(pVVar27 + 8));
    uVar6 = 0;
    if (param_11 != 0) {
      uVar6 = uVar11 / param_11;
    }
    if ((int)uVar6 < param_4) {
      param_4 = uVar6;
    }
    param_9 = pVVar27;
    if ((M<unsigned int>(self + 0xbe8) & 0x70000000) != 0) {
      iVar12 = VCALL(M<int>(self), 0x5f0)(self,param_7,param_5,param_6,0,0,&param_11);
      param_10 = param_10 + iVar12;
    }
LAB_00043834:
    iVar12 = this->copy_buffer_using_DMA(param_1,param_2,param_3,param_4,param_5,param_6,(ATIR500SurfaceBuffer *)(param_7),(VendorTransferBuffer *)(param_9),
                        param_10,param_11,(IODirection)1,uVar5);
    if (iVar12 != 0) {
      return;
    }
    if (bVar1) goto LAB_00043888;
    piVar13 = M<int *>(pVVar27 + 8);
  }
  piVar13 = (int *)VCALL(*piVar13, 0x150)
                             (piVar13,M<unsigned int>(M<int>(self + 0xd50) + 0x82c) | 1);
  if (piVar13 == (int *)0x0) {
    return;
  }
  iVar12 = VCALL(*piVar13, 0xd0)(piVar13);
  piVar24 = M<int *>(self + 0xd50);
  puVar23 = (UInt64 *)(iVar12 + param_10);
  iVar25 = piVar24[0x1ed];
  iVar12 = VCALL(*piVar24, 0x558)(piVar24,param_8);
  piVar24[0x1ed] = iVar25 + iVar12;
  if (((bVar1) && (uVar6 = M<unsigned int>(param_7 + 0x3c), (uVar6 & 0x800) != 0)) &&
     ((M<unsigned int>(self + 0xbe8) & 0xc0000) != 0)) {
    uVar11 = uVar6 >> 0xc & 0xf;
    uVar6 = uVar6 >> 0x10 & 0xf;
  }
  else {
    uVar6 = 1;
    uVar11 = 1;
  }
  iVar12 = uVar6 * param_1;
  iVar25 = uVar11 * param_2;
  if (((bVar1) && (pVVar27 != (UInt8 *)0x0)) &&
     (M<int>(pVVar27 + 0x54) == M<int>(self + 0x7c))) {
    piVar24 = (int *)VCALL(*M<int *>(pVVar27 + 8), 0x150)
                               (M<int *>(pVVar27 + 8),M<unsigned int>(M<int>(self + 0xd50) + 0x82c) | 1
                               );
    bVar29 = (piVar24 == (int *)0x0) << 1;
    if (piVar24 == (int *)0x0) goto LAB_00043db4;
    iVar14 = VCALL(*piVar24, 0xd0)(piVar24);
    uVar17 = M<unsigned int>(param_7 + 0x3c);
    bVar4 = false;
    uVar28 = (unsigned int)M<UInt16>(pVVar27 + 0x52);
    uVar3 = M<UInt16>(param_7 + 0x16);
    iVar14 = iVar14 + (unsigned int)M<UInt16>(pVVar27 + 0x50);
  }
  else {
    uVar17 = M<unsigned int>(param_7 + 0x3c);
    uVar19 = 0;
    iVar14 = M<int>(param_7 + 8) + M<int>(self + 0xc10);
    if ((uVar17 & 0xf00000) != 0) {
      uVar19 = (int)((unsigned int)M<UInt16>(param_7 + 0x14) / (uVar17 >> 0x14 & 0xf)) >> (param_6 & 0x3f)
      ;
    }
    uVar3 = M<UInt16>(param_7 + 0x16);
    uVar28 = 0x20 / uVar3;
    if (uVar28 <= uVar19) {
      uVar28 = uVar19;
    }
    piVar24 = (int *)0x0;
    uVar28 = uVar28 * uVar3;
    bVar4 = true;
    bVar29 = 2;
  }
  iVar21 = (int)(unsigned int)M<UInt16>(param_7 + 0x1e) >> (param_6 & 0x3f);
  puVar26 = (UInt64 *)
            (iVar14 + M<int>(param_7 + param_6 * 4 + 0x40) * (unsigned int)M<UInt16>(param_7 + 0x20) +
                      param_5 * (M<int>(param_7 + param_6 * 4 + 0x44) -
                                M<int>(param_7 + param_6 * 4 + 0x40)));
  iVar14 = 1;
  if (iVar21 != 0) {
    iVar14 = iVar21;
  }
  if ((bVar1) && ((M<unsigned int>(self + 0xbe8) & 0x70000000) == 0)) {
    if ((int)M<SInt16>(self + 0xbd6) != (int)M<SInt16>(self + 0xbda)) {
      iVar14 = (int)M<SInt16>(self + 0xbda);
    }
    iVar25 = (iVar14 - iVar25) - uVar11;
  }
  if (((uVar17 & 0xf00000) == 0x100000) || (!bVar1)) {
    iVar14 = iVar25 * uVar28;
    uVar28 = -uVar28;
    puVar26 = (UInt64 *)((int)puVar26 + iVar14 + iVar12 * (unsigned int)uVar3);
    if (bVar1) goto LAB_00043ac4;
LAB_00043ad0:
    uVar28 = -uVar28;
  }
  else {
LAB_00043ac4:
    if ((M<unsigned int>(self + 0xbe8) & 0x70000000) != 0) goto LAB_00043ad0;
  }
  bVar30 = !bVar4 << 1;
  iVar14 = uVar6 * (unsigned int)uVar3 * param_3;
  if (bVar4) {
    VCALL(M<int>(self), 0x5fc)(self,param_7);
    uVar17 = M<unsigned int>(param_7 + 0x3c);
  }
  if (bVar1) {
    if ((uVar17 >> 0x14 & 0xf) < 2) goto LAB_00043b24;
    iVar14 = iVar25 - param_4;
    if (iVar14 < iVar25) {
      bVar31 = (iVar12 < iVar12 + param_3) << 3;
      do {
        iVar21 = iVar12;
        puVar10 = puVar23;
        if ((bool)(bVar31 >> 3 & 1)) {
          do {
            iVar15 = get_offset_of_sample_0((ATIR500SurfaceBuffer *)param_7,iVar21,iVar25);
            puVar16 = (UInt8 *)(iVar15 + (int)puVar26);
            if (puVar10 < (UInt64 *)((int)puVar10 + (unsigned int)M<UInt16>(param_7 + 0x16))) {
              iVar15 = (int)((int)puVar10 + (unsigned int)M<UInt16>(param_7 + 0x16)) - (int)puVar10;
              iVar8 = 0;
              do {
                uVar2 = *puVar16;
                puVar16 = puVar16 + 1;
                M<UInt8>((int)puVar10 + iVar8) = uVar2;
                iVar8 = iVar8 + 1;
                iVar15 = iVar15 + -1;
              } while (iVar15 != 0);
              puVar10 = (UInt64 *)((int)puVar10 + iVar8);
            }
            iVar21 = iVar21 + 1;
          } while (iVar21 < iVar12 + param_3);
        }
        iVar25 = iVar25 + -1;
        puVar23 = (UInt64 *)((int)puVar23 + param_11);
      } while (iVar14 < iVar25);
    }
  }
  else {
    if (1 < (uVar17 >> 0x14 & 0xf)) {
      M<UInt8>(M<int>(param_7 + 0x24) + 0x58) = 0;
    }
LAB_00043b24:
    if (uVar6 == 1) {
      if (0 < param_4) {
        uVar6 = 0;
        do {
          puVar18 = (UInt64 *)((int)puVar23 + iVar14);
          puVar10 = puVar26;
          puVar20 = puVar23;
          if ((puVar23 < puVar18) && (((unsigned int)puVar23 & 7) != 0)) {
            puVar9 = (UInt64 *)((int)puVar26 + ((int)puVar18 - (int)puVar23));
            iVar12 = (int)puVar9 - (int)puVar26;
            puVar22 = puVar26;
            do {
              uVar2 = M<UInt8>(puVar22);
              puVar22 = (UInt64 *)((int)puVar22 + 1);
              M<UInt8>(puVar20) = uVar2;
              puVar20 = (UInt64 *)((int)puVar20 + 1);
              iVar12 = iVar12 + -1;
              puVar10 = puVar9;
              if (iVar12 == 0) break;
              puVar10 = puVar22;
            } while (((unsigned int)puVar20 & 7) != 0);
          }
          while (puVar20 + 4 <= puVar18) {
            *puVar20 = *puVar10;
            puVar20[1] = puVar10[1];
            puVar20[2] = puVar10[2];
            puVar20[3] = puVar10[3];
            puVar10 = puVar10 + 4;
            puVar20 = puVar20 + 4;
          }
          while ((UInt64 *)((int)puVar20 + 4) <= puVar18) {
            uVar7 = M<UInt32>(puVar10);
            puVar10 = (UInt64 *)((int)puVar10 + 4);
            M<UInt32>(puVar20) = uVar7;
            puVar20 = (UInt64 *)((int)puVar20 + 4);
          }
          if (puVar20 < puVar18) {
            iVar12 = (int)puVar18 - (int)puVar20;
            iVar25 = 0;
            do {
              uVar2 = M<UInt8>(puVar10);
              puVar10 = (UInt64 *)((int)puVar10 + 1);
              M<UInt8>(iVar25 + (int)puVar20) = uVar2;
              iVar25 = iVar25 + 1;
              iVar12 = iVar12 + -1;
            } while (iVar12 != 0);
          }
          uVar6 = uVar6 + 1;
          puVar26 = (UInt64 *)((int)puVar26 + uVar11 * uVar28);
          puVar23 = (UInt64 *)((int)puVar23 + param_11);
        } while (param_4 != uVar6);
      }
    }
    else if (0 < param_4) {
      uVar6 = 0;
      do {
        puVar10 = (UInt64 *)((int)puVar26 + iVar14);
        if (puVar26 < puVar10) {
          uVar17 = (unsigned int)M<UInt16>(param_7 + 0x16);
          puVar20 = puVar26;
          puVar18 = puVar23;
          do {
            if (puVar18 < (UInt64 *)((int)puVar18 + uVar17)) {
              iVar12 = (int)((int)puVar18 + uVar17) - (int)puVar18;
              iVar25 = 0;
              do {
                uVar2 = M<UInt8>(puVar20);
                puVar20 = (UInt64 *)((int)puVar20 + 1);
                M<UInt8>(iVar25 + (int)puVar18) = uVar2;
                iVar25 = iVar25 + 1;
                iVar12 = iVar12 + -1;
              } while (iVar12 != 0);
              uVar17 = (unsigned int)M<UInt16>(param_7 + 0x16);
              puVar18 = (UInt64 *)((int)puVar18 + iVar25);
            }
            puVar20 = (UInt64 *)((int)puVar20 + uVar17);
          } while (puVar20 < puVar10);
        }
        uVar6 = uVar6 + 1;
        puVar26 = (UInt64 *)((int)puVar26 + uVar11 * uVar28);
        puVar23 = (UInt64 *)((int)puVar23 + param_11);
      } while (param_4 != uVar6);
    }
  }
  if (!(bool)(bVar30 >> 1 & 1)) {
    VCALL(M<int>(self), 0x600)(self,param_7);
  }
LAB_00043db4:
  VCALL(*piVar13, 0x18)(piVar13);
  if (!(bool)(bVar29 >> 1 & 1)) {
    VCALL(*piVar24, 0x18)(piVar24);
  }
  return;
}
