#include "decls.h"

/* FUN_0012ea1a @ 0x12ea1a (70 bytes) */
int FUN_0012ea1a(param_1)
  int param_1;
{
  undefined1 local_24 [16];
  int *local_14;
  
  FUN_001a868e(local_24,*(undefined4 *)(param_1 + 4));
  while (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 4))(local_14);
    FUN_001a856e(local_24);
  }
  return;
}

/* FUN_0012ea60 @ 0x12ea60 (118 bytes) */
int FUN_0012ea60(param_1)
  int param_1;
{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  ((int (*)())FUN_0012ea1a)(param_1);
  puVar1 = *(uint **)(param_1 + 4);
  if (puVar1 != (uint *)0x0) {
    if (*puVar1 == 0) {
      uVar3 = puVar1[2];
    }
    else {
      uVar4 = 0;
      uVar3 = puVar1[2];
      do {
        iVar2 = *(int *)(uVar3 + uVar4 * 4);
        if (iVar2 != 0) {
          FUN_001a7aba(puVar1[5],iVar2);
          uVar3 = puVar1[2];
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *puVar1);
    }
    FUN_001a7aba(puVar1[5],uVar3);
    if (puVar1 != (uint *)0x0) {
      FUN_001a7aba(puVar1[-1],puVar1 + -1);
    }
  }
  return;
}

/* FUN_0012ead6 @ 0x12ead6 (83 bytes) */
int FUN_0012ead6(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  FUN_0012e90a(param_1,&param_2,&param_3);
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 8) = param_3;
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 4) = param_2;
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 0xc) = param_4;
  FUN_001a84b2(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x24));
  return;
}

/* FUN_0012eb2a @ 0x12eb2a (90 bytes) */
int FUN_0012eb2a(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  
  FUN_0012e90a(param_1,&param_2,&param_3);
  uVar1 = FUN_0012a2a6(param_3,param_2,param_4,*param_1);
  FUN_001a89d8(param_1[1],uVar1);
  return uVar1;
}

/* FUN_0012eb84 @ 0x12eb84 (89 bytes) */
int FUN_0012eb84(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  
  iVar1 = ((int (*)())FUN_0012ead6)(param_1,param_2,param_3,param_4);
  if (iVar1 != 0) {
    return;
  }
  ((int (*)())FUN_0012eb2a)();
  return;
}

/* FUN_0012ebde @ 0x12ebde (55 bytes) */
int FUN_0012ebde(param_1, param_2)
  int param_1;
  int param_2;
{
  if (((*(byte *)(param_1 + 0x15c) & 1) == (*(byte *)(param_2 + 0x15c) & 1)) &&
     (*(int *)(param_1 + 0x20) == *(int *)(param_2 + 0x20))) {
    return 0;
  }
  return 0xffffffff;
}

/* FUN_0012ec16 @ 0x12ec16 (89 bytes) */
int FUN_0012ec16(param_1, param_2)
  int param_1;
  int param_2;
{
  if (((((*(byte *)(param_1 + 0x15c) & 1) == (*(byte *)(param_2 + 0x15c) & 1)) &&
       (*(int *)(param_1 + 0x20) == *(int *)(param_2 + 0x20))) &&
      (((char)*(byte *)(param_1 + 0x15c) >> 1 & 1U) == ((char)*(byte *)(param_2 + 0x15c) >> 1 & 1U))
      ) && (*(int *)(param_1 + 0x38) == *(int *)(param_2 + 0x38))) {
    return 0;
  }
  return 0xffffffff;
}

/* FUN_0012ec70 @ 0x12ec70 (120 bytes) */
int FUN_0012ec70(param_1, param_2)
  int param_1;
  int param_2;
{
  byte bVar1;
  byte bVar2;
  
  bVar1 = *(byte *)(param_1 + 0x15c);
  bVar2 = *(byte *)(param_2 + 0x15c);
  if (((((bVar1 & 1) == (bVar2 & 1)) && (*(int *)(param_1 + 0x20) == *(int *)(param_2 + 0x20))) &&
      (((char)bVar1 >> 1 & 1U) == ((char)bVar2 >> 1 & 1U))) &&
     (((*(int *)(param_1 + 0x38) == *(int *)(param_2 + 0x38) &&
       (((char)bVar1 >> 2 & 1U) == ((char)bVar2 >> 2 & 1U))) &&
      (*(int *)(param_1 + 0x50) == *(int *)(param_2 + 0x50))))) {
    return 0;
  }
  return 0xffffffff;
}

/* FUN_0012ece8 @ 0x12ece8 (151 bytes) */
int FUN_0012ece8(param_1, param_2)
  int param_1;
  int param_2;
{
  byte bVar1;
  byte bVar2;
  
  bVar1 = *(byte *)(param_1 + 0x15c);
  bVar2 = *(byte *)(param_2 + 0x15c);
  if ((((((bVar1 & 1) == (bVar2 & 1)) && (*(int *)(param_1 + 0x20) == *(int *)(param_2 + 0x20))) &&
       (((char)bVar1 >> 1 & 1U) == ((char)bVar2 >> 1 & 1U))) &&
      ((*(int *)(param_1 + 0x38) == *(int *)(param_2 + 0x38) &&
       (((char)bVar1 >> 2 & 1U) == ((char)bVar2 >> 2 & 1U))))) &&
     ((*(int *)(param_1 + 0x50) == *(int *)(param_2 + 0x50) &&
      ((((char)bVar1 >> 3 & 1U) == ((char)bVar2 >> 3 & 1U) &&
       (*(int *)(param_1 + 0x68) == *(int *)(param_2 + 0x68))))))) {
    return 0;
  }
  return 0xffffffff;
}

/* FUN_0012ed80 @ 0x12ed80 (44 bytes) */
int FUN_0012ed80(param_1, param_2)
  int param_1;
  int param_2;
{
  if (((*(int *)(param_1 + 8) == *(int *)(param_2 + 8)) &&
      (*(int *)(param_1 + 4) == *(int *)(param_2 + 4))) &&
     (*(int *)(param_1 + 0xc) == *(int *)(param_2 + 0xc))) {
    return 0;
  }
  return 0xffffffff;
}

/* FUN_0012edac @ 0x12edac (92 bytes) */
int FUN_0012edac(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  undefined1 local_24 [16];
  int *local_14;
  
  FUN_001a868e(local_24,*(undefined4 *)(param_1 + 4));
  if (local_14 != (int *)0x0) {
    iVar2 = 0;
    do {
      cVar1 = (**(code **)(*local_14 + 0x18))(local_14);
      iVar2 = (iVar2 + 1) - (uint)(cVar1 == '\0');
      FUN_001a856e(local_24);
    } while (local_14 != (int *)0x0);
    return iVar2;
  }
  return 0;
}

/* FUN_0012ee08 @ 0x12ee08 (118 bytes) */
int FUN_0012ee08(param_1)
  int param_1;
{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  ((int (*)())FUN_0012ea1a)(param_1);
  puVar1 = *(uint **)(param_1 + 4);
  if (puVar1 != (uint *)0x0) {
    if (*puVar1 == 0) {
      uVar3 = puVar1[2];
    }
    else {
      uVar4 = 0;
      uVar3 = puVar1[2];
      do {
        iVar2 = *(int *)(uVar3 + uVar4 * 4);
        if (iVar2 != 0) {
          FUN_001a7aba(puVar1[5],iVar2);
          uVar3 = puVar1[2];
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *puVar1);
    }
    FUN_001a7aba(puVar1[5],uVar3);
    if (puVar1 != (uint *)0x0) {
      FUN_001a7aba(puVar1[-1],puVar1 + -1);
    }
  }
  return;
}

/* FUN_0012ee7e @ 0x12ee7e (1164 bytes) */
int FUN_0012ee7e(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  uint uVar6;
  
  *(undefined1 *)(param_1 + 0xb) = param_2;
  param_1[0xc] = -1;
  param_1[0xd] = *(int *)(*(int *)(*param_1 + 0x54) + 0x30);
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  uVar5 = *(undefined4 *)(*param_1 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar5,0x1c);
  *puVar2 = uVar5;
  puVar1 = puVar2 + 1;
  puVar2[4] = FUN_0012ed80;
  puVar2[5] = FUN_0012e8e0;
  puVar2[6] = uVar5;
  puVar2[1] = 1;
  iVar3 = 0;
  uVar6 = 1;
  do {
    uVar6 = uVar6 * 2;
    if (0xf < uVar6) break;
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x20);
  *puVar1 = uVar6;
  puVar2[2] = 0;
  pvVar4 = (void *)FUN_001a7bca(uVar5,*puVar1 << 2);
  puVar2[3] = pvVar4;
  _memset(pvVar4,0,*puVar1 << 2);
  param_1[1] = (int)puVar1;
  uVar5 = *(undefined4 *)(*param_1 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar5,0x1c);
  *puVar2 = uVar5;
  puVar1 = puVar2 + 1;
  puVar2[4] = FUN_0012ebde;
  puVar2[5] = FUN_0012e8a0;
  puVar2[6] = uVar5;
  puVar2[1] = 1;
  uVar6 = 1;
  iVar3 = 0x20;
  do {
    uVar6 = uVar6 * 2;
    if (0xf < uVar6) break;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *puVar1 = uVar6;
  puVar2[2] = 0;
  pvVar4 = (void *)FUN_001a7bca(uVar5,*puVar1 << 2);
  puVar2[3] = pvVar4;
  _memset(pvVar4,0,*puVar1 << 2);
  param_1[2] = (int)puVar1;
  uVar5 = *(undefined4 *)(*param_1 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar5,0x1c);
  *puVar2 = uVar5;
  puVar1 = puVar2 + 1;
  puVar2[4] = FUN_0012ec16;
  puVar2[5] = FUN_0012e8ac;
  puVar2[6] = uVar5;
  puVar2[1] = 1;
  uVar6 = 1;
  iVar3 = 0x20;
  do {
    uVar6 = uVar6 * 2;
    if (0xf < uVar6) break;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *puVar1 = uVar6;
  puVar2[2] = 0;
  pvVar4 = (void *)FUN_001a7bca(uVar5,*puVar1 << 2);
  puVar2[3] = pvVar4;
  _memset(pvVar4,0,*puVar1 << 2);
  param_1[3] = (int)puVar1;
  uVar5 = *(undefined4 *)(*param_1 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar5,0x1c);
  *puVar2 = uVar5;
  puVar1 = puVar2 + 1;
  puVar2[4] = FUN_0012ec70;
  puVar2[5] = FUN_0012e8ba;
  puVar2[6] = uVar5;
  puVar2[1] = 1;
  uVar6 = 1;
  iVar3 = 0x20;
  do {
    uVar6 = uVar6 * 2;
    if (0xf < uVar6) break;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *puVar1 = uVar6;
  puVar2[2] = 0;
  pvVar4 = (void *)FUN_001a7bca(uVar5,*puVar1 << 2);
  puVar2[3] = pvVar4;
  _memset(pvVar4,0,*puVar1 << 2);
  param_1[4] = (int)puVar1;
  uVar5 = *(undefined4 *)(*param_1 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar5,0x1c);
  *puVar2 = uVar5;
  puVar1 = puVar2 + 1;
  puVar2[4] = FUN_0012ece8;
  puVar2[5] = FUN_0012e8cc;
  puVar2[6] = uVar5;
  puVar2[1] = 1;
  uVar6 = 1;
  iVar3 = 0x20;
  do {
    uVar6 = uVar6 * 2;
    if (0xf < uVar6) break;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *puVar1 = uVar6;
  puVar2[2] = 0;
  pvVar4 = (void *)FUN_001a7bca(uVar5,*puVar1 << 2);
  puVar2[3] = pvVar4;
  _memset(pvVar4,0,*puVar1 << 2);
  param_1[5] = (int)puVar1;
  uVar5 = *(undefined4 *)(*param_1 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar5,0x14);
  *puVar2 = uVar5;
  puVar2[4] = uVar5;
  puVar2[2] = 0;
  puVar2[1] = 2;
  uVar5 = FUN_001a7bca(uVar5,8);
  puVar2[3] = uVar5;
  param_1[6] = (int)(puVar2 + 1);
  uVar5 = *(undefined4 *)(*param_1 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar5,0x14);
  *puVar2 = uVar5;
  puVar2[4] = uVar5;
  puVar2[2] = 0;
  puVar2[1] = 2;
  uVar5 = FUN_001a7bca(uVar5,8);
  puVar2[3] = uVar5;
  param_1[8] = (int)(puVar2 + 1);
  param_1[7] = 0;
  uVar5 = *(undefined4 *)(*param_1 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar5,0x34);
  *puVar2 = uVar5;
  FUN_0012ac02(puVar2 + 1,0,0,0,*param_1);
  param_1[9] = (int)(puVar2 + 1);
  uVar5 = *(undefined4 *)(*param_1 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar5,0x168);
  *puVar2 = uVar5;
  FUN_0010ee6a(puVar2 + 1,*param_1);
  param_1[10] = (int)(puVar2 + 1);
  *(undefined4 *)(*param_1 + 0x8c) = 0;
  *(undefined4 *)(*param_1 + 0x78) = 1;
  *(undefined4 *)(*param_1 + 0x7c) = 0;
  param_1[0x11] = -1;
  param_1[0x12] = -1;
  param_1[0x13] = -1;
  param_1[0x14] = -1;
  param_1[0x15] = -1;
  param_1[0x16] = -1;
  param_1[0x17] = -1;
  param_1[0x18] = -1;
  param_1[0x19] = -1;
  return;
}

/* FUN_0012f36c @ 0x12f36c (143 bytes) */
int FUN_0012f36c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
{
  int iVar1;
  
  iVar1 = param_1 + 0x60 + *(int *)(param_1 + 0x172c) * 0x34;
  *(int *)(param_1 + 0x172c) = *(int *)(param_1 + 0x172c) + 1;
  *(undefined4 *)(iVar1 + 0x1c) = 1;
  *(undefined4 *)(iVar1 + 8) = param_3;
  *(undefined4 *)(iVar1 + 0xc) = param_4;
  *(undefined1 *)(iVar1 + 0x34) = param_2;
  *(undefined1 *)(iVar1 + 0x35) = param_2;
  *(undefined1 *)(iVar1 + 0x36) = param_2;
  *(undefined1 *)(iVar1 + 0x37) = param_2;
  *(char *)(iVar1 + 0x38) = (char)param_5;
  *(char *)(iVar1 + 0x39) = (char)((uint)param_5 >> 8);
  *(char *)(iVar1 + 0x3a) = (char)((uint)param_5 >> 0x10);
  *(char *)(iVar1 + 0x3b) = (char)((uint)param_5 >> 0x18);
  *(undefined4 *)(iVar1 + 0x18) = param_9;
  *(uint *)(iVar1 + 0x24) = (uint)(param_6 == 0);
  *(undefined4 *)(iVar1 + 0x10) = param_10;
  return;
}

/* FUN_0012f3fc @ 0x12f3fc (28 bytes) */
int FUN_0012f3fc(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = 0x40;
  if (*(int *)(param_1 + 0x1740) != 2) {
    uVar1 = 0x20;
  }
  return uVar1;
}

/* FUN_0012f418 @ 0x12f418 (35 bytes) */
int FUN_0012f418(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x138))(param_1,0);
  *param_2 = uVar1;
  return;
}

/* FUN_0012f43c @ 0x12f43c (154 bytes) */
int FUN_0012f43c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_000e27f6(param_2,100);
  *puVar1 = PTR_DAT_002139f5 + 8;
  puVar1[2] = param_2;
  puVar1[1] = 0;
  *puVar1 = PTR_DAT_00213a05 + 8;
  FUN_0019ca40(puVar1 + 10);
  FUN_0019cafe(puVar1);
  puVar1[0x18] = 0;
  *(undefined4 **)(param_1 + 0x60) = puVar1;
  puVar1 = (undefined4 *)FUN_000e27f6(param_2,0xc);
  *puVar1 = PTR_DAT_00213a01 + 8;
  puVar1[1] = 1;
  puVar1[2] = 0;
  *(undefined4 **)(param_1 + 100) = puVar1;
  return;
}

/* FUN_0012f4ea @ 0x12f4ea (18 bytes) */
int FUN_0012f4ea(param_1)
  int param_1;
{
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x2c) = 0x100;
  return;
}

/* FUN_0012f4fc @ 0x12f4fc (22 bytes) */
int FUN_0012f4fc(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(undefined4 *)(PTR_PTR_002139ed + param_2 * 4);
}

/* FUN_0012f512 @ 0x12f512 (21 bytes) */
int FUN_0012f512(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  return *(int *)(param_3 + 0x138) == 1;
}

/* FUN_0012f528 @ 0x12f528 (16 bytes) */
int FUN_0012f528()
{
  return &DAT_001ef860;
}

/* FUN_0012f538 @ 0x12f538 (470 bytes) */
int FUN_0012f538(param_1, param_2, param_3)
  int param_1;
  int param_2;
  void *param_3;
{
  byte bVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  _memcpy((void *)(param_2 + 0x64c),param_3,0x963c);
  *(undefined4 *)(param_2 + 0x104) = *(undefined4 *)(param_1 + 0x172c);
  local_14 = 0;
  local_24 = param_1 + 0x60;
  local_28 = param_2 + 0x100;
  local_2c = 0;
  iVar6 = param_1;
  do {
    *(char *)(local_2c + 0x108 + param_2) = (char)*(undefined4 *)(iVar6 + 0x68);
    *(char *)(local_2c + 0x109 + param_2) = (char)*(undefined4 *)(iVar6 + 0x6c);
    *(char *)(local_2c + 0x10a + param_2) = (char)*(undefined4 *)(iVar6 + 0x70);
    bVar3 = *(byte *)(iVar6 + 0x78) & 0xf;
    bVar1 = *(byte *)(local_2c + 0x10b + param_2);
    *(byte *)(local_2c + 0x10b + param_2) = bVar1 & 0xf0 | bVar3;
    *(byte *)(local_2c + 0x10b + param_2) =
         bVar1 & 0x70 | bVar3 | (char)*(undefined4 *)(iVar6 + 0x7c) << 7;
    iVar2 = local_24 + 8;
    iVar4 = local_28 + 8;
    iVar5 = 0;
    do {
      *(undefined1 *)(iVar4 + 4) = *(undefined1 *)(iVar2 + 0x2c);
      *(undefined1 *)(iVar4 + 8) = *(undefined1 *)(iVar2 + 0x30);
      iVar5 = iVar5 + 1;
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar5 != 4);
    local_14 = local_14 + 1;
    local_2c = local_2c + 0xc;
    local_28 = local_28 + 0xc;
    local_24 = local_24 + 0x34;
    iVar6 = iVar6 + 0x34;
  } while (local_14 != 0x40);
  *(undefined4 *)(param_2 + 0x408) = *(undefined4 *)(param_1 + 0x1728);
  local_10 = 0;
  local_18 = param_1 + 0xd60;
  local_1c = param_2 + 0x400;
  local_20 = 0;
  do {
    *(char *)(local_20 + 0x40c + param_2) = (char)*(undefined4 *)(param_1 + 0xd68);
    *(char *)(local_20 + 0x40d + param_2) = (char)*(undefined4 *)(param_1 + 0xd6c);
    *(char *)(local_20 + 0x40e + param_2) = (char)*(undefined4 *)(param_1 + 0xd70);
    bVar3 = *(byte *)(param_1 + 0xd78) & 0xf;
    bVar1 = *(byte *)(local_20 + 0x40f + param_2);
    *(byte *)(local_20 + 0x40f + param_2) = bVar1 & 0xf0 | bVar3;
    *(byte *)(local_20 + 0x40f + param_2) =
         bVar1 & 0x70 | bVar3 | (char)*(undefined4 *)(param_1 + 0xd7c) << 7;
    iVar6 = local_18 + 8;
    iVar2 = local_1c + 0xc;
    iVar4 = 4;
    do {
      *(undefined1 *)(iVar2 + 4) = *(undefined1 *)(iVar6 + 0x2c);
      *(undefined1 *)(iVar2 + 8) = *(undefined1 *)(iVar6 + 0x30);
      iVar6 = iVar6 + 1;
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    local_10 = local_10 + 1;
    local_20 = local_20 + 0xc;
    local_1c = local_1c + 0xc;
    local_18 = local_18 + 0x34;
    param_1 = param_1 + 0x34;
  } while (local_10 != 0x30);
  return 0;
}

/* FUN_0012f70e @ 0x12f70e (39 bytes) */
int FUN_0012f70e()
{
  int in_stack_0000001c;
  
  if (*(int *)(in_stack_0000001c + 0x3f4) != 0) {
    FUN_000e27ca(in_stack_0000001c,0xf);
  }
  return 0;
}

/* FUN_0012f736 @ 0x12f736 (5 bytes) */
int FUN_0012f736()
{
  return;
}

/* FUN_0012f73c @ 0x12f73c (5 bytes) */
int FUN_0012f73c()
{
  return;
}

/* FUN_0012f742 @ 0x12f742 (282 bytes) */
int FUN_0012f742(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  float *param_2;
  undefined4 *param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  bool bVar2;
  float *pfVar3;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  float fVar7;
  float fVar8;
  
  *param_3 = 0xffffffff;
  fVar8 = 0.0;
  fVar7 = 0.0;
  bVar2 = true;
  pcVar6 = (char *)&param_4;
  pfVar3 = param_2;
  do {
    if (*pcVar6 != '\x04') {
      if (bVar2) {
        fVar8 = *pfVar3;
        bVar2 = false;
      }
      else {
        if (fVar8 != *pfVar3) {
          return 0;
        }
        if (NAN(fVar8) || NAN(*pfVar3)) {
          return 0;
        }
      }
    }
    pcVar6 = pcVar6 + 1;
    pfVar3 = pfVar3 + 1;
  } while (pcVar6 != &STACKARG(0x14));
  iVar4 = 4;
  do {
    fVar7 = fVar7 + fVar8;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  puVar5 = &DAT_001cc430;
  do {
    uVar1 = *puVar5;
    if ((fVar7 == (float)puVar5[1]) && (!NAN(fVar7) && !NAN((float)puVar5[1]))) {
      if ((char)param_4 != '\x04') {
        if ((fVar8 != (float)puVar5[-4]) || (NAN(fVar8) || NAN((float)puVar5[-4])))
        goto LAB_0012f7ec;
      }
      if ((*(unsigned char *)((unsigned char *)&(param_4) + 1)) != '\x04') {
        if ((fVar8 != (float)puVar5[-3]) || (NAN(fVar8) || NAN((float)puVar5[-3])))
        goto LAB_0012f7ec;
      }
      if ((*(unsigned char *)((unsigned char *)&(param_4) + 2)) != '\x04') {
        if ((fVar8 != (float)puVar5[-2]) || (NAN(fVar8) || NAN((float)puVar5[-2])))
        goto LAB_0012f7ec;
      }
      if ((*(unsigned char *)((unsigned char *)&(param_4) + 3)) == '\x04') {
LAB_0012f834:
        iVar4 = 1;
        do {
          param_2[iVar4 + -1] = fVar8;
          iVar4 = iVar4 + 1;
        } while (iVar4 != 5);
        *param_3 = uVar1;
        return 1;
      }
      if (((float)puVar5[-1] == fVar8) && (!NAN((float)puVar5[-1]) && !NAN(fVar8)))
      goto LAB_0012f834;
    }
LAB_0012f7ec:
    puVar5 = puVar5 + 6;
    if (puVar5 == (undefined4 *)&DAT_001cc478) {
      return 0;
    }
  } while( true );
}

/* FUN_0012f85c @ 0x12f85c (55 bytes) */
int FUN_0012f85c(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = &DAT_001cc4a0;
  do {
    FUN_001840fe(param_2,*puVar1);
    puVar1 = puVar1 + 1;
  } while (puVar1 != &DAT_001cc4c8);
  return;
}

/* FUN_0012f894 @ 0x12f894 (95 bytes) */
int FUN_0012f894(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_001cc48c;
  do {
    iVar1 = FUN_001840fe(param_2,*puVar2);
    *(undefined1 *)(iVar1 + 8) = 1;
    *(undefined4 *)(iVar1 + 0x14) = *puVar2;
    *(undefined1 *)(iVar1 + 9) = 0;
    *(undefined1 *)(iVar1 + 0x18) = 0;
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    FUN_00186ab4(iVar1,param_2);
    puVar2 = puVar2 + 1;
  } while (puVar2 != (undefined4 *)&DAT_001cc498);
  return;
}

/* FUN_0012f8f4 @ 0x12f8f4 (40 bytes) */
int FUN_0012f8f4(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  param_2 = param_3;
  param_1 = *(undefined4 *)(*(int *)(param_5 + 0x3f4) + 0x3a0);
  FUN_000f6e40();
  return;
}

/* FUN_0012f91c @ 0x12f91c (944 bytes) */
int FUN_0012f91c(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  float *param_3;
  int *param_4;
{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int *piVar4;
  float *pfVar5;
  int iVar6;
  float fVar7;
  float *local_f4;
  float local_e0 [5];
  float local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
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
  float local_24;
  undefined4 local_20;
  
  if (*param_4 == DAT_001cc4cc) {
    return 0;
  }
  local_f4 = param_3;
  bVar1 = true;
  bVar2 = true;
  fVar7 = 0.0;
  iVar6 = 0;
  piVar4 = param_4;
  do {
    if ((char)*piVar4 != '\x04') {
      if (bVar1) {
        fVar7 = *local_f4;
        bVar1 = false;
      }
      else if (fVar7 == *local_f4) {
        bVar1 = false;
      }
      else {
        bVar2 = false;
      }
    }
    iVar6 = iVar6 + 1;
    piVar4 = (int *)((int)piVar4 + 1);
    local_f4 = local_f4 + 1;
  } while (iVar6 != 4);
  if (bVar2) {
    pfVar5 = local_e0 + 1;
    do {
      *pfVar5 = NAN;
      pfVar5 = pfVar5 + 1;
    } while (&local_cc != pfVar5);
    iVar6 = 1;
    do {
      local_e0[iVar6] = fVar7;
      iVar6 = iVar6 + 1;
    } while (iVar6 != 5);
    iVar6 = FUN_000f8aa6(param_2,local_e0 + 1,DAT_001cc4c8);
  }
  else {
    iVar6 = FUN_000f8aa6(param_2,param_3,*param_4);
  }
  if (iVar6 == 0) {
    local_e0[0] = *(float *)(param_2 + 0x3a0);
    iVar6 = FUN_000f80ae(local_e0[0],param_3,param_4);
    if (iVar6 == 0) {
      if ((((*(byte *)(param_2 + 0x31) & 1) != 0) && (*param_3 == 0.0)) && (!NAN(*param_3))) {
        if (((((FLOAT_001c5ba4 == param_3[1]) && (!NAN(FLOAT_001c5ba4) && !NAN(param_3[1]))) &&
             ((param_3[2] == 0.0 && ((!NAN(param_3[2]) && (param_3[3] == 0.0)))))) &&
            (!NAN(param_3[3]))) && (*param_4 == DAT_001cc4c8)) {
          FUN_000f6de0(param_3,local_e0 + 1);
          local_7c = local_94;
          local_78 = local_90;
          local_74 = local_8c;
          local_70 = local_88;
          local_6c = local_84;
          local_68 = local_80;
          local_64 = local_ac;
          local_60 = local_a8;
          local_5c = local_a4;
          local_58 = local_a0;
          local_54 = local_9c;
          local_50 = local_98;
          local_4c = local_c4;
          local_48 = local_c0;
          local_44 = local_bc;
          local_40 = local_b8;
          local_3c = local_b4;
          local_38 = local_b0;
          local_34 = local_e0[1];
          local_30 = local_e0[2];
          local_2c = local_e0[3];
          local_28 = local_e0[4];
          local_24 = local_cc;
          local_20 = local_c8;
          iVar6 = FUN_000f7508(local_e0[0],local_e0[1],local_e0[2],local_e0[3],local_e0[4],local_cc,
                               local_c8,local_c4,local_c0,local_bc,local_b8,local_b4,local_b0,
                               local_ac,local_a8,local_a4,local_a0,local_9c,local_98,local_94,
                               local_90,local_8c,local_88,local_84,local_80);
          return iVar6;
        }
      }
      iVar6 = FUN_000f7a2e(local_e0[0],param_3,param_4);
      if (iVar6 == 0) {
        return 0;
      }
      cVar3 = (**(code **)(*param_1 + 0x100))(param_1,param_4);
      if (cVar3 == '\0') {
        return 0;
      }
    }
  }
  return iVar6;
}

/* FUN_0012fccc @ 0x12fccc (505 bytes) */
int FUN_0012fccc(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int *param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  char cVar1;
  uint *puVar2;
  uint local_3c [4];
  uint local_2c [4];
  uint local_1c [3];
  
  puVar2 = local_2c;
  do {
    *puVar2 = 0x7ffffffe;
    puVar2 = puVar2 + 1;
  } while (local_1c != puVar2);
  puVar2 = local_3c;
  do {
    *puVar2 = 0x7ffffffe;
    puVar2 = puVar2 + 1;
  } while (local_2c != puVar2);
  puVar2 = &DAT_001cc42c;
  while( true ) {
    local_2c[3] = *puVar2;
    local_2c[2] = puVar2[-1];
    local_2c[1] = puVar2[-2];
    local_2c[0] = puVar2[-3];
    local_3c[0] = local_2c[0] ^ _DAT_001cc4e0;
    local_3c[1] = local_2c[1] ^ _DAT_001cc4e0;
    local_3c[2] = local_2c[2] ^ _DAT_001cc4e0;
    local_3c[3] = local_2c[3] ^ _DAT_001cc4e0;
    cVar1 = FUN_000f7dda(param_2,param_3,param_4,local_2c);
    if (cVar1 != '\0') {
      FUN_000fa0d2(param_2,*(undefined4 *)(param_5 + 0x3f4),param_3,local_2c[0],local_2c[1],
                   local_2c[2],local_2c[3]);
      return 1;
    }
    cVar1 = (**(code **)(*param_2 + 0x8c))(param_2);
    if ((cVar1 != '\0') && (cVar1 = FUN_000f7dda(param_2,param_3,param_4,local_3c), cVar1 != '\0'))
    break;
    puVar2 = puVar2 + 6;
    if (puVar2 == &DAT_001cc474) {
      return 0;
    }
  }
  FUN_000fa0d2(param_2,*(undefined4 *)(param_5 + 0x3f4),param_3,local_2c[0],local_2c[1],local_2c[2],
               local_2c[3]);
  if ((param_2[param_3 * 6 + 0x28] & 2U) != 0) {
    return 1;
  }
  FUN_00109c0e(param_2 + param_3 * 6 + 0x23,1,param_2[param_3 * 6 + 0x28] & 1U ^ 1);
  return 1;
}

/* FUN_0012fec6 @ 0x12fec6 (458 bytes) */
int FUN_0012fec6(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  undefined4 param_7;
  int param_8;
  undefined4 param_9;
  int param_10;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int local_20;
  
  uVar1 = *(undefined4 *)(param_10 + 0x3f4);
  local_20 = *(int *)(PTR_DAT_0021347d + param_2 * 4);
  iVar2 = FUN_0010a17a(0x8b,param_10);
  uVar3 = FUN_000edadc(uVar1,param_4);
  iVar4 = FUN_0010b0f4(iVar2,1);
  *(int *)(iVar4 + 8) = param_3;
  *(undefined4 *)(iVar4 + 0xc) = uVar3;
  uVar3 = FUN_000edadc(uVar1,param_6);
  iVar4 = FUN_0010b0f4(iVar2,2);
  *(int *)(iVar4 + 8) = param_5;
  *(undefined4 *)(iVar4 + 0xc) = uVar3;
  FUN_000fb2d4(uVar1,&param_7,**(undefined4 **)(param_8 + 0x6c),1,iVar2);
  FUN_000fb2d4(uVar1,&param_7,*(undefined4 *)(*(int *)(param_8 + 0x6c) + 4),2,iVar2);
  if ((param_3 == param_5) && (param_4 == param_6)) {
    if ((((byte)*(uint *)(iVar2 + 0xb8) & 1) != ((byte)*(uint *)(iVar2 + 0xd0) & 1)) &&
       (((*(uint *)(iVar2 + 0xb8) & 2) == 0 && ((*(uint *)(iVar2 + 0xd0) & 2) == 0)))) {
      iVar4 = FUN_0010b0f4(iVar2,2);
      iVar4 = *(int *)(iVar4 + 0x10);
      iVar5 = FUN_0010b0f4(iVar2,1);
      if (*(int *)(iVar5 + 0x10) == iVar4) {
        if ((*(byte *)(iVar2 + 0xb8) & 1) != 0) {
          FUN_00109c0e(iVar2 + 0xa4,1,0);
          local_20 = *(int *)(PTR_DAT_002139fd + local_20 * 4);
        }
        FUN_000f9ef4(iVar2,uVar1,2,0,0,0,0);
      }
    }
  }
  *(int *)(iVar2 + 300) = local_20;
  return iVar2;
}

/* FUN_00130090 @ 0x130090 (746 bytes) */
int FUN_00130090(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  uint local_34;
  int local_30;
  
  if (param_2 == 1) {
    iVar1 = *(int *)(param_3 + 0x3f4);
    iVar3 = ((int (*)())FUN_0012ead6)(*(undefined4 *)(iVar1 + 0x3a0),0x1b,0,0);
    if (iVar3 != 0) {
      FUN_00109fa4(*(undefined4 *)(iVar3 + 0x38),3,3,8,0);
      iVar4 = *(int *)(param_3 + 0xf0) + -1;
      *(int *)(param_3 + 0xf0) = iVar4;
      uVar5 = ((int (*)())FUN_0012eb2a)(*(undefined4 *)(iVar1 + 0x3a0),0,iVar4,0);
      local_34 = 1;
      local_30 = 0;
      iVar4 = *(int *)(iVar3 + 0x14);
      if (*(int *)(iVar4 + 4) != 0) {
        do {
          iVar4 = *(int *)(local_30 + *(int *)(iVar4 + 8));
          if (((*(byte *)(iVar4 + 0x14) & 1) != 0) && (0 < *(int *)(iVar4 + 0x84))) {
            iVar7 = 1;
            do {
              if (*(int *)(iVar4 + 0x98 + iVar7 * 0x18) == 0x1b) {
                FUN_0010a3c2(iVar4,iVar7,uVar5);
              }
              iVar7 = iVar7 + 1;
            } while (iVar7 <= *(int *)(iVar4 + 0x84));
          }
          local_34 = local_34 + 1;
          local_30 = local_30 + 4;
          iVar4 = *(int *)(iVar3 + 0x14);
        } while (local_34 <= *(uint *)(iVar4 + 4));
      }
      cVar2 = FUN_000d920a(*(undefined4 *)(param_3 + 0xdc),0);
      if (cVar2 == '\0') {
        piVar6 = (int *)FUN_0010a17a(0x14,param_3);
        FUN_0010a3c2(piVar6,0,uVar5);
        FUN_0010a3c2(piVar6,1,iVar3);
        iVar4 = FUN_0010b0f4(piVar6,1);
        *(undefined4 *)(iVar4 + 0x10) = DAT_001cc46c;
        FUN_000fa0d2(piVar6,*(undefined4 *)(param_3 + 0x3f4),2,0x40000000,0x40000000,0x40000000,
                     0x40000000);
        FUN_00109c0e(piVar6 + 0x2f,1,1);
        FUN_000fa0d2(piVar6,*(undefined4 *)(param_3 + 0x3f4),3,0x3f800000,0x3f800000,0x3f800000,
                     0x3f800000);
      }
      else {
        piVar6 = (int *)FUN_0010a17a(0x31,param_3);
        FUN_0010a3c2(piVar6,0,uVar5);
        FUN_0010a3c2(piVar6,1,iVar3);
        iVar4 = FUN_0010b0f4(piVar6,1);
        *(undefined4 *)(iVar4 + 0x10) = DAT_001cc4d0;
      }
      FUN_0012a9e6(iVar3,1,piVar6);
      FUN_0012a42e(uVar5,piVar6);
      FUN_000e9512(*(undefined4 *)(iVar1 + 0x394),piVar6);
      (**(code **)(*piVar6 + 8))(piVar6,param_3);
      return;
    }
  }
  return;
}

/* FUN_0013037a @ 0x13037a (470 bytes) */
int FUN_0013037a(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  undefined4 param_3;
{
  byte bVar1;
  int iVar2;
  float *local_2c;
  int local_28;
  float *local_24;
  int local_20;
  
  if ((((*(char *)(param_2 + 2) != '\0') && (bVar1 = *(byte *)((int)param_2 + 9), (bVar1 & 1) == 0))
      && ((bVar1 & 2) == 0)) && (((bVar1 & 4) == 0 && ((bVar1 & 8) == 0)))) {
    iVar2 = FUN_001840fe(param_3,-param_2[5]);
    if ((((*(char *)(iVar2 + 8) == '\0') ||
         ((bVar1 = *(byte *)(iVar2 + 9), (bVar1 & 1) != 0 || ((bVar1 & 2) != 0)))) ||
        (((bVar1 & 4) != 0 || ((bVar1 & 8) != 0)))) &&
       (((*(byte *)(iVar2 + 9) & 1) == 0 || ((*(byte *)(iVar2 + 9) & 2) != 0)))) {
      *(undefined4 *)(iVar2 + 0x20) = 0x31;
      FUN_00186a96(iVar2,param_2);
      *(float *)(iVar2 + 0x14) = param_2[5];
      *(undefined1 *)(iVar2 + 0x18) = 1;
      *(undefined4 *)(iVar2 + 0x1c) = 0;
      *(undefined1 *)(iVar2 + 9) = 1;
    }
    local_24 = (float *)&DAT_001cc470;
    local_20 = -3;
    do {
      iVar2 = FUN_001840fe(param_3,*param_2 * *local_24);
      if (((((*(char *)(iVar2 + 8) == '\0') || (bVar1 = *(byte *)(iVar2 + 9), (bVar1 & 1) != 0)) ||
           ((bVar1 & 2) != 0)) || (((bVar1 & 4) != 0 || ((bVar1 & 8) != 0)))) &&
         ((((*(byte *)(iVar2 + 9) & 1) == 0 || ((*(byte *)(iVar2 + 9) & 2) != 0)) &&
          (((*(byte *)(iVar2 + 9) & 2) == 0 || ((*(byte *)(iVar2 + 9) & 1) != 0)))))) {
        *(undefined4 *)(iVar2 + 0x20) = 0x31;
        FUN_00186a96(iVar2,param_2);
        *(float *)(iVar2 + 0x14) = param_2[5];
        *(int *)(iVar2 + 0x1c) = local_20;
        *(undefined1 *)(iVar2 + 0x18) = 0;
        *(undefined1 *)(iVar2 + 9) = 2;
      }
      local_24 = local_24 + 1;
      local_20 = local_20 + 1;
    } while (local_20 != 4);
    local_2c = (float *)&DAT_001cc470;
    local_28 = -3;
    do {
      iVar2 = FUN_001840fe(param_3,(float)((uint)*param_2 ^ _DAT_001cc4f0) * *local_2c);
      if (*(char *)(iVar2 + 8) == '\0') {
        *(undefined4 *)(iVar2 + 0x20) = 0x31;
        FUN_00186a96(iVar2,param_2);
        *(float *)(iVar2 + 0x14) = param_2[5];
        *(undefined1 *)(iVar2 + 0x18) = 1;
        *(int *)(iVar2 + 0x1c) = local_28;
        *(undefined1 *)(iVar2 + 9) = 3;
      }
      local_2c = local_2c + 1;
      local_28 = local_28 + 1;
    } while (local_28 != 4);
  }
  return;
}

/* FUN_00130550 @ 0x130550 (334 bytes) */
int FUN_00130550(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_001130c0(param_1,param_2);
  *param_1 = &PTR_FUN_001fd4c8;
  param_1[1] = PTR_DAT_002139f1;
  param_1[0xb] = 0x20;
  param_1[7] = 0;
  param_1[8] = 0x7fffffff;
  param_1[10] = 0x10;
  param_1[0xe] = 9;
  param_1[0xf] = 0x10;
  param_1[0x10] = 0x60;
  param_1[0x14] = 0x20;
  param_1[0x15] = 4;
  param_1[0x16] = 0xfffffffd;
  param_1[0x17] = 3;
  FUN_0011325a(param_1);
  FUN_00113210(param_1,0x30);
  FUN_00113210(param_1,0x31);
  FUN_00113210(param_1,0x36);
  FUN_00113210(param_1,0x39);
  FUN_00113210(param_1,0x3b);
  FUN_00113210(param_1,0x3c);
  FUN_00113210(param_1,0x40);
  FUN_00113210(param_1,0x41);
  FUN_00113210(param_1,0x42);
  param_1[2] = param_1[2] | 0x20000;
  FUN_00131e70(param_1);
  if (param_3 == '\0') {
    return;
  }
  ((int (*)())FUN_0012f43c)(param_1,param_2);
  return;
}

/* FUN_001306b2 @ 0x1306b2 (334 bytes) */
int FUN_001306b2(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_001130c0(param_1,param_2);
  *param_1 = &PTR_FUN_001fd4c8;
  param_1[1] = PTR_DAT_002139f1;
  param_1[0xb] = 0x20;
  param_1[7] = 0;
  param_1[8] = 0x7fffffff;
  param_1[10] = 0x10;
  param_1[0xe] = 9;
  param_1[0xf] = 0x10;
  param_1[0x10] = 0x60;
  param_1[0x14] = 0x20;
  param_1[0x15] = 4;
  param_1[0x16] = 0xfffffffd;
  param_1[0x17] = 3;
  FUN_0011325a(param_1);
  FUN_00113210(param_1,0x30);
  FUN_00113210(param_1,0x31);
  FUN_00113210(param_1,0x36);
  FUN_00113210(param_1,0x39);
  FUN_00113210(param_1,0x3b);
  FUN_00113210(param_1,0x3c);
  FUN_00113210(param_1,0x40);
  FUN_00113210(param_1,0x41);
  FUN_00113210(param_1,0x42);
  param_1[2] = param_1[2] | 0x20000;
  FUN_00131e70(param_1);
  if (param_3 == '\0') {
    return;
  }
  ((int (*)())FUN_0012f43c)(param_1,param_2);
  return;
}

/* FUN_00130814 @ 0x130814 (151 bytes) */
int FUN_00130814(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_000e27f6(param_2,0x3c);
  *puVar1 = PTR_DAT_002139f5 + 8;
  puVar1[2] = param_2;
  puVar1[1] = 0;
  *puVar1 = PTR_DAT_00213a09 + 8;
  FUN_001a3010(puVar1);
  FUN_001825e0(puVar1);
  puVar1[0xe] = 0;
  *(undefined4 **)(param_1 + 0x60) = puVar1;
  puVar1 = (undefined4 *)FUN_000e27f6(param_2,0xc);
  *puVar1 = PTR_DAT_00213a01 + 8;
  puVar1[1] = 1;
  puVar1[2] = 0;
  *(undefined4 **)(param_1 + 100) = puVar1;
  return;
}

/* FUN_001308be @ 0x1308be (64 bytes) */
int FUN_001308be(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x138))(param_1,0);
  *param_2 = uVar1;
  uVar1 = (**(code **)(*param_1 + 0x140))(param_1,0);
  param_2[1] = uVar1;
  return;
}

/* FUN_001308fe @ 0x1308fe (47 bytes) */
int FUN_001308fe(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  
  *param_2 = 0;
  uVar1 = (**(code **)(*param_1 + 0x138))(param_1,0);
  param_2[1] = uVar1;
  return;
}

/* FUN_0013092e @ 0x13092e (10 bytes) */
int FUN_0013092e()
{
  return 0x14;
}

/* FUN_00130938 @ 0x130938 (10 bytes) */
int FUN_00130938()
{
  return 0x20;
}

/* FUN_00130942 @ 0x130942 (46 bytes) */
undefined4 FUN_00130942(undefined4 param_1,float param_2)

{
  if ((param_2 != FLOAT_001c5b9c) && (param_2 != FLOAT_001c5ba4)) {
    return 0;
  }
  return 1;
}

/* FUN_00130970 @ 0x130970 (5 bytes) */
int FUN_00130970()
{
  return;
}

/* FUN_00130976 @ 0x130976 (50 bytes) */
int FUN_00130976(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  return *(byte *)(param_2 * 0xc +
                   *(int *)(*(int *)(param_3 + 8) + 0x268 +
                           *(int *)(*(int *)(param_3 + 8) + 0x270) * 4) + 0x10a) == param_2;
}

/* FUN_001309a8 @ 0x1309a8 (607 bytes) */
int FUN_001309a8(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  _memcpy(*(void **)(param_2 + 0x650),(void *)param_3[1],*param_3 << 4);
  _memcpy(*(void **)(param_2 + 0x654),(void *)param_3[2],900);
  *(int *)(param_2 + 0x658) = param_3[3];
  *(int *)(param_2 + 0x65c) = param_3[4];
  *(int *)(param_2 + 0x660) = param_3[5];
  *(int *)(param_2 + 0x664) = param_3[6];
  *(int *)(param_2 + 0x668) = param_3[7];
  *(int *)(param_2 + 0x66c) = param_3[8];
  *(int *)(param_2 + 0x670) = param_3[9];
  iVar2 = *(int *)(param_1 + 0x172c);
  *(int *)(param_2 + 0x104) = iVar2;
  if (iVar2 != 0) {
    uVar6 = 0;
    iVar2 = param_1;
    do {
      iVar3 = param_2 + 0x100 + *(int *)(iVar2 + 0x70) * 0xc;
      *(uint *)(iVar2 + 0x68) = (uint)*(byte *)(iVar3 + 8);
      *(uint *)(iVar2 + 0x6c) = (uint)*(byte *)(iVar3 + 9);
      uVar6 = uVar6 + 1;
      iVar2 = iVar2 + 0x34;
    } while (uVar6 < *(uint *)(param_2 + 0x104));
  }
  local_14 = 0;
  local_24 = param_1 + 0x60;
  local_28 = param_2 + 0x100;
  local_2c = 0;
  iVar2 = param_1;
  do {
    *(char *)(local_2c + 0x108 + param_2) = (char)*(undefined4 *)(iVar2 + 0x68);
    *(char *)(local_2c + 0x109 + param_2) = (char)*(undefined4 *)(iVar2 + 0x6c);
    *(char *)(local_2c + 0x10a + param_2) = (char)*(undefined4 *)(iVar2 + 0x70);
    bVar4 = *(byte *)(iVar2 + 0x78) & 0xf;
    bVar1 = *(byte *)(local_2c + 0x10b + param_2);
    *(byte *)(local_2c + 0x10b + param_2) = bVar1 & 0xf0 | bVar4;
    *(byte *)(local_2c + 0x10b + param_2) =
         bVar1 & 0x70 | bVar4 | (char)*(undefined4 *)(iVar2 + 0x7c) << 7;
    iVar3 = local_24 + 8;
    iVar5 = local_28 + 8;
    iVar7 = 0;
    do {
      *(undefined1 *)(iVar5 + 4) = *(undefined1 *)(iVar3 + 0x2c);
      *(undefined1 *)(iVar5 + 8) = *(undefined1 *)(iVar3 + 0x30);
      iVar7 = iVar7 + 1;
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar7 != 4);
    local_14 = local_14 + 1;
    local_2c = local_2c + 0xc;
    local_28 = local_28 + 0xc;
    local_24 = local_24 + 0x34;
    iVar2 = iVar2 + 0x34;
  } while (local_14 != 0x40);
  *(undefined4 *)(param_2 + 0x408) = *(undefined4 *)(param_1 + 0x1728);
  local_10 = 0;
  local_18 = param_1 + 0xd60;
  local_1c = param_2 + 0x400;
  local_20 = 0;
  do {
    *(char *)(local_20 + 0x40c + param_2) = (char)*(undefined4 *)(param_1 + 0xd68);
    *(char *)(local_20 + 0x40d + param_2) = (char)*(undefined4 *)(param_1 + 0xd6c);
    *(char *)(local_20 + 0x40e + param_2) = (char)*(undefined4 *)(param_1 + 0xd70);
    bVar4 = *(byte *)(param_1 + 0xd78) & 0xf;
    bVar1 = *(byte *)(local_20 + 0x40f + param_2);
    *(byte *)(local_20 + 0x40f + param_2) = bVar1 & 0xf0 | bVar4;
    *(byte *)(local_20 + 0x40f + param_2) =
         bVar1 & 0x70 | bVar4 | (char)*(undefined4 *)(param_1 + 0xd7c) << 7;
    iVar2 = local_18 + 8;
    iVar3 = local_1c + 0xc;
    iVar5 = 4;
    do {
      *(undefined1 *)(iVar3 + 4) = *(undefined1 *)(iVar2 + 0x2c);
      *(undefined1 *)(iVar3 + 8) = *(undefined1 *)(iVar2 + 0x30);
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    local_10 = local_10 + 1;
    local_20 = local_20 + 0xc;
    local_1c = local_1c + 0xc;
    local_18 = local_18 + 0x34;
    param_1 = param_1 + 0x34;
  } while (local_10 != 0x30);
  return 0;
}

/* FUN_00130c08 @ 0x130c08 (5 bytes) */
int FUN_00130c08()
{
  return;
}

/* FUN_00130c0e @ 0x130c0e (5 bytes) */
int FUN_00130c0e()
{
  return;
}

/* FUN_00130c14 @ 0x130c14 (16 bytes) */
int FUN_00130c14()
{
  return &DAT_001f2000;
}

/* FUN_00130c24 @ 0x130c24 (39 bytes) */
int FUN_00130c24()
{
  int in_stack_0000001c;
  
  if (*(int *)(in_stack_0000001c + 0x3f4) != 0) {
    FUN_000e27ca(in_stack_0000001c,0xf);
  }
  return 0;
}

/* FUN_00130c4c @ 0x130c4c (143 bytes) */
int FUN_00130c4c(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined1 *param_3;
  undefined4 param_4;
  undefined4 param_5;
  uint param_6;
{
  int iVar1;
  int iVar2;
  undefined1 *local_10;
  
  iVar2 = param_1 + 0xd60 + *(int *)(param_1 + 0x1728) * 0x34;
  iVar1 = iVar2 + 8;
  *(int *)(param_1 + 0x1728) = *(int *)(param_1 + 0x1728) + 1;
  *(undefined4 *)(iVar2 + 0x1c) = 1;
  *(undefined4 *)(iVar2 + 8) = param_4;
  *(undefined4 *)(iVar2 + 0xc) = param_5;
  *(uint *)(iVar2 + 0x18) = param_6;
  *(undefined4 *)(iVar2 + 0x24) = 1;
  *(undefined4 *)(iVar2 + 0x10) = param_5;
  local_10 = param_3;
  iVar2 = 0;
  do {
    if ((param_6 & 1 << ((byte)iVar2 & 0x1f)) != 0) {
      *(char *)(iVar1 + 0x2c) = (char)*(undefined4 *)(param_2 + iVar2 * 4);
      *(undefined1 *)(iVar1 + 0x30) = *local_10;
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 1;
    local_10 = local_10 + 1;
  } while (iVar2 != 4);
  return;
}

/* FUN_00130cdc @ 0x130cdc (188 bytes) */
int FUN_00130cdc(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
{
  int iVar1;
  
  iVar1 = param_1 + 0xd60 + *(int *)(param_1 + 0x1728) * 0x34;
  *(int *)(param_1 + 0x1728) = *(int *)(param_1 + 0x1728) + 1;
  *(undefined4 *)(iVar1 + 0x1c) = 1;
  *(int *)(iVar1 + 8) = param_3;
  *(undefined4 *)(iVar1 + 0xc) = param_4;
  *(undefined1 *)(iVar1 + 0x34) = param_2;
  *(undefined1 *)(iVar1 + 0x35) = param_2;
  *(undefined1 *)(iVar1 + 0x36) = param_2;
  *(undefined1 *)(iVar1 + 0x37) = param_2;
  if (param_3 != 4) {
    *(char *)(iVar1 + 0x38) = (char)param_5;
    *(char *)(iVar1 + 0x39) = (char)((uint)param_5 >> 8);
    *(char *)(iVar1 + 0x3a) = (char)((uint)param_5 >> 0x10);
    *(char *)(iVar1 + 0x3b) = (char)((uint)param_5 >> 0x18);
    *(undefined4 *)(iVar1 + 0x18) = param_9;
    *(uint *)(iVar1 + 0x24) = (uint)(param_6 == 0);
    *(undefined4 *)(iVar1 + 0x10) = param_10;
    return;
  }
  *(undefined1 *)(iVar1 + 0x38) = 3;
  *(undefined1 *)(iVar1 + 0x39) = 3;
  *(undefined1 *)(iVar1 + 0x3a) = 3;
  *(undefined1 *)(iVar1 + 0x3b) = 3;
  *(undefined4 *)(iVar1 + 0x18) = param_9;
  *(uint *)(iVar1 + 0x24) = (uint)(param_6 == 0);
  *(undefined4 *)(iVar1 + 0x10) = param_10;
  return;
}

/* FUN_00130d98 @ 0x130d98 (106 bytes) */
int FUN_00130d98(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = param_1 + 0x60 + *(int *)(param_1 + 0x172c) * 0x34;
  *(int *)(param_1 + 0x172c) = *(int *)(param_1 + 0x172c) + 1;
  *(undefined4 *)(iVar1 + 0x1c) = 1;
  *(undefined4 *)(iVar1 + 8) = 5;
  *(undefined4 *)(iVar1 + 0xc) = param_2;
  *(undefined1 *)(iVar1 + 0x34) = param_3;
  *(undefined1 *)(iVar1 + 0x35) = param_3;
  *(undefined1 *)(iVar1 + 0x36) = param_3;
  *(undefined1 *)(iVar1 + 0x37) = param_3;
  *(undefined1 *)(iVar1 + 0x38) = 0;
  *(undefined1 *)(iVar1 + 0x39) = 1;
  *(undefined1 *)(iVar1 + 0x3a) = 2;
  *(undefined1 *)(iVar1 + 0x3b) = 3;
  *(undefined4 *)(iVar1 + 0x18) = 0xf;
  *(undefined4 *)(iVar1 + 0x10) = param_2;
  return;
}

/* FUN_00130e02 @ 0x130e02 (232 bytes) */
int FUN_00130e02(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int *param_3;
{
  float fVar1;
  float *pfVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int aiStack_30 [8];
  
  *param_3 = -1;
  pcVar3 = &STACKARG(0x10);
  pfVar2 = param_2;
  pcVar5 = pcVar3;
  while ((((*pcVar5 == '\x04' || (fVar1 = *pfVar2, fVar1 == 0.0)) || (fVar1 == FLOAT_001c5ba4)) ||
         (fVar1 == FLOAT_001c5bdc))) {
    pcVar5 = pcVar5 + 1;
    pfVar2 = pfVar2 + 1;
    if (pcVar5 == &STACKARG(0x14)) {
      iVar6 = 1;
      do {
        if (*pcVar3 == '\x04') {
          param_2[iVar6 + -1] = 0.0;
        }
        iVar6 = iVar6 + 1;
        pcVar3 = pcVar3 + 1;
      } while (iVar6 != 5);
      aiStack_30[1] = 0x1b;
      aiStack_30[2] = 9;
      aiStack_30[3] = 3;
      aiStack_30[4] = 0x28;
      iVar6 = 0;
      *param_3 = 0;
      iVar4 = 1;
      do {
        iVar6 = (int)*param_2 * aiStack_30[iVar4] + iVar6;
        *param_3 = iVar6;
        iVar4 = iVar4 + 1;
        param_2 = param_2 + 1;
      } while (iVar4 != 5);
      return 1;
    }
  }
  return 0;
}

/* FUN_00130eea @ 0x130eea (95 bytes) */
int FUN_00130eea(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_001cc508;
  do {
    iVar1 = FUN_001840fe(param_2,*puVar2);
    *(undefined1 *)(iVar1 + 8) = 1;
    *(undefined4 *)(iVar1 + 0x14) = *puVar2;
    *(undefined1 *)(iVar1 + 9) = 0;
    *(undefined1 *)(iVar1 + 0x18) = 0;
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    FUN_00186ab4(iVar1,param_2);
    puVar2 = puVar2 + 1;
  } while (puVar2 != &DAT_001cc510);
  return;
}

/* FUN_00130f4a @ 0x130f4a (290 bytes) */
int FUN_00130f4a(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  float fVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  float *pfVar5;
  float local_34 [3];
  undefined4 local_28;
  byte bStack_25;
  undefined4 local_24;
  undefined4 local_20;
  
  local_20 = param_4;
  piVar3 = (int *)FUN_0010b180(param_2,param_3);
  cVar2 = (**(code **)(*piVar3 + 0x48))(piVar3);
  if (cVar2 == '\0') {
    return 0;
  }
  iVar4 = FUN_0010b0f4(param_2,param_3);
  local_24 = *(undefined4 *)(iVar4 + 0x10);
  iVar4 = 1;
  pfVar5 = local_34;
  do {
    pfVar5 = (float *)((int)pfVar5 + 4);
    pfVar5[0xffffffff] = 0.0;
    if (*(char *)((int)&local_24 + iVar4 + 3) == '\0') {
      if (((int)(char)piVar3[0x57] >> ((&bStack_25)[iVar4] & 0x1f) & 1U) == 0) {
        return 0;
      }
      fVar1 = (float)piVar3[(uint)(&bStack_25)[iVar4] * 6 + 8];
      if ((fVar1 != 0.0) && (fVar1 != FLOAT_001c5ba4)) {
        if (fVar1 != FLOAT_001c5bdc) {
          return 0;
        }
        if (NAN(fVar1) || NAN(FLOAT_001c5bdc)) {
          return 0;
        }
      }
      pfVar5[0xffffffff] = fVar1;
    }
    iVar4 = iVar4 + 1;
    if (iVar4 == 5) {
      FUN_000fa0d2(param_2,*(undefined4 *)(param_5 + 0x3f4),param_3,local_34[0],local_34[1],
                   local_34[2],local_28);
      return 1;
    }
  } while( true );
}

/* FUN_0013106c @ 0x13106c (610 bytes) */
int FUN_0013106c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  int *param_2;
  int param_3;
  int *param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_48;
  int local_44;
  int *local_40;
  int aiStack_38 [4];
  int local_28 [6];
  
  iVar6 = 1;
  do {
    aiStack_38[iVar6 + 3] = -1;
    aiStack_38[iVar6] = -1;
    iVar6 = iVar6 + 1;
  } while (iVar6 != 4);
  local_40 = param_2;
  local_48 = 0;
  local_44 = 0;
  iVar7 = 1;
  iVar6 = (**(code **)(*param_2 + 0x14))(param_2);
  if (0 < iVar6) {
    do {
      if ((*(byte *)(*(int *)(param_7 + 0x3f4) + 0x30) & 8) != 0) {
        if (iVar7 == param_3) {
          cVar2 = (**(code **)(*param_4 + 0x60))(param_4);
          if (cVar2 == '\0') {
            iVar5 = param_4[0x25];
            iVar6 = param_4[0x26];
          }
          else {
            iVar6 = FUN_0010b180(param_4,1);
            iVar6 = *(int *)(iVar6 + 0x98);
            iVar5 = FUN_0010b180(param_4,1);
            iVar5 = *(int *)(iVar5 + 0x94);
          }
          goto LAB_0013116e;
        }
        iVar6 = FUN_0010b180(param_2,iVar7);
        if (iVar6 != 0) {
          piVar3 = (int *)FUN_0010b180(param_2,iVar7);
          cVar2 = (**(code **)(*piVar3 + 0x60))(piVar3);
          if (cVar2 == '\0') {
            iVar6 = FUN_0010b180(param_2,iVar7);
            iVar6 = *(int *)(iVar6 + 0x98);
            iVar5 = FUN_0010b180(param_2,iVar7);
            iVar5 = *(int *)(iVar5 + 0x94);
          }
          else {
            uVar4 = FUN_0010b180(param_2,iVar7);
            iVar6 = FUN_0010b180(uVar4,1);
            iVar6 = *(int *)(iVar6 + 0x98);
            uVar4 = FUN_0010b180(param_2,iVar7);
            iVar5 = FUN_0010b180(uVar4,1);
            iVar5 = *(int *)(iVar5 + 0x94);
          }
          goto LAB_0013116e;
        }
        goto switchD_00131180_caseD_0;
      }
      if (iVar7 == param_3) {
        iVar5 = *(int *)(param_4[0x23] + 8);
        iVar6 = param_4[0x26];
      }
      else {
        iVar5 = local_40[0x2b];
        iVar6 = local_40[0x2c];
      }
LAB_0013116e:
      switch(iVar6) {
      case 2:
      case 0xc:
      case 0x26:
      case 0x28:
        iVar6 = 0;
        do {
          if (aiStack_38[iVar6 + 4] == -1) {
            aiStack_38[iVar6 + 4] = iVar5;
            local_48 = local_48 + 1;
            goto switchD_00131180_caseD_0;
          }
          if (iVar5 == aiStack_38[iVar6 + 4]) goto switchD_00131180_caseD_0;
          iVar6 = iVar6 + 1;
        } while (iVar6 != 3);
        break;
      case 0x29:
      case 0x37:
        iVar1 = 0;
        iVar6 = aiStack_38[1];
        while (iVar6 != -1) {
          if ((iVar5 == iVar6) || (iVar1 + 1 == 3)) goto switchD_00131180_caseD_0;
          iVar6 = aiStack_38[iVar1 + 2];
          iVar1 = iVar1 + 1;
        }
        aiStack_38[iVar1 + 1] = iVar5;
        local_44 = local_44 + 1;
      default:
switchD_00131180_caseD_0: ;
      }
      if ((1 < local_48) || (local_40 = local_40 + 6, 1 < local_44)) {
        return 0;
      }
      iVar7 = iVar7 + 1;
      iVar6 = (**(code **)(*param_2 + 0x14))(param_2);
    } while (iVar7 <= iVar6);
  }
  return 1;
}

/* FUN_001313b0 @ 0x1313b0 (40 bytes) */
int FUN_001313b0(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  param_2 = param_3;
  param_1 = *(undefined4 *)(*(int *)(param_5 + 0x3f4) + 0x3a0);
  FUN_000f6e40();
  return;
}

/* FUN_001313d8 @ 0x1313d8 (293 bytes) */
int FUN_001313d8(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  float *param_3;
  int *param_4;
{
  undefined4 uVar1;
  bool bVar2;
  int *piVar3;
  float *pfVar4;
  int iVar5;
  float fVar6;
  float *local_44;
  undefined4 uStack_30;
  float local_2c [4];
  float local_1c [3];
  
  if (*param_4 == DAT_001cc514) {
    return 0;
  }
  local_44 = param_3;
  bVar2 = true;
  (*(unsigned char *)((unsigned char *)&(uStack_30) + 3)) = '\x01';
  fVar6 = 0.0;
  iVar5 = 0;
  piVar3 = param_4;
  do {
    if ((char)*piVar3 != '\x04') {
      if (bVar2) {
        fVar6 = *local_44;
        bVar2 = false;
      }
      else if (fVar6 == *local_44) {
        bVar2 = false;
      }
      else {
        (*(unsigned char *)((unsigned char *)&(uStack_30) + 3)) = '\0';
      }
    }
    iVar5 = iVar5 + 1;
    piVar3 = (int *)((int)piVar3 + 1);
    local_44 = local_44 + 1;
  } while (iVar5 != 4);
  if ((*(unsigned char *)((unsigned char *)&(uStack_30) + 3)) == '\0') {
    iVar5 = FUN_000f8aa6(param_2,param_3,*param_4);
  }
  else {
    pfVar4 = local_2c;
    do {
      *pfVar4 = NAN;
      pfVar4 = pfVar4 + 1;
    } while (pfVar4 != local_1c);
    iVar5 = 1;
    do {
      (&uStack_30)[iVar5] = fVar6;
      iVar5 = iVar5 + 1;
    } while (iVar5 != 5);
    iVar5 = FUN_000f8aa6(param_2,local_2c,DAT_001cc510);
  }
  if (iVar5 == 0) {
    uVar1 = *(undefined4 *)(param_2 + 0x3a0);
    iVar5 = FUN_000f80ae(uVar1,param_3,param_4);
    if ((iVar5 == 0) && (iVar5 = FUN_000f7a2e(uVar1,param_3,param_4), iVar5 == 0)) {
      return 0;
    }
  }
  return iVar5;
}

/* FUN_001314fe @ 0x1314fe (529 bytes) */
int FUN_001314fe(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
  undefined4 param_9;
  int param_10;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  
  uVar2 = *(undefined4 *)(param_10 + 0x3f4);
  switch(param_2) {
  case 0:
    uVar4 = 0x27;
    bVar3 = false;
    break;
  case 1:
    uVar4 = 0x2a;
    bVar3 = false;
    break;
  case 2:
    uVar4 = 0x28;
    bVar3 = true;
    break;
  case 3:
    uVar4 = 0x29;
    bVar3 = true;
    break;
  case 4:
    uVar4 = 0x28;
    bVar3 = false;
    break;
  case 5:
    uVar4 = 0x29;
    bVar3 = false;
    break;
  default:
    uVar4 = 0xb5;
    bVar3 = false;
  }
  uVar4 = FUN_0010a17a(uVar4,param_10);
  uVar5 = FUN_000edadc(uVar2,param_4);
  iVar6 = FUN_0010b0f4(uVar4,2 - (uint)!bVar3);
  *(undefined4 *)(iVar6 + 8) = param_3;
  *(undefined4 *)(iVar6 + 0xc) = uVar5;
  uVar5 = FUN_000edadc(uVar2,param_6);
  iVar6 = FUN_0010b0f4(uVar4,((int)((uint)bVar3 << 0x1f) >> 0x1f) + 2);
  *(undefined4 *)(iVar6 + 8) = param_5;
  *(undefined4 *)(iVar6 + 0xc) = uVar5;
  FUN_000fb2d4(uVar2,&param_7,**(undefined4 **)(param_8 + 0x6c),2 - (uint)!bVar3,uVar4);
  FUN_000fb2d4(uVar2,&param_7,*(undefined4 *)(*(int *)(param_8 + 0x6c) + 4),
               ((int)((uint)bVar3 << 0x1f) >> 0x1f) + 2,uVar4);
  iVar6 = *(int *)(param_10 + 0xf0) + -1;
  *(int *)(param_10 + 0xf0) = iVar6;
  iVar7 = FUN_0010b0f4(uVar4,0);
  *(int *)(iVar7 + 8) = iVar6;
  *(undefined4 *)(iVar7 + 0xc) = 0;
  FUN_000fbaca(uVar2,uVar4,param_9);
  uVar2 = *(undefined4 *)(param_10 + 0xb8);
  puVar8 = (undefined4 *)FUN_001a7bca(uVar2,0x168);
  *puVar8 = uVar2;
  puVar1 = puVar8 + 1;
  FUN_0010ac30(puVar1,0x8c,param_10);
  iVar7 = FUN_0010b0f4(puVar1,1);
  *(int *)(iVar7 + 8) = iVar6;
  *(undefined4 *)(iVar7 + 0xc) = 0;
  puVar8[0x4c] = 0;
  return puVar1;
}

/* FUN_00131746 @ 0x131746 (321 bytes) */
int FUN_00131746(param_1, param_2)
  int *param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int local_10;
  
  if (*(char *)(param_2 + 0x3c8) == '\0') {
    iVar3 = *(int *)(*(int *)(param_2 + 0x394) + 0x98);
    if (*(int *)(iVar3 + 8) != 0) {
      local_10 = 0;
      do {
        if ((((*(byte *)(iVar3 + 0x14) & 1) != 0) && (*(int *)(*(int *)(iVar3 + 0x88) + 8) == 0xa4))
           && ((cVar1 = FUN_000e1402(*(undefined4 *)(param_2 + 8),0x3e), cVar1 == '\0' ||
               (cVar1 = (**(code **)(*param_1 + 0x18c))
                                  (param_1,*(undefined4 *)(iVar3 + 0x94),param_2), cVar1 != '\0'))))
        {
          (**(code **)(*param_1 + 400))(param_1,*(undefined4 *)(iVar3 + 0x94),local_10);
          iVar2 = FUN_0010b0f4(iVar3,0);
          *(int *)(iVar2 + 8) = local_10;
          local_10 = local_10 + 1;
        }
        iVar3 = *(int *)(iVar3 + 8);
      } while (*(int *)(iVar3 + 8) != 0);
      return;
    }
  }
  else {
    iVar3 = *(int *)(*(int *)(param_2 + 0x394) + 0x98);
    iVar2 = *(int *)(iVar3 + 8);
    while (iVar2 != 0) {
      if (((*(byte *)(iVar3 + 0x14) & 1) != 0) && (*(int *)(*(int *)(iVar3 + 0x88) + 8) == 0xa4)) {
        (**(code **)(*param_1 + 400))
                  (param_1,*(undefined4 *)(iVar3 + 0x94),*(undefined4 *)(iVar3 + 0x94));
      }
      iVar3 = *(int *)(iVar3 + 8);
      iVar2 = *(int *)(iVar3 + 8);
    }
  }
  return;
}

