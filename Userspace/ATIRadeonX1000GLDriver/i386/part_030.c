#include "decls.h"

/* FUN_0010eb52 @ 0x10eb52 (87 bytes) */
int FUN_0010eb52(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  FUN_0010e420(param_1,0x7a,param_2);
  *param_1 = PTR_DAT_00213519 + 8;
  param_1[0x26] = 0;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  return;
}

/* FUN_0010ebaa @ 0x10ebaa (124 bytes) */
int FUN_0010ebaa(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  FUN_0010e420(param_1,0x79,param_3);
  *param_1 = &PTR_FUN_001fcb28;
  param_1[0x26] = *(undefined4 *)(param_2 + 4);
  param_1[0x25] = *(undefined4 *)(param_2 + 8);
  param_1[0x23] = param_2;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  FUN_000f1af0(*(undefined4 *)(param_3 + 0x3f4),param_1);
  return;
}

/* FUN_0010ec42 @ 0x10ec42 (124 bytes) */
int FUN_0010ec42(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  FUN_0010e420(param_1,0x79,param_3);
  *param_1 = &PTR_FUN_001fcb28;
  param_1[0x26] = *(undefined4 *)(param_2 + 4);
  param_1[0x25] = *(undefined4 *)(param_2 + 8);
  param_1[0x23] = param_2;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  FUN_000f1af0(*(undefined4 *)(param_3 + 0x3f4),param_1);
  return;
}

/* FUN_0010ecda @ 0x10ecda (122 bytes) */
int FUN_0010ecda(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  char cVar1;
  
  FUN_0010e420(param_1,param_2,param_3);
  *param_1 = PTR_DAT_002134d5 + 8;
  param_1[0x4c] = 0;
  param_1[0x26] = 0x1a;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  cVar1 = FUN_000e1402(param_3,0x3e);
  if (cVar1 != '\0') {
    param_1[5] = param_1[5] | 0x18;
  }
  return;
}

/* FUN_0010ed70 @ 0x10ed70 (69 bytes) */
int FUN_0010ed70(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010ecda)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010edd4 @ 0x10edd4 (122 bytes) */
int FUN_0010edd4(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  char cVar1;
  
  FUN_0010e420(param_1,param_2,param_3);
  *param_1 = PTR_DAT_002134d5 + 8;
  param_1[0x4c] = 0;
  param_1[0x26] = 0x1a;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  cVar1 = FUN_000e1402(param_3,0x3e);
  if (cVar1 != '\0') {
    param_1[5] = param_1[5] | 0x18;
  }
  return;
}

/* FUN_0010ee6a @ 0x10ee6a (114 bytes) */
int FUN_0010ee6a(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  FUN_0010e420(param_1,0x79,param_2);
  *param_1 = &PTR_FUN_001fcb28;
  param_1[0x26] = 2;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  param_1[0x4b] = 0xffffffff;
  FUN_000f1af0(*(undefined4 *)(param_2 + 0x3f4),param_1);
  return;
}

/* FUN_0010eef8 @ 0x10eef8 (114 bytes) */
int FUN_0010eef8(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  FUN_0010e420(param_1,0x79,param_2);
  *param_1 = &PTR_FUN_001fcb28;
  param_1[0x26] = 2;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  param_1[0x4b] = 0xffffffff;
  FUN_000f1af0(*(undefined4 *)(param_2 + 0x3f4),param_1);
  return;
}

/* FUN_0010ef86 @ 0x10ef86 (66 bytes) */
int FUN_0010ef86(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010ca48(param_1,param_2,param_3);
  *param_1 = PTR_DAT_0021354d + 8;
  param_1[0x20] = 1;
  return;
}

/* FUN_0010efc8 @ 0x10efc8 (76 bytes) */
int FUN_0010efc8(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010ca48(param_1,param_2,param_3);
  *param_1 = PTR_DAT_002134fd + 8;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  return;
}

/* FUN_0010f014 @ 0x10f014 (76 bytes) */
int FUN_0010f014(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010ca48(param_1,param_2,param_3);
  *param_1 = PTR_DAT_002134fd + 8;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  return;
}

/* FUN_0010f060 @ 0x10f060 (69 bytes) */
int FUN_0010f060(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010f014)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010f0c4 @ 0x10f0c4 (77 bytes) */
int FUN_0010f0c4(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  FUN_0010ca48(param_1,0x83,param_2);
  *param_1 = PTR_DAT_00213515 + 8;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  return;
}

/* FUN_0010f112 @ 0x10f112 (77 bytes) */
int FUN_0010f112(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  FUN_0010ca48(param_1,0x83,param_2);
  *param_1 = PTR_DAT_00213515 + 8;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  return;
}

/* FUN_0010f160 @ 0x10f160 (76 bytes) */
int FUN_0010f160(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010ca48(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213515 + 8;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  return;
}

/* FUN_0010f1ac @ 0x10f1ac (76 bytes) */
int FUN_0010f1ac(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010ca48(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213515 + 8;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  return;
}

/* FUN_0010f1f8 @ 0x10f1f8 (69 bytes) */
int FUN_0010f1f8(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010f1ac)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010f25c @ 0x10f25c (87 bytes) */
int FUN_0010f25c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010ca48(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_001fca68;
  param_1[0x20] = 1;
  param_1[0x21] = 1;
  *(undefined1 *)(param_1 + 0x4b) = 0;
  *(undefined1 *)(param_1 + 0x4c) = 0;
  return;
}

/* FUN_0010f2b4 @ 0x10f2b4 (87 bytes) */
int FUN_0010f2b4(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010ca48(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_001fca68;
  param_1[0x20] = 1;
  param_1[0x21] = 1;
  *(undefined1 *)(param_1 + 0x4b) = 0;
  *(undefined1 *)(param_1 + 0x4c) = 0;
  return;
}

/* FUN_0010f30c @ 0x10f30c (69 bytes) */
int FUN_0010f30c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010f2b4)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010f370 @ 0x10f370 (73 bytes) */
int FUN_0010f370(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010ca48(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_001fc8e8;
  param_1[0x20] = 1;
  param_1[0x21] = 1;
  return;
}

/* FUN_0010f3ba @ 0x10f3ba (73 bytes) */
int FUN_0010f3ba(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010ca48(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_001fc8e8;
  param_1[0x20] = 1;
  param_1[0x21] = 1;
  return;
}

/* FUN_0010f404 @ 0x10f404 (69 bytes) */
int FUN_0010f404(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010f3ba)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010f468 @ 0x10f468 (73 bytes) */
int FUN_0010f468(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010ca48(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_001fc9a8;
  param_1[0x20] = 1;
  param_1[0x21] = 2;
  return;
}

/* FUN_0010f4b2 @ 0x10f4b2 (73 bytes) */
int FUN_0010f4b2(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010ca48(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_001fc9a8;
  param_1[0x20] = 1;
  param_1[0x21] = 2;
  return;
}

/* FUN_0010f4fc @ 0x10f4fc (69 bytes) */
int FUN_0010f4fc(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010f4b2)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010f560 @ 0x10f560 (122 bytes) */
int FUN_0010f560(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  int iVar2;
  
  FUN_0010ca48(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_001fc6a8;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  param_1[0x4b] = 0;
  param_1[0x27] = DAT_001cbe74;
  uVar1 = DAT_001cbe70;
  iVar2 = 4;
  do {
    param_1[0x2d] = uVar1;
    param_1 = param_1 + 6;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

/* FUN_0010f5da @ 0x10f5da (122 bytes) */
int FUN_0010f5da(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  int iVar2;
  
  FUN_0010ca48(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_001fc6a8;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  param_1[0x4b] = 0;
  param_1[0x27] = DAT_001cbe74;
  uVar1 = DAT_001cbe70;
  iVar2 = 4;
  do {
    param_1[0x2d] = uVar1;
    param_1 = param_1 + 6;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

/* FUN_0010f654 @ 0x10f654 (69 bytes) */
int FUN_0010f654(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010f5da)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010f6b8 @ 0x10f6b8 (185 bytes) */
int FUN_0010f6b8(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  FUN_0010ca48(param_1,0x8e,param_2);
  *param_1 = &PTR_FUN_001fc828;
  param_1[0x20] = 1;
  piVar2 = (int *)FUN_001a7bca(*(undefined4 *)(param_2 + 0xbc),0x84);
  iVar4 = 1;
  piVar1 = piVar2;
  do {
    iVar3 = FUN_001a7bca(*(undefined4 *)(param_2 + 0xbc),0x10);
    *piVar1 = iVar3;
    iVar3 = 0;
    do {
      *(undefined4 *)(iVar3 + *piVar1) = 1;
      iVar3 = iVar3 + 4;
    } while (iVar3 != 0x10);
    iVar4 = iVar4 + 1;
    piVar1 = piVar1 + 1;
  } while (iVar4 != 0x22);
  param_1[0x4e] = piVar2;
  *(undefined1 *)(param_1 + 0x4d) = 0;
  return;
}

/* FUN_0010f790 @ 0x10f790 (185 bytes) */
int FUN_0010f790(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  FUN_0010ca48(param_1,0x8e,param_2);
  *param_1 = &PTR_FUN_001fc828;
  param_1[0x20] = 1;
  piVar2 = (int *)FUN_001a7bca(*(undefined4 *)(param_2 + 0xbc),0x84);
  iVar4 = 1;
  piVar1 = piVar2;
  do {
    iVar3 = FUN_001a7bca(*(undefined4 *)(param_2 + 0xbc),0x10);
    *piVar1 = iVar3;
    iVar3 = 0;
    do {
      *(undefined4 *)(iVar3 + *piVar1) = 1;
      iVar3 = iVar3 + 4;
    } while (iVar3 != 0x10);
    iVar4 = iVar4 + 1;
    piVar1 = piVar1 + 1;
  } while (iVar4 != 0x22);
  param_1[0x4e] = piVar2;
  *(undefined1 *)(param_1 + 0x4d) = 0;
  return;
}

/* FUN_0010f868 @ 0x10f868 (101 bytes) */
int FUN_0010f868(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_0010ca48(param_1,0x81,param_3);
  *param_1 = PTR_DAT_00213531 + 8;
  param_1[0x20] = 1;
  param_1[0x21] = 1;
  param_1[5] = param_1[5] | 0x18;
  FUN_000f0b74(*(undefined4 *)(param_3 + 0x3f4),param_1);
  return;
}

/* FUN_0010f8e8 @ 0x10f8e8 (101 bytes) */
int FUN_0010f8e8(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_0010ca48(param_1,0x81,param_3);
  *param_1 = PTR_DAT_00213531 + 8;
  param_1[0x20] = 1;
  param_1[0x21] = 1;
  param_1[5] = param_1[5] | 0x18;
  FUN_000f0b74(*(undefined4 *)(param_3 + 0x3f4),param_1);
  return;
}

/* FUN_0010f968 @ 0x10f968 (69 bytes) */
int FUN_0010f968(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010f8e8)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010f9cc @ 0x10f9cc (101 bytes) */
int FUN_0010f9cc(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_0010ca48(param_1,0x8d,param_3);
  *param_1 = PTR_DAT_00213539 + 8;
  param_1[0x20] = 0;
  param_1[0x21] = 1;
  param_1[5] = param_1[5] | 0x18;
  FUN_000f0b74(*(undefined4 *)(param_3 + 0x3f4),param_1);
  return;
}

/* FUN_0010fa4c @ 0x10fa4c (101 bytes) */
int FUN_0010fa4c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_0010ca48(param_1,0x8d,param_3);
  *param_1 = PTR_DAT_00213539 + 8;
  param_1[0x20] = 0;
  param_1[0x21] = 1;
  param_1[5] = param_1[5] | 0x18;
  FUN_000f0b74(*(undefined4 *)(param_3 + 0x3f4),param_1);
  return;
}

/* FUN_0010facc @ 0x10facc (69 bytes) */
int FUN_0010facc(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010fa4c)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010fb30 @ 0x10fb30 (82 bytes) */
int FUN_0010fb30(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  FUN_0010ca48(param_1,0x90,param_4);
  *param_1 = PTR_DAT_00213511 + 8;
  param_1[0x4b] = param_2;
  param_1[0x4c] = param_3;
  param_1[5] = param_1[5] | 0x100;
  return;
}

/* FUN_0010fb82 @ 0x10fb82 (82 bytes) */
int FUN_0010fb82(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  FUN_0010ca48(param_1,0x90,param_4);
  *param_1 = PTR_DAT_00213511 + 8;
  param_1[0x4b] = param_2;
  param_1[0x4c] = param_3;
  param_1[5] = param_1[5] | 0x100;
  return;
}

/* FUN_0010fbd4 @ 0x10fbd4 (82 bytes) */
int FUN_0010fbd4(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  FUN_0010ca48(param_1,0x8f,param_4);
  *param_1 = PTR_DAT_00213545 + 8;
  param_1[0x4b] = param_2;
  param_1[0x4c] = param_3;
  param_1[5] = param_1[5] | 0x100;
  return;
}

/* FUN_0010fc26 @ 0x10fc26 (82 bytes) */
int FUN_0010fc26(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  FUN_0010ca48(param_1,0x8f,param_4);
  *param_1 = PTR_DAT_00213545 + 8;
  param_1[0x4b] = param_2;
  param_1[0x4c] = param_3;
  param_1[5] = param_1[5] | 0x100;
  return;
}

/* FUN_0010fc78 @ 0x10fc78 (64 bytes) */
int FUN_0010fc78(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  FUN_0010ca48(param_1,0x92,param_2);
  *param_1 = PTR_DAT_002134f9 + 8;
  param_1[5] = param_1[5] | 0x100;
  return;
}

/* FUN_0010fcb8 @ 0x10fcb8 (64 bytes) */
int FUN_0010fcb8(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  FUN_0010ca48(param_1,0x92,param_2);
  *param_1 = PTR_DAT_002134f9 + 8;
  param_1[5] = param_1[5] | 0x100;
  return;
}

/* FUN_0010fcf8 @ 0x10fcf8 (64 bytes) */
int FUN_0010fcf8(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  FUN_0010ca48(param_1,0x91,param_2);
  *param_1 = PTR_DAT_002134d9 + 8;
  param_1[5] = param_1[5] | 0x100;
  return;
}

/* FUN_0010fd38 @ 0x10fd38 (64 bytes) */
int FUN_0010fd38(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  FUN_0010ca48(param_1,0x91,param_2);
  *param_1 = PTR_DAT_002134d9 + 8;
  param_1[5] = param_1[5] | 0x100;
  return;
}

/* FUN_0010fd78 @ 0x10fd78 (20 bytes) */
int FUN_0010fd78(param_1)
  int param_1;
{
  return (longdouble)*(float *)(&DAT_001cbe98 + param_1 * 4);
}

/* FUN_0010fd8c @ 0x10fd8c (47 bytes) */
undefined4 FUN_0010fd8c(float param_1)

{
  float *pfVar1;
  
  pfVar1 = (float *)&DAT_001cbe8c;
  while ((param_1 != *pfVar1 || (NAN(param_1) || NAN(*pfVar1)))) {
    pfVar1 = pfVar1 + 1;
    if (pfVar1 == (float *)&DAT_001cbea8) {
      return 0;
    }
  }
  return 1;
}

/* FUN_0010fdbc @ 0x10fdbc (48 bytes) */
int FUN_0010fdbc(float param_1)

{
  int iVar1;
  float *pfVar2;
  
  iVar1 = 0;
  pfVar2 = (float *)&DAT_001cbe8c;
  while ((param_1 != *pfVar2 || (NAN(param_1) || NAN(*pfVar2)))) {
    iVar1 = iVar1 + 1;
    pfVar2 = pfVar2 + 1;
    if (iVar1 == 7) {
      return 0;
    }
  }
  return iVar1 + -3;
}

/* FUN_0010fdec @ 0x10fdec (150 bytes) */
undefined4 FUN_0010fdec(float param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != FLOAT_001c5c28) || (NAN(param_1) || NAN(FLOAT_001c5c28))) {
    if ((param_1 != FLOAT_001c5bd8) || (NAN(param_1) || NAN(FLOAT_001c5bd8))) {
      if ((param_1 != FLOAT_001c5bd4) || (NAN(param_1) || NAN(FLOAT_001c5bd4))) {
        if ((param_1 != FLOAT_001c5ba4) || (NAN(param_1) || NAN(FLOAT_001c5ba4))) {
          if ((param_1 != FLOAT_001c5bd0) || (NAN(param_1) || NAN(FLOAT_001c5bd0))) {
            if ((param_1 != FLOAT_001c5bcc) || (NAN(param_1) || NAN(FLOAT_001c5bcc))) {
              if (param_1 != FLOAT_001c5bc8) {
                return 0;
              }
              uVar1 = 3;
            }
            else {
              uVar1 = 2;
            }
          }
          else {
            uVar1 = 1;
          }
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 0xffffffff;
      }
    }
    else {
      uVar1 = 0xfffffffe;
    }
  }
  else {
    uVar1 = 0xfffffffd;
  }
  *param_2 = uVar1;
  return 1;
}

/* FUN_0010fe82 @ 0x10fe82 (210 bytes) */
int FUN_0010fe82(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (0 < param_2) {
    (**(code **)(*param_1 + 0x14))(param_1);
  }
  if (0 < param_3) {
    (**(code **)(*param_1 + 0x14))(param_1);
  }
  iVar1 = param_1[param_2 * 6 + 0x23];
  iVar2 = param_1[param_2 * 6 + 0x24];
  iVar3 = param_1[param_2 * 6 + 0x25];
  iVar4 = param_1[param_2 * 6 + 0x26];
  iVar5 = param_1[param_2 * 6 + 0x27];
  iVar6 = param_1[param_2 * 6 + 0x28];
  param_1[param_2 * 6 + 0x23] = param_1[param_3 * 6 + 0x23];
  param_1[param_2 * 6 + 0x24] = param_1[param_3 * 6 + 0x24];
  param_1[param_2 * 6 + 0x25] = param_1[param_3 * 6 + 0x25];
  param_1[param_2 * 6 + 0x26] = param_1[param_3 * 6 + 0x26];
  param_1[param_2 * 6 + 0x27] = param_1[param_3 * 6 + 0x27];
  param_1[param_2 * 6 + 0x28] = param_1[param_3 * 6 + 0x28];
  param_1[param_3 * 6 + 0x23] = iVar1;
  param_1[param_3 * 6 + 0x24] = iVar2;
  param_1[param_3 * 6 + 0x25] = iVar3;
  param_1[param_3 * 6 + 0x26] = iVar4;
  param_1[param_3 * 6 + 0x27] = iVar5;
  param_1[param_3 * 6 + 0x28] = iVar6;
  iVar1 = param_1[param_2 + 0x41];
  param_1[param_2 + 0x41] = param_1[param_3 + 0x41];
  param_1[param_3 + 0x41] = iVar1;
  return;
}

/* FUN_0010ff54 @ 0x10ff54 (141 bytes) */
int FUN_0010ff54(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  uVar2 = *(undefined4 *)(param_2 + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar2,0x168);
  *puVar3 = uVar2;
  puVar1 = puVar3 + 1;
  FUN_0010ac30(puVar1,0x8c,param_2);
  iVar4 = FUN_0010b0f4(puVar1,1);
  *(undefined4 *)(iVar4 + 8) = param_1;
  *(undefined4 *)(iVar4 + 0xc) = 0;
  iVar4 = FUN_0010b0f4(puVar1,1);
  *(undefined4 *)(iVar4 + 0x10) = DAT_001cbe80;
  puVar3[0x4c] = 0;
  return puVar1;
}

/* FUN_00110000 @ 0x110000 (226 bytes) */
int FUN_00110000(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  FUN_00109d1c(param_1,&local_18,0xffffffff);
  uVar1 = *(undefined4 *)(param_1 + 4);
  uVar2 = *(undefined4 *)(param_1 + 0x158);
  iVar3 = FUN_00109e42(param_1,param_3);
  FUN_001a7d72(param_1);
  FUN_00109d86(param_1,param_2);
  FUN_00109d48(param_1,&local_18);
  *(int *)(param_1 + 0x160) = iVar3 + *(int *)(param_3 + 0x46c);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x14c);
  *(undefined4 *)(param_1 + 0x98) = 0;
  FUN_000e9596(uVar2,uVar1,param_1);
  (**(code **)(*param_2 + 0xc))(param_2,0,*(undefined4 *)(param_3 + 8));
  return;
}

/* FUN_001100e2 @ 0x1100e2 (46 bytes) */
float FUN_001100e2(int param_1,float param_2)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)((int (*)())FUN_0010fd78)(*(undefined4 *)(param_1 + 0x124));
  return (float)lVar1 * param_2;
}

/* FUN_00110110 @ 0x110110 (460 bytes) */
int FUN_00110110(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int local_14;
  
  cVar3 = (**(code **)(*param_1 + 0x5c))(param_1);
  if (cVar3 == '\0') {
    return param_1;
  }
  piVar4 = (int *)FUN_0010a1c2(param_1,*(undefined4 *)(param_2 + 8),0);
  iVar6 = piVar4[0x53];
  iVar5 = FUN_0010b0f4(piVar4,0);
  *(int *)(iVar5 + 8) = iVar6;
  FUN_000e956e(param_1[0x56],param_1,piVar4);
  piVar4[0x58] = *(int *)(param_2 + 0x46c);
  if (param_3 != '\0') {
    uVar9 = *(undefined4 *)(*(int *)(param_2 + 8) + 0xbc);
    puVar8 = (undefined4 *)FUN_001a7bca(uVar9,0x14);
    *puVar8 = uVar9;
    puVar8[4] = uVar9;
    puVar8[2] = 0;
    puVar8[1] = 2;
    uVar9 = FUN_001a7bca(uVar9,8);
    puVar8[3] = uVar9;
    piVar4[4] = (int)(puVar8 + 1);
    local_14 = 1;
    while( true ) {
      iVar6 = (**(code **)(*piVar4 + 0x14))(piVar4);
      if (iVar6 < local_14) break;
      iVar6 = FUN_0010b180(piVar4,local_14);
      puVar1 = *(uint **)(iVar6 + 0x10);
      uVar2 = puVar1[1];
      if (uVar2 < *puVar1) {
        _memset((void *)(uVar2 * 4 + puVar1[2]),0,4);
        puVar1[1] = uVar2 + 1;
        puVar8 = (undefined4 *)(uVar2 * 4 + puVar1[2]);
      }
      else {
        puVar8 = (undefined4 *)FUN_001a7f7c(puVar1,uVar2);
      }
      *puVar8 = piVar4;
      local_14 = local_14 + 1;
    }
  }
  iVar5 = 1;
  iVar6 = (**(code **)(*piVar4 + 0x14))(piVar4);
  if (0 < iVar6) {
    do {
      iVar6 = *(int *)(param_2 + 0x46c);
      iVar7 = FUN_0010b180(piVar4,iVar5);
      if (iVar6 < *(int *)(iVar7 + 0x160)) {
        *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + 1;
      }
      else {
        *(int *)(iVar7 + 0x160) = iVar6 + 1;
      }
      iVar5 = iVar5 + 1;
      iVar6 = (**(code **)(*piVar4 + 0x14))(piVar4);
    } while (iVar5 <= iVar6);
  }
  return piVar4;
}

/* FUN_001102fa @ 0x1102fa (103 bytes) */
float FUN_001102fa(int param_1,float param_2)

{
  float fVar1;
  
  fVar1 = param_2;
  if ((*(char *)(param_1 + 0x120) != '\0') && (fVar1 = FLOAT_001c5ba4, param_2 <= FLOAT_001c5ba4)) {
    return (float)((uint)param_2 & -(uint)(0.0 <= param_2));
  }
  return fVar1;
}

/* FUN_00110362 @ 0x110362 (204 bytes) */
int FUN_00110362(int *param_1,float param_2,int *param_3)

{
  float *pfVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_10;
  
  (**(code **)(*param_1 + 0x60))(param_1);
  local_10 = 0;
  do {
    iVar3 = FUN_0010b0f4(param_1,0);
    if (*(char *)(local_10 + 0x10 + iVar3) != '\x01') {
      iVar5 = 1;
      iVar3 = (**(code **)(*param_1 + 0x14))(param_1);
      if (0 < iVar3) {
        do {
          iVar3 = FUN_0010b180(param_1,iVar5);
          if (*(int *)(iVar3 + 0x98) == 0x33) {
            iVar4 = FUN_0010b0f4(param_1,iVar5);
            bVar2 = *(byte *)(local_10 + 0x10 + iVar4);
            if (((bVar2 != 4) &&
                (pfVar1 = (float *)(iVar3 + 0x20 + (uint)bVar2 * 0x18), param_2 == *pfVar1)) &&
               (!NAN(param_2) && !NAN(*pfVar1))) {
              *param_3 = local_10;
              return iVar5;
            }
          }
          iVar5 = iVar5 + 1;
          iVar3 = (**(code **)(*param_1 + 0x14))(param_1);
        } while (iVar5 <= iVar3);
      }
    }
    local_10 = local_10 + 1;
    if (local_10 == 4) {
      return 0;
    }
  } while( true );
}

/* FUN_0011042e @ 0x11042e (95 bytes) */
float FUN_0011042e(int param_1,int param_2,float param_3)

{
  if ((*(byte *)(param_1 + 0xa0 + param_2 * 0x18) & 1) != 0) {
    if ((param_3 != 0.0) || (NAN(param_3))) {
      return (float)((uint)param_3 ^ _DAT_001cbeb0);
    }
    param_3 = 0.0;
  }
  return param_3;
}

/* FUN_0011048e @ 0x11048e (87 bytes) */
float FUN_0011048e(int param_1,int param_2,float param_3)

{
  if ((*(byte *)(param_1 + 0xa0 + param_2 * 0x18) & 2) != 0) {
    if ((param_3 < FLOAT_001c5b9c) && (!NAN(param_3) && !NAN(FLOAT_001c5b9c))) {
      return (float)((uint)param_3 ^ _DAT_001cbec0);
    }
  }
  return param_3;
}

/* FUN_001104e6 @ 0x1104e6 (303 bytes) */
int FUN_001104e6(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 uVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  switch(param_1) {
  case 0:
    uVar3 = 0x2a;
    bVar2 = false;
    break;
  case 1:
    uVar3 = 0x27;
    bVar2 = false;
    break;
  case 2:
    uVar3 = 0x29;
    bVar2 = true;
    break;
  case 3:
    uVar3 = 0x28;
    bVar2 = true;
    break;
  case 4:
    uVar3 = 0x29;
    bVar2 = false;
    break;
  case 5:
    uVar3 = 0x28;
    bVar2 = false;
    break;
  default:
    uVar3 = 0;
    bVar2 = false;
  }
  uVar1 = *(undefined4 *)(param_5 + 0x3f4);
  iVar4 = FUN_0010a17a(uVar3,param_5);
  iVar5 = FUN_0010b0f4(iVar4,2 - (uint)!bVar2);
  *(undefined4 *)(iVar5 + 8) = param_2;
  *(undefined4 *)(iVar5 + 0xc) = param_3;
  FUN_000fa0d2(iVar4,uVar1,((int)((uint)bVar2 << 0x1f) >> 0x1f) + 2,param_4,param_4,param_4,param_4)
  ;
  iVar6 = *(int *)(param_5 + 0xf0) + -1;
  *(int *)(param_5 + 0xf0) = iVar6;
  iVar5 = FUN_0010b0f4(iVar4,0);
  *(int *)(iVar5 + 8) = iVar6;
  *(undefined4 *)(iVar5 + 0xc) = 0;
  *(undefined4 *)(iVar4 + 0x9c) = DAT_001cbe84;
  return iVar4;
}

/* FUN_0011062e @ 0x11062e (286 bytes) */
int FUN_0011062e(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  char cVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int local_20;
  
  local_20 = 0;
  while (iVar2 = FUN_0010b0f4(param_1,0), *(char *)(local_20 + 0x10 + iVar2) == '\x01') {
LAB_0011070e:
    local_20 = local_20 + 1;
    if (local_20 == 4) {
      return 1;
    }
  }
  iVar2 = FUN_0010b0f4(param_1,param_2);
  uVar4 = (uint)*(byte *)(local_20 + 0x10 + iVar2);
  piVar3 = (int *)FUN_0010b180(param_1,param_2);
  do {
    cVar1 = (**(code **)(*piVar3 + 100))(piVar3);
    while( true ) {
      if (cVar1 == '\0') {
        cVar1 = (**(code **)(*piVar3 + 0x48))(piVar3);
        if ((((cVar1 == '\0') || (((int)(char)piVar3[0x57] >> ((byte)uVar4 & 0x1f) & 1U) == 0)) ||
            ((float)piVar3[uVar4 * 6 + 8] != 0.0)) || (NAN((float)piVar3[uVar4 * 6 + 8]))) {
          return 0;
        }
        goto LAB_0011070e;
      }
      iVar2 = FUN_0010b0f4(piVar3,0);
      if (*(char *)(uVar4 + 0x10 + iVar2) != '\0') break;
      iVar2 = FUN_0010b0f4(piVar3,1);
      uVar4 = (uint)*(byte *)(uVar4 + 0x10 + iVar2);
      piVar3 = (int *)FUN_0010b180(piVar3,1);
      cVar1 = (**(code **)(*piVar3 + 100))(piVar3);
    }
    piVar3 = (int *)FUN_0010b180(piVar3,piVar3[0x21]);
  } while( true );
}

