#include "decls.h"

/* FUN_00054c10 @ 0x54c10 (388 bytes) */
int FUN_00054c10(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  int *piVar6;
  
  **(int **)(((unsigned char *)0x0000116c) + param_1) = **(int **)(((unsigned char *)0x0000116c) + param_1) + -1;
  if (**(int **)(((unsigned char *)0x0000116c) + param_1) == 0) {
    FUN_00054980();
  }
  piVar6 = *(int **)(((unsigned char *)0x0000116c) + param_2);
  iVar1 = piVar6[4];
  *(int *)(((unsigned char *)0x0000118c) + param_1) = iVar1;
  piVar6[4] = iVar1 + 1;
  ((unsigned char *)0x00001170)[param_1] = 0;
  *(undefined4 *)(((unsigned char *)0x00001188) + param_1) = 0;
  *(int **)(((unsigned char *)0x0000116c) + param_1) = piVar6;
  *(int *)(((unsigned char *)0x00001168) + param_1) = piVar6[3];
  *piVar6 = *piVar6 + 1;
  if (piVar6[1] != 0) {
    uVar3 = 0;
    iVar1 = 0;
    do {
      iVar5 = piVar6[3];
      uVar3 = uVar3 + 1;
      pvVar4 = *(void **)(iVar1 + iVar5);
      uVar2 = (**(code **)(param_1 + 0x10))(piVar6[4],4);
      *(undefined4 *)(iVar1 + iVar5) = uVar2;
      _memcpy(*(void **)(piVar6[3] + iVar1),pvVar4,piVar6[4] * 4 - 4);
      (**(code **)(param_1 + 0x18))(pvVar4);
      (**(code **)(((unsigned char *)0x000011a4) + param_1))
                (param_1,iVar1 + piVar6[3],*(undefined4 *)(((unsigned char *)0x0000118c) + param_1));
      iVar5 = piVar6[3];
      pvVar4 = *(void **)(iVar1 + iVar5 + 4);
      uVar2 = (**(code **)(param_1 + 0x10))(piVar6[4],1);
      *(undefined4 *)(iVar1 + iVar5 + 4) = uVar2;
      iVar5 = piVar6[3] + iVar1;
      iVar1 = iVar1 + 0x7c;
      _memcpy(*(void **)(iVar5 + 4),pvVar4,piVar6[4] - 1);
      (**(code **)(param_1 + 0x18))(pvVar4);
    } while (uVar3 < (uint)piVar6[1]);
  }
  return;
}

/* FUN_00054da0 @ 0x54da0 (36 bytes) */
int FUN_00054da0(param_1, param_2)
  int param_1;
  uint param_2;
{
  if (*(uint *)(param_1 + 0xc) <= param_2) {
    return 0;
  }
  return *(undefined4 *)(param_2 * 4 + *(int *)(param_1 + 8));
}

/* FUN_00054dd0 @ 0x54dd0 (376 bytes) */
int FUN_00054dd0(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  void *param_3;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  if ((uVar2 & 0x3f) == 0) {
    uVar2 = (**(code **)(param_1 + 0xc))(((unsigned char *)0x00001500) + uVar2 * 0x54);
    if (uVar2 != 0) {
      if (param_2[1] != 0) {
        (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar2,param_2[1],*param_2 * 0x54);
        (**(code **)(param_1 + 0x18))(param_2[1]);
      }
      param_2[1] = uVar2;
      uVar2 = *param_2;
      goto LAB_00054e60;
    }
LAB_00054f2c:
    uVar2 = 0;
  }
  else {
LAB_00054e60:
    _memcpy((void *)(param_2[1] + uVar2 * 0x54),param_3,0x54);
    uVar1 = *(uint *)((int)param_3 + 0x20);
    *(undefined1 *)(uVar2 * 0x54 + param_2[1] + 0x3c) = 0;
    if (param_2[3] <= uVar1) {
      uVar1 = (**(code **)(param_1 + 0x10))(uVar1 + 0x40,4);
      if (uVar1 == 0) goto LAB_00054f2c;
      if (param_2[2] != 0) {
        (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar1,param_2[2],param_2[3] << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar1;
      param_2[3] = *(int *)((int)param_3 + 0x20) + 0x40;
      uVar1 = *(uint *)((int)param_3 + 0x20);
    }
    *(uint *)(uVar1 * 4 + param_2[2]) = uVar2;
    *param_2 = *param_2 + 1;
  }
  return uVar2;
}

/* FUN_00054f50 @ 0x54f50 (380 bytes) */
int FUN_00054f50(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  uint param_3;
  undefined4 *param_4;
  undefined4 *param_5;
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  
  if (param_3 == 0) {
    param_5[1] = 0;
    *param_5 = 0;
    goto LAB_000550a0;
  }
  iVar9 = *(int *)(((unsigned char *)0x0000116c) + param_1);
  uVar1 = param_3 & 0x7fffffff;
  *(byte *)(param_5 + 6) = (byte)(param_3 >> 0x1f);
  iVar4 = ((int (*)())FUN_00054da0)(iVar9 + 0x14,uVar1);
  if (iVar4 == 0) {
    iVar5 = ((int (*)())FUN_00054da0)(param_2 + 0x1c,uVar1);
    if (iVar5 == 0) {
      return 0;
    }
  }
  else {
    param_2 = param_2 + 0x1c;
    iVar5 = ((int (*)())FUN_00054da0)(param_2,uVar1);
    if (iVar5 == 0) {
      iVar5 = *(int *)(iVar9 + 0x18);
      iVar8 = iVar4 * 0x54;
      if (*(int *)(iVar5 + iVar8 + 0x30) == 0) {
        uVar2 = *(uint *)(iVar5 + iVar8 + 0x34);
        if (uVar2 < 2) {
          iVar5 = ((int (*)())FUN_00054dd0)(param_1,param_2);
          goto LAB_00055088;
        }
      }
      else {
        iVar4 = ((int (*)())FUN_00054da0)(iVar9 + 0x14);
        iVar8 = iVar4 * 0x54;
        uVar2 = *(uint *)(iVar5 + iVar8 + 0x34);
      }
      if (uVar2 != 0) {
        iVar4 = iVar4 * 0x54;
        uVar2 = 0;
        do {
          iVar5 = iVar4 + iVar5;
          uVar2 = uVar2 + 1;
          iVar4 = iVar4 + 0x54;
          ((int (*)())FUN_00054dd0)(param_1,param_2,iVar5);
          iVar5 = *(int *)(iVar9 + 0x18);
        } while (uVar2 < *(uint *)(iVar8 + iVar5 + 0x34));
      }
      iVar5 = ((int (*)())FUN_00054da0)(param_2,uVar1);
    }
  }
LAB_00055088:
  param_5[1] = iVar5;
  *param_5 = 2;
LAB_000550a0:
  uVar6 = param_4[1];
  uVar7 = param_4[2];
  uVar3 = param_4[3];
  param_5[2] = *param_4;
  param_5[3] = uVar6;
  param_5[4] = uVar7;
  param_5[5] = uVar3;
  return 1;
}

/* FUN_000550e0 @ 0x550e0 (244 bytes) */
int FUN_000550e0(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (*param_2 == 1) {
    uVar1 = param_2[1];
    if (uVar1 < 0x6111) {
      if (0x610e < uVar1) {
        return 0x87bf;
      }
      if (uVar1 == 0x610e) {
        return 0x87be;
      }
    }
    else if (0x8799 < uVar1) {
      if (uVar1 < 0x87a5) {
        return 0x87bf;
      }
      if (uVar1 == 0x87bd) {
        return 0x87be;
      }
    }
  }
  else if (*param_2 == 2) {
    iVar3 = param_2[1] * 0x54 + *(int *)(param_1 + 4);
    uVar1 = *(uint *)(iVar3 + 0x28);
    if ((0x87c0 < uVar1) && ((uVar1 < 0x87c5 || (uVar1 == 0xffffffff)))) {
      iVar2 = *(int *)(iVar3 + 0x24);
      if (iVar2 != 0x87bf) {
        if (iVar2 == 0x87c0) {
          return 0x87c0;
        }
        if (iVar2 != 0x87be) {
          return 0;
        }
        if (*(char *)(iVar3 + 0x44) == '\0') {
          return 0x87be;
        }
        if (*(int *)(iVar3 + 0x48) != 0xf) {
          return 0x87be;
        }
      }
      return 0x87bf;
    }
  }
  return 0;
}

/* FUN_000551f0 @ 0x551f0 (244 bytes) */
int FUN_000551f0(param_1, param_2)
  int param_1;
  uint *param_2;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = param_2[1];
  if (uVar2 != 0) {
    uVar3 = *param_2;
    uVar4 = 0;
    if (uVar3 != 0) {
      do {
        iVar1 = uVar4 * 0x54 + uVar2;
        if ((*(int *)(iVar1 + 0x38) != 0) && (*(char *)(iVar1 + 0x3c) != '\0')) {
          (**(code **)(param_1 + 0x18))();
          *(undefined4 *)(uVar4 * 0x54 + param_2[1] + 0x38) = 0;
          uVar2 = param_2[1];
          uVar3 = *param_2;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar3);
    }
    (**(code **)(param_1 + 0x18))(uVar2);
    *param_2 = 0;
    param_2[1] = 0;
    (**(code **)(param_1 + 0x18))(param_2[2]);
    param_2[3] = 0;
    param_2[2] = 0;
  }
  return;
}

/* FUN_00055300 @ 0x55300 (184 bytes) */
int FUN_00055300(param_1, param_2)
  int param_1;
  int *param_2;
{
  (**(code **)(((unsigned char *)0x000011ac) + param_1))(param_1,param_2,1);
  if (*param_2 != 0) {
    (**(code **)(param_1 + 0x18))();
    *param_2 = 0;
  }
  if (param_2[1] != 0) {
    (**(code **)(param_1 + 0x18))();
    param_2[1] = 0;
  }
  if (param_2[6] != 0) {
    (**(code **)(param_1 + 0x18))();
    param_2[6] = 0;
    param_2[5] = 0;
  }
  ((int (*)())FUN_000551f0)(param_1,param_2 + 7);
  return;
}

/* FUN_000553c0 @ 0x553c0 (556 bytes) */
int FUN_000553c0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  undefined4 *param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  undefined4 in_stack_00000040;
  
  uVar2 = *(uint *)(param_2 + 0x14);
  if ((uVar2 & 0x3f) == 0) {
    iVar3 = (**(code **)(param_1 + 0xc))(uVar2 * 0x74 + 0x1d00);
    if (iVar3 == 0) {
      return 0;
    }
    if (*(int *)(param_2 + 0x18) != 0) {
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (iVar3,*(int *)(param_2 + 0x18),*(int *)(param_2 + 0x14) * 0x74);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0x18));
    }
    *(int *)(param_2 + 0x18) = iVar3;
    uVar2 = *(uint *)(param_2 + 0x14);
  }
  iVar3 = uVar2 * 0x74 + *(int *)(param_2 + 0x18);
  if (0x20 < param_3 - 0x8782U) {
    return 0;
  }
  *(int *)(uVar2 * 0x74 + *(int *)(param_2 + 0x18)) = param_3;
  if (param_4 < 0x879d) {
    if ((param_4 < 0x879a) && (2 < param_4 - 0x610e)) {
LAB_00055500:
      iVar5 = ((int (*)())FUN_00054da0)(param_2 + 0x1c,param_4);
      if (iVar5 == 0) {
        return 0;
      }
      iVar4 = *(int *)(iVar5 * 0x54 + *(int *)(param_2 + 0x20) + 0x28);
      if ((iVar4 != 0x87c4) && (iVar4 != -1)) {
        return 0;
      }
      *(int *)(iVar3 + 8) = iVar5;
      *(undefined4 *)(iVar3 + 4) = 2;
      goto LAB_00055550;
    }
  }
  else if (param_4 < 0x87a5) {
    if ((int)(uint)(byte)((unsigned char *)0x000013b0)[param_1] <= (int)(param_4 - 0x879d)) {
      return 0;
    }
  }
  else if (param_4 != 0x87bd) goto LAB_00055500;
  *(uint *)(iVar3 + 8) = param_4;
  *(undefined4 *)(iVar3 + 4) = 1;
LAB_00055550:
  uVar1 = *param_5;
  uVar6 = param_5[1];
  uVar7 = param_5[2];
  *(undefined4 *)(iVar3 + 0x18) = param_5[3];
  *(undefined4 *)(iVar3 + 0xc) = uVar1;
  *(undefined4 *)(iVar3 + 0x10) = uVar6;
  *(undefined4 *)(iVar3 + 0x14) = uVar7;
  iVar5 = ((int (*)())FUN_00054f50)(param_1,param_2,param_6,param_7,iVar3 + 0x20);
  if (((iVar5 != 0) &&
      (iVar5 = ((int (*)())FUN_00054f50)(param_1,param_2,param_8,in_stack_00000038,iVar3 + 0x3c), iVar5 != 0)) &&
     (iVar3 = ((int (*)())FUN_00054f50)(param_1,param_2,in_stack_0000003c,in_stack_00000040,iVar3 + 0x58),
     iVar3 != 0)) {
    *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + 1;
    return 1;
  }
  return 0;
}

/* FUN_00055610 @ 0x55610 (1008 bytes) */
int FUN_00055610(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint *param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  int param_6;
  uint param_7;
  int param_8;
{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = *(int *)(((unsigned char *)0x0000116c) + param_1);
  if (*(int *)(iVar5 + 0x24) < 0) {
LAB_00055a00:
    uVar3 = 0;
  }
  else {
    uVar4 = *param_2;
    if ((uVar4 & 0x3f) == 0) {
      uVar4 = (**(code **)(param_1 + 0xc))(((unsigned char *)0x00001500) + uVar4 * 0x54);
      if (uVar4 == 0) goto LAB_00055a00;
      if (param_2[1] != 0) {
        (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar4,param_2[1],*param_2 * 0x54);
        (**(code **)(param_1 + 0x18))(param_2[1]);
      }
      param_2[1] = uVar4;
      uVar4 = *param_2;
    }
    if (param_4 == -4) {
      *(undefined4 *)(param_2[1] + uVar4 * 0x54 + 0x28) = 0x87c1;
      *(undefined1 *)(uVar4 * 0x54 + param_2[1] + 0x3c) = 0;
    }
    else if (param_4 == -3) {
      iVar6 = uVar4 * 0x54;
      *(undefined4 *)(param_2[1] + iVar6 + 0x28) = 0x87c2;
      *(int *)(iVar6 + param_2[1] + 0x38) =
           param_8 * 0x10 + *(int *)(((unsigned char *)0x00004308) + *(int *)(*(int *)(param_1 + 4) + 0x10));
      *(undefined1 *)(iVar6 + param_2[1] + 0x3c) = 0;
    }
    else if (param_4 == -2) {
      iVar6 = uVar4 * 0x54;
      *(undefined4 *)(param_2[1] + iVar6 + 0x28) = 0x87c2;
      *(int *)(iVar6 + param_2[1] + 0x38) =
           param_8 * 0x10 +
           *(int *)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 0x18) + 0x18c) + 0x18);
      *(undefined1 *)(iVar6 + param_2[1] + 0x3c) = 0;
    }
    else {
      iVar6 = uVar4 * 0x54;
      *(int *)(param_2[1] + iVar6 + 0x28) = param_4;
      if (param_3 == 0x87bf) {
        uVar3 = 0x10;
      }
      else if (param_3 == 0x87c0) {
        uVar3 = 0x40;
      }
      else {
        if (param_3 != 0x87be) {
          *(undefined4 *)(iVar6 + param_2[1] + 0x38) = 0;
          *(undefined1 *)(iVar6 + param_2[1] + 0x3c) = 0;
          goto LAB_00055870;
        }
        uVar3 = 4;
      }
      uVar2 = param_2[1];
      uVar3 = (**(code **)(param_1 + 0xc))(uVar3);
      *(undefined4 *)(iVar6 + uVar2 + 0x38) = uVar3;
      *(undefined1 *)(iVar6 + param_2[1] + 0x3c) = 1;
    }
LAB_00055870:
    iVar6 = uVar4 * 0x54;
    *(undefined4 *)(param_2[1] + iVar6 + 0x20) = *(undefined4 *)(iVar5 + 0x24);
    *(int *)(param_2[1] + iVar6 + 0x24) = param_3;
    *(undefined4 *)(param_2[1] + iVar6 + 0x2c) = param_5;
    if ((param_6 != 0) || (1 < param_7)) {
      iVar1 = iVar6 + param_2[1];
      if (param_6 == 0) {
        param_6 = *(int *)(iVar1 + 0x20);
      }
    }
    else {
      iVar1 = param_2[1] + iVar6;
    }
    *(int *)(iVar1 + 0x30) = param_6;
    *(uint *)(param_2[1] + iVar6 + 0x34) = param_7;
    *(undefined1 *)(param_2[1] + iVar6 + 0x3d) = 0;
    *(undefined4 *)(param_2[1] + iVar6 + 0x40) = 0xffffffff;
    *(undefined1 *)(param_2[1] + iVar6 + 0x44) = 0;
    uVar2 = *(uint *)(iVar5 + 0x24);
    if (param_2[3] <= uVar2) {
      uVar2 = (**(code **)(param_1 + 0x10))(uVar2 + 0x40,4);
      if (uVar2 == 0) goto LAB_00055a00;
      if (param_2[2] != 0) {
        (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar2,param_2[2],param_2[3] << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar2;
      param_2[3] = *(int *)(iVar5 + 0x24) + 0x40;
      uVar2 = *(uint *)(iVar5 + 0x24);
    }
    *(uint *)(uVar2 * 4 + param_2[2]) = uVar4;
    *param_2 = *param_2 + 1;
    iVar1 = *(int *)(iVar5 + 0x24) + 1;
    *(int *)(iVar5 + 0x24) = iVar1;
    if (iVar1 == 0x610e) {
      *(undefined4 *)(iVar5 + 0x24) = 0x6111;
    }
    else if (iVar1 == 0x879a) {
      *(undefined4 *)(iVar5 + 0x24) = 0x87be;
    }
    uVar3 = *(undefined4 *)(param_2[1] + iVar6 + 0x20);
  }
  return uVar3;
}

/* FUN_00055a30 @ 0x55a30 (48 bytes) */
int FUN_00055a30(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 < *(uint *)(param_1 + 0xc)) {
    iVar1 = *(int *)(param_2 * 4 + *(int *)(param_1 + 8)) * 0x54 + *(int *)(param_1 + 4);
  }
  return iVar1;
}

/* FUN_00055a60 @ 0x55a60 (220 bytes) */
int FUN_00055a60(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  iVar2 = *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x24);
  if (iVar2 == 0) {
    uVar1 = ((int (*)())FUN_00055610)(param_1,param_2,0x87c0,0x87c2,0x87e1,0,0,0);
    iVar2 = ((int (*)())FUN_00055a30)(param_2,uVar1);
    *(undefined4 *)(iVar2 + 0x4c) = 0;
    *(undefined1 *)(iVar2 + 0x44) = 1;
    *(undefined4 *)(iVar2 + 0x48) = 0x87e3;
    *(undefined4 *)(iVar2 + 0x50) = 0x80;
  }
  else {
    *(undefined4 *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x24) = 0;
    ((int (*)())FUN_00055610)(param_1,param_2,0x87be,0x87c1,0x87e1,0,0,0);
    *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x24) = iVar2;
  }
  return;
}

/* FUN_00055b50 @ 0x55b50 (428 bytes) */
int FUN_00055b50(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = (**(code **)(param_1 + 0x10))(*(undefined4 *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x10),4)
  ;
  *param_2 = uVar2;
  (**(code **)(((unsigned char *)0x000011a4) + param_1))(param_1,param_2,0xffffffff);
  uVar2 = (**(code **)(param_1 + 0x10))(*(undefined4 *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x10),1)
  ;
  param_2[1] = uVar2;
  if (0 < *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x10)) {
    iVar3 = 0;
    do {
      *(undefined1 *)(param_2[1] + iVar3) = 0;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x10));
  }
  *(undefined1 *)(param_2 + 4) = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  ((int (*)())FUN_00055a60)(param_1,param_2 + 7);
  param_2[0xc] = 0;
  param_2[0xb] = 0;
  if (((unsigned char *)0x000013b0)[param_1] != '\0') {
    iVar3 = 0;
    puVar1 = param_2;
    do {
      *(undefined1 *)(puVar1 + 0xd) = 0;
      *(undefined1 *)(puVar1 + 0x11) = 1;
      iVar3 = iVar3 + 1;
      puVar1 = (undefined4 *)((int)puVar1 + 1);
    } while (iVar3 < (int)(uint)(byte)((unsigned char *)0x000013b0)[param_1]);
  }
  iVar3 = 4;
  *(undefined1 *)(param_2 + 0x1b) = 0;
  param_2[0x15] = 0;
  param_2[0x16] = 0;
  param_2[0x17] = 0;
  param_2[0x18] = 0;
  param_2[0x19] = 0;
  param_2[0x1a] = 0;
  puVar1 = param_2;
  do {
    *(undefined1 *)((int)puVar1 + 0x6d) = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = 8;
  puVar1 = param_2;
  do {
    *(undefined1 *)((int)puVar1 + 0x71) = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined1 *)((int)param_2 + 0x7b) = 0;
  *(undefined1 *)((int)param_2 + 0x79) = 0;
  *(undefined1 *)((int)param_2 + 0x7a) = 0;
  return;
}

/* FUN_00055d00 @ 0x55d00 (148 bytes) */
int FUN_00055d00(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  
  iVar4 = *(int *)(((unsigned char *)0x0000112c) + param_1);
  uVar3 = *(uint *)(iVar4 + 4);
  if (uVar3 != 0) {
    uVar5 = 0;
    iVar7 = 0;
    do {
      iVar2 = iVar7 + *(int *)(iVar4 + 8);
      if (*(int *)(iVar2 + 4) == 0x8620) {
        puVar6 = *(undefined4 **)(iVar2 + 0x14);
        uVar1 = FUN_00053b00(param_1,*puVar6);
        puVar6[0x2a] = uVar1;
        uVar3 = *(uint *)(iVar4 + 4);
      }
      uVar5 = uVar5 + 1;
      iVar7 = iVar7 + 0x18;
    } while (uVar5 < uVar3);
  }
  return;
}

/* FUN_00055da0 @ 0x55da0 (1756 bytes) */
int FUN_00055da0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  
  if (*(int *)(param_4 + 0x28) == 0x87c2) {
    *(int *)(param_2 + 0x5c) = *(int *)(param_2 + 0x5c) + 1;
    if (*(char *)(param_4 + 0x44) == '\0') {
      *(int *)(param_3 + 0x224) = *(int *)(param_3 + 0x224) + 1;
    }
    else {
      *(int *)(param_3 + 0x22c) = *(int *)(param_3 + 0x22c) + 1;
    }
    iVar4 = *(int *)(param_4 + 0x24);
    *(undefined1 *)(param_4 + 0x3d) = 1;
    if (iVar4 == 0x87bf) {
      uVar6 = 0;
      uVar7 = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x5c) = *(int *)(param_3 + 0x5c) + 1;
      while (uVar7 < *(uint *)(param_3 + 0x58)) {
        if (!bVar1) goto LAB_00055f2c;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x54) + 0x10) == '\0') {
          uVar6 = 1;
          bVar1 = false;
        }
        else {
          uVar7 = uVar7 + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
      goto LAB_00055f28;
    }
    if (iVar4 == 0x87c0) {
      uVar7 = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x5c) = *(int *)(param_3 + 0x5c) + 4;
      while (uVar7 < *(int *)(param_3 + 0x58) - 3U) {
        if (!bVar1) goto LAB_00055fac;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x54) + 0x10) == '\0') {
          bVar1 = false;
        }
        else {
          uVar7 = uVar7 + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
      if (!bVar1) {
LAB_00055fac:
        iVar8 = uVar7 * 0x28;
        iVar4 = iVar8 + *(int *)(param_3 + 0x54);
        if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
           (*(char *)(iVar4 + 0x88) == '\0')) {
          iVar4 = 0;
          iVar10 = 4;
          do {
            iVar2 = uVar7 + iVar4;
            iVar4 = iVar4 + 1;
            *(int *)(param_4 + 0x10) = iVar2;
            param_4 = param_4 + 4;
            iVar2 = *(int *)(param_3 + 0x54) + iVar8;
            iVar8 = iVar8 + 0x28;
            *(undefined1 *)(iVar2 + 0x10) = 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
          return;
        }
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar10 = *(int *)(param_3 + 0x58);
      uVar9 = (**(code **)(param_1 + 0x10))(iVar10 + 0x10,0x28);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar9,*(undefined4 *)(param_3 + 0x54),*(int *)(param_3 + 0x58) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x54));
      *(undefined4 *)(param_3 + 0x54) = uVar9;
      iVar4 = iVar10 * 0x28;
      iVar2 = 4;
      iVar8 = 0;
      *(int *)(param_3 + 0x58) = *(int *)(param_3 + 0x58) + 0x10;
      do {
        iVar3 = iVar10 + iVar8;
        iVar8 = iVar8 + 1;
        *(int *)(param_4 + 0x10) = iVar3;
        param_4 = param_4 + 4;
        iVar3 = *(int *)(param_3 + 0x54) + iVar4;
        iVar4 = iVar4 + 0x28;
        *(undefined1 *)(iVar3 + 0x10) = 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      return;
    }
    if (iVar4 != 0x87be) {
      return;
    }
    uVar9 = 0;
    uVar7 = 0;
    iVar4 = 0;
    bVar1 = true;
    *(int *)(param_3 + 0x5c) = *(int *)(param_3 + 0x5c) + 1;
    while (uVar7 < *(uint *)(param_3 + 0x58)) {
      if (!bVar1) goto LAB_0005618c;
      if (*(char *)(iVar4 + *(int *)(param_3 + 0x54) + 0x10) == '\0') {
        uVar9 = 1;
        bVar1 = false;
      }
      else {
        uVar7 = uVar7 + 1;
        iVar4 = iVar4 + 0x28;
      }
    }
  }
  else {
    if (*(int *)(param_4 + 0x28) != 0x87c3) {
      return;
    }
    *(int *)(param_2 + 0x60) = *(int *)(param_2 + 0x60) + 1;
    *(undefined1 *)(param_4 + 0x3d) = 1;
    iVar4 = *(int *)(param_4 + 0x24);
    if (iVar4 == 0x87bf) {
      uVar6 = 0;
      uVar7 = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x5c) = *(int *)(param_3 + 0x5c) + 1;
      while (uVar7 < *(uint *)(param_3 + 0x58)) {
        if (!bVar1) goto LAB_00055f2c;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x54) + 0x10) == '\0') {
          uVar6 = 1;
          bVar1 = false;
        }
        else {
          uVar7 = uVar7 + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
LAB_00055f28:
      if (bVar1) {
        *(undefined1 *)(param_2 + 0x10) = uVar6;
        iVar4 = *(int *)(param_3 + 0x58);
        uVar9 = (**(code **)(param_1 + 0x10))(iVar4 + 0x10,0x28);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar9,*(undefined4 *)(param_3 + 0x54),*(int *)(param_3 + 0x58) * 0x28);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x54));
        *(undefined4 *)(param_3 + 0x54) = uVar9;
        *(int *)(param_3 + 0x58) = *(int *)(param_3 + 0x58) + 0x10;
        goto LAB_000562e8;
      }
LAB_00055f2c:
      *(uint *)(param_4 + 4) = uVar7;
      goto LAB_00055f30;
    }
    if (iVar4 == 0x87c0) {
      uVar7 = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x5c) = *(int *)(param_3 + 0x5c) + 4;
      while (uVar7 < *(int *)(param_3 + 0x58) - 3U) {
        if (!bVar1) goto LAB_0005636c;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x54) + 0x10) == '\0') {
          bVar1 = false;
        }
        else {
          uVar7 = uVar7 + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
      if (!bVar1) {
LAB_0005636c:
        iVar8 = uVar7 * 0x28;
        iVar4 = iVar8 + *(int *)(param_3 + 0x54);
        if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
           (*(char *)(iVar4 + 0x88) == '\0')) {
          iVar4 = 0;
          iVar10 = 4;
          do {
            iVar2 = uVar7 + iVar4;
            iVar4 = iVar4 + 1;
            *(int *)(param_4 + 0x10) = iVar2;
            param_4 = param_4 + 4;
            iVar2 = *(int *)(param_3 + 0x54) + iVar8;
            iVar8 = iVar8 + 0x28;
            *(undefined1 *)(iVar2 + 0x10) = 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
          return;
        }
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar10 = *(int *)(param_3 + 0x58);
      uVar9 = (**(code **)(param_1 + 0x10))(iVar10 + 0x10,0x28);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar9,*(undefined4 *)(param_3 + 0x54),*(int *)(param_3 + 0x58) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x54));
      *(undefined4 *)(param_3 + 0x54) = uVar9;
      iVar4 = iVar10 * 0x28;
      iVar2 = 4;
      iVar8 = 0;
      *(int *)(param_3 + 0x58) = *(int *)(param_3 + 0x58) + 0x10;
      do {
        iVar3 = iVar10 + iVar8;
        iVar8 = iVar8 + 1;
        *(int *)(param_4 + 0x10) = iVar3;
        param_4 = param_4 + 4;
        iVar3 = *(int *)(param_3 + 0x54) + iVar4;
        iVar4 = iVar4 + 0x28;
        *(undefined1 *)(iVar3 + 0x10) = 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      return;
    }
    if (iVar4 != 0x87be) {
      return;
    }
    uVar9 = 0;
    uVar7 = 0;
    iVar4 = 0;
    bVar1 = true;
    *(int *)(param_3 + 0x5c) = *(int *)(param_3 + 0x5c) + 1;
    while (uVar7 < *(uint *)(param_3 + 0x58)) {
      if (!bVar1) goto LAB_0005618c;
      if (*(char *)(iVar4 + *(int *)(param_3 + 0x54) + 0x10) == '\0') {
        uVar9 = 1;
        bVar1 = false;
      }
      else {
        uVar7 = uVar7 + 1;
        iVar4 = iVar4 + 0x28;
      }
    }
  }
  if (bVar1) {
    *(char *)(param_2 + 0x10) = (char)uVar9;
    iVar4 = *(int *)(param_3 + 0x58);
    uVar5 = (**(code **)(param_1 + 0x10))(iVar4 + 0x10,0x28);
    (**(code **)(((unsigned char *)0x00001344) + param_1))
              (uVar5,*(undefined4 *)(param_3 + 0x54),*(int *)(param_3 + 0x58) * 0x28);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x54));
    *(undefined4 *)(param_3 + 0x54) = uVar5;
    *(int *)(param_3 + 0x58) = *(int *)(param_3 + 0x58) + 0x10;
    *(undefined4 *)(param_4 + 8) = uVar9;
LAB_000562e8:
    *(int *)(param_4 + 4) = iVar4;
    *(undefined1 *)(iVar4 * 0x28 + *(int *)(param_3 + 0x54) + 0x10) = 1;
    return;
  }
LAB_0005618c:
  *(uint *)(param_4 + 4) = uVar7;
  *(undefined4 *)(param_4 + 8) = 0;
LAB_00055f30:
  *(undefined1 *)(uVar7 * 0x28 + *(int *)(param_3 + 0x54) + 0x10) = 1;
  return;
}

/* FUN_000564c0 @ 0x564c0 (1668 bytes) */
int FUN_000564c0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  if (*param_4 != 2) {
    return;
  }
  iVar10 = param_4[1];
  iVar11 = iVar10 * 0x54 + *(int *)(param_2 + 0x20);
  if (*(int *)(iVar11 + 0x28) != 0x87c4) {
    return;
  }
  bVar1 = *(char *)(iVar11 + 0x3d) == '\0';
  if (!bVar1) {
    return;
  }
  *(undefined1 *)(iVar11 + 0x3d) = 1;
  *(int *)(param_2 + 100) = *(int *)(param_2 + 100) + 1;
  iVar7 = *(int *)(iVar10 * 0x54 + *(int *)(param_2 + 0x20) + 0x24);
  if (iVar7 == 0x87bf) {
    uVar9 = 0;
    uVar6 = 0;
    while (uVar9 < *(uint *)(param_3 + 0x50)) {
      if (!bVar1) goto LAB_000567d8;
      if (*(char *)(uVar9 * 0x28 + *(int *)(param_3 + 0x4c) + 0x10) == '\0') {
        uVar6 = 1;
        bVar1 = false;
      }
      else {
        uVar9 = uVar9 + 1;
      }
    }
    if (bVar1) {
      *(undefined1 *)(param_2 + 0x10) = uVar6;
      uVar9 = *(uint *)(param_3 + 0x50);
      uVar4 = (**(code **)(param_1 + 0x10))(uVar9 + 0x10,0x28);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar4,*(undefined4 *)(param_3 + 0x4c),*(int *)(param_3 + 0x50) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x4c));
      *(undefined4 *)(param_3 + 0x4c) = uVar4;
      iVar7 = uVar9 * 0x28;
      *(int *)(param_3 + 0x50) = *(int *)(param_3 + 0x50) + 0x10;
      *(uint *)(iVar11 + 4) = uVar9;
      *(undefined1 *)(*(int *)(param_3 + 0x4c) + iVar7 + 0x10) = 1;
      *(undefined4 *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x14) = 4;
      *(int *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x18) = iVar10;
      *(int *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x1c) = iVar10;
      *(int *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x20) = iVar10;
      *(int *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x24) = iVar10;
      if (uVar9 < *(uint *)(param_3 + 0x2ac)) {
        return;
      }
LAB_00056918:
      *(uint *)(param_3 + 0x2ac) = uVar9 + 1;
      return;
    }
LAB_000567d8:
    *(uint *)(iVar11 + 4) = uVar9;
    iVar11 = uVar9 * 0x28;
    *(undefined1 *)(*(int *)(param_3 + 0x4c) + iVar11 + 0x10) = 1;
    *(undefined4 *)(iVar11 + *(int *)(param_3 + 0x4c) + 0x14) = 4;
    *(int *)(iVar11 + *(int *)(param_3 + 0x4c) + 0x18) = iVar10;
    *(int *)(iVar11 + *(int *)(param_3 + 0x4c) + 0x1c) = iVar10;
    *(int *)(iVar11 + *(int *)(param_3 + 0x4c) + 0x20) = iVar10;
    *(int *)(iVar11 + *(int *)(param_3 + 0x4c) + 0x24) = iVar10;
    if (uVar9 < *(uint *)(param_3 + 0x2ac)) {
      return;
    }
  }
  else {
    if (iVar7 == 0x87c0) {
      uVar9 = 0;
      while (uVar9 < *(int *)(param_3 + 0x50) - 3U) {
        if (!bVar1) goto LAB_00056978;
        if (*(char *)(uVar9 * 0x28 + *(int *)(param_3 + 0x4c) + 0x10) == '\0') {
          bVar1 = false;
        }
        else {
          uVar9 = uVar9 + 1;
        }
      }
      if (!bVar1) {
LAB_00056978:
        iVar7 = uVar9 * 0x28;
        iVar8 = iVar7 + *(int *)(param_3 + 0x4c);
        if (((*(char *)(iVar8 + 0x38) == '\0') && (*(char *)(iVar8 + 0x60) == '\0')) &&
           (*(char *)(iVar8 + 0x88) == '\0')) {
          iVar8 = 0;
          iVar12 = 4;
          do {
            iVar2 = uVar9 + iVar8;
            iVar8 = iVar8 + 1;
            *(int *)(iVar11 + 0x10) = iVar2;
            iVar11 = iVar11 + 4;
            *(undefined1 *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x10) = 1;
            *(undefined4 *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x14) = 4;
            *(int *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x18) = iVar10;
            *(int *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x1c) = iVar10;
            *(int *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x20) = iVar10;
            iVar2 = iVar7 + *(int *)(param_3 + 0x4c);
            iVar7 = iVar7 + 0x28;
            *(int *)(iVar2 + 0x24) = iVar10;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
          if (uVar9 + 3 < *(uint *)(param_3 + 0x2ac)) {
            return;
          }
          *(uint *)(param_3 + 0x2ac) = uVar9 + 4;
          return;
        }
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar12 = *(int *)(param_3 + 0x50);
      uVar4 = (**(code **)(param_1 + 0x10))(iVar12 + 0x10,0x28);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar4,*(undefined4 *)(param_3 + 0x4c),*(int *)(param_3 + 0x50) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x4c));
      *(undefined4 *)(param_3 + 0x4c) = uVar4;
      iVar8 = iVar12 * 0x28;
      iVar2 = 4;
      iVar7 = 0;
      *(int *)(param_3 + 0x50) = *(int *)(param_3 + 0x50) + 0x10;
      do {
        iVar3 = iVar12 + iVar7;
        iVar7 = iVar7 + 1;
        *(int *)(iVar11 + 0x10) = iVar3;
        iVar11 = iVar11 + 4;
        *(undefined1 *)(*(int *)(param_3 + 0x4c) + iVar8 + 0x10) = 1;
        *(undefined4 *)(*(int *)(param_3 + 0x4c) + iVar8 + 0x14) = 4;
        *(int *)(*(int *)(param_3 + 0x4c) + iVar8 + 0x18) = iVar10;
        *(int *)(*(int *)(param_3 + 0x4c) + iVar8 + 0x1c) = iVar10;
        *(int *)(*(int *)(param_3 + 0x4c) + iVar8 + 0x20) = iVar10;
        iVar3 = *(int *)(param_3 + 0x4c) + iVar8;
        iVar8 = iVar8 + 0x28;
        *(int *)(iVar3 + 0x24) = iVar10;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      if (iVar12 + 3U < *(uint *)(param_3 + 0x2ac)) {
        return;
      }
      *(int *)(param_3 + 0x2ac) = iVar12 + 4;
      return;
    }
    if (iVar7 != 0x87be) {
      return;
    }
    uVar5 = *(uint *)(param_3 + 0x50);
    uVar9 = 0;
    bVar1 = false;
    iVar7 = 0;
    while (uVar9 < uVar5) {
      if (bVar1) goto LAB_000565ec;
      iVar8 = iVar7 + *(int *)(param_3 + 0x4c);
      if ((*(char *)(iVar8 + 0x10) == '\0') || (bVar1 = true, 3 < *(uint *)(iVar8 + 0x14))) {
        uVar9 = uVar9 + 1;
        iVar7 = iVar7 + 0x28;
        bVar1 = false;
      }
    }
    if (bVar1) {
LAB_000565ec:
      *(uint *)(iVar11 + 4) = uVar9;
      iVar7 = uVar9 * 0x28;
      *(undefined4 *)(iVar11 + 8) = *(undefined4 *)(*(int *)(param_3 + 0x4c) + iVar7 + 0x14);
      iVar11 = iVar7 + *(int *)(param_3 + 0x4c);
      *(int *)(*(int *)(iVar11 + 0x14) * 4 + iVar11 + 0x18) = iVar10;
      iVar7 = iVar7 + *(int *)(param_3 + 0x4c);
      *(int *)(iVar7 + 0x14) = *(int *)(iVar7 + 0x14) + 1;
      if (uVar9 < *(uint *)(param_3 + 0x2ac)) {
        return;
      }
    }
    else {
      if (uVar5 == 0) {
LAB_000566c8:
        *(undefined1 *)(param_2 + 0x10) = 0;
        uVar9 = *(uint *)(param_3 + 0x50);
        uVar4 = (**(code **)(param_1 + 0x10))(uVar9 + 0x10,0x28);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar4,*(undefined4 *)(param_3 + 0x4c),*(int *)(param_3 + 0x50) * 0x28);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x4c));
        *(undefined4 *)(param_3 + 0x4c) = uVar4;
        iVar7 = uVar9 * 0x28;
        *(int *)(param_3 + 0x50) = *(int *)(param_3 + 0x50) + 0x10;
        *(undefined4 *)(iVar11 + 8) = 0;
        *(uint *)(iVar11 + 4) = uVar9;
        *(undefined1 *)(*(int *)(param_3 + 0x4c) + iVar7 + 0x10) = 1;
        *(undefined4 *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x14) = 1;
        *(int *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x18) = iVar10;
        if (uVar9 < *(uint *)(param_3 + 0x2ac)) {
          return;
        }
        goto LAB_00056918;
      }
      uVar9 = 0;
      do {
        bVar1 = *(char *)(uVar9 * 0x28 + *(int *)(param_3 + 0x4c) + 0x10) != '\0';
        if (bVar1) {
          uVar9 = uVar9 + 1;
        }
        if (uVar5 <= uVar9) {
          if (bVar1) goto LAB_000566c8;
          break;
        }
      } while (bVar1);
      *(uint *)(iVar11 + 4) = uVar9;
      iVar7 = uVar9 * 0x28;
      *(undefined4 *)(iVar11 + 8) = 0;
      *(undefined1 *)(*(int *)(param_3 + 0x4c) + iVar7 + 0x10) = 1;
      *(undefined4 *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x14) = 1;
      *(int *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x18) = iVar10;
      if (uVar9 < *(uint *)(param_3 + 0x2ac)) {
        return;
      }
    }
  }
  *(uint *)(param_3 + 0x2ac) = uVar9 + 1;
  return;
}

/* FUN_00056b80 @ 0x56b80 (80 bytes) */
int FUN_00056b80(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  if ((*param_1 == 2) &&
     ((((iVar1 = param_1[1], iVar1 == *(int *)(param_2 + 0x18) ||
        (iVar1 == *(int *)(param_2 + 0x1c))) || (iVar1 == *(int *)(param_2 + 0x20))) ||
      (iVar1 == *(int *)(param_2 + 0x24))))) {
    return 1;
  }
  return 0;
}

/* FUN_00056be0 @ 0x56be0 (816 bytes) */
int FUN_00056be0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  bool bVar21;
  
  iVar17 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  uVar14 = *(uint *)(iVar17 + 0x50);
  if (uVar14 != 0) {
    uVar15 = param_3 + 1;
    uVar12 = 0;
    iVar16 = 0;
    do {
      iVar19 = iVar16 + *(int *)(iVar17 + 0x4c);
      if (*(char *)(iVar19 + 0x10) != '\0') {
        iVar13 = *(int *)(iVar19 + 0x18);
        if (((((iVar13 != 0) || (*(int *)(iVar19 + 0x1c) != 0)) || (*(int *)(iVar19 + 0x20) != 0))
            || (*(int *)(iVar19 + 0x24) != 0)) && (uVar7 = param_2[5], uVar15 < uVar7)) {
          bVar8 = 0;
          bVar9 = 0;
          bVar10 = 0;
          iVar20 = uVar15 * 0x74 + param_2[6];
          bVar11 = 0;
          bVar5 = true;
          uVar18 = uVar15;
          do {
            iVar6 = ((int (*)())FUN_00056b80)(iVar20 + 0x20,iVar19);
            if (((iVar6 == 0) && (iVar6 = ((int (*)())FUN_00056b80)(iVar20 + 0x3c,iVar19), iVar6 == 0)) &&
               (iVar6 = ((int (*)())FUN_00056b80)(iVar20 + 0x58,iVar19), iVar6 == 0)) {
              iVar6 = ((int (*)())FUN_00056b80)(iVar20 + 4,iVar19);
              if (iVar6 != 0) {
                iVar6 = *(int *)(iVar20 + 8);
                if (*(int *)(iVar6 * 0x54 + param_2[8] + 0x24) == 0x87be) {
                  bVar1 = iVar13 == iVar6;
                  bVar2 = iVar6 == *(int *)(iVar19 + 0x1c);
                  bVar3 = iVar6 == *(int *)(iVar19 + 0x20);
                  bVar4 = iVar6 == *(int *)(iVar19 + 0x24);
                }
                else {
                  bVar1 = *(byte *)(iVar20 + 0xf);
                  bVar2 = *(byte *)(iVar20 + 0x13);
                  bVar3 = *(byte *)(iVar20 + 0x17);
                  bVar4 = *(byte *)(iVar20 + 0x1b);
                }
                bVar11 = bVar11 | bVar4;
                bVar10 = bVar10 | bVar3;
                bVar9 = bVar9 | bVar2;
                bVar8 = bVar8 | bVar1;
                if (((bVar8 != 0) && (bVar9 != 0)) && (bVar10 != 0)) {
                  bVar21 = bVar11 != 0;
                  goto LAB_00056e00;
                }
              }
              bVar21 = false;
            }
            else {
              bVar5 = false;
              bVar21 = true;
            }
LAB_00056e00:
            uVar18 = uVar18 + 1;
          } while ((uVar18 != uVar7) && (iVar20 = iVar20 + 0x74, !bVar21));
          if (!bVar5) goto LAB_00056ef0;
        }
        *(undefined1 *)(iVar13 * 0x54 + param_2[8] + 0x3d) = 0;
        *(undefined1 *)
         (*(int *)(iVar16 + *(int *)(iVar17 + 0x4c) + 0x1c) * 0x54 + param_2[8] + 0x3d) = 0;
        *(undefined1 *)
         (*(int *)(iVar16 + *(int *)(iVar17 + 0x4c) + 0x20) * 0x54 + param_2[8] + 0x3d) = 0;
        *(undefined1 *)
         (*(int *)(iVar16 + *(int *)(iVar17 + 0x4c) + 0x24) * 0x54 + param_2[8] + 0x3d) = 0;
        *(undefined1 *)(iVar16 + *(int *)(iVar17 + 0x4c) + 0x10) = 0;
        *(undefined4 *)(iVar16 + *(int *)(iVar17 + 0x4c) + 0x14) = 0;
        *(undefined4 *)(iVar16 + *(int *)(iVar17 + 0x4c) + 0x18) = 0;
        *(undefined4 *)(iVar16 + *(int *)(iVar17 + 0x4c) + 0x1c) = 0;
        *(undefined4 *)(iVar16 + *(int *)(iVar17 + 0x4c) + 0x20) = 0;
        *(undefined4 *)(iVar16 + *(int *)(iVar17 + 0x4c) + 0x24) = 0;
        param_2[0x19] = param_2[0x19] + -1;
        uVar14 = *(uint *)(iVar17 + 0x50);
      }
LAB_00056ef0:
      uVar12 = uVar12 + 1;
      iVar16 = iVar16 + 0x28;
    } while (uVar12 < uVar14);
  }
  return;
}

/* FUN_00056f20 @ 0x56f20 (988 bytes) */
int FUN_00056f20(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int *param_2;
  uint *param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  int param_7;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  uVar6 = *param_4;
  param_5 = param_5 & 0x3f;
  uVar1 = (param_6 & 1) << 6;
  iVar9 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  *param_4 = uVar1 | param_5 | uVar6 & 0xefffff00;
  uVar2 = (param_3[2] & 1) << 0x14;
  *param_4 = uVar2 | uVar1 | param_5 | uVar6 & 0xefefff00;
  uVar3 = (param_3[3] & 1) << 0x15;
  *param_4 = uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xefcfff00;
  uVar4 = (param_3[4] & 1) << 0x16;
  *param_4 = uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef8fff00;
  uVar5 = (param_3[5] & 1) << 0x17;
  *param_4 = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef0fff00;
  uVar7 = *param_3;
  if (uVar7 == 2) {
    iVar9 = param_3[1] * 0x54 + param_2[8];
    if (*(int *)(iVar9 + 0x28) == 0x87c4) {
      iVar8 = *(int *)(iVar9 + 0x24);
      if (iVar8 == 0x87bf) {
        *param_4 = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef0ff000;
        uVar7 = (*(uint *)(iVar9 + 4) & 0x7f) << 0xd |
                uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000;
        *param_4 = uVar7;
      }
      else if (iVar8 == 0x87c0) {
        *param_4 = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef0ff000;
        uVar7 = (*(uint *)(param_7 * 4 + iVar9 + 0x10) & 0x7f) << 0xd |
                uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000;
        *param_4 = uVar7;
      }
      else {
        if (iVar8 != 0x87be) {
          return 0;
        }
        *param_4 = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef0ff000;
        uVar7 = (*(uint *)(iVar9 + 4) & 0x7f) << 0xd;
        param_5 = param_5 | uVar6 & 0xef001000;
        *param_4 = uVar7 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5;
        iVar9 = *(int *)(iVar9 + 8);
        if (iVar9 == 1) {
          uVar7 = uVar7 | uVar3 | uVar1 | param_5;
          *param_4 = uVar7;
        }
        else if (iVar9 == 0) {
          uVar7 = uVar7 | uVar2 | uVar1 | param_5;
          *param_4 = uVar7;
        }
        else if (iVar9 == 2) {
          uVar7 = uVar7 | uVar4 | uVar1 | param_5;
          *param_4 = uVar7;
        }
        else {
          if (iVar9 != 3) {
            return 0;
          }
          uVar7 = uVar7 | uVar5 | uVar1 | param_5;
          *param_4 = uVar7;
        }
      }
    }
    else {
      if (*(int *)(iVar9 + 0x28) != -1) {
        return 0;
      }
      uVar7 = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x100;
      *param_4 = uVar7;
    }
  }
  else if (uVar7 < 3) {
    if (uVar7 != 1) {
      return 0;
    }
    *param_4 = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef0ff000 | 0x200;
    uVar7 = param_3[1];
    if (uVar7 == 0x879b) {
      uVar7 = (*(uint *)(iVar9 + 0x1ec) & 0x7f) << 0xd |
              uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x200;
      *param_4 = uVar7;
    }
    else if (uVar7 < 0x879c) {
      if (uVar7 == 0x610f) {
        if (*(char *)((int)param_2 + 0x6f) != '\0') {
          uVar7 = (*(uint *)(iVar9 + 500) & 0x7f) << 0xd |
                  uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x200;
          *param_4 = uVar7;
          goto LAB_00057320;
        }
      }
      else {
        if (uVar7 < 0x6110) {
          if (uVar7 != 0x610e) {
            return 0;
          }
          if (*(char *)((int)param_2 + 0x79) == '\0') {
            *param_4 = uVar5 | uVar4 | uVar3 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x200;
          }
          else {
            *param_4 = (*(uint *)(iVar9 + 0x1fc) & 0x7f) << 0xd |
                       uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x200;
          }
          uVar7 = *param_4 & 0xff1fffff;
          *param_4 = uVar7;
          goto LAB_00057320;
        }
        if (uVar7 != 0x6110) {
          if (uVar7 != 0x879a) {
            return 0;
          }
          uVar7 = (*(uint *)(iVar9 + 0x1e8) & 0x7f) << 0xd |
                  uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x200;
          *param_4 = uVar7;
          goto LAB_00057320;
        }
        if (*(char *)(param_2 + 0x1c) != '\0') {
          uVar7 = (*(uint *)(iVar9 + 0x1f8) & 0x7f) << 0xd |
                  uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x200;
          *param_4 = uVar7;
          goto LAB_00057320;
        }
      }
      uVar7 = uVar1 | param_5 | uVar6 & 0xef001000 | 0x200;
      *param_4 = uVar7;
    }
    else if (uVar7 < 0x87a5) {
      if (uVar7 < 0x879d) {
        uVar7 = (*(uint *)(iVar9 + 0x1f0) & 0x7f) << 0xd |
                uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x200;
        *param_4 = uVar7;
        if (*(char *)(iVar9 + 0x42) != '\0') {
          uVar7 = *param_4 & 0xff7fffff;
          *param_4 = uVar7;
        }
      }
      else {
        uVar7 = (*(uint *)(uVar7 * 4 + iVar9 + -0x21c74) & 0x7f) << 0xd |
                uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x200;
        *param_4 = uVar7;
      }
    }
    else {
      if (uVar7 != 0x87bd) {
        return 0;
      }
      *param_4 = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef0ff000 | 0x300;
      uVar2 = (*(uint *)(iVar9 + 0x1f0) & 0x7f) << 0xd;
      param_5 = param_5 | uVar6 & 0xef001000;
      *param_4 = uVar2 | uVar5 | uVar1 | param_5 | 0x300;
      uVar7 = (*(byte *)(iVar9 + 0x42) & 1) << 0x17 | uVar2 | uVar1 | param_5 | 0x300;
      *param_4 = uVar7;
    }
  }
  else if (uVar7 == 3) {
    *param_4 = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef0ff000;
    uVar7 = (param_3[1] & 0x7f) << 0xd |
            uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000;
    *param_4 = uVar7;
  }
  else {
    if (uVar7 != 5) {
      return 0;
    }
    *param_4 = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef0ff000 | 0x100;
    uVar7 = (param_3[1] & 0x7f) << 0xd |
            uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x100;
    *param_4 = uVar7;
  }
LAB_00057320:
  *param_4 = uVar7 & 0x1fffefff;
  return 1;
}

/* FUN_00057340 @ 0x57340 (1768 bytes) */
int FUN_00057340(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  uint *param_3;
  uint *param_4;
  int param_5;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  switch(param_3[2]) {
  case 0x87d5:
  case 0x87d9:
    uVar4 = *param_4 & 0xffff1fff;
    *param_4 = uVar4;
    break;
  case 0x87d6:
  case 0x87da:
    uVar4 = *param_4 & 0xffff1fff | 0x2000;
    *param_4 = uVar4;
    break;
  case 0x87d7:
  case 0x87db:
    uVar4 = *param_4 & 0xffff1fff | 0x4000;
    *param_4 = uVar4;
    break;
  case 0x87d8:
  case 0x87dc:
    uVar4 = *param_4 & 0xffff1fff | 0x6000;
    *param_4 = uVar4;
    break;
  case 0x87dd:
    uVar4 = *param_4 & 0xffff1fff | 0x8000;
    *param_4 = uVar4;
    break;
  case 0x87de:
  case 0x87df:
    uVar4 = *param_4 & 0xffff1fff | 0xa000;
    *param_4 = uVar4;
    break;
  default:
    goto LAB_00057ae0;
  }
  if (10 < param_3[2] - 0x87d5) {
LAB_00057ae0:
    return 0;
  }
  uVar5 = 1 << (param_3[2] - 0x87d5 & 0x3f);
  if ((uVar5 & 0x30f) == 0) {
    if ((uVar5 & 0x4f0) == 0) {
      return 0;
    }
    uVar4 = uVar4 | 0x2000000;
    *param_4 = uVar4;
  }
  else {
    uVar4 = uVar4 & 0xfdffffff;
    *param_4 = uVar4;
  }
  switch(param_3[3]) {
  case 0x87d5:
  case 0x87d9:
    uVar4 = uVar4 & 0xfff8ffff;
    *param_4 = uVar4;
    break;
  case 0x87d6:
  case 0x87da:
    uVar4 = uVar4 & 0xfff8ffff | 0x10000;
    *param_4 = uVar4;
    break;
  case 0x87d7:
  case 0x87db:
    uVar4 = uVar4 & 0xfff8ffff | 0x20000;
    *param_4 = uVar4;
    break;
  case 0x87d8:
  case 0x87dc:
    uVar4 = uVar4 & 0xfff8ffff | 0x30000;
    *param_4 = uVar4;
    break;
  case 0x87dd:
    uVar4 = uVar4 & 0xfff8ffff | 0x40000;
    *param_4 = uVar4;
    break;
  case 0x87de:
  case 0x87df:
    uVar4 = uVar4 & 0xfff8ffff | 0x50000;
    *param_4 = uVar4;
    break;
  default:
    return 0;
  }
  if (10 < param_3[3] - 0x87d5) {
    return 0;
  }
  uVar5 = 1 << (param_3[3] - 0x87d5 & 0x3f);
  if ((uVar5 & 0x30f) == 0) {
    if ((uVar5 & 0x4f0) == 0) {
      return 0;
    }
    uVar4 = uVar4 | 0x4000000;
    *param_4 = uVar4;
  }
  else {
    uVar4 = uVar4 & 0xfbffffff;
    *param_4 = uVar4;
  }
  switch(param_3[4]) {
  case 0x87d5:
  case 0x87d9:
    uVar4 = uVar4 & 0xffc7ffff;
    *param_4 = uVar4;
    break;
  case 0x87d6:
  case 0x87da:
    uVar4 = uVar4 & 0xffc7ffff | 0x80000;
    *param_4 = uVar4;
    break;
  case 0x87d7:
  case 0x87db:
    uVar4 = uVar4 & 0xffc7ffff | 0x100000;
    *param_4 = uVar4;
    break;
  case 0x87d8:
  case 0x87dc:
    uVar4 = uVar4 & 0xffc7ffff | 0x180000;
    *param_4 = uVar4;
    break;
  case 0x87dd:
    uVar4 = uVar4 & 0xffc7ffff | 0x200000;
    *param_4 = uVar4;
    break;
  case 0x87de:
  case 0x87df:
    uVar4 = uVar4 & 0xffc7ffff | 0x280000;
    *param_4 = uVar4;
    break;
  default:
    return 0;
  }
  if (10 < param_3[4] - 0x87d5) {
    return 0;
  }
  uVar5 = 1 << (param_3[4] - 0x87d5 & 0x3f);
  if ((uVar5 & 0x30f) == 0) {
    if ((uVar5 & 0x4f0) == 0) {
      return 0;
    }
    uVar4 = uVar4 | 0x8000000;
    *param_4 = uVar4;
  }
  else {
    uVar4 = uVar4 & 0xf7ffffff;
    *param_4 = uVar4;
  }
  switch(param_3[5]) {
  case 0x87d5:
  case 0x87d9:
    uVar4 = uVar4 & 0xfe3fffff;
    *param_4 = uVar4;
    break;
  case 0x87d6:
  case 0x87da:
    uVar4 = uVar4 & 0xfe3fffff | 0x400000;
    *param_4 = uVar4;
    break;
  case 0x87d7:
  case 0x87db:
    uVar4 = uVar4 & 0xfe3fffff | 0x800000;
    *param_4 = uVar4;
    break;
  case 0x87d8:
  case 0x87dc:
    uVar4 = uVar4 & 0xfe3fffff | 0xc00000;
    *param_4 = uVar4;
    break;
  case 0x87dd:
    uVar4 = uVar4 & 0xfe3fffff | 0x1000000;
    *param_4 = uVar4;
    break;
  case 0x87de:
  case 0x87df:
    uVar4 = uVar4 & 0xfe3fffff | 0x1400000;
    *param_4 = uVar4;
    break;
  default:
    return 0;
  }
  if (10 < param_3[5] - 0x87d5) {
    return 0;
  }
  uVar5 = 1 << (param_3[5] - 0x87d5 & 0x3f);
  if ((uVar5 & 0x30f) == 0) {
    if ((uVar5 & 0x4f0) == 0) {
      return 0;
    }
    uVar4 = uVar4 | 0x10000000;
    *param_4 = uVar4;
  }
  else {
    uVar4 = uVar4 & 0xefffffff;
    *param_4 = uVar4;
  }
  uVar5 = *param_3;
  if (uVar5 != 2) {
    if (uVar5 < 3) {
      if (uVar5 != 0) {
        return 0;
      }
      uVar5 = uVar4 & 0xffffe018;
      *param_4 = uVar5;
    }
    else if (uVar5 == 3) {
      *param_4 = uVar4 & 0xfffffff8;
      uVar5 = (param_3[1] & 0xff) << 5 | uVar4 & 0xffffe018;
      *param_4 = uVar5;
    }
    else {
      if (uVar5 != 4) {
        return 0;
      }
      *param_4 = uVar4 & 0xfffffff8 | 2;
      uVar5 = (param_3[1] & 0xff) << 5 | uVar4 & 0xffffe018 | 2;
      *param_4 = uVar5;
    }
    goto LAB_00057aa0;
  }
  iVar7 = param_3[1] * 0x54;
  iVar8 = iVar7 + *(int *)(param_2 + 4);
  uVar5 = *(uint *)(iVar8 + 0x28);
  if (uVar5 < 0x87c4) {
    if (uVar5 < 0x87c2) {
      if (uVar5 != 0x87c1) {
        return 0;
      }
      iVar6 = *(int *)(iVar8 + 0x24);
      if (iVar6 == 0x87bf) {
        *param_4 = uVar4 & 0xfffffff8 | 1;
        uVar1 = (*(uint *)(iVar8 + 4) & 0xff) << 5;
        uVar5 = uVar1 | uVar4 & 0xffffe018 | 1;
        *param_4 = uVar5;
        iVar7 = iVar7 + *(int *)(param_2 + 4);
        if ((*(char *)(iVar7 + 0x44) != '\0') && (*(int *)(iVar7 + 0x48) == 1)) {
          uVar5 = uVar1 | uVar4 & 0xfe3fe018 | 1 | 0x1000000;
          *param_4 = uVar5;
        }
        goto LAB_00057aa0;
      }
      if (iVar6 != 0x87c0) {
        if (iVar6 != 0x87be) {
          return 0;
        }
        *param_4 = uVar4 & 0xfffffff8 | 1;
        uVar5 = (*(uint *)(iVar8 + 4) & 0xff) << 5;
        *param_4 = uVar5 | uVar4 & 0xffffe018 | 1;
        uVar1 = (*(uint *)(iVar8 + 8) & 7) << 0xd;
        *param_4 = uVar1 | uVar5 | uVar4 & 0xffff0018 | 1;
        iVar7 = iVar7 + *(int *)(param_2 + 4);
        if ((*(char *)(iVar7 + 0x44) == '\0') || (*(int *)(iVar7 + 0x48) != 0xf)) {
          uVar2 = (*(uint *)(iVar8 + 8) & 7) << 0x10;
          *param_4 = uVar2 | uVar1 | uVar5 | uVar4 & 0xfff80018 | 1;
          uVar3 = (*(uint *)(iVar8 + 8) & 7) << 0x13;
          *param_4 = uVar3 | uVar2 | uVar1 | uVar5 | uVar4 & 0xffc00018 | 1;
          uVar5 = (*(uint *)(iVar8 + 8) & 7) << 0x16 |
                  uVar3 | uVar2 | uVar1 | uVar5 | uVar4 & 0xfe000018 | 1;
          *param_4 = uVar5;
        }
        else {
          uVar5 = uVar1 | uVar5 | uVar4 & 0xfe000018 | 1 | 0x1640000;
          *param_4 = uVar5;
        }
        uVar5 = uVar5 & 0xe1ffffff;
        *param_4 = uVar5;
        goto LAB_00057aa0;
      }
      uVar4 = uVar4 & 0xfffffff8 | 1;
    }
    else {
      iVar7 = *(int *)(iVar8 + 0x24);
      if (iVar7 == 0x87bf) {
        *param_4 = uVar4 & 0xfffffff8 | 2;
        uVar5 = (*(uint *)(iVar8 + 4) & 0xff) << 5 | uVar4 & 0xffffe018 | 2;
        *param_4 = uVar5;
        goto LAB_00057aa0;
      }
      if (iVar7 != 0x87c0) {
        uVar4 = uVar4 & 0xfffffff8 | 2;
        if (iVar7 != 0x87be) {
          return 0;
        }
        goto LAB_000579dc;
      }
      uVar4 = uVar4 & 0xfffffff8 | 2;
    }
    *param_4 = uVar4;
    uVar5 = (*(uint *)(param_5 * 4 + iVar8 + 0x10) & 0xff) << 5 | uVar4 & 0xffffe01f;
    *param_4 = uVar5;
  }
  else {
    if (uVar5 != 0x87c4) {
      return 0;
    }
    iVar7 = *(int *)(iVar8 + 0x24);
    if (iVar7 == 0x87bf) {
      *param_4 = uVar4 & 0xfffffff8;
      uVar5 = (*(uint *)(iVar8 + 4) & 0xff) << 5 | uVar4 & 0xffffe018;
      *param_4 = uVar5;
      goto LAB_00057aa0;
    }
    if (iVar7 == 0x87c0) {
      *param_4 = uVar4 & 0xfffffff8;
      uVar5 = (*(uint *)(param_5 * 4 + iVar8 + 0x10) & 0xff) << 5 | uVar4 & 0xffffe018;
      *param_4 = uVar5;
      goto LAB_00057aa0;
    }
    if (iVar7 != 0x87be) {
      return 0;
    }
    uVar4 = uVar4 & 0xfffffff8;
LAB_000579dc:
    *param_4 = uVar4;
    uVar5 = (*(uint *)(iVar8 + 4) & 0xff) << 5;
    *param_4 = uVar5 | uVar4 & 0xffffe01f;
    uVar1 = (*(uint *)(iVar8 + 8) & 7) << 0xd;
    *param_4 = uVar1 | uVar5 | uVar4 & 0xffff001f;
    uVar2 = (*(uint *)(iVar8 + 8) & 7) << 0x10;
    *param_4 = uVar2 | uVar1 | uVar5 | uVar4 & 0xfff8001f;
    uVar3 = (*(uint *)(iVar8 + 8) & 7) << 0x13;
    *param_4 = uVar3 | uVar2 | uVar1 | uVar5 | uVar4 & 0xffc0001f;
    uVar5 = (*(uint *)(iVar8 + 8) & 7) << 0x16 | uVar3 | uVar2 | uVar1 | uVar5 | uVar4 & 0xe000001f;
    *param_4 = uVar5;
  }
LAB_00057aa0:
  if (*(char *)(param_3 + 6) == '\0') {
    uVar5 = uVar5 & 0x9fffffef;
    *param_4 = uVar5;
  }
  else {
    uVar5 = uVar5 & 0x9fffffff | 0x10;
    *param_4 = uVar5;
  }
  *param_4 = uVar5 & 0x7fffffff;
  return 1;
}

/* FUN_00057af0 @ 0x57af0 (144 bytes) */
int FUN_00057af0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  int iVar1;
  int iVar2;
  
  if ((*param_2 == 2) && (*param_3 == 2)) {
    if (param_2[1] != param_3[1]) {
      iVar1 = *(int *)(param_2[1] * 0x54 + *(int *)(param_1 + 4) + 0x28);
      iVar2 = *(int *)(param_3[1] * 0x54 + *(int *)(param_1 + 4) + 0x28);
      if (((iVar1 == 0x87c1) && (iVar2 == 0x87c1)) ||
         ((iVar1 - 0x87c2U < 2 && (iVar2 - 0x87c2U < 2)))) {
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_00057b80 @ 0x57b80 (360 bytes) */
int FUN_00057b80(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = 0;
  bVar1 = true;
  uVar4 = 0;
  iVar2 = 0;
  iVar6 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  while( true ) {
    if (*(uint *)(iVar6 + 0x50) <= uVar5) {
      if (bVar1) {
        *(char *)(param_2 + 4) = (char)uVar4;
        uVar5 = *(uint *)(iVar6 + 0x50);
        iVar2 = (**(code **)(param_1 + 0x10))(uVar5 + 0x10,0x28);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (iVar2,*(undefined4 *)(iVar6 + 0x4c),*(int *)(iVar6 + 0x50) * 0x28);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar6 + 0x4c));
        iVar3 = uVar5 * 0x28;
        *(int *)(iVar6 + 0x4c) = iVar2;
        *(int *)(iVar6 + 0x50) = *(int *)(iVar6 + 0x50) + 0x10;
        *(undefined1 *)(iVar2 + iVar3 + 0x10) = 1;
        *(undefined4 *)(iVar3 + *(int *)(iVar6 + 0x4c) + 0x14) = 4;
        *(undefined4 *)(iVar3 + *(int *)(iVar6 + 0x4c) + 0x18) = uVar4;
        *(undefined4 *)(iVar3 + *(int *)(iVar6 + 0x4c) + 0x1c) = uVar4;
        *(undefined4 *)(iVar3 + *(int *)(iVar6 + 0x4c) + 0x20) = uVar4;
        *(undefined4 *)(iVar3 + *(int *)(iVar6 + 0x4c) + 0x24) = uVar4;
        param_2[0x19] = param_2[0x19] + 1;
      }
      return uVar5;
    }
    if (!bVar1) break;
    if (*(char *)(iVar2 + *(int *)(iVar6 + 0x4c) + 0x10) == '\0') {
      uVar4 = 1;
      bVar1 = false;
    }
    else {
      uVar5 = uVar5 + 1;
      iVar2 = iVar2 + 0x28;
    }
  }
  return uVar5;
}

/* FUN_00059cb0 @ 0x59cb0 (824 bytes) */
int FUN_00059cb0(param_1, param_2, param_3)
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
  iVar2 = ((int (*)())FUN_00057af0)(piVar6,iVar5,iVar4);
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
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,7,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 8,0);
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
    uVar3 = ((int (*)())FUN_00057b80)(param_1,param_2);
    local_78 = 3;
    local_60 = 0;
    local_64 = 1;
    local_70 = 1;
    local_6c = 1;
    local_68 = 1;
    local_74 = uVar3;
    ((int (*)())FUN_00056f20)(param_1,param_2,&local_78,iVar2,3,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    uVar1 = *(uint *)(iVar2 + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(iVar2 + 0xc) = uVar1;
    *(uint *)(iVar2 + 8) = uVar1;
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2 + 0x10,7,0,0);
    local_5c = 3;
    local_44 = 0;
    local_54 = 0x87d5;
    local_50 = 0x87d6;
    local_4c = 0x87d7;
    local_48 = 0x87d8;
    local_58 = uVar3;
    ((int (*)())FUN_00057340)(param_2,piVar6,&local_5c,iVar2 + 0x14,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 0x18,0);
    uVar3 = 2;
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x18);
  }
  return uVar3;
}

/* FUN_0005b010 @ 0x5b010 (932 bytes) */
int FUN_0005b010(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined1 uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iStack00000020;
  undefined4 local_98;
  int local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88[0];
  undefined4 local_84;
  undefined1 local_80;
  undefined4 local_7c;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined1 local_64;
  
  iVar7 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar8 = *(int *)(iVar7 + 0x18);
  iStack00000020 = param_3;
  if (0x100 < iVar8 + 4U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar8 = *(int *)(iVar7 + 0x18);
    if (*(uint *)(iVar7 + 0x20) < iVar8 + 4U) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar7 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar3,*(undefined4 *)(iVar7 + 0x1c),*(int *)(iVar7 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar7 + 0x1c));
      *(undefined4 *)(iVar7 + 0x1c) = uVar3;
      iVar8 = *(int *)(iVar7 + 0x18);
      *(int *)(iVar7 + 0x20) = *(int *)(iVar7 + 0x20) + 0x10;
    }
  }
  piVar5 = param_2 + 7;
  iVar9 = iVar8 * 0x10 + *(int *)(iVar7 + 0x1c);
  iVar8 = ((int (*)())FUN_00057b80)(param_1,param_2);
  iVar6 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar4 = iStack00000020 + 0x20;
  iVar7 = iVar8 * 0x28 + *(int *)(iVar6 + 0x4c);
  uVar1 = *(undefined1 *)(iVar7 + 0x10);
  *(undefined1 *)(iVar7 + 0x10) = 1;
  uVar3 = ((int (*)())FUN_00057b80)(param_1,param_2);
  *(undefined1 *)(iVar8 * 0x28 + *(int *)(iVar6 + 0x4c) + 0x10) = uVar1;
  local_98 = 3;
  local_90 = 1;
  local_8c = 0;
  local_88[0] = 0;
  local_84 = 0;
  local_80 = 0;
  local_94 = iVar8;
  ((int (*)())FUN_00056f20)(param_1,param_2,&local_98,iVar9,0xb,1,0);
  ((int (*)())FUN_00057340)(param_2,piVar5,iVar4,iVar9 + 4,0);
  uVar2 = *(uint *)(iVar9 + 4) & 0xfe001fff | 0x1f6da000;
  *(uint *)(iVar9 + 0xc) = uVar2;
  *(uint *)(iVar9 + 4) = uVar2;
  *(uint *)(iVar9 + 8) = uVar2;
  local_98 = 3;
  local_90 = 1;
  local_8c = 1;
  local_88[0] = 1;
  local_84 = 1;
  local_80 = 0;
  local_94 = iVar8;
  ((int (*)())FUN_00056f20)(param_1,param_2,&local_98,iVar9 + 0x10,3,0,0);
  local_7c = 3;
  local_74 = 0x87d5;
  local_70 = 0x87d5;
  local_6c = 0x87d5;
  local_68 = 0x87d5;
  local_64 = 0;
  local_78 = iVar8;
  ((int (*)())FUN_00057340)(param_2,piVar5,&local_7c,iVar9 + 0x14,0);
  ((int (*)())FUN_00057340)(param_2,piVar5,iVar4,iVar9 + 0x18,0);
  *(undefined4 *)(iVar9 + 0x1c) = *(undefined4 *)(iVar9 + 0x18);
  local_84 = 1;
  local_98 = 3;
  local_90 = 1;
  local_8c = 1;
  local_88[0] = 1;
  local_80 = 0;
  local_94 = uVar3;
  ((int (*)())FUN_00056f20)(param_1,param_2,&local_98,iVar9 + 0x20,6,0,0);
  local_74 = 0x87d5;
  local_7c = 3;
  local_64 = 0;
  local_70 = 0x87d6;
  local_6c = 0x87d7;
  local_68 = 0x87d8;
  local_78 = iVar8;
  ((int (*)())FUN_00057340)(param_2,piVar5,&local_7c,iVar9 + 0x24,0);
  *(undefined4 *)(iVar9 + 0x2c) = *(undefined4 *)(iVar9 + 0x24);
  *(undefined4 *)(iVar9 + 0x28) = *(undefined4 *)(iVar9 + 0x24);
  ((int (*)())FUN_00056f20)(param_1,param_2,iStack00000020 + 4,iVar9 + 0x30,3,0,0);
  ((int (*)())FUN_00057340)(param_2,piVar5,&local_7c,iVar9 + 0x34,0);
  local_7c = 3;
  local_64 = 0;
  local_74 = 0x87d9;
  local_70 = 0x87da;
  local_6c = 0x87db;
  local_68 = 0x87dc;
  local_78 = uVar3;
  ((int (*)())FUN_00057340)(param_2,piVar5,&local_7c,iVar9 + 0x38,0);
  *(undefined4 *)(iVar9 + 0x3c) = *(undefined4 *)(iVar9 + 0x38);
  return 4;
}

/* FUN_0005b4f0 @ 0x5b4f0 (304 bytes) */
int FUN_0005b4f0(param_1, param_2, param_3)
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
  ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,0xc,1,0);
  ((int (*)())FUN_00057340)(param_2,param_2 + 7,param_3 + 0x20,iVar2 + 4,0);
  *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 4);
  *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 4);
  return 1;
}

/* FUN_0005b620 @ 0x5b620 (824 bytes) */
int FUN_0005b620(param_1, param_2, param_3)
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
  
  iVar6 = param_3 + 0x20;
  piVar5 = param_2 + 7;
  iVar4 = param_3 + 0x3c;
  iVar2 = ((int (*)())FUN_00057af0)(piVar5,iVar6,iVar4);
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
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,5,1,0);
    ((int (*)())FUN_00057340)(param_2,piVar5,iVar6,iVar2 + 4,0);
    ((int (*)())FUN_00057340)(param_2,piVar5,iVar4,iVar2 + 8,0);
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
    uVar3 = ((int (*)())FUN_00057b80)(param_1,param_2);
    local_78 = 3;
    local_70 = 0;
    local_6c = 0;
    local_68 = 0;
    local_64 = 1;
    local_60 = 0;
    local_74 = uVar3;
    ((int (*)())FUN_00056f20)(param_1,param_2,&local_78,iVar2,3,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar5,iVar6,iVar2 + 4,0);
    uVar1 = *(uint *)(iVar2 + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(iVar2 + 0xc) = uVar1;
    *(uint *)(iVar2 + 8) = uVar1;
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2 + 0x10,5,1,0);
    local_5c = 3;
    local_44 = 0;
    local_54 = 0x87d5;
    local_50 = 0x87d6;
    local_4c = 0x87d7;
    local_48 = 0x87d8;
    local_58 = uVar3;
    ((int (*)())FUN_00057340)(param_2,piVar5,&local_5c,iVar2 + 0x14,0);
    ((int (*)())FUN_00057340)(param_2,piVar5,iVar4,iVar2 + 0x18,0);
    uVar3 = 2;
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x18);
  }
  return uVar3;
}

/* FUN_0005ba90 @ 0x5ba90 (304 bytes) */
int FUN_0005ba90(param_1, param_2, param_3)
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
  ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,8,1,0);
  ((int (*)())FUN_00057340)(param_2,param_2 + 7,param_3 + 0x20,iVar2 + 4,0);
  *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 4);
  *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 4);
  return 1;
}

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
  iVar2 = ((int (*)())FUN_00057af0)(piVar6,iVar5,iVar4);
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
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,3,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 8,0);
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
    uVar3 = ((int (*)())FUN_00057b80)(param_1,param_2);
    local_78 = 3;
    local_60 = 0;
    local_64 = 1;
    local_70 = 1;
    local_6c = 1;
    local_68 = 1;
    local_74 = uVar3;
    ((int (*)())FUN_00056f20)(param_1,param_2,&local_78,iVar2,3,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    uVar1 = *(uint *)(iVar2 + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(iVar2 + 0xc) = uVar1;
    *(uint *)(iVar2 + 8) = uVar1;
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2 + 0x10,3,0,0);
    local_5c = 3;
    local_44 = 0;
    local_54 = 0x87d5;
    local_50 = 0x87d6;
    local_4c = 0x87d7;
    local_48 = 0x87d8;
    local_58 = uVar3;
    ((int (*)())FUN_00057340)(param_2,piVar6,&local_5c,iVar2 + 0x14,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 0x18,0);
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
  undefined4 local_88[0];
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
  iVar3 = ((int (*)())FUN_00057af0)(piVar5,iVar6,iVar7);
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
    uVar4 = ((int (*)())FUN_00057b80)(param_1,param_2);
    local_98 = 3;
    local_80 = 0;
    local_84 = 1;
    local_90 = 1;
    local_8c = 1;
    local_88[0] = 1;
    local_94 = uVar4;
    ((int (*)())FUN_00056f20)(param_1,param_2,&local_98,iVar3,2,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar5,iVar6,iVar3 + 4,0);
    uVar2 = *(uint *)(iVar3 + 4);
    *(uint *)(iVar3 + 4) =
         (uVar2 & 0x4000000) << 1 |
         (uVar2 & 0x2000000) << 1 |
         uVar2 >> 2 & 0x2000000 |
         (uVar2 & 0x70000) << 3 | (uVar2 & 0xe000) << 3 | uVar2 >> 6 & 0xe000 | uVar2 & 0xe0001fff |
         0x1000000;
    ((int (*)())FUN_00057340)(param_2,piVar5,iVar7,iVar3 + 8,0);
    uVar2 = *(uint *)(iVar3 + 8);
    uVar2 = (uVar2 & 0x2000000) << 2 |
            uVar2 >> 1 & 0x4000000 |
            uVar2 >> 1 & 0x2000000 |
            (uVar2 & 0xe000) << 6 | uVar2 >> 3 & 0x70000 | uVar2 >> 3 & 0xe000 | uVar2 & 0xe0001fff
            | 0x1000000;
    *(uint *)(iVar3 + 0xc) = uVar2;
    *(uint *)(iVar3 + 8) = uVar2;
    ((int (*)())FUN_00056f20)(param_1,param_2,iStack00000020 + 4,iVar3 + 0x10,4,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar5,iVar6,iVar3 + 0x14,0);
    uVar2 = *(uint *)(iVar3 + 0x14);
    *(uint *)(iVar3 + 0x14) =
         (uVar2 & 0x2000000) << 2 |
         uVar2 >> 1 & 0x4000000 |
         uVar2 >> 1 & 0x2000000 |
         (uVar2 & 0xe000) << 6 | uVar2 >> 3 & 0x70000 | uVar2 >> 3 & 0xe000 | uVar2 & 0xe0001fff |
         0x1400000;
    ((int (*)())FUN_00057340)(param_2,piVar5,iVar7,iVar3 + 0x18,0);
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
    ((int (*)())FUN_00057340)(param_2,piVar5,&local_7c,iVar3 + 0x1c,0);
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
    iVar10 = ((int (*)())FUN_00057b80)(param_1,param_2);
    local_58 = &local_7c;
    iVar8 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar3 = iVar10 * 0x28 + *(int *)(iVar8 + 0x4c);
    uVar1 = *(undefined1 *)(iVar3 + 0x10);
    *(undefined1 *)(iVar3 + 0x10) = 1;
    uVar4 = ((int (*)())FUN_00057b80)(param_1,param_2);
    *(undefined1 *)(iVar10 * 0x28 + *(int *)(iVar8 + 0x4c) + 0x10) = uVar1;
    local_80 = 0;
    local_98 = 3;
    local_90 = 1;
    local_8c = 1;
    local_88[0] = 1;
    local_84 = 1;
    local_94 = iVar10;
    ((int (*)())FUN_00056f20)(param_1,param_2,&local_98,iVar9,3,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar5,iVar6,iVar9 + 4,0);
    uVar2 = *(uint *)(iVar9 + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(iVar9 + 0xc) = uVar2;
    *(uint *)(iVar9 + 8) = uVar2;
    local_80 = 0;
    local_84 = 1;
    local_98 = 3;
    local_90 = 1;
    local_8c = 1;
    local_88[0] = 1;
    local_94 = uVar4;
    ((int (*)())FUN_00056f20)(param_1,param_2,&local_98,iVar9 + 0x10,2,0,0);
    local_74 = 0x87d7;
    local_70 = 0x87d5;
    local_64 = 0;
    local_6c = 0x87d6;
    local_68 = 0x87dd;
    local_7c = 3;
    local_78 = iVar10;
    ((int (*)())FUN_00057340)(param_2,piVar5,local_58,iVar9 + 0x14,0);
    ((int (*)())FUN_00057340)(param_2,piVar5,iVar7,iVar9 + 0x18,0);
    uVar2 = *(uint *)(iVar9 + 0x18);
    uVar2 = (uVar2 & 0x2000000) << 2 |
            uVar2 >> 1 & 0x4000000 |
            uVar2 >> 1 & 0x2000000 |
            (uVar2 & 0xe000) << 6 | uVar2 >> 3 & 0x70000 | uVar2 >> 3 & 0xe000 | uVar2 & 0xe0001fff
            | 0x1000000;
    *(uint *)(iVar9 + 0x1c) = uVar2;
    *(uint *)(iVar9 + 0x18) = uVar2;
    ((int (*)())FUN_00056f20)(param_1,param_2,iStack00000020 + 4,iVar9 + 0x20,4,0,0);
    local_74 = 0x87d6;
    local_70 = 0x87d7;
    local_64 = 0;
    local_6c = 0x87d5;
    local_68 = 0x87de;
    local_7c = 3;
    local_78 = iVar10;
    ((int (*)())FUN_00057340)(param_2,piVar5,local_58,iVar9 + 0x24,0);
    ((int (*)())FUN_00057340)(param_2,piVar5,iVar7,iVar9 + 0x28,0);
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
    ((int (*)())FUN_00057340)(param_2,piVar5,local_58,iVar9 + 0x2c,0);
    uVar4 = 3;
  }
  return uVar4;
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
  ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar3,3,0,0);
  ((int (*)())FUN_00057340)(param_2,param_2 + 7,param_3 + 0x20,iVar3 + 4,0);
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
  ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar4,3,0,0);
  ((int (*)())FUN_00057340)(param_2,param_2 + 7,param_3 + 0x20,iVar4 + 4,0);
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
  iVar2 = ((int (*)())FUN_00057af0)(piVar6,iVar5,iVar4);
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
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,5,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 8,0);
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
    uVar3 = ((int (*)())FUN_00057b80)(param_1,param_2);
    local_78 = 3;
    local_60 = 0;
    local_64 = 1;
    local_70 = 1;
    local_6c = 1;
    local_68 = 1;
    local_74 = uVar3;
    ((int (*)())FUN_00056f20)(param_1,param_2,&local_78,iVar2,3,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    uVar1 = *(uint *)(iVar2 + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(iVar2 + 0xc) = uVar1;
    *(uint *)(iVar2 + 8) = uVar1;
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2 + 0x10,5,0,0);
    local_5c = 3;
    local_44 = 0;
    local_54 = 0x87d5;
    local_50 = 0x87d6;
    local_4c = 0x87d7;
    local_48 = 0x87d8;
    local_58 = uVar3;
    ((int (*)())FUN_00057340)(param_2,piVar6,&local_5c,iVar2 + 0x14,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 0x18,0);
    uVar3 = 2;
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x18);
  }
  return uVar3;
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
  uint local_88[0];
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
  local_a4 = ((int (*)())FUN_00057b80)();
  *param_3 = (local_a4 & 0x7f) << 0xd | *param_3 & 0xfff010ff | 0x100000;
  sVar1 = *(short *)(((unsigned char *)0x00002e04) + iVar5);
  local_88[0] = local_a4;
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
    ((int (*)())FUN_00056f20)(param_1,param_2,&local_a8,iVar5,2,0,0);
    local_8c = 3;
    local_74 = 0;
    local_78 = 0x87d5;
    local_84 = 0x87d5;
    local_80 = 0x87d5;
    local_7c = 0x87d5;
    ((int (*)())FUN_00057340)(param_2,piVar4,&local_8c,iVar5 + 4,0);
    ((int (*)())FUN_00057340)(param_2,piVar4,&local_8c,iVar5 + 8,0);
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
    ((int (*)())FUN_00056f20)(param_1,param_2,&local_a8,iVar5 + 0x10,2,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar4,&local_8c,iVar5 + 0x14,0);
    local_58 = 0;
    local_70 = 4;
    local_5c = 0x87d7;
    local_68 = 0x87d7;
    local_64 = 0x87d7;
    local_60 = 0x87d7;
    ((int (*)())FUN_00057340)(param_2,piVar4,&local_70,iVar5 + 0x18,0);
    *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x18);
    local_a8 = 1;
    local_a4 = 0x87bd;
    local_a0 = 0;
    local_9c = 0;
    local_98 = 0;
    local_94 = (uint)*(byte *)(iVar3 + 0x42);
    local_90 = 0;
    ((int (*)())FUN_00056f20)(param_1,param_2,&local_a8,iVar5 + 0x20,3,1,0);
    ((int (*)())FUN_00057340)(param_2,piVar4,&local_8c,iVar5 + 0x24,0);
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
    ((int (*)())FUN_00056f20)(param_1,param_2,&local_a8,iVar5,1,0,0);
    local_84 = 0x87dd;
    local_78 = 0x87dd;
    local_74 = 0;
    local_80 = 0x87de;
    local_8c = 3;
    local_7c = 0x87d5;
    ((int (*)())FUN_00057340)(param_2,param_2 + 7,&local_8c,iVar5 + 4,0);
    local_5c = 0x87dd;
    local_58 = 0;
    local_68 = 0x87dd;
    local_64 = 0x87d6;
    local_60 = 0x87d7;
    local_70 = 4;
    ((int (*)())FUN_00057340)(param_2,param_2 + 7,&local_70,iVar5 + 8,0);
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
      ((int (*)())FUN_00056f20)(param_1,param_2,&local_a8,iVar5,2,0,0);
      local_8c = 3;
      local_74 = 0;
      local_78 = 0x87d5;
      local_84 = 0x87d5;
      local_80 = 0x87d5;
      local_7c = 0x87d5;
      ((int (*)())FUN_00057340)(param_2,piVar4,&local_8c,iVar5 + 4,0);
      local_58 = 0;
      local_70 = 4;
      local_5c = 0x87d7;
      local_68 = 0x87d7;
      local_64 = 0x87d7;
      local_60 = 0x87d7;
      ((int (*)())FUN_00057340)(param_2,piVar4,&local_70,iVar5 + 8,0);
      *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
      local_a8 = 1;
      local_a4 = 0x87bd;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = (uint)*(byte *)(iVar3 + 0x42);
      local_90 = 0;
      ((int (*)())FUN_00056f20)(param_1,param_2,&local_a8,iVar5 + 0x10,3,1,0);
      ((int (*)())FUN_00057340)(param_2,piVar4,&local_8c,iVar5 + 0x14,0);
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
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  uVar2 = 0;
  while( true ) {
    bVar1 = *(int *)(param_1 + uVar2 * 4) != 0;
    if ((bVar1) && (uVar5 = uVar2 + 1, uVar5 < 0x20)) {
      iVar3 = 0x20 - uVar5;
      puVar4 = (undefined4 *)(param_1 + uVar5 * 4);
      do {
        puVar4[-1] = *puVar4;
        puVar4 = puVar4 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    uVar2 = uVar2 + 1;
    if (0x1f < uVar2) break;
    if (bVar1) {
      return;
    }
  }
  return;
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
    _memcpy((void *)(*(int *)(FUN_00002748 + param_1 + 4) + 0xc),*(void **)(param_2 + 0x1c),
            iVar2 * 0x10);
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
  void *param_4;
  int param_5;
{
  short sVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_3 + 0x5c);
  if (iVar3 == 0) {
    return;
  }
  if ((*(char *)(param_2 + 0x7a) == '\0') || ((*(uint *)(param_1 + 0x44) & 0x1000000) == 0)) {
    if (param_5 == 0) {
      return;
    }
  }
  else {
    iVar4 = *(int *)(param_3 + 0x60);
    iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x10);
    sVar1 = *(short *)(((unsigned char *)0x00002e04) + iVar3);
    if (sVar1 == 0x801) {
      *(undefined4 *)((int)param_4 + iVar4 * 0x10 + 4) = 0;
      *(float *)((int)param_4 + iVar4 * 0x10 + 8) =
           -(*(float *)(((unsigned char *)0x00002df0) + iVar3) * *(float *)(((unsigned char *)0x00002df0) + iVar3));
    }
    else if (sVar1 == 0x2601) {
      *(float *)((int)param_4 + iVar4 * 0x10 + 4) =
           *(float *)(((unsigned char *)0x00002df8) + iVar3) * *(float *)(((unsigned char *)0x00002dfc) + iVar3);
      *(float *)((int)param_4 + iVar4 * 0x10 + 8) = -*(float *)(((unsigned char *)0x00002dfc) + iVar3);
    }
    else if (sVar1 == 0x800) {
      *(undefined4 *)((int)param_4 + iVar4 * 0x10 + 4) = 0;
      *(float *)((int)param_4 + iVar4 * 0x10 + 8) = -*(float *)(((unsigned char *)0x00002df0) + iVar3);
    }
    if (param_5 == 0) {
      puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,7);
      *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar2;
      iVar3 = iVar4 * 0x10;
      *puVar2 = 0x880;
      *(int *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) =
           iVar4 + *(int *)(param_1 + 0x2448) + *(int *)(param_3 + 0x14);
      *(undefined **)(*(int *)(FUN_00002748 + param_1 + 4) + 8) = ((unsigned char *)0x00038882);
      *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 0xc) =
           *(undefined4 *)((int)param_4 + iVar3);
      *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 0x10) =
           *(undefined4 *)((int)param_4 + iVar3 + 4);
      *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 0x14) =
           *(undefined4 *)((int)param_4 + iVar3 + 8);
      *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 0x18) =
           *(undefined4 *)((int)param_4 + iVar3 + 0xc);
      UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
      iVar3 = *(int *)(FUN_00002748 + param_1 + 4) + 0x1c;
      *(int *)(FUN_00002748 + param_1 + 4) = iVar3;
      goto LAB_000620ec;
    }
    iVar3 = *(int *)(param_3 + 0x5c);
  }
  puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,iVar3 * 4 + 3);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar2;
  *puVar2 = 0x880;
  *(int *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) =
       *(int *)(param_1 + 0x2448) + *(int *)(param_3 + 0x14);
  *(uint *)(*(int *)(FUN_00002748 + param_1 + 4) + 8) = (iVar3 * 4 + -1) * 0x10000 | 0x8882;
  _memcpy((void *)(*(int *)(FUN_00002748 + param_1 + 4) + 0xc),param_4,iVar3 * 0x10);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  iVar3 = iVar3 * 0x10 + *(int *)(FUN_00002748 + param_1 + 4) + 0xc;
  *(int *)(FUN_00002748 + param_1 + 4) = iVar3;
LAB_000620ec:
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,iVar3);
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
    (**(code **)(param_1 + 0x18))();
  }
  if (*(int *)(param_2 + 0x24) != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  if (*(int *)(param_2 + 0x4c) != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  if (*(int *)(param_2 + 0x54) != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  if (*(int *)(param_2 + 0x220) != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  if (*(int *)(param_2 + 0x228) != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  if (*(int *)(param_2 + 0x2b8) != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  (**(code **)(param_1 + 0x18))(param_2);
  FUN_0007dd30(param_1,param_2);
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
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  code *pcVar8;
  int iVar9;
  
  iVar4 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + **(int **)(((unsigned char *)0x00001168) + param_1));
  if (*(char *)(*(int **)(((unsigned char *)0x00001168) + param_1) + 4) != '\0') {
    if ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0) {
      *(undefined4 *)(param_1 + 0x1ca0) = *(undefined4 *)(iVar4 + 0x234);
      *(undefined4 *)(param_1 + 0x1ca4) = *(undefined4 *)(iVar4 + 0x238);
      *(undefined4 *)(param_1 + 0x1b9c) = *(undefined4 *)(iVar4 + 0x23c);
      *(undefined4 *)(param_1 + 0x1ba0) = *(undefined4 *)(iVar4 + 0x240);
      iVar3 = *(int *)(iVar4 + 0x2a0);
      if (iVar3 + 1U >> 1 != 0) {
        uVar7 = 0;
        iVar5 = param_1;
        iVar9 = iVar4;
        do {
          uVar7 = uVar7 + 1;
          *(undefined4 *)(iVar5 + 0x1be4) = *(undefined4 *)(iVar9 + 0x244);
          puVar1 = (undefined4 *)(iVar9 + 0x270);
          iVar9 = iVar9 + 4;
          *(undefined4 *)(iVar5 + 0x1c04) = *puVar1;
          iVar5 = iVar5 + 4;
          iVar3 = *(int *)(iVar4 + 0x2a0);
        } while (uVar7 < iVar3 + 1U >> 1);
      }
      *(int *)(param_1 + 0x2438) = iVar3;
      pcVar8 = *(code **)(((unsigned char *)0x00001334) + param_1);
      uVar6 = *(undefined4 *)(iVar4 + 0x2a0);
      *(undefined4 *)(param_1 + 0x1b78) = 0;
      *(undefined4 *)(param_1 + 0x243c) = uVar6;
      bVar2 = *(byte *)(iVar4 + 0x36);
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x40000;
      *(uint *)(param_1 + 0x1b78) = bVar2 & 3;
      (*pcVar8)(param_1,1);
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
  undefined8 *puVar5;
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
              iVar7 = *(int *)(iVar7 + 4) * 0x10;
              uVar27 = *puVar2;
              uVar26 = *puVar8;
              iVar13 = *(int *)(iVar13 + 4) * 0x10;
              iVar10 = *(int *)(iVar10 + 4) * 0x10;
              *(undefined8 *)(iVar6 + iVar12) = *puVar5;
              *(undefined8 *)(iVar6 + iVar12 + 8) = uVar22;
              *(undefined8 *)(iVar6 + iVar7) = uVar28;
              *(undefined8 *)(iVar6 + iVar7 + 8) = uVar25;
              *(undefined8 *)(iVar6 + iVar13) = uVar27;
              *(undefined8 *)(iVar6 + iVar13 + 8) = uVar24;
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
          pcVar1 = *(code **)(param_1 + 0x275c);
          *(int *)(FUN_00002748 + param_1 + 4) = *(int *)(FUN_00002748 + param_1 + 4) + 8;
          (*pcVar1)(param_1);
          ((int (*)())FUN_00061eb0)(param_1,param_2,pcVar21,puVar16[0x22],1);
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
        *puVar16 = ((unsigned char *)0x000208b4);
        *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) =
             *(undefined4 *)(param_1 + 0x1b90);
        *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 8) =
             *(undefined4 *)(param_1 + 0x1b8c);
        *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 0xc) =
             *(undefined4 *)(param_1 + 0x1b94);
        iVar6 = *(int *)(FUN_00002748 + param_1 + 4);
        pcVar1 = *(code **)(param_1 + 0x275c);
        *(int *)(FUN_00002748 + param_1 + 4) = iVar6 + 0x10;
        (*pcVar1)(param_1,iVar6 + 0x10);
        puVar16 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
        *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar16;
        *puVar16 = 0x8b7;
        *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) =
             *(undefined4 *)(param_1 + 0x1b98);
        iVar6 = *(int *)(FUN_00002748 + param_1 + 4);
        pcVar1 = *(code **)(param_1 + 0x275c);
        *(int *)(FUN_00002748 + param_1 + 4) = iVar6 + 8;
        (*pcVar1)(param_1,iVar6 + 8);
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
              iVar6 = *(int *)(FUN_00002748 + param_1 + 4);
              pcVar1 = *(code **)(param_1 + 0x275c);
              *(int *)(FUN_00002748 + param_1 + 4) = iVar6 + 8;
              (*pcVar1)(param_1,iVar6 + 8);
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
int FUN_00064f40(param_1)
  int param_1;
{
  byte *pbVar1;
  byte bVar2;
  code *pcVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  int *piVar8;
  int *piVar9;
  undefined4 *puVar10;
  int iVar11;
  
  if ((*(uint *)(param_1 + 0x44) & 0x100000) == 0) {
    param_1 = param_1 + 0x18a0;
    iVar6 = 0x10;
    do {
      *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffffe;
      param_1 = param_1 + 8;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  else {
    piVar9 = *(int **)(((unsigned char *)0x00001168) + param_1);
    if (((*(byte *)(param_1 + 0x2d) & 8) != 0) && ((*(uint *)(param_1 + 0x8c) & 0x10000) != 0)) {
      puVar10 = *(undefined4 **)(((unsigned char *)0x000011b4) + param_1);
      puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
      *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar4;
      *puVar4 = 0x8a1;
      *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) = 0;
      iVar6 = *(int *)(FUN_00002748 + param_1 + 4);
      pcVar3 = *(code **)(param_1 + 0x275c);
      *(int *)(FUN_00002748 + param_1 + 4) = iVar6 + 8;
      (*pcVar3)(param_1,iVar6 + 8);
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
          pcVar3 = *(code **)(param_1 + 0x275c);
          *(int *)(FUN_00002748 + param_1 + 4) = *(int *)(FUN_00002748 + param_1 + 4) + 8;
          (*pcVar3)(param_1);
          ((int (*)())FUN_00061eb0)(param_1,piVar9,iVar6,piVar8[0x22],0);
          return;
        }
      }
      ((int (*)())FUN_00064a10)(param_1,piVar9);
      param_1 = param_1 + 0x18a0;
      iVar6 = 0x10;
      do {
        pbVar1 = (byte *)((int)piVar9 + 0x71);
        piVar9 = (int *)((int)piVar9 + 1);
        *(uint *)(param_1 + 8) = -(uint)*pbVar1 >> 0x1f | *(uint *)(param_1 + 8) & 0xfffffffe;
        param_1 = param_1 + 8;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
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
  code *pcVar3;
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
    *puVar2 = ((unsigned char *)0x000208b4);
    *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) = *(undefined4 *)(param_1 + 0x1b90);
    *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 8) = *(undefined4 *)(param_1 + 0x1b8c);
    *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 0xc) = *(undefined4 *)(param_1 + 0x1b94);
    iVar1 = *(int *)(FUN_00002748 + param_1 + 4);
    pcVar3 = *(code **)(param_1 + 0x275c);
    *(int *)(FUN_00002748 + param_1 + 4) = iVar1 + 0x10;
    (*pcVar3)(param_1,iVar1 + 0x10);
    puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar2;
    *puVar2 = 0x8b7;
    *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) = *(undefined4 *)(param_1 + 0x1b98);
    iVar1 = *(int *)(FUN_00002748 + param_1 + 4);
    pcVar3 = *(code **)(param_1 + 0x275c);
    *(int *)(FUN_00002748 + param_1 + 4) = iVar1 + 8;
    (*pcVar3)(param_1,iVar1 + 8);
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
  undefined4 uVar4;
  int iVar5;
  code *pcVar6;
  undefined4 local_38;
  undefined4 local_34 [8];
  
  cVar1 = *(char *)(param_1 + 0x29);
  if (*(char *)(param_1 + 0x1868) == '\0') {
    (**(code **)(((unsigned char *)0x000012e0) + param_1))();
    return;
  }
  *(undefined1 *)(param_1 + 0x126) = 0;
  (**(code **)(((unsigned char *)0x0000133c) + param_1))();
  if (cVar1 == '\0') {
    iVar5 = *(int *)(param_1 + 0x13c);
    if (iVar5 == *(int *)(param_1 + 0x140)) {
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
    iVar5 = *(int *)(param_1 + 0x13c);
    iVar2 = *(int *)(param_1 + 0x148);
  }
  *(int *)(param_1 + 0x140) = iVar5;
  *(int *)(param_1 + 0x144) = iVar2;
  if (*(char *)(param_1 + 0x124) != '\0') {
LAB_00065500:
    (**(code **)(((unsigned char *)0x000012dc) + param_1))(param_1);
    return;
  }
  if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
    return;
  }
  iVar2 = FUN_0009edd0(param_1,param_1 + 0x1874);
  if (iVar2 == 0) {
    FUN_0009d080(param_1);
    uVar3 = FUN_0009bd00(param_1);
    (**(code **)(((unsigned char *)0x000012b4) + param_1))(param_1);
    uVar4 = FUN_0009d410(param_1,1,&local_38,local_34,uVar3);
    iVar2 = FUN_0009c800(param_1,param_1 + 0x1874,uVar4,*(undefined1 *)(param_1 + 0x131),local_38,
                         local_34[0],uVar3,*(undefined1 *)(param_1 + 0x126));
    if (*(char *)(param_1 + 0x126) != '\0') {
      pcVar6 = *(code **)(((unsigned char *)0x0000133c) + param_1);
      *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000000;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1020;
      *(undefined1 *)(param_1 + 0x29) = 1;
      (*pcVar6)(param_1);
      goto LAB_00065500;
    }
  }
  else if (*(char *)(iVar2 + 0x59) != '\0') goto LAB_0006559c;
  *(int *)(param_1 + 0x14c) = iVar2;
  (**(code **)(((unsigned char *)0x000012c4) + param_1))(param_1,iVar2);
  iVar5 = *(int *)(iVar2 + 0x54) + 0x750;
  if (iVar5 == *(int *)(((unsigned char *)0x0000148c) + param_1)) {
    (**(code **)((int)((unsigned char *)0x000012a0) + param_1))(param_1);
  }
  else {
    (**(code **)((int)((unsigned char *)0x00001294) + param_1))(param_1,iVar5,*(undefined4 *)(iVar2 + 0x3c));
  }
  if (*(char *)(*(int *)(iVar2 + 0x54) + 0x752) == '\0') {
    return;
  }
LAB_0006559c:
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1020;
  *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000000;
  *(undefined1 *)(param_1 + 0x126) = 1;
  *(undefined1 *)(param_1 + 0x29) = 1;
  (**(code **)(((unsigned char *)0x0000133c) + param_1))(param_1);
  (**(code **)(((unsigned char *)0x000012dc) + param_1))(param_1);
  return;
}

/* FUN_00065610 @ 0x65610 (152 bytes) */
int FUN_00065610(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  _memset((void *)(param_2 + 0x68),-1,0x3c);
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
  void *pvVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  void *pvVar10;
  uint uVar11;
  int iVar12;
  int local_78;
  undefined4 local_74;
  uint local_70 [2];
  undefined4 local_68;
  uint local_64;
  
  _memset(local_70,0,0x30);
  uVar7 = *(uint *)(param_1 + 0x44);
  local_68 = *(undefined4 *)(param_1 + 0x1804);
  local_70[0] = local_70[0] | 8;
  if ((uVar7 & 0xc00) != 0) {
    local_64 = uVar7 >> 0xb & 1 | uVar7 >> 9 & 2 | (uint)(byte)((unsigned char *)0x000011d3)[param_1] << 2;
  }
  pvVar10 = *(void **)(param_1 + 0x14c);
  if ((pvVar10 == (void *)0x0) ||
     (iVar3 = _memcmp(pvVar10,local_70,0x30), pvVar4 = pvVar10, iVar3 != 0)) {
    pvVar4 = (void *)FUN_0009edd0(param_1,local_70);
    if (pvVar4 == (void *)0x0) {
      uVar9 = *(uint *)(param_1 + 0x1804);
      bVar1 = ((unsigned char *)0x000011d2)[param_1];
      uVar7 = *(uint *)(param_1 + 0x44) >> 10 & 1;
      puVar5 = (undefined4 *)FUN_00092bf0(param_1,1,0);
      *puVar5 = 0;
      ((int (*)())FUN_00065610)(param_1,puVar5,&local_78,&local_74);
      if (uVar7 == 0) {
        uVar2 = uVar9 >> 3 & 1;
        uVar11 = uVar9 >> 1 & 1;
        uVar8 = 0;
      }
      else {
        uVar2 = uVar9 >> 3 & 1;
        uVar11 = uVar9 >> 1 & 1;
        uVar8 = (uint)bVar1 + uVar2 * 2 + (uVar9 & 1) + uVar11 + 2;
      }
      FUN_00092d40(puVar5,uVar7,(uint)bVar1);
      if (uVar11 == 0) {
        iVar12 = 1;
        iVar3 = 2;
      }
      else {
        iVar12 = 2;
        iVar3 = 3;
        puVar5[0x13] = 1;
        FUN_00093130(puVar5);
      }
      puVar5[3] = iVar12;
      FUN_00092ea0(puVar5,3,0,0);
      if ((uVar9 & 1) != 0) {
        puVar5[4] = iVar3;
        FUN_00092ea0(puVar5,4,1,0);
        if ((uVar9 & 4) != 0) {
          puVar5[0x14] = iVar3;
          puVar5[0x15] = 3;
          FUN_000931e0(puVar5);
        }
        iVar3 = iVar12 + 2;
      }
      if (uVar2 != 0) {
        puVar5[5] = iVar3;
        FUN_00092ea0(puVar5,3,2,1);
        puVar5[6] = iVar3 + 1;
        puVar5[0x20] = 0;
        iVar3 = iVar3 + 2;
        FUN_00092ea0(puVar5,4,3,1);
      }
      uVar7 = (uint)(uVar2 != 0);
      if (uVar9 >> 4 != 0) {
        uVar2 = 0;
        iVar12 = param_1;
        do {
          iVar6 = *(int *)(iVar12 + 0x1824);
          puVar5[iVar6 + 0xb] = iVar3;
          iVar3 = iVar3 + 1;
          if (uVar7 == uVar8) {
            uVar7 = uVar7 + 1;
          }
          puVar5[iVar6 + 0x21] = uVar7;
          uVar2 = uVar2 + 1;
          uVar7 = uVar7 + 1;
          iVar12 = iVar12 + 4;
          FUN_00093000(puVar5);
        } while (uVar9 >> 4 != uVar2);
      }
      FUN_0009a910(puVar5);
      local_78 = iVar3;
      pvVar4 = (void *)FUN_0009c800(param_1,local_70,puVar5,iVar3,local_74,0,0,1);
      *(undefined4 *)((int)pvVar4 + 0x34) = 0;
      *(int *)((int)pvVar4 + 0x38) = *(int *)(*(int *)((int)pvVar4 + 0x54) + 0x3cc) + -1;
      pvVar10 = *(void **)(param_1 + 0x14c);
    }
    else {
      pvVar10 = *(void **)(param_1 + 0x14c);
    }
  }
  if (pvVar4 != pvVar10) {
    *(void **)(param_1 + 0x14c) = pvVar4;
    *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000;
  }
  (**(code **)((int)((unsigned char *)0x00001294) + param_1))
            (param_1,*(int *)((int)pvVar4 + 0x54) + 0x750,*(undefined4 *)((int)pvVar4 + 0x3c));
  return;
}

/* FUN_00065ea0 @ 0x65ea0 (1912 bytes) */
int FUN_00065ea0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
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
  void *pvVar4;
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
  uint in_stack_00000038;
  uint in_stack_0000003c;
  uint *in_stack_00000040;
  uint *in_stack_00000044;
  
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
  uVar1 = (in_stack_00000038 & 0x3f) << 0x10 | in_stack_0000003c & 0xffff;
  if (*in_stack_00000044 == 0) {
    uVar10 = in_stack_00000044[1];
    if (uVar10 == 0) {
      uVar7 = in_stack_00000044[2];
      if (uVar7 == 0) {
        uVar6 = in_stack_00000044[3];
        if (uVar6 == 0) {
          uVar11 = *in_stack_00000040;
          if (uVar11 == 0) {
            uVar5 = in_stack_00000040[1];
            if (uVar5 == 1) {
              uVar3 = in_stack_00000040[2];
              if (uVar3 == 2) {
                uVar9 = in_stack_00000040[3];
                if (uVar9 == 3) goto LAB_00066234;
              }
              else {
                uVar9 = in_stack_00000040[3];
              }
            }
            else {
              uVar9 = in_stack_00000040[3];
              uVar3 = in_stack_00000040[2];
            }
          }
          else {
            uVar9 = in_stack_00000040[3];
            uVar5 = in_stack_00000040[1];
            uVar3 = in_stack_00000040[2];
          }
        }
        else {
          uVar9 = in_stack_00000040[3];
          uVar11 = *in_stack_00000040;
          uVar5 = in_stack_00000040[1];
          uVar3 = in_stack_00000040[2];
        }
      }
      else {
        uVar6 = in_stack_00000044[3];
        uVar9 = in_stack_00000040[3];
        uVar11 = *in_stack_00000040;
        uVar5 = in_stack_00000040[1];
        uVar3 = in_stack_00000040[2];
      }
    }
    else {
      uVar6 = in_stack_00000044[3];
      uVar9 = in_stack_00000040[3];
      uVar7 = in_stack_00000044[2];
      uVar11 = *in_stack_00000040;
      uVar5 = in_stack_00000040[1];
      uVar3 = in_stack_00000040[2];
    }
  }
  else {
    uVar6 = in_stack_00000044[3];
    uVar9 = in_stack_00000040[3];
    uVar10 = in_stack_00000044[1];
    uVar7 = in_stack_00000044[2];
    uVar11 = *in_stack_00000040;
    uVar5 = in_stack_00000040[1];
    uVar3 = in_stack_00000040[2];
  }
  uVar1 = uVar1 | 0x400000;
  uVar15 = (uVar6 & 1) << 0xf |
           (uVar9 & 7) << 0xc |
           (uVar7 & 1) << 0xb |
           (uVar3 & 7) << 8 |
           (uVar10 & 1) << 7 | (uVar5 & 7) << 4 | (*in_stack_00000044 & 1) << 3 | uVar11 & 7;
LAB_00066234:
  uVar3 = *puVar18;
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    pvVar4 = (void *)(**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = 0x23;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    pvVar4 = (void *)(**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  if ((uVar13 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar3) {
      pvVar4 = (void *)(**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar4;
      uVar3 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar14;
    uVar3 = *puVar18 + 1;
    *puVar18 = uVar3;
  }
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    pvVar4 = (void *)(**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar12;
  uVar13 = *puVar18 + 1;
  *puVar18 = uVar13;
  if ((uVar12 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      pvVar4 = (void *)(**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar4;
      uVar13 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar17;
    uVar13 = *puVar18 + 1;
    *puVar18 = uVar13;
  }
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar13) {
    pvVar4 = (void *)(**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    uVar13 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar1;
  uVar13 = *puVar18 + 1;
  *puVar18 = uVar13;
  if ((uVar1 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      pvVar4 = (void *)(**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar4;
      uVar13 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    *puVar18 = *puVar18 + 1;
  }
  return;
}

/* FUN_0006fd10 @ 0x6fd10 (180 bytes) */
int FUN_0006fd10(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  undefined4 param_3;
{
  void *pvVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = param_3;
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_0006fdd0 @ 0x6fdd0 (1812 bytes) */
int FUN_0006fdd0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  
  iVar4 = *(int *)(param_4 + 0x28);
  if (iVar4 == 0x87c3) {
    *(int *)(param_2 + 0x60) = *(int *)(param_2 + 0x60) + 1;
    *(int *)(param_3 + 0x118) = *(int *)(param_3 + 0x118) + 1;
    *(undefined1 *)(param_4 + 0x3d) = 1;
    iVar4 = *(int *)(param_4 + 0x24);
    if (iVar4 == 0x87bf) {
      uVar6 = 0;
      uVar7 = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
      while (uVar7 < *(uint *)(param_3 + 0x48)) {
        if (!bVar1) goto LAB_000702bc;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x44) + 0x10) == '\0') {
          uVar6 = 1;
          bVar1 = false;
        }
        else {
          uVar7 = uVar7 + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
      goto LAB_000702b8;
    }
    if (iVar4 == 0x87c0) {
      uVar7 = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 4;
      while (uVar7 < *(int *)(param_3 + 0x48) - 3U) {
        if (!bVar1) goto LAB_000703cc;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x44) + 0x10) == '\0') {
          bVar1 = false;
        }
        else {
          uVar7 = uVar7 + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
      if (!bVar1) {
LAB_000703cc:
        iVar8 = uVar7 * 0x28;
        iVar4 = iVar8 + *(int *)(param_3 + 0x44);
        if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
           (*(char *)(iVar4 + 0x88) == '\0')) {
          iVar4 = 0;
          iVar10 = 4;
          do {
            iVar2 = uVar7 + iVar4;
            iVar4 = iVar4 + 1;
            *(int *)(param_4 + 0x10) = iVar2;
            param_4 = param_4 + 4;
            iVar2 = *(int *)(param_3 + 0x44) + iVar8;
            iVar8 = iVar8 + 0x28;
            *(undefined1 *)(iVar2 + 0x10) = 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
          return 0;
        }
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar10 = *(int *)(param_3 + 0x48);
      uVar9 = (**(code **)(param_1 + 0x10))(iVar10 + 0x40,0x28);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar9,*(undefined4 *)(param_3 + 0x44),*(int *)(param_3 + 0x48) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x44));
      *(undefined4 *)(param_3 + 0x44) = uVar9;
      iVar4 = iVar10 * 0x28;
      iVar2 = 4;
      iVar8 = 0;
      *(int *)(param_3 + 0x48) = *(int *)(param_3 + 0x48) + 0x40;
      do {
        iVar3 = iVar10 + iVar8;
        iVar8 = iVar8 + 1;
        *(int *)(param_4 + 0x10) = iVar3;
        param_4 = param_4 + 4;
        iVar3 = *(int *)(param_3 + 0x44) + iVar4;
        iVar4 = iVar4 + 0x28;
        *(undefined1 *)(iVar3 + 0x10) = 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      return 0;
    }
    if (iVar4 != 0x87be) {
      return 1;
    }
    uVar9 = 0;
    uVar7 = 0;
    iVar4 = 0;
    bVar1 = true;
    *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
    while (uVar7 < *(uint *)(param_3 + 0x48)) {
      if (!bVar1) goto LAB_000701ac;
      if (*(char *)(iVar4 + *(int *)(param_3 + 0x44) + 0x10) == '\0') {
        uVar9 = 1;
        bVar1 = false;
      }
      else {
        uVar7 = uVar7 + 1;
        iVar4 = iVar4 + 0x28;
      }
    }
  }
  else {
    if (iVar4 == 0x87c4) {
      return 0;
    }
    if (iVar4 != 0x87c2) {
      return 1;
    }
    *(int *)(param_2 + 0x5c) = *(int *)(param_2 + 0x5c) + 1;
    if (*(char *)(param_4 + 0x44) == '\0') {
      *(int *)(param_3 + 0x118) = *(int *)(param_3 + 0x118) + 1;
    }
    else {
      *(int *)(param_3 + 0x120) = *(int *)(param_3 + 0x120) + 1;
    }
    iVar4 = *(int *)(param_4 + 0x24);
    *(undefined1 *)(param_4 + 0x3d) = 1;
    if (iVar4 == 0x87bf) {
      uVar6 = 0;
      uVar7 = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
      while (uVar7 < *(uint *)(param_3 + 0x48)) {
        if (!bVar1) goto LAB_000702bc;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x44) + 0x10) == '\0') {
          uVar6 = 1;
          bVar1 = false;
        }
        else {
          uVar7 = uVar7 + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
LAB_000702b8:
      if (!bVar1) {
LAB_000702bc:
        *(uint *)(param_4 + 4) = uVar7;
        *(undefined1 *)(uVar7 * 0x28 + *(int *)(param_3 + 0x44) + 0x10) = 1;
        return 0;
      }
      *(undefined1 *)(param_2 + 0x10) = uVar6;
      iVar4 = *(int *)(param_3 + 0x48);
      uVar9 = (**(code **)(param_1 + 0x10))(iVar4 + 0x40,0x28);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar9,*(undefined4 *)(param_3 + 0x44),*(int *)(param_3 + 0x48) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x44));
      *(undefined4 *)(param_3 + 0x44) = uVar9;
      *(int *)(param_3 + 0x48) = *(int *)(param_3 + 0x48) + 0x40;
      goto LAB_00070350;
    }
    if (iVar4 == 0x87c0) {
      uVar7 = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 4;
      while (uVar7 < *(int *)(param_3 + 0x48) - 3U) {
        if (!bVar1) goto LAB_0006ffbc;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x44) + 0x10) == '\0') {
          bVar1 = false;
        }
        else {
          uVar7 = uVar7 + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
      if (!bVar1) {
LAB_0006ffbc:
        iVar8 = uVar7 * 0x28;
        iVar4 = iVar8 + *(int *)(param_3 + 0x44);
        if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
           (*(char *)(iVar4 + 0x88) == '\0')) {
          iVar4 = 0;
          iVar10 = 4;
          do {
            iVar2 = uVar7 + iVar4;
            iVar4 = iVar4 + 1;
            *(int *)(param_4 + 0x10) = iVar2;
            param_4 = param_4 + 4;
            iVar2 = *(int *)(param_3 + 0x44) + iVar8;
            iVar8 = iVar8 + 0x28;
            *(undefined1 *)(iVar2 + 0x10) = 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
          return 0;
        }
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar10 = *(int *)(param_3 + 0x48);
      uVar9 = (**(code **)(param_1 + 0x10))(iVar10 + 0x40,0x28);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar9,*(undefined4 *)(param_3 + 0x44),*(int *)(param_3 + 0x48) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x44));
      *(undefined4 *)(param_3 + 0x44) = uVar9;
      iVar4 = iVar10 * 0x28;
      iVar2 = 4;
      iVar8 = 0;
      *(int *)(param_3 + 0x48) = *(int *)(param_3 + 0x48) + 0x40;
      do {
        iVar3 = iVar10 + iVar8;
        iVar8 = iVar8 + 1;
        *(int *)(param_4 + 0x10) = iVar3;
        param_4 = param_4 + 4;
        iVar3 = iVar4 + *(int *)(param_3 + 0x44);
        iVar4 = iVar4 + 0x28;
        *(undefined1 *)(iVar3 + 0x10) = 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      return 0;
    }
    if (iVar4 != 0x87be) {
      return 1;
    }
    uVar9 = 0;
    uVar7 = 0;
    iVar4 = 0;
    bVar1 = true;
    *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
    while (uVar7 < *(uint *)(param_3 + 0x48)) {
      if (!bVar1) goto LAB_000701ac;
      if (*(char *)(iVar4 + *(int *)(param_3 + 0x44) + 0x10) == '\0') {
        uVar9 = 1;
        bVar1 = false;
      }
      else {
        uVar7 = uVar7 + 1;
        iVar4 = iVar4 + 0x28;
      }
    }
  }
  if (!bVar1) {
LAB_000701ac:
    *(uint *)(param_4 + 4) = uVar7;
    *(undefined4 *)(param_4 + 8) = 0;
    *(undefined1 *)(uVar7 * 0x28 + *(int *)(param_3 + 0x44) + 0x10) = 1;
    return 0;
  }
  *(char *)(param_2 + 0x10) = (char)uVar9;
  iVar4 = *(int *)(param_3 + 0x48);
  uVar5 = (**(code **)(param_1 + 0x10))(iVar4 + 0x40,0x28);
  (**(code **)(((unsigned char *)0x00001344) + param_1))
            (uVar5,*(undefined4 *)(param_3 + 0x44),*(int *)(param_3 + 0x48) * 0x28);
  (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x44));
  *(undefined4 *)(param_3 + 0x44) = uVar5;
  *(int *)(param_3 + 0x48) = *(int *)(param_3 + 0x48) + 0x40;
  *(undefined4 *)(param_4 + 8) = uVar9;
LAB_00070350:
  *(int *)(param_4 + 4) = iVar4;
  *(undefined1 *)(iVar4 * 0x28 + *(int *)(param_3 + 0x44) + 0x10) = 1;
  return 0;
}

/* FUN_00070520 @ 0x70520 (252 bytes) */
int FUN_00070520(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int *param_4;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (*param_4 == 2) {
    iVar1 = *(int *)(param_2 + 0x20);
    iVar4 = param_4[1] * 0x54;
    iVar2 = iVar4 + iVar1;
    if (*(char *)(iVar2 + 0x3d) == '\0') {
      if (*(int *)(iVar2 + 0x30) == 0) {
        if (*(uint *)(iVar2 + 0x34) < 2) {
          iVar1 = ((int (*)())FUN_0006fdd0)();
          if (iVar1 != 1) {
            return 0;
          }
          return 1;
        }
      }
      else {
        iVar4 = ((int (*)())FUN_00054da0)(param_2 + 0x1c,*(int *)(iVar2 + 0x30));
        iVar1 = *(int *)(param_2 + 0x20);
        iVar4 = iVar4 * 0x54;
      }
      if (*(int *)(iVar4 + iVar1 + 0x34) != 0) {
        uVar3 = 0;
        iVar2 = iVar4;
        do {
          iVar1 = ((int (*)())FUN_0006fdd0)(param_1,param_2,param_3,iVar1 + iVar2);
          if (iVar1 == 1) {
            return 1;
          }
          iVar1 = *(int *)(param_2 + 0x20);
          uVar3 = uVar3 + 1;
          iVar2 = iVar2 + 0x54;
        } while (uVar3 < *(uint *)(iVar1 + iVar4 + 0x34));
      }
    }
  }
  return 0;
}

/* FUN_00070630 @ 0x70630 (1412 bytes) */
int FUN_00070630(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  if (*param_4 == 2) {
    iVar10 = param_4[1];
    iVar11 = iVar10 * 0x54 + *(int *)(param_2 + 0x20);
    if ((*(int *)(iVar11 + 0x28) == 0x87c4) && (*(char *)(iVar11 + 0x3d) == '\0')) {
      *(undefined1 *)(iVar11 + 0x3d) = 1;
      *(int *)(param_2 + 100) = *(int *)(param_2 + 100) + 1;
      iVar7 = *(int *)(iVar10 * 0x54 + *(int *)(param_2 + 0x20) + 0x24);
      if (iVar7 == 0x87bf) {
        uVar5 = 0;
        uVar6 = 0;
        bVar1 = true;
        while (uVar5 < *(uint *)(param_3 + 0x40)) {
          if (!bVar1) goto LAB_000708f8;
          if (*(char *)(uVar5 * 0x28 + *(int *)(param_3 + 0x3c) + 0x10) == '\0') {
            uVar6 = 1;
            bVar1 = false;
          }
          else {
            uVar5 = uVar5 + 1;
          }
        }
        if (bVar1) {
          *(undefined1 *)(param_2 + 0x10) = uVar6;
          uVar5 = *(uint *)(param_3 + 0x40);
          uVar4 = (**(code **)(param_1 + 0x10))(uVar5 + 0x40,0x28);
          (**(code **)(((unsigned char *)0x00001344) + param_1))
                    (uVar4,*(undefined4 *)(param_3 + 0x3c),*(int *)(param_3 + 0x40) * 0x28);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x3c));
          *(undefined4 *)(param_3 + 0x3c) = uVar4;
          *(int *)(param_3 + 0x40) = *(int *)(param_3 + 0x40) + 0x40;
          *(uint *)(iVar11 + 4) = uVar5;
        }
        else {
LAB_000708f8:
          *(uint *)(iVar11 + 4) = uVar5;
        }
        iVar11 = uVar5 * 0x28;
        *(undefined1 *)(*(int *)(param_3 + 0x3c) + iVar11 + 0x10) = 1;
        *(undefined4 *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x14) = 4;
        *(int *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x18) = iVar10;
        *(int *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x1c) = iVar10;
        *(int *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x20) = iVar10;
        *(int *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x24) = iVar10;
      }
      else if (iVar7 == 0x87c0) {
        uVar5 = 0;
        bVar1 = true;
        while (uVar5 < *(int *)(param_3 + 0x40) - 3U) {
          if (!bVar1) goto LAB_00070a18;
          if (*(char *)(uVar5 * 0x28 + *(int *)(param_3 + 0x3c) + 0x10) == '\0') {
            bVar1 = false;
          }
          else {
            uVar5 = uVar5 + 1;
          }
        }
        if (!bVar1) {
LAB_00070a18:
          iVar8 = uVar5 * 0x28;
          iVar7 = iVar8 + *(int *)(param_3 + 0x3c);
          if (((*(char *)(iVar7 + 0x38) == '\0') && (*(char *)(iVar7 + 0x60) == '\0')) &&
             (*(char *)(iVar7 + 0x88) == '\0')) {
            iVar7 = 0;
            iVar12 = 4;
            do {
              iVar2 = uVar5 + iVar7;
              iVar7 = iVar7 + 1;
              *(int *)(iVar11 + 0x10) = iVar2;
              iVar11 = iVar11 + 4;
              *(undefined1 *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x10) = 1;
              *(undefined4 *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x14) = 4;
              *(int *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x18) = iVar10;
              *(int *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x1c) = iVar10;
              *(int *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x20) = iVar10;
              iVar2 = *(int *)(param_3 + 0x3c) + iVar8;
              iVar8 = iVar8 + 0x28;
              *(int *)(iVar2 + 0x24) = iVar10;
              iVar12 = iVar12 + -1;
            } while (iVar12 != 0);
            return;
          }
        }
        *(undefined1 *)(param_2 + 0x10) = 0;
        iVar12 = *(int *)(param_3 + 0x40);
        uVar4 = (**(code **)(param_1 + 0x10))(iVar12 + 0x40,0x28);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar4,*(undefined4 *)(param_3 + 0x3c),*(int *)(param_3 + 0x40) * 0x28);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x3c));
        *(undefined4 *)(param_3 + 0x3c) = uVar4;
        iVar8 = iVar12 * 0x28;
        iVar2 = 4;
        iVar7 = 0;
        *(int *)(param_3 + 0x40) = *(int *)(param_3 + 0x40) + 0x40;
        do {
          iVar3 = iVar12 + iVar7;
          iVar7 = iVar7 + 1;
          *(int *)(iVar11 + 0x10) = iVar3;
          iVar11 = iVar11 + 4;
          *(undefined1 *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x10) = 1;
          *(undefined4 *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x14) = 4;
          *(int *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x18) = iVar10;
          *(int *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x1c) = iVar10;
          *(int *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x20) = iVar10;
          iVar3 = *(int *)(param_3 + 0x3c) + iVar8;
          iVar8 = iVar8 + 0x28;
          *(int *)(iVar3 + 0x24) = iVar10;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      else if (iVar7 == 0x87be) {
        uVar5 = *(uint *)(param_3 + 0x40);
        uVar9 = 0;
        bVar1 = false;
        iVar7 = 0;
        while (uVar9 < uVar5) {
          if (bVar1) goto LAB_0007075c;
          iVar8 = iVar7 + *(int *)(param_3 + 0x3c);
          if ((*(char *)(iVar8 + 0x10) == '\0') || (bVar1 = true, 3 < *(uint *)(iVar8 + 0x14))) {
            uVar9 = uVar9 + 1;
            iVar7 = iVar7 + 0x28;
            bVar1 = false;
          }
        }
        if (bVar1) {
LAB_0007075c:
          *(uint *)(iVar11 + 4) = uVar9;
          iVar7 = uVar9 * 0x28;
          *(undefined4 *)(iVar11 + 8) = *(undefined4 *)(*(int *)(param_3 + 0x3c) + iVar7 + 0x14);
          iVar11 = iVar7 + *(int *)(param_3 + 0x3c);
          *(int *)(*(int *)(iVar11 + 0x14) * 4 + iVar11 + 0x18) = iVar10;
          iVar7 = iVar7 + *(int *)(param_3 + 0x3c);
          *(int *)(iVar7 + 0x14) = *(int *)(iVar7 + 0x14) + 1;
        }
        else {
          if (uVar5 == 0) {
LAB_000707f4:
            *(undefined1 *)(param_2 + 0x10) = 0;
            uVar9 = *(uint *)(param_3 + 0x40);
            uVar4 = (**(code **)(param_1 + 0x10))(uVar9 + 0x40,0x28);
            (**(code **)(((unsigned char *)0x00001344) + param_1))
                      (uVar4,*(undefined4 *)(param_3 + 0x3c),*(int *)(param_3 + 0x40) * 0x28);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x3c));
            *(undefined4 *)(param_3 + 0x3c) = uVar4;
            *(int *)(param_3 + 0x40) = *(int *)(param_3 + 0x40) + 0x40;
            *(undefined4 *)(iVar11 + 8) = 0;
            *(uint *)(iVar11 + 4) = uVar9;
          }
          else {
            uVar9 = 0;
            do {
              bVar1 = *(char *)(uVar9 * 0x28 + *(int *)(param_3 + 0x3c) + 0x10) != '\0';
              if (bVar1) {
                uVar9 = uVar9 + 1;
              }
              if (uVar5 <= uVar9) {
                if (bVar1) goto LAB_000707f4;
                break;
              }
            } while (bVar1);
            *(uint *)(iVar11 + 4) = uVar9;
            *(undefined4 *)(iVar11 + 8) = 0;
          }
          iVar11 = uVar9 * 0x28;
          *(undefined1 *)(*(int *)(param_3 + 0x3c) + iVar11 + 0x10) = 1;
          *(undefined4 *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x14) = 1;
          *(int *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x18) = iVar10;
        }
      }
    }
  }
  return;
}

/* FUN_00070bf0 @ 0x70bf0 (80 bytes) */
int FUN_00070bf0(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  if ((*param_1 == 2) &&
     ((((iVar1 = param_1[1], iVar1 == *(int *)(param_2 + 0x18) ||
        (iVar1 == *(int *)(param_2 + 0x1c))) || (iVar1 == *(int *)(param_2 + 0x20))) ||
      (iVar1 == *(int *)(param_2 + 0x24))))) {
    return 1;
  }
  return 0;
}

/* FUN_00070c70 @ 0x70c70 (84 bytes) */
int FUN_00070c70(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = uVar2;
    if (*(int *)(uVar2 * 4 + param_1 + 0x60) == -1) {
      return uVar2;
    }
    do {
      uVar2 = uVar1 + 1;
      if (0x15 < uVar2) {
        return 0xffffffff;
      }
      uVar1 = uVar2;
    } while (((uVar2 == 1) || (uVar1 = 0x12, uVar2 == 0x12)) || (uVar1 = uVar2, uVar2 == 0x13));
  } while( true );
}

/* FUN_00070cd0 @ 0x70cd0 (144 bytes) */
int FUN_00070cd0(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  
  iVar3 = *(int *)(param_1 + 0x40);
  if (iVar3 == 0) {
    return -1;
  }
  iVar7 = *(int *)(param_1 + 0x3c);
  if (*(char *)(iVar7 + 0x10) == '\0') {
    iVar4 = 0;
    iVar5 = 0;
    iVar8 = iVar7;
  }
  else {
    pcVar6 = (char *)(iVar7 + 0x38);
    iVar4 = 0;
    iVar2 = 0x28;
    do {
      iVar5 = iVar2;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) {
        return -1;
      }
      cVar1 = *pcVar6;
      iVar8 = iVar7 + iVar5;
      pcVar6 = pcVar6 + 0x28;
      iVar2 = iVar5 + 0x28;
    } while (cVar1 != '\0');
  }
  *(undefined1 *)(iVar8 + 0x10) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x3c) + iVar5 + 0x14) = 4;
  return iVar4;
}

/* FUN_00070d80 @ 0x70d80 (3624 bytes) */
int FUN_00070d80(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  short sVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  uint *puVar7;
  
  puVar7 = (uint *)(param_2 + 4);
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (param_4 == 0) {
    if (*(uint *)(param_2 + 8) <= *(uint *)(param_2 + 4)) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_2 + 0xc),*(int *)(param_2 + 4) << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar3;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(*puVar7 * 4 + *(int *)(param_2 + 0xc)) = 0x47;
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(param_2 + 8) <= uVar4) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar3;
      uVar4 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x100000;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c0) + param_3);
    if (*(uint *)(param_2 + 8) <= uVar5) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar3;
      uVar5 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x440000;
    puVar6 = (undefined *)0x0;
    uVar4 = *(uint *)(param_2 + 8);
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    if (uVar4 <= uVar5) {
LAB_00071330:
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(uVar4 * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar3;
      uVar5 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
LAB_00071390:
    *(undefined **)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = puVar6;
    *puVar7 = *puVar7 + 1;
  }
  else {
    *(undefined1 *)(param_2 + 3) = 1;
    sVar1 = *(short *)(((unsigned char *)0x00002e04) + iVar2);
    if (sVar1 == 0x801) {
      if (*(uint *)(param_2 + 8) <= *(uint *)(param_2 + 4)) {
        pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar3,*(void **)(param_2 + 0xc),*(int *)(param_2 + 4) << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar3;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(undefined4 *)(*puVar7 * 4 + *(int *)(param_2 + 0xc)) = 0x49;
      uVar5 = *puVar7 + 1;
      *puVar7 = uVar5;
      uVar4 = *(uint *)(((unsigned char *)0x000013c0) + param_3);
      if (*(uint *)(param_2 + 8) <= uVar5) {
        pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar3;
        uVar5 = *puVar7;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x40000;
      uVar4 = *puVar7 + 1;
      *puVar7 = uVar4;
      uVar5 = *(uint *)(((unsigned char *)0x000013c0) + param_3) & 0xffff | 0x40000;
      if (*(uint *)(param_2 + 8) <= uVar4) {
        pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar3;
        uVar4 = *puVar7;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar5;
      uVar4 = *puVar7 + 1;
      *puVar7 = uVar4;
      if (*(uint *)(param_2 + 8) <= uVar4) {
        pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar3;
        uVar4 = *puVar7;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar5;
      uVar4 = *puVar7 + 1;
      *puVar7 = uVar4;
    }
    else {
      if (sVar1 == 0x2601) {
        if (*(uint *)(param_2 + 8) <= *(uint *)(param_2 + 4)) {
          pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar3,*(void **)(param_2 + 0xc),*(int *)(param_2 + 4) << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar3;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(*puVar7 * 4 + *(int *)(param_2 + 0xc)) = 0x23;
        uVar4 = *puVar7 + 1;
        *puVar7 = uVar4;
        if (*(uint *)(param_2 + 8) <= uVar4) {
          pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar3;
          uVar4 = *puVar7;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x100000;
        uVar5 = *puVar7 + 1;
        *puVar7 = uVar5;
        uVar4 = *(uint *)(((unsigned char *)0x000013c0) + param_3);
        if (*(uint *)(param_2 + 8) <= uVar5) {
          pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar3;
          uVar5 = *puVar7;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x440000;
        uVar4 = *puVar7 + 1;
        *puVar7 = uVar4;
        if (*(uint *)(param_2 + 8) <= uVar4) {
          pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar3;
          uVar4 = *puVar7;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = ((unsigned char *)0x00004054);
        uVar5 = *puVar7 + 1;
        *puVar7 = uVar5;
        uVar4 = *(uint *)(((unsigned char *)0x000013c4) + param_3);
        if (*(uint *)(param_2 + 8) <= uVar5) {
          pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar3;
          uVar5 = *puVar7;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x410000;
        puVar6 = ((unsigned char *)0x00004214);
        uVar4 = *(uint *)(param_2 + 8);
        uVar5 = *puVar7 + 1;
        *puVar7 = uVar5;
        if (uVar4 <= uVar5) goto LAB_00071330;
        goto LAB_00071390;
      }
      if (sVar1 != 0x800) {
        return;
      }
      uVar4 = *puVar7;
    }
    if (*(uint *)(param_2 + 8) <= uVar4) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar3;
      uVar4 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x49;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c0) + param_3);
    if (*(uint *)(param_2 + 8) <= uVar5) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar3;
      uVar5 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x40000;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c0) + param_3);
    if (*(uint *)(param_2 + 8) <= uVar5) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar3;
      uVar5 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x40000;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c4) + param_3);
    if (*(uint *)(param_2 + 8) <= uVar5) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar3;
      uVar5 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x410000;
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(param_2 + 8) <= uVar4) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar3;
      uVar4 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = ((unsigned char *)0x00002222);
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(param_2 + 8) <= uVar4) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar3;
      uVar4 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x2c;
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(param_2 + 8) <= uVar4) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar3;
      uVar4 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x100000;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c0) + param_3);
    if (*(uint *)(param_2 + 8) <= uVar5) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar3;
      uVar5 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x440000;
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(param_2 + 8) <= uVar4) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar3;
      uVar4 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0;
    *puVar7 = *puVar7 + 1;
  }
  return;
}

/* FUN_000738c0 @ 0x738c0 (2852 bytes) */
int FUN_000738c0(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint *param_2;
  int param_3;
  int *param_4;
  int param_5;
  uint *param_6;
{
  uint uVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined *puVar9;
  uint uVar10;
  undefined *puVar11;
  
  puVar9 = ((unsigned char *)0x00003210);
  switch(param_4[2]) {
  case 0x87d9:
    puVar9 = ((unsigned char *)0x00003218);
  case 0x87d5:
    break;
  case 0x87da:
    puVar9 = ((unsigned char *)0x00003218);
  case 0x87d6:
    puVar9 = (undefined *)((uint)puVar9 | 1);
    break;
  case 0x87db:
    puVar9 = ((unsigned char *)0x00003218);
  case 0x87d7:
    puVar9 = (undefined *)((uint)puVar9 | 2);
    break;
  case 0x87dc:
    puVar9 = ((unsigned char *)0x00003218);
  case 0x87d8:
    puVar9 = (undefined *)((uint)puVar9 | 3);
    break;
  case 0x87dd:
    puVar9 = ((unsigned char *)0x00003214);
    break;
  case 0x87de:
    puVar9 = ((unsigned char *)0x00003215);
  }
  switch(param_4[3]) {
  case 0x87d9:
    puVar9 = (undefined *)((uint)puVar9 | 0x80);
  case 0x87d5:
    puVar9 = (undefined *)((uint)puVar9 & 0xffffff8f);
    break;
  case 0x87da:
    puVar9 = (undefined *)((uint)puVar9 | 0x80);
  case 0x87d6:
    puVar9 = (undefined *)((uint)puVar9 & 0xffffff8f | 0x10);
    break;
  case 0x87db:
    puVar9 = (undefined *)((uint)puVar9 | 0x80);
  case 0x87d7:
    puVar9 = (undefined *)((uint)puVar9 & 0xffffff8f | 0x20);
    break;
  case 0x87dc:
    puVar9 = (undefined *)((uint)puVar9 | 0x80);
  case 0x87d8:
    puVar9 = (undefined *)((uint)puVar9 & 0xffffff8f | 0x30);
    break;
  case 0x87dd:
    puVar9 = (undefined *)((uint)puVar9 & 0xffffff8f | 0x40);
    break;
  case 0x87de:
    puVar9 = (undefined *)((uint)puVar9 & 0xffffff8f | 0x50);
  }
  switch(param_4[4]) {
  case 0x87d9:
    puVar9 = (undefined *)((uint)puVar9 | 0x800);
  case 0x87d5:
    puVar9 = (undefined *)((uint)puVar9 & 0xfffff8ff);
    break;
  case 0x87da:
    puVar9 = (undefined *)((uint)puVar9 | 0x800);
  case 0x87d6:
    puVar9 = (undefined *)((uint)puVar9 & 0xfffff8ff | 0x100);
    break;
  case 0x87db:
    puVar9 = (undefined *)((uint)puVar9 | 0x800);
  case 0x87d7:
    puVar9 = (undefined *)((uint)puVar9 & 0xfffff8ff | 0x200);
    break;
  case 0x87dc:
    puVar9 = (undefined *)((uint)puVar9 | 0x800);
  case 0x87d8:
    puVar9 = (undefined *)((uint)puVar9 & 0xfffff8ff | 0x300);
    break;
  case 0x87dd:
    puVar9 = (undefined *)((uint)puVar9 & 0xfffff8ff | 0x400);
    break;
  case 0x87de:
    puVar9 = (undefined *)((uint)puVar9 & 0xfffff8ff | 0x500);
  }
  switch(param_4[5]) {
  case 0x87d9:
    puVar9 = (undefined *)((uint)puVar9 | 0x8000);
  case 0x87d5:
    puVar9 = (undefined *)((uint)puVar9 & 0xffff8fff);
    break;
  case 0x87da:
    puVar9 = (undefined *)((uint)puVar9 | 0x8000);
  case 0x87d6:
    puVar9 = (undefined *)((uint)puVar9 & 0xffff8fff | 0x1000);
    break;
  case 0x87db:
    puVar9 = (undefined *)((uint)puVar9 | 0x8000);
  case 0x87d7:
    puVar9 = (undefined *)((uint)puVar9 & 0xffff8fff | 0x2000);
    break;
  case 0x87dc:
    puVar9 = (undefined *)((uint)puVar9 | 0x8000);
  case 0x87d8:
    puVar9 = (undefined *)((uint)puVar9 & 0xffff8fff | 0x3000);
    break;
  case 0x87dd:
    puVar9 = (undefined *)((uint)puVar9 & 0xffff8fff | 0x4000);
    break;
  case 0x87de:
    puVar9 = (undefined *)((uint)puVar9 & 0xffff8fff | 0x5000);
  }
  if (param_6 != (uint *)0x0) {
    uVar10 = *param_6;
    uVar2 = uVar10 & 3;
    if (uVar2 == 2) {
      puVar9 = (undefined *)((uint)puVar9 >> 8 & 7 | (uint)puVar9 & 0xfffffff8);
    }
    else if (uVar2 == 3) {
      puVar9 = (undefined *)((uint)puVar9 >> 0xc & 7 | (uint)puVar9 & 0xfffffff8);
    }
    else if (uVar2 == 1) {
      puVar9 = (undefined *)((uint)puVar9 >> 4 & 7 | (uint)puVar9 & 0xfffffff8);
    }
    uVar7 = param_6[1];
    uVar2 = uVar7 & 3;
    if (uVar2 != 1) {
      if (uVar2 == 0) {
        puVar9 = (undefined *)(((uint)puVar9 & 7) << 4 | (uint)puVar9 & 0xffffff8f);
      }
      else if (uVar2 == 2) {
        puVar9 = (undefined *)((uint)puVar9 >> 4 & 0x70 | (uint)puVar9 & 0xffffff8f);
      }
      else if (uVar2 == 3) {
        puVar9 = (undefined *)((uint)puVar9 >> 8 & 0x70 | (uint)puVar9 & 0xffffff8f);
      }
    }
    uVar1 = param_6[2];
    uVar2 = uVar1 & 3;
    if (uVar2 == 1) {
      puVar9 = (undefined *)(((uint)puVar9 & 0x70) << 4 | (uint)puVar9 & 0xfffff8ff);
    }
    else if (uVar2 == 0) {
      puVar9 = (undefined *)(((uint)puVar9 & 7) << 8 | (uint)puVar9 & 0xfffff8ff);
    }
    else if ((uVar2 != 2) && (uVar2 == 3)) {
      puVar9 = (undefined *)((uint)puVar9 >> 4 & 0x700 | (uint)puVar9 & 0xfffff8ff);
    }
    uVar6 = param_6[3];
    uVar2 = uVar6 & 3;
    if (uVar2 == 1) {
      puVar9 = (undefined *)(((uint)puVar9 & 0x70) << 8 | (uint)puVar9 & 0xffff8fff);
    }
    else if (uVar2 == 0) {
      puVar9 = (undefined *)(((uint)puVar9 & 7) << 0xc | (uint)puVar9 & 0xffff8fff);
    }
    else if (uVar2 == 2) {
      puVar9 = (undefined *)(((uint)puVar9 & 0x700) << 4 | (uint)puVar9 & 0xffff8fff);
    }
    if ((uVar10 & 4) != 0) {
      puVar9 = (undefined *)(((uint)puVar9 ^ 8) & 8 | (uint)puVar9 & 0xfffffff7);
    }
    if ((uVar7 & 4) != 0) {
      puVar9 = (undefined *)(((uint)puVar9 ^ 0x80) & 0x80 | (uint)puVar9 & 0xffffff7f);
    }
    if ((uVar1 & 4) != 0) {
      puVar9 = (undefined *)(((uint)puVar9 ^ 0x800) & 0x800 | (uint)puVar9 & 0xfffff7ff);
    }
    if ((uVar6 & 4) != 0) {
      puVar9 = (undefined *)(((uint)puVar9 ^ 0x8000) & 0x8000 | (uint)puVar9 & 0xffff7fff);
    }
    if ((uVar10 & 8) != 0) {
      puVar9 = (undefined *)((uint)puVar9 & 0xffff7777 | 0x100000);
    }
    if ((uVar7 & 8) != 0) {
      puVar9 = (undefined *)((uint)puVar9 & 0xffff7777 | 0x100000);
    }
    if ((uVar1 & 8) != 0) {
      puVar9 = (undefined *)((uint)puVar9 & 0xffff7777 | 0x100000);
    }
    if ((uVar6 & 8) != 0) {
      puVar9 = (undefined *)((uint)puVar9 & 0xffff7777 | 0x100000);
    }
  }
  puVar11 = puVar9;
  if (*param_4 != 2) {
    if (*param_4 != 0) {
      return 0;
    }
    uVar2 = 0x40000;
    goto LAB_00074014;
  }
  iVar5 = param_4[1] * 0x54 + *(int *)(param_3 + 0x20);
  uVar2 = *(uint *)(iVar5 + 0x28);
  iVar8 = *(int *)(iVar5 + 0x24);
  if (uVar2 < 0x87c4) {
    if (uVar2 < 0x87c2) {
      if (uVar2 != 0x87c1) {
        return 0;
      }
      if (iVar8 == 0x87bf) {
        uVar2 = *(uint *)(iVar5 + 4) & 0xffff | 0x50000;
        if ((*(char *)(iVar5 + 0x44) != '\0') && (*(int *)(iVar5 + 0x48) == 1)) {
          puVar11 = (undefined *)((uint)puVar9 & 0xffff8fff | 0x4000);
        }
      }
      else if (iVar8 == 0x87c0) {
        uVar2 = *(uint *)(iVar5 + 0x10) & 0xffff | 0x50000;
      }
      else {
        if (iVar8 != 0x87be) {
          return 0;
        }
        uVar10 = *(uint *)(iVar5 + 8);
        uVar2 = *(uint *)(iVar5 + 4) & 0xffff | 0x50000;
        puVar11 = (undefined *)
                  ((uVar10 & 7) << 0xc |
                  (uVar10 & 7) << 8 | (uVar10 & 7) << 4 | uVar10 & 7 | (uint)puVar9 & 0xffff8888);
        if ((*(char *)(iVar5 + 0x44) != '\0') && (*(int *)(iVar5 + 0x48) == 0xf)) {
          puVar11 = (undefined *)((uint)puVar9 & 0xffff8888 | 0x5441);
        }
      }
      goto LAB_00074014;
    }
    if (iVar8 == 0x87bf) {
      uVar2 = *(uint *)(iVar5 + 4) & 0xffff | 0x10000;
      goto LAB_00074014;
    }
    if (iVar8 == 0x87c0) {
      uVar2 = *(uint *)(iVar5 + 0x10) & 0xffff | 0x10000;
      goto LAB_00074014;
    }
    if (iVar8 != 0x87be) {
      return 0;
    }
    uVar10 = *(uint *)(iVar5 + 8);
    uVar2 = *(uint *)(iVar5 + 4);
    iVar5 = 1;
  }
  else {
    if (uVar2 != 0x87c4) {
      return 0;
    }
    if (iVar8 == 0x87bf) {
      uVar2 = *(uint *)(iVar5 + 4) & 0xffff | 0x40000;
      goto LAB_00074014;
    }
    if (iVar8 == 0x87c0) {
      uVar2 = *(uint *)(iVar5 + 0x10) & 0xffff | 0x40000;
      goto LAB_00074014;
    }
    if (iVar8 != 0x87be) {
      return 0;
    }
    uVar10 = *(uint *)(iVar5 + 8);
    uVar2 = *(uint *)(iVar5 + 4);
    iVar5 = 4;
  }
  uVar2 = uVar2 & 0xffff | iVar5 << 0x10;
  puVar11 = (undefined *)
            ((uVar10 & 7) << 0xc |
            (uVar10 & 7) << 8 | (uVar10 & 7) << 4 | uVar10 & 7 | (uint)puVar9 & 0xffff8888);
LAB_00074014:
  if ((param_5 == 0) && (puVar11 == ((unsigned char *)0x00003210))) {
    if (*(char *)(param_4 + 6) == '\0') {
      uVar10 = *param_2;
      if (param_2[1] <= uVar10) {
        pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if ((void *)param_2[2] != (void *)0x0) {
          _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = (uint)pvVar3;
        uVar10 = *param_2;
        param_2[1] = param_2[1] + 0x80;
      }
      uVar4 = 1;
      *(uint *)(uVar10 * 4 + param_2[2]) = uVar2;
      *param_2 = *param_2 + 1;
    }
    else {
      uVar10 = *param_2;
      if (param_2[1] <= uVar10) {
        pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if ((void *)param_2[2] != (void *)0x0) {
          _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = (uint)pvVar3;
        uVar10 = *param_2;
        param_2[1] = param_2[1] + 0x80;
      }
      *(uint *)(uVar10 * 4 + param_2[2]) = uVar2 | 0x800000;
      uVar2 = *param_2 + 1;
      *param_2 = uVar2;
      if (param_2[1] <= uVar2) {
        pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if ((void *)param_2[2] != (void *)0x0) {
          _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = (uint)pvVar3;
        uVar2 = *param_2;
        param_2[1] = param_2[1] + 0x80;
      }
      uVar4 = 2;
      *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0;
      *param_2 = *param_2 + 1;
    }
  }
  else if (*(char *)(param_4 + 6) == '\0') {
    uVar10 = *param_2;
    if (param_2[1] <= uVar10) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if ((void *)param_2[2] != (void *)0x0) {
        _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = (uint)pvVar3;
      uVar10 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    *(uint *)(uVar10 * 4 + param_2[2]) = uVar2 | 0x400000;
    uVar2 = *param_2 + 1;
    *param_2 = uVar2;
    if (param_2[1] <= uVar2) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if ((void *)param_2[2] != (void *)0x0) {
        _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = (uint)pvVar3;
      uVar2 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    uVar4 = 2;
    *(undefined **)(uVar2 * 4 + param_2[2]) = puVar11;
    *param_2 = *param_2 + 1;
  }
  else {
    uVar10 = *param_2;
    if (param_2[1] <= uVar10) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if ((void *)param_2[2] != (void *)0x0) {
        _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = (uint)pvVar3;
      uVar10 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    *(uint *)(uVar10 * 4 + param_2[2]) = uVar2 | 0xc00000;
    uVar2 = *param_2 + 1;
    *param_2 = uVar2;
    if (param_2[1] <= uVar2) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if ((void *)param_2[2] != (void *)0x0) {
        _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = (uint)pvVar3;
      uVar2 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    *(undefined **)(uVar2 * 4 + param_2[2]) = puVar11;
    uVar2 = *param_2 + 1;
    *param_2 = uVar2;
    if (param_2[1] <= uVar2) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if ((void *)param_2[2] != (void *)0x0) {
        _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = (uint)pvVar3;
      uVar2 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    uVar4 = 3;
    *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0;
    *param_2 = *param_2 + 1;
  }
  return uVar4;
}

