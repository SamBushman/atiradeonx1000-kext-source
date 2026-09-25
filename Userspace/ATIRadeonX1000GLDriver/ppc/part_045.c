#include "decls.h"

/* FUN_0016c970 @ 0x16c970 (1108 bytes) */
int FUN_0016c970(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  int *piVar9;
  char *pcVar10;
  int iVar11;
  
  piVar9 = *(int **)(param_2 + 0x38);
  if (((((piVar9[5] & 0x20U) == 0) && (piVar9[0x20] != 0)) &&
      (iVar2 = FUN_00126760(piVar9[0x26]), iVar2 != 0)) && ((piVar9[5] & 2U) == 0)) {
    (**(code **)(*piVar9 + 0x50))(piVar9);
  }
  pcVar10 = *(char **)(param_2 + 0x60);
  if (pcVar10 != (char *)0x0) {
    iVar4 = 4;
    iVar2 = 0;
    pcVar6 = pcVar10;
    pcVar8 = pcVar10;
    do {
      if (((*pcVar6 != '\0') && (*(int *)(pcVar8 + 0x18) != 0)) &&
         (0 < *(int *)(iVar2 * 4 + *(int *)(pcVar8 + 0x18) + 0x48))) {
        return;
      }
      iVar2 = iVar2 + 1;
      pcVar6 = pcVar6 + 1;
      pcVar8 = pcVar8 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    uVar5 = *(uint *)(pcVar10 + 4);
    if ((-1 < (int)uVar5) && ((int)uVar5 < param_1[0x51])) {
      iVar2 = *(int *)(pcVar10 + 0x14);
      if (iVar2 == 0) {
        iVar4 = param_1[0x4c];
        uVar3 = uVar5 >> 3 & 0x1ffffffc;
      }
      else {
        iVar4 = param_1[0x4c];
        uVar3 = uVar5 >> 3 & 0x1ffffffc;
        if ((*(uint *)(uVar3 + iVar4 + 8) >> (uVar5 & 0x1f) & 1) != 0) goto LAB_0016cd84;
      }
      if ((*(uint *)(uVar3 + iVar4 + 8) >> (uVar5 & 0x1f) & 1) == 0) {
        return;
      }
      iVar2 = 4;
      piVar9 = param_1;
      pcVar6 = pcVar10;
      do {
        if (*pcVar6 != '\0') {
          *(int *)(*(int *)(pcVar10 + 4) * 4 + piVar9[0x54]) = param_1[0xb];
        }
        pcVar6 = pcVar6 + 1;
        piVar9 = piVar9 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      return;
    }
    iVar2 = *(int *)(pcVar10 + 0x14);
LAB_0016cd84:
    iVar4 = (**(code **)(*(int *)param_1[3] + 0x18))();
    if ((iVar4 <= iVar2) &&
       (iVar4 = FUN_00164bec(param_1,*(undefined4 *)pcVar10,iVar2,1), -1 < iVar4)) {
      iVar7 = param_1[0x51];
      iVar2 = *(int *)(*(int *)(pcVar10 + 8) + 0x38);
      while( true ) {
        if (iVar2 == 0) {
          return;
        }
        *(int *)(iVar2 + 0x94) = iVar4 + iVar7;
        if ((*(uint *)(iVar2 + 0x14) & 0x200) == 0) break;
        iVar2 = FUN_00105594(iVar2,*(undefined4 *)(iVar2 + 0x84));
      }
      return;
    }
    iVar2 = FUN_00164bec(param_1,*(undefined4 *)pcVar10,iVar2,0);
    bVar1 = iVar2 < 0;
    if (bVar1) {
      iVar2 = *(int *)(*param_1 + 0x3c4) + 1;
      *(int *)(*param_1 + 0x3c4) = iVar2;
    }
    iVar4 = *(int *)(*(int *)(pcVar10 + 8) + 0x38);
    while( true ) {
      if (iVar4 == 0) {
        return;
      }
      *(int *)(iVar4 + 0x94) = iVar2;
      if (bVar1) {
        uVar5 = *(uint *)(iVar4 + 0x14) & 0xffffffbf;
        *(uint *)(iVar4 + 0x14) = uVar5;
      }
      else {
        uVar5 = *(uint *)(iVar4 + 0x14) | 0x40;
        *(uint *)(iVar4 + 0x14) = uVar5;
      }
      if ((uVar5 & 0x200) == 0) break;
      iVar4 = FUN_00105594(iVar4,*(undefined4 *)(iVar4 + 0x84));
    }
    return;
  }
  iVar7 = *(int *)(param_2 + 0x38);
  iVar11 = 4;
  iVar2 = iVar7;
  iVar4 = param_2;
  do {
    if ((*(char *)(iVar2 + 0xc) != '\0') && (0 < *(int *)(iVar4 + 0x48))) {
      return;
    }
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  uVar5 = *(uint *)(iVar7 + 0x94);
  if (((*(uint *)(iVar7 + 0x14) & 0x40) == 0) || (param_1[0x51] <= (int)uVar5)) {
    iVar2 = *(int *)(param_2 + 0x2c);
LAB_0016cd5c:
    iVar4 = (**(code **)(*(int *)param_1[3] + 0x18))();
    if ((iVar2 < iVar4) ||
       (iVar4 = FUN_00164bec(param_1,*(undefined4 *)(*(int *)(param_2 + 0x38) + 0xc),iVar2,1),
       iVar4 < 0)) {
      iVar2 = FUN_00164bec(param_1,*(undefined4 *)(*(int *)(param_2 + 0x38) + 0xc),iVar2,0);
      bVar1 = iVar2 < 0;
      if (bVar1) {
        iVar2 = *(int *)(*param_1 + 0x3c4) + 1;
        *(int *)(*param_1 + 0x3c4) = iVar2;
      }
      *(int *)(*(int *)(param_2 + 0x38) + 0x94) = iVar2;
      iVar2 = *(int *)(param_2 + 0x38);
      if (bVar1) {
        *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xffffffbf;
      }
      else {
        *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 0x40;
      }
    }
    else {
      *(int *)(*(int *)(param_2 + 0x38) + 0x94) = iVar4 + param_1[0x51];
    }
  }
  else {
    iVar2 = *(int *)(param_2 + 0x2c);
    if (iVar2 == 0) {
      iVar4 = param_1[0x4c];
      uVar3 = uVar5 >> 3 & 0x1ffffffc;
    }
    else {
      iVar4 = param_1[0x4c];
      uVar3 = uVar5 >> 3 & 0x1ffffffc;
      if ((*(uint *)(uVar3 + iVar4 + 8) >> (uVar5 & 0x1f) & 1) != 0) goto LAB_0016cd5c;
    }
    if ((*(uint *)(uVar3 + iVar4 + 8) >> (uVar5 & 0x1f) & 1) != 0) {
      iVar4 = 4;
      iVar2 = 0;
      piVar9 = param_1;
      while( true ) {
        if (*(char *)(iVar7 + iVar2 + 0xc) != '\0') {
          *(int *)(piVar9[0x54] + uVar5 * 4) = param_1[0xb];
        }
        iVar2 = iVar2 + 1;
        piVar9 = piVar9 + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) break;
        iVar7 = *(int *)(param_2 + 0x38);
      }
    }
  }
  return;
}

/* FUN_0016cdc4 @ 0x16cdc4 (1516 bytes) */
int FUN_0016cdc4(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  bool bVar1;
  char *pcVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  int *piVar14;
  undefined4 local_48 [7];
  
  uVar11 = 0;
  puVar13 = *(uint **)(param_2 + 0x44);
  piVar9 = *(int **)(param_2 + 0x38);
  uVar8 = puVar13[1];
  if (0 < (int)uVar8) {
    while( true ) {
      if (uVar11 < *puVar13) {
        uVar3 = puVar13[1];
        if (uVar3 <= uVar11) {
          _memset((void *)(uVar3 * 4 + puVar13[2]),0,(uVar11 - uVar3) * 4 + 4);
          puVar13[1] = uVar11 + 1;
        }
        puVar4 = (undefined4 *)(uVar11 * 4 + puVar13[2]);
      }
      else {
        puVar4 = (undefined4 *)FUN_0019423c(puVar13,uVar11);
      }
      uVar11 = uVar11 + 1;
      piVar14 = (int *)*puVar4;
      if (piVar14[2] == 0) {
        iVar12 = *piVar14;
        iVar5 = (**(code **)(*piVar9 + 0x60))(piVar9);
        if ((iVar5 != 0) && (iVar5 = (**(code **)(**(int **)(iVar12 + 0x38) + 0x5c))(), iVar5 != 0))
        {
          FUN_0019401c(iVar12);
        }
        iVar5 = iVar12;
        do {
          if (((((*(char *)(piVar14 + 6) != '\0') &&
                (iVar7 = *(int *)(iVar5 + 0x48) + -1, *(int *)(iVar5 + 0x48) = iVar7, iVar7 == 0))
               && (piVar10 = *(int **)(iVar12 + 0x38), (piVar10[5] & 0x20U) == 0)) &&
              ((piVar10[0x20] != 0 && (iVar7 = FUN_00126760(piVar10[0x26]), iVar7 != 0)))) &&
             (((piVar10[5] & 2U) == 0 &&
              ((iVar7 = (**(code **)(*piVar10 + 0x50))(piVar10), iVar7 == 0 &&
               (iVar7 = FUN_000e07dc(*param_1,0x25), iVar7 != 0)))))) {
            if (param_1[0x58] == 0) {
              if ((int)param_1[0x51] <= *(int *)(*(int *)(iVar12 + 0x38) + 0x94)) {
                FUN_001659fc(param_1,iVar12);
              }
            }
            else {
              ((int (*)())FUN_0016c970)(param_1,iVar12);
            }
          }
          iVar5 = iVar5 + 4;
          piVar14 = (int *)((int)piVar14 + 1);
        } while (iVar12 + 0x10 != iVar5);
      }
      if (uVar8 == uVar11) break;
      puVar13 = *(uint **)(param_2 + 0x44);
    }
  }
  iVar5 = FUN_000e07dc(*param_1,0x26);
  if (iVar5 != 0) {
    iVar12 = 1;
    iVar5 = FUN_000e07dc(*param_1,0x25);
    if (iVar5 != 0) {
      for (; iVar5 = (**(code **)(*piVar9 + 0x14))(piVar9), iVar12 <= iVar5; iVar12 = iVar12 + 1) {
        uVar6 = FUN_00105594(piVar9,iVar12);
        while (iVar5 = FUN_00105594(uVar6,0), iVar5 != 0) {
          uVar6 = FUN_00105594(uVar6,0);
        }
        FUN_00106004(piVar9,iVar12,uVar6,0,*param_1);
      }
      goto LAB_0016d0d8;
    }
  }
  if (((piVar9[5] & 0x200U) != 0) &&
     (iVar5 = FUN_00105594(piVar9,piVar9[0x21]), (*(uint *)(iVar5 + 0x14) & 1) == 0)) {
    FUN_00106004(piVar9,piVar9[0x21],0,0,*param_1);
    piVar9[5] = piVar9[5] & 0xfffffdff;
    uVar8 = *(uint *)(iVar5 + 0x14);
    piVar9[0x21] = piVar9[0x21] + -1;
    if ((uVar8 & 0x200) != 0) {
      uVar6 = FUN_00105594(iVar5,*(undefined4 *)(iVar5 + 0x84));
      FUN_00106804(piVar9,uVar6,0,*param_1);
    }
  }
LAB_0016d0d8:
  iVar5 = FUN_000e07dc(*param_1,0x25);
  if ((iVar5 != 0) && (iVar5 = *(int *)(param_2 + 0x60), iVar5 != 0)) {
    iVar12 = *(int *)(iVar5 + 4);
    if (-1 < iVar12) {
      piVar9[0x25] = iVar12;
      piVar9[5] = piVar9[5] | 0x40;
      iVar5 = 0;
      puVar4 = param_1;
      do {
        iVar7 = FUN_001054ec(piVar9,0);
        if (*(char *)(iVar5 + iVar7 + 0x10) != '\x01') {
          *(int *)(puVar4[0x4d] + iVar12 * 4) = param_2;
          if ((puVar4[0x54] != 0) && (*(int *)(*(int *)(param_2 + 0x60) + 0x14) == 0)) {
            *(undefined4 *)(puVar4[0x54] + iVar12 * 4) = 0x7fffffff;
          }
        }
        bVar1 = iVar5 != 3;
        puVar4 = puVar4 + 1;
        iVar5 = iVar5 + 1;
      } while (bVar1);
      iVar5 = *(int *)(param_2 + 0x60);
    }
    if (*(int *)(param_2 + 0x2c) < *(int *)(iVar5 + 0x14)) {
      *(int *)(iVar5 + 0x14) = *(int *)(param_2 + 0x2c);
    }
    iVar5 = 0;
    do {
      iVar12 = FUN_001054ec(piVar9,0);
      if (*(char *)(iVar5 + iVar12 + 0x10) != '\x01') {
        *(int *)(iVar5 * 4 + *(int *)(param_2 + 0x60) + 0x18) = param_2;
      }
      bVar1 = iVar5 != 3;
      iVar5 = iVar5 + 1;
    } while (bVar1);
  }
  piVar14 = *(int **)(param_2 + 0x38);
  if (((((piVar14[5] & 0x20U) == 0) && (piVar14[0x20] != 0)) &&
      (iVar5 = FUN_00126760(piVar14[0x26]), iVar5 != 0)) &&
     (((piVar14[5] & 2U) == 0 && (iVar5 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar5 == 0)))) {
    if ((*(int *)(param_2 + 0x60) == 0) ||
       (iVar5 = *(int *)(*(int *)(param_2 + 0x60) + 8), iVar5 == 0)) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(iVar5 + 0x38);
    }
    iVar12 = FUN_000e07dc(*param_1,0x26);
    if ((iVar12 != 0) && (iVar12 = FUN_000e07dc(*param_1,0x25), iVar12 != 0)) {
      if (iVar5 == 0) {
        if ((*(uint *)(*(int *)(param_2 + 0x38) + 0x14) & 0x200) != 0) {
          FUN_00106004(piVar9,piVar9[0x21],0,0,*param_1);
          piVar9[0x21] = piVar9[0x21] + -1;
          piVar9[5] = piVar9[5] & 0xfffffdff;
        }
      }
      else {
        FUN_00106004(iVar5,0,*(undefined4 *)(param_2 + 0x38),0,*param_1);
        FUN_00106804(piVar9,iVar5,0,*param_1);
      }
    }
    if ((*(int *)(param_2 + 0x60) != 0) &&
       (iVar5 = FUN_001054ec(piVar9,0), *(int *)(iVar5 + 0x10) != DAT_001b0198)) {
      iVar5 = *(int *)(param_2 + 0x60);
      if ((*(int *)(iVar5 + 8) == 0) || (*(int *)(*(int *)(iVar5 + 8) + 0x2c) != param_1[0xb])) {
        iVar12 = FUN_001054ec(*(undefined4 *)(param_2 + 0x38),0);
        *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar12 + 0x10);
      }
      else {
        iVar12 = FUN_001054ec(*(undefined4 *)(param_2 + 0x38),0);
        pcVar2 = (char *)(iVar5 + 0xc);
        iVar5 = 0;
        local_48[0] = *(undefined4 *)(iVar12 + 0x10);
        iVar12 = 4;
        do {
          if (*(char *)((int)local_48 + iVar5) != '\x01') {
            *pcVar2 = *(char *)((int)local_48 + iVar5);
          }
          iVar5 = iVar5 + 1;
          pcVar2 = pcVar2 + 1;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
      }
      *(int *)(*(int *)(param_2 + 0x60) + 8) = param_2;
    }
  }
  return;
}

/* FUN_0016d3b0 @ 0x16d3b0 (392 bytes) */
int FUN_0016d3b0(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x38) + 0x5c))(*(int **)(param_2 + 0x38));
  if (iVar1 == 0) {
    (**(code **)(*(int *)param_1[2] + 0x74))((int *)param_1[2],param_2,param_1[0xc]);
  }
  else {
    FUN_00193f64(param_1 + 0x25,param_2);
  }
  iVar1 = param_1[0xb];
  *(int *)(param_2 + 0x2c) = iVar1;
  *(int *)(param_2 + 0x30) = iVar1;
  (**(code **)(*(int *)param_1[2] + 0x10))((int *)param_1[2],*(undefined4 *)(param_2 + 0x38));
  ((int (*)())FUN_0017212c)(param_1[2],param_2);
  (**(code **)(*(int *)param_1[3] + 0x10))((int *)param_1[3],param_2);
  ((int (*)())FUN_0016cdc4)(param_1,param_2);
  iVar1 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0xd4))();
  if ((iVar1 != 0) && ((*(uint *)(*(int *)(param_2 + 0x38) + 0x14) & 0x1000) != 0)) {
    ((int (*)())FUN_0016e1a4)(param_1);
  }
  ((int (*)())FUN_00170bcc)(param_1,param_2);
  iVar1 = (**(code **)(*(int *)param_1[3] + 0x20))
                    ((int *)param_1[3],*(undefined4 *)(param_2 + 0x38));
  if (((iVar1 != 0) ||
      (iVar1 = (**(code **)(*(int *)param_1[3] + 0x24))
                         ((int *)param_1[3],*(undefined4 *)(param_2 + 0x38)), iVar1 != 0)) &&
     (param_1[0x4a] <= *(int *)(param_2 + 0xc))) {
    param_1[0x4b] = param_1[0x4b] + 1;
  }
  return;
}

/* FUN_0016d538 @ 0x16d538 (1996 bytes) */
int FUN_0016d538(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  uint *puVar15;
  undefined4 local_58 [8];
  
  FUN_001045e4(*(undefined4 *)(param_2 + 0x38));
  if (param_1[0x61] < 0) {
    if (*(int *)(*(int *)(param_2 + 0x38) + 0x98) == 0x3a) {
      param_1[0x61] = 1;
    }
    else {
      param_1[0x61] = *(int *)(*(int *)(*param_1 + 0x30c) + 0x1c);
    }
  }
  iVar10 = *(int *)(param_2 + 0x38);
  iVar12 = 0;
  iVar3 = FUN_001054ec(iVar10,1);
  FUN_000f2c5c(*(undefined4 *)(iVar3 + 0x10));
  do {
    iVar3 = FUN_001054ec(iVar10,0);
    if (*(char *)(iVar12 + iVar3 + 0x10) != '\x01') {
      iVar3 = FUN_001054ec(iVar10,1);
      uVar7 = (uint)*(byte *)(iVar12 + iVar3 + 0x10);
      goto LAB_0016d5f8;
    }
    bVar1 = iVar12 != 3;
    iVar12 = iVar12 + 1;
  } while (bVar1);
  uVar7 = 4;
LAB_0016d5f8:
  iVar3 = param_1[0x61];
  if (0 < iVar3) {
    uVar11 = 0;
    piVar5 = param_1;
    do {
      if (piVar5[0x5c] != 0) {
        iVar3 = FUN_00105594(*(undefined4 *)(piVar5[0x5c] + 0x38),1);
        iVar12 = FUN_00105594(iVar10,1);
        if (iVar3 == iVar12) {
          iVar12 = piVar5[0x5c];
          iVar13 = *(int *)(iVar12 + 0x38);
          iVar8 = uVar11 + (((int)uVar11 >> 2) + (uint)((int)uVar11 < 0 && (uVar11 & 3) != 0)) * -4;
          iVar3 = FUN_001054ec(iVar13,1);
          if ((uVar7 == *(byte *)(iVar8 + iVar3 + 0x10)) &&
             (iVar3 = (**(code **)(**(int **)(iVar13 + 0x88) + 0x18))(),
             iVar3 == *(int *)(iVar10 + 300))) {
            FUN_00106004(iVar10,1,iVar13,0,*param_1);
            uVar14 = *(undefined4 *)(PTR_DAT_001e8b8c + iVar8 * 4);
            iVar3 = FUN_001054ec(iVar10,1);
            *(undefined4 *)(iVar3 + 0x10) = uVar14;
            if (*(int *)(iVar12 + 0x6c) != 0) {
              *(int *)(param_2 + 0x6c) = *(int *)(iVar12 + 0x6c);
            }
            puVar15 = *(uint **)(param_2 + 0x40);
            uVar11 = 0;
            *(int *)(iVar12 + 0x6c) = param_2;
            uVar7 = puVar15[1];
            if ((int)uVar7 < 1) {
              return 1;
            }
            while( true ) {
              if (uVar11 < *puVar15) {
                uVar4 = puVar15[1];
                if (uVar4 <= uVar11) {
                  _memset((void *)(uVar4 * 4 + puVar15[2]),0,(uVar11 - uVar4) * 4 + 4);
                  puVar15[1] = uVar11 + 1;
                }
                piVar5 = (int *)(uVar11 * 4 + puVar15[2]);
              }
              else {
                piVar5 = (int *)FUN_0019423c(puVar15,uVar11);
              }
              uVar11 = uVar11 + 1;
              iVar3 = *piVar5;
              iVar10 = *(int *)(iVar3 + 4);
              if (*(int *)(iVar3 + 8) == 0) {
                local_58[0] = 0;
                *(undefined1 *)((int)local_58 + iVar8) = 1;
                FUN_00165b7c(param_1,iVar12,iVar10,*(undefined4 *)(iVar3 + 0x10),
                             *(undefined4 *)(iVar3 + 0x14),local_58[0]);
                *(int *)(iVar10 + 0x34) = *(int *)(iVar10 + 0x34) + -1;
              }
              if (uVar7 == uVar11) break;
              puVar15 = *(uint **)(param_2 + 0x40);
            }
            return 1;
          }
        }
        iVar3 = param_1[0x61];
      }
      uVar11 = uVar11 + 1;
      piVar5 = piVar5 + 1;
    } while ((int)uVar11 < iVar3);
    if (0 < iVar3) {
      iVar12 = param_1[0x5c];
      if (iVar12 == 0) {
        uVar9 = 0;
        iVar3 = 0;
      }
      else {
        uVar4 = 0;
        uVar11 = 0xffffffff;
        piVar5 = param_1;
        do {
          if ((*(int *)((uVar4 + (((int)uVar4 >> 2) + (uint)((int)uVar4 < 0 && (uVar4 & 3) != 0)) *
                                 -4) * 4 + iVar12 + 0x48) == 0) &&
             (((int)uVar11 < 0 ||
              (*(int *)(iVar12 + 0x2c) < *(int *)(param_1[uVar11 + 0x5c] + 0x2c))))) {
            uVar11 = uVar4;
          }
          uVar4 = uVar4 + 1;
          iVar3 = iVar3 + -1;
          uVar9 = uVar11;
          if (iVar3 == 0) break;
          iVar12 = piVar5[0x5d];
          piVar5 = piVar5 + 1;
          uVar9 = uVar4;
        } while (iVar12 != 0);
        if ((int)uVar9 < 0) {
          return 0;
        }
        iVar3 = uVar9 + (((int)uVar9 >> 2) + (uint)((int)uVar9 < 0 && (uVar9 & 3) != 0)) * -4;
      }
      uVar4 = uVar9 - iVar3;
      uVar11 = uVar4 + 4;
      piVar5 = param_1 + uVar4 + 0x5c;
      do {
        if ((((*(uint *)(*(int *)(*param_1 + 0x30c) + 8) & 0x200) == 0) && (*piVar5 != 0)) &&
           (uVar4 != uVar9)) {
          iVar12 = FUN_00105594(*(undefined4 *)(*piVar5 + 0x38),1);
          iVar8 = FUN_00105594(iVar10,1);
          if (iVar12 == iVar8) {
            iVar12 = *piVar5;
            piVar6 = *(int **)(iVar12 + 0x38);
            if (*(int *)(iVar10 + 300) == 0) {
              if (*(int *)(piVar6[0x22] + 8) == 0xa6) goto LAB_0016d91c;
            }
            else if (*(int *)(piVar6[0x22] + 8) == 0x2b) {
LAB_0016d91c:
              if ((param_1[uVar9 + 0x5c] == 0) ||
                 (iVar8 = FUN_00167a74(param_1[uVar9 + 0x5c],iVar3), iVar8 < *(int *)(iVar12 + 0x2c)
                 )) {
                *(undefined1 *)((int)piVar6 + iVar3 + 0x9c) = 0;
                (**(code **)(*piVar6 + 0x88))(piVar6,1,iVar3,uVar7);
                *(undefined1 *)((int)piVar6 + iVar3 + 0xc) = 1;
                iVar8 = *param_1;
                param_1[uVar9 + 0x5c] = iVar12;
                FUN_00106004(iVar10,1,piVar6,0,iVar8);
                uVar14 = *(undefined4 *)(PTR_DAT_001e8b8c + iVar3 * 4);
                iVar10 = FUN_001054ec(iVar10,1);
                *(undefined4 *)(iVar10 + 0x10) = uVar14;
                if (*(int *)(iVar12 + 0x6c) != 0) {
                  *(int *)(param_2 + 0x6c) = *(int *)(iVar12 + 0x6c);
                }
                puVar15 = *(uint **)(param_2 + 0x40);
                uVar11 = 0;
                *(int *)(iVar12 + 0x6c) = param_2;
                uVar7 = puVar15[1];
                if ((int)uVar7 < 1) {
                  return 1;
                }
                while( true ) {
                  if (uVar11 < *puVar15) {
                    uVar4 = puVar15[1];
                    if (uVar4 <= uVar11) {
                      _memset((void *)(uVar4 * 4 + puVar15[2]),0,(uVar11 - uVar4) * 4 + 4);
                      puVar15[1] = uVar11 + 1;
                    }
                    piVar5 = (int *)(uVar11 * 4 + puVar15[2]);
                  }
                  else {
                    piVar5 = (int *)FUN_0019423c(puVar15,uVar11);
                  }
                  uVar11 = uVar11 + 1;
                  iVar10 = *piVar5;
                  iVar8 = *(int *)(iVar10 + 4);
                  if (*(int *)(iVar10 + 8) == 0) {
                    local_58[0] = 0;
                    *(undefined1 *)((int)local_58 + iVar3) = 1;
                    FUN_00165b7c(param_1,iVar12,iVar8,*(undefined4 *)(iVar10 + 0x10),
                                 *(undefined4 *)(iVar10 + 0x14),local_58[0]);
                    *(int *)(iVar8 + 0x34) = *(int *)(iVar8 + 0x34) + -1;
                  }
                  if (uVar7 == uVar11) break;
                  puVar15 = *(uint **)(param_2 + 0x40);
                }
                return 1;
              }
            }
          }
        }
        uVar4 = uVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (uVar11 != uVar4);
      iVar12 = (**(code **)(*(int *)param_1[2] + 0x80))
                         ((int *)param_1[2],param_1[0x60],*(undefined4 *)(iVar10 + 300),
                          *(undefined4 *)(iVar10 + 0x130),*(int *)(iVar10 + 0x98) == 0x3a);
      puVar2 = PTR_DAT_001e8b64;
      param_1[0x60] = iVar12;
      *(undefined4 *)(iVar12 + 0x98) = 0x20;
      *(uint *)(iVar12 + 0x94) = ((int)uVar9 >> 2) + (uint)((int)uVar9 < 0 && (uVar9 & 3) != 0);
      *(undefined4 *)(param_1[0x60] + 0x9c) = *(undefined4 *)(puVar2 + iVar3 * 4);
      iVar12 = param_1[0x60];
      uVar14 = FUN_00105594(iVar10,1);
      FUN_00106004(iVar12,1,uVar14,0,*param_1);
      puVar2 = PTR_DAT_001e8b8c;
      uVar14 = *(undefined4 *)(PTR_DAT_001e8b8c + uVar7 * 4);
      iVar12 = FUN_001054ec(param_1[0x60],1);
      *(undefined4 *)(iVar12 + 0x10) = uVar14;
      *(undefined4 *)(param_1[0x60] + 0xc) = 0;
      *(undefined1 *)(param_1[0x60] + iVar3 + 0xc) = 1;
      iVar12 = (**(code **)(*(int *)param_1[2] + 0xc))((int *)param_1[2],param_1[0x60]);
      if (iVar12 != 0) {
        iVar12 = FUN_00165d3c(param_1,param_1[0x60],param_2 + 0xc,param_1[0xb]);
        param_1[0x60] = 0;
        param_1[uVar9 + 0x5c] = iVar12;
        FUN_00106004(iVar10,1,*(undefined4 *)(iVar12 + 0x38),0,*param_1);
        uVar14 = *(undefined4 *)(puVar2 + iVar3 * 4);
        iVar10 = FUN_001054ec(iVar10,1);
        *(undefined4 *)(iVar10 + 0x10) = uVar14;
        uVar11 = 0;
        puVar15 = *(uint **)(param_2 + 0x40);
        *(int *)(iVar12 + 0x6c) = param_2;
        uVar7 = puVar15[1];
        if (0 < (int)uVar7) {
          while( true ) {
            if (uVar11 < *puVar15) {
              uVar4 = puVar15[1];
              if (uVar4 <= uVar11) {
                _memset((void *)(uVar4 * 4 + puVar15[2]),0,(uVar11 - uVar4) * 4 + 4);
                puVar15[1] = uVar11 + 1;
              }
              piVar5 = (int *)(uVar11 * 4 + puVar15[2]);
            }
            else {
              piVar5 = (int *)FUN_0019423c(puVar15,uVar11);
            }
            uVar11 = uVar11 + 1;
            iVar10 = *piVar5;
            uVar14 = *(undefined4 *)(iVar10 + 4);
            if (*(int *)(iVar10 + 8) == 0) {
              local_58[0] = 0;
              *(undefined1 *)((int)local_58 + iVar3) = 1;
              FUN_00165b7c(param_1,iVar12,uVar14,*(undefined4 *)(iVar10 + 0x10),
                           *(undefined4 *)(iVar10 + 0x14),local_58[0]);
            }
            if (uVar7 == uVar11) break;
            puVar15 = *(uint **)(param_2 + 0x40);
          }
        }
        ((int (*)())FUN_0016d3b0)(param_1,iVar12);
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_0016dd04 @ 0x16dd04 (596 bytes) */
int FUN_0016dd04(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined4 uVar14;
  code *pcVar15;
  int iVar16;
  
  iVar9 = 0;
  uVar7 = *(undefined4 *)(param_2 + 0x38);
  FUN_00104644(uVar7);
  piVar2 = param_1;
  piVar11 = param_1;
  do {
    if (piVar11[0x62] != 0) {
      iVar16 = *(int *)(piVar11[0x62] + 0x38);
      iVar13 = *(int *)(iVar16 + 0x130);
      iVar10 = *(int *)(iVar16 + 0x134);
      iVar8 = *(int *)(iVar16 + 300);
      iVar3 = FUN_00105c5c(uVar7,0);
      iVar4 = FUN_00105594(uVar7,1);
      if (iVar13 == *(int *)(iVar4 + 0x94)) {
        if ((iVar10 <= iVar3) && (iVar3 < iVar10 + iVar8)) goto LAB_0016ddd8;
        if (iVar8 == 0x10) {
          if ((iVar10 <= iVar3) && (iVar3 < iVar10 + 0x20)) {
            *(undefined4 *)(iVar16 + 300) = 0x20;
LAB_0016ddd8:
            FUN_00106004(uVar7,1,iVar16,0,*param_1);
            *(undefined4 *)(param_2 + 0x6c) = *(undefined4 *)(piVar2[0x62] + 0x6c);
            *(int *)(piVar2[0x62] + 0x6c) = param_2;
            return 1;
          }
          if ((iVar10 + -0x10 <= iVar3) && (iVar3 < iVar10 + 0x10)) {
            *(undefined4 *)(iVar16 + 300) = 0x20;
            *(int *)(iVar16 + 0x134) = iVar10 + -0x10;
            goto LAB_0016ddd8;
          }
        }
      }
    }
    bVar1 = iVar9 == 1;
    piVar2 = piVar2 + 1;
    piVar11 = piVar11 + 1;
    iVar9 = iVar9 + 1;
    if (bVar1) {
      iVar9 = 0;
      piVar2 = param_1;
      do {
        if (piVar2[0x62] == 0) {
          if (iVar9 < 0) {
            return 0;
          }
          uVar14 = *(undefined4 *)(*param_1 + 0x374);
          puVar5 = (undefined4 *)FUN_00193e18(uVar14,0x168);
          *puVar5 = uVar14;
          puVar12 = puVar5 + 1;
          FUN_00109a80(puVar12,0xfa,*param_1);
          uVar6 = FUN_00105c5c(uVar7,0);
          puVar5[0x27] = 0x45;
          puVar5[0x26] = iVar9;
          iVar3 = FUN_00105594(uVar7,1);
          uVar14 = DAT_001b0194;
          puVar5[0x4d] = *(undefined4 *)(iVar3 + 0x94);
          puVar5[0x4c] = 0x10;
          puVar5[0x4e] = (((int)uVar6 >> 4) + (uint)((int)uVar6 < 0 && (uVar6 & 0xf) != 0)) * 0x10;
          puVar5[4] = uVar14;
          pcVar15 = *(code **)(puVar5[1] + 0x94);
          uVar14 = FUN_00105594(uVar7,1);
          (*pcVar15)(puVar12,uVar14,*param_1);
          iVar3 = FUN_00165d3c(param_1,puVar12,param_2 + 0xc,param_1[0xb]);
          iVar4 = *param_1;
          param_1[iVar9 + 0x62] = iVar3;
          FUN_00106004(uVar7,1,puVar12,0,iVar4);
          *(int *)(iVar3 + 0x6c) = param_2;
          ((int (*)())FUN_0016d3b0)(param_1,iVar3);
          return 1;
        }
        bVar1 = iVar9 != 1;
        piVar2 = piVar2 + 1;
        iVar9 = iVar9 + 1;
      } while (bVar1);
      return 0;
    }
  } while( true );
}

/* FUN_0016df8c @ 0x16df8c (536 bytes) */
int FUN_0016df8c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  FUN_00166ba8(param_1,param_2);
  iVar2 = param_1 + 0xf8;
  if (*(int *)(param_2 + 0x68) == 0) {
    iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x20))
                      (*(int **)(param_1 + 0xc),*(undefined4 *)(param_2 + 0x38));
    if ((iVar2 == 0) &&
       (iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x24))
                          (*(int **)(param_1 + 0xc),*(undefined4 *)(param_2 + 0x38)), iVar2 == 0)) {
      if (((*(int *)(param_2 + 0x58) == 0) &&
          (iVar2 = FUN_001045e4(*(undefined4 *)(param_2 + 0x38)), iVar2 == 0)) &&
         (iVar2 = FUN_00104644(*(undefined4 *)(param_2 + 0x38)), iVar2 == 0)) {
        ((int (*)())FUN_0016d3b0)(param_1,param_2);
        return;
      }
      piVar4 = *(int **)(param_2 + 0x38);
      if ((((piVar4[5] & 0x20U) == 0) && (piVar4[0x20] != 0)) &&
         ((iVar2 = FUN_00126760(piVar4[0x26]), iVar2 != 0 &&
          (((piVar4[5] & 2U) == 0 && (iVar2 = (**(code **)(*piVar4 + 0x50))(piVar4), iVar2 == 0)))))
         ) {
        iVar3 = 4;
        iVar2 = param_2;
        while (*(int *)(iVar2 + 0x48) < 1) {
          iVar2 = iVar2 + 4;
          iVar3 = iVar3 + -1;
          if (iVar3 == 0) {
            ((int (*)())FUN_00170da0)(param_1,param_2);
            return;
          }
        }
      }
      iVar2 = param_1 + 0x4c;
      iVar3 = *(int *)(param_1 + 0x54);
      iVar1 = *(int *)(iVar3 + 8);
      while (iVar1 != 0) {
        iVar1 = FUN_001648ac(param_1,param_2,iVar3);
        if (0 < iVar1) {
LAB_0016e148:
          FUN_00193f44(param_2,iVar3);
          return;
        }
        iVar3 = *(int *)(iVar3 + 8);
        iVar1 = *(int *)(iVar3 + 8);
      }
    }
    else {
      iVar2 = param_1 + 0x34;
      iVar3 = *(int *)(param_1 + 0x3c);
      iVar1 = *(int *)(iVar3 + 8);
      while (iVar1 != 0) {
        iVar1 = FUN_001648ac(param_1,param_2,iVar3);
        if (0 < iVar1) goto LAB_0016e148;
        iVar3 = *(int *)(iVar3 + 8);
        iVar1 = *(int *)(iVar3 + 8);
      }
    }
  }
  FUN_00193f64(iVar2,param_2);
  return;
}

/* FUN_0016e1a4 @ 0x16e1a4 (1668 bytes) */
int FUN_0016e1a4(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined4 *puVar13;
  int iVar14;
  int *piVar15;
  int iVar16;
  uint uVar17;
  uint *puVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  
  iVar9 = param_1[0x61];
  if (0 < iVar9) {
    uVar11 = 0;
    puVar13 = param_1;
    do {
      iVar14 = puVar13[0x5c];
      iVar10 = uVar11 + (((int)uVar11 >> 2) + (uint)((int)uVar11 < 0 && (uVar11 & 3) != 0)) * -4;
      if ((iVar14 != 0) && (*(int *)(iVar14 + 0x2c) < (int)param_1[0xb])) {
        iVar22 = iVar10 * 4;
        puVar13[0x5c] = 0;
        puVar1 = PTR_DAT_001eb254;
        if ((0 < *(int *)(iVar22 + iVar14 + 0x48)) &&
           (iVar16 = *(int *)(iVar14 + 0x6c), iVar16 != 0)) {
          do {
            iVar9 = FUN_001054ec(*(undefined4 *)(iVar16 + 0x38),1);
            if (*(int *)(iVar9 + 0x10) == *(int *)(puVar1 + iVar22)) {
              iVar20 = 4;
              iVar9 = iVar16;
LAB_0016e258:
              if (*(int *)(iVar9 + 0x48) < 1) goto code_r0x0016e264;
              uVar5 = FUN_0010445c(*(undefined4 *)(iVar16 + 0x38),*param_1,0);
              uVar6 = FUN_00105594(*(undefined4 *)(iVar14 + 0x38),1);
              FUN_00106004(uVar5,1,uVar6,0,*param_1);
              iVar9 = FUN_001054ec(*(undefined4 *)(iVar14 + 0x38),1);
              uVar6 = *(undefined4 *)(puVar1 + (uint)*(byte *)(iVar10 + iVar9 + 0x10) * 4);
              iVar9 = FUN_001054ec(uVar5,1);
              *(undefined4 *)(iVar9 + 0x10) = uVar6;
              uVar7 = 0;
              iVar9 = FUN_00165d3c(param_1,uVar5,iVar16 + 0xc,param_1[0xb]);
              puVar18 = *(uint **)(iVar16 + 0x40);
              uVar19 = puVar18[1];
              if (0 < (int)uVar19) {
                while( true ) {
                  if (uVar7 < *puVar18) {
                    uVar2 = puVar18[1];
                    if (uVar2 <= uVar7) {
                      _memset((void *)(uVar2 * 4 + puVar18[2]),0,(uVar7 - uVar2) * 4 + 4);
                      puVar18[1] = uVar7 + 1;
                    }
                    puVar8 = (undefined4 *)(uVar7 * 4 + puVar18[2]);
                  }
                  else {
                    puVar8 = (undefined4 *)FUN_0019423c(puVar18,uVar7);
                  }
                  uVar7 = uVar7 + 1;
                  piVar15 = (int *)*puVar8;
                  iVar23 = 1;
                  iVar20 = piVar15[1];
                  if (*(int *)(iVar20 + 0x2c) < 0) {
                    for (; iVar3 = (**(code **)(**(int **)(iVar20 + 0x38) + 0x14))(),
                        iVar23 <= iVar3; iVar23 = iVar23 + 1) {
                      iVar3 = FUN_00105594(*(undefined4 *)(iVar20 + 0x38),iVar23);
                      if (iVar3 == *(int *)(iVar16 + 0x38)) {
                        FUN_00106004(*(undefined4 *)(iVar20 + 0x38),iVar23,uVar5,0,*param_1);
                      }
                    }
                    *piVar15 = iVar9;
                    puVar18 = *(uint **)(iVar9 + 0x40);
                    uVar2 = puVar18[1];
                    if (uVar2 < *puVar18) {
                      _memset((void *)(uVar2 * 4 + puVar18[2]),0,4);
                      puVar8 = (undefined4 *)(uVar2 * 4 + puVar18[2]);
                      puVar18[1] = uVar2 + 1;
                    }
                    else {
                      puVar8 = (undefined4 *)FUN_0019423c(puVar18,uVar2);
                    }
                    *puVar8 = piVar15;
                    iVar21 = 4;
                    iVar23 = iVar9;
                    iVar3 = iVar16;
                    do {
                      if (*(char *)(piVar15 + 6) != '\0') {
                        *(int *)(iVar23 + 0x48) = *(int *)(iVar23 + 0x48) + 1;
                        *(int *)(iVar3 + 0x48) = *(int *)(iVar3 + 0x48) + -1;
                      }
                      piVar15 = (int *)((int)piVar15 + 1);
                      iVar23 = iVar23 + 4;
                      iVar3 = iVar3 + 4;
                      iVar21 = iVar21 + -1;
                    } while (iVar21 != 0);
                    puVar18 = *(uint **)(iVar20 + 0x44);
                    uVar2 = puVar18[1];
                    uVar17 = uVar2 - 1;
                    if (-1 < (int)uVar17) {
                      iVar23 = uVar17 * 4;
                      uVar12 = 0;
                      while( true ) {
                        if (uVar17 < *puVar18) {
                          uVar4 = puVar18[1];
                          if (uVar4 <= uVar17) {
                            _memset((void *)(uVar4 * 4 + puVar18[2]),0,(uVar17 - uVar4) * 4 + 4);
                            puVar18[1] = uVar17 + 1;
                          }
                          puVar8 = (undefined4 *)(iVar23 + puVar18[2]);
                        }
                        else {
                          puVar8 = (undefined4 *)FUN_0019423c(puVar18,uVar17);
                        }
                        if ((iVar14 == *(int *)*puVar8) &&
                           (*(char *)((int)*puVar8 + iVar10 + 0x18) != '\0')) {
                          FUN_00194208(*(undefined4 *)(iVar20 + 0x44),uVar17);
                          *(int *)(iVar22 + iVar14 + 0x48) = *(int *)(iVar22 + iVar14 + 0x48) + -1;
                        }
                        uVar12 = uVar12 + 1;
                        uVar17 = uVar17 - 1;
                        iVar23 = iVar23 + -4;
                        if (uVar2 == uVar12) break;
                        puVar18 = *(uint **)(iVar20 + 0x44);
                      }
                    }
                    iVar23 = *(int *)(iVar20 + 0x34);
                    if (iVar23 == 0) {
                      FUN_0019401c(iVar20);
                      iVar23 = *(int *)(iVar20 + 0x34);
                    }
                    *(int *)(iVar20 + 0x34) = iVar23 + 1;
                  }
                  if (uVar19 == uVar7) break;
                  puVar18 = *(uint **)(iVar16 + 0x40);
                }
              }
              ((int (*)())FUN_0016df8c)(param_1,iVar9);
            }
LAB_0016e574:
            iVar16 = *(int *)(iVar16 + 0x6c);
          } while (iVar16 != 0);
          iVar9 = param_1[0x61];
        }
      }
      uVar11 = uVar11 + 1;
      puVar13 = puVar13 + 1;
    } while ((int)uVar11 < iVar9);
  }
  puVar13 = param_1;
  do {
    iVar9 = puVar13[0x62];
    if ((iVar9 != 0) && (*(int *)(iVar9 + 0x2c) < (int)param_1[0xb])) {
      puVar13[0x62] = 0;
      for (iVar10 = *(int *)(iVar9 + 0x6c); iVar10 != 0; iVar10 = *(int *)(iVar10 + 0x6c)) {
        iVar22 = 4;
        iVar14 = iVar10;
        while (*(int *)(iVar14 + 0x48) < 1) {
          iVar14 = iVar14 + 4;
          iVar22 = iVar22 + -1;
          if (iVar22 == 0) goto LAB_0016e800;
        }
        uVar5 = FUN_0010445c(*(undefined4 *)(iVar10 + 0x38),*param_1,0);
        uVar6 = FUN_00105594(*(undefined4 *)(iVar9 + 0x38),1);
        FUN_00106004(uVar5,1,uVar6,0,*param_1);
        iVar14 = FUN_00165d3c(param_1,uVar5,iVar10 + 0xc,param_1[0xb]);
        puVar18 = *(uint **)(iVar10 + 0x40);
        uVar19 = 0;
        uVar11 = puVar18[1];
        if (0 < (int)uVar11) {
          while( true ) {
            if (uVar19 < *puVar18) {
              uVar7 = puVar18[1];
              if (uVar7 <= uVar19) {
                _memset((void *)(uVar7 * 4 + puVar18[2]),0,(uVar19 - uVar7) * 4 + 4);
                puVar18[1] = uVar19 + 1;
              }
              puVar8 = (undefined4 *)(uVar19 * 4 + puVar18[2]);
            }
            else {
              puVar8 = (undefined4 *)FUN_0019423c(puVar18,uVar19);
            }
            uVar19 = uVar19 + 1;
            piVar15 = (int *)*puVar8;
            iVar16 = 1;
            iVar22 = piVar15[1];
            if (*(int *)(iVar22 + 0x2c) < 0) {
              for (; iVar20 = (**(code **)(**(int **)(iVar22 + 0x38) + 0x14))(), iVar16 <= iVar20;
                  iVar16 = iVar16 + 1) {
                iVar20 = FUN_00105594(*(undefined4 *)(iVar22 + 0x38),iVar16);
                if (iVar20 == *(int *)(iVar10 + 0x38)) {
                  FUN_00106004(*(undefined4 *)(iVar22 + 0x38),iVar16,uVar5,0,*param_1);
                }
              }
              *piVar15 = iVar14;
              puVar18 = *(uint **)(iVar14 + 0x40);
              uVar7 = puVar18[1];
              if (uVar7 < *puVar18) {
                _memset((void *)(uVar7 * 4 + puVar18[2]),0,4);
                puVar8 = (undefined4 *)(uVar7 * 4 + puVar18[2]);
                puVar18[1] = uVar7 + 1;
              }
              else {
                puVar8 = (undefined4 *)FUN_0019423c(puVar18,uVar7);
              }
              *puVar8 = piVar15;
              iVar23 = 4;
              iVar16 = iVar14;
              iVar20 = iVar10;
              do {
                if (*(char *)(piVar15 + 6) != '\0') {
                  *(int *)(iVar16 + 0x48) = *(int *)(iVar16 + 0x48) + 1;
                  *(int *)(iVar20 + 0x48) = *(int *)(iVar20 + 0x48) + -1;
                }
                piVar15 = (int *)((int)piVar15 + 1);
                iVar16 = iVar16 + 4;
                iVar20 = iVar20 + 4;
                iVar23 = iVar23 + -1;
              } while (iVar23 != 0);
              iVar16 = *(int *)(iVar22 + 0x34);
              if (iVar16 == 0) {
                FUN_0019401c(iVar22);
                iVar16 = *(int *)(iVar22 + 0x34);
              }
              *(int *)(iVar22 + 0x34) = iVar16 + 1;
            }
            if (uVar11 == uVar19) break;
            puVar18 = *(uint **)(iVar10 + 0x40);
          }
        }
        ((int (*)())FUN_0016df8c)(param_1,iVar14);
LAB_0016e800: ;
      }
    }
    puVar13 = puVar13 + 1;
    if (param_1 + 2 == puVar13) {
      return;
    }
  } while( true );
code_r0x0016e264:
  iVar9 = iVar9 + 4;
  iVar20 = iVar20 + -1;
  if (iVar20 == 0) goto LAB_0016e574;
  goto LAB_0016e258;
}

/* FUN_0016e828 @ 0x16e828 (1640 bytes) */
int FUN_0016e828(param_1)
  int *param_1;
{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar7 = param_1[0xb];
  (**(code **)(*(int *)param_1[3] + 0x14))((int *)param_1[3],param_1[0xc]);
  (**(code **)(*(int *)param_1[2] + 0x14))();
  puVar4 = (undefined4 *)param_1[0xc];
  iVar10 = 5;
  param_1[0xb] = param_1[0xb] + 1;
  puVar3 = puVar4;
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  FUN_00193fa4(puVar4 + 5);
  iVar10 = param_1[0x15];
  for (iVar9 = *(int *)(param_1[0x15] + 8); iVar9 != 0; iVar9 = *(int *)(iVar9 + 8)) {
    FUN_0019401c(iVar10);
    FUN_00193f64(param_1 + 0x1f,iVar10);
    iVar10 = iVar9;
  }
  iVar10 = param_1[0xf];
  for (iVar9 = *(int *)(param_1[0xf] + 8); iVar9 != 0; iVar9 = *(int *)(iVar9 + 8)) {
    FUN_0019401c(iVar10);
    FUN_00193f64(param_1 + 0x1f,iVar10);
    iVar10 = iVar9;
  }
  param_1[0x44] = 0;
  param_1[0x48] = -1;
  param_1[0x47] = -1;
  iVar10 = param_1[0x21];
  if (*(int *)(iVar10 + 8) == 0) {
    iVar8 = -1;
    iVar9 = -1;
  }
  else {
    iVar8 = -1;
    iVar9 = -1;
    do {
      if (param_1[0x44] < *(int *)(iVar10 + 0x14)) {
        param_1[0x44] = *(int *)(iVar10 + 0x14);
      }
      iVar5 = (**(code **)(*(int *)param_1[3] + 0x20))
                        ((int *)param_1[3],*(undefined4 *)(iVar10 + 0x38));
      if ((iVar5 == 0) &&
         (iVar5 = (**(code **)(*(int *)param_1[3] + 0x24))
                            ((int *)param_1[3],*(undefined4 *)(iVar10 + 0x38)), iVar5 == 0)) {
        iVar5 = *(int *)(iVar10 + 0xc);
        if (*(int *)(iVar10 + 0xc) < param_1[0x47]) {
          iVar5 = param_1[0x47];
        }
        iVar9 = param_1[0xb];
        param_1[0x47] = iVar5;
      }
      else {
        iVar5 = *(int *)(iVar10 + 0xc);
        if (*(int *)(iVar10 + 0xc) < param_1[0x48]) {
          iVar5 = param_1[0x48];
        }
        iVar8 = param_1[0xb];
        param_1[0x48] = iVar5;
      }
      iVar10 = *(int *)(iVar10 + 8);
    } while (*(int *)(iVar10 + 8) != 0);
  }
  iVar10 = param_1[0x1b];
  if (*(int *)(iVar10 + 8) == 0) {
    bVar1 = iVar8 < 0;
    bVar2 = iVar9 < 0;
  }
  else {
    bVar1 = iVar8 < 0;
    bVar2 = iVar9 < 0;
    do {
      if (param_1[0x44] < *(int *)(iVar10 + 0x14)) {
        param_1[0x44] = *(int *)(iVar10 + 0x14);
      }
      iVar5 = (**(code **)(*(int *)param_1[3] + 0x20))
                        ((int *)param_1[3],*(undefined4 *)(iVar10 + 0x38));
      if ((iVar5 == 0) &&
         (iVar5 = (**(code **)(*(int *)param_1[3] + 0x24))
                            ((int *)param_1[3],*(undefined4 *)(iVar10 + 0x38)), iVar5 == 0)) {
        iVar5 = *(int *)(iVar10 + 0xc);
        if (*(int *)(iVar10 + 0xc) < param_1[0x47]) {
          iVar5 = param_1[0x47];
        }
        param_1[0x47] = iVar5;
        if (bVar2) {
          iVar5 = *(int *)(iVar10 + 0x30);
        }
        else {
          iVar5 = *(int *)(iVar10 + 0x30);
          if (iVar9 <= iVar5) goto LAB_0016eb08;
        }
        bVar2 = iVar5 < 0;
        iVar9 = iVar5;
      }
      else {
        iVar5 = *(int *)(iVar10 + 0xc);
        if (*(int *)(iVar10 + 0xc) < param_1[0x48]) {
          iVar5 = param_1[0x48];
        }
        param_1[0x48] = iVar5;
        if (bVar1) {
          iVar5 = *(int *)(iVar10 + 0x30);
        }
        else {
          iVar5 = *(int *)(iVar10 + 0x30);
          if (iVar8 <= iVar5) goto LAB_0016eb08;
        }
        bVar1 = iVar5 < 0;
        iVar8 = iVar5;
      }
LAB_0016eb08:
      iVar10 = *(int *)(iVar10 + 8);
    } while (*(int *)(iVar10 + 8) != 0);
  }
  iVar10 = param_1[0x40];
  iVar5 = *(int *)(iVar10 + 8);
  while (iVar5 != 0) {
    if (param_1[0x44] < *(int *)(iVar10 + 0x14)) {
      param_1[0x44] = *(int *)(iVar10 + 0x14);
    }
    iVar5 = *(int *)(iVar10 + 0xc);
    if (*(int *)(iVar10 + 0xc) < param_1[0x47]) {
      iVar5 = param_1[0x47];
    }
    param_1[0x47] = iVar5;
    if (bVar2) {
      iVar5 = *(int *)(iVar10 + 0x30);
LAB_0016eb7c:
      bVar2 = iVar5 < 0;
      iVar9 = iVar5;
    }
    else {
      iVar5 = *(int *)(iVar10 + 0x30);
      bVar2 = false;
      if (iVar5 < iVar9) goto LAB_0016eb7c;
    }
    iVar10 = *(int *)(iVar10 + 8);
    iVar5 = *(int *)(iVar10 + 8);
  }
  iVar10 = (**(code **)(*(int *)param_1[2] + 0x5c))();
  param_1[0x45] = iVar10;
  param_1[9] = (uint)(param_1[0x44] <= iVar10);
  if (bVar2) {
    if (bVar1) goto LAB_0016ec14;
  }
  else if (((bVar1) || (param_1[0x46] == 0)) || (iVar9 <= iVar8)) {
    if (iVar9 <= param_1[0xb]) {
      iVar9 = param_1[0xb];
    }
    param_1[0xb] = iVar9;
    goto LAB_0016ec14;
  }
  if (iVar8 <= param_1[0xb]) {
    iVar8 = param_1[0xb];
  }
  param_1[0xb] = iVar8;
LAB_0016ec14:
  iVar10 = *(int *)(param_1[0x21] + 8);
  if (iVar10 == 0) {
    iVar9 = 0;
    iVar8 = 0;
  }
  else {
    iVar9 = 0;
    iVar8 = 0;
    iVar5 = param_1[0x21];
    do {
      iVar6 = iVar10;
      FUN_0019401c(iVar5);
      ((int (*)())FUN_0016df8c)(param_1,iVar5);
      iVar10 = (**(code **)(*(int *)param_1[3] + 0x20))
                         ((int *)param_1[3],*(undefined4 *)(iVar5 + 0x38));
      if ((iVar10 != 0) ||
         (iVar10 = (**(code **)(*(int *)param_1[3] + 0x24))
                             ((int *)param_1[3],*(undefined4 *)(iVar5 + 0x38)), iVar10 != 0)) {
        if (iVar8 < *(int *)(iVar5 + 0x14)) {
          iVar8 = *(int *)(iVar5 + 0x14);
        }
        if (*(int *)(iVar5 + 0xc) == param_1[0x48]) {
          iVar9 = iVar9 + 1;
        }
      }
      iVar10 = *(int *)(iVar6 + 8);
      iVar5 = iVar6;
    } while (iVar10 != 0);
  }
  iVar10 = param_1[0x1b];
  for (iVar5 = *(int *)(param_1[0x1b] + 8); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
    iVar6 = FUN_00166ba8(param_1,iVar10);
    if (iVar6 != 0) {
      FUN_0019401c(iVar10);
      ((int (*)())FUN_0016df8c)(param_1,iVar10);
      iVar6 = (**(code **)(*(int *)param_1[3] + 0x20))
                        ((int *)param_1[3],*(undefined4 *)(iVar10 + 0x38));
      if ((iVar6 != 0) ||
         (iVar6 = (**(code **)(*(int *)param_1[3] + 0x24))
                            ((int *)param_1[3],*(undefined4 *)(iVar10 + 0x38)), iVar6 != 0)) {
        if (iVar8 < *(int *)(iVar10 + 0x14)) {
          iVar8 = *(int *)(iVar10 + 0x14);
        }
        if (*(int *)(iVar10 + 0xc) == param_1[0x48]) {
          iVar9 = iVar9 + 1;
        }
      }
    }
    iVar10 = iVar5;
  }
  iVar10 = FUN_00193f08(param_1 + 0x3e);
  if ((((iVar10 == 0) && (iVar10 = FUN_00193f08(param_1 + 0x13), iVar10 != 0)) &&
      (iVar10 = FUN_00193f08(param_1 + 0xd), iVar10 != 0)) &&
     (iVar10 = FUN_00194034(param_1 + 0x3e), iVar10 == param_1[0x3d])) {
    iVar10 = param_1[0x40];
    for (iVar5 = *(int *)(param_1[0x40] + 8); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
      FUN_0019401c(iVar10);
      *(undefined4 *)(iVar10 + 0x68) = 0;
      FUN_00193f64(param_1 + 0x13,iVar10);
      iVar10 = iVar5;
    }
  }
  iVar10 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0xd4))();
  if ((iVar10 != 0) && (iVar10 = (**(code **)(*(int *)param_1[2] + 0x18))(), iVar10 != 0)) {
    ((int (*)())FUN_0016e1a4)(param_1);
  }
  FUN_00164a74(param_1,iVar9,iVar8);
  return param_1[0xb] - iVar7;
}

/* FUN_0016ee90 @ 0x16ee90 (284 bytes) */
int FUN_0016ee90(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*(int *)param_1[2] + 0x50))();
  if (iVar1 == 0) goto LAB_0016ef60;
  iVar1 = FUN_000e07dc(*param_1,0x28);
  if (iVar1 == 0) {
LAB_0016ef04:
    iVar2 = 0;
  }
  else {
    iVar2 = 1;
    iVar1 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],param_2);
    if (iVar1 == 0) goto LAB_0016ef04;
  }
  iVar1 = (**(code **)(*(int *)param_1[2] + 0x4c))
                    ((int *)param_1[2],*(undefined4 *)(param_2 + 0x38));
  if ((iVar1 != *(int *)(param_2 + 0x58)) || (iVar2 != *(int *)(param_2 + 0x5c))) {
    ((int (*)())FUN_0017212c)(param_1[2],param_2);
    *(int *)(param_2 + 0x58) = iVar1;
    *(int *)(param_2 + 0x5c) = iVar2;
    ((int (*)())FUN_00172078)(param_1[2],param_2);
  }
LAB_0016ef60:
  iVar1 = FUN_00166ba8(param_1,param_2);
  if (iVar1 != 0) {
    ((int (*)())FUN_0016df8c)(param_1,param_2);
    return;
  }
  FUN_00193f64(param_1 + 0x19,param_2);
  return;
}

/* FUN_0016ff54 @ 0x16ff54 (6540 bytes) */
int FUN_0016ff54(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  undefined4 *puVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  uint *puVar26;
  uint uVar27;
  undefined4 uVar28;
  int *piVar29;
  undefined4 uVar30;
  int iVar31;
  int *piStack00000018;
  uint local_78;
  uint local_74;
  int local_70;
  undefined4 local_6c;
  uint local_68;
  uint local_64 [6];
  undefined4 in_stack_ffffffb8;
  undefined4 in_stack_ffffffbc;
  
  iVar4 = param_1[0x46];
  if (iVar4 == 0) {
    iVar25 = param_1[0x15];
  }
  else {
    iVar25 = param_1[0xf];
  }
  bVar1 = true;
  iVar20 = 0;
  iVar18 = 0;
  iVar19 = 0;
  while (*(int *)(iVar25 + 8) != 0) {
    piVar9 = *(int **)(iVar25 + 0x38);
    if ((iVar4 == 0) && (param_2 < *(int *)(iVar25 + 0x10))) goto LAB_00170868;
    iVar4 = FUN_001045e4(piVar9);
    if (iVar4 == 0) {
      iVar4 = FUN_00104644(piVar9);
      if (iVar4 != 0) {
        iVar4 = ((int (*)())FUN_0016dd04)(param_1,iVar25);
        iVar18 = iVar18 + 1;
        goto joined_r0x00170058;
      }
      iVar4 = *(int *)(iVar25 + 0x60);
      iVar19 = iVar19 + 1;
      if (iVar4 == 0) {
LAB_0017036c:
        iVar4 = FUN_000e07dc(*param_1,0x25);
        if ((iVar4 != 0) &&
           (((((*(int *)(iVar25 + 0x60) == 0 || (*(int *)(*(int *)(iVar25 + 0x60) + 4) < 0)) &&
              (piVar9[0x26] == 1)) && ((*(int *)(iVar25 + 100) == 0 && ((piVar9[5] & 0x40U) == 0))))
            && ((piVar9[5] & 0x20U) == 0)))) {
          iVar15 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x7c))
                             (*(int **)(*param_1 + 0x30c),piVar9);
          iVar4 = DAT_001b0194;
          if (iVar15 != 0) {
            if (*(int **)(iVar25 + 0x60) == (int *)0x0) {
              iVar4 = piVar9[3];
            }
            else {
              iVar4 = **(int **)(iVar25 + 0x60);
            }
          }
          iVar4 = FUN_00167b68(param_1,1,iVar4);
          iVar15 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x138))();
          if ((iVar4 < 0) || (iVar15 + 4 <= iVar4)) {
            if ((*(int *)(iVar25 + 0x58) == 2) &&
               (iVar4 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],iVar25),
               iVar4 != 0)) {
              ((int (*)())FUN_0017212c)(param_1[2],iVar25);
              (**(code **)(*(int *)param_1[2] + 0x38))((int *)param_1[2],iVar25);
              ((int (*)())FUN_00172078)(param_1[2],iVar25);
            }
            piVar9[0x26] = 0;
          }
        }
        iVar4 = (**(code **)(*(int *)param_1[3] + 0xc))((int *)param_1[3],piVar9);
        if (iVar4 == 0) {
          iVar4 = *(int *)(iVar25 + 8);
          bVar1 = false;
          FUN_0019401c(iVar25);
          FUN_00193f64(param_1 + 0x1f,iVar25);
          iVar25 = iVar4;
        }
        else {
          if ((*(uint *)(*(int *)(*param_1 + 0x30c) + 8) & 0x200) == 0) {
            iVar4 = (**(code **)(*(int *)param_1[2] + 0xc))((int *)param_1[2],piVar9);
            if (iVar4 != 0) goto LAB_001705f8;
            iVar4 = (**(code **)(*(int *)param_1[2] + 0x24))();
            if (iVar4 != 0) {
              iVar4 = FUN_00167ef4(param_1,iVar25);
              if (iVar4 != 0) {
                return iVar4;
              }
              goto LAB_001705f8;
            }
            iVar4 = FUN_000e07dc(*param_1,0x28);
            if (iVar4 != 0) {
              iVar4 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],iVar25);
              if ((iVar4 != 0) &&
                 (iVar4 = (**(code **)(*(int *)param_1[2] + 0x2c))
                                    ((int *)param_1[2],iVar25,param_1 + 0x4d), iVar4 != 0))
              goto LAB_001705f8;
              iVar12 = 0;
              iVar15 = 0;
              iVar4 = 0;
              iVar13 = 0;
              do {
                iVar16 = *(int *)(param_1[0xc] + iVar13 * 4);
                if (iVar16 != 0) {
                  iVar12 = iVar12 + 1;
                  iVar31 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],iVar16);
                  iVar4 = iVar16;
                  if (iVar31 != 0) {
                    iVar15 = iVar15 + 1;
                  }
                }
                bVar1 = iVar13 != 4;
                iVar13 = iVar13 + 1;
              } while (bVar1);
              if ((iVar12 == 1) && (iVar15 == 1)) {
                (**(code **)(*(int *)param_1[2] + 8))();
                iVar15 = (**(code **)(*(int *)param_1[2] + 0xc))
                                   ((int *)param_1[2],*(undefined4 *)(iVar25 + 0x38));
                if (iVar15 != 0) {
                  (**(code **)(*(int *)param_1[2] + 0x10))
                            ((int *)param_1[2],*(undefined4 *)(iVar25 + 0x38));
                  iVar15 = (**(code **)(*(int *)param_1[2] + 0x2c))
                                     ((int *)param_1[2],iVar4,param_1 + 0x4d);
                  if (iVar15 != 0) {
                    (**(code **)(*(int *)param_1[2] + 8))();
                    (**(code **)(*(int *)param_1[2] + 0x10))
                              ((int *)param_1[2],*(undefined4 *)(iVar4 + 0x38));
                    FUN_0019401c(iVar25);
                    return iVar25;
                  }
                }
                (**(code **)(*(int *)param_1[2] + 8))();
                (**(code **)(*(int *)param_1[2] + 0x10))
                          ((int *)param_1[2],*(undefined4 *)(iVar4 + 0x38));
              }
            }
          }
          else {
            iVar4 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],iVar25);
            if ((iVar4 == 0) || (iVar4 = FUN_000e07dc(*param_1,0x28), iVar4 == 0)) {
              iVar4 = (**(code **)(*(int *)param_1[2] + 0xc))((int *)param_1[2],piVar9);
            }
            else {
              iVar4 = (**(code **)(*(int *)param_1[2] + 0x2c))
                                ((int *)param_1[2],iVar25,param_1 + 0x4d);
            }
            if (iVar4 != 0) goto LAB_001705f8;
          }
          iVar15 = *(int *)(iVar25 + 8);
          FUN_0019401c(iVar25);
          iVar4 = FUN_000e07dc(*param_1,0x27);
          if ((((iVar4 != 0) && (iVar4 = FUN_000e07dc(*param_1,0x2b), iVar4 == 0)) &&
              (param_1[0x46] == 0)) &&
             ((*(int *)(iVar25 + 0x60) == 0 || ((*(uint *)(param_1[1] + 0x30) & 0x2000) != 0)))) {
            iVar4 = (**(code **)(*(int *)param_1[2] + 0x3c))((int *)param_1[2],piVar9);
            if (iVar4 - 1U < 3) {
              bVar1 = false;
              FUN_00193f64(param_1 + (iVar4 - 1U) * 6 + 0x2b,iVar25);
              iVar25 = iVar15;
              goto LAB_00170838;
            }
          }
          FUN_00193f64(param_1 + 0x1f,iVar25);
          bVar1 = false;
          iVar25 = iVar15;
        }
      }
      else {
        if (-1 < *(int *)(iVar4 + 4)) {
          iVar4 = FUN_000e07dc(*param_1,0x25);
          if (iVar4 != 0) {
            if (((piVar9[0x20] != 0) && (iVar4 = FUN_00126760(piVar9[0x26]), iVar4 != 0)) &&
               ((piVar9[5] & 2U) == 0)) {
              (**(code **)(*piVar9 + 0x50))(piVar9);
            }
            iVar12 = 4;
            iVar15 = *(int *)(*(int *)(iVar25 + 0x60) + 4);
            iVar4 = 0;
            piVar11 = param_1;
            do {
              iVar13 = iVar4 << 2;
              iVar16 = *(int *)(iVar15 * 4 + piVar11[0x4d]);
              uVar3 = 0;
              if (iVar16 != 0) {
                iVar13 = iVar4 * 4;
                uVar3 = *(undefined4 *)(iVar13 + iVar16 + 0x48);
              }
              *(undefined4 *)((int)local_64 + iVar13) = uVar3;
              iVar4 = iVar4 + 1;
              piVar11 = piVar11 + 1;
              iVar12 = iVar12 + -1;
            } while (iVar12 != 0);
            puVar26 = *(uint **)(iVar25 + 0x44);
            uVar22 = 0;
            uVar14 = puVar26[1];
            if (0 < (int)uVar14) {
              while( true ) {
                if (uVar22 < *puVar26) {
                  uVar24 = puVar26[1];
                  if (uVar24 <= uVar22) {
                    _memset((void *)(uVar24 * 4 + puVar26[2]),0,(uVar22 - uVar24) * 4 + 4);
                    puVar26[1] = uVar22 + 1;
                  }
                  puVar17 = (undefined4 *)(uVar22 * 4 + puVar26[2]);
                }
                else {
                  puVar17 = (undefined4 *)FUN_0019423c(puVar26,uVar22);
                }
                uVar22 = uVar22 + 1;
                piVar11 = (int *)*puVar17;
                iVar4 = *piVar11;
                if (((((piVar11[2] == 0) && (piVar29 = *(int **)(iVar4 + 0x38), piVar29[0x20] != 0))
                     && ((iVar12 = FUN_00126760(piVar29[0x26]), iVar12 != 0 &&
                         (((piVar29[5] & 2U) == 0 &&
                          (iVar12 = (**(code **)(*piVar29 + 0x50))(piVar29), iVar12 == 0)))))) &&
                    (iVar4 = *(int *)(iVar4 + 0x38), (*(uint *)(iVar4 + 0x14) & 0x40) != 0)) &&
                   (iVar15 == *(int *)(iVar4 + 0x94))) {
                  iVar12 = 4;
                  iVar4 = 0;
                  do {
                    if (*(char *)(piVar11 + 6) != '\0') {
                      *(int *)((int)local_64 + iVar4) = *(int *)((int)local_64 + iVar4) + -1;
                    }
                    piVar11 = (int *)((int)piVar11 + 1);
                    iVar4 = iVar4 + 4;
                    iVar12 = iVar12 + -1;
                  } while (iVar12 != 0);
                }
                if (uVar14 == uVar22) break;
                puVar26 = *(uint **)(iVar25 + 0x44);
              }
            }
            iVar4 = 0;
            do {
              iVar15 = FUN_001054ec(piVar9,0);
              if ((*(char *)(iVar4 + iVar15 + 0x10) != '\x01') && (0 < (int)local_64[iVar4]))
              goto LAB_00170968;
              bVar2 = iVar4 != 3;
              iVar4 = iVar4 + 1;
            } while (bVar2);
          }
          iVar4 = *(int *)(iVar25 + 0x60);
          if (iVar4 == 0) goto LAB_0017036c;
        }
        if (*(int *)(iVar4 + 8) == 0) goto LAB_0017036c;
        if (*(int *)(*(int *)(iVar4 + 8) + 0x2c) == param_1[0xb]) {
          iVar15 = FUN_001054ec(piVar9,0);
          pcVar5 = (char *)(iVar4 + 0xc);
          iVar4 = 0;
          local_68 = *(uint *)(iVar15 + 0x10);
          iVar15 = 4;
          do {
            if ((*pcVar5 != '\x01') && (*(char *)((int)local_64 + iVar4 + -4) != '\x01'))
            goto LAB_00170320;
            iVar4 = iVar4 + 1;
            pcVar5 = pcVar5 + 1;
            iVar15 = iVar15 + -1;
          } while (iVar15 != 0);
          iVar4 = *(int *)(iVar25 + 0x60);
        }
        iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 8) + 0x38) + 0x98);
        if (iVar4 == piVar9[0x26]) goto LAB_0017036c;
        if (piVar9[0x26] == 1) {
          piVar9[0x26] = 0;
          goto LAB_0017036c;
        }
        if (((piVar9[5] & 0x20U) == 0) && (iVar4 == 1)) {
          piVar9[0x26] = 1;
          goto LAB_0017036c;
        }
LAB_00170968:
        iVar25 = *(int *)(iVar25 + 8);
      }
    }
    else {
      iVar4 = ((int (*)())FUN_0016d538)(param_1,iVar25);
      iVar20 = iVar20 + 1;
joined_r0x00170058:
      if (iVar4 != 0) {
LAB_001705f8:
        FUN_0019401c(iVar25);
        return iVar25;
      }
LAB_00170320:
      iVar4 = *(int *)(iVar25 + 8);
      FUN_0019401c(iVar25);
      FUN_00193f64(param_1 + 0x1f,iVar25);
      iVar25 = iVar4;
    }
LAB_00170838:
    iVar4 = param_1[0x46];
  }
  if (iVar4 == 0) {
LAB_00170868:
    if (((0 < iVar20) || (0 < iVar18)) &&
       ((iVar19 == 0 && (iVar4 = FUN_00193f08(param_1 + 0x19), iVar4 != 0)))) {
      iVar4 = 5;
      piVar9 = (int *)param_1[0xc];
      do {
        if (*piVar9 != 0) goto LAB_001708c4;
        piVar9 = piVar9 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      iVar4 = FUN_00193f08((int *)param_1[0xc] + 5);
      if (iVar4 != 0) {
        if (0 >= iVar20) {
          if (iVar18 < 1) {
            return 0;
          }
          (**(code **)(*(int *)param_1[2] + 0x1c))();
          return 0;
        }
        iVar4 = param_1[0x61];
        piStack00000018 = param_1;
        if (0 < iVar4) {
          uVar14 = 0;
          do {
            local_64[1] = param_1[0x5c];
            local_64[0] = uVar14 + (((int)uVar14 >> 2) +
                                   (uint)((int)uVar14 < 0 && (uVar14 & 3) != 0)) * -4;
            iVar25 = *(int *)(local_64[1] + 0x6c);
            if (iVar25 != 0) {
              iVar4 = local_64[0] * 4;
              do {
                iVar18 = FUN_001054ec(*(undefined4 *)(iVar25 + 0x38),1);
                if (*(int *)(iVar18 + 0x10) == *(int *)(PTR_DAT_001e8b8c + iVar4)) {
                  iVar20 = 4;
                  iVar18 = iVar25;
LAB_0016f038:
                  if (*(int *)(iVar18 + 0x48) < 1) goto code_r0x0016f044;
                  FUN_000f31f8(&local_68,DAT_001b0190,*(undefined4 *)(*(int *)(iVar25 + 0x38) + 0xc)
                              );
                  iVar18 = FUN_00167e1c(piStack00000018,*(undefined4 *)(iVar25 + 0x38),local_68,
                                        piStack00000018[0xb],iVar25 + 0xc);
                  puVar26 = *(uint **)(iVar25 + 0x40);
                  uVar22 = puVar26[1];
                  uVar24 = uVar22 - 1;
                  if (-1 < (int)uVar24) {
                    iVar20 = uVar24 * 4;
                    uVar23 = 0;
                    while( true ) {
                      if (uVar24 < *puVar26) {
                        uVar10 = puVar26[1];
                        if (uVar10 <= uVar24) {
                          _memset((void *)(uVar10 * 4 + puVar26[2]),0,(uVar24 - uVar10) * 4 + 4);
                          puVar26[1] = uVar24 + 1;
                        }
                        puVar17 = (undefined4 *)(iVar20 + puVar26[2]);
                      }
                      else {
                        puVar17 = (undefined4 *)FUN_0019423c(puVar26,uVar24);
                      }
                      piVar9 = (int *)*puVar17;
                      iVar15 = 1;
                      iVar19 = piVar9[1];
                      if (*(int *)(iVar19 + 0x2c) < 0) {
                        for (; iVar12 = (**(code **)(**(int **)(iVar19 + 0x38) + 0x14))(),
                            iVar15 <= iVar12; iVar15 = iVar15 + 1) {
                          iVar12 = FUN_00105594(*(undefined4 *)(iVar19 + 0x38),iVar15);
                          if (iVar12 == *(int *)(iVar25 + 0x38)) {
                            FUN_00106004(*(undefined4 *)(iVar19 + 0x38),iVar15,
                                         *(undefined4 *)(iVar18 + 0x38),0,*piStack00000018);
                          }
                        }
                        *piVar9 = iVar18;
                        FUN_00194208(*(undefined4 *)(iVar25 + 0x40),uVar24);
                        puVar26 = *(uint **)(iVar18 + 0x40);
                        uVar10 = puVar26[1];
                        if (uVar10 < *puVar26) {
                          _memset((void *)(uVar10 * 4 + puVar26[2]),0,4);
                          puVar17 = (undefined4 *)(uVar10 * 4 + puVar26[2]);
                          puVar26[1] = uVar10 + 1;
                        }
                        else {
                          puVar17 = (undefined4 *)FUN_0019423c(puVar26,uVar10);
                        }
                        *puVar17 = piVar9;
                        iVar15 = *(int *)(iVar19 + 0x34);
                        if (iVar15 == 0) {
                          FUN_0019401c(iVar19);
                          iVar15 = *(int *)(iVar19 + 0x34);
                        }
                        *(int *)(iVar19 + 0x34) = iVar15 + 1;
                        iVar13 = 4;
                        iVar15 = iVar18;
                        iVar12 = iVar25;
                        do {
                          if (*(char *)(piVar9 + 6) != '\0') {
                            *(int *)(iVar15 + 0x48) = *(int *)(iVar15 + 0x48) + 1;
                            *(int *)(iVar12 + 0x48) = *(int *)(iVar12 + 0x48) + -1;
                          }
                          piVar9 = (int *)((int)piVar9 + 1);
                          iVar15 = iVar15 + 4;
                          iVar12 = iVar12 + 4;
                          iVar13 = iVar13 + -1;
                        } while (iVar13 != 0);
                        puVar26 = *(uint **)(iVar19 + 0x44);
                        uVar10 = puVar26[1];
                        uVar27 = uVar10 - 1;
                        if (-1 < (int)uVar27) {
                          iVar15 = uVar27 * 4;
                          uVar21 = 0;
                          while( true ) {
                            if (uVar27 < *puVar26) {
                              uVar6 = puVar26[1];
                              if (uVar6 <= uVar27) {
                                _memset((void *)(uVar6 * 4 + puVar26[2]),0,(uVar27 - uVar6) * 4 + 4)
                                ;
                                puVar26[1] = uVar27 + 1;
                              }
                              puVar17 = (undefined4 *)(iVar15 + puVar26[2]);
                            }
                            else {
                              puVar17 = (undefined4 *)FUN_0019423c(puVar26,uVar27);
                            }
                            piVar9 = (int *)*puVar17;
                            if ((local_64[1] == *piVar9) &&
                               (*(char *)((int)piVar9 + local_64[0] + 0x18) != '\0')) {
                              FUN_00194208(*(undefined4 *)(iVar19 + 0x44),uVar27);
                              piVar9[1] = iVar18;
                              puVar26 = *(uint **)(iVar18 + 0x44);
                              uVar6 = puVar26[1];
                              if (uVar6 < *puVar26) {
                                _memset((void *)(uVar6 * 4 + puVar26[2]),0,4);
                                puVar17 = (undefined4 *)(uVar6 * 4 + puVar26[2]);
                                puVar26[1] = uVar6 + 1;
                              }
                              else {
                                puVar17 = (undefined4 *)FUN_0019423c(puVar26,uVar6);
                              }
                              *puVar17 = piVar9;
                            }
                            uVar21 = uVar21 + 1;
                            uVar27 = uVar27 - 1;
                            iVar15 = iVar15 + -4;
                            if (uVar10 == uVar21) break;
                            puVar26 = *(uint **)(iVar19 + 0x44);
                          }
                        }
                      }
                      uVar23 = uVar23 + 1;
                      uVar24 = uVar24 - 1;
                      iVar20 = iVar20 + -4;
                      if (uVar22 == uVar23) break;
                      puVar26 = *(uint **)(iVar25 + 0x40);
                    }
                  }
                  FUN_00165b7c(piStack00000018,iVar25,iVar18,1,0,
                               *(undefined4 *)(*(int *)(iVar18 + 0x38) + 0xc));
                  uVar3 = *(undefined4 *)(iVar25 + 0x38);
                  *(int *)(iVar18 + 0x34) = *(int *)(iVar18 + 0x34) + -1;
                  iVar19 = *(int *)(iVar25 + 0x2c);
                  iVar20 = FUN_00164e7c(piStack00000018,uVar3,*(undefined4 *)(iVar18 + 0x38),0,1,0);
                  iVar19 = iVar19 + iVar20;
                  if (*(int *)(iVar18 + 0x30) < iVar19) {
                    *(int *)(iVar18 + 0x30) = iVar19;
                  }
                  ((int (*)())FUN_0016ee90)(piStack00000018,iVar18);
                }
LAB_0016f3cc:
                iVar25 = *(int *)(iVar25 + 0x6c);
              } while (iVar25 != 0);
              iVar4 = piStack00000018[0x61];
            }
            uVar14 = uVar14 + 1;
            param_1 = param_1 + 1;
          } while ((int)uVar14 < iVar4);
        }
        piVar9 = piStack00000018;
        iVar4 = FUN_00193f08(piStack00000018 + 0x13);
        if (iVar4 == 0) {
          iVar25 = piVar9[0x15];
          iVar4 = (**(code **)(*(int *)piStack00000018[2] + 0xc))
                            ((int *)piStack00000018[2],*(undefined4 *)(iVar25 + 0x38));
          if ((iVar4 != 0) &&
             (iVar4 = (**(code **)(*(int *)piStack00000018[3] + 0xc))
                                ((int *)piStack00000018[3],*(undefined4 *)(iVar25 + 0x38)),
             iVar4 != 0)) {
            FUN_0019401c(iVar25);
            return iVar25;
          }
        }
        return 0;
      }
    }
LAB_001708c4:
    iVar4 = FUN_00193f08(param_1 + 0x13);
  }
  else {
    iVar4 = FUN_00193f08(param_1 + 0xd);
  }
  if ((iVar4 != 0) || (!bVar1)) {
    return 0;
  }
  if (param_1[0x46] == 0) {
    iVar4 = param_1[0x15];
  }
  else {
    iVar4 = param_1[0xf];
  }
  do {
    if (*(int *)(iVar4 + 8) == 0) {
LAB_0016f574:
      iVar4 = (**(code **)(*(int *)param_1[2] + 0x24))();
      if (iVar4 != 0) {
        (**(code **)(*(int *)param_1[2] + 0x7c))();
      }
      return 0;
    }
    if ((param_1[0x46] == 0) && (param_2 < *(int *)(iVar4 + 0x10))) {
      return 0;
    }
    iVar25 = (**(code **)(*(int *)param_1[2] + 0xc))
                       ((int *)param_1[2],*(undefined4 *)(iVar4 + 0x38));
    if (iVar25 == 0) {
      iVar25 = (**(code **)(*(int *)param_1[2] + 0x24))();
      if (iVar25 != 0) {
        iVar25 = FUN_00167ef4(param_1,iVar4);
        if (iVar25 != 0) {
          return iVar25;
        }
        goto LAB_0016f530;
      }
    }
    else {
LAB_0016f530:
      iVar25 = (**(code **)(*(int *)param_1[3] + 0xc))
                         ((int *)param_1[3],*(undefined4 *)(iVar4 + 0x38));
      if (iVar25 != 0) {
        if (*(int *)(iVar4 + 8) != 0) {
          local_6c = *(undefined4 *)(*param_1 + 0x378);
          local_74 = 0;
          local_78 = 2;
          local_70 = FUN_00193e18(local_6c,8);
          local_64[2] = *(undefined4 *)(*param_1 + 0x378);
          local_64[0] = 0;
          local_68 = 2;
          local_64[1] = FUN_00193e18(local_64[2],8);
          uVar7 = *(undefined4 *)(*param_1 + 0x378);
          local_64[3] = 2;
          local_64[4] = 0;
          local_64[5] = FUN_00193e18(uVar7,8);
          uVar30 = *(undefined4 *)(*param_1 + 0x378);
          iVar25 = *(int *)(iVar4 + 0x60);
          puVar8 = (undefined4 *)FUN_00193e18(uVar30,0x2c);
          uVar14 = local_64[4];
          uVar28 = DAT_001b01a8;
          uVar3 = DAT_001b0198;
          *puVar8 = uVar30;
          puVar8[4] = uVar3;
          puVar8[1] = uVar28;
          puVar8[2] = 0xffffffff;
          puVar8[5] = 0;
          puVar8[6] = 0x7fffffff;
          iVar18 = 4;
          puVar8[3] = 0;
          puVar17 = puVar8 + 1;
          do {
            puVar17[6] = 0;
            puVar17 = puVar17 + 1;
            iVar18 = iVar18 + -1;
          } while (iVar18 != 0);
          *(undefined4 **)(iVar4 + 0x60) = puVar8 + 1;
          puVar8[5] = 1;
          uVar3 = *(undefined4 *)(*(int *)(iVar4 + 0x38) + 0xc);
          puVar17 = *(undefined4 **)(iVar4 + 0x60);
          *(int *)(iVar25 + 0x10) = *(int *)(iVar25 + 0x10) + -1;
          *puVar17 = uVar3;
          if (local_64[4] < local_64[3]) {
            iVar18 = local_64[4] * 4;
            _memset((void *)(iVar18 + local_64[5]),0,4);
            local_64[4] = uVar14 + 1;
            piVar9 = (int *)(iVar18 + local_64[5]);
          }
          else {
            piVar9 = (int *)FUN_0019423c(local_64 + 3,local_64[4]);
          }
          *piVar9 = iVar4;
LAB_0016fcc0:
          do {
            uVar14 = local_74;
            if (local_64[4] == 0) {
              if (0 < (int)local_74) {
                uVar24 = 0;
                uVar22 = 1;
                iVar25 = 0;
                do {
                  if (uVar24 < local_78) {
                    if (local_74 <= uVar24) {
                      _memset((void *)(local_74 * 4 + local_70),0,(uVar24 - local_74) * 4 + 4);
                      local_74 = uVar22;
                    }
                    piVar9 = (int *)(iVar25 + local_70);
                  }
                  else {
                    piVar9 = (int *)FUN_0019423c(&local_78,uVar24);
                  }
                  iVar20 = *piVar9;
                  ((int (*)())FUN_0017212c)(param_1[2],iVar20);
                  iVar18 = *(int *)(iVar20 + 0x38);
                  FUN_000f31f8(&STACKARG(0xffffffb8),DAT_001b0190,*(undefined4 *)(iVar18 + 0xc));
                  uVar3 = DAT_001b01a4;
                  *(undefined4 *)(iVar18 + 0x9c) = in_stack_ffffffb8;
                  iVar18 = *(int *)(iVar20 + 0x38);
                  FUN_000f3340(&STACKARG(0xffffffbc),uVar3,*(undefined4 *)(iVar18 + 0xc));
                  iVar18 = FUN_001054ec(iVar18,1);
                  *(undefined4 *)(iVar18 + 0x10) = in_stack_ffffffbc;
                  uVar3 = (**(code **)(*(int *)param_1[2] + 0x4c))
                                    ((int *)param_1[2],*(undefined4 *)(iVar20 + 0x38));
                  *(undefined4 *)(iVar20 + 0x58) = uVar3;
                  if (uVar24 < local_68) {
                    if (local_64[0] <= uVar24) {
                      _memset((void *)(local_64[0] * 4 + local_64[1]),0,
                              (uVar24 - local_64[0]) * 4 + 4);
                      local_64[0] = uVar22;
                    }
                    puVar17 = (undefined4 *)(iVar25 + local_64[1]);
                  }
                  else {
                    puVar17 = (undefined4 *)FUN_0019423c(&local_68,uVar24);
                  }
                  FUN_00165b7c(param_1,*puVar17,iVar20,1,0,
                               *(undefined4 *)(*(int *)(iVar20 + 0x38) + 0xc));
                  ((int (*)())FUN_00172078)(param_1[2],iVar20);
                  if (uVar24 < local_68) {
                    if (local_64[0] <= uVar24) {
                      _memset((void *)(local_64[0] * 4 + local_64[1]),0,
                              (uVar24 - local_64[0]) * 4 + 4);
                      local_64[0] = uVar22;
                    }
                    piVar9 = (int *)(iVar25 + local_64[1]);
                  }
                  else {
                    piVar9 = (int *)FUN_0019423c(&local_68,uVar24);
                  }
                  if (-1 < *(int *)(*piVar9 + 0x2c)) {
                    *(int *)(iVar20 + 0x34) = *(int *)(iVar20 + 0x34) + -1;
                    ((int (*)())FUN_0016ee90)(param_1,iVar20);
                  }
                  uVar24 = uVar24 + 1;
                  uVar22 = uVar22 + 1;
                  iVar25 = iVar25 + 4;
                } while (uVar14 != uVar24);
              }
              FUN_0019401c(iVar4);
              FUN_00193cc0(uVar7,local_64[5]);
              FUN_00193cc0(local_64[2],local_64[1]);
              FUN_00193cc0(local_6c,local_70);
              return iVar4;
            }
            uVar14 = local_64[4] - 1;
            piVar9 = (int *)0x0;
            if (uVar14 < local_64[4]) {
              piVar9 = (int *)(uVar14 * 4 + local_64[5]);
            }
            iVar18 = *piVar9;
            FUN_00194208(local_64 + 3,uVar14);
            puVar26 = *(uint **)(iVar18 + 0x40);
            uVar22 = 0;
            uVar14 = puVar26[1];
          } while ((int)uVar14 < 1);
          do {
            if (uVar22 < *puVar26) {
              uVar24 = puVar26[1];
              if (uVar24 <= uVar22) {
                _memset((void *)(uVar24 * 4 + puVar26[2]),0,(uVar22 - uVar24) * 4 + 4);
                puVar26[1] = uVar22 + 1;
              }
              piVar9 = (int *)(uVar22 * 4 + puVar26[2]);
            }
            else {
              piVar9 = (int *)FUN_0019423c(puVar26,uVar22);
            }
            iVar20 = *piVar9;
            if (*(int *)(iVar20 + 8) == 0) {
              iVar19 = *(int *)(iVar20 + 4);
              uVar23 = 0;
              puVar26 = *(uint **)(iVar19 + 0x44);
              uVar24 = puVar26[1];
              if (0 < (int)uVar24) {
                do {
                  if (uVar23 < *puVar26) {
                    uVar10 = puVar26[1];
                    if (uVar10 <= uVar23) {
                      _memset((void *)(uVar10 * 4 + puVar26[2]),0,(uVar23 - uVar10) * 4 + 4);
                      puVar26[1] = uVar23 + 1;
                    }
                    puVar17 = (undefined4 *)(uVar23 * 4 + puVar26[2]);
                  }
                  else {
                    puVar17 = (undefined4 *)FUN_0019423c(puVar26,uVar23);
                  }
                  piVar9 = (int *)*puVar17;
                  if ((((piVar9[2] == 0) && (iVar15 = *piVar9, iVar18 != iVar15)) &&
                      (piVar9[4] == *(int *)(iVar20 + 0x10))) &&
                     (piVar9[5] == *(int *)(iVar20 + 0x14))) {
                    if (((*(int *)(iVar15 + 0x2c) < 0) ||
                        ((*(uint *)(*(int *)(iVar15 + 0x38) + 0x14) & 0x40) == 0)) &&
                       (iVar15 = FUN_00166a0c(param_1,iVar15), uVar10 = local_64[4], iVar15 == 0)) {
                      if (*(int *)(*piVar9 + 0x60) != *(int *)(iVar4 + 0x60)) {
                        *(int *)(*piVar9 + 0x60) = *(int *)(iVar4 + 0x60);
                        *(int *)(*(int *)(iVar4 + 0x60) + 0x10) =
                             *(int *)(*(int *)(iVar4 + 0x60) + 0x10) + 1;
                        **(uint **)(iVar4 + 0x60) =
                             **(uint **)(iVar4 + 0x60) | *(uint *)(*(int *)(*piVar9 + 0x38) + 0xc);
                        *(int *)(iVar25 + 0x10) = *(int *)(iVar25 + 0x10) + -1;
                        iVar15 = *piVar9;
                        if (local_64[4] < local_64[3]) {
                          iVar12 = local_64[4] * 4;
                          _memset((void *)(iVar12 + local_64[5]),0,4);
                          local_64[4] = uVar10 + 1;
                          piVar9 = (int *)(iVar12 + local_64[5]);
                        }
                        else {
                          piVar9 = (int *)FUN_0019423c(local_64 + 3,local_64[4]);
                        }
                        *piVar9 = iVar15;
                      }
                    }
                    else {
                      uVar10 = local_74;
                      if ((int)local_74 < 1) {
                        iVar15 = *piVar9;
                      }
                      else {
                        uVar27 = 0;
                        do {
                          if (uVar27 < local_78) {
                            if (local_74 <= uVar27) {
                              _memset((void *)(local_74 * 4 + local_70),0,
                                      (uVar27 - local_74) * 4 + 4);
                              local_74 = uVar27 + 1;
                            }
                            piVar11 = (int *)(uVar27 * 4 + local_70);
                          }
                          else {
                            piVar11 = (int *)FUN_0019423c(&local_78,uVar27);
                          }
                          iVar12 = FUN_00105594(*(undefined4 *)(*piVar11 + 0x38),1);
                          iVar15 = *piVar9;
                          if (iVar12 == *(int *)(iVar15 + 0x38)) {
                            if (uVar27 < local_78) {
                              if (local_74 <= uVar27) {
                                _memset((void *)(local_74 * 4 + local_70),0,
                                        (uVar27 - local_74) * 4 + 4);
                                local_74 = uVar27 + 1;
                              }
                              piVar11 = (int *)(uVar27 * 4 + local_70);
                            }
                            else {
                              piVar11 = (int *)FUN_0019423c(&local_78,uVar27);
                            }
                            iVar15 = *piVar11;
                            *(uint *)(*(int *)(iVar15 + 0x38) + 0xc) =
                                 *(uint *)(*(int *)(iVar15 + 0x38) + 0xc) | piVar9[6];
                            **(uint **)(iVar15 + 0x60) = **(uint **)(iVar15 + 0x60) | piVar9[6];
                            goto LAB_0016fafc;
                          }
                          uVar27 = uVar27 + 1;
                        } while (uVar10 != uVar27);
                      }
                      uVar3 = DAT_001b0190;
                      iVar12 = *(int *)(iVar15 + 0x2c);
                      uVar28 = *(undefined4 *)(iVar15 + 0x38);
                      iVar15 = (**(code **)(*(int *)param_1[2] + 0x78))();
                      iVar15 = FUN_00167e1c(param_1,uVar28,uVar3,iVar12 + iVar15,*piVar9 + 0xc);
                      if (local_74 < local_78) {
                        iVar12 = local_74 * 4;
                        local_74 = local_74 + 1;
                        *(undefined4 *)(iVar12 + local_70) = 0;
                        piVar11 = (int *)(iVar12 + local_70);
                      }
                      else {
                        piVar11 = (int *)FUN_0019423c(&local_78,local_74);
                      }
                      *piVar11 = iVar15;
                      if (local_64[0] < local_68) {
                        iVar12 = local_64[0] * 4;
                        local_64[0] = local_64[0] + 1;
                        *(undefined4 *)(iVar12 + local_64[1]) = 0;
                        piVar11 = (int *)(iVar12 + local_64[1]);
                      }
                      else {
                        piVar11 = (int *)FUN_0019423c(&local_68,local_64[0]);
                      }
                      *piVar11 = *piVar9;
                      *(int *)(*(int *)(iVar15 + 0x38) + 0xc) = piVar9[6];
                      FUN_00106804(*(undefined4 *)(iVar15 + 0x38),*(undefined4 *)(iVar18 + 0x38),0,
                                   *param_1);
                      *(undefined4 *)(iVar15 + 0x60) = *(undefined4 *)(iVar4 + 0x60);
                      *(int *)(*(int *)(iVar4 + 0x60) + 0x10) =
                           *(int *)(*(int *)(iVar4 + 0x60) + 0x10) + 1;
                      **(uint **)(iVar4 + 0x60) = **(uint **)(iVar4 + 0x60) | piVar9[6];
LAB_0016fafc:
                      if ((piVar9[4] < 1) || (piVar9[5] != 0)) {
LAB_0016fb44:
                        iVar12 = *piVar9;
                      }
                      else {
                        iVar13 = FUN_00105594(*(undefined4 *)(iVar19 + 0x38),piVar9[4]);
                        iVar12 = *piVar9;
                        if (iVar13 == *(int *)(iVar12 + 0x38)) {
                          FUN_00106004(*(undefined4 *)(iVar19 + 0x38),piVar9[4],
                                       *(undefined4 *)(iVar15 + 0x38),0,*param_1);
                          goto LAB_0016fb44;
                        }
                      }
                      iVar31 = 4;
                      iVar16 = 0;
                      piVar11 = piVar9;
                      iVar13 = iVar15;
                      do {
                        if (*(char *)(piVar11 + 6) != '\0') {
                          iVar12 = iVar16 * 4 + iVar12;
                          *(int *)(iVar12 + 0x48) = *(int *)(iVar12 + 0x48) + -1;
                          *(int *)(iVar13 + 0x48) = *(int *)(iVar13 + 0x48) + 1;
                          iVar12 = *piVar9;
                        }
                        iVar16 = iVar16 + 1;
                        piVar11 = (int *)((int)piVar11 + 1);
                        iVar13 = iVar13 + 4;
                        iVar31 = iVar31 + -1;
                      } while (iVar31 != 0);
                      FUN_00194374(*(undefined4 *)(iVar12 + 0x40),piVar9);
                      if (-1 < *(int *)(*piVar9 + 0x2c)) {
                        *(int *)(iVar19 + 0x34) = *(int *)(iVar19 + 0x34) + 1;
                      }
                      *piVar9 = iVar15;
                      puVar26 = *(uint **)(iVar15 + 0x40);
                      uVar10 = puVar26[1];
                      if (uVar10 < *puVar26) {
                        _memset((void *)(uVar10 * 4 + puVar26[2]),0,4);
                        puVar17 = (undefined4 *)(uVar10 * 4 + puVar26[2]);
                        puVar26[1] = uVar10 + 1;
                      }
                      else {
                        puVar17 = (undefined4 *)FUN_0019423c(puVar26,uVar10);
                      }
                      *puVar17 = piVar9;
                    }
                  }
                  uVar23 = uVar23 + 1;
                  if (uVar24 == uVar23) break;
                  puVar26 = *(uint **)(iVar19 + 0x44);
                } while( true );
              }
            }
            uVar22 = uVar22 + 1;
            if (uVar14 == uVar22) goto LAB_0016fcc0;
            puVar26 = *(uint **)(iVar18 + 0x40);
          } while( true );
        }
        goto LAB_0016f574;
      }
    }
    iVar4 = *(int *)(iVar4 + 8);
  } while( true );
code_r0x0016f044:
  iVar18 = iVar18 + 4;
  iVar20 = iVar20 + -1;
  if (iVar20 == 0) goto LAB_0016f3cc;
  goto LAB_0016f038;
}

/* FUN_00170990 @ 0x170990 (572 bytes) */
int FUN_00170990(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (((*(int *)(param_1 + 0x118) == 0) && (iVar2 = FUN_00193f08(param_1 + 0x4c), iVar2 == 0)) &&
     (*(int *)(param_1 + 0x20) != 0)) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x54) + 0x10);
    iVar3 = (**(code **)(**(int **)(param_1 + 8) + 0x84))();
    iVar2 = iVar2 + iVar3;
  }
  else {
    iVar2 = 0x7fffffff;
  }
  while ((iVar3 = (**(code **)(**(int **)(param_1 + 8) + 0x20))(), iVar3 == 0 &&
         (iVar3 = ((int (*)())FUN_0016ff54)(param_1,iVar2), iVar3 != 0))) {
    ((int (*)())FUN_0016d3b0)(param_1,iVar3);
  }
  iVar2 = 0;
  iVar3 = 0;
  while( true ) {
    while( true ) {
      iVar4 = FUN_00193f08(iVar3 + param_1 + 0xac);
      if (iVar4 != 0) break;
      uVar5 = *(undefined4 *)(iVar3 + param_1 + 0xb4);
      FUN_0019401c(uVar5);
      iVar4 = (**(code **)(**(int **)(param_1 + 8) + 0x20))();
      if ((iVar4 == 0) && (iVar4 = FUN_00168d80(param_1,uVar5), iVar4 != 0)) {
        ((int (*)())FUN_0016d3b0)(param_1,iVar4);
      }
      else {
        FUN_00193f64(param_1 + 0x7c,uVar5);
      }
    }
    bVar1 = iVar2 == 2;
    iVar2 = iVar2 + 1;
    if (bVar1) break;
    iVar3 = iVar2 * 0x18;
  }
  while (((iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x20))(), iVar2 == 0 &&
          (*(int *)(param_1 + 0x118) == 0)) && (iVar2 = FUN_0016629c(param_1), iVar2 != 0))) {
    ((int (*)())FUN_0016d3b0)(param_1,iVar2);
  }
  iVar2 = FUN_0016c640(param_1);
  if (iVar2 == 0) {
    (**(code **)(**(int **)(param_1 + 8) + 0x7c))();
  }
  ((int (*)())FUN_0016e828)(param_1);
  iVar3 = FUN_00193f08(param_1 + 0x4c);
  if ((iVar3 == 0) || (iVar3 = FUN_00193f08(param_1 + 0x34), iVar3 == 0)) {
    uVar5 = 0;
  }
  else {
    iVar3 = FUN_00193f08(param_1 + 100);
    uVar5 = 1;
    if (iVar3 == 0) {
      iVar3 = FUN_0016c640(param_1);
      if (iVar3 == 0) {
        *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 0x80;
      }
      ((int (*)())FUN_0016e828)(param_1);
      uVar5 = 0;
    }
  }
  return uVar5;
}

/* FUN_00170bcc @ 0x170bcc (468 bytes) */
int FUN_00170bcc(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint *puVar11;
  
  puVar10 = *(uint **)(param_2 + 0x40);
  uVar3 = puVar10[1];
  if (0 < (int)uVar3) {
    uVar8 = 0;
    uVar4 = 1;
    iVar5 = 0;
    while( true ) {
      if (uVar8 < *puVar10) {
        uVar1 = puVar10[1];
        puVar11 = puVar10;
        if (uVar1 <= uVar8) {
          _memset((void *)(uVar1 * 4 + puVar10[2]),0,(uVar8 - uVar1) * 4 + 4);
          puVar10[1] = uVar4;
          puVar11 = *(uint **)(param_2 + 0x40);
        }
        piVar2 = (int *)(iVar5 + puVar10[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar10,uVar8);
        puVar11 = *(uint **)(param_2 + 0x40);
      }
      iVar6 = *(int *)(param_2 + 0x2c);
      iVar9 = *(int *)(*piVar2 + 4);
      iVar7 = *(int *)(iVar9 + 0x30);
      *(int *)(iVar9 + 0x34) = *(int *)(iVar9 + 0x34) + -1;
      if (uVar8 < *puVar11) {
        uVar1 = puVar11[1];
        if (uVar1 <= uVar8) {
          _memset((void *)(uVar1 * 4 + puVar11[2]),0,(uVar8 - uVar1) * 4 + 4);
          puVar11[1] = uVar4;
        }
        piVar2 = (int *)(iVar5 + puVar11[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar11,uVar8);
      }
      if (iVar7 < iVar6 + *(int *)(*piVar2 + 0xc)) {
        puVar10 = *(uint **)(param_2 + 0x40);
        iVar6 = *(int *)(param_2 + 0x2c);
        if (uVar8 < *puVar10) {
          uVar1 = puVar10[1];
          if (uVar1 <= uVar8) {
            _memset((void *)(uVar1 * 4 + puVar10[2]),0,(uVar8 - uVar1) * 4 + 4);
            puVar10[1] = uVar4;
          }
          piVar2 = (int *)(iVar5 + puVar10[2]);
        }
        else {
          piVar2 = (int *)FUN_0019423c(puVar10,uVar8);
        }
        iVar6 = iVar6 + *(int *)(*piVar2 + 0xc);
      }
      else {
        iVar6 = *(int *)(iVar9 + 0x30);
      }
      *(int *)(iVar9 + 0x30) = iVar6;
      if (*(int *)(iVar9 + 0x34) == 0) {
        ((int (*)())FUN_0016ee90)(param_1,iVar9);
      }
      uVar8 = uVar8 + 1;
      uVar4 = uVar4 + 1;
      iVar5 = iVar5 + 4;
      if (uVar3 == uVar8) break;
      puVar10 = *(uint **)(param_2 + 0x40);
    }
  }
  return;
}

/* FUN_00170da0 @ 0x170da0 (204 bytes) */
int FUN_00170da0(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(param_2 + 0x2c) = uVar1;
  *(undefined4 *)(param_2 + 0x30) = uVar1;
  ((int (*)())FUN_0017212c)(*(undefined4 *)(param_1 + 8),param_2);
  ((int (*)())FUN_0016cdc4)(param_1,param_2);
  ((int (*)())FUN_00170bcc)(param_1,param_2);
  iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x20))
                    (*(int **)(param_1 + 0xc),*(undefined4 *)(param_2 + 0x38));
  if (((iVar2 != 0) ||
      (iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x24))
                         (*(int **)(param_1 + 0xc),*(undefined4 *)(param_2 + 0x38)), iVar2 != 0)) &&
     (*(int *)(param_1 + 0x128) <= *(int *)(param_2 + 0xc))) {
    *(int *)(param_1 + 300) = *(int *)(param_1 + 300) + 1;
  }
  *(uint *)(*(int *)(param_2 + 0x38) + 0x14) =
       *(uint *)(*(int *)(param_2 + 0x38) + 0x14) & 0xfffffffe;
  return;
}

/* FUN_00170e6c @ 0x170e6c (2176 bytes) */
int FUN_00170e6c(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  int *piVar12;
  int *piVar13;
  uint *puVar14;
  int *piVar15;
  int iVar16;
  int local_48;
  int local_44;
  undefined1 auStack_40 [8];
  int local_38;
  
  FUN_0016a568(param_1,param_2);
  FUN_0016bd70(param_1);
  FUN_001670fc(param_1);
  piVar3 = (int *)param_1[0x4c];
  iVar2 = *piVar3;
  if (iVar2 != 0) {
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    do {
      piVar3[2] = 0;
      piVar3 = piVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iVar2 = param_1[0x51];
  if (0 < iVar2) {
    uVar7 = 0;
    do {
      uVar8 = uVar7 >> 3 & 0x1ffffffc;
      uVar11 = uVar7 & 0x1f;
      if (((*(uint *)(uVar8 + *(int *)(param_1[1] + 0x430) + 8) >> uVar11 & 1) != 0) &&
         ((*(uint *)(uVar8 + *(int *)(param_2 + 0x104) + 8) >> uVar11 & 1) == 0)) {
        *(uint *)(uVar8 + param_1[0x4c] + 8) = 1 << uVar11 | *(uint *)(uVar8 + param_1[0x4c] + 8);
      }
      iVar2 = 4;
      piVar3 = param_1;
      do {
        piVar12 = piVar3 + 0x4d;
        piVar3 = piVar3 + 1;
        *(undefined4 *)(uVar7 * 4 + *piVar12) = 0;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      iVar2 = param_1[0x51];
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < iVar2);
  }
  if (param_1[0x58] != 0) {
    piVar3 = param_1;
    while( true ) {
      if (0 < iVar2) {
        iVar2 = 0;
        do {
          iVar9 = iVar2 * 4;
          iVar2 = iVar2 + 1;
          *(undefined4 *)(iVar9 + piVar3[0x54]) = 0;
        } while (iVar2 < param_1[0x51]);
      }
      iVar2 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x13c))();
      if (0 < iVar2) {
        iVar9 = 0;
        do {
          iVar5 = iVar9 * 4;
          iVar9 = iVar9 + 1;
          *(undefined4 *)(iVar5 + piVar3[0x58]) = 0;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      piVar3 = piVar3 + 1;
      if (param_1 + 4 == piVar3) break;
      iVar2 = param_1[0x51];
    }
  }
  puVar14 = (uint *)param_1[5];
  uVar7 = puVar14[1];
  if (uVar7 != 0) {
    uVar11 = 0;
    do {
      if (uVar11 < *puVar14) {
        if (uVar7 <= uVar11) {
          _memset((void *)(uVar7 * 4 + puVar14[2]),0,(uVar11 - uVar7) * 4 + 4);
          puVar14[1] = uVar11 + 1;
        }
        piVar3 = (int *)(uVar11 * 4 + puVar14[2]);
      }
      else {
        piVar3 = (int *)FUN_0019423c(puVar14,uVar11);
      }
      uVar11 = uVar11 + 1;
      iVar9 = *piVar3;
      piVar3 = *(int **)(iVar9 + 0x38);
      iVar2 = piVar3[0x25];
      if ((((piVar3[0x20] != 0) && (iVar5 = FUN_00126760(piVar3[0x26]), iVar5 != 0)) &&
          ((piVar3[5] & 2U) == 0)) &&
         ((iVar5 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar5 == 0 && ((piVar3[5] & 0x40U) != 0)))
         ) {
        local_48 = piVar3[3];
        if (*(int *)(iVar9 + 0x60) != 0) {
          *(int *)(*(int *)(iVar9 + 0x60) + 8) = iVar9;
          *(int *)(*(int *)(iVar9 + 0x60) + 4) = iVar2;
          local_48 = **(int **)(iVar9 + 0x60);
        }
        iVar16 = 4;
        iVar5 = 0;
        piVar12 = param_1;
        do {
          if (*(char *)((int)&local_48 + iVar5) != '\0') {
            *(int *)(piVar12[0x4d] + iVar2 * 4) = iVar9;
            if (piVar12[0x54] != 0) {
              *(undefined4 *)(piVar12[0x54] + iVar2 * 4) = 0x7fffffff;
            }
            if (*(int *)(iVar9 + 0x60) != 0) {
              *(int *)(iVar5 * 4 + *(int *)(iVar9 + 0x60) + 0x18) = iVar9;
              *(undefined4 *)(*(int *)(iVar9 + 0x60) + 0x14) = 0;
            }
          }
          iVar5 = iVar5 + 1;
          piVar12 = piVar12 + 1;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
        if (piVar3[0x26] == 1) {
          iVar5 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x138))();
          iVar9 = param_1[0x67];
          if (param_1[0x67] < iVar2 - iVar5) {
            iVar9 = iVar2 - iVar5;
          }
          param_1[0x67] = iVar9;
        }
        else {
          iVar9 = param_1[0x66];
          if (param_1[0x66] < iVar2) {
            iVar9 = iVar2;
          }
          param_1[0x66] = iVar9;
          if (iVar2 <= param_1[0x68]) {
            iVar2 = param_1[0x68];
          }
          param_1[0x68] = iVar2;
        }
      }
      puVar14 = (uint *)param_1[5];
      uVar7 = puVar14[1];
    } while (uVar11 < uVar7);
  }
  iVar2 = 4;
  piVar3 = param_1;
  do {
    piVar3[0x5c] = 0;
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 0;
  piVar3 = param_1;
  do {
    bVar1 = iVar2 != 1;
    piVar3[0x62] = 0;
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (bVar1);
  iVar2 = FUN_000e07dc(*param_1,0x47);
  if ((iVar2 != 0) && (iVar2 = FUN_000e07dc(*param_1,0x24), iVar2 != 0)) {
    FUN_00169b70(param_1);
  }
  uVar11 = 0;
  (**(code **)(*(int *)param_1[2] + 8))();
  (**(code **)(*(int *)param_1[3] + 8))();
  param_1[0x46] = 1;
  param_1[0x4a] = -1;
  param_1[0x4b] = 0;
  param_1[0xb] = 1;
  param_1[0x47] = -1;
  param_1[0x48] = -1;
  param_1[0x49] = 0;
  FUN_001940a8(auStack_40);
  puVar14 = (uint *)param_1[6];
  uVar7 = puVar14[1];
  if (0 < (int)uVar7) {
    while( true ) {
      if (uVar11 < *puVar14) {
        uVar8 = puVar14[1];
        if (uVar8 <= uVar11) {
          _memset((void *)(uVar8 * 4 + puVar14[2]),0,(uVar11 - uVar8) * 4 + 4);
          puVar14[1] = uVar11 + 1;
        }
        piVar3 = (int *)(uVar11 * 4 + puVar14[2]);
      }
      else {
        piVar3 = (int *)FUN_0019423c(puVar14,uVar11);
      }
      if (*(int *)(*piVar3 + 0x34) == 0) {
        FUN_00193f64(auStack_40,*piVar3);
      }
      uVar11 = uVar11 + 1;
      if (uVar7 == uVar11) break;
      puVar14 = (uint *)param_1[6];
    }
  }
  iVar9 = *(int *)(local_38 + 8);
  iVar2 = local_38;
  while (iVar5 = iVar9, iVar5 != 0) {
    FUN_0019401c(iVar2);
    ((int (*)())FUN_0016ee90)(param_1,iVar2);
    iVar9 = (**(code **)(*(int *)param_1[3] + 0x20))
                      ((int *)param_1[3],*(undefined4 *)(iVar2 + 0x38));
    if ((iVar9 == 0) &&
       (iVar9 = (**(code **)(*(int *)param_1[3] + 0x24))
                          ((int *)param_1[3],*(undefined4 *)(iVar2 + 0x38)), iVar9 == 0)) {
      iVar9 = *(int *)(iVar2 + 0xc);
      if (*(int *)(iVar2 + 0xc) < param_1[0x47]) {
        iVar9 = param_1[0x47];
      }
      param_1[0x47] = iVar9;
    }
    else {
      iVar9 = *(int *)(iVar2 + 0xc);
      if (*(int *)(iVar2 + 0xc) < param_1[0x48]) {
        iVar9 = param_1[0x48];
      }
      param_1[0x48] = iVar9;
    }
    iVar2 = iVar5;
    iVar9 = *(int *)(iVar5 + 8);
  }
  piVar3 = param_1 + 0xd;
  param_1[0x46] = 0;
  iVar2 = FUN_00193f08(piVar3);
  if ((iVar2 == 0) && (param_1[0x47] + -1 <= param_1[0x48])) {
    param_1[0x4a] = param_1[0x48];
    param_1[0x46] = 1;
  }
  piVar12 = (int *)(*(int **)(param_1[4] + 0x98))[2];
  if (piVar12 != (int *)0x0) {
    piVar10 = (int *)0x0;
    piVar15 = *(int **)(param_1[4] + 0x98);
    do {
      piVar13 = piVar12;
      iVar2 = (**(code **)(*piVar15 + 0x34))(piVar15);
      if ((iVar2 == 0) && (iVar2 = (**(code **)(*piVar15 + 0x38))(piVar15), iVar2 == 0)) {
        iVar2 = FUN_00164df4(piVar15);
        if (iVar2 == 0) {
          FUN_0019401c(piVar15);
          piVar15[0x56] = 0;
        }
        else {
          piVar15[5] = piVar15[5] | 4;
          piVar10 = piVar15;
        }
      }
      else {
        piVar15[5] = piVar15[5] & 0xfffffffb;
      }
      piVar12 = (int *)piVar13[2];
      piVar15 = piVar13;
    } while (piVar12 != (int *)0x0);
    if (piVar10 != (int *)0x0) {
      piVar10[5] = piVar10[5] & 0xfffffffb;
    }
  }
  piVar12 = param_1 + 0x13;
  iVar2 = FUN_00193f08(piVar12);
  if ((((iVar2 == 0) || (iVar2 = FUN_00193f08(piVar3), iVar2 == 0)) ||
      (iVar2 = FUN_00193f08(param_1 + 0x19), iVar2 == 0)) ||
     (iVar2 = FUN_00193f08(param_1 + 0x3e), iVar2 == 0)) {
    iVar2 = FUN_0016c640(param_1);
    if ((iVar2 == 0) && (iVar2 = FUN_00193f08(param_1 + 0x25), iVar2 != 0)) {
      iVar2 = FUN_00193f08(param_1 + 0x3e);
      if (((iVar2 == 0) && (iVar2 = FUN_00193f08(piVar12), iVar2 != 0)) &&
         ((iVar2 = FUN_00193f08(piVar3), iVar2 != 0 &&
          (iVar2 = FUN_00194034(param_1 + 0x3e), iVar2 == param_1[0x3d])))) {
        iVar2 = param_1[0x40];
        for (iVar9 = *(int *)(param_1[0x40] + 8); iVar9 != 0; iVar9 = *(int *)(iVar9 + 8)) {
          FUN_0019401c(iVar2);
          *(undefined4 *)(iVar2 + 0x68) = 0;
          FUN_00193f64(piVar12,iVar2);
          iVar2 = iVar9;
        }
      }
    }
    else {
      ((int (*)())FUN_0016e828)(param_1);
    }
    do {
      iVar2 = ((int (*)())FUN_00170990)(param_1);
    } while (iVar2 == 0);
    FUN_0016c640(param_1);
    puVar6 = (undefined4 *)param_1[0xc];
    iVar2 = 5;
    puVar4 = puVar6;
    do {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  else {
    FUN_0016c640(param_1);
    puVar6 = (undefined4 *)param_1[0xc];
    iVar2 = 5;
    puVar4 = puVar6;
    do {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_00193fa4(puVar6 + 5);
  iVar2 = (**(code **)(*(int *)param_1[3] + 0x1c))();
  if (iVar2 != 0) {
    iVar2 = *(int *)(param_2 + 0xd0);
    iVar9 = 0;
    local_44 = 0;
    for (uVar7 = 1; uVar7 <= *(uint *)(iVar2 + 4); uVar7 = uVar7 + 1) {
      local_44 = *(int *)(*(int *)(iVar2 + 8) + iVar9);
      if (local_44 != 0) {
        *(undefined4 *)(local_44 + 0xdc) = 1;
      }
      iVar9 = iVar9 + 4;
    }
  }
  FUN_00166cfc(param_1);
  return;
}

/* FUN_00171714 @ 0x171714 (408 bytes) */
int FUN_00171714(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  void *pvVar9;
  int iVar10;
  int iVar11;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r10;
  int *piVar12;
  undefined4 uVar13;
  int *piVar14;
  int *piVar15;
  int *piVar16;
  
  param_1[1] = param_2;
  iVar4 = *(int *)(param_2 + 8);
  *param_1 = iVar4;
  iVar4 = FUN_0010ddcc(iVar4);
  param_1[2] = iVar4;
  iVar4 = FUN_0010ddd8(*param_1);
  param_1[3] = iVar4;
  uVar13 = *(undefined4 *)(*param_1 + 0x378);
  puVar5 = (undefined4 *)FUN_00193e18(uVar13,0x14);
  *puVar5 = uVar13;
  puVar5[1] = 2;
  puVar5[4] = uVar13;
  puVar5[2] = 0;
  uVar13 = FUN_00193e18(uVar13,8);
  puVar5[3] = uVar13;
  param_1[5] = (int)(puVar5 + 1);
  uVar13 = *(undefined4 *)(*param_1 + 0x378);
  puVar5 = (undefined4 *)FUN_00193e18(uVar13,0x14);
  *puVar5 = uVar13;
  puVar5[1] = 2;
  puVar5[2] = 0;
  puVar5[4] = uVar13;
  uVar13 = FUN_00193e18(uVar13,8);
  puVar5[3] = uVar13;
  param_1[6] = (int)(puVar5 + 1);
  uVar13 = *(undefined4 *)(*param_1 + 0x378);
  puVar6 = (undefined4 *)FUN_00193e18(uVar13,0x30);
  *puVar6 = uVar13;
  FUN_001940a8(puVar6 + 6);
  iVar4 = 5;
  puVar5 = puVar6 + 1;
  do {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  param_1[0xc] = (int)(puVar6 + 1);
  iVar4 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x138))();
  iVar7 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x140))();
  iVar4 = iVar4 + iVar7;
  param_1[0x51] = iVar4;
  uVar2 = iVar4 + 0x1fU >> 5;
  uVar13 = *(undefined4 *)(*param_1 + 0x378);
  puVar5 = (undefined4 *)FUN_00193e18(uVar13,uVar2 * 4 + 0xc);
  piVar12 = puVar5 + 1;
  *puVar5 = uVar13;
  puVar5[1] = uVar2;
  puVar5[2] = iVar4;
  if (uVar2 != 0) {
    iVar4 = *piVar12;
    piVar14 = piVar12;
    if (iVar4 == 0) {
      iVar4 = 1;
    }
    do {
      piVar14[2] = 0;
      piVar14 = piVar14 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  param_1[0x4c] = (int)piVar12;
  iVar4 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x13c))();
  bVar1 = iVar4 < 1;
  piVar12 = param_1;
  do {
    iVar7 = FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),param_1[0x51] << 2);
    piVar12[0x4d] = iVar7;
    if (bVar1) {
      piVar12[0x54] = 0;
      piVar12[0x58] = 0;
    }
    else {
      iVar8 = FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),param_1[0x51] << 2);
      iVar7 = *param_1;
      piVar12[0x54] = iVar8;
      iVar7 = FUN_00193e18(*(undefined4 *)(iVar7 + 0x378),iVar4 << 2);
      piVar12[0x58] = iVar7;
    }
    piVar12 = piVar12 + 1;
  } while (piVar12 != param_1 + 4);
  iVar4 = param_1[0x51];
  param_1[0x53] = iVar4;
  param_1[0x60] = 0;
  param_1[0x61] = -1;
  param_1[0x52] = iVar4;
  param_1[100] = 0;
  param_1[0x65] = 0;
  param_1[0x66] = -1;
  param_1[0x67] = -1;
  param_1[0x68] = -1;
  param_1[0x69] = -1;
  param_1[0x6a] = 0;
  iVar7 = FUN_000e79d0(*(undefined4 *)(param_1[1] + 0x3a0));
  if (iVar7 == 1) {
    iVar7 = param_1[1];
    puVar5 = (undefined4 *)0x0;
    iVar4 = *(int *)(*(int *)(iVar7 + 0x3a0) + 0xd0);
    if (*(int *)(iVar4 + 4) != 0) {
      puVar5 = *(undefined4 **)(iVar4 + 8);
    }
    piVar16 = *(int **)(*(int *)(iVar7 + 0x3a0) + 0xa0);
    uVar13 = *puVar5;
    piVar14 = (int *)piVar16[1];
    if (piVar14 != (int *)0x0) {
      do {
        piVar15 = piVar14;
        iVar7 = (**(code **)(*piVar16 + 0x34))(piVar16);
        if ((iVar7 == 0) && (iVar7 = (**(code **)(*piVar16 + 0x38))(piVar16), iVar7 == 0)) {
          FUN_0019401c(piVar16);
          FUN_000e76c4(uVar13,piVar16);
        }
        piVar14 = (int *)piVar15[1];
        piVar16 = piVar15;
      } while (piVar14 != (int *)0x0);
      iVar7 = param_1[1];
    }
    *(undefined4 *)(iVar7 + 0x3a4) = uVar13;
  }
  iVar7 = FUN_000e79dc(*(undefined4 *)(param_1[1] + 0x3a8));
  if (iVar7 == 1) {
    iVar7 = param_1[1];
    puVar5 = (undefined4 *)0x0;
    iVar4 = *(int *)(*(int *)(iVar7 + 0x3a8) + 0xd4);
    if (*(int *)(iVar4 + 4) != 0) {
      puVar5 = *(undefined4 **)(iVar4 + 8);
    }
    piVar16 = *(int **)(*(int *)(iVar7 + 0x3a8) + 0x98);
    uVar13 = *puVar5;
    piVar14 = (int *)piVar16[2];
    if (piVar14 == (int *)0x0) goto code_r0x00171ba0;
    do {
      piVar15 = piVar14;
      iVar7 = (**(code **)(*piVar16 + 0x34))(piVar16);
      if ((iVar7 == 0) && (iVar7 = (**(code **)(*piVar16 + 0x38))(piVar16), iVar7 == 0)) {
        iVar7 = (**(code **)(*piVar16 + 0x68))(piVar16);
        if (iVar7 != 0) {
          piVar14 = (int *)FUN_00105594(piVar16,1);
          iVar7 = (**(code **)(*piVar14 + 0x50))();
          if (iVar7 != 0) goto code_r0x00171b84;
        }
        FUN_0019401c(piVar16);
        FUN_000e7688(uVar13,piVar16);
      }
code_r0x00171b84:
      piVar14 = (int *)piVar15[2];
      piVar16 = piVar15;
    } while (piVar14 != (int *)0x0);
  }
  iVar7 = param_1[1];
code_r0x00171ba0:
  (**(code **)(*(int *)param_1[2] + 0x70))((int *)param_1[2],iVar7);
  FUN_000ed7e4(param_1[1]);
  iVar7 = FUN_000e07dc(*param_1,0x43);
  if (iVar7 != 0) {
    FUN_00184ab4(param_1,param_2);
  }
  FUN_00169e30(param_1);
  FUN_00165014(param_1);
  iVar7 = *(int *)(param_1[1] + 900);
  iVar8 = *(int *)(iVar7 + 8);
  while (iVar8 != 0) {
    iVar8 = FUN_00194034(iVar7 + 0x90);
    if (2 < iVar8) {
      ((int (*)())FUN_00170e6c)(param_1,iVar7);
      iVar4 = param_1[1];
      param_1[100] = param_1[100] + param_1[0xb];
      *(undefined4 *)(iVar7 + 0x118) = *(undefined4 *)(iVar4 + 0x474);
    }
    iVar7 = *(int *)(iVar7 + 8);
    iVar8 = *(int *)(iVar7 + 8);
  }
  if (!bVar1) {
    param_1[0x66] = param_1[0x68];
  }
  if (-1 < param_1[0x66]) {
    iVar7 = 0;
    do {
      iVar8 = iVar7 + 1;
      FUN_00130444(param_1[1],iVar7);
      iVar7 = iVar8;
    } while (iVar8 <= param_1[0x66]);
  }
  iVar7 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x138))();
  if (-1 < param_1[0x67]) {
    iVar8 = 0;
    do {
      iVar10 = iVar7 + iVar8;
      iVar8 = iVar8 + 1;
      FUN_00130444(param_1[1],iVar10);
    } while (iVar8 <= param_1[0x67]);
  }
  iVar8 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x140))();
  if (-1 < param_1[0x69]) {
    iVar10 = 0;
    do {
      iVar11 = iVar7 + iVar8 + iVar10;
      iVar10 = iVar10 + 1;
      FUN_00130444(param_1[1],iVar11);
    } while (iVar10 <= param_1[0x69]);
  }
  FUN_000e0e0c(*param_1,"Scheduler : Total cycles %d\n",param_1[100],in_r6,in_r7,in_r8,iVar4,in_r10)
  ;
  FUN_000e0e0c(*param_1,"Scheduler : Total dot-product transformed %d\n",param_1[0x6a],in_r6,in_r7,
               in_r8,iVar4,in_r10);
  FUN_000ed7e4(param_1[1]);
  FUN_00138080(param_2);
  iVar4 = param_1[0x4c];
  piVar14 = param_1;
  if (iVar4 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
  }
  do {
    if (!bVar1) {
      FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),piVar14[0x54]);
      FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),piVar14[0x58]);
    }
    piVar16 = piVar14 + 1;
    FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),piVar14[0x4d]);
    piVar14 = piVar16;
  } while (piVar12 != piVar16);
  iVar4 = param_1[0xc];
  if (iVar4 != 0) {
    puVar3 = PTR_DAT_001e8b48 + 8;
    *(undefined **)(iVar4 + 0x14) = puVar3;
    *(undefined **)(iVar4 + 0x20) = puVar3;
    FUN_00193cc0(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
  }
  iVar4 = param_1[6];
  if (iVar4 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar4 + 0xc),*(undefined4 *)(iVar4 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
  }
  iVar4 = param_1[5];
  if (iVar4 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar4 + 0xc),*(undefined4 *)(iVar4 + 8));
    iVar7 = *(int *)(iVar4 + -4);
    if ((*(int *)(iVar7 + 0x28) != 0) &&
       (pvVar9 = *(void **)(iVar7 + 0x14), pvVar9 == (void *)(iVar4 + -4))) {
      _memset(pvVar9,0,*(int *)(iVar7 + 8) - (int)pvVar9);
      *(undefined4 *)(iVar7 + 8) = *(undefined4 *)(iVar7 + 0x14);
    }
    return;
  }
  return;
}

/* FUN_00171e68 @ 0x171e68 (200 bytes) */
int FUN_00171e68(param_1)
  int param_1;
{
  bool bVar1;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 *puVar2;
  int iVar4;
  undefined1 auStack_1d8 [52];
  undefined1 auStack_1a4 [24];
  undefined1 auStack_18c [24];
  undefined1 auStack_174 [24];
  undefined1 auStack_15c [24];
  undefined1 auStack_144 [24];
  undefined4 auStack_12c [18];
  undefined4 uStack_e4;
  undefined1 local_e0 [200];
  undefined4 *puVar3;
  
  FUN_001940a8(auStack_1a4);
  FUN_001940a8(auStack_18c);
  FUN_001940a8(auStack_174);
  FUN_001940a8(auStack_15c);
  FUN_001940a8(auStack_144);
  iVar4 = 1;
  puVar2 = auStack_12c;
  do {
    FUN_001940a8(puVar2);
    bVar1 = iVar4 != -1;
    puVar2 = puVar2 + 6;
    iVar4 = iVar4 + -1;
  } while (bVar1);
  FUN_001940a8(local_e0);
  iVar4 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x42);
  if (iVar4 != 0) {
    FUN_0018401c(auStack_1d8,param_1,in_r5,in_r6,in_r7,in_r8,in_r9);
  }
  ((int (*)())FUN_00171714)(auStack_1d8,param_1);
  puVar2 = &uStack_e4;
  do {
    puVar3 = puVar2 + -6;
    *puVar3 = PTR_DAT_001e8b48 + 8;
    puVar2[-3] = PTR_DAT_001e8b48 + 8;
    puVar2 = puVar3;
  } while (puVar3 != auStack_12c);
  return;
}

/* FUN_00172000 @ 0x172000 (20 bytes) */
int FUN_00172000(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}

/* FUN_00172014 @ 0x172014 (100 bytes) */
int FUN_00172014(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0xc);
  iVar3 = *(int *)(param_1 + 0x10);
  if (iVar2 <= iVar3) {
    if (*(int *)(param_1 + 0x14) < iVar3 - iVar2) {
      return iVar3;
    }
    uVar1 = *(int *)(param_1 + 0x14) + iVar2 + iVar3;
    return ((int)uVar1 >> 1) + (uint)((int)uVar1 < 0 && (uVar1 & 1) != 0);
  }
  if (*(int *)(param_1 + 0x14) < iVar2 - iVar3) {
    return iVar2;
  }
  uVar1 = *(int *)(param_1 + 0x14) + iVar2 + iVar3;
  return ((int)uVar1 >> 1) + (uint)((int)uVar1 < 0 && (uVar1 & 1) != 0);
}

/* FUN_00172078 @ 0x172078 (180 bytes) */
int FUN_00172078(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  (**(code **)(*param_1 + 0x4c))(param_1,*(undefined4 *)(param_2 + 0x38));
  iVar1 = *(int *)(param_2 + 0x58);
  if (iVar1 == 3) {
    param_1[3] = param_1[3] + 1;
    param_1[4] = param_1[4] + 1;
  }
  else if (*(int *)(param_2 + 0x5c) == 0) {
    if (iVar1 == 1) {
      param_1[3] = param_1[3] + 1;
    }
    else if (iVar1 == 2) {
      param_1[4] = param_1[4] + 1;
    }
  }
  else {
    param_1[5] = param_1[5] + 1;
  }
  return;
}

/* FUN_0017212c @ 0x17212c (216 bytes) */
int FUN_0017212c(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x58);
  iVar1 = (**(code **)(*param_1 + 0x4c))(param_1,*(undefined4 *)(param_2 + 0x38));
  if (iVar2 != iVar1) {
    (**(code **)(*param_1 + 0x50))(param_1);
  }
  iVar1 = *(int *)(param_2 + 0x58);
  if (iVar1 == 3) {
    param_1[3] = param_1[3] + -1;
    param_1[4] = param_1[4] + -1;
  }
  else if (*(int *)(param_2 + 0x5c) == 0) {
    if (iVar1 == 1) {
      param_1[3] = param_1[3] + -1;
    }
    else if (iVar1 == 2) {
      param_1[4] = param_1[4] + -1;
    }
  }
  else {
    param_1[5] = param_1[5] + -1;
  }
  return;
}

/* FUN_00172204 @ 0x172204 (200 bytes) */
int FUN_00172204(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x4c))();
  iVar2 = (**(code **)(*param_1 + 0x30))(param_1,param_2);
  if (iVar1 == 3) {
    param_1[3] = param_1[3] + 1;
    param_1[4] = param_1[4] + 1;
  }
  else if (iVar2 == 0) {
    if (iVar1 == 1) {
      param_1[3] = param_1[3] + 1;
    }
    else if (iVar1 == 2) {
      param_1[4] = param_1[4] + 1;
    }
  }
  else {
    param_1[5] = param_1[5] + 1;
  }
  return;
}

/* FUN_001722cc @ 0x1722cc (92 bytes) */
int FUN_001722cc(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x14) < *(int *)(param_1 + 0xc)) {
    return *(int *)(param_2 + 0x20) + *(int *)(param_2 + 0x28);
  }
  if (*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x14) < *(int *)(param_1 + 0x10)) {
    return *(int *)(param_2 + 0x20) + *(int *)(param_2 + 0x24);
  }
  return *(int *)(param_2 + 0x20) + *(int *)(param_2 + 0x24) + *(int *)(param_2 + 0x28);
}

/* FUN_00172328 @ 0x172328 (176 bytes) */
int FUN_00172328(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = *(int *)(param_1 + 0xc);
  iVar6 = *(int *)(param_1 + 0x10);
  iVar3 = iVar4;
  iVar5 = iVar6;
  if (iVar6 < iVar4) {
    iVar3 = iVar6;
    iVar5 = iVar4;
  }
  if ((iVar5 - iVar3) + 2 <= *(int *)(param_1 + 0x14)) {
    uVar1 = *(int *)(param_1 + 0x14) + iVar4 + iVar6;
    iVar3 = ((int)uVar1 >> 1) + (uint)((int)uVar1 < 0 && (uVar1 & 1) != 0);
    if ((uVar1 & 1) != 0) {
      return iVar3 + 1;
    }
    return iVar3;
  }
  iVar2 = *(int *)(param_2 + 0x58);
  if (iVar2 == 3) {
    return iVar5;
  }
  if (*(int *)(param_2 + 0x5c) == 0) {
    if (iVar2 == 1) {
      if (iVar4 == iVar5) {
        return iVar4;
      }
    }
    else {
      if (iVar2 != 2) {
        return 0;
      }
      if (iVar6 == iVar5) {
        return iVar6;
      }
    }
  }
  return iVar3;
}

/* FUN_001723d8 @ 0x1723d8 (80 bytes) */
int FUN_001723d8(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int *param_3;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_2 + 0x58) == 0) {
    FUN_00193f64(param_3 + 5,param_2);
    return;
  }
  iVar3 = 5;
  iVar2 = 0;
  piVar1 = param_3;
  do {
    if (*piVar1 == 0) {
      param_3[iVar2] = param_2;
      return;
    }
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

/* FUN_00172428 @ 0x172428 (76 bytes) */
int FUN_00172428(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (*(int *)(*(int *)(param_1 + 8) + 0x6b8) != 0) {
    return 1;
  }
  if ((param_2 < 0x10) && ((param_3 < 0x10 || (param_4 <= param_3 << 2)))) {
    uVar1 = 0;
    uVar2 = 0;
  }
  else {
    uVar1 = 1;
    uVar2 = 1;
  }
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x6b8) = uVar1;
  return uVar2;
}

/* FUN_00172474 @ 0x172474 (96 bytes) */
int FUN_00172474(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar2 = 0x2b;
    if (param_3 == 0) {
      uVar2 = 0xa6;
    }
    uVar3 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
    puVar1 = (undefined4 *)FUN_00193e18(uVar3,0x168);
    *puVar1 = uVar3;
    param_2 = puVar1 + 1;
    FUN_0010502c(param_2,uVar2,*(undefined4 *)(param_1 + 8));
  }
  else {
    FUN_00104f34(param_2,param_3);
  }
  return param_2;
}

/* FUN_00172514 @ 0x172514 (176 bytes) */
int FUN_00172514(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  ((int (*)())FUN_0017212c)(param_1,param_2);
  (**(code **)(*param_1 + 0x38))(param_1,param_2);
  iVar1 = (**(code **)(*param_1 + 0xc))(param_1,*(undefined4 *)(param_2 + 0x38));
  if (iVar1 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,param_2);
    ((int (*)())FUN_00172078)(param_1,param_2);
  }
  else {
    ((int (*)())FUN_00172078)(param_1,param_2);
  }
  return iVar1 != 0;
}

/* FUN_001725c4 @ 0x1725c4 (600 bytes) */
int FUN_001725c4(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30 [4];
  
  iVar4 = param_1[0x56];
  uVar1 = FUN_00105594(param_1,param_2);
  iVar2 = FUN_001043f0(0x31,param_3);
  *(undefined4 *)(iVar2 + 0x98) = 0;
  *(undefined4 *)(iVar2 + 0x94) = *(undefined4 *)(iVar2 + 0x14c);
  FUN_00106004(iVar2,1,uVar1,0,param_3);
  iVar3 = FUN_001054ec(param_1,param_2);
  FUN_000f3398(&local_38,*(undefined4 *)(iVar3 + 0x10));
  FUN_00106004(param_1,param_2,iVar2,0,param_3);
  FUN_000f31f8(&local_34,DAT_001b01b0,local_38);
  *(undefined4 *)(iVar2 + 0x9c) = local_34;
  FUN_000f3340(local_30,DAT_001b01ac,local_38);
  iVar3 = FUN_001054ec(iVar2,1);
  *(undefined4 *)(iVar3 + 0x10) = local_30[0];
  *(undefined4 *)(iVar2 + 0xc) = local_38;
  if ((param_1[param_2 * 6 + 0x28] & 2U) != 0) {
    FUN_00103d50(param_1 + param_2 * 6 + 0x23,2,0);
    FUN_00103d50(iVar2 + 0xa4,2,1);
  }
  iVar3 = FUN_00165604(iVar4,iVar2);
  iVar5 = 1;
  if (*(int *)(iVar3 + 0x158) == 0) {
    *(int *)(*(int *)(param_3 + 0x6c4) + 0x238) = *(int *)(*(int *)(param_3 + 0x6c4) + 0x238) + 1;
    iVar2 = (**(code **)(*param_1 + 0x28))(param_1);
    if (iVar2 == 0) {
      FUN_000e7700(iVar4,param_1,iVar3);
    }
    else {
      for (piVar6 = (int *)param_1[1]; piVar6 != (int *)0x0; piVar6 = (int *)piVar6[1]) {
        iVar2 = (**(code **)(*piVar6 + 0x28))(piVar6);
        if (iVar2 == 0) {
          FUN_000e7738(iVar4,piVar6,iVar3);
          return iVar3;
        }
      }
      FUN_000e76c4(iVar4,iVar3);
    }
  }
  else {
    for (; iVar4 = (**(code **)(*param_1 + 0x14))(param_1), iVar5 <= iVar4; iVar5 = iVar5 + 1) {
      iVar4 = FUN_00105594(param_1,iVar5);
      if (iVar2 == iVar4) {
        FUN_00106004(param_1,iVar5,iVar3,0,param_3);
      }
    }
  }
  return iVar3;
}

/* FUN_0017281c @ 0x17281c (416 bytes) */
int FUN_0017281c(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x38) + 0x28))(*(int **)(param_2 + 0x38));
  if ((iVar1 != 0) &&
     (iVar1 = (**(code **)(*param_1 + 0x20))(param_1,*(undefined4 *)(param_2 + 0x38)), iVar1 != 0))
  {
    param_1[2] = *(int *)(param_2 + 0x2c);
  }
  puVar8 = *(uint **)(param_2 + 0x44);
  uVar5 = puVar8[1];
  if (0 < (int)uVar5) {
    uVar7 = 0;
    uVar6 = 1;
    iVar1 = 0;
    while( true ) {
      if (uVar7 < *puVar8) {
        uVar2 = puVar8[1];
        if (uVar2 <= uVar7) {
          _memset((void *)(uVar2 * 4 + puVar8[2]),0,(uVar7 - uVar2) * 4 + 4);
          puVar8[1] = uVar6;
        }
        piVar3 = (int *)(iVar1 + puVar8[2]);
      }
      else {
        piVar3 = (int *)FUN_0019423c(puVar8,uVar7);
      }
      if (*(int *)(*piVar3 + 0x1c) != 0) {
        puVar8 = *(uint **)(param_2 + 0x44);
        if (uVar7 < *puVar8) {
          uVar2 = puVar8[1];
          if (uVar2 <= uVar7) {
            _memset((void *)(uVar2 * 4 + puVar8[2]),0,(uVar7 - uVar2) * 4 + 4);
            puVar8[1] = uVar6;
          }
          puVar4 = (undefined4 *)(iVar1 + puVar8[2]);
        }
        else {
          puVar4 = (undefined4 *)FUN_0019423c(puVar8,uVar7);
        }
        if (param_1[1] <= *(int *)(*(int *)*puVar4 + 0x2c)) {
          *(uint *)(*(int *)(param_2 + 0x38) + 0x14) =
               *(uint *)(*(int *)(param_2 + 0x38) + 0x14) | 0x1000;
          param_1[1] = *(int *)(param_2 + 0x2c);
        }
      }
      uVar7 = uVar7 + 1;
      uVar6 = uVar6 + 1;
      iVar1 = iVar1 + 4;
      if (uVar5 == uVar7) break;
      puVar8 = *(uint **)(param_2 + 0x44);
    }
  }
  return;
}

/* FUN_001729bc @ 0x1729bc (108 bytes) */
int FUN_001729bc(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 1;
  iVar4 = param_1;
  do {
    iVar2 = param_1;
    iVar5 = iVar3;
    if (*(int *)(param_1 + 0x20) == *(int *)(iVar4 + 0x24)) {
      return 1;
    }
    while (iVar5 + -1 != 0) {
      piVar1 = (int *)(iVar2 + 0x24);
      iVar2 = iVar2 + 4;
      iVar5 = iVar5 + -1;
      if (*(int *)(iVar4 + 0x24) == *piVar1) {
        return 1;
      }
    }
    iVar2 = 4 - iVar3;
    do {
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 4;
      iVar2 = iVar2 + -1;
      if (iVar2 == 0) {
        return 0;
      }
    } while (iVar3 < 1);
  } while( true );
}

/* FUN_00172a28 @ 0x172a28 (104 bytes) */
int FUN_00172a28(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = FUN_000e07dc(*(undefined4 *)(param_1 + 0x238),9);
  if ((iVar1 != 0) && (iVar1 = FUN_000e07dc(*(undefined4 *)(param_1 + 0x238),0x30), iVar1 != 0)) {
    FUN_0017f78c(param_1);
    return;
  }
  return;
}

/* FUN_00172a90 @ 0x172a90 (32 bytes) */
int FUN_00172a90(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_2 + 4) = uVar1;
  FUN_0010ac38(param_1,1,2);
  return;
}

/* FUN_00172ab0 @ 0x172ab0 (40 bytes) */
int FUN_00172ab0(param_1)
  int param_1;
{
  return *(int *)(param_1 + 4) % 0x65;
}

/* FUN_00172ad8 @ 0x172ad8 (28 bytes) */
int FUN_00172ad8(param_1, param_2)
  int param_1;
  int param_2;
{
  return -(uint)(*(int *)(param_1 + 4) != *(int *)(param_2 + 4));
}

/* FUN_00172af4 @ 0x172af4 (56 bytes) */
int FUN_00172af4(param_1)
  int *param_1;
{
  return (*param_1 * 0x25) % 0x65;
}

/* FUN_00172b2c @ 0x172b2c (28 bytes) */
int FUN_00172b2c(param_1, param_2)
  int *param_1;
  int *param_2;
{
  return -(uint)(*param_1 != *param_2);
}

/* FUN_00172b48 @ 0x172b48 (40 bytes) */
int FUN_00172b48(param_1)
  int *param_1;
{
  return *param_1 % 0x65;
}

/* FUN_00172b70 @ 0x172b70 (48 bytes) */
int FUN_00172b70(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int iVar1;
  
  iVar1 = FUN_00176264(*param_1,*param_2);
  return -(uint)(iVar1 == 0);
}

/* FUN_00172ba0 @ 0x172ba0 (48 bytes) */
int FUN_00172ba0(param_1)
  int param_1;
{
  return *(uint *)(*(int *)(param_1 + 4) + 0xb4) % 0x65;
}

/* FUN_00172bd0 @ 0x172bd0 (332 bytes) */
int FUN_00172bd0(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 *puVar13;
  
  iVar12 = *(int *)(param_1 + 4);
  iVar10 = *(int *)(param_2 + 4);
  piVar9 = *(int **)(iVar12 + 0xb0);
  iVar7 = *(int *)(param_1 + 8);
  iVar8 = *(int *)(param_2 + 8);
  iVar3 = FUN_0011379c(*(undefined4 *)(iVar12 + 0x238),piVar9);
  iVar5 = iVar12 + 0xb4;
  iVar6 = iVar10 + 0xb4;
  if ((((iVar3 == 0) || (*(int *)(iVar12 + 0xb4) != *(int *)(iVar10 + 0xb4))) ||
      (*(int *)(iVar12 + 0xc0) != *(int *)(iVar10 + 0xc0))) ||
     (*(int *)(iVar12 + 0xc4) != *(int *)(iVar10 + 0xc4))) {
LAB_00172d04:
    uVar4 = 0xffffffff;
  }
  else {
    iVar7 = iVar7 * 4 + iVar5;
    iVar3 = iVar8 * 4 + iVar6;
    iVar8 = iVar7 + 0x14;
    iVar10 = iVar3 + 0x14;
    puVar11 = (undefined4 *)(iVar7 + 0xc4);
    puVar13 = (undefined4 *)(iVar3 + 0xc4);
    for (iVar3 = 1; iVar7 = (**(code **)(*piVar9 + 0x14))(piVar9), iVar3 <= iVar7; iVar3 = iVar3 + 1
        ) {
      iVar7 = FUN_00176264(*puVar11,*puVar13);
      if (((iVar7 == 0) || (*(int *)(iVar5 + 0x108) != *(int *)(iVar6 + 0x108))) ||
         (*(int *)(iVar8 + 0x20) != *(int *)(iVar10 + 0x20))) goto LAB_00172d04;
      piVar1 = (int *)(iVar8 + 0x30);
      iVar5 = iVar5 + 4;
      piVar2 = (int *)(iVar10 + 0x30);
      iVar8 = iVar8 + 0x20;
      iVar10 = iVar10 + 0x20;
      iVar6 = iVar6 + 4;
      puVar11 = puVar11 + 4;
      puVar13 = puVar13 + 4;
      if (*piVar1 != *piVar2) goto LAB_00172d04;
    }
    uVar4 = 0;
  }
  return uVar4;
}

/* FUN_00172d1c @ 0x172d1c (168 bytes) */
int FUN_00172d1c(param_1)
  int param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 1;
  for (iVar4 = 0; iVar3 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(), iVar4 < iVar3;
      iVar4 = iVar4 + 1) {
    iVar3 = 4;
    piVar2 = (int *)(iVar4 * 0x10 + param_1 + 0x168);
    do {
      iVar1 = *piVar2;
      piVar2 = piVar2 + 1;
      iVar5 = iVar5 * iVar1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return (iVar5 + *(int *)(param_1 + 0xb4)) % 0x65;
}

/* FUN_00172dc4 @ 0x172dc4 (56 bytes) */
int FUN_00172dc4(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = _memcmp((void *)(param_1 + 0xb4),(void *)(param_2 + 0xb4),0x15c);
  return (iVar1 == 0) - 1;
}

/* FUN_00172dfc @ 0x172dfc (8 bytes) */
int FUN_00172dfc()
{
  return 0;
}

/* FUN_00172e04 @ 0x172e04 (116 bytes) */
int FUN_00172e04(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 4;
  iVar2 = param_2;
  iVar3 = param_1;
  while( true ) {
    if (((*(int *)(iVar3 + 0x20) != *(int *)(iVar2 + 0x20)) && (*(int *)(iVar3 + 0x20) != 3)) &&
       (*(int *)(iVar2 + 0x20) != 3)) break;
    iVar3 = iVar3 + 4;
    iVar2 = iVar2 + 4;
    iVar4 = iVar4 + -1;
    if (iVar4 == 0) {
      iVar2 = 0;
      do {
        if (*(int *)(param_1 + 0xb8) != *(int *)(param_2 + 0xb8)) {
          return 0xffffffff;
        }
        bVar1 = iVar2 != 1;
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
        iVar2 = iVar2 + 1;
      } while (bVar1);
      return 0;
    }
  }
  return 0xffffffff;
}

/* FUN_00172e78 @ 0x172e78 (92 bytes) */
int FUN_00172e78(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = 4;
  iVar4 = 0;
  iVar3 = 0;
  do {
    uVar1 = *(uint *)(iVar3 + param_1 + 0x20);
    uVar5 = (int)uVar1 >> 0x1f;
    iVar2 = (uVar5 ^ uVar1) - uVar5;
    if (iVar4 < iVar2) {
      iVar4 = iVar2;
    }
    iVar3 = iVar3 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return iVar4 % 0x65;
}

/* FUN_00172ed4 @ 0x172ed4 (20 bytes) */
int FUN_00172ed4(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3c8) + 1;
  *(int *)(param_1 + 0x3c8) = iVar1;
  return iVar1;
}

/* FUN_00172ee8 @ 0x172ee8 (20 bytes) */
int FUN_00172ee8(param_1)
  int param_1;
{
  *(int *)(param_1 + 0x3cc) = *(int *)(param_1 + 0x3cc) + -1;
  return;
}

/* FUN_00172efc @ 0x172efc (8 bytes) */
int FUN_00172efc(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x3c8);
}

/* FUN_00172f0c @ 0x172f0c (20 bytes) */
int FUN_00172f0c(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x3cc) = 0xfffffffe;
  *(undefined4 *)(param_1 + 0x3c8) = 4;
  return;
}

/* FUN_00172f24 @ 0x172f24 (8 bytes) */
int FUN_00172f24()
{
  return 0;
}

/* FUN_00172f34 @ 0x172f34 (124 bytes) */
int FUN_00172f34(param_1)
  int param_1;
{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  iVar5 = param_1;
  do {
    iVar3 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    cVar2 = *(char *)(iVar4 + iVar3 + 0x10);
    if (cVar2 == '\0') {
      *(undefined4 *)(iVar5 + 0x20) = *(undefined4 *)(iVar5 + 0x178);
    }
    else if (cVar2 == '\x01') {
      *(undefined4 *)(iVar5 + 0x20) = *(undefined4 *)(iVar5 + 0x10);
    }
    bVar1 = iVar4 != 3;
    iVar5 = iVar5 + 4;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  return;
}

/* FUN_00172fb0 @ 0x172fb0 (4 bytes) */
int FUN_00172fb0()
{
  return;
}

/* FUN_00172fb4 @ 0x172fb4 (4 bytes) */
int FUN_00172fb4()
{
  return;
}

/* FUN_00172fb8 @ 0x172fb8 (96 bytes) */
int FUN_00172fb8(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x54))();
  if ((iVar1 == 0) || (uVar2 = 1, *(int *)(*(int *)(param_1 + 0xb0) + 0xb0) != 0x2a)) {
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_00173018 @ 0x173018 (332 bytes) */
int FUN_00173018(param_1)
  int param_1;
{
  int *piVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 local_28;
  
  local_28 = DAT_001b01bc;
  iVar6 = 1;
  iVar7 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
  *(int *)(iVar7 + 0xa8) = *(int *)(iVar7 + 0xa8) + 1;
  iVar7 = param_1;
  do {
    if (*(int *)(param_1 + 0x20) == *(int *)(iVar7 + 0x24)) {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\0';
      iVar4 = param_1;
      iVar8 = iVar6;
      do {
        cVar3 = cVar3 + '\x01';
        iVar8 = iVar8 + -1;
        if (iVar8 == 0) goto LAB_001730b4;
        piVar1 = (int *)(iVar4 + 0x24);
        iVar4 = iVar4 + 4;
      } while (*piVar1 != *(int *)(iVar7 + 0x24));
    }
    iVar4 = *(int *)(param_1 + 0xb0);
    *(char *)((int)&local_28 + iVar6) = cVar3;
    *(undefined1 *)(iVar6 + iVar4 + 0x9c) = 1;
LAB_001730b4:
    iVar4 = 4 - iVar6;
    do {
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 4;
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) {
        uVar5 = FUN_001084b8(0x31,*(undefined4 *)(param_1 + 0x238));
        FUN_001046c8(uVar5,0,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c));
        FUN_001046c8(uVar5,1,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c));
        uVar2 = local_28;
        iVar7 = FUN_001054ec(uVar5,1);
        *(undefined4 *)(iVar7 + 0x10) = uVar2;
        FUN_000e7738(*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158),*(int *)(param_1 + 0xb0),
                     uVar5);
        FUN_000ed63c(*(undefined4 *)(*(int *)(param_1 + 0x238) + 0x6c4),uVar5);
        return 1;
      }
    } while (iVar6 < 1);
  } while( true );
}

/* FUN_00173164 @ 0x173164 (196 bytes) */
int FUN_00173164(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 local_38 [6];
  
  iVar3 = 0;
  piVar4 = (int *)(param_2 + 0x20);
  local_38[0] = DAT_001b01b8;
  do {
    iVar2 = FUN_001054ec(*(undefined4 *)(param_2 + 0xb0),0);
    if (*(char *)(iVar3 + iVar2 + 0x10) != '\x01') {
      iVar5 = 4;
      iVar2 = 0;
      while (*(int *)(param_3 + 0x20 + iVar2 * 4) != *piVar4) {
        iVar2 = iVar2 + 1;
        iVar5 = iVar5 + -1;
        if (iVar5 == 0) {
          *param_1 = DAT_001b01b8;
          return param_1;
        }
      }
      *(char *)((int)local_38 + iVar3) = (char)iVar2;
    }
    bVar1 = iVar3 != 3;
    piVar4 = piVar4 + 1;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  *param_1 = local_38[0];
  return param_1;
}

/* FUN_00173228 @ 0x173228 (80 bytes) */
int FUN_00173228(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int local_18 [5];
  
  ((int (*)())FUN_00173164)(local_18,param_2,param_1);
  return -(uint)(local_18[0] == DAT_001b01b8);
}

/* FUN_00173278 @ 0x173278 (184 bytes) */
int FUN_00173278(param_1)
  undefined4 *param_1;
{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar4 = 0;
  puVar5 = param_1;
  do {
    iVar3 = FUN_001054ec(param_1[0x2c],0);
    cVar2 = *(char *)(iVar4 + iVar3 + 0x10);
    if (cVar2 == '\0') {
      puVar5[8] = *puVar5;
      puVar5[0x1c] = puVar5[0x14];
      puVar5[0x28] = puVar5[0x20];
    }
    else if (cVar2 == '\x01') {
      if ((*(uint *)(param_1[0x2c] + 0x14) & 0x200) == 0) {
        puVar5[8] = 2;
      }
      else {
        puVar5[8] = puVar5[4];
        puVar5[0x1c] = puVar5[0x18];
        puVar5[0x28] = puVar5[0x24];
      }
    }
    bVar1 = iVar4 != 3;
    puVar5 = puVar5 + 1;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  return;
}

/* FUN_00173330 @ 0x173330 (48 bytes) */
int FUN_00173330(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  
  **(undefined4 **)(param_1 + 0x3f4) = param_2;
  uVar1 = FUN_00194834(*(undefined4 *)(param_1 + 1000),*(undefined4 *)(param_1 + 0x3f4));
  return uVar1;
}

/* FUN_00173360 @ 0x173360 (64 bytes) */
int FUN_00173360(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  
  *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 4) = param_2;
  **(undefined4 **)(param_1 + 0x3f0) = 0x7ffffffe;
  uVar1 = FUN_00194834(*(undefined4 *)(param_1 + 0x3e0),*(undefined4 *)(param_1 + 0x3f0));
  return uVar1;
}

