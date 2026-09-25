#include "decls.h"

/* FUN_00109a80 @ 0x109a80 (76 bytes) */
int FUN_00109a80(param_1, param_2, param_3)
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

/* FUN_00109acc @ 0x109acc (84 bytes) */
int FUN_00109acc(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c04;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00109b20 @ 0x109b20 (84 bytes) */
int FUN_00109b20(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c04;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00109b74 @ 0x109b74 (68 bytes) */
int FUN_00109b74(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00109b20)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00109bf0 @ 0x109bf0 (92 bytes) */
int FUN_00109bf0(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,0x83,param_2);
  puVar1 = PTR_DAT_001e8c1c;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00109c4c @ 0x109c4c (92 bytes) */
int FUN_00109c4c(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,0x83,param_2);
  puVar1 = PTR_DAT_001e8c1c;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00109ca8 @ 0x109ca8 (84 bytes) */
int FUN_00109ca8(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c1c;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00109cfc @ 0x109cfc (84 bytes) */
int FUN_00109cfc(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,param_2,param_3);
  puVar1 = PTR_DAT_001e8c1c;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00109d50 @ 0x109d50 (68 bytes) */
int FUN_00109d50(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00109cfc)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00109dcc @ 0x109dcc (92 bytes) */
int FUN_00109dcc(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_001070f8(param_1,param_2,param_3);
  param_1[0x4c] = 0;
  *param_1 = &PTR_FUN_001ea3b8;
  param_1[0x21] = 1;
  param_1[0x20] = 1;
  param_1[0x4b] = 0;
  return;
}

/* FUN_00109e28 @ 0x109e28 (92 bytes) */
int FUN_00109e28(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_001070f8(param_1,param_2,param_3);
  param_1[0x4c] = 0;
  *param_1 = &PTR_FUN_001ea3b8;
  param_1[0x21] = 1;
  param_1[0x20] = 1;
  param_1[0x4b] = 0;
  return;
}

/* FUN_00109e84 @ 0x109e84 (68 bytes) */
int FUN_00109e84(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00109e28)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_00109f00 @ 0x109f00 (80 bytes) */
int FUN_00109f00(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_001070f8(param_1,param_2,param_3);
  param_1[0x21] = 1;
  *param_1 = &PTR_FUN_001ea268;
  param_1[0x20] = 1;
  return;
}

/* FUN_00109f50 @ 0x109f50 (80 bytes) */
int FUN_00109f50(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_001070f8(param_1,param_2,param_3);
  param_1[0x21] = 1;
  *param_1 = &PTR_FUN_001ea268;
  param_1[0x20] = 1;
  return;
}

/* FUN_00109fa0 @ 0x109fa0 (68 bytes) */
int FUN_00109fa0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_00109f50)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_0010a01c @ 0x10a01c (84 bytes) */
int FUN_0010a01c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_001070f8(param_1,param_2,param_3);
  param_1[0x21] = 2;
  *param_1 = &PTR_FUN_001ea310;
  param_1[0x20] = 1;
  return;
}

/* FUN_0010a070 @ 0x10a070 (84 bytes) */
int FUN_0010a070(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_001070f8(param_1,param_2,param_3);
  param_1[0x21] = 2;
  *param_1 = &PTR_FUN_001ea310;
  param_1[0x20] = 1;
  return;
}

/* FUN_0010a0c4 @ 0x10a0c4 (68 bytes) */
int FUN_0010a0c4(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_0010a070)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_0010a140 @ 0x10a140 (128 bytes) */
int FUN_0010a140(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  FUN_001070f8(param_1,param_2,param_3);
  uVar2 = DAT_001af9c8;
  param_1[0x20] = 1;
  uVar1 = DAT_001af9c4;
  *param_1 = &PTR_FUN_001ea070;
  iVar3 = 4;
  param_1[0x4b] = 0;
  param_1[0x27] = uVar2;
  param_1[0x21] = 0;
  do {
    param_1[0x2d] = uVar1;
    param_1 = param_1 + 6;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

/* FUN_0010a1c0 @ 0x10a1c0 (128 bytes) */
int FUN_0010a1c0(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  FUN_001070f8(param_1,param_2,param_3);
  uVar2 = DAT_001af9c8;
  param_1[0x20] = 1;
  uVar1 = DAT_001af9c4;
  *param_1 = &PTR_FUN_001ea070;
  iVar3 = 4;
  param_1[0x4b] = 0;
  param_1[0x27] = uVar2;
  param_1[0x21] = 0;
  do {
    param_1[0x2d] = uVar1;
    param_1 = param_1 + 6;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

/* FUN_0010a240 @ 0x10a240 (68 bytes) */
int FUN_0010a240(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_0010a1c0)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_0010a2bc @ 0x10a2bc (184 bytes) */
int FUN_0010a2bc(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  FUN_001070f8(param_1,0x8e,param_2);
  param_1[0x20] = 1;
  *param_1 = &PTR_FUN_001ea1c0;
  iVar2 = FUN_00193e18(*(undefined4 *)(param_2 + 0x378),0x84);
  iVar5 = 0;
  do {
    uVar3 = FUN_00193e18(*(undefined4 *)(param_2 + 0x378),0x10);
    *(undefined4 *)(iVar5 + iVar2) = uVar3;
    iVar6 = 4;
    iVar4 = 0;
    do {
      *(undefined4 *)(iVar4 + *(int *)(iVar5 + iVar2)) = 1;
      iVar4 = iVar4 + 4;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    bVar1 = iVar5 != 0x80;
    iVar5 = iVar5 + 4;
  } while (bVar1);
  param_1[0x4e] = iVar2;
  param_1[0x4d] = 0;
  return;
}

/* FUN_0010a398 @ 0x10a398 (184 bytes) */
int FUN_0010a398(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  FUN_001070f8(param_1,0x8e,param_2);
  param_1[0x20] = 1;
  *param_1 = &PTR_FUN_001ea1c0;
  iVar2 = FUN_00193e18(*(undefined4 *)(param_2 + 0x378),0x84);
  iVar5 = 0;
  do {
    uVar3 = FUN_00193e18(*(undefined4 *)(param_2 + 0x378),0x10);
    *(undefined4 *)(iVar5 + iVar2) = uVar3;
    iVar6 = 4;
    iVar4 = 0;
    do {
      *(undefined4 *)(iVar4 + *(int *)(iVar5 + iVar2)) = 1;
      iVar4 = iVar4 + 4;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    bVar1 = iVar5 != 0x80;
    iVar5 = iVar5 + 4;
  } while (bVar1);
  param_1[0x4e] = iVar2;
  param_1[0x4d] = 0;
  return;
}

/* FUN_0010a474 @ 0x10a474 (96 bytes) */
int FUN_0010a474(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,0x81,param_3);
  puVar1 = PTR_DAT_001e8c38;
  param_1[0x21] = 1;
  param_1[5] = param_1[5] | 0x18;
  *param_1 = puVar1 + 8;
  param_1[0x20] = 1;
  FUN_000ee9ac(*(undefined4 *)(param_3 + 0x6c4),param_1);
  return;
}

/* FUN_0010a50c @ 0x10a50c (96 bytes) */
int FUN_0010a50c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,0x81,param_3);
  puVar1 = PTR_DAT_001e8c38;
  param_1[0x21] = 1;
  param_1[5] = param_1[5] | 0x18;
  *param_1 = puVar1 + 8;
  param_1[0x20] = 1;
  FUN_000ee9ac(*(undefined4 *)(param_3 + 0x6c4),param_1);
  return;
}

/* FUN_0010a5a4 @ 0x10a5a4 (68 bytes) */
int FUN_0010a5a4(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_0010a50c)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_0010a620 @ 0x10a620 (100 bytes) */
int FUN_0010a620(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,0x8d,param_3);
  puVar1 = PTR_DAT_001e8c40 + 8;
  param_1[0x20] = 0;
  *param_1 = puVar1;
  param_1[5] = param_1[5] | 0x18;
  param_1[0x21] = 1;
  FUN_000ee9ac(*(undefined4 *)(param_3 + 0x6c4),param_1);
  return;
}

/* FUN_0010a6bc @ 0x10a6bc (100 bytes) */
int FUN_0010a6bc(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,0x8d,param_3);
  puVar1 = PTR_DAT_001e8c40 + 8;
  param_1[0x20] = 0;
  *param_1 = puVar1;
  param_1[5] = param_1[5] | 0x18;
  param_1[0x21] = 1;
  FUN_000ee9ac(*(undefined4 *)(param_3 + 0x6c4),param_1);
  return;
}

/* FUN_0010a758 @ 0x10a758 (68 bytes) */
int FUN_0010a758(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  ((int (*)())FUN_0010a6bc)(puVar1 + 1,param_1,param_2);
  return puVar1 + 1;
}

/* FUN_0010a7d4 @ 0x10a7d4 (104 bytes) */
int FUN_0010a7d4(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,0x90,param_4);
  puVar1 = PTR_DAT_001e8c18;
  param_1[0x4b] = param_2;
  param_1[5] = param_1[5] | 0x100;
  *param_1 = puVar1 + 8;
  param_1[0x4c] = param_3;
  return;
}

/* FUN_0010a83c @ 0x10a83c (104 bytes) */
int FUN_0010a83c(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,0x90,param_4);
  puVar1 = PTR_DAT_001e8c18;
  param_1[0x4b] = param_2;
  param_1[5] = param_1[5] | 0x100;
  *param_1 = puVar1 + 8;
  param_1[0x4c] = param_3;
  return;
}

/* FUN_0010a8a4 @ 0x10a8a4 (104 bytes) */
int FUN_0010a8a4(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,0x8f,param_4);
  puVar1 = PTR_DAT_001e8c4c;
  param_1[0x4b] = param_2;
  param_1[5] = param_1[5] | 0x100;
  *param_1 = puVar1 + 8;
  param_1[0x4c] = param_3;
  return;
}

/* FUN_0010a90c @ 0x10a90c (104 bytes) */
int FUN_0010a90c(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,0x8f,param_4);
  puVar1 = PTR_DAT_001e8c4c;
  param_1[0x4b] = param_2;
  param_1[5] = param_1[5] | 0x100;
  *param_1 = puVar1 + 8;
  param_1[0x4c] = param_3;
  return;
}

/* FUN_0010a974 @ 0x10a974 (88 bytes) */
int FUN_0010a974(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,0x92,param_2);
  puVar1 = PTR_DAT_001e8c00 + 8;
  param_1[5] = param_1[5] | 0x100;
  *param_1 = puVar1;
  return;
}

/* FUN_0010a9cc @ 0x10a9cc (88 bytes) */
int FUN_0010a9cc(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,0x92,param_2);
  puVar1 = PTR_DAT_001e8c00 + 8;
  param_1[5] = param_1[5] | 0x100;
  *param_1 = puVar1;
  return;
}

/* FUN_0010aa24 @ 0x10aa24 (88 bytes) */
int FUN_0010aa24(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,0x91,param_2);
  puVar1 = PTR_DAT_001e8be0 + 8;
  param_1[5] = param_1[5] | 0x100;
  *param_1 = puVar1;
  return;
}

/* FUN_0010aa7c @ 0x10aa7c (88 bytes) */
int FUN_0010aa7c(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,0x91,param_2);
  puVar1 = PTR_DAT_001e8be0 + 8;
  param_1[5] = param_1[5] | 0x100;
  *param_1 = puVar1;
  return;
}

/* FUN_0010aad4 @ 0x10aad4 (40 bytes) */
double FUN_0010aad4(int param_1)
{
  return (double)*(float *)(&DAT_001af9ec + param_1 * 4);
}

/* FUN_0010aafc @ 0x10aafc (68 bytes) */
undefined4 FUN_0010aafc(double fparam_1)
{
  float *pfVar1;
  int iVar2;
  
  pfVar1 = (float *)&DAT_001af9e0;
  iVar2 = 7;
  do {
    if ((double)*pfVar1 == fparam_1) {
      return 1;
    }
    pfVar1 = pfVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}

/* FUN_0010ab40 @ 0x10ab40 (76 bytes) */
int FUN_0010ab40(double fparam_1)
{
  float *pfVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  pfVar1 = (float *)&DAT_001af9e0;
  iVar3 = 7;
  do {
    if ((double)*pfVar1 == fparam_1) {
      return iVar2 + -3;
    }
    iVar2 = iVar2 + 1;
    pfVar1 = pfVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 0;
}

/* FUN_0010ab8c @ 0x10ab8c (172 bytes) */
undefined4 FUN_0010ab8c(undefined4 param_1,undefined4 *param_2,double fparam_1)
{
  undefined4 uVar1;
  
  uVar1 = 0xfffffffd;
  if ((((fparam_1 != (double)FLOAT_001aa170) &&
       (uVar1 = 0xfffffffe, fparam_1 != (double)FLOAT_001aa110)) &&
      (uVar1 = 0xffffffff, fparam_1 != (double)FLOAT_001aa10c)) &&
     (((uVar1 = 0, fparam_1 != (double)FLOAT_001aa0e8 &&
       (uVar1 = 1, fparam_1 != (double)FLOAT_001aa108)) &&
      (uVar1 = 2, fparam_1 != (double)FLOAT_001aa104)))) {
    if (fparam_1 != (double)FLOAT_001aa100) {
      return 0;
    }
    uVar1 = 3;
  }
  *param_2 = uVar1;
  return 1;
}

/* FUN_0010ac38 @ 0x10ac38 (304 bytes) */
int FUN_0010ac38(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  int iVar1;
  int iVar2;
  int extraout_r4;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar1 = param_2;
  iVar2 = param_3;
  if (0 < param_2) {
    (**(code **)(*param_1 + 0x14))(param_1,param_2,param_3,param_4);
    iVar1 = extraout_r4;
  }
  if (0 < param_3) {
    (**(code **)(*param_1 + 0x14))(param_1,iVar1,iVar2,param_4);
  }
  iVar1 = param_1[param_2 * 6 + 0x23];
  iVar7 = param_1[param_2 * 6 + 0x24];
  iVar5 = param_1[param_2 * 6 + 0x25];
  iVar3 = param_1[param_2 * 6 + 0x26];
  iVar2 = param_1[param_2 * 6 + 0x27];
  iVar8 = param_1[param_2 * 6 + 0x28];
  iVar9 = param_1[param_3 * 6 + 0x24];
  iVar6 = param_1[param_3 * 6 + 0x25];
  iVar4 = param_1[param_3 * 6 + 0x26];
  param_1[param_2 * 6 + 0x23] = param_1[param_3 * 6 + 0x23];
  param_1[param_2 * 6 + 0x24] = iVar9;
  param_1[param_2 * 6 + 0x25] = iVar6;
  param_1[param_2 * 6 + 0x26] = iVar4;
  iVar4 = param_1[param_3 * 6 + 0x28];
  param_1[param_2 * 6 + 0x27] = param_1[param_3 * 6 + 0x27];
  param_1[param_2 * 6 + 0x28] = iVar4;
  param_1[param_3 * 6 + 0x24] = iVar7;
  param_1[param_3 * 6 + 0x25] = iVar5;
  param_1[param_3 * 6 + 0x26] = iVar3;
  param_1[param_3 * 6 + 0x23] = iVar1;
  param_1[param_3 * 6 + 0x27] = iVar2;
  iVar1 = param_1[param_3 + 0x41];
  iVar2 = param_1[param_2 + 0x41];
  param_1[param_3 * 6 + 0x28] = iVar8;
  param_1[param_2 + 0x41] = iVar1;
  param_1[param_3 + 0x41] = iVar2;
  return;
}

/* FUN_0010ad68 @ 0x10ad68 (76 bytes) */
int FUN_0010ad68(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  uVar3 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar3,0x168);
  puVar4 = puVar1 + 1;
  *puVar1 = uVar3;
  FUN_0010502c(puVar4,0x8c,param_2);
  iVar2 = FUN_001054ec(puVar4,1);
  *(undefined4 *)(iVar2 + 8) = param_1;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  uVar3 = UNK_001af9d4;
  iVar2 = FUN_001054ec(puVar4,1);
  *(undefined4 *)(iVar2 + 0x10) = uVar3;
  puVar1[0x4c] = 0;
  return puVar4;
}

/* FUN_0010ae20 @ 0x10ae20 (200 bytes) */
int FUN_0010ae20(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  FUN_00103f18(param_1,&local_48,0xffffffff);
  uVar3 = *(undefined4 *)(param_1 + 4);
  uVar4 = *(undefined4 *)(param_1 + 0x158);
  iVar2 = FUN_00104054(param_1,param_3);
  FUN_0019401c(param_1);
  FUN_00103f84(param_1,param_2);
  FUN_00103f44(param_1,&local_48);
  iVar1 = *(int *)(param_3 + 0x478);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x14c);
  *(int *)(param_1 + 0x160) = iVar2 + iVar1;
  *(undefined4 *)(param_1 + 0x98) = 0;
  FUN_000e7738(uVar4,uVar3,param_1);
  (**(code **)(*param_2 + 0xc))(param_2,0,*(undefined4 *)(param_3 + 8));
  return;
}

/* FUN_0010aee8 @ 0x10aee8 (80 bytes) */
float * FUN_0010aee8(float *param_1,int param_2,float param_3)
{
  double dVar1;
  
  dVar1 = (double)((double (*)())FUN_0010aad4)(*(undefined4 *)(param_2 + 0x124));
  *param_1 = (float)(dVar1 * (double)param_3);
  return param_1;
}

/* FUN_0010af38 @ 0x10af38 (200 bytes) */
int FUN_0010af38(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint *puVar7;
  
  iVar1 = (**(code **)(*param_1 + 0x5c))();
  piVar2 = param_1;
  if (iVar1 != 0) {
    piVar2 = (int *)FUN_0010445c(param_1,*(undefined4 *)(param_2 + 8),0);
    iVar5 = piVar2[0x53];
    iVar1 = FUN_001054ec(piVar2,0);
    *(int *)(iVar1 + 8) = iVar5;
    FUN_000e7700(param_1[0x56],param_1,piVar2);
    piVar2[0x58] = *(int *)(param_2 + 0x478);
    if (param_3 != 0) {
      uVar6 = *(undefined4 *)(*(int *)(param_2 + 8) + 0x378);
      puVar3 = (undefined4 *)FUN_00193e18(uVar6,0x14);
      puVar3[1] = 2;
      *puVar3 = uVar6;
      puVar3[2] = 0;
      puVar3[4] = uVar6;
      uVar6 = FUN_00193e18(uVar6,8);
      puVar3[3] = uVar6;
      piVar2[4] = (int)(puVar3 + 1);
      for (iVar1 = 1; iVar5 = (**(code **)(*piVar2 + 0x14))(piVar2), iVar1 <= iVar5;
          iVar1 = iVar1 + 1) {
        iVar5 = FUN_00105594(piVar2,iVar1);
        puVar7 = *(uint **)(iVar5 + 0x10);
        uVar4 = puVar7[1];
        if (uVar4 < *puVar7) {
          _memset((void *)(uVar4 * 4 + puVar7[2]),0,4);
          puVar3 = (undefined4 *)(uVar4 * 4 + puVar7[2]);
          puVar7[1] = uVar4 + 1;
        }
        else {
          puVar3 = (undefined4 *)FUN_0019423c(puVar7,uVar4);
        }
        *puVar3 = piVar2;
      }
    }
    for (iVar1 = 1; iVar5 = (**(code **)(*piVar2 + 0x14))(piVar2), iVar1 <= iVar5; iVar1 = iVar1 + 1
        ) {
      iVar5 = FUN_00105594(piVar2,iVar1);
      if (*(int *)(param_2 + 0x478) < *(int *)(iVar5 + 0x160)) {
        *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + 1;
      }
      else {
        *(int *)(iVar5 + 0x160) = *(int *)(param_2 + 0x478) + 1;
      }
    }
  }
  return piVar2;
}

/* FUN_0010b118 @ 0x10b118 (108 bytes) */
void FUN_0010b118(float *param_1,int param_2,float param_3)
{
  float fVar1;
  
  fVar1 = param_3;
  if ((*(int *)(param_2 + 0x120) != 0) && (fVar1 = FLOAT_001aa0e8, param_3 <= FLOAT_001aa0e8)) {
    fVar1 = param_3;
    if (param_3 < 0.0) {
      fVar1 = FLOAT_001aa0d4;
    }
    if (-param_3 < 0.0) {
      fVar1 = param_3;
    }
  }
  *param_1 = fVar1;
  return;
}

/* FUN_0010b184 @ 0x10b184 (256 bytes) */
int FUN_0010b184(int *param_1,undefined4 param_2,int *param_3,double fparam_1)
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  (**(code **)(*param_1 + 0x60))();
  do {
    iVar3 = FUN_001054ec(param_1,0);
    iVar6 = 1;
    if (*(char *)(iVar5 + iVar3 + 0x10) != '\x01') {
      for (; iVar3 = (**(code **)(*param_1 + 0x14))(param_1), iVar6 <= iVar3; iVar6 = iVar6 + 1) {
        iVar3 = FUN_00105594(param_1,iVar6);
        if (*(int *)(iVar3 + 0x98) == 0x33) {
          iVar4 = FUN_001054ec(param_1,iVar6);
          uVar2 = (uint)*(byte *)(iVar5 + iVar4 + 0x10);
          if ((uVar2 != 4) && ((double)*(float *)(uVar2 * 0x18 + iVar3 + 0x20) == fparam_1)) {
            *param_3 = iVar5;
            return iVar6;
          }
        }
      }
    }
    bVar1 = iVar5 == 3;
    iVar5 = iVar5 + 1;
    if (bVar1) {
      return 0;
    }
  } while( true );
}

/* FUN_0010b284 @ 0x10b284 (88 bytes) */
void FUN_0010b284(float *param_1,int param_2,int param_3,float param_4)
{
  float fVar1;
  
  fVar1 = param_4;
  if ((*(uint *)(param_3 * 0x18 + param_2 + 0xa0) & 1) != 0) {
    fVar1 = FLOAT_001aa0d4;
    if (param_4 != FLOAT_001aa0d4) {
      fVar1 = -param_4;
    }
  }
  *param_1 = fVar1;
  return;
}

/* FUN_0010b2dc @ 0x10b2dc (80 bytes) */
void FUN_0010b2dc(float *param_1,int param_2,int param_3,float param_4)
{
  if ((*(uint *)(param_3 * 0x18 + param_2 + 0xa0) & 2) != 0) {
    if (param_4 < FLOAT_001aa0d4) {
      param_4 = -param_4;
    }
  }
  *param_1 = param_4;
  return;
}

/* FUN_0010b32c @ 0x10b32c (100 bytes) */
int FUN_0010b32c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,double fparam_1)
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  switch(param_1) {
  case 0:
    uVar2 = 0x2a;
    bVar1 = false;
    break;
  case 1:
    uVar2 = 0x27;
    bVar1 = false;
    break;
  case 2:
    uVar2 = 0x29;
    bVar1 = true;
    break;
  case 3:
    uVar2 = 0x28;
    bVar1 = true;
    break;
  case 4:
    uVar2 = 0x29;
    bVar1 = false;
    break;
  case 5:
    uVar2 = 0x28;
    bVar1 = false;
    break;
  default:
    uVar2 = 0;
    bVar1 = false;
  }
  uVar5 = *(undefined4 *)(param_5 + 0x6c4);
  iVar3 = FUN_001043f0(uVar2,param_5);
  iVar4 = FUN_001054ec(iVar3,2 - (uint)!bVar1);
  *(undefined4 *)(iVar4 + 0xc) = param_3;
  *(undefined4 *)(iVar4 + 8) = param_2;
  if (!bVar1) {
    uVar2 = 2;
  }
  else {
    uVar2 = 1;
  }
  ((void (*)())FUN_000f79c4)(iVar3,uVar5,uVar2,fparam_1,fparam_1,fparam_1,fparam_1);
  iVar6 = *(int *)(param_5 + 0x3ac) + -1;
  *(int *)(param_5 + 0x3ac) = iVar6;
  iVar4 = FUN_001054ec(iVar3,0);
  uVar2 = _UNK_001af9d8;
  *(undefined4 *)(iVar4 + 0xc) = 0;
  *(int *)(iVar4 + 8) = iVar6;
  *(undefined4 *)(iVar3 + 0x9c) = uVar2;
  return iVar3;
}

/* FUN_0010b498 @ 0x10b498 (352 bytes) */
int FUN_0010b498(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  bool bVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  
  fVar2 = FLOAT_001aa0d4;
  iVar5 = 0;
  do {
    iVar3 = FUN_001054ec(param_1,0);
    if (*(char *)(iVar5 + iVar3 + 0x10) != '\x01') {
      iVar3 = FUN_001054ec(param_1,param_2);
      uVar6 = (uint)*(byte *)(iVar5 + iVar3 + 0x10);
      piVar4 = (int *)FUN_00105594(param_1,param_2);
      while (iVar3 = (**(code **)(*piVar4 + 100))(piVar4), iVar3 != 0) {
        iVar3 = FUN_001054ec(piVar4,0);
        if (*(char *)(uVar6 + iVar3 + 0x10) == '\0') {
          iVar3 = FUN_001054ec(piVar4,1);
          uVar6 = (uint)*(byte *)(uVar6 + iVar3 + 0x10);
          piVar4 = (int *)FUN_00105594(piVar4,1);
        }
        else {
          piVar4 = (int *)FUN_00105594(piVar4,piVar4[0x21]);
        }
      }
      iVar3 = (**(code **)(*piVar4 + 0x48))(piVar4);
      if (((iVar3 == 0) || (((int)*(char *)(piVar4 + 0x57) >> (uVar6 & 0x3f) & 1U) == 0)) ||
         ((float)piVar4[uVar6 * 6 + 8] != fVar2)) {
        return 0;
      }
    }
    bVar1 = iVar5 == 3;
    iVar5 = iVar5 + 1;
    if (bVar1) {
      return 1;
    }
  } while( true );
}

/* FUN_0010b5f8 @ 0x10b5f8 (112 bytes) */
int FUN_0010b5f8(param_1)
  int param_1;
{
  switch(*(undefined4 *)(*(int *)(param_1 + 0x88) + 8)) {
  case 0x20:
  case 0x24:
  case 0x27:
    return 0;
  case 0x21:
  case 0x26:
  case 0x28:
    return 2;
  case 0x22:
  case 0x25:
  case 0x29:
    return 3;
  case 0x23:
  case 0x2a:
    return 1;
  default:
    return 8;
  case 0x8b:
  case 0x8c:
  case 0x8d:
    return *(undefined4 *)(param_1 + 300);
  }
}

/* FUN_0010b820 @ 0x10b820 (220 bytes) */
bool FUN_0010b820(undefined4 param_1,double fparam_1,double fparam_2)
{
  undefined4 uVar1;
  bool bVar2;
  
  uVar1 = ((int (*)())FUN_0010b5f8)(param_1);
  bVar2 = false;
  switch(uVar1) {
  case 0:
    bVar2 = fparam_1 == fparam_2;
    break;
  case 1:
    bVar2 = fparam_1 != fparam_2;
    break;
  case 2:
    bVar2 = fparam_2 < fparam_1;
    break;
  case 3:
    bVar2 = fparam_2 <= fparam_1;
    break;
  case 4:
    bVar2 = fparam_1 < fparam_2;
    break;
  case 5:
    bVar2 = fparam_1 <= fparam_2;
  }
  return bVar2;
}

/* FUN_0010b914 @ 0x10b914 (40 bytes) */
int FUN_0010b914(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 8);
  if (((iVar1 != 0x8c) && (iVar1 != 0x8d)) && (iVar1 != 0x8b)) {
    return;
  }
  *(undefined4 *)(param_1 + 300) = param_2;
  return;
}

/* FUN_0010b93c @ 0x10b93c (344 bytes) */
float * FUN_0010b93c(float *param_1,int param_2,int param_3,float param_4,int param_5)
{
  uint uVar1;
  float fVar2;
  double dVar3;
  
  dVar3 = (double)param_4;
  (**(code **)(**(int **)(param_5 + 0x30c) + 0xf0))(dVar3,*(int **)(param_5 + 0x30c));
  switch(*(undefined4 *)(*(int *)(param_2 + 0x88) + 8)) {
  case 0x12:
    break;
  case 0x13:
    if (param_3 != 1) {
      dVar3 = (double)FLOAT_001aa0e8;
    }
    goto LAB_0010badc;
  case 0x14:
    if (param_3 == 2) {
      if ((*(uint *)(param_2 + 0xe8) & 1) == 0) {
        fVar2 = 0.0;
      }
      else {
        fVar2 = 1.0;
      }
      goto LAB_0010baf4;
    }
    if (param_3 == 3) {
      uVar1 = *(uint *)(param_2 + 0xe8);
      goto joined_r0x0010bad0;
    }
    if (param_3 == 1) {
      uVar1 = *(uint *)(param_2 + 0xe8);
      goto joined_r0x0010baa4;
    }
  default:
    fVar2 = NAN;
LAB_0010baf4:
    *param_1 = fVar2;
    return param_1;
  case 0x16:
  case 0x17:
  case 0x19:
  case 0x31:
    *param_1 = param_4;
    return param_1;
  }
  if (param_3 == 1) {
    uVar1 = *(uint *)(param_2 + 0xb8);
joined_r0x0010bad0:
    if ((uVar1 & 1) == 0) goto LAB_0010badc;
  }
  else {
    uVar1 = *(uint *)(param_2 + 0xb8);
joined_r0x0010baa4:
    if ((uVar1 & 1) != 0) goto LAB_0010badc;
  }
  dVar3 = (double)FLOAT_001aa0d4;
LAB_0010badc:
  *param_1 = (float)dVar3;
  return param_1;
}

/* FUN_0010bb14 @ 0x10bb14 (136 bytes) */
int FUN_0010bb14(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 8);
  if (iVar1 == 0x13) {
    if ((*(uint *)(param_1 + 0xb8) & 1) == (*(uint *)(param_1 + 0xd0) & 1)) {
      return 1;
    }
  }
  else if (iVar1 == 0x14) {
    if ((*(uint *)(param_1 + 0xb8) & 1) == (*(uint *)(param_1 + 0xd0) & 1)) {
      return 1;
    }
    if ((*(uint *)(param_1 + 0xe8) & 1) != 0) {
      return 1;
    }
  }
  else if ((iVar1 == 0x12) &&
          (((*(uint *)(param_1 + 0xb8) & 1) == 0 || ((*(uint *)(param_1 + 0xd0) & 1) == 0)))) {
    return 1;
  }
  return 0;
}

/* FUN_0010bb9c @ 0x10bb9c (220 bytes) */
int FUN_0010bb9c(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  undefined4 param_6;
{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = (**(code **)(*param_1 + 0x14))();
  uVar3 = FUN_0011333c(*(undefined4 *)(param_1[0x22] + 8),param_6);
  iVar4 = FUN_00112f54(uVar3);
  param_1[0x22] = iVar4;
  if (param_5 != 0) {
    iVar4 = FUN_00112f54(0x35);
    param_1[0x22] = iVar4;
    FUN_00103d50(param_1 + 0x2f,1,param_1[0x34] & 1U ^ 1);
  }
  puVar1 = PTR_DAT_001e8b8c;
  param_1[0x2d] = *(int *)(PTR_DAT_001e8b8c + param_2 * 4);
  if (1 < iVar2) {
    param_1[0x33] = *(int *)(puVar1 + param_3 * 4);
  }
  if (2 < iVar2) {
    param_1[0x39] = *(int *)(puVar1 + param_4 * 4);
  }
  return;
}

/* FUN_0010bc78 @ 0x10bc78 (216 bytes) */
int FUN_0010bc78(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_28;
  int local_24;
  int local_20 [4];
  
  iVar1 = *(int *)(param_1[0x22] + 8);
  uVar2 = FUN_0011333c(iVar1,param_2);
  iVar3 = FUN_00112f54(uVar2);
  param_1[0x22] = iVar3;
  iVar3 = (**(code **)(*param_1 + 0x14))(param_1);
  FUN_000f33f8(&local_28,param_1[0x2d]);
  param_1[0x2d] = local_28;
  if (1 < iVar3) {
    FUN_000f33f8(&local_24,param_1[0x33]);
    param_1[0x33] = local_24;
  }
  if (2 < iVar3) {
    FUN_000f33f8(local_20,param_1[0x39]);
    param_1[0x39] = local_20[0];
  }
  if (iVar1 == 0x35) {
    FUN_00103d50(param_1 + 0x2f,1,param_1[0x34] & 1U ^ 1);
  }
  return iVar1 == 0x35;
}

/* FUN_0010bd50 @ 0x10bd50 (332 bytes) */
void FUN_0010bd50(int param_1,undefined4 param_2,int param_3,int param_4,double fparam_1)
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  *(int *)(param_1 + 0x84) = param_3;
  ((void (*)())FUN_000f79c4)(param_1,*(undefined4 *)(param_4 + 0x6c4),param_3,fparam_1,fparam_1,fparam_1,fparam_1)
  ;
  uVar4 = DAT_001af9fc;
  if (param_3 == 0) {
    *(undefined4 *)(param_1 + 0x9c) = DAT_001af9fc;
  }
  else {
    iVar3 = FUN_001054ec(param_1,param_3);
    *(undefined4 *)(iVar3 + 0x10) = uVar4;
  }
  if ((*(uint *)(*(int *)(param_4 + 0x6c4) + 0x30) & 8) == 0) {
    iVar3 = *(int *)(param_3 * 0x18 + param_1 + 0x8c);
    piVar1 = *(int **)(iVar3 + 0x18);
    if (*piVar1 == 0) {
      piVar1 = (int *)FUN_0019423c(piVar1,0);
    }
    else {
      if (piVar1[1] == 0) {
        *(undefined4 *)piVar1[2] = 0;
        piVar1[1] = 1;
      }
      piVar1 = (int *)piVar1[2];
    }
    iVar5 = *piVar1;
    if (*(int *)(*(int *)(iVar3 + 0x2c) + 4) == 0) {
      uVar4 = *(undefined4 *)(param_4 + 0x378);
      puVar2 = (undefined4 *)FUN_00193e18(uVar4,0x240);
      puVar6 = puVar2 + 1;
      *puVar2 = uVar4;
      FUN_00173938(puVar6,iVar5,param_4);
      FUN_00173f1c(puVar6);
      FUN_00174e0c(puVar6);
      FUN_00173278(puVar6);
      FUN_00123424(iVar3,*(undefined4 *)(*(int *)(iVar5 + 0x158) + 0xb0),puVar6);
    }
    FUN_00106004(param_1,param_3,iVar5,0,param_4);
    return;
  }
  return;
}

