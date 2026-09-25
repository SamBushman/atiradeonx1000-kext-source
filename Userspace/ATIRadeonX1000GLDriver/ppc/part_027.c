#include "decls.h"

/* FUN_00103d50 @ 0x103d50 (40 bytes) */
int FUN_00103d50(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  if (param_3 != 0) {
    *(uint *)(param_1 + 0x14) = param_2 | *(uint *)(param_1 + 0x14);
    return;
  }
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & ~param_2;
  return;
}

/* FUN_00103d78 @ 0x103d78 (220 bytes) */
int FUN_00103d78(undefined4 param_1,int param_2,uint param_3,double fparam_1)
{
  float fVar1;
  uint uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  
  uVar2 = 1 << (param_2 - 1U & 0x3f);
  dVar5 = (double)(float)((double)CONCAT44(0x43300000,-uVar2 ^ 0x80000000) - DOUBLE_001aa1e0);
  dVar3 = (double)((float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - DOUBLE_001aa1e0) +
                  FLOAT_001aa114 /
                  (float)((double)CONCAT44(0x43300000,1 << (param_3 - 1 & 0x3f) ^ 0x80000000) -
                         DOUBLE_001aa1e0));
  fVar1 = (float)(dVar3 - fparam_1);
  dVar4 = fparam_1;
  if (fVar1 < 0.0) {
    dVar4 = dVar3;
  }
  if (-fVar1 < 0.0) {
    dVar4 = fparam_1;
  }
  fVar1 = (float)(dVar4 - dVar5);
  dVar3 = dVar4;
  if (fVar1 < 0.0) {
    dVar3 = dVar5;
  }
  if (-fVar1 < 0.0) {
    dVar3 = dVar4;
  }
  return (int)(dVar3 * (double)(float)((double)CONCAT44(0x43300000,
                                                        1 << (param_3 & 0x3f) ^ 0x80000000) -
                                      DOUBLE_001aa1e0));
}

/* FUN_00103e54 @ 0x103e54 (28 bytes) */
double FUN_00103e54( void)
{
  return (double)FLOAT_001aa0d4;
}

/* FUN_00103e70 @ 0x103e70 (16 bytes) */
int FUN_00103e70(param_1)
  uint param_1;
{
  return param_1 < 2;
}

/* FUN_00103e84 @ 0x103e84 (56 bytes) */
int FUN_00103e84(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x10) = DAT_001af9c0;
    return;
  }
  *(undefined4 *)(param_1 + 0x10) = DAT_001af9bc;
  return;
}

/* FUN_00103ebc @ 0x103ebc (92 bytes) */
int FUN_00103ebc(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  
  _memcpy(param_2,param_1,0x164);
  if (param_4 == 0) {
    iVar1 = *(int *)(param_3 + 0x324);
    *(int *)(param_2 + 0x14c) = iVar1;
    *(int *)(param_3 + 0x324) = iVar1 + 1;
  }
  return param_2;
}

/* FUN_00103f18 @ 0x103f18 (44 bytes) */
int FUN_00103f18(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  uint param_3;
{
  *param_2 = param_3;
  if ((param_3 & 1) != 0) {
    param_2[1] = *(uint *)(param_1 + 0x160);
  }
  if ((*param_2 & 2) == 0) {
    return;
  }
  param_2[2] = *(uint *)(param_1 + 0x14c);
  return;
}

/* FUN_00103f44 @ 0x103f44 (64 bytes) */
int FUN_00103f44(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  
  uVar1 = *param_2;
  if ((uVar1 & 1) != 0) {
    *(uint *)(param_1 + 0x160) = param_2[1];
    uVar1 = *param_2;
    param_2[1] = 0;
  }
  if ((uVar1 & 2) != 0) {
    *(uint *)(param_1 + 0x14c) = param_2[2];
  }
  *param_2 = 0;
  param_2[2] = 0;
  return;
}

/* FUN_00103f84 @ 0x103f84 (100 bytes) */
int FUN_00103f84(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_20 = 0;
  local_28 = 0;
  local_24 = 0;
  ((int (*)())FUN_00103f18)(param_1,&local_28,0xffffffff);
  _memcpy(param_1,param_2,0x164);
  ((int (*)())FUN_00103f44)(param_1,&local_28);
  return;
}

/* FUN_00103fe8 @ 0x103fe8 (52 bytes) */
int FUN_00103fe8(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = param_3 * 0x18 + param_2;
  if ((*(int *)(param_1 + 0x94) == *(int *)(iVar1 + 0x94)) &&
     (*(int *)(param_1 + 0x98) == *(int *)(iVar1 + 0x98))) {
    return 1;
  }
  return 0;
}

/* FUN_0010401c @ 0x10401c (56 bytes) */
int FUN_0010401c(param_1)
  int param_1;
{
  FUN_0019401c(param_1);
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
  return;
}

/* FUN_00104054 @ 0x104054 (24 bytes) */
int FUN_00104054(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x160) - *(int *)(param_2 + 0x478);
  if (-1 < iVar1) {
    return iVar1;
  }
  return 0;
}

/* FUN_0010406c @ 0x10406c (68 bytes) */
int FUN_0010406c(param_1)
  int param_1;
{
  if ((*(uint *)(PTR_PTR_001e8c60 + param_1 * 0x10 + 4) & 0x400) != 0) {
    return 0x16;
  }
  if ((*(uint *)(PTR_PTR_001e8c60 + param_1 * 0x10 + 4) & 0x800) == 0) {
    return param_1;
  }
  return 0x15;
}

/* FUN_001040b0 @ 0x1040b0 (84 bytes) */
int FUN_001040b0(param_1)
  int param_1;
{
  if ((*(uint *)(PTR_PTR_001e8c60 + param_1 * 0x10 + 4) & 0x400) != 0) {
    return '\x04';
  }
  if ((*(uint *)(PTR_PTR_001e8c60 + param_1 * 0x10 + 4) & 0x800) != 0) {
    return '\x03';
  }
  return (param_1 == 7) + '\x01';
}

/* FUN_00104104 @ 0x104104 (124 bytes) */
int FUN_00104104(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  uint param_3;
  uint param_4;
{
  if (param_2 == 1) {
    *(uint *)(param_1 + 0x130) = (param_3 & 0xff) << 0x10 | param_4 & 0xffff;
    return;
  }
  if (param_2 < 2) {
    if (param_2 != 0) {
      return;
    }
    *(uint *)(param_1 + 300) = (param_3 & 0xff) << 0x10 | param_4 & 0xffff;
    return;
  }
  if (param_2 == 2) {
    *(uint *)(param_1 + 0x134) = (param_3 & 0xff) << 0x10 | param_4 & 0xffff;
    return;
  }
  if (param_2 != 3) {
    return;
  }
  *(uint *)(param_1 + 0x138) = (param_3 & 0xff) << 0x10 | param_4 & 0xffff;
  return;
}

/* FUN_00104180 @ 0x104180 (80 bytes) */
int FUN_00104180(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(undefined2 *)(param_1 + 0x132);
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      return *(undefined2 *)(param_1 + 0x12e);
    }
  }
  else {
    if (param_2 == 2) {
      return *(undefined2 *)(param_1 + 0x136);
    }
    if (param_2 == 3) {
      return *(undefined2 *)(param_1 + 0x13a);
    }
  }
  return 0;
}

/* FUN_001041d0 @ 0x1041d0 (156 bytes) */
int FUN_001041d0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  uint param_5;
{
  if (param_2 == 1) {
    *(uint *)(param_1 + 0x130) = param_3 << 0x18 | (param_4 & 0xff) << 0x10 | param_5 & 0xffff;
    return;
  }
  if (param_2 < 2) {
    if (param_2 != 0) {
      return;
    }
    *(uint *)(param_1 + 300) = param_3 << 0x18 | (param_4 & 0xff) << 0x10 | param_5 & 0xffff;
    return;
  }
  if (param_2 == 2) {
    *(uint *)(param_1 + 0x134) = param_3 << 0x18 | (param_4 & 0xff) << 0x10 | param_5 & 0xffff;
    return;
  }
  if (param_2 != 3) {
    return;
  }
  *(uint *)(param_1 + 0x138) = param_3 << 0x18 | (param_4 & 0xff) << 0x10 | param_5 & 0xffff;
  return;
}

/* FUN_0010426c @ 0x10426c (80 bytes) */
int FUN_0010426c(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(undefined2 *)(param_1 + 0x132);
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      return *(undefined2 *)(param_1 + 0x12e);
    }
  }
  else {
    if (param_2 == 2) {
      return *(undefined2 *)(param_1 + 0x136);
    }
    if (param_2 == 3) {
      return *(undefined2 *)(param_1 + 0x13a);
    }
  }
  return 0;
}

/* FUN_001042bc @ 0x1042bc (116 bytes) */
int FUN_001042bc(param_1, param_2)
  int *param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  pcVar4 = (char *)((int)param_1 + param_2 + 0xb4);
  iVar3 = 1;
  while( true ) {
    iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
    if (iVar2 < iVar3) {
      return -1;
    }
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 0x18;
    if (cVar1 != '\x04') break;
    iVar3 = iVar3 + 1;
  }
  return iVar3;
}

/* FUN_00104330 @ 0x104330 (52 bytes) */
int FUN_00104330(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0x1f;
  *(undefined4 *)(param_1 + 0x9c) = DAT_001af9c0;
  return;
}

/* FUN_00104364 @ 0x104364 (24 bytes) */
int FUN_00104364(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
{
  *param_2 = 0;
  *param_3 = 0;
  *param_4 = 4;
  return;
}

/* FUN_0010437c @ 0x10437c (36 bytes) */
int FUN_0010437c(param_1, param_2)
  int param_1;
  int param_2;
{
  if (((*(uint *)(param_2 + 0x30) & 0x4000) != 0) && (*(int *)(param_1 + 0x98) == 0x24)) {
    return 1;
  }
  return 0;
}

/* FUN_001043a0 @ 0x1043a0 (80 bytes) */
int FUN_001043a0()
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 0x15;
  piVar2 = &DAT_001ea500;
  do {
    iVar1 = *piVar2;
    piVar2 = piVar2 + 2;
    if (iVar1 != iVar3) {
      return 0;
    }
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return 1;
}

/* FUN_001043f0 @ 0x1043f0 (108 bytes) */
int FUN_001043f0(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00113388(param_1,param_2);
  iVar1 = (**(code **)(&DAT_001ea4fc + iVar1 * 8))(param_1,param_2);
  uVar2 = FUN_00112f54(param_1);
  *(undefined4 *)(iVar1 + 0x88) = uVar2;
  return iVar1;
}

/* FUN_0010445c @ 0x10445c (132 bytes) */
int FUN_0010445c(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)FUN_00193e18(*(undefined4 *)(param_2 + 0x374),0x168);
  *puVar2 = *(undefined4 *)(param_2 + 0x374);
  _memcpy(puVar2 + 1,param_1,0x164);
  if (param_3 == 0) {
    iVar1 = *(int *)(param_2 + 0x324);
    puVar2[0x54] = iVar1;
    *(int *)(param_2 + 0x324) = iVar1 + 1;
  }
  puVar2[0x57] = 0;
  puVar2[3] = 0;
  puVar2[2] = 0;
  return puVar2 + 1;
}

/* FUN_001044e0 @ 0x1044e0 (60 bytes) */
int FUN_001044e0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_00193cc0(*(undefined4 *)(param_3 + 0x374),*(undefined4 *)(param_1 + 0x13c));
  *(undefined4 *)(param_1 + 0x13c) = param_2;
  return;
}

/* FUN_0010453c @ 0x10453c (168 bytes) */
int FUN_0010453c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  undefined4 uStack00000020;
  
  uStack00000020 = param_3;
  if (*(int *)(param_1 + 0x98) == 0x33) {
    pbVar4 = (byte *)&STACKARG(0x20);
    do {
      uVar1 = (uint)*pbVar4;
      if ((uVar1 != 4) &&
         ((((int)*(char *)(param_1 + 0x15c) >> (uVar1 & 0x3f) & 1U) == 0 ||
          (iVar2 = (**(code **)(**(int **)(param_2 + 0x30c) + 0xf0))
                             ((double)*(float *)(uVar1 * 0x18 + param_1 + 0x20)), iVar2 == 0))))
      goto LAB_001045cc;
      pbVar4 = pbVar4 + 1;
    } while (pbVar4 != &STACKARG(0x24));
    uVar3 = 1;
  }
  else {
LAB_001045cc:
    uVar3 = 0;
  }
  return uVar3;
}

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
  
  ((int (*)())FUN_00103d50)(param_1,1,param_2[5] & 1);
  ((int (*)())FUN_00103d50)(param_1,2,(uint)param_2[5] >> 1 & 1);
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
  ((int (*)())FUN_00103d50)(param_1,1,*(uint *)(param_2 + 0x14) & 1);
  ((int (*)())FUN_00103d50)(param_1,2,*(uint *)(param_2 + 0x14) >> 1 & 1);
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
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = ((int (*)())FUN_00104800)(param_1,param_2);
  iVar3 = param_1;
  if ((iVar1 == 0) && (iVar1 = ((int (*)())FUN_00104800)(param_2,param_1), iVar3 = param_2, iVar1 == 0)) {
    uVar2 = FUN_000e7924(*(undefined4 *)(param_1 + 0x158),*(undefined4 *)(param_2 + 0x158));
    iVar3 = FUN_000e7c98(uVar2);
    return iVar3;
  }
  return iVar3;
}

/* FUN_001048d4 @ 0x1048d4 (56 bytes) */
void FUN_001048d4(int param_1,double fparam_1)
{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x13c);
  uVar1 = ((int (*)())FUN_00103d78)(param_1,3,4,fparam_1);
  *(undefined2 *)(iVar2 + 0x18) = uVar1;
  return;
}

/* FUN_0010490c @ 0x10490c (56 bytes) */
void FUN_0010490c(int param_1,double fparam_1)
{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x13c);
  uVar1 = ((int (*)())FUN_00103d78)(param_1,3,4,fparam_1);
  *(undefined2 *)(iVar2 + 0x18) = uVar1;
  return;
}

/* FUN_00104944 @ 0x104944 (56 bytes) */
void FUN_00104944(int param_1,double fparam_1)
{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x13c);
  uVar1 = ((int (*)())FUN_00103d78)(param_1,3,4,fparam_1);
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
int FUN_001049c4(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
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

/* FUN_0010502c @ 0x10502c (312 bytes) */
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

/* FUN_001051b0 @ 0x1051b0 (312 bytes) */
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

/* FUN_00105334 @ 0x105334 (152 bytes) */
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
      ((int (*)())FUN_00103e84)(puVar1 + 1,param_2);
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
        _memset(uVar2 * 4 + puVar5[2],0,(uVar4 - uVar2) * 4 + 4);
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
int FUN_00105594(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = ((int (*)())FUN_001054ec)(param_1,param_2);
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

