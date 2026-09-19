#include "decls.h"

/* FUN_0008bb1c @ 0x8bb1c (1079 bytes) */
int FUN_0008bb1c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  int local_18;
  
  *param_3 = param_2;
  if (param_2 == 1) {
    if (*(uint *)(param_1 + 1000) != 0) {
      uVar3 = 0;
      iVar2 = param_1;
      do {
        if (((*(char *)(iVar2 + 0x6c4) == '\0') && (*(char *)(iVar2 + 0x6c5) == '\0')) &&
           (*(char *)(iVar2 + 0x6c6) == '\0')) {
          param_3[1] = uVar3;
          param_3[2] = DAT_001eea10;
          param_3[3] = DAT_001eea14;
          param_3[4] = DAT_001eea18;
          param_3[5] = DAT_001eea1c;
          param_3[6] = DAT_001eea00;
          param_3[7] = DAT_001eea04;
          param_3[8] = DAT_001eea08;
          param_3[9] = DAT_001eea0c;
          *(undefined1 *)(param_1 + 0x6c4 + uVar3 * 4) = 1;
          *(undefined1 *)(param_1 + 0x6c5 + uVar3 * 4) = 1;
          *(undefined1 *)(param_1 + 0x6c6 + uVar3 * 4) = 1;
          if (uVar3 < *(uint *)(param_1 + 0x3d0)) {
            return 0;
          }
          goto LAB_0008bd13;
        }
        uVar3 = uVar3 + 1;
        iVar2 = iVar2 + 4;
      } while (uVar3 != *(uint *)(param_1 + 1000));
    }
  }
  else if (param_2 == 0) {
    if (*(uint *)(param_1 + 1000) != 0) {
      uVar3 = 0;
      iVar2 = param_1;
      do {
        if (((*(char *)(iVar2 + 0x6c4) == '\0') && (*(char *)(iVar2 + 0x6c5) == '\0')) &&
           ((*(char *)(iVar2 + 0x6c6) == '\0' && (*(char *)(iVar2 + 0x6c7) == '\0')))) {
          param_3[1] = uVar3;
          param_3[2] = DAT_001ee9b0;
          param_3[3] = DAT_001ee9b4;
          param_3[4] = DAT_001ee9b8;
          param_3[5] = DAT_001ee9bc;
          param_3[6] = DAT_001ee9a0;
          param_3[7] = DAT_001ee9a4;
          param_3[8] = DAT_001ee9a8;
          param_3[9] = DAT_001ee9ac;
          *(undefined1 *)(param_1 + 0x6c4 + uVar3 * 4) = 1;
          *(undefined1 *)(param_1 + 0x6c5 + uVar3 * 4) = 1;
          *(undefined1 *)(param_1 + 0x6c6 + uVar3 * 4) = 1;
          *(undefined1 *)(param_1 + 0x6c7 + uVar3 * 4) = 1;
          if (uVar3 < *(uint *)(param_1 + 0x3d0)) {
            return 0;
          }
          goto LAB_0008bd13;
        }
        uVar3 = uVar3 + 1;
        iVar2 = iVar2 + 4;
      } while (uVar3 != *(uint *)(param_1 + 1000));
    }
  }
  else {
    if (param_2 != 2) {
      return 4;
    }
    if (*(uint *)(param_1 + 1000) != 0) {
      if (*(char *)(param_1 + 0x6c4) == '\0') {
        uVar3 = 0;
LAB_0008bcb8:
        param_3[1] = uVar3;
        param_3[2] = DAT_001ee990;
        param_3[3] = DAT_001ee994;
        param_3[4] = DAT_001ee998;
        param_3[5] = DAT_001ee99c;
        param_3[6] = DAT_00210694;
        param_3[7] = DAT_00210698;
        param_3[8] = DAT_0021069c;
        param_3[9] = DAT_002106a0;
        *(undefined1 *)(param_1 + 0x6c4 + uVar3 * 4) = 1;
        if (uVar3 < *(uint *)(param_1 + 0x3d0)) {
          return 0;
        }
      }
      else if (*(char *)(param_1 + 0x6c5) == '\0') {
        uVar3 = 0;
LAB_0008bc54:
        param_3[1] = uVar3;
        param_3[2] = DAT_001ee9f0;
        param_3[3] = DAT_001ee9f4;
        param_3[4] = DAT_001ee9f8;
        param_3[5] = DAT_001ee9fc;
        param_3[6] = DAT_001ee970;
        param_3[7] = DAT_001ee974;
        param_3[8] = DAT_001ee978;
        param_3[9] = DAT_001ee97c;
        *(undefined1 *)(param_1 + 0x6c5 + uVar3 * 4) = 1;
        if (uVar3 < *(uint *)(param_1 + 0x3d0)) {
          return 0;
        }
      }
      else if (*(char *)(param_1 + 0x6c6) == '\0') {
        uVar3 = 0;
LAB_0008bda4:
        param_3[1] = uVar3;
        param_3[2] = DAT_001ee9e0;
        param_3[3] = DAT_001ee9e4;
        param_3[4] = DAT_001ee9e8;
        param_3[5] = DAT_001ee9ec;
        param_3[6] = DAT_001ee980;
        param_3[7] = DAT_001ee984;
        param_3[8] = DAT_001ee988;
        param_3[9] = DAT_001ee98c;
        *(undefined1 *)(param_1 + 0x6c6 + uVar3 * 4) = 1;
        if (uVar3 < *(uint *)(param_1 + 0x3d0)) {
          return 0;
        }
      }
      else {
        if (*(char *)(param_1 + 0x6c7) == '\0') {
          uVar3 = 0;
        }
        else {
          local_18 = param_1;
          uVar3 = 0;
          do {
            uVar3 = uVar3 + 1;
            if (*(uint *)(param_1 + 1000) == uVar3) goto LAB_0008bb96;
            if (*(char *)(local_18 + 0x6c8) == '\0') goto LAB_0008bcb8;
            if (*(char *)(local_18 + 0x6c9) == '\0') goto LAB_0008bc54;
            if (*(char *)(local_18 + 0x6ca) == '\0') goto LAB_0008bda4;
            pcVar1 = (char *)(local_18 + 0x6cb);
            local_18 = local_18 + 4;
          } while (*pcVar1 != '\0');
        }
        param_3[1] = uVar3;
        param_3[2] = DAT_001ee9d0;
        param_3[3] = DAT_001ee9d4;
        param_3[4] = DAT_001ee9d8;
        param_3[5] = DAT_001ee9dc;
        param_3[6] = DAT_001ee960;
        param_3[7] = DAT_001ee964;
        param_3[8] = DAT_001ee968;
        param_3[9] = DAT_001ee96c;
        *(undefined1 *)(param_1 + 0x6c7 + uVar3 * 4) = 1;
        if (uVar3 < *(uint *)(param_1 + 0x3d0)) {
          return 0;
        }
      }
LAB_0008bd13:
      *(uint *)(param_1 + 0x3d0) = uVar3 + 1;
      return 0;
    }
  }
LAB_0008bb96:
  param_3[1] = -1;
  param_3[2] = DAT_002106a4;
  param_3[3] = DAT_002106a8;
  param_3[4] = DAT_002106ac;
  param_3[5] = DAT_002106b0;
  param_3[6] = DAT_001ee9c0;
  param_3[7] = DAT_001ee9c4;
  param_3[8] = DAT_001ee9c8;
  param_3[9] = DAT_001ee9cc;
  return 7;
}

/* FUN_0008bf53 @ 0x8bf53 (176 bytes) */
int FUN_0008bf53(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  
  iVar1 = *param_2;
  if (iVar1 == 1) {
    *(undefined1 *)(param_1 + 0x6c4 + param_2[1] * 4) = 0;
    *(undefined1 *)(param_1 + 0x6c5 + param_2[1] * 4) = 0;
    *(undefined1 *)(param_1 + 0x6c6 + param_2[1] * 4) = 0;
    return;
  }
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 0x6c4 + param_2[1] * 4) = 0;
    *(undefined1 *)(param_1 + 0x6c5 + param_2[1] * 4) = 0;
    *(undefined1 *)(param_1 + 0x6c6 + param_2[1] * 4) = 0;
    *(undefined1 *)(param_1 + 0x6c7 + param_2[1] * 4) = 0;
  }
  else if (iVar1 == 2) {
    iVar1 = param_2[6];
    if (iVar1 == 1) {
      *(undefined1 *)(param_1 + 0x6c5 + param_2[1] * 4) = 0;
      return;
    }
    if (iVar1 == 0) {
      *(undefined1 *)(param_1 + 0x6c4 + param_2[1] * 4) = 0;
      return;
    }
    if (iVar1 == 2) {
      *(undefined1 *)(param_1 + 0x6c6 + param_2[1] * 4) = 0;
      return;
    }
    if (iVar1 == 3) {
      *(undefined1 *)(param_1 + 0x6c7 + param_2[1] * 4) = 0;
      return;
    }
  }
  return;
}

/* FUN_0008c003 @ 0x8c003 (166 bytes) */
int FUN_0008c003(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 *param_4;
  int *param_5;
{
  uint uVar1;
  
  uVar1 = param_2 - 8;
  if (uVar1 < 2) {
    *param_4 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
    if (param_3 == 1) {
      *param_5 = *(int *)(param_1 + 0x2dc + uVar1 * 0x24);
    }
    else if (param_3 == 0) {
      *param_5 = *(int *)(param_1 + 0x2d8 + uVar1 * 0x24);
    }
    else if (param_3 == 2) {
      *param_5 = *(int *)(param_1 + 0x2e0 + uVar1 * 0x24);
    }
    else {
      if (param_3 != 3) {
        return '\x04';
      }
      *param_5 = *(int *)(param_1 + 0x2ec + uVar1 * 0x24);
    }
  }
  else {
    *param_4 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
    *param_5 = *(int *)(param_1 + 0xc + param_2 * 4);
  }
  return (*param_5 == -1) * '\x02';
}

/* FUN_0008c0a9 @ 0x8c0a9 (202 bytes) */
int FUN_0008c0a9(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  undefined4 *param_3;
  int *param_4;
  undefined4 *param_5;
{
  int iVar1;
  
  if (param_2 < 2) {
    *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
    *param_4 = *(int *)(param_1 + 0x58);
    iVar1 = *param_4;
  }
  else {
    if (3 < param_2) {
      return 4;
    }
    *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
    *param_4 = *(int *)(param_1 + 800 + (param_2 & 1) * 4);
    iVar1 = *param_4;
  }
  if (iVar1 == -1) {
    return 2;
  }
  iVar1 = (param_2 & 1) * 4;
  *param_5 = *(undefined4 *)((PTR_DAT_001eea60)[*(int *)(param_1 + 0x3d8)] + iVar1);
  param_5[1] = *(undefined4 *)((PTR_DAT_001eea60)[*(int *)(param_1 + 0x3d8)] + iVar1);
  param_5[2] = *(undefined4 *)((PTR_DAT_001eea60)[*(int *)(param_1 + 0x3d8)] + iVar1);
  param_5[3] = *(undefined4 *)((PTR_DAT_001eea60)[*(int *)(param_1 + 0x3d8)] + iVar1);
  return 0;
}

/* FUN_0008c173 @ 0x8c173 (5 bytes) */
int FUN_0008c173()
{
  return;
}

/* FUN_0008c178 @ 0x8c178 (598 bytes) */
int FUN_0008c178(param_1)
  undefined4 *param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar1 = param_1[0xf5];
  if (param_1[0xfe] == -1) {
    iVar7 = ((int (*)())FUN_0008bb1c)(param_1,0,param_1 + 0xfd);
    if (iVar7 != 0) {
      return 7;
    }
    uVar2 = *(undefined4 *)param_1[0xfc];
    uVar3 = param_1[0xfe];
    uVar4 = *(undefined4 *)(param_1[0xfb] + 8);
    iVar7 = param_1[0x2d];
    uVar5 = *(undefined4 *)(param_1[0xfb] + 4);
    uVar6 = *param_1;
    (**(code **)(iVar1 + 0x12ec))
              (param_1,uVar2,uVar3,&DAT_001ee9b0,uVar4,iVar7 + 3,&DAT_001ee9a0,&DAT_00210684,uVar5,
               uVar6,&DAT_001ee960,&DAT_00210684);
    (**(code **)(iVar1 + 0x12f4))
              (param_1,uVar2,uVar3,&DAT_001ee9b0,uVar4,iVar7 + 2,&DAT_001ee9a0,&DAT_00210684,uVar5,
               uVar6,&DAT_001ee980,&DAT_00210684,uVar2,uVar3,&DAT_001ee9a0,&DAT_00210684);
    (**(code **)(iVar1 + 0x12f4))
              (param_1,uVar2,uVar3,&DAT_001ee9b0,uVar4,iVar7 + 1,&DAT_001ee9a0,&DAT_00210684,uVar5,
               uVar6,&DAT_001ee970,&DAT_00210684,uVar2,uVar3,&DAT_001ee9a0,&DAT_00210684);
    (**(code **)(iVar1 + 0x12f4))
              (param_1,uVar2,uVar3,&DAT_001ee9b0,uVar4,iVar7,&DAT_001ee9a0,&DAT_00210684,uVar5,uVar6
               ,&DAT_00210694,&DAT_00210684,uVar2,uVar3,&DAT_001ee9a0,&DAT_00210684);
  }
  return 0;
}

/* FUN_0008c3ce @ 0x8c3ce (517 bytes) */
int FUN_0008c3ce(param_1)
  undefined4 *param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar1 = param_1[0xf5];
  if (param_1[0xfe] == -1) {
    iVar7 = ((int (*)())FUN_0008bb1c)(param_1,0,param_1 + 0xfd);
    if (iVar7 != 0) {
      return 7;
    }
    uVar2 = *(undefined4 *)param_1[0xfc];
    uVar3 = param_1[0xfe];
    uVar4 = *(undefined4 *)(param_1[0xfb] + 8);
    iVar7 = param_1[0x2d];
    uVar5 = *(undefined4 *)(param_1[0xfb] + 4);
    uVar6 = *param_1;
    (**(code **)(iVar1 + 0x12e4))
              (param_1,uVar2,uVar3,&DAT_001ee990,uVar4,iVar7,&DAT_001ee9a0,&DAT_00210684,uVar5,uVar6
               ,&DAT_001ee9a0,&DAT_00210684);
    (**(code **)(iVar1 + 0x12e4))
              (param_1,uVar2,uVar3,&DAT_001ee9f0,uVar4,iVar7 + 1,&DAT_001ee9a0,&DAT_00210684,uVar5,
               uVar6,&DAT_001ee9a0,&DAT_00210684);
    (**(code **)(iVar1 + 0x12e4))
              (param_1,uVar2,uVar3,&DAT_001ee9e0,uVar4,iVar7 + 2,&DAT_001ee9a0,&DAT_00210684,uVar5,
               uVar6,&DAT_001ee9a0,&DAT_00210684);
    (**(code **)(iVar1 + 0x12e4))
              (param_1,uVar2,uVar3,&DAT_001ee9d0,uVar4,iVar7 + 3,&DAT_001ee9a0,&DAT_00210684,uVar5,
               uVar6,&DAT_001ee9a0,&DAT_00210684);
  }
  return 0;
}

/* FUN_0008c5d3 @ 0x8c5d3 (252 bytes) */
int FUN_0008c5d3(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x510) == -1) {
    iVar3 = *(int *)(param_1 + 0x3f8);
    if (iVar3 == -1) {
      if ((*(byte *)((int)&switchdataD_000013c0 + iVar1) & 4) == 0) {
        ((int (*)())FUN_0008c3ce)();
      }
      else {
        ((int (*)())FUN_0008c178)();
      }
      iVar3 = *(int *)(param_1 + 0x3f8);
      if (iVar3 == -1) {
        return 2;
      }
    }
    iVar2 = ((int (*)())FUN_0008bb1c)(param_1,2,param_1 + 0x50c);
    if (iVar2 != 0) {
      return 7;
    }
    (**(code **)(iVar1 + 0x12e4))
              (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x510),
               param_1 + 0x514,**(undefined4 **)(param_1 + 0x3ec),iVar3,&DAT_001eea00,&DAT_00210684,
               **(undefined4 **)(param_1 + 0x3ec),iVar3,&DAT_001eea00,&DAT_00210684);
  }
  return 0;
}

/* FUN_0008c6cf @ 0x8c6cf (167 bytes) */
int FUN_0008c6cf(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x6a0) == -1) {
    iVar2 = ((int (*)())FUN_0008bb1c)(param_1,2,param_1 + 0x69c);
    if (iVar2 != 0) {
      return 7;
    }
    (**(code **)(iVar1 + 0x1314))
              (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x6a0),
               param_1 + 0x6a4,param_2,param_3,&DAT_001ee960,&DAT_00210684);
  }
  return 0;
}

/* FUN_0008c776 @ 0x8c776 (426 bytes) */
int FUN_0008c776(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x448) == -1) {
    iVar7 = ((int (*)())FUN_0008bb1c)(param_1,1,param_1 + 0x444);
    if (iVar7 != 0) {
      return 7;
    }
    uVar2 = **(undefined4 **)(param_1 + 0x3f0);
    uVar3 = *(undefined4 *)(param_1 + 0x448);
    uVar4 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
    iVar7 = *(int *)(param_1 + 0xc4);
    uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
    uVar6 = *(undefined4 *)(param_1 + 4);
    (**(code **)(iVar1 + 0x12e4))
              (param_1,uVar2,uVar3,&DAT_001ee990,uVar4,iVar7,&DAT_001eea00,&DAT_00210684,uVar5,uVar6
               ,&DAT_001eea00,&DAT_00210684);
    (**(code **)(iVar1 + 0x12e4))
              (param_1,uVar2,uVar3,&DAT_001ee9f0,uVar4,iVar7 + 1,&DAT_001eea00,&DAT_00210684,uVar5,
               uVar6,&DAT_001eea00,&DAT_00210684);
    (**(code **)(iVar1 + 0x12e4))
              (param_1,uVar2,uVar3,&DAT_001ee9e0,uVar4,iVar7 + 2,&DAT_001eea00,&DAT_00210684,uVar5,
               uVar6,&DAT_001eea00,&DAT_00210684);
  }
  return 0;
}

/* FUN_0008c920 @ 0x8c920 (635 bytes) */
int FUN_0008c920(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_58;
  int local_50;
  undefined1 local_44 [4];
  undefined4 local_40;
  undefined1 local_3c [16];
  undefined1 local_2c [28];
  
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x498) == -1) {
    if (*(char *)(iVar1 + 0x12a) == '\0') {
      local_50 = *(int *)(param_1 + 4);
      local_58 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
      iVar5 = ((int (*)())FUN_0008bb1c)(param_1,1,param_1 + 0x494);
      if (iVar5 != 0) {
        return 7;
      }
    }
    else {
      local_50 = *(int *)(param_1 + 0x448);
      if (local_50 == -1) {
        ((int (*)())FUN_0008c776)();
        local_50 = *(int *)(param_1 + 0x448);
        if (local_50 == -1) {
          return 2;
        }
      }
      local_58 = **(undefined4 **)(param_1 + 0x3ec);
      *(undefined4 *)(param_1 + 0x494) = *(undefined4 *)(param_1 + 0x444);
      *(int *)(param_1 + 0x498) = local_50;
      *(undefined4 *)(param_1 + 0x49c) = *(undefined4 *)(param_1 + 0x44c);
      *(undefined4 *)(param_1 + 0x4a0) = *(undefined4 *)(param_1 + 0x450);
      *(undefined4 *)(param_1 + 0x4a4) = *(undefined4 *)(param_1 + 0x454);
      *(undefined4 *)(param_1 + 0x4a8) = *(undefined4 *)(param_1 + 0x458);
      *(undefined4 *)(param_1 + 0x4ac) = *(undefined4 *)(param_1 + 0x45c);
      *(undefined4 *)(param_1 + 0x4b0) = *(undefined4 *)(param_1 + 0x460);
      *(undefined4 *)(param_1 + 0x4b4) = *(undefined4 *)(param_1 + 0x464);
      *(undefined4 *)(param_1 + 0x4b8) = *(undefined4 *)(param_1 + 0x468);
    }
    iVar5 = ((int (*)())FUN_0008bb1c)(param_1,2,local_44);
    if (iVar5 != 0) {
      return 7;
    }
    uVar2 = **(undefined4 **)(param_1 + 0x3f0);
    uVar3 = *(undefined4 *)(param_1 + 0x498);
    uVar4 = **(undefined4 **)(param_1 + 0x3ec);
    (**(code **)(iVar1 + 0x12e4))
              (param_1,uVar2,local_40,local_3c,local_58,local_50,&DAT_001eea00,&DAT_00210684,
               local_58,local_50,&DAT_001eea00,&DAT_00210684);
    (**(code **)(iVar1 + 0x1318))
              (param_1,uVar2,local_40,local_3c,uVar4,local_40,local_2c,&DAT_00210684);
    (**(code **)(iVar1 + 0x12ec))
              (param_1,uVar2,uVar3,&DAT_001eea10,uVar4,local_40,local_2c,&DAT_00210684,local_58,
               local_50,&DAT_001eea00,&DAT_00210684);
    ((int (*)())FUN_0008bf53)(param_1,local_44);
  }
  return 0;
}

/* FUN_0008cb9b @ 0x8cb9b (408 bytes) */
int FUN_0008cb9b(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_20;
  
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x470) == -1) {
    if (*(char *)(iVar1 + 0x12a) == '\0') {
      iVar4 = *(int *)(param_1 + 4);
      local_20 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
      iVar2 = ((int (*)())FUN_0008bb1c)(param_1,2,param_1 + 0x46c);
      if (iVar2 != 0) {
        return 7;
      }
      puVar3 = *(undefined4 **)(param_1 + 0x3ec);
    }
    else {
      iVar4 = *(int *)(param_1 + 0x448);
      if (iVar4 == -1) {
        ((int (*)())FUN_0008c776)();
        iVar4 = *(int *)(param_1 + 0x448);
        if (iVar4 == -1) {
          return 2;
        }
      }
      puVar3 = *(undefined4 **)(param_1 + 0x3ec);
      local_20 = *puVar3;
      *(undefined4 *)(param_1 + 0x46c) = *(undefined4 *)(param_1 + 0x444);
      *(int *)(param_1 + 0x470) = iVar4;
      *(undefined4 *)(param_1 + 0x474) = *(undefined4 *)(param_1 + 0x44c);
      *(undefined4 *)(param_1 + 0x478) = *(undefined4 *)(param_1 + 0x450);
      *(undefined4 *)(param_1 + 0x47c) = *(undefined4 *)(param_1 + 0x454);
      *(undefined4 *)(param_1 + 0x480) = *(undefined4 *)(param_1 + 0x458);
      *(undefined4 *)(param_1 + 0x484) = *(undefined4 *)(param_1 + 0x45c);
      *(undefined4 *)(param_1 + 0x488) = *(undefined4 *)(param_1 + 0x460);
      *(undefined4 *)(param_1 + 0x48c) = *(undefined4 *)(param_1 + 0x464);
      *(undefined4 *)(param_1 + 0x490) = *(undefined4 *)(param_1 + 0x468);
    }
    (**(code **)(iVar1 + 0x12ec))
              (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x470),
               &DAT_001eea10,puVar3[2],*(undefined4 *)(param_1 + 0x344),&DAT_00210694,&DAT_00210684,
               local_20,iVar4,&DAT_001eea00,&DAT_00210684);
  }
  return 0;
}

/* FUN_0008cd33 @ 0x8cd33 (657 bytes) */
int FUN_0008cd33(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x560) == -1) {
    iVar6 = ((int (*)())FUN_0008bb1c)(param_1,0,param_1 + 0x55c);
    if (iVar6 != 0) {
      return 7;
    }
    uVar2 = **(undefined4 **)(param_1 + 0x3f0);
    uVar3 = *(undefined4 *)(param_1 + 0x560);
    uVar4 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
    uVar5 = *(undefined4 *)(param_1 + 0x5c);
    if (param_2 < 4) {
      if (param_3 != '\0') {
        local_2c = DAT_002106a4;
        local_28 = DAT_002106a8;
        local_24 = DAT_002106ac;
        local_20 = DAT_002106b0;
        local_3c = DAT_001eea00;
        local_38 = DAT_001eea04;
        local_34 = DAT_001eea08;
        local_30 = DAT_001eea0c;
        if (param_2 == 1) {
          local_28 = 1;
          local_38 = 4;
          local_34 = 4;
        }
        else if (param_2 == 0) {
          local_2c = 1;
          local_3c = 4;
          local_38 = 4;
          local_34 = 4;
        }
        else if (param_2 == 2) {
          local_24 = 1;
          local_34 = 4;
        }
        else if (param_2 == 3) {
          local_20 = 1;
        }
        local_4c = 1;
        local_48 = 1;
        local_44 = 1;
        local_40 = 0;
        (**(code **)(iVar1 + 0x12e8))
                  (param_1,uVar2,uVar3,&DAT_001ee9b0,uVar4,uVar5,&local_3c,&DAT_00210684);
        (**(code **)(iVar1 + 0x12e4))
                  (param_1,uVar2,uVar3,&local_2c,**(undefined4 **)(param_1 + 0x3ec),uVar3,
                   &DAT_001eea40,&local_4c,**(undefined4 **)(param_1 + 0x3ec),uVar3,&DAT_001eea50,
                   &DAT_00210684);
        return 0;
      }
      (**(code **)(iVar1 + 0x12e8))
                (param_1,uVar2,uVar3,&DAT_001ee9b0,uVar4,uVar5,&DAT_001eea00,&DAT_00210684);
      return 0;
    }
    (**(code **)(iVar1 + 0x12e8))
              (param_1,uVar2,uVar3,&DAT_001ee9b0,uVar4,uVar5,&DAT_001ee9a0,&DAT_00210684);
  }
  return 0;
}

/* FUN_0008cfc4 @ 0x8cfc4 (219 bytes) */
int FUN_0008cfc4(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x538) == -1) {
    iVar3 = *(int *)(param_1 + 0x510);
    if (iVar3 == -1) {
      ((int (*)())FUN_0008c5d3)();
      iVar3 = *(int *)(param_1 + 0x510);
      if (iVar3 == -1) {
        return 2;
      }
    }
    iVar2 = ((int (*)())FUN_0008bb1c)(param_1,2,param_1 + 0x534);
    if (iVar2 != 0) {
      return 7;
    }
    (**(code **)(iVar1 + 0x1318))
              (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x538),
               param_1 + 0x53c,**(undefined4 **)(param_1 + 0x3ec),iVar3,param_1 + 0x524,
               &DAT_00210684);
  }
  return 0;
}

/* FUN_0008d09f @ 0x8d09f (304 bytes) */
int FUN_0008d09f(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_20;
  
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x420) == -1) {
    local_20 = *(int *)(param_1 + 0x538);
    if (local_20 == -1) {
      ((int (*)())FUN_0008cfc4)();
      local_20 = *(int *)(param_1 + 0x538);
      if (local_20 == -1) {
        return 2;
      }
    }
    iVar3 = *(int *)(param_1 + 0x3f8);
    if (iVar3 == -1) {
      if ((*(byte *)((int)&switchdataD_000013c0 + iVar1) & 4) == 0) {
        ((int (*)())FUN_0008c3ce)();
      }
      else {
        ((int (*)())FUN_0008c178)();
      }
      iVar3 = *(int *)(param_1 + 0x3f8);
      if (iVar3 == -1) {
        return 2;
      }
    }
    iVar2 = ((int (*)())FUN_0008bb1c)(param_1,1,param_1 + 0x41c);
    if (iVar2 != 0) {
      return 7;
    }
    (**(code **)(iVar1 + 0x12ec))
              (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x420),
               &DAT_001eea10,**(undefined4 **)(param_1 + 0x3ec),local_20,param_1 + 0x54c,
               &DAT_00210684,**(undefined4 **)(param_1 + 0x3ec),iVar3,&DAT_001eea00,&DAT_00210684);
  }
  return 0;
}

/* FUN_0008d1cf @ 0x8d1cf (591 bytes) */
int FUN_0008d1cf(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int local_54;
  undefined1 local_44 [4];
  undefined4 local_40;
  undefined1 local_3c [16];
  undefined1 local_2c [28];
  
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x4c0) != -1) {
    return 0;
  }
  local_54 = *(int *)(param_1 + 0x420);
  if (local_54 == -1) {
    ((int (*)())FUN_0008d09f)();
    local_54 = *(int *)(param_1 + 0x420);
    if (local_54 == -1) {
      return 2;
    }
  }
  if (*(char *)(iVar1 + 0x128) == '\0') {
    if (*(char *)(iVar1 + 300) == '\0') {
      iVar6 = *(int *)(param_1 + 0x448);
      if (iVar6 != -1) goto LAB_0008d255;
      ((int (*)())FUN_0008c776)();
      iVar6 = *(int *)(param_1 + 0x448);
    }
    else {
      iVar6 = *(int *)(param_1 + 0x470);
      if (iVar6 != -1) goto LAB_0008d255;
      ((int (*)())FUN_0008cb9b)();
      iVar6 = *(int *)(param_1 + 0x470);
    }
  }
  else {
    iVar6 = *(int *)(param_1 + 0x498);
    if (iVar6 != -1) goto LAB_0008d255;
    ((int (*)())FUN_0008c920)();
    iVar6 = *(int *)(param_1 + 0x498);
  }
  if (iVar6 == -1) {
    return 2;
  }
LAB_0008d255:
  iVar5 = ((int (*)())FUN_0008bb1c)(param_1,1,param_1 + 0x4bc);
  if (iVar5 == 0) {
    uVar2 = *(undefined4 *)(param_1 + 0x4c0);
    iVar5 = ((int (*)())FUN_0008bb1c)(param_1,2,local_44);
    if (iVar5 == 0) {
      uVar3 = **(undefined4 **)(param_1 + 0x3f0);
      uVar4 = **(undefined4 **)(param_1 + 0x3ec);
      (**(code **)(iVar1 + 0x12e4))
                (param_1,uVar3,local_40,local_3c,uVar4,local_54,&DAT_001eea00,&DAT_00210684,uVar4,
                 iVar6,&DAT_001eea00,&DAT_00210684);
      (**(code **)(iVar1 + 0x12f8))
                (param_1,uVar3,uVar2,&DAT_001eea10,uVar4,local_40,local_2c,&DAT_00210684,uVar4,iVar6
                 ,&DAT_001eea00,&DAT_001eea20,uVar4,local_54,&DAT_001eea00,&DAT_00210684);
      ((int (*)())FUN_0008bf53)(param_1,local_44);
      return 0;
    }
  }
  return 7;
}

/* FUN_0008d41e @ 0x8d41e (1060 bytes) */
int FUN_0008d41e(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int local_a4;
  undefined1 local_9c [4];
  undefined4 local_98;
  undefined1 local_94 [16];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_78;
  undefined1 local_74 [4];
  undefined4 local_70;
  undefined1 local_6c [16];
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x4e8) == -1) {
    local_a4 = *(int *)(param_1 + 0x4c0);
    if (local_a4 == -1) {
      ((int (*)())FUN_0008d1cf)();
      local_a4 = *(int *)(param_1 + 0x4c0);
      if (local_a4 == -1) {
        return 2;
      }
    }
    iVar5 = ((int (*)())FUN_0008bb1c)(param_1,1,param_1 + 0x4e4);
    if (iVar5 != 0) {
      return 7;
    }
    uVar2 = *(undefined4 *)(param_1 + 0x4e8);
    iVar5 = ((int (*)())FUN_0008bb1c)(param_1,2,local_74);
    if (iVar5 != 0) {
      return 7;
    }
    iVar5 = ((int (*)())FUN_0008bb1c)(param_1,2,local_9c);
    if (iVar5 != 0) {
      return 7;
    }
    uVar3 = **(undefined4 **)(param_1 + 0x3f0);
    uVar4 = **(undefined4 **)(param_1 + 0x3ec);
    (**(code **)(iVar1 + 0x12f0))
              (param_1,uVar3,local_70,local_6c,uVar4,local_70,&DAT_001eea40,&DAT_00210684,uVar4,
               local_70,&DAT_001eea40,&DAT_00210684);
    local_2c = 4;
    local_28 = 4;
    local_24 = local_54;
    local_20 = 4;
    (**(code **)(iVar1 + 0x12f4))
              (param_1,uVar3,uVar2,&DAT_001eea10,uVar4,local_70,&local_5c,&DAT_00210684,uVar4,
               local_a4,&DAT_001eea00,&DAT_00210684,uVar4,local_70,&local_2c,&DAT_00210684);
    (**(code **)(iVar1 + 0x12e4))
              (param_1,uVar3,local_70,local_6c,uVar4,uVar2,&DAT_001eea00,&DAT_00210684,uVar4,uVar2,
               &DAT_001eea00,&DAT_00210684);
    (**(code **)(iVar1 + 0x1318))
              (param_1,uVar3,local_70,local_6c,uVar4,local_70,&local_5c,&DAT_00210684);
    (**(code **)(iVar1 + 0x131c))
              (param_1,uVar3,local_98,local_94,uVar4,local_98,&DAT_001eea40,&DAT_001eea20);
    local_2c = local_5c;
    local_28 = local_58;
    local_24 = 4;
    local_20 = 4;
    local_3c = *(undefined4 *)(param_1 + 0x4d4);
    local_38 = *(undefined4 *)(param_1 + 0x4d8);
    local_34 = 4;
    local_30 = 4;
    local_4c = local_84;
    local_48 = local_80;
    local_44 = 4;
    local_40 = local_78;
    (**(code **)(iVar1 + 0x12f4))
              (param_1,uVar3,uVar2,&DAT_001eea10,uVar4,local_70,&local_2c,&DAT_00210684,uVar4,
               local_a4,&local_3c,&DAT_00210684,uVar4,local_98,&local_4c,&DAT_00210684);
    ((int (*)())FUN_0008bf53)(param_1,local_74);
    ((int (*)())FUN_0008bf53)(param_1,local_9c);
  }
  return 0;
}

/* FUN_0008d842 @ 0x8d842 (888 bytes) */
int FUN_0008d842(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined1 *local_78;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 *local_54;
  undefined1 local_44 [4];
  undefined4 local_40;
  undefined1 local_3c [16];
  undefined1 local_2c [28];
  
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x588) == -1) {
    local_6c = **(undefined4 **)(param_1 + 0x3f0);
    puVar7 = *(undefined4 **)(param_1 + 0x3ec);
    uVar2 = puVar7[2];
    uVar3 = *(undefined4 *)(param_1 + 0x330);
    if (*(short *)(*(int *)(*(int *)(iVar1 + 4) + 0x10) + 0x2e06) == -0x7bae) {
      if (*(int *)(param_1 + 0x3f8) == -1) {
        if ((*(byte *)((int)&switchdataD_000013c0 + iVar1) & 4) == 0) {
          ((int (*)())FUN_0008c3ce)();
        }
        else {
          ((int (*)())FUN_0008c178)();
        }
        if (*(int *)(param_1 + 0x3f8) == -1) {
          return 2;
        }
        puVar7 = *(undefined4 **)(param_1 + 0x3ec);
      }
      local_64 = *puVar7;
      local_60 = *(undefined4 *)(param_1 + 0x3f8);
      local_54 = &DAT_001ee980;
    }
    else {
      local_64 = puVar7[1];
      local_60 = *(undefined4 *)(param_1 + 0x50);
      iVar6 = *(int *)(param_1 + 0x54);
      if (iVar6 == 1) {
        local_54 = &DAT_001ee970;
      }
      else if (iVar6 == 0) {
        local_54 = &DAT_00210694;
      }
      else if (iVar6 == 2) {
        local_54 = &DAT_001ee980;
      }
      else if (iVar6 == 3) {
        local_54 = &DAT_001ee960;
      }
      else {
        local_54 = &DAT_001ee9a0;
      }
    }
    iVar6 = ((int (*)())FUN_0008bb1c)(param_1,2,param_1 + 0x584);
    if (iVar6 != 0) {
      return 7;
    }
    local_68 = *(undefined4 *)(param_1 + 0x588);
    iVar6 = ((int (*)())FUN_0008bb1c)(param_1,2,local_44);
    if (iVar6 != 0) {
      return 7;
    }
    iVar6 = *(int *)(param_1 + 0x3d4);
    iVar4 = *(int *)(*(int *)(iVar6 + 4) + 0x10);
    if ((*(short *)(iVar4 + 0x2e06) == -0x7bae) && (*(short *)(iVar4 + 0x2e08) == -0x7aa5)) {
      (**(code **)(iVar6 + 0x12e4))
                (param_1,local_6c,local_40,local_3c,local_64,local_60,&DAT_001eea00,&DAT_00210684,
                 local_64,local_60,&DAT_001eea00,&DAT_00210684);
    }
    else {
      (**(code **)(iVar6 + 0x12ec))
                (param_1,local_6c,local_40,local_3c,local_64,local_60,local_54,&DAT_00210684,
                 local_64,local_60,local_54,&DAT_00210684);
    }
    local_78 = local_3c;
    uVar5 = **(undefined4 **)(param_1 + 0x3ec);
    (**(code **)(iVar1 + 0x12ec))
              (param_1,local_6c,local_40,local_78,uVar2,uVar3,&DAT_001ee980,&DAT_00210684,uVar5,
               local_40,local_2c,&DAT_00210684);
    if (*(int *)(param_1 + 0x3d8) == 0) {
      if ((*(byte *)(iVar1 + 0x44) & 1) == 0) {
        local_6c = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
        local_68 = *(undefined4 *)(param_1 + 0x70);
        puVar7 = &DAT_001ee9d0;
      }
      else {
        puVar7 = (undefined4 *)(param_1 + 0x58c);
      }
    }
    else {
      local_6c = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
      local_68 = *(undefined4 *)(param_1 + 0x70);
      puVar7 = &DAT_001ee990;
    }
    (**(code **)(iVar1 + 0x1320))
              (param_1,local_6c,local_68,puVar7,uVar5,local_40,local_2c,&DAT_00210684);
    ((int (*)())FUN_0008bf53)(param_1,local_44);
  }
  return 0;
}

/* FUN_0008dbba @ 0x8dbba (373 bytes) */
int FUN_0008dbba(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  void *pvVar1;
  
  if (param_2 < 3) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(0x1998);
    *(int *)((int)pvVar1 + 0x3d4) = param_1;
    _memset(pvVar1,-1,0x68);
    _memset((void *)((int)pvVar1 + 0x68),-1,0x3c);
    _memset((void *)((int)pvVar1 + 0xa4),-1,0x324);
    *(undefined4 *)((int)pvVar1 + 0x3c8) = 0;
    *(undefined4 *)((int)pvVar1 + 0x3cc) = 0;
    *(undefined4 *)((int)pvVar1 + 0x3d0) = 0;
    *(uint *)((int)pvVar1 + 0x3d8) = param_2;
    *(undefined4 *)((int)pvVar1 + 0x3e0) = 0;
    *(undefined4 *)((int)pvVar1 + 0x3e4) = *(undefined4 *)(&DAT_001eeb68 + param_2 * 4);
    *(undefined4 *)((int)pvVar1 + 1000) = *(undefined4 *)(&DAT_001eeb60 + param_2 * 4);
    *(undefined **)((int)pvVar1 + 0x3ec) = (PTR_DAT_001eeb40)[param_2];
    *(undefined **)((int)pvVar1 + 0x3f0) = (PTR_DAT_001eeae0)[param_2];
    _memset((void *)((int)pvVar1 + 0x3f4),-1,0x2d0);
    _memset((void *)((int)pvVar1 + 0x6c4),0,0x80);
    *(undefined1 *)((int)pvVar1 + 0x744) = param_3;
    *(code **)((int)pvVar1 + 0x748) = FUN_0008bb1c;
    *(code **)((int)pvVar1 + 0x74c) = FUN_0008bf53;
    if (*(code **)(param_1 + 0x12d4) != (code *)0x0) {
      (**(code **)(param_1 + 0x12d4))(param_1,pvVar1);
      return pvVar1;
    }
  }
  else {
    pvVar1 = (void *)0x0;
  }
  return pvVar1;
}

/* FUN_0008dd2f @ 0x8dd2f (341 bytes) */
int FUN_0008dd2f(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  uint param_3;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 == (int *)0x0) {
    uVar3 = 1;
  }
  else {
    if ((param_1[0x1a] == -1) || (iVar1 = *param_1, iVar1 == -1)) {
      return 2;
    }
    if (param_2 != '\0') {
      if (7 < param_3) {
        return 3;
      }
      if (param_1[param_3 + 0x21] == -1) {
        return 2;
      }
    }
    iVar2 = param_1[0xf5];
    uVar3 = *(undefined4 *)(param_1[0xfb] + 4);
    (**(code **)(iVar2 + 0x12e8))
              (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001ee9b0,uVar3,iVar1,
               &DAT_001ee9a0,&DAT_00210684);
    if ((((char)param_1[0x1d1] != '\0') && (param_1[0x1a8] == -1)) &&
       (((int (*)())FUN_0008c6cf)(), param_1[0x1a8] == -1)) {
      return 2;
    }
    if (param_2 != '\0') {
      (**(code **)(iVar2 + 0x12e8))
                (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),param_1[param_3 + 0x21],&DAT_001ee9b0
                 ,uVar3,iVar1,&DAT_001ee9a0,&DAT_00210684);
    }
    uVar3 = 0;
  }
  return uVar3;
}

/* FUN_0008de84 @ 0x8de84 (417 bytes) */
int FUN_0008de84(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  int iVar1;
  int iVar2;
  undefined4 *local_28;
  undefined4 *local_20;
  
  if (param_1 == 0) {
    return 1;
  }
  if (param_2 == 3) {
    if (1 < param_4) {
      return 3;
    }
    iVar1 = *(int *)(param_1 + 0x74 + param_4 * 4);
    if ((iVar1 != -1) && (iVar2 = *(int *)(param_1 + 0xc + param_3 * 4), iVar2 != -1)) {
      if ((*(int *)(param_1 + 0x3d8) == 0) && (iVar1 == *(int *)(param_1 + 0x70))) {
        local_28 = &DAT_001eea10;
      }
      else {
        local_28 = &DAT_001ee9b0;
      }
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x12e8))
                (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc),iVar1,local_28,
                 *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),iVar2,&DAT_001ee9a0,&DAT_00210684);
      return 0;
    }
  }
  else {
    if (1 < param_4) {
      return 3;
    }
    iVar1 = *(int *)(param_1 + 0x7c + param_4 * 4);
    if ((iVar1 != -1) && (iVar2 = *(int *)(param_1 + 0xc + param_3 * 4), iVar2 != -1)) {
      if ((*(int *)(param_1 + 0x3d8) == 0) && (iVar1 == *(int *)(param_1 + 0x70))) {
        local_20 = &DAT_001eea10;
      }
      else {
        local_20 = &DAT_001ee9b0;
      }
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x12e8))
                (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x10),iVar1,local_20,
                 *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),iVar2,&DAT_001ee9a0,&DAT_00210684);
      return 0;
    }
  }
  return 2;
}

/* FUN_0008e025 @ 0x8e025 (347 bytes) */
int FUN_0008e025(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    uVar4 = 1;
  }
  else if (param_2 < 8) {
    iVar1 = *(int *)(param_1 + 0x84 + param_2 * 4);
    if (((iVar1 == -1) || (iVar2 = *(int *)(param_1 + 0x2c + param_2 * 4), iVar2 == -1)) ||
       ((*(char *)(param_1 + 0x744) != '\0' && (*(int *)(param_1 + 0xa4) == -1)))) {
      return 2;
    }
    uVar4 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x14);
    uVar3 = (*(undefined4 **)(param_1 + 0x3ec))[1];
    if (*(char *)(param_1 + 0x744) == '\0') {
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x12e8))
                (param_1,uVar4,iVar1,&DAT_001ee9b0,uVar3,iVar2,&DAT_001ee9a0,&DAT_00210684);
      uVar4 = 0;
    }
    else {
      if (*(int *)(param_1 + 0x6a0) == -1) {
        return 2;
      }
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x12ec))
                (param_1,uVar4,iVar1,&DAT_001ee9b0,uVar3,iVar2,&DAT_001ee9a0,&DAT_00210684,
                 **(undefined4 **)(param_1 + 0x3ec),*(int *)(param_1 + 0x6a0),param_1 + 0x6b4,
                 &DAT_00210684);
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 3;
  }
  return uVar4;
}

/* FUN_0008e180 @ 0x8e180 (146 bytes) */
int FUN_0008e180(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 1;
  }
  else {
    if ((*(int *)(param_1 + 0x6c) == -1) || (*(int *)(param_1 + 0x4c) == -1)) {
      return 2;
    }
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x12e8))
              (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x1c),*(int *)(param_1 + 0x6c),
               &DAT_001ee9b0,*(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),*(int *)(param_1 + 0x4c)
               ,&DAT_00210694,&DAT_00210684);
    uVar1 = 0;
  }
  return uVar1;
}

/* FUN_0008e212 @ 0x8e212 (348 bytes) */
int FUN_0008e212(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_1 == 0) {
    return 1;
  }
  iVar1 = *(int *)(param_1 + 0x70);
  if ((iVar1 == -1) || (*(int *)(param_1 + 0x50) == -1)) {
    return 2;
  }
  if ((3 < *(uint *)(param_1 + 0x54)) ||
     ((((*(int *)(param_1 + 0x3d8) == 0 && (iVar1 != *(int *)(param_1 + 0x74))) &&
       (iVar1 != *(int *)(param_1 + 0x78))) &&
      ((iVar1 != *(int *)(param_1 + 0x7c) && (iVar1 != *(int *)(param_1 + 0x80))))))) {
    return 3;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x3d4) + 0x12e) = 1;
  if ((*(byte *)(*(int *)(param_1 + 0x3d4) + 0x44) & 1) != 0) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x54);
  if (iVar1 == 1) {
    puVar2 = &DAT_001ee970;
  }
  else {
    if (iVar1 == 0) {
      puVar2 = &DAT_00210694;
      iVar1 = *(int *)(param_1 + 0x3d8);
      goto joined_r0x0008e2e4;
    }
    if (iVar1 == 2) {
      puVar2 = &DAT_001ee980;
    }
    else if (iVar1 == 3) {
      puVar2 = &DAT_001ee960;
    }
    else {
      puVar2 = &DAT_001ee9a0;
    }
  }
  iVar1 = *(int *)(param_1 + 0x3d8);
joined_r0x0008e2e4:
  if (iVar1 == 0) {
    puVar3 = &DAT_001ee9d0;
  }
  else {
    puVar3 = &DAT_001ee990;
  }
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x12e8))
            (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18),
             *(undefined4 *)(param_1 + 0x70),puVar3,*(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),
             *(undefined4 *)(param_1 + 0x50),puVar2,&DAT_00210684);
  return 0;
}

/* FUN_0008e36e @ 0x8e36e (421 bytes) */
int FUN_0008e36e(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 local_44 [4];
  undefined4 local_40;
  
  if (param_1 == 0) {
    uVar6 = 1;
  }
  else if (*(int *)(param_1 + 8) == -1) {
    uVar6 = 2;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x3d4);
    iVar5 = ((int (*)())FUN_0008bb1c)(param_1,0,local_44);
    if (iVar5 == 0) {
      uVar6 = **(undefined4 **)(param_1 + 0x3f0);
      uVar2 = (*(undefined4 **)(param_1 + 0x3ec))[1];
      uVar3 = *(undefined4 *)(param_1 + 8);
      uVar4 = **(undefined4 **)(param_1 + 0x3ec);
      (**(code **)(iVar1 + 0x12e4))
                (param_1,uVar6,local_40,&DAT_001ee9b0,uVar2,uVar3,&DAT_001eea40,&DAT_00210684,uVar2,
                 uVar3,&DAT_001eea40,&DAT_00210684);
      (**(code **)(iVar1 + 0x12ec))
                (param_1,uVar6,local_40,&DAT_001ee9b0,uVar2,uVar3,&DAT_001ee9a0,&DAT_00210684,uVar4,
                 local_40,&DAT_001ee9a0,&DAT_00210684);
      (**(code **)(iVar1 + 0x1310))
                (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 4),0,&DAT_001ee9b0,uVar4,
                 local_40,&DAT_001ee9a0,&DAT_00210684);
      ((int (*)())FUN_0008bf53)(param_1,local_44);
      return 0;
    }
    uVar6 = 7;
  }
  return uVar6;
}

/* FUN_0008e513 @ 0x8e513 (23 bytes) */
int FUN_0008e513(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = ((int (*)())FUN_0008d41e)();
    return uVar1;
  }
  return 1;
}

/* FUN_0008e52a @ 0x8e52a (1748 bytes) */
int FUN_0008e52a(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  uint param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  undefined4 local_b4;
  uint local_ac;
  undefined4 *local_a8;
  int *local_a4;
  int *local_a0;
  undefined1 local_94 [4];
  undefined4 local_90;
  undefined1 local_6c [4];
  undefined4 local_68;
  undefined1 local_44 [4];
  undefined4 local_40;
  
  if (param_1 == 0) {
    return 1;
  }
  if (4 < param_3) {
    return 4;
  }
  if (param_3 != 0) {
    uVar8 = 0;
    iVar10 = param_1;
    do {
      if (param_2[uVar8] == 0) {
        iVar5 = *(int *)(param_1 + 4);
      }
      else {
        if (param_2[uVar8] != 1) {
          return 3;
        }
        iVar5 = *(int *)(param_1 + 100);
      }
      if ((iVar5 == -1) || (*(int *)(iVar10 + 0xc4) == -1)) goto LAB_0008e60d;
      uVar8 = uVar8 + 1;
      iVar10 = iVar10 + 4;
    } while (param_3 != uVar8);
  }
  if ((param_3 < 4) && (param_4 != '\0')) {
    if (param_2[param_3] == 0) {
      if (*(int *)(param_1 + 4) == -1) {
        return 2;
      }
LAB_0008e5ce:
      if (*(int *)(param_1 + 0xc4 + param_3 * 4) != -1) goto LAB_0008e5db;
    }
    else {
      if (param_2[param_3] != 1) {
        return 3;
      }
      if (*(int *)(param_1 + 100) != -1) goto LAB_0008e5ce;
    }
LAB_0008e60d:
    uVar4 = 2;
  }
  else {
LAB_0008e5db:
    iVar10 = *(int *)(param_1 + 0x3d4);
    if (*(int *)(param_1 + 0x448) == -1) {
      if ((*(int *)(param_1 + 0x560) == -1) && (((int (*)())FUN_0008cd33)(), *(int *)(param_1 + 0x560) == -1)) {
        uVar4 = 2;
      }
      else {
        uVar4 = *(undefined4 *)(param_1 + 0x560);
        if (param_3 < 4) {
          param_3 = (param_3 + 1) - (uint)(param_4 == '\0');
        }
        iVar5 = ((int (*)())FUN_0008bb1c)(param_1,1,param_1 + 0x444);
        if (iVar5 == 0) {
          iVar5 = ((int (*)())FUN_0008bb1c)(param_1,0,local_44);
          if (iVar5 == 0) {
            iVar5 = ((int (*)())FUN_0008bb1c)(param_1,0,local_6c);
            if (iVar5 == 0) {
              iVar5 = ((int (*)())FUN_0008bb1c)(param_1,0,local_94);
              if (iVar5 == 0) {
                uVar1 = **(undefined4 **)(param_1 + 0x3f0);
                puVar6 = *(undefined4 **)(param_1 + 0x3ec);
                uVar2 = puVar6[2];
                uVar3 = puVar6[1];
                if (param_3 == 0) {
LAB_0008e755:
                  uVar2 = *(undefined4 *)(param_1 + 0x448);
                  uVar3 = *puVar6;
                  (**(code **)(iVar10 + 0x12e4))
                            (param_1,uVar1,uVar2,&DAT_001ee990,uVar3,local_40,&DAT_001ee9a0,
                             &DAT_00210684,uVar3,uVar4,&DAT_001ee9a0,&DAT_00210684);
                  (**(code **)(iVar10 + 0x12e4))
                            (param_1,uVar1,uVar2,&DAT_001ee9f0,uVar3,local_68,&DAT_001ee9a0,
                             &DAT_00210684,uVar3,uVar4,&DAT_001ee9a0,&DAT_00210684);
                  (**(code **)(iVar10 + 0x12e4))
                            (param_1,uVar1,uVar2,&DAT_001ee9e0,uVar3,local_90,&DAT_001ee9a0,
                             &DAT_00210684,uVar3,uVar4,&DAT_001ee9a0,&DAT_00210684);
                  ((int (*)())FUN_0008bf53)(param_1,local_44);
                  ((int (*)())FUN_0008bf53)(param_1,local_6c);
                  ((int (*)())FUN_0008bf53)(param_1,local_94);
                  return 0;
                }
                piVar9 = (int *)(param_1 + 0xc4);
LAB_0008e93e:
                local_a0 = param_2;
                local_a8 = &DAT_001ee990;
                local_ac = 0;
                iVar5 = *piVar9;
                iVar7 = *param_2;
                local_a4 = piVar9;
                if (iVar7 == 0) goto LAB_0008eb6e;
                do {
                  if (iVar7 == 1) {
                    local_b4 = *(undefined4 *)(param_1 + 100);
                  }
                  else {
                    local_b4 = 0;
                  }
                  while( true ) {
                    (**(code **)(iVar10 + 0x12e4))
                              (param_1,uVar1,local_40,local_a8,uVar2,iVar5,&DAT_001eea00,
                               &DAT_00210684,uVar3,local_b4,&DAT_001eea00,&DAT_00210684);
                    (**(code **)(iVar10 + 0x12e4))
                              (param_1,uVar1,local_68,local_a8,uVar2,iVar5 + 1,&DAT_001eea00,
                               &DAT_00210684,uVar3,local_b4,&DAT_001eea00,&DAT_00210684);
                    (**(code **)(iVar10 + 0x12e4))
                              (param_1,uVar1,local_90,local_a8,uVar2,iVar5 + 2,&DAT_001eea00,
                               &DAT_00210684,uVar3,local_b4,&DAT_001eea00,&DAT_00210684);
                    local_ac = local_ac + 1;
                    if (param_3 <= local_ac) {
                      puVar6 = *(undefined4 **)(param_1 + 0x3ec);
                      goto LAB_0008e755;
                    }
                    if (local_ac == 1) {
                      local_a8 = &DAT_001ee9f0;
                    }
                    else {
                      if (local_ac == 0) goto LAB_0008e93e;
                      local_a8 = &DAT_001ee9e0;
                      if (local_ac != 2) {
                        if (local_ac == 3) {
                          local_a8 = &DAT_001ee9d0;
                        }
                        else {
                          local_a8 = (undefined4 *)0x0;
                        }
                      }
                    }
                    local_a4 = local_a4 + 1;
                    local_a0 = local_a0 + 1;
                    iVar5 = *local_a4;
                    iVar7 = *local_a0;
                    if (iVar7 != 0) break;
LAB_0008eb6e:
                    local_b4 = *(undefined4 *)(param_1 + 4);
                  }
                } while( true );
              }
            }
          }
        }
        uVar4 = 7;
      }
    }
    else {
      uVar4 = 0;
    }
  }
  return uVar4;
}

/* FUN_0008ebfe @ 0x8ebfe (42 bytes) */
int FUN_0008ebfe(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 1;
  }
  if ((*(int *)(param_1 + 4) != -1) && (*(int *)(param_1 + 0x344) != -1)) {
    uVar1 = ((int (*)())FUN_0008cb9b)();
    return uVar1;
  }
  return 2;
}

/* FUN_0008ec28 @ 0x8ec28 (25 bytes) */
int FUN_0008ec28(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 4) != -1) {
    uVar1 = ((int (*)())FUN_0008c920)();
    return uVar1;
  }
  return 2;
}

/* FUN_0008ec41 @ 0x8ec41 (5383 bytes) */
int FUN_0008ec41(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  int *param_2;
  uint param_3;
  int param_4;
  int param_5;
  uint param_6;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 *puVar12;
  int *piVar13;
  undefined4 local_1bc;
  int local_1b8;
  int local_1a4;
  uint local_19c;
  undefined4 local_194;
  int local_184;
  uint local_17c;
  undefined4 *local_178;
  int *local_174;
  undefined1 *local_170;
  int *local_16c;
  int *local_168;
  undefined1 local_15c [4];
  undefined4 local_158;
  undefined1 local_134 [4];
  undefined4 local_130;
  undefined1 local_10c [4];
  undefined4 local_108;
  undefined1 local_e4 [4];
  undefined4 local_e0;
  undefined1 local_bc [4];
  undefined4 local_b8;
  undefined1 local_94 [4];
  int local_90;
  undefined1 local_6c [4];
  undefined4 local_68;
  undefined1 local_44 [4];
  int local_40;
  
  if (param_1 == (int *)0x0) {
    return 1;
  }
  if (4 < param_3) {
    return 4;
  }
  if (param_3 != 0) {
    uVar11 = 0;
    piVar13 = param_1;
    do {
      if (param_2[uVar11] == 0) {
        iVar6 = *param_1;
      }
      else {
        if (param_2[uVar11] != 1) {
          return 3;
        }
        iVar6 = param_1[0x18];
      }
      if (iVar6 == -1) {
        return 2;
      }
      if (piVar13[0x29] == -1) {
        return 2;
      }
      uVar11 = uVar11 + 1;
      piVar13 = piVar13 + 1;
    } while (param_3 != uVar11);
  }
  if ((param_3 < 4) && (param_4 != '\0')) {
    if (param_2[param_3] == 0) {
      if (*param_1 == -1) {
        return 2;
      }
    }
    else {
      if (param_2[param_3] != 1) {
        return 3;
      }
      if (param_1[0x18] == -1) {
        return 2;
      }
    }
    if (param_1[param_3 + 0x29] == -1) {
      return 2;
    }
  }
  if (param_1[0x1a] == -1) {
    return 2;
  }
  if (param_5 != '\0') {
    if (7 < param_6) {
      return 3;
    }
    if (param_1[param_6 + 0x21] == -1) {
      return 2;
    }
  }
  iVar6 = param_1[0xf5];
  if ((*(byte *)((int)&switchdataD_000013c0 + iVar6) & 4) == 0) {
    if ((param_1[0x158] == -1) && (((int (*)())FUN_0008cd33)(), param_1[0x158] == -1)) {
      return 2;
    }
    iVar1 = param_1[0x158];
    if (param_3 < 4) {
      param_3 = (param_3 + 1) - (uint)(param_4 == '\0');
    }
    iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_6c);
    if (iVar8 == 0) {
      iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_44);
      if (iVar8 == 0) {
        iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_bc);
        if (iVar8 == 0) {
          iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_15c);
          if (iVar8 == 0) {
            uVar2 = *(undefined4 *)param_1[0xfc];
            puVar12 = (undefined4 *)param_1[0xfb];
            uVar3 = *puVar12;
            uVar4 = puVar12[2];
            uVar5 = puVar12[1];
            if (param_3 == 0) {
LAB_0008f5ef:
              if (param_5 == '\0') {
                local_194 = *(undefined4 *)(param_1[0xfc] + 8);
                iVar8 = param_1[0x1a];
              }
              else {
                iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_94);
                if (iVar8 != 0) {
                  return 7;
                }
                local_194 = *(undefined4 *)param_1[0xfc];
                iVar8 = local_90;
              }
              (**(code **)(iVar6 + 0x12e4))
                        (param_1,local_194,iVar8,&DAT_001ee990,uVar3,local_68,&DAT_001ee9a0,
                         &DAT_00210684,uVar3,iVar1,&DAT_001ee9a0,&DAT_00210684);
              (**(code **)(iVar6 + 0x12e4))
                        (param_1,local_194,iVar8,&DAT_001ee9f0,uVar3,local_40,&DAT_001ee9a0,
                         &DAT_00210684,uVar3,iVar1,&DAT_001ee9a0,&DAT_00210684);
              (**(code **)(iVar6 + 0x12e4))
                        (param_1,local_194,iVar8,&DAT_001ee9e0,uVar3,local_b8,&DAT_001ee9a0,
                         &DAT_00210684,uVar3,iVar1,&DAT_001ee9a0,&DAT_00210684);
              if (((char)param_1[0x1d1] == '\0') || (param_1[0x1a8] != -1)) {
                (**(code **)(iVar6 + 0x12e4))
                          (param_1,local_194,iVar8,&DAT_001ee9d0,uVar3,local_158,&DAT_001ee9a0,
                           &DAT_00210684,uVar3,iVar1,&DAT_001ee9a0,&DAT_00210684);
                ((int (*)())FUN_0008bf53)(param_1,local_6c);
                ((int (*)())FUN_0008bf53)(param_1,local_44);
                ((int (*)())FUN_0008bf53)(param_1,local_bc);
                ((int (*)())FUN_0008bf53)(param_1,local_15c);
              }
              else {
                (**(code **)(iVar6 + 0x12e4))
                          (param_1,*(undefined4 *)param_1[0xfc],local_68,&DAT_001ee9d0,uVar3,
                           local_158,&DAT_001ee9a0,&DAT_00210684,uVar3,iVar1,&DAT_001ee9a0,
                           &DAT_00210684);
                (**(code **)(iVar6 + 0x12e8))
                          (param_1,local_194,iVar8,&DAT_001ee9d0,uVar3,local_68,&DAT_001ee960,
                           &DAT_00210684);
                ((int (*)())FUN_0008c6cf)();
                ((int (*)())FUN_0008bf53)(param_1,local_6c);
                ((int (*)())FUN_0008bf53)(param_1,local_44);
                ((int (*)())FUN_0008bf53)(param_1,local_bc);
                ((int (*)())FUN_0008bf53)(param_1,local_15c);
                if (param_1[0x1a8] == -1) {
                  ((int (*)())FUN_0008bf53)(param_1,local_94);
                  return 2;
                }
              }
              if (param_5 != '\0') {
                (**(code **)(iVar6 + 0x12e8))
                          (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001ee9b0,
                           uVar3,local_90,&DAT_001ee9a0,&DAT_00210684);
                (**(code **)(iVar6 + 0x12e8))
                          (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),param_1[param_6 + 0x21],
                           &DAT_001ee9b0,uVar3,local_90,&DAT_001ee9a0,&DAT_00210684);
                ((int (*)())FUN_0008bf53)(param_1,local_94);
                return 0;
              }
              return 0;
            }
            piVar13 = param_1 + 0x29;
LAB_0008ee6f:
            local_168 = param_2;
            local_178 = &DAT_001ee990;
            local_17c = 0;
            iVar8 = *piVar13;
            iVar9 = *param_2;
            local_16c = piVar13;
            if (iVar9 == 0) goto LAB_0008f120;
            do {
              if (iVar9 == 1) {
                local_184 = param_1[0x18];
              }
              else {
                local_184 = 0;
              }
              while( true ) {
                (**(code **)(iVar6 + 0x12e4))
                          (param_1,uVar2,local_68,local_178,uVar4,iVar8,&DAT_001ee9a0,&DAT_00210684,
                           uVar5,local_184,&DAT_001ee9a0,&DAT_00210684);
                (**(code **)(iVar6 + 0x12e4))
                          (param_1,uVar2,local_40,local_178,uVar4,iVar8 + 1,&DAT_001ee9a0,
                           &DAT_00210684,uVar5,local_184,&DAT_001ee9a0,&DAT_00210684);
                (**(code **)(iVar6 + 0x12e4))
                          (param_1,uVar2,local_b8,local_178,uVar4,iVar8 + 2,&DAT_001ee9a0,
                           &DAT_00210684,uVar5,local_184,&DAT_001ee9a0,&DAT_00210684);
                (**(code **)(iVar6 + 0x12e4))
                          (param_1,uVar2,local_158,local_178,uVar4,iVar8 + 3,&DAT_001ee9a0,
                           &DAT_00210684,uVar5,local_184,&DAT_001ee9a0,&DAT_00210684);
                local_17c = local_17c + 1;
                if (param_3 <= local_17c) goto LAB_0008f5ef;
                if (local_17c == 1) {
                  local_178 = &DAT_001ee9f0;
                }
                else {
                  if (local_17c == 0) goto LAB_0008ee6f;
                  if (local_17c == 2) {
                    local_178 = &DAT_001ee9e0;
                  }
                  else if (local_17c == 3) {
                    local_178 = &DAT_001ee9d0;
                  }
                  else {
                    local_178 = (undefined4 *)0x0;
                  }
                }
                local_16c = local_16c + 1;
                local_168 = local_168 + 1;
                iVar8 = *local_16c;
                iVar9 = *local_168;
                if (iVar9 != 0) break;
LAB_0008f120:
                local_184 = *param_1;
              }
            } while( true );
          }
        }
      }
    }
  }
  else {
    if ((param_1[0x158] == -1) && (((int (*)())FUN_0008cd33)(), param_1[0x158] == -1)) {
      return 2;
    }
    iVar1 = param_1[0x158];
    if (param_3 < 4) {
      param_3 = (param_3 + 1) - (uint)(param_4 == '\0');
    }
    iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_15c);
    if (iVar8 == 0) {
      iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_134);
      if (iVar8 == 0) {
        iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_10c);
        if (iVar8 == 0) {
          iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_e4);
          if (iVar8 == 0) {
            iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_44);
            if (iVar8 == 0) {
              puVar12 = (undefined4 *)param_1[0xfc];
              uVar2 = *puVar12;
              puVar10 = (undefined4 *)param_1[0xfb];
              uVar3 = *puVar10;
              uVar4 = puVar10[2];
              uVar5 = puVar10[1];
              if (param_3 != 0) {
                local_174 = param_1;
                local_19c = 0;
                local_170 = local_15c;
                do {
                  iVar8 = local_174[0x29];
                  uVar7 = *(undefined4 *)(local_170 + 4);
                  if (param_2[local_19c] == 0) {
                    local_1a4 = *param_1;
                  }
                  else if (param_2[local_19c] == 1) {
                    local_1a4 = param_1[0x18];
                  }
                  else {
                    local_1a4 = 0;
                  }
                  (**(code **)(iVar6 + 0x12ec))
                            (param_1,uVar2,uVar7,&DAT_001ee9b0,uVar4,iVar8 + 3,&DAT_001ee9a0,
                             &DAT_00210684,uVar5,local_1a4,&DAT_001ee960,&DAT_00210684);
                  (**(code **)(iVar6 + 0x12f4))
                            (param_1,uVar2,uVar7,&DAT_001ee9b0,uVar4,iVar8 + 2,&DAT_001ee9a0,
                             &DAT_00210684,uVar5,local_1a4,&DAT_001ee980,&DAT_00210684,uVar2,uVar7,
                             &DAT_001ee9a0,&DAT_00210684);
                  (**(code **)(iVar6 + 0x12f4))
                            (param_1,uVar2,uVar7,&DAT_001ee9b0,uVar4,iVar8 + 1,&DAT_001ee9a0,
                             &DAT_00210684,uVar5,local_1a4,&DAT_001ee970,&DAT_00210684,uVar2,uVar7,
                             &DAT_001ee9a0,&DAT_00210684);
                  (**(code **)(iVar6 + 0x12f4))
                            (param_1,uVar2,uVar7,&DAT_001ee9b0,uVar4,iVar8,&DAT_001ee9a0,
                             &DAT_00210684,uVar5,local_1a4,&DAT_00210694,&DAT_00210684,uVar2,uVar7,
                             &DAT_001ee9a0,&DAT_00210684);
                  local_19c = local_19c + 1;
                  local_174 = local_174 + 1;
                  local_170 = local_170 + 0x28;
                } while (param_3 != local_19c);
                puVar12 = (undefined4 *)param_1[0xfc];
                puVar10 = (undefined4 *)param_1[0xfb];
              }
              iVar8 = local_40;
              if (param_5 == '\0') {
                local_1bc = puVar12[2];
                local_1b8 = param_1[0x1a];
              }
              else {
                local_1bc = *puVar12;
                local_1b8 = local_40;
              }
              uVar2 = *puVar10;
              (**(code **)(iVar6 + 0x12ec))
                        (param_1,uVar2,local_40,&DAT_001ee9b0,uVar3,local_e0,&DAT_001ee9a0,
                         &DAT_00210684,uVar3,iVar1,&DAT_001ee960,&DAT_00210684);
              (**(code **)(iVar6 + 0x12f4))
                        (param_1,uVar2,iVar8,&DAT_001ee9b0,uVar3,local_108,&DAT_001ee9a0,
                         &DAT_00210684,uVar3,iVar1,&DAT_001ee980,&DAT_00210684,uVar2,iVar8,
                         &DAT_001ee9a0,&DAT_00210684);
              (**(code **)(iVar6 + 0x12f4))
                        (param_1,uVar2,iVar8,&DAT_001ee9b0,uVar3,local_130,&DAT_001ee9a0,
                         &DAT_00210684,uVar3,iVar1,&DAT_001ee970,&DAT_00210684,uVar2,iVar8,
                         &DAT_001ee9a0,&DAT_00210684);
              if (((char)param_1[0x1d1] == '\0') || (param_1[0x1a8] != -1)) {
                (**(code **)(iVar6 + 0x12f4))
                          (param_1,local_1bc,local_1b8,&DAT_001ee9b0,uVar3,local_158,&DAT_001ee9a0,
                           &DAT_00210684,uVar3,iVar1,&DAT_00210694,&DAT_00210684,uVar3,iVar8,
                           &DAT_001ee9a0,&DAT_00210684);
              }
              else {
                (**(code **)(iVar6 + 0x12f4))
                          (param_1,uVar2,iVar8,&DAT_001ee9b0,uVar3,local_158,&DAT_001ee9a0,
                           &DAT_00210684,uVar3,iVar1,&DAT_00210694,&DAT_00210684,uVar3,iVar8,
                           &DAT_001ee9a0,&DAT_00210684);
                if (param_5 == '\0') {
                  (**(code **)(iVar6 + 0x12e8))
                            (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001ee9b0,
                             uVar3,local_40,&DAT_001ee9a0,&DAT_00210684);
                }
                ((int (*)())FUN_0008c6cf)();
                if (param_1[0x1a8] == -1) {
                  ((int (*)())FUN_0008bf53)(param_1,local_15c);
                  ((int (*)())FUN_0008bf53)(param_1,local_134);
                  ((int (*)())FUN_0008bf53)(param_1,local_10c);
                  ((int (*)())FUN_0008bf53)(param_1,local_e4);
                  ((int (*)())FUN_0008bf53)(param_1,local_44);
                  return 2;
                }
              }
              if (param_5 != '\0') {
                (**(code **)(iVar6 + 0x12e8))
                          (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001ee9b0,
                           uVar3,local_40,&DAT_001ee9a0,&DAT_00210684);
                (**(code **)(iVar6 + 0x12e8))
                          (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),param_1[param_6 + 0x21],
                           &DAT_001ee9b0,uVar3,local_40,&DAT_001ee9a0,&DAT_00210684);
              }
              ((int (*)())FUN_0008bf53)(param_1,local_15c);
              ((int (*)())FUN_0008bf53)(param_1,local_134);
              ((int (*)())FUN_0008bf53)(param_1,local_10c);
              ((int (*)())FUN_0008bf53)(param_1,local_e4);
              ((int (*)())FUN_0008bf53)(param_1,local_44);
              return 0;
            }
          }
        }
      }
    }
  }
  return 7;
}

/* FUN_00090148 @ 0x90148 (5120 bytes) */
int FUN_00090148(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int *param_2;
  uint param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  int local_18c;
  uint local_184;
  undefined4 local_178;
  int local_16c;
  uint local_164;
  undefined4 *local_160;
  int *local_15c;
  undefined1 *local_158;
  int *local_154;
  int *local_150;
  int *local_14c;
  int *local_148;
  uint local_144;
  int local_140;
  undefined1 local_134 [4];
  undefined4 local_130;
  undefined1 local_10c [4];
  undefined4 local_108;
  undefined1 local_e4 [4];
  undefined4 local_e0;
  undefined1 local_bc [4];
  undefined4 local_b8;
  undefined1 local_94 [4];
  undefined4 local_90;
  undefined1 local_6c [4];
  undefined4 local_68;
  undefined1 local_44 [4];
  undefined4 local_40;
  
  if (param_1 == (int *)0x0) {
    return 1;
  }
  if (4 < param_3) {
    return 4;
  }
  if (param_3 != 0) {
    uVar11 = 0;
    piVar12 = param_1;
    do {
      if (param_2[uVar11] == 0) {
        iVar1 = *param_1;
      }
      else {
        if (param_2[uVar11] != 1) {
          return 3;
        }
        iVar1 = param_1[0x18];
      }
      if (iVar1 == -1) {
        return 2;
      }
      if (piVar12[0x2d] == -1) {
        return 2;
      }
      uVar11 = uVar11 + 1;
      piVar12 = piVar12 + 1;
    } while (param_3 != uVar11);
  }
  if ((param_3 < 4) && (param_4 != '\0')) {
    if (param_2[param_3] == 0) {
      if (*param_1 == -1) {
        return 2;
      }
    }
    else {
      if (param_2[param_3] != 1) {
        return 3;
      }
      if (param_1[0x18] == -1) {
        return 2;
      }
    }
    if (param_1[param_3 + 0x2d] == -1) {
      return 2;
    }
  }
  iVar1 = param_1[0xf5];
  if ((*(byte *)((int)&switchdataD_000013c0 + iVar1) & 4) == 0) {
    if (param_1[0xfe] == -1) {
      if ((param_1[0x158] == -1) && (((int (*)())FUN_0008cd33)(), param_1[0x158] == -1)) {
        return 2;
      }
      iVar4 = param_1[0x158];
      if (param_3 < 4) {
        param_3 = (param_3 + 1) - (uint)(param_4 == '\0');
      }
      iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,param_1 + 0xfd);
      if (iVar8 == 0) {
        iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_44);
        if (iVar8 == 0) {
          iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_6c);
          if (iVar8 == 0) {
            iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_94);
            if (iVar8 == 0) {
              iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_134);
              if (iVar8 == 0) {
                uVar5 = *(undefined4 *)param_1[0xfc];
                puVar9 = (undefined4 *)param_1[0xfb];
                uVar6 = puVar9[2];
                uVar7 = puVar9[1];
                if ((param_3 < 3) && (param_5 != '\0')) {
                  if (param_3 != 0) {
                    piVar12 = param_1 + 0x2d;
LAB_00091274:
                    local_178 = local_40;
                    local_148 = param_2;
                    local_164 = 0;
                    iVar8 = *piVar12;
                    iVar10 = *param_2;
                    local_14c = piVar12;
                    if (iVar10 == 0) goto LAB_0009150e;
                    do {
                      if (iVar10 == 1) {
                        local_16c = param_1[0x18];
                      }
                      else {
                        local_16c = 0;
                      }
                      while( true ) {
                        (**(code **)(iVar1 + 0x12e4))
                                  (param_1,uVar5,local_178,&DAT_001ee990,uVar6,iVar8,&DAT_001ee9a0,
                                   &DAT_00210684,uVar7,local_16c,&DAT_001ee9a0,&DAT_00210684);
                        (**(code **)(iVar1 + 0x12e4))
                                  (param_1,uVar5,local_178,&DAT_001ee9f0,uVar6,iVar8 + 1,
                                   &DAT_001ee9a0,&DAT_00210684,uVar7,local_16c,&DAT_001ee9a0,
                                   &DAT_00210684);
                        (**(code **)(iVar1 + 0x12e4))
                                  (param_1,uVar5,local_178,&DAT_001ee9e0,uVar6,iVar8 + 2,
                                   &DAT_001ee9a0,&DAT_00210684,uVar7,local_16c,&DAT_001ee9a0,
                                   &DAT_00210684);
                        (**(code **)(iVar1 + 0x12e4))
                                  (param_1,uVar5,local_178,&DAT_001ee9d0,uVar6,iVar8 + 3,
                                   &DAT_001ee9a0,&DAT_00210684,uVar7,local_16c,&DAT_001ee9a0,
                                   &DAT_00210684);
                        local_164 = local_164 + 1;
                        if (param_3 <= local_164) {
                          puVar9 = (undefined4 *)param_1[0xfb];
                          goto LAB_00090857;
                        }
                        if (local_164 == 0) goto LAB_00091274;
                        if (local_164 == 1) {
                          local_178 = local_68;
                        }
                        else {
                          local_178 = 0;
                        }
                        local_14c = local_14c + 1;
                        local_148 = local_148 + 1;
                        iVar8 = *local_14c;
                        iVar10 = *local_148;
                        if (iVar10 != 0) break;
LAB_0009150e:
                        local_16c = *param_1;
                      }
                    } while( true );
                  }
LAB_00090857:
                  iVar8 = param_1[0xfe];
                  uVar6 = *puVar9;
                  (**(code **)(iVar1 + 0x12ec))
                            (param_1,uVar5,iVar8,&DAT_001ee9b0,uVar6,iVar4,&DAT_00210694,
                             &DAT_00210684,uVar6,local_40,&DAT_001ee9a0,&DAT_00210684);
                  (**(code **)(iVar1 + 0x12f4))
                            (param_1,uVar5,iVar8,&DAT_001ee9b0,uVar6,iVar4,&DAT_001ee970,
                             &DAT_00210684,uVar6,local_68,&DAT_001ee9a0,&DAT_00210684,uVar6,iVar8,
                             &DAT_001ee9a0,&DAT_00210684);
                }
                else {
                  if (param_3 != 0) {
                    piVar12 = param_1 + 0x2d;
LAB_00090ed4:
                    local_150 = param_2;
                    local_160 = &DAT_001ee990;
                    local_144 = 0;
                    iVar8 = *piVar12;
                    iVar10 = *param_2;
                    local_154 = piVar12;
                    if (iVar10 == 0) goto LAB_00091183;
                    do {
                      if (iVar10 == 1) {
                        local_140 = param_1[0x18];
                      }
                      else {
                        local_140 = 0;
                      }
                      while( true ) {
                        (**(code **)(iVar1 + 0x12e4))
                                  (param_1,uVar5,local_40,local_160,uVar6,iVar8,&DAT_001ee9a0,
                                   &DAT_00210684,uVar7,local_140,&DAT_001ee9a0,&DAT_00210684);
                        (**(code **)(iVar1 + 0x12e4))
                                  (param_1,uVar5,local_68,local_160,uVar6,iVar8 + 1,&DAT_001ee9a0,
                                   &DAT_00210684,uVar7,local_140,&DAT_001ee9a0,&DAT_00210684);
                        (**(code **)(iVar1 + 0x12e4))
                                  (param_1,uVar5,local_90,local_160,uVar6,iVar8 + 2,&DAT_001ee9a0,
                                   &DAT_00210684,uVar7,local_140,&DAT_001ee9a0,&DAT_00210684);
                        (**(code **)(iVar1 + 0x12e4))
                                  (param_1,uVar5,local_130,local_160,uVar6,iVar8 + 3,&DAT_001ee9a0,
                                   &DAT_00210684,uVar7,local_140,&DAT_001ee9a0,&DAT_00210684);
                        local_144 = local_144 + 1;
                        if (param_3 <= local_144) {
                          puVar9 = (undefined4 *)param_1[0xfb];
                          goto LAB_00090a07;
                        }
                        if (local_144 == 1) {
                          local_160 = &DAT_001ee9f0;
                        }
                        else {
                          if (local_144 == 0) goto LAB_00090ed4;
                          local_160 = &DAT_001ee9e0;
                          if ((local_144 != 2) && (local_160 = (undefined4 *)0x0, local_144 == 3)) {
                            local_160 = &DAT_001ee9d0;
                          }
                        }
                        local_154 = local_154 + 1;
                        local_150 = local_150 + 1;
                        iVar8 = *local_154;
                        iVar10 = *local_150;
                        if (iVar10 != 0) break;
LAB_00091183:
                        local_140 = *param_1;
                      }
                    } while( true );
                  }
LAB_00090a07:
                  iVar8 = param_1[0xfe];
                  uVar6 = *puVar9;
                  (**(code **)(iVar1 + 0x12e4))
                            (param_1,uVar5,iVar8,&DAT_001ee990,uVar6,local_40,&DAT_001ee9a0,
                             &DAT_00210684,uVar6,iVar4,&DAT_001ee9a0,&DAT_00210684);
                  (**(code **)(iVar1 + 0x12e4))
                            (param_1,uVar5,iVar8,&DAT_001ee9f0,uVar6,local_68,&DAT_001ee9a0,
                             &DAT_00210684,uVar6,iVar4,&DAT_001ee9a0,&DAT_00210684);
                  (**(code **)(iVar1 + 0x12e4))
                            (param_1,uVar5,iVar8,&DAT_001ee9e0,uVar6,local_90,&DAT_001ee9a0,
                             &DAT_00210684,uVar6,iVar4,&DAT_001ee9a0,&DAT_00210684);
                  (**(code **)(iVar1 + 0x12e4))
                            (param_1,uVar5,iVar8,&DAT_001ee9d0,uVar6,local_130,&DAT_001ee9a0,
                             &DAT_00210684,uVar6,iVar4,&DAT_001ee9a0,&DAT_00210684);
                }
                ((int (*)())FUN_0008bf53)(param_1,local_44);
                ((int (*)())FUN_0008bf53)(param_1,local_6c);
                ((int (*)())FUN_0008bf53)(param_1,local_94);
                ((int (*)())FUN_0008bf53)(param_1,local_134);
                return 0;
              }
            }
          }
        }
      }
      return 7;
    }
  }
  else if (param_1[0xfe] == -1) {
    if ((param_1[0x158] == -1) && (((int (*)())FUN_0008cd33)(), param_1[0x158] == -1)) {
      return 2;
    }
    iVar4 = param_1[0x158];
    if (param_3 < 4) {
      param_3 = (param_3 + 1) - (uint)(param_4 == '\0');
    }
    iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,param_1 + 0xfd);
    if (iVar8 != 0) {
      return 7;
    }
    iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_134);
    if (iVar8 != 0) {
      return 7;
    }
    iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_10c);
    if (iVar8 != 0) {
      return 7;
    }
    iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_e4);
    if (iVar8 != 0) {
      return 7;
    }
    iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_bc);
    if (iVar8 != 0) {
      return 7;
    }
    uVar5 = *(undefined4 *)param_1[0xfc];
    puVar9 = (undefined4 *)param_1[0xfb];
    uVar6 = *puVar9;
    uVar7 = puVar9[2];
    uVar2 = puVar9[1];
    if (param_3 != 0) {
      local_15c = param_1;
      local_184 = 0;
      local_158 = local_134;
      do {
        iVar8 = local_15c[0x2d];
        uVar3 = *(undefined4 *)(local_158 + 4);
        if (param_2[local_184] == 0) {
          local_18c = *param_1;
        }
        else if (param_2[local_184] == 1) {
          local_18c = param_1[0x18];
        }
        else {
          local_18c = 0;
        }
        (**(code **)(iVar1 + 0x12ec))
                  (param_1,uVar5,uVar3,&DAT_001ee9b0,uVar7,iVar8 + 3,&DAT_001ee9a0,&DAT_00210684,
                   uVar2,local_18c,&DAT_001ee960,&DAT_00210684);
        (**(code **)(iVar1 + 0x12f4))
                  (param_1,uVar5,uVar3,&DAT_001ee9b0,uVar7,iVar8 + 2,&DAT_001ee9a0,&DAT_00210684,
                   uVar2,local_18c,&DAT_001ee980,&DAT_00210684,uVar5,uVar3,&DAT_001ee9a0,
                   &DAT_00210684);
        (**(code **)(iVar1 + 0x12f4))
                  (param_1,uVar5,uVar3,&DAT_001ee9b0,uVar7,iVar8 + 1,&DAT_001ee9a0,&DAT_00210684,
                   uVar2,local_18c,&DAT_001ee970,&DAT_00210684,uVar5,uVar3,&DAT_001ee9a0,
                   &DAT_00210684);
        (**(code **)(iVar1 + 0x12f4))
                  (param_1,uVar5,uVar3,&DAT_001ee9b0,uVar7,iVar8,&DAT_001ee9a0,&DAT_00210684,uVar2,
                   local_18c,&DAT_00210694,&DAT_00210684,uVar5,uVar3,&DAT_001ee9a0,&DAT_00210684);
        local_184 = local_184 + 1;
        local_15c = local_15c + 1;
        local_158 = local_158 + 0x28;
      } while (param_3 != local_184);
      puVar9 = (undefined4 *)param_1[0xfb];
    }
    uVar5 = *puVar9;
    iVar8 = param_1[0xfe];
    (**(code **)(iVar1 + 0x12ec))
              (param_1,uVar5,iVar8,&DAT_001ee9b0,uVar6,local_b8,&DAT_001ee9a0,&DAT_00210684,uVar6,
               iVar4,&DAT_001ee960,&DAT_00210684);
    (**(code **)(iVar1 + 0x12f4))
              (param_1,uVar5,iVar8,&DAT_001ee9b0,uVar6,local_e0,&DAT_001ee9a0,&DAT_00210684,uVar6,
               iVar4,&DAT_001ee980,&DAT_00210684,uVar5,iVar8,&DAT_001ee9a0,&DAT_00210684);
    (**(code **)(iVar1 + 0x12f4))
              (param_1,uVar5,iVar8,&DAT_001ee9b0,uVar6,local_108,&DAT_001ee9a0,&DAT_00210684,uVar6,
               iVar4,&DAT_001ee970,&DAT_00210684,uVar5,iVar8,&DAT_001ee9a0,&DAT_00210684);
    (**(code **)(iVar1 + 0x12f4))
              (param_1,uVar5,iVar8,&DAT_001ee9b0,uVar6,local_130,&DAT_001ee9a0,&DAT_00210684,uVar6,
               iVar4,&DAT_00210694,&DAT_00210684,uVar6,iVar8,&DAT_001ee9a0,&DAT_00210684);
    ((int (*)())FUN_0008bf53)(param_1,local_134);
    ((int (*)())FUN_0008bf53)(param_1,local_10c);
    ((int (*)())FUN_0008bf53)(param_1,local_e4);
    ((int (*)())FUN_0008bf53)(param_1,local_bc);
    return 0;
  }
  return 0;
}

/* FUN_00091548 @ 0x91548 (23 bytes) */
int FUN_00091548(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = ((int (*)())FUN_0008cfc4)();
    return uVar1;
  }
  return 1;
}

/* FUN_0009155f @ 0x9155f (23 bytes) */
int FUN_0009155f(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = ((int (*)())FUN_0008d09f)();
    return uVar1;
  }
  return 1;
}

/* FUN_00091576 @ 0x91576 (43 bytes) */
int FUN_00091576(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 1;
  }
  if (*(int *)(param_1 + 0x5c) != -1) {
    uVar1 = ((int (*)())FUN_0008cd33)();
    return uVar1;
  }
  return 2;
}

/* FUN_000915a1 @ 0x915a1 (2563 bytes) */
int FUN_000915a1(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_84;
  undefined4 local_80;
  undefined1 local_6c [4];
  undefined4 local_68;
  undefined1 local_44 [4];
  undefined4 local_40;
  
  if (param_1 == 0) {
    return 1;
  }
  if ((*(int *)(param_1 + 0x68) != -1) && (*(int *)(param_1 + 0xd4) != -1)) {
    if (param_2 != '\0') {
      if (7 < param_3) {
        return 3;
      }
      if (*(int *)(param_1 + 0x84 + param_3 * 4) == -1) {
        return 2;
      }
    }
    iVar1 = *(int *)(param_1 + 0x3d4);
    if ((*(byte *)((int)&switchdataD_000013c0 + iVar1) & 4) == 0) {
      if ((*(int *)(param_1 + 0x3f8) != -1) || (((int (*)())FUN_0008c3ce)(), *(int *)(param_1 + 0x3f8) != -1)) {
        if (param_2 == '\0') {
          local_84 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 8);
          local_80 = *(undefined4 *)(param_1 + 0x68);
        }
        else {
          iVar7 = ((int (*)())FUN_0008bb1c)(param_1,0,local_44);
          if (iVar7 != 0) {
            return 7;
          }
          local_84 = **(undefined4 **)(param_1 + 0x3f0);
          local_80 = local_40;
        }
        uVar2 = (*(undefined4 **)(param_1 + 0x3ec))[2];
        iVar7 = *(int *)(param_1 + 0xd4);
        uVar3 = **(undefined4 **)(param_1 + 0x3ec);
        uVar4 = *(undefined4 *)(param_1 + 0x3f8);
        (**(code **)(iVar1 + 0x12e4))
                  (param_1,local_84,local_80,&DAT_001ee990,uVar2,iVar7,&DAT_001ee9a0,&DAT_00210684,
                   uVar3,uVar4,&DAT_001ee9a0,&DAT_00210684);
        (**(code **)(iVar1 + 0x12e4))
                  (param_1,local_84,local_80,&DAT_001ee9f0,uVar2,iVar7 + 1,&DAT_001ee9a0,
                   &DAT_00210684,uVar3,uVar4,&DAT_001ee9a0,&DAT_00210684);
        (**(code **)(iVar1 + 0x12e4))
                  (param_1,local_84,local_80,&DAT_001ee9e0,uVar2,iVar7 + 2,&DAT_001ee9a0,
                   &DAT_00210684,uVar3,uVar4,&DAT_001ee9a0,&DAT_00210684);
        if ((*(char *)(param_1 + 0x744) == '\0') || (*(int *)(param_1 + 0x6a0) != -1)) {
          (**(code **)(iVar1 + 0x12e4))
                    (param_1,local_84,local_80,&DAT_001ee9d0,uVar2,iVar7 + 3,&DAT_001ee9a0,
                     &DAT_00210684,uVar3,uVar4,&DAT_001ee9a0,&DAT_00210684);
        }
        else {
          uVar5 = **(undefined4 **)(param_1 + 0x3f0);
          iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_6c);
          if (iVar8 != 0) {
            return 7;
          }
          (**(code **)(iVar1 + 0x12e4))
                    (param_1,uVar5,local_68,&DAT_001ee9d0,uVar2,iVar7 + 3,&DAT_001ee9a0,
                     &DAT_00210684,uVar3,uVar4,&DAT_001ee9a0,&DAT_00210684);
          (**(code **)(iVar1 + 0x12e8))
                    (param_1,local_84,local_80,&DAT_001ee9d0,uVar3,local_68,&DAT_001ee960,
                     &DAT_00210684);
          ((int (*)())FUN_0008c6cf)();
          ((int (*)())FUN_0008bf53)(param_1,local_6c);
          if (*(int *)(param_1 + 0x6a0) == -1) {
            return 2;
          }
        }
        if (param_2 != '\0') {
          uVar2 = **(undefined4 **)(param_1 + 0x3ec);
          (**(code **)(iVar1 + 0x12e8))
                    (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 8),
                     *(undefined4 *)(param_1 + 0x68),&DAT_001ee9b0,uVar2,local_40,&DAT_001ee9a0,
                     &DAT_00210684);
          (**(code **)(iVar1 + 0x12e8))
                    (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x14),
                     *(undefined4 *)(param_1 + 0x84 + param_3 * 4),&DAT_001ee9b0,uVar2,local_40,
                     &DAT_001ee9a0,&DAT_00210684);
          ((int (*)())FUN_0008bf53)(param_1,local_44);
        }
        return 0;
      }
    }
    else {
      uVar2 = **(undefined4 **)(param_1 + 0x3ec);
      if ((*(int *)(param_1 + 0x3f8) != -1) || (((int (*)())FUN_0008c178)(), *(int *)(param_1 + 0x3f8) != -1)) {
        iVar7 = ((int (*)())FUN_0008bb1c)(param_1,0,local_44);
        uVar3 = local_40;
        if (iVar7 != 0) {
          return 7;
        }
        if (param_2 == '\0') {
          local_9c = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 8);
          local_98 = *(undefined4 *)(param_1 + 0x68);
        }
        else {
          local_9c = **(undefined4 **)(param_1 + 0x3f0);
          local_98 = local_40;
        }
        uVar4 = (*(undefined4 **)(param_1 + 0x3ec))[2];
        iVar7 = *(int *)(param_1 + 0xd4);
        uVar5 = **(undefined4 **)(param_1 + 0x3ec);
        uVar6 = *(undefined4 *)(param_1 + 0x3f8);
        (**(code **)(iVar1 + 0x12ec))
                  (param_1,uVar5,local_40,&DAT_001ee9b0,uVar4,iVar7 + 3,&DAT_001ee9a0,&DAT_00210684,
                   uVar5,uVar6,&DAT_001ee960,&DAT_00210684);
        (**(code **)(iVar1 + 0x12f4))
                  (param_1,uVar5,uVar3,&DAT_001ee9b0,uVar4,iVar7 + 2,&DAT_001ee9a0,&DAT_00210684,
                   uVar5,uVar6,&DAT_001ee980,&DAT_00210684,uVar5,uVar3,&DAT_001ee9a0,&DAT_00210684);
        (**(code **)(iVar1 + 0x12f4))
                  (param_1,uVar5,uVar3,&DAT_001ee9b0,uVar4,iVar7 + 1,&DAT_001ee9a0,&DAT_00210684,
                   uVar5,uVar6,&DAT_001ee970,&DAT_00210684,uVar5,uVar3,&DAT_001ee9a0,&DAT_00210684);
        if ((*(char *)(param_1 + 0x744) == '\0') || (*(int *)(param_1 + 0x6a0) != -1)) {
          (**(code **)(iVar1 + 0x12f4))
                    (param_1,local_9c,local_98,&DAT_001ee9b0,uVar4,iVar7,&DAT_001ee9a0,&DAT_00210684
                     ,uVar5,uVar6,&DAT_00210694,&DAT_00210684,uVar2,local_40,&DAT_001ee9a0,
                     &DAT_00210684);
        }
        else {
          (**(code **)(iVar1 + 0x12f4))
                    (param_1,**(undefined4 **)(param_1 + 0x3ec),local_40,&DAT_001ee9b0,uVar4,iVar7,
                     &DAT_001ee9a0,&DAT_00210684,uVar5,uVar6,&DAT_00210694,&DAT_00210684,uVar2,
                     local_40,&DAT_001ee9a0,&DAT_00210684);
          if (param_2 == '\0') {
            (**(code **)(iVar1 + 0x12e8))
                      (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 8),
                       *(undefined4 *)(param_1 + 0x68),&DAT_001ee9b0,uVar2,local_40,&DAT_001ee9a0,
                       &DAT_00210684);
          }
          ((int (*)())FUN_0008c6cf)();
          if (*(int *)(param_1 + 0x6a0) == -1) {
            ((int (*)())FUN_0008bf53)(param_1,local_44);
            return 2;
          }
        }
        if (param_2 != '\0') {
          uVar2 = **(undefined4 **)(param_1 + 0x3ec);
          (**(code **)(iVar1 + 0x12e8))
                    (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 8),
                     *(undefined4 *)(param_1 + 0x68),&DAT_001ee9b0,uVar2,local_40,&DAT_001ee9a0,
                     &DAT_00210684);
          (**(code **)(iVar1 + 0x12e8))
                    (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x14),
                     *(undefined4 *)(param_1 + 0x84 + param_3 * 4),&DAT_001ee9b0,uVar2,local_40,
                     &DAT_001ee9a0,&DAT_00210684);
        }
        ((int (*)())FUN_0008bf53)(param_1,local_44);
        return 0;
      }
    }
  }
  return 2;
}

/* FUN_00091fa4 @ 0x91fa4 (69 bytes) */
int FUN_00091fa4(param_1)
  int *param_1;
{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    return 1;
  }
  if ((param_1[0x2d] != -1) && (*param_1 != -1)) {
    if ((*(byte *)((int)&switchdataD_000013c0 + param_1[0xf5]) & 4) == 0) {
      uVar1 = ((int (*)())FUN_0008c3ce)();
      return uVar1;
    }
    uVar1 = ((int (*)())FUN_0008c178)();
    return uVar1;
  }
  return 2;
}

/* FUN_00091fe9 @ 0x91fe9 (2577 bytes) */
int FUN_00091fe9(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  uint param_3;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 local_a4;
  int local_a0;
  undefined4 local_88;
  undefined1 local_6c [4];
  undefined4 local_68;
  undefined1 local_44 [4];
  int local_40;
  
  if (param_1 == (int *)0x0) {
    return 1;
  }
  iVar8 = param_1[0x1a];
  if (iVar8 == -1) {
    return 2;
  }
  if (param_1[0x29] == -1) {
    return 2;
  }
  if (*param_1 == -1) {
    return 2;
  }
  if (param_2 != '\0') {
    if (7 < param_3) {
      return 3;
    }
    if (param_1[param_3 + 0x21] == -1) {
      return 2;
    }
  }
  iVar1 = param_1[0xf5];
  if ((*(byte *)((int)&switchdataD_000013c0 + iVar1) & 4) == 0) {
    if (param_2 == '\0') {
      local_88 = *(undefined4 *)(param_1[0xfc] + 8);
    }
    else {
      iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_44);
      if (iVar8 != 0) goto LAB_000923bb;
      local_88 = *(undefined4 *)param_1[0xfc];
      iVar8 = local_40;
    }
    uVar9 = *(undefined4 *)(param_1[0xfb] + 8);
    iVar7 = param_1[0x29];
    uVar3 = *(undefined4 *)(param_1[0xfb] + 4);
    iVar5 = *param_1;
    (**(code **)(iVar1 + 0x12e4))
              (param_1,local_88,iVar8,&DAT_001ee990,uVar9,iVar7,&DAT_001ee9a0,&DAT_00210684,uVar3,
               iVar5,&DAT_001ee9a0,&DAT_00210684);
    (**(code **)(iVar1 + 0x12e4))
              (param_1,local_88,iVar8,&DAT_001ee9f0,uVar9,iVar7 + 1,&DAT_001ee9a0,&DAT_00210684,
               uVar3,iVar5,&DAT_001ee9a0,&DAT_00210684);
    (**(code **)(iVar1 + 0x12e4))
              (param_1,local_88,iVar8,&DAT_001ee9e0,uVar9,iVar7 + 2,&DAT_001ee9a0,&DAT_00210684,
               uVar3,iVar5,&DAT_001ee9a0,&DAT_00210684);
    if (((char)param_1[0x1d1] == '\0') || (param_1[0x1a8] != -1)) {
      (**(code **)(iVar1 + 0x12e4))
                (param_1,local_88,iVar8,&DAT_001ee9d0,uVar9,iVar7 + 3,&DAT_001ee9a0,&DAT_00210684,
                 uVar3,iVar5,&DAT_001ee9a0,&DAT_00210684);
    }
    else {
      uVar4 = *(undefined4 *)param_1[0xfc];
      uVar6 = *(undefined4 *)param_1[0xfb];
      iVar10 = ((int (*)())FUN_0008bb1c)(param_1,0,local_6c);
      if (iVar10 != 0) goto LAB_000923bb;
      (**(code **)(iVar1 + 0x12e4))
                (param_1,uVar4,local_68,&DAT_001ee9d0,uVar9,iVar7 + 3,&DAT_001ee9a0,&DAT_00210684,
                 uVar3,iVar5,&DAT_001ee9a0,&DAT_00210684);
      (**(code **)(iVar1 + 0x12e8))
                (param_1,local_88,iVar8,&DAT_001ee9d0,uVar6,local_68,&DAT_001ee960,&DAT_00210684);
      ((int (*)())FUN_0008c6cf)();
      ((int (*)())FUN_0008bf53)(param_1,local_6c);
      if (param_1[0x1a8] == -1) {
        return 2;
      }
    }
    if (param_2 == '\0') {
      uVar9 = 0;
    }
    else {
      uVar9 = *(undefined4 *)param_1[0xfb];
      (**(code **)(iVar1 + 0x12e8))
                (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001ee9b0,uVar9,
                 local_40,&DAT_001ee9a0,&DAT_00210684);
      (**(code **)(iVar1 + 0x12e8))
                (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),param_1[param_3 + 0x21],&DAT_001ee9b0
                 ,uVar9,local_40,&DAT_001ee9a0,&DAT_00210684);
      ((int (*)())FUN_0008bf53)(param_1,local_44);
      uVar9 = 0;
    }
  }
  else {
    uVar9 = *(undefined4 *)param_1[0xfb];
    iVar7 = ((int (*)())FUN_0008bb1c)(param_1,0,local_44);
    iVar8 = local_40;
    if (iVar7 == 0) {
      if (param_2 == '\0') {
        local_a4 = *(undefined4 *)(param_1[0xfc] + 8);
        local_a0 = param_1[0x1a];
      }
      else {
        local_a4 = *(undefined4 *)param_1[0xfc];
        local_a0 = local_40;
      }
      puVar2 = (undefined4 *)param_1[0xfb];
      uVar3 = puVar2[2];
      iVar7 = param_1[0x29];
      uVar4 = puVar2[1];
      iVar5 = *param_1;
      uVar6 = *puVar2;
      (**(code **)(iVar1 + 0x12ec))
                (param_1,uVar6,local_40,&DAT_001ee9b0,uVar3,iVar7 + 3,&DAT_001ee9a0,&DAT_00210684,
                 uVar4,iVar5,&DAT_001ee960,&DAT_00210684);
      (**(code **)(iVar1 + 0x12f4))
                (param_1,uVar6,iVar8,&DAT_001ee9b0,uVar3,iVar7 + 2,&DAT_001ee9a0,&DAT_00210684,uVar4
                 ,iVar5,&DAT_001ee980,&DAT_00210684,uVar6,iVar8,&DAT_001ee9a0,&DAT_00210684);
      (**(code **)(iVar1 + 0x12f4))
                (param_1,uVar6,iVar8,&DAT_001ee9b0,uVar3,iVar7 + 1,&DAT_001ee9a0,&DAT_00210684,uVar4
                 ,iVar5,&DAT_001ee970,&DAT_00210684,uVar6,iVar8,&DAT_001ee9a0,&DAT_00210684);
      if (((char)param_1[0x1d1] == '\0') || (param_1[0x1a8] != -1)) {
        (**(code **)(iVar1 + 0x12f4))
                  (param_1,local_a4,local_a0,&DAT_001ee9b0,uVar3,iVar7,&DAT_001ee9a0,&DAT_00210684,
                   uVar4,iVar5,&DAT_00210694,&DAT_00210684,uVar9,local_40,&DAT_001ee9a0,
                   &DAT_00210684);
      }
      else {
        (**(code **)(iVar1 + 0x12f4))
                  (param_1,*(undefined4 *)param_1[0xfb],local_40,&DAT_001ee9b0,uVar3,iVar7,
                   &DAT_001ee9a0,&DAT_00210684,uVar4,iVar5,&DAT_00210694,&DAT_00210684,uVar9,
                   local_40,&DAT_001ee9a0,&DAT_00210684);
        if (param_2 == '\0') {
          (**(code **)(iVar1 + 0x12e8))
                    (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001ee9b0,uVar9,
                     local_40,&DAT_001ee9a0,&DAT_00210684);
        }
        ((int (*)())FUN_0008c6cf)();
        if (param_1[0x1a8] == -1) {
          ((int (*)())FUN_0008bf53)(param_1,local_44);
          return 2;
        }
      }
      if (param_2 != '\0') {
        uVar9 = *(undefined4 *)param_1[0xfb];
        (**(code **)(iVar1 + 0x12e8))
                  (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001ee9b0,uVar9,
                   local_40,&DAT_001ee9a0,&DAT_00210684);
        (**(code **)(iVar1 + 0x12e8))
                  (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),param_1[param_3 + 0x21],
                   &DAT_001ee9b0,uVar9,local_40,&DAT_001ee9a0,&DAT_00210684);
      }
      ((int (*)())FUN_0008bf53)(param_1,local_44);
      return 0;
    }
LAB_000923bb:
    uVar9 = 7;
  }
  return uVar9;
}

/* FUN_000929fa @ 0x929fa (42 bytes) */
int FUN_000929fa(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 1;
  }
  if ((*(int *)(param_1 + 0xc4) != -1) && (*(int *)(param_1 + 4) != -1)) {
    uVar1 = ((int (*)())FUN_0008c776)();
    return uVar1;
  }
  return 2;
}

/* FUN_00092a24 @ 0x92a24 (124 bytes) */
int FUN_00092a24(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 0x330) == -1) || (iVar1 = *(int *)(param_1 + 0x70), iVar1 == -1)) {
    return 2;
  }
  if (*(short *)(*(int *)(*(int *)(*(int *)(param_1 + 0x3d4) + 4) + 0x10) + 0x2e06) == -0x7baf) {
    if (*(int *)(param_1 + 0x50) == -1) {
      return 2;
    }
    if (3 < *(uint *)(param_1 + 0x54)) {
      return 3;
    }
  }
  if ((((*(int *)(param_1 + 0x3d8) == 0) && (iVar1 != *(int *)(param_1 + 0x74))) &&
      (iVar1 != *(int *)(param_1 + 0x78))) &&
     ((iVar1 != *(int *)(param_1 + 0x7c) && (iVar1 != *(int *)(param_1 + 0x80))))) {
    return 3;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x3d4) + 0x12e) = 0;
  uVar2 = ((int (*)())FUN_0008d842)();
  return uVar2;
}

/* FUN_00092aa0 @ 0x92aa0 (2021 bytes) */
int FUN_00092aa0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 *param_1;
  uint param_2;
  int param_3;
  uint param_4;
  int param_5;
  uint param_6;
  uint param_7;
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 *local_a8;
  undefined *local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined1 local_6c [4];
  undefined4 local_68;
  undefined1 local_44 [4];
  undefined4 local_40;
  
  if ((param_5 == '\0') && (param_7 == 0)) {
    uVar9 = ((int (*)())FUN_0008e025)(param_1,param_2);
    return uVar9;
  }
  if (param_1 == (undefined4 *)0x0) {
    return 1;
  }
  if (((7 < param_2) || (7 < param_4)) || (7 < param_6)) {
    return 3;
  }
  if (((param_1[param_2 + 0x21] == -1) || (param_1[param_2 + 0xb] == -1)) ||
     ((*(char *)(param_1 + 0x1d1) != '\0' && (param_1[0x29] == -1)))) {
    return 2;
  }
  iVar1 = param_1[0xf5];
  if ((*(char *)(param_1 + 0x1d1) == '\0') && ((param_7 == 0 || (param_5 == '\0')))) {
    bVar6 = false;
  }
  else {
    iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_44);
    if (iVar8 != 0) {
      return 7;
    }
    bVar6 = true;
  }
  if (*(char *)(param_1 + 0x1d1) == '\0') {
    if (param_7 == 0) {
      local_b4 = *(undefined4 *)(param_1[0xfb] + 4);
      local_8c = param_1[param_2 + 0xb];
      local_ac = 0;
      local_b0 = 0;
      puVar11 = (undefined4 *)param_1[0xfc];
      local_90 = param_1[param_2 + 0x21];
    }
    else if (param_5 == '\0') {
      puVar11 = (undefined4 *)param_1[0xfc];
      local_ac = puVar11[5];
      local_90 = param_1[param_2 + 0x21];
      local_b4 = 0;
      local_8c = 0;
      local_b0 = local_90;
    }
    else {
      puVar11 = (undefined4 *)param_1[0xfc];
      local_ac = *puVar11;
      local_8c = local_40;
      local_b4 = *(undefined4 *)param_1[0xfb];
      local_b0 = local_40;
      local_90 = param_1[param_2 + 0x21];
    }
    local_84 = puVar11[5];
    if (param_7 == 0) {
      bVar7 = false;
      local_88 = 0;
      local_94 = 0;
      goto LAB_00092cc5;
    }
    bVar7 = false;
    local_88 = 0;
    local_94 = 0;
  }
  else {
    if (param_7 == 0) {
      local_b4 = *(undefined4 *)(param_1[0xfb] + 4);
      local_8c = param_1[param_2 + 0xb];
      local_88 = *(undefined4 *)param_1[0xfc];
      local_94 = local_40;
      local_90 = local_40;
      bVar7 = false;
      local_84 = local_88;
      goto LAB_00092cc5;
    }
    local_ac = *(undefined4 *)param_1[0xfc];
    local_b0 = local_40;
    if (param_5 == '\0') {
      local_94 = local_40;
      bVar7 = false;
      local_b4 = 0;
      local_8c = 0;
      local_84 = 0;
      local_90 = 0;
      local_88 = local_ac;
    }
    else {
      if (param_1[0x1a8] == -1) {
        if (!bVar6) {
          return 2;
        }
        ((int (*)())FUN_0008bf53)(param_1,local_44);
        return 2;
      }
      iVar8 = ((int (*)())FUN_0008bb1c)(param_1,0,local_6c);
      if (iVar8 != 0) {
        if (!bVar6) {
          return 7;
        }
        ((int (*)())FUN_0008bf53)(param_1,local_44);
        return 7;
      }
      local_b4 = *(undefined4 *)param_1[0xfb];
      local_8c = local_40;
      local_88 = *(undefined4 *)param_1[0xfc];
      local_94 = local_68;
      bVar7 = true;
      local_90 = local_94;
      local_84 = local_88;
    }
  }
  if (((((param_7 & 7) == 0) || ((param_7 & 0x38) == 0)) || ((param_7 & 0x1c0) == 0)) ||
     ((param_7 & 0xe00) == 0)) {
    (**(code **)(iVar1 + 0x12e8))
              (param_1,local_ac,local_b0,&DAT_001ee9b0,*(undefined4 *)(param_1[0xfb] + 4),
               param_1[param_2 + 0xb],&DAT_001ee9a0,&DAT_00210684);
  }
  puVar11 = param_1 + param_2 * 4 + 0xd2;
  iVar8 = 0;
  local_98 = &DAT_001eeaa0;
  do {
    uVar10 = param_7 >> ((byte)iVar8 & 0x1f) & 7;
    if (uVar10 == 0) goto LAB_00093195;
    iVar2 = param_1[0xf5];
    puVar3 = (undefined4 *)param_1[0xfb];
    uVar9 = puVar3[2];
    uVar4 = *puVar11;
    switch(uVar10) {
    case 1:
      uVar5 = *puVar3;
      iVar12 = param_1[0xfe];
      if (iVar12 == -1) {
        if ((*(byte *)((int)&switchdataD_000013c0 + iVar2) & 4) == 0) {
          ((int (*)())FUN_0008c3ce)();
        }
        else {
          ((int (*)())FUN_0008c178)();
        }
        iVar12 = param_1[0xfe];
      }
      (**(code **)(iVar2 + 0x12e4))
                (param_1,local_ac,local_b0,local_98,uVar9,uVar4,&DAT_001ee9a0,&DAT_00210684,uVar5,
                 iVar12,&DAT_001ee9a0,&DAT_00210684);
      break;
    case 2:
      (**(code **)(iVar2 + 0x12e4))
                (param_1,local_ac,local_b0,local_98,uVar9,uVar4,&DAT_001ee9a0,&DAT_00210684,
                 puVar3[1],*param_1,&DAT_001ee9a0,&DAT_00210684);
      break;
    case 3:
      uVar9 = *puVar3;
      iVar12 = param_1[0x13a];
      if (iVar12 == -1) {
        ((int (*)())FUN_0008d41e)();
        iVar12 = param_1[0x13a];
      }
      (**(code **)(iVar2 + 0x12e8))
                (param_1,local_ac,local_b0,local_98,uVar9,iVar12,&DAT_001ee9a0,&DAT_00210684);
      break;
    case 4:
      uVar9 = *puVar3;
      if (*(char *)(iVar2 + 0x128) == '\0') {
        if (*(char *)(iVar2 + 300) == '\0') {
          iVar12 = param_1[0x112];
          if (iVar12 == -1) {
            ((int (*)())FUN_0008c776)();
            iVar12 = param_1[0x112];
          }
        }
        else {
          iVar12 = param_1[0x11c];
          if (iVar12 == -1) {
            ((int (*)())FUN_0008cb9b)();
            iVar12 = param_1[0x11c];
          }
        }
      }
      else {
        iVar12 = param_1[0x126];
        if (iVar12 == -1) {
          ((int (*)())FUN_0008c920)();
          iVar12 = param_1[0x126];
        }
      }
      goto code_r0x00093161;
    case 5:
      uVar9 = *puVar3;
      iVar12 = param_1[0x130];
      if (iVar12 == -1) {
        ((int (*)())FUN_0008d1cf)();
        iVar12 = param_1[0x130];
      }
code_r0x00093161:
      (**(code **)(iVar2 + 0x12e8))
                (param_1,local_ac,local_b0,local_98,uVar9,iVar12,&DAT_001ee9a0,&DAT_00210684);
    }
LAB_00093195:
    iVar8 = iVar8 + 3;
    local_98 = local_98 + 0x10;
    puVar11 = puVar11 + 1;
  } while (iVar8 != 0xc);
LAB_00092cc5:
  if (param_5 != '\0') {
    if (param_3 == '\0') {
      local_a8 = &DAT_001ee9a0;
    }
    else {
      local_a8 = (undefined4 *)&DAT_001eea50;
    }
    uVar9 = *(undefined4 *)(param_1[0xfb] + 8);
    iVar8 = param_1[param_6 + 0x36];
    (**(code **)(iVar1 + 0x12e4))
              (param_1,local_84,local_90,&DAT_001ee990,uVar9,iVar8,&DAT_001ee9a0,&DAT_00210684,
               local_b4,local_8c,local_a8,&DAT_00210684);
    (**(code **)(iVar1 + 0x12e4))
              (param_1,local_84,local_90,&DAT_001ee9f0,uVar9,iVar8 + 1,&DAT_001ee9a0,&DAT_00210684,
               local_b4,local_8c,local_a8,&DAT_00210684);
    (**(code **)(iVar1 + 0x12e4))
              (param_1,local_84,local_90,&DAT_001ee9e0,uVar9,iVar8 + 2,&DAT_001ee9a0,&DAT_00210684,
               local_b4,local_8c,local_a8,&DAT_00210684);
    (**(code **)(iVar1 + 0x12e4))
              (param_1,local_84,local_90,&DAT_001ee9d0,uVar9,iVar8 + 3,&DAT_001ee9a0,&DAT_00210684,
               local_b4,local_8c,local_a8,&DAT_00210684);
  }
  if (*(char *)(param_1 + 0x1d1) != '\0') {
    (**(code **)(iVar1 + 0x12ec))
              (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),param_1[param_2 + 0x21],&DAT_001ee9b0,
               local_88,local_94,&DAT_001ee9a0,&DAT_00210684,*(undefined4 *)param_1[0xfb],
               param_1[0x1a8],param_1 + 0x1ad,&DAT_00210684);
  }
  if (bVar6) {
    ((int (*)())FUN_0008bf53)(param_1,local_44);
  }
  if (bVar7) {
    ((int (*)())FUN_0008bf53)(param_1,local_6c);
  }
  return 0;
}

/* FUN_00093589 @ 0x93589 (2278 bytes) */
int FUN_00093589(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  uint local_8c;
  uint local_74;
  int local_6c;
  int local_68;
  uint local_50;
  undefined4 local_44 [2];
  int local_3c [2];
  int local_34 [2];
  undefined1 local_2c [4];
  int local_28;
  undefined1 local_24 [4];
  undefined4 local_20 [4];
  
  if (param_1 == 0) {
    return 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  iVar2 = *(int *)(*(int *)(iVar1 + 4) + 0x10);
  local_8c = 0;
  iVar11 = param_1;
  do {
    iVar8 = ((int (*)())FUN_0008c003)(local_2c,local_24);
    if (iVar8 != 0) {
      return iVar8;
    }
    iVar8 = ((int (*)())FUN_0008c003)(local_2c,local_24);
    if (iVar8 != 0) {
      return iVar8;
    }
    if ((*(int *)(iVar1 + 0x13c) == 1) && (*(int *)(iVar11 + 0x2f8) == -1)) {
      return 2;
    }
    local_8c = local_8c + 1;
    iVar11 = iVar11 + 0x24;
  } while (local_8c <= *(byte *)(iVar2 + 0x2d4c));
  if (*(int *)(param_1 + 0x328) == -1) {
    return 2;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  iVar2 = *(int *)(*(int *)(iVar1 + 4) + 0x10);
  uVar3 = **(undefined4 **)(param_1 + 0x3f0);
  uVar4 = **(undefined4 **)(param_1 + 0x3ec);
  iVar11 = (*(undefined4 **)(param_1 + 0x3ec))[2];
  local_74 = 0;
  iVar8 = 0;
  do {
    ((int (*)())FUN_0008c003)((int)local_34 + iVar8,(int)local_3c + iVar8);
    local_74 = local_74 + 1;
    iVar8 = iVar8 + 4;
  } while (local_74 <= *(byte *)(iVar2 + 0x2d4c));
  if (((*(byte *)(iVar2 + 0x2d4c) == 0) || (local_34[0] != local_34[1])) ||
     (local_3c[0] != local_3c[1])) {
    bVar7 = false;
  }
  else {
    bVar7 = true;
  }
  local_68 = param_1;
  local_50 = 0;
  local_6c = 0;
  iVar8 = param_1;
  do {
    iVar9 = ((int (*)())FUN_0008bb1c)(param_1,0,param_1 + 0x5ac + local_6c);
    if (iVar9 != 0) {
      return 7;
    }
    uVar5 = *(undefined4 *)(iVar8 + 0x5b0);
    local_44[local_50] = uVar5;
    iVar9 = local_34[local_50];
    if (iVar11 == iVar9) {
      iVar9 = ((int (*)())FUN_0008bb1c)(param_1,1,param_1 + 0x64c + local_6c);
      if (iVar9 != 0) {
        return 7;
      }
      *(undefined4 *)(iVar8 + 0x64c) = uVar4;
      (**(code **)(iVar1 + 0x12e8))
                (param_1,uVar3,*(undefined4 *)(iVar8 + 0x650),&DAT_001eea10,iVar11,
                 local_3c[local_50],&DAT_001ee9a0,&DAT_00210684);
      ((int (*)())FUN_0008c003)(&local_28,local_20);
      if (iVar11 == local_28) {
        local_20[0] = *(undefined4 *)(local_68 + 0x2f8);
        (**(code **)(iVar1 + 0x12e8))
                  (param_1,uVar3,uVar5,&DAT_001eea10,iVar11,local_20[0],&DAT_001ee9a0,&DAT_00210684)
        ;
      }
      else {
        (**(code **)(iVar1 + 0x12f4))
                  (param_1,uVar3,uVar5,&DAT_001eea10,uVar4,*(undefined4 *)(iVar8 + 0x650),
                   &DAT_001ee9a0,&DAT_00210684,iVar11,*(undefined4 *)(param_1 + 0x328),&DAT_001ee9a0
                   ,&DAT_00210684,local_28,local_20[0],&DAT_001ee9a0,&DAT_00210684);
      }
      if (*(int *)(param_1 + 0x32c) != -1) {
        (**(code **)(iVar1 + 0x12f4))
                  (param_1,uVar3,uVar5,&DAT_001eea10,uVar4,*(undefined4 *)(iVar8 + 0x650),
                   &DAT_001ee9a0,&DAT_00210684,iVar11,*(int *)(param_1 + 0x32c),&DAT_001ee9a0,
                   &DAT_00210684,uVar4,uVar5,&DAT_001ee9a0,&DAT_00210684);
      }
    }
    else {
      *(int *)(iVar8 + 0x64c) = iVar9;
      iVar6 = local_3c[local_50];
      *(int *)(iVar8 + 0x650) = iVar6;
      if (((bVar7) && (local_50 != 0)) ||
         ((**(code **)(iVar1 + 0x12ec))
                    (param_1,uVar3,uVar5,&DAT_001eea10,iVar9,iVar6,&DAT_001ee9a0,&DAT_00210684,
                     iVar11,*(undefined4 *)(param_1 + 0x328),&DAT_001ee9a0,&DAT_00210684), bVar7)) {
        if (local_50 == 1) {
          ((int (*)())FUN_0008c003)(&local_28,local_20);
          uVar10 = local_44[0];
          (**(code **)(iVar1 + 0x12f0))
                    (param_1,uVar3,local_44[1],&DAT_001eea10,uVar4,local_44[0],&DAT_001ee9a0,
                     &DAT_00210684,local_28,local_20[0],&DAT_001ee9a0,&DAT_00210684);
          ((int (*)())FUN_0008c003)(&local_28,local_20);
          goto LAB_00093cac;
        }
      }
      else {
        ((int (*)())FUN_0008c003)(&local_28,local_20);
        uVar10 = uVar5;
LAB_00093cac:
        (**(code **)(iVar1 + 0x12f0))
                  (param_1,uVar3,uVar10,&DAT_001eea10,uVar4,uVar10,&DAT_001ee9a0,&DAT_00210684,
                   local_28,local_20[0],&DAT_001ee9a0,&DAT_00210684);
      }
      if ((*(int *)(param_1 + 0x32c) != -1) && ((!bVar7 || (local_50 == 0)))) {
        (**(code **)(iVar1 + 0x12f4))
                  (param_1,uVar3,uVar5,&DAT_001eea10,local_34[local_50],local_3c[local_50],
                   &DAT_001ee9a0,&DAT_00210684,iVar11,*(int *)(param_1 + 0x32c),&DAT_001ee9a0,
                   &DAT_00210684,uVar4,uVar5,&DAT_001ee9a0,&DAT_00210684);
      }
    }
    if (*(char *)(iVar1 + 0x12d) != '\0') {
      if (*(short *)(iVar2 + 0x2d48) == -0x7e06) {
        iVar9 = ((int (*)())FUN_0008bb1c)(param_1,1,param_1 + 0x5fc + local_6c);
        if (iVar9 != 0) {
          return 7;
        }
      }
      else {
        *(undefined4 *)(iVar8 + 0x5fc) = *(undefined4 *)(iVar8 + 0x5ac);
        *(undefined4 *)(iVar8 + 0x600) = *(undefined4 *)(iVar8 + 0x5b0);
        *(undefined4 *)(iVar8 + 0x604) = *(undefined4 *)(iVar8 + 0x5b4);
        *(undefined4 *)(iVar8 + 0x608) = *(undefined4 *)(iVar8 + 0x5b8);
        *(undefined4 *)(iVar8 + 0x60c) = *(undefined4 *)(iVar8 + 0x5bc);
        *(undefined4 *)(iVar8 + 0x610) = *(undefined4 *)(iVar8 + 0x5c0);
        *(undefined4 *)(iVar8 + 0x614) = *(undefined4 *)(iVar8 + 0x5c4);
        *(undefined4 *)(iVar8 + 0x618) = *(undefined4 *)(iVar8 + 0x5c8);
        *(undefined4 *)(iVar8 + 0x61c) = *(undefined4 *)(iVar8 + 0x5cc);
        *(undefined4 *)(iVar8 + 0x620) = *(undefined4 *)(iVar8 + 0x5d0);
      }
    }
    local_50 = local_50 + 1;
    local_6c = local_6c + 0x28;
    iVar8 = iVar8 + 0x28;
    local_68 = local_68 + 0x24;
    if (*(byte *)(iVar2 + 0x2d4c) < local_50) {
      return 0;
    }
  } while( true );
}

/* FUN_00093e6f @ 0x93e6f (6208 bytes) */
int FUN_00093e6f(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int iVar17;
  undefined4 *puVar18;
  undefined4 *local_1f8;
  undefined1 *local_1bc;
  undefined *local_1b8;
  undefined1 *local_1ac;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_168;
  int local_164;
  undefined *local_160;
  undefined1 *local_15c;
  int local_158;
  int local_150;
  uint local_140;
  undefined1 local_13c [4];
  undefined4 local_138;
  undefined1 local_134 [16];
  undefined1 local_124 [56];
  undefined1 local_ec [4];
  undefined4 local_e8;
  undefined1 local_e4 [16];
  undefined1 local_d4 [16];
  undefined1 local_c4 [4];
  undefined4 local_c0;
  undefined1 local_9c [4];
  undefined4 local_98;
  undefined1 local_94 [16];
  undefined1 local_84 [16];
  undefined1 local_74 [4];
  undefined4 local_70;
  undefined1 local_6c [16];
  undefined1 local_5c [16];
  undefined1 local_4c [16];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_2c [8];
  int local_24;
  int local_20 [4];
  
  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x3d4) + 4) + 0x10);
  iVar1 = param_1 + 0xf8 + param_2 * 0x3c;
  if (*(int *)(iVar1 + 0x24) == -1) {
    return 2;
  }
  if ((param_5 == 2) && (*(int *)(iVar1 + 4) == -1)) {
    return 2;
  }
  if (param_6 == 2) {
    iVar7 = 0;
    iVar6 = iVar1;
    do {
      if ((*(int *)(iVar6 + 0xc) == -1) && (*(int *)(iVar1 + 8) == -1)) {
        return 2;
      }
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 4;
    } while (iVar7 != *(byte *)(iVar2 + 0x2d4c) + 1);
  }
  if (param_7 != 0) {
    uVar12 = 0;
    do {
      iVar6 = ((int (*)())FUN_0008c0a9)(local_2c,local_4c);
      if (iVar6 != 0) {
        return iVar6;
      }
      uVar12 = uVar12 + 1;
    } while (uVar12 <= *(byte *)(iVar2 + 0x2d4c));
    if ((*(char *)(iVar2 + 0x2d4d) == '\0') && (*(int *)(iVar1 + 0x28) == -1)) {
      return 2;
    }
  }
  if (param_7 == 2) {
    iVar7 = 0;
    iVar6 = iVar1;
    do {
      if ((*(int *)(iVar6 + 0x18) == -1) && (*(int *)(iVar1 + 0x14) == -1)) {
        return 2;
      }
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 4;
    } while (iVar7 != *(byte *)(iVar2 + 0x2d4c) + 1);
  }
  iVar2 = *(int *)(param_1 + 0x3d4);
  iVar6 = *(int *)(*(int *)(iVar2 + 4) + 0x10);
  if (*(char *)(iVar2 + 0x128) == '\0') {
    if (*(char *)(iVar2 + 300) == '\0') {
      if (*(char *)(iVar2 + 0x12a) == '\0') {
        local_168 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
        local_164 = *(int *)(param_1 + 4);
      }
      else {
        local_168 = **(undefined4 **)(param_1 + 0x3ec);
        local_164 = *(int *)(param_1 + 0x448);
        if (local_164 != -1) goto LAB_00093fe5;
        ((int (*)())FUN_0008c776)();
        local_164 = *(int *)(param_1 + 0x448);
      }
    }
    else {
      local_168 = **(undefined4 **)(param_1 + 0x3ec);
      local_164 = *(int *)(param_1 + 0x470);
      if (local_164 != -1) goto LAB_00093fe5;
      ((int (*)())FUN_0008cb9b)();
      local_164 = *(int *)(param_1 + 0x470);
    }
  }
  else {
    local_168 = **(undefined4 **)(param_1 + 0x3ec);
    local_164 = *(int *)(param_1 + 0x498);
    if (local_164 != -1) goto LAB_00093fe5;
    ((int (*)())FUN_0008c920)();
    local_164 = *(int *)(param_1 + 0x498);
  }
  if (local_164 == -1) {
    return 2;
  }
LAB_00093fe5:
  iVar7 = ((int (*)())FUN_0008bb1c)(param_1,2,local_9c);
  if (iVar7 == 0) {
    uVar3 = **(undefined4 **)(param_1 + 0x3f0);
    iVar7 = **(int **)(param_1 + 0x3ec);
    iVar4 = (*(int **)(param_1 + 0x3ec))[2];
    (**(code **)(iVar2 + 0x12e4))
              (param_1,uVar3,local_98,local_94,iVar4,*(undefined4 *)(iVar1 + 0x24),&DAT_001eea00,
               &DAT_00210684,local_168,local_164,&DAT_001eea00,&DAT_00210684);
    if ((param_5 != 0) && (param_5 != 3)) {
      uVar12 = 0;
      iVar9 = param_1;
      do {
        uVar15 = *(undefined4 *)(iVar9 + 0x5b0);
        if (param_5 == 1) {
          (**(code **)(iVar2 + 0x12f0))
                    (param_1,uVar3,uVar15,&DAT_001eea10,iVar7,uVar15,&DAT_001ee9a0,&DAT_00210684,
                     *(undefined4 *)(iVar9 + 0x64c),*(undefined4 *)(iVar9 + 0x650),&DAT_001ee9a0,
                     &DAT_00210684);
        }
        else {
          (**(code **)(iVar2 + 0x12f4))
                    (param_1,uVar3,uVar15,&DAT_001eea10,*(undefined4 *)(iVar9 + 0x64c),
                     *(undefined4 *)(iVar9 + 0x650),&DAT_001ee9a0,&DAT_00210684,iVar4,
                     *(undefined4 *)(iVar1 + 4),&DAT_001ee9a0,&DAT_00210684,iVar7,uVar15,
                     &DAT_001ee9a0,&DAT_00210684);
        }
        uVar12 = uVar12 + 1;
        iVar9 = iVar9 + 0x28;
      } while (uVar12 <= *(byte *)(iVar6 + 0x2d4c));
    }
    local_1b8 = &DAT_00210684;
    uVar12 = 0;
    puVar11 = local_13c;
    puVar10 = puVar11;
    do {
      iVar9 = ((int (*)())FUN_0008bb1c)(param_1,1,puVar10);
      if (iVar9 != 0) {
        return 7;
      }
      uVar12 = uVar12 + 1;
      puVar10 = puVar10 + 0x28;
    } while (uVar12 <= *(byte *)(iVar6 + 0x2d4c));
    if (param_7 == 0) {
      do {
        uVar12 = 0;
        puVar8 = local_1b8;
        puVar10 = puVar11;
        do {
          local_1bc = local_84;
          (**(code **)(iVar2 + 0x132c))
                    (param_1,uVar3,*(undefined4 *)(puVar10 + 4),local_134 + uVar12 * 0x28,iVar7,
                     local_98,&DAT_001ee9c0,&DAT_00210684,iVar7,local_98,local_1bc,puVar8,iVar7,
                     local_98,&DAT_001eea40,&DAT_00210684);
          uVar12 = uVar12 + 1;
          if (*(byte *)(iVar6 + 0x2d4c) < uVar12) goto LAB_000946ad;
          puVar10 = puVar10 + 0x28;
          puVar8 = &DAT_001eea20;
        } while (uVar12 != 0);
      } while( true );
    }
    iVar9 = ((int (*)())FUN_0008bb1c)(param_1,2,local_ec);
    if (iVar9 == 0) {
      iVar9 = ((int (*)())FUN_0008bb1c)(param_1,2,local_74);
      if (iVar9 == 0) {
        if (*(char *)(iVar6 + 0x2d4d) == '\0') {
          (**(code **)(iVar2 + 0x12e4))
                    (param_1,uVar3,local_e8,local_e4,iVar4,*(undefined4 *)(iVar1 + 0x28),
                     &DAT_001eea00,&DAT_00210684,local_168,local_164,&DAT_001eea00,&DAT_00210684);
        }
        else {
          iVar9 = *(int *)(param_1 + 0x420);
          if (iVar9 == -1) {
            ((int (*)())FUN_0008d09f)();
            iVar9 = *(int *)(param_1 + 0x420);
            if (iVar9 == -1) {
              return 2;
            }
          }
          (**(code **)(iVar2 + 0x12f0))
                    (param_1,uVar3,local_138,local_134,iVar4,*(undefined4 *)(iVar1 + 0x24),
                     &DAT_001ee9a0,&DAT_00210684,iVar7,iVar9,&DAT_001ee9a0,&DAT_001eea20);
          (**(code **)(iVar2 + 0x12e4))
                    (param_1,uVar3,local_e8,local_e4,iVar7,local_138,local_124,&DAT_00210684,iVar7,
                     local_138,local_124,&DAT_00210684);
          (**(code **)(iVar2 + 0x12e4))
                    (param_1,uVar3,local_70,local_6c,iVar7,local_138,local_124,&DAT_00210684,
                     local_168,local_164,&DAT_001eea00,&DAT_00210684);
          (**(code **)(iVar2 + 0x1318))
                    (param_1,uVar3,local_e8,local_e4,iVar7,local_e8,local_d4,&DAT_00210684);
          (**(code **)(iVar2 + 0x12ec))
                    (param_1,uVar3,local_e8,local_e4,iVar7,local_70,local_5c,&DAT_00210684,iVar7,
                     local_e8,local_d4,&DAT_00210684);
        }
        local_1ac = local_d4;
        do {
          local_160 = &DAT_00210684;
          uVar12 = 0;
          puVar10 = puVar11;
          do {
            ((int (*)())FUN_0008c0a9)(&local_24,&local_3c);
            (**(code **)(iVar2 + 0x132c))
                      (param_1,uVar3,*(undefined4 *)(puVar10 + 4),local_134 + uVar12 * 0x28,iVar7,
                       local_e8,local_1ac,local_160,iVar7,local_98,local_84,local_160,local_20[0],
                       local_24,&local_3c,&DAT_00210684);
            uVar12 = uVar12 + 1;
            if (*(byte *)(iVar6 + 0x2d4c) < uVar12) {
              ((int (*)())FUN_0008bf53)(param_1,local_ec);
              ((int (*)())FUN_0008bf53)(param_1,local_74);
LAB_000946ad:
              local_158 = param_1;
              local_140 = 0;
              local_1f8 = (undefined4 *)(param_1 + 0x74);
              local_15c = puVar11;
              local_150 = iVar1;
              do {
                if (param_7 == 0) {
                  if (((param_3 != '\0') && (*(char *)(iVar2 + 0x12d) != '\0')) &&
                     (*(short *)(iVar6 + 0x2d48) == -0x7e06)) {
                    iVar13 = *(int *)(local_158 + 0x600);
                    iVar14 = iVar7;
                    iVar9 = iVar13;
                    iVar17 = iVar13;
                    puVar18 = &DAT_001ee9c0;
LAB_00094b97:
                    (**(code **)(iVar2 + 0x12ec))
                              (param_1,uVar3,iVar13,&DAT_001eea10,iVar14,iVar9,&DAT_001ee9a0,
                               &DAT_00210684,iVar7,iVar17,puVar18,&DAT_00210684);
                  }
                }
                else {
                  iVar13 = *(int *)(local_158 + 0x600);
                  if (*(int *)(local_150 + 0x18) == -1) {
                    ((int (*)())FUN_0008c003)(local_20,&local_24);
                  }
                  if (param_7 == 1) {
                    if ((param_3 != '\0') && (*(short *)(iVar6 + 0x2d48) == -0x7e06)) {
                      puVar18 = &DAT_001ee980;
                      iVar17 = *(int *)(local_15c + 4);
                      iVar14 = local_20[0];
                      iVar9 = local_24;
                      goto LAB_00094b97;
                    }
                    (**(code **)(iVar2 + 0x12f4))
                              (param_1,uVar3,iVar13,&DAT_001eea10,local_20[0],local_24,&DAT_001ee9a0
                               ,&DAT_00210684,iVar7,*(undefined4 *)(local_15c + 4),&DAT_001ee980,
                               &DAT_00210684,iVar7,iVar13,&DAT_001ee9a0,&DAT_00210684);
                  }
                  else {
                    iVar9 = *(int *)(local_150 + 0x18);
                    if (iVar9 == -1) {
                      iVar9 = ((int (*)())FUN_0008bb1c)(param_1,1,local_c4);
                      if (iVar9 != 0) {
                        return 7;
                      }
                      if (iVar4 == local_20[0]) {
                        puVar18 = &DAT_001ee9a0;
                        (**(code **)(iVar2 + 0x12ec))
                                  (param_1,uVar3,local_c0,&DAT_001eea10,iVar4,local_24,&DAT_001ee9a0
                                   ,&DAT_00210684,iVar7,*(undefined4 *)(local_15c + 4),&DAT_001ee980
                                   ,&DAT_00210684);
                        if ((param_3 == '\0') || (*(short *)(iVar6 + 0x2d48) != -0x7e06)) {
                          uVar15 = *(undefined4 *)(iVar1 + 0x14);
                          iVar9 = iVar4;
                          goto LAB_0009488e;
                        }
                        (**(code **)(iVar2 + 0x12ec))
                                  (param_1,uVar3,iVar13,&DAT_001eea10,iVar4,
                                   *(undefined4 *)(iVar1 + 0x14),&DAT_001ee9a0,&DAT_00210684,iVar7,
                                   local_c0,&DAT_001ee9a0,&DAT_00210684);
                      }
                      else {
                        (**(code **)(iVar2 + 0x12ec))
                                  (param_1,uVar3,local_c0,&DAT_001eea10,iVar4,
                                   *(undefined4 *)(iVar1 + 0x14),&DAT_001ee9a0,&DAT_00210684,
                                   local_20[0],local_24,&DAT_001ee9a0,&DAT_00210684);
                        if ((param_3 == '\0') || (*(short *)(iVar6 + 0x2d48) != -0x7e06)) {
                          uVar15 = *(undefined4 *)(local_15c + 4);
                          iVar9 = iVar7;
                          puVar18 = &DAT_001ee980;
LAB_0009488e:
                          (**(code **)(iVar2 + 0x12f4))
                                    (param_1,uVar3,iVar13,&DAT_001eea10,iVar9,uVar15,puVar18,
                                     &DAT_00210684,iVar7,local_c0,&DAT_001ee9a0,&DAT_00210684,iVar7,
                                     iVar13,&DAT_001ee9a0,&DAT_00210684);
                        }
                        else {
                          (**(code **)(iVar2 + 0x12ec))
                                    (param_1,uVar3,iVar13,&DAT_001eea10,iVar7,
                                     *(undefined4 *)(local_15c + 4),&DAT_001ee980,&DAT_00210684,
                                     iVar7,local_c0,&DAT_001ee9a0,&DAT_00210684);
                        }
                      }
                      ((int (*)())FUN_0008bf53)(param_1,local_c4);
                    }
                    else {
                      if ((param_3 != '\0') && (*(short *)(iVar6 + 0x2d48) == -0x7e06)) {
                        iVar17 = *(int *)(local_15c + 4);
                        iVar14 = iVar4;
                        puVar18 = &DAT_001ee980;
                        goto LAB_00094b97;
                      }
                      (**(code **)(iVar2 + 0x12f4))
                                (param_1,uVar3,iVar13,&DAT_001eea10,iVar4,iVar9,&DAT_001ee9a0,
                                 &DAT_00210684,iVar7,*(undefined4 *)(local_15c + 4),&DAT_001ee980,
                                 &DAT_00210684,iVar7,iVar13,&DAT_001ee9a0,&DAT_00210684);
                    }
                  }
                }
                if (param_6 == 0) {
                  if (param_4 != '\0') {
                    uVar15 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc);
                    uVar16 = *local_1f8;
                    uVar5 = *(undefined4 *)(local_158 + 0x5b0);
                    ((int (*)())FUN_0008c003)(local_20,&local_24);
                    local_3c = 5;
                    local_38 = 5;
                    local_34 = 5;
                    local_30 = 3;
                    (**(code **)(iVar2 + 0x12ec))
                              (param_1,uVar15,uVar16,&DAT_001ee9b0,iVar7,uVar5,&DAT_001eea50,
                               &DAT_00210684,local_20[0],local_24,&local_3c,&DAT_00210684);
                  }
                }
                else {
                  uVar15 = *(undefined4 *)(local_158 + 0x5b0);
                  if (param_4 == '\0') {
                    local_17c = **(undefined4 **)(param_1 + 0x3f0);
                    puVar18 = &DAT_001eea10;
                    local_178 = uVar15;
                  }
                  else {
                    local_17c = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc);
                    puVar18 = &DAT_001ee9b0;
                    local_178 = *local_1f8;
                  }
                  if (*(int *)(local_150 + 0xc) == -1) {
                    ((int (*)())FUN_0008c003)(local_20,&local_24);
                  }
                  if (param_6 == 1) {
                    (**(code **)(iVar2 + 0x12f4))
                              (param_1,local_17c,local_178,puVar18,local_20[0],local_24,
                               &DAT_001ee9a0,&DAT_00210684,iVar7,*(undefined4 *)(local_15c + 4),
                               &DAT_001eea78,&DAT_00210684,iVar7,uVar15,&DAT_001eea00,&DAT_00210684)
                    ;
                  }
                  else if (*(int *)(local_150 + 0xc) == -1) {
                    iVar9 = ((int (*)())FUN_0008bb1c)(param_1,0,local_c4);
                    if (iVar9 != 0) {
                      return 7;
                    }
                    if (iVar4 == local_20[0]) {
                      (**(code **)(iVar2 + 0x12ec))
                                (param_1,uVar3,local_c0,puVar18,iVar4,local_24,&DAT_001ee9a0,
                                 &DAT_00210684,iVar7,*(undefined4 *)(local_15c + 4),&DAT_001eea78,
                                 &DAT_00210684);
                      puVar8 = &DAT_001eea50;
                      uVar16 = *(undefined4 *)(iVar1 + 8);
                      iVar9 = iVar4;
                    }
                    else {
                      (**(code **)(iVar2 + 0x12ec))
                                (param_1,uVar3,local_c0,puVar18,iVar4,*(undefined4 *)(iVar1 + 8),
                                 &DAT_001eea50,&DAT_00210684,local_20[0],local_24,&DAT_001ee9a0,
                                 &DAT_00210684);
                      uVar15 = *(undefined4 *)(local_158 + 0x5b0);
                      uVar16 = *(undefined4 *)(local_15c + 4);
                      iVar9 = iVar7;
                      puVar8 = &DAT_001eea78;
                    }
                    (**(code **)(iVar2 + 0x12f4))
                              (param_1,local_17c,local_178,puVar18,iVar9,uVar16,puVar8,&DAT_00210684
                               ,iVar7,local_c0,&DAT_001ee9a0,&DAT_00210684,iVar7,uVar15,
                               &DAT_001eea00,&DAT_00210684);
                    ((int (*)())FUN_0008bf53)(param_1,local_c4);
                  }
                  else {
                    (**(code **)(iVar2 + 0x12f4))
                              (param_1,local_17c,local_178,puVar18,iVar4,*(int *)(local_150 + 0xc),
                               &DAT_001ee9a0,&DAT_00210684,iVar7,*(undefined4 *)(local_15c + 4),
                               &DAT_001eea78,&DAT_00210684,iVar7,uVar15,&DAT_001eea00,&DAT_00210684)
                    ;
                  }
                }
                local_140 = local_140 + 1;
                local_1f8 = local_1f8 + 1;
                local_15c = local_15c + 0x28;
                local_158 = local_158 + 0x28;
                local_150 = local_150 + 4;
                if (*(byte *)(iVar6 + 0x2d4c) < local_140) {
                  ((int (*)())FUN_0008bf53)(param_1,local_9c);
                  uVar12 = 0;
                  do {
                    ((int (*)())FUN_0008bf53)(param_1,puVar11);
                    uVar12 = uVar12 + 1;
                    puVar11 = puVar11 + 0x28;
                  } while (uVar12 <= *(byte *)(iVar6 + 0x2d4c));
                  return 0;
                }
              } while( true );
            }
            puVar10 = puVar10 + 0x28;
            local_160 = &DAT_001eea20;
          } while (uVar12 != 0);
        } while( true );
      }
    }
  }
  return 7;
}

/* FUN_000956af @ 0x956af (9475 bytes) */
int FUN_000956af(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
  int param_9;
  int param_10;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  undefined *puVar19;
  int iVar20;
  undefined4 *puVar21;
  undefined1 *local_280;
  undefined4 *local_27c;
  undefined *local_25c;
  undefined1 *local_24c;
  undefined4 *local_240;
  undefined *local_234;
  undefined1 *local_22c;
  undefined1 *local_1ec;
  undefined4 local_1e4;
  undefined4 local_1e0;
  int local_1d0;
  undefined *local_1c8;
  uint local_1c4;
  undefined1 *local_1c0;
  int local_1bc;
  int local_1b4;
  uint local_1a4;
  undefined1 local_19c [4];
  undefined4 local_198;
  undefined1 local_194 [16];
  undefined1 local_184 [56];
  undefined1 local_14c [4];
  undefined4 local_148;
  undefined1 local_144 [16];
  undefined4 local_134 [4];
  undefined1 local_124 [4];
  undefined4 local_120;
  undefined1 local_11c [16];
  undefined1 local_10c [16];
  undefined1 local_fc [4];
  undefined4 local_f8;
  undefined1 local_f4 [16];
  undefined1 local_e4 [16];
  undefined1 local_d4 [4];
  undefined4 local_d0;
  undefined1 local_cc [16];
  undefined1 local_bc [16];
  undefined1 local_ac [4];
  undefined4 local_a8;
  undefined1 local_a4 [16];
  undefined1 local_94 [16];
  undefined1 local_84 [4];
  int local_80;
  undefined1 local_7c [32];
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 local_3c [16];
  int local_2c;
  undefined1 local_28 [8];
  int local_20 [4];
  
  if (param_1 == 0) {
    return 1;
  }
  iVar1 = param_1 + 0xf8 + param_2 * 0x3c;
  if (*(int *)(iVar1 + 0x24) == -1) {
    return 2;
  }
  if (param_5 != '\0') {
    if (param_6 == '\0') {
      iVar2 = *(int *)(iVar1 + 0x2c);
    }
    else {
      iVar2 = *(int *)(iVar1 + 0x34);
    }
    if (iVar2 == -1) {
      return 2;
    }
  }
  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x3d4) + 4) + 0x10);
  if (*(char *)(*(int *)(param_1 + 0x3d4) + 0x150c + param_2 * 0x6c) != '\0') {
    if (*(int *)(iVar1 + 0x28) == -1) {
      return 2;
    }
    if (*(int *)(iVar1 + 0x30) == -1) {
      return 2;
    }
    if ((*(float *)(param_2 * 0x80 + 0x251c + iVar2) != 0.0) && (*(int *)(iVar1 + 0x38) == -1)) {
      return 2;
    }
  }
  if ((param_8 == 2) && (*(int *)(iVar1 + 4) == -1)) {
    return 2;
  }
  if (param_9 == 2) {
    iVar10 = 0;
    iVar9 = iVar1;
    do {
      if ((*(int *)(iVar9 + 0xc) == -1) && (*(int *)(iVar1 + 8) == -1)) {
        return 2;
      }
      iVar10 = iVar10 + 1;
      iVar9 = iVar9 + 4;
    } while (iVar10 != *(byte *)(iVar2 + 0x2d4c) + 1);
  }
  if (param_10 != 0) {
    uVar15 = 0;
    do {
      iVar9 = ((int (*)())FUN_0008c0a9)(local_28,local_3c);
      if (iVar9 != 0) {
        return iVar9;
      }
      uVar15 = uVar15 + 1;
    } while (uVar15 <= *(byte *)(iVar2 + 0x2d4c));
  }
  if (param_10 == 2) {
    iVar10 = 0;
    iVar9 = iVar1;
    do {
      if ((*(int *)(iVar9 + 0x18) == -1) && (*(int *)(iVar1 + 0x14) == -1)) {
        return 2;
      }
      iVar10 = iVar10 + 1;
      iVar9 = iVar9 + 4;
    } while (*(byte *)(iVar2 + 0x2d4c) + 1 != iVar10);
  }
  iVar2 = *(int *)(param_1 + 0x3d4);
  iVar9 = *(int *)(*(int *)(iVar2 + 4) + 0x10);
  iVar10 = ((int (*)())FUN_0008bb1c)(param_1,1,local_84);
  if (iVar10 != 0) {
    return 7;
  }
  iVar10 = ((int (*)())FUN_0008bb1c)(param_1,1,local_d4);
  if (iVar10 != 0) {
    return 7;
  }
  iVar10 = ((int (*)())FUN_0008bb1c)(param_1,2,local_124);
  if (iVar10 != 0) {
    return 7;
  }
  local_1ec = local_14c;
  iVar10 = ((int (*)())FUN_0008bb1c)(param_1,2,local_1ec);
  if (iVar10 != 0) {
    return 7;
  }
  iVar10 = *(int *)(param_1 + 0x3f8);
  if (iVar10 == -1) {
    if ((*(byte *)((int)&switchdataD_000013c0 + iVar2) & 4) == 0) {
      ((int (*)())FUN_0008c3ce)();
    }
    else {
      ((int (*)())FUN_0008c178)();
    }
    iVar10 = *(int *)(param_1 + 0x3f8);
    if (iVar10 == -1) {
      return 2;
    }
  }
  if (*(char *)(iVar2 + 0x128) == '\0') {
    if (*(char *)(iVar2 + 300) == '\0') {
      local_1d0 = *(int *)(param_1 + 0x448);
      if (local_1d0 != -1) goto LAB_000959b3;
      ((int (*)())FUN_0008c776)();
      local_1d0 = *(int *)(param_1 + 0x448);
    }
    else {
      local_1d0 = *(int *)(param_1 + 0x470);
      if (local_1d0 != -1) goto LAB_000959b3;
      ((int (*)())FUN_0008cb9b)();
      local_1d0 = *(int *)(param_1 + 0x470);
    }
  }
  else {
    local_1d0 = *(int *)(param_1 + 0x498);
    if (local_1d0 != -1) goto LAB_000959b3;
    ((int (*)())FUN_0008c920)();
    local_1d0 = *(int *)(param_1 + 0x498);
  }
  if (local_1d0 == -1) {
    return 2;
  }
LAB_000959b3:
  uVar3 = **(undefined4 **)(param_1 + 0x3f0);
  iVar4 = **(int **)(param_1 + 0x3ec);
  iVar5 = (*(int **)(param_1 + 0x3ec))[2];
  if (param_7 == '\0') {
    puVar12 = &DAT_00210684;
    (**(code **)(iVar2 + 0x12ec))
              (param_1,uVar3,local_80,local_7c,iVar4,iVar10,&DAT_001ee960,&DAT_00210684,iVar5,
               *(undefined4 *)(iVar1 + 0x24),&DAT_001ee9a0,&DAT_00210684);
    puVar19 = &DAT_001eea20;
    iVar11 = *(int *)(iVar1 + 0x24);
    iVar16 = iVar5;
    iVar17 = iVar4;
    iVar20 = iVar10;
    iVar10 = local_80;
  }
  else {
    puVar12 = &DAT_001eea20;
    puVar19 = &DAT_00210684;
    iVar16 = iVar4;
    iVar11 = iVar10;
    iVar17 = iVar5;
    iVar20 = *(int *)(iVar1 + 0x24);
  }
  local_234 = &DAT_001eea20;
  local_240 = &DAT_001ee9a0;
  local_25c = &DAT_00210684;
  (**(code **)(iVar2 + 0x12f4))
            (param_1,uVar3,local_80,local_7c,iVar16,iVar11,&DAT_001ee960,puVar19,iVar17,iVar20,
             &DAT_001ee9a0,&DAT_00210684,iVar4,iVar10,&DAT_001ee9a0,puVar12);
  (**(code **)(iVar2 + 0x12e4))
            (param_1,uVar3,local_d0,&DAT_001ee990,iVar4,local_80,&DAT_001eea00,&DAT_00210684,iVar4,
             local_80,&DAT_001eea00,&DAT_00210684);
  (**(code **)(iVar2 + 0x1318))
            (param_1,uVar3,local_148,local_144,iVar4,local_d0,&DAT_00210694,&DAT_00210684);
  puVar21 = local_134;
  (**(code **)(iVar2 + 0x12ec))
            (param_1,uVar3,local_80,local_7c,iVar4,local_148,puVar21,&DAT_00210684,iVar4,local_80,
             &DAT_001ee9a0,&DAT_00210684);
  if ((param_5 != '\0') && (param_6 == '\0')) {
    (**(code **)(iVar2 + 0x12ec))
              (param_1,uVar3,local_d0,&DAT_001ee9f0,iVar4,local_148,puVar21,&DAT_00210684,iVar4,
               local_d0,&DAT_00210694,&DAT_00210684);
    local_5c = 0;
    local_58 = 1;
    local_54 = 5;
    local_50 = 4;
    (**(code **)(iVar2 + 0x12e4))
              (param_1,uVar3,local_148,local_144,iVar5,*(undefined4 *)(iVar1 + 0x2c),&DAT_001eea00,
               &DAT_00210684,iVar4,local_d0,&local_5c,&DAT_00210684);
    (**(code **)(iVar2 + 0x1314))
              (param_1,uVar3,local_148,local_144,iVar4,local_148,puVar21,&DAT_00210684);
  }
  if (*(char *)(iVar2 + 0x150c + param_2 * 0x6c) == '\0') {
    if (param_5 == '\0') {
      bVar8 = false;
    }
    else if (param_6 == '\0') {
      bVar8 = true;
    }
    else {
      (**(code **)(iVar2 + 0x12e8))
                (param_1,uVar3,local_148,local_144,iVar5,*(undefined4 *)(iVar1 + 0x34),&DAT_001ee9a0
                 ,&DAT_00210684);
      bVar8 = true;
    }
  }
  else {
    iVar10 = ((int (*)())FUN_0008bb1c)(param_1,2,local_ac);
    if (iVar10 != 0) {
      return 7;
    }
    (**(code **)(iVar2 + 0x12e4))
              (param_1,uVar3,local_a8,local_a4,iVar5,*(undefined4 *)(iVar1 + 0x28),&DAT_001eea00,
               &DAT_00210684,iVar4,local_80,&DAT_001eea00,&DAT_00210684);
    if (*(float *)(param_2 * 0x80 + 0x251c + iVar9) == 0.0) {
      (**(code **)(iVar2 + 0x130c))
                (param_1,uVar3,local_a8,local_a4,iVar4,local_a8,local_94,&DAT_00210684,iVar5,
                 *(undefined4 *)(iVar1 + 0x30),&DAT_001ee9a0,&DAT_00210684);
    }
    else {
      iVar10 = ((int (*)())FUN_0008bb1c)(param_1,2,local_fc);
      if (iVar10 != 0) {
        return 7;
      }
      (**(code **)(iVar2 + 0x130c))
                (param_1,uVar3,local_f8,local_f4,iVar4,local_a8,local_94,&DAT_00210684,iVar5,
                 *(undefined4 *)(iVar1 + 0x30),&DAT_001ee9a0,&DAT_00210684);
      (**(code **)(iVar2 + 0x12ec))
                (param_1,uVar3,local_a8,local_a4,iVar4,local_a8,local_94,&DAT_00210684,iVar4,
                 local_f8,local_e4,&DAT_00210684);
      (**(code **)(iVar2 + 0x1324))
                (param_1,uVar3,local_a8,local_a4,iVar4,local_a8,local_94,&DAT_00210684,iVar5,
                 *(undefined4 *)(iVar1 + 0x38),&DAT_001ee9a0,&DAT_00210684);
      ((int (*)())FUN_0008bf53)(param_1,local_fc);
    }
    local_24c = local_94;
    if (param_5 != '\0') {
      iVar10 = iVar4;
      if (param_6 != '\0') {
        local_148 = *(undefined4 *)(iVar1 + 0x34);
        iVar10 = iVar5;
        puVar21 = local_240;
      }
      (**(code **)(iVar2 + 0x12ec))
                (param_1,uVar3,local_a8,local_a4,iVar4,local_a8,local_24c,&DAT_00210684,iVar10,
                 local_148,puVar21,&DAT_00210684);
    }
    ((int (*)())FUN_0008bf53)(param_1,local_1ec);
    bVar8 = true;
    local_1ec = local_ac;
  }
  (**(code **)(iVar2 + 0x12e4))
            (param_1,uVar3,local_120,local_11c,iVar4,local_80,&DAT_001eea00,&DAT_00210684,iVar4,
             local_1d0,&DAT_001eea00,&DAT_00210684);
  ((int (*)())FUN_0008bf53)(param_1,local_d4);
  if ((param_8 != 0) && (param_8 != 3)) {
    local_1c4 = 0;
    iVar10 = param_1;
    do {
      uVar18 = *(undefined4 *)(iVar10 + 0x5b0);
      uVar6 = *(undefined4 *)(iVar10 + 0x64c);
      if (param_8 == 1) {
        if (bVar8) {
          (**(code **)(iVar2 + 0x12f4))
                    (param_1,uVar3,uVar18,&DAT_001eea10,uVar6,*(undefined4 *)(iVar10 + 0x650),
                     &DAT_001ee9a0,&DAT_00210684,iVar4,*(undefined4 *)(local_1ec + 4),
                     local_1ec + 0x18,&DAT_00210684,iVar4,uVar18,&DAT_001ee9a0,&DAT_00210684);
        }
        else {
          (**(code **)(iVar2 + 0x12f0))
                    (param_1,uVar3,uVar18,&DAT_001eea10,uVar6,*(undefined4 *)(iVar10 + 0x650),
                     &DAT_001ee9a0,&DAT_00210684,iVar4,uVar18,&DAT_001ee9a0,&DAT_00210684);
        }
      }
      else if (bVar8) {
        iVar11 = ((int (*)())FUN_0008bb1c)(param_1,0,local_d4);
        if (iVar11 != 0) {
          return 7;
        }
        (**(code **)(iVar2 + 0x12ec))
                  (param_1,uVar3,local_d0,&DAT_001ee9b0,uVar6,*(undefined4 *)(iVar10 + 0x650),
                   &DAT_001ee9a0,&DAT_00210684,iVar5,*(undefined4 *)(iVar1 + 4),&DAT_001ee9a0,
                   &DAT_00210684);
        (**(code **)(iVar2 + 0x12f4))
                  (param_1,uVar3,uVar18,&DAT_001eea10,iVar4,local_d0,&DAT_001ee9a0,&DAT_00210684,
                   iVar4,*(undefined4 *)(local_1ec + 4),local_1ec + 0x18,&DAT_00210684,iVar4,uVar18,
                   &DAT_001ee9a0,&DAT_00210684);
        ((int (*)())FUN_0008bf53)(param_1,local_d4);
      }
      else {
        (**(code **)(iVar2 + 0x12f4))
                  (param_1,uVar3,uVar18,&DAT_001eea10,uVar6,*(undefined4 *)(iVar10 + 0x650),
                   &DAT_001ee9a0,&DAT_00210684,iVar5,*(undefined4 *)(iVar1 + 4),&DAT_001ee9a0,
                   &DAT_00210684,iVar4,uVar18,&DAT_001ee9a0,&DAT_00210684);
      }
      local_1c4 = local_1c4 + 1;
      iVar10 = iVar10 + 0x28;
    } while (local_1c4 <= *(byte *)(iVar9 + 0x2d4c));
  }
  uVar15 = 0;
  puVar14 = local_19c;
  puVar13 = puVar14;
  do {
    iVar10 = ((int (*)())FUN_0008bb1c)(param_1,1,puVar13);
    if (iVar10 != 0) {
      return 7;
    }
    uVar15 = uVar15 + 1;
    puVar13 = puVar13 + 0x28;
  } while (uVar15 <= *(byte *)(iVar9 + 0x2d4c));
  if (param_10 == 0) {
    do {
      uVar15 = 0;
      puVar12 = local_25c;
      puVar13 = puVar14;
      do {
        local_22c = local_10c;
        (**(code **)(iVar2 + 0x132c))
                  (param_1,uVar3,*(undefined4 *)(puVar13 + 4),local_194 + uVar15 * 0x28,iVar4,
                   local_120,&DAT_001ee9c0,&DAT_00210684,iVar4,local_120,local_22c,puVar12,iVar4,
                   local_120,&DAT_001eea40,&DAT_00210684);
        uVar15 = uVar15 + 1;
        if (*(byte *)(iVar9 + 0x2d4c) < uVar15) goto LAB_00096a0f;
        puVar13 = puVar13 + 0x28;
        puVar12 = local_234;
      } while (uVar15 != 0);
    } while( true );
  }
  iVar10 = ((int (*)())FUN_0008bb1c)(param_1,2,local_d4);
  if (iVar10 != 0) {
    return 7;
  }
  iVar10 = ((int (*)())FUN_0008bb1c)(param_1,2,local_fc);
  if (iVar10 != 0) {
    return 7;
  }
  if (*(char *)(iVar9 + 0x2d4d) == '\0') {
    local_5c = 4;
    local_58 = 4;
    local_54 = 5;
    local_50 = 4;
    iVar10 = local_80;
    puVar21 = &local_5c;
  }
  else {
    iVar10 = *(int *)(param_1 + 0x420);
    puVar21 = local_240;
    local_25c = local_234;
    if (iVar10 == -1) {
      ((int (*)())FUN_0008d09f)();
      iVar10 = *(int *)(param_1 + 0x420);
      if (iVar10 == -1) {
        return 2;
      }
    }
  }
  (**(code **)(iVar2 + 0x12f0))
            (param_1,uVar3,local_198,local_194,iVar4,local_80,&DAT_001ee9a0,&DAT_00210684,iVar4,
             iVar10,puVar21,local_25c);
  (**(code **)(iVar2 + 0x12e4))
            (param_1,uVar3,local_d0,local_cc,iVar4,local_198,local_184,&DAT_00210684,iVar4,local_198
             ,local_184,&DAT_00210684);
  (**(code **)(iVar2 + 0x12e4))
            (param_1,uVar3,local_f8,local_f4,iVar4,local_198,local_184,&DAT_00210684,iVar4,local_1d0
             ,&DAT_001eea00,&DAT_00210684);
  (**(code **)(iVar2 + 0x1318))
            (param_1,uVar3,local_d0,local_cc,iVar4,local_d0,local_bc,&DAT_00210684);
  (**(code **)(iVar2 + 0x12ec))
            (param_1,uVar3,local_d0,local_cc,iVar4,local_f8,local_e4,&DAT_00210684,iVar4,local_d0,
             local_bc,&DAT_00210684);
  do {
    local_1c8 = &DAT_00210684;
    uVar15 = 0;
    puVar13 = puVar14;
    do {
      ((int (*)())FUN_0008c0a9)(&local_2c,&local_4c);
      (**(code **)(iVar2 + 0x132c))
                (param_1,uVar3,*(undefined4 *)(puVar13 + 4),local_194 + uVar15 * 0x28,iVar4,local_d0
                 ,local_bc,local_1c8,iVar4,local_120,local_10c,local_1c8,local_20[0],local_2c,
                 &local_4c,&DAT_00210684);
      uVar15 = uVar15 + 1;
      if (*(byte *)(iVar9 + 0x2d4c) < uVar15) {
        ((int (*)())FUN_0008bf53)(param_1,local_d4);
        ((int (*)())FUN_0008bf53)(param_1,local_fc);
LAB_00096a0f:
        local_1bc = param_1;
        local_1a4 = 0;
        local_27c = (undefined4 *)(param_1 + 0x74);
        local_280 = local_194;
        local_1c0 = puVar14;
        local_1b4 = iVar1;
        do {
          if (bVar8) {
            (**(code **)(iVar2 + 0x12ec))
                      (param_1,uVar3,*(undefined4 *)(local_1c0 + 4),local_280,iVar4,
                       *(undefined4 *)(local_1ec + 4),local_1ec + 0x18,&DAT_00210684,iVar4,
                       *(undefined4 *)(local_1c0 + 4),&DAT_001ee9a0,&DAT_00210684);
          }
          if (param_10 == 0) {
            if (((param_3 != '\0') && (*(char *)(iVar2 + 0x12d) != '\0')) &&
               (*(short *)(iVar9 + 0x2d48) == -0x7e06)) {
              iVar10 = *(int *)(local_1bc + 0x600);
              iVar17 = iVar4;
              iVar11 = iVar10;
              iVar16 = iVar10;
              puVar21 = &DAT_001ee9c0;
LAB_00096edc:
              (**(code **)(iVar2 + 0x12ec))
                        (param_1,uVar3,iVar10,&DAT_001eea10,iVar17,iVar11,&DAT_001ee9a0,
                         &DAT_00210684,iVar4,iVar16,puVar21,&DAT_00210684);
            }
          }
          else {
            iVar10 = *(int *)(local_1bc + 0x600);
            if (*(int *)(local_1b4 + 0x18) == -1) {
              ((int (*)())FUN_0008c003)(local_20,&local_2c);
            }
            if (param_10 == 1) {
              if ((param_3 != '\0') && (*(short *)(iVar9 + 0x2d48) == -0x7e06)) {
                puVar21 = &DAT_001ee980;
                iVar16 = *(int *)(local_1c0 + 4);
                iVar17 = local_20[0];
                iVar11 = local_2c;
                goto LAB_00096edc;
              }
              (**(code **)(iVar2 + 0x12f4))
                        (param_1,uVar3,iVar10,&DAT_001eea10,local_20[0],local_2c,&DAT_001ee9a0,
                         &DAT_00210684,iVar4,*(undefined4 *)(local_1c0 + 4),&DAT_001ee980,
                         &DAT_00210684,iVar4,iVar10,&DAT_001ee9a0,&DAT_00210684);
            }
            else {
              iVar11 = *(int *)(local_1b4 + 0x18);
              if (iVar11 == -1) {
                iVar11 = ((int (*)())FUN_0008bb1c)(param_1,1,local_d4);
                if (iVar11 != 0) {
                  return 7;
                }
                if (iVar5 == local_20[0]) {
                  (**(code **)(iVar2 + 0x12ec))
                            (param_1,uVar3,local_d0,&DAT_001eea10,iVar5,local_2c,&DAT_001ee9a0,
                             &DAT_00210684,iVar4,*(undefined4 *)(local_1c0 + 4),&DAT_001ee980,
                             &DAT_00210684);
                  if ((param_3 == '\0') || (*(short *)(iVar9 + 0x2d48) != -0x7e06)) {
                    uVar18 = *(undefined4 *)(iVar1 + 0x14);
                    iVar11 = iVar5;
                    puVar21 = local_240;
                    goto LAB_00096bea;
                  }
                  (**(code **)(iVar2 + 0x12ec))
                            (param_1,uVar3,iVar10,&DAT_001eea10,iVar5,*(undefined4 *)(iVar1 + 0x14),
                             &DAT_001ee9a0,&DAT_00210684,iVar4,local_d0,&DAT_001ee9a0,&DAT_00210684)
                  ;
                }
                else {
                  (**(code **)(iVar2 + 0x12ec))
                            (param_1,uVar3,local_d0,&DAT_001eea10,iVar5,
                             *(undefined4 *)(iVar1 + 0x14),&DAT_001ee9a0,&DAT_00210684,local_20[0],
                             local_2c,&DAT_001ee9a0,&DAT_00210684);
                  if ((param_3 == '\0') || (*(short *)(iVar9 + 0x2d48) != -0x7e06)) {
                    uVar18 = *(undefined4 *)(local_1c0 + 4);
                    iVar11 = iVar4;
                    puVar21 = &DAT_001ee980;
LAB_00096bea:
                    (**(code **)(iVar2 + 0x12f4))
                              (param_1,uVar3,iVar10,&DAT_001eea10,iVar11,uVar18,puVar21,
                               &DAT_00210684,iVar4,local_d0,&DAT_001ee9a0,&DAT_00210684,iVar4,iVar10
                               ,&DAT_001ee9a0,&DAT_00210684);
                  }
                  else {
                    (**(code **)(iVar2 + 0x12ec))
                              (param_1,uVar3,iVar10,&DAT_001eea10,iVar4,
                               *(undefined4 *)(local_1c0 + 4),&DAT_001ee980,&DAT_00210684,iVar4,
                               local_d0,&DAT_001ee9a0,&DAT_00210684);
                  }
                }
                ((int (*)())FUN_0008bf53)(param_1,local_d4);
              }
              else {
                if ((param_3 != '\0') && (*(short *)(iVar9 + 0x2d48) == -0x7e06)) {
                  iVar16 = *(int *)(local_1c0 + 4);
                  iVar17 = iVar5;
                  puVar21 = &DAT_001ee980;
                  goto LAB_00096edc;
                }
                (**(code **)(iVar2 + 0x12f4))
                          (param_1,uVar3,iVar10,&DAT_001eea10,iVar5,iVar11,&DAT_001ee9a0,
                           &DAT_00210684,iVar4,*(undefined4 *)(local_1c0 + 4),&DAT_001ee980,
                           &DAT_00210684,iVar4,iVar10,&DAT_001ee9a0,&DAT_00210684);
              }
            }
          }
          if (param_9 == 0) {
            if (param_4 != '\0') {
              uVar18 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc);
              uVar6 = *local_27c;
              uVar7 = *(undefined4 *)(local_1bc + 0x5b0);
              ((int (*)())FUN_0008c003)(local_20,&local_2c);
              local_4c = 5;
              local_48 = 5;
              local_44 = 5;
              local_40 = 3;
              (**(code **)(iVar2 + 0x12ec))
                        (param_1,uVar18,uVar6,&DAT_001ee9b0,iVar4,uVar7,&DAT_001eea50,&DAT_00210684,
                         local_20[0],local_2c,&local_4c,&DAT_00210684);
            }
          }
          else {
            uVar18 = *(undefined4 *)(local_1bc + 0x5b0);
            if (param_4 == '\0') {
              local_1e4 = **(undefined4 **)(param_1 + 0x3f0);
              puVar21 = &DAT_001eea10;
              local_1e0 = uVar18;
            }
            else {
              local_1e4 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc);
              puVar21 = &DAT_001ee9b0;
              local_1e0 = *local_27c;
            }
            if (*(int *)(local_1b4 + 0xc) == -1) {
              ((int (*)())FUN_0008c003)(local_20,&local_2c);
            }
            if (param_9 == 1) {
              (**(code **)(iVar2 + 0x12f4))
                        (param_1,local_1e4,local_1e0,puVar21,local_20[0],local_2c,&DAT_001ee9a0,
                         &DAT_00210684,iVar4,*(undefined4 *)(local_1c0 + 4),&DAT_001eea78,
                         &DAT_00210684,iVar4,uVar18,&DAT_001eea00,&DAT_00210684);
            }
            else if (*(int *)(local_1b4 + 0xc) == -1) {
              iVar10 = ((int (*)())FUN_0008bb1c)(param_1,0,local_d4);
              if (iVar10 != 0) {
                return 7;
              }
              if (iVar5 == local_20[0]) {
                (**(code **)(iVar2 + 0x12ec))
                          (param_1,uVar3,local_d0,puVar21,iVar5,local_2c,&DAT_001ee9a0,&DAT_00210684
                           ,iVar4,*(undefined4 *)(local_1c0 + 4),&DAT_001eea78,&DAT_00210684);
                (**(code **)(iVar2 + 0x12f4))
                          (param_1,local_1e4,local_1e0,puVar21,iVar5,*(undefined4 *)(iVar1 + 8),
                           &DAT_001eea50,&DAT_00210684,iVar4,local_d0,&DAT_001ee9a0,&DAT_00210684,
                           iVar4,uVar18,&DAT_001eea00,&DAT_00210684);
              }
              else {
                (**(code **)(iVar2 + 0x12ec))
                          (param_1,uVar3,local_d0,puVar21,iVar5,*(undefined4 *)(iVar1 + 8),
                           &DAT_001eea50,&DAT_00210684,local_20[0],local_2c,&DAT_001ee9a0,
                           &DAT_00210684);
                (**(code **)(iVar2 + 0x12f4))
                          (param_1,local_1e4,local_1e0,puVar21,iVar4,*(undefined4 *)(local_1c0 + 4),
                           &DAT_001eea78,&DAT_00210684,iVar4,local_d0,&DAT_001ee9a0,&DAT_00210684,
                           iVar4,uVar18,&DAT_001eea00,&DAT_00210684);
              }
              ((int (*)())FUN_0008bf53)(param_1,local_d4);
            }
            else {
              (**(code **)(iVar2 + 0x12f4))
                        (param_1,local_1e4,local_1e0,puVar21,iVar5,*(int *)(local_1b4 + 0xc),
                         &DAT_001ee9a0,&DAT_00210684,iVar4,*(undefined4 *)(local_1c0 + 4),
                         &DAT_001eea78,&DAT_00210684,iVar4,uVar18,&DAT_001eea00,&DAT_00210684);
            }
          }
          local_1a4 = local_1a4 + 1;
          local_280 = local_280 + 0x28;
          local_27c = local_27c + 1;
          local_1c0 = local_1c0 + 0x28;
          local_1bc = local_1bc + 0x28;
          local_1b4 = local_1b4 + 4;
          if (*(byte *)(iVar9 + 0x2d4c) < local_1a4) {
            ((int (*)())FUN_0008bf53)(param_1,local_84);
            ((int (*)())FUN_0008bf53)(param_1,local_124);
            ((int (*)())FUN_0008bf53)(param_1,local_1ec);
            uVar15 = 0;
            do {
              ((int (*)())FUN_0008bf53)(param_1,puVar14);
              uVar15 = uVar15 + 1;
              puVar14 = puVar14 + 0x28;
            } while (uVar15 <= *(byte *)(iVar9 + 0x2d4c));
            return 0;
          }
        } while( true );
      }
      puVar13 = puVar13 + 0x28;
      local_1c8 = &DAT_001eea20;
    } while (uVar15 != 0);
  } while( true );
}

/* FUN_00097bb2 @ 0x97bb2 (78 bytes) */
int FUN_00097bb2(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_c8;
  undefined1 auStack_bc [4];
  undefined4 uStack_b8;
  undefined1 auStack_b4 [16];
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined1 auStack_94 [4];
  undefined4 uStack_90;
  undefined1 auStack_8c [16];
  undefined1 auStack_7c [16];
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  if (param_1 == 0) {
    return 1;
  }
  switch(param_2) {
  case 0:
    if (*(int *)(param_1 + 0x4c) == -1) {
      return 2;
    }
code_r0x00097c16:
    if (*(int *)(param_1 + 0x334) != -1) {
code_r0x00097c23:
      if (*(int *)(param_1 + 0x338) != -1) {
code_r0x00097c30:
        if ((*(int *)(param_1 + 0x340) != -1) && (*(int *)(param_1 + 0x6c) != -1)) {
          iVar1 = *(int *)(param_1 + 0x3d4);
          bVar9 = param_2 < 3;
          iVar11 = ((int (*)())FUN_0008bb1c)(param_1,2,auStack_bc);
          if ((iVar11 == 0) &&
             ((!bVar9 || (iVar11 = ((int (*)())FUN_0008bb1c)(param_1,1,auStack_94), iVar11 == 0)))) {
            uVar2 = **(undefined4 **)(param_1 + 0x3f0);
            uVar3 = (*(undefined4 **)(param_1 + 0x3f0))[7];
            puVar4 = *(undefined4 **)(param_1 + 0x3ec);
            uVar5 = *puVar4;
            uStack_e0 = puVar4[1];
            uVar6 = puVar4[2];
            if (param_2 == 0) {
              (**(code **)(iVar1 + 0x12ec))
                        (param_1,uVar2,uStack_90,&DAT_001ee9e0,uStack_e0,
                         *(undefined4 *)(param_1 + 0x4c),&DAT_00210694,&DAT_00210684,uVar6,
                         *(undefined4 *)(param_1 + 0x334),&DAT_001ee980,&DAT_00210684);
            }
            if (bVar9) {
              if ((*(int *)(param_1 + 0x510) == -1) &&
                 (((int (*)())FUN_0008c5d3)(), *(int *)(param_1 + 0x510) == -1)) {
                return 2;
              }
              uVar7 = *(undefined4 *)(param_1 + 0x510);
              uVar8 = *(undefined4 *)(param_1 + 0x338);
              if (param_3 == '\0') {
                if ((*(int *)(param_1 + 0x538) == -1) &&
                   (((int (*)())FUN_0008cfc4)(), *(int *)(param_1 + 0x538) == -1)) {
                  return 2;
                }
                uStack_4c = 1;
                uStack_48 = 1;
                uStack_44 = 0;
                uStack_40 = 0;
                uStack_3c = *(undefined4 *)(param_1 + 0x54c);
                uStack_38 = 5;
                uStack_34 = 4;
                uStack_30 = 4;
                (**(code **)(iVar1 + 0x12ec))
                          (param_1,uVar2,uStack_90,&uStack_4c,uVar5,*(undefined4 *)(param_1 + 0x538)
                           ,&uStack_3c,&DAT_00210684,uVar5,uVar7,param_1 + 0x524,&DAT_00210684);
                uStack_3c = 1;
                uStack_38 = 0;
                uStack_34 = 5;
                uStack_30 = 4;
                (**(code **)(iVar1 + 0x12e4))
                          (param_1,uVar2,uStack_b8,auStack_b4,uVar6,uVar8,&DAT_001eea00,
                           &DAT_00210684,uVar5,uStack_90,&uStack_3c,&DAT_00210684);
              }
              else {
                uStack_3c = *(undefined4 *)(param_1 + 0x524);
                uStack_38 = 4;
                uStack_34 = 5;
                uStack_30 = 4;
                (**(code **)(iVar1 + 0x12e4))
                          (param_1,uVar2,uStack_b8,auStack_b4,uVar6,uVar8,&DAT_001eea00,
                           &DAT_00210684,uVar5,uVar7,&uStack_3c,&DAT_00210684);
              }
              (**(code **)(iVar1 + 0x1318))
                        (param_1,uVar2,uStack_b8,auStack_b4,uVar5,uStack_b8,&uStack_a4,&DAT_00210684
                        );
            }
            uStack_c8 = uVar5;
            switch(param_2) {
            case 0:
              uStack_dc = uStack_90;
              uStack_5c = DAT_001ee980;
              uStack_58 = DAT_001ee984;
              uStack_54 = DAT_001ee988;
              uStack_50 = DAT_001ee98c;
              uStack_d8 = uStack_b8;
              uStack_2c = uStack_a4;
              uStack_28 = uStack_a0;
              uStack_24 = uStack_9c;
              uStack_20 = uStack_98;
              bVar10 = false;
              uStack_e0 = uVar5;
              break;
            case 1:
              uStack_dc = *(undefined4 *)(param_1 + 0x4c);
              uStack_5c = DAT_00210694;
              uStack_58 = DAT_00210698;
              uStack_54 = DAT_0021069c;
              uStack_50 = DAT_002106a0;
              uStack_d8 = uStack_b8;
              uStack_2c = uStack_a4;
              uStack_28 = uStack_a0;
              uStack_24 = uStack_9c;
              uStack_20 = uStack_98;
              bVar10 = false;
              break;
            case 2:
              uStack_dc = uStack_b8;
              uStack_5c = uStack_a4;
              uStack_58 = uStack_a0;
              uStack_54 = uStack_9c;
              uStack_50 = uStack_98;
              uStack_d8 = *(undefined4 *)(param_1 + 0x334);
              uStack_2c = DAT_001ee980;
              uStack_28 = DAT_001ee984;
              uStack_24 = DAT_001ee988;
              uStack_20 = DAT_001ee98c;
              bVar10 = true;
              uStack_e0 = uVar5;
              uStack_c8 = uVar6;
              break;
            case 3:
              uStack_dc = *(undefined4 *)(param_1 + 0x4c);
              uStack_5c = DAT_00210694;
              uStack_58 = DAT_00210698;
              uStack_54 = DAT_0021069c;
              uStack_50 = DAT_002106a0;
              uStack_d8 = *(undefined4 *)(param_1 + 0x334);
              uStack_2c = DAT_001ee980;
              uStack_28 = DAT_001ee984;
              uStack_24 = DAT_001ee988;
              uStack_20 = DAT_001ee98c;
              bVar10 = true;
              uStack_c8 = uVar6;
              break;
            case 4:
              uStack_dc = *(undefined4 *)(param_1 + 0x340);
              uStack_5c = _DAT_001eea40;
              uStack_58 = (*(unsigned int *)0x001eea44);
              uStack_54 = (*(unsigned int *)0x001eea48);
              uStack_50 = (*(unsigned int *)0x001eea4c);
              uStack_d8 = *(undefined4 *)(param_1 + 0x334);
              uStack_2c = DAT_001ee980;
              uStack_28 = DAT_001ee984;
              uStack_24 = DAT_001ee988;
              uStack_20 = DAT_001ee98c;
              bVar10 = true;
              uStack_e0 = uVar6;
              uStack_c8 = uVar6;
              break;
            default:
              uStack_dc = 0;
              uStack_d8 = 0;
              uStack_e0 = 0;
              uStack_c8 = 0;
              bVar10 = false;
            }
            if (bVar9) {
              ((int (*)())FUN_0008bf53)(param_1,auStack_94);
            }
            uStack_6c = 0;
            uStack_68 = 4;
            uStack_64 = 4;
            uStack_60 = 1;
            if (bVar10) {
              iVar11 = ((int (*)())FUN_0008bb1c)(param_1,2,auStack_94);
              if (iVar11 != 0) {
                return 7;
              }
              (**(code **)(iVar1 + 0x12e8))
                        (param_1,uVar2,uStack_90,auStack_8c,uStack_c8,uStack_d8,&uStack_2c,
                         &DAT_00210684);
              (**(code **)(iVar1 + 0x12fc))
                        (param_1,uVar3,*(undefined4 *)(param_1 + 0x6c),&DAT_001ee9b0,uStack_e0,
                         uStack_dc,&uStack_5c,&DAT_00210684,uVar5,uStack_90,auStack_7c,&DAT_00210684
                         ,uVar6,*(undefined4 *)(param_1 + 0x340),&uStack_6c,&DAT_00210684);
              ((int (*)())FUN_0008bf53)(param_1,auStack_94);
            }
            else {
              (**(code **)(iVar1 + 0x12fc))
                        (param_1,uVar3,*(undefined4 *)(param_1 + 0x6c),&DAT_001ee9b0,uStack_e0,
                         uStack_dc,&uStack_5c,&DAT_00210684,uStack_c8,uStack_d8,&uStack_2c,
                         &DAT_00210684,uVar6,*(undefined4 *)(param_1 + 0x340),&uStack_6c,
                         &DAT_00210684);
            }
            ((int (*)())FUN_0008bf53)(param_1,auStack_bc);
            return 0;
          }
          return 7;
        }
      }
    }
    return 2;
  case 1:
    if (*(int *)(param_1 + 0x4c) == -1) {
      return 2;
    }
    goto code_r0x00097c23;
  case 2:
    goto code_r0x00097c16;
  case 3:
    if (*(int *)(param_1 + 0x4c) == -1) {
      return 2;
    }
  case 4:
    if (*(int *)(param_1 + 0x334) == -1) {
      return 2;
    }
    goto code_r0x00097c30;
  default:
    return 4;
  }
}

/* FUN_00098504 @ 0x98504 (896 bytes) */
int FUN_00098504(param_1)
  int param_1;
{
  short sVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined1 local_44 [4];
  undefined4 local_40;
  
  if (param_1 == 0) {
    uVar7 = 1;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x70);
    if (iVar2 == -1) {
      return 2;
    }
    iVar10 = *(int *)(param_1 + 0x3d4);
    uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
    if (*(short *)(*(int *)(*(int *)(iVar10 + 4) + 0x10) + 0x2e06) == -0x7bae) {
      if (*(int *)(param_1 + 0x3f8) == -1) {
        if ((*(byte *)((int)&switchdataD_000013c0 + iVar10) & 4) == 0) {
          ((int (*)())FUN_0008c3ce)();
        }
        else {
          ((int (*)())FUN_0008c178)();
        }
        if (*(int *)(param_1 + 0x3f8) == -1) {
          return 2;
        }
        iVar10 = *(int *)(param_1 + 0x3d4);
      }
      uVar4 = **(undefined4 **)(param_1 + 0x3ec);
      uVar5 = *(undefined4 *)(param_1 + 0x3f8);
      iVar8 = *(int *)(*(int *)(iVar10 + 4) + 0x10);
      if ((*(short *)(iVar8 + 0x2e06) == -0x7bae) &&
         (sVar1 = *(short *)(iVar8 + 0x2e08), sVar1 != -0x7aa4)) {
        if (sVar1 == -0x7aa5) {
          uVar6 = **(undefined4 **)(param_1 + 0x3f0);
          iVar8 = ((int (*)())FUN_0008bb1c)(param_1,1,local_44);
          if (iVar8 == 0) {
            puVar9 = &DAT_001ee990;
            (**(code **)(iVar10 + 0x12e4))
                      (param_1,uVar6,local_40,&DAT_001ee990,uVar4,uVar5,&DAT_001eea00,&DAT_00210684,
                       uVar4,uVar5,&DAT_001eea00,&DAT_00210684,iVar10,&DAT_001ee990);
            (**(code **)(iVar10 + 0x1318))
                      (param_1,uVar6,local_40,&DAT_001ee9f0,uVar4,local_40,&DAT_00210694,
                       &DAT_00210684);
            (**(code **)(iVar10 + 0x12e4))
                      (param_1,uVar7,iVar2,puVar9,uVar4,local_40,&DAT_001eeb80,&DAT_00210684,uVar4,
                       local_40,&DAT_001eeb70,&DAT_00210684);
            ((int (*)())FUN_0008bf53)(param_1,local_44);
            uVar7 = 0;
          }
          else {
            uVar7 = 7;
          }
        }
        else {
          (**(code **)(iVar10 + 0x12e8))
                    (param_1,uVar7,iVar2,&DAT_001ee990,uVar4,uVar5,&DAT_001ee980,&DAT_001eea20);
          uVar7 = 0;
        }
      }
      else {
        (**(code **)(iVar10 + 0x1304))
                  (param_1,uVar7,iVar2,&DAT_001ee990,uVar4,uVar5,&DAT_001ee980,&DAT_00210684,uVar4,
                   uVar5,&DAT_001ee980,&DAT_001eea20);
        uVar7 = 0;
      }
    }
    else {
      if (*(int *)(param_1 + 0x50) == -1) {
        return 2;
      }
      uVar3 = *(uint *)(param_1 + 0x54);
      if (uVar3 < 4) {
        if (uVar3 == 2) {
          puVar9 = &DAT_001ee980;
        }
        else if (uVar3 == 3) {
          puVar9 = &DAT_001ee960;
        }
        else if (uVar3 == 1) {
          puVar9 = &DAT_001ee970;
        }
        else {
          puVar9 = &DAT_00210694;
        }
        (**(code **)(iVar10 + 0x12e8))
                  (param_1,uVar7,iVar2,&DAT_001ee990,*(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),
                   *(int *)(param_1 + 0x50),puVar9,&DAT_00210684);
        return 0;
      }
      uVar7 = 3;
    }
  }
  return uVar7;
}

/* FUN_00098884 @ 0x98884 (78 bytes) */
int FUN_00098884(param_1)
  int param_1;
{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(int *)(param_1 + 0x3d4) + 0x12d8);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(*(int *)(param_1 + 0x3d4),param_1);
  }
  if ((*(int *)(param_1 + 0x3d8) == 0) && (*(uint *)(param_1 + 0x3e4) < *(uint *)(param_1 + 0x3cc)))
  {
    return 6;
  }
  return 0;
}

/* FUN_000988d2 @ 0x988d2 (61 bytes) */
int FUN_000988d2(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x3c8) != 0) {
      (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x3c8));
    }
    (**(code **)(param_1 + 0x18))(param_2);
    return 0;
  }
  return 1;
}

/* FUN_0009890f @ 0x9890f (1556 bytes) */
int FUN_0009890f(param_1)
  int param_1;
{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 *local_a0;
  undefined1 local_8c [4];
  undefined4 local_88;
  undefined1 local_64 [4];
  undefined4 local_60;
  undefined1 local_5c [24];
  undefined4 local_44;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  iVar2 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x588) == -1) {
    local_b4 = **(undefined4 **)(param_1 + 0x3f0);
    puVar10 = *(undefined4 **)(param_1 + 0x3ec);
    uVar11 = puVar10[2];
    uVar3 = *(undefined4 *)(param_1 + 0x330);
    if (*(short *)(*(int *)(*(int *)(iVar2 + 4) + 0x10) + 0x2e06) == -0x7bae) {
      if (*(int *)(param_1 + 0x3f8) == -1) {
        if ((*(byte *)((int)&switchdataD_000013c0 + iVar2) & 4) == 0) {
          ((int (*)())FUN_0008c3ce)();
        }
        else {
          ((int (*)())FUN_0008c178)();
        }
        if (*(int *)(param_1 + 0x3f8) == -1) {
          return 2;
        }
        puVar10 = *(undefined4 **)(param_1 + 0x3ec);
      }
      local_b0 = *puVar10;
      local_ac = *(undefined4 *)(param_1 + 0x3f8);
      puVar10 = &DAT_001ee980;
    }
    else {
      local_b0 = puVar10[1];
      local_ac = *(undefined4 *)(param_1 + 0x50);
      iVar8 = *(int *)(param_1 + 0x54);
      if (iVar8 == 1) {
        puVar10 = &DAT_001ee970;
      }
      else if (iVar8 == 0) {
        puVar10 = &DAT_00210694;
      }
      else if (iVar8 == 2) {
        puVar10 = &DAT_001ee980;
      }
      else if (iVar8 == 3) {
        puVar10 = &DAT_001ee960;
      }
      else {
        puVar10 = &DAT_001ee9a0;
      }
    }
    iVar8 = ((int (*)())FUN_0008bb1c)(param_1,2,param_1 + 0x584);
    if (iVar8 != 0) {
      return 7;
    }
    uVar4 = *(undefined4 *)(param_1 + 0x588);
    iVar8 = ((int (*)())FUN_0008bb1c)(param_1,2,local_64);
    uVar7 = local_60;
    if (iVar8 != 0) {
      return 7;
    }
    iVar8 = *(int *)(param_1 + 0x3d4);
    iVar9 = *(int *)(*(int *)(iVar8 + 4) + 0x10);
    if ((*(short *)(iVar9 + 0x2e06) == -0x7bae) &&
       (sVar1 = *(short *)(iVar9 + 0x2e08), sVar1 != -0x7aa4)) {
      if (sVar1 == -0x7aa5) {
        uVar5 = **(undefined4 **)(param_1 + 0x3f0);
        uVar6 = **(undefined4 **)(param_1 + 0x3ec);
        iVar9 = ((int (*)())FUN_0008bb1c)(param_1,1,local_8c);
        if (iVar9 != 0) {
          return 7;
        }
        (**(code **)(iVar8 + 0x12e4))
                  (param_1,uVar5,local_88,&DAT_001ee990,local_b0,local_ac,&DAT_001eea00,
                   &DAT_00210684,local_b0,local_ac,&DAT_001eea00,&DAT_00210684);
        (**(code **)(iVar8 + 0x1318))
                  (param_1,uVar5,local_88,&DAT_001ee9f0,uVar6,local_88,&DAT_00210694,&DAT_00210684);
        (**(code **)(iVar8 + 0x12e4))
                  (param_1,local_b4,uVar7,local_5c,uVar6,local_88,&DAT_001eeb80,&DAT_00210684,uVar6,
                   local_88,&DAT_001eeb70,&DAT_00210684);
        ((int (*)())FUN_0008bf53)(param_1,local_8c);
      }
      else {
        (**(code **)(iVar8 + 0x12e8))
                  (param_1,local_b4,local_60,local_5c,local_b0,local_ac,puVar10,&DAT_001eea20);
      }
    }
    else {
      (**(code **)(iVar8 + 0x1304))
                (param_1,local_b4,local_60,local_5c,local_b0,local_ac,puVar10,&DAT_00210684,local_b0
                 ,local_ac,puVar10,&DAT_001eea20);
    }
    uVar7 = **(undefined4 **)(param_1 + 0x3ec);
    local_2c = 4;
    local_28 = 1;
    local_24 = 2;
    local_20 = 4;
    local_3c = 4;
    local_38 = 5;
    local_34 = local_44;
    local_30 = 4;
    if (*(int *)(param_1 + 0x3d8) == 0) {
      local_a0 = (undefined4 *)(param_1 + 0x58c);
      (**(code **)(iVar2 + 0x12e4))
                (param_1,local_b4,uVar4,local_a0,uVar11,uVar3,&local_2c,&DAT_00210684,uVar7,local_60
                 ,&local_3c,&DAT_00210684);
      ((int (*)())FUN_0008bf53)(param_1,local_64);
      uVar11 = uVar4;
      if ((*(byte *)(iVar2 + 0x44) & 1) == 0) {
        local_b4 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
        local_a0 = &DAT_001ee9d0;
        uVar11 = *(undefined4 *)(param_1 + 0x70);
      }
      (**(code **)(iVar2 + 0x1328))
                (param_1,local_b4,uVar11,local_a0,uVar7,uVar4,param_1 + 0x59c,&DAT_00210684,uVar7,
                 uVar4,&DAT_001eea40,&DAT_00210684);
    }
    else {
      (**(code **)(iVar2 + 0x12e4))
                (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18),
                 *(undefined4 *)(param_1 + 0x70),&DAT_001ee990,uVar11,uVar3,&local_2c,&DAT_00210684,
                 uVar7,local_60,&local_3c,&DAT_00210684);
      ((int (*)())FUN_0008bf53)(param_1,local_64);
    }
  }
  return 0;
}

/* FUN_00098f23 @ 0x98f23 (124 bytes) */
int FUN_00098f23(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 0x330) == -1) || (iVar1 = *(int *)(param_1 + 0x70), iVar1 == -1)) {
    return 2;
  }
  if (*(short *)(*(int *)(*(int *)(*(int *)(param_1 + 0x3d4) + 4) + 0x10) + 0x2e06) == -0x7baf) {
    if (*(int *)(param_1 + 0x50) == -1) {
      return 2;
    }
    if (3 < *(uint *)(param_1 + 0x54)) {
      return 3;
    }
  }
  if ((((*(int *)(param_1 + 0x3d8) == 0) && (iVar1 != *(int *)(param_1 + 0x74))) &&
      (iVar1 != *(int *)(param_1 + 0x78))) &&
     ((iVar1 != *(int *)(param_1 + 0x7c) && (iVar1 != *(int *)(param_1 + 0x80))))) {
    return 3;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x3d4) + 0x12e) = 0;
  uVar2 = ((int (*)())FUN_0009890f)();
  return uVar2;
}

/* FUN_00098f9f @ 0x98f9f (1356 bytes) */
int FUN_00098f9f(param_1)
  int param_1;
{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined1 *local_a4;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 *local_84;
  undefined1 local_6c [4];
  undefined4 local_68;
  undefined1 local_44 [4];
  undefined4 local_40;
  undefined1 local_3c [16];
  undefined1 local_2c [28];
  
  iVar2 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x588) == -1) {
    local_9c = **(undefined4 **)(param_1 + 0x3f0);
    puVar10 = *(undefined4 **)(param_1 + 0x3ec);
    uVar3 = puVar10[2];
    uVar4 = *(undefined4 *)(param_1 + 0x330);
    if (*(short *)(*(int *)(*(int *)(iVar2 + 4) + 0x10) + 0x2e06) == -0x7bae) {
      if (*(int *)(param_1 + 0x3f8) == -1) {
        if ((*(byte *)((int)&switchdataD_000013c0 + iVar2) & 4) == 0) {
          ((int (*)())FUN_0008c3ce)();
        }
        else {
          ((int (*)())FUN_0008c178)();
        }
        if (*(int *)(param_1 + 0x3f8) == -1) {
          return 2;
        }
        puVar10 = *(undefined4 **)(param_1 + 0x3ec);
      }
      local_94 = *puVar10;
      local_90 = *(undefined4 *)(param_1 + 0x3f8);
      local_84 = &DAT_001ee980;
    }
    else {
      local_94 = puVar10[1];
      local_90 = *(undefined4 *)(param_1 + 0x50);
      iVar8 = *(int *)(param_1 + 0x54);
      if (iVar8 == 1) {
        local_84 = &DAT_001ee970;
      }
      else if (iVar8 == 0) {
        local_84 = &DAT_00210694;
      }
      else if (iVar8 == 2) {
        local_84 = &DAT_001ee980;
      }
      else if (iVar8 == 3) {
        local_84 = &DAT_001ee960;
      }
      else {
        local_84 = &DAT_001ee9a0;
      }
    }
    iVar8 = ((int (*)())FUN_0008bb1c)(param_1,2,param_1 + 0x584);
    if (iVar8 != 0) {
      return 7;
    }
    local_98 = *(undefined4 *)(param_1 + 0x588);
    iVar8 = ((int (*)())FUN_0008bb1c)(param_1,2,local_44);
    uVar7 = local_40;
    if (iVar8 != 0) {
      return 7;
    }
    iVar8 = *(int *)(param_1 + 0x3d4);
    iVar9 = *(int *)(*(int *)(iVar8 + 4) + 0x10);
    if ((*(short *)(iVar9 + 0x2e06) == -0x7bae) &&
       (sVar1 = *(short *)(iVar9 + 0x2e08), sVar1 != -0x7aa4)) {
      if (sVar1 == -0x7aa5) {
        uVar5 = **(undefined4 **)(param_1 + 0x3f0);
        uVar6 = **(undefined4 **)(param_1 + 0x3ec);
        iVar9 = ((int (*)())FUN_0008bb1c)(param_1,1,local_6c);
        if (iVar9 != 0) {
          return 7;
        }
        (**(code **)(iVar8 + 0x12e4))
                  (param_1,uVar5,local_68,&DAT_001ee990,local_94,local_90,&DAT_001eea00,
                   &DAT_00210684,local_94,local_90,&DAT_001eea00,&DAT_00210684);
        (**(code **)(iVar8 + 0x1318))
                  (param_1,uVar5,local_68,&DAT_001ee9f0,uVar6,local_68,&DAT_00210694,&DAT_00210684);
        (**(code **)(iVar8 + 0x12e4))
                  (param_1,local_9c,uVar7,local_3c,uVar6,local_68,&DAT_001eeb80,&DAT_00210684,uVar6,
                   local_68,&DAT_001eeb70,&DAT_00210684);
        ((int (*)())FUN_0008bf53)(param_1,local_6c);
      }
      else {
        (**(code **)(iVar8 + 0x12e8))
                  (param_1,local_9c,local_40,local_3c,local_94,local_90,local_84,&DAT_001eea20);
      }
    }
    else {
      (**(code **)(iVar8 + 0x1304))
                (param_1,local_9c,local_40,local_3c,local_94,local_90,local_84,&DAT_00210684,
                 local_94,local_90,local_84,&DAT_001eea20);
    }
    local_a4 = local_3c;
    uVar7 = **(undefined4 **)(param_1 + 0x3ec);
    (**(code **)(iVar2 + 0x12ec))
              (param_1,local_9c,local_40,local_a4,uVar3,uVar4,&DAT_001ee980,&DAT_00210684,uVar7,
               local_40,local_2c,&DAT_00210684);
    if (*(int *)(param_1 + 0x3d8) == 0) {
      if ((*(byte *)(iVar2 + 0x44) & 1) == 0) {
        local_9c = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
        local_98 = *(undefined4 *)(param_1 + 0x70);
        puVar10 = &DAT_001ee9d0;
      }
      else {
        puVar10 = (undefined4 *)(param_1 + 0x58c);
      }
    }
    else {
      local_9c = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
      local_98 = *(undefined4 *)(param_1 + 0x70);
      puVar10 = &DAT_001ee990;
    }
    (**(code **)(iVar2 + 0x1320))
              (param_1,local_9c,local_98,puVar10,uVar7,local_40,local_2c,&DAT_00210684);
    ((int (*)())FUN_0008bf53)(param_1,local_44);
  }
  return 0;
}

/* FUN_000994eb @ 0x994eb (928 bytes) */
int FUN_000994eb(param_1, param_2)
  int param_1;
  int param_2;
{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 *local_58;
  int local_54;
  int local_50;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  if (param_1 == 0) {
    return 1;
  }
  iVar2 = *(int *)(param_1 + 0x3d4);
  iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x10);
  uVar4 = **(undefined4 **)(param_1 + 0x3ec);
  local_50 = param_1;
  local_54 = param_1;
  local_64 = 0;
  do {
    uVar5 = *(undefined4 *)(local_54 + 0x5b0);
    local_60 = *(undefined4 *)(local_54 + 0x600);
    uVar9 = *(undefined4 *)(local_50 + 0x74);
    ((int (*)())FUN_0008c003)(local_20,&local_24);
    local_34 = 5;
    local_30 = 5;
    local_2c = 5;
    local_28 = 3;
    if (param_2 == 0) {
      (**(code **)(iVar2 + 0x12ec))
                (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc),uVar9,&DAT_001ee9b0,uVar4,
                 uVar5,&DAT_001eea50,&DAT_00210684,local_20[0],local_24,&local_34,&DAT_00210684);
      if (*(short *)(iVar3 + 0x2d48) == -0x7e06) goto LAB_0009975b;
LAB_000995cb:
      if (((*(char *)(iVar2 + 0x44) < '\0') && (*(char *)(iVar2 + 0x121) == '\0')) ||
         ((*(byte *)(iVar2 + 0x45) & 0x85) != 0)) goto LAB_000995e4;
    }
    else {
      if (*(short *)(iVar3 + 0x2d48) != -0x7e06) goto LAB_000995cb;
LAB_0009975b:
      if (*(char *)(iVar2 + 0x12d) == '\0') goto LAB_000995cb;
LAB_000995e4:
      uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x10);
      iVar6 = *(int *)(local_50 + 0x7c);
      ((int (*)())FUN_0008c003)(local_20,&local_24);
      if ((*(short *)(iVar3 + 0x2d48) == -0x7e06) && (*(char *)(iVar2 + 0x12d) != '\0')) {
        if (param_2 == 0) {
          local_60 = local_24;
          local_58 = &DAT_001eea30;
          local_5c = local_20[0];
        }
        else {
          local_58 = (undefined4 *)&DAT_001eea50;
          local_5c = uVar4;
        }
      }
      else {
        local_5c = local_20[0];
        local_60 = local_24;
        local_58 = &DAT_001eea30;
      }
      uVar8 = local_24;
      uVar9 = local_20[0];
      if (((*(char *)(iVar2 + 0x44) < '\0') && (*(char *)(iVar2 + 0x121) == '\0')) &&
         ((*(int *)(param_1 + 0x3d8) == 0 && (iVar6 == *(int *)(param_1 + 0x70))))) {
        if (*(char *)(iVar2 + 0x12e) == '\0') {
          if (*(int *)(param_1 + 0x588) == -1) {
            sVar1 = *(short *)(iVar3 + 0x2e04);
            if (sVar1 == 0x801) {
              ((int (*)())FUN_0008d842)();
            }
            else if (sVar1 == 0x2601) {
              ((int (*)())FUN_0009890f)();
            }
            else if (sVar1 == 0x800) {
              ((int (*)())FUN_00098f9f)();
            }
            if (*(int *)(param_1 + 0x588) == -1) {
              return 2;
            }
          }
          local_28 = *(undefined4 *)(param_1 + 0x5a8);
          uVar8 = *(undefined4 *)(param_1 + 0x588);
          uVar9 = uVar4;
        }
        else {
          uVar9 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
          uVar8 = *(undefined4 *)(param_1 + 0x50);
          iVar7 = *(int *)(param_1 + 0x54);
          if (iVar7 == 1) {
            local_28 = 1;
          }
          else if (iVar7 == 0) {
            local_28 = 0;
          }
          else if (iVar7 == 2) {
            local_28 = 2;
          }
          else {
            local_28 = 3;
          }
        }
      }
      (**(code **)(iVar2 + 0x12ec))
                (param_1,uVar5,iVar6,&DAT_001ee9b0,local_5c,local_60,local_58,&DAT_00210684,uVar9,
                 uVar8,&local_34,&DAT_00210684);
    }
    local_64 = local_64 + 1;
    local_54 = local_54 + 0x28;
    local_50 = local_50 + 4;
    if (*(byte *)(iVar3 + 0x2d4c) < local_64) {
      return 0;
    }
  } while( true );
}

/* FUN_0009988b @ 0x9988b (124 bytes) */
int FUN_0009988b(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 0x330) == -1) || (iVar1 = *(int *)(param_1 + 0x70), iVar1 == -1)) {
    return 2;
  }
  if (*(short *)(*(int *)(*(int *)(*(int *)(param_1 + 0x3d4) + 4) + 0x10) + 0x2e06) == -0x7baf) {
    if (*(int *)(param_1 + 0x50) == -1) {
      return 2;
    }
    if (3 < *(uint *)(param_1 + 0x54)) {
      return 3;
    }
  }
  if ((((*(int *)(param_1 + 0x3d8) == 0) && (iVar1 != *(int *)(param_1 + 0x74))) &&
      (iVar1 != *(int *)(param_1 + 0x78))) &&
     ((iVar1 != *(int *)(param_1 + 0x7c) && (iVar1 != *(int *)(param_1 + 0x80))))) {
    return 3;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x3d4) + 0x12e) = 0;
  uVar2 = ((int (*)())FUN_00098f9f)();
  return uVar2;
}

/* FUN_00099907 @ 0x99907 (968 bytes) */
int FUN_00099907(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int local_7c;
  undefined1 local_54 [4];
  undefined4 local_50;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (param_1 == 0) {
    uVar7 = 1;
  }
  else {
    if (param_2 < 8) {
      iVar1 = *(int *)(param_1 + 0x84 + param_2 * 4);
      if (iVar1 == -1) {
        return 2;
      }
      local_7c = *(int *)(param_1 + 0x3d4);
      uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x14);
      local_2c = DAT_001eea30;
      local_28 = DAT_001eea34;
      local_24 = DAT_001eea38;
      local_20 = DAT_001eea3c;
      if (*(short *)(*(int *)(*(int *)(local_7c + 4) + 0x10) + 0x2e06) == -0x7bae) {
        if (*(int *)(param_1 + 0x3f8) == -1) {
          if ((*(byte *)((int)&switchdataD_000013c0 + local_7c) & 4) == 0) {
            ((int (*)())FUN_0008c3ce)();
          }
          else {
            ((int (*)())FUN_0008c178)();
          }
          if (*(int *)(param_1 + 0x3f8) == -1) {
            return 2;
          }
          local_7c = *(int *)(param_1 + 0x3d4);
        }
        uVar3 = **(undefined4 **)(param_1 + 0x3ec);
        uVar4 = *(undefined4 *)(param_1 + 0x3f8);
        local_2c = 2;
        iVar8 = *(int *)(*(int *)(local_7c + 4) + 0x10);
        if (*(short *)(iVar8 + 0x2e06) != -0x7bae) {
          (**(code **)(local_7c + 0x1304))
                    (param_1,uVar7,iVar1,&DAT_001ee9b0,uVar3,uVar4,&local_2c,&DAT_00210684,uVar3,
                     uVar4,&local_2c,&DAT_001eea20);
          return 0;
        }
        if (*(short *)(iVar8 + 0x2e08) == -0x7aa5) {
          uVar5 = **(undefined4 **)(param_1 + 0x3f0);
          uVar6 = **(undefined4 **)(param_1 + 0x3ec);
          iVar8 = ((int (*)())FUN_0008bb1c)(param_1,1,local_54);
          if (iVar8 != 0) {
            return 7;
          }
          (**(code **)(local_7c + 0x12e4))
                    (param_1,uVar5,local_50,&DAT_001ee990,uVar3,uVar4,&DAT_001eea00,&DAT_00210684,
                     uVar3,uVar4,&DAT_001eea00,&DAT_00210684);
          (**(code **)(local_7c + 0x1318))
                    (param_1,uVar5,local_50,&DAT_001ee9f0,uVar6,local_50,&DAT_00210694,&DAT_00210684
                    );
          (**(code **)(local_7c + 0x12e4))
                    (param_1,uVar7,iVar1,&DAT_001ee9b0,uVar6,local_50,&DAT_001eeb80,&DAT_00210684,
                     uVar6,local_50,&DAT_001eeb70,&DAT_00210684);
          ((int (*)())FUN_0008bf53)(param_1,local_54);
          return 0;
        }
        (**(code **)(local_7c + 0x12e8))
                  (param_1,uVar7,iVar1,&DAT_001ee9b0,uVar3,uVar4,&local_2c,&DAT_001eea20);
        return 0;
      }
      if (*(int *)(param_1 + 0x50) == -1) {
        return 2;
      }
      uVar2 = *(uint *)(param_1 + 0x54);
      if (uVar2 < 4) {
        if (uVar2 == 1) {
          local_2c = 1;
        }
        else if (uVar2 == 0) {
          local_2c = 0;
        }
        else if (uVar2 == 2) {
          local_2c = 2;
        }
        else if (uVar2 == 3) {
          local_2c = 3;
        }
        else {
          local_2c = 4;
        }
        (**(code **)(local_7c + 0x12e8))
                  (param_1,uVar7,iVar1,&DAT_001ee9b0,*(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),
                   *(int *)(param_1 + 0x50),&local_2c,&DAT_00210684);
        return 0;
      }
    }
    uVar7 = 3;
  }
  return uVar7;
}

/* FUN_00099cd0 @ 0x99cd0 (35 bytes) */
int FUN_00099cd0(param_1, param_2, param_3)
  int param_1;
  undefined8 *param_2;
  int param_3;
{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)(param_3 * 0x10 + param_1);
  uVar1 = param_2[1];
  *puVar2 = *param_2;
  puVar2[1] = uVar1;
  return;
}

/* FUN_00099cf3 @ 0x99cf3 (298 bytes) */
int FUN_00099cf3(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 *param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  
  puVar16 = (undefined4 *)(param_4 * 0x10 + param_2);
  uVar1 = param_3[1];
  uVar2 = param_3[2];
  uVar3 = param_3[3];
  uVar4 = param_3[4];
  uVar5 = param_3[5];
  uVar6 = param_3[6];
  uVar7 = param_3[7];
  uVar8 = param_3[8];
  uVar9 = param_3[9];
  uVar10 = param_3[10];
  uVar11 = param_3[0xb];
  uVar12 = param_3[0xc];
  uVar13 = param_3[0xd];
  uVar14 = param_3[0xe];
  uVar15 = param_3[0xf];
  if (param_1 != '\0') {
    *puVar16 = *param_3;
    puVar16[1] = uVar1;
    puVar16[2] = uVar2;
    puVar16[3] = uVar3;
    puVar16[4] = uVar4;
    puVar16[5] = uVar5;
    puVar16[6] = uVar6;
    puVar16[7] = uVar7;
    puVar16[8] = uVar8;
    puVar16[9] = uVar9;
    puVar16[10] = uVar10;
    puVar16[0xb] = uVar11;
    puVar16[0xc] = uVar12;
    puVar16[0xd] = uVar13;
    puVar16[0xe] = uVar14;
    puVar16[0xf] = uVar15;
    return;
  }
  *puVar16 = *param_3;
  puVar16[1] = uVar4;
  puVar16[2] = uVar8;
  puVar16[3] = uVar12;
  puVar16[4] = uVar1;
  puVar16[5] = uVar5;
  puVar16[6] = uVar9;
  puVar16[7] = uVar13;
  puVar16[8] = uVar2;
  puVar16[9] = uVar6;
  puVar16[10] = uVar10;
  puVar16[0xb] = uVar14;
  puVar16[0xc] = uVar3;
  puVar16[0xd] = uVar7;
  puVar16[0xe] = uVar11;
  puVar16[0xf] = uVar15;
  return;
}

/* FUN_00099e1d @ 0x99e1d (53 bytes) */
int FUN_00099e1d(param_1)
  int param_1;
{
  ushort uVar1;
  int *piVar2;
  
  uVar1 = *(ushort *)(((unsigned char *)0x000013be) + param_1);
  piVar2 = (int *)(**(code **)(param_1 + 0xc))((uint)uVar1 * 8 + 0xc);
  *piVar2 = (int)(piVar2 + 3);
  piVar2[1] = (int)(piVar2 + 3 + uVar1);
  piVar2[2] = 0;
  return;
}

/* FUN_00099e52 @ 0x99e52 (163 bytes) */
int FUN_00099e52(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(undefined1 *)(param_1 + 0x125) = 0;
  *(undefined1 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined1 *)(param_1 + 0x131) = param_2;
  *(undefined1 *)(param_1 + 0x12d) = 0;
  *(undefined1 *)(param_1 + 0x12f) = 0;
  *(code **)(param_1 + 0x12c8) = FUN_00099cf3;
  *(code **)(param_1 + 0x12cc) = FUN_00099cd0;
  iVar2 = 8;
  iVar1 = param_1;
  do {
    *(undefined4 *)(iVar1 + 0x150) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar1 = 0;
  do {
    *(undefined1 *)(param_1 + 0x3a8 + iVar1 * 4) = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 != 8);
  *(undefined1 *)(param_1 + 0x126) = 0;
  *(undefined1 *)(param_1 + 299) = 0;
  return;
}

/* FUN_00099ef5 @ 0x99ef5 (2040 bytes) */
int FUN_00099ef5(param_1)
  int param_1;
{
  byte *pbVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  float fVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  undefined4 uVar9;
  bool bVar10;
  float fVar11;
  undefined1 uVar12;
  char cVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  float *pfVar17;
  int iVar18;
  uint uVar19;
  bool bVar20;
  byte *local_4c;
  uint local_34;
  int local_18;
  
  iVar8 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  iVar15 = param_1 + 0x124;
  cVar13 = *(char *)(iVar8 + 0x24ad);
  cVar5 = *(char *)(iVar8 + 0x24ae);
  cVar6 = *(char *)(param_1 + 0x12f);
  if ((*(byte *)(param_1 + 0x44) & 1) == 0) {
    cVar13 = '\0';
    if ((*(byte *)(param_1 + 0x8c) & 0x30) != 0) {
      cVar13 = cVar5;
    }
    *(char *)(param_1 + 300) = cVar13;
    return;
  }
  bVar20 = *(short *)(iVar8 + 0x2d48) == -0x7e06;
  cVar7 = *(char *)(iVar8 + 0x2d4d);
  uVar9 = *(undefined4 *)
           (&DAT_001eeba0 +
           (uint)*(byte *)(iVar8 + 0x2d4b) *
           ((*(ushort *)(iVar8 + 0x2d44) & 1 | (int)(*(ushort *)(iVar8 + 0x2d44) & 8) >> 2) +
           (((int)(*(ushort *)(iVar8 + 0x2d46) & 0x400) >> 8) + (*(ushort *)(iVar8 + 0x2d46) & 0xf))
           * 3 + 1) * 4);
  *(undefined4 *)(param_1 + 0x26c) = uVar9;
  uVar14 = 0;
  if (*(int *)(param_1 + 0x13c) == 1) {
    uVar14 = uVar9;
  }
  *(undefined4 *)(param_1 + 0x1890) = uVar14;
  *(undefined1 *)(param_1 + 0x12f) = 0;
  if ((cVar7 == '\0') || (cVar5 != '\0')) {
    if ((((*(byte *)(param_1 + 0x8c) >> 4 | *(byte *)(param_1 + 0x8c) >> 5) & 1) != 0) &&
       (((*(byte *)(param_1 + 0x42) & 1) != 0 && (*(char *)(param_1 + 0x13b5) != '\0')))) {
      iVar16 = 0;
      iVar18 = param_1;
      do {
        *(byte *)(iVar18 + 0x1814) = *(byte *)(iVar18 + 0x1814) | 0x18;
        iVar16 = iVar16 + 1;
        iVar18 = iVar18 + 1;
      } while (iVar16 < (int)(uint)*(byte *)(param_1 + 0x13b5));
    }
    if (((cVar5 == '\0') || (cVar13 != '\0')) || (*(char *)(param_1 + 0x12f) != '\0')) {
      uVar12 = 0;
    }
    else {
      uVar12 = 1;
    }
    *(undefined1 *)(param_1 + 300) = uVar12;
    if ((cVar6 != *(char *)(param_1 + 0x12f)) && (*(char *)(param_1 + 0x13b5) != '\0')) {
      iVar16 = 0;
      iVar18 = param_1;
      do {
        *(byte *)(iVar18 + 0x1814) = *(byte *)(iVar18 + 0x1814) | 0x18;
        iVar16 = iVar16 + 1;
        iVar18 = iVar18 + 1;
      } while (iVar16 < (int)(uint)*(byte *)(param_1 + 0x13b5));
    }
  }
  else {
    *(undefined1 *)(param_1 + 300) = 0;
    if (((*(byte *)(param_1 + 0x42) & 1) != 0) && (*(char *)(param_1 + 0x13b5) != '\0')) {
      iVar16 = 0;
      iVar18 = param_1;
      do {
        *(byte *)(iVar18 + 0x1814) = *(byte *)(iVar18 + 0x1814) | 0x18;
        iVar16 = iVar16 + 1;
        iVar18 = iVar18 + 1;
      } while (iVar16 < (int)(uint)*(byte *)(param_1 + 0x13b5));
    }
  }
  if ((*(uint *)(param_1 + 0x180c) & 1) != 0) {
    *(uint *)(param_1 + 0x180c) = *(uint *)(param_1 + 0x180c) & 0xfffffffe;
  }
  uVar19 = DAT_001c63f0;
  fVar11 = FLOAT_001c5ba4;
  local_34 = *(uint *)(param_1 + 0x88);
  if (local_34 != 0) {
    bVar10 = false;
    local_18 = 0;
    local_4c = (byte *)(param_1 + 0x1895);
    iVar18 = param_1;
    do {
      iVar16 = iVar18 - param_1;
      if ((local_34 & 1) != 0) {
        pfVar17 = (float *)(iVar8 + 0x24c0 + iVar16 * 0x80);
        puVar2 = (undefined4 *)(param_1 + 0x14a4 + local_18);
        pbVar1 = (byte *)(iVar18 + 0x1814);
        if (*(byte *)(iVar18 + 0x1814) != 0) {
          if ((*(byte *)(iVar18 + 0x1814) & 1) != 0) {
            fVar4 = *pfVar17;
            if (((((fVar4 != 0.0) || (NAN(fVar4))) || (pfVar17[1] != 0.0)) ||
                ((NAN(pfVar17[1]) || (pfVar17[2] != 0.0)))) || (NAN(pfVar17[2]))) {
              if (((fVar4 != FLOAT_001c5ba4) || (FLOAT_001c5ba4 != pfVar17[1])) ||
                 ((FLOAT_001c5ba4 != pfVar17[2] || (NAN(FLOAT_001c5ba4) || NAN(pfVar17[2]))))) {
                if (((((FLOAT_001c5ba4 != pfVar17[0x14]) ||
                      (NAN(FLOAT_001c5ba4) || NAN(pfVar17[0x14]))) || (pfVar17[0x15] != 0.0)) ||
                    ((pfVar17[0x16] != 0.0 || (NAN(pfVar17[0x16]))))) ||
                   (*(char *)(puVar2 + 0x1a) != '\0')) {
                  *(byte *)(param_1 + 0x3a8 + iVar16 * 4) =
                       *(byte *)(param_1 + 0x3a8 + iVar16 * 4) & 0xfc | 2;
                  local_4c[-1] = local_4c[-1] & 0xf9 | 4;
                }
                else {
                  pbVar3 = (byte *)(param_1 + 0x3a8 + iVar16 * 4);
                  *pbVar3 = *pbVar3 | 3;
                  local_4c[-1] = local_4c[-1] | 6;
                  bVar10 = true;
                }
              }
              else {
                *(byte *)(param_1 + 0x3a8 + iVar16 * 4) =
                     *(byte *)(param_1 + 0x3a8 + iVar16 * 4) & 0xfc | 1;
                local_4c[-1] = local_4c[-1] & 0xf9 | 2;
              }
            }
            else {
              pbVar3 = (byte *)(param_1 + 0x3a8 + iVar16 * 4);
              *pbVar3 = *pbVar3 & 0xfc;
              local_4c[-1] = local_4c[-1] & 0xf9;
            }
          }
          if ((*pbVar1 & 2) != 0) {
            fVar4 = pfVar17[4];
            if (((fVar4 != 0.0) || (NAN(fVar4))) ||
               ((pfVar17[5] != 0.0 ||
                (((NAN(pfVar17[5]) || (pfVar17[6] != 0.0)) || (NAN(pfVar17[6]))))))) {
              if (((fVar4 != fVar11) || (fVar11 != pfVar17[5])) ||
                 ((fVar11 != pfVar17[6] || (NAN(fVar11) || NAN(pfVar17[6]))))) {
                *(byte *)(param_1 + 0x3a8 + iVar16 * 4) =
                     *(byte *)(param_1 + 0x3a8 + iVar16 * 4) & 0xf3 | 8;
                local_4c[-1] = local_4c[-1] & 0xe7 | 0x10;
              }
              else {
                *(byte *)(param_1 + 0x3a8 + iVar16 * 4) =
                     *(byte *)(param_1 + 0x3a8 + iVar16 * 4) & 0xf3 | 4;
                local_4c[-1] = local_4c[-1] & 0xe7 | 8;
              }
            }
            else {
              pbVar3 = (byte *)(param_1 + 0x3a8 + iVar16 * 4);
              *pbVar3 = *pbVar3 & 0xf3;
              local_4c[-1] = local_4c[-1] & 0xe7;
            }
          }
          if ((*pbVar1 & 4) != 0) {
            fVar4 = pfVar17[8];
            if (((fVar4 != 0.0) || (NAN(fVar4))) ||
               ((pfVar17[9] != 0.0 ||
                (((NAN(pfVar17[9]) || (pfVar17[10] != 0.0)) || (NAN(pfVar17[10]))))))) {
              if (((fVar4 != fVar11) || (fVar11 != pfVar17[9])) ||
                 ((fVar11 != pfVar17[10] || (NAN(fVar11) || NAN(pfVar17[10]))))) {
                *(byte *)(param_1 + 0x3a8 + iVar16 * 4) =
                     *(byte *)(param_1 + 0x3a8 + iVar16 * 4) & 0xcf | 0x20;
                local_4c[-1] = local_4c[-1] & 0x9f | 0x40;
              }
              else {
                *(byte *)(param_1 + 0x3a8 + iVar16 * 4) =
                     *(byte *)(param_1 + 0x3a8 + iVar16 * 4) & 0xcf | 0x10;
                local_4c[-1] = local_4c[-1] & 0x9f | 0x20;
              }
            }
            else {
              pbVar3 = (byte *)(param_1 + 0x3a8 + iVar16 * 4);
              *pbVar3 = *pbVar3 & 0xcf;
              local_4c[-1] = local_4c[-1] & 0x9f;
            }
          }
          if ((*pbVar1 & 0x20) != 0) {
            if (((pfVar17[0x15] != 0.0) || (NAN(pfVar17[0x15]))) ||
               ((pfVar17[0x16] != 0.0 || (NAN(pfVar17[0x16]))))) {
              *(byte *)(param_1 + 0x3a8 + iVar16 * 4) =
                   *(byte *)(param_1 + 0x3a8 + iVar16 * 4) & 0x7f | 0x40;
              *local_4c = *local_4c & 0xef | 8;
            }
            else if ((pfVar17[0x14] == fVar11) || (pfVar17[0x14] == 0.0)) {
              pbVar3 = (byte *)(param_1 + 0x3a8 + iVar16 * 4);
              *pbVar3 = *pbVar3 & 0x3f;
              *local_4c = *local_4c & 0xe7;
            }
            else {
              pbVar3 = (byte *)(param_1 + 0x3a8 + iVar16 * 4);
              *pbVar3 = *pbVar3 | 0xc0;
              *local_4c = *local_4c | 0x18;
              *(byte *)(iVar18 + 0x181c) = *(byte *)(iVar18 + 0x181c) | 4;
            }
          }
          if (pfVar17[0xf] == 0.0) {
            if (*(char *)(param_1 + 0x12f) == '\0') {
              *(undefined4 *)(iVar15 + 0x174) = puVar2[0x14];
              *(undefined4 *)(iVar15 + 0x178) = puVar2[0x15];
              *(undefined4 *)(iVar15 + 0x17c) = puVar2[0x16];
              *(undefined4 *)(iVar15 + 0x180) = puVar2[0x17];
              *(undefined4 *)(iVar15 + 500) = puVar2[0x10];
              *(undefined4 *)(iVar15 + 0x1f8) = puVar2[0x11];
              *(undefined4 *)(iVar15 + 0x1fc) = puVar2[0x12];
              *(undefined4 *)(iVar15 + 0x200) = puVar2[0x13];
            }
            else {
              *(undefined4 *)(iVar15 + 0x174) = puVar2[0xc];
              *(undefined4 *)(iVar15 + 0x178) = puVar2[0xd];
              *(undefined4 *)(iVar15 + 0x17c) = puVar2[0xe];
              *(undefined4 *)(iVar15 + 0x180) = puVar2[0xf];
              *(undefined4 *)(iVar15 + 500) = puVar2[8];
              *(undefined4 *)(iVar15 + 0x1f8) = puVar2[9];
              *(undefined4 *)(iVar15 + 0x1fc) = puVar2[10];
              *(undefined4 *)(iVar15 + 0x200) = puVar2[0xb];
            }
          }
          else {
            *(undefined4 *)(iVar15 + 0x174) = *puVar2;
            *(undefined4 *)(iVar15 + 0x178) = puVar2[1];
            *(undefined4 *)(iVar15 + 0x17c) = puVar2[2];
            *(undefined4 *)(iVar15 + 0x180) = puVar2[3];
            *(uint *)(iVar15 + 500) = puVar2[4] ^ uVar19;
            *(uint *)(iVar15 + 0x1f8) = puVar2[5] ^ uVar19;
            *(uint *)(iVar15 + 0x1fc) = puVar2[6] ^ uVar19;
            *(byte *)(param_1 + 0x3a9 + iVar16 * 4) =
                 *(byte *)(param_1 + 0x3a9 + iVar16 * 4) & 0xfe | fVar11 == pfVar17[0xf];
          }
          *pbVar1 = 0;
        }
        if (*(char *)(iVar18 + 0x181c) != '\0') {
          *(undefined1 *)(iVar18 + 0x181c) = 0;
        }
        bVar20 = (bool)(bVar20 | (*(byte *)(param_1 + 0x3a8 + iVar16 * 4) & 0x30) != 0);
      }
      iVar18 = iVar18 + 1;
      local_4c = local_4c + 2;
      iVar15 = iVar15 + 0x10;
      local_18 = local_18 + 0x6c;
      local_34 = local_34 >> 1;
    } while (local_34 != 0);
    if (bVar10) {
      *(undefined4 *)(param_1 + 0x398) = 0;
      *(undefined4 *)(param_1 + 0x39c) = 0;
      *(undefined4 *)(param_1 + 0x3a0) = 0;
      *(byte *)(param_1 + 0x1877) = *(byte *)(param_1 + 0x1877) | 0x20;
      uVar19 = *(uint *)(param_1 + 0x88);
      if (uVar19 != 0) {
        iVar15 = 0;
        pfVar17 = (float *)(iVar8 + 0x24c0);
        do {
          while (((uVar19 & 1) != 0 && ((*(byte *)(param_1 + 0x3a8 + iVar15 * 4) & 3) == 3))) {
            *(float *)(param_1 + 0x398) = *(float *)(param_1 + 0x398) + *pfVar17;
            *(float *)(param_1 + 0x39c) = *(float *)(param_1 + 0x39c) + pfVar17[1];
            *(float *)(param_1 + 0x3a0) = *(float *)(param_1 + 0x3a0) + pfVar17[2];
            iVar15 = iVar15 + 1;
            pfVar17 = pfVar17 + 0x20;
            uVar19 = uVar19 >> 1;
            if (uVar19 == 0) goto LAB_0009a4fd;
          }
          iVar15 = iVar15 + 1;
          pfVar17 = pfVar17 + 0x20;
          uVar19 = uVar19 >> 1;
        } while (uVar19 != 0);
      }
    }
  }
LAB_0009a4fd:
  *(bool *)(param_1 + 0x12d) = bVar20;
  return;
}

/* FUN_0009a6ed @ 0x9a6ed (172 bytes) */
int FUN_0009a6ed(param_1)
  int param_1;
{
  int iVar1;
  int *piVar2;
  undefined4 local_10;
  
  if (*(int *)(param_1 + 0x111c) != 0) {
    local_10 = 0;
    do {
      piVar2 = (int *)(local_10 * 4 + *(int *)(param_1 + 0x1118));
      iVar1 = *piVar2;
      while (iVar1 != 0) {
        *piVar2 = *(int *)(iVar1 + 0x5c);
        ((int (*)())FUN_000988d2)(param_1,*(undefined4 *)(iVar1 + 0x54));
        if (*(int *)(iVar1 + 0x4c) != 0) {
          (**(code **)(param_1 + 0x18))(*(int *)(iVar1 + 0x4c));
        }
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar1 + 0x50));
        (**(code **)(param_1 + 0x18))(iVar1);
        piVar2 = (int *)(local_10 * 4 + *(int *)(param_1 + 0x1118));
        iVar1 = *piVar2;
      }
      *piVar2 = 0;
      local_10 = local_10 + 1;
    } while (local_10 < *(uint *)(param_1 + 0x111c));
  }
  *(undefined4 *)(param_1 + 0x3c8) = 0;
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(undefined4 *)(param_1 + 0x148c) = 0;
  return;
}

/* FUN_0009a799 @ 0x9a799 (668 bytes) */
int FUN_0009a799(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint *param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  undefined4 *param_7;
  int param_8;
{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  byte bVar6;
  uint uVar7;
  uint *puVar8;
  uint *local_20;
  
  puVar2 = (uint *)(**(code **)(param_1 + 0xc))(0x60);
  if (1000000 < *(uint *)(param_1 + 0x3c8)) {
    ((int (*)())FUN_0009a6ed)(param_1);
  }
  if (*(char *)(param_1 + 0x1120) != '\0') {
    uVar7 = (*param_2 + param_2[2] + param_2[3]) % *(uint *)(param_1 + 0x111c);
    goto LAB_0009a7f2;
  }
  puVar4 = param_2 + 0xc;
  if (puVar4 < param_2 + 0xb) {
    uVar7 = 0;
    local_20 = param_2 + 5;
    puVar8 = param_2;
    if (local_20 <= puVar4) goto LAB_0009a9ce;
LAB_0009a963:
    bVar6 = 0;
    local_20 = puVar8;
  }
  else {
    uVar7 = 0;
    puVar5 = param_2;
    puVar1 = param_2 + 0xb;
    do {
      puVar8 = puVar1;
      uVar7 = uVar7 ^ *puVar5 ^ (puVar5[1] >> 0x1d | puVar5[1] << 3) ^
              (puVar5[2] >> 0x1a | puVar5[2] << 6) ^ (puVar5[3] >> 0x17 | puVar5[3] << 9) ^
              (puVar5[4] >> 0x14 | puVar5[4] << 0xc) ^ (puVar5[5] >> 0x11 | puVar5[5] << 0xf) ^
              (puVar5[6] >> 0xe | puVar5[6] << 0x12) ^ (puVar5[7] >> 0xb | puVar5[7] << 0x15) ^
              (puVar5[8] >> 8 | puVar5[8] << 0x18) ^ (puVar5[9] >> 5 | puVar5[9] << 0x1b) ^
              (puVar5[10] >> 2 | puVar5[10] << 0x1e);
      puVar5 = puVar8;
      puVar1 = puVar8 + 0xb;
    } while (puVar8 + 0xb <= puVar4);
    local_20 = puVar8 + 5;
    if (puVar4 < local_20) goto LAB_0009a963;
LAB_0009a9ce:
    uVar7 = uVar7 ^ *puVar8 ^ (puVar8[1] >> 0x1d | puVar8[1] << 3) ^
            (puVar8[2] >> 0x1a | puVar8[2] << 6) ^ (puVar8[3] >> 0x17 | puVar8[3] << 9) ^
            (puVar8[4] >> 0x14 | puVar8[4] << 0xc);
    bVar6 = 0xf;
  }
  for (; local_20 < puVar4; local_20 = local_20 + 1) {
    uVar7 = uVar7 ^ (*local_20 << (bVar6 & 0x1f) | *local_20 >> 0x20 - (bVar6 & 0x1f));
    bVar6 = bVar6 + 3;
  }
  uVar7 = uVar7 % *(uint *)(param_1 + 0x111c);
LAB_0009a7f2:
  puVar2[0xc] = *(uint *)(param_1 + 0x3c8);
  *(int *)(param_1 + 0x3c8) = *(int *)(param_1 + 0x3c8) + 1;
  *puVar2 = *param_2;
  puVar2[1] = param_2[1];
  puVar2[2] = param_2[2];
  puVar2[3] = param_2[3];
  puVar2[4] = param_2[4];
  puVar2[5] = param_2[5];
  puVar2[6] = param_2[6];
  puVar2[7] = param_2[7];
  puVar2[8] = param_2[8];
  puVar2[9] = param_2[9];
  puVar2[10] = param_2[10];
  puVar2[0xb] = param_2[0xb];
  puVar2[0x15] = param_3;
  puVar2[0xf] = param_4;
  puVar2[0x10] = param_5;
  puVar2[0x11] = *(uint *)(param_3 + 0x3d0);
  puVar2[0x12] = param_6;
  if (param_7 == (undefined4 *)0x0) {
    uVar3 = ((int (*)())FUN_00099e1d)(param_1);
    puVar2[0x14] = uVar3;
    *(undefined4 *)(uVar3 + 8) = 0;
    *(undefined1 *)(puVar2 + 0x16) = 0;
    puVar2[0x13] = 0;
  }
  else {
    puVar2[0x14] = (uint)param_7;
    if (((param_7[2] == 1) && (*(int *)*param_7 == 0)) && (*(int *)param_7[1] == 0)) {
      *(undefined1 *)(puVar2 + 0x16) = 1;
      puVar2[0x13] = 0;
    }
    else {
      *(undefined1 *)(puVar2 + 0x16) = 0;
      uVar3 = (**(code **)(param_1 + 0xc))(param_6 << 4);
      puVar2[0x13] = uVar3;
    }
  }
  *(undefined1 *)((int)puVar2 + 0x59) = param_8;
  puVar2[0x17] = *(uint *)(*(int *)(param_1 + 0x1118) + uVar7 * 4);
  *(uint **)(uVar7 * 4 + *(int *)(param_1 + 0x1118)) = puVar2;
  return puVar2;
}

