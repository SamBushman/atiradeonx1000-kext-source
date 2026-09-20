#include "decls.h"

/* FUN_00107df4 @ 0x107df4 (68 bytes) */
int FUN_00107df4(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  FUN_00107da8(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00107e70 @ 0x107e70 (68 bytes) */
int FUN_00107e70(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  FUN_00107da8(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00107eec @ 0x107eec (76 bytes) */
int FUN_00107eec(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  FUN_001071a8(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8bec;
  param_1[0x21] = 2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00107f38 @ 0x107f38 (96 bytes) */
int FUN_00107f38(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00107eec)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c30 + 8;
  param_1[0x20] = 1;
  *param_1 = puVar1;
  param_1[5] = param_1[5] | 0x18;
  param_1[0x4b] = 0;
  FUN_000ee9ac(*(undefined4 *)(param_3 + 0x6c4),param_1);
  return;
}

/* FUN_00107fd0 @ 0x107fd0 (92 bytes) */
int FUN_00107fd0(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00107eec)(param_1,0x8b,param_3);
  puVar1 = PTR_DAT_001e8be4;
  param_1[0x20] = 0;
  param_1[5] = param_1[5] | 0x18;
  *param_1 = puVar1 + 8;
  FUN_000ee9ac(*(undefined4 *)(param_3 + 0x6c4),param_1);
  return;
}

/* FUN_00108064 @ 0x108064 (68 bytes) */
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

/* FUN_001080e0 @ 0x1080e0 (92 bytes) */
int FUN_001080e0(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00107eec)(param_1,0x8b,param_3);
  puVar1 = PTR_DAT_001e8be4;
  param_1[0x20] = 0;
  param_1[5] = param_1[5] | 0x18;
  *param_1 = puVar1 + 8;
  FUN_000ee9ac(*(undefined4 *)(param_3 + 0x6c4),param_1);
  return;
}

/* FUN_00108174 @ 0x108174 (76 bytes) */
int FUN_00108174(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  FUN_001071a8(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8bec;
  param_1[0x21] = 2;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001081c0 @ 0x1081c0 (68 bytes) */
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

/* FUN_0010823c @ 0x10823c (68 bytes) */
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
int FUN_001082b8(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  FUN_001071a8(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c24;
  param_1[0x21] = 3;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00108304 @ 0x108304 (76 bytes) */
int FUN_00108304(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  FUN_001071a8(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c24;
  param_1[0x21] = 3;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00108350 @ 0x108350 (68 bytes) */
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

/* FUN_001083cc @ 0x1083cc (68 bytes) */
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
int FUN_00108448(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  
  FUN_00107cec(param_1,param_2,param_3);
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

/* FUN_001084b8 @ 0x1084b8 (68 bytes) */
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

/* FUN_00108534 @ 0x108534 (68 bytes) */
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
  
  FUN_001071a8(param_1,0x30,param_2);
  param_1[5] = param_1[5] | 0x12;
  *param_1 = &PTR_FUN_001ea118;
  if ((*(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) & 0x4000) == 0) {
    FUN_000ee9ac(*(int *)(param_2 + 0x6c4),param_1);
  }
  uVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x178))(*(int **)(param_2 + 0x30c),param_2);
  uVar2 = FUN_00112f54(uVar1);
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

/* FUN_001086e8 @ 0x1086e8 (100 bytes) */
int FUN_001086e8(param_1, param_2, param_3)
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

/* FUN_00108770 @ 0x108770 (92 bytes) */
int FUN_00108770(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_001085b0)(param_1,param_2);
  puVar1 = PTR_DAT_001e8bfc;
  param_1[0x21] = 1;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  uVar2 = FUN_00112f54(0xf9);
  param_1[0x22] = uVar2;
  return;
}

/* FUN_001087f0 @ 0x1087f0 (92 bytes) */
int FUN_001087f0(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_001085b0)(param_1,param_2);
  puVar1 = PTR_DAT_001e8bfc;
  param_1[0x21] = 1;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  uVar2 = FUN_00112f54(0xf9);
  param_1[0x22] = uVar2;
  return;
}

/* FUN_00108870 @ 0x108870 (84 bytes) */
int FUN_00108870(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001085b0)(param_1,param_2);
  puVar1 = PTR_DAT_001e8c28;
  param_1[0x21] = 2;
  param_1[0x26] = 0x16;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001088c4 @ 0x1088c4 (84 bytes) */
int FUN_001088c4(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  ((int (*)())FUN_001085b0)(param_1,param_2);
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
  
  FUN_001071a8(param_1,0x30,param_2);
  param_1[5] = param_1[5] | 0x12;
  *param_1 = &PTR_FUN_001ea118;
  if ((*(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) & 0x4000) == 0) {
    FUN_000ee9ac(*(int *)(param_2 + 0x6c4),param_1);
  }
  uVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x178))(*(int **)(param_2 + 0x30c),param_2);
  uVar2 = FUN_00112f54(uVar1);
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

/* FUN_00108ad8 @ 0x108ad8 (68 bytes) */
int FUN_00108ad8(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00108a50)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00108b54 @ 0x108b54 (96 bytes) */
int FUN_00108b54(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00107eec)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c30 + 8;
  param_1[0x20] = 1;
  *param_1 = puVar1;
  param_1[5] = param_1[5] | 0x18;
  param_1[0x4b] = 0;
  FUN_000ee9ac(*(undefined4 *)(param_3 + 0x6c4),param_1);
  return;
}

/* FUN_00108bec @ 0x108bec (68 bytes) */
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
  
  FUN_001070f8(param_1,0x86,param_2);
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
  
  FUN_001070f8(param_1,0x86,param_2);
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
  FUN_001070f8(param_1,0x87,param_2);
  *param_1 = PTR_DAT_001e8c44 + 8;
  return;
}

/* FUN_00108d5c @ 0x108d5c (76 bytes) */
int FUN_00108d5c(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  FUN_001070f8(param_1,0x87,param_2);
  *param_1 = PTR_DAT_001e8c44 + 8;
  return;
}

/* FUN_00108da8 @ 0x108da8 (76 bytes) */
int FUN_00108da8(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  FUN_001070f8(param_1,0x88,param_2);
  *param_1 = PTR_DAT_001e8c5c + 8;
  return;
}

/* FUN_00108df4 @ 0x108df4 (76 bytes) */
int FUN_00108df4(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  FUN_001070f8(param_1,0x88,param_2);
  *param_1 = PTR_DAT_001e8c5c + 8;
  return;
}

/* FUN_00108e40 @ 0x108e40 (76 bytes) */
int FUN_00108e40(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c54;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00108e8c @ 0x108e8c (84 bytes) */
int FUN_00108e8c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c14;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00108ee0 @ 0x108ee0 (68 bytes) */
int FUN_00108ee0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00108e8c)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00108f5c @ 0x108f5c (84 bytes) */
int FUN_00108f5c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c14;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00108fb0 @ 0x108fb0 (92 bytes) */
int FUN_00108fb0(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(param_1,0x85,param_2);
  puVar1 = PTR_DAT_001e8c14;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_0010900c @ 0x10900c (92 bytes) */
int FUN_0010900c(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(param_1,0x85,param_2);
  puVar1 = PTR_DAT_001e8c14;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00109068 @ 0x109068 (76 bytes) */
int FUN_00109068(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_00108e40)(param_1,0x79,param_2);
  *param_1 = PTR_DAT_001e8bf8 + 8;
  return;
}

/* FUN_001090b4 @ 0x1090b4 (76 bytes) */
int FUN_001090b4(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_00108e40)(param_1,0x79,param_2);
  *param_1 = PTR_DAT_001e8bf8 + 8;
  return;
}

/* FUN_00109100 @ 0x109100 (76 bytes) */
int FUN_00109100(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_00108e40)(param_1,0xfa,param_2);
  *param_1 = PTR_DAT_001e8c34 + 8;
  return;
}

/* FUN_0010914c @ 0x10914c (76 bytes) */
int FUN_0010914c(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_00108e40)(param_1,0xfa,param_2);
  *param_1 = PTR_DAT_001e8c34 + 8;
  return;
}

/* FUN_00109198 @ 0x109198 (216 bytes) */
int FUN_00109198(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(param_1,0x7e,param_2);
  puVar1 = PTR_DAT_001e8c3c + 8;
  param_1[0x20] = 1;
  *param_1 = puVar1;
  param_1[5] = param_1[5] | 0x40;
  param_1[0x51] = 0x32;
  param_1[0x52] = 0;
  param_1[0x21] = 0;
  param_1[0x50] = 0;
  param_1[0x4f] = 0;
  FUN_001041d0(param_1,0,0,5,0);
  FUN_001041d0(param_1,1,0,5,0);
  FUN_001041d0(param_1,2,0,5,0);
  FUN_001041d0(param_1,3,0,5,0);
  return;
}

/* FUN_00109270 @ 0x109270 (216 bytes) */
int FUN_00109270(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(param_1,0x7e,param_2);
  puVar1 = PTR_DAT_001e8c3c + 8;
  param_1[0x20] = 1;
  *param_1 = puVar1;
  param_1[5] = param_1[5] | 0x40;
  param_1[0x51] = 0x32;
  param_1[0x52] = 0;
  param_1[0x21] = 0;
  param_1[0x50] = 0;
  param_1[0x4f] = 0;
  FUN_001041d0(param_1,0,0,5,0);
  FUN_001041d0(param_1,1,0,5,0);
  FUN_001041d0(param_1,2,0,5,0);
  FUN_001041d0(param_1,3,0,5,0);
  return;
}

/* FUN_00109348 @ 0x109348 (112 bytes) */
int FUN_00109348(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_00108e40)(param_1,0x7a,param_3);
  puVar1 = PTR_DAT_001e8c20;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  param_1[0x26] = *(undefined4 *)(param_2 + 4);
  uVar2 = *(undefined4 *)(param_2 + 8);
  param_1[0x21] = 0;
  param_1[0x25] = uVar2;
  param_1[0x23] = param_2;
  return;
}

/* FUN_001093b8 @ 0x1093b8 (112 bytes) */
int FUN_001093b8(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_00108e40)(param_1,0x7a,param_3);
  puVar1 = PTR_DAT_001e8c20;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  param_1[0x26] = *(undefined4 *)(param_2 + 4);
  uVar2 = *(undefined4 *)(param_2 + 8);
  param_1[0x21] = 0;
  param_1[0x25] = uVar2;
  param_1[0x23] = param_2;
  return;
}

/* FUN_00109428 @ 0x109428 (88 bytes) */
int FUN_00109428(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c20;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  param_1[0x26] = 0;
  return;
}

/* FUN_00109480 @ 0x109480 (68 bytes) */
int FUN_00109480(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00109428)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_001094fc @ 0x1094fc (88 bytes) */
int FUN_001094fc(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c20;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  param_1[0x26] = 0;
  return;
}

/* FUN_00109554 @ 0x109554 (96 bytes) */
int FUN_00109554(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(param_1,0x7a,param_2);
  puVar1 = PTR_DAT_001e8c20;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  param_1[0x26] = 0;
  return;
}

/* FUN_001095b4 @ 0x1095b4 (96 bytes) */
int FUN_001095b4(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)(param_1,0x7a,param_2);
  puVar1 = PTR_DAT_001e8c20;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  param_1[0x26] = 0;
  return;
}

/* FUN_00109614 @ 0x109614 (112 bytes) */
int FUN_00109614(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  
  ((int (*)())FUN_00108e40)(param_1,0x79,param_3);
  *param_1 = &PTR_FUN_001ea460;
  param_1[0x26] = *(undefined4 *)(param_2 + 4);
  uVar1 = *(undefined4 *)(param_2 + 8);
  param_1[0x23] = param_2;
  param_1[0x25] = uVar1;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  FUN_000ef8f8(*(undefined4 *)(param_3 + 0x6c4),param_1);
  return;
}

/* FUN_001096bc @ 0x1096bc (112 bytes) */
int FUN_001096bc(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  
  ((int (*)())FUN_00108e40)(param_1,0x79,param_3);
  *param_1 = &PTR_FUN_001ea460;
  param_1[0x26] = *(undefined4 *)(param_2 + 4);
  uVar1 = *(undefined4 *)(param_2 + 8);
  param_1[0x23] = param_2;
  param_1[0x25] = uVar1;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  FUN_000ef8f8(*(undefined4 *)(param_3 + 0x6c4),param_1);
  return;
}

/* FUN_00109764 @ 0x109764 (116 bytes) */
int FUN_00109764(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  int iVar2;
  
  ((int (*)())FUN_00108e40)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8bdc;
  param_1[0x21] = 0;
  param_1[0x26] = 0x1a;
  *param_1 = puVar1 + 8;
  param_1[0x20] = 1;
  param_1[0x4c] = 0;
  iVar2 = FUN_000e07dc(param_3,0x3e);
  if (iVar2 != 0) {
    param_1[5] = param_1[5] | 0x18;
  }
  return;
}

/* FUN_00109810 @ 0x109810 (68 bytes) */
int FUN_00109810(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00109764)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_0010988c @ 0x10988c (116 bytes) */
int FUN_0010988c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  int iVar2;
  
  ((int (*)())FUN_00108e40)(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8bdc;
  param_1[0x21] = 0;
  param_1[0x26] = 0x1a;
  *param_1 = puVar1 + 8;
  param_1[0x20] = 1;
  param_1[0x4c] = 0;
  iVar2 = FUN_000e07dc(param_3,0x3e);
  if (iVar2 != 0) {
    param_1[5] = param_1[5] | 0x18;
  }
  return;
}

/* FUN_00109938 @ 0x109938 (108 bytes) */
int FUN_00109938(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  ((int (*)())FUN_00108e40)(param_1,0x79,param_2);
  param_1[0x26] = 2;
  *param_1 = &PTR_FUN_001ea460;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  param_1[0x4b] = 0xffffffff;
  FUN_000ef8f8(*(undefined4 *)(param_2 + 0x6c4),param_1);
  return;
}

/* FUN_001099dc @ 0x1099dc (108 bytes) */
int FUN_001099dc(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  ((int (*)())FUN_00108e40)(param_1,0x79,param_2);
  param_1[0x26] = 2;
  *param_1 = &PTR_FUN_001ea460;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  param_1[0x4b] = 0xffffffff;
  FUN_000ef8f8(*(undefined4 *)(param_2 + 0x6c4),param_1);
  return;
}

