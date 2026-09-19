#include "decls.h"

/* FUN_0019ab60 @ 0x19ab60 (100 bytes) */
int FUN_0019ab60(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x40))(param_2);
  if (iVar1 == 0) {
    FUN_000e1534(param_4,0xf);
    return;
  }
  return;
}

/* FUN_0019abc4 @ 0x19abc4 (100 bytes) */
int FUN_0019abc4(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 300) + 0x40))();
  if (iVar1 == 0) {
    FUN_000e1534(param_4,0xf);
    return;
  }
  return;
}

/* FUN_0019ac2c @ 0x19ac2c (120 bytes) */
int FUN_0019ac2c(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  
  FUN_0019a568(param_1,4);
  iVar2 = *(int *)(param_1 + 0x5c) * 0x1c;
  *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
  iVar1 = iVar2 + *(int *)(param_1 + 0x40);
  *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x40)) = param_2;
  *(undefined4 *)(iVar1 + 8) = 0x35;
  *(undefined4 *)(iVar1 + 0xc) = param_3;
  iVar2 = *(int *)(param_1 + 0x58);
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(int *)(iVar1 + 0x10) = iVar2 + -2;
  return;
}

/* FUN_0019acb0 @ 0x19acb0 (328 bytes) */
int FUN_0019acb0(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  
  *(int *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_4 + 0x30c);
  iVar4 = *(int *)(param_4 + 0x324) << 4;
  iVar1 = *(int *)(*(int *)(param_4 + 0x30c) + 0x40) << 4;
  if (iVar4 < iVar1) {
    iVar4 = iVar1;
  }
  uVar2 = FUN_00193e18(*(undefined4 *)(param_4 + 0x374),iVar4);
  *(undefined4 *)(param_1 + 0x44) = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_4 + 0x374),*(int *)(param_4 + 0x324) * 0x38);
  *(undefined4 *)(param_1 + 0x40) = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_4 + 0x374),900);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x54) = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_4 + 0x374),*(int *)(param_4 + 0x324) << 3);
  *(undefined4 *)(param_1 + 8) = uVar2;
  pvVar3 = (void *)FUN_000e14e4(param_4,0x28,param_3);
  *(void **)(param_1 + 0x50) = pvVar3;
  _memset(pvVar3,0,0x28);
  **(int **)(param_1 + 0x50) = iVar4;
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 4) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 8) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x70) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  return;
}

/* FUN_0019adf8 @ 0x19adf8 (136 bytes) */
int FUN_0019adf8(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3d4) = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc);
    if (*(int *)(iVar2 + 0x3d4) == 0) {
      *(undefined4 *)(iVar2 + 0x3d4) = 1;
      iVar2 = *(int *)(param_1 + 0xc);
    }
    iVar1 = *(int *)(iVar2 + 0x3d4);
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0x374),*(undefined4 *)(param_1 + 0x60));
    uVar3 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x374),iVar1 * 0xc);
    *(undefined4 *)(param_1 + 0x60) = uVar3;
  }
  return;
}

/* FUN_0019ae80 @ 0x19ae80 (104 bytes) */
int FUN_0019ae80(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x9c);
  uVar1 = FUN_000e7d5c(param_2);
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,uVar1,*(undefined4 *)(param_2 + 0x134));
  return;
}

/* FUN_0019b03c @ 0x19b03c (908 bytes) */
int FUN_0019b03c(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int *param_3;
  undefined4 *param_4;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  undefined4 uVar13;
  
  *param_4 = 0;
  piVar4 = (int *)0x0;
  if (param_3 != (int *)0x0) {
    piVar8 = (int *)0x0;
    piVar9 = (int *)0x0;
    bVar2 = false;
    bVar1 = true;
    piVar10 = param_3;
    do {
      uVar11 = piVar10[5];
      if ((uVar11 & 1) != 0) {
        if ((uVar11 & 4) != 0) {
          bVar2 = true;
        }
        iVar3 = FUN_0019a538(*(undefined4 *)(param_1 + 0x88),piVar10);
        if (iVar3 == 0) {
          if ((uVar11 & 0x10000) == 0) {
            piVar8 = piVar10;
          }
        }
        else {
          piVar9 = piVar10;
          if (piVar10[0x26] == 1) {
            iVar3 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),piVar10);
            piVar4 = *(int **)(*(int *)(param_1 + 0xc) + 0x30c);
            iVar5 = (**(code **)(*piVar4 + 0x138))(piVar4,0);
            if ((uint)(iVar3 - iVar5) < 4) {
              iVar3 = (**(code **)(*piVar10 + 0x14))(piVar10);
              if (1 < iVar3) {
                iVar3 = FUN_00105594(piVar10,1);
                iVar5 = *(int *)(iVar3 + 0x94);
                iVar3 = FUN_00105594(piVar10,2);
                if (iVar5 != *(int *)(iVar3 + 0x94)) goto LAB_0019b168;
              }
              uVar11 = piVar10[5];
              goto LAB_0019b144;
            }
LAB_0019b168:
            uVar11 = piVar10[5];
          }
          bVar1 = false;
        }
      }
LAB_0019b144:
      piVar10 = (int *)piVar10[2];
    } while ((piVar10 != (int *)0x0) && ((uVar11 & 4) != 0));
    piVar4 = param_3;
    if ((piVar8 != (int *)0x0) && (piVar9 != (int *)0x0)) {
      if (bVar1) {
        *param_4 = 1;
      }
      else if (bVar2) {
        *(int *)(*(int *)(param_1 + 0x10) + 0x14) = *(int *)(*(int *)(param_1 + 0x10) + 0x14) + 1;
        piVar4 = (int *)piVar10[1];
        iVar3 = param_3[0x56];
        if (piVar4 == piVar9) {
          *(uint *)(piVar9[1] + 0x14) = *(uint *)(piVar9[1] + 0x14) & 0xfffffffb;
        }
        else {
          piVar9[5] = piVar9[5] & 0xfffffffb;
          FUN_0019401c(piVar9);
          FUN_000e7738(iVar3,piVar4,piVar9);
        }
        for (iVar5 = 1; iVar6 = (**(code **)(*piVar9 + 0x14))(piVar9), piVar4 = piVar8,
            iVar5 <= iVar6; iVar5 = iVar5 + 1) {
          iVar12 = piVar8[0x26];
          iVar6 = FUN_00105594(piVar9,iVar5);
          if (iVar12 == *(int *)(iVar6 + 0x98)) {
            iVar6 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),piVar8);
            uVar13 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
            uVar7 = FUN_00105594(piVar9,iVar5);
            iVar12 = thunk_FUN_00134de8(uVar13,uVar7);
            if (iVar6 == iVar12) {
              iVar6 = 1;
              piVar4 = (int *)FUN_001043f0(0x31,*(undefined4 *)(param_1 + 0xc));
              uVar7 = FUN_00130690(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),0);
              iVar5 = FUN_001054ec(piVar4,0);
              *(undefined4 *)(iVar5 + 0xc) = 0;
              *(undefined4 *)(iVar5 + 8) = uVar7;
              FUN_00106004(piVar4,1,piVar8,0,*(undefined4 *)(param_1 + 0xc));
              FUN_000e7700(iVar3,piVar8,piVar4);
              *(int *)(*(int *)(param_1 + 0x10) + 0x18) =
                   *(int *)(*(int *)(param_1 + 0x10) + 0x18) + 1;
              if (piVar4 == (int *)0x0) {
                return piVar8;
              }
              for (; iVar3 = (**(code **)(*piVar9 + 0x14))(piVar9), iVar6 <= iVar3;
                  iVar6 = iVar6 + 1) {
                iVar5 = piVar8[0x26];
                iVar3 = FUN_00105594(piVar9,iVar6);
                if (iVar5 == *(int *)(iVar3 + 0x98)) {
                  iVar3 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),piVar8
                                            );
                  uVar13 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
                  uVar7 = FUN_00105594(piVar9,iVar6);
                  iVar5 = thunk_FUN_00134de8(uVar13,uVar7);
                  if (iVar3 == iVar5) {
                    FUN_00106004(piVar9,iVar6,piVar4,0,*(undefined4 *)(param_1 + 0xc));
                  }
                }
              }
              return piVar4;
            }
          }
        }
      }
    }
  }
  return piVar4;
}

/* FUN_0019b3c8 @ 0x19b3c8 (728 bytes) */
int FUN_0019b3c8(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int local_38 [9];
  
  piVar5 = *(int **)(param_2 + 8);
  if (piVar5[2] == 0) {
    return;
  }
  do {
    iVar3 = (**(code **)(*param_1 + 8))(param_1);
    if (iVar3 != 0) {
      FUN_000e1534(param_1[3],5);
    }
    iVar3 = param_1[3];
    if (**(int **)(iVar3 + 0x6c4) == 0) {
      piVar4 = (int *)FUN_000e3b88(param_1[4],param_2,piVar5,local_38);
      if ((piVar4 == (int *)0x0) || (local_38[0] == 0)) {
        iVar3 = param_1[3];
      }
      else {
        iVar3 = param_1[3];
        piVar5 = piVar4;
      }
    }
    piVar4 = piVar5;
    if (**(int **)(iVar3 + 0x6c4) == 0) {
      piVar4 = (int *)((int (*)())FUN_0019b03c)(param_1,param_2,piVar5,param_1 + 0x1f);
      iVar3 = param_1[3];
    }
    iVar3 = FUN_00106cf8(piVar4,*(undefined4 *)(iVar3 + 0x6c4));
    if ((((iVar3 == 0) || (uVar2 = piVar4[5], (uVar2 & 4) != 0)) || ((int)uVar2 < 0)) ||
       ((uVar2 & 0x1000) != 0)) {
      (**(code **)(*param_1 + 0xbc))(param_1);
      piVar6 = piVar4;
      piVar5 = piVar4;
      do {
        if (piVar5 == (int *)0x0) break;
        uVar2 = piVar6[5];
        if ((uVar2 & 1) != 0) {
          if ((uVar2 & 0x10000) == 0) {
            iVar3 = (**(code **)(*piVar6 + 0x68))(piVar6);
            if (iVar3 != 0) {
              piVar5 = (int *)FUN_00105594(piVar6,1);
              iVar3 = (**(code **)(*piVar5 + 0x50))();
              if ((iVar3 != 0) && (piVar6[0x51] != 0)) {
                return;
              }
            }
            FUN_0019a568(param_1,2);
            (**(code **)(*piVar6 + 0x1c))(piVar6,param_1,0,param_1[3]);
          }
          else {
            iVar3 = (**(code **)(*piVar6 + 0x48))(piVar6);
            if (iVar3 != 0) {
              (**(code **)(*param_1 + 0xc0))(param_1,piVar6,param_1[3]);
            }
          }
          (**(code **)(*piVar6 + 0x20))(piVar6,param_1,0,param_1[3]);
          uVar2 = piVar6[5];
        }
        piVar6 = (int *)piVar6[2];
        piVar5 = (int *)(uVar2 & 4);
      } while (piVar6 != (int *)0x0);
      iVar3 = (**(code **)(*piVar4 + 0x24))(piVar4);
      if (iVar3 == 0) {
        piVar6 = (int *)piVar4[2];
      }
      else {
        (**(code **)(*param_1 + 0xc4))(param_1);
        piVar6 = (int *)piVar4[2];
      }
    }
    else {
      *(int *)(param_1[4] + 0xc) = *(int *)(param_1[4] + 0xc) + 1;
      piVar6 = (int *)piVar4[2];
    }
    do {
      piVar5 = piVar6;
      puVar1 = (uint *)(piVar4 + 5);
      if ((int *)piVar5[2] == (int *)0x0) {
        return;
      }
      piVar6 = (int *)piVar5[2];
      piVar4 = piVar5;
    } while ((*puVar1 & 4) != 0);
  } while( true );
}

/* FUN_0019b6a0 @ 0x19b6a0 (168 bytes) */
int FUN_0019b6a0(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  FUN_0019a568(param_1,3);
  piVar3 = (int *)0x0;
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x28);
  uVar2 = *(uint *)(iVar1 + 4);
  if (uVar2 - 1 < uVar2) {
    piVar3 = (int *)((uVar2 - 1) * 4 + *(int *)(iVar1 + 8));
  }
  iVar4 = *piVar3;
  FUN_00194208(iVar1,uVar2 - 1);
  uVar2 = *(uint *)(iVar4 + 0x10);
  *(int *)(iVar4 + 0x18) = *(int *)(param_1 + 0x58) + -2;
  if (uVar2 < *(uint *)(param_1 + 0x2c)) {
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x58) + -1;
    uVar2 = *(uint *)(iVar4 + 0x10);
  }
  if (uVar2 < *(uint *)(param_1 + 0x30)) {
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x58) + -1;
  }
  return;
}

/* FUN_0019b748 @ 0x19b748 (192 bytes) */
int FUN_0019b748(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  
  FUN_0019a568(param_1,4);
  iVar1 = *(int *)(param_1 + 0x5c);
  *(int *)(param_1 + 0x5c) = iVar1 + 1;
  iVar5 = iVar1 * 0x1c + *(int *)(param_1 + 0x40);
  *(undefined4 *)(iVar5 + 8) = 0x3e;
  iVar1 = *(int *)(param_1 + 0x58);
  *(undefined4 *)(iVar5 + 0xc) = param_2;
  *(undefined4 *)(iVar5 + 4) = param_3;
  *(int *)(iVar5 + 0x10) = iVar1 + -2;
  puVar4 = *(uint **)(*(int *)(param_1 + 0x10) + 0x28);
  uVar3 = puVar4[1];
  if (uVar3 < *puVar4) {
    _memset((void *)(uVar3 * 4 + puVar4[2]),0,4);
    piVar2 = (int *)(uVar3 * 4 + puVar4[2]);
    puVar4[1] = uVar3 + 1;
  }
  else {
    piVar2 = (int *)FUN_0019423c(puVar4,uVar3);
  }
  *piVar2 = iVar5;
  return;
}

/* FUN_0019b808 @ 0x19b808 (180 bytes) */
int FUN_0019b808(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)0x0;
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x24);
  uVar2 = *(uint *)(iVar1 + 4);
  if (uVar2 - 1 < uVar2) {
    piVar3 = (int *)((uVar2 - 1) * 4 + *(int *)(iVar1 + 8));
  }
  iVar4 = *piVar3;
  FUN_00194208(iVar1,uVar2 - 1);
  *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(param_1 + 0x58);
  if (*(int *)(iVar4 + 0x14) == 0) {
    uVar2 = *(uint *)(iVar4 + 0x10);
    *(uint *)(iVar4 + 0x14) = uVar2;
  }
  else {
    uVar2 = *(uint *)(iVar4 + 0x10);
  }
  if (uVar2 < *(uint *)(param_1 + 0x2c)) {
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x58);
    uVar2 = *(uint *)(iVar4 + 0x10);
  }
  if (uVar2 < *(uint *)(param_1 + 0x30)) {
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x58);
  }
  FUN_0019a568(param_1,3);
  return;
}

/* FUN_0019b8bc @ 0x19b8bc (96 bytes) */
int FUN_0019b8bc(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x90);
  *puVar1 = uVar2;
  puVar1[1] = &PTR_LAB_001eb808;
  puVar1[7] = 0;
  return puVar1 + 1;
}

/* FUN_0019b91c @ 0x19b91c (124 bytes) */
int FUN_0019b91c(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_LAB_001eb808;
  FUN_00193cc0(*(undefined4 *)(param_1[3] + 0x374),param_1[2]);
  param_1[2] = 0;
  FUN_00193cc0(*(undefined4 *)(param_1[3] + 0x374),param_1[0x18]);
  param_1[0x11] = 0;
  *param_1 = PTR_DAT_001e914c + 8;
  return;
}

/* FUN_0019baf4 @ 0x19baf4 (1596 bytes) */
int FUN_0019baf4(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  uint *param_3;
{
  bool bVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined4 uVar16;
  
  iVar4 = (**(code **)(**(int **)(*(int *)(param_1 + 0xc) + 0x30c) + 0x16c))();
  iVar2 = *(int *)(param_2[0x22] + 8);
  iVar4 = *(int *)(iVar2 * 0x38 + iVar4 + 0xc);
  if (iVar2 == 0x32) {
    uVar15 = param_3[3];
    bVar1 = true;
    uVar12 = param_3[1];
    uVar14 = param_3[2] >> 0x10 & 7;
    uVar13 = uVar12 >> 0xd & 7;
    param_3[1] = uVar14 << 0x16 |
                 uVar14 << 0x13 | uVar14 << 0x10 | uVar14 << 0xd | param_3[2] & 0xfe001fff;
    *(byte *)((int)param_3 + 3) = (byte)iVar4 | 0x40;
    param_3[2] = uVar13 << 0x16 | uVar13 << 0x13 | uVar13 << 0x10 | uVar12 & 0xfe00ffff;
    param_3[3] = (uVar15 & 0xfff81fff) >> 3 & 0x380000 |
                 (uVar15 & 0xffff1fff) >> 6 & 0x70000 | uVar15 >> 9 & 0xe000 | uVar15 & 0xffc01fff;
  }
  else if (iVar4 == -1) {
    if (iVar2 < 0x32) {
      if (iVar2 < 0x30) {
        if (iVar2 == 0x1c) {
          bVar1 = true;
          *(undefined1 *)((int)param_3 + 3) = 1;
          param_3[1] = param_3[1] & 0xfe3fffff | 0x1000000;
          param_3[2] = param_3[2] & 0xfe3fffff | 0x1000000;
        }
        else {
          if (iVar2 != 0x28) goto LAB_0019bc7c;
          uVar12 = param_3[1];
          bVar1 = true;
          *(undefined1 *)((int)param_3 + 3) = 10;
          param_3[1] = param_3[2];
          param_3[2] = uVar12;
        }
      }
      else {
LAB_0019bbfc:
        bVar1 = false;
        *(undefined1 *)((int)param_3 + 3) = 7;
        param_3[2] = param_3[1];
      }
    }
    else {
      if (iVar2 == 0x66) goto LAB_0019bbfc;
      if (iVar2 != 0xa5) goto LAB_0019bc7c;
      bVar1 = true;
      *(undefined1 *)((int)param_3 + 3) = 5;
      param_3[3] = param_3[2];
    }
  }
  else {
    *(byte *)((int)param_3 + 3) = (byte)iVar4;
LAB_0019bc7c:
    bVar1 = true;
  }
  iVar2 = (**(code **)(*param_2 + 0x14))(param_2);
  if (iVar2 != 3) goto LAB_0019bee4;
  piVar5 = (int *)FUN_00105594(param_2,1);
  iVar2 = (**(code **)(*piVar5 + 0x60))();
  if (iVar2 == 0) {
    uVar16 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = FUN_00105594(param_2,1);
    iVar2 = thunk_FUN_00134de8(uVar16,uVar6);
    iVar7 = FUN_00105594(param_2,1);
    iVar7 = *(int *)(iVar7 + 0x98);
  }
  else {
    uVar16 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = FUN_00105594(param_2,1);
    uVar6 = FUN_00105594(uVar6,1);
    iVar2 = thunk_FUN_00134de8(uVar16,uVar6);
    uVar6 = FUN_00105594(param_2,1);
    iVar7 = FUN_00105594(uVar6,1);
    iVar7 = *(int *)(iVar7 + 0x98);
  }
  piVar5 = (int *)FUN_00105594(param_2,2);
  iVar8 = (**(code **)(*piVar5 + 0x60))();
  if (iVar8 == 0) {
    uVar16 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = FUN_00105594(param_2,2);
    iVar8 = thunk_FUN_00134de8(uVar16,uVar6);
    iVar9 = FUN_00105594(param_2,2);
    iVar9 = *(int *)(iVar9 + 0x98);
  }
  else {
    uVar16 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = FUN_00105594(param_2,2);
    uVar6 = FUN_00105594(uVar6,1);
    iVar8 = thunk_FUN_00134de8(uVar16,uVar6);
    uVar6 = FUN_00105594(param_2,2);
    iVar9 = FUN_00105594(uVar6,1);
    iVar9 = *(int *)(iVar9 + 0x98);
  }
  piVar5 = (int *)FUN_00105594(param_2,3);
  iVar10 = (**(code **)(*piVar5 + 0x60))();
  if (iVar10 == 0) {
    uVar16 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = FUN_00105594(param_2,3);
    iVar11 = thunk_FUN_00134de8(uVar16,uVar6);
    iVar10 = FUN_00105594(param_2,3);
    iVar10 = *(int *)(iVar10 + 0x98);
  }
  else {
    uVar16 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = FUN_00105594(param_2,3);
    uVar6 = FUN_00105594(uVar6,1);
    iVar11 = thunk_FUN_00134de8(uVar16,uVar6);
    uVar6 = FUN_00105594(param_2,3);
    iVar10 = FUN_00105594(uVar6,1);
    iVar10 = *(int *)(iVar10 + 0x98);
  }
  if (((((iVar7 != 0) || (iVar9 != 0)) || (iVar10 != 0)) || ((iVar2 == iVar8 || (iVar8 == iVar11))))
     || (iVar2 == iVar11)) goto LAB_0019bee4;
  uVar3 = 0;
  if (iVar4 == 4) {
LAB_0019bed0:
    *(undefined1 *)((int)param_3 + 3) = uVar3;
  }
  else if (iVar4 == 0xb) {
    uVar3 = 1;
    goto LAB_0019bed0;
  }
  *(byte *)((int)param_3 + 3) = (byte)*param_3 | 0x80;
LAB_0019bee4:
  iVar2 = FUN_0019a538(*(undefined4 *)(param_1 + 0x88),param_2);
  if ((iVar2 != 0) && (bVar1)) {
    *(byte *)((int)param_3 + 3) = (byte)*param_3 | 0x40;
  }
  iVar2 = param_2[0x26];
  if ((iVar2 == 5) && (param_2[0x25] == 0)) {
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x58);
    iVar2 = param_2[0x26];
  }
  *param_3 = (*(uint *)(&DAT_001b2ad0 + iVar2 * 4) & 0xf) << 8 | *param_3 & 0xfffff0ff;
  iVar2 = FUN_00105dbc(param_2,0);
  if (iVar2 == 1) {
    *(undefined4 *)(param_1 + 0x24) = 1;
    *param_3 = *param_3 | 0x1000;
    uVar13 = FUN_00105c5c(param_2,0);
    uVar12 = *param_3;
  }
  else if (iVar2 == 2) {
    uVar13 = 0;
    *(undefined4 *)(param_1 + 0x24) = 1;
    uVar12 = *param_3 & 0x1fffffff | 0x20000000;
    *param_3 = uVar12;
  }
  else {
    uVar12 = *param_3;
    uVar13 = 0;
  }
  if (((uVar12 & 0xf00) == 0x200) || ((uVar12 & 0xf00) == 0x300)) {
    if (iVar2 == 0) {
      uVar13 = uVar13 + param_2[0x25];
    }
    else {
      uVar13 = uVar13 + *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x6c4) + 0x3f0);
    }
  }
  else if (iVar2 == 0) {
    iVar2 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),param_2);
    iVar4 = param_2[0x26];
    uVar13 = uVar13 + iVar2;
    if (iVar4 == 1) {
      piVar5 = *(int **)(*(int *)(param_1 + 0xc) + 0x30c);
      iVar2 = (**(code **)(*piVar5 + 0x138))(piVar5,0);
      uVar13 = uVar13 - iVar2;
      uVar6 = FUN_0019a2e0(*(undefined4 *)(param_1 + 0x38),uVar13);
      *(undefined4 *)(param_1 + 0x38) = uVar6;
      iVar4 = param_2[0x26];
    }
    if (iVar4 == 0) {
      uVar6 = FUN_0019a2e0(*(undefined4 *)(param_1 + 0x34),uVar13);
      *(undefined4 *)(param_1 + 0x34) = uVar6;
      uVar12 = *param_3;
    }
    else {
      uVar12 = *param_3;
    }
  }
  *param_3 = (uVar13 & 0x7f) << 0xd | uVar12 & 0xfff01fff;
  iVar2 = FUN_001054ec(param_2,0);
  uVar12 = *(uint *)(iVar2 + 0x10);
  uVar12 = (uint)((uVar12 & 0xff) == 0) << 0x17 |
           (uint)((uVar12 >> 8 & 0xff) == 0) << 0x16 |
           (uint)((uVar12 >> 0x10 & 0xff) == 0) << 0x15 |
           (uint)(uVar12 >> 0x18 == 0) << 0x14 | *param_3 & 0xff0fffff;
  *param_3 = uVar12;
  if (param_2[0x48] != 0) {
    iVar2 = FUN_0019a538(*(undefined4 *)(param_1 + 0x88),param_2);
    if ((iVar2 == 0) || (!bVar1)) {
      *param_3 = uVar12 | 0x1000000;
    }
    else {
      *param_3 = uVar12 | 0x2000000;
    }
  }
  return;
}

/* FUN_0019c130 @ 0x19c130 (2376 bytes) */
int FUN_0019c130(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int *piVar15;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  int iVar19;
  uint uVar20;
  uint *puVar21;
  uint local_88;
  uint local_84;
  int local_80;
  uint local_7c [4];
  uint local_6c [5];
  uint local_58;
  uint *local_54;
  
  puVar21 = (uint *)(param_3 + 8);
  if (((param_5 != 2) && (puVar21 = (uint *)(param_3 + 0xc), param_5 != 3)) &&
     (puVar21 = (uint *)0x0, param_5 == 1)) {
    puVar21 = (uint *)(param_3 + 4);
  }
  piVar11 = (int *)FUN_00105594(param_2,param_4);
  if (piVar11[0x26] == 0x33) {
    if (param_4 < 2) {
      *puVar21 = *puVar21 & 0xffffe018;
      *(undefined4 *)(param_1 + 0x80) = 1;
    }
    else {
      uVar7 = *puVar21;
      uVar20 = *(uint *)(param_3 + 4) & 7;
      *puVar21 = uVar20 | uVar7 & 0xfffffff8;
      uVar9 = *(uint *)(param_3 + 4) & 0x10;
      *puVar21 = uVar9 | uVar20 | uVar7 & 0xffffffe8;
      uVar13 = *(uint *)(param_3 + 4) & 0x80000000;
      *puVar21 = uVar13 | uVar9 | uVar20 | uVar7 & 0x7fffffe8;
      uVar10 = *(uint *)(param_3 + 4) & 0x60000000;
      *puVar21 = uVar10 | uVar13 | uVar9 | uVar20 | uVar7 & 0x1fffffe8;
      *puVar21 = *(uint *)(param_3 + 4) & 0x1fe0 |
                 uVar10 | uVar13 | uVar9 | uVar20 | uVar7 & 0x1fffe008;
    }
    iVar12 = FUN_001054ec(param_2,param_4);
    uVar20 = *(uint *)(iVar12 + 0x10);
    uVar9 = *(uint *)(param_4 * 0x18 + param_2 + 0xa0) & 1;
    iVar12 = FUN_0019a538(*(undefined4 *)(param_1 + 0x88),param_2);
    if (iVar12 != 0) {
      if (param_4 != 1) {
        uVar20 = uVar20 >> 0x18;
      }
      uVar13 = FUN_0019a6f0(piVar11,uVar20 & 0xff,&local_80);
      uVar7 = *puVar21;
      uVar13 = uVar13 & 7;
      uVar20 = uVar13 << 0xd;
      *puVar21 = uVar20 | uVar7 & 0xffff1fff;
      uVar10 = uVar9 ^ 1;
      if (local_80 == 0) {
        uVar10 = uVar9;
      }
      *puVar21 = uVar10 << 0x19 | uVar20 | uVar7 & 0xfdff1fff;
      *puVar21 = uVar10 << 0x1c |
                 uVar13 << 0x16 |
                 uVar10 << 0x1b |
                 uVar13 << 0x13 |
                 uVar10 << 0x1a | uVar13 << 0x10 | uVar10 << 0x19 | uVar20 | uVar7 & 0xe0001fff;
      return;
    }
    uVar13 = FUN_0019a6f0(piVar11,uVar20 >> 0x18,&local_80);
    uVar7 = *puVar21;
    uVar13 = (uVar13 & 7) << 0xd;
    *puVar21 = uVar13 | uVar7 & 0xffff1fff;
    uVar10 = uVar9 ^ 1;
    if (local_80 == 0) {
      uVar10 = uVar9;
    }
    *puVar21 = uVar10 << 0x19 | uVar13 | uVar7 & 0xfdff1fff;
    uVar13 = FUN_0019a6f0(piVar11,uVar20 >> 0x10 & 0xff,&local_80);
    uVar7 = *puVar21;
    uVar13 = (uVar13 & 7) << 0x10;
    *puVar21 = uVar13 | uVar7 & 0xfff8ffff;
    uVar10 = uVar9 ^ 1;
    if (local_80 == 0) {
      uVar10 = uVar9;
    }
    *puVar21 = uVar10 << 0x1a | uVar13 | uVar7 & 0xfbf8ffff;
    uVar13 = FUN_0019a6f0(piVar11,uVar20 >> 8 & 0xff,&local_80);
    uVar7 = *puVar21;
    uVar13 = (uVar13 & 7) << 0x13;
    *puVar21 = uVar13 | uVar7 & 0xffc7ffff;
    uVar10 = uVar9 ^ 1;
    if (local_80 == 0) {
      uVar10 = uVar9;
    }
    *puVar21 = uVar10 << 0x1b | uVar13 | uVar7 & 0xf7c7ffff;
    uVar20 = FUN_0019a6f0(piVar11,uVar20 & 0xff,&local_80);
    uVar10 = *puVar21;
    uVar20 = (uVar20 & 7) << 0x16;
    *puVar21 = uVar20 | uVar10 & 0xfe3fffff;
    uVar13 = uVar9 ^ 1;
    if (local_80 == 0) {
      uVar13 = uVar9;
    }
    *puVar21 = uVar13 << 0x1c | uVar20 | uVar10 & 0xee3fffff;
    return;
  }
  iVar12 = (**(code **)(*piVar11 + 0x60))();
  if (iVar12 == 0) {
    iVar12 = FUN_00105dbc(param_2,param_4);
    iVar14 = piVar11[0x26];
    uVar18 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    piVar15 = piVar11;
LAB_0019c490:
    uVar20 = thunk_FUN_00134de8(uVar18,piVar15);
    *puVar21 = *(uint *)(&DAT_001b2c14 + iVar14 * 4) & 7 | *puVar21 & 0xfffffff8;
    if (iVar14 == 0x37) {
      *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x58);
    }
    else if (iVar14 == 1) {
      piVar15 = *(int **)(*(int *)(param_1 + 0xc) + 0x30c);
      iVar16 = (**(code **)(*piVar15 + 0x138))(piVar15,0);
      uVar20 = uVar20 - iVar16;
    }
  }
  else {
    iVar12 = FUN_00105dbc(piVar11,1);
    iVar14 = FUN_00105594(piVar11,1);
    iVar14 = *(int *)(iVar14 + 0x98);
    if (iVar14 != 0x33) {
      uVar18 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
      piVar15 = (int *)FUN_00105594(piVar11,1);
      goto LAB_0019c490;
    }
    if (param_4 < 2) {
      uVar20 = 0;
      *puVar21 = *puVar21 & 0xfffffff8;
      *(undefined4 *)(param_1 + 0x80) = 1;
    }
    else {
      uVar7 = *puVar21;
      uVar9 = *(uint *)(param_3 + 4) & 7;
      *puVar21 = uVar9 | uVar7 & 0xfffffff8;
      uVar13 = *(uint *)(param_3 + 4) & 0x10;
      uVar20 = *(uint *)(param_3 + 4) >> 5 & 0xff;
      *puVar21 = uVar13 | uVar9 | uVar7 & 0xffffffe8;
      uVar10 = *(uint *)(param_3 + 4) & 0x80000000;
      *puVar21 = uVar10 | uVar13 | uVar9 | uVar7 & 0x7fffffe8;
      *puVar21 = *(uint *)(param_3 + 4) & 0x60000000 | uVar10 | uVar13 | uVar9 | uVar7 & 0x1fffffe8;
    }
  }
  iVar16 = FUN_00126708(piVar11[0x26]);
  iVar17 = (**(code **)(*piVar11 + 0x60))(piVar11);
  if (iVar17 != 0) {
    iVar16 = FUN_00105594(piVar11,1);
    if (iVar16 == 0) {
      iVar16 = piVar11[0x2c];
    }
    else {
      iVar16 = FUN_00105594(piVar11,1);
      iVar16 = *(int *)(iVar16 + 0x98);
    }
    iVar16 = FUN_00126708(iVar16);
  }
  if ((iVar16 != 0) && (*(uint *)(param_1 + 0x4c) < uVar20)) {
    *(uint *)(param_1 + 0x4c) = uVar20;
  }
  if (iVar12 - 1U < 2) {
    iVar12 = (**(code **)(*piVar11 + 0x60))(piVar11);
    if (iVar12 == 0) {
      uVar20 = FUN_00105c5c(param_2,param_4);
    }
    else {
      uVar20 = FUN_00105c5c(piVar11,1);
    }
    *(undefined4 *)(param_1 + 0x24) = 1;
    if (iVar14 == 0x28) {
      *(undefined4 *)(param_1 + 0x4c) = 0xff;
    }
    else if (iVar14 != 0x29) {
      if (iVar14 == 0x26) {
        *(undefined4 *)(param_1 + 0x4c) = 0xff;
        *puVar21 = *puVar21 | 0x10;
        iVar12 = (**(code **)(*piVar11 + 0x60))(piVar11);
        if (iVar12 == 0) {
          iVar12 = FUN_001054ec(piVar11,1);
          uVar18 = *(undefined4 *)(iVar12 + 0x10);
        }
        else {
          uVar18 = FUN_00105594(piVar11,1);
          iVar12 = FUN_001054ec(uVar18,1);
          uVar18 = *(undefined4 *)(iVar12 + 0x10);
        }
        iVar12 = FUN_000f2d18(uVar18,DAT_001b2d38);
        if (iVar12 != 0) {
          uVar9 = *puVar21 & 0x9fffffff;
          *puVar21 = uVar9;
          goto LAB_0019c710;
        }
        iVar12 = FUN_000f2d18(uVar18,DAT_001b2d34);
        if (iVar12 != 0) {
          uVar9 = *puVar21 & 0x9fffffff | 0x20000000;
          *puVar21 = uVar9;
          goto LAB_0019c710;
        }
        iVar12 = FUN_000f2d18(uVar18,DAT_001b2d30);
        if (iVar12 != 0) {
          uVar9 = *puVar21 & 0x9fffffff | 0x40000000;
          *puVar21 = uVar9;
          goto LAB_0019c710;
        }
        iVar12 = FUN_000f2d18(uVar18,DAT_001b2d2c);
        if (iVar12 != 0) {
          uVar9 = *puVar21 & 0x9fffffff | 0x60000000;
          *puVar21 = uVar9;
          goto LAB_0019c710;
        }
      }
      goto LAB_0019c70c;
    }
    uVar9 = *puVar21 & 0x9fffffff | 0x80000000;
    *puVar21 = uVar9;
  }
  else {
LAB_0019c70c:
    uVar9 = *puVar21;
  }
LAB_0019c710:
  *puVar21 = (uVar20 & 0xff) << 5 | uVar9 & 0xffffe01f;
  uVar20 = *(uint *)(param_4 * 0x18 + param_2 + 0xa0) & 1;
  iVar12 = FUN_001054ec(param_2,param_4);
  local_88 = *(uint *)(iVar12 + 0x10);
  iVar12 = (**(code **)(*piVar11 + 0x60))(piVar11);
  if (iVar12 == 0) {
    local_7c[0] = *(uint *)(&DAT_001b2be8 + (local_88 >> 0x18) * 4);
    local_7c[2] = *(uint *)(&DAT_001b2be8 + (local_88 >> 8 & 0xff) * 4);
    local_7c[3] = *(uint *)(&DAT_001b2be8 + (local_88 & 0xff) * 4);
    local_7c[1] = *(uint *)(&DAT_001b2be8 + (local_88 >> 0x10 & 0xff) * 4);
    local_6c[0] = uVar20;
    local_6c[1] = uVar20;
    local_6c[2] = uVar20;
    local_6c[3] = uVar20;
  }
  else {
    iVar12 = FUN_001054ec(piVar11,1);
    local_84 = local_88;
    FUN_000f2bdc(&local_58,*(undefined4 *)(iVar12 + 0x10),local_88);
    local_88 = local_58;
    iVar16 = 0;
    iVar12 = 0;
    local_54 = local_7c;
    do {
      bVar3 = *(byte *)((int)&local_84 + iVar16);
      if (bVar3 != 4) {
        if ((iVar14 == 0x33) || (bVar4 = *(byte *)((int)&local_88 + iVar16), bVar4 == 4)) {
          if (0 < piVar11[0x21]) {
            iVar17 = 1;
            do {
              iVar19 = FUN_001054ec(piVar11,iVar17);
              cVar2 = *(char *)((uint)bVar3 + iVar19 + 0x10);
              if (cVar2 != '\x04') {
                uVar18 = FUN_00105594(piVar11,iVar17);
                uVar18 = FUN_0019a6f0(uVar18,cVar2,&local_80);
                *(undefined4 *)(iVar12 + (int)local_54) = uVar18;
                uVar9 = uVar20;
                if (local_80 != 0) {
                  uVar9 = (uint)(uVar20 == 0);
                }
                *(uint *)((int)local_6c + iVar12) = uVar9;
                break;
              }
              iVar17 = iVar17 + 1;
            } while (iVar17 <= piVar11[0x21]);
          }
        }
        else {
          *(uint *)((int)local_6c + iVar12) = uVar20;
          *(undefined4 *)(iVar12 + (int)local_7c) = *(undefined4 *)(&DAT_001b2be8 + (uint)bVar4 * 4)
          ;
        }
      }
      bVar1 = iVar16 != 3;
      iVar12 = iVar12 + 4;
      iVar16 = iVar16 + 1;
    } while (bVar1);
  }
  iVar12 = FUN_0019a538(*(undefined4 *)(param_1 + 0x88),param_2);
  if (iVar12 == 0) {
    uVar8 = *puVar21;
    uVar20 = (local_7c[0] & 7) << 0xd;
    *puVar21 = uVar20 | uVar8 & 0xffff1fff;
    uVar9 = (local_7c[1] & 7) << 0x10;
    *puVar21 = uVar9 | uVar20 | uVar8 & 0xfff81fff;
    uVar13 = (local_7c[2] & 7) << 0x13;
    *puVar21 = uVar13 | uVar9 | uVar20 | uVar8 & 0xffc01fff;
    uVar10 = (local_7c[3] & 7) << 0x16;
    *puVar21 = uVar10 | uVar13 | uVar9 | uVar20 | uVar8 & 0xfe001fff;
    uVar7 = (local_6c[0] & 1) << 0x19;
    *puVar21 = uVar7 | uVar10 | uVar13 | uVar9 | uVar20 | uVar8 & 0xfc001fff;
    uVar5 = (local_6c[1] & 1) << 0x1a;
    *puVar21 = uVar5 | uVar7 | uVar10 | uVar13 | uVar9 | uVar20 | uVar8 & 0xf8001fff;
    uVar6 = (local_6c[2] & 1) << 0x1b;
    *puVar21 = uVar6 | uVar5 | uVar7 | uVar10 | uVar13 | uVar9 | uVar20 | uVar8 & 0xf0001fff;
    uVar20 = (local_6c[3] & 1) << 0x1c |
             uVar6 | uVar5 | uVar7 | uVar10 | uVar13 | uVar9 | uVar20 | uVar8 & 0xe0001fff;
    *puVar21 = uVar20;
  }
  else {
    if (param_4 == 1) {
      uVar9 = *puVar21;
      uVar20 = (local_7c[3] & 7) << 0xd;
      *puVar21 = uVar20 | uVar9 & 0xffff1fff;
      uVar20 = (local_6c[3] & 1) << 0x19 | uVar20 | uVar9 & 0xfdff1fff;
      *puVar21 = uVar20;
    }
    else if (param_4 == 2) {
      uVar9 = *puVar21;
      uVar20 = (local_7c[0] & 7) << 0xd;
      *puVar21 = uVar20 | uVar9 & 0xffff1fff;
      uVar20 = (local_6c[0] & 1) << 0x19 | uVar20 | uVar9 & 0xfdff1fff;
      *puVar21 = uVar20;
    }
    else {
      uVar20 = *puVar21;
    }
    uVar20 = (uVar20 & 0x2000000) << 3 |
             (uVar20 & 0x2000000) << 2 |
             (uVar20 & 0x2000000) << 1 |
             (uVar20 & 0xe000) << 9 |
             (uVar20 & 0xe000) << 6 | (uVar20 & 0xe000) << 3 | uVar20 & 0xe200ffff;
    *puVar21 = uVar20;
  }
  if ((*(int *)(param_1 + 0x84) != 0) && ((uVar20 & 0x80000010) == 0)) {
    uVar9 = *(uint *)(param_3 + 0xc);
    *(uint *)(param_3 + 0xc) = uVar20 & 3 | uVar9 & 0xfffffffc;
    *(uint *)(param_3 + 0xc) = *puVar21 & 0x1fe0 | uVar20 & 3 | uVar9 & 0xffffe01c;
  }
  if ((*(int *)(param_1 + 0x80) != 0) && (param_4 == 2)) {
    uVar10 = *(uint *)(param_3 + 4);
    uVar20 = *puVar21 & 7;
    *(uint *)(param_3 + 4) = uVar20 | uVar10 & 0xfffffff8;
    uVar9 = *puVar21 & 0x1fe0;
    *(uint *)(param_3 + 4) = uVar9 | uVar20 | uVar10 & 0xffffe018;
    uVar13 = *puVar21 & 0x10;
    *(uint *)(param_3 + 4) = uVar13 | uVar9 | uVar20 | uVar10 & 0xffffe008;
    uVar7 = *puVar21;
    *(uint *)(param_3 + 4) = uVar7 & 0x80000000 | uVar13 | uVar9 | uVar20 | uVar10 & 0x7fffe008;
    *(uint *)(param_3 + 4) =
         *puVar21 & 0x60000000 | uVar7 & 0x80000000 | uVar13 | uVar9 | uVar20 | uVar10 & 0x1fffe008;
  }
  return;
}

/* FUN_0019ca78 @ 0x19ca78 (1916 bytes) */
int FUN_0019ca78(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  uint *param_3;
{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  uint *puVar10;
  undefined4 uVar11;
  int local_48 [4];
  uint local_38;
  uint local_34 [2];
  
  puVar10 = param_3 + 3;
  *param_3 = *param_3 | 0x10000000;
  FUN_00105dbc(param_2,1);
  iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
  if (iVar3 == 2) {
    FUN_00105dbc(param_2,2);
  }
  piVar4 = (int *)FUN_00105594(param_2,1);
  iVar3 = (**(code **)(*piVar4 + 0x60))();
  if (iVar3 == 0) {
    iVar3 = piVar4[0x26];
  }
  else {
    iVar3 = FUN_00105594(piVar4,1);
    iVar3 = *(int *)(iVar3 + 0x98);
  }
  if (iVar3 == 0x37) {
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x58);
  }
  iVar5 = (**(code **)(*piVar4 + 0x60))(piVar4);
  if (iVar5 == 0) {
    uVar7 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),piVar4);
  }
  else {
    uVar11 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = FUN_00105594(piVar4,1);
    uVar7 = thunk_FUN_00134de8(uVar11,uVar6);
  }
  if (iVar3 == 1) {
    piVar8 = *(int **)(*(int *)(param_1 + 0xc) + 0x30c);
    iVar5 = (**(code **)(*piVar8 + 0x138))(piVar8,0);
    uVar7 = uVar7 - iVar5;
    uVar6 = FUN_0019a2e0(*(undefined4 *)(param_1 + 0x38),uVar7);
    *(undefined4 *)(param_1 + 0x38) = uVar6;
  }
  else if (iVar3 == 0) {
    uVar6 = FUN_0019a2e0(*(undefined4 *)(param_1 + 0x34),uVar7);
    *(undefined4 *)(param_1 + 0x34) = uVar6;
  }
  uVar2 = param_2[0x2e];
  if ((uVar2 & 2) == 0) {
    uVar9 = *puVar10;
  }
  else {
    uVar9 = *puVar10 | 8;
    *puVar10 = uVar9;
    uVar2 = param_2[0x2e];
  }
  if ((uVar2 & 1) != 0) {
    uVar9 = uVar9 | 0x2000000;
    *puVar10 = uVar9;
  }
  if ((param_2[0x34] & 1U) != 0) {
    uVar9 = uVar9 | 0x4000000;
    *puVar10 = uVar9;
  }
  if (piVar4[0x26] == 0x33) {
    uVar7 = param_3[1];
    if ((uVar7 & 0x80000010) == 0) {
      *puVar10 = uVar7 & 3 | uVar9 & 0xfffffffc;
      *puVar10 = param_3[1] & 0x1fe0 | uVar7 & 3 | uVar9 & 0xffffe01c;
    }
    else {
      uVar2 = param_3[2];
      if ((uVar2 & 0x80000010) == 0) {
        *puVar10 = uVar2 & 3 | uVar9 & 0xfffffffc;
        *puVar10 = param_3[2] & 0x1fe0 | uVar2 & 3 | uVar9 & 0xffffe01c;
      }
      else if (((uVar7 & 7) == 0) && ((uVar2 & 7) == 0)) {
        *puVar10 = uVar9 & 0xffffe01c | 2;
      }
      else {
        *puVar10 = uVar9 & 0xffffe01c;
      }
    }
    *(undefined4 *)(param_1 + 0x84) = 1;
    iVar3 = FUN_001054ec(param_2,1);
    uVar7 = FUN_0019a6f0(piVar4,*(undefined1 *)(iVar3 + 0x13),local_48);
    uVar2 = *puVar10;
    uVar7 = (uVar7 & 7) << 0xd;
    *puVar10 = uVar7 | uVar2 & 0xffff1fff;
    uVar9 = uVar2 >> 0x19 & 1;
    if (local_48[0] != 0) {
      uVar9 = 1 - uVar9;
    }
    *puVar10 = (uVar9 & 1) << 0x19 | uVar7 | uVar2 & 0xfdff1fff;
    iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
    if (1 < iVar3) {
      uVar6 = FUN_00105594(param_2,2);
      iVar3 = FUN_001054ec(param_2,2);
      uVar7 = FUN_0019a6f0(uVar6,*(undefined1 *)(iVar3 + 0x10),local_48);
      uVar2 = *puVar10;
      uVar7 = (uVar7 & 7) << 0x10;
      *puVar10 = uVar7 | uVar2 & 0xfff8ffff;
      uVar9 = uVar2 >> 0x1a & 1;
      if (local_48[0] != 0) {
        uVar9 = 1 - uVar9;
      }
      *puVar10 = (uVar9 & 1) << 0x1a | uVar7 | uVar2 & 0xfbf8ffff;
    }
    goto LAB_0019d024;
  }
  *puVar10 = *(uint *)(&DAT_001b2c14 + iVar3 * 4) & 3 | uVar9 & 0xfffffffc;
  iVar3 = (**(code **)(*piVar4 + 0x60))(piVar4);
  if (iVar3 == 0) {
    iVar3 = FUN_00126708(piVar4[0x26]);
  }
  else {
    iVar3 = FUN_00105594(piVar4,1);
    iVar3 = FUN_00126708(*(undefined4 *)(iVar3 + 0x98));
  }
  if ((iVar3 != 0) && (*(uint *)(param_1 + 0x4c) < uVar7)) {
    *(uint *)(param_1 + 0x4c) = uVar7;
  }
  *puVar10 = (uVar7 & 0xff) << 5 | *puVar10 & 0xffffe01f;
  iVar3 = FUN_001054ec(param_2,1);
  uVar2 = *(uint *)(iVar3 + 0x10);
  iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
  uVar7 = uVar2;
  if (1 < iVar3) {
    iVar3 = FUN_001054ec(param_2,2);
    uVar7 = *(uint *)(iVar3 + 0x10);
  }
  iVar3 = (**(code **)(*piVar4 + 0x60))(piVar4);
  if (iVar3 == 0) {
    iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar3 < 2) {
      uVar2 = *(uint *)(&DAT_001b2be8 + (uVar2 & 0xff) * 4);
      uVar7 = uVar2;
    }
    else {
      uVar2 = *(uint *)(&DAT_001b2be8 + (uVar2 & 0xff) * 4);
      uVar7 = *(uint *)(&DAT_001b2be8 + (uVar7 >> 0x16 & 0x3fc));
    }
  }
  else {
    iVar3 = FUN_001054ec(piVar4,1);
    uVar6 = *(undefined4 *)(iVar3 + 0x10);
    FUN_000f2bdc(&local_38,uVar6,uVar2);
    if (((uVar2 & 0xff) == 4) || ((local_38 & 0xff) == 4)) {
      iVar3 = 1;
      if (0 < piVar4[0x21]) {
        do {
          iVar5 = FUN_001054ec(piVar4,iVar3);
          cVar1 = *(char *)(iVar5 + 0x13);
          if (cVar1 != '\x04') {
            uVar11 = FUN_00105594(piVar4,iVar3);
            uVar2 = FUN_0019a6f0(uVar11,cVar1,local_48);
            goto LAB_0019cf10;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 <= piVar4[0x21]);
      }
      uVar2 = 0;
    }
    else {
      uVar2 = *(uint *)(&DAT_001b2be8 + (local_38 & 0xff) * 4);
    }
LAB_0019cf10:
    iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
    if (1 < iVar3) {
      FUN_000f2bdc(local_34,uVar6,uVar7);
      if ((uVar7 >> 0x18 != 4) && (local_34[0] >> 0x18 != 4)) {
        uVar7 = *(uint *)(&DAT_001b2be8 + (local_34[0] >> 0x18) * 4);
        goto LAB_0019d014;
      }
      iVar3 = 1;
      if (0 < piVar4[0x21]) {
        do {
          iVar5 = FUN_001054ec(piVar4,iVar3);
          cVar1 = *(char *)(iVar5 + 0x10);
          if (cVar1 != '\x04') {
            uVar6 = FUN_00105594(piVar4,iVar3);
            uVar7 = FUN_0019a6f0(uVar6,cVar1,local_48);
            goto LAB_0019d014;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 <= piVar4[0x21]);
      }
    }
    uVar7 = 0;
  }
LAB_0019d014:
  *puVar10 = (uVar7 & 7) << 0x10 | (uVar2 & 7) << 0xd | *puVar10 & 0xfff81fff;
LAB_0019d024:
  iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 0xc) + 0x30c) + 0x16c))();
  uVar7 = *(uint *)(*(int *)(param_2[0x22] + 8) * 0x38 + iVar3 + 0xc);
  if (uVar7 == 0xffffffff) {
    if (*(int *)(param_2[0x22] + 8) == 0x66) {
      *puVar10 = *puVar10 & 0xfe18ffff | 0x1450000;
    }
  }
  else {
    uVar2 = (uVar7 & 0xf) << 0x15 | *puVar10 & 0xfe1fffff;
    *puVar10 = uVar2;
    if (0xf < (int)uVar7) {
      *puVar10 = uVar2 | 4;
    }
  }
  iVar3 = FUN_001054ec(param_2,0);
  iVar3 = *(int *)(iVar3 + 0x10);
  if (iVar3 == DAT_001b2c10) {
    *puVar10 = *puVar10 & 0xe7ffffff;
  }
  else if (iVar3 == DAT_001b2c0c) {
    *puVar10 = *puVar10 & 0xe7ffffff | 0x8000000;
  }
  else if (iVar3 == DAT_001b2c08) {
    *puVar10 = *puVar10 & 0xe7ffffff | 0x10000000;
  }
  else if (iVar3 == DAT_001b2c04) {
    *puVar10 = *puVar10 & 0xe7ffffff | 0x18000000;
  }
  iVar3 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),param_2);
  piVar4 = *(int **)(*(int *)(param_1 + 0xc) + 0x30c);
  iVar5 = (**(code **)(*piVar4 + 0x138))(piVar4,0);
  *puVar10 = (iVar3 - iVar5) * 0x80000 & 0x180000U | *puVar10 & 0xffe7ffff;
  if (param_2[0x48] != 0) {
    (**(code **)(**(int **)(*(int *)(param_1 + 0xc) + 0x30c) + 0x80))();
    *param_3 = *param_3 | 0x2000000;
  }
  return;
}

/* FUN_0019d1f4 @ 0x19d1f4 (572 bytes) */
int FUN_0019d1f4(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = *(int *)(param_1 + 8);
  iVar1 = *(int *)(param_1 + 0x58) * 8;
  if (*(int *)(iVar2 + iVar1) == 0) {
    *(int **)(iVar2 + iVar1) = param_2;
  }
  else {
    *(int **)(iVar2 + iVar1 + 4) = param_2;
  }
  puVar3 = (uint *)(*(int *)(param_1 + 0x58) * 0x10 + *(int *)(param_1 + 0x44));
  iVar1 = FUN_0019a538(*(undefined4 *)(param_1 + 0x88),param_2);
  if ((iVar1 == 0) || (*(int *)(param_1 + 0x7c) == 0)) {
    *(undefined4 *)(param_1 + 0x84) = 0;
    *(undefined4 *)(param_1 + 0x80) = 0;
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
    if (0 < iVar1) {
      ((int (*)())FUN_0019c130)(param_1,param_2,puVar3,1,1);
    }
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar1 < 2) {
      FUN_0019a7b0(puVar3,1,2);
    }
    else {
      ((int (*)())FUN_0019c130)(param_1,param_2,puVar3,2,2);
    }
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar1 < 3) {
      if (*(int *)(param_1 + 0x7c) == 0) {
        FUN_0019a7b0(puVar3,2,3);
      }
    }
    else {
      ((int (*)())FUN_0019c130)(param_1,param_2,puVar3,3,3);
    }
    ((int (*)())FUN_0019baf4)(param_1,param_2,puVar3);
  }
  else {
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
    if (1 < iVar1) {
      FUN_00105594(param_2,1);
      FUN_00105594(param_2,2);
    }
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
    if (0 < iVar1) {
      iVar1 = FUN_001054ec(param_2,1);
      FUN_000f2c5c(*(undefined4 *)(iVar1 + 0x10));
    }
    ((int (*)())FUN_0019ca78)(param_1,param_2,puVar3);
  }
  if (param_2[0x47] == 2) {
    *puVar3 = *puVar3 & 0xf7ffffff | 0x4000000;
  }
  else if (param_2[0x47] == 3) {
    *puVar3 = *puVar3 | 0xc000000;
  }
  return;
}

/* FUN_0019d430 @ 0x19d430 (68 bytes) */
int FUN_0019d430(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x8c) < 0) {
    uVar1 = FUN_00130690(param_2,0);
    *(undefined4 *)(param_1 + 0x8c) = uVar1;
  }
  return;
}

/* FUN_0019d4e8 @ 0x19d4e8 (136 bytes) */
int FUN_0019d4e8(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(param_1 + 0x90);
  if (iVar1 == 0) {
    uVar2 = FUN_00130690(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),0);
    uVar4 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x378);
    puVar3 = (undefined4 *)FUN_00193e18(uVar4,0x168);
    *puVar3 = uVar4;
    FUN_00109554(puVar3 + 1,*(undefined4 *)(param_1 + 0xc));
    *(undefined4 **)(param_1 + 0x90) = puVar3 + 1;
    puVar3[0x27] = 0;
    puVar3[0x26] = uVar2;
    iVar1 = *(int *)(param_1 + 0x90);
  }
  return iVar1;
}

/* FUN_0019d590 @ 0x19d590 (528 bytes) */
int FUN_0019d590(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint *puVar9;
  
  iVar8 = param_2[0x4e];
  iVar4 = FUN_00194034(iVar8 + 0x90);
  if ((iVar4 < 3) && (iVar4 = FUN_000e79e8(iVar8), iVar4 != 0)) {
    piVar7 = (int *)0x0;
    if (*(int *)(*(int *)(iVar8 + 0xd0) + 4) != 0) {
      piVar7 = *(int **)(*(int *)(iVar8 + 0xd0) + 8);
    }
    if (*piVar7 == param_2[0x4f]) {
      return;
    }
  }
  iVar4 = (**(code **)(*param_2 + 0x40))(param_2);
  if (iVar4 == 0) {
    if ((param_2[0x51] == 0) || (*(int *)(*(int *)(param_1 + 0x94) + 4) != 2)) {
      if (**(int **)(param_4 + 0x6c4) == 0) {
        piVar7 = (int *)FUN_001043f0(0x57,param_4);
        iVar6 = ((int (*)())FUN_0019d4e8)(param_1);
        iVar4 = DAT_001b2d50;
        piVar7[0x25] = *(int *)(iVar6 + 0x94);
        piVar7[0x27] = iVar4;
        piVar7[0x26] = 0;
        FUN_00106004(piVar7,1,iVar6,0,param_4);
        uVar1 = DAT_001b2d4c;
        iVar4 = FUN_001054ec(piVar7,1);
        *(undefined4 *)(iVar4 + 0x10) = uVar1;
        (**(code **)(*piVar7 + 0x84))(piVar7,0);
        FUN_000e76c4(iVar8,piVar7);
        return;
      }
    }
    else {
      FUN_00194208(*(int *)(param_1 + 0x94),1);
      puVar9 = *(uint **)(param_1 + 0x94);
      uVar2 = puVar9[1];
      if (uVar2 < *puVar9) {
        _memset((void *)(uVar2 * 4 + puVar9[2]),0,4);
        puVar5 = (undefined4 *)(uVar2 * 4 + puVar9[2]);
        puVar9[1] = uVar2 + 1;
      }
      else {
        puVar5 = (undefined4 *)FUN_0019423c(puVar9,uVar2);
      }
      *puVar5 = 2;
    }
  }
  else {
    piVar7 = (int *)0x0;
    iVar4 = *(int *)(*(int *)(param_1 + 0x10) + 0x24);
    uVar3 = *(uint *)(iVar4 + 4);
    uVar2 = uVar3 - 1;
    if (uVar2 < uVar3) {
      piVar7 = (int *)(uVar2 * 4 + *(int *)(iVar4 + 8));
    }
    iVar4 = *piVar7;
    FUN_0019a568(param_1,4);
    *(int *)(iVar4 + 0x14) = *(int *)(param_1 + 0x58) + -2;
  }
  return;
}

/* FUN_0019d7a0 @ 0x19d7a0 (184 bytes) */
int FUN_0019d7a0(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (**(int **)(param_2 + 0xac) == 0) {
    iVar1 = ((int (*)())FUN_0019d4e8)();
    iVar3 = *(int *)(iVar1 + 0x94);
    piVar2 = (int *)FUN_001043f0(0x59,param_4);
    iVar1 = DAT_001b2d50;
    piVar2[0x25] = iVar3;
    piVar2[0x26] = 0;
    piVar2[0x27] = iVar1;
    (**(code **)(*piVar2 + 0x84))(piVar2,3);
    FUN_000e7688(param_2,piVar2);
  }
                    
                    
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  return;
}

/* FUN_0019dc48 @ 0x19dc48 (104 bytes) */
int FUN_0019dc48(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0xa0);
  uVar1 = FUN_000e7d5c(*(undefined4 *)(param_2 + 300));
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,uVar1);
  return;
}

/* FUN_0019dd7c @ 0x19dd7c (180 bytes) */
int FUN_0019dd7c(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_0019acb0)();
  *(undefined4 *)(param_1 + 0x8c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x90) = 0;
  uVar2 = *(undefined4 *)(param_4 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[1] = 2;
  puVar1[4] = uVar2;
  puVar1[2] = 0;
  uVar2 = FUN_00193e18(uVar2,8);
  puVar1[3] = uVar2;
  *(undefined4 **)(param_1 + 0x98) = puVar1 + 1;
  uVar2 = *(undefined4 *)(param_4 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[1] = 2;
  puVar1[2] = 0;
  puVar1[4] = uVar2;
  uVar2 = FUN_00193e18(uVar2,8);
  puVar1[3] = uVar2;
  *(undefined4 **)(param_1 + 0x94) = puVar1 + 1;
  return;
}

/* FUN_0019deb0 @ 0x19deb0 (144 bytes) */
int FUN_0019deb0(param_1)
  undefined4 *param_1;
{
  int iVar1;
  
  iVar1 = param_1[0x26];
  *param_1 = &PTR_FUN_001eb8d8;
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x25];
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  ((int (*)())FUN_0019b91c)(param_1);
  return;
}

/* FUN_0019df54 @ 0x19df54 (144 bytes) */
int FUN_0019df54(param_1)
  undefined4 *param_1;
{
  int iVar1;
  
  iVar1 = param_1[0x26];
  *param_1 = &PTR_FUN_001eb8d8;
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x25];
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  ((int (*)())FUN_0019b91c)(param_1);
  return;
}

/* FUN_0019dff8 @ 0x19dff8 (292 bytes) */
int FUN_0019dff8(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  piVar5 = *(int **)(param_2 + 0xac);
  FUN_00194208(param_1[0x25],*(int *)(param_1[0x25] + 4) + -1);
  if (*piVar5 == 0) {
    piVar5 = (int *)0x0;
    uVar3 = *(uint *)(param_1[0x25] + 4);
    uVar2 = uVar3 - 1;
    if (uVar2 < uVar3) {
      piVar5 = (int *)(uVar2 * 4 + *(int *)(param_1[0x25] + 8));
    }
    iVar6 = *piVar5;
    FUN_000e2bf4(param_3,iVar6);
    if (iVar6 != 0) {
      iVar6 = FUN_001043f0(0x58,param_4);
      iVar4 = ((int (*)())FUN_0019d4e8)(param_1);
      uVar1 = DAT_001b2d50;
      *(undefined4 *)(iVar6 + 0x94) = *(undefined4 *)(iVar4 + 0x94);
      *(undefined4 *)(iVar6 + 0x98) = 0;
      *(undefined4 *)(iVar6 + 0x9c) = uVar1;
      FUN_00106004(iVar6,1,iVar4,0,param_4);
      uVar1 = DAT_001b2d4c;
      iVar4 = FUN_001054ec(iVar6,1);
      *(undefined4 *)(iVar4 + 0x10) = uVar1;
      FUN_000e76c4(param_2,iVar6);
    }
  }
                    
                    
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  return;
}

/* FUN_0019e660 @ 0x19e660 (128 bytes) */
int FUN_0019e660(param_1)
  int param_1;
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  
  ((int (*)())FUN_0019adf8)();
  puVar3 = *(uint **)(param_1 + 0x94);
  uVar2 = puVar3[1];
  if (uVar2 < *puVar3) {
    _memset((void *)(uVar2 * 4 + puVar3[2]),0,4);
    puVar1 = (undefined4 *)(uVar2 * 4 + puVar3[2]);
    puVar3[1] = uVar2 + 1;
  }
  else {
    puVar1 = (undefined4 *)FUN_0019423c(puVar3,uVar2);
  }
  *puVar1 = 0;
  return;
}

/* FUN_0019e6e0 @ 0x19e6e0 (688 bytes) */
int FUN_0019e6e0(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  code *UNRECOVERED_JUMPTABLE;
  uint *puVar9;
  int iVar10;
  double dVar11;
  
  piVar8 = *(int **)(param_2 + 0xac);
  if ((0 < *(int *)(param_2 + 0x138)) || (*(int *)(param_2 + 0x13c) != 0)) {
    iVar3 = ((int (*)())FUN_0019d4e8)();
    puVar9 = (uint *)param_1[0x25];
    uVar7 = *(undefined4 *)(iVar3 + 0x94);
    piVar6 = (int *)0x0;
    uVar2 = puVar9[1] - 1;
    if (uVar2 < puVar9[1]) {
      piVar6 = (int *)(uVar2 * 4 + puVar9[2]);
    }
    if (*piVar6 == 0) {
      if (*piVar8 == 0) {
        iVar3 = FUN_001043f0(0x53,param_4);
        uVar1 = DAT_001b2d50;
        dVar11 = (double)FLOAT_001aa0d4;
        *(undefined4 *)(iVar3 + 0x94) = uVar7;
        *(undefined4 *)(iVar3 + 0x9c) = uVar1;
        *(undefined4 *)(iVar3 + 0x98) = 0;
        FUN_000f79c4(dVar11,dVar11,dVar11,dVar11,iVar3,piVar8,1);
        *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffffffb;
        FUN_000e7688(param_2,iVar3);
        puVar9 = (uint *)param_1[0x25];
      }
    }
    else if (*piVar8 == 0) {
      iVar10 = *(int *)(param_1[0x26] + 4);
      if (2 < iVar10) {
        if (iVar10 < 7) {
          uVar7 = FUN_00130690(piVar8,0);
          iVar10 = iVar10 + -3;
        }
        else {
          uVar7 = 0;
          iVar10 = 0;
        }
      }
      iVar4 = FUN_001084b8(0x66,param_4);
      *(undefined4 *)(iVar4 + 0x9c) = DAT_001b2d54;
      *(undefined1 *)(iVar10 + iVar4 + 0x9c) = 0;
      *(undefined4 *)(iVar4 + 0x98) = 0;
      *(undefined4 *)(iVar4 + 0x94) = uVar7;
      FUN_00106004(iVar4,1,iVar3,0,param_4);
      uVar7 = DAT_001b2d4c;
      iVar3 = FUN_001054ec(iVar4,1);
      *(undefined4 *)(iVar3 + 0x10) = uVar7;
      *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) & 0xfffffffb;
      FUN_000e7688(param_2,iVar4);
      puVar9 = (uint *)param_1[0x26];
      uVar2 = puVar9[1];
      if (uVar2 < *puVar9) {
        _memset((void *)(uVar2 * 4 + puVar9[2]),0,4);
        piVar8 = (int *)(uVar2 * 4 + puVar9[2]);
        puVar9[1] = uVar2 + 1;
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar9,uVar2);
      }
      *piVar8 = iVar4;
      puVar9 = (uint *)param_1[0x25];
    }
    uVar2 = puVar9[1];
    if (uVar2 < *puVar9) {
      _memset((void *)(uVar2 * 4 + puVar9[2]),0,4);
      puVar5 = (undefined4 *)(uVar2 * 4 + puVar9[2]);
      puVar9[1] = uVar2 + 1;
    }
    else {
      puVar5 = (undefined4 *)FUN_0019423c(puVar9,uVar2);
    }
    *puVar5 = 3;
  }
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x9c);
  uVar7 = FUN_000e7d5c(param_2);
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,uVar7,*(undefined4 *)(param_2 + 0x134));
  return;
}

/* FUN_0019e990 @ 0x19e990 (108 bytes) */
int FUN_0019e990(param_1, param_2)
  uint *param_1;
  int param_2;
{
  if ((*param_1 & 0x400000) != 0) {
    if (param_2 == 1) {
      return param_1[1] >> 2 & 3;
    }
    if (param_2 < 2) {
      if (param_2 == 0) {
        return param_1[1] & 3;
      }
    }
    else {
      if (param_2 == 2) {
        return param_1[1] >> 4 & 3;
      }
      if (param_2 == 3) {
        return param_1[1] >> 6 & 3;
      }
    }
  }
  return 1;
}

/* FUN_0019e9fc @ 0x19e9fc (168 bytes) */
int FUN_0019e9fc(param_1, param_2)
  uint *param_1;
  int param_2;
{
  if ((*param_1 & 0x400000) == 0) {
    if (param_2 == 1) {
      return 1;
    }
    if (param_2 < 2) {
      if (param_2 == 0) {
        return 0;
      }
    }
    else {
      if (param_2 == 2) {
        return 2;
      }
      if (param_2 == 3) {
        return 3;
      }
    }
  }
  else {
    if (param_2 == 1) {
      return param_1[1] >> 4 & 7;
    }
    if (param_2 < 2) {
      if (param_2 == 0) {
        return param_1[1] & 7;
      }
    }
    else {
      if (param_2 == 2) {
        return param_1[1] >> 8 & 7;
      }
      if (param_2 == 3) {
        return param_1[1] >> 0xc & 7;
      }
    }
  }
  return 0xffffffff;
}

/* FUN_0019eaa4 @ 0x19eaa4 (32 bytes) */
int FUN_0019eaa4(param_1)
  uint *param_1;
{
  if ((*param_1 & 0x400000) == 0) {
    return 0;
  }
  return param_1[1] & 0x8888;
}

/* FUN_0019eb30 @ 0x19eb30 (172 bytes) */
int FUN_0019eb30(param_1)
  uint *param_1;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if ((*param_1 & 0x400000) == 0) {
    return 0;
  }
  uVar1 = param_1[1];
  if (1 < (uVar1 & 3) - 2) {
    iVar3 = 4;
    iVar2 = 0;
    do {
      while( true ) {
        do {
          while( true ) {
            iVar2 = iVar2 + 1;
            iVar3 = iVar3 + -1;
            if (iVar3 == 0) {
              return 0;
            }
            if (iVar2 != 1) break;
            if ((uVar1 & 0xc) == 8) {
              return 1;
            }
            if ((uVar1 & 0xc) == 0xc) {
              return 1;
            }
          }
        } while (iVar2 < 2);
        if (iVar2 != 2) break;
        if ((uVar1 & 0x30) == 0x20) {
          return 1;
        }
        if ((uVar1 & 0x30) == 0x30) {
          return 1;
        }
      }
    } while ((iVar2 != 3) || (((uVar1 & 0xc0) != 0x80 && ((uVar1 & 0xc0) != 0xc0))));
  }
  return 1;
}

/* FUN_0019ec88 @ 0x19ec88 (108 bytes) */
int FUN_0019ec88(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  
  if (param_1 == 1) {
    param_3 = param_3 + 4;
  }
  else {
    iVar2 = 0;
    if (-1 < param_2) {
      do {
        iVar2 = iVar2 + 1;
        iVar1 = ((int (*)())FUN_0019ecf4)(param_3);
        param_3 = param_3 + iVar1 * 4;
      } while (iVar2 <= param_2);
    }
  }
  return param_3;
}

/* FUN_0019ecf4 @ 0x19ecf4 (192 bytes) */
int FUN_0019ecf4(param_1)
  uint *param_1;
{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = param_1 + 1;
  uVar1 = *param_1;
  if ((uVar1 & 0x400000) != 0) {
    puVar3 = param_1 + 2;
  }
  if ((uVar1 & 0x1800000) == 0) {
    uVar4 = 0;
    if ((uVar1 & 0x2000000) == 0) {
      uVar1 = *param_1;
    }
    else {
      do {
        uVar4 = uVar4 + 1;
        iVar2 = ((int (*)())FUN_0019ecf4)(puVar3);
        uVar1 = *param_1;
        puVar3 = puVar3 + iVar2;
      } while (uVar4 < (uVar1 >> 0x19 & 1));
    }
    if ((uVar1 & 0x1800000) == 0) goto LAB_0019ed78;
  }
  puVar3 = (uint *)((int (*)())FUN_0019ec88)(uVar1 >> 0x17 & 3,uVar1 >> 0x19 & 1,puVar3);
  uVar1 = *param_1;
LAB_0019ed78:
  if ((uVar1 & 0x4000000) != 0) {
    puVar3 = puVar3 + 1;
  }
  return (int)puVar3 - (int)param_1 >> 2;
}

/* FUN_0019ee08 @ 0x19ee08 (108 bytes) */
int FUN_0019ee08(param_1)
  uint *param_1;
{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = param_1 + 1;
  uVar1 = *param_1;
  if ((uVar1 & 0x400000) != 0) {
    puVar2 = param_1 + 2;
  }
  if ((uVar1 & 0x1800000) != 0) {
    puVar2 = (uint *)((int (*)())FUN_0019ec88)(uVar1 >> 0x17 & 3,uVar1 >> 0x19 & 1);
    uVar1 = *param_1;
  }
  if ((uVar1 & 0x4000000) != 0) {
    puVar2 = puVar2 + 1;
  }
  return (int)puVar2 - (int)param_1 >> 2;
}

/* FUN_0019ee74 @ 0x19ee74 (184 bytes) */
int FUN_0019ee74(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)(param_1 + 1);
  if (cVar1 == '\x01') {
    *(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) =
         *(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) | 0x2000;
    piVar2 = *(int **)(param_2 + 0x310);
    *(int *)(param_2 + 0x30c) = piVar2[2];
                    
                    
    (**(code **)(*piVar2 + 8))(piVar2);
    return;
  }
  if (cVar1 != '\x02') {
    if (cVar1 != '\0') {
      return;
    }
    *(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) = *(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) | 1;
    piVar2 = *(int **)(param_2 + 0x310);
    *(int *)(param_2 + 0x30c) = piVar2[1];
                    
                    
    (**(code **)(*piVar2 + 0xc))(piVar2);
    return;
  }
  *(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) = *(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) | 0x4000
  ;
  piVar2 = *(int **)(param_2 + 0x310);
  *(int *)(param_2 + 0x30c) = piVar2[3];
                    
                    
  (**(code **)(*piVar2 + 0x10))(piVar2);
  return;
}

/* FUN_0019ef2c @ 0x19ef2c (32 bytes) */
int FUN_0019ef2c(param_1)
  int param_1;
{
  *(undefined **)(param_1 + 0xc) = &DAT_001e6730;
  return;
}

/* FUN_0019ef50 @ 0x19ef50 (324 bytes) */
int FUN_0019ef50(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined *puVar1;
  void *pvVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_4 + 0x30c);
  pvVar2 = (void *)FUN_000e14e4(param_4,0x963c);
  *(void **)(param_1 + 0xac) = pvVar2;
  _memset(pvVar2,0,0x963c);
  iVar3 = *(int *)(*(int *)(param_4 + 0x30c) + 0x40);
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(int *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0x60) = 1;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x80) = 1;
  *(undefined4 *)(param_1 + 0x84) = 1;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 0x98) = 1;
  *(undefined4 *)(param_1 + 0x94) = 1;
  **(undefined4 **)(param_1 + 0xa8) = 0;
  puVar1 = PTR_DAT_001e913c;
  *(int *)(*(int *)(param_1 + 0xa8) + 4) = iVar3 + 1;
  *(undefined4 *)(puVar1 + 0x2654) = 7;
  *(undefined4 *)(puVar1 + 0x10e4) = 0xd;
  *(undefined4 *)(puVar1 + 0x22d4) = 0xe;
  *(undefined4 *)(puVar1 + 0x229c) = 0xb;
  *(undefined4 *)(puVar1 + 0x2344) = 0xf;
  *(undefined4 *)(puVar1 + 0x230c) = 0xc;
  *(undefined4 *)(puVar1 + 0x261c) = 5;
  *(undefined4 *)(puVar1 + 0x1a4c) = 6;
  *(undefined4 *)(puVar1 + 0x10ac) = 0xc;
  return;
}

/* FUN_0019f880 @ 0x19f880 (240 bytes) */
int FUN_0019f880(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  *(undefined4 *)(param_1[0x18] * 0x48 + param_1[0x2a]) = 5;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xe) = 0;
  if (param_2 == 0) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x12) = 0x55;
  }
  else {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x12) = 0xaa;
  }
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x14) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x15) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x17) = param_3;
  (**(code **)(*param_1 + 0x15c))(param_1);
  return param_1[0x18] + -1;
}

/* FUN_0019f98c @ 0x19f98c (204 bytes) */
int FUN_0019f98c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint *param_3;
{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int local_28;
  uint local_24 [7];
  
  if (*(int *)(param_2 + 300) == 3) {
    uVar2 = 0;
    iVar4 = 4;
    iVar3 = param_2;
    do {
      if ((((int)*(char *)(param_2 + 0x15c) >> (uVar2 & 0x3f) & 1U) != 0) &&
         (*(int *)(iVar3 + 0x1c) == 2)) {
        fVar1 = *(float *)(uVar2 * 0x18 + param_2 + 0x20);
        break;
      }
      uVar2 = uVar2 + 1;
      iVar3 = iVar3 + 0x18;
      iVar4 = iVar4 + -1;
      fVar1 = FLOAT_001aa0d4;
    } while (iVar4 != 0);
    iVar3 = ((undefined4 (*)())FUN_00191888)((double)fVar1,*(undefined4 *)(param_1 + 0xa4),param_2,&local_28,local_24);
    if (iVar3 != 0) {
      *param_3 = local_24[0] | local_28 << 3 | 0x2000;
      return 1;
    }
  }
  return 0;
}

/* FUN_0019fa58 @ 0x19fa58 (300 bytes) */
int FUN_0019fa58(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  uint param_5;
{
  float fVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  
  if (1 < *(int *)(param_4 + 0x84)) {
    puVar6 = (uint *)(param_3 + param_2 * 4);
    iVar7 = 2;
    do {
      piVar4 = (int *)FUN_00105594(param_4,iVar7);
      if (((piVar4 != (int *)0x0) && (iVar5 = (**(code **)(*piVar4 + 0x48))(), iVar5 != 0)) &&
         ((param_5 & 0xff) < 4)) {
        iVar5 = FUN_001054ec(param_4,iVar7);
        uVar3 = (uint)*(byte *)((param_5 & 0xff) + iVar5 + 0x10);
        if (uVar3 < 4) {
          uVar2 = *puVar6 & 0xfffff1ff;
          fVar1 = (float)piVar4[uVar3 * 6 + 8];
          *puVar6 = uVar2;
          if (fVar1 == 0.0) {
            *puVar6 = uVar2 | 0x800;
          }
          else if (fVar1 == 0.5) {
            *puVar6 = uVar2 | 0xa00;
          }
          else if (fVar1 == 1.0) {
            *puVar6 = uVar2 | 0xc00;
          }
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 <= *(int *)(param_4 + 0x84));
  }
  return;
}

/* FUN_0019fb84 @ 0x19fb84 (320 bytes) */
int FUN_0019fb84(param_1)
  int *param_1;
{
  void *pvVar1;
  
  if (param_1[0x1d] == 0) {
    pvVar1 = (void *)(param_1[0x2a] + param_1[0x18] * 0x48);
    _memcpy((void *)((int)pvVar1 + 0x48),pvVar1,0x48);
    _memset((void *)(param_1[0x18] * 0x48 + param_1[0x2a]),0,0x48);
    param_1[0x18] = 2;
    param_1[0x1d] = 1;
    (**(code **)(*param_1 + 0xc4))(param_1,1,0,0,0,0);
    (**(code **)(*param_1 + 200))(param_1,1,0,0,0,0);
    (**(code **)(*param_1 + 0xcc))(param_1,1,0xf);
    (**(code **)(*param_1 + 0xd0))(param_1,1,0xf);
  }
  param_1[0x21] = 1;
  param_1[0x20] = 1;
  param_1[0x18] = param_1[0x18] + 1;
  return;
}

/* FUN_0019fccc @ 0x19fccc (292 bytes) */
int FUN_0019fccc(param_1)
  int *param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  *(int *)(param_1[0x2b] + 0x93b8) = param_1[0x24];
  *(int *)(param_1[0x2b] + 0x9364) = *(int *)(*(int *)(param_1[3] + 0x6c4) + 0x7c) + 1;
  *(undefined4 *)(param_1[0x2b] + 0x9368) = *(undefined4 *)(*(int *)(param_1[3] + 0x6c4) + 0x84);
  iVar1 = FUN_0013061c(*(undefined4 *)(param_1[3] + 0x6c4),0);
  if (iVar1 != 0) {
    iVar2 = iVar1 + -1;
  }
  if ((*(int *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x48) != 3) ||
     (param_1[0x2d] == (param_1[0x18] - param_1[0x1d]) + -1)) {
    (**(code **)(*param_1 + 0xbc))(param_1);
    (**(code **)(*param_1 + 0xc0))(param_1);
    (**(code **)(*param_1 + 0x15c))(param_1);
  }
                    
                    
  (**(code **)(*param_1 + 0x144))(param_1,param_1[0x1e],iVar2);
  return;
}

/* FUN_0019ff2c @ 0x19ff2c (176 bytes) */
int FUN_0019ff2c(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_1[0x18];
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  if ((*(int *)(param_2 + 0xdc) != 0) && (iVar4 == param_1[0x18])) {
    iVar4 = *(int *)(param_2 + 0xd0);
    iVar3 = 0;
    for (uVar2 = 1; uVar2 <= *(uint *)(iVar4 + 4); uVar2 = uVar2 + 1) {
      iVar1 = *(int *)(iVar3 + *(int *)(iVar4 + 8));
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0xdc) = 1;
      }
      iVar3 = iVar3 + 4;
    }
  }
  return;
}

/* FUN_0019ffdc @ 0x19ffdc (216 bytes) */
int FUN_0019ffdc(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  
  iVar3 = param_1[0x18];
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  if ((*(int *)(param_2 + 0xdc) == 0) || (bVar1 = true, iVar3 != param_1[0x18])) {
    bVar1 = false;
  }
  pcVar4 = *(code **)(*param_1 + 0x9c);
  uVar2 = FUN_000e7d5c(param_2);
  (*pcVar4)(param_1,uVar2,*(undefined4 *)(param_2 + 0x134));
  if (bVar1) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x44) = 1;
  }
  if (*(int *)(param_2 + 0x134) != 0) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x3a) = 3;
  }
  return;
}

/* FUN_001a06c4 @ 0x1a06c4 (252 bytes) */
int FUN_001a06c4(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  piVar1 = (int *)FUN_00105594(param_2,param_3);
  if (((((piVar1[0x20] == 0) || (iVar2 = FUN_00126760(piVar1[0x26]), iVar2 == 0)) ||
       ((piVar1[5] & 2U) != 0)) || (iVar2 = (**(code **)(*piVar1 + 0x50))(piVar1), iVar2 != 0)) &&
     (iVar2 = (**(code **)(*piVar1 + 0x50))(piVar1), iVar2 == 0)) {
    uVar3 = 0;
    if (piVar1[0x26] == 0x29) {
      iVar2 = FUN_00105c5c(param_2,param_3);
      uVar3 = iVar2 + *(int *)(*(int *)(param_4 + 0x6c4) + 0x3f0) | 0x4000;
    }
    return uVar3;
  }
  uVar3 = thunk_FUN_00134de8(*(undefined4 *)(param_4 + 0x6c4),piVar1);
  return uVar3;
}

/* FUN_001a07c0 @ 0x1a07c0 (304 bytes) */
int FUN_001a07c0(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  
  iVar6 = FUN_00105594(param_5);
  fVar4 = FLOAT_001aa10c;
  fVar3 = FLOAT_001aa0d4;
  puVar9 = (uint *)(param_4 + param_2 * 4);
  iVar8 = 0;
  uVar10 = 0;
  do {
    iVar7 = FUN_001054ec(param_5,param_2);
    uVar5 = (uint)*(byte *)(iVar8 + iVar7 + 0x10);
    if (uVar5 < 4) {
      fVar2 = *(float *)(uVar5 * 0x18 + iVar6 + 0x20);
      if (fVar2 == fVar3) {
LAB_001a08b4:
        *puVar9 = 4 << (uVar10 & 0x3f) | *puVar9;
      }
      else if (fVar2 == fVar4) {
        *puVar9 = 5 << (uVar10 & 0x3f) | *puVar9;
      }
      else if (fVar2 == 1.0) {
        *puVar9 = 6 << (uVar10 & 0x3f) | *puVar9;
      }
    }
    else {
      if (uVar5 != 6) goto LAB_001a08b4;
      *puVar9 = 6 << (uVar10 & 0x3f) | *puVar9;
    }
    bVar1 = iVar8 == 2;
    uVar10 = uVar10 + 3;
    iVar8 = iVar8 + 1;
    if (bVar1) {
      return;
    }
  } while( true );
}

/* FUN_001a08f0 @ 0x1a08f0 (224 bytes) */
int FUN_001a08f0(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
{
  float fVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = FUN_00105594(param_5);
  iVar2 = param_2 * 4;
  *(undefined4 *)(iVar2 + param_3) = 0;
  iVar5 = FUN_001054ec(param_5,param_2);
  uVar3 = (uint)*(byte *)(iVar5 + 0x13);
  if (uVar3 < 4) {
    fVar1 = *(float *)(uVar3 * 0x18 + iVar4 + 0x20);
    if (fVar1 == FLOAT_001aa0d4) {
LAB_001a09b0:
      *(uint *)(iVar2 + param_4) = *(uint *)(iVar2 + param_4) | 0x800;
      return;
    }
    if (fVar1 == FLOAT_001aa10c) {
      *(uint *)(iVar2 + param_4) = *(uint *)(iVar2 + param_4) | 0xa00;
      return;
    }
    if (fVar1 != FLOAT_001aa0e8) {
      return;
    }
  }
  else if (uVar3 != 6) goto LAB_001a09b0;
  *(uint *)(iVar2 + param_4) = *(uint *)(iVar2 + param_4) | 0xc00;
  return;
}

/* FUN_001a09d0 @ 0x1a09d0 (364 bytes) */
int FUN_001a09d0(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
{
  bool bVar1;
  byte bVar2;
  float fVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  uint *puVar7;
  byte *pbVar8;
  int iVar9;
  uint uVar10;
  undefined4 uStack00000028;
  
  if (1 < *(int *)(param_4 + 0x84)) {
    iVar9 = 2;
    puVar7 = (uint *)(param_3 + param_2 * 4);
    uStack00000028 = param_5;
    do {
      piVar5 = (int *)FUN_00105594(param_4,iVar9);
      if ((piVar5 != (int *)0x0) && (iVar6 = (**(code **)(*piVar5 + 0x48))(), iVar6 != 0)) {
        pbVar8 = (byte *)&STACKARG(0x28);
        uVar10 = 0;
        do {
          bVar2 = *pbVar8;
          if (bVar2 < 4) {
            iVar6 = FUN_001054ec(param_4,iVar9);
            uVar4 = (uint)*(byte *)((uint)bVar2 + iVar6 + 0x10);
            if (uVar4 < 4) {
              fVar3 = (float)piVar5[uVar4 * 6 + 8];
              if (fVar3 == 0.0) {
                *puVar7 = *puVar7 & ~(7 << (uVar10 & 0x3f)) | 4 << (uVar10 & 0x3f);
              }
              else if (fVar3 == 0.5) {
                *puVar7 = *puVar7 & ~(7 << (uVar10 & 0x3f)) | 5 << (uVar10 & 0x3f);
              }
              else if (fVar3 == 1.0) {
                *puVar7 = *puVar7 & ~(7 << (uVar10 & 0x3f)) | 6 << (uVar10 & 0x3f);
              }
            }
          }
          bVar1 = uVar10 != 6;
          pbVar8 = pbVar8 + 1;
          uVar10 = uVar10 + 3;
        } while (bVar1);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 <= *(int *)(param_4 + 0x84));
  }
  return;
}

/* FUN_001a0b3c @ 0x1a0b3c (1192 bytes) */
int FUN_001a0b3c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int *param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  int iVar6;
  
  iVar4 = (**(code **)(*param_2 + 0x14))(param_2);
  if (*(int *)(param_2[0x22] + 8) == 0xb4) {
    iVar4 = 3;
  }
  else if (iVar4 < 1) {
    return;
  }
  bVar1 = param_3 != 0;
  bVar2 = param_6 != 0;
  do {
    if (bVar1) {
      *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x2a) =
           (char)*(undefined4 *)(param_4 + 4);
      iVar6 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(uint *)(iVar6 + 0x24) = *(int *)(param_5 + 4) << 0x1d | *(uint *)(iVar6 + 0x24) & 0x1fffffff
      ;
      iVar6 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(uint *)(iVar6 + 0x24) =
           (*(uint *)(param_5 + 4) & 0x38) << 0x17 | *(uint *)(iVar6 + 0x24) & 0xe3ffffff;
      iVar6 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(uint *)(iVar6 + 0x24) =
           (*(uint *)(param_5 + 4) & 0x1c0) << 0x11 | *(uint *)(iVar6 + 0x24) & 0xfc7fffff;
    }
    if (bVar2) {
      *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x39) =
           (char)*(undefined4 *)(param_7 + 4);
      *(byte *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x36) =
           (byte)(*(uint *)(param_8 + 4) >> 9) & 7;
    }
    iVar6 = 1;
    while( true ) {
      iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(byte *)(iVar3 + 0x2a) = *(byte *)(iVar3 + 0x2a) | 0x80;
      iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(byte *)(iVar3 + 0x39) = *(byte *)(iVar3 + 0x39) | 0x80;
      iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(byte *)(iVar3 + 0x2b) = *(byte *)(iVar3 + 0x2b) | 0x80;
      iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(byte *)(iVar3 + 0x3a) = *(byte *)(iVar3 + 0x3a) | 0x80;
      iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(byte *)(iVar3 + 0x2c) = *(byte *)(iVar3 + 0x2c) | 0x80;
      iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(byte *)(iVar3 + 0x3b) = *(byte *)(iVar3 + 0x3b) | 0x80;
      uVar5 = FUN_0019545c(param_2[iVar6 * 6 + 0x28] & 1,(uint)param_2[iVar6 * 6 + 0x28] >> 1 & 1);
      if (bVar2) {
        if (iVar6 == 1) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x3c) = uVar5
          ;
        }
        else if (iVar6 == 2) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x3d) = uVar5
          ;
        }
        else if (iVar6 == 3) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x3e) = uVar5
          ;
        }
      }
      if (bVar1) {
        if (iVar6 == 1) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x2d) = uVar5
          ;
        }
        else if (iVar6 == 2) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x2e) = uVar5
          ;
        }
        else if (iVar6 == 3) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x2f) = uVar5
          ;
        }
      }
      iVar6 = iVar6 + 1;
      if (iVar4 < iVar6) {
        return;
      }
      if (iVar6 == 1) break;
      if (iVar6 == 2) {
        if (bVar1) {
          *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x2b) =
               (char)*(undefined4 *)(param_4 + 8);
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar3 + 0x24) =
               (*(uint *)(param_5 + 8) & 7) << 0xd | *(uint *)(iVar3 + 0x24) & 0xffff1fff;
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar3 + 0x24) =
               (*(uint *)(param_5 + 8) & 0x38) << 7 | *(uint *)(iVar3 + 0x24) & 0xffffe3ff;
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar3 + 0x24) =
               (*(uint *)(param_5 + 8) & 0x1c0) << 1 | *(uint *)(iVar3 + 0x24) & 0xfffffc7f;
        }
        if (bVar2) {
          *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x3a) =
               (char)*(undefined4 *)(param_7 + 8);
          *(byte *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x37) =
               (byte)(*(uint *)(param_8 + 8) >> 9) & 7;
        }
      }
      else if (iVar6 == 3) {
        if (bVar1) {
          *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x2c) =
               (char)*(undefined4 *)(param_4 + 0xc);
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar3 + 0x28) =
               *(int *)(param_5 + 0xc) << 0x1d | *(uint *)(iVar3 + 0x28) & 0x1fffffff;
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar3 + 0x28) =
               (*(uint *)(param_5 + 0xc) & 0x38) << 0x17 | *(uint *)(iVar3 + 0x28) & 0xe3ffffff;
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar3 + 0x28) =
               (*(uint *)(param_5 + 0xc) & 0x1c0) << 0x11 | *(uint *)(iVar3 + 0x28) & 0xfc7fffff;
        }
        if (bVar2) {
          *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x3b) =
               (char)*(undefined4 *)(param_7 + 0xc);
          *(byte *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x38) =
               (byte)(*(uint *)(param_8 + 0xc) >> 9) & 7;
        }
      }
    }
  } while( true );
}

/* FUN_001a0fe4 @ 0x1a0fe4 (356 bytes) */
int FUN_001a0fe4(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  int local_48;
  float local_44;
  int local_30;
  float local_2c;
  
  uVar1 = DAT_001b2d70;
  iVar2 = FUN_000f5cf0(param_1,1,DAT_001b2d70,&local_48);
  if ((((iVar2 == 0) || (local_48 != 2)) ||
      (iVar2 = FUN_000f5cf0(param_1,2,uVar1,&local_30), iVar2 == 0)) || (local_30 != 2)) {
    bVar3 = false;
    *param_2 = 0;
  }
  else {
    bVar3 = false;
    switch(*(undefined4 *)(param_1 + 300)) {
    case 0:
      bVar3 = local_44 == local_2c;
      break;
    case 1:
      bVar3 = local_44 != local_2c;
      break;
    case 2:
      bVar3 = local_2c < local_44;
      break;
    case 3:
      bVar3 = local_2c <= local_44;
      break;
    case 4:
      bVar3 = local_44 < local_2c;
      break;
    case 5:
      bVar3 = local_44 <= local_2c;
    }
    *param_2 = 1;
  }
  return bVar3;
}

/* FUN_001a1160 @ 0x1a1160 (144 bytes) */
int FUN_001a1160(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)0x0;
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x24);
  uVar2 = *(uint *)(iVar1 + 4);
  if (uVar2 - 1 < uVar2) {
    piVar3 = (int *)((uVar2 - 1) * 4 + *(int *)(iVar1 + 8));
  }
  iVar4 = *piVar3;
  FUN_00194208(iVar1,uVar2 - 1);
  *(short *)(iVar4 * 0x48 + *(int *)(param_1 + 0xa8) + 0xc) =
       ((short)*(undefined4 *)(param_1 + 0x60) - (short)*(undefined4 *)(param_1 + 0x74)) + -1;
  *(int *)(param_1 + 0xb4) = (*(int *)(param_1 + 0x60) - *(int *)(param_1 + 0x74)) + -1;
  return;
}

/* FUN_001a11f0 @ 0x1a11f0 (328 bytes) */
int FUN_001a11f0(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  uint *puVar8;
  
  iVar3 = FUN_000e7804(param_2);
  uVar7 = *(undefined4 *)(param_4 + 0x6c4);
  iVar2 = *(int *)(iVar3 + 300);
  uVar4 = FUN_00105594(iVar3,1);
  uVar4 = thunk_FUN_00134de8(uVar7,uVar4);
  iVar3 = param_1[0x18];
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  if ((*(int *)(param_2 + 0xdc) == 0) || (bVar1 = true, iVar3 != param_1[0x18])) {
    bVar1 = false;
  }
  uVar4 = (**(code **)(*param_1 + 0x98))(param_1,iVar2 != 1,uVar4,0);
  if (bVar1) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x44) = 1;
  }
  puVar8 = *(uint **)(param_1[4] + 0x24);
  uVar6 = puVar8[1];
  if (uVar6 < *puVar8) {
    _memset((void *)(uVar6 * 4 + puVar8[2]),0,4);
    puVar5 = (undefined4 *)(uVar6 * 4 + puVar8[2]);
    puVar8[1] = uVar6 + 1;
  }
  else {
    puVar5 = (undefined4 *)FUN_0019423c(puVar8,uVar6);
  }
  *puVar5 = uVar4;
  return;
}

/* FUN_001a1338 @ 0x1a1338 (96 bytes) */
int FUN_001a1338(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,((unsigned char *)0x000010c4));
  *puVar1 = uVar2;
  puVar1[1] = &PTR_FUN_001eb9a8;
  puVar1[7] = 0;
  return puVar1 + 1;
}

/* FUN_001a1398 @ 0x1a1398 (312 bytes) */
int FUN_001a1398(param_1)
  int *param_1;
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  int iVar5;
  
  do {
    iVar2 = *(int *)(param_1[4] + 0x28);
    uVar3 = *(uint *)(iVar2 + 4);
    if (uVar3 == 0) {
      sVar4 = -1;
LAB_001a1430:
      *(undefined4 *)(param_1[0x18] * 0x48 + param_1[0x2a]) = 5;
      *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x12) = 0xff;
      *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x10) = 1;
      *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xe) = 2;
      *(short *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xc) = sVar4 - (short)param_1[0x1d];
                    
                    
      (**(code **)(*param_1 + 0x15c))(param_1);
      return;
    }
    piVar1 = (int *)0x0;
    if (uVar3 - 1 < uVar3) {
      piVar1 = (int *)((uVar3 - 1) * 4 + *(int *)(iVar2 + 8));
    }
    iVar5 = *piVar1;
    FUN_00194208(iVar2,uVar3 - 1);
    if ((*(char *)(iVar5 + 0xe) == '\x03') || (*(char *)(iVar5 + 0xe) == '\x01')) {
      sVar4 = *(short *)(iVar5 + 0xc);
      *(short *)(iVar5 + 0xc) = (short)param_1[0x18] - (short)param_1[0x1d];
      goto LAB_001a1430;
    }
    *(short *)(iVar5 + 0xc) = (short)param_1[0x18] - (short)param_1[0x1d];
  } while( true );
}

/* FUN_001a158c @ 0x1a158c (704 bytes) */
int FUN_001a158c(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = *(int *)(param_1[4] + 0x24);
  piVar1 = (int *)0x0;
  uVar4 = *(uint *)(iVar2 + 4);
  if (uVar4 - 1 < uVar4) {
    piVar1 = (int *)((uVar4 - 1) * 4 + *(int *)(iVar2 + 8));
  }
  iVar7 = *piVar1;
  FUN_00194208(iVar2,uVar4 - 1);
  iVar2 = param_1[0x18];
  iVar3 = FUN_000e07dc(param_4,0x4b);
  if (iVar3 == 0) {
    iVar2 = param_1[0x2a];
  }
  else {
    iVar3 = (iVar2 + -1) * 0x48;
    iVar2 = param_1[0x2a];
    iVar6 = iVar2 + iVar3;
    if ((((*(int *)(iVar2 + iVar3) == 5) && (*(char *)(iVar6 + 0xe) == '\0')) &&
        ((*(uint *)(iVar6 + 0x10) & 0xff00ff00) == 0x1000000)) &&
       (*(char *)(iVar2 + iVar7 * 0x48 + 0xf) == '\0')) {
      cVar5 = *(char *)(iVar6 + 0x13);
      param_1[0x18] = param_1[0x18] + -1;
      param_1[0x2f] = param_1[0x2f] + 1;
      cVar5 = cVar5 + '\x01';
      *(int *)(param_1[4] + 0x1c) = *(int *)(param_1[4] + 0x1c) + 1;
      iVar2 = param_1[0x2a];
      goto LAB_001a168c;
    }
  }
  cVar5 = '\x01';
  param_1[0x2f] = 0;
LAB_001a168c:
  *(short *)(iVar2 + iVar7 * 0x48 + 0xc) = (short)param_1[0x18] - (short)param_1[0x1d];
  iVar3 = param_1[0x2f];
  iVar2 = param_1[0x2e];
  param_1[iVar2 + 0x30] = iVar7;
  if (0 < iVar3) {
    iVar6 = param_1[0x2a];
    piVar1 = param_1 + iVar2 + 0x30;
    uVar4 = (uint)*(byte *)(iVar6 + iVar7 * 0x48 + 0x13);
    while( true ) {
      if (*(char *)(*piVar1 * 0x48 + iVar6 + 0xf) == '\0') {
        uVar4 = uVar4 + 1;
      }
      iVar2 = piVar1[1];
      iVar6 = iVar6 + iVar2 * 0x48;
      if (*(char *)(iVar6 + 0xf) == '\x01') {
        uVar4 = uVar4 + 1;
      }
      *(char *)(iVar6 + 0x13) = (char)uVar4;
      if (uVar4 != 0) {
        *(undefined1 *)(iVar2 * 0x48 + param_1[0x2a] + 0x15) = 1;
      }
      piVar1 = piVar1 + 1;
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) break;
      iVar6 = param_1[0x2a];
    }
    iVar2 = param_1[0x2e];
  }
  param_1[0x2e] = iVar2 + -1;
  *(undefined4 *)(param_1[0x18] * 0x48 + param_1[0x2a]) = 5;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xe) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x12) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x10) = 1;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x14) = 1;
  *(char *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x13) = cVar5;
  (**(code **)(*param_1 + 0x15c))(param_1);
  if (*(int *)(param_2 + 0xdc) != 0) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x44) = 1;
  }
                    
                    
  (**(code **)(*param_1 + 0x34))(param_1,param_3,0);
  return;
}

/* FUN_001a191c @ 0x1a191c (560 bytes) */
int FUN_001a191c(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  byte bVar3;
  undefined1 uVar4;
  int iVar2;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  
  switch(*(undefined4 *)(param_4 + 300)) {
  default:
    iVar6 = 2;
    uVar5 = 0;
    break;
  case 1:
    iVar6 = 2;
    uVar5 = 3;
    break;
  case 2:
    iVar6 = 1;
    uVar5 = 1;
    break;
  case 3:
    iVar6 = 2;
    uVar5 = 2;
    break;
  case 4:
    iVar6 = 2;
    uVar5 = 1;
    break;
  case 5:
    iVar6 = 1;
    uVar5 = 2;
  }
  bVar3 = FUN_0019545c(1,0);
  *(undefined4 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8)) = 4;
  if (param_2 != 0) {
    iVar7 = *(int *)(param_1 + 0x60);
    iVar1 = *(int *)(param_1 + 0xa8);
    iVar2 = FUN_001054ec(param_4,0);
    uVar4 = FUN_00195424(*(undefined4 *)(iVar2 + 0x10));
    *(undefined1 *)(iVar7 * 0x48 + iVar1 + 0x15) = uVar4;
    if (iVar6 == 1) {
      iVar1 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(byte *)(iVar1 + 0x2d) = bVar3 ^ *(byte *)(iVar1 + 0x2d);
    }
    else {
      iVar1 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(byte *)(iVar1 + 0x2e) = bVar3 ^ *(byte *)(iVar1 + 0x2e);
    }
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x16) = uVar5;
  }
  if (param_3 != 0) {
    iVar7 = *(int *)(param_1 + 0x60);
    iVar1 = *(int *)(param_1 + 0xa8);
    iVar2 = FUN_001054ec(param_4,0);
    *(bool *)(iVar7 * 0x48 + iVar1 + 0x21) = *(char *)(iVar2 + 0x13) == '\0';
  }
  if (iVar6 == 1) {
    iVar6 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(byte *)(iVar6 + 0x3c) = bVar3 ^ *(byte *)(iVar6 + 0x3c);
  }
  else {
    iVar6 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(byte *)(iVar6 + 0x3d) = bVar3 ^ *(byte *)(iVar6 + 0x3d);
  }
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x22) = uVar5;
  return;
}

/* FUN_001a1b64 @ 0x1a1b64 (448 bytes) */
int FUN_001a1b64(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  undefined1 uVar6;
  int iVar7;
  
  iVar7 = *(int *)(param_4 + 0x98);
  iVar5 = *(int *)(param_4 + 0x94);
  if (iVar7 == 0x2c) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x15) = 7;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x21) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0xac) + 0x9374) = 1;
    bVar2 = (*(int *)(param_4 + 300) == 0) << 1;
    if ((*(uint *)(param_4 + 0x14) & 0x1000) != 0) {
      bVar2 = bVar2 | 1;
    }
    *(byte *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x16) = bVar2;
    *(byte *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x22) = bVar2;
  }
  else {
    if (iVar7 == 9) {
      iVar1 = iVar5 + 1;
      iVar4 = *(int *)(*(int *)(param_1 + 0xac) + 0x9374);
      if (iVar1 <= iVar4) {
        iVar1 = iVar4;
      }
      *(int *)(*(int *)(param_1 + 0xac) + 0x9374) = iVar1;
    }
    uVar6 = (undefined1)iVar5;
    if ((param_2 != 0) && (iVar7 != 8)) {
      *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x16) = uVar6;
      iVar4 = *(int *)(param_1 + 0x60);
      iVar5 = *(int *)(param_1 + 0xa8);
      iVar1 = FUN_001054ec(param_4,0);
      uVar3 = FUN_00195424(*(undefined4 *)(iVar1 + 0x10));
      *(undefined1 *)(iVar4 * 0x48 + iVar5 + 0x15) = uVar3;
    }
    if (param_3 != 0) {
      *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x22) = uVar6;
      if (iVar7 == 8) {
        *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x23) = 1;
      }
      else {
        iVar1 = *(int *)(param_1 + 0x60);
        iVar5 = *(int *)(param_1 + 0xa8);
        iVar7 = FUN_001054ec(param_4,0);
        *(bool *)(iVar1 * 0x48 + iVar5 + 0x21) = *(char *)(iVar7 + 0x13) == '\0';
      }
    }
  }
  return;
}

/* FUN_001a1d24 @ 0x1a1d24 (2180 bytes) */
int FUN_001a1d24(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  bool bVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined2 uVar8;
  int iVar6;
  byte bVar9;
  undefined4 uVar7;
  byte bVar11;
  uint uVar10;
  undefined4 unaff_r21;
  undefined4 unaff_r22;
  int *piVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  uint local_78 [4];
  uint local_68 [4];
  undefined4 local_58 [4];
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  uint local_3c [3];
  
  piVar3 = (int *)FUN_00105594(param_2,1);
  iVar4 = (**(code **)(*piVar3 + 0x60))();
  if (iVar4 != 0) {
    iVar13 = FUN_001054ec(piVar3,1);
    uVar7 = *(undefined4 *)(iVar13 + 0x10);
    iVar13 = FUN_001054ec(param_2,1);
    unaff_r22 = *(undefined4 *)(iVar13 + 0x10);
    FUN_000f2bdc(&local_48,uVar7,unaff_r22);
    piVar5 = (int *)FUN_00105594(piVar3,1);
    FUN_00106004(param_2,1,piVar5,0,param_4);
    iVar13 = FUN_001054ec(piVar3,1);
    uVar7 = *(undefined4 *)(iVar13 + 0x10);
    iVar13 = FUN_001054ec(param_2,1);
    *(undefined4 *)(iVar13 + 0x10) = uVar7;
    unaff_r21 = local_48;
    piVar12 = piVar3;
  }
  else {
    piVar12 = (int *)0x0;
    piVar5 = piVar3;
  }
  uVar8 = (**(code **)(*param_1 + 0x158))(param_1,param_2,1,param_4);
  *(undefined4 *)(param_1[0x18] * 0x48 + param_1[0x2a]) = 2;
  *(undefined2 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xe) = uVar8;
  iVar14 = *(int *)(param_2 + 0x134);
  iVar13 = *(int *)(*(int *)(param_2 + 0x88) + 8);
  if (iVar13 != 0x77) {
    *(char *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x19) = (char)iVar14;
    iVar16 = param_1[0x18];
    iVar6 = param_1[0x2a];
    uVar8 = thunk_FUN_00134de8(*(undefined4 *)(param_4 + 0x6c4),param_2);
    *(undefined2 *)(iVar16 * 0x48 + iVar6 + 0xc) = uVar8;
  }
  else {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x19) = 0;
    *(undefined2 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xc) = 0;
    *(undefined4 *)(param_1[0x2b] + 0x9370) = 1;
  }
  iVar6 = (**(code **)(*piVar5 + 0x80))(piVar5);
  if (iVar6 == 0) {
    *(undefined4 *)(iVar14 * 4 + param_1[0x2b] + 0x9378) = 1;
  }
  if (*(int *)(PTR_DAT_001e913c + iVar13 * 0x38 + 0xc) != -1) {
    *(char *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x1a) =
         (char)*(int *)(PTR_DAT_001e913c + iVar13 * 0x38 + 0xc);
  }
  bVar11 = 0xc;
  iVar14 = *(int *)(iVar14 * 0xc + *(int *)(*(int *)(param_4 + 0x6c4) + 0x78) + 4);
  if (iVar14 != 2) {
    if (iVar14 < 3) {
      bVar11 = 0xe;
      if (iVar14 != 1) {
LAB_001a1f84:
        bVar11 = 0;
      }
    }
    else {
      bVar11 = 8;
      if (4 < iVar14) goto LAB_001a1f84;
    }
  }
  bVar1 = *(int *)(param_2 + 0x138) == 1;
  if (iVar13 == 0x77) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x1f) = 0;
    iVar14 = FUN_001054ec(param_2,1);
    FUN_000f32cc(&local_44,*(undefined4 *)(iVar14 + 0x10));
    uVar7 = DAT_001b2d68;
    *(undefined4 *)(param_2 + 0x9c) = local_44;
    iVar14 = FUN_001054ec(param_2,1);
    *(undefined4 *)(iVar14 + 0x10) = uVar7;
    goto LAB_001a20d4;
  }
  if ((iVar13 - 0x75U < 2) || (iVar13 == 0xae)) {
    *(byte *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x1f) = bVar11 & 7;
    *(bool *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x18) = bVar1;
    iVar14 = param_1[0x18] * 0x48 + param_1[0x2a];
    if ((*(uint *)(param_2 + 0x14) & 0x2000) == 0) goto LAB_001a20b4;
LAB_001a20cc:
    uVar2 = 0;
  }
  else {
    *(byte *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x1f) = bVar11;
    *(bool *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x18) = bVar1;
    iVar14 = param_1[0x18] * 0x48 + param_1[0x2a];
    if ((*(uint *)(param_2 + 0x14) & 0x2000) != 0) goto LAB_001a20cc;
LAB_001a20b4:
    iVar6 = FUN_000e07dc(param_4,0x22);
    uVar2 = 1;
    if (iVar6 == 0) goto LAB_001a20cc;
  }
  *(undefined1 *)(iVar14 + 0x1c) = uVar2;
LAB_001a20d4:
  iVar14 = FUN_001054ec(param_2,1);
  FUN_000f3470(&local_40,*(undefined4 *)(iVar14 + 0x10));
  iVar14 = param_1[0x18] * 0x48 + param_1[0x2a];
  *(uint *)(iVar14 + 0x14) = local_40 >> 2 & 0xc00000 | *(uint *)(iVar14 + 0x14) & 0xff3fffff;
  iVar14 = param_1[0x18] * 0x48 + param_1[0x2a];
  *(uint *)(iVar14 + 0x14) = (local_40 & 0x30000) << 4 | *(uint *)(iVar14 + 0x14) & 0xffcfffff;
  iVar14 = param_1[0x18] * 0x48 + param_1[0x2a];
  *(uint *)(iVar14 + 0x14) = (local_40 & 0x300) << 10 | *(uint *)(iVar14 + 0x14) & 0xfff3ffff;
  iVar14 = param_1[0x18] * 0x48 + param_1[0x2a];
  *(uint *)(iVar14 + 0x14) = (local_40 & 3) << 0x10 | *(uint *)(iVar14 + 0x14) & 0xfffcffff;
  FUN_000f3470(local_3c,*(undefined4 *)(param_2 + 0x140));
  iVar14 = param_1[0x18] * 0x48 + param_1[0x2a];
  *(uint *)(iVar14 + 0x14) = (local_3c[0] & 0x3000000) << 6 | *(uint *)(iVar14 + 0x14) & 0x3fffffff;
  iVar14 = param_1[0x18] * 0x48 + param_1[0x2a];
  *(uint *)(iVar14 + 0x14) = (local_3c[0] & 0x30000) << 0xc | *(uint *)(iVar14 + 0x14) & 0xcfffffff;
  iVar14 = param_1[0x18] * 0x48 + param_1[0x2a];
  *(uint *)(iVar14 + 0x14) = (local_3c[0] & 0x300) << 0x12 | *(uint *)(iVar14 + 0x14) & 0xf3ffffff;
  iVar14 = param_1[0x18] * 0x48 + param_1[0x2a];
  *(uint *)(iVar14 + 0x14) = (local_3c[0] & 3) << 0x18 | *(uint *)(iVar14 + 0x14) & 0xfcffffff;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x1d) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x1e) = 0;
  iVar6 = param_1[0x18] * 0x48 + param_1[0x2a];
  bVar11 = *(byte *)(iVar6 + 0x1d);
  iVar14 = FUN_001054ec(param_2,0);
  bVar9 = FUN_00195424(*(undefined4 *)(iVar14 + 0x10));
  *(byte *)(iVar6 + 0x1d) = bVar11 | bVar9;
  iVar6 = param_1[0x18] * 0x48 + param_1[0x2a];
  bVar11 = *(byte *)(iVar6 + 0x1e);
  iVar14 = FUN_001054ec(param_2,0);
  *(byte *)(iVar6 + 0x1e) = bVar11 | *(char *)(iVar14 + 0x13) == '\0';
  *(undefined2 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x10) = 0;
  *(undefined2 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x12) = 0;
  param_1[0x2c] = param_1[0x18];
  if (iVar13 == 0x78) {
    iVar13 = FUN_001054ec(param_2,2);
    uVar10 = *(uint *)(iVar13 + 0x10);
    iVar13 = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(iVar13 + 0x14) = uVar10 >> 10 & 0xc000 | *(uint *)(iVar13 + 0x14) & 0xffff3fff;
    iVar13 = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(iVar13 + 0x14) = uVar10 >> 4 & 0x3000 | *(uint *)(iVar13 + 0x14) & 0xffffcfff;
    iVar13 = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(iVar13 + 0x14) = (uVar10 & 0x300) << 2 | *(uint *)(iVar13 + 0x14) & 0xfffff3ff;
    iVar13 = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(iVar13 + 0x14) = (uVar10 & 3) << 8 | *(uint *)(iVar13 + 0x14) & 0xfffffcff;
    iVar14 = param_1[0x18];
    iVar13 = param_1[0x2a];
    uVar15 = *(undefined4 *)(param_4 + 0x6c4);
    uVar7 = FUN_00105594(param_2,2);
    uVar8 = thunk_FUN_00134de8(uVar15,uVar7);
    *(undefined2 *)(iVar14 * 0x48 + iVar13 + 0x10) = uVar8;
    iVar13 = FUN_001054ec(param_2,3);
    uVar10 = *(uint *)(iVar13 + 0x10);
    iVar13 = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(iVar13 + 0x14) = uVar10 >> 0x12 & 0xc0 | *(uint *)(iVar13 + 0x14) & 0xffffff3f;
    iVar13 = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(iVar13 + 0x14) = uVar10 >> 0xc & 0x30 | *(uint *)(iVar13 + 0x14) & 0xffffffcf;
    iVar13 = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(iVar13 + 0x14) = uVar10 >> 6 & 0xc | *(uint *)(iVar13 + 0x14) & 0xfffffff3;
    iVar13 = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(iVar13 + 0x14) = uVar10 & 3 | *(uint *)(iVar13 + 0x14) & 0xfffffffc;
    iVar14 = param_1[0x18];
    iVar13 = param_1[0x2a];
    uVar15 = *(undefined4 *)(param_4 + 0x6c4);
    uVar7 = FUN_00105594(param_2,3);
    uVar8 = thunk_FUN_00134de8(uVar15,uVar7);
    *(undefined2 *)(iVar14 * 0x48 + iVar13 + 0x12) = uVar8;
  }
  if (iVar4 != 0) {
    iVar4 = 0;
    iVar13 = 4;
    do {
      *(undefined4 *)(iVar4 + (int)local_78) = 0;
      *(undefined4 *)(iVar4 + (int)local_58) = 0;
      *(undefined4 *)(iVar4 + (int)local_68) = 0;
      iVar4 = iVar4 + 4;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    (**(code **)(*param_1 + 0xf8))(param_1,1,local_58,local_78,0,unaff_r21);
    (**(code **)(*param_1 + 0x108))(param_1,1,local_78,piVar12,unaff_r22);
    (**(code **)(*param_1 + 0x10c))(param_1,1,local_68,piVar12,unaff_r22);
    FUN_00106004(param_2,1,piVar12,0,param_4);
    iVar4 = FUN_001054ec(param_2,1);
    *(undefined4 *)(iVar4 + 0x10) = unaff_r22;
    iVar4 = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(iVar4 + 0x14) = (local_78[1] & 3) << 0x16 | *(uint *)(iVar4 + 0x14) & 0xff3fffff;
    iVar4 = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(iVar4 + 0x14) = (local_78[1] & 0x18) << 0x11 | *(uint *)(iVar4 + 0x14) & 0xffcfffff;
    iVar4 = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(iVar4 + 0x14) = (local_78[1] & 0xc0) << 0xc | *(uint *)(iVar4 + 0x14) & 0xfff3ffff;
    iVar4 = param_1[0x18] * 0x48 + param_1[0x2a];
    *(uint *)(iVar4 + 0x14) = (local_68[1] & 0x600) << 7 | *(uint *)(iVar4 + 0x14) & 0xfffcffff;
  }
  return;
}

/* FUN_001a25a8 @ 0x1a25a8 (692 bytes) */
int FUN_001a25a8(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined1 uVar7;
  undefined1 auStack_48 [40];
  
  iVar1 = FUN_001043f0(0x12,param_1[3]);
  uVar2 = FUN_00105594(param_2,1);
  FUN_00106004(iVar1,1,uVar2,0,param_1[3]);
  iVar6 = iVar1 + 0xa4;
  iVar3 = FUN_001054ec(param_2,1);
  uVar2 = *(undefined4 *)(iVar3 + 0x10);
  iVar3 = FUN_001054ec(iVar1,1);
  uVar5 = *(uint *)(param_2 + 0xb8);
  *(undefined4 *)(iVar3 + 0x10) = uVar2;
  FUN_00103d50(iVar6,2,uVar5 >> 1 & 1);
  iVar3 = iVar1 + 0xbc;
  FUN_00103d50(iVar6,1,*(uint *)(param_2 + 0xb8) & 1);
  uVar2 = FUN_00105594(param_2,2);
  FUN_00106004(iVar1,2,uVar2,0,param_1[3]);
  iVar4 = FUN_001054ec(param_2,2);
  uVar2 = *(undefined4 *)(iVar4 + 0x10);
  iVar4 = FUN_001054ec(iVar1,2);
  uVar5 = *(uint *)(param_2 + 0xd0);
  *(undefined4 *)(iVar4 + 0x10) = uVar2;
  FUN_00103d50(iVar3,2,uVar5 >> 1 & 1);
  uVar7 = 2;
  FUN_00103d50(iVar3,1,*(uint *)(param_2 + 0xd0) & 1);
  *(undefined4 *)(iVar1 + 0x9c) = DAT_001b2d6c;
  iVar4 = FUN_001054ec(iVar1,0);
  *(undefined4 *)(iVar4 + 0xc) = 0;
  *(undefined4 *)(iVar4 + 8) = 0;
  switch(*(undefined4 *)(param_2 + 300)) {
  case 0:
    uVar7 = 0;
    FUN_00103d50(iVar3,1,*(uint *)(param_2 + 0xd0) & 1 ^ 1);
    break;
  case 1:
    uVar7 = 3;
    FUN_00103d50(iVar3,1,*(uint *)(param_2 + 0xd0) & 1 ^ 1);
    break;
  case 2:
    uVar5 = *(uint *)(param_2 + 0xb8);
    goto LAB_001a2784;
  case 3:
    uVar5 = *(uint *)(param_2 + 0xd0);
    goto LAB_001a27a4;
  case 4:
    uVar5 = *(uint *)(param_2 + 0xd0);
    iVar6 = iVar3;
LAB_001a2784:
    uVar7 = 1;
    FUN_00103d50(iVar6,1,uVar5 & 1 ^ 1);
    break;
  case 5:
    uVar5 = *(uint *)(param_2 + 0xb8);
    iVar3 = iVar6;
LAB_001a27a4:
    uVar7 = 2;
    FUN_00103d50(iVar3,1,uVar5 & 1 ^ 1);
  }
  FUN_001940a8(auStack_48);
  FUN_00193f64(auStack_48,iVar1);
  (**(code **)(*param_1 + 0x34))(param_1,auStack_48,param_3);
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -5) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -4) = uVar7;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x34) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x33) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -3) = 1;
  return;
}

