#include "decls.h"

/* FUN_0013c894 @ 0x13c894 (622 bytes) */
int FUN_0013c894(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  char cVar4;
  undefined4 *puVar5;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  
  if (param_2 != param_3) {
    cVar4 = FUN_0013c22c(param_1,param_2,param_3);
    if (cVar4 == '\0') {
      FUN_0013c1ee(param_1,param_2,param_3);
      puVar1 = *(uint **)(param_1 + 4);
      if (param_2 < *puVar1) {
        uVar2 = puVar1[1];
        if (uVar2 <= param_2) {
          _memset((void *)(puVar1[2] + uVar2 * 4),0,(param_2 - uVar2) * 4 + 4);
          puVar1[1] = param_2 + 1;
        }
        puVar5 = (undefined4 *)(puVar1[2] + param_2 * 4);
      }
      else {
        puVar5 = (undefined4 *)FUN_001a7f7c(puVar1,param_2);
      }
      FUN_0013c142(*puVar5,local_10,local_14);
      uVar3 = *(undefined4 *)(param_1 + 0x2c);
      puVar1 = *(uint **)(param_1 + 4);
      if (param_2 < *puVar1) {
        uVar2 = puVar1[1];
        if (uVar2 <= param_2) {
          _memset((void *)(puVar1[2] + uVar2 * 4),0,(param_2 - uVar2) * 4 + 4);
          puVar1[1] = param_2 + 1;
        }
        puVar5 = (undefined4 *)(puVar1[2] + param_2 * 4);
      }
      else {
        puVar5 = (undefined4 *)FUN_001a7f7c(puVar1,param_2);
      }
      FUN_0013c5a0(*puVar5,param_3,local_10,local_14,uVar3);
      puVar1 = *(uint **)(param_1 + 4);
      if (param_3 < *puVar1) {
        uVar2 = puVar1[1];
        if (uVar2 <= param_3) {
          _memset((void *)(puVar1[2] + uVar2 * 4),0,(param_3 - uVar2) * 4 + 4);
          puVar1[1] = param_3 + 1;
        }
        puVar5 = (undefined4 *)(puVar1[2] + param_3 * 4);
      }
      else {
        puVar5 = (undefined4 *)FUN_001a7f7c(puVar1,param_3);
      }
      FUN_0013c142(*puVar5,local_10,local_14);
      uVar3 = *(undefined4 *)(param_1 + 0x2c);
      puVar1 = *(uint **)(param_1 + 4);
      if (param_3 < *puVar1) {
        uVar2 = puVar1[1];
        if (uVar2 <= param_3) {
          _memset((void *)(puVar1[2] + uVar2 * 4),0,(param_3 - uVar2) * 4 + 4);
          puVar1[1] = param_3 + 1;
        }
        puVar5 = (undefined4 *)(puVar1[2] + param_3 * 4);
      }
      else {
        puVar5 = (undefined4 *)FUN_001a7f7c(puVar1,param_3);
      }
      FUN_0013c5a0(*puVar5,param_2,local_10,local_14,uVar3);
      return;
    }
  }
  return;
}

/* FUN_0013cb02 @ 0x13cb02 (303 bytes) */
int FUN_0013cb02(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined1 local_19;
  int local_14;
  int local_10;
  
  puVar1 = *(uint **)(param_1 + 4);
  if (param_3 < *puVar1) {
    uVar2 = puVar1[1];
    if (uVar2 <= param_3) {
      _memset((void *)(puVar1[2] + uVar2 * 4),0,(param_3 - uVar2) * 4 + 4);
      puVar1[1] = param_3 + 1;
    }
    piVar6 = (int *)(puVar1[2] + param_3 * 4);
  }
  else {
    piVar6 = (int *)FUN_001a7f7c(puVar1,param_3);
  }
  iVar3 = *piVar6;
  local_14 = *(int *)(iVar3 + 8);
  if (0 < *(int *)(iVar3 + 4)) {
    iVar7 = -1;
    local_10 = 0;
    local_19 = 0;
    do {
      while( true ) {
        iVar7 = iVar7 + 1;
        if (iVar7 == 7) {
          local_14 = *(int *)(local_14 + 0x1c);
          iVar7 = 0;
        }
        iVar5 = FUN_0013c266(param_1,*(undefined4 *)(local_14 + iVar7 * 4),1);
        if ((iVar5 == param_2) || (cVar4 = FUN_0013c22c(param_1,param_2,iVar5), cVar4 != '\0'))
        break;
        ((int (*)())FUN_0013c894)(param_1,param_2,iVar5);
        local_19 = 1;
        local_10 = local_10 + 1;
        if (*(int *)(iVar3 + 4) <= local_10) {
          return 1;
        }
      }
      local_10 = local_10 + 1;
    } while (local_10 < *(int *)(iVar3 + 4));
    return local_19;
  }
  return 0;
}

/* FUN_0013cc32 @ 0x13cc32 (349 bytes) */
int FUN_0013cc32(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  int *piVar1;
  undefined4 *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 *local_14;
  
  puVar5 = *(uint **)(param_1 + 4);
  if (param_3 < *puVar5) {
    uVar4 = puVar5[1];
    puVar3 = puVar5;
    if (uVar4 <= param_3) {
      _memset((void *)(puVar5[2] + uVar4 * 4),0,(param_3 - uVar4) * 4 + 4);
      puVar5[1] = param_3 + 1;
      puVar3 = *(uint **)(param_1 + 4);
    }
    local_14 = (undefined4 *)(puVar5[2] + param_3 * 4);
  }
  else {
    local_14 = (undefined4 *)FUN_001a7f7c(puVar5,param_3);
    puVar3 = *(uint **)(param_1 + 4);
  }
  if (param_2 < *puVar3) {
    uVar4 = puVar3[1];
    if (uVar4 <= param_2) {
      _memset((void *)(puVar3[2] + uVar4 * 4),0,(param_2 - uVar4) * 4 + 4);
      puVar3[1] = param_2 + 1;
    }
    puVar5 = *(uint **)(*(int *)(puVar3[2] + param_2 * 4) + 0x10);
    uVar4 = puVar5[1];
    if (*puVar5 <= uVar4) {
LAB_0013cd59:
      puVar2 = (undefined4 *)FUN_001a7f7c(puVar5,uVar4);
      *puVar2 = *local_14;
      return;
    }
  }
  else {
    piVar1 = (int *)FUN_001a7f7c(puVar3,param_2);
    puVar5 = *(uint **)(*piVar1 + 0x10);
    uVar4 = puVar5[1];
    if (*puVar5 <= uVar4) goto LAB_0013cd59;
  }
  _memset((void *)(uVar4 * 4 + puVar5[2]),0,4);
  puVar5[1] = uVar4 + 1;
  *(undefined4 *)(uVar4 * 4 + puVar5[2]) = *local_14;
  return;
}

/* FUN_0013cd90 @ 0x13cd90 (330 bytes) */
int FUN_0013cd90(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  uint local_10;
  
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),*(undefined4 *)(param_1 + 0x14));
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),*(undefined4 *)(param_1 + 0x18));
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),*(undefined4 *)(param_1 + 0x10));
  if (0 < *(int *)(param_1 + 0xc)) {
    local_10 = 0;
    do {
      puVar3 = *(uint **)(param_1 + 4);
      if (local_10 < *puVar3) {
        uVar1 = puVar3[1];
        if (uVar1 <= local_10) {
          _memset((void *)(puVar3[2] + uVar1 * 4),0,(local_10 - uVar1) * 4 + 4);
          puVar3[1] = local_10 + 1;
        }
        piVar4 = (int *)(puVar3[2] + local_10 * 4);
      }
      else {
        piVar4 = (int *)FUN_001a7f7c(puVar3,local_10);
      }
      local_10 = local_10 + 1;
      iVar2 = *piVar4;
      if (iVar2 != 0) {
        FUN_0013c636(iVar2);
        FUN_001a7aba(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
      }
    } while ((int)local_10 < *(int *)(param_1 + 0xc));
  }
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),*(undefined4 *)(param_1 + 0x20));
  return;
}

/* FUN_0013ceda @ 0x13ceda (330 bytes) */
int FUN_0013ceda(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  uint local_10;
  
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),*(undefined4 *)(param_1 + 0x14));
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),*(undefined4 *)(param_1 + 0x18));
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),*(undefined4 *)(param_1 + 0x10));
  if (0 < *(int *)(param_1 + 0xc)) {
    local_10 = 0;
    do {
      puVar3 = *(uint **)(param_1 + 4);
      if (local_10 < *puVar3) {
        uVar1 = puVar3[1];
        if (uVar1 <= local_10) {
          _memset((void *)(puVar3[2] + uVar1 * 4),0,(local_10 - uVar1) * 4 + 4);
          puVar3[1] = local_10 + 1;
        }
        piVar4 = (int *)(puVar3[2] + local_10 * 4);
      }
      else {
        piVar4 = (int *)FUN_001a7f7c(puVar3,local_10);
      }
      local_10 = local_10 + 1;
      iVar2 = *piVar4;
      if (iVar2 != 0) {
        FUN_0013c636(iVar2);
        FUN_001a7aba(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
      }
    } while ((int)local_10 < *(int *)(param_1 + 0xc));
  }
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),*(undefined4 *)(param_1 + 0x20));
  return;
}

/* FUN_0013d024 @ 0x13d024 (558 bytes) */
int FUN_0013d024(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  int param_3;
{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int local_24;
  int local_20;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  
  puVar1 = *(uint **)(param_3 + 4);
  if (param_2 < *puVar1) {
    uVar2 = puVar1[1];
    if (uVar2 <= param_2) {
      _memset((void *)(puVar1[2] + uVar2 * 4),0,(param_2 - uVar2) * 4 + 4);
      puVar1[1] = param_2 + 1;
    }
    iVar3 = *(int *)(puVar1[2] + param_2 * 4);
    iVar4 = param_1[2];
  }
  else {
    piVar7 = (int *)FUN_001a7f7c(puVar1,param_2);
    iVar3 = *piVar7;
    iVar4 = param_1[2];
  }
  if (iVar4 == 0) {
    param_1[2] = *(int *)(iVar3 + 8);
  }
  else {
    do {
      iVar8 = iVar4;
      iVar4 = *(int *)(iVar8 + 0x1c);
    } while (iVar4 != 0);
    *(undefined4 *)(iVar8 + 0x1c) = *(undefined4 *)(iVar3 + 8);
  }
  FUN_0013c142(param_1,local_10,local_14);
  puVar1 = *(uint **)(param_3 + 4);
  if (param_2 < *puVar1) {
    uVar2 = puVar1[1];
    if (uVar2 <= param_2) {
      _memset((void *)(puVar1[2] + uVar2 * 4),0,(param_2 - uVar2) * 4 + 4);
      puVar1[1] = param_2 + 1;
    }
    piVar7 = (int *)(puVar1[2] + param_2 * 4);
  }
  else {
    piVar7 = (int *)FUN_001a7f7c(puVar1,param_2);
  }
  iVar4 = *piVar7;
  local_24 = *(int *)(iVar4 + 8);
  if (0 < *(int *)(iVar4 + 4)) {
    iVar8 = -1;
    local_20 = 0;
    do {
      while( true ) {
        iVar8 = iVar8 + 1;
        if (iVar8 == 7) {
          local_24 = *(int *)(local_24 + 0x1c);
          iVar8 = 0;
        }
        uVar6 = FUN_0013c266(param_3,*(undefined4 *)(local_24 + iVar8 * 4),1);
        cVar5 = FUN_0013c22c(param_3,*(undefined4 *)(*(int *)(param_3 + 0x20) + *param_1 * 4),uVar6)
        ;
        if (cVar5 != '\0') break;
        FUN_0013c5a0(param_1,uVar6,local_10,local_14,*(undefined4 *)(param_3 + 0x2c));
        FUN_0013c1ee(param_3,*(undefined4 *)(*(int *)(param_3 + 0x20) + *param_1 * 4),uVar6);
        local_20 = local_20 + 1;
        if (*(int *)(iVar4 + 4) <= local_20) goto LAB_0013d18e;
      }
      local_20 = local_20 + 1;
    } while (local_20 < *(int *)(iVar4 + 4));
  }
LAB_0013d18e:
  *(undefined4 *)(iVar3 + 4) = 0;
  *(undefined4 *)(iVar3 + 8) = 0;
  return;
}

/* FUN_0013d252 @ 0x13d252 (212 bytes) */
int FUN_0013d252(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  if (param_2 != param_3) {
    cVar3 = FUN_0013c22c(param_1,param_3,param_2);
    if (cVar3 != '\0') {
      return 0;
    }
    uVar5 = param_3;
    if ((int)param_2 <= (int)param_3) {
      uVar5 = param_2;
    }
    if ((int)param_2 < (int)param_3) {
      param_2 = param_3;
    }
    puVar1 = *(uint **)(param_1 + 4);
    if (uVar5 < *puVar1) {
      uVar2 = puVar1[1];
      if (uVar2 <= uVar5) {
        _memset((void *)(puVar1[2] + uVar2 * 4),0,(uVar5 - uVar2) * 4 + 4);
        puVar1[1] = uVar5 + 1;
      }
      puVar4 = (undefined4 *)(puVar1[2] + uVar5 * 4);
    }
    else {
      puVar4 = (undefined4 *)FUN_001a7f7c(puVar1,uVar5);
    }
    ((int (*)())FUN_0013d024)(*puVar4,param_2,param_1);
    FUN_0013c314(param_1,uVar5,param_2);
  }
  return 1;
}

/* FUN_0013d326 @ 0x13d326 (658 bytes) */
int FUN_0013d326(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint *param_3;
  int param_4;
  int param_5;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint *puVar5;
  int local_1c;
  int local_18;
  int local_14;
  
  puVar5 = *(uint **)(param_1 + 4);
  if (param_2 < *puVar5) {
    uVar1 = puVar5[1];
    if (uVar1 <= param_2) {
      _memset((void *)(puVar5[2] + uVar1 * 4),0,(param_2 - uVar1) * 4 + 4);
      puVar5[1] = param_2 + 1;
    }
    piVar4 = (int *)(puVar5[2] + param_2 * 4);
  }
  else {
    piVar4 = (int *)FUN_001a7f7c(puVar5,param_2);
  }
  iVar2 = *piVar4;
  local_1c = *(int *)(iVar2 + 8);
  if (0 < *(int *)(iVar2 + 4)) {
    local_18 = -1;
    local_14 = 0;
    do {
      while( true ) {
        local_18 = local_18 + 1;
        if (local_18 == 7) {
          local_1c = *(int *)(local_1c + 0x1c);
          local_18 = 0;
        }
        uVar1 = *(uint *)(local_1c + local_18 * 4);
        puVar5 = *(uint **)(param_1 + 4);
        if (uVar1 < *puVar5) {
          uVar3 = puVar5[1];
          if (uVar3 <= uVar1) {
            _memset((void *)(puVar5[2] + uVar3 * 4),0,(uVar1 - uVar3) * 4 + 4);
            puVar5[1] = uVar1 + 1;
          }
          piVar4 = (int *)(puVar5[2] + uVar1 * 4);
        }
        else {
          piVar4 = (int *)FUN_001a7f7c(puVar5,uVar1);
        }
        if ((0 < *(int *)(*piVar4 + 0xc)) &&
           (*(int *)(*(int *)(*(int *)(param_1 + 0x28) + 0x450) + uVar1 * 4) == param_5)) break;
LAB_0013d3a4:
        local_14 = local_14 + 1;
        if (*(int *)(iVar2 + 4) <= local_14) {
          return;
        }
      }
      puVar5 = *(uint **)(param_1 + 4);
      if (uVar1 < *puVar5) {
        uVar3 = puVar5[1];
        if (uVar3 <= uVar1) {
          _memset((void *)(puVar5[2] + uVar3 * 4),0,(uVar1 - uVar3) * 4 + 4);
          puVar5[1] = uVar1 + 1;
        }
        piVar4 = (int *)(puVar5[2] + uVar1 * 4);
      }
      else {
        piVar4 = (int *)FUN_001a7f7c(puVar5,uVar1);
      }
      *(int *)(*piVar4 + 0xc) = *(int *)(*piVar4 + 0xc) + -1;
      puVar5 = *(uint **)(param_1 + 4);
      if (uVar1 < *puVar5) {
        uVar3 = puVar5[1];
        if (uVar3 <= uVar1) {
          _memset((void *)(puVar5[2] + uVar3 * 4),0,(uVar1 - uVar3) * 4 + 4);
          puVar5[1] = uVar1 + 1;
        }
        piVar4 = (int *)(puVar5[2] + uVar1 * 4);
      }
      else {
        piVar4 = (int *)FUN_001a7f7c(puVar5,uVar1);
      }
      if (*(int *)(*piVar4 + 0xc) != param_4 + -1) goto LAB_0013d3a4;
      uVar3 = param_3[1];
      if (uVar3 < *param_3) {
        _memset((void *)(uVar3 * 4 + param_3[2]),0,4);
        param_3[1] = uVar3 + 1;
        *(uint *)(uVar3 * 4 + param_3[2]) = uVar1;
      }
      else {
        puVar5 = (uint *)FUN_001a7f7c(param_3,uVar3);
        *puVar5 = uVar1;
      }
      local_14 = local_14 + 1;
    } while (local_14 < *(int *)(iVar2 + 4));
  }
  return;
}

/* FUN_0013d5b8 @ 0x13d5b8 (4713 bytes) */
int FUN_0013d5b8(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  uint *puVar13;
  int iVar14;
  int *piVar15;
  int *piVar16;
  int *piVar17;
  int iVar18;
  undefined4 *puVar19;
  uint uVar20;
  uint uVar21;
  uint *puVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int *piVar26;
  int iVar27;
  int *local_100;
  uint local_f4;
  uint local_f0;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_6c;
  uint local_68;
  int local_5c;
  int local_58;
  int local_54;
  uint local_3c;
  int local_38;
  int local_2c;
  uint local_28;
  uint local_24;
  
  puVar13 = *(uint **)(param_1 + 0x24);
  if (*puVar13 != 0) {
    uVar20 = 0;
    uVar21 = *puVar13;
    do {
      puVar13[2] = 0;
      uVar20 = uVar20 + 1;
      puVar13 = puVar13 + 1;
    } while (uVar20 < uVar21);
  }
  iVar24 = *(int *)(*(int *)(*(int *)(param_1 + 0x2c) + 0x54) + 0x14);
  iVar25 = iVar24 << 2;
  iVar5 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),iVar25);
  iVar6 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),iVar25);
  iVar7 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),iVar25);
  piVar26 = *(int **)(*(int *)(param_1 + 0x2c) + 0x54);
  (**(code **)(*piVar26 + 0x130))(piVar26,iVar7,*(int *)(param_1 + 0x2c));
  iVar8 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),iVar25);
  iVar9 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),iVar25);
  iVar10 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),iVar25);
  iVar25 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),iVar25);
  if (0 < iVar24) {
    local_bc = 0;
    do {
      iVar27 = local_bc * 4;
      iVar14 = *(int *)(iVar27 + *(int *)(param_1 + 0x14));
      if (iVar14 < 1) {
        iVar14 = 1;
      }
      *(int *)(iVar5 + iVar27) = iVar14;
      uVar12 = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc);
      puVar11 = (undefined4 *)FUN_001a7bca(uVar12,0x14);
      *puVar11 = uVar12;
      puVar11[4] = uVar12;
      puVar11[2] = 0;
      puVar11[1] = 2;
      uVar12 = FUN_001a7bca(uVar12,8);
      puVar11[3] = uVar12;
      *(undefined4 **)(iVar8 + local_bc * 4) = puVar11 + 1;
      uVar12 = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc);
      puVar11 = (undefined4 *)FUN_001a7bca(uVar12,0x14);
      *puVar11 = uVar12;
      puVar11[4] = uVar12;
      puVar11[2] = 0;
      puVar11[1] = 2;
      uVar12 = FUN_001a7bca(uVar12,8);
      puVar11[3] = uVar12;
      *(undefined4 **)(iVar9 + local_bc * 4) = puVar11 + 1;
      uVar12 = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc);
      iVar14 = *(int *)(iVar7 + iVar27);
      uVar21 = iVar14 + 0x1fU >> 5;
      puVar11 = (undefined4 *)FUN_001a7bca(uVar12,uVar21 * 4 + 0xc);
      *puVar11 = uVar12;
      puVar11[2] = iVar14;
      puVar11[1] = uVar21;
      if (uVar21 != 0) {
        uVar20 = 0;
        puVar19 = puVar11 + 1;
        do {
          puVar19[2] = 0;
          uVar20 = uVar20 + 1;
          puVar19 = puVar19 + 1;
        } while (uVar20 < uVar21);
      }
      *(undefined4 **)(iVar10 + local_bc * 4) = puVar11 + 1;
      *(undefined4 *)(iVar25 + iVar27) = 0;
      *(undefined4 *)(iVar6 + iVar27) = 0;
      local_bc = local_bc + 1;
    } while (iVar24 != local_bc);
  }
  uVar21 = *(uint *)(param_1 + 8);
  if (0 < (int)uVar21) {
    local_c0 = 0;
    do {
      piVar26 = (int *)(local_c0 * 4 + *(int *)(*(int *)(param_1 + 0x28) + 0x44c));
      *piVar26 = *piVar26 -
                 *(int *)(*(int *)(param_1 + 0x10) +
                         *(int *)(local_c0 * 4 + *(int *)(*(int *)(param_1 + 0x28) + 0x450)) * 4);
      local_c0 = local_c0 + 1;
      uVar21 = *(uint *)(param_1 + 8);
    } while (local_c0 < (int)uVar21);
  }
  if (*(int *)(param_1 + 0xc) <= (int)uVar21) {
    iVar14 = *(int *)(param_1 + 0x28);
LAB_0013d8d3:
    *(undefined4 *)(iVar14 + 0x25c) = 0;
    if (iVar24 < 1) {
      local_c4 = 0;
LAB_0013e07a:
      *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x464) = *(undefined4 *)(param_1 + 0xc);
      iVar24 = *(int *)(param_1 + 8);
      if (iVar24 < *(int *)(param_1 + 0xc)) {
        iVar14 = iVar24 * 4;
        do {
          iVar27 = *(int *)(*(int *)(param_1 + 0x28) + 0x44c);
          *(undefined4 *)(iVar27 + iVar14) =
               *(undefined4 *)(iVar27 + *(int *)(*(int *)(param_1 + 0x20) + iVar14) * 4);
          iVar24 = iVar24 + 1;
          iVar14 = iVar14 + 4;
        } while (iVar24 < *(int *)(param_1 + 0xc));
      }
      if (0 < *(int *)(param_1 + 0xc)) {
        local_2c = 0;
        do {
          piVar26 = (int *)(local_2c * 4 + *(int *)(*(int *)(param_1 + 0x28) + 0x44c));
          *piVar26 = *piVar26 +
                     *(int *)(*(int *)(param_1 + 0x10) +
                             *(int *)(*(int *)(*(int *)(param_1 + 0x28) + 0x450) + local_2c * 4) * 4
                             );
          local_2c = local_2c + 1;
        } while (local_2c < *(int *)(param_1 + 0xc));
      }
      FUN_000f0346(*(undefined4 *)(param_1 + 0x28),"color_graph");
      FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),iVar25);
      FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),iVar10);
      FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),iVar9);
      FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),iVar8);
      FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),iVar7);
      FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),iVar6);
      FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc),iVar5);
      return 0 < local_c4;
    }
    local_c4 = 0;
    local_58 = 1;
    local_54 = 0;
    do {
      iVar14 = local_58 + -1;
      piVar26 = (int *)(iVar9 + local_54);
      while( true ) {
        iVar27 = local_58 * 4;
        piVar16 = (int *)(iVar9 + iVar27 + -4);
        if (*(int *)(*(int *)(iVar9 + iVar27 + -4) + 4) == *(int *)(iVar25 + iVar27 + -4)) break;
        piVar17 = (int *)(*(int *)(param_1 + 0x28) + 0x25c);
        *piVar17 = *piVar17 + 1;
        piVar17 = (int *)(iVar27 + iVar8 + -4);
        iVar18 = *(int *)(iVar27 + iVar8 + -4);
        iVar23 = *(int *)(iVar18 + 4);
        local_24 = MACH_HEADER.magic;
        while (MACH_HEADER.magic = local_24, iVar23 != 0) {
          uVar21 = *(uint *)(iVar18 + 4);
          if (uVar21 - 1 < uVar21) {
            local_24 = *(uint *)(*(int *)(iVar18 + 8) + (uVar21 - 1) * 4);
            FUN_001a7f3c(iVar18,uVar21 - 1);
            puVar13 = *(uint **)(param_1 + 4);
            if (local_24 < *puVar13) goto LAB_0013d9bc;
LAB_0013daa0:
            piVar15 = (int *)FUN_001a7f7c(puVar13,local_24);
            *(undefined4 *)(*piVar15 + 0xc) = 0;
            puVar13 = (uint *)*piVar16;
            uVar21 = puVar13[1];
            if (uVar21 < *puVar13) goto LAB_0013d9e9;
LAB_0013dac8:
            puVar13 = (uint *)FUN_001a7f7c(puVar13,uVar21);
          }
          else {
            FUN_001a7f3c(iVar18,uVar21 - 1);
            puVar13 = *(uint **)(param_1 + 4);
            if (*puVar13 <= local_24) goto LAB_0013daa0;
LAB_0013d9bc:
            uVar21 = puVar13[1];
            if (uVar21 <= local_24) {
              _memset((void *)(puVar13[2] + uVar21 * 4),0,(local_24 - uVar21) * 4 + 4);
              puVar13[1] = local_24 + 1;
            }
            *(undefined4 *)(*(int *)(puVar13[2] + local_24 * 4) + 0xc) = 0;
            puVar13 = (uint *)*piVar16;
            uVar21 = puVar13[1];
            if (*puVar13 <= uVar21) goto LAB_0013dac8;
LAB_0013d9e9:
            _memset((void *)(uVar21 * 4 + puVar13[2]),0,4);
            puVar13[1] = uVar21 + 1;
            puVar13 = (uint *)(uVar21 * 4 + puVar13[2]);
          }
          *puVar13 = local_24;
          ((int (*)())FUN_0013d326)(param_1,local_24,*piVar17,*(undefined4 *)(iVar5 + -4 + iVar27),iVar14);
          iVar18 = *piVar17;
          local_24 = MACH_HEADER.magic;
          iVar23 = *(int *)(iVar18 + 4);
        }
        if (*(int *)(*piVar16 + 4) != *(int *)(iVar25 + iVar27 + -4)) {
          piVar16 = (int *)(iVar5 + iVar27 + -4);
          *piVar16 = *piVar16 + 1;
          local_f0 = *(uint *)(param_1 + 8);
          if ((int)local_f0 < *(int *)(param_1 + 0xc)) {
            local_5c = local_f0 * 4;
            do {
              if ((local_f0 == *(uint *)(local_5c + *(int *)(param_1 + 0x20))) &&
                 (iVar14 == *(int *)(local_5c + *(int *)(*(int *)(param_1 + 0x28) + 0x450)))) {
                puVar13 = *(uint **)(param_1 + 4);
                if (local_f0 < *puVar13) {
                  uVar21 = puVar13[1];
                  if (uVar21 <= local_f0) {
                    _memset((void *)(puVar13[2] + uVar21 * 4),0,(local_f0 - uVar21) * 4 + 4);
                    puVar13[1] = local_f0 + 1;
                  }
                  piVar16 = (int *)(local_5c + puVar13[2]);
                }
                else {
                  piVar16 = (int *)FUN_001a7f7c(puVar13,local_f0);
                }
                if (*(int *)(*piVar16 + 0xc) == *(int *)(iVar5 + iVar27 + -4) + -1) {
                  puVar13 = (uint *)*piVar17;
                  uVar21 = puVar13[1];
                  if (uVar21 < *puVar13) {
                    _memset((void *)(uVar21 * 4 + puVar13[2]),0,4);
                    puVar13[1] = uVar21 + 1;
                    *(uint *)(uVar21 * 4 + puVar13[2]) = local_f0;
                  }
                  else {
                    puVar13 = (uint *)FUN_001a7f7c(puVar13,uVar21);
                    *puVar13 = local_f0;
                  }
                }
              }
              local_f0 = local_f0 + 1;
              local_5c = local_5c + 4;
            } while ((int)local_f0 < *(int *)(param_1 + 0xc));
          }
        }
      }
      iVar18 = *(int *)(iVar8 + -4 + local_58 * 4);
      if (iVar18 != 0) {
        FUN_001a7aba(*(undefined4 *)(iVar18 + 0xc),*(undefined4 *)(iVar18 + 8));
        FUN_001a7aba(*(undefined4 *)(iVar18 + -4),iVar18 + -4);
      }
      *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x260) = 0;
LAB_0013dc59:
      if (*(int *)(*piVar26 + 4) != 0) {
        do {
          iVar18 = iVar10 + local_58 * 4;
          piVar16 = (int *)(iVar18 + -4);
          puVar13 = *(uint **)(iVar18 + -4);
          if (*puVar13 != 0) {
            uVar20 = 0;
            uVar21 = *puVar13;
            do {
              puVar13[2] = 0;
              uVar20 = uVar20 + 1;
              puVar13 = puVar13 + 1;
            } while (uVar20 < uVar21);
          }
          iVar18 = *(int *)(param_1 + 0x28);
          iVar23 = *(int *)(iVar18 + 0x430 + iVar14 * 4);
          if (iVar23 < *(int *)(iVar18 + 0x43c + iVar14 * 4)) {
            do {
              cVar4 = FUN_00137fb8(iVar18,iVar23);
              if (cVar4 == '\0') {
                uVar21 = iVar23 - *(int *)(*(int *)(param_1 + 0x28) + 0x430 + iVar14 * 4);
                puVar13 = (uint *)(*piVar16 + 8 + (uVar21 >> 5) * 4);
                *puVar13 = *puVar13 | 1 << ((byte)uVar21 & 0x1f);
              }
              iVar23 = iVar23 + 1;
              iVar18 = *(int *)(param_1 + 0x28);
            } while (iVar23 < *(int *)(iVar18 + 0x43c + iVar14 * 4));
            iVar18 = *piVar26;
            uVar20 = *(uint *)(iVar18 + 4);
            uVar21 = uVar20 - 1;
            if (uVar20 <= uVar21) goto LAB_0013dccf;
LAB_0013df56:
            local_28 = *(uint *)(*(int *)(iVar18 + 8) + uVar21 * 4);
            FUN_001a7f3c(iVar18,uVar20 - 1);
            puVar13 = *(uint **)(param_1 + 4);
            if (local_28 < *puVar13) goto LAB_0013dcf6;
LAB_0013df81:
            piVar17 = (int *)FUN_001a7f7c(puVar13,local_28);
          }
          else {
            iVar18 = *piVar26;
            uVar20 = *(uint *)(iVar18 + 4);
            uVar21 = uVar20 - 1;
            if (uVar21 < uVar20) goto LAB_0013df56;
LAB_0013dccf:
            local_28 = MACH_HEADER.magic;
            FUN_001a7f3c(iVar18,uVar20 - 1);
            puVar13 = *(uint **)(param_1 + 4);
            if (*puVar13 <= local_28) goto LAB_0013df81;
LAB_0013dcf6:
            uVar21 = puVar13[1];
            if (uVar21 <= local_28) {
              _memset((void *)(puVar13[2] + uVar21 * 4),0,(local_28 - uVar21) * 4 + 4);
              puVar13[1] = local_28 + 1;
            }
            piVar17 = (int *)(puVar13[2] + local_28 * 4);
          }
          iVar18 = *piVar17;
          local_100 = *(int **)(iVar18 + 8);
          if (0 < *(int *)(iVar18 + 4)) {
            iVar23 = -1;
            local_6c = 0;
            do {
              while( true ) {
                iVar23 = iVar23 + 1;
                if (iVar23 == 7) {
                  local_100 = (int *)local_100[7];
                  iVar23 = 0;
                  iVar3 = *(int *)(param_1 + 0x28);
                  iVar1 = *local_100 * 4;
                  iVar2 = *(int *)(*(int *)(iVar3 + 0x450) + iVar1);
                }
                else {
                  iVar3 = *(int *)(param_1 + 0x28);
                  iVar1 = local_100[iVar23] * 4;
                  iVar2 = *(int *)(*(int *)(iVar3 + 0x450) + iVar1);
                }
                if ((iVar14 == iVar2) &&
                   (uVar21 = *(uint *)(iVar1 + *(int *)(iVar3 + 0x44c)), -1 < (int)uVar21)) break;
                local_6c = local_6c + 1;
                if (*(int *)(iVar18 + 4) <= local_6c) goto LAB_0013dde8;
              }
              puVar13 = (uint *)(*piVar16 + 8 + (uVar21 >> 5) * 4);
              *puVar13 = *puVar13 | 1 << ((byte)uVar21 & 0x1f);
              local_6c = local_6c + 1;
            } while (local_6c < *(int *)(iVar18 + 4));
          }
LAB_0013dde8:
          puVar13 = *(uint **)(param_1 + 4);
          if (local_28 < *puVar13) {
            uVar21 = puVar13[1];
            if (uVar21 <= local_28) {
              _memset((void *)(puVar13[2] + uVar21 * 4),0,(local_28 - uVar21) * 4 + 4);
              puVar13[1] = local_28 + 1;
            }
            piVar17 = (int *)(puVar13[2] + local_28 * 4);
          }
          else {
            piVar17 = (int *)FUN_001a7f7c(puVar13,local_28);
          }
          uVar21 = *(uint *)(*(int *)(*piVar17 + 0x10) + 4);
          if (0 < (int)uVar21) {
            local_68 = 0;
            do {
              puVar13 = *(uint **)(param_1 + 4);
              if (local_28 < *puVar13) {
                uVar20 = puVar13[1];
                if (uVar20 <= local_28) {
                  _memset((void *)(puVar13[2] + uVar20 * 4),0,(local_28 - uVar20) * 4 + 4);
                  puVar13[1] = local_28 + 1;
                }
                puVar13 = *(uint **)(*(int *)(local_28 * 4 + puVar13[2]) + 0x10);
                if (*puVar13 <= local_68) goto LAB_0013dedd;
LAB_0013de55:
                uVar20 = puVar13[1];
                if (uVar20 <= local_68) {
                  _memset((void *)(puVar13[2] + uVar20 * 4),0,(local_68 - uVar20) * 4 + 4);
                  puVar13[1] = local_68 + 1;
                }
                puVar11 = (undefined4 *)(puVar13[2] + local_68 * 4);
              }
              else {
                piVar17 = (int *)FUN_001a7f7c(puVar13,local_28);
                puVar13 = *(uint **)(*piVar17 + 0x10);
                if (local_68 < *puVar13) goto LAB_0013de55;
LAB_0013dedd:
                puVar11 = (undefined4 *)FUN_001a7f7c(puVar13,local_68);
              }
              uVar20 = *(uint *)(*(int *)(*(int *)(param_1 + 0x28) + 0x44c) + *(int *)*puVar11 * 4);
              if ((-1 < (int)uVar20) &&
                 ((*(uint *)(*piVar16 + 8 + (uVar20 >> 5) * 4) >> ((byte)uVar20 & 0x1f) & 1) == 0))
              {
                piVar16 = (int *)(*(int *)(param_1 + 0x28) + 0x260);
                *piVar16 = *piVar16 + 1;
                if (*(int *)(iVar6 + iVar27 + -4) < (int)(uVar20 + 1)) {
                  *(uint *)(iVar6 + iVar27 + -4) = uVar20 + 1;
                }
                goto LAB_0013dfcd;
              }
              local_68 = local_68 + 1;
            } while (uVar21 != local_68);
          }
          iVar18 = *piVar16;
          if (*(uint *)(iVar18 + 4) == 0) goto LAB_0013e27e;
          if ((*(byte *)(iVar18 + 8) & 1) == 0) {
            uVar20 = 0;
            iVar18 = 1;
          }
          else {
            uVar20 = 0;
            do {
              uVar21 = uVar20;
              uVar20 = uVar21 + 1;
              if (uVar20 == *(uint *)(iVar18 + 4)) goto LAB_0013e27e;
            } while ((*(uint *)(iVar18 + 8 + (uVar20 >> 5) * 4) >> ((byte)uVar20 & 0x1f) & 1) != 0);
            if (uVar20 == 0xffffffff) goto LAB_0013e27e;
            iVar18 = uVar21 + 2;
          }
          if (*(int *)(iVar6 + iVar27 + -4) < iVar18) {
            *(int *)(iVar6 + iVar27 + -4) = iVar18;
          }
LAB_0013dfcd:
          *(uint *)(*(int *)(*(int *)(param_1 + 0x28) + 0x44c) + local_28 * 4) = uVar20;
          FUN_00137b7e(*(int *)(param_1 + 0x28),
                       uVar20 + *(int *)(*(int *)(param_1 + 0x28) + 0x430 + iVar14 * 4));
          if (*(int *)(*piVar26 + 4) == 0) break;
        } while( true );
      }
      iVar14 = *(int *)(iVar9 + -4 + local_58 * 4);
      if (iVar14 != 0) {
        FUN_001a7aba(*(undefined4 *)(iVar14 + 0xc),*(undefined4 *)(iVar14 + 8));
        FUN_001a7aba(*(undefined4 *)(iVar14 + -4),iVar14 + -4);
      }
      iVar14 = *(int *)(iVar10 + -4 + local_58 * 4);
      if (iVar14 != 0) {
        FUN_001a7aba(*(undefined4 *)(iVar14 + -4),iVar14 + -4);
      }
      local_58 = local_58 + 1;
      local_54 = local_54 + 4;
      if (iVar24 + 1 == local_58) goto LAB_0013e07a;
    } while( true );
  }
  local_3c = uVar21 + 1;
  local_38 = uVar21 * 4;
  iVar14 = *(int *)(param_1 + 0x28);
  local_f4 = local_3c;
  do {
    if (uVar21 == *(uint *)(local_38 + *(int *)(param_1 + 0x20))) {
      piVar26 = (int *)(iVar25 + *(int *)(local_38 + *(int *)(iVar14 + 0x450)) * 4);
      *piVar26 = *piVar26 + 1;
      puVar13 = *(uint **)(param_1 + 4);
      if (uVar21 < *puVar13) {
        uVar20 = puVar13[1];
        puVar22 = puVar13;
        if (uVar20 <= uVar21) {
          _memset((void *)(puVar13[2] + uVar20 * 4),0,(uVar21 - uVar20) * 4 + 4);
          puVar13[1] = local_3c;
          puVar22 = *(uint **)(param_1 + 4);
        }
        piVar26 = (int *)(local_38 + puVar13[2]);
      }
      else {
        piVar26 = (int *)FUN_001a7f7c(puVar13,uVar21);
        puVar22 = *(uint **)(param_1 + 4);
      }
      iVar14 = *piVar26;
      uVar12 = *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x450);
      if (uVar21 < *puVar22) {
        uVar20 = puVar22[1];
        if (uVar20 <= uVar21) {
          _memset((void *)(puVar22[2] + uVar20 * 4),0,(uVar21 - uVar20) * 4 + 4);
          puVar22[1] = local_3c;
        }
        puVar11 = (undefined4 *)(local_38 + puVar22[2]);
      }
      else {
        puVar11 = (undefined4 *)FUN_001a7f7c(puVar22,uVar21);
      }
      uVar12 = FUN_0013c332(*puVar11,uVar21,uVar12,param_1);
      *(undefined4 *)(iVar14 + 0xc) = uVar12;
      puVar13 = *(uint **)(param_1 + 4);
      if (uVar21 < *puVar13) {
        uVar20 = puVar13[1];
        if (uVar20 <= uVar21) {
          _memset((void *)(puVar13[2] + uVar20 * 4),0,(uVar21 - uVar20) * 4 + 4);
          puVar13[1] = local_3c;
        }
        piVar26 = (int *)(local_38 + puVar13[2]);
      }
      else {
        piVar26 = (int *)FUN_001a7f7c(puVar13,uVar21);
      }
      if (*(int *)(*piVar26 + 0xc) == 0) {
        puVar13 = *(uint **)(iVar9 + *(int *)(local_38 + *(int *)(*(int *)(param_1 + 0x28) + 0x450))
                                     * 4);
        uVar20 = puVar13[1];
        if (uVar20 < *puVar13) {
          _memset((void *)(uVar20 * 4 + puVar13[2]),0,4);
          puVar13[1] = uVar20 + 1;
          puVar13 = (uint *)(uVar20 * 4 + puVar13[2]);
        }
        else {
          puVar13 = (uint *)FUN_001a7f7c(puVar13,uVar20);
        }
      }
      else {
        puVar13 = *(uint **)(param_1 + 4);
        if (uVar21 < *puVar13) {
          uVar20 = puVar13[1];
          if (uVar20 <= uVar21) {
            _memset((void *)(puVar13[2] + uVar20 * 4),0,(uVar21 - uVar20) * 4 + 4);
            puVar13[1] = local_3c;
          }
          piVar26 = (int *)(puVar13[2] + local_38);
        }
        else {
          piVar26 = (int *)FUN_001a7f7c(puVar13,uVar21);
        }
        iVar14 = *(int *)(param_1 + 0x28);
        iVar27 = *(int *)(local_38 + *(int *)(iVar14 + 0x450)) * 4;
        if (*(int *)(iVar5 + iVar27) <= *(int *)(*piVar26 + 0xc)) goto LAB_0013d762;
        puVar13 = *(uint **)(iVar8 + iVar27);
        uVar20 = puVar13[1];
        if (uVar20 < *puVar13) {
          _memset((void *)(uVar20 * 4 + puVar13[2]),0,4);
          puVar13[1] = uVar20 + 1;
          puVar13 = (uint *)(uVar20 * 4 + puVar13[2]);
        }
        else {
          puVar13 = (uint *)FUN_001a7f7c(puVar13,uVar20);
        }
      }
      *puVar13 = uVar21;
      iVar14 = *(int *)(param_1 + 0x28);
    }
LAB_0013d762:
    local_3c = local_3c + 1;
    local_38 = local_38 + 4;
    if (*(int *)(param_1 + 0xc) <= (int)local_f4) goto LAB_0013d8d3;
    uVar21 = local_f4;
    local_f4 = local_f4 + 1;
  } while( true );
LAB_0013e27e:
  iVar18 = *(int *)(param_1 + 0x2c);
  if (*(short *)(*(int *)(iVar18 + 0x54) + 8) < 0) {
    cVar4 = FUN_000e1402(iVar18,0x48);
    if (cVar4 != '\0') {
      local_c4 = local_c4 + 1;
      puVar13 = *(uint **)(param_1 + 4);
      if (local_28 < *puVar13) {
        uVar21 = puVar13[1];
        if (uVar21 <= local_28) {
          _memset((void *)(puVar13[2] + uVar21 * 4),0,(local_28 - uVar21) * 4 + 4);
          puVar13[1] = local_28 + 1;
        }
        piVar16 = (int *)(puVar13[2] + local_28 * 4);
      }
      else {
        piVar16 = (int *)FUN_001a7f7c(puVar13,local_28);
      }
      if (*(char *)(*piVar16 + 0x18) == '\0') {
        uVar21 = local_28 >> 5;
        (*(unsigned char *)((unsigned char *)&(local_28) + 0)) = (byte)local_28 & 0x1f;
        puVar13 = (uint *)(*(int *)(param_1 + 0x24) + 8 + uVar21 * 4);
        *puVar13 = *puVar13 | 1 << (byte)local_28;
      }
      goto LAB_0013dc59;
    }
    iVar18 = *(int *)(param_1 + 0x2c);
  }
  FUN_000e27ca(iVar18,4);
  goto LAB_0013dc59;
}

/* FUN_0013e86a @ 0x13e86a (732 bytes) */
int FUN_0013e86a(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int local_18;
  
  *param_1 = 0;
  param_1[2] = param_2;
  param_1[3] = param_3;
  param_1[10] = param_4;
  param_1[0xb] = param_5;
  if (param_3 == 0) {
    return;
  }
  iVar3 = FUN_001a7bca(*(undefined4 *)(param_5 + 0xbc),param_3 * 4);
  param_1[8] = iVar3;
  uVar5 = *(undefined4 *)(param_1[0xb] + 0xbc);
  puVar4 = (undefined4 *)FUN_001a7bca(uVar5,0x14);
  *puVar4 = uVar5;
  puVar4[4] = uVar5;
  puVar4[2] = 0;
  puVar4[1] = 2;
  uVar5 = FUN_001a7bca(uVar5,8);
  puVar4[3] = uVar5;
  param_1[1] = (int)(puVar4 + 1);
  iVar3 = param_1[3];
  if (0 < iVar3) {
    local_18 = 0;
    do {
      while( true ) {
        uVar5 = *(undefined4 *)(param_1[0xb] + 0xbc);
        puVar4 = (undefined4 *)FUN_001a7bca(uVar5,0x28);
        *puVar4 = uVar5;
        puVar4 = puVar4 + 1;
        FUN_0013c746(puVar4,local_18,0,param_1,param_1[0xb]);
        puVar1 = (uint *)param_1[1];
        uVar7 = puVar1[1];
        if (uVar7 < *puVar1) break;
        puVar6 = (undefined4 *)FUN_001a7f7c(puVar1,uVar7);
        *puVar6 = puVar4;
        local_18 = local_18 + 1;
        iVar3 = param_1[3];
        if (iVar3 <= local_18) goto LAB_0013e9de;
      }
      _memset((void *)(puVar1[2] + uVar7 * 4),0,4);
      puVar1[1] = uVar7 + 1;
      *(undefined4 **)(puVar1[2] + uVar7 * 4) = puVar4;
      local_18 = local_18 + 1;
      iVar3 = param_1[3];
    } while (local_18 < iVar3);
  }
LAB_0013e9de:
  uVar5 = *(undefined4 *)(param_1[0xb] + 0xbc);
  iVar3 = (iVar3 * iVar3 - iVar3) / 2;
  uVar7 = iVar3 + 0x1fU >> 5;
  puVar4 = (undefined4 *)FUN_001a7bca(uVar5,uVar7 * 4 + 0xc);
  *puVar4 = uVar5;
  puVar4[2] = iVar3;
  puVar4[1] = uVar7;
  if (uVar7 != 0) {
    uVar8 = 0;
    puVar6 = puVar4 + 1;
    do {
      puVar6[2] = 0;
      uVar8 = uVar8 + 1;
      puVar6 = puVar6 + 1;
    } while (uVar8 < uVar7);
  }
  *param_1 = (int)(puVar4 + 1);
  iVar9 = *(int *)(*(int *)(param_1[0xb] + 0x54) + 0x14) << 2;
  iVar3 = FUN_001a7bca(*(undefined4 *)(param_1[0xb] + 0xbc),iVar9);
  param_1[4] = iVar3;
  piVar2 = *(int **)(param_1[0xb] + 0x54);
  (**(code **)(*piVar2 + 0x134))(piVar2,iVar3,param_1[0xb]);
  iVar3 = FUN_001a7bca(*(undefined4 *)(param_1[0xb] + 0xbc),iVar9);
  param_1[6] = iVar3;
  iVar3 = FUN_001a7bca(*(undefined4 *)(param_1[0xb] + 0xbc),iVar9);
  param_1[5] = iVar3;
  iVar3 = param_1[0xb];
  if (0 < *(int *)(*(int *)(iVar3 + 0x54) + 0x14)) {
    iVar9 = 0;
    do {
      *(undefined4 *)(param_1[6] + iVar9 * 4) = 0;
      *(undefined4 *)(param_1[5] + iVar9 * 4) = 0;
      iVar9 = iVar9 + 1;
      iVar3 = param_1[0xb];
    } while (iVar9 < *(int *)(*(int *)(iVar3 + 0x54) + 0x14));
  }
  uVar5 = *(undefined4 *)(iVar3 + 0xbc);
  puVar6 = (undefined4 *)FUN_001a7bca(uVar5,0x20c);
  *puVar6 = uVar5;
  puVar6[2] = 0x1000;
  puVar6[1] = 0x80;
  uVar7 = 0;
  puVar4 = puVar6 + 1;
  do {
    puVar4[2] = 0;
    uVar7 = uVar7 + 1;
    puVar4 = puVar4 + 1;
  } while (uVar7 < 0x80);
  param_1[9] = (int)(puVar6 + 1);
  return;
}

/* FUN_0013eb88 @ 0x13eb88 (732 bytes) */
int FUN_0013eb88(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int local_18;
  
  *param_1 = 0;
  param_1[2] = param_2;
  param_1[3] = param_3;
  param_1[10] = param_4;
  param_1[0xb] = param_5;
  if (param_3 == 0) {
    return;
  }
  iVar3 = FUN_001a7bca(*(undefined4 *)(param_5 + 0xbc),param_3 * 4);
  param_1[8] = iVar3;
  uVar5 = *(undefined4 *)(param_1[0xb] + 0xbc);
  puVar4 = (undefined4 *)FUN_001a7bca(uVar5,0x14);
  *puVar4 = uVar5;
  puVar4[4] = uVar5;
  puVar4[2] = 0;
  puVar4[1] = 2;
  uVar5 = FUN_001a7bca(uVar5,8);
  puVar4[3] = uVar5;
  param_1[1] = (int)(puVar4 + 1);
  iVar3 = param_1[3];
  if (0 < iVar3) {
    local_18 = 0;
    do {
      while( true ) {
        uVar5 = *(undefined4 *)(param_1[0xb] + 0xbc);
        puVar4 = (undefined4 *)FUN_001a7bca(uVar5,0x28);
        *puVar4 = uVar5;
        puVar4 = puVar4 + 1;
        FUN_0013c746(puVar4,local_18,0,param_1,param_1[0xb]);
        puVar1 = (uint *)param_1[1];
        uVar7 = puVar1[1];
        if (uVar7 < *puVar1) break;
        puVar6 = (undefined4 *)FUN_001a7f7c(puVar1,uVar7);
        *puVar6 = puVar4;
        local_18 = local_18 + 1;
        iVar3 = param_1[3];
        if (iVar3 <= local_18) goto LAB_0013ecfc;
      }
      _memset((void *)(puVar1[2] + uVar7 * 4),0,4);
      puVar1[1] = uVar7 + 1;
      *(undefined4 **)(puVar1[2] + uVar7 * 4) = puVar4;
      local_18 = local_18 + 1;
      iVar3 = param_1[3];
    } while (local_18 < iVar3);
  }
LAB_0013ecfc:
  uVar5 = *(undefined4 *)(param_1[0xb] + 0xbc);
  iVar3 = (iVar3 * iVar3 - iVar3) / 2;
  uVar7 = iVar3 + 0x1fU >> 5;
  puVar4 = (undefined4 *)FUN_001a7bca(uVar5,uVar7 * 4 + 0xc);
  *puVar4 = uVar5;
  puVar4[2] = iVar3;
  puVar4[1] = uVar7;
  if (uVar7 != 0) {
    uVar8 = 0;
    puVar6 = puVar4 + 1;
    do {
      puVar6[2] = 0;
      uVar8 = uVar8 + 1;
      puVar6 = puVar6 + 1;
    } while (uVar8 < uVar7);
  }
  *param_1 = (int)(puVar4 + 1);
  iVar9 = *(int *)(*(int *)(param_1[0xb] + 0x54) + 0x14) << 2;
  iVar3 = FUN_001a7bca(*(undefined4 *)(param_1[0xb] + 0xbc),iVar9);
  param_1[4] = iVar3;
  piVar2 = *(int **)(param_1[0xb] + 0x54);
  (**(code **)(*piVar2 + 0x134))(piVar2,iVar3,param_1[0xb]);
  iVar3 = FUN_001a7bca(*(undefined4 *)(param_1[0xb] + 0xbc),iVar9);
  param_1[6] = iVar3;
  iVar3 = FUN_001a7bca(*(undefined4 *)(param_1[0xb] + 0xbc),iVar9);
  param_1[5] = iVar3;
  iVar3 = param_1[0xb];
  if (0 < *(int *)(*(int *)(iVar3 + 0x54) + 0x14)) {
    iVar9 = 0;
    do {
      *(undefined4 *)(param_1[6] + iVar9 * 4) = 0;
      *(undefined4 *)(param_1[5] + iVar9 * 4) = 0;
      iVar9 = iVar9 + 1;
      iVar3 = param_1[0xb];
    } while (iVar9 < *(int *)(*(int *)(iVar3 + 0x54) + 0x14));
  }
  uVar5 = *(undefined4 *)(iVar3 + 0xbc);
  puVar6 = (undefined4 *)FUN_001a7bca(uVar5,0x20c);
  *puVar6 = uVar5;
  puVar6[2] = 0x1000;
  puVar6[1] = 0x80;
  uVar7 = 0;
  puVar4 = puVar6 + 1;
  do {
    puVar4[2] = 0;
    uVar7 = uVar7 + 1;
    puVar4 = puVar4 + 1;
  } while (uVar7 < 0x80);
  param_1[9] = (int)(puVar6 + 1);
  return;
}

/* FUN_0013eea6 @ 0x13eea6 (529 bytes) */
int FUN_0013eea6(param_1)
  int *param_1;
{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  byte local_30;
  
  iVar2 = param_1[3];
  iVar7 = iVar2 + 1;
  param_1[3] = iVar7;
  iVar3 = *param_1;
  iVar7 = (iVar7 * iVar7 - iVar7) / 2;
  uVar4 = *(undefined4 *)(param_1[0xb] + 0xbc);
  uVar10 = iVar7 + 0x1fU >> 5;
  puVar5 = (undefined4 *)FUN_001a7bca(uVar4,uVar10 * 4 + 0xc);
  *puVar5 = uVar4;
  puVar5[2] = iVar7;
  puVar5[1] = uVar10;
  if (uVar10 != 0) {
    uVar8 = 0;
    puVar6 = puVar5 + 1;
    do {
      puVar6[2] = 0;
      uVar8 = uVar8 + 1;
      puVar6 = puVar6 + 1;
    } while (uVar8 < uVar10);
  }
  *param_1 = (int)(puVar5 + 1);
  iVar9 = param_1[3];
  if (iVar7 - iVar9 != -1 && -1 < (iVar7 - iVar9) + 1) {
    uVar10 = 0;
    do {
      local_30 = (byte)uVar10 & 0x1f;
      if ((*(uint *)(iVar3 + 8 + (uVar10 >> 5) * 4) >> local_30 & 1) != 0) {
        puVar1 = (uint *)(*param_1 + 8 + (uVar10 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << local_30;
        iVar9 = param_1[3];
      }
      uVar10 = uVar10 + 1;
    } while ((int)uVar10 < (iVar7 - iVar9) + 1);
  }
  if (iVar3 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
    iVar9 = param_1[3];
  }
  iVar3 = param_1[8];
  iVar7 = FUN_001a7bca(*(undefined4 *)(param_1[0xb] + 0xbc),iVar9 * 4);
  param_1[8] = iVar7;
  if (0 < iVar2) {
    iVar7 = 0;
    do {
      *(undefined4 *)(iVar7 * 4 + param_1[8]) = *(undefined4 *)(iVar3 + iVar7 * 4);
      iVar7 = iVar7 + 1;
    } while (iVar2 != iVar7);
  }
  FUN_001a7aba(*(undefined4 *)(param_1[0xb] + 0xbc),iVar3);
  uVar4 = *(undefined4 *)(param_1[0xb] + 0xbc);
  puVar5 = (undefined4 *)FUN_001a7bca(uVar4,0x28);
  *puVar5 = uVar4;
  puVar5 = puVar5 + 1;
  FUN_0013c746(puVar5,iVar2,0,param_1,param_1[0xb]);
  puVar1 = (uint *)param_1[1];
  uVar10 = puVar1[1];
  if (uVar10 < *puVar1) {
    _memset((void *)(puVar1[2] + uVar10 * 4),0,4);
    puVar1[1] = uVar10 + 1;
    *(undefined4 **)(puVar1[2] + uVar10 * 4) = puVar5;
    return;
  }
  puVar6 = (undefined4 *)FUN_001a7f7c(puVar1,uVar10);
  *puVar6 = puVar5;
  return;
}

/* FUN_0013f0d8 @ 0x13f0d8 (544 bytes) */
int FUN_0013f0d8(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int local_18;
  int local_14;
  
  local_14 = param_1[3];
  param_2 = local_14 + param_2;
  param_1[3] = param_2;
  iVar2 = *param_1;
  uVar3 = *(undefined4 *)(param_1[0xb] + 0xbc);
  iVar9 = (param_2 * param_2 - param_2) / 2;
  uVar7 = iVar9 + 0x1fU >> 5;
  puVar4 = (undefined4 *)FUN_001a7bca(uVar3,uVar7 * 4 + 0xc);
  *puVar4 = uVar3;
  puVar4[2] = iVar9;
  puVar4[1] = uVar7;
  if (uVar7 != 0) {
    uVar8 = 0;
    puVar5 = puVar4 + 1;
    do {
      puVar5[2] = 0;
      uVar8 = uVar8 + 1;
      puVar5 = puVar5 + 1;
    } while (uVar8 < uVar7);
  }
  *param_1 = (int)(puVar4 + 1);
  if (0 < local_14) {
    local_18 = 0;
    while (local_18 = local_18 + 1, local_14 != local_18) {
      if (0 < local_18) {
        iVar9 = 0;
        do {
          uVar7 = FUN_0013c1c8(param_1,iVar9,local_18);
          bVar6 = (byte)uVar7 & 0x1f;
          if ((*(uint *)(iVar2 + 8 + (uVar7 >> 5) * 4) >> bVar6 & 1) != 0) {
            puVar1 = (uint *)(*param_1 + 8 + (uVar7 >> 5) * 4);
            *puVar1 = *puVar1 | 1 << bVar6;
          }
          iVar9 = iVar9 + 1;
        } while (local_18 != iVar9);
      }
    }
  }
  iVar2 = param_1[8];
  iVar9 = FUN_001a7bca(*(undefined4 *)(param_1[0xb] + 0xbc),param_1[3] << 2);
  param_1[8] = iVar9;
  if (0 < local_14) {
    iVar9 = 0;
    do {
      *(undefined4 *)(iVar9 * 4 + param_1[8]) = *(undefined4 *)(iVar2 + iVar9 * 4);
      iVar9 = iVar9 + 1;
    } while (local_14 != iVar9);
  }
  FUN_001a7aba(*(undefined4 *)(param_1[0xb] + 0xbc),iVar2);
  if (local_14 < param_1[3]) {
    do {
      uVar3 = *(undefined4 *)(param_1[0xb] + 0xbc);
      puVar4 = (undefined4 *)FUN_001a7bca(uVar3,0x28);
      *puVar4 = uVar3;
      FUN_0013c746(puVar4 + 1,local_14,0,param_1,param_1[0xb]);
      puVar1 = (uint *)param_1[1];
      uVar7 = puVar1[1];
      if (uVar7 < *puVar1) {
        _memset((void *)(puVar1[2] + uVar7 * 4),0,4);
        puVar1[1] = uVar7 + 1;
        puVar5 = (undefined4 *)(puVar1[2] + uVar7 * 4);
      }
      else {
        puVar5 = (undefined4 *)FUN_001a7f7c(puVar1,uVar7);
      }
      *puVar5 = puVar4 + 1;
      local_14 = local_14 + 1;
    } while (local_14 < param_1[3]);
  }
  return;
}

/* FUN_0013f318 @ 0x13f318 (1357 bytes) */
int FUN_0013f318(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  int *local_28;
  int local_1c;
  int local_18;
  int *local_10;
  
  iVar1 = *(int *)(*(int *)(param_2 + 0x3f4) + 0x378);
  iVar2 = *(int *)(iVar1 + 8);
  do {
    if (iVar2 == 0) {
      return;
    }
    iVar2 = (*(int **)(iVar1 + 0xa0))[1];
    local_28 = *(int **)(iVar1 + 0xa0);
    while (iVar2 != 0) {
      while( true ) {
        if ((local_28 != *(int **)(iVar1 + 0x98)) &&
           (piVar7 = (int *)local_28[1], (*(byte *)(piVar7 + 5) & 4) != 0)) goto LAB_0013f3d1;
        iVar2 = *(int *)(iVar1 + 0xb8);
        if (local_28 != (int *)0x0) break;
        local_28 = (int *)MACH_HEADER.cputype;
        if (*(int *)(MACH_HEADER.cputype + 4) == 0) goto LAB_0013f3df;
      }
      piVar7 = local_28;
      do {
        uVar3 = piVar7[5];
        if ((uVar3 & 1) == 0) {
          piVar7 = (int *)piVar7[2];
        }
        else {
          iVar6 = (**(code **)(*piVar7 + 0x7c))(piVar7);
          if (iVar6 == 0) {
            if ((((piVar7[0x20] != 0) && (cVar5 = FUN_0012dfd8(piVar7[0x26]), cVar5 != '\0')) &&
                ((*(byte *)(piVar7 + 5) & 2) == 0)) &&
               (cVar5 = (**(code **)(*piVar7 + 0x50))(piVar7), cVar5 == '\0')) {
              uVar3 = piVar7[0x25];
              cVar5 = (**(code **)(*piVar7 + 0x40))(piVar7);
              if ((cVar5 == '\0') && (cVar5 = (**(code **)(*piVar7 + 0x28))(piVar7), cVar5 == '\0'))
              {
                piVar7[5] = piVar7[5] | 0x20000000;
                local_10 = piVar7;
                for (iVar6 = 1; iVar9 = (**(code **)(*piVar7 + 0x14))(piVar7), iVar6 <= iVar9;
                    iVar6 = iVar6 + 1) {
                  if ((iVar6 < 1) || (iVar9 = FUN_0010b180(piVar7,iVar6), iVar9 == 0)) {
                    iVar9 = local_10[0x2c];
                  }
                  else {
                    iVar9 = FUN_0010b180(piVar7,iVar6);
                    iVar9 = *(int *)(iVar9 + 0x98);
                  }
                  cVar5 = FUN_0012dff6(iVar9);
                  if (cVar5 == '\0') {
LAB_0013f81a:
                    uVar10 = piVar7[5] & 0xdfffffff;
                    piVar7[5] = uVar10;
                    goto LAB_0013f55c;
                  }
                  FUN_0010b0f4(piVar7,iVar6);
                  iVar9 = FUN_0010b7c8(piVar7,iVar6);
                  local_10 = local_10 + 6;
                  if (iVar9 != 0) goto LAB_0013f81a;
                }
                uVar10 = piVar7[5];
              }
              else {
                puVar4 = *(uint **)(param_1 + 4);
                if (uVar3 < *puVar4) {
                  uVar10 = puVar4[1];
                  if (uVar10 <= uVar3) {
                    _memset((void *)(puVar4[2] + uVar10 * 4),0,(uVar3 - uVar10) * 4 + 4);
                    puVar4[1] = uVar3 + 1;
                  }
                  piVar8 = (int *)(puVar4[2] + uVar3 * 4);
                }
                else {
                  piVar8 = (int *)FUN_001a7f7c(puVar4,uVar3);
                }
                *(undefined1 *)(*piVar8 + 0x20) = 0;
                uVar10 = piVar7[5];
              }
LAB_0013f55c:
              if ((uVar10 & 0x20000000) != 0) {
                puVar4 = *(uint **)(param_1 + 4);
                if (uVar3 < *puVar4) {
                  uVar10 = puVar4[1];
                  if (uVar10 <= uVar3) {
                    _memset((void *)(puVar4[2] + uVar10 * 4),0,(uVar3 - uVar10) * 4 + 4);
                    puVar4[1] = uVar3 + 1;
                  }
                  piVar8 = (int *)(puVar4[2] + uVar3 * 4);
                }
                else {
                  piVar8 = (int *)FUN_001a7f7c(puVar4,uVar3);
                }
                *(undefined1 *)(*piVar8 + 0x20) = 1;
              }
              puVar4 = *(uint **)(param_1 + 4);
              if (uVar3 < *puVar4) {
                uVar10 = puVar4[1];
                if (uVar10 <= uVar3) {
                  _memset((void *)(puVar4[2] + uVar10 * 4),0,(uVar3 - uVar10) * 4 + 4);
                  puVar4[1] = uVar3 + 1;
                }
                piVar8 = (int *)(puVar4[2] + uVar3 * 4);
              }
              else {
                piVar8 = (int *)FUN_001a7f7c(puVar4,uVar3);
              }
              if (*(char *)(*piVar8 + 0x18) == '\0') {
                if ((piVar7[5] & 0x20000000U) == 0) {
                  local_1c = 0x7fffffff;
                  if ((piVar7[5] & 0x40U) == 0) {
                    local_1c = iVar2 * 100;
                  }
                }
                else {
                  local_1c = 0;
                }
                puVar4 = *(uint **)(param_1 + 4);
                if (uVar3 < *puVar4) {
                  uVar10 = puVar4[1];
                  if (uVar10 <= uVar3) {
                    _memset((void *)(puVar4[2] + uVar10 * 4),0,(uVar3 - uVar10) * 4 + 4);
                    puVar4[1] = uVar3 + 1;
                  }
                  piVar8 = (int *)(puVar4[2] + uVar3 * 4);
                }
                else {
                  piVar8 = (int *)FUN_001a7f7c(puVar4,uVar3);
                }
                *(int *)(*piVar8 + 0x1c) = *(int *)(*piVar8 + 0x1c) + local_1c;
              }
            }
            local_18 = 1;
            while (iVar6 = (**(code **)(*piVar7 + 0x14))(piVar7), local_18 <= iVar6) {
              piVar8 = (int *)FUN_0010b180(piVar7,local_18);
              uVar3 = piVar8[0x25];
              if ((((piVar8[0x20] == 0) || (cVar5 = FUN_0012dfd8(piVar8[0x26]), cVar5 == '\0')) ||
                  ((*(byte *)(piVar8 + 5) & 2) != 0)) ||
                 (cVar5 = (**(code **)(*piVar8 + 0x50))(piVar8), cVar5 != '\0')) {
LAB_0013f440:
                local_18 = local_18 + 1;
              }
              else {
                puVar4 = *(uint **)(param_1 + 4);
                if (uVar3 < *puVar4) {
                  uVar10 = puVar4[1];
                  if (uVar10 <= uVar3) {
                    _memset((void *)(puVar4[2] + uVar10 * 4),0,(uVar3 - uVar10) * 4 + 4);
                    puVar4[1] = uVar3 + 1;
                  }
                  piVar8 = (int *)(puVar4[2] + uVar3 * 4);
                }
                else {
                  piVar8 = (int *)FUN_001a7f7c(puVar4,uVar3);
                }
                if (*(char *)(*piVar8 + 0x18) != '\0') goto LAB_0013f440;
                puVar4 = *(uint **)(param_1 + 4);
                if (uVar3 < *puVar4) {
                  uVar10 = puVar4[1];
                  if (uVar10 <= uVar3) {
                    _memset((void *)(puVar4[2] + uVar10 * 4),0,(uVar3 - uVar10) * 4 + 4);
                    puVar4[1] = uVar3 + 1;
                  }
                  piVar8 = (int *)(puVar4[2] + uVar3 * 4);
                }
                else {
                  piVar8 = (int *)FUN_001a7f7c(puVar4,uVar3);
                }
                *(int *)(*piVar8 + 0x1c) = *(int *)(*piVar8 + 0x1c) + iVar2;
                local_18 = local_18 + 1;
              }
            }
          }
          uVar3 = piVar7[5];
          piVar7 = (int *)piVar7[2];
        }
      } while ((piVar7 != (int *)0x0) && ((uVar3 & 4) != 0));
      piVar7 = (int *)local_28[1];
LAB_0013f3d1:
      local_28 = piVar7;
      iVar2 = piVar7[1];
    }
LAB_0013f3df:
    iVar1 = *(int *)(iVar1 + 8);
    iVar2 = *(int *)(iVar1 + 8);
  } while( true );
}

/* FUN_0013f866 @ 0x13f866 (34 bytes) */
int FUN_0013f866(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = param_2 * 4 + param_3;
  return *(uint *)(param_1 + 8 + (uVar1 >> 5) * 4) >> ((byte)uVar1 & 0x1f) & 1;
}

/* FUN_0013f888 @ 0x13f888 (78 bytes) */
int FUN_0013f888(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  uint param_3;
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_0010b180(param_1,param_2);
  uVar2 = param_3;
  while( true ) {
    if (uVar2 == 0) {
      return 0;
    }
    if (((*(byte *)(param_3 + 0x14) & 1) != 0) && (param_3 == uVar1)) break;
    param_3 = *(uint *)(param_3 + 4);
    uVar2 = *(uint *)(param_3 + 0x14) & 4;
    if (param_3 == 0) {
      return 0;
    }
  }
  return 1;
}

/* FUN_0013f8d6 @ 0x13f8d6 (306 bytes) */
int FUN_0013f8d6(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  byte bVar6;
  int local_14;
  int *local_10;
  
  iVar2 = param_2[0x21];
  if (0 < iVar2) {
    local_10 = param_2 + iVar2 * 6 + 0x23;
    local_14 = 0;
LAB_0013f952:
    do {
      iVar3 = *local_10;
      uVar4 = *(uint *)(iVar3 + 0x1c);
      if ((int)uVar4 < 0) {
        if (*(int *)(iVar3 + 4) == 0x2c) {
          *(undefined1 *)(param_1 + 0x3a8) = 1;
          *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) | 1;
          local_14 = local_14 + 1;
          local_10 = local_10 + -6;
          if (iVar2 == local_14) break;
          goto LAB_0013f952;
        }
      }
      else {
        bVar6 = (byte)uVar4 & 0x1f;
        if ((*(uint *)(param_3 + 8 + (uVar4 >> 5) * 4) >> bVar6 & 1) == 0) {
          puVar1 = (uint *)(*(int *)(param_1 + 0x3a4) + 8 + (uVar4 >> 5) * 4);
          *puVar1 = *puVar1 | 1 << bVar6;
          *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) | 1;
        }
      }
      local_14 = local_14 + 1;
      local_10 = local_10 + -6;
    } while (iVar2 != local_14);
  }
  if (((0 < param_2[0x20]) && ((*(byte *)(param_2 + 5) & 2) == 0)) &&
     (uVar4 = *(uint *)(param_2[0x23] + 0x1c), -1 < (int)uVar4)) {
    puVar1 = (uint *)(param_3 + 8 + (uVar4 >> 5) * 4);
    *puVar1 = *puVar1 | 1 << ((byte)uVar4 & 0x1f);
  }
  cVar5 = (**(code **)(*param_2 + 0x78))(param_2);
  if (cVar5 != '\0') {
    iVar2 = param_2[0x29];
    uVar4 = *(uint *)(iVar2 + 0x1c);
    if (-1 < (int)uVar4) {
      puVar1 = (uint *)(*(int *)(param_1 + 0x3a4) + 8 + (uVar4 >> 5) * 4);
      *puVar1 = *puVar1 | 1 << ((byte)uVar4 & 0x1f);
      puVar1 = (uint *)(iVar2 + 0x24);
      *puVar1 = *puVar1 | 1;
    }
  }
  return;
}

/* FUN_0013fa08 @ 0x13fa08 (187 bytes) */
int FUN_0013fa08(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = FUN_000ede1c(param_1);
  iVar4 = 1;
  while( true ) {
    iVar3 = FUN_001a7d8a(param_1 + 0x370);
    if (iVar3 < iVar4) break;
    iVar3 = *(int *)(iVar2 + iVar4 * 4);
    iVar1 = *(int *)(iVar3 + 0x104);
    if (iVar1 != 0) {
      FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
    }
    *(undefined4 *)(iVar3 + 0x104) = 0;
    iVar1 = *(int *)(iVar3 + 0xfc);
    if (iVar1 != 0) {
      FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
    }
    *(undefined4 *)(iVar3 + 0xfc) = 0;
    iVar1 = *(int *)(iVar3 + 0x100);
    if (iVar1 != 0) {
      FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
    }
    *(undefined4 *)(iVar3 + 0x100) = 0;
    iVar4 = iVar4 + 1;
  }
  return;
}

/* FUN_0013fac4 @ 0x13fac4 (212 bytes) */
int FUN_0013fac4(param_1)
  int param_1;
{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar5 = (undefined4 *)FUN_001a7bca(uVar2,0x20c);
  puVar1 = puVar5 + 1;
  *puVar5 = uVar2;
  puVar5[2] = 0x1000;
  puVar5[1] = 0x80;
  uVar7 = 0;
  puVar6 = puVar1;
  do {
    puVar6[2] = 0;
    uVar7 = uVar7 + 1;
    puVar6 = puVar6 + 1;
  } while (uVar7 < 0x80);
  iVar3 = *(int *)(param_1 + 0x378);
  iVar4 = *(int *)(iVar3 + 8);
  do {
    if (iVar4 == 0) {
      return;
    }
    if (*puVar1 != 0) {
      uVar7 = 0;
      puVar6 = puVar1;
      do {
        puVar6[2] = 0;
        uVar7 = uVar7 + 1;
        puVar6 = puVar6 + 1;
      } while (uVar7 < *puVar1);
    }
    iVar8 = *(int *)(iVar3 + 0x98);
    iVar4 = *(int *)(iVar8 + 8);
    while (iVar4 != 0) {
      while ((*(byte *)(iVar8 + 0x14) & 1) != 0) {
        ((int (*)())FUN_0013f8d6)(param_1,iVar8,puVar1);
        iVar8 = *(int *)(iVar8 + 8);
        if (*(int *)(iVar8 + 8) == 0) goto LAB_0013fb81;
      }
      iVar8 = *(int *)(iVar8 + 8);
      iVar4 = *(int *)(iVar8 + 8);
    }
LAB_0013fb81:
    iVar3 = *(int *)(iVar3 + 8);
    iVar4 = *(int *)(iVar3 + 8);
  } while( true );
}

/* FUN_0013fb98 @ 0x13fb98 (88 bytes) */
int FUN_0013fb98(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  while( true ) {
    iVar1 = FUN_0010b0f4(param_1,0);
    if (*(char *)(param_2 + 0x10 + iVar1) == '\0') {
      return 1;
    }
    if ((*(byte *)(param_1 + 0x15) & 2) == 0) break;
    param_1 = FUN_0010b180(param_1,*(undefined4 *)(param_1 + 0x84));
    if (param_1 == 0) {
      return 0;
    }
  }
  return 0;
}

/* FUN_0013fbf0 @ 0x13fbf0 (157 bytes) */
int FUN_0013fbf0(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  uint uVar1;
  char cVar2;
  int iVar3;
  
  *param_3 = param_2;
LAB_0013fc03:
  do {
    uVar1 = *param_3;
    iVar3 = FUN_0010b0f4(param_1,0);
    if (*(char *)(uVar1 + 0x10 + iVar3) == '\0') {
      if ((*(byte *)(param_1 + 5) & 1) != 0) {
        return param_1;
      }
      cVar2 = (**(code **)(*param_1 + 100))(param_1);
      if (cVar2 == '\0') goto LAB_0013fc03;
      uVar1 = *param_3;
      iVar3 = FUN_0010b0f4(param_1,1);
      *param_3 = (uint)*(byte *)(uVar1 + 0x10 + iVar3);
      param_1 = (int *)FUN_0010b180(param_1,1);
    }
    else {
      if ((*(byte *)((int)param_1 + 0x15) & 2) == 0) {
        return (int *)0x0;
      }
      param_1 = (int *)FUN_0010b180(param_1,param_1[0x21]);
    }
    if (param_1 == (int *)0x0) {
      return (int *)0x0;
    }
  } while( true );
}

/* FUN_0013fc8e @ 0x13fc8e (715 bytes) */
int FUN_0013fc8e(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint *puVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int local_60;
  int *local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_10;
  
  piVar3 = *(int **)(*(int *)(param_1 + 0x124) + 0x98);
  piVar6 = piVar3;
  local_2c = piVar3;
  if (piVar3[2] == 0) {
    return;
  }
joined_r0x0013fcb8:
  do {
    if (piVar6 != (int *)0x0) {
      uVar8 = piVar3[5];
      if ((uVar8 & 1) == 0) {
        piVar3 = (int *)piVar3[2];
      }
      else {
        local_28 = 1;
        iVar5 = (**(code **)(*piVar3 + 0x14))(piVar3);
        if (0 < iVar5) {
          do {
            piVar6 = (int *)FUN_0010b180(piVar3,local_28);
            if ((((piVar6[0x20] != 0) && (cVar4 = FUN_0012dfd8(piVar6[0x26]), cVar4 != '\0')) &&
                ((*(byte *)(piVar6 + 5) & 2) == 0)) &&
               (cVar4 = (**(code **)(*piVar6 + 0x50))(piVar6), cVar4 == '\0')) {
              iVar5 = FUN_0010b0f4(piVar3,local_28);
              local_10 = FUN_000f5bdc(*(undefined4 *)(iVar5 + 0x10));
              local_60 = 0;
              do {
                if (*(char *)((int)&local_10 + local_60) != '\0') {
                  uVar8 = local_60 + piVar6[0x25] * 4;
                  puVar2 = (uint *)(param_2 + 8 + (uVar8 >> 5) * 4);
                  *puVar2 = *puVar2 | 1 << ((byte)uVar8 & 0x1f);
                }
                local_60 = local_60 + 1;
              } while (local_60 != 4);
            }
            local_28 = local_28 + 1;
            iVar5 = (**(code **)(*piVar3 + 0x14))(piVar3);
          } while (local_28 <= iVar5);
        }
        if (((piVar3[0x20] != 0) && (cVar4 = FUN_0012dfd8(piVar3[0x26]), cVar4 != '\0')) &&
           (((*(byte *)(piVar3 + 5) & 2) == 0 &&
            (cVar4 = (**(code **)(*piVar3 + 0x50))(piVar3), cVar4 == '\0')))) {
          iVar5 = 0;
          do {
            iVar7 = FUN_0010b0f4(piVar3,0);
            if (*(char *)(iVar5 + 0x10 + iVar7) != '\x01') {
              uVar8 = iVar5 + piVar3[0x25] * 4;
              puVar2 = (uint *)(param_2 + 8 + (uVar8 >> 5) * 4);
              *puVar2 = *puVar2 | 1 << ((byte)uVar8 & 0x1f);
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 != 4);
        }
        uVar8 = 1;
        local_20 = 0;
        iVar7 = *(int *)(param_1 + 0x124);
        iVar5 = *(int *)(iVar7 + 0x124);
        if (*(int *)(iVar5 + 4) != 0) {
          do {
            piVar6 = *(int **)(local_20 + *(int *)(iVar5 + 8));
            if ((*(byte *)(piVar6 + 5) & 1) != 0) {
              cVar4 = (**(code **)(*piVar6 + 0x60))(piVar6);
              if (cVar4 == '\0') {
                local_24 = 0;
                do {
                  iVar5 = FUN_0010b0f4(piVar3,0);
                  if (*(char *)(local_24 + 0x10 + iVar5) != '\x01') {
                    uVar1 = local_24 + piVar6[0x25] * 4;
                    puVar2 = (uint *)(param_2 + 8 + (uVar1 >> 5) * 4);
                    *puVar2 = *puVar2 | 1 << ((byte)uVar1 & 0x1f);
                  }
                  local_24 = local_24 + 1;
                } while (local_24 != 4);
                iVar7 = *(int *)(param_1 + 0x124);
              }
              else {
                iVar7 = *(int *)(param_1 + 0x124);
              }
            }
            uVar8 = uVar8 + 1;
            local_20 = local_20 + 4;
            iVar5 = *(int *)(iVar7 + 0x124);
          } while (uVar8 <= *(uint *)(iVar5 + 4));
        }
        uVar8 = piVar3[5];
        piVar3 = (int *)piVar3[2];
      }
      if (piVar3 != (int *)0x0) {
        piVar6 = (int *)(uVar8 & 4);
        goto joined_r0x0013fcb8;
      }
    }
    uVar8 = local_2c[5];
    piVar3 = (int *)local_2c[2];
    iVar5 = piVar3[2];
    while( true ) {
      if (iVar5 == 0) {
        return;
      }
      piVar6 = piVar3;
      local_2c = piVar3;
      if ((uVar8 & 4) == 0) break;
      uVar8 = piVar3[5];
      piVar3 = (int *)piVar3[2];
      iVar5 = piVar3[2];
    }
  } while( true );
}

/* FUN_0013ff5a @ 0x13ff5a (2179 bytes) */
int FUN_0013ff5a(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int *piVar1;
  undefined4 uVar2;
  bool bVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  uint *puVar12;
  int *piVar13;
  int *piVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint *puVar18;
  int local_74;
  int *local_6c;
  int local_58;
  int local_50;
  int local_44;
  int local_40;
  int local_3c;
  uint local_30;
  uint local_2c;
  int local_28;
  uint local_24;
  undefined4 local_10;
  
  *(uint *)(param_3 + 0x30) = *(uint *)(param_3 + 0x30) | 0x1000;
  iVar6 = FUN_000edd54(param_3);
  param_2 = param_2 * 4;
  uVar16 = param_2 + 0x1fU >> 5;
  iVar11 = uVar16 * 4 + 0xc;
  local_74 = 1;
  iVar7 = param_3 + 0x370;
  iVar8 = FUN_001a7d8a(iVar7);
  if (0 < iVar8) {
    do {
      piVar1 = *(int **)(iVar6 + local_74 * 4);
      uVar2 = *(undefined4 *)(param_4 + 0xbc);
      puVar9 = (undefined4 *)FUN_001a7bca(uVar2,iVar11);
      *puVar9 = uVar2;
      puVar9[2] = param_2;
      puVar9[1] = uVar16;
      if (uVar16 != 0) {
        uVar17 = 0;
        puVar10 = puVar9 + 1;
        do {
          puVar10[2] = 0;
          uVar17 = uVar17 + 1;
          puVar10 = puVar10 + 1;
        } while (uVar17 < uVar16);
      }
      piVar1[0x40] = (int)(puVar9 + 1);
      uVar2 = *(undefined4 *)(param_4 + 0xbc);
      puVar9 = (undefined4 *)FUN_001a7bca(uVar2,iVar11);
      *puVar9 = uVar2;
      puVar9[2] = param_2;
      puVar9[1] = uVar16;
      if (uVar16 != 0) {
        uVar17 = 0;
        puVar10 = puVar9 + 1;
        do {
          puVar10[2] = 0;
          uVar17 = uVar17 + 1;
          puVar10 = puVar10 + 1;
        } while (uVar17 < uVar16);
      }
      piVar1[0x3f] = (int)(puVar9 + 1);
      uVar2 = *(undefined4 *)(param_4 + 0xbc);
      puVar9 = (undefined4 *)FUN_001a7bca(uVar2,iVar11);
      *puVar9 = uVar2;
      puVar9[2] = param_2;
      puVar9[1] = uVar16;
      if (uVar16 != 0) {
        uVar17 = 0;
        puVar10 = puVar9 + 1;
        do {
          puVar10[2] = 0;
          uVar17 = uVar17 + 1;
          puVar10 = puVar10 + 1;
        } while (uVar17 < uVar16);
      }
      piVar1[0x41] = (int)(puVar9 + 1);
      local_6c = (int *)piVar1[0x26];
      if (local_6c[2] != 0) {
        do {
          iVar8 = (**(code **)(*local_6c + 0x7c))(local_6c);
          piVar13 = local_6c;
          if (iVar8 == 0) {
            do {
              uVar17 = piVar13[5];
              if (((uVar17 & 1) != 0) && (*(int *)(piVar13[0x22] + 8) != 0x8e)) {
                cVar4 = (**(code **)(*piVar13 + 0x34))(piVar13);
                if ((cVar4 == '\0') &&
                   (((cVar4 = (**(code **)(*piVar13 + 0x38))(piVar13), cVar4 == '\0' &&
                     (cVar4 = (**(code **)(*piVar13 + 0x60))(piVar13), cVar4 == '\0')) &&
                    (cVar4 = (**(code **)(*piVar13 + 0x5c))(piVar13), cVar4 == '\0')))) {
                  iVar8 = piVar13[0x21];
                  uVar17 = piVar13[5];
                  if ((uVar17 & 0x200) != 0) {
                    iVar8 = iVar8 + -1;
                  }
                  if (0 < iVar8) {
                    local_58 = 1;
                    do {
                      piVar14 = (int *)FUN_0010b180(piVar13,local_58);
                      if (((piVar14[0x20] != 0) &&
                          (cVar4 = FUN_0012dfd8(piVar14[0x26]), cVar4 != '\0')) &&
                         (((*(byte *)(piVar14 + 5) & 2) == 0 &&
                          ((cVar4 = (**(code **)(*piVar14 + 0x50))(piVar14), cVar4 == '\0' &&
                           (cVar4 = ((int (*)())FUN_0013f888)(piVar13,local_58,piVar13), cVar4 == '\0')))))) {
                        iVar15 = FUN_0010b0f4(piVar13,local_58);
                        local_10 = FUN_000f5bdc(*(undefined4 *)(iVar15 + 0x10));
                        iVar15 = piVar14[0x25];
                        uVar17 = iVar15 << 2;
                        local_50 = 0;
                        do {
                          if ((*(char *)((int)&local_10 + local_50) != '\0') &&
                             (cVar4 = ((int (*)())FUN_0013f866)(piVar1[0x41],iVar15,local_50), cVar4 == '\0')) {
                            puVar12 = (uint *)(piVar1[0x3f] + 8 + (uVar17 >> 5) * 4);
                            *puVar12 = *puVar12 | 1 << ((byte)uVar17 & 0x1f);
                          }
                          local_50 = local_50 + 1;
                          uVar17 = uVar17 + 1;
                        } while (local_50 != 4);
                      }
                      local_58 = local_58 + 1;
                    } while (local_58 <= iVar8);
                    uVar17 = piVar13[5];
                  }
                  if ((uVar17 & 0x200) == 0) goto LAB_001402d6;
                  piVar14 = (int *)FUN_0010b180(piVar13,piVar13[0x21]);
                  if ((((piVar14[0x20] != 0) && (cVar4 = FUN_0012dfd8(piVar14[0x26]), cVar4 != '\0')
                       ) && ((*(byte *)(piVar14 + 5) & 2) == 0)) &&
                     (cVar4 = (**(code **)(*piVar14 + 0x50))(piVar14), cVar4 == '\0')) {
                    iVar8 = piVar14[0x25];
                    cVar4 = ((int (*)())FUN_0013f888)(piVar13,piVar13[0x21],piVar13);
                    if (cVar4 == '\0') {
                      local_24 = iVar8 << 2;
                      local_44 = 0;
                      do {
                        iVar15 = FUN_0010b0f4(piVar13,0);
                        if (((*(char *)(local_44 + 0x10 + iVar15) == '\x01') &&
                            (cVar4 = ((int (*)())FUN_0013f866)(piVar1[0x41],iVar8,local_44), cVar4 == '\0')) &&
                           (cVar4 = ((int (*)())FUN_0013fb98)(piVar14,local_44), cVar4 != '\0')) {
                          puVar12 = (uint *)(piVar1[0x3f] + 8 + (local_24 >> 5) * 4);
                          *puVar12 = *puVar12 | 1 << ((byte)local_24 & 0x1f);
                        }
                        local_44 = local_44 + 1;
                        local_24 = local_24 + 1;
                      } while (local_44 != 4);
                    }
                  }
                }
                uVar17 = piVar13[5];
              }
LAB_001402d6:
              piVar14 = local_6c;
            } while (((int *)piVar13[2] != (int *)0x0) &&
                    (piVar13 = (int *)piVar13[2], (uVar17 & 4) != 0));
            do {
              uVar17 = piVar14[5];
              if (((uVar17 & 1) != 0) && (*(int *)(piVar14[0x22] + 8) != 0x8e)) {
                cVar4 = (**(code **)(*piVar14 + 0x34))(piVar14);
                if ((((cVar4 == '\0') &&
                     (cVar4 = (**(code **)(*piVar14 + 0x38))(piVar14), cVar4 == '\0')) &&
                    (cVar4 = (**(code **)(*piVar14 + 0x60))(piVar14), cVar4 == '\0')) &&
                   (cVar4 = (**(code **)(*piVar14 + 0x5c))(piVar14), cVar4 == '\0')) {
                  if ((piVar14[0x20] == 0) || (cVar4 = FUN_0012dfd8(piVar14[0x26]), cVar4 == '\0'))
                  {
LAB_0014035a:
                    uVar17 = piVar14[5];
                  }
                  else {
                    uVar17 = piVar14[5];
                    if ((uVar17 & 2) == 0) {
                      cVar4 = (**(code **)(*piVar14 + 0x50))(piVar14);
                      if (cVar4 == '\0') {
                        iVar8 = 0;
                        do {
                          iVar15 = FUN_0010b0f4(piVar14,0);
                          if (*(char *)(iVar8 + 0x10 + iVar15) != '\x01') {
                            uVar17 = iVar8 + piVar14[0x25] * 4;
                            puVar12 = (uint *)(piVar1[0x41] + 8 + (uVar17 >> 5) * 4);
                            *puVar12 = *puVar12 | 1 << ((byte)uVar17 & 0x1f);
                          }
                          iVar8 = iVar8 + 1;
                        } while (iVar8 != 4);
                      }
                      goto LAB_0014035a;
                    }
                  }
                  if ((uVar17 & 0x200) == 0) goto LAB_0014030f;
                  piVar13 = (int *)FUN_0010b180(piVar14,piVar14[0x21]);
                  if (((piVar13[0x20] != 0) && (cVar4 = FUN_0012dfd8(piVar13[0x26]), cVar4 != '\0'))
                     && (((*(byte *)(piVar13 + 5) & 2) == 0 &&
                         (cVar4 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar4 == '\0')))) {
                    local_40 = 0;
                    do {
                      iVar8 = FUN_0010b0f4(piVar14,0);
                      if ((*(char *)(local_40 + 0x10 + iVar8) == '\x01') &&
                         (cVar4 = ((int (*)())FUN_0013fb98)(piVar13,local_40), cVar4 != '\0')) {
                        uVar17 = local_40 + piVar14[0x25] * 4;
                        puVar12 = (uint *)(piVar1[0x41] + 8 + (uVar17 >> 5) * 4);
                        *puVar12 = *puVar12 | 1 << ((byte)uVar17 & 0x1f);
                      }
                      local_40 = local_40 + 1;
                    } while (local_40 != 4);
                  }
                }
                uVar17 = piVar14[5];
              }
LAB_0014030f: ;
            } while (((int *)piVar14[2] != (int *)0x0) &&
                    (piVar14 = (int *)piVar14[2], (uVar17 & 4) != 0));
          }
          uVar17 = local_6c[5];
          local_6c = (int *)local_6c[2];
          iVar8 = local_6c[2];
          while( true ) {
            if (iVar8 == 0) goto LAB_00140105;
            if ((uVar17 & 4) == 0) break;
            uVar17 = local_6c[5];
            local_6c = (int *)local_6c[2];
            iVar8 = local_6c[2];
          }
        } while( true );
      }
LAB_00140105:
      cVar4 = (**(code **)(*piVar1 + 0x18))(piVar1);
      if (cVar4 != '\0') {
        ((int (*)())FUN_0013fc8e)(piVar1,piVar1[0x3f]);
      }
      local_74 = local_74 + 1;
      iVar8 = FUN_001a7d8a(iVar7);
    } while (local_74 <= iVar8);
  }
  iVar11 = FUN_000ede1c(param_3);
  do {
    bVar3 = false;
    local_3c = 1;
    iVar6 = FUN_001a7d8a(iVar7);
    if (0 < iVar6) {
      do {
        piVar1 = *(int **)(iVar11 + local_3c * 4);
        cVar4 = (**(code **)(*piVar1 + 0x20))(piVar1);
        if (cVar4 == '\0') {
          puVar12 = (uint *)piVar1[0x40];
          if (*puVar12 != 0) {
            uVar17 = 0;
            uVar16 = *puVar12;
            do {
              puVar12[2] = 0;
              uVar17 = uVar17 + 1;
              puVar12 = puVar12 + 1;
            } while (uVar17 < uVar16);
          }
          bVar5 = true;
          local_2c = 1;
          local_28 = 0;
          iVar6 = piVar1[0x34];
          if (*(int *)(iVar6 + 4) != 0) {
            do {
              iVar6 = *(int *)(*(int *)(iVar6 + 8) + local_28);
              if (iVar6 != 0) {
                if (bVar5) {
                  puVar12 = (uint *)piVar1[0x40];
                  iVar6 = *(int *)(iVar6 + 0xfc);
                  if (*puVar12 != 0) {
                    uVar16 = 0;
                    puVar18 = puVar12;
                    do {
                      puVar18[2] = *(uint *)(iVar6 + 8);
                      uVar16 = uVar16 + 1;
                      iVar6 = iVar6 + 4;
                      puVar18 = puVar18 + 1;
                    } while (uVar16 < *puVar12);
                  }
                }
                else {
                  puVar12 = (uint *)piVar1[0x40];
                  iVar6 = *(int *)(iVar6 + 0xfc);
                  if (*puVar12 != 0) {
                    uVar17 = 0;
                    uVar16 = *puVar12;
                    do {
                      puVar12[2] = puVar12[2] | *(uint *)(iVar6 + 8);
                      uVar17 = uVar17 + 1;
                      puVar12 = puVar12 + 1;
                      iVar6 = iVar6 + 4;
                    } while (uVar17 < uVar16);
                  }
                }
                bVar5 = false;
              }
              local_2c = local_2c + 1;
              local_28 = local_28 + 4;
              iVar6 = piVar1[0x34];
            } while (local_2c <= *(uint *)(iVar6 + 4));
          }
          iVar6 = piVar1[0x3f];
          puVar12 = (uint *)piVar1[0x40];
          iVar8 = piVar1[0x41];
          if (*puVar12 == 0) {
            bVar5 = false;
          }
          else {
            local_30 = 0;
            bVar5 = false;
            puVar18 = puVar12;
            do {
              uVar16 = ~*(uint *)(iVar8 + 8) & puVar18[2] | *(uint *)(iVar6 + 8);
              if (*(uint *)(iVar6 + 8) != uVar16) {
                *(uint *)(iVar6 + 8) = uVar16;
                bVar5 = true;
              }
              local_30 = local_30 + 1;
              puVar18 = puVar18 + 1;
              iVar8 = iVar8 + 4;
              iVar6 = iVar6 + 4;
            } while (local_30 < *puVar12);
          }
          bVar3 = bVar5 || bVar3;
        }
        local_3c = local_3c + 1;
        iVar6 = FUN_001a7d8a(iVar7);
      } while (local_3c <= iVar6);
    }
  } while (bVar3);
  return;
}

/* FUN_001407e0 @ 0x1407e0 (53 bytes) */
int FUN_001407e0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 8) + 0x54);
  (**(code **)(*piVar1 + 0x6c))(piVar1,param_1,param_4);
  FUN_0015349e();
  return;
}

/* FUN_00140816 @ 0x140816 (33 bytes) */
int FUN_00140816(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    iVar2 = iVar2 + (param_1 >> ((byte)iVar1 & 0x1f) & 1U);
    iVar1 = iVar1 + 1;
  } while (iVar1 != 4);
  return iVar2;
}

/* FUN_00140838 @ 0x140838 (50 bytes) */
int FUN_00140838(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  if (((*(int *)(param_1 + 0x158) != param_3) && (*(int *)(param_1 + 0x158) != param_4)) &&
     (*(int *)(param_1 + 0x158) != param_2)) {
    return 1;
  }
  return 0;
}

/* FUN_0014086a @ 0x14086a (189 bytes) */
int FUN_0014086a(param_1, param_2)
  int *param_1;
  int *param_2;
{
  char cVar1;
  int *piVar2;
  int *local_10;
  
  (**(code **)(*param_2 + 0x14))(param_2);
  local_10 = (int *)FUN_0010b180(param_2,1);
  while (cVar1 = (**(code **)(*local_10 + 0x60))(local_10), cVar1 != '\0') {
    local_10 = (int *)FUN_0010b180(local_10,1);
  }
  piVar2 = (int *)FUN_0010b180(param_2,2);
  while (cVar1 = (**(code **)(*piVar2 + 0x60))(piVar2), cVar1 != '\0') {
    piVar2 = (int *)FUN_0010b180(piVar2,1);
  }
  while( true ) {
    do {
      param_2 = (int *)param_2[1];
      cVar1 = (**(code **)(*param_2 + 0x60))(param_2);
    } while (cVar1 != '\0');
    if (param_1 == param_2) {
      return 1;
    }
    if (param_2 == local_10) {
      return 0;
    }
    if (param_2 == piVar2) break;
    cVar1 = (**(code **)(*param_2 + 0x34))(param_2);
    if (cVar1 != '\0') {
      return 0;
    }
  }
  return 0;
}

/* FUN_00140928 @ 0x140928 (136 bytes) */
int FUN_00140928(param_1, param_2)
  int param_1;
  dword param_2;
{
  uint uVar1;
  dword dVar2;
  int iVar3;
  undefined4 local_10;
  
  uVar1 = *(int *)(param_1 + 4) - 1;
  if (uVar1 < *(uint *)(param_1 + 4)) {
    dVar2 = *(dword *)(*(int *)(param_1 + 8) + uVar1 * 4);
    local_10 = dVar2;
    (*(unsigned char *)((unsigned char *)&(local_10) + 3)) = (char)(dVar2 >> 0x18);
  }
  else {
    local_10 = MACH_HEADER.magic;
    (*(unsigned char *)((unsigned char *)&(local_10) + 3)) = (char)(MACH_HEADER.magic >> 0x18);
    dVar2 = MACH_HEADER.magic;
  }
  if ((*(unsigned char *)((unsigned char *)&(local_10) + 3)) != '\0') {
    if ((int)param_2 < 5) {
      if ((int)param_2 < 1) {
        return true;
      }
    }
    else {
      param_2 = 4;
    }
    dVar2 = 0;
    iVar3 = 0;
    do {
      if (*(char *)((int)&local_10 + dVar2) != -1) {
        iVar3 = iVar3 + 1;
      }
      dVar2 = dVar2 + 1;
    } while (param_2 != dVar2);
    return iVar3 < 2;
  }
  return dVar2 == param_2;
}

/* FUN_001409b0 @ 0x1409b0 (71 bytes) */
int FUN_001409b0(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_8;
  
  uVar3 = *(int *)(param_1 + 4) - 1;
  if (uVar3 < *(uint *)(param_1 + 4)) {
    piVar1 = (int *)(*(int *)(param_1 + 8) + uVar3 * 4);
  }
  else {
    piVar1 = (int *)0x0;
  }
  iVar2 = *piVar1;
  local_8 = iVar2;
  (*(unsigned char *)((unsigned char *)&(local_8) + 3)) = (char)((uint)iVar2 >> 0x18);
  if ((*(unsigned char *)((unsigned char *)&(local_8) + 3)) != '\0') {
    iVar2 = 0;
    do {
      if (*(char *)((int)&local_8 + iVar2) != -1) {
        return (int)*(char *)((int)&local_8 + iVar2);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 4);
    iVar2 = 0;
  }
  return iVar2;
}

/* FUN_001409f8 @ 0x1409f8 (125 bytes) */
int FUN_001409f8(param_1, param_2)
  int *param_1;
  int *param_2;
{
  char cVar1;
  int iVar2;
  
  if (param_1[0x2e] == 0) {
    while (param_1 = (int *)param_1[0x3b], param_1 != param_2) {
      while( true ) {
        if (param_1[0x2e] != 0) {
          return 0;
        }
        cVar1 = (**(code **)(*param_1 + 0x28))(param_1);
        if (cVar1 == '\0') break;
        iVar2 = FUN_000eac0c(param_1[0x49],0);
        param_1 = *(int **)(iVar2 + 0xec);
        if (param_1 == param_2) {
          return 0;
        }
      }
      cVar1 = (**(code **)(*param_1 + 0x24))(param_1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_00140a76 @ 0x140a76 (44 bytes) */
int FUN_00140a76(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x13) &&
     (*(int *)(*(int *)(param_2 + 0x88) + 8) != 0x12)) {
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x20000;
    return;
  }
  return;
}

/* FUN_00140aa2 @ 0x140aa2 (47 bytes) */
int FUN_00140aa2(param_1)
  int param_1;
{
  switch(*(undefined4 *)(*(int *)(param_1 + 0x88) + 8)) {
  case 0x69:
  case 0x6b:
  case 0x75:
  case 0x76:
  case 0x9e:
  case 0x9f:
  case 0xa0:
  case 0xa1:
  case 0xaf:
    return 1;
  default:
    return 0;
  }
}

/* FUN_00140bf8 @ 0x140bf8 (382 bytes) */
int FUN_00140bf8(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int *piVar5;
  int *local_1c;
  int *local_18;
  
  piVar1 = *(int **)(param_1 + 0x394);
  local_18 = *(int **)(param_1 + 0x378);
  if (local_18[2] != 0) {
    local_1c = (int *)0x0;
    do {
      iVar2 = local_18[0x26];
      for (iVar3 = *(int *)(local_18[0x26] + 8); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
        cVar4 = ((int (*)())FUN_00140aa2)(iVar2);
        if (cVar4 != '\0') {
          piVar5 = (int *)FUN_0010b180(iVar2,1);
          cVar4 = (**(code **)(*piVar5 + 0x4c))(piVar5);
          piVar5 = local_18;
          if (cVar4 != '\0') {
joined_r0x00140c80:
            do {
              if (piVar5 == piVar1) break;
              cVar4 = (**(code **)(*piVar5 + 0x24))(piVar5);
              if (cVar4 != '\0') {
                if (local_1c == (int *)0x0) {
                  FUN_000e977a(piVar1);
                  local_1c = (int *)FUN_000eac7c(piVar1,0);
                  cVar4 = (**(code **)(*local_1c + 0x24))(local_1c);
                  if (cVar4 == '\0') {
                    (**(code **)(*local_1c + 0x2c))(local_1c);
                  }
                }
                FUN_00109e26(iVar2);
                *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 1;
                FUN_000e9512(local_1c,iVar2);
                break;
              }
              cVar4 = (**(code **)(*piVar5 + 0x28))(piVar5);
              if (cVar4 == '\0') {
                cVar4 = (**(code **)(*piVar5 + 0x2c))(piVar5);
                if (cVar4 != '\0') {
                  piVar5 = (int *)FUN_000e9b0e(piVar5);
                  goto joined_r0x00140c80;
                }
                cVar4 = (**(code **)(*piVar5 + 0x34))(piVar5);
                if (cVar4 != '\0') {
                  piVar5 = (int *)FUN_000e9b0e(piVar5[0x49]);
                }
              }
              else {
                piVar5 = (int *)FUN_000eac0c(piVar5[0x49],0);
              }
              piVar5 = (int *)piVar5[0x3b];
            } while( true );
          }
        }
        iVar2 = iVar3;
      }
      local_18 = (int *)local_18[2];
    } while (local_18[2] != 0);
  }
  return;
}

/* FUN_00140d76 @ 0x140d76 (293 bytes) */
int FUN_00140d76(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  int param_3;
  int param_4;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint local_20;
  
  cVar1 = (**(code **)(*param_2 + 0x5c))(param_2);
  if (cVar1 == '\0') {
    iVar4 = param_2[3];
    iVar2 = FUN_0010b0f4(param_2,0);
    uVar3 = FUN_000f5a44(*(undefined4 *)(iVar2 + 0x10),iVar4);
    local_20 = DAT_001cc558;
    iVar4 = (**(code **)(*param_2 + 0x14))(param_2);
    if (param_3 <= iVar4) {
      local_20 = FUN_000f626e(param_2,param_3,param_4,uVar3);
    }
    uVar3 = FUN_000f5a44(DAT_001cc540,local_20);
    iVar4 = FUN_0010b180(param_2,param_3);
    if ((iVar4 != 0) && ((*(int *)(iVar4 + 0x98) == 2 || (*(int *)(iVar4 + 0x98) == 0xc)))) {
      cVar1 = (**(code **)(**(int **)(param_1 + 0x54) + 0xec))
                        (*(int **)(param_1 + 0x54),param_2,param_3,uVar3,
                         *(undefined4 *)(param_4 + 8));
      if (cVar1 != '\0') {
        iVar2 = FUN_0010b180(param_2,param_3);
        if (iVar4 != iVar2) {
          *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | local_20;
        }
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_00140e9c @ 0x140e9c (97 bytes) */
undefined4 FUN_00140e9c(undefined4 param_1,undefined4 param_2,float param_3)

{
  char cVar1;
  int iVar2;
  int local_24;
  float local_20;
  
  iVar2 = FUN_0010b0f4(param_1,0);
  cVar1 = FUN_000f7e7e(param_1,param_2,*(undefined4 *)(iVar2 + 0x10),&local_24);
  if ((((cVar1 != '\0') && (param_3 == local_20)) && (!NAN(param_3) && !NAN(local_20))) &&
     (local_24 == 2)) {
    return 1;
  }
  return 0;
}

/* FUN_00140efe @ 0x140efe (1168 bytes) */
int FUN_00140efe(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 local_2c;
  undefined4 local_28;
  
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) != 0x29) {
    return 0;
  }
  cVar1 = ((undefined4 (*)())FUN_00140e9c)(param_1,1,0);
  if (cVar1 == '\0') {
    return 0;
  }
  iVar2 = FUN_0010b180(param_1,2);
  iVar3 = *(int *)(iVar2 + 0x88);
  if ((*(int *)(iVar3 + 8) == 0x24) && ((*(byte *)(iVar2 + 0x15) & 2) == 0)) {
    cVar1 = ((undefined4 (*)())FUN_00140e9c)(iVar2,2,0);
    if (cVar1 == '\0') {
LAB_00141222:
      iVar3 = *(int *)(iVar2 + 0x88);
      goto LAB_00140f5f;
    }
    cVar1 = ((undefined4 (*)())FUN_00140e9c)(iVar2,3,0x3f800000);
    if (cVar1 == '\0') {
LAB_00141326:
      iVar3 = *(int *)(iVar2 + 0x88);
      goto LAB_00140f5f;
    }
    if ((*(uint *)(iVar2 + 0xb8) & 1) != 0) goto LAB_00141222;
    if ((*(uint *)(iVar2 + 0xb8) & 2) != 0) goto LAB_00141326;
  }
  else {
LAB_00140f5f:
    if ((*(int *)(iVar3 + 8) == 0x28) && ((*(byte *)(iVar2 + 0x15) & 2) == 0)) {
      cVar1 = ((undefined4 (*)())FUN_00140e9c)(iVar2,2,0);
      if (cVar1 != '\0') {
        if ((*(uint *)(iVar2 + 0xb8) & 1) != 0) {
          iVar3 = *(int *)(iVar2 + 0x88);
          goto LAB_00140f69;
        }
        if ((*(uint *)(iVar2 + 0xb8) & 2) != 0) {
          local_2c = 1;
          local_28 = 0x27;
          goto LAB_00140fec;
        }
      }
      iVar3 = *(int *)(iVar2 + 0x88);
    }
LAB_00140f69:
    if ((*(int *)(iVar3 + 8) == 0x28) && ((*(byte *)(iVar2 + 0x15) & 2) == 0)) {
      cVar1 = ((undefined4 (*)())FUN_00140e9c)(iVar2,1,0);
      if (cVar1 != '\0') {
        if ((*(uint *)(iVar2 + 0xd0) & 1) != 0) {
          iVar3 = *(int *)(iVar2 + 0x88);
          goto LAB_00140f73;
        }
        if ((*(uint *)(iVar2 + 0xd0) & 2) == 0) {
          local_2c = 2;
          local_28 = 0x29;
          goto LAB_00140fec;
        }
      }
      iVar3 = *(int *)(iVar2 + 0x88);
    }
LAB_00140f73:
    if (*(int *)(iVar3 + 8) != 0x25) {
      return 0;
    }
    if ((*(byte *)(iVar2 + 0x15) & 2) != 0) {
      return 0;
    }
    cVar1 = ((undefined4 (*)())FUN_00140e9c)(iVar2,2,0);
    if (cVar1 == '\0') {
      return 0;
    }
    cVar1 = ((undefined4 (*)())FUN_00140e9c)(iVar2,3,0x3f800000);
    if (cVar1 == '\0') {
      return 0;
    }
    if ((*(uint *)(iVar2 + 0xb8) & 1) != 0) {
      return 0;
    }
    if ((*(uint *)(iVar2 + 0xb8) & 2) != 0) {
      return 0;
    }
  }
  local_2c = 1;
  local_28 = 0x29;
LAB_00140fec:
  iVar3 = FUN_0010b180(iVar2,local_2c);
  if (((((*(int *)(*(int *)(iVar3 + 0x88) + 8) == 0x12) && ((*(byte *)(iVar3 + 0x15) & 2) == 0)) &&
       ((*(uint *)(iVar3 + 0xb8) & 1) == 0)) &&
      (((*(uint *)(iVar3 + 0xb8) & 2) == 0 && ((*(uint *)(iVar3 + 0xd0) & 1) != 0)))) &&
     ((*(uint *)(iVar3 + 0xd0) & 2) == 0)) {
    iVar4 = FUN_0010b0f4(param_1,2);
    uVar5 = *(undefined4 *)(iVar4 + 0x10);
    iVar4 = FUN_0010b0f4(iVar2,local_2c);
    uVar5 = FUN_000f5610(*(undefined4 *)(iVar4 + 0x10),uVar5);
    iVar4 = FUN_0010b0f4(iVar3,1);
    uVar6 = FUN_000f5610(*(undefined4 *)(iVar4 + 0x10),uVar5);
    iVar4 = FUN_0010b0f4(iVar3,2);
    uVar5 = FUN_000f5610(*(undefined4 *)(iVar4 + 0x10),uVar5);
    iVar4 = FUN_0010b180(iVar3,1);
    FUN_0010ba02(param_1,1,iVar4,0,*(undefined4 *)(param_4 + 8));
    iVar7 = FUN_0010b180(iVar3,2);
    cVar1 = FUN_0010a62e(iVar2,param_4);
    if ((cVar1 == '\0') || (cVar1 = FUN_0010a62e(iVar3,param_4), cVar1 == '\0')) {
      if (*(int *)(param_4 + 0x46c) < *(int *)(iVar4 + 0x160)) {
        *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
      }
      else {
        *(int *)(iVar4 + 0x160) = *(int *)(param_4 + 0x46c) + 1;
      }
      if (*(int *)(param_4 + 0x46c) < *(int *)(iVar7 + 0x160)) {
        *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + 1;
      }
      else {
        *(int *)(iVar7 + 0x160) = *(int *)(param_4 + 0x46c) + 1;
      }
    }
    FUN_0010ba02(param_1,2,iVar7,0,*(undefined4 *)(param_4 + 8));
    iVar3 = FUN_0010b0f4(param_1,1);
    *(undefined4 *)(iVar3 + 0x10) = uVar6;
    iVar3 = FUN_0010b0f4(param_1,2);
    *(undefined4 *)(iVar3 + 0x10) = uVar5;
    uVar5 = FUN_00118f66(local_28);
    *(undefined4 *)(param_1 + 0x88) = uVar5;
    FUN_0010b3fe(iVar2,*(undefined4 *)(param_4 + 8));
  }
  return 0;
}

/* FUN_0014138e @ 0x14138e (179 bytes) */
int FUN_0014138e(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int *piVar1;
  char cVar2;
  
  if (((*(byte *)(param_1 + 0x14) & 1) != 0) &&
     ((param_2 == 0 || ((*(byte *)(param_2 + 0x14) & 1) != 0)))) {
    cVar2 = ((int (*)())FUN_00140efe)(param_1,param_2,param_3,param_4);
    if (cVar2 != '\0') {
      *(int *)(param_1 + 0x150) = *(int *)(param_4 + 0x468) + -1;
    }
    piVar1 = *(int **)(*(int *)(param_4 + 8) + 0x54);
    cVar2 = (**(code **)(*piVar1 + 0x70))(piVar1,param_2,param_3,param_1,param_4);
    if (cVar2 != '\0') {
      *(int *)(param_1 + 0x150) = *(int *)(param_4 + 0x468) + -1;
    }
    FUN_001536e4();
    return;
  }
  return;
}

/* FUN_00141442 @ 0x141442 (547 bytes) */
int FUN_00141442(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  char cVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  uint *local_38;
  int local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  undefined4 local_10;
  
  local_10 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_18 = 0;
  local_1c = 2;
  local_14 = FUN_001a7bca(local_10,8);
  *(int *)(param_1 + 0x468) = *(int *)(param_1 + 0x468) + 1;
  iVar3 = *(int *)(param_1 + 0x378);
  iVar4 = *(int *)(iVar3 + 8);
  while (iVar4 != 0) {
    piVar5 = *(int **)(iVar3 + 0x98);
    iVar4 = piVar5[2];
    while (iVar4 != 0) {
      if ((((*(byte *)(piVar5 + 5) & 1) != 0) &&
          (cVar6 = (**(code **)(*piVar5 + 0x30))(piVar5), uVar1 = local_18, cVar6 != '\0')) &&
         (*(int *)(param_1 + 0x468) != piVar5[0x54])) {
        piVar5[0x54] = *(int *)(param_1 + 0x468);
        if (local_18 < local_1c) {
          iVar4 = local_18 * 4;
          _memset((void *)(iVar4 + local_14),0,4);
          local_18 = uVar1 + 1;
          puVar7 = (undefined4 *)(iVar4 + local_14);
        }
        else {
          puVar7 = (undefined4 *)FUN_001a7f7c(&local_1c,local_18);
        }
        local_38 = &local_1c;
        *puVar7 = piVar5;
        do {
          uVar1 = local_18 - 1;
          if (uVar1 < local_18) {
            piVar9 = (int *)(local_14 + uVar1 * 4);
          }
          else {
            piVar9 = (int *)0x0;
          }
          iVar4 = *piVar9;
          FUN_001a7f3c(local_38,uVar1);
          if (0 < *(int *)(iVar4 + 0x84)) {
            local_20 = 1;
            do {
              iVar8 = FUN_0010b180(iVar4,local_20);
              uVar1 = local_18;
              *(uint *)(iVar8 + 0x14) = *(uint *)(iVar8 + 0x14) | 0x2000;
              if ((iVar8 != 0) && (*(int *)(param_1 + 0x468) != *(int *)(iVar8 + 0x150))) {
                *(int *)(iVar8 + 0x150) = *(int *)(param_1 + 0x468);
                if (local_18 < local_1c) {
                  iVar2 = local_18 * 4;
                  _memset((void *)(iVar2 + local_14),0,4);
                  local_18 = uVar1 + 1;
                  piVar9 = (int *)(iVar2 + local_14);
                }
                else {
                  piVar9 = (int *)FUN_001a7f7c(local_38,local_18);
                }
                *piVar9 = iVar8;
              }
              local_20 = local_20 + 1;
            } while (local_20 <= *(int *)(iVar4 + 0x84));
          }
        } while (local_18 != 0);
      }
      piVar5 = (int *)piVar5[2];
      iVar4 = piVar5[2];
    }
    iVar3 = *(int *)(iVar3 + 8);
    iVar4 = *(int *)(iVar3 + 8);
  }
  FUN_001a7aba(local_10,local_14);
  return;
}

/* FUN_00141682 @ 0x141682 (702 bytes) */
int FUN_00141682(param_1, param_2, param_3)
  int *param_1;
  uint *param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  byte bVar5;
  byte bVar6;
  dword dVar7;
  char cVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int *piVar11;
  dword local_18;
  int local_14;
  
  cVar8 = (**(code **)(*param_1 + 0x40))(param_1);
  if (cVar8 != '\0') {
    return;
  }
  uVar9 = FUN_000e9644(param_1);
  uVar1 = param_2[1];
  if (uVar1 < *param_2) {
    _memset((void *)(uVar1 * 4 + param_2[2]),0,4);
    param_2[1] = uVar1 + 1;
    puVar10 = (undefined4 *)(uVar1 * 4 + param_2[2]);
  }
  else {
    puVar10 = (undefined4 *)FUN_001a7f7c(param_2,uVar1);
  }
  *puVar10 = uVar9;
  bVar5 = 0;
  bVar6 = 0;
  do {
    while( true ) {
      dVar7 = MACH_HEADER.magic;
      uVar1 = param_2[1];
      if (uVar1 <= uVar1 - 1) break;
      local_18 = *(dword *)(param_2[2] + (uVar1 - 1) * 4);
      FUN_001a7f3c(param_2,uVar1 - 1);
      if (*(int *)(local_18 + 0x84) < 1) goto LAB_00141726;
LAB_0014176e:
      local_14 = 1;
      do {
        piVar11 = (int *)FUN_0010b180(local_18,local_14);
        if (piVar11 != (int *)0x0) {
          cVar8 = (**(code **)(*piVar11 + 0x28))(piVar11);
          if (cVar8 == '\0') {
            cVar8 = (**(code **)(*piVar11 + 0x4c))(piVar11);
            if (cVar8 != '\0') {
              bVar5 = 1;
              goto LAB_001417b1;
            }
            bVar4 = (bool)(bVar6 & bVar5);
          }
          else {
            bVar6 = 1;
LAB_001417b1:
            bVar4 = (bool)(bVar6 & bVar5);
          }
          if (bVar4) {
            iVar2 = param_1[0x4b];
            iVar3 = param_1[0x4c];
            cVar8 = FUN_000eacec(param_1);
            if (cVar8 != '\0') {
              piVar11 = *(int **)(iVar2 + 0x98);
              iVar2 = piVar11[2];
              while (iVar2 != 0) {
                if (((*(byte *)(piVar11 + 5) & 1) != 0) &&
                   (cVar8 = (**(code **)(*piVar11 + 0x28))(piVar11), cVar8 != '\0')) {
                  param_1[3] = param_1[3] | 0x400;
                  return;
                }
                piVar11 = (int *)piVar11[2];
                iVar2 = piVar11[2];
              }
              piVar11 = *(int **)(iVar3 + 0x98);
              iVar2 = piVar11[2];
              while (iVar2 != 0) {
                if (((*(byte *)(piVar11 + 5) & 1) != 0) &&
                   (cVar8 = (**(code **)(*piVar11 + 0x28))(piVar11), cVar8 != '\0')) {
                  param_1[3] = param_1[3] | 0x400;
                  return;
                }
                piVar11 = (int *)piVar11[2];
                iVar2 = piVar11[2];
              }
            }
            param_1[3] = param_1[3] | 0x800;
            return;
          }
          if (param_3 != piVar11[0x54]) {
            piVar11[0x54] = param_3;
            uVar1 = param_2[1];
            if (uVar1 < *param_2) {
              _memset((void *)(uVar1 * 4 + param_2[2]),0,4);
              param_2[1] = uVar1 + 1;
              puVar10 = (undefined4 *)(uVar1 * 4 + param_2[2]);
            }
            else {
              puVar10 = (undefined4 *)FUN_001a7f7c(param_2,uVar1);
            }
            *puVar10 = piVar11;
          }
        }
        local_14 = local_14 + 1;
      } while (local_14 <= *(int *)(local_18 + 0x84));
      if (param_2[1] == 0) goto LAB_00141836;
    }
    local_18 = MACH_HEADER.magic;
    FUN_001a7f3c(param_2,uVar1 - 1);
    if (0 < *(int *)(dVar7 + 0x84)) goto LAB_0014176e;
LAB_00141726: ;
  } while (param_2[1] != 0);
LAB_00141836:
  param_1[3] = param_1[3] | 0x400;
  return;
}

/* FUN_00141940 @ 0x141940 (344 bytes) */
int FUN_00141940(param_1)
  uint *param_1;
{
  uint uVar1;
  dword dVar2;
  char cVar3;
  int *piVar4;
  dword *pdVar5;
  int iVar6;
  int iVar7;
  undefined4 local_10;
  
  dVar2 = MACH_HEADER.magic;
  uVar1 = param_1[1];
  if (uVar1 - 1 < uVar1) {
    dVar2 = *(dword *)(param_1[2] + (uVar1 - 1) * 4);
    FUN_001a7f3c(param_1,uVar1 - 1);
    local_10 = dVar2;
    (*(unsigned char *)((unsigned char *)&(local_10) + 3)) = (char)(dVar2 >> 0x18);
    cVar3 = (*(unsigned char *)((unsigned char *)&(local_10) + 3));
  }
  else {
    FUN_001a7f3c(param_1,uVar1 - 1);
    local_10 = dVar2;
    (*(unsigned char *)((unsigned char *)&(local_10) + 3)) = (char)(dVar2 >> 0x18);
    cVar3 = (*(unsigned char *)((unsigned char *)&(local_10) + 3));
  }
  local_10 = dVar2;
  if (cVar3 != '\0') {
    iVar7 = 0;
    do {
      if (*(char *)((int)&local_10 + iVar7) != -1) {
        iVar6 = (int)*(char *)((int)&local_10 + iVar7 + 1);
        *(undefined1 *)((int)&local_10 + iVar7) = 0xff;
        dVar2 = local_10;
        uVar1 = param_1[1];
        if (uVar1 < *param_1) {
          _memset((void *)(uVar1 * 4 + param_1[2]),0,4);
          param_1[1] = uVar1 + 1;
          *(dword *)(uVar1 * 4 + param_1[2]) = dVar2;
          return iVar6;
        }
        pdVar5 = (dword *)FUN_001a7f7c(param_1,uVar1);
        *pdVar5 = dVar2;
        return iVar6;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 != 4);
    return 0;
  }
  iVar7 = local_10 + 1;
  uVar1 = param_1[1];
  if (uVar1 < *param_1) {
    _memset((void *)(uVar1 * 4 + param_1[2]),0,4);
    param_1[1] = uVar1 + 1;
    *(int *)(uVar1 * 4 + param_1[2]) = iVar7;
  }
  else {
    piVar4 = (int *)FUN_001a7f7c(param_1,uVar1);
    *piVar4 = iVar7;
  }
  return iVar7;
}

/* FUN_00141a98 @ 0x141a98 (808 bytes) */
int FUN_00141a98(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  undefined4 param_3;
{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int local_40;
  int local_20 [3];
  undefined4 local_14;
  char cStack_11;
  undefined4 local_10;
  
  if (param_1 == 0) {
    return 1;
  }
  iVar2 = *(int *)(param_1 + 0x84);
  local_10 = 0xffffffff;
  if (iVar2 == 1) {
    local_10 = 0xffffff01;
    uVar3 = param_2[1];
    if (uVar3 < *param_2) {
      _memset((void *)(uVar3 * 4 + param_2[2]),0,4);
      param_2[1] = uVar3 + 1;
      *(undefined4 *)(uVar3 * 4 + param_2[2]) = 0xffffff01;
      return 1;
    }
    puVar8 = (undefined4 *)FUN_001a7f7c(param_2,uVar3);
    *puVar8 = 0xffffff01;
    return 1;
  }
  if (4 < iVar2) {
    uVar3 = param_2[1];
    if (uVar3 < *param_2) {
      _memset((void *)(uVar3 * 4 + param_2[2]),0,4);
      param_2[1] = uVar3 + 1;
      puVar8 = (undefined4 *)(uVar3 * 4 + param_2[2]);
    }
    else {
      puVar8 = (undefined4 *)FUN_001a7f7c(param_2,uVar3);
    }
    *puVar8 = 1;
    return 1;
  }
  uVar9 = FUN_0010b180(param_1,1);
  local_20[0] = FUN_00109e42(uVar9,param_3);
  uVar9 = FUN_0010b180(param_1,2);
  local_20[1] = FUN_00109e42(uVar9,param_3);
  if (iVar2 == 2) {
    if (local_20[0] < local_20[1]) {
      (*(unsigned short *)((unsigned char *)&(local_10) + 0)) = 0x201;
    }
    else {
      (*(unsigned short *)((unsigned char *)&(local_10) + 0)) = 0x102;
    }
    uVar9 = local_10;
    uVar3 = param_2[1];
    if (uVar3 < *param_2) {
      _memset((void *)(uVar3 * 4 + param_2[2]),0,4);
      param_2[1] = uVar3 + 1;
      puVar8 = (undefined4 *)(uVar3 * 4 + param_2[2]);
    }
    else {
      puVar8 = (undefined4 *)FUN_001a7f7c(param_2,uVar3);
    }
    *puVar8 = uVar9;
    return (int)(char)local_10;
  }
  uVar9 = FUN_0010b180(param_1,3);
  local_20[2] = FUN_00109e42(uVar9,param_3);
  if (iVar2 == 4) {
    uVar9 = FUN_0010b180(param_1,4);
    local_14 = FUN_00109e42(uVar9,param_3);
  }
  else if (iVar2 < 1) goto LAB_00141c7d;
  iVar10 = 1;
  do {
    (&cStack_11)[iVar10] = (char)iVar10;
    iVar10 = iVar10 + 1;
  } while (iVar2 + 1 != iVar10);
LAB_00141c7d:
  uVar9 = local_10;
  do {
    local_40 = 0;
    bVar6 = false;
    iVar11 = 0;
    iVar10 = local_40;
    while (local_40 = iVar10, iVar12 = iVar11, bVar7 = bVar6, local_40 < iVar2 + -1) {
      while( true ) {
        bVar6 = bVar7;
        iVar4 = *(int *)((int)local_20 + iVar12);
        iVar10 = local_40 + 1;
        iVar11 = iVar12 + 4;
        iVar5 = *(int *)((int)local_20 + iVar12 + 4);
        if (iVar4 <= iVar5) break;
        *(int *)((int)local_20 + iVar12) = iVar5;
        *(int *)((int)local_20 + iVar12 + 4) = iVar4;
        uVar1 = *(undefined1 *)((int)&local_10 + local_40);
        *(undefined1 *)((int)&local_10 + local_40) = *(undefined1 *)((int)&local_10 + local_40 + 1);
        *(undefined1 *)((int)&local_10 + local_40 + 1) = uVar1;
        bVar6 = true;
        iVar12 = iVar11;
        local_40 = iVar10;
        bVar7 = true;
        if (iVar2 + -1 <= iVar10) goto LAB_00141cf4;
      }
    }
LAB_00141cf4:
    if (!bVar6) {
      uVar3 = param_2[1];
      if (uVar3 < *param_2) {
        _memset((void *)(uVar3 * 4 + param_2[2]),0,4);
        param_2[1] = uVar3 + 1;
        puVar8 = (undefined4 *)(uVar3 * 4 + param_2[2]);
      }
      else {
        puVar8 = (undefined4 *)FUN_001a7f7c(param_2,uVar3);
      }
      *puVar8 = uVar9;
      return (int)(char)local_10;
    }
  } while( true );
}

/* FUN_00141dc0 @ 0x141dc0 (290 bytes) */
int FUN_00141dc0(param_1)
  int param_1;
{
  byte bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  uint *puVar6;
  int iVar7;
  uint local_18;
  uint local_14;
  int local_10;
  
  puVar6 = *(uint **)(param_1 + 0x10);
  if (puVar6[1] == 0) {
    return 0;
  }
  local_18 = 0;
  local_14 = 0;
  do {
    if (local_18 < *puVar6) {
      uVar2 = puVar6[1];
      if (uVar2 <= local_18) {
        _memset((void *)(puVar6[2] + uVar2 * 4),0,(local_18 - uVar2) * 4 + 4);
        puVar6[1] = local_18 + 1;
      }
      puVar5 = (undefined4 *)(puVar6[2] + local_18 * 4);
    }
    else {
      puVar5 = (undefined4 *)FUN_001a7f7c(puVar6,local_18);
    }
    local_18 = local_18 + 1;
    piVar3 = (int *)*puVar5;
    iVar7 = 1;
    iVar4 = (**(code **)(*piVar3 + 0x14))(piVar3);
    if (0 < iVar4) {
      do {
        iVar4 = FUN_0010b180(piVar3,iVar7);
        if (param_1 == iVar4) {
          local_10 = 0;
          do {
            iVar4 = FUN_0010b0f4(piVar3,iVar7);
            bVar1 = *(byte *)(local_10 + 0x10 + iVar4);
            if (bVar1 != 4) {
              local_14 = local_14 | 1 << (bVar1 & 0x1f);
            }
            local_10 = local_10 + 1;
          } while (local_10 != 4);
        }
        iVar7 = iVar7 + 1;
        iVar4 = (**(code **)(*piVar3 + 0x14))(piVar3);
      } while (iVar7 <= iVar4);
    }
    puVar6 = *(uint **)(param_1 + 0x10);
  } while (local_18 < puVar6[1]);
  return local_14;
}

/* FUN_00141ee2 @ 0x141ee2 (277 bytes) */
int FUN_00141ee2(param_1, param_2)
  int *param_1;
  uint param_2;
{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  uint *puVar8;
  int iVar9;
  uint local_14;
  
  puVar8 = (uint *)param_1[4];
  if (puVar8[1] != 0) {
    local_14 = 0;
    do {
      if (local_14 < *puVar8) {
        uVar2 = puVar8[1];
        if (uVar2 <= local_14) {
          _memset((void *)(puVar8[2] + uVar2 * 4),0,(local_14 - uVar2) * 4 + 4);
          puVar8[1] = local_14 + 1;
        }
        puVar7 = (undefined4 *)(puVar8[2] + local_14 * 4);
      }
      else {
        puVar7 = (undefined4 *)FUN_001a7f7c(puVar8,local_14);
      }
      uVar3 = *puVar7;
      iVar9 = 1;
      iVar4 = (**(code **)(*param_1 + 0x14))(param_1);
      if (0 < iVar4) {
        do {
          piVar5 = (int *)FUN_0010b180(uVar3,iVar9);
          if (param_1 == piVar5) {
            iVar4 = 0;
            do {
              iVar6 = FUN_0010b0f4(uVar3,iVar9);
              bVar1 = *(byte *)(iVar4 + 0x10 + iVar6);
              if ((bVar1 != 4) && (param_2 = param_2 & ~(1 << (bVar1 & 0x1f)), param_2 == 0)) {
                return 0;
              }
              iVar4 = iVar4 + 1;
            } while (iVar4 != 4);
          }
          iVar9 = iVar9 + 1;
          iVar4 = (**(code **)(*param_1 + 0x14))(param_1);
        } while (iVar9 <= iVar4);
      }
      local_14 = local_14 + 1;
      puVar8 = (uint *)param_1[4];
    } while (local_14 < puVar8[1]);
  }
  return param_2;
}

/* FUN_00141ff8 @ 0x141ff8 (2587 bytes) */
int FUN_00141ff8(param_1)
  int param_1;
{
  byte bVar1;
  int *piVar2;
  undefined4 uVar3;
  code *pcVar4;
  bool bVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  byte *pbVar13;
  int *piVar14;
  uint uVar15;
  bool bVar16;
  byte local_ac;
  byte local_94;
  int local_64;
  int local_5c;
  uint local_4c;
  uint local_48;
  int local_44;
  int local_3c;
  int local_34;
  int local_2c;
  int local_28;
  uint local_24;
  undefined4 local_10;
  
  iVar7 = FUN_001a7c0a(*(undefined4 *)(*(int *)(param_1 + 8) + 0xbc),
                       *(int *)(*(int *)(param_1 + 8) + 0x68) << 2,1);
  local_64 = *(int *)(param_1 + 0x378);
  if (*(int *)(local_64 + 8) != 0) {
    do {
      piVar2 = *(int **)(local_64 + 0x98);
      iVar10 = piVar2[2];
      while (iVar10 != 0) {
        if ((*(byte *)(piVar2 + 5) & 1) != 0) {
          iVar10 = *(int *)(piVar2[0x22] + 8);
          local_5c = 1;
          iVar8 = (**(code **)(*piVar2 + 0x14))(piVar2);
          if (0 < iVar8) {
            do {
              piVar9 = (int *)FUN_0010b180(piVar2,local_5c);
              local_10 = *(uint *)(iVar7 + piVar9[0x53] * 4);
              if (iVar10 == 0x8e) {
LAB_00142194:
                uVar15 = 0;
                do {
                  *(byte *)((int)&local_10 + uVar15) =
                       *(byte *)((int)&local_10 + uVar15) & 3 | 1 | (byte)((uVar15 & 0x3f) << 2);
                  uVar15 = uVar15 + 1;
                } while (uVar15 != 4);
LAB_001421ca:
                *(uint *)(iVar7 + piVar9[0x53] * 4) = local_10;
              }
              else {
                uVar3 = *(undefined4 *)(param_1 + 8);
                cVar6 = (**(code **)(*piVar9 + 0x24))(piVar9);
                if (((cVar6 == '\0') || (cVar6 = FUN_001192da(uVar3,piVar9), cVar6 != '\0')) ||
                   ((*(byte *)((int)piVar9 + 0x16) & 0x40) != 0)) goto LAB_00142194;
                bVar5 = false;
                bVar16 = false;
                local_4c = 0xf;
                local_48 = 0;
                local_44 = 0;
                do {
                  iVar8 = FUN_0010b0f4(piVar2,local_5c);
                  bVar1 = *(byte *)(local_44 + 0x10 + iVar8);
                  uVar15 = (uint)bVar1;
                  iVar8 = FUN_0010b0f4(piVar9,0);
                  if (*(char *)(local_44 + 0x10 + iVar8) != '\x01') {
                    local_4c = local_4c & ~(1 << ((byte)local_44 & 0x1f));
                  }
                  if (bVar1 != 4) {
                    if (bVar1 == 3) {
                      if (((local_10 & 0x1000000) == 0) || ((*(unsigned char *)((unsigned char *)&(local_10) + 3)) >> 2 == 3)) {
                        local_10 = local_10 & 0x3ffffff | 0xc000000;
                      }
                      else {
                        local_48 = local_48 | 1 << ((*(unsigned char *)((unsigned char *)&(local_10) + 3)) >> 2 & 0x1f);
                      }
                      local_4c = local_4c & 0xfffffff7;
                      bVar5 = true;
                    }
                    else if (((local_10 & 0x1000000) == 0) || (uVar15 != (*(unsigned char *)((unsigned char *)&(local_10) + 3)) >> 2)) {
                      *(byte *)((int)&local_10 + uVar15) =
                           *(byte *)((int)&local_10 + uVar15) & 3 | (byte)((uVar15 & 0x3f) << 2);
                      local_4c = local_4c & ~(1 << (bVar1 & 0x1f));
                      bVar16 = true;
                    }
                    else {
                      local_10 = local_10 & 0x3ffffff | 0xc000000;
                      local_94 = *(byte *)((int)&local_10 + uVar15) & 3 | bVar1 << 2;
                      *(byte *)((int)&local_10 + uVar15) = local_94;
                      local_4c = 0;
                    }
                    *(byte *)((int)&local_10 + uVar15) = *(byte *)((int)&local_10 + uVar15) | 1;
                  }
                  local_44 = local_44 + 1;
                } while (local_44 != 4);
                if (((local_4c != 0) && (bVar16)) && (bVar5)) {
                  if (local_48 != 0) {
                    if ((local_4c & local_48) == 0) goto LAB_001421dc;
                    local_4c = local_48;
                  }
                  local_24 = ((int (*)())FUN_00141ee2)(piVar9,local_4c,param_1);
                  if (local_24 == 0) goto LAB_001421dc;
                  iVar8 = FUN_0010b0f4(piVar9,0);
                  if (*(char *)(iVar8 + 0x13) == '\x01') {
                    if ((*(byte *)((int)piVar9 + 0x15) & 2) != 0) {
                      for (piVar14 = (int *)FUN_0010b180(piVar9,piVar9[0x21]); piVar14 != (int *)0x0
                          ; piVar14 = (int *)FUN_0010b180(piVar14,piVar14[0x21])) {
                        iVar8 = FUN_0010b0f4(piVar14,0);
                        if (*(char *)(iVar8 + 0x13) == '\x01') {
                          local_24 = ((int (*)())FUN_00141ee2)(piVar14,local_24,param_1);
                        }
                        else {
                          cVar6 = (**(code **)(*piVar14 + 0x24))(piVar14);
                          if ((cVar6 == '\0') ||
                             (cVar6 = FUN_001192da(*(undefined4 *)(param_1 + 8),piVar14),
                             cVar6 != '\0')) goto LAB_001421dc;
                        }
                        if (local_24 == 0) goto LAB_001421dc;
                        if ((*(byte *)((int)piVar14 + 0x15) & 2) == 0) break;
                      }
                    }
                    if ((local_24 & 1) == 0) {
                      if ((local_24 & 2) == 0) {
                        local_3c = 2;
                        local_28 = 2;
                      }
                      else {
                        local_3c = 1;
                        local_28 = 1;
                      }
                    }
                    else {
                      local_3c = 0;
                      local_28 = 0;
                    }
                    iVar8 = FUN_0010b0f4(piVar9,0);
                    if (((*(char *)(iVar8 + 0x13) == '\x01') &&
                        ((*(byte *)((int)piVar9 + 0x15) & 2) != 0)) &&
                       (iVar8 = FUN_0010b180(piVar9,piVar9[0x21]), iVar8 != 0)) {
                      do {
                        iVar11 = iVar7 + *(int *)(iVar8 + 0x14c) * 4;
                        *(byte *)(iVar11 + 3) = *(byte *)(iVar11 + 3) & 3 | (byte)(local_28 << 2);
                        iVar11 = iVar7 + *(int *)(iVar8 + 0x14c) * 4;
                        *(byte *)(iVar11 + 3) = *(byte *)(iVar11 + 3) | 1;
                        pbVar13 = (byte *)(iVar7 + *(int *)(iVar8 + 0x14c) * 4 + local_3c);
                        *pbVar13 = *pbVar13 | 1;
                        iVar11 = FUN_0010b0f4(iVar8,0);
                        if ((*(char *)(iVar11 + 0x13) != '\x01') ||
                           ((*(byte *)(iVar8 + 0x15) & 2) == 0)) break;
                        iVar8 = FUN_0010b180(iVar8,*(undefined4 *)(iVar8 + 0x84));
                      } while (iVar8 != 0);
                    }
                    local_ac = (byte)(local_10 >> 0x18) & 3 | (byte)(local_28 << 2);
                    local_10 = CONCAT13(local_ac,(undefined3)local_10);
                  }
                  goto LAB_001421ca;
                }
              }
LAB_001421dc:
              local_5c = local_5c + 1;
              iVar8 = (**(code **)(*piVar2 + 0x14))(piVar2);
            } while (local_5c <= iVar8);
          }
        }
        piVar2 = (int *)piVar2[2];
        iVar10 = piVar2[2];
      }
      local_64 = *(int *)(local_64 + 8);
    } while (*(int *)(local_64 + 8) != 0);
    local_64 = *(int *)(param_1 + 0x378);
  }
  iVar10 = *(int *)(local_64 + 8);
  while (iVar10 != 0) {
    piVar2 = *(int **)(local_64 + 0x98);
    iVar10 = piVar2[2];
    while (iVar10 != 0) {
      if ((*(byte *)(piVar2 + 5) & 1) != 0) {
        cVar6 = (**(code **)(*piVar2 + 0x24))(piVar2);
        if (((cVar6 != '\0') &&
            (cVar6 = FUN_001192da(*(undefined4 *)(param_1 + 8),piVar2), cVar6 == '\0')) &&
           (bVar1 = *(byte *)(iVar7 + 3 + piVar2[0x53] * 4), (bVar1 & 1) != 0)) {
          uVar15 = (uint)(bVar1 >> 2);
          FUN_0010b0f4(piVar2,0);
          if (uVar15 != 3) {
            iVar10 = piVar2[3];
            iVar8 = FUN_0010b0f4(piVar2,0);
            uVar12 = FUN_000f5a44(*(undefined4 *)(iVar8 + 0x10),iVar10);
            (*(unsigned char *)((unsigned char *)&(local_10) + 3)) = (byte)(uVar12 >> 0x18);
            bVar16 = (*(unsigned char *)((unsigned char *)&(local_10) + 3)) == '\0';
            local_10 = uVar12;
            if (bVar16) {
              (*(unsigned int *)((unsigned char *)&(local_10) + 0)) = (undefined3)uVar12;
              local_10 = CONCAT13(1,(undefined3)local_10);
              *(undefined1 *)((int)&local_10 + uVar15) = 0;
              *(undefined1 *)((int)piVar2 + 0xf) = 0;
              *(undefined1 *)((int)piVar2 + uVar15 + 0xc) = 1;
              cVar6 = FUN_001190ce(*(undefined4 *)(piVar2[0x22] + 8),*(undefined4 *)(param_1 + 8));
              if (cVar6 == '\0') {
                local_34 = 1;
                while (iVar10 = (**(code **)(*piVar2 + 0x14))(piVar2), local_34 <= iVar10) {
                  iVar10 = FUN_0010b180(piVar2,local_34);
                  iVar8 = FUN_0010b0f4(piVar2,local_34);
                  if (*(char *)(uVar15 + 0x10 + iVar8) != '\x04') {
                    FUN_0010b0f4(piVar2,local_34);
                    FUN_0010b0f4(piVar2,local_34);
                  }
                  pcVar4 = *(code **)(*piVar2 + 0x88);
                  iVar8 = FUN_0010b0f4(piVar2,local_34);
                  (*pcVar4)(piVar2,local_34,uVar15,*(undefined1 *)(iVar8 + 0x13));
                  (**(code **)(*piVar2 + 0x88))(piVar2,local_34,3,4);
                  if (*(int *)(iVar10 + 0x98) == 0x33) {
                    (**(code **)(*piVar2 + 0x88))(piVar2,local_34,uVar15,uVar15);
                    *(undefined1 *)(iVar10 + 0xc + uVar15) = 1;
                    *(undefined1 *)(uVar15 + 0x9c + iVar10) = 0;
                    local_34 = local_34 + 1;
                  }
                  else {
                    local_34 = local_34 + 1;
                  }
                }
              }
              piVar9 = *(int **)(*(int *)(param_1 + 8) + 0x54);
              cVar6 = (**(code **)(*piVar9 + 0x7c))(piVar9,piVar2);
              if (cVar6 != '\0') {
                piVar2[0x27] = local_10;
              }
            }
          }
        }
        for (local_2c = 1; iVar10 = (**(code **)(*piVar2 + 0x14))(piVar2), local_2c <= iVar10;
            local_2c = local_2c + 1) {
          piVar9 = (int *)FUN_0010b180(piVar2,local_2c);
          iVar10 = piVar9[0x53];
          cVar6 = (**(code **)(*piVar9 + 0x24))(piVar9);
          if (cVar6 != '\0') {
            iVar10 = iVar7 + iVar10 * 4;
            bVar1 = *(byte *)(iVar10 + 3);
            if (((bVar1 & 1) != 0) && (bVar1 >> 2 != 3)) {
              iVar8 = 0;
              do {
                iVar11 = FUN_0010b0f4(piVar2,local_2c);
                if (*(char *)(iVar8 + 0x10 + iVar11) == '\x03') {
                  (**(code **)(*piVar2 + 0x88))(piVar2,local_2c,iVar8,*(byte *)(iVar10 + 3) >> 2);
                }
                iVar8 = iVar8 + 1;
              } while (iVar8 != 4);
            }
          }
        }
      }
      piVar2 = (int *)piVar2[2];
      iVar10 = piVar2[2];
    }
    local_64 = *(int *)(local_64 + 8);
    iVar10 = *(int *)(local_64 + 8);
  }
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xbc),iVar7);
  return;
}

/* FUN_00142a14 @ 0x142a14 (563 bytes) */
int FUN_00142a14(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *local_1c;
  uint local_18;
  
  local_1c = (int *)0x0;
  local_18 = 0;
  iVar6 = FUN_00109e42(param_1,param_2);
  if (0 < iVar6) {
    do {
      puVar1 = *(uint **)(param_1 + 0x10);
      if (local_18 < *puVar1) {
        uVar2 = puVar1[1];
        if (uVar2 <= local_18) {
          _memset((void *)(puVar1[2] + uVar2 * 4),0,(local_18 - uVar2) * 4 + 4);
          puVar1[1] = local_18 + 1;
        }
        piVar7 = (int *)(puVar1[2] + local_18 * 4);
      }
      else {
        piVar7 = (int *)FUN_001a7f7c(puVar1,local_18);
      }
      iVar6 = *piVar7;
      piVar7 = *(int **)(iVar6 + 0x158);
      if ((*(byte *)(piVar7 + 3) & 0x40) != 0) goto LAB_00142b01;
      if (*(int *)(*(int *)(iVar6 + 0x88) + 8) == 0x8e) {
        iVar3 = 0;
        do {
          iVar9 = iVar3;
          if (*(int *)(iVar6 + 0x84) <= iVar9) goto LAB_00142a92;
          iVar8 = FUN_0010b180(iVar6,iVar9 + 1);
          iVar3 = iVar9 + 1;
        } while (param_1 != iVar8);
        piVar7 = (int *)FUN_000eac0c(piVar7,iVar9);
      }
LAB_00142a92:
      cVar5 = (**(code **)(*piVar7 + 0x24))(piVar7);
      if ((cVar5 != '\0') && (piVar7 = (int *)FUN_000eac0c(piVar7,0), piVar7 == (int *)0x0))
      goto LAB_00142b01;
      piVar4 = piVar7;
      if ((local_1c != (int *)0x0) && (piVar4 = local_1c, local_1c != piVar7)) {
        do {
          iVar6 = piVar7[0x2f];
          iVar3 = local_1c[0x2f];
          if (iVar3 < iVar6) {
            piVar7 = (int *)piVar7[0x3b];
LAB_00142b18:
            if (piVar7 == (int *)0x0) goto LAB_00142b01;
          }
          else if (iVar6 < iVar3) {
            local_1c = (int *)local_1c[0x3b];
          }
          else if (iVar6 == iVar3) {
            piVar7 = (int *)piVar7[0x3b];
            local_1c = (int *)local_1c[0x3b];
            goto LAB_00142b18;
          }
          piVar4 = piVar7;
        } while ((local_1c != (int *)0x0) && (piVar4 = local_1c, local_1c != piVar7));
      }
      local_1c = piVar4;
      local_18 = local_18 + 1;
      iVar6 = FUN_00109e42(param_1,param_2);
    } while ((int)local_18 < iVar6);
  }
  iVar6 = FUN_000e97aa(local_1c);
  if (((1 < iVar6) &&
      (local_1c = (int *)FUN_000eac0c(local_1c,0), local_1c == *(int **)(param_1 + 0x158))) ||
     (cVar5 = ((int (*)())FUN_001409f8)(local_1c,*(undefined4 *)(param_2 + 0x394)), cVar5 == '\0')) {
LAB_00142b01:
    local_1c = (int *)0x0;
  }
  return local_1c;
}

/* FUN_00142c48 @ 0x142c48 (2401 bytes) */
int FUN_00142c48(param_1)
  int param_1;
{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  undefined4 *puVar12;
  int *piVar13;
  undefined4 *puVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int *piVar18;
  int *piVar19;
  uint local_90;
  int local_68;
  uint local_64;
  int *local_50;
  int *local_48;
  int local_34;
  int *local_30;
  
  iVar15 = *(int *)(param_1 + 0x39c);
  while ((iVar15 != 0 && (iVar6 = FUN_000e97bc(iVar15), iVar6 != 0))) {
    *(uint *)(iVar15 + 0xc) = *(uint *)(iVar15 + 0xc) | 0x40;
    iVar15 = *(int *)(iVar15 + 0xec);
  }
  iVar15 = *(int *)(param_1 + 0x394);
  uVar8 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar7 = (undefined4 *)FUN_001a7bca(uVar8,0x14);
  *puVar7 = uVar8;
  puVar1 = puVar7 + 1;
  puVar7[4] = uVar8;
  puVar7[2] = 0;
  puVar7[1] = 2;
  uVar8 = FUN_001a7bca(uVar8,8);
  puVar7[3] = uVar8;
  iVar6 = *(int *)(param_1 + 0x378);
  iVar16 = *(int *)(iVar6 + 8);
  while (iVar16 != 0) {
    if ((iVar6 != iVar15) && (cVar5 = ((int (*)())FUN_001409f8)(iVar6,iVar15), cVar5 != '\0')) {
      iVar16 = *(int *)(iVar6 + 0x98);
      iVar9 = *(int *)(iVar16 + 8);
      while (iVar9 != 0) {
        if ((*(byte *)(iVar16 + 0x14) & 1) != 0) {
          local_68 = 0;
LAB_00142d39:
          if (local_68 < *(int *)(iVar16 + 0x84)) {
            while( true ) {
              local_68 = local_68 + 1;
              iVar9 = FUN_0010b180(iVar16,local_68);
              cVar5 = ((int (*)())FUN_00140aa2)(iVar9);
              if ((((cVar5 == '\0') || (*(int *)(*(int *)(iVar9 + 0x158) + 0xb8) != 0)) ||
                  (iVar10 = ((int (*)())FUN_00142a14)(iVar9,param_1), iVar10 == 0)) ||
                 (iVar10 == *(int *)(iVar9 + 0x158))) break;
              uVar17 = MACH_HEADER.filetype;
              for (piVar11 = *(int **)(iVar10 + 0xec); MACH_HEADER.filetype = uVar17,
                  piVar11 != (int *)0x0; piVar11 = (int *)piVar11[0x3b]) {
                cVar5 = (**(code **)(*piVar11 + 0x24))(piVar11);
                if (cVar5 != '\0') {
                  uVar17 = piVar11[3];
                  break;
                }
                uVar17 = piVar11[3];
                if ((uVar17 & 0x40) != 0) break;
                uVar17 = MACH_HEADER.filetype;
              }
              if ((uVar17 & 0x800) != 0) break;
              uVar17 = puVar7[2];
              if (uVar17 < *puVar1) {
                _memset((void *)(uVar17 * 4 + puVar7[3]),0,4);
                puVar7[2] = uVar17 + 1;
                piVar11 = (int *)(uVar17 * 4 + puVar7[3]);
              }
              else {
                piVar11 = (int *)FUN_001a7f7c(puVar1,uVar17);
              }
              *piVar11 = iVar9;
              FUN_00109e26(iVar9);
              *(uint *)(iVar9 + 0x14) = *(uint *)(iVar9 + 0x14) | 1;
              FUN_000e9540(iVar10,iVar9);
              if (*(int *)(iVar16 + 0x84) <= local_68) goto LAB_00142e59;
            }
            goto LAB_00142d39;
          }
        }
LAB_00142e59:
        iVar16 = *(int *)(iVar16 + 8);
        iVar9 = *(int *)(iVar16 + 8);
      }
    }
    iVar6 = *(int *)(iVar6 + 8);
    iVar16 = *(int *)(iVar6 + 8);
  }
  if (puVar7[2] == 0) {
    return;
  }
  local_64 = 0;
LAB_00142e96:
  if (local_64 < *puVar1) {
    uVar17 = puVar7[2];
    if (uVar17 <= local_64) {
      _memset((void *)(puVar7[3] + uVar17 * 4),0,(local_64 - uVar17) * 4 + 4);
      puVar7[2] = local_64 + 1;
    }
    iVar15 = *(int *)(puVar7[3] + local_64 * 4);
    piVar11 = *(int **)(iVar15 + 0x158);
  }
  else {
    piVar11 = (int *)FUN_001a7f7c(puVar1,local_64);
    iVar15 = *piVar11;
    piVar11 = *(int **)(iVar15 + 0x158);
  }
  if (piVar11 == (int *)0x0) {
    local_30 = (int *)0x0;
    piVar18 = (int *)0x0;
  }
  else {
    piVar18 = (int *)0x0;
    local_48 = piVar11;
    do {
      cVar5 = (**(code **)(*local_48 + 0x14))(local_48);
      if (cVar5 != '\0') goto LAB_00143162;
      cVar5 = (**(code **)(*local_48 + 0x24))(local_48);
      local_30 = local_48;
      if (cVar5 != '\0') break;
      cVar5 = (**(code **)(*local_48 + 0x28))(local_48);
      if (cVar5 == '\0') {
        cVar5 = (**(code **)(*local_48 + 0x34))(local_48);
        if (cVar5 == '\0') {
          cVar5 = (**(code **)(*local_48 + 0x2c))(local_48);
          piVar18 = local_48;
          if (cVar5 == '\0') {
            local_48 = (int *)FUN_000eac0c(local_48,0);
          }
          else {
            local_48 = (int *)FUN_000e9b0e(local_48);
          }
        }
        else {
          piVar18 = (int *)local_48[0x49];
          local_48 = (int *)FUN_000e9b0e(piVar18);
        }
      }
      else {
        piVar18 = (int *)local_48[0x49];
        local_48 = (int *)FUN_000eac0c(piVar18,0);
      }
      local_30 = local_48;
    } while (local_48 != (int *)0x0);
  }
  uVar8 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar12 = (undefined4 *)FUN_001a7bca(uVar8,300);
  *puVar12 = uVar8;
  local_48 = puVar12 + 1;
  FUN_000ebe1a(local_48,*(undefined4 *)(param_1 + 8));
  if (piVar18 == (int *)local_30[0x4c]) {
    local_30[0x4c] = (int)local_48;
  }
  FUN_000edc00(param_1,piVar18,local_48);
  FUN_000eb12a(local_30,piVar18,local_48);
  FUN_000ea91c(local_48,piVar18);
  piVar18 = (int *)local_30[0x4d];
  piVar13 = piVar11;
  local_50 = piVar11;
  do {
    piVar19 = piVar13;
    cVar5 = (**(code **)(*piVar19 + 0x28))(piVar19);
    if ((cVar5 != '\0') && (piVar19 == piVar18)) {
      uVar17 = 1;
      iVar16 = 0;
      iVar6 = piVar19[0x35];
      if (*(int *)(iVar6 + 4) != 0) {
        do {
          piVar13 = *(int **)(*(int *)(iVar6 + 8) + iVar16);
          if ((piVar13 != (int *)0x0) && (local_50 != piVar13)) goto LAB_001430b7;
          uVar17 = uVar17 + 1;
          iVar16 = iVar16 + 4;
          iVar6 = piVar19[0x35];
        } while (uVar17 <= *(uint *)(iVar6 + 4));
      }
      piVar13 = (int *)0x0;
LAB_001430b7:
      cVar5 = (**(code **)(*piVar13 + 0x18))(piVar13);
      if (cVar5 == '\0') break;
    }
    cVar5 = (**(code **)(*piVar19 + 0x24))(piVar19);
    piVar13 = piVar19;
    if (cVar5 != '\0') {
      piVar13 = (int *)FUN_000eac7c(piVar19[0x4d],0);
    }
    cVar5 = (**(code **)(*piVar13 + 0x2c))(piVar13);
    if (cVar5 != '\0') {
      piVar13 = (int *)piVar13[0x51];
    }
    piVar13 = (int *)FUN_000eac7c(piVar13,0);
    local_50 = piVar19;
  } while( true );
  uVar8 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar12 = (undefined4 *)FUN_001a7bca(uVar8,300);
  *puVar12 = uVar8;
  puVar14 = puVar12 + 1;
  FUN_000ebb06(puVar14,*(undefined4 *)(param_1 + 8));
  puVar12[1] = PTR_DAT_00213a2d + 8;
  puVar12[0x4a] = local_48;
  FUN_000edc32(param_1,piVar13,puVar14);
  FUN_000eb2a6(piVar19,piVar13,puVar14);
  FUN_000ea91c(piVar13,puVar14);
LAB_00143162:
  uVar8 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar12 = (undefined4 *)FUN_001a7bca(uVar8,0x14);
  *puVar12 = uVar8;
  puVar2 = puVar12 + 1;
  puVar12[4] = uVar8;
  puVar12[2] = 0;
  puVar12[1] = 2;
  uVar8 = FUN_001a7bca(uVar8,8);
  puVar12[3] = uVar8;
  uVar8 = FUN_0010b180(iVar15,1);
  uVar17 = puVar12[2];
  if (uVar17 < (uint)puVar12[1]) {
    _memset((void *)(uVar17 * 4 + puVar12[3]),0,4);
    puVar12[2] = uVar17 + 1;
    puVar14 = (undefined4 *)(uVar17 * 4 + puVar12[3]);
  }
  else {
    puVar14 = (undefined4 *)FUN_001a7f7c(puVar2,uVar17);
  }
  *puVar14 = uVar8;
  if (puVar12[2] != 0) {
    local_90 = 0;
    if (*puVar2 == 0) goto LAB_00143333;
LAB_0014325d:
    uVar17 = puVar12[2];
    if (uVar17 <= local_90) {
      _memset((void *)(puVar12[3] + uVar17 * 4),0,(local_90 - uVar17) * 4 + 4);
      puVar12[2] = local_90 + 1;
    }
    piVar18 = (int *)(puVar12[3] + local_90 * 4);
    uVar17 = local_90;
    do {
      local_90 = uVar17 + 1;
      piVar18 = (int *)*piVar18;
      if ((int *)piVar18[0x56] != local_48) {
        if (uVar17 == 0) {
          puVar3 = (uint *)local_48[0x49];
          uVar17 = puVar3[1];
          if (uVar17 < *puVar3) {
            _memset((void *)(uVar17 * 4 + puVar3[2]),0,4);
            puVar3[1] = uVar17 + 1;
            piVar13 = (int *)(uVar17 * 4 + puVar3[2]);
          }
          else {
            piVar13 = (int *)FUN_001a7f7c(puVar3,uVar17);
          }
          *piVar13 = (int)piVar18;
        }
        if (((((*(byte *)(piVar18 + 5) & 8) == 0) && (*(int *)(piVar18[0x22] + 8) != 0x8e)) &&
            (piVar18[0x56] != *(int *)(param_1 + 0x394))) &&
           (cVar5 = (**(code **)(*piVar18 + 0x50))(piVar18), cVar5 == '\0')) {
          uVar17 = 0;
          iVar15 = FUN_00109e42(piVar18,param_1);
          if (0 < iVar15) {
            do {
              puVar3 = (uint *)piVar18[4];
              if (uVar17 < *puVar3) {
                uVar4 = puVar3[1];
                if (uVar4 <= uVar17) {
                  _memset((void *)(puVar3[2] + uVar4 * 4),0,(uVar17 - uVar4) * 4 + 4);
                  puVar3[1] = uVar17 + 1;
                }
                piVar13 = (int *)(puVar3[2] + uVar17 * 4);
              }
              else {
                piVar13 = (int *)FUN_001a7f7c(puVar3,uVar17);
              }
              if ((local_48 != *(int **)(*piVar13 + 0x158)) &&
                 (piVar11 != *(int **)(*piVar13 + 0x158))) goto LAB_00143316;
              uVar17 = uVar17 + 1;
              iVar15 = FUN_00109e42(piVar18,param_1);
            } while ((int)uVar17 < iVar15);
          }
          FUN_00109e26(piVar18);
          piVar18[5] = piVar18[5] | 1;
          FUN_000e9540(local_48,piVar18);
          for (local_34 = 1; iVar15 = (**(code **)(*piVar18 + 0x14))(piVar18), local_34 < iVar15;
              local_34 = local_34 + 1) {
            uVar8 = FUN_0010b180(piVar18,local_34);
            uVar17 = puVar12[2];
            if (uVar17 < *puVar2) {
              _memset((void *)(uVar17 * 4 + puVar12[3]),0,4);
              puVar12[2] = uVar17 + 1;
              puVar14 = (undefined4 *)(uVar17 * 4 + puVar12[3]);
            }
            else {
              puVar14 = (undefined4 *)FUN_001a7f7c(puVar2,uVar17);
            }
            *puVar14 = uVar8;
          }
        }
      }
LAB_00143316:
      if ((uint)puVar12[2] <= local_90) break;
      if (local_90 < *puVar2) goto LAB_0014325d;
LAB_00143333:
      piVar18 = (int *)FUN_001a7f7c(puVar2,local_90);
      uVar17 = local_90;
    } while( true );
  }
  local_64 = local_64 + 1;
  if ((uint)puVar7[2] <= local_64) {
    return;
  }
  goto LAB_00142e96;
}

/* FUN_00143642 @ 0x143642 (1198 bytes) */
int FUN_00143642(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_70;
  uint *local_6c;
  int local_60;
  undefined1 local_55;
  int local_4c;
  uint local_44;
  int local_40;
  uint local_30;
  uint local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  
  iVar3 = *(int *)(param_1 + 0x2ac);
  *(int *)(param_1 + 0x2ac) = iVar3 + 1;
  iVar8 = *(int *)(param_1 + 8);
  iVar6 = *(int *)(iVar8 + 0x68);
  if (param_2 == '\0') {
    local_60 = 0;
  }
  else {
    local_60 = FUN_001a7bca(*(undefined4 *)(iVar8 + 0xbc),iVar6 << 2);
    local_70 = *(int *)(param_1 + 0x378);
    if (*(int *)(local_70 + 8) == 0) {
      iVar8 = *(int *)(param_1 + 8);
    }
    else {
      do {
        iVar8 = *(int *)(local_70 + 0x98);
        iVar10 = *(int *)(iVar8 + 8);
        while (iVar10 != 0) {
          if ((*(byte *)(iVar8 + 0x14) & 1) != 0) {
            iVar9 = *(int *)(iVar8 + 0x160) - *(int *)(param_1 + 0x46c);
            iVar10 = 0;
            if (-1 < iVar9) {
              iVar10 = iVar9;
            }
            *(int *)(local_60 + *(int *)(iVar8 + 0x14c) * 4) = iVar10;
          }
          iVar8 = *(int *)(iVar8 + 8);
          iVar10 = *(int *)(iVar8 + 8);
        }
        local_70 = *(int *)(local_70 + 8);
      } while (*(int *)(local_70 + 8) != 0);
      iVar8 = *(int *)(param_1 + 8);
    }
  }
  *(int *)(param_1 + 0x468) = *(int *)(param_1 + 0x468) + 1;
  *(int *)(param_1 + 0x46c) = *(int *)(param_1 + 0x46c) + iVar6 * 4;
  local_24 = *(undefined4 *)(iVar8 + 0xbc);
  local_2c = 0;
  local_30 = 2;
  local_28 = FUN_001a7bca(local_24,8);
  local_20 = 0;
  local_44 = 1;
  local_40 = 0;
  iVar8 = *(int *)(param_1 + 0x3b8);
LAB_001436e9:
  do {
    if (*(uint *)(iVar8 + 4) < local_44) {
      iVar8 = *(int *)(param_1 + 0x378);
      if (*(int *)(iVar8 + 8) == 0) {
        local_55 = 1;
      }
      else {
        local_55 = 1;
        do {
          piVar7 = *(int **)(iVar8 + 0x98);
          iVar6 = piVar7[2];
          while (iVar6 != 0) {
            while ((((*(byte *)(piVar7 + 5) & 1) != 0 &&
                    (cVar5 = (**(code **)(*piVar7 + 0x34))(piVar7), cVar5 == '\0')) &&
                   (cVar5 = (**(code **)(*piVar7 + 0x38))(piVar7), cVar5 == '\0'))) {
              uVar4 = local_55;
              if ((param_2 != '\0') &&
                 (cVar5 = (**(code **)(*piVar7 + 0x48))(piVar7), cVar5 == '\0')) {
                iVar6 = piVar7[0x58] - *(int *)(param_1 + 0x46c);
                if (iVar6 < 0) {
                  iVar6 = 0;
                }
                uVar4 = 0;
                if (*(int *)(local_60 + piVar7[0x53] * 4) == iVar6) {
                  uVar4 = local_55;
                }
              }
              local_55 = uVar4;
              if (((*(int *)(param_1 + 0x468) == piVar7[0x54]) || ((piVar7[5] & 8U) != 0)) ||
                 (((piVar7[5] & 0x10U) != 0 ||
                  (((**(code **)(*piVar7 + 0x10))(piVar7,*(undefined4 *)(param_1 + 8)),
                   piVar7[0x26] == 2 || (piVar7[0x26] == 0x33)))))) break;
              piVar2 = (int *)(param_1 + 0x2b0 + iVar3 * 4);
              *piVar2 = *piVar2 + 1;
              piVar7 = (int *)piVar7[2];
              if (piVar7[2] == 0) goto LAB_0014388b;
            }
            piVar7 = (int *)piVar7[2];
            iVar6 = piVar7[2];
          }
LAB_0014388b:
          iVar8 = *(int *)(iVar8 + 8);
        } while (*(int *)(iVar8 + 8) != 0);
      }
      if (param_2 != '\0') {
        FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xbc),local_60);
      }
      FUN_001a7aba(local_24,local_28);
      return local_55;
    }
    local_20 = *(int *)(*(int *)(iVar8 + 8) + local_40);
    if ((*(byte *)(local_20 + 0x14) & 1) == 0) {
LAB_001438e1:
      local_44 = local_44 + 1;
      local_40 = local_40 + 4;
      goto LAB_001436e9;
    }
    iVar6 = FUN_0010b0f4(local_20,0);
    iVar8 = local_20;
    uVar1 = local_2c;
    if (*(int *)(iVar6 + 0x10) == DAT_001cc54c) {
      iVar8 = *(int *)(param_1 + 0x3b8);
      goto LAB_001438e1;
    }
    if (*(int *)(param_1 + 0x468) == *(int *)(local_20 + 0x150)) {
      iVar8 = *(int *)(param_1 + 0x3b8);
      local_44 = local_44 + 1;
      local_40 = local_40 + 4;
    }
    else {
      *(int *)(local_20 + 0x150) = *(int *)(param_1 + 0x468);
      if (local_2c < local_30) {
        iVar6 = local_2c * 4;
        _memset((void *)(iVar6 + local_28),0,4);
        local_2c = uVar1 + 1;
        piVar7 = (int *)(iVar6 + local_28);
      }
      else {
        piVar7 = (int *)FUN_001a7f7c(&local_30,local_2c);
      }
      local_6c = &local_30;
      *piVar7 = iVar8;
      do {
        while( true ) {
          uVar1 = local_2c - 1;
          if (uVar1 < local_2c) {
            piVar7 = (int *)(local_28 + uVar1 * 4);
          }
          else {
            piVar7 = (int *)0x0;
          }
          iVar8 = *piVar7;
          FUN_001a7f3c(local_6c,uVar1);
          if (0 < *(int *)(iVar8 + 0x84)) break;
          if (local_2c == 0) goto LAB_00143a8e;
        }
        local_4c = 1;
        do {
          iVar6 = FUN_0010b180(iVar8,local_4c);
          uVar1 = local_2c;
          if (iVar6 != 0) {
            if (*(int *)(param_1 + 0x46c) < *(int *)(iVar6 + 0x160)) {
              *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
            }
            else {
              *(int *)(iVar6 + 0x160) = *(int *)(param_1 + 0x46c) + 1;
            }
            if (*(int *)(param_1 + 0x468) != *(int *)(iVar6 + 0x150)) {
              *(int *)(iVar6 + 0x150) = *(int *)(param_1 + 0x468);
              if (local_2c < local_30) {
                iVar10 = local_2c * 4;
                _memset((void *)(iVar10 + local_28),0,4);
                local_2c = uVar1 + 1;
                piVar7 = (int *)(iVar10 + local_28);
              }
              else {
                piVar7 = (int *)FUN_001a7f7c(local_6c,local_2c);
              }
              *piVar7 = iVar6;
            }
          }
          local_4c = local_4c + 1;
        } while (local_4c <= *(int *)(iVar8 + 0x84));
      } while (local_2c != 0);
LAB_00143a8e:
      iVar8 = *(int *)(param_1 + 0x3b8);
      local_44 = local_44 + 1;
      local_40 = local_40 + 4;
    }
  } while( true );
}

/* FUN_00143b0c @ 0x143b0c (1109 bytes) */
int FUN_00143b0c(param_1)
  int param_1;
{
  uint uVar1;
  dword dVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  dword *pdVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  bool bVar10;
  uint local_54;
  int local_50;
  uint local_40;
  uint local_3c;
  int local_38;
  undefined4 local_34;
  uint local_30;
  uint local_2c;
  int local_28;
  undefined4 local_24;
  dword local_20;
  
  cVar3 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x1c);
  if ((((cVar3 == '\0') && (cVar3 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x1d), cVar3 == '\0'))
      && (cVar3 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x39), cVar3 == '\0')) &&
     (cVar3 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x1b), cVar3 == '\0')) {
    FUN_000e1c3e(*(undefined4 *)(param_1 + 8),
                 "Special : all peephole flags off -> bypass Rewrite()\n");
  }
  *(int *)(param_1 + 0x468) = *(int *)(param_1 + 0x468) + 1;
  local_24 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_2c = 0;
  local_30 = 2;
  local_28 = FUN_001a7bca(local_24,8);
  local_34 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_3c = 0;
  local_40 = 2;
  local_38 = FUN_001a7bca(local_34,8);
  local_20 = 0;
  local_54 = 1;
  local_50 = 0;
  iVar5 = *(int *)(param_1 + 0x3b8);
  if (*(int *)(iVar5 + 4) != 0) {
    do {
      uVar9 = local_2c;
      local_20 = *(dword *)(*(int *)(iVar5 + 8) + local_50);
      if ((*(byte *)(local_20 + 0x14) & 1) != 0) {
        if (local_2c < local_30) {
          iVar5 = local_2c * 4;
          _memset((void *)(iVar5 + local_28),0,4);
          local_2c = uVar9 + 1;
          *(undefined4 *)(iVar5 + local_28) = 0;
          if (local_40 <= local_3c) {
LAB_00143f4d:
            puVar4 = (undefined4 *)FUN_001a7f7c(&local_40,local_3c);
            goto LAB_00143c5e;
          }
        }
        else {
          puVar4 = (undefined4 *)FUN_001a7f7c(&local_30,local_2c);
          *puVar4 = 0;
          if (local_40 <= local_3c) goto LAB_00143f4d;
        }
        uVar9 = local_3c;
        iVar5 = local_3c * 4;
        _memset((void *)(iVar5 + local_38),0,4);
        local_3c = uVar9 + 1;
        puVar4 = (undefined4 *)(iVar5 + local_38);
LAB_00143c5e:
        *puVar4 = 0;
        bVar10 = true;
        uVar9 = local_2c;
LAB_00143c6c:
        if (uVar9 != 0) {
          do {
            if (bVar10) {
              if ((local_20 == 0) || (*(int *)(param_1 + 0x468) == *(int *)(local_20 + 0x150))) {
                bVar10 = false;
                goto LAB_00143c6c;
              }
              *(int *)(local_20 + 0x150) = *(int *)(param_1 + 0x468);
              iVar5 = FUN_0010b180(local_20,1);
              dVar2 = local_20;
              uVar9 = local_2c;
              if (iVar5 == 0) {
                if (local_2c - 1 < local_2c) {
                  puVar4 = (undefined4 *)(local_28 + (local_2c - 1) * 4);
                }
                else {
                  puVar4 = (undefined4 *)0x0;
                }
                uVar7 = *puVar4;
                goto LAB_00143e00;
              }
              if (local_2c < local_30) {
                iVar5 = local_2c * 4;
                _memset((void *)(iVar5 + local_28),0,4);
                local_2c = uVar9 + 1;
                pdVar6 = (dword *)(iVar5 + local_28);
              }
              else {
                pdVar6 = (dword *)FUN_001a7f7c(&local_30,local_2c);
              }
              *pdVar6 = dVar2;
              uVar7 = ((int (*)())FUN_00141a98)(local_20,&local_40,param_1);
            }
            else {
              uVar1 = uVar9 - 1;
              dVar2 = MACH_HEADER.magic;
              if (uVar1 < uVar9) {
                dVar2 = *(dword *)(local_28 + uVar1 * 4);
              }
              if (dVar2 == 0) {
                local_20 = dVar2;
                FUN_001a7f3c(&local_30,uVar1);
                FUN_001a7f3c(&local_40,local_3c - 1);
                bVar10 = false;
                uVar9 = local_2c;
                goto LAB_00143c6c;
              }
              bVar10 = local_20 == 0;
              local_20 = dVar2;
              if (bVar10) goto LAB_00143dc8;
              cVar3 = ((int (*)())FUN_00140928)(&local_40,*(undefined4 *)(dVar2 + 0x84));
              uVar9 = local_2c;
              if (cVar3 != '\0') goto LAB_00143dc8;
              uVar7 = ((int (*)())FUN_00141940)(&local_40);
            }
            local_20 = FUN_0010b180(local_20,uVar7);
            bVar10 = true;
            uVar9 = local_2c;
            if (local_2c == 0) break;
          } while( true );
        }
        iVar5 = *(int *)(param_1 + 0x3b8);
      }
      local_54 = local_54 + 1;
      local_50 = local_50 + 4;
    } while (local_54 <= *(uint *)(iVar5 + 4));
  }
  FUN_001a7aba(local_34,local_38);
  FUN_001a7aba(local_24,local_28);
  return;
LAB_00143dc8:
  FUN_001a7f3c(&local_30,uVar9 - 1);
  FUN_001a7f3c(&local_40,local_3c - 1);
  if (local_2c - 1 < local_2c) {
    puVar4 = (undefined4 *)(local_28 + (local_2c - 1) * 4);
  }
  else {
    puVar4 = (undefined4 *)0x0;
  }
  uVar7 = *puVar4;
LAB_00143e00:
  uVar8 = ((int (*)())FUN_001409b0)(&local_40);
  ((int (*)())FUN_0014138e)(local_20,uVar7,uVar8,param_1);
  bVar10 = false;
  uVar9 = local_2c;
  goto LAB_00143c6c;
}

/* FUN_00143f94 @ 0x143f94 (1232 bytes) */
int FUN_00143f94(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  bool bVar3;
  dword dVar4;
  char cVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  undefined4 *puVar10;
  dword *pdVar11;
  uint local_44;
  int local_40;
  uint local_30;
  uint local_2c;
  int local_28;
  undefined4 local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  undefined4 local_14;
  dword local_10;
  
  *(int *)(param_1 + 0x468) = *(int *)(param_1 + 0x468) + 1;
  local_14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_1c = 0;
  local_20 = 2;
  local_18 = FUN_001a7bca(local_14,8);
  local_24 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_2c = 0;
  local_30 = 2;
  local_28 = FUN_001a7bca(local_24,8);
  local_10 = 0;
  local_44 = 1;
  local_40 = 0;
  iVar7 = *(int *)(param_1 + 0x3b8);
  if (*(int *)(iVar7 + 4) != 0) {
    do {
      uVar9 = local_1c;
      local_10 = *(dword *)(local_40 + *(int *)(iVar7 + 8));
      if ((*(byte *)(local_10 + 0x14) & 1) != 0) {
        if (local_1c < local_20) {
          iVar7 = local_1c * 4;
          _memset((void *)(iVar7 + local_18),0,4);
          local_1c = uVar9 + 1;
          *(undefined4 *)(iVar7 + local_18) = 0;
          if (local_2c < local_30) goto LAB_00144093;
LAB_00144450:
          puVar6 = (undefined4 *)FUN_001a7f7c(&local_30,local_2c);
        }
        else {
          puVar6 = (undefined4 *)FUN_001a7f7c(&local_20,local_1c);
          *puVar6 = 0;
          if (local_30 <= local_2c) goto LAB_00144450;
LAB_00144093:
          uVar9 = local_2c;
          iVar7 = local_2c * 4;
          _memset((void *)(iVar7 + local_28),0,4);
          local_2c = uVar9 + 1;
          puVar6 = (undefined4 *)(iVar7 + local_28);
        }
        *puVar6 = 0;
        bVar3 = true;
        uVar9 = local_1c;
LAB_001440d0:
        if (uVar9 != 0) {
          while (bVar3) {
            if (local_10 == 0) {
LAB_001442f2:
              bVar3 = false;
              goto LAB_001440d0;
            }
            cVar5 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x14);
            if (cVar5 != '\0') {
              local_10 = FUN_00152de4(local_10,*(undefined4 *)(param_1 + 8));
            }
            uVar9 = local_1c;
            if (*(int *)(param_1 + 0x468) == *(int *)(local_10 + 0x150)) goto LAB_001442f2;
            *(int *)(local_10 + 0x150) = *(int *)(param_1 + 0x468);
            iVar7 = FUN_0010b180(local_10,1);
            dVar4 = local_10;
            uVar9 = local_1c;
            if (iVar7 == 0) goto LAB_00144372;
            if (local_1c < local_20) {
              iVar7 = local_1c * 4;
              _memset((void *)(iVar7 + local_18),0,4);
              local_1c = uVar9 + 1;
              *(dword *)(iVar7 + local_18) = dVar4;
              if (local_2c < local_30) goto LAB_00144194;
LAB_0014441b:
              puVar6 = (undefined4 *)FUN_001a7f7c(&local_30,local_2c);
            }
            else {
              pdVar11 = (dword *)FUN_001a7f7c(&local_20,local_1c);
              *pdVar11 = dVar4;
              if (local_30 <= local_2c) goto LAB_0014441b;
LAB_00144194:
              uVar9 = local_2c;
              iVar7 = local_2c * 4;
              _memset((void *)(iVar7 + local_28),0,4);
              local_2c = uVar9 + 1;
              puVar6 = (undefined4 *)(iVar7 + local_28);
            }
            *puVar6 = 1;
            local_10 = FUN_0010b180(local_10,1);
LAB_001441dc:
            bVar3 = true;
            uVar9 = local_1c;
            if (local_1c == 0) goto LAB_001441ef;
          }
          uVar1 = uVar9 - 1;
          dVar4 = MACH_HEADER.magic;
          if (uVar1 < uVar9) {
            dVar4 = *(dword *)(local_18 + uVar1 * 4);
          }
          if (dVar4 == 0) {
            local_10 = dVar4;
            FUN_001a7f3c(&local_20,uVar1);
            FUN_001a7f3c(&local_30,local_2c - 1);
            bVar3 = false;
            uVar9 = local_1c;
            goto LAB_001440d0;
          }
          if (local_10 != 0) {
            uVar9 = local_2c - 1;
            if (uVar9 < local_2c) {
              if (*(int *)(local_28 + uVar9 * 4) != *(int *)(dVar4 + 0x84)) goto LAB_0014427a;
            }
            else if (MACH_HEADER.magic != *(dword *)(dVar4 + 0x84)) {
LAB_0014427a:
              if (uVar9 < local_2c) {
                piVar8 = (int *)(local_28 + uVar9 * 4);
              }
              else {
                piVar8 = (int *)0x0;
              }
              iVar7 = *piVar8;
              local_10 = dVar4;
              FUN_001a7f3c(&local_30,uVar9);
              uVar9 = local_2c;
              if (local_2c < local_30) {
                iVar2 = local_2c * 4;
                _memset((void *)(iVar2 + local_28),0,4);
                local_2c = uVar9 + 1;
                piVar8 = (int *)(iVar2 + local_28);
              }
              else {
                piVar8 = (int *)FUN_001a7f7c(&local_30,local_2c);
              }
              *piVar8 = iVar7 + 1;
              local_10 = FUN_0010b180(local_10,iVar7 + 1);
              goto LAB_001441dc;
            }
          }
          local_10 = dVar4;
          FUN_001a7f3c(&local_20,uVar1);
          FUN_001a7f3c(&local_30,local_2c - 1);
LAB_00144372:
          if (local_2c - 1 < local_2c) {
            puVar6 = (undefined4 *)(local_28 + (local_2c - 1) * 4);
          }
          else {
            puVar6 = (undefined4 *)0x0;
          }
          if (local_1c - 1 < local_1c) {
            puVar10 = (undefined4 *)(local_18 + (local_1c - 1) * 4);
          }
          else {
            puVar10 = (undefined4 *)0x0;
          }
          ((int (*)())FUN_001407e0)(local_10,*puVar10,*puVar6,param_1);
          bVar3 = false;
          uVar9 = local_1c;
          goto LAB_001440d0;
        }
LAB_001441ef:
        iVar7 = *(int *)(param_1 + 0x3b8);
      }
      local_44 = local_44 + 1;
      local_40 = local_40 + 4;
    } while (local_44 <= *(uint *)(iVar7 + 4));
  }
  FUN_001a7aba(local_24,local_28);
  FUN_001a7aba(local_14,local_18);
  return;
}

/* FUN_00144496 @ 0x144496 (70 bytes) */
int FUN_00144496(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1[0x22] + 8) == 0x8e) {
    iVar1 = (**(code **)(*param_1 + 0x7c))(param_1);
    return *(undefined4 *)(iVar1 + 300);
  }
  if ((*(byte *)((int)param_1 + 0x15) & 2) == 0) {
    return 0;
  }
  uVar2 = FUN_0010b180(param_1,param_1[0x21]);
  return uVar2;
}

/* FUN_001444dc @ 0x1444dc (1705 bytes) */
int FUN_001444dc(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int *piVar10;
  int *piVar11;
  bool bVar12;
  undefined4 local_64;
  int local_5c;
  int local_50;
  int local_4c;
  int local_40;
  int local_2c;
  int local_28;
  
  cVar3 = FUN_000eacec(param_1);
  if (((cVar3 != '\0') && (cVar3 = (**(code **)(*param_1 + 0x40))(param_1), cVar3 == '\0')) &&
     ((iVar4 = FUN_000e9644(param_1), *(int *)(*(int *)(iVar4 + 0x88) + 8) == 0x8b ||
      (iVar4 = FUN_000e9644(param_1), *(int *)(*(int *)(iVar4 + 0x88) + 8) == 0x8c)))) {
    iVar4 = param_1[0x4b];
    iVar1 = param_1[0x4c];
    iVar2 = param_1[0x4d];
    piVar11 = *(int **)(iVar2 + 0x98);
    if (piVar11[2] == 0) {
      local_5c = 0;
      local_4c = 0;
      local_50 = 2;
    }
    else {
      local_5c = 0;
      local_50 = 0;
      local_4c = 0;
      do {
        if (((((*(byte *)(piVar11 + 5) & 1) != 0) &&
             (cVar3 = (**(code **)(*piVar11 + 0x34))(piVar11), cVar3 == '\0')) &&
            (cVar3 = (**(code **)(*piVar11 + 0x38))(piVar11), cVar3 == '\0')) &&
           (*(int *)(piVar11[0x22] + 8) == 0x8e)) {
          local_5c = local_5c + 1;
          piVar5 = (int *)FUN_0010b180(piVar11,1);
          if ((iVar4 == piVar5[0x56]) &&
             (cVar3 = (**(code **)(*piVar5 + 100))(piVar5), cVar3 != '\0')) {
            for (local_2c = 1; iVar6 = (**(code **)(*piVar5 + 0x14))(piVar5), local_2c <= iVar6;
                local_2c = local_2c + 1) {
              if ((((piVar5[local_2c * 6 + 0x28] & 1U) != 0) ||
                  ((piVar5[local_2c * 6 + 0x28] & 2U) != 0)) ||
                 (cVar3 = FUN_000f5a1e(piVar5,local_2c), cVar3 == '\0')) goto LAB_001445e1;
            }
            if (((char)piVar5[0x48] != '\0') || (piVar5[0x49] != 0)) goto LAB_001445e1;
            if ((piVar5[0x20] != 0) &&
               (((cVar3 = FUN_0012dfd8(piVar5[0x26]), cVar3 != '\0' &&
                 ((*(byte *)(piVar5 + 5) & 2) == 0)) &&
                (cVar3 = (**(code **)(*piVar5 + 0x50))(piVar5), cVar3 == '\0')))) {
              iVar6 = 4;
              piVar10 = piVar5;
              do {
                if ((byte)((char)piVar10[0x27] - 2U) < 2) goto LAB_001445e1;
                piVar10 = (int *)((int)piVar10 + 1);
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
            }
            FUN_0010b0f4(piVar5,0);
            iVar6 = FUN_0010b7c8(piVar5,0);
            if (((iVar6 != 0) || ((piVar5[5] & 2U) != 0)) ||
               (((piVar5[5] & 0x200U) != 0 || (*(int *)(piVar5[4] + 4) != 1)))) goto LAB_001445e1;
            local_50 = local_50 + 1;
            bVar12 = true;
          }
          else {
LAB_001445e1:
            cVar3 = ((int (*)())FUN_00140838)(piVar5,param_1,iVar4,iVar1);
            bVar12 = cVar3 != '\0';
          }
          piVar5 = (int *)FUN_0010b180(piVar11,2);
          if ((iVar1 == piVar5[0x56]) &&
             (cVar3 = (**(code **)(*piVar5 + 100))(piVar5), cVar3 != '\0')) {
            for (local_28 = 1; iVar6 = (**(code **)(*piVar5 + 0x14))(piVar5), local_28 <= iVar6;
                local_28 = local_28 + 1) {
              if ((((piVar5[local_28 * 6 + 0x28] & 1U) != 0) ||
                  ((piVar5[local_28 * 6 + 0x28] & 2U) != 0)) ||
                 (cVar3 = FUN_000f5a1e(piVar5,local_28), cVar3 == '\0')) goto LAB_00144626;
            }
            if (((char)piVar5[0x48] != '\0') || (piVar5[0x49] != 0)) goto LAB_00144626;
            if (((piVar5[0x20] != 0) &&
                ((cVar3 = FUN_0012dfd8(piVar5[0x26]), cVar3 != '\0' &&
                 ((*(byte *)(piVar5 + 5) & 2) == 0)))) &&
               (cVar3 = (**(code **)(*piVar5 + 0x50))(piVar5), cVar3 == '\0')) {
              iVar6 = 4;
              piVar10 = piVar5;
              do {
                if ((byte)((char)piVar10[0x27] - 2U) < 2) goto LAB_00144626;
                piVar10 = (int *)((int)piVar10 + 1);
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
            }
            FUN_0010b0f4(piVar5,0);
            iVar6 = FUN_0010b7c8(piVar5,0);
            if ((((iVar6 != 0) || ((piVar5[5] & 2U) != 0)) || ((piVar5[5] & 0x200U) != 0)) ||
               (*(int *)(piVar5[4] + 4) != 1)) goto LAB_00144626;
            local_4c = local_4c + 1;
          }
          else {
LAB_00144626:
            cVar3 = ((int (*)())FUN_00140838)(piVar5,param_1,iVar4,iVar1);
            if (cVar3 == '\0') {
              return;
            }
          }
          if (!bVar12) {
            return;
          }
        }
        piVar11 = (int *)piVar11[2];
      } while (piVar11[2] != 0);
      local_50 = local_50 + 2;
    }
    iVar6 = FUN_001a7d8a(iVar4 + 0x90);
    if (((local_50 == iVar6) && (iVar6 = FUN_001a7d8a(iVar1 + 0x90), iVar6 == local_4c + 2)) &&
       (local_5c != 0)) {
      uVar7 = FUN_000eac0c(param_1,0);
      local_40 = FUN_000e9644(param_1);
      local_64 = DAT_001cc554;
      if (*(int *)(*(int *)(local_40 + 0x88) + 8) == 0x8c) {
        iVar6 = FUN_0010b0f4(local_40,1);
        local_64 = *(undefined4 *)(iVar6 + 0x10);
        FUN_000f1b60(param_2,local_40);
        bVar12 = *(int *)(local_40 + 300) != 7;
        local_40 = FUN_0010b180(local_40,1);
      }
      else {
        FUN_0011286e(local_40,param_3);
        FUN_000e9512(uVar7,local_40);
        bVar12 = false;
      }
      piVar11 = *(int **)(iVar2 + 0x98);
      for (piVar5 = (int *)piVar11[2]; piVar5 != (int *)0x0; piVar5 = (int *)piVar5[2]) {
        cVar3 = (**(code **)(*piVar11 + 0x34))(piVar11);
        if ((cVar3 == '\0') && (cVar3 = (**(code **)(*piVar11 + 0x38))(piVar11), cVar3 == '\0')) {
          if (*(int *)(piVar11[0x22] + 8) == 0x8e) {
            uVar8 = FUN_0010b180(piVar11,1);
            uVar9 = FUN_0010b180(piVar11,2);
            cVar3 = ((int (*)())FUN_00140838)(uVar8,param_1,iVar4,iVar1);
            if (cVar3 == '\0') {
              FUN_001a7d72(uVar8);
              FUN_000e9512(uVar7,uVar8);
            }
            cVar3 = ((int (*)())FUN_00140838)(uVar9,param_1,iVar4,iVar1);
            if (cVar3 == '\0') {
              FUN_001a7d72(uVar9);
              FUN_000e9512(uVar7,uVar9);
            }
            FUN_00112ba2(piVar11,local_40,local_64,param_3);
            if ((*(int *)(piVar11[0x22] + 8) != 0x31) && (bVar12)) {
              FUN_0010fe82(piVar11,2,3,param_3);
            }
            FUN_000e9512(uVar7,piVar11);
          }
          else {
            FUN_001a7d72(piVar11);
            FUN_000e9512(uVar7,piVar11);
          }
        }
        piVar11 = piVar5;
      }
    }
  }
  return;
}

/* FUN_00144b86 @ 0x144b86 (653 bytes) */
int FUN_00144b86(param_1)
  int param_1;
{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  cVar3 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x13);
  if (cVar3 != '\0') {
    cVar3 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x17);
    if (cVar3 != '\0') {
      FUN_001266e2(param_1);
    }
    ((int (*)())FUN_00143f94)(param_1);
    local_20 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
    local_28 = 0;
    local_2c = 2;
    local_24 = FUN_001a7bca(local_20,8);
    piVar5 = *(int **)(param_1 + 0x378);
    if (piVar5[2] != 0) {
      do {
        while (cVar3 = (**(code **)(*piVar5 + 0x24))(piVar5), cVar3 != '\0') {
          iVar4 = *(int *)(param_1 + 0x468) + 1;
          *(int *)(param_1 + 0x468) = iVar4;
          ((int (*)())FUN_00141682)(piVar5,&local_2c,iVar4);
          piVar5 = (int *)piVar5[2];
          if (piVar5[2] == 0) goto LAB_00144c62;
        }
        piVar5 = (int *)piVar5[2];
      } while (piVar5[2] != 0);
    }
LAB_00144c62:
    cVar3 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x18);
    if (((cVar3 != '\0') && (cVar3 = FUN_000e144e(*(undefined4 *)(param_1 + 8),0,3), cVar3 == '\0'))
       && ((*(byte *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 10) & 2) == 0)) {
      ((int (*)())FUN_00140bf8)(param_1);
      ((int (*)())FUN_00142c48)(param_1);
    }
    FUN_001a7aba(local_20,local_24);
  }
  piVar5 = *(int **)(*(int *)(param_1 + 8) + 0x54);
  (**(code **)(*piVar5 + 0x110))(piVar5,param_1);
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xffffff7f;
  cVar3 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x19);
  if (cVar3 != '\0') {
    piVar5 = *(int **)(param_1 + 0x378);
    piVar1 = (int *)piVar5[2];
    if (piVar1 != (int *)0x0) {
      cVar3 = (**(code **)(*piVar5 + 0x24))(piVar5);
      while( true ) {
        if (cVar3 != '\0') {
          ((int (*)())FUN_001444dc)(piVar5,param_1,*(undefined4 *)(param_1 + 8));
        }
        piVar2 = (int *)piVar1[2];
        if (piVar2 == (int *)0x0) break;
        cVar3 = (**(code **)(*piVar1 + 0x24))(piVar1);
        piVar5 = piVar1;
        piVar1 = piVar2;
      }
    }
  }
  cVar3 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x37);
  if (cVar3 != '\0') {
    FUN_00117f44(param_1);
  }
  ((int (*)())FUN_00143b0c)(param_1);
  ((int (*)())FUN_00143642)(param_1,0);
  FUN_000f0346(param_1,"rewrite");
  cVar3 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x1f);
  if (cVar3 != '\0') {
    FUN_00135ca0(param_1);
  }
  return;
}

/* FUN_00144e30 @ 0x144e30 (1306 bytes) */
int FUN_00144e30(param_1)
  int param_1;
{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  char cVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int local_4c;
  int local_48;
  int local_34;
  int *local_24;
  
  iVar1 = *(int *)(param_1 + 0x378);
  iVar7 = *(int *)(iVar1 + 8);
  while (iVar7 != 0) {
    piVar2 = *(int **)(iVar1 + 0x98);
    iVar7 = piVar2[2];
    while (iVar7 != 0) {
      if ((*(byte *)(piVar2 + 5) & 1) != 0) {
        piVar6 = (int *)(**(code **)(*piVar2 + 0x7c))(piVar2);
        if ((((piVar6 != (int *)0x0) && (piVar6[0x20] != 0)) &&
            (cVar5 = FUN_0012dfd8(piVar6[0x26]), cVar5 != '\0')) &&
           ((((*(byte *)(piVar6 + 5) & 2) == 0 &&
             (cVar5 = (**(code **)(*piVar6 + 0x50))(piVar6), cVar5 == '\0')) &&
            ((*(byte *)(piVar6 + 5) & 0x40) == 0)))) {
          iVar7 = FUN_0010a1c2(piVar6,*(undefined4 *)(param_1 + 8),0);
          *(undefined4 *)(iVar7 + 0x9c) = DAT_001cc56c;
          *(undefined4 *)(iVar7 + 0x94) = *(undefined4 *)(iVar7 + 0x14c);
          FUN_000e956e(iVar1,piVar6,iVar7);
          iVar9 = FUN_0010a1c2(piVar6,*(undefined4 *)(param_1 + 8),0);
          *(undefined4 *)(iVar9 + 0x9c) = DAT_001cc568;
          *(undefined4 *)(iVar9 + 0x94) = *(undefined4 *)(iVar9 + 0x14c);
          FUN_000e956e(iVar1,piVar6,iVar9);
          iVar8 = FUN_0010a1c2(piVar6,*(undefined4 *)(param_1 + 8),0);
          *(undefined4 *)(iVar8 + 0x9c) = DAT_001cc564;
          *(undefined4 *)(iVar8 + 0x94) = *(undefined4 *)(iVar8 + 0x14c);
          FUN_000e956e(iVar1,piVar6,iVar8);
          piVar6[0x27] = DAT_001cc560;
          *(undefined4 *)(iVar7 + 300) = 0;
          *(int *)(iVar9 + 300) = iVar7;
          *(int *)(iVar8 + 300) = iVar9;
          piVar6[0x4b] = iVar8;
        }
        cVar5 = (**(code **)(*piVar2 + 0x24))(piVar2);
        if (((cVar5 != '\0') && (piVar2[0x20] != 0)) &&
           ((cVar5 = FUN_0012dfd8(piVar2[0x26]), cVar5 != '\0' &&
            ((((*(byte *)(piVar2 + 5) & 2) == 0 &&
              (cVar5 = (**(code **)(*piVar2 + 0x50))(piVar2), cVar5 == '\0')) &&
             (iVar7 = FUN_001192a8(*(undefined4 *)(piVar2[0x22] + 8),*(undefined4 *)(param_1 + 8)),
             iVar7 == 0)))))) {
          cVar5 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x32);
          if (cVar5 == '\0') {
            cVar5 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x30);
            if (cVar5 != '\0') {
              iVar7 = FUN_0010b0f4(piVar2,0);
              uVar3 = *(uint *)(iVar7 + 0x10);
              cVar5 = FUN_000f57b4(uVar3);
              if (cVar5 == '\0') {
                iVar7 = FUN_0010a1c2(piVar2,*(undefined4 *)(param_1 + 8),0);
                *(uint *)(iVar7 + 0x9c) = uVar3 & 0xffffff | 0x1000000;
                uVar4 = *(undefined4 *)(iVar7 + 0x14c);
                iVar9 = FUN_0010b0f4(iVar7,0);
                *(undefined4 *)(iVar9 + 8) = uVar4;
                piVar2[0x27] = DAT_001cc55c;
                FUN_0010c18e(piVar2,iVar7,0,*(undefined4 *)(param_1 + 8));
                FUN_000e956e(iVar1,piVar2,iVar7);
                local_34 = 1;
                while (iVar7 = (**(code **)(*piVar2 + 0x14))(piVar2), local_34 <= iVar7) {
                  piVar6 = (int *)FUN_0010b180(piVar2,local_34);
                  cVar5 = (**(code **)(*piVar6 + 0x5c))(piVar6);
                  if (cVar5 == '\0') {
                    local_34 = local_34 + 1;
                  }
                  else {
                    iVar7 = FUN_0010a1c2(piVar6,*(undefined4 *)(param_1 + 8),0);
                    uVar4 = *(undefined4 *)(iVar7 + 0x14c);
                    iVar9 = FUN_0010b0f4(iVar7,0);
                    *(undefined4 *)(iVar9 + 8) = uVar4;
                    FUN_000e9596(piVar6[0x56],piVar6,iVar7);
                    FUN_0010ba02(piVar2,local_34,iVar7,0,*(undefined4 *)(param_1 + 8));
                    local_34 = local_34 + 1;
                  }
                }
              }
            }
          }
          else {
            local_4c = FUN_000f60f4(piVar2);
            if (1 < local_4c) {
              local_48 = 0;
              local_24 = (int *)PTR_DAT_0021345d;
              do {
                iVar7 = FUN_0010b0f4(piVar2,0);
                if (*(char *)(local_48 + 0x10 + iVar7) != '\x01') {
                  if (local_4c < 2) {
                    piVar2[0x27] = *local_24;
                    FUN_000f5d78(piVar2);
                  }
                  else {
                    iVar7 = FUN_0010a1c2(piVar2,*(undefined4 *)(param_1 + 8),0);
                    *(int *)(iVar7 + 0x9c) = *local_24;
                    FUN_000e956e(iVar1,piVar2,iVar7);
                    if ((*(byte *)((int)piVar2 + 0x15) & 2) != 0) {
                      uVar4 = *(undefined4 *)(param_1 + 8);
                      uVar10 = FUN_0010b180(piVar2,piVar2[0x21]);
                      FUN_0010c18e(iVar7,uVar10,0,uVar4);
                    }
                    FUN_0010c18e(piVar2,iVar7,0,*(undefined4 *)(param_1 + 8));
                  }
                  local_4c = local_4c + -1;
                }
                local_48 = local_48 + 1;
                local_24 = local_24 + 1;
              } while (local_48 != 4);
            }
          }
        }
      }
      piVar2 = (int *)piVar2[2];
      iVar7 = piVar2[2];
    }
    iVar1 = *(int *)(iVar1 + 8);
    iVar7 = *(int *)(iVar1 + 8);
  }
  return;
}

/* FUN_0014534a @ 0x14534a (506 bytes) */
int FUN_0014534a(param_1, param_2)
  int *param_1;
  int param_2;
{
  float fVar1;
  byte bVar2;
  undefined4 uVar3;
  char cVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int local_34;
  int local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  uVar3 = *(undefined4 *)(param_2 + 8);
  cVar4 = (**(code **)(*param_1 + 100))(param_1);
  if ((cVar4 != '\0') && ((*(byte *)((int)param_1 + 0x15) & 2) != 0)) {
    piVar5 = (int *)FUN_0010b180(param_1,1);
    piVar6 = (int *)FUN_0010b180(param_1,param_1[0x21]);
    cVar4 = (**(code **)(*piVar5 + 0x48))(piVar5);
    if ((cVar4 != '\0') && (cVar4 = (**(code **)(*piVar6 + 0x2c))(piVar6), cVar4 != '\0')) {
      iVar7 = FUN_0010b0f4(piVar6,0);
      local_20[0] = *(undefined4 *)(iVar7 + 0x10);
      iVar7 = FUN_0010b0f4(param_1,0);
      local_24 = *(undefined4 *)(iVar7 + 0x10);
      local_28 = piVar6[0x50];
      local_34 = 0;
      do {
        cVar4 = *(char *)((int)local_20 + local_34 + -4);
        if (cVar4 == '\0') {
          if (*(char *)((int)local_20 + local_34) != '\0') {
            return;
          }
          iVar7 = FUN_0010b0f4(param_1,1);
          bVar2 = *(byte *)(local_34 + 0x10 + iVar7);
          if (((int)(char)piVar5[0x57] >> (bVar2 & 0x1f) & 1U) == 0) {
            return;
          }
          if (piVar5[(uint)bVar2 * 6 + 7] != 2) {
            return;
          }
          fVar1 = (float)piVar5[(uint)bVar2 * 6 + 8];
          if (((fVar1 != FLOAT_001c5b9c) || (NAN(fVar1) || NAN(FLOAT_001c5b9c))) ||
             (*(char *)((int)&local_28 + local_34) != '\x05')) {
            if (fVar1 != FLOAT_001c5ba4) {
              return;
            }
            if (NAN(fVar1) || NAN(FLOAT_001c5ba4)) {
              return;
            }
            if (*(char *)((int)&local_28 + local_34) != '\x03') {
              return;
            }
          }
        }
        else if (cVar4 != '\x01') {
          return;
        }
        local_34 = local_34 + 1;
      } while (local_34 != 4);
      FUN_0010ba02(param_1,1,piVar6,0,uVar3);
      param_1[0x27] = DAT_001cc540;
      iVar7 = FUN_0010b0f4(param_1,1);
      *(undefined4 *)(iVar7 + 0x10) = DAT_001cc53c;
      FUN_0010ba02(param_1,param_1[0x21],0,0,*(undefined4 *)(param_2 + 8));
      param_1[0x21] = param_1[0x21] + -1;
      param_1[5] = param_1[5] & 0xfffffdff;
    }
  }
  return;
}

/* FUN_00145544 @ 0x145544 (7692 bytes) */
int FUN_00145544(param_1)
  int param_1;
{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  char cVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uint uVar16;
  uint *puVar17;
  int local_12c;
  uint local_128;
  uint local_11c;
  uint local_118;
  int local_100;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_d8;
  int local_d4;
  uint *local_a8;
  uint local_a4;
  int local_a0;
  uint local_98;
  int local_84;
  int local_7c;
  int *local_78;
  uint local_70;
  int local_6c;
  uint local_68;
  int local_64;
  uint local_60;
  int local_5c;
  uint local_58;
  int local_54;
  uint local_48;
  uint local_44;
  int local_40;
  undefined4 local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  int local_20 [4];
  
  cVar4 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x4e);
  if (cVar4 == '\0') {
    cVar4 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x4f);
    if (cVar4 == '\0') goto LAB_001456a5;
    local_3c = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
    local_44 = 0;
    local_48 = 2;
    local_40 = FUN_001a7bca(local_3c,8);
    local_28 = 0;
    local_58 = 1;
    local_54 = 0;
    iVar10 = *(int *)(param_1 + 0x3b8);
    for (; uVar16 = local_44, local_58 <= *(uint *)(iVar10 + 4); local_58 = local_58 + 1) {
      iVar11 = *(int *)(local_54 + *(int *)(iVar10 + 8));
      local_28 = iVar11;
      if (((*(byte *)(iVar11 + 0x14) & 1) != 0) && (*(int *)(iVar11 + 0x98) == 6)) {
        if (local_44 < local_48) {
          iVar10 = local_44 * 4;
          _memset((void *)(iVar10 + local_40),0,4);
          local_44 = uVar16 + 1;
          piVar5 = (int *)(iVar10 + local_40);
        }
        else {
          piVar5 = (int *)FUN_001a7f7c(&local_48,local_44);
        }
        *piVar5 = iVar11;
        *(uint *)(local_28 + 0x14) = *(uint *)(local_28 + 0x14) & 0xfffffff7;
        *(uint *)(local_28 + 0x14) = *(uint *)(local_28 + 0x14) & 0xffffffef;
        iVar10 = *(int *)(param_1 + 0x3b8);
      }
      local_54 = local_54 + 4;
    }
    while (local_44 != 0) {
      uVar16 = local_44 - 1;
      if (uVar16 < local_44) {
        puVar6 = (undefined4 *)(local_40 + uVar16 * 4);
      }
      else {
        puVar6 = (undefined4 *)0x0;
      }
      uVar14 = *puVar6;
      FUN_001a7f3c(&local_48,uVar16);
      FUN_000f1b60(param_1,uVar14);
    }
  }
  else {
    local_3c = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
    local_44 = 0;
    local_48 = 2;
    local_40 = FUN_001a7bca(local_3c,8);
    local_28 = 0;
    local_60 = 1;
    local_5c = 0;
    iVar10 = *(int *)(param_1 + 0x3b8);
    for (; uVar16 = local_44, local_60 <= *(uint *)(iVar10 + 4); local_60 = local_60 + 1) {
      iVar11 = *(int *)(local_5c + *(int *)(iVar10 + 8));
      local_28 = iVar11;
      if (((*(byte *)(iVar11 + 0x14) & 1) != 0) && (*(int *)(iVar11 + 0x98) != 6)) {
        if (local_44 < local_48) {
          iVar10 = local_44 * 4;
          _memset((void *)(iVar10 + local_40),0,4);
          local_44 = uVar16 + 1;
          piVar5 = (int *)(iVar10 + local_40);
        }
        else {
          piVar5 = (int *)FUN_001a7f7c(&local_48,local_44);
        }
        *piVar5 = iVar11;
        *(uint *)(local_28 + 0x14) = *(uint *)(local_28 + 0x14) & 0xfffffff7;
        *(uint *)(local_28 + 0x14) = *(uint *)(local_28 + 0x14) & 0xffffffef;
        iVar10 = *(int *)(param_1 + 0x3b8);
      }
      local_5c = local_5c + 4;
    }
    while (local_44 != 0) {
      uVar16 = local_44 - 1;
      if (uVar16 < local_44) {
        puVar6 = (undefined4 *)(local_40 + uVar16 * 4);
      }
      else {
        puVar6 = (undefined4 *)0x0;
      }
      uVar14 = *puVar6;
      FUN_001a7f3c(&local_48,uVar16);
      FUN_000f1b60(param_1,uVar14);
    }
  }
  FUN_001a7aba(local_3c,local_40);
LAB_001456a5:
  local_2c = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_34 = 0;
  local_38 = 2;
  local_30 = FUN_001a7bca(local_2c,8);
  iVar10 = *(int *)(*(int *)(param_1 + 8) + 0x68) * 4;
  iVar7 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 8) + 0xbc),iVar10);
  iVar8 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 8) + 0xbc),iVar10);
  iVar10 = *(int *)(param_1 + 0x378);
  iVar11 = *(int *)(iVar10 + 8);
  while (iVar11 != 0) {
    piVar5 = *(int **)(iVar10 + 0x98);
    iVar11 = piVar5[2];
    while (iVar11 != 0) {
      while ((*(byte *)(piVar5 + 5) & 1) == 0) {
        piVar5 = (int *)piVar5[2];
        if (piVar5[2] == 0) goto LAB_0014581c;
      }
      *(int *)(iVar7 + piVar5[0x53] * 4) = piVar5[0x53];
      *(undefined4 *)(iVar8 + piVar5[0x53] * 4) = 0;
      cVar4 = (**(code **)(*piVar5 + 0x48))(piVar5);
      if (cVar4 != '\0') {
        piVar5[0x27] = DAT_001cc540;
      }
      piVar5[3] = 0;
      ((int (*)())FUN_0014534a)(piVar5,param_1);
      uVar14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
      puVar6 = (undefined4 *)FUN_001a7bca(uVar14,0x14);
      *puVar6 = uVar14;
      puVar6[4] = uVar14;
      puVar6[2] = 0;
      puVar6[1] = 2;
      uVar14 = FUN_001a7bca(uVar14,8);
      puVar6[3] = uVar14;
      piVar5[4] = (int)(puVar6 + 1);
      piVar5 = (int *)piVar5[2];
      iVar11 = piVar5[2];
    }
LAB_0014581c:
    iVar10 = *(int *)(iVar10 + 8);
    iVar11 = *(int *)(iVar10 + 8);
  }
  local_28 = 0;
  local_68 = 1;
  local_64 = 0;
  iVar10 = *(int *)(param_1 + 0x3b8);
  if (*(int *)(iVar10 + 4) != 0) {
    do {
      iVar11 = *(int *)(local_64 + *(int *)(iVar10 + 8));
      local_28 = iVar11;
      if ((*(byte *)(iVar11 + 0x14) & 1) != 0) {
        iVar10 = FUN_0010b0f4(iVar11,0);
        uVar14 = FUN_000f5fea(*(undefined4 *)(iVar10 + 0x10));
        iVar10 = local_28;
        uVar16 = local_34;
        *(undefined4 *)(iVar11 + 0xc) = uVar14;
        if (local_34 < local_38) {
          iVar11 = local_34 * 4;
          _memset((void *)(iVar11 + local_30),0,4);
          local_34 = uVar16 + 1;
          piVar5 = (int *)(iVar11 + local_30);
        }
        else {
          piVar5 = (int *)FUN_001a7f7c(&local_38,local_34);
        }
        *piVar5 = iVar10;
        iVar10 = *(int *)(param_1 + 0x3b8);
      }
      local_68 = local_68 + 1;
      local_64 = local_64 + 4;
    } while (local_68 <= *(uint *)(iVar10 + 4));
  }
  while (local_34 != 0) {
    while( true ) {
      uVar16 = local_34 - 1;
      if (uVar16 < local_34) {
        piVar5 = (int *)(local_30 + uVar16 * 4);
      }
      else {
        piVar5 = (int *)0x0;
      }
      piVar5 = (int *)*piVar5;
      FUN_001a7f3c(&local_38,uVar16);
      cVar4 = (**(code **)(*piVar5 + 0x30))(piVar5);
      if (((cVar4 != '\0') && (-1 < piVar5[0x4d])) &&
         (*(int *)(*(int *)(param_1 + 0x78) + 4 + piVar5[0x4d] * 0xc) - 10U < 2)) {
        uVar14 = FUN_0010b180(piVar5,1);
        piVar9 = (int *)((int (*)())FUN_0013fbf0)(uVar14,3,&local_28);
        if ((piVar9 != (int *)0x0) && (cVar4 = (**(code **)(*piVar9 + 0x50))(piVar9), cVar4 != '\0')
           ) {
          (**(code **)(*piVar5 + 0x88))(piVar5,1,3,4);
        }
      }
      if ((*(byte *)((int)piVar5 + 0x15) & 2) == 0) {
        local_ec = piVar5[0x21];
      }
      else {
        local_ec = piVar5[0x21] + -1;
      }
      if (local_ec < 1) break;
      local_e8 = 1;
      do {
        piVar9 = (int *)FUN_0010b180(piVar5,local_e8);
        if (piVar9 != (int *)0x0) {
          if ((((piVar9[0x20] == 0) || (cVar4 = FUN_0012dfd8(piVar9[0x26]), cVar4 == '\0')) ||
              (((*(byte *)(piVar9 + 5) & 2) != 0 ||
               (cVar4 = (**(code **)(*piVar9 + 0x50))(piVar9), cVar4 != '\0')))) &&
             ((cVar4 = FUN_0012df9c(piVar9[0x26]), cVar4 == '\0' &&
              (cVar4 = FUN_0012dfba(piVar9[0x26]), cVar4 == '\0')))) {
            bVar2 = false;
          }
          else {
            bVar2 = true;
          }
          local_118 = DAT_001cc558;
          iVar10 = (**(code **)(*piVar5 + 0x14))(piVar5);
          if (local_e8 <= iVar10) {
            local_118 = FUN_000f65d0(piVar5,local_e8,piVar5[3],param_1);
          }
          if (local_118 == 0) {
            if (local_e8 == 0) {
              piVar5[0x27] = DAT_001cc538;
            }
            else {
              iVar10 = FUN_0010b0f4(piVar5,local_e8);
              *(int *)(iVar10 + 0x10) = DAT_001cc538;
            }
          }
          if (!bVar2) {
            local_118 = 1;
          }
          local_e4 = -1;
LAB_001459e4:
          if (local_118 != 0) {
            if (*(int *)(piVar9[0x22] + 8) == 0x8e) {
              iVar10 = (**(code **)(*piVar9 + 0x7c))(piVar9);
              local_11c = local_118;
              if (iVar10 == 0) {
                local_e0 = 0;
              }
              else {
                local_e0 = 0;
                do {
                  iVar11 = FUN_001a8f90(*(undefined4 *)(iVar10 + 0x14c),iVar7);
                  iVar12 = FUN_0010b0f4(iVar10,0);
                  uVar16 = FUN_000f5fea(*(undefined4 *)(iVar12 + 0x10));
                  if ((local_e4 == iVar11) || (iVar12 = local_e0, (local_11c & uVar16) != 0)) {
                    local_11c = local_11c | uVar16;
                    iVar12 = iVar11;
                    if ((-1 < local_e4) && (iVar12 = local_e4, local_e4 != iVar11)) {
                      FUN_001a8fcc(local_e4,iVar11,iVar7);
                    }
                    local_e4 = iVar12;
                    iVar12 = iVar10;
                    if (local_e0 != 0) {
                      *(undefined4 *)(iVar10 + 0xc) = 0;
                      *(int *)(iVar10 + 0x9c) = DAT_001cc54c;
                      iVar12 = local_e0;
                    }
                  }
                  local_e0 = iVar12;
                  iVar10 = *(int *)(iVar10 + 300);
                } while (iVar10 != 0);
              }
              uVar16 = local_34;
              if (*(uint *)(local_e0 + 0xc) != local_11c) {
                if (local_34 < local_38) {
                  iVar10 = local_34 * 4;
                  _memset((void *)(iVar10 + local_30),0,4);
                  local_34 = uVar16 + 1;
                  piVar9 = (int *)(iVar10 + local_30);
                }
                else {
                  piVar9 = (int *)FUN_001a7f7c(&local_38,local_34);
                }
                *piVar9 = local_e0;
                *(uint *)(local_e0 + 0xc) = local_11c;
                uVar14 = FUN_000f5a44(DAT_001cc540,local_11c);
                *(undefined4 *)(local_e0 + 0x9c) = uVar14;
              }
            }
            else {
              iVar10 = FUN_0010b0f4(piVar9,0);
              uVar16 = FUN_000f5fea(*(undefined4 *)(iVar10 + 0x10));
              if (((!bVar2) || (iVar10 = local_e4, (local_118 & uVar16) != 0)) &&
                 (iVar10 = FUN_001a8f90(piVar9[0x53],iVar7), -1 < local_e4)) {
                FUN_001a8fcc(local_e4,iVar10,iVar7);
                iVar10 = local_e4;
              }
              local_e4 = iVar10;
              uVar3 = local_34;
              uVar1 = piVar9[3];
              if (bVar2) {
                piVar9[3] = local_118 & uVar16 | uVar1;
              }
              else {
                piVar9[3] = uVar16;
              }
              if (uVar1 != piVar9[3]) {
                if (local_34 < local_38) {
                  iVar10 = local_34 * 4;
                  _memset((void *)(iVar10 + local_30),0,4);
                  local_34 = uVar3 + 1;
                  puVar6 = (undefined4 *)(iVar10 + local_30);
                }
                else {
                  puVar6 = (undefined4 *)FUN_001a7f7c(&local_38,local_34);
                }
                *puVar6 = piVar9;
              }
              if (bVar2) {
                cVar4 = FUN_0010b1aa(piVar9);
                if (cVar4 == '\0') {
                  local_118 = local_118 - (uVar16 & local_118);
                }
                if (local_118 != 0) goto code_r0x0014715c;
              }
            }
          }
        }
        local_e8 = local_e8 + 1;
      } while (local_e8 <= local_ec);
      if (local_34 == 0) goto LAB_00145a16;
    }
  }
LAB_00145a16:
  local_100 = *(int *)(param_1 + 0x378);
  if (*(int *)(local_100 + 8) != 0) {
    do {
      piVar5 = *(int **)(local_100 + 0x98);
      iVar10 = piVar5[2];
      while (iVar10 != 0) {
        if ((*(byte *)(piVar5 + 5) & 1) == 0) {
LAB_00145a4c:
          piVar5 = (int *)piVar5[2];
          iVar10 = piVar5[2];
        }
        else {
          iVar10 = piVar5[3];
          iVar11 = FUN_0010b0f4(piVar5,0);
          iVar10 = FUN_000f5a44(*(undefined4 *)(iVar11 + 0x10),iVar10);
          if (((((piVar5[0x20] != 0) && (cVar4 = FUN_0012dfd8(piVar5[0x26]), cVar4 != '\0')) &&
               (((*(byte *)(piVar5 + 5) & 2) == 0 &&
                (cVar4 = (**(code **)(*piVar5 + 0x50))(piVar5), cVar4 == '\0')))) ||
              ((cVar4 = FUN_0012df9c(piVar5[0x26]), cVar4 != '\0' ||
               (cVar4 = FUN_0012dfba(piVar5[0x26]), cVar4 != '\0')))) &&
             ((piVar9 = *(int **)(*(int *)(param_1 + 8) + 0x54),
              cVar4 = (**(code **)(*piVar9 + 0x7c))(piVar9,piVar5), cVar4 != '\0' &&
              (iVar11 = FUN_0010b0f4(piVar5,0), iVar10 != *(int *)(iVar11 + 0x10))))) {
            piVar5[0x27] = iVar10;
          }
          if (piVar5[3] == 0) {
LAB_00145bc8:
            if (piVar5[0x20] == 0) goto LAB_00145bd9;
LAB_00146168:
            cVar4 = FUN_0012dfd8(piVar5[0x26]);
            if (((cVar4 == '\0') || ((*(byte *)(piVar5 + 5) & 2) != 0)) ||
               (cVar4 = (**(code **)(*piVar5 + 0x50))(piVar5), cVar4 != '\0')) goto LAB_00145bd9;
            if (piVar5[3] == 0) goto LAB_00145c02;
LAB_001461ab:
            iVar10 = ((int (*)())FUN_00144496)(piVar5);
          }
          else {
            local_d8 = piVar5[0x21];
            if ((*(byte *)((int)piVar5 + 0x15) & 2) != 0) {
              local_d8 = local_d8 + -1;
            }
            cVar4 = (**(code **)(*piVar5 + 0x60))(piVar5);
            if (cVar4 != '\0') {
              if (0 < local_d8) {
                iVar11 = 1;
                do {
                  while ((iVar12 = (**(code **)(*piVar5 + 0x14))(piVar5), iVar12 < iVar11 ||
                         (iVar13 = FUN_000f626e(piVar5,iVar11,param_1,iVar10), iVar12 = DAT_001cc538
                         , iVar13 != 0))) {
LAB_00145b2d:
                    iVar11 = iVar11 + 1;
                    if (local_d8 < iVar11) goto LAB_00145b8d;
                  }
                  if (iVar11 != 0) {
                    iVar13 = FUN_0010b0f4(piVar5,iVar11);
                    *(int *)(iVar13 + 0x10) = iVar12;
                    goto LAB_00145b2d;
                  }
                  piVar5[0x27] = DAT_001cc538;
                  iVar11 = 1;
                } while (0 < local_d8);
              }
LAB_00145b8d:
              FUN_00111598(piVar5,*(undefined4 *)(param_1 + 8));
              local_d8 = piVar5[0x21];
              if ((*(byte *)((int)piVar5 + 0x15) & 2) != 0) {
                local_d8 = local_d8 + -1;
              }
            }
            if (local_d8 < 1) goto LAB_00145bc8;
            local_d4 = 1;
            do {
              local_128 = DAT_001cc558;
              piVar9 = (int *)FUN_0010b180(piVar5,local_d4);
              iVar11 = (**(code **)(*piVar5 + 0x14))(piVar5);
              if (local_d4 <= iVar11) {
                local_128 = FUN_000f626e(piVar5,local_d4,param_1,iVar10);
              }
              cVar4 = ((int (*)())FUN_00140d76)(*(undefined4 *)(param_1 + 8),piVar5,local_d4,param_1);
              uVar16 = DAT_001cc558;
              if (cVar4 == '\0') {
                iVar11 = (**(code **)(*piVar5 + 0x14))(piVar5);
                if (local_d4 <= iVar11) {
                  uVar16 = FUN_000f65d0(piVar5,local_d4,piVar5[3],param_1);
                }
                if (piVar9 != (int *)0x0) {
                  if (((((piVar9[0x20] != 0) && (cVar4 = FUN_0012dfd8(piVar9[0x26]), cVar4 != '\0'))
                       && ((*(byte *)(piVar9 + 5) & 2) == 0)) &&
                      (cVar4 = (**(code **)(*piVar9 + 0x50))(piVar9), cVar4 == '\0')) ||
                     ((cVar4 = FUN_0012df9c(piVar9[0x26]), cVar4 != '\0' ||
                      (cVar4 = FUN_0012dfba(piVar9[0x26]), cVar4 != '\0')))) {
                    for (; (piVar9[3] & uVar16) == 0; piVar9 = (int *)((int (*)())FUN_00144496)(piVar9)) {
                    }
                    FUN_0010ba02(piVar5,local_d4,piVar9,0,*(undefined4 *)(param_1 + 8));
                    iVar11 = FUN_0010b0f4(piVar5,local_d4);
                    local_12c = FUN_000f5b96(*(undefined4 *)(iVar11 + 0x10),local_128);
                    iVar11 = FUN_0010b0f4(piVar5,local_d4);
                    if (*(int *)(iVar11 + 0x10) != DAT_001cc538) {
                      puVar17 = (uint *)piVar9[4];
                      uVar16 = puVar17[1];
                      if (uVar16 < *puVar17) {
                        _memset((void *)(uVar16 * 4 + puVar17[2]),0,4);
                        puVar17[1] = uVar16 + 1;
                        puVar6 = (undefined4 *)(uVar16 * 4 + puVar17[2]);
                      }
                      else {
                        puVar6 = (undefined4 *)FUN_001a7f7c(puVar17,uVar16);
                      }
                      *puVar6 = piVar5;
                    }
                    ((int (*)())FUN_00140a76)(piVar9,piVar5);
                    goto LAB_00146107;
                  }
                  puVar17 = (uint *)piVar9[4];
                  uVar16 = puVar17[1];
                  if (uVar16 < *puVar17) {
                    _memset((void *)(uVar16 * 4 + puVar17[2]),0,4);
                    puVar17[1] = uVar16 + 1;
                    *(int **)(uVar16 * 4 + puVar17[2]) = piVar5;
                  }
                  else {
                    puVar6 = (undefined4 *)FUN_001a7f7c(puVar17,uVar16);
                    *puVar6 = piVar5;
                  }
                }
              }
              else {
                cVar4 = FUN_0010a320(piVar5);
                uVar14 = DAT_001cc53c;
                if (cVar4 != '\0') {
                  uVar14 = DAT_001cc554;
                }
                cVar4 = FUN_001192da(*(undefined4 *)(param_1 + 8),piVar5);
                if (cVar4 != '\0') {
                  if (local_d4 == 1) {
                    puVar6 = &DAT_001cc550;
                  }
                  else {
                    puVar6 = &DAT_001cc554;
                  }
                  uVar14 = *puVar6;
                }
                local_12c = FUN_000f5b96(uVar14,local_128);
                iVar11 = FUN_0010b180(piVar5,local_d4);
                if (*(int *)(iVar11 + 0x10) == 0) {
                  uVar14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
                  puVar6 = (undefined4 *)FUN_001a7bca(uVar14,0x14);
                  *puVar6 = uVar14;
                  puVar6[4] = uVar14;
                  puVar6[2] = 0;
                  puVar6[1] = 2;
                  uVar14 = FUN_001a7bca(uVar14,8);
                  puVar6[3] = uVar14;
                  *(undefined4 **)(iVar11 + 0x10) = puVar6 + 1;
                }
                puVar17 = *(uint **)(iVar11 + 0x10);
                uVar16 = puVar17[1];
                if (uVar16 < *puVar17) {
                  _memset((void *)(puVar17[2] + uVar16 * 4),0,4);
                  puVar17[1] = uVar16 + 1;
                  puVar6 = (undefined4 *)(puVar17[2] + uVar16 * 4);
                }
                else {
                  puVar6 = (undefined4 *)FUN_001a7f7c(puVar17,uVar16);
                }
                *puVar6 = piVar5;
LAB_00146107:
                iVar11 = FUN_0010b0f4(piVar5,local_d4);
                if (local_12c != *(int *)(iVar11 + 0x10)) {
                  if (local_d4 == 0) {
                    piVar5[0x27] = local_12c;
                  }
                  else {
                    iVar11 = FUN_0010b0f4(piVar5,local_d4);
                    *(int *)(iVar11 + 0x10) = local_12c;
                  }
                }
              }
              local_d4 = local_d4 + 1;
            } while (local_d4 <= local_d8);
            if (piVar5[0x20] != 0) goto LAB_00146168;
LAB_00145bd9:
            cVar4 = FUN_0012df9c(piVar5[0x26]);
            if ((cVar4 == '\0') && (cVar4 = FUN_0012dfba(piVar5[0x26]), cVar4 == '\0'))
            goto LAB_00145a4c;
            if (piVar5[3] != 0) goto LAB_001461ab;
LAB_00145c02:
            iVar10 = 0;
          }
          iVar11 = FUN_001a8f90(piVar5[0x53],iVar7);
          while ((iVar10 != 0 &&
                 ((iVar12 = FUN_001a8f90(*(undefined4 *)(iVar10 + 0x14c),iVar7), iVar11 != iVar12 ||
                  (cVar4 = FUN_000f6d42(iVar10,piVar5), cVar4 == '\0'))))) {
            iVar10 = ((int (*)())FUN_00144496)(iVar10);
          }
          *(int *)(iVar8 + piVar5[0x53] * 4) = iVar10;
          piVar5 = (int *)piVar5[2];
          iVar10 = piVar5[2];
        }
      }
      local_100 = *(int *)(local_100 + 8);
    } while (*(int *)(local_100 + 8) != 0);
    local_100 = *(int *)(param_1 + 0x378);
  }
  iVar10 = *(int *)(local_100 + 8);
  while (iVar10 != 0) {
    piVar5 = *(int **)(local_100 + 0x98);
    iVar10 = piVar5[2];
joined_r0x00145ccf:
    if (iVar10 != 0) {
      do {
        if ((*(byte *)(piVar5 + 5) & 1) != 0) {
          if (((((piVar5[0x20] == 0) || (cVar4 = FUN_0012dfd8(piVar5[0x26]), cVar4 == '\0')) ||
               ((*(byte *)(piVar5 + 5) & 2) != 0)) ||
              (cVar4 = (**(code **)(*piVar5 + 0x50))(piVar5), cVar4 != '\0')) &&
             ((cVar4 = FUN_0012df9c(piVar5[0x26]), cVar4 == '\0' &&
              (cVar4 = FUN_0012dfba(piVar5[0x26]), cVar4 == '\0')))) goto code_r0x00146313;
          iVar10 = FUN_0010b0f4(piVar5,0);
          if (*(int *)(iVar10 + 0x10) != DAT_001cc54c) {
            FUN_001126d2(piVar5,*(undefined4 *)(param_1 + 8));
          }
          if ((*(byte *)((int)piVar5 + 0x15) & 2) != 0) {
            iVar10 = *(int *)(iVar8 + piVar5[0x53] * 4);
            if (iVar10 == 0) {
              FUN_0010ba02(piVar5,piVar5[0x21],0,0,*(undefined4 *)(param_1 + 8));
              piVar5[0x21] = piVar5[0x21] + -1;
              piVar5[5] = piVar5[5] & 0xfffffdff;
            }
            else {
              FUN_0010c18e(piVar5,iVar10,0,*(undefined4 *)(param_1 + 8));
              iVar11 = DAT_001cc538;
              if (piVar5[0x21] == 0) {
                piVar5[0x27] = DAT_001cc538;
              }
              else {
                iVar7 = FUN_0010b0f4(piVar5,piVar5[0x21]);
                *(int *)(iVar7 + 0x10) = iVar11;
              }
              puVar17 = *(uint **)(iVar10 + 0x10);
              uVar16 = puVar17[1];
              if (uVar16 < *puVar17) {
                _memset((void *)(uVar16 * 4 + puVar17[2]),0,4);
                puVar17[1] = uVar16 + 1;
                puVar6 = (undefined4 *)(uVar16 * 4 + puVar17[2]);
              }
              else {
                puVar6 = (undefined4 *)FUN_001a7f7c(puVar17,uVar16);
              }
              *puVar6 = piVar5;
              *(uint *)(iVar10 + 0x14) = *(uint *)(iVar10 + 0x14) | 0x400000;
            }
          }
          if ((((char)piVar5[0x48] != '\0') || (piVar5[0x49] != 0)) &&
             (((*(byte *)((int)piVar5 + 0x15) & 2) != 0 &&
              (piVar9 = *(int **)(*(int *)(param_1 + 8) + 0x54),
              cVar4 = (**(code **)(*piVar9 + 0x7c))(piVar9,piVar5), cVar4 == '\0')))) {
            iVar11 = FUN_0010a1c2(piVar5,*(undefined4 *)(param_1 + 8),0);
            uVar14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
            puVar6 = (undefined4 *)FUN_001a7bca(uVar14,0x14);
            *puVar6 = uVar14;
            puVar6[4] = uVar14;
            puVar6[2] = 0;
            puVar6[1] = 2;
            uVar14 = FUN_001a7bca(uVar14,8);
            puVar6[3] = uVar14;
            *(undefined4 **)(iVar11 + 0x10) = puVar6 + 1;
            FUN_000e956e(local_100,piVar5,iVar11);
            iVar10 = piVar5[4];
            FUN_001a7d72(piVar5);
            FUN_0010db52(piVar5,0x31,*(undefined4 *)(param_1 + 8));
            piVar5[4] = iVar10;
            piVar5[0x25] = piVar5[0x53];
            piVar5[0x26] = 0;
            FUN_0010ba02(piVar5,1,iVar11,0,*(undefined4 *)(param_1 + 8));
            uVar14 = *(undefined4 *)(param_1 + 8);
            uVar15 = FUN_0010b180(iVar11,*(undefined4 *)(iVar11 + 0x84));
            FUN_0010c18e(piVar5,uVar15,0,uVar14);
            iVar10 = DAT_001cc538;
            if (piVar5[0x21] == 0) {
              piVar5[0x27] = DAT_001cc538;
              local_a8 = *(uint **)(iVar11 + 0x10);
              local_a4 = local_a8[1];
              if (*local_a8 <= local_a4) goto LAB_00146dee;
LAB_001468c3:
              _memset((void *)(local_a4 * 4 + local_a8[2]),0,4);
              local_a8[1] = local_a4 + 1;
              puVar6 = (undefined4 *)(local_a4 * 4 + local_a8[2]);
            }
            else {
              iVar7 = FUN_0010b0f4(piVar5,piVar5[0x21]);
              *(int *)(iVar7 + 0x10) = iVar10;
              local_a8 = *(uint **)(iVar11 + 0x10);
              local_a4 = local_a8[1];
              if (local_a4 < *local_a8) goto LAB_001468c3;
LAB_00146dee:
              puVar6 = (undefined4 *)FUN_001a7f7c(local_a8,local_a4);
            }
            *puVar6 = piVar5;
            FUN_0010ba02(iVar11,*(undefined4 *)(iVar11 + 0x84),0,0,*(undefined4 *)(param_1 + 8));
            *(int *)(iVar11 + 0x84) = *(int *)(iVar11 + 0x84) + -1;
            *(uint *)(iVar11 + 0x14) = *(uint *)(iVar11 + 0x14) & 0xfffffdff;
            *(int *)(iVar11 + 0x160) = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x3f4) + 0x46c) + 1
            ;
            if (0 < *(int *)(iVar11 + 0x84)) {
              local_a0 = 1;
              do {
                iVar10 = FUN_0010b180(iVar11,local_a0);
                puVar17 = *(uint **)(iVar10 + 0x10);
                if (puVar17[1] != 0) {
                  local_98 = 0;
                  do {
                    if (local_98 < *puVar17) {
                      uVar16 = puVar17[1];
                      if (uVar16 <= local_98) {
                        _memset((void *)(puVar17[2] + uVar16 * 4),0,(local_98 - uVar16) * 4 + 4);
                        puVar17[1] = local_98 + 1;
                      }
                      piVar9 = *(int **)(puVar17[2] + local_98 * 4);
                    }
                    else {
                      piVar9 = (int *)FUN_001a7f7c(puVar17,local_98);
                      piVar9 = (int *)*piVar9;
                    }
                    if (piVar5 == piVar9) {
                      FUN_001a7f3c(*(undefined4 *)(iVar10 + 0x10),local_98);
                      puVar17 = *(uint **)(iVar10 + 0x10);
                      uVar16 = puVar17[1];
                      if (uVar16 < *puVar17) {
                        _memset((void *)(uVar16 * 4 + puVar17[2]),0,4);
                        puVar17[1] = uVar16 + 1;
                        piVar9 = (int *)(uVar16 * 4 + puVar17[2]);
                      }
                      else {
                        piVar9 = (int *)FUN_001a7f7c(puVar17,uVar16);
                      }
                      *piVar9 = iVar11;
                      break;
                    }
                    local_98 = local_98 + 1;
                    puVar17 = *(uint **)(iVar10 + 0x10);
                  } while (local_98 < puVar17[1]);
                }
                local_a0 = local_a0 + 1;
              } while (local_a0 <= *(int *)(iVar11 + 0x84));
            }
            FUN_000e9596(local_100,iVar11,piVar5);
          }
        }
        piVar5 = (int *)piVar5[2];
        if (piVar5[2] == 0) break;
      } while( true );
    }
    local_100 = *(int *)(local_100 + 8);
    iVar10 = *(int *)(local_100 + 8);
  }
  *(int *)(param_1 + 0x468) = *(int *)(param_1 + 0x468) + 1;
  local_28 = 0;
  local_70 = 1;
  local_6c = 0;
  iVar10 = *(int *)(param_1 + 0x3b8);
  if (*(int *)(iVar10 + 4) != 0) {
    do {
      uVar16 = local_34;
      iVar11 = *(int *)(*(int *)(iVar10 + 8) + local_6c);
      local_28 = iVar11;
      if ((*(byte *)(iVar11 + 0x14) & 1) != 0) {
        if (local_34 < local_38) {
          iVar10 = local_34 * 4;
          _memset((void *)(iVar10 + local_30),0,4);
          local_34 = uVar16 + 1;
          piVar5 = (int *)(iVar10 + local_30);
        }
        else {
          piVar5 = (int *)FUN_001a7f7c(&local_38,local_34);
        }
        *piVar5 = iVar11;
        iVar10 = *(int *)(param_1 + 0x3b8);
      }
      local_70 = local_70 + 1;
      local_6c = local_6c + 4;
    } while (local_70 <= *(uint *)(iVar10 + 4));
  }
  while (local_34 != 0) {
    while( true ) {
      uVar16 = local_34 - 1;
      if (uVar16 < local_34) {
        piVar5 = (int *)(local_30 + uVar16 * 4);
      }
      else {
        piVar5 = (int *)0x0;
      }
      iVar10 = *piVar5;
      FUN_001a7f3c(&local_38,uVar16);
      *(undefined4 *)(iVar10 + 0x150) = *(undefined4 *)(param_1 + 0x468);
      iVar11 = *(int *)(iVar10 + 0x84);
      if ((*(byte *)(iVar10 + 0x15) & 2) != 0) {
        iVar11 = iVar11 + -1;
      }
      if (iVar11 < 1) break;
      local_84 = 1;
      do {
        while (piVar5 = (int *)FUN_0010b180(iVar10,local_84), uVar16 = local_34,
              piVar5 == (int *)0x0) {
LAB_001465af:
          local_84 = local_84 + 1;
          if (iVar11 < local_84) goto LAB_001465c2;
        }
        if (*(int *)(param_1 + 0x468) != piVar5[0x54]) {
          if (local_34 < local_38) {
            iVar7 = local_34 * 4;
            _memset((void *)(iVar7 + local_30),0,4);
            local_34 = uVar16 + 1;
            puVar6 = (undefined4 *)(iVar7 + local_30);
          }
          else {
            puVar6 = (undefined4 *)FUN_001a7f7c(&local_38,local_34);
          }
          *puVar6 = piVar5;
        }
        if (((((piVar5[0x20] != 0) && (cVar4 = FUN_0012dfd8(piVar5[0x26]), cVar4 != '\0')) &&
             ((*(byte *)(piVar5 + 5) & 2) == 0)) &&
            (cVar4 = (**(code **)(*piVar5 + 0x50))(piVar5), cVar4 == '\0')) ||
           ((cVar4 = FUN_0012df9c(piVar5[0x26]), cVar4 != '\0' ||
            (cVar4 = FUN_0012dfba(piVar5[0x26]), cVar4 != '\0')))) {
          iVar7 = FUN_0010b0f4(iVar10,local_84);
          local_24 = FUN_000f5bdc(*(undefined4 *)(iVar7 + 0x10));
          local_7c = 0;
          local_78 = piVar5;
LAB_0014651a:
          do {
            cVar4 = FUN_0012dff6(local_78[0x26]);
            uVar16 = local_34;
            if (cVar4 == '\0') {
              if (*(int *)(param_1 + 0x468) != local_78[0x54]) {
                if (local_34 < local_38) {
                  iVar7 = local_34 * 4;
                  _memset((void *)(iVar7 + local_30),0,4);
                  local_34 = uVar16 + 1;
                  puVar6 = (undefined4 *)(iVar7 + local_30);
                }
                else {
                  puVar6 = (undefined4 *)FUN_001a7f7c(&local_38,local_34);
                }
                *puVar6 = local_78;
              }
              local_48 = local_78[3];
              if ((*(char *)((int)local_20 + local_7c + -4) != '\0') &&
                 (*(char *)((int)&local_48 + local_7c) == '\0')) {
                iVar7 = local_78[0x21];
                iVar8 = FUN_0010b0f4(local_78,iVar7);
                local_20[0] = *(int *)(iVar8 + 0x10);
                if (*(char *)((int)local_20 + local_7c) == '\x04') {
                  *(char *)((int)local_20 + local_7c) = (char)local_7c;
                  iVar8 = local_20[0];
                  if (iVar7 == 0) {
                    local_78[0x27] = local_20[0];
                  }
                  else {
                    iVar7 = FUN_0010b0f4(local_78,iVar7);
                    *(int *)(iVar7 + 0x10) = iVar8;
                  }
                  local_78 = (int *)FUN_0010b180(local_78,local_78[0x21]);
                  if (local_78 != (int *)0x0) goto LAB_0014651a;
                }
              }
            }
            local_7c = local_7c + 1;
            local_78 = piVar5;
          } while (local_7c != 4);
          goto LAB_001465af;
        }
        local_84 = local_84 + 1;
      } while (local_84 <= iVar11);
LAB_001465c2:
      if (local_34 == 0) goto LAB_001465cd;
    }
  }
LAB_001465cd:
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x20000;
  FUN_000f0346(param_1,"reduce");
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x80;
  FUN_001a7aba(local_2c,local_30);
  return;
code_r0x0014715c:
  piVar9 = (int *)FUN_0010b180(piVar9,piVar9[0x21]);
  goto LAB_001459e4;
code_r0x00146313:
  piVar5 = (int *)piVar5[2];
  iVar10 = piVar5[2];
  goto joined_r0x00145ccf;
}

/* FUN_00147412 @ 0x147412 (2317 bytes) */
int FUN_00147412(param_1, param_2)
  int *param_1;
  int param_2;
{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined4 *puVar10;
  int *piVar11;
  undefined4 uVar12;
  uint *puVar13;
  uint uVar14;
  int *local_5c;
  bool local_55;
  undefined4 local_54;
  int local_50;
  uint local_3c;
  int local_34;
  undefined4 local_28;
  undefined4 local_24;
  int local_20 [4];
  
  uVar14 = param_1[5];
  if ((uVar14 & 0x200) == 0) {
    if ((uVar14 & 0x400000) == 0) {
      return true;
    }
    piVar9 = (int *)param_1[4];
    if (piVar9[1] != 1) {
      return false;
    }
    if (*piVar9 == 0) {
      puVar10 = (undefined4 *)FUN_001a7f7c(piVar9,0);
    }
    else {
      puVar10 = (undefined4 *)piVar9[2];
    }
    local_5c = (int *)*puVar10;
    uVar14 = local_5c[5];
    if ((uVar14 & 0x200) != 0) {
      FUN_0010b180(local_5c,local_5c[0x21]);
      uVar14 = local_5c[5];
    }
    local_55 = (uVar14 & 0x400000) == 0;
  }
  else {
    if ((uVar14 & 0x400000) != 0) {
      return false;
    }
    local_5c = (int *)FUN_0010b180(param_1,param_1[0x21]);
    local_55 = true;
  }
  cVar5 = (**(code **)(*local_5c + 100))(local_5c);
  if (cVar5 != '\0') {
    iVar6 = FUN_0010b180(param_1,1);
    iVar7 = FUN_0010b180(param_1,2);
    iVar8 = FUN_0010b180(local_5c,1);
    if (iVar6 == iVar8) {
      local_54 = 2;
      local_50 = 1;
    }
    else {
      if (iVar7 != iVar8) {
        return false;
      }
      local_54 = 1;
      local_50 = 2;
      iVar7 = iVar6;
    }
    if (((char)param_1[0x48] == (char)local_5c[0x48]) && (param_1[0x49] == local_5c[0x49])) {
      if ((((byte)((uint)param_1[local_50 * 6 + 0x28] >> 1) & 1) ==
           ((byte)((uint)local_5c[0x2e] >> 1) & 1)) &&
         (((byte)param_1[local_50 * 6 + 0x28] & 1) == ((byte)local_5c[0x2e] & 1))) {
        iVar6 = FUN_0010b0f4(param_1,0);
        local_20[0] = *(int *)(iVar6 + 0x10);
        iVar6 = FUN_0010b0f4(local_5c,0);
        local_24 = *(undefined4 *)(iVar6 + 0x10);
        iVar8 = 1;
        do {
          if ((*(char *)((int)local_20 + iVar8 + -1) != '\x01') &&
             (*(char *)((int)&local_28 + iVar8 + 3) != '\x01')) {
            return false;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 != 5);
        local_20[0] = FUN_000f5892(local_20[0],*(undefined4 *)(iVar6 + 0x10));
        param_1[0x27] = local_20[0];
        piVar9 = (int *)((int (*)())FUN_00110f42)(2,local_20[0],iVar7,param_2,*(undefined4 *)(param_2 + 8),0);
        iVar7 = 0;
        do {
          if (*(char *)((int)local_20 + iVar7) == '\0') {
            iVar6 = FUN_0010b0f4(local_5c,1);
            cVar5 = *(char *)(iVar7 + 0x10 + iVar6);
            if (cVar5 == '\x04') {
              pcVar4 = *(code **)(*piVar9 + 0x88);
              iVar6 = FUN_0010b0f4(param_1,local_54);
              (*pcVar4)(piVar9,1,iVar7,*(undefined1 *)(iVar7 + 0x10 + iVar6));
            }
            else {
              (**(code **)(*piVar9 + 0x88))(piVar9,2,iVar7,iVar7);
            }
            iVar6 = FUN_0010b0f4(param_1,local_50);
            cVar1 = *(char *)(iVar7 + 0x10 + iVar6);
            if (cVar1 == '\x04') {
              (**(code **)(*param_1 + 0x88))(param_1,local_50,iVar7,cVar5);
            }
            else {
              (**(code **)(*param_1 + 0x88))(param_1,local_50,iVar7,cVar1);
            }
            (**(code **)(*param_1 + 0x88))(param_1,local_54,iVar7,iVar7);
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 != 4);
        FUN_0010ba02(param_1,local_54,piVar9,1,*(undefined4 *)(param_2 + 8));
        FUN_000e956e(param_1[0x56],param_1,piVar9);
        if (((param_1[5] & 0x200U) == 0) || ((*(byte *)((int)local_5c + 0x15) & 2) != 0)) {
          if (((param_1[5] & 0x200U) == 0) || ((*(byte *)((int)local_5c + 0x15) & 2) == 0)) {
            puVar13 = (uint *)local_5c[4];
            local_3c = puVar13[1] - 1;
            if (-1 < (int)local_3c) {
              local_34 = local_3c * 4;
              do {
                if (local_3c < *puVar13) {
                  uVar14 = puVar13[1];
                  if (uVar14 <= local_3c) {
                    _memset((void *)(puVar13[2] + uVar14 * 4),0,(local_3c - uVar14) * 4 + 4);
                    puVar13[1] = local_3c + 1;
                  }
                  piVar9 = (int *)(local_34 + puVar13[2]);
                }
                else {
                  piVar9 = (int *)FUN_001a7f7c(puVar13,local_3c);
                }
                piVar9 = (int *)*piVar9;
                for (iVar7 = 1; iVar6 = (**(code **)(*piVar9 + 0x14))(piVar9), iVar7 <= iVar6;
                    iVar7 = iVar7 + 1) {
                  piVar11 = (int *)FUN_0010b180(piVar9,iVar7);
                  if (local_5c == piVar11) {
                    FUN_0010ba02(piVar9,iVar7,param_1,1,*(undefined4 *)(param_2 + 8));
                    goto LAB_001476db;
                  }
                }
                if (((*(byte *)((int)piVar9 + 0x15) & 2) != 0) &&
                   (piVar11 = (int *)FUN_0010b180(piVar9,piVar9[0x21]), local_5c == piVar11)) {
                  FUN_0010c18e(piVar9,param_1,1,*(undefined4 *)(param_2 + 8));
                }
LAB_001476db:
                local_3c = local_3c - 1;
                local_34 = local_34 + -4;
                if (local_3c == 0xffffffff) break;
                puVar13 = (uint *)local_5c[4];
              } while( true );
            }
            uVar2 = *(undefined4 *)(param_2 + 8);
            iVar7 = FUN_0010b180(local_5c,local_5c[0x21]);
            puVar13 = *(uint **)(iVar7 + 0x10);
            if (0 < (int)puVar13[1]) {
              uVar14 = 0;
              do {
                if (uVar14 < *puVar13) {
                  uVar3 = puVar13[1];
                  if (uVar3 <= uVar14) {
                    _memset((void *)(puVar13[2] + uVar3 * 4),0,(uVar14 - uVar3) * 4 + 4);
                    puVar13[1] = uVar14 + 1;
                  }
                  piVar9 = (int *)(puVar13[2] + uVar14 * 4);
                }
                else {
                  piVar9 = (int *)FUN_001a7f7c(puVar13,uVar14);
                }
                if (local_5c == (int *)*piVar9) {
                  FUN_001a7f3c(puVar13,uVar14);
                  iVar7 = FUN_0010b180(local_5c,local_5c[0x21]);
                  *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + -1;
                  break;
                }
                uVar14 = uVar14 + 1;
              } while ((int)uVar14 < (int)puVar13[1]);
            }
            FUN_0010ba02(local_5c,local_5c[0x21],0,1,uVar2);
            local_5c[0x21] = local_5c[0x21] + -1;
            local_5c[5] = local_5c[5] & 0xfffffdff;
          }
          else {
            iVar7 = FUN_0010b0f4(param_1,param_1[0x21]);
            local_28 = *(int *)(iVar7 + 0x10);
            iVar7 = 0;
            do {
              iVar6 = FUN_0010b0f4(param_1,0);
              if (*(char *)(iVar7 + 0x10 + iVar6) != '\x01') {
                *(undefined1 *)((int)&local_28 + iVar7) = 4;
              }
              iVar7 = iVar7 + 1;
            } while (iVar7 != 4);
            uVar2 = *(undefined4 *)(param_2 + 8);
            iVar7 = FUN_0010b180(param_1,param_1[0x21]);
            puVar13 = *(uint **)(iVar7 + 0x10);
            if (0 < (int)puVar13[1]) {
              uVar14 = 0;
              do {
                if (uVar14 < *puVar13) {
                  uVar3 = puVar13[1];
                  if (uVar3 <= uVar14) {
                    _memset((void *)(puVar13[2] + uVar3 * 4),0,(uVar14 - uVar3) * 4 + 4);
                    puVar13[1] = uVar14 + 1;
                  }
                  piVar9 = (int *)(puVar13[2] + uVar14 * 4);
                }
                else {
                  piVar9 = (int *)FUN_001a7f7c(puVar13,uVar14);
                }
                if (param_1 == (int *)*piVar9) {
                  FUN_001a7f3c(puVar13,uVar14);
                  iVar7 = FUN_0010b180(param_1,param_1[0x21]);
                  *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + -1;
                  break;
                }
                uVar14 = uVar14 + 1;
              } while ((int)uVar14 < (int)puVar13[1]);
            }
            FUN_0010ba02(param_1,param_1[0x21],0,1,uVar2);
            param_1[0x21] = param_1[0x21] + -1;
            param_1[5] = param_1[5] & 0xfffffdff;
            if (local_28 != DAT_001cc538) {
              uVar2 = *(undefined4 *)(param_2 + 8);
              uVar12 = FUN_0010b180(local_5c,local_5c[0x21]);
              FUN_0010c18e(param_1,uVar12,1,uVar2);
              iVar7 = local_28;
              if (param_1[0x21] == 0) {
                param_1[0x27] = local_28;
              }
              else {
                iVar6 = FUN_0010b0f4(param_1,param_1[0x21]);
                *(int *)(iVar6 + 0x10) = iVar7;
              }
            }
          }
        }
        else {
          uVar2 = *(undefined4 *)(param_2 + 8);
          iVar7 = FUN_0010b180(param_1,param_1[0x21]);
          puVar13 = *(uint **)(iVar7 + 0x10);
          if (0 < (int)puVar13[1]) {
            uVar14 = 0;
            do {
              if (uVar14 < *puVar13) {
                uVar3 = puVar13[1];
                if (uVar3 <= uVar14) {
                  _memset((void *)(puVar13[2] + uVar3 * 4),0,(uVar14 - uVar3) * 4 + 4);
                  puVar13[1] = uVar14 + 1;
                }
                piVar9 = (int *)(puVar13[2] + uVar14 * 4);
              }
              else {
                piVar9 = (int *)FUN_001a7f7c(puVar13,uVar14);
              }
              if (param_1 == (int *)*piVar9) {
                FUN_001a7f3c(puVar13,uVar14);
                iVar7 = FUN_0010b180(param_1,param_1[0x21]);
                *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + -1;
                break;
              }
              uVar14 = uVar14 + 1;
            } while ((int)uVar14 < (int)puVar13[1]);
          }
          FUN_0010ba02(param_1,param_1[0x21],0,1,uVar2);
          param_1[0x21] = param_1[0x21] + -1;
          param_1[5] = param_1[5] & 0xfffffdff;
        }
        if (*(int *)(local_5c[4] + 4) == 0) {
          (**(code **)(*local_5c + 0xc))(local_5c,1,*(undefined4 *)(param_2 + 8));
        }
        if (local_55 == false) {
          param_1[5] = param_1[5] | 0x400000;
          return false;
        }
        return local_55;
      }
    }
  }
  return false;
}

/* FUN_00147d20 @ 0x147d20 (5452 bytes) */
int FUN_00147d20(param_1)
  int param_1;
{
  uint *puVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  char cVar11;
  char cVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  undefined4 uVar16;
  int iVar17;
  int iVar18;
  undefined4 *puVar19;
  uint *puVar20;
  int *piVar21;
  int *piVar22;
  int *piVar23;
  int *piVar24;
  undefined4 uVar25;
  int iVar26;
  undefined4 uVar27;
  int iVar28;
  int *piVar29;
  uint uVar30;
  int local_100;
  uint local_d0;
  uint local_c0;
  int *local_98;
  int *local_94;
  int local_88;
  int local_80;
  uint local_7c;
  int local_78;
  uint local_74;
  int local_70;
  int local_68;
  uint local_60;
  int local_5c;
  uint local_54;
  int *local_50;
  uint local_3c;
  uint local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  uint local_20 [4];
  
  cVar11 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x30);
  uVar14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar13 = (undefined4 *)FUN_001a7bca(uVar14,0x14);
  *puVar13 = uVar14;
  puVar1 = puVar13 + 1;
  puVar13[4] = uVar14;
  puVar13[2] = 0;
  puVar13[1] = 2;
  uVar14 = FUN_001a7bca(uVar14,8);
  puVar13[3] = uVar14;
  uVar14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar15 = (undefined4 *)FUN_001a7bca(uVar14,0x14);
  *puVar15 = uVar14;
  puVar15[4] = uVar14;
  puVar15[2] = 0;
  puVar15[1] = 2;
  uVar14 = FUN_001a7bca(uVar14,8);
  puVar15[3] = uVar14;
  local_30 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_38 = 0;
  local_3c = 2;
  local_34 = FUN_001a7bca(local_30,8);
  uVar14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  uVar16 = FUN_001a7bca(uVar14,8);
  iVar4 = *(int *)(param_1 + 0x378);
  iVar26 = *(int *)(iVar4 + 8);
  do {
    if (iVar26 == 0) {
      FUN_001a7aba(uVar14,uVar16);
      FUN_001a7aba(local_30,local_34);
      return;
    }
    puVar13[2] = 0;
    puVar15[2] = 0;
    local_38 = 0;
    piVar21 = *(int **)(iVar4 + 0x98);
    iVar26 = piVar21[2];
    while (iVar26 != 0) {
      while ((*(byte *)(piVar21 + 5) & 1) != 0) {
        iVar26 = FUN_0010b0f4(piVar21,0);
        iVar26 = *(int *)(iVar26 + 0x10);
        if (((*(int *)(piVar21[0x22] + 8) != 0x12) ||
            (cVar12 = ((int (*)())FUN_00147412)(piVar21,param_1), cVar12 == '\0')) || (iVar26 == DAT_001cc54c))
        break;
        if (cVar11 == '\0') {
          if (iVar26 == DAT_001cc540) break;
          iVar26 = puVar13[2];
        }
        else {
          if ((iVar26 == DAT_001cc548) || (iVar26 == DAT_001cc544)) break;
          iVar26 = puVar13[2];
        }
        if (iVar26 != 0) {
          local_d0 = 0;
          do {
            if (local_d0 < *puVar1) {
              uVar30 = puVar13[2];
              if (uVar30 <= local_d0) {
                _memset((void *)(puVar13[3] + uVar30 * 4),0,(local_d0 - uVar30) * 4 + 4);
                puVar13[2] = local_d0 + 1;
              }
              piVar22 = (int *)(puVar13[3] + local_d0 * 4);
            }
            else {
              piVar22 = (int *)FUN_001a7f7c(puVar1,local_d0);
            }
            iVar26 = *piVar22;
            for (iVar17 = 1; iVar18 = (**(code **)(*piVar21 + 0x14))(piVar21), iVar17 <= iVar18;
                iVar17 = iVar17 + 1) {
              iVar18 = FUN_0010b180(piVar21,iVar17);
              if (iVar26 == iVar18) {
                uVar30 = puVar13[2];
                if (uVar30 < *puVar1) {
                  _memset((void *)(uVar30 * 4 + puVar13[3]),0,4);
                  puVar13[2] = uVar30 + 1;
                  puVar19 = (undefined4 *)(uVar30 * 4 + puVar13[3]);
                }
                else {
                  puVar19 = (undefined4 *)FUN_001a7f7c(puVar1,uVar30);
                }
                *puVar19 = 0;
                if (local_38 < local_3c) {
                  iVar26 = local_38 * 4;
                  *(undefined4 *)(iVar26 + local_34) = 0;
                  local_38 = local_38 + 1;
                  *(undefined4 *)(iVar26 + local_34) = 0;
                }
                else {
                  puVar19 = (undefined4 *)FUN_001a7f7c(&local_3c,local_38);
                  *puVar19 = 0;
                }
                goto LAB_00147fa5;
              }
            }
            local_d0 = local_d0 + 1;
          } while (local_d0 < (uint)puVar13[2]);
        }
LAB_00147fa5:
        uVar25 = ((int (*)())FUN_00141dc0)(piVar21);
        uVar30 = puVar13[2];
        if (uVar30 < *puVar1) {
          _memset((void *)(uVar30 * 4 + puVar13[3]),0,4);
          puVar13[2] = uVar30 + 1;
          puVar19 = (undefined4 *)(uVar30 * 4 + puVar13[3]);
        }
        else {
          puVar19 = (undefined4 *)FUN_001a7f7c(puVar1,uVar30);
        }
        *puVar19 = piVar21;
        if (local_38 < local_3c) {
          iVar26 = local_38 * 4;
          *(undefined4 *)(iVar26 + local_34) = 0;
          local_38 = local_38 + 1;
          puVar19 = (undefined4 *)(iVar26 + local_34);
        }
        else {
          puVar19 = (undefined4 *)FUN_001a7f7c(&local_3c,local_38);
        }
        *puVar19 = uVar25;
        piVar21 = (int *)piVar21[2];
        if (piVar21[2] == 0) goto LAB_00148048;
      }
      piVar21 = (int *)piVar21[2];
      iVar26 = piVar21[2];
    }
LAB_00148048:
    if (puVar13[2] != 0) {
      local_54 = 0;
      if (local_3c == 0) goto LAB_001481c0;
LAB_00148064:
      if (local_38 <= local_54) {
        _memset((void *)(local_34 + local_38 * 4),0,(local_54 - local_38) * 4 + 4);
        local_38 = local_54 + 1;
      }
      local_c0 = *(uint *)(local_34 + local_54 * 4);
      if (*puVar1 <= local_54) goto LAB_001481e5;
LAB_0014808b:
      uVar30 = puVar13[2];
      if (uVar30 <= local_54) {
        _memset((void *)(puVar13[3] + uVar30 * 4),0,(local_54 - uVar30) * 4 + 4);
        puVar13[2] = local_54 + 1;
      }
      piVar21 = (int *)(puVar13[3] + local_54 * 4);
      uVar30 = local_54;
      do {
        local_54 = uVar30 + 1;
        iVar26 = *piVar21;
        if ((iVar26 != 0) && (local_54 < (uint)puVar13[2])) {
          local_5c = local_54 * 4;
          local_60 = uVar30 + 2;
LAB_0014816c:
          uVar30 = local_60 - 1;
          if (uVar30 < *puVar1) {
            uVar5 = puVar13[2];
            if (uVar5 <= uVar30) {
              _memset((void *)(puVar13[3] + uVar5 * 4),0,(uVar30 - uVar5) * 4 + 4);
              puVar13[2] = local_60;
            }
            piVar21 = *(int **)(local_5c + puVar13[3]);
          }
          else {
            puVar19 = (undefined4 *)FUN_001a7f7c(puVar1,uVar30);
            piVar21 = (int *)*puVar19;
          }
          if (piVar21 == (int *)0x0) goto LAB_001481a2;
          if (uVar30 < local_3c) {
            if (local_38 <= uVar30) {
              _memset((void *)(local_34 + local_38 * 4),0,(uVar30 - local_38) * 4 + 4);
              local_38 = local_60;
            }
            puVar20 = (uint *)(local_5c + local_34);
          }
          else {
            puVar20 = (uint *)FUN_001a7f7c(&local_3c,uVar30);
          }
          uVar5 = *puVar20;
          iVar17 = ((int (*)())FUN_00140816)(local_c0);
          iVar18 = ((int (*)())FUN_00140816)(uVar5);
          if (4 < iVar17 + iVar18) goto LAB_00148151;
          piVar22 = (int *)FUN_0010b180(iVar26,1);
          local_98 = (int *)FUN_0010b180(iVar26,2);
          piVar23 = (int *)FUN_0010b180(piVar21,1);
          piVar24 = (int *)FUN_0010b180(piVar21,2);
          iVar17 = (*(uint *)(iVar26 + 0xb8) >> 1 & 1) + (*(uint *)(iVar26 + 0xb8) & 1) * 2;
          iVar18 = (*(uint *)(iVar26 + 0xd0) >> 1 & 1) + (*(uint *)(iVar26 + 0xd0) & 1) * 2;
          iVar28 = ((uint)piVar21[0x2e] >> 1 & 1) + (piVar21[0x2e] & 1U) * 2;
          iVar2 = ((uint)piVar21[0x34] >> 1 & 1) + (piVar21[0x34] & 1U) * 2;
          if ((piVar22 == piVar23) && (iVar17 == iVar28)) {
            bVar7 = true;
            if (piVar22 != piVar24) goto LAB_00148305;
LAB_0014881a:
            if (iVar17 != iVar2) goto LAB_00148305;
            bVar10 = true;
          }
          else {
            bVar7 = false;
            if (piVar22 == piVar24) goto LAB_0014881a;
LAB_00148305:
            bVar10 = false;
          }
          if ((local_98 == piVar23) && (iVar18 == iVar28)) {
            bVar8 = true;
          }
          else {
            bVar8 = false;
          }
          if ((local_98 == piVar24) && (iVar18 == iVar2)) {
            bVar9 = true;
          }
          else {
            bVar9 = false;
          }
          piVar29 = piVar24;
          if ((((!bVar7) && (piVar29 = piVar23, !bVar10)) &&
              (piVar29 = piVar24, local_98 = piVar22, !bVar8)) && (piVar29 = piVar23, !bVar9))
          goto LAB_00148151;
          cVar12 = (**(code **)(*local_98 + 0x60))(local_98);
          if (cVar12 != '\0') {
            local_98 = (int *)FUN_0010b180(local_98,1);
          }
          cVar12 = (**(code **)(*piVar29 + 0x60))(piVar29);
          if (cVar12 == '\0') {
            piVar22 = (int *)0x0;
            local_50 = piVar29;
          }
          else {
            local_50 = (int *)FUN_0010b180(piVar29,1);
            piVar22 = piVar29;
          }
          cVar12 = (**(code **)(*local_98 + 0x48))(local_98);
          if ((((cVar12 == '\0') &&
               (cVar12 = (**(code **)(*local_50 + 0x48))(local_50), cVar12 == '\0')) &&
              ((iVar17 = (**(code **)(*local_98 + 0x80))(local_98), iVar17 == 0 &&
               (iVar17 = (**(code **)(*local_50 + 0x80))(local_50), iVar17 == 0)))) ||
             (cVar12 = ((int (*)())FUN_0014086a)(iVar26,piVar21), cVar12 == '\0')) goto LAB_001481a2;
          if (uVar30 < *puVar1) {
            uVar6 = puVar13[2];
            if (uVar6 <= uVar30) {
              _memset((void *)(puVar13[3] + uVar6 * 4),0,(uVar30 - uVar6) * 4 + 4);
              puVar13[2] = local_60;
            }
            puVar19 = (undefined4 *)(puVar13[3] + uVar30 * 4);
          }
          else {
            puVar19 = (undefined4 *)FUN_001a7f7c(puVar1,uVar30);
          }
          *puVar19 = 0;
          FUN_0010c18e(piVar21,iVar26,1,*(undefined4 *)(param_1 + 8));
          FUN_001a7d72(piVar21);
          FUN_000e9596(*(undefined4 *)(iVar26 + 0x158),iVar26,piVar21);
          if (piVar22 != (int *)0x0) {
            FUN_001a7d72(piVar22);
            FUN_000e9596(*(undefined4 *)(iVar26 + 0x158),iVar26,piVar22);
          }
          local_24 = DAT_001cc53c;
          local_20[0] = local_24;
          iVar17 = FUN_0010b0f4(piVar21,0);
          iVar17 = *(int *)(iVar17 + 0x10);
          (*(unsigned char *)((unsigned char *)&(local_28) + 3)) = (char)((uint)iVar17 >> 0x18);
          cVar12 = (*(unsigned char *)((unsigned char *)&(local_28) + 3));
          local_28 = iVar17;
          if ((local_c0 & uVar5) == 0) {
            *(int *)(param_1 + 0x278) = *(int *)(param_1 + 0x278) + 1;
            FUN_0010c18e(piVar21,iVar26,1,*(undefined4 *)(param_1 + 8));
            iVar26 = FUN_0010b0f4(piVar21,piVar21[0x21]);
            *(undefined4 *)(iVar26 + 0x10) = DAT_001cc538;
            iVar26 = 0;
            uVar30 = local_c0;
            while( true ) {
              if ((uVar30 & 1) != 0) {
                (**(code **)(*piVar21 + 0x88))(piVar21,piVar21[0x21],iVar26,iVar26);
              }
              iVar26 = iVar26 + 1;
              if (iVar26 == 4) break;
              uVar30 = (int)local_c0 >> ((byte)iVar26 & 0x1f);
            }
            goto LAB_001481a2;
          }
          *(int *)(param_1 + 0x278) = *(int *)(param_1 + 0x278) + 1;
          iVar17 = 0;
          local_100 = 0;
          do {
            if ((((int)(local_c0 & uVar5) >> ((byte)local_100 & 0x1f) & 1U) != 0) && (iVar17 < 4)) {
              do {
                if (((int)(~(local_c0 | uVar5) & 0xf) >> ((byte)iVar17 & 0x1f) & 1U) != 0) {
                  *(byte *)((int)local_20 + local_100) = (byte)iVar17;
                  *(byte *)((int)local_20 + iVar17 + -4) = (byte)local_100;
                  *(undefined1 *)((int)&local_28 + local_100) = 1;
                  *(undefined1 *)((int)&local_28 + iVar17) = 0;
                  iVar17 = iVar17 + 1;
                  break;
                }
                iVar17 = iVar17 + 1;
              } while (iVar17 != 4);
            }
            local_100 = local_100 + 1;
          } while (local_100 != 4);
          piVar21[0x27] = local_28;
          iVar17 = FUN_0010b0f4(piVar21,piVar21[0x21]);
          *(undefined4 *)(iVar17 + 0x10) = DAT_001cc538;
          iVar17 = 0;
          do {
            if (((int)local_c0 >> ((byte)iVar17 & 0x1f) & 1U) != 0) {
              (**(code **)(*piVar21 + 0x88))
                        (piVar21,piVar21[0x21],*(undefined1 *)((int)local_20 + iVar17),
                         *(undefined1 *)((int)local_20 + iVar17));
            }
            iVar17 = iVar17 + 1;
          } while (iVar17 != 4);
          if ((cVar12 == '\0') || ((*(unsigned char *)((unsigned char *)&(local_28) + 3)) != '\0')) {
            local_94 = (int *)0x0;
          }
          else {
            uVar25 = *(undefined4 *)(param_1 + 8);
            iVar17 = FUN_0010b180(piVar21,piVar21[0x21]);
            puVar20 = *(uint **)(iVar17 + 0x10);
            if (0 < (int)puVar20[1]) {
              uVar30 = 0;
              do {
                if (uVar30 < *puVar20) {
                  uVar6 = puVar20[1];
                  if (uVar6 <= uVar30) {
                    _memset((void *)(puVar20[2] + uVar6 * 4),0,(uVar30 - uVar6) * 4 + 4);
                    puVar20[1] = uVar30 + 1;
                  }
                  puVar19 = (undefined4 *)(puVar20[2] + uVar30 * 4);
                }
                else {
                  puVar19 = (undefined4 *)FUN_001a7f7c(puVar20,uVar30);
                }
                if ((int *)*puVar19 == piVar21) {
                  FUN_001a7f3c(puVar20,uVar30);
                  iVar17 = FUN_0010b180(piVar21,piVar21[0x21]);
                  *(int *)(iVar17 + 0x160) = *(int *)(iVar17 + 0x160) + -1;
                  break;
                }
                uVar30 = uVar30 + 1;
              } while ((int)uVar30 < (int)puVar20[1]);
            }
            FUN_0010ba02(piVar21,piVar21[0x21],0,1,uVar25);
            iVar17 = piVar21[0x21];
            piVar21[0x21] = iVar17 + -1;
            piVar21[5] = piVar21[5] & 0xfffffdff;
            iVar17 = FUN_0010b0f4(piVar21,iVar17 + -1);
            uVar25 = *(undefined4 *)(iVar17 + 0x10);
            local_94 = (int *)FUN_0010a1c2(piVar21,*(undefined4 *)(param_1 + 8),0);
            uVar27 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
            puVar19 = (undefined4 *)FUN_001a7bca(uVar27,0x14);
            *puVar19 = uVar27;
            puVar19[4] = uVar27;
            puVar19[2] = 0;
            puVar19[1] = 2;
            uVar27 = FUN_001a7bca(uVar27,8);
            puVar19[3] = uVar27;
            local_94[4] = (int)(puVar19 + 1);
            local_94[0x58] = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x3f4) + 0x46c);
            FUN_0010c18e(piVar21,iVar26,1,*(undefined4 *)(param_1 + 8));
            iVar17 = FUN_0010b0f4(piVar21,piVar21[0x21]);
            *(undefined4 *)(iVar17 + 0x10) = uVar25;
            *(undefined1 *)((int)piVar21 + 0x9f) = 1;
            local_94[0x27] = DAT_001cc548;
            FUN_000e9596(piVar21[0x56],piVar21,local_94);
            FUN_0010c18e(local_94,piVar21,1,*(undefined4 *)(param_1 + 8));
            iVar17 = FUN_0010b0f4(local_94,local_94[0x21]);
            *(undefined4 *)(iVar17 + 0x10) = DAT_001cc538;
            iVar17 = 0;
            do {
              if ((((int)uVar5 >> ((byte)iVar17 & 0x1f) & 1U) != 0) && (iVar17 != 3)) {
                (**(code **)(*local_94 + 0x88))(local_94,local_94[0x21],iVar17,iVar17);
              }
              if ((((int)local_c0 >> ((byte)iVar17 & 0x1f) & 1U) != 0) &&
                 (cVar12 = *(char *)((int)local_20 + iVar17), cVar12 != '\x03')) {
                (**(code **)(*local_94 + 0x88))(local_94,local_94[0x21],cVar12,cVar12);
              }
              iVar17 = iVar17 + 1;
            } while (iVar17 != 4);
            iVar17 = piVar21[0x26];
            iVar18 = local_94[0x53];
            iVar28 = FUN_0010b0f4(local_94,0);
            *(int *)(iVar28 + 8) = iVar18;
            *(int *)(iVar28 + 0xc) = iVar17;
            for (local_88 = 1; iVar17 = (**(code **)(*local_94 + 0x14))(local_94),
                local_88 <= iVar17; local_88 = local_88 + 1) {
              iVar17 = FUN_0010b180(local_94,local_88);
              puVar20 = *(uint **)(iVar17 + 0x10);
              uVar30 = puVar20[1];
              if (uVar30 < *puVar20) {
                _memset((void *)(uVar30 * 4 + puVar20[2]),0,4);
                puVar20[1] = uVar30 + 1;
                puVar19 = (undefined4 *)(uVar30 * 4 + puVar20[2]);
              }
              else {
                puVar19 = (undefined4 *)FUN_001a7f7c(puVar20,uVar30);
              }
              *puVar19 = local_94;
            }
          }
          uVar30 = local_24 >> 0x18;
          for (iVar17 = 1; iVar18 = (**(code **)(*piVar21 + 0x14))(piVar21), iVar17 <= iVar18;
              iVar17 = iVar17 + 1) {
            iVar18 = FUN_0010b0f4(piVar21,iVar17);
            local_2c = *(undefined4 *)(iVar18 + 0x10);
            local_80 = 0;
            iVar18 = 0;
            do {
              if (*(char *)((int)&local_28 + iVar18) == '\0') {
                if ((local_94 == (int *)0x0) || (iVar18 != 3)) {
                  local_80 = local_80 + 1;
                  (**(code **)(*piVar21 + 0x88))
                            (piVar21,iVar17,iVar18,
                             *(undefined1 *)
                              ((int)&local_2c + (uint)*(byte *)((int)local_20 + iVar18 + -4)));
                }
                else {
                  (**(code **)(*piVar21 + 0x88))(piVar21,iVar17,3,4);
                  (**(code **)(*local_94 + 0x88))
                            (local_94,iVar17,3,*(undefined1 *)((int)&local_2c + uVar30));
                }
              }
              else {
                (**(code **)(*piVar21 + 0x88))(piVar21,iVar17,iVar18,4);
                if (local_94 != (int *)0x0) {
                  (**(code **)(*local_94 + 0x88))(local_94,iVar17,iVar18,4);
                }
              }
              iVar18 = iVar18 + 1;
            } while (iVar18 != 4);
            if (local_80 == 1) {
              uVar25 = FUN_001122ce(piVar21,iVar17,param_1);
              iVar18 = FUN_0010b0f4(piVar21,iVar17);
              *(undefined4 *)(iVar18 + 0x10) = uVar25;
            }
            if (local_94 != (int *)0x0) {
              uVar25 = FUN_001122ce(local_94,iVar17,param_1);
              iVar18 = FUN_0010b0f4(local_94,iVar17);
              *(undefined4 *)(iVar18 + 0x10) = uVar25;
            }
          }
          puVar20 = (uint *)piVar21[4];
          local_7c = puVar20[1] - 1;
          if (-1 < (int)local_7c) {
            local_68 = local_7c * 4;
            if (*puVar20 <= local_7c) goto LAB_00148a06;
LAB_001489a6:
            uVar30 = puVar20[1];
            if (uVar30 <= local_7c) {
              _memset((void *)(puVar20[2] + uVar30 * 4),0,(local_7c - uVar30) * 4 + 4);
              puVar20[1] = local_7c + 1;
            }
            puVar19 = (undefined4 *)(local_68 + puVar20[2]);
            do {
              piVar22 = (int *)*puVar19;
              iVar17 = 1;
LAB_001489d8:
              iVar18 = (**(code **)(*piVar22 + 0x14))(piVar22);
              if (iVar17 <= iVar18) {
                piVar23 = (int *)FUN_0010b180(piVar22,iVar17);
                if (piVar23 != piVar21) goto code_r0x001489d5;
                if (local_94 != (int *)0x0) {
                  FUN_0010ba02(piVar22,iVar17,local_94,1,*(undefined4 *)(param_1 + 8));
                }
                local_78 = 0;
                do {
                  iVar18 = FUN_0010b0f4(piVar22,iVar17);
                  bVar3 = *(byte *)(local_78 + 0x10 + iVar18);
                  if (bVar3 != 4) {
                    (**(code **)(*piVar22 + 0x88))
                              (piVar22,iVar17,local_78,*(undefined1 *)((int)local_20 + (uint)bVar3))
                    ;
                  }
                  local_78 = local_78 + 1;
                } while (local_78 != 4);
              }
              if (local_7c == 0) break;
              local_68 = local_68 + -4;
              local_7c = local_7c - 1;
              puVar20 = (uint *)piVar21[4];
              if (local_7c < *puVar20) goto LAB_001489a6;
LAB_00148a06:
              puVar19 = (undefined4 *)FUN_001a7f7c(puVar20,local_7c);
            } while( true );
          }
          puVar20 = *(uint **)(iVar26 + 0x10);
          local_74 = puVar20[1] - 1;
          if (-1 < (int)local_74) {
            local_70 = local_74 * 4;
            if (*puVar20 <= local_74) goto LAB_00148b2f;
LAB_00148ad0:
            uVar30 = puVar20[1];
            if (uVar30 <= local_74) {
              _memset((void *)(puVar20[2] + uVar30 * 4),0,(local_74 - uVar30) * 4 + 4);
              puVar20[1] = local_74 + 1;
            }
            puVar19 = (undefined4 *)(local_70 + puVar20[2]);
            do {
              piVar21 = (int *)*puVar19;
              for (iVar17 = 1; iVar18 = (**(code **)(*piVar21 + 0x14))(piVar21), iVar17 <= iVar18;
                  iVar17 = iVar17 + 1) {
                iVar18 = FUN_0010b180(piVar21,iVar17);
                if (iVar26 == iVar18) {
                  if (local_94 != (int *)0x0) {
                    FUN_0010ba02(piVar21,iVar17,local_94,1,*(undefined4 *)(param_1 + 8));
                  }
                  break;
                }
              }
              local_74 = local_74 - 1;
              local_70 = local_70 + -4;
              if (local_74 == 0xffffffff) break;
              puVar20 = *(uint **)(iVar26 + 0x10);
              if (local_74 < *puVar20) goto LAB_00148ad0;
LAB_00148b2f:
              puVar19 = (undefined4 *)FUN_001a7f7c(puVar20,local_74);
            } while( true );
          }
        }
LAB_001481a2:
        if ((uint)puVar13[2] <= local_54) break;
        if (local_54 < local_3c) goto LAB_00148064;
LAB_001481c0:
        puVar20 = (uint *)FUN_001a7f7c(&local_3c,local_54);
        local_c0 = *puVar20;
        if (local_54 < *puVar1) goto LAB_0014808b;
LAB_001481e5:
        piVar21 = (int *)FUN_001a7f7c(puVar1,local_54);
        uVar30 = local_54;
      } while( true );
    }
    iVar4 = *(int *)(iVar4 + 8);
    iVar26 = *(int *)(iVar4 + 8);
  } while( true );
LAB_00148151:
  local_5c = local_5c + 4;
  bVar7 = (uint)puVar13[2] <= local_60;
  local_60 = local_60 + 1;
  if (bVar7) goto LAB_001481a2;
  goto LAB_0014816c;
code_r0x001489d5:
  iVar17 = iVar17 + 1;
  goto LAB_001489d8;
}

/* FUN_00149328 @ 0x149328 (28 bytes) */
int FUN_00149328(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}

/* FUN_00149344 @ 0x149344 (11 bytes) */
int FUN_00149344(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(undefined4 *)(param_2 + 0xc);
}

/* FUN_00149350 @ 0x149350 (383 bytes) */
int FUN_00149350(param_1, param_2, param_3)
  undefined4 *param_1;
  int *param_2;
  int *param_3;
{
  char cVar1;
  int iVar2;
  byte local_1c;
  byte local_18;
  int local_10;
  
  if ((((((*(int *)(param_2[0x22] + 8) == *(int *)(param_3[0x22] + 8)) &&
         (cVar1 = FUN_001195a6(*param_1,param_2), cVar1 != '\0')) &&
        (cVar1 = (**(code **)(*param_2 + 100))(param_2), cVar1 == '\0')) &&
       ((param_2[0x20] != 0 && (cVar1 = FUN_0012dfd8(param_2[0x26]), cVar1 != '\0')))) &&
      (((*(byte *)(param_2 + 5) & 2) == 0 &&
       ((cVar1 = (**(code **)(*param_2 + 0x50))(param_2), cVar1 == '\0' && (param_3[0x20] != 0))))))
     && ((cVar1 = FUN_0012dfd8(param_3[0x26]), cVar1 != '\0' &&
         (((((*(byte *)(param_3 + 5) & 2) == 0 &&
            (cVar1 = (**(code **)(*param_3 + 0x50))(param_3), cVar1 == '\0')) &&
           ((char)param_2[0x48] == (char)param_3[0x48])) && (param_2[0x49] == param_3[0x49])))))) {
    iVar2 = param_2[0x21] + -1 + (uint)((param_2[5] & 0x200U) == 0);
    if (iVar2 < 1) {
      return 1;
    }
    if ((((byte)param_3[0x2e] & 1) == ((byte)param_2[0x2e] & 1)) &&
       (local_1c = (byte)((uint)param_3[0x2e] >> 1) & 1,
       ((byte)((uint)param_2[0x2e] >> 1) & 1) == local_1c)) {
      local_10 = 1;
      do {
        local_10 = local_10 + 1;
        if (iVar2 < local_10) {
          return 1;
        }
      } while ((((byte)param_3[local_10 * 6 + 0x28] & 1) == ((byte)param_2[local_10 * 6 + 0x28] & 1)
               ) && (local_18 = (byte)((uint)param_3[local_10 * 6 + 0x28] >> 1) & 1,
                    local_18 == ((byte)((uint)param_2[local_10 * 6 + 0x28] >> 1) & 1)));
    }
  }
  return 0;
}

