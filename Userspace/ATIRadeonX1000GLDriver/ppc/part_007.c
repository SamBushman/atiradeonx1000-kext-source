#include "decls.h"

/* FUN_000744d0 @ 0x744d0 (1412 bytes) */
int FUN_000744d0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint *param_2;
  int *param_3;
  int *param_4;
  int param_5;
{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = 0x55;
  iVar5 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_3);
  if (param_4[2] == 0) {
    uVar6 = 0x54;
  }
  iVar3 = param_4[3];
  if (iVar3 == 0) {
    uVar6 = uVar6 & 0xfffffff3;
  }
  if (param_4[4] == 0) {
    uVar6 = uVar6 & 0xffffffcf;
  }
  if (param_4[5] == 0) {
    uVar6 = uVar6 & 0xffffff3f;
  }
  if (*param_4 == 1) {
    uVar4 = param_4[1];
    if (uVar4 == 0x879b) {
      uVar6 = uVar6 | 0x100;
      *(undefined1 *)((int)param_3 + 0x6d) = 1;
      uVar7 = 0x120000;
    }
    else if (uVar4 < 0x879c) {
      if (uVar4 == 0x610f) {
        uVar6 = uVar6 | 0x100;
        *(undefined1 *)((int)param_3 + 0x6f) = 1;
        uVar7 = 0x120001;
      }
      else if (uVar4 < 0x6110) {
        if (uVar4 != 0x610e) {
          return 0;
        }
        *(undefined1 *)((int)param_3 + 0x79) = 1;
        uVar7 = 0xd0000;
        uVar6 = uVar6 & 0xffffff03;
      }
      else if (uVar4 == 0x6110) {
        uVar6 = uVar6 | 0x100;
        *(undefined1 *)(param_3 + 0x1c) = 1;
        uVar7 = 0x130001;
      }
      else {
        if (uVar4 != 0x879a) {
          return 0;
        }
        uVar7 = 0xe0000;
      }
    }
    else if (uVar4 < 0x87a5) {
      if (uVar4 < 0x879d) {
        uVar6 = uVar6 | 0x100;
        *(undefined1 *)((int)param_3 + 0x6e) = 1;
        uVar7 = 0x130000;
      }
      else {
        uVar7 = uVar4 + 0x7863 & 0xffff | 0x110000;
        if (param_4[2] == 1) {
          *(byte *)((int)param_3 + (uVar4 - 0x872c)) =
               *(byte *)((int)param_3 + (uVar4 - 0x872c)) | 1;
          iVar3 = param_4[3];
        }
        if (iVar3 == 1) {
          *(byte *)((int)param_3 + param_4[1] + -0x872c) =
               *(byte *)((int)param_3 + param_4[1] + -0x872c) | 2;
        }
        if (param_4[4] == 1) {
          *(byte *)((int)param_3 + param_4[1] + -0x872c) =
               *(byte *)((int)param_3 + param_4[1] + -0x872c) | 4;
        }
        if (param_4[5] == 1) {
          *(byte *)((int)param_3 + param_4[1] + -0x872c) =
               *(byte *)((int)param_3 + param_4[1] + -0x872c) | 8;
        }
      }
    }
    else {
      if (uVar4 != 0x87bd) {
        return 0;
      }
      uVar4 = *(uint *)(((unsigned char *)0x000013c0) + iVar5);
      *(undefined1 *)((int)param_3 + 0x7a) = 1;
      *(undefined1 *)(iVar5 + 0x33) = 1;
      uVar7 = uVar4 & 0xffff | 0x40000;
      uVar6 = uVar6 & 0xffffff03;
    }
  }
  else {
    if (*param_4 != 2) {
      return 0;
    }
    iVar5 = param_4[1] * 0x54 + param_3[8];
    iVar3 = *(int *)(iVar5 + 0x24);
    if (*(int *)(iVar5 + 0x28) == 0x87c4) {
      if (iVar3 == 0x87bf) {
        uVar7 = *(uint *)(iVar5 + 4) & 0xffff | 0x40000;
      }
      else if (iVar3 == 0x87c0) {
        uVar7 = *(uint *)(iVar5 + 0x10) & 0xffff | 0x40000;
      }
      else {
        if (iVar3 != 0x87be) {
          return 0;
        }
        iVar3 = *(int *)(iVar5 + 8);
        uVar7 = *(uint *)(iVar5 + 4) & 0xffff | 0x40000;
        if (iVar3 == 1) {
          uVar6 = uVar6 & 0xffffff0c;
        }
        else if (iVar3 == 0) {
          uVar6 = uVar6 & 0xffffff03;
        }
        else if (iVar3 == 2) {
          uVar6 = uVar6 & 0xffffff30;
        }
        else {
          if (iVar3 != 3) {
            return 0;
          }
          uVar6 = uVar6 & 0xffffffc0;
        }
      }
    }
    else {
      if (*(int *)(iVar5 + 0x28) != -1) {
        return 0;
      }
      uVar7 = 0x30000;
    }
  }
  if ((param_5 == 0) && (uVar6 == 0x55)) {
    uVar6 = *param_2;
    if (param_2[1] <= uVar6) {
      pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if ((void *)param_2[2] != (void *)0x0) {
        _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = (uint)pvVar1;
      uVar6 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    uVar2 = 1;
    *(uint *)(uVar6 * 4 + param_2[2]) = uVar7;
    *param_2 = *param_2 + 1;
  }
  else {
    uVar4 = *param_2;
    if (param_2[1] <= uVar4) {
      pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if ((void *)param_2[2] != (void *)0x0) {
        _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = (uint)pvVar1;
      uVar4 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    *(uint *)(uVar4 * 4 + param_2[2]) = uVar7 | 0x400000;
    uVar4 = *param_2 + 1;
    *param_2 = uVar4;
    if (param_2[1] <= uVar4) {
      pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if ((void *)param_2[2] != (void *)0x0) {
        _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = (uint)pvVar1;
      uVar4 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    uVar2 = 2;
    *(uint *)(uVar4 * 4 + param_2[2]) = uVar6;
    *param_2 = *param_2 + 1;
  }
  return uVar2;
}

/* FUN_00074a70 @ 0x74a70 (192 bytes) */
int FUN_00074a70(param_1, param_2, param_3, param_4)
  int param_1;
  uint *param_2;
  uint param_3;
  uint param_4;
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
  *(uint *)(uVar2 * 4 + param_2[2]) = (param_4 & 0x3fff) << 0x10 | param_3 & 0xffff;
  *param_2 = *param_2 + 1;
  return 1;
}

/* FUN_00074b30 @ 0x74b30 (204 bytes) */
int FUN_00074b30(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  param_2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,param_2,0x48,0);
  if (iVar1 != 0) {
    local_48 = *(undefined4 *)(param_4 + 4);
    local_44 = *(undefined4 *)(param_4 + 8);
    local_30 = *(undefined4 *)(param_4 + 0x1c);
    local_34 = 0;
    local_3c = 0;
    local_38 = 0;
    local_40 = 1;
    iVar1 = ((int (*)())FUN_000744d0)(param_1,param_2,param_3,&local_48,1);
    if ((iVar1 != 0) &&
       (iVar1 = FUN_000738c0(param_1,param_2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) {
      return 1;
    }
  }
  return 0xffffffff;
}

/* FUN_00076770 @ 0x76770 (352 bytes) */
int FUN_00076770(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int *param_3;
{
  short sVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  
  iVar4 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_3);
  if (*(int *)(iVar4 + 0x4c) == 0) {
    return;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(char *)((int)param_3 + 0x7a) != '\0') && (((unsigned char *)0x00002e0a)[iVar3] != '\0')) {
    sVar1 = *(short *)(((unsigned char *)0x00002e04) + iVar3);
    iVar6 = *(int *)(((unsigned char *)0x000013c4) + iVar4);
    if (sVar1 == 0x801) {
      fVar5 = 0.0;
      fVar2 = -(*(float *)(((unsigned char *)0x00002df0) + iVar3) * *(float *)(((unsigned char *)0x00002df0) + iVar3));
    }
    else if (sVar1 == 0x2601) {
      fVar5 = *(float *)(((unsigned char *)0x00002dfc) + iVar3) * *(float *)(((unsigned char *)0x00002df8) + iVar3);
      fVar2 = -*(float *)(((unsigned char *)0x00002dfc) + iVar3);
    }
    else {
      fVar5 = FLOAT_001aa0d4;
      fVar2 = FLOAT_001aa0d4;
      if (sVar1 == 0x800) {
        fVar5 = 0.0;
        fVar2 = -*(float *)(((unsigned char *)0x00002df0) + iVar3);
      }
    }
    iVar3 = iVar6 * 0x10;
    iVar7 = iVar3 + iVar4;
    *(undefined4 *)(*(int *)(iVar4 + 0x124) + iVar3) = 0;
    *(float *)(iVar3 + *(int *)(iVar4 + 0x124) + 4) = fVar5;
    *(float *)(iVar3 + *(int *)(iVar4 + 0x124) + 8) = fVar2;
    *(undefined4 *)(iVar3 + *(int *)(iVar4 + 0x124) + 0xc) = 0;
    *(undefined4 *)(iVar7 + 0x160) = 0;
    *(float *)(iVar7 + 0x158) = fVar5;
    *(float *)(iVar7 + 0x15c) = fVar2;
    *(undefined4 *)(iVar7 + 0x154) = 0;
    if (*(int *)(((unsigned char *)0x0000137c) + iVar4) < iVar6) {
      *(int *)(((unsigned char *)0x0000137c) + iVar4) = iVar6;
    }
  }
                    
                    
  (**(code **)((int)((unsigned char *)0x000012a0) + param_1))(param_1,iVar4 + 0x13c);
  return;
}

/* FUN_000768e0 @ 0x768e0 (384 bytes) */
int FUN_000768e0(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  
  if (*param_2 != 0) {
    iVar9 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    if ((*(char *)(param_2 + 4) != '\0') && ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0)) {
      iVar8 = iVar9 + 0x13c;
      if (iVar8 == *(int *)(((unsigned char *)0x0000148c) + param_1)) {
        (**(code **)((int)((unsigned char *)0x000012a0) + param_1))(param_1,iVar8);
      }
      else {
        (**(code **)((int)((unsigned char *)0x00001294) + param_1))(param_1,iVar8,*(undefined4 *)(iVar9 + 0x130));
      }
      (**(code **)(((unsigned char *)0x000012b4) + param_1))(param_1);
      if (*(int *)(iVar9 + 0x4c) != 0) {
        iVar4 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
        uVar2 = *(uint *)(iVar4 + 0x118);
        if (uVar2 != 0) {
          uVar3 = 0;
          do {
            iVar6 = *(int *)(((unsigned char *)0x0000137c) + iVar9);
            iVar1 = *(int *)(uVar3 * 4 + *(int *)(iVar4 + 0x114)) * 0x54 + param_2[8];
            puVar7 = *(undefined4 **)(iVar1 + 0x38);
            iVar1 = *(int *)(iVar1 + 4);
            iVar5 = iVar1 * 0x10 + iVar4;
            *(undefined4 *)(iVar5 + 0x154) = *puVar7;
            *(undefined4 *)(iVar5 + 0x158) = puVar7[1];
            *(undefined4 *)(iVar5 + 0x15c) = puVar7[2];
            *(undefined4 *)(iVar5 + 0x160) = puVar7[3];
            if (iVar6 < iVar1) {
              *(int *)(((unsigned char *)0x0000137c) + iVar9) = iVar1;
              uVar2 = *(uint *)(iVar4 + 0x118);
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < uVar2);
        }
        ((int (*)())FUN_00076770)(param_1,iVar8,param_2);
      }
      *(undefined4 *)(((unsigned char *)0x00001354) + param_1) = 0;
      *(undefined4 *)(((unsigned char *)0x0000134c) + param_1) = 0;
      *(undefined1 **)(((unsigned char *)0x00001350) + param_1) = ((unsigned char *)0x00077430);
    }
  }
  return;
}

/* FUN_00076ac0 @ 0x76ac0 (188 bytes) */
int FUN_00076ac0(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x44);
  uVar1 = (uint)*(byte *)(param_2 + 0x36) & uVar2 >> 7 & 1 |
          ((uint)*(byte *)(param_2 + 0x37) & uVar2 >> 6 & 1) << 1;
  if (*(char *)(param_2 + 0x33) != '\0') {
    if (*(char *)(param_2 + 0x30) != '\0') {
      uVar1 = uVar1 | uVar2 >> 10 & 4;
    }
    if ((uVar2 & 0x800) != 0) {
      uVar1 = (uint)(byte)((unsigned char *)0x000011d1)[param_1] << 7 | uVar1 | 8;
    }
  }
  if (*(char *)(param_2 + 0x2e) == '\0') {
    uVar2 = *(uint *)(param_1 + 0x44);
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x44);
    if ((uVar2 & 0x400) != 0) {
      uVar1 = uVar1 | (uint)(byte)((unsigned char *)0x000011d2)[param_1] << 0x14 | 0x10;
    }
  }
  if ((uVar2 & 0x2000) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  return uVar1 | (uint)(byte)((unsigned char *)0x00002e0a)[*(int *)(*(int *)(param_1 + 4) + 0x10)] << 6;
}

/* FUN_00076b80 @ 0x76b80 (116 bytes) */
int FUN_00076b80(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar3 = *piVar2;
  uVar1 = ((int (*)())FUN_00076ac0)(param_1,iVar3);
  *(uint *)(iVar3 + 0x38) = uVar1;
  *(int *)(iVar3 + 0x138) = piVar2[(uVar1 & 0x1f) + 1];
  piVar2[(uVar1 & 0x1f) + 1] = iVar3;
  *(undefined1 *)(iVar3 + 0x134) = 1;
  piVar2[0x21] = piVar2[0x21] + 1;
  return;
}

/* FUN_00076c10 @ 0x76c10 (72 bytes) */
int FUN_00076c10(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = *(int *)((param_2 & 0x1f) * 4 + param_1 + 4);
  if (iVar1 != 0) {
    if (param_2 == *(uint *)(iVar1 + 0x38)) {
      return iVar1;
    }
    while (iVar1 = *(int *)(iVar1 + 0x138), iVar1 != 0) {
      if (param_2 == *(uint *)(iVar1 + 0x38)) {
        return iVar1;
      }
    }
  }
  return 0;
}

/* FUN_00076c60 @ 0x76c60 (480 bytes) */
int FUN_00076c60(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  iVar3 = *(int *)(((unsigned char *)0x0000148c) + param_1);
  piVar6 = *(int **)(((unsigned char *)0x00001168) + param_1);
  if ((*(uint *)(param_1 + 0x44) & 0x100000) == 0) {
                    
                    
    (**(code **)(((unsigned char *)0x000012a4) + param_1))(param_1,piVar6,1);
    return;
  }
  iVar7 = *(int *)(((unsigned char *)0x0000118c) + param_1);
  piVar4 = *(int **)(iVar7 * 4 + *piVar6);
  iVar5 = *piVar4;
  iVar2 = ((int (*)())FUN_00076ac0)(param_1,iVar5);
  if (((*(char *)(piVar6[1] + iVar7) == '\0') && (iVar2 == *(int *)(iVar5 + 0x38))) &&
     (*(int *)(iVar5 + 4) == piVar6[0x15])) {
    if ((*(byte *)(param_1 + 0x2d) & 4) == 0) {
      bVar1 = iVar5 == 0;
      if ((*(byte *)(param_1 + 0x2d) & 3) != 0) {
        ((int (*)())FUN_00076770)(param_1,iVar5 + 0x13c,piVar6);
      }
      goto LAB_00076dc0;
    }
    bVar1 = iVar5 == 0;
  }
  else {
    iVar5 = ((int (*)())FUN_00076c10)(piVar4,iVar2);
    bVar1 = iVar5 == 0;
    if ((bVar1) || (*(char *)(piVar6[1] + *(int *)(((unsigned char *)0x0000118c) + param_1)) != '\0')) {
      FUN_000546d0(param_1,piVar6);
    }
    else {
      *piVar4 = iVar5;
      piVar6[0x15] = *(int *)(iVar5 + 4);
      *(undefined4 *)(((unsigned char *)0x00001174) + param_1) = *(undefined4 *)(iVar5 + 4);
    }
    *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 3;
  }
  ((int (*)())FUN_000768e0)(param_1,piVar6);
  (**(code **)(((unsigned char *)0x000012a4) + param_1))(param_1,piVar6,0);
LAB_00076dc0:
  (**(code **)(((unsigned char *)0x000012b4) + param_1))(param_1);
  if ((!bVar1) && (iVar3 != iVar5 + 0x13c)) {
                    
                    
    (**(code **)((int)((unsigned char *)0x00001294) + param_1))
              (param_1,iVar5 + 0x13c,*(undefined4 *)(iVar5 + 0x130));
    return;
  }
  return;
}

/* FUN_00076e70 @ 0x76e70 (356 bytes) */
int FUN_00076e70(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = param_2 + 0x13c;
  if ((iVar1 != 0) && (*(int *)(param_2 + 0x150) != 0)) {
    (**(code **)(((unsigned char *)0x000012ac) + param_1))(param_1,iVar1);
  }
  if (*(int *)(param_2 + 8) != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  if (*(int *)(param_2 + 0x10) != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  if (*(int *)(param_2 + 0x3c) != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  if (*(int *)(param_2 + 0x44) != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  if (*(int *)(param_2 + 0x114) != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  if (*(int *)(param_2 + 0x11c) != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  if (*(int *)(((unsigned char *)0x000013d8) + param_2) != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  if (*(int *)(param_2 + 0x124) != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  if (iVar1 == *(int *)(((unsigned char *)0x0000148c) + param_1)) {
    *(undefined4 *)(((unsigned char *)0x0000148c) + param_1) = 0;
  }
                    
                    
  (**(code **)(param_1 + 0x18))(param_2);
  return;
}

/* FUN_000774c0 @ 0x774c0 (156 bytes) */
int FUN_000774c0(param_1, param_2)
  code *param_1;
  undefined4 param_2;
{
  void *pvVar1;
  
  pvVar1 = (void *)(*param_1)(((unsigned char *)0x000359a4));
  if (pvVar1 != (void *)0x0) {
    _memset(pvVar1,0,0x359a4);
    *(void **)((int)pvVar1 + 0x34) = pvVar1;
    *(undefined4 *)((int)pvVar1 + 0x12458) = param_2;
    *(code **)((int)pvVar1 + 0x12454) = param_1;
    *(undefined4 *)((int)pvVar1 + 0x359a0) = 0xdeaddead;
    _memset((void *)((int)pvVar1 + 0x38),0,0x1241c);
    *(undefined4 *)((int)pvVar1 + 0x3c) = param_2;
    *(code **)((int)pvVar1 + 0x38) = param_1;
  }
  return pvVar1;
}

/* FUN_00077560 @ 0x77560 (228 bytes) */
int FUN_00077560(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  
  iVar2 = param_2 * 4 + param_1;
  if (*(uint *)(iVar2 + 0x10454) < param_3) {
    *(uint *)(iVar2 + 0x10454) = param_3;
  }
  if ((*(uint *)(iVar2 + 0x3348c) & 0x10000) == 0) {
    iVar3 = *(int *)(param_1 + 0x26870);
    *(uint *)(iVar2 + 0x3348c) = *(uint *)(iVar2 + 0x3348c) | 0x10000;
    uVar4 = 0;
    piVar5 = (int *)(param_2 * 0xc + param_1 + 0x450);
    *(int *)(param_1 + 0x26870) = iVar3 + 1;
    *(int *)(((unsigned char *)0x00024870) + iVar3 * 4 + param_1) = param_2;
    do {
      if ((1 << (uVar4 & 0x3f) & *(uint *)(iVar2 + 0x6450)) != 0) {
        for (puVar6 = (undefined4 *)*piVar5; puVar6 != (undefined4 *)0x0;
            puVar6 = (undefined4 *)puVar6[4]) {
          ((int (*)())FUN_00077560)(param_1,*puVar6,param_3 + 1);
        }
      }
      bVar1 = uVar4 != 2;
      piVar5 = piVar5 + 1;
      uVar4 = uVar4 + 1;
    } while (bVar1);
  }
  return;
}

/* FUN_00077650 @ 0x77650 (76 bytes) */
int FUN_00077650(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 == 0) {
    return;
  }
  if (param_2 != 0) {
    if (iVar2 == param_2) {
      *param_1 = *(int *)(iVar2 + 0x10);
      return;
    }
    do {
      iVar1 = *(int *)(iVar2 + 0x10);
      if (param_2 == iVar1) {
        *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(param_2 + 0x10);
        return;
      }
      iVar2 = iVar1;
    } while (iVar1 != 0);
    return;
  }
  return;
}

/* FUN_000776b0 @ 0x776b0 (176 bytes) */
int FUN_000776b0(param_1)
  int param_1;
{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x30c20) = 0;
  if ((**(uint **)(param_1 + 0x34) & 0x40) == 0) {
    *(undefined4 *)(param_1 + 0x30c24) = 0;
    puVar2 = (undefined4 *)(param_1 + 0x30c28);
    iVar3 = 0;
    do {
      bVar1 = iVar3 != 1;
      *puVar2 = 0;
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (bVar1);
    puVar2 = (undefined4 *)(param_1 + 0x30c30);
    iVar3 = 6;
    do {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *(undefined4 *)(((unsigned char *)0x00030c4c) + param_1) = 0;
    *(undefined4 *)(((unsigned char *)0x00030c48) + param_1) = 0;
  }
  else {
    puVar2 = (undefined4 *)(param_1 + 0x31450);
    iVar3 = 0xf;
    do {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  puVar2 = (undefined4 *)(param_1 + 0x30ba0);
  iVar3 = 0x20;
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

/* FUN_00077760 @ 0x77760 (72 bytes) */
int FUN_00077760(param_1, param_2, param_3)
  uint param_1;
  uint *param_2;
  int param_3;
{
  uint uVar1;
  undefined4 *puVar2;
  
  uVar1 = *param_2 - 1;
  if (param_1 < uVar1) {
    puVar2 = (undefined4 *)(param_3 + param_1 * 4);
    do {
      param_1 = param_1 + 1;
      *puVar2 = puVar2[1];
      puVar2 = puVar2 + 1;
      uVar1 = *param_2 - 1;
    } while (param_1 < uVar1);
  }
  *param_2 = uVar1;
  return;
}

/* FUN_000777b0 @ 0x777b0 (56 bytes) */
int FUN_000777b0(param_1, param_2)
  uint *param_1;
  int param_2;
{
  uint uVar1;
  
  uVar1 = *param_1 & 0xf00;
  if ((uVar1 != 0) && (((uVar1 != 0x400 && (uVar1 != 0x500)) || (param_2 == 0)))) {
    return 0;
  }
  return 1;
}

/* FUN_00077800 @ 0x77800 (64 bytes) */
int FUN_00077800(param_1, param_2)
  uint *param_1;
  int param_2;
{
  if ((*param_1 & 0xf00) == 0x300) {
    if (param_2 == 0) {
      return 1;
    }
  }
  else if (((*param_1 & 0xf00) == 0x100) && (param_2 != 0)) {
    return 1;
  }
  return 0;
}

/* FUN_00077850 @ 0x77850 (12 bytes) */
int FUN_00077850(param_1)
  uint *param_1;
{
  return *param_1 >> 0x14 & 0xf;
}

/* FUN_00077860 @ 0x77860 (792 bytes) */
int FUN_00077860(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  
  iVar3 = *(int *)(((unsigned char *)0x00024870) + param_3 * 4 + param_1) * 0x10;
  puVar8 = (uint *)(iVar3 + param_2);
  if (param_4 == 0) {
    switch(*(uint *)(param_2 + iVar3) >> 8 & 0xf) {
    case 0:
      puVar9 = (uint *)(param_1 + 0x30ba0 + (*puVar8 >> 0xb & 0x1fc));
      break;
    default:
      goto switchD_000778cc_caseD_1;
    case 3:
      puVar9 = (uint *)(param_1 + 0x30c20 + (*puVar8 >> 0xb & 0x1fc));
      break;
    case 4:
      puVar9 = (uint *)(param_1 + 0x30c24 + (*puVar8 >> 0xb & 0x1fc));
      break;
    case 5:
      puVar9 = (uint *)(param_1 + 0x30c28 + (*puVar8 >> 0xb & 0x1fc));
      break;
    case 6:
      puVar9 = (uint *)(param_1 + 0x30c30 + (*puVar8 >> 0xb & 0x1fc));
      break;
    case 7:
      puVar9 = (uint *)(((unsigned char *)0x00030c48) + (*puVar8 >> 0xb & 0x1fc) + param_1);
      break;
    case 8:
      puVar9 = (uint *)(((unsigned char *)0x00030c4c) + (*puVar8 >> 0xb & 0x1fc) + param_1);
    }
  }
  else {
    uVar4 = *(uint *)(param_2 + iVar3);
    uVar2 = uVar4 >> 8 & 0xf;
    if (uVar2 < 6) {
      uVar2 = 1 << uVar2;
      if ((uVar2 & 0x31) != 0) {
        puVar9 = (uint *)(param_1 + 0x30ba0 + (uVar4 >> 0xb & 0x1fc));
        goto LAB_000779d4;
      }
      if ((uVar2 & 2) != 0) {
        puVar9 = (uint *)(param_1 + 0x30c20 + (uVar4 >> 0xb & 0x1fc));
        goto LAB_000779d4;
      }
      if ((uVar2 & 0xc) != 0) {
        puVar9 = (uint *)(param_1 + 0x31450 + (uVar4 >> 0xb & 0x1fc));
        goto LAB_000779d4;
      }
    }
switchD_000778cc_caseD_1:
    puVar9 = (uint *)0x0;
  }
LAB_000779d4:
  iVar3 = ((int (*)())FUN_000777b0)(puVar8,param_4);
  if ((iVar3 == 0) && (iVar3 = ((int (*)())FUN_00077800)(puVar8,param_4), iVar3 == 0)) {
    uVar4 = ((int (*)())FUN_00077850)(puVar8);
    uVar2 = *puVar9;
    *puVar9 = uVar4 | uVar2;
    if ((uVar2 & uVar4 & 0xff) != 0) {
      return 0;
    }
  }
  uVar2 = 0;
  uVar4 = *(uint *)(((unsigned char *)0x00024870) + param_3 * 4 + param_1);
  piVar7 = (int *)(uVar4 * 0xc + param_1 + 0x450);
  do {
    if ((*(uint *)(uVar4 * 4 + param_1 + 0x6450) & 1 << (uVar2 & 0x3f)) != 0) {
      for (piVar6 = (int *)*piVar7; piVar6 != (int *)0x0; piVar6 = (int *)piVar6[4]) {
        if ((*(uint *)(*piVar6 * 4 + param_1 + 0x3348c) & 0x40000) == 0) {
          return 0;
        }
      }
    }
    bVar1 = uVar2 != 2;
    piVar7 = piVar7 + 1;
    uVar2 = uVar2 + 1;
  } while (bVar1);
  iVar3 = ((int (*)())FUN_000777b0)(puVar8,param_4);
  if ((iVar3 != 0) && (puVar9 = *(uint **)(uVar4 * 4 + param_1 + 0xe450), puVar9 != (uint *)0x0)) {
    uVar2 = ((int (*)())FUN_00077850)(puVar8);
    do {
      uVar10 = *puVar9;
      uVar5 = ((int (*)())FUN_00077850)(param_2 + uVar10 * 0x10);
      if ((((uVar2 & uVar5) != 0) && (uVar10 < uVar4)) &&
         ((*(uint *)(uVar10 * 4 + param_1 + 0x3348c) & 0x40000) == 0)) {
        return 0;
      }
      puVar9 = (uint *)puVar9[4];
    } while (puVar9 != (uint *)0x0);
  }
  return 1;
}

/* FUN_00077ba0 @ 0x77ba0 (140 bytes) */
int FUN_00077ba0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 4;
  uVar4 = 0;
  piVar2 = (int *)(param_3 * 0x10 + param_1 + 0x2d87c);
  do {
    uVar3 = 1 << (uVar4 & 0x3f);
    if ((uVar3 & param_4) != 0) {
      bVar1 = *(byte *)(param_3 + param_1 + 0x3087c);
      if (((int)(char)bVar1 >> (uVar4 & 0x3f) & 1U) == 0) {
        *piVar2 = param_2;
        *(byte *)(param_3 + param_1 + 0x3087c) = (byte)uVar3 | bVar1;
      }
      else if ((param_2 != *piVar2) && (param_5 != 0)) {
        return 6;
      }
    }
    uVar4 = uVar4 + 1;
    piVar2 = piVar2 + 1;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      return 0;
    }
  } while( true );
}

/* FUN_00077c40 @ 0x77c40 (124 bytes) */
int FUN_00077c40(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  uint param_3;
  int param_4;
{
  byte bVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  iVar5 = 4;
  piVar3 = (int *)(param_1 + 0x30b8c);
  do {
    uVar2 = 1 << (uVar4 & 0x3f);
    if ((uVar2 & param_3) != 0) {
      bVar1 = *(byte *)(param_1 + 0x30b9c);
      if (((int)(char)bVar1 >> (uVar4 & 0x3f) & 1U) == 0) {
        *piVar3 = param_2;
        *(byte *)(param_1 + 0x30b9c) = (byte)uVar2 | bVar1;
      }
      else if ((param_2 != *piVar3) && (param_4 != 0)) {
        return 6;
      }
    }
    uVar4 = uVar4 + 1;
    piVar3 = piVar3 + 1;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      return 0;
    }
  } while( true );
}

/* FUN_00077cd0 @ 0x77cd0 (24 bytes) */
int FUN_00077cd0(param_1)
  uint *param_1;
{
  return (*param_1 & 0xf) == 1;
}

/* FUN_00077cf0 @ 0x77cf0 (20 bytes) */
int FUN_00077cf0(param_1)
  uint *param_1;
{
  return (*param_1 & 0xf00) == 0;
}

/* FUN_00077d10 @ 0x77d10 (120 bytes) */
int FUN_00077d10(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = ((int (*)())FUN_00077850)(param_1 + 0x1286c + param_2 * 0x10);
  for (iVar1 = *(int *)(param_2 * 4 + param_1 + 0xc450); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10))
  {
    uVar2 = uVar2 | *(uint *)(iVar1 + 4);
  }
  return uVar2;
}

/* FUN_00077d90 @ 0x77d90 (1176 bytes) */
int FUN_00077d90(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  uint param_5;
  uint param_6;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint *puVar15;
  int *piVar16;
  int iVar17;
  int iVar18;
  int local_68 [4];
  uint local_58 [7];
  
  iVar3 = param_3 * 0x10;
  iVar17 = 4;
  puVar4 = (uint *)(iVar3 + param_1 + 0x2d87c);
  uVar12 = 0;
  do {
    if (((param_6 & 1 << (uVar12 & 0x3f)) == 0) ||
       ((((int)*(char *)(param_3 + param_1 + 0x3087c) >> (uVar12 & 0x3f) & 1U) != 0 &&
        (param_5 == *puVar4)))) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    uVar12 = uVar12 + 1;
    iVar17 = iVar17 + -1;
    if (iVar17 == 0) {
      if (!bVar2) {
        return 0;
      }
      break;
    }
    puVar4 = puVar4 + 1;
  } while (!bVar2);
  uVar12 = (uint)*(char *)(param_3 + param_1 + 0x3087c);
  if ((uVar12 & param_4) == 0) {
    return 0;
  }
  uVar10 = 0;
  bVar2 = false;
  iVar17 = 4;
  puVar5 = (undefined4 *)(iVar3 + param_1 + 0x2a87c);
  do {
    uVar13 = 1 << (uVar10 & 0x3f);
    if (((((uVar13 & uVar12) != 0) && (puVar4 = (uint *)*puVar5, puVar4 != (uint *)0x0)) &&
        (param_5 == *puVar4)) && (puVar4[1] == 0)) {
      uVar12 = uVar12 & ~uVar13;
      bVar2 = true;
    }
    uVar10 = uVar10 + 1;
    puVar5 = puVar5 + 1;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  if ((uVar12 != 0) && (bVar2)) {
    iVar17 = 0;
    uVar10 = 0;
    bVar2 = false;
    piVar11 = (int *)(iVar3 + param_1 + 0x2d87c);
    do {
      if ((1 << (uVar10 & 0x3f) & uVar12) != 0) {
        if (bVar2) {
          iVar14 = *piVar11;
          iVar6 = 0;
          iVar18 = iVar17;
          do {
            piVar16 = local_68 + iVar6;
            iVar18 = iVar18 + -1;
            if (iVar18 == 0) {
              if (*piVar16 != iVar14) goto LAB_00077f68;
              break;
            }
            iVar6 = iVar6 + 1;
          } while (*piVar16 != iVar14);
        }
        else {
          iVar14 = *piVar11;
LAB_00077f68:
          local_68[iVar17] = iVar14;
          bVar2 = 0 < iVar17 + 1;
          iVar17 = iVar17 + 1;
        }
      }
      bVar1 = uVar10 != 3;
      piVar11 = piVar11 + 1;
      uVar10 = uVar10 + 1;
    } while (bVar1);
    if (bVar2) {
      iVar14 = 0;
      uVar10 = 0;
      piVar11 = local_68;
      do {
        iVar6 = *piVar11;
        piVar11 = piVar11 + 1;
        if (iVar6 != -1) {
          for (puVar4 = *(uint **)(iVar6 * 4 + param_1 + 0xc450); puVar4 != (uint *)0x0;
              puVar4 = (uint *)puVar4[4]) {
            uVar13 = *puVar4;
            if ((*(uint *)(uVar13 * 4 + param_1 + 0x3348c) & 0x40000) == 0) {
              uVar8 = ((int (*)())FUN_00077850)(uVar13 * 0x10 + param_2);
              uVar9 = 0;
              puVar15 = local_58;
              iVar6 = 4;
              do {
                uVar7 = 1 << (uVar9 & 0x3f);
                if ((uVar8 & uVar7 & ~uVar12) != 0) {
                  if ((uVar7 & uVar10) == 0) {
                    *puVar15 = uVar13;
                    uVar10 = uVar10 | uVar7;
                  }
                  else if (uVar13 < *puVar15) {
                    *puVar15 = uVar13;
                  }
                }
                uVar9 = uVar9 + 1;
                puVar15 = puVar15 + 1;
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
            }
          }
        }
        iVar14 = iVar14 + 1;
      } while (iVar14 != iVar17);
      if (uVar10 != 0) {
        uVar13 = 0;
        puVar4 = local_58;
        iVar17 = 4;
        do {
          uVar8 = 1 << (uVar13 & 0x3f);
          if (((uVar8 & uVar10) != 0) && (param_5 == *puVar4)) {
            uVar10 = uVar10 & ~uVar8;
          }
          uVar13 = uVar13 + 1;
          puVar4 = puVar4 + 1;
          iVar17 = iVar17 + -1;
        } while (iVar17 != 0);
      }
      goto LAB_000780d4;
    }
  }
  uVar10 = 0;
LAB_000780d4:
  if (((param_4 & uVar12) == 0) && ((uVar10 & param_4) != 0)) {
    return 1;
  }
  param_4 = param_4 & (uVar10 | uVar12);
  if (param_4 != 0) {
    uVar12 = 0;
    puVar4 = (uint *)(iVar3 + param_1 + 0x2d87c);
    do {
      uVar10 = 1 << (uVar12 & 0x3f);
      if ((uVar10 & param_4) != 0) {
        if ((param_6 & uVar10) == 0) {
          puVar15 = *(uint **)(param_5 * 4 + param_1 + 0xc450);
          if (puVar15 != (uint *)0x0) {
            do {
              if (*puVar15 == *puVar4) {
                param_4 = param_4 & ~uVar10;
              }
              puVar15 = (uint *)puVar15[4];
            } while (puVar15 != (uint *)0x0);
          }
        }
        else if (param_5 == *puVar4) {
          param_4 = param_4 & ~uVar10;
        }
      }
      bVar2 = uVar12 != 3;
      puVar4 = puVar4 + 1;
      uVar12 = uVar12 + 1;
    } while (bVar2);
    if (param_4 != 0) {
      uVar12 = 0;
      piVar11 = (int *)(iVar3 + param_1 + 0x2d87c);
      do {
        uVar10 = 1 << (uVar12 & 0x3f);
        if ((((uVar10 & param_4) != 0) && ((uVar10 & param_6) == 0)) &&
           (piVar16 = *(int **)(param_5 * 4 + param_1 + 0xe450), piVar16 != (int *)0x0)) {
          do {
            if (*piVar16 == *piVar11) {
              param_4 = param_4 & ~uVar10;
            }
            piVar16 = (int *)piVar16[4];
          } while (piVar16 != (int *)0x0);
        }
        bVar2 = uVar12 != 3;
        piVar11 = piVar11 + 1;
        uVar12 = uVar12 + 1;
      } while (bVar2);
      if (param_4 != 0) {
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_00078250 @ 0x78250 (132 bytes) */
int FUN_00078250(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = ((int (*)())FUN_00077d90)(param_1,param_2,iVar3 + 0x200,param_3,param_4,param_5);
    if (iVar2 == 0) {
      return iVar3 + 0x200;
    }
    bVar1 = iVar3 != 3;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  return -1;
}

/* FUN_000782e0 @ 0x782e0 (20 bytes) */
int FUN_000782e0(param_1)
  uint *param_1;
{
  return (*param_1 & 0xf) == 0;
}

/* FUN_00078300 @ 0x78300 (200 bytes) */
int FUN_00078300(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 3);
  switch(cVar1) {
  case '\0':
  case '@':
    return 0;
  case '\x01':
  case '\x02':
  case '\x03':
  case '\x05':
  case '\a':
  case '\b':
  case '\t':
  case '\n':
switchD_00078334_caseD_1:
    return 3;
  case '\x04':
  case '\v':
  case '\f':
  case -0x80:
switchD_00078334_caseD_4:
    return 7;
  case '\x06':
  case '\r':
  case '\x0e':
  case 'A':
  case 'B':
  case 'F':
  case 'G':
  case 'H':
  case 'I':
  case 'K':
  case 'L':
  case 'P':
  case 'Q':
    goto switchD_00078334_caseD_6;
  default:
    if (param_2 != 0) {
      switch(cVar1) {
      case 'C':
        return 4;
      case 'D':
      case 'M':
      case 'N':
      case -0x7f:
        goto switchD_00078334_caseD_4;
      case 'E':
      case 'O':
        return 5;
      default:
        goto switchD_000785b4_caseD_46;
      case 'J':
        goto switchD_00078334_caseD_1;
      }
    }
    if ((7 < (byte)(cVar1 + 0xbdU)) || ((1 << ((int)(char)(cVar1 + -0x43) & 0x3fU) & 0x87U) == 0)) {
switchD_000785b4_caseD_46:
      return 0xffffffff;
    }
switchD_00078334_caseD_6:
    return 1;
  }
}

/* FUN_00078700 @ 0x78700 (84 bytes) */
int FUN_00078700(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  
  param_2 = param_2 * 4;
  iVar1 = param_1 + 0x3348c;
  piVar2 = *(int **)(param_2 + param_1 + 0xc450);
  *(uint *)(iVar1 + param_2) = *(uint *)(iVar1 + param_2) | 0x2000;
  if (piVar2 != (int *)0x0) {
    do {
      *(uint *)(iVar1 + *piVar2 * 4) = *(uint *)(iVar1 + *piVar2 * 4) | 0x2000;
      piVar2 = (int *)piVar2[4];
    } while (piVar2 != (int *)0x0);
    return;
  }
  return;
}

/* FUN_00078760 @ 0x78760 (448 bytes) */
int FUN_00078760(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  char *param_4;
  int *param_5;
{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint *puVar7;
  
  puVar7 = (uint *)(param_3 * 0x10 + param_2);
  uVar2 = ((int (*)())FUN_00077d10)(param_1,param_3);
  uVar3 = ((int (*)())FUN_00077850)(puVar7);
  uVar5 = *(uint *)(param_3 * 0x10 + param_2);
  if ((uVar5 & 0xf00) == 0x400) {
    iVar4 = ((int (*)())FUN_00077d90)(param_1,param_2,
                         (char)(DAT_001aa758)[uVar5 >> 8 & 0xf] * 0x100 + (uVar5 >> 0xd & 0x7f),
                         uVar2,param_3,uVar3);
    if (iVar4 == 0) {
      *param_4 = '\0';
      return true;
    }
  }
  else {
    piVar6 = *(int **)(param_3 * 4 + param_1 + 0xa450);
    if (piVar6 != (int *)0x0) {
      cVar1 = *(char *)(*piVar6 * 4 + param_1 + 0x3148d);
      while( true ) {
        if ('\0' < cVar1) {
          ((int (*)())FUN_00078700)(param_1,param_3);
          return false;
        }
        piVar6 = (int *)piVar6[4];
        if (piVar6 == (int *)0x0) break;
        cVar1 = *(char *)(*piVar6 * 4 + param_1 + 0x3148d);
      }
    }
  }
  iVar4 = ((int (*)())FUN_00078250)(param_1,param_2,uVar2,param_3,uVar3);
  *param_5 = iVar4;
  if (iVar4 == -1) {
    ((int (*)())FUN_00078700)(param_1,param_3);
    *param_4 = '\0';
  }
  else {
    uVar5 = *puVar7;
    *param_4 = '\x01' - ((char)(DAT_001aa758)[uVar5 >> 8 & 0xf] * 0x100 + (uVar5 >> 0xd & 0x7f) ==
                        iVar4);
  }
  return iVar4 != -1;
}

/* FUN_00078950 @ 0x78950 (64 bytes) */
int FUN_00078950(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 + 0x3348c;
  iVar2 = *(int *)(((unsigned char *)0x00035498) + param_1);
  *(uint *)(iVar1 + *(int *)(((unsigned char *)0x00035494) + param_1) * 4) =
       *(uint *)(iVar1 + *(int *)(((unsigned char *)0x00035494) + param_1) * 4) | 0x100;
  *(uint *)(iVar1 + iVar2 * 4) = *(uint *)(iVar1 + iVar2 * 4) | 0x100;
  *(int *)(((unsigned char *)0x0003548c) + param_1) = *(int *)(((unsigned char *)0x0003548c) + param_1) + 1;
  return;
}

/* FUN_00078a10 @ 0x78a10 (356 bytes) */
int FUN_00078a10(param_1, param_2, param_3)
  int param_1;
  char *param_2;
  uint *param_3;
{
  bool bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_28 [7];
  
  uVar4 = ((int (*)())FUN_00078300)(param_3,**(uint **)(param_1 + 0x34) >> 6 & 1);
  uVar7 = 0;
  param_2[0] = '\0';
  param_2[1] = '\0';
  param_2[2] = '\0';
  param_2[3] = '\0';
  puVar5 = local_28;
  do {
    param_3 = param_3 + 1;
    if ((uVar4 & 1 << (uVar7 & 0x3f)) == 0) {
      *puVar5 = 0x501;
    }
    else {
      uVar6 = (char)(DAT_001aa760)[*param_3 & 0xf] * 0x100 + (*param_3 >> 5 & 0xff);
      *puVar5 = uVar6;
      if (uVar7 != 0) {
        bVar1 = true;
        puVar3 = local_28;
        uVar8 = uVar7;
        do {
          uVar2 = *puVar3;
          puVar3 = puVar3 + 1;
          if (uVar6 == uVar2) {
            bVar1 = false;
          }
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
        if (!bVar1) goto LAB_00078b54;
      }
      uVar6 = uVar6 >> 8;
      if (uVar6 == 1) {
        param_2[3] = param_2[3] + '\x01';
      }
      else if (uVar6 == 0) {
        *param_2 = *param_2 + '\x01';
      }
      else if (uVar6 == 2) {
        param_2[1] = param_2[1] + '\x01';
      }
      else if (uVar6 == 4) {
        param_2[2] = param_2[2] + '\x01';
      }
    }
LAB_00078b54:
    bVar1 = uVar7 == 2;
    puVar5 = puVar5 + 1;
    uVar7 = uVar7 + 1;
    if (bVar1) {
      return;
    }
  } while( true );
}

/* FUN_00078b80 @ 0x78b80 (560 bytes) */
int FUN_00078b80(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  int local_68 [9];
  
  iVar7 = param_1 + 0x1286c;
  uVar5 = *(uint *)(iVar7 + param_2 * 0x10);
  uVar8 = (uint)(char)(DAT_001aa764)[param_3 >> 8];
  if ((char)(DAT_001aa758)[uVar5 >> 8 & 0xf] * 0x100 + (uVar5 >> 0xd & 0x7f) != param_3) {
    *(uint *)(iVar7 + param_2 * 0x10) =
         (param_3 & 0x7f) << 0xd | (uVar8 & 0xf) << 8 | uVar5 & 0xfff010ff;
    piVar9 = *(int **)(param_2 * 4 + param_1 + 0xa450);
    if (piVar9 != (int *)0x0) {
      do {
        iVar2 = *piVar9;
        uVar12 = 0;
        piVar10 = local_68;
        iVar11 = iVar2 * 0x10 + iVar7;
        uVar5 = *(uint *)(iVar2 * 4 + param_1 + 0x6450);
        local_68[0] = iVar11 + 4;
        local_68[1] = iVar11 + 8;
        local_68[2] = iVar11 + 0xc;
        puVar13 = (undefined4 *)(iVar2 * 0xc + param_1 + 0x450);
        do {
          if (((uVar5 & 1 << (uVar12 & 0x3f)) != 0) &&
             (piVar3 = (int *)*puVar13, piVar3 != (int *)0x0)) {
            bVar1 = false;
            do {
              if (param_2 == *piVar3) {
                bVar1 = true;
              }
              piVar3 = (int *)piVar3[4];
            } while (piVar3 != (int *)0x0);
            if (bVar1) {
              uVar6 = uVar8;
              if ((**(uint **)(param_1 + 0x34) & 0x40) != 0) {
                if (uVar8 == 4) {
                  uVar6 = 3;
                }
                else if (uVar8 == 5) {
                  uVar6 = 1;
                }
                else {
                  uVar6 = 0;
                }
              }
              uVar4 = *(uint *)*piVar10;
              if (((param_3 & 0xff) != (uVar4 >> 5 & 0xff)) || (uVar6 != (uVar4 & 0xf))) {
                *(uint *)*piVar10 = (param_3 & 0xff) << 5 | uVar6 & 0xf | uVar4 & 0xffffe010;
                ((int (*)())FUN_00078a10)(param_1,param_1 + 0x3148c + iVar2 * 4,iVar11);
              }
            }
          }
          bVar1 = uVar12 != 2;
          piVar10 = piVar10 + 1;
          puVar13 = puVar13 + 1;
          uVar12 = uVar12 + 1;
        } while (bVar1);
        piVar9 = (int *)piVar9[4];
      } while (piVar9 != (int *)0x0);
    }
    for (puVar13 = *(undefined4 **)(param_2 * 4 + param_1 + 0xc450); puVar13 != (undefined4 *)0x0;
        puVar13 = (undefined4 *)puVar13[4]) {
      ((int (*)())FUN_00078b80)(param_1,*puVar13,param_3);
    }
  }
  return;
}

/* FUN_00078db0 @ 0x78db0 (68 bytes) */
int FUN_00078db0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_2 + param_1 + 0x3087c);
  iVar2 = (param_2 * 4 + param_3) * 4 + param_1;
  *(undefined4 *)(iVar2 + 0x2d87c) = 0;
  *(undefined4 *)(iVar2 + 0x2a87c) = 0;
  *(byte *)(param_2 + param_1 + 0x3087c) =
       ((byte)(-2 << (param_3 & 0x1f)) | (byte)(0xfffffffe >> 0x20 - (param_3 & 0x1f))) & bVar1;
  return;
}

/* FUN_00078e00 @ 0x78e00 (228 bytes) */
int FUN_00078e00(param_1, param_2)
  undefined4 *param_1;
  uint param_2;
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_1[0x105];
  if (uVar3 < param_2) {
    uVar3 = param_1[0x102];
    uVar2 = param_1[0x104];
    if (uVar3 <= uVar2) {
      if (0xfe < uVar3) {
        return 0;
      }
      uVar1 = (*(code *)*param_1)(0x1000);
      iVar4 = param_1[0x102];
      param_1[uVar3 + 2] = uVar1;
      if (param_1[iVar4 + 2] == 0) {
        return 0;
      }
      uVar2 = param_1[0x104];
      param_1[0x102] = iVar4 + 1;
    }
    uVar3 = 0x1000;
    param_1[0x105] = 0x1000;
    param_1[0x104] = uVar2 + 1;
    param_1[0x103] = param_1[uVar2 + 2];
  }
  iVar4 = param_1[0x103];
  param_1[0x105] = uVar3 - param_2;
  param_1[0x103] = param_2 + iVar4;
  return (param_2 + iVar4) - param_2;
}

/* FUN_00078ef0 @ 0x78ef0 (24 bytes) */
int FUN_00078ef0(param_1)
  uint *param_1;
{
  return (*param_1 & 0xf) == 2;
}

/* FUN_00078f10 @ 0x78f10 (92 bytes) */
int FUN_00078f10(param_1, param_2)
  uint *param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *param_1 >> 0x15 & 1;
  }
  if (param_2 == 0) {
    return *param_1 >> 0x14 & 1;
  }
  if (param_2 == 2) {
    return *param_1 >> 0x16 & 1;
  }
  if (param_2 != 3) {
    return 0;
  }
  return *param_1 >> 0x17 & 1;
}

/* FUN_00078f80 @ 0x78f80 (2340 bytes) */
int FUN_00078f80(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  undefined4 *param_3;
  int param_4;
  undefined4 param_5;
{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int *piVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined4 *puVar17;
  int *piVar18;
  uint uVar19;
  uint uVar20;
  int *piVar21;
  int iVar22;
  int iVar23;
  int iStack00000024;
  undefined4 uStack00000028;
  int local_78 [4];
  uint local_68 [4];
  uint *local_58;
  
  piVar21 = (int *)(param_2 * 0xc + param_1 + 0x450);
  uVar20 = 0;
  uVar19 = *(uint *)(param_2 * 4 + param_1 + 0x6450);
  puVar17 = param_3;
  iStack00000024 = param_4;
  uStack00000028 = param_5;
  do {
    if ((uVar19 & 1 << (uVar20 & 0x3f)) != 0) {
      for (iVar22 = *piVar21; iVar22 != 0; iVar22 = *(int *)(iVar22 + 0x10)) {
        iVar11 = ((int (*)())FUN_00078ef0)(*puVar17,uStack00000028);
        if (iVar11 == 0) {
          uVar16 = 0;
          do {
            if ((1 << (uVar16 & 0x3f) & *(uint *)(iVar22 + 4)) != 0) {
              puVar6 = *(uint **)((((char)(DAT_001aa760)[*(uint *)*puVar17 & 0xf] * 0x100 +
                                   (*(uint *)*puVar17 >> 5 & 0xff)) * 4 + uVar16) * 4 + param_1 +
                                 0x2a87c);
              while( true ) {
                if (puVar6 == (uint *)0x0) {
                  return 6;
                }
                if (param_2 == (*puVar6 & 0xfff)) break;
                puVar6 = (uint *)puVar6[1];
              }
              *puVar6 = *puVar6 | 0x4000;
            }
            bVar1 = uVar16 != 3;
            uVar16 = uVar16 + 1;
          } while (bVar1);
        }
        else {
          uVar16 = 0;
          piVar18 = (int *)(param_1 + 0x30b7c);
          do {
            if ((1 << (uVar16 & 0x3f) & *(uint *)(iVar22 + 4)) != 0) {
              puVar6 = (uint *)*piVar18;
              while( true ) {
                if (puVar6 == (uint *)0x0) {
                  return 6;
                }
                if (param_2 == (*puVar6 & 0xfff)) break;
                puVar6 = (uint *)puVar6[1];
              }
              *puVar6 = *puVar6 | 0x4000;
            }
            bVar1 = uVar16 != 3;
            piVar18 = piVar18 + 1;
            uVar16 = uVar16 + 1;
          } while (bVar1);
        }
      }
    }
    bVar1 = uVar20 != 2;
    piVar21 = piVar21 + 1;
    puVar17 = puVar17 + 1;
    uVar20 = uVar20 + 1;
  } while (bVar1);
  uVar20 = 0;
  piVar21 = (int *)(param_2 * 0xc + param_1 + 0x450);
  local_58 = local_68;
LAB_00079150:
  if ((uVar19 & 1 << (uVar20 & 0x3f)) != 0) {
    puVar6 = (uint *)*param_3;
    iVar22 = *piVar21;
    iVar11 = (char)(DAT_001aa760)[*puVar6 & 0xf] * 0x100 + (*puVar6 >> 5 & 0xff);
    if (iVar22 != 0) {
      bVar1 = false;
LAB_000791c0:
      iVar12 = ((int (*)())FUN_00078ef0)(puVar6,uStack00000028);
      if (iVar12 == 0) {
        puVar6 = (uint *)(param_1 + iVar11 * 0x10 + 0x2a87c);
        uVar16 = 0;
LAB_000792a0:
        uVar14 = 1 << (uVar16 & 0x3f);
        if ((uVar14 & *(uint *)(iVar22 + 4)) != 0) {
          puVar7 = (uint *)*puVar6;
          uVar8 = 0;
          if (puVar7 != (uint *)0x0) {
            do {
              if ((*puVar7 & 0x4000) == 0) goto LAB_00079318;
              puVar7 = (uint *)puVar7[1];
              *puVar6 = (uint)puVar7;
            } while (puVar7 != (uint *)0x0);
            goto LAB_00079324;
          }
          goto LAB_00079328;
        }
        goto LAB_00079340;
      }
      puVar6 = (uint *)(param_1 + 0x30b7c);
      uVar16 = 0;
LAB_000791e0:
      uVar14 = 1 << (uVar16 & 0x3f);
      if ((uVar14 & *(uint *)(iVar22 + 4)) != 0) {
        puVar7 = (uint *)*puVar6;
        uVar8 = 0;
        if (puVar7 != (uint *)0x0) {
          do {
            if ((*puVar7 & 0x4000) == 0) goto LAB_00079258;
            puVar7 = (uint *)puVar7[1];
            *puVar6 = (uint)puVar7;
          } while (puVar7 != (uint *)0x0);
          goto LAB_00079264;
        }
        goto LAB_00079268;
      }
      goto LAB_00079280;
    }
    bVar1 = false;
    goto LAB_00079378;
  }
  goto LAB_000798a8;
LAB_00079318:
  while (puVar13 = puVar7, puVar7 = (uint *)puVar13[1], puVar7 != (uint *)0x0) {
    if ((*puVar7 & 0x4000) != 0) {
      puVar13[1] = puVar7[1];
      puVar7 = puVar13;
    }
  }
LAB_00079324:
  uVar8 = *puVar6;
LAB_00079328:
  if (uVar8 == 0) {
    bVar1 = true;
    *(byte *)(iVar11 + param_1 + 0x3087c) = *(byte *)(iVar11 + param_1 + 0x3087c) & ~(byte)uVar14;
  }
LAB_00079340:
  bVar2 = uVar16 == 3;
  puVar6 = puVar6 + 1;
  uVar16 = uVar16 + 1;
  if (bVar2) goto LAB_00079350;
  goto LAB_000792a0;
LAB_00079258:
  while (puVar13 = puVar7, puVar7 = (uint *)puVar13[1], puVar7 != (uint *)0x0) {
    if ((*puVar7 & 0x4000) != 0) {
      puVar13[1] = puVar7[1];
      puVar7 = puVar13;
    }
  }
LAB_00079264:
  uVar8 = *puVar6;
LAB_00079268:
  if (uVar8 == 0) {
    *(byte *)(param_1 + 0x30b9c) = *(byte *)(param_1 + 0x30b9c) & ~(byte)uVar14;
  }
LAB_00079280:
  bVar2 = uVar16 == 3;
  puVar6 = puVar6 + 1;
  uVar16 = uVar16 + 1;
  if (bVar2) goto LAB_00079350;
  goto LAB_000791e0;
LAB_00079350:
  iVar22 = *(int *)(iVar22 + 0x10);
  if (iVar22 == 0) goto LAB_0007936c;
  puVar6 = (uint *)*param_3;
  goto LAB_000791c0;
LAB_0007936c:
  if (*piVar21 == 0) {
LAB_00079378:
    uVar16 = *(uint *)*param_3;
    if ((uVar16 & 0xf) == 1) {
      puVar17 = (undefined4 *)(iVar11 * 0x10 + param_1 + 0x2a87c);
      uVar14 = 0;
      do {
        uVar8 = 1 << (uVar14 & 0x3f);
        if (((1 << (uVar16 >> 0xd & 7) | 1 << (uVar16 >> 0x10 & 7) | 1 << (uVar16 >> 0x13 & 7) |
             1 << (uVar16 >> 0x16 & 7)) & uVar8) != 0) {
          puVar6 = (uint *)*puVar17;
          bVar2 = puVar6 == (uint *)0x0;
          if (!bVar2) {
            uVar5 = *puVar6;
            while (puVar7 = puVar6, uVar5 == param_2) {
              puVar6 = (uint *)puVar6[1];
              bVar2 = puVar6 == (uint *)0x0;
              if (bVar2) goto LAB_00079448;
              uVar5 = *puVar6;
            }
            while (puVar13 = puVar7, puVar7 = (uint *)puVar13[1], puVar7 != (uint *)0x0) {
              if (param_2 == *puVar7) {
                puVar13[1] = puVar7[1];
                puVar7 = puVar13;
              }
            }
          }
LAB_00079448:
          *puVar17 = puVar6;
          if (bVar2) {
            *(byte *)(iVar11 + param_1 + 0x3087c) =
                 *(byte *)(iVar11 + param_1 + 0x3087c) & ~(byte)uVar8;
          }
        }
        bVar2 = uVar14 != 3;
        puVar17 = puVar17 + 1;
        uVar14 = uVar14 + 1;
      } while (bVar2);
    }
  }
  if (bVar1) {
    iVar22 = 0;
    uVar14 = 0;
    bVar1 = false;
    piVar18 = (int *)(iVar11 * 0x10 + param_1 + 0x2d87c);
    uVar16 = (uint)*(char *)(iVar11 + param_1 + 0x3087c);
    do {
      if ((uVar16 & 1 << (uVar14 & 0x3f)) != 0) {
        if (bVar1) {
          iVar12 = *piVar18;
          iVar9 = 0;
          iVar23 = iVar22;
          do {
            piVar4 = local_78 + iVar9;
            iVar23 = iVar23 + -1;
            if (iVar23 == 0) {
              if (*piVar4 != iVar12) goto LAB_00079508;
              break;
            }
            iVar9 = iVar9 + 1;
          } while (*piVar4 != iVar12);
        }
        else {
          iVar12 = *piVar18;
LAB_00079508:
          local_78[iVar22] = iVar12;
          bVar1 = 0 < iVar22 + 1;
          iVar22 = iVar22 + 1;
        }
      }
      bVar2 = uVar14 != 3;
      piVar18 = piVar18 + 1;
      uVar14 = uVar14 + 1;
    } while (bVar2);
    if (bVar1) {
      iVar12 = 0;
      uVar14 = 0;
      piVar18 = local_78;
      do {
        iVar9 = *piVar18;
        piVar18 = piVar18 + 1;
        if (iVar9 != -1) {
          for (puVar6 = *(uint **)(iVar9 * 4 + param_1 + 0xc450); puVar6 != (uint *)0x0;
              puVar6 = (uint *)puVar6[4]) {
            uVar8 = *puVar6;
            if ((*(uint *)(uVar8 * 4 + param_1 + 0x3348c) & 0x40000) == 0) {
              uVar5 = puVar6[1];
              uVar15 = 0;
              puVar7 = local_68;
              iVar9 = 4;
              do {
                uVar10 = 1 << (uVar15 & 0x3f);
                if ((uVar5 & uVar10 & ~uVar16) != 0) {
                  if ((uVar10 & uVar14) == 0) {
                    *puVar7 = uVar8;
                    uVar14 = uVar14 | uVar10;
                  }
                  else if (uVar8 < *puVar7) {
                    *puVar7 = uVar8;
                  }
                }
                uVar15 = uVar15 + 1;
                puVar7 = puVar7 + 1;
                iVar9 = iVar9 + -1;
              } while (iVar9 != 0);
            }
          }
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 != iVar22);
      if (uVar14 != 0) {
        uVar16 = 0;
        do {
          if ((1 << (uVar16 & 0x3f) & uVar14) != 0) {
            uVar8 = 0;
            puVar6 = local_58;
            do {
              if ((((uVar16 != uVar8) && ((1 << (uVar8 & 0x3f) & uVar14) != 0)) &&
                  (uVar5 = local_58[uVar16], uVar5 < *puVar6)) &&
                 (iVar12 = ((int (*)())FUN_00078f10)(iStack00000024 + uVar5 * 0x10,uVar8), iVar12 != 0)) {
                *puVar6 = uVar5;
              }
              bVar2 = uVar8 != 3;
              puVar6 = puVar6 + 1;
              uVar8 = uVar8 + 1;
            } while (bVar2);
          }
          bVar2 = uVar16 != 3;
          uVar16 = uVar16 + 1;
        } while (bVar2);
        uVar16 = 0;
        puVar6 = local_68;
        do {
          uVar8 = 1 << (uVar16 & 0x3f);
          if (((uVar8 & uVar14) != 0) &&
             (iVar12 = ((int (*)())FUN_00077ba0)(param_1,*puVar6,iVar11,uVar8,1), iVar12 != 0)) {
            return iVar12;
          }
          bVar2 = uVar16 != 3;
          puVar6 = puVar6 + 1;
          uVar16 = uVar16 + 1;
        } while (bVar2);
      }
    }
    cVar3 = *(char *)(iVar11 + param_1 + 0x3087c);
    if (bVar1) {
      iVar12 = 0;
      uVar16 = 0;
      piVar18 = local_78;
      do {
        iVar9 = *piVar18;
        piVar18 = piVar18 + 1;
        if (iVar9 != -1) {
          for (puVar6 = *(uint **)(iVar9 * 4 + param_1 + 0xe450); puVar6 != (uint *)0x0;
              puVar6 = (uint *)puVar6[4]) {
            uVar14 = *puVar6;
            if ((*(uint *)(uVar14 * 4 + param_1 + 0x3348c) & 0x40000) == 0) {
              uVar8 = puVar6[1];
              uVar5 = 0;
              puVar7 = local_68;
              iVar9 = 4;
              do {
                uVar15 = 1 << (uVar5 & 0x3f);
                if ((uVar8 & uVar15 & ~(int)cVar3) != 0) {
                  if ((uVar15 & uVar16) == 0) {
                    *puVar7 = uVar14;
                    uVar16 = uVar16 | uVar15;
                  }
                  else if (uVar14 < *puVar7) {
                    *puVar7 = uVar14;
                  }
                }
                uVar5 = uVar5 + 1;
                puVar7 = puVar7 + 1;
                iVar9 = iVar9 + -1;
              } while (iVar9 != 0);
            }
          }
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 != iVar22);
      if (uVar16 != 0) {
        uVar14 = 0;
        do {
          if ((1 << (uVar14 & 0x3f) & uVar16) != 0) {
            uVar8 = 0;
            puVar6 = local_68;
            do {
              if (((uVar14 != uVar8) && ((1 << (uVar8 & 0x3f) & uVar16) != 0)) &&
                 ((uVar5 = local_68[uVar14], uVar5 < *puVar6 &&
                  (iVar22 = ((int (*)())FUN_00078f10)(uVar5 * 0x10 + iStack00000024,uVar8), iVar22 != 0)))) {
                *puVar6 = uVar5;
              }
              bVar1 = uVar8 != 3;
              puVar6 = puVar6 + 1;
              uVar8 = uVar8 + 1;
            } while (bVar1);
          }
          bVar1 = uVar14 != 3;
          uVar14 = uVar14 + 1;
        } while (bVar1);
        uVar14 = 0;
        puVar6 = local_68;
        do {
          uVar8 = 1 << (uVar14 & 0x3f);
          if (((uVar8 & uVar16) != 0) &&
             (iVar22 = ((int (*)())FUN_00077ba0)(param_1,*puVar6,iVar11,uVar8,1), iVar22 != 0)) {
            return iVar22;
          }
          bVar1 = uVar14 != 3;
          puVar6 = puVar6 + 1;
          uVar14 = uVar14 + 1;
        } while (bVar1);
      }
    }
  }
LAB_000798a8:
  bVar1 = uVar20 == 2;
  param_3 = param_3 + 1;
  piVar21 = piVar21 + 1;
  uVar20 = uVar20 + 1;
  if (bVar1) {
    return 0;
  }
  goto LAB_00079150;
}

/* FUN_000798f0 @ 0x798f0 (28 bytes) */
int FUN_000798f0(param_1, param_2)
  uint *param_1;
  uint param_2;
{
  *param_1 = (param_2 & 8) << 0x14 |
             (param_2 & 4) << 0x14 |
             (param_2 & 2) << 0x14 | (param_2 & 1) << 0x14 | *param_1 & 0xff0fffff;
  return;
}

/* FUN_00079910 @ 0x79910 (248 bytes) */
int FUN_00079910(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  int *param_2;
  int param_3;
  uint param_4;
  int param_5;
  int param_6;
  undefined4 param_7;
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = (int *)*param_2;
  if ((int *)*param_2 == (int *)0x0) {
    piVar2 = (int *)((int (*)())FUN_00078e00)(param_7,0x14);
    *param_2 = (int)piVar2;
    if (piVar2 != (int *)0x0) {
      piVar2[3] = param_6;
      *piVar2 = param_3;
      piVar2[1] = param_4;
      piVar2[4] = 0;
      piVar2[2] = param_5;
      return 0;
    }
  }
  else {
    do {
      piVar3 = piVar2;
      if (param_3 == *piVar3) {
        piVar3[1] = param_4 | piVar3[1];
        return 0;
      }
      piVar2 = (int *)piVar3[4];
    } while ((int *)piVar3[4] != (int *)0x0);
    piVar2 = (int *)((int (*)())FUN_00078e00)(param_7,0x14);
    piVar3[4] = (int)piVar2;
    if (piVar2 != (int *)0x0) {
      *piVar2 = param_3;
      piVar2[1] = param_4;
      piVar2[4] = 0;
      iVar1 = piVar3[4];
      *(int *)(iVar1 + 0xc) = param_6;
      *(int *)(iVar1 + 8) = param_5;
      return 0;
    }
  }
  return 7;
}

/* FUN_00079a20 @ 0x79a20 (92 bytes) */
int FUN_00079a20(param_1, param_2)
  uint *param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(ushort *)param_1 & 7;
  }
  if (param_2 == 0) {
    return *param_1 >> 0xd & 7;
  }
  if (param_2 == 2) {
    return *param_1 >> 0x13 & 7;
  }
  if (param_2 != 3) {
    return 0;
  }
  return *param_1 >> 0x16 & 7;
}

/* FUN_00079a90 @ 0x79a90 (100 bytes) */
int FUN_00079a90(param_1, param_2, param_3)
  uint *param_1;
  int param_2;
  uint param_3;
{
  if (param_2 == 1) {
    *param_1 = (param_3 & 7) << 0x10 | *param_1 & 0xfff8ffff;
    return;
  }
  if (param_2 == 0) {
    *param_1 = (param_3 & 7) << 0xd | *param_1 & 0xffff1fff;
    return;
  }
  if (param_2 == 2) {
    *param_1 = (param_3 & 7) << 0x13 | *param_1 & 0xffc7ffff;
    return;
  }
  if (param_2 != 3) {
    return;
  }
  *param_1 = (param_3 & 7) << 0x16 | *param_1 & 0xfe3fffff;
  return;
}

/* FUN_00079b00 @ 0x79b00 (200 bytes) */
int FUN_00079b00(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  int iVar1;
  undefined4 *puVar2;
  
  if ((param_3 != param_2) && (((code **)FUN_00030c50)[param_3 + param_1] == (code *)0x0)) {
    ((code **)FUN_00030c50)[param_3 + param_1] = (code *)0x1;
    iVar1 = ((int (*)())FUN_00079910)(param_1,param_1 + 0xe450 + param_2 * 4,param_3,param_4,0,0,param_1 + 0x38);
    if (iVar1 != 0) {
      return iVar1;
    }
    for (puVar2 = *(undefined4 **)(param_3 * 4 + param_1 + 0xc450); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)puVar2[4]) {
      iVar1 = ((int (*)())FUN_00079b00)(param_1,param_2,*puVar2,puVar2[1]);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
  }
  return 0;
}

/* FUN_00079bd0 @ 0x79bd0 (532 bytes) */
int FUN_00079bd0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  undefined4 param_7;
{
  int iVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  
  iVar1 = (param_5 * 4 + param_6) * 4;
  puVar7 = (uint *)(iVar1 + param_2 + 4);
  uVar4 = ((int (*)())FUN_00079a20)(puVar7,param_7);
  if ((1 < uVar4 - 4) && (iVar8 = param_5 + -1, -1 < iVar8)) {
    puVar10 = (uint *)(param_2 + iVar8 * 0x10);
    iVar9 = 0;
    do {
      uVar3 = *puVar7 & 0xf;
      uVar6 = *puVar10 >> 8 & 0xf;
      if (uVar3 == 1) {
        bVar2 = uVar6 == 5;
LAB_00079cd0:
        if (((!bVar2) || ((*puVar10 >> 0xd & 0x7f) != (*puVar7 >> 5 & 0xff))) ||
           (iVar5 = ((int (*)())FUN_00078f10)(puVar10,uVar4), iVar5 == 0)) goto LAB_00079dc0;
        if ((char)*puVar10 == 'A') {
          if (((**(uint **)(param_1 + 0x34) & 0x280) == 0) || (uVar4 != 3)) {
LAB_00079d90:
            ((int (*)())FUN_00079910)(param_1,param_4 + 0x418 + (param_5 * 3 + param_6) * 4,iVar8 - iVar9,
                         1 << (uVar4 & 0x3f),0,0,param_4);
            bVar2 = true;
          }
          else {
            ((int (*)())FUN_00079a90)(puVar7,param_7,5);
            if (param_3 == 0) goto LAB_00079dc8;
LAB_00079d78:
            bVar2 = true;
            *(uint *)(iVar1 + param_3 + 4) = *puVar7;
          }
        }
        else {
          if (((char)*puVar10 != 'D') || ((uVar4 != 0 && (uVar4 != 3)))) goto LAB_00079d90;
          ((int (*)())FUN_00079a90)(puVar7,param_7,5);
          if ((param_3 != 0) && ((**(uint **)(param_1 + 0x34) & 0x200) != 0)) goto LAB_00079d78;
LAB_00079dc8:
          bVar2 = true;
        }
      }
      else {
        if (uVar3 == 0) {
          bVar2 = uVar6 == 0;
          goto LAB_00079cd0;
        }
        if (uVar3 == 3) {
          bVar2 = uVar6 == 4;
          goto LAB_00079cd0;
        }
LAB_00079dc0:
        bVar2 = false;
      }
      if (iVar8 == iVar9) {
        return;
      }
      iVar9 = iVar9 + 1;
      puVar10 = puVar10 + -4;
    } while (!bVar2);
  }
  return;
}

/* FUN_00079e10 @ 0x79e10 (88 bytes) */
int FUN_00079e10(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((((*(uint *)(param_1 + 4) & 0xf) == 0) && ((*(uint *)(param_1 + 8) & 0xf) == 0)) &&
     ((*(uint *)(param_1 + 0xc) & 0xf) == 0)) {
    uVar1 = *(uint *)(param_1 + 4) & 0x1fe0;
    uVar2 = *(uint *)(param_1 + 8) & 0x1fe0;
    if (((uVar1 != uVar2) && (uVar3 = *(uint *)(param_1 + 0xc) & 0x1fe0, uVar2 != uVar3)) &&
       (uVar1 != uVar3)) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00079e70 @ 0x79e70 (488 bytes) */
int FUN_00079e70(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  uint uVar13;
  int *piVar14;
  int iVar15;
  uint uVar16;
  
  iVar11 = param_1 + 0x1286c;
  uVar8 = *(uint *)(param_1 + 0x2a878);
  if (uVar8 != 0) {
    uVar13 = 0;
    uVar7 = 6;
    bVar2 = false;
    do {
      iVar15 = *(int *)(uVar13 * 4 + param_1 + 0x28878);
      puVar9 = (uint *)(iVar11 + iVar15 * 0x10);
      if ((((param_2 != 0) && ((**(uint **)(param_1 + 0x34) & 0x40) != 0)) &&
          (bVar4 = (char)*puVar9 + 0xbc, bVar4 < 0xb)) &&
         (((1 << ((int)(char)bVar4 & 0x3fU) & 0x601U) != 0 &&
          (iVar5 = ((int (*)())FUN_00079e10)(puVar9), iVar5 != 0)))) {
        bVar2 = true;
        uVar7 = 8;
      }
      piVar12 = *(int **)(iVar15 * 4 + param_1 + 0xa450);
      if (piVar12 != (int *)0x0) {
        uVar10 = uVar13 + 1;
        do {
          if (uVar10 < uVar8) {
            uVar3 = *puVar9;
            iVar15 = *piVar12;
            piVar14 = (int *)(param_1 + uVar10 * 4 + 0x28878);
            uVar16 = uVar10;
            do {
              iVar5 = *piVar14;
              if ((*(uint *)(iVar11 + iVar5 * 0x10) & 0xfef00) == (uVar3 & 0xfef00)) {
                uVar6 = ((int (*)())FUN_00077850)(iVar11 + iVar5 * 0x10);
                bVar1 = true;
                if ((uVar6 & piVar12[1]) == 0) goto LAB_00079fc0;
              }
              else {
LAB_00079fc0:
                bVar1 = false;
              }
              uVar16 = uVar16 + 1;
              if (uVar8 == uVar16) {
                if (bVar1) {
LAB_00079ffc:
                  if (iVar5 != iVar15) {
                    bVar2 = true;
                    uVar7 = 9;
                  }
                }
                break;
              }
              if (bVar1) goto LAB_00079ffc;
              piVar14 = piVar14 + 1;
            } while (iVar5 != iVar15);
          }
          piVar12 = (int *)piVar12[4];
        } while (piVar12 != (int *)0x0);
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 < uVar8);
    if (bVar2) {
      return uVar7;
    }
  }
  return 0;
}

/* FUN_0007a060 @ 0x7a060 (16 bytes) */
int FUN_0007a060(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x410) = 0;
  *(undefined4 *)(param_1 + 0x414) = 0;
  return;
}

/* FUN_0007a070 @ 0x7a070 (156 bytes) */
int FUN_0007a070(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x408) != 0) {
    uVar2 = 0;
    iVar3 = param_1;
    do {
      uVar2 = uVar2 + 1;
      (**(code **)(param_1 + 4))(*(undefined4 *)(iVar3 + 8));
      uVar1 = *(uint *)(param_1 + 0x408);
      *(undefined4 *)(iVar3 + 8) = 0;
      iVar3 = iVar3 + 4;
    } while (uVar2 < uVar1);
  }
  *(undefined4 *)(param_1 + 0x40c) = 0;
  *(undefined4 *)(param_1 + 0x408) = 0;
  ((int (*)())FUN_0007a060)(param_1);
  return;
}

/* FUN_0007a110 @ 0x7a110 (100 bytes) */
int FUN_0007a110(param_1)
  int param_1;
{
  if (param_1 != 0) {
    ((int (*)())FUN_0007a070)(param_1 + 0x12454);
    ((int (*)())FUN_0007a070)(param_1 + 0x38);
                    
                    
    (**(code **)(param_1 + 0x12458))(param_1);
    return;
  }
  return;
}

/* FUN_0007a1a0 @ 0x7a1a0 (756 bytes) */
int FUN_0007a1a0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  int iVar16;
  int iVar17;
  
  iVar2 = param_2 * 4;
  puVar15 = (uint *)(param_1 + 0x1286c + param_2 * 0x10);
  uVar14 = 0;
  uVar13 = *(uint *)(iVar2 + param_1 + 0x6450);
  uVar6 = ((int (*)())FUN_00077850)(puVar15);
  uVar4 = 0;
  iVar16 = 4;
  do {
    if ((uVar6 & 1 << (uVar4 & 0x3f)) != 0) {
      uVar14 = uVar14 | 1 << (param_3 >> ((uVar4 & 0xf) << 2) & 0xf);
    }
    uVar4 = uVar4 + 1;
    iVar16 = iVar16 + -1;
  } while (iVar16 != 0);
  if (uVar6 != uVar14) {
    uVar8 = 0;
    uVar4 = 0xd;
    do {
      if ((uVar6 & 1 << (uVar8 & 0x3f)) != 0) {
        uVar11 = 0;
        uVar9 = (param_3 >> ((uVar8 & 0xf) << 2) & 0xf) * 3 + 0xd;
        puVar12 = puVar15;
        do {
          if ((uVar13 & 1 << (uVar11 & 0x3f)) != 0) {
            uVar3 = puVar12[1];
            puVar12[1] = (uVar3 & ~(7 << (uVar4 & 0x3f)) |
                         (uVar3 >> (uVar9 & 0x3f) & 7) << (uVar4 & 0x3f)) & ~(7 << (uVar9 & 0x3f)) |
                         (uVar3 >> (uVar4 & 0x3f) & 7) << (uVar9 & 0x3f);
          }
          bVar1 = uVar11 != 2;
          puVar12 = puVar12 + 1;
          uVar11 = uVar11 + 1;
        } while (bVar1);
      }
      bVar1 = uVar8 != 3;
      uVar4 = uVar4 + 3;
      uVar8 = uVar8 + 1;
    } while (bVar1);
    *puVar15 = *puVar15 & 0xff0fffff | uVar14 << 0x14;
    for (piVar7 = *(int **)(iVar2 + param_1 + 0xa450); piVar7 != (int *)0x0;
        piVar7 = (int *)piVar7[4]) {
      iVar16 = *piVar7;
      uVar6 = 0;
      uVar13 = 0;
      iVar17 = 4;
      uVar4 = *(uint *)(iVar16 * 4 + param_1 + 0x6450);
      puVar15 = (uint *)(param_1 + iVar16 * 0x10 + 0x12870);
      do {
        if ((piVar7[1] & 1 << (uVar13 & 0x3f)) != 0) {
          uVar6 = uVar6 | 1 << (param_3 >> ((uVar13 & 0xf) << 2) & 0xf);
        }
        uVar13 = uVar13 + 1;
        iVar17 = iVar17 + -1;
      } while (iVar17 != 0);
      piVar7[1] = uVar6;
      uVar6 = 0;
      puVar10 = (undefined4 *)(iVar16 * 0xc + param_1 + 0x450);
      do {
        if (((uVar4 & 1 << (uVar6 & 0x3f)) != 0) && (piVar5 = (int *)*puVar10, piVar5 != (int *)0x0)
           ) {
          bVar1 = false;
          do {
            if (param_2 == *piVar5) {
              uVar13 = 0;
              uVar14 = 0;
              iVar16 = 4;
              do {
                if ((piVar5[1] & 1 << (uVar14 & 0x3f)) != 0) {
                  uVar13 = uVar13 | 1 << (param_3 >> ((uVar14 & 0xf) << 2) & 0xf);
                }
                uVar14 = uVar14 + 1;
                iVar16 = iVar16 + -1;
              } while (iVar16 != 0);
              piVar5[1] = uVar13;
              bVar1 = true;
            }
            piVar5 = (int *)piVar5[4];
          } while (piVar5 != (int *)0x0);
          if (bVar1) {
            *puVar15 = (param_3 >> (*puVar15 >> 0x1b & 0xc) & 3) << 0x1d | *puVar15 & 0x9fffffff;
          }
        }
        bVar1 = uVar6 != 2;
        puVar15 = puVar15 + 1;
        puVar10 = puVar10 + 1;
        uVar6 = uVar6 + 1;
      } while (bVar1);
    }
    for (puVar10 = *(undefined4 **)(iVar2 + param_1 + 0xc450); puVar10 != (undefined4 *)0x0;
        puVar10 = (undefined4 *)puVar10[4]) {
      ((int (*)())FUN_0007a1a0)(param_1,*puVar10,param_3);
    }
  }
  return;
}

/* FUN_0007a4a0 @ 0x7a4a0 (1544 bytes) */
int FUN_0007a4a0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
  undefined1 *param_6;
  uint *param_7;
{
  bool bVar1;
  char cVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  int *piVar17;
  undefined *puVar18;
  
  *param_6 = 0;
  *param_7 = 0xffffffff;
  puVar16 = (uint *)(param_5 * 0x10 + param_2);
  iVar5 = ((int (*)())FUN_000777b0)(puVar16,param_3);
  if (iVar5 == 0) {
    iVar5 = ((int (*)())FUN_00077800)(puVar16,param_3);
    if (iVar5 != 0) {
      puVar18 = ((unsigned char *)0x00003210);
      uVar6 = ((int (*)())FUN_00077d10)(param_1,param_5);
      uVar7 = ((int (*)())FUN_00077850)(puVar16);
      uVar15 = 0;
      uVar14 = 0;
      iVar5 = param_5 * 4 + param_1;
      uVar11 = (uint)*(char *)(param_1 + 0x30b9c);
LAB_0007a7b0:
      if (((uVar6 & uVar11 & 1 << (uVar14 & 0x3f)) == 0) || (4 < uVar15)) goto LAB_0007aa50;
      if (uVar15 != 4) {
        if ((1 << (uVar15 & 0x3f) & ~(uVar6 | uVar11)) == 0) {
          iVar4 = 5 - uVar15;
          do {
            uVar15 = uVar15 + 1;
            iVar4 = iVar4 + -1;
            if (iVar4 == 0) goto LAB_0007aa50;
            if (uVar15 == 4) goto LAB_0007a7e8;
          } while ((1 << (uVar15 & 0x3f) & ~(uVar6 | uVar11)) == 0);
        }
        uVar13 = uVar15 << (uVar14 << 2 & 0x3c);
        uVar15 = uVar15 + 1;
        puVar18 = (undefined *)((uint)puVar18 & ~(0xf << (uVar14 << 2 & 0x3c)) | uVar13);
        goto LAB_0007aa50;
      }
LAB_0007a7e8:
      uVar15 = 0;
      uVar14 = 0;
      iVar4 = 4;
      do {
        if ((uVar6 & 1 << (uVar14 & 0x3f)) != 0) {
          uVar15 = uVar15 | 1 << ((uint)puVar18 >> ((uVar14 & 0xf) << 2) & 0xf);
        }
        uVar14 = uVar14 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      uVar14 = 0;
      uVar6 = 0;
      iVar4 = 4;
      do {
        if ((uVar7 & 1 << (uVar6 & 0x3f)) != 0) {
          uVar14 = uVar14 | 1 << ((uint)puVar18 >> ((uVar6 & 0xf) << 2) & 0xf);
        }
        uVar6 = uVar6 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      uVar11 = uVar11 & uVar15;
      if (uVar11 == 0) {
LAB_0007aa5c:
        puVar3 = puVar18;
      }
      else {
        puVar12 = (undefined4 *)(param_1 + 0x30b7c);
        uVar6 = 0;
        iVar4 = 4;
        do {
          uVar7 = 1 << (uVar6 & 0x3f);
          if (((((uVar7 & uVar11) != 0) && (piVar17 = (int *)*puVar12, piVar17 != (int *)0x0)) &&
              (param_5 == *piVar17)) && (piVar17[1] == 0)) {
            uVar11 = uVar11 & ~uVar7;
          }
          uVar6 = uVar6 + 1;
          puVar12 = puVar12 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        if (uVar11 == 0) goto LAB_0007aa5c;
        piVar17 = (int *)(param_1 + 0x30b8c);
        uVar6 = 0;
        do {
          uVar7 = 1 << (uVar6 & 0x3f);
          if ((uVar7 & uVar11) != 0) {
            if ((uVar7 & uVar14) == 0) {
              piVar8 = *(int **)(iVar5 + 0xc450);
              if (piVar8 != (int *)0x0) {
                do {
                  if (((uVar7 & piVar8[1]) == 0) || (bVar1 = true, *piVar8 != *piVar17)) {
                    bVar1 = false;
                  }
                  piVar8 = (int *)piVar8[4];
                  if (piVar8 == (int *)0x0) {
                    if (!bVar1) goto LAB_0007a948;
                    break;
                  }
                } while (!bVar1);
                goto LAB_0007a944;
              }
            }
            else if (param_5 == *piVar17) {
LAB_0007a944:
              uVar11 = uVar11 & ~uVar7;
            }
          }
LAB_0007a948:
          bVar1 = uVar6 != 3;
          piVar17 = piVar17 + 1;
          uVar6 = uVar6 + 1;
        } while (bVar1);
        if (uVar11 == 0) goto LAB_0007aa5c;
        piVar17 = (int *)(param_1 + 0x30b8c);
        uVar6 = 0;
        do {
          uVar7 = 1 << (uVar6 & 0x3f);
          if ((((uVar7 & uVar11) != 0) && ((uVar7 & uVar14) == 0)) &&
             (piVar8 = *(int **)(iVar5 + 0xe450), piVar8 != (int *)0x0)) {
            do {
              if (((uVar7 & piVar8[1]) == 0) || (bVar1 = true, *piVar8 != *piVar17)) {
                bVar1 = false;
              }
              piVar8 = (int *)piVar8[4];
              if (piVar8 == (int *)0x0) {
                if (!bVar1) goto LAB_0007a9d4;
                break;
              }
            } while (!bVar1);
            uVar11 = uVar11 & ~uVar7;
          }
LAB_0007a9d4:
          bVar1 = uVar6 != 3;
          piVar17 = piVar17 + 1;
          uVar6 = uVar6 + 1;
        } while (bVar1);
        puVar3 = (undefined *)0xffffffff;
        if (uVar11 == 0) goto LAB_0007aa5c;
      }
      *param_7 = (uint)puVar3;
      if (puVar3 != (undefined *)0xffffffff) {
        if (puVar3 == ((unsigned char *)0x00003210)) goto LAB_0007a680;
        goto LAB_0007aa80;
      }
      goto LAB_0007aa90;
    }
LAB_0007a680:
    uVar9 = 1;
  }
  else {
    if (((*(uint *)(param_5 * 4 + param_1 + 0x3348c) & 0x1000) != 0) &&
       (iVar5 = ((int (*)())FUN_00078760)(param_1,param_2,param_5,param_6,param_7), iVar5 != 0)) {
      return 1;
    }
    uVar6 = ((int (*)())FUN_00077850)(puVar16);
    for (piVar17 = *(int **)(param_5 * 4 + param_1 + 0xe450); piVar17 != (int *)0x0;
        piVar17 = (int *)piVar17[4]) {
      iVar5 = *piVar17;
      uVar7 = ((int (*)())FUN_00077850)(param_2 + iVar5 * 0x10);
      if (((uVar6 & uVar7) != 0) &&
         (iVar5 = iVar5 * 4 + param_1, (*(uint *)(iVar5 + 0x3348c) & 0x40000) != 0)) {
        for (piVar8 = *(int **)(iVar5 + 0xa450); piVar8 != (int *)0x0; piVar8 = (int *)piVar8[4]) {
          if (((param_5 != *piVar8) && ((uVar6 & uVar7 & piVar8[1]) != 0)) &&
             ((*(uint *)(*piVar8 * 4 + param_1 + 0x3348c) & 0x40000) == 0)) goto LAB_0007aa90;
        }
      }
    }
    uVar9 = ((int (*)())FUN_00077d10)(param_1,param_5);
    iVar5 = ((int (*)())FUN_00077cf0)(puVar16,param_3);
    if (iVar5 == 0) {
      uVar6 = *puVar16;
LAB_0007a634:
      cVar2 = (DAT_001aa758)[uVar6 >> 8 & 0xf];
      uVar10 = ((int (*)())FUN_00077850)(puVar16);
      iVar5 = ((int (*)())FUN_00077d90)(param_1,param_2,cVar2 * 0x100 + (uVar6 >> 0xd & 0x7f),uVar9,param_5,
                           uVar10);
      if (iVar5 == 0) goto LAB_0007a680;
    }
    else {
      uVar6 = *puVar16;
      if ((uVar6 >> 0xd & 0x7f) < param_4) goto LAB_0007a634;
    }
    iVar5 = ((int (*)())FUN_00077cf0)(puVar16,param_3);
    if (iVar5 == 0) {
      if (((*puVar16 & 0xf00) != 0x400) || (bVar1 = true, param_3 == 0)) {
        bVar1 = false;
      }
      if (bVar1) {
        uVar10 = ((int (*)())FUN_00077850)(puVar16);
        uVar6 = ((int (*)())FUN_00078250)(param_1,param_2,uVar9,param_5,uVar10);
        *param_7 = uVar6;
      }
    }
    else {
      uVar10 = ((int (*)())FUN_00077850)(puVar16);
      if (param_4 != 0) {
        uVar6 = 0;
        do {
          iVar5 = ((int (*)())FUN_00077d90)(param_1,param_2,uVar6,uVar9,param_5,uVar10);
          if (iVar5 == 0) goto LAB_0007a6e4;
          uVar6 = uVar6 + 1;
        } while (param_4 != uVar6);
      }
      uVar6 = 0xffffffff;
LAB_0007a6e4:
      *param_7 = uVar6;
    }
    if ((int)*param_7 < 0) {
LAB_0007aa90:
      uVar9 = 0;
    }
    else {
LAB_0007aa80:
      uVar9 = 1;
      *param_6 = 1;
    }
  }
  return uVar9;
LAB_0007aa50:
  bVar1 = uVar14 == 3;
  uVar14 = uVar14 + 1;
  if (bVar1) goto LAB_0007aa5c;
  goto LAB_0007a7b0;
}

/* FUN_0007aae0 @ 0x7aae0 (1460 bytes) */
int FUN_0007aae0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  uint param_3;
  undefined1 *param_4;
  undefined4 *param_5;
  int param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  bool bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  char *pcVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint *puVar16;
  int *piVar17;
  uint uVar18;
  uint uStack00000020;
  undefined1 *puStack00000024;
  undefined4 *puStack00000028;
  byte local_78;
  undefined1 local_77 [3];
  undefined4 local_74;
  undefined4 local_70 [2];
  int local_68;
  int local_64;
  uint local_60;
  int local_5c;
  undefined4 *local_58;
  
  *param_4 = 0;
  local_78 = 0;
  local_74 = 0;
  if (param_2 == 0) {
    iVar11 = 0;
  }
  else {
    iVar11 = 0;
    pcVar12 = (char *)(param_1 + 0x3087c);
    iVar3 = param_2;
    do {
      if (*pcVar12 == '\0') {
        iVar11 = iVar11 + 1;
      }
      pcVar12 = pcVar12 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  iVar3 = *(int *)(((unsigned char *)0x00035490) + param_1);
  uStack00000020 = param_3;
  puStack00000024 = param_4;
  puStack00000028 = param_5;
  if (iVar3 == 2) {
    local_68 = *(int *)(((unsigned char *)0x00035494) + param_1);
    *(undefined4 *)(((unsigned char *)0x00035490) + param_1) = 3;
    iVar3 = ((int (*)())FUN_00078760)(param_1,param_6,local_68,param_4,param_5);
    if (iVar3 != 0) {
      ((int (*)())FUN_00078950)(param_1);
      return local_68;
    }
  }
  else if (iVar3 == 3) {
    *(undefined4 *)(((unsigned char *)0x00035490) + param_1) = 0;
  }
  else if (iVar3 == 1) {
    local_68 = *(int *)(((unsigned char *)0x00035498) + param_1);
    local_77[0] = 0;
    iVar3 = ((int (*)())FUN_0007a4a0)(param_1,param_6,param_8,param_2,local_68,local_77,local_70);
    *(undefined4 *)(((unsigned char *)0x00035490) + param_1) = 3;
    if (iVar3 != 0) {
      *puStack00000024 = local_77[0];
      *puStack00000028 = local_70[0];
      ((int (*)())FUN_00078950)(param_1);
      return local_68;
    }
  }
  local_68 = 0;
  if (*(int *)(param_1 + 0x28874) != 0) {
    local_5c = param_1 + 0x20000;
    local_58 = &local_74;
    iVar3 = -1;
    piVar17 = (int *)(param_1 + 0x26874);
    local_60 = 0;
    local_64 = 0;
    uVar14 = 0;
    uVar10 = 0;
    do {
      iVar4 = 0;
      local_78 = 0;
      do {
        bVar1 = iVar4 != 2;
        iVar4 = iVar4 + 1;
      } while (bVar1);
      iVar4 = ((int (*)())FUN_0007a4a0)(param_1,param_6,param_8,param_2,*piVar17,&local_78,local_58);
      if (iVar4 != 0) {
        iVar4 = 100;
        if (uStack00000020 <= (uint)piVar17[-0x1001]) {
          iVar4 = 0;
        }
        iVar15 = *piVar17;
        iVar9 = iVar15 * 4 + param_1;
        iVar4 = *(int *)(iVar9 + 0x10454) * 2 + iVar4;
        if (*(int *)(iVar9 + 0x8450) != 0) {
          iVar4 = iVar4 + 0x20;
        }
        uVar13 = *(uint *)(iVar9 + 0x6450);
        iVar9 = 0;
        uVar18 = 0;
        puVar5 = (uint *)(param_6 + iVar15 * 0x10);
        do {
          puVar5 = puVar5 + 1;
          if (((uVar13 & 1 << (uVar18 & 0x3f)) != 0) &&
             (iVar7 = ((int (*)())FUN_000782e0)(puVar5,param_8), iVar7 != 0)) {
            bVar1 = true;
            iVar7 = 4;
            puVar6 = (undefined4 *)
                     (((char)(DAT_001aa760)[*puVar5 & 0xf] * 0x100 + (*puVar5 >> 5 & 0xff)) * 0x10
                      + param_1 + 0x2a87c);
            do {
              piVar8 = (int *)*puVar6;
              if ((piVar8 != (int *)0x0) && ((iVar15 != *piVar8 || (piVar8[1] != 0)))) {
                bVar1 = false;
              }
              iVar7 = iVar7 + -1;
              if (iVar7 == 0) {
                if (bVar1) {
                  iVar9 = iVar9 + 1;
                }
                break;
              }
              puVar6 = puVar6 + 1;
            } while (bVar1);
          }
          bVar1 = uVar18 != 2;
          uVar18 = uVar18 + 1;
        } while (bVar1);
        iVar4 = iVar9 * (param_2 - iVar11) * 2 + iVar4;
        if ((iVar3 < iVar4) || (uVar14 == 0)) {
          local_60 = (uint)local_78;
          local_64 = 1;
          uVar10 = local_74;
          iVar3 = iVar4;
          local_68 = iVar15;
        }
      }
      uVar14 = uVar14 + 1;
      piVar17 = piVar17 + 1;
    } while (uVar14 < *(uint *)(param_1 + 0x28874));
    if (local_64 != 0) {
      *puStack00000024 = (char)local_60;
      *puStack00000028 = uVar10;
      puVar5 = (uint *)(param_6 + local_68 * 0x10);
      bVar2 = (byte)*puVar5 >> 6;
      uVar14 = bVar2 & 1;
      iVar3 = (*(code *)(PTR_LAB_001e9150)[uVar14])(param_1,local_68);
      if (iVar3 == 0) {
        return local_68;
      }
      if (*(int *)(param_1 + 0x28874) == 0) {
        return local_68;
      }
      iVar3 = param_1 + 0x3148c;
      uVar13 = 0;
      piVar17 = (int *)(local_5c + 0x6874);
      pcVar12 = (char *)(iVar3 + local_68 * 4);
      do {
        iVar4 = *piVar17;
        puVar16 = (uint *)(param_6 + iVar4 * 0x10);
        uVar18 = (byte)((byte)*puVar16 >> 6) & 1;
        iVar11 = (*(code *)(PTR_LAB_001e9150)[uVar18])(param_1,iVar4);
        if ((iVar11 != 0) && (uVar14 != uVar18)) {
          iVar11 = iVar3 + iVar4 * 4;
          if ((*puVar5 & 0x40) == 0) {
            puVar16 = puVar5;
          }
          if (((((int)*pcVar12 + (int)*(char *)(iVar3 + iVar4 * 4) < 3) &&
               ((int)pcVar12[1] + (int)*(char *)(iVar11 + 1) < 2)) &&
              ((int)pcVar12[2] + (int)*(char *)(iVar11 + 2) < 2)) &&
             (((int)pcVar12[3] + (int)*(char *)(iVar11 + 3) < 2 && ((*puVar16 & 0xf00) != 0x400))))
          {
            if ((bVar2 & 1) == 0) {
              *(int *)(((unsigned char *)0x00035494) + param_1) = iVar4;
              *(int *)(((unsigned char *)0x00035498) + param_1) = local_68;
            }
            else {
              *(int *)(((unsigned char *)0x00035498) + param_1) = iVar4;
              *(int *)(((unsigned char *)0x00035494) + param_1) = local_68;
            }
            if (*(int *)(((unsigned char *)0x00035494) + param_1) == local_68) {
              iVar3 = ((int (*)())FUN_00078760)(param_1,param_6,local_68,local_77,local_70);
              if (iVar3 != 0) {
                *(undefined4 *)(((unsigned char *)0x00035490) + param_1) = 1;
                *puStack00000024 = local_77[0];
                *puStack00000028 = local_70[0];
                return local_68;
              }
              *(undefined4 *)(((unsigned char *)0x00035490) + param_1) = 0;
              return local_68;
            }
            *(undefined4 *)(((unsigned char *)0x00035490) + param_1) = 2;
            return local_68;
          }
        }
        uVar13 = uVar13 + 1;
        piVar17 = piVar17 + 1;
        if (*(uint *)(param_1 + 0x28874) <= uVar13) {
          return local_68;
        }
      } while( true );
    }
  }
  return -1;
}

/* FUN_0007b0d0 @ 0x7b0d0 (5660 bytes) */
int FUN_0007b0d0(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  int *piVar9;
  byte bVar10;
  byte bVar11;
  int iVar12;
  int *piVar13;
  undefined4 *puVar14;
  uint *puVar15;
  uint uVar16;
  uint uVar17;
  uint *puVar18;
  int iVar19;
  int iVar20;
  uint uVar21;
  uint *puVar22;
  int *piVar23;
  uint *puVar24;
  char cVar25;
  int iVar26;
  int iVar27;
  uint uVar28;
  bool bVar30;
  int iVar29;
  int iVar31;
  int *piVar32;
  uint *puVar33;
  uint uVar34;
  undefined4 *puVar35;
  int *piVar36;
  int iVar37;
  char local_b8 [4];
  undefined4 local_b4;
  char local_b0;
  char local_af;
  char local_ae;
  char local_ad;
  char local_ac;
  char local_ab;
  char local_aa;
  char local_a9;
  int local_a8 [8];
  uint local_88;
  int local_84;
  int local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  int local_70;
  int local_6c;
  uint local_68;
  uint local_64;
  int local_60;
  
  iVar19 = param_1 + 0x38;
  local_64 = 0xe;
  puVar18 = *(uint **)(param_1 + 0x34);
  uVar34 = *puVar18;
  uVar4 = uVar34 >> 6 & 1;
  if (uVar4 == 0) {
    local_64 = 0xc;
  }
  iVar27 = *(int *)(param_1 + 0x2286c);
  iVar20 = param_1 + 0x1286c;
  if (((uVar4 != 0) && ((uVar34 & 0x400) != 0)) && (iVar27 != 0)) {
    piVar23 = (int *)(param_1 + 0xc450);
    iVar26 = 0;
    iVar29 = 0;
    do {
      iVar31 = iVar20 + iVar26 * 0x10;
      ((int (*)())FUN_00078a10)(param_1,iVar29 + param_1 + 0x3148c,iVar31);
      if ((*(byte *)(iVar31 + 3) & 0x40) == 0) {
        iVar37 = param_1 + 0x3348c;
        uVar21 = *(uint *)(iVar29 + iVar37);
        *(uint *)(iVar29 + iVar37) = uVar21 | 0x10;
        uVar4 = ((int (*)())FUN_00078300)(iVar31,1);
        if ((uVar4 & 4) == 0) {
          *(uint *)(iVar29 + iVar37) = uVar21 | 0x30;
        }
      }
      else {
        iVar37 = param_1 + 0x3348c;
        uVar21 = *(uint *)(iVar29 + iVar37);
        *(uint *)(iVar29 + iVar37) = uVar21 | 1;
        uVar4 = ((int (*)())FUN_00077850)(iVar31);
        if ((((((uVar4 - 1 & uVar4) == 0) &&
              (iVar12 = (*(byte *)(iVar31 + 3) & 0xffffffbf) * 0x14,
              *(int *)(&DAT_001aa5f0 + iVar12) != 0)) &&
             (((DAT_001aa600)[iVar12] == '\0' || ((uVar34 >> 0xd & 1) != 0)))) &&
            ((uVar4 = *(uint *)(iVar20 + iVar26 * 0x10) & 0xf00, uVar4 != 0x200 && (uVar4 != 0x300))
            )) && ((*(int *)(&DAT_001aa5f4 + iVar12) == 1 ||
                   ((*(int *)(&DAT_001aa5f4 + iVar12) == 2 &&
                    ((*(uint *)(*(int *)(&DAT_001aa5f8 + iVar12) * 4 + iVar31 + 4) & 0x60001fff) ==
                     (*(uint *)(iVar31 + 4 + *(int *)(&DAT_001aa5fc + iVar12) * 4) & 0x60001fff)))))
                  )) {
          *(uint *)(iVar29 + iVar37) = uVar21 | 3;
          piVar13 = (int *)*piVar23;
          *(uint *)(iVar29 + iVar37) = uVar21 | 0x1003;
          for (; piVar13 != (int *)0x0; piVar13 = (int *)piVar13[4]) {
            *(uint *)(iVar37 + *piVar13 * 4) = *(uint *)(iVar37 + *piVar13 * 4) | 0x1000;
          }
        }
      }
      iVar26 = iVar26 + 1;
      iVar29 = iVar29 + 4;
      piVar23 = piVar23 + 1;
    } while (iVar27 != iVar26);
    uVar34 = *puVar18;
  }
  iVar26 = iVar20;
  if ((uVar34 & 2) != 0) {
    for (; iVar27 != 0; iVar27 = iVar27 + -1) {
      if (*(char *)(iVar26 + 3) == '\x04') {
        *(undefined1 *)(iVar26 + 3) = 0x80;
      }
      else if (((uVar34 >> 6 & 1) != 0) && (*(char *)(iVar26 + 3) == '\v')) {
        *(undefined1 *)(iVar26 + 3) = 0x81;
      }
      iVar26 = iVar26 + 0x10;
    }
  }
  puVar35 = *(undefined4 **)(param_1 + 0x10450);
  if (*(undefined4 **)(param_1 + 0x10450) != (undefined4 *)0x0) {
    do {
      piVar23 = puVar35 + 4;
      puVar14 = puVar35;
      puVar35 = (undefined4 *)*piVar23;
    } while ((undefined4 *)*piVar23 != (undefined4 *)0x0);
    while( true ) {
      puVar35 = puVar14;
      ((int (*)())FUN_00077560)(param_1,*puVar35,0);
      puVar14 = *(undefined4 **)(param_1 + 0x10450);
      if ((puVar14 == (undefined4 *)0x0) || (puVar35 == puVar14)) break;
      for (puVar3 = (undefined4 *)puVar14[4]; puVar35 != puVar3; puVar3 = (undefined4 *)puVar3[4]) {
        if (puVar3 == (undefined4 *)0x0) goto LAB_0007b378;
        puVar14 = puVar3;
      }
    }
  }
LAB_0007b378:
  local_88 = *(uint *)(param_1 + 0x26870);
  bVar1 = local_88 != 0;
  if (bVar1) {
    piVar23 = (int *)(((unsigned char *)0x00024870) + param_1);
    uVar4 = 0;
    do {
      iVar27 = *piVar23;
      for (piVar13 = *(int **)(iVar27 * 4 + iVar19 + 0xa418); piVar13 != (int *)0x0;
          piVar13 = (int *)piVar13[4]) {
        if ((*(uint *)(*piVar13 * 4 + param_1 + 0x3348c) & 0x10000) == 0) {
          ((int (*)())FUN_00077650)(param_1 + 0xa450 + iVar27 * 4,piVar13);
          iVar27 = *piVar23;
        }
      }
      for (piVar13 = *(int **)(iVar27 * 4 + iVar19 + 0xc418); piVar13 != (int *)0x0;
          piVar13 = (int *)piVar13[4]) {
        if ((*(uint *)(*piVar13 * 4 + param_1 + 0x3348c) & 0x10000) == 0) {
          ((int (*)())FUN_00077650)(param_1 + 0xc450 + iVar27 * 4,piVar13);
          iVar27 = *piVar23;
        }
      }
      for (piVar13 = *(int **)(iVar27 * 4 + iVar19 + 0xe418); piVar13 != (int *)0x0;
          piVar13 = (int *)piVar13[4]) {
        if ((*(uint *)(*piVar13 * 4 + param_1 + 0x3348c) & 0x10000) == 0) {
          ((int (*)())FUN_00077650)(param_1 + 0xe450 + *piVar23 * 4,piVar13);
        }
      }
      uVar4 = uVar4 + 1;
      piVar23 = piVar23 + 1;
    } while (uVar4 < *(uint *)(param_1 + 0x26870));
  }
  if ((((**(uint **)(param_1 + 0x34) & 0x40) != 0) && (bVar1)) &&
     (iVar27 = local_88 - 1, iVar27 != 0)) {
    iVar26 = 0;
    puVar24 = (uint *)(iVar20 + iVar27 * 0x10);
    puVar22 = (uint *)(iVar27 * 4 + param_1 + 0x6450);
    do {
      local_6c = iVar27 - iVar26;
      if ((puVar22[0xb40f] & 0x10000) != 0) {
        uVar4 = *puVar24;
        local_68 = *puVar22;
        if ((uVar4 & 0xf00) == 0x500) {
          iVar29 = (char)(DAT_001aa758)[uVar4 >> 8 & 0xf] * 0x100 + (uVar4 >> 0xd & 0x7f);
          if ((uVar4 & 0x100000) != 0) {
            ((int (*)())FUN_00078db0)(param_1,iVar29,0);
            uVar4 = *puVar24;
          }
          if ((uVar4 & 0x200000) != 0) {
            ((int (*)())FUN_00078db0)(param_1,iVar29,1);
            uVar4 = *puVar24;
          }
          if ((uVar4 & 0x400000) != 0) {
            ((int (*)())FUN_00078db0)(param_1,iVar29,2);
            uVar4 = *puVar24;
          }
          if ((uVar4 & 0x800000) != 0) {
            ((int (*)())FUN_00078db0)(param_1,iVar29,3);
          }
        }
        uVar4 = 0;
        puVar15 = puVar24;
        do {
          puVar15 = puVar15 + 1;
          if (((local_68 & 1 << (uVar4 & 0x3f)) != 0) && (uVar34 = *puVar15, (uVar34 & 0xf) == 1)) {
            uVar21 = 0;
            iVar29 = DAT_001aa761 * 0x100 + (uVar34 >> 5 & 0xff);
            local_60 = iVar29 + param_1 + 0x30870;
            piVar23 = (int *)(iVar29 * 0x10 + param_1 + 0x2a87c);
            do {
              uVar28 = 1 << (uVar21 & 0x3f);
              if (((1 << (uVar34 >> 0x16 & 7) | 1 << (uVar34 >> 0x13 & 7) |
                    1 << (uVar34 >> 0x10 & 7) | 1 << (uVar34 >> 0xd & 7)) & uVar28) != 0) {
                iVar29 = *piVar23;
                piVar13 = (int *)((int (*)())FUN_00078e00)(param_1 + 0x12454,8);
                if (piVar13 != (int *)0x0) {
                  piVar13[1] = iVar29;
                  *piVar13 = local_6c;
                  *piVar23 = (int)piVar13;
                  piVar23[0xc00] = -1;
                  *(byte *)(local_60 + 0xc) = (byte)uVar28 | *(byte *)(local_60 + 0xc);
                }
              }
              bVar30 = uVar21 != 3;
              piVar23 = piVar23 + 1;
              uVar21 = uVar21 + 1;
            } while (bVar30);
          }
          bVar30 = uVar4 != 2;
          uVar4 = uVar4 + 1;
        } while (bVar30);
      }
      iVar26 = iVar26 + 1;
      puVar24 = puVar24 + -4;
      puVar22 = puVar22 + -1;
    } while (iVar26 != iVar27);
  }
  uVar4 = 0;
  ((int (*)())FUN_000776b0)(param_1);
  piVar23 = (int *)(((unsigned char *)0x00024870) + param_1);
  while (uVar4 < *(uint *)(param_1 + 0x26870)) {
    iVar27 = ((int (*)())FUN_00077860)(param_1,iVar20,uVar4,**(uint **)(param_1 + 0x34) >> 6 & 1);
    if (iVar27 == 0) {
      uVar4 = uVar4 + 1;
      piVar23 = piVar23 + 1;
    }
    else {
      iVar26 = *piVar23;
      iVar27 = *(int *)(param_1 + 0x28874) * 4 + param_1;
      *(int *)(param_1 + 0x28874) = *(int *)(param_1 + 0x28874) + 1;
      *(int *)(iVar27 + 0x26874) = iVar26;
      *(undefined4 *)(iVar27 + 0x22870) = 0;
      iVar27 = iVar26 * 4 + param_1;
      ((int (*)())FUN_00077760)(uVar4,param_1 + 0x26870,((unsigned char *)0x00024870) + param_1);
      *(uint *)(iVar27 + 0x3348c) = *(uint *)(iVar27 + 0x3348c) & 0xfffeffff | 0x20000;
    }
  }
LAB_0007b7a4:
  if (*(uint *)(param_1 + 0x2a878) < local_88) {
    if (*(int *)(param_1 + 0x28874) == 0) {
      return 2;
    }
    iVar27 = ((int (*)())FUN_0007aae0)(param_1,local_64,9,local_b8,&local_b4,iVar20,*puVar18,*puVar18 >> 6 & 1);
    if (iVar27 < 0) {
      uVar4 = **(uint **)(param_1 + 0x34);
      bVar30 = true;
      while (((uVar4 >> 6 & 1) != 0 && (local_64 < 0x20))) {
        if (local_64 == 0x12) {
          local_64 = 0x18;
        }
        else if (local_64 == 0x18) {
          local_64 = 0x20;
        }
        else if (local_64 == 0xe) {
          local_64 = 0x12;
        }
        iVar27 = ((int (*)())FUN_0007aae0)(param_1,local_64,9,local_b8,&local_b4,iVar20,*puVar18);
        bVar30 = iVar27 < 0;
        if (!bVar30) goto LAB_0007b894;
        uVar4 = **(uint **)(param_1 + 0x34);
      }
      if (bVar30) {
        return 3;
      }
    }
LAB_0007b894:
    iVar29 = 0;
    iVar26 = iVar20 + iVar27 * 0x10;
    puVar22 = (uint *)(param_1 + 0x1286c + iVar27 * 0x10);
    do {
      iVar26 = iVar26 + 4;
      bVar30 = iVar29 != 8;
      *(int *)(iVar29 + (int)local_a8) = iVar26;
      iVar29 = iVar29 + 4;
    } while (bVar30);
    if (local_b8[0] == '\0') {
      puVar24 = *(uint **)(param_1 + 0x34);
    }
    else {
      puVar24 = *(uint **)(param_1 + 0x34);
      uVar4 = *puVar24 >> 6 & 1;
      iVar26 = ((int (*)())FUN_000777b0)(puVar22,uVar4);
      if (iVar26 == 0) {
        iVar26 = ((int (*)())FUN_00077800)(puVar22,uVar4);
        if (iVar26 != 0) {
          ((int (*)())FUN_0007a1a0)(param_1,iVar27,local_b4);
          puVar24 = *(uint **)(param_1 + 0x34);
        }
      }
      else {
        ((int (*)())FUN_00078b80)(param_1,iVar27,local_b4);
        puVar24 = *(uint **)(param_1 + 0x34);
      }
    }
    iVar26 = ((int (*)())FUN_00078f80)(param_1,iVar27,local_a8,iVar20,*puVar24 >> 6 & 1);
    if (iVar26 != 0) {
      return iVar26;
    }
    iVar26 = ((int (*)())FUN_000777b0)(puVar22,**(uint **)(param_1 + 0x34) >> 6 & 1);
    if (iVar26 == 0) {
      iVar26 = iVar27 * 4;
      iVar29 = ((int (*)())FUN_00077800)(puVar22,*puVar18 >> 6 & 1);
      if (iVar29 != 0) {
        uVar8 = ((int (*)())FUN_00077850)(puVar22);
        iVar29 = ((int (*)())FUN_00077c40)(param_1,iVar27,uVar8,1);
        if (iVar29 != 0) {
          return iVar29;
        }
        for (puVar35 = *(undefined4 **)(iVar26 + iVar19 + 0xc418); puVar35 != (undefined4 *)0x0;
            puVar35 = (undefined4 *)puVar35[4]) {
          iVar29 = ((int (*)())FUN_00077c40)(param_1,*puVar35,puVar35[1],1);
          if (iVar29 != 0) {
            return iVar29;
          }
        }
        for (puVar35 = *(undefined4 **)(iVar26 + iVar19 + 0xe418); puVar35 != (undefined4 *)0x0;
            puVar35 = (undefined4 *)puVar35[4]) {
          ((int (*)())FUN_00077c40)(param_1,*puVar35,puVar35[1],1);
        }
        piVar13 = (int *)(param_1 + 0x30b7c);
        uVar4 = 0;
        piVar23 = *(int **)(iVar26 + iVar19 + 0xa418);
        do {
          if (piVar23 != (int *)0x0) {
            bVar30 = false;
            piVar36 = piVar23;
            do {
              if ((1 << (uVar4 & 0x3f) & piVar36[1]) != 0) {
                if (bVar30) {
                  piVar9 = (int *)*piVar13;
                  do {
                    piVar32 = piVar9;
                    if (*piVar32 == *piVar36) goto LAB_0007bdf0;
                    piVar9 = (int *)piVar32[1];
                  } while ((int *)piVar32[1] != (int *)0x0);
                  piVar9 = (int *)((int (*)())FUN_00078e00)(param_1 + 0x12454,8);
                  piVar32[1] = (int)piVar9;
                  if (piVar9 == (int *)0x0) {
                    return 7;
                  }
                  iVar26 = *piVar36;
                  piVar9[1] = 0;
                  *piVar9 = iVar26;
                }
                else {
                  if (*piVar13 != 0) {
                    return 6;
                  }
                  piVar9 = (int *)((int (*)())FUN_00078e00)(param_1 + 0x12454,8);
                  *piVar13 = (int)piVar9;
                  if (piVar9 == (int *)0x0) {
                    return 7;
                  }
                  *piVar9 = *piVar36;
                  *(undefined4 *)(*piVar13 + 4) = 0;
                  bVar30 = true;
                }
              }
LAB_0007bdf0:
              piVar36 = (int *)piVar36[4];
            } while (piVar36 != (int *)0x0);
          }
          bVar30 = uVar4 != 3;
          piVar13 = piVar13 + 1;
          uVar4 = uVar4 + 1;
        } while (bVar30);
      }
    }
    else {
      uVar4 = *puVar22;
      cVar25 = (DAT_001aa758)[uVar4 >> 8 & 0xf];
      uVar8 = ((int (*)())FUN_00077850)(puVar22);
      iVar26 = ((int (*)())FUN_00077ba0)(param_1,iVar27,cVar25 * 0x100 + (uVar4 >> 0xd & 0x7f),uVar8,1);
      if (iVar26 != 0) {
        return iVar26;
      }
      iVar26 = iVar27 * 4;
      uVar4 = 0;
      for (puVar24 = *(uint **)(iVar26 + iVar19 + 0xc418); puVar24 != (uint *)0x0;
          puVar24 = (uint *)puVar24[4]) {
        uVar34 = *puVar24;
        if ((*(uint *)(uVar34 * 4 + param_1 + 0x3348c) & 0x40000) == 0) {
          uVar28 = ((int (*)())FUN_00077850)(param_1 + 0x1286c + uVar34 * 0x10);
          uVar21 = 0;
          puVar15 = (uint *)(local_a8 + 3);
          iVar29 = 4;
          do {
            uVar5 = 1 << (uVar21 & 0x3f);
            if ((uVar28 & uVar5) != 0) {
              if ((uVar5 & uVar4) == 0) {
                *puVar15 = uVar34;
                uVar4 = uVar4 | uVar5;
              }
              else if (uVar34 < *puVar15) {
                *puVar15 = uVar34;
              }
            }
            uVar21 = uVar21 + 1;
            puVar15 = puVar15 + 1;
            iVar29 = iVar29 + -1;
          } while (iVar29 != 0);
        }
      }
      uVar34 = 0;
      piVar23 = local_a8 + 3;
      do {
        uVar21 = 1 << (uVar34 & 0x3f);
        if (((uVar4 & uVar21) != 0) &&
           (iVar29 = ((int (*)())FUN_00077ba0)(param_1,*piVar23,
                                  (char)(DAT_001aa758)[*puVar22 >> 8 & 0xf] * 0x100 +
                                  (*puVar22 >> 0xd & 0x7f),uVar21,0), iVar29 != 0)) {
          return iVar29;
        }
        bVar30 = uVar34 != 3;
        piVar23 = piVar23 + 1;
        uVar34 = uVar34 + 1;
      } while (bVar30);
      for (puVar35 = *(undefined4 **)(iVar26 + iVar19 + 0xe418); puVar35 != (undefined4 *)0x0;
          puVar35 = (undefined4 *)puVar35[4]) {
        ((int (*)())FUN_00077ba0)(param_1,*puVar35,
                     (char)(DAT_001aa758)[*puVar22 >> 8 & 0xf] * 0x100 + (*puVar22 >> 0xd & 0x7f),
                     puVar35[1],0);
      }
      uVar4 = 0;
      piVar23 = *(int **)(iVar26 + iVar19 + 0xa418);
      piVar13 = (int *)(((char)(DAT_001aa758)[*puVar22 >> 8 & 0xf] * 0x100 +
                        (*puVar22 >> 0xd & 0x7f)) * 0x10 + param_1 + 0x2a87c);
      do {
        if (piVar23 != (int *)0x0) {
          bVar30 = false;
          piVar36 = piVar23;
          do {
            if ((1 << (uVar4 & 0x3f) & piVar36[1]) != 0) {
              if (bVar30) {
                piVar9 = (int *)*piVar13;
                do {
                  piVar32 = piVar9;
                  if (*piVar32 == *piVar36) goto LAB_0007bc50;
                  piVar9 = (int *)piVar32[1];
                } while ((int *)piVar32[1] != (int *)0x0);
                piVar9 = (int *)((int (*)())FUN_00078e00)(param_1 + 0x12454,8);
                piVar32[1] = (int)piVar9;
                if (piVar9 == (int *)0x0) {
                  return 7;
                }
                iVar26 = *piVar36;
                piVar9[1] = 0;
                *piVar9 = iVar26;
              }
              else {
                if (*piVar13 != 0) {
                  return 6;
                }
                piVar9 = (int *)((int (*)())FUN_00078e00)(param_1 + 0x12454,8);
                *piVar13 = (int)piVar9;
                if (piVar9 == (int *)0x0) {
                  return 7;
                }
                *piVar9 = *piVar36;
                *(undefined4 *)(*piVar13 + 4) = 0;
                bVar30 = true;
              }
            }
LAB_0007bc50:
            piVar36 = (int *)piVar36[4];
          } while (piVar36 != (int *)0x0);
        }
        bVar30 = uVar4 != 3;
        piVar13 = piVar13 + 1;
        uVar4 = uVar4 + 1;
      } while (bVar30);
    }
    iVar26 = iVar27 * 4 + param_1;
    iVar31 = *(int *)(param_1 + 0x2a878);
    iVar29 = *(int *)(param_1 + 0x28874);
    uVar4 = *(uint *)(iVar26 + 0x3348c);
    *(int *)(param_1 + 0x2a878) = iVar31 + 1;
    *(int *)(iVar31 * 4 + param_1 + 0x28878) = iVar27;
    *(uint *)(iVar26 + 0x3348c) = uVar4 & 0xfffdffff | 0x40000;
    uVar4 = 0;
    if (iVar29 != 0) {
      piVar23 = (int *)(param_1 + 0x26874);
      uVar34 = 0;
      iVar26 = 1;
      iVar29 = 0x22874;
      do {
        if ((iVar27 == *piVar23) && (uVar34 < *(int *)(param_1 + 0x28874) - 1U)) {
          puVar35 = (undefined4 *)(param_1 + iVar29);
          uVar4 = uVar34;
          do {
            iVar31 = *(int *)(param_1 + 0x28874);
            uVar4 = uVar4 + 1;
            uVar8 = puVar35[0x1001];
            puVar35[uVar34 - iVar26] = *puVar35;
            puVar35[0x1000] = uVar8;
            puVar35 = puVar35 + 1;
          } while (uVar4 < iVar31 - 1U);
        }
        uVar4 = *(uint *)(param_1 + 0x28874);
        uVar34 = uVar34 + 1;
        iVar26 = iVar26 + 1;
        iVar29 = iVar29 + 4;
        piVar23 = piVar23 + 1;
      } while (uVar34 < uVar4);
    }
    iVar27 = *(int *)(((unsigned char *)0x00035490) + param_1);
    *(uint *)(param_1 + 0x28874) = uVar4 - 1;
    if ((iVar27 != 3) && (uVar4 - 1 != 0)) {
      piVar23 = (int *)(param_1 + 0x22870);
      uVar4 = 0;
      do {
        if (*piVar23 != 0) {
          *piVar23 = *piVar23 + -1;
        }
        uVar4 = uVar4 + 1;
        piVar23 = piVar23 + 1;
      } while (uVar4 < *(uint *)(param_1 + 0x28874));
    }
    uVar4 = 0;
    ((int (*)())FUN_000776b0)(param_1);
    piVar23 = (int *)(((unsigned char *)0x00024870) + param_1);
    while (uVar4 < *(uint *)(param_1 + 0x26870)) {
      iVar27 = ((int (*)())FUN_00077860)(param_1,iVar20,uVar4,**(uint **)(param_1 + 0x34) >> 6 & 1);
      if (iVar27 == 0) {
        uVar4 = uVar4 + 1;
        piVar23 = piVar23 + 1;
      }
      else {
        iVar26 = *piVar23;
        iVar27 = *(int *)(param_1 + 0x28874) * 4 + param_1;
        *(int *)(param_1 + 0x28874) = *(int *)(param_1 + 0x28874) + 1;
        *(int *)(iVar27 + 0x26874) = iVar26;
        *(undefined4 *)(iVar27 + 0x22870) = 9;
        iVar27 = iVar26 * 4 + param_1;
        ((int (*)())FUN_00077760)(uVar4,param_1 + 0x26870,((unsigned char *)0x00024870) + param_1);
        *(uint *)(iVar27 + 0x3348c) = *(uint *)(iVar27 + 0x3348c) & 0xfffeffff | 0x20000;
      }
    }
    if (((*puVar18 & 0x10) == 0) || (iVar27 = ((int (*)())FUN_00079e70)(param_1,0), iVar27 == 0))
    goto LAB_0007b7a4;
  }
  else {
    uVar4 = **(uint **)(param_1 + 0x34);
    if (bVar1) {
      uVar34 = 0;
      iVar27 = iVar20;
      do {
        iVar26 = ((int (*)())FUN_00079e10)(iVar27);
        if (iVar26 != 0) {
          if (*(char *)(iVar27 + 3) == '\x04') {
            *(undefined1 *)(iVar27 + 3) = 0x80;
          }
          else if (((uVar4 >> 6 & 1) != 0) && (*(char *)(iVar27 + 3) == '\v')) {
            *(undefined1 *)(iVar27 + 3) = 0x81;
          }
        }
        uVar34 = uVar34 + 1;
        iVar27 = iVar27 + 0x10;
      } while (local_88 != uVar34);
    }
    if (((*puVar18 & 0x20) != 0) && (iVar27 = ((int (*)())FUN_00079e70)(param_1,1), iVar27 != 0)) {
      return iVar27;
    }
    iVar27 = *(int *)(param_1 + 0x34);
    if (*(int *)(param_1 + 0x2a878) == 0) {
      uVar21 = 0;
      uVar4 = 0;
      uVar34 = 0;
      local_70 = 0;
      local_74 = 0;
      local_78 = 0;
      local_80 = 0;
    }
    else {
      uVar4 = 0;
      local_7c = 0;
      local_70 = 0;
      uVar34 = 0;
      uVar21 = 0;
      local_74 = 0;
      local_78 = 0;
      local_80 = 0;
      iVar26 = param_1 + 0x30000;
      do {
        iVar29 = *(int *)(iVar26 + -0x7788) * 4;
        puVar22 = (uint *)(uVar21 * 0x10 + *(int *)(iVar27 + 0x18));
        puVar18 = (uint *)(iVar20 + *(int *)(iVar26 + -0x7788) * 0x10);
        if ((*(uint *)(iVar29 + param_1 + 0x3348c) & 0x100) == 0) {
LAB_0007c4b0:
          bVar11 = 0;
          uVar28 = *(uint *)(iVar29 + iVar19 + 0x6418);
          uVar5 = 0;
          cVar25 = *(char *)(iVar29 + iVar19 + 0x841b);
          puVar24 = puVar18;
          do {
            puVar24 = puVar24 + 1;
            if ((uVar28 & 1 << (uVar5 & 0x3f)) != 0) {
              bVar10 = ((int (*)())FUN_00077cd0)(puVar24,**(uint **)(param_1 + 0x34) >> 6 & 1);
              bVar11 = bVar10 | bVar11;
            }
            bVar1 = uVar5 != 2;
            uVar5 = uVar5 + 1;
          } while (bVar1);
        }
        else {
          local_84 = *(int *)(iVar26 + -0x7784);
          puVar33 = (uint *)(iVar20 + local_84 * 0x10);
          puVar24 = puVar33;
          puVar15 = puVar18;
          if ((*puVar18 & 0x40) == 0) {
            puVar24 = puVar18;
            puVar15 = puVar33;
          }
          uVar28 = *puVar15;
          uVar5 = *puVar15;
          puVar24[3] = 0;
          puVar33 = puVar24 + 3;
          uVar5 = uVar5 >> 0x14 & 0xf;
          ((int (*)())FUN_00078a10)(param_1,&local_b0,puVar24);
          ((int (*)())FUN_00078a10)(param_1,&local_ac,puVar15);
          if ((((2 < (int)local_b0 + (int)local_ac) || (1 < (int)local_af + (int)local_ab)) ||
              (1 < (int)local_ae + (int)local_aa)) ||
             ((1 < (int)local_ad + (int)local_a9 || ((*puVar24 & 0xf00) == 0x400))))
          goto LAB_0007c4b0;
          uVar6 = puVar24[3];
          uVar17 = (*puVar15 & 0x6000) << 6;
          puVar24[3] = uVar17 | uVar6 & 0xffe7ffff;
          uVar2 = ((byte)*puVar15 & 0xf) << 0x15;
          puVar24[3] = uVar2 | uVar17 | uVar6 & 0xfe07ffff;
          uVar16 = (byte)((byte)*puVar15 >> 2) & 4;
          puVar24[3] = uVar16 | uVar2 | uVar17 | uVar6 & 0xfe07fffb;
          if (uVar5 == 2) {
            puVar24[3] = uVar16 | uVar2 | uVar17 | uVar6 & 0xe607fffb | 0x8000000;
          }
          else if (uVar5 < 3) {
            if (uVar5 == 1) {
              *puVar33 = uVar16 | uVar2 | uVar17 | uVar6 & 0xe607fffb;
            }
          }
          else if (uVar5 == 4) {
            puVar24[3] = uVar16 | uVar2 | uVar17 | uVar6 & 0xe607fffb | 0x10000000;
          }
          else if (uVar5 == 8) {
            *puVar33 = uVar16 | uVar2 | uVar17 | uVar6 & 0xe607fffb | 0x18000000;
          }
          iVar31 = ((byte)uVar28 & 0x1f) * 0x14;
          uVar28 = *(uint *)(&DAT_001aa5f8 + iVar31);
          if (uVar28 < 3) {
            uVar7 = *puVar33;
            uVar17 = puVar15[uVar28 + 1] & 3;
            *puVar33 = uVar17 | uVar7 & 0xfffffffc;
            uVar16 = puVar15[uVar28 + 1] & 0x10;
            *puVar33 = uVar16 | uVar17 | uVar7 & 0xffffffec;
            uVar2 = puVar15[uVar28 + 1] & 0x1fe0;
            *puVar33 = uVar2 | uVar16 | uVar17 | uVar7 & 0xffffe00c;
            uVar6 = puVar15[uVar28 + 1] & 0x60000000;
            *puVar33 = uVar6 | uVar2 | uVar16 | uVar17 | uVar7 & 0x9fffe00c;
            uVar5 = puVar15[uVar28 + 1] >> 3 & 0x2000000;
            *puVar33 = uVar5 | uVar6 | uVar2 | uVar16 | uVar17 | uVar7 & 0x9dffe00c;
            *puVar33 = puVar15[uVar28 + 1] >> 9 & 0xe000 |
                       uVar5 | uVar6 | uVar2 | uVar16 | uVar17 | uVar7 & 0x9dff000c;
          }
          uVar28 = *(uint *)(&DAT_001aa5fc + iVar31);
          if (uVar28 < 3) {
            uVar7 = *puVar33;
            uVar17 = puVar15[uVar28 + 1] & 3;
            *puVar33 = uVar17 | uVar7 & 0xfffffffc;
            uVar16 = puVar15[uVar28 + 1] & 0x10;
            *puVar33 = uVar16 | uVar17 | uVar7 & 0xffffffec;
            uVar2 = puVar15[uVar28 + 1] & 0x1fe0;
            *puVar33 = uVar2 | uVar16 | uVar17 | uVar7 & 0xffffe00c;
            uVar6 = puVar15[uVar28 + 1] & 0x60000000;
            *puVar33 = uVar6 | uVar2 | uVar16 | uVar17 | uVar7 & 0x9fffe00c;
            uVar5 = puVar15[uVar28 + 1] >> 2 & 0x4000000;
            *puVar33 = uVar5 | uVar6 | uVar2 | uVar16 | uVar17 | uVar7 & 0x9bffe00c;
            *puVar33 = puVar15[uVar28 + 1] >> 6 & 0x70000 |
                       uVar5 | uVar6 | uVar2 | uVar16 | uVar17 | uVar7 & 0x9bf8e00c;
          }
          *puVar24 = *puVar24 | 0x10000000;
          if ((*(int *)(iVar29 + iVar19 + 0x8418) != 0) ||
             (cVar25 = '\0', *(int *)(local_84 * 4 + iVar19 + 0x8418) != 0)) {
            cVar25 = '\x01';
          }
          bVar11 = 0;
          uVar5 = 0;
          uVar28 = *(uint *)(iVar29 + iVar19 + 0x6418);
          do {
            puVar18 = puVar18 + 1;
            if ((uVar28 & 1 << (uVar5 & 0x3f)) != 0) {
              bVar10 = ((int (*)())FUN_00077cd0)(puVar18,**(uint **)(param_1 + 0x34) >> 6 & 1);
              bVar11 = bVar10 | bVar11;
            }
            bVar1 = uVar5 != 2;
            uVar5 = uVar5 + 1;
          } while (bVar1);
          if (bVar11 == 0) {
            uVar5 = 0;
            iVar29 = iVar20 + local_84 * 0x10;
            uVar28 = *(uint *)(local_84 * 4 + iVar19 + 0x6418);
            bVar10 = 0;
            do {
              iVar29 = iVar29 + 4;
              if ((uVar28 & 1 << (uVar5 & 0x3f)) != 0) {
                bVar11 = ((int (*)())FUN_00077cd0)(iVar29,**(uint **)(param_1 + 0x34) >> 6 & 1);
                bVar10 = bVar11 | bVar10;
              }
              bVar1 = uVar5 != 2;
              uVar5 = uVar5 + 1;
            } while (bVar1);
            bVar11 = 0;
            if (bVar10 != 0) goto LAB_0007c484;
          }
          else {
LAB_0007c484:
            bVar11 = 1;
          }
          iVar26 = iVar26 + 4;
          local_80 = local_80 + 1;
          local_7c = local_7c + 1;
          puVar18 = puVar24;
        }
        if ((cVar25 != '\0') && (iVar29 = *(int *)(iVar27 + 0x20), local_74 = uVar21, iVar29 != 0))
        {
          uVar17 = puVar18[1];
          uVar5 = puVar18[2];
          uVar28 = puVar18[3];
          iVar31 = local_70 * 0x10;
          local_70 = local_70 + 1;
          iVar37 = iVar29 + iVar31;
          *(uint *)(iVar29 + iVar31) = *puVar18;
          *(uint *)(iVar37 + 0xc) = uVar28;
          *(uint *)(iVar37 + 4) = uVar17;
          *(uint *)(iVar37 + 8) = uVar5;
        }
        uVar28 = *puVar18;
        if (((uVar28 & 0xf00) != 0x800) ||
           (bVar1 = true, (**(uint **)(param_1 + 0x34) >> 6 & 1) != 0)) {
          bVar1 = false;
        }
        if (bVar1) {
          uVar34 = uVar21;
        }
        if (bVar11 != 0) {
          uVar4 = uVar21;
        }
        iVar29 = ((int (*)())FUN_00077cf0)(puVar18);
        if ((iVar29 != 0) && (uVar5 = (uVar28 >> 0xd & 0x7f) + 1, local_78 < uVar5)) {
          local_78 = uVar5;
        }
        if (uVar21 == 0x400) {
          return 10;
        }
        uVar5 = puVar18[3];
        uVar17 = puVar18[1];
        uVar21 = uVar21 + 1;
        iVar26 = iVar26 + 4;
        uVar16 = puVar18[2];
        *puVar22 = uVar28;
        puVar22[3] = uVar5;
        puVar22[1] = uVar17;
        puVar22[2] = uVar16;
        local_7c = local_7c + 1;
      } while (local_7c < *(uint *)(param_1 + 0x2a878));
    }
    **(uint **)(iVar27 + 0x1c) = uVar21;
    puVar18 = *(uint **)(iVar27 + 0x28);
    if (puVar18 != (uint *)0x0) {
      if ((**(uint **)(param_1 + 0x34) & 0x40) == 0) {
        if (local_74 < uVar34) {
          local_74 = uVar34;
        }
        *puVar18 = local_74;
      }
      else {
        *puVar18 = local_74;
      }
    }
    if (*(uint **)(iVar27 + 0x2c) != (uint *)0x0) {
      **(uint **)(iVar27 + 0x2c) = uVar4;
    }
    if (*(uint **)(iVar27 + 0x30) != (uint *)0x0) {
      **(uint **)(iVar27 + 0x30) = local_78;
    }
    if (*(int *)(iVar27 + 0x20) != 0) {
      **(int **)(iVar27 + 0x24) = local_70;
    }
    iVar27 = 0;
    *(int *)(((unsigned char *)0x0003548c) + param_1) = local_80;
  }
  return iVar27;
}

/* FUN_0007c760 @ 0x7c760 (4940 bytes) */
int FUN_0007c760(param_1)
  uint *param_1;
{
  uint *puVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  uint *puVar12;
  uint uVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  undefined4 *puVar18;
  int iVar19;
  uint uVar20;
  uint *puVar21;
  uint uVar22;
  char cVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  uint *puVar27;
  uint uVar28;
  int *piVar29;
  uint *puVar30;
  undefined4 *puVar31;
  byte in_xer_so;
  int iVar32;
  int iVar33;
  uint local_b8;
  uint *local_b4;
  uint *local_b0;
  uint *local_ac;
  uint *local_a8;
  uint **local_a4;
  int local_a0;
  uint *local_9c;
  int local_98;
  int local_94;
  int local_90;
  uint local_8c;
  int local_88;
  uint *local_84;
  uint *local_80;
  uint *local_7c;
  uint local_78;
  undefined4 *local_74;
  int *local_70;
  uint local_6c;
  int *local_68;
  uint *local_64;
  int local_60;
  uint **local_5c;
  
  if (0x800 < param_1[2]) {
    return 10;
  }
  if (param_1[2] == 0) {
    return 1;
  }
  param_1[0xd] = (uint)param_1;
  local_64 = param_1 + 0xc000;
  ((int (*)())FUN_0007a060)(param_1 + 0x4915);
  iVar19 = 0;
  local_64[-0x15e2] = 0;
  local_64[-0x1de3] = 0;
  puVar21 = local_64 + 0x21f;
  puVar9 = local_64 + -0x15e4;
  do {
    *(undefined1 *)puVar21 = 0;
    puVar8 = puVar9 + 3;
    iVar32 = 4;
    do {
      *puVar8 = 0;
      puVar8[0xc00] = 0;
      puVar8 = puVar8 + 1;
      iVar32 = iVar32 + -1;
    } while (iVar32 != 0);
    bVar2 = iVar19 != 0x2ff;
    puVar9 = puVar9 + 4;
    puVar21 = (uint *)((int)puVar21 + 1);
    iVar19 = iVar19 + 1;
  } while (bVar2);
  iVar19 = 4;
  *(undefined1 *)(local_64 + 0x2e7) = 0;
  puVar9 = local_64 + 0x2df;
  do {
    *puVar9 = 0;
    puVar9[4] = 0;
    puVar9 = puVar9 + 1;
    iVar19 = iVar19 + -1;
  } while (iVar19 != 0);
  param_1[0x9a1c] = 0;
  _memset(local_64 + 0x523,0,0x2000);
  iVar19 = 0x800;
  puVar9 = local_64 + 0xd23;
  do {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
    iVar19 = iVar19 + -1;
  } while (iVar19 != 0);
  puVar8 = param_1 + 0xe;
  local_64[0x1523] = 0;
  ((int (*)())FUN_0007a060)(puVar8);
  puVar21 = param_1 + 0x3914;
  iVar19 = 0;
  puVar9 = param_1 + 0x112;
  do {
    puVar10 = puVar9 + 2;
    iVar32 = 0;
    do {
      bVar2 = iVar32 != 2;
      *puVar10 = 0;
      iVar32 = iVar32 + 1;
      puVar10 = puVar10 + 1;
    } while (bVar2);
    bVar2 = iVar19 != 0x7ff;
    puVar21[-0x1000] = 0;
    puVar21[-0x800] = 0;
    *puVar21 = 0;
    puVar21[-0x2000] = 0;
    puVar21[-0x1800] = 0;
    puVar21[0x801] = 0;
    param_1[0x4114] = 0;
    puVar9 = puVar9 + 3;
    puVar21 = puVar21 + 1;
    iVar19 = iVar19 + 1;
  } while (bVar2);
  if ((*param_1 & 0x40) == 0) {
    param_1[0x8a1b] = param_1[2];
    _memcpy(param_1 + 0x4a1b,(void *)param_1[1],param_1[2] << 4);
  }
  else {
    uVar11 = param_1[2];
    param_1[0x8a1b] = uVar11;
    param_1[0x8a1b] = 0;
    if (uVar11 != 0) {
      puVar10 = param_1 + 0x4a1b;
      puVar9 = (uint *)param_1[1];
      puVar21 = puVar10;
      while( true ) {
        uVar20 = puVar9[1];
        uVar17 = puVar9[2];
        uVar22 = puVar9[3];
        *puVar21 = *puVar9;
        puVar21[1] = uVar20;
        puVar21[2] = uVar17;
        puVar21[3] = uVar22;
        uVar20 = param_1[0x8a1b] + 1;
        param_1[0x8a1b] = uVar20;
        if ((*puVar9 & 0x10000000) != 0) {
          puVar27 = puVar9 + 3;
          puVar30 = puVar10 + uVar20 * 4;
          iVar19 = (puVar9[3] >> 0x15 & 0xf) * 0x14;
          if (0x7ff < uVar20) {
            return 10;
          }
          puVar21[3] = 0x124800;
          *puVar21 = *puVar21 & 0xefffffff;
          puVar10[uVar20 * 4] = 0;
          puVar30[3] = 0x124800;
          puVar30[1] = 0x124800;
          puVar30[2] = 0x124800;
          *(byte *)((int)puVar30 + 3) = (byte)(puVar9[3] >> 0x15) & 0xf | 0x40;
          uVar17 = puVar10[uVar20 * 4];
          puVar10[uVar20 * 4] = uVar17 & 0xfffff0ff | 0x400;
          uVar17 = (puVar9[3] >> 0x13 & 3) << 0xd | uVar17 & 0xff0010ff | 0x400;
          puVar10[uVar20 * 4] = uVar17;
          uVar22 = puVar9[3] >> 0x1b & 3;
          if (uVar22 == 1) {
            puVar10[uVar20 * 4] = uVar17 | 0x200000;
          }
          else if (uVar22 < 2) {
            if (uVar22 == 0) {
              puVar10[uVar20 * 4] = uVar17 | 0x100000;
            }
          }
          else if (uVar22 == 2) {
            puVar10[uVar20 * 4] = uVar17 | 0x400000;
          }
          else if (uVar22 == 3) {
            puVar10[uVar20 * 4] = uVar17 | 0x800000;
          }
          *puVar30 = *puVar30 & 0xefffffff;
          uVar20 = *(uint *)(&DAT_001aa5f8 + iVar19);
          if (uVar20 < 3) {
            uVar7 = puVar30[uVar20 + 1];
            uVar22 = *puVar27 & 3;
            puVar30[uVar20 + 1] = uVar22 | uVar7 & 0xfffffff0;
            uVar13 = *puVar27 & 0x10;
            puVar30[uVar20 + 1] = uVar13 | uVar22 | uVar7 & 0xffffffe0;
            uVar28 = *puVar27 & 0x1fe0;
            puVar30[uVar20 + 1] = uVar28 | uVar13 | uVar22 | uVar7 & 0xffffe000;
            uVar5 = *puVar27 & 0x60000000;
            puVar30[uVar20 + 1] = uVar5 | uVar28 | uVar13 | uVar22 | uVar7 & 0x9fffe000;
            uVar17 = (*puVar27 & 0x2000000) << 3;
            puVar30[uVar20 + 1] = uVar17 | uVar5 | uVar28 | uVar13 | uVar22 | uVar7 & 0x8fffe000;
            puVar30[uVar20 + 1] =
                 (*puVar27 & 0xe000) << 9 |
                 uVar17 | uVar5 | uVar28 | uVar13 | uVar22 | uVar7 & 0x8e3fe000;
          }
          uVar20 = *(uint *)(&DAT_001aa5fc + iVar19);
          if (uVar20 < 3) {
            uVar7 = puVar30[uVar20 + 1];
            uVar22 = *puVar27 & 3;
            puVar30[uVar20 + 1] = uVar22 | uVar7 & 0xfffffff0;
            uVar13 = *puVar27 & 0x10;
            puVar30[uVar20 + 1] = uVar13 | uVar22 | uVar7 & 0xffffffe0;
            uVar28 = *puVar27 & 0x1fe0;
            puVar30[uVar20 + 1] = uVar28 | uVar13 | uVar22 | uVar7 & 0xffffe000;
            uVar5 = *puVar27 & 0x60000000;
            puVar30[uVar20 + 1] = uVar5 | uVar28 | uVar13 | uVar22 | uVar7 & 0x9fffe000;
            uVar17 = (*puVar27 & 0x4000000) << 2;
            puVar30[uVar20 + 1] = uVar17 | uVar5 | uVar28 | uVar13 | uVar22 | uVar7 & 0x8fffe000;
            puVar30[uVar20 + 1] =
                 (*(ushort *)puVar27 & 7) << 0x16 |
                 uVar17 | uVar5 | uVar28 | uVar13 | uVar22 | uVar7 & 0x8e3fe000;
          }
          param_1[0x8a1b] = param_1[0x8a1b] + 1;
        }
        uVar11 = uVar11 - 1;
        if (uVar11 == 0) break;
        puVar21 = puVar10 + param_1[0x8a1b] * 4;
        puVar9 = puVar9 + 4;
        if (0x7ff < param_1[0x8a1b]) {
          return 10;
        }
      }
    }
  }
  local_78 = param_1[0x8a1b];
  puVar9 = param_1 + 0x4a1b;
  local_74 = (undefined4 *)param_1[6];
  local_70 = (int *)param_1[10];
  local_6c = param_1[8];
  local_68 = (int *)param_1[9];
  if ((uint *)param_1[7] != (uint *)0x0) {
    *(uint *)param_1[7] = local_78;
  }
  local_60 = (uint)(byte)(((int)local_70 < 0) << 3 | (0 < (int)local_70) << 2 |
                          (local_70 == (int *)0x0) << 1 | in_xer_so & 1) << 0x1c;
  if (local_70 != (int *)0x0) {
    *local_70 = local_78 - 1;
  }
  local_98 = local_78 - 1;
  if (-1 < local_98) {
    iVar19 = local_98 * 4;
    iVar25 = local_98 * 0xc;
    puVar30 = puVar9 + local_98 * 4;
    local_94 = 0;
    puVar10 = local_74 + local_98 * 4;
    local_5c = &local_b4;
    bVar2 = local_74 == (undefined4 *)0x0;
    puVar21 = puVar8 + local_78 + 0x1905;
    iVar24 = 0;
    iVar26 = local_98;
    iVar32 = local_98;
    do {
      iVar32 = iVar32 + -1;
      if (bVar2) {
LAB_0007cc7c:
        puVar27 = (uint *)param_1[0xd];
      }
      else {
        puVar27 = (uint *)param_1[0xd];
        if ((*puVar27 & 0x200) == 0) {
          iVar33 = 4;
          puVar27 = puVar10;
          puVar12 = puVar30;
          do {
            uVar11 = *puVar12;
            puVar12 = puVar12 + 1;
            *puVar27 = uVar11;
            puVar27 = puVar27 + 1;
            iVar33 = iVar33 + -1;
          } while (iVar33 != 0);
          goto LAB_0007cc7c;
        }
      }
      iVar33 = 0;
      puVar12 = puVar9 + iVar19;
      do {
        puVar12 = puVar12 + 1;
        bVar3 = iVar33 != 8;
        *(uint **)(iVar33 + (int)local_5c) = puVar12;
        iVar33 = iVar33 + 4;
      } while (bVar3);
      local_a8 = puVar9 + iVar19;
      uVar11 = ((int (*)())FUN_00077850)(puVar30);
      if (uVar11 == 0) {
LAB_0007ceb8:
        local_90 = 0;
      }
      else {
        if ((*puVar27 & 0x40) == 0) {
          uVar20 = *puVar30;
          if ((uVar20 >> 8 & 0xf) - 4 < 5) {
            for (piVar29 = (int *)param_1[0x4114]; piVar29 != (int *)0x0;
                piVar29 = (int *)piVar29[4]) {
              local_b8 = puVar9[*piVar29 * 4];
              if ((uVar20 & 0xfef00) == (local_b8 & 0xfef00)) {
                uVar20 = ((int (*)())FUN_00077850)(&local_b8);
                uVar11 = uVar11 & ~uVar20;
                ((int (*)())FUN_000798f0)(puVar30,uVar11);
                uVar20 = *puVar30;
              }
            }
            if (((uVar20 & 0xf00) == 0x400) && (puVar21[0x800] = 1, local_94 == 0)) {
              if ((bool)((byte)((uint)local_60 >> 0x1d) & 1)) {
                local_94 = 1;
              }
              else {
                *local_70 = iVar26;
                local_94 = 1;
              }
            }
            iVar33 = ((int (*)())FUN_00079910)(param_1,param_1 + 0x4114,iVar26,uVar11,0,0,puVar8);
            if (iVar33 != 0) {
              return iVar33;
            }
LAB_0007ceb4:
            puVar27 = (uint *)param_1[0xd];
          }
          goto LAB_0007ceb8;
        }
        uVar20 = *puVar30;
        if (1 < (uVar20 >> 8 & 0xf) - 2) goto LAB_0007ceb8;
        for (piVar29 = (int *)param_1[0x4114]; piVar29 != (int *)0x0; piVar29 = (int *)piVar29[4]) {
          local_b8 = puVar9[*piVar29 * 4];
          if ((uVar20 & 0xfe000) == (local_b8 & 0xfe000)) {
            uVar20 = ((int (*)())FUN_00077850)(&local_b8);
            uVar11 = uVar11 & ~uVar20;
            ((int (*)())FUN_000798f0)(puVar30,uVar11);
            uVar20 = *puVar30;
          }
        }
        if ((uVar20 & 0xfe000) == 0) {
          puVar21[0x800] = 1;
        }
        if ((local_94 == 0) && ((*puVar30 & 0xfe000) == 0)) {
          if ((bool)((byte)((uint)local_60 >> 0x1d) & 1)) {
            local_94 = 1;
          }
          else {
            *local_70 = iVar26;
            local_94 = 1;
          }
        }
        iVar33 = ((int (*)())FUN_00079910)(param_1,param_1 + 0x4114,iVar26,uVar11,0,0,puVar8);
        if (iVar33 != 0) {
          return iVar33;
        }
        if ((*puVar30 & 0xf00) != 0x300) goto LAB_0007ceb4;
        puVar27 = (uint *)param_1[0xd];
        local_90 = 1;
      }
      uVar20 = *puVar27 >> 6 & 1;
      iVar33 = ((int (*)())FUN_000777b0)(puVar30,uVar20);
      if (((iVar33 != 0) || (iVar33 = ((int (*)())FUN_00077800)(puVar30,uVar20), iVar33 != 0)) &&
         (piVar29 = (int *)puVar21[0x1000], piVar29 != (int *)0x0)) {
        do {
          uVar20 = puVar8[(int)(((unsigned char *)0x00002106) + *piVar29)];
          if (uVar20 != 0) {
            puVar21[0x800] = 1;
          }
          piVar29 = (int *)piVar29[4];
        } while ((piVar29 != (int *)0x0) && (uVar20 == 0));
        puVar27 = (uint *)param_1[0xd];
      }
      uVar20 = *puVar27 >> 6 & 1;
      iVar33 = ((int (*)())FUN_000777b0)(puVar30,uVar20);
      if ((iVar33 != 0) || (iVar33 = ((int (*)())FUN_00077800)(puVar30,uVar20), iVar33 != 0)) {
        uVar17 = 0;
        for (uVar20 = puVar21[0x1000]; uVar20 != 0; uVar20 = *(uint *)(uVar20 + 0x10)) {
          uVar17 = uVar17 | *(uint *)(uVar20 + 4);
        }
        if (uVar11 != uVar17) {
          ((int (*)())FUN_000798f0)(puVar30,uVar11 & uVar17);
          puVar27 = (uint *)param_1[0xd];
        }
      }
      puVar12 = local_b4;
      cVar23 = (char)*puVar30;
      if (((cVar23 == 'A') && ((*puVar27 & 0x80) != 0)) && (uVar11 = puVar21[0x1000], uVar11 != 0))
      {
        uVar20 = 0;
        do {
          puVar1 = (uint *)(uVar11 + 4);
          uVar11 = *(uint *)(uVar11 + 0x10);
          uVar20 = uVar20 | *puVar1;
        } while (uVar11 != 0);
        if ((uVar20 & 7) == 2) {
          *(undefined1 *)((int)puVar30 + 3) = 6;
          uVar14 = ((int (*)())FUN_00079a20)(local_b4,3);
          ((int (*)())FUN_00079a90)(puVar12,1,uVar14);
          if (!bVar2) {
            iVar33 = 4;
            puVar12 = local_74 + iVar19;
            puVar27 = local_a8;
            do {
              uVar11 = *puVar27;
              puVar27 = puVar27 + 1;
              *puVar12 = uVar11;
              puVar12 = puVar12 + 1;
              iVar33 = iVar33 + -1;
            } while (iVar33 != 0);
          }
          puVar27 = (uint *)param_1[0xd];
          cVar23 = (char)*puVar30;
        }
      }
      if ((cVar23 == 'D') &&
         (iVar33 = ((int (*)())FUN_000777b0)(puVar30,*puVar27 >> 6 & 1), puVar12 = local_b4, iVar33 != 0)) {
        *puVar30 = *puVar30 & 0xff6fffff;
        puVar27 = (uint *)param_1[0xd];
        if ((*puVar27 >> 6 & 1) != 0) {
          uVar11 = *puVar27 >> 6 & 1;
          iVar33 = ((int (*)())FUN_000782e0)(local_b4,uVar11);
          puVar1 = local_b0;
          if (((iVar33 != 0) &&
              (iVar33 = ((int (*)())FUN_000782e0)(local_b0,uVar11), puVar6 = local_ac, iVar33 != 0)) &&
             (iVar33 = ((int (*)())FUN_000782e0)(local_ac,uVar11), iVar33 != 0)) {
            uVar11 = *puVar12;
            if (((uVar11 & 0x1fe0) == (*puVar1 & 0x1fe0)) &&
               ((uVar11 & 0x1fe0) == (*puVar6 & 0x1fe0))) {
              uVar20 = *puVar1 >> 9 & 0xe000;
              *puVar12 = uVar20 | uVar11 & 0xffff1fff;
              *puVar12 = *puVar6 >> 6 & 0x70000 | uVar20 | uVar11 & 0xfff81fff;
              uVar20 = *puVar1;
              uVar11 = (uVar11 & 0x1c00000) >> 9;
              *puVar1 = uVar11 | uVar20 & 0xffff1fff;
              *puVar1 = *puVar6 >> 6 & 0x70000 | uVar11 | uVar20 & 0xfff81fff;
              uVar20 = *puVar6;
              uVar11 = *puVar12 >> 9 & 0xe000;
              *puVar6 = uVar11 | uVar20 & 0xffff1fff;
              *puVar6 = *puVar1 >> 6 & 0x70000 | uVar11 | uVar20 & 0xfff81fff;
              puVar27 = (uint *)param_1[0xd];
            }
          }
        }
      }
      if ((!bVar2) && ((*puVar27 & 0x200) != 0)) {
        iVar33 = 4;
        puVar12 = local_74 + iVar19;
        puVar27 = local_a8;
        do {
          uVar11 = *puVar27;
          puVar27 = puVar27 + 1;
          *puVar12 = uVar11;
          puVar12 = puVar12 + 1;
          iVar33 = iVar33 + -1;
        } while (iVar33 != 0);
        puVar27 = (uint *)param_1[0xd];
      }
      uVar20 = 0;
      local_a0 = 0;
      uVar11 = ((int (*)())FUN_00078300)(puVar30,*puVar27 >> 6 & 1);
      local_a4 = &local_b0;
      *puVar21 = uVar11;
      local_9c = puVar8 + iVar26 * 3 + 0x106;
      local_7c = local_b4;
      local_80 = local_b0;
      local_84 = local_ac;
      iVar33 = iVar25;
      do {
        if ((uVar11 & 1 << (uVar20 & 0x3f)) == 0) {
          uVar17 = 5;
          if ((*(uint *)param_1[0xd] & 0x40) == 0) {
            uVar17 = 9;
          }
          **(uint **)(local_a0 + (int)local_5c) =
               uVar17 | **(uint **)(local_a0 + (int)local_5c) & 0xfffffff0;
          goto LAB_0007da08;
        }
        puVar27 = (uint *)param_1[0xd];
        uVar28 = **(uint **)(local_a0 + (int)local_5c);
        uVar17 = *puVar27 >> 6;
        uVar22 = uVar17 & 1;
        uVar13 = uVar28 & 0xf;
        if ((uVar13 == 0) || (((uVar13 == 3 || (uVar13 == 1)) && (uVar22 != 0)))) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
        if (!bVar3) {
          iVar15 = ((int (*)())FUN_00078ef0)(*(uint **)(local_a0 + (int)local_5c),uVar22);
          if (iVar15 != 0) {
            uVar17 = uVar28 >> 4 & 1;
            if (uVar22 != 0) {
              uVar17 = uVar28 >> 0x1e & 2 | uVar28 >> 4 & 1;
            }
            if ((uVar17 == 1) && (local_8c = uVar28 >> 0x1d & 3, -1 < iVar32)) {
              iVar15 = 0;
              local_88 = (int)param_1 + iVar33 + 0x450;
              puVar12 = puVar30;
              while( true ) {
                puVar12 = puVar12 + -4;
                local_b8 = *puVar12;
                iVar16 = ((int (*)())FUN_00077800)(&local_b8,*puVar27 >> 6 & 1);
                if ((iVar16 == 0) || (iVar16 = ((int (*)())FUN_00078f10)(&local_b8,local_8c), iVar16 == 0)) {
                  bVar3 = false;
                }
                else {
                  ((int (*)())FUN_00079910)(param_1,local_88,iVar32 - iVar15,1 << (local_8c & 0x3f),0,0,puVar8);
                  bVar3 = true;
                }
                if ((iVar15 == iVar32) || (iVar15 = iVar15 + 1, bVar3)) break;
                puVar27 = (uint *)param_1[0xd];
              }
            }
          }
          goto switchD_0007d27c_caseD_0;
        }
        switch((char)*puVar30) {
        case '\x01':
          iVar15 = 0;
          puVar27 = *local_a4;
          do {
            iVar16 = ((int (*)())FUN_00079a20)(puVar27,iVar15);
            if (iVar16 != 4) {
              ((int (*)())FUN_00079bd0)(param_1,puVar9,local_74,puVar8,iVar26,uVar20,iVar15);
            }
            bVar3 = iVar15 != 3;
            iVar15 = iVar15 + 1;
          } while (bVar3);
          break;
        case '\x02':
          iVar15 = 0;
          bVar3 = local_90 == 0;
          do {
            if (bVar3) {
              iVar16 = ((int (*)())FUN_00078f10)(puVar30,iVar15);
              if ((iVar16 != 0) && (iVar16 = ((int (*)())FUN_00079a20)(*local_a4,iVar15), iVar16 != 4)) {
                ((int (*)())FUN_00079bd0)(param_1,puVar9,local_74,puVar8,iVar26,uVar20,iVar15);
              }
            }
            else if (((iVar15 == 0) && (iVar16 = ((int (*)())FUN_00077850)(puVar30), iVar16 != 0)) &&
                    (iVar16 = ((int (*)())FUN_00079a20)(*local_a4,0), iVar16 != 4)) {
              ((int (*)())FUN_00079bd0)(param_1,puVar9,local_74,puVar8,iVar26,uVar20,0);
            }
            bVar4 = iVar15 != 3;
            iVar15 = iVar15 + 1;
          } while (bVar4);
          break;
        case '\x03':
        case '\x04':
        case '\x06':
        case '\a':
        case '\b':
        case '\t':
        case '\n':
        case '\v':
        case '\f':
        case '\r':
        case '\x0e':
        case -0x80:
        case -0x7f:
          iVar15 = 0;
          bVar3 = local_90 == 0;
          do {
            if (bVar3) {
              iVar16 = ((int (*)())FUN_00078f10)(puVar30,iVar15);
              if (iVar16 != 0) {
                ((int (*)())FUN_00079bd0)(param_1,puVar9,local_74,puVar8,iVar26,uVar20,iVar15);
              }
            }
            else if ((iVar15 == 0) && (iVar16 = ((int (*)())FUN_00077850)(puVar30), iVar16 != 0)) {
              ((int (*)())FUN_00079bd0)(param_1,puVar9,local_74,puVar8,iVar26,uVar20,0);
            }
            bVar4 = iVar15 != 3;
            iVar15 = iVar15 + 1;
          } while (bVar4);
          break;
        case '\x05':
          iVar15 = 1;
          do {
            if (uVar20 == 0) {
              if (iVar15 - 1U < 2) {
LAB_0007d6c4:
                iVar16 = ((int (*)())FUN_00078f10)(puVar30,iVar15);
                if (iVar16 != 0) {
                  ((int (*)())FUN_00079bd0)(param_1,puVar9,local_74,puVar8,iVar26,uVar20,iVar15);
                }
              }
            }
            else if ((uVar20 == 1) && ((iVar15 == 1 || (iVar15 == 3)))) goto LAB_0007d6c4;
            bVar3 = iVar15 != 3;
            iVar15 = iVar15 + 1;
          } while (bVar3);
          break;
        case 'A':
        case 'B':
        case 'F':
        case 'H':
        case 'K':
        case 'L':
        case 'P':
        case 'Q':
          goto switchD_0007d27c_caseD_41;
        case 'C':
        case 'G':
        case 'I':
          if ((uVar17 & 1) != 0) goto switchD_0007d27c_caseD_41;
          ((int (*)())FUN_00079bd0)(param_1,puVar9,local_74,puVar8,iVar26,uVar20,0);
          break;
        case 'D':
          iVar15 = 0;
          if ((uVar17 & 1) == 0) {
            do {
              ((int (*)())FUN_00079bd0)(param_1,puVar9,local_74,puVar8,iVar26,uVar20,iVar15);
              iVar16 = 4 - iVar15;
              if (4 < iVar15 + 1) {
                iVar16 = 1;
              }
              do {
                iVar15 = iVar15 + 1;
                iVar16 = iVar16 + -1;
                if (iVar16 == 0) goto switchD_0007d27c_caseD_0;
              } while (iVar15 == 2);
            } while( true );
          }
          if ((((*local_7c & 0xf) == 0) && ((*local_80 & 0xf) == 0)) &&
             (((*local_84 & 0xf) == 0 &&
              ((uVar17 = *local_7c & 0x1fe0, uVar17 == (*local_80 & 0x1fe0) &&
               (iVar15 = 0, uVar17 == (*local_84 & 0x1fe0))))))) {
            do {
              ((int (*)())FUN_00079bd0)(param_1,puVar9,local_74,puVar8,iVar26,uVar20,iVar15);
              iVar16 = 4 - iVar15;
              if (4 < iVar15 + 1) {
                iVar16 = 1;
              }
              do {
                iVar15 = iVar15 + 1;
                iVar16 = iVar16 + -1;
                if (iVar16 == 0) goto switchD_0007d27c_caseD_0;
              } while (iVar15 == 2);
            } while( true );
          }
          goto switchD_0007d27c_caseD_41;
        case 'E':
        case 'M':
        case 'N':
        case 'O':
          iVar15 = 0;
          if ((uVar17 & 1) == 0) {
            do {
              ((int (*)())FUN_00079bd0)(param_1,puVar9,local_74,puVar8,iVar26,uVar20,iVar15);
              iVar16 = 3 - iVar15;
              if (3 < iVar15 + 1) {
                iVar16 = 1;
              }
              do {
                iVar15 = iVar15 + 1;
                iVar16 = iVar16 + -1;
                if (iVar16 == 0) goto switchD_0007d27c_caseD_0;
              } while (((iVar15 == 1) && ((char)*puVar30 != '\r')) && ((char)*puVar30 != '\x0e'));
            } while( true );
          }
switchD_0007d27c_caseD_41:
          ((int (*)())FUN_00079bd0)(param_1,puVar9,local_74,puVar8,iVar26,uVar20,3);
          break;
        case 'J':
          if ((uVar17 & 1) != 0) goto switchD_0007d27c_caseD_41;
          iVar15 = 0;
          do {
            ((int (*)())FUN_00079bd0)(param_1,puVar9,local_74,puVar8,iVar26,uVar20,iVar15);
            bVar3 = iVar15 != 1;
            iVar15 = iVar15 + 1;
          } while (bVar3);
        }
switchD_0007d27c_caseD_0:
        for (piVar29 = (int *)*local_9c; piVar29 != (int *)0x0; piVar29 = (int *)piVar29[4]) {
          iVar15 = ((int (*)())FUN_00079910)(param_1,param_1 + *piVar29 + 0x2914,iVar26,piVar29[1],piVar29[2],0,
                                puVar8);
          if (iVar15 != 0) {
            return iVar15;
          }
        }
LAB_0007da08:
        bVar3 = uVar20 != 2;
        iVar33 = iVar33 + 4;
        uVar20 = uVar20 + 1;
        local_9c = local_9c + 1;
        local_a0 = local_a0 + 4;
        local_a4 = local_a4 + -1;
      } while (bVar3);
      iVar24 = iVar24 + 1;
      iVar26 = iVar26 + -1;
      iVar25 = iVar25 + -0xc;
      puVar30 = puVar30 + -4;
      puVar21 = puVar21 + -1;
      iVar19 = iVar19 + -4;
      puVar10 = puVar10 + -4;
    } while (iVar24 != local_98 + 1);
  }
  bVar2 = 0 < (int)local_78;
  if (bVar2) {
    puVar21 = param_1 + 0x2914;
    uVar11 = 0;
    puVar9 = param_1 + 0x3114;
    do {
      for (piVar29 = (int *)*puVar21; piVar29 != (int *)0x0; piVar29 = (int *)piVar29[4]) {
        uVar17 = 0;
        uVar20 = puVar8[*piVar29 + 0x1906];
        puVar10 = puVar8 + *piVar29 * 3 + 0x106;
        do {
          if (((uVar20 & 1 << (uVar17 & 0x3f)) != 0) &&
             (puVar30 = (uint *)*puVar10, puVar30 != (uint *)0x0)) {
            bVar3 = false;
            puVar27 = puVar30;
            do {
              if (uVar11 == *puVar27) {
                bVar3 = true;
              }
              puVar27 = (uint *)puVar27[4];
            } while (puVar27 != (uint *)0x0);
            if (bVar3) {
              do {
                if ((uVar11 != *puVar30) &&
                   (iVar19 = ((int (*)())FUN_00079910)(param_1,puVar9,*puVar30,puVar30[1],0,0,puVar8),
                   iVar19 != 0)) {
                  return iVar19;
                }
                puVar30 = (uint *)puVar30[4];
              } while (puVar30 != (uint *)0x0);
            }
          }
          bVar3 = uVar17 != 2;
          puVar10 = puVar10 + 1;
          uVar17 = uVar17 + 1;
        } while (bVar3);
      }
      uVar11 = uVar11 + 1;
      puVar9 = puVar9 + 1;
      puVar21 = puVar21 + 1;
    } while (uVar11 != local_78);
    puVar9 = param_1 + 0x3114;
    uVar11 = 0;
    do {
      _memset(local_64 + 0x314,0,0x800);
      for (puVar31 = (undefined4 *)*puVar9; puVar31 != (undefined4 *)0x0;
          puVar31 = (undefined4 *)puVar31[4]) {
        ((int (*)())FUN_00079b00)(param_1,uVar11,*puVar31,puVar31[1]);
      }
      uVar11 = uVar11 + 1;
      puVar9 = puVar9 + 1;
    } while (uVar11 != local_78);
  }
  if (((local_68 != (int *)0x0) && (local_6c != 0)) && (*local_68 = 0, bVar2)) {
    puVar9 = param_1 + 0x2114;
    uVar11 = 0;
    puVar31 = local_74;
    do {
      if (*puVar9 != 0) {
        iVar19 = 0;
        iVar32 = 4;
        puVar18 = puVar31;
        do {
          uVar14 = *puVar18;
          puVar18 = puVar18 + 1;
          iVar26 = *local_68 * 4 + iVar19;
          iVar19 = iVar19 + 1;
          *(undefined4 *)(local_6c + iVar26 * 4) = uVar14;
          iVar32 = iVar32 + -1;
        } while (iVar32 != 0);
        *local_68 = *local_68 + 1;
      }
      uVar11 = uVar11 + 1;
      puVar9 = puVar9 + 1;
      puVar31 = puVar31 + 4;
    } while (uVar11 != local_78);
  }
  if ((*param_1 & 0x100) == 0) {
    iVar19 = ((int (*)())FUN_0007b0d0)(param_1);
    return iVar19;
  }
  return 0;
}

/* FUN_0007dcd0 @ 0x7dcd0 (88 bytes) */
int FUN_0007dcd0(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(((unsigned char *)0x000011b4) + param_1);
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0xc))(8);
  *puVar1 = param_2;
  puVar1[1] = *(undefined4 *)(iVar2 + 8);
  *(undefined4 **)(iVar2 + 8) = puVar1;
  return;
}

/* FUN_0007dd30 @ 0x7dd30 (160 bytes) */
int FUN_0007dd30(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(((unsigned char *)0x000011b4) + param_1);
  if ((iVar4 == 0) || (piVar2 = *(int **)(iVar4 + 8), piVar2 == (int *)0x0)) {
LAB_0007ddc0:
    uVar1 = 0;
  }
  else {
    if (*piVar2 == param_2) {
      *(int *)(iVar4 + 8) = piVar2[1];
    }
    else {
      do {
        piVar3 = piVar2;
        piVar2 = (int *)piVar3[1];
        if (piVar2 == (int *)0x0) goto LAB_0007ddc0;
      } while (param_2 != *piVar2);
      piVar3[1] = piVar2[1];
    }
    (**(code **)(param_1 + 0x18))(piVar2);
    uVar1 = 1;
  }
  return uVar1;
}

/* FUN_00083110 @ 0x83110 (856 bytes) */
int FUN_00083110(param_1)
  int param_1;
{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  *(undefined4 *)(param_1 + 0x1ca0) = 1;
  *(undefined4 *)(param_1 + 0x1ca4) = 4;
  uVar2 = *(uint *)(param_1 + 0x1804);
  FUN_0004fc80(param_1,0,3,0,0,0,0,0);
  *(undefined4 *)(param_1 + 0x1b9c) = 1;
  *(undefined4 *)(param_1 + 0x1bb0) = 0;
  *(undefined4 *)(param_1 + 0x1ba0) = 0;
  if ((uVar2 & 2) == 0) {
    iVar6 = 1;
    iVar4 = 2;
  }
  else {
    iVar6 = 2;
    iVar4 = 3;
    *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 0x40000;
    *(uint *)(param_1 + 0x1ca4) =
         (*(uint *)(param_1 + 0x1ca4) & 0x7f) + 1 & 0x7f | *(uint *)(param_1 + 0x1ca4) & 0xffffff80;
    FUN_0004fc80(param_1,1,0,0,1,0,0,0);
    *(uint *)(param_1 + 0x1b9c) = *(uint *)(param_1 + 0x1b9c) | 0x10000;
  }
  *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 4;
  *(uint *)(param_1 + 0x1ca4) =
       (*(uint *)(param_1 + 0x1ca4) & 0x7f) + 4 & 0x7f | *(uint *)(param_1 + 0x1ca4) & 0xffffff80;
  FUN_0004fc80(param_1,iVar6,3,0,iVar6,0,0,0);
  *(uint *)(param_1 + 0x1b9c) = *(uint *)(param_1 + 0x1b9c) | 2;
  iVar5 = iVar4;
  if ((uVar2 & 1) != 0) {
    iVar5 = iVar6 + 2;
    *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 8;
    *(uint *)(param_1 + 0x1ca4) =
         (*(uint *)(param_1 + 0x1ca4) & 0x7f) + 4 & 0x7f | *(uint *)(param_1 + 0x1ca4) & 0xffffff80;
    FUN_0004fc80(param_1,iVar4,3,0,iVar4,0,0,0);
    *(uint *)(param_1 + 0x1b9c) = *(uint *)(param_1 + 0x1b9c) | 4;
  }
  if ((uVar2 & 8) != 0) {
    *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 0x30;
    *(uint *)(param_1 + 0x1ca4) =
         (*(uint *)(param_1 + 0x1ca4) & 0x7f) + 7 & 0x7f | *(uint *)(param_1 + 0x1ca4) & 0xffffff80;
    FUN_0004fc80(param_1,iVar5,3,0,iVar5,0,0,0);
    iVar4 = iVar5 + 1;
    iVar5 = iVar5 + 2;
    FUN_0004fc80(param_1,iVar4,2,0,iVar4,0,0,0);
    *(uint *)(param_1 + 0x1b9c) = *(uint *)(param_1 + 0x1b9c) | 0x18;
  }
  if (uVar2 >> 4 != 0) {
    uVar3 = 0;
    iVar4 = iVar5;
    iVar6 = param_1;
    do {
      uVar7 = *(uint *)(iVar6 + 0x1824);
      uVar3 = uVar3 + 1;
      iVar5 = iVar4 + 1;
      iVar6 = iVar6 + 4;
      *(uint *)(param_1 + 0x1ca0) = 0x400 << (uVar7 & 0x3f) | *(uint *)(param_1 + 0x1ca0);
      uVar7 = 4 << (uVar7 * 3 & 0x3f);
      *(uint *)(param_1 + 0x1ca4) =
           (*(uint *)(param_1 + 0x1ca4) & 0x7f) + 4 & 0x7f |
           *(uint *)(param_1 + 0x1ca4) & 0xffffff80;
      FUN_0004fc80(param_1,iVar4,3,0,iVar4,0,0,0);
      *(uint *)(param_1 + 0x1bb0) = uVar7 | *(uint *)(param_1 + 0x1bb0);
      *(uint *)(param_1 + 0x1ba0) = uVar7 | *(uint *)(param_1 + 0x1ba0);
      iVar4 = iVar5;
    } while (uVar2 >> 4 != uVar3);
  }
  if ((*(uint *)(param_1 + 0x44) & 0x400) != 0) {
    uVar2 = 4 << ((uint)(byte)((unsigned char *)0x000011d2)[param_1] * 3 & 0x3f);
    *(uint *)(param_1 + 0x1bb0) = uVar2 | *(uint *)(param_1 + 0x1bb0);
    *(uint *)(param_1 + 0x1ba0) = uVar2 | *(uint *)(param_1 + 0x1ba0);
  }
  uVar2 = iVar5 - 1;
  if ((uVar2 & 1) == 0) {
    iVar4 = (uVar2 * 2 & 0xfffffffc) + param_1;
    *(uint *)(iVar4 + 0x1be4) = *(uint *)(iVar4 + 0x1be4) | 0x2000;
  }
  else {
    iVar4 = (uVar2 * 2 & 0xfffffffc) + param_1;
    *(uint *)(iVar4 + 0x1be4) = *(uint *)(iVar4 + 0x1be4) | 0x20000000;
  }
  pcVar1 = *(code **)(((unsigned char *)0x00001334) + param_1);
  *(int *)(param_1 + 0x243c) = iVar5;
  *(int *)(param_1 + 0x2438) = iVar5;
  (*pcVar1)(param_1,1);
                    
                    
  (**(code **)(((unsigned char *)0x00001330) + param_1))(param_1,0xc0100000);
  return;
}

/* FUN_00083470 @ 0x83470 (828 bytes) */
int FUN_00083470(param_1)
  int param_1;
{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  void *pvVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  void *pvVar11;
  uint uVar12;
  int iVar13;
  uint local_68 [2];
  undefined4 local_60;
  uint local_5c;
  
  if (*(char *)(param_1 + 0x1868) == '\0') {
    _memset(local_68,0,0x30);
    uVar6 = *(uint *)(param_1 + 0x44);
    local_60 = *(undefined4 *)(param_1 + 0x1804);
    local_68[0] = local_68[0] | 8;
    if ((uVar6 & 0xc00) != 0) {
      local_5c = uVar6 >> 0xb & 1 | uVar6 >> 9 & 2 | (uint)(byte)((unsigned char *)0x000011d3)[param_1] << 2;
    }
    pvVar11 = *(void **)(param_1 + 0x14c);
    if ((pvVar11 == (void *)0x0) ||
       (iVar3 = _memcmp(pvVar11,local_68,0x30), pvVar4 = pvVar11, iVar3 != 0)) {
      pvVar4 = (void *)FUN_0009edd0(param_1,local_68);
      if (pvVar4 == (void *)0x0) {
        uVar10 = *(uint *)(param_1 + 0x1804);
        puVar5 = (undefined4 *)FUN_00092bf0(param_1,0,0);
        puVar5[0x1a] = 0;
        *puVar5 = 0;
        uVar6 = *(uint *)(param_1 + 0x44);
        if ((uVar6 & 0x400) == 0) {
          uVar1 = uVar10 >> 3 & 1;
          uVar12 = uVar10 >> 1 & 1;
          iVar3 = 0;
        }
        else {
          uVar1 = uVar10 >> 3 & 1;
          uVar12 = uVar10 >> 1 & 1;
          iVar3 = uVar1 * 2 + (uVar10 & 1) + uVar12 + (uint)(byte)((unsigned char *)0x000011d2)[param_1] + 2;
          puVar5[(byte)((unsigned char *)0x000011d2)[param_1] + 0x21] = iVar3;
          uVar6 = *(uint *)(param_1 + 0x44);
        }
        FUN_00092d40(puVar5,uVar6 >> 10 & 1,((unsigned char *)0x000011d2)[param_1]);
        if (uVar12 == 0) {
          iVar7 = 1;
          iVar13 = 1;
          iVar8 = 2;
          iVar9 = 2;
        }
        else {
          iVar13 = 2;
          iVar7 = 2;
          puVar5[0x1b] = 1;
          puVar5[0x13] = 1;
          iVar8 = 3;
          iVar9 = 3;
          FUN_00093130(puVar5);
        }
        puVar5[3] = iVar7;
        puVar5[0x1d] = iVar13;
        FUN_00092ea0(puVar5,3,0,0);
        if ((uVar10 & 1) != 0) {
          puVar5[4] = iVar8;
          puVar5[0x1f] = iVar9;
          FUN_00092ea0(puVar5,4,1,0);
          if ((uVar10 & 4) != 0) {
            puVar5[0x14] = iVar8;
            puVar5[0x1c] = iVar9;
            puVar5[0x15] = 3;
            FUN_000931e0(puVar5);
          }
          iVar8 = iVar7 + 2;
          iVar9 = iVar13 + 2;
        }
        if (uVar1 != 0) {
          puVar5[5] = iVar8;
          puVar5[0x1e] = iVar9;
          FUN_00092ea0(puVar5,3,2,1);
          puVar5[6] = iVar8 + 1;
          puVar5[0x20] = iVar9 + 1;
          iVar8 = iVar8 + 2;
          iVar9 = iVar9 + 2;
          FUN_00092ea0(puVar5,4,3,1);
        }
        if (uVar10 >> 4 != 0) {
          uVar6 = 0;
          iVar7 = param_1;
          do {
            iVar13 = *(int *)(iVar7 + 0x1824);
            puVar5[iVar13 + 0xb] = iVar8;
            iVar8 = iVar8 + 1;
            if (iVar3 == iVar9) {
              iVar9 = iVar9 + 1;
            }
            puVar5[iVar13 + 0x21] = iVar9;
            uVar6 = uVar6 + 1;
            iVar7 = iVar7 + 4;
            iVar9 = iVar9 + 1;
            FUN_00093000(puVar5);
          } while (uVar10 >> 4 != uVar6);
        }
        FUN_0009a910(puVar5);
        if (iVar3 == iVar9) {
          iVar9 = iVar9 + 1;
        }
        pvVar4 = (void *)FUN_0009c800(param_1,local_68,puVar5,iVar8,iVar9,0,0,1);
        *(undefined4 *)((int)pvVar4 + 0x34) = 0;
        *(int *)((int)pvVar4 + 0x38) = *(int *)(*(int *)((int)pvVar4 + 0x54) + 0x3cc) + -1;
        pvVar11 = *(void **)(param_1 + 0x14c);
      }
      else {
        pvVar11 = *(void **)(param_1 + 0x14c);
      }
    }
    if (pvVar4 != pvVar11) {
      pcVar2 = *(code **)(((unsigned char *)0x000012d0) + param_1);
      *(void **)(param_1 + 0x14c) = pvVar4;
      *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000;
      (*pcVar2)(param_1,pvVar4);
    }
  }
  else {
    FUN_000656b0();
  }
  return;
}

/* FUN_000837b0 @ 0x837b0 (188 bytes) */
int FUN_000837b0(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  ((int (*)())FUN_00083470)();
  ((int (*)())FUN_00083110)(param_1);
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,9);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar1;
  *puVar1 = 0x861;
  uVar2 = *(undefined4 *)(param_1 + 0x1ca0);
  puVar1[2] = 0x10824;
  puVar1[1] = uVar2;
  puVar1[3] = *(undefined4 *)(param_1 + 0x1b9c);
  uVar2 = *(undefined4 *)(param_1 + 0x1ba0);
  puVar1[5] = 0x82d;
  puVar1[4] = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x1ca4);
  puVar1[7] = ((unsigned char *)0x00001047);
  puVar1[6] = uVar2;
  puVar1[8] = *(undefined4 *)(param_1 + 0x1bb0);
  pcVar3 = *(code **)(param_1 + 0x275c);
  *(int *)(FUN_00002748 + param_1 + 4) = *(int *)(FUN_00002748 + param_1 + 4) + 0x24;
  (*pcVar3)(param_1);
  FUN_0004e880(param_1);
  return;
}

/* FUN_00083870 @ 0x83870 (1012 bytes) */
int FUN_00083870(param_1)
  int param_1;
{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  code *pcVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  undefined4 local_38;
  undefined4 local_34 [5];
  
  *(undefined1 *)(param_1 + 0x126) = 0;
  *(undefined4 *)(param_1 + 0x1b98) = 0;
  cVar1 = *(char *)(param_1 + 0x29);
  FUN_00090470();
  if (cVar1 == '\0') {
    iVar13 = *(int *)(param_1 + 0x13c);
    if (iVar13 == *(int *)(param_1 + 0x140)) {
      iVar3 = *(int *)(param_1 + 0x148);
      if (iVar3 == *(int *)(param_1 + 0x144)) {
        return;
      }
    }
    else {
      iVar3 = *(int *)(param_1 + 0x148);
    }
  }
  else {
    iVar13 = *(int *)(param_1 + 0x13c);
    iVar3 = *(int *)(param_1 + 0x148);
  }
  *(int *)(param_1 + 0x140) = iVar13;
  *(int *)(param_1 + 0x144) = iVar3;
  if (*(char *)(param_1 + 0x124) == '\0') {
    if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
      return;
    }
    iVar3 = FUN_0009edd0(param_1,param_1 + 0x1874);
    if (iVar3 == 0) {
      FUN_0009d080(param_1);
      uVar8 = FUN_0009bd00(param_1);
      iVar13 = FUN_0009d410(param_1,0,&local_38,local_34,uVar8);
      iVar3 = FUN_0009c800(param_1,param_1 + 0x1874,iVar13,*(undefined1 *)(param_1 + 0x131),local_38
                           ,local_34[0],uVar8,*(undefined1 *)(param_1 + 0x126));
      puVar9 = (undefined4 *)
               ((int (*)())FUN_000774c0)(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x18));
      puVar9[8] = 0;
      puVar9[9] = 0;
      *puVar9 = 0x460;
      puVar9[3] = 0x20;
      iVar10 = FUN_0009cb10(param_1,iVar3,puVar9,0x10);
      ((int (*)())FUN_0007a110)(puVar9);
      if (*(uint *)(iVar13 + 0x3cc) <= *(uint *)(iVar13 + 0x3e4)) {
        *(undefined1 *)(iVar3 + 0x59) = 0;
        *(undefined1 *)(param_1 + 0x126) = 0;
      }
      if (*(char *)(param_1 + 0x126) == '\0') {
        if (iVar10 == 0) {
          iVar13 = *(int *)(iVar3 + 0x54);
          iVar10 = *(int *)(iVar13 + 0x3cc);
          *(undefined4 *)(iVar3 + 0x38) = 0;
          if (iVar10 != 0) {
            iVar4 = iVar10 * 0x10 + *(int *)(iVar13 + 0x3c8);
            do {
              if ((((*(uint *)(iVar4 + -0xc) & 7) == 1) || ((*(uint *)(iVar4 + -8) & 7) == 1)) ||
                 ((*(uint *)(iVar4 + -4) & 7) == 1)) {
                *(int *)(iVar3 + 0x38) = iVar10 + -1;
              }
              iVar10 = iVar10 + -1;
            } while ((iVar10 != 0) && (iVar4 = iVar4 + -0x10, *(int *)(iVar3 + 0x38) == 0));
          }
        }
        else {
          iVar13 = *(int *)(iVar3 + 0x54);
        }
        puVar5 = *(uint **)(iVar13 + 0x3c8);
        if (*(int *)(iVar13 + 0x3cc) != 0) {
          uVar12 = 0;
          do {
            uVar2 = *puVar5;
            if ((uVar2 & 0x3f) == 4) {
              if ((((puVar5[1] & 7) == 0) && ((puVar5[2] & 7) == 0)) && ((puVar5[3] & 7) == 0)) {
                uVar6 = puVar5[1] >> 5 & 0xff;
                uVar11 = puVar5[2] >> 5 & 0xff;
                if (((uVar6 != uVar11) && (uVar14 = puVar5[3] >> 5 & 0xff, uVar6 != uVar14)) &&
                   (uVar11 != uVar14)) {
                  *puVar5 = uVar2 & 0xffffffc0 | 0x80;
                  iVar13 = *(int *)(iVar3 + 0x54);
                }
              }
            }
            else if ((((uVar2 & 0x3f) == 0xb) && ((puVar5[1] & 7) == 0)) &&
                    (((puVar5[2] & 7) == 0 && ((puVar5[3] & 7) == 0)))) {
              uVar6 = puVar5[1] >> 5 & 0xff;
              uVar11 = puVar5[2] >> 5 & 0xff;
              if (((uVar6 != uVar11) && (uVar14 = puVar5[3] >> 5 & 0xff, uVar6 != uVar14)) &&
                 (uVar11 != uVar14)) {
                *puVar5 = uVar2 & 0xffffffc0 | 0x81;
                iVar13 = *(int *)(iVar3 + 0x54);
              }
            }
            uVar12 = uVar12 + 1;
            puVar5 = puVar5 + 4;
          } while (uVar12 < *(uint *)(iVar13 + 0x3cc));
        }
LAB_00083c10:
        if (iVar3 != *(int *)(param_1 + 0x14c)) {
          *(int *)(param_1 + 0x14c) = iVar3;
          pcVar7 = *(code **)(((unsigned char *)0x000012d0) + param_1);
          *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000;
          (*pcVar7)(param_1,iVar3);
        }
        (**(code **)(((unsigned char *)0x000012c4) + param_1))(param_1,iVar3);
        return;
      }
      *(undefined1 *)(param_1 + 0x2435) = 1;
      *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000000;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1020;
      FUN_000a7d10(param_1);
      *(undefined1 *)(param_1 + 0x29) = 1;
      FUN_00090470(param_1);
    }
    else {
      if (*(char *)(iVar3 + 0x59) == '\0') goto LAB_00083c10;
      *(undefined1 *)(param_1 + 0x2435) = 1;
      *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000000;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1020;
      FUN_000a7d10(param_1);
      *(undefined1 *)(param_1 + 0x126) = 1;
      *(undefined1 *)(param_1 + 0x29) = 1;
      FUN_00090470(param_1);
    }
  }
  ((int (*)())FUN_000837b0)(param_1);
  return;
}

