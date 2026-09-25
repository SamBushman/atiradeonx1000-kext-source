#include "decls.h"

/* FUN_00186510 @ 0x186510 (1400 bytes) */
int FUN_00186510(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  int param_4;
{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  undefined1 *puVar11;
  int iVar12;
  int local_78;
  uint local_74;
  uint local_70;
  int local_6c;
  uint local_68;
  undefined4 local_64;
  int local_60;
  undefined4 uStack_5c;
  int local_58 [4];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  iVar5 = FUN_001054ec(param_1,1);
  local_60 = *(int *)(iVar5 + 0x10);
  iVar5 = FUN_001054ec(param_1,2);
  local_78 = *(int *)(iVar5 + 0x10);
  if (local_60 == local_78) {
    return 1;
  }
  iVar5 = FUN_001054ec(param_1,0);
  iVar8 = 0;
  local_64 = *(undefined4 *)(iVar5 + 0x10);
  do {
    iVar5 = 0;
    pcVar4 = &DAT_001b0228 + iVar8 * 4;
    iVar12 = 4;
    while ((*(char *)((int)&local_64 + iVar5) != '\0' ||
           ((*(char *)((int)&local_78 + iVar5) == *(char *)((int)&local_60 + iVar5) &&
            (*(char *)((int)&local_78 + iVar5) == *pcVar4))))) {
      iVar5 = iVar5 + 1;
      pcVar4 = pcVar4 + 1;
      iVar12 = iVar12 + -1;
      if (iVar12 == 0) {
        return 1;
      }
    }
    bVar1 = iVar8 != 4;
    iVar8 = iVar8 + 1;
  } while (bVar1);
  iVar5 = FUN_000f31e8(param_1,1);
  if ((iVar5 == 0) && (iVar5 = FUN_000f31e8(param_1,2), iVar5 == 0)) {
    *(int *)(*(int *)(param_4 + 0x6c4) + 0x204) = *(int *)(*(int *)(param_4 + 0x6c4) + 0x204) + 1;
    return 0;
  }
  piVar9 = (int *)*param_2;
  iVar8 = 1;
  piVar10 = (int *)*param_3;
  iVar5 = FUN_000f31e8(param_1,1);
  if (iVar5 != 0) {
    iVar8 = 2;
    local_60 = local_78;
    piVar9 = piVar10;
  }
  iVar12 = *(int *)(param_4 + 0x6c4);
  iVar5 = FUN_001054ec(param_1,0);
  local_74 = *(uint *)(iVar5 + 0x10);
  iVar5 = FUN_001054ec(piVar9,0);
  local_70 = *(uint *)(iVar5 + 0x10);
  local_6c = DAT_001b0224;
  if ((piVar9[5] & 0x200U) != 0) {
    *(int *)(*(int *)(param_4 + 0x6c4) + 0x204) = *(int *)(*(int *)(param_4 + 0x6c4) + 0x204) + 1;
    iVar5 = FUN_001054ec(piVar9,piVar9[0x21]);
    iVar6 = 0;
    local_6c = *(int *)(iVar5 + 0x10);
    iVar5 = 4;
    do {
      if ((*(byte *)((int)&local_60 + iVar6) != 4) &&
         (*(char *)((int)&local_6c + (uint)*(byte *)((int)&local_60 + iVar6)) != '\x04')) {
        bVar1 = false;
        goto LAB_00186708;
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  bVar1 = true;
LAB_00186708:
  local_68 = DAT_001b0220;
  if (bVar1) {
    iVar5 = FUN_0011379c(param_4,piVar9);
    if (iVar5 == 0) {
      iVar5 = FUN_001131c0(*(undefined4 *)(piVar9[0x22] + 8),param_4);
      if (iVar5 == 0) goto LAB_00186a60;
      iVar5 = FUN_0010497c(piVar9,iVar12);
      uVar3 = DAT_001b0220;
      if (iVar5 == 0) {
        iVar5 = 0;
        iVar6 = 4;
        do {
          if (((*(char *)((int)&local_74 + iVar5) == '\0') &&
              (*(char *)((int)&local_70 + iVar5) != '\0')) &&
             ((*(char *)((int)&local_70 + iVar5) != '\x01' ||
              (*(char *)((int)&local_6c + iVar5) != '\x04')))) goto LAB_00186a60;
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        uVar7 = (local_74 << 0x18 | (local_74 >> 8 & 0xff) << 0x10 | (local_74 >> 0x10 & 0xff) << 8
                | local_74 >> 0x18) &
                (local_70 << 0x18 | (local_70 >> 8 & 0xff) << 0x10 | (local_70 >> 0x10 & 0xff) << 8
                | local_70 >> 0x18);
        local_68 = uVar7 << 0x18 | (uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 | uVar7 >> 0x18;
      }
      else {
        local_68 = local_74;
      }
      piVar9[0x27] = local_68;
      FUN_000f3908(&local_40,local_68);
      FUN_000f3340(local_3c,uVar3,local_40);
    }
    else {
      iVar5 = FUN_0010497c(piVar9,iVar12);
      if (iVar5 == 0) {
        iVar5 = 0;
        iVar6 = 4;
        do {
          if ((*(char *)((int)&local_74 + iVar5) == '\0') &&
             ((*(char *)((int)&local_70 + iVar5) != '\x01' ||
              (*(char *)((int)&local_6c + iVar5) != '\x04')))) goto LAB_00186a60;
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        uVar7 = (local_74 << 0x18 | (local_74 >> 8 & 0xff) << 0x10 | (local_74 >> 0x10 & 0xff) << 8
                | local_74 >> 0x18) &
                (local_70 << 0x18 | (local_70 >> 8 & 0xff) << 0x10 | (local_70 >> 0x10 & 0xff) << 8
                | local_70 >> 0x18);
        local_68 = uVar7 << 0x18 | (uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 | uVar7 >> 0x18;
      }
      else {
        local_68 = local_74;
      }
      iVar5 = FUN_000f2e18(local_68);
      if (iVar5 == 0) goto LAB_00186a60;
      iVar6 = 1;
      piVar9[0x27] = local_68;
      iVar5 = FUN_0010497c(piVar9,iVar12);
      if (iVar5 == 0) {
        for (; iVar5 = (**(code **)(*piVar9 + 0x14))(piVar9), iVar6 <= iVar5; iVar6 = iVar6 + 1) {
          iVar5 = FUN_001054ec(piVar9,iVar6);
          (&uStack_5c)[iVar6] = *(undefined4 *)(iVar5 + 0x10);
        }
      }
      else {
        piVar10 = local_58;
        for (; iVar5 = (**(code **)(*piVar9 + 0x14))(piVar9), iVar6 <= iVar5; iVar6 = iVar6 + 1) {
          *piVar10 = DAT_001b0224;
          piVar10 = piVar10 + 1;
        }
      }
      iVar5 = FUN_001054ec(param_1,iVar8);
      iVar12 = 0;
      local_64 = *(undefined4 *)(iVar5 + 0x10);
      do {
        if (*(char *)((int)&local_74 + iVar12) == '\0') {
          iVar5 = 1;
          puVar11 = (undefined1 *)((int)local_58 + iVar12);
          while( true ) {
            iVar6 = (**(code **)(*piVar9 + 0x14))(piVar9);
            if (iVar6 < iVar5) break;
            bVar2 = *(byte *)((int)&local_64 + iVar12);
            iVar6 = FUN_001054ec(piVar9,iVar5);
            *puVar11 = *(undefined1 *)((uint)bVar2 + iVar6 + 0x10);
            iVar5 = iVar5 + 1;
            puVar11 = puVar11 + 4;
          }
        }
        bVar1 = iVar12 != 3;
        iVar12 = iVar12 + 1;
      } while (bVar1);
      piVar10 = local_58;
      for (iVar5 = 1; iVar12 = (**(code **)(*piVar9 + 0x14))(piVar9), uVar3 = DAT_001b0220,
          iVar5 <= iVar12; iVar5 = iVar5 + 1) {
        iVar12 = *piVar10;
        if (iVar5 == 0) {
          piVar9[0x27] = iVar12;
        }
        else {
          iVar6 = FUN_001054ec(piVar9,iVar5);
          *(int *)(iVar6 + 0x10) = iVar12;
        }
        piVar10 = piVar10 + 1;
      }
      FUN_000f3908(&local_48,local_74);
      FUN_000f3340(&local_44,uVar3,local_48);
      local_3c[0] = local_44;
    }
    if (iVar8 == 0) {
      uVar3 = 1;
      *(undefined4 *)(param_1 + 0x9c) = local_3c[0];
    }
    else {
      iVar5 = FUN_001054ec(param_1,iVar8);
      uVar3 = 1;
      *(undefined4 *)(iVar5 + 0x10) = local_3c[0];
    }
  }
  else {
LAB_00186a60:
    uVar3 = 0;
    *(int *)(iVar12 + 0x204) = *(int *)(iVar12 + 0x204) + 1;
  }
  return uVar3;
}

/* FUN_00186a88 @ 0x186a88 (2816 bytes) */
int FUN_00186a88(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  int *param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int *piVar10;
  int *piVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int *local_a8;
  int *local_a4 [10];
  int local_7c [4];
  int local_6c;
  float local_68;
  
  local_a4[9] = (int *)0x3f800000;
  local_a4[5] = (int *)0x3f000000;
  local_a4[6] = (int *)0x3f800000;
  local_a4[7] = (int *)0x3f800000;
  local_a4[8] = (int *)0x3f800000;
  local_a4[2] = (int *)0x3f000000;
  local_a4[3] = (int *)0x3f000000;
  local_a4[4] = (int *)0x3f000000;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar7 = param_4;
  uVar9 = param_5;
  uVar8 = param_6;
  FUN_00105594(param_1,param_2);
  iVar4 = (**(code **)(*param_1 + 0x14))(param_1);
  if (iVar4 < param_2) {
    return 0;
  }
  iVar4 = (**(code **)(*param_1 + 0x5c))(param_1);
  if (iVar4 != 0) {
    return 0;
  }
  iVar4 = (**(code **)(*param_1 + 0x28))(param_1);
  if (iVar4 != 0) {
    return 0;
  }
  if ((param_1[5] & 2U) != 0) {
    return 0;
  }
  iVar4 = (**(code **)(*param_1 + 100))(param_1);
  if (iVar4 != 0) {
    for (iVar4 = 1; iVar5 = (**(code **)(*param_1 + 0x14))(param_1), iVar4 <= iVar5;
        iVar4 = iVar4 + 1) {
      if ((((param_1[iVar4 * 6 + 0x28] & 1U) != 0) || ((param_1[iVar4 * 6 + 0x28] & 2U) != 0)) ||
         (iVar5 = FUN_000f31e8(param_1,iVar4), iVar5 == 0)) goto LAB_001874d4;
    }
    if ((param_1[0x48] == 0) && (param_1[0x49] == 0)) {
      if (((param_1[0x20] != 0) &&
          ((iVar4 = FUN_00126760(param_1[0x26]), iVar4 != 0 && ((param_1[5] & 2U) == 0)))) &&
         (iVar4 = (**(code **)(*param_1 + 0x50))(param_1), iVar4 == 0)) {
        iVar4 = 4;
        piVar10 = param_1;
        do {
          if (*(byte *)(piVar10 + 0x27) - 2 < 2) goto LAB_001874d4;
          piVar10 = (int *)((int)piVar10 + 1);
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      FUN_001054ec(param_1,0);
      iVar4 = FUN_00105dbc(param_1,0);
      if (((iVar4 == 0) && ((param_1[5] & 2U) == 0)) && ((param_1[5] & 0x200U) == 0)) {
        return 0;
      }
    }
  }
LAB_001874d4:
  if (*(int *)(param_1[0x22] + 8) == 0x8e) {
    return 0;
  }
  iVar4 = (**(code **)(*param_3 + 0x5c))(param_3);
  if (iVar4 != 0) {
    return 0;
  }
  if (param_3[0x48] != 0) {
    return 0;
  }
  iVar4 = ((int (*)())FUN_001897fc)(param_1,param_2);
  if (iVar4 != 0) {
    return 0;
  }
  uVar2 = param_3[5];
  piVar10 = (int *)0x0;
  if ((uVar2 & 0x200) != 0) {
    iVar5 = param_3[1];
    FUN_0019401c(param_3);
    local_a8 = (int *)FUN_0010445c(param_3,*(undefined4 *)(param_4 + 8),1);
    iVar4 = FUN_00162dfc(&local_a8,1,param_4);
    if (iVar4 == 0) {
      FUN_000e7738(*(undefined4 *)(iVar5 + 0x158),iVar5,param_3);
      return 0;
    }
    FUN_000e7738(*(undefined4 *)(iVar5 + 0x158),iVar5,local_a8);
    FUN_000e7738(*(undefined4 *)(iVar5 + 0x158),local_a8,param_3);
    uVar2 = local_a8[5];
    piVar10 = param_3;
    param_3 = local_a8;
  }
  if ((uVar2 & 0x200) != 0) {
    return 0;
  }
  if (0 < param_3[0x21]) {
    iVar4 = 1;
    do {
      piVar6 = (int *)FUN_00105594(param_3,iVar4);
      iVar5 = (**(code **)(*piVar6 + 0x60))();
      if (iVar5 != 0) {
        return 0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= param_3[0x21]);
  }
  iVar5 = FUN_001054ec(param_3,0);
  iVar4 = param_3[0x22];
  uVar12 = *(undefined4 *)(iVar5 + 0x10);
  if (*(int *)(iVar4 + 8) == 0x12) {
    local_a8 = (int *)FUN_00105594(param_3,1);
    iVar4 = FUN_001267b8(local_a8[0x26]);
    if (iVar4 == 0) {
      if (local_a8[0x26] == 0x33) {
        iVar4 = FUN_001054ec(param_3,1);
        iVar5 = 0;
        local_a4[0] = *(int **)(iVar4 + 0x10);
        iVar4 = 4;
        piVar6 = local_7c;
        do {
          uVar2 = (uint)*(byte *)(iVar5 + (int)local_a4);
          if (uVar2 != 4) {
            *piVar6 = local_a8[uVar2 * 6 + 8];
          }
          iVar5 = iVar5 + 1;
          piVar6 = piVar6 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        uVar13 = *(undefined4 *)(param_4 + 0x3ac);
        local_a8 = (int *)FUN_000f5f94(uVar13,local_7c,local_a4,iVar7,uVar9,uVar8,piVar6);
        if (local_a8 == (int *)0x0) {
          local_a8 = (int *)FUN_000f57f0(uVar13,local_7c,local_a4,iVar7);
        }
        piVar6 = local_a4;
        if (local_a8 == (int *)0x0) {
          return 0;
        }
        iVar7 = FUN_001054ec(param_3,1);
        *(int **)(iVar7 + 0x10) = piVar6;
        uVar9 = *(undefined4 *)(param_4 + 8);
        FUN_00106004(param_3,1,local_a8,0,uVar9);
      }
      else {
        local_a8 = (int *)0x0;
      }
    }
    if (local_a8 == (int *)0x0) {
      return 0;
    }
    iVar7 = (**(code **)(*local_a8 + 0x5c))();
    if (iVar7 != 0) {
      return 0;
    }
    if ((param_3[0x2e] & 2U) != 0) {
      return 0;
    }
    if (param_3[0x49] != 0) {
      return 0;
    }
    piVar6 = &local_6c;
    iVar7 = FUN_000f5cf0(param_3,2,uVar12,piVar6);
    if ((iVar7 == 0) || (bVar1 = true, local_6c != 2)) {
      bVar1 = false;
    }
    if (bVar1) {
      if ((local_68 == FLOAT_001aa0e8) || (local_68 == FLOAT_001aa114)) {
        uVar2 = (uint)(local_68 == FLOAT_001aa114);
        if (uVar2 == (param_3[0x2e] & 1U)) {
          return 0;
        }
        iVar4 = FUN_001043f0(0x9c,*(undefined4 *)(param_4 + 8));
        uVar9 = *(undefined4 *)(iVar4 + 0x14c);
        iVar7 = FUN_001054ec(iVar4,0);
        *(undefined4 *)(iVar7 + 0xc) = 0x31;
        *(undefined4 *)(iVar7 + 8) = uVar9;
        uVar9 = *(undefined4 *)(param_4 + 8);
        piVar6 = local_a8;
        goto LAB_00187498;
      }
      if ((((local_68 == FLOAT_001aa10c) || (local_68 == FLOAT_001aa174)) &&
          (iVar7 = FUN_00184cd8(param_1,param_2,param_4), iVar7 != 0)) &&
         ((param_3[0x2e] & 1U) == (uint)(local_68 == FLOAT_001aa10c))) {
        iVar7 = FUN_001043f0(0x99,*(undefined4 *)(param_4 + 8));
        uVar9 = *(undefined4 *)(iVar7 + 0x14c);
        iVar4 = FUN_001054ec(iVar7,0);
        *(undefined4 *)(iVar4 + 0xc) = 0x31;
        *(undefined4 *)(iVar4 + 8) = uVar9;
        uVar9 = FUN_00105594(param_3,1);
        FUN_00106004(iVar7,1,uVar9,0,*(undefined4 *)(param_4 + 8));
        iVar7 = FUN_00185da4(param_2,(uint)(local_68 == FLOAT_001aa174),param_1,iVar7,param_3,
                             param_4,param_5,param_6,param_7,piVar10);
        if (iVar7 != 0) {
          param_1[0x49] = param_1[0x49] + -1;
          return iVar7;
        }
        return 0;
      }
    }
    local_a4[1] = (int *)FUN_00105594(param_3,2);
    iVar7 = FUN_001267b8(local_a4[1][0x26]);
    if (iVar7 == 0) {
      if (local_a4[1][0x26] == 0x33) {
        iVar7 = FUN_001054ec(param_3,2);
        iVar4 = 0;
        local_a4[0] = *(int **)(iVar7 + 0x10);
        iVar7 = 4;
        piVar11 = local_7c;
        do {
          uVar2 = (uint)*(byte *)(iVar4 + (int)local_a4);
          if (uVar2 != 4) {
            *piVar11 = local_a4[1][uVar2 * 6 + 8];
          }
          iVar4 = iVar4 + 1;
          piVar11 = piVar11 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        uVar12 = *(undefined4 *)(param_4 + 0x3ac);
        local_a4[1] = (int *)FUN_000f5f94(uVar12,local_7c,local_a4,piVar6,uVar9,uVar8,piVar11);
        if (local_a4[1] == (int *)0x0) {
          local_a4[1] = (int *)FUN_000f57f0(uVar12,local_7c,local_a4,piVar6);
        }
        piVar6 = local_a4;
        if (local_a4[1] == (int *)0x0) {
          return 0;
        }
        iVar7 = FUN_001054ec(param_3,2);
        *(int **)(iVar7 + 0x10) = piVar6;
        FUN_00106004(param_3,2,local_a4[1],0,*(undefined4 *)(param_4 + 8));
      }
      else {
        local_a4[1] = (int *)0x0;
      }
    }
    if (((local_a4[1] == (int *)0x0) || ((param_3[0x34] & 2U) != 0)) ||
       ((iVar7 = (**(code **)(*local_a4[1] + 0x5c))(), iVar7 != 0 ||
        (iVar7 = ((int (*)())FUN_00186510)(param_3,&local_a8,local_a4 + 1,*(undefined4 *)(param_4 + 8)),
        iVar7 == 0)))) {
      return 0;
    }
    if ((param_3[0x2e] & 1U) == (param_3[0x34] & 1U)) {
      uVar8 = *(undefined4 *)(param_4 + 8);
      uVar9 = 0x9b;
    }
    else {
      uVar8 = *(undefined4 *)(param_4 + 8);
      uVar9 = 0x9a;
    }
    iVar4 = FUN_001043f0(uVar9,uVar8);
    uVar9 = *(undefined4 *)(iVar4 + 0x14c);
    iVar7 = FUN_001054ec(iVar4,0);
    *(undefined4 *)(iVar7 + 0xc) = 0x31;
    *(undefined4 *)(iVar7 + 8) = uVar9;
    FUN_00106004(iVar4,1,local_a8,0,*(undefined4 *)(param_4 + 8));
    FUN_00106004(iVar4,2,local_a4[1],0,*(undefined4 *)(param_4 + 8));
    uVar2 = param_3[0x2e] & 1;
  }
  else {
    if (*(int *)(iVar4 + 8) == 0x31) {
      iVar7 = FUN_00105594(param_3,1);
      uVar9 = 0;
      if (iVar7 != 0) {
        iVar7 = FUN_00105594(param_3,1);
        uVar9 = *(undefined4 *)(iVar7 + 0x98);
      }
      iVar7 = FUN_001267b8(uVar9);
      if ((iVar7 != 0) && ((param_3[0x2e] & 2U) == 0)) {
        piVar6 = (int *)FUN_00105594(param_3,1);
        iVar7 = (**(code **)(*piVar6 + 0x5c))();
        if ((iVar7 == 0) && (param_3[0x49] == 1)) {
          if ((param_3[0x2e] & 1U) == 0) {
            if ((param_3[0x34] & 1U) == 0) goto LAB_001872f8;
LAB_001872f0:
            uVar2 = 1;
          }
          else {
            if ((param_3[0x34] & 1U) == 0) goto LAB_001872f0;
LAB_001872f8:
            uVar2 = 0;
          }
          iVar4 = FUN_001043f0(0x9b,*(undefined4 *)(param_4 + 8));
          uVar9 = *(undefined4 *)(iVar4 + 0x14c);
          iVar7 = FUN_001054ec(iVar4,0);
          *(undefined4 *)(iVar7 + 0xc) = 0x31;
          *(undefined4 *)(iVar7 + 8) = uVar9;
          uVar9 = FUN_00105594(param_3,1);
          FUN_00106004(iVar4,1,uVar9,0,*(undefined4 *)(param_4 + 8));
          uVar9 = FUN_00105594(param_3,1);
          FUN_00106004(iVar4,2,uVar9,0,*(undefined4 *)(param_4 + 8));
          goto LAB_0018754c;
        }
      }
      iVar4 = param_3[0x22];
    }
    if (*(int *)(iVar4 + 8) != 0x14) {
      return 0;
    }
    iVar7 = FUN_00105594(param_3,1);
    if (iVar7 == 0) {
      uVar9 = 0;
    }
    else {
      iVar7 = FUN_00105594(param_3,1);
      uVar9 = *(undefined4 *)(iVar7 + 0x98);
    }
    iVar7 = FUN_001267b8(uVar9);
    if (iVar7 == 0) {
      return 0;
    }
    if ((param_3[0x2e] & 2U) != 0) {
      return 0;
    }
    piVar6 = (int *)FUN_00105594(param_3,1);
    iVar7 = (**(code **)(*piVar6 + 0x5c))();
    if (iVar7 != 0) {
      return 0;
    }
    iVar7 = FUN_000f5c0c(param_3,2,uVar12,local_a4 + 6);
    if (iVar7 == 0) {
      return 0;
    }
    iVar7 = FUN_000f5c0c(param_3,3,uVar12,local_a4 + 2);
    if (iVar7 == 0) {
      return 0;
    }
    if (param_3[0x49] != 1) {
      return 0;
    }
    uVar2 = param_3[0x3a] & 1;
    if ((param_3[0x2e] & 1U) == 0) {
      if ((param_3[0x34] & 1U) == 0) goto LAB_0018744c;
LAB_00187444:
      uVar3 = 1;
    }
    else {
      if ((param_3[0x34] & 1U) == 0) goto LAB_00187444;
LAB_0018744c:
      uVar3 = 0;
    }
    if (uVar3 == uVar2) {
      return 0;
    }
    iVar4 = FUN_001043f0(0x99,*(undefined4 *)(param_4 + 8));
    uVar9 = *(undefined4 *)(iVar4 + 0x14c);
    iVar7 = FUN_001054ec(iVar4,0);
    *(undefined4 *)(iVar7 + 0xc) = 0x31;
    *(undefined4 *)(iVar7 + 8) = uVar9;
    piVar6 = (int *)FUN_00105594(param_3,1);
    uVar9 = *(undefined4 *)(param_4 + 8);
LAB_00187498:
    FUN_00106004(iVar4,1,piVar6,0,uVar9);
  }
LAB_0018754c:
  iVar7 = FUN_00185da4(param_2,uVar2,param_1,iVar4,param_3,param_4,param_5,param_6,param_7,piVar10);
  return iVar7;
}

/* FUN_001875a8 @ 0x1875a8 (1328 bytes) */
int FUN_001875a8(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c [5];
  
  if ((((((param_1 != (int *)0x0) && (*(int *)(*(int *)(param_3 + 0x88) + 8) == 0x12)) &&
        (*(int *)(param_1[0x22] + 8) == 0x12)) &&
       (((iVar4 = FUN_0010497c(param_3,param_4), iVar4 != 0 && (*(int *)(param_3 + 0x120) == 0)) &&
        ((*(int *)(param_3 + 0x124) == 0 && ((param_1[0x48] == 0 && (param_1[0x49] == 0)))))))) &&
      ((param_1[5] & 0x200U) == 0)) &&
     (((*(uint *)(param_3 + 0x14) & 0x200) == 0 && ((*(uint *)(param_3 + 0x14) & 0x40000) == 0)))) {
    iVar4 = FUN_001054ec(param_1,0);
    iVar13 = *(int *)(iVar4 + 0x10);
    iVar4 = FUN_001054ec(param_3,0);
    if (iVar13 != *(int *)(iVar4 + 0x10)) {
      iVar4 = FUN_001054ec(param_3,0);
      iVar4 = FUN_000f3824(*(undefined4 *)(iVar4 + 0x10));
      if (iVar4 == 0) goto LAB_00187a90;
    }
    iVar4 = FUN_000f31e8(param_1,param_2);
    if (iVar4 == 0) {
      iVar4 = (**(code **)(*param_1 + 0x60))(param_1);
      if (iVar4 != 0) {
        return 0;
      }
      iVar4 = FUN_001054ec(param_1,param_2);
      uVar12 = *(undefined4 *)(iVar4 + 0x10);
      iVar4 = FUN_001054ec(param_1,0);
      uVar10 = *(undefined4 *)(iVar4 + 0x10);
      *(undefined4 *)(param_3 + 0x9c) = uVar10;
      iVar4 = FUN_001054ec(param_3,1);
      FUN_000f2bdc(&local_68,*(undefined4 *)(iVar4 + 0x10),uVar12);
      iVar4 = FUN_001054ec(param_3,1);
      *(undefined4 *)(iVar4 + 0x10) = local_68;
      iVar4 = FUN_001054ec(param_3,2);
      FUN_000f2bdc(&local_64,*(undefined4 *)(iVar4 + 0x10),uVar12);
      iVar4 = FUN_001054ec(param_3,2);
      uVar12 = DAT_001b0220;
      *(undefined4 *)(iVar4 + 0x10) = local_64;
      FUN_000f3908(&local_60,uVar10);
      FUN_000f3340(local_5c,uVar12,local_60);
      if (param_2 == 0) {
        param_1[0x27] = local_5c[0];
      }
      else {
        iVar4 = FUN_001054ec(param_1,param_2);
        *(int *)(iVar4 + 0x10) = local_5c[0];
      }
    }
    piVar5 = (int *)FUN_00105594(param_3,1);
    FUN_001054ec(param_3,1);
    piVar6 = (int *)FUN_00105594(param_3,2);
    uVar1 = *(uint *)(param_3 + 0xd0) & 1;
    uVar8 = *(uint *)(param_3 + 0xd0) >> 1 & 1;
    iVar4 = FUN_001054ec(param_3,2);
    uVar12 = *(undefined4 *)(iVar4 + 0x10);
    iVar13 = (param_2 == 1) + 1;
    piVar7 = (int *)FUN_00105594(param_1,iVar13);
    uVar2 = param_1[iVar13 * 6 + 0x28] & 1;
    uVar9 = (uint)param_1[iVar13 * 6 + 0x28] >> 1 & 1;
    iVar4 = FUN_001054ec(param_1,iVar13);
    uVar10 = *(undefined4 *)(iVar4 + 0x10);
    iVar4 = (**(code **)(*piVar5 + 0x5c))(piVar5);
    if (iVar4 != 0) {
      return 0;
    }
    iVar4 = (**(code **)(*piVar6 + 0x5c))(piVar6);
    if (iVar4 != 0) {
      return 0;
    }
    iVar4 = (**(code **)(*piVar7 + 0x5c))(piVar7);
    if (iVar4 != 0) {
      return 0;
    }
    iVar4 = (**(code **)(*piVar7 + 0x48))(piVar7);
    if ((((iVar4 != 0) && (iVar4 = (**(code **)(*piVar5 + 0x48))(piVar5), iVar4 == 0)) &&
        (iVar4 = (**(code **)(*piVar6 + 0x48))(piVar6), iVar4 == 0)) &&
       ((param_1[param_2 * 6 + 0x28] & 2U) == 0)) {
      iVar11 = param_3 + 0xbc;
      FUN_00106004(param_3,2,piVar7,0,*(undefined4 *)(param_4 + 8));
      FUN_00103d50(iVar11,1,uVar2);
      FUN_00103d50(iVar11,2,uVar9);
      piVar5 = param_1 + iVar13 * 6 + 0x23;
      iVar4 = FUN_001054ec(param_3,2);
      *(undefined4 *)(iVar4 + 0x10) = uVar10;
      FUN_00106004(param_1,iVar13,piVar6,0,*(undefined4 *)(param_4 + 8));
      FUN_00103d50(piVar5,1,uVar1);
      FUN_00103d50(piVar5,2,uVar8);
      iVar4 = FUN_001054ec(param_1,iVar13);
      uVar3 = param_1[param_2 * 6 + 0x28];
      *(undefined4 *)(iVar4 + 0x10) = uVar12;
      if ((uVar3 & 1) != 0) {
        FUN_00103d50(iVar11,1,*(uint *)(param_3 + 0xd0) & 1 ^ 1);
        FUN_00103d50(piVar5,1,param_1[iVar13 * 6 + 0x28] & 1U ^ 1);
      }
      iVar4 = ((int (*)())FUN_00186a88)(param_1,param_2,param_3,param_4,1,1,0);
      if (iVar4 != 0) {
        return 1;
      }
      FUN_00106004(param_3,2,piVar6,0,*(undefined4 *)(param_4 + 8));
      FUN_00103d50(iVar11,1,uVar1);
      FUN_00103d50(iVar11,2,uVar8);
      iVar4 = FUN_001054ec(param_3,2);
      *(undefined4 *)(iVar4 + 0x10) = uVar12;
      FUN_00106004(param_1,iVar13,piVar7,0,*(undefined4 *)(param_4 + 8));
      FUN_00103d50(piVar5,1,uVar2);
      FUN_00103d50(piVar5,2,uVar9);
      iVar4 = FUN_001054ec(param_1,iVar13);
      *(undefined4 *)(iVar4 + 0x10) = uVar10;
    }
  }
LAB_00187a90:
  iVar4 = ((int (*)())FUN_00186a88)(param_1,param_2,param_3,param_4,1,1,0);
  if (iVar4 == 0) {
    return 0;
  }
  return 1;
}

/* FUN_00187ad8 @ 0x187ad8 (1996 bytes) */
int FUN_00187ad8(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  undefined4 *puVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  undefined4 uVar21;
  uint uVar22;
  int iVar23;
  uint *puVar24;
  code *pcVar25;
  int iVar26;
  int iVar27;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_80;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c;
  uint local_68;
  uint local_64;
  undefined4 local_60;
  undefined4 *local_5c;
  
  piVar5 = (int *)FUN_001922c4(0,0,param_1,param_2);
  iVar2 = *(int *)(piVar5[0x22] + 8);
  if (((iVar2 != 0x24) && (iVar2 != 0x25)) && (iVar2 != 0x26)) {
    return;
  }
  iVar2 = ((undefined4 (*)())FUN_00139838)(piVar5,2,(double)FLOAT_001aa0e8);
  iVar6 = ((undefined4 (*)())FUN_00139838)(piVar5,2,(double)FLOAT_001aa0d4);
  if ((iVar6 == 0) || (iVar6 = ((undefined4 (*)())FUN_00139838)(piVar5,3,(double)FLOAT_001aa0e8), iVar6 == 0)) {
    iVar6 = ((undefined4 (*)())FUN_00139838)(piVar5,3,(double)FLOAT_001aa0d4);
    if (iVar6 == 0) {
      return;
    }
    if (iVar2 == 0) {
      return;
    }
  }
  if ((piVar5[5] & 0x200U) != 0) {
    return;
  }
  puVar24 = (uint *)piVar5[4];
  uVar3 = puVar24[1];
  uVar18 = uVar3 - 1;
  if (-1 < (int)uVar18) {
    iVar6 = uVar18 * 4;
    uVar19 = 0;
    piVar11 = (int *)0x0;
    uVar22 = uVar18;
    do {
      if (uVar22 < *puVar24) {
        uVar7 = puVar24[1];
        if (uVar7 <= uVar22) {
          _memset(uVar7 * 4 + puVar24[2],0,(uVar22 - uVar7) * 4 + 4);
          puVar24[1] = uVar22 + 1;
        }
        piVar8 = (int *)(iVar6 + puVar24[2]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar24,uVar22);
      }
      iVar26 = *piVar8;
      iVar4 = *(int *)(iVar26 + 0x88);
      piVar8 = piVar11;
      if (*(int *)(iVar4 + 8) != 0x13) {
        if (*(int *)(iVar4 + 8) == 0x14) {
          piVar9 = (int *)FUN_00105594(iVar26,1);
          if ((piVar5 == piVar9) || (piVar9 = (int *)FUN_00105594(iVar26,2), piVar5 == piVar9))
          goto LAB_00187ce4;
          iVar4 = *(int *)(iVar26 + 0x88);
        }
        if (*(int *)(iVar4 + 8) == 0x12) {
          piVar9 = (int *)FUN_00105594(iVar26,1);
          piVar10 = (int *)FUN_00105594(iVar26,2);
          piVar8 = piVar10;
          if (((piVar5 != piVar9) && (piVar8 = piVar9, piVar5 != piVar10)) ||
             ((piVar11 != (int *)0x0 && (piVar11 != piVar8)))) goto LAB_00187cfc;
        }
      }
LAB_00187ce4:
      uVar19 = uVar19 + 1;
      uVar22 = uVar22 - 1;
      iVar6 = iVar6 + -4;
      if (uVar19 == uVar3) goto LAB_00187cfc;
      puVar24 = (uint *)piVar5[4];
      piVar11 = piVar8;
    } while( true );
  }
LAB_00187d00:
  iVar6 = *(int *)(param_2 + 0x478);
  if (-1 < (int)uVar18) {
    iVar4 = uVar18 * 4;
    uVar22 = 0;
    do {
      if (uVar18 < *puVar24) {
        uVar19 = puVar24[1];
        if (uVar19 <= uVar18) {
          _memset(uVar19 * 4 + puVar24[2],0,(uVar18 - uVar19) * 4 + 4);
          puVar24[1] = uVar18 + 1;
        }
        piVar11 = (int *)(iVar4 + puVar24[2]);
      }
      else {
        piVar11 = (int *)FUN_0019423c(puVar24,uVar18);
      }
      iVar26 = *piVar11;
      if (*(int *)(*(int *)(iVar26 + 0x88) + 8) == 0x13) {
        piVar11 = (int *)FUN_00105594(iVar26,1);
        if (piVar5 == piVar11) {
          uVar21 = 1;
          iVar23 = 2;
        }
        else {
          piVar11 = (int *)FUN_00105594(iVar26,2);
          if (piVar5 != piVar11) {
            if ((*(uint *)(iVar26 + 0x14) & 0x200) != 0) {
              FUN_00105594(iVar26,*(undefined4 *)(iVar26 + 0x84));
            }
            goto LAB_00188244;
          }
          uVar21 = 2;
          iVar23 = 1;
        }
        local_5c = &local_94;
        iVar20 = 0;
        *(int *)(param_2 + 500) = *(int *)(param_2 + 500) + 1;
        FUN_00194208(piVar5[4],uVar18);
        piVar5[0x58] = piVar5[0x58] + -1;
        local_80 = 0;
        local_94 = 0;
        local_90 = 0;
        uVar12 = FUN_001054ec(iVar26,0);
        FUN_00104730(local_5c,uVar12);
        local_60 = FUN_00105594(iVar26,iVar23);
        FUN_00106004(iVar26,iVar23,0,1,*(undefined4 *)(param_2 + 8));
        iVar13 = FUN_001054ec(iVar26,iVar23);
        local_78 = *(int *)(iVar13 + 0x10);
        iVar13 = FUN_001054ec(iVar26,uVar21);
        local_98 = *(undefined4 *)(iVar13 + 0x10);
        uVar19 = *(uint *)(iVar23 * 0x18 + iVar26 + 0xa0);
        local_68 = uVar19 & 1;
        local_64 = uVar19 >> 1 & 1;
        local_6c = piVar5[1];
        local_70 = *(undefined4 *)(iVar26 + 8);
        local_74 = *(undefined4 *)(iVar26 + 0x158);
        iVar13 = piVar5[0x56];
        iVar23 = *(int *)(iVar26 + 0x10);
        FUN_0019401c(piVar5);
        FUN_0019401c(iVar26);
        iVar16 = *(int *)(iVar26 + 0x14c);
        iVar27 = *(int *)(iVar26 + 0x120);
        iVar17 = *(int *)(iVar26 + 0x124);
        if ((*(uint *)(iVar26 + 0x14) & 0x200) != 0) {
          iVar20 = FUN_00105594(iVar26,*(undefined4 *)(iVar26 + 0x84));
          uVar21 = *(undefined4 *)(param_2 + 8);
          iVar14 = FUN_00105594(iVar26,*(undefined4 *)(iVar26 + 0x84));
          puVar24 = *(uint **)(iVar14 + 0x10);
          uVar19 = puVar24[1];
          if (0 < (int)uVar19) {
            uVar7 = 0;
            do {
              if (uVar7 < *puVar24) {
                if (uVar19 <= uVar7) {
                  _memset(uVar19 * 4 + puVar24[2],0,(uVar7 - uVar19) * 4 + 4);
                  puVar24[1] = uVar7 + 1;
                }
                piVar11 = (int *)(uVar7 * 4 + puVar24[2]);
              }
              else {
                piVar11 = (int *)FUN_0019423c(puVar24,uVar7);
              }
              if (iVar26 == *piVar11) {
                FUN_00194208(puVar24,uVar7);
                iVar14 = FUN_00105594(iVar26,*(undefined4 *)(iVar26 + 0x84));
                *(int *)(iVar14 + 0x160) = *(int *)(iVar14 + 0x160) + -1;
                break;
              }
              uVar19 = puVar24[1];
              uVar7 = uVar7 + 1;
            } while ((int)uVar7 < (int)uVar19);
          }
          FUN_00106004(iVar26,*(undefined4 *)(iVar26 + 0x84),0,1,uVar21);
          *(int *)(iVar26 + 0x84) = *(int *)(iVar26 + 0x84) + -1;
          *(uint *)(iVar26 + 0x14) = *(uint *)(iVar26 + 0x14) & 0xfffffdff;
        }
        iVar14 = *(int *)(iVar26 + 0x160) - iVar6;
        if (iVar14 < 0) {
          iVar14 = 0;
        }
        piVar11 = (int *)FUN_00103ebc(piVar5,iVar26,*(undefined4 *)(param_2 + 8),1);
        iVar26 = (iVar2 == 0) + 2;
        FUN_001062c0(piVar11,0,local_5c,*(undefined4 *)(param_2 + 8));
        piVar11[0x53] = iVar16;
        FUN_000e7738(iVar13,local_6c,piVar5);
        FUN_000e7700(local_74,local_70,piVar11);
        piVar11[0x48] = iVar27;
        piVar11[0x49] = iVar17;
        if (iVar20 != 0) {
          FUN_00106804(piVar11,iVar20,1,*(undefined4 *)(param_2 + 8));
        }
        piVar11[4] = iVar23;
        FUN_00106004(piVar11,iVar26,local_60,1,*(undefined4 *)(param_2 + 8));
        piVar11[0x58] = iVar6 + iVar14;
        if (iVar26 == 0) {
          piVar11[0x27] = local_78;
        }
        else {
          iVar23 = FUN_001054ec(piVar11,iVar26);
          *(int *)(iVar23 + 0x10) = local_78;
        }
        FUN_00103d50(piVar11 + iVar26 * 6 + 0x23,2,local_64);
        FUN_00103d50(piVar11 + iVar26 * 6 + 0x23,1,local_68);
        iVar23 = FUN_00105594(piVar11,1);
        if (iVar6 < *(int *)(iVar23 + 0x160)) {
          *(int *)(iVar23 + 0x160) = *(int *)(iVar23 + 0x160) + 1;
        }
        else {
          *(int *)(iVar23 + 0x160) = iVar6 + 1;
        }
        puVar24 = *(uint **)(iVar23 + 0x10);
        uVar19 = puVar24[1];
        if (uVar19 < *puVar24) {
          _memset(uVar19 * 4 + puVar24[2],0,4);
          puVar15 = (undefined4 *)(uVar19 * 4 + puVar24[2]);
          puVar24[1] = uVar19 + 1;
        }
        else {
          puVar15 = (undefined4 *)FUN_0019423c(puVar24,uVar19);
        }
        *puVar15 = piVar11;
        iVar23 = 0;
        do {
          uVar19 = (uint)*(byte *)((int)&local_98 + iVar23);
          iVar13 = FUN_001054ec(piVar11,0);
          if (*(char *)(iVar23 + iVar13 + 0x10) == '\x01') {
            uVar19 = 4;
          }
          for (iVar13 = 1; iVar20 = (**(code **)(*piVar11 + 0x14))(piVar11), iVar13 <= iVar20;
              iVar13 = iVar13 + 1) {
            if (iVar26 != iVar13) {
              if (uVar19 == 4) {
                (**(code **)(*piVar11 + 0x88))(piVar11,iVar13,iVar23,4);
              }
              else {
                pcVar25 = *(code **)(*piVar11 + 0x88);
                iVar20 = FUN_001054ec(piVar5,iVar13);
                (*pcVar25)(piVar11,iVar13,iVar23,*(undefined1 *)(uVar19 + iVar20 + 0x10));
              }
            }
          }
          bVar1 = iVar23 != 3;
          iVar23 = iVar23 + 1;
        } while (bVar1);
      }
LAB_00188244:
      uVar22 = uVar22 + 1;
      uVar18 = uVar18 - 1;
      iVar4 = iVar4 + -4;
      if (uVar22 == uVar3) goto code_r0x00188258;
      puVar24 = (uint *)piVar5[4];
    } while( true );
  }
LAB_0018825c:
  if (puVar24[1] == 0) {
    (**(code **)(*piVar5 + 0xc))(piVar5,1,*(undefined4 *)(param_2 + 8));
  }
  return;
LAB_00187cfc:
  puVar24 = (uint *)piVar5[4];
  goto LAB_00187d00;
code_r0x00188258:
  puVar24 = (uint *)piVar5[4];
  goto LAB_0018825c;
}

/* FUN_001882a4 @ 0x1882a4 (408 bytes) */
int FUN_001882a4(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  double fparam_1;
  
  iVar4 = (**(code **)(*param_1 + 0x68))();
  if (iVar4 != 0) {
    piVar5 = (int *)FUN_00105594(param_1,1);
    iVar4 = (**(code **)(*piVar5 + 0x40))();
    if (iVar4 != 0) {
      uVar7 = 0xffffffff;
      iVar4 = 0;
      fVar2 = FLOAT_001aa0d4;
      do {
        iVar6 = FUN_001054ec(param_1,0);
        if (*(char *)(iVar4 + iVar6 + 0x10) != '\x01') {
          iVar6 = FUN_001054ec(param_1,1);
          uVar8 = (uint)*(byte *)(iVar4 + iVar6 + 0x10);
          if (((int)*(char *)(piVar5 + 0x57) >> (uVar8 & 0x3f) & 1U) == 0) {
            return;
          }
          iVar6 = ((undefined4 (*)())FUN_0010aafc)((double)(float)piVar5[uVar8 * 6 + 8]);
          if (iVar6 == 0) {
            return;
          }
          if (uVar7 == 0xffffffff) {
            fVar2 = (float)piVar5[uVar8 * 6 + 8];
            uVar7 = uVar8;
          }
          else if ((float)piVar5[uVar8 * 6 + 8] != fVar2) {
            return;
          }
        }
        bVar1 = iVar4 != 3;
        iVar4 = iVar4 + 1;
      } while (bVar1);
      iVar4 = ((int (*)())FUN_0010ab40)((double)(float)piVar5[uVar7 * 6 + 8]);
      iVar6 = (**(code **)(**(int **)(param_2 + 0x30c) + 0xfc))(*(int **)(param_2 + 0x30c),iVar4,0);
      if (iVar6 != 0) {
        fparam_1 = (double)FLOAT_001aa0e8;
        ((void (*)())FUN_000f79c4)(param_1,*(undefined4 *)(param_2 + 0x6c4),1,fparam_1,fparam_1,fparam_1,fparam_1)
        ;
        uVar3 = DAT_001b0220;
        param_1[0x49] = iVar4;
        iVar4 = FUN_001054ec(param_1,1);
        *(undefined4 *)(iVar4 + 0x10) = uVar3;
      }
    }
  }
  return;
}

/* FUN_0018843c @ 0x18843c (1328 bytes) */
int FUN_0018843c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  int param_2;
  int param_3;
  int *param_4;
  undefined4 *param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 local_38 [7];
  
  uVar6 = 0;
  local_38[0] = 0;
  puVar5 = param_5;
  iVar1 = FUN_000e07dc(param_5[2],0x1b);
  if (iVar1 == 0) {
LAB_00188508:
    iVar1 = FUN_000e07dc(param_5[2],0x1c);
    if (iVar1 != 0) {
      iVar1 = FUN_00154dc0(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
        if (param_4 == (int *)0x0) goto LAB_00188950;
      }
      iVar1 = FUN_00162cc0(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
        if (param_4 == (int *)0x0) goto LAB_00188950;
      }
      iVar1 = (**(code **)(*param_4 + 0x14))(param_4);
      if ((param_3 <= iVar1) && (iVar1 = FUN_00158264(param_2,param_3,param_4,param_5), iVar1 != 0))
      {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
        if (param_4 == (int *)0x0) goto LAB_00188950;
        uVar6 = 1;
      }
      iVar1 = FUN_00155a60(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_0014bdbc(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_0014caec(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_0014d8f8(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_00150d38(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_0014cec8(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_0015df44(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_0015e494(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_000e07dc(param_5[2],0x3c);
      if ((iVar1 != 0) && (iVar1 = FUN_00163478(param_2,param_3,param_4,param_5), iVar1 != 0)) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_0014d274(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_00158c3c(param_4,param_5);
      if (iVar1 != 0) {
        uVar6 = 1;
      }
    }
    iVar1 = FUN_0015546c(param_2,param_3,param_4,(uint)param_5);
    if (iVar1 != 0) {
      uVar6 = 1;
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    piVar3 = param_4;
    puVar4 = param_5;
    iVar1 = FUN_00155654(param_2,param_3,param_4,param_5);
    piVar2 = param_4;
    if (iVar1 != 0) {
      uVar6 = 1;
      piVar2 = (int *)FUN_00146610(param_2,param_3,param_4);
      piVar3 = param_4;
    }
    iVar1 = FUN_000e07dc(param_5[2],0x1d);
    if ((((iVar1 != 0) &&
         (iVar1 = FUN_001633f8(piVar2,param_5,piVar3,puVar4,puVar5,param_6,param_7), iVar1 != 0)) &&
        (iVar1 = (**(code **)(*piVar2 + 100))(piVar2), iVar1 != 0)) &&
       ((param_2 != 0 && (iVar1 = FUN_00160320(param_2,param_3,piVar2,param_5,local_38), iVar1 != 0)
        ))) {
      piVar2 = (int *)FUN_00146610(param_2,param_3,piVar2);
      if (piVar2 == (int *)0x0) goto LAB_00188950;
    }
    iVar1 = FUN_000e07dc(param_5[2],0x39);
    if (iVar1 != 0) {
      ((int (*)())FUN_001882a4)(piVar2,param_5[2]);
    }
    iVar1 = FUN_00159b58(piVar2,1,param_5);
    if (iVar1 != 0) {
      piVar2 = (int *)FUN_00146610(param_2,param_3,piVar2);
    }
    iVar1 = FUN_000e07dc(param_5[2],0x39);
    if ((iVar1 != 0) && (iVar1 = ((int (*)())FUN_001875a8)(param_2,param_3,piVar2,param_5), iVar1 != 0)) {
      uVar6 = 1;
      piVar2 = (int *)FUN_00146610(param_2,param_3,piVar2);
    }
    iVar1 = FUN_000e07dc(param_5[2],0x3b);
    if ((iVar1 != 0) && ((piVar2[5] & 1U) != 0)) {
      FUN_001859bc(piVar2,param_5,param_5[2]);
    }
  }
  else {
    uVar6 = (**(code **)(*param_4 + 100))(param_4);
    iVar1 = FUN_0014abdc(param_4,param_5,local_38);
    if (iVar1 == 0) {
LAB_001884c8:
      if (param_2 != 0) {
        puVar5 = local_38;
        iVar1 = FUN_00160320(param_2,param_3,param_4,param_5,puVar5);
        if (iVar1 != 0) {
          param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
          if (param_4 == (int *)0x0) goto LAB_00188950;
        }
      }
      goto LAB_00188508;
    }
    param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    if (param_4 != (int *)0x0) goto LAB_001884c8;
LAB_00188950:
    uVar6 = 1;
  }
  return uVar6;
}

/* FUN_0018896c @ 0x18896c (1208 bytes) */
int FUN_0018896c(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint *puVar12;
  int *piVar13;
  undefined4 local_58;
  undefined4 local_54;
  int local_48;
  undefined4 local_44;
  int local_38 [5];
  
  if (*(int *)(param_1[0x22] + 8) != 0x31) {
    return;
  }
  iVar1 = FUN_00105594(param_1,1);
  uVar2 = 0;
  if (iVar1 != 0) {
    iVar1 = FUN_00105594(param_1,1);
    uVar2 = *(undefined4 *)(iVar1 + 0x98);
  }
  iVar1 = FUN_001267b8(uVar2);
  if (iVar1 == 0) {
    return;
  }
  piVar3 = (int *)FUN_00105594(param_1,1);
  iVar1 = (**(code **)(*piVar3 + 0x5c))();
  if (iVar1 != 0) {
    return;
  }
  if ((param_1[5] & 0x200U) != 0) {
    return;
  }
  if (param_1[0x48] != 0) {
    return;
  }
  piVar3 = (int *)FUN_00105594(param_1,1);
  iVar1 = (**(code **)(*piVar3 + 0x48))();
  if (iVar1 != 0) {
    return;
  }
  if (param_1[0x49] == 0) {
    return;
  }
  if (((param_1[0x2e] & 1U) == 0) && ((param_1[0x2e] & 2U) == 0)) {
    iVar1 = FUN_001054ec(param_1,1);
    iVar1 = FUN_000f3190(*(undefined4 *)(iVar1 + 0x10));
    if (iVar1 != 0) goto LAB_00188a5c;
  }
  iVar1 = FUN_00184bf0(param_1);
  if (iVar1 == 0) {
    return;
  }
LAB_00188a5c:
  uVar2 = FUN_00105594(param_1,1);
  iVar1 = FUN_00184ef0(uVar2,param_1[0x49],param_2);
  if (iVar1 != 0) {
    *(int *)(param_2 + 0x160) = *(int *)(param_2 + 0x160) + 1;
    uVar2 = FUN_00105594(param_1,1);
    puVar12 = (uint *)param_1[4];
    uVar9 = puVar12[1] - 1;
    if (-1 < (int)uVar9) {
      do {
        if (uVar9 < *puVar12) {
          uVar4 = puVar12[1];
          if (uVar4 <= uVar9) {
            _memset(uVar4 * 4 + puVar12[2],0,(uVar9 - uVar4) * 4 + 4);
            puVar12[1] = uVar9 + 1;
          }
          puVar5 = (undefined4 *)(uVar9 * 4 + puVar12[2]);
        }
        else {
          puVar5 = (undefined4 *)FUN_0019423c(puVar12,uVar9);
        }
        piVar13 = (int *)*puVar5;
        piVar3 = piVar13 + 0x20;
        for (iVar1 = 0; iVar8 = (**(code **)(*piVar13 + 0x14))(piVar13), iVar1 <= iVar8;
            iVar1 = iVar1 + 1) {
          piVar6 = (int *)FUN_00105594(piVar13,iVar1);
          if (param_1 == piVar6) {
            uVar9 = uVar9 - 1;
            iVar8 = FUN_001054ec(piVar6,1);
            uVar10 = *(undefined4 *)(iVar8 + 0x10);
            iVar8 = FUN_001054ec(piVar13,iVar1);
            FUN_000f2bdc(local_38,uVar10,*(undefined4 *)(iVar8 + 0x10));
            iVar8 = local_38[0];
            if ((*(int *)(piVar13[0x22] + 8) != 0x8e) ||
               (((iVar7 = FUN_000f3190(local_38[0]), iVar7 != 0 && ((param_1[0x2e] & 1U) == 0)) &&
                ((param_1[0x2e] & 2U) == 0)))) {
              FUN_00106004(piVar13,iVar1,uVar2,1,*(undefined4 *)(param_2 + 8));
              if (iVar1 == 0) {
                piVar13[0x27] = iVar8;
              }
              else {
                iVar7 = FUN_001054ec(piVar13,iVar1);
                *(int *)(iVar7 + 0x10) = iVar8;
              }
              FUN_00103d50(piVar3 + 3,2,(uint)param_1[0x2e] >> 1 & 1);
              if ((param_1[0x2e] & 1U) != 0) {
                FUN_00103d50(piVar3 + 3,1,piVar3[8] & 1U ^ 1);
              }
            }
          }
          piVar3 = piVar3 + 6;
        }
        if (((piVar13[5] & 0x200U) != 0) &&
           (piVar3 = (int *)FUN_00105594(piVar13,piVar13[0x21]), param_1 == piVar3)) {
          iVar1 = FUN_000f31e8(piVar3,1);
          if (iVar1 != 0) {
            local_44 = 0;
            local_58 = 0;
            local_54 = 0;
            FUN_00104d3c(piVar13,&local_58);
            uVar10 = *(undefined4 *)(param_2 + 8);
            iVar1 = FUN_00105594(piVar13,piVar13[0x21]);
            puVar12 = *(uint **)(iVar1 + 0x10);
            uVar4 = puVar12[1];
            if (0 < (int)uVar4) {
              uVar11 = 0;
              do {
                if (uVar11 < *puVar12) {
                  if (uVar4 <= uVar11) {
                    _memset(uVar4 * 4 + puVar12[2],0,(uVar11 - uVar4) * 4 + 4);
                    puVar12[1] = uVar11 + 1;
                  }
                  piVar3 = (int *)(uVar11 * 4 + puVar12[2]);
                }
                else {
                  piVar3 = (int *)FUN_0019423c(puVar12,uVar11);
                }
                if (piVar13 == (int *)*piVar3) {
                  FUN_00194208(puVar12,uVar11);
                  iVar1 = FUN_00105594(piVar13,piVar13[0x21]);
                  *(int *)(iVar1 + 0x160) = *(int *)(iVar1 + 0x160) + -1;
                  break;
                }
                uVar4 = puVar12[1];
                uVar11 = uVar11 + 1;
              } while ((int)uVar11 < (int)uVar4);
            }
            FUN_00106004(piVar13,piVar13[0x21],0,1,uVar10);
            piVar13[0x21] = piVar13[0x21] + -1;
            piVar13[5] = piVar13[5] & 0xfffffdff;
            FUN_00106804(piVar13,uVar2,1,*(undefined4 *)(param_2 + 8));
            iVar1 = local_48;
            if (piVar13[0x21] == 0) {
              piVar13[0x27] = local_48;
            }
            else {
              iVar8 = FUN_001054ec(piVar13,piVar13[0x21]);
              *(int *)(iVar8 + 0x10) = iVar1;
            }
          }
          uVar9 = uVar9 - 1;
        }
        if ((int)uVar9 < 0) break;
        puVar12 = (uint *)param_1[4];
      } while( true );
    }
    iVar1 = FUN_00104054(param_1,param_2);
    if (iVar1 == 0) {
      FUN_0019401c(param_1);
      (**(code **)(*param_1 + 0xc))(param_1,1,*(undefined4 *)(param_2 + 8));
    }
  }
  return;
}

/* FUN_00188e24 @ 0x188e24 (256 bytes) */
int FUN_00188e24(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  if ((*(uint *)(param_2 + 0x14) & 1) != 0) {
    ((int (*)())FUN_00187ad8)(param_2,param_3);
    iVar1 = FUN_000e07dc(*(undefined4 *)(param_3 + 8),0x36);
    if ((iVar1 == 0) || (FUN_00184d7c(param_2,param_3), (*(uint *)(param_2 + 0x14) & 1) != 0)) {
      iVar1 = FUN_000e07dc(*(undefined4 *)(param_3 + 8),0x15);
      if (iVar1 != 0) {
        FUN_00150b94(param_2,param_3);
        FUN_0014e6e4(param_2,param_3);
      }
      iVar1 = FUN_000e07dc(*(undefined4 *)(param_3 + 8),0x16);
      if ((iVar1 != 0) && (iVar1 = FUN_0010497c(param_2,param_3), iVar1 == 0)) {
        FUN_0015a68c(param_2,param_3);
      }
      iVar1 = FUN_000e07dc(*(undefined4 *)(param_3 + 8),0x14);
      if (iVar1 != 0) {
        ((int (*)())FUN_0018896c)(param_2,param_3);
        return;
      }
    }
  }
  return;
}

/* FUN_00188f24 @ 0x188f24 (200 bytes) */
int FUN_00188f24(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined1 auStack_28 [24];
  
  piVar3 = *(int **)(param_2 + 900);
  iVar1 = piVar3[2];
  while (iVar1 != 0) {
    iVar1 = (**(code **)(*piVar3 + 0x24))(piVar3);
    if (iVar1 != 0) {
      iVar2 = piVar3[0x4d];
      iVar1 = FUN_00194034(iVar2 + 0x90);
      if ((((iVar1 < 3) && (iVar1 = FUN_000e79d0(iVar2), iVar1 == 1)) &&
          (iVar1 = FUN_000e920c(iVar2,0), iVar1 == piVar3[0x4f])) &&
         (iVar1 = FUN_000e87e4(piVar3,auStack_28), iVar1 == 0)) {
        piVar3 = (int *)FUN_0012abd8(param_2,piVar3);
      }
    }
    piVar3 = (int *)piVar3[2];
    iVar1 = piVar3[2];
  }
  return;
}

/* FUN_00188fec @ 0x188fec (1280 bytes) */
int FUN_00188fec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  int param_2;
  int *param_3;
  int *param_4;
  int *param_5;
  undefined4 param_6;
  int param_7;
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  int local_38 [8];
  
  uVar7 = 0;
  local_38[0] = 0;
  piVar4 = param_3;
  piVar5 = param_4;
  piVar6 = param_5;
  iVar1 = FUN_000e07dc(param_5[2],0x1b);
  if (iVar1 != 0) {
    uVar7 = (**(code **)(*param_4 + 100))(param_4);
    piVar4 = local_38;
    iVar1 = FUN_0014abdc(param_4,param_5,piVar4);
    piVar2 = param_4;
    if ((iVar1 != 0) &&
       (piVar2 = (int *)FUN_00146610(param_2,param_3,param_4), piVar4 = param_4,
       piVar2 == (int *)0x0)) {
      return 1;
    }
    param_4 = piVar2;
    if (param_2 != 0) {
      piVar6 = local_38;
      piVar4 = piVar2;
      piVar5 = param_5;
      iVar1 = FUN_00160320(param_2,param_3,piVar2,param_5,piVar6);
      if ((iVar1 != 0) &&
         (param_4 = (int *)FUN_00146610(param_2,param_3,piVar2), piVar4 = piVar2,
         param_4 == (int *)0x0)) {
        return 1;
      }
    }
  }
  iVar1 = FUN_000e07dc(param_5[2],0x1c);
  if (iVar1 != 0) {
    param_7 = **(int **)(param_5[2] + 0x30c);
    iVar1 = (**(code **)(param_7 + 0x84))();
    if (((iVar1 != 0) && (iVar1 = FUN_00154dc0(param_4,param_5), iVar1 != 0)) &&
       (param_4 = (int *)FUN_00146610(param_2,param_3,param_4), param_4 == (int *)0x0)) {
      return 1;
    }
    iVar1 = FUN_00162cc0(param_4,param_5);
    if ((iVar1 != 0) &&
       (param_4 = (int *)FUN_00146610(param_2,param_3,param_4), param_4 == (int *)0x0)) {
      return 1;
    }
    iVar1 = (**(code **)(*param_4 + 0x14))(param_4);
    if (((int)param_3 <= iVar1) &&
       (iVar1 = FUN_00158264(param_2,param_3,param_4,param_5), iVar1 != 0)) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      if (param_4 == (int *)0x0) {
        return 1;
      }
      uVar7 = 1;
    }
    iVar1 = FUN_00155a60(param_4,param_5);
    if (iVar1 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar1 = FUN_0014bdbc(param_4,param_5);
    if (iVar1 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    piVar4 = (int *)0x0;
    piVar5 = (int *)((int)&MACH_HEADER.magic + 1);
    iVar1 = FUN_0014b82c(param_4,param_5,0,1);
    piVar2 = param_4;
    if (iVar1 != 0) {
      piVar2 = (int *)FUN_00146610(param_2,param_3,param_4);
      piVar4 = param_4;
    }
    iVar1 = FUN_0014b150(piVar2,param_5);
    piVar3 = piVar2;
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*piVar2 + 100))(piVar2);
      if (((iVar1 != 0) && ((piVar2[5] & 0x200U) == 0)) && (param_2 != 0)) {
        piVar6 = local_38;
        piVar5 = param_5;
        FUN_00160320(param_2,param_3,piVar2,param_5,piVar6);
      }
      piVar3 = (int *)FUN_00146610(param_2,param_3,piVar2);
      if (piVar3 == (int *)0x0) {
        return 1;
      }
      uVar7 = 1;
      piVar4 = piVar2;
    }
    iVar1 = FUN_00150d38(piVar3,param_5);
    piVar2 = piVar3;
    if (iVar1 != 0) {
      piVar2 = (int *)FUN_00146610(param_2,param_3,piVar3);
      piVar4 = piVar3;
    }
    iVar1 = FUN_0015ceb0(piVar2,param_5);
    piVar3 = piVar2;
    if (iVar1 != 0) {
      piVar3 = (int *)FUN_00146610(param_2,param_3,piVar2);
      piVar4 = piVar2;
    }
    iVar1 = FUN_0015bd40(piVar3,param_5);
    piVar2 = piVar3;
    if (iVar1 != 0) {
      piVar2 = (int *)FUN_00146610(param_2,param_3,piVar3);
      piVar4 = piVar3;
    }
    iVar1 = FUN_00163994(piVar2,param_5);
    piVar3 = piVar2;
    if (iVar1 != 0) {
      piVar3 = (int *)FUN_00146610(param_2,param_3,piVar2);
      piVar4 = piVar2;
    }
    iVar1 = FUN_0015c6d4(piVar3,param_5);
    piVar2 = piVar3;
    if (iVar1 != 0) {
      piVar2 = (int *)FUN_00146610(param_2,param_3,piVar3);
      piVar4 = piVar3;
    }
    iVar1 = FUN_0014acb8(piVar2,param_5);
    piVar3 = piVar2;
    if (iVar1 != 0) {
      piVar3 = (int *)FUN_00146610(param_2,param_3,piVar2);
      piVar4 = piVar2;
    }
    iVar1 = FUN_0015e494(piVar3,param_5);
    param_4 = piVar3;
    if (iVar1 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,piVar3);
      piVar4 = piVar3;
    }
  }
  iVar1 = FUN_000e07dc(param_5[2],0x1d);
  if ((((iVar1 != 0) &&
       (iVar1 = FUN_001633f8(param_4,param_5,piVar4,piVar5,piVar6,param_6,param_7), iVar1 != 0)) &&
      ((iVar1 = (**(code **)(*param_4 + 100))(param_4), iVar1 != 0 &&
       ((param_2 != 0 &&
        (iVar1 = FUN_00160320(param_2,param_3,param_4,param_5,local_38), iVar1 != 0)))))) &&
     (param_4 = (int *)FUN_00146610(param_2,param_3,param_4), param_4 == (int *)0x0)) {
    return 1;
  }
  iVar1 = FUN_000e07dc(param_5[2],0x3a);
  if (iVar1 == 0) {
    return uVar7;
  }
  if ((param_5[0x8a] < *(int *)(param_5[2] + 0x664)) &&
     (iVar1 = FUN_0015ea3c(param_2,param_3,param_4,param_5), iVar1 != 0)) {
    uVar7 = 1;
    param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
  }
  iVar1 = FUN_0015f44c(param_2,param_3,param_4,param_5);
  if (iVar1 != 0) {
    FUN_00146610(param_2,param_3,param_4);
    return 1;
  }
  return uVar7;
}

/* FUN_001894ec @ 0x1894ec (116 bytes) */
int FUN_001894ec(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  if (((*(uint *)(param_2 + 0x14) & 1) != 0) &&
     (iVar1 = FUN_000e07dc(*(undefined4 *)(param_3 + 8),0x15), iVar1 != 0)) {
    FUN_00150b94(param_2,param_3);
    FUN_0014e6e4(param_2,param_3);
    return;
  }
  return;
}

/* FUN_00189560 @ 0x189560 (64 bytes) */
int FUN_00189560(param_1)
  undefined4 *param_1;
{
  bool bVar1;
  int iVar2;
  
  iVar2 = 0;
  param_1[5] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  do {
    bVar1 = iVar2 != 2;
    param_1[6] = 0;
    param_1[9] = 0;
    iVar2 = iVar2 + 1;
    param_1[0xc] = 0;
    param_1 = param_1 + 1;
  } while (bVar1);
  return;
}

/* FUN_001895a0 @ 0x1895a0 (100 bytes) */
int FUN_001895a0(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar4 = *param_2;
  param_1[2] = param_2[2];
  uVar3 = param_2[3];
  *param_1 = uVar4;
  iVar5 = 0;
  param_1[3] = uVar3;
  uVar4 = param_2[1];
  param_1[4] = param_2[4];
  uVar3 = param_2[5];
  param_1[1] = uVar4;
  param_1[5] = uVar3;
  do {
    bVar2 = iVar5 != 2;
    iVar5 = iVar5 + 1;
    param_1[6] = param_2[6];
    puVar1 = param_2 + 9;
    uVar3 = param_2[0xc];
    param_2 = param_2 + 1;
    param_1[9] = *puVar1;
    param_1[0xc] = uVar3;
    param_1 = param_1 + 1;
  } while (bVar2);
  return;
}

/* FUN_00189604 @ 0x189604 (40 bytes) */
int FUN_00189604(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  ((int (*)())FUN_00189560)(param_1 + 0x28);
  return;
}

/* FUN_0018962c @ 0x18962c (52 bytes) */
int FUN_0018962c(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_2 + 0x30))(param_2);
  return uVar1 ^ 1;
}

/* FUN_00189660 @ 0x189660 (152 bytes) */
int FUN_00189660(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
  int *param_4;
  int *param_5;
{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_5 != (int *)0x0) && (iVar1 = (**(code **)(*param_5 + 0x4c))(param_5), iVar1 != 0)) &&
     (*param_4 == 0x10304)) {
    return 1;
  }
                    
                    
  uVar2 = (**(code **)(*param_1 + 0x100))(param_1,param_4);
  return uVar2;
}

/* FUN_001896f8 @ 0x1896f8 (108 bytes) */
int FUN_001896f8(param_1)
  uint param_1;
{
  return *(uint *)(&DAT_001b0244 +
                  ((param_1 >> 0x18) * 0x7d + (param_1 >> 0x10 & 0xff) * 0x19 +
                   (param_1 >> 8 & 0xff) * 5 + (param_1 & 0xff)) * 0x10) ==
         ((uint)(byte)DAT_001b2a68 << 0x18 | (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 2)) << 0x10 |
          (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 1)) << 8 | (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 0)));
}

/* FUN_0018976c @ 0x18976c (28 bytes) */
int FUN_0018976c(param_1)
  undefined4 param_1;
{
  undefined4 uVar1;
  
  uVar1 = FUN_000f2d18(param_1,DAT_001b2a64);
  return uVar1;
}

/* FUN_00189788 @ 0x189788 (104 bytes) */
int FUN_00189788(param_1)
  undefined4 param_1;
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_001b2994;
  do {
    iVar1 = FUN_000f2d18(*puVar2,param_1);
    if (iVar1 != 0) {
      return 1;
    }
    puVar2 = puVar2 + 1;
  } while (puVar2 != (undefined4 *)&UNK_001b29e4);
  return 0;
}

/* FUN_001897f0 @ 0x1897f0 (8 bytes) */
int FUN_001897f0(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())FUN_00189788)(*param_2);
  return;
}

/* FUN_001897fc @ 0x1897fc (68 bytes) */
int FUN_001897fc(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_00105594(param_1,param_2);
  bVar2 = false;
  if (*(int *)(iVar1 + 0x98) == 0x33) {
    bVar2 = *(int *)(iVar1 + 300) != 3;
  }
  return bVar2;
}

/* FUN_00189840 @ 0x189840 (364 bytes) */
int FUN_00189840(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  int *param_3;
  int param_4;
  int param_5;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *local_58 [12];
  
  iVar5 = 0;
  do {
    iVar4 = 2;
    piVar7 = param_2;
    do {
      for (iVar6 = 1; iVar2 = (**(code **)(*piVar7 + 0x14))(piVar7), iVar6 <= iVar2;
          iVar6 = iVar6 + 1) {
        piVar1 = (int *)FUN_00105594(piVar7,iVar6);
        iVar2 = (**(code **)(*piVar1 + 0x60))();
        if (iVar2 == 0) {
LAB_001898e0:
          iVar2 = (**(code **)(*piVar1 + 0x48))(piVar1);
          if ((iVar2 != 0) && (piVar1[0x4b] == 3)) {
            if (iVar5 < 1) {
LAB_00189934:
              iVar2 = iVar5 + 1;
              local_58[iVar5] = piVar1;
              iVar5 = iVar2;
              if (param_4 + param_5 < iVar2) {
                return 0;
              }
            }
            else if (local_58[0] != piVar1) {
              iVar3 = 0;
              iVar2 = iVar5;
              do {
                iVar3 = iVar3 + 1;
                iVar2 = iVar2 + -1;
                if (iVar2 == 0) goto LAB_00189934;
              } while (piVar1 != local_58[iVar3]);
            }
          }
        }
        else {
          iVar2 = FUN_0010497c(piVar1,*(undefined4 *)(*(int *)(param_1 + 8) + 0x6c4));
          if (iVar2 != 0) {
            piVar1 = (int *)FUN_00105594(piVar1,1);
            goto LAB_001898e0;
          }
        }
      }
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) {
        return 1;
      }
      piVar7 = param_3;
    } while (iVar4 != 2);
  } while( true );
}

/* FUN_001899ac @ 0x1899ac (568 bytes) */
int FUN_001899ac(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  int *param_3;
  undefined4 param_4;
  int param_5;
{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int *local_68 [13];
  
  iVar6 = 0;
  do {
    iVar7 = 0;
    piVar11 = param_2;
    do {
      iVar8 = 1;
      if (piVar11 != (int *)0x0) {
        for (; iVar5 = (**(code **)(*piVar11 + 0x14))(piVar11), iVar8 <= iVar5; iVar8 = iVar8 + 1) {
          piVar3 = (int *)FUN_00105594(piVar11,iVar8);
          iVar4 = (**(code **)(*piVar3 + 0x60))();
          iVar5 = iVar8;
          piVar10 = piVar11;
          if (iVar4 == 0) {
LAB_00189a60:
            iVar4 = (**(code **)(*piVar3 + 0x48))(piVar3);
            if ((iVar4 != 0) && (piVar3[0x4b] == 3)) {
              if (iVar6 < 1) {
                iVar4 = 0;
LAB_00189ab0:
                local_68[iVar6] = piVar3;
                iVar6 = iVar6 + 1;
              }
              else {
                iVar4 = 0;
                iVar9 = iVar6;
                piVar2 = local_68;
                while (piVar3 != piVar2) {
                  iVar4 = iVar4 + 1;
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_00189ab0;
                  piVar2 = local_68[iVar4];
                }
              }
              iVar9 = 0;
              if (iVar4 < param_5) {
                do {
                  iVar4 = FUN_001054ec(piVar10,iVar5);
                  if (*(char *)(iVar9 + iVar4 + 0x10) != '\x04') {
                    (**(code **)(*piVar10 + 0x88))(piVar10,iVar5,iVar9,3);
                  }
                  bVar1 = iVar9 != 3;
                  iVar9 = iVar9 + 1;
                } while (bVar1);
                *(undefined1 *)((int)piVar3 + 0x9f) = 0;
              }
              else {
                do {
                  iVar4 = FUN_001054ec(piVar10,iVar5);
                  if (*(char *)(iVar9 + iVar4 + 0x10) != '\x04') {
                    (**(code **)(*piVar10 + 0x88))(piVar10,iVar5,iVar9,0);
                  }
                  bVar1 = iVar9 != 3;
                  iVar9 = iVar9 + 1;
                } while (bVar1);
                *(undefined1 *)(piVar3 + 0x27) = 0;
              }
            }
          }
          else {
            iVar5 = FUN_0010497c(piVar3,*(undefined4 *)(*(int *)(param_1 + 8) + 0x6c4));
            if (iVar5 != 0) {
              piVar2 = (int *)FUN_00105594(piVar3,1);
              iVar5 = 1;
              piVar10 = piVar3;
              piVar3 = piVar2;
              goto LAB_00189a60;
            }
          }
        }
      }
      bVar1 = iVar7 == 1;
      iVar7 = iVar7 + 1;
      if (bVar1) {
        return;
      }
      piVar11 = param_3;
    } while (iVar7 != 0);
  } while( true );
}

/* FUN_00189be4 @ 0x189be4 (64 bytes) */
int FUN_00189be4(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_2 + 0x88) + 8);
  if ((iVar1 == 0x1e) || (iVar1 == 0x1d)) {
    return 1;
  }
  if ((iVar1 != 0x1c) && (iVar1 != 0xa3)) {
    return 0;
  }
  return 2;
}

/* FUN_00189c24 @ 0x189c24 (188 bytes) */
int FUN_00189c24(param_1)
  int *param_1;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = 0;
  (**(code **)(*param_1 + 0x5c))();
  iVar4 = *(int *)(param_1[0x22] + 8);
  iVar1 = FUN_00105594(param_1,1);
  uVar3 = *(uint *)(iVar1 + 0x94);
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
  if (1 < iVar1) {
    iVar1 = FUN_00105594(param_1,2);
    uVar2 = *(uint *)(iVar1 + 0x94) & 0xfff;
  }
  iVar1 = FUN_001054ec(param_1,0);
  return uVar2 | iVar4 << 0x19 | -(*(byte *)(iVar1 + 0x13) ^ 1) >> 7 & 0x1000000 |
                 (uVar3 & 0xfff) << 0xc;
}

/* FUN_00189ce0 @ 0x189ce0 (276 bytes) */
int FUN_00189ce0(param_1, param_2)
  int *param_1;
  int *param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (**(code **)(*param_1 + 0x5c))();
  if (iVar2 != 0) {
    (**(code **)(*param_2 + 0x5c))(param_2);
  }
  if (*(int *)(param_1[0x22] + 8) == *(int *)(param_2[0x22] + 8)) {
    iVar2 = FUN_001054ec(param_1,0);
    cVar1 = *(char *)(iVar2 + 0x13);
    iVar2 = FUN_001054ec(param_2,0);
    if (cVar1 == *(char *)(iVar2 + 0x13)) {
      iVar2 = FUN_00105594(param_1,1);
      iVar3 = FUN_00105594(param_2,1);
      if (iVar2 == iVar3) {
        iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
        if (1 < iVar2) {
          iVar2 = FUN_00105594(param_1,2);
          iVar3 = FUN_00105594(param_2,2);
          if (iVar2 != iVar3) {
            return 0xffffffff;
          }
        }
        return 0;
      }
    }
  }
  return 0xffffffff;
}

/* FUN_00189df4 @ 0x189df4 (480 bytes) */
int FUN_00189df4(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int *param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = (**(code **)(*param_1 + 0x28))();
  if ((iVar2 == 0) && (*(int *)(param_1[0x22] + 4) != 1)) {
    iVar4 = *(int *)(param_1[0x22] + 8);
    iVar2 = iVar4;
    if ((iVar4 - 0x1cU < 3) || (iVar4 == 0xa3)) {
      if (((iVar4 == 0x1d) || (iVar4 == 0xa3)) ||
         (iVar4 = FUN_001054ec(param_1,0), *(char *)(iVar4 + 0x13) == '\0')) {
        iVar4 = 0x97;
      }
      else {
        iVar4 = -1;
      }
LAB_00189f70:
      if (iVar2 < 0) goto LAB_00189f94;
LAB_00189f84:
      if (*param_2 < 0) {
        *param_2 = iVar2;
        goto LAB_00189f94;
      }
    }
    else {
      if (((((iVar4 != 0x37) && (iVar4 != 0x3a)) &&
           ((iVar4 != 0x3b && ((iVar4 != 0x3e && (iVar4 != 0x3f)))))) && (iVar4 != 0x40)) &&
         ((((iVar4 != 0x41 && (iVar4 != 0x42)) && (iVar4 != 0x43)) &&
          ((iVar4 != 0x4c && (iVar4 != 0x4d)))))) {
        iVar2 = FUN_001054ec(param_1,0);
        uVar1 = *(uint *)(iVar2 + 0x10);
        if ((uVar1 >> 0x18 == 0) ||
           (((uVar1 >> 0x10 & 0xff) == 0 || (iVar2 = -1, (uVar1 >> 8 & 0xff) == 0)))) {
          iVar2 = iVar4;
        }
        if ((uVar1 & 0xff) != 0) {
          iVar4 = -1;
        }
        goto LAB_00189f70;
      }
      iVar2 = FUN_001054ec(param_1,0);
      uVar1 = *(uint *)(iVar2 + 0x10);
      if (((uVar1 >> 0x18 == 0) || ((uVar1 >> 0x10 & 0xff) == 0)) || ((uVar1 >> 8 & 0xff) == 0)) {
        iVar2 = 0x98;
        goto LAB_00189f84;
      }
LAB_00189f94:
      if (iVar4 < 0) goto LAB_00189fb4;
      if (*param_3 < 0) {
        *param_3 = iVar4;
        return 1;
      }
    }
    uVar3 = 0;
  }
  else {
LAB_00189fb4:
    uVar3 = 1;
  }
  return uVar3;
}

/* FUN_00189fd4 @ 0x189fd4 (172 bytes) */
int FUN_00189fd4(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  int *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int iVar1;
  undefined4 uVar2;
  int local_28;
  int local_24 [7];
  
  local_24[0] = -1;
  local_28 = -1;
  if ((param_2[5] & 0x8000U) == 0) {
    iVar1 = (**(code **)(*param_2 + 0x28))(param_2);
    if (iVar1 == 0) {
      ((int (*)())FUN_00189df4)(param_2,&local_28,local_24);
      if (local_28 < 0) {
        if (-1 < local_24[0]) {
          return 2;
        }
        goto LAB_0018a060;
      }
      if (local_24[0] < 0) {
        return 1;
      }
    }
    uVar2 = 3;
  }
  else {
LAB_0018a060:
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_0018a080 @ 0x18a080 (364 bytes) */
int FUN_0018a080(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  
  iVar1 = (**(code **)(*param_2 + 0x30))(param_2);
  if (iVar1 != 0) {
    iVar1 = FUN_001054ec(param_2,1);
    uVar2 = ((int (*)())FUN_0018976c)(*(undefined4 *)(iVar1 + 0x10));
    return uVar2;
  }
  iVar4 = 1;
  iVar1 = (**(code **)(*param_2 + 0x5c))(param_2);
  if (iVar1 == 0) {
    for (; iVar1 = (**(code **)(*param_2 + 0x14))(param_2), iVar4 <= iVar1; iVar4 = iVar4 + 1) {
      iVar1 = FUN_001054ec(param_2,iVar4);
      uVar2 = *(undefined4 *)(iVar1 + 0x10);
      piVar3 = (int *)FUN_00105594(param_2,iVar4);
      iVar1 = (**(code **)(*piVar3 + 0x5c))();
      if (iVar1 == 0) {
        iVar1 = ((int (*)())FUN_001896f8)(uVar2);
      }
      else {
        iVar1 = ((int (*)())FUN_00189788)(uVar2);
      }
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  else {
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar1 != 1) {
      iVar1 = FUN_001054ec(param_2,1);
      iVar4 = *(int *)(iVar1 + 0x10);
      iVar1 = FUN_001054ec(param_2,2);
      if (iVar4 != *(int *)(iVar1 + 0x10)) {
        return 0;
      }
    }
  }
  return 1;
}

/* FUN_0018a1ec @ 0x18a1ec (596 bytes) */
int FUN_0018a1ec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int *param_2;
  int param_3;
  int param_4;
  int *param_5;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  
  *param_5 = 0;
  iVar2 = FUN_001054ec(param_2,param_3);
  uVar5 = *(uint *)(iVar2 + 0x10);
  iVar2 = (**(code **)(*param_2 + 0x28))(param_2);
  if (iVar2 == 0) {
    iVar2 = (**(code **)(*param_2 + 0x5c))(param_2);
    if (iVar2 != 0) {
      iVar2 = FUN_000f31e8(param_2,1);
      if (iVar2 == 0) {
        return;
      }
      iVar2 = (**(code **)(*param_2 + 0x14))(param_2);
      if (iVar2 == 1) {
        return;
      }
      FUN_000f31e8(param_2,2);
      return;
    }
    piVar3 = (int *)FUN_00105594(param_2,param_3);
    iVar2 = (**(code **)(*piVar3 + 0x5c))();
    if (iVar2 == 0) {
      iVar2 = ((int (*)())FUN_001896f8)(uVar5);
    }
    else {
      iVar2 = ((int (*)())FUN_00189788)(uVar5);
    }
  }
  else {
    if (param_3 != 1) {
      return;
    }
    iVar2 = ((int (*)())FUN_0018976c)(uVar5);
  }
  if (iVar2 == 0) {
    iVar2 = ((uVar5 >> 0x18) * 0x7d + (uVar5 >> 0x10 & 0xff) * 0x19 + (uVar5 >> 8 & 0xff) * 5 +
            (uVar5 & 0xff)) * 4;
    if (((uint)(byte)DAT_001b2a68 << 0x18 | (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 2)) << 0x10 |
         (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 1)) << 8 | (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 0))) !=
        *(uint *)(&DAT_001b0240 + (iVar2 + *param_5) * 4)) {
      do {
        uVar4 = *(uint *)(&DAT_001b0240 + (iVar2 + *param_5) * 4);
        *(uint *)(*param_5 * 4 + param_4) =
             uVar4 << 0x18 | (uVar4 & 0xff00) << 8 | uVar4 >> 8 & 0xff00 | uVar4 >> 0x18;
        iVar1 = *param_5;
        *param_5 = iVar1 + 1;
      } while (*(uint *)(&DAT_001b0240 + (iVar2 + iVar1 + 1) * 4) !=
               ((uint)(byte)DAT_001b2a68 << 0x18 | (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 2)) << 0x10 |
                (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 1)) << 8 | (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 0))));
    }
    if (uVar5 >> 0x18 != 4) {
      uVar5 = uVar5 & 0xffffff;
    }
    if ((uVar5 >> 0x10 & 0xff) != 4) {
      uVar5 = uVar5 & 0xff00ffff | 0x10000;
    }
    if ((uVar5 >> 8 & 0xff) != 4) {
      uVar5 = uVar5 & 0xffff00ff | 0x200;
    }
    if ((uVar5 & 0xff) != 4) {
      uVar5 = uVar5 & 0xffffff00 | 3;
    }
    iVar2 = FUN_001054ec(param_2,param_3);
    *(uint *)(iVar2 + 0x10) = uVar5;
  }
  return;
}

/* FUN_0018a440 @ 0x18a440 (232 bytes) */
int FUN_0018a440(param_1, param_2)
  int *param_1;
  int param_2;
{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  undefined4 uVar16;
  uint uVar17;
  int iVar18;
  double dVar19;
  undefined4 local_78;
  int local_74 [3];
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  int local_5c;
  int local_58;
  
  iVar14 = *(int *)(param_2 + 900);
  if (*(int *)(iVar14 + 8) != 0) {
    local_5c = 0x18a450;
    local_58 = 0x18a450;
    do {
      uVar16 = *(undefined4 *)(param_1[2] + 0x378);
      puVar5 = (undefined4 *)FUN_00193e18(uVar16,0x1c);
      puVar15 = puVar5 + 1;
      *puVar5 = uVar16;
      puVar5[4] = local_5c + -0x770;
      uVar3 = 1;
      iVar18 = 0x20;
      puVar5[1] = 1;
      puVar5[5] = local_58 + -0x82c;
      puVar5[6] = uVar16;
      do {
        uVar3 = uVar3 << 1;
        if (0xf < uVar3) break;
        iVar18 = iVar18 + -1;
      } while (iVar18 != 0);
      *puVar15 = uVar3;
      puVar5[2] = 0;
      uVar16 = FUN_00193e18(uVar16,*puVar15 << 2);
      puVar5[3] = uVar16;
      _memset(uVar16,0,*puVar15 << 2);
      piVar2 = *(int **)(iVar14 + 0x98);
      for (piVar4 = (int *)(*(int **)(iVar14 + 0x98))[2]; piVar4 != (int *)0x0;
          piVar4 = (int *)piVar4[2]) {
        if ((piVar2[5] & 1U) != 0) {
          if ((*(int *)(piVar2[0x22] + 8) == 0x31) || (*(int *)(piVar2[0x22] + 8) == 0x30)) {
            piVar4 = (int *)FUN_00105594(piVar2,1);
            iVar18 = (**(code **)(*piVar4 + 0x5c))();
            if ((iVar18 != 0) && ((piVar2[0x2e] & 2U) == 0)) {
              piVar4 = (int *)FUN_00105594(piVar2,1);
              iVar18 = piVar2[0x49];
              if (*(int *)(piVar4[0x22] + 8) == 0x99) {
                iVar18 = iVar18 + 1;
              }
              iVar10 = (**(code **)(**(int **)(param_1[2] + 0x30c) + 0xfc))
                                 (*(int **)(param_1[2] + 0x30c),iVar18,0);
              if (iVar10 != 0) {
                iVar9 = piVar2[1];
                iVar8 = 0;
                iVar11 = piVar2[0x25];
                iVar12 = piVar2[0x26];
                iVar10 = FUN_001054ec(piVar2,0);
                iVar13 = *(int *)(iVar10 + 0x10);
                iVar10 = FUN_001054ec(piVar2,1);
                uVar17 = piVar2[5];
                uVar3 = piVar2[0x2e] & 1;
                uVar16 = *(undefined4 *)(iVar10 + 0x10);
                iVar10 = piVar2[0x48];
                if ((uVar17 & 0x200) != 0) {
                  iVar8 = FUN_00105594(piVar2,piVar2[0x21]);
                }
                FUN_0019401c(piVar2);
                FUN_00108174(piVar2,0x12,*(undefined4 *)(param_2 + 8));
                piVar2[0x27] = iVar13;
                piVar2[0x48] = iVar10;
                piVar2[0x49] = iVar18;
                piVar2[0x25] = iVar11;
                piVar2[0x26] = iVar12;
                if ((uVar17 & 0x40) == 0) {
                  piVar2[5] = piVar2[5] & 0xffffffbf;
                }
                else {
                  piVar2[5] = piVar2[5] | 0x40;
                }
                if ((uVar17 & 2) != 0) {
                  FUN_0010469c(piVar2,*(undefined4 *)(param_1[2] + 0x6c4),iVar12,iVar11);
                }
                if (iVar8 != 0) {
                  FUN_00106804(piVar2,iVar8,0,param_1[2]);
                }
                FUN_000e7738(iVar14,iVar9,piVar2);
                iVar18 = *(int *)(piVar4[0x22] + 8);
                if (iVar18 == 0x9a) {
                  uVar6 = FUN_00105594(piVar4,1);
                  FUN_00106004(piVar2,1,uVar6,0,param_1[2]);
                  uVar6 = FUN_00105594(piVar4,2);
                  FUN_00106004(piVar2,2,uVar6,0,param_1[2]);
                  iVar18 = FUN_001054ec(piVar2,1);
                  *(undefined4 *)(iVar18 + 0x10) = uVar16;
                  iVar18 = FUN_001054ec(piVar2,2);
                  *(undefined4 *)(iVar18 + 0x10) = uVar16;
                  FUN_00103d50(piVar2 + 0x29,1,uVar3);
                  FUN_00103d50(piVar2 + 0x2f,1,uVar3 ^ 1);
                }
                else {
                  if (iVar18 < 0x9b) {
                    if (iVar18 != 0x99) goto code_r0x0018a910;
                    uVar6 = FUN_00105594(piVar4,1);
                    FUN_00106004(piVar2,1,uVar6,0,param_1[2]);
                    dVar19 = (double)FLOAT_001aa10c;
                    ((void (*)())FUN_000f79c4)(piVar2,param_2,2,dVar19,dVar19,dVar19,dVar19);
                    iVar18 = FUN_001054ec(piVar2,1);
                    *(undefined4 *)(iVar18 + 0x10) = uVar16;
                    uVar17 = uVar3 ^ 1;
                  }
                  else if (iVar18 == 0x9b) {
                    uVar6 = FUN_00105594(piVar4,1);
                    FUN_00106004(piVar2,1,uVar6,0,param_1[2]);
                    uVar6 = FUN_00105594(piVar4,2);
                    FUN_00106004(piVar2,2,uVar6,0,param_1[2]);
                    iVar18 = FUN_001054ec(piVar2,1);
                    *(undefined4 *)(iVar18 + 0x10) = uVar16;
                    iVar18 = FUN_001054ec(piVar2,2);
                    *(undefined4 *)(iVar18 + 0x10) = uVar16;
                    uVar17 = uVar3;
                  }
                  else {
                    if (iVar18 != 0x9c) goto code_r0x0018a910;
                    uVar6 = FUN_00105594(piVar4,1);
                    FUN_00106004(piVar2,1,uVar6,0,param_1[2]);
                    dVar19 = (double)FLOAT_001aa0e8;
                    ((void (*)())FUN_000f79c4)(piVar2,param_2,2,dVar19,dVar19,dVar19,dVar19);
                    iVar18 = FUN_001054ec(piVar2,1);
                    *(undefined4 *)(iVar18 + 0x10) = uVar16;
                    uVar17 = uVar3 ^ 1;
                  }
                  FUN_00103d50(piVar2 + 0x29,1,uVar17);
                  FUN_00103d50(piVar2 + 0x2f,1,uVar3);
                }
code_r0x0018a910:
                (**(code **)(*piVar4 + 0xc))(piVar4,0,param_1[2]);
                piVar4 = (int *)piVar2[2];
                goto code_r0x0018aab8;
              }
            }
          }
          for (iVar18 = 1; iVar10 = (**(code **)(*piVar2 + 0x14))(piVar2), iVar18 <= iVar10;
              iVar18 = iVar18 + 1) {
            piVar4 = (int *)FUN_00105594(piVar2,iVar18);
            iVar10 = (**(code **)(*piVar4 + 0x5c))();
            if (iVar10 != 0) {
              piVar7 = (int *)FUN_00194834(puVar15,piVar4);
              if (piVar7 == (int *)0x0) {
                FUN_00194d44(puVar15,piVar4);
              }
              else if (piVar4 != piVar7) {
                iVar10 = FUN_001054ec(piVar7,0);
                local_74[0] = *(int *)(iVar10 + 0x10);
                iVar9 = FUN_001054ec(piVar4,0);
                iVar10 = DAT_001b2a64;
                iVar8 = 0;
                local_78 = *(undefined4 *)(iVar9 + 0x10);
                iVar9 = 4;
                do {
                  cVar1 = *(char *)((int)local_74 + iVar8 + -4);
                  if (cVar1 != '\x01') {
                    *(char *)((int)local_74 + iVar8) = cVar1;
                  }
                  iVar8 = iVar8 + 1;
                  iVar9 = iVar9 + -1;
                } while (iVar9 != 0);
                piVar7[0x27] = local_74[0];
                FUN_000f3908(&local_68,local_74[0]);
                FUN_000f3340(&local_64,iVar10,local_68);
                uVar16 = local_64;
                iVar10 = FUN_001054ec(piVar7,1);
                *(undefined4 *)(iVar10 + 0x10) = uVar16;
                iVar10 = (**(code **)(*piVar7 + 0x14))(piVar7);
                if (1 < iVar10) {
                  iVar10 = FUN_001054ec(piVar7,2);
                  *(undefined4 *)(iVar10 + 0x10) = uVar16;
                }
                FUN_00106004(piVar2,iVar18,piVar7,0,param_1[2]);
                (**(code **)(*piVar4 + 0xc))(piVar4,0,param_1[2]);
              }
            }
          }
          piVar4 = (int *)piVar2[2];
        }
code_r0x0018aab8:
        piVar2 = piVar4;
      }
      if (puVar15 != (uint *)0x0) {
        uVar3 = *puVar15;
        if (uVar3 == 0) {
          iVar18 = puVar5[3];
        }
        else {
          iVar18 = puVar5[3];
          uVar17 = 0;
          do {
            iVar10 = *(int *)(uVar17 * 4 + iVar18);
            if (iVar10 != 0) {
              FUN_00193cc0(puVar5[6],iVar10);
              uVar3 = *puVar15;
              iVar18 = puVar5[3];
            }
            uVar17 = uVar17 + 1;
          } while (uVar17 < uVar3);
        }
        FUN_00193cc0(puVar5[6],iVar18);
        FUN_00193cc0(*puVar5,puVar5);
      }
      piVar2 = *(int **)(iVar14 + 0x98);
      for (piVar4 = (int *)(*(int **)(iVar14 + 0x98))[2]; piVar4 != (int *)0x0;
          piVar4 = (int *)piVar4[2]) {
        if ((piVar2[5] & 1U) != 0) {
          iVar10 = 1;
          iVar18 = FUN_000e07dc(param_1[2],0x41);
          if (iVar18 != 0) {
            for (; iVar18 = (**(code **)(*piVar2 + 0x14))(piVar2), iVar10 <= iVar18;
                iVar10 = iVar10 + 1) {
              piVar4 = (int *)FUN_00105594(piVar2,iVar10);
              iVar18 = (**(code **)(*piVar4 + 0x80))();
              iVar8 = FUN_001054ec(piVar2,iVar10);
              FUN_000f39d0(&local_60,*(undefined4 *)(iVar8 + 0x10));
              uVar3 = local_60;
              iVar8 = FUN_001054ec(piVar2,iVar10);
              uVar17 = *(uint *)(iVar8 + 0x10);
              if ((((iVar18 != 0) &&
                   (((iVar9 = FUN_001054ec(iVar18,0), iVar8 = _UNK_001b2a7c,
                     *(char *)(iVar9 + 0x12) == '\x01' || (*(int *)(iVar18 + 0xb4) == _UNK_001b2a7c)
                     ) && ((uVar3 >> 8 & 0xff) != 0)))) && ((uVar17 >> 8 & 0xff) == 3)) &&
                 (((uVar3 >> 0x18 != 0 && (uVar17 >> 0x18 == 0)) ||
                  (((uVar3 >> 0x10 & 0xff) != 0 && ((uVar17 >> 0x10 & 0xff) == 1)))))) {
                *(undefined1 *)(iVar18 + 0xe) = 1;
                *(int *)(iVar18 + 0xb4) = iVar8;
                *(undefined1 *)(iVar18 + 0x9e) = 0;
                iVar18 = DAT_001b2a64;
                if (iVar10 == 0) {
                  piVar2[0x27] = DAT_001b2a64;
                }
                else {
                  iVar8 = FUN_001054ec(piVar2,iVar10);
                  *(int *)(iVar8 + 0x10) = iVar18;
                }
              }
            }
          }
          if (*(int *)(piVar2[0x22] + 8) == 0x8e) {
            piVar4 = (int *)piVar2[2];
          }
          else {
            (**(code **)(*param_1 + 0x6c))(param_1,piVar2);
            piVar4 = (int *)piVar2[2];
          }
        }
        piVar2 = piVar4;
      }
      iVar14 = *(int *)(iVar14 + 8);
    } while (*(int *)(iVar14 + 8) != 0);
  }
  return;
}

/* FUN_0018ad08 @ 0x18ad08 (1204 bytes) */
int FUN_0018ad08(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int *param_3;
  undefined4 *param_4;
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  
  iVar1 = *(int *)(*(int *)(param_2 + 0x88) + 8);
  if (iVar1 == 0x1c) {
    piVar2 = (int *)FUN_001043f0(0x13,param_1[2]);
    iVar1 = DAT_001b2a70;
    piVar2[0x25] = piVar2[0x53];
    piVar2[0x27] = iVar1;
    piVar2[0x26] = 0;
    *param_4 = 3;
    uVar3 = FUN_001054ec(param_2,1);
    FUN_001062c0(piVar2,1,uVar3,param_1[2]);
    uVar3 = FUN_001054ec(param_2,2);
    FUN_001062c0(piVar2,2,uVar3,param_1[2]);
    piVar2[3] = 0;
    uVar3 = DAT_001b2a68;
    *(undefined1 *)((int)piVar2 + 0xf) = 1;
    *param_3 = 2;
    do {
      iVar1 = FUN_001054ec(piVar2,1);
      *(undefined4 *)(iVar1 + 0x10) = uVar3;
      iVar5 = *param_3;
      pcVar4 = *(code **)(*piVar2 + 0x88);
      iVar1 = FUN_001054ec(param_2,1);
      (*pcVar4)(piVar2,1,3,*(undefined1 *)(iVar5 + iVar1 + 0x10));
      iVar1 = FUN_001054ec(piVar2,2);
      *(undefined4 *)(iVar1 + 0x10) = uVar3;
      iVar5 = *param_3;
      pcVar4 = *(code **)(*piVar2 + 0x88);
      iVar1 = FUN_001054ec(param_2,2);
      (*pcVar4)(piVar2,2,3,*(undefined1 *)(iVar5 + iVar1 + 0x10));
      iVar1 = (**(code **)(*param_1 + 0xc))(param_1,piVar2);
      if (iVar1 != 0) {
        return piVar2;
      }
    } while (((*(uint *)(*(int *)(param_1[2] + 0x30c) + 8) & 0x400) != 0) &&
            (iVar1 = *param_3, *param_3 = iVar1 + -1, -1 < iVar1 + -1));
  }
  else {
    if (iVar1 != 0x1e) {
      if (iVar1 != 0x1d) {
        return (int *)0x0;
      }
      piVar2 = (int *)FUN_001043f0(0x1c,param_1[2]);
      iVar1 = DAT_001b2a6c;
      piVar2[0x25] = piVar2[0x53];
      piVar2[0x27] = iVar1;
      piVar2[0x26] = 0;
      *param_4 = 1;
      *param_3 = 3;
      uVar3 = FUN_001054ec(param_2,1);
      FUN_001062c0(piVar2,1,uVar3,param_1[2]);
      uVar3 = FUN_001054ec(param_2,2);
      FUN_001062c0(piVar2,2,uVar3,param_1[2]);
      (**(code **)(*piVar2 + 0x88))(piVar2,1,3,4);
      (**(code **)(*piVar2 + 0x88))(piVar2,2,3,4);
      piVar2[3] = 0;
      *(undefined1 *)(piVar2 + 3) = 1;
      iVar1 = (**(code **)(*param_1 + 0xc))(param_1,piVar2);
      if (iVar1 != 0) {
        return piVar2;
      }
      iVar1 = *piVar2;
      goto LAB_0018b190;
    }
    piVar2 = (int *)FUN_001043f0(0x14,param_1[2]);
    iVar1 = DAT_001b2a70;
    piVar2[0x25] = piVar2[0x53];
    piVar2[0x27] = iVar1;
    piVar2[0x26] = 0;
    *param_4 = 3;
    uVar3 = FUN_001054ec(param_2,1);
    FUN_001062c0(piVar2,1,uVar3,param_1[2]);
    uVar3 = FUN_001054ec(param_2,2);
    FUN_001062c0(piVar2,2,uVar3,param_1[2]);
    uVar3 = FUN_001054ec(param_2,3);
    FUN_001062c0(piVar2,3,uVar3,param_1[2]);
    piVar2[3] = 0;
    uVar3 = DAT_001b2a68;
    *(undefined1 *)((int)piVar2 + 0xf) = 1;
    *param_3 = 1;
    do {
      iVar1 = FUN_001054ec(piVar2,1);
      *(undefined4 *)(iVar1 + 0x10) = uVar3;
      iVar5 = *param_3;
      pcVar4 = *(code **)(*piVar2 + 0x88);
      iVar1 = FUN_001054ec(param_2,1);
      (*pcVar4)(piVar2,1,3,*(undefined1 *)(iVar5 + iVar1 + 0x10));
      iVar1 = FUN_001054ec(piVar2,2);
      *(undefined4 *)(iVar1 + 0x10) = uVar3;
      iVar5 = *param_3;
      pcVar4 = *(code **)(*piVar2 + 0x88);
      iVar1 = FUN_001054ec(param_2,2);
      (*pcVar4)(piVar2,2,3,*(undefined1 *)(iVar5 + iVar1 + 0x10));
      iVar1 = FUN_001054ec(piVar2,3);
      *(undefined4 *)(iVar1 + 0x10) = uVar3;
      pcVar4 = *(code **)(*piVar2 + 0x88);
      iVar1 = FUN_001054ec(param_2,3);
      (*pcVar4)(piVar2,3,3,*(undefined1 *)(iVar1 + 0x12));
      iVar1 = (**(code **)(*param_1 + 0xc))(param_1,piVar2);
      if (iVar1 != 0) {
        return piVar2;
      }
      iVar1 = *param_3;
      *param_3 = iVar1 + -1;
    } while (-1 < iVar1 + -1);
  }
  iVar1 = *piVar2;
LAB_0018b190:
  (**(code **)(iVar1 + 4))(piVar2);
  return (int *)0x0;
}

/* FUN_0018b1bc @ 0x18b1bc (1176 bytes) */
int FUN_0018b1bc(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  
  bVar1 = param_3 <= param_4;
  if (bVar1) {
    puVar3 = (undefined4 *)(param_3 * 4 + param_2 + 0x48);
    iVar10 = param_3;
    do {
      iVar10 = iVar10 + 1;
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    } while (iVar10 <= param_4);
  }
  puVar15 = *(uint **)(param_2 + 0x40);
  uVar14 = 0;
  uVar12 = puVar15[1];
  if (0 < (int)uVar12) {
    while( true ) {
      if (uVar14 < *puVar15) {
        uVar5 = puVar15[1];
        if (uVar5 <= uVar14) {
          _memset(uVar5 * 4 + puVar15[2],0,(uVar14 - uVar5) * 4 + 4);
          puVar15[1] = uVar14 + 1;
        }
        piVar6 = (int *)(uVar14 * 4 + puVar15[2]);
      }
      else {
        piVar6 = (int *)FUN_0019423c(puVar15,uVar14);
      }
      uVar14 = uVar14 + 1;
      iVar10 = *piVar6;
      if (*(int *)(iVar10 + 8) == 0) {
        if (bVar1) {
          puVar4 = (undefined1 *)(param_3 + iVar10 + 0x18);
          iVar11 = param_3;
          do {
            iVar11 = iVar11 + 1;
            *puVar4 = 0;
            puVar4 = puVar4 + 1;
          } while (iVar11 <= param_4);
        }
        *(undefined1 *)(param_5 + iVar10 + 0x18) = 1;
        iVar11 = param_5 * 4 + param_2;
        *(int *)(iVar11 + 0x48) = *(int *)(iVar11 + 0x48) + 1;
        iVar11 = *(int *)(iVar10 + 4);
        piVar6 = *(int **)(iVar11 + 0x38);
        if ((piVar6[5] & 0x200U) != 0) {
          FUN_00105594(piVar6,piVar6[0x21]);
        }
        (**(code **)(*piVar6 + 0x28))(piVar6);
        iVar7 = (**(code **)(*piVar6 + 0x5c))(piVar6);
        if (iVar7 == 0) {
          piVar9 = (int *)FUN_00105594(piVar6,*(undefined4 *)(iVar10 + 0x10));
          iVar11 = (**(code **)(*piVar9 + 0x60))();
          if (iVar11 == 0) {
            iVar11 = 0;
            do {
              iVar7 = FUN_001054ec(piVar6,*(undefined4 *)(iVar10 + 0x10));
              uVar5 = (uint)*(byte *)(iVar11 + iVar7 + 0x10);
              if ((param_3 <= (int)uVar5) && ((int)uVar5 <= param_4)) {
                (**(code **)(*piVar6 + 0x88))(piVar6,*(undefined4 *)(iVar10 + 0x10),iVar11,param_5);
              }
              bVar2 = iVar11 != 3;
              iVar11 = iVar11 + 1;
            } while (bVar2);
          }
        }
        else {
          iVar10 = (**(code **)(*piVar6 + 0x14))(piVar6);
          if (1 < iVar10) {
            FUN_00105594(piVar6,1);
            FUN_00105594(piVar6,2);
          }
          if (bVar1) {
            puVar4 = (undefined1 *)((int)piVar6 + param_3 + 0xc);
            iVar10 = param_3;
            do {
              puVar4[0x90] = 1;
              iVar7 = *piVar6;
              *puVar4 = 0;
              (**(code **)(iVar7 + 0x88))(piVar6,1,iVar10,4);
              iVar7 = (**(code **)(*piVar6 + 0x14))(piVar6);
              if (iVar7 == 2) {
                (**(code **)(*piVar6 + 0x88))(piVar6,2,iVar10,4);
              }
              iVar10 = iVar10 + 1;
              puVar4 = puVar4 + 1;
            } while (iVar10 <= param_4);
          }
          *(undefined1 *)((int)piVar6 + param_5 + 0x9c) = 0;
          iVar10 = *piVar6;
          *(undefined1 *)((int)piVar6 + param_5 + 0xc) = 1;
          (**(code **)(iVar10 + 0x88))(piVar6,1,param_5,param_5);
          iVar10 = (**(code **)(*piVar6 + 0x14))(piVar6);
          if (iVar10 == 2) {
            (**(code **)(*piVar6 + 0x88))(piVar6,2,param_5,param_5);
          }
          if (bVar1) {
            puVar3 = (undefined4 *)(param_3 * 4 + iVar11 + 0x48);
            iVar10 = param_3;
            do {
              iVar10 = iVar10 + 1;
              *puVar3 = 0;
              puVar3 = puVar3 + 1;
            } while (iVar10 <= param_4);
          }
          puVar15 = *(uint **)(iVar11 + 0x40);
          uVar5 = 0;
          uVar13 = puVar15[1];
          if (0 < (int)uVar13) {
            while( true ) {
              if (uVar5 < *puVar15) {
                uVar8 = puVar15[1];
                if (uVar8 <= uVar5) {
                  _memset(uVar8 * 4 + puVar15[2],0,(uVar5 - uVar8) * 4 + 4);
                  puVar15[1] = uVar5 + 1;
                }
                piVar6 = (int *)(uVar5 * 4 + puVar15[2]);
              }
              else {
                piVar6 = (int *)FUN_0019423c(puVar15,uVar5);
              }
              uVar5 = uVar5 + 1;
              iVar10 = *piVar6;
              if (*(int *)(iVar10 + 8) == 0) {
                if (bVar1) {
                  puVar4 = (undefined1 *)(param_3 + iVar10 + 0x18);
                  iVar7 = param_3;
                  do {
                    iVar7 = iVar7 + 1;
                    *puVar4 = 0;
                    puVar4 = puVar4 + 1;
                  } while (iVar7 <= param_4);
                }
                *(undefined1 *)(param_5 + iVar10 + 0x18) = 1;
                iVar10 = param_5 * 4 + iVar11;
                *(int *)(iVar10 + 0x48) = *(int *)(iVar10 + 0x48) + 1;
              }
              if (uVar13 == uVar5) break;
              puVar15 = *(uint **)(iVar11 + 0x40);
            }
          }
        }
      }
      if (uVar12 == uVar14) break;
      puVar15 = *(uint **)(param_2 + 0x40);
    }
  }
  return;
}

/* FUN_0018b654 @ 0x18b654 (888 bytes) */
int FUN_0018b654(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  undefined4 local_48;
  
  pbVar6 = *(byte **)(param_2 + 0x60);
  local_48 = DAT_001b2a78;
  if (pbVar6 != (byte *)0x0) {
    uVar3 = (DAT_001b2a78 << 0x18 | (DAT_001b2a78 >> 8 & 0xff) << 0x10 |
             (DAT_001b2a78 >> 0x10 & 0xff) << 8 | DAT_001b2a78 >> 0x18) -
            ((uint)pbVar6[3] << 0x18 | (uint)pbVar6[2] << 0x10 | (uint)pbVar6[1] << 8 |
            (uint)*pbVar6);
    local_48 = uVar3 * 0x1000000 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
    iVar4 = *(int *)(*(int *)(param_2 + 0x60) + 4);
    if (-1 < iVar4) {
      iVar9 = 4;
      iVar7 = 0;
      do {
        iVar5 = *(int *)(iVar4 * 4 + *(int *)(param_3 + iVar7 * 4));
        if ((iVar5 != 0) && (*(int *)(iVar7 * 4 + iVar5 + 0x48) != 0)) {
          *(undefined1 *)((int)&local_48 + iVar7) = 0;
        }
        iVar7 = iVar7 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
  }
  if (local_48 == DAT_001b2a74) {
    return 0;
  }
  piVar8 = *(int **)(param_2 + 0x38);
  FUN_000f3a30(piVar8);
  iVar4 = FUN_001054ec(piVar8,0);
  if (*(char *)(iVar4 + 0x13) == '\0') {
    if (local_48 == DAT_001b2a78) {
      iVar7 = param_1[0x1a];
      param_1[0x1a] = iVar7 + 1;
      if (2 < iVar7 + 1) {
        param_1[0x1a] = 0;
      }
    }
    else {
      iVar7 = 0;
      while (*(char *)((int)&local_48 + iVar7) == '\0') {
        bVar1 = iVar7 == 2;
        iVar7 = iVar7 + 1;
        if (bVar1) {
          return 0;
        }
      }
    }
    if (iVar7 == -1) {
      return 0;
    }
    iVar4 = 3;
  }
  else {
    if ((char)local_48 == '\0') {
      return 0;
    }
    iVar4 = FUN_001054ec(piVar8,0);
    iVar7 = 3;
    iVar4 = FUN_000f30d4(*(undefined4 *)(iVar4 + 0x10));
  }
  *(undefined1 *)((int)piVar8 + iVar4 + 0x9c) = 1;
  *(undefined1 *)((int)piVar8 + iVar4 + 0xc) = 0;
  iVar5 = 1;
  *(undefined1 *)((int)piVar8 + iVar7 + 0x9c) = 0;
  iVar9 = piVar8[0x22];
  *(undefined1 *)((int)piVar8 + iVar7 + 0xc) = 1;
  if (*(int *)(PTR_DAT_001e913c + *(int *)(iVar9 + 8) * 0x38 + 0x34) == 0) {
    for (; iVar9 = (**(code **)(*piVar8 + 0x14))(piVar8), iVar5 <= iVar9; iVar5 = iVar5 + 1) {
      iVar9 = FUN_001054ec(piVar8,iVar5);
      uVar2 = *(undefined1 *)(iVar4 + iVar9 + 0x10);
      (**(code **)(*piVar8 + 0x88))(piVar8,iVar5,iVar4,4);
      (**(code **)(*piVar8 + 0x88))(piVar8,iVar5,iVar7,uVar2);
    }
  }
  iVar9 = (**(code **)(*param_1 + 0xc))(param_1,*(undefined4 *)(param_2 + 0x38));
  if (iVar9 == 0) {
    *(undefined1 *)((int)piVar8 + iVar4 + 0x9c) = 0;
    *(undefined1 *)((int)piVar8 + iVar4 + 0xc) = 1;
    iVar5 = 1;
    *(undefined1 *)((int)piVar8 + iVar7 + 0x9c) = 1;
    iVar9 = piVar8[0x22];
    *(undefined1 *)((int)piVar8 + iVar7 + 0xc) = 0;
    if (*(int *)(PTR_DAT_001e913c + *(int *)(iVar9 + 8) * 0x38 + 0x34) == 0) {
      for (; iVar9 = (**(code **)(*piVar8 + 0x14))(piVar8), iVar5 <= iVar9; iVar5 = iVar5 + 1) {
        iVar9 = FUN_001054ec(piVar8,iVar5);
        uVar2 = *(undefined1 *)(iVar7 + iVar9 + 0x10);
        (**(code **)(*piVar8 + 0x88))(piVar8,iVar5,iVar7,4);
        (**(code **)(*piVar8 + 0x88))(piVar8,iVar5,iVar4,uVar2);
      }
    }
    return 0;
  }
  *(uint *)(param_2 + 0x58) = (iVar7 == 3) + 1;
  if (*(int *)(param_2 + 0x60) != 0) {
    *(undefined1 *)(*(int *)(param_2 + 0x60) + iVar7) = 1;
  }
  ((int (*)())FUN_0018b1bc)(param_1,param_2,iVar4,iVar4,iVar7);
  return 1;
}

/* FUN_0018b9cc @ 0x18b9cc (712 bytes) */
int FUN_0018b9cc(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined1 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  
  piVar10 = *(int **)(param_2 + 0x38);
  if ((piVar10[0x20] == 0) || (iVar4 = FUN_00126760(piVar10[0x26]), iVar4 == 0)) {
    uVar2 = piVar10[5];
  }
  else {
    uVar2 = piVar10[5];
    if ((uVar2 & 2) == 0) {
      (**(code **)(*piVar10 + 0x50))(piVar10);
      uVar2 = piVar10[5];
    }
  }
  if (((uVar2 & 2) == 0) && (iVar4 = (**(code **)(*piVar10 + 0x5c))(piVar10), iVar4 == 0)) {
    (**(code **)(*piVar10 + 0x28))(piVar10);
  }
  iVar8 = *(int *)(PTR_DAT_001e913c + *(int *)(piVar10[0x22] + 8) * 0x38 + 0x34);
  iVar4 = FUN_001054ec(piVar10,0);
  if (*(char *)(iVar4 + 0x13) == '\0') {
    if ((iVar8 == 0) && (iVar4 = FUN_000f3a30(piVar10), 1 < iVar4)) {
      iVar4 = FUN_001054ec(piVar10,0);
      iVar7 = 3;
      iVar9 = FUN_000f3108(*(undefined4 *)(iVar4 + 0x10));
      iVar4 = 3;
    }
    else {
      iVar9 = *(int *)(param_1 + 0x68);
      *(int *)(param_1 + 0x68) = iVar9 + 1;
      if (iVar9 + 1 < 3) {
        iVar7 = 3;
        iVar4 = 3;
      }
      else {
        iVar7 = 3;
        *(undefined4 *)(param_1 + 0x68) = 0;
        iVar4 = 3;
      }
    }
  }
  else if (iVar8 == 5) {
    iVar7 = 0;
    iVar9 = 3;
    iVar4 = 2;
  }
  else {
    iVar4 = FUN_001054ec(piVar10,0);
    iVar9 = 3;
    iVar7 = FUN_000f30d4(*(undefined4 *)(iVar4 + 0x10));
    iVar4 = iVar7;
  }
  puVar3 = (undefined1 *)((int)piVar10 + iVar7 + 0xc);
  iVar6 = iVar7;
  do {
    iVar6 = iVar6 + 1;
    puVar3[0x90] = 1;
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  } while (iVar6 <= iVar4);
  *(undefined1 *)((int)piVar10 + iVar9 + 0xc) = 1;
  *(undefined1 *)((int)piVar10 + iVar9 + 0x9c) = 0;
  *(uint *)(param_2 + 0x58) = (iVar9 == 3) + 1;
  if (((iVar8 - 1U < 2) || (iVar8 == 5)) || (iVar6 = 1, iVar7 != iVar4)) {
    *(undefined4 *)(param_2 + 0x5c) = 0;
  }
  else {
    for (; iVar5 = (**(code **)(*piVar10 + 0x14))(piVar10), iVar6 <= iVar5; iVar6 = iVar6 + 1) {
      iVar5 = FUN_001054ec(piVar10,iVar6);
      uVar1 = *(undefined1 *)(iVar7 + iVar5 + 0x10);
      (**(code **)(*piVar10 + 0x88))(piVar10,iVar6,iVar7,4);
      (**(code **)(*piVar10 + 0x88))(piVar10,iVar6,iVar9,uVar1);
    }
    if ((iVar8 == 0) && (iVar8 = FUN_000f3a30(piVar10), 1 < iVar8)) {
      *(undefined4 *)(param_2 + 0x5c) = 0;
    }
  }
  ((int (*)())FUN_0018b1bc)(param_1,param_2,iVar7,iVar4,iVar9);
  return;
}

/* FUN_0018bc94 @ 0x18bc94 (1332 bytes) */
int FUN_0018bc94(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int *param_3;
  int *param_4;
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  int local_68 [10];
  
  if (param_2 < 3) {
    iVar7 = param_2 * 4 + param_1;
    if (*(int *)(iVar7 + 0x30) == 0) {
      iVar7 = ((int (*)())FUN_0018bc94)(param_1,param_2 + 1,param_3,param_4);
      if (iVar7 != 0) goto LAB_0018c1b0;
    }
    else {
      piVar11 = param_3 + 3;
      piVar8 = param_4 + 3;
      piVar6 = param_4;
      piVar9 = param_3;
      do {
        piVar14 = (int *)*piVar9;
        if ((((piVar14 == (int *)0x0) || (piVar14 == *(int **)(iVar7 + 0x18))) ||
            ((((*(int **)(iVar7 + 0x18) != (int *)0x0 &&
               ((piVar14[0x20] != 0 && (iVar3 = FUN_00126760(piVar14[0x26]), iVar3 != 0)))) &&
              ((piVar14[5] & 2U) == 0)) &&
             ((((((iVar3 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar3 == 0 &&
                  (piVar14 = *(int **)(iVar7 + 0x18), piVar14[0x20] != 0)) &&
                 (iVar3 = FUN_00126760(piVar14[0x26]), iVar3 != 0)) &&
                (((piVar14[5] & 2U) == 0 &&
                 (iVar3 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar3 == 0)))) &&
               ((*(uint *)(*piVar9 + 0x14) & 0x40) != 0)) &&
              (((*(uint *)(*(int *)(iVar7 + 0x18) + 0x14) & 0x40) != 0 &&
               (*(int *)(*piVar9 + 0x94) == *(int *)(*(int *)(iVar7 + 0x18) + 0x94))))))))) &&
           (((piVar14 = (int *)*piVar11, piVar14 == (int *)0x0 ||
             (piVar14 == *(int **)(iVar7 + 0x24))) ||
            (((((*(int **)(iVar7 + 0x24) != (int *)0x0 && (piVar14[0x20] != 0)) &&
               (iVar3 = FUN_00126760(piVar14[0x26]), iVar3 != 0)) &&
              ((((piVar14[5] & 2U) == 0 &&
                (iVar3 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar3 == 0)) &&
               (piVar14 = *(int **)(iVar7 + 0x24), piVar14[0x20] != 0)))) &&
             (((iVar3 = FUN_00126760(piVar14[0x26]), iVar3 != 0 && ((piVar14[5] & 2U) == 0)) &&
              ((iVar3 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar3 == 0 &&
               ((((*(uint *)(*piVar11 + 0x14) & 0x40) != 0 &&
                 ((*(uint *)(*(int *)(iVar7 + 0x24) + 0x14) & 0x40) != 0)) &&
                (*(int *)(*piVar11 + 0x94) == *(int *)(*(int *)(iVar7 + 0x24) + 0x94))))))))))))) {
          *piVar9 = *(int *)(iVar7 + 0x18);
          *piVar11 = *(int *)(iVar7 + 0x24);
          *piVar6 = *piVar6 + 1;
          *piVar8 = *piVar8 + 1;
          iVar3 = ((int (*)())FUN_0018bc94)(param_1,param_2 + 1,param_3,param_4);
          if (iVar3 != 0) goto LAB_0018c1b0;
          *piVar6 = *piVar6 + -1;
          iVar3 = *piVar8 + -1;
          *piVar8 = iVar3;
          if (*piVar6 == 0) {
            *piVar9 = 0;
            iVar3 = *piVar8;
          }
          if (iVar3 == 0) {
            *piVar11 = 0;
          }
        }
        piVar9 = piVar9 + 1;
        piVar11 = piVar11 + 1;
        piVar8 = piVar8 + 1;
        piVar6 = piVar6 + 1;
      } while (param_3 + 3 != piVar9);
    }
LAB_0018bf4c:
    uVar4 = 0;
  }
  else {
    piVar8 = param_4 + 3;
    piVar14 = local_68;
    piVar6 = piVar8;
    piVar9 = param_4;
    piVar11 = piVar14;
    do {
      iVar7 = *piVar9;
      piVar9 = piVar9 + 1;
      *piVar11 = iVar7;
      iVar7 = *piVar6;
      piVar6 = piVar6 + 1;
      piVar11[3] = iVar7;
      piVar11 = piVar11 + 1;
    } while (piVar11 != local_68 + 3);
    iVar7 = 0;
    iVar3 = param_1 + 0x10;
    do {
      piVar13 = (int *)(iVar3 + 8);
      iVar10 = 0;
      piVar6 = param_4;
      piVar9 = param_3;
      do {
        if ((*(int *)(param_1 + 0x30) == 0) && (*piVar13 != 0)) {
          iVar12 = 0;
          piVar2 = piVar9;
          do {
            if (((int *)*piVar2 != (int *)0x0) &&
               ((piVar15 = (int *)*piVar13, (int *)*piVar2 == piVar15 ||
                ((((piVar15 != (int *)0x0 && (piVar15[0x20] != 0)) &&
                  (iVar5 = FUN_00126760(piVar15[0x26]), iVar5 != 0)) &&
                 ((((((piVar15[5] & 2U) == 0 &&
                     (iVar5 = (**(code **)(*piVar15 + 0x50))(piVar15), iVar5 == 0)) &&
                    ((piVar15 = (int *)*piVar2, piVar15[0x20] != 0 &&
                     ((iVar5 = FUN_00126760(piVar15[0x26]), iVar5 != 0 && ((piVar15[5] & 2U) == 0)))
                     ))) && (iVar5 = (**(code **)(*piVar15 + 0x50))(piVar15), iVar5 == 0)) &&
                  ((((*(uint *)(*piVar13 + 0x14) & 0x40) != 0 &&
                    ((*(uint *)(*piVar2 + 0x14) & 0x40) != 0)) &&
                   (*(int *)(*piVar13 + 0x94) == *(int *)(*piVar2 + 0x94))))))))))) {
              piVar6[iVar12] = piVar6[iVar12] + 1;
              goto LAB_0018c0d4;
            }
            bVar1 = iVar12 != 2;
            piVar2 = piVar2 + 1;
            iVar12 = iVar12 + 1;
          } while (bVar1);
          iVar12 = 0;
          piVar2 = piVar9;
          while (*piVar2 != 0) {
            bVar1 = iVar12 == 2;
            piVar2 = piVar2 + 1;
            iVar12 = iVar12 + 1;
            if (bVar1) {
              piVar6 = param_3 + 3;
              do {
                iVar3 = *piVar14;
                *param_4 = iVar3;
                iVar7 = piVar14[3];
                *piVar8 = iVar7;
                if (iVar3 == 0) {
                  *param_3 = 0;
                }
                if (iVar7 == 0) {
                  *piVar6 = 0;
                }
                piVar14 = piVar14 + 1;
                param_4 = param_4 + 1;
                piVar8 = piVar8 + 1;
                piVar6 = piVar6 + 1;
                param_3 = param_3 + 1;
              } while (piVar11 != piVar14);
              goto LAB_0018bf4c;
            }
          }
          piVar9[iVar12] = *piVar13;
          piVar6[iVar12] = piVar6[iVar12] + 1;
        }
LAB_0018c0d4:
        bVar1 = iVar10 != 0xc;
        piVar13 = piVar13 + 3;
        piVar6 = piVar6 + 3;
        piVar9 = piVar9 + 3;
        iVar10 = iVar10 + 0xc;
      } while (bVar1);
      bVar1 = iVar7 != 2;
      iVar3 = iVar3 + 4;
      param_1 = param_1 + 4;
      iVar7 = iVar7 + 1;
    } while (bVar1);
LAB_0018c1b0:
    uVar4 = 1;
  }
  return uVar4;
}

/* FUN_0018c1c8 @ 0x18c1c8 (1440 bytes) */
int FUN_0018c1c8(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int local_58 [3];
  int local_4c [9];
  
  piVar5 = param_2 + 3;
  piVar4 = local_58;
  piVar1 = piVar5;
  piVar3 = param_2;
  do {
    *piVar4 = 0;
    piVar4[3] = 0;
    piVar4 = piVar4 + 1;
    *piVar3 = 0;
    *piVar1 = 0;
    piVar3 = piVar3 + 1;
    piVar1 = piVar1 + 1;
  } while (piVar4 != local_4c);
  if (*param_1 != 0) {
    *param_2 = *param_1;
    local_58[0] = local_58[0] + 1;
  }
  if (param_1[1] != 0) {
    *piVar5 = param_1[1];
    local_4c[0] = local_4c[0] + 1;
  }
  piVar1 = param_1;
  piVar3 = param_1;
  do {
    piVar4 = param_1;
    piVar6 = param_1;
    if ((param_1[2] == 0) || (param_1[3] == 0)) {
LAB_0018c498:
      do {
        if ((param_1[4] == 0) || (param_1[5] == 0)) {
LAB_0018c6a0:
          iVar2 = ((int (*)())FUN_0018bc94)(param_1,0,param_2,local_58);
          if (iVar2 != 0) {
            return 1;
          }
          local_4c[0] = local_4c[0] + -1;
          if (local_4c[0] == 0) {
            *piVar5 = 0;
          }
          local_4c[1] = local_4c[1] + -1;
          if (local_4c[1] == 0) {
            param_2[4] = 0;
          }
        }
        else {
          piVar7 = (int *)*piVar5;
          if ((((piVar7 == (int *)0x0) || (piVar7 == (int *)piVar6[5])) ||
              ((((((int *)piVar6[5] != (int *)0x0 && (piVar7[0x20] != 0)) &&
                 (iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0)) &&
                (((piVar7[5] & 2U) == 0 &&
                 (iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0)))) &&
               ((piVar7 = (int *)piVar6[5], piVar7[0x20] != 0 &&
                (((iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0 && ((piVar7[5] & 2U) == 0)) &&
                 ((iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0 &&
                  ((((*(uint *)(*piVar5 + 0x14) & 0x40) != 0 &&
                    ((*(uint *)(piVar6[5] + 0x14) & 0x40) != 0)) &&
                   (*(int *)(*piVar5 + 0x94) == *(int *)(piVar6[5] + 0x94))))))))))))) &&
             (((piVar7 = (int *)param_2[4], piVar7 == (int *)0x0 || (piVar7 == (int *)piVar4[4])) ||
              (((int *)piVar4[4] != (int *)0x0 &&
               ((((piVar7[0x20] != 0 && (iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0)) &&
                 (((piVar7[5] & 2U) == 0 &&
                  (((iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0 &&
                    (piVar7 = (int *)piVar4[4], piVar7[0x20] != 0)) &&
                   (iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0)))))) &&
                ((((piVar7[5] & 2U) == 0 &&
                  (iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0)) &&
                 (((*(uint *)(param_2[4] + 0x14) & 0x40) != 0 &&
                  (((*(uint *)(piVar4[4] + 0x14) & 0x40) != 0 &&
                   (*(int *)(param_2[4] + 0x94) == *(int *)(piVar4[4] + 0x94))))))))))))))) {
            *piVar5 = piVar6[5];
            local_4c[1] = local_4c[1] + 1;
            local_4c[0] = local_4c[0] + 1;
            param_2[4] = piVar4[4];
            goto LAB_0018c6a0;
          }
        }
        piVar6 = piVar6 + -1;
        piVar4 = piVar4 + 1;
      } while (param_1 + -2 != piVar6);
      local_58[0] = local_58[0] + -1;
      if (local_58[0] == 0) {
        *param_2 = 0;
      }
      local_58[1] = local_58[1] + -1;
      if (local_58[1] == 0) {
        param_2[1] = 0;
      }
    }
    else {
      piVar7 = (int *)*param_2;
      if ((((piVar7 == (int *)0x0) || (piVar7 == (int *)piVar3[3])) ||
          (((((((int *)piVar3[3] != (int *)0x0 && (piVar7[0x20] != 0)) &&
              (iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0)) &&
             (((piVar7[5] & 2U) == 0 && (iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0))
             )) && (piVar7 = (int *)piVar3[3], piVar7[0x20] != 0)) &&
           ((((iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0 && ((piVar7[5] & 2U) == 0)) &&
             (iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0)) &&
            ((((*(uint *)(*param_2 + 0x14) & 0x40) != 0 &&
              ((*(uint *)(piVar3[3] + 0x14) & 0x40) != 0)) &&
             (*(int *)(*param_2 + 0x94) == *(int *)(piVar3[3] + 0x94))))))))) &&
         (((piVar7 = (int *)param_2[1], piVar7 == (int *)0x0 || (piVar7 == (int *)piVar1[2])) ||
          (((((int *)piVar1[2] != (int *)0x0 &&
             ((piVar7[0x20] != 0 && (iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0)))) &&
            ((piVar7[5] & 2U) == 0)) &&
           (((((iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0 &&
               (piVar7 = (int *)piVar1[2], piVar7[0x20] != 0)) &&
              (iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0)) &&
             (((piVar7[5] & 2U) == 0 && (iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0))
             )) && (((*(uint *)(param_2[1] + 0x14) & 0x40) != 0 &&
                    (((*(uint *)(piVar1[2] + 0x14) & 0x40) != 0 &&
                     (*(int *)(param_2[1] + 0x94) == *(int *)(piVar1[2] + 0x94))))))))))))) {
        *param_2 = piVar3[3];
        local_58[0] = local_58[0] + 1;
        local_58[1] = local_58[1] + 1;
        param_2[1] = piVar1[2];
        goto LAB_0018c498;
      }
    }
    piVar3 = piVar3 + -1;
    piVar1 = piVar1 + 1;
    if (param_1 + -2 == piVar3) {
      return 0;
    }
  } while( true );
}

/* FUN_0018c768 @ 0x18c768 (140 bytes) */
int FUN_0018c768(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int *piVar2;
  int local_38 [3];
  int local_2c [9];
  
  iVar1 = ((int (*)())FUN_0018c1c8)(param_1,local_38);
  param_2[1] = 0;
  *param_2 = 0;
  if (iVar1 != 0) {
    piVar2 = local_38;
    do {
      if (*piVar2 == 0) {
        *param_2 = *param_2 + 1;
      }
      if (piVar2[3] == 0) {
        param_2[1] = param_2[1] + 1;
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 != local_2c);
  }
  return iVar1;
}

/* FUN_0018c7f4 @ 0x18c7f4 (396 bytes) */
int FUN_0018c7f4(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = (int *)(param_3 * 0xc + param_1 + 0x18);
  iVar4 = 0;
  while (((int *)*piVar5 == (int *)0x0 ||
         ((param_2 != (int *)*piVar5 &&
          (((((param_2 == (int *)0x0 || (param_2[0x20] == 0)) ||
             (iVar2 = FUN_00126760(param_2[0x26]), iVar2 == 0)) ||
            (((((param_2[5] & 2U) != 0 ||
               (iVar2 = (**(code **)(*param_2 + 0x50))(param_2), iVar2 != 0)) ||
              ((piVar3 = (int *)*piVar5, piVar3[0x20] == 0 ||
               ((iVar2 = FUN_00126760(piVar3[0x26]), iVar2 == 0 || ((piVar3[5] & 2U) != 0)))))) ||
             (iVar2 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar2 != 0)))) ||
           ((((param_2[5] & 0x40U) == 0 || ((*(uint *)(*piVar5 + 0x14) & 0x40) == 0)) ||
            (param_2[0x25] != *(int *)(*piVar5 + 0x94)))))))))) {
    bVar1 = iVar4 == 2;
    piVar5 = piVar5 + 1;
    iVar4 = iVar4 + 1;
    if (bVar1) {
      iVar4 = 0;
      piVar5 = (int *)(param_3 * 0xc + param_1 + 0x18);
      do {
        if (*piVar5 == 0) {
          *(int **)((param_3 * 3 + iVar4) * 4 + param_1 + 0x18) = param_2;
          return 1;
        }
        bVar1 = iVar4 != 2;
        piVar5 = piVar5 + 1;
        iVar4 = iVar4 + 1;
      } while (bVar1);
      return 0;
    }
  }
  return 1;
}

/* FUN_0018c980 @ 0x18c980 (1112 bytes) */
int FUN_0018c980(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  
  iVar4 = 0;
  iVar6 = param_1;
  while (*(int *)(iVar6 + 0x30) != 0) {
    piVar7 = *(int **)(iVar6 + 0x18);
    if (((param_2 == piVar7) ||
        ((((((piVar7 != (int *)0x0 && (param_2 != (int *)0x0)) && (piVar7[0x20] != 0)) &&
           ((iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0 && ((piVar7[5] & 2U) == 0)))) &&
          ((((iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0 &&
             ((param_2[0x20] != 0 && (iVar2 = FUN_00126760(param_2[0x26]), iVar2 != 0)))) &&
            ((param_2[5] & 2U) == 0)) &&
           (((iVar2 = (**(code **)(*param_2 + 0x50))(param_2), iVar2 == 0 &&
             ((*(uint *)(*(int *)(iVar6 + 0x18) + 0x14) & 0x40) != 0)) &&
            ((param_2[5] & 0x40U) != 0)))))) &&
         (*(int *)(*(int *)(iVar6 + 0x18) + 0x94) == param_2[0x25])))) &&
       ((piVar7 = *(int **)(iVar6 + 0x24), param_3 == piVar7 ||
        (((((piVar7 != (int *)0x0 && (param_3 != (int *)0x0)) &&
           ((piVar7[0x20] != 0 &&
            ((iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0 && ((piVar7[5] & 2U) == 0)))))) &&
          (iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0)) &&
         (((((param_3[0x20] != 0 && (iVar2 = FUN_00126760(param_3[0x26]), iVar2 != 0)) &&
            ((param_3[5] & 2U) == 0)) &&
           ((iVar2 = (**(code **)(*param_3 + 0x50))(param_3), iVar2 == 0 &&
            ((*(uint *)(*(int *)(iVar6 + 0x24) + 0x14) & 0x40) != 0)))) &&
          (((param_3[5] & 0x40U) != 0 && (*(int *)(*(int *)(iVar6 + 0x24) + 0x94) == param_3[0x25]))
          )))))))) goto LAB_0018cdb8;
    bVar1 = iVar4 == 2;
    iVar6 = iVar6 + 4;
    iVar4 = iVar4 + 1;
    if (bVar1) goto LAB_0018cdb8;
  }
  iVar2 = iVar4 + 1;
  iVar6 = iVar4 * 4 + param_1;
  iVar5 = *(int *)(iVar6 + 0x18);
  iVar4 = *(int *)(iVar6 + 0x24);
  *(undefined4 *)(iVar6 + 0x30) = 1;
  *(int **)(iVar6 + 0x18) = param_2;
  *(int **)(iVar6 + 0x24) = param_3;
  if (iVar2 < 3) {
    piVar7 = (int *)(iVar2 * 4 + param_1 + 0x18);
    do {
      piVar8 = (int *)*piVar7;
      if ((piVar8 != (int *)0x0) &&
         ((param_2 == piVar8 ||
          ((((param_2 != (int *)0x0 && (piVar8[0x20] != 0)) &&
            (iVar6 = FUN_00126760(piVar8[0x26]), iVar6 != 0)) &&
           (((((piVar8[5] & 2U) == 0 && (iVar6 = (**(code **)(*piVar8 + 0x50))(piVar8), iVar6 == 0))
             && ((param_2[0x20] != 0 &&
                 ((iVar6 = FUN_00126760(param_2[0x26]), iVar6 != 0 && ((param_2[5] & 2U) == 0))))))
            && ((iVar6 = (**(code **)(*param_2 + 0x50))(param_2), iVar6 == 0 &&
                ((((*(uint *)(*piVar7 + 0x14) & 0x40) != 0 && ((param_2[5] & 0x40U) != 0)) &&
                 (*(int *)(*piVar7 + 0x94) == param_2[0x25])))))))))))) {
        *piVar7 = 0;
      }
      piVar8 = (int *)piVar7[3];
      if ((piVar8 != (int *)0x0) &&
         ((param_3 == piVar8 ||
          ((((param_3 != (int *)0x0 && (piVar8[0x20] != 0)) &&
            ((iVar6 = FUN_00126760(piVar8[0x26]), iVar6 != 0 &&
             (((piVar8[5] & 2U) == 0 && (iVar6 = (**(code **)(*piVar8 + 0x50))(piVar8), iVar6 == 0))
             )))) && (((param_3[0x20] != 0 &&
                       ((((iVar6 = FUN_00126760(param_3[0x26]), iVar6 != 0 &&
                          ((param_3[5] & 2U) == 0)) &&
                         (iVar6 = (**(code **)(*param_3 + 0x50))(param_3), iVar6 == 0)) &&
                        (((*(uint *)(piVar7[3] + 0x14) & 0x40) != 0 && ((param_3[5] & 0x40U) != 0)))
                        ))) && (*(int *)(piVar7[3] + 0x94) == param_3[0x25])))))))) {
        piVar7[3] = 0;
      }
      bVar1 = iVar2 != 2;
      piVar7 = piVar7 + 1;
      iVar2 = iVar2 + 1;
    } while (bVar1);
  }
  if (((iVar5 == 0) || (iVar6 = ((int (*)())FUN_0018c7f4)(param_1,iVar5,0), iVar6 != 0)) &&
     ((iVar4 == 0 || (iVar6 = ((int (*)())FUN_0018c7f4)(param_1,iVar4,1), iVar6 != 0)))) {
LAB_0018cdb8:
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

/* FUN_0018cdd8 @ 0x18cdd8 (1456 bytes) */
int FUN_0018cdd8(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  int *param_3;
  int param_4;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  iVar5 = param_4 * 8;
  iVar3 = iVar5 + param_1;
  piVar6 = *(int **)(iVar3 + 8);
  if ((piVar6 == (int *)0x0) || (piVar4 = *(int **)(iVar3 + 0xc), piVar4 == (int *)0x0)) {
    iVar3 = param_4 * 4;
    piVar6 = *(int **)(iVar3 + param_1);
    if ((((piVar6 == (int *)0x0) || (piVar6 == param_2)) ||
        (((((((param_2 != (int *)0x0 && (piVar6[0x20] != 0)) &&
             (iVar1 = FUN_00126760(piVar6[0x26]), iVar1 != 0)) &&
            ((((piVar6[5] & 2U) == 0 && (iVar1 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar1 == 0))
             && (param_2[0x20] != 0)))) &&
           ((iVar1 = FUN_00126760(param_2[0x26]), iVar1 != 0 && ((param_2[5] & 2U) == 0)))) &&
          ((iVar1 = (**(code **)(*param_2 + 0x50))(param_2), iVar1 == 0 &&
           ((((*(uint *)(*(int *)(iVar3 + param_1) + 0x14) & 0x40) != 0 &&
             ((param_2[5] & 0x40U) != 0)) &&
            (*(int *)(*(int *)(iVar3 + param_1) + 0x94) == param_2[0x25])))))) ||
         ((piVar6 = *(int **)(iVar3 + param_1), param_3 == piVar6 ||
          ((((piVar6 != (int *)0x0 && (param_3 != (int *)0x0)) &&
            (((piVar6[0x20] != 0 &&
              ((iVar1 = FUN_00126760(piVar6[0x26]), iVar1 != 0 && ((piVar6[5] & 2U) == 0)))) &&
             (iVar1 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar1 == 0)))) &&
           (((((param_3[0x20] != 0 && (iVar1 = FUN_00126760(param_3[0x26]), iVar1 != 0)) &&
              ((param_3[5] & 2U) == 0)) &&
             ((iVar1 = (**(code **)(*param_3 + 0x50))(param_3), iVar1 == 0 &&
              ((*(uint *)(*(int *)(iVar3 + param_1) + 0x14) & 0x40) != 0)))) &&
            (((param_3[5] & 0x40U) != 0 &&
             (*(int *)(*(int *)(iVar3 + param_1) + 0x94) == param_3[0x25])))))))))))) &&
       ((iVar3 = ((int (*)())FUN_0018c7f4)(param_1,param_2,param_4), iVar3 != 0 &&
        (iVar3 = ((int (*)())FUN_0018c7f4)(param_1,param_3,param_4), iVar3 != 0)))) {
      *(int **)(iVar5 + param_1 + 0xc) = param_3;
      *(int **)(iVar5 + param_1 + 8) = param_2;
      return 1;
    }
LAB_0018d170:
    uVar2 = 0;
  }
  else {
    if (piVar6 == param_2) {
LAB_0018cee8:
      if ((param_3 != piVar4) &&
         ((((piVar4 == (int *)0x0 || (param_3 == (int *)0x0)) ||
           ((piVar4[0x20] == 0 ||
            ((iVar1 = FUN_00126760(piVar4[0x26]), iVar1 == 0 || ((piVar4[5] & 2U) != 0)))))) ||
          (((iVar1 = (**(code **)(*piVar4 + 0x50))(piVar4), iVar1 != 0 ||
            ((((param_3[0x20] == 0 || (iVar1 = FUN_00126760(param_3[0x26]), iVar1 == 0)) ||
              ((param_3[5] & 2U) != 0)) ||
             ((iVar1 = (**(code **)(*param_3 + 0x50))(param_3), iVar1 != 0 ||
              ((*(uint *)(*(int *)(iVar3 + 0xc) + 0x14) & 0x40) == 0)))))) ||
           (((param_3[5] & 0x40U) == 0 || (*(int *)(*(int *)(iVar3 + 0xc) + 0x94) != param_3[0x25]))
           )))))) goto LAB_0018cfbc;
    }
    else {
      if (((((param_2 != (int *)0x0) && (piVar6[0x20] != 0)) &&
           (iVar1 = FUN_00126760(piVar6[0x26]), iVar1 != 0)) &&
          ((((piVar6[5] & 2U) == 0 && (iVar1 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar1 == 0))
           && ((param_2[0x20] != 0 &&
               ((iVar1 = FUN_00126760(param_2[0x26]), iVar1 != 0 && ((param_2[5] & 2U) == 0))))))))
         && ((iVar1 = (**(code **)(*param_2 + 0x50))(param_2), iVar1 == 0 &&
             ((((*(uint *)(*(int *)(iVar3 + 8) + 0x14) & 0x40) != 0 && ((param_2[5] & 0x40U) != 0))
              && (*(int *)(*(int *)(iVar3 + 8) + 0x94) == param_2[0x25])))))) {
        piVar4 = *(int **)(iVar3 + 0xc);
        goto LAB_0018cee8;
      }
LAB_0018cfbc:
      iVar5 = iVar5 + param_1;
      piVar6 = *(int **)(iVar5 + 8);
      if (((param_3 != piVar6) &&
          (((((piVar6 == (int *)0x0 || (param_3 == (int *)0x0)) ||
             ((piVar6[0x20] == 0 ||
              (((iVar3 = FUN_00126760(piVar6[0x26]), iVar3 == 0 || ((piVar6[5] & 2U) != 0)) ||
               (iVar3 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar3 != 0)))))) ||
            ((param_3[0x20] == 0 || (iVar3 = FUN_00126760(param_3[0x26]), iVar3 == 0)))) ||
           (((param_3[5] & 2U) != 0 ||
            (((iVar3 = (**(code **)(*param_3 + 0x50))(param_3), iVar3 != 0 ||
              ((*(uint *)(*(int *)(iVar5 + 8) + 0x14) & 0x40) == 0)) ||
             (((param_3[5] & 0x40U) == 0 || (*(int *)(*(int *)(iVar5 + 8) + 0x94) != param_3[0x25]))
             )))))))) ||
         ((piVar6 = *(int **)(iVar5 + 0xc), param_2 != piVar6 &&
          (((((piVar6 == (int *)0x0 || (param_2 == (int *)0x0)) || (piVar6[0x20] == 0)) ||
            ((iVar3 = FUN_00126760(piVar6[0x26]), iVar3 == 0 || ((piVar6[5] & 2U) != 0)))) ||
           ((((iVar3 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar3 != 0 ||
              ((param_2[0x20] == 0 || (iVar3 = FUN_00126760(param_2[0x26]), iVar3 == 0)))) ||
             ((param_2[5] & 2U) != 0)) ||
            ((((iVar3 = (**(code **)(*param_2 + 0x50))(param_2), iVar3 != 0 ||
               ((*(uint *)(*(int *)(iVar5 + 0xc) + 0x14) & 0x40) == 0)) ||
              ((param_2[5] & 0x40U) == 0)) ||
             (*(int *)(*(int *)(iVar5 + 0xc) + 0x94) != param_2[0x25])))))))))) goto LAB_0018d170;
    }
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_0018d388 @ 0x18d388 (300 bytes) */
int FUN_0018d388(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = param_3 * 4;
  piVar3 = *(int **)(iVar1 + param_1);
  if (piVar3 == (int *)0x0) {
    iVar2 = ((int (*)())FUN_0018c7f4)(param_1,param_2,param_3);
    if (iVar2 != 0) {
      *(int **)(iVar1 + param_1) = param_2;
      return 1;
    }
  }
  else if ((piVar3 == param_2) ||
          (((((param_2 != (int *)0x0 && (piVar3[0x20] != 0)) &&
             (iVar2 = FUN_00126760(piVar3[0x26]), iVar2 != 0)) &&
            (((((piVar3[5] & 2U) == 0 && (iVar2 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar2 == 0)
               ) && ((param_2[0x20] != 0 &&
                     ((iVar2 = FUN_00126760(param_2[0x26]), iVar2 != 0 && ((param_2[5] & 2U) == 0)))
                     ))) && (iVar2 = (**(code **)(*param_2 + 0x50))(param_2), iVar2 == 0)))) &&
           ((((*(uint *)(*(int *)(iVar1 + param_1) + 0x14) & 0x40) != 0 &&
             ((param_2[5] & 0x40U) != 0)) &&
            (*(int *)(*(int *)(iVar1 + param_1) + 0x94) == param_2[0x25])))))) {
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
          FUN_0019401c(piVar3);
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
            iVar2 = ((int (*)())FUN_0018cdd8)(param_4,uVar4,uVar5,0);
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
            iVar2 = ((int (*)())FUN_0018cdd8)(param_4,uVar4,uVar5,1);
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
            iVar8 = ((int (*)())FUN_0018c7f4)(param_4,piVar6,1);
          }
          else if ((local_40[0] & 0xff) == 0) {
            iVar8 = ((int (*)())FUN_0018c7f4)(param_4,piVar6,0);
          }
          else {
            iVar8 = ((int (*)())FUN_0018c980)(param_4,piVar6,piVar6);
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
  ((int (*)())FUN_00189560)(auStack_58);
  iVar1 = ((int (*)())FUN_0018d4b4)(param_1,&local_68,&local_64,auStack_58,param_2);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = ((int (*)())FUN_0018c768)(auStack_58,auStack_60);
  }
  return uVar2;
}

/* FUN_0018dabc @ 0x18dabc (1680 bytes) */
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
    local_70 = FUN_00193e18(local_6c,8);
    local_5c = *(undefined4 *)(param_1[2] + 0x378);
    local_64 = 0;
    local_68 = 2;
    local_60 = FUN_00193e18(local_5c,8);
    local_4c = *(undefined4 *)(param_1[2] + 0x378);
    local_54 = 0;
    local_58 = 2;
    local_50 = FUN_00193e18(local_4c,8);
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
            _memset(uVar6 * 4 + puVar20[2],0,(uVar16 - uVar6) * 4 + 4);
            puVar20[1] = uVar13;
          }
          piVar7 = (int *)(iVar14 + puVar20[2]);
        }
        else {
          piVar7 = (int *)FUN_0019423c(puVar20,uVar16);
        }
        iVar17 = *piVar7;
        if (*(int *)(iVar17 + 8) == 0) {
          puVar20 = *(uint **)(param_2 + 0x40);
          if (uVar16 < *puVar20) {
            uVar6 = puVar20[1];
            if (uVar6 <= uVar16) {
              _memset(uVar6 * 4 + puVar20[2],0,(uVar16 - uVar6) * 4 + 4);
              puVar20[1] = uVar13;
            }
            piVar7 = (int *)(iVar14 + puVar20[2]);
          }
          else {
            piVar7 = (int *)FUN_0019423c(puVar20,uVar16);
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
              piVar9 = (int *)FUN_00105594(piVar7,iVar8);
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
                  _memset(iVar8 + local_70,0,4);
                  local_74 = uVar6 + 1;
                  puVar11 = (undefined4 *)(iVar8 + local_70);
                }
                else {
                  puVar11 = (undefined4 *)FUN_0019423c(&local_78,local_74);
                }
                uVar6 = local_64;
                *puVar11 = piVar7;
                uVar18 = *(undefined4 *)(iVar17 + 0x10);
                if (local_64 < local_68) {
                  iVar17 = local_64 * 4;
                  _memset(iVar17 + local_60,0,4);
                  local_64 = uVar6 + 1;
                  puVar11 = (undefined4 *)(iVar17 + local_60);
                }
                else {
                  puVar11 = (undefined4 *)FUN_0019423c(&local_68,local_64);
                }
                uVar6 = local_54;
                *puVar11 = uVar18;
                if (local_54 < local_58) {
                  iVar17 = local_54 * 4;
                  _memset(iVar17 + local_50,0,4);
                  local_54 = uVar6 + 1;
                  puVar11 = (undefined4 *)(iVar17 + local_50);
                }
                else {
                  puVar11 = (undefined4 *)FUN_0019423c(&local_58,local_54);
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
      uVar12 = local_74 - 1;
      piVar7 = (int *)0x0;
      if (uVar12 < local_74) {
        piVar7 = (int *)(uVar12 * 4 + local_70);
      }
      iVar3 = *piVar7;
      FUN_00194208(&local_78,uVar12);
      piVar7 = (int *)0x0;
      uVar12 = local_64 - 1;
      if (uVar12 < local_64) {
        piVar7 = (int *)(uVar12 * 4 + local_60);
      }
      iVar15 = *piVar7;
      FUN_00194208(&local_68,uVar12);
      puVar11 = (undefined4 *)0x0;
      uVar12 = local_54 - 1;
      if (uVar12 < local_54) {
        puVar11 = (undefined4 *)(uVar12 * 4 + local_50);
      }
      uVar19 = *puVar11;
      FUN_00194208(&local_58,uVar12);
      if (iVar15 == 0) {
        *(undefined4 *)(iVar3 + 0x9c) = uVar19;
      }
      else {
        iVar3 = FUN_001054ec(iVar3,iVar15);
        *(undefined4 *)(iVar3 + 0x10) = uVar19;
      }
    }
    FUN_00193cc0(local_4c,local_50);
    FUN_00193cc0(local_5c,local_60);
    FUN_00193cc0(local_6c,local_70);
  }
  return uVar5;
}

/* FUN_0018e1a8 @ 0x18e1a8 (1724 bytes) */
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
    local_8c = FUN_00193e18(local_88,8);
    local_84[3] = *(undefined4 *)(param_1[2] + 0x378);
    local_84[1] = 0;
    local_84[0] = 2;
    local_84[2] = FUN_00193e18(local_84[3],8);
    iVar14 = *(int *)(iVar17 + 0x474) + 1;
    *(int *)(iVar17 + 0x474) = iVar14;
    iVar5 = FUN_00105594(param_2,1);
    *(int *)(iVar5 + 0x150) = iVar14;
    if (local_90 < local_94) {
      iVar7 = local_90 * 4;
      uVar21 = local_90 + 1;
      _memset(iVar7 + local_8c,0,4);
      piVar6 = (int *)(iVar7 + local_8c);
      local_90 = uVar21;
    }
    else {
      piVar6 = (int *)FUN_0019423c(&local_94,local_90);
    }
    *piVar6 = iVar5;
    bVar2 = false;
    bVar3 = false;
    do {
      uVar21 = local_90 - 1;
      piVar6 = (int *)0x0;
      if (uVar21 < local_90) {
        piVar6 = (int *)(uVar21 * 4 + local_8c);
      }
      iVar20 = *piVar6;
      FUN_00194208(&local_94,uVar21);
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
                      iVar8 = ((undefined4 (*)())FUN_00139838)(piVar6,2,(double)FLOAT_001aa0d4);
                      if (iVar8 == 0) {
                        FUN_00103d50(piVar6 + 0x2f,1,piVar6[0x34] & 1U ^ 1);
                      }
                      iVar8 = ((undefined4 (*)())FUN_00139838)(piVar6,3,(double)FLOAT_001aa0d4);
                      if (iVar8 != 0) goto LAB_0018e5a0;
                    }
                    FUN_00103d50(piVar6 + 0x35,1,piVar6[0x3a] & 1U ^ 1);
                  }
LAB_0018e5a0:
                  uVar13 = 0;
                }
                else {
                  iVar8 = ((undefined4 (*)())FUN_00139838)(iVar20,iVar12,(double)FLOAT_001aa0d4);
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
                    _memset(iVar8 + local_84[2],0,4);
                    local_84[1] = uVar21 + 1;
                    puVar9 = (undefined4 *)(iVar8 + local_84[2]);
                  }
                  else {
                    puVar9 = (undefined4 *)FUN_0019423c(local_84,local_84[1]);
                  }
                  *puVar9 = piVar6;
                  bVar3 = true;
                }
              }
              else {
                if (local_90 < local_94) {
                  iVar8 = local_90 * 4;
                  uVar21 = local_90 + 1;
                  _memset(iVar8 + local_8c,0,4);
                  puVar9 = (undefined4 *)(iVar8 + local_8c);
                  local_90 = uVar21;
                }
                else {
                  puVar9 = (undefined4 *)FUN_0019423c(&local_94,local_90);
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
          uVar21 = local_84[1] - 1;
          piVar6 = (int *)0x0;
          if (uVar21 < local_84[1]) {
            piVar6 = (int *)(uVar21 * 4 + local_84[2]);
          }
          iVar5 = *piVar6;
          FUN_00194208(local_84,uVar21);
          *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x80000000;
        }
      }
      piVar6 = (int *)0x0;
    }
    FUN_00193cc0(local_84[3],local_84[2]);
    FUN_00193cc0(local_88,local_8c);
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
code_r0x0018e934:
        piVar11 = (int *)FUN_00105594(param_2,iVar5);
        iVar14 = (**(code **)(*piVar11 + 0x48))();
        if (iVar14 == 0) {
          piVar11 = (int *)FUN_00105594(param_2,iVar5);
          iVar14 = (**(code **)(*piVar11 + 0x60))();
          if ((iVar14 == 0) &&
             ((((param_2[iVar5 * 6 + 0x28] & 2U) == 0 && ((param_2[iVar5 * 6 + 0x28] & 1U) == 0)) ||
              (iVar14 = FUN_00148d8c(param_2,iVar17), iVar14 != 0)))) goto code_r0x0018eb5c;
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
        if (iVar14 == 0) goto code_r0x0018e934;
        uVar16 = FUN_00105594(param_2,iVar5);
        iVar14 = FUN_0010c47c(uVar16,param_1[2]);
        if (iVar14 == 0) goto code_r0x0018e934;
        uVar16 = FUN_00105594(param_2,iVar5);
        uVar16 = FUN_0010cb48(uVar16,param_1[2]);
        FUN_00106004(param_2,iVar5,uVar16,0,param_1[2]);
      }
code_r0x0018eb5c: ;
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
        FUN_0019401c(piVar11);
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
            ((void (*)())FUN_000f79c4)(piVar11,*(undefined4 *)(param_1[2] + 0x6c4),2,dVar22,dVar22,dVar22,dVar22);
            FUN_00103d50(piVar11 + 0x29,1,1);
          }
          else {
            FUN_00106004(piVar11,2,uVar16,0,param_1[2]);
            iVar14 = FUN_001054ec(piVar11,2);
            *(int *)(iVar14 + 0x10) = iVar15;
            FUN_00103d50(piVar11 + 0x2f,1,(uint)(iVar7 == 0x9a));
          }
        }
        else {
          FUN_00103d50(piVar11 + 0x29,1,1);
          dVar22 = (double)FLOAT_001aa0e8;
          ((void (*)())FUN_000f79c4)(piVar11,*(undefined4 *)(param_1[2] + 0x6c4),2,dVar22,dVar22,dVar22,dVar22);
          dVar22 = (double)FLOAT_001aa10c;
          ((void (*)())FUN_000f79c4)(piVar11,*(undefined4 *)(param_1[2] + 0x6c4),3,dVar22,dVar22,dVar22,dVar22);
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
      ((int (*)())FUN_00189df4)(param_2,param_1 + 0x18,param_1 + 0x20);
      ((int (*)())FUN_0018d4b4)(param_2,param_1 + 0x1c,param_1 + 0x24,param_1 + 0x28,*(undefined4 *)(param_1 + 8)
                  );
      ((int (*)())FUN_0018c768)(param_1 + 0x28,&local_38);
      uVar2 = 0;
      if (*(int *)(param_1 + 100) != 0) {
        ((int (*)())FUN_00189840)(param_1,*(int *)(param_1 + 100),param_2,local_38,local_34);
        uVar2 = *(undefined4 *)(param_1 + 100);
      }
      ((int (*)())FUN_001899ac)(param_1,uVar2,param_2,local_38,local_34);
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
    ((int (*)())FUN_001895a0)(auStack_60,param_1 + 0x28);
    iVar1 = ((int (*)())FUN_00189df4)(param_2,&local_78,&local_70);
    if ((((iVar1 == 0) ||
         (iVar1 = ((int (*)())FUN_0018d4b4)(param_2,&local_74,&local_6c,auStack_60,*(undefined4 *)(param_1 + 8)),
         iVar1 == 0)) || (iVar1 = ((int (*)())FUN_0018c768)(auStack_60,&local_68), iVar1 == 0)) ||
       ((*(int *)(param_1 + 100) != 0 &&
        (iVar1 = ((int (*)())FUN_00189840)(param_1,*(int *)(param_1 + 100),param_2,local_68,local_64), iVar1 == 0
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
int FUN_0018f984(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
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
                _memset(uVar8 * 4 + puVar16[2],0,(uVar14 - uVar8) * 4 + 4);
                puVar16[1] = uVar14 + 1;
              }
              piVar9 = (int *)(uVar14 * 4 + puVar16[2]);
            }
            else {
              piVar9 = (int *)FUN_0019423c(puVar16,uVar14);
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
          iVar1 = ((int (*)())FUN_0018f850)(param_1,&local_38,&local_2c,
                               (uint)(*(int *)(param_2[0x22] + 8) == 0x14));
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

/* FUN_00190990 @ 0x190990 (1256 bytes) */
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
    ((void (*)())FUN_000f79c4)(iVar1,iVar11,2,dVar15,dVar15,dVar15,dVar15);
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
    ((void (*)())FUN_000f79c4)(iVar2,iVar11,2,dVar15,dVar15,dVar15,dVar15);
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
    FUN_0019401c(param_2);
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
        if ((iVar2 < 0) || (iVar2 == local_a4)) goto code_r0x0019125c;
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
code_r0x0019125c:
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

