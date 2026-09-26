#include "decls.h"

/* FUN_0005bbc0 @ 0x5bbc0 (928 bytes) */
int FUN_0005bbc0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44;
  
  iVar5 = param_3 + 0x20;
  piVar6 = param_2 + 7;
  iVar4 = param_3 + 0x3c;
  iVar2 = FUN_00057af0(piVar6,iVar5,iVar4);
  if (iVar2 == 0) {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 1U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 1U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    FUN_00056f20(param_1,param_2,param_3 + 4,iVar2,3,0,0);
    FUN_00057340(param_2,piVar6,iVar5,iVar2 + 4,0);
    FUN_00057340(param_2,piVar6,iVar4,iVar2 + 8,0);
    uVar1 = *(uint *)(iVar2 + 8);
    uVar3 = 1;
    uVar1 = (uVar1 & 0xf1ffffff ^ 0x10000000) & 0x10000000 |
            (uVar1 & 0xf9ffffff ^ 0x8000000) & 0x8000000 |
            (uVar1 & 0xfdffffff ^ 0x4000000) & 0x4000000 |
            (uVar1 ^ 0x2000000) & 0x2000000 | uVar1 & 0xe1ffffff;
    *(uint *)(iVar2 + 0xc) = uVar1;
    *(uint *)(iVar2 + 8) = uVar1;
  }
  else {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    uVar3 = FUN_00057b80(param_1,param_2);
    local_78 = 3;
    local_60 = 0;
    local_64 = 1;
    local_70 = 1;
    local_6c = 1;
    local_68 = 1;
    local_74 = uVar3;
    FUN_00056f20(param_1,param_2,&local_78,iVar2,3,0,0);
    FUN_00057340(param_2,piVar6,iVar5,iVar2 + 4,0);
    uVar1 = *(uint *)(iVar2 + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(iVar2 + 0xc) = uVar1;
    *(uint *)(iVar2 + 8) = uVar1;
    FUN_00056f20(param_1,param_2,param_3 + 4,iVar2 + 0x10,3,0,0);
    local_5c = 3;
    local_44 = 0;
    local_54 = 0x87d5;
    local_50 = 0x87d6;
    local_4c = 0x87d7;
    local_48 = 0x87d8;
    local_58 = uVar3;
    FUN_00057340(param_2,piVar6,&local_5c,iVar2 + 0x14,0);
    FUN_00057340(param_2,piVar6,iVar4,iVar2 + 0x18,0);
    uVar1 = *(uint *)(iVar2 + 0x18);
    uVar3 = 2;
    uVar1 = (uVar1 & 0xf1ffffff ^ 0x10000000) & 0x10000000 |
            (uVar1 & 0xf9ffffff ^ 0x8000000) & 0x8000000 |
            (uVar1 & 0xfdffffff ^ 0x4000000) & 0x4000000 |
            (uVar1 ^ 0x2000000) & 0x2000000 | uVar1 & 0xe1ffffff;
    *(uint *)(iVar2 + 0x1c) = uVar1;
    *(uint *)(iVar2 + 0x18) = uVar1;
  }
  return uVar3;
}

/* FUN_0005bf60 @ 0x5bf60 (1672 bytes) */
int FUN_0005bf60(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iStack00000020;
  undefined4 local_98;
  int local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined1 local_80;
  undefined4 local_7c;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined1 local_64;
  undefined4 *local_58;
  
  iVar6 = param_3 + 0x20;
  piVar5 = param_2 + 7;
  iVar7 = param_3 + 0x3c;
  iStack00000020 = param_3;
  iVar3 = FUN_00057af0(piVar5,iVar6,iVar7);
  if (iVar3 == 0) {
    iVar3 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar10 = *(int *)(iVar3 + 0x18);
    if (0x100 < iVar10 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar10 = *(int *)(iVar3 + 0x18);
      if (*(uint *)(iVar3 + 0x20) < iVar10 + 2U) {
        uVar4 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar4,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
        *(undefined4 *)(iVar3 + 0x1c) = uVar4;
        iVar10 = *(int *)(iVar3 + 0x18);
        *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
      }
    }
    iVar3 = iVar10 * 0x10 + *(int *)(iVar3 + 0x1c);
    uVar4 = FUN_00057b80(param_1,param_2);
    local_98 = 3;
    local_80 = 0;
    local_84 = 1;
    local_90 = 1;
    local_8c = 1;
    local_88 = 1;
    local_94 = uVar4;
    FUN_00056f20(param_1,param_2,&local_98,iVar3,2,0,0);
    FUN_00057340(param_2,piVar5,iVar6,iVar3 + 4,0);
    uVar2 = *(uint *)(iVar3 + 4);
    *(uint *)(iVar3 + 4) =
         (uVar2 & 0x4000000) << 1 |
         (uVar2 & 0x2000000) << 1 |
         uVar2 >> 2 & 0x2000000 |
         (uVar2 & 0x70000) << 3 | (uVar2 & 0xe000) << 3 | uVar2 >> 6 & 0xe000 | uVar2 & 0xe0001fff |
         0x1000000;
    FUN_00057340(param_2,piVar5,iVar7,iVar3 + 8,0);
    uVar2 = *(uint *)(iVar3 + 8);
    uVar2 = (uVar2 & 0x2000000) << 2 |
            uVar2 >> 1 & 0x4000000 |
            uVar2 >> 1 & 0x2000000 |
            (uVar2 & 0xe000) << 6 | uVar2 >> 3 & 0x70000 | uVar2 >> 3 & 0xe000 | uVar2 & 0xe0001fff
            | 0x1000000;
    *(uint *)(iVar3 + 0xc) = uVar2;
    *(uint *)(iVar3 + 8) = uVar2;
    FUN_00056f20(param_1,param_2,iStack00000020 + 4,iVar3 + 0x10,4,0,0);
    FUN_00057340(param_2,piVar5,iVar6,iVar3 + 0x14,0);
    uVar2 = *(uint *)(iVar3 + 0x14);
    *(uint *)(iVar3 + 0x14) =
         (uVar2 & 0x2000000) << 2 |
         uVar2 >> 1 & 0x4000000 |
         uVar2 >> 1 & 0x2000000 |
         (uVar2 & 0xe000) << 6 | uVar2 >> 3 & 0x70000 | uVar2 >> 3 & 0xe000 | uVar2 & 0xe0001fff |
         0x1400000;
    FUN_00057340(param_2,piVar5,iVar7,iVar3 + 0x18,0);
    uVar2 = *(uint *)(iVar3 + 0x18);
    *(uint *)(iVar3 + 0x18) =
         (uVar2 & 0x4000000) << 1 |
         (uVar2 & 0x2000000) << 1 |
         uVar2 >> 2 & 0x2000000 |
         (uVar2 & 0x70000) << 3 | (uVar2 & 0xe000) << 3 | uVar2 >> 6 & 0xe000 | uVar2 & 0xe0001fff |
         0x1400000;
    local_7c = 3;
    local_74 = 0x87d9;
    local_70 = 0x87da;
    local_6c = 0x87db;
    local_68 = 0x87dc;
    local_64 = 0;
    local_78 = uVar4;
    FUN_00057340(param_2,piVar5,&local_7c,iVar3 + 0x1c,0);
    uVar4 = 2;
  }
  else {
    iVar10 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar3 = *(int *)(iVar10 + 0x18);
    if (0x100 < iVar3 + 3U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar3 = *(int *)(iVar10 + 0x18);
      if (*(uint *)(iVar10 + 0x20) < iVar3 + 3U) {
        uVar4 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar10 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar4,*(undefined4 *)(iVar10 + 0x1c),*(int *)(iVar10 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar10 + 0x1c));
        *(undefined4 *)(iVar10 + 0x1c) = uVar4;
        iVar3 = *(int *)(iVar10 + 0x18);
        *(int *)(iVar10 + 0x20) = *(int *)(iVar10 + 0x20) + 0x10;
      }
    }
    iVar9 = iVar3 * 0x10 + *(int *)(iVar10 + 0x1c);
    iVar10 = FUN_00057b80(param_1,param_2);
    local_58 = &local_7c;
    iVar8 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar3 = iVar10 * 0x28 + *(int *)(iVar8 + 0x4c);
    uVar1 = *(undefined1 *)(iVar3 + 0x10);
    *(undefined1 *)(iVar3 + 0x10) = 1;
    uVar4 = FUN_00057b80(param_1,param_2);
    *(undefined1 *)(iVar10 * 0x28 + *(int *)(iVar8 + 0x4c) + 0x10) = uVar1;
    local_80 = 0;
    local_98 = 3;
    local_90 = 1;
    local_8c = 1;
    local_88 = 1;
    local_84 = 1;
    local_94 = iVar10;
    FUN_00056f20(param_1,param_2,&local_98,iVar9,3,0,0);
    FUN_00057340(param_2,piVar5,iVar6,iVar9 + 4,0);
    uVar2 = *(uint *)(iVar9 + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(iVar9 + 0xc) = uVar2;
    *(uint *)(iVar9 + 8) = uVar2;
    local_80 = 0;
    local_84 = 1;
    local_98 = 3;
    local_90 = 1;
    local_8c = 1;
    local_88 = 1;
    local_94 = uVar4;
    FUN_00056f20(param_1,param_2,&local_98,iVar9 + 0x10,2,0,0);
    local_74 = 0x87d7;
    local_70 = 0x87d5;
    local_64 = 0;
    local_6c = 0x87d6;
    local_68 = 0x87dd;
    local_7c = 3;
    local_78 = iVar10;
    FUN_00057340(param_2,piVar5,local_58,iVar9 + 0x14,0);
    FUN_00057340(param_2,piVar5,iVar7,iVar9 + 0x18,0);
    uVar2 = *(uint *)(iVar9 + 0x18);
    uVar2 = (uVar2 & 0x2000000) << 2 |
            uVar2 >> 1 & 0x4000000 |
            uVar2 >> 1 & 0x2000000 |
            (uVar2 & 0xe000) << 6 | uVar2 >> 3 & 0x70000 | uVar2 >> 3 & 0xe000 | uVar2 & 0xe0001fff
            | 0x1000000;
    *(uint *)(iVar9 + 0x1c) = uVar2;
    *(uint *)(iVar9 + 0x18) = uVar2;
    FUN_00056f20(param_1,param_2,iStack00000020 + 4,iVar9 + 0x20,4,0,0);
    local_74 = 0x87d6;
    local_70 = 0x87d7;
    local_64 = 0;
    local_6c = 0x87d5;
    local_68 = 0x87de;
    local_7c = 3;
    local_78 = iVar10;
    FUN_00057340(param_2,piVar5,local_58,iVar9 + 0x24,0);
    FUN_00057340(param_2,piVar5,iVar7,iVar9 + 0x28,0);
    uVar2 = *(uint *)(iVar9 + 0x28);
    *(uint *)(iVar9 + 0x28) =
         (uVar2 & 0x4000000) << 1 |
         (uVar2 & 0x2000000) << 1 |
         uVar2 >> 2 & 0x2000000 |
         (uVar2 & 0x70000) << 3 | (uVar2 & 0xe000) << 3 | uVar2 >> 6 & 0xe000 | uVar2 & 0xe0001fff |
         0x1400000;
    local_74 = 0x87d9;
    local_70 = 0x87da;
    local_7c = 3;
    local_6c = 0x87db;
    local_68 = 0x87dc;
    local_64 = 0;
    local_78 = uVar4;
    FUN_00057340(param_2,piVar5,local_58,iVar9 + 0x2c,0);
    uVar4 = 3;
  }
  return uVar4;
}

/* FUN_0005c600 @ 0x5c600 (1552 bytes) */
int FUN_0005c600(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined1 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined1 uStack_54;
  
  if ((*(int *)(param_3 + 4) != *(int *)(param_3 + 0x3c)) ||
     (*(int *)(param_3 + 8) != *(int *)(param_3 + 0x40))) {
    piVar5 = param_2 + 7;
    iVar4 = param_3 + 0x20;
    iVar6 = param_3 + 0x3c;
    iVar2 = FUN_00057af0(piVar5,iVar4,iVar6);
    if (iVar2 == 0) {
      iVar7 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
      iVar2 = *(int *)(iVar7 + 0x18);
      if (0x100 < iVar2 + 4U) {
        *(undefined1 *)(param_2 + 4) = 0;
        iVar2 = *(int *)(iVar7 + 0x18);
        if (*(uint *)(iVar7 + 0x20) < iVar2 + 4U) {
          uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar7 + 0x20) * 0x10 + 0x100);
          (**(code **)(((unsigned char *)0x00001344) + param_1))
                    (uVar3,*(undefined4 *)(iVar7 + 0x1c),*(int *)(iVar7 + 0x20) << 4);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar7 + 0x1c));
          *(undefined4 *)(iVar7 + 0x1c) = uVar3;
          iVar2 = *(int *)(iVar7 + 0x18);
          *(int *)(iVar7 + 0x20) = *(int *)(iVar7 + 0x20) + 0x10;
        }
      }
      iVar8 = *(int *)(iVar7 + 0x1c);
      iVar2 = iVar2 * 0x10;
      iVar7 = param_3 + 4;
      iVar9 = iVar2 + iVar8;
      FUN_00056f20(param_1,param_2,iVar7,iVar9,1,0,0);
      *(uint *)(iVar2 + iVar8) = *(uint *)(iVar2 + iVar8) & 0xff1fffff;
      FUN_00057340(param_2,piVar5,iVar4,iVar9 + 4,0);
      FUN_00057340(param_2,piVar5,iVar6,iVar9 + 8,0);
      *(undefined4 *)(iVar9 + 0xc) = *(undefined4 *)(iVar9 + 8);
      FUN_00056f20(param_1,param_2,iVar7,iVar9 + 0x10,1,0,0);
      *(uint *)(iVar9 + 0x10) = *(uint *)(iVar9 + 0x10) & 0xff2fffff;
      FUN_00057340(param_2,piVar5,iVar4,iVar9 + 0x14,1);
      FUN_00057340(param_2,piVar5,iVar6,iVar9 + 0x18,0);
      *(undefined4 *)(iVar9 + 0x1c) = *(undefined4 *)(iVar9 + 0x18);
      FUN_00056f20(param_1,param_2,iVar7,iVar9 + 0x20,1,0,0);
      *(uint *)(iVar9 + 0x20) = *(uint *)(iVar9 + 0x20) & 0xff4fffff;
      FUN_00057340(param_2,piVar5,iVar4,iVar9 + 0x24,2);
      FUN_00057340(param_2,piVar5,iVar6,iVar9 + 0x28,0);
      *(undefined4 *)(iVar9 + 0x2c) = *(undefined4 *)(iVar9 + 0x28);
      FUN_00056f20(param_1,param_2,iVar7,iVar9 + 0x30,1,0,0);
      *(uint *)(iVar9 + 0x30) = *(uint *)(iVar9 + 0x30) & 0xff8fffff;
      FUN_00057340(param_2,piVar5,iVar4,iVar9 + 0x34,3);
      FUN_00057340(param_2,piVar5,iVar6,iVar9 + 0x38,0);
      *(undefined4 *)(iVar9 + 0x3c) = *(undefined4 *)(iVar9 + 0x38);
      return 4;
    }
  }
  piVar5 = param_2 + 7;
  iVar2 = param_3 + 0x20;
  iVar4 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar6 = *(int *)(iVar4 + 0x18);
  if (0x100 < iVar6 + 5U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar6 = *(int *)(iVar4 + 0x18);
    if (*(uint *)(iVar4 + 0x20) < iVar6 + 5U) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar3,*(undefined4 *)(iVar4 + 0x1c),*(int *)(iVar4 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0x1c));
      *(undefined4 *)(iVar4 + 0x1c) = uVar3;
      iVar6 = *(int *)(iVar4 + 0x18);
      *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x10;
    }
  }
  iVar7 = param_3 + 4;
  iVar4 = iVar6 * 0x10 + *(int *)(iVar4 + 0x1c);
  uVar3 = FUN_00057b80(param_1,param_2);
  uStack_88 = 3;
  uStack_70 = 0;
  uStack_74 = 1;
  uStack_80 = 1;
  uStack_7c = 1;
  uStack_78 = 1;
  uStack_84 = uVar3;
  FUN_00056f20(param_1,param_2,&uStack_88,iVar4,3,0,0);
  FUN_00057340(param_2,piVar5,param_3 + 0x3c,iVar4 + 4,0);
  uVar1 = *(uint *)(iVar4 + 4) & 0xfe001fff | 0x1248000;
  *(uint *)(iVar4 + 0xc) = uVar1;
  *(uint *)(iVar4 + 8) = uVar1;
  FUN_00056f20(param_1,param_2,iVar7,iVar4 + 0x10,1,0,0);
  *(uint *)(iVar4 + 0x10) = *(uint *)(iVar4 + 0x10) & 0xff1fffff;
  FUN_00057340(param_2,piVar5,iVar2,iVar4 + 0x14,0);
  uStack_6c = 3;
  uStack_54 = 0;
  uStack_60 = 0x87d6;
  uStack_64 = 0x87d5;
  uStack_5c = 0x87d7;
  uStack_58 = 0x87d8;
  uStack_68 = uVar3;
  FUN_00057340(param_2,piVar5,&uStack_6c,iVar4 + 0x18,0);
  *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar4 + 0x18);
  FUN_00056f20(param_1,param_2,iVar7,iVar4 + 0x20,1,0,0);
  *(uint *)(iVar4 + 0x20) = *(uint *)(iVar4 + 0x20) & 0xff2fffff;
  FUN_00057340(param_2,piVar5,iVar2,iVar4 + 0x24,1);
  FUN_00057340(param_2,piVar5,&uStack_6c,iVar4 + 0x28,0);
  *(undefined4 *)(iVar4 + 0x2c) = *(undefined4 *)(iVar4 + 0x28);
  FUN_00056f20(param_1,param_2,iVar7,iVar4 + 0x30,1,0,0);
  *(uint *)(iVar4 + 0x30) = *(uint *)(iVar4 + 0x30) & 0xff4fffff;
  FUN_00057340(param_2,piVar5,iVar2,iVar4 + 0x34,2);
  FUN_00057340(param_2,piVar5,&uStack_6c,iVar4 + 0x38,0);
  *(undefined4 *)(iVar4 + 0x3c) = *(undefined4 *)(iVar4 + 0x38);
  FUN_00056f20(param_1,param_2,iVar7,iVar4 + 0x40,1,0,0);
  *(uint *)(iVar4 + 0x40) = *(uint *)(iVar4 + 0x40) & 0xff8fffff;
  FUN_00057340(param_2,piVar5,iVar2,iVar4 + 0x44,3);
  FUN_00057340(param_2,piVar5,&uStack_6c,iVar4 + 0x48,0);
  *(undefined4 *)(iVar4 + 0x4c) = *(undefined4 *)(iVar4 + 0x48);
  return 5;
}

/* FUN_0005cc20 @ 0x5cc20 (320 bytes) */
int FUN_0005cc20(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar3 = *(int *)(iVar4 + 0x18);
  if (0x100 < iVar3 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar3 = *(int *)(iVar4 + 0x18);
    if (*(uint *)(iVar4 + 0x20) < iVar3 + 1U) {
      uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar2,*(undefined4 *)(iVar4 + 0x1c),*(int *)(iVar4 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0x1c));
      *(undefined4 *)(iVar4 + 0x1c) = uVar2;
      iVar3 = *(int *)(iVar4 + 0x18);
      *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x10;
    }
  }
  iVar3 = iVar3 * 0x10 + *(int *)(iVar4 + 0x1c);
  FUN_00056f20(param_1,param_2,param_3 + 4,iVar3,3,0,0);
  FUN_00057340(param_2,param_2 + 7,param_3 + 0x20,iVar3 + 4,0);
  uVar1 = *(uint *)(iVar3 + 4) & 0xfe001fff | 0x1248000;
  *(uint *)(iVar3 + 0xc) = uVar1;
  *(uint *)(iVar3 + 8) = uVar1;
  return 1;
}

/* FUN_0005cd60 @ 0x5cd60 (1228 bytes) */
int FUN_0005cd60(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar4 = *(int *)(iVar5 + 0x18);
  if (0x100 < iVar4 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar4 = *(int *)(iVar5 + 0x18);
    if (*(uint *)(iVar5 + 0x20) < iVar4 + 1U) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
      *(undefined4 *)(iVar5 + 0x1c) = uVar3;
      iVar4 = *(int *)(iVar5 + 0x18);
      *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
    }
  }
  iVar4 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
  FUN_00056f20(param_1,param_2,param_3 + 4,iVar4,3,0,0);
  FUN_00057340(param_2,param_2 + 7,param_3 + 0x20,iVar4 + 4,0);
  switch(*(undefined4 *)(param_3 + 0x28)) {
  case 0x87d5:
  case 0x87d9:
    uVar1 = *(uint *)(iVar4 + 4) & 0xffff1fff;
    *(uint *)(iVar4 + 4) = uVar1;
    break;
  case 0x87d6:
  case 0x87da:
    uVar1 = *(uint *)(iVar4 + 4) & 0xffff1fff | 0x2000;
    *(uint *)(iVar4 + 4) = uVar1;
    break;
  case 0x87d7:
  case 0x87db:
    uVar1 = *(uint *)(iVar4 + 4) & 0xffff1fff | 0x4000;
    *(uint *)(iVar4 + 4) = uVar1;
    break;
  case 0x87d8:
  case 0x87dc:
    uVar1 = *(uint *)(iVar4 + 4) & 0xffff1fff | 0x6000;
    *(uint *)(iVar4 + 4) = uVar1;
    break;
  case 0x87dd:
    uVar1 = *(uint *)(iVar4 + 4) & 0xffff1fff | 0x8000;
    *(uint *)(iVar4 + 4) = uVar1;
    break;
  case 0x87de:
  case 0x87df:
    uVar1 = *(uint *)(iVar4 + 4) & 0xffff1fff | 0xa000;
    *(uint *)(iVar4 + 4) = uVar1;
    break;
  default:
    goto LAB_0005d2d0;
  }
  uVar2 = *(int *)(param_3 + 0x28) - 0x87d5;
  if (uVar2 < 0xb) {
    uVar2 = 1 << (uVar2 & 0x3f);
    if ((uVar2 & 0x30f) == 0) {
      if ((uVar2 & 0x4f0) == 0) {
        return 0;
      }
      uVar1 = uVar1 | 0x2000000;
      *(uint *)(iVar4 + 4) = uVar1;
    }
    else {
      uVar1 = uVar1 & 0xfdffffff;
      *(uint *)(iVar4 + 4) = uVar1;
    }
    switch(*(undefined4 *)(param_3 + 0x2c)) {
    case 0x87d5:
    case 0x87d9:
      uVar1 = uVar1 & 0xfff8ffff;
      *(uint *)(iVar4 + 4) = uVar1;
      break;
    case 0x87d6:
    case 0x87da:
      uVar1 = uVar1 & 0xfff8ffff | 0x10000;
      *(uint *)(iVar4 + 4) = uVar1;
      break;
    case 0x87d7:
    case 0x87db:
      uVar1 = uVar1 & 0xfff8ffff | 0x20000;
      *(uint *)(iVar4 + 4) = uVar1;
      break;
    case 0x87d8:
    case 0x87dc:
      uVar1 = uVar1 & 0xfff8ffff | 0x30000;
      *(uint *)(iVar4 + 4) = uVar1;
      break;
    case 0x87dd:
      uVar1 = uVar1 & 0xfff8ffff | 0x40000;
      *(uint *)(iVar4 + 4) = uVar1;
      break;
    case 0x87de:
    case 0x87df:
      uVar1 = uVar1 & 0xfff8ffff | 0x50000;
      *(uint *)(iVar4 + 4) = uVar1;
      break;
    default:
      goto LAB_0005d2d0;
    }
    uVar2 = *(int *)(param_3 + 0x2c) - 0x87d5;
    if (uVar2 < 0xb) {
      uVar2 = 1 << (uVar2 & 0x3f);
      if ((uVar2 & 0x30f) == 0) {
        if ((uVar2 & 0x4f0) == 0) {
          return 0;
        }
        uVar1 = uVar1 | 0x4000000;
        *(uint *)(iVar4 + 4) = uVar1;
      }
      else {
        uVar1 = uVar1 & 0xfbffffff;
        *(uint *)(iVar4 + 4) = uVar1;
      }
      switch(*(undefined4 *)(param_3 + 0x30)) {
      case 0x87d5:
      case 0x87d9:
        uVar1 = uVar1 & 0xffc7ffff;
        *(uint *)(iVar4 + 4) = uVar1;
        break;
      case 0x87d6:
      case 0x87da:
        uVar1 = uVar1 & 0xffc7ffff | 0x80000;
        *(uint *)(iVar4 + 4) = uVar1;
        break;
      case 0x87d7:
      case 0x87db:
        uVar1 = uVar1 & 0xffc7ffff | 0x100000;
        *(uint *)(iVar4 + 4) = uVar1;
        break;
      case 0x87d8:
      case 0x87dc:
        uVar1 = uVar1 & 0xffc7ffff | 0x180000;
        *(uint *)(iVar4 + 4) = uVar1;
        break;
      case 0x87dd:
        uVar1 = uVar1 & 0xffc7ffff | 0x200000;
        *(uint *)(iVar4 + 4) = uVar1;
        break;
      case 0x87de:
      case 0x87df:
        uVar1 = uVar1 & 0xffc7ffff | 0x280000;
        *(uint *)(iVar4 + 4) = uVar1;
        break;
      default:
        goto LAB_0005d2d0;
      }
      uVar2 = *(int *)(param_3 + 0x30) - 0x87d5;
      if (uVar2 < 0xb) {
        uVar2 = 1 << (uVar2 & 0x3f);
        if ((uVar2 & 0x30f) == 0) {
          if ((uVar2 & 0x4f0) == 0) {
            return 0;
          }
          uVar1 = uVar1 | 0x8000000;
          *(uint *)(iVar4 + 4) = uVar1;
        }
        else {
          uVar1 = uVar1 & 0xf7ffffff;
          *(uint *)(iVar4 + 4) = uVar1;
        }
        switch(*(undefined4 *)(param_3 + 0x34)) {
        case 0x87d5:
        case 0x87d9:
          uVar1 = uVar1 & 0xfe3fffff;
          *(uint *)(iVar4 + 4) = uVar1;
          break;
        case 0x87d6:
        case 0x87da:
          uVar1 = uVar1 & 0xfe3fffff | 0x400000;
          *(uint *)(iVar4 + 4) = uVar1;
          break;
        case 0x87d7:
        case 0x87db:
          uVar1 = uVar1 & 0xfe3fffff | 0x800000;
          *(uint *)(iVar4 + 4) = uVar1;
          break;
        case 0x87d8:
        case 0x87dc:
          uVar1 = uVar1 & 0xfe3fffff | 0xc00000;
          *(uint *)(iVar4 + 4) = uVar1;
          break;
        case 0x87dd:
          uVar1 = uVar1 & 0xfe3fffff | 0x1000000;
          *(uint *)(iVar4 + 4) = uVar1;
          break;
        case 0x87de:
        case 0x87df:
          uVar1 = uVar1 & 0xfe3fffff | 0x1400000;
          *(uint *)(iVar4 + 4) = uVar1;
          break;
        default:
          goto LAB_0005d2d0;
        }
        uVar2 = *(int *)(param_3 + 0x34) - 0x87d5;
        if (uVar2 < 0xb) {
          uVar2 = 1 << (uVar2 & 0x3f);
          if ((uVar2 & 0x30f) == 0) {
            if ((uVar2 & 0x4f0) == 0) {
              return 0;
            }
            uVar1 = uVar1 | 0x10000000;
            *(uint *)(iVar4 + 4) = uVar1;
          }
          else {
            uVar1 = uVar1 & 0xefffffff;
            *(uint *)(iVar4 + 4) = uVar1;
          }
          uVar1 = uVar1 & 0xe0001fff | 0x1248000;
          *(uint *)(iVar4 + 0xc) = uVar1;
          *(uint *)(iVar4 + 8) = uVar1;
          return 1;
        }
      }
    }
  }
LAB_0005d2d0:
  return 0;
}

/* FUN_0005d2f0 @ 0x5d2f0 (372 bytes) */
int FUN_0005d2f0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar6 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar8 = *(int *)(iVar6 + 0x18);
  if (0x100 < iVar8 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar8 = *(int *)(iVar6 + 0x18);
    if (*(uint *)(iVar6 + 0x20) < iVar8 + 1U) {
      uVar5 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar6 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar5,*(undefined4 *)(iVar6 + 0x1c),*(int *)(iVar6 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar6 + 0x1c));
      *(undefined4 *)(iVar6 + 0x1c) = uVar5;
      iVar8 = *(int *)(iVar6 + 0x18);
      *(int *)(iVar6 + 0x20) = *(int *)(iVar6 + 0x20) + 0x10;
    }
  }
  iVar7 = *(int *)(iVar6 + 0x1c);
  iVar8 = iVar8 * 0x10;
  iVar6 = iVar8 + iVar7;
  FUN_00056f20(param_1,param_2,param_3 + 4,iVar6,3,0,0);
  uVar3 = *(uint *)(iVar8 + iVar7);
  uVar4 = (*(uint *)(param_3 + 0xc) & 1) << 0x14;
  *(uint *)(iVar8 + iVar7) = uVar4 | uVar3 & 0xffefffff;
  uVar1 = (*(uint *)(param_3 + 0x10) & 1) << 0x15;
  *(uint *)(iVar8 + iVar7) = uVar1 | uVar4 | uVar3 & 0xffcfffff;
  uVar2 = (*(uint *)(param_3 + 0x14) & 1) << 0x16;
  *(uint *)(iVar8 + iVar7) = uVar2 | uVar1 | uVar4 | uVar3 & 0xff8fffff;
  *(uint *)(iVar8 + iVar7) =
       (*(uint *)(param_3 + 0x18) & 1) << 0x17 | uVar2 | uVar1 | uVar4 | uVar3 & 0xff0fffff;
  FUN_00057340(param_2,param_2 + 7,param_3 + 0x20,iVar6 + 4,0);
  uVar4 = *(uint *)(iVar6 + 4) & 0xfe001fff | 0x1248000;
  *(uint *)(iVar6 + 0xc) = uVar4;
  *(uint *)(iVar6 + 8) = uVar4;
  return 1;
}

/* FUN_0005d470 @ 0x5d470 (424 bytes) */
int FUN_0005d470(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar3 = *(int *)(iVar4 + 0x18);
  if (0x100 < iVar3 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar3 = *(int *)(iVar4 + 0x18);
    if (*(uint *)(iVar4 + 0x20) < iVar3 + 1U) {
      uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar2,*(undefined4 *)(iVar4 + 0x1c),*(int *)(iVar4 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0x1c));
      *(undefined4 *)(iVar4 + 0x1c) = uVar2;
      iVar3 = *(int *)(iVar4 + 0x18);
      *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x10;
    }
  }
  iVar5 = param_3 + 4;
  iVar4 = iVar3 * 0x10 + *(int *)(iVar4 + 0x1c);
  iVar3 = FUN_000550e0(param_2 + 7,iVar5);
  if (*(uint *)(param_3 + 0x40) < 4) {
    if (iVar3 == 0x87bf) {
      FUN_00056f20(param_1,param_2,iVar5,iVar4,3,0,0);
    }
    else {
      if (iVar3 != 0x87c0) goto LAB_0005d600;
      FUN_00056f20(param_1,param_2,iVar5,iVar4,3,0,*(uint *)(param_3 + 0x40));
    }
    FUN_00057340(param_2,param_2 + 7,param_3 + 0x20,iVar4 + 4,0);
    uVar2 = 1;
    uVar1 = *(uint *)(iVar4 + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(iVar4 + 0xc) = uVar1;
    *(uint *)(iVar4 + 8) = uVar1;
  }
  else {
LAB_0005d600:
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* FUN_0005d620 @ 0x5d620 (568 bytes) */
int FUN_0005d620(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar2 = *(int *)(iVar5 + 0x18);
  if (0x100 < iVar2 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar2 = *(int *)(iVar5 + 0x18);
    if (*(uint *)(iVar5 + 0x20) < iVar2 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar1,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
      *(undefined4 *)(iVar5 + 0x1c) = uVar1;
      iVar2 = *(int *)(iVar5 + 0x18);
      *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
    }
  }
  piVar4 = param_2 + 7;
  iVar3 = param_3 + 0x20;
  iVar5 = iVar2 * 0x10 + *(int *)(iVar5 + 0x1c);
  iVar2 = FUN_000550e0(piVar4,iVar3);
  uVar6 = *(uint *)(param_3 + 0x40);
  if (uVar6 < 4) {
    FUN_00056f20(param_1,param_2,param_3 + 4,iVar5,3,0,0);
    if (iVar2 == 0x87bf) {
      FUN_00057340(param_2,piVar4,iVar3,iVar5 + 4,0);
      if (uVar6 == 1) {
        uVar6 = *(uint *)(iVar5 + 4) >> 0x10 & 7;
        uVar6 = uVar6 << 0x16 | uVar6 << 0x13 | uVar6 << 0xd | *(uint *)(iVar5 + 4) & 0xfe071fff;
        *(uint *)(iVar5 + 4) = uVar6;
      }
      else if (uVar6 == 0) {
        uVar6 = *(uint *)(iVar5 + 4) >> 0xd & 7;
        uVar6 = uVar6 << 0x16 | uVar6 << 0x13 | uVar6 << 0x10 | *(uint *)(iVar5 + 4) & 0xfe00ffff;
        *(uint *)(iVar5 + 4) = uVar6;
      }
      else if (uVar6 == 2) {
        uVar6 = *(uint *)(iVar5 + 4) >> 0x13 & 7;
        uVar6 = uVar6 << 0x16 | uVar6 << 0x10 | uVar6 << 0xd | *(uint *)(iVar5 + 4) & 0xfe381fff;
        *(uint *)(iVar5 + 4) = uVar6;
      }
      else {
        if (uVar6 != 3) goto LAB_0005d81c;
        uVar6 = *(uint *)(iVar5 + 4) >> 0x16 & 7;
        uVar6 = uVar6 << 0x13 | uVar6 << 0x10 | uVar6 << 0xd | *(uint *)(iVar5 + 4) & 0xffc01fff;
        *(uint *)(iVar5 + 4) = uVar6;
      }
    }
    else {
      if (iVar2 != 0x87c0) goto LAB_0005d850;
      FUN_00057340(param_2,piVar4,iVar3,iVar5 + 4,uVar6);
LAB_0005d81c:
      uVar6 = *(uint *)(iVar5 + 4);
    }
    uVar1 = 1;
    uVar6 = uVar6 & 0xfe001fff | 0x1248000;
    *(uint *)(iVar5 + 0xc) = uVar6;
    *(uint *)(iVar5 + 8) = uVar6;
  }
  else {
LAB_0005d850:
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* FUN_0005d870 @ 0x5d870 (336 bytes) */
int FUN_0005d870(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar3 = *(int *)(iVar4 + 0x18);
  if (0x100 < iVar3 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar3 = *(int *)(iVar4 + 0x18);
    if (*(uint *)(iVar4 + 0x20) < iVar3 + 1U) {
      uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar2,*(undefined4 *)(iVar4 + 0x1c),*(int *)(iVar4 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0x1c));
      *(undefined4 *)(iVar4 + 0x1c) = uVar2;
      iVar3 = *(int *)(iVar4 + 0x18);
      *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x10;
    }
  }
  iVar3 = iVar3 * 0x10 + *(int *)(iVar4 + 0x1c);
  FUN_00056f20(param_1,param_2,param_3 + 4,iVar3,4,1,0);
  FUN_00057340(param_2,param_2 + 7,param_3 + 0x20,iVar3 + 4,0);
  uVar1 = *(uint *)(iVar3 + 4);
  *(uint *)(iVar3 + 0xc) = uVar1;
  *(uint *)(iVar3 + 4) = (uVar1 & 0x4000000) << 2 | (uVar1 & 0x70000) << 6 | uVar1 & 0xee3fffff;
  *(uint *)(iVar3 + 8) = (uVar1 & 0x2000000) << 3 | (uVar1 & 0xe000) << 9 | uVar1 & 0xee3fffff;
  return 1;
}

/* FUN_0005d9c0 @ 0x5d9c0 (824 bytes) */
int FUN_0005d9c0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44;
  
  iVar5 = param_3 + 0x20;
  piVar6 = param_2 + 7;
  iVar4 = param_3 + 0x3c;
  iVar2 = FUN_00057af0(piVar6,iVar5,iVar4);
  if (iVar2 == 0) {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 1U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 1U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    FUN_00056f20(param_1,param_2,param_3 + 4,iVar2,5,0,0);
    FUN_00057340(param_2,piVar6,iVar5,iVar2 + 4,0);
    FUN_00057340(param_2,piVar6,iVar4,iVar2 + 8,0);
    uVar3 = 1;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 8);
  }
  else {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    uVar3 = FUN_00057b80(param_1,param_2);
    local_78 = 3;
    local_60 = 0;
    local_64 = 1;
    local_70 = 1;
    local_6c = 1;
    local_68 = 1;
    local_74 = uVar3;
    FUN_00056f20(param_1,param_2,&local_78,iVar2,3,0,0);
    FUN_00057340(param_2,piVar6,iVar5,iVar2 + 4,0);
    uVar1 = *(uint *)(iVar2 + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(iVar2 + 0xc) = uVar1;
    *(uint *)(iVar2 + 8) = uVar1;
    FUN_00056f20(param_1,param_2,param_3 + 4,iVar2 + 0x10,5,0,0);
    local_5c = 3;
    local_44 = 0;
    local_54 = 0x87d5;
    local_50 = 0x87d6;
    local_4c = 0x87d7;
    local_48 = 0x87d8;
    local_58 = uVar3;
    FUN_00057340(param_2,piVar6,&local_5c,iVar2 + 0x14,0);
    FUN_00057340(param_2,piVar6,iVar4,iVar2 + 0x18,0);
    uVar3 = 2;
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x18);
  }
  return uVar3;
}

/* FUN_0005dd00 @ 0x5dd00 (324 bytes) */
int FUN_0005dd00(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar3 = *(int *)(iVar4 + 0x18);
  if (0x100 < iVar3 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar3 = *(int *)(iVar4 + 0x18);
    if (*(uint *)(iVar4 + 0x20) < iVar3 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar1,*(undefined4 *)(iVar4 + 0x1c),*(int *)(iVar4 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0x1c));
      *(undefined4 *)(iVar4 + 0x1c) = uVar1;
      iVar3 = *(int *)(iVar4 + 0x18);
      *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x10;
    }
  }
  iVar3 = iVar3 * 0x10 + *(int *)(iVar4 + 0x1c);
  FUN_00056f20(param_1,param_2,param_3 + 4,iVar3,1,1,0);
  FUN_00057340(param_2,param_2 + 7,param_3 + 0x20,iVar3 + 4,0);
  uVar2 = *(uint *)(iVar3 + 4);
  uVar2 = (uVar2 & 0x2000000) << 3 | (uVar2 & 0xe000) << 9 | uVar2 & 0xee3fffff;
  *(uint *)(iVar3 + 0xc) = uVar2;
  *(uint *)(iVar3 + 4) = uVar2;
  *(uint *)(iVar3 + 8) = uVar2;
  return 1;
}

/* FUN_0005de50 @ 0x5de50 (324 bytes) */
int FUN_0005de50(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar3 = *(int *)(iVar4 + 0x18);
  if (0x100 < iVar3 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar3 = *(int *)(iVar4 + 0x18);
    if (*(uint *)(iVar4 + 0x20) < iVar3 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar1,*(undefined4 *)(iVar4 + 0x1c),*(int *)(iVar4 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0x1c));
      *(undefined4 *)(iVar4 + 0x1c) = uVar1;
      iVar3 = *(int *)(iVar4 + 0x18);
      *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x10;
    }
  }
  iVar3 = iVar3 * 0x10 + *(int *)(iVar4 + 0x1c);
  FUN_00056f20(param_1,param_2,param_3 + 4,iVar3,2,1,0);
  FUN_00057340(param_2,param_2 + 7,param_3 + 0x20,iVar3 + 4,0);
  uVar2 = *(uint *)(iVar3 + 4);
  uVar2 = (uVar2 & 0x2000000) << 3 | (uVar2 & 0xe000) << 9 | uVar2 & 0xee3fffff;
  *(uint *)(iVar3 + 0xc) = uVar2;
  *(uint *)(iVar3 + 4) = uVar2;
  *(uint *)(iVar3 + 8) = uVar2;
  return 1;
}

/* FUN_0005dfa0 @ 0x5dfa0 (304 bytes) */
int FUN_0005dfa0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar2 = *(int *)(iVar3 + 0x18);
  if (0x100 < iVar2 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar2 = *(int *)(iVar3 + 0x18);
    if (*(uint *)(iVar3 + 0x20) < iVar2 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar1,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0x1c) = uVar1;
      iVar2 = *(int *)(iVar3 + 0x18);
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
    }
  }
  iVar2 = iVar2 * 0x10 + *(int *)(iVar3 + 0x1c);
  FUN_00056f20(param_1,param_2,param_3 + 4,iVar2,0xd,0,0);
  FUN_00057340(param_2,param_2 + 7,param_3 + 0x20,iVar2 + 4,0);
  *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 4);
  *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 4);
  return 1;
}

/* FUN_0005e0d0 @ 0x5e0d0 (1676 bytes) */
int FUN_0005e0d0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  uint *param_3;
{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 local_a8;
  uint local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  uint local_94;
  undefined1 local_90;
  undefined4 local_8c;
  uint local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined1 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 local_58;
  
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  iVar3 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  uVar2 = *(undefined4 *)(iVar3 + 0x60);
  local_a4 = FUN_00057b80(param_1,param_2);
  *param_3 = (local_a4 & 0x7f) << 0xd | *param_3 & 0xfff010ff | 0x100000;
  sVar1 = *(short *)(((unsigned char *)0x00002e04) + iVar5);
  local_88 = local_a4;
  local_6c = uVar2;
  if (sVar1 == 0x801) {
    iVar5 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar6 = *(int *)(iVar5 + 0x18);
    if (0x100 < iVar6 + 3U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar6 = *(int *)(iVar5 + 0x18);
      if (*(uint *)(iVar5 + 0x20) < iVar6 + 3U) {
        uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar2,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
        *(undefined4 *)(iVar5 + 0x1c) = uVar2;
        iVar6 = *(int *)(iVar5 + 0x18);
        *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
      }
    }
    local_9c = 0;
    local_98 = 0;
    local_94 = 0;
    local_90 = 0;
    local_a8 = 3;
    iVar5 = iVar6 * 0x10 + *(int *)(iVar5 + 0x1c);
    local_a0 = 1;
    piVar4 = param_2 + 7;
    FUN_00056f20(param_1,param_2,&local_a8,iVar5,2,0,0);
    local_8c = 3;
    local_74 = 0;
    local_78 = 0x87d5;
    local_84 = 0x87d5;
    local_80 = 0x87d5;
    local_7c = 0x87d5;
    FUN_00057340(param_2,piVar4,&local_8c,iVar5 + 4,0);
    FUN_00057340(param_2,piVar4,&local_8c,iVar5 + 8,0);
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
    FUN_00056f20(param_1,param_2,&local_a8,iVar5 + 0x10,2,0,0);
    FUN_00057340(param_2,piVar4,&local_8c,iVar5 + 0x14,0);
    local_58 = 0;
    local_70 = 4;
    local_5c = 0x87d7;
    local_68 = 0x87d7;
    local_64 = 0x87d7;
    local_60 = 0x87d7;
    FUN_00057340(param_2,piVar4,&local_70,iVar5 + 0x18,0);
    *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x18);
    local_a8 = 1;
    local_a4 = 0x87bd;
    local_a0 = 0;
    local_9c = 0;
    local_98 = 0;
    local_94 = (uint)*(byte *)(iVar3 + 0x42);
    local_90 = 0;
    FUN_00056f20(param_1,param_2,&local_a8,iVar5 + 0x20,3,1,0);
    FUN_00057340(param_2,piVar4,&local_8c,iVar5 + 0x24,0);
    uVar2 = 3;
    *(undefined4 *)(iVar5 + 0x2c) = *(undefined4 *)(iVar5 + 0x24);
    *(undefined4 *)(iVar5 + 0x28) = *(undefined4 *)(iVar5 + 0x24);
  }
  else if (sVar1 == 0x2601) {
    iVar5 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar6 = *(int *)(iVar5 + 0x18);
    if (0x100 < iVar6 + 1U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar6 = *(int *)(iVar5 + 0x18);
      if (*(uint *)(iVar5 + 0x20) < iVar6 + 1U) {
        uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar2,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
        *(undefined4 *)(iVar5 + 0x1c) = uVar2;
        iVar6 = *(int *)(iVar5 + 0x18);
        *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
      }
    }
    local_a0 = 0;
    local_9c = 0;
    local_a8 = 1;
    local_98 = 0;
    local_a4 = 0x87bd;
    iVar5 = iVar6 * 0x10 + *(int *)(iVar5 + 0x1c);
    local_94 = (uint)*(byte *)(iVar3 + 0x42);
    local_90 = 0;
    FUN_00056f20(param_1,param_2,&local_a8,iVar5,1,0,0);
    local_84 = 0x87dd;
    local_78 = 0x87dd;
    local_74 = 0;
    local_80 = 0x87de;
    local_8c = 3;
    local_7c = 0x87d5;
    FUN_00057340(param_2,param_2 + 7,&local_8c,iVar5 + 4,0);
    local_5c = 0x87dd;
    local_58 = 0;
    local_68 = 0x87dd;
    local_64 = 0x87d6;
    local_60 = 0x87d7;
    local_70 = 4;
    FUN_00057340(param_2,param_2 + 7,&local_70,iVar5 + 8,0);
    uVar2 = 1;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
  }
  else {
    uVar2 = 0;
    if (sVar1 == 0x800) {
      iVar5 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
      iVar6 = *(int *)(iVar5 + 0x18);
      if (0x100 < iVar6 + 2U) {
        *(undefined1 *)(param_2 + 4) = 0;
        iVar6 = *(int *)(iVar5 + 0x18);
        if (*(uint *)(iVar5 + 0x20) < iVar6 + 2U) {
          uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
          (**(code **)(((unsigned char *)0x00001344) + param_1))
                    (uVar2,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
          *(undefined4 *)(iVar5 + 0x1c) = uVar2;
          iVar6 = *(int *)(iVar5 + 0x18);
          *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
        }
      }
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_a8 = 3;
      iVar5 = iVar6 * 0x10 + *(int *)(iVar5 + 0x1c);
      local_a0 = 1;
      piVar4 = param_2 + 7;
      FUN_00056f20(param_1,param_2,&local_a8,iVar5,2,0,0);
      local_8c = 3;
      local_74 = 0;
      local_78 = 0x87d5;
      local_84 = 0x87d5;
      local_80 = 0x87d5;
      local_7c = 0x87d5;
      FUN_00057340(param_2,piVar4,&local_8c,iVar5 + 4,0);
      local_58 = 0;
      local_70 = 4;
      local_5c = 0x87d7;
      local_68 = 0x87d7;
      local_64 = 0x87d7;
      local_60 = 0x87d7;
      FUN_00057340(param_2,piVar4,&local_70,iVar5 + 8,0);
      *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
      local_a8 = 1;
      local_a4 = 0x87bd;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = (uint)*(byte *)(iVar3 + 0x42);
      local_90 = 0;
      FUN_00056f20(param_1,param_2,&local_a8,iVar5 + 0x10,3,1,0);
      FUN_00057340(param_2,piVar4,&local_8c,iVar5 + 0x14,0);
      uVar2 = 2;
      *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x14);
      *(undefined4 *)(iVar5 + 0x18) = *(undefined4 *)(iVar5 + 0x14);
    }
  }
  return uVar2;
}

/* FUN_0005e770 @ 0x5e770 (108 bytes) */
int FUN_0005e770(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  
  uVar1 = 0;
  while( true ) {
    iVar4 = *(int *)(param_1 + uVar1 * 4);
    if ((iVar4 != 0) && (uVar5 = uVar1 + 1, uVar5 < 0x20)) {
      iVar2 = 0x20 - uVar5;
      puVar3 = (undefined4 *)(param_1 + uVar5 * 4);
      do {
        puVar3[-1] = *puVar3;
        puVar3 = puVar3 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    uVar1 = uVar1 + 1;
    if (0x1f < uVar1) break;
    if (iVar4 != 0) {
      return iVar4;
    }
  }
  return iVar4;
}

/* FUN_0005e7f0 @ 0x5e7f0 (3156 bytes) */
int FUN_0005e7f0(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int local_248 [32];
  int local_1c8 [32];
  int local_148 [32];
  int local_c8 [34];
  
  iVar7 = 0;
  iVar15 = 0x20;
  iVar11 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  *(undefined4 *)(iVar11 + 0x234) = 1;
  do {
    *(undefined4 *)((int)local_248 + iVar7) = 0;
    *(undefined4 *)(iVar7 + (int)local_1c8) = 0;
    *(undefined4 *)(iVar7 + (int)local_148) = 0;
    *(undefined4 *)(iVar7 + (int)local_c8) = 0;
    iVar7 = iVar7 + 4;
    iVar15 = iVar15 + -1;
  } while (iVar15 != 0);
  if (param_2[5] == 0) {
    iVar9 = 0;
    iVar10 = 0;
    iVar15 = 0;
  }
  else {
    iVar7 = 0;
    uVar13 = 0;
    iVar9 = 0;
    iVar10 = 0;
    iVar15 = 0;
    do {
      iVar5 = uVar13 * 0x74;
      iVar17 = param_2[6];
      iVar16 = iVar7;
      if (((*(int *)(iVar5 + iVar17 + 0x20) == 2) &&
          (iVar4 = *(int *)(iVar5 + iVar17 + 0x24) * 0x54 + param_2[8],
          *(int *)(iVar4 + 0x28) == 0x87c1)) && (*(char *)(iVar4 + 0x3d) == '\0')) {
        if ((*(char *)(iVar4 + 0x44) == '\0') || (*(int *)(iVar4 + 0x48) == 0x12)) {
          iVar7 = *(int *)(iVar4 + 0x24);
          if (iVar7 == 0x87bf) {
            local_148[iVar10] = iVar4;
            iVar10 = iVar10 + 1;
          }
          else if (iVar7 == 0x87c0) {
            local_c8[iVar15] = iVar4;
            iVar15 = iVar15 + 1;
          }
          else if (iVar7 == 0x87be) {
            local_1c8[iVar9] = iVar4;
            iVar9 = iVar9 + 1;
          }
        }
        else {
          iVar16 = iVar7 + 1;
          local_248[iVar7] = iVar4;
          switch(*(undefined4 *)(iVar4 + 0x48)) {
          case 0:
            *(undefined1 *)(iVar11 + 0x2c) = 1;
            break;
          case 1:
            *(undefined1 *)(iVar11 + 0x2d) = 1;
            param_2[0xc] = param_2[0xc] | 8;
            break;
          case 2:
            iVar7 = *(int *)(iVar4 + 0x4c);
            *(undefined1 *)(iVar7 + iVar11 + 0x2e) = 1;
            *(undefined1 *)((int)param_2 + iVar7 + 0x34) = 1;
            param_2[0xc] = param_2[0xc] | 4;
            break;
          case 3:
            *(undefined1 *)(iVar11 + 0x36) = 1;
            param_2[0xc] = param_2[0xc] | 1;
            break;
          case 4:
            *(undefined1 *)(iVar11 + 0x37) = 1;
            break;
          case 5:
            *(undefined1 *)(iVar11 + 0x38) = 1;
            break;
          case 6:
            *(undefined1 *)(iVar11 + 0x39) = 1;
            break;
          case 7:
            *(undefined1 *)(iVar11 + 0x36) = 1;
            break;
          case 8:
            *(undefined1 *)(iVar11 + 0x3b) = 1;
            break;
          case 9:
            *(undefined1 *)(iVar11 + 0x3c) = 1;
            break;
          case 10:
            *(undefined1 *)(iVar11 + 0x3d) = 1;
            break;
          case 0xb:
            *(undefined1 *)(iVar11 + 0x3a) = 1;
            break;
          case 0xc:
            *(undefined1 *)(iVar11 + 0x40) = 1;
            break;
          case 0xd:
            *(undefined1 *)(iVar11 + 0x41) = 1;
            break;
          case 0xe:
            *(undefined1 *)(iVar11 + 0x37) = 1;
            param_2[0xc] = param_2[0xc] | 2;
            break;
          case 0xf:
            *(undefined1 *)(iVar11 + 0x3e) = 1;
            param_2[0xc] = param_2[0xc] | 0x40;
            break;
          case 0x10:
            *(undefined1 *)(iVar11 + 0x3f) = 1;
            param_2[0xc] = param_2[0xc] | 0x80;
          }
        }
        *(undefined1 *)(iVar4 + 0x3d) = 1;
        iVar17 = param_2[6];
        param_2[0x16] = param_2[0x16] + 1;
      }
      iVar4 = iVar16;
      if (((*(int *)(iVar5 + iVar17 + 0x3c) == 2) &&
          (iVar7 = *(int *)(iVar5 + iVar17 + 0x40) * 0x54 + param_2[8],
          *(int *)(iVar7 + 0x28) == 0x87c1)) && (*(char *)(iVar7 + 0x3d) == '\0')) {
        if ((*(char *)(iVar7 + 0x44) == '\0') || (*(int *)(iVar7 + 0x48) == 0x12)) {
          iVar16 = *(int *)(iVar7 + 0x24);
          if (iVar16 == 0x87bf) {
            local_148[iVar10] = iVar7;
            iVar10 = iVar10 + 1;
          }
          else if (iVar16 == 0x87c0) {
            local_c8[iVar15] = iVar7;
            iVar15 = iVar15 + 1;
          }
          else if (iVar16 == 0x87be) {
            local_1c8[iVar9] = iVar7;
            iVar9 = iVar9 + 1;
          }
        }
        else {
          iVar4 = iVar16 + 1;
          local_248[iVar16] = iVar7;
          switch(*(undefined4 *)(iVar7 + 0x48)) {
          case 0:
            *(undefined1 *)(iVar11 + 0x2c) = 1;
            break;
          case 1:
            *(undefined1 *)(iVar11 + 0x2d) = 1;
            param_2[0xc] = param_2[0xc] | 8;
            break;
          case 2:
            iVar16 = *(int *)(iVar7 + 0x4c);
            *(undefined1 *)(iVar16 + iVar11 + 0x2e) = 1;
            *(undefined1 *)((int)param_2 + iVar16 + 0x34) = 1;
            param_2[0xc] = param_2[0xc] | 4;
            break;
          case 3:
            *(undefined1 *)(iVar11 + 0x36) = 1;
            param_2[0xc] = param_2[0xc] | 1;
            break;
          case 4:
            *(undefined1 *)(iVar11 + 0x37) = 1;
            break;
          case 5:
            *(undefined1 *)(iVar11 + 0x38) = 1;
            break;
          case 6:
            *(undefined1 *)(iVar11 + 0x39) = 1;
            break;
          case 7:
            *(undefined1 *)(iVar11 + 0x36) = 1;
            break;
          case 8:
            *(undefined1 *)(iVar11 + 0x3b) = 1;
            break;
          case 9:
            *(undefined1 *)(iVar11 + 0x3c) = 1;
            break;
          case 10:
            *(undefined1 *)(iVar11 + 0x3d) = 1;
            break;
          case 0xb:
            *(undefined1 *)(iVar11 + 0x3a) = 1;
            break;
          case 0xc:
            *(undefined1 *)(iVar11 + 0x40) = 1;
            break;
          case 0xd:
            *(undefined1 *)(iVar11 + 0x41) = 1;
            break;
          case 0xe:
            *(undefined1 *)(iVar11 + 0x37) = 1;
            param_2[0xc] = param_2[0xc] | 2;
            break;
          case 0xf:
            *(undefined1 *)(iVar11 + 0x3e) = 1;
            param_2[0xc] = param_2[0xc] | 0x40;
            break;
          case 0x10:
            *(undefined1 *)(iVar11 + 0x3f) = 1;
            param_2[0xc] = param_2[0xc] | 0x80;
          }
        }
        *(undefined1 *)(iVar7 + 0x3d) = 1;
        iVar17 = param_2[6];
        param_2[0x16] = param_2[0x16] + 1;
      }
      iVar7 = iVar4;
      if (((*(int *)(iVar5 + iVar17 + 0x58) == 2) &&
          (iVar16 = *(int *)(iVar5 + iVar17 + 0x5c) * 0x54 + param_2[8],
          *(int *)(iVar16 + 0x28) == 0x87c1)) && (*(char *)(iVar16 + 0x3d) == '\0')) {
        if ((*(char *)(iVar16 + 0x44) == '\0') || (*(int *)(iVar16 + 0x48) == 0x12)) {
          iVar5 = *(int *)(iVar16 + 0x24);
          if (iVar5 == 0x87bf) {
            local_148[iVar10] = iVar16;
            iVar10 = iVar10 + 1;
          }
          else if (iVar5 == 0x87c0) {
            local_c8[iVar15] = iVar16;
            iVar15 = iVar15 + 1;
          }
          else if (iVar5 == 0x87be) {
            local_1c8[iVar9] = iVar16;
            iVar9 = iVar9 + 1;
          }
        }
        else {
          iVar7 = iVar4 + 1;
          local_248[iVar4] = iVar16;
          switch(*(undefined4 *)(iVar16 + 0x48)) {
          case 0:
            *(undefined1 *)(iVar11 + 0x2c) = 1;
            break;
          case 1:
            *(undefined1 *)(iVar11 + 0x2d) = 1;
            param_2[0xc] = param_2[0xc] | 8;
            break;
          case 2:
            iVar5 = *(int *)(iVar16 + 0x4c);
            *(undefined1 *)(iVar5 + iVar11 + 0x2e) = 1;
            *(undefined1 *)((int)param_2 + iVar5 + 0x34) = 1;
            param_2[0xc] = param_2[0xc] | 4;
            break;
          case 3:
            *(undefined1 *)(iVar11 + 0x36) = 1;
            param_2[0xc] = param_2[0xc] | 1;
            break;
          case 4:
            *(undefined1 *)(iVar11 + 0x37) = 1;
            break;
          case 5:
            *(undefined1 *)(iVar11 + 0x38) = 1;
            break;
          case 6:
            *(undefined1 *)(iVar11 + 0x39) = 1;
            break;
          case 7:
            *(undefined1 *)(iVar11 + 0x36) = 1;
            break;
          case 8:
            *(undefined1 *)(iVar11 + 0x3b) = 1;
            break;
          case 9:
            *(undefined1 *)(iVar11 + 0x3c) = 1;
            break;
          case 10:
            *(undefined1 *)(iVar11 + 0x3d) = 1;
            break;
          case 0xb:
            *(undefined1 *)(iVar11 + 0x3a) = 1;
            break;
          case 0xc:
            *(undefined1 *)(iVar11 + 0x40) = 1;
            break;
          case 0xd:
            *(undefined1 *)(iVar11 + 0x41) = 1;
            break;
          case 0xe:
            *(undefined1 *)(iVar11 + 0x37) = 1;
            param_2[0xc] = param_2[0xc] | 2;
            break;
          case 0xf:
            *(undefined1 *)(iVar11 + 0x3e) = 1;
            param_2[0xc] = param_2[0xc] | 0x40;
            break;
          case 0x10:
            *(undefined1 *)(iVar11 + 0x3f) = 1;
            param_2[0xc] = param_2[0xc] | 0x80;
          }
        }
        *(undefined1 *)(iVar16 + 0x3d) = 1;
        param_2[0x16] = param_2[0x16] + 1;
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 < (uint)param_2[5]);
  }
  if (*(char *)(iVar11 + 0x2c) != '\0') {
    iVar7 = 0;
    iVar16 = 0x20;
    do {
      iVar5 = *(int *)((int)local_248 + iVar7);
      if (((iVar5 == 0) || (*(int *)(iVar5 + 0x48) != 0)) || (*(int *)(iVar5 + 0x4c) != 0)) {
        iVar5 = 0;
      }
      iVar16 = iVar16 + -1;
    } while ((iVar16 != 0) && (iVar7 = iVar7 + 4, iVar5 == 0));
    *(undefined4 *)(iVar5 + 4) = 0;
    *(undefined4 *)(iVar11 + 0x198) = 0;
    *(undefined1 *)(*(int *)(iVar11 + 0x24) + 0x10) = 1;
  }
  bVar1 = iVar10 == 0;
  uVar14 = 2;
  uVar13 = 0;
  DAT_001dba98 = 0xe;
  iVar7 = 0x50;
  puVar12 = &DAT_001dba44;
  do {
    if (!bVar1) {
      iVar10 = iVar10 + -1;
      puVar6 = (undefined4 *)((int (*)())FUN_0005e770)(local_148);
      uVar3 = *puVar12;
      bVar1 = iVar10 == 0;
      puVar6[1] = uVar14;
      puVar12 = puVar12 + 1;
      uVar14 = uVar14 + 1;
      *puVar6 = uVar3;
      iVar16 = iVar7 + *(int *)(iVar11 + 0x24);
      iVar7 = iVar7 + 0x28;
      *(undefined1 *)(iVar16 + 0x10) = 1;
      *(uint *)(iVar11 + 0x234) = 4 << (uVar13 & 0x3f) | *(uint *)(iVar11 + 0x234);
    }
    bVar2 = uVar13 != 7;
    uVar13 = uVar13 + 1;
  } while (bVar2);
  iVar7 = uVar14 * 0x28;
  uVar13 = 0;
  puVar12 = (undefined4 *)(uVar14 * 4 + 0x1dba3c);
  do {
    if (!bVar1) {
      iVar10 = iVar10 + -1;
      puVar6 = (undefined4 *)((int (*)())FUN_0005e770)(local_148);
      uVar3 = *puVar12;
      bVar1 = iVar10 == 0;
      puVar6[1] = uVar14;
      puVar12 = puVar12 + 1;
      uVar14 = uVar14 + 1;
      *puVar6 = uVar3;
      iVar16 = iVar7 + *(int *)(iVar11 + 0x24);
      iVar7 = iVar7 + 0x28;
      *(undefined1 *)(iVar16 + 0x10) = 1;
      *(uint *)(iVar11 + 0x234) = 0x400 << (uVar13 & 0x3f) | *(uint *)(iVar11 + 0x234);
    }
    bVar2 = uVar13 != 7;
    uVar13 = uVar13 + 1;
  } while (bVar2);
  uVar13 = uVar14;
  if (*(char *)(uVar14 * 0x28 + *(int *)(iVar11 + 0x24) + 0x10) != '\0') {
    uVar8 = *(uint *)(iVar11 + 0x234);
    uVar13 = uVar14 + 1;
    *(uint *)(iVar11 + 0x234) = uVar8 | 0x40000;
    if (*(char *)(uVar13 * 0x28 + *(int *)(iVar11 + 0x24) + 0x10) != '\0') {
      uVar13 = uVar14 + 2;
      *(uint *)(iVar11 + 0x234) = uVar8 | 0xc0000;
    }
  }
  if (!bVar1) {
    iVar10 = iVar10 + -1;
    puVar12 = (undefined4 *)((int (*)())FUN_0005e770)(local_148);
    iVar7 = uVar13 * 0x28;
    bVar1 = iVar10 == 0;
    uVar3 = *(undefined4 *)(uVar13 * 4 + 0x1dba3c);
    puVar12[1] = uVar13;
    uVar13 = uVar13 + 1;
    *puVar12 = uVar3;
    *(undefined1 *)(iVar7 + *(int *)(iVar11 + 0x24) + 0x10) = 1;
    *(uint *)(iVar11 + 0x234) = *(uint *)(iVar11 + 0x234) | 0x100000;
  }
  if (((iVar9 != 0) || (!bVar1)) || (iVar15 != 0)) {
    *(undefined1 *)(param_2 + 4) = 0;
    if (iVar9 != 0) {
      iVar16 = uVar13 * 0x28;
      iVar7 = 0;
      do {
        iVar5 = ((int (*)())FUN_0005e770)(local_1c8);
        if (*(uint *)(iVar11 + 0x28) <= uVar13) {
          uVar3 = (**(code **)(param_1 + 0x10))(*(uint *)(iVar11 + 0x28) + 0x10,0x28);
          (**(code **)(((unsigned char *)0x00001344) + param_1))
                    (uVar3,*(undefined4 *)(iVar11 + 0x24),*(int *)(iVar11 + 0x28) * 0x28);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar11 + 0x24));
          *(undefined4 *)(iVar11 + 0x24) = uVar3;
          *(int *)(iVar11 + 0x28) = *(int *)(iVar11 + 0x28) + 0x10;
        }
        *(uint *)(iVar5 + 4) = uVar13;
        *(undefined4 *)(iVar5 + 8) = 0;
        iVar7 = iVar7 + 1;
        uVar13 = uVar13 + 1;
        iVar5 = iVar16 + *(int *)(iVar11 + 0x24);
        iVar16 = iVar16 + 0x28;
        *(undefined1 *)(iVar5 + 0x10) = 1;
      } while (iVar9 != iVar7);
    }
    if (!bVar1) {
      iVar9 = uVar13 * 0x28;
      iVar7 = 0;
      do {
        iVar16 = ((int (*)())FUN_0005e770)(local_148);
        if (*(uint *)(iVar11 + 0x28) <= uVar13) {
          uVar3 = (**(code **)(param_1 + 0x10))(*(uint *)(iVar11 + 0x28) + 0x10,0x28);
          (**(code **)(((unsigned char *)0x00001344) + param_1))
                    (uVar3,*(undefined4 *)(iVar11 + 0x24),*(int *)(iVar11 + 0x28) * 0x28);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar11 + 0x24));
          *(undefined4 *)(iVar11 + 0x24) = uVar3;
          *(int *)(iVar11 + 0x28) = *(int *)(iVar11 + 0x28) + 0x10;
        }
        *(uint *)(iVar16 + 4) = uVar13;
        iVar7 = iVar7 + 1;
        uVar13 = uVar13 + 1;
        iVar16 = *(int *)(iVar11 + 0x24) + iVar9;
        iVar9 = iVar9 + 0x28;
        *(undefined1 *)(iVar16 + 0x10) = 1;
      } while (iVar10 != iVar7);
    }
    if (iVar15 != 0) {
      iVar9 = uVar13 * 0x28;
      iVar7 = 0;
      do {
        iVar10 = ((int (*)())FUN_0005e770)(local_c8);
        if (*(uint *)(iVar11 + 0x28) <= uVar13 + 3) {
          uVar3 = (**(code **)(param_1 + 0x10))(*(uint *)(iVar11 + 0x28) + 0x10,0x28);
          (**(code **)(((unsigned char *)0x00001344) + param_1))
                    (uVar3,*(undefined4 *)(iVar11 + 0x24),*(int *)(iVar11 + 0x28) * 0x28);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar11 + 0x24));
          *(undefined4 *)(iVar11 + 0x24) = uVar3;
          *(int *)(iVar11 + 0x28) = *(int *)(iVar11 + 0x28) + 0x10;
        }
        iVar5 = 0;
        iVar17 = 4;
        iVar16 = iVar9;
        do {
          iVar4 = uVar13 + iVar5;
          iVar5 = iVar5 + 1;
          *(int *)(iVar10 + 0x10) = iVar4;
          iVar10 = iVar10 + 4;
          iVar4 = iVar16 + *(int *)(iVar11 + 0x24);
          iVar16 = iVar16 + 0x28;
          *(undefined1 *)(iVar4 + 0x10) = 1;
          iVar17 = iVar17 + -1;
        } while (iVar17 != 0);
        iVar7 = iVar7 + 1;
        uVar13 = uVar13 + 4;
        iVar9 = iVar9 + 0xa0;
      } while (iVar7 != iVar15);
    }
  }
  *(uint *)(iVar11 + 0x2a4) = uVar13;
  return;
}

/* FUN_0005f540 @ 0x5f540 (688 bytes) */
int FUN_0005f540(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 auStack_2c [3];
  
  iVar11 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  if (*(char *)(param_2 + 4) != '\0') {
    iVar3 = (**(code **)(param_1 + 0xc))(*(int *)(iVar11 + 0x18) << 4);
    puVar4 = (undefined4 *)
             FUN_000774c0(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x18));
    puVar4[8] = 0;
    puVar4[9] = 0;
    puVar4[3] = 0x20;
    *puVar4 = 0x460;
    puVar4[1] = *(undefined4 *)(iVar11 + 0x1c);
    uVar7 = *(undefined4 *)(iVar11 + 0x18);
    puVar4[7] = &uStack_38;
    puVar4[10] = &uStack_34;
    puVar4[6] = iVar3;
    puVar4[0xb] = &uStack_30;
    puVar4[2] = uVar7;
    puVar4[0xc] = auStack_2c;
    iVar5 = FUN_0007c760(puVar4);
    FUN_0007a110(puVar4);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar11 + 0x1c));
    *(int *)(iVar11 + 0x1c) = iVar3;
    if (iVar5 == 0) {
      *(uint *)(iVar11 + 0x18) = uStack_38;
      param_2[0x15] = uStack_38;
      *(undefined4 *)(iVar11 + 8) = uStack_34;
      *(undefined4 *)(iVar11 + 0xc) = uStack_30;
      *(undefined4 *)(iVar11 + 0x2ac) = auStack_2c[0];
    }
    else {
      *(undefined4 *)(iVar11 + 0xc) = 0;
      if (uStack_38 != 0) {
        uVar9 = uStack_38;
        iVar3 = uStack_38 * 0x10 + iVar3;
        do {
          if ((((*(uint *)(iVar3 + -0xc) & 7) == 1) || ((*(uint *)(iVar3 + -8) & 7) == 1)) ||
             ((*(uint *)(iVar3 + -4) & 7) == 1)) {
            *(uint *)(iVar11 + 0xc) = uVar9 - 1;
          }
          uVar9 = uVar9 - 1;
        } while ((uVar9 != 0) && (iVar3 = iVar3 + -0x10, *(int *)(iVar11 + 0xc) == 0));
      }
    }
    puVar2 = *(uint **)(iVar11 + 0x1c);
    if (uStack_38 != 0) {
      uVar9 = 0;
      do {
        uVar1 = *puVar2;
        if ((uVar1 & 0x3f) == 4) {
          if ((((puVar2[1] & 7) == 0) && ((puVar2[2] & 7) == 0)) && ((puVar2[3] & 7) == 0)) {
            uVar6 = puVar2[1] >> 5 & 0xff;
            uVar10 = puVar2[2] >> 5 & 0xff;
            if (((uVar6 != uVar10) && (uVar8 = puVar2[3] >> 5 & 0xff, uVar6 != uVar8)) &&
               (uVar10 != uVar8)) {
              *puVar2 = uVar1 & 0xffffffc0 | 0x80;
            }
          }
        }
        else if ((((uVar1 & 0x3f) == 0xb) && ((puVar2[1] & 7) == 0)) &&
                (((puVar2[2] & 7) == 0 && ((puVar2[3] & 7) == 0)))) {
          uVar6 = puVar2[1] >> 5 & 0xff;
          uVar10 = puVar2[2] >> 5 & 0xff;
          if (((uVar6 != uVar10) && (uVar8 = puVar2[3] >> 5 & 0xff, uVar6 != uVar8)) &&
             (uVar10 != uVar8)) {
            *puVar2 = uVar1 & 0xffffffc0 | 0x81;
          }
        }
        uVar9 = uVar9 + 1;
        puVar2 = puVar2 + 4;
      } while (uVar9 < uStack_38);
    }
  }
  return;
}

/* FUN_0005f810 @ 0x5f810 (9624 bytes) */
int FUN_0005f810(param_1, param_2)
  int param_1;
  int *param_2;
{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 uVar7;
  int *piVar6;
  int iVar8;
  uint in_r5;
  int in_r6;
  uint in_r7;
  uint in_r8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  undefined4 uVar20;
  uint *puVar21;
  uint uVar22;
  uint uVar23;
  int iVar24;
  undefined4 auStack_d8 [2];
  int iStack_d0;
  int iStack_cc;
  int iStack_c8;
  int iStack_c4;
  int iStack_c0;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  
  puVar21 = *(uint **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  uVar23 = *puVar21;
  if ((param_2[6] == 0) || (param_2[5] == 0)) {
    uVar7 = 1;
LAB_00061d90:
    param_2[0x19] = 0;
    param_2[0xc] = 0;
    param_2[0x15] = 0;
    param_2[0x16] = 0;
    param_2[0x17] = 0;
    param_2[0x18] = 0;
  }
  else {
    *(undefined1 *)(param_2 + 4) = 1;
    ((int (*)())FUN_0005e7f0)(param_1,param_2);
    iVar8 = (**(code **)(param_1 + 0xc))(param_2[5] << 4);
    if (param_2[5] != 0) {
      in_r5 = 0;
      in_r6 = 0;
      do {
        iVar10 = param_2[6];
        iVar16 = in_r6 + iVar10;
        if (*(int *)(iVar16 + 4) == 1) {
          uVar5 = *(uint *)(iVar16 + 8);
          if (uVar5 < 0x879d) {
            if (uVar5 < 0x879b) {
              if (uVar5 < 0x6111) {
                if (uVar5 < 0x610f) {
                  if (uVar5 == 0x610e) {
                    *(undefined1 *)((int)param_2 + 0x79) = 1;
                  }
                }
                else {
                  *(undefined1 *)((int)param_2 + (uVar5 - 0x60a0)) = 1;
                }
              }
              else if (uVar5 == 0x879a) {
                *(undefined1 *)(param_2 + 0x1b) = 1;
              }
            }
            else {
              *(undefined1 *)((int)param_2 + (uVar5 - 0x872e)) = 1;
            }
          }
          else if (uVar5 < 0x87a5) {
            if (*(int *)(iVar16 + 0xc) != 0) {
              *(byte *)((int)param_2 + (uVar5 - 0x872c)) =
                   *(byte *)((int)param_2 + (uVar5 - 0x872c)) | 1;
            }
            if (*(int *)(iVar16 + 0x10) != 0) {
              *(byte *)((int)param_2 + *(int *)(iVar16 + 8) + -0x872c) =
                   *(byte *)((int)param_2 + *(int *)(iVar16 + 8) + -0x872c) | 2;
            }
            if (*(int *)(iVar16 + 0x14) != 0) {
              *(byte *)((int)param_2 + *(int *)(iVar16 + 8) + -0x872c) =
                   *(byte *)((int)param_2 + *(int *)(iVar16 + 8) + -0x872c) | 4;
            }
            if (*(int *)(iVar16 + 0x18) != 0) {
              *(byte *)((int)param_2 + *(int *)(iVar16 + 8) + -0x872c) =
                   *(byte *)((int)param_2 + *(int *)(iVar16 + 8) + -0x872c) | 8;
            }
          }
          else if (uVar5 == 0x87bd) {
            *(undefined1 *)((int)param_2 + 0x7a) = 1;
          }
        }
        iVar10 = in_r6 + iVar10;
        iVar16 = in_r5 * 0x10;
        in_r5 = in_r5 + 1;
        in_r6 = in_r6 + 0x74;
        in_r7 = *(uint *)(iVar10 + 0x18);
        iVar11 = iVar16 + iVar8;
        uVar14 = *(undefined4 *)(iVar10 + 0x10);
        in_r8 = *(uint *)(iVar10 + 0x14);
        *(undefined4 *)(iVar8 + iVar16) = *(undefined4 *)(iVar10 + 0xc);
        *(uint *)(iVar11 + 0xc) = in_r7;
        *(undefined4 *)(iVar11 + 4) = uVar14;
        *(uint *)(iVar11 + 8) = in_r8;
      } while (in_r5 < (uint)param_2[5]);
    }
    if ((*(char *)((int)param_2 + 0x7a) == '\0') ||
       (uVar7 = 1, (*(uint *)(param_1 + 0x44) & 0x1000) != 0)) {
      uVar7 = 0;
    }
    *(undefined1 *)(uVar23 + 0x42) = uVar7;
    *(undefined1 *)(uVar23 + 0x43) = *(undefined1 *)((int)param_2 + 0x79);
    if ((*(char *)((int)param_2 + 0x6f) != '\0') || (uVar7 = 0, *(char *)(param_2 + 0x1c) != '\0'))
    {
      uVar7 = 1;
    }
    *(undefined1 *)(uVar23 + 0x44) = uVar7;
    uVar5 = *(uint *)(param_1 + 0x44);
    if ((uVar5 & 0x80) == 0) {
      *(undefined1 *)((int)param_2 + 0x79) = 0;
      uVar5 = *(uint *)(param_1 + 0x44);
    }
    if ((uVar5 & 0x40) == 0) {
      *(undefined1 *)(param_2 + 0x1c) = 0;
      *(undefined1 *)((int)param_2 + 0x6f) = 0;
    }
    if ((*(char *)((int)param_2 + 0x7a) != '\0') && ((*(uint *)(param_1 + 0x44) & 0x800) != 0)) {
      in_r7 = (uint)(byte)((unsigned char *)0x000011d1)[param_1];
      in_r8 = in_r7 + (int)param_2;
      if (*(char *)(in_r8 + 0x71) != '\0') {
        uVar17 = param_2[5];
        uVar5 = 0;
        if (uVar17 != 0) {
          do {
            iVar10 = uVar5 * 0x74 + param_2[6];
            if ((*(int *)(iVar10 + 4) == 1) && (*(int *)(iVar10 + 8) == in_r7 + 0x879d)) {
              *(undefined4 *)(iVar10 + 0x18) = 0;
              *(undefined4 *)(iVar10 + 0xc) = 0;
              *(undefined4 *)(iVar10 + 0x10) = 0;
              *(undefined4 *)(iVar10 + 0x14) = 0;
              uVar17 = param_2[5];
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar17);
        }
      }
      *(undefined1 *)(in_r8 + 0x71) = 0xf;
    }
    if ((*(char *)(param_2 + 0x1b) != '\0') && ((*(uint *)(param_1 + 0x44) & 0x400) != 0)) {
      bVar1 = ((unsigned char *)0x000011d2)[param_1];
      uVar5 = (uint)bVar1;
      if ((*(char *)((int)param_2 + bVar1 + 0x71) != '\0') && (uVar17 = param_2[5], uVar17 != 0)) {
        in_r8 = 0;
        in_r7 = 0;
        iVar10 = 0;
        in_r6 = bVar1 + 0x879d;
        do {
          iVar16 = iVar10 + param_2[6];
          if ((*(int *)(iVar16 + 4) == 1) && (*(int *)(iVar16 + 8) == in_r6)) {
            *(undefined4 *)(iVar16 + 0x18) = 0;
            *(undefined4 *)(iVar16 + 0xc) = 0;
            *(undefined4 *)(iVar16 + 0x10) = 0;
            *(undefined4 *)(iVar16 + 0x14) = 0;
            uVar17 = param_2[5];
          }
          in_r8 = in_r8 + 1;
          iVar10 = iVar10 + 0x74;
        } while (in_r8 < uVar17);
        uVar5 = (uint)(byte)((unsigned char *)0x000011d2)[param_1];
      }
      *(undefined1 *)((int)param_2 + uVar5 + 0x71) = 0xf;
    }
    iVar10 = 1;
    *(undefined4 *)(uVar23 + 0x1e8) = 0;
    if (*(char *)((int)param_2 + 0x79) != '\0') {
      iVar10 = 2;
      *(undefined4 *)(uVar23 + 0x1fc) = 1;
    }
    uVar5 = param_2[0x1b];
    if ((((uVar5 & 0xffffff) != 0) || (*(char *)(param_2 + 0x1c) != '\0')) ||
       (*(char *)((int)param_2 + 0x7a) != '\0')) {
      *(int *)(uVar23 + 0x1ec) = iVar10;
      iVar10 = iVar10 + 1;
      uVar5 = param_2[0x1b];
    }
    if ((((uVar5 & 0xffff) != 0) || (*(char *)(param_2 + 0x1c) != '\0')) ||
       (*(char *)((int)param_2 + 0x7a) != '\0')) {
      *(int *)(uVar23 + 0x1f0) = iVar10;
      iVar10 = iVar10 + 1;
    }
    if ((*(char *)((int)param_2 + 0x6f) != '\0') || (*(char *)(param_2 + 0x1c) != '\0')) {
      iVar16 = iVar10 + 1;
      *(int *)(uVar23 + 500) = iVar10;
      iVar10 = iVar10 + 2;
      *(int *)(uVar23 + 0x1f8) = iVar16;
    }
    iVar16 = 8;
    piVar6 = param_2;
    uVar5 = uVar23;
    do {
      if (*(char *)((int)piVar6 + 0x71) != '\0') {
        *(int *)(uVar5 + 0x200) = iVar10;
        iVar10 = iVar10 + 1;
      }
      piVar6 = (int *)((int)piVar6 + 1);
      uVar5 = uVar5 + 4;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
    *(undefined4 *)(uVar23 + 0x22c) = 0;
    *(undefined4 *)(uVar23 + 0x224) = 0;
    if (param_2[5] != 0) {
      uVar5 = 0;
      iVar10 = 0;
      do {
        iVar16 = param_2[6];
        if (*(int *)(iVar10 + iVar16 + 0x20) == 2) {
          iVar18 = param_2[8];
          iVar11 = *(int *)(iVar10 + iVar16 + 0x24) * 0x54;
          in_r6 = iVar11 + iVar18;
          if ((*(int *)(in_r6 + 0x28) == 0x87c2) && (*(char *)(in_r6 + 0x3d) == '\0')) {
            if (*(int *)(in_r6 + 0x30) == 0) {
              if (*(uint *)(in_r6 + 0x34) < 2) {
                in_r5 = uVar23;
                FUN_00055da0(param_1,param_2,uVar23,in_r6);
                iVar16 = param_2[6];
                goto LAB_0005fdf0;
              }
            }
            else {
              iVar11 = FUN_00054da0(param_2 + 7,*(int *)(in_r6 + 0x30));
              iVar18 = param_2[8];
              iVar11 = iVar11 * 0x54;
            }
            if (*(int *)(iVar18 + iVar11 + 0x34) != 0) {
              uVar17 = 0;
              iVar16 = iVar11;
              do {
                in_r6 = iVar16 + iVar18;
                uVar17 = uVar17 + 1;
                iVar16 = iVar16 + 0x54;
                in_r5 = uVar23;
                FUN_00055da0(param_1,param_2,uVar23,in_r6);
                iVar18 = param_2[8];
              } while (uVar17 < *(uint *)(iVar18 + iVar11 + 0x34));
            }
            iVar16 = param_2[6];
          }
        }
LAB_0005fdf0:
        if (*(int *)(iVar10 + iVar16 + 0x3c) == 2) {
          iVar19 = param_2[8];
          iVar11 = *(int *)(iVar10 + iVar16 + 0x40) * 0x54;
          iVar18 = iVar11 + iVar19;
          if ((*(int *)(iVar18 + 0x28) == 0x87c2) && (*(char *)(iVar18 + 0x3d) == '\0')) {
            if (*(int *)(iVar18 + 0x30) == 0) {
              if (1 < *(uint *)(iVar18 + 0x34)) goto LAB_00060230;
              param_2[0x17] = param_2[0x17] + 1;
              if (*(char *)(iVar18 + 0x44) == '\0') {
                *(int *)(uVar23 + 0x224) = *(int *)(uVar23 + 0x224) + 1;
              }
              else {
                *(int *)(uVar23 + 0x22c) = *(int *)(uVar23 + 0x22c) + 1;
              }
              iVar16 = *(int *)(iVar18 + 0x24);
              *(undefined1 *)(iVar18 + 0x3d) = 1;
              if (iVar16 == 0x87bf) {
                in_r8 = 0;
                uVar17 = 0;
                iVar16 = 0;
                bVar2 = true;
                *(int *)(uVar23 + 0x5c) = *(int *)(uVar23 + 0x5c) + 1;
                while (uVar17 < *(uint *)(uVar23 + 0x58)) {
                  if (!bVar2) goto LAB_0005ffe8;
                  if (*(char *)(iVar16 + *(int *)(uVar23 + 0x54) + 0x10) == '\0') {
                    in_r8 = 1;
                    bVar2 = false;
                  }
                  else {
                    uVar17 = uVar17 + 1;
                    iVar16 = iVar16 + 0x28;
                  }
                }
                if (bVar2) {
                  *(char *)(param_2 + 4) = (char)in_r8;
                  iVar16 = *(int *)(uVar23 + 0x58);
                  uVar14 = (**(code **)(param_1 + 0x10))(iVar16 + 0x10,0x28);
                  in_r5 = *(int *)(uVar23 + 0x58) * 0x28;
                  (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar14,*(undefined4 *)(uVar23 + 0x54));
                  (**(code **)(param_1 + 0x18))(*(undefined4 *)(uVar23 + 0x54));
                  *(undefined4 *)(uVar23 + 0x54) = uVar14;
                  *(int *)(uVar23 + 0x58) = *(int *)(uVar23 + 0x58) + 0x10;
LAB_00060078:
                  *(int *)(iVar18 + 4) = iVar16;
                  *(undefined1 *)(iVar16 * 0x28 + *(int *)(uVar23 + 0x54) + 0x10) = 1;
                  iVar16 = param_2[6];
                  goto LAB_000608e0;
                }
LAB_0005ffe8:
                *(uint *)(iVar18 + 4) = uVar17;
LAB_0005ffec:
                *(undefined1 *)(uVar17 * 0x28 + *(int *)(uVar23 + 0x54) + 0x10) = 1;
                iVar16 = param_2[6];
                goto LAB_000608e0;
              }
              if (iVar16 == 0x87c0) {
                uVar17 = 0;
                iVar16 = 0;
                bVar2 = true;
                *(int *)(uVar23 + 0x5c) = *(int *)(uVar23 + 0x5c) + 4;
                while (uVar17 < *(int *)(uVar23 + 0x58) - 3U) {
                  if (!bVar2) goto LAB_000600f4;
                  if (*(char *)(iVar16 + *(int *)(uVar23 + 0x54) + 0x10) == '\0') {
                    bVar2 = false;
                  }
                  else {
                    uVar17 = uVar17 + 1;
                    iVar16 = iVar16 + 0x28;
                  }
                }
                if (!bVar2) {
LAB_000600f4:
                  iVar16 = uVar17 * 0x28;
                  iVar11 = iVar16 + *(int *)(uVar23 + 0x54);
                  if (((*(char *)(iVar11 + 0x38) == '\0') && (*(char *)(iVar11 + 0x60) == '\0')) &&
                     (*(char *)(iVar11 + 0x88) == '\0')) {
                    in_r8 = 0;
                    iVar11 = 4;
                    in_r7 = 1;
                    do {
                      iVar19 = uVar17 + in_r8;
                      in_r8 = in_r8 + 1;
                      *(int *)(iVar18 + 0x10) = iVar19;
                      iVar18 = iVar18 + 4;
                      iVar19 = iVar16 + *(int *)(uVar23 + 0x54);
                      iVar16 = iVar16 + 0x28;
                      *(undefined1 *)(iVar19 + 0x10) = 1;
                      iVar11 = iVar11 + -1;
                    } while (iVar11 != 0);
                    goto LAB_000608d4;
                  }
                }
                *(undefined1 *)(param_2 + 4) = 0;
                iVar19 = *(int *)(uVar23 + 0x58);
                uVar14 = (**(code **)(param_1 + 0x10))(iVar19 + 0x10,0x28);
                in_r5 = *(int *)(uVar23 + 0x58) * 0x28;
                (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar14,*(undefined4 *)(uVar23 + 0x54));
                (**(code **)(param_1 + 0x18))(*(undefined4 *)(uVar23 + 0x54));
                *(undefined4 *)(uVar23 + 0x54) = uVar14;
                iVar16 = iVar19 * 0x28;
                iVar12 = 4;
                iVar11 = 0;
                in_r8 = 1;
                *(int *)(uVar23 + 0x58) = *(int *)(uVar23 + 0x58) + 0x10;
                do {
                  iVar3 = iVar11 + iVar19;
                  iVar11 = iVar11 + 1;
                  *(int *)(iVar18 + 0x10) = iVar3;
                  iVar18 = iVar18 + 4;
                  iVar3 = *(int *)(uVar23 + 0x54) + iVar16;
                  iVar16 = iVar16 + 0x28;
                  *(undefined1 *)(iVar3 + 0x10) = 1;
                  iVar12 = iVar12 + -1;
                } while (iVar12 != 0);
              }
              else if (iVar16 == 0x87be) {
                uVar14 = 0;
                uVar17 = 0;
                iVar16 = 0;
                bVar2 = true;
                *(int *)(uVar23 + 0x5c) = *(int *)(uVar23 + 0x5c) + 1;
                while (uVar17 < *(uint *)(uVar23 + 0x58)) {
                  if (!bVar2) goto LAB_0005ff00;
                  if (*(char *)(iVar16 + *(int *)(uVar23 + 0x54) + 0x10) == '\0') {
                    uVar14 = 1;
                    bVar2 = false;
                  }
                  else {
                    uVar17 = uVar17 + 1;
                    iVar16 = iVar16 + 0x28;
                  }
                }
                if (bVar2) {
                  *(char *)(param_2 + 4) = (char)uVar14;
                  iVar16 = *(int *)(uVar23 + 0x58);
                  uVar15 = (**(code **)(param_1 + 0x10))(iVar16 + 0x10,0x28);
                  in_r5 = *(int *)(uVar23 + 0x58) * 0x28;
                  (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar15,*(undefined4 *)(uVar23 + 0x54));
                  (**(code **)(param_1 + 0x18))(*(undefined4 *)(uVar23 + 0x54));
                  *(undefined4 *)(uVar23 + 0x54) = uVar15;
                  *(int *)(uVar23 + 0x58) = *(int *)(uVar23 + 0x58) + 0x10;
                  *(undefined4 *)(iVar18 + 8) = uVar14;
                  goto LAB_00060078;
                }
LAB_0005ff00:
                *(uint *)(iVar18 + 4) = uVar17;
                *(undefined4 *)(iVar18 + 8) = 0;
                goto LAB_0005ffec;
              }
            }
            else {
              iVar11 = FUN_00054da0(param_2 + 7,*(int *)(iVar18 + 0x30));
              iVar19 = param_2[8];
              iVar11 = iVar11 * 0x54;
LAB_00060230:
              if (*(int *)(iVar11 + iVar19 + 0x34) != 0) {
                uVar17 = 0;
                iVar16 = iVar11;
                do {
                  iVar18 = iVar19 + iVar16;
                  if (*(int *)(iVar18 + 0x28) == 0x87c2) {
                    param_2[0x17] = param_2[0x17] + 1;
                    if (*(char *)(iVar18 + 0x44) == '\0') {
                      *(int *)(uVar23 + 0x224) = *(int *)(uVar23 + 0x224) + 1;
                    }
                    else {
                      *(int *)(uVar23 + 0x22c) = *(int *)(uVar23 + 0x22c) + 1;
                    }
                    iVar19 = *(int *)(iVar18 + 0x24);
                    *(undefined1 *)(iVar18 + 0x3d) = 1;
                    if (iVar19 != 0x87bf) {
                      if (iVar19 == 0x87c0) {
                        uVar22 = 0;
                        iVar19 = 0;
                        bVar2 = true;
                        *(int *)(uVar23 + 0x5c) = *(int *)(uVar23 + 0x5c) + 4;
                        while (uVar22 < *(int *)(uVar23 + 0x58) - 3U) {
                          if (!bVar2) goto LAB_000603e0;
                          if (*(char *)(iVar19 + *(int *)(uVar23 + 0x54) + 0x10) == '\0') {
                            bVar2 = false;
                          }
                          else {
                            uVar22 = uVar22 + 1;
                            iVar19 = iVar19 + 0x28;
                          }
                        }
                        if (!bVar2) {
LAB_000603e0:
                          uVar9 = uVar22 * 0x28;
                          iVar19 = uVar9 + *(int *)(uVar23 + 0x54);
                          in_r8 = uVar9;
                          if (((*(char *)(iVar19 + 0x38) == '\0') &&
                              (*(char *)(iVar19 + 0x60) == '\0')) &&
                             (*(char *)(iVar19 + 0x88) == '\0')) {
                            in_r8 = 0;
                            iVar19 = 4;
                            in_r7 = 1;
                            do {
                              iVar12 = uVar22 + in_r8;
                              in_r8 = in_r8 + 1;
                              *(int *)(iVar18 + 0x10) = iVar12;
                              iVar18 = iVar18 + 4;
                              iVar12 = *(int *)(uVar23 + 0x54) + uVar9;
                              uVar9 = uVar9 + 0x28;
                              *(undefined1 *)(iVar12 + 0x10) = 1;
                              iVar19 = iVar19 + -1;
                            } while (iVar19 != 0);
                            goto LAB_000608b8;
                          }
                        }
                        *(undefined1 *)(param_2 + 4) = 0;
                        iVar3 = *(int *)(uVar23 + 0x58);
                        uVar14 = (**(code **)(param_1 + 0x10))
                                           (iVar3 + 0x10,0x28,in_r5,in_r6,in_r7,in_r8,0);
                        in_r5 = *(int *)(uVar23 + 0x58) * 0x28;
                        (**(code **)(((unsigned char *)0x00001344) + param_1))
                                  (uVar14,*(undefined4 *)(uVar23 + 0x54));
                        (**(code **)(param_1 + 0x18))(*(undefined4 *)(uVar23 + 0x54));
                        *(undefined4 *)(uVar23 + 0x54) = uVar14;
                        iVar12 = iVar3 * 0x28;
                        iVar24 = 4;
                        iVar19 = 0;
                        in_r8 = 1;
                        *(int *)(uVar23 + 0x58) = *(int *)(uVar23 + 0x58) + 0x10;
                        do {
                          iVar4 = iVar19 + iVar3;
                          iVar19 = iVar19 + 1;
                          *(int *)(iVar18 + 0x10) = iVar4;
                          iVar18 = iVar18 + 4;
                          iVar4 = *(int *)(uVar23 + 0x54) + iVar12;
                          iVar12 = iVar12 + 0x28;
                          *(undefined1 *)(iVar4 + 0x10) = 1;
                          iVar24 = iVar24 + -1;
                        } while (iVar24 != 0);
                      }
                      else if (iVar19 == 0x87be) {
                        uVar14 = 0;
                        uVar22 = 0;
                        iVar19 = 0;
                        bVar2 = true;
                        *(int *)(uVar23 + 0x5c) = *(int *)(uVar23 + 0x5c) + 1;
                        while (uVar22 < *(uint *)(uVar23 + 0x58)) {
                          if (!bVar2) goto LAB_00060590;
                          if (*(char *)(iVar19 + *(int *)(uVar23 + 0x54) + 0x10) == '\0') {
                            uVar14 = 1;
                            bVar2 = false;
                          }
                          else {
                            uVar22 = uVar22 + 1;
                            iVar19 = iVar19 + 0x28;
                          }
                        }
LAB_0006058c:
                        if (!bVar2) {
LAB_00060590:
                          *(uint *)(iVar18 + 4) = uVar22;
                          *(undefined4 *)(iVar18 + 8) = 0;
                          *(undefined1 *)(uVar22 * 0x28 + *(int *)(uVar23 + 0x54) + 0x10) = 1;
                          iVar19 = param_2[8];
                          goto LAB_000608bc;
                        }
                        *(char *)(param_2 + 4) = (char)uVar14;
                        iVar19 = *(int *)(uVar23 + 0x58);
                        uVar15 = (**(code **)(param_1 + 0x10))(iVar19 + 0x10,0x28);
                        in_r5 = *(int *)(uVar23 + 0x58) * 0x28;
                        (**(code **)(((unsigned char *)0x00001344) + param_1))
                                  (uVar15,*(undefined4 *)(uVar23 + 0x54));
                        (**(code **)(param_1 + 0x18))(*(undefined4 *)(uVar23 + 0x54));
                        *(undefined4 *)(uVar23 + 0x54) = uVar15;
                        *(int *)(uVar23 + 0x58) = *(int *)(uVar23 + 0x58) + 0x10;
                        *(undefined4 *)(iVar18 + 8) = uVar14;
                        goto LAB_00060720;
                      }
                      goto LAB_000608b8;
                    }
                    in_r8 = 0;
                    uVar22 = 0;
                    iVar19 = 0;
                    bVar2 = true;
                    *(int *)(uVar23 + 0x5c) = *(int *)(uVar23 + 0x5c) + 1;
                    while (uVar22 < *(uint *)(uVar23 + 0x58)) {
                      if (!bVar2) goto LAB_00060690;
                      if (*(char *)(iVar19 + *(int *)(uVar23 + 0x54) + 0x10) == '\0') {
                        in_r8 = 1;
                        bVar2 = false;
                      }
                      else {
                        uVar22 = uVar22 + 1;
                        iVar19 = iVar19 + 0x28;
                      }
                    }
LAB_0006068c:
                    if (bVar2) {
                      *(char *)(param_2 + 4) = (char)in_r8;
                      iVar19 = *(int *)(uVar23 + 0x58);
                      uVar14 = (**(code **)(param_1 + 0x10))(iVar19 + 0x10,0x28);
                      in_r5 = *(int *)(uVar23 + 0x58) * 0x28;
                      (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar14,*(undefined4 *)(uVar23 + 0x54));
                      (**(code **)(param_1 + 0x18))(*(undefined4 *)(uVar23 + 0x54));
                      *(undefined4 *)(uVar23 + 0x54) = uVar14;
                      *(int *)(uVar23 + 0x58) = *(int *)(uVar23 + 0x58) + 0x10;
LAB_00060720:
                      *(int *)(iVar18 + 4) = iVar19;
                      *(undefined1 *)(iVar19 * 0x28 + *(int *)(uVar23 + 0x54) + 0x10) = 1;
                      iVar19 = param_2[8];
                    }
                    else {
LAB_00060690:
                      *(uint *)(iVar18 + 4) = uVar22;
                      *(undefined1 *)(uVar22 * 0x28 + *(int *)(uVar23 + 0x54) + 0x10) = 1;
                      iVar19 = param_2[8];
                    }
                  }
                  else if (*(int *)(iVar18 + 0x28) == 0x87c3) {
                    param_2[0x18] = param_2[0x18] + 1;
                    *(undefined1 *)(iVar18 + 0x3d) = 1;
                    iVar19 = *(int *)(iVar18 + 0x24);
                    if (iVar19 == 0x87bf) {
                      in_r8 = 0;
                      uVar22 = 0;
                      iVar19 = 0;
                      bVar2 = true;
                      *(int *)(uVar23 + 0x5c) = *(int *)(uVar23 + 0x5c) + 1;
                      while (uVar22 < *(uint *)(uVar23 + 0x58)) {
                        if (!bVar2) goto LAB_00060690;
                        if (*(char *)(iVar19 + *(int *)(uVar23 + 0x54) + 0x10) == '\0') {
                          in_r8 = 1;
                          bVar2 = false;
                        }
                        else {
                          uVar22 = uVar22 + 1;
                          iVar19 = iVar19 + 0x28;
                        }
                      }
                      goto LAB_0006068c;
                    }
                    if (iVar19 == 0x87c0) {
                      uVar22 = 0;
                      iVar19 = 0;
                      bVar2 = true;
                      *(int *)(uVar23 + 0x5c) = *(int *)(uVar23 + 0x5c) + 4;
                      while (uVar22 < *(int *)(uVar23 + 0x58) - 3U) {
                        if (!bVar2) goto LAB_0006079c;
                        if (*(char *)(iVar19 + *(int *)(uVar23 + 0x54) + 0x10) == '\0') {
                          bVar2 = false;
                        }
                        else {
                          uVar22 = uVar22 + 1;
                          iVar19 = iVar19 + 0x28;
                        }
                      }
                      if (!bVar2) {
LAB_0006079c:
                        uVar9 = uVar22 * 0x28;
                        iVar19 = uVar9 + *(int *)(uVar23 + 0x54);
                        in_r8 = uVar9;
                        if (((*(char *)(iVar19 + 0x38) == '\0') &&
                            (*(char *)(iVar19 + 0x60) == '\0')) &&
                           (*(char *)(iVar19 + 0x88) == '\0')) {
                          in_r8 = 0;
                          iVar19 = 4;
                          in_r7 = 1;
                          do {
                            iVar12 = in_r8 + uVar22;
                            in_r8 = in_r8 + 1;
                            *(int *)(iVar18 + 0x10) = iVar12;
                            iVar18 = iVar18 + 4;
                            iVar12 = *(int *)(uVar23 + 0x54) + uVar9;
                            uVar9 = uVar9 + 0x28;
                            *(undefined1 *)(iVar12 + 0x10) = 1;
                            iVar19 = iVar19 + -1;
                          } while (iVar19 != 0);
                          goto LAB_000608b8;
                        }
                      }
                      *(undefined1 *)(param_2 + 4) = 0;
                      iVar3 = *(int *)(uVar23 + 0x58);
                      uVar14 = (**(code **)(param_1 + 0x10))
                                         (iVar3 + 0x10,0x28,in_r5,in_r6,in_r7,in_r8,0);
                      in_r5 = *(int *)(uVar23 + 0x58) * 0x28;
                      (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar14,*(undefined4 *)(uVar23 + 0x54));
                      (**(code **)(param_1 + 0x18))(*(undefined4 *)(uVar23 + 0x54));
                      *(undefined4 *)(uVar23 + 0x54) = uVar14;
                      iVar12 = iVar3 * 0x28;
                      iVar24 = 4;
                      iVar19 = 0;
                      in_r8 = 1;
                      *(int *)(uVar23 + 0x58) = *(int *)(uVar23 + 0x58) + 0x10;
                      do {
                        iVar4 = iVar19 + iVar3;
                        iVar19 = iVar19 + 1;
                        *(int *)(iVar18 + 0x10) = iVar4;
                        iVar18 = iVar18 + 4;
                        iVar4 = *(int *)(uVar23 + 0x54) + iVar12;
                        iVar12 = iVar12 + 0x28;
                        *(undefined1 *)(iVar4 + 0x10) = 1;
                        iVar24 = iVar24 + -1;
                      } while (iVar24 != 0);
                    }
                    else if (iVar19 == 0x87be) {
                      uVar14 = 0;
                      uVar22 = 0;
                      iVar19 = 0;
                      bVar2 = true;
                      *(int *)(uVar23 + 0x5c) = *(int *)(uVar23 + 0x5c) + 1;
                      while (uVar22 < *(uint *)(uVar23 + 0x58)) {
                        if (!bVar2) goto LAB_00060590;
                        if (*(char *)(iVar19 + *(int *)(uVar23 + 0x54) + 0x10) == '\0') {
                          uVar14 = 1;
                          bVar2 = false;
                        }
                        else {
                          uVar22 = uVar22 + 1;
                          iVar19 = iVar19 + 0x28;
                        }
                      }
                      goto LAB_0006058c;
                    }
LAB_000608b8:
                    iVar19 = param_2[8];
                  }
LAB_000608bc:
                  uVar17 = uVar17 + 1;
                  iVar16 = iVar16 + 0x54;
                } while (uVar17 < *(uint *)(iVar11 + iVar19 + 0x34));
              }
            }
LAB_000608d4:
            iVar16 = param_2[6];
          }
        }
LAB_000608e0:
        if (*(int *)(iVar10 + iVar16 + 0x58) == 2) {
          iVar18 = param_2[8];
          iVar16 = *(int *)(iVar10 + iVar16 + 0x5c) * 0x54;
          iVar11 = iVar16 + iVar18;
          if ((*(int *)(iVar11 + 0x28) == 0x87c2) && (*(char *)(iVar11 + 0x3d) == '\0')) {
            if (*(int *)(iVar11 + 0x30) == 0) {
              if (*(uint *)(iVar11 + 0x34) < 2) {
                param_2[0x17] = param_2[0x17] + 1;
                if (*(char *)(iVar11 + 0x44) == '\0') {
                  *(int *)(uVar23 + 0x224) = *(int *)(uVar23 + 0x224) + 1;
                }
                else {
                  *(int *)(uVar23 + 0x22c) = *(int *)(uVar23 + 0x22c) + 1;
                }
                iVar16 = *(int *)(iVar11 + 0x24);
                *(undefined1 *)(iVar11 + 0x3d) = 1;
                if (iVar16 == 0x87bf) {
                  in_r8 = 0;
                  uVar17 = 0;
                  iVar16 = 0;
                  bVar2 = true;
                  *(int *)(uVar23 + 0x5c) = *(int *)(uVar23 + 0x5c) + 1;
                  while (uVar17 < *(uint *)(uVar23 + 0x58)) {
                    if (!bVar2) goto LAB_00060ad8;
                    if (*(char *)(iVar16 + *(int *)(uVar23 + 0x54) + 0x10) == '\0') {
                      in_r8 = 1;
                      bVar2 = false;
                    }
                    else {
                      uVar17 = uVar17 + 1;
                      iVar16 = iVar16 + 0x28;
                    }
                  }
                  if (bVar2) {
                    *(char *)(param_2 + 4) = (char)in_r8;
                    iVar16 = *(int *)(uVar23 + 0x58);
                    uVar14 = (**(code **)(param_1 + 0x10))(iVar16 + 0x10,0x28);
                    in_r5 = *(int *)(uVar23 + 0x58) * 0x28;
                    (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar14,*(undefined4 *)(uVar23 + 0x54));
                    (**(code **)(param_1 + 0x18))(*(undefined4 *)(uVar23 + 0x54));
                    *(undefined4 *)(uVar23 + 0x54) = uVar14;
                    *(int *)(uVar23 + 0x58) = *(int *)(uVar23 + 0x58) + 0x10;
LAB_00060b64:
                    *(int *)(iVar11 + 4) = iVar16;
                    *(undefined1 *)(iVar16 * 0x28 + *(int *)(uVar23 + 0x54) + 0x10) = 1;
                  }
                  else {
LAB_00060ad8:
                    *(uint *)(iVar11 + 4) = uVar17;
LAB_00060adc:
                    *(undefined1 *)(uVar17 * 0x28 + *(int *)(uVar23 + 0x54) + 0x10) = 1;
                  }
                }
                else if (iVar16 == 0x87c0) {
                  uVar17 = 0;
                  iVar16 = 0;
                  bVar2 = true;
                  *(int *)(uVar23 + 0x5c) = *(int *)(uVar23 + 0x5c) + 4;
                  while (uVar17 < *(int *)(uVar23 + 0x58) - 3U) {
                    if (!bVar2) goto LAB_00060bdc;
                    if (*(char *)(iVar16 + *(int *)(uVar23 + 0x54) + 0x10) == '\0') {
                      bVar2 = false;
                    }
                    else {
                      uVar17 = uVar17 + 1;
                      iVar16 = iVar16 + 0x28;
                    }
                  }
                  if (!bVar2) {
LAB_00060bdc:
                    iVar16 = uVar17 * 0x28;
                    iVar18 = iVar16 + *(int *)(uVar23 + 0x54);
                    if (((*(char *)(iVar18 + 0x38) == '\0') && (*(char *)(iVar18 + 0x60) == '\0'))
                       && (*(char *)(iVar18 + 0x88) == '\0')) {
                      in_r8 = 0;
                      iVar18 = 4;
                      in_r7 = 1;
                      do {
                        iVar19 = in_r8 + uVar17;
                        in_r8 = in_r8 + 1;
                        *(int *)(iVar11 + 0x10) = iVar19;
                        iVar11 = iVar11 + 4;
                        iVar19 = iVar16 + *(int *)(uVar23 + 0x54);
                        iVar16 = iVar16 + 0x28;
                        *(undefined1 *)(iVar19 + 0x10) = 1;
                        iVar18 = iVar18 + -1;
                      } while (iVar18 != 0);
                      goto LAB_000613b0;
                    }
                  }
                  *(undefined1 *)(param_2 + 4) = 0;
                  iVar19 = *(int *)(uVar23 + 0x58);
                  uVar14 = (**(code **)(param_1 + 0x10))(iVar19 + 0x10,0x28);
                  in_r5 = *(int *)(uVar23 + 0x58) * 0x28;
                  (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar14,*(undefined4 *)(uVar23 + 0x54));
                  (**(code **)(param_1 + 0x18))(*(undefined4 *)(uVar23 + 0x54));
                  *(undefined4 *)(uVar23 + 0x54) = uVar14;
                  iVar18 = iVar19 * 0x28;
                  iVar12 = 4;
                  iVar16 = 0;
                  in_r8 = 1;
                  *(int *)(uVar23 + 0x58) = *(int *)(uVar23 + 0x58) + 0x10;
                  do {
                    iVar3 = iVar16 + iVar19;
                    iVar16 = iVar16 + 1;
                    *(int *)(iVar11 + 0x10) = iVar3;
                    iVar11 = iVar11 + 4;
                    iVar3 = iVar18 + *(int *)(uVar23 + 0x54);
                    iVar18 = iVar18 + 0x28;
                    *(undefined1 *)(iVar3 + 0x10) = 1;
                    iVar12 = iVar12 + -1;
                  } while (iVar12 != 0);
                }
                else if (iVar16 == 0x87be) {
                  uVar14 = 0;
                  uVar17 = 0;
                  iVar16 = 0;
                  bVar2 = true;
                  *(int *)(uVar23 + 0x5c) = *(int *)(uVar23 + 0x5c) + 1;
                  while (uVar17 < *(uint *)(uVar23 + 0x58)) {
                    if (!bVar2) goto LAB_000609f0;
                    if (*(char *)(iVar16 + *(int *)(uVar23 + 0x54) + 0x10) == '\0') {
                      uVar14 = 1;
                      bVar2 = false;
                    }
                    else {
                      uVar17 = uVar17 + 1;
                      iVar16 = iVar16 + 0x28;
                    }
                  }
                  if (bVar2) {
                    *(char *)(param_2 + 4) = (char)uVar14;
                    iVar16 = *(int *)(uVar23 + 0x58);
                    uVar15 = (**(code **)(param_1 + 0x10))(iVar16 + 0x10,0x28);
                    in_r5 = *(int *)(uVar23 + 0x58) * 0x28;
                    (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar15,*(undefined4 *)(uVar23 + 0x54));
                    (**(code **)(param_1 + 0x18))(*(undefined4 *)(uVar23 + 0x54));
                    *(undefined4 *)(uVar23 + 0x54) = uVar15;
                    *(int *)(uVar23 + 0x58) = *(int *)(uVar23 + 0x58) + 0x10;
                    *(undefined4 *)(iVar11 + 8) = uVar14;
                    goto LAB_00060b64;
                  }
LAB_000609f0:
                  *(uint *)(iVar11 + 4) = uVar17;
                  *(undefined4 *)(iVar11 + 8) = 0;
                  goto LAB_00060adc;
                }
                goto LAB_000613b0;
              }
            }
            else {
              iVar16 = FUN_00054da0(param_2 + 7,*(int *)(iVar11 + 0x30));
              iVar18 = param_2[8];
              iVar16 = iVar16 * 0x54;
            }
            if (*(int *)(iVar18 + iVar16 + 0x34) != 0) {
              uVar17 = 0;
              iVar11 = iVar16;
              do {
                iVar19 = iVar18 + iVar11;
                if (*(int *)(iVar19 + 0x28) == 0x87c2) {
                  param_2[0x17] = param_2[0x17] + 1;
                  if (*(char *)(iVar19 + 0x44) == '\0') {
                    *(int *)(uVar23 + 0x224) = *(int *)(uVar23 + 0x224) + 1;
                  }
                  else {
                    *(int *)(uVar23 + 0x22c) = *(int *)(uVar23 + 0x22c) + 1;
                  }
                  iVar18 = *(int *)(iVar19 + 0x24);
                  *(undefined1 *)(iVar19 + 0x3d) = 1;
                  if (iVar18 != 0x87bf) {
                    if (iVar18 == 0x87c0) {
                      uVar22 = 0;
                      iVar18 = 0;
                      bVar2 = true;
                      *(int *)(uVar23 + 0x5c) = *(int *)(uVar23 + 0x5c) + 4;
                      while (uVar22 < *(int *)(uVar23 + 0x58) - 3U) {
                        if (!bVar2) goto LAB_00060ebc;
                        if (*(char *)(iVar18 + *(int *)(uVar23 + 0x54) + 0x10) == '\0') {
                          bVar2 = false;
                        }
                        else {
                          uVar22 = uVar22 + 1;
                          iVar18 = iVar18 + 0x28;
                        }
                      }
                      if (!bVar2) {
LAB_00060ebc:
                        uVar9 = uVar22 * 0x28;
                        iVar18 = uVar9 + *(int *)(uVar23 + 0x54);
                        in_r8 = uVar9;
                        if (((*(char *)(iVar18 + 0x38) == '\0') &&
                            (*(char *)(iVar18 + 0x60) == '\0')) &&
                           (*(char *)(iVar18 + 0x88) == '\0')) {
                          in_r8 = 0;
                          iVar18 = 4;
                          in_r7 = 1;
                          do {
                            iVar12 = in_r8 + uVar22;
                            in_r8 = in_r8 + 1;
                            *(int *)(iVar19 + 0x10) = iVar12;
                            iVar19 = iVar19 + 4;
                            iVar12 = *(int *)(uVar23 + 0x54) + uVar9;
                            uVar9 = uVar9 + 0x28;
                            *(undefined1 *)(iVar12 + 0x10) = 1;
                            iVar18 = iVar18 + -1;
                          } while (iVar18 != 0);
                          goto LAB_00061394;
                        }
                      }
                      *(undefined1 *)(param_2 + 4) = 0;
                      iVar3 = *(int *)(uVar23 + 0x58);
                      uVar14 = (**(code **)(param_1 + 0x10))
                                         (iVar3 + 0x10,0x28,in_r5,in_r6,in_r7,in_r8,0);
                      in_r5 = *(int *)(uVar23 + 0x58) * 0x28;
                      (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar14,*(undefined4 *)(uVar23 + 0x54));
                      (**(code **)(param_1 + 0x18))(*(undefined4 *)(uVar23 + 0x54));
                      *(undefined4 *)(uVar23 + 0x54) = uVar14;
                      iVar12 = iVar3 * 0x28;
                      iVar24 = 4;
                      iVar18 = 0;
                      in_r8 = 1;
                      *(int *)(uVar23 + 0x58) = *(int *)(uVar23 + 0x58) + 0x10;
                      do {
                        iVar4 = iVar3 + iVar18;
                        iVar18 = iVar18 + 1;
                        *(int *)(iVar19 + 0x10) = iVar4;
                        iVar19 = iVar19 + 4;
                        iVar4 = iVar12 + *(int *)(uVar23 + 0x54);
                        iVar12 = iVar12 + 0x28;
                        *(undefined1 *)(iVar4 + 0x10) = 1;
                        iVar24 = iVar24 + -1;
                      } while (iVar24 != 0);
                    }
                    else if (iVar18 == 0x87be) {
                      uVar14 = 0;
                      uVar22 = 0;
                      iVar18 = 0;
                      bVar2 = true;
                      *(int *)(uVar23 + 0x5c) = *(int *)(uVar23 + 0x5c) + 1;
                      while (uVar22 < *(uint *)(uVar23 + 0x58)) {
                        if (!bVar2) goto LAB_0006106c;
                        if (*(char *)(iVar18 + *(int *)(uVar23 + 0x54) + 0x10) == '\0') {
                          uVar14 = 1;
                          bVar2 = false;
                        }
                        else {
                          uVar22 = uVar22 + 1;
                          iVar18 = iVar18 + 0x28;
                        }
                      }
LAB_00061068:
                      if (!bVar2) {
LAB_0006106c:
                        *(uint *)(iVar19 + 4) = uVar22;
                        *(undefined4 *)(iVar19 + 8) = 0;
                        *(undefined1 *)(uVar22 * 0x28 + *(int *)(uVar23 + 0x54) + 0x10) = 1;
                        iVar18 = param_2[8];
                        goto LAB_00061398;
                      }
                      *(char *)(param_2 + 4) = (char)uVar14;
                      iVar18 = *(int *)(uVar23 + 0x58);
                      uVar15 = (**(code **)(param_1 + 0x10))(iVar18 + 0x10,0x28);
                      in_r5 = *(int *)(uVar23 + 0x58) * 0x28;
                      (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar15,*(undefined4 *)(uVar23 + 0x54));
                      (**(code **)(param_1 + 0x18))(*(undefined4 *)(uVar23 + 0x54));
                      *(undefined4 *)(uVar23 + 0x54) = uVar15;
                      *(int *)(uVar23 + 0x58) = *(int *)(uVar23 + 0x58) + 0x10;
                      *(undefined4 *)(iVar19 + 8) = uVar14;
                      goto LAB_000611fc;
                    }
                    goto LAB_00061394;
                  }
                  in_r8 = 0;
                  uVar22 = 0;
                  iVar18 = 0;
                  bVar2 = true;
                  *(int *)(uVar23 + 0x5c) = *(int *)(uVar23 + 0x5c) + 1;
                  while (uVar22 < *(uint *)(uVar23 + 0x58)) {
                    if (!bVar2) goto LAB_0006116c;
                    if (*(char *)(iVar18 + *(int *)(uVar23 + 0x54) + 0x10) == '\0') {
                      in_r8 = 1;
                      bVar2 = false;
                    }
                    else {
                      uVar22 = uVar22 + 1;
                      iVar18 = iVar18 + 0x28;
                    }
                  }
LAB_00061168:
                  if (bVar2) {
                    *(char *)(param_2 + 4) = (char)in_r8;
                    iVar18 = *(int *)(uVar23 + 0x58);
                    uVar14 = (**(code **)(param_1 + 0x10))(iVar18 + 0x10,0x28);
                    in_r5 = *(int *)(uVar23 + 0x58) * 0x28;
                    (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar14,*(undefined4 *)(uVar23 + 0x54));
                    (**(code **)(param_1 + 0x18))(*(undefined4 *)(uVar23 + 0x54));
                    *(undefined4 *)(uVar23 + 0x54) = uVar14;
                    *(int *)(uVar23 + 0x58) = *(int *)(uVar23 + 0x58) + 0x10;
LAB_000611fc:
                    *(int *)(iVar19 + 4) = iVar18;
                    *(undefined1 *)(iVar18 * 0x28 + *(int *)(uVar23 + 0x54) + 0x10) = 1;
                    iVar18 = param_2[8];
                  }
                  else {
LAB_0006116c:
                    *(uint *)(iVar19 + 4) = uVar22;
                    *(undefined1 *)(uVar22 * 0x28 + *(int *)(uVar23 + 0x54) + 0x10) = 1;
                    iVar18 = param_2[8];
                  }
                }
                else if (*(int *)(iVar19 + 0x28) == 0x87c3) {
                  param_2[0x18] = param_2[0x18] + 1;
                  *(undefined1 *)(iVar19 + 0x3d) = 1;
                  iVar18 = *(int *)(iVar19 + 0x24);
                  if (iVar18 == 0x87bf) {
                    in_r8 = 0;
                    uVar22 = 0;
                    iVar18 = 0;
                    bVar2 = true;
                    *(int *)(uVar23 + 0x5c) = *(int *)(uVar23 + 0x5c) + 1;
                    while (uVar22 < *(uint *)(uVar23 + 0x58)) {
                      if (!bVar2) goto LAB_0006116c;
                      if (*(char *)(iVar18 + *(int *)(uVar23 + 0x54) + 0x10) == '\0') {
                        in_r8 = 1;
                        bVar2 = false;
                      }
                      else {
                        uVar22 = uVar22 + 1;
                        iVar18 = iVar18 + 0x28;
                      }
                    }
                    goto LAB_00061168;
                  }
                  if (iVar18 == 0x87c0) {
                    uVar22 = 0;
                    iVar18 = 0;
                    bVar2 = true;
                    *(int *)(uVar23 + 0x5c) = *(int *)(uVar23 + 0x5c) + 4;
                    while (uVar22 < *(int *)(uVar23 + 0x58) - 3U) {
                      if (!bVar2) goto LAB_00061278;
                      if (*(char *)(iVar18 + *(int *)(uVar23 + 0x54) + 0x10) == '\0') {
                        bVar2 = false;
                      }
                      else {
                        uVar22 = uVar22 + 1;
                        iVar18 = iVar18 + 0x28;
                      }
                    }
                    if (!bVar2) {
LAB_00061278:
                      uVar9 = uVar22 * 0x28;
                      iVar18 = uVar9 + *(int *)(uVar23 + 0x54);
                      in_r8 = uVar9;
                      if (((*(char *)(iVar18 + 0x38) == '\0') && (*(char *)(iVar18 + 0x60) == '\0'))
                         && (*(char *)(iVar18 + 0x88) == '\0')) {
                        in_r8 = 0;
                        iVar18 = 4;
                        in_r7 = 1;
                        do {
                          iVar12 = in_r8 + uVar22;
                          in_r8 = in_r8 + 1;
                          *(int *)(iVar19 + 0x10) = iVar12;
                          iVar19 = iVar19 + 4;
                          iVar12 = *(int *)(uVar23 + 0x54) + uVar9;
                          uVar9 = uVar9 + 0x28;
                          *(undefined1 *)(iVar12 + 0x10) = 1;
                          iVar18 = iVar18 + -1;
                        } while (iVar18 != 0);
                        goto LAB_00061394;
                      }
                    }
                    *(undefined1 *)(param_2 + 4) = 0;
                    iVar3 = *(int *)(uVar23 + 0x58);
                    uVar14 = (**(code **)(param_1 + 0x10))
                                       (iVar3 + 0x10,0x28,in_r5,in_r6,in_r7,in_r8,0);
                    in_r5 = *(int *)(uVar23 + 0x58) * 0x28;
                    (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar14,*(undefined4 *)(uVar23 + 0x54));
                    (**(code **)(param_1 + 0x18))(*(undefined4 *)(uVar23 + 0x54));
                    *(undefined4 *)(uVar23 + 0x54) = uVar14;
                    iVar12 = iVar3 * 0x28;
                    iVar24 = 4;
                    iVar18 = 0;
                    in_r8 = 1;
                    *(int *)(uVar23 + 0x58) = *(int *)(uVar23 + 0x58) + 0x10;
                    do {
                      iVar4 = iVar3 + iVar18;
                      iVar18 = iVar18 + 1;
                      *(int *)(iVar19 + 0x10) = iVar4;
                      iVar19 = iVar19 + 4;
                      iVar4 = *(int *)(uVar23 + 0x54) + iVar12;
                      iVar12 = iVar12 + 0x28;
                      *(undefined1 *)(iVar4 + 0x10) = 1;
                      iVar24 = iVar24 + -1;
                    } while (iVar24 != 0);
                  }
                  else if (iVar18 == 0x87be) {
                    uVar14 = 0;
                    uVar22 = 0;
                    iVar18 = 0;
                    bVar2 = true;
                    *(int *)(uVar23 + 0x5c) = *(int *)(uVar23 + 0x5c) + 1;
                    while (uVar22 < *(uint *)(uVar23 + 0x58)) {
                      if (!bVar2) goto LAB_0006106c;
                      if (*(char *)(iVar18 + *(int *)(uVar23 + 0x54) + 0x10) == '\0') {
                        uVar14 = 1;
                        bVar2 = false;
                      }
                      else {
                        uVar22 = uVar22 + 1;
                        iVar18 = iVar18 + 0x28;
                      }
                    }
                    goto LAB_00061068;
                  }
LAB_00061394:
                  iVar18 = param_2[8];
                }
LAB_00061398:
                uVar17 = uVar17 + 1;
                iVar11 = iVar11 + 0x54;
              } while (uVar17 < *(uint *)(iVar16 + iVar18 + 0x34));
            }
          }
        }
LAB_000613b0:
        uVar5 = uVar5 + 1;
        iVar10 = iVar10 + 0x74;
      } while (uVar5 < (uint)param_2[5]);
      if (param_2[5] != 0) {
        uVar5 = 0;
        iVar10 = 0;
        do {
          iVar16 = param_2[6];
          if (*(int *)(iVar10 + iVar16 + 0x20) == 2) {
            iVar19 = param_2[8];
            iVar11 = *(int *)(iVar10 + iVar16 + 0x24) * 0x54;
            iVar18 = iVar11 + iVar19;
            if ((*(int *)(iVar18 + 0x28) == 0x87c3) && (*(char *)(iVar18 + 0x3d) == '\0')) {
              if (*(int *)(iVar18 + 0x30) == 0) {
                if (*(uint *)(iVar18 + 0x34) < 2) {
                  FUN_00055da0(param_1,param_2,uVar23,iVar18);
                  iVar16 = param_2[6];
                  goto LAB_000614b0;
                }
              }
              else {
                iVar11 = FUN_00054da0(param_2 + 7,*(int *)(iVar18 + 0x30));
                iVar19 = param_2[8];
                iVar11 = iVar11 * 0x54;
              }
              if (*(int *)(iVar19 + iVar11 + 0x34) != 0) {
                uVar17 = 0;
                iVar16 = iVar11;
                do {
                  iVar19 = iVar16 + iVar19;
                  uVar17 = uVar17 + 1;
                  iVar16 = iVar16 + 0x54;
                  FUN_00055da0(param_1,param_2,uVar23,iVar19);
                  iVar19 = param_2[8];
                } while (uVar17 < *(uint *)(iVar19 + iVar11 + 0x34));
              }
              iVar16 = param_2[6];
            }
          }
LAB_000614b0:
          if (*(int *)(iVar10 + iVar16 + 0x3c) == 2) {
            iVar19 = param_2[8];
            iVar11 = *(int *)(iVar10 + iVar16 + 0x40) * 0x54;
            iVar18 = iVar11 + iVar19;
            if ((*(int *)(iVar18 + 0x28) == 0x87c3) && (*(char *)(iVar18 + 0x3d) == '\0')) {
              if (*(int *)(iVar18 + 0x30) == 0) {
                if (*(uint *)(iVar18 + 0x34) < 2) {
                  FUN_00055da0(param_1,param_2,uVar23,iVar18);
                  iVar16 = param_2[6];
                  goto LAB_00061580;
                }
              }
              else {
                iVar11 = FUN_00054da0(param_2 + 7,*(int *)(iVar18 + 0x30));
                iVar19 = param_2[8];
                iVar11 = iVar11 * 0x54;
              }
              if (*(int *)(iVar19 + iVar11 + 0x34) != 0) {
                uVar17 = 0;
                iVar16 = iVar11;
                do {
                  iVar19 = iVar16 + iVar19;
                  uVar17 = uVar17 + 1;
                  iVar16 = iVar16 + 0x54;
                  FUN_00055da0(param_1,param_2,uVar23,iVar19);
                  iVar19 = param_2[8];
                } while (uVar17 < *(uint *)(iVar19 + iVar11 + 0x34));
              }
              iVar16 = param_2[6];
            }
          }
LAB_00061580:
          if (*(int *)(iVar10 + iVar16 + 0x58) == 2) {
            iVar18 = param_2[8];
            iVar16 = *(int *)(iVar10 + iVar16 + 0x5c) * 0x54;
            iVar11 = iVar16 + iVar18;
            if ((*(int *)(iVar11 + 0x28) == 0x87c3) && (*(char *)(iVar11 + 0x3d) == '\0')) {
              if (*(int *)(iVar11 + 0x30) == 0) {
                if (*(uint *)(iVar11 + 0x34) < 2) {
                  FUN_00055da0(param_1,param_2,uVar23,iVar11);
                  goto LAB_00061650;
                }
              }
              else {
                iVar16 = FUN_00054da0(param_2 + 7,*(int *)(iVar11 + 0x30));
                iVar18 = param_2[8];
                iVar16 = iVar16 * 0x54;
              }
              if (*(int *)(iVar18 + iVar16 + 0x34) != 0) {
                uVar17 = 0;
                iVar11 = iVar16;
                do {
                  iVar18 = iVar11 + iVar18;
                  uVar17 = uVar17 + 1;
                  iVar11 = iVar11 + 0x54;
                  FUN_00055da0(param_1,param_2,uVar23,iVar18);
                  iVar18 = param_2[8];
                } while (uVar17 < *(uint *)(iVar18 + iVar16 + 0x34));
              }
            }
          }
LAB_00061650:
          uVar5 = uVar5 + 1;
          iVar10 = iVar10 + 0x74;
        } while (uVar5 < (uint)param_2[5]);
      }
    }
    if ((*(char *)((int)param_2 + 0x7a) != '\0') && ((*(uint *)(param_1 + 0x44) & 0x1000000) != 0))
    {
      uVar5 = *(int *)(uVar23 + 0x5c) + 1;
      *(int *)(uVar23 + 0x60) = *(int *)(uVar23 + 0x5c);
      *(uint *)(uVar23 + 0x5c) = uVar5;
      if (*(uint *)(uVar23 + 0x58) < uVar5) {
        *(undefined1 *)(param_2 + 4) = 0;
        uVar14 = (**(code **)(param_1 + 0x10))(*(int *)(uVar23 + 0x58) + 0x10,0x28);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar14,*(undefined4 *)(uVar23 + 0x54),*(int *)(uVar23 + 0x58) * 0x28);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(uVar23 + 0x54));
        *(undefined4 *)(uVar23 + 0x54) = uVar14;
        *(int *)(uVar23 + 0x58) = *(int *)(uVar23 + 0x58) + 0x10;
      }
    }
    uVar17 = 0;
    *(undefined4 *)(uVar23 + 0x18) = 0;
    uVar5 = 0;
    if (param_2[5] != 0) {
      uVar22 = 0;
      iVar10 = 0;
      do {
        if (0x20 < *(int *)(iVar10 + param_2[6]) - 0x8782U) {
          param_2[0x19] = 0;
          param_2[0xc] = 0;
          param_2[0x15] = 0;
          param_2[0x16] = 0;
          param_2[0x17] = 0;
          param_2[0x18] = 0;
          return 0;
        }
        FUN_000564c0(param_1,param_2,uVar23,iVar10 + param_2[6] + 4);
        FUN_000564c0(param_1,param_2,uVar23,iVar10 + param_2[6] + 0x20);
        FUN_000564c0(param_1,param_2,uVar23,iVar10 + param_2[6] + 0x3c);
        iVar16 = iVar10 + param_2[6] + 0x58;
        FUN_000564c0(param_1,param_2,uVar23,iVar16);
        if (uVar17 < (uint)param_2[0x19]) {
          uVar17 = param_2[0x19];
        }
        iVar11 = *(int *)(iVar10 + param_2[6]) + -0x8782;
        iVar18 = (*(code *)(PTR_FUN_001db9b8)[iVar11])(param_1,param_2,iVar10 + param_2[6]);
        if (iVar18 < 0) {
          uVar7 = 0;
          goto LAB_00061d90;
        }
        *(int *)(uVar23 + 0x18) = iVar18 + *(int *)(uVar23 + 0x18);
        uVar5 = *(uint *)(param_1 + 0x44);
        if ((uVar5 & 0x800) != 0) {
          iVar18 = iVar10 + param_2[6];
          iVar19 = *(int *)(iVar18 + 4);
          if ((iVar19 == 1) && (*(int *)(iVar18 + 8) == 0x87bd)) {
            bVar1 = ((unsigned char *)0x000011d1)[param_1];
            _memcpy(auStack_d8,iVar18,0x74);
            iStack_c8 = 0;
            iStack_c4 = 0;
            iStack_c0 = 0;
            iStack_d0 = bVar1 + 0x879d;
            iStack_cc = iVar19;
            iVar18 = (*(code *)(PTR_FUN_001db9b8)[iVar11])(param_1,param_2,auStack_d8);
            iVar12 = *(int *)(uVar23 + 0x18);
            *(int *)(uVar23 + 0x18) = iVar18 + iVar12;
            uStack_a4 = 0x87de;
            auStack_d8[0] = 0x8799;
            iStack_cc = 0;
            uStack_b0 = 0x87dd;
            uStack_ac = 0x87dd;
            uStack_a8 = 0x87dd;
            iStack_c8 = iVar19;
            iStack_c4 = iVar19;
            iStack_c0 = iVar19;
            iVar18 = (*(code *)PTR_FUN_001dba14)
                               (param_1,param_2,auStack_d8,iVar16,in_r7,in_r8,iVar12);
            *(int *)(uVar23 + 0x18) = iVar18 + *(int *)(uVar23 + 0x18);
            uVar5 = *(uint *)(param_1 + 0x44);
          }
        }
        if ((((uVar5 & 0x400) != 0) && (iVar18 = iVar10 + param_2[6], *(int *)(iVar18 + 4) == 1)) &&
           (*(int *)(iVar18 + 8) == 0x879a)) {
          _memcpy(auStack_d8,iVar18,0x74);
          iStack_d0 = (byte)((unsigned char *)0x000011d2)[param_1] + 0x879d;
          iVar16 = (*(code *)(PTR_FUN_001db9b8)[iVar11])
                             (param_1,param_2,auStack_d8,iVar16,in_r7,in_r8,
                              (PTR_FUN_001db9b8)[iVar11]);
          *(int *)(uVar23 + 0x18) = iVar16 + *(int *)(uVar23 + 0x18);
        }
        if (*(char *)((int)param_2 + 0x7b) == '\0') {
          FUN_00056be0(param_1,param_2,uVar22);
        }
        if (((*(char *)((int)param_2 + 0x7a) != '\0') &&
            ((*(uint *)(param_1 + 0x44) & 0x1000000) != 0)) &&
           ((*(int *)(iVar10 + param_2[6] + 4) == 1 && (*(int *)(iVar10 + param_2[6] + 8) == 0x87bd)
            ))) {
          iVar11 = *(int *)(uVar23 + 0x18);
          iVar16 = ((int (*)())FUN_0005e0d0)(param_1,param_2,iVar11 * 0x10 + *(int *)(uVar23 + 0x1c) + -0x10);
          *(int *)(uVar23 + 0x18) = iVar11 + iVar16;
        }
        uVar5 = param_2[5];
        uVar22 = uVar22 + 1;
        iVar10 = iVar10 + 0x74;
      } while (uVar22 < uVar5);
    }
    iVar10 = *(int *)(uVar23 + 0x18);
    param_2[0x19] = uVar17;
    param_2[0x15] = iVar10;
    if (uVar5 != 0) {
      uVar5 = 0;
      iVar10 = 0;
      do {
        iVar16 = uVar5 * 0x10;
        uVar5 = uVar5 + 1;
        iVar11 = iVar16 + iVar8;
        uVar20 = *(undefined4 *)(iVar11 + 0xc);
        uVar14 = *(undefined4 *)(iVar11 + 4);
        iVar18 = iVar10 + param_2[6];
        iVar10 = iVar10 + 0x74;
        uVar15 = *(undefined4 *)(iVar11 + 8);
        *(undefined4 *)(iVar18 + 0xc) = *(undefined4 *)(iVar8 + iVar16);
        *(undefined4 *)(iVar18 + 0x18) = uVar20;
        *(undefined4 *)(iVar18 + 0x10) = uVar14;
        *(undefined4 *)(iVar18 + 0x14) = uVar15;
      } while (uVar5 < (uint)param_2[5]);
    }
    (**(code **)(param_1 + 0x18))(iVar8);
    iVar8 = *(int *)(uVar23 + 0x18);
    *(undefined4 *)(uVar23 + 8) = 0;
    if (iVar8 != 0) {
      do {
        uVar17 = *(uint *)(iVar8 * 0x10 + *(int *)(uVar23 + 0x1c) + -0x10);
        uVar5 = uVar17 & 0xf00;
        if (((uVar5 == 0x200) || (uVar5 == 0x300)) && ((uVar17 & 0xfe000) == 0)) {
          *(int *)(uVar23 + 8) = iVar8 + -1;
        }
        iVar8 = iVar8 + -1;
      } while ((iVar8 != 0) && (*(int *)(uVar23 + 8) == 0));
    }
    if (*(int *)(uVar23 + 0x224) != 0) {
      uVar14 = (**(code **)(param_1 + 0xc))(*(int *)(uVar23 + 0x224) << 2);
      *(undefined4 *)(uVar23 + 0x220) = uVar14;
      uVar5 = param_2[7];
      if (uVar5 != 0) {
        uVar17 = 0;
        iVar8 = 0;
        iVar10 = 0;
        do {
          iVar16 = iVar10 + param_2[8];
          if (((*(char *)(iVar16 + 0x3d) != '\0') && (*(int *)(iVar16 + 0x28) == 0x87c2)) &&
             (*(char *)(iVar16 + 0x44) == '\0')) {
            iVar16 = iVar8 * 4;
            iVar8 = iVar8 + 1;
            *(uint *)(iVar16 + *(int *)(uVar23 + 0x220)) = uVar17;
            uVar5 = param_2[7];
          }
          uVar17 = uVar17 + 1;
          iVar10 = iVar10 + 0x54;
        } while (uVar17 < uVar5);
      }
    }
    if (*(int *)(uVar23 + 0x22c) != 0) {
      uVar14 = (**(code **)(param_1 + 0xc))(*(int *)(uVar23 + 0x22c) << 2);
      *(undefined4 *)(uVar23 + 0x228) = uVar14;
      uVar5 = param_2[7];
      if (uVar5 != 0) {
        uVar17 = 0;
        iVar8 = 0;
        iVar10 = 0;
        do {
          iVar16 = iVar10 + param_2[8];
          if (((*(char *)(iVar16 + 0x3d) != '\0') && (*(int *)(iVar16 + 0x28) == 0x87c2)) &&
             (*(char *)(iVar16 + 0x44) != '\0')) {
            iVar11 = iVar8 * 4;
            iVar8 = iVar8 + 1;
            *(uint *)(iVar11 + *(int *)(uVar23 + 0x228)) = uVar17;
            *(uint *)(uVar23 + 0x230) = *(uint *)(uVar23 + 0x230) | *(uint *)(iVar16 + 0x50);
            uVar5 = param_2[7];
          }
          uVar17 = uVar17 + 1;
          iVar10 = iVar10 + 0x54;
        } while (uVar17 < uVar5);
      }
    }
    uVar5 = *(uint *)(uVar23 + 0x5c);
    if (uVar5 != 0) {
      if (puVar21[0x23] < uVar5) {
        uVar5 = (**(code **)(param_1 + 0x14))(puVar21[0x22],uVar5 << 4);
        puVar21[0x22] = uVar5;
        puVar21[0x23] = *(uint *)(uVar23 + 0x5c);
      }
      if (param_2[0x18] != 0) {
        uVar17 = param_2[7];
        uVar5 = 0;
        if (uVar17 != 0) {
          do {
            iVar8 = uVar5 * 0x54 + param_2[8];
            if ((*(char *)(iVar8 + 0x3d) != '\0') && (*(int *)(iVar8 + 0x28) == 0x87c3)) {
              puVar13 = *(undefined4 **)(iVar8 + 0x38);
              uVar14 = puVar13[3];
              iVar8 = *(int *)(iVar8 + 4) * 0x10;
              uVar20 = puVar13[1];
              uVar15 = puVar13[2];
              iVar10 = iVar8 + puVar21[0x22];
              *(undefined4 *)(iVar8 + puVar21[0x22]) = *puVar13;
              *(undefined4 *)(iVar10 + 0xc) = uVar14;
              *(undefined4 *)(iVar10 + 4) = uVar20;
              *(undefined4 *)(iVar10 + 8) = uVar15;
              uVar17 = param_2[7];
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar17);
        }
      }
    }
    ((int (*)())FUN_00062af0)(param_1,param_2);
    ((int (*)())FUN_00062a70)(param_1,param_2);
    *(undefined1 *)(param_2[1] + *(int *)(((unsigned char *)0x0000118c) + param_1)) = 0;
    if (*(int *)(uVar23 + 0x2b8) != 0) {
      (**(code **)(param_1 + 0x18))(*(int *)(uVar23 + 0x2b8));
      *(undefined4 *)(uVar23 + 0x2b8) = 0;
    }
    uVar7 = *(undefined1 *)(param_2 + 4);
  }
  return uVar7;
}

/* FUN_00061dc0 @ 0x61dc0 (224 bytes) */
int FUN_00061dc0(param_1, param_2)
  int param_1;
  int param_2;
{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x18);
  if ((iVar2 != 0) && (*(int *)(param_2 + 0x1c) != 0)) {
    puVar1 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,iVar2 * 4 + 3);
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar1;
    *puVar1 = 0x880;
    *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) = *(undefined4 *)(param_2 + 4);
    *(uint *)(*(int *)(FUN_00002748 + param_1 + 4) + 8) = (iVar2 * 4 + -1) * 0x10000 | 0x8882;
    _memcpy(*(int *)(FUN_00002748 + param_1 + 4) + 0xc,*(undefined4 *)(param_2 + 0x1c),iVar2 * 0x10)
    ;
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
    iVar2 = iVar2 * 0x10 + *(int *)(FUN_00002748 + param_1 + 4) + 0xc;
    *(int *)(FUN_00002748 + param_1 + 4) = iVar2;
                    
                    
    (*UNRECOVERED_JUMPTABLE)(param_1,iVar2);
    return;
  }
  return;
}

/* FUN_00061eb0 @ 0x61eb0 (604 bytes) */
int FUN_00061eb0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  short sVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_3 + 0x5c);
  if (iVar4 == 0) {
    return;
  }
  if ((*(char *)(param_2 + 0x7a) == '\0') || ((*(uint *)(param_1 + 0x44) & 0x1000000) == 0)) {
    if (param_5 == 0) {
      return;
    }
  }
  else {
    iVar5 = *(int *)(param_3 + 0x60);
    iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
    sVar1 = *(short *)(((unsigned char *)0x00002e04) + iVar4);
    if (sVar1 == 0x801) {
      iVar2 = param_4 + iVar5 * 0x10;
      *(undefined4 *)(iVar2 + 4) = 0;
      *(float *)(iVar2 + 8) =
           -(*(float *)(((unsigned char *)0x00002df0) + iVar4) * *(float *)(((unsigned char *)0x00002df0) + iVar4));
    }
    else if (sVar1 == 0x2601) {
      iVar2 = param_4 + iVar5 * 0x10;
      *(float *)(iVar2 + 4) = *(float *)(((unsigned char *)0x00002df8) + iVar4) * *(float *)(((unsigned char *)0x00002dfc) + iVar4);
      *(float *)(iVar2 + 8) = -*(float *)(((unsigned char *)0x00002dfc) + iVar4);
    }
    else if (sVar1 == 0x800) {
      iVar2 = param_4 + iVar5 * 0x10;
      *(undefined4 *)(iVar2 + 4) = 0;
      *(float *)(iVar2 + 8) = -*(float *)(((unsigned char *)0x00002df0) + iVar4);
    }
    if (param_5 == 0) {
      puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,7);
      *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3;
      *puVar3 = 0x880;
      iVar4 = param_4 + iVar5 * 0x10;
      *(int *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) =
           iVar5 + *(int *)(param_1 + 0x2448) + *(int *)(param_3 + 0x14);
      *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 8) = 0x38882;
      *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 0xc) =
           *(undefined4 *)(param_4 + iVar5 * 0x10);
      *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 0x10) = *(undefined4 *)(iVar4 + 4);
      *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 0x14) = *(undefined4 *)(iVar4 + 8);
      *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 0x18) = *(undefined4 *)(iVar4 + 0xc);
      UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
      iVar4 = *(int *)(FUN_00002748 + param_1 + 4) + 0x1c;
      *(int *)(FUN_00002748 + param_1 + 4) = iVar4;
      goto LAB_000620ec;
    }
    iVar4 = *(int *)(param_3 + 0x5c);
  }
  puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,iVar4 * 4 + 3);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3;
  *puVar3 = 0x880;
  *(int *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) =
       *(int *)(param_1 + 0x2448) + *(int *)(param_3 + 0x14);
  *(uint *)(*(int *)(FUN_00002748 + param_1 + 4) + 8) = (iVar4 * 4 + -1) * 0x10000 | 0x8882;
  _memcpy(*(int *)(FUN_00002748 + param_1 + 4) + 0xc,param_4,iVar4 * 0x10);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  iVar4 = iVar4 * 0x10 + *(int *)(FUN_00002748 + param_1 + 4) + 0xc;
  *(int *)(FUN_00002748 + param_1 + 4) = iVar4;
LAB_000620ec:
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,iVar4);
  return;
}

/* FUN_00062120 @ 0x62120 (252 bytes) */
int FUN_00062120(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  short sVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x44);
  uVar2 = (uint)*(byte *)(param_3 + 0x43) & uVar3 >> 7 & 1 |
          ((uint)*(byte *)(param_3 + 0x44) & uVar3 >> 6 & 1) << 1 |
          (uint)(*(int *)(param_1 + 0x148) == 1) << 2;
  if (*(char *)(param_2 + 0x7a) != '\0') {
    if (*(char *)(param_2 + 0x6e) != '\0') {
      uVar2 = uVar2 | uVar3 >> 9 & 8;
    }
    if ((uVar3 & 0x1000000) != 0) {
      sVar1 = *(short *)(((unsigned char *)0x00002e04) + *(int *)(*(int *)(param_1 + 4) + 0x10));
      if (sVar1 == 0x801) {
        uVar2 = uVar2 | 0x30;
      }
      else if (sVar1 == 0x2601) {
        uVar2 = uVar2 | 0x10;
      }
      else if (sVar1 == 0x800) {
        uVar2 = uVar2 | 0x20;
      }
    }
    if ((uVar3 & 0x800) != 0) {
      uVar2 = uVar2 | (uint)(byte)((unsigned char *)0x000011d1)[param_1] << 0xf | 0x4000;
    }
  }
  if (*(char *)(param_2 + 0x6c) == '\0') {
    return uVar2;
  }
  if ((*(uint *)(param_1 + 0x44) & 0x400) == 0) {
    return uVar2;
  }
  return uVar2 | (uint)(byte)((unsigned char *)0x000011d2)[param_1] << 0x18 | 0x800000;
}

/* FUN_00062220 @ 0x62220 (272 bytes) */
int FUN_00062220(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(param_2 + 0x1c) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x1c));
  }
  if (*(int *)(param_2 + 0x24) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x24));
  }
  if (*(int *)(param_2 + 0x4c) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x4c));
  }
  if (*(int *)(param_2 + 0x54) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x54));
  }
  if (*(int *)(param_2 + 0x220) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x220));
  }
  if (*(int *)(param_2 + 0x228) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x228));
  }
  if (*(int *)(param_2 + 0x2b8) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x2b8));
  }
  (**(code **)(param_1 + 0x18))(param_2);
  FUN_0007dd30(param_1,param_2);
  return;
}

/* FUN_00062370 @ 0x62370 (104 bytes) */
int FUN_00062370(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 == 0) {
    iVar2 = param_1 + 0x18a0;
    iVar3 = 0x10;
    do {
      pbVar1 = (byte *)(param_2 + 0x71);
      param_2 = param_2 + 1;
      *(uint *)(iVar2 + 8) = -(uint)*pbVar1 >> 0x1f | *(uint *)(iVar2 + 8) & 0xfffffffe;
      iVar2 = iVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  else {
    iVar2 = param_1 + 0x18a0;
    iVar3 = 0x10;
    do {
      *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) & 0xfffffffe;
      iVar2 = iVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

/* FUN_000623e0 @ 0x623e0 (40 bytes) */
int FUN_000623e0(param_1)
  int param_1;
{
  *(undefined4 *)(((unsigned char *)0x000011c4) + param_1) = 0x100;
  *(undefined4 *)(((unsigned char *)0x000011b8) + param_1) = 0x100;
  *(undefined4 *)(((unsigned char *)0x000011bc) + param_1) = 0x10;
  *(undefined4 *)(((unsigned char *)0x000011c8) + param_1) = 0x20;
  *(undefined4 *)(((unsigned char *)0x000011c0) + param_1) = 0x100;
  return;
}

/* FUN_00062410 @ 0x62410 (116 bytes) */
int FUN_00062410(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(**(code **)(param_1 + 0xc))(0xc);
  *puVar2 = 0;
  uVar1 = *(undefined4 *)(param_1 + 0x2448);
  puVar2[2] = 0;
  puVar2[1] = uVar1;
  *(undefined4 *)(((unsigned char *)0x000011c8) + param_1) = 0x20;
  *(undefined4 **)(((unsigned char *)0x000011b4) + param_1) = puVar2;
  *(undefined4 *)(((unsigned char *)0x000011c4) + param_1) = 0x100;
  *(undefined4 *)(((unsigned char *)0x000011bc) + param_1) = 0x10;
  *(undefined4 *)(((unsigned char *)0x000011b8) + param_1) = 0x100;
  *(undefined4 *)(((unsigned char *)0x000011c0) + param_1) = 0x100;
  return;
}

/* FUN_00062490 @ 0x62490 (120 bytes) */
int FUN_00062490(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = *(int *)(((unsigned char *)0x000011b4) + param_1);
  puVar1 = *(undefined4 **)(iVar2 + 8);
  while (puVar1 != (undefined4 *)0x0) {
    *(undefined1 *)*puVar1 = 0;
    puVar3 = (undefined4 *)puVar1[1];
    (**(code **)(param_1 + 0x18))(puVar1);
    puVar1 = puVar3;
  }
  *(undefined4 *)(iVar2 + 8) = 0;
  return;
}

/* FUN_00062510 @ 0x62510 (92 bytes) */
int FUN_00062510(param_1)
  int param_1;
{
  if (*(int *)(((unsigned char *)0x000011b4) + param_1) != 0) {
    ((int (*)())FUN_00062490)(param_1);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(((unsigned char *)0x000011b4) + param_1));
    *(undefined4 *)(((unsigned char *)0x000011b4) + param_1) = 0;
  }
  return;
}

/* FUN_00062570 @ 0x62570 (616 bytes) */
int FUN_00062570(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  uint param_3;
{
  undefined1 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  
  if (param_3 == 0xffffffff) {
    param_3 = 0;
    uVar8 = *(uint *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x10);
  }
  else {
    uVar8 = param_3 + 1;
  }
  iVar9 = param_3 << 2;
  do {
    puVar4 = (undefined1 *)(**(code **)(param_1 + 0xc))(700);
    *puVar4 = 0;
    *(undefined4 *)(puVar4 + 4) = 0;
    *(undefined4 *)(puVar4 + 8) = 0;
    *(undefined4 *)(puVar4 + 0xc) = 0;
    *(undefined4 *)(puVar4 + 0x10) = 0;
    *(undefined4 *)(puVar4 + 0x14) = 0;
    *(undefined4 *)(puVar4 + 0x18) = 0;
    uVar5 = (**(code **)(param_1 + 0xc))(0x1000);
    *(undefined4 *)(puVar4 + 0x20) = 0x100;
    *(undefined4 *)(puVar4 + 0x1c) = uVar5;
    iVar6 = (**(code **)(param_1 + 0x10))(0x16,0x28);
    *(int *)(puVar4 + 0x24) = iVar6;
    *(undefined4 *)(puVar4 + 0x28) = 0x16;
    *(undefined1 *)(iVar6 + 0x10) = 1;
    puVar4[0x2c] = 0;
    puVar4[0x2d] = 0;
    iVar6 = 8;
    puVar1 = puVar4;
    do {
      puVar1[0x2e] = 0;
      puVar1 = puVar1 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar6 = 8;
    puVar1 = puVar4;
    do {
      puVar1[0x36] = 0;
      puVar1 = puVar1 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    puVar4[0x3e] = 0;
    puVar4[0x3f] = 0;
    puVar4[0x40] = 0;
    puVar4[0x41] = 0;
    iVar6 = 4;
    *(undefined1 *)(param_2 + 0x1b) = 0;
    piVar2 = param_2;
    do {
      *(undefined1 *)((int)piVar2 + 0x6d) = 0;
      piVar2 = (int *)((int)piVar2 + 1);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar6 = 8;
    piVar2 = param_2;
    do {
      *(undefined1 *)((int)piVar2 + 0x71) = 0;
      piVar2 = (int *)((int)piVar2 + 1);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    *(undefined1 *)((int)param_2 + 0x7a) = 0;
    *(undefined1 *)((int)param_2 + 0x79) = 0;
    puVar4[0x44] = 0;
    puVar4[0x42] = 0;
    puVar4[0x43] = 0;
    *(undefined4 *)(puVar4 + 0x48) = 0;
    uVar5 = (**(code **)(param_1 + 0x10))(0x20,0x28);
    *(undefined4 *)(puVar4 + 0x4c) = uVar5;
    *(undefined4 *)(puVar4 + 0x50) = 0x20;
    uVar5 = (**(code **)(param_1 + 0x10))(0x100,0x28);
    puVar4[0x2b0] = 0;
    *(undefined4 *)(puVar4 + 0x58) = 0x100;
    *(undefined4 *)(puVar4 + 0x54) = uVar5;
    *(undefined4 *)(puVar4 + 0x5c) = 0;
    *(undefined4 *)(puVar4 + 0x74) = 0;
    *(undefined4 *)(puVar4 + 0x220) = 0;
    *(undefined4 *)(puVar4 + 0x224) = 0;
    *(undefined4 *)(puVar4 + 0x228) = 0;
    *(undefined4 *)(puVar4 + 0x22c) = 0;
    *(undefined4 *)(puVar4 + 0x230) = 0;
    *(undefined4 *)(puVar4 + 0x2a4) = 0;
    *(undefined4 *)(puVar4 + 0x2a8) = 0;
    *(undefined4 *)(puVar4 + 0x2ac) = 0;
    *(undefined4 *)(puVar4 + 0x2b4) = 0;
    puVar7 = *(undefined4 **)(*param_2 + iVar9);
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)(**(code **)(param_1 + 0xc))(0x90);
      iVar6 = 0x20;
      puVar3 = puVar7;
      do {
        puVar3 = puVar3 + 1;
        *puVar3 = 0;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      puVar7[0x23] = 0;
      puVar7[0x21] = 0;
      puVar7[0x22] = 0;
      *(undefined4 **)(*param_2 + iVar9) = puVar7;
    }
    param_3 = param_3 + 1;
    *puVar7 = puVar4;
    iVar9 = iVar9 + 4;
  } while (param_3 < uVar8);
  return;
}

/* FUN_000627e4 @ 0x627e4 (328 bytes) */
int FUN_000627e4(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  
  iVar5 = *param_2;
  if (iVar5 != 0) {
    if (param_3 == 0) {
      uVar7 = *(uint *)(((unsigned char *)0x0000118c) + param_1);
      uVar3 = uVar7 + 1;
    }
    else {
      uVar7 = 0;
      uVar3 = *(uint *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x10);
    }
    if (uVar7 < uVar3) {
      iVar9 = uVar7 << 2;
      iVar8 = 0;
      while( true ) {
        piVar10 = *(int **)(iVar5 + iVar9);
        if (piVar10 != (int *)0x0) {
          if (*(char *)(*piVar10 + 0x2b0) == '\0') {
            ((int (*)())FUN_00062220)(param_1,*piVar10);
            *piVar10 = 0;
          }
          if (param_3 != 0) {
            iVar5 = 0;
            piVar4 = piVar10;
            do {
              piVar1 = piVar4 + 1;
              piVar4 = piVar4 + 1;
              iVar6 = *piVar1;
              while (iVar6 != 0) {
                *piVar4 = *(int *)(iVar6 + 0x2b4);
                ((int (*)())FUN_00062220)(param_1,iVar6);
                iVar6 = *piVar4;
              }
              bVar2 = iVar5 != 0x1f;
              iVar5 = iVar5 + 1;
            } while (bVar2);
            if (piVar10[0x22] != 0) {
              (**(code **)(param_1 + 0x18))(piVar10[0x22]);
            }
            (**(code **)(param_1 + 0x18))(piVar10);
            *(undefined4 *)(*param_2 + iVar9) = 0;
          }
        }
        iVar8 = iVar8 + 1;
        iVar9 = iVar9 + 4;
        if (iVar8 == uVar3 - uVar7) break;
        iVar5 = *param_2;
      }
    }
  }
  return;
}

/* FUN_00062940 @ 0x62940 (276 bytes) */
int FUN_00062940(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 a5;
  int *a7;
  code *UNRECOVERED_JUMPTABLE;
  int iVar7;
  undefined4 *puVar8;
  
  puVar8 = *(undefined4 **)(param_3 + 0x38);
  a5 = puVar8[2];
  uVar1 = puVar8[3];
  iVar3 = *(int *)(param_3 + 4) * 0x10;
  a7 = *(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  uVar6 = *puVar8;
  uVar5 = puVar8[1];
  iVar7 = *a7;
  iVar2 = iVar3 + a7[0x22];
  *(undefined4 *)(iVar3 + a7[0x22]) = uVar6;
  *(undefined4 *)(iVar2 + 0xc) = uVar1;
  *(undefined4 *)(iVar2 + 8) = a5;
  *(undefined4 *)(iVar2 + 4) = uVar5;
  puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,9,param_3,uVar5,uVar6,a5,iVar3,a7);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar4;
  *puVar4 = 0x8a1;
  *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) = 0;
  *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 8) = 0x880;
  *(int *)(*(int *)(FUN_00002748 + param_1 + 4) + 0xc) =
       *(int *)(param_1 + 0x2448) + *(int *)(iVar7 + 0x14) + *(int *)(param_3 + 4);
  *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 0x10) = 0x38882;
  uVar1 = *puVar8;
  iVar3 = *(int *)(FUN_00002748 + param_1 + 4);
  uVar5 = puVar8[1];
  uVar6 = puVar8[2];
  *(undefined4 *)(iVar3 + 0x20) = puVar8[3];
  *(undefined4 *)(iVar3 + 0x14) = uVar1;
  *(undefined4 *)(iVar3 + 0x18) = uVar5;
  *(undefined4 *)(iVar3 + 0x1c) = uVar6;
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(FUN_00002748 + param_1 + 4) = *(int *)(FUN_00002748 + param_1 + 4) + 0x24;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1);
  return;
}

/* FUN_00062a60 @ 0x62a60 (4 bytes) */
int FUN_00062a60()
{
  return;
}

/* FUN_00062a70 @ 0x62a70 (116 bytes) */
int FUN_00062a70(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar3 = *piVar2;
  uVar1 = ((int (*)())FUN_00062120)(param_1,param_2,iVar3);
  *(uint *)(iVar3 + 0x48) = uVar1;
  *(int *)(iVar3 + 0x2b4) = piVar2[(uVar1 & 0x1f) + 1];
  piVar2[(uVar1 & 0x1f) + 1] = iVar3;
  *(undefined1 *)(iVar3 + 0x2b0) = 1;
  piVar2[0x21] = piVar2[0x21] + 1;
  return;
}

/* FUN_00062af0 @ 0x62af0 (5624 bytes) */
int FUN_00062af0(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  iVar5 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  *(undefined4 *)(iVar5 + 0x29c) = 0;
  *(undefined4 *)(iVar5 + 0x240) = 0;
  *(undefined4 *)(iVar5 + 0x23c) = 1;
  *(undefined4 *)(iVar5 + 0x2a0) = 1;
  *(undefined4 *)(iVar5 + 0x238) = 4;
  *(undefined4 *)(iVar5 + 0x2a8) = 1;
  iVar8 = *(int *)(iVar5 + 0x24);
  *(uint *)(iVar5 + 0x244) = *(uint *)(iVar5 + 0x244) & 0xffff0000 | 3;
  *(uint *)(iVar5 + 0x270) = *(uint *)(iVar5 + 0x270) & 0xffff0000 | 0xf688;
  bVar1 = *(char *)(iVar8 + 0x38) != '\0';
  if (bVar1) {
    *(undefined4 *)(iVar5 + 0x2a0) = 2;
    *(undefined4 *)(iVar5 + 0x238) = 8;
    *(undefined4 *)(iVar5 + 0x244) = 0x1030003;
    *(undefined4 *)(iVar5 + 0x270) = 0xf688f688;
  }
  bVar3 = !bVar1;
  uVar7 = (uint)bVar1;
  bVar1 = bVar3;
  if (*(char *)(iVar8 + 0x60) != '\0') {
    bVar1 = !bVar3;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x203;
      *(uint *)(iVar8 + 0x270) = (uint)bVar3 | *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x2030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x88) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x303;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x3030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0xb0) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x403;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x4030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0xd8) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x503;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x5030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x100) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x603;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x6030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x128) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x703;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x7030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x150) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x803;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x8030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x178) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x903;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x9030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x1a0) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0xa03;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0xa030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x1c8) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0xb03;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0xb030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x1f0) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0xc03;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0xc030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x218) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0xd03;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0xd030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x240) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0xe03;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0xe030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x268) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0xf03;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0xf030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x290) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x1003;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x10030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x2b8) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x1103;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x11030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x2e0) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x1203;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x12030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x308) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x1303;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x13030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x330) != '\0') {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x1403;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x14030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    iVar8 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x2a0) = *(int *)(iVar5 + 0x2a0) + 1;
  }
  if (*(char *)(iVar8 + 0x358) == '\0') {
    uVar6 = *(uint *)(iVar5 + 0x2a0);
  }
  else {
    bVar1 = !bVar1;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff0000 | 0x1503;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff0000 | 0xf688;
    }
    else {
      iVar8 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) & 0xffff | 0x15030000;
      *(uint *)(iVar8 + 0x270) = *(uint *)(iVar8 + 0x270) & 0xffff | 0xf6880000;
    }
    uVar6 = *(int *)(iVar5 + 0x2a0) + 1;
    *(uint *)(iVar5 + 0x2a0) = uVar6;
  }
  if (uVar6 < 2) {
    *(uint *)(iVar5 + 0x234) = *(uint *)(iVar5 + 0x234) | 2;
    *(uint *)(iVar5 + 0x238) =
         (*(uint *)(iVar5 + 0x238) & 0x7f) + 4 & 0x7f | *(uint *)(iVar5 + 0x238) & 0xffffff80;
    *(uint *)(iVar5 + 0x244) = *(uint *)(iVar5 + 0x244) & 0x2000ffff | 0x21030000;
    *(uint *)(iVar5 + 0x2a0) = uVar6 + 1;
    *(uint *)(iVar5 + 0x270) = *(uint *)(iVar5 + 0x270) & 0xffff | 0xf6880000;
  }
  else {
    if (bVar1) {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x244) = *(uint *)(iVar8 + 0x244) | 0x2000;
    }
    else {
      iVar8 = uVar7 * 4 + iVar5;
      *(uint *)(iVar8 + 0x240) = *(uint *)(iVar8 + 0x240) | 0x20000000;
    }
    if (0x10 < *(uint *)(iVar5 + 0x2a0)) {
      *(undefined1 *)(param_2 + 4) = 0;
    }
  }
  uVar7 = param_2[0x1b];
  if ((((uVar7 & 0xffffff) == 0) && (*(char *)(param_2 + 0x1c) == '\0')) &&
     (*(char *)((int)param_2 + 0x7a) == '\0')) {
    iVar8 = *(int *)(iVar5 + 0x2a8);
  }
  else {
    iVar8 = *(int *)(iVar5 + 0x2a8) + 1;
    *(uint *)(iVar5 + 0x23c) = *(uint *)(iVar5 + 0x23c) | 2;
    *(int *)(iVar5 + 0x2a8) = iVar8;
    uVar7 = param_2[0x1b];
  }
  if ((((uVar7 & 0xffff) != 0) || (*(char *)(param_2 + 0x1c) != '\0')) ||
     (*(char *)((int)param_2 + 0x7a) != '\0')) {
    iVar8 = iVar8 + 1;
    *(int *)(iVar5 + 0x2a8) = iVar8;
    *(uint *)(iVar5 + 0x23c) = *(uint *)(iVar5 + 0x23c) | 4;
  }
  if ((*(char *)((int)param_2 + 0x6f) != '\0') || (*(char *)(param_2 + 0x1c) != '\0')) {
    iVar8 = iVar8 + 2;
    *(int *)(iVar5 + 0x2a8) = iVar8;
    *(uint *)(iVar5 + 0x23c) = *(uint *)(iVar5 + 0x23c) | 0x18;
  }
  if (*(char *)((int)param_2 + 0x79) != '\0') {
    iVar8 = iVar8 + 1;
    *(int *)(iVar5 + 0x2a8) = iVar8;
    *(uint *)(iVar5 + 0x23c) = *(uint *)(iVar5 + 0x23c) | 0x10000;
  }
  uVar7 = 0;
  iVar9 = 8;
  do {
    bVar2 = *(byte *)((int)param_2 + 0x71);
    if (bVar2 != 0) {
      iVar4 = 4;
      if ((bVar2 & 8) == 0) {
        iVar4 = 3 - (uint)((bVar2 & 4) == 0);
      }
      uVar6 = iVar4 << (uVar7 & 0x3f);
      iVar8 = iVar8 + 1;
      *(int *)(iVar5 + 0x2a8) = iVar8;
      *(uint *)(iVar5 + 0x240) = uVar6 | *(uint *)(iVar5 + 0x240);
      *(uint *)(iVar5 + 0x29c) = uVar6 | *(uint *)(iVar5 + 0x29c);
    }
    param_2 = (int *)((int)param_2 + 1);
    uVar7 = uVar7 + 3;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  if (iVar8 == 1) {
    *(undefined4 *)(iVar5 + 0x2a8) = 2;
    *(uint *)(iVar5 + 0x240) = *(uint *)(iVar5 + 0x240) & 0xff1fffff | 0x800000;
    *(uint *)(iVar5 + 0x29c) = *(uint *)(iVar5 + 0x29c) & 0xff1fffff | 0x800000;
    return;
  }
  return;
}

/* FUN_000640f0 @ 0x640f0 (220 bytes) */
int FUN_000640f0(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = (param_3 + -1) * 0x10000;
  switch(param_2) {
  default:
    return 0;
  case 2:
    return uVar1 | 0x8c8;
  case 3:
    return uVar1 | 0x8cc;
  case 4:
    return uVar1 | 0x8d0;
  case 5:
    return uVar1 | 0x8d4;
  case 6:
    return uVar1 | 0x8d8;
  case 7:
    return uVar1 | 0x8dc;
  case 8:
    return uVar1 | 0x8e0;
  case 9:
    return uVar1 | 0x8e4;
  case 10:
    return uVar1 | 0x8e8;
  case 0xb:
    return uVar1 | 0x8ec;
  case 0xc:
    return uVar1 | 0x8f0;
  case 0xd:
    return uVar1 | 0x8f4;
  case 0xe:
    return uVar1 | 0x8f8;
  case 0xf:
    return uVar1 | 0x8fc;
  case 0x10:
    return uVar1 | 0x900;
  case 0x11:
    return uVar1 | 0x904;
  case 0x13:
    return uVar1 | 0x90c;
  case 0x14:
    return uVar1 | 0x910;
  case 0x15:
    return uVar1 | 0x914;
  }
}

/* FUN_00064230 @ 0x64230 (1256 bytes) */
int FUN_00064230(param_1, param_2)
  int param_1;
  int *param_2;
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  bool bVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  iVar13 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  puVar4 = *(uint **)(((unsigned char *)0x00001384) + iVar13);
  iVar3 = *(int *)(iVar13 + 0x150);
  if (puVar4 == (uint *)0x0) {
    puVar4 = (uint *)(**(code **)(param_1 + 0xc))(0x7c);
    *(uint **)(((unsigned char *)0x00001384) + iVar13) = puVar4;
  }
  uVar9 = puVar4[5];
  puVar4[3] = 0;
  puVar4[4] = 0;
  iVar8 = 0;
  puVar4[1] = 4;
  puVar4[2] = 1;
  uVar2 = puVar4[0x10];
  puVar4[5] = uVar9 & 0xffffff00 | 3;
  uVar10 = *(uint *)(((unsigned char *)0x000055e8) + iVar3);
  puVar4[0x10] = uVar2 & 0xfffff000 | 0x688;
  puVar4[5] = (uVar10 & 0x1f) << 8 | uVar9 & 0xffff0000 | 3;
  if (*(int *)(((unsigned char *)0x000055e8) + iVar3) != 0x16) {
    iVar8 = 0xf;
  }
  *puVar4 = 1;
  iVar14 = 0;
  bVar7 = true;
  puVar4[0x1b] = 1;
  puVar4[0x1d] = 1;
  puVar4[0x10] = iVar8 << 0xc | uVar2 & 0xffff0000 | 0x688;
  puVar5 = &DAT_001dbab8;
  iVar12 = 1;
  iVar15 = 0x15;
  iVar8 = iVar13;
  do {
    if (0 < *(int *)(iVar8 + 100)) {
      iVar11 = *(int *)(iVar8 + 0xbc);
      puVar4[1] = (puVar4[1] & 0x7f) + 4 & 0x7f | puVar4[1] & 0xffffff80;
      if (bVar7) {
        iVar6 = 0;
        iVar11 = iVar11 * 4 + iVar3 + 0x24;
        uVar2 = puVar4[iVar14 + 5];
        puVar4[iVar14 + 5] = uVar2 & 0xff00ffff | 0x30000;
        puVar4[iVar14 + 5] =
             (*(uint *)(((unsigned char *)0x000055c4) + iVar11) & 0x1f) << 0x18 | uVar2 & 0xffff | 0x30000;
        puVar4[iVar14 + 0x10] = puVar4[iVar14 + 0x10] & 0xf000ffff | 0x6880000;
        if (*(int *)(((unsigned char *)0x000055c4) + iVar11) != 0x16) {
          iVar6 = 0xf;
        }
        bVar7 = false;
        puVar4[iVar14 + 0x10] = iVar6 << 0x1c | puVar4[iVar14 + 0x10] & 0xfffffff;
        iVar14 = iVar14 + 1;
      }
      else {
        iVar6 = 0;
        iVar11 = iVar11 * 4 + iVar3 + 0x24;
        uVar2 = puVar4[iVar14 + 5];
        puVar4[iVar14 + 5] = uVar2 & 0xffffff00 | 3;
        puVar4[iVar14 + 5] =
             (*(uint *)(((unsigned char *)0x000055c4) + iVar11) & 0x1f) << 8 | uVar2 & 0xffff0000 | 3;
        puVar4[iVar14 + 0x10] = puVar4[iVar14 + 0x10] & 0xfffff000 | 0x688;
        if (*(int *)(((unsigned char *)0x000055c4) + iVar11) != 0x16) {
          iVar6 = 0xf;
        }
        bVar7 = true;
        puVar4[iVar14 + 0x10] = iVar6 << 0xc | puVar4[iVar14 + 0x10] & 0xffff0fff;
      }
      iVar12 = iVar12 + 1;
      uVar2 = puVar4[0x1b] + 1;
      puVar4[0x1b] = uVar2;
      *puVar4 = *puVar4 | *puVar5;
      if (iVar12 == *(int *)(iVar13 + 0x110)) goto LAB_000644c0;
    }
    iVar8 = iVar8 + 4;
    puVar5 = puVar5 + 1;
    iVar15 = iVar15 + -1;
  } while (iVar15 != 0);
  uVar2 = puVar4[0x1b];
LAB_000644c0:
  if (uVar2 < 2) {
    *puVar4 = *puVar4 | 2;
    puVar4[1] = (puVar4[1] & 0x7f) + 4 & 0x7f | puVar4[1] & 0xffffff80;
    puVar4[5] = puVar4[5] & 0x2000ffff | 0x21030000;
    puVar4[0x1b] = uVar2 + 1;
    puVar4[0x10] = puVar4[0x10] & 0xffff | 0xf6880000;
  }
  else {
    if (bVar7) {
      puVar4[iVar14 + 5] = puVar4[iVar14 + 5] | 0x2000;
    }
    else {
      puVar4[iVar14 + 4] = puVar4[iVar14 + 4] | 0x20000000;
    }
    if (0x10 < puVar4[0x1b]) {
      *(undefined1 *)(param_2 + 4) = 0;
    }
  }
  uVar2 = param_2[0x1b];
  if ((((uVar2 & 0xffffff) != 0) || (*(char *)(param_2 + 0x1c) != '\0')) ||
     (((unsigned char *)0x000013c8)[iVar13] != '\0')) {
    puVar4[2] = puVar4[2] | 2;
    puVar4[0x1d] = puVar4[0x1d] + 1;
    uVar2 = param_2[0x1b];
  }
  if ((((uVar2 & 0xffff) != 0) || (*(char *)(param_2 + 0x1c) != '\0')) ||
     (((unsigned char *)0x000013c8)[iVar13] != '\0')) {
    puVar4[2] = puVar4[2] | 4;
    puVar4[0x1d] = puVar4[0x1d] + 1;
  }
  if ((*(char *)((int)param_2 + 0x6f) != '\0') || (*(char *)(param_2 + 0x1c) != '\0')) {
    puVar4[2] = puVar4[2] | 0x18;
    puVar4[0x1d] = puVar4[0x1d] + 2;
  }
  if (*(char *)((int)param_2 + 0x79) != '\0') {
    puVar4[2] = puVar4[2] | 0x10000;
    puVar4[0x1d] = puVar4[0x1d] + 1;
  }
  uVar2 = 0;
  iVar13 = 8;
  do {
    bVar1 = *(byte *)((int)param_2 + 0x71);
    if (bVar1 != 0) {
      iVar8 = 4;
      if ((bVar1 & 8) == 0) {
        iVar8 = 3 - (uint)((bVar1 & 4) == 0);
      }
      uVar9 = iVar8 << (uVar2 & 0x3f);
      puVar4[3] = uVar9 | puVar4[3];
      puVar4[4] = uVar9 | puVar4[4];
      puVar4[0x1d] = puVar4[0x1d] + 1;
    }
    param_2 = (int *)((int)param_2 + 1);
    uVar2 = uVar2 + 3;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  puVar4[2] = *(uint *)(((unsigned char *)0x00005498) + iVar3);
  uVar9 = *(uint *)(((unsigned char *)0x0000549c) + iVar3);
  puVar4[3] = uVar9;
  uVar2 = *(uint *)(((unsigned char *)0x00005434) + iVar3);
  puVar4[0x1d] = uVar2;
  if (uVar2 == 1) {
    puVar4[0x1d] = 2;
    puVar4[3] = uVar9 & 0xff1fffff | 0x800000;
    puVar4[4] = puVar4[4] & 0xff1fffff | 0x800000;
  }
  return;
}

/* FUN_00064720 @ 0x64720 (304 bytes) */
int FUN_00064720(param_1)
  int param_1;
{
  undefined4 *puVar1;
  byte bVar2;
  int iVar3;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  int a5;
  int iVar4;
  undefined4 a6;
  uint uVar5;
  code *a7;
  int iVar6;
  
  a5 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + **(int **)(((unsigned char *)0x00001168) + param_1));
  if (*(char *)(*(int **)(((unsigned char *)0x00001168) + param_1) + 4) != '\0') {
    if ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0) {
      *(undefined4 *)(param_1 + 0x1ca0) = *(undefined4 *)(a5 + 0x234);
      *(undefined4 *)(param_1 + 0x1ca4) = *(undefined4 *)(a5 + 0x238);
      *(undefined4 *)(param_1 + 0x1b9c) = *(undefined4 *)(a5 + 0x23c);
      *(undefined4 *)(param_1 + 0x1ba0) = *(undefined4 *)(a5 + 0x240);
      iVar3 = *(int *)(a5 + 0x2a0);
      if (iVar3 + 1U >> 1 != 0) {
        uVar5 = 0;
        iVar4 = param_1;
        iVar6 = a5;
        do {
          uVar5 = uVar5 + 1;
          *(undefined4 *)(iVar4 + 0x1be4) = *(undefined4 *)(iVar6 + 0x244);
          puVar1 = (undefined4 *)(iVar6 + 0x270);
          iVar6 = iVar6 + 4;
          *(undefined4 *)(iVar4 + 0x1c04) = *puVar1;
          iVar4 = iVar4 + 4;
          iVar3 = *(int *)(a5 + 0x2a0);
        } while (uVar5 < iVar3 + 1U >> 1);
      }
      *(int *)(param_1 + 0x2438) = iVar3;
      a7 = *(code **)(((unsigned char *)0x00001334) + param_1);
      a6 = *(undefined4 *)(a5 + 0x2a0);
      *(undefined4 *)(param_1 + 0x1b78) = 0;
      *(undefined4 *)(param_1 + 0x243c) = a6;
      bVar2 = *(byte *)(a5 + 0x36);
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x40000;
      *(uint *)(param_1 + 0x1b78) = bVar2 & 3;
      (*a7)(param_1,1,in_r5,in_r6,in_r7,a5,a6,a7);
      *(undefined1 *)(param_1 + 0x2435) = 1;
    }
  }
  return;
}

/* FUN_00064850 @ 0x64850 (436 bytes) */
int FUN_00064850(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  
  piVar5 = *(int **)(((unsigned char *)0x00001168) + param_1);
  puVar6 = *(undefined4 **)
            (((unsigned char *)0x00001384) + **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *piVar5));
  if ((*(char *)(piVar5 + 4) != '\0') && ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0)) {
    if ((*(int *)(param_1 + 0x1b9c) != puVar6[2]) ||
       (bVar4 = false, *(int *)(param_1 + 0x1ba0) != puVar6[3])) {
      bVar4 = true;
    }
    *(undefined4 *)(param_1 + 0x1ca0) = *puVar6;
    *(undefined4 *)(param_1 + 0x1ca4) = puVar6[1];
    *(undefined4 *)(param_1 + 0x1b9c) = puVar6[2];
    *(undefined4 *)(param_1 + 0x1ba0) = puVar6[3];
    iVar2 = puVar6[0x1b];
    if (iVar2 + 1U >> 1 != 0) {
      uVar8 = 0;
      iVar7 = param_1;
      puVar9 = puVar6;
      do {
        uVar8 = uVar8 + 1;
        *(undefined4 *)(iVar7 + 0x1be4) = puVar9[5];
        puVar1 = puVar9 + 0x10;
        puVar9 = puVar9 + 1;
        *(undefined4 *)(iVar7 + 0x1c04) = *puVar1;
        iVar7 = iVar7 + 4;
        iVar2 = puVar6[0x1b];
      } while (uVar8 < iVar2 + 1U >> 1);
    }
    *(int *)(param_1 + 0x2438) = iVar2;
    uVar3 = puVar6[0x1b];
    *(undefined4 *)(param_1 + 0x1b78) = 0;
    *(undefined4 *)(param_1 + 0x243c) = uVar3;
    if ((piVar5[0xc] & 1U) != 0) {
      *(undefined4 *)(param_1 + 0x1b78) = 1;
    }
    iVar2 = *(int *)(((unsigned char *)0x0000148c) + param_1);
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x40000;
    if (iVar2 != 0) {
      iVar2 = *(int *)(iVar2 + 0x14);
      if (((*(int *)(param_1 + 0x1b50) != *(int *)(iVar2 + 0x5658)) ||
          (iVar7 = *(int *)(param_1 + 0x1ba4), iVar7 != *(int *)(iVar2 + 0x5650))) || (bVar4)) {
        (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,1);
        *(undefined4 *)(iVar2 + 0x5650) = *(undefined4 *)(param_1 + 0x1ba4);
        *(undefined4 *)(iVar2 + 0x5658) = *(undefined4 *)(param_1 + 0x1b50);
        iVar7 = *(int *)(param_1 + 0x1ba4);
      }
      *(int *)(iVar2 + 0x5650) = iVar7;
      *(undefined4 *)(iVar2 + 0x5658) = *(undefined4 *)(param_1 + 0x1b50);
    }
    *(undefined1 *)(param_1 + 0x2435) = 1;
  }
  return;
}

/* FUN_00064a10 @ 0x64a10 (1304 bytes) */
int FUN_00064a10(param_1, param_2)
  int param_1;
  int *param_2;
{
  code *pcVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  undefined8 *puVar4;
  char *in_r5;
  undefined8 *puVar5;
  undefined4 in_r6;
  undefined4 in_r7;
  int in_r8;
  int iVar6;
  int iVar7;
  undefined8 *puVar8;
  int iVar9;
  int iVar10;
  char cVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  undefined4 *puVar16;
  uint uVar17;
  int *piVar18;
  uint uVar19;
  int *piVar20;
  char *pcVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  undefined8 uVar28;
  
  if (*param_2 != 0) {
    piVar20 = *(int **)(((unsigned char *)0x000011b4) + param_1);
    puVar16 = *(undefined4 **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    pcVar21 = (char *)*puVar16;
    uVar17 = *(uint *)(pcVar21 + 0x18);
    uVar19 = *(uint *)(pcVar21 + 0x5c);
    if ((*(char *)(param_2 + 4) != '\0') && ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0)) {
      if (*pcVar21 != '\0') {
LAB_00064c00:
        if (uVar19 != 0) {
          if (*(int *)(pcVar21 + 0x2b8) == 0) {
            iVar6 = puVar16[0x22];
            iVar9 = param_2[8];
            piVar18 = *(int **)(pcVar21 + 0x220) + *(int *)(pcVar21 + 0x224);
            piVar20 = *(int **)(pcVar21 + 0x220);
            while (piVar20 + 4 <= piVar18) {
              iVar12 = iVar9 + *piVar20 * 0x54;
              iVar10 = iVar9 + piVar20[3] * 0x54;
              iVar7 = iVar9 + piVar20[1] * 0x54;
              iVar13 = iVar9 + piVar20[2] * 0x54;
              puVar5 = *(undefined8 **)(iVar12 + 0x38);
              puVar4 = *(undefined8 **)(iVar7 + 0x38);
              puVar2 = *(undefined8 **)(iVar13 + 0x38);
              puVar8 = *(undefined8 **)(iVar10 + 0x38);
              uVar22 = puVar5[1];
              iVar12 = *(int *)(iVar12 + 4) * 0x10;
              uVar24 = puVar2[1];
              uVar25 = puVar4[1];
              uVar23 = puVar8[1];
              uVar28 = *puVar4;
              in_r8 = *(int *)(iVar7 + 4) * 0x10;
              uVar27 = *puVar2;
              uVar26 = *puVar8;
              iVar7 = *(int *)(iVar13 + 4) * 0x10;
              iVar10 = *(int *)(iVar10 + 4) * 0x10;
              *(undefined8 *)(iVar6 + iVar12) = *puVar5;
              *(undefined8 *)(iVar6 + iVar12 + 8) = uVar22;
              *(undefined8 *)(iVar6 + in_r8) = uVar28;
              *(undefined8 *)(iVar6 + in_r8 + 8) = uVar25;
              *(undefined8 *)(iVar6 + iVar7) = uVar27;
              *(undefined8 *)(iVar6 + iVar7 + 8) = uVar24;
              *(undefined8 *)(iVar6 + iVar10) = uVar26;
              *(undefined8 *)(iVar6 + iVar10 + 8) = uVar23;
              piVar20 = piVar20 + 4;
            }
            for (; piVar20 < piVar18; piVar20 = piVar20 + 1) {
              iVar12 = iVar9 + *piVar20 * 0x54;
              puVar2 = *(undefined8 **)(iVar12 + 0x38);
              uVar22 = puVar2[1];
              iVar12 = *(int *)(iVar12 + 4) * 0x10;
              *(undefined8 *)(iVar6 + iVar12) = *puVar2;
              *(undefined8 *)(iVar6 + iVar12 + 8) = uVar22;
            }
          }
          puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
          *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3;
          *puVar3 = 0x8a1;
          *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) = 0;
          iVar6 = *(int *)(FUN_00002748 + param_1 + 4);
          pcVar1 = *(code **)(param_1 + 0x275c);
          *(int *)(FUN_00002748 + param_1 + 4) = iVar6 + 8;
          (*pcVar1)(param_1,iVar6 + 8);
          in_r6 = puVar16[0x22];
          in_r7 = 1;
          in_r5 = pcVar21;
          ((int (*)())FUN_00061eb0)(param_1,param_2,pcVar21,in_r6,1);
        }
        uVar14 = *(uint *)(param_1 + 0x1b90);
        cVar11 = '\0';
        uVar19 = *(uint *)(pcVar21 + 4) & 0x3ff;
        *(uint *)(param_1 + 0x1b90) = uVar19 | uVar14 & 0xfffffc00;
        uVar17 = (*(int *)(pcVar21 + 4) + *(int *)(pcVar21 + 8)) * 0x400 & 0xffc00;
        *(uint *)(param_1 + 0x1b90) = uVar17 | uVar19 | uVar14 & 0xfff00000;
        *(uint *)(param_1 + 0x1b90) =
             (*(uint *)(pcVar21 + 0x10) & 0x3ff) << 0x14 | uVar17 | uVar19 | uVar14 & 0xc0000000;
        *(uint *)(param_1 + 0x1b94) =
             *(int *)(pcVar21 + 4) + *(int *)(pcVar21 + 0xc) & 0x3ffU |
             *(uint *)(param_1 + 0x1b94) & 0xfffffc00;
        *(char *)(param_1 + 0x1b8f) = (char)*(undefined4 *)(pcVar21 + 0x14);
        if (*(int *)(pcVar21 + 0x5c) != 0) {
          cVar11 = (char)*(int *)(pcVar21 + 0x5c) + -1;
        }
        *(char *)(param_1 + 0x1b8d) = cVar11;
        puVar16 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
        *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar16;
        *puVar16 = 0x208b4;
        *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) =
             *(undefined4 *)(param_1 + 0x1b90);
        *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 8) =
             *(undefined4 *)(param_1 + 0x1b8c);
        *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 0xc) =
             *(undefined4 *)(param_1 + 0x1b94);
        iVar6 = *(int *)(FUN_00002748 + param_1 + 4);
        pcVar1 = *(code **)(param_1 + 0x275c);
        *(int *)(FUN_00002748 + param_1 + 4) = iVar6 + 0x10;
        (*pcVar1)(param_1,iVar6 + 0x10,in_r5,in_r6,in_r7,in_r8,pcVar1);
        puVar16 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
        *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar16;
        *puVar16 = 0x8b7;
        iVar9 = *(int *)(FUN_00002748 + param_1 + 4);
        *(undefined4 *)(iVar9 + 4) = *(undefined4 *)(param_1 + 0x1b98);
        iVar6 = *(int *)(FUN_00002748 + param_1 + 4);
        pcVar1 = *(code **)(param_1 + 0x275c);
        *(int *)(FUN_00002748 + param_1 + 4) = iVar6 + 8;
        (*pcVar1)(param_1,iVar6 + 8,in_r5,in_r6,in_r7,in_r8,iVar9);
        FUN_00050ef0(param_1,*(undefined4 *)(pcVar21 + 0x2a4),*(undefined4 *)(pcVar21 + 0x2a8),
                     *(undefined4 *)(pcVar21 + 0x2ac));
        ((int (*)())FUN_00064720)(param_1);
        return;
      }
      uVar15 = 0;
      uVar14 = 0;
      iVar9 = *piVar20;
      iVar6 = *(int *)(param_1 + 0xd8);
      iVar12 = piVar20[1] - *(int *)(param_1 + 0x2448);
LAB_00064a98:
      if (iVar6 == 1) goto LAB_00064ac0;
      if (iVar6 == 0) {
        uVar15 = 0x80 - iVar9;
        uVar14 = 0x80 - iVar12;
        goto LAB_00064af0;
      }
      if (iVar6 != 2) goto LAB_00064af0;
      do {
        uVar15 = 0x100 - iVar9;
        uVar14 = 0x100 - iVar12;
        *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x48000;
LAB_00064af0:
        while( true ) {
          if ((uVar17 <= uVar15) && (uVar19 <= uVar14)) {
            *(int *)(pcVar21 + 0x14) = iVar12;
            *(int *)(pcVar21 + 4) = iVar9;
            *(uint *)(pcVar21 + 0x10) = uVar17 + iVar9 + -1;
            *piVar20 = uVar17 + *piVar20;
            piVar20[1] = uVar19 + piVar20[1];
            ((int (*)())FUN_00061dc0)(param_1,pcVar21);
            *pcVar21 = '\x01';
            FUN_0007dcd0(param_1,pcVar21);
            uVar19 = *(uint *)(pcVar21 + 0x5c);
            goto LAB_00064c00;
          }
          if (iVar6 == 1) break;
          if (iVar6 != 0) {
            if (iVar6 == 2) {
              puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
              *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3;
              *puVar3 = 0x8a1;
              *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) = 0;
              pcVar1 = *(code **)(param_1 + 0x275c);
              iVar6 = *(int *)(FUN_00002748 + param_1 + 4) + 8;
              *(int *)(FUN_00002748 + param_1 + 4) = iVar6;
              (*pcVar1)(param_1,iVar6,in_r5,in_r6,in_r7,in_r8,iVar6);
              *piVar20 = 0;
              piVar20[1] = *(int *)(param_1 + 0x2448);
              ((int (*)())FUN_00062490)(param_1);
              iVar6 = *(int *)(param_1 + 0xd8);
              iVar9 = 0;
              iVar12 = 0;
            }
            goto LAB_00064a98;
          }
          iVar6 = 1;
          *(undefined4 *)(param_1 + 0xd8) = 1;
LAB_00064ac0:
          uVar15 = 0xfe - iVar9;
          uVar14 = 0x100 - iVar12;
          *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000;
        }
        iVar6 = 2;
        *(undefined4 *)(param_1 + 0xd8) = 2;
      } while( true );
    }
  }
  return;
}

/* FUN_00064f40 @ 0x64f40 (708 bytes) */
int FUN_00064f40(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  byte *pbVar1;
  byte bVar2;
  code *pcVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  bool bVar7;
  int *piVar8;
  int *piVar9;
  undefined4 *puVar10;
  int iVar11;
  
  if ((*(uint *)(param_1 + 0x44) & 0x100000) == 0) {
    iVar6 = param_1 + 0x18a0;
    iVar11 = 0x10;
    do {
      *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) & 0xfffffffe;
      iVar6 = iVar6 + 8;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  else {
    piVar9 = *(int **)(((unsigned char *)0x00001168) + param_1);
    if (((*(byte *)(param_1 + 0x2d) & 8) != 0) && ((*(uint *)(param_1 + 0x8c) & 0x10000) != 0)) {
      puVar10 = *(undefined4 **)(((unsigned char *)0x000011b4) + param_1);
      puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
      *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar4;
      *puVar4 = 0x8a1;
      *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) = 0;
      pcVar3 = *(code **)(param_1 + 0x275c);
      iVar6 = *(int *)(FUN_00002748 + param_1 + 4) + 8;
      *(int *)(FUN_00002748 + param_1 + 4) = iVar6;
      (*pcVar3)(param_1,iVar6,in_r5,in_r6,in_r7,in_r8,iVar6);
      *puVar10 = 0;
      puVar10[1] = *(undefined4 *)(param_1 + 0x2448);
      ((int (*)())FUN_00062490)(param_1);
      *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0xfffeffff;
    }
    if (*(char *)(piVar9 + 4) != '\0') {
      iVar11 = *(int *)(((unsigned char *)0x0000118c) + param_1);
      piVar8 = *(int **)(iVar11 * 4 + *piVar9);
      iVar6 = *piVar8;
      uVar5 = ((int (*)())FUN_00062120)(param_1,piVar9,iVar6);
      if ((*(char *)(param_1 + 0x31) == '\0') ||
         (bVar7 = true, *(char *)(piVar9[1] + iVar11) == '\0')) {
        bVar7 = false;
      }
      if (((uVar5 != *(uint *)(iVar6 + 0x48)) || (*(int *)(iVar6 + 0x18) != piVar9[0x15])) ||
         (bVar7)) {
        for (iVar6 = piVar8[(uVar5 & 0x1f) + 1]; iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x2b4)) {
          if (*(uint *)(iVar6 + 0x48) == uVar5) {
            if (!bVar7) {
              *piVar8 = iVar6;
              piVar9[0x15] = *(int *)(iVar6 + 0x18);
              *(undefined4 *)(((unsigned char *)0x00001174) + param_1) = *(undefined4 *)(iVar6 + 0x18);
              goto LAB_00065094;
            }
            break;
          }
        }
        FUN_000546d0(param_1,piVar9);
LAB_00065094:
        *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 3;
      }
      else {
        bVar2 = *(byte *)(param_1 + 0x2d);
        if ((bVar2 & 4) == 0) {
          if ((bVar2 & 3) == 0) {
            return;
          }
          puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
          *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar4;
          *puVar4 = 0x8a1;
          *(uint *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) = bVar2 & 4;
          iVar11 = *(int *)(FUN_00002748 + param_1 + 4);
          pcVar3 = *(code **)(param_1 + 0x275c);
          *(int *)(FUN_00002748 + param_1 + 4) = iVar11 + 8;
          (*pcVar3)(param_1,iVar11 + 8);
          ((int (*)())FUN_00061eb0)(param_1,piVar9,iVar6,piVar8[0x22],0);
          return;
        }
      }
      ((int (*)())FUN_00064a10)(param_1,piVar9);
      iVar6 = param_1 + 0x18a0;
      iVar11 = 0x10;
      do {
        pbVar1 = (byte *)((int)piVar9 + 0x71);
        piVar9 = (int *)((int)piVar9 + 1);
        *(uint *)(iVar6 + 8) = -(uint)*pbVar1 >> 0x1f | *(uint *)(iVar6 + 8) & 0xfffffffe;
        iVar6 = iVar6 + 8;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      return;
    }
  }
  return;
}

/* FUN_000651e0 @ 0x651e0 (400 bytes) */
int FUN_000651e0(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  code *pcVar3;
  int a6;
  char *pcVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  for (puVar5 = *(undefined4 **)(*(int *)(((unsigned char *)0x000011b4) + param_1) + 8); puVar5 != (undefined4 *)0x0
      ; puVar5 = (undefined4 *)puVar5[1]) {
    ((int (*)())FUN_00061dc0)(param_1,*puVar5);
  }
  piVar6 = *(int **)(((unsigned char *)0x00001168) + param_1);
  puVar5 = *(undefined4 **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *piVar6);
  pcVar4 = (char *)*puVar5;
  if ((*(char *)(piVar6 + 4) != '\0') && (*pcVar4 != '\0')) {
    puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar2;
    *puVar2 = 0x208b4;
    *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) = *(undefined4 *)(param_1 + 0x1b90);
    *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 8) = *(undefined4 *)(param_1 + 0x1b8c);
    *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 0xc) = *(undefined4 *)(param_1 + 0x1b94);
    iVar1 = *(int *)(FUN_00002748 + param_1 + 4);
    pcVar3 = *(code **)(param_1 + 0x275c);
    *(int *)(FUN_00002748 + param_1 + 4) = iVar1 + 0x10;
    (*pcVar3)(param_1,iVar1 + 0x10,in_r5,in_r6,in_r7,in_r8,pcVar3);
    puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar2;
    *puVar2 = 0x8b7;
    a6 = *(int *)(FUN_00002748 + param_1 + 4);
    *(undefined4 *)(a6 + 4) = *(undefined4 *)(param_1 + 0x1b98);
    iVar1 = *(int *)(FUN_00002748 + param_1 + 4);
    pcVar3 = *(code **)(param_1 + 0x275c);
    *(int *)(FUN_00002748 + param_1 + 4) = iVar1 + 8;
    (*pcVar3)(param_1,iVar1 + 8,in_r5,in_r6,in_r7,in_r8,a6);
    FUN_00050ef0(param_1,*(undefined4 *)(pcVar4 + 0x2a4),*(undefined4 *)(pcVar4 + 0x2a8),
                 *(undefined4 *)(pcVar4 + 0x2ac));
    ((int (*)())FUN_00061eb0)(param_1,piVar6,pcVar4,puVar5[0x22],1);
  }
  *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0xfffeffff;
  return;
}

/* FUN_00065370 @ 0x65370 (636 bytes) */
int FUN_00065370(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 in_r5;
  uint in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar4;
  code *a6;
  undefined4 in_r10;
  undefined8 uVar5;
  undefined4 local_38;
  undefined4 local_34 [8];
  
  cVar1 = *(char *)(param_1 + 0x29);
  if (*(char *)(param_1 + 0x1868) == '\0') {
    (**(code **)(((unsigned char *)0x000012e0) + param_1))(param_1);
    return;
  }
  *(undefined1 *)(param_1 + 0x126) = 0;
  (**(code **)(((unsigned char *)0x0000133c) + param_1))(param_1);
  if (cVar1 == '\0') {
    iVar4 = *(int *)(param_1 + 0x13c);
    if (iVar4 == *(int *)(param_1 + 0x140)) {
      iVar2 = *(int *)(param_1 + 0x148);
      if (iVar2 == *(int *)(param_1 + 0x144)) {
        return;
      }
    }
    else {
      iVar2 = *(int *)(param_1 + 0x148);
    }
  }
  else {
    iVar4 = *(int *)(param_1 + 0x13c);
    iVar2 = *(int *)(param_1 + 0x148);
  }
  *(int *)(param_1 + 0x140) = iVar4;
  *(int *)(param_1 + 0x144) = iVar2;
  if (*(char *)(param_1 + 0x124) != '\0') {
LAB_00065500:
    (**(code **)(((unsigned char *)0x000012dc) + param_1))(param_1);
    return;
  }
  if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
    return;
  }
  uVar5 = FUN_0009edd0(param_1,param_1 + 0x1874);
  iVar2 = (int)((ulonglong)uVar5 >> 0x20);
  uVar3 = (undefined4)uVar5;
  if (iVar2 == 0) {
    FUN_0009d080(param_1,uVar3,in_r5,in_r6,in_r7,in_r8);
    uVar3 = FUN_0009bd00(param_1);
    (**(code **)(((unsigned char *)0x000012b4) + param_1))(param_1);
    in_r5 = FUN_0009d410(param_1,1,&local_38,local_34,uVar3,in_r8,iVar4,in_r10);
    in_r6 = (uint)*(byte *)(param_1 + 0x131);
    uVar5 = FUN_0009c800(param_1,param_1 + 0x1874,in_r5,in_r6,local_38,local_34[0],uVar3,
                         (uint)*(byte *)(param_1 + 0x126));
    iVar2 = (int)((ulonglong)uVar5 >> 0x20);
    in_r7 = local_38;
    in_r8 = local_34[0];
    if (*(char *)(param_1 + 0x126) != '\0') {
      a6 = *(code **)(((unsigned char *)0x0000133c) + param_1);
      *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000000;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1020;
      *(undefined1 *)(param_1 + 0x29) = 1;
      (*a6)(param_1,(int)uVar5,in_r5,in_r6,local_38,local_34[0],a6);
      goto LAB_00065500;
    }
  }
  else if (*(char *)(iVar2 + 0x59) != '\0') goto LAB_0006559c;
  *(int *)(param_1 + 0x14c) = iVar2;
  (**(code **)(((unsigned char *)0x000012c4) + param_1))(param_1,iVar2);
  if (*(int *)(iVar2 + 0x54) + 0x750 == *(int *)(((unsigned char *)0x0000148c) + param_1)) {
    (**(code **)((int)((unsigned char *)0x000012a0) + param_1))(param_1);
    uVar3 = extraout_r4;
  }
  else {
    in_r5 = *(undefined4 *)(iVar2 + 0x3c);
    (**(code **)((int)((unsigned char *)0x00001294) + param_1))(param_1);
    uVar3 = extraout_r4_00;
  }
  if (*(char *)(*(int *)(iVar2 + 0x54) + 0x752) == '\0') {
    return;
  }
LAB_0006559c:
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1020;
  *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000000;
  *(undefined1 *)(param_1 + 0x126) = 1;
  *(undefined1 *)(param_1 + 0x29) = 1;
  (**(code **)(((unsigned char *)0x0000133c) + param_1))(param_1,uVar3,in_r5,in_r6,in_r7,in_r8,1);
  (**(code **)(((unsigned char *)0x000012dc) + param_1))(param_1);
  return;
}

/* FUN_00065610 @ 0x65610 (152 bytes) */
int FUN_00065610(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  _memset(param_2 + 0x68,0xffffffff,0x3c);
  *(undefined4 *)(param_2 + 0xa0) = 7;
  *(undefined4 *)(param_2 + 0x90) = 3;
  *(undefined4 *)(param_2 + 0x68) = 0;
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 0x8c) = 2;
  *(undefined4 *)(param_2 + 0x88) = 1;
  *(undefined4 *)(param_2 + 0x98) = 5;
  *(undefined4 *)(param_2 + 0x6c) = 0;
  *(undefined4 *)(param_2 + 0x74) = 0;
  *(undefined4 *)(param_2 + 0x7c) = 0;
  *(undefined4 *)(param_2 + 0x70) = 0;
  *(undefined4 *)(param_2 + 0x78) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_2 + 0x94) = 4;
  *(undefined4 *)(param_2 + 0x9c) = 6;
  return;
}

/* FUN_000656b0 @ 0x656b0 (780 bytes) */
int FUN_000656b0(param_1)
  int param_1;
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 in_r7;
  undefined4 in_r8;
  uint in_r9;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined4 local_74;
  uint local_70 [2];
  undefined4 local_68;
  uint local_64;
  
  _memset(local_70,0,0x30);
  uVar8 = *(uint *)(param_1 + 0x44);
  local_68 = *(undefined4 *)(param_1 + 0x1804);
  local_70[0] = local_70[0] | 8;
  if ((uVar8 & 0xc00) != 0) {
    in_r9 = uVar8 >> 9 & 2;
    local_64 = uVar8 >> 0xb & 1 | in_r9 | (uint)(byte)((unsigned char *)0x000011d3)[param_1] << 2;
  }
  iVar11 = *(int *)(param_1 + 0x14c);
  if ((iVar11 == 0) || (iVar3 = _memcmp(iVar11,local_70,0x30), iVar4 = iVar11, iVar3 != 0)) {
    iVar4 = FUN_0009edd0(param_1,local_70);
    if (iVar4 == 0) {
      uVar10 = *(uint *)(param_1 + 0x1804);
      bVar1 = ((unsigned char *)0x000011d2)[param_1];
      uVar8 = *(uint *)(param_1 + 0x44) >> 10 & 1;
      puVar5 = (undefined4 *)FUN_00092bf0(param_1,1,0);
      *puVar5 = 0;
      ((int (*)())FUN_00065610)(param_1,puVar5);
      if (uVar8 == 0) {
        uVar2 = uVar10 >> 3 & 1;
        uVar12 = uVar10 >> 1 & 1;
        uVar9 = 0;
      }
      else {
        uVar2 = uVar10 >> 3 & 1;
        uVar12 = uVar10 >> 1 & 1;
        in_r9 = (uVar10 & 1) + uVar12;
        uVar9 = (uint)bVar1 + uVar2 * 2 + in_r9 + 2;
      }
      FUN_00092d40(puVar5,uVar8,(uint)bVar1);
      if (uVar12 == 0) {
        iVar4 = 1;
        iVar11 = 2;
      }
      else {
        iVar4 = 2;
        iVar11 = 3;
        puVar5[0x13] = 1;
        FUN_00093130(puVar5);
      }
      puVar5[3] = iVar4;
      uVar6 = 0;
      uVar7 = 0;
      FUN_00092ea0(puVar5,3,0,0);
      if ((uVar10 & 1) != 0) {
        puVar5[4] = iVar11;
        uVar6 = 1;
        uVar7 = 0;
        FUN_00092ea0(puVar5,4,1,0);
        if ((uVar10 & 4) != 0) {
          puVar5[0x14] = iVar11;
          puVar5[0x15] = 3;
          FUN_000931e0(puVar5);
        }
        iVar11 = iVar4 + 2;
      }
      if (uVar2 != 0) {
        puVar5[5] = iVar11;
        FUN_00092ea0(puVar5,3,2,1);
        puVar5[6] = iVar11 + 1;
        puVar5[0x20] = 0;
        uVar6 = 3;
        uVar7 = 1;
        iVar11 = iVar11 + 2;
        FUN_00092ea0(puVar5,4,3,1);
      }
      uVar8 = (uint)(uVar2 != 0);
      if (uVar10 >> 4 != 0) {
        uVar2 = 0;
        iVar4 = param_1;
        do {
          iVar3 = *(int *)(iVar4 + 0x1824);
          puVar5[iVar3 + 0xb] = iVar11;
          iVar11 = iVar11 + 1;
          if (uVar8 == uVar9) {
            uVar8 = uVar8 + 1;
          }
          puVar5[iVar3 + 0x21] = uVar8;
          uVar2 = uVar2 + 1;
          uVar8 = uVar8 + 1;
          iVar4 = iVar4 + 4;
          FUN_00093000(puVar5,iVar3,uVar6,uVar7,in_r7,in_r8,in_r9);
        } while (uVar10 >> 4 != uVar2);
      }
      FUN_0009a910(puVar5);
      iVar4 = FUN_0009c800(param_1,local_70,puVar5,iVar11,local_74,0,0,1);
      *(undefined4 *)(iVar4 + 0x34) = 0;
      *(int *)(iVar4 + 0x38) = *(int *)(*(int *)(iVar4 + 0x54) + 0x3cc) + -1;
      iVar11 = *(int *)(param_1 + 0x14c);
    }
    else {
      iVar11 = *(int *)(param_1 + 0x14c);
    }
  }
  if (iVar4 != iVar11) {
    *(int *)(param_1 + 0x14c) = iVar4;
    *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000;
  }
  (**(code **)((int)((unsigned char *)0x00001294) + param_1))
            (param_1,*(int *)(iVar4 + 0x54) + 0x750,*(undefined4 *)(iVar4 + 0x3c));
  return;
}

/* FUN_000659d0 @ 0x659d0 (612 bytes) */
void FUN_000659d0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  
  iVar9 = 8;
  iVar2 = *(int *)(param_2 + 0x54);
  iVar6 = iVar2 + 0x750;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  puVar8 = (undefined4 *)(iVar2 + 0x768);
  iVar3 = iVar6;
  do {
    *(undefined4 *)(((unsigned char *)0x00001018) + iVar3) = 0;
    iVar3 = iVar3 + 4;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  *(undefined4 *)(iVar2 + 0x1990) = 0xffff;
  if (*(char *)(param_2 + 0x58) == '\0') {
    iVar3 = 0;
    if (*(int *)(param_2 + 0x48) != 0) {
      uVar7 = *(undefined4 *)(param_2 + 0x4c);
      ((void (*)())FUN_0009f0b0)(param_1,param_2,param_3,param_4,param_5,param_6,iVar4,param_8,fparam_1,fparam_2,
                   fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffa8,
                   in_stack_ffffffb0,in_stack_ffffffb8,in_stack_ffffffc0,in_stack_ffffffc8);
      _memcpy(puVar8,uVar7,*(int *)(param_2 + 0x48) << 4);
      iVar3 = *(int *)(param_2 + 0x48);
      if (0 < iVar3) {
        uVar5 = 0;
        do {
          iVar3 = ((int)uVar5 >> 5) + (uint)((int)uVar5 < 0 && (uVar5 & 0x1f) != 0);
          iVar4 = iVar3 * 4 + iVar6;
          uVar1 = uVar5 + iVar3 * -0x20;
          uVar5 = uVar5 + 1;
          *(uint *)(((unsigned char *)0x00001018) + iVar4) = 1 << (uVar1 & 0x3f) | *(uint *)(((unsigned char *)0x00001018) + iVar4);
          iVar3 = *(int *)(param_2 + 0x48);
        } while ((int)uVar5 < iVar3);
      }
    }
    *(int *)(iVar2 + 0x1788) = iVar3;
  }
  else {
    if ((*(uint *)(((unsigned char *)0x000013c0) + param_1) & 4) == 0) {
      *puVar8 = *(undefined4 *)(iVar4 + 0x2460);
      *(undefined4 *)(iVar2 + 0x76c) = *(undefined4 *)(iVar4 + 0x2470);
      *(undefined4 *)(iVar2 + 0x770) = *(undefined4 *)(iVar4 + 0x2480);
      *(undefined4 *)(iVar2 + 0x774) = *(undefined4 *)(iVar4 + 0x2490);
      *(undefined4 *)(iVar2 + 0x778) = *(undefined4 *)(iVar4 + 0x2464);
      *(undefined4 *)(iVar2 + 0x77c) = *(undefined4 *)(iVar4 + 0x2474);
      *(undefined4 *)(iVar2 + 0x780) = *(undefined4 *)(iVar4 + 0x2484);
      *(undefined4 *)(iVar2 + 0x784) = *(undefined4 *)(iVar4 + 0x2494);
      *(undefined4 *)(iVar2 + 0x788) = *(undefined4 *)(iVar4 + 0x2468);
      *(undefined4 *)(iVar2 + 0x78c) = *(undefined4 *)(iVar4 + 0x2478);
      *(undefined4 *)(iVar2 + 0x790) = *(undefined4 *)(iVar4 + 0x2488);
      *(undefined4 *)(iVar2 + 0x794) = *(undefined4 *)(iVar4 + 0x2498);
      *(undefined4 *)(iVar2 + 0x798) = *(undefined4 *)(iVar4 + 0x246c);
      *(undefined4 *)(iVar2 + 0x79c) = *(undefined4 *)(iVar4 + 0x247c);
      *(undefined4 *)(iVar2 + 0x7a0) = *(undefined4 *)(iVar4 + 0x248c);
      *(undefined4 *)(iVar2 + 0x7a4) = *(undefined4 *)(iVar4 + 0x249c);
    }
    else {
      *puVar8 = *(undefined4 *)(iVar4 + 0x2460);
      *(undefined4 *)(iVar2 + 0x76c) = *(undefined4 *)(iVar4 + 0x2464);
      *(undefined4 *)(iVar2 + 0x770) = *(undefined4 *)(iVar4 + 0x2468);
      *(undefined4 *)(iVar2 + 0x774) = *(undefined4 *)(iVar4 + 0x246c);
      *(undefined4 *)(iVar2 + 0x778) = *(undefined4 *)(iVar4 + 0x2470);
      *(undefined4 *)(iVar2 + 0x77c) = *(undefined4 *)(iVar4 + 0x2474);
      *(undefined4 *)(iVar2 + 0x780) = *(undefined4 *)(iVar4 + 0x2478);
      *(undefined4 *)(iVar2 + 0x784) = *(undefined4 *)(iVar4 + 0x247c);
      *(undefined4 *)(iVar2 + 0x788) = *(undefined4 *)(iVar4 + 0x2480);
      *(undefined4 *)(iVar2 + 0x78c) = *(undefined4 *)(iVar4 + 0x2484);
      *(undefined4 *)(iVar2 + 0x790) = *(undefined4 *)(iVar4 + 0x2488);
      *(undefined4 *)(iVar2 + 0x794) = *(undefined4 *)(iVar4 + 0x248c);
      *(undefined4 *)(iVar2 + 0x798) = *(undefined4 *)(iVar4 + 0x2490);
      *(undefined4 *)(iVar2 + 0x79c) = *(undefined4 *)(iVar4 + 0x2494);
      *(undefined4 *)(iVar2 + 0x7a0) = *(undefined4 *)(iVar4 + 0x2498);
      *(undefined4 *)(iVar2 + 0x7a4) = *(undefined4 *)(iVar4 + 0x249c);
    }
    *(undefined4 *)(iVar2 + 0x1768) = 0xf;
    *(undefined4 *)(iVar2 + 0x1788) = 4;
  }
  if ((*(char *)(iVar2 + 0x751) != '\0') && (iVar6 == *(int *)(((unsigned char *)0x0000148c) + param_1))) {
                    
                    
    (**(code **)((int)((unsigned char *)0x000012a0) + param_1))(param_1,iVar6);
    return;
  }
  return;
}

/* FUN_00065c40 @ 0x65c40 (52 bytes) */
int FUN_00065c40(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  if (((*(uint *)(param_1 + 0x44) & 0x100000) != 0) && (*(char *)(param_1 + 0x124) == '\0')) {
    return;
  }
                    
                    
  (**(code **)((int)((unsigned char *)0x00001298) + param_1))(param_1,*(int *)(param_2 + 0x54) + 0x750);
  return;
}

/* FUN_00065c80 @ 0x65c80 (4 bytes) */
int FUN_00065c80()
{
  return;
}

/* FUN_00065c90 @ 0x65c90 (328 bytes) */
int FUN_00065c90(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = (uint *)(param_2 + 0x754);
  if (*(uint *)(param_2 + 0x758) <= *(uint *)(param_2 + 0x754)) {
    uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 0x758) * 4 + 0x200);
    if (*(int *)(param_2 + 0x75c) != 0) {
      _memcpy(uVar1,*(int *)(param_2 + 0x75c),*(int *)(param_2 + 0x754) << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0x75c));
    }
    *(undefined4 *)(param_2 + 0x75c) = uVar1;
    *(int *)(param_2 + 0x758) = *(int *)(param_2 + 0x758) + 0x80;
  }
  *(undefined4 *)(*puVar3 * 4 + *(int *)(param_2 + 0x75c)) = 1;
  uVar2 = *puVar3 + 1;
  *puVar3 = uVar2;
  if (*(uint *)(param_2 + 0x758) <= uVar2) {
    uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 0x758) * 4 + 0x200);
    if (*(int *)(param_2 + 0x75c) != 0) {
      _memcpy(uVar1,*(int *)(param_2 + 0x75c),*puVar3 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0x75c));
    }
    *(undefined4 *)(param_2 + 0x75c) = uVar1;
    uVar2 = *puVar3;
    *(int *)(param_2 + 0x758) = *(int *)(param_2 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + *(int *)(param_2 + 0x75c)) = 0x200;
  *puVar3 = *puVar3 + 1;
  return;
}

/* FUN_00065de0 @ 0x65de0 (192 bytes) */
int FUN_00065de0(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_2 + 0x754);
  if (*(uint *)(param_2 + 0x758) <= *(uint *)(param_2 + 0x754)) {
    uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 0x758) * 4 + 0x200);
    if (*(int *)(param_2 + 0x75c) != 0) {
      _memcpy(uVar1,*(int *)(param_2 + 0x75c),*(int *)(param_2 + 0x754) << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0x75c));
    }
    *(undefined4 *)(param_2 + 0x75c) = uVar1;
    *(int *)(param_2 + 0x758) = *(int *)(param_2 + 0x758) + 0x80;
  }
  *(undefined4 *)(*piVar2 * 4 + *(int *)(param_2 + 0x75c)) = 0x28;
  *piVar2 = *piVar2 + 1;
  return;
}

/* FUN_00065ea0 @ 0x65ea0 (1912 bytes) */
int FUN_00065ea0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  uint param_3;
  int *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
  uint param_9;
  uint param_10;
  uint *param_11;
  uint *param_12;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint *puVar18;
  
  uVar13 = (param_2 & 0x3f) << 0x10 | param_3 & 0xffff;
  puVar18 = (uint *)(param_1 + 0x754);
  uVar15 = 0;
  uVar17 = 0;
  uVar14 = 0;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    uVar13 = uVar13 | 0x400000;
    uVar14 = 0x55;
  }
  if (*param_4 == 0) {
    iVar16 = param_4[3];
    iVar8 = param_4[1];
    iVar2 = param_4[2];
LAB_00065f90:
    uVar13 = uVar13 | 0x400000;
    uVar14 = (uint)(iVar16 != 0) * 0x40 |
             (uint)(iVar2 != 0) * 0x10 | (uint)(iVar8 != 0) * 4 | (uint)(*param_4 != 0);
  }
  else {
    iVar8 = param_4[1];
    if (iVar8 == 0) {
      iVar16 = param_4[3];
      iVar2 = param_4[2];
      goto LAB_00065f90;
    }
    iVar2 = param_4[2];
    if (iVar2 == 0) {
      iVar16 = param_4[3];
      goto LAB_00065f90;
    }
    if (param_4[3] == 0) {
      iVar16 = 0;
      goto LAB_00065f90;
    }
  }
  uVar12 = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  if (*param_8 == 0) {
    uVar7 = param_8[1];
    if (uVar7 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar6 = param_8[2];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_000660e0;
    }
    uVar6 = param_8[2];
    if (uVar6 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_000660e0;
    }
    uVar5 = param_8[3];
    if (uVar5 != 0) {
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_000660e0;
    }
    uVar10 = *param_7;
    if (uVar10 != 0) {
      uVar9 = param_7[3];
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_000660e0;
    }
    uVar3 = param_7[1];
    if (uVar3 != 1) {
      uVar9 = param_7[3];
      uVar1 = param_7[2];
      goto LAB_000660e0;
    }
    uVar1 = param_7[2];
    if (uVar1 != 2) {
      uVar9 = param_7[3];
      goto LAB_000660e0;
    }
    uVar9 = param_7[3];
    if (uVar9 != 3) goto LAB_000660e0;
  }
  else {
    uVar5 = param_8[3];
    uVar9 = param_7[3];
    uVar7 = param_8[1];
    uVar6 = param_8[2];
    uVar10 = *param_7;
    uVar3 = param_7[1];
    uVar1 = param_7[2];
LAB_000660e0:
    uVar12 = uVar12 | 0x400000;
    uVar17 = (uVar5 & 1) << 0xf |
             (uVar9 & 7) << 0xc |
             (uVar6 & 1) << 0xb |
             (uVar1 & 7) << 8 |
             (uVar7 & 1) << 7 | (uVar3 & 7) << 4 | (*param_8 & 1) << 3 | uVar10 & 7;
  }
  uVar1 = (param_9 & 0x3f) << 0x10 | param_10 & 0xffff;
  if (*param_12 == 0) {
    uVar10 = param_12[1];
    if (uVar10 == 0) {
      uVar7 = param_12[2];
      if (uVar7 == 0) {
        uVar6 = param_12[3];
        if (uVar6 == 0) {
          uVar11 = *param_11;
          if (uVar11 == 0) {
            uVar5 = param_11[1];
            if (uVar5 == 1) {
              uVar3 = param_11[2];
              if (uVar3 == 2) {
                uVar9 = param_11[3];
                if (uVar9 == 3) goto LAB_00066234;
              }
              else {
                uVar9 = param_11[3];
              }
            }
            else {
              uVar9 = param_11[3];
              uVar3 = param_11[2];
            }
          }
          else {
            uVar9 = param_11[3];
            uVar5 = param_11[1];
            uVar3 = param_11[2];
          }
        }
        else {
          uVar9 = param_11[3];
          uVar11 = *param_11;
          uVar5 = param_11[1];
          uVar3 = param_11[2];
        }
      }
      else {
        uVar6 = param_12[3];
        uVar9 = param_11[3];
        uVar11 = *param_11;
        uVar5 = param_11[1];
        uVar3 = param_11[2];
      }
    }
    else {
      uVar6 = param_12[3];
      uVar9 = param_11[3];
      uVar7 = param_12[2];
      uVar11 = *param_11;
      uVar5 = param_11[1];
      uVar3 = param_11[2];
    }
  }
  else {
    uVar6 = param_12[3];
    uVar9 = param_11[3];
    uVar10 = param_12[1];
    uVar7 = param_12[2];
    uVar11 = *param_11;
    uVar5 = param_11[1];
    uVar3 = param_11[2];
  }
  uVar1 = uVar1 | 0x400000;
  uVar15 = (uVar6 & 1) << 0xf |
           (uVar9 & 7) << 0xc |
           (uVar7 & 1) << 0xb |
           (uVar3 & 7) << 8 |
           (uVar10 & 1) << 7 | (uVar5 & 7) << 4 | (*param_12 & 1) << 3 | uVar11 & 7;
LAB_00066234:
  uVar3 = *puVar18;
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = 0x23;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  if ((uVar13 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar3) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar3 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar14;
    uVar3 = *puVar18 + 1;
    *puVar18 = uVar3;
  }
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar12;
  uVar13 = *puVar18 + 1;
  *puVar18 = uVar13;
  if ((uVar12 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar13 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar17;
    uVar13 = *puVar18 + 1;
    *puVar18 = uVar13;
  }
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar13) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar13 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar1;
  uVar13 = *puVar18 + 1;
  *puVar18 = uVar13;
  if ((uVar1 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar13 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    *puVar18 = *puVar18 + 1;
  }
  return;
}

/* FUN_00066640 @ 0x66640 (1308 bytes) */
int FUN_00066640(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  int *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint *puVar16;
  
  uVar12 = (param_2 & 0x3f) << 0x10 | param_3 & 0xffff;
  puVar16 = (uint *)(param_1 + 0x754);
  uVar15 = 0;
  uVar13 = 0;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    uVar12 = uVar12 | 0x400000;
    uVar13 = 0x55;
  }
  if (*param_4 == 0) {
    iVar14 = param_4[3];
    iVar8 = param_4[1];
    iVar2 = param_4[2];
LAB_00066720:
    uVar12 = uVar12 | 0x400000;
    uVar13 = (uint)(iVar14 != 0) * 0x40 |
             (uint)(iVar2 != 0) * 0x10 | (uint)(iVar8 != 0) * 4 | (uint)(*param_4 != 0);
  }
  else {
    iVar8 = param_4[1];
    if (iVar8 == 0) {
      iVar14 = param_4[3];
      iVar2 = param_4[2];
      goto LAB_00066720;
    }
    iVar2 = param_4[2];
    if (iVar2 == 0) {
      iVar14 = param_4[3];
      goto LAB_00066720;
    }
    if (param_4[3] == 0) {
      iVar14 = 0;
      goto LAB_00066720;
    }
  }
  uVar11 = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  if (*param_8 == 0) {
    uVar7 = param_8[1];
    if (uVar7 == 0) {
      uVar6 = param_8[2];
      if (uVar6 == 0) {
        uVar5 = param_8[3];
        if (uVar5 == 0) {
          uVar10 = *param_7;
          if (uVar10 == 0) {
            uVar3 = param_7[1];
            if (uVar3 == 1) {
              uVar1 = param_7[2];
              if (uVar1 == 2) {
                uVar9 = param_7[3];
                if (uVar9 == 3) goto LAB_00066894;
              }
              else {
                uVar9 = param_7[3];
              }
            }
            else {
              uVar9 = param_7[3];
              uVar1 = param_7[2];
            }
          }
          else {
            uVar9 = param_7[3];
            uVar3 = param_7[1];
            uVar1 = param_7[2];
          }
        }
        else {
          uVar9 = param_7[3];
          uVar10 = *param_7;
          uVar3 = param_7[1];
          uVar1 = param_7[2];
        }
      }
      else {
        uVar5 = param_8[3];
        uVar9 = param_7[3];
        uVar10 = *param_7;
        uVar3 = param_7[1];
        uVar1 = param_7[2];
      }
    }
    else {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar6 = param_8[2];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
    }
  }
  else {
    uVar5 = param_8[3];
    uVar9 = param_7[3];
    uVar7 = param_8[1];
    uVar6 = param_8[2];
    uVar10 = *param_7;
    uVar3 = param_7[1];
    uVar1 = param_7[2];
  }
  uVar11 = uVar11 | 0x400000;
  uVar15 = (uVar5 & 1) << 0xf |
           (uVar9 & 7) << 0xc |
           (uVar6 & 1) << 0xb |
           (uVar1 & 7) << 8 | (uVar7 & 1) << 7 | (uVar3 & 7) << 4 | (*param_8 & 1) << 3 | uVar10 & 7
  ;
LAB_00066894:
  uVar1 = *puVar16;
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = 0x47;
  uVar1 = *puVar16 + 1;
  *puVar16 = uVar1;
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar12;
  uVar1 = *puVar16 + 1;
  *puVar16 = uVar1;
  if ((uVar12 & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar1) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar1 = *puVar16;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
    uVar1 = *puVar16 + 1;
    *puVar16 = uVar1;
  }
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar11;
  uVar12 = *puVar16 + 1;
  *puVar16 = uVar12;
  if ((uVar11 & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar12) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar12 = *puVar16;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar12 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    *puVar16 = *puVar16 + 1;
  }
  return;
}

/* FUN_00066b80 @ 0x66b80 (1912 bytes) */
int FUN_00066b80(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  uint param_3;
  int *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
  uint param_9;
  uint param_10;
  uint *param_11;
  uint *param_12;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint *puVar18;
  
  uVar13 = (param_2 & 0x3f) << 0x10 | param_3 & 0xffff;
  puVar18 = (uint *)(param_1 + 0x754);
  uVar15 = 0;
  uVar17 = 0;
  uVar14 = 0;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    uVar13 = uVar13 | 0x400000;
    uVar14 = 0x55;
  }
  if (*param_4 == 0) {
    iVar16 = param_4[3];
    iVar8 = param_4[1];
    iVar2 = param_4[2];
LAB_00066c70:
    uVar13 = uVar13 | 0x400000;
    uVar14 = (uint)(iVar16 != 0) * 0x40 |
             (uint)(iVar2 != 0) * 0x10 | (uint)(iVar8 != 0) * 4 | (uint)(*param_4 != 0);
  }
  else {
    iVar8 = param_4[1];
    if (iVar8 == 0) {
      iVar16 = param_4[3];
      iVar2 = param_4[2];
      goto LAB_00066c70;
    }
    iVar2 = param_4[2];
    if (iVar2 == 0) {
      iVar16 = param_4[3];
      goto LAB_00066c70;
    }
    if (param_4[3] == 0) {
      iVar16 = 0;
      goto LAB_00066c70;
    }
  }
  uVar12 = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  if (*param_8 == 0) {
    uVar7 = param_8[1];
    if (uVar7 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar6 = param_8[2];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_00066dc0;
    }
    uVar6 = param_8[2];
    if (uVar6 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_00066dc0;
    }
    uVar5 = param_8[3];
    if (uVar5 != 0) {
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_00066dc0;
    }
    uVar10 = *param_7;
    if (uVar10 != 0) {
      uVar9 = param_7[3];
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_00066dc0;
    }
    uVar3 = param_7[1];
    if (uVar3 != 1) {
      uVar9 = param_7[3];
      uVar1 = param_7[2];
      goto LAB_00066dc0;
    }
    uVar1 = param_7[2];
    if (uVar1 != 2) {
      uVar9 = param_7[3];
      goto LAB_00066dc0;
    }
    uVar9 = param_7[3];
    if (uVar9 != 3) goto LAB_00066dc0;
  }
  else {
    uVar5 = param_8[3];
    uVar9 = param_7[3];
    uVar7 = param_8[1];
    uVar6 = param_8[2];
    uVar10 = *param_7;
    uVar3 = param_7[1];
    uVar1 = param_7[2];
LAB_00066dc0:
    uVar12 = uVar12 | 0x400000;
    uVar17 = (uVar5 & 1) << 0xf |
             (uVar9 & 7) << 0xc |
             (uVar6 & 1) << 0xb |
             (uVar1 & 7) << 8 |
             (uVar7 & 1) << 7 | (uVar3 & 7) << 4 | (*param_8 & 1) << 3 | uVar10 & 7;
  }
  uVar1 = (param_9 & 0x3f) << 0x10 | param_10 & 0xffff;
  if (*param_12 == 0) {
    uVar10 = param_12[1];
    if (uVar10 == 0) {
      uVar7 = param_12[2];
      if (uVar7 == 0) {
        uVar6 = param_12[3];
        if (uVar6 == 0) {
          uVar11 = *param_11;
          if (uVar11 == 0) {
            uVar5 = param_11[1];
            if (uVar5 == 1) {
              uVar3 = param_11[2];
              if (uVar3 == 2) {
                uVar9 = param_11[3];
                if (uVar9 == 3) goto LAB_00066f14;
              }
              else {
                uVar9 = param_11[3];
              }
            }
            else {
              uVar9 = param_11[3];
              uVar3 = param_11[2];
            }
          }
          else {
            uVar9 = param_11[3];
            uVar5 = param_11[1];
            uVar3 = param_11[2];
          }
        }
        else {
          uVar9 = param_11[3];
          uVar11 = *param_11;
          uVar5 = param_11[1];
          uVar3 = param_11[2];
        }
      }
      else {
        uVar6 = param_12[3];
        uVar9 = param_11[3];
        uVar11 = *param_11;
        uVar5 = param_11[1];
        uVar3 = param_11[2];
      }
    }
    else {
      uVar6 = param_12[3];
      uVar9 = param_11[3];
      uVar7 = param_12[2];
      uVar11 = *param_11;
      uVar5 = param_11[1];
      uVar3 = param_11[2];
    }
  }
  else {
    uVar6 = param_12[3];
    uVar9 = param_11[3];
    uVar10 = param_12[1];
    uVar7 = param_12[2];
    uVar11 = *param_11;
    uVar5 = param_11[1];
    uVar3 = param_11[2];
  }
  uVar1 = uVar1 | 0x400000;
  uVar15 = (uVar6 & 1) << 0xf |
           (uVar9 & 7) << 0xc |
           (uVar7 & 1) << 0xb |
           (uVar3 & 7) << 8 |
           (uVar10 & 1) << 7 | (uVar5 & 7) << 4 | (*param_12 & 1) << 3 | uVar11 & 7;
LAB_00066f14:
  uVar3 = *puVar18;
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = 0x49;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  if ((uVar13 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar3) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar3 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar14;
    uVar3 = *puVar18 + 1;
    *puVar18 = uVar3;
  }
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar12;
  uVar13 = *puVar18 + 1;
  *puVar18 = uVar13;
  if ((uVar12 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar13 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar17;
    uVar13 = *puVar18 + 1;
    *puVar18 = uVar13;
  }
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar13) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar13 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar1;
  uVar13 = *puVar18 + 1;
  *puVar18 = uVar13;
  if ((uVar1 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar13 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    *puVar18 = *puVar18 + 1;
  }
  return;
}

/* FUN_00067320 @ 0x67320 (1912 bytes) */
int FUN_00067320(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  uint param_3;
  int *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
  uint param_9;
  uint param_10;
  uint *param_11;
  uint *param_12;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint *puVar18;
  
  uVar13 = (param_2 & 0x3f) << 0x10 | param_3 & 0xffff;
  puVar18 = (uint *)(param_1 + 0x754);
  uVar15 = 0;
  uVar17 = 0;
  uVar14 = 0;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    uVar13 = uVar13 | 0x400000;
    uVar14 = 0x55;
  }
  if (*param_4 == 0) {
    iVar16 = param_4[3];
    iVar8 = param_4[1];
    iVar2 = param_4[2];
LAB_00067410:
    uVar13 = uVar13 | 0x400000;
    uVar14 = (uint)(iVar16 != 0) * 0x40 |
             (uint)(iVar2 != 0) * 0x10 | (uint)(iVar8 != 0) * 4 | (uint)(*param_4 != 0);
  }
  else {
    iVar8 = param_4[1];
    if (iVar8 == 0) {
      iVar16 = param_4[3];
      iVar2 = param_4[2];
      goto LAB_00067410;
    }
    iVar2 = param_4[2];
    if (iVar2 == 0) {
      iVar16 = param_4[3];
      goto LAB_00067410;
    }
    if (param_4[3] == 0) {
      iVar16 = 0;
      goto LAB_00067410;
    }
  }
  uVar12 = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  if (*param_8 == 0) {
    uVar7 = param_8[1];
    if (uVar7 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar6 = param_8[2];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_00067560;
    }
    uVar6 = param_8[2];
    if (uVar6 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_00067560;
    }
    uVar5 = param_8[3];
    if (uVar5 != 0) {
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_00067560;
    }
    uVar10 = *param_7;
    if (uVar10 != 0) {
      uVar9 = param_7[3];
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_00067560;
    }
    uVar3 = param_7[1];
    if (uVar3 != 1) {
      uVar9 = param_7[3];
      uVar1 = param_7[2];
      goto LAB_00067560;
    }
    uVar1 = param_7[2];
    if (uVar1 != 2) {
      uVar9 = param_7[3];
      goto LAB_00067560;
    }
    uVar9 = param_7[3];
    if (uVar9 != 3) goto LAB_00067560;
  }
  else {
    uVar5 = param_8[3];
    uVar9 = param_7[3];
    uVar7 = param_8[1];
    uVar6 = param_8[2];
    uVar10 = *param_7;
    uVar3 = param_7[1];
    uVar1 = param_7[2];
LAB_00067560:
    uVar12 = uVar12 | 0x400000;
    uVar17 = (uVar5 & 1) << 0xf |
             (uVar9 & 7) << 0xc |
             (uVar6 & 1) << 0xb |
             (uVar1 & 7) << 8 |
             (uVar7 & 1) << 7 | (uVar3 & 7) << 4 | (*param_8 & 1) << 3 | uVar10 & 7;
  }
  uVar1 = (param_9 & 0x3f) << 0x10 | param_10 & 0xffff;
  if (*param_12 == 0) {
    uVar10 = param_12[1];
    if (uVar10 == 0) {
      uVar7 = param_12[2];
      if (uVar7 == 0) {
        uVar6 = param_12[3];
        if (uVar6 == 0) {
          uVar11 = *param_11;
          if (uVar11 == 0) {
            uVar5 = param_11[1];
            if (uVar5 == 1) {
              uVar3 = param_11[2];
              if (uVar3 == 2) {
                uVar9 = param_11[3];
                if (uVar9 == 3) goto LAB_000676b4;
              }
              else {
                uVar9 = param_11[3];
              }
            }
            else {
              uVar9 = param_11[3];
              uVar3 = param_11[2];
            }
          }
          else {
            uVar9 = param_11[3];
            uVar5 = param_11[1];
            uVar3 = param_11[2];
          }
        }
        else {
          uVar9 = param_11[3];
          uVar11 = *param_11;
          uVar5 = param_11[1];
          uVar3 = param_11[2];
        }
      }
      else {
        uVar6 = param_12[3];
        uVar9 = param_11[3];
        uVar11 = *param_11;
        uVar5 = param_11[1];
        uVar3 = param_11[2];
      }
    }
    else {
      uVar6 = param_12[3];
      uVar9 = param_11[3];
      uVar7 = param_12[2];
      uVar11 = *param_11;
      uVar5 = param_11[1];
      uVar3 = param_11[2];
    }
  }
  else {
    uVar6 = param_12[3];
    uVar9 = param_11[3];
    uVar10 = param_12[1];
    uVar7 = param_12[2];
    uVar11 = *param_11;
    uVar5 = param_11[1];
    uVar3 = param_11[2];
  }
  uVar1 = uVar1 | 0x400000;
  uVar15 = (uVar6 & 1) << 0xf |
           (uVar9 & 7) << 0xc |
           (uVar7 & 1) << 0xb |
           (uVar3 & 7) << 8 |
           (uVar10 & 1) << 7 | (uVar5 & 7) << 4 | (*param_12 & 1) << 3 | uVar11 & 7;
LAB_000676b4:
  uVar3 = *puVar18;
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = 3;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  if ((uVar13 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar3) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar3 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar14;
    uVar3 = *puVar18 + 1;
    *puVar18 = uVar3;
  }
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar12;
  uVar13 = *puVar18 + 1;
  *puVar18 = uVar13;
  if ((uVar12 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar13 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar17;
    uVar13 = *puVar18 + 1;
    *puVar18 = uVar13;
  }
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar13) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar13 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar1;
  uVar13 = *puVar18 + 1;
  *puVar18 = uVar13;
  if ((uVar1 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar13 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    *puVar18 = *puVar18 + 1;
  }
  return;
}

/* FUN_00067ac0 @ 0x67ac0 (2516 bytes) */
int FUN_00067ac0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16)
  int param_1;
  uint param_2;
  uint param_3;
  int *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
  uint param_9;
  uint param_10;
  uint *param_11;
  uint *param_12;
  uint param_13;
  uint param_14;
  uint *param_15;
  uint *param_16;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint *puVar20;
  
  uVar13 = (param_2 & 0x3f) << 0x10 | param_3 & 0xffff;
  puVar20 = (uint *)(param_1 + 0x754);
  uVar16 = 0;
  uVar17 = 0;
  uVar18 = 0;
  uVar15 = 0;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    uVar13 = uVar13 | 0x400000;
    uVar15 = 0x55;
  }
  if (*param_4 == 0) {
    iVar19 = param_4[3];
    iVar8 = param_4[1];
    iVar2 = param_4[2];
LAB_00067bc0:
    uVar13 = uVar13 | 0x400000;
    uVar15 = (uint)(iVar19 != 0) * 0x40 |
             (uint)(iVar2 != 0) * 0x10 | (uint)(iVar8 != 0) * 4 | (uint)(*param_4 != 0);
  }
  else {
    iVar8 = param_4[1];
    if (iVar8 == 0) {
      iVar19 = param_4[3];
      iVar2 = param_4[2];
      goto LAB_00067bc0;
    }
    iVar2 = param_4[2];
    if (iVar2 == 0) {
      iVar19 = param_4[3];
      goto LAB_00067bc0;
    }
    if (param_4[3] == 0) {
      iVar19 = 0;
      goto LAB_00067bc0;
    }
  }
  uVar14 = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  if (*param_8 == 0) {
    uVar7 = param_8[1];
    if (uVar7 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar6 = param_8[2];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_00067d10;
    }
    uVar6 = param_8[2];
    if (uVar6 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_00067d10;
    }
    uVar5 = param_8[3];
    if (uVar5 != 0) {
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_00067d10;
    }
    uVar10 = *param_7;
    if (uVar10 != 0) {
      uVar9 = param_7[3];
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_00067d10;
    }
    uVar3 = param_7[1];
    if (uVar3 != 1) {
      uVar9 = param_7[3];
      uVar1 = param_7[2];
      goto LAB_00067d10;
    }
    uVar1 = param_7[2];
    if (uVar1 != 2) {
      uVar9 = param_7[3];
      goto LAB_00067d10;
    }
    uVar9 = param_7[3];
    if (uVar9 != 3) goto LAB_00067d10;
  }
  else {
    uVar5 = param_8[3];
    uVar9 = param_7[3];
    uVar7 = param_8[1];
    uVar6 = param_8[2];
    uVar10 = *param_7;
    uVar3 = param_7[1];
    uVar1 = param_7[2];
LAB_00067d10:
    uVar14 = uVar14 | 0x400000;
    uVar18 = (uVar5 & 1) << 0xf |
             (uVar9 & 7) << 0xc |
             (uVar6 & 1) << 0xb |
             (uVar1 & 7) << 8 |
             (uVar7 & 1) << 7 | (uVar3 & 7) << 4 | (*param_8 & 1) << 3 | uVar10 & 7;
  }
  uVar1 = (param_9 & 0x3f) << 0x10 | param_10 & 0xffff;
  if (*param_12 == 0) {
    uVar10 = param_12[1];
    if (uVar10 != 0) {
      uVar6 = param_12[3];
      uVar9 = param_11[3];
      uVar7 = param_12[2];
      uVar11 = *param_11;
      uVar5 = param_11[1];
      uVar3 = param_11[2];
      goto LAB_00067e40;
    }
    uVar7 = param_12[2];
    if (uVar7 != 0) {
      uVar6 = param_12[3];
      uVar9 = param_11[3];
      uVar11 = *param_11;
      uVar5 = param_11[1];
      uVar3 = param_11[2];
      goto LAB_00067e40;
    }
    uVar6 = param_12[3];
    if (uVar6 != 0) {
      uVar9 = param_11[3];
      uVar11 = *param_11;
      uVar5 = param_11[1];
      uVar3 = param_11[2];
      goto LAB_00067e40;
    }
    uVar11 = *param_11;
    if (uVar11 != 0) {
      uVar9 = param_11[3];
      uVar5 = param_11[1];
      uVar3 = param_11[2];
      goto LAB_00067e40;
    }
    uVar5 = param_11[1];
    if (uVar5 != 1) {
      uVar9 = param_11[3];
      uVar3 = param_11[2];
      goto LAB_00067e40;
    }
    uVar3 = param_11[2];
    if (uVar3 != 2) {
      uVar9 = param_11[3];
      goto LAB_00067e40;
    }
    uVar9 = param_11[3];
    if (uVar9 != 3) goto LAB_00067e40;
  }
  else {
    uVar6 = param_12[3];
    uVar9 = param_11[3];
    uVar10 = param_12[1];
    uVar7 = param_12[2];
    uVar11 = *param_11;
    uVar5 = param_11[1];
    uVar3 = param_11[2];
LAB_00067e40:
    uVar1 = uVar1 | 0x400000;
    uVar17 = (uVar6 & 1) << 0xf |
             (uVar9 & 7) << 0xc |
             (uVar7 & 1) << 0xb |
             (uVar3 & 7) << 8 |
             (uVar10 & 1) << 7 | (uVar5 & 7) << 4 | (*param_12 & 1) << 3 | uVar11 & 7;
  }
  uVar3 = (param_13 & 0x3f) << 0x10 | param_14 & 0xffff;
  if (*param_16 == 0) {
    uVar11 = param_16[1];
    if (uVar11 == 0) {
      uVar9 = param_16[2];
      if (uVar9 == 0) {
        uVar7 = param_16[3];
        if (uVar7 == 0) {
          uVar12 = *param_15;
          if (uVar12 == 0) {
            uVar6 = param_15[1];
            if (uVar6 == 1) {
              uVar5 = param_15[2];
              if (uVar5 == 2) {
                uVar10 = param_15[3];
                if (uVar10 == 3) goto LAB_00067f94;
              }
              else {
                uVar10 = param_15[3];
              }
            }
            else {
              uVar10 = param_15[3];
              uVar5 = param_15[2];
            }
          }
          else {
            uVar10 = param_15[3];
            uVar6 = param_15[1];
            uVar5 = param_15[2];
          }
        }
        else {
          uVar10 = param_15[3];
          uVar12 = *param_15;
          uVar6 = param_15[1];
          uVar5 = param_15[2];
        }
      }
      else {
        uVar7 = param_16[3];
        uVar10 = param_15[3];
        uVar12 = *param_15;
        uVar6 = param_15[1];
        uVar5 = param_15[2];
      }
    }
    else {
      uVar7 = param_16[3];
      uVar10 = param_15[3];
      uVar9 = param_16[2];
      uVar12 = *param_15;
      uVar6 = param_15[1];
      uVar5 = param_15[2];
    }
  }
  else {
    uVar7 = param_16[3];
    uVar10 = param_15[3];
    uVar11 = param_16[1];
    uVar9 = param_16[2];
    uVar12 = *param_15;
    uVar6 = param_15[1];
    uVar5 = param_15[2];
  }
  uVar3 = uVar3 | 0x400000;
  uVar16 = (uVar7 & 1) << 0xf |
           (uVar10 & 7) << 0xc |
           (uVar9 & 1) << 0xb |
           (uVar5 & 7) << 8 |
           (uVar11 & 1) << 7 | (uVar6 & 7) << 4 | (*param_16 & 1) << 3 | uVar12 & 7;
LAB_00067f94:
  uVar5 = *puVar20;
  iVar19 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar5) {
    uVar4 = (**(code **)(iVar19 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar20 << 2);
      (**(code **)(iVar19 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar5 = *puVar20;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) = 0x40;
  uVar5 = *puVar20 + 1;
  *puVar20 = uVar5;
  iVar19 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar5) {
    uVar4 = (**(code **)(iVar19 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar20 << 2);
      (**(code **)(iVar19 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar5 = *puVar20;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
  uVar5 = *puVar20 + 1;
  *puVar20 = uVar5;
  if ((uVar13 & 0x400000) != 0) {
    iVar19 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar5) {
      uVar4 = (**(code **)(iVar19 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar20 << 2);
        (**(code **)(iVar19 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar5 = *puVar20;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    uVar5 = *puVar20 + 1;
    *puVar20 = uVar5;
  }
  iVar19 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar5) {
    uVar4 = (**(code **)(iVar19 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar20 << 2);
      (**(code **)(iVar19 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar5 = *puVar20;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) = uVar14;
  uVar13 = *puVar20 + 1;
  *puVar20 = uVar13;
  if ((uVar14 & 0x400000) != 0) {
    iVar19 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      uVar4 = (**(code **)(iVar19 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar20 << 2);
        (**(code **)(iVar19 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar13 = *puVar20;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar18;
    uVar13 = *puVar20 + 1;
    *puVar20 = uVar13;
  }
  iVar19 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar13) {
    uVar4 = (**(code **)(iVar19 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar20 << 2);
      (**(code **)(iVar19 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar13 = *puVar20;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar1;
  uVar13 = *puVar20 + 1;
  *puVar20 = uVar13;
  if ((uVar1 & 0x400000) != 0) {
    iVar19 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      uVar4 = (**(code **)(iVar19 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar20 << 2);
        (**(code **)(iVar19 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar13 = *puVar20;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar17;
    uVar13 = *puVar20 + 1;
    *puVar20 = uVar13;
  }
  iVar19 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar13) {
    uVar4 = (**(code **)(iVar19 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar20 << 2);
      (**(code **)(iVar19 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar13 = *puVar20;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar3;
  uVar13 = *puVar20 + 1;
  *puVar20 = uVar13;
  if ((uVar3 & 0x400000) != 0) {
    iVar19 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      uVar4 = (**(code **)(iVar19 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar20 << 2);
        (**(code **)(iVar19 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar13 = *puVar20;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar16;
    *puVar20 = *puVar20 + 1;
  }
  return;
}

/* FUN_000684c0 @ 0x684c0 (3632 bytes) */
int FUN_000684c0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16)
  int param_1;
  uint param_2;
  uint param_3;
  int *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
  uint param_9;
  uint param_10;
  uint *param_11;
  uint *param_12;
  uint param_13;
  uint param_14;
  uint *param_15;
  uint *param_16;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint *puVar21;
  uint uStack0000001c;
  uint uStack00000020;
  undefined1 auStack_88 [4];
  uint uStack_84;
  uint uStack_58;
  
  puVar21 = (uint *)(param_1 + 0x754);
  uVar17 = 0;
  uVar16 = 0;
  uVar18 = 0;
  uVar15 = 0;
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  (**(code **)(param_1 + 0x748))(param_1,0,auStack_88,param_4,param_5,param_6,param_7,param_8);
  uVar11 = uStack_84 & 0xffff;
  uStack_58 = 3;
  iVar20 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *(uint *)(param_1 + 0x754)) {
    uVar4 = (**(code **)(iVar20 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*(int *)(param_1 + 0x754) << 2);
      (**(code **)(iVar20 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*puVar21 * 4 + *(int *)(param_1 + 0x75c)) = uStack_58;
  uVar10 = *puVar21 + 1;
  *puVar21 = uVar10;
  iVar20 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar10) {
    uVar4 = (**(code **)(iVar20 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar21 << 2);
      (**(code **)(iVar20 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar10 = *puVar21;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar10 * 4 + *(int *)(param_1 + 0x75c)) = uVar11 | 0x40000;
  uVar11 = *puVar21 + 1;
  *puVar21 = uVar11;
  iVar20 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar11) {
    uVar4 = (**(code **)(iVar20 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar21 << 2);
      (**(code **)(iVar20 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar11 = *puVar21;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar11 * 4 + *(int *)(param_1 + 0x75c)) = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  uVar11 = *puVar21 + 1;
  *puVar21 = uVar11;
  iVar20 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar11) {
    uVar4 = (**(code **)(iVar20 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar21 << 2);
      (**(code **)(iVar20 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar11 = *puVar21;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar11 * 4 + *(int *)(param_1 + 0x75c)) = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  uVar11 = *puVar21 + 1;
  *puVar21 = uVar11;
  uStack_58 = uStack_58 & 0xffff0000 | 0x40;
  uVar10 = (uStack0000001c & 0x3f) << 0x10 | uStack00000020 & 0xffff;
  if ((uStack0000001c == 0x12) || (uStack0000001c == 0x13)) {
    uVar10 = uVar10 | 0x400000;
    uVar15 = 0x55;
  }
  if (*param_4 == 0) {
    iVar20 = param_4[3];
    iVar8 = param_4[1];
    iVar2 = param_4[2];
LAB_00068a20:
    uVar10 = uVar10 | 0x400000;
    uVar15 = (uint)(iVar20 != 0) * 0x40 |
             (uint)(iVar2 != 0) * 0x10 | (uint)(iVar8 != 0) * 4 | (uint)(*param_4 != 0);
  }
  else {
    iVar8 = param_4[1];
    if (iVar8 == 0) {
      iVar20 = param_4[3];
      iVar2 = param_4[2];
      goto LAB_00068a20;
    }
    iVar2 = param_4[2];
    if (iVar2 == 0) {
      iVar20 = param_4[3];
      goto LAB_00068a20;
    }
    if (param_4[3] == 0) {
      iVar20 = 0;
      goto LAB_00068a20;
    }
  }
  uVar19 = (param_5 & 0x3f) << 0x10 | uStack_84 & 0xffff;
  if (*param_8 == 0) {
    uVar7 = param_8[1];
    if (uVar7 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar6 = param_8[2];
      uVar12 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_00068b70;
    }
    uVar6 = param_8[2];
    if (uVar6 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar12 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_00068b70;
    }
    uVar5 = param_8[3];
    if (uVar5 != 0) {
      uVar9 = param_7[3];
      uVar12 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_00068b70;
    }
    uVar12 = *param_7;
    if (uVar12 != 0) {
      uVar9 = param_7[3];
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_00068b70;
    }
    uVar3 = param_7[1];
    if (uVar3 != 1) {
      uVar9 = param_7[3];
      uVar1 = param_7[2];
      goto LAB_00068b70;
    }
    uVar1 = param_7[2];
    if (uVar1 != 2) {
      uVar9 = param_7[3];
      goto LAB_00068b70;
    }
    uVar9 = param_7[3];
    if (uVar9 != 3) goto LAB_00068b70;
  }
  else {
    uVar5 = param_8[3];
    uVar9 = param_7[3];
    uVar7 = param_8[1];
    uVar6 = param_8[2];
    uVar12 = *param_7;
    uVar3 = param_7[1];
    uVar1 = param_7[2];
LAB_00068b70:
    uVar19 = uVar19 | 0x400000;
    uVar18 = (uVar5 & 1) << 0xf |
             (uVar9 & 7) << 0xc |
             (uVar6 & 1) << 0xb |
             (uVar1 & 7) << 8 |
             (uVar7 & 1) << 7 | (uVar3 & 7) << 4 | (*param_8 & 1) << 3 | uVar12 & 7;
  }
  uVar1 = (param_9 & 0x3f) << 0x10 | param_10 & 0xffff;
  if (*param_12 == 0) {
    uVar5 = param_12[1];
    if (uVar5 != 0) {
      uVar6 = param_11[3];
      uVar3 = param_12[3];
      goto LAB_00068c4c;
    }
    uVar12 = param_12[2];
    if (uVar12 != 0) {
      uVar6 = param_11[3];
      uVar13 = *param_11;
      uVar7 = param_11[2];
      uVar3 = param_12[3];
      uVar9 = param_11[1];
      goto LAB_00068cb0;
    }
    uVar3 = param_12[3];
    if (uVar3 != 0) {
      uVar6 = param_11[3];
      uVar13 = *param_11;
      uVar9 = param_11[1];
      uVar7 = param_11[2];
      goto LAB_00068cb0;
    }
    uVar13 = *param_11;
    if (uVar13 != 0) {
      uVar6 = param_11[3];
      uVar9 = param_11[1];
      uVar7 = param_11[2];
      goto LAB_00068cb0;
    }
    uVar9 = param_11[1];
    if (uVar9 != 1) {
      uVar6 = param_11[3];
      uVar7 = param_11[2];
      goto LAB_00068cb0;
    }
    uVar7 = param_11[2];
    if (uVar7 != 2) {
      uVar6 = param_11[3];
      goto LAB_00068cb0;
    }
    uVar6 = param_11[3];
    if (uVar6 != 3) goto LAB_00068cb0;
  }
  else {
    uVar6 = param_11[3];
    uVar3 = param_12[3];
    uVar5 = param_12[1];
LAB_00068c4c:
    uVar12 = param_12[2];
    uVar13 = *param_11;
    uVar9 = param_11[1];
    uVar7 = param_11[2];
LAB_00068cb0:
    uVar1 = uVar1 | 0x400000;
    uVar16 = (uVar3 & 1) << 0xf |
             (uVar6 & 7) << 0xc |
             (uVar12 & 1) << 0xb |
             (uVar7 & 7) << 8 |
             (uVar5 & 1) << 7 | (uVar9 & 7) << 4 | (*param_12 & 1) << 3 | uVar13 & 7;
  }
  uVar3 = (param_13 & 0x3f) << 0x10 | param_14 & 0xffff;
  if (*param_16 == 0) {
    uVar6 = param_16[1];
    if (uVar6 != 0) {
      uVar7 = param_15[3];
      uVar5 = param_16[3];
      goto LAB_00068d8c;
    }
    uVar13 = param_16[2];
    if (uVar13 == 0) {
      uVar5 = param_16[3];
      if (uVar5 == 0) {
        uVar14 = *param_15;
        if (uVar14 == 0) {
          uVar12 = param_15[1];
          if (uVar12 == 1) {
            uVar9 = param_15[2];
            if (uVar9 == 2) {
              uVar7 = param_15[3];
              if (uVar7 == 3) goto LAB_00068e14;
            }
            else {
              uVar7 = param_15[3];
            }
          }
          else {
            uVar7 = param_15[3];
            uVar9 = param_15[2];
          }
        }
        else {
          uVar7 = param_15[3];
          uVar12 = param_15[1];
          uVar9 = param_15[2];
        }
      }
      else {
        uVar7 = param_15[3];
        uVar14 = *param_15;
        uVar12 = param_15[1];
        uVar9 = param_15[2];
      }
    }
    else {
      uVar7 = param_15[3];
      uVar14 = *param_15;
      uVar9 = param_15[2];
      uVar5 = param_16[3];
      uVar12 = param_15[1];
    }
  }
  else {
    uVar7 = param_15[3];
    uVar5 = param_16[3];
    uVar6 = param_16[1];
LAB_00068d8c:
    uVar13 = param_16[2];
    uVar14 = *param_15;
    uVar12 = param_15[1];
    uVar9 = param_15[2];
  }
  uVar3 = uVar3 | 0x400000;
  uVar17 = (uVar5 & 1) << 0xf |
           (uVar7 & 7) << 0xc |
           (uVar13 & 1) << 0xb |
           (uVar9 & 7) << 8 |
           (uVar6 & 1) << 7 | (uVar12 & 7) << 4 | (*param_16 & 1) << 3 | uVar14 & 7;
LAB_00068e14:
  iVar20 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar11) {
    uVar4 = (**(code **)(iVar20 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar21 << 2);
      (**(code **)(iVar20 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar11 = *puVar21;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar11 * 4 + *(int *)(param_1 + 0x75c)) = uStack_58;
  uVar11 = *puVar21 + 1;
  *puVar21 = uVar11;
  iVar20 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar11) {
    uVar4 = (**(code **)(iVar20 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar21 << 2);
      (**(code **)(iVar20 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar11 = *puVar21;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar11 * 4 + *(int *)(param_1 + 0x75c)) = uVar10;
  uVar11 = *puVar21 + 1;
  *puVar21 = uVar11;
  if ((uVar10 & 0x400000) != 0) {
    iVar20 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar11) {
      uVar4 = (**(code **)(iVar20 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar21 << 2);
        (**(code **)(iVar20 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar11 = *puVar21;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar11 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    uVar11 = *puVar21 + 1;
    *puVar21 = uVar11;
  }
  iVar20 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar11) {
    uVar4 = (**(code **)(iVar20 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar21 << 2);
      (**(code **)(iVar20 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar11 = *puVar21;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar11 * 4 + *(int *)(param_1 + 0x75c)) = uVar19;
  uVar11 = *puVar21 + 1;
  *puVar21 = uVar11;
  if ((uVar19 & 0x400000) != 0) {
    iVar20 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar11) {
      uVar4 = (**(code **)(iVar20 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar21 << 2);
        (**(code **)(iVar20 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar11 = *puVar21;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar11 * 4 + *(int *)(param_1 + 0x75c)) = uVar18;
    uVar11 = *puVar21 + 1;
    *puVar21 = uVar11;
  }
  iVar20 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar11) {
    uVar4 = (**(code **)(iVar20 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar21 << 2);
      (**(code **)(iVar20 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar11 = *puVar21;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar11 * 4 + *(int *)(param_1 + 0x75c)) = uVar1;
  uVar11 = *puVar21 + 1;
  *puVar21 = uVar11;
  if ((uVar1 & 0x400000) != 0) {
    iVar20 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar11) {
      uVar4 = (**(code **)(iVar20 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar21 << 2);
        (**(code **)(iVar20 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar11 = *puVar21;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar11 * 4 + *(int *)(param_1 + 0x75c)) = uVar16;
    uVar11 = *puVar21 + 1;
    *puVar21 = uVar11;
  }
  iVar20 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar11) {
    uVar4 = (**(code **)(iVar20 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar21 << 2);
      (**(code **)(iVar20 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar11 = *puVar21;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar11 * 4 + *(int *)(param_1 + 0x75c)) = uVar3;
  uVar11 = *puVar21 + 1;
  *puVar21 = uVar11;
  if ((uVar3 & 0x400000) != 0) {
    iVar20 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar11) {
      uVar4 = (**(code **)(iVar20 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar21 << 2);
        (**(code **)(iVar20 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar11 = *puVar21;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar11 * 4 + *(int *)(param_1 + 0x75c)) = uVar17;
    *puVar21 = *puVar21 + 1;
  }
  return;
}

/* FUN_00069330 @ 0x69330 (4280 bytes) */
int FUN_00069330(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16)
  int param_1;
  uint param_2;
  uint param_3;
  int *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
  uint param_9;
  uint param_10;
  uint *param_11;
  uint *param_12;
  uint param_13;
  uint param_14;
  uint *param_15;
  uint *param_16;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  int iVar18;
  undefined1 auStack_88 [4];
  uint uStack_84;
  
  puVar17 = (uint *)(param_1 + 0x754);
  uVar15 = 0;
  uVar13 = 0;
  uVar14 = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  uVar16 = 0;
  (**(code **)(param_1 + 0x748))(param_1,0,auStack_88,param_4,param_5,param_6,param_7,param_8);
  uVar5 = uStack_84 & 0xffff;
  if (*param_8 == 0) {
    uVar10 = param_8[1];
    if (uVar10 != 0) {
      uVar6 = param_8[3];
      uVar8 = param_7[3];
      uVar7 = param_8[2];
      uVar11 = *param_7;
      uVar2 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_000694c0;
    }
    uVar7 = param_8[2];
    if (uVar7 != 0) {
      uVar6 = param_8[3];
      uVar8 = param_7[3];
      uVar11 = *param_7;
      uVar2 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_000694c0;
    }
    uVar6 = param_8[3];
    if (uVar6 != 0) {
      uVar8 = param_7[3];
      uVar11 = *param_7;
      uVar2 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_000694c0;
    }
    uVar11 = *param_7;
    if (uVar11 != 0) {
      uVar8 = param_7[3];
      uVar2 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_000694c0;
    }
    uVar2 = param_7[1];
    if (uVar2 != 1) {
      uVar8 = param_7[3];
      uVar1 = param_7[2];
      goto LAB_000694c0;
    }
    uVar1 = param_7[2];
    if (uVar1 != 2) {
      uVar8 = param_7[3];
      goto LAB_000694c0;
    }
    uVar8 = param_7[3];
    if (uVar8 != 3) goto LAB_000694c0;
  }
  else {
    uVar6 = param_8[3];
    uVar8 = param_7[3];
    uVar10 = param_8[1];
    uVar7 = param_8[2];
    uVar11 = *param_7;
    uVar2 = param_7[1];
    uVar1 = param_7[2];
LAB_000694c0:
    uVar14 = uVar14 | 0x400000;
    uVar15 = (uVar6 & 1) << 0xf |
             (uVar8 & 7) << 0xc |
             (uVar7 & 1) << 0xb |
             (uVar1 & 7) << 8 |
             (uVar10 & 1) << 7 | (uVar2 & 7) << 4 | (*param_8 & 1) << 3 | uVar11 & 7;
  }
  uVar1 = (param_9 & 0x3f) << 0x10 | param_10 & 0xffff;
  if (*param_12 == 0) {
    uVar11 = param_12[1];
    if (uVar11 != 0) {
      uVar7 = param_12[3];
      uVar10 = param_11[3];
      uVar8 = param_12[2];
      uVar12 = *param_11;
      uVar6 = param_11[1];
      uVar2 = param_11[2];
      goto LAB_000695f0;
    }
    uVar8 = param_12[2];
    if (uVar8 != 0) {
      uVar7 = param_12[3];
      uVar10 = param_11[3];
      uVar12 = *param_11;
      uVar6 = param_11[1];
      uVar2 = param_11[2];
      goto LAB_000695f0;
    }
    uVar7 = param_12[3];
    if (uVar7 != 0) {
      uVar10 = param_11[3];
      uVar12 = *param_11;
      uVar6 = param_11[1];
      uVar2 = param_11[2];
      goto LAB_000695f0;
    }
    uVar12 = *param_11;
    if (uVar12 != 0) {
      uVar10 = param_11[3];
      uVar6 = param_11[1];
      uVar2 = param_11[2];
      goto LAB_000695f0;
    }
    uVar6 = param_11[1];
    if (uVar6 != 1) {
      uVar10 = param_11[3];
      uVar2 = param_11[2];
      goto LAB_000695f0;
    }
    uVar2 = param_11[2];
    if (uVar2 != 2) {
      uVar10 = param_11[3];
      goto LAB_000695f0;
    }
    uVar10 = param_11[3];
    if (uVar10 != 3) goto LAB_000695f0;
  }
  else {
    uVar7 = param_12[3];
    uVar10 = param_11[3];
    uVar11 = param_12[1];
    uVar8 = param_12[2];
    uVar12 = *param_11;
    uVar6 = param_11[1];
    uVar2 = param_11[2];
LAB_000695f0:
    uVar1 = uVar1 | 0x400000;
    uVar16 = (uVar7 & 1) << 0xf |
             (uVar10 & 7) << 0xc |
             (uVar8 & 1) << 0xb |
             (uVar2 & 7) << 8 |
             (uVar11 & 1) << 7 | (uVar6 & 7) << 4 | (*param_12 & 1) << 3 | uVar12 & 7;
  }
  uVar2 = *puVar17;
  iVar18 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2) {
    uVar4 = (**(code **)(iVar18 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar18 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar2 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + *(int *)(param_1 + 0x75c)) = 0x49;
  uVar2 = *puVar17 + 1;
  *puVar17 = uVar2;
  iVar18 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2) {
    uVar4 = (**(code **)(iVar18 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar18 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar2 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar2 * 4 + *(int *)(param_1 + 0x75c)) = uVar5 | 0x40000;
  uVar5 = *puVar17 + 1;
  *puVar17 = uVar5;
  iVar18 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar5) {
    uVar4 = (**(code **)(iVar18 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar18 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar5 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) = uVar14;
  uVar5 = *puVar17 + 1;
  *puVar17 = uVar5;
  if ((uVar14 & 0x400000) != 0) {
    iVar18 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar5) {
      uVar4 = (**(code **)(iVar18 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
        (**(code **)(iVar18 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar5 = *puVar17;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    uVar5 = *puVar17 + 1;
    *puVar17 = uVar5;
  }
  iVar18 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar5) {
    uVar4 = (**(code **)(iVar18 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar18 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar5 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) = uVar1;
  uVar5 = *puVar17 + 1;
  *puVar17 = uVar5;
  if ((uVar1 & 0x400000) != 0) {
    iVar18 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar5) {
      uVar4 = (**(code **)(iVar18 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
        (**(code **)(iVar18 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar5 = *puVar17;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) = uVar16;
    uVar5 = *puVar17 + 1;
    *puVar17 = uVar5;
  }
  uVar6 = *param_15;
  uVar2 = *param_16;
  uVar7 = param_16[1];
  uVar8 = param_16[2];
  iVar18 = *(int *)(param_1 + 0x3d4);
  uVar15 = uStack_84 & 0xffff;
  uVar16 = uStack_84 & 0xffff;
  uVar10 = param_16[3];
  if (*(uint *)(param_1 + 0x758) <= uVar5) {
    uVar4 = (**(code **)(iVar18 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar18 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar5 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) = 0x41;
  uVar5 = *puVar17 + 1;
  *puVar17 = uVar5;
  iVar18 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar5) {
    uVar4 = (**(code **)(iVar18 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar18 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar5 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) = uVar16 | 0x40000;
  uVar5 = *puVar17 + 1;
  *puVar17 = uVar5;
  iVar18 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar5) {
    uVar4 = (**(code **)(iVar18 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar18 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar5 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) = uVar15 | uVar14 & 0xfe400000 | 0x440000;
  uVar5 = *puVar17 + 1;
  *puVar17 = uVar5;
  iVar18 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar5) {
    uVar4 = (**(code **)(iVar18 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar18 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar5 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined **)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) = ((unsigned char *)0x00003333);
  uVar5 = *puVar17 + 1;
  *puVar17 = uVar5;
  iVar18 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar5) {
    uVar4 = (**(code **)(iVar18 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar18 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar5 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) =
       (param_13 & 0x3f) << 0x10 | param_14 & 0xffff | uVar1 & 0xfe400000 | 0x400000;
  uVar5 = *puVar17 + 1;
  *puVar17 = uVar5;
  iVar18 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar5) {
    uVar4 = (**(code **)(iVar18 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar18 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar5 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) =
       (uVar10 & 1) << 0xf |
       (uVar6 & 7) << 0xc |
       (uVar8 & 1) << 0xb |
       (uVar6 & 7) << 8 | (uVar7 & 1) << 7 | (uVar6 & 7) << 4 | (uVar2 & 1) << 3 | uVar6 & 7;
  uVar5 = *puVar17 + 1;
  *puVar17 = uVar5;
  uVar14 = param_15[3];
  uVar15 = (param_2 & 0x3f) << 0x10 | param_3 & 0xffff;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    uVar15 = uVar15 | 0x400000;
    uVar13 = 0x55;
  }
  if (*param_4 == 0) {
    iVar18 = param_4[3];
    iVar9 = param_4[1];
    iVar3 = param_4[2];
  }
  else {
    iVar9 = param_4[1];
    if (iVar9 == 0) {
      iVar18 = param_4[3];
      iVar3 = param_4[2];
    }
    else {
      iVar3 = param_4[2];
      if (iVar3 == 0) {
        iVar18 = param_4[3];
      }
      else {
        if (param_4[3] != 0) goto LAB_00069f70;
        iVar18 = 0;
      }
    }
  }
  uVar15 = uVar15 | 0x400000;
  uVar13 = (uint)(iVar18 != 0) * 0x40 |
           (uint)(iVar3 != 0) * 0x10 | (uint)(iVar9 != 0) * 4 | (uint)(*param_4 != 0);
LAB_00069f70:
  uVar16 = *param_16;
  uVar6 = param_16[1];
  uVar2 = param_16[2];
  iVar18 = *(int *)(param_1 + 0x3d4);
  uVar1 = param_16[3];
  if (*(uint *)(param_1 + 0x758) <= uVar5) {
    uVar4 = (**(code **)(iVar18 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar18 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar5 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) = 0x44;
  uVar5 = *puVar17 + 1;
  *puVar17 = uVar5;
  iVar18 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar5) {
    uVar4 = (**(code **)(iVar18 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar18 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar5 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
  uVar5 = *puVar17 + 1;
  *puVar17 = uVar5;
  if ((uVar15 & 0x400000) != 0) {
    iVar18 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar5) {
      uVar4 = (**(code **)(iVar18 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
        (**(code **)(iVar18 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar5 = *puVar17;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
    uVar5 = *puVar17 + 1;
    *puVar17 = uVar5;
  }
  iVar18 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar5) {
    uVar4 = (**(code **)(iVar18 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar18 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar5 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) = uStack_84 & 0xffff | 0x440000;
  uVar5 = *puVar17 + 1;
  *puVar17 = uVar5;
  iVar18 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar5) {
    uVar4 = (**(code **)(iVar18 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar18 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar5 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined **)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) = ((unsigned char *)0x00003333);
  uVar5 = *puVar17 + 1;
  *puVar17 = uVar5;
  iVar18 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar5) {
    uVar4 = (**(code **)(iVar18 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar18 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar5 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) =
       (param_13 & 0x3f) << 0x10 | param_14 & 0xffff | 0x400000 | 0x400000;
  uVar5 = *puVar17 + 1;
  *puVar17 = uVar5;
  iVar18 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar5) {
    uVar4 = (**(code **)(iVar18 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar18 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar5 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar5 * 4 + *(int *)(param_1 + 0x75c)) =
       (uVar1 & 1) << 0xf |
       (uVar14 & 7) << 0xc |
       (uVar2 & 1) << 0xb |
       (uVar14 & 7) << 8 | (uVar6 & 1) << 7 | (uVar14 & 7) << 4 | (uVar16 & 1) << 3 | uVar14 & 7;
  *puVar17 = *puVar17 + 1;
  (**(code **)(param_1 + 0x74c))(param_1,auStack_88);
  return;
}

/* FUN_0006a400 @ 0x6a400 (1912 bytes) */
int FUN_0006a400(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  uint param_3;
  int *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
  uint param_9;
  uint param_10;
  uint *param_11;
  uint *param_12;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint *puVar18;
  
  uVar13 = (param_2 & 0x3f) << 0x10 | param_3 & 0xffff;
  puVar18 = (uint *)(param_1 + 0x754);
  uVar15 = 0;
  uVar17 = 0;
  uVar14 = 0;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    uVar13 = uVar13 | 0x400000;
    uVar14 = 0x55;
  }
  if (*param_4 == 0) {
    iVar16 = param_4[3];
    iVar8 = param_4[1];
    iVar2 = param_4[2];
LAB_0006a4f0:
    uVar13 = uVar13 | 0x400000;
    uVar14 = (uint)(iVar16 != 0) * 0x40 |
             (uint)(iVar2 != 0) * 0x10 | (uint)(iVar8 != 0) * 4 | (uint)(*param_4 != 0);
  }
  else {
    iVar8 = param_4[1];
    if (iVar8 == 0) {
      iVar16 = param_4[3];
      iVar2 = param_4[2];
      goto LAB_0006a4f0;
    }
    iVar2 = param_4[2];
    if (iVar2 == 0) {
      iVar16 = param_4[3];
      goto LAB_0006a4f0;
    }
    if (param_4[3] == 0) {
      iVar16 = 0;
      goto LAB_0006a4f0;
    }
  }
  uVar12 = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  if (*param_8 == 0) {
    uVar7 = param_8[1];
    if (uVar7 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar6 = param_8[2];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006a640;
    }
    uVar6 = param_8[2];
    if (uVar6 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006a640;
    }
    uVar5 = param_8[3];
    if (uVar5 != 0) {
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006a640;
    }
    uVar10 = *param_7;
    if (uVar10 != 0) {
      uVar9 = param_7[3];
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006a640;
    }
    uVar3 = param_7[1];
    if (uVar3 != 1) {
      uVar9 = param_7[3];
      uVar1 = param_7[2];
      goto LAB_0006a640;
    }
    uVar1 = param_7[2];
    if (uVar1 != 2) {
      uVar9 = param_7[3];
      goto LAB_0006a640;
    }
    uVar9 = param_7[3];
    if (uVar9 != 3) goto LAB_0006a640;
  }
  else {
    uVar5 = param_8[3];
    uVar9 = param_7[3];
    uVar7 = param_8[1];
    uVar6 = param_8[2];
    uVar10 = *param_7;
    uVar3 = param_7[1];
    uVar1 = param_7[2];
LAB_0006a640:
    uVar12 = uVar12 | 0x400000;
    uVar17 = (uVar5 & 1) << 0xf |
             (uVar9 & 7) << 0xc |
             (uVar6 & 1) << 0xb |
             (uVar1 & 7) << 8 |
             (uVar7 & 1) << 7 | (uVar3 & 7) << 4 | (*param_8 & 1) << 3 | uVar10 & 7;
  }
  uVar1 = (param_9 & 0x3f) << 0x10 | param_10 & 0xffff;
  if (*param_12 == 0) {
    uVar10 = param_12[1];
    if (uVar10 == 0) {
      uVar7 = param_12[2];
      if (uVar7 == 0) {
        uVar6 = param_12[3];
        if (uVar6 == 0) {
          uVar11 = *param_11;
          if (uVar11 == 0) {
            uVar5 = param_11[1];
            if (uVar5 == 1) {
              uVar3 = param_11[2];
              if (uVar3 == 2) {
                uVar9 = param_11[3];
                if (uVar9 == 3) goto LAB_0006a794;
              }
              else {
                uVar9 = param_11[3];
              }
            }
            else {
              uVar9 = param_11[3];
              uVar3 = param_11[2];
            }
          }
          else {
            uVar9 = param_11[3];
            uVar5 = param_11[1];
            uVar3 = param_11[2];
          }
        }
        else {
          uVar9 = param_11[3];
          uVar11 = *param_11;
          uVar5 = param_11[1];
          uVar3 = param_11[2];
        }
      }
      else {
        uVar6 = param_12[3];
        uVar9 = param_11[3];
        uVar11 = *param_11;
        uVar5 = param_11[1];
        uVar3 = param_11[2];
      }
    }
    else {
      uVar6 = param_12[3];
      uVar9 = param_11[3];
      uVar7 = param_12[2];
      uVar11 = *param_11;
      uVar5 = param_11[1];
      uVar3 = param_11[2];
    }
  }
  else {
    uVar6 = param_12[3];
    uVar9 = param_11[3];
    uVar10 = param_12[1];
    uVar7 = param_12[2];
    uVar11 = *param_11;
    uVar5 = param_11[1];
    uVar3 = param_11[2];
  }
  uVar1 = uVar1 | 0x400000;
  uVar15 = (uVar6 & 1) << 0xf |
           (uVar9 & 7) << 0xc |
           (uVar7 & 1) << 0xb |
           (uVar3 & 7) << 8 |
           (uVar10 & 1) << 7 | (uVar5 & 7) << 4 | (*param_12 & 1) << 3 | uVar11 & 7;
LAB_0006a794:
  uVar3 = *puVar18;
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = 0x44;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  if ((uVar13 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar3) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar3 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar14;
    uVar3 = *puVar18 + 1;
    *puVar18 = uVar3;
  }
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar12;
  uVar13 = *puVar18 + 1;
  *puVar18 = uVar13;
  if ((uVar12 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar13 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar17;
    uVar13 = *puVar18 + 1;
    *puVar18 = uVar13;
  }
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar13) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar13 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar1;
  uVar13 = *puVar18 + 1;
  *puVar18 = uVar13;
  if ((uVar1 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar13 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    *puVar18 = *puVar18 + 1;
  }
  return;
}

/* FUN_0006aba0 @ 0x6aba0 (1912 bytes) */
int FUN_0006aba0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  uint param_3;
  int *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
  uint param_9;
  uint param_10;
  uint *param_11;
  uint *param_12;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint *puVar18;
  
  uVar13 = (param_2 & 0x3f) << 0x10 | param_3 & 0xffff;
  puVar18 = (uint *)(param_1 + 0x754);
  uVar15 = 0;
  uVar17 = 0;
  uVar14 = 0;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    uVar13 = uVar13 | 0x400000;
    uVar14 = 0x55;
  }
  if (*param_4 == 0) {
    iVar16 = param_4[3];
    iVar8 = param_4[1];
    iVar2 = param_4[2];
LAB_0006ac90:
    uVar13 = uVar13 | 0x400000;
    uVar14 = (uint)(iVar16 != 0) * 0x40 |
             (uint)(iVar2 != 0) * 0x10 | (uint)(iVar8 != 0) * 4 | (uint)(*param_4 != 0);
  }
  else {
    iVar8 = param_4[1];
    if (iVar8 == 0) {
      iVar16 = param_4[3];
      iVar2 = param_4[2];
      goto LAB_0006ac90;
    }
    iVar2 = param_4[2];
    if (iVar2 == 0) {
      iVar16 = param_4[3];
      goto LAB_0006ac90;
    }
    if (param_4[3] == 0) {
      iVar16 = 0;
      goto LAB_0006ac90;
    }
  }
  uVar12 = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  if (*param_8 == 0) {
    uVar7 = param_8[1];
    if (uVar7 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar6 = param_8[2];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006ade0;
    }
    uVar6 = param_8[2];
    if (uVar6 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006ade0;
    }
    uVar5 = param_8[3];
    if (uVar5 != 0) {
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006ade0;
    }
    uVar10 = *param_7;
    if (uVar10 != 0) {
      uVar9 = param_7[3];
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006ade0;
    }
    uVar3 = param_7[1];
    if (uVar3 != 1) {
      uVar9 = param_7[3];
      uVar1 = param_7[2];
      goto LAB_0006ade0;
    }
    uVar1 = param_7[2];
    if (uVar1 != 2) {
      uVar9 = param_7[3];
      goto LAB_0006ade0;
    }
    uVar9 = param_7[3];
    if (uVar9 != 3) goto LAB_0006ade0;
  }
  else {
    uVar5 = param_8[3];
    uVar9 = param_7[3];
    uVar7 = param_8[1];
    uVar6 = param_8[2];
    uVar10 = *param_7;
    uVar3 = param_7[1];
    uVar1 = param_7[2];
LAB_0006ade0:
    uVar12 = uVar12 | 0x400000;
    uVar17 = (uVar5 & 1) << 0xf |
             (uVar9 & 7) << 0xc |
             (uVar6 & 1) << 0xb |
             (uVar1 & 7) << 8 |
             (uVar7 & 1) << 7 | (uVar3 & 7) << 4 | (*param_8 & 1) << 3 | uVar10 & 7;
  }
  uVar1 = (param_9 & 0x3f) << 0x10 | param_10 & 0xffff;
  if (*param_12 == 0) {
    uVar10 = param_12[1];
    if (uVar10 == 0) {
      uVar7 = param_12[2];
      if (uVar7 == 0) {
        uVar6 = param_12[3];
        if (uVar6 == 0) {
          uVar11 = *param_11;
          if (uVar11 == 0) {
            uVar5 = param_11[1];
            if (uVar5 == 1) {
              uVar3 = param_11[2];
              if (uVar3 == 2) {
                uVar9 = param_11[3];
                if (uVar9 == 3) goto LAB_0006af34;
              }
              else {
                uVar9 = param_11[3];
              }
            }
            else {
              uVar9 = param_11[3];
              uVar3 = param_11[2];
            }
          }
          else {
            uVar9 = param_11[3];
            uVar5 = param_11[1];
            uVar3 = param_11[2];
          }
        }
        else {
          uVar9 = param_11[3];
          uVar11 = *param_11;
          uVar5 = param_11[1];
          uVar3 = param_11[2];
        }
      }
      else {
        uVar6 = param_12[3];
        uVar9 = param_11[3];
        uVar11 = *param_11;
        uVar5 = param_11[1];
        uVar3 = param_11[2];
      }
    }
    else {
      uVar6 = param_12[3];
      uVar9 = param_11[3];
      uVar7 = param_12[2];
      uVar11 = *param_11;
      uVar5 = param_11[1];
      uVar3 = param_11[2];
    }
  }
  else {
    uVar6 = param_12[3];
    uVar9 = param_11[3];
    uVar10 = param_12[1];
    uVar7 = param_12[2];
    uVar11 = *param_11;
    uVar5 = param_11[1];
    uVar3 = param_11[2];
  }
  uVar1 = uVar1 | 0x400000;
  uVar15 = (uVar6 & 1) << 0xf |
           (uVar9 & 7) << 0xc |
           (uVar7 & 1) << 0xb |
           (uVar3 & 7) << 8 |
           (uVar10 & 1) << 7 | (uVar5 & 7) << 4 | (*param_12 & 1) << 3 | uVar11 & 7;
LAB_0006af34:
  uVar3 = *puVar18;
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = 0x41;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  if ((uVar13 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar3) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar3 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar14;
    uVar3 = *puVar18 + 1;
    *puVar18 = uVar3;
  }
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar12;
  uVar13 = *puVar18 + 1;
  *puVar18 = uVar13;
  if ((uVar12 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar13 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar17;
    uVar13 = *puVar18 + 1;
    *puVar18 = uVar13;
  }
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar13) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar13 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar1;
  uVar13 = *puVar18 + 1;
  *puVar18 = uVar13;
  if ((uVar1 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar13 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    *puVar18 = *puVar18 + 1;
  }
  return;
}

/* FUN_0006b340 @ 0x6b340 (1920 bytes) */
int FUN_0006b340(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  uint param_3;
  int *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
  uint param_9;
  uint param_10;
  uint *param_11;
  uint *param_12;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint *puVar18;
  
  uVar13 = (param_2 & 0x3f) << 0x10 | param_3 & 0xffff;
  puVar18 = (uint *)(param_1 + 0x754);
  uVar15 = 0;
  uVar17 = 0;
  uVar14 = 0;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    uVar13 = uVar13 | 0x400000;
    uVar14 = 0x55;
  }
  if (*param_4 == 0) {
    iVar16 = param_4[3];
    iVar8 = param_4[1];
    iVar2 = param_4[2];
LAB_0006b430:
    uVar13 = uVar13 | 0x400000;
    uVar14 = (uint)(iVar16 != 0) * 0x40 |
             (uint)(iVar2 != 0) * 0x10 | (uint)(iVar8 != 0) * 4 | (uint)(*param_4 != 0);
  }
  else {
    iVar8 = param_4[1];
    if (iVar8 == 0) {
      iVar16 = param_4[3];
      iVar2 = param_4[2];
      goto LAB_0006b430;
    }
    iVar2 = param_4[2];
    if (iVar2 == 0) {
      iVar16 = param_4[3];
      goto LAB_0006b430;
    }
    if (param_4[3] == 0) {
      iVar16 = 0;
      goto LAB_0006b430;
    }
  }
  uVar12 = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  if (*param_8 == 0) {
    uVar7 = param_8[1];
    if (uVar7 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar6 = param_8[2];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006b580;
    }
    uVar6 = param_8[2];
    if (uVar6 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006b580;
    }
    uVar5 = param_8[3];
    if (uVar5 != 0) {
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006b580;
    }
    uVar10 = *param_7;
    if (uVar10 != 0) {
      uVar9 = param_7[3];
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006b580;
    }
    uVar3 = param_7[1];
    if (uVar3 != 1) {
      uVar9 = param_7[3];
      uVar1 = param_7[2];
      goto LAB_0006b580;
    }
    uVar1 = param_7[2];
    if (uVar1 != 2) {
      uVar9 = param_7[3];
      goto LAB_0006b580;
    }
    uVar9 = param_7[3];
    if (uVar9 != 3) goto LAB_0006b580;
  }
  else {
    uVar5 = param_8[3];
    uVar9 = param_7[3];
    uVar7 = param_8[1];
    uVar6 = param_8[2];
    uVar10 = *param_7;
    uVar3 = param_7[1];
    uVar1 = param_7[2];
LAB_0006b580:
    uVar12 = uVar12 | 0x400000;
    uVar17 = (uVar5 & 1) << 0xf |
             (uVar9 & 7) << 0xc |
             (uVar6 & 1) << 0xb |
             (uVar1 & 7) << 8 |
             (uVar7 & 1) << 7 | (uVar3 & 7) << 4 | (*param_8 & 1) << 3 | uVar10 & 7;
  }
  uVar1 = (param_9 & 0x3f) << 0x10 | param_10 & 0xffff;
  if (*param_12 == 0) {
    uVar10 = param_12[1];
    if (uVar10 == 0) {
      uVar7 = param_12[2];
      if (uVar7 == 0) {
        uVar6 = param_12[3];
        if (uVar6 == 0) {
          uVar11 = *param_11;
          if (uVar11 == 0) {
            uVar5 = param_11[1];
            if (uVar5 == 1) {
              uVar3 = param_11[2];
              if (uVar3 == 2) {
                uVar9 = param_11[3];
                if (uVar9 == 3) goto LAB_0006b6d4;
              }
              else {
                uVar9 = param_11[3];
              }
            }
            else {
              uVar9 = param_11[3];
              uVar3 = param_11[2];
            }
          }
          else {
            uVar9 = param_11[3];
            uVar5 = param_11[1];
            uVar3 = param_11[2];
          }
        }
        else {
          uVar9 = param_11[3];
          uVar11 = *param_11;
          uVar5 = param_11[1];
          uVar3 = param_11[2];
        }
      }
      else {
        uVar6 = param_12[3];
        uVar9 = param_11[3];
        uVar11 = *param_11;
        uVar5 = param_11[1];
        uVar3 = param_11[2];
      }
    }
    else {
      uVar6 = param_12[3];
      uVar9 = param_11[3];
      uVar7 = param_12[2];
      uVar11 = *param_11;
      uVar5 = param_11[1];
      uVar3 = param_11[2];
    }
  }
  else {
    uVar6 = param_12[3];
    uVar9 = param_11[3];
    uVar10 = param_12[1];
    uVar7 = param_12[2];
    uVar11 = *param_11;
    uVar5 = param_11[1];
    uVar3 = param_11[2];
  }
  uVar1 = uVar1 | 0x400000;
  uVar15 = (uVar6 & 1) << 0xf |
           (uVar9 & 7) << 0xc |
           (uVar7 & 1) << 0xb |
           (uVar3 & 7) << 8 |
           (uVar10 & 1) << 7 | (uVar5 & 7) << 4 | (*param_12 & 1) << 3 | uVar11 & 7;
LAB_0006b6d4:
  uVar3 = *puVar18;
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = 0x50056;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  if ((uVar13 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar3) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar3 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar14;
    uVar3 = *puVar18 + 1;
    *puVar18 = uVar3;
  }
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar12;
  uVar13 = *puVar18 + 1;
  *puVar18 = uVar13;
  if ((uVar12 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar13 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar17;
    uVar13 = *puVar18 + 1;
    *puVar18 = uVar13;
  }
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar13) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar13 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar1;
  uVar13 = *puVar18 + 1;
  *puVar18 = uVar13;
  if ((uVar1 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar13 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    *puVar18 = *puVar18 + 1;
  }
  return;
}

/* FUN_0006bae0 @ 0x6bae0 (1920 bytes) */
int FUN_0006bae0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  uint param_3;
  int *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
  uint param_9;
  uint param_10;
  uint *param_11;
  uint *param_12;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint *puVar18;
  
  uVar13 = (param_2 & 0x3f) << 0x10 | param_3 & 0xffff;
  puVar18 = (uint *)(param_1 + 0x754);
  uVar15 = 0;
  uVar17 = 0;
  uVar14 = 0;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    uVar13 = uVar13 | 0x400000;
    uVar14 = 0x55;
  }
  if (*param_4 == 0) {
    iVar16 = param_4[3];
    iVar8 = param_4[1];
    iVar2 = param_4[2];
LAB_0006bbd0:
    uVar13 = uVar13 | 0x400000;
    uVar14 = (uint)(iVar16 != 0) * 0x40 |
             (uint)(iVar2 != 0) * 0x10 | (uint)(iVar8 != 0) * 4 | (uint)(*param_4 != 0);
  }
  else {
    iVar8 = param_4[1];
    if (iVar8 == 0) {
      iVar16 = param_4[3];
      iVar2 = param_4[2];
      goto LAB_0006bbd0;
    }
    iVar2 = param_4[2];
    if (iVar2 == 0) {
      iVar16 = param_4[3];
      goto LAB_0006bbd0;
    }
    if (param_4[3] == 0) {
      iVar16 = 0;
      goto LAB_0006bbd0;
    }
  }
  uVar12 = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  if (*param_8 == 0) {
    uVar7 = param_8[1];
    if (uVar7 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar6 = param_8[2];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006bd20;
    }
    uVar6 = param_8[2];
    if (uVar6 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006bd20;
    }
    uVar5 = param_8[3];
    if (uVar5 != 0) {
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006bd20;
    }
    uVar10 = *param_7;
    if (uVar10 != 0) {
      uVar9 = param_7[3];
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006bd20;
    }
    uVar3 = param_7[1];
    if (uVar3 != 1) {
      uVar9 = param_7[3];
      uVar1 = param_7[2];
      goto LAB_0006bd20;
    }
    uVar1 = param_7[2];
    if (uVar1 != 2) {
      uVar9 = param_7[3];
      goto LAB_0006bd20;
    }
    uVar9 = param_7[3];
    if (uVar9 != 3) goto LAB_0006bd20;
  }
  else {
    uVar5 = param_8[3];
    uVar9 = param_7[3];
    uVar7 = param_8[1];
    uVar6 = param_8[2];
    uVar10 = *param_7;
    uVar3 = param_7[1];
    uVar1 = param_7[2];
LAB_0006bd20:
    uVar12 = uVar12 | 0x400000;
    uVar17 = (uVar5 & 1) << 0xf |
             (uVar9 & 7) << 0xc |
             (uVar6 & 1) << 0xb |
             (uVar1 & 7) << 8 |
             (uVar7 & 1) << 7 | (uVar3 & 7) << 4 | (*param_8 & 1) << 3 | uVar10 & 7;
  }
  uVar1 = (param_9 & 0x3f) << 0x10 | param_10 & 0xffff;
  if (*param_12 == 0) {
    uVar10 = param_12[1];
    if (uVar10 == 0) {
      uVar7 = param_12[2];
      if (uVar7 == 0) {
        uVar6 = param_12[3];
        if (uVar6 == 0) {
          uVar11 = *param_11;
          if (uVar11 == 0) {
            uVar5 = param_11[1];
            if (uVar5 == 1) {
              uVar3 = param_11[2];
              if (uVar3 == 2) {
                uVar9 = param_11[3];
                if (uVar9 == 3) goto LAB_0006be74;
              }
              else {
                uVar9 = param_11[3];
              }
            }
            else {
              uVar9 = param_11[3];
              uVar3 = param_11[2];
            }
          }
          else {
            uVar9 = param_11[3];
            uVar5 = param_11[1];
            uVar3 = param_11[2];
          }
        }
        else {
          uVar9 = param_11[3];
          uVar11 = *param_11;
          uVar5 = param_11[1];
          uVar3 = param_11[2];
        }
      }
      else {
        uVar6 = param_12[3];
        uVar9 = param_11[3];
        uVar11 = *param_11;
        uVar5 = param_11[1];
        uVar3 = param_11[2];
      }
    }
    else {
      uVar6 = param_12[3];
      uVar9 = param_11[3];
      uVar7 = param_12[2];
      uVar11 = *param_11;
      uVar5 = param_11[1];
      uVar3 = param_11[2];
    }
  }
  else {
    uVar6 = param_12[3];
    uVar9 = param_11[3];
    uVar10 = param_12[1];
    uVar7 = param_12[2];
    uVar11 = *param_11;
    uVar5 = param_11[1];
    uVar3 = param_11[2];
  }
  uVar1 = uVar1 | 0x400000;
  uVar15 = (uVar6 & 1) << 0xf |
           (uVar9 & 7) << 0xc |
           (uVar7 & 1) << 0xb |
           (uVar3 & 7) << 8 |
           (uVar10 & 1) << 7 | (uVar5 & 7) << 4 | (*param_12 & 1) << 3 | uVar11 & 7;
LAB_0006be74:
  uVar3 = *puVar18;
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = 0x20056;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  if ((uVar13 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar3) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar3 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar14;
    uVar3 = *puVar18 + 1;
    *puVar18 = uVar3;
  }
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar12;
  uVar13 = *puVar18 + 1;
  *puVar18 = uVar13;
  if ((uVar12 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar13 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar17;
    uVar13 = *puVar18 + 1;
    *puVar18 = uVar13;
  }
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar13) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar13 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar1;
  uVar13 = *puVar18 + 1;
  *puVar18 = uVar13;
  if ((uVar1 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar13 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    *puVar18 = *puVar18 + 1;
  }
  return;
}

/* FUN_0006c280 @ 0x6c280 (1308 bytes) */
int FUN_0006c280(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  int *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint *puVar16;
  
  uVar12 = (param_2 & 0x3f) << 0x10 | param_3 & 0xffff;
  puVar16 = (uint *)(param_1 + 0x754);
  uVar15 = 0;
  uVar13 = 0;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    uVar12 = uVar12 | 0x400000;
    uVar13 = 0x55;
  }
  if (*param_4 == 0) {
    iVar14 = param_4[3];
    iVar8 = param_4[1];
    iVar2 = param_4[2];
LAB_0006c360:
    uVar12 = uVar12 | 0x400000;
    uVar13 = (uint)(iVar14 != 0) * 0x40 |
             (uint)(iVar2 != 0) * 0x10 | (uint)(iVar8 != 0) * 4 | (uint)(*param_4 != 0);
  }
  else {
    iVar8 = param_4[1];
    if (iVar8 == 0) {
      iVar14 = param_4[3];
      iVar2 = param_4[2];
      goto LAB_0006c360;
    }
    iVar2 = param_4[2];
    if (iVar2 == 0) {
      iVar14 = param_4[3];
      goto LAB_0006c360;
    }
    if (param_4[3] == 0) {
      iVar14 = 0;
      goto LAB_0006c360;
    }
  }
  uVar11 = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  if (*param_8 == 0) {
    uVar7 = param_8[1];
    if (uVar7 == 0) {
      uVar6 = param_8[2];
      if (uVar6 == 0) {
        uVar5 = param_8[3];
        if (uVar5 == 0) {
          uVar10 = *param_7;
          if (uVar10 == 0) {
            uVar3 = param_7[1];
            if (uVar3 == 1) {
              uVar1 = param_7[2];
              if (uVar1 == 2) {
                uVar9 = param_7[3];
                if (uVar9 == 3) goto LAB_0006c4d4;
              }
              else {
                uVar9 = param_7[3];
              }
            }
            else {
              uVar9 = param_7[3];
              uVar1 = param_7[2];
            }
          }
          else {
            uVar9 = param_7[3];
            uVar3 = param_7[1];
            uVar1 = param_7[2];
          }
        }
        else {
          uVar9 = param_7[3];
          uVar10 = *param_7;
          uVar3 = param_7[1];
          uVar1 = param_7[2];
        }
      }
      else {
        uVar5 = param_8[3];
        uVar9 = param_7[3];
        uVar10 = *param_7;
        uVar3 = param_7[1];
        uVar1 = param_7[2];
      }
    }
    else {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar6 = param_8[2];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
    }
  }
  else {
    uVar5 = param_8[3];
    uVar9 = param_7[3];
    uVar7 = param_8[1];
    uVar6 = param_8[2];
    uVar10 = *param_7;
    uVar3 = param_7[1];
    uVar1 = param_7[2];
  }
  uVar11 = uVar11 | 0x400000;
  uVar15 = (uVar5 & 1) << 0xf |
           (uVar9 & 7) << 0xc |
           (uVar6 & 1) << 0xb |
           (uVar1 & 7) << 8 | (uVar7 & 1) << 7 | (uVar3 & 7) << 4 | (*param_8 & 1) << 3 | uVar10 & 7
  ;
LAB_0006c4d4:
  uVar1 = *puVar16;
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = 0x54;
  uVar1 = *puVar16 + 1;
  *puVar16 = uVar1;
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar12;
  uVar1 = *puVar16 + 1;
  *puVar16 = uVar1;
  if ((uVar12 & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar1) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar1 = *puVar16;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
    uVar1 = *puVar16 + 1;
    *puVar16 = uVar1;
  }
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar11;
  uVar12 = *puVar16 + 1;
  *puVar16 = uVar12;
  if ((uVar11 & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar12) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar12 = *puVar16;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar12 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    *puVar16 = *puVar16 + 1;
  }
  return;
}

