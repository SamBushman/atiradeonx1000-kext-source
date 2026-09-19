#include "decls.h"

/* FUN_0012c3c6 @ 0x12c3c6 (674 bytes) */
int FUN_0012c3c6(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001fce48;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  uVar4 = *(undefined4 *)(param_5 + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x168);
  *puVar3 = uVar4;
  puVar1 = puVar3 + 1;
  FUN_0010dfac(puVar1,param_5);
  iVar2 = *(int *)(param_5 + 0x3f4);
  FUN_000e9540(*(undefined4 *)(iVar2 + 0x39c),puVar1);
  FUN_0010a3c2(puVar1,0,param_1);
  FUN_0012a42e(param_1,puVar1);
  param_1[0xc] = puVar1;
  puVar3[0x50] = param_3;
  puVar3[0x51] = param_2;
  uVar4 = FUN_000edb1c(iVar2,param_3);
  uVar4 = FUN_000edb48(iVar2,uVar4);
  FUN_00109ed6(puVar1,0,uVar4,param_2);
  uVar4 = FUN_000edb1c(iVar2,param_3);
  uVar4 = FUN_000edb48(iVar2,uVar4);
  FUN_00109ed6(puVar1,1,uVar4,param_2);
  uVar4 = FUN_000edb1c(iVar2,param_3);
  uVar4 = FUN_000edb48(iVar2,uVar4);
  FUN_00109ed6(puVar1,2,uVar4,param_2);
  uVar4 = FUN_000edb1c(iVar2,param_3);
  uVar4 = FUN_000edb48(iVar2,uVar4);
  FUN_00109ed6(puVar1,3,uVar4,param_2);
  iVar5 = *(int *)(param_5 + 0xf0) + -1;
  *(int *)(param_5 + 0xf0) = iVar5;
  uVar4 = FUN_0012eb2a(*(undefined4 *)(iVar2 + 0x3a0),0,iVar5,0);
  param_1[0xd] = uVar4;
  FUN_0010a3c2(puVar1,1,uVar4);
  FUN_0012a9e6(param_1[0xd],1,puVar1);
  if (param_3 == 8) {
    iVar5 = FUN_0010b0f4(puVar1,1);
    *(undefined4 *)(iVar5 + 0x10) = DAT_001cc410;
    uVar4 = (**(code **)(**(int **)(param_5 + 0x54) + 0x118))(*(int **)(param_5 + 0x54));
    puVar3[0x28] = uVar4;
    *(undefined4 **)(iVar2 + 0x34c) = puVar1;
    return;
  }
  if (param_3 == 9) {
    if (param_1[2] == 0) {
      *(undefined4 **)(iVar2 + 0x348) = puVar1;
      return;
    }
  }
  else {
    if (param_3 == 6) {
      *(undefined4 **)(iVar2 + 0x358) = puVar1;
      return;
    }
    if (param_3 == 7) {
      *(undefined4 **)(iVar2 + 0x35c) = puVar1;
      *(undefined1 *)(iVar2 + 0x362) = 1;
    }
  }
  return;
}

/* FUN_0012c69a @ 0x12c69a (674 bytes) */
int FUN_0012c69a(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001fce48;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  uVar4 = *(undefined4 *)(param_5 + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x168);
  *puVar3 = uVar4;
  puVar1 = puVar3 + 1;
  FUN_0010dfac(puVar1,param_5);
  iVar2 = *(int *)(param_5 + 0x3f4);
  FUN_000e9540(*(undefined4 *)(iVar2 + 0x39c),puVar1);
  FUN_0010a3c2(puVar1,0,param_1);
  FUN_0012a42e(param_1,puVar1);
  param_1[0xc] = puVar1;
  puVar3[0x50] = param_3;
  puVar3[0x51] = param_2;
  uVar4 = FUN_000edb1c(iVar2,param_3);
  uVar4 = FUN_000edb48(iVar2,uVar4);
  FUN_00109ed6(puVar1,0,uVar4,param_2);
  uVar4 = FUN_000edb1c(iVar2,param_3);
  uVar4 = FUN_000edb48(iVar2,uVar4);
  FUN_00109ed6(puVar1,1,uVar4,param_2);
  uVar4 = FUN_000edb1c(iVar2,param_3);
  uVar4 = FUN_000edb48(iVar2,uVar4);
  FUN_00109ed6(puVar1,2,uVar4,param_2);
  uVar4 = FUN_000edb1c(iVar2,param_3);
  uVar4 = FUN_000edb48(iVar2,uVar4);
  FUN_00109ed6(puVar1,3,uVar4,param_2);
  iVar5 = *(int *)(param_5 + 0xf0) + -1;
  *(int *)(param_5 + 0xf0) = iVar5;
  uVar4 = FUN_0012eb2a(*(undefined4 *)(iVar2 + 0x3a0),0,iVar5,0);
  param_1[0xd] = uVar4;
  FUN_0010a3c2(puVar1,1,uVar4);
  FUN_0012a9e6(param_1[0xd],1,puVar1);
  if (param_3 == 8) {
    iVar5 = FUN_0010b0f4(puVar1,1);
    *(undefined4 *)(iVar5 + 0x10) = DAT_001cc410;
    uVar4 = (**(code **)(**(int **)(param_5 + 0x54) + 0x118))(*(int **)(param_5 + 0x54));
    puVar3[0x28] = uVar4;
    *(undefined4 **)(iVar2 + 0x34c) = puVar1;
    return;
  }
  if (param_3 == 9) {
    if (param_1[2] == 0) {
      *(undefined4 **)(iVar2 + 0x348) = puVar1;
      return;
    }
  }
  else {
    if (param_3 == 6) {
      *(undefined4 **)(iVar2 + 0x358) = puVar1;
      return;
    }
    if (param_3 == 7) {
      *(undefined4 **)(iVar2 + 0x35c) = puVar1;
      *(undefined1 *)(iVar2 + 0x362) = 1;
    }
  }
  return;
}

/* FUN_0012c96e @ 0x12c96e (1325 bytes) */
int FUN_0012c96e(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 local_38;
  undefined4 local_24;
  int local_20 [4];
  
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001fce88;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  iVar5 = *(int *)(param_5 + 0x3f4);
  if ((*(uint *)(iVar5 + 0x30) & 0x2000) != 0) {
    cVar1 = ((int (*)())FUN_0012dfd8)(param_1[1]);
    if (cVar1 != '\0') {
      iVar3 = *(int *)(param_5 + 0x78);
      param_1[7] = iVar3;
      *(int *)(param_5 + 0x78) = iVar3 + 1;
      param_1[4] = param_2;
    }
    uVar4 = *(undefined4 *)(param_5 + 0xb8);
    puVar6 = (undefined4 *)FUN_001a7bca(uVar4,0x168);
    *puVar6 = uVar4;
    puVar6 = puVar6 + 1;
    FUN_0010e6e2(puVar6,param_5);
    param_1[0xe] = puVar6;
    (**(code **)(**(int **)(iVar5 + 0x394) + 0xc))(*(int **)(iVar5 + 0x394),puVar6);
    FUN_0010a3c2(param_1[0xe],0,param_1);
    FUN_0012a42e(param_1,param_1[0xe]);
    *(int *)(param_1[0xe] + 0x144) = param_3;
    *(undefined4 *)(param_1[0xe] + 0x148) = param_2;
    return;
  }
  if ((*(uint *)(iVar5 + 0x30) & 1) == 0) {
    return;
  }
  uVar4 = *(undefined4 *)(param_5 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar4,0x168);
  *puVar2 = uVar4;
  puVar6 = puVar2 + 1;
  FUN_0010dfac(puVar6,param_5);
  FUN_000e9512(*(undefined4 *)(iVar5 + 0x39c),puVar6);
  FUN_0010a3c2(puVar6,0,param_1);
  FUN_0012a42e(param_1,puVar6);
  param_1[0xc] = puVar6;
  iVar3 = *(int *)(param_5 + 0xf0) + -1;
  *(int *)(param_5 + 0xf0) = iVar3;
  uVar4 = FUN_0012eb2a(*(undefined4 *)(iVar5 + 0x3a0),0,iVar3,0);
  param_1[0xf] = uVar4;
  cVar1 = (**(code **)(**(int **)(param_5 + 0x54) + 0x120))(*(int **)(param_5 + 0x54),iVar5,param_5)
  ;
  if (cVar1 == '\0') goto LAB_0012cabd;
  local_20[0] = 6;
  local_24 = 0;
  cVar1 = ((int (*)())FUN_0012e94e)(*(undefined4 *)(iVar5 + 0x3a0),param_1[1],param_2,local_20,&local_24);
  if (cVar1 == '\0') goto LAB_0012cabd;
  if (local_20[0] == 0x3f) {
    local_38 = 0xd;
  }
  else if (local_20[0] < 0x40) {
    if (local_20[0] == 0x3e) {
      local_38 = 0xb;
    }
    else {
LAB_0012cd37:
      local_38 = 5;
    }
  }
  else if (local_20[0] == 0x40) {
    local_38 = 0xe;
  }
  else {
    if (local_20[0] != 0x41) goto LAB_0012cd37;
    local_38 = 0xc;
  }
  uVar7 = FUN_0012eb2a(*(undefined4 *)(iVar5 + 0x3a0),local_20[0],local_24,0);
  uVar4 = *(undefined4 *)(param_5 + 0xb8);
  puVar8 = (undefined4 *)FUN_001a7bca(uVar4,0x168);
  *puVar8 = uVar4;
  puVar8 = puVar8 + 1;
  FUN_0010dfac(puVar8,param_5);
  param_1[0xd] = puVar8;
  FUN_000e9512(*(undefined4 *)(iVar5 + 0x39c),puVar8);
  FUN_0010a3c2(param_1[0xd],1,param_1[0xf]);
  FUN_0010a3c2(param_1[0xd],0,uVar7);
  *(undefined4 *)(param_1[0xd] + 0x9c) = DAT_001cc41c;
  FUN_0012a42e(uVar7,param_1[0xd]);
  iVar3 = 0;
  do {
    FUN_00109ed6(param_1[0xd],iVar3,local_38,local_24);
    iVar3 = iVar3 + 1;
  } while (iVar3 != 4);
LAB_0012cabd:
  FUN_0010a3c2(puVar6,1,param_1[0xf]);
  FUN_0012a9e6(param_1[0xf],1,puVar6);
  puVar2[0x50] = param_3;
  puVar2[0x51] = param_2;
  uVar4 = FUN_000edb1c(iVar5,param_3);
  uVar4 = FUN_000edb48(iVar5,uVar4);
  FUN_00109ed6(puVar6,0,uVar4,param_2);
  uVar4 = FUN_000edb1c(iVar5,param_3);
  uVar4 = FUN_000edb48(iVar5,uVar4);
  FUN_00109ed6(puVar6,1,uVar4,param_2);
  uVar4 = FUN_000edb1c(iVar5,param_3);
  uVar4 = FUN_000edb48(iVar5,uVar4);
  FUN_00109ed6(puVar6,2,uVar4,param_2);
  uVar4 = FUN_000edb1c(iVar5,param_3);
  uVar4 = FUN_000edb48(iVar5,uVar4);
  FUN_00109ed6(puVar6,3,uVar4,param_2);
  if (param_3 == 0x18) {
    iVar5 = FUN_0010b0f4(puVar6,1);
    *(undefined4 *)(iVar5 + 0x10) = DAT_001cc410;
    uVar4 = (**(code **)(**(int **)(param_5 + 0x54) + 0x1c))(*(int **)(param_5 + 0x54));
    puVar2[0x28] = uVar4;
  }
  return;
}

/* FUN_0012cefa @ 0x12cefa (1325 bytes) */
int FUN_0012cefa(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 local_38;
  undefined4 local_24;
  int local_20 [4];
  
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001fce88;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  iVar5 = *(int *)(param_5 + 0x3f4);
  if ((*(uint *)(iVar5 + 0x30) & 0x2000) != 0) {
    cVar1 = ((int (*)())FUN_0012dfd8)(param_1[1]);
    if (cVar1 != '\0') {
      iVar3 = *(int *)(param_5 + 0x78);
      param_1[7] = iVar3;
      *(int *)(param_5 + 0x78) = iVar3 + 1;
      param_1[4] = param_2;
    }
    uVar4 = *(undefined4 *)(param_5 + 0xb8);
    puVar6 = (undefined4 *)FUN_001a7bca(uVar4,0x168);
    *puVar6 = uVar4;
    puVar6 = puVar6 + 1;
    FUN_0010e6e2(puVar6,param_5);
    param_1[0xe] = puVar6;
    (**(code **)(**(int **)(iVar5 + 0x394) + 0xc))(*(int **)(iVar5 + 0x394),puVar6);
    FUN_0010a3c2(param_1[0xe],0,param_1);
    FUN_0012a42e(param_1,param_1[0xe]);
    *(int *)(param_1[0xe] + 0x144) = param_3;
    *(undefined4 *)(param_1[0xe] + 0x148) = param_2;
    return;
  }
  if ((*(uint *)(iVar5 + 0x30) & 1) == 0) {
    return;
  }
  uVar4 = *(undefined4 *)(param_5 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar4,0x168);
  *puVar2 = uVar4;
  puVar6 = puVar2 + 1;
  FUN_0010dfac(puVar6,param_5);
  FUN_000e9512(*(undefined4 *)(iVar5 + 0x39c),puVar6);
  FUN_0010a3c2(puVar6,0,param_1);
  FUN_0012a42e(param_1,puVar6);
  param_1[0xc] = puVar6;
  iVar3 = *(int *)(param_5 + 0xf0) + -1;
  *(int *)(param_5 + 0xf0) = iVar3;
  uVar4 = FUN_0012eb2a(*(undefined4 *)(iVar5 + 0x3a0),0,iVar3,0);
  param_1[0xf] = uVar4;
  cVar1 = (**(code **)(**(int **)(param_5 + 0x54) + 0x120))(*(int **)(param_5 + 0x54),iVar5,param_5)
  ;
  if (cVar1 == '\0') goto LAB_0012d049;
  local_20[0] = 6;
  local_24 = 0;
  cVar1 = ((int (*)())FUN_0012e94e)(*(undefined4 *)(iVar5 + 0x3a0),param_1[1],param_2,local_20,&local_24);
  if (cVar1 == '\0') goto LAB_0012d049;
  if (local_20[0] == 0x3f) {
    local_38 = 0xd;
  }
  else if (local_20[0] < 0x40) {
    if (local_20[0] == 0x3e) {
      local_38 = 0xb;
    }
    else {
LAB_0012d2c3:
      local_38 = 5;
    }
  }
  else if (local_20[0] == 0x40) {
    local_38 = 0xe;
  }
  else {
    if (local_20[0] != 0x41) goto LAB_0012d2c3;
    local_38 = 0xc;
  }
  uVar7 = FUN_0012eb2a(*(undefined4 *)(iVar5 + 0x3a0),local_20[0],local_24,0);
  uVar4 = *(undefined4 *)(param_5 + 0xb8);
  puVar8 = (undefined4 *)FUN_001a7bca(uVar4,0x168);
  *puVar8 = uVar4;
  puVar8 = puVar8 + 1;
  FUN_0010dfac(puVar8,param_5);
  param_1[0xd] = puVar8;
  FUN_000e9512(*(undefined4 *)(iVar5 + 0x39c),puVar8);
  FUN_0010a3c2(param_1[0xd],1,param_1[0xf]);
  FUN_0010a3c2(param_1[0xd],0,uVar7);
  *(undefined4 *)(param_1[0xd] + 0x9c) = DAT_001cc41c;
  FUN_0012a42e(uVar7,param_1[0xd]);
  iVar3 = 0;
  do {
    FUN_00109ed6(param_1[0xd],iVar3,local_38,local_24);
    iVar3 = iVar3 + 1;
  } while (iVar3 != 4);
LAB_0012d049:
  FUN_0010a3c2(puVar6,1,param_1[0xf]);
  FUN_0012a9e6(param_1[0xf],1,puVar6);
  puVar2[0x50] = param_3;
  puVar2[0x51] = param_2;
  uVar4 = FUN_000edb1c(iVar5,param_3);
  uVar4 = FUN_000edb48(iVar5,uVar4);
  FUN_00109ed6(puVar6,0,uVar4,param_2);
  uVar4 = FUN_000edb1c(iVar5,param_3);
  uVar4 = FUN_000edb48(iVar5,uVar4);
  FUN_00109ed6(puVar6,1,uVar4,param_2);
  uVar4 = FUN_000edb1c(iVar5,param_3);
  uVar4 = FUN_000edb48(iVar5,uVar4);
  FUN_00109ed6(puVar6,2,uVar4,param_2);
  uVar4 = FUN_000edb1c(iVar5,param_3);
  uVar4 = FUN_000edb48(iVar5,uVar4);
  FUN_00109ed6(puVar6,3,uVar4,param_2);
  if (param_3 == 0x18) {
    iVar5 = FUN_0010b0f4(puVar6,1);
    *(undefined4 *)(iVar5 + 0x10) = DAT_001cc410;
    uVar4 = (**(code **)(**(int **)(param_5 + 0x54) + 0x1c))(*(int **)(param_5 + 0x54));
    puVar2[0x28] = uVar4;
  }
  return;
}

/* FUN_0012d486 @ 0x12d486 (103 bytes) */
int FUN_0012d486(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_002139d1 + 8;
  FUN_00137b7e(*(undefined4 *)(param_5 + 0x3f4),param_2);
  param_1[9] = param_1[9] | 2;
  param_1[4] = param_2;
  return;
}

/* FUN_0012d500 @ 0x12d500 (103 bytes) */
int FUN_0012d500(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_002139d1 + 8;
  FUN_00137b7e(*(undefined4 *)(param_5 + 0x3f4),param_2);
  param_1[9] = param_1[9] | 2;
  param_1[4] = param_2;
  return;
}

/* FUN_0012d57a @ 0x12d57a (80 bytes) */
int FUN_0012d57a(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001fcf48;
  param_1[4] = param_2 + param_3 * 0x10000;
  return;
}

/* FUN_0012d5ca @ 0x12d5ca (80 bytes) */
int FUN_0012d5ca(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001fcf48;
  param_1[4] = param_2 + param_3 * 0x10000;
  return;
}

/* FUN_0012d61a @ 0x12d61a (400 bytes) */
int FUN_0012d61a(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_20 [4];
  
  FUN_0012bdec(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_002139c1 + 8;
  iVar1 = *(int *)(param_5 + 0x3f4);
  local_20[0] = DAT_001cc418;
  uVar2 = (**(code **)(**(int **)(param_5 + 0x54) + 0xa4))
                    (*(int **)(param_5 + 0x54),local_20,param_5);
  uVar3 = FUN_0012eb84(*(undefined4 *)(iVar1 + 0x3a0),0x10,uVar2,0);
  uVar2 = *(undefined4 *)(param_5 + 0xb8);
  puVar4 = (undefined4 *)FUN_001a7bca(uVar2,0x168);
  *puVar4 = uVar2;
  puVar4 = puVar4 + 1;
  FUN_0010e916(puVar4,param_1,param_5);
  FUN_000e9540(*(undefined4 *)(iVar1 + 0x394),puVar4);
  FUN_0010a3c2(puVar4,0,uVar3);
  FUN_0012a42e(uVar3,puVar4);
  uVar5 = FUN_0010dbb8(0x31,param_5);
  FUN_0010a3c2(uVar5,1,uVar3);
  uVar2 = local_20[0];
  iVar6 = FUN_0010b0f4(uVar5,1);
  *(undefined4 *)(iVar6 + 0x10) = uVar2;
  FUN_0010a3c2(uVar5,0,param_1);
  FUN_0012a42e(param_1,uVar5);
  FUN_000e9512(*(undefined4 *)(iVar1 + 0x394),uVar5);
  return;
}

/* FUN_0012d7e4 @ 0x12d7e4 (82 bytes) */
int FUN_0012d7e4(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_002139c5 + 8;
  param_1[4] = param_2;
  param_1[0xc] = 0;
  return;
}

/* FUN_0012d836 @ 0x12d836 (82 bytes) */
int FUN_0012d836(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_002139c5 + 8;
  param_1[4] = param_2;
  param_1[0xc] = 0;
  return;
}

/* FUN_0012d888 @ 0x12d888 (75 bytes) */
int FUN_0012d888(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_002139e1 + 8;
  param_1[4] = param_2;
  return;
}

/* FUN_0012d8d4 @ 0x12d8d4 (75 bytes) */
int FUN_0012d8d4(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_002139e1 + 8;
  param_1[4] = param_2;
  return;
}

/* FUN_0012d920 @ 0x12d920 (106 bytes) */
int FUN_0012d920(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_002139e5 + 8;
  param_1[0xc] = 0;
  *param_1 = PTR_DAT_002139d5 + 8;
  param_1[4] = *(undefined4 *)(param_5 + 0x88);
  *(int *)(param_5 + 0x88) = *(int *)(param_5 + 0x88) + 1;
  return;
}

/* FUN_0012d98a @ 0x12d98a (81 bytes) */
int FUN_0012d98a(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_002139c9 + 8;
  param_1[9] = param_1[9] | 2;
  param_1[4] = 0x20;
  return;
}

/* FUN_0012d9dc @ 0x12d9dc (81 bytes) */
int FUN_0012d9dc(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_002139c9 + 8;
  param_1[9] = param_1[9] | 2;
  param_1[4] = 0x20;
  return;
}

/* FUN_0012da2e @ 0x12da2e (67 bytes) */
int FUN_0012da2e(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001fd008;
  return;
}

/* FUN_0012da72 @ 0x12da72 (67 bytes) */
int FUN_0012da72(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001fd008;
  return;
}

/* FUN_0012dab6 @ 0x12dab6 (313 bytes) */
int FUN_0012dab6(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001fcf08;
  param_1[9] = param_1[9] | 2;
  param_1[4] = param_2;
  if ((*(byte *)(*(int *)(param_5 + 0x3f4) + 0x31) & 0x40) == 0) {
    return;
  }
  uVar2 = *(undefined4 *)(param_5 + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar2,0x168);
  *puVar3 = uVar2;
  puVar1 = puVar3 + 1;
  FUN_0010dfac(puVar1,param_5);
  puVar3[0x28] = DAT_001cc414;
  FUN_0010a3c2(puVar1,0,param_1);
  FUN_0012a42e(param_1,puVar1);
  FUN_0010a3c2(puVar1,1,param_1);
  iVar4 = FUN_0010b0f4(puVar1,1);
  *(undefined4 *)(iVar4 + 0x10) = DAT_001cc410;
  FUN_0012a9e6(param_1,1,puVar1);
  FUN_000f0b74(*(undefined4 *)(param_5 + 0x3f4),puVar1);
  FUN_000e9512(*(undefined4 *)(*(int *)(param_5 + 0x3f4) + 0x39c),puVar1);
  return;
}

/* FUN_0012dc20 @ 0x12dc20 (313 bytes) */
int FUN_0012dc20(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001fcf08;
  param_1[9] = param_1[9] | 2;
  param_1[4] = param_2;
  if ((*(byte *)(*(int *)(param_5 + 0x3f4) + 0x31) & 0x40) == 0) {
    return;
  }
  uVar2 = *(undefined4 *)(param_5 + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar2,0x168);
  *puVar3 = uVar2;
  puVar1 = puVar3 + 1;
  FUN_0010dfac(puVar1,param_5);
  puVar3[0x28] = DAT_001cc414;
  FUN_0010a3c2(puVar1,0,param_1);
  FUN_0012a42e(param_1,puVar1);
  FUN_0010a3c2(puVar1,1,param_1);
  iVar4 = FUN_0010b0f4(puVar1,1);
  *(undefined4 *)(iVar4 + 0x10) = DAT_001cc410;
  FUN_0012a9e6(param_1,1,puVar1);
  FUN_000f0b74(*(undefined4 *)(param_5 + 0x3f4),puVar1);
  FUN_000e9512(*(undefined4 *)(*(int *)(param_5 + 0x3f4) + 0x39c),puVar1);
  return;
}

/* FUN_0012dd8a @ 0x12dd8a (106 bytes) */
int FUN_0012dd8a(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_002139e5 + 8;
  param_1[0xc] = 0;
  *param_1 = PTR_DAT_002139dd + 8;
  param_1[4] = *(undefined4 *)(param_5 + 0x80);
  *(int *)(param_5 + 0x80) = *(int *)(param_5 + 0x80) + 1;
  return;
}

/* FUN_0012ddf4 @ 0x12ddf4 (106 bytes) */
int FUN_0012ddf4(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_002139e5 + 8;
  param_1[0xc] = 0;
  *param_1 = PTR_DAT_002139dd + 8;
  param_1[4] = *(undefined4 *)(param_5 + 0x80);
  *(int *)(param_5 + 0x80) = *(int *)(param_5 + 0x80) + 1;
  return;
}

/* FUN_0012de5e @ 0x12de5e (106 bytes) */
int FUN_0012de5e(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_002139e5 + 8;
  param_1[0xc] = 0;
  *param_1 = PTR_DAT_002139cd + 8;
  param_1[4] = *(undefined4 *)(param_5 + 0x84);
  *(int *)(param_5 + 0x84) = *(int *)(param_5 + 0x84) + 1;
  return;
}

/* FUN_0012dec8 @ 0x12dec8 (106 bytes) */
int FUN_0012dec8(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_002139e5 + 8;
  param_1[0xc] = 0;
  *param_1 = PTR_DAT_002139cd + 8;
  param_1[4] = *(undefined4 *)(param_5 + 0x84);
  *(int *)(param_5 + 0x84) = *(int *)(param_5 + 0x84) + 1;
  return;
}

/* FUN_0012df32 @ 0x12df32 (106 bytes) */
int FUN_0012df32(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  FUN_0012aa80(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_002139e5 + 8;
  param_1[0xc] = 0;
  *param_1 = PTR_DAT_002139d5 + 8;
  param_1[4] = *(undefined4 *)(param_5 + 0x88);
  *(int *)(param_5 + 0x88) = *(int *)(param_5 + 0x88) + 1;
  return;
}

/* FUN_0012df9c @ 0x12df9c (29 bytes) */
int FUN_0012df9c(param_1)
  int param_1;
{
  return *(uint *)(DAT_001fd044 + param_1 * 0x10) >> 7 & 1;
}

/* FUN_0012dfba @ 0x12dfba (29 bytes) */
int FUN_0012dfba(param_1)
  int param_1;
{
  return *(uint *)(DAT_001fd044 + param_1 * 0x10) >> 8 & 1;
}

/* FUN_0012dfd8 @ 0x12dfd8 (29 bytes) */
int FUN_0012dfd8(param_1)
  int param_1;
{
  return *(uint *)(DAT_001fd044 + param_1 * 0x10) & 1;
}

/* FUN_0012dff6 @ 0x12dff6 (29 bytes) */
int FUN_0012dff6(param_1)
  int param_1;
{
  return *(uint *)(DAT_001fd044 + param_1 * 0x10) >> 6 & 1;
}

/* FUN_0012e014 @ 0x12e014 (30 bytes) */
int FUN_0012e014(param_1)
  int param_1;
{
  return ((DAT_001fd044)[param_1 * 0x10] & 0x11) != 0;
}

/* FUN_0012e032 @ 0x12e032 (83 bytes) */
int FUN_0012e032(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_4 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x34);
  *puVar2 = uVar1;
  ((int (*)())FUN_0012da72)(puVar2 + 1,param_1,param_2,param_3,param_4);
  return puVar2 + 1;
}

/* FUN_0012e0a4 @ 0x12e0a4 (28 bytes) */
int FUN_0012e0a4(param_1)
  int param_1;
{
  return *(uint *)(DAT_001fd044 + param_1 * 0x10) >> 1 & 1;
}

/* FUN_0012e0c0 @ 0x12e0c0 (29 bytes) */
int FUN_0012e0c0(param_1)
  int param_1;
{
  return *(uint *)(DAT_001fd044 + param_1 * 0x10) >> 9 & 1;
}

/* FUN_0012e0de @ 0x12e0de (24 bytes) */
int FUN_0012e0de(param_1)
  int param_1;
{
  return (DAT_001fd048)[param_1 * 0x10];
}

/* FUN_0012e0f6 @ 0x12e0f6 (83 bytes) */
int FUN_0012e0f6(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_4 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x34);
  *puVar2 = uVar1;
  FUN_0012bda4(puVar2 + 1,param_1,param_2,param_3,param_4);
  return puVar2 + 1;
}

/* FUN_0012e168 @ 0x12e168 (83 bytes) */
int FUN_0012e168(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_4 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x38);
  *puVar2 = uVar1;
  FUN_0012c36e(puVar2 + 1,param_1,param_2,param_3,param_4);
  return puVar2 + 1;
}

/* FUN_0012e1da @ 0x12e1da (83 bytes) */
int FUN_0012e1da(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_4 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x34);
  *puVar2 = uVar1;
  FUN_0012bbdc(puVar2 + 1,param_1,param_2,param_3,param_4);
  return puVar2 + 1;
}

/* FUN_0012e24c @ 0x12e24c (83 bytes) */
int FUN_0012e24c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_4 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x44);
  *puVar2 = uVar1;
  ((int (*)())FUN_0012cefa)(puVar2 + 1,param_1,param_2,param_3,param_4);
  return puVar2 + 1;
}

/* FUN_0012e2be @ 0x12e2be (83 bytes) */
int FUN_0012e2be(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_4 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x38);
  *puVar2 = uVar1;
  FUN_0012c00e(puVar2 + 1,param_1,param_2,param_3,param_4);
  return puVar2 + 1;
}

/* FUN_0012e330 @ 0x12e330 (83 bytes) */
int FUN_0012e330(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_4 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x38);
  *puVar2 = uVar1;
  ((int (*)())FUN_0012d61a)(puVar2 + 1,param_1,param_2,param_3,param_4);
  return puVar2 + 1;
}

/* FUN_0012e3a2 @ 0x12e3a2 (83 bytes) */
int FUN_0012e3a2(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_4 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x34);
  *puVar2 = uVar1;
  ((int (*)())FUN_0012d5ca)(puVar2 + 1,param_1,param_2,param_3,param_4);
  return puVar2 + 1;
}

/* FUN_0012e414 @ 0x12e414 (83 bytes) */
int FUN_0012e414(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_4 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x38);
  *puVar2 = uVar1;
  ((int (*)())FUN_0012d836)(puVar2 + 1,param_1,param_2,param_3,param_4);
  return puVar2 + 1;
}

/* FUN_0012e486 @ 0x12e486 (83 bytes) */
int FUN_0012e486(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_4 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x34);
  *puVar2 = uVar1;
  ((int (*)())FUN_0012d8d4)(puVar2 + 1,param_1,param_2,param_3,param_4);
  return puVar2 + 1;
}

/* FUN_0012e4f8 @ 0x12e4f8 (108 bytes) */
int FUN_0012e4f8(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar2 = *(undefined4 *)(param_4 + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar2,0x38);
  *puVar3 = uVar2;
  puVar1 = puVar3 + 1;
  FUN_0012aa80(puVar1,param_1,param_2,param_3,param_4);
  *puVar1 = PTR_DAT_002139e5 + 8;
  puVar3[0xd] = 0;
  return puVar1;
}

/* FUN_0012e582 @ 0x12e582 (83 bytes) */
int FUN_0012e582(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_4 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x38);
  *puVar2 = uVar1;
  ((int (*)())FUN_0012d920)(puVar2 + 1,param_1,param_2,param_3,param_4);
  return puVar2 + 1;
}

/* FUN_0012e5f4 @ 0x12e5f4 (83 bytes) */
int FUN_0012e5f4(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_4 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x38);
  *puVar2 = uVar1;
  ((int (*)())FUN_0012dec8)(puVar2 + 1,param_1,param_2,param_3,param_4);
  return puVar2 + 1;
}

/* FUN_0012e666 @ 0x12e666 (83 bytes) */
int FUN_0012e666(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_4 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x38);
  *puVar2 = uVar1;
  ((int (*)())FUN_0012ddf4)(puVar2 + 1,param_1,param_2,param_3,param_4);
  return puVar2 + 1;
}

/* FUN_0012e6d8 @ 0x12e6d8 (83 bytes) */
int FUN_0012e6d8(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_4 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x34);
  *puVar2 = uVar1;
  ((int (*)())FUN_0012d9dc)(puVar2 + 1,param_1,param_2,param_3,param_4);
  return puVar2 + 1;
}

/* FUN_0012e74a @ 0x12e74a (83 bytes) */
int FUN_0012e74a(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_4 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x34);
  *puVar2 = uVar1;
  ((int (*)())FUN_0012dc20)(puVar2 + 1,param_1,param_2,param_3,param_4);
  return puVar2 + 1;
}

/* FUN_0012e7bc @ 0x12e7bc (83 bytes) */
int FUN_0012e7bc(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_4 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x34);
  *puVar2 = uVar1;
  ((int (*)())FUN_0012d500)(puVar2 + 1,param_1,param_2,param_3,param_4);
  return puVar2 + 1;
}

/* FUN_0012e82e @ 0x12e82e (83 bytes) */
int FUN_0012e82e(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_4 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x3c);
  *puVar2 = uVar1;
  ((int (*)())FUN_0012c69a)(puVar2 + 1,param_1,param_2,param_3,param_4);
  return puVar2 + 1;
}

/* FUN_0012e8a0 @ 0x12e8a0 (11 bytes) */
int FUN_0012e8a0(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x20);
}

/* FUN_0012e8ac @ 0x12e8ac (14 bytes) */
int FUN_0012e8ac(param_1)
  int param_1;
{
  return *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x38);
}

/* FUN_0012e8ba @ 0x12e8ba (17 bytes) */
int FUN_0012e8ba(param_1)
  int param_1;
{
  return *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x50);
}

/* FUN_0012e8cc @ 0x12e8cc (20 bytes) */
int FUN_0012e8cc(param_1)
  int param_1;
{
  return *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x50) +
         *(int *)(param_1 + 0x68);
}

/* FUN_0012e8e0 @ 0x12e8e0 (14 bytes) */
int FUN_0012e8e0(param_1)
  int param_1;
{
  return *(int *)(param_1 + 4) + *(int *)(param_1 + 8);
}

/* FUN_0012e8ee @ 0x12e8ee (13 bytes) */
int FUN_0012e8ee(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  return;
}

/* FUN_0012e8fc @ 0x12e8fc (13 bytes) */
int FUN_0012e8fc(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  return;
}

/* FUN_0012e90a @ 0x12e90a (68 bytes) */
int FUN_0012e90a(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  if (*param_2 == 0x24) {
    if (*param_3 == *(int *)(param_1 + 0x44)) {
      *param_2 = 6;
      *param_3 = 0;
      return;
    }
    if (*param_3 == *(int *)(param_1 + 0x48)) {
      *param_2 = 7;
      *param_3 = 0;
      return;
    }
  }
  return;
}

/* FUN_0012e94e @ 0x12e94e (203 bytes) */
int FUN_0012e94e(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 *param_4;
  undefined4 *param_5;
{
  if (param_2 == 0x24) {
    if (*(int *)(param_1 + 0x4c) == param_3) {
      *param_4 = 0x3f;
      *param_5 = 0;
      return 1;
    }
    if (param_3 == *(int *)(param_1 + 0x54)) {
      *param_4 = 0x3f;
      *param_5 = 1;
      return 1;
    }
    if (param_3 == *(int *)(param_1 + 0x50)) {
      *param_4 = 0x40;
      *param_5 = 0;
      return 1;
    }
    if (param_3 == *(int *)(param_1 + 0x58)) {
      *param_4 = 0x40;
      *param_5 = 1;
      return 1;
    }
    if (param_3 == *(int *)(param_1 + 0x5c)) {
      *param_4 = 0x3e;
      *param_5 = 0;
      return 1;
    }
    if (param_3 == *(int *)(param_1 + 0x60)) {
      *param_4 = 0x41;
      *param_5 = 0;
      return 1;
    }
  }
  return 0;
}

