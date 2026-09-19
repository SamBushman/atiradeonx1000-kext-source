#include "decls.h"

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
undefined4 FUN_0010aafc(double param_1)

{
  float *pfVar1;
  int iVar2;
  
  pfVar1 = (float *)&DAT_001af9e0;
  iVar2 = 7;
  do {
    if ((double)*pfVar1 == param_1) {
      return 1;
    }
    pfVar1 = pfVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}

/* FUN_0010ab40 @ 0x10ab40 (76 bytes) */
int FUN_0010ab40(double param_1)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  pfVar1 = (float *)&DAT_001af9e0;
  iVar3 = 7;
  do {
    if ((double)*pfVar1 == param_1) {
      return iVar2 + -3;
    }
    iVar2 = iVar2 + 1;
    pfVar1 = pfVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 0;
}

/* FUN_0010ab8c @ 0x10ab8c (172 bytes) */
undefined4 FUN_0010ab8c(double param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xfffffffd;
  if ((((param_1 != (double)FLOAT_001aa170) &&
       (uVar1 = 0xfffffffe, param_1 != (double)FLOAT_001aa110)) &&
      (uVar1 = 0xffffffff, param_1 != (double)FLOAT_001aa10c)) &&
     (((uVar1 = 0, param_1 != (double)FLOAT_001aa0e8 &&
       (uVar1 = 1, param_1 != (double)FLOAT_001aa108)) &&
      (uVar1 = 2, param_1 != (double)FLOAT_001aa104)))) {
    if (param_1 != (double)FLOAT_001aa100) {
      return 0;
    }
    uVar1 = 3;
  }
  *param_3 = uVar1;
  return 1;
}

/* FUN_0010ac38 @ 0x10ac38 (304 bytes) */
int FUN_0010ac38(param_1, param_2, param_3)
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
  int iVar7;
  int iVar8;
  int iVar9;
  
  if (0 < param_2) {
    (**(code **)(*param_1 + 0x14))();
  }
  if (0 < param_3) {
    (**(code **)(*param_1 + 0x14))(param_1);
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

/* FUN_0010ad68 @ 0x10ad68 (152 bytes) */
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
  uVar3 = DAT_001af9d4;
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

/* FUN_0010af38 @ 0x10af38 (448 bytes) */
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
int FUN_0010b184(double param_1,int *param_2,undefined4 param_3,int *param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  (**(code **)(*param_2 + 0x60))();
  do {
    iVar3 = FUN_001054ec(param_2,0);
    iVar6 = 1;
    if (*(char *)(iVar5 + iVar3 + 0x10) != '\x01') {
      for (; iVar3 = (**(code **)(*param_2 + 0x14))(param_2), iVar6 <= iVar3; iVar6 = iVar6 + 1) {
        iVar3 = FUN_00105594(param_2,iVar6);
        if (*(int *)(iVar3 + 0x98) == 0x33) {
          iVar4 = FUN_001054ec(param_2,iVar6);
          uVar2 = (uint)*(byte *)(iVar5 + iVar4 + 0x10);
          if ((uVar2 != 4) && ((double)*(float *)(uVar2 * 0x18 + iVar3 + 0x20) == param_1)) {
            *param_4 = iVar5;
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
bool FUN_0010b820(double param_1,double param_2)

{
  undefined4 uVar1;
  bool bVar2;
  
  uVar1 = ((int (*)())FUN_0010b5f8)();
  bVar2 = false;
  switch(uVar1) {
  case 0:
    bVar2 = param_1 == param_2;
    break;
  case 1:
    bVar2 = param_1 != param_2;
    break;
  case 2:
    bVar2 = param_2 < param_1;
    break;
  case 3:
    bVar2 = param_2 <= param_1;
    break;
  case 4:
    bVar2 = param_1 < param_2;
    break;
  case 5:
    bVar2 = param_1 <= param_2;
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
  int iVar3;
  
  iVar2 = (**(code **)(*param_1 + 0x14))();
  FUN_0011333c(*(undefined4 *)(param_1[0x22] + 8),param_6);
  iVar3 = FUN_00112f54();
  param_1[0x22] = iVar3;
  if (param_5 != 0) {
    iVar3 = FUN_00112f54(0x35);
    param_1[0x22] = iVar3;
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
int FUN_0010bc78(param_1)
  int *param_1;
{
  int iVar1;
  int iVar2;
  int local_28;
  int local_24;
  int local_20 [4];
  
  iVar1 = *(int *)(param_1[0x22] + 8);
  FUN_0011333c(iVar1);
  iVar2 = FUN_00112f54();
  param_1[0x22] = iVar2;
  iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
  FUN_000f33f8(&local_28,param_1[0x2d]);
  param_1[0x2d] = local_28;
  if (1 < iVar2) {
    FUN_000f33f8(&local_24,param_1[0x33]);
    param_1[0x33] = local_24;
  }
  if (2 < iVar2) {
    FUN_000f33f8(local_20,param_1[0x39]);
    param_1[0x39] = local_20[0];
  }
  if (iVar1 == 0x35) {
    FUN_00103d50(param_1 + 0x2f,1,param_1[0x34] & 1U ^ 1);
  }
  return iVar1 == 0x35;
}

/* FUN_0010bd50 @ 0x10bd50 (352 bytes) */
int FUN_0010bd50(param_1, param_2, param_3, param_4, param_5)
  undefined8 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  *(int *)(param_2 + 0x84) = param_4;
  FUN_000f79c4(param_1,param_1,param_1,param_1,param_2,*(undefined4 *)(param_5 + 0x6c4));
  uVar4 = DAT_001af9fc;
  if (param_4 == 0) {
    *(undefined4 *)(param_2 + 0x9c) = DAT_001af9fc;
  }
  else {
    iVar3 = FUN_001054ec(param_2,param_4);
    *(undefined4 *)(iVar3 + 0x10) = uVar4;
  }
  if ((*(uint *)(*(int *)(param_5 + 0x6c4) + 0x30) & 8) == 0) {
    iVar3 = *(int *)(param_4 * 0x18 + param_2 + 0x8c);
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
      uVar4 = *(undefined4 *)(param_5 + 0x378);
      puVar2 = (undefined4 *)FUN_00193e18(uVar4,0x240);
      puVar6 = puVar2 + 1;
      *puVar2 = uVar4;
      FUN_00173938(puVar6,iVar5,param_5);
      FUN_00173f1c(puVar6);
      FUN_00174e0c(puVar6);
      FUN_00173278(puVar6);
      FUN_00123424(iVar3,*(undefined4 *)(*(int *)(iVar5 + 0x158) + 0xb0),puVar6);
    }
    FUN_00106004(param_2,param_4,iVar5,0,param_5);
    return;
  }
  return;
}

/* FUN_0010bed0 @ 0x10bed0 (320 bytes) */
int FUN_0010bed0(double param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  
  *(int *)(param_5 + 0x228) = *(int *)(param_5 + 0x228) + 1;
  iVar2 = FUN_0010a240(0xa2,param_6);
  *(undefined4 *)(iVar2 + 0x98) = 0x36;
  *(undefined4 *)(iVar2 + 0x94) = *(undefined4 *)(iVar2 + 0x14c);
  *(undefined4 *)(iVar2 + 0x9c) = param_3;
  *(int *)(iVar2 + 0x84) = param_2;
  FUN_00106004(iVar2,1,param_4,*(uint *)(param_5 + 0x30) >> 7 & 1,param_6);
  uVar1 = DAT_001af9fc;
  iVar3 = FUN_001054ec(iVar2,1);
  *(undefined4 *)(iVar3 + 0x10) = uVar1;
  FUN_000f79c4(param_1,param_1,param_1,param_1,iVar2,param_5,2);
  iVar3 = FUN_001054ec(iVar2,2);
  *(undefined4 *)(iVar3 + 0x10) = uVar1;
  if (param_2 == 3) {
    dVar4 = (double)FLOAT_001aa0d4;
    if (param_1 == dVar4) {
      dVar4 = (double)FLOAT_001aa0e8;
    }
    FUN_000f79c4(dVar4,dVar4,dVar4,dVar4,iVar2,param_5,3);
    uVar1 = DAT_001af9fc;
    iVar3 = FUN_001054ec(iVar2,3);
    *(undefined4 *)(iVar3 + 0x10) = uVar1;
  }
  *(int *)(iVar2 + 0x160) = *(int *)(param_5 + 0x478) + 1;
  return iVar2;
}

/* FUN_0010c010 @ 0x10c010 (872 bytes) */
int FUN_0010c010(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int *piVar22;
  
  iVar14 = 0;
  uVar6 = FUN_00105594(param_1,1);
  uVar2 = param_1[0x2e];
  iVar7 = FUN_001054ec(param_1,1);
  uVar13 = *(undefined4 *)(iVar7 + 0x10);
  uVar8 = FUN_00105594(param_1,2);
  uVar3 = param_1[0x34];
  iVar7 = FUN_001054ec(param_1,2);
  uVar9 = *(undefined4 *)(iVar7 + 0x10);
  uVar10 = FUN_00105594(param_1,3);
  uVar4 = param_1[0x3a];
  iVar7 = FUN_001054ec(param_1,3);
  uVar11 = *(undefined4 *)(iVar7 + 0x10);
  iVar16 = param_1[1];
  iVar15 = param_1[0x56];
  iVar17 = param_1[0x26];
  iVar18 = param_1[0x25];
  iVar7 = FUN_001054ec(param_1,0);
  iVar19 = *(int *)(iVar7 + 0x10);
  iVar20 = param_1[0x48];
  iVar21 = param_1[0x49];
  iVar7 = FUN_00104054(param_1,*(undefined4 *)(param_3 + 0x6c4));
  if ((param_1[5] & 0x200U) != 0) {
    iVar14 = FUN_00105594(param_1,param_1[0x21]);
  }
  iVar12 = FUN_00105594(param_1,param_2);
  FUN_0019401c(param_1);
  iVar5 = *(int *)(param_1[0x22] + 8);
  if (iVar5 == 0x25) {
    bVar1 = param_2 == 2;
    iVar5 = 0xb2 - (uint)(param_2 == 3);
  }
  else if (iVar5 == 0x26) {
    bVar1 = param_2 == 2;
    iVar5 = (param_2 == 3) + 0xb1;
  }
  else if (iVar5 == 0x24) {
    if (param_2 == 3) {
      iVar5 = 0xb0;
      bVar1 = false;
    }
    else {
      iVar5 = 0xb3;
      bVar1 = false;
    }
  }
  else {
    iVar5 = 0;
    bVar1 = false;
  }
  FUN_00108174(param_1,iVar5,param_3);
  param_1[0x49] = iVar21;
  param_1[0x25] = iVar18;
  param_1[0x26] = iVar17;
  param_1[0x27] = iVar19;
  piVar22 = param_1 + 0x29;
  param_1[0x48] = iVar20;
  param_1[0x58] = iVar7 + *(int *)(*(int *)(param_3 + 0x6c4) + 0x478);
  FUN_000e7738(iVar15,iVar16,param_1);
  FUN_00106004(param_1,1,uVar6,0,param_3);
  FUN_00103d50(piVar22,1,uVar2 & 1);
  FUN_00103d50(piVar22,2,uVar2 >> 1 & 1);
  iVar7 = FUN_001054ec(param_1,1);
  *(undefined4 *)(iVar7 + 0x10) = uVar13;
  if (bVar1) {
    FUN_00103d50(piVar22,1,param_1[0x2e] & 1U ^ 1);
  }
  if (param_2 == 3) {
    FUN_00106004(param_1,2,uVar8,0,param_3);
    FUN_00103d50(param_1 + 0x2f,1,uVar3 & 1);
    FUN_00103d50(param_1 + 0x2f,2,uVar3 >> 1 & 1);
    iVar7 = FUN_001054ec(param_1,2);
    *(undefined4 *)(iVar7 + 0x10) = uVar9;
  }
  else {
    FUN_00106004(param_1,2,uVar10,0,param_3);
    FUN_00103d50(param_1 + 0x2f,1,uVar4 & 1);
    FUN_00103d50(param_1 + 0x2f,2,uVar4 >> 1 & 1);
    iVar7 = FUN_001054ec(param_1,2);
    *(undefined4 *)(iVar7 + 0x10) = uVar11;
  }
  if (iVar14 == 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x94);
  }
  else {
    UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x94);
    iVar12 = iVar14;
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,iVar12,param_3);
  return;
}

/* FUN_0010c37c @ 0x10c37c (256 bytes) */
int FUN_0010c37c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_1 + 0x84);
  if (0 < iVar4) {
    iVar3 = 1;
    do {
      iVar1 = FUN_001054ec(param_1,iVar3);
      iVar5 = iVar3;
      if (*(int *)(iVar1 + 0x10) == DAT_001af9fc) {
        do {
          if (iVar5 < iVar4) {
            FUN_00105e54(param_1,iVar5,param_1,iVar5 + 1);
            uVar2 = FUN_00105594(param_1,iVar5 + 1);
            FUN_00106004(param_1,iVar5,uVar2,0,param_2);
          }
          else {
            FUN_00104be8(param_1,iVar5);
            FUN_00106004(param_1,iVar5,0,0,param_2);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 <= iVar4);
        iVar4 = iVar4 + -1;
        *(int *)(param_1 + 0x84) = iVar4;
      }
      else {
        iVar3 = iVar3 + 1;
      }
    } while (iVar3 <= iVar4);
  }
  return;
}

/* FUN_0010c47c @ 0x10c47c (500 bytes) */
int FUN_0010c47c(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 local_38 [8];
  
  (**(code **)(*param_1 + 0x60))();
  piVar4 = (int *)FUN_00105594(param_1,1);
  iVar3 = *(int *)(piVar4[0x22] + 8);
  if (((((iVar3 - 0x16U < 2) || (iVar3 == 0x19)) || (iVar3 == 0x31)) ||
      (((iVar3 == 0x13 || (iVar3 == 0x14)) || (iVar3 == 0x12)))) &&
     (iVar8 = *(int *)(*(int *)(param_2 + 0x6c4) + 0x228),
     iVar3 = (**(code **)(*piVar4 + 0x14))(piVar4), iVar8 + iVar3 < *(int *)(param_2 + 0x664))) {
    bVar2 = true;
    if (1 < param_1[0x21]) {
      iVar3 = 2;
      bVar2 = true;
      do {
        iVar8 = FUN_00105594(param_1,iVar3);
        if (*(int *)(iVar8 + 0x98) == 0x33) {
          iVar5 = FUN_001054ec(param_1,iVar3);
          iVar7 = 0;
          local_38[0] = *(undefined4 *)(iVar5 + 0x10);
          iVar5 = 4;
          do {
            if ((*(byte *)((int)local_38 + iVar7) != 4) &&
               (*(float *)((uint)*(byte *)((int)local_38 + iVar7) * 0x18 + iVar8 + 0x20) !=
                FLOAT_001aa0d4)) {
              bVar2 = false;
              break;
            }
            iVar7 = iVar7 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= param_1[0x21]);
    }
    if ((piVar4[5] & 0x200U) != 0) {
      uVar10 = 0;
      do {
        iVar3 = FUN_001054ec(param_1,1);
        uVar9 = (uint)*(byte *)(uVar10 + iVar3 + 0x10);
        if (((uVar9 != 4) &&
            (iVar3 = FUN_001054ec(piVar4,0), *(char *)(uVar10 + iVar3 + 0x10) == '\x01')) &&
           (uVar9 != uVar10)) goto LAB_0010c648;
        bVar1 = uVar10 != 3;
        uVar10 = uVar10 + 1;
      } while (bVar1);
    }
    if ((!bVar2) && (iVar3 = ((int (*)())FUN_0010bb14)(piVar4), iVar3 == 0)) {
      return 0;
    }
    uVar6 = 1;
  }
  else {
LAB_0010c648:
    uVar6 = 0;
  }
  return uVar6;
}

/* FUN_0010c670 @ 0x10c670 (1240 bytes) */
int FUN_0010c670(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  double dVar12;
  undefined8 uVar13;
  undefined4 local_48;
  int local_44 [6];
  
  piVar2 = (int *)FUN_00105594(param_1,1);
  iVar3 = FUN_001054ec(param_1,1);
  iVar3 = FUN_0010453c(piVar2,param_3,*(undefined4 *)(iVar3 + 0x10));
  if (iVar3 == 0) {
    iVar9 = *(int *)(*(int *)(param_3 + 0x6c4) + 0x478);
    iVar3 = (**(code **)(*piVar2 + 0x5c))(piVar2);
    if (iVar3 == 0) {
      if (iVar9 < piVar2[0x58]) {
        piVar2[0x58] = piVar2[0x58] + 1;
      }
      else {
        piVar2[0x58] = iVar9 + 1;
      }
    }
    else {
      iVar8 = iVar9 + 1;
      piVar4 = (int *)FUN_0010445c(piVar2,param_3,0);
      piVar4[0x26] = 0x31;
      piVar4[0x25] = piVar4[0x53];
      FUN_000e7738(piVar2[0x56],piVar2,piVar4);
      piVar4[0x58] = iVar8;
      iVar3 = FUN_00105594(piVar4,1);
      if (iVar9 < *(int *)(iVar3 + 0x160)) {
        *(int *)(iVar3 + 0x160) = *(int *)(iVar3 + 0x160) + 1;
      }
      else {
        *(int *)(iVar3 + 0x160) = iVar8;
      }
      piVar2 = piVar4;
      if (1 < piVar4[0x21]) {
        iVar3 = FUN_00105594(piVar4,2);
        if (iVar9 < *(int *)(iVar3 + 0x160)) {
          *(int *)(iVar3 + 0x160) = *(int *)(iVar3 + 0x160) + 1;
        }
        else {
          *(int *)(iVar3 + 0x160) = iVar8;
        }
      }
    }
    FUN_00106004(param_2,1,piVar2,0,param_3);
    if ((*(uint *)(*(int *)(param_3 + 0x6c4) + 0x30) & 8) == 0) {
      FUN_001046c8(param_2,1,*(undefined4 *)(param_1 + 0xa4));
    }
    else {
      FUN_00105894(param_1,param_3);
    }
    iVar3 = 0;
    local_48 = DAT_001af9fc;
    do {
      iVar9 = FUN_001054ec(param_2,1);
      uVar11 = (uint)*(byte *)(iVar3 + iVar9 + 0x10);
      if (uVar11 != 4) {
        iVar9 = FUN_001054ec(param_1,1);
        if (*(char *)(uVar11 + iVar9 + 0x10) == '\x04') {
          if (1 < *(int *)(param_1 + 0x84)) {
            iVar9 = 2;
            do {
              iVar8 = FUN_001054ec(param_1,iVar9);
              uVar10 = (uint)*(byte *)(uVar11 + iVar8 + 0x10);
              if (uVar10 != 4) {
                uVar13 = FUN_00105594(param_1,iVar9);
                dVar12 = (double)*(float *)(uVar10 * 0x18 + (int)((ulonglong)uVar13 >> 0x20) + 0x20)
                ;
                uVar13 = ((int (*)())FUN_0010b184)(dVar12,param_2,(int)uVar13,local_44);
                iVar9 = local_44[0];
                iVar8 = (int)((ulonglong)uVar13 >> 0x20);
                if (iVar8 == 0) {
                  iVar9 = param_2[0x21];
                  ((int (*)())FUN_0010bd50)(dVar12,param_2,(int)uVar13,iVar9 + 1,param_3);
                  (**(code **)(*param_2 + 0x88))(param_2,iVar9 + 1,iVar3,iVar3);
                }
                else if (local_44[0] != iVar3) {
                  iVar5 = FUN_001054ec(param_2,iVar8);
                  (**(code **)(*param_2 + 0x88))
                            (param_2,iVar8,iVar3,*(undefined1 *)(iVar9 + iVar5 + 0x10));
                }
                break;
              }
              iVar9 = iVar9 + 1;
            } while (iVar9 <= *(int *)(param_1 + 0x84));
          }
        }
        else {
          iVar9 = FUN_001054ec(param_1,1);
          *(undefined1 *)((int)local_44 + iVar3 + -4) = *(undefined1 *)(uVar11 + iVar9 + 0x10);
        }
      }
      uVar6 = local_48;
      bVar1 = iVar3 != 3;
      iVar3 = iVar3 + 1;
    } while (bVar1);
    iVar3 = FUN_001054ec(param_2,1);
    *(undefined4 *)(iVar3 + 0x10) = uVar6;
  }
  else {
    iVar3 = FUN_001054ec(param_2,1);
    iVar9 = param_2[0x21];
    local_48 = *(undefined4 *)(iVar3 + 0x10);
    if (1 < iVar9) {
      iVar8 = 2;
      iVar3 = 1;
      do {
        uVar6 = FUN_00105594(param_2,iVar8);
        FUN_00106004(param_2,iVar3,uVar6,0,param_3);
        iVar5 = FUN_001054ec(param_2,iVar8);
        iVar5 = *(int *)(iVar5 + 0x10);
        if (iVar3 == 0) {
          param_2[0x27] = iVar5;
        }
        else {
          iVar7 = FUN_001054ec(param_2,iVar3);
          *(int *)(iVar7 + 0x10) = iVar5;
        }
        iVar8 = iVar8 + 1;
        iVar3 = iVar3 + 1;
      } while (iVar8 <= iVar9);
    }
    param_2[0x21] = iVar9 + -1;
    iVar3 = 0;
    do {
      uVar11 = (uint)*(byte *)((int)local_44 + iVar3 + -4);
      if ((uVar11 != 4) && (0 < *(int *)(param_1 + 0x84))) {
        iVar9 = 1;
        do {
          iVar8 = FUN_001054ec(param_1,iVar9);
          uVar10 = (uint)*(byte *)(uVar11 + iVar8 + 0x10);
          if (uVar10 != 4) {
            uVar13 = FUN_00105594(param_1,iVar9);
            dVar12 = (double)*(float *)(uVar10 * 0x18 + (int)((ulonglong)uVar13 >> 0x20) + 0x20);
            uVar13 = ((int (*)())FUN_0010b184)(dVar12,param_2,(int)uVar13,local_44);
            iVar9 = local_44[0];
            iVar8 = (int)((ulonglong)uVar13 >> 0x20);
            if (iVar8 == 0) {
              iVar9 = param_2[0x21];
              ((int (*)())FUN_0010bd50)(dVar12,param_2,(int)uVar13,iVar9 + 1,param_3);
              (**(code **)(*param_2 + 0x88))(param_2,iVar9 + 1,iVar3,iVar3);
            }
            else if (local_44[0] != iVar3) {
              iVar5 = FUN_001054ec(param_2,iVar8);
              (**(code **)(*param_2 + 0x88))
                        (param_2,iVar8,iVar3,*(undefined1 *)(iVar9 + iVar5 + 0x10));
            }
            break;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 <= *(int *)(param_1 + 0x84));
      }
      bVar1 = iVar3 != 3;
      iVar3 = iVar3 + 1;
    } while (bVar1);
    FUN_00105894(param_1,param_3);
  }
  return;
}

/* FUN_0010cb48 @ 0x10cb48 (1156 bytes) */
int FUN_0010cb48(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 extraout_r4;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  double dVar13;
  undefined8 uVar14;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c;
  undefined4 local_68;
  int local_64 [2];
  undefined4 local_5c [5];
  float local_48 [4];
  
  piVar3 = (int *)FUN_00105594(param_1,1);
  iVar2 = *(int *)(*(int *)(param_2 + 0x6c4) + 0x478);
  if (iVar2 < piVar3[0x58]) {
    piVar3[0x58] = piVar3[0x58] + 1;
  }
  else {
    piVar3[0x58] = iVar2 + 1;
  }
  iVar2 = FUN_001054ec(param_1,1);
  local_70 = *(undefined4 *)(iVar2 + 0x10);
  iVar2 = FUN_001054ec(param_1,0);
  local_78 = *(int *)(iVar2 + 0x10);
  iVar2 = FUN_001054ec(piVar3,0);
  local_74 = *(undefined4 *)(iVar2 + 0x10);
  if ((piVar3[5] & 0x200U) != 0) {
    iVar2 = 0;
    iVar12 = 4;
    do {
      if ((*(byte *)((int)&local_70 + iVar2) != 4) &&
         (*(char *)((int)&local_74 + (uint)*(byte *)((int)&local_70 + iVar2)) == '\x01')) {
        *(undefined1 *)((int)&local_78 + iVar2) = 1;
        *(undefined1 *)((int)&local_70 + iVar2) = 4;
      }
      iVar2 = iVar2 + 1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  iVar2 = piVar3[0x56];
  puVar8 = local_5c;
  for (iVar12 = 1; iVar5 = (**(code **)(*piVar3 + 0x14))(piVar3), iVar12 <= iVar5;
      iVar12 = iVar12 + 1) {
    iVar9 = 0;
    *(int *)(*(int *)(param_2 + 0x6c4) + 0x228) = *(int *)(*(int *)(param_2 + 0x6c4) + 0x228) + 1;
    piVar11 = (int *)FUN_0010a240(0xa2,param_2);
    *puVar8 = piVar11;
    piVar11[0x26] = 0x36;
    piVar11[0x25] = piVar11[0x53];
    piVar11[0x21] = 1;
    piVar11[0x4b] = 1;
    uVar7 = FUN_00105594(piVar3,iVar12);
    FUN_00106004(piVar11,1,uVar7,0,param_2);
    piVar11[0x27] = local_78;
    iVar5 = FUN_001054ec(piVar3,iVar12);
    local_68 = *(undefined4 *)(iVar5 + 0x10);
    do {
      if (*(byte *)((int)&local_70 + iVar9) != 4) {
        (**(code **)(*piVar11 + 0x88))
                  (piVar11,1,iVar9,
                   *(undefined1 *)((int)local_64 + (*(byte *)((int)&local_70 + iVar9) - 4)));
      }
      bVar1 = iVar9 != 3;
      iVar9 = iVar9 + 1;
    } while (bVar1);
    FUN_000e7700(iVar2,piVar3,piVar11);
    piVar4 = (int *)FUN_00105594(piVar11,1);
    iVar5 = (**(code **)(*piVar4 + 0x60))();
    if (iVar5 != 0) {
      uVar7 = FUN_00105594(piVar11,1);
      ((int (*)())FUN_0010c670)(uVar7,piVar11,param_2);
    }
    FUN_00106004(piVar3,iVar12,piVar11,0,param_2);
    puVar8 = puVar8 + 1;
    piVar11[0x58] = *(int *)(*(int *)(param_2 + 0x6c4) + 0x478) + 1;
  }
  iVar2 = 0;
  do {
    if ((*(char *)((int)&local_78 + iVar2) != '\x01') &&
       (*(char *)((int)&local_70 + iVar2) == '\x04')) {
      if (1 < *(int *)(param_1 + 0x84)) {
        iVar12 = 2;
        do {
          iVar5 = FUN_001054ec(param_1,iVar12);
          uVar10 = (uint)*(byte *)(iVar2 + iVar5 + 0x10);
          if (uVar10 != 4) {
            iVar12 = FUN_00105594(param_1,iVar12);
            uVar7 = *(undefined4 *)(uVar10 * 0x18 + iVar12 + 0x20);
            goto LAB_0010ce20;
          }
          iVar12 = iVar12 + 1;
        } while (iVar12 <= *(int *)(param_1 + 0x84));
      }
      uVar7 = 0;
LAB_0010ce20:
      puVar8 = local_5c;
      for (iVar12 = 1; iVar5 = (**(code **)(*piVar3 + 0x14))(piVar3), iVar12 <= iVar5;
          iVar12 = iVar12 + 1) {
        ((float * (*)())FUN_0010b93c)(local_48,piVar3,iVar12,uVar7,param_2);
        dVar13 = (double)local_48[0];
        piVar11 = (int *)*puVar8;
        uVar14 = ((int (*)())FUN_0010b184)(dVar13,piVar11,extraout_r4,local_64);
        iVar5 = local_64[0];
        iVar9 = (int)((ulonglong)uVar14 >> 0x20);
        if (iVar9 == 0) {
          iVar5 = piVar11[0x21];
          ((int (*)())FUN_0010bd50)(dVar13,piVar11,(int)uVar14,iVar5 + 1,param_2);
          (**(code **)(*piVar11 + 0x88))(piVar11,iVar5 + 1,iVar2,iVar2);
        }
        else {
          iVar6 = FUN_001054ec(piVar11,iVar9);
          (**(code **)(*piVar11 + 0x88))(piVar11,iVar9,iVar2,*(undefined1 *)(iVar5 + iVar6 + 0x10));
        }
        puVar8 = puVar8 + 1;
      }
    }
    local_6c = DAT_001afa00;
    bVar1 = iVar2 == 3;
    iVar2 = iVar2 + 1;
    if (bVar1) {
      iVar2 = 0;
      piVar3[0x27] = local_78;
      iVar12 = 4;
      do {
        if (*(char *)((int)&local_78 + iVar2) == '\x01') {
          *(undefined1 *)((int)&local_6c + iVar2) = 4;
        }
        iVar2 = iVar2 + 1;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
      for (iVar2 = 1; iVar5 = (**(code **)(*piVar3 + 0x14))(piVar3), iVar12 = local_6c,
          iVar2 <= iVar5; iVar2 = iVar2 + 1) {
        if (iVar2 == 0) {
          piVar3[0x27] = local_6c;
        }
        else {
          iVar5 = FUN_001054ec(piVar3,iVar2);
          *(int *)(iVar5 + 0x10) = iVar12;
        }
      }
      FUN_00105894(param_1,param_2);
      return piVar3;
    }
  } while( true );
}

/* FUN_0010cfcc @ 0x10cfcc (400 bytes) */
int FUN_0010cfcc(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_28 [2];
  
  piVar2 = (int *)FUN_00105594(param_2,param_3);
  iVar3 = (**(code **)(*piVar2 + 0x60))();
  if (iVar3 != 0) {
    iVar3 = FUN_001054ec(param_2,0);
    iVar3 = FUN_000f37b8(*(undefined4 *)(iVar3 + 0x10));
    iVar4 = FUN_001054ec(param_2,param_3);
    bVar1 = *(byte *)(iVar3 + iVar4 + 0x10);
    if (-1 < iVar3) {
      FUN_001054ec(piVar2,0);
    }
    for (iVar3 = 1; iVar4 = (**(code **)(*piVar2 + 0x14))(piVar2), iVar3 <= iVar4; iVar3 = iVar3 + 1
        ) {
      iVar4 = FUN_001054ec(piVar2,iVar3);
      if (*(char *)((uint)bVar1 + iVar4 + 0x10) != '\x04') {
        uVar5 = FUN_00105594(piVar2,iVar3);
        FUN_00106004(param_2,param_3,uVar5,1,*(undefined4 *)(param_4 + 8));
        iVar4 = FUN_001049c4(piVar2,param_4);
        if (iVar4 != 0) {
          (**(code **)(*piVar2 + 0xc))(piVar2,1,*(undefined4 *)(param_4 + 8));
        }
        iVar3 = FUN_001054ec(piVar2,iVar3);
        uVar5 = *(undefined4 *)(iVar3 + 0x10);
        iVar3 = FUN_001054ec(param_2,param_3);
        FUN_000f2bdc(local_28,uVar5,*(undefined4 *)(iVar3 + 0x10));
        *param_1 = local_28[0];
        return param_1;
      }
    }
  }
  iVar3 = FUN_001054ec(param_2,param_3);
  *param_1 = *(undefined4 *)(iVar3 + 0x10);
  return param_1;
}

/* FUN_0010d15c @ 0x10d15c (504 bytes) */
int FUN_0010d15c(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 local_78;
  int local_74;
  undefined4 local_64;
  
  iVar13 = *(int *)(param_4 + 0x6c4);
  iVar7 = param_1[2];
  iVar8 = param_1[0x56];
  iVar9 = param_1[4];
  iVar2 = FUN_00104054(param_1,iVar13);
  iVar3 = FUN_001054ec(param_1,0);
  iVar3 = *(int *)(iVar3 + 0x10);
  local_64 = 0;
  local_78 = 0;
  local_74 = 0;
  iVar11 = param_1[0x48];
  iVar12 = param_1[0x49];
  if ((param_1[5] & 0x200U) != 0) {
    FUN_00104d3c(param_1,&local_78);
  }
  uVar4 = FUN_00105594(param_1,param_2);
  uVar1 = param_1[param_2 * 6 + 0x28];
  iVar14 = 1;
  iVar5 = FUN_001054ec(param_1,param_2);
  uVar10 = *(undefined4 *)(iVar5 + 0x10);
  if (param_3 == 0) {
    for (; iVar5 = (**(code **)(*param_1 + 0x14))(param_1), iVar14 <= iVar5; iVar14 = iVar14 + 1) {
      if (iVar14 != param_2) {
        uVar6 = FUN_00105594(param_1,iVar14);
        FUN_00105894(uVar6,param_4);
      }
    }
    FUN_0019401c(param_1);
  }
  else {
    (**(code **)(*param_1 + 0xc))(param_1,1,param_4);
  }
  FUN_00108448(param_1,0x31,*(undefined4 *)(iVar13 + 8));
  param_1[4] = iVar9;
  param_1[0x58] = iVar2 + *(int *)(iVar13 + 0x478);
  param_1[0x26] = 0;
  param_1[0x25] = param_1[0x53];
  param_1[0x48] = iVar11;
  param_1[0x49] = iVar12;
  param_1[0x27] = iVar3;
  FUN_00106004(param_1,1,uVar4,0,param_4);
  FUN_00103d50(param_1 + 0x29,1,uVar1 & 1);
  FUN_00103d50(param_1 + 0x29,2,uVar1 >> 1 & 1);
  iVar2 = FUN_001054ec(param_1,1);
  *(undefined4 *)(iVar2 + 0x10) = uVar10;
  if (local_74 != 0) {
    FUN_00106b48(param_1,&local_78,param_3,param_4);
  }
  FUN_000e7700(iVar8,iVar7,param_1);
  return;
}

/* FUN_0010d358 @ 0x10d358 (372 bytes) */
int FUN_0010d358(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_58 [4];
  float local_54;
  undefined1 auStack_40 [4];
  float local_3c;
  
  iVar1 = FUN_00112f78(*(undefined4 *)(*(int *)(param_1 + 0x88) + 8));
  if (iVar1 != 0) {
    iVar1 = FUN_001054ec(param_1,0);
    uVar3 = *(undefined4 *)(iVar1 + 0x10);
    iVar1 = FUN_000f5cf0(param_1,1,uVar3,auStack_58);
    iVar2 = FUN_000f5cf0(param_1,2,uVar3,auStack_40);
    if (iVar1 == 0) {
      iVar1 = FUN_00105594(param_1,1);
      uVar4 = *(undefined4 *)(iVar1 + 0x98);
      iVar1 = FUN_00105594(param_1,2);
      uVar3 = *(undefined4 *)(iVar1 + 0x98);
      iVar1 = FUN_00126708(uVar4);
      if (iVar1 == 0) {
        return;
      }
      iVar1 = FUN_00126708(uVar3);
      if (iVar1 != 0) {
        return;
      }
    }
    else if (iVar2 != 0) {
      if ((((local_54 != FLOAT_001aa0e8) && (local_54 != FLOAT_001aa114)) &&
          (local_54 != FLOAT_001aa108)) && (local_54 != FLOAT_001aa1c8)) {
        return;
      }
      if (local_3c == FLOAT_001aa0e8) {
        return;
      }
      if (local_3c == FLOAT_001aa114) {
        return;
      }
      if (local_3c == FLOAT_001aa108) {
        return;
      }
      if (local_3c == FLOAT_001aa1c8) {
        return;
      }
    }
    ((int (*)())FUN_0010ac38)(param_1,1,2,param_2);
  }
  return;
}

/* FUN_0010d4cc @ 0x10d4cc (608 bytes) */
int FUN_0010d4cc(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 uVar12;
  int *piVar13;
  
  uVar4 = FUN_00105594(param_1,1);
  uVar1 = *(uint *)(param_1 + 0xb8) & 1;
  uVar11 = *(uint *)(param_1 + 0xb8) >> 1 & 1;
  iVar5 = FUN_001054ec(param_1,1);
  uVar10 = *(undefined4 *)(iVar5 + 0x10);
  uVar6 = FUN_00105594(param_1,2);
  uVar2 = *(uint *)(param_1 + 0xd0) & 1;
  uVar9 = *(uint *)(param_1 + 0xd0) >> 1 & 1;
  iVar5 = FUN_001054ec(param_1,2);
  uVar3 = DAT_001af9dc;
  piVar13 = *(int **)(param_1 + 0x158);
  uVar8 = *(undefined4 *)(iVar5 + 0x10);
  uVar12 = *(undefined4 *)(param_1 + 0x14c);
  iVar5 = (**(code **)(*piVar13 + 0x24))(piVar13);
  if (iVar5 != 0) {
    FUN_000e7804(piVar13);
    piVar13[0x4c] = 0;
  }
  FUN_0019401c(param_1);
  iVar5 = ((int (*)())FUN_0010b5f8)(param_1);
  uVar7 = *(undefined4 *)(PTR_DAT_001e8c70 + iVar5 * 4);
  iVar5 = *(int *)(PTR_DAT_001e8c6c + iVar5 * 4);
  *(int *)(*(int *)(param_2 + 0x6c4) + 0x21c) = *(int *)(*(int *)(param_2 + 0x6c4) + 0x21c) + 1;
  FUN_00108174(param_1,uVar7,param_2);
  *(undefined4 *)(param_1 + 0x94) = uVar12;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = uVar3;
  if (iVar5 == 0) {
    FUN_00106004(param_1,1,uVar4,0,param_2);
    FUN_00103d50(param_1 + 0xa4,1,uVar1);
    FUN_00103d50(param_1 + 0xa4,2,uVar11);
    iVar5 = FUN_001054ec(param_1,1);
    *(undefined4 *)(iVar5 + 0x10) = uVar10;
    FUN_00106004(param_1,2,uVar6,0,param_2);
    FUN_00103d50(param_1 + 0xbc,1,uVar2);
    FUN_00103d50(param_1 + 0xbc,2,uVar9);
    iVar5 = FUN_001054ec(param_1,2);
    *(undefined4 *)(iVar5 + 0x10) = uVar8;
  }
  else {
    FUN_00106004(param_1,2,uVar4,0,param_2);
    FUN_00103d50(param_1 + 0xbc,1,uVar1);
    FUN_00103d50(param_1 + 0xbc,2,uVar11);
    iVar5 = FUN_001054ec(param_1,2);
    *(undefined4 *)(iVar5 + 0x10) = uVar10;
    FUN_00106004(param_1,1,uVar6,0,param_2);
    FUN_00103d50(param_1 + 0xa4,1,uVar2);
    FUN_00103d50(param_1 + 0xa4,2,uVar9);
    iVar5 = FUN_001054ec(param_1,1);
    *(undefined4 *)(iVar5 + 0x10) = uVar8;
  }
  return;
}

/* FUN_0010d730 @ 0x10d730 (844 bytes) */
int FUN_0010d730(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  uint param_3;
  int param_4;
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int iVar16;
  
  uVar3 = FUN_00105594(param_1,1);
  uVar1 = *(uint *)(param_1 + 0xb8) & 1;
  uVar12 = *(uint *)(param_1 + 0xb8) >> 1 & 1;
  iVar4 = FUN_001054ec(param_1,1);
  uVar10 = *(undefined4 *)(iVar4 + 0x10);
  uVar5 = FUN_00105594(param_1,2);
  uVar2 = *(uint *)(param_1 + 0xd0) & 1;
  uVar11 = *(uint *)(param_1 + 0xd0) >> 1 & 1;
  iVar4 = FUN_001054ec(param_1,2);
  iVar16 = *(int *)(param_4 + 0x6c4);
  uVar9 = *(undefined4 *)(iVar4 + 0x10);
  iVar4 = FUN_00104054(param_1,iVar16);
  uVar13 = *(undefined4 *)(param_1 + 0x98);
  uVar15 = *(undefined4 *)(param_1 + 0x94);
  iVar6 = FUN_001054ec(param_1,0);
  uVar14 = *(undefined4 *)(iVar6 + 0x10);
  FUN_0019401c(param_1);
  iVar6 = (**(code **)(*param_2 + 0x48))(param_2);
  if ((iVar6 != 0) && (((int)*(char *)(param_2 + 0x57) >> (param_3 >> 0x18 & 0x3f) & 1U) != 0)) {
    uVar7 = FUN_00105594(param_1,1);
    uVar8 = FUN_00105594(param_1,2);
    *(int *)(iVar16 + 0x220) = *(int *)(iVar16 + 0x220) + 1;
    FUN_00108448(param_1,0x31,param_4);
    *(undefined4 *)(param_1 + 0x94) = uVar15;
    *(undefined4 *)(param_1 + 0x98) = uVar13;
    *(undefined4 *)(param_1 + 0x9c) = uVar14;
    *(int *)(param_1 + 0x160) = iVar4 + *(int *)(iVar16 + 0x478);
    if ((float)param_2[(param_3 >> 0x18) * 6 + 8] == FLOAT_001aa0d4) {
      FUN_00106004(param_1,1,uVar3,0,param_4);
      FUN_00103d50(param_1 + 0xa4,1,uVar1);
      FUN_00103d50(param_1 + 0xa4,2,uVar12);
      iVar4 = FUN_001054ec(param_1,1);
      *(undefined4 *)(iVar4 + 0x10) = uVar10;
      uVar7 = uVar8;
    }
    else {
      FUN_00106004(param_1,1,uVar5,0,param_4);
      FUN_00103d50(param_1 + 0xa4,1,uVar2);
      FUN_00103d50(param_1 + 0xa4,2,uVar11);
      iVar4 = FUN_001054ec(param_1,1);
      *(undefined4 *)(iVar4 + 0x10) = uVar9;
    }
    FUN_00105894(uVar7,param_4);
    return;
  }
  *(int *)(iVar16 + 0x224) = *(int *)(iVar16 + 0x224) + 1;
  FUN_00108304(param_1,0x24,param_4);
  *(undefined4 *)(param_1 + 0x94) = uVar15;
  *(undefined4 *)(param_1 + 0x98) = uVar13;
  *(undefined4 *)(param_1 + 0x9c) = uVar14;
  *(int *)(param_1 + 0x160) = iVar4 + *(int *)(iVar16 + 0x478);
  FUN_00106004(param_1,1,param_2,0,param_4);
  if (*(int *)(iVar16 + 0x478) < param_2[0x58]) {
    param_2[0x58] = param_2[0x58] + 1;
  }
  else {
    param_2[0x58] = *(int *)(iVar16 + 0x478) + 1;
  }
  iVar4 = FUN_001054ec(param_1,1);
  *(uint *)(iVar4 + 0x10) = param_3;
  FUN_00106004(param_1,3,uVar3,0,param_4);
  FUN_00103d50(param_1 + 0xd4,1,uVar1);
  FUN_00103d50(param_1 + 0xd4,2,uVar12);
  iVar4 = FUN_001054ec(param_1,3);
  *(undefined4 *)(iVar4 + 0x10) = uVar10;
  FUN_00106004(param_1,2,uVar5,0,param_4);
  FUN_00103d50(param_1 + 0xbc,1,uVar2);
  FUN_00103d50(param_1 + 0xbc,2,uVar11);
  iVar4 = FUN_001054ec(param_1,2);
  *(undefined4 *)(iVar4 + 0x10) = uVar9;
  return;
}

/* FUN_0010da84 @ 0x10da84 (84 bytes) */
int FUN_0010da84(param_1)
  int param_1;
{
  *(undefined4 *)(((unsigned char *)0x00001730) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x0000172c) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001728) + param_1) = 0;
  _memset((void *)(param_1 + 0x68),0,0xd00);
  _memset((void *)(param_1 + 0xd68),0,0x9c0);
  return;
}

/* FUN_0010dad8 @ 0x10dad8 (128 bytes) */
int FUN_0010dad8(param_1)
  undefined4 *param_1;
{
  param_1[5] = 1;
  param_1[4] = 1;
  param_1[0x19] = 0;
  param_1[2] = 0;
  param_1[6] = 0;
  *param_1 = &PTR_FUN_001ea5b0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  return;
}

/* FUN_0010db58 @ 0x10db58 (128 bytes) */
int FUN_0010db58(param_1)
  undefined4 *param_1;
{
  param_1[5] = 1;
  param_1[4] = 1;
  param_1[0x19] = 0;
  param_1[2] = 0;
  param_1[6] = 0;
  *param_1 = &PTR_FUN_001ea5b0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  return;
}

/* FUN_0010dbd8 @ 0x10dbd8 (36 bytes) */
int FUN_0010dbd8(param_1, param_2)
  int param_1;
  uint param_2;
{
  param_1 = ((int)param_2 >> 3) + param_1;
  ((unsigned char *)0x00001734)[param_1] = (byte)(1 << (param_2 & 7)) | ((unsigned char *)0x00001734)[param_1];
  return;
}

/* FUN_0010dc20 @ 0x10dc20 (124 bytes) */
int FUN_0010dc20(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 5;
  iVar2 = param_1;
  do {
    ((unsigned char *)0x00001734)[iVar2] = 0xff;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = 6;
  iVar2 = param_1;
  do {
    ((unsigned char *)0x00001739)[iVar2] = 0;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar2 = 0x28;
  do {
    ((int (*)())FUN_0010dbd8)(param_1,iVar2);
    bVar1 = iVar2 != 0x2c;
    iVar2 = iVar2 + 1;
  } while (bVar1);
  return;
}

/* FUN_0010dc9c @ 0x10dc9c (28 bytes) */
int FUN_0010dc9c(param_1, param_2)
  int param_1;
  uint param_2;
{
  return (int)(uint)(byte)((unsigned char *)0x00001734)[((int)param_2 >> 3) + param_1] >> (param_2 & 7) & 1;
}

/* FUN_0010dcc4 @ 0x10dcc4 (56 bytes) */
int FUN_0010dcc4()
{
  int in_stack_00000038;
  
  if (*(int *)(in_stack_00000038 + 0x6c4) != 0) {
    FUN_000e1534(in_stack_00000038,0xf);
  }
  return 0;
}

/* FUN_0010dd08 @ 0x10dd08 (68 bytes) */
int FUN_0010dd08(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  
  iVar1 = FUN_00109810(0xa4,param_3);
  *(undefined4 *)(iVar1 + 300) = param_2;
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & 0xffff7fff;
  return;
}

/* FUN_0010dd54 @ 0x10dd54 (120 bytes) */
int FUN_0010dd54(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(iVar4 + 0xc78) = 0;
  *(undefined4 *)(iVar4 + 0x2a0) = 0;
  puVar3 = PTR_DAT_001e8c84;
  puVar2 = PTR_FUN_001e8c7c;
  puVar1 = PTR_DAT_001e8c78;
  *(undefined4 *)(iVar4 + 0xc60) = 0x4c;
  *(undefined **)(iVar4 + 0xd08) = puVar1;
  *(undefined **)(iVar4 + 0xc9c) = puVar3;
  *(undefined4 *)(iVar4 + 0xc70) = 4;
  *(undefined **)(iVar4 + 0xc74) = puVar2;
  *(undefined4 *)(iVar4 + 0x288) = 0x4d;
  *(undefined4 *)(iVar4 + 0x298) = 4;
  *(undefined **)(iVar4 + 0x29c) = puVar2;
  *(undefined **)(*(int *)(param_1 + 0xc) + 0xe28) = puVar3;
  return;
}

/* FUN_0010ddcc @ 0x10ddcc (12 bytes) */
int FUN_0010ddcc(param_1)
  int param_1;
{
  return *(undefined4 *)(*(int *)(param_1 + 0x30c) + 0x60);
}

/* FUN_0010ddd8 @ 0x10ddd8 (12 bytes) */
int FUN_0010ddd8(param_1)
  int param_1;
{
  return *(undefined4 *)(*(int *)(param_1 + 0x30c) + 100);
}

/* FUN_0010ddfc @ 0x10ddfc (56 bytes) */
int FUN_0010ddfc()
{
  int in_r9;
  
  if (*(int *)(in_r9 + 0x6c4) != 0) {
    FUN_000e1534(in_r9,0xf);
  }
  return 0;
}

/* FUN_0010de34 @ 0x10de34 (56 bytes) */
int FUN_0010de34()
{
  int in_stack_0000003c;
  
  if (*(int *)(in_stack_0000003c + 0x6c4) != 0) {
    FUN_000e1534(in_stack_0000003c,0xf);
  }
  return 0;
}

/* FUN_0010de6c @ 0x10de6c (140 bytes) */
int FUN_0010de6c(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  uint *param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar1 = *param_4;
  uVar5 = *(undefined4 *)(param_2 + 0x3ac);
  uVar4 = *(undefined4 *)(param_2 + 8);
  uVar2 = FUN_000ec208(param_2,*param_4 >> 0x10 & 0x3f);
  uVar2 = FUN_00127608(uVar5,uVar2,(int)(short)uVar1,0);
  iVar3 = FUN_00109810(0xa4,uVar4);
  FUN_001046c8(iVar3,0,uVar2);
  *(int *)(iVar3 + 300) = (int)(short)uVar1;
  FUN_000f92fc(param_2,iVar3,param_6);
  return;
}

/* FUN_0010defc @ 0x10defc (340 bytes) */
int FUN_0010defc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = 0;
  if (iVar1 != 0) {
    puVar3 = *(undefined4 **)(iVar1 + 0x60);
    if (puVar3 != (undefined4 *)0x0) {
      (**(code **)*puVar3)(puVar3);
      (**(code **)(param_2 + 0x34c))(*(undefined4 *)(param_2 + 0x354),puVar3);
      iVar1 = *(int *)(param_1 + 4);
    }
    if (*(int *)(iVar1 + 100) != 0) {
      (**(code **)(param_2 + 0x34c))(*(undefined4 *)(param_2 + 0x354));
      iVar1 = *(int *)(param_1 + 4);
    }
    (**(code **)(param_2 + 0x34c))(*(undefined4 *)(param_2 + 0x354),iVar1);
    iVar2 = *(int *)(param_1 + 4);
  }
  iVar1 = *(int *)(param_1 + 8);
  if ((iVar2 != iVar1) && (iVar1 != 0)) {
    puVar3 = *(undefined4 **)(iVar1 + 0x60);
    if (puVar3 != (undefined4 *)0x0) {
      (**(code **)*puVar3)(puVar3);
      (**(code **)(param_2 + 0x34c))(*(undefined4 *)(param_2 + 0x354),puVar3);
      iVar1 = *(int *)(param_1 + 8);
    }
    if (*(int *)(iVar1 + 100) != 0) {
      (**(code **)(param_2 + 0x34c))(*(undefined4 *)(param_2 + 0x354),*(int *)(iVar1 + 100));
      iVar1 = *(int *)(param_1 + 8);
    }
    (**(code **)(param_2 + 0x34c))(*(undefined4 *)(param_2 + 0x354),iVar1);
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

/* FUN_0010e050 @ 0x10e050 (172 bytes) */
int FUN_0010e050(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  int iVar2;
  
  param_1[2] = 0;
  puVar1 = PTR_DAT_001e8c88;
  param_1[1] = 0;
  *param_1 = puVar1 + 8;
  *param_1 = PTR_DAT_001e8c74 + 8;
  iVar2 = FUN_000e1564(param_2,((unsigned char *)0x00001740));
  if (iVar2 != 0) {
    FUN_0012a578(iVar2,param_2,1);
  }
  param_1[1] = iVar2;
  iVar2 = FUN_000e1564(param_2,((unsigned char *)0x00001744));
  if (iVar2 != 0) {
    FUN_00129130(iVar2,param_2,1);
  }
  param_1[2] = iVar2;
  return;
}

/* FUN_0010e114 @ 0x10e114 (172 bytes) */
int FUN_0010e114(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  int iVar2;
  
  param_1[2] = 0;
  puVar1 = PTR_DAT_001e8c88;
  param_1[1] = 0;
  *param_1 = puVar1 + 8;
  *param_1 = PTR_DAT_001e8c74 + 8;
  iVar2 = FUN_000e1564(param_2,((unsigned char *)0x00001740));
  if (iVar2 != 0) {
    FUN_0012a578(iVar2,param_2,1);
  }
  param_1[1] = iVar2;
  iVar2 = FUN_000e1564(param_2,((unsigned char *)0x00001744));
  if (iVar2 != 0) {
    FUN_00129130(iVar2,param_2,1);
  }
  param_1[2] = iVar2;
  return;
}

/* FUN_0010e1d8 @ 0x10e1d8 (176 bytes) */
int FUN_0010e1d8(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar1 = PTR_DAT_001e8c80;
  puVar3 = PTR_DAT_001e8c74 + 8;
  param_1[2] = 0;
  *param_1 = puVar3;
  param_1[1] = 0;
  *param_1 = puVar1 + 8;
  iVar2 = FUN_000e1564(param_2,((unsigned char *)0x00001740));
  if (iVar2 != 0) {
    FUN_0012a8bc(iVar2,param_2,1);
  }
  param_1[1] = iVar2;
  iVar2 = FUN_000e1564(param_2,0x1944);
  if (iVar2 != 0) {
    FUN_001920e0(iVar2,param_2,1);
  }
  param_1[2] = iVar2;
  return;
}

/* FUN_0010e368 @ 0x10e368 (76 bytes) */
int FUN_0010e368(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = 3;
  if (param_1 != 0x18) {
    iVar2 = FUN_0010406c();
    iVar1 = 1;
    if (iVar2 != 0x15) {
      iVar1 = (uint)(iVar2 == 0x16) << 1;
    }
  }
  return iVar1;
}

/* FUN_0010e3b4 @ 0x10e3b4 (88 bytes) */
int FUN_0010e3b4(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (0 < param_2) {
    iVar2 = 0;
    iVar3 = *(int *)(param_2 * 4 + param_1 + 4);
    if (iVar3 == *(int *)(param_1 + 4)) {
      return iVar2;
    }
    while( true ) {
      iVar2 = iVar2 + 1;
      param_2 = param_2 + -1;
      if (param_2 == 0) break;
      piVar1 = (int *)(param_1 + 8);
      param_1 = param_1 + 4;
      if (iVar3 == *piVar1) {
        return iVar2;
      }
    }
  }
  return -1;
}

/* FUN_0010e40c @ 0x10e40c (84 bytes) */
int FUN_0010e40c(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_1 != 0x16) {
    if (param_1 != 0x17) {
      return param_2;
    }
    if (param_2 == 0) {
      return 1;
    }
    if (param_2 != 1) {
      return param_2;
    }
    return 3;
  }
  if (param_2 == 0) {
    return param_2;
  }
  if (param_2 != 1) {
    return param_2;
  }
  return 2;
}

/* FUN_0010e460 @ 0x10e460 (140 bytes) */
int FUN_0010e460(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  if ((*param_1 != *param_2) && (param_1[5] <= param_2[5])) {
    iVar2 = 0;
    do {
      if (param_1[1] == 0) {
        *(undefined4 *)(param_3 + iVar2) = 0xffffffff;
      }
      else {
        iVar5 = 4;
        iVar4 = 0;
        piVar3 = param_2;
        while (param_1[1] != piVar3[1]) {
          iVar4 = iVar4 + 1;
          piVar3 = piVar3 + 1;
          iVar5 = iVar5 + -1;
          if (iVar5 == 0) {
            return 0;
          }
        }
        *(int *)(iVar2 + param_3) = iVar4;
      }
      bVar1 = iVar2 != 0xc;
      param_1 = param_1 + 1;
      iVar2 = iVar2 + 4;
    } while (bVar1);
    return 1;
  }
  return 0;
}

