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
    iVar4 = (**(code **)(*(int *)param_1[3] + 0x18))((int *)param_1[3]);
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
    iVar4 = (**(code **)(*(int *)param_1[3] + 0x18))((int *)param_1[3]);
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
          _memset(uVar3 * 4 + puVar13[2],0,(uVar11 - uVar3) * 4 + 4);
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
        if ((iVar5 != 0) &&
           (iVar5 = (**(code **)(**(int **)(iVar12 + 0x38) + 0x5c))(*(int **)(iVar12 + 0x38)),
           iVar5 != 0)) {
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
       (iVar5 = FUN_001054ec(piVar9,0), *(int *)(iVar5 + 0x10) != 0x1010101)) {
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
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x38) + 0x5c))(*(int **)(param_2 + 0x38),param_2);
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
  iVar1 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0xd4))(*(int **)(*param_1 + 0x30c));
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
  undefined4 a3;
  undefined4 in_r7;
  int *in_r8;
  int *a0;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  uint *puVar14;
  undefined4 uVar15;
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
  iVar9 = *(int *)(param_2 + 0x38);
  iVar11 = 0;
  iVar3 = FUN_001054ec(iVar9,1);
  FUN_000f2c5c(*(undefined4 *)(iVar3 + 0x10));
  do {
    iVar3 = FUN_001054ec(iVar9,0);
    if (*(char *)(iVar11 + iVar3 + 0x10) != '\x01') {
      iVar3 = FUN_001054ec(iVar9,1);
      uVar6 = (uint)*(byte *)(iVar11 + iVar3 + 0x10);
      goto LAB_0016d5f8;
    }
    bVar1 = iVar11 != 3;
    iVar11 = iVar11 + 1;
  } while (bVar1);
  uVar6 = 4;
LAB_0016d5f8:
  iVar3 = param_1[0x61];
  if (0 < iVar3) {
    uVar10 = 0;
    piVar5 = param_1;
    do {
      if (piVar5[0x5c] != 0) {
        iVar3 = FUN_00105594(*(undefined4 *)(piVar5[0x5c] + 0x38),1);
        iVar11 = FUN_00105594(iVar9,1);
        if (iVar3 == iVar11) {
          iVar11 = piVar5[0x5c];
          iVar12 = *(int *)(iVar11 + 0x38);
          iVar7 = uVar10 + (((int)uVar10 >> 2) + (uint)((int)uVar10 < 0 && (uVar10 & 3) != 0)) * -4;
          iVar3 = FUN_001054ec(iVar12,1);
          if ((uVar6 == *(byte *)(iVar7 + iVar3 + 0x10)) &&
             (iVar3 = (**(code **)(**(int **)(iVar12 + 0x88) + 0x18))(*(int **)(iVar12 + 0x88)),
             iVar3 == *(int *)(iVar9 + 300))) {
            FUN_00106004(iVar9,1,iVar12,0,*param_1);
            uVar13 = *(undefined4 *)(PTR_DAT_001e8b8c + iVar7 * 4);
            iVar3 = FUN_001054ec(iVar9,1);
            *(undefined4 *)(iVar3 + 0x10) = uVar13;
            if (*(int *)(iVar11 + 0x6c) != 0) {
              *(int *)(param_2 + 0x6c) = *(int *)(iVar11 + 0x6c);
            }
            puVar14 = *(uint **)(param_2 + 0x40);
            uVar10 = 0;
            *(int *)(iVar11 + 0x6c) = param_2;
            uVar6 = puVar14[1];
            if ((int)uVar6 < 1) {
              return 1;
            }
            while( true ) {
              if (uVar10 < *puVar14) {
                uVar4 = puVar14[1];
                if (uVar4 <= uVar10) {
                  _memset(uVar4 * 4 + puVar14[2],0,(uVar10 - uVar4) * 4 + 4);
                  puVar14[1] = uVar10 + 1;
                }
                piVar5 = (int *)(uVar10 * 4 + puVar14[2]);
              }
              else {
                piVar5 = (int *)FUN_0019423c(puVar14,uVar10);
              }
              uVar10 = uVar10 + 1;
              iVar3 = *piVar5;
              iVar9 = *(int *)(iVar3 + 4);
              if (*(int *)(iVar3 + 8) == 0) {
                local_58[0] = 0;
                *(undefined1 *)((int)local_58 + iVar7) = 1;
                FUN_00165b7c(param_1,iVar11,iVar9,*(undefined4 *)(iVar3 + 0x10),
                             *(undefined4 *)(iVar3 + 0x14),local_58[0],(uint)local_58);
                *(int *)(iVar9 + 0x34) = *(int *)(iVar9 + 0x34) + -1;
              }
              if (uVar6 == uVar10) break;
              puVar14 = *(uint **)(param_2 + 0x40);
            }
            return 1;
          }
        }
        iVar3 = param_1[0x61];
      }
      uVar10 = uVar10 + 1;
      piVar5 = piVar5 + 1;
    } while ((int)uVar10 < iVar3);
    if (0 < iVar3) {
      iVar11 = param_1[0x5c];
      if (iVar11 == 0) {
        uVar8 = 0;
        iVar3 = 0;
      }
      else {
        uVar4 = 0;
        uVar10 = 0xffffffff;
        in_r8 = param_1;
        do {
          if ((*(int *)((uVar4 + (((int)uVar4 >> 2) + (uint)((int)uVar4 < 0 && (uVar4 & 3) != 0)) *
                                 -4) * 4 + iVar11 + 0x48) == 0) &&
             (((int)uVar10 < 0 ||
              (*(int *)(iVar11 + 0x2c) < *(int *)(param_1[uVar10 + 0x5c] + 0x2c))))) {
            uVar10 = uVar4;
          }
          uVar4 = uVar4 + 1;
          iVar3 = iVar3 + -1;
          uVar8 = uVar10;
          if (iVar3 == 0) break;
          iVar11 = in_r8[0x5d];
          in_r8 = in_r8 + 1;
          uVar8 = uVar4;
        } while (iVar11 != 0);
        if ((int)uVar8 < 0) {
          return 0;
        }
        iVar3 = uVar8 + (((int)uVar8 >> 2) + (uint)((int)uVar8 < 0 && (uVar8 & 3) != 0)) * -4;
      }
      uVar4 = uVar8 - iVar3;
      uVar10 = uVar4 + 4;
      piVar5 = param_1 + uVar4 + 0x5c;
      do {
        if ((((*(uint *)(*(int *)(*param_1 + 0x30c) + 8) & 0x200) == 0) && (*piVar5 != 0)) &&
           (uVar4 != uVar8)) {
          iVar11 = FUN_00105594(*(undefined4 *)(*piVar5 + 0x38),1);
          iVar7 = FUN_00105594(iVar9,1);
          if (iVar11 == iVar7) {
            iVar11 = *piVar5;
            a0 = *(int **)(iVar11 + 0x38);
            if (*(int *)(iVar9 + 300) == 0) {
              if (*(int *)(a0[0x22] + 8) == 0xa6) goto LAB_0016d91c;
            }
            else if (*(int *)(a0[0x22] + 8) == 0x2b) {
LAB_0016d91c:
              if ((param_1[uVar8 + 0x5c] == 0) ||
                 (iVar7 = FUN_00167a74(param_1[uVar8 + 0x5c],iVar3), iVar7 < *(int *)(iVar11 + 0x2c)
                 )) {
                *(undefined1 *)((int)a0 + iVar3 + 0x9c) = 0;
                (**(code **)(*a0 + 0x88))(a0,1,iVar3,uVar6,in_r7,in_r8,*(code **)(*a0 + 0x88));
                *(undefined1 *)((int)a0 + iVar3 + 0xc) = 1;
                iVar7 = *param_1;
                param_1[uVar8 + 0x5c] = iVar11;
                FUN_00106004(iVar9,1,a0,0,iVar7);
                uVar13 = *(undefined4 *)(PTR_DAT_001e8b8c + iVar3 * 4);
                iVar9 = FUN_001054ec(iVar9,1);
                *(undefined4 *)(iVar9 + 0x10) = uVar13;
                if (*(int *)(iVar11 + 0x6c) != 0) {
                  *(int *)(param_2 + 0x6c) = *(int *)(iVar11 + 0x6c);
                }
                puVar14 = *(uint **)(param_2 + 0x40);
                uVar10 = 0;
                *(int *)(iVar11 + 0x6c) = param_2;
                uVar6 = puVar14[1];
                if ((int)uVar6 < 1) {
                  return 1;
                }
                while( true ) {
                  if (uVar10 < *puVar14) {
                    uVar4 = puVar14[1];
                    if (uVar4 <= uVar10) {
                      _memset(uVar4 * 4 + puVar14[2],0,(uVar10 - uVar4) * 4 + 4);
                      puVar14[1] = uVar10 + 1;
                    }
                    piVar5 = (int *)(uVar10 * 4 + puVar14[2]);
                  }
                  else {
                    piVar5 = (int *)FUN_0019423c(puVar14,uVar10);
                  }
                  uVar10 = uVar10 + 1;
                  iVar9 = *piVar5;
                  iVar7 = *(int *)(iVar9 + 4);
                  if (*(int *)(iVar9 + 8) == 0) {
                    local_58[0] = 0;
                    *(undefined1 *)((int)local_58 + iVar3) = 1;
                    FUN_00165b7c(param_1,iVar11,iVar7,*(undefined4 *)(iVar9 + 0x10),
                                 *(undefined4 *)(iVar9 + 0x14),local_58[0],(uint)local_58);
                    *(int *)(iVar7 + 0x34) = *(int *)(iVar7 + 0x34) + -1;
                  }
                  if (uVar6 == uVar10) break;
                  puVar14 = *(uint **)(param_2 + 0x40);
                }
                return 1;
              }
            }
          }
        }
        uVar4 = uVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (uVar10 != uVar4);
      iVar11 = (**(code **)(*(int *)param_1[2] + 0x80))
                         ((int *)param_1[2],param_1[0x60],*(undefined4 *)(iVar9 + 300),
                          *(undefined4 *)(iVar9 + 0x130),*(int *)(iVar9 + 0x98) == 0x3a);
      puVar2 = PTR_DAT_001e8b64;
      param_1[0x60] = iVar11;
      *(undefined4 *)(iVar11 + 0x98) = 0x20;
      *(uint *)(iVar11 + 0x94) = ((int)uVar8 >> 2) + (uint)((int)uVar8 < 0 && (uVar8 & 3) != 0);
      *(undefined4 *)(param_1[0x60] + 0x9c) = *(undefined4 *)(puVar2 + iVar3 * 4);
      iVar11 = param_1[0x60];
      uVar13 = FUN_00105594(iVar9,1);
      iVar7 = *param_1;
      a3 = 0;
      FUN_00106004(iVar11,1,uVar13,0,iVar7);
      puVar2 = PTR_DAT_001e8b8c;
      uVar15 = *(undefined4 *)(PTR_DAT_001e8b8c + uVar6 * 4);
      iVar11 = FUN_001054ec(param_1[0x60],1);
      *(undefined4 *)(iVar11 + 0x10) = uVar15;
      *(undefined4 *)(param_1[0x60] + 0xc) = 0;
      iVar11 = param_1[0x60];
      *(undefined1 *)(iVar11 + iVar3 + 0xc) = 1;
      iVar11 = (**(code **)(*(int *)param_1[2] + 0xc))
                         ((int *)param_1[2],param_1[0x60],uVar13,a3,iVar7,in_r8,iVar11 + iVar3);
      if (iVar11 != 0) {
        iVar11 = FUN_00165d3c(param_1,param_1[0x60],param_2 + 0xc,param_1[0xb]);
        param_1[0x60] = 0;
        param_1[uVar8 + 0x5c] = iVar11;
        FUN_00106004(iVar9,1,*(undefined4 *)(iVar11 + 0x38),0,*param_1);
        uVar13 = *(undefined4 *)(puVar2 + iVar3 * 4);
        iVar9 = FUN_001054ec(iVar9,1);
        *(undefined4 *)(iVar9 + 0x10) = uVar13;
        uVar10 = 0;
        puVar14 = *(uint **)(param_2 + 0x40);
        *(int *)(iVar11 + 0x6c) = param_2;
        uVar6 = puVar14[1];
        if (0 < (int)uVar6) {
          while( true ) {
            if (uVar10 < *puVar14) {
              uVar4 = puVar14[1];
              if (uVar4 <= uVar10) {
                _memset(uVar4 * 4 + puVar14[2],0,(uVar10 - uVar4) * 4 + 4);
                puVar14[1] = uVar10 + 1;
              }
              piVar5 = (int *)(uVar10 * 4 + puVar14[2]);
            }
            else {
              piVar5 = (int *)FUN_0019423c(puVar14,uVar10);
            }
            uVar10 = uVar10 + 1;
            iVar9 = *piVar5;
            uVar13 = *(undefined4 *)(iVar9 + 4);
            if (*(int *)(iVar9 + 8) == 0) {
              local_58[0] = 0;
              *(undefined1 *)((int)local_58 + iVar3) = 1;
              FUN_00165b7c(param_1,iVar11,uVar13,*(undefined4 *)(iVar9 + 0x10),
                           *(undefined4 *)(iVar9 + 0x14),local_58[0],(uint)local_58);
            }
            if (uVar6 == uVar10) break;
            puVar14 = *(uint **)(param_2 + 0x40);
          }
        }
        ((int (*)())FUN_0016d3b0)(param_1,iVar11);
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
        iVar1 = FUN_001648ac(param_1,param_2,iVar3,0);
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
        iVar1 = FUN_001648ac(param_1,param_2,iVar3,0);
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
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *puVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  uint uVar16;
  uint *puVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  
  iVar8 = param_1[0x61];
  if (0 < iVar8) {
    uVar10 = 0;
    puVar12 = param_1;
    do {
      iVar13 = puVar12[0x5c];
      iVar9 = uVar10 + (((int)uVar10 >> 2) + (uint)((int)uVar10 < 0 && (uVar10 & 3) != 0)) * -4;
      if ((iVar13 != 0) && (*(int *)(iVar13 + 0x2c) < (int)param_1[0xb])) {
        puVar12[0x5c] = 0;
        if ((0 < *(int *)(iVar9 * 4 + iVar13 + 0x48)) &&
           (iVar15 = *(int *)(iVar13 + 0x6c), iVar15 != 0)) {
          do {
            iVar8 = FUN_001054ec(*(undefined4 *)(iVar15 + 0x38),1);
            if (*(int *)(iVar8 + 0x10) == (DAT_001aa818)[iVar9]) {
              iVar19 = 4;
              iVar8 = iVar15;
LAB_0016e258:
              if (*(int *)(iVar8 + 0x48) < 1) goto code_r0x0016e264;
              uVar3 = FUN_0010445c(*(undefined4 *)(iVar15 + 0x38),*param_1,0);
              uVar4 = FUN_00105594(*(undefined4 *)(iVar13 + 0x38),1);
              FUN_00106004(uVar3,1,uVar4,0,*param_1);
              iVar8 = FUN_001054ec(*(undefined4 *)(iVar13 + 0x38),1);
              uVar4 = (DAT_001aa818)[*(byte *)(iVar9 + iVar8 + 0x10)];
              iVar8 = FUN_001054ec(uVar3,1);
              *(undefined4 *)(iVar8 + 0x10) = uVar4;
              uVar5 = 0;
              iVar8 = FUN_00165d3c(param_1,uVar3,iVar15 + 0xc,param_1[0xb]);
              puVar17 = *(uint **)(iVar15 + 0x40);
              uVar18 = puVar17[1];
              if (0 < (int)uVar18) {
                while( true ) {
                  if (uVar5 < *puVar17) {
                    uVar1 = puVar17[1];
                    if (uVar1 <= uVar5) {
                      _memset(uVar1 * 4 + puVar17[2],0,(uVar5 - uVar1) * 4 + 4);
                      puVar17[1] = uVar5 + 1;
                    }
                    puVar6 = (undefined4 *)(uVar5 * 4 + puVar17[2]);
                  }
                  else {
                    puVar6 = (undefined4 *)FUN_0019423c(puVar17,uVar5);
                  }
                  uVar5 = uVar5 + 1;
                  piVar14 = (int *)*puVar6;
                  iVar7 = 1;
                  iVar19 = piVar14[1];
                  if (*(int *)(iVar19 + 0x2c) < 0) {
                    for (; iVar21 = (**(code **)(**(int **)(iVar19 + 0x38) + 0x14))
                                              (*(int **)(iVar19 + 0x38)), iVar7 <= iVar21;
                        iVar7 = iVar7 + 1) {
                      iVar21 = FUN_00105594(*(undefined4 *)(iVar19 + 0x38),iVar7);
                      if (iVar21 == *(int *)(iVar15 + 0x38)) {
                        FUN_00106004(*(undefined4 *)(iVar19 + 0x38),iVar7,uVar3,0,*param_1);
                      }
                    }
                    *piVar14 = iVar8;
                    puVar17 = *(uint **)(iVar8 + 0x40);
                    uVar1 = puVar17[1];
                    if (uVar1 < *puVar17) {
                      _memset(uVar1 * 4 + puVar17[2],0,4);
                      puVar6 = (undefined4 *)(uVar1 * 4 + puVar17[2]);
                      puVar17[1] = uVar1 + 1;
                    }
                    else {
                      puVar6 = (undefined4 *)FUN_0019423c(puVar17,uVar1);
                    }
                    *puVar6 = piVar14;
                    iVar20 = 4;
                    iVar7 = iVar8;
                    iVar21 = iVar15;
                    do {
                      if (*(char *)(piVar14 + 6) != '\0') {
                        *(int *)(iVar7 + 0x48) = *(int *)(iVar7 + 0x48) + 1;
                        *(int *)(iVar21 + 0x48) = *(int *)(iVar21 + 0x48) + -1;
                      }
                      piVar14 = (int *)((int)piVar14 + 1);
                      iVar7 = iVar7 + 4;
                      iVar21 = iVar21 + 4;
                      iVar20 = iVar20 + -1;
                    } while (iVar20 != 0);
                    puVar17 = *(uint **)(iVar19 + 0x44);
                    uVar1 = puVar17[1];
                    uVar16 = uVar1 - 1;
                    if (-1 < (int)uVar16) {
                      iVar7 = uVar16 * 4;
                      uVar11 = 0;
                      while( true ) {
                        if (uVar16 < *puVar17) {
                          uVar2 = puVar17[1];
                          if (uVar2 <= uVar16) {
                            _memset(uVar2 * 4 + puVar17[2],0,(uVar16 - uVar2) * 4 + 4);
                            puVar17[1] = uVar16 + 1;
                          }
                          puVar6 = (undefined4 *)(iVar7 + puVar17[2]);
                        }
                        else {
                          puVar6 = (undefined4 *)FUN_0019423c(puVar17,uVar16);
                        }
                        if ((iVar13 == *(int *)*puVar6) &&
                           (*(char *)((int)*puVar6 + iVar9 + 0x18) != '\0')) {
                          FUN_00194208(*(undefined4 *)(iVar19 + 0x44),uVar16);
                          iVar21 = iVar9 * 4 + iVar13;
                          *(int *)(iVar21 + 0x48) = *(int *)(iVar21 + 0x48) + -1;
                        }
                        uVar11 = uVar11 + 1;
                        uVar16 = uVar16 - 1;
                        iVar7 = iVar7 + -4;
                        if (uVar1 == uVar11) break;
                        puVar17 = *(uint **)(iVar19 + 0x44);
                      }
                    }
                    iVar7 = *(int *)(iVar19 + 0x34);
                    if (iVar7 == 0) {
                      FUN_0019401c(iVar19);
                      iVar7 = *(int *)(iVar19 + 0x34);
                    }
                    *(int *)(iVar19 + 0x34) = iVar7 + 1;
                  }
                  if (uVar18 == uVar5) break;
                  puVar17 = *(uint **)(iVar15 + 0x40);
                }
              }
              ((int (*)())FUN_0016df8c)(param_1,iVar8);
            }
LAB_0016e574:
            iVar15 = *(int *)(iVar15 + 0x6c);
          } while (iVar15 != 0);
          iVar8 = param_1[0x61];
        }
      }
      uVar10 = uVar10 + 1;
      puVar12 = puVar12 + 1;
    } while ((int)uVar10 < iVar8);
  }
  puVar12 = param_1;
  do {
    iVar8 = puVar12[0x62];
    if ((iVar8 != 0) && (*(int *)(iVar8 + 0x2c) < (int)param_1[0xb])) {
      puVar12[0x62] = 0;
      for (iVar9 = *(int *)(iVar8 + 0x6c); iVar9 != 0; iVar9 = *(int *)(iVar9 + 0x6c)) {
        iVar15 = 4;
        iVar13 = iVar9;
        while (*(int *)(iVar13 + 0x48) < 1) {
          iVar13 = iVar13 + 4;
          iVar15 = iVar15 + -1;
          if (iVar15 == 0) goto LAB_0016e800;
        }
        uVar3 = FUN_0010445c(*(undefined4 *)(iVar9 + 0x38),*param_1,0);
        uVar4 = FUN_00105594(*(undefined4 *)(iVar8 + 0x38),1);
        FUN_00106004(uVar3,1,uVar4,0,*param_1);
        iVar13 = FUN_00165d3c(param_1,uVar3,iVar9 + 0xc,param_1[0xb]);
        puVar17 = *(uint **)(iVar9 + 0x40);
        uVar18 = 0;
        uVar10 = puVar17[1];
        if (0 < (int)uVar10) {
          while( true ) {
            if (uVar18 < *puVar17) {
              uVar5 = puVar17[1];
              if (uVar5 <= uVar18) {
                _memset(uVar5 * 4 + puVar17[2],0,(uVar18 - uVar5) * 4 + 4);
                puVar17[1] = uVar18 + 1;
              }
              puVar6 = (undefined4 *)(uVar18 * 4 + puVar17[2]);
            }
            else {
              puVar6 = (undefined4 *)FUN_0019423c(puVar17,uVar18);
            }
            uVar18 = uVar18 + 1;
            piVar14 = (int *)*puVar6;
            iVar19 = 1;
            iVar15 = piVar14[1];
            if (*(int *)(iVar15 + 0x2c) < 0) {
              for (; iVar7 = (**(code **)(**(int **)(iVar15 + 0x38) + 0x14))
                                       (*(int **)(iVar15 + 0x38)), iVar19 <= iVar7;
                  iVar19 = iVar19 + 1) {
                iVar7 = FUN_00105594(*(undefined4 *)(iVar15 + 0x38),iVar19);
                if (iVar7 == *(int *)(iVar9 + 0x38)) {
                  FUN_00106004(*(undefined4 *)(iVar15 + 0x38),iVar19,uVar3,0,*param_1);
                }
              }
              *piVar14 = iVar13;
              puVar17 = *(uint **)(iVar13 + 0x40);
              uVar5 = puVar17[1];
              if (uVar5 < *puVar17) {
                _memset(uVar5 * 4 + puVar17[2],0,4);
                puVar6 = (undefined4 *)(uVar5 * 4 + puVar17[2]);
                puVar17[1] = uVar5 + 1;
              }
              else {
                puVar6 = (undefined4 *)FUN_0019423c(puVar17,uVar5);
              }
              *puVar6 = piVar14;
              iVar21 = 4;
              iVar19 = iVar13;
              iVar7 = iVar9;
              do {
                if (*(char *)(piVar14 + 6) != '\0') {
                  *(int *)(iVar19 + 0x48) = *(int *)(iVar19 + 0x48) + 1;
                  *(int *)(iVar7 + 0x48) = *(int *)(iVar7 + 0x48) + -1;
                }
                piVar14 = (int *)((int)piVar14 + 1);
                iVar19 = iVar19 + 4;
                iVar7 = iVar7 + 4;
                iVar21 = iVar21 + -1;
              } while (iVar21 != 0);
              iVar19 = *(int *)(iVar15 + 0x34);
              if (iVar19 == 0) {
                FUN_0019401c(iVar15);
                iVar19 = *(int *)(iVar15 + 0x34);
              }
              *(int *)(iVar15 + 0x34) = iVar19 + 1;
            }
            if (uVar10 == uVar18) break;
            puVar17 = *(uint **)(iVar9 + 0x40);
          }
        }
        ((int (*)())FUN_0016df8c)(param_1,iVar13);
LAB_0016e800: ;
      }
    }
    puVar12 = puVar12 + 1;
    if (param_1 + 2 == puVar12) {
      return;
    }
  } while( true );
code_r0x0016e264:
  iVar8 = iVar8 + 4;
  iVar19 = iVar19 + -1;
  if (iVar19 == 0) goto LAB_0016e574;
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
  (**(code **)(*(int *)param_1[2] + 0x14))((int *)param_1[2]);
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
  iVar10 = (**(code **)(*(int *)param_1[2] + 0x5c))((int *)param_1[2]);
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
  iVar10 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0xd4))(*(int **)(*param_1 + 0x30c));
  if ((iVar10 != 0) &&
     (iVar10 = (**(code **)(*(int *)param_1[2] + 0x18))((int *)param_1[2]), iVar10 != 0)) {
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
  
  iVar1 = (**(code **)(*(int *)param_1[2] + 0x50))((int *)param_1[2],param_2);
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
  uint uVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  undefined4 *puVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  undefined *puVar19;
  uint *puVar20;
  uint *puVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  uint uVar25;
  undefined *puVar26;
  uint uVar27;
  uint uVar28;
  undefined *puVar29;
  int iVar30;
  int *piVar31;
  undefined4 uVar32;
  int iVar33;
  int *piStack00000018;
  undefined *local_78;
  undefined *local_74;
  int local_70;
  undefined4 local_6c;
  undefined *local_68;
  undefined *local_64;
  int local_60;
  undefined4 local_5c;
  uint local_58;
  uint local_54;
  int local_50;
  undefined4 in_stack_ffffffb8;
  undefined4 in_stack_ffffffbc;
  
  iVar4 = param_1[0x46];
  if (iVar4 == 0) {
    iVar30 = param_1[0x15];
  }
  else {
    iVar30 = param_1[0xf];
  }
  bVar1 = true;
  iVar24 = 0;
  iVar22 = 0;
  iVar23 = 0;
  while (*(int *)(iVar30 + 8) != 0) {
    piVar9 = *(int **)(iVar30 + 0x38);
    if ((iVar4 == 0) && (param_2 < *(int *)(iVar30 + 0x10))) goto LAB_00170868;
    iVar4 = FUN_001045e4(piVar9);
    if (iVar4 == 0) {
      iVar4 = FUN_00104644(piVar9);
      if (iVar4 != 0) {
        iVar4 = ((int (*)())FUN_0016dd04)(param_1,iVar30);
        iVar22 = iVar22 + 1;
        goto joined_r0x00170058;
      }
      iVar4 = *(int *)(iVar30 + 0x60);
      iVar23 = iVar23 + 1;
      if (iVar4 == 0) {
LAB_0017036c:
        iVar4 = FUN_000e07dc(*param_1,0x25);
        if ((iVar4 != 0) &&
           (((((*(int *)(iVar30 + 0x60) == 0 || (*(int *)(*(int *)(iVar30 + 0x60) + 4) < 0)) &&
              (piVar9[0x26] == 1)) && ((*(int *)(iVar30 + 100) == 0 && ((piVar9[5] & 0x40U) == 0))))
            && ((piVar9[5] & 0x20U) == 0)))) {
          iVar4 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x7c))
                            (*(int **)(*param_1 + 0x30c),piVar9);
          if (iVar4 == 0) {
            iVar4 = 0x1010101;
          }
          else if (*(int **)(iVar30 + 0x60) == (int *)0x0) {
            iVar4 = piVar9[3];
          }
          else {
            iVar4 = **(int **)(iVar30 + 0x60);
          }
          iVar4 = FUN_00167b68(param_1,1,iVar4);
          piVar12 = *(int **)(*param_1 + 0x30c);
          iVar17 = (**(code **)(*piVar12 + 0x138))(piVar12,*param_1);
          if ((iVar4 < 0) || (iVar17 + 4 <= iVar4)) {
            if ((*(int *)(iVar30 + 0x58) == 2) &&
               (iVar4 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],iVar30),
               iVar4 != 0)) {
              ((int (*)())FUN_0017212c)(param_1[2],iVar30);
              (**(code **)(*(int *)param_1[2] + 0x38))((int *)param_1[2],iVar30);
              ((int (*)())FUN_00172078)(param_1[2],iVar30);
            }
            piVar9[0x26] = 0;
          }
        }
        iVar4 = (**(code **)(*(int *)param_1[3] + 0xc))((int *)param_1[3],piVar9);
        if (iVar4 == 0) {
          iVar4 = *(int *)(iVar30 + 8);
          bVar1 = false;
          FUN_0019401c(iVar30);
          FUN_00193f64(param_1 + 0x1f,iVar30);
          iVar30 = iVar4;
        }
        else {
          if ((*(uint *)(*(int *)(*param_1 + 0x30c) + 8) & 0x200) == 0) {
            iVar4 = (**(code **)(*(int *)param_1[2] + 0xc))((int *)param_1[2],piVar9);
            if (iVar4 != 0) goto LAB_001705f8;
            iVar4 = (**(code **)(*(int *)param_1[2] + 0x24))((int *)param_1[2]);
            if (iVar4 != 0) {
              iVar4 = FUN_00167ef4(param_1,iVar30);
              if (iVar4 != 0) {
                return iVar4;
              }
              goto LAB_001705f8;
            }
            iVar4 = FUN_000e07dc(*param_1,0x28);
            if (iVar4 != 0) {
              iVar4 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],iVar30);
              if ((iVar4 != 0) &&
                 (iVar4 = (**(code **)(*(int *)param_1[2] + 0x2c))
                                    ((int *)param_1[2],iVar30,param_1 + 0x4d), iVar4 != 0))
              goto LAB_001705f8;
              iVar13 = 0;
              iVar17 = 0;
              iVar4 = 0;
              iVar14 = 0;
              do {
                iVar18 = *(int *)(param_1[0xc] + iVar14 * 4);
                if (iVar18 != 0) {
                  iVar13 = iVar13 + 1;
                  iVar33 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],iVar18);
                  iVar4 = iVar18;
                  if (iVar33 != 0) {
                    iVar17 = iVar17 + 1;
                  }
                }
                bVar1 = iVar14 != 4;
                iVar14 = iVar14 + 1;
              } while (bVar1);
              if ((iVar13 == 1) && (iVar17 == 1)) {
                (**(code **)(*(int *)param_1[2] + 8))((int *)param_1[2]);
                iVar17 = (**(code **)(*(int *)param_1[2] + 0xc))
                                   ((int *)param_1[2],*(undefined4 *)(iVar30 + 0x38));
                if (iVar17 != 0) {
                  (**(code **)(*(int *)param_1[2] + 0x10))
                            ((int *)param_1[2],*(undefined4 *)(iVar30 + 0x38));
                  iVar17 = (**(code **)(*(int *)param_1[2] + 0x2c))
                                     ((int *)param_1[2],iVar4,param_1 + 0x4d);
                  if (iVar17 != 0) {
                    (**(code **)(*(int *)param_1[2] + 8))((int *)param_1[2]);
                    (**(code **)(*(int *)param_1[2] + 0x10))
                              ((int *)param_1[2],*(undefined4 *)(iVar4 + 0x38));
                    FUN_0019401c(iVar30);
                    return iVar30;
                  }
                }
                (**(code **)(*(int *)param_1[2] + 8))((int *)param_1[2]);
                (**(code **)(*(int *)param_1[2] + 0x10))
                          ((int *)param_1[2],*(undefined4 *)(iVar4 + 0x38));
              }
            }
          }
          else {
            iVar4 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],iVar30);
            if ((iVar4 == 0) || (iVar4 = FUN_000e07dc(*param_1,0x28), iVar4 == 0)) {
              iVar4 = (**(code **)(*(int *)param_1[2] + 0xc))((int *)param_1[2],piVar9);
            }
            else {
              iVar4 = (**(code **)(*(int *)param_1[2] + 0x2c))
                                ((int *)param_1[2],iVar30,param_1 + 0x4d);
            }
            if (iVar4 != 0) goto LAB_001705f8;
          }
          iVar17 = *(int *)(iVar30 + 8);
          FUN_0019401c(iVar30);
          iVar4 = FUN_000e07dc(*param_1,0x27);
          if ((((iVar4 != 0) && (iVar4 = FUN_000e07dc(*param_1,0x2b), iVar4 == 0)) &&
              (param_1[0x46] == 0)) &&
             ((*(int *)(iVar30 + 0x60) == 0 || ((*(uint *)(param_1[1] + 0x30) & 0x2000) != 0)))) {
            iVar4 = (**(code **)(*(int *)param_1[2] + 0x3c))((int *)param_1[2],piVar9);
            if (iVar4 - 1U < 3) {
              bVar1 = false;
              FUN_00193f64(param_1 + (iVar4 - 1U) * 6 + 0x2b,iVar30);
              iVar30 = iVar17;
              goto LAB_00170838;
            }
          }
          FUN_00193f64(param_1 + 0x1f,iVar30);
          bVar1 = false;
          iVar30 = iVar17;
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
            iVar13 = 4;
            iVar17 = *(int *)(*(int *)(iVar30 + 0x60) + 4);
            iVar4 = 0;
            piVar12 = param_1;
            do {
              iVar14 = iVar4 << 2;
              iVar18 = *(int *)(iVar17 * 4 + piVar12[0x4d]);
              uVar7 = 0;
              if (iVar18 != 0) {
                iVar14 = iVar4 * 4;
                uVar7 = *(undefined4 *)(iVar14 + iVar18 + 0x48);
              }
              *(undefined4 *)((int)&local_64 + iVar14) = uVar7;
              iVar4 = iVar4 + 1;
              piVar12 = piVar12 + 1;
              iVar13 = iVar13 + -1;
            } while (iVar13 != 0);
            puVar20 = *(uint **)(iVar30 + 0x44);
            uVar3 = 0;
            uVar16 = puVar20[1];
            if (0 < (int)uVar16) {
              while( true ) {
                if (uVar3 < *puVar20) {
                  uVar10 = puVar20[1];
                  if (uVar10 <= uVar3) {
                    _memset(uVar10 * 4 + puVar20[2],0,(uVar3 - uVar10) * 4 + 4);
                    puVar20[1] = uVar3 + 1;
                  }
                  puVar15 = (undefined4 *)(uVar3 * 4 + puVar20[2]);
                }
                else {
                  puVar15 = (undefined4 *)FUN_0019423c(puVar20,uVar3);
                }
                uVar3 = uVar3 + 1;
                piVar12 = (int *)*puVar15;
                iVar4 = *piVar12;
                if (((((piVar12[2] == 0) && (piVar31 = *(int **)(iVar4 + 0x38), piVar31[0x20] != 0))
                     && ((iVar13 = FUN_00126760(piVar31[0x26]), iVar13 != 0 &&
                         (((piVar31[5] & 2U) == 0 &&
                          (iVar13 = (**(code **)(*piVar31 + 0x50))(piVar31), iVar13 == 0)))))) &&
                    (iVar4 = *(int *)(iVar4 + 0x38), (*(uint *)(iVar4 + 0x14) & 0x40) != 0)) &&
                   (iVar17 == *(int *)(iVar4 + 0x94))) {
                  iVar13 = 4;
                  iVar4 = 0;
                  do {
                    if (*(char *)(piVar12 + 6) != '\0') {
                      *(int *)((int)&local_64 + iVar4) = *(int *)((int)&local_64 + iVar4) + -1;
                    }
                    piVar12 = (int *)((int)piVar12 + 1);
                    iVar4 = iVar4 + 4;
                    iVar13 = iVar13 + -1;
                  } while (iVar13 != 0);
                }
                if (uVar16 == uVar3) break;
                puVar20 = *(uint **)(iVar30 + 0x44);
              }
            }
            iVar4 = 0;
            do {
              iVar17 = FUN_001054ec(piVar9,0);
              if ((*(char *)(iVar4 + iVar17 + 0x10) != '\x01') && (0 < (int)(&local_64)[iVar4]))
              goto LAB_00170968;
              bVar2 = iVar4 != 3;
              iVar4 = iVar4 + 1;
            } while (bVar2);
          }
          iVar4 = *(int *)(iVar30 + 0x60);
          if (iVar4 == 0) goto LAB_0017036c;
        }
        if (*(int *)(iVar4 + 8) == 0) goto LAB_0017036c;
        if (*(int *)(*(int *)(iVar4 + 8) + 0x2c) == param_1[0xb]) {
          iVar17 = FUN_001054ec(piVar9,0);
          pcVar5 = (char *)(iVar4 + 0xc);
          iVar4 = 0;
          local_68 = *(undefined **)(iVar17 + 0x10);
          iVar17 = 4;
          do {
            if ((*pcVar5 != '\x01') && (*(char *)((int)&local_68 + iVar4) != '\x01'))
            goto LAB_00170320;
            iVar4 = iVar4 + 1;
            pcVar5 = pcVar5 + 1;
            iVar17 = iVar17 + -1;
          } while (iVar17 != 0);
          iVar4 = *(int *)(iVar30 + 0x60);
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
        iVar30 = *(int *)(iVar30 + 8);
      }
    }
    else {
      iVar4 = ((int (*)())FUN_0016d538)(param_1,iVar30);
      iVar24 = iVar24 + 1;
joined_r0x00170058:
      if (iVar4 != 0) {
LAB_001705f8:
        FUN_0019401c(iVar30);
        return iVar30;
      }
LAB_00170320:
      iVar4 = *(int *)(iVar30 + 8);
      FUN_0019401c(iVar30);
      FUN_00193f64(param_1 + 0x1f,iVar30);
      iVar30 = iVar4;
    }
LAB_00170838:
    iVar4 = param_1[0x46];
  }
  if (iVar4 == 0) {
LAB_00170868:
    if (((0 < iVar24) || (0 < iVar22)) &&
       ((iVar23 == 0 && (iVar4 = FUN_00193f08(param_1 + 0x19), iVar4 != 0)))) {
      iVar4 = 5;
      piVar9 = (int *)param_1[0xc];
      do {
        if (*piVar9 != 0) goto LAB_001708c4;
        piVar9 = piVar9 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      iVar4 = FUN_00193f08((int *)param_1[0xc] + 5);
      if (iVar4 != 0) {
        if (0 >= iVar24) {
          if (iVar22 < 1) {
            return 0;
          }
          (**(code **)(*(int *)param_1[2] + 0x1c))((int *)param_1[2]);
          return 0;
        }
        iVar4 = param_1[0x61];
        piStack00000018 = param_1;
        if (0 < iVar4) {
          uVar16 = 0;
          do {
            local_60 = param_1[0x5c];
            local_64 = (undefined *)
                       (uVar16 + (((int)uVar16 >> 2) + (uint)((int)uVar16 < 0 && (uVar16 & 3) != 0))
                                 * -4);
            iVar30 = *(int *)(local_60 + 0x6c);
            if (iVar30 != 0) {
              iVar4 = (int)local_64 * 4;
              do {
                iVar22 = FUN_001054ec(*(undefined4 *)(iVar30 + 0x38),1);
                if (*(int *)(iVar22 + 0x10) == *(int *)(PTR_DAT_001e8b8c + iVar4)) {
                  iVar24 = 4;
                  iVar22 = iVar30;
LAB_0016f038:
                  if (*(int *)(iVar22 + 0x48) < 1) goto code_r0x0016f044;
                  puVar19 = PTR_DAT_001e8b8c;
                  FUN_000f31f8(&local_68,0,*(undefined4 *)(*(int *)(iVar30 + 0x38) + 0xc));
                  iVar22 = FUN_00167e1c(piStack00000018,*(undefined4 *)(iVar30 + 0x38),local_68,
                                        piStack00000018[0xb],iVar30 + 0xc);
                  puVar20 = *(uint **)(iVar30 + 0x40);
                  uVar3 = puVar20[1];
                  uVar10 = uVar3 - 1;
                  if (-1 < (int)uVar10) {
                    iVar24 = uVar10 * 4;
                    uVar28 = 0;
                    while( true ) {
                      if (uVar10 < *puVar20) {
                        uVar11 = puVar20[1];
                        if (uVar11 <= uVar10) {
                          _memset(uVar11 * 4 + puVar20[2],0,(uVar10 - uVar11) * 4 + 4);
                          puVar20[1] = uVar10 + 1;
                        }
                        puVar15 = (undefined4 *)(iVar24 + puVar20[2]);
                      }
                      else {
                        puVar15 = (undefined4 *)FUN_0019423c(puVar20,uVar10);
                      }
                      piVar9 = (int *)*puVar15;
                      iVar17 = 1;
                      iVar23 = piVar9[1];
                      if (*(int *)(iVar23 + 0x2c) < 0) {
                        for (; iVar13 = (**(code **)(**(int **)(iVar23 + 0x38) + 0x14))
                                                  (*(int **)(iVar23 + 0x38)), iVar17 <= iVar13;
                            iVar17 = iVar17 + 1) {
                          iVar13 = FUN_00105594(*(undefined4 *)(iVar23 + 0x38),iVar17);
                          if (iVar13 == *(int *)(iVar30 + 0x38)) {
                            FUN_00106004(*(undefined4 *)(iVar23 + 0x38),iVar17,
                                         *(undefined4 *)(iVar22 + 0x38),0,*piStack00000018);
                          }
                        }
                        *piVar9 = iVar22;
                        FUN_00194208(*(undefined4 *)(iVar30 + 0x40),uVar10);
                        puVar20 = *(uint **)(iVar22 + 0x40);
                        uVar11 = puVar20[1];
                        if (uVar11 < *puVar20) {
                          _memset(uVar11 * 4 + puVar20[2],0,4);
                          puVar15 = (undefined4 *)(uVar11 * 4 + puVar20[2]);
                          puVar20[1] = uVar11 + 1;
                        }
                        else {
                          puVar15 = (undefined4 *)FUN_0019423c(puVar20,uVar11);
                        }
                        *puVar15 = piVar9;
                        iVar17 = *(int *)(iVar23 + 0x34);
                        if (iVar17 == 0) {
                          FUN_0019401c(iVar23);
                          iVar17 = *(int *)(iVar23 + 0x34);
                        }
                        *(int *)(iVar23 + 0x34) = iVar17 + 1;
                        iVar14 = 4;
                        iVar17 = iVar22;
                        iVar13 = iVar30;
                        do {
                          if (*(char *)(piVar9 + 6) != '\0') {
                            *(int *)(iVar17 + 0x48) = *(int *)(iVar17 + 0x48) + 1;
                            puVar19 = (undefined *)(*(int *)(iVar13 + 0x48) + -1);
                            *(undefined **)(iVar13 + 0x48) = puVar19;
                          }
                          piVar9 = (int *)((int)piVar9 + 1);
                          iVar17 = iVar17 + 4;
                          iVar13 = iVar13 + 4;
                          iVar14 = iVar14 + -1;
                        } while (iVar14 != 0);
                        puVar20 = *(uint **)(iVar23 + 0x44);
                        uVar11 = puVar20[1];
                        uVar27 = uVar11 - 1;
                        if (-1 < (int)uVar27) {
                          iVar17 = uVar27 * 4;
                          uVar25 = 0;
                          while( true ) {
                            if (uVar27 < *puVar20) {
                              uVar6 = puVar20[1];
                              if (uVar6 <= uVar27) {
                                _memset(uVar6 * 4 + puVar20[2],0,(uVar27 - uVar6) * 4 + 4);
                                puVar20[1] = uVar27 + 1;
                              }
                              puVar15 = (undefined4 *)(iVar17 + puVar20[2]);
                            }
                            else {
                              puVar15 = (undefined4 *)FUN_0019423c(puVar20,uVar27);
                            }
                            piVar9 = (int *)*puVar15;
                            if ((local_60 == *piVar9) &&
                               (puVar19 = local_64, (local_64 + (int)piVar9)[0x18] != '\0')) {
                              FUN_00194208(*(undefined4 *)(iVar23 + 0x44),uVar27);
                              piVar9[1] = iVar22;
                              puVar20 = *(uint **)(iVar22 + 0x44);
                              uVar6 = puVar20[1];
                              if (uVar6 < *puVar20) {
                                _memset(uVar6 * 4 + puVar20[2],0,4);
                                puVar15 = (undefined4 *)(uVar6 * 4 + puVar20[2]);
                                puVar20[1] = uVar6 + 1;
                              }
                              else {
                                puVar15 = (undefined4 *)FUN_0019423c(puVar20,uVar6);
                              }
                              *puVar15 = piVar9;
                            }
                            uVar25 = uVar25 + 1;
                            uVar27 = uVar27 - 1;
                            iVar17 = iVar17 + -4;
                            if (uVar11 == uVar25) break;
                            puVar20 = *(uint **)(iVar23 + 0x44);
                          }
                        }
                      }
                      uVar28 = uVar28 + 1;
                      uVar10 = uVar10 - 1;
                      iVar24 = iVar24 + -4;
                      if (uVar3 == uVar28) break;
                      puVar20 = *(uint **)(iVar30 + 0x40);
                    }
                  }
                  FUN_00165b7c(piStack00000018,iVar30,iVar22,1,0,
                               *(undefined4 *)(*(int *)(iVar22 + 0x38) + 0xc),(uint)puVar19);
                  uVar7 = *(undefined4 *)(iVar30 + 0x38);
                  *(int *)(iVar22 + 0x34) = *(int *)(iVar22 + 0x34) + -1;
                  iVar23 = *(int *)(iVar30 + 0x2c);
                  iVar24 = FUN_00164e7c(piStack00000018,uVar7,*(undefined4 *)(iVar22 + 0x38),0,1,0);
                  iVar23 = iVar23 + iVar24;
                  if (*(int *)(iVar22 + 0x30) < iVar23) {
                    *(int *)(iVar22 + 0x30) = iVar23;
                  }
                  ((int (*)())FUN_0016ee90)(piStack00000018,iVar22);
                }
LAB_0016f3cc:
                iVar30 = *(int *)(iVar30 + 0x6c);
              } while (iVar30 != 0);
              iVar4 = piStack00000018[0x61];
            }
            uVar16 = uVar16 + 1;
            param_1 = param_1 + 1;
          } while ((int)uVar16 < iVar4);
        }
        piVar9 = piStack00000018;
        iVar4 = FUN_00193f08(piStack00000018 + 0x13);
        if (iVar4 == 0) {
          iVar30 = piVar9[0x15];
          iVar4 = (**(code **)(*(int *)piStack00000018[2] + 0xc))
                            ((int *)piStack00000018[2],*(undefined4 *)(iVar30 + 0x38));
          if ((iVar4 != 0) &&
             (iVar4 = (**(code **)(*(int *)piStack00000018[3] + 0xc))
                                ((int *)piStack00000018[3],*(undefined4 *)(iVar30 + 0x38)),
             iVar4 != 0)) {
            FUN_0019401c(iVar30);
            return iVar30;
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
      iVar4 = (**(code **)(*(int *)param_1[2] + 0x24))((int *)param_1[2]);
      if (iVar4 != 0) {
        (**(code **)(*(int *)param_1[2] + 0x7c))((int *)param_1[2]);
      }
      return 0;
    }
    if ((param_1[0x46] == 0) && (param_2 < *(int *)(iVar4 + 0x10))) {
      return 0;
    }
    iVar30 = (**(code **)(*(int *)param_1[2] + 0xc))
                       ((int *)param_1[2],*(undefined4 *)(iVar4 + 0x38));
    if (iVar30 == 0) {
      iVar30 = (**(code **)(*(int *)param_1[2] + 0x24))((int *)param_1[2]);
      if (iVar30 != 0) {
        iVar30 = FUN_00167ef4(param_1,iVar4);
        if (iVar30 != 0) {
          return iVar30;
        }
        goto LAB_0016f530;
      }
    }
    else {
LAB_0016f530:
      iVar30 = (**(code **)(*(int *)param_1[3] + 0xc))
                         ((int *)param_1[3],*(undefined4 *)(iVar4 + 0x38));
      if (iVar30 != 0) {
        if (*(int *)(iVar4 + 8) != 0) {
          local_6c = *(undefined4 *)(*param_1 + 0x378);
          local_74 = (undefined *)0x0;
          local_78 = (undefined *)0x2;
          local_70 = FUN_00193e18(local_6c,8);
          local_5c = *(undefined4 *)(*param_1 + 0x378);
          local_64 = (undefined *)0x0;
          local_68 = (undefined *)0x2;
          local_60 = FUN_00193e18(local_5c,8);
          uVar7 = *(undefined4 *)(*param_1 + 0x378);
          local_58 = 2;
          local_54 = 0;
          local_50 = FUN_00193e18(uVar7,8);
          uVar32 = *(undefined4 *)(*param_1 + 0x378);
          iVar30 = *(int *)(iVar4 + 0x60);
          puVar8 = (undefined4 *)FUN_00193e18(uVar32,0x2c);
          uVar16 = local_54;
          *puVar8 = uVar32;
          puVar8[4] = 0x1010101;
          puVar8[1] = 0;
          puVar8[2] = 0xffffffff;
          puVar8[5] = 0;
          puVar8[6] = 0x7fffffff;
          iVar22 = 4;
          puVar8[3] = 0;
          puVar15 = puVar8 + 1;
          do {
            puVar15[6] = 0;
            puVar15 = puVar15 + 1;
            iVar22 = iVar22 + -1;
          } while (iVar22 != 0);
          *(undefined4 **)(iVar4 + 0x60) = puVar8 + 1;
          puVar8[5] = 1;
          puVar20 = *(uint **)(iVar4 + 0x38);
          uVar3 = puVar20[3];
          puVar21 = *(uint **)(iVar4 + 0x60);
          *(int *)(iVar30 + 0x10) = *(int *)(iVar30 + 0x10) + -1;
          *puVar21 = uVar3;
          if (local_54 < local_58) {
            iVar22 = local_54 * 4;
            _memset(iVar22 + local_50,0,4);
            local_54 = uVar16 + 1;
            piVar9 = (int *)(iVar22 + local_50);
          }
          else {
            piVar9 = (int *)FUN_0019423c(&local_58,local_54);
          }
          *piVar9 = iVar4;
LAB_0016fcc0:
          do {
            puVar19 = local_74;
            if (local_54 == 0) {
              if (0 < (int)local_74) {
                puVar29 = (undefined *)0x0;
                puVar26 = (undefined *)0x1;
                iVar30 = 0;
                do {
                  if (puVar29 < local_78) {
                    if (local_74 <= puVar29) {
                      _memset((int)local_74 * 4 + local_70,0,((int)puVar29 - (int)local_74) * 4 + 4)
                      ;
                      local_74 = puVar26;
                    }
                    piVar9 = (int *)(iVar30 + local_70);
                  }
                  else {
                    piVar9 = (int *)FUN_0019423c(&local_78,puVar29);
                  }
                  iVar24 = *piVar9;
                  ((int (*)())FUN_0017212c)(param_1[2],iVar24);
                  iVar22 = *(int *)(iVar24 + 0x38);
                  FUN_000f31f8(&STACKARG(0xffffffb8),0,*(undefined4 *)(iVar22 + 0xc));
                  *(undefined4 *)(iVar22 + 0x9c) = in_stack_ffffffb8;
                  iVar22 = *(int *)(iVar24 + 0x38);
                  FUN_000f3340(&STACKARG(0xffffffbc),0x10203,*(undefined4 *)(iVar22 + 0xc));
                  iVar22 = FUN_001054ec(iVar22,1);
                  *(undefined4 *)(iVar22 + 0x10) = in_stack_ffffffbc;
                  uVar32 = (**(code **)(*(int *)param_1[2] + 0x4c))
                                     ((int *)param_1[2],*(undefined4 *)(iVar24 + 0x38));
                  *(undefined4 *)(iVar24 + 0x58) = uVar32;
                  if (puVar29 < local_68) {
                    if (local_64 <= puVar29) {
                      _memset((int)local_64 * 4 + local_60,0,((int)puVar29 - (int)local_64) * 4 + 4)
                      ;
                      local_64 = puVar26;
                    }
                    puVar15 = (undefined4 *)(iVar30 + local_60);
                  }
                  else {
                    puVar15 = (undefined4 *)FUN_0019423c(&local_68,puVar29);
                  }
                  FUN_00165b7c(param_1,*puVar15,iVar24,1,0,
                               *(undefined4 *)(*(int *)(iVar24 + 0x38) + 0xc),(uint)puVar20);
                  ((int (*)())FUN_00172078)(param_1[2],iVar24);
                  if (puVar29 < local_68) {
                    if (local_64 <= puVar29) {
                      _memset((int)local_64 * 4 + local_60,0,((int)puVar29 - (int)local_64) * 4 + 4)
                      ;
                      local_64 = puVar26;
                    }
                    piVar9 = (int *)(iVar30 + local_60);
                  }
                  else {
                    piVar9 = (int *)FUN_0019423c(&local_68,puVar29);
                  }
                  if (-1 < *(int *)(*piVar9 + 0x2c)) {
                    *(int *)(iVar24 + 0x34) = *(int *)(iVar24 + 0x34) + -1;
                    ((int (*)())FUN_0016ee90)(param_1,iVar24);
                  }
                  puVar29 = puVar29 + 1;
                  puVar26 = puVar26 + 1;
                  iVar30 = iVar30 + 4;
                } while (puVar19 != puVar29);
              }
              FUN_0019401c(iVar4);
              FUN_00193cc0(uVar7,local_50);
              FUN_00193cc0(local_5c,local_60);
              FUN_00193cc0(local_6c,local_70);
              return iVar4;
            }
            uVar16 = local_54 - 1;
            piVar9 = (int *)0x0;
            if (uVar16 < local_54) {
              piVar9 = (int *)(uVar16 * 4 + local_50);
            }
            iVar22 = *piVar9;
            FUN_00194208(&local_58,uVar16);
            puVar21 = *(uint **)(iVar22 + 0x40);
            uVar3 = 0;
            uVar16 = puVar21[1];
          } while ((int)uVar16 < 1);
          do {
            if (uVar3 < *puVar21) {
              uVar10 = puVar21[1];
              if (uVar10 <= uVar3) {
                _memset(uVar10 * 4 + puVar21[2],0,(uVar3 - uVar10) * 4 + 4);
                puVar21[1] = uVar3 + 1;
              }
              piVar9 = (int *)(uVar3 * 4 + puVar21[2]);
            }
            else {
              piVar9 = (int *)FUN_0019423c(puVar21,uVar3);
            }
            iVar24 = *piVar9;
            if (*(int *)(iVar24 + 8) == 0) {
              iVar23 = *(int *)(iVar24 + 4);
              uVar28 = 0;
              puVar21 = *(uint **)(iVar23 + 0x44);
              uVar10 = puVar21[1];
              if (0 < (int)uVar10) {
                do {
                  if (uVar28 < *puVar21) {
                    uVar11 = puVar21[1];
                    if (uVar11 <= uVar28) {
                      _memset(uVar11 * 4 + puVar21[2],0,(uVar28 - uVar11) * 4 + 4);
                      puVar21[1] = uVar28 + 1;
                    }
                    puVar15 = (undefined4 *)(uVar28 * 4 + puVar21[2]);
                  }
                  else {
                    puVar15 = (undefined4 *)FUN_0019423c(puVar21,uVar28);
                  }
                  piVar9 = (int *)*puVar15;
                  if ((((piVar9[2] == 0) && (iVar17 = *piVar9, iVar22 != iVar17)) &&
                      (piVar9[4] == *(int *)(iVar24 + 0x10))) &&
                     (piVar9[5] == *(int *)(iVar24 + 0x14))) {
                    if (((*(int *)(iVar17 + 0x2c) < 0) ||
                        ((*(uint *)(*(int *)(iVar17 + 0x38) + 0x14) & 0x40) == 0)) &&
                       (iVar17 = FUN_00166a0c(param_1,iVar17), uVar11 = local_54, iVar17 == 0)) {
                      puVar20 = (uint *)*piVar9;
                      if (puVar20[0x18] != *(uint *)(iVar4 + 0x60)) {
                        puVar20[0x18] = *(uint *)(iVar4 + 0x60);
                        *(int *)(*(int *)(iVar4 + 0x60) + 0x10) =
                             *(int *)(*(int *)(iVar4 + 0x60) + 0x10) + 1;
                        puVar20 = *(uint **)(*piVar9 + 0x38);
                        **(uint **)(iVar4 + 0x60) = **(uint **)(iVar4 + 0x60) | puVar20[3];
                        *(int *)(iVar30 + 0x10) = *(int *)(iVar30 + 0x10) + -1;
                        iVar17 = *piVar9;
                        if (local_54 < local_58) {
                          iVar13 = local_54 * 4;
                          _memset(iVar13 + local_50,0,4);
                          local_54 = uVar11 + 1;
                          piVar9 = (int *)(iVar13 + local_50);
                        }
                        else {
                          piVar9 = (int *)FUN_0019423c(&local_58,local_54);
                        }
                        *piVar9 = iVar17;
                      }
                    }
                    else {
                      puVar19 = local_74;
                      if ((int)local_74 < 1) {
                        iVar17 = *piVar9;
                      }
                      else {
                        puVar26 = (undefined *)0x0;
                        do {
                          if (puVar26 < local_78) {
                            if (local_74 <= puVar26) {
                              _memset((int)local_74 * 4 + local_70,0,
                                      ((int)puVar26 - (int)local_74) * 4 + 4);
                              local_74 = puVar26 + 1;
                            }
                            piVar12 = (int *)((int)puVar26 * 4 + local_70);
                          }
                          else {
                            piVar12 = (int *)FUN_0019423c(&local_78,puVar26);
                          }
                          iVar13 = FUN_00105594(*(undefined4 *)(*piVar12 + 0x38),1);
                          iVar17 = *piVar9;
                          if (iVar13 == *(int *)(iVar17 + 0x38)) {
                            if (puVar26 < local_78) {
                              if (local_74 <= puVar26) {
                                _memset((int)local_74 * 4 + local_70,0,
                                        ((int)puVar26 - (int)local_74) * 4 + 4);
                                local_74 = puVar26 + 1;
                              }
                              piVar12 = (int *)((int)puVar26 * 4 + local_70);
                            }
                            else {
                              piVar12 = (int *)FUN_0019423c(&local_78,puVar26);
                            }
                            iVar17 = *piVar12;
                            *(uint *)(*(int *)(iVar17 + 0x38) + 0xc) =
                                 *(uint *)(*(int *)(iVar17 + 0x38) + 0xc) | piVar9[6];
                            puVar20 = *(uint **)(iVar17 + 0x60);
                            *puVar20 = *puVar20 | piVar9[6];
                            goto LAB_0016fafc;
                          }
                          puVar26 = puVar26 + 1;
                        } while (puVar19 != puVar26);
                      }
                      iVar13 = *(int *)(iVar17 + 0x2c);
                      uVar32 = *(undefined4 *)(iVar17 + 0x38);
                      iVar17 = (**(code **)(*(int *)param_1[2] + 0x78))((int *)param_1[2]);
                      iVar17 = FUN_00167e1c(param_1,uVar32,0,iVar13 + iVar17,*piVar9 + 0xc);
                      if (local_74 < local_78) {
                        iVar13 = (int)local_74 * 4;
                        local_74 = local_74 + 1;
                        *(undefined4 *)(iVar13 + local_70) = 0;
                        piVar12 = (int *)(iVar13 + local_70);
                      }
                      else {
                        piVar12 = (int *)FUN_0019423c(&local_78,local_74);
                      }
                      *piVar12 = iVar17;
                      if (local_64 < local_68) {
                        iVar13 = (int)local_64 * 4;
                        local_64 = local_64 + 1;
                        *(undefined4 *)(iVar13 + local_60) = 0;
                        piVar12 = (int *)(iVar13 + local_60);
                      }
                      else {
                        piVar12 = (int *)FUN_0019423c(&local_68,local_64);
                      }
                      *piVar12 = *piVar9;
                      *(int *)(*(int *)(iVar17 + 0x38) + 0xc) = piVar9[6];
                      FUN_00106804(*(undefined4 *)(iVar17 + 0x38),*(undefined4 *)(iVar22 + 0x38),0,
                                   *param_1);
                      *(undefined4 *)(iVar17 + 0x60) = *(undefined4 *)(iVar4 + 0x60);
                      puVar20 = *(uint **)(iVar4 + 0x60);
                      puVar20[4] = puVar20[4] + 1;
                      **(uint **)(iVar4 + 0x60) = **(uint **)(iVar4 + 0x60) | piVar9[6];
LAB_0016fafc:
                      if ((piVar9[4] < 1) || (piVar9[5] != 0)) {
LAB_0016fb44:
                        iVar13 = *piVar9;
                      }
                      else {
                        iVar14 = FUN_00105594(*(undefined4 *)(iVar23 + 0x38),piVar9[4]);
                        iVar13 = *piVar9;
                        if (iVar14 == *(int *)(iVar13 + 0x38)) {
                          FUN_00106004(*(undefined4 *)(iVar23 + 0x38),piVar9[4],
                                       *(undefined4 *)(iVar17 + 0x38),0,*param_1);
                          goto LAB_0016fb44;
                        }
                      }
                      iVar33 = 4;
                      iVar18 = 0;
                      piVar12 = piVar9;
                      iVar14 = iVar17;
                      do {
                        if (*(char *)(piVar12 + 6) != '\0') {
                          iVar13 = iVar18 * 4 + iVar13;
                          puVar20 = (uint *)(*(int *)(iVar13 + 0x48) + -1);
                          *(uint **)(iVar13 + 0x48) = puVar20;
                          *(int *)(iVar14 + 0x48) = *(int *)(iVar14 + 0x48) + 1;
                          iVar13 = *piVar9;
                        }
                        iVar18 = iVar18 + 1;
                        piVar12 = (int *)((int)piVar12 + 1);
                        iVar14 = iVar14 + 4;
                        iVar33 = iVar33 + -1;
                      } while (iVar33 != 0);
                      FUN_00194374(*(undefined4 *)(iVar13 + 0x40),piVar9);
                      if (-1 < *(int *)(*piVar9 + 0x2c)) {
                        *(int *)(iVar23 + 0x34) = *(int *)(iVar23 + 0x34) + 1;
                      }
                      *piVar9 = iVar17;
                      puVar21 = *(uint **)(iVar17 + 0x40);
                      uVar11 = puVar21[1];
                      if (uVar11 < *puVar21) {
                        _memset(uVar11 * 4 + puVar21[2],0,4);
                        puVar15 = (undefined4 *)(uVar11 * 4 + puVar21[2]);
                        puVar21[1] = uVar11 + 1;
                      }
                      else {
                        puVar15 = (undefined4 *)FUN_0019423c(puVar21,uVar11);
                      }
                      *puVar15 = piVar9;
                    }
                  }
                  uVar28 = uVar28 + 1;
                  if (uVar10 == uVar28) break;
                  puVar21 = *(uint **)(iVar23 + 0x44);
                } while( true );
              }
            }
            uVar3 = uVar3 + 1;
            if (uVar16 == uVar3) goto LAB_0016fcc0;
            puVar21 = *(uint **)(iVar22 + 0x40);
          } while( true );
        }
        goto LAB_0016f574;
      }
    }
    iVar4 = *(int *)(iVar4 + 8);
  } while( true );
code_r0x0016f044:
  iVar22 = iVar22 + 4;
  iVar24 = iVar24 + -1;
  if (iVar24 == 0) goto LAB_0016f3cc;
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
    iVar3 = (**(code **)(**(int **)(param_1 + 8) + 0x84))(*(int **)(param_1 + 8));
    iVar2 = iVar2 + iVar3;
  }
  else {
    iVar2 = 0x7fffffff;
  }
  while ((iVar3 = (**(code **)(**(int **)(param_1 + 8) + 0x20))(*(int **)(param_1 + 8)), iVar3 == 0
         && (iVar3 = ((int (*)())FUN_0016ff54)(param_1,iVar2), iVar3 != 0))) {
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
      iVar4 = (**(code **)(**(int **)(param_1 + 8) + 0x20))(*(int **)(param_1 + 8));
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
  while (((iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x20))(*(int **)(param_1 + 8)), iVar2 == 0
          && (*(int *)(param_1 + 0x118) == 0)) && (iVar2 = FUN_0016629c(param_1), iVar2 != 0))) {
    ((int (*)())FUN_0016d3b0)(param_1,iVar2);
  }
  iVar2 = FUN_0016c640(param_1);
  if (iVar2 == 0) {
    (**(code **)(**(int **)(param_1 + 8) + 0x7c))(*(int **)(param_1 + 8));
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
          _memset(uVar1 * 4 + puVar10[2],0,(uVar8 - uVar1) * 4 + 4);
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
          _memset(uVar1 * 4 + puVar11[2],0,(uVar8 - uVar1) * 4 + 4);
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
            _memset(uVar1 * 4 + puVar10[2],0,(uVar8 - uVar1) * 4 + 4);
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
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
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
    uVar8 = 0;
    do {
      uVar9 = uVar8 >> 3 & 0x1ffffffc;
      uVar12 = uVar8 & 0x1f;
      if (((*(uint *)(uVar9 + *(int *)(param_1[1] + 0x430) + 8) >> uVar12 & 1) != 0) &&
         ((*(uint *)(uVar9 + *(int *)(param_2 + 0x104) + 8) >> uVar12 & 1) == 0)) {
        *(uint *)(uVar9 + param_1[0x4c] + 8) = 1 << uVar12 | *(uint *)(uVar9 + param_1[0x4c] + 8);
      }
      iVar2 = 4;
      piVar3 = param_1;
      do {
        piVar5 = piVar3 + 0x4d;
        piVar3 = piVar3 + 1;
        *(undefined4 *)(uVar8 * 4 + *piVar5) = 0;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      iVar2 = param_1[0x51];
      uVar8 = uVar8 + 1;
    } while ((int)uVar8 < iVar2);
  }
  if (param_1[0x58] != 0) {
    piVar3 = param_1;
    while( true ) {
      if (0 < iVar2) {
        iVar2 = 0;
        do {
          iVar10 = iVar2 * 4;
          iVar2 = iVar2 + 1;
          *(undefined4 *)(iVar10 + piVar3[0x54]) = 0;
        } while (iVar2 < param_1[0x51]);
      }
      piVar5 = *(int **)(*param_1 + 0x30c);
      iVar2 = (**(code **)(*piVar5 + 0x13c))(piVar5,*param_1);
      if (0 < iVar2) {
        iVar10 = 0;
        do {
          iVar6 = iVar10 * 4;
          iVar10 = iVar10 + 1;
          *(undefined4 *)(iVar6 + piVar3[0x58]) = 0;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      piVar3 = piVar3 + 1;
      if (param_1 + 4 == piVar3) break;
      iVar2 = param_1[0x51];
    }
  }
  puVar14 = (uint *)param_1[5];
  uVar8 = puVar14[1];
  if (uVar8 != 0) {
    uVar12 = 0;
    do {
      if (uVar12 < *puVar14) {
        if (uVar8 <= uVar12) {
          _memset(uVar8 * 4 + puVar14[2],0,(uVar12 - uVar8) * 4 + 4);
          puVar14[1] = uVar12 + 1;
        }
        piVar3 = (int *)(uVar12 * 4 + puVar14[2]);
      }
      else {
        piVar3 = (int *)FUN_0019423c(puVar14,uVar12);
      }
      uVar12 = uVar12 + 1;
      iVar10 = *piVar3;
      piVar3 = *(int **)(iVar10 + 0x38);
      iVar2 = piVar3[0x25];
      if ((((piVar3[0x20] != 0) && (iVar6 = FUN_00126760(piVar3[0x26]), iVar6 != 0)) &&
          ((piVar3[5] & 2U) == 0)) &&
         ((iVar6 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar6 == 0 && ((piVar3[5] & 0x40U) != 0)))
         ) {
        local_48 = piVar3[3];
        if (*(int *)(iVar10 + 0x60) != 0) {
          *(int *)(*(int *)(iVar10 + 0x60) + 8) = iVar10;
          *(int *)(*(int *)(iVar10 + 0x60) + 4) = iVar2;
          local_48 = **(int **)(iVar10 + 0x60);
        }
        iVar16 = 4;
        iVar6 = 0;
        piVar5 = param_1;
        do {
          if (*(char *)((int)&local_48 + iVar6) != '\0') {
            *(int *)(piVar5[0x4d] + iVar2 * 4) = iVar10;
            if (piVar5[0x54] != 0) {
              *(undefined4 *)(piVar5[0x54] + iVar2 * 4) = 0x7fffffff;
            }
            if (*(int *)(iVar10 + 0x60) != 0) {
              *(int *)(iVar6 * 4 + *(int *)(iVar10 + 0x60) + 0x18) = iVar10;
              *(undefined4 *)(*(int *)(iVar10 + 0x60) + 0x14) = 0;
            }
          }
          iVar6 = iVar6 + 1;
          piVar5 = piVar5 + 1;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
        if (piVar3[0x26] == 1) {
          piVar3 = *(int **)(*param_1 + 0x30c);
          iVar6 = (**(code **)(*piVar3 + 0x138))(piVar3,*param_1);
          iVar10 = param_1[0x67];
          if (param_1[0x67] < iVar2 - iVar6) {
            iVar10 = iVar2 - iVar6;
          }
          param_1[0x67] = iVar10;
        }
        else {
          iVar10 = param_1[0x66];
          if (param_1[0x66] < iVar2) {
            iVar10 = iVar2;
          }
          param_1[0x66] = iVar10;
          if (iVar2 <= param_1[0x68]) {
            iVar2 = param_1[0x68];
          }
          param_1[0x68] = iVar2;
        }
      }
      puVar14 = (uint *)param_1[5];
      uVar8 = puVar14[1];
    } while (uVar12 < uVar8);
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
  uVar12 = 0;
  (**(code **)(*(int *)param_1[2] + 8))((int *)param_1[2]);
  (**(code **)(*(int *)param_1[3] + 8))((int *)param_1[3]);
  param_1[0x46] = 1;
  param_1[0x4a] = -1;
  param_1[0x4b] = 0;
  param_1[0xb] = 1;
  param_1[0x47] = -1;
  param_1[0x48] = -1;
  param_1[0x49] = 0;
  FUN_001940a8(auStack_40);
  puVar14 = (uint *)param_1[6];
  uVar8 = puVar14[1];
  if (0 < (int)uVar8) {
    while( true ) {
      if (uVar12 < *puVar14) {
        uVar9 = puVar14[1];
        if (uVar9 <= uVar12) {
          _memset(uVar9 * 4 + puVar14[2],0,(uVar12 - uVar9) * 4 + 4);
          puVar14[1] = uVar12 + 1;
        }
        piVar3 = (int *)(uVar12 * 4 + puVar14[2]);
      }
      else {
        piVar3 = (int *)FUN_0019423c(puVar14,uVar12);
      }
      if (*(int *)(*piVar3 + 0x34) == 0) {
        FUN_00193f64(auStack_40,*piVar3);
      }
      uVar12 = uVar12 + 1;
      if (uVar8 == uVar12) break;
      puVar14 = (uint *)param_1[6];
    }
  }
  iVar10 = *(int *)(local_38 + 8);
  iVar2 = local_38;
  while (iVar6 = iVar10, iVar6 != 0) {
    FUN_0019401c(iVar2);
    ((int (*)())FUN_0016ee90)(param_1,iVar2);
    iVar10 = (**(code **)(*(int *)param_1[3] + 0x20))
                       ((int *)param_1[3],*(undefined4 *)(iVar2 + 0x38));
    if ((iVar10 == 0) &&
       (iVar10 = (**(code **)(*(int *)param_1[3] + 0x24))
                           ((int *)param_1[3],*(undefined4 *)(iVar2 + 0x38)), iVar10 == 0)) {
      iVar10 = *(int *)(iVar2 + 0xc);
      if (*(int *)(iVar2 + 0xc) < param_1[0x47]) {
        iVar10 = param_1[0x47];
      }
      param_1[0x47] = iVar10;
    }
    else {
      iVar10 = *(int *)(iVar2 + 0xc);
      if (*(int *)(iVar2 + 0xc) < param_1[0x48]) {
        iVar10 = param_1[0x48];
      }
      param_1[0x48] = iVar10;
    }
    iVar2 = iVar6;
    iVar10 = *(int *)(iVar6 + 8);
  }
  piVar3 = param_1 + 0xd;
  param_1[0x46] = 0;
  iVar2 = FUN_00193f08(piVar3);
  if ((iVar2 == 0) && (param_1[0x47] + -1 <= param_1[0x48])) {
    param_1[0x4a] = param_1[0x48];
    param_1[0x46] = 1;
  }
  piVar5 = (int *)(*(int **)(param_1[4] + 0x98))[2];
  if (piVar5 != (int *)0x0) {
    piVar11 = (int *)0x0;
    piVar15 = *(int **)(param_1[4] + 0x98);
    do {
      piVar13 = piVar5;
      iVar2 = (**(code **)(*piVar15 + 0x34))(piVar15);
      if ((iVar2 == 0) && (iVar2 = (**(code **)(*piVar15 + 0x38))(piVar15), iVar2 == 0)) {
        iVar2 = FUN_00164df4(piVar15);
        if (iVar2 == 0) {
          FUN_0019401c(piVar15);
          piVar15[0x56] = 0;
        }
        else {
          piVar15[5] = piVar15[5] | 4;
          piVar11 = piVar15;
        }
      }
      else {
        piVar15[5] = piVar15[5] & 0xfffffffb;
      }
      piVar5 = (int *)piVar13[2];
      piVar15 = piVar13;
    } while (piVar5 != (int *)0x0);
    if (piVar11 != (int *)0x0) {
      piVar11[5] = piVar11[5] & 0xfffffffb;
    }
  }
  piVar5 = param_1 + 0x13;
  iVar2 = FUN_00193f08(piVar5);
  if ((((iVar2 == 0) || (iVar2 = FUN_00193f08(piVar3), iVar2 == 0)) ||
      (iVar2 = FUN_00193f08(param_1 + 0x19), iVar2 == 0)) ||
     (iVar2 = FUN_00193f08(param_1 + 0x3e), iVar2 == 0)) {
    iVar2 = FUN_0016c640(param_1);
    if ((iVar2 == 0) && (iVar2 = FUN_00193f08(param_1 + 0x25), iVar2 != 0)) {
      iVar2 = FUN_00193f08(param_1 + 0x3e);
      if (((iVar2 == 0) && (iVar2 = FUN_00193f08(piVar5), iVar2 != 0)) &&
         ((iVar2 = FUN_00193f08(piVar3), iVar2 != 0 &&
          (iVar2 = FUN_00194034(param_1 + 0x3e), iVar2 == param_1[0x3d])))) {
        iVar2 = param_1[0x40];
        for (iVar10 = *(int *)(param_1[0x40] + 8); iVar10 != 0; iVar10 = *(int *)(iVar10 + 8)) {
          FUN_0019401c(iVar2);
          *(undefined4 *)(iVar2 + 0x68) = 0;
          FUN_00193f64(piVar5,iVar2);
          iVar2 = iVar10;
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
    puVar7 = (undefined4 *)param_1[0xc];
    iVar2 = 5;
    puVar4 = puVar7;
    do {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  else {
    FUN_0016c640(param_1);
    puVar7 = (undefined4 *)param_1[0xc];
    iVar2 = 5;
    puVar4 = puVar7;
    do {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_00193fa4(puVar7 + 5);
  iVar2 = (**(code **)(*(int *)param_1[3] + 0x1c))((int *)param_1[3]);
  if (iVar2 != 0) {
    iVar2 = *(int *)(param_2 + 0xd0);
    iVar10 = 0;
    local_44 = 0;
    for (uVar8 = 1; uVar8 <= *(uint *)(iVar2 + 4); uVar8 = uVar8 + 1) {
      local_44 = *(int *)(*(int *)(iVar2 + 8) + iVar10);
      if (local_44 != 0) {
        *(undefined4 *)(local_44 + 0xdc) = 1;
      }
      iVar10 = iVar10 + 4;
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
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r10;
  undefined4 uVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  
  param_1[1] = param_2;
  iVar4 = *(int *)(param_2 + 8);
  *param_1 = iVar4;
  iVar4 = FUN_0010ddcc(iVar4);
  param_1[2] = iVar4;
  iVar4 = FUN_0010ddd8(*param_1);
  param_1[3] = iVar4;
  uVar12 = *(undefined4 *)(*param_1 + 0x378);
  puVar5 = (undefined4 *)FUN_00193e18(uVar12,0x14);
  *puVar5 = uVar12;
  puVar5[1] = 2;
  puVar5[4] = uVar12;
  puVar5[2] = 0;
  uVar12 = FUN_00193e18(uVar12,8);
  puVar5[3] = uVar12;
  param_1[5] = (int)(puVar5 + 1);
  uVar12 = *(undefined4 *)(*param_1 + 0x378);
  puVar5 = (undefined4 *)FUN_00193e18(uVar12,0x14);
  *puVar5 = uVar12;
  puVar5[1] = 2;
  puVar5[2] = 0;
  puVar5[4] = uVar12;
  uVar12 = FUN_00193e18(uVar12,8);
  puVar5[3] = uVar12;
  param_1[6] = (int)(puVar5 + 1);
  uVar12 = *(undefined4 *)(*param_1 + 0x378);
  puVar6 = (undefined4 *)FUN_00193e18(uVar12,0x30);
  *puVar6 = uVar12;
  FUN_001940a8(puVar6 + 6);
  iVar4 = 5;
  puVar5 = puVar6 + 1;
  do {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  param_1[0xc] = (int)(puVar6 + 1);
  piVar7 = *(int **)(*param_1 + 0x30c);
  iVar4 = (**(code **)(*piVar7 + 0x138))(piVar7,*param_1);
  piVar7 = *(int **)(*param_1 + 0x30c);
  iVar8 = (**(code **)(*piVar7 + 0x140))(piVar7,*param_1);
  iVar4 = iVar4 + iVar8;
  param_1[0x51] = iVar4;
  uVar2 = iVar4 + 0x1fU >> 5;
  uVar12 = *(undefined4 *)(*param_1 + 0x378);
  puVar5 = (undefined4 *)FUN_00193e18(uVar12,uVar2 * 4 + 0xc);
  piVar7 = puVar5 + 1;
  *puVar5 = uVar12;
  puVar5[1] = uVar2;
  puVar5[2] = iVar4;
  if (uVar2 != 0) {
    iVar4 = *piVar7;
    piVar13 = piVar7;
    if (iVar4 == 0) {
      iVar4 = 1;
    }
    do {
      piVar13[2] = 0;
      piVar13 = piVar13 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  param_1[0x4c] = (int)piVar7;
  iVar4 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x13c))();
  bVar1 = iVar4 < 1;
  piVar7 = param_1;
  do {
    iVar8 = FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),param_1[0x51] << 2);
    piVar7[0x4d] = iVar8;
    if (bVar1) {
      piVar7[0x54] = 0;
      piVar7[0x58] = 0;
    }
    else {
      iVar9 = FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),param_1[0x51] << 2);
      iVar8 = *param_1;
      piVar7[0x54] = iVar9;
      iVar8 = FUN_00193e18(*(undefined4 *)(iVar8 + 0x378),iVar4 << 2);
      piVar7[0x58] = iVar8;
    }
    piVar7 = piVar7 + 1;
  } while (piVar7 != param_1 + 4);
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
  iVar8 = FUN_000e79d0(*(undefined4 *)(param_1[1] + 0x3a0));
  if (iVar8 == 1) {
    iVar8 = param_1[1];
    puVar5 = (undefined4 *)0x0;
    iVar4 = *(int *)(*(int *)(iVar8 + 0x3a0) + 0xd0);
    if (*(int *)(iVar4 + 4) != 0) {
      puVar5 = *(undefined4 **)(iVar4 + 8);
    }
    piVar15 = *(int **)(*(int *)(iVar8 + 0x3a0) + 0xa0);
    uVar12 = *puVar5;
    piVar13 = (int *)piVar15[1];
    if (piVar13 != (int *)0x0) {
      do {
        piVar14 = piVar13;
        iVar8 = (**(code **)(*piVar15 + 0x34))(piVar15);
        if ((iVar8 == 0) && (iVar8 = (**(code **)(*piVar15 + 0x38))(piVar15), iVar8 == 0)) {
          FUN_0019401c(piVar15);
          FUN_000e76c4(uVar12,piVar15);
        }
        piVar13 = (int *)piVar14[1];
        piVar15 = piVar14;
      } while (piVar13 != (int *)0x0);
      iVar8 = param_1[1];
    }
    *(undefined4 *)(iVar8 + 0x3a4) = uVar12;
  }
  iVar8 = FUN_000e79dc(*(undefined4 *)(param_1[1] + 0x3a8));
  if (iVar8 == 1) {
    iVar8 = param_1[1];
    puVar5 = (undefined4 *)0x0;
    iVar4 = *(int *)(*(int *)(iVar8 + 0x3a8) + 0xd4);
    if (*(int *)(iVar4 + 4) != 0) {
      puVar5 = *(undefined4 **)(iVar4 + 8);
    }
    piVar15 = *(int **)(*(int *)(iVar8 + 0x3a8) + 0x98);
    uVar12 = *puVar5;
    piVar13 = (int *)piVar15[2];
    if (piVar13 == (int *)0x0) goto code_r0x00171ba0;
    do {
      piVar14 = piVar13;
      iVar8 = (**(code **)(*piVar15 + 0x34))(piVar15);
      if ((iVar8 == 0) && (iVar8 = (**(code **)(*piVar15 + 0x38))(piVar15), iVar8 == 0)) {
        iVar8 = (**(code **)(*piVar15 + 0x68))(piVar15);
        if (iVar8 != 0) {
          piVar13 = (int *)FUN_00105594(piVar15,1);
          iVar8 = (**(code **)(*piVar13 + 0x50))();
          if (iVar8 != 0) goto code_r0x00171b84;
        }
        FUN_0019401c(piVar15);
        FUN_000e7688(uVar12,piVar15);
      }
code_r0x00171b84:
      piVar13 = (int *)piVar14[2];
      piVar15 = piVar14;
    } while (piVar13 != (int *)0x0);
  }
  iVar8 = param_1[1];
code_r0x00171ba0:
  (**(code **)(*(int *)param_1[2] + 0x70))((int *)param_1[2],iVar8);
  FUN_000ed7e4(param_1[1],0x1a9f20);
  iVar8 = FUN_000e07dc(*param_1,0x43);
  if (iVar8 != 0) {
    FUN_00184ab4(param_1,param_2);
  }
  FUN_00169e30(param_1);
  FUN_00165014(param_1);
  iVar8 = *(int *)(param_1[1] + 900);
  iVar9 = *(int *)(iVar8 + 8);
  while (iVar9 != 0) {
    iVar9 = FUN_00194034(iVar8 + 0x90);
    if (2 < iVar9) {
      ((int (*)())FUN_00170e6c)(param_1,iVar8);
      iVar4 = param_1[1];
      param_1[100] = param_1[100] + param_1[0xb];
      *(undefined4 *)(iVar8 + 0x118) = *(undefined4 *)(iVar4 + 0x474);
    }
    iVar8 = *(int *)(iVar8 + 8);
    iVar9 = *(int *)(iVar8 + 8);
  }
  if (!bVar1) {
    param_1[0x66] = param_1[0x68];
  }
  if (-1 < param_1[0x66]) {
    iVar8 = 0;
    do {
      iVar9 = iVar8 + 1;
      FUN_00130444(param_1[1],iVar8);
      iVar8 = iVar9;
    } while (iVar9 <= param_1[0x66]);
  }
  iVar8 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x138))();
  if (-1 < param_1[0x67]) {
    iVar9 = 0;
    do {
      iVar10 = iVar8 + iVar9;
      iVar9 = iVar9 + 1;
      FUN_00130444(param_1[1],iVar10);
    } while (iVar9 <= param_1[0x67]);
  }
  iVar9 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x140))();
  if (-1 < param_1[0x69]) {
    iVar10 = 0;
    do {
      iVar11 = iVar8 + iVar9 + iVar10;
      iVar10 = iVar10 + 1;
      FUN_00130444(param_1[1],iVar11);
    } while (iVar10 <= param_1[0x69]);
  }
  FUN_000e0e0c(*param_1,"Scheduler : Total cycles %d\n",param_1[100],in_r6,in_r7,in_r8,iVar4,in_r10)
  ;
  FUN_000e0e0c(*param_1,"Scheduler : Total dot-product transformed %d\n",param_1[0x6a],in_r6,in_r7,
               in_r8,iVar4,in_r10);
  FUN_000ed7e4(param_1[1],0x1a9f84);
  FUN_00138080(param_2);
  iVar4 = param_1[0x4c];
  piVar13 = param_1;
  if (iVar4 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
  }
  do {
    if (!bVar1) {
      FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),piVar13[0x54]);
      FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),piVar13[0x58]);
    }
    piVar15 = piVar13 + 1;
    FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),piVar13[0x4d]);
    piVar13 = piVar15;
  } while (piVar7 != piVar15);
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
    iVar8 = *(int *)(iVar4 + -4);
    if ((*(int *)(iVar8 + 0x28) != 0) && (iVar9 = *(int *)(iVar8 + 0x14), iVar9 == iVar4 + -4)) {
      _memset(iVar9,0,*(int *)(iVar8 + 8) - iVar9);
      *(undefined4 *)(iVar8 + 8) = *(undefined4 *)(iVar8 + 0x14);
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
  
  iVar1 = (**(code **)(*param_1 + 0x4c))(param_1,param_2);
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
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x38) + 0x28))(*(int **)(param_2 + 0x38),param_2);
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
          _memset(uVar2 * 4 + puVar8[2],0,(uVar7 - uVar2) * 4 + 4);
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
            _memset(uVar2 * 4 + puVar8[2],0,(uVar7 - uVar2) * 4 + 4);
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
  uint param_3;
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_2 + 4) = uVar1;
  FUN_0010ac38(param_1,1,2,param_3);
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
  for (iVar4 = 0;
      iVar3 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0)),
      iVar4 < iVar3; iVar4 = iVar4 + 1) {
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
  
  iVar1 = _memcmp(param_1 + 0xb4,param_2 + 0xb4,0x15c);
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
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x54))(*(int **)(param_1 + 0xb0));
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

