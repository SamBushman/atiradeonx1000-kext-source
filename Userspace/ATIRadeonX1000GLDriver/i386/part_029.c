#include "decls.h"

/* FUN_0010d372 @ 0x10d372 (69 bytes) */
int FUN_0010d372(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  FUN_0010d31a(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010d3d6 @ 0x10d3d6 (88 bytes) */
int FUN_0010d3d6(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010d2d8(param_1,param_2,param_3);
  *param_1 = PTR_DAT_002134e1 + 8;
  param_1[0x20] = 0;
  param_1[0x27] = DAT_001cbe74;
  param_1[0x21] = 0;
  return;
}

/* FUN_0010d42e @ 0x10d42e (66 bytes) */
int FUN_0010d42e(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010cadc(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213525 + 8;
  param_1[0x21] = 0;
  return;
}

/* FUN_0010d470 @ 0x10d470 (69 bytes) */
int FUN_0010d470(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010d42e)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010d4d4 @ 0x10d4d4 (69 bytes) */
int FUN_0010d4d4(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010d42e)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010d538 @ 0x10d538 (66 bytes) */
int FUN_0010d538(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010cadc(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213561 + 8;
  param_1[0x21] = 1;
  return;
}

/* FUN_0010d57a @ 0x10d57a (101 bytes) */
int FUN_0010d57a(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  
  ((int (*)())FUN_0010d538)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_002134e9 + 8;
  param_1[0x20] = 1;
  iVar1 = 2;
  do {
    param_1[0x25] = 0xffffffff;
    param_1[0x26] = 0;
    param_1 = param_1 + 6;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

/* FUN_0010d5e0 @ 0x10d5e0 (66 bytes) */
int FUN_0010d5e0(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010cadc(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213561 + 8;
  param_1[0x21] = 1;
  return;
}

/* FUN_0010d622 @ 0x10d622 (69 bytes) */
int FUN_0010d622(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010d5e0)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010d686 @ 0x10d686 (69 bytes) */
int FUN_0010d686(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010d5e0)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010d6ea @ 0x10d6ea (66 bytes) */
int FUN_0010d6ea(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010cadc(param_1,param_2,param_3);
  *param_1 = PTR_DAT_002134e5 + 8;
  param_1[0x21] = 2;
  return;
}

/* FUN_0010d72c @ 0x10d72c (100 bytes) */
int FUN_0010d72c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  ((int (*)())FUN_0010d6ea)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213529 + 8;
  param_1[0x20] = 1;
  param_1[0x4b] = 0;
  param_1[5] = param_1[5] | 0x18;
  FUN_000f0b74(*(undefined4 *)(param_3 + 0x3f4),param_1);
  return;
}

/* FUN_0010d7ac @ 0x10d7ac (91 bytes) */
int FUN_0010d7ac(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  ((int (*)())FUN_0010d6ea)(param_1,0x8b,param_3);
  *param_1 = PTR_DAT_002134dd + 8;
  param_1[0x20] = 0;
  param_1[5] = param_1[5] | 0x18;
  FUN_000f0b74(*(undefined4 *)(param_3 + 0x3f4),param_1);
  return;
}

/* FUN_0010d822 @ 0x10d822 (69 bytes) */
int FUN_0010d822(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010d7ac)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010d886 @ 0x10d886 (91 bytes) */
int FUN_0010d886(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  ((int (*)())FUN_0010d6ea)(param_1,0x8b,param_3);
  *param_1 = PTR_DAT_002134dd + 8;
  param_1[0x20] = 0;
  param_1[5] = param_1[5] | 0x18;
  FUN_000f0b74(*(undefined4 *)(param_3 + 0x3f4),param_1);
  return;
}

/* FUN_0010d8fc @ 0x10d8fc (66 bytes) */
int FUN_0010d8fc(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010cadc(param_1,param_2,param_3);
  *param_1 = PTR_DAT_002134e5 + 8;
  param_1[0x21] = 2;
  return;
}

/* FUN_0010d93e @ 0x10d93e (69 bytes) */
int FUN_0010d93e(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010d8fc)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010d9a2 @ 0x10d9a2 (69 bytes) */
int FUN_0010d9a2(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010d8fc)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010da06 @ 0x10da06 (66 bytes) */
int FUN_0010da06(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010cadc(param_1,param_2,param_3);
  *param_1 = PTR_DAT_0021351d + 8;
  param_1[0x21] = 3;
  return;
}

/* FUN_0010da48 @ 0x10da48 (66 bytes) */
int FUN_0010da48(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010cadc(param_1,param_2,param_3);
  *param_1 = PTR_DAT_0021351d + 8;
  param_1[0x21] = 3;
  return;
}

/* FUN_0010da8a @ 0x10da8a (69 bytes) */
int FUN_0010da8a(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010da48)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010daee @ 0x10daee (69 bytes) */
int FUN_0010daee(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010da48)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010db52 @ 0x10db52 (101 bytes) */
int FUN_0010db52(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  
  ((int (*)())FUN_0010d538)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_002134e9 + 8;
  param_1[0x20] = 1;
  iVar1 = 2;
  do {
    param_1[0x25] = 0xffffffff;
    param_1[0x26] = 0;
    param_1 = param_1 + 6;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

/* FUN_0010dbb8 @ 0x10dbb8 (69 bytes) */
int FUN_0010dbb8(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010db52)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010dc1c @ 0x10dc1c (69 bytes) */
int FUN_0010dc1c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010db52)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010dc80 @ 0x10dc80 (303 bytes) */
int FUN_0010dc80(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 uVar1;
  
  FUN_0010cadc(param_1,0x30,param_2);
  *param_1 = &PTR_FUN_001fc768;
  param_1[5] = param_1[5] | 0x12;
  if ((*(byte *)(*(int *)(param_2 + 0x3f4) + 0x31) & 0x40) == 0) {
    FUN_000f0b74(*(int *)(param_2 + 0x3f4),param_1);
  }
  uVar1 = (**(code **)(**(int **)(param_2 + 0x54) + 0x178))(*(int **)(param_2 + 0x54),param_2);
  uVar1 = FUN_00118f66(uVar1);
  param_1[0x22] = uVar1;
  param_1[0x21] = 1;
  param_1[0x20] = 0;
  param_1[0x27] = DAT_001cbe74;
  param_1[0x4f] = 0x32;
  param_1[0x50] = 0;
  FUN_00109ed6(param_1,0,5,0);
  FUN_00109ed6(param_1,1,5,0);
  FUN_00109ed6(param_1,2,5,0);
  FUN_00109ed6(param_1,3,5,0);
  *(undefined1 *)(param_1 + 0x51) = 0;
  return;
}

/* FUN_0010ddca @ 0x10ddca (86 bytes) */
int FUN_0010ddca(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  
  ((int (*)())FUN_0010dc80)(param_1,param_3);
  *param_1 = PTR_DAT_002134f5 + 8;
  param_1[0x20] = 1;
  param_1[0x21] = 1;
  uVar1 = FUN_00118f66(param_2);
  param_1[0x22] = uVar1;
  return;
}

/* FUN_0010de3c @ 0x10de3c (87 bytes) */
int FUN_0010de3c(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  
  ((int (*)())FUN_0010dc80)(param_1,param_2);
  *param_1 = PTR_DAT_002134f5 + 8;
  param_1[0x20] = 1;
  param_1[0x21] = 1;
  uVar1 = FUN_00118f66(0xf9);
  param_1[0x22] = uVar1;
  return;
}

/* FUN_0010deae @ 0x10deae (87 bytes) */
int FUN_0010deae(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  
  ((int (*)())FUN_0010dc80)(param_1,param_2);
  *param_1 = PTR_DAT_002134f5 + 8;
  param_1[0x20] = 1;
  param_1[0x21] = 1;
  uVar1 = FUN_00118f66(0xf9);
  param_1[0x22] = uVar1;
  return;
}

/* FUN_0010df20 @ 0x10df20 (69 bytes) */
int FUN_0010df20(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_0010dc80)(param_1,param_2);
  *param_1 = PTR_DAT_00213521 + 8;
  param_1[0x26] = 0x16;
  param_1[0x21] = 2;
  return;
}

/* FUN_0010df66 @ 0x10df66 (69 bytes) */
int FUN_0010df66(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_0010dc80)(param_1,param_2);
  *param_1 = PTR_DAT_00213521 + 8;
  param_1[0x26] = 0x16;
  param_1[0x21] = 2;
  return;
}

/* FUN_0010dfac @ 0x10dfac (303 bytes) */
int FUN_0010dfac(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 uVar1;
  
  FUN_0010cadc(param_1,0x30,param_2);
  *param_1 = &PTR_FUN_001fc768;
  param_1[5] = param_1[5] | 0x12;
  if ((*(byte *)(*(int *)(param_2 + 0x3f4) + 0x31) & 0x40) == 0) {
    FUN_000f0b74(*(int *)(param_2 + 0x3f4),param_1);
  }
  uVar1 = (**(code **)(**(int **)(param_2 + 0x54) + 0x178))(*(int **)(param_2 + 0x54),param_2);
  uVar1 = FUN_00118f66(uVar1);
  param_1[0x22] = uVar1;
  param_1[0x21] = 1;
  param_1[0x20] = 0;
  param_1[0x27] = DAT_001cbe74;
  param_1[0x4f] = 0x32;
  param_1[0x50] = 0;
  FUN_00109ed6(param_1,0,5,0);
  FUN_00109ed6(param_1,1,5,0);
  FUN_00109ed6(param_1,2,5,0);
  FUN_00109ed6(param_1,3,5,0);
  *(undefined1 *)(param_1 + 0x51) = 0;
  return;
}

/* FUN_0010e0f6 @ 0x10e0f6 (86 bytes) */
int FUN_0010e0f6(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  
  ((int (*)())FUN_0010dc80)(param_1,param_3);
  *param_1 = PTR_DAT_002134f5 + 8;
  param_1[0x20] = 1;
  param_1[0x21] = 1;
  uVar1 = FUN_00118f66(param_2);
  param_1[0x22] = uVar1;
  return;
}

/* FUN_0010e168 @ 0x10e168 (69 bytes) */
int FUN_0010e168(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010e0f6)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010e1cc @ 0x10e1cc (100 bytes) */
int FUN_0010e1cc(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  ((int (*)())FUN_0010d6ea)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213529 + 8;
  param_1[0x20] = 1;
  param_1[0x4b] = 0;
  param_1[5] = param_1[5] | 0x18;
  FUN_000f0b74(*(undefined4 *)(param_3 + 0x3f4),param_1);
  return;
}

/* FUN_0010e24c @ 0x10e24c (69 bytes) */
int FUN_0010e24c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010e1cc)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010e2b0 @ 0x10e2b0 (67 bytes) */
int FUN_0010e2b0(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  FUN_0010ca48(param_1,0x86,param_2);
  *param_1 = PTR_DAT_002134ed + 8;
  param_1[0x4b] = 0;
  return;
}

/* FUN_0010e2f4 @ 0x10e2f4 (67 bytes) */
int FUN_0010e2f4(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  FUN_0010ca48(param_1,0x86,param_2);
  *param_1 = PTR_DAT_002134ed + 8;
  param_1[0x4b] = 0;
  return;
}

/* FUN_0010e338 @ 0x10e338 (57 bytes) */
int FUN_0010e338(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  FUN_0010ca48(param_1,0x87,param_2);
  *param_1 = PTR_DAT_0021353d + 8;
  return;
}

/* FUN_0010e372 @ 0x10e372 (57 bytes) */
int FUN_0010e372(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  FUN_0010ca48(param_1,0x87,param_2);
  *param_1 = PTR_DAT_0021353d + 8;
  return;
}

/* FUN_0010e3ac @ 0x10e3ac (57 bytes) */
int FUN_0010e3ac(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  FUN_0010ca48(param_1,0x88,param_2);
  *param_1 = PTR_DAT_00213555 + 8;
  return;
}

/* FUN_0010e3e6 @ 0x10e3e6 (57 bytes) */
int FUN_0010e3e6(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  FUN_0010ca48(param_1,0x88,param_2);
  *param_1 = PTR_DAT_00213555 + 8;
  return;
}

/* FUN_0010e420 @ 0x10e420 (66 bytes) */
int FUN_0010e420(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0010ca48(param_1,param_2,param_3);
  *param_1 = PTR_DAT_0021354d + 8;
  param_1[0x20] = 1;
  return;
}

/* FUN_0010e462 @ 0x10e462 (76 bytes) */
int FUN_0010e462(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010e420)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_0021350d + 8;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  return;
}

/* FUN_0010e4ae @ 0x10e4ae (69 bytes) */
int FUN_0010e4ae(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010e462)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010e512 @ 0x10e512 (76 bytes) */
int FUN_0010e512(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010e420)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_0021350d + 8;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  return;
}

/* FUN_0010e55e @ 0x10e55e (77 bytes) */
int FUN_0010e55e(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_0010e420)(param_1,0x85,param_2);
  *param_1 = PTR_DAT_0021350d + 8;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  return;
}

/* FUN_0010e5ac @ 0x10e5ac (77 bytes) */
int FUN_0010e5ac(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_0010e420)(param_1,0x85,param_2);
  *param_1 = PTR_DAT_0021350d + 8;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  return;
}

/* FUN_0010e5fa @ 0x10e5fa (57 bytes) */
int FUN_0010e5fa(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_0010e420)(param_1,0x79,param_2);
  *param_1 = PTR_DAT_002134f1 + 8;
  return;
}

/* FUN_0010e634 @ 0x10e634 (57 bytes) */
int FUN_0010e634(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_0010e420)(param_1,0x79,param_2);
  *param_1 = PTR_DAT_002134f1 + 8;
  return;
}

/* FUN_0010e66e @ 0x10e66e (57 bytes) */
int FUN_0010e66e(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_0010e420)(param_1,0xfa,param_2);
  *param_1 = PTR_DAT_0021352d + 8;
  return;
}

/* FUN_0010e6a8 @ 0x10e6a8 (57 bytes) */
int FUN_0010e6a8(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_0010e420)(param_1,0xfa,param_2);
  *param_1 = PTR_DAT_0021352d + 8;
  return;
}

/* FUN_0010e6e2 @ 0x10e6e2 (281 bytes) */
int FUN_0010e6e2(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_0010e420)(param_1,0x7e,param_2);
  *param_1 = PTR_DAT_00213535 + 8;
  param_1[5] = param_1[5] | 0x40;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  param_1[0x50] = 0;
  param_1[0x4f] = 0;
  param_1[0x51] = 0x32;
  param_1[0x52] = 0;
  FUN_00109fa4(param_1,0,0,5,0);
  FUN_00109fa4(param_1,1,0,5,0);
  FUN_00109fa4(param_1,2,0,5,0);
  FUN_00109fa4(param_1,3,0,5,0);
  return;
}

/* FUN_0010e7fc @ 0x10e7fc (281 bytes) */
int FUN_0010e7fc(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_0010e420)(param_1,0x7e,param_2);
  *param_1 = PTR_DAT_00213535 + 8;
  param_1[5] = param_1[5] | 0x40;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  param_1[0x50] = 0;
  param_1[0x4f] = 0;
  param_1[0x51] = 0x32;
  param_1[0x52] = 0;
  FUN_00109fa4(param_1,0,0,5,0);
  FUN_00109fa4(param_1,1,0,5,0);
  FUN_00109fa4(param_1,2,0,5,0);
  FUN_00109fa4(param_1,3,0,5,0);
  return;
}

/* FUN_0010e916 @ 0x10e916 (106 bytes) */
int FUN_0010e916(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010e420)(param_1,0x7a,param_3);
  *param_1 = PTR_DAT_00213519 + 8;
  param_1[0x20] = 1;
  param_1[0x26] = *(undefined4 *)(param_2 + 4);
  param_1[0x25] = *(undefined4 *)(param_2 + 8);
  param_1[0x23] = param_2;
  param_1[0x21] = 0;
  return;
}

/* FUN_0010e980 @ 0x10e980 (106 bytes) */
int FUN_0010e980(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010e420)(param_1,0x7a,param_3);
  *param_1 = PTR_DAT_00213519 + 8;
  param_1[0x20] = 1;
  param_1[0x26] = *(undefined4 *)(param_2 + 4);
  param_1[0x25] = *(undefined4 *)(param_2 + 8);
  param_1[0x23] = param_2;
  param_1[0x21] = 0;
  return;
}

/* FUN_0010e9ea @ 0x10e9ea (86 bytes) */
int FUN_0010e9ea(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010e420)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213519 + 8;
  param_1[0x26] = 0;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  return;
}

/* FUN_0010ea40 @ 0x10ea40 (69 bytes) */
int FUN_0010ea40(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  ((int (*)())FUN_0010e9ea)(puVar2 + 1,param_1,param_2);
  return puVar2 + 1;
}

/* FUN_0010eaa4 @ 0x10eaa4 (86 bytes) */
int FUN_0010eaa4(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_0010e420)(param_1,param_2,param_3);
  *param_1 = PTR_DAT_00213519 + 8;
  param_1[0x26] = 0;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  return;
}

/* FUN_0010eafa @ 0x10eafa (87 bytes) */
int FUN_0010eafa(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_0010e420)(param_1,0x7a,param_2);
  *param_1 = PTR_DAT_00213519 + 8;
  param_1[0x26] = 0;
  param_1[0x20] = 1;
  param_1[0x21] = 0;
  return;
}

