#include "decls.h"

/* FUN_0010f704 @ 0x10f704 (376 bytes) */
int FUN_0010f704(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  int param_3;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  uint uVar10;
  
  uVar9 = *(undefined4 *)(param_3 + 0x378);
  puVar3 = (undefined4 *)FUN_00193e18(uVar9,0x14);
  puVar8 = puVar3 + 1;
  puVar3[1] = 2;
  *puVar3 = uVar9;
  puVar3[2] = 0x30;
  uVar6 = 0;
  puVar2 = puVar8;
  do {
    uVar6 = uVar6 + 1;
    puVar2[2] = 0;
    puVar2 = puVar2 + 1;
  } while (uVar6 < 2);
  uVar6 = param_2[1];
  uVar10 = 0;
  if (uVar6 != 0) {
    do {
      if (uVar10 < *param_2) {
        if (uVar6 <= uVar10) {
          _memset((void *)(uVar6 * 4 + param_2[2]),0,(uVar10 - uVar6) * 4 + 4);
          param_2[1] = uVar10 + 1;
        }
        piVar4 = (int *)(uVar10 * 4 + param_2[2]);
      }
      else {
        piVar4 = (int *)FUN_0019423c(param_2,uVar10);
      }
      uVar10 = uVar10 + 1;
      if (*(int *)(*piVar4 + 0x1c) == param_1) {
        uVar6 = *(uint *)(*piVar4 + 0x14);
        uVar7 = uVar6 >> 3 & 0x1ffffffc;
        *(uint *)((int)puVar8 + uVar7 + 8) =
             1 << (uVar6 & 0x1f) | *(uint *)((int)puVar8 + uVar7 + 8);
      }
      uVar6 = param_2[1];
    } while (uVar10 < uVar6);
  }
  iVar1 = puVar3[2];
  iVar5 = 0;
  if (iVar1 != 0) {
    uVar6 = 0;
    do {
      if ((*(uint *)((int)puVar8 + (uVar6 >> 3 & 0x1ffffffc) + 8) >> (uVar6 & 0x1f) & 1) != 0) {
        iVar5 = iVar5 + 1;
      }
      uVar6 = uVar6 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return iVar5;
}

/* FUN_0010f87c @ 0x10f87c (424 bytes) */
int FUN_0010f87c(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint *param_3;
{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  int iVar13;
  
  uVar2 = param_3[1];
  if (uVar2 != 0) {
    uVar7 = 0;
    do {
      if (uVar7 < *param_3) {
        if (uVar2 <= uVar7) {
          _memset((void *)(uVar2 * 4 + param_3[2]),0,(uVar7 - uVar2) * 4 + 4);
          param_3[1] = uVar7 + 1;
        }
        puVar3 = (undefined4 *)(uVar7 * 4 + param_3[2]);
      }
      else {
        puVar3 = (undefined4 *)FUN_0019423c(param_3,uVar7);
      }
      uVar6 = uVar7 + 1;
      iVar9 = *(int *)*puVar3;
      if (*(uint *)(iVar9 + 0x94) != uVar7) {
        iVar4 = FUN_001054ec(iVar9,0);
        iVar8 = 0;
        *(uint *)(iVar4 + 8) = uVar7;
        do {
          puVar11 = *(uint **)(param_1 + 0x418);
          uVar2 = puVar11[1];
          if (uVar2 != 0) {
            uVar10 = 0;
            do {
              if (uVar10 < *puVar11) {
                if (uVar2 <= uVar10) {
                  _memset((void *)(uVar2 * 4 + puVar11[2]),0,(uVar10 - uVar2) * 4 + 4);
                  puVar11[1] = uVar10 + 1;
                }
                piVar5 = (int *)(uVar10 * 4 + puVar11[2]);
              }
              else {
                piVar5 = (int *)FUN_0019423c(puVar11,uVar10);
              }
              iVar13 = *piVar5;
              iVar12 = *(int *)(iVar13 + 4);
              iVar4 = FUN_00104ee4(iVar9,iVar8);
              if (((iVar12 == iVar4) &&
                  (iVar12 = *(int *)(iVar13 + 8), iVar4 = FUN_00104180(iVar9,iVar8), iVar12 == iVar4
                  )) && (*(int *)(iVar13 + 0x18) == iVar8)) {
                *(uint *)(iVar13 + 0xc) = uVar7;
                *(uint *)(iVar13 + 0x14) = uVar7;
                break;
              }
              puVar11 = *(uint **)(param_1 + 0x418);
              uVar10 = uVar10 + 1;
              uVar2 = puVar11[1];
            } while (uVar10 < uVar2);
          }
          bVar1 = iVar8 != 3;
          iVar8 = iVar8 + 1;
        } while (bVar1);
      }
      uVar2 = param_3[1];
      uVar7 = uVar6;
    } while (uVar6 < uVar2);
  }
  return;
}

/* FUN_0010fa24 @ 0x10fa24 (304 bytes) */
int FUN_0010fa24(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  uint *param_5;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  
  uVar2 = param_5[1];
  if (uVar2 != 0) {
    uVar6 = 0;
    do {
      if (uVar6 < *param_5) {
        if (uVar2 <= uVar6) {
          _memset((void *)(uVar2 * 4 + param_5[2]),0,(uVar6 - uVar2) * 4 + 4);
          param_5[1] = uVar6 + 1;
        }
        piVar4 = (int *)(uVar6 * 4 + param_5[2]);
      }
      else {
        piVar4 = (int *)FUN_0019423c(param_5,uVar6);
      }
      uVar6 = uVar6 + 1;
      iVar5 = *piVar4;
      if ((*(int *)(iVar5 + 0x1c) == param_1) && (param_3 < param_4)) {
        iVar3 = param_3;
        if (*(int *)(iVar5 + 0x14) != *(int *)(param_2 + param_3 * 4)) {
          iVar1 = param_4 - param_3;
          piVar4 = (int *)(param_2 + param_3 * 4);
          do {
            iVar3 = iVar3 + 1;
            iVar1 = iVar1 + -1;
            if (iVar1 == 0) goto LAB_0010fb28;
            piVar4 = piVar4 + 1;
          } while (*piVar4 != *(int *)(iVar5 + 0x14));
        }
        *(int *)(iVar5 + 0x14) = iVar3;
      }
LAB_0010fb28:
      uVar2 = param_5[1];
    } while (uVar6 < uVar2);
  }
  return;
}

/* FUN_0010fb54 @ 0x10fb54 (308 bytes) */
int FUN_0010fb54(param_1, param_2, param_3)
  uint *param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  undefined4 auStack_f8 [51];
  
  iVar4 = 1;
  iVar6 = *param_2;
  *param_2 = iVar6 + 4;
  uVar1 = param_1[1];
  if (0 < (int)uVar1) {
    uVar7 = 0;
    iVar4 = 0;
    do {
      if (uVar7 < *param_1) {
        if (uVar1 <= uVar7) {
          _memset((void *)(uVar1 * 4 + param_1[2]),0,(uVar7 - uVar1) * 4 + 4);
          param_1[1] = uVar7 + 1;
        }
        puVar2 = (undefined4 *)(uVar7 * 4 + param_1[2]);
      }
      else {
        puVar2 = (undefined4 *)FUN_0019423c(param_1,uVar7);
      }
      uVar7 = uVar7 + 1;
      piVar8 = (int *)*puVar2;
      iVar9 = *piVar8;
      iVar3 = FUN_0010e40c(*(undefined4 *)(iVar9 + 0x13c),*(undefined4 *)(iVar9 + 0x140));
      iVar5 = iVar6 + iVar3;
      if (3 < iVar3) {
        iVar5 = *param_2;
        *param_2 = iVar5 + 1;
        iVar9 = *piVar8;
      }
      auStack_f8[iVar5] = *(undefined4 *)(iVar9 + 0x94);
      iVar3 = *piVar8;
      *(undefined4 *)(iVar3 + 0x98) = 5;
      *(int *)(iVar3 + 0x94) = iVar5;
      if (iVar4 < iVar5) {
        iVar4 = iVar5;
      }
      uVar1 = param_1[1];
    } while ((int)uVar7 < (int)uVar1);
    iVar4 = iVar4 + 1;
  }
  ((int (*)())FUN_0010fa24)(2,auStack_f8,iVar6,iVar4,*(undefined4 *)(param_3 + 0x418));
  return;
}

/* FUN_0010fc88 @ 0x10fc88 (272 bytes) */
int FUN_0010fc88(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint *param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  undefined4 auStack_f8 [53];
  
  uVar2 = param_2[1];
  iVar7 = *(int *)(param_4 + 0x3f0);
  iVar5 = 1;
  if (0 < (int)uVar2) {
    uVar8 = 0;
    iVar5 = 0;
    do {
      if (uVar8 < *param_2) {
        if (uVar2 <= uVar8) {
          _memset((void *)(uVar2 * 4 + param_2[2]),0,(uVar8 - uVar2) * 4 + 4);
          param_2[1] = uVar8 + 1;
        }
        puVar4 = (undefined4 *)(uVar8 * 4 + param_2[2]);
      }
      else {
        puVar4 = (undefined4 *)FUN_0019423c(param_2,uVar8);
      }
      uVar8 = uVar8 + 1;
      piVar6 = (int *)*puVar4;
      iVar3 = *piVar6;
      iVar1 = iVar7 + *(int *)(iVar3 + 0x140);
      auStack_f8[iVar1] = *(undefined4 *)(iVar3 + 0x94);
      iVar3 = *piVar6;
      *(undefined4 *)(iVar3 + 0x98) = 5;
      *(int *)(iVar3 + 0x94) = iVar1;
      if (iVar5 < iVar1) {
        iVar5 = iVar1;
      }
      uVar2 = param_2[1];
    } while ((int)uVar8 < (int)uVar2);
    iVar5 = iVar5 + 1;
  }
  ((int (*)())FUN_0010fa24)(param_1,auStack_f8,iVar7,iVar5,*(undefined4 *)(param_4 + 0x418));
  return;
}

/* FUN_0010fd98 @ 0x10fd98 (396 bytes) */
int FUN_0010fd98(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint *param_2;
  int *param_3;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  int local_f8 [52];
  
  iVar11 = 0x30;
  iVar3 = 0;
  do {
    *(undefined4 *)((int)local_f8 + iVar3) = 0xffffffff;
    iVar3 = iVar3 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  uVar5 = param_2[1];
  iVar11 = *param_3;
  iVar3 = iVar11;
  if (0 < (int)uVar5) {
    uVar10 = 0;
    do {
      if (uVar10 < *param_2) {
        if (uVar5 <= uVar10) {
          _memset((void *)(uVar5 * 4 + param_2[2]),0,(uVar10 - uVar5) * 4 + 4);
          param_2[1] = uVar10 + 1;
        }
        puVar6 = (undefined4 *)(uVar10 * 4 + param_2[2]);
      }
      else {
        puVar6 = (undefined4 *)FUN_0019423c(param_2,uVar10);
      }
      uVar10 = uVar10 + 1;
      piVar7 = (int *)*puVar6;
      iVar3 = *(int *)(*piVar7 + 0x94);
      if (iVar11 < 0x30) {
        iVar2 = 0x30 - iVar11;
        piVar9 = local_f8 + iVar11;
        bVar1 = false;
        iVar8 = iVar11;
        do {
          if (iVar3 == *piVar9) {
            iVar4 = *piVar7;
            bVar1 = true;
            *(undefined4 *)(iVar4 + 0x98) = 5;
            *(int *)(iVar4 + 0x94) = iVar8;
          }
          iVar8 = iVar8 + 1;
          piVar9 = piVar9 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        if (!bVar1) goto LAB_0010febc;
      }
      else {
LAB_0010febc:
        iVar8 = *param_3;
        local_f8[iVar8] = iVar3;
        iVar3 = *piVar7;
        *(int *)(iVar3 + 0x94) = iVar8;
        *(undefined4 *)(iVar3 + 0x98) = 5;
        *param_3 = *param_3 + 1;
      }
      uVar5 = param_2[1];
    } while ((int)uVar10 < (int)uVar5);
    iVar3 = *param_3;
  }
  ((int (*)())FUN_0010fa24)(param_1,local_f8,iVar11,iVar3,*(undefined4 *)(param_4 + 0x418));
  return;
}

/* FUN_0010ff24 @ 0x10ff24 (252 bytes) */
int FUN_0010ff24(param_1, param_2)
  int *param_1;
  uint *param_2;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  uVar2 = param_2[1];
  if (uVar2 != 0) {
    uVar6 = 0;
    do {
      if (uVar6 < *param_2) {
        if (uVar2 <= uVar6) {
          _memset((void *)(uVar2 * 4 + param_2[2]),0,(uVar6 - uVar2) * 4 + 4);
          param_2[1] = uVar6 + 1;
        }
        piVar3 = (int *)(uVar6 * 4 + param_2[2]);
      }
      else {
        piVar3 = (int *)FUN_0019423c(param_2,uVar6);
      }
      uVar6 = uVar6 + 1;
      piVar3 = (int *)*piVar3;
      if (piVar3[7] == param_1[6]) {
        iVar7 = 4;
        iVar5 = 0;
        piVar4 = param_1;
        do {
          if (*piVar3 == piVar4[1]) {
            iVar1 = *(int *)(*param_1 + 0x94);
            piVar3[6] = iVar5;
            piVar3[5] = iVar1;
          }
          iVar5 = iVar5 + 1;
          piVar4 = piVar4 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      uVar2 = param_2[1];
    } while (uVar6 < uVar2);
  }
  return;
}

/* FUN_00110020 @ 0x110020 (204 bytes) */
int FUN_00110020(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int *piVar14;
  uint *puVar15;
  
  piVar14 = *(int **)(param_2 + 0xb0);
  iVar2 = FUN_0010e634(piVar14);
  if (iVar2 == 0) {
    return;
  }
  iVar2 = FUN_001054ec(piVar14,0);
  if (*(int *)(iVar2 + 0x10) == DAT_001afa14) {
    FUN_000ef970(param_1,piVar14);
                    
                    
    (**(code **)(*piVar14 + 0xc))(piVar14,0,*(undefined4 *)(param_1 + 8));
    return;
  }
  uVar12 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  puVar3 = (undefined4 *)FUN_00193e18(uVar12,0x30);
  piVar8 = puVar3 + 1;
  *puVar3 = uVar12;
  FUN_0010e814(piVar8,piVar14);
  iVar2 = FUN_0010e744(piVar14);
  if (iVar2 == 0) {
    iVar2 = FUN_0010e6e8(piVar14);
    if (iVar2 == 0) {
      iVar2 = FUN_0010e690(piVar14);
      if (iVar2 == 0) goto LAB_001101ac;
      puVar15 = *(uint **)(param_1 + 0x424);
      uVar10 = puVar15[1];
      if (uVar10 < *puVar15) goto LAB_00110170;
    }
    else {
      puVar15 = *(uint **)(param_1 + 0x420);
      uVar10 = puVar15[1];
      if (uVar10 < *puVar15) goto LAB_00110170;
    }
LAB_0011019c:
    puVar3 = (undefined4 *)FUN_0019423c(puVar15,uVar10);
  }
  else {
    puVar15 = *(uint **)(param_1 + 0x41c);
    uVar10 = puVar15[1];
    if (*puVar15 <= uVar10) goto LAB_0011019c;
LAB_00110170:
    _memset((void *)(uVar10 * 4 + puVar15[2]),0,4);
    puVar3 = (undefined4 *)(uVar10 * 4 + puVar15[2]);
    puVar15[1] = uVar10 + 1;
  }
  *puVar3 = piVar8;
LAB_001101ac:
  iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),7);
  if (iVar2 != 0) {
    FUN_00172f34(param_2);
    FUN_0010e8e4(piVar8,param_2 + 0x20);
  }
  iVar2 = 0;
  do {
    iVar4 = FUN_001054ec(*piVar8,0);
    if (*(char *)(iVar2 + iVar4 + 0x10) != '\x01') {
      uVar9 = *(undefined4 *)(param_2 + 0x20);
      uVar12 = FUN_00104ee4(*piVar8,iVar2);
      uVar5 = FUN_00104180(*piVar8,iVar2);
      uVar11 = *(undefined4 *)(*piVar8 + 0x94);
      uVar6 = FUN_0010e368(*(undefined4 *)(*piVar8 + 0x13c));
      uVar13 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar3 = (undefined4 *)FUN_00193e18(uVar13,0x24);
      *puVar3 = uVar13;
      puVar3[1] = uVar9;
      puVar3[2] = uVar12;
      puVar3[3] = uVar5;
      puVar3[6] = uVar11;
      puVar3[8] = uVar6;
      puVar3[4] = uVar11;
      puVar3[5] = iVar2;
      puVar3[7] = iVar2;
      puVar15 = *(uint **)(param_1 + 0x418);
      uVar10 = puVar15[1];
      if (uVar10 < *puVar15) {
        _memset((void *)(uVar10 * 4 + puVar15[2]),0,4);
        puVar7 = (undefined4 *)(uVar10 * 4 + puVar15[2]);
        puVar15[1] = uVar10 + 1;
      }
      else {
        puVar7 = (undefined4 *)FUN_0019423c(puVar15,uVar10);
      }
      *puVar7 = puVar3 + 1;
    }
    bVar1 = iVar2 != 3;
    param_2 = param_2 + 4;
    iVar2 = iVar2 + 1;
  } while (bVar1);
  return;
}

/* FUN_001102e0 @ 0x1102e0 (124 bytes) */
int FUN_001102e0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint *param_3;
{
  bool bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined4 *puVar17;
  int *piVar18;
  int iVar19;
  undefined1 *puVar20;
  int iVar21;
  int *piVar22;
  uint *puVar23;
  int *piVar24;
  undefined4 uVar25;
  uint uVar26;
  undefined4 uVar27;
  undefined4 *puVar28;
  uint *puVar29;
  uint *puVar30;
  uint uVar31;
  uint uVar32;
  uint *puVar33;
  int iStack0000001c;
  undefined4 local_98;
  int local_94 [4];
  undefined1 local_84 [28];
  int local_68;
  undefined *local_64;
  uint local_60;
  int *local_5c;
  undefined *local_58;
  undefined1 *local_54;
  
  uVar25 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  iStack0000001c = param_2;
  puVar6 = (undefined4 *)FUN_00193e18(uVar25,0x14);
  *puVar6 = uVar25;
  puVar6[1] = 2;
  puVar6[2] = 0;
  puVar6[4] = uVar25;
  uVar25 = FUN_00193e18(uVar25,8);
  puVar6[3] = uVar25;
  uVar26 = 0;
  puVar30 = *(uint **)(param_1 + 0x418);
  uVar7 = puVar30[1];
  if (uVar7 != 0) {
    do {
      if (uVar26 < *puVar30) {
        if (uVar7 <= uVar26) {
          _memset((void *)(uVar7 * 4 + puVar30[2]),0,(uVar26 - uVar7) * 4 + 4);
          puVar30[1] = uVar26 + 1;
        }
        piVar24 = (int *)(uVar26 * 4 + puVar30[2]);
      }
      else {
        piVar24 = (int *)FUN_0019423c(puVar30,uVar26);
      }
      uVar26 = uVar26 + 1;
      piVar24 = (int *)*piVar24;
      if (iStack0000001c == piVar24[7]) {
        uVar7 = puVar6[2];
        if ((int)uVar7 < 1) {
          iVar8 = *piVar24;
        }
        else {
          iVar8 = *piVar24;
          uVar32 = 0;
          uVar31 = uVar7;
          do {
            piVar24 = (int *)0x0;
            if (uVar32 < uVar7) {
              piVar24 = (int *)(uVar32 * 4 + puVar6[3]);
            }
            if (*piVar24 == iVar8) goto LAB_0011047c;
            uVar32 = uVar32 + 1;
            uVar31 = uVar31 - 1;
          } while (uVar31 != 0);
        }
        if (uVar7 < (uint)puVar6[1]) {
          _memset((void *)(uVar7 * 4 + puVar6[3]),0,4);
          piVar24 = (int *)(uVar7 * 4 + puVar6[3]);
          puVar6[2] = uVar7 + 1;
        }
        else {
          piVar24 = (int *)FUN_0019423c(puVar6 + 1,uVar7);
        }
        *piVar24 = iVar8;
      }
LAB_0011047c:
      puVar30 = *(uint **)(param_1 + 0x418);
      uVar7 = puVar30[1];
    } while (uVar26 < uVar7);
  }
  uVar7 = puVar6[2];
  local_68 = ((int)uVar7 >> 2) + (uint)((int)uVar7 < 0 && (uVar7 & 3) != 0);
  *(uint *)(param_1 + 0x428) = uVar7;
  if ((uVar7 & 3) != 0) {
    local_68 = local_68 + 1;
  }
  iVar8 = ((int (*)())FUN_0010f704)(iStack0000001c,puVar30,*(undefined4 *)(param_1 + 8));
  if (local_68 < iVar8) {
    uVar7 = param_3[1];
    uVar26 = 0;
    if (uVar7 == 0) {
      uVar7 = 0;
    }
    else {
      do {
        if (uVar26 < *param_3) {
          if (uVar7 <= uVar26) {
            _memset((void *)(uVar7 * 4 + param_3[2]),0,(uVar26 - uVar7) * 4 + 4);
            param_3[1] = uVar26 + 1;
          }
          puVar6 = (undefined4 *)(uVar26 * 4 + param_3[2]);
        }
        else {
          puVar6 = (undefined4 *)FUN_0019423c(param_3,uVar26);
        }
        uVar26 = uVar26 + 1;
        FUN_0019401c(*(undefined4 *)*puVar6);
        uVar7 = param_3[1];
      } while (uVar26 < uVar7);
    }
    if (uVar7 != 0) {
      uVar26 = 0;
      do {
        if (uVar26 < *param_3) {
          if (uVar7 <= uVar26) {
            _memset((void *)(uVar7 * 4 + param_3[2]),0,(uVar26 - uVar7) * 4 + 4);
            param_3[1] = uVar26 + 1;
          }
          puVar6 = (undefined4 *)(uVar26 * 4 + param_3[2]);
        }
        else {
          puVar6 = (undefined4 *)FUN_0019423c(param_3,uVar26);
        }
        uVar26 = uVar26 + 1;
        piVar22 = (int *)*puVar6;
        iVar8 = 0;
        piVar24 = piVar22;
        do {
          iVar9 = FUN_001054ec(*piVar22,0);
          if ((*(char *)(iVar8 + iVar9 + 0x10) != '\x01') &&
             (iVar9 = FUN_0010e3b4(piVar22,iVar8), -1 < iVar9)) {
            iVar5 = piVar22[5];
            piVar24[1] = 0;
            piVar22[5] = iVar5 + -1;
            puVar30 = *(uint **)(param_1 + 0x418);
            uVar7 = puVar30[1];
            if (uVar7 != 0) {
              uVar31 = 0;
              do {
                if (uVar31 < *puVar30) {
                  if (uVar7 <= uVar31) {
                    _memset((void *)(uVar7 * 4 + puVar30[2]),0,(uVar31 - uVar7) * 4 + 4);
                    puVar30[1] = uVar31 + 1;
                  }
                  piVar10 = (int *)(uVar31 * 4 + puVar30[2]);
                }
                else {
                  piVar10 = (int *)FUN_0019423c(puVar30,uVar31);
                }
                iVar5 = *piVar10;
                if (((iStack0000001c == *(int *)(iVar5 + 0x1c)) && (*(int *)(iVar5 + 0x10) == iVar8)
                    ) && (*(int *)(iVar5 + 0xc) == *(int *)(*piVar22 + 0x94))) {
                  *(int *)(iVar5 + 0x18) = iVar9;
                  break;
                }
                puVar30 = *(uint **)(param_1 + 0x418);
                uVar31 = uVar31 + 1;
                uVar7 = puVar30[1];
              } while (uVar31 < uVar7);
            }
            *(undefined1 *)(iVar8 + *piVar22 + 0x9c) = 1;
          }
          bVar1 = iVar8 != 3;
          piVar24 = piVar24 + 1;
          iVar8 = iVar8 + 1;
        } while (bVar1);
        uVar7 = param_3[1];
      } while (uVar26 < uVar7);
    }
    iVar8 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0xc4))();
    if (iVar8 == 0) {
      uVar7 = param_3[1];
      uVar26 = 0;
      if (uVar7 == 0) {
        uVar7 = 0;
      }
      else {
        do {
          if (uVar26 < *param_3) {
            if (uVar7 <= uVar26) {
              _memset((void *)(uVar7 * 4 + param_3[2]),0,(uVar26 - uVar7) * 4 + 4);
              param_3[1] = uVar26 + 1;
            }
            puVar6 = (undefined4 *)(uVar26 * 4 + param_3[2]);
          }
          else {
            puVar6 = (undefined4 *)FUN_0019423c(param_3,uVar26);
          }
          uVar26 = uVar26 + 1;
          piVar24 = (int *)*puVar6;
          iVar8 = FUN_0010ecb8(*piVar24);
          if (iVar8 != 0) {
            iVar8 = 0;
            do {
              iVar9 = FUN_001054ec(*piVar24,0);
              if ((*(char *)(iVar8 + iVar9 + 0x10) == '\x01') && (iVar9 = iVar8 + 1, iVar9 < 4)) {
                do {
                  iVar5 = FUN_001054ec(*piVar24,0);
                  if (*(char *)(iVar9 + iVar5 + 0x10) == '\0') {
                    iVar14 = *piVar24;
                    iVar5 = piVar24[iVar8 + 1];
                    piVar24[iVar8 + 1] = piVar24[iVar9 + 1];
                    piVar24[iVar9 + 1] = iVar5;
                    *(undefined1 *)(iVar8 + iVar14 + 0x9c) = 0;
                    *(undefined1 *)(iVar9 + *piVar24 + 0x9c) = 1;
                    iVar5 = FUN_001054ec(*piVar24,1);
                    uVar3 = *(undefined1 *)(iVar9 + iVar5 + 0x10);
                    iVar5 = FUN_001054ec(*piVar24,1);
                    uVar2 = *(undefined1 *)(iVar8 + iVar5 + 0x10);
                    (**(code **)(*(int *)*piVar24 + 0x88))((int *)*piVar24,1,iVar8,uVar3);
                    (**(code **)(*(int *)*piVar24 + 0x88))((int *)*piVar24,1,iVar9,uVar2);
                    break;
                  }
                  bVar1 = iVar9 != 3;
                  iVar9 = iVar9 + 1;
                } while (bVar1);
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 < 4);
            puVar30 = *(uint **)(param_1 + 0x418);
            uVar31 = 0;
            uVar7 = puVar30[1];
            if (uVar7 != 0) {
              do {
                if (uVar31 < *puVar30) {
                  if (uVar7 <= uVar31) {
                    _memset((void *)(uVar7 * 4 + puVar30[2]),0,(uVar31 - uVar7) * 4 + 4);
                    puVar30[1] = uVar31 + 1;
                  }
                  piVar22 = (int *)(uVar31 * 4 + puVar30[2]);
                }
                else {
                  piVar22 = (int *)FUN_0019423c(puVar30,uVar31);
                }
                uVar31 = uVar31 + 1;
                piVar22 = (int *)*piVar22;
                if ((iStack0000001c == piVar22[7]) && (piVar22[3] == *(int *)(*piVar24 + 0x94))) {
                  iVar9 = 4;
                  iVar8 = 0;
                  piVar10 = piVar24;
                  do {
                    if (*piVar22 == piVar10[1]) {
                      piVar22[6] = iVar8;
                      break;
                    }
                    iVar8 = iVar8 + 1;
                    piVar10 = piVar10 + 1;
                    iVar9 = iVar9 + -1;
                  } while (iVar9 != 0);
                }
                puVar30 = *(uint **)(param_1 + 0x418);
                uVar7 = puVar30[1];
              } while (uVar31 < uVar7);
            }
          }
          uVar7 = param_3[1];
        } while (uVar26 < uVar7);
      }
      iVar8 = 4;
      do {
        if (0 < (int)uVar7) {
          uVar26 = 0;
          do {
            if (uVar26 < *param_3) {
              if (uVar7 <= uVar26) {
                _memset((void *)(uVar7 * 4 + param_3[2]),0,(uVar26 - uVar7) * 4 + 4);
                param_3[1] = uVar26 + 1;
                uVar7 = uVar26 + 1;
              }
              puVar6 = (undefined4 *)(uVar26 * 4 + param_3[2]);
            }
            else {
              puVar6 = (undefined4 *)FUN_0019423c(param_3,uVar26);
              uVar7 = param_3[1];
            }
            uVar26 = uVar26 + 1;
            piVar24 = (int *)*puVar6;
            if ((iVar8 == piVar24[5]) && (uVar31 = 0, 0 < (int)uVar7)) {
              do {
                if (uVar31 < *param_3) {
                  if (uVar7 <= uVar31) {
                    _memset((void *)(uVar7 * 4 + param_3[2]),0,(uVar31 - uVar7) * 4 + 4);
                    param_3[1] = uVar31 + 1;
                  }
                  puVar6 = (undefined4 *)(uVar31 * 4 + param_3[2]);
                }
                else {
                  puVar6 = (undefined4 *)FUN_0019423c(param_3,uVar31);
                }
                piVar22 = (int *)*puVar6;
                iVar9 = FUN_0010e460(piVar22,piVar24,local_94);
                if (iVar9 != 0) {
                  puVar30 = *(uint **)(param_1 + 0x418);
                  uVar7 = puVar30[1];
                  iVar9 = *(int *)(*piVar22 + 0x94);
                  uVar25 = *(undefined4 *)(*piVar24 + 0x94);
                  if (0 < (int)uVar7) {
                    uVar32 = 0;
                    do {
                      if (uVar32 < *puVar30) {
                        if (uVar7 <= uVar32) {
                          _memset((void *)(uVar7 * 4 + puVar30[2]),0,(uVar32 - uVar7) * 4 + 4);
                          puVar30[1] = uVar32 + 1;
                        }
                        piVar10 = (int *)(uVar32 * 4 + puVar30[2]);
                      }
                      else {
                        piVar10 = (int *)FUN_0019423c(puVar30,uVar32);
                      }
                      uVar32 = uVar32 + 1;
                      iVar5 = *piVar10;
                      if (((iStack0000001c == *(int *)(iVar5 + 0x1c)) &&
                          (iVar9 == *(int *)(iVar5 + 0x14))) &&
                         (local_94[*(int *)(iVar5 + 0x18)] != -1)) {
                        *(int *)(iVar5 + 0x18) = local_94[*(int *)(iVar5 + 0x18)];
                        *(undefined4 *)(iVar5 + 0x14) = uVar25;
                      }
                      puVar30 = *(uint **)(param_1 + 0x418);
                      uVar7 = puVar30[1];
                    } while ((int)uVar32 < (int)uVar7);
                  }
                  FUN_00194374(param_3,piVar22);
                  uVar31 = uVar31 - 1;
                  FUN_000ef970(param_1,*piVar22);
                  *(int *)(param_1 + 0x230) = *(int *)(param_1 + 0x230) + 1;
                }
                uVar7 = param_3[1];
                uVar31 = uVar31 + 1;
              } while ((int)uVar31 < (int)uVar7);
            }
          } while ((int)uVar26 < (int)uVar7);
        }
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    puVar30 = (uint *)0x0;
    iVar8 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0xc4))();
    if (iVar8 != 0) {
      uVar25 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
      puVar6 = (undefined4 *)FUN_00193e18(uVar25,0x14);
      puVar30 = puVar6 + 1;
      puVar6[1] = 2;
      *puVar6 = uVar25;
      puVar6[2] = 0;
      puVar6[4] = uVar25;
      uVar25 = FUN_00193e18(uVar25,8);
      uVar7 = param_3[1];
      iVar8 = 4;
      puVar6[3] = uVar25;
      do {
        if (uVar7 == 0) break;
        if (0 < (int)uVar7) {
          uVar26 = 0;
          do {
            if (uVar26 < *param_3) {
              if (uVar7 <= uVar26) {
                _memset((void *)(uVar7 * 4 + param_3[2]),0,(uVar26 - uVar7) * 4 + 4);
                param_3[1] = uVar26 + 1;
              }
              puVar11 = (undefined4 *)(uVar26 * 4 + param_3[2]);
            }
            else {
              puVar11 = (undefined4 *)FUN_0019423c(param_3,uVar26);
            }
            puVar11 = (undefined4 *)*puVar11;
            if (puVar11[5] == 0) {
              FUN_00194374(param_3,puVar11);
              uVar26 = uVar26 - 1;
              FUN_000ef970(param_1,*puVar11);
              *(int *)(param_1 + 0x230) = *(int *)(param_1 + 0x230) + 1;
              FUN_001054ec(*puVar11,0);
            }
            else if (puVar11[5] == iVar8) {
              FUN_00194374(param_3,puVar11);
              FUN_0010f38c(puVar11,param_3);
              ((int (*)())FUN_0010ff24)(puVar11,*(undefined4 *)(param_1 + 0x418));
              uVar7 = puVar6[2];
              if (uVar7 < *puVar30) {
                _memset((void *)(uVar7 * 4 + puVar6[3]),0,4);
                puVar12 = (undefined4 *)(uVar7 * 4 + puVar6[3]);
                puVar6[2] = uVar7 + 1;
              }
              else {
                puVar12 = (undefined4 *)FUN_0019423c(puVar30,uVar7);
              }
              *puVar12 = puVar11;
              uVar26 = uVar26 - 1;
            }
            uVar7 = param_3[1];
            uVar26 = uVar26 + 1;
          } while ((int)uVar26 < (int)uVar7);
        }
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    iVar8 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0xc4))();
    if (iVar8 == 0) {
      puVar30 = param_3;
    }
    uVar25 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
    puVar6 = (undefined4 *)FUN_00193e18(uVar25,0x14);
    puVar23 = puVar6 + 1;
    *puVar6 = uVar25;
    puVar6[1] = 2;
    puVar6[2] = 0;
    puVar6[4] = uVar25;
    uVar25 = FUN_00193e18(uVar25,8);
    puVar6[3] = uVar25;
    uVar25 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
    puVar11 = (undefined4 *)FUN_00193e18(uVar25,0x14);
    puVar29 = puVar11 + 1;
    *puVar11 = uVar25;
    puVar11[1] = 2;
    puVar11[2] = 0;
    puVar11[4] = uVar25;
    uVar25 = FUN_00193e18(uVar25,8);
    puVar11[3] = uVar25;
    iVar8 = 0;
    piVar24 = &DAT_001fc1f0;
    local_64 = &DAT_001b02ec;
    do {
      piVar24[2] = 4;
      iVar9 = *(int *)(local_64 + -0x8d8);
      *piVar24 = iVar8;
      piVar24[1] = iVar9;
      uVar25 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
      puVar12 = (undefined4 *)FUN_00193e18(uVar25,0x14);
      puVar12[1] = 2;
      *puVar12 = uVar25;
      puVar12[2] = 0;
      puVar12[4] = uVar25;
      uVar25 = FUN_00193e18(uVar25,8);
      bVar1 = iVar8 != 0xb;
      puVar12[3] = uVar25;
      iVar8 = iVar8 + 1;
      piVar24[3] = (int)(puVar12 + 1);
      piVar24 = piVar24 + 4;
    } while (bVar1);
    uVar7 = puVar30[1];
    if (0 < (int)uVar7) {
      uVar26 = 0;
      do {
        if (uVar26 < *puVar30) {
          if (uVar7 <= uVar26) {
            _memset((void *)(uVar7 * 4 + puVar30[2]),0,(uVar26 - uVar7) * 4 + 4);
            puVar30[1] = uVar26 + 1;
          }
          puVar12 = (undefined4 *)(uVar26 * 4 + puVar30[2]);
        }
        else {
          puVar12 = (undefined4 *)FUN_0019423c(puVar30,uVar26);
        }
        uVar26 = uVar26 + 1;
        piVar24 = (int *)*puVar12;
        iVar5 = 0;
        iVar9 = *piVar24;
        iVar8 = *(int *)(iVar9 + 0x94);
        puVar12 = &DAT_001fc1f4 + iVar8 * 4;
        while( true ) {
          iVar9 = FUN_001054ec(iVar9,0);
          if (*(char *)(iVar5 + iVar9 + 0x10) != '\x01') {
            *(undefined1 *)puVar12 = 0;
            (DAT_001fc1f8)[iVar8 * 4] = (DAT_001fc1f8)[iVar8 * 4] + -1;
          }
          bVar1 = iVar5 == 3;
          puVar12 = (undefined4 *)((int)puVar12 + 1);
          iVar5 = iVar5 + 1;
          if (bVar1) break;
          iVar9 = *piVar24;
        }
        puVar33 = (uint *)(DAT_001fc1fc)[iVar8 * 4];
        uVar7 = puVar33[1];
        if (uVar7 < *puVar33) {
          _memset((void *)(uVar7 * 4 + puVar33[2]),0,4);
          puVar12 = (undefined4 *)(uVar7 * 4 + puVar33[2]);
          puVar33[1] = uVar7 + 1;
        }
        else {
          puVar12 = (undefined4 *)FUN_0019423c(puVar33,uVar7);
        }
        *puVar12 = piVar24;
        uVar7 = puVar30[1];
      } while ((int)uVar26 < (int)uVar7);
    }
    iVar8 = 0;
    piVar24 = DAT_001fc1f8;
    do {
      if (*piVar24 == 0) {
        puVar30 = (uint *)piVar24[1];
        uVar7 = puVar30[1];
        if (0 < (int)uVar7) {
          uVar26 = 0;
          do {
            if (uVar26 < *puVar30) {
              if (uVar7 <= uVar26) {
                _memset((void *)(uVar7 * 4 + puVar30[2]),0,(uVar26 - uVar7) * 4 + 4);
                puVar30[1] = uVar26 + 1;
              }
              puVar12 = (undefined4 *)(uVar26 * 4 + puVar30[2]);
            }
            else {
              puVar12 = (undefined4 *)FUN_0019423c(puVar30,uVar26);
            }
            uVar26 = uVar26 + 1;
            uVar7 = puVar6[2];
            if (uVar7 < *puVar23) {
              _memset((void *)(uVar7 * 4 + puVar6[3]),0,4);
              puVar17 = (undefined4 *)(uVar7 * 4 + puVar6[3]);
              puVar6[2] = uVar7 + 1;
            }
            else {
              puVar17 = (undefined4 *)FUN_0019423c(puVar23,uVar7);
            }
            *puVar17 = *puVar12;
            puVar30 = (uint *)piVar24[1];
            uVar7 = puVar30[1];
          } while ((int)uVar26 < (int)uVar7);
        }
      }
      else if (*piVar24 < 4) {
        uVar7 = puVar11[2];
        if (uVar7 < *puVar29) {
          _memset((void *)(uVar7 * 4 + puVar11[3]),0,4);
          puVar12 = (undefined4 *)(uVar7 * 4 + puVar11[3]);
          puVar11[2] = uVar7 + 1;
        }
        else {
          puVar12 = (undefined4 *)FUN_0019423c(puVar29,uVar7);
        }
        *puVar12 = &DAT_001fc1f0 + iVar8 * 4;
      }
      bVar1 = iVar8 != 0xb;
      piVar24 = piVar24 + 4;
      iVar8 = iVar8 + 1;
    } while (bVar1);
    local_54 = local_84;
    uVar7 = puVar11[2];
    iVar8 = 1;
    local_58 = &DAT_001b02ec;
    do {
      if (0 < (int)uVar7) {
        local_5c = local_94;
        uVar26 = 0;
        do {
          if (uVar26 < *puVar29) {
            if (uVar7 <= uVar26) {
              _memset((void *)(uVar7 * 4 + puVar11[3]),0,(uVar26 - uVar7) * 4 + 4);
              uVar7 = uVar26 + 1;
              puVar11[2] = uVar7;
            }
            puVar12 = (undefined4 *)(uVar26 * 4 + puVar11[3]);
          }
          else {
            puVar12 = (undefined4 *)FUN_0019423c(puVar29,uVar26);
            uVar7 = puVar11[2];
          }
          piVar24 = (int *)*puVar12;
          iVar9 = *piVar24;
          if ((iVar8 == piVar24[2]) && (uVar31 = 0, 0 < (int)uVar7)) {
LAB_00111270:
            if (uVar31 < *puVar29) {
              if (uVar7 <= uVar31) {
                _memset((void *)(uVar7 * 4 + puVar11[3]),0,(uVar31 - uVar7) * 4 + 4);
                puVar11[2] = uVar31 + 1;
              }
              puVar12 = (undefined4 *)(uVar31 * 4 + puVar11[3]);
            }
            else {
              puVar12 = (undefined4 *)FUN_0019423c(puVar29,uVar31);
            }
            piVar22 = (int *)*puVar12;
            iVar5 = *piVar22;
            if ((iVar5 == iVar9) || (iVar8 < 4 - piVar22[2])) goto LAB_001116e0;
            FUN_00194374(puVar29,piVar22);
            puVar30 = (uint *)piVar22[3];
            uVar7 = puVar30[1];
            if (0 < (int)uVar7) {
              uVar31 = 0;
              do {
                if (uVar31 < *puVar30) {
                  local_60 = uVar31 + 1;
                  if (uVar7 <= uVar31) {
                    _memset((void *)(uVar7 * 4 + puVar30[2]),0,(uVar31 - uVar7) * 4 + 4);
                    puVar30[1] = local_60;
                  }
                  piVar10 = (int *)(uVar31 * 4 + puVar30[2]);
                }
                else {
                  piVar10 = (int *)FUN_0019423c(puVar30,uVar31);
                  local_60 = uVar31 + 1;
                }
                iVar21 = 4;
                piVar10 = (int *)*piVar10;
                local_98 = *(undefined4 *)(local_64 + -0x8d8);
                local_94[0] = *(int *)(local_58 + -0x8dc);
                iVar14 = 0;
                iVar15 = *piVar10;
                piVar18 = piVar10;
                do {
                  *(undefined4 *)(local_54 + iVar14) = 0;
                  iVar14 = iVar14 + 4;
                  piVar18[7] = 0;
                  piVar18 = piVar18 + 1;
                  iVar21 = iVar21 + -1;
                } while (iVar21 != 0);
                iVar14 = 0;
                piVar18 = piVar24 + 1;
                do {
                  if (*(char *)piVar18 == '\x01') {
                    iVar21 = 0;
                    puVar20 = (undefined1 *)(iVar15 + 0x9c);
                    piVar13 = piVar10;
LAB_001113e0:
                    piVar13 = piVar13 + 1;
                    iVar16 = FUN_001054ec(iVar15,0);
                    if (*(char *)(iVar21 + iVar16 + 0x10) == '\x01') goto LAB_00111508;
                    iVar16 = FUN_001054ec(iVar15,1);
                    piVar4 = local_5c;
                    uVar3 = *(undefined1 *)(iVar21 + iVar16 + 0x10);
                    *(undefined1 *)((int)local_94 + iVar14 + -4) = 0;
                    *(undefined1 *)(iVar14 + (int)piVar4) = uVar3;
                    iVar16 = piVar24[2];
                    *(char *)piVar18 = '\0';
                    piVar24[2] = iVar16 + -1;
                    puVar30 = *(uint **)(param_1 + 0x418);
                    *(int *)(local_54 + iVar14 * 4) = *piVar13;
                    uVar7 = puVar30[1];
                    if (0 < (int)uVar7) {
                      uVar31 = 0;
                      do {
                        if (uVar31 < *puVar30) {
                          if (uVar7 <= uVar31) {
                            _memset((void *)(uVar7 * 4 + puVar30[2]),0,(uVar31 - uVar7) * 4 + 4);
                            puVar30[1] = uVar31 + 1;
                          }
                          piVar13 = (int *)(uVar31 * 4 + puVar30[2]);
                        }
                        else {
                          piVar13 = (int *)FUN_0019423c(puVar30,uVar31);
                        }
                        uVar31 = uVar31 + 1;
                        iVar16 = *piVar13;
                        if (((iStack0000001c == *(int *)(iVar16 + 0x1c)) &&
                            (iVar5 == *(int *)(iVar16 + 0x14))) &&
                           (iVar21 == *(int *)(iVar16 + 0x18))) {
                          *(int *)(iVar16 + 0x18) = iVar14;
                          *(int *)(iVar16 + 0x14) = iVar9;
                        }
                        puVar30 = *(uint **)(param_1 + 0x418);
                        uVar7 = puVar30[1];
                      } while ((int)uVar31 < (int)uVar7);
                    }
                    *puVar20 = 1;
                  }
LAB_0011151c:
                  bVar1 = iVar14 != 3;
                  piVar18 = (int *)((int)piVar18 + 1);
                  iVar14 = iVar14 + 1;
                } while (bVar1);
                iVar21 = 4;
                iVar14 = 0;
                piVar18 = piVar10;
                do {
                  iVar16 = *(int *)(local_54 + iVar14);
                  iVar14 = iVar14 + 4;
                  piVar18[7] = 1;
                  piVar18[1] = iVar16;
                  piVar18 = piVar18 + 1;
                  iVar21 = iVar21 + -1;
                } while (iVar21 != 0);
                iVar21 = FUN_001054ec(iVar15,0);
                iVar14 = local_94[0];
                *(int *)(iVar21 + 8) = iVar9;
                *(undefined4 *)(iVar15 + 0x9c) = local_98;
                iVar15 = FUN_001054ec(iVar15,1);
                *(int *)(iVar15 + 0x10) = iVar14;
                puVar30 = (uint *)piVar24[3];
                uVar7 = puVar30[1];
                if (uVar7 < *puVar30) {
                  _memset((void *)(uVar7 * 4 + puVar30[2]),0,4);
                  piVar18 = (int *)(uVar7 * 4 + puVar30[2]);
                  puVar30[1] = uVar7 + 1;
                }
                else {
                  piVar18 = (int *)FUN_0019423c(puVar30,uVar7);
                }
                *piVar18 = (int)piVar10;
                puVar30 = (uint *)piVar22[3];
                uVar7 = puVar30[1];
                uVar31 = local_60;
              } while ((int)local_60 < (int)uVar7);
            }
            if (piVar24[2] < 1) {
              puVar30 = (uint *)piVar24[3];
              uVar31 = 0;
              uVar7 = puVar30[1];
              if (0 < (int)uVar7) {
                do {
                  if (uVar31 < *puVar30) {
                    if (uVar7 <= uVar31) {
                      _memset((void *)(uVar7 * 4 + puVar30[2]),0,(uVar31 - uVar7) * 4 + 4);
                      puVar30[1] = uVar31 + 1;
                    }
                    puVar12 = (undefined4 *)(uVar31 * 4 + puVar30[2]);
                  }
                  else {
                    puVar12 = (undefined4 *)FUN_0019423c(puVar30,uVar31);
                  }
                  uVar31 = uVar31 + 1;
                  uVar7 = puVar6[2];
                  if (uVar7 < *puVar23) {
                    _memset((void *)(uVar7 * 4 + puVar6[3]),0,4);
                    puVar17 = (undefined4 *)(uVar7 * 4 + puVar6[3]);
                    puVar6[2] = uVar7 + 1;
                  }
                  else {
                    puVar17 = (undefined4 *)FUN_0019423c(puVar23,uVar7);
                  }
                  *puVar17 = *puVar12;
                  puVar30 = (uint *)piVar24[3];
                  uVar7 = puVar30[1];
                } while ((int)uVar31 < (int)uVar7);
              }
              FUN_00194374(puVar29,piVar24);
              uVar7 = puVar11[2];
            }
            else {
              uVar7 = puVar11[2];
              iVar8 = piVar24[2] + -1;
              uVar26 = 1;
            }
            goto LAB_001116f4;
          }
LAB_001116f0:
          uVar26 = uVar26 + 1;
LAB_001116f4: ;
        } while ((int)uVar26 < (int)uVar7);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < 4);
    uVar26 = 0;
    if (0 < (int)uVar7) {
      do {
        if (uVar26 < *puVar29) {
          if (uVar7 <= uVar26) {
            _memset((void *)(uVar7 * 4 + puVar11[3]),0,(uVar26 - uVar7) * 4 + 4);
            puVar11[2] = uVar26 + 1;
          }
          piVar24 = (int *)(uVar26 * 4 + puVar11[3]);
        }
        else {
          piVar24 = (int *)FUN_0019423c(puVar29,uVar26);
        }
        uVar26 = uVar26 + 1;
        iVar8 = *piVar24;
        puVar30 = *(uint **)(iVar8 + 0xc);
        uVar7 = puVar30[1];
        if (0 < (int)uVar7) {
          uVar31 = 0;
          do {
            if (uVar31 < *puVar30) {
              if (uVar7 <= uVar31) {
                _memset((void *)(uVar7 * 4 + puVar30[2]),0,(uVar31 - uVar7) * 4 + 4);
                puVar30[1] = uVar31 + 1;
              }
              piVar24 = (int *)(uVar31 * 4 + puVar30[2]);
            }
            else {
              piVar24 = (int *)FUN_0019423c(puVar30,uVar31);
            }
            uVar31 = uVar31 + 1;
            uVar7 = puVar6[2];
            iVar9 = *piVar24;
            if (uVar7 < *puVar23) {
              _memset((void *)(uVar7 * 4 + puVar6[3]),0,4);
              piVar24 = (int *)(uVar7 * 4 + puVar6[3]);
              puVar6[2] = uVar7 + 1;
            }
            else {
              piVar24 = (int *)FUN_0019423c(puVar23,uVar7);
            }
            *piVar24 = iVar9;
            iVar14 = 4;
            iVar5 = iVar8;
            do {
              if (*(char *)(iVar5 + 4) == '\0') {
                *(undefined4 *)(iVar9 + 0x1c) = 1;
              }
              iVar5 = iVar5 + 1;
              iVar9 = iVar9 + 4;
              iVar14 = iVar14 + -1;
            } while (iVar14 != 0);
            puVar30 = *(uint **)(iVar8 + 0xc);
            uVar7 = puVar30[1];
          } while ((int)uVar31 < (int)uVar7);
        }
        uVar7 = puVar11[2];
      } while ((int)uVar26 < (int)uVar7);
    }
    uVar7 = puVar6[2];
    if (0 < (int)uVar7) {
      uVar26 = 0;
      do {
        if (uVar26 < *puVar23) {
          if (uVar7 <= uVar26) {
            _memset((void *)(uVar7 * 4 + puVar6[3]),0,(uVar26 - uVar7) * 4 + 4);
            puVar6[2] = uVar26 + 1;
          }
          puVar11 = (undefined4 *)(uVar26 * 4 + puVar6[3]);
        }
        else {
          puVar11 = (undefined4 *)FUN_0019423c(puVar23,uVar26);
        }
        uVar26 = uVar26 + 1;
        puVar11 = (undefined4 *)*puVar11;
        iVar8 = 0;
        do {
          FUN_00104104(*puVar11,iVar8,0,0);
          bVar1 = iVar8 != 3;
          iVar8 = iVar8 + 1;
        } while (bVar1);
        uVar7 = puVar6[2];
      } while ((int)uVar26 < (int)uVar7);
    }
    iVar8 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0xc4))();
    if (iVar8 == 0) {
      uVar7 = puVar6[2];
      puVar30 = (uint *)0x0;
    }
    else {
      uVar25 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
      puVar11 = (undefined4 *)FUN_00193e18(uVar25,0x14);
      puVar30 = puVar11 + 1;
      *puVar11 = uVar25;
      puVar11[1] = 2;
      puVar11[2] = 0;
      puVar11[4] = uVar25;
      uVar25 = FUN_00193e18(uVar25,8);
      puVar11[3] = uVar25;
      iVar8 = ((int (*)())FUN_0010f704)(iStack0000001c,*(undefined4 *)(param_1 + 0x418),
                           *(undefined4 *)(param_1 + 8));
      if (local_68 < iVar8) {
        uVar7 = puVar6[2];
        do {
          iVar9 = 1;
          piVar24 = (int *)0x0;
          do {
            uVar26 = 0;
            if (0 < (int)uVar7) {
              do {
                if (uVar26 < *puVar23) {
                  if (uVar7 <= uVar26) {
                    _memset((void *)(uVar7 * 4 + puVar6[3]),0,(uVar26 - uVar7) * 4 + 4);
                    puVar6[2] = uVar26 + 1;
                  }
                  puVar12 = (undefined4 *)(uVar26 * 4 + puVar6[3]);
                }
                else {
                  puVar12 = (undefined4 *)FUN_0019423c(puVar23,uVar26);
                }
                piVar24 = (int *)*puVar12;
                if (piVar24[5] == iVar9) {
                  FUN_00194374(puVar23,piVar24);
                  FUN_000ef970(param_1,*piVar24);
                  *(int *)(param_1 + 0x230) = *(int *)(param_1 + 0x230) + 1;
                  uVar7 = puVar6[2];
                  goto code_r0x00111aa4;
                }
                uVar7 = puVar6[2];
                uVar26 = uVar26 + 1;
              } while ((int)uVar26 < (int)uVar7);
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < 5);
code_r0x00111aa4:
          iVar9 = 3;
          do {
            if (0 < (int)uVar7) {
              uVar26 = 0;
              do {
                if (uVar26 < *puVar23) {
                  if (uVar7 <= uVar26) {
                    _memset((void *)(uVar7 * 4 + puVar6[3]),0,(uVar26 - uVar7) * 4 + 4);
                    puVar6[2] = uVar26 + 1;
                  }
                  puVar12 = (undefined4 *)(uVar26 * 4 + puVar6[3]);
                }
                else {
                  puVar12 = (undefined4 *)FUN_0019423c(puVar23,uVar26);
                }
                piVar22 = (int *)*puVar12;
                iVar5 = FUN_0010e95c(piVar22);
                if (iVar9 == iVar5) {
                  iVar5 = 0;
                  puVar12 = (undefined4 *)PTR_DAT_001e8b64;
                  piVar10 = piVar22;
                  do {
                    iVar14 = FUN_0010e9d0(piVar22,iVar5);
                    if (iVar14 != 0) {
                      iVar14 = 0;
                      do {
                        iVar15 = FUN_001054ec(*piVar24,0);
                        if (*(char *)(iVar14 + iVar15 + 0x10) != '\x01') {
                          iVar21 = piVar24[iVar14 + 1];
                          *(undefined1 *)(iVar14 + *piVar24 + 0x9c) = 1;
                          iVar15 = piVar24[5];
                          piVar24[iVar14 + 1] = 0;
                          piVar24[5] = iVar15 + -1;
                          goto code_r0x00111b80;
                        }
                        bVar1 = iVar14 != 3;
                        iVar14 = iVar14 + 1;
                      } while (bVar1);
                      iVar14 = -1;
                      iVar21 = 0;
code_r0x00111b80:
                      iVar19 = *(int *)(*piVar24 + 0x94);
                      iVar15 = FUN_0010445c(*piVar24,*(undefined4 *)(param_1 + 8),0);
                      uVar27 = *(undefined4 *)(*piVar22 + 0x94);
                      iVar16 = FUN_001054ec(iVar15,0);
                      uVar25 = *puVar12;
                      *(undefined4 *)(iVar16 + 8) = uVar27;
                      *(undefined4 *)(iVar15 + 0x9c) = uVar25;
                      iVar16 = FUN_001054ec(*piVar24,1);
                      uVar25 = *(undefined4 *)
                                (PTR_DAT_001e8b8c + (uint)*(byte *)(iVar14 + iVar16 + 0x10) * 4);
                      iVar16 = FUN_001054ec(iVar15,1);
                      *(undefined4 *)(iVar16 + 0x10) = uVar25;
                      FUN_000ee9ac(param_1,iVar15);
                      *(int *)(param_1 + 0x230) = *(int *)(param_1 + 0x230) + -1;
                      uVar25 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
                      puVar17 = (undefined4 *)FUN_00193e18(uVar25,0x30);
                      puVar28 = puVar17 + 1;
                      *puVar17 = uVar25;
                      FUN_0010e814(puVar28,iVar15);
                      puVar17[6] = 1;
                      puVar28[iVar5 + 1] = iVar21;
                      uVar7 = puVar11[2];
                      if (uVar7 < *puVar30) {
                        _memset((void *)(uVar7 * 4 + puVar11[3]),0,4);
                        piVar18 = (int *)(uVar7 * 4 + puVar11[3]);
                        puVar11[2] = uVar7 + 1;
                      }
                      else {
                        piVar18 = (int *)FUN_0019423c(puVar30,uVar7);
                      }
                      *piVar18 = (int)puVar28;
                      uVar25 = *(undefined4 *)(iVar15 + 0x94);
                      piVar10[7] = 1;
                      puVar29 = *(uint **)(param_1 + 0x418);
                      uVar7 = puVar29[1];
                      if (uVar7 != 0) {
                        uVar31 = 0;
                        do {
                          if (uVar31 < *puVar29) {
                            if (uVar7 <= uVar31) {
                              _memset((void *)(uVar7 * 4 + puVar29[2]),0,(uVar31 - uVar7) * 4 + 4);
                              puVar29[1] = uVar31 + 1;
                            }
                            piVar18 = (int *)(uVar31 * 4 + puVar29[2]);
                          }
                          else {
                            piVar18 = (int *)FUN_0019423c(puVar29,uVar31);
                          }
                          uVar31 = uVar31 + 1;
                          iVar15 = *piVar18;
                          if (((iStack0000001c == *(int *)(iVar15 + 0x1c)) &&
                              (iVar19 == *(int *)(iVar15 + 0x14))) &&
                             (iVar14 == *(int *)(iVar15 + 0x18))) {
                            *(int *)(iVar15 + 0x18) = iVar5;
                            *(undefined4 *)(iVar15 + 0x14) = uVar25;
                          }
                          puVar29 = *(uint **)(param_1 + 0x418);
                          uVar7 = puVar29[1];
                        } while (uVar31 < uVar7);
                      }
                      if (piVar24[5] == 0) {
                        iVar9 = 0;
                        break;
                      }
                    }
                    bVar1 = iVar5 != 3;
                    piVar10 = piVar10 + 1;
                    puVar12 = puVar12 + 1;
                    iVar5 = iVar5 + 1;
                  } while (bVar1);
                }
                uVar7 = puVar6[2];
                uVar26 = uVar26 + 1;
              } while ((int)uVar26 < (int)uVar7);
            }
            iVar9 = iVar9 + -1;
          } while (0 < iVar9);
          iVar8 = iVar8 + -1;
        } while (local_68 < iVar8);
      }
      else {
        uVar7 = puVar6[2];
      }
    }
    uVar25 = *(undefined4 *)(param_1 + 0x3a8);
    if (uVar7 != 0) {
      uVar26 = 0;
      do {
        if (uVar26 < *puVar23) {
          if (uVar7 <= uVar26) {
            _memset((void *)(uVar7 * 4 + puVar6[3]),0,(uVar26 - uVar7) * 4 + 4);
            puVar6[2] = uVar26 + 1;
          }
          puVar11 = (undefined4 *)(uVar26 * 4 + puVar6[3]);
        }
        else {
          puVar11 = (undefined4 *)FUN_0019423c(puVar23,uVar26);
        }
        uVar26 = uVar26 + 1;
        FUN_000e7688(uVar25,*(undefined4 *)*puVar11);
        uVar7 = puVar6[2];
      } while (uVar26 < uVar7);
    }
    iVar8 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0xc4))();
    if (iVar8 != 0) {
      uVar26 = puVar30[1];
      uVar7 = 0;
      if (uVar26 != 0) {
        do {
          if (uVar7 < *puVar30) {
            if (uVar26 <= uVar7) {
              _memset((void *)(uVar26 * 4 + puVar30[2]),0,(uVar7 - uVar26) * 4 + 4);
              puVar30[1] = uVar7 + 1;
            }
            puVar11 = (undefined4 *)(uVar7 * 4 + puVar30[2]);
          }
          else {
            puVar11 = (undefined4 *)FUN_0019423c(puVar30,uVar7);
          }
          uVar7 = uVar7 + 1;
          FUN_000e7688(uVar25,*(undefined4 *)*puVar11);
          uVar26 = puVar30[1];
        } while (uVar7 < uVar26);
      }
    }
    uVar7 = param_3[1];
    while (uVar7 != 0) {
      FUN_00194208(param_3,0);
      uVar7 = param_3[1];
    }
    uVar7 = puVar6[2];
    if (uVar7 != 0) {
      uVar26 = 0;
      do {
        if (uVar26 < *puVar23) {
          if (uVar7 <= uVar26) {
            _memset((void *)(uVar7 * 4 + puVar6[3]),0,(uVar26 - uVar7) * 4 + 4);
            puVar6[2] = uVar26 + 1;
          }
          puVar11 = (undefined4 *)(uVar26 * 4 + puVar6[3]);
        }
        else {
          puVar11 = (undefined4 *)FUN_0019423c(puVar23,uVar26);
        }
        uVar26 = uVar26 + 1;
        uVar7 = param_3[1];
        if (uVar7 < *param_3) {
          _memset((void *)(uVar7 * 4 + param_3[2]),0,4);
          puVar12 = (undefined4 *)(uVar7 * 4 + param_3[2]);
          param_3[1] = uVar7 + 1;
        }
        else {
          puVar12 = (undefined4 *)FUN_0019423c(param_3,uVar7);
        }
        *puVar12 = *puVar11;
        uVar7 = puVar6[2];
      } while (uVar26 < uVar7);
    }
    iVar8 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0xc4))();
    if (iVar8 != 0) {
      uVar26 = puVar30[1];
      uVar7 = 0;
      if (uVar26 != 0) {
        do {
          if (uVar7 < *puVar30) {
            if (uVar26 <= uVar7) {
              _memset((void *)(uVar26 * 4 + puVar30[2]),0,(uVar7 - uVar26) * 4 + 4);
              puVar30[1] = uVar7 + 1;
            }
            puVar6 = (undefined4 *)(uVar7 * 4 + puVar30[2]);
          }
          else {
            puVar6 = (undefined4 *)FUN_0019423c(puVar30,uVar7);
          }
          uVar7 = uVar7 + 1;
          uVar26 = param_3[1];
          if (uVar26 < *param_3) {
            _memset((void *)(uVar26 * 4 + param_3[2]),0,4);
            puVar11 = (undefined4 *)(uVar26 * 4 + param_3[2]);
            param_3[1] = uVar26 + 1;
          }
          else {
            puVar11 = (undefined4 *)FUN_0019423c(param_3,uVar26);
          }
          *puVar11 = *puVar6;
          uVar26 = puVar30[1];
        } while (uVar7 < uVar26);
      }
    }
  }
  return;
LAB_001116e0:
  uVar7 = puVar11[2];
  uVar31 = uVar31 + 1;
  if ((int)uVar7 <= (int)uVar31) goto LAB_001116f0;
  goto LAB_00111270;
LAB_00111508:
  bVar1 = iVar21 == 3;
  puVar20 = puVar20 + 1;
  iVar21 = iVar21 + 1;
  if (bVar1) goto LAB_0011151c;
  goto LAB_001113e0;
}

/* FUN_001121b4 @ 0x1121b4 (156 bytes) */
int FUN_001121b4(param_1)
  int param_1;
{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  uint uVar14;
  undefined1 *puVar15;
  int iVar16;
  int *piVar17;
  uint *puVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  uint uVar23;
  int *piVar24;
  int iVar25;
  int iVar26;
  undefined1 local_98 [4];
  int local_94;
  undefined4 local_90 [4];
  undefined4 local_80 [4];
  int local_70 [6];
  undefined1 *local_58;
  
  piVar17 = *(int **)(param_1 + 0x3a4);
  if (piVar17 == (int *)0x0) {
    piVar17 = *(int **)(param_1 + 0x3a0);
  }
  iVar26 = *(int *)(*(int *)(param_1 + 8) + 0x378);
  piVar4 = (int *)FUN_00193e18(iVar26,0x14);
  puVar18 = (uint *)(piVar4 + 1);
  piVar4[1] = 2;
  *piVar4 = iVar26;
  piVar4[2] = 0;
  piVar4[4] = iVar26;
  iVar26 = FUN_00193e18(iVar26,8);
  piVar4[3] = iVar26;
  uVar14 = 0;
  piVar6 = (int *)piVar17[0x26];
  piVar24 = (int *)((int *)piVar17[0x26])[2];
  do {
    if (piVar24 == (int *)0x0) {
      FUN_001940f0(puVar18,FUN_0010e4ec);
      if (0 < (int)uVar14) {
        uVar23 = 0;
        do {
          if (uVar23 < *puVar18) {
            uVar5 = piVar4[2];
            if (uVar5 <= uVar23) {
              _memset((void *)(uVar5 * 4 + piVar4[3]),0,(uVar23 - uVar5) * 4 + 4);
              piVar4[2] = uVar23 + 1;
            }
            piVar6 = (int *)(uVar23 * 4 + piVar4[3]);
          }
          else {
            piVar6 = (int *)FUN_0019423c(puVar18,uVar23);
          }
          uVar5 = uVar23 + 1;
          iVar26 = *piVar6;
          if (iVar26 != 0) {
            iVar19 = 0;
            iVar22 = 0;
            do {
              iVar7 = FUN_001054ec(iVar26,0);
              if (*(char *)(iVar22 + iVar7 + 0x10) != '\x01') {
                uVar8 = FUN_00104b6c(iVar26,iVar22);
                local_90[iVar19] = uVar8;
                uVar8 = FUN_0010426c(iVar26,iVar22);
                local_98[iVar19] = (char)iVar22;
                local_80[iVar19] = uVar8;
                iVar19 = iVar19 + 1;
              }
              bVar1 = iVar22 != 3;
              iVar22 = iVar22 + 1;
            } while (bVar1);
            iVar22 = *(int *)(iVar26 + 0x140);
            iVar20 = *(int *)(iVar26 + 0x144);
            uVar8 = *(undefined4 *)(iVar26 + 0x148);
            iVar7 = *(int *)(iVar26 + 0x13c);
            local_70[0] = iVar26;
            if ((int)uVar5 < (int)uVar14) {
              local_58 = local_98;
              iVar21 = uVar23 + 2;
              iVar26 = uVar5 * 4;
              iVar16 = 1;
              uVar23 = uVar5;
              do {
                if (uVar23 < *puVar18) {
                  uVar9 = piVar4[2];
                  if (uVar9 <= uVar23) {
                    _memset((void *)(uVar9 * 4 + piVar4[3]),0,(uVar23 - uVar9) * 4 + 4);
                    piVar4[2] = iVar21;
                  }
                  piVar6 = (int *)(iVar26 + piVar4[3]);
                }
                else {
                  piVar6 = (int *)FUN_0019423c(puVar18,uVar23);
                }
                iVar25 = *piVar6;
                if (((iVar25 != 0) && (iVar10 = FUN_000f3a30(iVar25), iVar19 + iVar10 < 5)) &&
                   ((*(int *)(iVar25 + 0x144) == iVar20 &&
                    ((iVar7 == *(int *)(iVar25 + 0x13c) && (iVar22 == *(int *)(iVar25 + 0x140)))))))
                {
                  iVar10 = 0;
                  puVar15 = local_58 + iVar19 * 4;
                  do {
                    iVar11 = FUN_001054ec(iVar25,0);
                    if (*(char *)(iVar10 + iVar11 + 0x10) != '\x01') {
                      uVar12 = FUN_00104b6c(iVar25,iVar10);
                      *(undefined4 *)(puVar15 + 8) = uVar12;
                      uVar12 = FUN_0010426c(iVar25,iVar10);
                      *(undefined4 *)(puVar15 + 0x18) = uVar12;
                      puVar15 = puVar15 + 4;
                      local_58[iVar19] = (char)iVar10;
                      iVar19 = iVar19 + 1;
                    }
                    bVar1 = iVar10 != 3;
                    iVar10 = iVar10 + 1;
                  } while (bVar1);
                  iVar10 = iVar16 * 4;
                  iVar16 = iVar16 + 1;
                  *(int *)(local_58 + iVar10 + 0x28) = iVar25;
                  if (uVar23 < *puVar18) {
                    uVar9 = piVar4[2];
                    if (uVar9 <= uVar23) {
                      _memset((void *)(uVar9 * 4 + piVar4[3]),0,(uVar23 - uVar9) * 4 + 4);
                      piVar4[2] = iVar21;
                    }
                    puVar13 = (undefined4 *)(iVar26 + piVar4[3]);
                  }
                  else {
                    puVar13 = (undefined4 *)FUN_0019423c(puVar18,uVar23);
                  }
                  *puVar13 = 0;
                  if (iVar19 == 4) break;
                }
                uVar23 = uVar23 + 1;
                iVar21 = iVar21 + 1;
                iVar26 = iVar26 + 4;
              } while (uVar14 != uVar23);
              if (1 < iVar16) {
                uVar12 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
                puVar13 = (undefined4 *)FUN_00193e18(uVar12,0x168);
                *puVar13 = uVar12;
                piVar6 = puVar13 + 1;
                FUN_00109198(piVar6,*(undefined4 *)(param_1 + 8));
                puVar13[0x51] = iVar22;
                puVar13[0x50] = iVar7;
                puVar13[0x26] = uVar8;
                puVar13[0x27] = iVar20;
                puVar13[0x52] = iVar20;
                puVar13[0x53] = uVar8;
                if (0 < iVar19) {
                  iVar22 = 0;
                  piVar24 = piVar6;
                  iVar26 = 0;
                  do {
                    *(undefined1 *)(piVar24 + 0x27) = 0;
                    piVar24 = (int *)((int)piVar24 + 1);
                    (**(code **)(*piVar6 + 0x88))(piVar6,1,iVar26,local_98[iVar26]);
                    puVar2 = (undefined4 *)((int)local_90 + iVar22);
                    puVar3 = (undefined4 *)((int)local_80 + iVar22);
                    iVar7 = iVar26 + 1;
                    iVar22 = iVar22 + 4;
                    FUN_001041d0(piVar6,iVar26,3,*puVar2,*puVar3);
                    iVar26 = iVar7;
                  } while (iVar19 != iVar7);
                }
                iVar26 = 0;
                iVar19 = 0;
                puVar13[0x59] = iVar16 + *(int *)(param_1 + 0x478);
                (**(code **)(*piVar17 + 0xc))(piVar17,piVar6);
                do {
                  piVar24 = (int *)local_70[iVar19];
                  iVar22 = FUN_001054ec(piVar24,0);
                  local_94 = *(int *)(iVar22 + 0x10);
                  iVar22 = piVar24[0x58] - *(int *)(param_1 + 0x478);
                  if (iVar22 < 0) {
                    iVar22 = 0;
                  }
                  FUN_0019401c(piVar24);
                  FUN_00108448(piVar24,0x31,*(undefined4 *)(param_1 + 8));
                  piVar24[0x26] = 0;
                  iVar7 = 0;
                  piVar24[0x25] = piVar24[0x53];
                  piVar24[0x27] = local_94;
                  piVar24[0x58] = iVar22 + *(int *)(param_1 + 0x478);
                  iVar22 = iVar26;
                  do {
                    if (*(char *)((int)local_90 + iVar7 + -4) == '\x01') {
                      (**(code **)(*piVar24 + 0x88))(piVar24,1,iVar7,4);
                      iVar26 = iVar22;
                    }
                    else {
                      iVar26 = iVar22 + 1;
                      (**(code **)(*piVar24 + 0x88))(piVar24,1,iVar7,iVar22);
                    }
                    bVar1 = iVar7 != 3;
                    iVar7 = iVar7 + 1;
                    iVar22 = iVar26;
                  } while (bVar1);
                  iVar19 = iVar19 + 1;
                  FUN_00106004(piVar24,1,piVar6,0,*(undefined4 *)(param_1 + 8));
                  FUN_000e7688(piVar17,piVar24);
                } while (iVar16 != iVar19);
              }
            }
          }
          uVar23 = uVar5;
        } while ((int)uVar5 < (int)uVar14);
      }
      if (puVar18 != (uint *)0x0) {
        FUN_00193cc0(piVar4[4],piVar4[3]);
        iVar26 = *piVar4;
        if ((*(int *)(iVar26 + 0x28) != 0) &&
           (piVar17 = *(int **)(iVar26 + 0x14), piVar17 == piVar4)) {
          _memset(piVar17,0,*(int *)(iVar26 + 8) - (int)piVar17);
          *(undefined4 *)(iVar26 + 8) = *(undefined4 *)(iVar26 + 0x14);
        }
        return;
      }
      return;
    }
    if ((piVar6[5] & 1U) != 0) {
      iVar26 = (**(code **)(*piVar6 + 0x4c))(piVar6);
      if (iVar26 != 0) {
        iVar19 = (**(code **)(*piVar6 + 0x80))(piVar6);
        iVar26 = *(int *)(iVar19 + 0x144);
        if (((((*(int *)(param_1 + 0x3e4) == 0) || (iVar26 != *(int *)(param_1 + 0x3f4))) ||
             (*(int *)(iVar19 + 0x148) < *(int *)(param_1 + 1000))) ||
            (*(int *)(param_1 + 0x3ec) <= *(int *)(iVar19 + 0x148))) &&
           (((iVar26 == 0x24 || (iVar26 == 0x15)) &&
            ((iVar26 = FUN_000f3a30(iVar19), iVar26 != 4 &&
             (iVar26 = FUN_000f3a30(iVar19), iVar26 != 0)))))) {
          uVar23 = piVar4[2];
          uVar14 = uVar14 + 1;
          if (uVar23 < *puVar18) {
            _memset((void *)(uVar23 * 4 + piVar4[3]),0,4);
            piVar24 = (int *)(uVar23 * 4 + piVar4[3]);
            piVar4[2] = uVar23 + 1;
          }
          else {
            piVar24 = (int *)FUN_0019423c(puVar18,uVar23);
          }
          *piVar24 = iVar19;
          piVar24 = (int *)piVar6[2];
          goto LAB_00112378;
        }
      }
      piVar24 = (int *)piVar6[2];
    }
LAB_00112378:
    piVar6 = piVar24;
    piVar24 = (int *)piVar24[2];
  } while( true );
}

/* FUN_001128a0 @ 0x1128a0 (1640 bytes) */
int FUN_001128a0(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  undefined4 uVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  code *pcVar14;
  int *piVar15;
  uint *puVar16;
  int *piVar17;
  int iVar18;
  int local_58;
  undefined1 auStack_54 [4];
  undefined4 auStack_50 [10];
  
  piVar15 = *(int **)(*(int *)(param_2 + 0x3a8) + 0x98);
  piVar7 = (int *)piVar15[2];
  if (piVar7 == (int *)0x0) {
    piVar17 = (int *)0x0;
    piVar11 = (int *)0x0;
  }
  else {
    piVar17 = (int *)0x0;
    piVar11 = (int *)0x0;
    do {
      piVar8 = piVar7;
      if ((piVar15[5] & 1U) != 0) {
        iVar1 = (**(code **)(*piVar15 + 0x68))(piVar15);
        if (iVar1 == 0) {
LAB_0011293c:
          piVar8 = (int *)piVar15[2];
        }
        else if (piVar15[0x4f] == 6) {
          piVar8 = (int *)piVar15[2];
          piVar17 = piVar15;
        }
        else {
          if (piVar15[0x4f] != 7) goto LAB_0011293c;
          piVar8 = (int *)piVar15[2];
          piVar11 = piVar15;
        }
      }
      piVar7 = (int *)piVar8[2];
      piVar15 = piVar8;
    } while ((int *)piVar8[2] != (int *)0x0);
  }
  local_58 = 0;
  uVar10 = *(undefined4 *)(param_2 + 8);
  if (piVar17 != (int *)0x0) {
    piVar17[0x25] = 0;
    piVar17[0x26] = 5;
    local_58 = 1;
    pcVar14 = *(code **)(*param_1 + 0x54);
    uVar2 = FUN_00104180(piVar17,0);
    uVar4 = DAT_001afa0c;
    FUN_00104180(piVar17,0);
    (*pcVar14)(param_1,0,0,uVar2,uVar4,0,0,0);
  }
  if (piVar11 != (int *)0x0) {
    piVar11[0x25] = 1;
    piVar11[0x26] = 5;
    local_58 = local_58 + 1;
    pcVar14 = *(code **)(*param_1 + 0x54);
    uVar2 = FUN_00104180(piVar11,0);
    uVar4 = DAT_001afa0c;
    FUN_00104180(piVar11,0);
    (*pcVar14)(param_1,1,1,uVar2,uVar4,0,0,0);
  }
  iVar1 = FUN_0010f4d4(param_2);
  *(int *)(param_2 + 0x3e4) = iVar1;
  if (iVar1 == 0) {
    FUN_001940f0(*(undefined4 *)(param_2 + 0x420),FUN_0010e870);
    puVar16 = *(uint **)(param_2 + 0x420);
    uVar13 = puVar16[1];
    if (uVar13 != 0) {
      uVar5 = 0;
      uVar12 = 1;
      iVar1 = 0;
      do {
        uVar9 = *puVar16;
        if (uVar5 < uVar9) {
          if (uVar13 <= uVar5) {
            _memset((void *)(uVar13 * 4 + puVar16[2]),0,(uVar5 - uVar13) * 4 + 4);
            uVar9 = *puVar16;
            puVar16[1] = uVar12;
          }
          puVar3 = (undefined4 *)(iVar1 + puVar16[2]);
        }
        else {
          puVar3 = (undefined4 *)FUN_0019423c(puVar16,uVar5);
          uVar9 = *puVar16;
        }
        uVar4 = *(undefined4 *)(*(int *)*puVar3 + 0x13c);
        if (uVar5 < uVar9) {
          uVar13 = puVar16[1];
          if (uVar13 <= uVar5) {
            _memset((void *)(uVar13 * 4 + puVar16[2]),0,(uVar5 - uVar13) * 4 + 4);
            puVar16[1] = uVar12;
          }
          puVar3 = (undefined4 *)(iVar1 + puVar16[2]);
        }
        else {
          puVar3 = (undefined4 *)FUN_0019423c(puVar16,uVar5);
        }
        iVar6 = FUN_0010e40c(uVar4,*(undefined4 *)(*(int *)*puVar3 + 0x140));
        if (iVar6 - 2U < 2) {
          iVar6 = FUN_000e07dc(uVar10,0x3f);
          iVar1 = local_58;
          if (iVar6 == 0) {
            puVar16 = *(uint **)(param_2 + 0x420);
            local_58 = local_58 + 4;
            uVar13 = puVar16[1];
            if (uVar13 != 0) {
              uVar12 = 0;
              do {
                if (uVar12 < *puVar16) {
                  if (uVar13 <= uVar12) {
                    _memset((void *)(uVar13 * 4 + puVar16[2]),0,(uVar12 - uVar13) * 4 + 4);
                    puVar16[1] = uVar12 + 1;
                  }
                  puVar3 = (undefined4 *)(uVar12 * 4 + puVar16[2]);
                }
                else {
                  puVar3 = (undefined4 *)FUN_0019423c(puVar16,uVar12);
                }
                uVar12 = uVar12 + 1;
                iVar18 = *(int *)*puVar3;
                iVar6 = FUN_0010e40c(*(undefined4 *)(iVar18 + 0x13c),*(undefined4 *)(iVar18 + 0x140)
                                    );
                if (iVar6 < 4) {
                  *(undefined4 *)(iVar18 + 0x98) = 5;
                  *(int *)(iVar18 + 0x94) = iVar1 + iVar6;
                }
                else {
                  *(int *)(iVar18 + 0x94) = local_58;
                  *(undefined4 *)(iVar18 + 0x98) = 5;
                  local_58 = local_58 + 1;
                }
                puVar16 = *(uint **)(param_2 + 0x420);
                uVar13 = puVar16[1];
              } while (uVar12 < uVar13);
            }
          }
          else {
            ((int (*)())FUN_0010fb54)(*(undefined4 *)(param_2 + 0x420),&local_58,param_2);
          }
          goto LAB_00112c28;
        }
        uVar13 = puVar16[1];
        uVar5 = uVar5 + 1;
        uVar12 = uVar12 + 1;
        iVar1 = iVar1 + 4;
      } while (uVar5 < uVar13);
      puVar16 = *(uint **)(param_2 + 0x420);
    }
    ((int (*)())FUN_0010fd98)(2,puVar16,&local_58,param_2);
LAB_00112c28:
    ((int (*)())FUN_0010fd98)(3,*(undefined4 *)(param_2 + 0x424),&local_58,param_2);
    FUN_001940f0(*(undefined4 *)(param_2 + 0x41c),FUN_0010e8c4);
    ((int (*)())FUN_0010fd98)(1,*(undefined4 *)(param_2 + 0x41c),&local_58,param_2);
  }
  else {
    *(int *)(param_2 + 0x3f0) = local_58 - *(int *)(param_2 + 1000);
    ((int (*)())FUN_0010fc88)(2,*(undefined4 *)(param_2 + 0x420),&local_58,param_2);
    ((int (*)())FUN_0010fc88)(3,*(undefined4 *)(param_2 + 0x424),&local_58,param_2);
    ((int (*)())FUN_0010fc88)(1,*(undefined4 *)(param_2 + 0x41c),&local_58,param_2);
  }
  *(int *)(param_2 + 0x234) = local_58 + 1;
  uVar13 = 0;
  uVar12 = 0;
LAB_00112ec4:
  puVar16 = *(uint **)(param_2 + 0x418);
  uVar5 = puVar16[1];
  if (uVar5 <= uVar12) {
    return;
  }
  if (uVar12 < *puVar16) {
    if (uVar5 <= uVar12) {
      _memset((void *)(uVar5 * 4 + puVar16[2]),0,(uVar12 - uVar5) * 4 + 4);
      puVar16[1] = uVar12 + 1;
    }
    piVar7 = (int *)(uVar12 * 4 + puVar16[2]);
  }
  else {
    piVar7 = (int *)FUN_0019423c(puVar16,uVar12);
  }
  uVar9 = uVar12 + 1;
  iVar1 = *piVar7;
  uVar5 = *(uint *)(iVar1 + 0x10);
  auStack_50[uVar5] = *(undefined4 *)(iVar1 + 0x14);
  auStack_54[*(int *)(iVar1 + 0x10)] = (char)*(undefined4 *)(iVar1 + 0x18);
  puVar16 = *(uint **)(param_2 + 0x418);
  uVar13 = uVar13 | 1 << (uVar5 & 0x3f);
  uVar5 = puVar16[1];
  if (uVar5 != uVar9) goto code_r0x00112df4;
  iVar6 = *(int *)(iVar1 + 4);
  goto LAB_00112e78;
code_r0x00112df4:
  if (uVar9 < *puVar16) {
    if (uVar5 <= uVar9) {
      _memset((void *)(uVar5 * 4 + puVar16[2]),0,(uVar9 - uVar5) * 4 + 4);
      puVar16[1] = uVar12 + 2;
    }
    piVar7 = (int *)(uVar9 * 4 + puVar16[2]);
  }
  else {
    piVar7 = (int *)FUN_0019423c(puVar16,uVar9);
  }
  iVar6 = *(int *)(iVar1 + 4);
  if ((iVar6 != *(int *)(*piVar7 + 4)) ||
     (uVar12 = uVar9, *(int *)(iVar1 + 8) != *(int *)(*piVar7 + 8))) {
LAB_00112e78:
    pcVar14 = *(code **)(*param_1 + 0x58);
    uVar10 = FUN_000ec2c4(param_2,iVar6);
    uVar4 = FUN_0010e530(*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 8));
    (*pcVar14)(param_1,auStack_50,auStack_54,uVar10,uVar4,uVar13);
    uVar13 = 0;
    uVar12 = uVar9;
  }
  goto LAB_00112ec4;
}

/* FUN_00112f08 @ 0x112f08 (76 bytes) */
int FUN_00112f08(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x16c))(*(int **)(param_2 + 0x30c));
  return iVar1 + param_1 * 0x38 + 0x10;
}

/* FUN_00112f54 @ 0x112f54 (36 bytes) */
int FUN_00112f54(param_1)
  int param_1;
{
  return *(undefined4 *)(&DAT_001fc2b0 + param_1 * 4);
}

/* FUN_00112f78 @ 0x112f78 (76 bytes) */
int FUN_00112f78(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x16c))(*(int **)(param_2 + 0x30c));
  return *(uint *)(param_1 * 0x38 + iVar1) & 1;
}

/* FUN_00112fc4 @ 0x112fc4 (16 bytes) */
int FUN_00112fc4(param_1)
  uint param_1;
{
  return param_1 < 8;
}

/* FUN_00112fd4 @ 0x112fd4 (16 bytes) */
int FUN_00112fd4(param_1)
  uint param_1;
{
  return param_1 < 7;
}

/* FUN_00112fe4 @ 0x112fe4 (172 bytes) */
int FUN_00112fe4(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  
  iVar2 = (**(code **)(**(int **)(param_1 + 0x30c) + 0x16c))();
  iVar3 = (**(code **)(**(int **)(param_1 + 0x30c) + 0x40))();
  if (iVar3 < 1) {
LAB_00113034:
    uVar4 = 1;
  }
  else {
    if (*(int *)(iVar2 + 8) == 0) {
      piVar5 = (int *)(iVar2 + 0x40);
      iVar2 = 0;
      do {
        iVar1 = iVar2 + 1;
        if (iVar3 == iVar1) goto LAB_00113034;
        iVar2 = *piVar5;
        piVar5 = piVar5 + 0xe;
      } while (iVar2 == iVar1);
    }
    uVar4 = 0;
  }
  return uVar4;
}

/* FUN_00113090 @ 0x113090 (76 bytes) */
int FUN_00113090(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x16c))(*(int **)(param_2 + 0x30c));
  return *(uint *)(param_1 * 0x38 + iVar1) >> 2 & 1;
}

/* FUN_001130dc @ 0x1130dc (76 bytes) */
int FUN_001130dc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x16c))(*(int **)(param_2 + 0x30c));
  return *(uint *)(param_1 * 0x38 + iVar1) >> 3 & 1;
}

/* FUN_00113128 @ 0x113128 (76 bytes) */
int FUN_00113128(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x16c))(*(int **)(param_2 + 0x30c));
  return *(uint *)(param_1 * 0x38 + iVar1) >> 6 & 1;
}

/* FUN_00113174 @ 0x113174 (76 bytes) */
int FUN_00113174(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x16c))(*(int **)(param_2 + 0x30c));
  return *(uint *)(param_1 * 0x38 + iVar1) >> 7 & 1;
}

/* FUN_001131c0 @ 0x1131c0 (76 bytes) */
int FUN_001131c0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x16c))(*(int **)(param_2 + 0x30c));
  return *(uint *)(param_1 * 0x38 + iVar1) >> 8 & 1;
}

/* FUN_0011320c @ 0x11320c (76 bytes) */
int FUN_0011320c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x16c))(*(int **)(param_2 + 0x30c));
  return *(uint *)(param_1 * 0x38 + iVar1) >> 9 & 1;
}

/* FUN_00113258 @ 0x113258 (76 bytes) */
int FUN_00113258(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x16c))(*(int **)(param_2 + 0x30c));
  return *(uint *)(param_1 * 0x38 + iVar1) >> 10 & 1;
}

/* FUN_001132a4 @ 0x1132a4 (76 bytes) */
int FUN_001132a4(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x16c))(*(int **)(param_2 + 0x30c));
  return *(uint *)(param_1 * 0x38 + iVar1) >> 0xc & 1;
}

/* FUN_001132f0 @ 0x1132f0 (76 bytes) */
int FUN_001132f0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x16c))(*(int **)(param_2 + 0x30c));
  return *(uint *)(param_1 * 0x38 + iVar1) >> 0xd & 1;
}

/* FUN_0011333c @ 0x11333c (76 bytes) */
int FUN_0011333c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x16c))(*(int **)(param_2 + 0x30c));
  return *(undefined4 *)(param_1 * 0x38 + iVar1 + 4);
}

/* FUN_00113388 @ 0x113388 (76 bytes) */
int FUN_00113388(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x16c))(*(int **)(param_2 + 0x30c));
  return *(undefined4 *)(param_1 * 0x38 + iVar1 + 0x30);
}

/* FUN_001133d4 @ 0x1133d4 (76 bytes) */
int FUN_001133d4(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x16c))(*(int **)(param_2 + 0x30c));
  return *(undefined4 *)(param_1 * 0x38 + iVar1 + 0xc);
}

/* FUN_00113420 @ 0x113420 (76 bytes) */
int FUN_00113420(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x16c))(*(int **)(param_2 + 0x30c));
  return *(undefined4 *)(param_1 * 0x38 + iVar1 + 0x34);
}

/* FUN_0011346c @ 0x11346c (80 bytes) */
int FUN_0011346c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x30c) + 0x16c))();
  return *(uint *)(iVar1 + *(int *)(*(int *)(param_2 + 0x88) + 8) * 0x38) >> 2 & 1;
}

/* FUN_001134bc @ 0x1134bc (152 bytes) */
int FUN_001134bc(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    iVar1 = ((int (*)())FUN_0011346c)(*(undefined4 *)(param_3 + 8),param_2);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = *(int *)(param_1 + 0xc);
  }
  if (iVar1 != 0x10) {
    return iVar1;
  }
  iVar1 = (**(code **)(*param_2 + 0x30))(param_2);
  if (iVar1 != 0) {
    return 9;
  }
  iVar1 = ((int (*)())FUN_0011346c)(*(undefined4 *)(param_3 + 8),param_2);
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}

/* FUN_00113554 @ 0x113554 (56 bytes) */
double FUN_00113554(double fparam_1,double fparam_2)
{
  double dVar1;
  
  dVar1 = (double)FLOAT_001aa0d4;
  if (fparam_1 == dVar1) {
    return dVar1;
  }
  if (fparam_2 == dVar1) {
    return dVar1;
  }
  return (double)(float)(fparam_1 * fparam_2);
}

/* FUN_0011358c @ 0x11358c (28 bytes) */
int FUN_0011358c(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 3;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_1 + 4) = 9;
  return;
}

/* FUN_001135a8 @ 0x1135a8 (24 bytes) */
int FUN_001135a8(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_1 + 4) = 6;
  return;
}

/* FUN_001135c0 @ 0x1135c0 (44 bytes) */
int FUN_001135c0(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 300) = 0;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 1;
  return;
}

/* FUN_001135ec @ 0x1135ec (80 bytes) */
int FUN_001135ec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18;
  FUN_000ee9ac(*(undefined4 *)(param_3 + 0x6c4),param_2);
  *(undefined4 *)(param_1 + 4) = 7;
  return;
}

/* FUN_0011363c @ 0x11363c (84 bytes) */
int FUN_0011363c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined4 *)(param_2 + 0x80) = 0;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18;
  *(undefined4 *)(param_2 + 0x84) = 1;
  FUN_000ee9ac(*(undefined4 *)(param_3 + 0x6c4),param_2);
  *(undefined4 *)(param_1 + 4) = 8;
  return;
}

/* FUN_00113690 @ 0x113690 (84 bytes) */
int FUN_00113690(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18018;
  FUN_000ee9ac(*(undefined4 *)(param_3 + 0x6c4),param_2);
  *(undefined4 *)(param_1 + 4) = 5;
  return;
}

/* FUN_001136e4 @ 0x1136e4 (40 bytes) */
int FUN_001136e4(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 3;
  return;
}

/* FUN_0011370c @ 0x11370c (40 bytes) */
int FUN_0011370c(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 0x80) = 0;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 2;
  return;
}

/* FUN_00113734 @ 0x113734 (104 bytes) */
int FUN_00113734(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (((*(int **)(param_1 + 0x30c))[2] & 0x10U) != 0) {
    iVar2 = (**(code **)(**(int **)(param_1 + 0x30c) + 0x16c))();
    uVar1 = *(uint *)(iVar2 + *(int *)(*(int *)(param_2 + 0x88) + 8) * 0x38) >> 2 & 1;
  }
  return uVar1;
}

/* FUN_0011379c @ 0x11379c (124 bytes) */
int FUN_0011379c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x30c) + 0x16c))();
  iVar4 = *(int *)(*(int *)(param_2 + 0x88) + 8);
  iVar2 = ((int (*)())FUN_00113174)(iVar4,param_1);
  if ((iVar2 != 0) || (uVar3 = 1, (*(uint *)(iVar1 + iVar4 * 0x38) & 2) == 0)) {
    uVar3 = 0;
  }
  return uVar3;
}

/* FUN_00113818 @ 0x113818 (40 bytes) */
int FUN_00113818()
{
  DAT_001fb93c = PTR_DAT_001e8f28 + 8;
  return;
}

/* FUN_00113840 @ 0x113840 (40 bytes) */
int FUN_00113840()
{
  DAT_001fb928 = PTR_DAT_001e8f28 + 8;
  return;
}

/* FUN_00113868 @ 0x113868 (40 bytes) */
int FUN_00113868()
{
  DAT_001fb914 = PTR_DAT_001e8f28 + 8;
  return;
}

/* FUN_00113890 @ 0x113890 (40 bytes) */
int FUN_00113890()
{
  DAT_001fbf90 = PTR_DAT_001e8f28 + 8;
  return;
}

/* FUN_001138b8 @ 0x1138b8 (40 bytes) */
int FUN_001138b8()
{
  DAT_001fbf7c = PTR_DAT_001e8f28 + 8;
  return;
}

/* FUN_001138e0 @ 0x1138e0 (40 bytes) */
int FUN_001138e0()
{
  DAT_001fbf68 = PTR_DAT_001e8f28 + 8;
  return;
}

/* FUN_00113908 @ 0x113908 (40 bytes) */
int FUN_00113908()
{
  DAT_001fc134 = PTR_DAT_001e8f28 + 8;
  return;
}

/* FUN_00113930 @ 0x113930 (40 bytes) */
int FUN_00113930()
{
  DAT_001fc120 = PTR_DAT_001e8f28 + 8;
  return;
}

/* FUN_00113958 @ 0x113958 (40 bytes) */
int FUN_00113958()
{
  DAT_001fb964 = PTR_DAT_001e8f28 + 8;
  return;
}

/* FUN_00113980 @ 0x113980 (40 bytes) */
int FUN_00113980()
{
  DAT_001fb950 = PTR_DAT_001e8f28 + 8;
  return;
}

/* FUN_001139a8 @ 0x1139a8 (40 bytes) */
int FUN_001139a8()
{
  DAT_001fb464 = PTR_DAT_001e8f28 + 8;
  return;
}

/* FUN_001139d0 @ 0x1139d0 (40 bytes) */
int FUN_001139d0()
{
  DAT_001fb478 = PTR_DAT_001e8f28 + 8;
  return;
}

/* FUN_001139f8 @ 0x1139f8 (40 bytes) */
int FUN_001139f8()
{
  DAT_001fbdc4 = PTR_DAT_001e8f28 + 8;
  return;
}

/* FUN_00113a20 @ 0x113a20 (40 bytes) */
int FUN_00113a20()
{
  DAT_001fc170 = PTR_DAT_001e8f28 + 8;
  return;
}

/* FUN_00113a48 @ 0x113a48 (40 bytes) */
int FUN_00113a48()
{
  DAT_001fb2c0 = PTR_DAT_001e8f28 + 8;
  return;
}

/* FUN_00113a70 @ 0x113a70 (40 bytes) */
int FUN_00113a70()
{
  DAT_001fb2d4 = PTR_DAT_001e8f28 + 8;
  return;
}

/* FUN_00113a98 @ 0x113a98 (40 bytes) */
int FUN_00113a98()
{
  DAT_001fb2e8 = PTR_DAT_001e8f28 + 8;
  return;
}

