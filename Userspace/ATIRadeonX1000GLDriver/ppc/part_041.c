#include "decls.h"

/* FUN_001315f8 @ 0x1315f8 (684 bytes) */
int FUN_001315f8(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  int *param_4;
  undefined4 param_5;
  int param_6;
{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  
  iVar14 = *(int *)(*(int *)(param_1 + 0x2c) + 0x6c4);
  iVar5 = FUN_001043f0(0x31,*(int *)(param_1 + 0x2c));
  iVar12 = *param_4;
  *(undefined4 *)(iVar5 + 0x98) = *(undefined4 *)(param_2 + 0x98);
  *(int *)(iVar5 + 0x94) = iVar12;
  FUN_00106004(iVar5,1,param_3,0,*(undefined4 *)(param_1 + 0x2c));
  *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) & 0xffffffbf | 0x80000000;
  FUN_000e7700(param_6,param_5,iVar5);
  FUN_00106804(param_2,iVar5,0,*(undefined4 *)(param_1 + 0x2c));
  ((int (*)())FUN_00137474)(param_1);
  *(undefined4 *)(*param_4 * 4 + *(int *)(iVar14 + 0x45c)) = 0;
  **(int **)(param_1 + 0x18) = **(int **)(param_1 + 0x18) + 1;
  *param_4 = *param_4 + 1;
  iVar13 = *(int *)(iVar14 + 900);
  *(int *)(iVar14 + 600) = *(int *)(iVar14 + 600) + 1;
  iVar5 = *param_4;
  if (*(int *)(iVar13 + 8) != 0) {
    uVar11 = iVar5 * 4 + 0x1fU >> 5;
    do {
      puVar15 = *(uint **)(iVar13 + 0x104);
      uVar9 = puVar15[1];
      uVar10 = uVar9 + 1;
      if (uVar9 + 0x20 >> 5 == *puVar15) {
        puVar15[1] = uVar10;
        for (; uVar9 < uVar10; uVar9 = uVar9 + 1) {
          uVar2 = uVar9 >> 3 & 0x1ffffffc;
          *(uint *)((int)puVar15 + uVar2 + 8) =
               *(uint *)((int)puVar15 + uVar2 + 8) & ~(1 << (uVar9 & 0x1f));
        }
      }
      else {
        uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378);
        puVar8 = (undefined4 *)FUN_00193e18(uVar7,uVar11 * 4 + 0xc);
        piVar6 = puVar8 + 1;
        *puVar8 = uVar7;
        puVar8[1] = uVar11;
        puVar8[2] = iVar5 * 4;
        if (uVar11 != 0) {
          piVar3 = piVar6;
          uVar9 = uVar11;
          if (uVar11 == 0) {
            uVar9 = 1;
          }
          do {
            piVar3[2] = 0;
            piVar3 = piVar3 + 1;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        *(int **)(iVar13 + 0x104) = piVar6;
        iVar14 = *piVar6;
        if (iVar14 != 0) {
          if (iVar14 == 0) {
            iVar14 = 1;
          }
          do {
            puVar1 = puVar15 + 2;
            puVar15 = puVar15 + 1;
            piVar6[2] = piVar6[2] | *puVar1;
            piVar6 = piVar6 + 1;
            iVar14 = iVar14 + -1;
          } while (iVar14 != 0);
        }
      }
      iVar13 = *(int *)(iVar13 + 8);
    } while (*(int *)(iVar13 + 8) != 0);
    iVar5 = *param_4;
  }
  if (0 < iVar5) {
    iVar14 = 0;
    iVar13 = 4;
    do {
      uVar11 = iVar14 * 4;
      iVar4 = iVar13 + iVar14 * -4;
      do {
        if ((*(uint *)((uVar11 >> 3 & 0x1ffffffc) + *(int *)(param_6 + 0x104) + 8) >>
             (uVar11 & 0x1f) & 1) != 0) {
          uVar7 = ((int (*)())FUN_00134bf0)(param_1,iVar14,1);
          ((int (*)())FUN_00135334)(param_1,iVar12,uVar7);
          iVar5 = *param_4;
          break;
        }
        uVar11 = uVar11 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      iVar14 = iVar14 + 1;
      iVar13 = iVar13 + 4;
    } while (iVar14 < iVar5);
  }
  return;
}

/* FUN_001318a4 @ 0x1318a4 (300 bytes) */
int FUN_001318a4(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  
  puVar5 = *(uint **)(param_1 + 4);
  if (param_2 < *puVar5) {
    uVar1 = puVar5[1];
    if (uVar1 <= param_2) {
      _memset((void *)(uVar1 * 4 + puVar5[2]),0,(param_2 - uVar1) * 4 + 4);
      puVar5[1] = param_2 + 1;
    }
    puVar2 = (undefined4 *)(param_2 * 4 + puVar5[2]);
  }
  else {
    puVar2 = (undefined4 *)FUN_0019423c(puVar5,param_2);
  }
  iVar3 = ((int (*)())FUN_00134ab0)(*puVar2);
  if (iVar3 == 0) {
    iVar4 = *(int *)(param_3 + 0x138);
    iVar3 = FUN_00130f64(*(undefined4 *)(param_3 + 0x130),iVar4,*(undefined4 *)(param_1 + 0x2c));
    puVar5 = *(uint **)(param_1 + 4);
    if (param_2 < *puVar5) {
      uVar1 = puVar5[1];
      if (uVar1 <= param_2) {
        _memset((void *)(uVar1 * 4 + puVar5[2]),0,(param_2 - uVar1) * 4 + 4);
        puVar5[1] = param_2 + 1;
      }
      puVar2 = (undefined4 *)(param_2 * 4 + puVar5[2]);
    }
    else {
      puVar2 = (undefined4 *)FUN_0019423c(puVar5,param_2);
    }
    ((int (*)())FUN_00134aa8)(*puVar2,iVar3);
    *(int *)(param_3 + 0x138) = iVar4 + 1;
  }
  return iVar3;
}

/* FUN_001319d0 @ 0x1319d0 (176 bytes) */
int FUN_001319d0(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  iVar3 = 0;
  if (0 < (int)param_2) {
    uVar4 = 0;
    do {
      puVar5 = *(uint **)(param_1 + 0x8c);
      if (param_2 < *puVar5) {
        uVar1 = puVar5[1];
        if (uVar1 <= param_2) {
          _memset((void *)(uVar1 * 4 + puVar5[2]),0,(param_2 - uVar1) * 4 + 4);
          puVar5[1] = param_2 + 1;
        }
        piVar2 = (int *)(param_2 * 4 + puVar5[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar5,param_2);
      }
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + *piVar2;
    } while (param_2 != uVar4);
  }
  return iVar3;
}

/* FUN_00131a80 @ 0x131a80 (232 bytes) */
int FUN_00131a80(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  
  iVar4 = *(int *)(param_1 + 0x434);
  iVar1 = *(int *)(iVar4 + 4);
  if (iVar1 == 0) {
LAB_00131ae0:
    uVar6 = 0xffffffff;
  }
  else {
    uVar6 = 0;
    if ((*(uint *)(iVar4 + 8) & 1) != 0) {
      uVar6 = 0;
      do {
        uVar6 = uVar6 + 1;
        iVar1 = iVar1 + -1;
        if (iVar1 == 0) goto LAB_00131ae0;
      } while ((*(uint *)((uVar6 >> 3 & 0x1ffffffc) + iVar4 + 8) >> (uVar6 & 0x1f) & 1) != 0);
    }
  }
  iVar4 = (uVar6 >> 3 & 0x1ffffffc) + iVar4;
  *(uint *)(iVar4 + 8) = 1 << (uVar6 & 0x1f) | *(uint *)(iVar4 + 8);
  puVar7 = *(uint **)(param_1 + 0x8c);
  if (puVar7 == (uint *)0x0) {
    uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
    puVar2 = (undefined4 *)FUN_00193e18(uVar5,0x14);
    puVar7 = puVar2 + 1;
    *puVar2 = uVar5;
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2[4] = uVar5;
    uVar5 = FUN_00193e18(uVar5,8);
    puVar2[3] = uVar5;
    *(uint **)(param_1 + 0x8c) = puVar7;
  }
  if (uVar6 < *puVar7) {
    uVar3 = puVar7[1];
    if (uVar3 <= uVar6) {
      _memset((void *)(uVar3 * 4 + puVar7[2]),0,(uVar6 - uVar3) * 4 + 4);
      puVar7[1] = uVar6 + 1;
    }
    puVar2 = (undefined4 *)(uVar6 * 4 + puVar7[2]);
  }
  else {
    puVar2 = (undefined4 *)FUN_0019423c(puVar7,uVar6);
  }
  *puVar2 = 0;
  return uVar6;
}

/* FUN_00131c10 @ 0x131c10 (100 bytes) */
int FUN_00131c10(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x438);
  if (iVar1 == 0) {
    uVar2 = ((int (*)())FUN_00131a80)(param_1);
    uVar3 = ((int (*)())FUN_001319d0)(param_1,uVar2);
    iVar1 = FUN_00130ec0(uVar2,uVar3,*(undefined4 *)(param_1 + 8));
    *(int *)(param_1 + 0x438) = iVar1;
  }
  return iVar1;
}

/* FUN_00131c74 @ 0x131c74 (148 bytes) */
int FUN_00131c74(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint *puVar4;
  
  *(undefined4 *)(param_2 + 300) = param_3;
  puVar4 = *(uint **)(param_1 + 0x8c);
  uVar3 = *(uint *)(param_2 + 0x130);
  if (uVar3 < *puVar4) {
    uVar1 = puVar4[1];
    if (uVar1 <= uVar3) {
      _memset((void *)(uVar1 * 4 + puVar4[2]),0,(uVar3 - uVar1) * 4 + 4);
      puVar4[1] = uVar3 + 1;
    }
    puVar2 = (undefined4 *)(uVar3 * 4 + puVar4[2]);
  }
  else {
    puVar2 = (undefined4 *)FUN_0019423c(puVar4,uVar3);
  }
  *puVar2 = param_3;
  return;
}

/* FUN_00131d08 @ 0x131d08 (1440 bytes) */
int FUN_00131d08(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint in_r8;
  uint uVar9;
  int *in_r10;
  int iVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  
  iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0x14) << 2;
  iVar3 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x378),iVar4);
  iVar4 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x378),iVar4);
  uVar5 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x378),
                       *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0x14) << 2);
  piVar6 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
  (**(code **)(*piVar6 + 0x134))(piVar6,uVar5);
  iVar10 = *(int *)(param_1 + 8);
  if (0 < *(int *)(*(int *)(iVar10 + 0x30c) + 0x14)) {
    iVar11 = 0;
    iVar12 = 0;
    do {
      uVar5 = *(undefined4 *)(iVar10 + 0x378);
      puVar7 = (undefined4 *)FUN_00193e18(uVar5,0x20c);
      iVar10 = 0x80;
      *puVar7 = uVar5;
      puVar7[1] = 0x80;
      puVar7[2] = 0x1000;
      puVar8 = puVar7 + 1;
      do {
        puVar8[2] = 0;
        puVar8 = puVar8 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      *(undefined4 **)(iVar3 + iVar12) = puVar7 + 1;
      uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
      puVar7 = (undefined4 *)FUN_00193e18(uVar5,0x20c);
      iVar10 = 0x80;
      *puVar7 = uVar5;
      puVar7[1] = 0x80;
      puVar7[2] = 0x1000;
      puVar8 = puVar7 + 1;
      do {
        puVar8[2] = 0;
        puVar8 = puVar8 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      *(undefined4 **)(iVar4 + iVar12) = puVar7 + 1;
      iVar11 = iVar11 + 1;
      iVar10 = *(int *)(param_1 + 8);
      iVar12 = iVar12 + 4;
    } while (iVar11 < *(int *)(*(int *)(iVar10 + 0x30c) + 0x14));
  }
  iVar11 = *(int *)(*(int *)(param_1 + 900) + 8);
  iVar12 = *(int *)(param_1 + 900);
  if (iVar11 != 0) {
    do {
      iVar10 = iVar11;
      piVar13 = *(int **)(iVar12 + 0x98);
      piVar6 = (int *)piVar13[2];
      if ((int *)piVar13[2] != (int *)0x0) {
        do {
          piVar1 = piVar6;
          if (((piVar13[5] & 1U) != 0) && (piVar13[0x20] != 0)) {
            iVar10 = FUN_00126760(piVar13[0x26]);
            if ((iVar10 == 0) ||
               (((piVar13[5] & 2U) != 0 ||
                (iVar10 = (**(code **)(*piVar13 + 0x50))(piVar13), iVar10 != 0)))) {
LAB_00131f98:
              piVar1 = (int *)piVar13[2];
            }
            else {
              iVar10 = FUN_00130bfc(param_1,piVar13);
              uVar9 = piVar13[0x25];
              if ((piVar13[5] & 0x40U) == 0) {
                iVar10 = iVar10 * 4;
                in_r8 = uVar9 >> 3 & 0x1ffffffc;
                if ((*(uint *)(in_r8 + *(int *)(iVar4 + iVar10) + 8) >> (uVar9 & 0x1f) & 1) != 0)
                goto LAB_00131f98;
                iVar11 = *(int *)(*(int *)(param_1 + 0x3c0) + 0x18);
                *(int *)(iVar10 + iVar11) = *(int *)(iVar10 + iVar11) + 1;
                iVar10 = *(int *)(iVar4 + iVar10);
              }
              else {
                iVar10 = iVar10 * 4;
                in_r8 = uVar9 >> 3 & 0x1ffffffc;
                if ((*(uint *)(in_r8 + *(int *)(iVar3 + iVar10) + 8) >> (uVar9 & 0x1f) & 1) != 0)
                goto LAB_00131f98;
                iVar11 = *(int *)(*(int *)(param_1 + 0x3c0) + 0x14);
                *(int *)(iVar10 + iVar11) = *(int *)(iVar10 + iVar11) + 1;
                iVar10 = *(int *)(iVar3 + iVar10);
              }
              in_r10 = (int *)(1 << (uVar9 & 0x1f) | *(uint *)(in_r8 + iVar10 + 8));
              *(int **)(in_r8 + iVar10 + 8) = in_r10;
              piVar1 = (int *)piVar13[2];
            }
          }
          piVar6 = (int *)piVar1[2];
          piVar13 = piVar1;
        } while ((int *)piVar1[2] != (int *)0x0);
        iVar10 = *(int *)(iVar12 + 8);
      }
      iVar11 = *(int *)(iVar10 + 8);
      iVar12 = iVar10;
    } while (*(int *)(iVar10 + 8) != 0);
    iVar10 = *(int *)(param_1 + 8);
  }
  iVar12 = *(int *)(*(int *)(iVar10 + 0x30c) + 0x14);
  iVar11 = iVar12 + -1;
  if (-1 < iVar11) {
    iVar11 = iVar11 * 4;
    iVar10 = 0;
    piVar13 = (int *)(iVar3 + iVar11);
    piVar6 = (int *)(iVar4 + iVar11);
    do {
      iVar11 = *piVar6;
      if (iVar11 != 0) {
        FUN_00193cc0(*(undefined4 *)(iVar11 + -4),iVar11 + -4);
      }
      iVar11 = *piVar13;
      if (iVar11 != 0) {
        FUN_00193cc0(*(undefined4 *)(iVar11 + -4),iVar11 + -4);
      }
      iVar10 = iVar10 + 1;
      piVar6 = piVar6 + -1;
      piVar13 = piVar13 + -1;
    } while (iVar12 != iVar10);
    iVar10 = *(int *)(param_1 + 8);
  }
  FUN_00193cc0(*(undefined4 *)(iVar10 + 0x378),iVar4);
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x378),iVar3);
  iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0x14) << 2;
  piVar6 = (int *)FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x378),iVar4);
  *piVar6 = 0;
  iVar3 = *(int *)(param_1 + 8);
  if (1 < *(int *)(*(int *)(iVar3 + 0x30c) + 0x14)) {
    in_r8 = 1;
    in_r10 = piVar6;
    do {
      iVar3 = in_r8 * 4;
      iVar10 = *in_r10;
      in_r8 = in_r8 + 1;
      in_r10 = in_r10 + 1;
      *in_r10 = iVar10 + *(int *)(iVar3 + *(int *)(*(int *)(param_1 + 0x3c0) + 0x14) + -4);
      iVar3 = *(int *)(param_1 + 8);
    } while ((int)in_r8 < *(int *)(*(int *)(iVar3 + 0x30c) + 0x14));
  }
  puVar8 = (undefined4 *)FUN_00193e18(*(undefined4 *)(iVar3 + 0x378),iVar4);
  iVar4 = *(int *)(param_1 + 8);
  if (0 < *(int *)(*(int *)(iVar4 + 0x30c) + 0x14)) {
    in_r10 = (int *)0x0;
    in_r8 = 0;
    puVar7 = puVar8;
    do {
      *puVar7 = 0;
      in_r10 = (int *)((int)in_r10 + 1);
      iVar4 = *(int *)(param_1 + 8);
      puVar7 = puVar7 + 1;
    } while ((int)in_r10 < *(int *)(*(int *)(iVar4 + 0x30c) + 0x14));
  }
  iVar3 = *(int *)(*(int *)(param_1 + 900) + 8);
  iVar10 = *(int *)(param_1 + 900);
  if (iVar3 != 0) {
    do {
      iVar4 = iVar3;
      piVar13 = (int *)(*(int **)(iVar10 + 0x98))[2];
      piVar1 = *(int **)(iVar10 + 0x98);
      if (piVar13 != (int *)0x0) {
        do {
          piVar2 = piVar13;
          if (((piVar1[5] & 1U) != 0) && (piVar1[0x20] != 0)) {
            iVar4 = FUN_00126760(piVar1[0x26]);
            if ((iVar4 == 0) ||
               (((piVar1[5] & 2U) != 0 ||
                (iVar4 = (**(code **)(*piVar1 + 0x50))(piVar1), iVar4 != 0)))) {
              piVar2 = (int *)piVar1[2];
            }
            else {
              iVar4 = FUN_00130bfc(param_1,piVar1);
              if ((piVar1[5] & 0x40U) == 0) {
                if (param_5 == 0) {
                  iVar3 = param_3 + piVar1[0x25];
                }
                else {
                  iVar3 = piVar1[0x25];
                }
                iVar11 = iVar3 * 4;
                *(undefined4 *)(*(int *)(param_1 + 0x458) + iVar11) = 0xffffffff;
              }
              else {
                in_r10 = (int *)piVar1[0x25];
                iVar11 = *(int *)(param_1 + 0x460);
                iVar3 = (int)in_r10 * 4;
                if (*(int *)(iVar3 + iVar11) == -1) {
                  *(undefined4 *)(iVar3 + iVar11) = puVar8[iVar4];
                  puVar8[iVar4] = puVar8[iVar4] + 1;
                  iVar11 = *(int *)(param_1 + 0x460);
                }
                iVar3 = *(int *)(iVar3 + iVar11) + piVar6[iVar4];
                iVar11 = iVar3 * 4;
                *(int **)(*(int *)(param_1 + 0x458) + iVar11) = in_r10;
              }
              iVar12 = FUN_001054ec(piVar1,0);
              *(int *)(iVar12 + 8) = iVar3;
              *(int *)(*(int *)(param_1 + 0x45c) + iVar11) = iVar4;
              piVar2 = (int *)piVar1[2];
            }
          }
          piVar13 = (int *)piVar2[2];
          piVar1 = piVar2;
        } while ((int *)piVar2[2] != (int *)0x0);
        iVar4 = *(int *)(iVar10 + 8);
      }
      iVar3 = *(int *)(iVar4 + 8);
      iVar10 = iVar4;
    } while (*(int *)(iVar4 + 8) != 0);
    iVar4 = *(int *)(param_1 + 8);
  }
  uVar5 = 0;
  *(undefined4 *)(param_1 + 0x34) = 4;
  FUN_00193cc0(*(undefined4 *)(iVar4 + 0x378),piVar6);
  FUN_000e0e0c(*(undefined4 *)(param_1 + 8),
               "Register allocation : Repartition -> %d physical + %d virtual = %d regs\n",param_3,
               param_2,param_4,in_r8,uVar5,in_r10);
  return;
}

/* FUN_001322a8 @ 0x1322a8 (416 bytes) */
int FUN_001322a8(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  uint *puVar10;
  int *piVar11;
  undefined4 *puVar12;
  int *piVar13;
  int iVar14;
  int *piVar15;
  uint *puVar16;
  int iVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  int local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48 [2];
  
  iVar14 = *(int *)(param_6 + 0x6c4);
  *(undefined4 *)(iVar14 + 0x244) = 0;
  *(undefined4 *)(iVar14 + 0x240) = 0;
  if (0 < param_3) {
    iVar17 = 0;
    while (iVar17 = iVar17 + 1, param_3 != iVar17) {
      if (0 < iVar17) {
        iVar24 = 0;
        do {
          iVar20 = iVar24 + 1;
          ((int (*)())FUN_00135334)(param_2,iVar17,iVar24);
          iVar24 = iVar20;
        } while (iVar17 != iVar20);
      }
    }
  }
  uVar3 = param_4 * 4;
  uVar18 = *(undefined4 *)(param_6 + 0x378);
  uVar22 = uVar3 + 0x1f >> 5;
  puVar6 = (undefined4 *)FUN_00193e18(uVar18,uVar22 * 4 + 0xc);
  piVar15 = puVar6 + 1;
  *puVar6 = uVar18;
  puVar6[1] = uVar22;
  puVar6[2] = uVar3;
  if (uVar22 != 0) {
    piVar4 = piVar15;
    if (uVar22 == 0) {
      uVar22 = 1;
    }
    do {
      piVar4[2] = 0;
      piVar4 = piVar4 + 1;
      uVar22 = uVar22 - 1;
    } while (uVar22 != 0);
  }
  uVar19 = *(undefined4 *)(param_6 + 0x378);
  puVar7 = (undefined4 *)FUN_00193e18(uVar19,0x18);
  puVar16 = puVar7 + 1;
  *puVar7 = uVar19;
  puVar7[1] = 2;
  puVar7[2] = 0;
  puVar7[4] = uVar19;
  uVar18 = FUN_00193e18(uVar19,8);
  puVar7[3] = uVar18;
  uVar22 = param_4 + 0x1fU >> 5;
  puVar8 = (undefined4 *)FUN_00193e18(uVar19,uVar22 * 4 + 0xc);
  puVar12 = puVar8 + 1;
  *puVar8 = uVar19;
  puVar8[1] = uVar22;
  puVar8[2] = param_4;
  if (uVar22 != 0) {
    puVar8 = puVar12;
    if (uVar22 == 0) {
      uVar22 = 1;
    }
    do {
      puVar8[2] = 0;
      puVar8 = puVar8 + 1;
      uVar22 = uVar22 - 1;
    } while (uVar22 != 0);
  }
  puVar7[5] = puVar12;
  iVar14 = *(int *)(iVar14 + 900);
  iVar17 = *(int *)(iVar14 + 8);
  do {
    if (iVar17 == 0) {
      if (piVar15 != (int *)0x0) {
        FUN_00193cc0(*puVar6,puVar6);
      }
      return;
    }
    iVar17 = *piVar15;
    if (iVar17 != 0) {
      piVar4 = piVar15;
      iVar24 = iVar17;
      if (iVar17 == 0) {
        iVar24 = 1;
      }
      do {
        piVar4[2] = 0;
        piVar4 = piVar4 + 1;
        iVar24 = iVar24 + -1;
      } while (iVar24 != 0);
    }
    if (param_5 == 0) {
      iVar24 = *(int *)(iVar14 + 0x104);
      if (iVar17 != 0) {
        piVar4 = piVar15;
        if (iVar17 == 0) {
          iVar17 = 1;
        }
        do {
          piVar11 = (int *)(iVar24 + 8);
          iVar24 = iVar24 + 4;
          piVar4[2] = *piVar11;
          piVar4 = piVar4 + 1;
          iVar17 = iVar17 + -1;
        } while (iVar17 != 0);
      }
    }
    else if (0 < (int)uVar3) {
      uVar22 = 0;
      do {
        if ((*(uint *)((uVar22 >> 3 & 0x1ffffffc) + *(int *)(iVar14 + 0x104) + 8) >> (uVar22 & 0x1f)
            & 1) != 0) {
          iVar24 = ((int)uVar22 >> 2) + (uint)((int)uVar22 < 0 && (uVar22 & 3) != 0);
          iVar17 = ((int (*)())FUN_00134bf0)(param_2,iVar24,1);
          uVar5 = uVar22 + iVar24 * -4 + iVar17 * 4;
          uVar21 = uVar5 >> 3 & 0x1ffffffc;
          *(uint *)((int)piVar15 + uVar21 + 8) =
               1 << (uVar5 & 0x1f) | *(uint *)((int)piVar15 + uVar21 + 8);
        }
        uVar22 = uVar22 + 1;
      } while (uVar3 != uVar22);
    }
    piVar4 = *(int **)(iVar14 + 0xa0);
    for (piVar11 = (int *)(*(int **)(iVar14 + 0xa0))[1]; piVar11 != (int *)0x0;
        piVar11 = (int *)piVar11[1]) {
      if ((piVar4 == *(int **)(iVar14 + 0x98)) || ((piVar11[5] & 4U) == 0)) {
        bVar1 = piVar4 != (int *)0x0;
        piVar11 = piVar4;
        if (bVar1) {
          do {
            uVar22 = piVar11[5];
            if ((uVar22 & 1) != 0) {
              iVar17 = (**(code **)(*piVar11 + 0x7c))(piVar11);
              if (((iVar17 == 0) && (piVar11[0x20] != 0)) &&
                 (iVar17 = FUN_00126760(piVar11[0x26]), iVar17 != 0)) {
                uVar22 = piVar11[5];
                if ((uVar22 & 2) == 0) {
                  iVar17 = (**(code **)(*piVar11 + 0x50))(piVar11);
                  if (iVar17 != 0) goto code_r0x00132adc;
                  local_58 = UNK_001affec;
                  local_54 = UNK_001afff0;
                  local_50 = UNK_001afff4;
                  local_4c = UNK_001afff8;
                  uVar22 = ((int (*)())FUN_00134bf0)(param_2,piVar11[0x25],param_5);
                  iVar17 = (**(code **)(*piVar11 + 100))(piVar11);
                  if (iVar17 != 0) {
                    for (iVar17 = 1; iVar24 = (**(code **)(*piVar11 + 0x14))(piVar11),
                        iVar17 <= iVar24; iVar17 = iVar17 + 1) {
                      if ((((piVar11[iVar17 * 6 + 0x28] & 1U) != 0) ||
                          ((piVar11[iVar17 * 6 + 0x28] & 2U) != 0)) ||
                         (iVar24 = FUN_000f31e8(piVar11,iVar17), iVar24 == 0))
                      goto code_r0x001327f0;
                    }
                    if ((piVar11[0x48] == 0) && (piVar11[0x49] == 0)) {
                      if ((piVar11[0x20] != 0) &&
                         (((iVar17 = FUN_00126760(piVar11[0x26]), iVar17 != 0 &&
                           ((piVar11[5] & 2U) == 0)) &&
                          (iVar17 = (**(code **)(*piVar11 + 0x50))(piVar11), iVar17 == 0)))) {
                        iVar17 = 4;
                        piVar13 = piVar11;
                        do {
                          if (*(byte *)(piVar13 + 0x27) - 2 < 2) goto code_r0x001327f0;
                          piVar13 = (int *)((int)piVar13 + 1);
                          iVar17 = iVar17 + -1;
                        } while (iVar17 != 0);
                      }
                      FUN_001054ec(piVar11,0);
                      iVar17 = FUN_00105dbc(piVar11,0);
                      if (((iVar17 == 0) && ((piVar11[5] & 2U) == 0)) &&
                         (((((piVar11[5] & 0x200U) == 0 &&
                            ((piVar13 = (int *)FUN_00105594(piVar11,1), piVar13[0x20] != 0 &&
                             (iVar17 = FUN_00126760(piVar13[0x26]), iVar17 != 0)))) &&
                           ((piVar13[5] & 2U) == 0)) &&
                          (iVar17 = (**(code **)(*piVar13 + 0x50))(piVar13), iVar17 == 0)))) {
                        local_58 = ((int (*)())FUN_00134bf0)(param_2,piVar13[0x25],param_5);
                      }
                    }
                  }
code_r0x001327f0:
                  iVar17 = FUN_0013097c(piVar15,uVar22);
                  if (iVar17 == 0) {
                    if ((*(uint *)((uVar22 >> 3 & 0x1ffffffc) + puVar7[5] + 8) >> (uVar22 & 0x1f) &
                        1) != 0) goto code_r0x00132adc;
                    uVar21 = puVar7[2];
                    if (uVar21 < *puVar16) {
                      _memset((void *)(uVar21 * 4 + puVar7[3]),0,4);
                      puVar10 = (uint *)(uVar21 * 4 + puVar7[3]);
                      puVar7[2] = uVar21 + 1;
                    }
                    else {
                      puVar10 = (uint *)FUN_0019423c(puVar16,uVar21);
                    }
                    *puVar10 = uVar22;
                    uVar22 = piVar11[5];
                  }
                  else {
                    iVar17 = 0;
                    if (0 < param_4) {
code_r0x00132828:
                      if ((((((piVar11[5] & 0x200U) == 0) ||
                            (piVar13 = (int *)FUN_00105594(piVar11,piVar11[0x21]),
                            piVar13 == (int *)0x0)) || (piVar13[0x20] == 0)) ||
                          ((iVar24 = FUN_00126760(piVar13[0x26]), iVar24 == 0 ||
                           ((piVar13[5] & 2U) != 0)))) ||
                         (iVar24 = (**(code **)(*piVar13 + 0x50))(piVar13), iVar24 != 0)) {
                        iVar24 = 0;
                        do {
                          iVar20 = FUN_001054ec(piVar11,0);
                          if ((*(char *)(iVar24 + iVar20 + 0x10) != '\x01') &&
                             (iVar20 = FUN_00130958(piVar15,iVar17,iVar24), iVar20 != 0)) {
                            iVar20 = ((int (*)())FUN_00134bf0)(param_2,iVar17,param_5);
                            iVar23 = FUN_001303f4(iVar20,&local_58);
                            if (iVar23 == 0) goto code_r0x00132970;
                          }
                          bVar2 = iVar24 != 3;
                          iVar24 = iVar24 + 1;
                        } while (bVar2);
                      }
                      else {
                        iVar23 = 0;
                        iVar24 = ((int (*)())FUN_00134bf0)(param_2,piVar13[0x25],param_5);
                        do {
                          iVar20 = FUN_00130958(piVar15,iVar17,iVar23);
                          if (((iVar20 != 0) &&
                              (iVar20 = ((int (*)())FUN_00134bf0)(param_2,iVar17,param_5), iVar20 != local_58))
                             && ((iVar24 != iVar20 ||
                                 (iVar9 = FUN_000f313c(piVar11,iVar23), iVar9 != 0))))
                          goto code_r0x00132970;
                          bVar2 = iVar23 != 3;
                          iVar23 = iVar23 + 1;
                        } while (bVar2);
                      }
                      goto code_r0x00132990;
                    }
code_r0x0013299c:
                    if ((((*(int *)(piVar11[0x22] + 8) == 0x32) &&
                         (piVar13 = (int *)FUN_00105594(piVar11,1), piVar13[0x20] != 0)) &&
                        (iVar17 = FUN_00126760(piVar13[0x26]), iVar17 != 0)) &&
                       (((piVar13[5] & 2U) == 0 &&
                        (iVar17 = (**(code **)(*piVar13 + 0x50))(piVar13), iVar17 == 0)))) {
                      iVar17 = FUN_00105594(piVar11,1);
                      uVar18 = ((int (*)())FUN_00134bf0)(param_2,*(undefined4 *)(iVar17 + 0x94),param_5);
                      ((int (*)())FUN_00135334)(param_2,uVar22,uVar18);
                    }
                    iVar17 = (**(code **)(*piVar11 + 0x2c))(piVar11);
                    if (iVar17 == 0) goto code_r0x00132adc;
                    iVar17 = FUN_00105594(piVar11,1);
                    uVar18 = ((int (*)())FUN_00134bf0)(param_2,*(undefined4 *)(iVar17 + 0x94),param_5);
                    ((int (*)())FUN_00135334)(param_2,uVar22,uVar18);
                    uVar22 = piVar11[5];
                  }
                }
              }
              else {
code_r0x00132adc:
                uVar22 = piVar11[5];
              }
            }
            piVar13 = piVar4;
          } while (((int *)piVar11[2] != (int *)0x0) &&
                  (piVar11 = (int *)piVar11[2], (uVar22 & 4) != 0));
          do {
            uVar22 = piVar13[5];
            if ((uVar22 & 1) != 0) {
              iVar17 = (**(code **)(*piVar13 + 0x7c))(piVar13);
              if (((iVar17 == 0) && (piVar13[0x20] != 0)) &&
                 (iVar17 = FUN_00126760(piVar13[0x26]), iVar17 != 0)) {
                uVar22 = piVar13[5];
                if ((uVar22 & 2) != 0) goto code_r0x00132ca8;
                iVar17 = (**(code **)(*piVar13 + 0x50))(piVar13);
                if (iVar17 == 0) {
                  iVar24 = 0;
                  iVar17 = ((int (*)())FUN_00134bf0)(param_2,piVar13[0x25],param_5);
                  uVar21 = iVar17 << 2;
                  uVar22 = uVar21;
                  do {
                    iVar17 = FUN_001054ec(piVar13,0);
                    if (*(char *)(iVar24 + iVar17 + 0x10) != '\x01') {
                      uVar5 = uVar22 >> 3 & 0x1ffffffc;
                      *(uint *)((int)piVar15 + uVar5 + 8) =
                           *(uint *)((int)piVar15 + uVar5 + 8) & ~(1 << (uVar22 & 0x1f));
                    }
                    bVar2 = iVar24 != 3;
                    uVar22 = uVar22 + 1;
                    iVar24 = iVar24 + 1;
                  } while (bVar2);
                  uVar22 = piVar13[5];
                  if ((uVar22 & 0x200) == 0) goto code_r0x00132ca8;
                  piVar11 = (int *)FUN_00105594(piVar13,piVar13[0x21]);
                  if (((piVar11 != (int *)0x0) && (piVar11[0x20] != 0)) &&
                     ((iVar17 = FUN_00126760(piVar11[0x26]), iVar17 != 0 &&
                      (((piVar11[5] & 2U) == 0 &&
                       (iVar17 = (**(code **)(*piVar11 + 0x50))(piVar11), iVar17 == 0)))))) {
                    iVar17 = 0;
                    do {
                      iVar24 = FUN_001054ec(piVar13,0);
                      if ((*(char *)(iVar17 + iVar24 + 0x10) == '\x01') &&
                         (iVar24 = ((int (*)())FUN_00138240)(piVar11,iVar17), iVar24 != 0)) {
                        uVar22 = uVar21 >> 3 & 0x1ffffffc;
                        *(uint *)((int)piVar15 + uVar22 + 8) =
                             *(uint *)((int)piVar15 + uVar22 + 8) & ~(1 << (uVar21 & 0x1f));
                      }
                      bVar2 = iVar17 != 3;
                      uVar21 = uVar21 + 1;
                      iVar17 = iVar17 + 1;
                    } while (bVar2);
                  }
                }
              }
              uVar22 = piVar13[5];
            }
code_r0x00132ca8: ;
          } while (((int *)piVar13[2] != (int *)0x0) &&
                  (piVar13 = (int *)piVar13[2], (uVar22 & 4) != 0));
        }
        while (piVar11 = piVar4, puVar7[2] != 0) {
          uVar22 = puVar7[2] - 1;
          puVar10 = (uint *)0x0;
          if (uVar22 < (uint)puVar7[2]) {
            puVar10 = (uint *)(uVar22 * 4 + puVar7[3]);
          }
          uVar22 = *puVar10;
          FUN_00194208(puVar16,puVar7[2] - 1);
          iVar17 = (uVar22 >> 3 & 0x1ffffffc) + puVar7[5];
          *(uint *)(iVar17 + 8) =
               (-2 << (uVar22 & 0x1f) | 0xfffffffeU >> 0x20 - (uVar22 & 0x1f)) &
               *(uint *)(iVar17 + 8);
          if (0 < param_4) {
            iVar17 = 0;
            do {
              iVar24 = FUN_0013097c(piVar15,iVar17);
              if (iVar24 != 0) {
                uVar18 = ((int (*)())FUN_00134bf0)(param_2,iVar17,param_5);
                ((int (*)())FUN_00135334)(param_2,uVar22,uVar18);
              }
              iVar17 = iVar17 + 1;
            } while (param_4 != iVar17);
          }
        }
        while (bVar1) {
          uVar22 = piVar11[5];
          if ((uVar22 & 1) != 0) {
            iVar17 = FUN_001054ec(piVar11,0);
            if (((((*(int *)(iVar17 + 0x10) != UNK_001affe8) &&
                  (*(int *)(piVar11[0x22] + 8) != 0x8e)) &&
                 (iVar17 = (**(code **)(*piVar11 + 0x34))(piVar11), iVar17 == 0)) &&
                ((iVar17 = (**(code **)(*piVar11 + 0x38))(piVar11), iVar17 == 0 &&
                 (iVar17 = (**(code **)(*piVar11 + 0x60))(piVar11), iVar17 == 0)))) &&
               (iVar17 = (**(code **)(*piVar11 + 0x5c))(piVar11), iVar17 == 0)) {
              uVar22 = piVar11[5];
              iVar17 = piVar11[0x21];
              if ((uVar22 & 0x200) != 0) {
                iVar17 = iVar17 + -1;
              }
              if (0 < iVar17) {
                iVar24 = 1;
                do {
                  piVar13 = (int *)FUN_00105594(piVar11,iVar24);
                  if (((piVar13[0x20] != 0) && (iVar20 = FUN_00126760(piVar13[0x26]), iVar20 != 0))
                     && (((piVar13[5] & 2U) == 0 &&
                         ((iVar20 = (**(code **)(*piVar13 + 0x50))(piVar13), iVar20 == 0 &&
                          (iVar20 = ((int (*)())FUN_00137e98)(piVar11,iVar24,piVar11), iVar20 == 0)))))) {
                    iVar20 = FUN_001054ec(piVar11,iVar24);
                    FUN_000f3398(local_48,*(undefined4 *)(iVar20 + 0x10));
                    local_58 = local_48[0];
                    iVar20 = ((int (*)())FUN_00134bf0)(param_2,piVar13[0x25],param_5);
                    iVar23 = 4;
                    uVar22 = iVar20 << 2;
                    iVar20 = 0;
                    do {
                      if (*(char *)((int)&local_58 + iVar20) != '\0') {
                        uVar21 = uVar22 >> 3 & 0x1ffffffc;
                        *(uint *)((int)piVar15 + uVar21 + 8) =
                             1 << (uVar22 & 0x1f) | *(uint *)((int)piVar15 + uVar21 + 8);
                      }
                      iVar20 = iVar20 + 1;
                      uVar22 = uVar22 + 1;
                      iVar23 = iVar23 + -1;
                    } while (iVar23 != 0);
                  }
                  iVar24 = iVar24 + 1;
                } while (iVar24 <= iVar17);
                uVar22 = piVar11[5];
              }
              if ((uVar22 & 0x200) == 0) goto code_r0x0013304c;
              piVar13 = (int *)FUN_00105594(piVar11,piVar11[0x21]);
              if ((((piVar13 != (int *)0x0) && (piVar13[0x20] != 0)) &&
                  (iVar17 = FUN_00126760(piVar13[0x26]), iVar17 != 0)) &&
                 ((((piVar13[5] & 2U) == 0 &&
                   (iVar17 = (**(code **)(*piVar13 + 0x50))(piVar13), iVar17 == 0)) &&
                  (iVar17 = ((int (*)())FUN_00137e98)(piVar11,piVar11[0x21],piVar11), iVar17 == 0)))) {
                iVar24 = 0;
                iVar17 = ((int (*)())FUN_00134bf0)(param_2,piVar13[0x25],param_5);
                uVar22 = iVar17 << 2;
                do {
                  iVar17 = FUN_001054ec(piVar11,0);
                  if ((*(char *)(iVar24 + iVar17 + 0x10) == '\x01') &&
                     (iVar17 = ((int (*)())FUN_00138240)(piVar13,iVar24), iVar17 != 0)) {
                    uVar21 = uVar22 >> 3 & 0x1ffffffc;
                    *(uint *)((int)piVar15 + uVar21 + 8) =
                         1 << (uVar22 & 0x1f) | *(uint *)((int)piVar15 + uVar21 + 8);
                  }
                  bVar1 = iVar24 != 3;
                  uVar22 = uVar22 + 1;
                  iVar24 = iVar24 + 1;
                } while (bVar1);
              }
            }
            uVar22 = piVar11[5];
          }
code_r0x0013304c:
          if ((int *)piVar11[2] == (int *)0x0) break;
          bVar1 = (uVar22 & 4) != 0;
          piVar11 = (int *)piVar11[2];
        }
        piVar11 = (int *)piVar4[1];
      }
      piVar4 = piVar11;
    }
    iVar14 = *(int *)(iVar14 + 8);
    iVar17 = *(int *)(iVar14 + 8);
  } while( true );
code_r0x00132970:
  ((int (*)())FUN_00135334)(param_2,uVar22,iVar20);
code_r0x00132990:
  iVar17 = iVar17 + 1;
  if (param_4 == iVar17) goto code_r0x0013299c;
  goto code_r0x00132828;
}

/* FUN_001330f4 @ 0x1330f4 (328 bytes) */
int FUN_001330f4(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  do {
    piVar1 = (int *)FUN_00105594(param_2,param_2[0x21]);
    if (((piVar1[0x20] != 0) && (iVar2 = FUN_00126760(piVar1[0x26]), iVar2 != 0)) &&
       ((piVar1[5] & 2U) == 0)) {
      (**(code **)(*piVar1 + 0x50))(piVar1);
    }
    uVar3 = ((int (*)())FUN_00134bf0)(param_1,param_2[0x25],0);
    iVar2 = ((int (*)())FUN_00134bf0)(param_1,piVar1[0x25],0);
    iVar4 = ((int (*)())FUN_0013555c)(param_1,iVar2,uVar3);
  } while (((((iVar4 != 0) && ((piVar1[5] & 0x200U) != 0)) &&
            ((piVar5 = (int *)FUN_00105594(piVar1,piVar1[0x21]), piVar5[0x20] != 0 &&
             ((iVar4 = FUN_00126760(piVar5[0x26]), iVar4 != 0 && ((piVar5[5] & 2U) == 0)))))) &&
           (iVar4 = (**(code **)(*piVar5 + 0x50))(piVar5), iVar4 == 0)) &&
          ((iVar4 = ((int (*)())FUN_00134bf0)(param_1,piVar5[0x25],0), iVar2 != iVar4 &&
           (param_2 = piVar1, piVar1 != (int *)0x0))));
  return;
}

/* FUN_0013323c @ 0x13323c (3348 bytes) */
int FUN_0013323c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  undefined4 *puVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  bool bVar20;
  int iVar21;
  undefined4 uVar22;
  int *piVar23;
  uint *puVar24;
  undefined4 uVar25;
  int *piVar26;
  undefined4 local_98;
  int *local_94;
  uint local_90;
  uint local_8c;
  int local_88;
  undefined4 local_84;
  uint local_80;
  uint local_7c;
  int local_78;
  undefined4 local_74;
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c [6];
  
  local_74 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_7c = 0;
  local_80 = 2;
  local_78 = FUN_00193e18(local_74,8);
  local_84 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_8c = 0;
  local_90 = 2;
  local_88 = FUN_00193e18(local_84,8);
  iVar6 = FUN_000ee7a0(param_1);
  iVar3 = *(int *)(param_1 + 0x248);
  uVar25 = 0;
  do {
    *(undefined4 *)(param_1 + 0x250) = 0;
    if (0 < iVar3) {
      ((int (*)())FUN_00135278)(param_2);
      ((int (*)())FUN_00134db0)(param_2);
      local_8c = 0;
    }
    *(int *)(*(int *)(param_1 + 8) + 0x39c) = *(int *)(*(int *)(param_1 + 8) + 0x39c) + 1;
    piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
    (**(code **)(*piVar7 + 0x148))
              (piVar7,param_2,*(undefined4 *)(param_1 + 0x46c),*(undefined4 *)(param_1 + 0x464),
               uVar25);
    iVar19 = 0;
    for (iVar3 = 0; iVar8 = FUN_00194034(param_1 + 0x37c), iVar3 < iVar8; iVar3 = iVar3 + 1) {
      bVar20 = false;
      iVar8 = *(int *)(iVar6 + iVar3 * 4);
      piVar14 = *(int **)(iVar8 + 0x98);
      piVar7 = (int *)piVar14[2];
      if (piVar7 != (int *)0x0) {
        do {
          piVar23 = piVar14;
          if (piVar14 != (int *)0x0) {
            piVar7 = (int *)0x0;
            piVar26 = piVar14;
            do {
              uVar16 = piVar26[5];
              if ((uVar16 & 1) == 0) goto LAB_001339e4;
              iVar9 = (**(code **)(*piVar26 + 0x7c))(piVar26);
              if (iVar9 == 0) {
                if ((piVar26[5] & 0x10000U) == 0) {
                  if (piVar7 == (int *)0x0) {
                    piVar7 = piVar26;
                  }
                  if (bVar20) {
                    bVar20 = false;
                    piVar26[5] = piVar26[5] | 0x1000;
                  }
                }
                if (((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x200) != 0) &&
                   (((((iVar9 = (**(code **)(*piVar26 + 0x28))(piVar26), iVar9 != 0 ||
                       (iVar9 = (**(code **)(*piVar26 + 0x68))(piVar26), iVar9 != 0)) &&
                      (piVar10 = (int *)FUN_00105594(piVar26,1), piVar10[0x20] != 0)) &&
                     ((iVar9 = FUN_00126760(piVar10[0x26]), iVar9 != 0 && ((piVar10[5] & 2U) == 0)))
                     ) && (iVar9 = (**(code **)(*piVar10 + 0x50))(piVar10), iVar9 == 0)))) {
                  iVar9 = FUN_001054ec(piVar26,1);
                  FUN_000f3398(&local_68,*(undefined4 *)(iVar9 + 0x10));
                  iVar21 = 0;
                  local_98 = local_68;
                  iVar9 = -1;
                  do {
                    iVar13 = iVar9;
                    if ((((*(char *)((int)&local_98 + iVar21) != '\0') &&
                         (piVar11 = (int *)((int (*)())FUN_001382b8)(piVar10,iVar21,&local_94),
                         piVar11 != (int *)0x0)) &&
                        ((piVar11[0x20] != 0 &&
                         (((iVar12 = FUN_00126760(piVar11[0x26]), iVar12 != 0 &&
                           ((piVar11[5] & 2U) == 0)) &&
                          (iVar12 = (**(code **)(*piVar11 + 0x50))(piVar11), iVar12 == 0)))))) &&
                       ((iVar13 = ((int (*)())FUN_00134bf0)(param_2,piVar11[0x25],iVar19), uVar16 = local_8c,
                        iVar9 != -1 && (bVar2 = iVar9 != iVar13, iVar13 = iVar9, bVar2)))) {
                      if (local_8c < local_90) {
                        iVar9 = local_8c * 4;
                        _memset((void *)(iVar9 + local_88),0,4);
                        local_8c = uVar16 + 1;
                        puVar15 = (undefined4 *)(iVar9 + local_88);
                      }
                      else {
                        puVar15 = (undefined4 *)FUN_0019423c(&local_90,local_8c);
                      }
                      *puVar15 = piVar26;
                      break;
                    }
                    bVar2 = iVar21 != 3;
                    iVar21 = iVar21 + 1;
                    iVar9 = iVar13;
                  } while (bVar2);
                }
                if ((((piVar26[5] & 0x200U) != 0) &&
                    (piVar10 = (int *)FUN_00105594(piVar26,piVar26[0x21]), (piVar10[5] & 1U) != 0))
                   && ((piVar10[0x20] != 0 &&
                       (((iVar9 = FUN_00126760(piVar10[0x26]), iVar9 != 0 &&
                         ((piVar10[5] & 2U) == 0)) &&
                        (iVar9 = (**(code **)(*piVar10 + 0x50))(piVar10), iVar9 == 0)))))) {
                  iVar9 = ((int (*)())FUN_00134bf0)(param_2,piVar26[0x25],iVar19);
                  iVar21 = ((int (*)())FUN_00134bf0)(param_2,piVar10[0x25],iVar19);
                  if (iVar9 != iVar21) {
                    if (((piVar26[5] & 0x40U) == 0) || ((piVar10[5] & 0x40U) == 0)) {
                      if ((*(int *)(iVar9 * 4 + *(int *)(param_1 + 0x45c)) ==
                           *(int *)(iVar21 * 4 + *(int *)(param_1 + 0x45c))) &&
                         (iVar9 = ((int (*)())FUN_00135c20)(param_2,iVar9,iVar21), iVar9 != 0)) {
                        iVar19 = 1;
                        *(int *)(param_1 + 0x24c) = *(int *)(param_1 + 0x24c) + 1;
                      }
                      else {
                        *(int *)(param_1 + 0x250) = *(int *)(param_1 + 0x250) + 1;
                      }
                    }
                    else if ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x200) == 0)
                    {
                      ((int (*)())FUN_001315f8)(param_2,piVar26,piVar10,param_1 + 0x464,piVar14,iVar8);
                    }
                  }
                }
                iVar9 = (**(code **)(*piVar26 + 100))(piVar26);
                if (iVar9 == 0) goto LAB_001339e0;
                puVar24 = (uint *)(piVar26 + 0x2e);
                for (iVar9 = 1; iVar21 = (**(code **)(*piVar26 + 0x14))(piVar26), iVar9 <= iVar21;
                    iVar9 = iVar9 + 1) {
                  uVar16 = *puVar24;
                  puVar24 = puVar24 + 6;
                  if ((((uVar16 & 1) != 0) || ((uVar16 & 2) != 0)) ||
                     (iVar21 = FUN_000f31e8(piVar26,iVar9), iVar21 == 0)) goto LAB_001339e0;
                }
                if ((piVar26[0x48] != 0) || (piVar26[0x49] != 0)) goto LAB_001339e0;
                if (((piVar26[0x20] != 0) &&
                    ((iVar9 = FUN_00126760(piVar26[0x26]), iVar9 != 0 && ((piVar26[5] & 2U) == 0))))
                   && (iVar9 = (**(code **)(*piVar26 + 0x50))(piVar26), iVar9 == 0)) {
                  iVar9 = 4;
                  piVar10 = piVar26;
                  do {
                    if (*(byte *)(piVar10 + 0x27) - 2 < 2) goto LAB_001339e0;
                    piVar10 = (int *)((int)piVar10 + 1);
                    iVar9 = iVar9 + -1;
                  } while (iVar9 != 0);
                }
                FUN_001054ec(piVar26,0);
                iVar9 = FUN_00105dbc(piVar26,0);
                if (iVar9 != 0) goto LAB_001339e0;
                uVar16 = piVar26[5];
                if ((((uVar16 & 2) == 0) && ((uVar16 & 0x200) == 0)) && (-1 < (int)uVar16)) {
                  piVar10 = (int *)FUN_00105594(piVar26,1);
                  if (((piVar10[0x20] != 0) && (iVar9 = FUN_00126760(piVar10[0x26]), iVar9 != 0)) &&
                     (((piVar10[5] & 2U) == 0 &&
                      (iVar9 = (**(code **)(*piVar10 + 0x50))(piVar10), iVar9 == 0)))) {
                    iVar9 = ((int (*)())FUN_00134bf0)(param_2,piVar26[0x25],iVar19);
                    iVar21 = ((int (*)())FUN_00134bf0)(param_2,piVar10[0x25],iVar19);
                    if (((0 < *(int *)(*(int *)(param_1 + 8) + 0x678)) &&
                        (*(int *)(iVar9 * 4 + *(int *)(param_1 + 0x45c)) ==
                         *(int *)(iVar21 * 4 + *(int *)(param_1 + 0x45c)))) &&
                       (iVar13 = ((int (*)())FUN_00135c20)(param_2,iVar9,iVar21), uVar16 = local_7c, iVar13 != 0)
                       ) {
                      *(int *)(param_1 + 0x254) = *(int *)(param_1 + 0x254) + 1;
                      if ((piVar26[5] & 0x1000U) != 0) {
                        if ((piVar7 == (int *)0x0) || (piVar7 == piVar26)) {
                          bVar20 = true;
                        }
                        else {
                          piVar7[5] = piVar7[5] | 0x1000;
                        }
                      }
                      if (((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x200) == 0) ||
                         ((piVar26[5] & 0x40000000U) == 0)) {
                        (**(code **)(*piVar26 + 0xc))(piVar26,0);
                        uVar16 = piVar26[5];
                        iVar19 = 1;
                      }
                      else {
                        if (local_7c < local_80) {
                          iVar19 = local_7c * 4;
                          _memset((void *)(iVar19 + local_78),0,4);
                          local_7c = uVar16 + 1;
                          puVar15 = (undefined4 *)(iVar19 + local_78);
                        }
                        else {
                          puVar15 = (undefined4 *)FUN_0019423c(&local_80,local_7c);
                        }
                        *puVar15 = piVar26;
                        iVar19 = 1;
                        uVar16 = piVar26[5] | 0x80000000;
                        piVar26[5] = uVar16;
                      }
                      goto LAB_001339e4;
                    }
                    if ((*(int *)(param_1 + 0x46c) <= iVar9) &&
                       (*(int *)(iVar9 * 4 + *(int *)(param_1 + 0x45c)) ==
                        *(int *)(iVar21 * 4 + *(int *)(param_1 + 0x45c)))) {
                      ((int (*)())FUN_00135684)(param_2,iVar9,iVar21);
                    }
                  }
                  goto LAB_001339e0;
                }
              }
              else {
LAB_001339e0:
                uVar16 = piVar26[5];
              }
LAB_001339e4:
              piVar26 = (int *)piVar26[2];
            } while ((piVar26 != (int *)0x0) && ((uVar16 & 4) != 0));
            piVar7 = (int *)piVar14[2];
          }
          do {
            piVar14 = piVar7;
            puVar24 = (uint *)(piVar23 + 5);
            piVar7 = (int *)piVar14[2];
            if (piVar7 == (int *)0x0) {
              if (bVar20) {
                iVar9 = 0;
                local_94 = (int *)0x0;
                for (uVar16 = 1; uVar16 <= *(uint *)(*(int *)(iVar8 + 0xd0) + 4);
                    uVar16 = uVar16 + 1) {
                  local_94 = *(int **)(iVar9 + *(int *)(*(int *)(iVar8 + 0xd0) + 8));
                  if (local_94 != (int *)0x0) {
                    iVar21 = (**(code **)(*local_94 + 0x30))();
                    if (iVar21 == 0) {
                      local_94[0x37] = 1;
                    }
                    else {
                      *(undefined4 *)(local_94[0x4b] + 0xdc) = 1;
                    }
                  }
                  iVar9 = iVar9 + 4;
                }
              }
              goto LAB_00133348;
            }
            piVar23 = piVar14;
          } while ((*puVar24 & 4) != 0);
        } while( true );
      }
LAB_00133348: ;
    }
    iVar3 = *(int *)(param_1 + 0x248) + 1;
    *(int *)(param_1 + 0x248) = iVar3;
    if (iVar19 == 0) {
      iVar19 = *(int *)(param_1 + 8);
      bVar20 = false;
      goto LAB_00133af8;
    }
    iVar19 = 0;
    if (0 < *(int *)(param_1 + 0x464)) {
      do {
        ((int (*)())FUN_00134bf0)(param_2,iVar19,1);
        iVar19 = iVar19 + 1;
      } while (iVar19 < *(int *)(param_1 + 0x464));
      iVar3 = *(int *)(param_1 + 0x248);
    }
    iVar19 = *(int *)(param_1 + 8);
    if (*(int *)(iVar19 + 0x678) <= iVar3) break;
    uVar25 = 1;
  } while( true );
  bVar20 = true;
LAB_00133af8:
  *(undefined4 *)(param_1 + 0x34) = 5;
  if ((*(uint *)(*(int *)(iVar19 + 0x30c) + 8) & 0x200) != 0) {
LAB_00133bf0:
    if (local_7c != 0) {
      uVar16 = local_7c - 1;
      puVar15 = (undefined4 *)0x0;
      if (uVar16 < local_7c) {
        puVar15 = (undefined4 *)(uVar16 * 4 + local_78);
      }
      piVar14 = (int *)*puVar15;
      FUN_00194208(&local_80,uVar16);
      iVar3 = ((int (*)())FUN_00134bf0)(param_2,piVar14[0x25],0);
      piVar7 = (int *)FUN_00105594(piVar14,1);
      do {
        iVar6 = (**(code **)(*piVar7 + 0x50))(piVar7);
        if (iVar6 != 0) {
LAB_00133bd0:
          (**(code **)(*piVar14 + 0xc))(piVar14,0,*(undefined4 *)(param_1 + 8));
          break;
        }
        iVar6 = ((int (*)())FUN_00134bf0)(param_2,piVar7[0x25],0);
        if ((piVar7[5] & 0x200U) == 0) {
          if (iVar3 == iVar6) goto LAB_00133bd0;
          break;
        }
        piVar7 = (int *)FUN_00105594(piVar7,piVar7[0x21]);
      } while (iVar3 == iVar6);
      goto LAB_00133bf0;
    }
    if (local_8c != 0) {
      ((int (*)())FUN_00137694)(param_2,local_8c);
      uVar16 = local_8c;
      while (local_8c != 0) {
        uVar17 = local_8c - 1;
        puVar15 = (undefined4 *)0x0;
        if (uVar17 < local_8c) {
          puVar15 = (undefined4 *)(uVar17 * 4 + local_88);
        }
        uVar22 = *puVar15;
        FUN_00194208(&local_90,uVar17);
        *(int *)(param_1 + 600) = *(int *)(param_1 + 600) + 1;
        uVar25 = FUN_00105594(uVar22,1);
        piVar14 = (int *)FUN_00130c8c(param_2,uVar22,uVar25,param_1 + 0x464);
        iVar3 = FUN_001054ec(uVar22,1);
        FUN_000f366c(&local_64,*(undefined4 *)(iVar3 + 0x10));
        piVar14[0x27] = local_64;
        FUN_000f370c(&local_60,local_64);
        uVar25 = local_60;
        iVar3 = FUN_001054ec(piVar14,1);
        *(undefined4 *)(iVar3 + 0x10) = uVar25;
        FUN_000f3398(local_5c,uVar25);
        local_98 = local_5c[0];
        uVar25 = FUN_00105594(piVar14,1);
        iVar3 = 0;
        piVar7 = piVar14;
        do {
          if ((*(char *)((int)&local_98 + iVar3) != '\0') &&
             (iVar6 = ((int (*)())FUN_001382b8)(uVar25,iVar3,&local_94), iVar6 == 0)) {
            *(undefined1 *)(piVar7 + 0x27) = 1;
            (**(code **)(*piVar14 + 0x88))(piVar14,1,iVar3,4);
          }
          bVar2 = iVar3 != 3;
          piVar7 = (int *)((int)piVar7 + 1);
          iVar3 = iVar3 + 1;
        } while (bVar2);
        FUN_00106004(uVar22,1,piVar14,0,*(undefined4 *)(param_1 + 8));
      }
      piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
      (**(code **)(*piVar7 + 0x14c))(piVar7,param_1);
      iVar6 = *(int *)(param_1 + 900);
      iVar3 = *(int *)(param_1 + 0x464) * 4;
      if (*(int *)(iVar6 + 8) != 0) {
        uVar17 = iVar3 + 0x1fU >> 5;
        do {
          puVar24 = *(uint **)(iVar6 + 0x104);
          uVar4 = uVar16 * 4 + puVar24[1];
          if (uVar4 + 0x1f >> 5 == *puVar24) {
            uVar18 = uVar4 + uVar16 * -4;
            puVar24[1] = uVar4;
            if (uVar18 < uVar4) {
              iVar19 = uVar4 - uVar18;
              if (uVar4 < uVar18 + 1) {
                iVar19 = 1;
              }
              do {
                uVar5 = uVar18 >> 3 & 0x1ffffffc;
                uVar4 = uVar18 & 0x1f;
                uVar18 = uVar18 + 1;
                *(uint *)((int)puVar24 + uVar5 + 8) =
                     *(uint *)((int)puVar24 + uVar5 + 8) & ~(1 << uVar4);
                iVar19 = iVar19 + -1;
              } while (iVar19 != 0);
            }
          }
          else {
            uVar25 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
            puVar15 = (undefined4 *)FUN_00193e18(uVar25,uVar17 * 4 + 0xc);
            piVar7 = puVar15 + 1;
            *puVar15 = uVar25;
            puVar15[1] = uVar17;
            puVar15[2] = iVar3;
            if (uVar17 != 0) {
              uVar4 = uVar17;
              piVar14 = piVar7;
              if (uVar17 == 0) {
                uVar4 = 1;
              }
              do {
                uVar4 = uVar4 - 1;
                piVar14[2] = 0;
                piVar14 = piVar14 + 1;
              } while (uVar4 != 0);
            }
            *(int **)(iVar6 + 0x104) = piVar7;
            iVar19 = *piVar7;
            if (iVar19 != 0) {
              if (iVar19 == 0) {
                iVar19 = 1;
              }
              do {
                iVar19 = iVar19 + -1;
                puVar1 = puVar24 + 2;
                puVar24 = puVar24 + 1;
                piVar7[2] = piVar7[2] | *puVar1;
                piVar7 = piVar7 + 1;
              } while (iVar19 != 0);
            }
          }
          iVar6 = *(int *)(iVar6 + 8);
        } while (*(int *)(iVar6 + 8) != 0);
      }
      ((int (*)())FUN_00135278)(param_2);
      ((int (*)())FUN_00134db0)(param_2);
      piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
      (**(code **)(*piVar7 + 0x148))
                (piVar7,param_2,*(undefined4 *)(param_1 + 0x46c),*(undefined4 *)(param_1 + 0x464),1)
      ;
    }
  }
  if (bVar20) {
    ((int (*)())FUN_00135278)(param_2);
    ((int (*)())FUN_00134db0)(param_2);
    piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
    (**(code **)(*piVar7 + 0x148))
              (piVar7,param_2,*(undefined4 *)(param_1 + 0x46c),*(undefined4 *)(param_1 + 0x464),0);
  }
  FUN_00193cc0(local_84,local_88);
  FUN_00193cc0(local_74,local_78);
  return;
}

/* FUN_00133fe4 @ 0x133fe4 (140 bytes) */
int FUN_00133fe4(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  uint *puVar11;
  int iVar12;
  undefined4 uVar13;
  uint uVar14;
  int iVar15;
  int *piVar16;
  undefined4 uVar17;
  int *piVar18;
  uint uVar19;
  
  iVar10 = *(int *)(*(int *)(param_1 + 0x2c) + 0x6c4);
  uVar1 = ((int (*)())FUN_00131c10)(iVar10);
  uVar17 = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378);
  puVar2 = (undefined4 *)FUN_00193e18(uVar17,0x14);
  puVar11 = puVar2 + 1;
  *puVar2 = uVar17;
  puVar2[1] = 2;
  puVar2[2] = 0;
  puVar2[4] = uVar17;
  uVar17 = FUN_00193e18(uVar17,8);
  puVar2[3] = uVar17;
  uVar17 = 0;
  iVar12 = *(int *)(iVar10 + 900);
  iVar7 = *(int *)(*(int *)(iVar10 + 900) + 8);
  do {
    if (iVar7 == 0) {
      iVar12 = puVar2[2];
      if (0 < iVar12) {
        uVar17 = 1;
      }
      if (iVar12 == 0) {
        iVar7 = *(int *)(iVar10 + 0x454);
      }
      else {
        do {
          piVar16 = (int *)0x0;
          if (iVar12 - 1U < (uint)puVar2[2]) {
            piVar16 = (int *)((iVar12 - 1U) * 4 + puVar2[3]);
          }
          iVar12 = *piVar16;
          FUN_00194208(puVar11,puVar2[2] - 1);
          uVar5 = FUN_001308e0(iVar12);
          FUN_00130abc(uVar5);
          uVar5 = ((int (*)())FUN_001318a4)(param_1,*(undefined4 *)(iVar12 + 0x94),uVar1);
          uVar6 = thunk_FUN_001307f8(iVar12);
          FUN_001312f4(iVar12,uVar1,uVar5,uVar6,*(undefined4 *)(param_1 + 0x2c));
          iVar7 = *(int *)(iVar10 + 0x454) + 1;
          *(int *)(iVar10 + 0x454) = iVar7;
          iVar12 = puVar2[2];
        } while (iVar12 != 0);
      }
      ((int (*)())FUN_00131c74)(iVar10,uVar1,iVar7 << 2);
      return uVar17;
    }
    piVar16 = (int *)(*(int **)(iVar12 + 0x98))[2];
    piVar18 = *(int **)(iVar12 + 0x98);
    if (piVar16 != (int *)0x0) {
      do {
        piVar9 = piVar16;
        if (((piVar18[5] & 1U) != 0) && (*(int *)(piVar18[0x22] + 8) != 0x8e)) {
          iVar7 = (**(code **)(*piVar18 + 0x78))(piVar18);
          if ((iVar7 == 0) && (0 < piVar18[0x21])) {
            iVar7 = 1;
            do {
              piVar16 = (int *)FUN_00105594(piVar18,iVar7);
              if ((((piVar16[0x20] != 0) && (iVar3 = FUN_00126760(piVar16[0x26]), iVar3 != 0)) &&
                  ((piVar16[5] & 2U) == 0)) &&
                 (iVar3 = (**(code **)(*piVar16 + 0x50))(piVar16), iVar3 == 0)) {
                iVar15 = piVar16[0x25];
                iVar3 = FUN_001309bc(param_1,iVar15);
                if (iVar3 != 0) {
                  iVar3 = *piVar18;
                  piVar16[5] = piVar16[5] | 0x8000000;
                  iVar3 = (**(code **)(iVar3 + 0x14))(piVar18);
                  if ((iVar7 <= iVar3) && (iVar3 = FUN_00131008(1,piVar18,iVar7), iVar3 != 0)) {
                    FUN_00130abc(piVar18);
                    if (((piVar16[5] & 0x20000000U) == 0) || ((piVar16[6] & 1U) != 0)) {
                      iVar3 = ((int (*)())FUN_001318a4)(param_1,iVar15,uVar1);
                      iVar15 = FUN_00130a08(piVar18,*(undefined4 *)(iVar3 + 0x13c));
                      if (iVar15 == 0) {
                        uVar5 = FUN_00130424(param_1);
                        iVar15 = FUN_001054ec(piVar18,iVar7);
                        uVar13 = *(undefined4 *)(iVar15 + 0x10);
                        uVar6 = FUN_00130904(piVar18);
                        iVar15 = FUN_001311cc(uVar5,uVar13,uVar1,iVar3,uVar6,
                                              *(undefined4 *)(param_1 + 0x2c));
                      }
                      FUN_00106004(piVar18,iVar7,iVar15,0,*(undefined4 *)(param_1 + 0x2c));
                      uVar14 = puVar2[2];
                      if (0 < (int)uVar14) {
                        uVar8 = 0;
                        uVar19 = uVar14;
                        do {
                          piVar9 = (int *)0x0;
                          if (uVar8 < uVar14) {
                            piVar9 = (int *)(uVar8 * 4 + puVar2[3]);
                          }
                          if (piVar16 == (int *)*piVar9) goto code_r0x001342f8;
                          uVar8 = uVar8 + 1;
                          uVar19 = uVar19 - 1;
                        } while (uVar19 != 0);
                      }
                      if (uVar14 < *puVar11) {
                        _memset((void *)(uVar14 * 4 + puVar2[3]),0,4);
                        puVar2[2] = uVar14 + 1;
                        puVar4 = (undefined4 *)(uVar14 * 4 + puVar2[3]);
                      }
                      else {
                        puVar4 = (undefined4 *)FUN_0019423c(puVar11,uVar14);
                      }
                      *puVar4 = piVar16;
                    }
                    else {
                      uVar17 = 1;
                      uVar5 = FUN_00130904(piVar18);
                      FUN_00130da0(param_1,piVar18,iVar7,uVar5,*(undefined4 *)(param_1 + 0x2c));
                    }
                  }
                }
              }
code_r0x001342f8:
              iVar7 = iVar7 + 1;
            } while (iVar7 <= piVar18[0x21]);
          }
          piVar9 = (int *)piVar18[2];
        }
        piVar16 = (int *)piVar9[2];
        piVar18 = piVar9;
      } while ((int *)piVar9[2] != (int *)0x0);
      iVar7 = *(int *)(iVar12 + 8);
    }
    iVar12 = iVar7;
    iVar7 = *(int *)(iVar7 + 8);
  } while( true );
}

/* FUN_00134400 @ 0x134400 (600 bytes) */
int FUN_00134400(param_1)
  int param_1;
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  uint *puVar8;
  int *piVar9;
  
  iVar7 = *(int *)(*(int *)(*(int *)(param_1 + 0x2c) + 0x6c4) + 900);
  iVar3 = *(int *)(iVar7 + 8);
  do {
    if (iVar3 == 0) {
      return;
    }
    piVar1 = (int *)(*(int **)(iVar7 + 0xa0))[1];
    piVar9 = *(int **)(iVar7 + 0xa0);
    if (piVar1 != (int *)0x0) {
      do {
        piVar5 = piVar1;
        if (((piVar9 == *(int **)(iVar7 + 0x98)) || ((piVar5[5] & 4U) == 0)) &&
           (piVar1 = piVar9, piVar9 != (int *)0x0)) {
          do {
            uVar2 = piVar1[5];
            if ((uVar2 & 1) != 0) {
              iVar3 = 0;
              if (piVar1[0x20] != 0) {
                iVar3 = FUN_00126760(piVar1[0x26]);
                if (((iVar3 == 0) || ((piVar1[5] & 2U) != 0)) ||
                   ((iVar3 = (**(code **)(*piVar1 + 0x50))(piVar1), iVar3 != 0 ||
                    ((piVar1[5] & 0x8000000U) == 0)))) {
                  iVar3 = piVar1[0x20];
                }
                else {
                  puVar8 = *(uint **)(param_1 + 4);
                  uVar2 = piVar1[0x25];
                  if (uVar2 < *puVar8) {
                    uVar4 = puVar8[1];
                    if (uVar4 <= uVar2) {
                      _memset((void *)(uVar4 * 4 + puVar8[2]),0,(uVar2 - uVar4) * 4 + 4);
                      puVar8[1] = uVar2 + 1;
                    }
                    piVar5 = (int *)(uVar2 * 4 + puVar8[2]);
                  }
                  else {
                    piVar5 = (int *)FUN_0019423c(puVar8,uVar2);
                  }
                  *(undefined4 *)(*piVar5 + 0x18) = 1;
                  iVar3 = piVar1[0x20];
                }
              }
              if ((iVar3 == 0) || (iVar3 = FUN_00126760(piVar1[0x26]), iVar3 == 0)) {
LAB_001345fc:
                uVar2 = piVar1[5];
              }
              else {
                uVar2 = piVar1[5];
                if ((uVar2 & 2) == 0) {
                  iVar3 = (**(code **)(*piVar1 + 0x50))(piVar1);
                  if (iVar3 != 0) goto LAB_001345fc;
                  puVar8 = *(uint **)(param_1 + 4);
                  uVar2 = piVar1[0x25];
                  if (uVar2 < *puVar8) {
                    uVar4 = puVar8[1];
                    if (uVar4 <= uVar2) {
                      _memset((void *)(uVar4 * 4 + puVar8[2]),0,(uVar2 - uVar4) * 4 + 4);
                      puVar8[1] = uVar2 + 1;
                    }
                    puVar6 = (undefined4 *)(uVar2 * 4 + puVar8[2]);
                  }
                  else {
                    puVar6 = (undefined4 *)FUN_0019423c(puVar8,uVar2);
                  }
                  ((int (*)())FUN_00134aa8)(*puVar6,piVar1[0x1f]);
                  uVar2 = piVar1[5];
                }
              }
            }
          } while (((int *)piVar1[2] != (int *)0x0) && (piVar1 = (int *)piVar1[2], (uVar2 & 4) != 0)
                  );
          piVar5 = (int *)piVar9[1];
        }
        piVar1 = (int *)piVar5[1];
        piVar9 = piVar5;
      } while ((int *)piVar5[1] != (int *)0x0);
      iVar3 = *(int *)(iVar7 + 8);
    }
    iVar7 = iVar3;
    iVar3 = *(int *)(iVar3 + 8);
  } while( true );
}

/* FUN_00134658 @ 0x134658 (612 bytes) */
int FUN_00134658(param_1)
  int param_1;
{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  int *piVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
  FUN_001314b8(param_1);
  iVar9 = *(int *)(param_1 + 8);
  if (*(int *)(iVar9 + 0x3c4) == -1) {
    return;
  }
  *(undefined4 *)(param_1 + 0x454) = 0;
  *(undefined4 *)(param_1 + 0x438) = 0;
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x400;
  piVar10 = *(int **)(iVar9 + 0x30c);
  iVar4 = (**(code **)(*piVar10 + 0x138))(piVar10,iVar9);
  iVar5 = (**(code **)(*piVar10 + 0x140))(piVar10,iVar9);
  iVar9 = (**(code **)(*piVar10 + 0x13c))(piVar10,iVar9);
  iVar9 = iVar4 + iVar5 + iVar9;
  uVar11 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  uVar14 = iVar9 + 0x1fU >> 5;
  iVar4 = uVar14 * 4 + 0xc;
  puVar6 = (undefined4 *)FUN_00193e18(uVar11,iVar4);
  puVar8 = puVar6 + 1;
  *puVar6 = uVar11;
  puVar6[1] = uVar14;
  puVar6[2] = iVar9;
  if (uVar14 == 0) {
    uVar13 = *puVar8;
  }
  else {
    puVar2 = puVar8;
    uVar12 = uVar14;
    if (uVar14 == 0) {
      uVar12 = 1;
    }
    do {
      puVar2[2] = 0;
      puVar2 = puVar2 + 1;
      uVar12 = uVar12 - 1;
      uVar13 = uVar14;
    } while (uVar12 != 0);
  }
  iVar5 = *(int *)(param_1 + 0x42c);
  if (uVar13 != 0) {
    puVar2 = puVar8;
    if (uVar13 == 0) {
      uVar13 = 1;
    }
    do {
      puVar3 = (uint *)(iVar5 + 8);
      iVar5 = iVar5 + 4;
      puVar2[2] = *puVar3;
      puVar2 = puVar2 + 1;
      uVar13 = uVar13 - 1;
    } while (uVar13 != 0);
  }
  uVar11 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  puVar6 = (undefined4 *)FUN_00193e18(uVar11,iVar4);
  puVar2 = puVar6 + 1;
  *puVar6 = uVar11;
  puVar6[1] = uVar14;
  puVar6[2] = iVar9;
  if (uVar14 == 0) {
    uVar14 = *puVar2;
  }
  else {
    puVar3 = puVar2;
    uVar13 = uVar14;
    if (uVar14 == 0) {
      uVar13 = 1;
    }
    do {
      puVar3[2] = 0;
      puVar3 = puVar3 + 1;
      uVar13 = uVar13 - 1;
    } while (uVar13 != 0);
  }
  iVar9 = *(int *)(param_1 + 0x430);
  if (uVar14 != 0) {
    puVar3 = puVar2;
    if (uVar14 == 0) {
      uVar14 = 1;
    }
    do {
      puVar1 = (uint *)(iVar9 + 8);
      iVar9 = iVar9 + 4;
      puVar3[2] = *puVar1;
      puVar3 = puVar3 + 1;
      uVar14 = uVar14 - 1;
    } while (uVar14 != 0);
  }
  iVar9 = 0;
  do {
    uVar11 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
    puVar6 = (undefined4 *)FUN_00193e18(uVar11,0x34);
    *puVar6 = uVar11;
    ((int (*)())FUN_0013719c)(puVar6 + 1,*(undefined4 *)(param_1 + 0x46c),*(undefined4 *)(param_1 + 0x464),
                 param_1,*(undefined4 *)(param_1 + 8));
    *(undefined4 **)(param_1 + 0x3c0) = puVar6 + 1;
    ((int (*)())FUN_00131d08)(param_1,*(undefined4 *)(param_1 + 0x468),*(undefined4 *)(param_1 + 0x46c),
                 *(undefined4 *)(param_1 + 0x464),iVar9);
    if (iVar9 != 0) {
      ((int (*)())FUN_00134400)(*(undefined4 *)(param_1 + 0x3c0));
    }
    piVar10 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
    (**(code **)(*piVar10 + 0x144))(piVar10,*(undefined4 *)(param_1 + 0x464),param_1);
    ((int (*)())FUN_0013323c)(param_1,*(undefined4 *)(param_1 + 0x3c0));
    ((int (*)())FUN_00138080)(param_1);
    if (iVar9 != 0) {
      ((int (*)())FUN_001378e8)(*(undefined4 *)(param_1 + 0x3c0),*(undefined4 *)(param_1 + 8));
    }
    iVar9 = ((int (*)())FUN_00135fb0)(*(undefined4 *)(param_1 + 0x3c0));
    if (iVar9 != 0) {
      iVar5 = *(int *)(*(int *)(param_1 + 0x3c0) + 0x24);
      iVar4 = *(int *)(iVar5 + 4);
      if (iVar4 == 0) {
code_r0x001348ac:
        iVar4 = *(int *)(param_1 + 8);
      }
      else {
        uVar14 = 0;
        iVar7 = 0;
        do {
          if ((*(uint *)((uVar14 >> 3 & 0x1ffffffc) + iVar5 + 8) >> (uVar14 & 0x1f) & 1) != 0) {
            iVar7 = iVar7 + 1;
          }
          uVar14 = uVar14 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        if (iVar7 == 0) goto code_r0x001348ac;
        iVar4 = *(int *)(param_1 + 8);
        if (*(int *)(param_1 + 0x264) < *(int *)(iVar4 + 0x67c)) {
          *(int *)(param_1 + 0x264) = *(int *)(param_1 + 0x264) + 1;
          ((int (*)())FUN_00133fe4)(*(int *)(param_1 + 0x3c0));
          piVar10 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
          (**(code **)(*piVar10 + 0x14c))(piVar10,param_1);
          piVar10 = *(int **)(param_1 + 0x42c);
          iVar4 = *piVar10;
          if (iVar4 != 0) {
            puVar3 = puVar8;
            if (iVar4 == 0) {
              iVar4 = 1;
            }
            do {
              puVar1 = puVar3 + 2;
              puVar3 = puVar3 + 1;
              piVar10[2] = *puVar1;
              piVar10 = piVar10 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          piVar10 = *(int **)(param_1 + 0x430);
          iVar4 = *piVar10;
          if (iVar4 != 0) {
            puVar3 = puVar2;
            if (iVar4 == 0) {
              iVar4 = 1;
            }
            do {
              puVar1 = puVar3 + 2;
              puVar3 = puVar3 + 1;
              piVar10[2] = *puVar1;
              piVar10 = piVar10 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          FUN_001314b8(param_1);
          goto LAB_00134a58;
        }
      }
      FUN_000e1534(iVar4,4);
    }
LAB_00134a58:
    iVar4 = *(int *)(param_1 + 0x3c0);
    if (iVar4 != 0) {
      ((int (*)())FUN_001357d4)(iVar4);
      FUN_00193cc0(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
    }
    if (iVar9 == 0) {
      *(undefined4 *)(param_1 + 0x34) = 6;
      return;
    }
    iVar9 = 1;
  } while( true );
}

/* FUN_00134aa8 @ 0x134aa8 (8 bytes) */
int FUN_00134aa8(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}

/* FUN_00134ab0 @ 0x134ab0 (8 bytes) */
int FUN_00134ab0(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x14);
}

/* FUN_00134ab8 @ 0x134ab8 (100 bytes) */
int FUN_00134ab8(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  int iVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    *param_3 = 0;
    *param_2 = 6;
    return;
  }
  *param_2 = 0;
  *param_3 = *(int *)(param_1 + 8);
  while( true ) {
    iVar1 = *param_2 + 7;
    if (*(int *)(param_1 + 4) <= iVar1) break;
    *param_2 = iVar1;
    *param_3 = *(int *)(*param_3 + 0x1c);
  }
  *param_2 = (*(int *)(param_1 + 4) - *param_2) + -1;
  return;
}

/* FUN_00134b1c @ 0x134b1c (60 bytes) */
int FUN_00134b1c(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_3;
  if (param_2 < param_3) {
    iVar1 = param_2;
  }
  if (param_3 < param_2) {
    param_3 = param_2;
  }
  uVar2 = param_3 * (param_3 + -1);
  return iVar1 + ((int)uVar2 >> 1) + (uint)((int)uVar2 < 0 && (uVar2 & 1) != 0);
}

/* FUN_00134b58 @ 0x134b58 (76 bytes) */
int FUN_00134b58(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  uint uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  uVar1 = ((int (*)())FUN_00134b1c)(param_1,param_2,param_3);
  iVar2 = (uVar1 >> 3 & 0x1ffffffc) + iVar2;
  *(uint *)(iVar2 + 8) = 1 << (uVar1 & 0x1f) | *(uint *)(iVar2 + 8);
  return;
}

/* FUN_00134ba4 @ 0x134ba4 (76 bytes) */
int FUN_00134ba4(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  uint uVar1;
  
  uVar1 = ((int (*)())FUN_00134b1c)(param_1,param_2,param_3);
  return *(uint *)((uVar1 >> 3 & 0x1ffffffc) + *param_1 + 8) >> (uVar1 & 0x1f) & 1;
}

/* FUN_00134bf0 @ 0x134bf0 (40 bytes) */
int FUN_00134bf0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (param_3 != 0) {
    uVar1 = FUN_001952d8(param_2,*(undefined4 *)(param_1 + 0x20));
    return uVar1;
  }
  return *(undefined4 *)(param_2 * 4 + *(int *)(param_1 + 0x20));
}

/* FUN_00134c18 @ 0x134c18 (188 bytes) */
int FUN_00134c18(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = *(int *)(param_1 + 8);
  do {
    iVar2 = ((int (*)())FUN_00134bf0)(param_3,*(undefined4 *)(iVar3 * 4 + iVar4),1);
    if (iVar2 == param_2) {
      *(undefined4 *)(iVar3 * 4 + iVar4) = *(undefined4 *)(iVar4 + *(int *)(param_1 + 4) * 4);
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
    }
    else if ((*(int *)(param_1 + 4) == (*(int *)(param_1 + 4) / 7) * 7) &&
            (*(int *)(iVar4 + 0x1c) != 0)) {
      iVar4 = *(int *)(iVar4 + 0x1c);
    }
    bVar1 = iVar3 != 6;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  return;
}

/* FUN_00134cd4 @ 0x134cd4 (20 bytes) */
int FUN_00134cd4(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_00195330(param_2,param_3,*(undefined4 *)(param_1 + 0x20));
  return;
}

/* FUN_00134ce8 @ 0x134ce8 (200 bytes) */
int FUN_00134ce8(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((*(int *)(param_1 + 8) != 0) && (iVar2 = *(int *)(param_1 + 4), 0 < iVar2)) {
    iVar3 = 0;
    iVar4 = 0;
    iVar1 = 0;
    iVar5 = *(int *)(param_1 + 8);
    while( true ) {
      if (*(int *)(param_3 + param_2 * 4) ==
          *(int *)(param_3 +
                  *(int *)(*(int *)(iVar5 + (iVar4 + ((iVar4 / 7 + (iVar4 >> 0x1f)) - iVar1) * -7) *
                                            4) * 4 + *(int *)(param_4 + 0x20)) * 4)) {
        iVar3 = iVar3 + 1;
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + -1;
      if (iVar2 == 0) break;
      iVar1 = iVar4 >> 0x1f;
      if (((0 < iVar4) && (iVar4 == (iVar4 / 7) * 7)) && (*(int *)(iVar5 + 0x1c) != 0)) {
        iVar5 = *(int *)(iVar5 + 0x1c);
      }
    }
    return iVar3;
  }
  return 0;
}

/* FUN_00134db0 @ 0x134db0 (56 bytes) */
int FUN_00134db0(param_1)
  undefined4 *param_1;
{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  iVar1 = *piVar2;
  if (iVar1 == 0) {
    return;
  }
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  do {
    piVar2[2] = 0;
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

/* FUN_00134de8 @ 0x134de8 (264 bytes) */
int FUN_00134de8(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  
  if (param_2[0x26] != 0xc) {
    iVar1 = (**(code **)(*param_2 + 0x50))(param_2);
    if ((iVar1 != 0) || (iVar1 = FUN_001054ec(param_2,0), *(int *)(iVar1 + 0x10) == DAT_001afffc)) {
      return 0;
    }
    if ((((param_2[0x26] != 0x37) && (param_2[0x20] != 0)) &&
        (iVar1 = FUN_00126760(param_2[0x26]), iVar1 != 0)) &&
       ((((param_2[5] & 2U) == 0 && (iVar1 = (**(code **)(*param_2 + 0x50))(param_2), iVar1 == 0))
        && (((*(uint *)(param_1 + 0x30) & 0x400) != 0 || ((param_2[5] & 0x40U) == 0)))))) {
      return *(int *)(param_2[0x25] * 4 + *(int *)(param_1 + 0x458));
    }
  }
  return param_2[0x25];
}

/* FUN_00134ef4 @ 0x134ef4 (204 bytes) */
int FUN_00134ef4(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  int *param_3;
  int param_4;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  iVar2 = *param_2;
  *param_2 = iVar2 + 1;
  if (iVar2 + 1 == 7) {
    *param_2 = 0;
    iVar2 = *param_3;
    if (iVar2 == 0) {
      uVar3 = *(undefined4 *)(param_4 + 0x378);
      puVar1 = (undefined4 *)FUN_00193e18(uVar3,0x24);
      *puVar1 = uVar3;
      *(undefined4 **)(param_1 + 8) = puVar1 + 1;
      puVar1[8] = 0;
      *param_3 = *(int *)(param_1 + 8);
    }
    else {
      if (*(int *)(iVar2 + 0x1c) == 0) {
        uVar3 = *(undefined4 *)(param_4 + 0x378);
        puVar1 = (undefined4 *)FUN_00193e18(uVar3,0x24);
        *puVar1 = uVar3;
        *(undefined4 **)(iVar2 + 0x1c) = puVar1 + 1;
        *(undefined4 *)(*(int *)(*param_3 + 0x1c) + 0x1c) = 0;
        iVar2 = *param_3;
      }
      *param_3 = *(int *)(iVar2 + 0x1c);
    }
  }
  return;
}

/* FUN_00134fc0 @ 0x134fc0 (80 bytes) */
int FUN_00134fc0(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
  int *param_4;
  undefined4 param_5;
{
  ((int (*)())FUN_00134ef4)(param_1,param_3,param_4,param_5);
  *(undefined4 *)(*param_4 + *param_3 * 4) = param_2;
  return;
}

/* FUN_00135010 @ 0x135010 (128 bytes) */
int FUN_00135010(param_1)
  int param_1;
{
  int iVar1;
  
  while (iVar1 = *(int *)(param_1 + 8), iVar1 != 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar1 + 0x1c);
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
    return;
  }
  return;
}

/* FUN_00135090 @ 0x135090 (128 bytes) */
int FUN_00135090(param_1)
  int param_1;
{
  int iVar1;
  
  while (iVar1 = *(int *)(param_1 + 8), iVar1 != 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar1 + 0x1c);
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
    return;
  }
  return;
}

/* FUN_00135110 @ 0x135110 (148 bytes) */
int FUN_00135110(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  *(int *)(param_2 * 4 + *(int *)(param_4 + 0x20)) = param_2;
  uVar2 = *(undefined4 *)(param_5 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[1] = 2;
  puVar1[2] = 0;
  puVar1[4] = uVar2;
  uVar2 = FUN_00193e18(uVar2,8);
  puVar1[3] = uVar2;
  param_1[4] = (int)(puVar1 + 1);
  return;
}

/* FUN_001351c4 @ 0x1351c4 (148 bytes) */
int FUN_001351c4(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  *(int *)(param_2 * 4 + *(int *)(param_4 + 0x20)) = param_2;
  uVar2 = *(undefined4 *)(param_5 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[1] = 2;
  puVar1[2] = 0;
  puVar1[4] = uVar2;
  uVar2 = FUN_00193e18(uVar2,8);
  puVar1[3] = uVar2;
  param_1[4] = (int)(puVar1 + 1);
  return;
}

/* FUN_00135278 @ 0x135278 (188 bytes) */
int FUN_00135278(param_1)
  int param_1;
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  
  if (0 < *(int *)(param_1 + 0xc)) {
    uVar3 = 0;
    do {
      puVar4 = *(uint **)(param_1 + 4);
      if (uVar3 < *puVar4) {
        uVar1 = puVar4[1];
        if (uVar1 <= uVar3) {
          _memset((void *)(uVar1 * 4 + puVar4[2]),0,(uVar3 - uVar1) * 4 + 4);
          puVar4[1] = uVar3 + 1;
        }
        piVar2 = (int *)(uVar3 * 4 + puVar4[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar4,uVar3);
      }
      uVar3 = uVar3 + 1;
      *(undefined4 *)(*piVar2 + 4) = 0;
    } while ((int)uVar3 < *(int *)(param_1 + 0xc));
  }
  return;
}

/* FUN_00135334 @ 0x135334 (552 bytes) */
int FUN_00135334(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint *puVar4;
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [28];
  
  if ((param_2 != param_3) && (iVar1 = ((int (*)())FUN_00134ba4)(param_1,param_2,param_3), iVar1 == 0)) {
    ((int (*)())FUN_00134b58)(param_1,param_2,param_3);
    puVar4 = *(uint **)(param_1 + 4);
    if (param_2 < *puVar4) {
      uVar2 = puVar4[1];
      if (uVar2 <= param_2) {
        _memset((void *)(uVar2 * 4 + puVar4[2]),0,(param_2 - uVar2) * 4 + 4);
        puVar4[1] = param_2 + 1;
      }
      puVar3 = (undefined4 *)(param_2 * 4 + puVar4[2]);
    }
    else {
      puVar3 = (undefined4 *)FUN_0019423c(puVar4,param_2);
    }
    ((int (*)())FUN_00134ab8)(*puVar3,auStack_38,auStack_34);
    puVar4 = *(uint **)(param_1 + 4);
    if (param_2 < *puVar4) {
      uVar2 = puVar4[1];
      if (uVar2 <= param_2) {
        _memset((void *)(uVar2 * 4 + puVar4[2]),0,(param_2 - uVar2) * 4 + 4);
        puVar4[1] = param_2 + 1;
      }
      puVar3 = (undefined4 *)(param_2 * 4 + puVar4[2]);
    }
    else {
      puVar3 = (undefined4 *)FUN_0019423c(puVar4,param_2);
    }
    ((int (*)())FUN_00134fc0)(*puVar3,param_3,auStack_38,auStack_34,*(undefined4 *)(param_1 + 0x2c));
    puVar4 = *(uint **)(param_1 + 4);
    if (param_3 < *puVar4) {
      uVar2 = puVar4[1];
      if (uVar2 <= param_3) {
        _memset((void *)(uVar2 * 4 + puVar4[2]),0,(param_3 - uVar2) * 4 + 4);
        puVar4[1] = param_3 + 1;
      }
      puVar3 = (undefined4 *)(param_3 * 4 + puVar4[2]);
    }
    else {
      puVar3 = (undefined4 *)FUN_0019423c(puVar4,param_3);
    }
    ((int (*)())FUN_00134ab8)(*puVar3,auStack_38,auStack_34);
    puVar4 = *(uint **)(param_1 + 4);
    if (param_3 < *puVar4) {
      uVar2 = puVar4[1];
      if (uVar2 <= param_3) {
        _memset((void *)(uVar2 * 4 + puVar4[2]),0,(param_3 - uVar2) * 4 + 4);
        puVar4[1] = param_3 + 1;
      }
      puVar3 = (undefined4 *)(param_3 * 4 + puVar4[2]);
    }
    else {
      puVar3 = (undefined4 *)FUN_0019423c(puVar4,param_3);
    }
    ((int (*)())FUN_00134fc0)(*puVar3,param_2,auStack_38,auStack_34,*(undefined4 *)(param_1 + 0x2c));
  }
  return;
}

/* FUN_0013555c @ 0x13555c (296 bytes) */
int FUN_0013555c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  
  puVar11 = *(uint **)(param_1 + 4);
  if (param_3 < *puVar11) {
    uVar2 = puVar11[1];
    if (uVar2 <= param_3) {
      _memset((void *)(uVar2 * 4 + puVar11[2]),0,(param_3 - uVar2) * 4 + 4);
      puVar11[1] = param_3 + 1;
    }
    piVar3 = (int *)(param_3 * 4 + puVar11[2]);
  }
  else {
    piVar3 = (int *)FUN_0019423c(puVar11,param_3);
  }
  iVar7 = *piVar3;
  uVar4 = 0;
  iVar9 = *(int *)(iVar7 + 8);
  if (0 < *(int *)(iVar7 + 4)) {
    iVar10 = -1;
    iVar8 = 0;
    uVar4 = 0;
    do {
      bVar1 = iVar10 == 6;
      iVar10 = iVar10 + 1;
      if (bVar1) {
        iVar9 = *(int *)(iVar9 + 0x1c);
        iVar10 = 0;
      }
      iVar5 = ((int (*)())FUN_00134bf0)(param_1,*(undefined4 *)(iVar9 + iVar10 * 4),1);
      if ((iVar5 != param_2) && (iVar6 = ((int (*)())FUN_00134ba4)(param_1,param_2,iVar5), iVar6 == 0)) {
        uVar4 = 1;
        ((int (*)())FUN_00135334)(param_1,param_2,iVar5);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(iVar7 + 4));
  }
  return uVar4;
}

/* FUN_00135684 @ 0x135684 (336 bytes) */
int FUN_00135684(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint *puVar6;
  
  puVar5 = *(uint **)(param_1 + 4);
  if (param_2 < *puVar5) {
    uVar1 = puVar5[1];
    puVar6 = puVar5;
    if (uVar1 <= param_2) {
      _memset((void *)(uVar1 * 4 + puVar5[2]),0,(param_2 - uVar1) * 4 + 4);
      puVar5[1] = param_2 + 1;
      puVar6 = *(uint **)(param_1 + 4);
    }
    piVar2 = (int *)(param_2 * 4 + puVar5[2]);
  }
  else {
    piVar2 = (int *)FUN_0019423c(puVar5,param_2);
    puVar6 = *(uint **)(param_1 + 4);
  }
  puVar5 = *(uint **)(*piVar2 + 0x10);
  if (param_3 < *puVar6) {
    uVar1 = puVar6[1];
    if (uVar1 <= param_3) {
      _memset((void *)(uVar1 * 4 + puVar6[2]),0,(param_3 - uVar1) * 4 + 4);
      puVar6[1] = param_3 + 1;
    }
    puVar4 = (undefined4 *)(param_3 * 4 + puVar6[2]);
  }
  else {
    puVar4 = (undefined4 *)FUN_0019423c(puVar6,param_3);
  }
  uVar1 = puVar5[1];
  if (uVar1 < *puVar5) {
    _memset((void *)(uVar1 * 4 + puVar5[2]),0,4);
    puVar3 = (undefined4 *)(uVar1 * 4 + puVar5[2]);
    puVar5[1] = uVar1 + 1;
  }
  else {
    puVar3 = (undefined4 *)FUN_0019423c(puVar5,uVar1);
  }
  *puVar3 = *puVar4;
  return;
}

/* FUN_001357d4 @ 0x1357d4 (300 bytes) */
int FUN_001357d4(param_1)
  int param_1;
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x14));
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x18));
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x10));
  if (0 < *(int *)(param_1 + 0xc)) {
    uVar3 = 0;
    do {
      puVar4 = *(uint **)(param_1 + 4);
      if (uVar3 < *puVar4) {
        uVar1 = puVar4[1];
        if (uVar1 <= uVar3) {
          _memset((void *)(uVar1 * 4 + puVar4[2]),0,(uVar3 - uVar1) * 4 + 4);
          puVar4[1] = uVar3 + 1;
        }
        piVar2 = (int *)(uVar3 * 4 + puVar4[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar4,uVar3);
      }
      uVar3 = uVar3 + 1;
      iVar5 = *piVar2;
      if (iVar5 != 0) {
        ((int (*)())FUN_00135090)(iVar5);
        FUN_00193cc0(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
      }
    } while ((int)uVar3 < *(int *)(param_1 + 0xc));
  }
  iVar5 = *(int *)(param_1 + 4);
  if (iVar5 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
  }
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x20));
  return;
}

/* FUN_00135900 @ 0x135900 (300 bytes) */
int FUN_00135900(param_1)
  int param_1;
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x14));
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x18));
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x10));
  if (0 < *(int *)(param_1 + 0xc)) {
    uVar3 = 0;
    do {
      puVar4 = *(uint **)(param_1 + 4);
      if (uVar3 < *puVar4) {
        uVar1 = puVar4[1];
        if (uVar1 <= uVar3) {
          _memset((void *)(uVar1 * 4 + puVar4[2]),0,(uVar3 - uVar1) * 4 + 4);
          puVar4[1] = uVar3 + 1;
        }
        piVar2 = (int *)(uVar3 * 4 + puVar4[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar4,uVar3);
      }
      uVar3 = uVar3 + 1;
      iVar5 = *piVar2;
      if (iVar5 != 0) {
        ((int (*)())FUN_00135090)(iVar5);
        FUN_00193cc0(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
      }
    } while ((int)uVar3 < *(int *)(param_1 + 0xc));
  }
  iVar5 = *(int *)(param_1 + 4);
  if (iVar5 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
  }
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x20));
  return;
}

/* FUN_00135a2c @ 0x135a2c (500 bytes) */
int FUN_00135a2c(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  undefined1 auStack_48 [4];
  undefined1 auStack_44 [28];
  
  puVar11 = *(uint **)(param_3 + 4);
  if (param_2 < *puVar11) {
    uVar2 = puVar11[1];
    if (uVar2 <= param_2) {
      _memset((void *)(uVar2 * 4 + puVar11[2]),0,(param_2 - uVar2) * 4 + 4);
      puVar11[1] = param_2 + 1;
    }
    piVar3 = (int *)(param_2 * 4 + puVar11[2]);
  }
  else {
    piVar3 = (int *)FUN_0019423c(puVar11,param_2);
  }
  iVar6 = *piVar3;
  iVar7 = param_1[2];
  if (param_1[2] == 0) {
    param_1[2] = *(int *)(iVar6 + 8);
  }
  else {
    do {
      iVar9 = iVar7;
      iVar7 = *(int *)(iVar9 + 0x1c);
    } while (iVar7 != 0);
    *(undefined4 *)(iVar9 + 0x1c) = *(undefined4 *)(iVar6 + 8);
  }
  ((int (*)())FUN_00134ab8)(param_1,auStack_48,auStack_44);
  puVar11 = *(uint **)(param_3 + 4);
  if (param_2 < *puVar11) {
    uVar2 = puVar11[1];
    if (uVar2 <= param_2) {
      _memset((void *)(uVar2 * 4 + puVar11[2]),0,(param_2 - uVar2) * 4 + 4);
      puVar11[1] = param_2 + 1;
    }
    piVar3 = (int *)(param_2 * 4 + puVar11[2]);
  }
  else {
    piVar3 = (int *)FUN_0019423c(puVar11,param_2);
  }
  iVar7 = *piVar3;
  iVar9 = *(int *)(iVar7 + 8);
  if (0 < *(int *)(iVar7 + 4)) {
    iVar10 = -1;
    iVar8 = 0;
    do {
      bVar1 = iVar10 == 6;
      iVar10 = iVar10 + 1;
      if (bVar1) {
        iVar9 = *(int *)(iVar9 + 0x1c);
        iVar10 = 0;
      }
      uVar4 = ((int (*)())FUN_00134bf0)(param_3,*(undefined4 *)(iVar9 + iVar10 * 4),1);
      iVar5 = ((int (*)())FUN_00134ba4)(param_3,*(undefined4 *)(*param_1 * 4 + *(int *)(param_3 + 0x20)),uVar4);
      if (iVar5 == 0) {
        ((int (*)())FUN_00134fc0)(param_1,uVar4,auStack_48,auStack_44,*(undefined4 *)(param_3 + 0x2c));
        ((int (*)())FUN_00134b58)(param_3,*(undefined4 *)(*param_1 * 4 + *(int *)(param_3 + 0x20)),uVar4);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(iVar7 + 4));
  }
  *(undefined4 *)(iVar6 + 8) = 0;
  *(undefined4 *)(iVar6 + 4) = 0;
  return;
}

/* FUN_00135c20 @ 0x135c20 (260 bytes) */
int FUN_00135c20(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint *puVar6;
  
  uVar1 = 1;
  if (param_2 != param_3) {
    iVar2 = ((int (*)())FUN_00134ba4)(param_1,param_3,param_2);
    uVar1 = 0;
    if (iVar2 == 0) {
      uVar5 = param_2;
      if ((int)param_3 < (int)param_2) {
        uVar5 = param_3;
      }
      if ((int)param_2 < (int)param_3) {
        param_2 = param_3;
      }
      puVar6 = *(uint **)(param_1 + 4);
      if (uVar5 < *puVar6) {
        uVar3 = puVar6[1];
        if (uVar3 <= uVar5) {
          _memset((void *)(uVar3 * 4 + puVar6[2]),0,(uVar5 - uVar3) * 4 + 4);
          puVar6[1] = uVar5 + 1;
        }
        puVar4 = (undefined4 *)(uVar5 * 4 + puVar6[2]);
      }
      else {
        puVar4 = (undefined4 *)FUN_0019423c(puVar6,uVar5);
      }
      ((int (*)())FUN_00135a2c)(*puVar4,param_2,param_1);
      ((int (*)())FUN_00134cd4)(param_1,uVar5,param_2);
      uVar1 = 1;
    }
  }
  return uVar1;
}

/* FUN_00135d24 @ 0x135d24 (652 bytes) */
int FUN_00135d24(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint *param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  
  puVar10 = *(uint **)(param_1 + 4);
  if (param_2 < *puVar10) {
    uVar3 = puVar10[1];
    if (uVar3 <= param_2) {
      _memset((void *)(uVar3 * 4 + puVar10[2]),0,(param_2 - uVar3) * 4 + 4);
      puVar10[1] = param_2 + 1;
    }
    piVar4 = (int *)(param_2 * 4 + puVar10[2]);
  }
  else {
    piVar4 = (int *)FUN_0019423c(puVar10,param_2);
  }
  iVar7 = *piVar4;
  iVar8 = *(int *)(iVar7 + 8);
  if (0 < *(int *)(iVar7 + 4)) {
    iVar9 = -1;
    iVar6 = 0;
    do {
      bVar1 = iVar9 == 6;
      iVar9 = iVar9 + 1;
      if (bVar1) {
        iVar8 = *(int *)(iVar8 + 0x1c);
        iVar9 = 0;
      }
      puVar10 = *(uint **)(param_1 + 4);
      uVar3 = *(uint *)(iVar8 + iVar9 * 4);
      if (uVar3 < *puVar10) {
        uVar5 = puVar10[1];
        if (uVar5 <= uVar3) {
          _memset((void *)(uVar5 * 4 + puVar10[2]),0,(uVar3 - uVar5) * 4 + 4);
          puVar10[1] = uVar3 + 1;
        }
        piVar4 = (int *)(uVar3 * 4 + puVar10[2]);
      }
      else {
        piVar4 = (int *)FUN_0019423c(puVar10,uVar3);
      }
      if ((0 < *(int *)(*piVar4 + 0xc)) &&
         (iVar2 = uVar3 * 4, *(int *)(iVar2 + *(int *)(*(int *)(param_1 + 0x28) + 0x45c)) == param_5
         )) {
        puVar10 = *(uint **)(param_1 + 4);
        if (uVar3 < *puVar10) {
          uVar5 = puVar10[1];
          if (uVar5 <= uVar3) {
            _memset((void *)(uVar5 * 4 + puVar10[2]),0,(uVar3 - uVar5) * 4 + 4);
            puVar10[1] = uVar3 + 1;
          }
          piVar4 = (int *)(iVar2 + puVar10[2]);
        }
        else {
          piVar4 = (int *)FUN_0019423c(puVar10,uVar3);
        }
        *(int *)(*piVar4 + 0xc) = *(int *)(*piVar4 + 0xc) + -1;
        puVar10 = *(uint **)(param_1 + 4);
        if (uVar3 < *puVar10) {
          uVar5 = puVar10[1];
          if (uVar5 <= uVar3) {
            _memset((void *)(uVar5 * 4 + puVar10[2]),0,(uVar3 - uVar5) * 4 + 4);
            puVar10[1] = uVar3 + 1;
          }
          piVar4 = (int *)(iVar2 + puVar10[2]);
        }
        else {
          piVar4 = (int *)FUN_0019423c(puVar10,uVar3);
        }
        if (*(int *)(*piVar4 + 0xc) == param_4 + -1) {
          uVar5 = param_3[1];
          if (uVar5 < *param_3) {
            _memset((void *)(uVar5 * 4 + param_3[2]),0,4);
            puVar10 = (uint *)(uVar5 * 4 + param_3[2]);
            param_3[1] = uVar5 + 1;
          }
          else {
            puVar10 = (uint *)FUN_0019423c(param_3,uVar5);
          }
          *puVar10 = uVar3;
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(iVar7 + 4));
  }
  return;
}

/* FUN_00135fb0 @ 0x135fb0 (516 bytes) */
int FUN_00135fb0(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  undefined4 *puVar13;
  int *piVar14;
  int *piVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  undefined4 *puVar22;
  int *piVar23;
  uint uVar24;
  int *piVar25;
  int iVar26;
  uint uVar27;
  undefined4 uVar28;
  uint *puVar29;
  uint *puVar30;
  int iVar31;
  int local_5c;
  
  piVar6 = *(int **)(param_1 + 0x24);
  iVar3 = *piVar6;
  if (iVar3 != 0) {
    if (iVar3 == 0) {
      iVar3 = 1;
    }
    do {
      piVar6[2] = 0;
      piVar6 = piVar6 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  iVar21 = *(int *)(*(int *)(*(int *)(param_1 + 0x2c) + 0x30c) + 0x14);
  iVar3 = iVar21 << 2;
  iVar7 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar3);
  iVar8 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar3);
  iVar9 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar3);
  piVar6 = *(int **)(*(int *)(param_1 + 0x2c) + 0x30c);
  (**(code **)(*piVar6 + 0x130))(piVar6,iVar9);
  iVar10 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar3);
  piVar6 = (int *)FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar3);
  iVar11 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar3);
  piVar12 = (int *)FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar3);
  if (iVar21 >= 1) {
    iVar3 = 0;
    iVar26 = 0;
    do {
      iVar4 = *(int *)(iVar26 + *(int *)(param_1 + 0x14));
      if (iVar4 < 1) {
        iVar4 = 1;
      }
      *(int *)(iVar7 + iVar26) = iVar4;
      uVar28 = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378);
      puVar13 = (undefined4 *)FUN_00193e18(uVar28,0x14);
      *puVar13 = uVar28;
      puVar13[1] = 2;
      puVar13[4] = uVar28;
      puVar13[2] = 0;
      uVar28 = FUN_00193e18(uVar28,8);
      puVar13[3] = uVar28;
      *(undefined4 **)(iVar10 + iVar26) = puVar13 + 1;
      uVar28 = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378);
      puVar13 = (undefined4 *)FUN_00193e18(uVar28,0x14);
      *puVar13 = uVar28;
      puVar13[1] = 2;
      puVar13[2] = 0;
      puVar13[4] = uVar28;
      uVar28 = FUN_00193e18(uVar28,8);
      puVar13[3] = uVar28;
      *(undefined4 **)((int)piVar6 + iVar26) = puVar13 + 1;
      iVar4 = *(int *)(iVar26 + iVar9);
      uVar28 = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378);
      uVar27 = iVar4 + 0x1fU >> 5;
      puVar13 = (undefined4 *)FUN_00193e18(uVar28,uVar27 * 4 + 0xc);
      puVar22 = puVar13 + 1;
      *puVar13 = uVar28;
      puVar13[1] = uVar27;
      puVar13[2] = iVar4;
      if (uVar27 != 0) {
        puVar13 = puVar22;
        if (uVar27 == 0) {
          uVar27 = 1;
        }
        do {
          puVar13[2] = 0;
          puVar13 = puVar13 + 1;
          uVar27 = uVar27 - 1;
        } while (uVar27 != 0);
      }
      iVar3 = iVar3 + 1;
      *(undefined4 **)(iVar11 + iVar26) = puVar22;
      *(undefined4 *)((int)piVar12 + iVar26) = 0;
      *(undefined4 *)(iVar8 + iVar26) = 0;
      iVar26 = iVar26 + 4;
    } while (iVar21 != iVar3);
  }
  uVar27 = *(uint *)(param_1 + 8);
  if (0 < (int)uVar27) {
    iVar3 = 0;
    do {
      iVar26 = iVar3 * 4;
      iVar3 = iVar3 + 1;
      iVar4 = *(int *)(*(int *)(param_1 + 0x28) + 0x458);
      *(int *)(iVar26 + iVar4) =
           *(int *)(iVar26 + iVar4) -
           *(int *)(*(int *)(iVar26 + *(int *)(*(int *)(param_1 + 0x28) + 0x45c)) * 4 +
                   *(int *)(param_1 + 0x10));
      uVar27 = *(uint *)(param_1 + 8);
    } while (iVar3 < (int)uVar27);
  }
  iVar3 = *(int *)(param_1 + 0xc);
  if ((int)uVar27 < iVar3) {
    uVar24 = uVar27 + 1;
    iVar4 = *(int *)(param_1 + 0x28);
    iVar26 = uVar27 << 2;
    uVar5 = uVar24;
    do {
      uVar17 = uVar5;
      if (uVar27 == *(uint *)(iVar26 + *(int *)(param_1 + 0x20))) {
        iVar3 = *(int *)(iVar26 + *(int *)(iVar4 + 0x45c));
        piVar12[iVar3] = piVar12[iVar3] + 1;
        puVar29 = *(uint **)(param_1 + 4);
        if (uVar27 < *puVar29) {
          uVar5 = puVar29[1];
          puVar30 = puVar29;
          if (uVar5 <= uVar27) {
            _memset((void *)(uVar5 * 4 + puVar29[2]),0,(uVar27 - uVar5) * 4 + 4);
            puVar29[1] = uVar24;
            puVar30 = *(uint **)(param_1 + 4);
          }
          piVar14 = (int *)(iVar26 + puVar29[2]);
        }
        else {
          piVar14 = (int *)FUN_0019423c(puVar29,uVar27);
          puVar30 = *(uint **)(param_1 + 4);
        }
        iVar3 = *piVar14;
        if (uVar27 < *puVar30) {
          uVar5 = puVar30[1];
          if (uVar5 <= uVar27) {
            _memset((void *)(uVar5 * 4 + puVar30[2]),0,(uVar27 - uVar5) * 4 + 4);
            puVar30[1] = uVar24;
          }
          puVar13 = (undefined4 *)(iVar26 + puVar30[2]);
        }
        else {
          puVar13 = (undefined4 *)FUN_0019423c(puVar30,uVar27);
        }
        uVar28 = ((int (*)())FUN_00134ce8)(*puVar13,uVar27,*(undefined4 *)(*(int *)(param_1 + 0x28) + 0x45c),
                              param_1);
        *(undefined4 *)(iVar3 + 0xc) = uVar28;
        puVar29 = *(uint **)(param_1 + 4);
        if (uVar27 < *puVar29) {
          uVar5 = puVar29[1];
          if (uVar5 <= uVar27) {
            _memset((void *)(uVar5 * 4 + puVar29[2]),0,(uVar27 - uVar5) * 4 + 4);
            puVar29[1] = uVar24;
          }
          piVar14 = (int *)(iVar26 + puVar29[2]);
        }
        else {
          piVar14 = (int *)FUN_0019423c(puVar29,uVar27);
        }
        if (*(int *)(*piVar14 + 0xc) == 0) {
          puVar29 = (uint *)piVar6[*(int *)(iVar26 + *(int *)(*(int *)(param_1 + 0x28) + 0x45c))];
          uVar5 = puVar29[1];
          if (uVar5 < *puVar29) {
code_r0x001364b4:
            _memset((void *)(uVar5 * 4 + puVar29[2]),0,4);
            puVar30 = (uint *)(uVar5 * 4 + puVar29[2]);
            puVar29[1] = uVar5 + 1;
          }
          else {
code_r0x001364e0:
            puVar30 = (uint *)FUN_0019423c(puVar29,uVar5);
          }
          *puVar30 = uVar27;
          iVar4 = *(int *)(param_1 + 0x28);
          iVar3 = *(int *)(param_1 + 0xc);
        }
        else {
          puVar29 = *(uint **)(param_1 + 4);
          if (uVar27 < *puVar29) {
            uVar5 = puVar29[1];
            if (uVar5 <= uVar27) {
              _memset((void *)(uVar5 * 4 + puVar29[2]),0,(uVar27 - uVar5) * 4 + 4);
              puVar29[1] = uVar24;
            }
            piVar14 = (int *)(iVar26 + puVar29[2]);
          }
          else {
            piVar14 = (int *)FUN_0019423c(puVar29,uVar27);
          }
          iVar4 = *(int *)(param_1 + 0x28);
          iVar3 = *(int *)(iVar26 + *(int *)(iVar4 + 0x45c)) * 4;
          if (*(int *)(*piVar14 + 0xc) < *(int *)(iVar7 + iVar3)) {
            puVar29 = *(uint **)(iVar10 + iVar3);
            uVar5 = puVar29[1];
            if (uVar5 < *puVar29) goto code_r0x001364b4;
            goto code_r0x001364e0;
          }
          iVar3 = *(int *)(param_1 + 0xc);
        }
      }
      uVar24 = uVar24 + 1;
      iVar26 = iVar26 + 4;
      if (iVar3 <= (int)uVar17) goto code_r0x0013651c;
      uVar5 = uVar17 + 1;
      uVar27 = uVar17;
    } while( true );
  }
  iVar4 = *(int *)(param_1 + 0x28);
code_r0x0013651c:
  *(undefined4 *)(iVar4 + 0x25c) = 0;
  if (iVar21 < 1) {
    local_5c = 0;
  }
  else {
    iVar3 = 0;
    iVar26 = 0;
    local_5c = 0;
    piVar14 = piVar12;
    piVar23 = piVar6;
code_r0x001367c0:
    while (*(int *)(*(int *)((int)piVar6 + iVar26) + 4) != *(int *)((int)piVar12 + iVar26)) {
      piVar25 = (int *)(iVar10 + iVar26);
      *(int *)(*(int *)(param_1 + 0x28) + 0x25c) = *(int *)(*(int *)(param_1 + 0x28) + 0x25c) + 1;
      iVar4 = *(int *)(iVar10 + iVar26);
      uVar27 = *(uint *)(iVar4 + 4);
      while (uVar27 != 0) {
        puVar29 = (uint *)0x0;
        if (uVar27 - 1 < uVar27) {
          puVar29 = (uint *)((uVar27 - 1) * 4 + *(int *)(iVar4 + 8));
        }
        uVar5 = *puVar29;
        FUN_00194208(iVar4,uVar27 - 1);
        puVar29 = *(uint **)(param_1 + 4);
        if (uVar5 < *puVar29) {
          uVar27 = puVar29[1];
          if (uVar27 <= uVar5) {
            _memset((void *)(uVar27 * 4 + puVar29[2]),0,(uVar5 - uVar27) * 4 + 4);
            puVar29[1] = uVar5 + 1;
          }
          piVar15 = (int *)(uVar5 * 4 + puVar29[2]);
        }
        else {
          piVar15 = (int *)FUN_0019423c(puVar29,uVar5);
        }
        *(undefined4 *)(*piVar15 + 0xc) = 0;
        puVar29 = (uint *)*piVar23;
        uVar27 = puVar29[1];
        if (uVar27 < *puVar29) {
          _memset((void *)(uVar27 * 4 + puVar29[2]),0,4);
          puVar30 = (uint *)(uVar27 * 4 + puVar29[2]);
          puVar29[1] = uVar27 + 1;
        }
        else {
          puVar30 = (uint *)FUN_0019423c(puVar29,uVar27);
        }
        *puVar30 = uVar5;
        ((int (*)())FUN_00135d24)(param_1,uVar5,*piVar25,*(undefined4 *)(iVar7 + iVar26),iVar3);
        iVar4 = *piVar25;
        uVar27 = *(uint *)(iVar4 + 4);
      }
      if (*(int *)(*piVar23 + 4) != *piVar14) {
        *(int *)(iVar7 + iVar26) = *(int *)(iVar7 + iVar26) + 1;
        uVar27 = *(uint *)(param_1 + 8);
        iVar4 = *(int *)(param_1 + 0xc);
        if ((int)uVar27 < iVar4) {
          iVar16 = uVar27 << 2;
          do {
            if ((uVar27 == *(uint *)(iVar16 + *(int *)(param_1 + 0x20))) &&
               (iVar3 == *(int *)(iVar16 + *(int *)(*(int *)(param_1 + 0x28) + 0x45c)))) {
              puVar29 = *(uint **)(param_1 + 4);
              if (uVar27 < *puVar29) {
                uVar5 = puVar29[1];
                if (uVar5 <= uVar27) {
                  _memset((void *)(uVar5 * 4 + puVar29[2]),0,(uVar27 - uVar5) * 4 + 4);
                  puVar29[1] = uVar27 + 1;
                }
                piVar15 = (int *)(iVar16 + puVar29[2]);
              }
              else {
                piVar15 = (int *)FUN_0019423c(puVar29,uVar27);
              }
              if (*(int *)(*piVar15 + 0xc) == *(int *)(iVar7 + iVar26) + -1) {
                puVar29 = (uint *)*piVar25;
                uVar5 = puVar29[1];
                if (uVar5 < *puVar29) {
                  _memset((void *)(uVar5 * 4 + puVar29[2]),0,4);
                  puVar30 = (uint *)(uVar5 * 4 + puVar29[2]);
                  puVar29[1] = uVar5 + 1;
                }
                else {
                  puVar30 = (uint *)FUN_0019423c(puVar29,uVar5);
                }
                *puVar30 = uVar27;
                iVar4 = *(int *)(param_1 + 0xc);
              }
              else {
                iVar4 = *(int *)(param_1 + 0xc);
              }
            }
            uVar27 = uVar27 + 1;
            iVar16 = iVar16 + 4;
          } while ((int)uVar27 < iVar4);
        }
      }
    }
    iVar4 = *(int *)(iVar10 + iVar26);
    if (iVar4 != 0) {
      FUN_00193cc0(*(undefined4 *)(iVar4 + 0xc),*(undefined4 *)(iVar4 + 8));
      FUN_00193cc0(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
    }
    *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x260) = 0;
    while (*(int *)(*piVar23 + 4) != 0) {
      piVar14 = *(int **)(iVar26 + iVar11);
      piVar25 = (int *)(iVar26 + iVar11);
      iVar4 = *piVar14;
      if (iVar4 != 0) {
        if (iVar4 == 0) {
          iVar4 = 1;
        }
        do {
          piVar14[2] = 0;
          piVar14 = piVar14 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      iVar16 = *(int *)(param_1 + 0x28);
      iVar4 = iVar3 * 4;
      iVar31 = *(int *)(iVar4 + iVar16 + 0x43c);
      if (iVar31 < *(int *)(iVar4 + iVar16 + 0x448)) {
        do {
          iVar16 = FUN_001309dc(iVar16,iVar31);
          if (iVar16 == 0) {
            uVar27 = iVar31 - *(int *)(iVar4 + *(int *)(param_1 + 0x28) + 0x43c);
            iVar16 = (uVar27 >> 3 & 0x1ffffffc) + *piVar25;
            *(uint *)(iVar16 + 8) = 1 << (uVar27 & 0x1f) | *(uint *)(iVar16 + 8);
          }
          iVar16 = *(int *)(param_1 + 0x28);
          iVar31 = iVar31 + 1;
        } while (iVar31 < *(int *)(iVar4 + iVar16 + 0x448));
      }
      iVar16 = *piVar23;
      puVar29 = (uint *)0x0;
      uVar27 = *(uint *)(iVar16 + 4);
      if (uVar27 - 1 < uVar27) {
        puVar29 = (uint *)((uVar27 - 1) * 4 + *(int *)(iVar16 + 8));
      }
      uVar5 = *puVar29;
      FUN_00194208(iVar16,uVar27 - 1);
      puVar29 = *(uint **)(param_1 + 4);
      if (uVar5 < *puVar29) {
        uVar27 = puVar29[1];
        if (uVar27 <= uVar5) {
          _memset((void *)(uVar27 * 4 + puVar29[2]),0,(uVar5 - uVar27) * 4 + 4);
          puVar29[1] = uVar5 + 1;
        }
        piVar14 = (int *)(uVar5 * 4 + puVar29[2]);
      }
      else {
        piVar14 = (int *)FUN_0019423c(puVar29,uVar5);
      }
      iVar16 = *piVar14;
      iVar19 = *(int *)(iVar16 + 4);
      iVar31 = *(int *)(iVar16 + 8);
      if (0 < iVar19) {
        iVar20 = -1;
        iVar18 = 0;
        do {
          bVar1 = iVar20 == 6;
          iVar20 = iVar20 + 1;
          if (bVar1) {
            iVar31 = *(int *)(iVar31 + 0x1c);
            iVar20 = 0;
          }
          iVar2 = *(int *)(iVar31 + iVar20 * 4) * 4;
          if ((iVar3 == *(int *)(*(int *)(*(int *)(param_1 + 0x28) + 0x45c) + iVar2)) &&
             (uVar27 = *(uint *)(iVar2 + *(int *)(*(int *)(param_1 + 0x28) + 0x458)),
             -1 < (int)uVar27)) {
            iVar19 = (uVar27 >> 3 & 0x1ffffffc) + *piVar25;
            *(uint *)(iVar19 + 8) = 1 << (uVar27 & 0x1f) | *(uint *)(iVar19 + 8);
            iVar19 = *(int *)(iVar16 + 4);
          }
          iVar18 = iVar18 + 1;
        } while (iVar18 < iVar19);
      }
      puVar29 = *(uint **)(param_1 + 4);
      if (uVar5 < *puVar29) {
        uVar27 = puVar29[1];
        if (uVar27 <= uVar5) {
          _memset((void *)(uVar27 * 4 + puVar29[2]),0,(uVar5 - uVar27) * 4 + 4);
          puVar29[1] = uVar5 + 1;
        }
        piVar14 = (int *)(uVar5 * 4 + puVar29[2]);
      }
      else {
        piVar14 = (int *)FUN_0019423c(puVar29,uVar5);
      }
      uVar27 = *(uint *)(*(int *)(*piVar14 + 0x10) + 4);
      if (0 < (int)uVar27) {
        iVar16 = uVar5 * 4;
        uVar24 = 0;
        do {
          puVar29 = *(uint **)(param_1 + 4);
          if (uVar5 < *puVar29) {
            uVar17 = puVar29[1];
            if (uVar17 <= uVar5) {
              _memset((void *)(uVar17 * 4 + puVar29[2]),0,(uVar5 - uVar17) * 4 + 4);
              puVar29[1] = uVar5 + 1;
            }
            piVar14 = (int *)(iVar16 + puVar29[2]);
          }
          else {
            piVar14 = (int *)FUN_0019423c(puVar29,uVar5);
          }
          puVar29 = *(uint **)(*piVar14 + 0x10);
          if (uVar24 < *puVar29) {
            uVar17 = puVar29[1];
            if (uVar17 <= uVar24) {
              _memset((void *)(uVar17 * 4 + puVar29[2]),0,(uVar24 - uVar17) * 4 + 4);
              puVar29[1] = uVar24 + 1;
            }
            puVar13 = (undefined4 *)(uVar24 * 4 + puVar29[2]);
          }
          else {
            puVar13 = (undefined4 *)FUN_0019423c(puVar29,uVar24);
          }
          iVar31 = *(int *)(param_1 + 0x28);
          uVar17 = *(uint *)(*(int *)*puVar13 * 4 + *(int *)(iVar31 + 0x458));
          if ((-1 < (int)uVar17) &&
             ((*(uint *)((uVar17 >> 3 & 0x1ffffffc) + *piVar25 + 8) >> (uVar17 & 0x1f) & 1) == 0)) {
            *(int *)(iVar31 + 0x260) = *(int *)(iVar31 + 0x260) + 1;
            if (*(int *)(iVar8 + iVar26) < (int)(uVar17 + 1)) {
              *(uint *)(iVar8 + iVar26) = uVar17 + 1;
            }
            goto code_r0x00136cac;
          }
          uVar24 = uVar24 + 1;
        } while (uVar27 != uVar24);
      }
      iVar31 = *piVar25;
      iVar16 = *(int *)(iVar31 + 4);
      if (iVar16 == 0) {
code_r0x00136bb8:
        iVar4 = *(int *)(param_1 + 0x2c);
        if ((*(uint *)(*(int *)(iVar4 + 0x30c) + 8) & 0x8000) == 0) {
code_r0x00136be0:
          FUN_000e1534(iVar4,4);
        }
        else {
          iVar4 = FUN_000e07dc(iVar4,0x48);
          if (iVar4 == 0) {
            iVar4 = *(int *)(param_1 + 0x2c);
            goto code_r0x00136be0;
          }
          puVar29 = *(uint **)(param_1 + 4);
          local_5c = local_5c + 1;
          if (uVar5 < *puVar29) {
            uVar27 = puVar29[1];
            if (uVar27 <= uVar5) {
              _memset((void *)(uVar27 * 4 + puVar29[2]),0,(uVar5 - uVar27) * 4 + 4);
              puVar29[1] = uVar5 + 1;
            }
            piVar14 = (int *)(uVar5 * 4 + puVar29[2]);
          }
          else {
            piVar14 = (int *)FUN_0019423c(puVar29,uVar5);
          }
          if (*(int *)(*piVar14 + 0x18) == 0) {
            iVar4 = (uVar5 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 0x24);
            *(uint *)(iVar4 + 8) = 1 << (uVar5 & 0x1f) | *(uint *)(iVar4 + 8);
          }
        }
      }
      else {
        if ((*(uint *)(iVar31 + 8) & 1) == 0) {
          uVar17 = 0;
          iVar31 = 1;
        }
        else {
          uVar17 = 0;
          do {
            uVar27 = uVar17;
            uVar17 = uVar27 + 1;
            iVar16 = iVar16 + -1;
            if (iVar16 == 0) goto code_r0x00136bb8;
          } while ((*(uint *)((uVar17 >> 3 & 0x1ffffffc) + iVar31 + 8) >> (uVar17 & 0x1f) & 1) != 0)
          ;
          if (uVar17 == 0xffffffff) goto code_r0x00136bb8;
          iVar31 = uVar27 + 2;
        }
        iVar16 = uVar5 << 2;
        if (*(int *)(iVar8 + iVar26) < iVar31) {
          *(int *)(iVar8 + iVar26) = iVar31;
        }
code_r0x00136cac:
        *(uint *)(iVar16 + *(int *)(*(int *)(param_1 + 0x28) + 0x458)) = uVar17;
        FUN_00130444(*(int *)(param_1 + 0x28),
                     uVar17 + *(int *)(iVar4 + *(int *)(param_1 + 0x28) + 0x43c));
      }
    }
    iVar4 = *(int *)((int)piVar6 + iVar26);
    if (iVar4 != 0) {
      FUN_00193cc0(*(undefined4 *)(iVar4 + 0xc),*(undefined4 *)(iVar4 + 8));
      FUN_00193cc0(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
    }
    iVar4 = *(int *)(iVar11 + iVar26);
    if (iVar4 != 0) {
      FUN_00193cc0(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
    }
    iVar3 = iVar3 + 1;
    iVar26 = iVar26 + 4;
    if (iVar21 != iVar3) {
      piVar23 = (int *)((int)piVar6 + iVar26);
      piVar14 = (int *)((int)piVar12 + iVar26);
      goto code_r0x001367c0;
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x470) = *(undefined4 *)(param_1 + 0xc);
  iVar3 = *(int *)(param_1 + 8);
  iVar21 = *(int *)(param_1 + 0xc);
  if (iVar3 < iVar21) {
    iVar26 = iVar3 << 2;
    do {
      iVar3 = iVar3 + 1;
      iVar21 = *(int *)(*(int *)(param_1 + 0x28) + 0x458);
      *(undefined4 *)(iVar21 + iVar26) =
           *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) + iVar26) * 4 + iVar21);
      iVar26 = iVar26 + 4;
      iVar21 = *(int *)(param_1 + 0xc);
    } while (iVar3 < iVar21);
  }
  if (0 < iVar21) {
    iVar3 = 0;
    do {
      iVar21 = iVar3 * 4;
      iVar3 = iVar3 + 1;
      iVar26 = *(int *)(*(int *)(param_1 + 0x28) + 0x458);
      *(int *)(iVar21 + iVar26) =
           *(int *)(iVar21 + iVar26) +
           *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x28) + 0x45c) + iVar21) * 4 +
                   *(int *)(param_1 + 0x10));
    } while (iVar3 < *(int *)(param_1 + 0xc));
  }
  FUN_000ed7e4(*(undefined4 *)(param_1 + 0x28));
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),piVar12);
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar11);
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),piVar6);
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar10);
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar9);
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar8);
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar7);
  return 0 < local_5c;
}

/* FUN_00136ec4 @ 0x136ec4 (152 bytes) */
int FUN_00136ec4(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint *puVar5;
  undefined4 uVar6;
  uint uVar7;
  
  param_1[2] = param_2;
  param_1[10] = param_4;
  *param_1 = 0;
  param_1[3] = param_3;
  param_1[0xb] = param_5;
  if (param_3 != 0) {
    iVar1 = FUN_00193e18(*(undefined4 *)(param_5 + 0x378),param_3 << 2);
    param_1[8] = iVar1;
    uVar6 = *(undefined4 *)(param_1[0xb] + 0x378);
    puVar2 = (undefined4 *)FUN_00193e18(uVar6,0x14);
    *puVar2 = uVar6;
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2[4] = uVar6;
    uVar6 = FUN_00193e18(uVar6,8);
    puVar2[3] = uVar6;
    iVar4 = 0;
    iVar1 = param_1[3];
    param_1[1] = (int)(puVar2 + 1);
    if (0 < iVar1) {
      do {
        puVar5 = (uint *)param_1[1];
        uVar6 = *(undefined4 *)(param_1[0xb] + 0x378);
        puVar2 = (undefined4 *)FUN_00193e18(uVar6,0x28);
        *puVar2 = uVar6;
        ((int (*)())FUN_001351c4)(puVar2 + 1,iVar4,0,param_1,param_1[0xb]);
        uVar7 = puVar5[1];
        if (uVar7 < *puVar5) {
          _memset((void *)(uVar7 * 4 + puVar5[2]),0,4);
          puVar3 = (undefined4 *)(uVar7 * 4 + puVar5[2]);
          puVar5[1] = uVar7 + 1;
        }
        else {
          puVar3 = (undefined4 *)FUN_0019423c(puVar5,uVar7);
        }
        *puVar3 = puVar2 + 1;
        iVar4 = iVar4 + 1;
        iVar1 = param_1[3];
      } while (iVar4 < iVar1);
    }
    uVar6 = *(undefined4 *)(param_1[0xb] + 0x378);
    uVar7 = iVar1 * iVar1 - iVar1;
    iVar1 = ((int)uVar7 >> 1) + (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0);
    uVar7 = iVar1 + 0x1fU >> 5;
    puVar2 = (undefined4 *)FUN_00193e18(uVar6,uVar7 * 4 + 0xc);
    puVar3 = puVar2 + 1;
    *puVar2 = uVar6;
    puVar2[1] = uVar7;
    puVar2[2] = iVar1;
    if (uVar7 != 0) {
      puVar2 = puVar3;
      if (uVar7 == 0) {
        uVar7 = 1;
      }
      do {
        puVar2[2] = 0;
        puVar2 = puVar2 + 1;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
    *param_1 = (int)puVar3;
    iVar1 = *(int *)(*(int *)(param_1[0xb] + 0x30c) + 0x14) << 2;
    iVar4 = FUN_00193e18(*(undefined4 *)(param_1[0xb] + 0x378),iVar1);
    param_1[4] = iVar4;
    (**(code **)(**(int **)(param_1[0xb] + 0x30c) + 0x134))(*(int **)(param_1[0xb] + 0x30c),iVar4);
    iVar4 = FUN_00193e18(*(undefined4 *)(param_1[0xb] + 0x378),iVar1);
    param_1[6] = iVar4;
    iVar1 = FUN_00193e18(*(undefined4 *)(param_1[0xb] + 0x378),iVar1);
    iVar4 = param_1[0xb];
    param_1[5] = iVar1;
    if (0 < *(int *)(*(int *)(iVar4 + 0x30c) + 0x14)) {
      iVar1 = 0;
      do {
        iVar4 = iVar1 * 4;
        iVar1 = iVar1 + 1;
        *(undefined4 *)(param_1[6] + iVar4) = 0;
        *(undefined4 *)(param_1[5] + iVar4) = 0;
        iVar4 = param_1[0xb];
      } while (iVar1 < *(int *)(*(int *)(iVar4 + 0x30c) + 0x14));
    }
    uVar6 = *(undefined4 *)(iVar4 + 0x378);
    puVar3 = (undefined4 *)FUN_00193e18(uVar6,0x20c);
    puVar3[1] = 0x80;
    iVar1 = 0x80;
    *puVar3 = uVar6;
    puVar3[2] = 0x1000;
    puVar2 = puVar3 + 1;
    do {
      puVar2[2] = 0;
      puVar2 = puVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    param_1[9] = (int)(puVar3 + 1);
  }
  return;
}

/* FUN_0013719c @ 0x13719c (152 bytes) */
int FUN_0013719c(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint *puVar5;
  undefined4 uVar6;
  uint uVar7;
  
  param_1[2] = param_2;
  param_1[10] = param_4;
  *param_1 = 0;
  param_1[3] = param_3;
  param_1[0xb] = param_5;
  if (param_3 != 0) {
    iVar1 = FUN_00193e18(*(undefined4 *)(param_5 + 0x378),param_3 << 2);
    param_1[8] = iVar1;
    uVar6 = *(undefined4 *)(param_1[0xb] + 0x378);
    puVar2 = (undefined4 *)FUN_00193e18(uVar6,0x14);
    *puVar2 = uVar6;
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2[4] = uVar6;
    uVar6 = FUN_00193e18(uVar6,8);
    puVar2[3] = uVar6;
    iVar4 = 0;
    iVar1 = param_1[3];
    param_1[1] = (int)(puVar2 + 1);
    if (0 < iVar1) {
      do {
        puVar5 = (uint *)param_1[1];
        uVar6 = *(undefined4 *)(param_1[0xb] + 0x378);
        puVar2 = (undefined4 *)FUN_00193e18(uVar6,0x28);
        *puVar2 = uVar6;
        ((int (*)())FUN_001351c4)(puVar2 + 1,iVar4,0,param_1,param_1[0xb]);
        uVar7 = puVar5[1];
        if (uVar7 < *puVar5) {
          _memset((void *)(uVar7 * 4 + puVar5[2]),0,4);
          puVar3 = (undefined4 *)(uVar7 * 4 + puVar5[2]);
          puVar5[1] = uVar7 + 1;
        }
        else {
          puVar3 = (undefined4 *)FUN_0019423c(puVar5,uVar7);
        }
        *puVar3 = puVar2 + 1;
        iVar4 = iVar4 + 1;
        iVar1 = param_1[3];
      } while (iVar4 < iVar1);
    }
    uVar6 = *(undefined4 *)(param_1[0xb] + 0x378);
    uVar7 = iVar1 * iVar1 - iVar1;
    iVar1 = ((int)uVar7 >> 1) + (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0);
    uVar7 = iVar1 + 0x1fU >> 5;
    puVar2 = (undefined4 *)FUN_00193e18(uVar6,uVar7 * 4 + 0xc);
    puVar3 = puVar2 + 1;
    *puVar2 = uVar6;
    puVar2[1] = uVar7;
    puVar2[2] = iVar1;
    if (uVar7 != 0) {
      puVar2 = puVar3;
      if (uVar7 == 0) {
        uVar7 = 1;
      }
      do {
        puVar2[2] = 0;
        puVar2 = puVar2 + 1;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
    *param_1 = (int)puVar3;
    iVar1 = *(int *)(*(int *)(param_1[0xb] + 0x30c) + 0x14) << 2;
    iVar4 = FUN_00193e18(*(undefined4 *)(param_1[0xb] + 0x378),iVar1);
    param_1[4] = iVar4;
    (**(code **)(**(int **)(param_1[0xb] + 0x30c) + 0x134))(*(int **)(param_1[0xb] + 0x30c),iVar4);
    iVar4 = FUN_00193e18(*(undefined4 *)(param_1[0xb] + 0x378),iVar1);
    param_1[6] = iVar4;
    iVar1 = FUN_00193e18(*(undefined4 *)(param_1[0xb] + 0x378),iVar1);
    iVar4 = param_1[0xb];
    param_1[5] = iVar1;
    if (0 < *(int *)(*(int *)(iVar4 + 0x30c) + 0x14)) {
      iVar1 = 0;
      do {
        iVar4 = iVar1 * 4;
        iVar1 = iVar1 + 1;
        *(undefined4 *)(param_1[6] + iVar4) = 0;
        *(undefined4 *)(param_1[5] + iVar4) = 0;
        iVar4 = param_1[0xb];
      } while (iVar1 < *(int *)(*(int *)(iVar4 + 0x30c) + 0x14));
    }
    uVar6 = *(undefined4 *)(iVar4 + 0x378);
    puVar3 = (undefined4 *)FUN_00193e18(uVar6,0x20c);
    puVar3[1] = 0x80;
    iVar1 = 0x80;
    *puVar3 = uVar6;
    puVar3[2] = 0x1000;
    puVar2 = puVar3 + 1;
    do {
      puVar2[2] = 0;
      puVar2 = puVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    param_1[9] = (int)(puVar3 + 1);
  }
  return;
}

/* FUN_00137474 @ 0x137474 (428 bytes) */
int FUN_00137474(param_1)
  int *param_1;
{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint *puVar11;
  
  iVar8 = param_1[3];
  iVar4 = iVar8 + 1;
  iVar9 = *param_1;
  param_1[3] = iVar4;
  uVar10 = *(undefined4 *)(param_1[0xb] + 0x378);
  uVar1 = iVar4 * iVar4 - iVar4;
  iVar4 = ((int)uVar1 >> 1) + (uint)((int)uVar1 < 0 && (uVar1 & 1) != 0);
  uVar1 = iVar4 + 0x1fU >> 5;
  puVar2 = (undefined4 *)FUN_00193e18(uVar10,uVar1 * 4 + 0xc);
  puVar6 = puVar2 + 1;
  *puVar2 = uVar10;
  puVar2[1] = uVar1;
  puVar2[2] = iVar4;
  if (uVar1 != 0) {
    puVar2 = puVar6;
    if (uVar1 == 0) {
      uVar1 = 1;
    }
    do {
      puVar2[2] = 0;
      puVar2 = puVar2 + 1;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  iVar5 = param_1[3];
  *param_1 = (int)puVar6;
  if (0 < (iVar4 - iVar5) + 1) {
    uVar1 = 0;
    do {
      uVar7 = uVar1 >> 3 & 0x1ffffffc;
      if ((*(uint *)(uVar7 + iVar9 + 8) >> (uVar1 & 0x1f) & 1) != 0) {
        iVar5 = uVar7 + *param_1;
        *(uint *)(iVar5 + 8) = 1 << (uVar1 & 0x1f) | *(uint *)(iVar5 + 8);
        iVar5 = param_1[3];
      }
      uVar1 = uVar1 + 1;
    } while ((int)uVar1 < (iVar4 - iVar5) + 1);
  }
  if (iVar9 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar9 + -4),iVar9 + -4);
    iVar5 = param_1[3];
  }
  iVar9 = param_1[8];
  iVar4 = FUN_00193e18(*(undefined4 *)(param_1[0xb] + 0x378),iVar5 << 2);
  param_1[8] = iVar4;
  if (0 < iVar8) {
    iVar5 = 0;
    iVar4 = iVar8;
    do {
      *(undefined4 *)(iVar5 + param_1[8]) = *(undefined4 *)(iVar9 + iVar5);
      iVar5 = iVar5 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  FUN_00193cc0(*(undefined4 *)(param_1[0xb] + 0x378),iVar9);
  puVar11 = (uint *)param_1[1];
  uVar10 = *(undefined4 *)(param_1[0xb] + 0x378);
  puVar2 = (undefined4 *)FUN_00193e18(uVar10,0x28);
  *puVar2 = uVar10;
  ((int (*)())FUN_001351c4)(puVar2 + 1,iVar8,0,param_1,param_1[0xb]);
  uVar1 = puVar11[1];
  if (uVar1 < *puVar11) {
    _memset((void *)(uVar1 * 4 + puVar11[2]),0,4);
    piVar3 = (int *)(uVar1 * 4 + puVar11[2]);
    puVar11[1] = uVar1 + 1;
  }
  else {
    piVar3 = (int *)FUN_0019423c(puVar11,uVar1);
  }
  *piVar3 = (int)(puVar2 + 1);
  return;
}

/* FUN_00137694 @ 0x137694 (456 bytes) */
int FUN_00137694(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  
  iVar8 = param_1[3];
  iVar4 = iVar8 + param_2;
  iVar7 = *param_1;
  param_1[3] = iVar4;
  uVar9 = *(undefined4 *)(param_1[0xb] + 0x378);
  uVar11 = iVar4 * iVar4 - iVar4;
  iVar4 = ((int)uVar11 >> 1) + (uint)((int)uVar11 < 0 && (uVar11 & 1) != 0);
  uVar11 = iVar4 + 0x1fU >> 5;
  puVar2 = (undefined4 *)FUN_00193e18(uVar9,uVar11 * 4 + 0xc);
  puVar5 = puVar2 + 1;
  *puVar2 = uVar9;
  puVar2[1] = uVar11;
  puVar2[2] = iVar4;
  if (uVar11 != 0) {
    puVar2 = puVar5;
    if (uVar11 == 0) {
      uVar11 = 1;
    }
    do {
      puVar2[2] = 0;
      puVar2 = puVar2 + 1;
      uVar11 = uVar11 - 1;
    } while (uVar11 != 0);
  }
  *param_1 = (int)puVar5;
  if (0 < iVar8) {
    iVar4 = 0;
    while (iVar4 = iVar4 + 1, iVar8 != iVar4) {
      if (0 < iVar4) {
        iVar12 = 0;
        do {
          uVar11 = ((int (*)())FUN_00134b1c)(param_1,iVar12,iVar4);
          uVar6 = uVar11 >> 3 & 0x1ffffffc;
          if ((*(uint *)(uVar6 + iVar7 + 8) >> (uVar11 & 0x1f) & 1) != 0) {
            iVar1 = uVar6 + *param_1;
            *(uint *)(iVar1 + 8) = 1 << (uVar11 & 0x1f) | *(uint *)(iVar1 + 8);
          }
          iVar12 = iVar12 + 1;
        } while (iVar4 != iVar12);
      }
    }
  }
  iVar7 = param_1[8];
  iVar4 = FUN_00193e18(*(undefined4 *)(param_1[0xb] + 0x378),param_1[3] << 2);
  param_1[8] = iVar4;
  if (0 < iVar8) {
    iVar12 = 0;
    iVar4 = iVar8;
    do {
      *(undefined4 *)(iVar12 + param_1[8]) = *(undefined4 *)(iVar7 + iVar12);
      iVar12 = iVar12 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  FUN_00193cc0(*(undefined4 *)(param_1[0xb] + 0x378),iVar7);
  if (iVar8 < param_1[3]) {
    do {
      puVar10 = (uint *)param_1[1];
      uVar9 = *(undefined4 *)(param_1[0xb] + 0x378);
      puVar2 = (undefined4 *)FUN_00193e18(uVar9,0x28);
      *puVar2 = uVar9;
      ((int (*)())FUN_001351c4)(puVar2 + 1,iVar8,0,param_1,param_1[0xb]);
      uVar11 = puVar10[1];
      if (uVar11 < *puVar10) {
        _memset((void *)(uVar11 * 4 + puVar10[2]),0,4);
        piVar3 = (int *)(uVar11 * 4 + puVar10[2]);
        puVar10[1] = uVar11 + 1;
      }
      else {
        piVar3 = (int *)FUN_0019423c(puVar10,uVar11);
      }
      *piVar3 = (int)(puVar2 + 1);
      iVar8 = iVar8 + 1;
    } while (iVar8 < param_1[3]);
  }
  return;
}

/* FUN_001378e8 @ 0x1378e8 (1420 bytes) */
int FUN_001378e8(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint *puVar10;
  
  iVar8 = *(int *)(*(int *)(param_2 + 0x6c4) + 900);
  iVar7 = *(int *)(iVar8 + 8);
  do {
    if (iVar7 == 0) {
      return;
    }
    piVar1 = (int *)(*(int **)(iVar8 + 0xa0))[1];
    piVar9 = *(int **)(iVar8 + 0xa0);
    if (piVar1 != (int *)0x0) {
      do {
        piVar5 = piVar1;
        if (((piVar9 == *(int **)(iVar8 + 0x98)) || ((piVar5[5] & 4U) == 0)) &&
           (iVar7 = *(int *)(iVar8 + 0xb8), piVar9 != (int *)0x0)) {
          piVar1 = piVar9;
          do {
            uVar2 = piVar1[5];
            if ((uVar2 & 1) != 0) {
              iVar3 = (**(code **)(*piVar1 + 0x7c))(piVar1);
              if (iVar3 == 0) {
                if (((piVar1[0x20] != 0) && (iVar3 = FUN_00126760(piVar1[0x26]), iVar3 != 0)) &&
                   (((piVar1[5] & 2U) == 0 &&
                    (iVar3 = (**(code **)(*piVar1 + 0x50))(piVar1), iVar3 == 0)))) {
                  uVar2 = piVar1[0x25];
                  iVar3 = (**(code **)(*piVar1 + 0x40))(piVar1);
                  if ((iVar3 == 0) && (iVar3 = (**(code **)(*piVar1 + 0x28))(piVar1), iVar3 == 0)) {
                    piVar1[5] = piVar1[5] | 0x20000000;
                    piVar5 = piVar1;
                    for (iVar3 = 1; iVar6 = (**(code **)(*piVar1 + 0x14))(piVar1), iVar3 <= iVar6;
                        iVar3 = iVar3 + 1) {
                      if ((iVar3 < 1) || (iVar6 = FUN_00105594(piVar1,iVar3), iVar6 == 0)) {
                        iVar6 = piVar5[0x2c];
                      }
                      else {
                        iVar6 = FUN_00105594(piVar1,iVar3);
                        iVar6 = *(int *)(iVar6 + 0x98);
                      }
                      iVar6 = FUN_0012678c(iVar6);
                      if (iVar6 == 0) {
LAB_00137af8:
                        uVar4 = piVar1[5] & 0xdfffffff;
                        piVar1[5] = uVar4;
                        goto LAB_00137b2c;
                      }
                      FUN_001054ec(piVar1,iVar3);
                      piVar5 = piVar5 + 6;
                      iVar6 = FUN_00105dbc(piVar1,iVar3);
                      if (iVar6 != 0) goto LAB_00137af8;
                    }
                    uVar4 = piVar1[5];
                  }
                  else {
                    puVar10 = *(uint **)(param_1 + 4);
                    if (uVar2 < *puVar10) {
                      uVar4 = puVar10[1];
                      if (uVar4 <= uVar2) {
                        _memset((void *)(uVar4 * 4 + puVar10[2]),0,(uVar2 - uVar4) * 4 + 4);
                        puVar10[1] = uVar2 + 1;
                      }
                      piVar5 = (int *)(uVar2 * 4 + puVar10[2]);
                    }
                    else {
                      piVar5 = (int *)FUN_0019423c(puVar10,uVar2);
                    }
                    *(undefined4 *)(*piVar5 + 0x20) = 0;
                    uVar4 = piVar1[5];
                  }
LAB_00137b2c:
                  if ((uVar4 & 0x20000000) != 0) {
                    puVar10 = *(uint **)(param_1 + 4);
                    if (uVar2 < *puVar10) {
                      uVar4 = puVar10[1];
                      if (uVar4 <= uVar2) {
                        _memset((void *)(uVar4 * 4 + puVar10[2]),0,(uVar2 - uVar4) * 4 + 4);
                        puVar10[1] = uVar2 + 1;
                      }
                      piVar5 = (int *)(uVar2 * 4 + puVar10[2]);
                    }
                    else {
                      piVar5 = (int *)FUN_0019423c(puVar10,uVar2);
                    }
                    *(undefined4 *)(*piVar5 + 0x20) = 1;
                  }
                  puVar10 = *(uint **)(param_1 + 4);
                  if (uVar2 < *puVar10) {
                    uVar4 = puVar10[1];
                    if (uVar4 <= uVar2) {
                      _memset((void *)(uVar4 * 4 + puVar10[2]),0,(uVar2 - uVar4) * 4 + 4);
                      puVar10[1] = uVar2 + 1;
                    }
                    piVar5 = (int *)(uVar2 * 4 + puVar10[2]);
                  }
                  else {
                    piVar5 = (int *)FUN_0019423c(puVar10,uVar2);
                  }
                  if (*(int *)(*piVar5 + 0x18) == 0) {
                    iVar3 = 0;
                    if (((piVar1[5] & 0x20000000U) == 0) &&
                       (iVar3 = iVar7 * 100, (piVar1[5] & 0x40U) != 0)) {
                      iVar3 = 0x7fffffff;
                    }
                    puVar10 = *(uint **)(param_1 + 4);
                    if (uVar2 < *puVar10) {
                      uVar4 = puVar10[1];
                      if (uVar4 <= uVar2) {
                        _memset((void *)(uVar4 * 4 + puVar10[2]),0,(uVar2 - uVar4) * 4 + 4);
                        puVar10[1] = uVar2 + 1;
                      }
                      piVar5 = (int *)(uVar2 * 4 + puVar10[2]);
                    }
                    else {
                      piVar5 = (int *)FUN_0019423c(puVar10,uVar2);
                    }
                    *(int *)(*piVar5 + 0x1c) = iVar3 + *(int *)(*piVar5 + 0x1c);
                  }
                }
                for (iVar3 = 1; iVar6 = (**(code **)(*piVar1 + 0x14))(piVar1), iVar3 <= iVar6;
                    iVar3 = iVar3 + 1) {
                  piVar5 = (int *)FUN_00105594(piVar1,iVar3);
                  uVar2 = piVar5[0x25];
                  if ((((piVar5[0x20] != 0) && (iVar6 = FUN_00126760(piVar5[0x26]), iVar6 != 0)) &&
                      ((piVar5[5] & 2U) == 0)) &&
                     (iVar6 = (**(code **)(*piVar5 + 0x50))(piVar5), iVar6 == 0)) {
                    puVar10 = *(uint **)(param_1 + 4);
                    if (uVar2 < *puVar10) {
                      uVar4 = puVar10[1];
                      if (uVar4 <= uVar2) {
                        _memset((void *)(uVar4 * 4 + puVar10[2]),0,(uVar2 - uVar4) * 4 + 4);
                        puVar10[1] = uVar2 + 1;
                      }
                      piVar5 = (int *)(uVar2 * 4 + puVar10[2]);
                    }
                    else {
                      piVar5 = (int *)FUN_0019423c(puVar10,uVar2);
                    }
                    if (*(int *)(*piVar5 + 0x18) == 0) {
                      puVar10 = *(uint **)(param_1 + 4);
                      if (uVar2 < *puVar10) {
                        uVar4 = puVar10[1];
                        if (uVar4 <= uVar2) {
                          _memset((void *)(uVar4 * 4 + puVar10[2]),0,(uVar2 - uVar4) * 4 + 4);
                          puVar10[1] = uVar2 + 1;
                        }
                        piVar5 = (int *)(uVar2 * 4 + puVar10[2]);
                      }
                      else {
                        piVar5 = (int *)FUN_0019423c(puVar10,uVar2);
                      }
                      *(int *)(*piVar5 + 0x1c) = iVar7 + *(int *)(*piVar5 + 0x1c);
                    }
                  }
                }
              }
              uVar2 = piVar1[5];
            }
            piVar1 = (int *)piVar1[2];
          } while ((piVar1 != (int *)0x0) && ((uVar2 & 4) != 0));
          piVar5 = (int *)piVar9[1];
        }
        piVar1 = (int *)piVar5[1];
        piVar9 = piVar5;
      } while ((int *)piVar5[1] != (int *)0x0);
      iVar7 = *(int *)(iVar8 + 8);
    }
    iVar8 = iVar7;
    iVar7 = *(int *)(iVar7 + 8);
  } while( true );
}

/* FUN_00137e74 @ 0x137e74 (36 bytes) */
int FUN_00137e74(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = param_2 * 4 + param_3;
  return *(uint *)((uVar1 >> 3 & 0x1ffffffc) + param_1 + 8) >> (uVar1 & 0x1f) & 1;
}

/* FUN_00137e98 @ 0x137e98 (124 bytes) */
int FUN_00137e98(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  uint param_3;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = FUN_00105594(param_1,param_2);
  uVar1 = param_3;
  while( true ) {
    if (uVar1 == 0) {
      return 0;
    }
    if (((*(uint *)(param_3 + 0x14) & 1) != 0) && (param_3 == uVar2)) break;
    param_3 = *(uint *)(param_3 + 4);
    uVar1 = *(uint *)(param_3 + 0x14) & 4;
    if (param_3 == 0) {
      return 0;
    }
  }
  return 1;
}

/* FUN_00137f14 @ 0x137f14 (364 bytes) */
int FUN_00137f14(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar1 = param_2[0x21];
  if (0 < iVar1) {
    piVar3 = param_2 + iVar1 * 6 + 0x23;
    do {
      iVar6 = *piVar3;
      uVar4 = *(uint *)(iVar6 + 0x1c);
      if ((int)uVar4 < 0) {
        if (*(int *)(iVar6 + 4) == 0x2c) {
          *(undefined4 *)(param_1 + 0x3b4) = 1;
          *(uint *)(iVar6 + 0x24) = *(uint *)(iVar6 + 0x24) | 1;
        }
      }
      else {
        uVar5 = uVar4 >> 3 & 0x1ffffffc;
        if ((*(uint *)(uVar5 + param_3 + 8) >> (uVar4 & 0x1f) & 1) == 0) {
          iVar2 = uVar5 + *(int *)(param_1 + 0x3b0);
          *(uint *)(iVar2 + 8) = 1 << (uVar4 & 0x1f) | *(uint *)(iVar2 + 8);
          *(uint *)(iVar6 + 0x24) = *(uint *)(iVar6 + 0x24) | 1;
        }
      }
      piVar3 = piVar3 + -6;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  if (((0 < param_2[0x20]) && ((param_2[5] & 2U) == 0)) &&
     (uVar4 = *(uint *)(param_2[0x23] + 0x1c), -1 < (int)uVar4)) {
    iVar1 = (uVar4 >> 3 & 0x1ffffffc) + param_3;
    *(uint *)(iVar1 + 8) = 1 << (uVar4 & 0x1f) | *(uint *)(iVar1 + 8);
  }
  iVar1 = (**(code **)(*param_2 + 0x78))(param_2);
  if (iVar1 != 0) {
    iVar1 = param_2[0x29];
    uVar4 = *(uint *)(iVar1 + 0x1c);
    if (-1 < (int)uVar4) {
      iVar6 = (uVar4 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 0x3b0);
      *(uint *)(iVar6 + 8) = 1 << (uVar4 & 0x1f) | *(uint *)(iVar6 + 8);
      *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) | 1;
    }
  }
  return;
}

/* FUN_00138080 @ 0x138080 (176 bytes) */
int FUN_00138080(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 1;
  piVar1 = (int *)FUN_000ec5b8(param_1);
  while( true ) {
    piVar1 = piVar1 + 1;
    iVar2 = FUN_00194034(param_1 + 0x37c);
    if (iVar2 < iVar3) break;
    iVar4 = *piVar1;
    iVar2 = *(int *)(iVar4 + 0x108);
    if (iVar2 != 0) {
      FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
    }
    iVar2 = *(int *)(iVar4 + 0x100);
    *(undefined4 *)(iVar4 + 0x108) = 0;
    if (iVar2 != 0) {
      FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
    }
    iVar2 = *(int *)(iVar4 + 0x104);
    *(undefined4 *)(iVar4 + 0x100) = 0;
    if (iVar2 != 0) {
      FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
    }
    *(undefined4 *)(iVar4 + 0x104) = 0;
    iVar3 = iVar3 + 1;
  }
  return;
}

/* FUN_00138130 @ 0x138130 (272 bytes) */
int FUN_00138130(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  
  uVar6 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar3 = (undefined4 *)FUN_00193e18(uVar6,0x20c);
  piVar5 = puVar3 + 1;
  puVar3[1] = 0x80;
  iVar7 = 0x80;
  *puVar3 = uVar6;
  puVar3[2] = 0x1000;
  iVar4 = 0x80;
  piVar1 = piVar5;
  do {
    piVar1[2] = 0;
    piVar1 = piVar1 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = *(int *)(param_1 + 900);
  if (*(int *)(iVar7 + 8) != 0) {
    while( true ) {
      if (iVar4 != 0) {
        piVar1 = piVar5;
        if (iVar4 == 0) {
          iVar4 = 1;
        }
        do {
          piVar1[2] = 0;
          piVar1 = piVar1 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      iVar4 = *(int *)(iVar7 + 0x98);
      for (iVar2 = *(int *)(*(int *)(iVar7 + 0x98) + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
        if ((*(uint *)(iVar4 + 0x14) & 1) != 0) {
          ((int (*)())FUN_00137f14)(param_1,iVar4,piVar5);
          iVar2 = *(int *)(iVar4 + 8);
        }
        iVar4 = iVar2;
      }
      iVar7 = *(int *)(iVar7 + 8);
      if (*(int *)(iVar7 + 8) == 0) break;
      iVar4 = *piVar5;
    }
  }
  return;
}

/* FUN_00138240 @ 0x138240 (120 bytes) */
int FUN_00138240(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  do {
    iVar1 = FUN_001054ec(param_1,0);
    if (*(char *)(param_2 + iVar1 + 0x10) == '\0') {
      return 1;
    }
  } while (((*(uint *)(param_1 + 0x14) & 0x200) != 0) &&
          (param_1 = FUN_00105594(param_1,*(undefined4 *)(param_1 + 0x84)), param_1 != 0));
  return 0;
}

/* FUN_001382b8 @ 0x1382b8 (216 bytes) */
int FUN_001382b8(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  int iVar1;
  uint uVar2;
  
  *param_3 = param_2;
LAB_001382d4:
  do {
    uVar2 = *param_3;
    iVar1 = FUN_001054ec(param_1,0);
    if (*(char *)(uVar2 + iVar1 + 0x10) == '\0') {
      if ((param_1[5] & 1U) != 0) {
        return param_1;
      }
      iVar1 = (**(code **)(*param_1 + 100))(param_1);
      if (iVar1 == 0) goto LAB_001382d4;
      uVar2 = *param_3;
      iVar1 = FUN_001054ec(param_1,1);
      *param_3 = (uint)*(byte *)(uVar2 + iVar1 + 0x10);
      param_1 = (int *)FUN_00105594(param_1,1);
    }
    else {
      if ((param_1[5] & 0x200U) == 0) {
        return (int *)0x0;
      }
      param_1 = (int *)FUN_00105594(param_1,param_1[0x21]);
    }
    if (param_1 == (int *)0x0) {
      return (int *)0x0;
    }
  } while( true );
}

/* FUN_00138390 @ 0x138390 (772 bytes) */
int FUN_00138390(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  undefined4 local_48;
  int *local_44;
  undefined4 local_38 [5];
  
  piVar9 = *(int **)(*(int *)(param_1 + 300) + 0x98);
  piVar5 = (int *)piVar9[2];
  if (piVar5 == (int *)0x0) {
    return;
  }
  do {
    piVar11 = piVar9;
    if (piVar9 != (int *)0x0) {
      do {
        uVar3 = piVar11[5];
        if ((uVar3 & 1) != 0) {
          for (iVar10 = 1; iVar7 = (**(code **)(*piVar11 + 0x14))(piVar11), iVar10 <= iVar7;
              iVar10 = iVar10 + 1) {
            piVar5 = (int *)FUN_00105594(piVar11,iVar10);
            if ((((piVar5[0x20] != 0) && (iVar7 = FUN_00126760(piVar5[0x26]), iVar7 != 0)) &&
                ((piVar5[5] & 2U) == 0)) &&
               (iVar7 = (**(code **)(*piVar5 + 0x50))(piVar5), iVar7 == 0)) {
              iVar7 = FUN_001054ec(piVar11,iVar10);
              FUN_000f3398(local_38,*(undefined4 *)(iVar7 + 0x10));
              iVar7 = 0;
              local_48 = local_38[0];
              iVar8 = 4;
              do {
                if (*(char *)((int)&local_48 + iVar7) != '\0') {
                  uVar3 = piVar5[0x25] * 4 + iVar7;
                  iVar6 = (uVar3 >> 3 & 0x1ffffffc) + param_2;
                  *(uint *)(iVar6 + 8) = 1 << (uVar3 & 0x1f) | *(uint *)(iVar6 + 8);
                }
                iVar7 = iVar7 + 1;
                iVar8 = iVar8 + -1;
              } while (iVar8 != 0);
            }
          }
          if (((piVar11[0x20] != 0) && (iVar10 = FUN_00126760(piVar11[0x26]), iVar10 != 0)) &&
             (((piVar11[5] & 2U) == 0 &&
              (iVar10 = (**(code **)(*piVar11 + 0x50))(piVar11), iVar10 == 0)))) {
            iVar10 = 0;
            do {
              iVar7 = FUN_001054ec(piVar11,0);
              if (*(char *)(iVar10 + iVar7 + 0x10) != '\x01') {
                uVar3 = piVar11[0x25] * 4 + iVar10;
                iVar7 = (uVar3 >> 3 & 0x1ffffffc) + param_2;
                *(uint *)(iVar7 + 8) = 1 << (uVar3 & 0x1f) | *(uint *)(iVar7 + 8);
              }
              bVar2 = iVar10 != 3;
              iVar10 = iVar10 + 1;
            } while (bVar2);
          }
          iVar10 = *(int *)(param_1 + 300);
          iVar7 = 0;
          local_44 = (int *)0x0;
          for (uVar3 = 1; uVar3 <= *(uint *)(*(int *)(iVar10 + 300) + 4); uVar3 = uVar3 + 1) {
            local_44 = *(int **)(iVar7 + *(int *)(*(int *)(iVar10 + 300) + 8));
            if ((local_44[5] & 1U) != 0) {
              iVar10 = (**(code **)(*local_44 + 0x60))();
              if (iVar10 == 0) {
                iVar10 = 0;
                do {
                  iVar8 = FUN_001054ec(piVar11,0);
                  if (*(char *)(iVar10 + iVar8 + 0x10) != '\x01') {
                    uVar4 = local_44[0x25] * 4 + iVar10;
                    iVar8 = (uVar4 >> 3 & 0x1ffffffc) + param_2;
                    *(uint *)(iVar8 + 8) = 1 << (uVar4 & 0x1f) | *(uint *)(iVar8 + 8);
                  }
                  bVar2 = iVar10 != 3;
                  iVar10 = iVar10 + 1;
                } while (bVar2);
              }
              iVar10 = *(int *)(param_1 + 300);
            }
            iVar7 = iVar7 + 4;
          }
          uVar3 = piVar11[5];
        }
        piVar11 = (int *)piVar11[2];
      } while ((piVar11 != (int *)0x0) && ((uVar3 & 4) != 0));
      piVar5 = (int *)piVar9[2];
    }
    do {
      piVar11 = piVar5;
      puVar1 = (uint *)(piVar9 + 5);
      piVar5 = (int *)piVar11[2];
      if (piVar5 == (int *)0x0) {
        return;
      }
      piVar9 = piVar11;
    } while ((*puVar1 & 4) != 0);
  } while( true );
}

/* FUN_00138694 @ 0x138694 (2336 bytes) */
int FUN_00138694(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  uint *puVar1;
  bool bVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  undefined4 uVar19;
  int *piVar20;
  uint uVar21;
  undefined4 local_68;
  int local_64;
  undefined4 local_58 [3];
  
  iVar18 = param_2 * 4;
  iVar16 = 1;
  *(uint *)(param_3 + 0x30) = *(uint *)(param_3 + 0x30) | 0x1000;
  iVar5 = FUN_000ec4f0(param_3);
  uVar13 = iVar18 + 0x1fU >> 5;
  bVar2 = uVar13 != 0;
  iVar17 = uVar13 * 4 + 0xc;
  while( true ) {
    iVar10 = FUN_00194034(param_3 + 0x37c);
    if (iVar10 < iVar16) {
      puVar11 = (undefined4 *)FUN_000ec5b8(param_3);
      do {
        bVar2 = false;
        iVar18 = 1;
        puVar12 = puVar11;
        while( true ) {
          puVar12 = puVar12 + 1;
          iVar5 = FUN_00194034(param_3 + 0x37c);
          if (iVar5 < iVar18) break;
          piVar20 = (int *)*puVar12;
          iVar5 = (**(code **)(*piVar20 + 0x20))(piVar20);
          if (iVar5 == 0) {
            piVar4 = (int *)piVar20[0x41];
            iVar5 = *piVar4;
            if (iVar5 != 0) {
              if (iVar5 == 0) {
                iVar5 = 1;
              }
              do {
                piVar4[2] = 0;
                piVar4 = piVar4 + 1;
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
            }
            bVar3 = true;
            iVar5 = 0;
            local_64 = 0;
            for (uVar13 = 1; uVar13 <= *(uint *)(piVar20[0x34] + 4); uVar13 = uVar13 + 1) {
              local_64 = *(int *)(*(int *)(piVar20[0x34] + 8) + iVar5);
              if (local_64 != 0) {
                if (bVar3) {
                  piVar4 = (int *)piVar20[0x41];
                  iVar17 = *(int *)(local_64 + 0x100);
                  iVar16 = *piVar4;
                  if (iVar16 != 0) {
                    if (iVar16 == 0) {
                      iVar16 = 1;
                    }
                    do {
                      piVar9 = (int *)(iVar17 + 8);
                      iVar17 = iVar17 + 4;
                      piVar4[2] = *piVar9;
                      piVar4 = piVar4 + 1;
                      iVar16 = iVar16 + -1;
                    } while (iVar16 != 0);
                  }
                }
                else {
                  piVar4 = (int *)piVar20[0x41];
                  iVar17 = *(int *)(local_64 + 0x100);
                  iVar16 = *piVar4;
                  if (iVar16 != 0) {
                    if (iVar16 == 0) {
                      iVar16 = 1;
                    }
                    do {
                      puVar1 = (uint *)(iVar17 + 8);
                      iVar17 = iVar17 + 4;
                      piVar4[2] = piVar4[2] | *puVar1;
                      piVar4 = piVar4 + 1;
                      iVar16 = iVar16 + -1;
                    } while (iVar16 != 0);
                  }
                }
                bVar3 = false;
              }
              iVar5 = iVar5 + 4;
            }
            piVar4 = (int *)piVar20[0x41];
            bVar3 = false;
            iVar16 = piVar20[0x42];
            iVar17 = *piVar4;
            iVar5 = piVar20[0x40];
            if (iVar17 != 0) {
              bVar3 = false;
              if (iVar17 == 0) {
                iVar17 = 1;
              }
              do {
                uVar13 = piVar4[2] & ~*(uint *)(iVar16 + 8) | *(uint *)(iVar5 + 8);
                if (*(uint *)(iVar5 + 8) != uVar13) {
                  *(uint *)(iVar5 + 8) = uVar13;
                  bVar3 = true;
                }
                piVar4 = piVar4 + 1;
                iVar16 = iVar16 + 4;
                iVar5 = iVar5 + 4;
                iVar17 = iVar17 + -1;
              } while (iVar17 != 0);
            }
            bVar2 = bVar3 || bVar2;
          }
          iVar18 = iVar18 + 1;
        }
      } while (bVar2);
      return;
    }
    uVar19 = *(undefined4 *)(param_4 + 0x378);
    piVar20 = *(int **)(iVar5 + iVar16 * 4);
    puVar11 = (undefined4 *)FUN_00193e18(uVar19,iVar17);
    puVar12 = puVar11 + 1;
    *puVar11 = uVar19;
    puVar11[1] = uVar13;
    puVar11[2] = iVar18;
    if (bVar2) {
      puVar11 = puVar12;
      uVar21 = uVar13;
      if (uVar13 == 0) {
        uVar21 = 1;
      }
      do {
        puVar11[2] = 0;
        puVar11 = puVar11 + 1;
        uVar21 = uVar21 - 1;
      } while (uVar21 != 0);
    }
    piVar20[0x41] = (int)puVar12;
    uVar19 = *(undefined4 *)(param_4 + 0x378);
    puVar11 = (undefined4 *)FUN_00193e18(uVar19,iVar17);
    puVar12 = puVar11 + 1;
    *puVar11 = uVar19;
    puVar11[1] = uVar13;
    puVar11[2] = iVar18;
    if (bVar2) {
      puVar11 = puVar12;
      uVar21 = uVar13;
      if (uVar13 == 0) {
        uVar21 = 1;
      }
      do {
        puVar11[2] = 0;
        puVar11 = puVar11 + 1;
        uVar21 = uVar21 - 1;
      } while (uVar21 != 0);
    }
    piVar20[0x40] = (int)puVar12;
    uVar19 = *(undefined4 *)(param_4 + 0x378);
    puVar11 = (undefined4 *)FUN_00193e18(uVar19,iVar17);
    puVar12 = puVar11 + 1;
    *puVar11 = uVar19;
    puVar11[1] = uVar13;
    puVar11[2] = iVar18;
    if (bVar2) {
      puVar11 = puVar12;
      uVar21 = uVar13;
      if (uVar13 == 0) {
        uVar21 = 1;
      }
      do {
        puVar11[2] = 0;
        puVar11 = puVar11 + 1;
        uVar21 = uVar21 - 1;
      } while (uVar21 != 0);
    }
    piVar4 = (int *)piVar20[0x26];
    piVar20[0x42] = (int)puVar12;
    if (piVar4[2] != 0) break;
LAB_00138d5c:
    iVar10 = (**(code **)(*piVar20 + 0x18))(piVar20);
    if (iVar10 != 0) {
      ((int (*)())FUN_00138390)(piVar20,piVar20[0x40]);
    }
    iVar16 = iVar16 + 1;
  }
  do {
    iVar10 = (**(code **)(*piVar4 + 0x7c))(piVar4);
    piVar9 = piVar4;
    if (iVar10 == 0) {
      do {
        uVar21 = piVar9[5];
        if (((uVar21 & 1) != 0) && (*(int *)(piVar9[0x22] + 8) != 0x8e)) {
          iVar10 = (**(code **)(*piVar9 + 0x34))(piVar9);
          if ((iVar10 == 0) &&
             (((iVar10 = (**(code **)(*piVar9 + 0x38))(piVar9), iVar10 == 0 &&
               (iVar10 = (**(code **)(*piVar9 + 0x60))(piVar9), iVar10 == 0)) &&
              (iVar10 = (**(code **)(*piVar9 + 0x5c))(piVar9), iVar10 == 0)))) {
            uVar21 = piVar9[5];
            iVar10 = piVar9[0x21];
            if ((uVar21 & 0x200) != 0) {
              iVar10 = iVar10 + -1;
            }
            if (0 < iVar10) {
              iVar14 = 1;
              do {
                piVar6 = (int *)FUN_00105594(piVar9,iVar14);
                if (((piVar6[0x20] != 0) && (iVar7 = FUN_00126760(piVar6[0x26]), iVar7 != 0)) &&
                   (((piVar6[5] & 2U) == 0 &&
                    ((iVar7 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar7 == 0 &&
                     (iVar7 = ((int (*)())FUN_00137e98)(piVar9,iVar14,piVar9), iVar7 == 0)))))) {
                  iVar7 = FUN_001054ec(piVar9,iVar14);
                  iVar15 = 0;
                  FUN_000f3398(local_58,*(undefined4 *)(iVar7 + 0x10));
                  local_68 = local_58[0];
                  iVar7 = piVar6[0x25];
                  uVar21 = iVar7 << 2;
                  do {
                    if ((*(char *)((int)&local_68 + iVar15) != '\0') &&
                       (iVar8 = ((int (*)())FUN_00137e74)(piVar20[0x42],iVar7,iVar15), iVar8 == 0)) {
                      iVar8 = (uVar21 >> 3 & 0x1ffffffc) + piVar20[0x40];
                      *(uint *)(iVar8 + 8) = 1 << (uVar21 & 0x1f) | *(uint *)(iVar8 + 8);
                    }
                    bVar3 = iVar15 != 3;
                    uVar21 = uVar21 + 1;
                    iVar15 = iVar15 + 1;
                  } while (bVar3);
                }
                iVar14 = iVar14 + 1;
              } while (iVar14 <= iVar10);
              uVar21 = piVar9[5];
            }
            if ((uVar21 & 0x200) == 0) goto LAB_00138af0;
            piVar6 = (int *)FUN_00105594(piVar9,piVar9[0x21]);
            if ((((piVar6[0x20] != 0) && (iVar10 = FUN_00126760(piVar6[0x26]), iVar10 != 0)) &&
                ((piVar6[5] & 2U) == 0)) &&
               (iVar10 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar10 == 0)) {
              iVar14 = piVar6[0x25];
              iVar10 = ((int (*)())FUN_00137e98)(piVar9,piVar9[0x21],piVar9);
              if (iVar10 == 0) {
                uVar21 = iVar14 << 2;
                iVar10 = 0;
                do {
                  iVar7 = FUN_001054ec(piVar9,0);
                  if (((*(char *)(iVar10 + iVar7 + 0x10) == '\x01') &&
                      (iVar7 = ((int (*)())FUN_00137e74)(piVar20[0x42],iVar14,iVar10), iVar7 == 0)) &&
                     (iVar7 = ((int (*)())FUN_00138240)(piVar6,iVar10), iVar7 != 0)) {
                    iVar7 = (uVar21 >> 3 & 0x1ffffffc) + piVar20[0x40];
                    *(uint *)(iVar7 + 8) = 1 << (uVar21 & 0x1f) | *(uint *)(iVar7 + 8);
                  }
                  bVar3 = iVar10 != 3;
                  uVar21 = uVar21 + 1;
                  iVar10 = iVar10 + 1;
                } while (bVar3);
              }
            }
          }
          uVar21 = piVar9[5];
        }
LAB_00138af0:
        piVar6 = piVar4;
      } while (((int *)piVar9[2] != (int *)0x0) && (piVar9 = (int *)piVar9[2], (uVar21 & 4) != 0));
      do {
        uVar21 = piVar6[5];
        if (((uVar21 & 1) != 0) && (*(int *)(piVar6[0x22] + 8) != 0x8e)) {
          iVar10 = (**(code **)(*piVar6 + 0x34))(piVar6);
          if ((((iVar10 == 0) && (iVar10 = (**(code **)(*piVar6 + 0x38))(piVar6), iVar10 == 0)) &&
              (iVar10 = (**(code **)(*piVar6 + 0x60))(piVar6), iVar10 == 0)) &&
             (iVar10 = (**(code **)(*piVar6 + 0x5c))(piVar6), iVar10 == 0)) {
            if ((piVar6[0x20] == 0) || (iVar10 = FUN_00126760(piVar6[0x26]), iVar10 == 0)) {
LAB_00138c50:
              uVar21 = piVar6[5];
            }
            else {
              uVar21 = piVar6[5];
              if ((uVar21 & 2) == 0) {
                iVar10 = (**(code **)(*piVar6 + 0x50))(piVar6);
                if (iVar10 == 0) {
                  iVar10 = 0;
                  do {
                    iVar14 = FUN_001054ec(piVar6,0);
                    if (*(char *)(iVar10 + iVar14 + 0x10) != '\x01') {
                      uVar21 = piVar6[0x25] * 4 + iVar10;
                      iVar14 = (uVar21 >> 3 & 0x1ffffffc) + piVar20[0x42];
                      *(uint *)(iVar14 + 8) = 1 << (uVar21 & 0x1f) | *(uint *)(iVar14 + 8);
                    }
                    bVar3 = iVar10 != 3;
                    iVar10 = iVar10 + 1;
                  } while (bVar3);
                }
                goto LAB_00138c50;
              }
            }
            if ((uVar21 & 0x200) == 0) goto LAB_00138d24;
            piVar9 = (int *)FUN_00105594(piVar6,piVar6[0x21]);
            if (((piVar9[0x20] != 0) && (iVar10 = FUN_00126760(piVar9[0x26]), iVar10 != 0)) &&
               (((piVar9[5] & 2U) == 0 &&
                (iVar10 = (**(code **)(*piVar9 + 0x50))(piVar9), iVar10 == 0)))) {
              iVar10 = 0;
              do {
                iVar14 = FUN_001054ec(piVar6,0);
                if ((*(char *)(iVar10 + iVar14 + 0x10) == '\x01') &&
                   (iVar14 = ((int (*)())FUN_00138240)(piVar9,iVar10), iVar14 != 0)) {
                  uVar21 = piVar6[0x25] * 4 + iVar10;
                  iVar14 = (uVar21 >> 3 & 0x1ffffffc) + piVar20[0x42];
                  *(uint *)(iVar14 + 8) = 1 << (uVar21 & 0x1f) | *(uint *)(iVar14 + 8);
                }
                bVar3 = iVar10 != 3;
                iVar10 = iVar10 + 1;
              } while (bVar3);
            }
          }
          uVar21 = piVar6[5];
        }
LAB_00138d24: ;
      } while (((int *)piVar6[2] != (int *)0x0) && (piVar6 = (int *)piVar6[2], (uVar21 & 4) != 0));
    }
    piVar9 = (int *)piVar4[2];
    piVar6 = piVar4;
    do {
      piVar4 = piVar9;
      puVar1 = (uint *)(piVar6 + 5);
      if ((int *)piVar4[2] == (int *)0x0) goto LAB_00138d5c;
      piVar9 = (int *)piVar4[2];
      piVar6 = piVar4;
    } while ((*puVar1 & 4) != 0);
  } while( true );
}

/* FUN_00138fb4 @ 0x138fb4 (84 bytes) */
int FUN_00138fb4(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 8) + 0x30c);
  (**(code **)(*piVar1 + 0x6c))(piVar1,param_1,param_4);
  FUN_0014846c(param_1,param_4);
  return;
}

/* FUN_00139008 @ 0x139008 (44 bytes) */
int FUN_00139008(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 4;
  iVar3 = 0;
  uVar2 = 0;
  do {
    uVar1 = uVar2 & 0x3f;
    uVar2 = uVar2 + 1;
    iVar3 = iVar3 + (param_1 >> uVar1 & 1U);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return iVar3;
}

/* FUN_00139034 @ 0x139034 (40 bytes) */
int FUN_00139034(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x158);
  if (((iVar1 != param_3) && (iVar1 != param_4)) && (iVar1 != param_2)) {
    return 1;
  }
  return 0;
}

/* FUN_0013905c @ 0x13905c (308 bytes) */
int FUN_0013905c(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  (**(code **)(*param_2 + 0x14))(param_2);
  piVar1 = (int *)FUN_00105594(param_2,1);
  while (iVar2 = (**(code **)(*piVar1 + 0x60))(piVar1), iVar2 != 0) {
    piVar1 = (int *)FUN_00105594(piVar1,1);
  }
  piVar3 = (int *)FUN_00105594(param_2,2);
  while (iVar2 = (**(code **)(*piVar3 + 0x60))(piVar3), iVar2 != 0) {
    piVar3 = (int *)FUN_00105594(piVar3,1);
  }
  while( true ) {
    do {
      param_2 = (int *)param_2[1];
      iVar2 = (**(code **)(*param_2 + 0x60))(param_2);
    } while (iVar2 != 0);
    if (param_1 == param_2) break;
    if (((param_2 == piVar1) || (param_2 == piVar3)) ||
       (iVar2 = (**(code **)(*param_2 + 0x34))(param_2), iVar2 != 0)) {
      return 0;
    }
  }
  return 1;
}

/* FUN_00139190 @ 0x139190 (156 bytes) */
int FUN_00139190(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 local_28;
  
  uVar1 = *(uint *)(param_1 + 4) - 1;
  piVar2 = (int *)0x0;
  if (uVar1 < *(uint *)(param_1 + 4)) {
    piVar2 = (int *)(uVar1 * 4 + *(int *)(param_1 + 8));
  }
  local_28 = *piVar2;
  if ((char)local_28 == '\0') {
    return local_28 == param_2;
  }
  if (param_2 < 5) {
    iVar4 = 0;
    if (param_2 < 1) goto LAB_00139218;
  }
  else {
    param_2 = 4;
  }
  iVar3 = 0;
  iVar4 = 0;
  do {
    if (*(char *)((int)&local_28 + iVar3) != -1) {
      iVar4 = iVar4 + 1;
    }
    iVar3 = iVar3 + 1;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
LAB_00139218:
  return iVar4 < 2;
}

