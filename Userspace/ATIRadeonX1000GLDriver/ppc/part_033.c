#include "decls.h"

/* FUN_0012c7c0 @ 0x12c7c0 (328 bytes) */
int FUN_0012c7c0(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 local_38 [8];
  
  if (*(int *)(*(int *)(param_2 + 0x88) + 8) == 0x12) {
    iVar6 = 0;
    iVar5 = -1;
    iVar7 = 0;
    do {
      iVar3 = FUN_001054ec(param_2,0);
      if (*(char *)(iVar7 + iVar3 + 0x10) != '\x01') {
        iVar5 = param_1[0xe];
        iVar6 = iVar6 + 1;
        if (iVar5 != iVar7) {
          return 0;
        }
        if (1 < iVar6) {
          return 0;
        }
      }
      bVar1 = iVar7 != 3;
      iVar7 = iVar7 + 1;
    } while (bVar1);
    iVar6 = FUN_00104054(param_2,param_1[0x10]);
    if (1 < iVar6) {
      *param_1 = 1;
    }
    iVar6 = FUN_00105594(param_1[0xd],1);
    if (param_2 == iVar6) {
      piVar4 = (int *)FUN_00105594(iVar6,2);
      iVar6 = (**(code **)(*piVar4 + 0x48))();
      if (iVar6 != 0) {
        iVar6 = FUN_001054ec(param_2,2);
        local_38[0] = *(undefined4 *)(iVar6 + 0x10);
        uVar2 = (uint)*(byte *)((int)local_38 + iVar5);
        if (((((int)*(char *)(piVar4 + 0x57) >> (uVar2 & 0x3f) & 1U) != 0) &&
            (piVar4[uVar2 * 6 + 7] == 2)) && ((float)piVar4[uVar2 * 6 + 8] == FLOAT_001aa0e8)) {
          return 1;
        }
      }
    }
  }
  return 0;
}

/* FUN_0012c908 @ 0x12c908 (952 bytes) */
int FUN_0012c908(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  byte bVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined4 local_38;
  int local_34;
  undefined4 local_30 [2];
  longlong local_28;
  
  *param_4 = 0;
  if (param_2 == 0) {
    return 0;
  }
  iVar3 = *(int *)(*(int *)(param_2 + 0x88) + 8);
  if (iVar3 == 0x8b) {
    iVar3 = FUN_00105594(param_2,1);
    if (iVar3 != *(int *)(param_1 + 0x34)) {
      return 0;
    }
    piVar7 = (int *)FUN_00105594(param_2,2);
    iVar3 = (**(code **)(*piVar7 + 0x48))();
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = FUN_0010b5f8(param_2);
    if (iVar3 != 3) {
      return 0;
    }
    iVar3 = FUN_001054ec(param_2,2);
    local_38 = *(undefined4 *)(iVar3 + 0x10);
    bVar1 = *(byte *)((int)&local_38 + *(int *)(param_1 + 0x38));
    uVar9 = (uint)bVar1;
    *(uint *)(param_1 + 0x14) = uVar9;
    if (piVar7[0x26] == 0x33) {
      local_34 = piVar7[uVar9 * 6 + 8];
      uVar4 = *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x3ac);
      local_30[0] = DAT_001affd0;
      *(byte *)((int)local_30 + uVar9) = bVar1;
      piVar7 = (int *)FUN_000f57f0(uVar4,&local_34,local_30);
      *(uint *)(param_1 + 0x14) = (uint)*(byte *)((int)local_30 + *(int *)(param_1 + 0x14));
      if (piVar7 == (int *)0x0) {
        return 0;
      }
    }
    *(int *)(param_1 + 0x10) = piVar7[0x25];
  }
  else {
    if (iVar3 != 0x8c) {
      return 0;
    }
    uVar4 = FUN_00105594(param_2,1);
    piVar5 = (int *)FUN_00105594(uVar4,1);
    piVar6 = (int *)FUN_00105594(uVar4,2);
    iVar3 = (**(code **)(*piVar5 + 0x48))(piVar5);
    piVar7 = piVar5;
    if (iVar3 == 0) {
      iVar3 = (**(code **)(*piVar6 + 0x48))(piVar6);
      if (iVar3 == 0) {
        return 0;
      }
      *param_4 = 1;
      piVar7 = piVar6;
      piVar6 = piVar5;
    }
    if (piVar6 != *(int **)(param_1 + 0x34)) {
      return 0;
    }
    iVar3 = FUN_00104054(uVar4,*(undefined4 *)(param_1 + 0x40));
    if (iVar3 != 1) {
      return 0;
    }
    iVar3 = FUN_0010b5f8(uVar4);
    if (*param_4 == 0) {
      if (iVar3 != 2) {
        return 0;
      }
    }
    else if (iVar3 != 3) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
    if ((*(byte *)(piVar7 + 0x57) & 1) == 0) {
      *(int *)(param_1 + 0x10) = piVar7[0x25];
      iVar3 = FUN_001054ec(param_2,1);
      local_38 = *(undefined4 *)(iVar3 + 0x10);
      *(uint *)(param_1 + 0x14) = (uint)*(byte *)((int)&local_38 + *(int *)(param_1 + 0x38));
      if (*param_4 == 0) {
        iVar3 = FUN_001054ec(uVar4,1);
        local_38 = *(undefined4 *)(iVar3 + 0x10);
      }
      else {
        iVar3 = FUN_001054ec(uVar4,2);
        local_38 = *(undefined4 *)(iVar3 + 0x10);
      }
      *(uint *)(param_1 + 0x14) = (uint)*(byte *)((int)&local_38 + *(int *)(param_1 + 0x14));
    }
    else {
      fVar2 = (float)piVar7[8];
      *(undefined4 *)(param_1 + 0x1c) = 1;
      local_28 = (longlong)(int)fVar2;
      *(int *)(param_1 + 0x18) = (int)fVar2;
    }
  }
  iVar3 = *(int *)(param_3 + 0x134);
  iVar10 = *(int *)(param_3 + 0x138);
  if (*param_4 == 0) {
    iVar8 = FUN_00194034(iVar3 + 0x90);
    if ((iVar8 < 3) && (iVar10 = FUN_00194034(iVar10 + 0x90), iVar10 < 3)) {
      piVar7 = (int *)FUN_000e920c(iVar3,0);
      iVar10 = (**(code **)(*piVar7 + 0x38))();
      if (iVar10 != 0) {
        uVar4 = FUN_000e920c(iVar3,0);
        *(undefined4 *)(param_1 + 0x24) = uVar4;
LAB_0012cc9c:
        *(int *)(param_1 + 0x28) = param_3;
        return 1;
      }
    }
  }
  else {
    iVar3 = FUN_000e7770(iVar10);
    if ((iVar3 != 0) && (iVar3 = FUN_00194034(iVar10 + 0x90), iVar3 < 3)) {
      piVar7 = (int *)FUN_000e920c(iVar10,0);
      *(int **)(param_1 + 0x24) = piVar7;
      iVar3 = (**(code **)(*piVar7 + 0x38))();
      if (iVar3 != 0) {
        uVar4 = FUN_000e920c(*(undefined4 *)(param_3 + 0x13c),0);
        iVar3 = FUN_000e7770();
        if ((iVar3 != 0) &&
           (iVar3 = FUN_000e920c(uVar4,0), iVar3 == *(int *)(*(int *)(param_1 + 0x2c) + 0x150)))
        goto LAB_0012cc9c;
      }
    }
  }
  return 0;
}

/* FUN_0012ccc0 @ 0x12ccc0 (740 bytes) */
int FUN_0012ccc0(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int local_88[0];
  int local_84 [12];
  undefined4 local_54;
  int local_44;
  
  piVar6 = (int *)(*(int **)(param_1 + 900))[2];
  if (piVar6 != (int *)0x0) {
    bVar1 = false;
    piVar8 = *(int **)(param_1 + 900);
    local_44 = param_1;
    do {
      piVar7 = piVar6;
      iVar3 = (**(code **)(*piVar8 + 0x2c))(piVar8);
      if ((iVar3 != 0) && (iVar3 = FUN_0012ba58(local_84,piVar8), iVar3 != 0)) {
        local_84[0] = 0;
        iVar3 = piVar8[0x26];
        for (iVar2 = *(int *)(piVar8[0x26] + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
          if ((*(int *)(*(int *)(iVar3 + 0x88) + 8) == 0x8e) &&
             (iVar4 = FUN_0012b35c(local_84,iVar3), iVar4 != 0)) {
            uVar5 = FUN_00105594(iVar3,2);
            iVar4 = FUN_0012c59c(local_84,uVar5);
            if (iVar4 != 0) {
              uVar5 = FUN_00105594(iVar3,1);
              iVar3 = ((int (*)())FUN_0012c7c0)(local_84,uVar5);
              if (iVar3 != 0) {
                local_54 = uVar5;
                piVar6 = (int *)FUN_000e920c(piVar8,0);
                iVar3 = (**(code **)(*piVar6 + 0x24))();
                if (iVar3 == 0) {
                  iVar3 = FUN_000e7770(piVar6);
                  if (iVar3 != 0) {
                    iVar3 = FUN_00194034(piVar6 + 0x24);
                    if ((iVar3 < 3) || (iVar3 = FUN_00194034(piVar6 + 0x24), iVar3 == 3)) {
                      piVar6 = (int *)FUN_000e920c(piVar6,0);
                      iVar3 = (**(code **)(*piVar6 + 0x24))();
                      if (iVar3 != 0) goto LAB_0012ce40;
                    }
                  }
                }
                else {
LAB_0012ce40:
                  uVar5 = FUN_000e7804(piVar6);
                  piVar9 = (int *)piVar6[0x4f];
                  local_88[0] = 0;
                  iVar3 = ((int (*)())FUN_0012c908)(local_84,uVar5,piVar6,&local_88);
                  if (iVar3 != 0) {
                    if ((local_88[0] == 0) && (piVar6 = (int *)piVar8[0x54], piVar9 != piVar6)) {
                      iVar3 = 0;
                      do {
                        iVar4 = (**(code **)(*piVar9 + 0x2c))(piVar9);
                        if (iVar4 == 0) {
                          iVar4 = (**(code **)(*piVar9 + 0x30))(piVar9);
                          if (iVar4 == 0) {
                            if (iVar3 == 0) {
                              (**(code **)(*piVar9 + 0x38))(piVar9);
                            }
                          }
                          else {
                            iVar3 = iVar3 + -1;
                          }
                        }
                        else {
                          iVar3 = iVar3 + 1;
                        }
                        piVar9 = (int *)piVar9[2];
                      } while (piVar6 != piVar9);
                    }
                    iVar3 = FUN_0012b6a8(local_84,local_88[0]);
                    bVar1 = bVar1 || iVar3 != 0;
                    if (iVar3 != 0) {
                      FUN_000ed7e4(param_1,"loop_trans");
                    }
                  }
                }
              }
            }
          }
          iVar3 = iVar2;
        }
      }
      piVar6 = (int *)piVar7[2];
      piVar8 = piVar7;
    } while (piVar6 != (int *)0x0);
    if (bVar1) {
      FUN_000ec2e8(param_1);
      FUN_0013bd68(param_1,0);
      return 1;
    }
  }
  return 0;
}

/* FUN_0012cfa4 @ 0x12cfa4 (820 bytes) */
int FUN_0012cfa4(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  undefined4 param_3;
  int *param_4;
{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint local_54;
  uint local_50;
  int local_4c;
  undefined4 local_48;
  
  local_48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_50 = 0;
  local_54 = 2;
  local_4c = FUN_00193e18(local_48,8);
  uVar8 = local_50;
  if (local_50 < local_54) {
    iVar7 = local_50 * 4;
    _memset((void *)(local_4c + iVar7),0,4);
    local_50 = uVar8 + 1;
    puVar4 = (undefined4 *)(iVar7 + local_4c);
  }
  else {
    puVar4 = (undefined4 *)FUN_0019423c(&local_54,local_50);
  }
  *puVar4 = param_3;
  while (local_50 != 0) {
    piVar2 = (int *)0x0;
    if (local_50 - 1 < local_50) {
      piVar2 = (int *)((local_50 - 1) * 4 + local_4c);
    }
    iVar7 = *piVar2;
    FUN_00194208(&local_54);
    piVar2 = *(int **)(iVar7 + 0x98);
    for (piVar3 = (int *)piVar2[2]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[2]) {
      if ((piVar2[5] & 1U) != 0) {
        iVar5 = (**(code **)(*piVar2 + 0x34))(piVar2);
        if ((iVar5 == 0) && (iVar5 = (**(code **)(*piVar2 + 0x38))(piVar2), iVar5 == 0)) {
          if (*(int *)(piVar2[0x22] + 8) != 0x8e) {
            piVar3 = piVar2;
            for (iVar5 = 1; iVar6 = (**(code **)(*piVar2 + 0x14))(piVar2), iVar5 <= iVar6;
                iVar5 = iVar5 + 1) {
              FUN_001234d8(piVar3[0x29],piVar2);
              piVar3 = piVar3 + 6;
            }
          }
          (**(code **)(*piVar2 + 0xc))(piVar2,0,*(undefined4 *)(param_1 + 8));
        }
        piVar3 = (int *)piVar2[2];
      }
      piVar2 = piVar3;
    }
    iVar5 = 0;
    for (uVar8 = 1; iVar6 = *(int *)(iVar7 + 0xd0), uVar8 <= *(uint *)(iVar6 + 4); uVar8 = uVar8 + 1
        ) {
      piVar2 = *(int **)(*(int *)(iVar6 + 8) + iVar5);
      if ((((piVar2 != (int *)0x0) && (piVar2 != param_4)) && (piVar2 != param_2)) &&
         (((iVar6 = (**(code **)(*piVar2 + 0x38))(), iVar6 == 0 &&
           (iVar6 = (**(code **)(*piVar2 + 0x3c))(), iVar6 == 0)) &&
          (iVar6 = FUN_00194034(piVar2 + 0x24), uVar1 = local_50, 2 < iVar6)))) {
        if (local_50 < local_54) {
          iVar6 = local_50 * 4;
          _memset((void *)(iVar6 + local_4c),0,4);
          local_50 = uVar1 + 1;
          puVar4 = (undefined4 *)(iVar6 + local_4c);
        }
        else {
          puVar4 = (undefined4 *)FUN_0019423c(&local_54,local_50);
        }
        *puVar4 = piVar2;
      }
      iVar5 = iVar5 + 4;
    }
  }
  local_50 = 0;
  piVar2 = (int *)param_4[0x26];
  for (piVar3 = (int *)((int *)param_4[0x26])[2]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[2]) {
    if ((piVar2[5] & 1U) != 0) {
      piVar3 = (int *)(**(code **)(*piVar2 + 0x7c))(piVar2);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0xc))(piVar3,0,*(undefined4 *)(param_1 + 8));
      }
      piVar3 = (int *)piVar2[2];
    }
    piVar2 = piVar3;
  }
  FUN_00194034(param_4 + 0x24);
  FUN_00193cc0(local_48,local_4c);
  return;
}

/* FUN_0012d2f0 @ 0x12d2f0 (2556 bytes) */
int FUN_0012d2f0(param_1)
  int param_1;
{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined4 uVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  int *piVar17;
  int iVar18;
  int iVar19;
  int *piVar20;
  uint *puVar21;
  uint *puVar22;
  int iVar23;
  undefined1 auStack_68 [4];
  undefined4 local_64;
  int local_60 [2];
  int local_58;
  int *local_54;
  
  piVar17 = *(int **)(param_1 + 900);
  piVar20 = (int *)piVar17[2];
  if (piVar20 != (int *)0x0) {
    bVar1 = false;
    do {
      iVar5 = (**(code **)(*piVar17 + 0x28))(piVar17);
      if ((iVar5 != 0) && (iVar5 = (**(code **)(*piVar17 + 0x40))(piVar17), iVar5 == 0)) {
        iVar5 = *(int *)(param_1 + 8);
        if (*(int *)(iVar5 + 0x6a8) <= *(int *)(*(int *)(iVar5 + 0x6c4) + 0x15c)) break;
        iVar14 = piVar17[0x4b];
        iVar5 = (**(code **)(**(int **)(iVar5 + 0x30c) + 0x114))(*(int **)(iVar5 + 0x30c),iVar14);
        if ((iVar5 == 0) || (iVar5 = FUN_000e87e4(iVar14,auStack_68), iVar5 != 0)) break;
        puVar21 = (uint *)piVar17[0x35];
        iVar5 = *(int *)(iVar14 + 0x134);
        iVar18 = *(int *)(iVar14 + 0x138);
        if (*puVar21 == 0) {
          piVar20 = (int *)FUN_0019423c(puVar21,0);
          puVar22 = (uint *)piVar17[0x35];
        }
        else {
          puVar22 = puVar21;
          if (puVar21[1] == 0) {
            *(undefined4 *)puVar21[2] = 0;
            puVar21[1] = 1;
            puVar22 = (uint *)piVar17[0x35];
          }
          piVar20 = (int *)puVar21[2];
        }
        iVar19 = *piVar20;
        if (*puVar22 < 2) {
          piVar20 = (int *)FUN_0019423c(puVar22,1);
        }
        else {
          uVar6 = puVar22[1];
          if (uVar6 < 2) {
            _memset((void *)(uVar6 * 4 + puVar22[2]),0,(1 - uVar6) * 4 + 4);
            puVar22[1] = 2;
          }
          piVar20 = (int *)(puVar22[2] + 4);
        }
        piVar7 = *(int **)(iVar14 + 0xd4);
        iVar23 = *piVar20;
        if (*piVar7 == 0) {
          piVar20 = (int *)FUN_0019423c(piVar7,0);
        }
        else {
          if (piVar7[1] == 0) {
            *(undefined4 *)piVar7[2] = 0;
            piVar7[1] = 1;
          }
          piVar20 = (int *)piVar7[2];
        }
        local_58 = *piVar20;
        piVar20 = (int *)piVar17[0x34];
        if (*piVar20 == 0) {
          piVar20 = (int *)FUN_0019423c(piVar20,0);
        }
        else {
          if (piVar20[1] == 0) {
            *(undefined4 *)piVar20[2] = 0;
            piVar20[1] = 1;
          }
          piVar20 = (int *)piVar20[2];
        }
        iVar16 = *piVar20;
        piVar20 = *(int **)(local_58 + 0xd0);
        if (*piVar20 == 0) {
          piVar20 = (int *)FUN_0019423c(piVar20,0);
        }
        else {
          if (piVar20[1] == 0) {
            *(undefined4 *)piVar20[2] = 0;
            piVar20[1] = 1;
          }
          piVar20 = (int *)piVar20[2];
        }
        *piVar20 = iVar5;
        piVar20 = *(int **)(iVar5 + 0xd4);
        if (*piVar20 == 0) {
          piVar20 = (int *)FUN_0019423c(piVar20,0);
        }
        else {
          if (piVar20[1] == 0) {
            *(undefined4 *)piVar20[2] = 0;
            piVar20[1] = 1;
          }
          piVar20 = (int *)piVar20[2];
        }
        *piVar20 = local_58;
        piVar20 = *(int **)(iVar16 + 0xd4);
        if (*piVar20 == 0) {
          piVar20 = (int *)FUN_0019423c(piVar20,0);
        }
        else {
          if (piVar20[1] == 0) {
            *(undefined4 *)piVar20[2] = 0;
            piVar20[1] = 1;
          }
          piVar20 = (int *)piVar20[2];
        }
        *piVar20 = iVar23;
        piVar20 = *(int **)(iVar23 + 0xd0);
        if (*piVar20 == 0) {
          piVar20 = (int *)FUN_0019423c(piVar20,0);
        }
        else {
          if (piVar20[1] == 0) {
            *(undefined4 *)piVar20[2] = 0;
            piVar20[1] = 1;
          }
          piVar20 = (int *)piVar20[2];
        }
        *piVar20 = iVar16;
        piVar20 = *(int **)(iVar19 + 0xd0);
        if (*piVar20 == 0) {
          piVar20 = (int *)FUN_0019423c(piVar20,0);
        }
        else {
          if (piVar20[1] == 0) {
            *(undefined4 *)piVar20[2] = 0;
            piVar20[1] = 1;
          }
          piVar20 = (int *)piVar20[2];
        }
        *piVar20 = iVar18;
        piVar20 = *(int **)(iVar18 + 0xd4);
        if (*piVar20 == 0) {
          piVar20 = (int *)FUN_0019423c(piVar20,0);
        }
        else {
          if (piVar20[1] == 0) {
            *(undefined4 *)piVar20[2] = 0;
            piVar20[1] = 1;
          }
          piVar20 = (int *)piVar20[2];
        }
        *piVar20 = iVar19;
        *(int *)(iVar5 + 0xf0) = local_58;
        *(int *)(iVar18 + 0xf0) = iVar19;
        *(int *)(iVar16 + 0xf0) = iVar23;
        piVar20 = (int *)FUN_000e7804(iVar14);
        if (*(int *)(piVar20[0x22] + 8) == 0x8b) {
          iVar5 = FUN_0010b498(piVar20,2);
          if (iVar5 == 0) {
            iVar5 = FUN_0010b498(piVar20,1);
            if (iVar5 == 0) {
              piVar8 = (int *)FUN_001043f0(0x12,*(undefined4 *)(param_1 + 8));
              piVar8[0x26] = 0;
              piVar8[0x25] = piVar8[0x53];
              uVar11 = FUN_001054ec(piVar20,1);
              FUN_001062c0(piVar8,1,uVar11,*(undefined4 *)(param_1 + 8));
              uVar11 = FUN_001054ec(piVar20,2);
              FUN_001062c0(piVar8,2,uVar11,*(undefined4 *)(param_1 + 8));
              FUN_00103d50(piVar8 + 0x2f,1,piVar20[0x34] & 1U ^ 1);
              FUN_000e76c4(iVar16,piVar8);
              FUN_00105f04(piVar8,param_1);
              uVar11 = DAT_001affd8;
              for (iVar5 = 1; iVar18 = (**(code **)(*piVar8 + 0x14))(piVar8), iVar5 <= iVar18;
                  iVar5 = iVar5 + 1) {
                piVar7 = (int *)FUN_00105594(piVar8,iVar5);
                iVar18 = (**(code **)(*piVar7 + 0x5c))();
                if (iVar18 != 0) {
                  FUN_0019401c(piVar7);
                  FUN_000e7700(iVar16,piVar8,piVar7);
                }
              }
              uVar6 = 0;
              uVar12 = 0;
              piVar7 = piVar8;
            }
            else {
              piVar7 = *(int **)(iVar16 + 200);
              piVar8 = (int *)FUN_00105594(piVar20,2);
              iVar5 = FUN_001054ec(piVar20,2);
              uVar11 = *(undefined4 *)(iVar5 + 0x10);
              uVar6 = piVar20[0x34] & 1;
              uVar12 = (uint)piVar20[0x34] >> 1 & 1;
              iVar5 = FUN_0010b5f8(piVar20);
              FUN_0010b914(piVar20,*(undefined4 *)(PTR_DAT_001e90f8 + iVar5 * 4));
            }
          }
          else {
            piVar7 = *(int **)(iVar16 + 200);
            piVar8 = (int *)FUN_00105594(piVar20,1);
            iVar5 = FUN_001054ec(piVar20,1);
            uVar11 = *(undefined4 *)(iVar5 + 0x10);
            uVar6 = piVar20[0x2e] & 1;
            uVar12 = (uint)piVar20[0x2e] >> 1 & 1;
          }
        }
        else {
          piVar7 = *(int **)(iVar16 + 200);
          piVar8 = (int *)FUN_00105594(piVar20,1);
          iVar18 = FUN_001054ec(piVar20,1);
          iVar5 = *(int *)(piVar8[0x22] + 8);
          uVar11 = *(undefined4 *)(iVar18 + 0x10);
          uVar6 = piVar20[0x2e] & 1U ^ 1;
          if ((((iVar5 == 0x27) || (iVar5 == 0x29)) || (iVar5 == 0x2a)) ||
             (uVar12 = 1, iVar5 == 0x28)) {
            uVar12 = 0;
          }
        }
        local_54 = piVar17 + 0x24;
        piVar2 = (int *)piVar17[0x26];
        for (piVar3 = (int *)((int *)piVar17[0x26])[2]; piVar3 != (int *)0x0;
            piVar3 = (int *)piVar3[2]) {
          if (*(int *)(piVar2[0x22] + 8) == 0x8e) {
            iVar5 = FUN_001054ec(piVar2,0);
            local_60[0] = *(int *)(iVar5 + 0x10);
            uVar9 = FUN_00105594(piVar2,1);
            uVar10 = FUN_00105594(piVar2,2);
            iVar18 = 4;
            iVar5 = 0;
            local_64 = uVar11;
            do {
              if (*(char *)((int)local_60 + iVar5) == '\x01') {
                *(undefined1 *)((int)local_60 + iVar5 + -4) = 4;
              }
              iVar5 = iVar5 + 1;
              iVar18 = iVar18 + -1;
            } while (iVar18 != 0);
            iVar5 = FUN_001054ec(piVar2,1);
            uVar15 = *(undefined4 *)(iVar5 + 0x10);
            iVar5 = FUN_001054ec(piVar2,2);
            uVar13 = *(undefined4 *)(iVar5 + 0x10);
            iVar5 = piVar2[0x58] - *(int *)(param_1 + 0x478);
            if (iVar5 < 0) {
              iVar5 = 0;
            }
            iVar19 = piVar2[4];
            FUN_00105b24(piVar2,param_1);
            FUN_0019401c(piVar2);
            FUN_00108304(piVar2,0x25,*(undefined4 *)(param_1 + 8));
            FUN_000e7738(iVar16,piVar7,piVar2);
            iVar18 = *(int *)(param_1 + 0x478);
            piVar2[4] = iVar19;
            piVar2[0x58] = iVar5 + iVar18;
            piVar2[0x25] = piVar2[0x53];
            piVar2[0x26] = 0;
            piVar2[0x27] = local_60[0];
            FUN_00106004(piVar2,1,piVar8,*(uint *)(param_1 + 0x30) >> 7 & 1,
                         *(undefined4 *)(param_1 + 8));
            uVar4 = local_64;
            iVar5 = FUN_001054ec(piVar2,1);
            *(undefined4 *)(iVar5 + 0x10) = uVar4;
            FUN_00103d50(piVar2 + 0x29,1,uVar6);
            FUN_00103d50(piVar2 + 0x29,2,uVar12);
            FUN_00106004(piVar2,2,uVar9,*(uint *)(param_1 + 0x30) >> 7 & 1,
                         *(undefined4 *)(param_1 + 8));
            iVar5 = FUN_001054ec(piVar2,2);
            *(undefined4 *)(iVar5 + 0x10) = uVar15;
            FUN_00106004(piVar2,3,uVar10,*(uint *)(param_1 + 0x30) >> 7 & 1,
                         *(undefined4 *)(param_1 + 8));
            iVar5 = FUN_001054ec(piVar2,3);
            *(undefined4 *)(iVar5 + 0x10) = uVar13;
            piVar7 = piVar2;
            if (*(int *)(piVar20[0x22] + 8) == 0x8b) {
              FUN_0012b3f8(piVar20,piVar2,*(undefined4 *)(param_1 + 8));
            }
          }
          else {
            iVar5 = (**(code **)(*piVar2 + 0x34))(piVar2);
            if (iVar5 == 0) break;
          }
          piVar2 = piVar3;
        }
        FUN_000ef970(param_1,piVar20);
        piVar20[5] = piVar20[5] & 0xffffffef;
        (**(code **)(*piVar20 + 0xc))
                  (piVar20,*(uint *)(param_1 + 0x30) >> 7 & 1,*(undefined4 *)(param_1 + 8));
        iVar5 = FUN_001049c4(piVar8,param_1);
        if (iVar5 != 0) {
          (**(code **)(*piVar8 + 0xc))
                    (piVar8,*(uint *)(param_1 + 0x30) >> 7 & 1,*(undefined4 *)(param_1 + 8));
        }
        *(undefined4 *)(iVar14 + 0x130) = 0;
        if ((*(int *)(iVar14 + 0x144) != 0) && (*(int *)(iVar14 + 0x140) != 0)) {
          *(undefined4 *)(*(int *)(iVar14 + 0x140) + 0x144) = 1;
        }
        FUN_000e7658(iVar14);
        piVar20 = (int *)local_54[2];
        for (piVar8 = (int *)((int *)local_54[2])[2]; piVar8 != (int *)0x0;
            piVar8 = (int *)piVar8[2]) {
          iVar5 = (**(code **)(*piVar20 + 0x34))(piVar20);
          if (iVar5 == 0) {
            iVar5 = (**(code **)(*piVar20 + 0x38))(piVar20);
            if (iVar5 != 0) break;
            FUN_0019401c(piVar20);
            FUN_000e7738(iVar16,piVar7,piVar20);
            piVar7 = piVar20;
          }
          piVar20 = piVar8;
        }
        FUN_000e7658(piVar17);
        iVar5 = local_58;
        do {
          bVar1 = true;
          iVar14 = FUN_000e7f38(iVar5);
          if (((iVar16 != iVar14) && (bVar1 = false, iVar14 == 0)) ||
             (iVar14 = FUN_0012aef0(param_1,iVar5,iVar14), iVar14 == 0)) {
            iVar5 = *(int *)(iVar5 + 8);
          }
        } while ((!bVar1) && (iVar5 != iVar16));
        bVar1 = true;
        piVar20 = *(int **)(local_58 + 8);
      }
      piVar17 = piVar20;
      piVar20 = (int *)piVar17[2];
    } while (piVar20 != (int *)0x0);
    if (bVar1) {
      FUN_000ec2e8(param_1);
      FUN_000ed7e4(param_1,"flatten_ifs");
      FUN_0013bd68(param_1,0);
    }
  }
  return;
}

/* FUN_0012dcf0 @ 0x12dcf0 (88 bytes) */
int FUN_0012dcf0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = FUN_000e0830(*(undefined4 *)(param_2 + 8),0,0);
  if (iVar1 == 0) {
    ((int (*)())FUN_0012d2f0)(param_2);
    return;
  }
  return;
}

/* FUN_0012dd58 @ 0x12dd58 (544 bytes) */
int FUN_0012dd58(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint local_44;
  uint local_40;
  undefined4 *local_3c;
  undefined4 local_38;
  
  *(int *)(param_1 + 0x474) = *(int *)(param_1 + 0x474) + 1;
  local_38 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_40 = 0;
  local_44 = 2;
  local_3c = (undefined4 *)FUN_00193e18(local_38,8);
  iVar1 = FUN_000e9184(param_2,0);
  FUN_00194374(*(undefined4 *)(iVar1 + 0xd0),param_2);
  iVar2 = FUN_000e920c(param_3,0);
  FUN_00194374(*(undefined4 *)(iVar2 + 0xd4),param_3);
  FUN_000e8e4c(iVar1,iVar2);
  while( true ) {
    iVar1 = 0;
    for (uVar5 = 1; uVar5 <= *(uint *)(param_2[0x34] + 4); uVar5 = uVar5 + 1) {
      iVar2 = *(int *)(*(int *)(param_2[0x34] + 8) + iVar1);
      if (((iVar2 != 0) && (*(int *)(param_1 + 0x474) != *(int *)(iVar2 + 0x118))) &&
         (param_3 != iVar2)) {
        *(int *)(iVar2 + 0x118) = *(int *)(param_1 + 0x474);
        if (local_40 < local_44) {
          local_3c[local_40] = 0;
          piVar3 = local_3c + local_40;
          local_40 = local_40 + 1;
        }
        else {
          piVar3 = (int *)FUN_0019423c(&local_44);
        }
        *piVar3 = iVar2;
      }
      iVar1 = iVar1 + 4;
    }
    iVar1 = (**(code **)(*param_2 + 0x24))(param_2);
    if ((iVar1 != 0) && (piVar3 = (int *)FUN_000e7804(param_2), piVar3 != (int *)0x0)) {
      FUN_000ef970(param_1,piVar3);
      (**(code **)(*piVar3 + 0xc))
                (piVar3,*(uint *)(param_1 + 0x30) >> 7 & 1,*(undefined4 *)(param_1 + 8));
      param_2[0x4c] = 0;
    }
    FUN_000e7658(param_2);
    if (local_40 == 0) break;
    puVar4 = local_3c;
    if (local_44 == 0) {
      puVar4 = (undefined4 *)FUN_0019423c(&local_44,0);
    }
    param_2 = (int *)*puVar4;
    if ((param_2 == (int *)0x0) || (iVar1 = FUN_00194374(&local_44,param_2), iVar1 == 0)) break;
  }
  FUN_000e7658(param_3);
  FUN_00193cc0(local_38,local_3c);
  return;
}

/* FUN_0012df90 @ 0x12df90 (1248 bytes) */
int FUN_0012df90(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  int *param_3;
  int *param_4;
  int *param_5;
{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  uint local_64;
  uint local_60;
  int local_5c;
  undefined4 local_58;
  
  if (param_2[0x53] == 1) {
    iVar11 = param_2[0x4e];
  }
  else {
    iVar11 = param_2[0x4d];
  }
  *(int *)(param_1 + 0x474) = *(int *)(param_1 + 0x474) + 1;
  local_58 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_60 = 0;
  local_64 = 2;
  local_5c = FUN_00193e18(local_58,8);
  uVar10 = local_60;
  if (local_60 < local_64) {
    iVar7 = local_60 * 4;
    _memset((void *)(local_5c + iVar7),0,4);
    local_60 = uVar10 + 1;
    piVar2 = (int *)(iVar7 + local_5c);
  }
  else {
    piVar2 = (int *)FUN_0019423c(&local_64,local_60);
  }
  *piVar2 = iVar11;
  *(undefined4 *)(iVar11 + 0x118) = *(undefined4 *)(param_1 + 0x474);
  while (local_60 != 0) {
    puVar1 = (undefined4 *)0x0;
    if (local_60 - 1 < local_60) {
      puVar1 = (undefined4 *)((local_60 - 1) * 4 + local_5c);
    }
    piVar2 = (int *)*puVar1;
    FUN_00194208(&local_64);
    iVar11 = (**(code **)(*piVar2 + 0x38))(piVar2);
    if ((iVar11 == 0) && (iVar11 = (**(code **)(*piVar2 + 0x3c))(piVar2), iVar11 == 0)) {
      iVar11 = 0;
      for (uVar10 = 1; uVar10 <= *(uint *)(piVar2[0x34] + 4); uVar10 = uVar10 + 1) {
        piVar6 = *(int **)(iVar11 + *(int *)(piVar2[0x34] + 8));
        if ((((piVar6 != (int *)0x0) && (*(int *)(param_1 + 0x474) != piVar6[0x46])) &&
            (piVar6 != param_3)) && (piVar6 != param_2)) {
          iVar7 = (**(code **)(*piVar6 + 0x38))();
          if ((iVar7 != 0) || (iVar7 = (**(code **)(*piVar6 + 0x3c))(), iVar7 != 0)) {
            piVar3 = (int *)piVar6[0x34];
            if (*piVar3 == 0) {
              piVar3 = (int *)FUN_0019423c(piVar3,0);
            }
            else {
              if (piVar3[1] == 0) {
                *(undefined4 *)piVar3[2] = 0;
                piVar3[1] = 1;
              }
              piVar3 = (int *)piVar3[2];
            }
            iVar7 = *piVar3;
            uVar4 = FUN_000e803c(iVar7,piVar6);
            puVar12 = *(uint **)(iVar7 + 0xd4);
            if (uVar4 < *puVar12) {
              uVar5 = puVar12[1];
              if (uVar5 <= uVar4) {
                _memset((void *)(uVar5 * 4 + puVar12[2]),0,(uVar4 - uVar5) * 4 + 4);
                puVar12[1] = uVar4 + 1;
              }
              puVar1 = (undefined4 *)(uVar4 * 4 + puVar12[2]);
            }
            else {
              puVar1 = (undefined4 *)FUN_0019423c(puVar12,uVar4);
            }
            *puVar1 = 0;
          }
          uVar4 = local_60;
          piVar6[0x46] = *(int *)(param_1 + 0x474);
          if (local_60 < local_64) {
            iVar7 = local_60 * 4;
            _memset((void *)(iVar7 + local_5c),0,4);
            local_60 = uVar4 + 1;
            puVar1 = (undefined4 *)(iVar7 + local_5c);
          }
          else {
            puVar1 = (undefined4 *)FUN_0019423c(&local_64,local_60);
          }
          *puVar1 = piVar6;
        }
        iVar11 = iVar11 + 4;
      }
    }
    FUN_00194034(piVar2 + 0x24);
    FUN_000e7658(piVar2);
  }
  piVar2 = (int *)FUN_000e7804(param_2);
  param_2[0x4c] = 0;
  FUN_000ef970(param_1,piVar2);
  (**(code **)(*piVar2 + 0xc))(piVar2,0,*(undefined4 *)(param_1 + 8));
  FUN_00194034(param_2 + 0x24);
  iVar7 = FUN_000e7e90(param_2);
  iVar8 = FUN_000e7f38(param_3);
  iVar11 = param_2[0x53];
  iVar9 = FUN_000e920c(param_2,iVar11 != 1);
  *param_4 = iVar9;
  piVar2 = *(int **)(iVar9 + 0xd4);
  if (*piVar2 == 0) {
    piVar2 = (int *)FUN_0019423c(piVar2,0);
  }
  else {
    if (piVar2[1] == 0) {
      *(undefined4 *)piVar2[2] = 0;
      piVar2[1] = 1;
    }
    piVar2 = (int *)piVar2[2];
  }
  *piVar2 = iVar7;
  piVar2 = *(int **)(iVar7 + 0xd0);
  if (*piVar2 == 0) {
    piVar2 = (int *)FUN_0019423c(piVar2,0);
  }
  else {
    if (piVar2[1] == 0) {
      *(undefined4 *)piVar2[2] = 0;
      piVar2[1] = 1;
    }
    piVar2 = (int *)piVar2[2];
  }
  *piVar2 = *param_4;
  iVar11 = FUN_000e9184(param_3,iVar11 != 1);
  *param_5 = iVar11;
  piVar2 = *(int **)(iVar11 + 0xd0);
  if (*piVar2 == 0) {
    piVar2 = (int *)FUN_0019423c(piVar2,0);
  }
  else {
    if (piVar2[1] == 0) {
      *(undefined4 *)piVar2[2] = 0;
      piVar2[1] = 1;
    }
    piVar2 = (int *)piVar2[2];
  }
  *piVar2 = iVar8;
  piVar2 = *(int **)(iVar8 + 0xd4);
  if (*piVar2 == 0) {
    piVar2 = (int *)FUN_0019423c(piVar2,0);
  }
  else {
    if (piVar2[1] == 0) {
      *(undefined4 *)piVar2[2] = 0;
      piVar2[1] = 1;
    }
    piVar2 = (int *)piVar2[2];
  }
  *piVar2 = *param_5;
  FUN_000e7658(param_2);
  FUN_000e7658(param_3);
  FUN_000ec2e8(param_1);
  FUN_00193cc0(local_58,local_5c);
  return;
}

/* FUN_0012e488 @ 0x12e488 (196 bytes) */
int FUN_0012e488(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  puVar1 = (undefined4 *)FUN_000e920c(param_2,0);
  iVar2 = FUN_00194034(puVar1 + 0x24);
  if ((2 < iVar2) || (iVar2 = FUN_000e7770(puVar1), puVar4 = puVar1, iVar2 == 0)) {
    uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
    puVar3 = (undefined4 *)FUN_00193e18(uVar5,0x130);
    *puVar3 = uVar5;
    puVar4 = puVar3 + 1;
    FUN_000ea020(puVar4,*(undefined4 *)(param_1 + 8));
    puVar3[0x2f] = *(undefined4 *)(param_2 + 0xb8);
    FUN_000ec3ac(param_1,param_2,puVar4);
    FUN_000e977c(param_2,puVar1,puVar4);
    FUN_000e8e4c(puVar4,puVar1);
  }
  return puVar4;
}

/* FUN_0012e56c @ 0x12e56c (680 bytes) */
int FUN_0012e56c(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  
  iVar2 = (**(code **)(*param_2 + 0x30))(param_2);
  if (iVar2 != 0) {
    uVar13 = *(undefined4 *)(param_3 + 0x374);
    iVar7 = param_2[0x4b];
    uVar5 = *(undefined4 *)(param_3 + 0x6c4);
    puVar3 = (undefined4 *)FUN_00193e18(uVar13,0x168);
    puVar6 = puVar3 + 1;
    *puVar3 = uVar13;
    FUN_0010502c(puVar6,0x8c,param_3);
    puVar3[0x4c] = 6;
    iVar2 = FUN_001054ec(puVar6,1);
    puVar1 = PTR_DAT_001e8b8c;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    uVar13 = *(undefined4 *)puVar1;
    *(undefined4 *)(iVar2 + 8) = param_1;
    iVar2 = FUN_001054ec(puVar6,1);
    *(undefined4 *)(iVar2 + 0x10) = uVar13;
    uVar11 = *(undefined4 *)(iVar7 + 0xb8);
    uVar13 = FUN_000e920c(iVar7,0);
    uVar14 = *(undefined4 *)(param_3 + 0x374);
    puVar3 = (undefined4 *)FUN_00193e18(uVar14,0x130);
    puVar8 = puVar3 + 1;
    *puVar3 = uVar14;
    FUN_000ea020(puVar8,param_3);
    puVar3[0x2f] = uVar11;
    FUN_000ec3ac(uVar5,iVar7,puVar8);
    FUN_000e977c(iVar7,uVar13,puVar8);
    uVar11 = FUN_0012b140(iVar7);
    uVar14 = *(undefined4 *)(param_3 + 0x374);
    puVar3 = (undefined4 *)FUN_00193e18(uVar14,0x130);
    puVar10 = puVar3 + 1;
    *puVar3 = uVar14;
    FUN_000ea020(puVar10,param_3);
    uVar14 = *(undefined4 *)(param_3 + 0x374);
    puVar3 = (undefined4 *)FUN_00193e18(uVar14,0x138);
    puVar9 = puVar3 + 1;
    *puVar3 = uVar14;
    FUN_000ec0c8(puVar9,iVar7,1,param_3);
    uVar14 = *(undefined4 *)(param_3 + 0x374);
    puVar3 = (undefined4 *)FUN_00193e18(uVar14,0x15c);
    puVar12 = puVar3 + 1;
    *puVar3 = uVar14;
    FUN_000ea6d0(puVar12,puVar6,uVar11,puVar10,param_3);
    uVar11 = *(undefined4 *)(param_3 + 0x374);
    puVar4 = (undefined4 *)FUN_00193e18(uVar11,0x134);
    puVar15 = puVar4 + 1;
    *puVar4 = uVar11;
    FUN_000ea148(puVar15,param_3);
    puVar4[0x4c] = puVar12;
    *puVar15 = PTR_DAT_001e9130 + 8;
    puVar3[0x4e] = puVar10;
    puVar3[0x4f] = puVar9;
    puVar3[0x50] = puVar15;
    FUN_000ec3ac(uVar5,puVar8,puVar12);
    FUN_000ec3ac(uVar5,puVar12,puVar10);
    FUN_000ec3ac(uVar5,puVar10,puVar9);
    FUN_000ec3ac(uVar5,puVar9,puVar15);
    FUN_000e8e4c(puVar8,puVar12);
    FUN_000e8e4c(puVar12,puVar10);
    FUN_000e8e4c(puVar12,puVar9);
    FUN_000e8e4c(puVar10,puVar15);
    FUN_000e8e4c(puVar9,*(undefined4 *)(iVar7 + 0x154));
    FUN_000e8e4c(puVar15,uVar13);
    FUN_000ed63c(uVar5,puVar6);
    return;
  }
  return;
}

/* FUN_0012e8c0 @ 0x12e8c0 (488 bytes) */
int FUN_0012e8c0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  piVar1 = param_2;
  do {
    if (piVar1 == param_3) {
      return;
    }
    piVar1 = (int *)FUN_000e920c(param_2,0);
    iVar2 = FUN_0012aef0(param_1,param_2,piVar1);
    if (iVar2 == 0) {
      param_2 = (int *)param_2[2];
    }
    iVar2 = (**(code **)(*param_2 + 0x28))(param_2);
    if (((iVar2 != 0) || (iVar2 = (**(code **)(*param_2 + 0x34))(param_2), iVar2 != 0)) &&
       (iVar2 = FUN_000e7f38(param_2), iVar2 == 0)) {
      uVar3 = FUN_000e920c(param_2,0);
      uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar4 = (undefined4 *)FUN_00193e18(uVar5,0x130);
      *puVar4 = uVar5;
      puVar6 = puVar4 + 1;
      FUN_000ea020(puVar6,*(undefined4 *)(param_1 + 8));
      puVar4[0x2f] = param_2[0x2e];
      FUN_000ec3ac(param_1,param_2,puVar6);
      FUN_000e9adc(param_2,uVar3,puVar6);
    }
    iVar2 = (**(code **)(*param_2 + 0x24))(param_2);
    if (((iVar2 != 0) || (iVar2 = (**(code **)(*param_2 + 0x2c))(param_2), iVar2 != 0)) &&
       (iVar2 = FUN_000e7e90(param_2), iVar2 == 0)) {
      uVar3 = FUN_000e9184(param_2,0);
      uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar4 = (undefined4 *)FUN_00193e18(uVar5,0x130);
      *puVar4 = uVar5;
      puVar6 = puVar4 + 1;
      FUN_000ea020(puVar6,*(undefined4 *)(param_1 + 8));
      puVar4[0x2f] = param_2[0x2e];
      FUN_000ec370(param_1,param_2,puVar6);
      FUN_000e9adc(uVar3,param_2,puVar6);
    }
  } while (param_2 != param_3);
  return;
}

/* FUN_0012eacc @ 0x12eacc (1460 bytes) */
int FUN_0012eacc(param_1)
  int param_1;
{
  bool bVar1;
  undefined *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 *puVar17;
  undefined4 uVar18;
  undefined4 *puVar19;
  int iVar20;
  int iVar21;
  undefined4 uVar22;
  uint uVar23;
  bool bVar24;
  double dVar25;
  
  if (*(int *)(*(int *)(param_1 + 0x414) + 4) == 0) {
    return;
  }
  uVar22 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar4 = (undefined4 *)FUN_00193e18(uVar22,0x14);
  *puVar4 = uVar22;
  puVar4[1] = 2;
  puVar4[4] = uVar22;
  puVar4[2] = 0;
  uVar22 = FUN_00193e18(uVar22,8);
  puVar4[3] = uVar22;
  iVar20 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar20;
  uVar22 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
  iVar5 = FUN_001054ec(uVar22,0);
  *(int *)(iVar5 + 8) = iVar20;
  dVar25 = (double)FLOAT_001aa0d4;
  *(undefined4 *)(iVar5 + 0xc) = 0;
  FUN_000f79c4(dVar25,dVar25,dVar25,dVar25,uVar22,param_1,1);
  FUN_000f92fc(param_1,uVar22,*(undefined4 *)(param_1 + 0x3a0));
  iVar21 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar21;
  iVar5 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
  iVar20 = FUN_001054ec(iVar5,0);
  *(undefined4 *)(iVar20 + 0xc) = 0;
  *(int *)(iVar20 + 8) = iVar21;
  FUN_000f7870(iVar5,param_1,1,0xffffffff,0xffffffff,0xffffffff,0xffffffff);
  FUN_000f92fc(param_1,iVar5,*(undefined4 *)(param_1 + 0x3a0));
  do {
    iVar20 = *(int *)(param_1 + 0x414);
    uVar11 = *(uint *)(iVar20 + 4);
    if (uVar11 == 0) {
      ((int (*)())FUN_0012e8c0)(param_1,*(undefined4 *)(param_1 + 0x3a0),*(undefined4 *)(param_1 + 0x3a8));
      return;
    }
    piVar3 = (int *)0x0;
    if (uVar11 - 1 < uVar11) {
      piVar3 = (int *)((uVar11 - 1) * 4 + *(int *)(iVar20 + 8));
    }
    iVar21 = *piVar3;
    FUN_00194208(iVar20,uVar11 - 1);
    uVar18 = *(undefined4 *)(iVar21 + 0x158);
    iVar20 = FUN_0012b140(uVar18);
    uVar16 = *(undefined4 *)(iVar20 + 0x13c);
    bVar24 = *(int *)(*(int *)(iVar21 + 0x88) + 8) != 0xf8;
    if (bVar24) {
      do {
        iVar20 = FUN_0012b140(iVar20);
      } while (*(int *)(iVar20 + 0x150) == 0);
      uVar11 = puVar4[2];
      uVar23 = 0;
      if (uVar11 != 0) {
        do {
          if (uVar23 < (uint)puVar4[1]) {
            if (uVar11 <= uVar23) {
              _memset((void *)(uVar11 * 4 + puVar4[3]),0,(uVar23 - uVar11) * 4 + 4);
              puVar4[2] = uVar23 + 1;
            }
            piVar3 = (int *)(uVar23 * 4 + puVar4[3]);
          }
          else {
            piVar3 = (int *)FUN_0019423c(puVar4 + 1,uVar23);
          }
          if (*piVar3 == iVar20) {
            bVar1 = true;
            goto LAB_0012ed24;
          }
          uVar11 = puVar4[2];
          uVar23 = uVar23 + 1;
        } while (uVar23 < uVar11);
      }
      bVar1 = false;
LAB_0012ed24:
      iVar6 = *(int *)(iVar20 + 0x134);
      uVar14 = *(undefined4 *)(iVar20 + 0x13c);
      uVar13 = 0xffffffff;
      if (!bVar1) goto LAB_0012ed5c;
      iVar20 = FUN_000e83bc(uVar18);
      uVar15 = *(undefined4 *)(iVar20 + 0x94);
    }
    else {
      uVar13 = *(undefined4 *)(iVar21 + 300);
      uVar14 = 0;
      iVar6 = FUN_0012ac58(uVar13,uVar16);
LAB_0012ed5c:
      uVar15 = 0;
      if (iVar6 != 0) {
        uVar15 = FUN_0012b248(uVar22,iVar6,param_1);
      }
    }
    uVar7 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar20 = FUN_001054ec(uVar7,0);
    uVar12 = *(undefined4 *)(iVar5 + 0x8c);
    *(undefined4 *)(iVar20 + 0xc) = 0;
    *(undefined4 *)(iVar20 + 8) = uVar15;
    FUN_001046c8(uVar7,1,uVar12);
    FUN_000ed63c(param_1,uVar7);
    FUN_000e7738(uVar18,iVar21,uVar7);
    FUN_0019401c(iVar21);
    while( true ) {
      while( true ) {
        uVar16 = ((int (*)())FUN_0012e488)(param_1,uVar16);
        iVar20 = FUN_000e920c(uVar16,0);
        iVar21 = FUN_0012afe8(bVar24,uVar13,iVar20,uVar14);
        uVar16 = FUN_0012b140(iVar20);
        if (iVar20 != iVar21) break;
        ((int (*)())FUN_0012e56c)(uVar15,iVar20,*(undefined4 *)(param_1 + 8));
        uVar16 = FUN_0012ae1c(iVar20);
      }
      if (iVar21 == 0) break;
      uVar18 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar8 = (undefined4 *)FUN_00193e18(uVar18,0x168);
      *puVar8 = uVar18;
      puVar17 = puVar8 + 1;
      FUN_0010502c(puVar17,0x8c,*(undefined4 *)(param_1 + 8));
      puVar8[0x4c] = 6;
      iVar6 = FUN_001054ec(puVar17,1);
      puVar2 = PTR_DAT_001e8b8c;
      *(undefined4 *)(iVar6 + 0xc) = 0;
      uVar18 = *(undefined4 *)puVar2;
      *(undefined4 *)(iVar6 + 8) = uVar15;
      iVar6 = FUN_001054ec(puVar17,1);
      *(undefined4 *)(iVar6 + 0x10) = uVar18;
      uVar18 = FUN_000e9184(iVar21,0);
      puVar9 = (undefined4 *)FUN_000e9184(iVar20,0);
      uVar12 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      uVar7 = *(undefined4 *)(iVar20 + 0xb8);
      puVar10 = (undefined4 *)FUN_00193e18(uVar12,0x15c);
      *puVar10 = uVar12;
      puVar19 = puVar10 + 1;
      FUN_000ea6d0(puVar19,puVar17,uVar16,iVar20,*(undefined4 *)(param_1 + 8));
      iVar6 = FUN_000e7770(puVar9);
      puVar8 = puVar9;
      if (iVar6 == 0) {
        uVar16 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar8 = (undefined4 *)FUN_00193e18(uVar16,0x130);
        *puVar8 = uVar16;
        puVar8 = puVar8 + 1;
        FUN_000ea020(puVar8,*(undefined4 *)(param_1 + 8));
        FUN_000e977c(puVar9,iVar20,puVar8);
        FUN_000e9948(puVar19,iVar20,puVar8);
        FUN_000ec3ac(param_1,puVar9,puVar8);
      }
      FUN_000ec3ac(param_1,puVar8,puVar19);
      uVar16 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar9 = (undefined4 *)FUN_00193e18(uVar16,0x130);
      *puVar9 = uVar16;
      puVar9 = puVar9 + 1;
      FUN_000ea020(puVar9,*(undefined4 *)(param_1 + 8));
      puVar10[0x4f] = puVar9;
      FUN_000ec3ac(param_1,uVar18,puVar9);
      uVar16 = puVar10[0x50];
      FUN_000ec3ac(param_1,puVar9,uVar16);
      FUN_000e78c0(puVar19,uVar7);
      FUN_000e8e4c(puVar19,puVar9);
      FUN_000e977c(puVar8,iVar20,puVar19);
      FUN_000e8e4c(puVar9,uVar16);
      FUN_000e977c(uVar18,iVar21,uVar16);
      FUN_000e8e4c(uVar16,iVar21);
      FUN_000ed63c(param_1,puVar17);
      ((int (*)())FUN_0012e56c)(uVar15,iVar21,*(undefined4 *)(param_1 + 8));
      uVar16 = FUN_0012ae1c(iVar21);
    }
  } while( true );
}

/* FUN_0012f0f8 @ 0x12f0f8 (3440 bytes) */
int FUN_0012f0f8(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int *param_4;
  int *param_5;
  int *param_6;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  int *piVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *puVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  undefined4 uVar22;
  int *piVar23;
  uint *puVar24;
  int iStack0000001c;
  int local_68;
  int local_64;
  undefined4 local_60;
  
  iStack0000001c = param_2;
  iVar5 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),2);
  if ((((iVar5 != 0) && (iVar5 = FUN_000e9cc8(param_3), iVar5 != 0)) &&
      (*(int *)(param_3 + 0x138) < 1)) && (*(int *)(param_3 + 0x13c) == 0)) {
    iVar5 = FUN_000e8c7c(param_3);
    iVar6 = FUN_000e8c14(param_3);
    iVar7 = FUN_000e8bac(param_3);
    uVar22 = *(undefined4 *)(param_1 + 8);
    iVar8 = FUN_0012aa78(uVar22,iVar5,iVar6,iVar7,param_3);
    if (iVar8 == 0) {
      FUN_0012aae0(uVar22,iVar5);
      *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
      iVar9 = FUN_000e7e90(param_3);
      local_60 = *(undefined4 *)(param_3 + 8);
      iVar8 = *param_4;
      if (iVar5 == 0) {
        while (param_3 != iVar8) {
          iVar6 = *(int *)(iVar8 + 4);
          piVar23 = *(int **)(iVar8 + 0x98);
          for (piVar4 = (int *)(*(int **)(iVar8 + 0x98))[2]; piVar4 != (int *)0x0;
              piVar4 = (int *)piVar4[2]) {
            if ((piVar23[5] & 1U) != 0) {
              iVar7 = (**(code **)(*piVar23 + 0x34))(piVar23);
              if ((iVar7 == 0) && (iVar7 = (**(code **)(*piVar23 + 0x38))(piVar23), iVar7 == 0)) {
                iVar7 = 1;
                piVar4 = piVar23;
                while( true ) {
                  iVar21 = (**(code **)(*piVar23 + 0x14))(piVar23);
                  if (iVar21 < iVar7) break;
                  iVar7 = iVar7 + 1;
                  FUN_001234d8(piVar4[0x29],piVar23);
                  piVar4 = piVar4 + 6;
                }
                (**(code **)(*piVar23 + 0xc))(piVar23,0,*(undefined4 *)(param_1 + 8));
                piVar4 = (int *)piVar23[2];
              }
              else {
                piVar4 = (int *)piVar23[2];
              }
            }
            piVar23 = piVar4;
          }
          FUN_000e7658(iVar8);
          iVar8 = iVar6;
        }
        *param_4 = iVar9;
        local_60 = *(undefined4 *)(param_3 + 8);
      }
      else {
        if ((1 < iVar5) && (param_3 != iVar8)) {
          iVar19 = 0;
          iVar21 = param_3;
          do {
            iVar21 = *(int *)(iVar21 + 8);
            *(int *)(iVar21 + 0xc0) = iVar19;
            iVar19 = iVar19 + 1;
          } while (iVar8 != iVar21);
        }
        bVar2 = param_3 != iVar8;
        iVar19 = *(int *)(param_3 + 0x14c);
        iVar21 = param_3;
        bVar1 = bVar2;
        while (bVar1) {
          piVar23 = *(int **)(iVar21 + 8);
          piVar23[0x2e] = piVar23[0x2e] + -1;
          iVar10 = (**(code **)(*piVar23 + 0x2c))(piVar23);
          if ((iVar10 != 0) && (param_3 == piVar23[0x53])) {
            piVar23[0x53] = iVar19;
          }
          iVar21 = *(int *)(iVar21 + 8);
          bVar1 = iVar8 != iVar21;
        }
        uVar22 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
        puVar11 = (undefined4 *)FUN_00193e18(uVar22,0x14);
        puVar24 = puVar11 + 1;
        puVar11[1] = 2;
        *puVar11 = uVar22;
        puVar11[2] = 0;
        puVar11[4] = uVar22;
        uVar22 = FUN_00193e18(uVar22,8);
        puVar11[3] = uVar22;
        if (1 < iVar5) {
          local_68 = 1;
          iVar21 = iVar8;
          local_64 = iVar6;
          do {
            local_64 = local_64 + iVar7;
            if (bVar2) {
              iVar19 = param_3;
              uVar20 = 0;
              do {
                uVar17 = uVar20;
                piVar23 = *(int **)(iVar19 + 8);
                iVar10 = (**(code **)(*piVar23 + 8))(piVar23);
                if (uVar17 < *puVar24) {
                  uVar20 = puVar11[2];
                  if (uVar20 <= uVar17) {
                    _memset((void *)(uVar20 * 4 + puVar11[3]),0,(uVar17 - uVar20) * 4 + 4);
                    puVar11[2] = uVar17 + 1;
                  }
                  piVar4 = (int *)(uVar17 * 4 + puVar11[3]);
                }
                else {
                  piVar4 = (int *)FUN_0019423c(puVar24,uVar17);
                }
                *piVar4 = iVar10;
                piVar4 = (int *)piVar23[0x26];
                for (piVar12 = (int *)((int *)piVar23[0x26])[2]; piVar12 != (int *)0x0;
                    piVar12 = (int *)piVar12[2]) {
                  if ((piVar4[5] & 1U) != 0) {
                    iVar18 = (**(code **)(*piVar4 + 0x34))(piVar4);
                    if (iVar18 == 0) {
                      iVar18 = (**(code **)(*piVar4 + 0x38))(piVar4);
                      if (iVar18 != 0) break;
                      iVar18 = FUN_0010445c(piVar4,*(undefined4 *)(param_1 + 8),0);
                      if ((*(int *)(param_3 + 0x134) == 0) && (iVar3 = FUN_0012ab04(), iVar3 != 0))
                      {
                        FUN_0012c3d0(iVar18,local_64,param_1);
                      }
                      if ((*(uint *)(iVar18 + 0x14) & 0x10) != 0) {
                        FUN_000ee9ac(param_1,iVar18);
                      }
                      iVar3 = (**(code **)(*piVar23 + 0x24))(piVar23);
                      if ((iVar3 != 0) &&
                         (piVar12 = (int *)FUN_000e7804(piVar23), piVar4 == piVar12)) {
                        *(int *)(iVar10 + 0x130) = iVar18;
                      }
                      iVar3 = (**(code **)(*piVar23 + 0x2c))(piVar23);
                      if ((iVar3 != 0) && (piVar4 == (int *)piVar23[0x52])) {
                        *(int *)(iVar10 + 0x148) = iVar18;
                      }
                      FUN_000f92fc(param_1,iVar18,iVar10);
                      piVar12 = (int *)piVar4[2];
                    }
                    else {
                      piVar12 = (int *)piVar4[2];
                    }
                  }
                  piVar4 = piVar12;
                }
                FUN_000ec3ac(param_1,*param_4,iVar10);
                *param_4 = iVar10;
                iVar19 = *(int *)(iVar19 + 8);
                uVar20 = uVar17 + 1;
              } while (iVar8 != iVar19);
            }
            else {
              uVar17 = 0xffffffff;
            }
            iVar19 = *(int *)(param_3 + 8);
            if (0 < (int)uVar17) {
              uVar20 = 0;
              iVar10 = 1;
              do {
                if (uVar20 < *puVar24) {
                  uVar13 = puVar11[2];
                  if (uVar13 <= uVar20) {
                    _memset((void *)(uVar13 * 4 + puVar11[3]),0,(uVar20 - uVar13) * 4 + 4);
                    puVar11[2] = iVar10;
                  }
                }
                else {
                  FUN_0019423c(puVar24,uVar20);
                }
                iVar18 = 0;
                for (uVar13 = 1; uVar13 <= *(uint *)(*(int *)(iVar19 + 0xd0) + 4);
                    uVar13 = uVar13 + 1) {
                  iVar3 = *(int *)(iVar18 + *(int *)(*(int *)(iVar19 + 0xd0) + 8));
                  if (iVar3 != 0) {
                    uVar16 = *puVar24;
                    if (uVar20 < uVar16) {
                      uVar14 = puVar11[2];
                      if (uVar14 <= uVar20) {
                        _memset((void *)(uVar14 * 4 + puVar11[3]),0,(uVar20 - uVar14) * 4 + 4);
                        uVar16 = *puVar24;
                        puVar11[2] = iVar10;
                      }
                      puVar15 = (undefined4 *)(uVar20 * 4 + puVar11[3]);
                    }
                    else {
                      puVar15 = (undefined4 *)FUN_0019423c(puVar24,uVar20);
                      uVar16 = *puVar24;
                    }
                    uVar22 = *puVar15;
                    uVar14 = *(uint *)(iVar3 + 0xc0);
                    if (uVar14 < uVar16) {
                      uVar16 = puVar11[2];
                      if (uVar16 <= uVar14) {
                        _memset((void *)(uVar16 * 4 + puVar11[3]),0,(uVar14 - uVar16) * 4 + 4);
                        puVar11[2] = uVar14 + 1;
                      }
                      puVar15 = (undefined4 *)(uVar14 * 4 + puVar11[3]);
                    }
                    else {
                      puVar15 = (undefined4 *)FUN_0019423c(puVar24,uVar14);
                    }
                    FUN_000e8e4c(uVar22,*puVar15);
                  }
                  iVar18 = iVar18 + 4;
                }
                uVar20 = uVar20 + 1;
                iVar19 = *(int *)(iVar19 + 8);
                iVar10 = iVar10 + 1;
              } while (uVar17 != uVar20);
            }
            if (*puVar24 == 0) {
              puVar15 = (undefined4 *)FUN_0019423c(puVar24,0);
            }
            else {
              if (puVar11[2] == 0) {
                *(undefined4 *)puVar11[3] = 0;
                puVar11[2] = 1;
              }
              puVar15 = (undefined4 *)puVar11[3];
            }
            FUN_000e8e4c(iVar21,*puVar15);
            iVar21 = param_3;
            bVar1 = bVar2;
            while (bVar1) {
              iVar19 = *(int *)(iVar21 + 8);
              uVar20 = *(uint *)(iVar19 + 0xc0);
              if (uVar20 < *puVar24) {
                uVar17 = puVar11[2];
                if (uVar17 <= uVar20) {
                  _memset((void *)(uVar17 * 4 + puVar11[3]),0,(uVar20 - uVar17) * 4 + 4);
                  puVar11[2] = uVar20 + 1;
                }
                puVar15 = (undefined4 *)(uVar20 * 4 + puVar11[3]);
              }
              else {
                puVar15 = (undefined4 *)FUN_0019423c(puVar24,uVar20);
              }
              piVar23 = (int *)*puVar15;
              iVar10 = (**(code **)(*piVar23 + 0x24))(piVar23);
              if (iVar10 == 0) {
                iVar10 = (**(code **)(*piVar23 + 0x28))(piVar23);
                if (iVar10 == 0) {
                  iVar10 = (**(code **)(*piVar23 + 0x2c))(piVar23);
                  if (iVar10 == 0) {
                    iVar10 = (**(code **)(*piVar23 + 0x30))(piVar23);
                    if (((iVar10 != 0) ||
                        (iVar10 = (**(code **)(*piVar23 + 0x34))(piVar23), iVar10 != 0)) ||
                       (iVar10 = (**(code **)(*piVar23 + 0x38))(piVar23), iVar10 != 0))
                    goto LAB_0012fafc;
                    (**(code **)(*piVar23 + 0x3c))(piVar23);
                  }
                  else {
                    uVar20 = *(uint *)(*(int *)(iVar19 + 0x150) + 0xc0);
                    if (uVar20 < *puVar24) {
                      uVar17 = puVar11[2];
                      if (uVar17 <= uVar20) {
                        _memset((void *)(uVar17 * 4 + puVar11[3]),0,(uVar20 - uVar17) * 4 + 4);
                        puVar11[2] = uVar20 + 1;
                      }
                      piVar4 = (int *)(uVar20 * 4 + puVar11[3]);
                    }
                    else {
                      piVar4 = (int *)FUN_0019423c(puVar24,uVar20);
                    }
                    iVar19 = *(int *)(iVar19 + 0x154);
                    piVar23[0x54] = *piVar4;
                    uVar20 = *(uint *)(iVar19 + 0xc0);
                    if (uVar20 < *puVar24) {
                      uVar17 = puVar11[2];
                      if (uVar17 <= uVar20) {
                        _memset((void *)(uVar17 * 4 + puVar11[3]),0,(uVar20 - uVar17) * 4 + 4);
                        puVar11[2] = uVar20 + 1;
                      }
                      piVar4 = (int *)(uVar20 * 4 + puVar11[3]);
                    }
                    else {
                      piVar4 = (int *)FUN_0019423c(puVar24,uVar20);
                    }
                    piVar23[0x55] = *piVar4;
                  }
                }
                else {
LAB_0012fafc:
                  uVar20 = *(uint *)(*(int *)(iVar19 + 300) + 0xc0);
                  if (uVar20 < *puVar24) {
                    uVar17 = puVar11[2];
                    if (uVar17 <= uVar20) {
                      _memset((void *)(uVar17 * 4 + puVar11[3]),0,(uVar20 - uVar17) * 4 + 4);
                      puVar11[2] = uVar20 + 1;
                    }
                    piVar4 = (int *)(uVar20 * 4 + puVar11[3]);
                  }
                  else {
                    piVar4 = (int *)FUN_0019423c(puVar24,uVar20);
                  }
                  piVar23[0x4b] = *piVar4;
                }
              }
              else {
                uVar20 = *(uint *)(*(int *)(iVar19 + 0x13c) + 0xc0);
                if (uVar20 < *puVar24) {
                  uVar17 = puVar11[2];
                  if (uVar17 <= uVar20) {
                    _memset((void *)(uVar17 * 4 + puVar11[3]),0,(uVar20 - uVar17) * 4 + 4);
                    puVar11[2] = uVar20 + 1;
                  }
                  piVar4 = (int *)(uVar20 * 4 + puVar11[3]);
                }
                else {
                  piVar4 = (int *)FUN_0019423c(puVar24,uVar20);
                }
                iVar10 = *(int *)(iVar19 + 0x134);
                piVar23[0x4f] = *piVar4;
                uVar20 = *(uint *)(iVar10 + 0xc0);
                if (uVar20 < *puVar24) {
                  uVar17 = puVar11[2];
                  if (uVar17 <= uVar20) {
                    _memset((void *)(uVar17 * 4 + puVar11[3]),0,(uVar20 - uVar17) * 4 + 4);
                    puVar11[2] = uVar20 + 1;
                  }
                  piVar4 = (int *)(uVar20 * 4 + puVar11[3]);
                }
                else {
                  piVar4 = (int *)FUN_0019423c(puVar24,uVar20);
                }
                iVar19 = *(int *)(iVar19 + 0x138);
                piVar23[0x4d] = *piVar4;
                uVar20 = *(uint *)(iVar19 + 0xc0);
                if (uVar20 < *puVar24) {
                  uVar17 = puVar11[2];
                  if (uVar17 <= uVar20) {
                    _memset((void *)(uVar17 * 4 + puVar11[3]),0,(uVar20 - uVar17) * 4 + 4);
                    puVar11[2] = uVar20 + 1;
                  }
                  piVar4 = (int *)(uVar20 * 4 + puVar11[3]);
                }
                else {
                  piVar4 = (int *)FUN_0019423c(puVar24,uVar20);
                }
                piVar23[0x4e] = *piVar4;
              }
              iVar21 = *(int *)(iVar21 + 8);
              bVar1 = iVar8 != iVar21;
            }
            local_68 = local_68 + 1;
            iVar21 = *param_4;
          } while (iVar5 != local_68);
        }
        iVar7 = param_3;
        if (*(int *)(param_3 + 0x134) == 0) {
          while (bVar2) {
            iVar10 = *(int *)(iVar7 + 8);
            iVar21 = *(int *)(*(int *)(iVar10 + 0x98) + 8);
            iVar19 = *(int *)(iVar10 + 0x98);
            if (iVar21 != 0) {
              do {
                iVar10 = iVar21;
                if ((*(uint *)(iVar19 + 0x14) & 1) != 0) {
                  iVar21 = FUN_0012ab04(iVar19);
                  if (iVar21 == 0) {
                    iVar10 = *(int *)(iVar19 + 8);
                  }
                  else {
                    FUN_0012c3d0(iVar19,iVar6,param_1);
                    iVar10 = *(int *)(iVar19 + 8);
                  }
                }
                iVar21 = *(int *)(iVar10 + 8);
                iVar19 = iVar10;
              } while (*(int *)(iVar10 + 8) != 0);
              iVar10 = *(int *)(iVar7 + 8);
            }
            bVar2 = iVar8 != iVar10;
            iVar7 = iVar10;
          }
        }
      }
      FUN_00194208(iStack0000001c,*(int *)(iStack0000001c + 4) + -1);
      *param_6 = *param_6 + -1;
      piVar23 = *(int **)(param_3 + 0x98);
      piVar4 = (int *)(*(int **)(param_3 + 0x98))[2];
      do {
        if (piVar4 == (int *)0x0) {
          FUN_000e93ac(param_3,iVar9,local_60);
          if (iVar5 == 0) {
            FUN_000e79d0(iVar9);
          }
          else {
            FUN_000e79d0(iVar9);
            FUN_000e79dc(local_60);
          }
          if (*(int **)(param_3 + 0x150) != (int *)0x0) {
            (**(code **)(**(int **)(param_3 + 0x150) + 4))();
          }
          if (*(int **)(param_3 + 0x154) != (int *)0x0) {
            (**(code **)(**(int **)(param_3 + 0x154) + 4))();
          }
          FUN_000e7658(param_3);
          uVar22 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
          puVar11 = (undefined4 *)FUN_00193e18(uVar22,0x130);
          *puVar11 = uVar22;
          FUN_000ea020(puVar11 + 1,*(undefined4 *)(param_1 + 8));
          *param_5 = (int)(puVar11 + 1);
          puVar11[0x2f] = *param_6;
          FUN_000ec3ac(param_1,*param_4,*param_5);
          FUN_000e8e4c(*param_4,*param_5);
          ((int (*)())FUN_0012e8c0)(param_1,iVar9,*param_4);
          *param_4 = *param_5;
          return 1;
        }
        if ((piVar23[5] & 1U) != 0) {
          iVar6 = (**(code **)(*piVar23 + 0x3c))(piVar23);
          if (iVar6 == 0) {
            if (*(int *)(piVar23[0x22] + 4) == 3) {
              if (*(int *)(param_3 + 0x134) == 0) goto LAB_0012fc9c;
              FUN_001234d8(piVar23[0x29],piVar23);
              FUN_0019401c(piVar23);
              iVar6 = *(int *)(param_3 + 0x14c);
              FUN_001046c8(piVar23,1,*(undefined4 *)(*(int *)(iVar6 + 0x148) + 0x8c));
              FUN_000ed63c(param_1,piVar23);
              FUN_000e7688(iVar6,piVar23);
              piVar4 = (int *)piVar23[2];
            }
            else {
              piVar4 = (int *)piVar23[2];
            }
          }
          else {
LAB_0012fc9c:
            FUN_001234d8(piVar23[0x29],piVar23);
            (**(code **)(*piVar23 + 0xc))(piVar23,0,*(undefined4 *)(param_1 + 8));
            piVar4 = (int *)piVar23[2];
          }
        }
        piVar23 = piVar4;
        piVar4 = (int *)piVar4[2];
      } while( true );
    }
  }
  return 0;
}

/* FUN_0012fe8c @ 0x12fe8c (524 bytes) */
int FUN_0012fe8c(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  uint local_44;
  uint local_40;
  undefined4 *local_3c;
  undefined4 local_38;
  
  iVar2 = FUN_00194034(param_3 + 0x90);
  if (2 < iVar2) {
    return 0;
  }
  *(int *)(param_1 + 0x474) = *(int *)(param_1 + 0x474) + 1;
  local_38 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_40 = 0;
  local_44 = 2;
  local_3c = (undefined4 *)FUN_00193e18(local_38,8);
  do {
    iVar2 = (**(code **)(*param_2 + 0x24))(param_2);
    if (iVar2 == 0) {
      iVar2 = FUN_00194034(param_2 + 0x24);
      if (((2 < iVar2) || (iVar2 = (**(code **)(*param_2 + 0x38))(param_2), iVar2 != 0)) ||
         (iVar2 = (**(code **)(*param_2 + 0x3c))(param_2), iVar2 != 0)) goto LAB_00130080;
    }
    else {
      iVar2 = FUN_00194034(param_2 + 0x24);
      if (3 < iVar2) {
LAB_00130080:
        uVar6 = 0;
        goto LAB_0013008c;
      }
    }
    iVar2 = 0;
    for (uVar5 = 1; uVar5 <= *(uint *)(param_2[0x34] + 4); uVar5 = uVar5 + 1) {
      iVar1 = *(int *)(*(int *)(param_2[0x34] + 8) + iVar2);
      if (((iVar1 != 0) && (*(int *)(param_1 + 0x474) != *(int *)(iVar1 + 0x118))) &&
         (param_3 != iVar1)) {
        *(int *)(iVar1 + 0x118) = *(int *)(param_1 + 0x474);
        if (local_40 < local_44) {
          local_3c[local_40] = 0;
          piVar3 = local_3c + local_40;
          local_40 = local_40 + 1;
        }
        else {
          piVar3 = (int *)FUN_0019423c(&local_44);
        }
        *piVar3 = iVar1;
      }
      iVar2 = iVar2 + 4;
    }
    if (local_40 == 0) {
LAB_00130088:
      uVar6 = 1;
LAB_0013008c:
      FUN_00193cc0(local_38,local_3c);
      return uVar6;
    }
    puVar4 = local_3c;
    if (local_44 == 0) {
      puVar4 = (undefined4 *)FUN_0019423c(&local_44,0);
    }
    param_2 = (int *)*puVar4;
    if ((param_2 == (int *)0x0) || (iVar2 = FUN_00194374(&local_44,param_2), iVar2 == 0))
    goto LAB_00130088;
  } while( true );
}

/* FUN_001300b0 @ 0x1300b0 (836 bytes) */
int FUN_001300b0(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  
  while( true ) {
    piVar8 = (int *)(*(int **)(param_1 + 900))[2];
    if (piVar8 == (int *)0x0) break;
    bVar1 = false;
    piVar9 = *(int **)(param_1 + 900);
    do {
      piVar3 = piVar8;
      iVar2 = (**(code **)(*piVar9 + 0x24))(piVar9);
      if (iVar2 == 0) {
        iVar2 = FUN_000e7770(piVar9);
        if ((((iVar2 != 0) && (iVar2 = FUN_00194034(piVar9 + 0x24), iVar2 < 3)) &&
            (iVar2 = FUN_000e79dc(piVar9), iVar2 == 1)) &&
           (iVar2 = FUN_000e79d0(piVar9), iVar2 == 1)) {
          piVar4 = (int *)FUN_000e9184(piVar9,0);
          piVar8 = (int *)FUN_000e920c(piVar9,0);
          iVar2 = FUN_000e7770(piVar4);
          if (((iVar2 != 0) || (iVar2 = (**(code **)(*piVar4 + 0x1c))(piVar4), iVar2 != 0)) &&
             ((iVar2 = FUN_000e7770(piVar8), iVar2 != 0 ||
              (iVar2 = (**(code **)(*piVar8 + 0x20))(piVar8), iVar2 != 0)))) {
            FUN_000e9730(piVar9,piVar4,piVar8);
            goto LAB_0013037c;
          }
        }
      }
      else {
        iVar5 = piVar9[0x4f];
        iVar7 = piVar9[0x4d];
        iVar6 = piVar9[0x4e];
        iVar2 = ((int (*)())FUN_0012fe8c)(param_1,piVar9,iVar5);
        if (iVar2 == 0) {
          iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x21);
          if (((iVar2 != 0) && (iVar2 = FUN_000e79a0(iVar7), iVar2 == 0)) &&
             ((iVar2 = FUN_000e920c(iVar7,0), iVar2 == iVar5 &&
              ((iVar2 = FUN_00194034(iVar7 + 0x90), iVar2 < 3 &&
               (iVar2 = FUN_00194034(iVar6 + 0x90), 2 < iVar2)))))) {
            FUN_0012abd8(param_1,piVar9);
            piVar3 = (int *)piVar9[0x4d];
            bVar1 = true;
          }
        }
        else {
          piVar8 = (int *)FUN_000e7804(piVar9);
          if (piVar8 != (int *)0x0) {
            FUN_000ef970(param_1,piVar8);
            piVar8[5] = piVar8[5] & 0xffffffef;
            (**(code **)(*piVar8 + 0xc))
                      (piVar8,*(uint *)(param_1 + 0x30) >> 7 & 1,*(undefined4 *)(param_1 + 8));
            piVar9[0x4c] = 0;
          }
          piVar9[3] = piVar9[3] | 0x100;
          piVar3 = (int *)FUN_000e9184(piVar9,0);
          iVar2 = piVar9[0x3c];
          FUN_00194374(piVar3[0x34],piVar9);
          piVar8 = (int *)FUN_000e7f38(iVar5);
          FUN_00194374(piVar8[0x35],iVar5);
          FUN_000e8e4c(piVar3,piVar8);
          piVar8[0x3c] = iVar2;
          ((int (*)())FUN_0012dd58)(param_1,piVar9,iVar5);
          (**(code **)(*piVar3 + 0x48))(piVar3);
          (**(code **)(*piVar8 + 0x48))(piVar8);
          iVar2 = FUN_0012aef0(param_1,piVar3,piVar8);
          if (iVar2 == 0) {
LAB_0013037c:
            bVar1 = true;
            piVar3 = piVar8;
          }
          else {
            piVar3 = (int *)FUN_000e920c(piVar3,0);
            bVar1 = true;
          }
        }
      }
      piVar8 = (int *)piVar3[2];
      piVar9 = piVar3;
    } while ((int *)piVar3[2] != (int *)0x0);
    if (!bVar1) break;
    *(undefined4 *)(param_1 + 0x394) = 0;
    *(undefined4 *)(param_1 + 0x398) = 0;
    *(undefined4 *)(param_1 + 0x39c) = 0;
    iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x11);
    if (iVar2 != 0) {
      FUN_0013bd68(param_1,0);
    }
  }
  FUN_000ed7e4(param_1,"remove_empty_graphs");
  return;
}

/* FUN_001303f4 @ 0x1303f4 (48 bytes) */
int FUN_001303f4(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 4;
  do {
    if (*(int *)(iVar1 + param_2) == param_1) {
      return 1;
    }
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}

/* FUN_00130424 @ 0x130424 (32 bytes) */
int FUN_00130424(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x2c) + 0x3c4) + 1;
  *(int *)(*(int *)(param_1 + 0x2c) + 0x3c4) = iVar1;
  return iVar1 + *(int *)(param_1 + 8);
}

/* FUN_00130444 @ 0x130444 (52 bytes) */
int FUN_00130444(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = (param_2 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 0x42c);
  *(uint *)(iVar1 + 8) =
       (-2 << (param_2 & 0x1f) | 0xfffffffeU >> 0x20 - (param_2 & 0x1f)) & *(uint *)(iVar1 + 8);
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x8000;
  return;
}

/* FUN_00130478 @ 0x130478 (44 bytes) */
int FUN_00130478(param_1, param_2)
  int param_1;
  uint param_2;
{
  if ((*(uint *)((param_2 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 0x42c) + 8) >> (param_2 & 0x1f) &
      1) != 0) {
    return 1;
  }
  return 0;
}

/* FUN_001304a4 @ 0x1304a4 (200 bytes) */
int FUN_001304a4(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar3 = *(int *)(param_1 + 8);
  piVar4 = *(int **)(iVar3 + 0x30c);
  iVar1 = (**(code **)(*piVar4 + 0x138))(piVar4,iVar3);
  iVar2 = (**(code **)(*piVar4 + 0x140))(piVar4,iVar3);
  iVar3 = (**(code **)(*piVar4 + 0x13c))(piVar4,iVar3);
  iVar3 = iVar1 + iVar2 + iVar3;
  if (0 < iVar3) {
    iVar1 = 0;
    do {
      iVar2 = ((int (*)())FUN_00130478)(param_1,iVar1);
      if (iVar2 == 0) {
        iVar5 = iVar5 + 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar3 != iVar1);
  }
  return iVar5;
}

/* FUN_00130594 @ 0x130594 (136 bytes) */
int FUN_00130594(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = param_2 * 4 + param_1;
  iVar4 = -1;
  iVar1 = *(int *)(iVar3 + 0x448);
  iVar5 = *(int *)(iVar3 + 0x43c);
  iVar3 = iVar5;
  if (iVar5 < iVar1) {
    do {
      iVar2 = ((int (*)())FUN_00130478)(param_1,iVar3);
      if ((iVar2 == 0) && (iVar4 < iVar3)) {
        iVar4 = iVar3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar1 != iVar3);
    if (-1 < iVar4) {
      iVar4 = iVar4 - iVar5;
    }
  }
  return iVar4;
}

/* FUN_0013061c @ 0x13061c (116 bytes) */
int FUN_0013061c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_2 * 4 + param_1;
  iVar4 = 0;
  iVar1 = *(int *)(iVar3 + 0x448);
  iVar3 = *(int *)(iVar3 + 0x43c);
  if (iVar3 < iVar1) {
    do {
      iVar2 = ((int (*)())FUN_00130478)(param_1,iVar3);
      if (iVar2 == 0) {
        iVar4 = iVar4 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != iVar1);
  }
  return iVar4;
}

/* FUN_00130690 @ 0x130690 (152 bytes) */
int FUN_00130690(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = ((int (*)())FUN_0013061c)();
  if (param_2 == 1) {
    iVar1 = iVar1 + 0x20;
  }
  iVar2 = ((int (*)())FUN_00130478)(param_1,iVar1);
  if (iVar2 == 0) {
    FUN_000e1534(*(undefined4 *)(param_1 + 8),4);
  }
  ((int (*)())FUN_00130444)(param_1,iVar1);
  *(int *)(*(int *)(param_1 + 0x470) * 4 + *(int *)(param_1 + 0x458)) = iVar1;
  *(int *)(*(int *)(param_1 + 0x470) * 4 + *(int *)(param_1 + 0x45c)) = param_2;
  *(int *)(param_1 + 0x470) = *(int *)(param_1 + 0x470) + 1;
  return;
}

/* FUN_00130728 @ 0x130728 (164 bytes) */
int FUN_00130728(param_1)
  int *param_1;
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = (**(code **)(*param_1 + 0x34))();
  if (iVar3 == 0) {
    iVar3 = (**(code **)(*param_1 + 0x28))(param_1);
    piVar1 = param_1;
    if (iVar3 == 0) {
      do {
        param_1 = piVar1;
        piVar1 = (int *)param_1[1];
      } while ((((int *)param_1[1])[5] & 4U) != 0);
    }
    else {
      uVar2 = param_1[5];
      while ((uVar2 & 0x1000) == 0) {
        param_1 = (int *)param_1[1];
        uVar2 = param_1[5];
      }
    }
  }
  return param_1;
}

/* FUN_001307cc @ 0x1307cc (44 bytes) */
int FUN_001307cc()
{
  int iVar1;
  
  iVar1 = ((int (*)())FUN_00130728)();
  ((int (*)())FUN_00130728)(*(undefined4 *)(iVar1 + 4));
  return;
}

/* FUN_001307f8 @ 0x1307f8 (228 bytes) */
int FUN_001307f8(param_1)
  int *param_1;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = (**(code **)(*param_1 + 0x38))();
  if (iVar3 == 0) {
    iVar3 = (**(code **)(*param_1 + 0x28))(param_1);
    if (iVar3 == 0) {
      uVar4 = param_1[5];
      while ((uVar4 & 4) != 0) {
        param_1 = (int *)param_1[2];
        uVar4 = param_1[5];
      }
    }
    else {
      iVar3 = (**(code **)(*param_1 + 0x74))(param_1);
      if (iVar3 == 0) {
        uVar4 = (**(code **)(*param_1 + 0x78))(param_1);
        piVar2 = param_1;
        while (piVar1 = piVar2, uVar4 == 0) {
          piVar2 = (int *)piVar1[2];
          uVar4 = piVar2[5] & 0x1000;
          param_1 = piVar1;
        }
      }
    }
  }
  return param_1;
}

/* FUN_001308e0 @ 0x1308e0 (36 bytes) */
int FUN_001308e0()
{
  int iVar1;
  
  iVar1 = ((int (*)())FUN_001307f8)();
  return *(undefined4 *)(iVar1 + 8);
}

/* FUN_00130904 @ 0x130904 (64 bytes) */
int FUN_00130904(param_1)
  undefined4 param_1;
{
  int iVar1;
  
  iVar1 = ((int (*)())FUN_001307cc)();
  if ((*(uint *)(iVar1 + 0x14) & 0x4000000) != 0) {
    ((int (*)())FUN_001307cc)(param_1);
  }
  ((int (*)())FUN_001307f8)();
  return;
}

/* FUN_00130958 @ 0x130958 (36 bytes) */
int FUN_00130958(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = param_2 * 4 + param_3;
  return *(uint *)((uVar1 >> 3 & 0x1ffffffc) + param_1 + 8) >> (uVar1 & 0x1f) & 1;
}

/* FUN_0013097c @ 0x13097c (64 bytes) */
int FUN_0013097c(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_2 << 2;
  iVar2 = 4;
  do {
    if ((*(uint *)((uVar1 >> 3 & 0x1ffffffc) + param_1 + 8) >> (uVar1 & 0x1f) & 1) != 0) {
      return 1;
    }
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}

/* FUN_001309bc @ 0x1309bc (32 bytes) */
int FUN_001309bc(param_1, param_2)
  int param_1;
  uint param_2;
{
  return *(uint *)((param_2 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 0x24) + 8) >> (param_2 & 0x1f) &
         1;
}

/* FUN_001309dc @ 0x1309dc (44 bytes) */
int FUN_001309dc(param_1, param_2)
  int param_1;
  uint param_2;
{
  if ((*(uint *)((param_2 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 0x430) + 8) >> (param_2 & 0x1f) &
      1) != 0) {
    return 1;
  }
  return 0;
}

/* FUN_00130a08 @ 0x130a08 (112 bytes) */
int FUN_00130a08(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  
  iVar1 = ((int (*)())FUN_00130728)();
  piVar2 = *(int **)(iVar1 + 4);
  while( true ) {
    iVar1 = (**(code **)(*piVar2 + 0x74))(piVar2);
    if (iVar1 == 0) {
      return (int *)0x0;
    }
    if (*(int *)(piVar2[0x30] + 0x13c) == param_2) break;
    piVar2 = (int *)piVar2[1];
  }
  return piVar2;
}

/* FUN_00130a78 @ 0x130a78 (68 bytes) */
int FUN_00130a78(param_1, param_2)
  uint param_1;
  int param_2;
{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = param_1;
  while( true ) {
    if (uVar2 == 0) {
      return 0;
    }
    puVar1 = (uint *)(param_1 + 0x14);
    if (((*puVar1 & 1) != 0) && (*(int *)(param_1 + 0x14c) == *(int *)(param_2 + 0x14c))) break;
    param_1 = *(uint *)(param_1 + 8);
    uVar2 = *puVar1 & 4;
    if (param_1 == 0) {
      return 0;
    }
  }
  return param_1;
}

/* FUN_00130abc @ 0x130abc (280 bytes) */
int FUN_00130abc(param_1)
  undefined4 param_1;
{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  
  piVar2 = (int *)((int (*)())FUN_001307cc)();
  piVar3 = (int *)((int (*)())FUN_00130728)(param_1);
  iVar4 = (**(code **)(*piVar2 + 0x24))(piVar2);
  if (((iVar4 != 0) && ((piVar2[5] & 0x4000000U) == 0)) &&
     (piVar7 = piVar3, piVar8 = piVar3, (piVar3[5] & 0x1000U) == 0)) {
    do {
      if (piVar8 == (int *)0x0) {
        return;
      }
      uVar1 = piVar7[5];
      if ((uVar1 & 1) != 0) {
        piVar8 = piVar7 + 0x29;
        for (iVar4 = 1; iVar6 = (**(code **)(*piVar7 + 0x14))(piVar7), iVar4 <= iVar6;
            iVar4 = iVar4 + 1) {
          uVar5 = FUN_00105594(piVar7,iVar4);
          iVar6 = ((int (*)())FUN_00130a78)(piVar2,uVar5);
          if (iVar6 != 0) {
            piVar3[5] = piVar3[5] | 0x10000000;
            FUN_00103d50(piVar8,4,1);
          }
          piVar8 = piVar8 + 6;
        }
        uVar1 = piVar7[5];
      }
      piVar7 = (int *)piVar7[2];
      piVar8 = (int *)(uVar1 & 4);
    } while (piVar7 != (int *)0x0);
  }
  return;
}

/* FUN_00130bd4 @ 0x130bd4 (40 bytes) */
int FUN_00130bd4(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = (param_2 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 0x430);
  *(uint *)(iVar1 + 8) =
       (-2 << (param_2 & 0x1f) | 0xfffffffeU >> 0x20 - (param_2 & 0x1f)) & *(uint *)(iVar1 + 8);
  return;
}

/* FUN_00130bfc @ 0x130bfc (144 bytes) */
int FUN_00130bfc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0x14);
  if (*(int *)(param_2 + 0x98) != 0) {
    if (*(int *)(param_2 + 0x98) == 1) {
      return 1;
    }
    return -1;
  }
  if ((*(uint *)(param_2 + 0x14) & 0x40) == 0) {
    return 0;
  }
  if (0 < iVar1) {
    iVar2 = 0;
    do {
      if ((*(int *)(param_1 + 0x43c) <= *(int *)(param_2 + 0x94)) &&
         (*(int *)(param_2 + 0x94) < *(int *)(param_1 + 0x448))) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      param_1 = param_1 + 4;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return -1;
}

/* FUN_00130c8c @ 0x130c8c (276 bytes) */
int FUN_00130c8c(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int *param_4;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = ((int (*)())FUN_00130728)(param_2);
  iVar6 = *(int *)(*(int *)(param_1 + 0x2c) + 0x6c4);
  iVar3 = FUN_001043f0(0x31,*(int *)(param_1 + 0x2c));
  uVar1 = *(undefined4 *)(param_3 + 0x98);
  *(int *)(iVar3 + 0x94) = *param_4;
  *(undefined4 *)(iVar3 + 0x98) = uVar1;
  FUN_00106004(iVar3,1,param_3,0,*(undefined4 *)(param_1 + 0x2c));
  uVar1 = *(undefined4 *)(iVar2 + 4);
  *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xffffffbf | 0x80000000;
  piVar4 = *(int **)(*(int *)(param_1 + 0x2c) + 0x30c);
  iVar5 = (**(code **)(*piVar4 + 0x150))(piVar4,uVar1);
  if (iVar5 != 0) {
    *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) | 0x1000;
  }
  FUN_000e7700(*(undefined4 *)(iVar2 + 0x158),iVar2,iVar3);
  *(undefined4 *)(*param_4 * 4 + *(int *)(iVar6 + 0x45c)) = 0;
  *(undefined4 *)(*param_4 * 4 + *(int *)(iVar6 + 0x458)) = 0xffffffff;
  **(int **)(param_1 + 0x18) = **(int **)(param_1 + 0x18) + 1;
  *param_4 = *param_4 + 1;
  return iVar3;
}

/* FUN_00130da0 @ 0x130da0 (200 bytes) */
int FUN_00130da0(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_00105594(param_2,param_3);
  iVar2 = FUN_0010445c(uVar1,param_5,0);
  if ((*(uint *)(param_2 + 0x14) & 0x40) == 0) {
    uVar1 = ((int (*)())FUN_00130424)(param_1);
    *(undefined4 *)(iVar2 + 0x98) = 0;
    *(undefined4 *)(iVar2 + 0x94) = uVar1;
  }
  FUN_000e7738(*(undefined4 *)(param_4 + 0x158),param_4,iVar2);
  *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 0x8000000;
  FUN_00106004(param_2,param_3,iVar2,0,param_5);
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) | 1;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) & 0xffffeffb | 0x8000000;
  return iVar2;
}

/* FUN_00130e68 @ 0x130e68 (88 bytes) */
int FUN_00130e68(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x28))();
  if ((iVar1 != 0) || (uVar2 = 0, *(int *)(param_1[0x22] + 8) == 0x93)) {
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_00130ec0 @ 0x130ec0 (132 bytes) */
int FUN_00130ec0(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar2 = *(undefined4 *)(param_3 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  puVar3 = puVar1 + 1;
  *puVar1 = uVar2;
  FUN_00109a80(puVar3,0xfa,param_3);
  puVar1[0x4d] = param_1;
  puVar1[0x27] = 0x3b;
  puVar1[0x4e] = param_2;
  puVar1[0x26] = param_1;
  FUN_000e7688(*(undefined4 *)(*(int *)(param_3 + 0x6c4) + 0x3a0),puVar3);
  return puVar3;
}

/* FUN_00130f64 @ 0x130f64 (132 bytes) */
int FUN_00130f64(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar2 = *(undefined4 *)(param_3 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  puVar3 = puVar1 + 1;
  *puVar1 = uVar2;
  FUN_00109a80(puVar3,0x79,param_3);
  puVar1[0x4d] = param_1;
  puVar1[0x27] = 0x3c;
  puVar1[0x50] = param_2;
  puVar1[0x26] = param_2;
  FUN_000e76c4(*(undefined4 *)(*(int *)(param_3 + 0x6c4) + 0x3a0),puVar3);
  return puVar3;
}

/* FUN_00131008 @ 0x131008 (452 bytes) */
int FUN_00131008(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  undefined4 param_3;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 local_48;
  undefined1 auStack_44 [12];
  undefined4 local_38 [5];
  
  iVar2 = FUN_001054ec(param_2,param_3);
  FUN_000f3398(local_38,*(undefined4 *)(iVar2 + 0x10));
  local_48 = local_38[0];
  uVar3 = FUN_00105594(param_2,param_3);
  iVar2 = 0;
  do {
    if ((auStack_44[iVar2 + -4] != '\0') &&
       (uVar4 = FUN_001382b8(uVar3,iVar2,auStack_44), -1 < param_1)) {
      iVar7 = 0;
      piVar5 = param_2;
      do {
        do {
          do {
            piVar5 = (int *)((int (*)())FUN_001307cc)(piVar5);
          } while ((piVar5[5] & 0x4000000U) != 0);
          iVar6 = (**(code **)(*piVar5 + 0x34))();
        } while ((((iVar6 != 0) || (iVar6 = (**(code **)(*piVar5 + 0x68))(piVar5), iVar6 != 0)) ||
                 (*(int *)(piVar5[0x22] + 8) == 0x8e)) ||
                ((iVar6 = (**(code **)(*piVar5 + 0x74))(piVar5), iVar6 != 0 ||
                 (iVar6 = (**(code **)(*piVar5 + 0x78))(piVar5), iVar6 != 0))));
        iVar7 = iVar7 + 1;
        iVar6 = (**(code **)(*(int *)param_2[0x56] + 0x24))();
        if ((iVar6 == 0) &&
           ((iVar6 = (**(code **)(*(int *)param_2[0x56] + 0x2c))(), iVar6 == 0 &&
            (piVar5[0x56] != param_2[0x56])))) {
          return 1;
        }
        iVar6 = ((int (*)())FUN_00130a78)(piVar5,uVar4);
        if (iVar6 != 0) {
          return 0;
        }
      } while (iVar7 <= param_1);
    }
    bVar1 = iVar2 == 3;
    iVar2 = iVar2 + 1;
    if (bVar1) {
      return 1;
    }
  } while( true );
}

/* FUN_001311cc @ 0x1311cc (264 bytes) */
int FUN_001311cc(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  uVar3 = *(undefined4 *)(param_6 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar3,0x168);
  puVar4 = puVar1 + 1;
  *puVar1 = uVar3;
  FUN_00107980(puVar4,0xfb,param_6);
  uVar3 = DAT_001affe4;
  puVar1[0x27] = 0;
  puVar1[0x28] = uVar3;
  puVar1[0x26] = param_1;
  FUN_00106004(puVar4,1,param_3,0,param_6);
  uVar3 = DAT_001affe0;
  iVar2 = FUN_001054ec(puVar4,1);
  *(undefined4 *)(iVar2 + 0x10) = uVar3;
  FUN_00106004(puVar4,2,param_4,0,param_6);
  uVar3 = DAT_001affdc;
  iVar2 = FUN_001054ec(puVar4,2);
  *(undefined4 *)(iVar2 + 0x10) = uVar3;
  FUN_000e7738(*(undefined4 *)(param_5 + 0x158),param_5,puVar4);
  puVar1[6] = puVar1[6] | 0x8001000;
  return puVar4;
}

/* FUN_001312f4 @ 0x1312f4 (420 bytes) */
int FUN_001312f4(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 local_48 [4];
  undefined4 local_38;
  undefined4 local_34 [3];
  
  iVar2 = FUN_001054ec(param_1,0);
  local_48[0] = *(undefined4 *)(iVar2 + 0x10);
  if (((*(uint *)(param_1 + 0x14) & 0x200) != 0) &&
     (iVar2 = FUN_00105594(param_1,*(undefined4 *)(param_1 + 0x84)), iVar2 != 0)) {
    iVar5 = 0;
    do {
      iVar3 = FUN_001054ec(param_1,0);
      if ((*(char *)(iVar5 + iVar3 + 0x10) == '\x01') &&
         (iVar3 = FUN_00138240(iVar2,iVar5), iVar3 != 0)) {
        *(undefined1 *)((int)local_48 + iVar5) = 0;
      }
      bVar1 = iVar5 != 3;
      iVar5 = iVar5 + 1;
    } while (bVar1);
  }
  FUN_000f370c(&local_38,local_48[0]);
  uVar6 = *(undefined4 *)(param_5 + 0x374);
  puVar4 = (undefined4 *)FUN_00193e18(uVar6,0x168);
  puVar7 = puVar4 + 1;
  *puVar4 = uVar6;
  FUN_001071fc(puVar7,0xfc,param_5);
  uVar6 = *(undefined4 *)(param_2 + 0x94);
  puVar4[0x27] = 0x3b;
  puVar4[0x26] = uVar6;
  FUN_000f36b8(local_34,local_38);
  puVar4[0x28] = local_34[0];
  FUN_00106004(puVar7,1,param_1,0,param_5);
  iVar2 = FUN_001054ec(puVar7,1);
  *(undefined4 *)(iVar2 + 0x10) = local_38;
  FUN_00106004(puVar7,2,param_3,0,param_5);
  uVar6 = DAT_001affdc;
  iVar2 = FUN_001054ec(puVar7,2);
  *(undefined4 *)(iVar2 + 0x10) = uVar6;
  FUN_00106004(puVar7,3,param_2,0,param_5);
  uVar6 = *(undefined4 *)(param_4 + 0x158);
  puVar4[6] = puVar4[6] | 0x1000;
  FUN_000e7738(uVar6,param_4,puVar7);
  return;
}

/* FUN_001314b8 @ 0x1314b8 (320 bytes) */
int FUN_001314b8(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  *(int *)(param_1 + 0x468) = *(int *)(*(int *)(param_1 + 8) + 0x3c4) + 1;
  iVar1 = ((int (*)())FUN_001304a4)();
  iVar4 = *(int *)(param_1 + 8);
  *(int *)(param_1 + 0x46c) = iVar1;
  *(int *)(param_1 + 0x464) = iVar1 + *(int *)(param_1 + 0x468);
  piVar5 = *(int **)(iVar4 + 0x30c);
  iVar1 = (**(code **)(*piVar5 + 0x138))(piVar5,iVar4);
  iVar2 = (**(code **)(*piVar5 + 0x140))(piVar5,iVar4);
  iVar4 = (**(code **)(*piVar5 + 0x13c))(piVar5,iVar4);
  iVar4 = iVar1 + iVar2 + iVar4;
  iVar1 = *(int *)(param_1 + 0x464);
  if (*(int *)(param_1 + 0x464) <= iVar4) {
    iVar1 = iVar4;
  }
  if (iVar1 < 0x1000) {
    iVar1 = 0x1000;
  }
  iVar2 = iVar1 << 2;
  uVar3 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),iVar2);
  *(undefined4 *)(param_1 + 0x458) = uVar3;
  uVar3 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),iVar2);
  *(undefined4 *)(param_1 + 0x45c) = uVar3;
  uVar3 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),iVar2);
  *(undefined4 *)(param_1 + 0x460) = uVar3;
  if (0 < iVar1) {
    iVar2 = 0;
    do {
      iVar4 = iVar2 * 4;
      iVar2 = iVar2 + 1;
      *(undefined4 *)(iVar4 + *(int *)(param_1 + 0x460)) = 0xffffffff;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

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
  FUN_00137474(param_1);
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
          uVar7 = FUN_00134bf0(param_1,iVar14,1);
          FUN_00135334(param_1,iVar12,uVar7);
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
    puVar2 = (undefined4 *)FUN_0019423c(puVar5);
  }
  iVar3 = FUN_00134ab0(*puVar2);
  if (iVar3 == 0) {
    iVar4 = *(int *)(param_3 + 0x138);
    iVar3 = ((int (*)())FUN_00130f64)(*(undefined4 *)(param_3 + 0x130),iVar4,*(undefined4 *)(param_1 + 0x2c));
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

/* FUN_00131a80 @ 0x131a80 (368 bytes) */
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
    uVar2 = ((int (*)())FUN_00131a80)();
    uVar3 = ((int (*)())FUN_001319d0)(param_1,uVar2);
    iVar1 = ((int (*)())FUN_00130ec0)(uVar2,uVar3,*(undefined4 *)(param_1 + 8));
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
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  
  iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0x14) << 2;
  iVar3 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x378),iVar4);
  iVar4 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x378),iVar4);
  uVar5 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x378),
                       *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0x14) << 2);
  piVar6 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
  (**(code **)(*piVar6 + 0x134))(piVar6,uVar5);
  iVar11 = *(int *)(param_1 + 8);
  if (0 < *(int *)(*(int *)(iVar11 + 0x30c) + 0x14)) {
    iVar12 = 0;
    iVar13 = 0;
    do {
      uVar5 = *(undefined4 *)(iVar11 + 0x378);
      puVar7 = (undefined4 *)FUN_00193e18(uVar5,0x20c);
      iVar11 = 0x80;
      *puVar7 = uVar5;
      puVar7[1] = 0x80;
      puVar7[2] = 0x1000;
      puVar8 = puVar7 + 1;
      do {
        puVar8[2] = 0;
        puVar8 = puVar8 + 1;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      *(undefined4 **)(iVar3 + iVar13) = puVar7 + 1;
      uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
      puVar7 = (undefined4 *)FUN_00193e18(uVar5,0x20c);
      iVar11 = 0x80;
      *puVar7 = uVar5;
      puVar7[1] = 0x80;
      puVar7[2] = 0x1000;
      puVar8 = puVar7 + 1;
      do {
        puVar8[2] = 0;
        puVar8 = puVar8 + 1;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      *(undefined4 **)(iVar4 + iVar13) = puVar7 + 1;
      iVar12 = iVar12 + 1;
      iVar11 = *(int *)(param_1 + 8);
      iVar13 = iVar13 + 4;
    } while (iVar12 < *(int *)(*(int *)(iVar11 + 0x30c) + 0x14));
  }
  iVar12 = *(int *)(*(int *)(param_1 + 900) + 8);
  iVar13 = *(int *)(param_1 + 900);
  if (iVar12 != 0) {
    do {
      iVar11 = iVar12;
      piVar14 = *(int **)(iVar13 + 0x98);
      piVar6 = (int *)piVar14[2];
      if ((int *)piVar14[2] != (int *)0x0) {
        do {
          piVar1 = piVar6;
          if (((piVar14[5] & 1U) != 0) && (piVar14[0x20] != 0)) {
            iVar11 = FUN_00126760(piVar14[0x26]);
            if ((iVar11 == 0) ||
               (((piVar14[5] & 2U) != 0 ||
                (iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0)))) {
LAB_00131f98:
              piVar1 = (int *)piVar14[2];
            }
            else {
              iVar11 = ((int (*)())FUN_00130bfc)(param_1,piVar14);
              uVar10 = piVar14[0x25];
              if ((piVar14[5] & 0x40U) == 0) {
                iVar11 = iVar11 * 4;
                uVar9 = uVar10 >> 3 & 0x1ffffffc;
                if ((*(uint *)(uVar9 + *(int *)(iVar4 + iVar11) + 8) >> (uVar10 & 0x1f) & 1) != 0)
                goto LAB_00131f98;
                iVar12 = *(int *)(*(int *)(param_1 + 0x3c0) + 0x18);
                *(int *)(iVar11 + iVar12) = *(int *)(iVar11 + iVar12) + 1;
                iVar11 = *(int *)(iVar4 + iVar11);
              }
              else {
                iVar11 = iVar11 * 4;
                uVar9 = uVar10 >> 3 & 0x1ffffffc;
                if ((*(uint *)(uVar9 + *(int *)(iVar3 + iVar11) + 8) >> (uVar10 & 0x1f) & 1) != 0)
                goto LAB_00131f98;
                iVar12 = *(int *)(*(int *)(param_1 + 0x3c0) + 0x14);
                *(int *)(iVar11 + iVar12) = *(int *)(iVar11 + iVar12) + 1;
                iVar11 = *(int *)(iVar3 + iVar11);
              }
              *(uint *)(uVar9 + iVar11 + 8) = 1 << (uVar10 & 0x1f) | *(uint *)(uVar9 + iVar11 + 8);
              piVar1 = (int *)piVar14[2];
            }
          }
          piVar6 = (int *)piVar1[2];
          piVar14 = piVar1;
        } while ((int *)piVar1[2] != (int *)0x0);
        iVar11 = *(int *)(iVar13 + 8);
      }
      iVar12 = *(int *)(iVar11 + 8);
      iVar13 = iVar11;
    } while (*(int *)(iVar11 + 8) != 0);
    iVar11 = *(int *)(param_1 + 8);
  }
  iVar13 = *(int *)(*(int *)(iVar11 + 0x30c) + 0x14);
  iVar12 = iVar13 + -1;
  if (-1 < iVar12) {
    iVar12 = iVar12 * 4;
    iVar11 = 0;
    piVar14 = (int *)(iVar3 + iVar12);
    piVar6 = (int *)(iVar4 + iVar12);
    do {
      iVar12 = *piVar6;
      if (iVar12 != 0) {
        FUN_00193cc0(*(undefined4 *)(iVar12 + -4),iVar12 + -4);
      }
      iVar12 = *piVar14;
      if (iVar12 != 0) {
        FUN_00193cc0(*(undefined4 *)(iVar12 + -4),iVar12 + -4);
      }
      iVar11 = iVar11 + 1;
      piVar6 = piVar6 + -1;
      piVar14 = piVar14 + -1;
    } while (iVar13 != iVar11);
    iVar11 = *(int *)(param_1 + 8);
  }
  FUN_00193cc0(*(undefined4 *)(iVar11 + 0x378),iVar4);
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x378),iVar3);
  iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0x14) << 2;
  piVar6 = (int *)FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x378),iVar4);
  *piVar6 = 0;
  iVar3 = *(int *)(param_1 + 8);
  if (1 < *(int *)(*(int *)(iVar3 + 0x30c) + 0x14)) {
    iVar11 = 1;
    piVar14 = piVar6;
    do {
      iVar3 = iVar11 * 4;
      iVar12 = *piVar14;
      iVar11 = iVar11 + 1;
      piVar14 = piVar14 + 1;
      *piVar14 = iVar12 + *(int *)(iVar3 + *(int *)(*(int *)(param_1 + 0x3c0) + 0x14) + -4);
      iVar3 = *(int *)(param_1 + 8);
    } while (iVar11 < *(int *)(*(int *)(iVar3 + 0x30c) + 0x14));
  }
  puVar8 = (undefined4 *)FUN_00193e18(*(undefined4 *)(iVar3 + 0x378),iVar4);
  iVar4 = *(int *)(param_1 + 8);
  if (0 < *(int *)(*(int *)(iVar4 + 0x30c) + 0x14)) {
    iVar3 = 0;
    puVar7 = puVar8;
    do {
      *puVar7 = 0;
      iVar3 = iVar3 + 1;
      iVar4 = *(int *)(param_1 + 8);
      puVar7 = puVar7 + 1;
    } while (iVar3 < *(int *)(*(int *)(iVar4 + 0x30c) + 0x14));
  }
  iVar3 = *(int *)(*(int *)(param_1 + 900) + 8);
  iVar11 = *(int *)(param_1 + 900);
  if (iVar3 != 0) {
    do {
      iVar4 = iVar3;
      piVar14 = (int *)(*(int **)(iVar11 + 0x98))[2];
      piVar1 = *(int **)(iVar11 + 0x98);
      if (piVar14 != (int *)0x0) {
        do {
          piVar2 = piVar14;
          if (((piVar1[5] & 1U) != 0) && (piVar1[0x20] != 0)) {
            iVar4 = FUN_00126760(piVar1[0x26]);
            if ((iVar4 == 0) ||
               (((piVar1[5] & 2U) != 0 ||
                (iVar4 = (**(code **)(*piVar1 + 0x50))(piVar1), iVar4 != 0)))) {
              piVar2 = (int *)piVar1[2];
            }
            else {
              iVar4 = ((int (*)())FUN_00130bfc)(param_1,piVar1);
              if ((piVar1[5] & 0x40U) == 0) {
                if (param_5 == 0) {
                  iVar3 = param_3 + piVar1[0x25];
                }
                else {
                  iVar3 = piVar1[0x25];
                }
                iVar12 = iVar3 * 4;
                *(undefined4 *)(*(int *)(param_1 + 0x458) + iVar12) = 0xffffffff;
              }
              else {
                iVar13 = piVar1[0x25];
                iVar12 = *(int *)(param_1 + 0x460);
                iVar3 = iVar13 * 4;
                if (*(int *)(iVar3 + iVar12) == -1) {
                  *(undefined4 *)(iVar3 + iVar12) = puVar8[iVar4];
                  puVar8[iVar4] = puVar8[iVar4] + 1;
                  iVar12 = *(int *)(param_1 + 0x460);
                }
                iVar3 = *(int *)(iVar3 + iVar12) + piVar6[iVar4];
                iVar12 = iVar3 * 4;
                *(int *)(*(int *)(param_1 + 0x458) + iVar12) = iVar13;
              }
              iVar13 = FUN_001054ec(piVar1,0);
              *(int *)(iVar13 + 8) = iVar3;
              *(int *)(*(int *)(param_1 + 0x45c) + iVar12) = iVar4;
              piVar2 = (int *)piVar1[2];
            }
          }
          piVar14 = (int *)piVar2[2];
          piVar1 = piVar2;
        } while ((int *)piVar2[2] != (int *)0x0);
        iVar4 = *(int *)(iVar11 + 8);
      }
      iVar3 = *(int *)(iVar4 + 8);
      iVar11 = iVar4;
    } while (*(int *)(iVar4 + 8) != 0);
    iVar4 = *(int *)(param_1 + 8);
  }
  *(undefined4 *)(param_1 + 0x34) = 4;
  FUN_00193cc0(*(undefined4 *)(iVar4 + 0x378),piVar6);
  FUN_000e0e0c(*(undefined4 *)(param_1 + 8),
               "Register allocation : Repartition -> %d physical + %d virtual = %d regs\n",param_3,
               param_2,param_4);
  return;
}

/* FUN_001322a8 @ 0x1322a8 (3608 bytes) */
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
          FUN_00135334(param_2,iVar17,iVar24);
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
          iVar17 = FUN_00134bf0(param_2,iVar24,1);
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
                  if (iVar17 != 0) goto LAB_00132adc;
                  local_58 = DAT_001affec;
                  local_54 = DAT_001afff0;
                  local_50 = DAT_001afff4;
                  local_4c = DAT_001afff8;
                  uVar22 = FUN_00134bf0(param_2,piVar11[0x25],param_5);
                  iVar17 = (**(code **)(*piVar11 + 100))(piVar11);
                  if (iVar17 != 0) {
                    for (iVar17 = 1; iVar24 = (**(code **)(*piVar11 + 0x14))(piVar11),
                        iVar17 <= iVar24; iVar17 = iVar17 + 1) {
                      if ((((piVar11[iVar17 * 6 + 0x28] & 1U) != 0) ||
                          ((piVar11[iVar17 * 6 + 0x28] & 2U) != 0)) ||
                         (iVar24 = FUN_000f31e8(piVar11,iVar17), iVar24 == 0)) goto LAB_001327f0;
                    }
                    if ((piVar11[0x48] == 0) && (piVar11[0x49] == 0)) {
                      if ((piVar11[0x20] != 0) &&
                         (((iVar17 = FUN_00126760(piVar11[0x26]), iVar17 != 0 &&
                           ((piVar11[5] & 2U) == 0)) &&
                          (iVar17 = (**(code **)(*piVar11 + 0x50))(piVar11), iVar17 == 0)))) {
                        iVar17 = 4;
                        piVar13 = piVar11;
                        do {
                          if (*(byte *)(piVar13 + 0x27) - 2 < 2) goto LAB_001327f0;
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
                        local_58 = FUN_00134bf0(param_2,piVar13[0x25],param_5);
                      }
                    }
                  }
LAB_001327f0:
                  iVar17 = ((int (*)())FUN_0013097c)(piVar15,uVar22);
                  if (iVar17 == 0) {
                    if ((*(uint *)((uVar22 >> 3 & 0x1ffffffc) + puVar7[5] + 8) >> (uVar22 & 0x1f) &
                        1) != 0) goto LAB_00132adc;
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
LAB_00132828:
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
                             (iVar20 = ((int (*)())FUN_00130958)(piVar15,iVar17,iVar24), iVar20 != 0)) {
                            iVar20 = FUN_00134bf0(param_2,iVar17,param_5);
                            iVar23 = ((int (*)())FUN_001303f4)(iVar20,&local_58);
                            if (iVar23 == 0) goto LAB_00132970;
                          }
                          bVar2 = iVar24 != 3;
                          iVar24 = iVar24 + 1;
                        } while (bVar2);
                      }
                      else {
                        iVar23 = 0;
                        iVar24 = FUN_00134bf0(param_2,piVar13[0x25],param_5);
                        do {
                          iVar20 = ((int (*)())FUN_00130958)(piVar15,iVar17,iVar23);
                          if (((iVar20 != 0) &&
                              (iVar20 = FUN_00134bf0(param_2,iVar17,param_5), iVar20 != local_58))
                             && ((iVar24 != iVar20 ||
                                 (iVar9 = FUN_000f313c(piVar11,iVar23), iVar9 != 0))))
                          goto LAB_00132970;
                          bVar2 = iVar23 != 3;
                          iVar23 = iVar23 + 1;
                        } while (bVar2);
                      }
                      goto LAB_00132990;
                    }
LAB_0013299c:
                    if ((((*(int *)(piVar11[0x22] + 8) == 0x32) &&
                         (piVar13 = (int *)FUN_00105594(piVar11,1), piVar13[0x20] != 0)) &&
                        (iVar17 = FUN_00126760(piVar13[0x26]), iVar17 != 0)) &&
                       (((piVar13[5] & 2U) == 0 &&
                        (iVar17 = (**(code **)(*piVar13 + 0x50))(piVar13), iVar17 == 0)))) {
                      iVar17 = FUN_00105594(piVar11,1);
                      uVar18 = FUN_00134bf0(param_2,*(undefined4 *)(iVar17 + 0x94),param_5);
                      FUN_00135334(param_2,uVar22,uVar18);
                    }
                    iVar17 = (**(code **)(*piVar11 + 0x2c))(piVar11);
                    if (iVar17 == 0) goto LAB_00132adc;
                    iVar17 = FUN_00105594(piVar11,1);
                    uVar18 = FUN_00134bf0(param_2,*(undefined4 *)(iVar17 + 0x94),param_5);
                    FUN_00135334(param_2,uVar22,uVar18);
                    uVar22 = piVar11[5];
                  }
                }
              }
              else {
LAB_00132adc:
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
                if ((uVar22 & 2) != 0) goto LAB_00132ca8;
                iVar17 = (**(code **)(*piVar13 + 0x50))(piVar13);
                if (iVar17 == 0) {
                  iVar24 = 0;
                  iVar17 = FUN_00134bf0(param_2,piVar13[0x25],param_5);
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
                  if ((uVar22 & 0x200) == 0) goto LAB_00132ca8;
                  piVar11 = (int *)FUN_00105594(piVar13,piVar13[0x21]);
                  if (((piVar11 != (int *)0x0) && (piVar11[0x20] != 0)) &&
                     ((iVar17 = FUN_00126760(piVar11[0x26]), iVar17 != 0 &&
                      (((piVar11[5] & 2U) == 0 &&
                       (iVar17 = (**(code **)(*piVar11 + 0x50))(piVar11), iVar17 == 0)))))) {
                    iVar17 = 0;
                    do {
                      iVar24 = FUN_001054ec(piVar13,0);
                      if ((*(char *)(iVar17 + iVar24 + 0x10) == '\x01') &&
                         (iVar24 = FUN_00138240(piVar11,iVar17), iVar24 != 0)) {
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
LAB_00132ca8: ;
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
              iVar24 = ((int (*)())FUN_0013097c)(piVar15,iVar17);
              if (iVar24 != 0) {
                uVar18 = FUN_00134bf0(param_2,iVar17,param_5);
                FUN_00135334(param_2,uVar22,uVar18);
              }
              iVar17 = iVar17 + 1;
            } while (param_4 != iVar17);
          }
        }
        while (bVar1) {
          uVar22 = piVar11[5];
          if ((uVar22 & 1) != 0) {
            iVar17 = FUN_001054ec(piVar11,0);
            if (((((*(int *)(iVar17 + 0x10) != DAT_001affe8) &&
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
                          (iVar20 = FUN_00137e98(piVar11,iVar24,piVar11), iVar20 == 0)))))) {
                    iVar20 = FUN_001054ec(piVar11,iVar24);
                    FUN_000f3398(local_48,*(undefined4 *)(iVar20 + 0x10));
                    local_58 = local_48[0];
                    iVar20 = FUN_00134bf0(param_2,piVar13[0x25],param_5);
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
              if ((uVar22 & 0x200) == 0) goto LAB_0013304c;
              piVar13 = (int *)FUN_00105594(piVar11,piVar11[0x21]);
              if ((((piVar13 != (int *)0x0) && (piVar13[0x20] != 0)) &&
                  (iVar17 = FUN_00126760(piVar13[0x26]), iVar17 != 0)) &&
                 ((((piVar13[5] & 2U) == 0 &&
                   (iVar17 = (**(code **)(*piVar13 + 0x50))(piVar13), iVar17 == 0)) &&
                  (iVar17 = FUN_00137e98(piVar11,piVar11[0x21],piVar11), iVar17 == 0)))) {
                iVar24 = 0;
                iVar17 = FUN_00134bf0(param_2,piVar13[0x25],param_5);
                uVar22 = iVar17 << 2;
                do {
                  iVar17 = FUN_001054ec(piVar11,0);
                  if ((*(char *)(iVar24 + iVar17 + 0x10) == '\x01') &&
                     (iVar17 = FUN_00138240(piVar13,iVar24), iVar17 != 0)) {
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
LAB_0013304c:
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
LAB_00132970:
  FUN_00135334(param_2,uVar22,iVar20);
LAB_00132990:
  iVar17 = iVar17 + 1;
  if (param_4 == iVar17) goto LAB_0013299c;
  goto LAB_00132828;
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
    uVar3 = FUN_00134bf0(param_1,param_2[0x25],0);
    iVar2 = FUN_00134bf0(param_1,piVar1[0x25],0);
    iVar4 = FUN_0013555c(param_1,iVar2,uVar3);
  } while (((((iVar4 != 0) && ((piVar1[5] & 0x200U) != 0)) &&
            ((piVar5 = (int *)FUN_00105594(piVar1,piVar1[0x21]), piVar5[0x20] != 0 &&
             ((iVar4 = FUN_00126760(piVar5[0x26]), iVar4 != 0 && ((piVar5[5] & 2U) == 0)))))) &&
           (iVar4 = (**(code **)(*piVar5 + 0x50))(piVar5), iVar4 == 0)) &&
          ((iVar4 = FUN_00134bf0(param_1,piVar5[0x25],0), iVar2 != iVar4 &&
           (param_2 = piVar1, piVar1 != (int *)0x0))));
  return;
}

/* FUN_0013323c @ 0x13323c (3452 bytes) */
int FUN_0013323c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint *puVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  undefined4 *puVar17;
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
  int local_88[0];
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
  local_88[0] = FUN_00193e18(local_84,8);
  iVar8 = FUN_000ee7a0(param_1);
  iVar5 = *(int *)(param_1 + 0x248);
  uVar25 = 0;
  do {
    *(undefined4 *)(param_1 + 0x250) = 0;
    if (0 < iVar5) {
      FUN_00135278(param_2);
      FUN_00134db0(param_2);
      local_8c = 0;
    }
    *(int *)(*(int *)(param_1 + 8) + 0x39c) = *(int *)(*(int *)(param_1 + 8) + 0x39c) + 1;
    piVar9 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
    (**(code **)(*piVar9 + 0x148))
              (piVar9,param_2,*(undefined4 *)(param_1 + 0x46c),*(undefined4 *)(param_1 + 0x464),
               uVar25);
    iVar19 = 0;
    for (iVar5 = 0; iVar10 = FUN_00194034(param_1 + 0x37c), iVar5 < iVar10; iVar5 = iVar5 + 1) {
      bVar20 = false;
      iVar10 = *(int *)(iVar8 + iVar5 * 4);
      piVar16 = *(int **)(iVar10 + 0x98);
      piVar9 = (int *)piVar16[2];
      if (piVar9 != (int *)0x0) {
        do {
          piVar23 = piVar16;
          if (piVar16 != (int *)0x0) {
            piVar9 = (int *)0x0;
            piVar26 = piVar16;
            do {
              uVar4 = piVar26[5];
              if ((uVar4 & 1) == 0) goto LAB_001339e4;
              iVar11 = (**(code **)(*piVar26 + 0x7c))(piVar26);
              if (iVar11 == 0) {
                if ((piVar26[5] & 0x10000U) == 0) {
                  if (piVar9 == (int *)0x0) {
                    piVar9 = piVar26;
                  }
                  if (bVar20) {
                    bVar20 = false;
                    piVar26[5] = piVar26[5] | 0x1000;
                  }
                }
                if (((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x200) != 0) &&
                   (((((iVar11 = (**(code **)(*piVar26 + 0x28))(piVar26), iVar11 != 0 ||
                       (iVar11 = (**(code **)(*piVar26 + 0x68))(piVar26), iVar11 != 0)) &&
                      (piVar12 = (int *)FUN_00105594(piVar26,1), piVar12[0x20] != 0)) &&
                     ((iVar11 = FUN_00126760(piVar12[0x26]), iVar11 != 0 && ((piVar12[5] & 2U) == 0)
                      ))) && (iVar11 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar11 == 0)))) {
                  iVar11 = FUN_001054ec(piVar26,1);
                  FUN_000f3398(&local_68,*(undefined4 *)(iVar11 + 0x10));
                  iVar21 = 0;
                  local_98 = local_68;
                  iVar11 = -1;
                  do {
                    iVar15 = iVar11;
                    if ((((*(char *)((int)&local_98 + iVar21) != '\0') &&
                         (piVar13 = (int *)FUN_001382b8(piVar12,iVar21,&local_94),
                         piVar13 != (int *)0x0)) &&
                        ((piVar13[0x20] != 0 &&
                         (((iVar14 = FUN_00126760(piVar13[0x26]), iVar14 != 0 &&
                           ((piVar13[5] & 2U) == 0)) &&
                          (iVar14 = (**(code **)(*piVar13 + 0x50))(piVar13), iVar14 == 0)))))) &&
                       ((iVar15 = FUN_00134bf0(param_2,piVar13[0x25],iVar19), uVar4 = local_8c,
                        iVar11 != -1 && (bVar2 = iVar11 != iVar15, iVar15 = iVar11, bVar2)))) {
                      if (local_8c < local_90) {
                        iVar11 = local_8c * 4;
                        _memset((void *)(iVar11 + local_88[0]),0,4);
                        local_8c = uVar4 + 1;
                        puVar17 = (undefined4 *)(iVar11 + local_88[0]);
                      }
                      else {
                        puVar17 = (undefined4 *)FUN_0019423c(&local_90,local_8c);
                      }
                      *puVar17 = piVar26;
                      break;
                    }
                    bVar2 = iVar21 != 3;
                    iVar21 = iVar21 + 1;
                    iVar11 = iVar15;
                  } while (bVar2);
                }
                if ((((piVar26[5] & 0x200U) != 0) &&
                    (piVar12 = (int *)FUN_00105594(piVar26,piVar26[0x21]), (piVar12[5] & 1U) != 0))
                   && ((piVar12[0x20] != 0 &&
                       (((iVar11 = FUN_00126760(piVar12[0x26]), iVar11 != 0 &&
                         ((piVar12[5] & 2U) == 0)) &&
                        (iVar11 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar11 == 0)))))) {
                  iVar11 = FUN_00134bf0(param_2,piVar26[0x25],iVar19);
                  iVar21 = FUN_00134bf0(param_2,piVar12[0x25],iVar19);
                  if (iVar11 != iVar21) {
                    if (((piVar26[5] & 0x40U) == 0) || ((piVar12[5] & 0x40U) == 0)) {
                      if ((*(int *)(iVar11 * 4 + *(int *)(param_1 + 0x45c)) ==
                           *(int *)(iVar21 * 4 + *(int *)(param_1 + 0x45c))) &&
                         (iVar11 = FUN_00135c20(param_2,iVar11,iVar21), iVar11 != 0)) {
                        iVar19 = 1;
                        *(int *)(param_1 + 0x24c) = *(int *)(param_1 + 0x24c) + 1;
                      }
                      else {
                        *(int *)(param_1 + 0x250) = *(int *)(param_1 + 0x250) + 1;
                      }
                    }
                    else if ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x200) == 0)
                    {
                      ((int (*)())FUN_001315f8)(param_2,piVar26,piVar12,param_1 + 0x464,piVar16,iVar10);
                    }
                  }
                }
                iVar11 = (**(code **)(*piVar26 + 100))(piVar26);
                if (iVar11 == 0) goto LAB_001339e0;
                puVar24 = (uint *)(piVar26 + 0x2e);
                for (iVar11 = 1; iVar21 = (**(code **)(*piVar26 + 0x14))(piVar26), iVar11 <= iVar21;
                    iVar11 = iVar11 + 1) {
                  uVar4 = *puVar24;
                  puVar24 = puVar24 + 6;
                  if ((((uVar4 & 1) != 0) || ((uVar4 & 2) != 0)) ||
                     (iVar21 = FUN_000f31e8(piVar26,iVar11), iVar21 == 0)) goto LAB_001339e0;
                }
                if ((piVar26[0x48] != 0) || (piVar26[0x49] != 0)) goto LAB_001339e0;
                if (((piVar26[0x20] != 0) &&
                    ((iVar11 = FUN_00126760(piVar26[0x26]), iVar11 != 0 && ((piVar26[5] & 2U) == 0))
                    )) && (iVar11 = (**(code **)(*piVar26 + 0x50))(piVar26), iVar11 == 0)) {
                  iVar11 = 4;
                  piVar12 = piVar26;
                  do {
                    if (*(byte *)(piVar12 + 0x27) - 2 < 2) goto LAB_001339e0;
                    piVar12 = (int *)((int)piVar12 + 1);
                    iVar11 = iVar11 + -1;
                  } while (iVar11 != 0);
                }
                FUN_001054ec(piVar26,0);
                iVar11 = FUN_00105dbc(piVar26,0);
                if (iVar11 != 0) goto LAB_001339e0;
                uVar4 = piVar26[5];
                if ((((uVar4 & 2) == 0) && ((uVar4 & 0x200) == 0)) && (-1 < (int)uVar4)) {
                  piVar12 = (int *)FUN_00105594(piVar26,1);
                  if (((piVar12[0x20] != 0) && (iVar11 = FUN_00126760(piVar12[0x26]), iVar11 != 0))
                     && (((piVar12[5] & 2U) == 0 &&
                         (iVar11 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar11 == 0)))) {
                    iVar11 = FUN_00134bf0(param_2,piVar26[0x25],iVar19);
                    iVar21 = FUN_00134bf0(param_2,piVar12[0x25],iVar19);
                    if (((0 < *(int *)(*(int *)(param_1 + 8) + 0x678)) &&
                        (*(int *)(iVar11 * 4 + *(int *)(param_1 + 0x45c)) ==
                         *(int *)(iVar21 * 4 + *(int *)(param_1 + 0x45c)))) &&
                       (iVar15 = FUN_00135c20(param_2,iVar11,iVar21), uVar4 = local_7c, iVar15 != 0)
                       ) {
                      *(int *)(param_1 + 0x254) = *(int *)(param_1 + 0x254) + 1;
                      if ((piVar26[5] & 0x1000U) != 0) {
                        if ((piVar9 == (int *)0x0) || (piVar9 == piVar26)) {
                          bVar20 = true;
                        }
                        else {
                          piVar9[5] = piVar9[5] | 0x1000;
                        }
                      }
                      if (((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x200) == 0) ||
                         ((piVar26[5] & 0x40000000U) == 0)) {
                        (**(code **)(*piVar26 + 0xc))(piVar26,0);
                        uVar4 = piVar26[5];
                        iVar19 = 1;
                      }
                      else {
                        if (local_7c < local_80) {
                          iVar19 = local_7c * 4;
                          _memset((void *)(iVar19 + local_78),0,4);
                          local_7c = uVar4 + 1;
                          puVar17 = (undefined4 *)(iVar19 + local_78);
                        }
                        else {
                          puVar17 = (undefined4 *)FUN_0019423c(&local_80,local_7c);
                        }
                        *puVar17 = piVar26;
                        iVar19 = 1;
                        uVar4 = piVar26[5] | 0x80000000;
                        piVar26[5] = uVar4;
                      }
                      goto LAB_001339e4;
                    }
                    if ((*(int *)(param_1 + 0x46c) <= iVar11) &&
                       (*(int *)(iVar11 * 4 + *(int *)(param_1 + 0x45c)) ==
                        *(int *)(iVar21 * 4 + *(int *)(param_1 + 0x45c)))) {
                      FUN_00135684(param_2,iVar11,iVar21);
                    }
                  }
                  goto LAB_001339e0;
                }
              }
              else {
LAB_001339e0:
                uVar4 = piVar26[5];
              }
LAB_001339e4:
              piVar26 = (int *)piVar26[2];
            } while ((piVar26 != (int *)0x0) && ((uVar4 & 4) != 0));
            piVar9 = (int *)piVar16[2];
          }
          do {
            piVar16 = piVar9;
            puVar24 = (uint *)(piVar23 + 5);
            piVar9 = (int *)piVar16[2];
            if (piVar9 == (int *)0x0) {
              if (bVar20) {
                iVar11 = 0;
                local_94 = (int *)0x0;
                for (uVar4 = 1; uVar4 <= *(uint *)(*(int *)(iVar10 + 0xd0) + 4); uVar4 = uVar4 + 1)
                {
                  local_94 = *(int **)(iVar11 + *(int *)(*(int *)(iVar10 + 0xd0) + 8));
                  if (local_94 != (int *)0x0) {
                    iVar21 = (**(code **)(*local_94 + 0x30))();
                    if (iVar21 == 0) {
                      local_94[0x37] = 1;
                    }
                    else {
                      *(undefined4 *)(local_94[0x4b] + 0xdc) = 1;
                    }
                  }
                  iVar11 = iVar11 + 4;
                }
              }
              goto LAB_00133348;
            }
            piVar23 = piVar16;
          } while ((*puVar24 & 4) != 0);
        } while( true );
      }
LAB_00133348: ;
    }
    iVar5 = *(int *)(param_1 + 0x248) + 1;
    *(int *)(param_1 + 0x248) = iVar5;
    if (iVar19 == 0) {
      iVar19 = *(int *)(param_1 + 8);
      bVar20 = false;
      goto LAB_00133af8;
    }
    iVar19 = 0;
    if (0 < *(int *)(param_1 + 0x464)) {
      do {
        FUN_00134bf0(param_2,iVar19,1);
        iVar19 = iVar19 + 1;
      } while (iVar19 < *(int *)(param_1 + 0x464));
      iVar5 = *(int *)(param_1 + 0x248);
    }
    iVar19 = *(int *)(param_1 + 8);
    if (*(int *)(iVar19 + 0x678) <= iVar5) break;
    uVar25 = 1;
  } while( true );
  bVar20 = true;
LAB_00133af8:
  *(undefined4 *)(param_1 + 0x34) = 5;
  if ((*(uint *)(*(int *)(iVar19 + 0x30c) + 8) & 0x200) != 0) {
LAB_00133bf0:
    if (local_7c != 0) {
      puVar17 = (undefined4 *)0x0;
      if (local_7c - 1 < local_7c) {
        puVar17 = (undefined4 *)((local_7c - 1) * 4 + local_78);
      }
      piVar16 = (int *)*puVar17;
      FUN_00194208(&local_80);
      iVar5 = FUN_00134bf0(param_2,piVar16[0x25],0);
      piVar9 = (int *)FUN_00105594(piVar16,1);
      do {
        iVar8 = (**(code **)(*piVar9 + 0x50))(piVar9);
        if (iVar8 != 0) {
LAB_00133bd0:
          (**(code **)(*piVar16 + 0xc))(piVar16,0,*(undefined4 *)(param_1 + 8));
          break;
        }
        iVar8 = FUN_00134bf0(param_2,piVar9[0x25],0);
        if ((piVar9[5] & 0x200U) == 0) {
          if (iVar5 == iVar8) goto LAB_00133bd0;
          break;
        }
        piVar9 = (int *)FUN_00105594(piVar9,piVar9[0x21]);
      } while (iVar5 == iVar8);
      goto LAB_00133bf0;
    }
    if (local_8c != 0) {
      FUN_00137694(param_2);
      uVar4 = local_8c;
      while (local_8c != 0) {
        puVar17 = (undefined4 *)0x0;
        if (local_8c - 1 < local_8c) {
          puVar17 = (undefined4 *)((local_8c - 1) * 4 + local_88[0]);
        }
        uVar22 = *puVar17;
        FUN_00194208(&local_90);
        *(int *)(param_1 + 600) = *(int *)(param_1 + 600) + 1;
        uVar25 = FUN_00105594(uVar22,1);
        piVar16 = (int *)((int (*)())FUN_00130c8c)(param_2,uVar22,uVar25,param_1 + 0x464);
        iVar5 = FUN_001054ec(uVar22,1);
        FUN_000f366c(&local_64,*(undefined4 *)(iVar5 + 0x10));
        piVar16[0x27] = local_64;
        FUN_000f370c(&local_60);
        uVar25 = local_60;
        iVar5 = FUN_001054ec(piVar16,1);
        *(undefined4 *)(iVar5 + 0x10) = uVar25;
        FUN_000f3398(local_5c,uVar25);
        local_98 = local_5c[0];
        uVar25 = FUN_00105594(piVar16,1);
        iVar5 = 0;
        piVar9 = piVar16;
        do {
          if ((*(char *)((int)&local_98 + iVar5) != '\0') &&
             (iVar8 = FUN_001382b8(uVar25,iVar5,&local_94), iVar8 == 0)) {
            *(undefined1 *)(piVar9 + 0x27) = 1;
            (**(code **)(*piVar16 + 0x88))(piVar16,1,iVar5,4);
          }
          bVar2 = iVar5 != 3;
          piVar9 = (int *)((int)piVar9 + 1);
          iVar5 = iVar5 + 1;
        } while (bVar2);
        FUN_00106004(uVar22,1,piVar16,0,*(undefined4 *)(param_1 + 8));
      }
      piVar9 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
      (**(code **)(*piVar9 + 0x14c))(piVar9,param_1);
      iVar8 = *(int *)(param_1 + 900);
      iVar5 = *(int *)(param_1 + 0x464) * 4;
      if (*(int *)(iVar8 + 8) != 0) {
        uVar3 = iVar5 + 0x1fU >> 5;
        do {
          puVar24 = *(uint **)(iVar8 + 0x104);
          uVar6 = uVar4 * 4 + puVar24[1];
          if (uVar6 + 0x1f >> 5 == *puVar24) {
            uVar18 = uVar6 + uVar4 * -4;
            puVar24[1] = uVar6;
            if (uVar18 < uVar6) {
              iVar19 = uVar6 - uVar18;
              if (uVar6 < uVar18 + 1) {
                iVar19 = 1;
              }
              do {
                uVar7 = uVar18 >> 3 & 0x1ffffffc;
                uVar6 = uVar18 & 0x1f;
                uVar18 = uVar18 + 1;
                *(uint *)((int)puVar24 + uVar7 + 8) =
                     *(uint *)((int)puVar24 + uVar7 + 8) & ~(1 << uVar6);
                iVar19 = iVar19 + -1;
              } while (iVar19 != 0);
            }
          }
          else {
            uVar25 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
            puVar17 = (undefined4 *)FUN_00193e18(uVar25,uVar3 * 4 + 0xc);
            piVar9 = puVar17 + 1;
            *puVar17 = uVar25;
            puVar17[1] = uVar3;
            puVar17[2] = iVar5;
            if (uVar3 != 0) {
              uVar6 = uVar3;
              piVar16 = piVar9;
              if (uVar3 == 0) {
                uVar6 = 1;
              }
              do {
                uVar6 = uVar6 - 1;
                piVar16[2] = 0;
                piVar16 = piVar16 + 1;
              } while (uVar6 != 0);
            }
            *(int **)(iVar8 + 0x104) = piVar9;
            iVar19 = *piVar9;
            if (iVar19 != 0) {
              if (iVar19 == 0) {
                iVar19 = 1;
              }
              do {
                iVar19 = iVar19 + -1;
                puVar1 = puVar24 + 2;
                puVar24 = puVar24 + 1;
                piVar9[2] = piVar9[2] | *puVar1;
                piVar9 = piVar9 + 1;
              } while (iVar19 != 0);
            }
          }
          iVar8 = *(int *)(iVar8 + 8);
        } while (*(int *)(iVar8 + 8) != 0);
      }
      FUN_00135278(param_2);
      FUN_00134db0(param_2);
      piVar9 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
      (**(code **)(*piVar9 + 0x148))
                (piVar9,param_2,*(undefined4 *)(param_1 + 0x46c),*(undefined4 *)(param_1 + 0x464),1)
      ;
    }
  }
  if (bVar20) {
    FUN_00135278(param_2);
    FUN_00134db0(param_2);
    piVar9 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
    (**(code **)(*piVar9 + 0x148))
              (piVar9,param_2,*(undefined4 *)(param_1 + 0x46c),*(undefined4 *)(param_1 + 0x464),0);
  }
  FUN_00193cc0(local_84,local_88[0]);
  FUN_00193cc0(local_74,local_78);
  return;
}

/* FUN_00133fe4 @ 0x133fe4 (1020 bytes) */
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
          uVar5 = ((int (*)())FUN_001308e0)(iVar12);
          ((int (*)())FUN_00130abc)(uVar5,param_1,*(undefined4 *)(param_1 + 0x2c));
          uVar5 = ((int (*)())FUN_001318a4)(param_1,*(undefined4 *)(iVar12 + 0x94),uVar1);
          uVar6 = thunk_FUN_001307f8(iVar12);
          ((int (*)())FUN_001312f4)(iVar12,uVar1,uVar5,uVar6,*(undefined4 *)(param_1 + 0x2c));
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
                iVar3 = ((int (*)())FUN_001309bc)(param_1,iVar15);
                if (iVar3 != 0) {
                  iVar3 = *piVar18;
                  piVar16[5] = piVar16[5] | 0x8000000;
                  iVar3 = (**(code **)(iVar3 + 0x14))(piVar18);
                  if ((iVar7 <= iVar3) && (iVar3 = ((int (*)())FUN_00131008)(1,piVar18,iVar7), iVar3 != 0)) {
                    ((int (*)())FUN_00130abc)(piVar18,param_1,*(undefined4 *)(param_1 + 0x2c));
                    if (((piVar16[5] & 0x20000000U) == 0) || ((piVar16[6] & 1U) != 0)) {
                      iVar3 = ((int (*)())FUN_001318a4)(param_1,iVar15,uVar1);
                      iVar15 = ((int (*)())FUN_00130a08)(piVar18,*(undefined4 *)(iVar3 + 0x13c));
                      if (iVar15 == 0) {
                        uVar5 = ((int (*)())FUN_00130424)(param_1);
                        iVar15 = FUN_001054ec(piVar18,iVar7);
                        uVar13 = *(undefined4 *)(iVar15 + 0x10);
                        uVar6 = ((int (*)())FUN_00130904)(piVar18);
                        iVar15 = ((int (*)())FUN_001311cc)(uVar5,uVar13,uVar1,iVar3,uVar6,
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
                          if (piVar16 == (int *)*piVar9) goto LAB_001342f8;
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
                      uVar5 = ((int (*)())FUN_00130904)(piVar18);
                      ((int (*)())FUN_00130da0)(param_1,piVar18,iVar7,uVar5,*(undefined4 *)(param_1 + 0x2c));
                    }
                  }
                }
              }
LAB_001342f8:
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

/* FUN_00134658 @ 0x134658 (1072 bytes) */
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
  
  ((int (*)())FUN_001314b8)();
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
    FUN_0013719c(puVar6 + 1,*(undefined4 *)(param_1 + 0x46c),*(undefined4 *)(param_1 + 0x464),
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
    FUN_00138080(param_1);
    if (iVar9 != 0) {
      FUN_001378e8(*(undefined4 *)(param_1 + 0x3c0),*(undefined4 *)(param_1 + 8));
    }
    iVar9 = FUN_00135fb0(*(undefined4 *)(param_1 + 0x3c0));
    if (iVar9 != 0) {
      iVar5 = *(int *)(*(int *)(param_1 + 0x3c0) + 0x24);
      iVar4 = *(int *)(iVar5 + 4);
      if (iVar4 == 0) {
LAB_001348ac:
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
        if (iVar7 == 0) goto LAB_001348ac;
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
          ((int (*)())FUN_001314b8)(param_1);
          goto LAB_00134a58;
        }
      }
      FUN_000e1534(iVar4,4);
    }
LAB_00134a58:
    iVar4 = *(int *)(param_1 + 0x3c0);
    if (iVar4 != 0) {
      FUN_001357d4(iVar4);
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

