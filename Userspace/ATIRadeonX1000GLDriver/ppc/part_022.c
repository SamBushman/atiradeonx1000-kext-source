#include "decls.h"

/* FUN_00106ffc @ 0x106ffc (80 bytes) */
int FUN_00106ffc(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  FUN_001051b0();
  puVar1 = PTR_DAT_001e8c64;
  param_1[0x20] = 1;
  param_1[0x21] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_0010704c @ 0x10704c (80 bytes) */
int FUN_0010704c(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  FUN_001051b0();
  puVar1 = PTR_DAT_001e8c64;
  param_1[0x20] = 1;
  param_1[0x21] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_0010709c @ 0x10709c (92 bytes) */
int FUN_0010709c(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  FUN_001051b0();
  puVar1 = PTR_DAT_001e8b50;
  param_1[5] = param_1[5] | 0x18000;
  *param_1 = puVar1 + 8;
  param_1[0x20] = 0;
  return;
}

/* FUN_001070f8 @ 0x1070f8 (92 bytes) */
int FUN_001070f8(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  FUN_001051b0();
  puVar1 = PTR_DAT_001e8b50;
  param_1[5] = param_1[5] | 0x18000;
  *param_1 = puVar1 + 8;
  param_1[0x20] = 0;
  return;
}

/* FUN_00107154 @ 0x107154 (84 bytes) */
int FUN_00107154(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  FUN_001051b0();
  puVar1 = PTR_DAT_001e8c58;
  param_1[0x4b] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001071a8 @ 0x1071a8 (84 bytes) */
int FUN_001071a8(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  FUN_001051b0();
  puVar1 = PTR_DAT_001e8c58;
  param_1[0x4b] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001071fc @ 0x1071fc (84 bytes) */
int FUN_001071fc(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  ((int (*)())FUN_0010704c)();
  puVar1 = PTR_DAT_001e8c10;
  param_1[0x4b] = 0;
  param_1[0x21] = 2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107250 @ 0x107250 (128 bytes) */
int FUN_00107250(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 uVar1;
  undefined *puVar2;
  
  ((int (*)())FUN_0010704c)();
  uVar1 = DAT_001af9bc;
  puVar2 = PTR_DAT_001e8c08 + 8;
  param_1[0x4b] = param_5;
  *param_1 = puVar2;
  param_1[0x4f] = 0;
  param_1[0x50] = uVar1;
  param_1[0x4c] = param_4;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  FUN_00104330(param_1,param_4,param_3);
  return;
}

/* FUN_001072d0 @ 0x1072d0 (128 bytes) */
int FUN_001072d0(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 uVar1;
  undefined *puVar2;
  
  ((int (*)())FUN_0010704c)();
  uVar1 = DAT_001af9bc;
  puVar2 = PTR_DAT_001e8c08 + 8;
  param_1[0x4b] = param_5;
  *param_1 = puVar2;
  param_1[0x4f] = 0;
  param_1[0x50] = uVar1;
  param_1[0x4c] = param_4;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  FUN_00104330(param_1,param_4,param_3);
  return;
}

/* FUN_00107350 @ 0x107350 (108 bytes) */
int FUN_00107350(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_001072d0)(puVar1 + 1,param_1,param_2,param_3,param_4);
  return puVar1 + 1;
}

/* FUN_001073dc @ 0x1073dc (68 bytes) */
int FUN_001073dc(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_0010704c)();
  *param_1 = PTR_DAT_001e8c08 + 8;
  return;
}

/* FUN_00107420 @ 0x107420 (68 bytes) */
int FUN_00107420(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_0010704c)();
  *param_1 = PTR_DAT_001e8c08 + 8;
  return;
}

/* FUN_00107464 @ 0x107464 (92 bytes) */
int FUN_00107464(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00107420)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_001074e0 @ 0x1074e0 (252 bytes) */
int FUN_001074e0(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  undefined *puVar2;
  undefined2 *puVar3;
  
  ((int (*)())FUN_0010704c)();
  puVar2 = PTR_DAT_001e8c0c;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0xffffffff;
  *param_1 = puVar2 + 8;
  param_1[0x26] = 0;
  param_1[0x2c] = 0;
  param_1[0x42] = 0;
  param_1[0x41] = 0;
  puVar3 = (undefined2 *)FUN_00193e18(*(undefined4 *)(param_3 + 0x374),0x24);
  _memset(puVar3,0,0x24);
  uVar1 = DAT_001af9bc;
  puVar3[4] = 7;
  puVar3[6] = 3;
  puVar3[9] = 1;
  puVar3[10] = 0;
  *puVar3 = 3;
  puVar3[1] = 3;
  puVar3[2] = 3;
  puVar3[3] = 7;
  puVar3[5] = 3;
  puVar3[7] = 1;
  puVar3[8] = 0;
  puVar3[0xb] = 0;
  puVar3[0xc] = 0;
  puVar3[0xd] = 0;
  puVar3[0xe] = 0;
  param_1[0x4f] = puVar3;
  param_1[0x4e] = 0xffffffff;
  param_1[0x50] = uVar1;
  if (param_2 == 0x77) {
    param_1[5] = param_1[5] | 8;
  }
  return;
}

/* FUN_00107600 @ 0x107600 (76 bytes) */
int FUN_00107600(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001074e0)();
  puVar1 = PTR_DAT_001e8c48;
  param_1[0x21] = 3;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_0010764c @ 0x10764c (252 bytes) */
int FUN_0010764c(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  undefined *puVar2;
  undefined2 *puVar3;
  
  ((int (*)())FUN_0010704c)();
  puVar2 = PTR_DAT_001e8c0c;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0xffffffff;
  *param_1 = puVar2 + 8;
  param_1[0x26] = 0;
  param_1[0x2c] = 0;
  param_1[0x42] = 0;
  param_1[0x41] = 0;
  puVar3 = (undefined2 *)FUN_00193e18(*(undefined4 *)(param_3 + 0x374),0x24);
  _memset(puVar3,0,0x24);
  uVar1 = DAT_001af9bc;
  puVar3[4] = 7;
  puVar3[6] = 3;
  puVar3[9] = 1;
  puVar3[10] = 0;
  *puVar3 = 3;
  puVar3[1] = 3;
  puVar3[2] = 3;
  puVar3[3] = 7;
  puVar3[5] = 3;
  puVar3[7] = 1;
  puVar3[8] = 0;
  puVar3[0xb] = 0;
  puVar3[0xc] = 0;
  puVar3[0xd] = 0;
  puVar3[0xe] = 0;
  param_1[0x4f] = puVar3;
  param_1[0x4e] = 0xffffffff;
  param_1[0x50] = uVar1;
  if (param_2 == 0x77) {
    param_1[5] = param_1[5] | 8;
  }
  return;
}

/* FUN_0010776c @ 0x10776c (92 bytes) */
int FUN_0010776c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_0010764c)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_001077e8 @ 0x1077e8 (92 bytes) */
int FUN_001077e8(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_0010764c)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00107864 @ 0x107864 (76 bytes) */
int FUN_00107864(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001074e0)();
  puVar1 = PTR_DAT_001e8c48;
  param_1[0x21] = 3;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001078b0 @ 0x1078b0 (92 bytes) */
int FUN_001078b0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00107864)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_0010792c @ 0x10792c (84 bytes) */
int FUN_0010792c(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  ((int (*)())FUN_0010704c)();
  puVar1 = PTR_DAT_001e8c50;
  param_1[0x4b] = 0;
  param_1[0x21] = 2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107980 @ 0x107980 (84 bytes) */
int FUN_00107980(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  ((int (*)())FUN_0010704c)();
  puVar1 = PTR_DAT_001e8c50;
  param_1[0x4b] = 0;
  param_1[0x21] = 2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001079d4 @ 0x1079d4 (84 bytes) */
int FUN_001079d4(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  ((int (*)())FUN_0010704c)();
  puVar1 = PTR_DAT_001e8c10;
  param_1[0x4b] = 0;
  param_1[0x21] = 2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107a28 @ 0x107a28 (76 bytes) */
int FUN_00107a28(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001071a8)();
  puVar1 = PTR_DAT_001e8c2c;
  param_1[0x21] = 0;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107a74 @ 0x107a74 (92 bytes) */
int FUN_00107a74(param_1)
  undefined4 *param_1;
{
  undefined4 uVar1;
  undefined *puVar2;
  
  ((int (*)())FUN_00107a28)();
  uVar1 = DAT_001af9c8;
  puVar2 = PTR_DAT_001e8be8 + 8;
  param_1[0x20] = 0;
  *param_1 = puVar2;
  param_1[0x27] = uVar1;
  param_1[0x21] = 0;
  return;
}

/* FUN_00107ad0 @ 0x107ad0 (92 bytes) */
int FUN_00107ad0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00107a74)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00107b4c @ 0x107b4c (92 bytes) */
int FUN_00107b4c(param_1)
  undefined4 *param_1;
{
  undefined4 uVar1;
  undefined *puVar2;
  
  ((int (*)())FUN_00107a28)();
  uVar1 = DAT_001af9c8;
  puVar2 = PTR_DAT_001e8be8 + 8;
  param_1[0x20] = 0;
  *param_1 = puVar2;
  param_1[0x27] = uVar1;
  param_1[0x21] = 0;
  return;
}

/* FUN_00107ba8 @ 0x107ba8 (76 bytes) */
int FUN_00107ba8(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001071a8)();
  puVar1 = PTR_DAT_001e8c2c;
  param_1[0x21] = 0;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107bf4 @ 0x107bf4 (92 bytes) */
int FUN_00107bf4(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00107ba8)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00107c70 @ 0x107c70 (92 bytes) */
int FUN_00107c70(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00107ba8)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00107cec @ 0x107cec (76 bytes) */
int FUN_00107cec(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001071a8)();
  puVar1 = PTR_DAT_001e8c68;
  param_1[0x21] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107d38 @ 0x107d38 (112 bytes) */
int FUN_00107d38(param_1)
  undefined4 *param_1;
{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  
  ((int (*)())FUN_00107cec)();
  puVar2 = PTR_DAT_001e8bf0;
  param_1[0x20] = 1;
  *param_1 = puVar2 + 8;
  iVar3 = 0;
  do {
    bVar1 = iVar3 != 1;
    param_1[0x25] = 0xffffffff;
    param_1[0x26] = 0;
    iVar3 = iVar3 + 1;
    param_1 = param_1 + 6;
  } while (bVar1);
  return;
}

/* FUN_00107da8 @ 0x107da8 (76 bytes) */
int FUN_00107da8(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001071a8)();
  puVar1 = PTR_DAT_001e8c68;
  param_1[0x21] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107df4 @ 0x107df4 (92 bytes) */
int FUN_00107df4(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00107da8)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00107e70 @ 0x107e70 (92 bytes) */
int FUN_00107e70(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00107da8)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00107eec @ 0x107eec (76 bytes) */
int FUN_00107eec(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001071a8)();
  puVar1 = PTR_DAT_001e8bec;
  param_1[0x21] = 2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107f38 @ 0x107f38 (116 bytes) */
int FUN_00107f38(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00107eec)();
  puVar1 = PTR_DAT_001e8c30 + 8;
  param_1[0x20] = 1;
  *param_1 = puVar1;
  param_1[5] = param_1[5] | 0x18;
  param_1[0x4b] = 0;
  FUN_000ee9ac(*(undefined4 *)(param_3 + 0x6c4),param_1);
  return;
}

/* FUN_00107fd0 @ 0x107fd0 (112 bytes) */
int FUN_00107fd0(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00107eec)(param_1,0x8b);
  puVar1 = PTR_DAT_001e8be4;
  param_1[0x20] = 0;
  param_1[5] = param_1[5] | 0x18;
  *param_1 = puVar1 + 8;
  FUN_000ee9ac(*(undefined4 *)(param_3 + 0x6c4),param_1);
  return;
}

/* FUN_00108064 @ 0x108064 (92 bytes) */
int FUN_00108064(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00107fd0)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_001080e0 @ 0x1080e0 (112 bytes) */
int FUN_001080e0(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00107eec)(param_1,0x8b);
  puVar1 = PTR_DAT_001e8be4;
  param_1[0x20] = 0;
  param_1[5] = param_1[5] | 0x18;
  *param_1 = puVar1 + 8;
  FUN_000ee9ac(*(undefined4 *)(param_3 + 0x6c4),param_1);
  return;
}

/* FUN_00108174 @ 0x108174 (76 bytes) */
int FUN_00108174(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001071a8)();
  puVar1 = PTR_DAT_001e8bec;
  param_1[0x21] = 2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001081c0 @ 0x1081c0 (92 bytes) */
int FUN_001081c0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00108174)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_0010823c @ 0x10823c (92 bytes) */
int FUN_0010823c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00108174)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_001082b8 @ 0x1082b8 (76 bytes) */
int FUN_001082b8(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001071a8)();
  puVar1 = PTR_DAT_001e8c24;
  param_1[0x21] = 3;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00108304 @ 0x108304 (76 bytes) */
int FUN_00108304(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001071a8)();
  puVar1 = PTR_DAT_001e8c24;
  param_1[0x21] = 3;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00108350 @ 0x108350 (92 bytes) */
int FUN_00108350(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00108304)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_001083cc @ 0x1083cc (92 bytes) */
int FUN_001083cc(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00108304)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00108448 @ 0x108448 (112 bytes) */
int FUN_00108448(param_1)
  undefined4 *param_1;
{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  
  ((int (*)())FUN_00107cec)();
  puVar2 = PTR_DAT_001e8bf0;
  param_1[0x20] = 1;
  *param_1 = puVar2 + 8;
  iVar3 = 0;
  do {
    bVar1 = iVar3 != 1;
    param_1[0x25] = 0xffffffff;
    param_1[0x26] = 0;
    iVar3 = iVar3 + 1;
    param_1 = param_1 + 6;
  } while (bVar1);
  return;
}

/* FUN_001084b8 @ 0x1084b8 (92 bytes) */
int FUN_001084b8(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00108448)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00108534 @ 0x108534 (92 bytes) */
int FUN_00108534(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00108448)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_001085b0 @ 0x1085b0 (276 bytes) */
int FUN_001085b0(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_001071a8)(param_1,0x30,param_2);
  param_1[5] = param_1[5] | 0x12;
  *param_1 = &PTR_FUN_001ea118;
  if ((*(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) & 0x4000) == 0) {
    FUN_000ee9ac(*(int *)(param_2 + 0x6c4),param_1);
  }
  (**(code **)(**(int **)(param_2 + 0x30c) + 0x178))(*(int **)(param_2 + 0x30c),param_2);
  uVar2 = FUN_00112f54();
  uVar1 = DAT_001af9c8;
  param_1[0x21] = 1;
  param_1[0x4f] = 0x32;
  param_1[0x27] = uVar1;
  param_1[0x22] = uVar2;
  param_1[0x20] = 0;
  param_1[0x50] = 0;
  FUN_00104104(param_1,0,5,0);
  FUN_00104104(param_1,1,5,0);
  FUN_00104104(param_1,2,5,0);
  FUN_00104104(param_1,3,5,0);
  param_1[0x51] = 0;
  return;
}

/* FUN_00108770 @ 0x108770 (92 bytes) */
int FUN_00108770(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_001085b0)();
  puVar1 = PTR_DAT_001e8bfc;
  param_1[0x21] = 1;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  uVar2 = FUN_00112f54(0xf9);
  param_1[0x22] = uVar2;
  return;
}

/* FUN_001088c4 @ 0x1088c4 (84 bytes) */
int FUN_001088c4(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001085b0)();
  puVar1 = PTR_DAT_001e8c28;
  param_1[0x21] = 2;
  param_1[0x26] = 0x16;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00108918 @ 0x108918 (276 bytes) */
int FUN_00108918(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_001071a8)(param_1,0x30,param_2);
  param_1[5] = param_1[5] | 0x12;
  *param_1 = &PTR_FUN_001ea118;
  if ((*(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) & 0x4000) == 0) {
    FUN_000ee9ac(*(int *)(param_2 + 0x6c4),param_1);
  }
  (**(code **)(**(int **)(param_2 + 0x30c) + 0x178))(*(int **)(param_2 + 0x30c),param_2);
  uVar2 = FUN_00112f54();
  uVar1 = DAT_001af9c8;
  param_1[0x21] = 1;
  param_1[0x4f] = 0x32;
  param_1[0x27] = uVar1;
  param_1[0x22] = uVar2;
  param_1[0x20] = 0;
  param_1[0x50] = 0;
  FUN_00104104(param_1,0,5,0);
  FUN_00104104(param_1,1,5,0);
  FUN_00104104(param_1,2,5,0);
  FUN_00104104(param_1,3,5,0);
  param_1[0x51] = 0;
  return;
}

/* FUN_00108a50 @ 0x108a50 (100 bytes) */
int FUN_00108a50(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_001085b0)(param_1,param_3);
  puVar1 = PTR_DAT_001e8bfc;
  param_1[0x21] = 1;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  uVar2 = FUN_00112f54(param_2);
  param_1[0x22] = uVar2;
  return;
}

/* FUN_00108b54 @ 0x108b54 (116 bytes) */
int FUN_00108b54(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00107eec)();
  puVar1 = PTR_DAT_001e8c30 + 8;
  param_1[0x20] = 1;
  *param_1 = puVar1;
  param_1[5] = param_1[5] | 0x18;
  param_1[0x4b] = 0;
  FUN_000ee9ac(*(undefined4 *)(param_3 + 0x6c4),param_1);
  return;
}

/* FUN_00108bec @ 0x108bec (92 bytes) */
int FUN_00108bec(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00108b54)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00108c68 @ 0x108c68 (84 bytes) */
int FUN_00108c68(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001070f8)(param_1,0x86,param_2);
  puVar1 = PTR_DAT_001e8bf4;
  param_1[0x4b] = 0;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00108cbc @ 0x108cbc (84 bytes) */
int FUN_00108cbc(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001070f8)(param_1,0x86,param_2);
  puVar1 = PTR_DAT_001e8bf4;
  param_1[0x4b] = 0;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00108d10 @ 0x108d10 (76 bytes) */
int FUN_00108d10(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_001070f8)(param_1,0x87,param_2);
  *param_1 = PTR_DAT_001e8c44 + 8;
  return;
}

