#include "decls.h"

/* FUN_001260f4 @ 0x1260f4 (88 bytes) */
int FUN_001260f4(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined *puVar1;
  
  FUN_0012379c(param_1,param_2,param_3,param_4,param_5);
  puVar1 = PTR_DAT_001e90d0;
  param_1[4] = 0x20;
  param_1[9] = param_1[9] | 2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_0012614c @ 0x12614c (88 bytes) */
int FUN_0012614c(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined *puVar1;
  
  FUN_0012379c(param_1,param_2,param_3,param_4,param_5);
  puVar1 = PTR_DAT_001e90d0;
  param_1[4] = 0x20;
  param_1[9] = param_1[9] | 2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001261a4 @ 0x1261a4 (68 bytes) */
int FUN_001261a4(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  FUN_0012379c(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001ea8d0;
  return;
}

/* FUN_001261e8 @ 0x1261e8 (68 bytes) */
int FUN_001261e8(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  FUN_0012379c(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001ea8d0;
  return;
}

/* FUN_0012622c @ 0x12622c (256 bytes) */
int FUN_0012622c(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  FUN_0012379c(param_1,param_2,param_3,param_4,param_5);
  param_1[4] = param_2;
  param_1[9] = param_1[9] | 2;
  *param_1 = &PTR_FUN_001ea7f0;
  if ((*(uint *)(*(int *)(param_5 + 0x6c4) + 0x30) & 0x4000) != 0) {
    uVar4 = *(undefined4 *)(param_5 + 0x374);
    puVar1 = (undefined4 *)FUN_00193e18(uVar4,0x168);
    puVar3 = puVar1 + 1;
    *puVar1 = uVar4;
    FUN_00108918(puVar3,param_5);
    puVar1[0x28] = DAT_001afef0;
    FUN_001046c8(puVar3,0,param_1);
    FUN_0012306c(param_1,puVar3);
    FUN_001046c8(puVar3,1,param_1);
    uVar4 = DAT_001afeec;
    iVar2 = FUN_001054ec(puVar3,1);
    *(undefined4 *)(iVar2 + 0x10) = uVar4;
    FUN_001236e4(param_1,1,puVar3);
    FUN_000ee9ac(*(undefined4 *)(param_5 + 0x6c4),puVar3);
    FUN_000e7688(*(undefined4 *)(*(int *)(param_5 + 0x6c4) + 0x3a8),puVar3);
  }
  return;
}

/* FUN_00126378 @ 0x126378 (256 bytes) */
int FUN_00126378(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  FUN_0012379c(param_1,param_2,param_3,param_4,param_5);
  param_1[4] = param_2;
  param_1[9] = param_1[9] | 2;
  *param_1 = &PTR_FUN_001ea7f0;
  if ((*(uint *)(*(int *)(param_5 + 0x6c4) + 0x30) & 0x4000) != 0) {
    uVar4 = *(undefined4 *)(param_5 + 0x374);
    puVar1 = (undefined4 *)FUN_00193e18(uVar4,0x168);
    puVar3 = puVar1 + 1;
    *puVar1 = uVar4;
    FUN_00108918(puVar3,param_5);
    puVar1[0x28] = DAT_001afef0;
    FUN_001046c8(puVar3,0,param_1);
    FUN_0012306c(param_1,puVar3);
    FUN_001046c8(puVar3,1,param_1);
    uVar4 = DAT_001afeec;
    iVar2 = FUN_001054ec(puVar3,1);
    *(undefined4 *)(iVar2 + 0x10) = uVar4;
    FUN_001236e4(param_1,1,puVar3);
    FUN_000ee9ac(*(undefined4 *)(param_5 + 0x6c4),puVar3);
    FUN_000e7688(*(undefined4 *)(*(int *)(param_5 + 0x6c4) + 0x3a8),puVar3);
  }
  return;
}

/* FUN_001264c4 @ 0x1264c4 (116 bytes) */
int FUN_001264c4(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined *puVar1;
  
  FUN_0012379c(param_1,param_2,param_3,param_4,param_5);
  puVar1 = PTR_DAT_001e90ec;
  param_1[0xc] = 0;
  *param_1 = puVar1 + 8;
  *param_1 = PTR_DAT_001e90e4 + 8;
  param_1[4] = *(undefined4 *)(param_5 + 0x33c);
  *(int *)(param_5 + 0x33c) = *(int *)(param_5 + 0x33c) + 1;
  return;
}

/* FUN_00126538 @ 0x126538 (116 bytes) */
int FUN_00126538(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined *puVar1;
  
  FUN_0012379c(param_1,param_2,param_3,param_4,param_5);
  puVar1 = PTR_DAT_001e90ec;
  param_1[0xc] = 0;
  *param_1 = puVar1 + 8;
  *param_1 = PTR_DAT_001e90e4 + 8;
  param_1[4] = *(undefined4 *)(param_5 + 0x33c);
  *(int *)(param_5 + 0x33c) = *(int *)(param_5 + 0x33c) + 1;
  return;
}

/* FUN_001265ac @ 0x1265ac (116 bytes) */
int FUN_001265ac(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined *puVar1;
  
  FUN_0012379c(param_1,param_2,param_3,param_4,param_5);
  puVar1 = PTR_DAT_001e90ec;
  param_1[0xc] = 0;
  *param_1 = puVar1 + 8;
  *param_1 = PTR_DAT_001e90d4 + 8;
  param_1[4] = *(undefined4 *)(param_5 + 0x340);
  *(int *)(param_5 + 0x340) = *(int *)(param_5 + 0x340) + 1;
  return;
}

/* FUN_00126620 @ 0x126620 (116 bytes) */
int FUN_00126620(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined *puVar1;
  
  FUN_0012379c(param_1,param_2,param_3,param_4,param_5);
  puVar1 = PTR_DAT_001e90ec;
  param_1[0xc] = 0;
  *param_1 = puVar1 + 8;
  *param_1 = PTR_DAT_001e90d4 + 8;
  param_1[4] = *(undefined4 *)(param_5 + 0x340);
  *(int *)(param_5 + 0x340) = *(int *)(param_5 + 0x340) + 1;
  return;
}

/* FUN_00126694 @ 0x126694 (116 bytes) */
int FUN_00126694(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined *puVar1;
  
  FUN_0012379c(param_1,param_2,param_3,param_4,param_5);
  puVar1 = PTR_DAT_001e90ec;
  param_1[0xc] = 0;
  *param_1 = puVar1 + 8;
  *param_1 = PTR_DAT_001e90dc + 8;
  param_1[4] = *(undefined4 *)(param_5 + 0x344);
  *(int *)(param_5 + 0x344) = *(int *)(param_5 + 0x344) + 1;
  return;
}

/* FUN_00126708 @ 0x126708 (44 bytes) */
int FUN_00126708(param_1)
  int param_1;
{
  return *(uint *)(&DAT_001ea904 + param_1 * 0x10) >> 7 & 1;
}

/* FUN_00126734 @ 0x126734 (44 bytes) */
int FUN_00126734(param_1)
  int param_1;
{
  return *(uint *)(&DAT_001ea904 + param_1 * 0x10) >> 8 & 1;
}

/* FUN_00126760 @ 0x126760 (44 bytes) */
int FUN_00126760(param_1)
  int param_1;
{
  return *(uint *)(&DAT_001ea904 + param_1 * 0x10) & 1;
}

/* FUN_0012678c @ 0x12678c (44 bytes) */
int FUN_0012678c(param_1)
  int param_1;
{
  return *(uint *)(&DAT_001ea904 + param_1 * 0x10) >> 6 & 1;
}

/* FUN_001267b8 @ 0x1267b8 (52 bytes) */
int FUN_001267b8(param_1)
  int param_1;
{
  return -(*(uint *)(&DAT_001ea904 + param_1 * 0x10) & 0x11) >> 0x1f;
}

/* FUN_001267ec @ 0x1267ec (84 bytes) */
int FUN_001267ec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_4 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x34);
  *puVar1 = uVar2;
  ((int (*)())FUN_001261e8)(puVar1 + 1,param_1,param_2,param_3,param_4);
  return puVar1 + 1;
}

/* FUN_00126878 @ 0x126878 (44 bytes) */
int FUN_00126878(param_1)
  int param_1;
{
  return *(uint *)(&DAT_001ea904 + param_1 * 0x10) >> 1 & 1;
}

/* FUN_001268a4 @ 0x1268a4 (44 bytes) */
int FUN_001268a4(param_1)
  int param_1;
{
  return *(uint *)(&DAT_001ea904 + param_1 * 0x10) >> 9 & 1;
}

/* FUN_001268d0 @ 0x1268d0 (40 bytes) */
int FUN_001268d0(param_1)
  int param_1;
{
  return (DAT_001ea908)[param_1 * 0x10];
}

/* FUN_001268f8 @ 0x1268f8 (84 bytes) */
int FUN_001268f8(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_4 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x34);
  *puVar1 = uVar2;
  FUN_001248ec(puVar1 + 1,param_1,param_2,param_3,param_4);
  return puVar1 + 1;
}

/* FUN_00126984 @ 0x126984 (84 bytes) */
int FUN_00126984(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_4 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x38);
  *puVar1 = uVar2;
  FUN_00124e04(puVar1 + 1,param_1,param_2,param_3,param_4);
  return puVar1 + 1;
}

/* FUN_00126a10 @ 0x126a10 (84 bytes) */
int FUN_00126a10(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_4 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x34);
  *puVar1 = uVar2;
  FUN_00124724(puVar1 + 1,param_1,param_2,param_3,param_4);
  return puVar1 + 1;
}

/* FUN_00126a9c @ 0x126a9c (84 bytes) */
int FUN_00126a9c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_4 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x44);
  *puVar1 = uVar2;
  FUN_001257b0(puVar1 + 1,param_1,param_2,param_3,param_4);
  return puVar1 + 1;
}

/* FUN_00126b28 @ 0x126b28 (84 bytes) */
int FUN_00126b28(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_4 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x38);
  *puVar1 = uVar2;
  FUN_00124b24(puVar1 + 1,param_1,param_2,param_3,param_4);
  return puVar1 + 1;
}

/* FUN_00126bb4 @ 0x126bb4 (84 bytes) */
int FUN_00126bb4(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_4 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x38);
  *puVar1 = uVar2;
  FUN_00125db8(puVar1 + 1,param_1,param_2,param_3,param_4);
  return puVar1 + 1;
}

/* FUN_00126c40 @ 0x126c40 (84 bytes) */
int FUN_00126c40(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_4 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x34);
  *puVar1 = uVar2;
  FUN_00125d60(puVar1 + 1,param_1,param_2,param_3,param_4);
  return puVar1 + 1;
}

/* FUN_00126ccc @ 0x126ccc (84 bytes) */
int FUN_00126ccc(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_4 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x38);
  *puVar1 = uVar2;
  FUN_00125f94(puVar1 + 1,param_1,param_2,param_3,param_4);
  return puVar1 + 1;
}

/* FUN_00126d58 @ 0x126d58 (84 bytes) */
int FUN_00126d58(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_4 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x34);
  *puVar1 = uVar2;
  FUN_00126034(puVar1 + 1,param_1,param_2,param_3,param_4);
  return puVar1 + 1;
}

/* FUN_00126de4 @ 0x126de4 (92 bytes) */
int FUN_00126de4(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  uVar3 = *(undefined4 *)(param_4 + 0x374);
  puVar2 = (undefined4 *)FUN_00193e18(uVar3,0x38);
  puVar4 = puVar2 + 1;
  *puVar2 = uVar3;
  FUN_0012379c(puVar4,param_1,param_2,param_3,param_4);
  puVar1 = PTR_DAT_001e90ec;
  puVar2[0xd] = 0;
  *puVar4 = puVar1 + 8;
  return puVar4;
}

/* FUN_00126e90 @ 0x126e90 (84 bytes) */
int FUN_00126e90(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_4 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x38);
  *puVar1 = uVar2;
  FUN_00126080(puVar1 + 1,param_1,param_2,param_3,param_4);
  return puVar1 + 1;
}

/* FUN_00126f1c @ 0x126f1c (84 bytes) */
int FUN_00126f1c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_4 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x38);
  *puVar1 = uVar2;
  ((int (*)())FUN_00126620)(puVar1 + 1,param_1,param_2,param_3,param_4);
  return puVar1 + 1;
}

/* FUN_00126fa8 @ 0x126fa8 (84 bytes) */
int FUN_00126fa8(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_4 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x38);
  *puVar1 = uVar2;
  ((int (*)())FUN_00126538)(puVar1 + 1,param_1,param_2,param_3,param_4);
  return puVar1 + 1;
}

/* FUN_00127034 @ 0x127034 (84 bytes) */
int FUN_00127034(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_4 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x34);
  *puVar1 = uVar2;
  ((int (*)())FUN_0012614c)(puVar1 + 1,param_1,param_2,param_3,param_4);
  return puVar1 + 1;
}

/* FUN_001270c0 @ 0x1270c0 (84 bytes) */
int FUN_001270c0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_4 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x34);
  *puVar1 = uVar2;
  ((int (*)())FUN_00126378)(puVar1 + 1,param_1,param_2,param_3,param_4);
  return puVar1 + 1;
}

/* FUN_0012714c @ 0x12714c (84 bytes) */
int FUN_0012714c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_4 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x34);
  *puVar1 = uVar2;
  FUN_00125c8c(puVar1 + 1,param_1,param_2,param_3,param_4);
  return puVar1 + 1;
}

/* FUN_001271d8 @ 0x1271d8 (84 bytes) */
int FUN_001271d8(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_4 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x3c);
  *puVar1 = uVar2;
  FUN_001250dc(puVar1 + 1,param_1,param_2,param_3,param_4);
  return puVar1 + 1;
}

/* FUN_00127264 @ 0x127264 (8 bytes) */
int FUN_00127264(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x20);
}

/* FUN_0012726c @ 0x12726c (16 bytes) */
int FUN_0012726c(param_1)
  int param_1;
{
  return *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x38);
}

/* FUN_0012727c @ 0x12727c (24 bytes) */
int FUN_0012727c(param_1)
  int param_1;
{
  return *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x50);
}

/* FUN_00127294 @ 0x127294 (32 bytes) */
int FUN_00127294(param_1)
  int param_1;
{
  return *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x50) +
         *(int *)(param_1 + 0x68);
}

/* FUN_001272b4 @ 0x1272b4 (16 bytes) */
int FUN_001272b4(param_1)
  int param_1;
{
  return *(int *)(param_1 + 4) + *(int *)(param_1 + 8);
}

/* FUN_001272cc @ 0x1272cc (8 bytes) */
int FUN_001272cc(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  return;
}

/* FUN_001272d4 @ 0x1272d4 (80 bytes) */
int FUN_001272d4(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  if (*param_2 != 0x24) {
    return;
  }
  if (*param_3 == *(int *)(param_1 + 0x44)) {
    *param_2 = 6;
    *param_3 = 0;
    return;
  }
  if (*param_3 != *(int *)(param_1 + 0x48)) {
    return;
  }
  *param_2 = 7;
  *param_3 = 0;
  return;
}

/* FUN_00127324 @ 0x127324 (232 bytes) */
int FUN_00127324(param_1, param_2, param_3, param_4, param_5)
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

/* FUN_0012740c @ 0x12740c (100 bytes) */
int FUN_0012740c(param_1)
  int param_1;
{
  undefined1 auStack_38 [16];
  int *local_28;
  
  FUN_00194a94(auStack_38,*(undefined4 *)(param_1 + 4));
  while (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 4))();
    FUN_00194938(auStack_38);
  }
  return;
}

/* FUN_00127470 @ 0x127470 (196 bytes) */
int FUN_00127470(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
  ((int (*)())FUN_0012740c)(param_1);
  puVar4 = *(uint **)(param_1 + 4);
  if (puVar4 != (uint *)0x0) {
    uVar1 = *puVar4;
    if (uVar1 == 0) {
      uVar3 = puVar4[2];
    }
    else {
      uVar3 = puVar4[2];
      uVar5 = 0;
      do {
        iVar2 = *(int *)(uVar5 * 4 + uVar3);
        if (iVar2 != 0) {
          FUN_00193cc0(puVar4[5],iVar2);
          uVar1 = *puVar4;
          uVar3 = puVar4[2];
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar1);
    }
    FUN_00193cc0(puVar4[5],uVar3);
    FUN_00193cc0(puVar4[-1],puVar4 + -1);
    return;
  }
  return;
}

/* FUN_00127534 @ 0x127534 (108 bytes) */
int FUN_00127534(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  ((int (*)())FUN_001272d4)(param_1,&STACKARG(0x1c),&STACKARG(0x20));
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 8) = uStack00000020;
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 4) = uStack0000001c;
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 0xc) = param_4;
  uVar1 = FUN_00194834(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x24));
  return uVar1;
}

/* FUN_001275a0 @ 0x1275a0 (104 bytes) */
int FUN_001275a0(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  ((int (*)())FUN_001272d4)(param_1,&STACKARG(0x1c),&STACKARG(0x20));
  uVar1 = FUN_00122e90(uStack00000020,uStack0000001c);
  FUN_00194d44(*(undefined4 *)(param_1 + 4),uVar1);
  return uVar1;
}

/* FUN_00127608 @ 0x127608 (100 bytes) */
int FUN_00127608(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ((int (*)())FUN_00127534)(param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    uVar2 = ((int (*)())FUN_001275a0)(param_1,param_2,param_3,param_4);
    return uVar2;
  }
  return iVar1;
}

/* FUN_0012766c @ 0x12766c (52 bytes) */
int FUN_0012766c(param_1, param_2)
  int param_1;
  int param_2;
{
  if (((*(byte *)(param_1 + 0x15c) & 1) == (*(byte *)(param_2 + 0x15c) & 1)) &&
     (*(int *)(param_1 + 0x20) == *(int *)(param_2 + 0x20))) {
    return 0;
  }
  return 0xffffffff;
}

/* FUN_001276a0 @ 0x1276a0 (92 bytes) */
int FUN_001276a0(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((((((int)*(char *)(param_1 + 0x15c) & 1U) == ((int)*(char *)(param_2 + 0x15c) & 1U)) &&
       (*(int *)(param_1 + 0x20) == *(int *)(param_2 + 0x20))) &&
      (((uint)(int)*(char *)(param_1 + 0x15c) >> 1 & 1) ==
       ((uint)(int)*(char *)(param_2 + 0x15c) >> 1 & 1))) &&
     (*(int *)(param_1 + 0x38) == *(int *)(param_2 + 0x38))) {
    return 0;
  }
  return 0xffffffff;
}

/* FUN_001276fc @ 0x1276fc (124 bytes) */
int FUN_001276fc(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(char *)(param_1 + 0x15c);
  uVar1 = (uint)*(char *)(param_2 + 0x15c);
  if (((((uVar2 & 1) == (uVar1 & 1)) && (*(int *)(param_1 + 0x20) == *(int *)(param_2 + 0x20))) &&
      ((uVar2 >> 1 & 1) == (uVar1 >> 1 & 1))) &&
     (((*(int *)(param_1 + 0x38) == *(int *)(param_2 + 0x38) &&
       ((uVar2 >> 2 & 1) == (uVar1 >> 2 & 1))) &&
      (*(int *)(param_1 + 0x50) == *(int *)(param_2 + 0x50))))) {
    return 0;
  }
  return 0xffffffff;
}

/* FUN_00127778 @ 0x127778 (156 bytes) */
int FUN_00127778(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(char *)(param_1 + 0x15c);
  uVar1 = (uint)*(char *)(param_2 + 0x15c);
  if ((((((uVar2 & 1) == (uVar1 & 1)) && (*(int *)(param_1 + 0x20) == *(int *)(param_2 + 0x20))) &&
       ((uVar2 >> 1 & 1) == (uVar1 >> 1 & 1))) &&
      ((*(int *)(param_1 + 0x38) == *(int *)(param_2 + 0x38) &&
       ((uVar2 >> 2 & 1) == (uVar1 >> 2 & 1))))) &&
     ((*(int *)(param_1 + 0x50) == *(int *)(param_2 + 0x50) &&
      (((uVar2 >> 3 & 1) == (uVar1 >> 3 & 1) &&
       (*(int *)(param_1 + 0x68) == *(int *)(param_2 + 0x68))))))) {
    return 0;
  }
  return 0xffffffff;
}

/* FUN_00127814 @ 0x127814 (60 bytes) */
int FUN_00127814(param_1, param_2)
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

/* FUN_00127850 @ 0x127850 (128 bytes) */
int FUN_00127850(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined1 auStack_38 [16];
  int *local_28;
  
  FUN_00194a94(auStack_38,*(undefined4 *)(param_1 + 4));
  iVar2 = 0;
  while (local_28 != (int *)0x0) {
    iVar1 = (**(code **)(*local_28 + 0x18))();
    if (iVar1 != 0) {
      iVar2 = iVar2 + 1;
    }
    FUN_00194938(auStack_38);
  }
  return iVar2;
}

/* FUN_001278d0 @ 0x1278d0 (196 bytes) */
int FUN_001278d0(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
  ((int (*)())FUN_0012740c)(param_1);
  puVar4 = *(uint **)(param_1 + 4);
  if (puVar4 != (uint *)0x0) {
    uVar1 = *puVar4;
    if (uVar1 == 0) {
      uVar3 = puVar4[2];
    }
    else {
      uVar3 = puVar4[2];
      uVar5 = 0;
      do {
        iVar2 = *(int *)(uVar5 * 4 + uVar3);
        if (iVar2 != 0) {
          FUN_00193cc0(puVar4[5],iVar2);
          uVar1 = *puVar4;
          uVar3 = puVar4[2];
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar1);
    }
    FUN_00193cc0(puVar4[5],uVar3);
    FUN_00193cc0(puVar4[-1],puVar4 + -1);
    return;
  }
  return;
}

/* FUN_00127994 @ 0x127994 (1024 bytes) */
int FUN_00127994(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  uint *puVar6;
  
  param_1[0xb] = param_2;
  param_1[0xc] = -1;
  iVar4 = *(int *)(*(int *)(*param_1 + 0x30c) + 0x30);
  param_1[0x10] = 0;
  param_1[0xd] = iVar4;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  uVar5 = *(undefined4 *)(*param_1 + 0x374);
  puVar2 = (undefined4 *)FUN_00193e18(uVar5,0x1c);
  puVar6 = puVar2 + 1;
  *puVar2 = uVar5;
  uVar1 = 1;
  puVar2[4] = FUN_00127814;
  puVar2[1] = 1;
  iVar4 = 0x20;
  puVar2[5] = FUN_001272b4;
  puVar2[6] = uVar5;
  do {
    uVar1 = uVar1 << 1;
    if (0xf < uVar1) break;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *puVar6 = uVar1;
  puVar2[2] = 0;
  pvVar3 = (void *)FUN_00193e18(uVar5,*puVar6 << 2);
  puVar2[3] = pvVar3;
  _memset(pvVar3,0,*puVar6 << 2);
  param_1[1] = (int)puVar6;
  uVar5 = *(undefined4 *)(*param_1 + 0x374);
  puVar2 = (undefined4 *)FUN_00193e18(uVar5,0x1c);
  puVar6 = puVar2 + 1;
  *puVar2 = uVar5;
  uVar1 = 1;
  puVar2[4] = FUN_0012766c;
  puVar2[1] = 1;
  iVar4 = 0x20;
  puVar2[5] = FUN_00127264;
  puVar2[6] = uVar5;
  do {
    uVar1 = uVar1 << 1;
    if (0xf < uVar1) break;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *puVar6 = uVar1;
  puVar2[2] = 0;
  pvVar3 = (void *)FUN_00193e18(uVar5,*puVar6 << 2);
  puVar2[3] = pvVar3;
  _memset(pvVar3,0,*puVar6 << 2);
  param_1[2] = (int)puVar6;
  uVar5 = *(undefined4 *)(*param_1 + 0x374);
  puVar2 = (undefined4 *)FUN_00193e18(uVar5,0x1c);
  puVar6 = puVar2 + 1;
  *puVar2 = uVar5;
  uVar1 = 1;
  puVar2[4] = FUN_001276a0;
  puVar2[1] = 1;
  iVar4 = 0x20;
  puVar2[5] = FUN_0012726c;
  puVar2[6] = uVar5;
  do {
    uVar1 = uVar1 << 1;
    if (0xf < uVar1) break;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *puVar6 = uVar1;
  puVar2[2] = 0;
  pvVar3 = (void *)FUN_00193e18(uVar5,*puVar6 << 2);
  puVar2[3] = pvVar3;
  _memset(pvVar3,0,*puVar6 << 2);
  param_1[3] = (int)puVar6;
  uVar5 = *(undefined4 *)(*param_1 + 0x374);
  puVar2 = (undefined4 *)FUN_00193e18(uVar5,0x1c);
  puVar6 = puVar2 + 1;
  *puVar2 = uVar5;
  uVar1 = 1;
  puVar2[4] = FUN_001276fc;
  puVar2[1] = 1;
  iVar4 = 0x20;
  puVar2[5] = FUN_0012727c;
  puVar2[6] = uVar5;
  do {
    uVar1 = uVar1 << 1;
    if (0xf < uVar1) break;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *puVar6 = uVar1;
  puVar2[2] = 0;
  pvVar3 = (void *)FUN_00193e18(uVar5,*puVar6 << 2);
  puVar2[3] = pvVar3;
  _memset(pvVar3,0,*puVar6 << 2);
  param_1[4] = (int)puVar6;
  uVar5 = *(undefined4 *)(*param_1 + 0x374);
  puVar2 = (undefined4 *)FUN_00193e18(uVar5,0x1c);
  puVar6 = puVar2 + 1;
  *puVar2 = uVar5;
  uVar1 = 1;
  puVar2[4] = FUN_00127778;
  puVar2[1] = 1;
  iVar4 = 0x20;
  puVar2[5] = FUN_00127294;
  puVar2[6] = uVar5;
  do {
    uVar1 = uVar1 << 1;
    if (0xf < uVar1) break;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *puVar6 = uVar1;
  puVar2[2] = 0;
  pvVar3 = (void *)FUN_00193e18(uVar5,*puVar6 << 2);
  puVar2[3] = pvVar3;
  _memset(pvVar3,0,*puVar6 << 2);
  param_1[5] = (int)puVar6;
  uVar5 = *(undefined4 *)(*param_1 + 0x374);
  puVar2 = (undefined4 *)FUN_00193e18(uVar5,0x14);
  *puVar2 = uVar5;
  puVar2[1] = 2;
  puVar2[4] = uVar5;
  puVar2[2] = 0;
  uVar5 = FUN_00193e18(uVar5,8);
  puVar2[3] = uVar5;
  param_1[6] = (int)(puVar2 + 1);
  uVar5 = *(undefined4 *)(*param_1 + 0x374);
  puVar2 = (undefined4 *)FUN_00193e18(uVar5,0x14);
  *puVar2 = uVar5;
  puVar2[1] = 2;
  puVar2[2] = 0;
  puVar2[4] = uVar5;
  uVar5 = FUN_00193e18(uVar5,8);
  puVar2[3] = uVar5;
  param_1[8] = (int)(puVar2 + 1);
  param_1[7] = 0;
  uVar5 = *(undefined4 *)(*param_1 + 0x374);
  puVar2 = (undefined4 *)FUN_00193e18(uVar5,0x34);
  *puVar2 = uVar5;
  FUN_001238e8(puVar2 + 1,0,0,0,*param_1);
  param_1[9] = (int)(puVar2 + 1);
  uVar5 = *(undefined4 *)(*param_1 + 0x374);
  puVar2 = (undefined4 *)FUN_00193e18(uVar5,0x168);
  *puVar2 = uVar5;
  FUN_00109938(puVar2 + 1,*param_1);
  param_1[10] = (int)(puVar2 + 1);
  *(undefined4 *)(*param_1 + 0x348) = 0;
  *(undefined4 *)(*param_1 + 0x334) = 1;
  *(undefined4 *)(*param_1 + 0x338) = 0;
  param_1[0x19] = -1;
  param_1[0x11] = -1;
  param_1[0x12] = -1;
  param_1[0x13] = -1;
  param_1[0x14] = -1;
  param_1[0x15] = -1;
  param_1[0x16] = -1;
  param_1[0x17] = -1;
  param_1[0x18] = -1;
  return;
}

/* FUN_00127e48 @ 0x127e48 (132 bytes) */
int FUN_00127e48(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  int iVar1;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  
  iVar1 = *(int *)(((unsigned char *)0x0000172c) + param_1);
  *(int *)(((unsigned char *)0x0000172c) + param_1) = iVar1 + 1;
  iVar1 = param_1 + iVar1 * 0x34 + 0x60;
  *(undefined4 *)(iVar1 + 8) = param_3;
  *(undefined4 *)(iVar1 + 0xc) = param_4;
  *(undefined4 *)(iVar1 + 0x10) = in_stack_0000003c;
  *(undefined4 *)(iVar1 + 0x1c) = 1;
  *(undefined1 *)(iVar1 + 0x37) = (undefined1)param_2;
  *(char *)(iVar1 + 0x38) = (char)((uint)param_5 >> 0x18);
  *(char *)(iVar1 + 0x39) = (char)((uint)param_5 >> 0x10);
  *(char *)(iVar1 + 0x3a) = (char)((uint)param_5 >> 8);
  *(char *)(iVar1 + 0x3b) = (char)param_5;
  *(uint *)(iVar1 + 0x24) = (uint)(param_6 == 0);
  *(undefined4 *)(iVar1 + 0x18) = in_stack_00000038;
  *(undefined1 *)(iVar1 + 0x34) = (undefined1)param_2;
  *(undefined1 *)(iVar1 + 0x35) = (undefined1)param_2;
  *(undefined1 *)(iVar1 + 0x36) = (undefined1)param_2;
  return;
}

/* FUN_00127ecc @ 0x127ecc (24 bytes) */
int FUN_00127ecc(param_1)
  int param_1;
{
  if (*(int *)(FUN_00001740 + param_1) == 2) {
    return 0x40;
  }
  return 0x20;
}

