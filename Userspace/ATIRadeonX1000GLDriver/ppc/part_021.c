#include "decls.h"

/* FUN_001045e4 @ 0x1045e4 (96 bytes) */
int FUN_001045e4(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x54))();
  uVar2 = 0;
  if ((iVar1 != 0) && ((param_1[0x26] == 0x26 || (param_1[0x26] == 0x3a)))) {
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_00104644 @ 0x104644 (88 bytes) */
int FUN_00104644(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x54))();
  if ((iVar1 == 0) || (uVar2 = 1, param_1[0x26] != 0x44)) {
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_0010469c @ 0x10469c (44 bytes) */
int FUN_0010469c(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  *(undefined4 *)(param_1 + 0x94) = param_4;
  *(undefined4 *)(param_1 + 0x98) = param_3;
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x42;
  *(undefined4 *)(param_1 + 0x80) = 0;
  FUN_000ee9ac(param_2,param_1);
  return;
}

/* FUN_001046c8 @ 0x1046c8 (104 bytes) */
int FUN_001046c8(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = param_2 * 0x18 + param_1;
  *(int *)(iVar2 + 0x98) = param_3[1];
  iVar1 = param_3[2];
  *(int **)(iVar2 + 0x8c) = param_3;
  *(int *)(iVar2 + 0x94) = iVar1;
  if (param_2 == 0) {
    uVar3 = (**(code **)(*param_3 + 0x24))(param_3);
    *(undefined4 *)(param_1 + 0x128) = uVar3;
  }
  return;
}

/* FUN_00104730 @ 0x104730 (120 bytes) */
int FUN_00104730(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  FUN_00103d50(param_1,1,param_2[5] & 1);
  FUN_00103d50(param_1,2,(uint)param_2[5] >> 1 & 1);
  uVar1 = *param_2;
  uVar2 = param_2[1];
  uVar4 = param_2[2];
  uVar3 = param_2[3];
  param_1[4] = param_2[4];
  *param_1 = uVar1;
  param_1[1] = uVar2;
  param_1[2] = uVar4;
  param_1[3] = uVar3;
  return;
}

/* FUN_001047a8 @ 0x1047a8 (88 bytes) */
int FUN_001047a8(param_1, param_2)
  int param_1;
  int param_2;
{
  FUN_00103d50(param_1,1,*(uint *)(param_2 + 0x14) & 1);
  FUN_00103d50(param_1,2,*(uint *)(param_2 + 0x14) >> 1 & 1);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  return;
}

/* FUN_00104800 @ 0x104800 (92 bytes) */
int FUN_00104800(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x158) != *(int *)(param_2 + 0x158)) {
    uVar2 = FUN_000e78f8(*(int *)(param_1 + 0x158),*(int *)(param_2 + 0x158));
    return uVar2;
  }
  if (param_1 != param_2) {
    iVar1 = *(int *)(param_2 + 4);
    while( true ) {
      if (iVar1 == 0) {
        return 0;
      }
      if (param_1 == iVar1) break;
      iVar1 = *(int *)(iVar1 + 4);
    }
  }
  return 1;
}

/* FUN_0010485c @ 0x10485c (120 bytes) */
int FUN_0010485c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = ((int (*)())FUN_00104800)();
  iVar2 = param_1;
  if ((iVar1 == 0) && (iVar1 = ((int (*)())FUN_00104800)(param_2,param_1), iVar2 = param_2, iVar1 == 0)) {
    FUN_000e7924(*(undefined4 *)(param_1 + 0x158),*(undefined4 *)(param_2 + 0x158));
    iVar2 = FUN_000e7c98();
    return iVar2;
  }
  return iVar2;
}

/* FUN_001048d4 @ 0x1048d4 (56 bytes) */
int FUN_001048d4(param_1)
  int param_1;
{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x13c);
  uVar1 = ((int (*)())FUN_00103d78)(param_1,3,4);
  *(undefined2 *)(iVar2 + 0x18) = uVar1;
  return;
}

/* FUN_0010490c @ 0x10490c (56 bytes) */
int FUN_0010490c(param_1)
  int param_1;
{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x13c);
  uVar1 = ((int (*)())FUN_00103d78)(param_1,3,4);
  *(undefined2 *)(iVar2 + 0x18) = uVar1;
  return;
}

/* FUN_00104944 @ 0x104944 (56 bytes) */
int FUN_00104944(param_1)
  int param_1;
{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x13c);
  uVar1 = ((int (*)())FUN_00103d78)(param_1,3,4);
  *(undefined2 *)(iVar2 + 0x18) = uVar1;
  return;
}

/* FUN_0010497c @ 0x10497c (36 bytes) */
int FUN_0010497c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x160) - *(int *)(param_2 + 0x478);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  return iVar1 == 1;
}

/* FUN_001049a0 @ 0x1049a0 (36 bytes) */
int FUN_001049a0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x160) - *(int *)(param_2 + 0x478);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  return iVar1 == 2;
}

/* FUN_001049c4 @ 0x1049c4 (36 bytes) */
int FUN_001049c4(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(int *)(param_1 + 0x160) - *(int *)(param_2 + 0x478) < 0 ||
         *(int *)(param_1 + 0x160) == *(int *)(param_2 + 0x478);
}

/* FUN_001049e8 @ 0x1049e8 (172 bytes) */
int FUN_001049e8(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_1[0x21];
  ((int (*)())FUN_001046c8)(param_1,iVar2 + 1,param_2);
  iVar3 = param_1[0x21];
  param_1[0x21] = iVar3 + 1;
  if (((0 < param_1[0x20]) && (param_2 == param_1[0x23])) &&
     (iVar4 = (**(code **)(*param_1 + 0x14))(param_1), iVar1 = DAT_001af9bc, iVar4 < iVar3 + 1)) {
    param_1[5] = param_1[5] | 0x200;
    param_1[(iVar2 + 1) * 6 + 0x27] = iVar1;
  }
  return;
}

/* FUN_00104a94 @ 0x104a94 (80 bytes) */
int FUN_00104a94(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(undefined1 *)(param_1 + 0x130);
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      return *(undefined1 *)(param_1 + 300);
    }
  }
  else {
    if (param_2 == 2) {
      return *(undefined1 *)(param_1 + 0x134);
    }
    if (param_2 == 3) {
      return *(undefined1 *)(param_1 + 0x138);
    }
  }
  return 0;
}

/* FUN_00104ae4 @ 0x104ae4 (136 bytes) */
int FUN_00104ae4(param_1, param_2)
  undefined1 *param_1;
  undefined4 param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  
  iVar3 = 0;
  puVar4 = param_1;
  do {
    iVar2 = ((int (*)())FUN_00104a94)(param_2,iVar3);
    if (iVar2 == 1) {
      *puVar4 = 5;
    }
    else if (iVar2 == 2) {
      *puVar4 = 6;
    }
    else {
      *puVar4 = 4;
    }
    bVar1 = iVar3 != 3;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  return param_1;
}

/* FUN_00104b6c @ 0x104b6c (80 bytes) */
int FUN_00104b6c(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(undefined1 *)(param_1 + 0x131);
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      return *(undefined1 *)(param_1 + 0x12d);
    }
  }
  else {
    if (param_2 == 2) {
      return *(undefined1 *)(param_1 + 0x135);
    }
    if (param_2 == 3) {
      return *(undefined1 *)(param_1 + 0x139);
    }
  }
  return 0;
}

/* FUN_00104bbc @ 0x104bbc (44 bytes) */
int FUN_00104bbc(param_1)
  undefined4 *param_1;
{
  param_1[3] = 0x46;
  param_1[5] = param_1[5] & 0xfffffffc;
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  *param_1 = 0;
  return;
}

/* FUN_00104be8 @ 0x104be8 (16 bytes) */
int FUN_00104be8(param_1, param_2)
  int param_1;
  int param_2;
{
  ((int (*)())FUN_00104bbc)(param_2 * 0x18 + param_1 + 0x8c);
  return;
}

/* FUN_00104bf8 @ 0x104bf8 (324 bytes) */
int FUN_00104bf8(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  ((int (*)())FUN_00104be8)(param_1,0);
  uVar3 = DAT_001af9bc;
  *(undefined4 *)(param_1 + 0x9c) = DAT_001af9c0;
  *(undefined4 *)(param_1 + 0x154) = uVar3;
  *(undefined4 *)(param_1 + 0xc) = 0;
  iVar7 = 1;
  iVar8 = param_1;
  do {
    ((int (*)())FUN_00104be8)(param_1,iVar7);
    *(undefined4 *)(iVar8 + 0xb4) = DAT_001af9bc;
    iVar4 = FUN_0011346c(param_2,param_1);
    if (iVar4 != 0) {
      if (iVar7 == 1) {
        puVar5 = &DAT_001af9d0;
      }
      else {
        puVar5 = &DAT_001af9cc;
      }
      *(undefined4 *)(iVar8 + 0xb4) = *puVar5;
    }
    bVar1 = iVar7 != 4;
    iVar8 = iVar8 + 0x18;
    iVar7 = iVar7 + 1;
  } while (bVar1);
  *(undefined4 *)(param_1 + 0x124) = 0;
  uVar6 = 0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  iVar7 = 4;
  iVar8 = param_1;
  do {
    *(undefined4 *)(iVar8 + 0x1c) = 0;
    uVar2 = uVar6 & 0x3f;
    *(undefined4 *)(iVar8 + 0x20) = 0;
    uVar6 = uVar6 + 1;
    iVar8 = iVar8 + 0x18;
    *(byte *)(param_1 + 0x15c) = *(byte *)(param_1 + 0x15c) & ~(byte)(1 << uVar2);
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(undefined4 *)(param_1 + 0x144) = 0;
  return;
}

/* FUN_00104d3c @ 0x104d3c (44 bytes) */
int FUN_00104d3c(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(*(int *)(param_1 + 0x84) * 0x18 + param_1 + 0x90);
  *(undefined4 *)(param_2 + 0x10) =
       *(undefined4 *)(*(int *)(param_1 + 0x84) * 0x18 + param_1 + 0x9c);
  return;
}

/* FUN_00104d68 @ 0x104d68 (184 bytes) */
int FUN_00104d68(param_1, param_2)
  int *param_1;
  char *param_2;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  piVar3 = param_1 + 0x27;
  do {
    if (*param_2 == '\0') {
      *(undefined1 *)piVar3 = 1;
      for (iVar5 = 1; iVar2 = (**(code **)(*param_1 + 0x14))(param_1), iVar5 <= iVar2;
          iVar5 = iVar5 + 1) {
        (**(code **)(*param_1 + 0x88))(param_1,iVar5,iVar4,4);
      }
    }
    else {
      *(undefined1 *)piVar3 = 0;
    }
    bVar1 = iVar4 != 3;
    piVar3 = (int *)((int)piVar3 + 1);
    param_2 = param_2 + 1;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  return;
}

/* FUN_00104e20 @ 0x104e20 (196 bytes) */
int FUN_00104e20(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x98);
  if (iVar1 == 0xc) {
    FUN_000f4d80(*(undefined4 *)(*(int *)(param_3 + 0x6c4) + 0x3ac),param_1);
    iVar1 = *(int *)(param_1 + 0x98);
  }
  if ((iVar1 != 2) && (iVar1 != 0x33)) {
    iVar3 = *(int *)(param_1 + 4);
    iVar1 = *(int *)(*(int *)(param_3 + 0x6c4) + 0x3a0);
    if (param_1 == *(int *)(iVar1 + 300)) {
      *(int *)(iVar1 + 300) = iVar3;
    }
    uVar2 = *(uint *)(param_1 + 0x14);
    if ((((uVar2 & 4) == 0) && (iVar3 != 0)) && ((*(uint *)(iVar3 + 0x14) & 4) != 0)) {
      *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffffffb;
      uVar2 = *(uint *)(param_1 + 0x14);
    }
    *(uint *)(param_1 + 0x14) = uVar2 & 0xfffffffe;
    FUN_0019401c(param_1);
    return;
  }
  return;
}

/* FUN_00104ee4 @ 0x104ee4 (80 bytes) */
int FUN_00104ee4(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(undefined1 *)(param_1 + 0x131);
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      return *(undefined1 *)(param_1 + 0x12d);
    }
  }
  else {
    if (param_2 == 2) {
      return *(undefined1 *)(param_1 + 0x135);
    }
    if (param_2 == 3) {
      return *(undefined1 *)(param_1 + 0x139);
    }
  }
  return 0;
}

/* FUN_00104f34 @ 0x104f34 (156 bytes) */
int FUN_00104f34(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 8);
    if (iVar1 == 0x2b) {
      uVar2 = FUN_00112f54(0xa6);
      *(undefined4 *)(param_1 + 0x88) = uVar2;
    }
    else if (iVar1 == 99) {
      uVar2 = FUN_00112f54(100);
      *(undefined4 *)(param_1 + 0x88) = uVar2;
    }
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 8);
    if (iVar1 == 0xa6) {
      uVar2 = FUN_00112f54(0x2b);
      *(undefined4 *)(param_1 + 0x88) = uVar2;
    }
    else if (iVar1 == 100) {
      uVar2 = FUN_00112f54(99);
      *(undefined4 *)(param_1 + 0x88) = uVar2;
    }
  }
  return;
}

/* FUN_00104fd0 @ 0x104fd0 (92 bytes) */
int FUN_00104fd0(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 8);
  if (iVar1 < 0xae) {
    if ((0xaa < iVar1) || ((0x23 < iVar1 && ((iVar1 < 0x27 || (iVar1 == 0x9d)))))) {
      return 1;
    }
  }
  else if (0xeb < iVar1) {
    if (iVar1 < 0xef) {
      return 1;
    }
    if (iVar1 - 0xf2U < 3) {
      return 1;
    }
  }
  return 0;
}

/* FUN_0010502c @ 0x10502c (332 bytes) */
int FUN_0010502c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  bool bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  param_1[0x1f] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = &PTR_FUN_001e9fc8;
  iVar4 = 5;
  puVar3 = param_1 + 0x23;
  do {
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[5] = 0;
    puVar3 = puVar3 + 6;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = *(int *)(param_3 + 0x324);
  param_1[0x53] = iVar4;
  *(int *)(param_3 + 0x324) = iVar4 + 1;
  param_1[0x58] = 0;
  iVar4 = 0;
  param_1[0x54] = 0;
  param_1[0x56] = 0;
  *(undefined1 *)(param_1 + 0x57) = 0;
  puVar3 = param_1;
  do {
    bVar1 = iVar4 != 1;
    puVar3[5] = 0;
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (bVar1);
  uVar2 = FUN_00112f54(param_2);
  param_1[0x22] = uVar2;
  param_1[5] = param_1[5] | 1;
  ((int (*)())FUN_00104bf8)(param_1,param_3);
  (*(code *)**(undefined4 **)param_1[0x22])((undefined4 *)param_1[0x22],param_1,param_3);
  if ((*(uint *)(*(int *)(param_3 + 0x6c4) + 0x30) & 0x80) != 0) {
    uVar2 = *(undefined4 *)(param_3 + 0x378);
    puVar3 = (undefined4 *)FUN_00193e18(uVar2,0x14);
    *puVar3 = uVar2;
    puVar3[1] = 2;
    puVar3[2] = 0;
    puVar3[4] = uVar2;
    uVar2 = FUN_00193e18(uVar2,8);
    puVar3[3] = uVar2;
    param_1[4] = puVar3 + 1;
  }
  return;
}

/* FUN_001051b0 @ 0x1051b0 (332 bytes) */
int FUN_001051b0(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  bool bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  param_1[0x1f] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = &PTR_FUN_001e9fc8;
  iVar4 = 5;
  puVar3 = param_1 + 0x23;
  do {
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[5] = 0;
    puVar3 = puVar3 + 6;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = *(int *)(param_3 + 0x324);
  param_1[0x53] = iVar4;
  *(int *)(param_3 + 0x324) = iVar4 + 1;
  param_1[0x58] = 0;
  iVar4 = 0;
  param_1[0x54] = 0;
  param_1[0x56] = 0;
  *(undefined1 *)(param_1 + 0x57) = 0;
  puVar3 = param_1;
  do {
    bVar1 = iVar4 != 1;
    puVar3[5] = 0;
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (bVar1);
  uVar2 = FUN_00112f54(param_2);
  param_1[0x22] = uVar2;
  param_1[5] = param_1[5] | 1;
  ((int (*)())FUN_00104bf8)(param_1,param_3);
  (*(code *)**(undefined4 **)param_1[0x22])((undefined4 *)param_1[0x22],param_1,param_3);
  if ((*(uint *)(*(int *)(param_3 + 0x6c4) + 0x30) & 0x80) != 0) {
    uVar2 = *(undefined4 *)(param_3 + 0x378);
    puVar3 = (undefined4 *)FUN_00193e18(uVar2,0x14);
    *puVar3 = uVar2;
    puVar3[1] = 2;
    puVar3[2] = 0;
    puVar3[4] = uVar2;
    uVar2 = FUN_00193e18(uVar2,8);
    puVar3[3] = uVar2;
    param_1[4] = puVar3 + 1;
  }
  return;
}

/* FUN_00105334 @ 0x105334 (408 bytes) */
int FUN_00105334(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint *puVar6;
  
  if (param_2 < 5) {
    *(undefined4 *)(param_2 * 0x18 + param_1 + 0x90) = param_3;
  }
  else {
    puVar6 = *(uint **)(param_1 + 0x118);
    if (puVar6 == (uint *)0x0) {
      uVar4 = *(undefined4 *)(param_4 + 0x374);
      puVar1 = (undefined4 *)FUN_00193e18(uVar4,0x14);
      puVar6 = puVar1 + 1;
      *puVar1 = uVar4;
      puVar1[1] = 2;
      puVar1[2] = 0;
      puVar1[4] = uVar4;
      uVar4 = FUN_00193e18(uVar4,8);
      puVar1[3] = uVar4;
      *(uint **)(param_1 + 0x118) = puVar6;
    }
    if ((int)puVar6[1] < (int)(param_2 - 4U)) {
      uVar4 = *(undefined4 *)(param_4 + 0x374);
      puVar1 = (undefined4 *)FUN_00193e18(uVar4,0x1c);
      *puVar1 = uVar4;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[6] = 0;
      puVar6 = *(uint **)(param_1 + 0x118);
      uVar5 = puVar6[1];
      if (uVar5 < *puVar6) {
        _memset((void *)(uVar5 * 4 + puVar6[2]),0,4);
        piVar2 = (int *)(uVar5 * 4 + puVar6[2]);
        puVar6[1] = uVar5 + 1;
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar6,uVar5);
      }
      *piVar2 = (int)(puVar1 + 1);
      FUN_00103e84(puVar1 + 1,param_2);
      puVar6 = *(uint **)(param_1 + 0x118);
    }
    uVar5 = param_2 - 5;
    if (uVar5 < *puVar6) {
      uVar3 = puVar6[1];
      if (uVar3 <= uVar5) {
        _memset((void *)(uVar3 * 4 + puVar6[2]),0,(uVar5 - uVar3) * 4 + 4);
        puVar6[1] = param_2 - 4U;
      }
      piVar2 = (int *)(uVar5 * 4 + puVar6[2]);
    }
    else {
      piVar2 = (int *)FUN_0019423c(puVar6,uVar5);
    }
    *(undefined4 *)(*piVar2 + 4) = param_3;
  }
  return;
}

/* FUN_001054ec @ 0x1054ec (168 bytes) */
int FUN_001054ec(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  uint *puVar5;
  
  if (param_2 < 5) {
    iVar1 = param_2 * 0x18 + param_1 + 0x8c;
  }
  else {
    puVar5 = *(uint **)(param_1 + 0x118);
    uVar4 = param_2 - 5;
    if (uVar4 < *puVar5) {
      uVar2 = puVar5[1];
      if (uVar2 <= uVar4) {
        _memset((void *)(uVar2 * 4 + puVar5[2]),0,(uVar4 - uVar2) * 4 + 4);
        puVar5[1] = param_2 - 4;
      }
      piVar3 = (int *)(uVar4 * 4 + puVar5[2]);
    }
    else {
      piVar3 = (int *)FUN_0019423c(puVar5,uVar4);
    }
    iVar1 = *piVar3;
  }
  return iVar1;
}

/* FUN_00105594 @ 0x105594 (56 bytes) */
int FUN_00105594()
{
  int iVar1;
  
  iVar1 = ((int (*)())FUN_001054ec)();
  if ((iVar1 == 0) || (iVar1 = *(int *)(iVar1 + 4), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}

/* FUN_001055cc @ 0x1055cc (128 bytes) */
int FUN_001055cc(param_1)
  int *param_1;
{
  int iVar1;
  bool bVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x54))();
  bVar2 = false;
  if (iVar1 != 0) {
    iVar1 = ((int (*)())FUN_00105594)(param_1,1);
    if (iVar1 == 0) {
      bVar2 = param_1[0x2c] == 0x2a;
    }
    else {
      bVar2 = *(int *)(iVar1 + 0x98) == 0x2a;
    }
  }
  return bVar2;
}

/* FUN_0010564c @ 0x10564c (584 bytes) */
int FUN_0010564c(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = FUN_00104054(param_1,*(undefined4 *)(param_2 + 0x6c4));
  uVar2 = 0;
  if (iVar1 == 0) {
    if (param_3 == 0) {
      iVar1 = param_1[0x21];
      iVar4 = 1;
      if (0 < iVar1) {
        do {
          iVar7 = ((int (*)())FUN_00105594)(param_1,iVar4);
          iVar1 = param_1[0x21];
          iVar4 = iVar4 + 1;
          *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + -1;
        } while (iVar4 <= iVar1);
      }
    }
    else {
      iVar1 = param_1[0x21];
    }
    if (0 < iVar1) {
      iVar1 = 1;
      do {
        piVar3 = (int *)((int (*)())FUN_00105594)(param_1,iVar1);
        iVar4 = (**(code **)(*piVar3 + 0x5c))();
        if ((iVar4 != 0) || (iVar4 = (**(code **)(*piVar3 + 0x60))(piVar3), iVar4 != 0)) {
          iVar7 = 1;
          iVar4 = FUN_00104054(piVar3,*(undefined4 *)(param_2 + 0x6c4));
          if (iVar4 == 0) {
            for (; iVar4 = (**(code **)(*piVar3 + 0x14))(piVar3), iVar7 <= iVar4; iVar7 = iVar7 + 1)
            {
              piVar5 = (int *)((int (*)())FUN_00105594)(piVar3,iVar7);
              piVar5[0x58] = piVar5[0x58] + -1;
              iVar4 = (**(code **)(*piVar5 + 0x5c))();
              if ((iVar4 != 0) &&
                 (iVar4 = FUN_00104054(piVar5,*(undefined4 *)(param_2 + 0x6c4)), iVar4 == 0)) {
                (**(code **)(*piVar3 + 0x60))(piVar3);
                for (iVar4 = 1; iVar6 = (**(code **)(*piVar5 + 0x14))(piVar5), iVar4 <= iVar6;
                    iVar4 = iVar4 + 1) {
                  iVar6 = ((int (*)())FUN_00105594)(piVar5,iVar4);
                  *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + -1;
                }
                (**(code **)(*piVar5 + 0xc))(piVar5,param_3,param_2);
              }
            }
            (**(code **)(*piVar3 + 0xc))(piVar3,param_3,param_2);
          }
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 <= param_1[0x21]);
    }
    (**(code **)(*param_1 + 0xc))(param_1,param_3,param_2);
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_00105894 @ 0x105894 (20 bytes) */
int FUN_00105894(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(int *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + -1;
  ((int (*)())FUN_0010564c)(param_1,param_2,0);
  return;
}

/* FUN_001058a8 @ 0x1058a8 (136 bytes) */
int FUN_001058a8(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  if (((*(uint *)(param_2 + 0x30) & 0x80) != 0) && (iVar2 = 1, 0 < *(int *)(param_1 + 0x84))) {
    do {
      iVar1 = ((int (*)())FUN_00105594)(param_1,iVar2);
      if (iVar1 != 0) {
        iVar1 = ((int (*)())FUN_00105594)(param_1,iVar2);
        *(int *)(iVar1 + 0x160) = *(int *)(iVar1 + 0x160) + -1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= *(int *)(param_1 + 0x84));
  }
  return;
}

/* FUN_00105930 @ 0x105930 (276 bytes) */
int FUN_00105930(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  
  if (((*(uint *)(param_2 + 0x30) & 0x80) != 0) && (iVar4 = 1, 0 < *(int *)(param_1 + 0x84))) {
    do {
      iVar1 = ((int (*)())FUN_00105594)(param_1,iVar4);
      if (iVar1 != 0) {
        iVar1 = ((int (*)())FUN_00105594)(param_1,iVar4);
        puVar6 = *(uint **)(iVar1 + 0x10);
        uVar2 = puVar6[1];
        if (0 < (int)uVar2) {
          uVar5 = 0;
          do {
            if (uVar5 < *puVar6) {
              if (uVar2 <= uVar5) {
                _memset((void *)(uVar2 * 4 + puVar6[2]),0,(uVar5 - uVar2) * 4 + 4);
                puVar6[1] = uVar5 + 1;
              }
              piVar3 = (int *)(uVar5 * 4 + puVar6[2]);
            }
            else {
              piVar3 = (int *)FUN_0019423c(puVar6,uVar5);
            }
            if (param_1 == *piVar3) {
              FUN_00194208(puVar6,uVar5);
              break;
            }
            uVar2 = puVar6[1];
            uVar5 = uVar5 + 1;
          } while ((int)uVar5 < (int)uVar2);
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= *(int *)(param_1 + 0x84));
  }
  return;
}

/* FUN_00105a44 @ 0x105a44 (224 bytes) */
int FUN_00105a44(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (**(code **)(*param_1 + 0x34))();
  if (iVar2 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1);
  }
  ((int (*)())FUN_00105930)(param_1,*(undefined4 *)(param_2 + 0x6c4));
  iVar3 = param_1[1];
  iVar2 = (**(code **)(*param_1 + 0x40))(param_1);
  if ((iVar2 != 0) &&
     (iVar2 = *(int *)(*(int *)(param_2 + 0x6c4) + 0x3a0), param_1 == *(int **)(iVar2 + 300))) {
    *(int *)(iVar2 + 300) = iVar3;
  }
  uVar1 = param_1[5];
  if ((((uVar1 & 4) == 0) && (iVar3 != 0)) && ((*(uint *)(iVar3 + 0x14) & 4) != 0)) {
    *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffffffb;
    uVar1 = param_1[5];
  }
  param_1[5] = uVar1 & 0xfffffffe;
  FUN_0019401c(param_1);
  return;
}

/* FUN_00105b24 @ 0x105b24 (88 bytes) */
int FUN_00105b24(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if ((*(uint *)(param_2 + 0x30) & 0x80) != 0) {
    ((int (*)())FUN_00105930)();
    ((int (*)())FUN_001058a8)(param_1,param_2);
    return;
  }
  return;
}

/* FUN_00105b7c @ 0x105b7c (224 bytes) */
int FUN_00105b7c(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (**(code **)(*param_1 + 0x34))();
  if (iVar2 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1);
  }
  ((int (*)())FUN_00105b24)(param_1,*(undefined4 *)(param_3 + 0x6c4));
  iVar3 = param_1[1];
  iVar2 = (**(code **)(*param_1 + 0x40))(param_1);
  if ((iVar2 != 0) &&
     (iVar2 = *(int *)(*(int *)(param_3 + 0x6c4) + 0x3a0), param_1 == *(int **)(iVar2 + 300))) {
    *(int *)(iVar2 + 300) = iVar3;
  }
  uVar1 = param_1[5];
  if ((((uVar1 & 4) == 0) && (iVar3 != 0)) && ((*(uint *)(iVar3 + 0x14) & 4) != 0)) {
    *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffffffb;
    uVar1 = param_1[5];
  }
  param_1[5] = uVar1 & 0xfffffffe;
  FUN_0019401c(param_1);
  return;
}

/* FUN_00105c5c @ 0x105c5c (168 bytes) */
int FUN_00105c5c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  while( true ) {
    if (param_2 == 0) {
      return *(undefined4 *)(param_1 + 0x128);
    }
    iVar1 = ((int (*)())FUN_00105594)();
    if (iVar1 == 0) break;
    param_1 = ((int (*)())FUN_00105594)(param_1,param_2);
    param_2 = 0;
  }
  piVar3 = *(int **)(param_2 * 0x18 + param_1 + 0x8c);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
                    
                    
  uVar2 = (**(code **)(*piVar3 + 0x24))(piVar3);
  return uVar2;
}

/* FUN_00105d04 @ 0x105d04 (184 bytes) */
int FUN_00105d04(param_1, param_2)
  undefined4 *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_2[5] & 0x200U) == 0) {
    iVar3 = param_2[0x21];
  }
  else {
    iVar3 = param_2[0x21] + -1;
  }
  iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
  do {
    iVar1 = iVar1 + 1;
    if (iVar3 < iVar1) {
      *param_1 = DAT_001af9bc;
      return param_1;
    }
    iVar2 = ((int (*)())FUN_001054ec)(param_2,iVar1);
  } while ((*(uint *)(*(int *)(iVar2 + 4) + 0x14) & 0x80000) == 0);
  *param_1 = *(undefined4 *)(iVar2 + 0x10);
  return param_1;
}

/* FUN_00105dbc @ 0x105dbc (152 bytes) */
int FUN_00105dbc(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined1 uVar1;
  int iVar2;
  
  if ((param_2 < 1) || (iVar2 = ((int (*)())FUN_00105594)(), iVar2 == 0)) {
    iVar2 = ((int (*)())FUN_001054ec)(param_1,param_2);
    iVar2 = *(int *)(iVar2 + 0xc);
  }
  else {
    iVar2 = ((int (*)())FUN_00105594)(param_1,param_2);
    iVar2 = *(int *)(iVar2 + 0x98);
  }
  uVar1 = 2;
  if (PTR_PTR_001e8c60[iVar2 * 0x10 + 9] != '\x01') {
    uVar1 = PTR_PTR_001e8c60[iVar2 * 0x10 + 9] == '\x02';
  }
  return uVar1;
}

/* FUN_00105e54 @ 0x105e54 (72 bytes) */
int FUN_00105e54(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  
  uVar1 = ((int (*)())FUN_001054ec)(param_3,param_4);
  ((int (*)())FUN_00104730)(param_2 * 0x18 + param_1 + 0x8c,uVar1);
  return;
}

/* FUN_00105e9c @ 0x105e9c (104 bytes) */
int FUN_00105e9c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x84) + 1;
  *(int *)(param_1 + 0x84) = iVar1;
  if ((*(uint *)(param_1 + 0x14) & 0x200) != 0) {
    ((int (*)())FUN_00105e54)(param_1,iVar1,param_1);
    iVar1 = *(int *)(param_1 + 0x84) + -1;
  }
  ((int (*)())FUN_001046c8)(param_1,iVar1,param_2);
  return;
}

/* FUN_00105f04 @ 0x105f04 (256 bytes) */
int FUN_00105f04(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  if (((*(uint *)(param_2 + 0x30) & 0x80) != 0) && (iVar3 = 1, 0 < *(int *)(param_1 + 0x84))) {
    do {
      iVar1 = ((int (*)())FUN_00105594)(param_1,iVar3);
      if (iVar1 != 0) {
        iVar1 = ((int (*)())FUN_00105594)(param_1,iVar3);
        puVar5 = *(uint **)(iVar1 + 0x10);
        uVar4 = puVar5[1];
        if (uVar4 < *puVar5) {
          _memset((void *)(uVar4 * 4 + puVar5[2]),0,4);
          piVar2 = (int *)(uVar4 * 4 + puVar5[2]);
          puVar5[1] = uVar4 + 1;
        }
        else {
          piVar2 = (int *)FUN_0019423c(puVar5,uVar4);
        }
        *piVar2 = param_1;
        iVar1 = ((int (*)())FUN_00105594)(param_1,iVar3);
        if (*(int *)(param_2 + 0x478) < *(int *)(iVar1 + 0x160)) {
          *(int *)(iVar1 + 0x160) = *(int *)(iVar1 + 0x160) + 1;
        }
        else {
          *(int *)(iVar1 + 0x160) = *(int *)(param_2 + 0x478) + 1;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= *(int *)(param_1 + 0x84));
  }
  return;
}

/* FUN_00106004 @ 0x106004 (428 bytes) */
int FUN_00106004(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  
  iVar4 = *(int *)(param_5 + 0x6c4);
  if ((param_4 != 0) && (iVar1 = ((int (*)())FUN_00105594)(), iVar1 != 0)) {
    iVar1 = ((int (*)())FUN_00105594)(param_1,param_2);
    puVar6 = *(uint **)(iVar1 + 0x10);
    uVar2 = puVar6[1];
    if (0 < (int)uVar2) {
      uVar5 = 0;
      do {
        if (uVar5 < *puVar6) {
          if (uVar2 <= uVar5) {
            _memset((void *)(uVar2 * 4 + puVar6[2]),0,(uVar5 - uVar2) * 4 + 4);
            puVar6[1] = uVar5 + 1;
          }
          piVar3 = (int *)(uVar5 * 4 + puVar6[2]);
        }
        else {
          piVar3 = (int *)FUN_0019423c(puVar6,uVar5);
        }
        if (param_1 == *piVar3) {
          FUN_00194208(puVar6,uVar5);
          iVar1 = ((int (*)())FUN_00105594)(param_1,param_2);
          *(int *)(iVar1 + 0x160) = *(int *)(iVar1 + 0x160) + -1;
          break;
        }
        uVar2 = puVar6[1];
        uVar5 = uVar5 + 1;
      } while ((int)uVar5 < (int)uVar2);
    }
  }
  ((int (*)())FUN_00105334)(param_1,param_2,param_3,param_5);
  if ((param_4 != 0) && (param_3 != 0)) {
    puVar6 = *(uint **)(param_3 + 0x10);
    uVar2 = puVar6[1];
    if (uVar2 < *puVar6) {
      _memset((void *)(uVar2 * 4 + puVar6[2]),0,4);
      piVar3 = (int *)(uVar2 * 4 + puVar6[2]);
      puVar6[1] = uVar2 + 1;
    }
    else {
      piVar3 = (int *)FUN_0019423c(puVar6,uVar2);
    }
    *piVar3 = param_1;
    iVar4 = *(int *)(iVar4 + 0x478);
    if (iVar4 < *(int *)(param_3 + 0x160)) {
      *(int *)(param_3 + 0x160) = *(int *)(param_3 + 0x160) + 1;
    }
    else {
      *(int *)(param_3 + 0x160) = iVar4 + 1;
    }
  }
  return;
}

/* FUN_001061b0 @ 0x1061b0 (128 bytes) */
int FUN_001061b0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x84);
  iVar2 = *(int *)(param_2 + 0x8c);
  if (0 < iVar1) {
    iVar3 = 1;
    iVar4 = param_1;
    do {
      if (iVar2 == *(int *)(iVar4 + 0xa4)) {
        ((int (*)())FUN_00106004)(param_1,iVar3,param_2,0,param_3);
        iVar1 = *(int *)(param_1 + 0x84);
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x18;
    } while (iVar3 <= iVar1);
  }
  return;
}

/* FUN_00106230 @ 0x106230 (144 bytes) */
int FUN_00106230(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_6 + 0x30c) + 0x11c))
                    (*(int **)(param_6 + 0x30c),param_1,param_2,param_3,param_4,param_5,param_6);
  if (iVar1 != 0) {
    ((int (*)())FUN_00106004)(param_1,param_2,param_3,0,param_6);
  }
  return iVar1 != 0;
}

/* FUN_001062c0 @ 0x1062c0 (412 bytes) */
int FUN_001062c0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  
  if (param_2 < 5) {
    iVar1 = param_2 * 0x18 + param_1 + 0x8c;
  }
  else {
    puVar7 = *(uint **)(param_1 + 0x118);
    if (puVar7 == (uint *)0x0) {
      uVar5 = *(undefined4 *)(param_4 + 0x374);
      puVar2 = (undefined4 *)FUN_00193e18(uVar5,0x14);
      puVar7 = puVar2 + 1;
      *puVar2 = uVar5;
      puVar2[1] = 2;
      puVar2[2] = 0;
      puVar2[4] = uVar5;
      uVar5 = FUN_00193e18(uVar5,8);
      puVar2[3] = uVar5;
      *(uint **)(param_1 + 0x118) = puVar7;
    }
    if ((int)puVar7[1] < (int)(param_2 - 4U)) {
      uVar5 = *(undefined4 *)(param_4 + 0x374);
      puVar2 = (undefined4 *)FUN_00193e18(uVar5,0x1c);
      *puVar2 = uVar5;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[6] = 0;
      puVar7 = *(uint **)(param_1 + 0x118);
      uVar6 = puVar7[1];
      if (uVar6 < *puVar7) {
        _memset((void *)(uVar6 * 4 + puVar7[2]),0,4);
        piVar3 = (int *)(uVar6 * 4 + puVar7[2]);
        puVar7[1] = uVar6 + 1;
      }
      else {
        piVar3 = (int *)FUN_0019423c(puVar7,uVar6);
      }
      *piVar3 = (int)(puVar2 + 1);
      FUN_00103e84(puVar2 + 1,param_2);
      puVar7 = *(uint **)(param_1 + 0x118);
    }
    uVar6 = param_2 - 5;
    if (uVar6 < *puVar7) {
      uVar4 = puVar7[1];
      if (uVar4 <= uVar6) {
        _memset((void *)(uVar4 * 4 + puVar7[2]),0,(uVar6 - uVar4) * 4 + 4);
        puVar7[1] = param_2 - 4U;
      }
      piVar3 = (int *)(uVar6 * 4 + puVar7[2]);
    }
    else {
      piVar3 = (int *)FUN_0019423c(puVar7,uVar6);
    }
    iVar1 = *piVar3;
  }
  ((int (*)())FUN_00104730)(iVar1,param_3);
  return;
}

/* FUN_0010647c @ 0x10647c (620 bytes) */
int FUN_0010647c(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30 [4];
  
  if (0 < param_1[0x20]) {
    iVar5 = 0;
    do {
      iVar3 = (**(code **)(*param_1 + 0x24))(param_1);
      if (iVar3 != 0) {
        ((int (*)())FUN_001054ec)(param_1,iVar5);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_1[0x20]);
  }
  iVar5 = *(int *)(param_2 + 0x6c4);
  if (((*(uint *)(iVar5 + 0x30) & 8) == 0) && (*(int *)(param_1[0x22] + 8) != 0x8e)) {
    iVar3 = ((int (*)())FUN_001054ec)(param_1,0);
    iVar5 = 0;
    local_38 = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = 4;
    do {
      if (*(char *)((int)&local_38 + iVar5) == '\0') {
        iVar5 = 1;
        if (0 < param_1[0x21]) {
          do {
            iVar3 = (**(code **)(*param_1 + 0x24))(param_1);
            if ((iVar3 != 0) || (iVar3 = (**(code **)(*param_1 + 0x28))(param_1), iVar3 != 0)) {
              ((int (*)())FUN_001054ec)(param_1,iVar5);
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 <= param_1[0x21]);
        }
        goto LAB_0010663c;
      }
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar5 = *(int *)(param_2 + 0x6c4);
    if (((*(uint *)(iVar5 + 0x30) & 0x20000) != 0) && (iVar3 = 1, 0 < param_1[0x21])) {
      do {
        iVar5 = ((int (*)())FUN_001054ec)(param_1,iVar3);
        local_34 = *(undefined4 *)(iVar5 + 0x10);
        iVar5 = ((int (*)())FUN_00105594)(param_1,iVar3);
        if (iVar5 != 0) {
          iVar4 = ((int (*)())FUN_001054ec)(iVar5,0);
          iVar6 = 0;
          local_30[0] = *(undefined4 *)(iVar4 + 0x10);
          do {
            uVar2 = (uint)*(byte *)((int)local_30 + iVar6 + -4);
            if (((uVar2 != 4) && (*(char *)((int)local_30 + uVar2) != '\0')) &&
               ((*(uint *)(iVar5 + 0x14) & 0x200) != 0)) {
              ((int (*)())FUN_001054ec)(iVar5,*(undefined4 *)(iVar5 + 0x84));
            }
            bVar1 = iVar6 != 3;
            iVar6 = iVar6 + 1;
          } while (bVar1);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= param_1[0x21]);
LAB_0010663c:
      iVar5 = *(int *)(param_2 + 0x6c4);
    }
  }
  if ((*(uint *)(iVar5 + 0x30) & 0x800) == 0) {
    (**(code **)(*param_1 + 0x68))(param_1);
  }
  if (((param_1[5] & 0x200U) != 0) && ((*(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) & 8) != 0)) {
    ((int (*)())FUN_00105594)(param_1,param_1[0x21]);
  }
  (**(code **)(*param_1 + 100))(param_1);
  return 1;
}

/* FUN_001066e8 @ 0x1066e8 (84 bytes) */
int FUN_001066e8(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = ((int (*)())FUN_001045e4)();
  if (iVar1 != 0) {
    iVar1 = ((int (*)())FUN_001054ec)(param_1,1);
    FUN_000f2c5c(*(undefined4 *)(iVar1 + 0x10));
  }
  ((int (*)())FUN_0010647c)(param_1,param_2);
  return;
}

/* FUN_0010673c @ 0x10673c (68 bytes) */
int FUN_0010673c(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  (**(code **)(*param_1 + 0x14))();
  ((int (*)())FUN_0010647c)(param_1,param_2);
  return;
}

/* FUN_00106780 @ 0x106780 (128 bytes) */
int FUN_00106780(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x84);
  if (0 < iVar1) {
    iVar2 = 1;
    do {
      iVar1 = ((int (*)())FUN_001054ec)(param_1,iVar2);
      iVar2 = iVar2 + 1;
      FUN_000f3190(*(undefined4 *)(iVar1 + 0x10));
      iVar1 = *(int *)(param_1 + 0x84);
    } while (iVar2 <= iVar1);
  }
  if (1 < iVar1) {
    iVar2 = 2;
    do {
      iVar2 = iVar2 + 1;
    } while (iVar2 <= iVar1);
  }
  ((int (*)())FUN_0010647c)(param_1,param_2);
  return;
}

/* FUN_00106804 @ 0x106804 (484 bytes) */
int FUN_00106804(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  
  iVar5 = *(int *)(param_4 + 0x6c4);
  if (param_3 != 0) {
    uVar2 = *(uint *)(param_1 + 0x14);
    if ((uVar2 & 0x200) == 0) goto LAB_00106908;
    iVar3 = ((int (*)())FUN_00105594)(param_1,*(undefined4 *)(param_1 + 0x84));
    if (iVar3 != 0) {
      puVar7 = *(uint **)(iVar3 + 0x10);
      uVar2 = puVar7[1];
      if (0 < (int)uVar2) {
        uVar6 = 0;
        do {
          if (uVar6 < *puVar7) {
            if (uVar2 <= uVar6) {
              _memset((void *)(uVar2 * 4 + puVar7[2]),0,(uVar6 - uVar2) * 4 + 4);
              puVar7[1] = uVar6 + 1;
            }
            piVar4 = (int *)(uVar6 * 4 + puVar7[2]);
          }
          else {
            piVar4 = (int *)FUN_0019423c(puVar7,uVar6);
          }
          if (param_1 == *piVar4) {
            FUN_00194208(puVar7,uVar6);
            uVar2 = *(uint *)(param_1 + 0x14);
            *(int *)(iVar3 + 0x160) = *(int *)(iVar3 + 0x160) + -1;
            goto LAB_00106908;
          }
          uVar2 = puVar7[1];
          uVar6 = uVar6 + 1;
        } while ((int)uVar6 < (int)uVar2);
      }
    }
  }
  uVar2 = *(uint *)(param_1 + 0x14);
LAB_00106908:
  if ((uVar2 & 0x200) == 0) {
    *(uint *)(param_1 + 0x14) = uVar2 | 0x200;
    uVar1 = DAT_001af9c4;
    *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
    iVar3 = ((int (*)())FUN_001054ec)(param_1);
    *(undefined4 *)(iVar3 + 0x10) = uVar1;
  }
  ((int (*)())FUN_00105334)(param_1,*(undefined4 *)(param_1 + 0x84),param_2,param_4);
  if ((param_3 != 0) && (param_2 != 0)) {
    puVar7 = *(uint **)(param_2 + 0x10);
    uVar2 = puVar7[1];
    if (uVar2 < *puVar7) {
      _memset((void *)(uVar2 * 4 + puVar7[2]),0,4);
      piVar4 = (int *)(uVar2 * 4 + puVar7[2]);
      puVar7[1] = uVar2 + 1;
    }
    else {
      piVar4 = (int *)FUN_0019423c(puVar7,uVar2);
    }
    *piVar4 = param_1;
    iVar5 = *(int *)(iVar5 + 0x478);
    if (iVar5 < *(int *)(param_2 + 0x160)) {
      *(int *)(param_2 + 0x160) = *(int *)(param_2 + 0x160) + 1;
    }
    else {
      *(int *)(param_2 + 0x160) = iVar5 + 1;
    }
  }
  return;
}

/* FUN_001069e8 @ 0x1069e8 (352 bytes) */
int FUN_001069e8(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x84);
  iVar3 = iVar2 + 1;
  *(int *)(param_1 + 0x84) = iVar3;
  if ((*(uint *)(param_1 + 0x14) & 0x200) == 0) {
    ((int (*)())FUN_00106004)(param_1,iVar3,param_2,0,param_3);
    uVar1 = DAT_001af9bc;
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x9c) = DAT_001af9bc;
    }
    else {
      iVar2 = ((int (*)())FUN_001054ec)(param_1,iVar3);
      *(undefined4 *)(iVar2 + 0x10) = uVar1;
    }
  }
  else {
    if ((*(uint *)(*(int *)(param_3 + 0x6c4) + 0x30) & 8) == 0) {
      uVar1 = ((int (*)())FUN_00105594)(param_1,iVar2);
      ((int (*)())FUN_00106004)(param_1,iVar3,uVar1,0,param_3);
    }
    else {
      uVar1 = ((int (*)())FUN_00105594)(param_1,iVar2);
      ((int (*)())FUN_00106804)(param_1,uVar1,0,param_3);
    }
    iVar4 = *(int *)(param_1 + 0x84);
    iVar3 = ((int (*)())FUN_001054ec)(param_1,iVar2);
    uVar1 = *(undefined4 *)(iVar3 + 0x10);
    if (iVar4 == 0) {
      *(undefined4 *)(param_1 + 0x9c) = uVar1;
    }
    else {
      iVar3 = ((int (*)())FUN_001054ec)(param_1,iVar4);
      *(undefined4 *)(iVar3 + 0x10) = uVar1;
    }
    ((int (*)())FUN_00106004)(param_1,iVar2,param_2,0,param_3);
    uVar1 = DAT_001af9bc;
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x9c) = DAT_001af9bc;
      iVar3 = 0;
    }
    else {
      iVar3 = ((int (*)())FUN_001054ec)(param_1,iVar2);
      *(undefined4 *)(iVar3 + 0x10) = uVar1;
      iVar3 = iVar2;
    }
  }
  return iVar3;
}

/* FUN_00106b48 @ 0x106b48 (88 bytes) */
int FUN_00106b48(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_00106804)(param_1,*(undefined4 *)(param_2 + 4));
  uVar2 = *(undefined4 *)(param_2 + 0x10);
  if (*(int *)(param_1 + 0x84) == 0) {
    *(undefined4 *)(param_1 + 0x9c) = uVar2;
  }
  else {
    iVar1 = ((int (*)())FUN_001054ec)(param_1);
    *(undefined4 *)(iVar1 + 0x10) = uVar2;
  }
  return;
}

/* FUN_00106ba0 @ 0x106ba0 (276 bytes) */
int FUN_00106ba0(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  if (0 < param_1[0x21]) {
    iVar2 = 1;
    do {
      iVar2 = iVar2 + 1;
    } while (iVar2 <= param_1[0x21]);
  }
  iVar2 = 0;
  do {
    ((int (*)())FUN_001054ec)(param_1,0);
    if (0 < param_1[0x21]) {
      iVar6 = 1;
      do {
        ((int (*)())FUN_001054ec)(param_1,iVar6);
        if ((*(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) & 8) != 0) {
          if (iVar6 != 1) {
            uVar3 = ((int (*)())FUN_00105594)(param_1,iVar6);
            iVar4 = ((int (*)())FUN_001054ec)(param_1,iVar6);
            FUN_0010453c(uVar3,param_2,*(undefined4 *)(iVar4 + 0x10));
          }
          piVar5 = (int *)((int (*)())FUN_00105594)(param_1,iVar6);
          (**(code **)(*piVar5 + 0x60))();
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 <= param_1[0x21]);
    }
    bVar1 = iVar2 != 3;
    iVar2 = iVar2 + 1;
  } while (bVar1);
  (**(code **)(*param_1 + 0x14))(param_1);
  ((int (*)())FUN_0010647c)(param_1,param_2);
  return;
}

/* FUN_00106cb4 @ 0x106cb4 (68 bytes) */
int FUN_00106cb4(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  (**(code **)(*param_1 + 0x14))();
  ((int (*)())FUN_0010647c)(param_1,param_2);
  return;
}

/* FUN_00106cf8 @ 0x106cf8 (772 bytes) */
int FUN_00106cf8(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if ((param_1[5] & 0x200U) != 0) {
    piVar1 = (int *)((int (*)())FUN_00105594)(param_1,param_1[0x21]);
    iVar2 = (**(code **)(*piVar1 + 0x50))();
    if (iVar2 == 0) {
      if (piVar1[0x20] == 0) {
        return 0;
      }
      iVar2 = FUN_00126760(piVar1[0x26]);
      if (iVar2 == 0) {
        return 0;
      }
      if ((piVar1[5] & 2U) != 0) {
        return 0;
      }
      iVar2 = (**(code **)(*piVar1 + 0x50))(piVar1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = thunk_FUN_00134de8(param_2,piVar1);
      iVar3 = thunk_FUN_00134de8(param_2,param_1);
      if (iVar2 != iVar3) {
        return 0;
      }
    }
  }
  iVar2 = (**(code **)(*param_1 + 100))(param_1);
  if (iVar2 != 0) {
    for (iVar2 = 1; iVar3 = (**(code **)(*param_1 + 0x14))(param_1), iVar2 <= iVar3;
        iVar2 = iVar2 + 1) {
      if ((param_1[iVar2 * 6 + 0x28] & 1U) != 0) {
        return 0;
      }
      if ((param_1[iVar2 * 6 + 0x28] & 2U) != 0) {
        return 0;
      }
      iVar3 = FUN_000f31e8(param_1,iVar2);
      if (iVar3 == 0) {
        return 0;
      }
    }
    if ((param_1[0x48] == 0) && (param_1[0x49] == 0)) {
      if ((param_1[0x20] != 0) &&
         (((iVar2 = FUN_00126760(param_1[0x26]), iVar2 != 0 && ((param_1[5] & 2U) == 0)) &&
          (iVar2 = (**(code **)(*param_1 + 0x50))(param_1), iVar2 == 0)))) {
        iVar2 = 4;
        piVar1 = param_1;
        do {
          if (*(byte *)(piVar1 + 0x27) - 2 < 2) {
            return 0;
          }
          piVar1 = (int *)((int)piVar1 + 1);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      ((int (*)())FUN_001054ec)(param_1,0);
      iVar2 = ((int (*)())FUN_00105dbc)(param_1,0);
      if ((((iVar2 == 0) && ((param_1[5] & 2U) == 0)) &&
          ((param_1[0x20] != 0 &&
           ((iVar2 = FUN_00126760(param_1[0x26]), iVar2 != 0 && ((param_1[5] & 2U) == 0)))))) &&
         (iVar2 = (**(code **)(*param_1 + 0x50))(param_1), iVar2 == 0)) {
        piVar1 = (int *)((int (*)())FUN_00105594)(param_1,1);
        iVar2 = (**(code **)(*piVar1 + 0x50))();
        if (iVar2 != 0) {
          return 1;
        }
        piVar1 = (int *)((int (*)())FUN_00105594)(param_1,1);
        if ((((piVar1[0x20] != 0) && (iVar2 = FUN_00126760(piVar1[0x26]), iVar2 != 0)) &&
            ((piVar1[5] & 2U) == 0)) && (iVar2 = (**(code **)(*piVar1 + 0x50))(piVar1), iVar2 == 0))
        {
          uVar4 = ((int (*)())FUN_00105594)(param_1,1);
          iVar2 = thunk_FUN_00134de8(param_2,uVar4);
          iVar3 = thunk_FUN_00134de8(param_2,param_1);
          if (iVar2 == iVar3) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

