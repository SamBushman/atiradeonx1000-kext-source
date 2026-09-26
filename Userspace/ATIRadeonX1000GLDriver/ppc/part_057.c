#include "decls.h"

/* FUN_001cfeac @ 0x1cfeac (52 bytes) */
int FUN_001cfeac(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b48 + 8;
  *param_1 = &PTR_FUN_001e9fc8;
  *param_1 = puVar1;
  return;
}

/* FUN_001cfee0 @ 0x1cfee0 (72 bytes) */
int FUN_001cfee0(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b48 + 8;
  *param_1 = &PTR_FUN_001e9fc8;
  *param_1 = puVar1;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  FUN_00193cc0(param_1[-1],param_1 + -1);
  return;
}

/* FUN_001cff28 @ 0x1cff28 (52 bytes) */
int FUN_001cff28(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b48 + 8;
  *param_1 = &PTR_FUN_001e9fc8;
  *param_1 = puVar1;
  return;
}

/* FUN_001cff5c @ 0x1cff5c (72 bytes) */
int FUN_001cff5c(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b48 + 8;
  *param_1 = &PTR_FUN_001e9fc8;
  *param_1 = puVar1;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  FUN_00193cc0(param_1[-1],param_1 + -1);
  return;
}

/* FUN_001cffa4 @ 0x1cffa4 (36 bytes) */
int FUN_001cffa4(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001ea5b0;
  return;
}

/* FUN_001cffc8 @ 0x1cffc8 (36 bytes) */
int FUN_001cffc8(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001ea5b0;
  operator_delete(param_1);
  return;
}

/* FUN_001d0000 @ 0x1d0000 (32 bytes) */
int FUN_001d0000(param_1)
  undefined4 *param_1;
{
  *param_1 = DAT_001afa04;
  return;
}

/* FUN_001d0070 @ 0x1d0070 (32 bytes) */
int FUN_001d0070(param_1)
  undefined4 *param_1;
{
  *param_1 = DAT_001afa08;
  return;
}

/* FUN_001d014c @ 0x1d014c (32 bytes) */
int FUN_001d014c(param_1)
  undefined4 *param_1;
{
  *param_1 = DAT_001afa04;
  return;
}

/* FUN_001d01b0 @ 0x1d01b0 (36 bytes) */
int FUN_001d01b0(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e8c88 + 8;
  return;
}

/* FUN_001d01d4 @ 0x1d01d4 (36 bytes) */
int FUN_001d01d4(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e8c88 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001d0208 @ 0x1d0208 (36 bytes) */
int FUN_001d0208(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e8f28 + 8;
  return;
}

/* FUN_001d022c @ 0x1d022c (36 bytes) */
int FUN_001d022c(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e8f28 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001d0278 @ 0x1d0278 (288 bytes) */
int FUN_001d0278(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int *param_3;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar2 = FUN_0017d610(param_2);
  if (((iVar2 == 0) && (iVar2 = FUN_0017cdbc(param_2), iVar2 == 0)) &&
     ((iVar2 = FUN_000e07dc(param_4,0xc), iVar2 == 0 || (iVar2 = FUN_0017e338(param_2), iVar2 == 0))
     )) {
    iVar4 = *(int *)(param_4 + 0x658);
    iVar2 = *(int *)(*(int *)(param_4 + 0x6c4) + 0xa8);
    uVar5 = *(undefined4 *)(param_2 + 0xb0);
    uVar6 = 2;
    iVar7 = 0;
    do {
      iVar3 = FUN_001054ec(uVar5,0);
      if (*(char *)(iVar7 + iVar3 + 0x10) != '\x01') {
        if (iVar4 <= iVar2) {
          return uVar6;
        }
        if ((*param_3 == 0x7ffffffe) &&
           ((iVar3 = FUN_00179b28(param_2,iVar7), iVar3 != 0 ||
            (iVar3 = FUN_00179cc0(param_2,iVar7), iVar3 != 0)))) {
          uVar6 = 1;
        }
      }
      bVar1 = iVar7 != 3;
      param_3 = param_3 + 1;
      iVar7 = iVar7 + 1;
    } while (bVar1);
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}

/* FUN_001d05b0 @ 0x1d05b0 (144 bytes) */
int FUN_001d05b0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  float *param_2;
  int param_3;
  int param_4;
{
  double dVar1;
  
  if (*(int *)(param_3 + 4) == 0) {
    *param_2 = 1.0;
  }
  else if (*(float *)(param_3 + 4) == FLOAT_001aa0e8) {
    *param_2 = 0.0;
  }
  else {
    dVar1 = (double)_cos(((double (*)(int, double))*(code **)(**(int **)(param_4 + 0x30c) + 0xe0))(*(int *)(param_4 + 0x30c), (double)*(float *)(param_3 + 4)));
    *param_2 = (float)dVar1;
  }
  return 1;
}

/* FUN_001d0640 @ 0x1d0640 (172 bytes) */
int FUN_001d0640(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  double dVar1;
  double dVar2;
  
  if (*(float *)(param_3 + 4) == FLOAT_001aa0e8) {
    *param_2 = 0.0;
  }
  if (*(int *)(param_3 + 4) != 0) {
    dVar1 = (double)*(float *)(param_3 + 4);
    if (dVar1 < (double)FLOAT_001aa0d4) {
      dVar1 = -dVar1;
    }
    dVar1 = (double)_logf(dVar1);
    dVar2 = (double)_log(DOUBLE_001aa2a0);
    *param_2 = (float)(dVar1 * (double)(float)(DOUBLE_001aa200 / dVar2));
  }
  return 1;
}

/* FUN_001d06ec @ 0x1d06ec (112 bytes) */
int FUN_001d06ec(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  float fVar1;
  double dVar2;
  
  fVar1 = FLOAT_001aa0e8;
  if (*(float *)(param_3 + 4) != FLOAT_001aa0e8) {
    if (*(float *)(param_3 + 4) <= FLOAT_001aa0d4) {
      return 1;
    }
    dVar2 = (double)_sqrt((double)*(float *)(param_3 + 4));
    fVar1 = (float)(DOUBLE_001aa200 / dVar2);
  }
  *param_2 = fVar1;
  return 1;
}

/* FUN_001d075c @ 0x1d075c (56 bytes) */
int FUN_001d075c(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  if (*(int *)(param_3 + 4) != 0) {
    *param_2 = FLOAT_001aa0e8 / *(float *)(param_3 + 4);
  }
  return 1;
}

/* FUN_001d0794 @ 0x1d0794 (140 bytes) */
int FUN_001d0794(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  float *param_2;
  int param_3;
  int param_4;
{
  double dVar1;
  
  if (*(int *)(param_3 + 4) == 0) {
    *param_2 = 0.0;
  }
  else if (*(float *)(param_3 + 4) == FLOAT_001aa0e8) {
    *param_2 = FLOAT_001aa0e8;
  }
  else {
    dVar1 = (double)_sin(((double (*)(int, double))*(code **)(**(int **)(param_4 + 0x30c) + 0xe0))(*(int *)(param_4 + 0x30c), (double)*(float *)(param_3 + 4)));
    *param_2 = (float)dVar1;
  }
  return 1;
}

/* FUN_001d0820 @ 0x1d0820 (100 bytes) */
int FUN_001d0820(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  float fVar1;
  double dVar2;
  
  fVar1 = *(float *)(param_3 + 4);
  if ((fVar1 != FLOAT_001aa0e8) && (*(int *)(param_3 + 4) != 0)) {
    if (*(int *)(param_3 + 4) < 1) {
      return 1;
    }
    dVar2 = (double)_sqrt((double)*(float *)(param_3 + 4));
    fVar1 = (float)dVar2;
  }
  *param_2 = fVar1;
  return 1;
}

/* FUN_001d0884 @ 0x1d0884 (100 bytes) */
int FUN_001d0884(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  double dVar1;
  
  if (*(int *)(param_3 + 4) == 0) {
    *param_2 = 1.0;
  }
  else {
    dVar1 = (double)_pow(DOUBLE_001aa2a0,(double)*(float *)(param_3 + 4));
    *param_2 = (float)dVar1;
  }
  return 1;
}

/* FUN_001d08e8 @ 0x1d08e8 (68 bytes) */
int FUN_001d08e8(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  *param_2 = (float)((double)CONCAT44(0x43300000,*(uint *)(param_3 + 4) ^ 0x80000000) -
                    DOUBLE_001aa1e0);
  return 1;
}

/* FUN_001d092c @ 0x1d092c (64 bytes) */
int FUN_001d092c(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  *param_2 = (float)((double)CONCAT44(0x43300000,*(undefined4 *)(param_3 + 4)) - DOUBLE_001aa250);
  return 1;
}

/* FUN_001d09b4 @ 0x1d09b4 (72 bytes) */
int FUN_001d09b4(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  double dVar1;
  
  dVar1 = (double)((double (*)())FUN_00113554)((double)*(float *)(param_3 + 4),(double)*(float *)(param_3 + 8));
  *param_2 = (float)(dVar1 + (double)*(float *)(param_3 + 0xc));
  return 1;
}

/* FUN_001d09fc @ 0x1d09fc (60 bytes) */
int FUN_001d09fc(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  double dVar1;
  
  dVar1 = (double)_floor((double)*(float *)(param_3 + 4));
  *param_2 = (float)dVar1;
  return 1;
}

/* FUN_001d0a38 @ 0x1d0a38 (76 bytes) */
int FUN_001d0a38(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  float fVar1;
  double dVar2;
  
  fVar1 = *(float *)(param_3 + 4);
  dVar2 = (double)_floor((double)fVar1);
  *param_2 = (float)((double)fVar1 - dVar2);
  return 1;
}

/* FUN_001d0a84 @ 0x1d0a84 (108 bytes) */
int FUN_001d0a84(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  float *param_2;
  float *param_3;
  float *param_4;
{
  double dVar1;
  double dVar2;
  double dVar3;
  
  dVar1 = (double)((double (*)())FUN_00113554)((double)*param_3,(double)*param_4);
  dVar2 = (double)((double (*)())FUN_00113554)((double)param_3[1],(double)param_4[1]);
  dVar3 = (double)((double (*)())FUN_00113554)((double)param_3[2],(double)param_4[2]);
  *param_2 = (float)((double)(float)(dVar1 + dVar2) + dVar3);
  return;
}

/* FUN_001d0af0 @ 0x1d0af0 (124 bytes) */
int FUN_001d0af0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  float *param_2;
  float *param_3;
  float *param_4;
{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar1 = (double)((double (*)())FUN_00113554)((double)*param_3,(double)*param_4);
  dVar2 = (double)((double (*)())FUN_00113554)((double)param_3[1],(double)param_4[1]);
  dVar3 = (double)((double (*)())FUN_00113554)((double)param_3[2],(double)param_4[2]);
  dVar4 = (double)((double (*)())FUN_00113554)((double)param_3[3],(double)param_4[3]);
  *param_2 = (float)((double)(float)((double)(float)(dVar1 + dVar2) + dVar3) + dVar4);
  return;
}

/* FUN_001d0b94 @ 0x1d0b94 (104 bytes) */
int FUN_001d0b94(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  float *param_2;
  float *param_3;
  float *param_4;
  int param_5;
{
  double dVar1;
  double dVar2;
  
  dVar1 = (double)((double (*)())FUN_00113554)((double)*param_3,(double)*param_4);
  dVar2 = (double)((double (*)())FUN_00113554)((double)param_3[1],(double)param_4[1]);
  *param_2 = (float)(dVar1 + dVar2) + *(float *)(param_5 + 8);
  return;
}

/* FUN_001d0bfc @ 0x1d0bfc (60 bytes) */
int FUN_001d0bfc(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (*(float *)(param_3 + 4) == FLOAT_001aa0d4) {
    uVar1 = *(undefined4 *)(param_3 + 8);
  }
  else {
    uVar1 = *(undefined4 *)(param_3 + 0xc);
  }
  *param_2 = uVar1;
  return 1;
}

/* FUN_001d0c38 @ 0x1d0c38 (64 bytes) */
int FUN_001d0c38(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (*(float *)(param_3 + 4) < FLOAT_001aa0d4) {
    uVar1 = *(undefined4 *)(param_3 + 0xc);
  }
  else {
    uVar1 = *(undefined4 *)(param_3 + 8);
  }
  *param_2 = uVar1;
  return 1;
}

/* FUN_001d0c78 @ 0x1d0c78 (60 bytes) */
int FUN_001d0c78(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (*(float *)(param_3 + 4) <= FLOAT_001aa0d4) {
    uVar1 = *(undefined4 *)(param_3 + 0xc);
  }
  else {
    uVar1 = *(undefined4 *)(param_3 + 8);
  }
  *param_2 = uVar1;
  return 1;
}

/* FUN_001d0cd8 @ 0x1d0cd8 (68 bytes) */
int FUN_001d0cd8(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *(float *)(param_3 + 4) - *(float *)(param_3 + 8);
  fVar3 = FLOAT_001aa0e8;
  if (fVar1 < 0.0) {
    fVar3 = FLOAT_001aa0d4;
  }
  fVar2 = FLOAT_001aa0d4;
  if (-fVar1 < 0.0) {
    fVar2 = fVar3;
  }
  *param_2 = fVar2;
  return 1;
}

/* FUN_001d0e0c @ 0x1d0e0c (212 bytes) */
int FUN_001d0e0c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int *param_3;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar2 = FUN_0017cdbc(param_2);
  uVar5 = 0;
  if (iVar2 == 0) {
    iVar4 = *(int *)(param_4 + 0x658);
    iVar2 = *(int *)(*(int *)(param_4 + 0x6c4) + 0xa8);
    uVar6 = *(undefined4 *)(param_2 + 0xb0);
    uVar5 = 2;
    iVar7 = 0;
    do {
      iVar3 = FUN_001054ec(uVar6,0);
      if (*(char *)(iVar7 + iVar3 + 0x10) != '\x01') {
        if (iVar4 <= iVar2) {
          return uVar5;
        }
        if ((*param_3 == 0x7ffffffe) && (iVar3 = FUN_00179cc0(param_2,iVar7), iVar3 != 0)) {
          uVar5 = 1;
        }
      }
      bVar1 = iVar7 != 3;
      param_3 = param_3 + 1;
      iVar7 = iVar7 + 1;
    } while (bVar1);
  }
  return uVar5;
}

/* FUN_001d0ee0 @ 0x1d0ee0 (72 bytes) */
int FUN_001d0ee0(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  if ((*(float *)(param_3 + 4) == FLOAT_001aa0d4) || (*(float *)(param_3 + 8) == FLOAT_001aa0d4)) {
    *param_2 = FLOAT_001aa0d4;
  }
  else {
    *param_2 = *(float *)(param_3 + 4) * *(float *)(param_3 + 8);
  }
  return 1;
}

/* FUN_001d0f28 @ 0x1d0f28 (68 bytes) */
int FUN_001d0f28(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d9c;
  *param_1 = PTR_DAT_001e8e28 + 8;
  puVar2 = PTR_DAT_001e8f28;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001d0f6c @ 0x1d0f6c (68 bytes) */
int FUN_001d0f6c(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d9c;
  *param_1 = PTR_DAT_001e8e28 + 8;
  puVar2 = PTR_DAT_001e8f28;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  return;
}

/* FUN_001d0fb0 @ 0x1d0fb0 (68 bytes) */
int FUN_001d0fb0(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d9c;
  *param_1 = PTR_DAT_001e904c + 8;
  puVar2 = PTR_DAT_001e8f28;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001d0ff4 @ 0x1d0ff4 (68 bytes) */
int FUN_001d0ff4(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d9c;
  *param_1 = PTR_DAT_001e904c + 8;
  puVar2 = PTR_DAT_001e8f28;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  return;
}

/* FUN_001d1038 @ 0x1d1038 (68 bytes) */
int FUN_001d1038(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d9c;
  *param_1 = PTR_DAT_001e8f0c + 8;
  puVar2 = PTR_DAT_001e8f28;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001d107c @ 0x1d107c (68 bytes) */
int FUN_001d107c(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d9c;
  *param_1 = PTR_DAT_001e8f0c + 8;
  puVar2 = PTR_DAT_001e8f28;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  return;
}

/* FUN_001d10c0 @ 0x1d10c0 (68 bytes) */
int FUN_001d10c0(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d88;
  *param_1 = PTR_DAT_001e8fe4 + 8;
  puVar2 = PTR_DAT_001e8f28;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001d1104 @ 0x1d1104 (68 bytes) */
int FUN_001d1104(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d88;
  *param_1 = PTR_DAT_001e8fe4 + 8;
  puVar2 = PTR_DAT_001e8f28;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  return;
}

/* FUN_001d1148 @ 0x1d1148 (68 bytes) */
int FUN_001d1148(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d88;
  *param_1 = PTR_DAT_001e8f8c + 8;
  puVar2 = PTR_DAT_001e8f28;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001d118c @ 0x1d118c (68 bytes) */
int FUN_001d118c(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d88;
  *param_1 = PTR_DAT_001e8f8c + 8;
  puVar2 = PTR_DAT_001e8f28;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  return;
}

/* FUN_001d11d0 @ 0x1d11d0 (68 bytes) */
int FUN_001d11d0(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d88;
  *param_1 = PTR_DAT_001e8fec + 8;
  puVar2 = PTR_DAT_001e8f28;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001d1214 @ 0x1d1214 (68 bytes) */
int FUN_001d1214(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d88;
  *param_1 = PTR_DAT_001e8fec + 8;
  puVar2 = PTR_DAT_001e8f28;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  return;
}

/* FUN_001d1258 @ 0x1d1258 (68 bytes) */
int FUN_001d1258(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8dd8;
  *param_1 = PTR_DAT_001e8fb8 + 8;
  puVar2 = PTR_DAT_001e8f28;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001d129c @ 0x1d129c (68 bytes) */
int FUN_001d129c(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8dd8;
  *param_1 = PTR_DAT_001e8fb8 + 8;
  puVar2 = PTR_DAT_001e8f28;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  return;
}

/* FUN_001d12e0 @ 0x1d12e0 (68 bytes) */
int FUN_001d12e0(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8dd8;
  *param_1 = PTR_DAT_001e8e90 + 8;
  puVar2 = PTR_DAT_001e8f28;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001d1324 @ 0x1d1324 (68 bytes) */
int FUN_001d1324(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8dd8;
  *param_1 = PTR_DAT_001e8e90 + 8;
  puVar2 = PTR_DAT_001e8f28;
  *param_1 = puVar1 + 8;
  *param_1 = puVar2 + 8;
  return;
}

/* FUN_001d1368 @ 0x1d1368 (68 bytes) */
int FUN_001d1368(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e9038;
  *param_1 = PTR_DAT_001e8d2c + 8;
  puVar1 = PTR_DAT_001e8f28;
  *param_1 = puVar2 + 8;
  *param_1 = puVar1 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001d13ac @ 0x1d13ac (68 bytes) */
int FUN_001d13ac(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e9038;
  *param_1 = PTR_DAT_001e8d2c + 8;
  puVar1 = PTR_DAT_001e8f28;
  *param_1 = puVar2 + 8;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001d13f0 @ 0x1d13f0 (68 bytes) */
int FUN_001d13f0(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e9038;
  *param_1 = PTR_DAT_001e8cd8 + 8;
  puVar1 = PTR_DAT_001e8f28;
  *param_1 = puVar2 + 8;
  *param_1 = puVar1 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001d1434 @ 0x1d1434 (68 bytes) */
int FUN_001d1434(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e9038;
  *param_1 = PTR_DAT_001e8cd8 + 8;
  puVar1 = PTR_DAT_001e8f28;
  *param_1 = puVar2 + 8;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001d1478 @ 0x1d1478 (68 bytes) */
int FUN_001d1478(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e8f94;
  *param_1 = PTR_DAT_001e9070 + 8;
  puVar1 = PTR_DAT_001e8f28;
  *param_1 = puVar2 + 8;
  *param_1 = puVar1 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001d14bc @ 0x1d14bc (68 bytes) */
int FUN_001d14bc(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e8f94;
  *param_1 = PTR_DAT_001e9070 + 8;
  puVar1 = PTR_DAT_001e8f28;
  *param_1 = puVar2 + 8;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001d1500 @ 0x1d1500 (68 bytes) */
int FUN_001d1500(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e907c;
  *param_1 = PTR_DAT_001e8cb8 + 8;
  puVar1 = PTR_DAT_001e8f28;
  *param_1 = puVar2 + 8;
  *param_1 = puVar1 + 8;
  operator_delete(param_1);
  return;
}

/* FUN_001d1544 @ 0x1d1544 (68 bytes) */
int FUN_001d1544(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e907c;
  *param_1 = PTR_DAT_001e8cb8 + 8;
  puVar1 = PTR_DAT_001e8f28;
  *param_1 = puVar2 + 8;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_001d1588 @ 0x1d1588 (52 bytes) */
int FUN_001d1588(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8f28 + 8;
  *param_1 = PTR_DAT_001e8db0 + 8;
  *param_1 = puVar1;
  return;
}

