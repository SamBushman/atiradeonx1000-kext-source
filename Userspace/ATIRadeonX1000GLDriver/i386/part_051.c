#include "decls.h"

/* FUN_001a79b8 @ 0x1a79b8 (38 bytes) */
int FUN_001a79b8(param_1)
  int *param_1;
{
  if (param_1[5] != 0) {
    ((int (*)())FUN_001a7aba)(*(undefined4 *)(*param_1 + 0xb4),param_1[5]);
  }
  return;
}

/* FUN_001a79de @ 0x1a79de (38 bytes) */
int FUN_001a79de(param_1)
  int *param_1;
{
  if (param_1[5] != 0) {
    ((int (*)())FUN_001a7aba)(*(undefined4 *)(*param_1 + 0xb4),param_1[5]);
  }
  return;
}

/* FUN_001a7a04 @ 0x1a7a04 (152 bytes) */
int FUN_001a7a04(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 local_10;
  
  cVar1 = *(char *)(param_1 + 6);
  if (cVar1 == '\x01') {
    local_10 = 4;
  }
  else if (cVar1 == '\x02') {
    local_10 = 0x10;
  }
  else if (cVar1 == '\0') {
    local_10 = 2;
  }
  else {
    local_10 = 0;
  }
  uVar2 = *(undefined4 *)(param_2 + 0xb4);
  puVar3 = (undefined4 *)((int (*)())FUN_001a7bca)(uVar2,0x1c);
  *puVar3 = uVar2;
  FUN_001a78e8(puVar3 + 1,1,local_10,param_2);
  puVar3[3] = 1;
  puVar3[4] = param_1;
  puVar3[5] = 0;
  return puVar3 + 1;
}

/* FUN_001a7aba @ 0x1a7aba (67 bytes) */
int FUN_001a7aba(param_1, param_2)
  int param_1;
  void *param_2;
{
  void *pvVar1;
  
  if ((*(char *)(param_1 + 0x28) != '\0') &&
     (pvVar1 = *(void **)(param_1 + 0x14), pvVar1 == param_2)) {
    _memset(pvVar1,0,*(int *)(param_1 + 8) - (int)pvVar1);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x14);
    return;
  }
  return;
}

/* FUN_001a7afe @ 0x1a7afe (91 bytes) */
int FUN_001a7afe(param_1)
  int *param_1;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)param_1[1];
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    (**(code **)(*param_1 + 0x90))(*(undefined4 *)(*param_1 + 0x98),puVar2);
    puVar2 = puVar1;
  }
  param_1[1] = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}

/* FUN_001a7b5a @ 0x1a7b5a (9 bytes) */
int FUN_001a7b5a()
{
  ((int (*)())FUN_001a7afe)();
  return;
}

/* FUN_001a7b64 @ 0x1a7b64 (102 bytes) */
int FUN_001a7b64(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  uVar3 = param_2 + 3U & 0xfffffffc;
  uVar5 = 0x2fd8;
  if (0x2fd7 < (int)uVar3) {
    uVar5 = uVar3;
  }
  uVar2 = param_1[1];
  puVar4 = (undefined4 *)FUN_000e27f6(*param_1,uVar5 + 8);
  param_1[1] = puVar4;
  *puVar4 = uVar2;
  *(uint *)(param_1[1] + 4) = uVar5 + 8;
  iVar1 = param_1[1] + 8;
  param_1[2] = iVar1;
  param_1[4] = uVar5 + 8 + param_1[1];
  param_1[5] = iVar1;
  return;
}

/* FUN_001a7bca @ 0x1a7bca (64 bytes) */
int FUN_001a7bca(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_2 + 3U & 0xfffffffc;
  iVar1 = *(int *)(param_1 + 8);
  if (*(uint *)(param_1 + 0x10) < uVar2 + iVar1) {
    ((int (*)())FUN_001a7b64)(param_1,uVar2);
    iVar1 = *(int *)(param_1 + 8);
  }
  *(int *)(param_1 + 0x14) = iVar1;
  *(uint *)(param_1 + 8) = uVar2 + iVar1;
  return iVar1;
}

/* FUN_001a7c0a @ 0x1a7c0a (61 bytes) */
int FUN_001a7c0a(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  void *pvVar1;
  
  pvVar1 = (void *)((int (*)())FUN_001a7bca)(param_1,param_3 * param_2);
  _memset(pvVar1,0,param_3 * param_2);
  return pvVar1;
}

/* FUN_001a7c48 @ 0x1a7c48 (49 bytes) */
int FUN_001a7c48(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  iVar2 = puVar1[1] - (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 8));
  for (puVar1 = (undefined4 *)*puVar1; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1)
  {
    iVar2 = iVar2 + puVar1[1];
  }
  return iVar2;
}

/* FUN_001a7c7a @ 0x1a7c7a (9 bytes) */
int FUN_001a7c7a()
{
  ((int (*)())FUN_001a7afe)();
  return;
}

/* FUN_001a7c84 @ 0x1a7c84 (20 bytes) */
int FUN_001a7c84(param_1)
  int param_1;
{
  return *(int *)(param_1 + 8) == param_1 + 0xc;
}

/* FUN_001a7c98 @ 0x1a7c98 (32 bytes) */
int FUN_001a7c98(param_1)
  int *param_1;
{
  int iVar1;
  
  iVar1 = param_1[2];
  *(int *)(iVar1 + 4) = param_1[1];
  *(int *)(param_1[1] + 8) = iVar1;
                    
                    
  (**(code **)(*param_1 + 4))();
  return;
}

/* FUN_001a7cb8 @ 0x1a7cb8 (30 bytes) */
int FUN_001a7cb8(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 4);
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 != 0) {
    *(int *)(iVar1 + 8) = param_1;
  }
  *(int *)(param_1 + 8) = param_2;
  *(int *)(param_2 + 4) = param_1;
  return;
}

/* FUN_001a7cd6 @ 0x1a7cd6 (24 bytes) */
int FUN_001a7cd6()
{
  ((int (*)())FUN_001a7cb8)();
  return;
}

/* FUN_001a7cee @ 0x1a7cee (30 bytes) */
int FUN_001a7cee(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 8);
  *(int *)(param_1 + 8) = iVar1;
  if (iVar1 != 0) {
    *(int *)(iVar1 + 4) = param_1;
  }
  *(int *)(param_1 + 4) = param_2;
  *(int *)(param_2 + 8) = param_1;
  return;
}

/* FUN_001a7d0c @ 0x1a7d0c (21 bytes) */
int FUN_001a7d0c()
{
  ((int (*)())FUN_001a7cee)();
  return;
}

/* FUN_001a7d22 @ 0x1a7d22 (17 bytes) */
int FUN_001a7d22(param_1)
  int param_1;
{
  *(int *)(param_1 + 8) = param_1 + 0xc;
  *(int *)(param_1 + 0x10) = param_1;
  return;
}

/* FUN_001a7d34 @ 0x1a7d34 (62 bytes) */
int FUN_001a7d34(param_1)
  int param_1;
{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 8);
  while (piVar2 != (int *)(param_1 + 0xc)) {
    piVar1 = (int *)piVar2[2];
    (**(code **)(*piVar2 + 4))(piVar2);
    piVar2 = piVar1;
  }
  ((int (*)())FUN_001a7d22)();
  return;
}

/* FUN_001a7d72 @ 0x1a7d72 (23 bytes) */
int FUN_001a7d72(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 8);
  *(int *)(*(int *)(param_1 + 8) + 4) = iVar1;
  return;
}

/* FUN_001a7d8a @ 0x1a7d8a (34 bytes) */
int FUN_001a7d8a(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  if (iVar2 != param_1 + 0xc) {
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      iVar2 = *(int *)(iVar2 + 8);
    } while (iVar2 != param_1 + 0xc);
    return iVar1;
  }
  return 0;
}

/* FUN_001a7dac @ 0x1a7dac (89 bytes) */
int FUN_001a7dac(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213441 + 8;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = PTR_DAT_00213441 + 8;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[2] = param_1 + 3;
  param_1[1] = 0;
  param_1[4] = param_1;
  param_1[5] = 0;
  return;
}

/* FUN_001a7e06 @ 0x1a7e06 (89 bytes) */
int FUN_001a7e06(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213441 + 8;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = PTR_DAT_00213441 + 8;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[2] = param_1 + 3;
  param_1[1] = 0;
  param_1[4] = param_1;
  param_1[5] = 0;
  return;
}

/* FUN_001a7e60 @ 0x1a7e60 (219 bytes) */
int FUN_001a7e60(param_1, param_2)
  int param_1;
  code *param_2;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  
  iVar2 = *(int *)(param_1 + 8);
  uVar5 = 1;
  do {
    uVar5 = uVar5 * 3 + 1;
  } while (uVar5 < *(uint *)(param_1 + 4));
  do {
    do {
      uVar4 = uVar5 / 3;
      if (uVar4 == 0) {
        return uVar5 * -0x55555555;
      }
      uVar5 = uVar4;
    } while (*(uint *)(param_1 + 4) <= uVar4);
    local_18 = (undefined4 *)(iVar2 + uVar4 * 4);
    local_1c = 0;
    local_20 = uVar4;
    do {
      uVar3 = *local_18;
      local_14 = local_1c;
      if (local_1c < 0) {
      }
      else {
        do {
          puVar1 = (undefined4 *)(iVar2 + local_14 * 4);
          iVar6 = (*param_2)(*puVar1,uVar3);
          if (iVar6 < 1) break;
          *(undefined4 *)(iVar2 + (uVar4 + local_14) * 4) = *puVar1;
          local_14 = local_14 - uVar4;
        } while (-1 < local_14);
      }
      *(undefined4 *)(iVar2 + (uVar4 + local_14) * 4) = uVar3;
      local_20 = local_20 + 1;
      local_1c = local_1c + 1;
      local_18 = local_18 + 1;
    } while (local_20 < *(uint *)(param_1 + 4));
  } while( true );
}

/* FUN_001a7f3c @ 0x1a7f3c (64 bytes) */
int FUN_001a7f3c(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  void *pvVar2;
  
  if (param_2 < *(uint *)(param_1 + 4)) {
    pvVar2 = (void *)(*(int *)(param_1 + 8) + param_2 * 4);
    iVar1 = *(uint *)(param_1 + 4) - 1;
    *(int *)(param_1 + 4) = iVar1;
    _memcpy(pvVar2,(void *)((int)pvVar2 + 4),(iVar1 - param_2) * 4);
  }
  return;
}

/* FUN_001a7f7c @ 0x1a7f7c (118 bytes) */
int FUN_001a7f7c(param_1, param_2)
  uint *param_1;
  uint param_2;
{
  void *pvVar1;
  uint uVar2;
  void *pvVar3;
  
  uVar2 = *param_1;
  if (uVar2 <= param_2) {
    do {
      uVar2 = uVar2 * 2;
    } while (uVar2 <= param_2);
    *param_1 = uVar2;
  }
  pvVar1 = (void *)param_1[2];
  pvVar3 = (void *)((int (*)())FUN_001a7bca)(param_1[3],uVar2 << 2);
  param_1[2] = (uint)pvVar3;
  _memcpy(pvVar3,pvVar1,param_1[1] << 2);
  ((int (*)())FUN_001a7aba)(param_1[3],pvVar1);
  if (param_1[1] < param_2 + 1) {
    param_1[1] = param_2 + 1;
  }
  return param_1[2] + param_2 * 4;
}

/* FUN_001a7ff2 @ 0x1a7ff2 (107 bytes) */
int FUN_001a7ff2(param_1, param_2)
  uint *param_1;
  uint param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  uVar3 = param_1[1];
  if (param_1[1] < param_2) {
    uVar3 = param_2;
  }
  if (*param_1 < uVar3 + 1) {
    ((int (*)())FUN_001a7f7c)(param_1,uVar3);
  }
  else {
    param_1[1] = uVar3 + 1;
  }
  iVar2 = param_1[2] + param_2 * 4;
  iVar1 = (param_1[1] - param_2) + -1;
  puVar6 = (undefined4 *)(iVar2 + iVar1 * 4);
  if (param_1[1] - param_2 != 1) {
    iVar4 = 0;
    puVar5 = puVar6;
    do {
      puVar6 = puVar5 + -1;
      *puVar5 = *puVar6;
      iVar4 = iVar4 + 1;
      puVar5 = puVar6;
    } while (iVar4 != iVar1);
  }
  *puVar6 = 0;
  return iVar2;
}

/* FUN_001a805e @ 0x1a805e (79 bytes) */
int FUN_001a805e(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  if (param_2 == **(int **)(param_1 + 8)) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      if (*(int *)(param_1 + 4) == iVar1) {
        return 0;
      }
    } while (param_2 != (*(int **)(param_1 + 8))[iVar1]);
  }
  ((int (*)())FUN_001a7f3c)(param_1,iVar1);
  return 1;
}

/* FUN_001a80ae @ 0x1a80ae (316 bytes) */
int FUN_001a80ae(param_1)
  uint *param_1;
{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint local_14;
  uint local_10;
  
  if (*param_1 == 0) {
    ((int (*)())FUN_001a7aba)(param_1[5],param_1[2]);
    return;
  }
  local_14 = 0;
  uVar4 = param_1[2];
  do {
    puVar1 = *(uint **)(uVar4 + local_14 * 4);
    if (puVar1 != (uint *)0x0) {
      if (puVar1[1] != 0) {
        local_10 = 0;
        do {
          if (local_10 < *puVar1) {
            uVar4 = puVar1[1];
            if (uVar4 <= local_10) {
              _memset((void *)(puVar1[2] + uVar4 * 4),0,(local_10 - uVar4) * 4 + 4);
              puVar1[1] = local_10 + 1;
            }
            piVar3 = (int *)(puVar1[2] + local_10 * 4);
          }
          else {
            piVar3 = (int *)((int (*)())FUN_001a7f7c)(puVar1,local_10);
          }
          local_10 = local_10 + 1;
          iVar2 = *piVar3;
          if (iVar2 != 0) {
            ((int (*)())FUN_001a7aba)(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
          }
        } while (local_10 < puVar1[1]);
        uVar4 = param_1[2];
      }
      ((int (*)())FUN_001a7aba)(param_1[5],*(undefined4 *)(uVar4 + local_14 * 4));
      uVar4 = param_1[2];
    }
    local_14 = local_14 + 1;
  } while (local_14 < *param_1);
  ((int (*)())FUN_001a7aba)(param_1[5],uVar4);
  return;
}

/* FUN_001a81ea @ 0x1a81ea (316 bytes) */
int FUN_001a81ea(param_1)
  uint *param_1;
{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint local_14;
  uint local_10;
  
  if (*param_1 == 0) {
    ((int (*)())FUN_001a7aba)(param_1[5],param_1[2]);
    return;
  }
  local_14 = 0;
  uVar4 = param_1[2];
  do {
    puVar1 = *(uint **)(uVar4 + local_14 * 4);
    if (puVar1 != (uint *)0x0) {
      if (puVar1[1] != 0) {
        local_10 = 0;
        do {
          if (local_10 < *puVar1) {
            uVar4 = puVar1[1];
            if (uVar4 <= local_10) {
              _memset((void *)(puVar1[2] + uVar4 * 4),0,(local_10 - uVar4) * 4 + 4);
              puVar1[1] = local_10 + 1;
            }
            piVar3 = (int *)(puVar1[2] + local_10 * 4);
          }
          else {
            piVar3 = (int *)((int (*)())FUN_001a7f7c)(puVar1,local_10);
          }
          local_10 = local_10 + 1;
          iVar2 = *piVar3;
          if (iVar2 != 0) {
            ((int (*)())FUN_001a7aba)(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
          }
        } while (local_10 < puVar1[1]);
        uVar4 = param_1[2];
      }
      ((int (*)())FUN_001a7aba)(param_1[5],*(undefined4 *)(uVar4 + local_14 * 4));
      uVar4 = param_1[2];
    }
    local_14 = local_14 + 1;
  } while (local_14 < *param_1);
  ((int (*)())FUN_001a7aba)(param_1[5],uVar4);
  return;
}

/* FUN_001a8326 @ 0x1a8326 (185 bytes) */
int FUN_001a8326(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  
  uVar4 = (*(code *)param_1[4])(param_2);
  puVar1 = *(uint **)(param_1[2] + (*param_1 - 1U & uVar4) * 4);
  if ((puVar1 != (uint *)0x0) && (puVar1[1] != 0)) {
    uVar4 = 0;
    do {
      if (uVar4 < *puVar1) {
        uVar2 = puVar1[1];
        if (uVar2 <= uVar4) {
          _memset((void *)(puVar1[2] + uVar2 * 4),0,(uVar4 - uVar2) * 4 + 4);
          puVar1[1] = uVar4 + 1;
        }
        piVar6 = (int *)(puVar1[2] + uVar4 * 4);
      }
      else {
        piVar6 = (int *)((int (*)())FUN_001a7f7c)(puVar1,uVar4);
      }
      puVar3 = (undefined4 *)*piVar6;
      iVar5 = (*(code *)param_1[3])(*puVar3,param_2);
      if (iVar5 == 0) {
  return puVar3;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < puVar1[1]);
  }
  return 0;
}

/* FUN_001a83e0 @ 0x1a83e0 (210 bytes) */
int FUN_001a83e0(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  uVar3 = (*(code *)param_1[4])(param_2);
  puVar1 = *(uint **)(param_1[2] + (*param_1 - 1U & uVar3) * 4);
  if ((puVar1 != (uint *)0x0) && (puVar1[1] != 0)) {
    uVar3 = 0;
    do {
      if (uVar3 < *puVar1) {
        uVar2 = puVar1[1];
        if (uVar2 <= uVar3) {
          _memset((void *)(puVar1[2] + uVar2 * 4),0,(uVar3 - uVar2) * 4 + 4);
          puVar1[1] = uVar3 + 1;
        }
        iVar5 = (*(code *)param_1[3])(*(undefined4 *)(puVar1[2] + uVar3 * 4),param_2);
      }
      else {
        puVar4 = (undefined4 *)((int (*)())FUN_001a7f7c)(puVar1,uVar3);
        iVar5 = (*(code *)param_1[3])(*puVar4,param_2);
      }
      if (iVar5 == 0) {
        ((int (*)())FUN_001a7f3c)();
        return;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < puVar1[1]);
  }
  return;
}

/* FUN_001a84b2 @ 0x1a84b2 (187 bytes) */
int FUN_001a84b2(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint local_10;
  
  uVar3 = (*(code *)param_1[4])(param_2);
  puVar1 = *(uint **)(param_1[2] + (*param_1 - 1U & uVar3) * 4);
  if ((puVar1 != (uint *)0x0) && (puVar1[1] != 0)) {
    local_10 = 0;
    do {
      if (local_10 < *puVar1) {
        uVar3 = puVar1[1];
        if (uVar3 <= local_10) {
          _memset((void *)(puVar1[2] + uVar3 * 4),0,(local_10 - uVar3) * 4 + 4);
          puVar1[1] = local_10 + 1;
        }
        puVar5 = (undefined4 *)(puVar1[2] + local_10 * 4);
      }
      else {
        puVar5 = (undefined4 *)((int (*)())FUN_001a7f7c)(puVar1,local_10);
      }
      uVar2 = *puVar5;
      iVar4 = (*(code *)param_1[3])(uVar2,param_2);
      if (iVar4 == 0) {
        return uVar2;
      }
      local_10 = local_10 + 1;
    } while (local_10 < puVar1[1]);
  }
  return 0;
}

/* FUN_001a856e @ 0x1a856e (287 bytes) */
int FUN_001a856e(param_1)
  undefined4 *param_1;
{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = param_1[3];
  if ((int)uVar4 < 0) {
    uVar4 = param_1[1];
    do {
      uVar4 = uVar4 + 1;
      param_1[1] = uVar4;
      if (*(uint *)*param_1 <= uVar4) {
        param_1[4] = 0;
        return;
      }
      puVar1 = *(uint **)(((uint *)*param_1)[2] + uVar4 * 4);
      param_1[2] = puVar1;
    } while ((puVar1 == (uint *)0x0) || (puVar1[1] == 0));
    uVar4 = puVar1[1];
    uVar5 = uVar4 - 1;
    param_1[3] = uVar4 - 2;
    if (uVar5 < *puVar1) {
      uVar2 = puVar1[1];
      if (uVar2 <= uVar5) {
        _memset((void *)(puVar1[2] + uVar2 * 4),0,(uVar5 - uVar2) * 4 + 4);
        puVar1[1] = uVar4;
      }
      puVar3 = (undefined4 *)(puVar1[2] + uVar5 * 4);
    }
    else {
      puVar3 = (undefined4 *)((int (*)())FUN_001a7f7c)(puVar1,uVar5);
    }
  }
  else {
    param_1[3] = uVar4 - 1;
    puVar1 = (uint *)param_1[2];
    if (uVar4 < *puVar1) {
      uVar5 = puVar1[1];
      if (uVar5 <= uVar4) {
        _memset((void *)(puVar1[2] + uVar5 * 4),0,(uVar4 - uVar5) * 4 + 4);
        puVar1[1] = uVar4 + 1;
      }
      puVar3 = (undefined4 *)(puVar1[2] + uVar4 * 4);
    }
    else {
      puVar3 = (undefined4 *)((int (*)())FUN_001a7f7c)(puVar1,uVar4);
    }
  }
  param_1[4] = *puVar3;
  return;
}

/* FUN_001a868e @ 0x1a868e (34 bytes) */
int FUN_001a868e(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  param_1[1] = 0xffffffff;
  param_1[3] = 0xffffffff;
  ((int (*)())FUN_001a856e)();
  return;
}

/* FUN_001a86b0 @ 0x1a86b0 (755 bytes) */
int FUN_001a86b0(param_1)
  uint *param_1;
{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  void *pvVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  int *piVar11;
  uint local_34;
  uint local_28;
  undefined4 local_20;
  uint local_1c;
  int local_18;
  int *local_14;
  
  uVar1 = *param_1;
  *param_1 = uVar1 * 2;
  pvVar5 = (void *)((int (*)())FUN_001a7bca)(param_1[5],uVar1 << 3);
  _memset(pvVar5,0,*param_1 << 2);
  if (0 < (int)uVar1) {
    local_14 = (int *)((int)pvVar5 + uVar1 * 4);
    local_34 = 0;
    do {
      puVar2 = *(uint **)(param_1[2] + local_34 * 4);
      if (puVar2 != (uint *)0x0) {
        uVar7 = param_1[5];
        puVar6 = (uint *)((int (*)())FUN_001a7bca)(uVar7,0x14);
        *puVar6 = uVar7;
        uVar7 = param_1[5];
        puVar6[4] = uVar7;
        puVar6[2] = 0;
        puVar6[1] = 2;
        uVar7 = ((int (*)())FUN_001a7bca)(uVar7,8);
        puVar6[3] = uVar7;
        piVar11 = (int *)(local_34 * 4 + (int)pvVar5);
        *piVar11 = (int)(puVar6 + 1);
        uVar7 = param_1[5];
        puVar8 = (uint *)((int (*)())FUN_001a7bca)(uVar7,0x14);
        *puVar8 = uVar7;
        puVar6 = puVar8 + 1;
        uVar7 = param_1[5];
        puVar8[4] = uVar7;
        puVar8[2] = 0;
        puVar8[1] = 2;
        uVar7 = ((int (*)())FUN_001a7bca)(uVar7,8);
        puVar8[3] = uVar7;
        *local_14 = (int)puVar6;
        puVar3 = (uint *)*piVar11;
        uVar7 = puVar2[1];
        local_18 = uVar7 * 4;
        local_1c = 0;
        uVar9 = uVar7;
        if (uVar7 != 0) {
          do {
            local_18 = local_18 + -4;
            local_28 = uVar9 - 1;
            if (local_28 < *puVar2) {
              uVar4 = puVar2[1];
              if (uVar4 <= local_28) {
                _memset((void *)(puVar2[2] + uVar4 * 4),0,(local_28 - uVar4) * 4 + 4);
                puVar2[1] = uVar9;
              }
              local_20 = *(undefined4 *)(local_18 + puVar2[2]);
              uVar9 = (*(code *)param_1[4])(local_20);
              if (local_34 != (*param_1 - 1 & uVar9)) goto LAB_001a883f;
LAB_001a88f3:
              uVar9 = puVar3[1];
              if (uVar9 < *puVar3) {
                _memset((void *)(uVar9 * 4 + puVar3[2]),0,4);
                puVar3[1] = uVar9 + 1;
                *(undefined4 *)(uVar9 * 4 + puVar3[2]) = local_20;
              }
              else {
                puVar10 = (undefined4 *)((int (*)())FUN_001a7f7c)(puVar3,uVar9);
                *puVar10 = local_20;
              }
            }
            else {
              puVar10 = (undefined4 *)((int (*)())FUN_001a7f7c)(puVar2,local_28);
              local_20 = *puVar10;
              uVar9 = (*(code *)param_1[4])(local_20);
              if (local_34 == (*param_1 - 1 & uVar9)) goto LAB_001a88f3;
LAB_001a883f:
              uVar9 = puVar8[2];
              if (uVar9 < *puVar6) {
                _memset((void *)(uVar9 * 4 + puVar8[3]),0,4);
                puVar8[2] = uVar9 + 1;
                puVar10 = (undefined4 *)(uVar9 * 4 + puVar8[3]);
              }
              else {
                puVar10 = (undefined4 *)((int (*)())FUN_001a7f7c)(puVar6,uVar9);
              }
              *puVar10 = local_20;
            }
            local_1c = local_1c + 1;
            uVar9 = local_28;
          } while (uVar7 != local_1c);
        }
      }
      local_34 = local_34 + 1;
      local_14 = local_14 + 1;
    } while (uVar1 != local_34);
  }
  param_1[2] = (uint)pvVar5;
  return;
}

/* FUN_001a89d8 @ 0x1a89d8 (173 bytes) */
int FUN_001a89d8(param_1, param_2)
  uint *param_1;
  undefined4 param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  uint *puVar3;
  int iVar4;
  int *piVar5;
  
  uVar1 = (*(code *)param_1[4])(param_2);
  iVar4 = (*param_1 - 1 & uVar1) * 4;
  uVar1 = param_1[2];
  piVar5 = (int *)(iVar4 + uVar1);
  if (*piVar5 == 0) {
    uVar1 = param_1[5];
    puVar3 = (uint *)((int (*)())FUN_001a7bca)(uVar1,0x14);
    *puVar3 = uVar1;
    uVar1 = param_1[5];
    puVar3[4] = uVar1;
    puVar3[2] = 0;
    puVar3[1] = 2;
    uVar1 = ((int (*)())FUN_001a7bca)(uVar1,8);
    puVar3[3] = uVar1;
    *piVar5 = (int)(puVar3 + 1);
    uVar1 = param_1[2];
  }
  iVar4 = *(int *)(iVar4 + uVar1);
  puVar2 = (undefined4 *)((int (*)())FUN_001a7ff2)(iVar4,0);
  *puVar2 = param_2;
  if (*param_1 < *(uint *)(iVar4 + 4)) {
    ((int (*)())FUN_001a86b0)(param_1);
  }
  param_1[1] = param_1[1] + 1;
  return;
}

/* FUN_001a8aa6 @ 0x1a8aa6 (759 bytes) */
int FUN_001a8aa6(param_1)
  uint *param_1;
{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  void *pvVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  int *piVar11;
  uint local_34;
  uint local_28;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  int *local_14;
  
  uVar1 = *param_1;
  *param_1 = uVar1 * 2;
  pvVar5 = (void *)((int (*)())FUN_001a7bca)(param_1[5],uVar1 << 3);
  _memset(pvVar5,0,*param_1 << 2);
  if (uVar1 != 0) {
    local_14 = (int *)((int)pvVar5 + uVar1 * 4);
    local_34 = 0;
    do {
      puVar2 = *(uint **)(param_1[2] + local_34 * 4);
      if (puVar2 != (uint *)0x0) {
        uVar7 = param_1[5];
        puVar6 = (uint *)((int (*)())FUN_001a7bca)(uVar7,0x14);
        *puVar6 = uVar7;
        uVar7 = param_1[5];
        puVar6[4] = uVar7;
        puVar6[2] = 0;
        puVar6[1] = 2;
        uVar7 = ((int (*)())FUN_001a7bca)(uVar7,8);
        puVar6[3] = uVar7;
        piVar11 = (int *)(local_34 * 4 + (int)pvVar5);
        *piVar11 = (int)(puVar6 + 1);
        uVar7 = param_1[5];
        puVar8 = (uint *)((int (*)())FUN_001a7bca)(uVar7,0x14);
        *puVar8 = uVar7;
        puVar6 = puVar8 + 1;
        uVar7 = param_1[5];
        puVar8[4] = uVar7;
        puVar8[2] = 0;
        puVar8[1] = 2;
        uVar7 = ((int (*)())FUN_001a7bca)(uVar7,8);
        puVar8[3] = uVar7;
        *local_14 = (int)puVar6;
        puVar3 = (uint *)*piVar11;
        uVar7 = puVar2[1];
        local_18 = uVar7 * 4;
        local_1c = 0;
        uVar9 = uVar7;
        if (uVar7 != 0) {
          do {
            local_18 = local_18 + -4;
            local_28 = uVar9 - 1;
            if (local_28 < *puVar2) {
              uVar4 = puVar2[1];
              if (uVar4 <= local_28) {
                _memset((void *)(puVar2[2] + uVar4 * 4),0,(local_28 - uVar4) * 4 + 4);
                puVar2[1] = uVar9;
              }
              local_20 = *(undefined4 **)(local_18 + puVar2[2]);
              uVar9 = (*(code *)param_1[4])(*local_20);
              if (local_34 != (*param_1 - 1 & uVar9)) goto LAB_001a8c37;
LAB_001a8ced:
              uVar9 = puVar3[1];
              if (uVar9 < *puVar3) {
                _memset((void *)(uVar9 * 4 + puVar3[2]),0,4);
                puVar3[1] = uVar9 + 1;
                *(undefined4 **)(uVar9 * 4 + puVar3[2]) = local_20;
              }
              else {
                puVar10 = (undefined4 *)((int (*)())FUN_001a7f7c)(puVar3,uVar9);
                *puVar10 = local_20;
              }
            }
            else {
              local_20 = (undefined4 *)((int (*)())FUN_001a7f7c)(puVar2,local_28);
              local_20 = (undefined4 *)*local_20;
              uVar9 = (*(code *)param_1[4])(*local_20);
              if (local_34 == (*param_1 - 1 & uVar9)) goto LAB_001a8ced;
LAB_001a8c37:
              uVar9 = puVar8[2];
              if (uVar9 < *puVar6) {
                _memset((void *)(uVar9 * 4 + puVar8[3]),0,4);
                puVar8[2] = uVar9 + 1;
                puVar10 = (undefined4 *)(uVar9 * 4 + puVar8[3]);
              }
              else {
                puVar10 = (undefined4 *)((int (*)())FUN_001a7f7c)(puVar6,uVar9);
              }
              *puVar10 = local_20;
            }
            local_1c = local_1c + 1;
            uVar9 = local_28;
          } while (uVar7 != local_1c);
        }
      }
      local_34 = local_34 + 1;
      local_14 = local_14 + 1;
    } while (uVar1 != local_34);
  }
  param_1[2] = (uint)pvVar5;
  return;
}

/* FUN_001a8dd2 @ 0x1a8dd2 (413 bytes) */
int FUN_001a8dd2(param_1, param_2, param_3)
  uint *param_1;
  uint param_2;
  uint param_3;
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  uint *puVar6;
  uint local_10;
  
  uVar2 = (*(code *)param_1[4])(param_2);
  iVar5 = (*param_1 - 1 & uVar2) * 4;
  uVar2 = param_1[2];
  piVar4 = (int *)(iVar5 + uVar2);
  if (*piVar4 == 0) {
    uVar2 = param_1[5];
    puVar6 = (uint *)((int (*)())FUN_001a7bca)(uVar2,0x14);
    *puVar6 = uVar2;
    uVar2 = param_1[5];
    puVar6[4] = uVar2;
    puVar6[2] = 0;
    puVar6[1] = 2;
    uVar2 = ((int (*)())FUN_001a7bca)(uVar2,8);
    puVar6[3] = uVar2;
    *piVar4 = (int)(puVar6 + 1);
    uVar2 = param_1[2];
  }
  puVar6 = *(uint **)(iVar5 + uVar2);
  uVar2 = param_1[5];
  puVar3 = (uint *)((int (*)())FUN_001a7bca)(uVar2,0xc);
  *puVar3 = uVar2;
  puVar3[1] = param_2;
  puVar3[2] = param_3;
  if (puVar6[1] != 0) {
    local_10 = 0;
    do {
      if (local_10 < *puVar6) {
        uVar2 = puVar6[1];
        if (uVar2 <= local_10) {
          _memset((void *)(puVar6[2] + uVar2 * 4),0,(local_10 - uVar2) * 4 + 4);
          puVar6[1] = local_10 + 1;
        }
        piVar4 = (int *)(puVar6[2] + local_10 * 4);
      }
      else {
        piVar4 = (int *)((int (*)())FUN_001a7f7c)(puVar6,local_10);
      }
      local_10 = local_10 + 1;
      puVar1 = (undefined4 *)*piVar4;
      iVar5 = (*(code *)param_1[3])(*puVar1,param_2);
      if (((iVar5 == 0) && (param_3 == puVar1[1])) && (puVar3 + 1 != (uint *)0x0)) {
        ((int (*)())FUN_001a7aba)(*puVar3,puVar3);
      }
    } while (local_10 < puVar6[1]);
  }
  piVar4 = (int *)((int (*)())FUN_001a7ff2)(puVar6,0);
  *piVar4 = (int)(puVar3 + 1);
  if (*param_1 < puVar6[1]) {
    ((int (*)())FUN_001a8aa6)(param_1);
  }
  param_1[1] = param_1[1] + 1;
  return;
}

/* FUN_001a8f90 @ 0x1a8f90 (60 bytes) */
int FUN_001a8f90(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)(param_2 + param_1 * 4);
  iVar3 = *piVar1;
  if (param_1 == iVar3) {
    *piVar1 = param_1;
    return;
  }
  do {
    iVar2 = *(int *)(param_2 + iVar3 * 4);
    iVar3 = *(int *)(param_2 + iVar2 * 4);
  } while (iVar2 != iVar3);
  while (param_1 != iVar2) {
    param_1 = *(int *)(param_2 + param_1 * 4);
    *(int *)(param_2 + param_1 * 4) = iVar2;
  }
  *piVar1 = iVar2;
  return;
}

/* FUN_001a8fcc @ 0x1a8fcc (17 bytes) */
int FUN_001a8fcc(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  *(undefined4 *)(param_3 + param_2 * 4) = param_1;
  return;
}

/* FUN_001a8fe0 @ 0x1a8fe0 (19 bytes) */
int FUN_001a8fe0(param_1)
  int param_1;
{
  if (-1 < param_1) {
    return param_1;
  }
  return 3 - param_1;
}

/* FUN_001a8ff4 @ 0x1a8ff4 (103 bytes) */
int FUN_001a8ff4(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  if ((((((char)param_1 != '\x03') || ((char)param_2 == '\0')) &&
       (((char)((uint)param_1 >> 8) != '\x03' || ((char)((uint)param_2 >> 8) == '\0')))) &&
      (((char)((uint)param_1 >> 0x10) != '\x03' || ((char)((uint)param_2 >> 0x10) == '\0')))) &&
     (((char)((uint)param_1 >> 0x18) != '\x03' || ((char)((uint)param_2 >> 0x18) == '\0')))) {
    return 0;
  }
  return 1;
}

/* FUN_001a905c @ 0x1a905c (92 bytes) */
int FUN_001a905c(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  if (((((2 < (byte)param_1) || ((char)param_2 == '\0')) &&
       ((2 < (byte)((uint)param_1 >> 8) || ((char)((uint)param_2 >> 8) == '\0')))) &&
      ((2 < (byte)((uint)param_1 >> 0x10) || ((char)((uint)param_2 >> 0x10) == '\0')))) &&
     ((2 < (byte)((uint)param_1 >> 0x18) || ((char)((uint)param_2 >> 0x18) == '\0')))) {
    return 0;
  }
  return 1;
}

/* FUN_001a90b8 @ 0x1a90b8 (47 bytes) */
int FUN_001a90b8(param_1)
  undefined4 param_1;
{
  return -((char)((uint)param_1 >> 0x10) == '\0') & 4U |
         -((char)((uint)param_1 >> 8) == '\0') & 2U | (char)param_1 == '\0';
}

/* FUN_001a90e8 @ 0x1a90e8 (22 bytes) */
int FUN_001a90e8(param_1, param_2)
  int param_1;
  int param_2;
{
  return param_1 | ~-(param_2 == '\0') & 2U;
}

/* FUN_001a90fe @ 0x1a90fe (5 bytes) */
int FUN_001a90fe()
{
  return;
}

/* FUN_001a9104 @ 0x1a9104 (173 bytes) */
int FUN_001a9104(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int local_20;
  
  cVar3 = (**(code **)(*param_2 + 0x14))(param_2);
  if (cVar3 != '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
  }
  iVar1 = param_1[0x18];
  (**(code **)(*param_2 + 0x44))(param_2,param_1[4]);
  *(undefined1 *)(param_1 + 6) = 0;
  if ((char)param_2[0x37] != '\0') {
    if (iVar1 == param_1[0x18]) {
      uVar4 = 1;
      local_20 = 0;
      iVar1 = param_2[0x34];
      if (*(int *)(iVar1 + 4) != 0) {
        do {
          iVar2 = *(int *)(*(int *)(iVar1 + 8) + local_20);
          if (iVar2 != 0) {
            *(undefined1 *)(iVar2 + 0xdc) = 1;
          }
          uVar4 = uVar4 + 1;
          local_20 = local_20 + 4;
        } while (uVar4 <= *(uint *)(iVar1 + 4));
      }
    }
    if (param_1[0x23] == 1) {
      (**(code **)(*param_1 + 0x148))(param_1);
      return;
    }
  }
  return;
}

/* FUN_001a91b2 @ 0x1a91b2 (5 bytes) */
int FUN_001a91b2()
{
  return;
}

/* FUN_001a91b8 @ 0x1a91b8 (10 bytes) */
int FUN_001a91b8()
{
  return 1;
}

/* FUN_001a91c2 @ 0x1a91c2 (5 bytes) */
int FUN_001a91c2()
{
  return;
}

/* FUN_001a91c8 @ 0x1a91c8 (14 bytes) */
int FUN_001a91c8(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  *param_2 = 0x258f;
  return;
}

/* FUN_001a91d6 @ 0x1a91d6 (65 bytes) */
int FUN_001a91d6(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_2 + 4);
  uVar2 = (uVar1 & 0x7f800000) >> 0x17;
  if (uVar2 != 0) {
    return (uVar2 - 0x40) * 0x10000 | (uVar1 & 0x80000000) >> 8 | (uVar1 & 0x7fffff) >> 7;
  }
  return 0;
}

/* FUN_001a9218 @ 0x1a9218 (17 bytes) */
int FUN_001a9218(param_1)
  int *param_1;
{
                    
                    
  (**(code **)(*param_1 + 0x104))();
  return;
}

/* FUN_001a922a @ 0x1a922a (21 bytes) */
int FUN_001a922a()
{
  undefined4 uStack00000008;
  undefined4 uStack0000000c;
  undefined4 in_stack_00000010;
  undefined4 in_stack_00000014;
  
  uStack0000000c = in_stack_00000010;
  uStack00000008 = in_stack_00000014;
  FUN_000e41ae();
  return;
}

/* FUN_001a9240 @ 0x1a9240 (50 bytes) */
int FUN_001a9240(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_001a922a)(param_2,*(undefined4 *)(param_1 + 0x5c),param_1 + 0x90,param_3,param_1);
  return;
}

/* FUN_001a9272 @ 0x1a9272 (29 bytes) */
int FUN_001a9272(param_1)
  int param_1;
{
  return *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x54) + 0x40) + 1 < *(int *)(param_1 + 0x60);
}

/* FUN_001a9290 @ 0x1a9290 (7 bytes) */
int FUN_001a9290()
{
  return 0;
}

/* FUN_001a9298 @ 0x1a9298 (5 bytes) */
int FUN_001a9298()
{
  return;
}

/* FUN_001a929e @ 0x1a929e (5 bytes) */
int FUN_001a929e()
{
  return;
}

