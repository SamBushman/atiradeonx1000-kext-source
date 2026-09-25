#include "decls.h"

/* FUN_0011e7ec @ 0x11e7ec (168 bytes) */
int FUN_0011e7ec(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((*(int *)(param_1 + 0x84) != 1) || (iVar1 = FUN_00105594(param_1,1), iVar1 == 0)) &&
     (1 < *(int *)(param_1 + 0x84))) {
    iVar1 = 2;
    do {
      iVar2 = FUN_00105594(param_1,iVar1 + -1);
      iVar3 = FUN_00105594(param_1,iVar1);
      if ((iVar2 != iVar3) || (iVar2 = FUN_00105594(param_1,iVar1), iVar2 == 0)) {
        return 0;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 <= *(int *)(param_1 + 0x84));
  }
  return 1;
}

/* FUN_0011e894 @ 0x11e894 (180 bytes) */
int FUN_0011e894(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 900);
  iVar1 = *(int *)(iVar4 + 8);
  do {
    if (iVar1 == 0) {
      return 1;
    }
    iVar1 = FUN_000e79b8(iVar4);
    if (iVar1 != 0) {
      iVar1 = 0;
      for (uVar3 = 1; uVar3 <= *(uint *)(*(int *)(iVar4 + 0xd4) + 4); uVar3 = uVar3 + 1) {
        iVar2 = *(int *)(*(int *)(*(int *)(iVar4 + 0xd4) + 8) + iVar1);
        if ((iVar2 != 0) && (iVar2 = FUN_000e79a0(iVar2), iVar2 != 0)) {
          return 0;
        }
        iVar1 = iVar1 + 4;
      }
    }
    iVar4 = *(int *)(iVar4 + 8);
    iVar1 = *(int *)(iVar4 + 8);
  } while( true );
}

/* FUN_0011e948 @ 0x11e948 (64 bytes) */
int FUN_0011e948(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  
  if (((*(uint *)(param_2 + 0x14) & 0x40) != 0) &&
     (iVar1 = FUN_001309dc(param_1,*(undefined4 *)(param_2 + 0x94)), iVar1 != 0)) {
    return 1;
  }
  return 0;
}

/* FUN_0011e988 @ 0x11e988 (280 bytes) */
int FUN_0011e988(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar3 = 1;
  iVar2 = *(int *)(param_1 + 0xb0);
  if (0 < *(int *)(iVar2 + 0x84)) {
    iVar4 = 0x18;
    iVar5 = param_1;
    do {
      iVar2 = iVar4 + iVar2;
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x18;
      iVar1 = ((int (*)())FUN_00122fa4)(*(undefined4 *)(iVar2 + 0x8c),param_2,*(undefined4 *)(param_1 + 0x238));
      iVar2 = *(int *)(param_1 + 0xb0);
      *(undefined4 *)(iVar5 + 0x214) = *(undefined4 *)(iVar1 + 0xb0);
      iVar5 = iVar5 + 4;
    } while (iVar3 <= *(int *)(iVar2 + 0x84));
  }
  iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 0x238),7);
  if (((iVar2 != 0) && (iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 0x238),9), iVar2 != 0)) &&
     (*(int *)(*(int *)(param_1 + 0xb0) + 0x80) != 0)) {
    piVar6 = *(int **)(*(int *)(param_1 + 0xb0) + 0x8c);
    iVar2 = (**(code **)(*piVar6 + 0x18))(piVar6);
    if (((iVar2 != 0) && (*(int *)(*(int *)(param_1 + 0xb0) + 0x84) != 0)) &&
       ((*(uint *)(*(int *)(param_1 + 0xb0) + 0x14) & 0x200) == 0)) {
      iVar2 = ((int (*)())FUN_00122fa4)(piVar6,param_2,*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(iVar3 * 4 + param_1 + 0x210) = *(undefined4 *)(iVar2 + 0xb0);
    }
  }
  return;
}

/* FUN_0011eaa0 @ 0x11eaa0 (672 bytes) */
int FUN_0011eaa0(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  int iVar13;
  undefined4 *puVar14;
  int iVar15;
  undefined4 uVar16;
  uint uVar17;
  uint uVar18;
  undefined1 auStack_60 [16];
  int local_50;
  
  iVar15 = *(int *)(*(int *)(param_1 + 0x3bc) + 4);
  uVar16 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  uVar18 = iVar15 + 0x1fU >> 5;
  iVar13 = uVar18 * 4 + 0xc;
  puVar4 = (undefined4 *)FUN_00193e18(uVar16,iVar13);
  piVar11 = puVar4 + 1;
  *puVar4 = uVar16;
  puVar4[1] = uVar18;
  puVar4[2] = iVar15;
  if (uVar18 != 0) {
    piVar1 = piVar11;
    uVar17 = uVar18;
    if (uVar18 == 0) {
      uVar17 = 1;
    }
    do {
      piVar1[2] = 0;
      piVar1 = piVar1 + 1;
      uVar17 = uVar17 - 1;
    } while (uVar17 != 0);
  }
  uVar16 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar5 = (undefined4 *)FUN_00193e18(uVar16,iVar13);
  piVar1 = puVar5 + 1;
  *puVar5 = uVar16;
  puVar5[1] = uVar18;
  puVar5[2] = iVar15;
  if (uVar18 != 0) {
    piVar8 = piVar1;
    if (uVar18 == 0) {
      uVar18 = 1;
    }
    do {
      piVar8[2] = 0;
      piVar8 = piVar8 + 1;
      uVar18 = uVar18 - 1;
    } while (uVar18 != 0);
  }
  FUN_00194a94(auStack_60,*(undefined4 *)(*(int *)(param_1 + 0x3ac) + 4));
  iVar13 = local_50;
  while (iVar13 != 0) {
    uVar18 = *(uint *)(iVar13 + 0x1c);
    local_50 = iVar13;
    if ((((-1 < (int)uVar18) &&
         ((*(uint *)((uVar18 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 0x3b0) + 8) >> (uVar18 & 0x1f)
          & 1) != 0)) || (*(int *)(iVar13 + 4) == 0x3b)) ||
       ((*(int *)(iVar13 + 4) == 0x2c && (*(int *)(param_1 + 0x3b4) != 0)))) {
      iVar15 = *piVar1;
      if (iVar15 != 0) {
        piVar8 = piVar1;
        if (iVar15 == 0) {
          iVar15 = 1;
        }
        do {
          piVar8[2] = 0;
          piVar8 = piVar8 + 1;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
      iVar15 = *piVar11;
      if (iVar15 != 0) {
        piVar8 = piVar11;
        if (iVar15 == 0) {
          iVar15 = 1;
        }
        do {
          piVar8[2] = 0;
          piVar8 = piVar8 + 1;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
      iVar15 = 0;
      for (uVar18 = 1; uVar18 <= *(uint *)(*(int *)(iVar13 + 0x18) + 4); uVar18 = uVar18 + 1) {
        iVar2 = *(int *)(*(int *)(*(int *)(iVar13 + 0x18) + 8) + iVar15);
        if ((*(uint *)(iVar2 + 0x14) & 1) != 0) {
          uVar17 = *(uint *)(*(int *)(iVar2 + 0x158) + 0xb4);
          uVar9 = uVar17 >> 3 & 0x1ffffffc;
          *(uint *)((int)piVar11 + uVar9 + 8) =
               1 << (uVar17 & 0x1f) | *(uint *)((int)piVar11 + uVar9 + 8);
        }
        iVar15 = iVar15 + 4;
      }
      iVar15 = 0;
      for (uVar18 = 1; uVar18 <= *(uint *)(*(int *)(iVar13 + 0x18) + 4); uVar18 = uVar18 + 1) {
        iVar2 = *(int *)(*(int *)(*(int *)(iVar13 + 0x18) + 8) + iVar15);
        if ((*(uint *)(iVar2 + 0x14) & 1) != 0) {
          iVar2 = *(int *)(iVar2 + 0x158);
          iVar10 = 0;
          for (uVar17 = 1; iVar3 = *(int *)(iVar2 + 0xf8), uVar17 <= *(uint *)(iVar3 + 4);
              uVar17 = uVar17 + 1) {
            piVar8 = *(int **)(*(int *)(iVar3 + 8) + iVar10);
            uVar12 = (uint)piVar8[0x2d] >> 3 & 0x1ffffffc;
            uVar9 = piVar8[0x2d] & 0x1f;
            if ((*(uint *)((int)piVar1 + uVar12 + 8) >> uVar9 & 1) == 0) {
              uVar16 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
              puVar6 = (undefined4 *)FUN_00193e18(uVar16,0x168);
              *puVar6 = uVar16;
              puVar14 = puVar6 + 1;
              FUN_0010a398(puVar14,*(undefined4 *)(param_1 + 8));
              uVar16 = FUN_000e79dc(piVar8);
              puVar6[0x22] = uVar16;
              FUN_001046c8(puVar14,0,iVar13);
              if (*(int *)(iVar13 + 4) == 0x2c) {
                puVar6[0x28] = UNK_001afee0;
              }
              uVar7 = *(uint *)((int)piVar11 + uVar12 + 8);
              if ((uVar7 >> uVar9 & 1) == 0) {
                *(uint *)((int)piVar11 + uVar12 + 8) = 1 << uVar9 | uVar7;
                ((int (*)())FUN_0012306c)(iVar13,puVar14);
              }
              FUN_000e76c4(piVar8,puVar14);
              (**(code **)(*piVar8 + 0x48))();
              *(uint *)((int)piVar1 + uVar12 + 8) = 1 << uVar9 | *(uint *)((int)piVar1 + uVar12 + 8)
              ;
            }
            iVar10 = iVar10 + 4;
          }
        }
        iVar15 = iVar15 + 4;
      }
    }
    FUN_00194938(auStack_60);
    iVar13 = local_50;
  }
  if (piVar11 != (int *)0x0) {
    FUN_00193cc0(*puVar4,puVar4);
  }
  if (piVar1 != (int *)0x0) {
    FUN_00193cc0(*puVar5,puVar5);
  }
  return;
}

/* FUN_0011eec8 @ 0x11eec8 (1072 bytes) */
int FUN_0011eec8(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  char *pcVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40 [2];
  undefined4 local_38 [5];
  
  iVar3 = FUN_000e07dc(*(undefined4 *)(param_2 + 8),6);
  if (iVar3 != 0) {
    piVar4 = *(int **)(param_1 + 0xb0);
    iVar3 = param_1;
    for (iVar13 = 1; iVar7 = (**(code **)(*piVar4 + 0x14))(), iVar13 <= iVar7; iVar13 = iVar13 + 1)
    {
      piVar12 = (int *)(iVar3 + 0x214);
      iVar7 = (**(code **)(**(int **)(iVar3 + 0x214) + 100))();
      if ((((iVar7 == 0) ||
           (iVar7 = FUN_00126760(*(undefined4 *)(*(int *)(iVar3 + 0x214) + 0x98)), iVar7 == 0)) ||
          (iVar7 = ((int (*)())FUN_0011e948)(param_2,*(undefined4 *)(iVar3 + 0x214)), iVar7 != 0)) ||
         ((iVar7 = *(int *)(iVar3 + 0x214), *(int *)(iVar7 + 0x120) != 0 ||
          (*(int *)(iVar7 + 0x124) != 0)))) {
LAB_0011f2a8:
        piVar4 = *(int **)(param_1 + 0xb0);
      }
      else {
        FUN_001054ec(iVar7,0);
        iVar7 = FUN_00105dbc(iVar7,0);
        if (iVar7 != 0) goto LAB_0011f2a8;
        iVar14 = *(int *)(iVar3 + 0x214);
        iVar7 = FUN_00105594(iVar14,1);
        if (iVar7 == 0) {
          uVar5 = *(undefined4 *)(iVar14 + 0xb0);
        }
        else {
          iVar7 = FUN_00105594(iVar14,1);
          uVar5 = *(undefined4 *)(iVar7 + 0x98);
        }
        iVar7 = FUN_00126708(uVar5);
        if (iVar7 == 0) {
          iVar14 = *piVar12;
          iVar7 = FUN_00105594(iVar14,1);
          if (iVar7 == 0) {
            uVar5 = *(undefined4 *)(iVar14 + 0xb0);
          }
          else {
            iVar7 = FUN_00105594(iVar14,1);
            uVar5 = *(undefined4 *)(iVar7 + 0x98);
          }
          iVar7 = FUN_00126734(uVar5);
          if (iVar7 == 0) goto LAB_0011f2a8;
        }
        iVar7 = *piVar12;
        FUN_001054ec(iVar7,1);
        iVar7 = FUN_00105dbc(iVar7,1);
        if (iVar7 == 0) {
          iVar7 = *piVar12;
LAB_0011f054:
          iVar7 = FUN_00105594(iVar7,1);
          iVar14 = iVar13 * 0x18;
          uVar2 = *(uint *)(iVar14 + *(int *)(param_1 + 0xb0) + 0xa0);
          uVar8 = uVar2 >> 1 & 1;
          uVar1 = *(uint *)(*piVar12 + 0xb8) & 1;
          uVar9 = *(uint *)(*piVar12 + 0xb8) >> 1 & 1;
          if (uVar8 == 0) {
            uVar8 = uVar9;
            if ((uVar2 & 1) == 0) {
              if (uVar1 != 0) goto LAB_0011f0bc;
            }
            else if (uVar1 == 0) {
LAB_0011f0bc:
              uVar9 = 1;
              goto LAB_0011f0c4;
            }
            uVar9 = 0;
          }
LAB_0011f0c4:
          piVar4 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
          iVar6 = (**(code **)(*piVar4 + 0x11c))
                            (piVar4,*(int *)(param_1 + 0xb0),iVar13,iVar7,uVar8,uVar9);
          if ((iVar6 == 0) ||
             (iVar6 = FUN_000f45f8(*(undefined4 *)(param_1 + 0xb0),iVar13,*piVar12,param_2),
             iVar6 == 0)) goto LAB_0011f2a8;
          *(int *)(param_2 + 0xa4) = *(int *)(param_2 + 0xa4) + 1;
          iVar6 = *(int *)(param_1 + 0xb0);
          iVar10 = iVar6 + iVar14 + 0x80;
          if ((*(uint *)(iVar10 + 0x20) & 2) == 0) {
            if ((*(uint *)(*piVar12 + 0xb8) & 2) != 0) {
              FUN_00103d50(iVar10 + 0xc,2,1);
              iVar6 = *(int *)(param_1 + 0xb0);
            }
            if ((*(uint *)(iVar6 + iVar14 + 0x80 + 0x20) & 1) == 0) {
              if ((*(uint *)(*piVar12 + 0xb8) & 1) == 0) goto LAB_0011f190;
LAB_0011f188:
              uVar5 = 1;
            }
            else {
              if ((*(uint *)(*piVar12 + 0xb8) & 1) == 0) goto LAB_0011f188;
LAB_0011f190:
              uVar5 = 0;
            }
            FUN_00103d50(iVar14 + iVar6 + 0x8c,1,uVar5);
            iVar6 = *(int *)(param_1 + 0xb0);
          }
          iVar14 = FUN_001054ec(iVar6,iVar13);
          local_48 = *(undefined4 *)(iVar14 + 0x10);
          iVar14 = FUN_00113090(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                                *(undefined4 *)(param_1 + 0x238));
          if (iVar14 == 0) {
            FUN_000f3340(local_38,local_48,*(undefined4 *)(iVar3 + 0x228));
            local_48 = local_38[0];
          }
          iVar14 = FUN_001054ec(*piVar12,1);
          local_44 = *(undefined4 *)(iVar14 + 0x10);
          local_40[0] = DAT_001afedc;
          iVar14 = 0;
          pcVar11 = (char *)(iVar13 * 4 + param_1 + 0x224);
          iVar6 = 4;
          do {
            if (*pcVar11 != '\0') {
              *(undefined1 *)((int)local_40 + iVar14) =
                   *(undefined1 *)((int)local_40 + (*(byte *)((int)&local_48 + iVar14) - 4));
            }
            uVar5 = local_40[0];
            iVar14 = iVar14 + 1;
            pcVar11 = pcVar11 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
          if (iVar13 == 0) {
            *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x9c) = local_40[0];
          }
          else {
            iVar14 = FUN_001054ec(*(int *)(param_1 + 0xb0),iVar13);
            *(undefined4 *)(iVar14 + 0x10) = uVar5;
          }
          uVar5 = *(undefined4 *)(iVar7 + 0x8c);
          FUN_001046c8(*(undefined4 *)(param_1 + 0xb0),iVar13,uVar5);
          ((int (*)())FUN_001236e4)(uVar5,iVar13,*(undefined4 *)(param_1 + 0xb0));
          piVar4 = *(int **)(param_1 + 0xb0);
          *piVar12 = iVar7;
        }
        else {
          iVar7 = FUN_00105dbc(*piVar12,1);
          if (iVar7 != 1) goto LAB_0011f2a8;
          piVar4 = *(int **)(param_1 + 0xb0);
          iVar7 = *piVar12;
          if (piVar4[0x56] == *(int *)(iVar7 + 0x158)) goto LAB_0011f054;
        }
      }
      iVar3 = iVar3 + 4;
    }
  }
  return;
}

/* FUN_0011f2f8 @ 0x11f2f8 (640 bytes) */
int FUN_0011f2f8(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  iVar1 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),5);
  if ((iVar1 != 0) && (iVar1 = (**(code **)(*param_2 + 100))(param_2), iVar1 != 0)) {
    for (iVar1 = 1; iVar2 = (**(code **)(*param_2 + 0x14))(param_2), iVar1 <= iVar2;
        iVar1 = iVar1 + 1) {
      if ((param_2[iVar1 * 6 + 0x28] & 1U) != 0) {
        return 0;
      }
      if ((param_2[iVar1 * 6 + 0x28] & 2U) != 0) {
        return 0;
      }
      iVar2 = FUN_000f31e8(param_2,iVar1);
      if (iVar2 == 0) {
        return 0;
      }
    }
    if ((param_2[0x48] == 0) && (param_2[0x49] == 0)) {
      if ((param_2[0x20] != 0) &&
         (((iVar1 = FUN_00126760(param_2[0x26]), iVar1 != 0 && ((param_2[5] & 2U) == 0)) &&
          (iVar1 = (**(code **)(*param_2 + 0x50))(param_2), iVar1 == 0)))) {
        iVar1 = 4;
        piVar4 = param_2;
        do {
          if (*(byte *)(piVar4 + 0x27) - 2 < 2) {
            return 0;
          }
          piVar4 = (int *)((int)piVar4 + 1);
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
      FUN_001054ec(param_2,0);
      iVar1 = FUN_00105dbc(param_2,0);
      if (((iVar1 == 0) && ((param_2[5] & 2U) == 0)) &&
         (((param_2[5] & 0x200U) == 0 && (iVar1 = FUN_00126760(param_2[0x26]), iVar1 != 0)))) {
        iVar1 = FUN_00105594(param_2,1);
        if (iVar1 == 0) {
          iVar1 = param_2[0x2c];
        }
        else {
          iVar1 = FUN_00105594(param_2,1);
          iVar1 = *(int *)(iVar1 + 0x98);
        }
        iVar1 = FUN_0012678c(iVar1);
        if (iVar1 == 0) {
          iVar1 = FUN_00105594(param_2,1);
          if (iVar1 == 0) {
            iVar1 = param_2[0x2c];
          }
          else {
            iVar1 = FUN_00105594(param_2,1);
            iVar1 = *(int *)(iVar1 + 0x98);
          }
          if (((iVar1 != 0x31) && (iVar1 = ((int (*)())FUN_0011e948)(param_1,param_2), iVar1 == 0)) &&
             (*(int *)(param_1 + 0xa0) < *(int *)(*(int *)(param_1 + 8) + 0x650))) {
            uVar3 = ((int (*)())FUN_00122fa4)(param_2[0x29],*(undefined4 *)(param_1 + 0x3a0),
                                 *(int *)(param_1 + 8));
            FUN_000e9c00(param_3,param_2[0x23],uVar3);
            (**(code **)(*param_2 + 0xc))(param_2,0,*(undefined4 *)(param_1 + 8));
            param_2[5] = param_2[5] | 0x400;
            *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + 1;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_0011f578 @ 0x11f578 (588 bytes) */
int FUN_0011f578(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  uint local_44;
  uint local_40;
  undefined4 *local_3c;
  undefined4 local_38;
  
  local_38 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_44 = 2;
  local_40 = 0;
  local_3c = (undefined4 *)FUN_00193e18(local_38,8);
  *(undefined4 *)(*(int *)(param_1 + 0x3a0) + 0x114) = 0x10;
  uVar6 = *(undefined4 *)(param_1 + 0x3a0);
  if (local_40 < local_44) {
    local_3c[local_40] = 0;
    puVar3 = local_3c + local_40;
    local_40 = local_40 + 1;
  }
  else {
    puVar3 = (undefined4 *)FUN_0019423c(&local_44,local_40);
  }
  *puVar3 = uVar6;
  do {
    if (local_44 == 0) {
      puVar3 = (undefined4 *)FUN_0019423c(&local_44,0);
    }
    else {
      puVar3 = local_3c;
      if (local_40 == 0) {
        *local_3c = 0;
        local_40 = 1;
      }
    }
    piVar7 = (int *)*puVar3;
    FUN_00194208(&local_44,0);
    iVar5 = 0;
    for (uVar8 = 1; uVar8 <= *(uint *)(piVar7[0x34] + 4); uVar8 = uVar8 + 1) {
      piVar4 = *(int **)(*(int *)(piVar7[0x34] + 8) + iVar5);
      if ((piVar4 != (int *)0x0) && (piVar4[0x45] == 0)) {
        if (piVar7[0x2e] < piVar4[0x2e]) {
          piVar4[0x45] = piVar7[0x45] << 2;
        }
        else {
          iVar2 = (**(code **)(*piVar4 + 0x34))();
          if (iVar2 == 0) {
            iVar2 = (**(code **)(*piVar7 + 0x24))(piVar7);
            if (iVar2 == 0) {
              iVar2 = (**(code **)(*piVar4 + 0x28))();
              if (iVar2 != 0) {
                piVar4[0x45] = piVar7[0x45] << 1;
                goto LAB_0011f744;
              }
              iVar2 = piVar7[0x45];
            }
            else {
              uVar1 = piVar7[0x45];
              iVar2 = ((int)uVar1 >> 1) + (uint)((int)uVar1 < 0 && (uVar1 & 1) != 0);
              if (iVar2 < 1) {
                iVar2 = 1;
              }
            }
            piVar4[0x45] = iVar2;
          }
          else {
            piVar4[0x45] = *(int *)(piVar4[0x4b] + 0x114);
          }
        }
LAB_0011f744:
        if (local_40 < local_44) {
          local_3c[local_40] = 0;
          puVar3 = local_3c + local_40;
          local_40 = local_40 + 1;
        }
        else {
          puVar3 = (undefined4 *)FUN_0019423c(&local_44,local_40);
        }
        *puVar3 = piVar4;
      }
      iVar5 = iVar5 + 4;
    }
    if (local_40 == 0) {
      FUN_00193cc0(local_38,local_3c);
      return;
    }
  } while( true );
}

/* FUN_0011f7fc @ 0x11f7fc (164 bytes) */
int FUN_0011f7fc(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint *param_3;
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(param_1 + 0x474);
  if (iVar2 < *(int *)(param_2 + 0x150)) {
    uVar3 = *(int *)(param_2 + 0x150) - iVar2;
  }
  else {
    uVar3 = param_3[1];
    if (uVar3 < *param_3) {
      _memset(uVar3 * 4 + param_3[2],0,4);
      piVar1 = (int *)(uVar3 * 4 + param_3[2]);
      param_3[1] = uVar3 + 1;
    }
    else {
      piVar1 = (int *)FUN_0019423c(param_3,uVar3);
    }
    *piVar1 = param_2;
    uVar3 = param_3[1];
    *(uint *)(param_2 + 0x150) = uVar3 + iVar2;
  }
  return uVar3 - 1;
}

/* FUN_0011f8a0 @ 0x11f8a0 (756 bytes) */
int FUN_0011f8a0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  uint *param_1;
  int param_2;
  int *param_3;
  int param_4;
  uint param_5;
  int param_6;
  int param_7;
  int param_8;
  uint *param_9;
  uint param_10;
{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  code *pcVar8;
  int *piVar9;
  
  piVar2 = (int *)FUN_001043f0(0x31,param_7);
  piVar2[0x25] = param_2;
  piVar2[0x26] = 0;
  if (param_5 < *param_1) {
    uVar3 = param_1[1];
    if (uVar3 <= param_5) {
      _memset(uVar3 * 4 + param_1[2],0,(param_5 - uVar3) * 4 + 4);
      param_1[1] = param_5 + 1;
    }
  }
  else {
    FUN_0019423c(param_1,param_5);
  }
  if (param_5 < *param_1) {
    uVar3 = param_1[1];
    if (uVar3 <= param_5) {
      _memset(uVar3 * 4 + param_1[2],0,(param_5 - uVar3) * 4 + 4);
      param_1[1] = param_5 + 1;
    }
    puVar4 = (undefined4 *)(param_5 * 4 + param_1[2]);
  }
  else {
    puVar4 = (undefined4 *)FUN_0019423c(param_1,param_5);
  }
  FUN_00106004(piVar2,1,*puVar4,0,param_7);
  if (param_4 != 0) {
    piVar2[5] = piVar2[5] | 0x40;
  }
  piVar9 = *(int **)(*(int *)(param_7 + 0x30c) + 100);
  pcVar8 = *(code **)(*piVar9 + 0x20);
  if (param_5 < *param_1) {
    uVar3 = param_1[1];
    if (uVar3 <= param_5) {
      _memset(uVar3 * 4 + param_1[2],0,(param_5 - uVar3) * 4 + 4);
      param_1[1] = param_5 + 1;
    }
    puVar4 = (undefined4 *)(param_5 * 4 + param_1[2]);
  }
  else {
    puVar4 = (undefined4 *)FUN_0019423c(param_1,param_5);
  }
  iVar5 = (*pcVar8)(piVar9,*puVar4);
  if ((iVar5 != 0) && ((*(uint *)(param_6 + 0xc) & 0x200) == 0)) {
    piVar2[5] = piVar2[5] | 0x1000;
    *(uint *)(param_6 + 0xc) = *(uint *)(param_6 + 0xc) | 0x200;
  }
  FUN_000e7688(param_6,piVar2);
  iVar5 = DAT_001afee4;
  piVar2[5] = piVar2[5] | 0x40000000;
  if (*param_3 != iVar5) {
    piVar2[0x27] = *param_3;
    iVar5 = 0;
    do {
      iVar6 = FUN_001054ec(piVar2,0);
      if (*(char *)(iVar5 + iVar6 + 0x10) == '\x01') {
        (**(code **)(*piVar2 + 0x88))(piVar2,1,iVar5,4);
      }
      bVar1 = iVar5 != 3;
      iVar5 = iVar5 + 1;
    } while (bVar1);
  }
  if (param_8 != 0) {
    if (param_10 < *param_9) {
      uVar3 = param_9[1];
      if (uVar3 <= param_10) {
        _memset(uVar3 * 4 + param_9[2],0,(param_10 - uVar3) * 4 + 4);
        param_9[1] = param_10 + 1;
      }
      puVar4 = (undefined4 *)(param_10 * 4 + param_9[2]);
    }
    else {
      puVar4 = (undefined4 *)FUN_0019423c(param_9,param_10);
    }
    uVar7 = ((int (*)())FUN_0011f7fc)(*(undefined4 *)(param_7 + 0x6c4),piVar2,param_1);
    *puVar4 = uVar7;
  }
  return;
}

/* FUN_0011fb94 @ 0x11fb94 (944 bytes) */
int FUN_0011fb94(param_1)
  int param_1;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  uint local_38;
  uint local_34;
  int local_30;
  undefined4 local_2c;
  
  local_2c = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_34 = 0;
  local_38 = 2;
  local_30 = FUN_00193e18(local_2c,8);
  iVar5 = *(int *)(param_1 + 900);
  for (iVar3 = *(int *)(*(int *)(param_1 + 900) + 8); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    piVar8 = *(int **)(iVar5 + 0x98);
    piVar4 = (int *)piVar8[2];
    if ((int *)piVar8[2] != (int *)0x0) {
      do {
        piVar1 = piVar4;
        if ((piVar8[5] & 1U) != 0) {
          iVar3 = (**(code **)(*piVar8 + 0x7c))(piVar8);
          uVar7 = local_34;
          if (iVar3 == 0) {
            piVar1 = (int *)piVar8[2];
          }
          else {
            if (local_34 < local_38) {
              iVar9 = local_34 * 4;
              _memset(iVar9 + local_30,0,4);
              local_34 = uVar7 + 1;
              piVar4 = (int *)(iVar9 + local_30);
            }
            else {
              piVar4 = (int *)FUN_0019423c(&local_38,local_34);
            }
            *piVar4 = iVar3;
            *(undefined4 *)(iVar3 + 0x134) = 1;
            piVar1 = (int *)piVar8[2];
          }
        }
        piVar4 = (int *)piVar1[2];
        piVar8 = piVar1;
      } while ((int *)piVar1[2] != (int *)0x0);
      iVar3 = *(int *)(iVar5 + 8);
    }
    iVar5 = iVar3;
  }
  while ((local_34 != 0 && (*(int *)(param_1 + 0x22c) < *(int *)(*(int *)(param_1 + 8) + 0x66c)))) {
    uVar7 = local_34 - 1;
    puVar2 = (undefined4 *)0x0;
    if (uVar7 < local_34) {
      puVar2 = (undefined4 *)(uVar7 * 4 + local_30);
    }
    piVar4 = (int *)*puVar2;
    FUN_00194208(&local_38,uVar7);
    piVar4[0x4d] = 0;
    iVar5 = FUN_0011e6f4(piVar4);
    if (iVar5 != 0) {
      while (piVar8 = (int *)piVar4[4], piVar8[1] != 0) {
        if (*piVar8 == 0) {
          puVar2 = (undefined4 *)FUN_0019423c(piVar8,0);
        }
        else {
          puVar2 = (undefined4 *)piVar8[2];
        }
        piVar8 = (int *)*puVar2;
        iVar9 = 1;
        iVar3 = piVar8[0x22];
        if (*(int *)(iVar3 + 8) == 0x8e) {
          iVar9 = 1;
          if (0 < piVar8[0x21]) {
            do {
              piVar1 = (int *)FUN_00105594(piVar8,iVar9);
              if (piVar1 == piVar4) {
                FUN_00106004(piVar8,iVar9,iVar5,1,*(undefined4 *)(param_1 + 8));
              }
              iVar9 = iVar9 + 1;
            } while (iVar9 <= piVar8[0x21]);
            iVar3 = piVar8[0x22];
          }
          if (((*(int *)(iVar3 + 8) == 0x8e) &&
              (piVar1 = (int *)(**(code **)(*piVar8 + 0x7c))(piVar8), piVar4 != piVar1)) &&
             (iVar3 = (**(code **)(*piVar8 + 0x7c))(piVar8), *(int *)(iVar3 + 0x134) == 0)) {
            uVar6 = (**(code **)(*piVar8 + 0x7c))(piVar8);
            uVar7 = local_34;
            if (local_34 < local_38) {
              iVar3 = local_34 * 4;
              _memset(iVar3 + local_30,0,4);
              local_34 = uVar7 + 1;
              puVar2 = (undefined4 *)(iVar3 + local_30);
            }
            else {
              puVar2 = (undefined4 *)FUN_0019423c(&local_38,local_34);
            }
            *puVar2 = uVar6;
            iVar3 = (**(code **)(*piVar8 + 0x7c))(piVar8);
            *(undefined4 *)(iVar3 + 0x134) = 0;
          }
        }
        else {
          for (; iVar3 = (**(code **)(*piVar8 + 0x14))(piVar8), iVar9 <= iVar3; iVar9 = iVar9 + 1) {
            piVar1 = (int *)FUN_00105594(piVar8,iVar9);
            if (piVar1 == piVar4) {
              FUN_00106004(piVar8,iVar9,iVar5,1,*(undefined4 *)(param_1 + 8));
            }
          }
          if (((piVar8[5] & 0x200U) != 0) &&
             (piVar1 = (int *)FUN_00105594(piVar8,piVar8[0x21]), piVar1 == piVar4)) {
            FUN_00106804(piVar8,iVar5,1,*(undefined4 *)(param_1 + 8));
          }
        }
      }
      FUN_00104054(piVar4,param_1);
      (**(code **)(*piVar4 + 0xc))(piVar4,1,*(undefined4 *)(param_1 + 8));
      *(int *)(param_1 + 0x22c) = *(int *)(param_1 + 0x22c) + 1;
    }
  }
  FUN_00193cc0(local_2c,local_30);
  return;
}

/* FUN_0011ff7c @ 0x11ff7c (3416 bytes) */
int FUN_0011ff7c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int *param_2;
  uint *param_3;
  uint *param_4;
  uint *param_5;
  uint *param_6;
  uint *param_7;
  int *param_8;
{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  uint uVar14;
  undefined4 uVar15;
  uint uVar16;
  int local_68;
  int local_64;
  
  param_3[1] = 0;
  param_4[1] = 0;
  param_5[1] = 0;
  param_6[1] = 0;
  param_7[1] = 0;
  iVar11 = param_2[0x34];
  iVar13 = 0;
  local_64 = 0;
  for (uVar14 = 1; uVar14 <= *(uint *)(iVar11 + 4); uVar14 = uVar14 + 1) {
    local_64 = *(int *)(iVar13 + *(int *)(iVar11 + 8));
    if (local_64 != 0) {
      uVar1 = FUN_000e8098(local_64,param_2);
      piVar10 = *(int **)(local_64 + 0x98);
      for (piVar2 = (int *)(*(int **)(local_64 + 0x98))[2]; piVar2 != (int *)0x0;
          piVar2 = (int *)piVar2[2]) {
        if ((piVar10[5] & 1U) == 0) goto LAB_00120400;
        iVar11 = (**(code **)(*piVar10 + 0x7c))(piVar10);
        if (iVar11 == 0) {
LAB_001203fc:
          piVar2 = (int *)piVar10[2];
        }
        else {
          piVar2 = (int *)FUN_00105594(iVar11,uVar1);
          if ((((piVar2[0x20] == 0) || (iVar3 = FUN_00126760(piVar2[0x26]), iVar3 == 0)) ||
              ((piVar2[5] & 2U) != 0)) ||
             (iVar3 = (**(code **)(*piVar2 + 0x50))(piVar2), iVar3 != 0)) {
            iVar3 = (**(code **)(*piVar2 + 0x60))(piVar2);
            if (iVar3 != 0) goto LAB_001200cc;
            goto LAB_001203fc;
          }
          iVar3 = FUN_001054ec(iVar11,0);
          iVar4 = FUN_001054ec(piVar2,0);
          if (((iVar3 == iVar4) && (*(int *)(iVar11 + 0x98) == piVar2[0x26])) &&
             ((*(uint *)(iVar11 + 0x14) >> 6 & 1) == ((uint)piVar2[5] >> 6 & 1))) goto LAB_001203fc;
LAB_001200cc:
          uVar5 = ((int (*)())FUN_0011f7fc)(param_1,iVar11,param_7);
          uVar6 = ((int (*)())FUN_0011f7fc)(param_1,piVar2,param_7);
          uVar16 = param_4[1];
          if (uVar16 < *param_4) {
            _memset(uVar16 * 4 + param_4[2],0,4);
            param_4[1] = uVar16 + 1;
            piVar2 = (int *)(uVar16 * 4 + param_4[2]);
          }
          else {
            piVar2 = (int *)FUN_0019423c(param_4,uVar16);
          }
          *piVar2 = uVar5 + uVar6 * 0x10000;
          if (uVar6 < *param_5) {
            uVar16 = param_5[1];
            if (uVar16 <= uVar6) {
              _memset(uVar16 * 4 + param_5[2],0,(uVar6 - uVar16) * 4 + 4);
              param_5[1] = uVar6 + 1;
            }
            puVar7 = (uint *)(uVar6 * 4 + param_5[2]);
          }
          else {
            puVar7 = (uint *)FUN_0019423c(param_5,uVar6);
          }
          *puVar7 = uVar6;
          if (uVar5 < *param_5) {
            uVar16 = param_5[1];
            if (uVar16 <= uVar5) {
              _memset(uVar16 * 4 + param_5[2],0,(uVar5 - uVar16) * 4 + 4);
              param_5[1] = uVar5 + 1;
            }
            puVar7 = (uint *)(uVar5 * 4 + param_5[2]);
          }
          else {
            puVar7 = (uint *)FUN_0019423c(param_5,uVar5);
          }
          *puVar7 = uVar5;
          if (uVar6 < *param_3) {
            uVar16 = param_3[1];
            if (uVar16 <= uVar6) {
              _memset(uVar16 * 4 + param_3[2],0,(uVar6 - uVar16) * 4 + 4);
              param_3[1] = uVar6 + 1;
            }
            puVar8 = (undefined4 *)(uVar6 * 4 + param_3[2]);
          }
          else {
            puVar8 = (undefined4 *)FUN_0019423c(param_3,uVar6);
          }
          *puVar8 = 1;
          if (uVar6 < *param_5) {
            uVar16 = param_5[1];
            if (uVar16 <= uVar6) {
              _memset(uVar16 * 4 + param_5[2],0,(uVar6 - uVar16) * 4 + 4);
              param_5[1] = uVar6 + 1;
            }
            puVar7 = (uint *)(uVar6 * 4 + param_5[2]);
          }
          else {
            puVar7 = (uint *)FUN_0019423c(param_5,uVar6);
          }
          uVar6 = *puVar7;
          if (uVar6 < *param_7) {
            uVar16 = param_7[1];
            if (uVar16 <= uVar6) {
              _memset(uVar16 * 4 + param_7[2],0,(uVar6 - uVar16) * 4 + 4);
              param_7[1] = uVar6 + 1;
            }
          }
          else {
            FUN_0019423c(param_7,uVar6);
          }
          if (uVar5 < *param_5) {
            uVar6 = param_5[1];
            if (uVar6 <= uVar5) {
              _memset(uVar6 * 4 + param_5[2],0,(uVar5 - uVar6) * 4 + 4);
              param_5[1] = uVar5 + 1;
            }
            puVar7 = (uint *)(uVar5 * 4 + param_5[2]);
          }
          else {
            puVar7 = (uint *)FUN_0019423c(param_5,uVar5);
          }
          uVar5 = *puVar7;
          if (uVar5 < *param_7) {
            uVar6 = param_7[1];
            if (uVar5 < uVar6) goto LAB_001203fc;
            _memset(uVar6 * 4 + param_7[2],0,(uVar5 - uVar6) * 4 + 4);
            param_7[1] = uVar5 + 1;
            piVar2 = (int *)piVar10[2];
          }
          else {
            FUN_0019423c(param_7,uVar5);
            piVar2 = (int *)piVar10[2];
          }
        }
LAB_00120400:
        piVar10 = piVar2;
      }
      iVar11 = param_2[0x34];
    }
    iVar13 = iVar13 + 4;
  }
  uVar14 = param_4[1];
  uVar5 = uVar14 - 1;
  if (-1 < (int)uVar5) {
    iVar11 = uVar5 * 4;
    uVar6 = 0;
    do {
      if (uVar5 < *param_4) {
        uVar16 = param_4[1];
        if (uVar16 <= uVar5) {
          _memset(uVar16 * 4 + param_4[2],0,(uVar5 - uVar16) * 4 + 4);
          param_4[1] = uVar5 + 1;
        }
        puVar8 = (undefined4 *)(iVar11 + param_4[2]);
      }
      else {
        puVar8 = (undefined4 *)FUN_0019423c(param_4,uVar5);
      }
      uVar1 = *puVar8;
      uVar16 = FUN_0011e6ec(uVar1);
      if (uVar16 < *param_3) {
        uVar9 = param_3[1];
        if (uVar9 <= uVar16) {
          _memset(uVar9 * 4 + param_3[2],0,(uVar16 - uVar9) * 4 + 4);
          param_3[1] = uVar16 + 1;
        }
        piVar10 = (int *)(uVar16 * 4 + param_3[2]);
      }
      else {
        piVar10 = (int *)FUN_0019423c(param_3,uVar16);
      }
      if (*piVar10 == 0) {
        uVar16 = param_6[1];
        if (uVar16 < *param_6) {
          _memset(uVar16 * 4 + param_6[2],0,4);
          param_6[1] = uVar16 + 1;
          puVar8 = (undefined4 *)(uVar16 * 4 + param_6[2]);
        }
        else {
          puVar8 = (undefined4 *)FUN_0019423c(param_6,uVar16);
        }
        *puVar8 = uVar1;
        FUN_00194208(param_4,uVar5);
      }
      uVar6 = uVar6 + 1;
      uVar5 = uVar5 - 1;
      iVar11 = iVar11 + -4;
    } while (uVar14 != uVar6);
  }
  uVar14 = param_6[1];
  do {
    if (uVar14 != 0) goto LAB_00120b04;
    do {
      if (param_4[1] == 0) {
        *(uint *)(param_1 + 0x474) = *(int *)(param_1 + 0x474) + param_7[1];
        return;
      }
LAB_00120b04:
      while (uVar14 != 0) {
        uVar5 = uVar14 - 1;
        if (uVar5 < *param_6) {
          if (uVar14 <= uVar5) {
            _memset(uVar14 * 4 + param_6[2],0,(uVar5 - uVar14) * 4 + 4);
            param_6[1] = uVar14;
          }
          piVar10 = (int *)(uVar5 * 4 + param_6[2]);
        }
        else {
          piVar10 = (int *)FUN_0019423c(param_6,uVar5);
        }
        uVar6 = *piVar10 >> 0x10;
        uVar14 = FUN_0011e6ec(*piVar10);
        FUN_00194208(param_6,uVar5);
        uVar5 = *param_7;
        if (uVar14 < uVar5) {
          uVar16 = param_7[1];
          if (uVar16 <= uVar14) {
            _memset(uVar16 * 4 + param_7[2],0,(uVar14 - uVar16) * 4 + 4);
            uVar5 = *param_7;
            param_7[1] = uVar14 + 1;
          }
          piVar10 = (int *)(uVar14 * 4 + param_7[2]);
        }
        else {
          piVar10 = (int *)FUN_0019423c(param_7,uVar14);
          uVar5 = *param_7;
        }
        uVar1 = *(undefined4 *)(*piVar10 + 0x94);
        if (uVar14 < uVar5) {
          uVar5 = param_7[1];
          if (uVar5 <= uVar14) {
            _memset(uVar5 * 4 + param_7[2],0,(uVar14 - uVar5) * 4 + 4);
            param_7[1] = uVar14 + 1;
          }
          puVar8 = (undefined4 *)(uVar14 * 4 + param_7[2]);
        }
        else {
          puVar8 = (undefined4 *)FUN_0019423c(param_7,uVar14);
        }
        iVar11 = FUN_001054ec(*puVar8,0);
        local_68 = *(int *)(iVar11 + 0x10);
        if (uVar14 < *param_7) {
          uVar5 = param_7[1];
          if (uVar5 <= uVar14) {
            _memset(uVar5 * 4 + param_7[2],0,(uVar14 - uVar5) * 4 + 4);
            param_7[1] = uVar14 + 1;
          }
          piVar10 = (int *)(uVar14 * 4 + param_7[2]);
        }
        else {
          piVar10 = (int *)FUN_0019423c(param_7,uVar14);
        }
        uVar5 = *(uint *)(*piVar10 + 0x14) >> 6 & 1;
        piVar10 = (int *)FUN_000e9184(param_2,0);
        iVar11 = (**(code **)(*piVar10 + 0x2c))();
        if (iVar11 == 0) {
LAB_0012079c:
          iVar11 = (**(code **)(*param_2 + 0x38))(param_2);
          if (iVar11 != 0) {
            uVar15 = 0;
            piVar10 = param_2;
            goto LAB_00120890;
          }
          if (uVar6 < *param_5) {
            uVar16 = param_5[1];
            if (uVar16 <= uVar6) {
              _memset(uVar16 * 4 + param_5[2],0,(uVar6 - uVar16) * 4 + 4);
              param_5[1] = uVar6 + 1;
            }
            puVar8 = (undefined4 *)(uVar6 * 4 + param_5[2]);
          }
          else {
            puVar8 = (undefined4 *)FUN_0019423c(param_5,uVar6);
          }
          uVar12 = *(undefined4 *)(param_1 + 8);
          uVar15 = *puVar8;
          piVar10 = param_2;
        }
        else {
          piVar10 = (int *)FUN_000e920c(param_2,0);
          iVar11 = (**(code **)(*piVar10 + 0x34))();
          if (iVar11 == 0) goto LAB_0012079c;
          uVar15 = FUN_000e9184(param_2,0);
          uVar15 = FUN_000e9184(uVar15,0);
          if (uVar6 < *param_5) {
            uVar16 = param_5[1];
            if (uVar16 <= uVar6) {
              _memset(uVar16 * 4 + param_5[2],0,(uVar6 - uVar16) * 4 + 4);
              param_5[1] = uVar6 + 1;
            }
            puVar8 = (undefined4 *)(uVar6 * 4 + param_5[2]);
          }
          else {
            puVar8 = (undefined4 *)FUN_0019423c(param_5,uVar6);
          }
          ((int (*)())FUN_0011f8a0)(param_7,uVar1,&local_68,uVar5,*puVar8,uVar15,*(undefined4 *)(param_1 + 8),0,0
                       ,0xffffffff);
          piVar10 = (int *)FUN_000e9184(param_2,0);
          uVar15 = 1;
LAB_00120890:
          piVar10 = (int *)FUN_000e9184(piVar10,uVar15);
          if (uVar6 < *param_5) {
            uVar16 = param_5[1];
            if (uVar16 <= uVar6) {
              _memset(uVar16 * 4 + param_5[2],0,(uVar6 - uVar16) * 4 + 4);
              param_5[1] = uVar6 + 1;
            }
            puVar8 = (undefined4 *)(uVar6 * 4 + param_5[2]);
          }
          else {
            puVar8 = (undefined4 *)FUN_0019423c(param_5,uVar6);
          }
          uVar15 = *puVar8;
          uVar12 = *(undefined4 *)(param_1 + 8);
        }
        ((int (*)())FUN_0011f8a0)(param_7,uVar1,&local_68,uVar5,uVar15,piVar10,uVar12,0,0,0xffffffff);
        if (local_68 == DAT_001afee4) {
          if (uVar6 < *param_5) {
            uVar5 = param_5[1];
            if (uVar5 <= uVar6) {
              _memset(uVar5 * 4 + param_5[2],0,(uVar6 - uVar5) * 4 + 4);
              param_5[1] = uVar6 + 1;
            }
            puVar7 = (uint *)(uVar6 * 4 + param_5[2]);
          }
          else {
            puVar7 = (uint *)FUN_0019423c(param_5,uVar6);
          }
          *puVar7 = uVar14;
        }
        uVar14 = param_4[1];
        uVar5 = uVar14 - 1;
        if (-1 < (int)uVar5) {
          iVar11 = uVar5 * 4;
          uVar16 = 0;
          do {
            if (uVar5 < *param_4) {
              uVar9 = param_4[1];
              if (uVar9 <= uVar5) {
                _memset(uVar9 * 4 + param_4[2],0,(uVar5 - uVar9) * 4 + 4);
                param_4[1] = uVar5 + 1;
              }
              puVar8 = (undefined4 *)(iVar11 + param_4[2]);
            }
            else {
              puVar8 = (undefined4 *)FUN_0019423c(param_4,uVar5);
            }
            uVar1 = *puVar8;
            uVar9 = FUN_0011e6ec(uVar1);
            if (uVar6 == uVar9) {
              uVar14 = param_6[1];
              if (uVar14 < *param_6) {
                _memset(uVar14 * 4 + param_6[2],0,4);
                param_6[1] = uVar14 + 1;
                puVar8 = (undefined4 *)(uVar14 * 4 + param_6[2]);
              }
              else {
                puVar8 = (undefined4 *)FUN_0019423c(param_6,uVar14);
              }
              *puVar8 = uVar1;
              FUN_00194208(param_4,uVar5);
              break;
            }
            uVar16 = uVar16 + 1;
            uVar5 = uVar5 - 1;
            iVar11 = iVar11 + -4;
          } while (uVar14 != uVar16);
        }
        uVar14 = param_6[1];
      }
      uVar5 = param_4[1];
    } while (uVar5 == 0);
    uVar14 = uVar5 - 1;
    if (uVar14 < *param_4) {
      if (uVar5 <= uVar14) {
        _memset(uVar5 * 4 + param_4[2],0,(uVar14 - uVar5) * 4 + 4);
        param_4[1] = uVar5;
      }
      puVar8 = (undefined4 *)(uVar14 * 4 + param_4[2]);
    }
    else {
      puVar8 = (undefined4 *)FUN_0019423c(param_4,uVar14);
    }
    uVar15 = *puVar8;
    uVar1 = FUN_0011e6ec(uVar15);
    FUN_00194208(param_4,uVar14);
    iVar13 = *(int *)(*(int *)(param_1 + 8) + 0x3c4) + 1;
    *(int *)(*(int *)(param_1 + 8) + 0x3c4) = iVar13;
    piVar10 = (int *)FUN_000e9184(param_2,0);
    iVar11 = (**(code **)(*piVar10 + 0x2c))();
    if (iVar11 == 0) {
LAB_00120cb8:
      (**(code **)(*param_2 + 0x38))(param_2);
    }
    else {
      piVar10 = (int *)FUN_000e920c(param_2,0);
      iVar11 = (**(code **)(*piVar10 + 0x34))();
      if (iVar11 == 0) goto LAB_00120cb8;
    }
    ((int (*)())FUN_0011f8a0)(param_7,iVar13,&DAT_001afee4,0,uVar1,param_2,*(undefined4 *)(param_1 + 8),1,param_5
                 ,uVar1);
    uVar14 = param_6[1];
    if (uVar14 < *param_6) {
      _memset(uVar14 * 4 + param_6[2],0,4);
      param_6[1] = uVar14 + 1;
      puVar8 = (undefined4 *)(uVar14 * 4 + param_6[2]);
    }
    else {
      puVar8 = (undefined4 *)FUN_0019423c(param_6,uVar14);
    }
    *puVar8 = uVar15;
    *param_8 = *param_8 + 1;
    uVar14 = param_6[1];
  } while( true );
}

/* FUN_00120cd4 @ 0x120cd4 (384 bytes) */
int FUN_00120cd4(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *in_r6;
  undefined4 *in_r7;
  undefined4 *in_r8;
  undefined4 *in_r9;
  int *in_r10;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  int local_48 [7];
  
  puVar1 = (undefined4 *)FUN_000ec4f0(param_1);
  iVar2 = FUN_00194034(param_1 + 0x37c);
  uVar13 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar3 = (undefined4 *)FUN_00193e18(uVar13,0x14);
  *puVar3 = uVar13;
  puVar3[1] = 2;
  puVar3[4] = uVar13;
  puVar3[2] = 0;
  uVar13 = FUN_00193e18(uVar13,8);
  puVar3[3] = uVar13;
  uVar13 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar4 = (undefined4 *)FUN_00193e18(uVar13,0x14);
  puVar8 = puVar4 + 1;
  *puVar4 = uVar13;
  puVar4[1] = 2;
  puVar4[4] = uVar13;
  puVar4[2] = 0;
  uVar13 = FUN_00193e18(uVar13,8);
  puVar4[3] = uVar13;
  uVar13 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar5 = (undefined4 *)FUN_00193e18(uVar13,0x14);
  puVar9 = puVar5 + 1;
  *puVar5 = uVar13;
  puVar5[1] = 2;
  puVar5[2] = 0;
  puVar5[4] = uVar13;
  uVar13 = FUN_00193e18(uVar13,8);
  puVar5[3] = uVar13;
  uVar13 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar6 = (undefined4 *)FUN_00193e18(uVar13,0x14);
  puVar10 = puVar6 + 1;
  puVar6[1] = 2;
  *puVar6 = uVar13;
  puVar6[2] = 0;
  puVar6[4] = uVar13;
  uVar13 = FUN_00193e18(uVar13,8);
  puVar6[3] = uVar13;
  uVar13 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar7 = (undefined4 *)FUN_00193e18(uVar13,0x14);
  puVar12 = puVar7 + 1;
  puVar7[1] = 2;
  *puVar7 = uVar13;
  puVar7[2] = 0;
  puVar7[4] = uVar13;
  uVar13 = FUN_00193e18(uVar13,8);
  puVar7[3] = uVar13;
  local_48[0] = 0;
  if (0 < iVar2) {
    iVar11 = 1;
    do {
      puVar1 = puVar1 + 1;
      iVar11 = iVar11 + 1;
      in_r10 = local_48;
      in_r6 = puVar8;
      in_r7 = puVar9;
      in_r8 = puVar10;
      in_r9 = puVar12;
      ((int (*)())FUN_0011ff7c)(param_1,*puVar1,puVar3 + 1,puVar8,puVar9,puVar10,puVar12,in_r10);
    } while (iVar11 <= iVar2);
  }
  if (puVar12 != (undefined4 *)0x0) {
    FUN_00193cc0(puVar7[4],puVar7[3]);
    FUN_00193cc0(*puVar7,puVar7);
  }
  if (puVar10 != (undefined4 *)0x0) {
    FUN_00193cc0(puVar6[4],puVar6[3]);
    FUN_00193cc0(*puVar6,puVar6);
  }
  if (puVar9 != (undefined4 *)0x0) {
    FUN_00193cc0(puVar5[4],puVar5[3]);
    FUN_00193cc0(*puVar5,puVar5);
  }
  if (puVar8 != (undefined4 *)0x0) {
    FUN_00193cc0(puVar4[4],puVar4[3]);
    FUN_00193cc0(*puVar4,puVar4);
  }
  if (puVar3 + 1 != (undefined4 *)0x0) {
    FUN_00193cc0(puVar3[4],puVar3[3]);
    FUN_00193cc0(*puVar3,puVar3);
  }
  if (local_48[0] != 0) {
    FUN_000e0e0c(*(undefined4 *)(param_1 + 8),
                 "SSA : Phi Replace -> %d added temps to break cycles\n",local_48[0],in_r6,in_r7,
                 in_r8,in_r9,in_r10);
  }
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xfffffffb | 0x40;
  return;
}

/* FUN_00121000 @ 0x121000 (1160 bytes) */
int FUN_00121000(param_1)
  int param_1;
{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  undefined4 uVar15;
  int **ppiVar16;
  int *piVar17;
  uint local_78;
  uint local_74;
  int local_70;
  undefined4 local_6c;
  uint local_68;
  uint local_64;
  int local_60;
  undefined4 local_5c;
  int *local_58 [11];
  
  local_6c = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_74 = 0;
  local_78 = 2;
  local_70 = FUN_00193e18(local_6c,8);
  uVar14 = local_74;
  uVar15 = *(undefined4 *)(param_1 + 0x3a0);
  if (local_74 < local_78) {
    iVar13 = local_74 * 4;
    _memset(local_70 + iVar13,0,4);
    local_74 = uVar14 + 1;
    puVar5 = (undefined4 *)(iVar13 + local_70);
  }
  else {
    puVar5 = (undefined4 *)FUN_0019423c(&local_78,local_74);
  }
  *puVar5 = uVar15;
  local_5c = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_64 = 0;
  local_68 = 2;
  iVar13 = *(int *)(param_1 + 0x3a0);
  local_60 = FUN_00193e18(local_5c,8);
  do {
    piVar9 = *(int **)(iVar13 + 0x98);
    for (piVar2 = (int *)(*(int **)(iVar13 + 0x98))[2]; piVar2 != (int *)0x0;
        piVar2 = (int *)piVar2[2]) {
      if (((((*(int *)(piVar9[0x22] + 8) != 0x8e) &&
            (iVar6 = (**(code **)(*piVar9 + 0x68))(piVar9), iVar6 == 0)) &&
           (iVar6 = FUN_0012ab04(piVar9), iVar6 == 0)) &&
          ((piVar9[0x21] != 0 && ((piVar9[5] & 8U) == 0)))) &&
         (iVar6 = FUN_001045e4(piVar9), iVar6 == 0)) {
        iVar6 = 0;
        piVar11 = (int *)piVar9[0x56];
        if (0 < piVar9[0x21]) {
          ppiVar16 = local_58;
          do {
            iVar6 = iVar6 + 1;
            iVar7 = FUN_00105594(piVar9,iVar6);
            *ppiVar16 = *(int **)(iVar7 + 0x158);
            ppiVar16 = ppiVar16 + 1;
          } while (iVar6 < piVar9[0x21]);
        }
        piVar8 = local_58;
        local_64 = 0;
        piVar12 = (int *)0x0;
        if (piVar11 != (int *)0x0) {
          piVar12 = piVar11;
          piVar17 = piVar11;
          do {
            if (iVar6 < 0) {
LAB_001211d0:
              bVar1 = false;
            }
            else {
              iVar10 = 0;
              iVar7 = 0;
              piVar4 = piVar8;
              while (piVar17 != piVar4) {
                iVar10 = iVar10 + 1;
                if (iVar6 < iVar10) goto LAB_001211d0;
                iVar7 = iVar10 * 4;
                piVar4 = local_58[iVar10];
              }
              bVar1 = true;
              piVar11 = *(int **)((int)local_58 + iVar7);
            }
            iVar7 = (**(code **)(*piVar17 + 0x2c))(piVar17);
            if (iVar7 != 0) {
              if (local_64 < local_68) {
                iVar7 = local_64 * 4;
                local_64 = local_64 + 1;
                *(undefined4 *)(iVar7 + local_60) = 0;
                puVar5 = (undefined4 *)(iVar7 + local_60);
              }
              else {
                puVar5 = (undefined4 *)FUN_0019423c(&local_68,local_64);
              }
              *puVar5 = piVar17;
            }
          } while ((!bVar1) &&
                  (piVar4 = piVar17 + 0x3c, piVar12 = piVar17, piVar17 = (int *)*piVar4,
                  (int *)*piVar4 != (int *)0x0));
        }
        iVar6 = (**(code **)(*piVar11 + 0x2c))(piVar11);
        if (iVar6 != 0) {
          piVar11 = piVar12;
        }
        uVar14 = 0;
        if (local_64 != 0) {
          do {
            if (uVar14 < local_68) {
              piVar8 = (int *)(uVar14 * 4 + local_60);
            }
            else {
              piVar8 = (int *)FUN_0019423c(&local_68,uVar14);
            }
            iVar6 = *(int *)(*piVar8 + 0x98);
            for (iVar7 = *(int *)(*(int *)(*piVar8 + 0x98) + 8); iVar7 != 0;
                iVar7 = *(int *)(iVar7 + 8)) {
              if (((*(uint *)(iVar6 + 0x14) & 1) != 0) &&
                 (*(int *)(*(int *)(iVar6 + 0x88) + 8) == 0x8e)) {
                piVar8 = (int *)FUN_00105594(iVar6,1);
                if (piVar9 == piVar8) {
                  bVar1 = false;
                  goto LAB_00121318;
                }
                iVar7 = *(int *)(iVar6 + 8);
              }
              iVar6 = iVar7;
            }
            bVar1 = true;
LAB_00121318:
            uVar14 = uVar14 + 1;
            if (!bVar1) goto LAB_00121390;
          } while (uVar14 < local_64);
        }
        if ((piVar11 != (int *)piVar9[0x56]) && (piVar11[0x45] < ((int *)piVar9[0x56])[0x45])) {
          FUN_0010401c(piVar9);
          piVar9[5] = piVar9[5] | 1;
          FUN_000e7688(piVar11,piVar9);
          iVar6 = *(int *)(*(int *)(param_1 + 8) + 0x6c4);
          *(int *)(iVar6 + 0x1b8) = *(int *)(iVar6 + 0x1b8) + 1;
        }
      }
LAB_00121390:
      piVar9 = piVar2;
    }
    iVar6 = FUN_000e7a10(iVar13);
    if (iVar6 == 0) {
      piVar9 = (int *)0x0;
      uVar14 = local_74 - 1;
      if (uVar14 < local_74) {
        piVar9 = (int *)(uVar14 * 4 + local_70);
      }
      iVar13 = *piVar9;
      FUN_00194208(&local_78,uVar14);
    }
    else {
      iVar6 = *(int *)(iVar13 + 0xf4);
      piVar9 = (int *)0x0;
      if (*(uint *)(iVar6 + 4) != 0) {
        piVar9 = *(int **)(iVar6 + 8);
      }
      iVar13 = *piVar9;
      if (1 < *(uint *)(iVar6 + 4)) {
        uVar14 = 1;
        do {
          uVar3 = local_74;
          uVar15 = *(undefined4 *)(uVar14 * 4 + *(int *)(iVar6 + 8));
          if (local_74 < local_78) {
            iVar7 = local_74 * 4;
            _memset(iVar7 + local_70,0,4);
            local_74 = uVar3 + 1;
            puVar5 = (undefined4 *)(iVar7 + local_70);
          }
          else {
            puVar5 = (undefined4 *)FUN_0019423c(&local_78,local_74);
          }
          *puVar5 = uVar15;
          uVar14 = uVar14 + 1;
        } while (uVar14 < *(uint *)(iVar6 + 4));
      }
    }
    if (local_74 == 0) {
      FUN_00193cc0(local_5c,local_60);
      FUN_00193cc0(local_6c,local_70);
      return;
    }
  } while( true );
}

/* FUN_001214fc @ 0x1214fc (6188 bytes) */
int FUN_001214fc(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  uint *puVar16;
  uint *puVar17;
  int *piVar18;
  undefined4 uVar19;
  uint uVar20;
  uint *puVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  undefined4 *local_68;
  int local_64;
  int local_60;
  uint local_5c;
  uint local_58;
  int local_54;
  undefined4 local_50;
  
  local_50 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_58 = 0;
  local_5c = 2;
  local_54 = FUN_00193e18(local_50,8);
  uVar4 = local_58;
  uVar19 = *(undefined4 *)(param_1 + 0x3a0);
  if (local_58 < local_5c) {
    iVar3 = local_58 * 4;
    _memset(local_54 + iVar3,0,4);
    local_58 = uVar4 + 1;
    puVar9 = (undefined4 *)(iVar3 + local_54);
  }
  else {
    puVar9 = (undefined4 *)FUN_0019423c(&local_5c,local_58);
  }
  *puVar9 = uVar19;
  piVar18 = *(int **)(param_1 + 0x3a0);
  piVar18[0x45] = 0x10;
  piVar18[0x2f] = 0;
  *(int *)(param_1 + 0x474) = *(int *)(param_1 + 0x474) + 1;
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x324);
  *(undefined4 *)(param_1 + 0x334) = 0;
  *(int *)(param_1 + 0x478) = iVar3 * 4 + *(int *)(param_1 + 0x478);
  iVar3 = FUN_000e07dc(*(int *)(param_1 + 8),7);
  if (iVar3 != 0) {
    iVar3 = *(int *)(param_1 + 8);
    uVar19 = *(undefined4 *)(iVar3 + 0x378);
    puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x14);
    *puVar9 = uVar19;
    puVar9[1] = 2;
    puVar9[4] = uVar19;
    puVar9[2] = 0;
    uVar19 = FUN_00193e18(uVar19,8);
    puVar9[3] = uVar19;
    *(undefined4 **)(iVar3 + 0x3d8) = puVar9 + 1;
    iVar3 = *(int *)(param_1 + 8);
    uVar19 = *(undefined4 *)(iVar3 + 0x378);
    puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x14);
    *puVar9 = uVar19;
    puVar9[1] = 2;
    puVar9[2] = 0;
    puVar9[4] = uVar19;
    uVar19 = FUN_00193e18(uVar19,8);
    puVar9[3] = uVar19;
    *(undefined4 **)(iVar3 + 0x3dc) = puVar9 + 1;
    iVar3 = *(int *)(param_1 + 8);
    uVar19 = *(undefined4 *)(iVar3 + 0x378);
    puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x1c);
    puVar2 = PTR_FUN_001e90b8;
    puVar1 = PTR_FUN_001e9098;
    puVar15 = puVar9 + 1;
    uVar4 = 1;
    *puVar9 = uVar19;
    puVar9[4] = puVar2;
    puVar9[1] = 1;
    iVar23 = 0x20;
    puVar9[5] = puVar1;
    puVar9[6] = uVar19;
    do {
      uVar4 = uVar4 << 1;
      if (0x3ff < uVar4) break;
      iVar23 = iVar23 + -1;
    } while (iVar23 != 0);
    *puVar15 = uVar4;
    puVar9[2] = 0;
    uVar19 = FUN_00193e18(uVar19,*puVar15 << 2);
    puVar9[3] = uVar19;
    _memset(uVar19,0,*puVar15 << 2);
    *(uint **)(iVar3 + 0x3e0) = puVar15;
    iVar3 = *(int *)(param_1 + 8);
    uVar19 = *(undefined4 *)(iVar3 + 0x378);
    puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x1c);
    puVar2 = PTR_FUN_001e90bc;
    puVar1 = PTR_FUN_001e9090;
    puVar15 = puVar9 + 1;
    uVar4 = 1;
    *puVar9 = uVar19;
    puVar9[4] = puVar1;
    puVar9[1] = 1;
    iVar23 = 0x20;
    puVar9[5] = puVar2;
    puVar9[6] = uVar19;
    do {
      uVar4 = uVar4 << 1;
      if (0x3ff < uVar4) break;
      iVar23 = iVar23 + -1;
    } while (iVar23 != 0);
    *puVar15 = uVar4;
    puVar9[2] = 0;
    uVar19 = FUN_00193e18(uVar19,*puVar15 << 2);
    puVar9[3] = uVar19;
    _memset(uVar19,0,*puVar15 << 2);
    *(uint **)(iVar3 + 0x3e4) = puVar15;
    iVar3 = *(int *)(param_1 + 8);
    uVar19 = *(undefined4 *)(iVar3 + 0x378);
    puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x1c);
    puVar2 = PTR_FUN_001e90ac;
    puVar1 = PTR_FUN_001e90a8;
    puVar15 = puVar9 + 1;
    uVar4 = 1;
    *puVar9 = uVar19;
    puVar9[4] = puVar2;
    puVar9[1] = 1;
    iVar23 = 0x20;
    puVar9[5] = puVar1;
    puVar9[6] = uVar19;
    do {
      uVar4 = uVar4 << 1;
      if (0x3ff < uVar4) break;
      iVar23 = iVar23 + -1;
    } while (iVar23 != 0);
    *puVar15 = uVar4;
    puVar9[2] = 0;
    uVar19 = FUN_00193e18(uVar19,*puVar15 << 2);
    puVar9[3] = uVar19;
    _memset(uVar19,0,*puVar15 << 2);
    *(uint **)(iVar3 + 1000) = puVar15;
    iVar3 = *(int *)(param_1 + 8);
    uVar19 = *(undefined4 *)(iVar3 + 0x378);
    puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x1c);
    puVar2 = PTR_FUN_001e90b4;
    puVar1 = PTR_FUN_001e90a0;
    puVar15 = puVar9 + 1;
    uVar4 = 1;
    *puVar9 = uVar19;
    puVar9[4] = puVar1;
    puVar9[1] = 1;
    iVar23 = 0x20;
    puVar9[5] = puVar2;
    puVar9[6] = uVar19;
    do {
      uVar4 = uVar4 << 1;
      if (0x3ff < uVar4) break;
      iVar23 = iVar23 + -1;
    } while (iVar23 != 0);
    *puVar15 = uVar4;
    puVar9[2] = 0;
    uVar19 = FUN_00193e18(uVar19,*puVar15 << 2);
    puVar9[3] = uVar19;
    _memset(uVar19,0,*puVar15 << 2);
    *(uint **)(iVar3 + 0x3ec) = puVar15;
    uVar19 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
    puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x2c);
    *puVar9 = uVar19;
    iVar3 = *(int *)(param_1 + 8);
    puVar9[1] = 0x7ffffffe;
    puVar9[5] = 4;
    puVar9[8] = 0;
    puVar9[2] = 0;
    *(undefined1 *)(puVar9 + 3) = 0;
    *(undefined1 *)((int)puVar9 + 0xd) = 0;
    puVar9[4] = 0;
    puVar9[7] = 0;
    *(undefined4 **)(iVar3 + 0x3f0) = puVar9 + 1;
    uVar19 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
    puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x34);
    *puVar9 = uVar19;
    iVar3 = *(int *)(param_1 + 8);
    puVar9[0xc] = 0;
    puVar9[2] = 0;
    puVar9[4] = 0;
    puVar9[5] = 0;
    puVar9[6] = 0;
    puVar9[7] = 0;
    puVar9[9] = 0;
    puVar9[10] = 0;
    puVar9[0xb] = 0;
    puVar9[1] = 0;
    puVar9[3] = 0xffffffff;
    puVar9[8] = 0;
    *(undefined4 **)(iVar3 + 0x3f4) = puVar9 + 1;
    (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0x124))();
    (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0x128))();
    FUN_001762bc(*(undefined4 *)(param_1 + 8));
    FUN_001762c0(*(undefined4 *)(param_1 + 8));
  }
  uVar19 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x14);
  *puVar9 = uVar19;
  puVar9[1] = 2;
  puVar9[4] = uVar19;
  puVar9[2] = 0;
  uVar19 = FUN_00193e18(uVar19,8);
  puVar9[3] = uVar19;
  *(undefined4 **)(param_1 + 0x404) = puVar9 + 1;
  uVar19 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x14);
  *puVar9 = uVar19;
  puVar9[1] = 2;
  puVar9[2] = 0;
  puVar9[4] = uVar19;
  uVar19 = FUN_00193e18(uVar19,8);
  puVar9[3] = uVar19;
  *(undefined4 **)(param_1 + 0x408) = puVar9 + 1;
  uVar19 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x14);
  puVar9[1] = 2;
  *puVar9 = uVar19;
  puVar9[2] = 0;
  puVar9[4] = uVar19;
  uVar19 = FUN_00193e18(uVar19,8);
  puVar9[3] = uVar19;
  *(undefined4 **)(param_1 + 0x40c) = puVar9 + 1;
  uVar19 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x14);
  puVar9[1] = 2;
  *puVar9 = uVar19;
  puVar9[2] = 0;
  puVar9[4] = uVar19;
  uVar19 = FUN_00193e18(uVar19,8);
  puVar9[3] = uVar19;
  *(undefined4 **)(param_1 + 0x410) = puVar9 + 1;
  iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0xc0))();
  if (iVar3 != 0) {
    uVar19 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
    puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x14);
    *puVar9 = uVar19;
    puVar9[1] = 2;
    puVar9[4] = uVar19;
    puVar9[2] = 0;
    uVar19 = FUN_00193e18(uVar19,8);
    puVar9[3] = uVar19;
    *(undefined4 **)(param_1 + 0x41c) = puVar9 + 1;
    uVar19 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
    puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x14);
    *puVar9 = uVar19;
    puVar9[1] = 2;
    puVar9[2] = 0;
    puVar9[4] = uVar19;
    uVar19 = FUN_00193e18(uVar19,8);
    puVar9[3] = uVar19;
    *(undefined4 **)(param_1 + 0x420) = puVar9 + 1;
    uVar19 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
    puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x14);
    puVar9[1] = 2;
    *puVar9 = uVar19;
    puVar9[2] = 0;
    puVar9[4] = uVar19;
    uVar19 = FUN_00193e18(uVar19,8);
    puVar9[3] = uVar19;
    *(undefined4 **)(param_1 + 0x424) = puVar9 + 1;
    uVar19 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
    puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x14);
    puVar9[1] = 2;
    *puVar9 = uVar19;
    puVar9[2] = 0;
    puVar9[4] = uVar19;
    uVar19 = FUN_00193e18(uVar19,8);
    puVar9[3] = uVar19;
    *(undefined4 **)(param_1 + 0x418) = puVar9 + 1;
  }
  iVar3 = -1;
  puVar15 = (uint *)0x0;
  puVar16 = (uint *)0x0;
  puVar17 = (uint *)0x0;
  do {
    if (piVar18[0x3c] != 0) {
      piVar18[0x2f] = *(int *)(piVar18[0x3c] + 0xbc) + 1;
    }
    iVar23 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),7);
    if (iVar23 != 0) {
      uVar19 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
      puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x1c);
      puVar2 = PTR_FUN_001e90c4;
      puVar1 = PTR_FUN_001e90b0;
      puVar15 = puVar9 + 1;
      uVar4 = 1;
      *puVar9 = uVar19;
      puVar9[4] = puVar1;
      puVar9[1] = 1;
      iVar23 = 0x20;
      puVar9[5] = puVar2;
      puVar9[6] = uVar19;
      do {
        uVar4 = uVar4 << 1;
        if (0xff < uVar4) break;
        iVar23 = iVar23 + -1;
      } while (iVar23 != 0);
      *puVar15 = uVar4;
      puVar9[2] = 0;
      uVar19 = FUN_00193e18(uVar19,*puVar15 << 2);
      puVar9[3] = uVar19;
      _memset(uVar19,0,*puVar15 << 2);
      puVar16 = *(uint **)(param_1 + 0x404);
      uVar4 = puVar16[1];
      if (uVar4 < *puVar16) {
        _memset(uVar4 * 4 + puVar16[2],0,4);
        puVar9 = (undefined4 *)(uVar4 * 4 + puVar16[2]);
        puVar16[1] = uVar4 + 1;
      }
      else {
        puVar9 = (undefined4 *)FUN_0019423c(puVar16,uVar4);
      }
      *puVar9 = puVar15;
      uVar19 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
      puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x1c);
      puVar2 = PTR_FUN_001e90c0;
      puVar1 = PTR_FUN_001e9094;
      puVar16 = puVar9 + 1;
      uVar4 = 1;
      *puVar9 = uVar19;
      puVar9[4] = puVar2;
      puVar9[1] = 1;
      iVar23 = 0x20;
      puVar9[5] = puVar1;
      puVar9[6] = uVar19;
      do {
        uVar4 = uVar4 << 1;
        if (0xff < uVar4) break;
        iVar23 = iVar23 + -1;
      } while (iVar23 != 0);
      *puVar16 = uVar4;
      puVar9[2] = 0;
      uVar19 = FUN_00193e18(uVar19,*puVar16 << 2);
      puVar9[3] = uVar19;
      _memset(uVar19,0,*puVar16 << 2);
      puVar17 = *(uint **)(param_1 + 0x408);
      uVar4 = puVar17[1];
      if (uVar4 < *puVar17) {
        _memset(uVar4 * 4 + puVar17[2],0,4);
        puVar9 = (undefined4 *)(uVar4 * 4 + puVar17[2]);
        puVar17[1] = uVar4 + 1;
      }
      else {
        puVar9 = (undefined4 *)FUN_0019423c(puVar17,uVar4);
      }
      *puVar9 = puVar16;
      uVar19 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
      puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x1c);
      puVar2 = PTR_FUN_001e90a4;
      puVar1 = PTR_FUN_001e909c;
      puVar17 = puVar9 + 1;
      uVar4 = 1;
      *puVar9 = uVar19;
      puVar9[4] = puVar1;
      puVar9[1] = 1;
      iVar23 = 0x20;
      puVar9[5] = puVar2;
      puVar9[6] = uVar19;
      do {
        uVar4 = uVar4 << 1;
        if (0xff < uVar4) break;
        iVar23 = iVar23 + -1;
      } while (iVar23 != 0);
      *puVar17 = uVar4;
      puVar9[2] = 0;
      uVar19 = FUN_00193e18(uVar19,*puVar17 << 2);
      puVar9[3] = uVar19;
      _memset(uVar19,0,*puVar17 << 2);
      puVar21 = *(uint **)(param_1 + 0x40c);
      uVar4 = puVar21[1];
      if (uVar4 < *puVar21) {
        _memset(uVar4 * 4 + puVar21[2],0,4);
        puVar9 = (undefined4 *)(uVar4 * 4 + puVar21[2]);
        puVar21[1] = uVar4 + 1;
      }
      else {
        puVar9 = (undefined4 *)FUN_0019423c(puVar21,uVar4);
      }
      *puVar9 = puVar17;
      uVar19 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
      puVar10 = (undefined4 *)FUN_00193e18(uVar19,0x20c);
      puVar10[1] = 0x80;
      iVar23 = 0x80;
      *puVar10 = uVar19;
      puVar10[2] = 0x1000;
      puVar9 = puVar10 + 1;
      do {
        puVar9[2] = 0;
        puVar9 = puVar9 + 1;
        iVar23 = iVar23 + -1;
      } while (iVar23 != 0);
      piVar18[0x4a] = (int)(puVar10 + 1);
      puVar21 = *(uint **)(param_1 + 0x410);
      uVar4 = puVar21[1];
      if (uVar4 < *puVar21) {
        _memset(uVar4 * 4 + puVar21[2],0,4);
        puVar9 = (undefined4 *)(uVar4 * 4 + puVar21[2]);
        puVar21[1] = uVar4 + 1;
      }
      else {
        puVar9 = (undefined4 *)FUN_0019423c(puVar21,uVar4);
      }
      *puVar9 = piVar18;
      iVar3 = iVar3 + 1;
    }
    piVar6 = (int *)((int *)piVar18[0x26])[2];
    piVar11 = piVar18;
    piVar8 = (int *)piVar18[0x26];
    if (piVar6 != (int *)0x0) {
LAB_00122000:
      piVar7 = piVar6;
      if ((piVar8[5] & 1U) == 0) break;
      iVar23 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),7);
      if (iVar23 != 0) {
        piVar18[0x47] = (int)puVar15;
        piVar18[0x48] = (int)puVar16;
        piVar18[0x49] = (int)puVar17;
      }
      iVar23 = (**(code **)(*piVar8 + 0x34))(piVar8);
      if ((iVar23 != 0) || (iVar23 = (**(code **)(*piVar8 + 0x38))(piVar8), iVar23 != 0)) {
LAB_001227a8:
        piVar7 = (int *)piVar8[2];
        break;
      }
      iVar23 = (**(code **)(*piVar8 + 0x28))(piVar8);
      if (iVar23 != 0) {
        *(uint *)(piVar8[0x56] + 0xc) = *(uint *)(piVar8[0x56] + 0xc) | 1;
        *(uint *)(piVar8[0x56] + 0xc) = *(uint *)(piVar8[0x56] + 0xc) | 2;
      }
      uVar19 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
      puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x240);
      *puVar9 = uVar19;
      puVar9 = puVar9 + 1;
      FUN_00173938(puVar9,piVar8,*(undefined4 *)(param_1 + 8));
      piVar6 = (int *)piVar8[0x23];
      local_68 = puVar9;
      if (piVar6 != (int *)0x0) {
        iVar12 = piVar8[0x26];
        iVar23 = FUN_00126760(iVar12);
        if (iVar23 != 0) {
          if ((piVar6[9] & 2U) == 0) {
            iVar23 = (**(code **)(*piVar6 + 0x18))(piVar6);
            if (iVar23 != 0) {
              piVar8[0x26] = 0;
              piVar8[0x25] = piVar8[0x53];
            }
          }
          else {
            iVar23 = piVar6[4];
            piVar8[0x26] = 0;
            piVar8[0x25] = iVar23;
            piVar8[5] = piVar8[5] | 0x40;
          }
        }
        if (iVar12 == 0x21) {
          *(uint *)(piVar8[0x56] + 0xc) = *(uint *)(piVar8[0x56] + 0xc) | 4;
        }
        else if (iVar12 == 0x30) {
          *(uint *)(piVar8[0x56] + 0xc) = *(uint *)(piVar8[0x56] + 0xc) | 0x10;
        }
      }
      if (*(int *)(piVar8[0x22] + 8) == 0x8e) {
        iVar23 = (**(code **)(*piVar8 + 0x7c))(piVar8);
        *(undefined4 **)(iVar23 + 0x130) = local_68;
        piVar8[0x54] = *(int *)(param_1 + 0x474);
        iVar23 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),7);
        if ((iVar23 != 0) && (*(int *)(param_1 + 0x14c) < *(int *)(*(int *)(param_1 + 8) + 0x654)))
        {
          uVar19 = (**(code **)(*piVar8 + 0x7c))(piVar8);
          iVar23 = ((int (*)())FUN_0011e7ec)(uVar19);
          if (iVar23 != 0) {
            iVar23 = FUN_00105594(piVar8,1);
            puVar21 = *(uint **)(*(int *)(iVar23 + 0x8c) + 0x2c);
            uVar20 = puVar21[1];
            uVar4 = uVar20 - 1;
            if (uVar4 < *puVar21) {
              if (uVar20 <= uVar4) {
                _memset(uVar20 * 4 + puVar21[2],0,(uVar4 - uVar20) * 4 + 4);
                puVar21[1] = uVar20;
              }
              puVar9 = (undefined4 *)(uVar4 * 4 + puVar21[2]);
            }
            else {
              puVar9 = (undefined4 *)FUN_0019423c(puVar21,uVar4);
            }
            FUN_000e9c00(piVar18,piVar8[0x23],*puVar9);
            (**(code **)(*piVar8 + 0xc))(piVar8,0,*(undefined4 *)(param_1 + 8));
            piVar8[5] = piVar8[5] | 0x400;
            *(int *)(param_1 + 0x150) = *(int *)(param_1 + 0x150) + 1;
            piVar7 = (int *)piVar8[2];
            break;
          }
          iVar23 = FUN_00175dac(param_1,iVar3,iVar3,&local_68,piVar18);
          if (iVar23 != 0) goto LAB_001227a8;
        }
LAB_00122704:
        iVar23 = piVar8[0x20];
        if (0 < iVar23) {
          iVar12 = 0;
          piVar6 = piVar8;
          do {
            FUN_000e9c00(piVar18,piVar6[0x23],local_68);
            iVar23 = piVar8[0x20];
            iVar12 = iVar12 + 1;
            piVar6 = piVar6 + 6;
          } while (iVar12 < iVar23);
        }
        if (((iVar23 != 0) && (iVar23 = FUN_00126760(piVar8[0x26]), iVar23 != 0)) &&
           (((piVar8[5] & 2U) == 0 &&
            ((iVar23 = (**(code **)(*piVar8 + 0x50))(piVar8), iVar23 == 0 &&
             ((piVar8[5] & 0x40U) == 0)))))) {
          iVar12 = piVar8[0x53];
          iVar23 = FUN_001054ec(piVar8,0);
          *(int *)(iVar23 + 8) = iVar12;
          piVar7 = (int *)piVar8[2];
          break;
        }
        goto LAB_001227a8;
      }
      iVar23 = ((int (*)())FUN_0011f2f8)(param_1,piVar8,piVar18);
      if (iVar23 != 0) goto LAB_001227a8;
      ((int (*)())FUN_0011e988)(local_68,*(undefined4 *)(param_1 + 0x3a0));
      ((int (*)())FUN_0011eec8)(local_68,param_1);
      iVar23 = FUN_00175dac(param_1,iVar3,0,&local_68,piVar18);
      if (iVar23 != 0) goto LAB_001227a8;
      iVar23 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0xc0))();
      if (iVar23 != 0) {
        FUN_00110020(param_1,local_68);
      }
      iVar23 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),7);
      if ((((iVar23 == 0) || (iVar23 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),9), iVar23 == 0))
          || (iVar23 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0xd), iVar23 == 0)) ||
         ((iVar23 = (**(code **)(*piVar18 + 0x24))(piVar18), iVar23 == 0 || (piVar18[0x53] == 0))))
      {
        if (0 < piVar8[0x21]) {
          iVar23 = 1;
          piVar6 = piVar8;
          do {
            FUN_00106004(piVar8,iVar23,local_68[iVar23 + 0x84],0,*(undefined4 *)(param_1 + 8));
            iVar12 = FUN_001054ec(piVar8,iVar23);
            piVar6[0x29] = 0;
            *(undefined4 *)(iVar12 + 0xc) = 0x46;
            *(undefined4 *)(iVar12 + 8) = 0xffffffff;
            iVar12 = (**(code **)(*(int *)local_68[iVar23 + 0x84] + 0x74))();
            if (iVar12 != 0) {
              *(undefined4 *)(param_1 + 0x334) = 1;
            }
            iVar23 = iVar23 + 1;
            piVar6 = piVar6 + 6;
          } while (iVar23 <= piVar8[0x21]);
        }
        goto LAB_00122704;
      }
      iVar12 = piVar18[0x4f];
      piVar11 = (int *)FUN_000e7e90(piVar18);
      iVar23 = FUN_000e7f38(iVar12);
      FUN_0012df90(param_1,piVar18,iVar12,&local_64,&local_60);
      FUN_000e7a24(piVar18);
      if (puVar16 != (uint *)0x0) {
        uVar4 = *puVar16;
        if (uVar4 == 0) {
          uVar20 = puVar16[2];
        }
        else {
          uVar20 = puVar16[2];
          uVar22 = 0;
          do {
            iVar12 = *(int *)(uVar22 * 4 + uVar20);
            if (iVar12 != 0) {
              FUN_00193cc0(puVar16[5],iVar12);
              uVar4 = *puVar16;
              uVar20 = puVar16[2];
            }
            uVar22 = uVar22 + 1;
          } while (uVar22 < uVar4);
        }
        FUN_00193cc0(puVar16[5],uVar20);
        FUN_00193cc0(puVar16[-1],puVar16 + -1);
      }
      piVar18[0x48] = 0;
      if (puVar17 != (uint *)0x0) {
        uVar4 = *puVar17;
        if (uVar4 == 0) {
          uVar20 = puVar17[2];
        }
        else {
          uVar20 = puVar17[2];
          uVar22 = 0;
          do {
            iVar12 = *(int *)(uVar22 * 4 + uVar20);
            if (iVar12 != 0) {
              FUN_00193cc0(puVar17[5],iVar12);
              uVar4 = *puVar17;
              uVar20 = puVar17[2];
            }
            uVar22 = uVar22 + 1;
          } while (uVar22 < uVar4);
        }
        FUN_00193cc0(puVar17[5],uVar20);
        FUN_00193cc0(puVar17[-1],puVar17 + -1);
      }
      piVar18[0x49] = 0;
      if (puVar15 != (uint *)0x0) {
        uVar4 = *puVar15;
        if (uVar4 == 0) {
          uVar20 = puVar15[2];
        }
        else {
          uVar20 = puVar15[2];
          uVar22 = 0;
          do {
            iVar12 = *(int *)(uVar22 * 4 + uVar20);
            if (iVar12 != 0) {
              FUN_00193cc0(puVar15[5],iVar12);
              uVar4 = *puVar15;
              uVar20 = puVar15[2];
            }
            uVar22 = uVar22 + 1;
          } while (uVar22 < uVar4);
        }
        FUN_00193cc0(puVar15[5],uVar20);
        FUN_00193cc0(puVar15[-1],puVar15 + -1);
      }
      piVar18[0x47] = 0;
      FUN_00194208(*(undefined4 *)(param_1 + 0x404),iVar3);
      FUN_00194208(*(undefined4 *)(param_1 + 0x408),iVar3);
      FUN_00194208(*(undefined4 *)(param_1 + 0x40c),iVar3);
      FUN_00194208(*(undefined4 *)(param_1 + 0x410),iVar3);
      iVar3 = iVar3 + -1;
      piVar18 = (int *)piVar11[0x3d];
      *(int **)(local_64 + 0xf0) = piVar11;
      if (*piVar18 == 0) {
        piVar18 = (int *)FUN_0019423c(piVar18,0);
      }
      else {
        if (piVar18[1] == 0) {
          *(undefined4 *)piVar18[2] = 0;
          piVar18[1] = 1;
        }
        piVar18 = (int *)piVar18[2];
      }
      *piVar18 = local_64;
      piVar18 = *(int **)(local_60 + 0xf4);
      if (*piVar18 == 0) {
        piVar18 = (int *)FUN_0019423c(piVar18,0);
      }
      else {
        if (piVar18[1] == 0) {
          *(undefined4 *)piVar18[2] = 0;
          piVar18[1] = 1;
        }
        piVar18 = (int *)piVar18[2];
      }
      *piVar18 = iVar23;
      *(int *)(iVar23 + 0xf0) = local_60;
    }
LAB_001227bc:
    iVar23 = 0;
    local_60 = 0;
    for (uVar4 = 1; uVar4 <= *(uint *)(piVar11[0x34] + 4); uVar4 = uVar4 + 1) {
      local_60 = *(int *)(iVar23 + *(int *)(piVar11[0x34] + 8));
      if (local_60 != 0) {
        iVar12 = FUN_000e8098(local_60,piVar11);
        piVar18 = (int *)(*(int **)(local_60 + 0x98))[2];
        if (piVar18 != (int *)0x0) {
          piVar6 = *(int **)(local_60 + 0x98);
          do {
            piVar8 = piVar18;
            if ((piVar6[5] & 1U) != 0) {
              piVar18 = (int *)(**(code **)(*piVar6 + 0x7c))(piVar6);
              if (piVar18 != (int *)0x0) {
                iVar13 = ((int (*)())FUN_00122fa4)(piVar18[0x23],*(undefined4 *)(param_1 + 0x3a0),
                                      *(undefined4 *)(param_1 + 8));
                FUN_00106004(piVar18,iVar12,*(undefined4 *)(iVar13 + 0xb0),0,
                             *(undefined4 *)(param_1 + 8));
                iVar5 = piVar18[0x4e];
                iVar14 = 0;
                iVar24 = 4;
                do {
                  *(undefined4 *)(iVar14 + *(int *)(iVar12 * 4 + iVar5)) =
                       *(undefined4 *)(iVar14 + iVar13 + 0x20);
                  iVar14 = iVar14 + 4;
                  iVar24 = iVar24 + -1;
                } while (iVar24 != 0);
                if ((((piVar18[0x20] != 0) && (iVar5 = FUN_00126760(piVar18[0x26]), iVar5 != 0)) &&
                    ((piVar18[5] & 2U) == 0)) &&
                   ((iVar5 = (**(code **)(*piVar18 + 0x50))(piVar18), iVar5 == 0 &&
                    ((piVar18[5] & 0x40U) == 0)))) {
                  iVar13 = piVar18[0x53];
                  iVar5 = FUN_001054ec(piVar18,0);
                  *(int *)(iVar5 + 8) = iVar13;
                  piVar8 = (int *)piVar6[2];
                  goto LAB_001228ec;
                }
              }
              piVar8 = (int *)piVar6[2];
            }
LAB_001228ec:
            piVar18 = (int *)piVar8[2];
            piVar6 = piVar8;
          } while ((int *)piVar8[2] != (int *)0x0);
        }
      }
      iVar23 = iVar23 + 4;
    }
    iVar23 = FUN_000e7a10(piVar11);
    if (iVar23 == 0) {
      FUN_000e7a24(piVar11);
      iVar23 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),7);
      if (iVar23 != 0) {
        if (puVar17 != (uint *)0x0) {
          uVar4 = *puVar17;
          if (uVar4 == 0) {
            uVar20 = puVar17[2];
          }
          else {
            uVar20 = puVar17[2];
            uVar22 = 0;
            do {
              iVar23 = *(int *)(uVar22 * 4 + uVar20);
              if (iVar23 != 0) {
                FUN_00193cc0(puVar17[5],iVar23);
                uVar4 = *puVar17;
                uVar20 = puVar17[2];
              }
              uVar22 = uVar22 + 1;
            } while (uVar22 < uVar4);
          }
          FUN_00193cc0(puVar17[5],uVar20);
          FUN_00193cc0(puVar17[-1],puVar17 + -1);
        }
        piVar11[0x49] = 0;
        if (puVar16 != (uint *)0x0) {
          uVar4 = *puVar16;
          if (uVar4 == 0) {
            uVar20 = puVar16[2];
          }
          else {
            uVar20 = puVar16[2];
            uVar22 = 0;
            do {
              iVar23 = *(int *)(uVar22 * 4 + uVar20);
              if (iVar23 != 0) {
                FUN_00193cc0(puVar16[5],iVar23);
                uVar4 = *puVar16;
                uVar20 = puVar16[2];
              }
              uVar22 = uVar22 + 1;
            } while (uVar22 < uVar4);
          }
          FUN_00193cc0(puVar16[5],uVar20);
          FUN_00193cc0(puVar16[-1],puVar16 + -1);
        }
        piVar11[0x48] = 0;
        if (puVar15 != (uint *)0x0) {
          uVar4 = *puVar15;
          if (uVar4 == 0) {
            uVar20 = puVar15[2];
          }
          else {
            uVar20 = puVar15[2];
            uVar22 = 0;
            do {
              iVar23 = *(int *)(uVar22 * 4 + uVar20);
              if (iVar23 != 0) {
                FUN_00193cc0(puVar15[5],iVar23);
                uVar4 = *puVar15;
                uVar20 = puVar15[2];
              }
              uVar22 = uVar22 + 1;
            } while (uVar22 < uVar4);
          }
          FUN_00193cc0(puVar15[5],uVar20);
          FUN_00193cc0(puVar15[-1],puVar15 + -1);
        }
        piVar11[0x47] = 0;
        FUN_00194208(*(undefined4 *)(param_1 + 0x404),iVar3);
        FUN_00194208(*(undefined4 *)(param_1 + 0x408),iVar3);
        FUN_00194208(*(undefined4 *)(param_1 + 0x40c),iVar3);
        FUN_00194208(*(undefined4 *)(param_1 + 0x410),iVar3);
        iVar3 = iVar3 + -1;
      }
      iVar23 = piVar11[0x3c];
      uVar4 = local_58 - 1;
      puVar9 = (undefined4 *)0x0;
      if (uVar4 < local_58) {
        puVar9 = (undefined4 *)(uVar4 * 4 + local_54);
      }
      piVar18 = (int *)*puVar9;
      FUN_00194208(&local_5c,uVar4);
      while ((iVar23 != 0 && (iVar23 != piVar18[0x3c]))) {
        FUN_000e7a24(iVar23);
        iVar23 = *(int *)(iVar23 + 0xf0);
        iVar12 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),7);
        if (iVar12 != 0) {
          FUN_00194208(*(undefined4 *)(param_1 + 0x404),iVar3);
          FUN_00194208(*(undefined4 *)(param_1 + 0x408),iVar3);
          FUN_00194208(*(undefined4 *)(param_1 + 0x40c),iVar3);
          FUN_00194208(*(undefined4 *)(param_1 + 0x410),iVar3);
          iVar3 = iVar3 + -1;
        }
      }
    }
    else {
      iVar23 = piVar11[0x3d];
      puVar9 = (undefined4 *)0x0;
      if (*(uint *)(iVar23 + 4) != 0) {
        puVar9 = *(undefined4 **)(iVar23 + 8);
      }
      piVar18 = (int *)*puVar9;
      if (1 < *(uint *)(iVar23 + 4)) {
        uVar4 = 1;
        do {
          uVar20 = local_58;
          uVar19 = *(undefined4 *)(uVar4 * 4 + *(int *)(iVar23 + 8));
          if (local_58 < local_5c) {
            iVar12 = local_58 * 4;
            _memset(iVar12 + local_54,0,4);
            local_58 = uVar20 + 1;
            puVar9 = (undefined4 *)(iVar12 + local_54);
          }
          else {
            puVar9 = (undefined4 *)FUN_0019423c(&local_5c,local_58);
          }
          *puVar9 = uVar19;
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint *)(iVar23 + 4));
      }
    }
    if (local_58 == 0) {
      iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0xc0))();
      if (iVar3 != 0) {
        FUN_0010f87c(param_1,2,*(undefined4 *)(param_1 + 0x420));
        iVar3 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x3f);
        if (iVar3 != 0) {
          FUN_001102e0(param_1,1,*(undefined4 *)(param_1 + 0x41c));
          iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 200))();
          if (iVar3 != 0) {
            FUN_001102e0(param_1,2,*(undefined4 *)(param_1 + 0x420));
          }
        }
      }
      iVar3 = *(int *)(param_1 + 0x404);
      if (iVar3 != 0) {
        FUN_00193cc0(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8));
        FUN_00193cc0(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
      }
      iVar3 = *(int *)(param_1 + 0x408);
      if (iVar3 != 0) {
        FUN_00193cc0(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8));
        FUN_00193cc0(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
      }
      iVar3 = *(int *)(param_1 + 0x40c);
      if (iVar3 != 0) {
        FUN_00193cc0(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8));
        FUN_00193cc0(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
      }
      iVar3 = *(int *)(param_1 + 0x410);
      if (iVar3 != 0) {
        FUN_00193cc0(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8));
        FUN_00193cc0(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
      }
      FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x378),
                   *(undefined4 *)(*(int *)(param_1 + 8) + 0x3d8));
      iVar3 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),7);
      if ((iVar3 != 0) && (iVar3 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),9), iVar3 != 0)) {
        FUN_00172fb0(*(undefined4 *)(param_1 + 8));
        FUN_00172fb4(*(undefined4 *)(param_1 + 8));
      }
      *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0xc;
      FUN_000ed7e4(param_1,"ssa_build");
      FUN_00193cc0(local_50,local_54);
      return;
    }
  } while( true );
  piVar6 = (int *)piVar7[2];
  piVar8 = piVar7;
  if ((int *)piVar7[2] == (int *)0x0) goto LAB_001227bc;
  goto LAB_00122000;
}

/* FUN_00122de8 @ 0x122de8 (168 bytes) */
int FUN_00122de8(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  
  FUN_0012b520(param_1);
  FUN_000f88b4(param_1);
  ((int (*)())FUN_0011eaa0)(param_1);
  ((int (*)())FUN_001214fc)(param_1);
  iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0xe);
  if (iVar2 != 0) {
    ((int (*)())FUN_0011f578)(param_1);
    ((int (*)())FUN_00121000)(param_1);
  }
  FUN_000ec8e4(param_1);
  piVar1 = *(int **)(param_1 + 0x3b0);
  iVar2 = *piVar1;
  if (iVar2 != 0) {
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    do {
      piVar1[2] = 0;
      piVar1 = piVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_000f019c(param_1);
  return;
}

/* FUN_00122e90 @ 0x122e90 (44 bytes) */
int FUN_00122e90(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  
                    
                    
  uVar1 = (**(code **)(PTR_PTR_001e8c60 + param_2 * 0x10 + 0xc))(param_1,param_2,param_3,param_4);
  return uVar1;
}

/* FUN_00122ebc @ 0x122ebc (28 bytes) */
int FUN_00122ebc(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x2c) + 4);
  *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
  FUN_00194208(*(int *)(param_1 + 0x2c),iVar1 + -1);
  return;
}

/* FUN_00122ed8 @ 0x122ed8 (80 bytes) */
int FUN_00122ed8(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack0000001c;
  
  uStack0000001c = param_2;
  if (*(int *)(*(int *)(param_1 + 0x30) + 0x98) != 8) {
    iVar2 = 0;
    iVar3 = 4;
    pcVar1 = (char *)&STACKARG(0x1c);
    do {
      if (*pcVar1 == '\0') {
        *(undefined1 *)(iVar2 + *(int *)(param_1 + 0x30) + 0x9c) = 0;
      }
      iVar2 = iVar2 + 1;
      pcVar1 = pcVar1 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return *(undefined4 *)(param_1 + 0x34);
}

/* FUN_00122f28 @ 0x122f28 (124 bytes) */
int FUN_00122f28(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  if ((param_1[9] & 2U) == 0) {
    iVar1 = (**(code **)(*param_1 + 0x18))();
    if (iVar1 != 0) {
      *(undefined4 *)(param_2 + 0x98) = 0;
      *(undefined4 *)(param_2 + 0x94) = *(undefined4 *)(param_2 + 0x14c);
    }
  }
  else {
    iVar1 = param_1[4];
    iVar2 = param_1[1];
    *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x40;
    *(int *)(param_2 + 0x94) = iVar1;
    *(int *)(param_2 + 0x98) = iVar2;
  }
  return;
}

/* FUN_00122fa4 @ 0x122fa4 (200 bytes) */
int FUN_00122fa4(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 uVar5;
  
  puVar3 = (uint *)param_1[0xb];
  uVar4 = puVar3[1];
  if (uVar4 == 0) {
    uVar5 = (**(code **)(*param_1 + 8))(param_1,param_2,param_3);
    FUN_000e9c00(param_2,param_1,uVar5);
  }
  else {
    uVar2 = uVar4 - 1;
    if (uVar2 < *puVar3) {
      if (uVar4 <= uVar2) {
        _memset(uVar4 * 4 + puVar3[2],0,(uVar2 - uVar4) * 4 + 4);
        puVar3[1] = uVar4;
      }
      puVar1 = (undefined4 *)(uVar2 * 4 + puVar3[2]);
    }
    else {
      puVar1 = (undefined4 *)FUN_0019423c(puVar3,uVar2);
    }
    uVar5 = *puVar1;
  }
  return uVar5;
}

/* FUN_0012306c @ 0x12306c (120 bytes) */
int FUN_0012306c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(param_1 + 0x18);
  uVar2 = puVar3[1];
  if (uVar2 < *puVar3) {
    _memset(uVar2 * 4 + puVar3[2],0,4);
    puVar1 = (undefined4 *)(uVar2 * 4 + puVar3[2]);
    puVar3[1] = uVar2 + 1;
  }
  else {
    puVar1 = (undefined4 *)FUN_0019423c(puVar3,uVar2);
  }
  *puVar1 = param_2;
  return;
}

/* FUN_001230e4 @ 0x1230e4 (268 bytes) */
int FUN_001230e4(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  
  uVar7 = *(undefined4 *)(param_3 + 0x374);
  piVar6 = *(int **)(*(int *)(*(int *)(param_3 + 0x6c4) + 0x354) + 300);
  puVar2 = (undefined4 *)FUN_00193e18(uVar7,0x168);
  puVar8 = puVar2 + 1;
  *puVar2 = uVar7;
  FUN_00109938(puVar8,param_3);
  iVar4 = *piVar6;
  iVar9 = 4;
  uVar5 = 0;
  puVar3 = puVar8;
  do {
    *(byte *)(puVar2 + 0x58) = (byte)(1 << (uVar5 & 0x3f)) | *(byte *)(puVar2 + 0x58);
    puVar3[7] = 3;
    iVar1 = *(int *)(param_1 + 8) * 4 + uVar5;
    if (iVar4 < iVar1) {
      puVar3[8] = 0;
    }
    else {
      puVar3[8] = piVar6[iVar1 + 1];
    }
    uVar5 = uVar5 + 1;
    puVar3 = puVar3 + 6;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  FUN_001046c8(puVar8,0,param_1);
  uVar7 = *(undefined4 *)(param_3 + 0x378);
  puVar3 = (undefined4 *)FUN_00193e18(uVar7,0x240);
  puVar2 = puVar3 + 1;
  *puVar3 = uVar7;
  FUN_00173938(puVar2,puVar8,param_3);
  iVar4 = FUN_000e07dc(param_3,7);
  if (iVar4 != 0) {
    FUN_00174e0c(puVar2);
    FUN_00173278(puVar2);
  }
  ((int (*)())FUN_0012306c)(param_1,puVar8);
  (**(code **)(*param_2 + 0xc))(param_2,puVar8);
  ((int (*)())FUN_00122f28)(param_1,puVar8);
  return puVar2;
}

/* FUN_00123288 @ 0x123288 (148 bytes) */
int FUN_00123288(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_00109810(0xa4,param_3);
  FUN_001046c8(iVar1,0,param_1);
  *(undefined4 *)(iVar1 + 0x9c) = DAT_001afee8;
  *(undefined4 *)(iVar1 + 300) = *(undefined4 *)(param_1 + 8);
  uVar5 = *(undefined4 *)(param_3 + 0x378);
  puVar2 = (undefined4 *)FUN_00193e18(uVar5,0x240);
  puVar4 = puVar2 + 1;
  *puVar2 = uVar5;
  FUN_00173938(puVar4,iVar1,param_3);
  iVar3 = FUN_000e07dc(param_3,7);
  if (iVar3 != 0) {
    FUN_00174e0c(puVar4);
    FUN_00173278(puVar4);
  }
  ((int (*)())FUN_0012306c)(param_1,iVar1);
  (**(code **)(*param_2 + 0xc))(param_2,iVar1);
  ((int (*)())FUN_00122f28)(param_1,iVar1);
  return puVar4;
}

/* FUN_00123398 @ 0x123398 (140 bytes) */
int FUN_00123398(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = *(uint **)(param_1 + 0x2c);
  uVar2 = puVar4[1];
  uVar3 = uVar2 - 1;
  if (uVar3 < *puVar4) {
    if (uVar2 <= uVar3) {
      _memset(uVar2 * 4 + puVar4[2],0,(uVar3 - uVar2) * 4 + 4);
      puVar4[1] = uVar2;
    }
    puVar1 = (undefined4 *)(uVar3 * 4 + puVar4[2]);
  }
  else {
    puVar1 = (undefined4 *)FUN_0019423c(puVar4,uVar3);
  }
  *puVar1 = param_2;
  return;
}

/* FUN_00123424 @ 0x123424 (180 bytes) */
int FUN_00123424(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(param_1 + 0x2c);
  if ((puVar3[1] != 0) && (param_2 == *(int *)(param_1 + 0x28))) {
    ((int (*)())FUN_00123398)(param_1,param_3);
    return;
  }
  *(int *)(param_1 + 0x28) = param_2;
  uVar2 = puVar3[1];
  if (uVar2 < *puVar3) {
    _memset(uVar2 * 4 + puVar3[2],0,4);
    puVar1 = (undefined4 *)(uVar2 * 4 + puVar3[2]);
    puVar3[1] = uVar2 + 1;
  }
  else {
    puVar1 = (undefined4 *)FUN_0019423c(puVar3,uVar2);
  }
  *puVar1 = param_3;
  return;
}

/* FUN_001234d8 @ 0x1234d8 (224 bytes) */
int FUN_001234d8(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  
  uVar1 = (*(uint **)(param_1 + 0x14))[1];
  if (uVar1 != 0) {
    uVar3 = 0;
    puVar4 = *(uint **)(param_1 + 0x14);
    do {
      if (uVar3 < *puVar4) {
        puVar5 = puVar4;
        if (uVar1 <= uVar3) {
          _memset(uVar1 * 4 + puVar4[2],0,(uVar3 - uVar1) * 4 + 4);
          puVar4[1] = uVar3 + 1;
          puVar5 = *(uint **)(param_1 + 0x14);
        }
        piVar2 = (int *)(uVar3 * 4 + puVar4[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar4,uVar3);
        puVar5 = *(uint **)(param_1 + 0x14);
      }
      if (*piVar2 == param_2) {
        FUN_00194208(puVar5,uVar3);
        return;
      }
      uVar1 = puVar5[1];
      uVar3 = uVar3 + 1;
      puVar4 = puVar5;
    } while (uVar3 < uVar1);
  }
  return;
}

/* FUN_001235b8 @ 0x1235b8 (300 bytes) */
int FUN_001235b8(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  uVar1 = (*(uint **)(param_1 + 0x14))[1];
  if (uVar1 != 0) {
    uVar4 = 0;
    puVar5 = *(uint **)(param_1 + 0x14);
    do {
      if (uVar4 < *puVar5) {
        puVar6 = puVar5;
        if (uVar1 <= uVar4) {
          _memset(uVar1 * 4 + puVar5[2],0,(uVar4 - uVar1) * 4 + 4);
          puVar5[1] = uVar4 + 1;
          puVar6 = *(uint **)(param_1 + 0x14);
        }
        piVar2 = (int *)(uVar4 * 4 + puVar5[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar5,uVar4);
        puVar6 = *(uint **)(param_1 + 0x14);
      }
      if (*piVar2 == param_2) {
        if (uVar4 < *puVar6) {
          uVar1 = puVar6[1];
          if (uVar1 <= uVar4) {
            _memset(uVar1 * 4 + puVar6[2],0,(uVar4 - uVar1) * 4 + 4);
            puVar6[1] = uVar4 + 1;
          }
          puVar3 = (undefined4 *)(uVar4 * 4 + puVar6[2]);
        }
        else {
          puVar3 = (undefined4 *)FUN_0019423c(puVar6,uVar4);
        }
        *puVar3 = param_3;
        return;
      }
      uVar1 = puVar6[1];
      uVar4 = uVar4 + 1;
      puVar5 = puVar6;
    } while (uVar4 < uVar1);
  }
  return;
}

/* FUN_001236e4 @ 0x1236e4 (184 bytes) */
int FUN_001236e4(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  if (param_2 < 2) {
LAB_00123718:
    puVar5 = *(uint **)(param_1 + 0x14);
    uVar4 = puVar5[1];
    if (uVar4 < *puVar5) {
      _memset(uVar4 * 4 + puVar5[2],0,4);
      piVar2 = (int *)(uVar4 * 4 + puVar5[2]);
      puVar5[1] = uVar4 + 1;
    }
    else {
      piVar2 = (int *)FUN_0019423c(puVar5,uVar4);
    }
    *piVar2 = param_3;
  }
  else if (param_1 != *(int *)(param_3 + 0xa4)) {
    iVar3 = param_2 + -1;
    iVar1 = param_3;
    do {
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) goto LAB_00123718;
      piVar2 = (int *)(iVar1 + 0xbc);
      iVar1 = iVar1 + 0x18;
    } while (param_1 != *piVar2);
  }
  return;
}

/* FUN_0012379c @ 0x12379c (296 bytes) */
int FUN_0012379c(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  param_1[2] = param_2;
  puVar1 = PTR_DAT_001e90f0;
  param_1[1] = param_3;
  param_1[3] = param_4;
  *param_1 = puVar1 + 8;
  param_1[4] = 0xffffffff;
  param_1[7] = 0xffffffff;
  iVar2 = *(int *)(param_5 + 0x348);
  param_1[8] = iVar2;
  *(int *)(param_5 + 0x348) = iVar2 + 1;
  param_1[10] = 0xffffffff;
  param_1[9] = 0;
  uVar4 = *(undefined4 *)(param_5 + 0x374);
  puVar3 = (undefined4 *)FUN_00193e18(uVar4,0x14);
  *puVar3 = uVar4;
  puVar3[1] = 2;
  puVar3[4] = uVar4;
  puVar3[2] = 0;
  uVar4 = FUN_00193e18(uVar4,8);
  puVar3[3] = uVar4;
  param_1[5] = puVar3 + 1;
  uVar4 = *(undefined4 *)(param_5 + 0x374);
  puVar3 = (undefined4 *)FUN_00193e18(uVar4,0x14);
  *puVar3 = uVar4;
  puVar3[1] = 2;
  puVar3[4] = uVar4;
  puVar3[2] = 0;
  uVar4 = FUN_00193e18(uVar4,8);
  puVar3[3] = uVar4;
  param_1[6] = puVar3 + 1;
  uVar4 = *(undefined4 *)(param_5 + 0x374);
  puVar3 = (undefined4 *)FUN_00193e18(uVar4,0x14);
  *puVar3 = uVar4;
  puVar3[1] = 2;
  puVar3[2] = 0;
  puVar3[4] = uVar4;
  uVar4 = FUN_00193e18(uVar4,8);
  puVar3[3] = uVar4;
  param_1[0xb] = puVar3 + 1;
  return;
}

/* FUN_001238e8 @ 0x1238e8 (296 bytes) */
int FUN_001238e8(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  param_1[2] = param_2;
  puVar1 = PTR_DAT_001e90f0;
  param_1[1] = param_3;
  param_1[3] = param_4;
  *param_1 = puVar1 + 8;
  param_1[4] = 0xffffffff;
  param_1[7] = 0xffffffff;
  iVar2 = *(int *)(param_5 + 0x348);
  param_1[8] = iVar2;
  *(int *)(param_5 + 0x348) = iVar2 + 1;
  param_1[10] = 0xffffffff;
  param_1[9] = 0;
  uVar4 = *(undefined4 *)(param_5 + 0x374);
  puVar3 = (undefined4 *)FUN_00193e18(uVar4,0x14);
  *puVar3 = uVar4;
  puVar3[1] = 2;
  puVar3[4] = uVar4;
  puVar3[2] = 0;
  uVar4 = FUN_00193e18(uVar4,8);
  puVar3[3] = uVar4;
  param_1[5] = puVar3 + 1;
  uVar4 = *(undefined4 *)(param_5 + 0x374);
  puVar3 = (undefined4 *)FUN_00193e18(uVar4,0x14);
  *puVar3 = uVar4;
  puVar3[1] = 2;
  puVar3[4] = uVar4;
  puVar3[2] = 0;
  uVar4 = FUN_00193e18(uVar4,8);
  puVar3[3] = uVar4;
  param_1[6] = puVar3 + 1;
  uVar4 = *(undefined4 *)(param_5 + 0x374);
  puVar3 = (undefined4 *)FUN_00193e18(uVar4,0x14);
  *puVar3 = uVar4;
  puVar3[1] = 2;
  puVar3[2] = 0;
  puVar3[4] = uVar4;
  uVar4 = FUN_00193e18(uVar4,8);
  puVar3[3] = uVar4;
  param_1[0xb] = puVar3 + 1;
  return;
}

/* FUN_00123a34 @ 0x123a34 (296 bytes) */
int FUN_00123a34(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 uStack0000001c;
  
  uStack0000001c = param_2;
  if ((*(uint *)(param_3 + 0x30) & 0x4000) == 0) {
    if (*(int *)(param_1 + 0x30) == 0) {
      iVar3 = *(int *)(param_1 + 0x3c);
      if (*(int *)(param_1 + 0x3c) == 0) {
        iVar3 = param_1;
      }
    }
    else {
      if (*(int *)(*(int *)(param_1 + 0x30) + 0x98) != 0x18) {
        iVar3 = 0;
        iVar5 = 4;
        pcVar4 = (char *)&STACKARG(0x1c);
        do {
          if (*pcVar4 == '\0') {
            *(undefined1 *)(iVar3 + *(int *)(param_1 + 0x30) + 0x9c) = 0;
            if (*(int *)(param_1 + 0x34) != 0) {
              *(undefined1 *)(iVar3 + *(int *)(param_1 + 0x34) + 0x9c) = 0;
            }
          }
          iVar3 = iVar3 + 1;
          pcVar4 = pcVar4 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      iVar3 = *(int *)(param_1 + 0x3c);
    }
  }
  else {
    iVar5 = *(int *)(param_3 + 8);
    uVar6 = *(undefined4 *)(iVar5 + 0x374);
    puVar1 = (undefined4 *)FUN_00193e18(uVar6,0x168);
    puVar7 = puVar1 + 1;
    *puVar1 = uVar6;
    FUN_00108770(puVar7,iVar5);
    puVar1[0x28] = uStack0000001c;
    puVar1[0x51] = *(undefined4 *)(param_1 + 8);
    puVar1[0x50] = *(undefined4 *)(param_1 + 4);
    uVar2 = FUN_00127608(*(undefined4 *)(param_3 + 0x3ac),0x2c,0,0);
    FUN_001046c8(puVar7,0,uVar2);
    FUN_001046c8(puVar7,2,uVar2);
    uVar6 = DAT_001afeec;
    iVar3 = FUN_001054ec(puVar7,2);
    *(undefined4 *)(iVar3 + 0x10) = uVar6;
    ((int (*)())FUN_0012306c)(uVar2,puVar7);
    uVar6 = *(undefined4 *)(param_3 + 0x3ac);
    iVar3 = *(int *)(iVar5 + 0x3ac) + -1;
    *(int *)(iVar5 + 0x3ac) = iVar3;
    uVar6 = FUN_001275a0(uVar6,0,iVar3,0);
    *(undefined4 *)(param_1 + 0x3c) = uVar6;
    FUN_001046c8(puVar7,1,uVar6);
    ((int (*)())FUN_001236e4)(*(undefined4 *)(param_1 + 0x3c),1,puVar7);
    ((int (*)())FUN_001236e4)(uVar2,2,puVar7);
    *(undefined4 **)(param_1 + 0x30) = puVar7;
    iVar3 = *(int *)(param_1 + 0x3c);
  }
  return iVar3;
}

/* FUN_00123c08 @ 0x123c08 (984 bytes) */
int FUN_00123c08(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  undefined4 param_3;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *a1;
  uint uVar11;
  uint *puVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  uint uVar15;
  int iVar16;
  undefined4 *local_58;
  undefined4 local_54;
  float local_50 [11];
  
  if (*(int *)(param_1 + 0x378) == 0) {
    iVar7 = *(int *)(param_1 + 8);
    iVar10 = *(int *)(iVar7 + 0x6c4);
    bVar1 = false;
    local_54 = DAT_001afee8;
    iVar9 = 0;
    iVar8 = 0;
    iVar16 = 4;
    iVar3 = iVar10;
    do {
      iVar2 = *(int *)(iVar3 + 0x10);
      if (iVar2 == 1) {
        *(undefined4 *)((int)local_50 + iVar8) = 0;
      }
      else if (iVar2 == 2) {
        *(undefined4 *)((int)local_50 + iVar8) = 0x3f800000;
      }
      else if (iVar2 == 0) {
        bVar1 = true;
        *(undefined4 *)((int)local_50 + iVar8) = 0;
        *(undefined1 *)((int)local_50 + iVar9 + -4) = 1;
      }
      iVar9 = iVar9 + 1;
      iVar8 = iVar8 + 4;
      iVar3 = iVar3 + 4;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
    uVar4 = FUN_001084b8(0x31,iVar7);
    *(undefined4 *)(param_1 + 0x378) = uVar4;
    ((void (*)())FUN_000f79c4)(uVar4,*(undefined4 *)(*(int *)(param_1 + 8) + 0x6c4),1,(double)local_50[0],
                 (double)local_50[1],(double)local_50[2],(double)local_50[3]);
    iVar3 = *(int *)(*(int *)(param_1 + 0x378) + 0xa4);
    piVar5 = *(int **)(iVar3 + 0x18);
    if (*piVar5 == 0) {
      puVar6 = (undefined4 *)FUN_0019423c(piVar5,0);
    }
    else {
      if (piVar5[1] == 0) {
        *(undefined4 *)piVar5[2] = 0;
        piVar5[1] = 1;
      }
      puVar6 = (undefined4 *)piVar5[2];
    }
    uVar4 = *puVar6;
    if (*(int *)(*(int *)(iVar3 + 0x2c) + 4) == 0) {
      uVar13 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
      puVar6 = (undefined4 *)FUN_00193e18(uVar13,0x240);
      *puVar6 = uVar13;
      puVar6 = puVar6 + 1;
      FUN_00173938(puVar6,uVar4,*(undefined4 *)(param_1 + 8));
      iVar7 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),7);
      if (iVar7 != 0) {
        FUN_00174e0c(puVar6);
        FUN_00173278(puVar6);
      }
      ((int (*)())FUN_00123424)(iVar3,param_2[0x2c],puVar6);
    }
    uVar13 = uVar4;
    ((int (*)())FUN_001236e4)(iVar3,1,uVar4);
    if (bVar1) {
      uVar14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar6 = (undefined4 *)FUN_00193e18(uVar14,0x168);
      *puVar6 = uVar14;
      a1 = puVar6 + 1;
      FUN_00108fb0(a1,*(undefined4 *)(param_1 + 8));
      (**(code **)(**(int **)(param_1 + 0x3a0) + 0xc))(*(int **)(param_1 + 0x3a0),a1,uVar13);
      iVar7 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar7;
      uVar13 = FUN_00127608(*(undefined4 *)(iVar10 + 0x3ac),0,iVar7,0);
      puVar6[0x24] = uVar13;
      iVar3 = FUN_001054ec(a1,0);
      *(int *)(iVar3 + 8) = iVar7;
      *(undefined4 *)(iVar3 + 0xc) = 0;
      uVar14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
      puVar6 = (undefined4 *)FUN_00193e18(uVar14,0x240);
      *puVar6 = uVar14;
      puVar6 = puVar6 + 1;
      FUN_00173938(puVar6,a1,*(undefined4 *)(param_1 + 8));
      iVar3 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),7);
      if (iVar3 != 0) {
        FUN_00174e0c(puVar6);
        FUN_00173278(puVar6);
      }
      ((int (*)())FUN_0012306c)(uVar13,a1);
      FUN_000e9c00(param_2,uVar13,puVar6);
      *(undefined4 *)(*(int *)(param_1 + 0x378) + 0x9c) = local_54;
      FUN_00106804(*(undefined4 *)(param_1 + 0x378),a1,0,*(undefined4 *)(param_1 + 8));
      *(undefined4 *)(*(int *)(param_1 + 0x378) + 0xbc) = uVar13;
      ((int (*)())FUN_001236e4)(uVar13,2,*(undefined4 *)(param_1 + 0x378));
    }
    FUN_00106004(*(undefined4 *)(param_1 + 0x378),1,uVar4,0,*(undefined4 *)(param_1 + 8));
    uVar4 = *(undefined4 *)(*(int *)(param_1 + 0x378) + 0x14c);
    iVar3 = FUN_001054ec(*(int *)(param_1 + 0x378),0);
    *(undefined4 *)(iVar3 + 0xc) = 0;
    *(undefined4 *)(iVar3 + 8) = uVar4;
    iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar3;
    uVar4 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0,iVar3,0);
    *(undefined4 *)(*(int *)(param_1 + 0x378) + 0x8c) = uVar4;
    ((int (*)())FUN_0012306c)(uVar4,*(undefined4 *)(param_1 + 0x378));
    (**(code **)(*param_2 + 0xc))(param_2,*(undefined4 *)(param_1 + 0x378),iVar3);
    uVar13 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
    puVar6 = (undefined4 *)FUN_00193e18(uVar13,0x240);
    *puVar6 = uVar13;
    FUN_00173938(puVar6 + 1,*(undefined4 *)(param_1 + 0x378),*(undefined4 *)(param_1 + 8));
    local_58 = puVar6 + 1;
    FUN_00175dac(iVar10,0,0,&local_58,param_2);
    FUN_000e9c00(param_2,uVar4,local_58);
    ((int (*)())FUN_00122f28)(uVar4,*(undefined4 *)(param_1 + 0x378));
  }
  else {
    puVar12 = *(uint **)(*(int *)(*(int *)(param_1 + 0x378) + 0x8c) + 0x2c);
    uVar11 = puVar12[1];
    uVar15 = uVar11 - 1;
    if (uVar15 < *puVar12) {
      if (uVar11 <= uVar15) {
        _memset((void *)(uVar11 * 4 + puVar12[2]),0,(uVar15 - uVar11) * 4 + 4);
        puVar12[1] = uVar11;
      }
      piVar5 = (int *)(uVar15 * 4 + puVar12[2]);
    }
    else {
      piVar5 = (int *)FUN_0019423c(puVar12,uVar15);
    }
    local_58 = (undefined4 *)*piVar5;
  }
  return local_58;
}

/* FUN_001240a8 @ 0x1240a8 (180 bytes) */
int FUN_001240a8(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  if (*(int *)(param_1 + 4) == 0x1a) {
    iVar1 = (**(code **)(**(int **)(param_3 + 0x30c) + 0x50))
                      (*(int **)(param_3 + 0x30c),*(undefined4 *)(param_1 + 8));
    FUN_001046c8(iVar1,0,param_1);
    *(undefined4 *)(iVar1 + 0x9c) = DAT_001afee8;
    ((int (*)())FUN_0012306c)(param_1,iVar1);
    uVar5 = *(undefined4 *)(param_3 + 0x378);
    puVar2 = (undefined4 *)FUN_00193e18(uVar5,0x240);
    puVar4 = puVar2 + 1;
    *puVar2 = uVar5;
    FUN_00173938(puVar4,iVar1,param_3);
    iVar3 = FUN_000e07dc(param_3,7);
    if (iVar3 != 0) {
      FUN_00174e0c(puVar4);
      FUN_00173278(puVar4);
    }
    *(uint *)(*(int *)(param_3 + 0x30c) + 8) = *(uint *)(*(int *)(param_3 + 0x30c) + 8) | 0x20;
    (**(code **)(*param_2 + 0xc))(param_2,iVar1);
    ((int (*)())FUN_00122f28)(param_1,iVar1);
    return puVar4;
  }
  puVar2 = (undefined4 *)((int (*)())FUN_00123c08)(*(undefined4 *)(param_3 + 0x6c4),param_2);
  return puVar2;
}

/* FUN_001241fc @ 0x1241fc (184 bytes) */
int FUN_001241fc(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  uVar4 = *(undefined4 *)(param_3 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar4,0x168);
  puVar5 = puVar1 + 1;
  *puVar1 = uVar4;
  FUN_00109a80(puVar5,0xfa,param_3);
  FUN_001046c8(puVar5,0,param_1);
  uVar4 = DAT_001afee8;
  puVar1[6] = puVar1[6] & 0xffff7fff;
  puVar1[0x28] = uVar4;
  uVar4 = *(undefined4 *)(param_3 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar4,0x240);
  puVar3 = puVar1 + 1;
  *puVar1 = uVar4;
  FUN_00173938(puVar3,puVar5,param_3);
  iVar2 = FUN_000e07dc(param_3,7);
  if (iVar2 != 0) {
    FUN_00174e0c(puVar3);
    FUN_00173278(puVar3);
  }
  ((int (*)())FUN_0012306c)(param_1,puVar5);
  (**(code **)(*param_2 + 0xc))(param_2,puVar5);
  ((int (*)())FUN_00122f28)(param_1,puVar5);
  return puVar3;
}

/* FUN_0012434c @ 0x12434c (152 bytes) */
int FUN_0012434c(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  uVar4 = *(undefined4 *)(param_3 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar4,0x168);
  puVar5 = puVar1 + 1;
  *puVar1 = uVar4;
  FUN_00109348(puVar5,param_1,param_3);
  FUN_001046c8(puVar5,0,param_1);
  uVar4 = *(undefined4 *)(param_3 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar4,0x240);
  puVar3 = puVar1 + 1;
  *puVar1 = uVar4;
  FUN_00173938(puVar3,puVar5,param_3);
  iVar2 = FUN_000e07dc(param_3,7);
  if (iVar2 != 0) {
    FUN_00174e0c(puVar3);
    FUN_00173278(puVar3);
  }
  ((int (*)())FUN_0012306c)(param_1,puVar5);
  (**(code **)(*param_2 + 0xc))(param_2,puVar5);
  ((int (*)())FUN_00122f28)(param_1,puVar5);
  return puVar3;
}

/* FUN_0012447c @ 0x12447c (148 bytes) */
int FUN_0012447c(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  uVar4 = *(undefined4 *)(param_3 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar4,0x168);
  puVar5 = puVar1 + 1;
  *puVar1 = uVar4;
  FUN_00109938(puVar5,param_3);
  FUN_001046c8(puVar5,0,param_1);
  uVar4 = *(undefined4 *)(param_3 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar4,0x240);
  puVar3 = puVar1 + 1;
  *puVar1 = uVar4;
  FUN_00173938(puVar3,puVar5,param_3);
  iVar2 = FUN_000e07dc(param_3,7);
  if (iVar2 != 0) {
    FUN_00174e0c(puVar3);
    FUN_00173278(puVar3);
  }
  ((int (*)())FUN_0012306c)(param_1,puVar5);
  (**(code **)(*param_2 + 0xc))(param_2,puVar5);
  ((int (*)())FUN_00122f28)(param_1,puVar5);
  return puVar3;
}

/* FUN_001245a8 @ 0x1245a8 (304 bytes) */
int FUN_001245a8(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  ((int (*)())FUN_0012379c)(param_1,param_2,param_3,param_4,param_5);
  param_1[4] = param_2;
  *param_1 = &PTR_FUN_001ea898;
  *(int *)(param_5 + 0x338) = *(int *)(param_5 + 0x338) + 1;
  if (param_3 == 3) {
    if (*(int *)(*(int *)(param_5 + 0x30c) + 0x24) <= param_2) {
      FUN_000e1534(param_5,10);
    }
  }
  else if (param_3 == 4) {
    if (*(int *)(*(int *)(param_5 + 0x30c) + 0x28) <= param_2) {
      FUN_000e1534(param_5,0xc);
    }
  }
  else if ((param_3 == 2) && (*(int *)(*(int *)(param_5 + 0x30c) + 0x2c) <= param_2)) {
    FUN_000e1534(param_5,0xb);
  }
  uVar4 = *(undefined4 *)(param_5 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar4,0x168);
  puVar3 = puVar1 + 1;
  *puVar1 = uVar4;
  FUN_00109614(puVar3,param_1,param_5);
  piVar2 = *(int **)(*(int *)(param_5 + 0x6c4) + 0x3a0);
  (**(code **)(*piVar2 + 0xc))(piVar2,puVar3);
  FUN_001046c8(puVar3,0,param_1);
  ((int (*)())FUN_0012306c)(param_1,puVar3);
  return;
}

/* FUN_00124724 @ 0x124724 (304 bytes) */
int FUN_00124724(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  ((int (*)())FUN_0012379c)(param_1,param_2,param_3,param_4,param_5);
  param_1[4] = param_2;
  *param_1 = &PTR_FUN_001ea898;
  *(int *)(param_5 + 0x338) = *(int *)(param_5 + 0x338) + 1;
  if (param_3 == 3) {
    if (*(int *)(*(int *)(param_5 + 0x30c) + 0x24) <= param_2) {
      FUN_000e1534(param_5,10);
    }
  }
  else if (param_3 == 4) {
    if (*(int *)(*(int *)(param_5 + 0x30c) + 0x28) <= param_2) {
      FUN_000e1534(param_5,0xc);
    }
  }
  else if ((param_3 == 2) && (*(int *)(*(int *)(param_5 + 0x30c) + 0x2c) <= param_2)) {
    FUN_000e1534(param_5,0xb);
  }
  uVar4 = *(undefined4 *)(param_5 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar4,0x168);
  puVar3 = puVar1 + 1;
  *puVar1 = uVar4;
  FUN_00109614(puVar3,param_1,param_5);
  piVar2 = *(int **)(*(int *)(param_5 + 0x6c4) + 0x3a0);
  (**(code **)(*piVar2 + 0xc))(piVar2,puVar3);
  FUN_001046c8(puVar3,0,param_1);
  ((int (*)())FUN_0012306c)(param_1,puVar3);
  return;
}

/* FUN_001248a0 @ 0x1248a0 (76 bytes) */
int FUN_001248a0(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())FUN_0012379c)(param_1,param_2,param_3,param_4,param_5);
  param_1[4] = param_2;
  *param_1 = &PTR_FUN_001ea860;
  return;
}

/* FUN_001248ec @ 0x1248ec (76 bytes) */
int FUN_001248ec(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())FUN_0012379c)(param_1,param_2,param_3,param_4,param_5);
  param_1[4] = param_2;
  *param_1 = &PTR_FUN_001ea860;
  return;
}

/* FUN_00124938 @ 0x124938 (100 bytes) */
int FUN_00124938(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  int iVar1;
  
  ((int (*)())FUN_0012379c)(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001ea7b8;
  iVar1 = *(int *)(param_5 + 0x334);
  param_1[4] = iVar1;
  param_1[7] = iVar1;
  *(int *)(param_5 + 0x334) = iVar1 + 1;
  param_1[0xc] = 0;
  return;
}

/* FUN_0012499c @ 0x12499c (300 bytes) */
int FUN_0012499c(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 local_38 [7];
  
  ((int (*)())FUN_00124938)(param_1,param_2,param_3,param_4,param_5);
  local_38[0] = DAT_001afef4;
  *param_1 = PTR_DAT_001e90c8 + 8;
  iVar4 = *(int *)(param_5 + 0x6c4);
  uVar1 = (**(code **)(**(int **)(param_5 + 0x30c) + 0xa4))
                    (*(int **)(param_5 + 0x30c),local_38,param_5);
  uVar1 = FUN_00127608(*(undefined4 *)(iVar4 + 0x3ac),0x10,uVar1,0);
  uVar5 = *(undefined4 *)(param_5 + 0x374);
  puVar2 = (undefined4 *)FUN_00193e18(uVar5,0x168);
  puVar6 = puVar2 + 1;
  *puVar2 = uVar5;
  FUN_00109348(puVar6,param_1,param_5);
  FUN_000e76c4(*(undefined4 *)(iVar4 + 0x3a0),puVar6);
  FUN_001046c8(puVar6,0,uVar1);
  ((int (*)())FUN_0012306c)(uVar1,puVar6);
  uVar5 = FUN_001084b8(0x31,param_5);
  FUN_001046c8(uVar5,1,uVar1);
  uVar1 = local_38[0];
  iVar3 = FUN_001054ec(uVar5,1);
  *(undefined4 *)(iVar3 + 0x10) = uVar1;
  FUN_001046c8(uVar5,0,param_1);
  ((int (*)())FUN_0012306c)(param_1,uVar5);
  FUN_000e7688(*(undefined4 *)(iVar4 + 0x3a0),uVar5);
  return;
}

/* FUN_00124b24 @ 0x124b24 (276 bytes) */
int FUN_00124b24(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  ((int (*)())FUN_00124938)(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_001e90e0 + 8;
  iVar5 = *(int *)(param_5 + 0x6c4);
  iVar1 = *(int *)(param_2 * 4 + iVar5 + 0x38);
  if (iVar1 == 0) {
    uVar2 = FUN_00127608(*(undefined4 *)(iVar5 + 0x3ac),0x10,param_2,0);
    uVar4 = *(undefined4 *)(param_5 + 0x374);
    puVar3 = (undefined4 *)FUN_00193e18(uVar4,0x168);
    puVar6 = puVar3 + 1;
    *puVar3 = uVar4;
    FUN_00109348(puVar6,param_1,param_5);
    FUN_000e76c4(*(undefined4 *)(iVar5 + 0x3a0),puVar6);
    FUN_001046c8(puVar6,0,uVar2);
    ((int (*)())FUN_0012306c)(uVar2,puVar6);
    *(undefined4 **)(param_2 * 4 + iVar5 + 0x38) = puVar6;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x8c);
  }
  uVar4 = FUN_001084b8(0x31,param_5);
  FUN_001046c8(uVar4,1,uVar2);
  FUN_001046c8(uVar4,0,param_1);
  ((int (*)())FUN_0012306c)(param_1,uVar4);
  FUN_000e7688(*(undefined4 *)(iVar5 + 0x3a0),uVar4);
  return;
}

/* FUN_00124c94 @ 0x124c94 (276 bytes) */
int FUN_00124c94(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  ((int (*)())FUN_00124938)(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_001e90e0 + 8;
  iVar5 = *(int *)(param_5 + 0x6c4);
  iVar1 = *(int *)(param_2 * 4 + iVar5 + 0x38);
  if (iVar1 == 0) {
    uVar2 = FUN_00127608(*(undefined4 *)(iVar5 + 0x3ac),0x10,param_2,0);
    uVar4 = *(undefined4 *)(param_5 + 0x374);
    puVar3 = (undefined4 *)FUN_00193e18(uVar4,0x168);
    puVar6 = puVar3 + 1;
    *puVar3 = uVar4;
    FUN_00109348(puVar6,param_1,param_5);
    FUN_000e76c4(*(undefined4 *)(iVar5 + 0x3a0),puVar6);
    FUN_001046c8(puVar6,0,uVar2);
    ((int (*)())FUN_0012306c)(uVar2,puVar6);
    *(undefined4 **)(param_2 * 4 + iVar5 + 0x38) = puVar6;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x8c);
  }
  uVar4 = FUN_001084b8(0x31,param_5);
  FUN_001046c8(uVar4,1,uVar2);
  FUN_001046c8(uVar4,0,param_1);
  ((int (*)())FUN_0012306c)(param_1,uVar4);
  FUN_000e7688(*(undefined4 *)(iVar5 + 0x3a0),uVar4);
  return;
}

/* FUN_00124e04 @ 0x124e04 (100 bytes) */
int FUN_00124e04(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  int iVar1;
  
  ((int (*)())FUN_0012379c)(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001ea7b8;
  iVar1 = *(int *)(param_5 + 0x334);
  param_1[4] = iVar1;
  param_1[7] = iVar1;
  *(int *)(param_5 + 0x334) = iVar1 + 1;
  param_1[0xc] = 0;
  return;
}

/* FUN_00124e68 @ 0x124e68 (552 bytes) */
int FUN_00124e68(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_28 [3];
  
  ((int (*)())FUN_0012379c)(param_1,param_2,param_3,param_4,param_5);
  param_1[0xd] = 0;
  *param_1 = &PTR_FUN_001ea748;
  param_1[0xc] = 0;
  uVar3 = *(undefined4 *)(param_5 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar3,0x168);
  puVar5 = puVar1 + 1;
  *puVar1 = uVar3;
  FUN_00108918(puVar5,param_5);
  iVar4 = *(int *)(param_5 + 0x6c4);
  FUN_000e76c4(*(undefined4 *)(iVar4 + 0x3a8),puVar5);
  FUN_001046c8(puVar5,0,param_1);
  ((int (*)())FUN_0012306c)(param_1,puVar5);
  param_1[0xc] = puVar5;
  puVar1[0x50] = param_3;
  puVar1[0x51] = param_2;
  uVar3 = FUN_000ec258(iVar4,param_3);
  uVar3 = FUN_000ec2a0(iVar4,uVar3);
  FUN_00104104(puVar5,0,uVar3,param_2);
  uVar3 = FUN_000ec258(iVar4,param_3);
  uVar3 = FUN_000ec2a0(iVar4,uVar3);
  FUN_00104104(puVar5,1,uVar3,param_2);
  uVar3 = FUN_000ec258(iVar4,param_3);
  uVar3 = FUN_000ec2a0(iVar4,uVar3);
  FUN_00104104(puVar5,2,uVar3,param_2);
  uVar3 = FUN_000ec258(iVar4,param_3);
  uVar3 = FUN_000ec2a0(iVar4,uVar3);
  FUN_00104104(puVar5,3,uVar3,param_2);
  uVar3 = *(undefined4 *)(iVar4 + 0x3ac);
  iVar2 = *(int *)(param_5 + 0x3ac) + -1;
  *(int *)(param_5 + 0x3ac) = iVar2;
  uVar3 = FUN_001275a0(uVar3,0,iVar2,0);
  param_1[0xd] = uVar3;
  FUN_001046c8(puVar5,1,uVar3);
  ((int (*)())FUN_001236e4)(param_1[0xd],1,puVar5);
  uVar3 = DAT_001afeec;
  if (param_3 == 8) {
    iVar2 = FUN_001054ec(puVar5,1);
    *(undefined4 *)(iVar2 + 0x10) = uVar3;
    (**(code **)(**(int **)(param_5 + 0x30c) + 0x118))(local_28);
    puVar1[0x28] = local_28[0];
    *(undefined4 **)(iVar4 + 0x34c) = puVar5;
  }
  else if (param_3 == 9) {
    if (param_1[2] == 0) {
      *(undefined4 **)(iVar4 + 0x348) = puVar5;
    }
  }
  else if (param_3 == 6) {
    *(undefined4 **)(iVar4 + 0x358) = puVar5;
  }
  else if (param_3 == 7) {
    *(undefined4 **)(iVar4 + 0x35c) = puVar5;
    *(undefined4 *)(iVar4 + 0x368) = 1;
  }
  return;
}

/* FUN_001250dc @ 0x1250dc (552 bytes) */
int FUN_001250dc(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_28 [3];
  
  ((int (*)())FUN_0012379c)(param_1,param_2,param_3,param_4,param_5);
  param_1[0xd] = 0;
  *param_1 = &PTR_FUN_001ea748;
  param_1[0xc] = 0;
  uVar3 = *(undefined4 *)(param_5 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar3,0x168);
  puVar5 = puVar1 + 1;
  *puVar1 = uVar3;
  FUN_00108918(puVar5,param_5);
  iVar4 = *(int *)(param_5 + 0x6c4);
  FUN_000e76c4(*(undefined4 *)(iVar4 + 0x3a8),puVar5);
  FUN_001046c8(puVar5,0,param_1);
  ((int (*)())FUN_0012306c)(param_1,puVar5);
  param_1[0xc] = puVar5;
  puVar1[0x50] = param_3;
  puVar1[0x51] = param_2;
  uVar3 = FUN_000ec258(iVar4,param_3);
  uVar3 = FUN_000ec2a0(iVar4,uVar3);
  FUN_00104104(puVar5,0,uVar3,param_2);
  uVar3 = FUN_000ec258(iVar4,param_3);
  uVar3 = FUN_000ec2a0(iVar4,uVar3);
  FUN_00104104(puVar5,1,uVar3,param_2);
  uVar3 = FUN_000ec258(iVar4,param_3);
  uVar3 = FUN_000ec2a0(iVar4,uVar3);
  FUN_00104104(puVar5,2,uVar3,param_2);
  uVar3 = FUN_000ec258(iVar4,param_3);
  uVar3 = FUN_000ec2a0(iVar4,uVar3);
  FUN_00104104(puVar5,3,uVar3,param_2);
  uVar3 = *(undefined4 *)(iVar4 + 0x3ac);
  iVar2 = *(int *)(param_5 + 0x3ac) + -1;
  *(int *)(param_5 + 0x3ac) = iVar2;
  uVar3 = FUN_001275a0(uVar3,0,iVar2,0);
  param_1[0xd] = uVar3;
  FUN_001046c8(puVar5,1,uVar3);
  ((int (*)())FUN_001236e4)(param_1[0xd],1,puVar5);
  uVar3 = DAT_001afeec;
  if (param_3 == 8) {
    iVar2 = FUN_001054ec(puVar5,1);
    *(undefined4 *)(iVar2 + 0x10) = uVar3;
    (**(code **)(**(int **)(param_5 + 0x30c) + 0x118))(local_28);
    puVar1[0x28] = local_28[0];
    *(undefined4 **)(iVar4 + 0x34c) = puVar5;
  }
  else if (param_3 == 9) {
    if (param_1[2] == 0) {
      *(undefined4 **)(iVar4 + 0x348) = puVar5;
    }
  }
  else if (param_3 == 6) {
    *(undefined4 **)(iVar4 + 0x358) = puVar5;
  }
  else if (param_3 == 7) {
    *(undefined4 **)(iVar4 + 0x35c) = puVar5;
    *(undefined4 *)(iVar4 + 0x368) = 1;
  }
  return;
}

/* FUN_00125350 @ 0x125350 (988 bytes) */
int FUN_00125350(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int local_48;
  undefined4 local_44 [3];
  undefined4 local_38 [3];
  
  ((int (*)())FUN_0012379c)(param_1,param_2,param_3,param_4,param_5);
  param_1[0xf] = 0;
  *param_1 = &PTR_FUN_001ea780;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  iVar7 = *(int *)(param_5 + 0x6c4);
  if ((*(uint *)(iVar7 + 0x30) & 0x2000) != 0) {
    iVar2 = FUN_00126760(param_1[1]);
    if (iVar2 != 0) {
      iVar2 = *(int *)(param_5 + 0x334);
      param_1[7] = iVar2;
      *(int *)(param_5 + 0x334) = iVar2 + 1;
      param_1[4] = param_2;
    }
    uVar8 = *(undefined4 *)(param_5 + 0x374);
    puVar3 = (undefined4 *)FUN_00193e18(uVar8,0x168);
    puVar9 = puVar3 + 1;
    *puVar3 = uVar8;
    FUN_00109198(puVar9,param_5);
    param_1[0xe] = puVar9;
    (**(code **)(**(int **)(iVar7 + 0x3a0) + 0xc))(*(int **)(iVar7 + 0x3a0),puVar9);
    FUN_001046c8(param_1[0xe],0,param_1);
    ((int (*)())FUN_0012306c)(param_1,param_1[0xe]);
    *(int *)(param_1[0xe] + 0x144) = param_3;
    *(undefined4 *)(param_1[0xe] + 0x148) = param_2;
    return;
  }
  if ((*(uint *)(iVar7 + 0x30) & 1) == 0) {
    return;
  }
  uVar8 = *(undefined4 *)(param_5 + 0x374);
  puVar3 = (undefined4 *)FUN_00193e18(uVar8,0x168);
  puVar9 = puVar3 + 1;
  *puVar3 = uVar8;
  FUN_00108918(puVar9,param_5);
  FUN_000e7688(*(undefined4 *)(iVar7 + 0x3a8),puVar9);
  FUN_001046c8(puVar9,0,param_1);
  ((int (*)())FUN_0012306c)(param_1,puVar9);
  param_1[0xc] = puVar9;
  uVar8 = *(undefined4 *)(iVar7 + 0x3ac);
  iVar2 = *(int *)(param_5 + 0x3ac) + -1;
  *(int *)(param_5 + 0x3ac) = iVar2;
  uVar8 = FUN_001275a0(uVar8,0,iVar2,0);
  param_1[0xf] = uVar8;
  iVar2 = (**(code **)(**(int **)(param_5 + 0x30c) + 0x120))
                    (*(int **)(param_5 + 0x30c),iVar7,param_5);
  if (iVar2 == 0) goto LAB_00125660;
  local_48 = 6;
  local_44[0] = 0;
  iVar2 = FUN_00127324(*(undefined4 *)(iVar7 + 0x3ac),param_1[1],param_2,&local_48,local_44);
  if (iVar2 == 0) goto LAB_00125660;
  uVar8 = 0xd;
  if (local_48 != 0x3f) {
    if (local_48 < 0x40) {
      uVar8 = 0xb;
      if (local_48 != 0x3e) {
LAB_00125578:
        uVar8 = 5;
      }
    }
    else {
      uVar8 = 0xe;
      if ((local_48 != 0x40) && (uVar8 = 0xc, local_48 != 0x41)) goto LAB_00125578;
    }
  }
  uVar4 = FUN_001275a0(*(undefined4 *)(iVar7 + 0x3ac),local_48,local_44[0],0);
  uVar6 = *(undefined4 *)(param_5 + 0x374);
  puVar5 = (undefined4 *)FUN_00193e18(uVar6,0x168);
  puVar10 = puVar5 + 1;
  *puVar5 = uVar6;
  FUN_00108918(puVar10,param_5);
  param_1[0xd] = puVar10;
  FUN_000e7688(*(undefined4 *)(iVar7 + 0x3a8),puVar10);
  FUN_001046c8(param_1[0xd],1,param_1[0xf]);
  FUN_001046c8(param_1[0xd],0,uVar4);
  *(undefined4 *)(param_1[0xd] + 0x9c) = DAT_001afef8;
  ((int (*)())FUN_0012306c)(uVar4,param_1[0xd]);
  iVar2 = 0;
  do {
    FUN_00104104(param_1[0xd],iVar2,uVar8,local_44[0]);
    bVar1 = iVar2 != 3;
    iVar2 = iVar2 + 1;
  } while (bVar1);
LAB_00125660:
  FUN_001046c8(puVar9,1,param_1[0xf]);
  ((int (*)())FUN_001236e4)(param_1[0xf],1,puVar9);
  puVar3[0x50] = param_3;
  puVar3[0x51] = param_2;
  uVar8 = FUN_000ec258(iVar7,param_3);
  uVar8 = FUN_000ec2a0(iVar7,uVar8);
  FUN_00104104(puVar9,0,uVar8,param_2);
  uVar8 = FUN_000ec258(iVar7,param_3);
  uVar8 = FUN_000ec2a0(iVar7,uVar8);
  FUN_00104104(puVar9,1,uVar8,param_2);
  uVar8 = FUN_000ec258(iVar7,param_3);
  uVar8 = FUN_000ec2a0(iVar7,uVar8);
  FUN_00104104(puVar9,2,uVar8,param_2);
  uVar8 = FUN_000ec258(iVar7,param_3);
  uVar8 = FUN_000ec2a0(iVar7,uVar8);
  FUN_00104104(puVar9,3,uVar8,param_2);
  uVar8 = DAT_001afeec;
  if (param_3 == 0x18) {
    iVar7 = FUN_001054ec(puVar9,1);
    *(undefined4 *)(iVar7 + 0x10) = uVar8;
    (**(code **)(**(int **)(param_5 + 0x30c) + 0x1c))(local_38);
    puVar3[0x28] = local_38[0];
  }
  return;
}

/* FUN_001257b0 @ 0x1257b0 (988 bytes) */
int FUN_001257b0(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int local_48;
  undefined4 local_44 [3];
  undefined4 local_38 [3];
  
  ((int (*)())FUN_0012379c)(param_1,param_2,param_3,param_4,param_5);
  param_1[0xf] = 0;
  *param_1 = &PTR_FUN_001ea780;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  iVar7 = *(int *)(param_5 + 0x6c4);
  if ((*(uint *)(iVar7 + 0x30) & 0x2000) != 0) {
    iVar2 = FUN_00126760(param_1[1]);
    if (iVar2 != 0) {
      iVar2 = *(int *)(param_5 + 0x334);
      param_1[7] = iVar2;
      *(int *)(param_5 + 0x334) = iVar2 + 1;
      param_1[4] = param_2;
    }
    uVar8 = *(undefined4 *)(param_5 + 0x374);
    puVar3 = (undefined4 *)FUN_00193e18(uVar8,0x168);
    puVar9 = puVar3 + 1;
    *puVar3 = uVar8;
    FUN_00109198(puVar9,param_5);
    param_1[0xe] = puVar9;
    (**(code **)(**(int **)(iVar7 + 0x3a0) + 0xc))(*(int **)(iVar7 + 0x3a0),puVar9);
    FUN_001046c8(param_1[0xe],0,param_1);
    ((int (*)())FUN_0012306c)(param_1,param_1[0xe]);
    *(int *)(param_1[0xe] + 0x144) = param_3;
    *(undefined4 *)(param_1[0xe] + 0x148) = param_2;
    return;
  }
  if ((*(uint *)(iVar7 + 0x30) & 1) == 0) {
    return;
  }
  uVar8 = *(undefined4 *)(param_5 + 0x374);
  puVar3 = (undefined4 *)FUN_00193e18(uVar8,0x168);
  puVar9 = puVar3 + 1;
  *puVar3 = uVar8;
  FUN_00108918(puVar9,param_5);
  FUN_000e7688(*(undefined4 *)(iVar7 + 0x3a8),puVar9);
  FUN_001046c8(puVar9,0,param_1);
  ((int (*)())FUN_0012306c)(param_1,puVar9);
  param_1[0xc] = puVar9;
  uVar8 = *(undefined4 *)(iVar7 + 0x3ac);
  iVar2 = *(int *)(param_5 + 0x3ac) + -1;
  *(int *)(param_5 + 0x3ac) = iVar2;
  uVar8 = FUN_001275a0(uVar8,0,iVar2,0);
  param_1[0xf] = uVar8;
  iVar2 = (**(code **)(**(int **)(param_5 + 0x30c) + 0x120))
                    (*(int **)(param_5 + 0x30c),iVar7,param_5);
  if (iVar2 == 0) goto LAB_00125ac0;
  local_48 = 6;
  local_44[0] = 0;
  iVar2 = FUN_00127324(*(undefined4 *)(iVar7 + 0x3ac),param_1[1],param_2,&local_48,local_44);
  if (iVar2 == 0) goto LAB_00125ac0;
  uVar8 = 0xd;
  if (local_48 != 0x3f) {
    if (local_48 < 0x40) {
      uVar8 = 0xb;
      if (local_48 != 0x3e) {
LAB_001259d8:
        uVar8 = 5;
      }
    }
    else {
      uVar8 = 0xe;
      if ((local_48 != 0x40) && (uVar8 = 0xc, local_48 != 0x41)) goto LAB_001259d8;
    }
  }
  uVar4 = FUN_001275a0(*(undefined4 *)(iVar7 + 0x3ac),local_48,local_44[0],0);
  uVar6 = *(undefined4 *)(param_5 + 0x374);
  puVar5 = (undefined4 *)FUN_00193e18(uVar6,0x168);
  puVar10 = puVar5 + 1;
  *puVar5 = uVar6;
  FUN_00108918(puVar10,param_5);
  param_1[0xd] = puVar10;
  FUN_000e7688(*(undefined4 *)(iVar7 + 0x3a8),puVar10);
  FUN_001046c8(param_1[0xd],1,param_1[0xf]);
  FUN_001046c8(param_1[0xd],0,uVar4);
  *(undefined4 *)(param_1[0xd] + 0x9c) = DAT_001afef8;
  ((int (*)())FUN_0012306c)(uVar4,param_1[0xd]);
  iVar2 = 0;
  do {
    FUN_00104104(param_1[0xd],iVar2,uVar8,local_44[0]);
    bVar1 = iVar2 != 3;
    iVar2 = iVar2 + 1;
  } while (bVar1);
LAB_00125ac0:
  FUN_001046c8(puVar9,1,param_1[0xf]);
  ((int (*)())FUN_001236e4)(param_1[0xf],1,puVar9);
  puVar3[0x50] = param_3;
  puVar3[0x51] = param_2;
  uVar8 = FUN_000ec258(iVar7,param_3);
  uVar8 = FUN_000ec2a0(iVar7,uVar8);
  FUN_00104104(puVar9,0,uVar8,param_2);
  uVar8 = FUN_000ec258(iVar7,param_3);
  uVar8 = FUN_000ec2a0(iVar7,uVar8);
  FUN_00104104(puVar9,1,uVar8,param_2);
  uVar8 = FUN_000ec258(iVar7,param_3);
  uVar8 = FUN_000ec2a0(iVar7,uVar8);
  FUN_00104104(puVar9,2,uVar8,param_2);
  uVar8 = FUN_000ec258(iVar7,param_3);
  uVar8 = FUN_000ec2a0(iVar7,uVar8);
  FUN_00104104(puVar9,3,uVar8,param_2);
  uVar8 = DAT_001afeec;
  if (param_3 == 0x18) {
    iVar7 = FUN_001054ec(puVar9,1);
    *(undefined4 *)(iVar7 + 0x10) = uVar8;
    (**(code **)(**(int **)(param_5 + 0x30c) + 0x1c))(local_38);
    puVar3[0x28] = local_38[0];
  }
  return;
}

/* FUN_00125c10 @ 0x125c10 (104 bytes) */
int FUN_00125c10(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  ((int (*)())FUN_0012379c)(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_001e90d8 + 8;
  FUN_00130444(*(undefined4 *)(param_5 + 0x6c4),param_2);
  param_1[4] = param_2;
  param_1[9] = param_1[9] | 2;
  return;
}

/* FUN_00125c8c @ 0x125c8c (104 bytes) */
int FUN_00125c8c(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  ((int (*)())FUN_0012379c)(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_001e90d8 + 8;
  FUN_00130444(*(undefined4 *)(param_5 + 0x6c4),param_2);
  param_1[4] = param_2;
  param_1[9] = param_1[9] | 2;
  return;
}

/* FUN_00125d08 @ 0x125d08 (88 bytes) */
int FUN_00125d08(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())FUN_0012379c)(param_1,param_2,param_3,param_4,param_5);
  param_1[4] = param_2 + param_3 * 0x10000;
  *param_1 = &PTR_FUN_001ea828;
  return;
}

/* FUN_00125d60 @ 0x125d60 (88 bytes) */
int FUN_00125d60(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())FUN_0012379c)(param_1,param_2,param_3,param_4,param_5);
  param_1[4] = param_2 + param_3 * 0x10000;
  *param_1 = &PTR_FUN_001ea828;
  return;
}

/* FUN_00125db8 @ 0x125db8 (300 bytes) */
int FUN_00125db8(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 local_38 [7];
  
  ((int (*)())FUN_00124938)(param_1,param_2,param_3,param_4,param_5);
  local_38[0] = DAT_001afef4;
  *param_1 = PTR_DAT_001e90c8 + 8;
  iVar4 = *(int *)(param_5 + 0x6c4);
  uVar1 = (**(code **)(**(int **)(param_5 + 0x30c) + 0xa4))
                    (*(int **)(param_5 + 0x30c),local_38,param_5);
  uVar1 = FUN_00127608(*(undefined4 *)(iVar4 + 0x3ac),0x10,uVar1,0);
  uVar5 = *(undefined4 *)(param_5 + 0x374);
  puVar2 = (undefined4 *)FUN_00193e18(uVar5,0x168);
  puVar6 = puVar2 + 1;
  *puVar2 = uVar5;
  FUN_00109348(puVar6,param_1,param_5);
  FUN_000e76c4(*(undefined4 *)(iVar4 + 0x3a0),puVar6);
  FUN_001046c8(puVar6,0,uVar1);
  ((int (*)())FUN_0012306c)(uVar1,puVar6);
  uVar5 = FUN_001084b8(0x31,param_5);
  FUN_001046c8(uVar5,1,uVar1);
  uVar1 = local_38[0];
  iVar3 = FUN_001054ec(uVar5,1);
  *(undefined4 *)(iVar3 + 0x10) = uVar1;
  FUN_001046c8(uVar5,0,param_1);
  ((int (*)())FUN_0012306c)(param_1,uVar5);
  FUN_000e7688(*(undefined4 *)(iVar4 + 0x3a0),uVar5);
  return;
}

/* FUN_00125f40 @ 0x125f40 (84 bytes) */
int FUN_00125f40(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined *puVar1;
  
  ((int (*)())FUN_0012379c)(param_1,param_2,param_3,param_4,param_5);
  puVar1 = PTR_DAT_001e90cc;
  param_1[0xc] = 0;
  param_1[4] = param_2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00125f94 @ 0x125f94 (84 bytes) */
int FUN_00125f94(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined *puVar1;
  
  ((int (*)())FUN_0012379c)(param_1,param_2,param_3,param_4,param_5);
  puVar1 = PTR_DAT_001e90cc;
  param_1[0xc] = 0;
  param_1[4] = param_2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00125fe8 @ 0x125fe8 (76 bytes) */
int FUN_00125fe8(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined *puVar1;
  
  ((int (*)())FUN_0012379c)(param_1,param_2,param_3,param_4,param_5);
  puVar1 = PTR_DAT_001e90e8;
  param_1[4] = param_2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00126034 @ 0x126034 (76 bytes) */
int FUN_00126034(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined *puVar1;
  
  ((int (*)())FUN_0012379c)(param_1,param_2,param_3,param_4,param_5);
  puVar1 = PTR_DAT_001e90e8;
  param_1[4] = param_2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00126080 @ 0x126080 (116 bytes) */
int FUN_00126080(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined *puVar1;
  
  ((int (*)())FUN_0012379c)(param_1,param_2,param_3,param_4,param_5);
  puVar1 = PTR_DAT_001e90ec;
  param_1[0xc] = 0;
  *param_1 = puVar1 + 8;
  *param_1 = PTR_DAT_001e90dc + 8;
  param_1[4] = *(undefined4 *)(param_5 + 0x344);
  *(int *)(param_5 + 0x344) = *(int *)(param_5 + 0x344) + 1;
  return;
}

