#include "decls.h"

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
int FUN_00108e40(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  FUN_001070f8();
  puVar1 = PTR_DAT_001e8c54;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00108e8c @ 0x108e8c (84 bytes) */
int FUN_00108e8c(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)();
  puVar1 = PTR_DAT_001e8c14;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00108ee0 @ 0x108ee0 (92 bytes) */
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
int FUN_00108f5c(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)();
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
int FUN_00109348(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_00108e40)(param_1,0x7a);
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
int FUN_001093b8(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_00108e40)(param_1,0x7a);
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
int FUN_00109428(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)();
  puVar1 = PTR_DAT_001e8c20;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  param_1[0x26] = 0;
  return;
}

/* FUN_00109480 @ 0x109480 (92 bytes) */
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
int FUN_001094fc(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  ((int (*)())FUN_00108e40)();
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

/* FUN_00109614 @ 0x109614 (132 bytes) */
int FUN_00109614(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  
  ((int (*)())FUN_00108e40)(param_1,0x79);
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

/* FUN_001096bc @ 0x1096bc (132 bytes) */
int FUN_001096bc(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  
  ((int (*)())FUN_00108e40)(param_1,0x79);
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

/* FUN_00109764 @ 0x109764 (136 bytes) */
int FUN_00109764(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  int iVar2;
  
  ((int (*)())FUN_00108e40)();
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

/* FUN_00109810 @ 0x109810 (92 bytes) */
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

/* FUN_0010988c @ 0x10988c (136 bytes) */
int FUN_0010988c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined *puVar1;
  int iVar2;
  
  ((int (*)())FUN_00108e40)();
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

/* FUN_00109938 @ 0x109938 (128 bytes) */
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

/* FUN_001099dc @ 0x1099dc (128 bytes) */
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

/* FUN_00109a80 @ 0x109a80 (76 bytes) */
int FUN_00109a80(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  FUN_001070f8();
  puVar1 = PTR_DAT_001e8c54;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00109acc @ 0x109acc (84 bytes) */
int FUN_00109acc(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  FUN_001070f8();
  puVar1 = PTR_DAT_001e8c04;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00109b20 @ 0x109b20 (84 bytes) */
int FUN_00109b20(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  FUN_001070f8();
  puVar1 = PTR_DAT_001e8c04;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00109b74 @ 0x109b74 (92 bytes) */
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
int FUN_00109ca8(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  FUN_001070f8();
  puVar1 = PTR_DAT_001e8c1c;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00109cfc @ 0x109cfc (84 bytes) */
int FUN_00109cfc(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  FUN_001070f8();
  puVar1 = PTR_DAT_001e8c1c;
  param_1[0x21] = 0;
  param_1[0x20] = 1;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00109d50 @ 0x109d50 (92 bytes) */
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
int FUN_00109dcc(param_1)
  undefined4 *param_1;
{
  FUN_001070f8();
  param_1[0x4c] = 0;
  *param_1 = &PTR_FUN_001ea3b8;
  param_1[0x21] = 1;
  param_1[0x20] = 1;
  param_1[0x4b] = 0;
  return;
}

/* FUN_00109e28 @ 0x109e28 (92 bytes) */
int FUN_00109e28(param_1)
  undefined4 *param_1;
{
  FUN_001070f8();
  param_1[0x4c] = 0;
  *param_1 = &PTR_FUN_001ea3b8;
  param_1[0x21] = 1;
  param_1[0x20] = 1;
  param_1[0x4b] = 0;
  return;
}

/* FUN_00109e84 @ 0x109e84 (92 bytes) */
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
int FUN_00109f00(param_1)
  undefined4 *param_1;
{
  FUN_001070f8();
  param_1[0x21] = 1;
  *param_1 = &PTR_FUN_001ea268;
  param_1[0x20] = 1;
  return;
}

/* FUN_00109f50 @ 0x109f50 (80 bytes) */
int FUN_00109f50(param_1)
  undefined4 *param_1;
{
  FUN_001070f8();
  param_1[0x21] = 1;
  *param_1 = &PTR_FUN_001ea268;
  param_1[0x20] = 1;
  return;
}

/* FUN_00109fa0 @ 0x109fa0 (92 bytes) */
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
int FUN_0010a01c(param_1)
  undefined4 *param_1;
{
  FUN_001070f8();
  param_1[0x21] = 2;
  *param_1 = &PTR_FUN_001ea310;
  param_1[0x20] = 1;
  return;
}

/* FUN_0010a070 @ 0x10a070 (84 bytes) */
int FUN_0010a070(param_1)
  undefined4 *param_1;
{
  FUN_001070f8();
  param_1[0x21] = 2;
  *param_1 = &PTR_FUN_001ea310;
  param_1[0x20] = 1;
  return;
}

/* FUN_0010a0c4 @ 0x10a0c4 (92 bytes) */
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
int FUN_0010a140(param_1)
  undefined4 *param_1;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  FUN_001070f8();
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
int FUN_0010a1c0(param_1)
  undefined4 *param_1;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  FUN_001070f8();
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

/* FUN_0010a240 @ 0x10a240 (92 bytes) */
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

/* FUN_0010a50c @ 0x10a50c (116 bytes) */
int FUN_0010a50c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,0x81);
  puVar1 = PTR_DAT_001e8c38;
  param_1[0x21] = 1;
  param_1[5] = param_1[5] | 0x18;
  *param_1 = puVar1 + 8;
  param_1[0x20] = 1;
  FUN_000ee9ac(*(undefined4 *)(param_3 + 0x6c4),param_1);
  return;
}

/* FUN_0010a5a4 @ 0x10a5a4 (92 bytes) */
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

/* FUN_0010a620 @ 0x10a620 (120 bytes) */
int FUN_0010a620(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,0x8d);
  puVar1 = PTR_DAT_001e8c40 + 8;
  param_1[0x20] = 0;
  *param_1 = puVar1;
  param_1[5] = param_1[5] | 0x18;
  param_1[0x21] = 1;
  FUN_000ee9ac(*(undefined4 *)(param_3 + 0x6c4),param_1);
  return;
}

/* FUN_0010a6bc @ 0x10a6bc (120 bytes) */
int FUN_0010a6bc(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  FUN_001070f8(param_1,0x8d);
  puVar1 = PTR_DAT_001e8c40 + 8;
  param_1[0x20] = 0;
  *param_1 = puVar1;
  param_1[5] = param_1[5] | 0x18;
  param_1[0x21] = 1;
  FUN_000ee9ac(*(undefined4 *)(param_3 + 0x6c4),param_1);
  return;
}

/* FUN_0010a758 @ 0x10a758 (92 bytes) */
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

