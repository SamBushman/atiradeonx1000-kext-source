#include "decls.h"

/* FUN_00186a7c @ 0x186a7c (26 bytes) */
int FUN_00186a7c(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((param_1 == param_2) && (param_1 != 0)) {
    return 1;
  }
  return 0;
}

/* FUN_00186a96 @ 0x186a96 (30 bytes) */
int FUN_00186a96(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(param_1 + 8) = *(undefined1 *)(param_2 + 8);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  return;
}

/* FUN_00186ab4 @ 0x186ab4 (36 bytes) */
int FUN_00186ab4(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  (**(code **)(**(int **)(param_2 + 0x54) + 300))(*(int **)(param_2 + 0x54),param_1,param_2);
  return;
}

/* FUN_00186ad8 @ 0x186ad8 (5 bytes) */
int FUN_00186ad8()
{
  return;
}

/* FUN_00186ade @ 0x186ade (43 bytes) */
int FUN_00186ade(param_1)
  undefined4 param_1;
{
  int iVar1;
  
  iVar1 = 1;
  do {
    FUN_00184b4a(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 != 4);
  return;
}

/* FUN_00186b0a @ 0x186b0a (34 bytes) */
longdouble FUN_00186b0a(undefined4 param_1,float param_2)

{
  return (longdouble)(FLOAT_001c5c74 * param_2);
}

/* FUN_00186b2c @ 0x186b2c (29 bytes) */
int FUN_00186b2c(param_1)
  uint param_1;
{
  if (param_1 == 0) {
    return 3;
  }
  if (0 < (int)param_1) {
    return 5;
  }
  return param_1 >> 0x1f;
}

/* FUN_00186b4a @ 0x186b4a (113 bytes) */
undefined4 FUN_00186b4a(float param_1)

{
  if ((param_1 == FLOAT_001c5ba4) && (!NAN(param_1) && !NAN(FLOAT_001c5ba4))) {
    return 1;
  }
  if ((param_1 == FLOAT_001c5bdc) && (!NAN(param_1) && !NAN(FLOAT_001c5bdc))) {
    return 3;
  }
  if ((param_1 == 0.0) && (!NAN(param_1))) {
    return 2;
  }
  if ((0.0 <= param_1) && (param_1 <= FLOAT_001c5ba4)) {
    return 4;
  }
  if ((FLOAT_001c5bdc <= param_1) && (param_1 <= 0.0)) {
    return 5;
  }
  return 0;
}

/* FUN_00186bbc @ 0x186bbc (111 bytes) */
int FUN_00186bbc(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  int local_14;
  int local_10;
  
  pcVar2 = (char *)(param_1 + 0x224 + param_2 * 4);
  piVar3 = (int *)(param_2 * 0x10 + 0x168 + param_1);
  local_14 = 0;
  local_10 = 4;
  do {
    if (*pcVar2 != '\0') {
      if (local_14 == 0) {
        local_14 = *piVar3;
      }
      else {
        cVar1 = ((int (*)())FUN_00186a7c)(local_14,*piVar3);
        if (cVar1 == '\0') {
          return 0;
        }
      }
    }
    pcVar2 = pcVar2 + 1;
    piVar3 = piVar3 + 1;
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  return 1;
}

/* FUN_00186c2c @ 0x186c2c (85 bytes) */
int FUN_00186c2c(float param_1,int param_2,int param_3)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  
  pfVar2 = (float *)(param_3 * 0x10 + param_2 + -0xc);
  iVar3 = 1;
  do {
    fVar1 = *pfVar2;
    if ((fVar1 == param_1) && (!NAN(fVar1) && !NAN(param_1))) {
LAB_00186c74:
      return iVar3 + 1;
    }
    if ((fVar1 == FLOAT_001c5bdc) && (!NAN(fVar1) && !NAN(FLOAT_001c5bdc))) {
      *pfVar2 = param_1;
      goto LAB_00186c74;
    }
    iVar3 = iVar3 + 1;
    pfVar2 = pfVar2 + 1;
    if (iVar3 == 4) {
      return 0;
    }
  } while( true );
}

/* FUN_00186c82 @ 0x186c82 (22 bytes) */
int FUN_00186c82(param_1)
  undefined4 param_1;
{
  undefined1 uVar1;
  
  uVar1 = FUN_0012e0c0(param_1);
  return uVar1;
}

/* FUN_00186c98 @ 0x186c98 (22 bytes) */
int FUN_00186c98(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(int *)(param_1 + 0x70 + param_2 * 4) == 4;
}

/* FUN_00186cae @ 0x186cae (25 bytes) */
int FUN_00186cae(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(int *)(param_1 + 0xa0 + param_2 * 4) == 1;
}

/* FUN_00186cc8 @ 0x186cc8 (25 bytes) */
int FUN_00186cc8(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(int *)(param_1 + 0xa0 + param_2 * 4) == 4;
}

/* FUN_00186ce2 @ 0x186ce2 (51 bytes) */
int FUN_00186ce2(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(param_1 + 300) == *(int *)(param_2 + 300)) {
    return 0;
  }
  if ((*(int *)(param_1 + 300) < 0) && (*(int *)(param_2 + 300) < 0)) {
    return 1;
  }
  return 2;
}

/* FUN_00186d16 @ 0x186d16 (17 bytes) */
int FUN_00186d16(param_1)
  int param_1;
{
  return param_1 == 0xf9;
}

/* FUN_00186d28 @ 0x186d28 (39 bytes) */
int FUN_00186d28(param_1)
  int param_1;
{
  if (param_1 == 0x32) {
    return 1;
  }
  if (param_1 < 0x33) {
    if (param_1 == 0x1f) {
      return 1;
    }
  }
  else if (param_1 - 0xa7U < 2) {
    return 1;
  }
  return 0;
}

/* FUN_00186d50 @ 0x186d50 (44 bytes) */
int FUN_00186d50(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  
  uVar1 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),param_2);
  *(undefined4 *)(param_1 + 0x30 + param_3 * 4) = uVar1;
  return;
}

/* FUN_00186d7c @ 0x186d7c (28 bytes) */
int FUN_00186d7c(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  return *(undefined4 *)(&DAT_001f8e20 + (param_2 * 6 + param_3) * 4);
}

/* FUN_00186d98 @ 0x186d98 (27 bytes) */
int FUN_00186d98(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if ((param_2 != 2) && (param_2 != 5)) {
    return 1;
  }
  return 0;
}

/* FUN_00186db4 @ 0x186db4 (119 bytes) */
int FUN_00186db4(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = param_1;
  do {
    iVar1 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    if ((*(char *)(iVar4 + 0x10 + iVar1) != '\x01') && (*(int *)(iVar3 + 0x30) == 0)) {
      if (*(int *)(iVar3 + 0x40) == 0) {
        uVar2 = FUN_001851d0(*(undefined4 *)(param_1 + 0x238),iVar4,param_1);
        *(undefined4 *)(iVar3 + 0x40) = uVar2;
      }
      *(undefined4 *)(*(int *)(iVar3 + 0x40) + 0xc) = 4;
    }
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar4 != 4);
  return;
}

/* FUN_00186e2c @ 0x186e2c (108 bytes) */
int FUN_00186e2c(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),0);
  if ((*(int *)(iVar1 + 4) != *(int *)(param_1 + 0x184)) &&
     (*(int *)(iVar1 + 4) != *(int *)(param_1 + 0x194))) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0xb0);
  uVar2 = FUN_00118f66(0x1c);
  *(undefined4 *)(iVar1 + 0x88) = uVar2;
  FUN_00184a5a(param_1);
  return 1;
}

/* FUN_00186e98 @ 0x186e98 (156 bytes) */
int FUN_00186e98(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  iVar2 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0));
  if (0 < iVar2) {
    do {
      cVar1 = FUN_001192da(*(undefined4 *)(param_1 + 0x238),*(undefined4 *)(param_1 + 0xb0));
      if (cVar1 == '\0') {
LAB_00186ee0:
        iVar2 = 0;
LAB_00186ee2:
        iVar2 = *(int *)(param_1 + 0x168 + (iVar2 + iVar3 * 4) * 4);
      }
      else {
        if (iVar3 == 1) {
          iVar2 = 3;
          goto LAB_00186ee2;
        }
        if (iVar3 != 3) goto LAB_00186ee0;
        iVar2 = *(int *)(param_1 + 0x19c);
      }
      if (-1 < iVar2) {
        return 0;
      }
      iVar3 = iVar3 + 1;
      iVar2 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0));
    } while (iVar3 <= iVar2);
  }
  return 1;
}

/* FUN_00186f34 @ 0x186f34 (83 bytes) */
int FUN_00186f34(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1 + 0x168 + param_2 * 4;
  iVar4 = 1;
  while( true ) {
    iVar2 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0));
    if (iVar2 < iVar4) {
      return 1;
    }
    piVar1 = (int *)(iVar3 + 0x10);
    iVar3 = iVar3 + 0x10;
    if (-1 < *piVar1) break;
    iVar4 = iVar4 + 1;
  }
  return 0;
}

/* FUN_00186f88 @ 0x186f88 (143 bytes) */
int FUN_00186f88(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  if (((((param_3 == '\0') || (*(int *)(param_2 * 0x10 + 0x168 + param_1) < 0)) &&
       ((param_4 == '\0' || (*(int *)(param_2 * 0x10 + 0x16c + param_1) < 0)))) &&
      ((param_5 == '\0' || (*(int *)(param_2 * 0x10 + 0x170 + param_1) < 0)))) &&
     ((param_6 == '\0' || (*(int *)(param_2 * 0x10 + 0x174 + param_1) < 0)))) {
    return 1;
  }
  return 0;
}

/* FUN_00187018 @ 0x187018 (94 bytes) */
int FUN_00187018(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1 + 0x168 + param_2 * 4;
  iVar3 = 2;
  while ((-1 < *(int *)(iVar2 + 0x10) ||
         (piVar1 = (int *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),*(int *)(iVar2 + 0x10)),
         *piVar1 != 0))) {
    iVar2 = iVar2 + 0x10;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return 0;
    }
  }
  *(int **)(param_1 + 0x30 + param_2 * 4) = piVar1;
  return 1;
}

/* FUN_00187076 @ 0x187076 (167 bytes) */
int FUN_00187076(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar1 = *(int *)(param_1 + 0x178 + param_2 * 4);
  if ((iVar1 < 0) && (*(int *)(param_1 + 0x188 + param_2 * 4) < 0)) {
    puVar4 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar1);
    puVar5 = (undefined4 *)
             FUN_001836ee(*(undefined4 *)(param_1 + 0x238),
                          *(undefined4 *)(param_1 + 0x188 + param_2 * 4));
    cVar2 = ((bool (*)())FUN_00110958)(*(undefined4 *)(param_1 + 0xb0),*puVar4,*puVar5);
    if (cVar2 == '\0') {
      uVar3 = 0;
    }
    else {
      uVar3 = 0x3f800000;
    }
    uVar3 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),uVar3);
    *(undefined4 *)(param_1 + 0x30 + param_2 * 4) = uVar3;
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

/* FUN_0018711e @ 0x18711e (133 bytes) */
int FUN_0018711e(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  
  cVar1 = FUN_001192da(*(undefined4 *)(param_1 + 0x238),*(undefined4 *)(param_1 + 0xb0));
  if (cVar1 == '\0') {
LAB_00187152:
    iVar2 = 0;
  }
  else {
    if (param_2 == 1) {
      iVar2 = *(int *)(param_1 + 0x184);
      goto joined_r0x0018717f;
    }
    if (param_2 != 3) goto LAB_00187152;
    iVar2 = 1;
  }
  iVar2 = *(int *)(param_1 + 0x168 + (iVar2 + param_2 * 4) * 4);
joined_r0x0018717f:
  if (-1 < iVar2) {
    return 0x7ffffffe;
  }
  puVar3 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar2);
  return *puVar3;
}

/* FUN_001871a4 @ 0x1871a4 (458 bytes) */
float FUN_001871a4(int param_1,undefined1 *param_2)

{
  float *pfVar1;
  int *piVar2;
  float *pfVar3;
  float *pfVar4;
  float fVar5;
  int iVar6;
  int local_60;
  float afStack_54 [5];
  float local_40 [4];
  float local_30 [4];
  float local_20 [4];
  
  local_20[0] = NAN;
  pfVar1 = afStack_54 + 9;
  pfVar3 = pfVar1;
  do {
    *pfVar3 = NAN;
    pfVar3 = pfVar3 + 1;
  } while (local_20 != pfVar3);
  pfVar3 = afStack_54 + 5;
  pfVar4 = pfVar3;
  do {
    *pfVar4 = NAN;
    pfVar4 = pfVar4 + 1;
  } while (pfVar1 != pfVar4);
  pfVar4 = afStack_54 + 1;
  do {
    *pfVar4 = NAN;
    pfVar4 = pfVar4 + 1;
  } while (pfVar3 != pfVar4);
  local_60 = 1;
  iVar6 = param_1;
  do {
    afStack_54[local_60 + 8] = 0.0;
    pfVar4 = (float *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),*(undefined4 *)(iVar6 + 0x178));
    if (pfVar4 != (float *)0x0) {
      afStack_54[local_60 + 8] = *pfVar4;
    }
    afStack_54[local_60 + 4] = 0.0;
    pfVar4 = (float *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),*(undefined4 *)(iVar6 + 0x188));
    if (pfVar4 != (float *)0x0) {
      afStack_54[local_60 + 4] = *pfVar4;
    }
    afStack_54[local_60] = 0.0;
    pfVar4 = (float *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),*(undefined4 *)(iVar6 + 0x198));
    if (pfVar4 != (float *)0x0) {
      afStack_54[local_60] = *pfVar4;
    }
    local_60 = local_60 + 1;
    iVar6 = iVar6 + 4;
  } while (local_60 != 5);
  local_20[0] = NAN;
  piVar2 = *(int **)(*(int *)(param_1 + 0xb0) + 0x88);
  (**(code **)(*piVar2 + 8))
            (piVar2,local_20,pfVar1,pfVar3,afStack_54 + 1,*(undefined4 *)(param_1 + 0x238));
  if (local_20[0] != FLOAT_001c5c78) {
    local_20[0] = (float)((float (*)())FUN_001100e2)(*(undefined4 *)(param_1 + 0xb0),local_20[0]);
    fVar5 = (float)((float (*)())FUN_001102fa)(*(undefined4 *)(param_1 + 0xb0),local_20[0]);
    if (fVar5 != local_20[0]) {
      *param_2 = 1;
      return fVar5;
    }
  }
  return local_20[0];
}

/* FUN_0018736e @ 0x18736e (257 bytes) */
int FUN_0018736e(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined1 *param_3;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_30;
  int local_24 [5];
  int local_10;
  
  piVar1 = local_24;
  do {
    *piVar1 = 0x7ffffffe;
    piVar1 = piVar1 + 1;
  } while (&local_10 != piVar1);
  local_10 = 0x7ffffffe;
  local_30 = 1;
  puVar4 = (undefined4 *)(param_1 + 0x178 + param_2 * 4);
  piVar1 = local_24;
  while( true ) {
    piVar1 = piVar1 + 1;
    iVar3 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0));
    if (iVar3 < local_30) break;
    piVar2 = (int *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),*puVar4);
    *piVar1 = *piVar2;
    local_30 = local_30 + 1;
    puVar4 = puVar4 + 4;
  }
  piVar1 = *(int **)(*(int *)(param_1 + 0xb0) + 0x88);
  (**(code **)(*piVar1 + 4))(piVar1,&local_10,local_24,*(undefined4 *)(param_1 + 0x238));
  if (local_10 != 0x7ffffffe) {
    local_10 = ((float (*)())FUN_001100e2)(*(undefined4 *)(param_1 + 0xb0),local_10);
    iVar3 = ((float (*)())FUN_001102fa)(*(undefined4 *)(param_1 + 0xb0),local_10);
    if (iVar3 != local_10) {
      *param_3 = 1;
      local_10 = iVar3;
    }
  }
  return local_10;
}

/* FUN_00187470 @ 0x187470 (113 bytes) */
int FUN_00187470(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  
  if ((((0 < param_1) && (0 < param_2)) && (iVar1 = FUN_001836c0(param_3,param_1), iVar1 != 0)) &&
     (iVar2 = FUN_001836c0(param_3,param_2), iVar2 != 0)) {
    if ((*(char *)(iVar1 + 0x20) != '\0') && (param_2 == *(int *)(iVar1 + 0x24))) {
      return 1;
    }
    if ((*(char *)(iVar2 + 0x20) != '\0') && (param_1 == *(int *)(iVar2 + 0x24))) {
      return 1;
    }
  }
  return 0;
}

/* FUN_001874e2 @ 0x1874e2 (42 bytes) */
int FUN_001874e2(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_00187470)(param_2,param_3,*(undefined4 *)(param_1 + 0x238));
  return uVar1;
}

/* FUN_0018750c @ 0x18750c (113 bytes) */
int FUN_0018750c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  
  if ((((0 < param_1) && (0 < param_2)) && (iVar1 = FUN_001836c0(param_3,param_1), iVar1 != 0)) &&
     (iVar2 = FUN_001836c0(param_3,param_2), iVar2 != 0)) {
    if ((*(char *)(iVar1 + 0x28) != '\0') && (param_2 == *(int *)(iVar1 + 0x2c))) {
      return 1;
    }
    if ((*(char *)(iVar2 + 0x28) != '\0') && (param_1 == *(int *)(iVar2 + 0x2c))) {
      return 1;
    }
  }
  return 0;
}

/* FUN_0018757e @ 0x18757e (42 bytes) */
int FUN_0018757e(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_0018750c)(param_2,param_3,*(undefined4 *)(param_1 + 0x238));
  return uVar1;
}

/* FUN_001875a8 @ 0x1875a8 (43 bytes) */
int FUN_001875a8(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if (0 < param_2) {
    iVar1 = FUN_001836c0(*(undefined4 *)(param_1 + 0x238),param_2);
    return *(undefined4 *)(iVar1 + 0xc);
  }
  return 0;
}

/* FUN_001875d4 @ 0x1875d4 (43 bytes) */
int FUN_001875d4(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if (0 < param_2) {
    iVar1 = FUN_001836c0(*(undefined4 *)(param_1 + 0x238),param_2);
    return *(undefined4 *)(iVar1 + 0x10);
  }
  return 0;
}

/* FUN_00187600 @ 0x187600 (144 bytes) */
int FUN_00187600(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int local_10;
  
  puVar4 = (undefined4 *)(param_3 * 0x10 + 0x168 + param_1);
  puVar3 = (undefined4 *)(param_2 * 0x10 + 0x168 + param_1);
  local_10 = 0;
  while ((iVar2 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0),
         *(char *)(local_10 + 0x10 + iVar2) == '\x01' ||
         (cVar1 = ((int (*)())FUN_00187470)(*puVar3,*puVar4,*(undefined4 *)(param_1 + 0x238)), cVar1 != '\0'))) {
    local_10 = local_10 + 1;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 1;
    if (local_10 == 4) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00187690 @ 0x187690 (144 bytes) */
int FUN_00187690(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int local_10;
  
  puVar4 = (undefined4 *)(param_3 * 0x10 + 0x168 + param_1);
  puVar3 = (undefined4 *)(param_2 * 0x10 + 0x168 + param_1);
  local_10 = 0;
  while ((iVar2 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0),
         *(char *)(local_10 + 0x10 + iVar2) == '\x01' ||
         (cVar1 = ((int (*)())FUN_0018750c)(*puVar3,*puVar4,*(undefined4 *)(param_1 + 0x238)), cVar1 != '\0'))) {
    local_10 = local_10 + 1;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 1;
    if (local_10 == 4) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00187720 @ 0x187720 (97 bytes) */
int FUN_00187720(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(param_3 * 0x10 + 0x168 + param_1);
  iVar3 = 0;
  while( true ) {
    iVar1 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    if ((*(char *)(iVar3 + 0x10 + iVar1) != '\x01') && (*piVar2 != param_2)) break;
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 1;
    if (iVar3 == 4) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00187782 @ 0x187782 (144 bytes) */
int FUN_00187782(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int local_10;
  
  piVar4 = (int *)(param_2 * 0x10 + 0x168 + param_1);
  local_10 = 0;
  iVar5 = 0;
  do {
    iVar1 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(char *)(iVar5 + 0x10 + iVar1) != '\x01') {
      if (local_10 == 0) {
        local_10 = *piVar4;
      }
      else if (*piVar4 != local_10) goto LAB_001877e1;
    }
    iVar5 = iVar5 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar5 != 4);
  if (local_10 < 0) {
    puVar3 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),local_10);
    uVar2 = *puVar3;
  }
  else {
LAB_001877e1:
    uVar2 = 0x7ffffffe;
  }
  return uVar2;
}

/* FUN_00187812 @ 0x187812 (215 bytes) */
int FUN_00187812(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  piVar3 = param_1;
  do {
    iVar1 = FUN_0010b0f4(param_1[0x2c],0);
    if (*(char *)(iVar4 + 0x10 + iVar1) != '\x01') {
      if ((undefined4 *)piVar3[0xc] == (undefined4 *)0x0) {
        iVar1 = *piVar3;
        if (iVar1 < 0) {
          puVar2 = (undefined4 *)FUN_001836ee(param_1[0x8e],iVar1);
          iVar1 = ((undefined4 (*)())FUN_00186b4a)(*puVar2);
        }
        else if (piVar3[0x10] == 0) {
          if (iVar1 < 1) {
            iVar1 = 0;
          }
          else {
            iVar1 = FUN_001836c0(param_1[0x8e],iVar1);
            iVar1 = *(int *)(iVar1 + 0x10);
          }
        }
        else {
          iVar1 = *(int *)(piVar3[0x10] + 0x10);
        }
      }
      else {
        iVar1 = ((undefined4 (*)())FUN_00186b4a)(*(undefined4 *)piVar3[0xc]);
      }
      if (*(char *)(param_1[0x2c] + 0x120) == '\0') {
        piVar3[0x14] = iVar1;
      }
      else {
        piVar3[0x14] = (DAT_001f9044)[iVar1];
      }
    }
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar4 != 4);
  return;
}

/* FUN_001878ea @ 0x1878ea (209 bytes) */
int FUN_001878ea(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  piVar3 = param_1;
  do {
    iVar1 = FUN_0010b0f4(param_1[0x2c],0);
    if (*(char *)(iVar4 + 0x10 + iVar1) != '\x01') {
      puVar2 = (undefined4 *)piVar3[0xc];
      if (puVar2 == (undefined4 *)0x0) {
        iVar1 = *piVar3;
        if (iVar1 < 0) {
          puVar2 = (undefined4 *)FUN_001836ee(param_1[0x8e],iVar1);
          goto LAB_00187924;
        }
        if (piVar3[0x10] == 0) {
          if (iVar1 < 1) {
            iVar1 = 0;
          }
          else {
            iVar1 = FUN_001836c0(param_1[0x8e],iVar1);
            iVar1 = *(int *)(iVar1 + 0xc);
          }
        }
        else {
          iVar1 = *(int *)(piVar3[0x10] + 0xc);
        }
      }
      else {
LAB_00187924:
        iVar1 = ((int (*)())FUN_00186b2c)(*puVar2);
      }
      if (*(char *)(param_1[0x2c] + 0x120) == '\0') {
        piVar3[0x20] = iVar1;
      }
      else {
        piVar3[0x20] = (DAT_001f908c)[iVar1];
      }
    }
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 1;
    if (iVar4 == 4) {
      return;
    }
  } while( true );
}

/* FUN_001879bc @ 0x1879bc (122 bytes) */
int FUN_001879bc(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int local_10;
  
  piVar3 = (int *)(param_2 * 0x10 + 0x168 + param_1);
  piVar2 = (int *)(param_3 * 0x10 + 0x168 + param_1);
  local_10 = 0;
  while( true ) {
    iVar1 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    if ((*(char *)(local_10 + 0x10 + iVar1) != '\x01') && (*piVar3 != *piVar2)) break;
    local_10 = local_10 + 1;
    piVar3 = piVar3 + 1;
    piVar2 = piVar2 + 1;
    if (local_10 == 4) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00187a36 @ 0x187a36 (127 bytes) */
int FUN_00187a36(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar1 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),param_3);
  piVar3 = (int *)(param_2 * 0x10 + 0x168 + param_1);
  iVar4 = 0;
  while( true ) {
    iVar2 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    if ((*(char *)(iVar4 + 0x10 + iVar2) != '\x01') && (*piVar3 != *(int *)(iVar1 + 4))) break;
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 1;
    if (iVar4 == 4) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00187ab6 @ 0x187ab6 (135 bytes) */
int FUN_00187ab6(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = param_1;
  do {
    iVar1 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    if (((*(char *)(iVar4 + 0x10 + iVar1) != '\x01') && (*(int *)(iVar3 + 0x30) == 0)) &&
       (*(int *)(*(int *)(param_1 + 0xb0) + 0x124) < 1)) {
      if (*(int *)(iVar3 + 0x40) == 0) {
        uVar2 = FUN_001851d0(*(undefined4 *)(param_1 + 0x238),iVar4,param_1);
        *(undefined4 *)(iVar3 + 0x40) = uVar2;
      }
      *(undefined4 *)(*(int *)(iVar3 + 0x40) + 0x10) = 4;
    }
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar4 != 4);
  return;
}

/* FUN_00187b3e @ 0x187b3e (111 bytes) */
int FUN_00187b3e(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(char *)(iVar2 + 0x10 + iVar1) == '\0') {
      *(undefined1 *)(iVar2 + 0x9c + *(int *)(param_1 + 0xb0)) = 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 4);
  iVar2 = *(int *)(param_1 + 0xb0);
  if ((*(byte *)(iVar2 + 0x15) & 2) == 0) {
    FUN_0010a6a6(iVar2,*(undefined4 *)(iVar2 + 0x8c),*(undefined4 *)(param_1 + 0x238));
  }
  return;
}

/* FUN_00187bae @ 0x187bae (212 bytes) */
int FUN_00187bae(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar2 = *(int *)(param_1 + 0xb0);
  if ((((*(char *)(iVar2 + 0x120) == '\0') && (*(int *)(iVar2 + 0x124) == 0)) &&
      ((*(uint *)(iVar2 + 0xb8) & 2) == 0)) && ((*(uint *)(iVar2 + 0xb8) & 1) != 0)) {
    iVar2 = FUN_0010b0f4(iVar2,0);
    cVar1 = *(char *)(iVar2 + 0x10);
    iVar2 = 0;
    iVar5 = param_1;
    while( true ) {
      if ((cVar1 != '\x01') && (*(int *)(iVar5 + 0x30) == 0)) {
        if (*(int *)(iVar5 + 0x40) == 0) {
          uVar4 = FUN_001851d0(*(undefined4 *)(param_1 + 0x238),iVar2,param_1);
          *(undefined4 *)(iVar5 + 0x40) = uVar4;
        }
        *(int *)(*(int *)(iVar5 + 0x40) + 4) = param_1;
        *(int *)(*(int *)(iVar5 + 0x40) + 8) = iVar2;
        *(undefined1 *)(*(int *)(iVar5 + 0x40) + 0x20) = 1;
        *(undefined4 *)(*(int *)(iVar5 + 0x40) + 0x24) = *(undefined4 *)(iVar5 + 0x178);
      }
      iVar5 = iVar5 + 4;
      if (iVar2 + 1 == 4) break;
      iVar3 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
      cVar1 = *(char *)(iVar2 + 0x11 + iVar3);
      iVar2 = iVar2 + 1;
    }
  }
  return;
}

/* FUN_00187c82 @ 0x187c82 (143 bytes) */
int FUN_00187c82(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  
  cVar3 = ((int (*)())FUN_0018757e)(param_1,*(undefined4 *)(param_1 + 0x178 + param_2 * 4),
                       *(undefined4 *)(param_1 + 0x188 + param_2 * 4));
  if (cVar3 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    if ((((byte)uVar1 & 1) == ((byte)uVar2 & 1)) &&
       (((byte)(uVar1 >> 1) & 1) == ((byte)(uVar2 >> 1) & 1))) {
      uVar4 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),0);
      *(undefined4 *)(param_1 + 0x30 + param_2 * 4) = uVar4;
      return 1;
    }
  }
  return 0;
}

/* FUN_00187d12 @ 0x187d12 (371 bytes) */
int FUN_00187d12(param_1)
  int param_1;
{
  int *piVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int local_24;
  int local_20;
  
  iVar4 = FUN_0011074c(*(undefined4 *)(param_1 + 0xb0));
  fVar5 = (float)((int (*)())FUN_00187782)(param_1,2);
  if (((fVar5 == FLOAT_001c5b9c) && (!NAN(fVar5) && !NAN(FLOAT_001c5b9c))) &&
     (piVar1 = *(int **)(*(int *)(param_1 + 0x238) + 0x54),
     cVar3 = (**(code **)(*piVar1 + 0x2c))(piVar1,iVar4), cVar3 == '\0')) {
    local_24 = 0;
    local_20 = 0;
    iVar9 = param_1;
    do {
      iVar6 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
      iVar7 = local_24;
      if (*(char *)(local_20 + 0x10 + iVar6) != '\x01') {
        iVar7 = *(int *)(iVar9 + 0x178);
        if (iVar7 < 0) {
          puVar8 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar7);
          iVar6 = ((int (*)())FUN_00186b2c)(*puVar8);
        }
        else {
          if (iVar7 < 1) {
            return;
          }
          iVar7 = FUN_001836c0(*(undefined4 *)(param_1 + 0x238),iVar7);
          iVar6 = *(int *)(iVar7 + 0xc);
          uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
          if ((uVar2 & 2) != 0) {
            iVar6 = (DAT_001f90bc)[iVar6];
          }
          if ((uVar2 & 1) != 0) {
            iVar6 = *(int *)(&DAT_001f90a4 + iVar6 * 4);
          }
        }
        if (iVar6 == 0) {
          return;
        }
        iVar7 = iVar6;
        if ((local_24 != 0) && (iVar7 = local_24, iVar6 != local_24)) {
          return;
        }
      }
      local_24 = iVar7;
      local_20 = local_20 + 1;
      iVar9 = iVar9 + 4;
    } while (local_20 != 4);
    piVar1 = *(int **)(*(int *)(param_1 + 0x238) + 0x54);
    iVar9 = (**(code **)(*piVar1 + 0x30))(piVar1,iVar4,local_24);
    if (iVar4 != iVar9) {
      FUN_00110a08(*(undefined4 *)(param_1 + 0xb0),iVar9);
      return;
    }
  }
  return;
}

/* FUN_00187e86 @ 0x187e86 (276 bytes) */
int FUN_00187e86(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  longdouble lVar6;
  
  iVar2 = *(int *)(param_1 + 0xb0);
  if ((((*(char *)(iVar2 + 0x120) == '\0') && ((*(uint *)(iVar2 + 0xb8) & 1) == 0)) &&
      ((*(uint *)(iVar2 + 0xb8) & 2) == 0)) && (*(int *)(iVar2 + 0x124) != 0)) {
    iVar2 = FUN_0010b0f4(iVar2,0);
    cVar1 = *(char *)(iVar2 + 0x10);
    iVar2 = 0;
    iVar5 = param_1;
    while( true ) {
      if ((cVar1 != '\x01') && (*(int *)(iVar5 + 0x30) == 0)) {
        if (*(int *)(iVar5 + 0x40) == 0) {
          uVar4 = FUN_001851d0(*(undefined4 *)(param_1 + 0x238),iVar2,param_1);
          *(undefined4 *)(iVar5 + 0x40) = uVar4;
        }
        iVar3 = FUN_001851d0(*(undefined4 *)(param_1 + 0x238),iVar2,param_1);
        *(int *)(iVar5 + 0x40) = iVar3;
        *(int *)(iVar3 + 4) = param_1;
        *(int *)(*(int *)(iVar5 + 0x40) + 8) = iVar2;
        *(undefined1 *)(*(int *)(iVar5 + 0x40) + 0x14) = 1;
        *(undefined4 *)(*(int *)(iVar5 + 0x40) + 0x18) = *(undefined4 *)(iVar5 + 0x178);
        iVar3 = *(int *)(iVar5 + 0x40);
        lVar6 = (longdouble)FUN_0010fd78(*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124));
        *(float *)(iVar3 + 0x1c) = (float)lVar6;
      }
      iVar5 = iVar5 + 4;
      if (iVar2 + 1 == 4) break;
      iVar3 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
      cVar1 = *(char *)(iVar2 + 0x11 + iVar3);
      iVar2 = iVar2 + 1;
    }
  }
  return;
}

/* FUN_00187f9a @ 0x187f9a (218 bytes) */
int FUN_00187f9a(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_10;
  
  iVar2 = *(int *)(param_1 + 0xb0);
  if ((((*(char *)(iVar2 + 0x120) == '\0') && (*(int *)(iVar2 + 0x124) == 0)) &&
      ((*(uint *)(iVar2 + 0xb8) & 1) == 0)) && ((*(uint *)(iVar2 + 0xb8) & 2) == 0)) {
    local_10 = 0;
    iVar2 = FUN_0010b0f4(iVar2,0);
    cVar1 = *(char *)(iVar2 + 0x10);
    iVar2 = param_1;
    while( true ) {
      if ((cVar1 != '\x01') && (*(int *)(iVar2 + 0x30) == 0)) {
        if (*(int *)(iVar2 + 0x40) == 0) {
          uVar4 = FUN_001851d0(*(undefined4 *)(param_1 + 0x238),local_10,param_1);
          *(undefined4 *)(iVar2 + 0x40) = uVar4;
        }
        *(int *)(*(int *)(iVar2 + 0x40) + 4) = param_1;
        *(int *)(*(int *)(iVar2 + 0x40) + 8) = local_10;
        *(undefined1 *)(*(int *)(iVar2 + 0x40) + 0x28) = 1;
        *(undefined4 *)(*(int *)(iVar2 + 0x40) + 0x2c) = *(undefined4 *)(iVar2 + 0x178);
      }
      iVar2 = iVar2 + 4;
      if (local_10 + 1 == 4) break;
      iVar3 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
      cVar1 = *(char *)(local_10 + 0x11 + iVar3);
      local_10 = local_10 + 1;
    }
  }
  return;
}

/* FUN_00188074 @ 0x188074 (416 bytes) */
float FUN_00188074(int param_1,undefined1 *param_2)

{
  float *pfVar1;
  int *piVar2;
  char cVar3;
  float *pfVar4;
  undefined4 *puVar5;
  int iVar6;
  float fVar7;
  int iVar8;
  int local_58;
  int aiStack_4c [6];
  float local_34 [5];
  float local_20 [4];
  
  local_20[0] = NAN;
  pfVar1 = (float *)(aiStack_4c + 6);
  pfVar4 = pfVar1;
  do {
    *pfVar4 = NAN;
    pfVar4 = pfVar4 + 1;
  } while (local_20 != pfVar4);
  local_58 = 8;
  for (iVar8 = 1;
      iVar6 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0)),
      iVar8 <= iVar6; iVar8 = iVar8 + 1) {
    cVar3 = FUN_001192da(*(undefined4 *)(param_1 + 0x238),*(undefined4 *)(param_1 + 0xb0));
    if (cVar3 == '\0') {
      *(undefined4 *)((int)aiStack_4c + local_58) = 0;
    }
    else if (iVar8 == 2) {
      aiStack_4c[3] = 0;
    }
    else if (iVar8 == 3) {
      aiStack_4c[4] = 1;
    }
    else if (iVar8 == 1) {
      aiStack_4c[2] = 3;
    }
    puVar5 = (undefined4 *)
             FUN_001836ee(*(undefined4 *)(param_1 + 0x238),
                          *(undefined4 *)
                           (param_1 + 0x168 + (*(int *)((int)aiStack_4c + local_58) + iVar8 * 4) * 4
                           ));
    *(undefined4 *)(local_58 + -4 + (int)pfVar1) = *puVar5;
    local_58 = local_58 + 4;
  }
  piVar2 = *(int **)(*(int *)(param_1 + 0xb0) + 0x88);
  (**(code **)(*piVar2 + 4))(piVar2,local_20,pfVar1,*(undefined4 *)(param_1 + 0x238));
  if (FLOAT_001c5c78 != local_20[0]) {
    local_20[0] = (float)((float (*)())FUN_001100e2)(*(undefined4 *)(param_1 + 0xb0),local_20[0]);
    fVar7 = (float)((float (*)())FUN_001102fa)(*(undefined4 *)(param_1 + 0xb0),local_20[0]);
    if (fVar7 != local_20[0]) {
      *param_2 = 1;
      return fVar7;
    }
  }
  return local_20[0];
}

/* FUN_00188214 @ 0x188214 (459 bytes) */
float FUN_00188214(int param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  longdouble lVar3;
  longdouble lVar4;
  float local_30;
  float local_20 [5];
  
  pfVar1 = local_20;
  do {
    *pfVar1 = NAN;
    pfVar1 = pfVar1 + 1;
  } while (pfVar1 != (float *)&STACKARG(0xfffffff4));
  fVar2 = NAN;
  if (*(int *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8) == 0x32) {
    if (param_2 == 1) {
      pfVar1 = (float *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),
                                     *(undefined4 *)(param_1 + 0x178));
      fVar2 = *pfVar1;
      if (fVar2 <= 0.0) {
        fVar2 = 0.0;
      }
    }
    else if (param_2 < 2) {
      if (param_2 == 0) {
        fVar2 = 1.0;
      }
    }
    else if (param_2 == 2) {
      pfVar1 = (float *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),
                                     *(undefined4 *)(param_1 + 0x178));
      local_20[0] = *pfVar1;
      pfVar1 = (float *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),
                                     *(undefined4 *)(param_1 + 0x17c));
      local_20[1] = *pfVar1;
      if ((local_20[0] <= 0.0) || (local_20[1] <= 0.0)) {
        fVar2 = 0.0;
      }
      else {
        pfVar1 = (float *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),
                                       *(undefined4 *)(param_1 + 0x184));
        local_20[3] = *pfVar1;
        if ((FLOAT_001c5c7c <= local_20[3]) || (NAN(local_20[3]) || NAN(FLOAT_001c5c7c))) {
          local_30 = FLOAT_001c5c80;
          if (local_20[3] <= FLOAT_001c5c80) {
            local_30 = local_20[3];
          }
        }
        else {
          local_30 = FLOAT_001c5c7c;
        }
        lVar3 = (longdouble)_log((double)local_20[1]);
        lVar4 = (longdouble)_log(0,0x40000000);
        lVar3 = (longdouble)
                _pow(0,0x40000000,(double)((float)((double)lVar3 / (double)lVar4) * local_30));
        fVar2 = (float)lVar3;
      }
    }
    else if (param_2 == 3) {
      fVar2 = 1.0;
    }
  }
  return fVar2;
}

/* FUN_001883e0 @ 0x1883e0 (208 bytes) */
int FUN_001883e0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8);
  if (iVar1 == 0x1c) {
    iVar1 = param_2 * 0x10 + param_1;
    iVar3 = *(int *)(iVar1 + 0x168);
    if (iVar3 != *(int *)(iVar1 + 0x16c)) {
      return 0x7ffffffe;
    }
    if (iVar3 != *(int *)(iVar1 + 0x170)) {
      return 0x7ffffffe;
    }
  }
  else {
    if (iVar1 < 0x1d) {
      if (iVar1 != 0x18) {
        return 0x7ffffffe;
      }
    }
    else if (iVar1 != 0x1d) {
      if (iVar1 != 0x1e) {
        return 0x7ffffffe;
      }
      if (param_2 - 1U < 2) {
        iVar1 = param_2 * 0x10 + param_1;
        iVar3 = *(int *)(iVar1 + 0x168);
        if (iVar3 != *(int *)(iVar1 + 0x16c)) {
          return 0x7ffffffe;
        }
      }
      else {
        iVar3 = *(int *)(param_2 * 0x10 + 0x170 + param_1);
      }
      goto LAB_00188478;
    }
    iVar1 = param_2 * 0x10 + param_1;
    iVar3 = *(int *)(iVar1 + 0x168);
    if (iVar3 != *(int *)(iVar1 + 0x16c)) {
      return 0x7ffffffe;
    }
    if (iVar3 != *(int *)(iVar1 + 0x170)) {
      return 0x7ffffffe;
    }
    if (iVar3 != *(int *)(iVar1 + 0x174)) {
      return 0x7ffffffe;
    }
  }
LAB_00188478:
  if (-1 < iVar3) {
    return 0x7ffffffe;
  }
  puVar2 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar3);
  return *puVar2;
}

/* FUN_001884b0 @ 0x1884b0 (156 bytes) */
int FUN_001884b0(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  piVar1 = *(int **)(param_1 + 0xb0);
  if (*(int *)(piVar1[0x22] + 8) == 0x32) {
    iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1);
    if (iVar2 == 1) {
      iVar4 = param_2 * 0x10 + param_1;
      iVar2 = *(int *)(iVar4 + 0x168);
      if (iVar2 != *(int *)(iVar4 + 0x16c)) {
        return 0x7ffffffe;
      }
      if (iVar2 != *(int *)(iVar4 + 0x174)) {
        return 0x7ffffffe;
      }
    }
    else {
      if (iVar2 != 3) {
        return 0x7ffffffe;
      }
      if (param_2 == 2) {
        iVar2 = *(int *)(param_1 + 0x18c);
      }
      else if (param_2 == 3) {
        iVar2 = *(int *)(param_1 + 0x1a4);
      }
      else {
        if (param_2 != 1) {
          return 0x7ffffffe;
        }
        iVar2 = *(int *)(param_1 + 0x178);
      }
    }
    if (iVar2 < 0) {
      puVar3 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar2);
      return *puVar3;
    }
  }
  return 0x7ffffffe;
}

/* FUN_0018854c @ 0x18854c (256 bytes) */
int FUN_0018854c(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = *(int **)(param_1 + 0xb0);
  iVar2 = *(int *)(piVar1[0x22] + 8);
  if (iVar2 == 0x1c) {
    for (iVar2 = 1; iVar4 = (**(code **)(*piVar1 + 0x14))(piVar1), iVar2 <= iVar4; iVar2 = iVar2 + 1
        ) {
      piVar1 = (int *)(iVar2 * 0x10 + 0x168 + param_1);
      iVar4 = 3;
      do {
        if (-1 < *piVar1) {
          return 0;
        }
        piVar1 = piVar1 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      piVar1 = *(int **)(param_1 + 0xb0);
    }
  }
  else {
    if (iVar2 < 0x1d) {
      if (iVar2 != 0x18) {
        return 0;
      }
    }
    else if (iVar2 != 0x1d) {
      if (iVar2 == 0x1e) {
        iVar4 = 1;
        iVar2 = param_1 + 0x170;
        do {
          piVar1 = (int *)(iVar2 + 8);
          iVar3 = 2;
          do {
            if (-1 < *piVar1) {
              return 0;
            }
            piVar1 = piVar1 + 1;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          iVar4 = iVar4 + 1;
          iVar2 = iVar2 + 0x10;
        } while (iVar4 != 3);
        if (*(int *)(param_1 + 0x1a0) < 0) {
          return 1;
        }
      }
      return 0;
    }
    for (iVar2 = 1; iVar4 = (**(code **)(*piVar1 + 0x14))(piVar1), iVar2 <= iVar4; iVar2 = iVar2 + 1
        ) {
      piVar1 = (int *)(iVar2 * 0x10 + 0x168 + param_1);
      iVar4 = 4;
      do {
        if (-1 < *piVar1) {
          return 0;
        }
        piVar1 = piVar1 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      piVar1 = *(int **)(param_1 + 0xb0);
    }
  }
  return 1;
}

/* FUN_0018864c @ 0x18864c (114 bytes) */
int FUN_0018864c(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8) == 0x32) {
    if (param_2 == 1) {
      return *(uint *)(param_1 + 0x178) >> 0x1f;
    }
    if (param_2 < 2) {
      if (param_2 == 0) {
        return 1;
      }
    }
    else if (param_2 == 2) {
      if (((*(int *)(param_1 + 0x178) < 0) && (*(int *)(param_1 + 0x180) < 0)) &&
         (*(int *)(param_1 + 0x184) < 0)) {
        return 1;
      }
    }
    else if (param_2 == 3) {
      return 1;
    }
  }
  return 0;
}

/* FUN_001886be @ 0x1886be (110 bytes) */
int FUN_001886be(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = *(int **)(param_1 + 0xb0);
  uVar3 = *(int *)(piVar4[0x22] + 8) - 0x12;
  if ((uVar3 < 0x20) && ((1 << ((byte)uVar3 & 0x1f) & 0x800000a7U) != 0)) {
    iVar5 = 1;
    while( true ) {
      iVar1 = (**(code **)(*piVar4 + 0x14))(piVar4);
      if (iVar1 < iVar5) break;
      piVar4 = *(int **)(param_1 + 0xb0);
      if (((piVar4[iVar5 * 6 + 0x28] & 1U) != 0) || ((piVar4[iVar5 * 6 + 0x28] & 2U) != 0))
      goto LAB_00188713;
      iVar5 = iVar5 + 1;
    }
    uVar2 = 1;
  }
  else {
LAB_00188713:
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_0018872c @ 0x18872c (31 bytes) */
int FUN_0018872c(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0x88) + 8) - 0x8bU < 2;
}

/* FUN_0018874c @ 0x18874c (429 bytes) */
int FUN_0018874c(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined1 *puVar6;
  int iVar7;
  int local_48;
  int local_40;
  undefined1 local_30 [4];
  int local_2c [7];
  
  if (*(int *)(param_1 + 0x30 + param_2 * 4) == 0) {
    iVar7 = param_1 + 0x168 + param_2 * 4;
    local_40 = 1;
    puVar6 = local_30;
    piVar5 = *(int **)(param_1 + 0xb0);
    local_48 = 0x98;
    for (; iVar2 = (**(code **)(*piVar5 + 0x14))(piVar5), local_40 <= iVar2; local_40 = local_40 + 1
        ) {
      iVar2 = *(int *)(iVar7 + 0x10);
      if (iVar2 < 0) {
        puVar3 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar2);
        uVar4 = ((int (*)())FUN_00186b2c)(*puVar3);
        *(undefined4 *)(puVar6 + 4) = uVar4;
        piVar5 = *(int **)(param_1 + 0xb0);
      }
      else {
        if (iVar2 < 1) {
          *(undefined4 *)(puVar6 + 4) = 0;
          piVar5 = *(int **)(param_1 + 0xb0);
          uVar1 = *(uint *)((int)piVar5 + local_48 + 0x20);
          if ((uVar1 & 2) != 0) {
            *(undefined4 *)(puVar6 + 4) = DAT_001f90bc[0];
            uVar1 = *(uint *)((int)piVar5 + local_48 + 0x20);
          }
        }
        else {
          iVar2 = FUN_001836c0(*(undefined4 *)(param_1 + 0x238),iVar2);
          iVar2 = *(int *)(iVar2 + 0xc);
          *(int *)(puVar6 + 4) = iVar2;
          piVar5 = *(int **)(param_1 + 0xb0);
          uVar1 = *(uint *)((int)piVar5 + local_48 + 0x20);
          if ((uVar1 & 2) != 0) {
            *(undefined4 *)(puVar6 + 4) = (DAT_001f90bc)[iVar2];
            uVar1 = *(uint *)((int)piVar5 + local_48 + 0x20);
          }
        }
        if ((uVar1 & 1) != 0) {
          *(undefined4 *)(puVar6 + 4) = *(undefined4 *)(&DAT_001f90a4 + *(int *)(puVar6 + 4) * 4);
        }
      }
      local_48 = local_48 + 0x18;
      puVar6 = puVar6 + 4;
      iVar7 = iVar7 + 0x10;
    }
    switch(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8)) {
    case 0x12:
      local_2c[0] = *(int *)((local_2c[1] + local_2c[0] * 6) * 4 + 0x1f8d80);
      break;
    case 0x13:
      local_2c[0] = *(int *)((local_2c[1] + local_2c[0] * 6) * 4 + 0x1f8b00);
      break;
    case 0x14:
      local_2c[0] = *(int *)((local_2c[2] +
                             *(int *)((local_2c[1] + local_2c[0] * 6) * 4 + 0x1f8b00) * 6) * 4 +
                            0x1f8d80);
      break;
    default:
      local_2c[0] = 0;
      break;
    case 0x17:
      local_2c[0] = *(int *)((local_2c[1] + local_2c[0] * 6) * 4 + 0x1f8c40);
      break;
    case 0x19:
      local_2c[0] = *(int *)((local_2c[1] + local_2c[0] * 6) * 4 + 0x1f8ba0);
      break;
    case 0x24:
    case 0x25:
    case 0x26:
      local_2c[0] = *(int *)((local_2c[2] + local_2c[1] * 6) * 4 + 0x1f8ce0);
      break;
    case 0x31:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43: ;
    }
    iVar7 = local_2c[0];
    if (*(char *)(*(int *)(param_1 + 0xb0) + 0x120) != '\0') {
      iVar7 = (DAT_001f908c)[local_2c[0]];
    }
    if (*(int *)(param_1 + 0x40 + param_2 * 4) == 0) {
      uVar4 = FUN_001851d0(*(undefined4 *)(param_1 + 0x238),param_2,param_1);
      *(undefined4 *)(param_1 + 0x40 + param_2 * 4) = uVar4;
    }
    *(int *)(*(int *)(param_1 + 0x40 + param_2 * 4) + 0xc) = iVar7;
    return;
  }
  return;
}

