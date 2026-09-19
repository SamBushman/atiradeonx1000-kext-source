#include "decls.h"

/* FUN_0018d388 @ 0x18d388 (300 bytes) */
int FUN_0018d388(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  int *piVar2;
  
  param_3 = param_3 * 4;
  piVar2 = *(int **)(param_3 + param_1);
  if (piVar2 == (int *)0x0) {
    iVar1 = FUN_0018c7f4();
    if (iVar1 != 0) {
      *(int **)(param_3 + param_1) = param_2;
      return 1;
    }
  }
  else if ((piVar2 == param_2) ||
          (((((param_2 != (int *)0x0 && (piVar2[0x20] != 0)) &&
             (iVar1 = FUN_00126760(piVar2[0x26]), iVar1 != 0)) &&
            (((((piVar2[5] & 2U) == 0 && (iVar1 = (**(code **)(*piVar2 + 0x50))(piVar2), iVar1 == 0)
               ) && ((param_2[0x20] != 0 &&
                     ((iVar1 = FUN_00126760(param_2[0x26]), iVar1 != 0 && ((param_2[5] & 2U) == 0)))
                     ))) && (iVar1 = (**(code **)(*param_2 + 0x50))(param_2), iVar1 == 0)))) &&
           ((((*(uint *)(*(int *)(param_3 + param_1) + 0x14) & 0x40) != 0 &&
             ((param_2[5] & 0x40U) != 0)) &&
            (*(int *)(*(int *)(param_3 + param_1) + 0x94) == param_2[0x25])))))) {
    return 1;
  }
  return 0;
}

/* FUN_0018d4b4 @ 0x18d4b4 (1428 bytes) */
int FUN_0018d4b4(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int *param_2;
  int *param_3;
  undefined4 param_4;
  int param_5;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  int local_68;
  float local_64;
  uint local_48;
  uint local_44;
  uint local_40 [5];
  
  iVar2 = *(int *)(param_1[0x22] + 8);
  if ((((iVar2 == 0x9e) || (iVar2 == 0xa0)) || (iVar2 == 0x9f)) || (iVar8 = 1, iVar2 == 0xa1)) {
    piVar3 = (int *)FUN_00105594(param_1,1);
    iVar2 = (**(code **)(*piVar3 + 0x5c))();
    if (iVar2 != 0) {
      return 0;
    }
    iVar2 = FUN_001054ec(param_1,0);
    if (((*(char *)(iVar2 + 0x10) == '\0') ||
        (iVar2 = FUN_001054ec(param_1,0), *(char *)(iVar2 + 0x11) == '\0')) ||
       (iVar2 = FUN_001054ec(param_1,0), *(char *)(iVar2 + 0x12) == '\0')) {
      uVar4 = FUN_00105594(param_1,1);
      iVar2 = ((int (*)())FUN_0018d388)(param_4,uVar4,0);
      if (iVar2 == 0) {
        return 0;
      }
    }
    iVar2 = FUN_001054ec(param_1,0);
    if (*(char *)(iVar2 + 0x13) == '\0') {
      uVar4 = FUN_00105594(param_1,1);
      iVar2 = ((int (*)())FUN_0018d388)(param_4,uVar4,1);
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  else {
    for (; iVar2 = (**(code **)(*param_1 + 0x14))(param_1), iVar8 <= iVar2; iVar8 = iVar8 + 1) {
      piVar3 = (int *)FUN_00105594(param_1,iVar8);
      iVar2 = (**(code **)(*piVar3 + 0x60))();
      if (iVar2 != 0) {
        piVar3 = (int *)FUN_00105594(piVar3,1);
        (**(code **)(*piVar3 + 0x60))();
      }
      iVar7 = (**(code **)(*piVar3 + 0x5c))(piVar3);
      if (iVar7 != 0) {
        if (((piVar3[0x56] != 0) && (param_1[0x56] != 0)) && (param_1[0x56] != piVar3[0x56])) {
          ((int (*)())FUN_0019401c)(piVar3);
          FUN_000e7738(param_1[0x56],param_1[1],piVar3);
        }
        iVar7 = *(int *)(piVar3[0x22] + 8);
        if (iVar2 == 0) {
          iVar2 = FUN_001054ec(param_1,iVar8);
          FUN_000f3398(&local_44,*(undefined4 *)(iVar2 + 0x10));
          uVar9 = local_44;
        }
        else {
          uVar4 = FUN_00105594(param_1,iVar8);
          iVar2 = FUN_001054ec(uVar4,1);
          FUN_000f3398(&local_48,*(undefined4 *)(iVar2 + 0x10));
          uVar9 = local_48;
        }
        if ((uVar9 & 0xffffff00) != 0) {
          if ((-1 < *param_2) && (iVar7 != *param_2)) {
            return 0;
          }
          *param_2 = iVar7;
          iVar2 = (**(code **)(*piVar3 + 0x14))(piVar3);
          if (iVar2 == 1) {
            uVar4 = FUN_00105594(piVar3,1);
            iVar2 = ((int (*)())FUN_0018d388)(param_4,uVar4,0);
          }
          else {
            uVar4 = FUN_00105594(piVar3,1);
            uVar5 = FUN_00105594(piVar3,2);
            iVar2 = FUN_0018cdd8(param_4,uVar4,uVar5,0);
          }
          if (iVar2 == 0) {
            return 0;
          }
        }
        if ((uVar9 & 0xff) != 0) {
          if ((-1 < *param_3) && (iVar7 != *param_3)) {
            return 0;
          }
          *param_3 = iVar7;
          iVar2 = (**(code **)(*piVar3 + 0x14))(piVar3);
          if (iVar2 == 1) {
            uVar4 = FUN_00105594(piVar3,1);
            iVar2 = ((int (*)())FUN_0018d388)(param_4,uVar4,1);
          }
          else {
            uVar4 = FUN_00105594(piVar3,1);
            uVar5 = FUN_00105594(piVar3,2);
            iVar2 = FUN_0018cdd8(param_4,uVar4,uVar5,1);
          }
          if (iVar2 == 0) {
            return 0;
          }
        }
      }
    }
    for (iVar2 = 1; iVar8 = (**(code **)(*param_1 + 0x14))(param_1), iVar2 <= iVar8;
        iVar2 = iVar2 + 1) {
      piVar3 = (int *)FUN_00105594(param_1,iVar2);
      iVar8 = (**(code **)(*piVar3 + 0x60))();
      if (iVar8 == 0) {
        bVar1 = false;
        piVar10 = param_1;
        piVar6 = piVar3;
        iVar8 = iVar2;
LAB_0018d948:
        iVar7 = (**(code **)(*piVar6 + 0x5c))(piVar6);
        if ((iVar7 == 0) && ((bVar1 || (piVar6[0x26] != 0x33)))) {
          iVar8 = FUN_001054ec(piVar10,iVar8);
          FUN_000f3398(local_40,*(undefined4 *)(iVar8 + 0x10));
          if ((local_40[0] & 0xffffff00) == 0) {
            if ((local_40[0] & 0xff) == 0) goto LAB_0018da08;
            iVar8 = FUN_0018c7f4(param_4,piVar6,1);
          }
          else if ((local_40[0] & 0xff) == 0) {
            iVar8 = FUN_0018c7f4(param_4,piVar6,0);
          }
          else {
            iVar8 = FUN_0018c980(param_4,piVar6,piVar6);
          }
          if (iVar8 == 0) {
            return 0;
          }
        }
      }
      else {
        piVar6 = (int *)FUN_00105594(piVar3,1);
        (**(code **)(*piVar6 + 0x60))();
        piVar10 = piVar3;
        if (piVar6[0x26] != 0x33) {
LAB_0018d93c:
          bVar1 = false;
          iVar8 = 1;
          goto LAB_0018d948;
        }
        iVar8 = FUN_001054ec(piVar3,0);
        iVar8 = FUN_000f5cf0(piVar3,1,*(undefined4 *)(iVar8 + 0x10),&local_68);
        if (((iVar8 == 0) || (local_68 != 2)) ||
           (iVar8 = (**(code **)(**(int **)(param_5 + 0x30c) + 0xf0))((double)local_64), iVar8 == 0)
           ) {
          iVar8 = FUN_0010497c(piVar3,*(undefined4 *)(param_5 + 0x6c4));
          if (iVar8 == 0) {
            bVar1 = true;
            iVar8 = 1;
            goto LAB_0018d948;
          }
          goto LAB_0018d93c;
        }
      }
LAB_0018da08: ;
    }
  }
  return 1;
}

/* FUN_0018da48 @ 0x18da48 (116 bytes) */
int FUN_0018da48(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 auStack_60 [8];
  undefined1 auStack_58 [72];
  
  local_64 = 0xffffffff;
  local_68 = 0xffffffff;
  FUN_00189560(auStack_58);
  iVar1 = ((int (*)())FUN_0018d4b4)(param_1,&local_68,&local_64,auStack_58,param_2);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_0018c768(auStack_58,auStack_60);
  }
  return uVar2;
}

/* FUN_0018dabc @ 0x18dabc (1708 bytes) */
int FUN_0018dabc(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  uint *puVar20;
  uint local_78;
  uint local_74;
  int local_70;
  undefined4 local_6c;
  uint local_68;
  uint local_64;
  int local_60;
  undefined4 local_5c;
  uint local_58;
  uint local_54;
  int local_50;
  undefined4 local_4c;
  
  iVar15 = *(int *)(param_2 + 0x38);
  iVar3 = (**(code **)(*param_1 + 0x30))(param_1,iVar15);
  if ((iVar3 == 0) ||
     ((iVar3 = *(int *)(PTR_DAT_001e913c + *(int *)(*(int *)(iVar15 + 0x88) + 8) * 0x38 + 0x34),
      *(int *)(param_2 + 0x60) != 0 && (iVar4 = FUN_000f3a30(iVar15), iVar4 != 1)))) {
    uVar5 = 0;
  }
  else {
    iVar4 = FUN_001054ec(iVar15,0);
    if (*(char *)(iVar4 + 0x13) == '\0') {
      if (iVar3 == 0) {
        iVar3 = FUN_001054ec(iVar15,0);
        iVar4 = 3;
        uVar5 = FUN_000f3108(*(undefined4 *)(iVar3 + 0x10));
        iVar3 = 3;
      }
      else if (iVar3 - 1U < 2) {
        iVar4 = 3;
        uVar5 = 0;
        iVar3 = 3;
      }
      else {
        iVar4 = 3;
        uVar5 = 0xffffffff;
        iVar3 = 3;
      }
    }
    else if ((iVar3 == 5) && (*(int *)(param_2 + 0x60) == 0)) {
      iVar4 = 0;
      uVar5 = 3;
      iVar3 = 2;
    }
    else {
      iVar3 = FUN_001054ec(iVar15,0);
      uVar5 = 3;
      iVar4 = FUN_000f30d4(*(undefined4 *)(iVar3 + 0x10));
      iVar3 = iVar4;
    }
    local_6c = *(undefined4 *)(param_1[2] + 0x378);
    local_74 = 0;
    local_78 = 2;
    local_70 = ((int (*)())FUN_00193e18)(local_6c,8);
    local_5c = *(undefined4 *)(param_1[2] + 0x378);
    local_64 = 0;
    local_68 = 2;
    local_60 = ((int (*)())FUN_00193e18)(local_5c,8);
    local_4c = *(undefined4 *)(param_1[2] + 0x378);
    local_54 = 0;
    local_58 = 2;
    local_50 = ((int (*)())FUN_00193e18)(local_4c,8);
    puVar20 = *(uint **)(param_2 + 0x40);
    uVar12 = puVar20[1];
    if (0 < (int)uVar12) {
      uVar16 = 0;
      uVar13 = 1;
      iVar14 = 0;
      do {
        if (uVar16 < *puVar20) {
          uVar6 = puVar20[1];
          if (uVar6 <= uVar16) {
            _memset((void *)(uVar6 * 4 + puVar20[2]),0,(uVar16 - uVar6) * 4 + 4);
            puVar20[1] = uVar13;
          }
          piVar7 = (int *)(iVar14 + puVar20[2]);
        }
        else {
          piVar7 = (int *)((int (*)())FUN_0019423c)(puVar20,uVar16);
        }
        iVar17 = *piVar7;
        if (*(int *)(iVar17 + 8) == 0) {
          puVar20 = *(uint **)(param_2 + 0x40);
          if (uVar16 < *puVar20) {
            uVar6 = puVar20[1];
            if (uVar6 <= uVar16) {
              _memset((void *)(uVar6 * 4 + puVar20[2]),0,(uVar16 - uVar6) * 4 + 4);
              puVar20[1] = uVar13;
            }
            piVar7 = (int *)(iVar14 + puVar20[2]);
          }
          else {
            piVar7 = (int *)((int (*)())FUN_0019423c)(puVar20,uVar16);
          }
          piVar7 = *(int **)(*(int *)(*piVar7 + 4) + 0x38);
          if ((((piVar7[5] & 0x200U) == 0) ||
              (iVar8 = FUN_00105594(piVar7,piVar7[0x21]), iVar15 != iVar8)) &&
             ((iVar8 = (**(code **)(*piVar7 + 0x28))(piVar7), iVar8 == 0 ||
              ((*(uint *)(*(int *)(param_1[2] + 0x30c) + 8) & 0x800) != 0)))) {
            iVar8 = (**(code **)(*piVar7 + 0x5c))(piVar7);
            if (iVar8 != 0) {
              iVar17 = (**(code **)(*piVar7 + 0x14))(piVar7);
              if (1 < iVar17) {
                iVar17 = FUN_00105594(piVar7,1);
                iVar8 = FUN_00105594(piVar7,2);
                if (iVar17 != iVar8) goto LAB_0018dda4;
              }
              goto LAB_0018e058;
            }
            iVar8 = *(int *)(piVar7[0x22] + 8);
            if ((((iVar8 == 0x9e) || (iVar8 == 0xa0)) || (iVar8 == 0x9f)) || (iVar8 == 0xa1))
            goto LAB_0018dda4;
            iVar8 = *(int *)(iVar17 + 0x10);
            if ((iVar8 < 1) || (*(int *)(iVar17 + 0x14) != 0)) {
              piVar9 = (int *)FUN_00105594(piVar7);
              iVar8 = (**(code **)(*piVar9 + 0x5c))();
              if (iVar8 != 0) {
                iVar8 = *(int *)(iVar17 + 0x10);
                goto LAB_0018de84;
              }
            }
            else {
LAB_0018de84:
              iVar8 = FUN_001054ec(piVar7,iVar8);
              uVar19 = *(undefined4 *)(iVar8 + 0x10);
              bVar2 = false;
              iVar8 = 0;
              do {
                iVar10 = FUN_001054ec(piVar7,*(undefined4 *)(iVar17 + 0x10));
                uVar6 = (uint)*(byte *)(iVar8 + iVar10 + 0x10);
                if ((iVar4 <= (int)uVar6) && ((int)uVar6 <= iVar3)) {
                  (**(code **)(*piVar7 + 0x88))(piVar7,*(undefined4 *)(iVar17 + 0x10),iVar8,uVar5);
                  bVar2 = true;
                }
                uVar6 = local_74;
                bVar1 = iVar8 != 3;
                iVar8 = iVar8 + 1;
              } while (bVar1);
              if (bVar2) {
                if (local_74 < local_78) {
                  iVar8 = local_74 * 4;
                  _memset((void *)(iVar8 + local_70),0,4);
                  local_74 = uVar6 + 1;
                  puVar11 = (undefined4 *)(iVar8 + local_70);
                }
                else {
                  puVar11 = (undefined4 *)((int (*)())FUN_0019423c)(&local_78,local_74);
                }
                uVar6 = local_64;
                *puVar11 = piVar7;
                uVar18 = *(undefined4 *)(iVar17 + 0x10);
                if (local_64 < local_68) {
                  iVar17 = local_64 * 4;
                  _memset((void *)(iVar17 + local_60),0,4);
                  local_64 = uVar6 + 1;
                  puVar11 = (undefined4 *)(iVar17 + local_60);
                }
                else {
                  puVar11 = (undefined4 *)((int (*)())FUN_0019423c)(&local_68,local_64);
                }
                uVar6 = local_54;
                *puVar11 = uVar18;
                if (local_54 < local_58) {
                  iVar17 = local_54 * 4;
                  _memset((void *)(iVar17 + local_50),0,4);
                  local_54 = uVar6 + 1;
                  puVar11 = (undefined4 *)(iVar17 + local_50);
                }
                else {
                  puVar11 = (undefined4 *)((int (*)())FUN_0019423c)(&local_58,local_54);
                }
                *puVar11 = uVar19;
              }
            }
            iVar17 = (**(code **)(*piVar7 + 0x5c))(piVar7);
            if (((iVar17 != 0) || (iVar17 = (**(code **)(*piVar7 + 0x60))(piVar7), iVar17 != 0)) ||
               ((iVar17 = (**(code **)(*param_1 + 0x88))(param_1,piVar7), iVar17 != 0 &&
                (iVar17 = ((int (*)())FUN_0018da48)(piVar7,param_1[2]), iVar17 != 0)))) goto LAB_0018e058;
          }
LAB_0018dda4:
          uVar5 = 0;
          goto LAB_0018e110;
        }
LAB_0018e058:
        uVar16 = uVar16 + 1;
        uVar13 = uVar13 + 1;
        iVar14 = iVar14 + 4;
        if (uVar12 == uVar16) break;
        puVar20 = *(uint **)(param_2 + 0x40);
      } while( true );
    }
    uVar5 = 1;
LAB_0018e110:
    while (local_74 != 0) {
      piVar7 = (int *)0x0;
      if (local_74 - 1 < local_74) {
        piVar7 = (int *)((local_74 - 1) * 4 + local_70);
      }
      iVar3 = *piVar7;
      ((int (*)())FUN_00194208)(&local_78);
      piVar7 = (int *)0x0;
      if (local_64 - 1 < local_64) {
        piVar7 = (int *)((local_64 - 1) * 4 + local_60);
      }
      iVar15 = *piVar7;
      ((int (*)())FUN_00194208)(&local_68);
      puVar11 = (undefined4 *)0x0;
      if (local_54 - 1 < local_54) {
        puVar11 = (undefined4 *)((local_54 - 1) * 4 + local_50);
      }
      uVar19 = *puVar11;
      ((int (*)())FUN_00194208)(&local_58);
      if (iVar15 == 0) {
        *(undefined4 *)(iVar3 + 0x9c) = uVar19;
      }
      else {
        iVar3 = FUN_001054ec(iVar3,iVar15);
        *(undefined4 *)(iVar3 + 0x10) = uVar19;
      }
    }
    ((int (*)())FUN_00193cc0)(local_4c,local_50);
    ((int (*)())FUN_00193cc0)(local_5c,local_60);
    ((int (*)())FUN_00193cc0)(local_6c,local_70);
  }
  return uVar5;
}

/* FUN_0018e1a8 @ 0x18e1a8 (4688 bytes) */
int FUN_0018e1a8(param_1, param_2)
  int *param_1;
  int *param_2;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  uint *puVar18;
  undefined4 uVar19;
  int iVar20;
  uint uVar21;
  double dVar22;
  int local_98;
  uint local_94;
  uint local_90;
  int local_8c;
  undefined4 local_88;
  uint local_84 [7];
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  undefined4 local_5c [3];
  
  iVar15 = param_2[0x56];
  iVar17 = *(int *)(param_1[2] + 0x6c4);
  iVar5 = FUN_000e07dc(param_1[2],0x40);
  if (((iVar5 == 0) || (*(int *)(param_2[0x22] + 8) != 0x77)) || ((param_2[5] & 0x2000000U) != 0)) {
    piVar6 = (int *)0x0;
  }
  else {
    local_88 = *(undefined4 *)(param_1[2] + 0x378);
    local_90 = 0;
    local_94 = 2;
    local_8c = ((int (*)())FUN_00193e18)(local_88,8);
    local_84[3] = *(undefined4 *)(param_1[2] + 0x378);
    local_84[1] = 0;
    local_84[0] = 2;
    local_84[2] = ((int (*)())FUN_00193e18)(local_84[3],8);
    iVar14 = *(int *)(iVar17 + 0x474) + 1;
    *(int *)(iVar17 + 0x474) = iVar14;
    iVar5 = FUN_00105594(param_2,1);
    *(int *)(iVar5 + 0x150) = iVar14;
    if (local_90 < local_94) {
      iVar7 = local_90 * 4;
      uVar21 = local_90 + 1;
      _memset((void *)(iVar7 + local_8c),0,4);
      piVar6 = (int *)(iVar7 + local_8c);
      local_90 = uVar21;
    }
    else {
      piVar6 = (int *)((int (*)())FUN_0019423c)(&local_94,local_90);
    }
    *piVar6 = iVar5;
    bVar2 = false;
    bVar3 = false;
    do {
      piVar6 = (int *)0x0;
      if (local_90 - 1 < local_90) {
        piVar6 = (int *)((local_90 - 1) * 4 + local_8c);
      }
      iVar20 = *piVar6;
      ((int (*)())FUN_00194208)(&local_94);
      iVar7 = FUN_001132a4(*(undefined4 *)(*(int *)(iVar20 + 0x88) + 8),param_1[2]);
      if (iVar7 != 0) goto LAB_0018e6f8;
      iVar7 = FUN_001132f0(*(undefined4 *)(*(int *)(iVar20 + 0x88) + 8),param_1[2]);
      if (iVar7 != 0) {
        iVar7 = *(int *)(*(int *)(iVar20 + 0x88) + 8);
        if (((iVar7 == 0x24) || (iVar7 == 0x25)) || (iVar12 = 1, iVar7 == 0x26)) {
          iVar12 = 2;
        }
        if (iVar12 <= *(int *)(iVar20 + 0x84)) {
          iVar7 = iVar12 * 0x18;
          puVar18 = (uint *)(iVar7 + iVar20 + 0xa0);
          do {
            piVar6 = (int *)FUN_00105594(iVar20,iVar12);
            if (iVar14 != piVar6[0x54]) {
              piVar6[0x54] = iVar14;
              iVar8 = FUN_001132a4(*(undefined4 *)(piVar6[0x22] + 8),param_1[2]);
              if (iVar8 != 0) {
LAB_0018e6e0:
                bVar2 = true;
                break;
              }
              if ((*puVar18 & 1) != 0) {
                iVar8 = (**(code **)(*piVar6 + 0x48))(piVar6);
                if (iVar8 == 0) {
                  iVar8 = FUN_0010497c(piVar6,iVar17);
                  if (iVar8 == 0) goto LAB_0018e6e0;
                  iVar8 = *(int *)(piVar6[0x22] + 8);
                  if (iVar8 == 0x31) {
LAB_0018e4e0:
                    FUN_00103d50(piVar6 + 0x29,1,piVar6[0x2e] & 1U ^ 1);
                  }
                  else if (iVar8 == 0x12) {
                    FUN_00103d50(piVar6 + 0x29,1,piVar6[0x2e] & 1U ^ 1);
                    FUN_00103d50(piVar6 + 0x2f,1,piVar6[0x34] & 1U ^ 1);
                  }
                  else {
                    if (iVar8 == 0x13) goto LAB_0018e4e0;
                    if (iVar8 == 0x14) {
                      FUN_00103d50(piVar6 + 0x29,1,piVar6[0x2e] & 1U ^ 1);
                    }
                    else {
                      if (((iVar8 != 0x24) && (iVar8 != 0x25)) && (iVar8 != 0x26))
                      goto LAB_0018e6e0;
                      iVar8 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,piVar6,2);
                      if (iVar8 == 0) {
                        FUN_00103d50(piVar6 + 0x2f,1,piVar6[0x34] & 1U ^ 1);
                      }
                      iVar8 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,piVar6,3);
                      if (iVar8 != 0) goto LAB_0018e5a0;
                    }
                    FUN_00103d50(piVar6 + 0x35,1,piVar6[0x3a] & 1U ^ 1);
                  }
LAB_0018e5a0:
                  uVar13 = 0;
                }
                else {
                  iVar8 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,iVar20,iVar12);
                  fVar4 = FLOAT_001aa0d4;
                  if (iVar8 != 0) goto LAB_0018e5a0;
                  uVar21 = 0;
                  piVar11 = piVar6;
                  do {
                    iVar8 = FUN_001054ec(piVar6,0);
                    if ((*(char *)(uVar21 + iVar8 + 0x10) != '\x01') &&
                       (((((int)*(char *)(piVar6 + 0x57) >> (uVar21 & 0x3f) & 1U) == 0 ||
                         (piVar11[7] != 2)) || ((float)piVar11[8] == fVar4)))) goto LAB_0018e6e0;
                    bVar1 = uVar21 != 3;
                    piVar11 = piVar11 + 6;
                    uVar21 = uVar21 + 1;
                  } while (bVar1);
                  if (bVar2) goto LAB_0018e6e0;
                  uVar13 = 1;
                }
                FUN_00103d50(iVar7 + iVar20 + 0x8c,1,uVar13);
              }
              iVar8 = FUN_001132f0(*(undefined4 *)(piVar6[0x22] + 8),param_1[2]);
              if (iVar8 == 0) {
                if (*(int *)(piVar6[0x22] + 8) == 0x31) {
                  iVar8 = FUN_00105594(piVar6,1);
                  iVar8 = FUN_001132a4(*(undefined4 *)(*(int *)(iVar8 + 0x88) + 8),param_1[2]);
                  if (iVar8 == 0) {
                    iVar8 = FUN_00105594(piVar6,1);
                    iVar8 = FUN_001132f0(*(undefined4 *)(*(int *)(iVar8 + 0x88) + 8),param_1[2]);
                    if (iVar8 == 0) goto LAB_0018e6c4;
                  }
                  uVar21 = local_84[1];
                  if (local_84[1] < local_84[0]) {
                    iVar8 = local_84[1] * 4;
                    _memset((void *)(iVar8 + local_84[2]),0,4);
                    local_84[1] = uVar21 + 1;
                    puVar9 = (undefined4 *)(iVar8 + local_84[2]);
                  }
                  else {
                    puVar9 = (undefined4 *)((int (*)())FUN_0019423c)(local_84,local_84[1]);
                  }
                  *puVar9 = piVar6;
                  bVar3 = true;
                }
              }
              else {
                if (local_90 < local_94) {
                  iVar8 = local_90 * 4;
                  uVar21 = local_90 + 1;
                  _memset((void *)(iVar8 + local_8c),0,4);
                  puVar9 = (undefined4 *)(iVar8 + local_8c);
                  local_90 = uVar21;
                }
                else {
                  puVar9 = (undefined4 *)((int (*)())FUN_0019423c)(&local_94,local_90);
                }
                *puVar9 = piVar6;
              }
            }
LAB_0018e6c4:
            iVar12 = iVar12 + 1;
            iVar7 = iVar7 + 0x18;
            puVar18 = puVar18 + 6;
          } while (iVar12 <= *(int *)(iVar20 + 0x84));
        }
      }
    } while (local_90 != 0);
    if (bVar2) {
LAB_0018e6f8:
      *(int *)(iVar17 + 0x238) = *(int *)(iVar17 + 0x238) + 1;
      piVar6 = (int *)FUN_001043f0(0x31,param_1[2]);
      piVar6[0x26] = 0;
      piVar6[0x25] = piVar6[0x53];
      FUN_00106004(piVar6,1,iVar5,0,param_1[2]);
      FUN_00106004(param_2,1,piVar6,0,param_1[2]);
      uVar13 = DAT_001b2a68;
      piVar6[0x27] = DAT_001b2a80;
      iVar5 = FUN_001054ec(piVar6,1);
      *(undefined4 *)(iVar5 + 0x10) = uVar13;
      iVar5 = 0;
      do {
        iVar14 = FUN_001054ec(param_2,1);
        uVar21 = (uint)*(byte *)(iVar5 + iVar14 + 0x10);
        if (uVar21 != 4) {
          (**(code **)(*piVar6 + 0x88))(piVar6,1,uVar21,uVar21);
          *(undefined1 *)((int)piVar6 + uVar21 + 0x9c) = 0;
        }
        bVar2 = iVar5 != 3;
        iVar5 = iVar5 + 1;
      } while (bVar2);
      FUN_000e7700(iVar15,param_2,piVar6);
      piVar6[5] = piVar6[5] | 0x80000000;
    }
    else {
      if (bVar3) {
        while (local_84[1] != 0) {
          piVar6 = (int *)0x0;
          if (local_84[1] - 1 < local_84[1]) {
            piVar6 = (int *)((local_84[1] - 1) * 4 + local_84[2]);
          }
          iVar5 = *piVar6;
          ((int (*)())FUN_00194208)(local_84);
          *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x80000000;
        }
      }
      piVar6 = (int *)0x0;
    }
    ((int (*)())FUN_00193cc0)(local_84[3],local_84[2]);
    ((int (*)())FUN_00193cc0)(local_88,local_8c);
  }
  uVar13 = 0;
  iVar5 = (**(code **)(*param_2 + 0x28))(param_2);
  if (iVar5 != 0) {
    bVar2 = piVar6 == (int *)0x0;
    for (iVar5 = 1; iVar14 = (**(code **)(*param_2 + 0x14))(param_2), iVar5 <= iVar14;
        iVar5 = iVar5 + 1) {
      piVar11 = (int *)FUN_00105594(param_2,iVar5);
      iVar14 = (**(code **)(*piVar11 + 0x60))();
      if (iVar14 == 0) {
LAB_0018e934:
        piVar11 = (int *)FUN_00105594(param_2,iVar5);
        iVar14 = (**(code **)(*piVar11 + 0x48))();
        if (iVar14 == 0) {
          piVar11 = (int *)FUN_00105594(param_2,iVar5);
          iVar14 = (**(code **)(*piVar11 + 0x60))();
          if ((iVar14 == 0) &&
             ((((param_2[iVar5 * 6 + 0x28] & 2U) == 0 && ((param_2[iVar5 * 6 + 0x28] & 1U) == 0)) ||
              (iVar14 = FUN_00148d8c(param_2,iVar17), iVar14 != 0)))) goto LAB_0018eb5c;
        }
        iVar7 = 0;
        *(int *)(iVar17 + 0x238) = *(int *)(iVar17 + 0x238) + 1;
        piVar10 = (int *)FUN_001043f0(0x31,param_1[2]);
        piVar10[0x26] = 0;
        piVar10[0x25] = piVar10[0x53];
        uVar13 = FUN_00105594(param_2,iVar5);
        FUN_00106004(piVar10,1,uVar13,0,param_1[2]);
        FUN_00103d50(piVar10 + 0x29,2,(uint)param_2[iVar5 * 6 + 0x28] >> 1 & 1);
        FUN_00103d50(piVar10 + 0x29,1,param_2[iVar5 * 6 + 0x28] & 1);
        iVar14 = FUN_001054ec(param_2,iVar5);
        uVar13 = *(undefined4 *)(iVar14 + 0x10);
        iVar14 = FUN_001054ec(piVar10,1);
        local_94 = DAT_001b2a64;
        *(undefined4 *)(iVar14 + 0x10) = uVar13;
        piVar11 = piVar10;
        do {
          iVar14 = FUN_001054ec(param_2,iVar5);
          if (*(char *)(iVar7 + iVar14 + 0x10) == '\x04') {
            *(undefined1 *)(piVar11 + 0x27) = 1;
            *(undefined1 *)((int)&local_94 + iVar7) = 4;
          }
          bVar3 = iVar7 != 3;
          piVar11 = (int *)((int)piVar11 + 1);
          iVar7 = iVar7 + 1;
        } while (bVar3);
        FUN_000e7700(iVar15,param_2,piVar10);
        FUN_00106004(param_2,iVar5,piVar10,0,param_1[2]);
        FUN_00103d50(param_2 + iVar5 * 6 + 0x23,2,0);
        FUN_00103d50(param_2 + iVar5 * 6 + 0x23,1,0);
        uVar21 = local_94;
        iVar14 = FUN_001054ec(param_2,iVar5);
        *(uint *)(iVar14 + 0x10) = uVar21;
        if (bVar2) {
          bVar2 = piVar10 == (int *)0x0;
          uVar13 = 1;
          piVar6 = piVar10;
        }
        else {
          uVar13 = 1;
        }
      }
      else {
        uVar16 = FUN_00105594(param_2,iVar5);
        uVar16 = FUN_00105594(uVar16,1);
        iVar14 = FUN_0010497c(uVar16,*(undefined4 *)(param_1[2] + 0x6c4));
        if (iVar14 == 0) goto LAB_0018e934;
        uVar16 = FUN_00105594(param_2,iVar5);
        iVar14 = FUN_0010c47c(uVar16,param_1[2]);
        if (iVar14 == 0) goto LAB_0018e934;
        uVar16 = FUN_00105594(param_2,iVar5);
        uVar16 = FUN_0010cb48(uVar16,param_1[2]);
        FUN_00106004(param_2,iVar5,uVar16,0,param_1[2]);
      }
LAB_0018eb5c: ;
    }
    if (!bVar2) {
      param_2 = piVar6;
    }
  }
  piVar6 = param_2;
  if (((*(int *)(param_2[0x22] + 8) == 0x9e) || (*(int *)(param_2[0x22] + 8) == 0xa0)) &&
     ((iVar5 = FUN_000f31e8(param_2,1), iVar5 == 0 ||
      (((param_2[0x2e] & 1U) != 0 || ((param_2[0x2e] & 2U) != 0)))))) {
    *(int *)(iVar17 + 0x238) = *(int *)(iVar17 + 0x238) + 1;
    piVar6 = (int *)FUN_001043f0(0x31,param_1[2]);
    piVar6[0x26] = 0;
    piVar6[0x25] = piVar6[0x53];
    iVar5 = FUN_001054ec(param_2,0);
    uVar13 = *(undefined4 *)(iVar5 + 0x10);
    iVar5 = FUN_001054ec(piVar6,0);
    *(undefined4 *)(iVar5 + 0x10) = uVar13;
    uVar13 = FUN_00105594(param_2,1);
    FUN_00106004(piVar6,1,uVar13,0,param_1[2]);
    FUN_00103d50(piVar6 + 0x29,2,(uint)param_2[0x2e] >> 1 & 1);
    FUN_00103d50(piVar6 + 0x29,1,param_2[0x2e] & 1);
    iVar5 = FUN_001054ec(param_2,1);
    uVar13 = *(undefined4 *)(iVar5 + 0x10);
    iVar5 = FUN_001054ec(piVar6,1);
    *(undefined4 *)(iVar5 + 0x10) = uVar13;
    FUN_000e7700(iVar15,param_2,piVar6);
    FUN_00106004(param_2,1,piVar6,0,param_1[2]);
    FUN_00103d50(param_2 + 0x29,2,0);
    FUN_00103d50(param_2 + 0x29,1,0);
    uVar21 = DAT_001b2a64;
    iVar5 = FUN_001054ec(param_2,1);
    iVar14 = 0;
    *(uint *)(iVar5 + 0x10) = uVar21;
    do {
      iVar5 = FUN_001054ec(param_2,0);
      if (*(char *)(iVar14 + iVar5 + 0x10) == '\x01') {
        (**(code **)(*param_2 + 0x88))(param_2,1,iVar14,4);
      }
      bVar2 = iVar14 != 3;
      iVar14 = iVar14 + 1;
    } while (bVar2);
    uVar13 = 1;
  }
  iVar14 = 1;
  iVar5 = (**(code **)(*param_1 + 0x88))(param_1,piVar6);
  if (iVar5 == 0) {
    for (; iVar5 = (**(code **)(*piVar6 + 0x14))(piVar6), iVar14 <= iVar5; iVar14 = iVar14 + 1) {
      local_98 = 0;
      (**(code **)(*param_1 + 0x68))(param_1,piVar6,iVar14,local_84,&local_98,param_1[2]);
      if (local_98 != 0) {
        if ((*(int *)(piVar6[0x22] + 8) == 0x31) || (*(int *)(piVar6[0x22] + 8) == 0x30)) {
          *(int *)(iVar17 + 0x238) = *(int *)(iVar17 + 0x238) + 1;
          iVar5 = FUN_001043f0(0x31,param_1[2]);
          FUN_00103f84(iVar5,piVar6);
          uVar21 = local_84[0];
          iVar7 = FUN_001054ec(iVar5,1);
          *(uint *)(iVar7 + 0x10) = uVar21;
          FUN_000f3258(&local_68,local_84[0]);
          *(undefined4 *)(iVar5 + 0x9c) = local_68;
          FUN_000e7700(iVar15,piVar6,iVar5);
          iVar7 = local_98 + -1;
          if (1 < iVar7) {
            iVar20 = 1;
            puVar18 = local_84;
            do {
              puVar18 = puVar18 + 1;
              iVar7 = FUN_001043f0(0x31,param_1[2]);
              FUN_00103f84(iVar7,piVar6);
              uVar21 = *puVar18;
              iVar12 = FUN_001054ec(iVar7,1);
              *(uint *)(iVar12 + 0x10) = uVar21;
              FUN_000f3258(&local_64,*puVar18);
              *(undefined4 *)(iVar7 + 0x9c) = local_64;
              FUN_000e7700(iVar15,piVar6,iVar7);
              if ((piVar6[5] & 2U) == 0) {
                FUN_00106804(iVar7,iVar5,0,param_1[2]);
                iVar5 = iVar7;
              }
              iVar20 = iVar20 + 1;
              *(int *)(iVar17 + 0x238) = *(int *)(iVar17 + 0x238) + 1;
              iVar7 = local_98 + -1;
            } while (iVar20 < iVar7);
          }
          uVar21 = local_84[iVar7];
          iVar7 = FUN_001054ec(piVar6,1);
          *(uint *)(iVar7 + 0x10) = uVar21;
          FUN_000f3258(&local_60,(&local_88)[local_98]);
          piVar6[0x27] = local_60;
          if ((piVar6[5] & 2U) == 0) {
            FUN_00106804(piVar6,iVar5,0,param_1[2]);
          }
        }
        else {
          piVar11 = (int *)FUN_00105594(piVar6,iVar14);
          iVar5 = 0;
          if (0 < local_98) {
            iVar20 = 0;
            puVar18 = local_84;
            iVar7 = iVar5;
            do {
              *(int *)(iVar17 + 0x238) = *(int *)(iVar17 + 0x238) + 1;
              iVar5 = FUN_001043f0(0x31,param_1[2]);
              *(undefined4 *)(iVar5 + 0x98) = 0;
              *(undefined4 *)(iVar5 + 0x94) = *(undefined4 *)(iVar5 + 0x14c);
              FUN_00106004(iVar5,1,piVar11,0,param_1[2]);
              uVar21 = *puVar18;
              iVar12 = FUN_001054ec(iVar5,1);
              *(uint *)(iVar12 + 0x10) = uVar21;
              FUN_000f3258(local_5c,*puVar18);
              *(undefined4 *)(iVar5 + 0x9c) = local_5c[0];
              if (iVar7 == 0) {
                if ((((piVar11[0x20] != 0) && (iVar7 = FUN_00126760(piVar11[0x26]), iVar7 != 0)) &&
                    ((piVar11[5] & 2U) == 0)) &&
                   (iVar7 = (**(code **)(*piVar11 + 0x50))(piVar11), iVar7 == 0)) {
                  iVar12 = 4;
                  bVar2 = false;
                  uVar21 = 0;
                  iVar7 = iVar5;
                  do {
                    if (uVar21 == *(byte *)(uVar21 + (int)local_84)) {
                      *(undefined1 *)(iVar7 + 0x9c) = 1;
                      bVar2 = true;
                    }
                    uVar21 = uVar21 + 1;
                    iVar7 = iVar7 + 1;
                    iVar12 = iVar12 + -1;
                  } while (iVar12 != 0);
                  if (bVar2) {
                    FUN_00106804(iVar5,piVar11,0,param_1[2]);
                  }
                }
              }
              else {
                FUN_00106804(iVar5,iVar7,0,param_1[2]);
              }
              iVar7 = FUN_001054ec(iVar5,0);
              if (*(int *)(iVar7 + 0x10) == DAT_001b2a80) {
                iVar5 = FUN_00105594(iVar5,*(undefined4 *)(iVar5 + 0x84));
              }
              else {
                FUN_000e7700(iVar15,piVar6,iVar5);
              }
              iVar20 = iVar20 + 1;
              puVar18 = puVar18 + 1;
              iVar7 = iVar5;
            } while (iVar20 < local_98);
          }
          FUN_00106004(piVar6,iVar14,iVar5,0,param_1[2]);
        }
      }
    }
    uVar13 = 1;
  }
  iVar17 = 1;
  iVar5 = ((int (*)())FUN_0018da48)(piVar6,param_1[2]);
  if (iVar5 == 0) {
    for (; iVar5 = (**(code **)(*piVar6 + 0x14))(piVar6), iVar17 <= iVar5; iVar17 = iVar17 + 1) {
      piVar11 = (int *)FUN_00105594(piVar6,iVar17);
      iVar5 = (**(code **)(*piVar11 + 0x60))();
      if (iVar5 != 0) {
        piVar11 = (int *)FUN_00105594(piVar11,1);
      }
      iVar5 = (**(code **)(*piVar11 + 0x5c))(piVar11);
      if (iVar5 != 0) {
        uVar13 = FUN_00105594(piVar11,1);
        iVar5 = FUN_001054ec(piVar11,0);
        iVar14 = *(int *)(iVar5 + 0x10);
        iVar5 = FUN_001054ec(piVar11,1);
        uVar19 = *(undefined4 *)(iVar5 + 0x10);
        uVar16 = 0;
        iVar5 = (**(code **)(*piVar11 + 0x14))(piVar11);
        if (1 < iVar5) {
          uVar16 = FUN_00105594(piVar11,2);
          iVar5 = FUN_001054ec(piVar11,2);
          iVar15 = *(int *)(iVar5 + 0x10);
        }
        iVar5 = piVar11[1];
        iVar7 = *(int *)(piVar11[0x22] + 8);
        ((int (*)())FUN_0019401c)(piVar11);
        if (iVar7 != 0x99) {
          FUN_00108174(piVar11,0x12,param_1[2]);
        }
        else {
          FUN_00108304(piVar11,0x14,param_1[2]);
        }
        iVar12 = piVar11[0x53];
        iVar20 = FUN_001054ec(piVar11,0);
        *(undefined4 *)(iVar20 + 0xc) = 0;
        *(int *)(iVar20 + 8) = iVar12;
        piVar11[0x27] = iVar14;
        FUN_00106004(piVar11,1,uVar13,0,param_1[2]);
        iVar14 = FUN_001054ec(piVar11,1);
        *(undefined4 *)(iVar14 + 0x10) = uVar19;
        if (iVar7 != 0x99) {
          if (iVar7 == 0x9c) {
            dVar22 = (double)FLOAT_001aa0e8;
            FUN_000f79c4(dVar22,dVar22,dVar22,dVar22,piVar11,*(undefined4 *)(param_1[2] + 0x6c4),2);
            FUN_00103d50(piVar11 + 0x29,1,1);
          }
          else {
            FUN_00106004(piVar11,2,uVar16,0,param_1[2]);
            iVar14 = FUN_001054ec(piVar11,2);
            *(int *)(iVar14 + 0x10) = iVar15;
            FUN_00103d50(piVar11 + 0x2f,1,iVar7 == 0x9a);
          }
        }
        else {
          FUN_00103d50(piVar11 + 0x29,1,1);
          dVar22 = (double)FLOAT_001aa0e8;
          FUN_000f79c4(dVar22,dVar22,dVar22,dVar22,piVar11,*(undefined4 *)(param_1[2] + 0x6c4),2);
          dVar22 = (double)FLOAT_001aa10c;
          FUN_000f79c4(dVar22,dVar22,dVar22,dVar22,piVar11,*(undefined4 *)(param_1[2] + 0x6c4),3);
          piVar11[0x49] = 1;
        }
        FUN_000e7738(*(undefined4 *)(iVar5 + 0x158),iVar5,piVar11);
        iVar5 = ((int (*)())FUN_0018da48)(piVar6,param_1[2]);
        if (iVar5 != 0) break;
      }
    }
    uVar13 = 1;
  }
  return uVar13;
}

/* FUN_0018f42c @ 0x18f42c (304 bytes) */
int FUN_0018f42c(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_38;
  undefined4 local_34;
  
  if ((param_2[5] & 0x8000U) == 0) {
    iVar1 = (**(code **)(*param_2 + 0x28))(param_2);
    if (iVar1 == 0) {
      FUN_00189df4(param_2,param_1 + 0x18,param_1 + 0x20);
      ((int (*)())FUN_0018d4b4)(param_2,param_1 + 0x1c,param_1 + 0x24,param_1 + 0x28,*(undefined4 *)(param_1 + 8)
                  );
      FUN_0018c768(param_1 + 0x28,&local_38);
      uVar2 = 0;
      if (*(int *)(param_1 + 100) != 0) {
        FUN_00189840(param_1,*(int *)(param_1 + 100),param_2,local_38,local_34);
        uVar2 = *(undefined4 *)(param_1 + 100);
      }
      FUN_001899ac(param_1,uVar2,param_2,local_38,local_34);
      if (*(int *)(param_1 + 100) == 0) {
        *(int **)(param_1 + 100) = param_2;
      }
      if (*(int *)(param_1 + 0x18) < 0) {
        if (*(int *)(param_1 + 0x20) < 0) {
          *(undefined4 *)(param_1 + 4) = 0;
        }
        else {
          *(undefined4 *)(param_1 + 4) = 2;
        }
      }
      else if (*(int *)(param_1 + 0x20) < 0) {
        *(undefined4 *)(param_1 + 4) = 1;
      }
      else {
        *(undefined4 *)(param_1 + 4) = 3;
      }
    }
    else {
      *(undefined4 *)(param_1 + 4) = 4;
    }
  }
  return;
}

/* FUN_0018f55c @ 0x18f55c (280 bytes) */
int FUN_0018f55c(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 auStack_60 [80];
  
  if ((param_2[5] & 0x8000U) == 0) {
    iVar1 = (**(code **)(*param_2 + 0x28))(param_2);
    if (iVar1 != 0) {
      return *(int *)(param_1 + 4) == 0;
    }
    local_78 = *(undefined4 *)(param_1 + 0x18);
    local_74 = *(undefined4 *)(param_1 + 0x1c);
    local_70 = *(undefined4 *)(param_1 + 0x20);
    local_6c = *(undefined4 *)(param_1 + 0x24);
    FUN_001895a0(auStack_60,param_1 + 0x28);
    iVar1 = FUN_00189df4(param_2,&local_78,&local_70);
    if ((((iVar1 == 0) ||
         (iVar1 = ((int (*)())FUN_0018d4b4)(param_2,&local_74,&local_6c,auStack_60,*(undefined4 *)(param_1 + 8)),
         iVar1 == 0)) || (iVar1 = FUN_0018c768(auStack_60,&local_68), iVar1 == 0)) ||
       ((*(int *)(param_1 + 100) != 0 &&
        (iVar1 = FUN_00189840(param_1,*(int *)(param_1 + 100),param_2,local_68,local_64), iVar1 == 0
        )))) {
      return false;
    }
  }
  return true;
}

/* FUN_0018f674 @ 0x18f674 (432 bytes) */
int FUN_0018f674(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (((((((param_2[0x20] != 0) && (iVar2 = FUN_00126760(param_2[0x26]), iVar2 != 0)) &&
         ((param_2[5] & 2U) == 0)) &&
        ((iVar2 = (**(code **)(*param_2 + 0x50))(param_2), iVar2 == 0 &&
         (uVar1 = param_2[5], (uVar1 & 0x20) == 0)))) &&
       (((uVar1 & 0x40) == 0 &&
        (((uVar1 & 2) == 0 && (iVar2 = (**(code **)(*param_2 + 0x5c))(param_2), iVar2 == 0)))))) &&
      (iVar2 = (**(code **)(*param_2 + 0x28))(param_2), iVar2 == 0)) &&
     ((((iVar2 = *(int *)(param_2[0x22] + 8), iVar2 != 0x9e && (iVar2 != 0xa0)) && (iVar2 != 0x9f))
      && (((iVar2 != 0xa1 && (iVar2 = *(int *)(PTR_DAT_001e913c + iVar2 * 0x38 + 0x34), iVar2 != 3))
          && (iVar2 != 8)))))) {
    iVar3 = FUN_001054ec(param_2,0);
    if (*(char *)(iVar3 + 0x13) == '\0') {
      if ((iVar2 != 5) &&
         ((iVar2 != 0 ||
          ((iVar2 = FUN_000f3a30(param_2), iVar2 != 4 &&
           ((iVar2 < 2 || ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x400) != 0))))
          )))) {
        return 1;
      }
    }
    else if ((*(char *)(iVar3 + 0x13) == '\x01') && (1 < iVar2 - 1U)) {
      if (iVar2 == 5) {
        return 1;
      }
      iVar2 = FUN_000f3a30(param_2);
      if (iVar2 < 2) {
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_0018f824 @ 0x18f824 (44 bytes) */
int FUN_0018f824(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x28) = 4;
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = 4;
  *(undefined4 *)(param_1 + 0x24) = 4;
  *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x30) = 0xffffffff;
  return;
}

/* FUN_0018f850 @ 0x18f850 (200 bytes) */
int FUN_0018f850(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  int *param_3;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_2[1];
  if (*param_2 == iVar2) {
    iVar3 = *param_3;
    bVar1 = iVar3 != param_3[1];
    if ((bVar1) && (iVar2 != 0)) {
      return 0;
    }
    if (iVar2 == param_2[2]) {
      if (iVar2 == 0) {
        if ((((param_4 == 0) && (bVar1)) && (iVar3 != param_3[2])) && (param_3[1] != param_3[2])) {
          return 0;
        }
      }
      else {
        if (bVar1) {
          return 0;
        }
        if (iVar3 != param_3[2]) {
          return 0;
        }
      }
    }
  }
  else {
    iVar3 = param_2[2];
    if (*param_2 == iVar3) {
      if (*param_3 == param_3[2]) {
        return 1;
      }
    }
    else {
      if (iVar2 != iVar3) {
        return 1;
      }
      iVar3 = iVar2;
      if (param_3[1] == param_3[2]) {
        return 1;
      }
    }
    if (iVar3 != 0) {
      return 0;
    }
  }
  return 1;
}

/* FUN_0018f918 @ 0x18f918 (108 bytes) */
int FUN_0018f918(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x30))(param_1,*(undefined4 *)(param_2 + 0x38));
  if ((iVar1 == 0) ||
     ((*(int *)(param_2 + 0x60) != 0 && (*(int *)(*(int *)(param_2 + 0x60) + 8) != 0)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_0018f984 @ 0x18f984 (596 bytes) */
int FUN_0018f984(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  iVar9 = *(int *)(param_2 + 900);
  iVar2 = *(int *)(iVar9 + 8);
  do {
    if (iVar2 == 0) {
      return;
    }
    iVar2 = *(int *)(iVar9 + 0x98);
    for (iVar3 = *(int *)(*(int *)(iVar9 + 0x98) + 8); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
      if ((*(uint *)(iVar2 + 0x14) & 1) != 0) {
        iVar3 = *(int *)(iVar2 + 0x88);
        if (*(int *)(iVar3 + 8) != 0x8e) {
          (**(code **)(*param_1 + 0x6c))(param_1,iVar2);
          iVar3 = *(int *)(iVar2 + 0x88);
        }
        if ((*(int *)(iVar3 + 8) == 0x31) || (*(int *)(iVar3 + 8) == 0x30)) {
          piVar5 = (int *)FUN_00105594(iVar2,1);
          iVar3 = (**(code **)(*piVar5 + 0x50))();
          if (iVar3 != 0) {
            iVar3 = *(int *)(iVar2 + 8);
            *(undefined4 *)(iVar2 + 0x9c) = DAT_001b2a84;
            goto LAB_0018fa5c;
          }
        }
        iVar3 = *(int *)(iVar2 + 8);
      }
LAB_0018fa5c:
      iVar2 = iVar3;
    }
    piVar5 = *(int **)(iVar9 + 0xa0);
    for (piVar4 = (int *)(*(int **)(iVar9 + 0xa0))[1]; piVar4 != (int *)0x0;
        piVar4 = (int *)piVar4[1]) {
      if ((piVar5[5] & 1U) != 0) {
        iVar2 = piVar5[0x22];
        if ((*(int *)(iVar2 + 8) == 0x31) || (*(int *)(iVar2 + 8) == 0x13)) {
          iVar2 = (**(code **)(*param_1 + 0x30))(param_1,piVar5);
          if (iVar2 == 0) {
            iVar2 = piVar5[0x22];
          }
          else {
            uVar8 = 0xffffffff;
            uVar7 = 0xffffffff;
            iVar3 = 0;
            iVar2 = (**(code **)(*piVar5 + 0x14))(piVar5);
            do {
              iVar6 = FUN_001054ec(piVar5,0);
              if (*(char *)(iVar3 + iVar6 + 0x10) != '\x01') {
                iVar6 = FUN_001054ec(piVar5,1);
                uVar8 = (uint)*(byte *)(iVar3 + iVar6 + 0x10);
                if (iVar2 == 2) {
                  iVar6 = FUN_001054ec(piVar5,2);
                  uVar7 = (uint)*(byte *)(iVar3 + iVar6 + 0x10);
                }
              }
              bVar1 = iVar3 != 3;
              iVar3 = iVar3 + 1;
            } while (bVar1);
            FUN_0010bb9c(piVar5,uVar8,uVar7,0,0,param_1[2]);
            iVar2 = piVar5[0x22];
          }
        }
        iVar2 = FUN_00113090(*(undefined4 *)(iVar2 + 8),param_1[2]);
        if ((iVar2 == 0) || (piVar5[0x26] != 0)) {
          piVar4 = (int *)piVar5[1];
        }
        else {
          piVar4 = (int *)piVar5[1];
          piVar5[0x26] = 1;
        }
      }
      piVar5 = piVar4;
    }
    iVar9 = *(int *)(iVar9 + 8);
    iVar2 = *(int *)(iVar9 + 8);
  } while( true );
}

/* FUN_0018fbd8 @ 0x18fbd8 (348 bytes) */
int FUN_0018fbd8(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  
  (**(code **)(*param_1 + 0x34))();
  piVar8 = *(int **)(param_2 + 0x38);
  iVar2 = *(int *)(piVar8[0x22] + 8);
  if ((iVar2 == 0x66) || (iVar2 == 0x36)) {
    FUN_0010bc78(piVar8,param_1[2]);
    piVar8[0x26] = 0;
  }
  else if ((iVar2 == 0x31) || (*(int *)(piVar8[0x22] + 8) == 0x13)) {
    uVar6 = 0xffffffff;
    uVar5 = 0xffffffff;
    iVar7 = 0;
    iVar2 = (**(code **)(*piVar8 + 0x14))(piVar8);
    do {
      iVar3 = FUN_001054ec(piVar8,0);
      if (*(char *)(iVar7 + iVar3 + 0x10) != '\x01') {
        iVar3 = FUN_001054ec(piVar8,1);
        uVar6 = (uint)*(byte *)(iVar7 + iVar3 + 0x10);
        if (iVar2 == 2) {
          iVar3 = FUN_001054ec(piVar8,2);
          uVar5 = (uint)*(byte *)(iVar7 + iVar3 + 0x10);
        }
      }
      bVar1 = iVar7 != 3;
      iVar7 = iVar7 + 1;
    } while (bVar1);
    FUN_0010bb9c(piVar8,uVar6,uVar5,0,0,param_1[2]);
    piVar8[0x26] = 1;
  }
  uVar4 = (**(code **)(*param_1 + 0x4c))(param_1,piVar8);
  *(undefined4 *)(param_2 + 0x58) = uVar4;
  return;
}

/* FUN_0018fd34 @ 0x18fd34 (972 bytes) */
int FUN_0018fd34(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint *puVar16;
  int *piVar17;
  
  piVar17 = *(int **)(param_2 + 0x38);
  if (((((*(int *)(param_2 + 0x60) == 0) && (piVar17[0x20] != 0)) &&
       (iVar5 = FUN_00126760(piVar17[0x26]), iVar5 != 0)) &&
      (((piVar17[5] & 2U) == 0 && (iVar5 = (**(code **)(*piVar17 + 0x50))(piVar17), iVar5 == 0))))
     && ((uVar4 = piVar17[5], (uVar4 & 0x20) == 0 && (((uVar4 & 0x40) == 0 && ((uVar4 & 2) == 0)))))
     ) {
    iVar5 = *(int *)(PTR_DAT_001e9140 + *(int *)(piVar17[0x22] + 8) * 0x38 + 0x34);
    if ((iVar5 == 0) ||
       ((((iVar5 == 5 || (iVar5 == 1)) || (iVar5 == 2)) || ((iVar5 == 3 || (iVar5 == 8)))))) {
      bVar2 = false;
      iVar15 = 0;
      iVar13 = -1;
      do {
        iVar6 = FUN_001054ec(piVar17,0);
        iVar7 = iVar13;
        if ((*(char *)(iVar15 + iVar6 + 0x10) == '\0') && (iVar7 = iVar15, -1 < iVar13)) {
          iVar7 = FUN_00113090(*(undefined4 *)(piVar17[0x22] + 8),param_1[2]);
          if (iVar7 == 0) {
            return;
          }
          bVar2 = true;
          iVar7 = iVar13;
        }
        bVar1 = iVar15 != 3;
        iVar15 = iVar15 + 1;
        iVar13 = iVar7;
      } while (bVar1);
      iVar13 = param_1[0xe];
      param_1[0xe] = iVar13 + 1;
      if (3 < iVar13 + 1) {
        param_1[0xe] = 0;
      }
      if ((iVar13 != iVar7) || (bVar2)) {
        iVar6 = 4;
        iVar15 = param_2;
        do {
          *(undefined4 *)(iVar15 + 0x48) = 0;
          iVar15 = iVar15 + 4;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        puVar16 = *(uint **)(param_2 + 0x40);
        uVar14 = 0;
        uVar4 = puVar16[1];
        if (0 < (int)uVar4) {
          while( true ) {
            if (uVar14 < *puVar16) {
              uVar8 = puVar16[1];
              if (uVar8 <= uVar14) {
                _memset((void *)(uVar8 * 4 + puVar16[2]),0,(uVar14 - uVar8) * 4 + 4);
                puVar16[1] = uVar14 + 1;
              }
              piVar9 = (int *)(uVar14 * 4 + puVar16[2]);
            }
            else {
              piVar9 = (int *)((int (*)())FUN_0019423c)(puVar16,uVar14);
            }
            uVar14 = uVar14 + 1;
            iVar15 = *piVar9;
            if (*(int *)(iVar15 + 8) == 0) {
              *(undefined4 *)(iVar15 + 0x18) = 0;
              *(undefined1 *)(iVar13 + iVar15 + 0x18) = 1;
              iVar6 = iVar13 * 4 + param_2;
              *(int *)(iVar6 + 0x48) = *(int *)(iVar6 + 0x48) + 1;
              piVar9 = *(int **)(*(int *)(iVar15 + 4) + 0x38);
              for (iVar15 = 1; iVar6 = (**(code **)(*piVar9 + 0x14))(piVar9), iVar15 <= iVar6;
                  iVar15 = iVar15 + 1) {
                piVar10 = (int *)FUN_00105594(piVar9,iVar15);
                if (piVar17 == piVar10) {
                  iVar6 = 0;
                  do {
                    iVar11 = FUN_001054ec(piVar9,iVar15);
                    if (*(char *)(iVar6 + iVar11 + 0x10) != '\x04') {
                      (**(code **)(*piVar9 + 0x88))(piVar9,iVar15,iVar6,iVar13);
                    }
                    bVar2 = iVar6 != 3;
                    iVar6 = iVar6 + 1;
                  } while (bVar2);
                }
              }
            }
            if (uVar4 == uVar14) break;
            puVar16 = *(uint **)(param_2 + 0x40);
          }
        }
        piVar17[0x27] = DAT_001b2a84;
        *(undefined1 *)((int)piVar17 + iVar13 + 0x9c) = 0;
        piVar17[3] = 0;
        *(undefined1 *)((int)piVar17 + iVar13 + 0xc) = 1;
        if (iVar5 == 0) {
          for (iVar5 = 1; iVar13 = (**(code **)(*piVar17 + 0x14))(piVar17), iVar5 <= iVar13;
              iVar5 = iVar5 + 1) {
            iVar13 = FUN_001054ec(piVar17,iVar5);
            iVar15 = 0;
            uVar3 = *(undefined1 *)(iVar7 + iVar13 + 0x10);
            do {
              (**(code **)(*piVar17 + 0x88))(piVar17,iVar5,iVar15,uVar3);
              bVar2 = iVar15 != 3;
              iVar15 = iVar15 + 1;
            } while (bVar2);
          }
        }
        uVar12 = (**(code **)(*param_1 + 0x4c))(param_1,piVar17);
        *(undefined4 *)(param_2 + 0x58) = uVar12;
      }
    }
  }
  return;
}

/* FUN_00190100 @ 0x190100 (728 bytes) */
int FUN_00190100(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 *param_4;
  int *param_5;
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar1 = (int *)FUN_00105594(param_2,param_3);
  iVar2 = (**(code **)(*piVar1 + 0x60))();
  if (iVar2 != 0) {
    piVar1 = (int *)FUN_00105594(piVar1,1);
  }
  switch(piVar1[0x26]) {
  case 0:
    if ((piVar1[5] & 0x40U) == 0) {
      *param_5 = piVar1[0x25] + 0x80;
    }
    else {
      *param_5 = piVar1[0x25];
    }
    uVar3 = 1;
    *param_4 = 0;
    break;
  case 1:
    if ((piVar1[5] & 0x40U) == 0) {
      *param_5 = piVar1[0x25] + 0x80;
    }
    else {
      *param_5 = piVar1[0x25];
    }
    uVar3 = 1;
    *param_4 = 3;
    break;
  case 2:
    uVar3 = 1;
    *param_5 = piVar1[0x25];
    *param_4 = 2;
    break;
  default:
    uVar3 = 0;
    break;
  case 0xc:
    uVar3 = 1;
    *param_5 = piVar1[0x25] + 0x700;
    *param_4 = 2;
    break;
  case 0x26:
    iVar2 = FUN_00105594(piVar1,1);
    *param_5 = *(int *)(iVar2 + 0x14c) << 10;
    iVar2 = FUN_001054ec(piVar1,1);
    iVar2 = FUN_000f2d18(*(undefined4 *)(iVar2 + 0x10),DAT_001b2a98);
    if (iVar2 == 0) {
      iVar2 = FUN_001054ec(piVar1,1);
      iVar2 = FUN_000f2d18(*(undefined4 *)(iVar2 + 0x10),DAT_001b2a94);
      if (iVar2 == 0) {
        iVar2 = FUN_001054ec(piVar1,1);
        iVar2 = FUN_000f2d18(*(undefined4 *)(iVar2 + 0x10),DAT_001b2a90);
        if (iVar2 == 0) {
          iVar2 = FUN_001054ec(piVar1,1);
          iVar2 = FUN_000f2d18(*(undefined4 *)(iVar2 + 0x10),DAT_001b2a8c);
          if (iVar2 != 0) {
            iVar4 = *param_5;
            iVar2 = FUN_00105c5c(piVar1,0);
            *param_5 = iVar4 + iVar2 + 0x400;
          }
        }
        else {
          iVar4 = *param_5;
          iVar2 = FUN_00105c5c(piVar1,0);
          *param_5 = iVar4 + iVar2 + 0x300;
        }
      }
      else {
        iVar4 = *param_5;
        iVar2 = FUN_00105c5c(piVar1,0);
        *param_5 = iVar4 + iVar2 + 0x200;
      }
    }
    else {
      iVar4 = *param_5;
      iVar2 = FUN_00105c5c(piVar1,0);
      *param_5 = iVar4 + iVar2 + 0x100;
    }
    uVar3 = 1;
    *param_4 = 2;
    break;
  case 0x28:
    iVar2 = FUN_00105c5c(param_2,param_3);
    uVar3 = 1;
    *param_5 = iVar2 + 0x500;
    *param_4 = 2;
    break;
  case 0x29:
    iVar2 = FUN_00105c5c(param_2,param_3);
    uVar3 = 1;
    *param_5 = iVar2 + 0x600;
    *param_4 = 1;
    break;
  case 0x37:
    uVar3 = 1;
    *param_5 = piVar1[0x25];
    *param_4 = 1;
  }
  return uVar3;
}

/* FUN_001904b8 @ 0x1904b8 (528 bytes) */
int FUN_001904b8(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  
  iVar1 = (**(code **)(*param_1 + 0x4c))();
  if (iVar1 == 0) {
    return;
  }
  if (iVar1 == 3) {
    param_1[7] = *(int *)(param_2[0x22] + 8);
    param_1[6] = *(int *)(param_2[0x22] + 8);
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar1 < 1) {
      return;
    }
    ((int (*)())FUN_00190100)(param_1,param_2,1,param_1 + 8,param_1 + 0xb);
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar1 < 2) {
      return;
    }
    ((int (*)())FUN_00190100)(param_1,param_2,2,param_1 + 9,param_1 + 0xc);
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar1 < 3) {
      return;
    }
    uVar2 = 3;
  }
  else {
    if (iVar1 != 2) {
      param_1[6] = *(int *)(param_2[0x22] + 8);
      if (param_2[0x26] == 1) {
        param_1[7] = *(int *)(param_2[0x22] + 8);
      }
      iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
      if (iVar1 < 1) {
        return;
      }
      ((int (*)())FUN_00190100)(param_1,param_2,1,param_1 + 8,param_1 + 0xb);
      iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
      if (iVar1 < 2) {
        return;
      }
      uVar2 = 2;
      piVar3 = param_1 + 9;
      piVar4 = param_1 + 0xc;
      goto LAB_0019060c;
    }
    param_1[7] = *(int *)(param_2[0x22] + 8);
    if (param_2[0x26] != 1) {
      param_1[6] = *(int *)(param_2[0x22] + 8);
    }
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar1 < 1) {
      return;
    }
    uVar2 = 1;
  }
  piVar3 = param_1 + 10;
  piVar4 = param_1 + 0xd;
LAB_0019060c:
  ((int (*)())FUN_00190100)(param_1,param_2,uVar2,piVar3,piVar4);
  return;
}

/* FUN_001906c8 @ 0x1906c8 (712 bytes) */
int FUN_001906c8(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  undefined4 uVar2;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24 [5];
  
  local_38 = param_1[8];
  local_34 = param_1[9];
  local_30 = param_1[10];
  local_2c = param_1[0xb];
  local_28 = param_1[0xc];
  local_24[0] = param_1[0xd];
  iVar1 = (**(code **)(*param_1 + 0x4c))();
  if (iVar1 == 0) {
LAB_0019092c:
    uVar2 = 1;
  }
  else {
    if (iVar1 == 3) {
      if ((param_1[7] < 0) && (param_1[6] < 0)) {
        iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
        if (0 < iVar1) {
          ((int (*)())FUN_00190100)(param_1,param_2,1,&local_38,&local_2c);
          iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
          if (1 < iVar1) {
            ((int (*)())FUN_00190100)(param_1,param_2,2,&local_34,&local_28);
            iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
            if (2 < iVar1) {
              ((int (*)())FUN_00190100)(param_1,param_2,3,&local_30,local_24);
            }
          }
          iVar1 = ((int (*)())FUN_0018f850)(param_1,&local_38,&local_2c,*(int *)(param_2[0x22] + 8) == 0x14);
          goto joined_r0x00190928;
        }
        goto LAB_0019092c;
      }
    }
    else if (iVar1 == 2) {
      if ((param_1[7] < 0) && ((param_1[6] < 0 || (param_2[0x26] == 1)))) {
        iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
        if (0 < iVar1) {
          ((int (*)())FUN_00190100)(param_1,param_2,1,&local_30,local_24);
          iVar1 = ((int (*)())FUN_0018f850)(param_1,&local_38,&local_2c,0);
joined_r0x00190928:
          if (iVar1 == 0) goto LAB_00190854;
        }
        goto LAB_0019092c;
      }
    }
    else if ((param_1[6] < 0) && ((param_1[7] < 0 || (param_2[0x26] != 1)))) {
      iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
      if (0 < iVar1) {
        ((int (*)())FUN_00190100)(param_1,param_2,1,&local_38,&local_2c);
        iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
        if (1 < iVar1) {
          ((int (*)())FUN_00190100)(param_1,param_2,2,&local_34,&local_28);
        }
        iVar1 = ((int (*)())FUN_0018f850)(param_1,&local_38,&local_2c,0);
        goto joined_r0x00190928;
      }
      goto LAB_0019092c;
    }
LAB_00190854:
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_00190990 @ 0x190990 (2308 bytes) */
int FUN_00190990(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int *piVar14;
  double dVar15;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  uint local_98;
  uint local_94;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  undefined4 local_5c;
  uint local_58;
  undefined4 local_54;
  uint local_50;
  undefined4 local_4c [6];
  
  uVar12 = 0;
  iVar13 = param_2[0x56];
  iVar11 = *(int *)(*(int *)(param_1 + 8) + 0x6c4);
  (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0x80))();
  iVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0x88))();
  if (iVar1 == 0) {
    piVar14 = param_2 + 0x26;
    for (iVar1 = 1; iVar2 = (**(code **)(*param_2 + 0x14))(param_2), iVar1 <= iVar2;
        iVar1 = iVar1 + 1) {
      if ((piVar14[8] & 2U) != 0) {
        iVar2 = FUN_00113258(*(undefined4 *)(param_2[0x22] + 8),*(undefined4 *)(param_1 + 8));
        if (iVar2 == 0) {
          uVar4 = FUN_00105594(param_2,iVar1);
          iVar2 = FUN_001043f0(0x17,*(undefined4 *)(param_1 + 8));
          *(undefined4 *)(iVar2 + 0x98) = 0;
          *(undefined4 *)(iVar2 + 0x94) = *(undefined4 *)(iVar2 + 0x14c);
          iVar5 = FUN_001054ec(param_2,iVar1);
          FUN_000f3398(&local_68,*(undefined4 *)(iVar5 + 0x10));
          uVar12 = local_68;
          FUN_000f31f8(&local_64,DAT_001b2a88,local_68);
          *(undefined4 *)(iVar2 + 0xc) = uVar12;
          *(undefined4 *)(iVar2 + 0x9c) = local_64;
          FUN_00103d50(iVar2 + 0xa4,1,0);
          FUN_00103d50(iVar2 + 0xbc,1,1);
          FUN_00106004(iVar2,1,uVar4,0,*(undefined4 *)(param_1 + 8));
          FUN_00106004(iVar2,2,uVar4,0,*(undefined4 *)(param_1 + 8));
          iVar2 = FUN_00165604(iVar13,iVar2);
          if (*(int *)(iVar2 + 0x158) == 0) {
            *(int *)(iVar11 + 0x238) = *(int *)(iVar11 + 0x238) + 1;
            FUN_000e7700(iVar13,param_2,iVar2);
          }
          FUN_00106004(param_2,iVar1,iVar2,0,*(undefined4 *)(param_1 + 8));
        }
        uVar12 = 1;
        FUN_00103d50(piVar14 + 3,2,0);
      }
      piVar14 = piVar14 + 6;
    }
  }
  uVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0x84))();
  if ((uVar3 == 0) && (*(int *)(param_2[0x22] + 8) == 0x25)) {
    local_98 = uVar3;
    local_94 = uVar3;
    local_84 = uVar3;
    local_80 = uVar3;
    local_7c = uVar3;
    local_6c = uVar3;
    uVar4 = FUN_001054ec(param_2,2);
    FUN_00104730(&local_80,uVar4);
    uVar4 = FUN_001054ec(param_2,3);
    FUN_00104730(&local_98,uVar4);
    iVar1 = FUN_001043f0(0x29,*(undefined4 *)(param_1 + 8));
    *(undefined4 *)(iVar1 + 0x98) = 0;
    *(undefined4 *)(iVar1 + 0x94) = *(undefined4 *)(iVar1 + 0x14c);
    iVar2 = FUN_001054ec(param_2,1);
    FUN_000f3398(&local_60,*(undefined4 *)(iVar2 + 0x10));
    FUN_000f31f8(&local_5c,DAT_001b2a88,local_60);
    *(undefined4 *)(iVar1 + 0x9c) = local_5c;
    *(int *)(iVar1 + 0xc) = local_60;
    FUN_00105e54(iVar1,1,param_2,1);
    dVar15 = (double)FLOAT_001aa0d4;
    FUN_000f79c4(dVar15,dVar15,dVar15,dVar15,iVar1,iVar11,2);
    *(int *)(iVar1 + 0x160) = *(int *)(iVar11 + 0x478) + 2;
    FUN_000e7700(iVar13,param_2,iVar1);
    iVar2 = FUN_001043f0(0x12,*(undefined4 *)(param_1 + 8));
    *(undefined4 *)(iVar2 + 0x98) = 0;
    *(undefined4 *)(iVar2 + 0x94) = *(undefined4 *)(iVar2 + 0x14c);
    iVar5 = FUN_001054ec(iVar1,0);
    uVar4 = *(undefined4 *)(iVar5 + 0x10);
    *(int *)(iVar2 + 0xc) = local_60;
    *(undefined4 *)(iVar2 + 0x9c) = uVar4;
    FUN_00106004(iVar2,1,iVar1,0,*(undefined4 *)(param_1 + 8));
    FUN_00103d50(iVar2 + 0xa4,1,1);
    dVar15 = (double)FLOAT_001aa0e8;
    FUN_000f79c4(dVar15,dVar15,dVar15,dVar15,iVar2,iVar11,2);
    *(int *)(iVar2 + 0x160) = *(int *)(iVar11 + 0x478) + 1;
    FUN_000e7700(iVar13,param_2,iVar2);
    iVar5 = FUN_001043f0(0x13,*(undefined4 *)(param_1 + 8));
    *(undefined4 *)(iVar5 + 0x98) = 0;
    *(undefined4 *)(iVar5 + 0x94) = *(undefined4 *)(iVar5 + 0x14c);
    iVar6 = FUN_001054ec(iVar1,0);
    uVar4 = *(undefined4 *)(iVar6 + 0x10);
    *(int *)(iVar5 + 0xc) = local_60;
    *(undefined4 *)(iVar5 + 0x9c) = uVar4;
    FUN_00106004(iVar5,1,iVar1,0,*(undefined4 *)(param_1 + 8));
    uVar4 = FUN_001054ec(iVar5,2);
    FUN_00104730(uVar4,&local_80);
    *(int *)(iVar5 + 0x160) = *(int *)(iVar11 + 0x478) + 1;
    FUN_000e7700(iVar13,param_2,iVar5);
    iVar6 = param_2[0x58] - *(int *)(iVar11 + 0x478);
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    ((int (*)())FUN_0019401c)(param_2);
    FUN_00108304(param_2,0x14,*(undefined4 *)(iVar11 + 8));
    param_2[0x26] = 0;
    param_2[0x25] = param_2[0x53];
    iVar1 = FUN_001054ec(iVar1,0);
    iVar1 = *(int *)(iVar1 + 0x10);
    param_2[3] = local_60;
    param_2[0x27] = iVar1;
    FUN_00106004(param_2,1,iVar2,0,*(undefined4 *)(param_1 + 8));
    uVar4 = FUN_001054ec(param_2,2);
    FUN_00104730(uVar4,&local_98);
    FUN_00106004(param_2,3,iVar5,0,*(undefined4 *)(param_1 + 8));
    param_2[0x58] = iVar6 + *(int *)(iVar11 + 0x478);
    FUN_000e7738(iVar13,iVar5,param_2);
  }
  iVar5 = 1;
  iVar1 = -1;
  iVar2 = -1;
  do {
    iVar6 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar6 < iVar5) {
      return uVar12;
    }
    uVar4 = FUN_00105594(param_2,iVar5);
    iVar7 = ((int (*)())FUN_00190100)(param_1,param_2,iVar5,&local_a8,&local_a4);
    iVar6 = iVar1;
    iVar8 = iVar2;
    if (iVar7 != 0) {
      if (local_a8 == 2) {
        iVar8 = local_a4;
        if ((iVar2 < 0) || (iVar2 == local_a4)) goto LAB_0019125c;
        iVar8 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        *(undefined4 *)(iVar8 + 0x98) = 0;
        *(undefined4 *)(iVar8 + 0x94) = *(undefined4 *)(iVar8 + 0x14c);
        FUN_00106004(iVar8,1,uVar4,0,*(undefined4 *)(param_1 + 8));
        local_98 = 0;
        for (iVar7 = 1; iVar9 = (**(code **)(*param_2 + 0x14))(param_2), iVar7 <= iVar9;
            iVar7 = iVar7 + 1) {
          iVar9 = ((int (*)())FUN_00190100)(param_1,param_2,iVar7,&local_a0,&local_9c);
          if (((iVar9 != 0) && (local_a0 == local_a8)) && (local_9c == local_a4)) {
            iVar9 = FUN_001054ec(param_2,iVar7);
            FUN_000f3398(&local_58,*(undefined4 *)(iVar9 + 0x10));
            local_98 = local_58 | local_98;
            FUN_00106004(param_2,iVar7,iVar8,0,*(undefined4 *)(param_1 + 8));
          }
        }
        iVar9 = 1;
        FUN_000f31f8(&local_54,DAT_001b2a88,local_98);
        *(undefined4 *)(iVar8 + 0x9c) = local_54;
        *(uint *)(iVar8 + 0xc) = local_98;
        iVar7 = FUN_00165604(iVar13,iVar8);
        if (*(int *)(iVar7 + 0x158) == 0) {
          uVar12 = 1;
          *(int *)(iVar11 + 0x238) = *(int *)(iVar11 + 0x238) + 1;
          FUN_000e7700(iVar13,param_2,iVar7);
        }
        else {
          for (; iVar10 = (**(code **)(*param_2 + 0x14))(param_2), iVar9 <= iVar10;
              iVar9 = iVar9 + 1) {
            iVar10 = FUN_00105594(param_2,iVar9);
            if (iVar8 == iVar10) {
              FUN_00106004(param_2,iVar9,iVar7,0,*(undefined4 *)(param_1 + 8));
            }
          }
          uVar12 = 1;
        }
      }
      iVar8 = iVar2;
      if (((local_a8 == 1) && (iVar6 = local_a4, -1 < iVar1)) && (iVar1 != local_a4)) {
        iVar6 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        *(undefined4 *)(iVar6 + 0x98) = 0;
        *(undefined4 *)(iVar6 + 0x94) = *(undefined4 *)(iVar6 + 0x14c);
        FUN_00106004(iVar6,1,uVar4,0,*(undefined4 *)(param_1 + 8));
        local_98 = 0;
        for (iVar8 = 1; iVar7 = (**(code **)(*param_2 + 0x14))(param_2), iVar8 <= iVar7;
            iVar8 = iVar8 + 1) {
          local_a0 = 4;
          iVar7 = ((int (*)())FUN_00190100)(param_1,param_2,iVar8,&local_a0,&local_9c);
          if (((iVar7 != 0) && (local_a0 == local_a8)) && (local_9c == local_a4)) {
            iVar7 = FUN_001054ec(param_2,iVar8);
            FUN_000f3398(&local_50,*(undefined4 *)(iVar7 + 0x10));
            local_98 = local_50 | local_98;
            FUN_00106004(param_2,iVar8,iVar6,0,*(undefined4 *)(param_1 + 8));
          }
        }
        iVar7 = 1;
        FUN_000f31f8(local_4c,DAT_001b2a88,local_98);
        *(undefined4 *)(iVar6 + 0x9c) = local_4c[0];
        *(uint *)(iVar6 + 0xc) = local_98;
        iVar8 = FUN_00165604(iVar13,iVar6);
        if (*(int *)(iVar8 + 0x158) == 0) {
          uVar12 = 1;
          *(int *)(iVar11 + 0x238) = *(int *)(iVar11 + 0x238) + 1;
          FUN_000e7700(iVar13,param_2,iVar8);
          iVar6 = iVar1;
          iVar8 = iVar2;
        }
        else {
          for (; iVar9 = (**(code **)(*param_2 + 0x14))(param_2), iVar7 <= iVar9; iVar7 = iVar7 + 1)
          {
            iVar9 = FUN_00105594(param_2,iVar7);
            if (iVar6 == iVar9) {
              FUN_00106004(param_2,iVar7,iVar8,0,*(undefined4 *)(param_1 + 8));
            }
          }
          uVar12 = 1;
          iVar6 = iVar1;
          iVar8 = iVar2;
        }
      }
    }
LAB_0019125c:
    iVar5 = iVar5 + 1;
    iVar1 = iVar6;
    iVar2 = iVar8;
  } while( true );
}

/* FUN_00191298 @ 0x191298 (724 bytes) */
int FUN_00191298(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  if ((param_2[5] & 0x8000U) != 0) {
    return 0;
  }
  iVar1 = FUN_00113090(*(undefined4 *)(param_2[0x22] + 8),*(undefined4 *)(param_1 + 8));
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
    if ((iVar1 < 3) && (*(int *)(param_2[0x22] + 8) != 0x32)) {
      return 1;
    }
  }
  else {
    iVar1 = FUN_000f3a30(param_2);
    if (((iVar1 < 2) && (iVar1 = *(int *)(param_2[0x22] + 8), iVar1 != 0xa5)) &&
       (((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x10000) != 0 ||
        ((iVar1 != 0x4c && (iVar1 != 0x4d)))))) {
      for (iVar1 = 0; iVar2 = (**(code **)(*param_2 + 0x14))(param_2), iVar1 <= iVar2;
          iVar1 = iVar1 + 1) {
        iVar2 = FUN_00105dbc(param_2,iVar1);
        if (iVar2 != 0) {
          return 3;
        }
      }
      iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
      if (1 < iVar1) {
        piVar3 = (int *)FUN_00105594(param_2,1);
        piVar4 = (int *)FUN_00105594(param_2,2);
        iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
        if (2 < iVar1) {
          piVar5 = (int *)FUN_00105594(param_2,3);
          if (piVar4 != piVar5) {
            return 3;
          }
          iVar1 = FUN_001054ec(param_2,3);
          iVar2 = *(int *)(iVar1 + 0x10);
          iVar1 = FUN_001054ec(param_2,2);
          if (iVar2 != *(int *)(iVar1 + 0x10)) {
            return 3;
          }
          if ((param_2[0x3a] & 1U) != (param_2[0x34] & 1U)) {
            return 3;
          }
        }
        if (piVar3 != piVar4) {
          if (piVar3[0x20] == 0) {
            return 3;
          }
          iVar1 = FUN_00126760(piVar3[0x26]);
          if (iVar1 == 0) {
            return 3;
          }
          if ((piVar3[5] & 2U) != 0) {
            return 3;
          }
          iVar1 = (**(code **)(*piVar3 + 0x50))(piVar3);
          if (iVar1 != 0) {
            return 3;
          }
          if (piVar4[0x20] == 0) {
            return 3;
          }
          iVar1 = FUN_00126760(piVar4[0x26]);
          if (iVar1 == 0) {
            return 3;
          }
          if ((piVar4[5] & 2U) != 0) {
            return 3;
          }
          iVar1 = (**(code **)(*piVar4 + 0x50))(piVar4);
          if (iVar1 != 0) {
            return 3;
          }
          if (piVar3[0x26] != piVar4[0x26]) {
            return 3;
          }
          if (((piVar3[5] & 0x40U) != 0) && ((piVar4[5] & 0x40U) != 0)) {
            if (piVar3[0x25] != piVar4[0x25]) {
              return 3;
            }
            return 2;
          }
          iVar1 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x25);
          if (iVar1 == 0) {
            return 3;
          }
          if ((piVar3[5] & 0x20U) != 0) {
            return 3;
          }
          if ((piVar4[5] & 0x20U) != 0) {
            return 3;
          }
          return 2;
        }
      }
      return 2;
    }
  }
  return 3;
}

/* FUN_0019156c @ 0x19156c (412 bytes) */
int FUN_0019156c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (((*(uint *)(param_2 + 0x14) & 2) == 0) &&
     ((*(int *)(param_2 + 0x98) == 0 || (*(int *)(param_2 + 0x98) == 1)))) {
    iVar2 = *(int *)(param_2 + 0x88);
    iVar1 = *(int *)(iVar2 + 8);
    if ((iVar1 == 0x66) || (iVar1 == 0x36)) {
      return 1;
    }
    if (iVar1 == 0x31) {
      iVar1 = FUN_000f3a30(param_2);
      if (iVar1 == 1) {
        return 1;
      }
      iVar2 = *(int *)(param_2 + 0x88);
    }
    if (((*(int *)(iVar2 + 8) == 0x13) && (iVar1 = FUN_000f3a30(param_2), iVar1 == 1)) &&
       ((*(uint *)(param_2 + 0xb8) & 1) == (*(uint *)(param_2 + 0xd0) & 1))) {
      iVar1 = FUN_00105594(param_2,1);
      iVar2 = FUN_00105594(param_2,2);
      if (iVar1 == iVar2) {
        return 1;
      }
      piVar3 = (int *)FUN_00105594(param_2,1);
      if (((((piVar3[0x20] != 0) && (iVar1 = FUN_00126760(piVar3[0x26]), iVar1 != 0)) &&
           (((piVar3[5] & 2U) == 0 &&
            ((iVar1 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar1 == 0 &&
             (piVar3 = (int *)FUN_00105594(param_2,2), piVar3[0x20] != 0)))))) &&
          (iVar1 = FUN_00126760(piVar3[0x26]), iVar1 != 0)) &&
         (((piVar3[5] & 2U) == 0 && (iVar1 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar1 == 0)))) {
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_00191710 @ 0x191710 (76 bytes) */
undefined4 FUN_00191710(double param_1)

{
  if (((param_1 != (double)FLOAT_001aa0d4) && (param_1 != (double)FLOAT_001aa10c)) &&
     (param_1 != (double)FLOAT_001aa0e8)) {
    return 0;
  }
  return 1;
}

/* FUN_00191888 @ 0x191888 (184 bytes) */
undefined4 FUN_00191888(double param_1,int param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  
  if ((double)FLOAT_001aa0d4 < param_1) {
    fVar1 = (float)param_1;
    if (((uint)fVar1 & 1) == 0) {
      uVar2 = (uint)fVar1 >> 1 & 0xff;
      *param_4 = uVar2;
      if ((uVar2 == 0) || (*param_4 = uVar2 - 0x78, uVar2 - 0x78 < 0x10)) {
        if (*param_4 == 0) {
          uVar2 = 0;
          iVar3 = 8;
          do {
            if (param_1 == (double)*(float *)(((unsigned char *)0x00001744) + param_2)) {
              *param_5 = uVar2;
              return 1;
            }
            uVar2 = uVar2 + 1;
            param_2 = param_2 + 4;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        else {
          *param_5 = (uint)fVar1 >> 9;
          if (((uint)fVar1 >> 9 & 0xfffff) == 0) {
            *param_5 = (uint)fVar1 >> 0x1d;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_00191940 @ 0x191940 (152 bytes) */
int FUN_00191940(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  undefined4 param_3;
{
  float fVar1;
  char *pcVar2;
  undefined4 uVar3;
  bool bVar4;
  int iVar5;
  undefined4 uStack00000020;
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [32];
  
  bVar4 = false;
  iVar5 = 4;
  uStack00000020 = param_3;
  pcVar2 = (char *)&STACKARG(0x20);
  fVar1 = FLOAT_001aa0d4;
  do {
    if (*pcVar2 != '\x04') {
      if (bVar4) {
        if (*param_2 != fVar1) {
          return 0;
        }
        bVar4 = true;
      }
      else {
        fVar1 = *param_2;
        bVar4 = true;
      }
    }
    pcVar2 = pcVar2 + 1;
    param_2 = param_2 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  uVar3 = ((undefined4 (*)())FUN_00191888)(param_1,param_2,auStack_28,auStack_24);
  return uVar3;
}

/* FUN_001919d8 @ 0x1919d8 (344 bytes) */
int FUN_001919d8(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  float *param_3;
  int *param_4;
{
  float fVar1;
  bool bVar2;
  int *piVar3;
  float *pfVar4;
  bool bVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  float local_38 [6];
  float local_20;
  
  if (*param_4 != DAT_001b2aa8) {
    iVar7 = 4;
    bVar2 = true;
    bVar5 = true;
    piVar3 = param_4;
    pfVar4 = param_3;
    fVar1 = FLOAT_001aa0d4;
    do {
      if (*(char *)piVar3 != '\x04') {
        if (bVar2) {
          fVar1 = *pfVar4;
          bVar2 = false;
        }
        else if (*pfVar4 != fVar1) {
          bVar5 = false;
        }
      }
      piVar3 = (int *)((int)piVar3 + 1);
      pfVar4 = pfVar4 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    if (bVar5) {
      iVar7 = 4;
      pfVar4 = local_38;
      do {
        *pfVar4 = NAN;
        pfVar4 = pfVar4 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iVar7 = 0;
      iVar8 = 4;
      do {
        local_20 = fVar1;
        *(float *)(iVar7 + (int)local_38) = fVar1;
        iVar7 = iVar7 + 4;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      iVar7 = FUN_000f6a04(param_2,local_38,DAT_001b2aa4);
    }
    else {
      iVar7 = FUN_000f6a04(param_2,param_3,*param_4);
    }
    if (iVar7 != 0) {
      return iVar7;
    }
    uVar6 = *(undefined4 *)(param_2 + 0x3ac);
    iVar7 = FUN_000f5f94(uVar6,param_3,param_4);
    if (iVar7 != 0) {
      return iVar7;
    }
    iVar7 = FUN_000f57f0(uVar6,param_3,param_4);
    if (iVar7 != 0) {
      return iVar7;
    }
  }
  return 0;
}

/* FUN_00191b30 @ 0x191b30 (316 bytes) */
int FUN_00191b30(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
  int param_5;
{
  char cVar1;
  float fVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  float *pfVar7;
  int iVar8;
  uint local_58;
  undefined4 local_54;
  float local_50 [8];
  undefined4 local_30;
  
  local_58 = param_4 << 0x18 | (param_4 & 0xff00) << 8 | param_4 >> 8 & 0xff00 | param_4 >> 0x18;
  piVar4 = (int *)FUN_00105594(param_2,param_3);
  iVar5 = (**(code **)(*piVar4 + 0x48))();
  if (iVar5 == 0) {
LAB_00191c54:
    uVar6 = 0;
  }
  else {
    iVar5 = FUN_001054ec(param_2,param_3);
    iVar8 = 0;
    local_54 = *(undefined4 *)(iVar5 + 0x10);
    iVar5 = 4;
    pfVar7 = local_50;
    do {
      cVar1 = *(char *)((int)&local_58 + iVar8);
      *pfVar7 = FLOAT_001aa0d4;
      if (cVar1 == '\0') {
        uVar3 = (uint)*(byte *)((int)local_50 + iVar8 + -4);
        if ((((int)*(char *)(piVar4 + 0x57) >> (uVar3 & 0x3f) & 1U) == 0) ||
           (((fVar2 = (float)piVar4[uVar3 * 6 + 8], fVar2 != FLOAT_001aa0d4 &&
             (fVar2 != FLOAT_001aa0e8)) && (local_30 = 0x3f000000, fVar2 != 0.5))))
        goto LAB_00191c54;
        *pfVar7 = fVar2;
      }
      iVar8 = iVar8 + 1;
      pfVar7 = pfVar7 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    FUN_000f79c4((double)local_50[0],(double)local_50[1],(double)local_50[2],(double)local_50[3],
                 param_2,*(undefined4 *)(param_5 + 0x6c4),param_3);
    uVar6 = 1;
  }
  return uVar6;
}

/* FUN_00191c7c @ 0x191c7c (428 bytes) */
int FUN_00191c7c(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  float *param_2;
  undefined4 *param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  float fVar1;
  bool bVar2;
  char *pcVar3;
  float *pfVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  undefined4 uStack00000024;
  
  uStack00000024 = param_4;
  *param_3 = 0xffffffff;
  pcVar3 = (char *)&STACKARG(0x24);
  iVar6 = 4;
  pfVar4 = param_2;
  pcVar5 = pcVar3;
  while ((((*pcVar5 == '\x04' || (fVar1 = *pfVar4, fVar1 == FLOAT_001aa0d4)) ||
          (fVar1 == FLOAT_001aa10c)) || (fVar1 == 1.0))) {
    pcVar5 = pcVar5 + 1;
    pfVar4 = pfVar4 + 1;
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) {
      iVar6 = (int)pcVar5 - (int)pcVar3;
      do {
        if (*pcVar3 == '\x04') {
          *param_2 = 0.0;
        }
        pcVar3 = pcVar3 + 1;
        param_2 = param_2 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      return 1;
    }
  }
  iVar6 = FUN_000e07dc(param_5,0x2f);
  if (iVar6 == 0) {
    return 0;
  }
  iVar6 = 4;
  bVar2 = true;
  pfVar4 = param_2;
  fVar1 = FLOAT_001aa0d4;
  do {
    if (*pcVar3 != '\x04') {
      if (bVar2) {
        fVar1 = *pfVar4;
        bVar2 = false;
      }
      else if (*pfVar4 != fVar1) {
        return 0;
      }
    }
    pcVar3 = pcVar3 + 1;
    pfVar4 = pfVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = (**(code **)(*param_1 + 0x98))(param_1,param_2,uStack00000024);
  if (iVar6 != 0) {
    iVar6 = 0;
    iVar7 = 4;
    do {
      *(float *)((int)param_2 + iVar6) = fVar1;
      iVar6 = iVar6 + 4;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    *param_3 = 3;
    return 1;
  }
  return 0;
}

/* FUN_00191e28 @ 0x191e28 (196 bytes) */
int FUN_00191e28(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  
  puVar2 = (undefined4 *)FUN_000e1564(param_2,0x6c);
  puVar1 = PTR_DAT_001e90f4;
  puVar3 = PTR_DAT_001e90fc + 8;
  puVar2[2] = param_2;
  *puVar2 = puVar3;
  puVar2[1] = 0;
  *puVar2 = puVar1 + 8;
  FUN_00189560(puVar2 + 10);
  FUN_00189604(puVar2);
  puVar2[0x1a] = 0;
  *puVar2 = PTR_DAT_001e9148 + 8;
  *(undefined4 **)(param_1 + 0x60) = puVar2;
  puVar2 = (undefined4 *)FUN_000e1564(param_2,0xc);
  puVar1 = PTR_DAT_001e9100;
  puVar2[1] = 1;
  puVar2[2] = 0;
  *puVar2 = puVar1 + 8;
  *(undefined4 **)(param_1 + 100) = puVar2;
  return;
}

/* FUN_001920e0 @ 0x1920e0 (748 bytes) */
int FUN_001920e0(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  double dVar7;
  uint uVar8;
  float *pfVar9;
  uint uVar10;
  float *pfVar11;
  double dVar12;
  
  FUN_00128fd0(param_1,param_2,0);
  param_1[7] = 0;
  param_1[0x10] = 0x200;
  *param_1 = &PTR_FUN_001eb450;
  param_1[0xb] = 0x100;
  param_1[8] = 0x7fffffff;
  param_1[0x13] = 4;
  param_1[9] = 0x20;
  param_1[10] = 0x10;
  param_1[0xe] = 0x89;
  param_1[0x15] = 0x400;
  param_1[0xf] = 0x10;
  param_1[0x11] = 4;
  param_1[0x12] = 4;
  param_1[0x14] = 0x20;
  FUN_0010dc20(param_1);
  FUN_0010dbd8(param_1,0x2f);
  FUN_0010dbd8(param_1,0x30);
  FUN_0010dbd8(param_1,0x31);
  FUN_0010dbd8(param_1,0x34);
  FUN_0010dbd8(param_1,0x35);
  FUN_0010dbd8(param_1,0x36);
  FUN_0010dbd8(param_1,0x37);
  FUN_0010dbd8(param_1,0x38);
  FUN_0010dbd8(param_1,0x39);
  FUN_0010dbd8(param_1,0x3a);
  FUN_0010dbd8(param_1,0x3b);
  FUN_0010dbd8(param_1,0x3c);
  FUN_0010dbd8(param_1,0x3d);
  FUN_0010dbd8(param_1,0x40);
  FUN_0010dbd8(param_1,0x42);
  FUN_0010dbd8(param_1,0x47);
  FUN_0010dbd8(param_1,0x4a);
  FUN_0010dbd8(param_1,0x4b);
  param_1[2] = param_1[2] & 0xfffdffff | 0x1d80;
  FUN_0019ef2c(param_1);
  if (param_3 != 0) {
    ((int (*)())FUN_00191e28)(param_1,param_2);
  }
  pfVar9 = (float *)(param_1 + 0x5d0);
  uVar8 = 0;
  FUN_001a325c(param_1,param_2);
  dVar7 = DOUBLE_001aa2a8[0];
  dVar6 = DOUBLE_001aa1e0;
  fVar5 = FLOAT_001aa1c4;
  fVar4 = FLOAT_001aa170;
  fVar3 = FLOAT_001aa0e8;
  do {
    uVar10 = 0;
    pfVar11 = pfVar9;
    do {
      pfVar11 = pfVar11 + 1;
      if (uVar8 == 0) {
        fVar2 = FLOAT_001aa1c0;
        if (uVar10 != 0) {
          fVar2 = (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - dVar6) * fVar4 * fVar5;
        }
      }
      else {
        dVar12 = (double)_pow(DOUBLE_001aa2a0,
                              (double)(float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) -
                                             dVar6) - dVar7);
        fVar2 = (float)dVar12 *
                ((float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - dVar6) * fVar4 + fVar3);
      }
      bVar1 = uVar10 != 7;
      *pfVar11 = fVar2;
      uVar10 = uVar10 + 1;
    } while (bVar1);
    bVar1 = uVar8 != 0xf;
    pfVar9 = pfVar9 + 8;
    uVar8 = uVar8 + 1;
  } while (bVar1);
  return;
}

/* FUN_001922c4 @ 0x1922c4 (1220 bytes) */
int FUN_001922c4(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  double dVar13;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  
  uVar11 = *(undefined4 *)(param_4 + 8);
  iVar2 = *(int *)(param_3[0x22] + 8);
  if (((((iVar2 == 0x5d) || (iVar2 == 0x29)) || (iVar2 == 0x5b)) ||
      ((iVar2 == 0x27 || (iVar2 == 0x5e)))) ||
     ((iVar2 == 0x2a || ((iVar2 == 0x5c || (iVar2 == 0x28)))))) {
    switch(iVar2) {
    case 0x27:
    case 0x5b:
      iVar12 = 1;
      iVar2 = 2;
      uVar9 = 3;
      uVar10 = 2;
      uVar8 = 1;
      uVar7 = 1;
      break;
    case 0x28:
    case 0x5c:
      iVar12 = 2;
      iVar2 = 1;
      uVar9 = 2;
      uVar10 = 3;
      uVar8 = 0;
      uVar7 = 0;
      break;
    case 0x29:
    case 0x5d:
      iVar12 = 1;
      iVar2 = 2;
      uVar9 = 3;
      uVar10 = 2;
      uVar8 = 0;
      uVar7 = 0;
      break;
    case 0x2a:
    case 0x5e:
      iVar12 = 1;
      iVar2 = 2;
      uVar9 = 2;
      uVar10 = 3;
      uVar8 = 1;
      uVar7 = 1;
      break;
    default:
      iVar12 = 0;
      iVar2 = 0;
      uVar9 = 0;
      uVar10 = 0;
      uVar8 = 0;
      uVar7 = 0;
    }
    iVar3 = FUN_001043f0(0x12,uVar11);
    uVar4 = FUN_00105594(param_3,iVar12);
    FUN_00106004(iVar3,iVar12,uVar4,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar11);
    iVar5 = FUN_001054ec(param_3,iVar12);
    uVar4 = *(undefined4 *)(iVar5 + 0x10);
    iVar5 = FUN_001054ec(iVar3,iVar12);
    *(undefined4 *)(iVar5 + 0x10) = uVar4;
    iVar5 = iVar3 + iVar12 * 0x18 + 0x8c;
    FUN_00103d50(iVar5,2,(uint)param_3[iVar12 * 6 + 0x28] >> 1 & 1);
    FUN_00103d50(iVar5,1,param_3[iVar12 * 6 + 0x28] & 1);
    uVar4 = FUN_00105594(param_3,iVar2);
    FUN_00106004(iVar3,iVar2,uVar4,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar11);
    iVar12 = FUN_001054ec(param_3,iVar2);
    uVar4 = *(undefined4 *)(iVar12 + 0x10);
    iVar12 = FUN_001054ec(iVar3,iVar2);
    *(undefined4 *)(iVar12 + 0x10) = uVar4;
    iVar12 = iVar3 + iVar2 * 0x18 + 0x8c;
    FUN_00103d50(iVar12,2,(uint)param_3[iVar2 * 6 + 0x28] >> 1 & 1);
    FUN_00103d50(iVar12,1,param_3[iVar2 * 6 + 0x28] & 1U ^ 1);
    iVar2 = FUN_001054ec(param_3,0);
    uVar4 = *(undefined4 *)(iVar2 + 0x10);
    *(undefined4 *)(iVar3 + 0x94) = *(undefined4 *)(iVar3 + 0x14c);
    *(undefined4 *)(iVar3 + 0x9c) = uVar4;
    *(undefined4 *)(iVar3 + 0x98) = 0;
    ((int (*)())FUN_00193f44)(iVar3,param_3);
    if ((*(uint *)(param_4 + 0x30) & 0x80) == 0) {
      *(int *)(iVar3 + 0x160) = *(int *)(param_4 + 0x478) + 1;
    }
    *(int *)(iVar3 + 0x158) = param_3[0x56];
    iVar2 = 0;
    local_40 = 0;
    local_48 = 0;
    local_44 = 0;
    FUN_00103f18(param_3,&local_48,0xffffffff);
    if ((param_3[5] & 0x200U) != 0) {
      iVar2 = FUN_00105594(param_3,param_3[0x21]);
    }
    iVar12 = param_3[4];
    ((int (*)())FUN_0019401c)(param_3);
    FUN_00106004(param_3,1,0,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar11);
    FUN_00106004(param_3,2,0,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar11);
    FUN_00108304(param_3,0x25,*(undefined4 *)(param_4 + 8));
    FUN_00103f44(param_3,&local_48);
    param_3[4] = iVar12;
    FUN_00106004(param_3,1,iVar3,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar11);
    iVar5 = 0;
    FUN_00103d50(param_3 + 0x29,1,uVar8);
    FUN_00103d50(param_3 + 0x29,2,uVar7);
    dVar13 = (double)FLOAT_001aa0e8;
    FUN_000f79c4(dVar13,dVar13,dVar13,dVar13,param_3,param_4,uVar10);
    dVar13 = (double)FLOAT_001aa0d4;
    FUN_000f79c4(dVar13,dVar13,dVar13,dVar13,param_3,param_4,uVar9);
    param_3[0x25] = param_3[0x53];
    param_3[0x26] = 0;
    iVar12 = FUN_001054ec(iVar3,0);
    param_3[0x27] = *(int *)(iVar12 + 0x10);
    do {
      iVar12 = FUN_001054ec(iVar3,0);
      if (*(char *)(iVar5 + iVar12 + 0x10) == '\x01') {
        for (iVar12 = 1; iVar6 = (**(code **)(*param_3 + 0x14))(param_3), iVar12 <= iVar6;
            iVar12 = iVar12 + 1) {
          (**(code **)(*param_3 + 0x88))(param_3,iVar12,iVar5,4);
        }
      }
      bVar1 = iVar5 != 3;
      iVar5 = iVar5 + 1;
    } while (bVar1);
    if (iVar2 != 0) {
      FUN_00106804(param_3,iVar2,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar11);
    }
    param_3[0x56] = *(int *)(iVar3 + 0x158);
    ((int (*)())FUN_00193f74)(param_3,iVar3);
    if ((*(uint *)(param_4 + 0x30) & 0x80) == 0) {
      FUN_001875a8(param_3,1,iVar3,param_4,*(undefined4 *)(param_4 + 8));
    }
  }
  return param_3;
}

/* FUN_0019286c @ 0x19286c (4308 bytes) */
int FUN_0019286c(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int *param_2;
  int param_3;
  int *param_4;
  int param_5;
{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  undefined4 uVar18;
  undefined4 local_58;
  int local_54 [7];
  
  local_58 = 0;
  iVar3 = (**(code **)(*param_4 + 0x60))(param_4);
  if (iVar3 != 0) {
    piVar4 = (int *)FUN_00105594(param_4,1);
    iVar3 = (**(code **)(*piVar4 + 0x60))();
    if (iVar3 != 0) {
      uVar5 = FUN_00105594(param_4,1);
      FUN_0010c670(uVar5,param_4,*(undefined4 *)(param_5 + 8));
    }
  }
  iVar3 = FUN_000e07dc(*(undefined4 *)(param_5 + 8),0x38);
  if (((iVar3 != 0) && (param_2 != (int *)0x0)) &&
     (iVar3 = (**(code **)(*param_2 + 100))(param_2), iVar3 == 0)) {
    FUN_0014a918(param_2,param_3,param_5);
  }
  uVar5 = 0;
  iVar3 = FUN_000e07dc(*(undefined4 *)(param_5 + 8),0x1b);
  if (iVar3 != 0) {
    uVar5 = (**(code **)(*param_4 + 100))(param_4);
    iVar3 = FUN_0014abdc(param_4,param_5,&local_58);
    if ((iVar3 != 0) &&
       (param_4 = (int *)FUN_00146610(param_2,param_3,param_4), param_4 == (int *)0x0)) {
      return 1;
    }
    if (((param_2 != (int *)0x0) &&
        (iVar3 = FUN_00160320(param_2,param_3,param_4,param_5,&local_58), iVar3 != 0)) &&
       (param_4 = (int *)FUN_00146610(param_2,param_3,param_4), param_4 == (int *)0x0)) {
      return 1;
    }
  }
  iVar3 = FUN_000e07dc(*(undefined4 *)(param_5 + 8),0x1c);
  if (iVar3 != 0) {
    iVar3 = FUN_00162cc0(param_4,param_5);
    if (iVar3 != 0) {
      iVar3 = (**(code **)(*param_4 + 100))(param_4);
      if (((iVar3 != 0) && ((param_4[5] & 0x200U) == 0)) && (param_2 != (int *)0x0)) {
        FUN_00160320(param_2,param_3,param_4,param_5,&local_58);
      }
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      if (param_4 == (int *)0x0) {
        return 1;
      }
    }
    iVar3 = (**(code **)(*param_4 + 0x14))(param_4);
    if ((param_3 <= iVar3) && (iVar3 = FUN_00158264(param_2,param_3,param_4,param_5), iVar3 != 0)) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      if (param_4 == (int *)0x0) {
        return 1;
      }
      uVar5 = 1;
    }
    iVar3 = FUN_00155a60(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0014bdbc(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0014b82c(param_4,param_5,0,1);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0014b150(param_4,param_5);
    if (iVar3 != 0) {
      iVar3 = (**(code **)(*param_4 + 100))(param_4);
      if (((iVar3 != 0) && ((param_4[5] & 0x200U) == 0)) && (param_2 != (int *)0x0)) {
        FUN_00160320(param_2,param_3,param_4,param_5,&local_58);
      }
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      if (param_4 == (int *)0x0) {
        return 1;
      }
      uVar5 = 1;
    }
    iVar3 = FUN_0014caec(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0014d8f8(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0015ceb0(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0015bd40(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_00163994(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0015c6d4(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0014cec8(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_00150d38(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0014acb8(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_001595f0(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0015df44(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0015e494(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_000e07dc(*(undefined4 *)(param_5 + 8),0x3c);
    if ((iVar3 != 0) && (iVar3 = FUN_00163478(param_2,param_3,param_4,param_5), iVar3 != 0)) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0014d274(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_00158c3c(param_4,param_5);
    if (iVar3 != 0) {
      uVar5 = 1;
    }
  }
  iVar3 = FUN_0015546c(param_2,param_3,param_4,param_5);
  if (iVar3 != 0) {
    uVar5 = 1;
    param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
  }
  iVar3 = FUN_00155654(param_2,param_3,param_4,param_5);
  if (iVar3 != 0) {
    uVar5 = 1;
    param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
  }
  iVar3 = FUN_000e07dc(*(undefined4 *)(param_5 + 8),0x1d);
  if (((((iVar3 != 0) && (iVar3 = FUN_001633f8(param_4,param_5), iVar3 != 0)) &&
       (iVar3 = (**(code **)(*param_4 + 100))(param_4), iVar3 != 0)) &&
      ((param_2 != (int *)0x0 &&
       (iVar3 = FUN_00160320(param_2,param_3,param_4,param_5,&local_58), iVar3 != 0)))) &&
     (param_4 = (int *)FUN_00146610(param_2,param_3,param_4), param_4 == (int *)0x0)) {
    return 1;
  }
  iVar3 = FUN_00160eb0(param_2,param_3,param_4,param_5);
  if (iVar3 != 0) {
    param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
  }
  uVar18 = *(undefined4 *)(param_5 + 8);
  if (*(int *)(param_4[0x22] + 8) != 0x77) goto LAB_00193490;
  iVar3 = FUN_000e07dc(uVar18,0x3d);
  if (iVar3 != 0) {
    iVar3 = FUN_001054ec(param_4,1);
    iVar3 = FUN_000f2c5c(*(undefined4 *)(iVar3 + 0x10));
    if (((iVar3 != 0) &&
        (piVar4 = (int *)FUN_00105594(param_4,1), *(int *)(piVar4[0x22] + 8) == 0x12)) &&
       ((piVar4[0x48] == 0 &&
        (((piVar4[0x49] == 0 && ((piVar4[5] & 0x200U) == 0)) &&
         (iVar3 = FUN_0010497c(piVar4,param_5), iVar3 != 0)))))) {
      iVar3 = FUN_001054ec(piVar4,0);
      iVar3 = FUN_000f37b8(*(undefined4 *)(iVar3 + 0x10));
      if (-1 < iVar3) {
        piVar6 = (int *)FUN_00105594(piVar4,1);
        piVar7 = (int *)FUN_00105594(piVar4,2);
        iVar8 = (**(code **)(*piVar6 + 0x48))(piVar6);
        if (iVar8 == 0) {
          iVar8 = (**(code **)(*piVar7 + 0x48))(piVar7);
          if (iVar8 == 0) goto LAB_0019348c;
          uVar13 = 2;
          iVar8 = 1;
        }
        else {
          uVar13 = 1;
          iVar8 = 2;
          piVar6 = piVar7;
        }
        iVar9 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa174,piVar4,uVar13);
        if (((iVar9 != 0) && ((piVar4[iVar8 * 6 + 0x28] & 1U) == 0)) &&
           ((piVar4[iVar8 * 6 + 0x28] & 2U) == 0)) {
          iVar8 = FUN_001054ec(piVar4,iVar8);
          uVar14 = (uint)*(byte *)(iVar3 + iVar8 + 0x10);
          if (((*(int *)(piVar6[0x22] + 8) == 0x12) && (piVar6[0x48] == 0)) && (piVar6[0x49] == 0))
          {
            iVar3 = FUN_001054ec(piVar6,0);
            uVar10 = FUN_000f37b8(*(undefined4 *)(iVar3 + 0x10));
            if ((uVar14 == uVar10) && (iVar3 = FUN_0010497c(piVar6,param_5), iVar3 != 0)) {
              iVar3 = FUN_00105594(piVar6,1);
              iVar8 = FUN_00105594(piVar6,2);
              uVar10 = piVar6[0x2e] & 1;
              if (((iVar3 == iVar8) &&
                  (((uVar10 != (piVar6[0x34] & 1U) && ((piVar6[0x2e] & 2U) == 0)) &&
                   ((piVar6[0x34] & 2U) == 0)))) &&
                 (iVar8 = FUN_001049a0(iVar8,param_5), iVar8 != 0)) {
                iVar8 = FUN_001054ec(piVar6,1);
                uVar17 = (uint)*(byte *)(uVar14 + iVar8 + 0x10);
                iVar8 = FUN_001054ec(piVar6,2);
                uVar15 = (uint)*(byte *)(uVar14 + iVar8 + 0x10);
                uVar14 = uVar15;
                if (uVar10 == 0) {
                  uVar14 = uVar17;
                  uVar17 = uVar15;
                }
                if (((*(int *)(*(int *)(iVar3 + 0x88) + 8) == 0x25) &&
                    (iVar8 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0e8,iVar3,2), iVar8 != 0)) &&
                   (((iVar8 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,iVar3,3), iVar8 != 0 &&
                     (((*(uint *)(iVar3 + 0x14) & 0x200) == 0 &&
                      ((*(uint *)(iVar3 + 0xb8) & 1) == 0)))) &&
                    ((*(uint *)(iVar3 + 0xb8) & 2) == 0)))) {
                  ((int (*)())FUN_0019401c)(piVar4);
                  ((int (*)())FUN_0019401c)(piVar6);
                  ((int (*)())FUN_0019401c)(iVar3);
                  FUN_00108174(piVar4,0x17,uVar18);
                  iVar3 = FUN_00105594(iVar3,1);
                  if (*(int *)(param_5 + 0x478) < *(int *)(iVar3 + 0x160)) {
                    *(int *)(iVar3 + 0x160) = *(int *)(iVar3 + 0x160) + 1;
                  }
                  else {
                    *(int *)(iVar3 + 0x160) = *(int *)(param_5 + 0x478) + 1;
                  }
                  if (*(int *)(param_5 + 0x478) < *(int *)(iVar3 + 0x160)) {
                    *(int *)(iVar3 + 0x160) = *(int *)(iVar3 + 0x160) + 1;
                  }
                  else {
                    *(int *)(iVar3 + 0x160) = *(int *)(param_5 + 0x478) + 1;
                  }
                  FUN_00106004(piVar4,1,iVar3,0,uVar18);
                  FUN_00106004(piVar4,2,iVar3,0,uVar18);
                  piVar4[0x27] = *(int *)(PTR_DAT_001e8b64 + uVar17 * 4);
                  FUN_00106804(piVar4,iVar3,0,uVar18);
                  uVar18 = DAT_001b2aac;
                  iVar3 = FUN_001054ec(piVar4,1);
                  *(undefined4 *)(iVar3 + 0x10) = uVar18;
                  iVar3 = FUN_001054ec(piVar4,2);
                  *(undefined4 *)(iVar3 + 0x10) = uVar18;
                  iVar3 = FUN_001054ec(param_4,1);
                  *(undefined4 *)(iVar3 + 0x10) = uVar18;
                  (**(code **)(*param_4 + 0x88))(param_4,1,uVar14,uVar14);
                  (**(code **)(*param_4 + 0x88))(param_4,1,uVar17,uVar17);
                  (**(code **)(*piVar4 + 0x88))(piVar4,1,uVar17,uVar17);
                  (**(code **)(*piVar4 + 0x88))(piVar4,2,uVar17,uVar17);
                  FUN_00103d50(piVar4 + 0x29,1,1);
                  FUN_00103d50(piVar4 + 0x2f,1,1);
                  piVar4[0x26] = 0;
                  piVar4[0x25] = piVar4[0x53];
                  if (*(int *)(param_5 + 0x478) < piVar4[0x58]) {
                    piVar4[0x58] = piVar4[0x58] + 1;
                  }
                  else {
                    piVar4[0x58] = *(int *)(param_5 + 0x478) + 1;
                  }
                  FUN_000e7700(param_4[0x56],param_4,piVar4);
                  local_54[0] = *(int *)(PTR_DAT_001e8b64 + uVar14 * 4);
                  pcVar2 = PTR_DAT_001e8b64 + uVar17 * 4;
                  iVar8 = 4;
                  iVar3 = 0;
                  do {
                    if (*pcVar2 != '\x01') {
                      *(char *)((int)local_54 + iVar3) = *pcVar2;
                    }
                    iVar3 = iVar3 + 1;
                    pcVar2 = pcVar2 + 1;
                    iVar8 = iVar8 + -1;
                  } while (iVar8 != 0);
                  param_4[0x27] = local_54[0];
                  param_4[5] = param_4[5] | 0x2000000;
                  param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
                  uVar18 = *(undefined4 *)(param_5 + 8);
                  goto LAB_00193490;
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0019348c:
  uVar18 = *(undefined4 *)(param_5 + 8);
LAB_00193490:
  iVar3 = FUN_000e07dc(uVar18,0x39);
  if (iVar3 != 0) {
    FUN_001882a4(param_4,*(undefined4 *)(param_5 + 8));
    for (iVar3 = 1; iVar8 = (**(code **)(*param_4 + 0x14))(param_4), iVar3 <= iVar8;
        iVar3 = iVar3 + 1) {
      uVar18 = FUN_00105594(param_4,iVar3);
      FUN_001875a8(param_4,iVar3,uVar18,param_5,*(undefined4 *)(param_5 + 8));
    }
    iVar3 = FUN_001875a8(param_2,param_3,param_4,param_5,*(undefined4 *)(param_5 + 8));
    if (iVar3 != 0) {
      uVar5 = 1;
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
  }
  piVar4 = (int *)((int (*)())FUN_001922c4)(param_2,param_3,param_4,param_5);
  iVar3 = FUN_00159b58(piVar4,1,param_5);
  if (iVar3 != 0) {
    uVar5 = 1;
    piVar4 = (int *)FUN_00146610(param_2,param_3,piVar4);
  }
  iVar3 = FUN_0011379c(*(undefined4 *)(param_5 + 8),piVar4);
  if ((iVar3 != 0) && ((piVar4[5] & 0x200U) == 0)) {
    for (iVar3 = 1; iVar8 = (**(code **)(*piVar4 + 0x14))(piVar4), iVar3 <= iVar8; iVar3 = iVar3 + 1
        ) {
      iVar8 = FUN_00105594(piVar4,iVar3);
      if ((((*(int *)(*(int *)(iVar8 + 0x88) + 8) == 0x4c) &&
           (iVar9 = FUN_0010497c(iVar8,param_5), iVar9 != 0)) &&
          ((*(uint *)(iVar8 + 0x14) & 0x200) != 0)) &&
         (iVar9 = FUN_00105594(iVar8,*(undefined4 *)(iVar8 + 0x84)),
         *(int *)(*(int *)(iVar9 + 0x88) + 8) == 0x4d)) {
        uVar18 = FUN_00105594(iVar8,*(undefined4 *)(iVar8 + 0x84));
        iVar9 = FUN_0010497c(uVar18,param_5);
        if ((iVar9 != 0) &&
           (iVar9 = FUN_00105594(iVar8,*(undefined4 *)(iVar8 + 0x84)),
           (*(uint *)(iVar9 + 0x14) & 0x200) == 0)) {
          iVar16 = 0;
          uVar18 = FUN_00105594(iVar8,*(undefined4 *)(iVar8 + 0x84));
          iVar11 = FUN_0010445c(piVar4,*(undefined4 *)(param_5 + 8),0);
          piVar6 = piVar4;
          iVar9 = iVar11;
          do {
            iVar12 = FUN_001054ec(piVar4,iVar3);
            if (*(byte *)(iVar16 + iVar12 + 0x10) < 4) {
              iVar12 = FUN_000f313c(uVar18);
              if (iVar12 == 0) {
                *(undefined1 *)(iVar9 + 0x9c) = 1;
              }
              else {
                *(undefined1 *)(piVar6 + 0x27) = 1;
              }
            }
            bVar1 = iVar16 != 3;
            piVar6 = (int *)((int)piVar6 + 1);
            iVar9 = iVar9 + 1;
            iVar16 = iVar16 + 1;
          } while (bVar1);
          FUN_00106004(iVar11,iVar3,uVar18,0,*(undefined4 *)(param_5 + 8));
          FUN_00106804(piVar4,iVar11,0,*(undefined4 *)(param_5 + 8));
          FUN_000e7700(piVar4[0x56],piVar4,iVar11);
          FUN_00106004(iVar8,*(undefined4 *)(iVar8 + 0x84),0,0,*(undefined4 *)(param_5 + 8));
          *(int *)(iVar8 + 0x84) = *(int *)(iVar8 + 0x84) + -1;
          *(uint *)(iVar8 + 0x14) = *(uint *)(iVar8 + 0x14) & 0xfffffdff;
          FUN_000f35c4(piVar4);
          FUN_000f35c4(iVar11);
          iVar8 = *(int *)(iVar11 + 0x84);
          *(int *)(iVar11 + 0x160) = *(int *)(param_5 + 0x478) + 1;
          if (0 < iVar8) {
            iVar9 = 1;
            do {
              if (iVar9 != iVar3) {
                piVar6 = (int *)FUN_00105594(iVar11,iVar9);
                iVar8 = (**(code **)(*piVar6 + 0x5c))();
                if (iVar8 == 0) {
                  iVar16 = FUN_00105594(iVar11,iVar9);
                  if (*(int *)(param_5 + 0x478) < *(int *)(iVar16 + 0x160)) {
                    iVar8 = *(int *)(iVar11 + 0x84);
                    *(int *)(iVar16 + 0x160) = *(int *)(iVar16 + 0x160) + 1;
                  }
                  else {
                    iVar8 = *(int *)(iVar11 + 0x84);
                    *(int *)(iVar16 + 0x160) = *(int *)(param_5 + 0x478) + 1;
                  }
                }
                else {
                  uVar18 = FUN_00105594(iVar11,iVar9);
                  iVar8 = FUN_0010445c(uVar18,*(undefined4 *)(param_5 + 8),0);
                  FUN_00106004(iVar11,iVar9,iVar8,0,*(undefined4 *)(param_5 + 8));
                  FUN_000e7700(*(undefined4 *)(iVar11 + 0x158),iVar11,iVar8);
                  if (0 < *(int *)(iVar8 + 0x84)) {
                    iVar16 = 1;
                    do {
                      iVar12 = FUN_00105594(iVar8,iVar16);
                      if (*(int *)(param_5 + 0x478) < *(int *)(iVar12 + 0x160)) {
                        *(int *)(iVar12 + 0x160) = *(int *)(iVar12 + 0x160) + 1;
                      }
                      else {
                        *(int *)(iVar12 + 0x160) = *(int *)(param_5 + 0x478) + 1;
                      }
                      iVar16 = iVar16 + 1;
                    } while (iVar16 <= *(int *)(iVar8 + 0x84));
                  }
                  iVar8 = *(int *)(iVar11 + 0x84);
                }
              }
              iVar9 = iVar9 + 1;
            } while (iVar9 <= iVar8);
          }
          break;
        }
      }
    }
  }
  iVar3 = FUN_000e07dc(*(undefined4 *)(param_5 + 8),0x3a);
  if (iVar3 == 0) {
    return uVar5;
  }
  if ((*(int *)(param_5 + 0x228) < *(int *)(*(int *)(param_5 + 8) + 0x664)) &&
     (iVar3 = FUN_0015ea3c(param_2,param_3,piVar4,param_5), iVar3 != 0)) {
    uVar5 = 1;
    piVar4 = (int *)FUN_00146610(param_2,param_3,piVar4);
  }
  iVar3 = FUN_0015f44c(param_2,param_3,piVar4,param_5);
  if (iVar3 != 0) {
    FUN_00146610(param_2,param_3,piVar4);
    return 1;
  }
  return uVar5;
}

/* FUN_00193944 @ 0x193944 (112 bytes) */
int FUN_00193944(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  int param_3;
  undefined4 *param_4;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_3 + 0x88) + 8);
  iVar1 = (**(code **)(*param_2 + 0x24))(param_2);
  if ((iVar1 == 0) || (3 < iVar3 - 0x9eU)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    *param_4 = 2;
  }
  return uVar2;
}

/* FUN_00193a00 @ 0x193a00 (140 bytes) */
int FUN_00193a00(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_000e07dc(*(undefined4 *)(param_2 + 8),0x4a);
  if (iVar1 != 0) {
    piVar2 = *(int **)(param_2 + 900);
    iVar1 = piVar2[2];
    while (iVar1 != 0) {
      iVar1 = (**(code **)(*piVar2 + 0x24))(piVar2);
      if (iVar1 != 0) {
        piVar2 = (int *)FUN_0012bb48(param_2,piVar2);
      }
      piVar2 = (int *)piVar2[2];
      iVar1 = piVar2[2];
    }
  }
  return;
}

/* FUN_00193ae4 @ 0x193ae4 (88 bytes) */
int FUN_00193ae4(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  
  param_1[1] = param_3;
  *param_1 = param_4;
  param_1[2] = param_2;
  if (param_2 < 3) {
    param_1[5] = 0;
  }
  else {
    iVar1 = ((int (*)())FUN_00193e18)(*(undefined4 *)(param_4 + 0x370),param_2 << 2);
    param_1[5] = iVar1;
  }
  return;
}

/* FUN_00193b3c @ 0x193b3c (116 bytes) */
int FUN_00193b3c(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_3 + 0x370);
  puVar1 = (undefined4 *)((int (*)())FUN_00193e18)(uVar2,0x1c);
  *puVar1 = uVar2;
  ((int (*)())FUN_00193ae4)(puVar1 + 1,1,0x22,param_3);
  puVar1[4] = param_1;
  puVar1[3] = 1;
  puVar1[5] = param_2;
  return puVar1 + 1;
}

/* FUN_00193be8 @ 0x193be8 (24 bytes) */
int FUN_00193be8(param_1)
  int *param_1;
{
  if (param_1[5] == 0) {
    return;
  }
  ((int (*)())FUN_00193cc0)(*(undefined4 *)(*param_1 + 0x370));
  return;
}

/* FUN_00193c00 @ 0x193c00 (160 bytes) */
int FUN_00193c00(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 4;
  cVar1 = *(char *)(param_1 + 5);
  if ((cVar1 != '\x01') && (iVar3 = 0x10, cVar1 != '\x02')) {
    iVar3 = (uint)(cVar1 == '\0') << 1;
  }
  uVar4 = *(undefined4 *)(param_2 + 0x370);
  puVar2 = (undefined4 *)((int (*)())FUN_00193e18)(uVar4,0x1c);
  *puVar2 = uVar4;
  ((int (*)())FUN_00193ae4)(puVar2 + 1,1,iVar3,param_2);
  puVar2[4] = param_1;
  puVar2[3] = 1;
  puVar2[5] = 0;
  return puVar2 + 1;
}

/* FUN_00193cc0 @ 0x193cc0 (88 bytes) */
int FUN_00193cc0(param_1, param_2)
  int param_1;
  void *param_2;
{
  void *pvVar1;
  
  if ((*(int *)(param_1 + 0x28) != 0) && (pvVar1 = *(void **)(param_1 + 0x14), pvVar1 == param_2)) {
    _memset(pvVar1,0,*(int *)(param_1 + 8) - (int)pvVar1);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x14);
  }
  return;
}

/* FUN_00193d18 @ 0x193d18 (124 bytes) */
int FUN_00193d18(param_1)
  int *param_1;
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)param_1[1];
  while (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    (**(code **)(*param_1 + 0x34c))(*(undefined4 *)(*param_1 + 0x354),piVar1);
    piVar1 = (int *)iVar2;
  }
  param_1[3] = 0;
  param_1[1] = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[2] = 0;
  return;
}

/* FUN_00193d98 @ 0x193d98 (128 bytes) */
int FUN_00193d98(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 uVar5;
  
  puVar1 = (undefined *)(param_2 + 3U & 0xfffffffc);
  puVar4 = ((unsigned char *)0x00002fd8);
  if (0x2fd7 < (int)puVar1) {
    puVar4 = puVar1;
  }
  uVar5 = param_1[1];
  puVar2 = (undefined4 *)FUN_000e1564(*param_1,puVar4 + 8);
  param_1[1] = puVar2;
  *puVar2 = uVar5;
  *(undefined **)(param_1[1] + 4) = puVar4 + 8;
  iVar3 = param_1[1] + 8;
  param_1[5] = iVar3;
  param_1[4] = puVar4 + param_1[1] + 8;
  param_1[2] = iVar3;
  return;
}

/* FUN_00193e18 @ 0x193e18 (92 bytes) */
int FUN_00193e18(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  
  uVar1 = param_2 + 3U & 0xfffffffc;
  if (*(uint *)(param_1 + 0x10) < uVar1 + *(int *)(param_1 + 8)) {
    ((int (*)())FUN_00193d98)(param_1,uVar1);
  }
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 8);
  *(uint *)(param_1 + 8) = uVar1 + *(int *)(param_1 + 8);
  return;
}

/* FUN_00193e74 @ 0x193e74 (68 bytes) */
int FUN_00193e74(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  void *pvVar1;
  
  pvVar1 = (void *)((int (*)())FUN_00193e18)(param_1,param_2 * param_3);
  _memset(pvVar1,0,param_2 * param_3);
  return pvVar1;
}

/* FUN_00193f08 @ 0x193f08 (24 bytes) */
int FUN_00193f08(param_1)
  int param_1;
{
  return *(int *)(param_1 + 8) == param_1 + 0xc;
}

/* FUN_00193f20 @ 0x193f20 (36 bytes) */
int FUN_00193f20(param_1)
  int *param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[2];
  iVar1 = *param_1;
  *(int *)(iVar2 + 4) = param_1[1];
  *(int *)(param_1[1] + 8) = iVar2;
                    
                    
  (**(code **)(iVar1 + 4))();
  return;
}

/* FUN_00193f44 @ 0x193f44 (32 bytes) */
int FUN_00193f44(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 4);
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 != 0) {
    *(int *)(iVar1 + 8) = param_1;
  }
  *(int *)(param_2 + 4) = param_1;
  *(int *)(param_1 + 8) = param_2;
  return;
}

/* FUN_00193f64 @ 0x193f64 (16 bytes) */
int FUN_00193f64(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_00193f44)(param_2,param_1 + 0xc);
  return;
}

/* FUN_00193f74 @ 0x193f74 (32 bytes) */
int FUN_00193f74(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 8);
  *(int *)(param_1 + 8) = iVar1;
  if (iVar1 != 0) {
    *(int *)(iVar1 + 4) = param_1;
  }
  *(int *)(param_2 + 8) = param_1;
  *(int *)(param_1 + 4) = param_2;
  return;
}

/* FUN_00193f94 @ 0x193f94 (16 bytes) */
int FUN_00193f94(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_00193f74)(param_2,param_1);
  return;
}

/* FUN_00193fa4 @ 0x193fa4 (16 bytes) */
int FUN_00193fa4(param_1)
  int param_1;
{
  *(int *)(param_1 + 0x10) = param_1;
  *(int *)(param_1 + 8) = param_1 + 0xc;
  return;
}

/* FUN_00193fb4 @ 0x193fb4 (104 bytes) */
int FUN_00193fb4(param_1)
  int param_1;
{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  while (piVar1 != (int *)(param_1 + 0xc)) {
    piVar2 = (int *)piVar1[2];
    (**(code **)(*piVar1 + 4))(piVar1);
    piVar1 = piVar2;
  }
  ((int (*)())FUN_00193fa4)(param_1);
  return;
}

/* FUN_0019401c @ 0x19401c (24 bytes) */
int FUN_0019401c(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 8);
  *(int *)(*(int *)(param_1 + 8) + 4) = iVar1;
  return;
}

/* FUN_00194034 @ 0x194034 (44 bytes) */
int FUN_00194034(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (iVar1 = *(int *)(param_1 + 8); iVar1 != param_1 + 0xc; iVar1 = *(int *)(iVar1 + 8)) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

/* FUN_00194060 @ 0x194060 (72 bytes) */
int FUN_00194060(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  param_1[4] = 0;
  puVar1 = PTR_DAT_001e8b48;
  param_1[5] = 0;
  param_1[5] = 0;
  param_1[3] = puVar1 + 8;
  param_1[2] = param_1 + 3;
  *param_1 = puVar1 + 8;
  param_1[1] = 0;
  param_1[4] = param_1;
  return;
}

/* FUN_001940a8 @ 0x1940a8 (72 bytes) */
int FUN_001940a8(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  param_1[4] = 0;
  puVar1 = PTR_DAT_001e8b48;
  param_1[5] = 0;
  param_1[5] = 0;
  param_1[3] = puVar1 + 8;
  param_1[2] = param_1 + 3;
  *param_1 = puVar1 + 8;
  param_1[1] = 0;
  param_1[4] = param_1;
  return;
}

/* FUN_001940f0 @ 0x1940f0 (280 bytes) */
int FUN_001940f0(param_1, param_2)
  int param_1;
  code *param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  uVar1 = 1;
  iVar8 = *(int *)(param_1 + 8);
  uVar3 = *(uint *)(param_1 + 4);
  do {
    uVar1 = uVar1 * 3 + 1;
  } while (uVar1 < uVar3);
  do {
    do {
      uVar1 = uVar1 / 3;
      if (uVar1 == 0) {
        return;
      }
    } while (uVar3 <= uVar1);
    puVar4 = (undefined4 *)(iVar8 + uVar1 * 4);
    iVar7 = 0;
    uVar5 = uVar1;
    do {
      uVar6 = *puVar4;
      for (iVar9 = iVar7; -1 < iVar9; iVar9 = iVar9 - uVar1) {
        iVar2 = (*param_2)(*(undefined4 *)(iVar8 + iVar9 * 4),uVar6);
        if (iVar2 < 1) break;
        *(undefined4 *)((uVar1 + iVar9) * 4 + iVar8) = *(undefined4 *)(iVar8 + iVar9 * 4);
      }
      uVar5 = uVar5 + 1;
      iVar7 = iVar7 + 1;
      *(undefined4 *)(iVar8 + (uVar1 + iVar9) * 4) = uVar6;
      puVar4 = puVar4 + 1;
      uVar3 = *(uint *)(param_1 + 4);
    } while (uVar5 < uVar3);
  } while( true );
}

/* FUN_00194208 @ 0x194208 (52 bytes) */
int FUN_00194208(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  void *pvVar2;
  
  if (*(uint *)(param_1 + 4) <= param_2) {
    return;
  }
  iVar1 = *(uint *)(param_1 + 4) - 1;
  pvVar2 = (void *)(param_2 * 4 + *(int *)(param_1 + 8));
  *(int *)(param_1 + 4) = iVar1;
  _memcpy(pvVar2,(void *)((int)pvVar2 + 4),(iVar1 - param_2) * 4);
  return;
}

/* FUN_0019423c @ 0x19423c (152 bytes) */
int FUN_0019423c(param_1, param_2)
  uint *param_1;
  uint param_2;
{
  uint uVar1;
  void *pvVar2;
  void *pvVar3;
  
  uVar1 = *param_1;
  if (uVar1 <= param_2) {
    do {
      uVar1 = uVar1 << 1;
    } while (uVar1 <= param_2);
    *param_1 = uVar1;
  }
  pvVar3 = (void *)param_1[2];
  pvVar2 = (void *)((int (*)())FUN_00193e18)(param_1[3],uVar1 << 2);
  param_1[2] = (uint)pvVar2;
  _memcpy(pvVar2,pvVar3,param_1[1] << 2);
  ((int (*)())FUN_00193cc0)(param_1[3],pvVar3);
  if (param_1[1] < param_2 + 1) {
    param_1[1] = param_2 + 1;
  }
  return param_2 * 4 + param_1[2];
}

/* FUN_001942d4 @ 0x1942d4 (160 bytes) */
int FUN_001942d4(param_1, param_2)
  uint *param_1;
  uint param_2;
{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  uVar2 = param_1[1];
  if (param_1[1] < param_2) {
    uVar2 = param_2;
  }
  if (*param_1 < uVar2 + 1) {
    ((int (*)())FUN_0019423c)(param_1,uVar2);
  }
  else {
    param_1[1] = uVar2 + 1;
  }
  iVar1 = (param_1[1] - param_2) + -1;
  puVar3 = (undefined4 *)(param_2 * 4 + param_1[2] + iVar1 * 4);
  if (iVar1 != 0) {
    iVar1 = (param_1[1] - param_2) + -1;
    puVar4 = puVar3;
    do {
      puVar3 = puVar4 + -1;
      *puVar4 = *puVar3;
      iVar1 = iVar1 + -1;
      puVar4 = puVar3;
    } while (iVar1 != 0);
  }
  *puVar3 = 0;
  return;
}

/* FUN_00194374 @ 0x194374 (124 bytes) */
int FUN_00194374(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == 0) {
LAB_001943c4:
    uVar2 = 0;
  }
  else {
    iVar3 = 0;
    if (param_2 != **(int **)(param_1 + 8)) {
      iVar3 = 0;
      do {
        iVar3 = iVar3 + 1;
        iVar1 = iVar1 + -1;
        if (iVar1 == 0) goto LAB_001943c4;
      } while (param_2 != (*(int **)(param_1 + 8))[iVar3]);
    }
    ((int (*)())FUN_00194208)(param_1,iVar3);
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_001943f0 @ 0x1943f0 (276 bytes) */
int FUN_001943f0(param_1)
  uint *param_1;
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  
  uVar1 = *param_1;
  if (uVar1 == 0) {
    uVar3 = param_1[2];
  }
  else {
    uVar3 = param_1[2];
    uVar5 = 0;
    do {
      puVar6 = *(uint **)(uVar3 + uVar5 * 4);
      if (puVar6 != (uint *)0x0) {
        uVar1 = puVar6[1];
        if (uVar1 != 0) {
          uVar3 = 0;
          do {
            if (uVar3 < *puVar6) {
              if (uVar1 <= uVar3) {
                _memset((void *)(uVar1 * 4 + puVar6[2]),0,(uVar3 - uVar1) * 4 + 4);
                puVar6[1] = uVar3 + 1;
              }
              piVar2 = (int *)(uVar3 * 4 + puVar6[2]);
            }
            else {
              piVar2 = (int *)((int (*)())FUN_0019423c)(puVar6,uVar3);
            }
            uVar3 = uVar3 + 1;
            iVar4 = *piVar2;
            if (iVar4 != 0) {
              ((int (*)())FUN_00193cc0)(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
            }
            uVar1 = puVar6[1];
          } while (uVar3 < uVar1);
          uVar3 = param_1[2];
        }
        ((int (*)())FUN_00193cc0)(param_1[5],*(undefined4 *)(uVar3 + uVar5 * 4));
        uVar1 = *param_1;
        uVar3 = param_1[2];
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  ((int (*)())FUN_00193cc0)(param_1[5],uVar3);
  return;
}

/* FUN_00194504 @ 0x194504 (276 bytes) */
int FUN_00194504(param_1)
  uint *param_1;
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  
  uVar1 = *param_1;
  if (uVar1 == 0) {
    uVar3 = param_1[2];
  }
  else {
    uVar3 = param_1[2];
    uVar5 = 0;
    do {
      puVar6 = *(uint **)(uVar3 + uVar5 * 4);
      if (puVar6 != (uint *)0x0) {
        uVar1 = puVar6[1];
        if (uVar1 != 0) {
          uVar3 = 0;
          do {
            if (uVar3 < *puVar6) {
              if (uVar1 <= uVar3) {
                _memset((void *)(uVar1 * 4 + puVar6[2]),0,(uVar3 - uVar1) * 4 + 4);
                puVar6[1] = uVar3 + 1;
              }
              piVar2 = (int *)(uVar3 * 4 + puVar6[2]);
            }
            else {
              piVar2 = (int *)((int (*)())FUN_0019423c)(puVar6,uVar3);
            }
            uVar3 = uVar3 + 1;
            iVar4 = *piVar2;
            if (iVar4 != 0) {
              ((int (*)())FUN_00193cc0)(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
            }
            uVar1 = puVar6[1];
          } while (uVar3 < uVar1);
          uVar3 = param_1[2];
        }
        ((int (*)())FUN_00193cc0)(param_1[5],*(undefined4 *)(uVar3 + uVar5 * 4));
        uVar1 = *param_1;
        uVar3 = param_1[2];
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  ((int (*)())FUN_00193cc0)(param_1[5],uVar3);
  return;
}

