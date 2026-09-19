#include "decls.h"

/* FUN_001ae176 @ 0x1ae176 (137 bytes) */
int FUN_001ae176(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10;
  
  **(undefined4 **)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x5c);
  if (*(int *)(param_1 + 0x5c) < 1) {
    return;
  }
  local_14 = 0;
  local_10 = 0;
  local_18 = 0;
  do {
    iVar2 = local_18 + *(int *)(param_1 + 0x54);
    puVar1 = (undefined4 *)(local_10 + *(int *)(param_1 + 0x40));
    *(undefined4 *)(iVar2 + 4) = *puVar1;
    *(undefined4 *)(iVar2 + 8) = puVar1[1];
    *(undefined4 *)(iVar2 + 0xc) = puVar1[2];
    *(undefined4 *)(iVar2 + 0x10) = puVar1[3];
    *(undefined4 *)(iVar2 + 0x14) = puVar1[4];
    *(undefined4 *)(iVar2 + 0x18) = puVar1[5];
    *(undefined4 *)(iVar2 + 0x1c) = puVar1[6];
    local_14 = local_14 + 1;
    local_18 = local_18 + 0x1c;
    local_10 = local_10 + 0x1c;
  } while (local_14 < *(int *)(param_1 + 0x5c));
  return;
}

/* FUN_001ae200 @ 0x1ae200 (5 bytes) */
int FUN_001ae200()
{
  return;
}

/* FUN_001ae206 @ 0x1ae206 (5 bytes) */
int FUN_001ae206()
{
  return;
}

/* FUN_001ae20c @ 0x1ae20c (44 bytes) */
int FUN_001ae20c(param_1)
  int param_1;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(int *)(param_1 + 0x58) * 0x10 + *(int *)(param_1 + 0x44));
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  return;
}

/* FUN_001ae238 @ 0x1ae238 (49 bytes) */
int FUN_001ae238(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(uint *)(PTR_DAT_00213a39 + *(int *)(*(int *)(param_2 + 0x88) + 8) * 0x38) >> 2 & 1;
}

/* FUN_001ae26a @ 0x1ae26a (120 bytes) */
int FUN_001ae26a(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2 * 5 + *(int *)(param_1 + 0x1c);
  iVar2 = *(int *)(&DAT_001f95e0 + iVar1 * 4);
  iVar1 = *(int *)(&DAT_001f9560 + iVar1 * 4);
  *(int *)(param_1 + 0x1c) = iVar1;
  if (iVar1 != -1) {
    if (iVar2 < 1) {
      if (iVar2 < 0) {
        iVar1 = *(int *)(param_1 + 0x58);
        do {
          iVar1 = iVar1 + -1;
          iVar2 = iVar2 + 1;
        } while (iVar2 != 0);
        *(int *)(param_1 + 0x58) = iVar1;
      }
    }
    else {
      iVar1 = 0;
      do {
        FUN_001ae092(param_1);
        iVar1 = iVar1 + 1;
      } while (iVar1 != iVar2);
    }
    return;
  }
  *(undefined4 *)(param_1 + 0x1c) = 2;
  return;
}

/* FUN_001ae2e2 @ 0x1ae2e2 (95 bytes) */
int FUN_001ae2e2(param_1)
  int param_1;
{
  FUN_000e1c3e(*(int *)(param_1 + 0xc),"next_sp = %d, max = %d\n",*(undefined4 *)(param_1 + 0x58),
               *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 0x54) + 0x40));
  if ((*(int *)(param_1 + 0x58) <= *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x54) + 0x40)) &&
     (*(int *)(param_1 + 0x5c) < 0x11)) {
    return 0;
  }
  return 1;
}

/* FUN_001ae342 @ 0x1ae342 (12 bytes) */
int FUN_001ae342(param_1)
  int param_1;
{
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  return;
}

/* FUN_001ae34e @ 0x1ae34e (55 bytes) */
int FUN_001ae34e(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  FUN_000e41ae(param_2,param_1,param_1[3]);
                    
                    
  (**(code **)(*param_1 + 0x88))();
  return;
}

/* FUN_001ae386 @ 0x1ae386 (153 bytes) */
int FUN_001ae386(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined1 *param_3;
{
  float fVar1;
  
  *param_3 = 0;
  if (3 < param_2) {
    if (param_2 < 6) {
      return 4;
    }
    if (param_2 == 6) {
      return 5;
    }
  }
  fVar1 = *(float *)(param_1 + param_2 * 0x18 + 0x20);
  if (fVar1 == FLOAT_001c5ba4) {
    return 5;
  }
  if (fVar1 != FLOAT_001c5b9c) {
    if ((fVar1 == FLOAT_001c5bdc) && (!NAN(fVar1) && !NAN(FLOAT_001c5bdc))) {
      *param_3 = 1;
      return 5;
    }
  }
  return 4;
}

/* FUN_001ae420 @ 0x1ae420 (90 bytes) */
int FUN_001ae420(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  dword *pdVar1;
  
  if (param_2 == 2) {
    pdVar1 = (dword *)(param_1 + 8);
  }
  else if (param_2 == 3) {
    pdVar1 = (dword *)(param_1 + 0xc);
  }
  else if (param_2 == 1) {
    pdVar1 = (dword *)(param_1 + 4);
  }
  else {
    pdVar1 = (dword *)0x0;
  }
  if (param_3 == 2) {
    *(dword *)(param_1 + 8) = *pdVar1;
    return;
  }
  if (param_3 == 3) {
    *(dword *)(param_1 + 0xc) = *pdVar1;
    return;
  }
  if (param_3 != 1) {
    MACH_HEADER.magic = *pdVar1;
    return;
  }
  *(dword *)(param_1 + 4) = *pdVar1;
  return;
}

/* FUN_001ae47a @ 0x1ae47a (101 bytes) */
int FUN_001ae47a(param_1, param_2)
  int *param_1;
  int param_2;
{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_0010b180(param_2,1);
  cVar1 = (**(code **)(*piVar2 + 0x50))(piVar2);
  if ((cVar1 != '\0') && (*(char *)(param_2 + 0x144) != '\0')) {
    return;
  }
                    
                    
  (**(code **)(*param_1 + 0x38))();
  return;
}

/* FUN_001ae4e0 @ 0x1ae4e0 (5 bytes) */
int FUN_001ae4e0()
{
  return;
}

/* FUN_001ae4e6 @ 0x1ae4e6 (14 bytes) */
int FUN_001ae4e6(param_1)
  int *param_1;
{
                    
                    
  (**(code **)(*param_1 + 0x38))();
  return;
}

/* FUN_001ae4f4 @ 0x1ae4f4 (14 bytes) */
int FUN_001ae4f4(param_1)
  int *param_1;
{
                    
                    
  (**(code **)(*param_1 + 0x38))();
  return;
}

/* FUN_001ae508 @ 0x1ae508 (5 bytes) */
int FUN_001ae508()
{
  return;
}

/* FUN_001ae50e @ 0x1ae50e (91 bytes) */
int FUN_001ae50e(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if ((1 < *(int *)(param_2 + 0x130)) && (*(int *)(param_1 + 0x5c) != 0x10)) {
    iVar1 = *(int *)(param_2 + 300);
    *(int *)(param_1 + 0x70) = iVar1;
    *(undefined4 *)(*(int *)(param_1 + 0x60) + iVar1 * 0xc) = *(undefined4 *)(param_1 + 0x58);
    *(undefined4 *)(*(int *)(param_1 + 0x60) + 8 + *(int *)(param_1 + 0x70) * 0xc) =
         *(undefined4 *)(param_1 + 0x1c);
    ((int (*)())FUN_001ae26a)(param_1,3);
    *(undefined1 *)(param_1 + 100) = 1;
  }
  return;
}

/* FUN_001ae56a @ 0x1ae56a (58 bytes) */
int FUN_001ae56a(param_1)
  int param_1;
{
  if (*(char *)(param_1 + 100) != '\0') {
    ((int (*)())FUN_001ae26a)(param_1,3);
    *(undefined4 *)(*(int *)(param_1 + 0x60) + 4 + *(int *)(param_1 + 0x70) * 0xc) =
         *(undefined4 *)(param_1 + 0x58);
    *(undefined1 *)(param_1 + 100) = 1;
  }
  return;
}

/* FUN_001ae5a4 @ 0x1ae5a4 (54 bytes) */
int FUN_001ae5a4(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x5c) * 0x1c + *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
  *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(iVar1 + 0x14) = param_2;
  *(undefined4 *)(iVar1 + 0x18) = param_3;
  return;
}

/* FUN_001ae5da @ 0x1ae5da (120 bytes) */
int FUN_001ae5da(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 *puVar1;
  int iVar2;
  
  if ((1 < *(int *)(param_2 + 0x130)) && (*(int *)(param_1 + 0x5c) != 0x10)) {
    *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 0x58);
    *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0x1c);
    iVar2 = *(int *)(param_2 + 300);
    *(int *)(param_1 + 0x70) = iVar2;
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(*(int *)(param_1 + 0x60) + iVar2 * 0xc);
    ((int (*)())FUN_001ae26a)(param_1,4);
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0x60) + *(int *)(param_1 + 0x70) * 0xc);
    ((int (*)())FUN_001ae5a4)(param_1,*puVar1,puVar1[1]);
    *(undefined1 *)(param_1 + 100) = 1;
  }
  return;
}

/* FUN_001ae652 @ 0x1ae652 (61 bytes) */
int FUN_001ae652(param_1)
  int param_1;
{
  if (*(char *)(param_1 + 100) != '\0') {
    ((int (*)())FUN_001ae26a)(param_1,3);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x68);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x6c);
    *(undefined1 *)(param_1 + 100) = 0;
    *(undefined4 *)(param_1 + 0x70) = 0xffffffff;
  }
  return;
}

/* FUN_001ae690 @ 0x1ae690 (35 bytes) */
int FUN_001ae690(param_1)
  int *param_1;
{
                    
                    
  (**(code **)(*param_1 + 0x34))();
  return;
}

/* FUN_001ae6b4 @ 0x1ae6b4 (51 bytes) */
int FUN_001ae6b4(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  char cVar1;
  
  cVar1 = (**(code **)(*param_2 + 0x40))(param_2);
  if (cVar1 != '\0') {
    return;
  }
  FUN_000e27ca();
  return;
}

/* FUN_001ae6e8 @ 0x1ae6e8 (5 bytes) */
int FUN_001ae6e8()
{
  return;
}

/* FUN_001ae6ee @ 0x1ae6ee (5 bytes) */
int FUN_001ae6ee()
{
  return;
}

/* FUN_001ae6f4 @ 0x1ae6f4 (51 bytes) */
int FUN_001ae6f4(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  char cVar1;
  
  cVar1 = (**(code **)(*param_2 + 0x40))(param_2);
  if (cVar1 != '\0') {
    return;
  }
  FUN_000e27ca();
  return;
}

/* FUN_001ae728 @ 0x1ae728 (57 bytes) */
int FUN_001ae728(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  char cVar1;
  
  cVar1 = (**(code **)(**(int **)(param_2 + 0x124) + 0x40))(*(int **)(param_2 + 0x124));
  if (cVar1 != '\0') {
    return;
  }
  FUN_000e27ca();
  return;
}

/* FUN_001ae762 @ 0x1ae762 (5 bytes) */
int FUN_001ae762()
{
  return;
}

/* FUN_001ae768 @ 0x1ae768 (107 bytes) */
int FUN_001ae768(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  uint *puVar1;
  
  ((int (*)())FUN_001ae26a)(param_1,4);
  puVar1 = (uint *)(*(int *)(param_1 + 0x5c) * 0x1c + *(int *)(param_1 + 0x40));
  *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
  *puVar1 = (uint)param_2;
  puVar1[2] = 0x35;
  puVar1[3] = param_3;
  puVar1[4] = *(int *)(param_1 + 0x58) - 2;
  puVar1[5] = 0;
  puVar1[6] = 0;
  return;
}

/* FUN_001ae7d4 @ 0x1ae7d4 (5 bytes) */
int FUN_001ae7d4()
{
  return;
}

/* FUN_001ae7da @ 0x1ae7da (5 bytes) */
int FUN_001ae7da()
{
  return;
}

/* FUN_001ae7e0 @ 0x1ae7e0 (5 bytes) */
int FUN_001ae7e0()
{
  return;
}

/* FUN_001ae7e6 @ 0x1ae7e6 (364 bytes) */
int FUN_001ae7e6(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  *(int *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_4 + 0x54);
  iVar1 = *(int *)(param_4 + 0x68) << 4;
  iVar2 = *(int *)(*(int *)(param_4 + 0x54) + 0x40) * 0x10;
  if (iVar2 <= iVar1) {
    iVar2 = iVar1;
  }
  uVar3 = FUN_001a7bca(*(undefined4 *)(param_4 + 0xb8),iVar2);
  *(undefined4 *)(param_1 + 0x44) = uVar3;
  uVar3 = FUN_001a7bca(*(undefined4 *)(param_4 + 0xb8),*(int *)(param_4 + 0x68) * 0x38);
  *(undefined4 *)(param_1 + 0x40) = uVar3;
  uVar3 = FUN_001a7bca(*(undefined4 *)(param_4 + 0xb8),900);
  *(undefined4 *)(param_1 + 0x54) = uVar3;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  uVar3 = FUN_001a7bca(*(undefined4 *)(param_4 + 0xb8),*(int *)(param_4 + 0x68) << 3);
  *(undefined4 *)(param_1 + 8) = uVar3;
  puVar4 = (undefined4 *)FUN_000e2790(param_4,0x28,param_3);
  *(undefined4 **)(param_1 + 0x50) = puVar4;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  **(int **)(param_1 + 0x50) = iVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 4) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 8) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined1 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined1 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined1 *)(param_1 + 0x7c) = 0;
  return;
}

/* FUN_001ae952 @ 0x1ae952 (129 bytes) */
int FUN_001ae952(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 == '\0') {
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x118) = 0;
    return;
  }
  iVar3 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar3 + 0x118) == 0) {
    *(undefined4 *)(iVar3 + 0x118) = 1;
    iVar3 = *(int *)(param_1 + 0xc);
  }
  iVar1 = *(int *)(iVar3 + 0x118);
  FUN_001a7aba(*(undefined4 *)(iVar3 + 0xb8),*(undefined4 *)(param_1 + 0x60));
  uVar2 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xb8),iVar1 * 0xc);
  *(undefined4 *)(param_1 + 0x60) = uVar2;
  return;
}

/* FUN_001ae9d4 @ 0x1ae9d4 (98 bytes) */
int FUN_001ae9d4(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  code *UNRECOVERED_JUMPTABLE;
  
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined1 *)(param_2 + 0xdc));
  UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x9c);
  FUN_000e9a1c(param_2);
                    
                    
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

/* FUN_001aea36 @ 0x1aea36 (64 bytes) */
int FUN_001aea36(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined1 *)(param_2 + 0xdc));
                    
                    
  (**(code **)(*param_1 + 0xa0))();
  return;
}

/* FUN_001aea76 @ 0x1aea76 (205 bytes) */
int FUN_001aea76(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  iVar1 = param_2[0x4c];
  iVar3 = FUN_001a7d8a(iVar1 + 0x90);
  if ((iVar3 < 3) && (cVar2 = FUN_000e97ce(iVar1), cVar2 != '\0')) {
    if (*(int *)(*(int *)(iVar1 + 0xd0) + 4) == 0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = *(int **)(*(int *)(iVar1 + 0xd0) + 8);
    }
    if (*piVar4 == param_2[0x4d]) {
      return;
    }
    cVar2 = (**(code **)(*param_2 + 0x40))(param_2);
  }
  else {
    cVar2 = (**(code **)(*param_2 + 0x40))(param_2);
  }
  if (cVar2 != '\0') {
    iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x24);
    uVar5 = *(int *)(iVar1 + 4) - 1;
    if (uVar5 < *(uint *)(iVar1 + 4)) {
      piVar4 = (int *)(*(int *)(iVar1 + 8) + uVar5 * 4);
    }
    else {
      piVar4 = (int *)0x0;
    }
    iVar1 = *piVar4;
    ((int (*)())FUN_001ae26a)(param_1,4);
    *(int *)(iVar1 + 0x14) = *(int *)(param_1 + 0x58) + -2;
    return;
  }
  FUN_000e27ca();
  return;
}

/* FUN_001aeb44 @ 0x1aeb44 (988 bytes) */
int FUN_001aeb44(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int *param_3;
  undefined1 *param_4;
{
  bool bVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int *local_1c;
  int *local_18;
  int local_10;
  
  *param_4 = 0;
  if (param_3 == (int *)0x0) {
    return (int *)0x0;
  }
  local_18 = (int *)0x0;
  local_1c = (int *)0x0;
  bVar2 = false;
  bVar1 = true;
  piVar10 = param_3;
  do {
    uVar4 = piVar10[5];
    if ((uVar4 & 1) == 0) {
LAB_001aeb8f:
      piVar8 = (int *)piVar10[2];
    }
    else {
      if ((uVar4 & 4) != 0) {
        bVar2 = true;
      }
      cVar3 = ((int (*)())FUN_001ae238)(*(undefined4 *)(param_1 + 0x80),piVar10);
      if (cVar3 != '\0') {
        local_1c = piVar10;
        if (piVar10[0x26] == 1) {
          iVar9 = FUN_0013c4e0(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3f4),piVar10);
          piVar8 = *(int **)(*(int *)(param_1 + 0xc) + 0x54);
          iVar5 = (**(code **)(*piVar8 + 0x138))(piVar8,0);
          if ((uint)(iVar9 - iVar5) < 4) {
            iVar9 = (**(code **)(*piVar10 + 0x14))(piVar10);
            if (1 < iVar9) {
              iVar9 = FUN_0010b180(piVar10,1);
              iVar9 = *(int *)(iVar9 + 0x94);
              iVar5 = FUN_0010b180(piVar10,2);
              if (iVar9 != *(int *)(iVar5 + 0x94)) goto LAB_001aeb85;
            }
            uVar4 = piVar10[5];
            goto LAB_001aeb8f;
          }
        }
LAB_001aeb85:
        bVar1 = false;
        uVar4 = piVar10[5];
        goto LAB_001aeb8f;
      }
      uVar4 = piVar10[5];
      if ((uVar4 & 0x10000) != 0) goto LAB_001aeb8f;
      piVar8 = (int *)piVar10[2];
      local_18 = piVar10;
    }
    piVar10 = piVar8;
  } while ((piVar10 != (int *)0x0) && ((uVar4 & 4) != 0));
  if ((local_18 != (int *)0x0) && (local_1c != (int *)0x0)) {
    if (bVar1) {
      *param_4 = 1;
      return param_3;
    }
    if (bVar2) {
      piVar8 = (int *)(*(int *)(param_1 + 0x10) + 0x14);
      *piVar8 = *piVar8 + 1;
      iVar9 = param_3[0x56];
      piVar10 = (int *)piVar10[1];
      if (piVar10 == local_1c) {
        *(uint *)(local_1c[1] + 0x14) = *(uint *)(local_1c[1] + 0x14) & 0xfffffffb;
      }
      else {
        local_1c[5] = local_1c[5] & 0xfffffffb;
        FUN_001a7d72(local_1c);
        FUN_000e9596(iVar9,piVar10,local_1c);
      }
      iVar11 = 1;
      iVar5 = (**(code **)(*local_1c + 0x14))(local_1c);
      if (0 < iVar5) {
        do {
          iVar5 = local_18[0x26];
          iVar6 = FUN_0010b180(local_1c,iVar11);
          if (iVar5 == *(int *)(iVar6 + 0x98)) {
            iVar5 = FUN_0013c4e0(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3f4),local_18);
            uVar7 = FUN_0010b180(local_1c,iVar11);
            iVar6 = FUN_0013c4e0(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3f4),uVar7);
            if (iVar5 == iVar6) {
              piVar8 = (int *)FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 0xc));
              uVar7 = FUN_00137d6c(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3f4),0);
              iVar5 = FUN_0010b0f4(piVar8,0);
              *(undefined4 *)(iVar5 + 8) = uVar7;
              *(undefined4 *)(iVar5 + 0xc) = 0;
              FUN_0010ba02(piVar8,1,local_18,0,*(undefined4 *)(param_1 + 0xc));
              FUN_000e956e(iVar9,local_18,piVar8);
              piVar10 = (int *)(*(int *)(param_1 + 0x10) + 0x18);
              *piVar10 = *piVar10 + 1;
              if (piVar8 == (int *)0x0) {
                return local_18;
              }
              local_10 = 1;
              goto LAB_001aedba;
            }
          }
          iVar11 = iVar11 + 1;
          iVar5 = (**(code **)(*local_1c + 0x14))(local_1c);
        } while (iVar11 <= iVar5);
      }
      return local_18;
    }
  }
  return param_3;
LAB_001aedba:
  iVar9 = (**(code **)(*local_1c + 0x14))(local_1c);
  if (iVar9 < local_10) {
    return piVar8;
  }
  iVar9 = local_18[0x26];
  iVar5 = FUN_0010b180(local_1c,local_10);
  if (iVar9 != *(int *)(iVar5 + 0x98)) {
LAB_001aedf5:
    local_10 = local_10 + 1;
    goto LAB_001aedba;
  }
  iVar9 = FUN_0013c4e0(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3f4),local_18);
  uVar7 = FUN_0010b180(local_1c,local_10);
  iVar5 = FUN_0013c4e0(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3f4),uVar7);
  if (iVar9 != iVar5) goto LAB_001aedf5;
  FUN_0010ba02(local_1c,local_10,piVar8,0,*(undefined4 *)(param_1 + 0xc));
  local_10 = local_10 + 1;
  goto LAB_001aedba;
}

/* FUN_001aef20 @ 0x1aef20 (608 bytes) */
int FUN_001aef20(param_1, param_2)
  int *param_1;
  int param_2;
{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  char local_d;
  
  piVar4 = *(int **)(param_2 + 8);
  if (piVar4[2] == 0) {
    return;
  }
  do {
    cVar1 = (**(code **)(*param_1 + 8))(param_1);
    if (cVar1 != '\0') {
      FUN_000e27ca(param_1[3],5);
    }
    iVar6 = param_1[3];
    if (**(char **)(iVar6 + 0x3f4) == '\0') {
      piVar5 = (int *)FUN_000e514a(param_1[4],param_2,piVar4,&local_d);
      if (piVar5 == (int *)0x0) {
        iVar6 = param_1[3];
      }
      else if (local_d == '\0') {
        iVar6 = param_1[3];
      }
      else {
        iVar6 = param_1[3];
        piVar4 = piVar5;
      }
    }
    if (**(char **)(iVar6 + 0x3f4) == '\0') {
      piVar4 = (int *)((int (*)())FUN_001aeb44)(param_1,param_2,piVar4,param_1 + 0x1f);
      iVar6 = param_1[3];
    }
    cVar1 = FUN_0010c6ee(piVar4,*(undefined4 *)(iVar6 + 0x3f4));
    if ((((cVar1 == '\0') || (uVar2 = piVar4[5], (uVar2 & 4) != 0)) || ((int)uVar2 < 0)) ||
       ((uVar2 & 0x1000) != 0)) {
      (**(code **)(*param_1 + 0xbc))(param_1);
      piVar5 = piVar4;
      piVar3 = piVar4;
      do {
        if (piVar3 == (int *)0x0) break;
        uVar2 = piVar5[5];
        if ((uVar2 & 1) != 0) {
          if ((uVar2 & 0x10000) == 0) {
            cVar1 = (**(code **)(*piVar5 + 0x68))(piVar5);
            if (cVar1 != '\0') {
              piVar3 = (int *)FUN_0010b180(piVar5,1);
              cVar1 = (**(code **)(*piVar3 + 0x50))(piVar3);
              if ((cVar1 != '\0') && ((char)piVar5[0x51] != '\0')) {
                return;
              }
            }
            ((int (*)())FUN_001ae26a)(param_1,2);
            (**(code **)(*piVar5 + 0x1c))(piVar5,param_1,0,param_1[3]);
          }
          else {
            cVar1 = (**(code **)(*piVar5 + 0x48))(piVar5);
            if (cVar1 != '\0') {
              (**(code **)(*param_1 + 0xc0))(param_1,piVar5,param_1[3]);
            }
          }
          (**(code **)(*piVar5 + 0x20))(piVar5,param_1,0,param_1[3]);
          uVar2 = piVar5[5];
        }
        piVar3 = (int *)(uVar2 & 4);
        piVar5 = (int *)piVar5[2];
      } while (piVar5 != (int *)0x0);
      cVar1 = (**(code **)(*piVar4 + 0x24))(piVar4);
      if (cVar1 != '\0') {
        (**(code **)(*param_1 + 0xc4))(param_1);
      }
    }
    else {
      *(int *)(param_1[4] + 0xc) = *(int *)(param_1[4] + 0xc) + 1;
    }
    uVar2 = piVar4[5];
    piVar4 = (int *)piVar4[2];
    iVar6 = piVar4[2];
    while( true ) {
      if (iVar6 == 0) {
        return;
      }
      if ((uVar2 & 4) == 0) break;
      uVar2 = piVar4[5];
      piVar4 = (int *)piVar4[2];
      iVar6 = piVar4[2];
    }
  } while( true );
}

/* FUN_001af180 @ 0x1af180 (129 bytes) */
int FUN_001af180(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  ((int (*)())FUN_001ae26a)(param_1,3);
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x28);
  uVar4 = *(int *)(iVar1 + 4) - 1;
  if (uVar4 < *(uint *)(iVar1 + 4)) {
    piVar3 = (int *)(*(int *)(iVar1 + 8) + uVar4 * 4);
  }
  else {
    piVar3 = (int *)0x0;
  }
  iVar2 = *piVar3;
  FUN_001a7f3c(iVar1,*(int *)(iVar1 + 4) + -1);
  *(int *)(iVar2 + 0x18) = *(int *)(param_1 + 0x58) + -2;
  if (*(uint *)(iVar2 + 0x10) < *(uint *)(param_1 + 0x2c)) {
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x58) + -1;
  }
  if (*(uint *)(iVar2 + 0x10) < *(uint *)(param_1 + 0x30)) {
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x58) + -1;
  }
  return;
}

/* FUN_001af202 @ 0x1af202 (198 bytes) */
int FUN_001af202(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  ((int (*)())FUN_001ae26a)(param_1,4);
  iVar4 = *(int *)(param_1 + 0x5c) * 0x1c + *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
  *(undefined4 *)(iVar4 + 8) = 0x3e;
  *(int *)(iVar4 + 0x10) = *(int *)(param_1 + 0x58) + -2;
  *(undefined4 *)(iVar4 + 0xc) = param_2;
  *(uint *)(iVar4 + 4) = (uint)param_3;
  puVar1 = *(uint **)(*(int *)(param_1 + 0x10) + 0x28);
  uVar2 = puVar1[1];
  if (uVar2 < *puVar1) {
    _memset((void *)(uVar2 * 4 + puVar1[2]),0,4);
    puVar1[1] = uVar2 + 1;
    *(int *)(uVar2 * 4 + puVar1[2]) = iVar4;
    return;
  }
  piVar3 = (int *)FUN_001a7f7c(puVar1,uVar2);
  *piVar3 = iVar4;
  return;
}

/* FUN_001af2c8 @ 0x1af2c8 (133 bytes) */
int FUN_001af2c8(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x24);
  uVar4 = *(int *)(iVar1 + 4) - 1;
  if (uVar4 < *(uint *)(iVar1 + 4)) {
    piVar3 = (int *)(*(int *)(iVar1 + 8) + uVar4 * 4);
  }
  else {
    piVar3 = (int *)0x0;
  }
  iVar2 = *piVar3;
  FUN_001a7f3c(iVar1,*(int *)(iVar1 + 4) + -1);
  *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(param_1 + 0x58);
  if (*(int *)(iVar2 + 0x14) == 0) {
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar2 + 0x10);
  }
  if (*(uint *)(iVar2 + 0x10) < *(uint *)(param_1 + 0x2c)) {
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x58);
  }
  if (*(uint *)(iVar2 + 0x10) < *(uint *)(param_1 + 0x30)) {
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x58);
  }
  ((int (*)())FUN_001ae26a)(param_1,3);
  return;
}

/* FUN_001af34e @ 0x1af34e (65 bytes) */
int FUN_001af34e(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xbc);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x88);
  *puVar2 = uVar1;
  *(undefined1 *)(puVar2 + 7) = 0;
  puVar2[1] = &PTR_FUN_001fdfa8;
  return puVar2 + 1;
}

/* FUN_001af390 @ 0x1af390 (104 bytes) */
int FUN_001af390(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fdfa8;
  FUN_001a7aba(*(undefined4 *)(param_1[3] + 0xb8),param_1[2]);
  param_1[2] = 0;
  FUN_001a7aba(*(undefined4 *)(param_1[3] + 0xb8),param_1[0x18]);
  param_1[0x11] = 0;
  *param_1 = PTR_DAT_00213a45 + 8;
  return;
}

/* FUN_001af40c @ 0x1af40c (104 bytes) */
int FUN_001af40c(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fdfa8;
  FUN_001a7aba(*(undefined4 *)(param_1[3] + 0xb8),param_1[2]);
  param_1[2] = 0;
  FUN_001a7aba(*(undefined4 *)(param_1[3] + 0xb8),param_1[0x18]);
  param_1[0x11] = 0;
  *param_1 = PTR_DAT_00213a45 + 8;
  return;
}

/* FUN_001af488 @ 0x1af488 (126 bytes) */
int FUN_001af488(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fdfa8;
  FUN_001a7aba(*(undefined4 *)(param_1[3] + 0xb8),param_1[2]);
  param_1[2] = 0;
  FUN_001a7aba(*(undefined4 *)(param_1[3] + 0xb8),param_1[0x18]);
  param_1[0x11] = 0;
  *param_1 = PTR_DAT_00213a45 + 8;
  if (param_1 != (undefined4 *)0x0) {
    FUN_001a7aba(param_1[-1],param_1 + -1);
  }
  return;
}

/* FUN_001af51a @ 0x1af51a (1980 bytes) */
int FUN_001af51a(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  uint *param_3;
{
  bool bVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  byte bVar10;
  ushort uVar11;
  uint uVar12;
  byte local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  piVar6 = *(int **)(*(int *)(param_1 + 0xc) + 0x54);
  iVar4 = (**(code **)(*piVar6 + 0x16c))(piVar6);
  iVar5 = *(int *)(param_2[0x22] + 8);
  iVar4 = *(int *)(iVar5 * 0x38 + 0xc + iVar4);
  local_2c = (byte)iVar4;
  if (*(int *)(param_2[0x22] + 8) == 0x32) {
    *(byte *)param_3 = local_2c | 0x40;
    uVar12 = param_3[1];
    bVar3 = *(byte *)((int)param_3 + 5) >> 5;
    param_3[1] = param_3[2];
    uVar11 = *(byte *)((int)param_3 + 10) & 7;
    bVar10 = (byte)uVar11;
    *(byte *)((int)param_3 + 5) = *(byte *)((int)param_3 + 5) & 0x1f | bVar10 << 5;
    *(byte *)((int)param_3 + 6) = *(byte *)((int)param_3 + 6) & 0xc0 | bVar10 | bVar10 * '\b';
    *(ushort *)((int)param_3 + 6) = *(ushort *)((int)param_3 + 6) & 0xfe3f | uVar11 << 6;
    param_3[2] = uVar12;
    *(byte *)((int)param_3 + 9) = *(byte *)((int)param_3 + 9) & 0x1f | bVar3 << 5;
    *(byte *)((int)param_3 + 10) = *(byte *)((int)param_3 + 10) & 0xc0 | bVar3 | bVar3 * '\b';
    *(ushort *)((int)param_3 + 10) = *(ushort *)((int)param_3 + 10) & 0xfe3f | (ushort)bVar3 << 6;
    bVar3 = (byte)(*(ushort *)((int)param_3 + 0xe) >> 6);
    bVar10 = bVar3 & 7;
    *(byte *)((int)param_3 + 0xd) = *(byte *)((int)param_3 + 0xd) & 0x1f | bVar3 << 5;
    bVar3 = *(byte *)((int)param_3 + 0xe);
    *(byte *)((int)param_3 + 0xe) = bVar3 & 0xf8 | bVar10;
    *(byte *)((int)param_3 + 0xe) =
         bVar3 & 0xc0 | bVar10 | ((byte)(*(ushort *)((int)param_3 + 0xe) >> 6) & 7) << 3;
    bVar1 = true;
    iVar5 = (**(code **)(*param_2 + 0x14))(param_2);
    goto joined_r0x001af849;
  }
  if (iVar4 == -1) {
    if (iVar5 < 0x32) {
      if (0x2f < iVar5) goto LAB_001afb60;
      if (iVar5 == 0x1c) {
        *(byte *)param_3 = 1;
        *(ushort *)((int)param_3 + 6) = *(ushort *)((int)param_3 + 6) & 0xfe3f | 0x100;
        *(ushort *)((int)param_3 + 10) = *(ushort *)((int)param_3 + 10) & 0xfe3f | 0x100;
        bVar1 = true;
      }
      else {
        if (iVar5 != 0x28) goto LAB_001af57a;
        *(byte *)param_3 = 10;
        uVar12 = param_3[1];
        param_3[1] = param_3[2];
        param_3[2] = uVar12;
        bVar1 = true;
      }
    }
    else if (iVar5 == 0x66) {
LAB_001afb60:
      *(byte *)param_3 = 7;
      param_3[2] = param_3[1];
      bVar1 = false;
    }
    else {
      if (iVar5 != 0xa5) goto LAB_001af57a;
      *(byte *)param_3 = 5;
      param_3[3] = param_3[2];
      bVar1 = true;
    }
  }
  else {
    *(byte *)param_3 = local_2c;
LAB_001af57a:
    bVar1 = true;
  }
  iVar5 = (**(code **)(*param_2 + 0x14))(param_2);
joined_r0x001af849:
  if (iVar5 == 3) {
    piVar6 = (int *)FUN_0010b180(param_2,1);
    cVar2 = (**(code **)(*piVar6 + 0x60))(piVar6);
    if (cVar2 == '\0') {
      uVar9 = FUN_0010b180(param_2,1);
      local_28 = FUN_0013c4e0(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3f4),uVar9);
      iVar5 = FUN_0010b180(param_2,1);
      local_24 = *(int *)(iVar5 + 0x98);
    }
    else {
      uVar9 = FUN_0010b180(param_2,1);
      uVar9 = FUN_0010b180(uVar9,1);
      local_28 = FUN_0013c4e0(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3f4),uVar9);
      uVar9 = FUN_0010b180(param_2,1);
      iVar5 = FUN_0010b180(uVar9,1);
      local_24 = *(int *)(iVar5 + 0x98);
    }
    piVar6 = (int *)FUN_0010b180(param_2,2);
    cVar2 = (**(code **)(*piVar6 + 0x60))(piVar6);
    if (cVar2 == '\0') {
      uVar9 = FUN_0010b180(param_2,2);
      iVar5 = FUN_0013c4e0(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3f4),uVar9);
      iVar7 = FUN_0010b180(param_2,2);
      local_20 = *(int *)(iVar7 + 0x98);
    }
    else {
      uVar9 = FUN_0010b180(param_2,2);
      uVar9 = FUN_0010b180(uVar9,1);
      iVar5 = FUN_0013c4e0(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3f4),uVar9);
      uVar9 = FUN_0010b180(param_2,2);
      iVar7 = FUN_0010b180(uVar9,1);
      local_20 = *(int *)(iVar7 + 0x98);
    }
    piVar6 = (int *)FUN_0010b180(param_2,3);
    cVar2 = (**(code **)(*piVar6 + 0x60))(piVar6);
    if (cVar2 == '\0') {
      uVar9 = FUN_0010b180(param_2,3);
      iVar8 = FUN_0013c4e0(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3f4),uVar9);
      iVar7 = FUN_0010b180(param_2,3);
      iVar7 = *(int *)(iVar7 + 0x98);
    }
    else {
      uVar9 = FUN_0010b180(param_2,3);
      uVar9 = FUN_0010b180(uVar9,1);
      iVar8 = FUN_0013c4e0(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3f4),uVar9);
      uVar9 = FUN_0010b180(param_2,3);
      iVar7 = FUN_0010b180(uVar9,1);
      iVar7 = *(int *)(iVar7 + 0x98);
    }
    if (((((local_24 == 0) && (local_20 == 0)) && (iVar7 == 0)) &&
        ((local_28 != iVar5 && (iVar5 != iVar8)))) && (local_28 != iVar8)) {
      if (iVar4 == 4) {
        *(byte *)param_3 = 0;
      }
      else if (iVar4 == 0xb) {
        *(byte *)param_3 = 1;
      }
      *(byte *)param_3 = (byte)*param_3 | 0x80;
    }
  }
  cVar2 = ((int (*)())FUN_001ae238)(*(undefined4 *)(param_1 + 0x80),param_2);
  if ((cVar2 == '\0') || (!bVar1)) {
    iVar5 = param_2[0x26];
  }
  else {
    *(byte *)param_3 = (byte)*param_3 | 0x40;
    iVar5 = param_2[0x26];
  }
  if ((iVar5 == 5) && (param_2[0x25] == 0)) {
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x58);
  }
  *param_3 = *param_3 & 0xfffff0ff | (*(uint *)(&DAT_001cf080 + param_2[0x26] * 4) & 0xf) << 8;
  iVar5 = FUN_0010b7c8(param_2,0);
  if (iVar5 == 1) {
    *(undefined1 *)(param_1 + 0x24) = 1;
    *(byte *)((int)param_3 + 1) = *(byte *)((int)param_3 + 1) | 0x10;
    uVar12 = FUN_0010b6e4(param_2,0);
  }
  else {
    if (iVar5 == 2) {
      *(undefined1 *)(param_1 + 0x24) = 1;
      *param_3 = *param_3 & 0x1fffffff | 0x20000000;
    }
    uVar12 = 0;
  }
  if ((byte)((*(byte *)((int)param_3 + 1) & 0xf) - 2) < 2) {
    if (iVar5 == 0) {
      uVar12 = uVar12 + param_2[0x25];
    }
    else {
      uVar12 = uVar12 + *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3f4) + 0x3e4);
    }
  }
  else if (iVar5 == 0) {
    iVar5 = FUN_0013c4e0(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3f4),param_2);
    uVar12 = uVar12 + iVar5;
    if (param_2[0x26] == 1) {
      piVar6 = *(int **)(*(int *)(param_1 + 0xc) + 0x54);
      iVar5 = (**(code **)(*piVar6 + 0x138))(piVar6,0);
      uVar12 = uVar12 - iVar5;
      uVar9 = FUN_001ae012();
      *(undefined4 *)(param_1 + 0x38) = uVar9;
    }
    if (param_2[0x26] == 0) {
      uVar9 = FUN_001ae012();
      *(undefined4 *)(param_1 + 0x34) = uVar9;
    }
  }
  *param_3 = *param_3 & 0xfff01fff | (uVar12 & 0x7f) << 0xd;
  iVar5 = FUN_0010b0f4(param_2,0);
  uVar9 = *(undefined4 *)(iVar5 + 0x10);
  uVar12 = *param_3 & 0xff0fffff | (uint)((char)uVar9 == '\0') << 0x14 |
           (uint)((char)((uint)uVar9 >> 8) == '\0') << 0x15 |
           (uint)((char)((uint)uVar9 >> 0x10) == '\0') << 0x16 |
           (uint)((char)((uint)uVar9 >> 0x18) == '\0') << 0x17;
  *param_3 = uVar12;
  if ((char)param_2[0x48] != '\0') {
    cVar2 = ((int (*)())FUN_001ae238)(*(undefined4 *)(param_1 + 0x80),param_2);
    if ((cVar2 != '\0') && (bVar1)) {
      *param_3 = uVar12 | 0x2000000;
      return;
    }
    *param_3 = uVar12 | 0x1000000;
    return;
  }
  return;
}

/* FUN_001afcd6 @ 0x1afcd6 (3184 bytes) */
int FUN_001afcd6(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  byte bVar1;
  int *piVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  int local_88;
  uint *local_70;
  int local_68;
  uint local_64;
  int local_60;
  int local_54;
  uint auStack_4c [4];
  uint local_3c [4];
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  char local_1d;
  
  if (param_5 == 2) {
    local_70 = (uint *)(param_3 + 8);
  }
  else if (param_5 == 3) {
    local_70 = (uint *)(param_3 + 0xc);
  }
  else if (param_5 == 1) {
    local_70 = (uint *)(param_3 + 4);
  }
  else {
    local_70 = (uint *)0x0;
  }
  piVar6 = (int *)FUN_0010b180(param_2,param_4);
  if (piVar6[0x26] == 0x33) {
    if (param_4 < 2) {
      *local_70 = *local_70 & 0xffffe018;
      *(undefined1 *)(param_1 + 0x7d) = 1;
    }
    else {
      uVar7 = *(byte *)(param_3 + 4) & 7;
      uVar11 = *local_70;
      *local_70 = uVar11 & 0xfffffff8 | uVar7;
      uVar8 = (*(byte *)(param_3 + 4) >> 4 & 1) << 4;
      *local_70 = uVar11 & 0xffffffe8 | uVar7 | uVar8;
      uVar9 = (uint)(*(byte *)(param_3 + 7) >> 7) << 0x1f;
      *local_70 = uVar11 & 0x7fffffe8 | uVar7 | uVar8 | uVar9;
      uVar10 = (*(byte *)(param_3 + 7) >> 5 & 3) << 0x1d;
      *local_70 = uVar11 & 0x1fffffe8 | uVar7 | uVar8 | uVar9 | uVar10;
      *local_70 = uVar11 & 0x1fffe008 | uVar7 | uVar8 | uVar9 | uVar10 |
                  (uint)(byte)(*(ushort *)(param_3 + 4) >> 5) << 5;
    }
    FUN_0010b0f4(param_2,param_4);
    bVar3 = *(byte *)(param_2 + 0xa0 + param_4 * 0x18) & 1;
    cVar4 = ((int (*)())FUN_001ae238)(*(undefined4 *)(param_1 + 0x80),param_2);
    if (cVar4 != '\0') {
      uVar11 = ((int (*)())FUN_001ae386)();
      uVar7 = (uVar11 & 7) << 0xd;
      uVar11 = *local_70;
      *local_70 = uVar11 & 0xffff1fff | uVar7;
      if (local_1d != '\0') {
        bVar3 = bVar3 ^ 1;
      }
      uVar8 = (uint)bVar3 << 0x19;
      *local_70 = uVar11 & 0xfdff1fff | uVar7 | uVar8;
      uVar9 = (uint)(*(byte *)((int)local_70 + 1) >> 5) << 0x10;
      *local_70 = uVar11 & 0xfdf81fff | uVar7 | uVar8 | uVar9;
      uVar10 = (*(byte *)((int)local_70 + 3) >> 1 & 1) << 0x1a;
      *local_70 = uVar11 & 0xf9f81fff | uVar7 | uVar8 | uVar9 | uVar10;
      uVar12 = (uint)(*(byte *)((int)local_70 + 1) >> 5) << 0x13;
      *local_70 = uVar11 & 0xf9c01fff | uVar7 | uVar8 | uVar9 | uVar10 | uVar12;
      uVar13 = (*(byte *)((int)local_70 + 3) >> 1 & 1) << 0x1b;
      *local_70 = uVar11 & 0xf1c01fff | uVar7 | uVar8 | uVar9 | uVar10 | uVar12 | uVar13;
      uVar14 = (uint)(*(byte *)((int)local_70 + 1) >> 5) << 0x16;
      *local_70 = uVar11 & 0xf0001fff | uVar7 | uVar8 | uVar9 | uVar10 | uVar12 | uVar13 | uVar14;
      *local_70 = uVar11 & 0xe0001fff | uVar7 | uVar8 | uVar9 | uVar10 | uVar12 | uVar13 | uVar14 |
                  (*(byte *)((int)local_70 + 3) >> 1 & 1) << 0x1c;
      return;
    }
    uVar11 = ((int (*)())FUN_001ae386)();
    uVar7 = (uVar11 & 7) << 0xd;
    uVar11 = *local_70;
    *local_70 = uVar11 & 0xffff1fff | uVar7;
    bVar1 = bVar3;
    if (local_1d != '\0') {
      bVar1 = bVar3 ^ 1;
    }
    *local_70 = uVar11 & 0xfdff1fff | uVar7 | (uint)bVar1 << 0x19;
    uVar11 = ((int (*)())FUN_001ae386)();
    uVar7 = (uVar11 & 7) << 0x10;
    uVar11 = *local_70;
    *local_70 = uVar11 & 0xfff8ffff | uVar7;
    bVar1 = bVar3;
    if (local_1d != '\0') {
      bVar1 = bVar3 ^ 1;
    }
    *local_70 = uVar11 & 0xfbf8ffff | uVar7 | (uint)bVar1 << 0x1a;
    uVar11 = ((int (*)())FUN_001ae386)();
    uVar7 = (uVar11 & 7) << 0x13;
    uVar11 = *local_70;
    *local_70 = uVar11 & 0xffc7ffff | uVar7;
    bVar1 = bVar3;
    if (local_1d != '\0') {
      bVar1 = bVar3 ^ 1;
    }
    *local_70 = uVar11 & 0xf7c7ffff | uVar7 | (uint)bVar1 << 0x1b;
    uVar11 = ((int (*)())FUN_001ae386)();
    uVar7 = (uVar11 & 7) << 0x16;
    uVar11 = *local_70;
    *local_70 = uVar11 & 0xfe3fffff | uVar7;
    if (local_1d != '\0') {
      bVar3 = bVar3 ^ 1;
    }
    *local_70 = uVar11 & 0xee3fffff | uVar7 | (uint)bVar3 << 0x1c;
    return;
  }
  cVar4 = (**(code **)(*piVar6 + 0x60))(piVar6);
  if (cVar4 == '\0') {
    local_60 = FUN_0010b7c8(param_2,param_4);
    local_68 = piVar6[0x26];
    local_64 = FUN_0013c4e0(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3f4),piVar6);
    *local_70 = *local_70 & 0xfffffff8 | *(uint *)(&DAT_001cf1e0 + local_68 * 4) & 7;
joined_r0x001b0284:
    if (local_68 != 0x37) {
      if (local_68 == 1) {
        piVar2 = *(int **)(*(int *)(param_1 + 0xc) + 0x54);
        iVar15 = (**(code **)(*piVar2 + 0x138))(piVar2,0);
        local_64 = local_64 - iVar15;
      }
      goto LAB_001b0294;
    }
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x58);
    cVar4 = FUN_0012df9c(piVar6[0x26]);
    cVar5 = (**(code **)(*piVar6 + 0x60))(piVar6);
    if (cVar5 != '\0') goto LAB_001affa8;
LAB_001b02b4:
    if (cVar4 == '\0') goto LAB_001affea;
LAB_001b02be:
    if (local_64 <= *(uint *)(param_1 + 0x4c)) goto LAB_001affea;
    *(uint *)(param_1 + 0x4c) = local_64;
    if (local_60 - 1U < 2) goto LAB_001b04a9;
LAB_001afff9:
    uVar11 = *local_70;
  }
  else {
    local_60 = FUN_0010b7c8(piVar6,1);
    iVar15 = FUN_0010b180(piVar6,1);
    local_68 = *(int *)(iVar15 + 0x98);
    if (local_68 != 0x33) {
      uVar16 = FUN_0010b180(piVar6,1);
      local_64 = FUN_0013c4e0(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3f4),uVar16);
      *local_70 = *local_70 & 0xfffffff8 | *(uint *)(&DAT_001cf1e0 + local_68 * 4) & 7;
      goto joined_r0x001b0284;
    }
    if (param_4 < 2) {
      *local_70 = *local_70 & 0xfffffff8;
      *(undefined1 *)(param_1 + 0x7d) = 1;
      local_64 = 0;
    }
    else {
      uVar7 = *(byte *)(param_3 + 4) & 7;
      uVar11 = *local_70;
      *local_70 = uVar11 & 0xfffffff8 | uVar7;
      local_64 = (uint)(byte)(*(ushort *)(param_3 + 4) >> 5);
      uVar8 = (*(byte *)(param_3 + 4) >> 4 & 1) << 4;
      *local_70 = uVar11 & 0xffffffe8 | uVar7 | uVar8;
      uVar9 = (uint)(*(byte *)(param_3 + 7) >> 7) << 0x1f;
      *local_70 = uVar11 & 0x7fffffe8 | uVar7 | uVar8 | uVar9;
      *local_70 = uVar11 & 0x1fffffe8 | uVar7 | uVar8 | uVar9 |
                  (*(byte *)(param_3 + 7) >> 5 & 3) << 0x1d;
    }
LAB_001b0294:
    cVar4 = FUN_0012df9c(piVar6[0x26]);
    cVar5 = (**(code **)(*piVar6 + 0x60))(piVar6);
    if (cVar5 == '\0') goto LAB_001b02b4;
LAB_001affa8:
    iVar15 = FUN_0010b180(piVar6,1);
    if (iVar15 == 0) {
      iVar15 = piVar6[0x2c];
    }
    else {
      iVar15 = FUN_0010b180(piVar6,1);
      iVar15 = *(int *)(iVar15 + 0x98);
    }
    cVar4 = FUN_0012df9c(iVar15);
    if (cVar4 != '\0') goto LAB_001b02be;
LAB_001affea:
    if (1 < local_60 - 1U) goto LAB_001afff9;
LAB_001b04a9:
    cVar4 = (**(code **)(*piVar6 + 0x60))(piVar6);
    if (cVar4 == '\0') {
      local_64 = FUN_0010b6e4(param_2,param_4);
    }
    else {
      local_64 = FUN_0010b6e4(piVar6,1);
    }
    *(undefined1 *)(param_1 + 0x24) = 1;
    if (local_68 == 0x28) {
      *(undefined4 *)(param_1 + 0x4c) = 0xff;
LAB_001b0879:
      *(byte *)((int)local_70 + 3) = *(byte *)((int)local_70 + 3) | 0x80;
      uVar11 = *local_70 & 0x9fffffff;
      *local_70 = uVar11;
    }
    else {
      if (local_68 == 0x29) goto LAB_001b0879;
      if (local_68 != 0x26) goto LAB_001afff9;
      *(undefined4 *)(param_1 + 0x4c) = 0xff;
      *(byte *)local_70 = (byte)*local_70 | 0x10;
      cVar4 = (**(code **)(*piVar6 + 0x60))(piVar6);
      if (cVar4 == '\0') {
        iVar15 = FUN_0010b0f4(piVar6,1);
        uVar16 = *(undefined4 *)(iVar15 + 0x10);
      }
      else {
        uVar16 = FUN_0010b180(piVar6,1);
        iVar15 = FUN_0010b0f4(uVar16,1);
        uVar16 = *(undefined4 *)(iVar15 + 0x10);
      }
      cVar4 = FUN_000f56f0(uVar16,DAT_001cf304);
      if (cVar4 == '\0') {
        cVar4 = FUN_000f56f0(uVar16,DAT_001cf300);
        if (cVar4 == '\0') {
          cVar4 = FUN_000f56f0(uVar16,DAT_001cf2fc);
          if (cVar4 == '\0') {
            cVar4 = FUN_000f56f0(uVar16,DAT_001cf2f8);
            if (cVar4 == '\0') {
              uVar11 = *local_70;
            }
            else {
              uVar11 = *local_70 | 0x60000000;
              *local_70 = uVar11;
            }
          }
          else {
            uVar11 = *local_70 & 0x9fffffff | 0x40000000;
            *local_70 = uVar11;
          }
        }
        else {
          uVar11 = *local_70 & 0x9fffffff | 0x20000000;
          *local_70 = uVar11;
        }
      }
      else {
        uVar11 = *local_70 & 0x9fffffff;
        *local_70 = uVar11;
      }
    }
  }
  *local_70 = uVar11 & 0xffffe01f | (local_64 & 0xff) << 5;
  uVar11 = (uint)(*(byte *)(param_2 + 0xa0 + param_4 * 0x18) & 1);
  iVar15 = FUN_0010b0f4(param_2,param_4);
  local_24 = *(uint *)(iVar15 + 0x10);
  cVar4 = (**(code **)(*piVar6 + 0x60))(piVar6);
  if (cVar4 == '\0') {
    local_3c[1] = *(uint *)(&DAT_001cf198 + (local_24 & 0xff) * 4);
    local_3c[2] = *(uint *)(&DAT_001cf198 + (local_24 >> 8 & 0xff) * 4);
    local_3c[3] = *(uint *)(&DAT_001cf198 + (local_24 >> 0x10 & 0xff) * 4);
    local_2c = *(uint *)(&DAT_001cf198 + (local_24 >> 0x18) * 4);
    auStack_4c[1] = uVar11;
    auStack_4c[2] = uVar11;
    auStack_4c[3] = uVar11;
    local_3c[0] = uVar11;
  }
  else {
    iVar15 = FUN_0010b0f4(piVar6,1);
    local_28 = local_24;
    local_24 = FUN_000f5610(*(undefined4 *)(iVar15 + 0x10),local_24);
    local_54 = 1;
    local_88 = 4;
    do {
      bVar3 = *(byte *)((int)&local_2c + local_54 + 3);
      if (bVar3 != 4) {
        if ((local_68 == 0x33) || (bVar1 = *(byte *)((int)&local_28 + local_54 + 3), bVar1 == 4)) {
          if (0 < piVar6[0x21]) {
            iVar15 = 1;
            do {
              iVar17 = FUN_0010b0f4(piVar6,iVar15);
              if (*(char *)(bVar3 + 0x10 + iVar17) != '\x04') {
                FUN_0010b180(piVar6,iVar15);
                uVar16 = ((int (*)())FUN_001ae386)();
                *(undefined4 *)((int)local_3c + local_88) = uVar16;
                uVar7 = uVar11;
                if (local_1d != '\0') {
                  uVar7 = (uint)(uVar11 == 0);
                }
                *(uint *)((int)auStack_4c + local_88) = uVar7;
                break;
              }
              iVar15 = iVar15 + 1;
            } while (iVar15 <= piVar6[0x21]);
          }
        }
        else {
          *(undefined4 *)((int)local_3c + local_88) =
               *(undefined4 *)(&DAT_001cf198 + (uint)bVar1 * 4);
          *(uint *)((int)auStack_4c + local_88) = uVar11;
        }
      }
      local_54 = local_54 + 1;
      local_88 = local_88 + 4;
    } while (local_54 != 5);
  }
  cVar4 = ((int (*)())FUN_001ae238)(*(undefined4 *)(param_1 + 0x80),param_2);
  if (cVar4 == '\0') {
    uVar7 = (local_3c[1] & 7) << 0xd;
    uVar11 = *local_70;
    *local_70 = uVar11 & 0xffff1fff | uVar7;
    uVar8 = (local_3c[2] & 7) << 0x10;
    *local_70 = uVar11 & 0xfff81fff | uVar7 | uVar8;
    uVar9 = (local_3c[3] & 7) << 0x13;
    *local_70 = uVar11 & 0xffc01fff | uVar7 | uVar8 | uVar9;
    uVar10 = (local_2c & 7) << 0x16;
    *local_70 = uVar11 & 0xfe001fff | uVar7 | uVar8 | uVar9 | uVar10;
    uVar12 = (auStack_4c[1] & 1) << 0x19;
    *local_70 = uVar11 & 0xfc001fff | uVar7 | uVar8 | uVar9 | uVar10 | uVar12;
    uVar13 = (auStack_4c[2] & 1) << 0x1a;
    *local_70 = uVar11 & 0xf8001fff | uVar7 | uVar8 | uVar9 | uVar10 | uVar12 | uVar13;
    uVar14 = (auStack_4c[3] & 1) << 0x1b;
    *local_70 = uVar11 & 0xf0001fff | uVar7 | uVar8 | uVar9 | uVar10 | uVar12 | uVar13 | uVar14;
    uVar11 = uVar11 & 0xe0001fff | uVar7 | uVar8 | uVar9 | uVar10 | uVar12 | uVar13 | uVar14 |
             (local_3c[0] & 1) << 0x1c;
    *local_70 = uVar11;
    cVar4 = *(char *)(param_1 + 0x7e);
    goto joined_r0x001b0385;
  }
  if (param_4 == 1) {
    uVar11 = *local_70 & 0xffff1fff | (local_2c & 7) << 0xd;
    *local_70 = uVar11;
    auStack_4c[1] = local_3c[0];
LAB_001b0494:
    uVar11 = uVar11 & 0xfdffffff | (auStack_4c[1] & 1) << 0x19;
    *local_70 = uVar11;
  }
  else {
    if (param_4 == 2) {
      uVar11 = *local_70 & 0xffff1fff | (local_3c[1] & 7) << 0xd;
      *local_70 = uVar11;
      goto LAB_001b0494;
    }
    uVar11 = *local_70;
  }
  uVar7 = (uint)(*(byte *)((int)local_70 + 1) >> 5) << 0x10;
  *local_70 = uVar11 & 0xfff8ffff | uVar7;
  uVar8 = (uint)(*(byte *)((int)local_70 + 1) >> 5) << 0x13;
  *local_70 = uVar11 & 0xffc0ffff | uVar7 | uVar8;
  uVar9 = (uint)(*(byte *)((int)local_70 + 1) >> 5) << 0x16;
  *local_70 = uVar11 & 0xfe00ffff | uVar7 | uVar8 | uVar9;
  uVar10 = (*(byte *)((int)local_70 + 3) >> 1 & 1) << 0x19;
  *local_70 = uVar11 & 0xfc00ffff | uVar7 | uVar8 | uVar9 | uVar10;
  uVar12 = (*(byte *)((int)local_70 + 3) >> 1 & 1) << 0x1a;
  *local_70 = uVar11 & 0xf800ffff | uVar7 | uVar8 | uVar9 | uVar10 | uVar12;
  uVar13 = (*(byte *)((int)local_70 + 3) >> 1 & 1) << 0x1b;
  *local_70 = uVar11 & 0xf000ffff | uVar7 | uVar8 | uVar9 | uVar10 | uVar12 | uVar13;
  uVar11 = uVar11 & 0xe000ffff | uVar7 | uVar8 | uVar9 | uVar10 | uVar12 | uVar13 |
           (*(byte *)((int)local_70 + 3) >> 1 & 1) << 0x1c;
  *local_70 = uVar11;
  cVar4 = *(char *)(param_1 + 0x7e);
joined_r0x001b0385:
  if ((cVar4 != '\0') && ((uVar11 & 0x80000010) == 0)) {
    uVar7 = (byte)*local_70 & 3;
    uVar11 = *(uint *)(param_3 + 0xc);
    *(uint *)(param_3 + 0xc) = uVar11 & 0xfffffffc | uVar7;
    *(uint *)(param_3 + 0xc) =
         uVar11 & 0xffffe01c | uVar7 | (uint)(byte)((ushort)*local_70 >> 5) << 5;
  }
  if ((*(char *)(param_1 + 0x7d) != '\0') && (param_4 == 2)) {
    uVar7 = (byte)*local_70 & 7;
    uVar11 = *(uint *)(param_3 + 4);
    *(uint *)(param_3 + 4) = uVar11 & 0xfffffff8 | uVar7;
    uVar8 = (uint)(byte)((ushort)*local_70 >> 5) << 5;
    *(uint *)(param_3 + 4) = uVar11 & 0xffffe018 | uVar7 | uVar8;
    uVar9 = ((byte)((byte)*local_70 >> 4) & 1) << 4;
    *(uint *)(param_3 + 4) = uVar11 & 0xffffe008 | uVar7 | uVar8 | uVar9;
    uVar10 = (uint)(*(byte *)((int)local_70 + 3) >> 7) << 0x1f;
    *(uint *)(param_3 + 4) = uVar11 & 0x7fffe008 | uVar7 | uVar8 | uVar9 | uVar10;
    *(uint *)(param_3 + 4) =
         uVar11 & 0x1fffe008 | uVar7 | uVar8 | uVar9 | uVar10 |
         (*(byte *)((int)local_70 + 3) >> 5 & 3) << 0x1d;
    return;
  }
  return;
}

/* FUN_001b0946 @ 0x1b0946 (1960 bytes) */
int FUN_001b0946(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  uint *param_3;
{
  int *piVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  byte extraout_var;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  uint local_48;
  uint local_40;
  uint local_30;
  char local_1d;
  
  *(byte *)((int)param_3 + 3) = *(byte *)((int)param_3 + 3) | 0x10;
  puVar12 = param_3 + 3;
  FUN_0010b7c8(param_2,1);
  iVar5 = (**(code **)(*param_2 + 0x14))(param_2);
  if (iVar5 == 2) {
    FUN_0010b7c8(param_2,2);
  }
  piVar6 = (int *)FUN_0010b180(param_2,1);
  cVar2 = (**(code **)(*piVar6 + 0x60))(piVar6);
  if (cVar2 == '\0') {
    iVar5 = piVar6[0x26];
  }
  else {
    iVar5 = FUN_0010b180(piVar6,1);
    iVar5 = *(int *)(iVar5 + 0x98);
  }
  if (iVar5 == 0x37) {
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x58);
  }
  cVar2 = (**(code **)(*piVar6 + 0x60))(piVar6);
  if (cVar2 == '\0') {
    local_40 = FUN_0013c4e0(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3f4),piVar6);
    if (iVar5 != 1) goto LAB_001b0a0b;
LAB_001b0bba:
    piVar1 = *(int **)(*(int *)(param_1 + 0xc) + 0x54);
    iVar10 = (**(code **)(*piVar1 + 0x138))(piVar1,0);
    local_40 = local_40 - iVar10;
    uVar7 = FUN_001ae012();
    *(undefined4 *)(param_1 + 0x38) = uVar7;
  }
  else {
    uVar7 = FUN_0010b180(piVar6,1);
    local_40 = FUN_0013c4e0(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3f4),uVar7);
    if (iVar5 == 1) goto LAB_001b0bba;
LAB_001b0a0b:
    if (iVar5 == 0) {
      uVar7 = FUN_001ae012();
      *(undefined4 *)(param_1 + 0x34) = uVar7;
    }
  }
  uVar11 = param_2[0x2e];
  if ((uVar11 & 2) != 0) {
    *(byte *)puVar12 = (byte)*puVar12 | 8;
    uVar11 = param_2[0x2e];
  }
  if ((uVar11 & 1) != 0) {
    *(byte *)((int)param_3 + 0xf) = *(byte *)((int)param_3 + 0xf) | 2;
  }
  if ((*(byte *)(param_2 + 0x34) & 1) != 0) {
    *(byte *)((int)param_3 + 0xf) = *(byte *)((int)param_3 + 0xf) | 4;
  }
  if (piVar6[0x26] != 0x33) {
    *puVar12 = *puVar12 & 0xfffffffc | *(uint *)(&DAT_001cf1e0 + iVar5 * 4) & 3;
    cVar2 = (**(code **)(*piVar6 + 0x60))(piVar6);
    if (cVar2 == '\0') {
      cVar2 = FUN_0012df9c(piVar6[0x26]);
      if ((cVar2 != '\0') && (*(uint *)(param_1 + 0x4c) < local_40)) {
        *(uint *)(param_1 + 0x4c) = local_40;
      }
    }
    else {
      iVar5 = FUN_0010b180(piVar6,1);
      cVar2 = FUN_0012df9c(*(undefined4 *)(iVar5 + 0x98));
      if ((cVar2 != '\0') && (*(uint *)(param_1 + 0x4c) < local_40)) {
        *(uint *)(param_1 + 0x4c) = local_40;
      }
    }
    *puVar12 = *puVar12 & 0xffffe01f | (local_40 & 0xff) << 5;
    iVar5 = FUN_0010b0f4(param_2,1);
    uVar11 = *(uint *)(iVar5 + 0x10);
    iVar5 = (**(code **)(*param_2 + 0x14))(param_2);
    local_48 = uVar11;
    if (1 < iVar5) {
      iVar5 = FUN_0010b0f4(param_2,2);
      local_48 = *(uint *)(iVar5 + 0x10);
    }
    cVar2 = (**(code **)(*piVar6 + 0x60))(piVar6);
    if (cVar2 == '\0') {
      iVar5 = (**(code **)(*param_2 + 0x14))(param_2);
      if (iVar5 < 2) {
        local_30 = *(uint *)(&DAT_001cf198 + (uVar11 >> 0x18) * 4);
        uVar11 = local_30;
      }
      else {
        local_30 = *(uint *)(&DAT_001cf198 + (uVar11 >> 0x18) * 4);
        uVar11 = *(uint *)(&DAT_001cf198 + (local_48 & 0xff) * 4);
      }
    }
    else {
      iVar5 = FUN_0010b0f4(piVar6,1);
      uVar7 = *(undefined4 *)(iVar5 + 0x10);
      FUN_000f5610(uVar7,uVar11);
      if (((char)(uVar11 >> 0x18) == '\x04') || (extraout_var == 4)) {
        if (0 < piVar6[0x21]) {
          iVar5 = 1;
          do {
            iVar10 = FUN_0010b0f4(piVar6,iVar5);
            if (*(char *)(iVar10 + 0x13) != '\x04') {
              FUN_0010b180(piVar6,iVar5);
              local_30 = ((int (*)())FUN_001ae386)();
              goto LAB_001b0b42;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 <= piVar6[0x21]);
        }
        local_30 = 0;
      }
      else {
        local_30 = *(uint *)(&DAT_001cf198 + (uint)extraout_var * 4);
      }
LAB_001b0b42:
      iVar5 = (**(code **)(*param_2 + 0x14))(param_2);
      if (iVar5 < 2) {
LAB_001b0fd5:
        uVar11 = 0;
      }
      else {
        bVar3 = FUN_000f5610(uVar7,local_48);
        if (((char)local_48 == '\x04') || (bVar3 == 4)) {
          if (piVar6[0x21] < 1) goto LAB_001b0fd5;
          iVar5 = 1;
          do {
            iVar10 = FUN_0010b0f4(piVar6,iVar5);
            if (*(char *)(iVar10 + 0x10) != '\x04') {
              FUN_0010b180(piVar6,iVar5);
              uVar11 = ((int (*)())FUN_001ae386)();
              goto LAB_001b0ee6;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 <= piVar6[0x21]);
          uVar11 = 0;
        }
        else {
          uVar11 = *(uint *)(&DAT_001cf198 + (uint)bVar3 * 4);
        }
      }
    }
LAB_001b0ee6:
    *puVar12 = (local_30 & 7) << 0xd | *puVar12 & 0xfff81fff | (uVar11 & 7) << 0x10;
    goto LAB_001b0d4e;
  }
  if ((param_3[1] & 0x80000010) == 0) {
    uVar11 = *puVar12 & 0xfffffffc | (byte)param_3[1] & 3;
    *puVar12 = uVar11;
    uVar4 = (ushort)param_3[1];
LAB_001b0c59:
    *puVar12 = uVar11 & 0xffffe01f | (uint)(byte)(uVar4 >> 5) << 5;
  }
  else {
    if ((param_3[2] & 0x80000010) == 0) {
      uVar11 = *puVar12 & 0xfffffffc | (byte)param_3[2] & 3;
      *puVar12 = uVar11;
      uVar4 = (ushort)param_3[2];
      goto LAB_001b0c59;
    }
    if (((param_3[1] & 7) == 0) && ((param_3[2] & 7) == 0)) {
      *puVar12 = *puVar12 & 0xffffe01c | 2;
    }
    else {
      *puVar12 = *puVar12 & 0xffffe01c;
    }
  }
  *(undefined1 *)(param_1 + 0x7e) = 1;
  FUN_0010b0f4(param_2,1);
  uVar11 = ((int (*)())FUN_001ae386)();
  uVar8 = (uVar11 & 7) << 0xd;
  uVar11 = *puVar12;
  *puVar12 = uVar11 & 0xffff1fff | uVar8;
  if (local_1d == '\0') {
    uVar9 = (uint)(*(byte *)((int)param_3 + 0xf) >> 1);
  }
  else {
    uVar9 = ~(uint)(*(byte *)((int)param_3 + 0xf) >> 1);
  }
  *puVar12 = uVar11 & 0xfdff1fff | uVar8 | (uVar9 & 1) << 0x19;
  iVar5 = (**(code **)(*param_2 + 0x14))(param_2);
  if (1 < iVar5) {
    FUN_0010b180(param_2,2);
    FUN_0010b0f4(param_2,2);
    uVar11 = ((int (*)())FUN_001ae386)();
    uVar8 = (uVar11 & 7) << 0x10;
    uVar11 = *puVar12;
    *puVar12 = uVar11 & 0xfff8ffff | uVar8;
    if (local_1d == '\0') {
      uVar9 = (uint)(*(byte *)((int)param_3 + 0xf) >> 2);
    }
    else {
      uVar9 = ~(uint)(*(byte *)((int)param_3 + 0xf) >> 2);
    }
    *puVar12 = uVar11 & 0xfbf8ffff | uVar8 | (uVar9 & 1) << 0x1a;
  }
LAB_001b0d4e:
  piVar6 = *(int **)(*(int *)(param_1 + 0xc) + 0x54);
  iVar5 = (**(code **)(*piVar6 + 0x16c))(piVar6);
  uVar11 = *(uint *)(*(int *)(param_2[0x22] + 8) * 0x38 + 0xc + iVar5);
  if (uVar11 == 0xffffffff) {
    if (*(int *)(param_2[0x22] + 8) == 0x66) {
      *puVar12 = *puVar12 & 0xfe18ffff | 0x1450000;
    }
  }
  else {
    *puVar12 = *puVar12 & 0xfe1fffff | (uVar11 & 0xf) << 0x15;
    if (0xf < (int)uVar11) {
      *(byte *)puVar12 = (byte)*puVar12 | 4;
    }
  }
  iVar5 = FUN_0010b0f4(param_2,0);
  iVar5 = *(int *)(iVar5 + 0x10);
  if (iVar5 == DAT_001cf1c0) {
    *puVar12 = *puVar12 & 0xe7ffffff;
  }
  else if (iVar5 == DAT_001cf1bc) {
    *puVar12 = *puVar12 & 0xe7ffffff | 0x8000000;
  }
  else if (iVar5 == DAT_001cf1b8) {
    *puVar12 = *puVar12 & 0xe7ffffff | 0x10000000;
  }
  else if (iVar5 == DAT_001cf1b4) {
    *puVar12 = *puVar12 | 0x18000000;
  }
  iVar5 = FUN_0013c4e0(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3f4),param_2);
  piVar6 = *(int **)(*(int *)(param_1 + 0xc) + 0x54);
  iVar10 = (**(code **)(*piVar6 + 0x138))(piVar6,0);
  *puVar12 = *puVar12 & 0xffe7ffff | (iVar5 - iVar10 & 3U) << 0x13;
  if ((char)param_2[0x48] != '\0') {
    piVar6 = *(int **)(*(int *)(param_1 + 0xc) + 0x54);
    (**(code **)(*piVar6 + 0x80))(piVar6);
    *param_3 = *param_3 | 0x2000000;
  }
  return;
}

/* FUN_001b10ee @ 0x1b10ee (520 bytes) */
int FUN_001b10ee(param_1, param_2)
  int param_1;
  int *param_2;
{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint *puVar4;
  
  iVar3 = *(int *)(param_1 + 0x58) * 8;
  piVar1 = (int *)(*(int *)(param_1 + 8) + iVar3);
  if (*piVar1 == 0) {
    *piVar1 = (int)param_2;
  }
  else {
    *(int **)(*(int *)(param_1 + 8) + 4 + iVar3) = param_2;
  }
  puVar4 = (uint *)(*(int *)(param_1 + 0x58) * 0x10 + *(int *)(param_1 + 0x44));
  cVar2 = ((int (*)())FUN_001ae238)(*(undefined4 *)(param_1 + 0x80),param_2);
  if ((cVar2 == '\0') || (*(char *)(param_1 + 0x7c) == '\0')) {
    *(undefined1 *)(param_1 + 0x7d) = 0;
    *(undefined1 *)(param_1 + 0x7e) = 0;
    iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
    if (0 < iVar3) {
      ((int (*)())FUN_001afcd6)(param_1,param_2,puVar4,1,1);
    }
    iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar3 < 2) {
      ((int (*)())FUN_001ae420)();
    }
    else {
      ((int (*)())FUN_001afcd6)(param_1,param_2,puVar4,2,2);
    }
    iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar3 < 3) {
      if (*(char *)(param_1 + 0x7c) == '\0') {
        ((int (*)())FUN_001ae420)();
      }
    }
    else {
      ((int (*)())FUN_001afcd6)(param_1,param_2,puVar4,3,3);
    }
    ((int (*)())FUN_001af51a)(param_1,param_2,puVar4);
    iVar3 = param_2[0x47];
  }
  else {
    iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
    if (1 < iVar3) {
      FUN_0010b180(param_2,1);
      FUN_0010b180(param_2,2);
    }
    iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
    if (0 < iVar3) {
      iVar3 = FUN_0010b0f4(param_2,1);
      FUN_000f5672(*(undefined4 *)(iVar3 + 0x10));
    }
    ((int (*)())FUN_001b0946)(param_1,param_2,puVar4);
    iVar3 = param_2[0x47];
  }
  if (iVar3 != 2) {
    if (iVar3 == 3) {
      *puVar4 = *puVar4 | 0xc000000;
      return;
    }
    return;
  }
  *puVar4 = *puVar4 & 0xf7ffffff | 0x4000000;
  return;
}

/* FUN_001b12f6 @ 0x1b12f6 (69 bytes) */
int FUN_001b12f6(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  
  if (-1 < *(int *)(param_1 + 0x84)) {
    return *(undefined4 *)(param_1 + 0x84);
  }
  uVar1 = FUN_00137d6c(param_2,0);
  *(undefined4 *)(param_1 + 0x84) = uVar1;
  return *(undefined4 *)(param_1 + 0x84);
}

/* FUN_001b133c @ 0x1b133c (5 bytes) */
int FUN_001b133c()
{
  return;
}

/* FUN_001b1342 @ 0x1b1342 (102 bytes) */
int FUN_001b1342(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  if (param_3 == '\0') {
    iVar1 = *(int *)(param_1 + 0x8c);
    uVar3 = *(int *)(iVar1 + 4) - 1;
    if (uVar3 < *(uint *)(iVar1 + 4)) {
      puVar2 = (undefined4 *)(*(int *)(iVar1 + 8) + uVar3 * 4);
    }
    else {
      puVar2 = (undefined4 *)0x0;
    }
    FUN_000e4164(param_2 + 0x90,*puVar2);
  }
  FUN_001ae15c();
  return;
}

/* FUN_001b13a8 @ 0x1b13a8 (151 bytes) */
int FUN_001b13a8(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_1 + 0x88) != 0) {
    return *(undefined4 *)(param_1 + 0x88);
  }
  uVar2 = FUN_00137d6c(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3f4),0);
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xbc);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar3 = uVar1;
  FUN_0010eafa(puVar3 + 1,*(undefined4 *)(param_1 + 0xc));
  *(undefined4 **)(param_1 + 0x88) = puVar3 + 1;
  puVar3[0x26] = uVar2;
  puVar3[0x27] = 0;
  return *(undefined4 *)(param_1 + 0x88);
}

/* FUN_001b145c @ 0x1b145c (523 bytes) */
int FUN_001b145c(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  undefined4 param_3;
  int param_4;
{
  uint *puVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  iVar5 = param_2[0x4c];
  iVar3 = FUN_001a7d8a(iVar5 + 0x90);
  if ((iVar3 < 3) && (cVar2 = FUN_000e97ce(iVar5), cVar2 != '\0')) {
    if (*(int *)(*(int *)(iVar5 + 0xd0) + 4) == 0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = *(int **)(*(int *)(iVar5 + 0xd0) + 8);
    }
    if (*piVar4 == param_2[0x4d]) {
      return;
    }
    cVar2 = (**(code **)(*param_2 + 0x40))(param_2);
  }
  else {
    cVar2 = (**(code **)(*param_2 + 0x40))(param_2);
  }
  if (cVar2 == '\0') {
    if (((char)param_2[0x4f] == '\0') || (*(int *)(*(int *)(param_1 + 0x8c) + 4) != 2)) {
      if (**(char **)(param_4 + 0x3f4) == '\0') {
        piVar4 = (int *)FUN_0010a17a(0x57,param_4);
        iVar5 = ((int (*)())FUN_001b13a8)(param_1);
        piVar4[0x25] = *(int *)(iVar5 + 0x94);
        piVar4[0x26] = 0;
        piVar4[0x27] = DAT_001cf30c;
        FUN_0010ba02(piVar4,1,iVar5,0,param_4);
        iVar5 = FUN_0010b0f4(piVar4,1);
        *(undefined4 *)(iVar5 + 0x10) = DAT_001cf308;
        (**(code **)(*piVar4 + 0x84))(piVar4,0);
        FUN_000e9540();
        return;
      }
    }
    else {
      FUN_001a7f3c(*(int *)(param_1 + 0x8c),1);
      puVar1 = *(uint **)(param_1 + 0x8c);
      uVar7 = puVar1[1];
      if (uVar7 < *puVar1) {
        _memset((void *)(uVar7 * 4 + puVar1[2]),0,4);
        puVar1[1] = uVar7 + 1;
        puVar6 = (undefined4 *)(uVar7 * 4 + puVar1[2]);
      }
      else {
        puVar6 = (undefined4 *)FUN_001a7f7c(puVar1,uVar7);
      }
      *puVar6 = 2;
    }
  }
  else {
    iVar5 = *(int *)(*(int *)(param_1 + 0x10) + 0x24);
    uVar7 = *(int *)(iVar5 + 4) - 1;
    if (uVar7 < *(uint *)(iVar5 + 4)) {
      piVar4 = (int *)(*(int *)(iVar5 + 8) + uVar7 * 4);
    }
    else {
      piVar4 = (int *)0x0;
    }
    iVar5 = *piVar4;
    ((int (*)())FUN_001ae26a)(param_1,4);
    *(int *)(iVar5 + 0x14) = *(int *)(param_1 + 0x58) + -2;
  }
  return;
}

/* FUN_001b1668 @ 0x1b1668 (185 bytes) */
int FUN_001b1668(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  int *piVar2;
  
  if (**(char **)(param_2 + 0xac) == '\0') {
    iVar1 = ((int (*)())FUN_001b13a8)(param_1);
    iVar1 = *(int *)(iVar1 + 0x94);
    piVar2 = (int *)FUN_0010a17a(0x59,param_4);
    piVar2[0x25] = iVar1;
    piVar2[0x26] = 0;
    piVar2[0x27] = DAT_001cf30c;
    (**(code **)(*piVar2 + 0x84))(piVar2,3);
    FUN_000e9512(param_2,piVar2);
  }
                    
                    
  (**(code **)(*param_1 + 0x34))();
  return;
}

/* FUN_001b1722 @ 0x1b1722 (87 bytes) */
int FUN_001b1722(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  code *UNRECOVERED_JUMPTABLE;
  
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined1 *)(param_2 + 0xdc));
  UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0xa0);
  FUN_000e9a1c(*(undefined4 *)(param_2 + 0x124));
                    
                    
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

/* FUN_001b177a @ 0x1b177a (1342 bytes) */
int FUN_001b177a(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int *local_24;
  
  pcVar1 = *(char **)(param_2 + 0xac);
  iVar3 = FUN_000e9644(param_2);
  if (*pcVar1 != '\0') {
    (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined1 *)(param_2 + 0xdc));
    FUN_000e3d70();
    return;
  }
  iVar2 = param_1[0x23];
  uVar7 = *(int *)(iVar2 + 4) - 1;
  if (uVar7 < *(uint *)(iVar2 + 4)) {
    piVar4 = (int *)(*(int *)(iVar2 + 8) + uVar7 * 4);
  }
  else {
    piVar4 = (int *)0x0;
  }
  iVar2 = *piVar4;
  iVar5 = FUN_0010b0f4(iVar3,1);
  uVar7 = *(uint *)(iVar5 + 0x10);
  iVar5 = *(int *)(*(int *)(iVar3 + 0x88) + 8);
  if (iVar5 == 0x8b) {
    if (*(int *)(iVar3 + 300) == 0) {
      local_24 = (int *)FUN_0010a17a(0x12,param_6);
      iVar5 = FUN_0010b0f4(local_24,1);
      *(uint *)(iVar5 + 0x10) = uVar7;
      FUN_00109c0e(local_24 + 0x29,1,*(byte *)(iVar3 + 0xb8) & 1);
      uVar6 = FUN_0010b180(iVar3,1);
      FUN_0010ba02(local_24,1,uVar6,0,param_6);
      uVar6 = FUN_0010b180(iVar3,2);
      FUN_0010ba02(local_24,2,uVar6,0,param_6);
      FUN_00109c0e(local_24 + 0x2f,1,1);
      iVar5 = ((int (*)())FUN_001b12f6)(param_1,pcVar1);
      local_24[0x25] = iVar5;
      local_24[0x26] = 0;
      (**(code **)(*local_24 + 0x84))(local_24,iVar2);
      FUN_000e9512(param_2,local_24);
      goto LAB_001b1821;
    }
  }
  else if (iVar5 == 0x8c) {
    if (*(int *)(iVar3 + 300) == 0) {
      local_24 = (int *)FUN_0010b180(iVar3,1);
    }
    else {
      local_24 = (int *)FUN_0010a17a(0x12,param_6);
      iVar5 = FUN_0010b0f4(local_24,1);
      *(uint *)(iVar5 + 0x10) = uVar7;
      FUN_00109c0e(local_24 + 0x29,1,*(byte *)(iVar3 + 0xb8) & 1);
      uVar6 = FUN_0010b180(iVar3,1);
      FUN_0010ba02(local_24,1,uVar6,0,param_6);
      FUN_000fa0d2(local_24,pcVar1,2,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
      FUN_00109c0e(local_24 + 0x2f,1,1);
      iVar5 = ((int (*)())FUN_001b12f6)(param_1,pcVar1);
      local_24[0x25] = iVar5;
      local_24[0x26] = 0;
      (**(code **)(*local_24 + 0x84))(local_24,iVar2);
      FUN_000e9512(param_2,local_24);
    }
    goto LAB_001b1821;
  }
  local_24 = (int *)0x0;
LAB_001b1821:
  iVar5 = ((int (*)())FUN_001b13a8)(param_1);
  iVar5 = *(int *)(iVar5 + 0x94);
  piVar4 = (int *)FUN_0010a17a(0x54,param_6);
  piVar4[0x25] = 0;
  piVar4[0x26] = 0;
  piVar4[0x27] = DAT_001cf310;
  FUN_0010ba02(piVar4,1,local_24,0,param_6);
  iVar8 = 0;
  do {
    (**(code **)(*piVar4 + 0x88))(piVar4,1,iVar8,uVar7 >> 0x18);
    iVar8 = iVar8 + 1;
  } while (iVar8 != 4);
  (**(code **)(*piVar4 + 0x84))(piVar4,iVar2);
  FUN_000e9512(param_2,piVar4);
  piVar4 = (int *)FUN_0010a17a(0x3e,param_6);
  FUN_0010ba02(piVar4,1,local_24,0,param_6);
  iVar8 = 0;
  do {
    (**(code **)(*piVar4 + 0x88))(piVar4,1,iVar8,uVar7 >> 0x18);
    iVar8 = iVar8 + 1;
  } while (iVar8 != 4);
  piVar4[0x25] = iVar5;
  piVar4[0x26] = 0;
  piVar4[0x27] = DAT_001cf30c;
  (**(code **)(*piVar4 + 0x84))(piVar4,(iVar2 != 3) + '\x02');
  FUN_000e9512(param_2,piVar4);
  FUN_001a7c98(iVar3);
  *(undefined4 *)(param_2 + 0x128) = 0;
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined1 *)(param_2 + 0xdc));
  FUN_000e3d70();
  return;
}

/* FUN_001b1cb8 @ 0x1b1cb8 (155 bytes) */
int FUN_001b1cb8(param_1)
  undefined4 *param_1;
{
  int iVar1;
  
  *param_1 = &PTR_FUN_001fe088;
  iVar1 = param_1[0x24];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x23];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  ((int (*)())FUN_001af390)(param_1);
  if (param_1 != (undefined4 *)0x0) {
    FUN_001a7aba(param_1[-1],param_1 + -1);
  }
  return;
}

/* FUN_001b1d66 @ 0x1b1d66 (220 bytes) */
int FUN_001b1d66(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_001ae7e6)(param_1,param_2,param_3,param_4);
  *(undefined4 *)(param_1 + 0x84) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x88) = 0;
  uVar2 = *(undefined4 *)(param_4 + 0xbc);
  puVar1 = (undefined4 *)FUN_001a7bca(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[4] = uVar2;
  puVar1[2] = 0;
  puVar1[1] = 2;
  uVar2 = FUN_001a7bca(uVar2,8);
  puVar1[3] = uVar2;
  *(undefined4 **)(param_1 + 0x90) = puVar1 + 1;
  uVar2 = *(undefined4 *)(param_4 + 0xbc);
  puVar1 = (undefined4 *)FUN_001a7bca(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[4] = uVar2;
  puVar1[2] = 0;
  puVar1[1] = 2;
  uVar2 = FUN_001a7bca(uVar2,8);
  puVar1[3] = uVar2;
  *(undefined4 **)(param_1 + 0x8c) = puVar1 + 1;
  return;
}

