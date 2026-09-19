#include "decls.h"

/* FUN_001beb58 @ 0x1beb58 (16 bytes) */
int FUN_001beb58()
{
  return DAT_001cbed0;
}

/* FUN_001beb68 @ 0x1beb68 (7 bytes) */
int FUN_001beb68()
{
  return 0;
}

/* FUN_001beb70 @ 0x1beb70 (7 bytes) */
int FUN_001beb70()
{
  return 0;
}

/* FUN_001beb78 @ 0x1beb78 (7 bytes) */
int FUN_001beb78()
{
  return 0;
}

/* FUN_001beb80 @ 0x1beb80 (7 bytes) */
int FUN_001beb80()
{
  return 0;
}

/* FUN_001beb88 @ 0x1beb88 (5 bytes) */
int FUN_001beb88()
{
  return;
}

/* FUN_001beb8e @ 0x1beb8e (7 bytes) */
int FUN_001beb8e()
{
  return 0;
}

/* FUN_001beb96 @ 0x1beb96 (5 bytes) */
int FUN_001beb96()
{
  return;
}

/* FUN_001beb9c @ 0x1beb9c (10 bytes) */
int FUN_001beb9c()
{
  return 0x30;
}

/* FUN_001beba6 @ 0x1beba6 (5 bytes) */
int FUN_001beba6()
{
  return;
}

/* FUN_001bebac @ 0x1bebac (5 bytes) */
int FUN_001bebac()
{
  return;
}

/* FUN_001bebb2 @ 0x1bebb2 (5 bytes) */
int FUN_001bebb2()
{
  return;
}

/* FUN_001bebb8 @ 0x1bebb8 (24 bytes) */
int FUN_001bebb8(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213581 + 8;
  return;
}

/* FUN_001bebd0 @ 0x1bebd0 (31 bytes) */
int FUN_001bebd0(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213581 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001bebf0 @ 0x1bebf0 (5 bytes) */
int FUN_001bebf0()
{
  return;
}

/* FUN_001bebf6 @ 0x1bebf6 (7 bytes) */
int FUN_001bebf6()
{
  return 0;
}

/* FUN_001bebfe @ 0x1bebfe (5 bytes) */
int FUN_001bebfe()
{
  return;
}

/* FUN_001bec04 @ 0x1bec04 (24 bytes) */
int FUN_001bec04(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_001bec1c @ 0x1bec1c (31 bytes) */
int FUN_001bec1c(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213819 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001bec3c @ 0x1bec3c (10 bytes) */
int FUN_001bec3c()
{
  return 2;
}

/* FUN_001bec46 @ 0x1bec46 (7 bytes) */
int FUN_001bec46()
{
  return 0;
}

/* FUN_001bec4e @ 0x1bec4e (30 bytes) */
int FUN_001bec4e(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  *param_2 = *(float *)(param_3 + 4) + *(float *)(param_3 + 8);
  return 1;
}

/* FUN_001bec6c @ 0x1bec6c (272 bytes) */
int FUN_001bec6c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int *param_3;
  int param_4;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 local_1c;
  
  cVar4 = FUN_001901b2(param_2);
  if (((cVar4 == '\0') && (cVar4 = FUN_0018f7c8(param_2), cVar4 == '\0')) &&
     ((cVar4 = FUN_000e1402(param_4,0xc), cVar4 == '\0' ||
      (cVar4 = FUN_00190f64(param_2), cVar4 == '\0')))) {
    uVar1 = *(undefined4 *)(param_2 + 0xb0);
    iVar2 = *(int *)(param_4 + 0x38c);
    iVar3 = *(int *)(*(int *)(param_4 + 0x3f4) + 0xa8);
    local_1c = 2;
    iVar6 = 0;
    do {
      iVar5 = FUN_0010b0f4(uVar1,0);
      if (*(char *)(iVar6 + 0x10 + iVar5) != '\x01') {
        if (iVar2 <= iVar3) {
          return local_1c;
        }
        if ((*param_3 == 0x7ffffffe) &&
           ((cVar4 = FUN_0018a170(param_2,iVar6), cVar4 != '\0' ||
            (cVar4 = FUN_0018a2c6(param_2,iVar6), cVar4 != '\0')))) {
          local_1c = 1;
        }
      }
      iVar6 = iVar6 + 1;
      param_3 = param_3 + 1;
    } while (iVar6 != 4);
    return local_1c;
  }
  return 0;
}

/* FUN_001bed7c @ 0x1bed7c (24 bytes) */
int FUN_001bed7c(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  *param_2 = *(int *)(param_3 + 4) + *(int *)(param_3 + 8);
  return 1;
}

/* FUN_001bed94 @ 0x1bed94 (24 bytes) */
int FUN_001bed94(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  *param_2 = *(uint *)(param_3 + 4) | *(uint *)(param_3 + 8);
  return 1;
}

/* FUN_001bedac @ 0x1bedac (23 bytes) */
int FUN_001bedac(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  *param_2 = ~*(uint *)(param_3 + 4);
  return 1;
}

/* FUN_001bedc4 @ 0x1bedc4 (26 bytes) */
int FUN_001bedc4(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  *param_2 = *(int *)(param_3 + 4) >> ((byte)*(undefined4 *)(param_3 + 8) & 0x1f);
  return 1;
}

/* FUN_001bedde @ 0x1bedde (26 bytes) */
int FUN_001bedde(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  *param_2 = *(int *)(param_3 + 4) << ((byte)*(undefined4 *)(param_3 + 8) & 0x1f);
  return 1;
}

/* FUN_001bedf8 @ 0x1bedf8 (31 bytes) */
int FUN_001bedf8(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  *param_2 = (*(uint *)(param_3 + 4) & 0x7fffffff) >> ((byte)*(undefined4 *)(param_3 + 8) & 0x1f);
  return 1;
}

/* FUN_001bee18 @ 0x1bee18 (24 bytes) */
int FUN_001bee18(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  *param_2 = *(uint *)(param_3 + 4) ^ *(uint *)(param_3 + 8);
  return 1;
}

/* FUN_001bee30 @ 0x1bee30 (24 bytes) */
int FUN_001bee30(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  *param_2 = *(uint *)(param_3 + 4) & *(uint *)(param_3 + 8);
  return 1;
}

/* FUN_001bee48 @ 0x1bee48 (24 bytes) */
int FUN_001bee48(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  *param_2 = *(int *)(param_3 + 8) - *(int *)(param_3 + 4);
  return 1;
}

/* FUN_001bee60 @ 0x1bee60 (25 bytes) */
int FUN_001bee60(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  *param_2 = *(int *)(param_3 + 4) * *(int *)(param_3 + 8);
  return 1;
}

/* FUN_001bee7a @ 0x1bee7a (25 bytes) */
int FUN_001bee7a(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  *param_2 = *(int *)(param_3 + 4) * *(int *)(param_3 + 8);
  return 1;
}

/* FUN_001bee94 @ 0x1bee94 (29 bytes) */
int FUN_001bee94(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = *(int *)(param_3 + 4);
  if (*(int *)(param_3 + 4) < *(int *)(param_3 + 8)) {
    iVar1 = *(int *)(param_3 + 8);
  }
  *param_2 = iVar1;
  return 1;
}

/* FUN_001beeb2 @ 0x1beeb2 (29 bytes) */
int FUN_001beeb2(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_3 + 4);
  if (*(uint *)(param_3 + 4) < *(uint *)(param_3 + 8)) {
    uVar1 = *(uint *)(param_3 + 8);
  }
  *param_2 = uVar1;
  return 1;
}

/* FUN_001beed0 @ 0x1beed0 (47 bytes) */
int FUN_001beed0(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = -(uint)(*(float *)(param_3 + 4) < *(float *)(param_3 + 8));
  *param_2 = ~uVar1 & (uint)*(float *)(param_3 + 4) | (uint)*(float *)(param_3 + 8) & uVar1;
  return 1;
}

/* FUN_001bef00 @ 0x1bef00 (47 bytes) */
int FUN_001bef00(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = -(uint)(*(float *)(param_3 + 4) <= *(float *)(param_3 + 8));
  *param_2 = ~uVar1 & (uint)*(float *)(param_3 + 8) | (uint)*(float *)(param_3 + 4) & uVar1;
  return 1;
}

/* FUN_001bef30 @ 0x1bef30 (29 bytes) */
int FUN_001bef30(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = *(int *)(param_3 + 4);
  if (*(int *)(param_3 + 8) <= *(int *)(param_3 + 4)) {
    iVar1 = *(int *)(param_3 + 8);
  }
  *param_2 = iVar1;
  return 1;
}

/* FUN_001bef4e @ 0x1bef4e (29 bytes) */
int FUN_001bef4e(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_3 + 4);
  if (*(uint *)(param_3 + 8) <= *(uint *)(param_3 + 4)) {
    uVar1 = *(uint *)(param_3 + 8);
  }
  *param_2 = uVar1;
  return 1;
}

/* FUN_001bef6c @ 0x1bef6c (23 bytes) */
int FUN_001bef6c(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  *param_2 = (int)*(float *)(param_3 + 4);
  return 1;
}

/* FUN_001bef84 @ 0x1bef84 (23 bytes) */
int FUN_001bef84(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  *param_2 = (int)*(float *)(param_3 + 4);
  return 1;
}

/* FUN_001bef9c @ 0x1bef9c (21 bytes) */
int FUN_001bef9c(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  *param_2 = *(undefined4 *)(param_3 + 4);
  return 1;
}

/* FUN_001befb2 @ 0x1befb2 (123 bytes) */
int FUN_001befb2(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  float *param_2;
  int param_3;
  int param_4;
{
  float fVar1;
  longdouble lVar2;
  
  if (*(int *)(param_3 + 4) == 0) {
    *param_2 = 1.0;
    return 1;
  }
  fVar1 = *(float *)(param_3 + 4);
  if ((fVar1 == FLOAT_001c5ba4) && (!NAN(fVar1) && !NAN(FLOAT_001c5ba4))) {
    *param_2 = 0.0;
    return 1;
  }
  lVar2 = (longdouble)
          (**(code **)(**(int **)(param_4 + 0x54) + 0xe0))(*(int **)(param_4 + 0x54),fVar1);
  lVar2 = (longdouble)_cosf((float)lVar2);
  *param_2 = (float)lVar2;
  return 1;
}

/* FUN_001bf02e @ 0x1bf02e (146 bytes) */
int FUN_001bf02e(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  longdouble lVar1;
  longdouble lVar2;
  float fVar3;
  
  if ((FLOAT_001c5ba4 == *(float *)(param_3 + 4)) &&
     (!NAN(FLOAT_001c5ba4) && !NAN(*(float *)(param_3 + 4)))) {
    *param_2 = 0.0;
  }
  if (*(float *)(param_3 + 4) != 0.0) {
    fVar3 = *(float *)(param_3 + 4);
    if (fVar3 < FLOAT_001c5b9c) {
      fVar3 = (float)((uint)fVar3 ^ _DAT_001cc3f0);
    }
    lVar1 = (longdouble)_logf(fVar3);
    lVar2 = (longdouble)_log(0,0x40000000);
    *param_2 = (float)(DOUBLE_001cf330 / (double)lVar2) * (float)lVar1;
  }
  return 1;
}

/* FUN_001bf0c0 @ 0x1bf0c0 (92 bytes) */
int FUN_001bf0c0(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  float fVar1;
  
  fVar1 = *(float *)(param_3 + 4);
  if ((fVar1 != FLOAT_001c5ba4) || (NAN(fVar1) || NAN(FLOAT_001c5ba4))) {
    if (FLOAT_001c5b9c < fVar1) {
      *param_2 = (float)(DOUBLE_001cf330 / SQRT((double)fVar1));
      return 1;
    }
  }
  else {
    *param_2 = FLOAT_001c5ba4;
  }
  return 1;
}

/* FUN_001bf11c @ 0x1bf11c (45 bytes) */
int FUN_001bf11c(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  if (*(int *)(param_3 + 4) != 0) {
    *param_2 = FLOAT_001c5ba4 / *(float *)(param_3 + 4);
  }
  return 1;
}

/* FUN_001bf14a @ 0x1bf14a (125 bytes) */
int FUN_001bf14a(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  float *param_2;
  int param_3;
  int param_4;
{
  float fVar1;
  longdouble lVar2;
  
  if (*(int *)(param_3 + 4) == 0) {
    *param_2 = 0.0;
    return 1;
  }
  fVar1 = *(float *)(param_3 + 4);
  if ((fVar1 == FLOAT_001c5ba4) && (!NAN(fVar1) && !NAN(FLOAT_001c5ba4))) {
    *param_2 = FLOAT_001c5ba4;
    return 1;
  }
  lVar2 = (longdouble)
          (**(code **)(**(int **)(param_4 + 0x54) + 0xe0))(*(int **)(param_4 + 0x54),fVar1);
  lVar2 = (longdouble)_sinf((float)lVar2);
  *param_2 = (float)lVar2;
  return 1;
}

/* FUN_001bf1c8 @ 0x1bf1c8 (55 bytes) */
int FUN_001bf1c8(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  float fVar1;
  
  fVar1 = *(float *)(param_3 + 4);
  if ((fVar1 != FLOAT_001c5ba4) && (*(int *)(param_3 + 4) != 0)) {
    if (*(int *)(param_3 + 4) < 1) {
      return 1;
    }
    fVar1 = SQRT(fVar1);
  }
  *param_2 = fVar1;
  return 1;
}

/* FUN_001bf200 @ 0x1bf200 (94 bytes) */
int FUN_001bf200(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  longdouble lVar1;
  
  if (*(int *)(param_3 + 4) == 0) {
    *param_2 = 1.0;
    return 1;
  }
  lVar1 = (longdouble)_pow(0,0x40000000,(double)*(float *)(param_3 + 4));
  *param_2 = (float)lVar1;
  return 1;
}

/* FUN_001bf25e @ 0x1bf25e (25 bytes) */
int FUN_001bf25e(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  *param_2 = (float)*(int *)(param_3 + 4);
  return 1;
}

/* FUN_001bf278 @ 0x1bf278 (62 bytes) */
int FUN_001bf278(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_3 + 4);
  if (-1 < (int)uVar1) {
    *param_2 = (float)(int)uVar1;
    return 1;
  }
  *param_2 = (float)uVar1;
  return 1;
}

/* FUN_001bf2b6 @ 0x1bf2b6 (30 bytes) */
int FUN_001bf2b6(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  *param_2 = *(float *)(param_3 + 4) * *(float *)(param_3 + 8);
  return 1;
}

/* FUN_001bf2d4 @ 0x1bf2d4 (28 bytes) */
undefined8 FUN_001bf2d4(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  *param_2 = (int)((ulonglong)((longlong)*(int *)(param_3 + 8) * (longlong)*(int *)(param_3 + 4)) >>
                  0x20);
  return 1;
}

/* FUN_001bf2f0 @ 0x1bf2f0 (28 bytes) */
undefined8 FUN_001bf2f0(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  *param_2 = (int)((ulonglong)*(uint *)(param_3 + 8) * (ulonglong)*(uint *)(param_3 + 4) >> 0x20);
  return 1;
}

/* FUN_001bf30c @ 0x1bf30c (48 bytes) */
int FUN_001bf30c(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  float fVar1;
  
  fVar1 = *(float *)(param_3 + 4);
  FUN_00119392();
  *param_2 = fVar1 + *(float *)(param_3 + 0xc);
  return 1;
}

/* FUN_001bf33c @ 0x1bf33c (32 bytes) */
int FUN_001bf33c(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  longdouble lVar1;
  
  lVar1 = (longdouble)_floorf(*(undefined4 *)(param_3 + 4));
  *param_2 = (float)lVar1;
  return 1;
}

/* FUN_001bf35c @ 0x1bf35c (56 bytes) */
int FUN_001bf35c(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  float fVar1;
  longdouble lVar2;
  
  fVar1 = *(float *)(param_3 + 4);
  lVar2 = (longdouble)_floorf(fVar1);
  *param_2 = fVar1 - (float)lVar2;
  return 1;
}

/* FUN_001bf394 @ 0x1bf394 (91 bytes) */
int FUN_001bf394(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  float *param_3;
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *param_3;
  FUN_00119392();
  fVar2 = param_3[1];
  FUN_00119392();
  fVar3 = param_3[2];
  FUN_00119392();
  *param_2 = fVar3 + fVar2 + fVar1;
  return;
}

/* FUN_001bf3f0 @ 0x1bf3f0 (116 bytes) */
int FUN_001bf3f0(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  float *param_3;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *param_3;
  FUN_00119392();
  fVar2 = param_3[1];
  FUN_00119392();
  fVar3 = param_3[2];
  FUN_00119392();
  fVar4 = param_3[3];
  FUN_00119392();
  *param_2 = fVar4 + fVar3 + fVar2 + fVar1;
  return;
}

