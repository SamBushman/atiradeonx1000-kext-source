#include "decls.h"

/* FUN_001a2994 @ 0x1a2994 (380 bytes) */
int FUN_001a2994(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  *(undefined4 *)(param_1[0x18] * 0x48 + param_1[0x2a]) = 5;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x12) = 0xff;
  if (param_3 == 0) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xe) = 5;
  }
  else {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xe) = 6;
  }
  if (param_2 < 1) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x15) = 0;
  }
  else {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x15) = 1;
  }
  *(char *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x13) = (char)param_2;
  (**(code **)(*param_1 + 0x15c))(param_1);
  *(short *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x3c) = (short)param_1[0x18] + -1;
  iVar1 = param_1[0x18];
  puVar5 = *(uint **)(param_1[4] + 0x28);
  iVar3 = param_1[0x2a];
  uVar4 = puVar5[1];
  if (uVar4 < *puVar5) {
    _memset((void *)(uVar4 * 4 + puVar5[2]),0,4);
    piVar2 = (int *)(uVar4 * 4 + puVar5[2]);
    puVar5[1] = uVar4 + 1;
  }
  else {
    piVar2 = (int *)FUN_0019423c(puVar5,uVar4);
  }
  *piVar2 = iVar1 * 0x48 + iVar3 + -0x48;
  return;
}

/* FUN_001a2b10 @ 0x1a2b10 (248 bytes) */
int FUN_001a2b10(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  undefined4 param_6;
{
  int iVar1;
  undefined4 uVar2;
  int local_38 [7];
  
  local_38[0] = 0;
  iVar1 = FUN_001a0fe4(param_3,local_38);
  if (local_38[0] == 0) {
    uVar2 = FUN_000e9184(param_6,0);
    FUN_001a25a8(param_1,param_3,param_5,uVar2);
    ((int (*)())FUN_001a2994)(param_1,param_2 + -1,param_4);
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + -0x36) = 0xf0;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + -0x3d) = 1;
  }
  else if ((iVar1 != 0) && (((int (*)())FUN_001a2994)(param_1,param_2 + -1,param_4), param_5 != 0)) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + -0x44) = 1;
  }
  return;
}

/* FUN_001a2c08 @ 0x1a2c08 (264 bytes) */
int FUN_001a2c08(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  
  piVar2 = (int *)FUN_000e7804(param_2);
  (**(code **)(*piVar2 + 0x14))();
  FUN_0019401c(piVar2);
  *(undefined4 *)(param_2 + 0x130) = 0;
  iVar5 = param_1[0x18];
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  piVar3 = (int *)0x0;
  iVar1 = *(int *)(*(int *)(param_2 + 0x134) + 0xd0);
  if (*(int *)(iVar1 + 4) != 0) {
    piVar3 = *(int **)(iVar1 + 8);
  }
  iVar1 = *piVar3;
  (**(code **)(*param_1 + 0x34))(param_1,iVar1 + 0x90,*(undefined4 *)(iVar1 + 0xdc));
  if (((*(int *)(param_2 + 0xdc) == 0) && (*(int *)(iVar1 + 0xdc) == 0)) ||
     (uVar4 = 1, iVar5 != param_1[0x18])) {
    uVar4 = 0;
  }
  ((int (*)())FUN_001a2b10)(param_1,*(undefined4 *)(iVar1 + 0x130),piVar2,
               *(undefined4 *)(*(int *)(iVar1 + 300) + 0x134),uVar4,param_2);
  return;
}

/* FUN_001a2d10 @ 0x1a2d10 (160 bytes) */
int FUN_001a2d10(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  bool bVar1;
  int iVar2;
  
  iVar2 = param_1[0x18];
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  if ((*(int *)(param_2 + 0xdc) == 0) || (bVar1 = true, iVar2 != param_1[0x18])) {
    bVar1 = false;
  }
  ((int (*)())FUN_001a2994)(param_1,*(undefined4 *)(param_2 + 0x130),
               *(undefined4 *)(*(int *)(param_2 + 300) + 0x134));
  if (bVar1) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x44) = 1;
  }
  return;
}

/* FUN_001a2db0 @ 0x1a2db0 (308 bytes) */
int FUN_001a2db0(param_1, param_2)
  int *param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  
  *(undefined4 *)(param_1[0x18] * 0x48 + param_1[0x2a]) = 5;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x12) = 0xf;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xe) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x14) = 2;
  if (param_2 != 0) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x15) = 2;
  }
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xb) = 1;
  iVar2 = param_1[0x18];
  puVar4 = *(uint **)(param_1[4] + 0x24);
  uVar3 = puVar4[1];
  if (uVar3 < *puVar4) {
    _memset((void *)(uVar3 * 4 + puVar4[2]),0,4);
    piVar1 = (int *)(uVar3 * 4 + puVar4[2]);
    puVar4[1] = uVar3 + 1;
  }
  else {
    piVar1 = (int *)FUN_0019423c(puVar4,uVar3);
  }
  *piVar1 = iVar2;
  (**(code **)(*param_1 + 0x15c))(param_1);
  param_1[0x2e] = param_1[0x2e] + 1;
  return;
}

/* FUN_001a2ee4 @ 0x1a2ee4 (284 bytes) */
int FUN_001a2ee4(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = (int *)FUN_000e7804(param_2);
  (**(code **)(*piVar1 + 0x14))();
  FUN_0019401c(piVar1);
  *(undefined4 *)(param_2 + 0x130) = 0;
  iVar4 = param_1[0x18];
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  if ((*(int *)(param_2 + 0xdc) == 0) || (uVar3 = 1, iVar4 != param_1[0x18])) {
    uVar3 = 0;
  }
  uVar2 = FUN_000e9184(param_2,0);
  FUN_001a25a8(param_1,piVar1,uVar3,uVar2);
  iVar5 = *(int *)(param_2 + 0x138);
  iVar4 = FUN_00194034(iVar5 + 0x90);
  if ((iVar4 < 3) && (iVar4 = FUN_000e79e8(iVar5), iVar4 != 0)) {
    piVar1 = (int *)0x0;
    if (*(int *)(*(int *)(iVar5 + 0xd0) + 4) != 0) {
      piVar1 = *(int **)(*(int *)(iVar5 + 0xd0) + 8);
    }
    uVar3 = 0;
    if (*piVar1 == *(int *)(param_2 + 0x13c)) goto LAB_001a2fe8;
  }
  uVar3 = 1;
LAB_001a2fe8:
  ((int (*)())FUN_001a2db0)(param_1,uVar3);
  return;
}

/* FUN_001a3000 @ 0x1a3000 (556 bytes) */
int FUN_001a3000(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  
  iVar4 = param_2[0x4e];
  iVar2 = FUN_00194034(iVar4 + 0x90);
  if ((iVar2 < 3) && (iVar2 = FUN_000e79e8(iVar4), iVar2 != 0)) {
    piVar1 = (int *)0x0;
    if (*(int *)(*(int *)(iVar4 + 0xd0) + 4) != 0) {
      piVar1 = *(int **)(*(int *)(iVar4 + 0xd0) + 8);
    }
    if (*piVar1 == param_2[0x4f]) {
      return;
    }
  }
  *(undefined4 *)(param_1[0x18] * 0x48 + param_1[0x2a]) = 5;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xe) = 0;
  iVar2 = (**(code **)(*param_2 + 0x40))(param_2);
  if (iVar2 == 0) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x12) = 0;
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x15) = 1;
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x13) = 1;
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xf) = 1;
  }
  else {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x12) = 0xff;
  }
  piVar1 = (int *)0x0;
  iVar2 = *(int *)(param_1[4] + 0x24);
  uVar3 = *(uint *)(iVar2 + 4);
  if (uVar3 - 1 < uVar3) {
    piVar1 = (int *)((uVar3 - 1) * 4 + *(int *)(iVar2 + 8));
  }
  iVar4 = *piVar1;
  FUN_00194208(iVar2,uVar3 - 1);
  *(short *)(iVar4 * 0x48 + param_1[0x2a] + 0xc) = (short)param_1[0x18] - (short)param_1[0x1d];
  iVar2 = param_1[0x18];
  puVar5 = *(uint **)(param_1[4] + 0x24);
  uVar3 = puVar5[1];
  if (uVar3 < *puVar5) {
    _memset((void *)(uVar3 * 4 + puVar5[2]),0,4);
    piVar1 = (int *)(uVar3 * 4 + puVar5[2]);
    puVar5[1] = uVar3 + 1;
  }
  else {
    piVar1 = (int *)FUN_0019423c(puVar5,uVar3);
  }
  *piVar1 = iVar2;
  if (*(int *)(param_2[0x4f] + 0xdc) != 0) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 4) = 1;
  }
                    
                    
  (**(code **)(*param_1 + 0x15c))(param_1);
  return;
}

/* FUN_001a322c @ 0x1a322c (32 bytes) */
int FUN_001a322c()
{
  return;
}

/* FUN_001a324c @ 0x1a324c (8 bytes) */
int FUN_001a324c()
{
  return;
}

/* FUN_001a3254 @ 0x1a3254 (4 bytes) */
int FUN_001a3254()
{
  return;
}

/* FUN_001a3258 @ 0x1a3258 (4 bytes) */
int FUN_001a3258()
{
  return;
}

/* FUN_001a325c @ 0x1a325c (4 bytes) */
int FUN_001a325c()
{
  return;
}

/* FUN_001a3260 @ 0x1a3260 (4 bytes) */
int FUN_001a3260()
{
  return;
}

/* FUN_001a3264 @ 0x1a3264 (24 bytes) */
int FUN_001a3264()
{
  return;
}

/* FUN_001a327c @ 0x1a327c (84 bytes) */
int FUN_001a327c()
{
  return;
}

/* FUN_001a32d0 @ 0x1a32d0 (172 bytes) */
int FUN_001a32d0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  if (DAT_001fc1d4 == (code *)0x0) {
    DAT_001fc1d4 = (code *)((int (*)())FUN_001a3580)("sprintf");
  }
                    
                    
  (*DAT_001fc1d4)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_001a337c @ 0x1a337c (172 bytes) */
int FUN_001a337c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  if (DAT_001fc1d8 == (code *)0x0) {
    DAT_001fc1d8 = (code *)((int (*)())FUN_001a3580)("printf");
  }
                    
                    
  (*DAT_001fc1d8)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_001a3428 @ 0x1a3428 (172 bytes) */
int FUN_001a3428(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  if (DAT_001fc1dc == (code *)0x0) {
    DAT_001fc1dc = (code *)((int (*)())FUN_001a3580)("vsnprintf");
  }
                    
                    
  (*DAT_001fc1dc)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_001a34d4 @ 0x1a34d4 (172 bytes) */
int FUN_001a34d4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  if (DAT_001fc1e0 == (code *)0x0) {
    DAT_001fc1e0 = (code *)((int (*)())FUN_001a3580)("vsprintf");
  }
                    
                    
  (*DAT_001fc1e0)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_001a3580 @ 0x1a3580 (164 bytes) */
int FUN_001a3580(param_1)
  char *param_1;
{
  size_t sVar1;
  int iVar2;
  char local_58 [4];
  char acStack_54 [4];
  char acStack_50 [64];
  
  local_58[0] = '_';
  _strcpy(local_58 + 1,param_1);
  sVar1 = _strlen(local_58);
  *(undefined4 *)(local_58 + sVar1) = (*(unsigned int *)((unsigned char *)&(s__LDBL128_001aa0b4) + 0));
  acStack_50[sVar1] = s__LDBL128_001aa0b4[8];
  *(undefined4 *)(acStack_54 + sVar1) = (*(unsigned int *)((unsigned char *)&(s__LDBL128_001aa0b4) + 4));
  iVar2 = _NSIsSymbolNameDefinedWithHint(local_58,"libSystem.");
  if (iVar2 == 0) {
    local_58[sVar1] = '\0';
  }
  _NSLookupAndBindSymbolWithHint(local_58,"libSystem.");
  _NSAddressOfSymbol();
  return;
}

/* FUN_001cd7bc @ 0x1cd7bc (28 bytes) */
int FUN_001cd7bc()
{
  return "pseudo";
}

/* FUN_001cd7ec @ 0x1cd7ec (36 bytes) */
int FUN_001cd7ec(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001e9a40;
  return;
}

/* FUN_001cd810 @ 0x1cd810 (36 bytes) */
int FUN_001cd810(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e8b48 + 8;
  return;
}

/* FUN_001cd834 @ 0x1cd834 (56 bytes) */
int FUN_001cd834(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e8b48 + 8;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  FUN_00193cc0(param_1[-1],param_1 + -1);
  return;
}

/* FUN_001cd86c @ 0x1cd86c (68 bytes) */
int FUN_001cd86c(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e8b4c;
  *param_1 = PTR_DAT_001e8b50 + 8;
  puVar1 = PTR_DAT_001e8b48;
  *param_1 = puVar2 + 8;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001cd8b0 @ 0x1cd8b0 (88 bytes) */
int FUN_001cd8b0(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e8b4c;
  *param_1 = PTR_DAT_001e8b50 + 8;
  puVar1 = PTR_DAT_001e8b48;
  *param_1 = puVar2 + 8;
  *param_1 = puVar1 + 8;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  FUN_00193cc0(param_1[-1],param_1 + -1);
  return;
}

/* FUN_001cd908 @ 0x1cd908 (104 bytes) */
int FUN_001cd908(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *param_1 = &PTR_FUN_001e9998;
  *param_1 = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *param_1 = PTR_DAT_001e8b4c + 8;
  *param_1 = puVar1;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  FUN_00193cc0(param_1[-1],param_1 + -1);
  return;
}

/* FUN_001cd970 @ 0x1cd970 (84 bytes) */
int FUN_001cd970(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *param_1 = &PTR_FUN_001e97a0;
  *param_1 = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *param_1 = PTR_DAT_001e8b4c + 8;
  *param_1 = puVar1;
  return;
}

/* FUN_001cd9c4 @ 0x1cd9c4 (104 bytes) */
int FUN_001cd9c4(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *param_1 = &PTR_FUN_001e97a0;
  *param_1 = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *param_1 = PTR_DAT_001e8b4c + 8;
  *param_1 = puVar1;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  FUN_00193cc0(param_1[-1],param_1 + -1);
  return;
}

/* FUN_001cda2c @ 0x1cda2c (84 bytes) */
int FUN_001cda2c(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *param_1 = &PTR_FUN_001e9848;
  *param_1 = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *param_1 = PTR_DAT_001e8b4c + 8;
  *param_1 = puVar1;
  return;
}

/* FUN_001cda80 @ 0x1cda80 (104 bytes) */
int FUN_001cda80(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *param_1 = &PTR_FUN_001e9848;
  *param_1 = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *param_1 = PTR_DAT_001e8b4c + 8;
  *param_1 = puVar1;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  FUN_00193cc0(param_1[-1],param_1 + -1);
  return;
}

/* FUN_001cdae8 @ 0x1cdae8 (84 bytes) */
int FUN_001cdae8(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *param_1 = &PTR_FUN_001e98f0;
  *param_1 = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *param_1 = PTR_DAT_001e8b4c + 8;
  *param_1 = puVar1;
  return;
}

/* FUN_001cdb3c @ 0x1cdb3c (104 bytes) */
int FUN_001cdb3c(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *param_1 = &PTR_FUN_001e98f0;
  *param_1 = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *param_1 = PTR_DAT_001e8b4c + 8;
  *param_1 = puVar1;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  FUN_00193cc0(param_1[-1],param_1 + -1);
  return;
}

/* FUN_001cdba4 @ 0x1cdba4 (84 bytes) */
int FUN_001cdba4(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *param_1 = &PTR_FUN_001e9998;
  *param_1 = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *param_1 = PTR_DAT_001e8b4c + 8;
  *param_1 = puVar1;
  return;
}

/* FUN_001cdc64 @ 0x1cdc64 (28 bytes) */
int FUN_001cdc64()
{
  return "SIMPLE";
}

/* FUN_001cdc88 @ 0x1cdc88 (28 bytes) */
int FUN_001cdc88()
{
  return "ENTRY";
}

/* FUN_001cdcac @ 0x1cdcac (28 bytes) */
int FUN_001cdcac()
{
  return "ANY";
}

/* FUN_001cdcd0 @ 0x1cdcd0 (28 bytes) */
int FUN_001cdcd0()
{
  return "EXIT";
}

/* FUN_001cdcfc @ 0x1cdcfc (28 bytes) */
int FUN_001cdcfc()
{
  return "LOOP_FOOTER";
}

/* FUN_001cdd20 @ 0x1cdd20 (28 bytes) */
int FUN_001cdd20()
{
  return "POST_LOOP_FOOTER";
}

/* FUN_001cdd44 @ 0x1cdd44 (28 bytes) */
int FUN_001cdd44()
{
  return "IF_HEADER";
}

/* FUN_001cdd60 @ 0x1cdd60 (28 bytes) */
int FUN_001cdd60()
{
  return "IF_HEADER_S";
}

/* FUN_001cdd84 @ 0x1cdd84 (28 bytes) */
int FUN_001cdd84()
{
  return "IF_FOOTER";
}

/* FUN_001cdda8 @ 0x1cdda8 (28 bytes) */
int FUN_001cdda8()
{
  return "IF_FOOTER_S";
}

/* FUN_001cddcc @ 0x1cddcc (28 bytes) */
int FUN_001cddcc()
{
  return "BREAK";
}

/* FUN_001cddf0 @ 0x1cddf0 (28 bytes) */
int FUN_001cddf0()
{
  return "CONTINUE";
}

/* FUN_001cde18 @ 0x1cde18 (28 bytes) */
int FUN_001cde18()
{
  return "FUNC_END";
}

/* FUN_001cde34 @ 0x1cde34 (104 bytes) */
int FUN_001cde34(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001e9f28;
  FUN_000ea270();
  if (param_1 != (undefined4 *)0x0) {
    FUN_00193cc0(param_1[-1],param_1 + -1);
    return;
  }
  return;
}

/* FUN_001cde9c @ 0x1cde9c (36 bytes) */
int FUN_001cde9c(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e8b58 + 8;
  FUN_000ea270();
  return;
}

/* FUN_001cdec0 @ 0x1cdec0 (104 bytes) */
int FUN_001cdec0(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e8b58 + 8;
  FUN_000ea270();
  if (param_1 != (undefined4 *)0x0) {
    FUN_00193cc0(param_1[-1],param_1 + -1);
    return;
  }
  return;
}

/* FUN_001cdf28 @ 0x1cdf28 (36 bytes) */
int FUN_001cdf28(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001e9b60;
  FUN_000ea270();
  return;
}

/* FUN_001cdf4c @ 0x1cdf4c (104 bytes) */
int FUN_001cdf4c(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001e9b60;
  FUN_000ea270();
  if (param_1 != (undefined4 *)0x0) {
    FUN_00193cc0(param_1[-1],param_1 + -1);
    return;
  }
  return;
}

/* FUN_001cdfb4 @ 0x1cdfb4 (36 bytes) */
int FUN_001cdfb4(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001e9bb8;
  FUN_000ea270();
  return;
}

/* FUN_001cdfd8 @ 0x1cdfd8 (104 bytes) */
int FUN_001cdfd8(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001e9bb8;
  FUN_000ea270();
  if (param_1 != (undefined4 *)0x0) {
    FUN_00193cc0(param_1[-1],param_1 + -1);
    return;
  }
  return;
}

/* FUN_001ce040 @ 0x1ce040 (36 bytes) */
int FUN_001ce040(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001e9c10;
  FUN_000ea270();
  return;
}

/* FUN_001ce064 @ 0x1ce064 (104 bytes) */
int FUN_001ce064(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001e9c10;
  FUN_000ea270();
  if (param_1 != (undefined4 *)0x0) {
    FUN_00193cc0(param_1[-1],param_1 + -1);
    return;
  }
  return;
}

/* FUN_001ce0cc @ 0x1ce0cc (36 bytes) */
int FUN_001ce0cc(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001e9c68;
  FUN_000ea270();
  return;
}

/* FUN_001ce0f0 @ 0x1ce0f0 (104 bytes) */
int FUN_001ce0f0(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001e9c68;
  FUN_000ea270();
  if (param_1 != (undefined4 *)0x0) {
    FUN_00193cc0(param_1[-1],param_1 + -1);
    return;
  }
  return;
}

/* FUN_001ce158 @ 0x1ce158 (36 bytes) */
int FUN_001ce158(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001e9cc0;
  FUN_000ea270();
  return;
}

/* FUN_001ce17c @ 0x1ce17c (104 bytes) */
int FUN_001ce17c(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001e9cc0;
  FUN_000ea270();
  if (param_1 != (undefined4 *)0x0) {
    FUN_00193cc0(param_1[-1],param_1 + -1);
    return;
  }
  return;
}

