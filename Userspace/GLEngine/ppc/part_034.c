#include "decls.h"

/* _glDrawArrays_CompExec @ 0xa8624 (72 bytes) */
int _glDrawArrays_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  _glDrawArrays_Comp(param_1,param_2,param_3,param_4);
  ((void (*)())_glDrawArrays_Exec)(param_1,param_2,param_3,param_4,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,
                     in_f8);
  return;
}

/* _glDrawArrays_NoopExec @ 0xa866c (684 bytes) */
void _glDrawArrays_NoopExec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar7;
  uint uVar8;
  int *piVar9;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(param_1 + 0x759c) == '\0') {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_000a88d8;
  }
  iVar7 = *(int *)(param_1 + 0x50ac);
  uVar3 = param_3;
  uVar6 = param_4;
  if (iVar7 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') {
LAB_000a88bc:
    if (*(char *)(param_1 + 0x759d) != '\0') {
      ((void (*)())_glDrawArrays_Exec)(param_1,param_2,param_3,param_4,fparam_1,fparam_2,fparam_3,fparam_4,
                         fparam_5,fparam_6,fparam_7,fparam_8);
      return;
    }
  }
  else {
    iVar5 = *(int *)(param_1 + 0x744c);
    piVar9 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
      ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar3,uVar6,in_r7,in_r8,iVar7,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000a87a8:
      uVar8 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar7 = 0;
      piVar4 = (int *)(param_1 + 0x324);
      do {
        iVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        if (iVar5 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < 9);
      uVar8 = *(uint *)(param_1 + 0x31c);
      if ((uVar8 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_000a87a8;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar8 = uVar8 & 0x17000000;
    }
    else {
      uVar8 = uVar8 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar9 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar8 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar9 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar8 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (bVar1) goto LAB_000a88bc;
    if (*(char *)(param_1 + 0x85a8) != *(char *)(param_1 + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
LAB_000a88a0:
      iVar7 = 0x13;
      do {
        *piVar9 = 0;
        piVar9 = piVar9 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      goto LAB_000a88bc;
    }
    uVar8 = (**(code **)(param_1 + 0x4788))
                      (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar9);
    if ((((uVar8 & 3) == (uint)*(byte *)(param_1 + 0x7580)) &&
        ((uVar8 & 4) == (uint)*(byte *)(param_1 + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (uVar8 & 8) == (uint)(*(char *)(param_1 + 0x759d) == '\0')))
    goto LAB_000a88a0;
    if ((uVar8 & 4) == 0) {
      uVar8 = uVar8 & 0xfffffffe;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar8);
    if (*(char *)(param_1 + 0x759d) != '\0') goto LAB_000a88a0;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x506;
LAB_000a88d8:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glDrawElements_Comp @ 0xa8918 (132 bytes) */
int _glDrawElements_Comp(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
  int param_5;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_4 != 0x1403) {
    if (param_4 < 0x1404) {
      bVar1 = param_4 == 0x1401;
    }
    else {
      bVar1 = param_4 == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return param_1;
      }
      *(undefined4 *)(param_1 + 0x7574) = 0x500;
      return param_1;
    }
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
  if (iVar2 != 0) {
    param_5 = param_5 + *(int *)(iVar2 + 0x30);
  }
  *(int *)(param_1 + 0x48d8) = param_5;
  *(int *)(param_1 + 0x4978) = param_5;
  if (param_4 != *(uint *)(param_1 + 0x48dc)) {
    *(uint *)(param_1 + 0x48dc) = param_4;
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
  }
  uVar3 = _gleDrawArraysOrElements_Comp(param_1,param_2,0,param_3);
  return uVar3;
}

/* _glDrawElements_IMM_Exec @ 0xa899c (136 bytes) */
void _glDrawElements_IMM_Exec(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  int iVar2;
  
  if (param_4 != 0x1403) {
    if (param_4 < 0x1404) {
      bVar1 = param_4 == 0x1401;
    }
    else {
      bVar1 = param_4 == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      *(undefined4 *)(param_1 + 0x7574) = 0x500;
      return;
    }
  }
  if (param_4 != *(uint *)(param_1 + 0x48dc)) {
    *(uint *)(param_1 + 0x48dc) = param_4;
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
  if (iVar2 != 0) {
    param_5 = param_5 + *(int *)(iVar2 + 0x30);
  }
  *(int *)(param_1 + 0x48d8) = param_5;
  *(int *)(param_1 + 0x4978) = param_5;
  ((int (*)())_gleDrawArraysOrElements_IMM_Exec)(param_1,param_2,0,param_3,1,*(int *)(param_1 + 0x4a60) + 0x10,fparam_1,fparam_2,
             fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return;
}

/* _glDrawElements_VBO_Exec @ 0xa8a24 (136 bytes) */
void _glDrawElements_VBO_Exec(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  int iVar2;
  
  if (param_4 != 0x1403) {
    if (param_4 < 0x1404) {
      bVar1 = param_4 == 0x1401;
    }
    else {
      bVar1 = param_4 == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      *(undefined4 *)(param_1 + 0x7574) = 0x500;
      return;
    }
  }
  if (param_4 != *(uint *)(param_1 + 0x48dc)) {
    *(uint *)(param_1 + 0x48dc) = param_4;
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
  if (iVar2 != 0) {
    param_5 = param_5 + *(int *)(iVar2 + 0x30);
  }
  *(int *)(param_1 + 0x48d8) = param_5;
  *(int *)(param_1 + 0x4978) = param_5;
  ((int (*)())_gleDrawArraysOrElements_VBO_Exec)(param_1,param_2,0,param_3,1,*(int *)(param_1 + 0x4a60) + 0x10,fparam_1,fparam_2,
             fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return;
}

/* _glDrawElements_VAR_Exec @ 0xa8aac (136 bytes) */
void _glDrawElements_VAR_Exec(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  int iVar2;
  
  if (param_4 != 0x1403) {
    if (param_4 < 0x1404) {
      bVar1 = param_4 == 0x1401;
    }
    else {
      bVar1 = param_4 == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      *(undefined4 *)(param_1 + 0x7574) = 0x500;
      return;
    }
  }
  if (param_4 != *(uint *)(param_1 + 0x48dc)) {
    *(uint *)(param_1 + 0x48dc) = param_4;
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
  if (iVar2 != 0) {
    param_5 = param_5 + *(int *)(iVar2 + 0x30);
  }
  *(int *)(param_1 + 0x48d8) = param_5;
  *(int *)(param_1 + 0x4978) = param_5;
  ((int (*)())_gleDrawArraysOrElements_VAR_Exec)(param_1,param_2,0,param_3,1,*(int *)(param_1 + 0x4a60) + 0x10,param_7,fparam_1,fparam_2
             ,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return;
}

/* _glDrawElements_CVA_Exec @ 0xa8b34 (136 bytes) */
void _glDrawElements_CVA_Exec(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  int iVar2;
  
  if (param_4 != 0x1403) {
    if (param_4 < 0x1404) {
      bVar1 = param_4 == 0x1401;
    }
    else {
      bVar1 = param_4 == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      *(undefined4 *)(param_1 + 0x7574) = 0x500;
      return;
    }
  }
  if (param_4 != *(uint *)(param_1 + 0x48dc)) {
    *(uint *)(param_1 + 0x48dc) = param_4;
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
  if (iVar2 != 0) {
    param_5 = param_5 + *(int *)(iVar2 + 0x30);
  }
  *(int *)(param_1 + 0x48d8) = param_5;
  *(int *)(param_1 + 0x4978) = param_5;
  ((int (*)())_gleDrawArraysOrElements_CVA_Exec)(param_1,param_2,0,param_3,1,*(int *)(param_1 + 0x4a60) + 0x10,fparam_1,fparam_2,
             fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return;
}

/* _glDrawElements_STD_Exec @ 0xa8bbc (136 bytes) */
double _glDrawElements_STD_Exec(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  int iVar2;
  
  if (param_4 != 0x1403) {
    if (param_4 < 0x1404) {
      bVar1 = param_4 == 0x1401;
    }
    else {
      bVar1 = param_4 == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      *(undefined4 *)(param_1 + 0x7574) = 0x500;
      return;
    }
  }
  if (param_4 != *(uint *)(param_1 + 0x48dc)) {
    *(uint *)(param_1 + 0x48dc) = param_4;
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
  if (iVar2 != 0) {
    param_5 = param_5 + *(int *)(iVar2 + 0x30);
  }
  *(int *)(param_1 + 0x48d8) = param_5;
  *(int *)(param_1 + 0x4978) = param_5;
  ((int (*)())_gleDrawArraysOrElements_Exec)(param_1,param_2,0,param_3,1,*(int *)(param_1 + 0x4a60) + 0x10,fparam_1,fparam_2,
             fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return;
}

/* _glDrawElements_Exec @ 0xa8c44 (136 bytes) */
void _glDrawElements_Exec(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  int iVar2;
  
  if (param_4 != 0x1403) {
    if (param_4 < 0x1404) {
      bVar1 = param_4 == 0x1401;
    }
    else {
      bVar1 = param_4 == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      *(undefined4 *)(param_1 + 0x7574) = 0x500;
      return;
    }
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
  if (iVar2 != 0) {
    param_5 = param_5 + *(int *)(iVar2 + 0x30);
  }
  *(int *)(param_1 + 0x48d8) = param_5;
  *(int *)(param_1 + 0x4978) = param_5;
  if (param_4 != *(uint *)(param_1 + 0x48dc)) {
    *(uint *)(param_1 + 0x48dc) = param_4;
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
  }
  ((undefined4 (*)())_gleEvalDrawArraysOrElements_Entires_Exec)(param_1,param_2,0,param_3,1,*(int *)(param_1 + 0x4a60) + 0x10,fparam_1,fparam_2,
             fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return;
}

/* _glDrawElements_CompExec @ 0xa8ccc (80 bytes) */
int _glDrawElements_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glDrawElements_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((void (*)())_glDrawElements_Exec)(param_1,param_2,param_3,param_4,param_5,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,
             in_f8);
  return;
}

/* _glDrawElements_NoopExec @ 0xa8d1c (692 bytes) */
void _glDrawElements_NoopExec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 in_r8;
  int iVar8;
  uint uVar9;
  int *piVar10;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(param_1 + 0x759c) == '\0') {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_000a8f8c;
  }
  iVar8 = *(int *)(param_1 + 0x50ac);
  uVar3 = param_3;
  uVar6 = param_4;
  uVar7 = param_5;
  if (iVar8 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') {
LAB_000a8f70:
    if (*(char *)(param_1 + 0x759d) != '\0') {
      ((void (*)())_glDrawElements_Exec)(param_1,param_2,param_3,param_4,param_5,fparam_1,fparam_2,fparam_3,fparam_4,
                 fparam_5,fparam_6,fparam_7,fparam_8);
      return;
    }
  }
  else {
    iVar5 = *(int *)(param_1 + 0x744c);
    piVar10 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
      ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar3,uVar6,uVar7,in_r8,iVar8,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000a8e5c:
      uVar9 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar8 = 0;
      piVar4 = (int *)(param_1 + 0x324);
      do {
        iVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        if (iVar5 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < 9);
      uVar9 = *(uint *)(param_1 + 0x31c);
      if ((uVar9 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_000a8e5c;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar9 = uVar9 & 0x17000000;
    }
    else {
      uVar9 = uVar9 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar10 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar9 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar10 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar9 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (bVar1) goto LAB_000a8f70;
    if (*(char *)(param_1 + 0x85a8) != *(char *)(param_1 + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
LAB_000a8f54:
      iVar8 = 0x13;
      do {
        *piVar10 = 0;
        piVar10 = piVar10 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      goto LAB_000a8f70;
    }
    uVar9 = (**(code **)(param_1 + 0x4788))
                      (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar10);
    if ((((uVar9 & 3) == (uint)*(byte *)(param_1 + 0x7580)) &&
        ((uVar9 & 4) == (uint)*(byte *)(param_1 + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (uVar9 & 8) == (uint)(*(char *)(param_1 + 0x759d) == '\0')))
    goto LAB_000a8f54;
    if ((uVar9 & 4) == 0) {
      uVar9 = uVar9 & 0xfffffffe;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar9);
    if (*(char *)(param_1 + 0x759d) != '\0') goto LAB_000a8f54;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x506;
LAB_000a8f8c:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glDrawRangeElements_Comp @ 0xa8fd0 (48 bytes) */
int _glDrawRangeElements_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  uint param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 uVar1;
  
  if (param_3 <= param_4) {
    uVar1 = ((int (*)())_glDrawElements_Comp)(param_1,param_2,param_5,param_6,param_7);
    return uVar1;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return param_1;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return param_1;
}

/* _glDrawRangeElements_IMM_Exec @ 0xa9000 (168 bytes) */
void _glDrawRangeElements_IMM_Exec(int param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5,uint param_6,int param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_4 < param_3) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
LAB_000a9058:
    *(undefined4 *)(param_1 + 0x7574) = uVar2;
    return;
  }
  if (param_6 != 0x1403) {
    if (param_6 < 0x1404) {
      bVar1 = param_6 == 0x1401;
    }
    else {
      bVar1 = param_6 == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar2 = 0x500;
      goto LAB_000a9058;
    }
  }
  if (param_6 != *(uint *)(param_1 + 0x48dc)) {
    *(uint *)(param_1 + 0x48dc) = param_6;
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
  if (iVar3 != 0) {
    param_7 = param_7 + *(int *)(iVar3 + 0x30);
  }
  *(int *)(param_1 + 0x4978) = param_7;
  *(int *)(param_1 + 0x48d8) = param_7;
  ((int (*)())_gleDrawArraysOrElements_IMM_Exec)(param_1,param_2,0,param_5,1,*(int *)(param_1 + 0x4a60) + 0x10,fparam_1,fparam_2,
             fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return;
}

/* _glDrawRangeElements_VBO_Exec @ 0xa90a8 (168 bytes) */
void _glDrawRangeElements_VBO_Exec(int param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5,uint param_6,int param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_4 < param_3) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
LAB_000a9100:
    *(undefined4 *)(param_1 + 0x7574) = uVar2;
    return;
  }
  if (param_6 != 0x1403) {
    if (param_6 < 0x1404) {
      bVar1 = param_6 == 0x1401;
    }
    else {
      bVar1 = param_6 == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar2 = 0x500;
      goto LAB_000a9100;
    }
  }
  if (param_6 != *(uint *)(param_1 + 0x48dc)) {
    *(uint *)(param_1 + 0x48dc) = param_6;
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
  if (iVar3 != 0) {
    param_7 = param_7 + *(int *)(iVar3 + 0x30);
  }
  *(int *)(param_1 + 0x4978) = param_7;
  *(int *)(param_1 + 0x48d8) = param_7;
  ((int (*)())_gleDrawArraysOrElements_VBO_Exec)(param_1,param_2,0,param_5,1,*(int *)(param_1 + 0x4a60) + 0x10,fparam_1,fparam_2,
             fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return;
}

/* _glDrawRangeElements_VAR_Exec @ 0xa9150 (168 bytes) */
void _glDrawRangeElements_VAR_Exec(int param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5,uint param_6,int param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_4 < param_3) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
LAB_000a91a8:
    *(undefined4 *)(param_1 + 0x7574) = uVar2;
    return;
  }
  if (param_6 != 0x1403) {
    if (param_6 < 0x1404) {
      bVar1 = param_6 == 0x1401;
    }
    else {
      bVar1 = param_6 == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar2 = 0x500;
      goto LAB_000a91a8;
    }
  }
  if (param_6 != *(uint *)(param_1 + 0x48dc)) {
    *(uint *)(param_1 + 0x48dc) = param_6;
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
  if (iVar3 != 0) {
    param_7 = param_7 + *(int *)(iVar3 + 0x30);
  }
  *(int *)(param_1 + 0x4978) = param_7;
  *(int *)(param_1 + 0x48d8) = param_7;
  ((int (*)())_gleDrawArraysOrElements_VAR_Exec)(param_1,param_2,0,param_5,1,*(int *)(param_1 + 0x4a60) + 0x10,param_7,fparam_1,fparam_2
             ,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return;
}

/* _glDrawRangeElements_CVA_Exec @ 0xa91f8 (168 bytes) */
void _glDrawRangeElements_CVA_Exec(int param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5,uint param_6,int param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_4 < param_3) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
LAB_000a9250:
    *(undefined4 *)(param_1 + 0x7574) = uVar2;
    return;
  }
  if (param_6 != 0x1403) {
    if (param_6 < 0x1404) {
      bVar1 = param_6 == 0x1401;
    }
    else {
      bVar1 = param_6 == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar2 = 0x500;
      goto LAB_000a9250;
    }
  }
  if (param_6 != *(uint *)(param_1 + 0x48dc)) {
    *(uint *)(param_1 + 0x48dc) = param_6;
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
  if (iVar3 != 0) {
    param_7 = param_7 + *(int *)(iVar3 + 0x30);
  }
  *(int *)(param_1 + 0x4978) = param_7;
  *(int *)(param_1 + 0x48d8) = param_7;
  ((int (*)())_gleDrawArraysOrElements_CVA_Exec)(param_1,param_2,0,param_5,1,*(int *)(param_1 + 0x4a60) + 0x10,fparam_1,fparam_2,
             fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return;
}

/* _glDrawRangeElements_Exec @ 0xa92a0 (168 bytes) */
void _glDrawRangeElements_Exec(int param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5,uint param_6,int param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_4 < param_3) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
LAB_000a92f8:
    *(undefined4 *)(param_1 + 0x7574) = uVar2;
    return;
  }
  if (param_6 != 0x1403) {
    if (param_6 < 0x1404) {
      bVar1 = param_6 == 0x1401;
    }
    else {
      bVar1 = param_6 == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar2 = 0x500;
      goto LAB_000a92f8;
    }
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
  if (iVar3 != 0) {
    param_7 = param_7 + *(int *)(iVar3 + 0x30);
  }
  *(int *)(param_1 + 0x48d8) = param_7;
  *(int *)(param_1 + 0x4978) = param_7;
  if (param_6 != *(uint *)(param_1 + 0x48dc)) {
    *(uint *)(param_1 + 0x48dc) = param_6;
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
  }
  ((undefined4 (*)())_gleEvalDrawArraysOrElements_Entires_Exec)(param_1,param_2,0,param_5,1,*(int *)(param_1 + 0x4a60) + 0x10,fparam_1,fparam_2,
             fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return;
}

/* _glDrawRangeElements_CompExec @ 0xa9348 (96 bytes) */
int _glDrawRangeElements_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glDrawRangeElements_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  ((void (*)())_glDrawRangeElements_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,fparam_1,in_f2,in_f3,in_f4,
             in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glDrawRangeElements_NoopExec @ 0xa93a8 (708 bytes) */
void _glDrawRangeElements_NoopExec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(param_1 + 0x759c) == '\0') {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_000a9620;
  }
  iVar9 = *(int *)(param_1 + 0x50ac);
  uVar3 = param_3;
  uVar6 = param_4;
  uVar7 = param_5;
  uVar8 = param_6;
  if (iVar9 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') {
LAB_000a9604:
    if (*(char *)(param_1 + 0x759d) != '\0') {
      ((void (*)())_glDrawRangeElements_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      return;
    }
  }
  else {
    iVar5 = *(int *)(param_1 + 0x744c);
    piVar11 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
      ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar3,uVar6,uVar7,uVar8,iVar9,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000a94f0:
      uVar10 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar9 = 0;
      piVar4 = (int *)(param_1 + 0x324);
      do {
        iVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        if (iVar5 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < 9);
      uVar10 = *(uint *)(param_1 + 0x31c);
      if ((uVar10 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_000a94f0;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar10 = uVar10 & 0x17000000;
    }
    else {
      uVar10 = uVar10 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar11 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar10 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar11 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar10 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (bVar1) goto LAB_000a9604;
    if (*(char *)(param_1 + 0x85a8) != *(char *)(param_1 + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
LAB_000a95e8:
      iVar9 = 0x13;
      do {
        *piVar11 = 0;
        piVar11 = piVar11 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      goto LAB_000a9604;
    }
    uVar10 = (**(code **)(param_1 + 0x4788))
                       (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar11);
    if ((((uVar10 & 3) == (uint)*(byte *)(param_1 + 0x7580)) &&
        ((uVar10 & 4) == (uint)*(byte *)(param_1 + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (uVar10 & 8) == (uint)(*(char *)(param_1 + 0x759d) == '\0')))
    goto LAB_000a95e8;
    if ((uVar10 & 4) == 0) {
      uVar10 = uVar10 & 0xfffffffe;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar10);
    if (*(char *)(param_1 + 0x759d) != '\0') goto LAB_000a95e8;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x506;
LAB_000a9620:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glDrawRangeElementArrayAPPLE_Comp @ 0xa966c (44 bytes) */
int _glDrawRangeElementArrayAPPLE_Comp(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  uint param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 uVar1;
  
  if (param_3 <= param_4) {
    uVar1 = ((int (*)())_glDrawElementArrayAPPLE_Comp)(param_1,param_2,param_5,param_6);
    return uVar1;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return param_1;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return param_1;
}

/* _glDrawRangeElementArrayAPPLE_Exec @ 0xa9698 (44 bytes) */
void _glDrawRangeElementArrayAPPLE_Exec(int param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  if (param_3 <= param_4) {
    ((void (*)())_glDrawElementArrayAPPLE_Exec)(param_1,param_2,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6
               ,fparam_7,fparam_8);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return;
}

/* _glDrawRangeElementArrayAPPLE_CompExec @ 0xa96c4 (88 bytes) */
int _glDrawRangeElementArrayAPPLE_CompExec(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glDrawRangeElementArrayAPPLE_Comp)(param_1,param_2,param_3,param_4,param_5,param_6);
  ((void (*)())_glDrawRangeElementArrayAPPLE_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,
             in_f7,in_f8);
  return;
}

/* _glDrawRangeElementArrayAPPLE_NoopExec @ 0xa971c (700 bytes) */
void _glDrawRangeElementArrayAPPLE_NoopExec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(param_1 + 0x759c) == '\0') {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_000a9990;
  }
  iVar9 = *(int *)(param_1 + 0x50ac);
  uVar3 = param_3;
  uVar6 = param_4;
  uVar7 = param_5;
  uVar8 = param_6;
  if (iVar9 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') {
LAB_000a9974:
    if (*(char *)(param_1 + 0x759d) != '\0') {
      ((void (*)())_glDrawRangeElementArrayAPPLE_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4
                 ,fparam_5,fparam_6,fparam_7,fparam_8);
      return;
    }
  }
  else {
    iVar5 = *(int *)(param_1 + 0x744c);
    piVar11 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
      ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar3,uVar6,uVar7,uVar8,iVar9,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000a9860:
      uVar10 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar9 = 0;
      piVar4 = (int *)(param_1 + 0x324);
      do {
        iVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        if (iVar5 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < 9);
      uVar10 = *(uint *)(param_1 + 0x31c);
      if ((uVar10 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_000a9860;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar10 = uVar10 & 0x17000000;
    }
    else {
      uVar10 = uVar10 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar11 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar10 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar11 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar10 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (bVar1) goto LAB_000a9974;
    if (*(char *)(param_1 + 0x85a8) != *(char *)(param_1 + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
LAB_000a9958:
      iVar9 = 0x13;
      do {
        *piVar11 = 0;
        piVar11 = piVar11 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      goto LAB_000a9974;
    }
    uVar10 = (**(code **)(param_1 + 0x4788))
                       (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar11);
    if ((((uVar10 & 3) == (uint)*(byte *)(param_1 + 0x7580)) &&
        ((uVar10 & 4) == (uint)*(byte *)(param_1 + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (uVar10 & 8) == (uint)(*(char *)(param_1 + 0x759d) == '\0')))
    goto LAB_000a9958;
    if ((uVar10 & 4) == 0) {
      uVar10 = uVar10 & 0xfffffffe;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar10);
    if (*(char *)(param_1 + 0x759d) != '\0') goto LAB_000a9958;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x506;
LAB_000a9990:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glMultiDrawRangeElementArrayAPPLE_Comp @ 0xa99d8 (48 bytes) */
int _glMultiDrawRangeElementArrayAPPLE_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  uint param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 uVar1;
  
  if (param_3 <= param_4) {
    uVar1 = ((int (*)())_glMultiDrawElementArrayAPPLE_Comp)(param_1,param_2,param_5,param_6,param_7);
    return uVar1;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return param_1;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return param_1;
}

/* _glMultiDrawRangeElementArrayAPPLE_Exec @ 0xa9a08 (48 bytes) */
void _glMultiDrawRangeElementArrayAPPLE_Exec(int param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  if (param_3 <= param_4) {
    ((void (*)())_glMultiDrawElementArrayAPPLE_Exec)(param_1,param_2,param_5,param_6,param_7,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
               fparam_6,fparam_7,fparam_8);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return;
}

/* _glMultiDrawRangeElementArrayAPPLE_CompExec @ 0xa9a38 (96 bytes) */
int _glMultiDrawRangeElementArrayAPPLE_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glMultiDrawRangeElementArrayAPPLE_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  ((void (*)())_glMultiDrawRangeElementArrayAPPLE_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,fparam_1,in_f2,in_f3,in_f4,
             in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glMultiDrawRangeElementArrayAPPLE_NoopExec @ 0xa9a98 (708 bytes) */
void _glMultiDrawRangeElementArrayAPPLE_NoopExec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(param_1 + 0x759c) == '\0') {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_000a9d10;
  }
  iVar9 = *(int *)(param_1 + 0x50ac);
  uVar3 = param_3;
  uVar6 = param_4;
  uVar7 = param_5;
  uVar8 = param_6;
  if (iVar9 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') {
LAB_000a9cf4:
    if (*(char *)(param_1 + 0x759d) != '\0') {
      ((void (*)())_glMultiDrawRangeElementArrayAPPLE_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      return;
    }
  }
  else {
    iVar5 = *(int *)(param_1 + 0x744c);
    piVar11 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
      ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar3,uVar6,uVar7,uVar8,iVar9,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000a9be0:
      uVar10 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar9 = 0;
      piVar4 = (int *)(param_1 + 0x324);
      do {
        iVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        if (iVar5 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < 9);
      uVar10 = *(uint *)(param_1 + 0x31c);
      if ((uVar10 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_000a9be0;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar10 = uVar10 & 0x17000000;
    }
    else {
      uVar10 = uVar10 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar11 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar10 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar11 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar10 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (bVar1) goto LAB_000a9cf4;
    if (*(char *)(param_1 + 0x85a8) != *(char *)(param_1 + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
LAB_000a9cd8:
      iVar9 = 0x13;
      do {
        *piVar11 = 0;
        piVar11 = piVar11 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      goto LAB_000a9cf4;
    }
    uVar10 = (**(code **)(param_1 + 0x4788))
                       (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar11);
    if ((((uVar10 & 3) == (uint)*(byte *)(param_1 + 0x7580)) &&
        ((uVar10 & 4) == (uint)*(byte *)(param_1 + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (uVar10 & 8) == (uint)(*(char *)(param_1 + 0x759d) == '\0')))
    goto LAB_000a9cd8;
    if ((uVar10 & 4) == 0) {
      uVar10 = uVar10 & 0xfffffffe;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar10);
    if (*(char *)(param_1 + 0x759d) != '\0') goto LAB_000a9cd8;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x506;
LAB_000a9d10:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glDrawElementArrayAPPLE_Comp @ 0xa9d5c (84 bytes) */
int _glDrawElementArrayAPPLE_Comp(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x4a60);
  iVar3 = *(int *)(iVar1 + 0xd8);
  if (*(int *)(iVar1 + 0x35c) != 0) {
    iVar3 = iVar3 + *(int *)(*(int *)(iVar1 + 0x35c) + 0x30);
  }
  *(int *)(param_1 + 0x48d8) = iVar3;
  *(int *)(param_1 + 0x4978) = iVar3;
  if ((uint)*(ushort *)(iVar1 + 0xe0) != *(uint *)(param_1 + 0x48dc)) {
    *(uint *)(param_1 + 0x48dc) = (uint)*(ushort *)(iVar1 + 0xe0);
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
  }
  uVar2 = _gleDrawArraysOrElements_Comp(param_1,param_2,param_3,param_4);
  return uVar2;
}

/* _glDrawElementArrayAPPLE_Exec @ 0xa9db0 (84 bytes) */
void _glDrawElementArrayAPPLE_Exec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x4a60);
  iVar2 = *(int *)(iVar1 + 0xd8);
  if (*(int *)(iVar1 + 0x35c) != 0) {
    iVar2 = iVar2 + *(int *)(*(int *)(iVar1 + 0x35c) + 0x30);
  }
  *(int *)(param_1 + 0x48d8) = iVar2;
  *(int *)(param_1 + 0x4978) = iVar2;
  if ((uint)*(ushort *)(iVar1 + 0xe0) != *(uint *)(param_1 + 0x48dc)) {
    *(uint *)(param_1 + 0x48dc) = (uint)*(ushort *)(iVar1 + 0xe0);
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
  }
  ((int (*)())_gleDrawArraysOrElements_Exec)(param_1,param_2,param_3,param_4,2,iVar1 + 0x10,fparam_1,fparam_2,fparam_3,fparam_4,
             fparam_5,fparam_6,fparam_7,fparam_8);
  return;
}

/* _glDrawElementArrayAPPLE_CompExec @ 0xa9e04 (72 bytes) */
int _glDrawElementArrayAPPLE_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glDrawElementArrayAPPLE_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glDrawElementArrayAPPLE_Exec)(param_1,param_2,param_3,param_4,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glDrawElementArrayAPPLE_NoopExec @ 0xa9e4c (684 bytes) */
void _glDrawElementArrayAPPLE_NoopExec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar7;
  uint uVar8;
  int *piVar9;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(param_1 + 0x759c) == '\0') {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_000aa0b8;
  }
  iVar7 = *(int *)(param_1 + 0x50ac);
  uVar3 = param_3;
  uVar6 = param_4;
  if (iVar7 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') {
LAB_000aa09c:
    if (*(char *)(param_1 + 0x759d) != '\0') {
      ((void (*)())_glDrawElementArrayAPPLE_Exec)(param_1,param_2,param_3,param_4,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                 fparam_6,fparam_7,fparam_8);
      return;
    }
  }
  else {
    iVar5 = *(int *)(param_1 + 0x744c);
    piVar9 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
      ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar3,uVar6,in_r7,in_r8,iVar7,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000a9f88:
      uVar8 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar7 = 0;
      piVar4 = (int *)(param_1 + 0x324);
      do {
        iVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        if (iVar5 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < 9);
      uVar8 = *(uint *)(param_1 + 0x31c);
      if ((uVar8 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_000a9f88;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar8 = uVar8 & 0x17000000;
    }
    else {
      uVar8 = uVar8 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar9 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar8 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar9 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar8 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (bVar1) goto LAB_000aa09c;
    if (*(char *)(param_1 + 0x85a8) != *(char *)(param_1 + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
LAB_000aa080:
      iVar7 = 0x13;
      do {
        *piVar9 = 0;
        piVar9 = piVar9 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      goto LAB_000aa09c;
    }
    uVar8 = (**(code **)(param_1 + 0x4788))
                      (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar9);
    if ((((uVar8 & 3) == (uint)*(byte *)(param_1 + 0x7580)) &&
        ((uVar8 & 4) == (uint)*(byte *)(param_1 + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (uVar8 & 8) == (uint)(*(char *)(param_1 + 0x759d) == '\0')))
    goto LAB_000aa080;
    if ((uVar8 & 4) == 0) {
      uVar8 = uVar8 & 0xfffffffe;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar8);
    if (*(char *)(param_1 + 0x759d) != '\0') goto LAB_000aa080;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x506;
LAB_000aa0b8:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glMultiDrawElementArrayAPPLE_Comp @ 0xaa0f8 (208 bytes) */
int _glMultiDrawElementArrayAPPLE_Comp(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x4a60);
  iVar1 = *(int *)(iVar2 + 0xd8);
  if (param_5 < 0) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x501;
    }
  }
  else {
    if (*(int *)(iVar2 + 0x35c) != 0) {
      iVar1 = iVar1 + *(int *)(*(int *)(iVar2 + 0x35c) + 0x30);
    }
    *(int *)(param_1 + 0x48d8) = iVar1;
    *(int *)(param_1 + 0x4978) = iVar1;
    if ((uint)*(ushort *)(iVar2 + 0xe0) != *(uint *)(param_1 + 0x48dc)) {
      *(uint *)(param_1 + 0x48dc) = (uint)*(ushort *)(iVar2 + 0xe0);
      *(undefined4 *)(param_1 + 0x488c) = 0;
      *(undefined4 *)(param_1 + 0x4890) = 0;
    }
    iVar1 = 0;
    if (0 < param_5) {
      do {
        iVar2 = iVar1 * 4;
        iVar1 = iVar1 + 1;
        _gleDrawArraysOrElements_Comp
                  (param_1,param_2,*(undefined4 *)(param_3 + iVar2),*(undefined4 *)(param_4 + iVar2)
                  );
      } while (iVar1 < param_5);
    }
  }
  return;
}

/* _glMultiDrawElementArrayAPPLE_Exec @ 0xaa1c8 (212 bytes) */
void _glMultiDrawElementArrayAPPLE_Exec(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  double extraout_f1;
  
  iVar3 = *(int *)(param_1 + 0x4a60);
  iVar2 = *(int *)(iVar3 + 0xd8);
  if (param_5 < 0) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x501;
    }
  }
  else {
    if (*(int *)(iVar3 + 0x35c) != 0) {
      iVar2 = iVar2 + *(int *)(*(int *)(iVar3 + 0x35c) + 0x30);
    }
    *(int *)(param_1 + 0x48d8) = iVar2;
    *(int *)(param_1 + 0x4978) = iVar2;
    if ((uint)*(ushort *)(iVar3 + 0xe0) != *(uint *)(param_1 + 0x48dc)) {
      *(uint *)(param_1 + 0x48dc) = (uint)*(ushort *)(iVar3 + 0xe0);
      *(undefined4 *)(param_1 + 0x488c) = 0;
      *(undefined4 *)(param_1 + 0x4890) = 0;
    }
    iVar2 = 0;
    if (0 < param_5) {
      do {
        iVar1 = iVar2 * 4;
        iVar2 = iVar2 + 1;
        ((int (*)())_gleDrawArraysOrElements_Exec)(param_1,param_2,*(undefined4 *)(param_3 + iVar1),*(undefined4 *)(param_4 + iVar1)
                   ,2,iVar3 + 0x10,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                   fparam_8);
        fparam_1 = extraout_f1;
      } while (iVar2 < param_5);
    }
  }
  return;
}

/* _glMultiDrawElementArrayAPPLE_CompExec @ 0xaa29c (152 bytes) */
int _glMultiDrawElementArrayAPPLE_CompExec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  if (param_5 < 0) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x501;
    }
  }
  else {
    iVar2 = 0;
    if (0 < param_5) {
      do {
        iVar1 = iVar2 * 4;
        ((int (*)())_glDrawElementArrayAPPLE_Comp)(param_1,param_2,*(undefined4 *)(iVar1 + param_3),*(undefined4 *)(iVar1 + param_4)
                  );
        iVar2 = iVar2 + 1;
        ((void (*)())_glDrawElementArrayAPPLE_Exec)(param_1,param_2,*(undefined4 *)(iVar1 + param_3),*(undefined4 *)(iVar1 + param_4)
                   ,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
      } while (iVar2 < param_5);
    }
  }
  return;
}

/* _glMultiDrawElementArrayAPPLE_NoopExec @ 0xaa334 (692 bytes) */
void _glMultiDrawElementArrayAPPLE_NoopExec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 in_r8;
  int iVar8;
  uint uVar9;
  int *piVar10;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(param_1 + 0x759c) == '\0') {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_000aa5a4;
  }
  iVar8 = *(int *)(param_1 + 0x50ac);
  uVar3 = param_3;
  uVar6 = param_4;
  uVar7 = param_5;
  if (iVar8 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') {
LAB_000aa588:
    if (*(char *)(param_1 + 0x759d) != '\0') {
      ((void (*)())_glMultiDrawElementArrayAPPLE_Exec)(param_1,param_2,param_3,param_4,param_5,fparam_1,fparam_2,fparam_3,fparam_4,
                 fparam_5,fparam_6,fparam_7,fparam_8);
      return;
    }
  }
  else {
    iVar5 = *(int *)(param_1 + 0x744c);
    piVar10 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
      ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar3,uVar6,uVar7,in_r8,iVar8,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000aa474:
      uVar9 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar8 = 0;
      piVar4 = (int *)(param_1 + 0x324);
      do {
        iVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        if (iVar5 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < 9);
      uVar9 = *(uint *)(param_1 + 0x31c);
      if ((uVar9 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_000aa474;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar9 = uVar9 & 0x17000000;
    }
    else {
      uVar9 = uVar9 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar10 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar9 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar10 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar9 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (bVar1) goto LAB_000aa588;
    if (*(char *)(param_1 + 0x85a8) != *(char *)(param_1 + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
LAB_000aa56c:
      iVar8 = 0x13;
      do {
        *piVar10 = 0;
        piVar10 = piVar10 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      goto LAB_000aa588;
    }
    uVar9 = (**(code **)(param_1 + 0x4788))
                      (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar10);
    if ((((uVar9 & 3) == (uint)*(byte *)(param_1 + 0x7580)) &&
        ((uVar9 & 4) == (uint)*(byte *)(param_1 + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (uVar9 & 8) == (uint)(*(char *)(param_1 + 0x759d) == '\0')))
    goto LAB_000aa56c;
    if ((uVar9 & 4) == 0) {
      uVar9 = uVar9 & 0xfffffffe;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar9);
    if (*(char *)(param_1 + 0x759d) != '\0') goto LAB_000aa56c;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x506;
LAB_000aa5a4:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glMultiDrawArrays_Comp @ 0xaa5e8 (132 bytes) */
int _glMultiDrawArrays_Comp(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1;
  if (param_5 < 0) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x501;
    }
  }
  else {
    iVar2 = 0;
    if (0 < param_5) {
      do {
        iVar1 = iVar2 * 4;
        iVar2 = iVar2 + 1;
        iVar1 = _glDrawArrays_Comp(param_1,param_2,*(undefined4 *)(param_3 + iVar1),
                                   *(undefined4 *)(param_4 + iVar1));
      } while (iVar2 < param_5);
    }
  }
  return iVar1;
}

/* _glMultiDrawArrays_Exec @ 0xaa66c (132 bytes) */
void _glMultiDrawArrays_Exec(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  int iVar1;
  int iVar2;
  
  if (param_5 < 0) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x501;
    }
  }
  else {
    iVar2 = 0;
    if (0 < param_5) {
      do {
        iVar1 = iVar2 * 4;
        iVar2 = iVar2 + 1;
        fparam_1 = (double)((double (*)())_glDrawArrays_STD_Exec)(param_1,param_2,*(undefined4 *)(param_3 + iVar1),
                                      *(undefined4 *)(param_4 + iVar1),fparam_1,fparam_2,fparam_3,
                                      fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      } while (iVar2 < param_5);
    }
  }
  return;
}

/* _glMultiDrawArrays_CompExec @ 0xaa6f0 (80 bytes) */
int _glMultiDrawArrays_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glMultiDrawArrays_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((void (*)())_glMultiDrawArrays_Exec)(param_1,param_2,param_3,param_4,param_5,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,
             in_f8);
  return;
}

/* _glMultiDrawArrays_NoopExec @ 0xaa740 (692 bytes) */
void _glMultiDrawArrays_NoopExec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 in_r8;
  int iVar8;
  uint uVar9;
  int *piVar10;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(param_1 + 0x759c) == '\0') {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_000aa9b0;
  }
  iVar8 = *(int *)(param_1 + 0x50ac);
  uVar3 = param_3;
  uVar6 = param_4;
  uVar7 = param_5;
  if (iVar8 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') {
LAB_000aa994:
    if (*(char *)(param_1 + 0x759d) != '\0') {
      ((void (*)())_glMultiDrawArrays_Exec)(param_1,param_2,param_3,param_4,param_5,fparam_1,fparam_2,fparam_3,fparam_4,
                 fparam_5,fparam_6,fparam_7,fparam_8);
      return;
    }
  }
  else {
    iVar5 = *(int *)(param_1 + 0x744c);
    piVar10 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
      ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar3,uVar6,uVar7,in_r8,iVar8,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000aa880:
      uVar9 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar8 = 0;
      piVar4 = (int *)(param_1 + 0x324);
      do {
        iVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        if (iVar5 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < 9);
      uVar9 = *(uint *)(param_1 + 0x31c);
      if ((uVar9 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_000aa880;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar9 = uVar9 & 0x17000000;
    }
    else {
      uVar9 = uVar9 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar10 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar9 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar10 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar9 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (bVar1) goto LAB_000aa994;
    if (*(char *)(param_1 + 0x85a8) != *(char *)(param_1 + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
LAB_000aa978:
      iVar8 = 0x13;
      do {
        *piVar10 = 0;
        piVar10 = piVar10 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      goto LAB_000aa994;
    }
    uVar9 = (**(code **)(param_1 + 0x4788))
                      (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar10);
    if ((((uVar9 & 3) == (uint)*(byte *)(param_1 + 0x7580)) &&
        ((uVar9 & 4) == (uint)*(byte *)(param_1 + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (uVar9 & 8) == (uint)(*(char *)(param_1 + 0x759d) == '\0')))
    goto LAB_000aa978;
    if ((uVar9 & 4) == 0) {
      uVar9 = uVar9 & 0xfffffffe;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar9);
    if (*(char *)(param_1 + 0x759d) != '\0') goto LAB_000aa978;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x506;
LAB_000aa9b0:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glMultiDrawElements_Comp @ 0xaa9f4 (140 bytes) */
int _glMultiDrawElements_Comp(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1;
  if (param_6 < 0) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x501;
    }
  }
  else {
    iVar2 = 0;
    if (0 < param_6) {
      do {
        iVar1 = iVar2 * 4;
        iVar2 = iVar2 + 1;
        iVar1 = ((int (*)())_glDrawElements_Comp)(param_1,param_2,*(undefined4 *)(param_3 + iVar1),param_4,
                           *(undefined4 *)(param_5 + iVar1));
      } while (iVar2 < param_6);
    }
  }
  return iVar1;
}

/* _glMultiDrawElements_Exec @ 0xaaa80 (136 bytes) */
void _glMultiDrawElements_Exec(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,undefined4 param_5,int param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  undefined4 uVar1;
  
  if (param_6 < 0) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x501;
    }
  }
  else if (0 < param_6) {
    do {
      uVar1 = *param_3;
      param_3 = param_3 + 1;
      fparam_1 = (double)((double (*)())_glDrawElements_STD_Exec)(param_1,param_2,uVar1,param_4,param_5,fparam_1,fparam_2,fparam_3
                                    ,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      param_6 = param_6 + -1;
    } while (param_6 != 0);
  }
  return;
}

/* _glMultiDrawElements_CompExec @ 0xaab08 (88 bytes) */
int _glMultiDrawElements_CompExec(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glMultiDrawElements_Comp)(param_1,param_2,param_3,param_4,param_5,param_6);
  ((void (*)())_glMultiDrawElements_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,
             in_f7,in_f8);
  return;
}

/* _glMultiDrawElements_NoopExec @ 0xaab60 (700 bytes) */
void _glMultiDrawElements_NoopExec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(param_1 + 0x759c) == '\0') {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_000aadd4;
  }
  iVar9 = *(int *)(param_1 + 0x50ac);
  uVar3 = param_3;
  uVar6 = param_4;
  uVar7 = param_5;
  uVar8 = param_6;
  if (iVar9 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') {
LAB_000aadb8:
    if (*(char *)(param_1 + 0x759d) != '\0') {
      ((void (*)())_glMultiDrawElements_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4
                 ,fparam_5,fparam_6,fparam_7,fparam_8);
      return;
    }
  }
  else {
    iVar5 = *(int *)(param_1 + 0x744c);
    piVar11 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
      ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar3,uVar6,uVar7,uVar8,iVar9,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000aaca4:
      uVar10 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar9 = 0;
      piVar4 = (int *)(param_1 + 0x324);
      do {
        iVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        if (iVar5 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < 9);
      uVar10 = *(uint *)(param_1 + 0x31c);
      if ((uVar10 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_000aaca4;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar10 = uVar10 & 0x17000000;
    }
    else {
      uVar10 = uVar10 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar11 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar10 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar11 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar10 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (bVar1) goto LAB_000aadb8;
    if (*(char *)(param_1 + 0x85a8) != *(char *)(param_1 + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
LAB_000aad9c:
      iVar9 = 0x13;
      do {
        *piVar11 = 0;
        piVar11 = piVar11 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      goto LAB_000aadb8;
    }
    uVar10 = (**(code **)(param_1 + 0x4788))
                       (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar11);
    if ((((uVar10 & 3) == (uint)*(byte *)(param_1 + 0x7580)) &&
        ((uVar10 & 4) == (uint)*(byte *)(param_1 + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (uVar10 & 8) == (uint)(*(char *)(param_1 + 0x759d) == '\0')))
    goto LAB_000aad9c;
    if ((uVar10 & 4) == 0) {
      uVar10 = uVar10 & 0xfffffffe;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar10);
    if (*(char *)(param_1 + 0x759d) != '\0') goto LAB_000aad9c;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x506;
LAB_000aadd4:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glWeightARB_ListExec @ 0xaae1c (100 bytes) */
int _glWeightARB_ListExec(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_2;
  iVar4 = 0;
  if (0 < iVar3) {
    piVar2 = (int *)(param_1 + 0x2d0);
    iVar4 = iVar3;
    do {
      param_2 = param_2 + 1;
      *piVar2 = *param_2;
      piVar2 = piVar2 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar4 = iVar3;
    if (3 < iVar3) goto LAB_000aae74;
  }
  do {
    iVar1 = iVar4 * 4;
    iVar4 = iVar4 + 1;
    *(undefined4 *)(iVar1 + param_1 + 0x2d0) = 0;
  } while (iVar4 < 4);
LAB_000aae74:
  return iVar3 * 4 + 4;
}

/* _glWeightbvARB_Exec @ 0xaae80 (188 bytes) */
int _glWeightbvARB_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  char *pcVar1;
  int iVar2;
  double dVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  int iVar7;
  
  fVar5 = FLOAT_00108e64;
  fVar4 = FLOAT_00108e60;
  dVar3 = DOUBLE_00108d58;
  if (4 < param_2) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x501;
      return;
    }
    return;
  }
  iVar7 = 0;
  if (0 < param_2) {
    pfVar6 = (float *)(param_1 + 0x2d0);
    do {
      pcVar1 = (char *)(param_3 + iVar7);
      iVar7 = iVar7 + 1;
      *pfVar6 = (float)((double)CONCAT44(0x43300000,(int)*pcVar1 ^ 0x80000000) - dVar3) * fVar4 +
                fVar5;
      pfVar6 = pfVar6 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    if (3 < iVar7) {
      return;
    }
  }
  do {
    iVar2 = iVar7 * 4;
    iVar7 = iVar7 + 1;
    *(undefined4 *)(iVar2 + param_1 + 0x2d0) = 0;
  } while (iVar7 < 4);
  return;
}

/* _glWeightbvARB_Comp @ 0xaaf3c (216 bytes) */
float * _glWeightbvARB_Comp(float *param_1,float param_2,int param_3)
{
  char *pcVar1;
  double dVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  if ((int)param_2 < 5) {
    param_1 = (float *)_gleAddListItem(param_1,PTR__glWeightARB_ListExec_0011045c,
                                       (int)param_2 * 4 + 4);
    if (param_1 != (float *)0x0) {
      iVar5 = 0;
      *param_1 = param_2;
      fVar4 = FLOAT_00108e64;
      fVar3 = FLOAT_00108e60;
      dVar2 = DOUBLE_00108d58;
      if (0 < (int)param_2) {
        param_1 = param_1 + 1;
        do {
          pcVar1 = (char *)(param_3 + iVar5);
          iVar5 = iVar5 + 1;
          *param_1 = (float)((double)CONCAT44(0x43300000,(int)*pcVar1 ^ 0x80000000) - dVar2) * fVar3
                     + fVar4;
          param_1 = param_1 + 1;
          param_2 = GH_U2F((unsigned int)(((int)param_2 + -1)));
        } while (param_2 != 0.0);
      }
    }
  }
  else if (param_1[0x1d5d] == 0.0) {
    param_1[0x1d5d] = 1.79506e-42;
  }
  return param_1;
}

/* _glWeightbvARB_CompExec @ 0xab014 (64 bytes) */
int _glWeightbvARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((float * (*)())_glWeightbvARB_Comp)(param_1,param_2,param_3);
  ((int (*)())_glWeightbvARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glWeightsvARB_Exec @ 0xab054 (192 bytes) */
int _glWeightsvARB_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  short *param_3;
{
  short sVar1;
  int iVar2;
  double dVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  int iVar7;
  
  fVar5 = FLOAT_00108e74;
  fVar4 = FLOAT_00108e70;
  dVar3 = DOUBLE_00108d58;
  if (4 < param_2) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x501;
      return;
    }
    return;
  }
  iVar7 = 0;
  if (0 < param_2) {
    pfVar6 = (float *)(param_1 + 0x2d0);
    iVar7 = param_2;
    do {
      sVar1 = *param_3;
      param_3 = param_3 + 1;
      *pfVar6 = (float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) - dVar3) * fVar4 +
                fVar5;
      pfVar6 = pfVar6 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    iVar7 = param_2;
    if (3 < param_2) {
      return;
    }
  }
  do {
    iVar2 = iVar7 * 4;
    iVar7 = iVar7 + 1;
    *(undefined4 *)(iVar2 + param_1 + 0x2d0) = 0;
  } while (iVar7 < 4);
  return;
}

/* _glWeightsvARB_Comp @ 0xab114 (216 bytes) */
float * _glWeightsvARB_Comp(float *param_1,float param_2,short *param_3)
{
  short sVar1;
  double dVar2;
  float fVar3;
  float fVar4;
  
  if ((int)param_2 < 5) {
    param_1 = (float *)_gleAddListItem(param_1,PTR__glWeightARB_ListExec_0011045c,
                                       (int)param_2 * 4 + 4);
    if ((param_1 != (float *)0x0) &&
       (*param_1 = param_2, fVar4 = FLOAT_00108e74, fVar3 = FLOAT_00108e70, dVar2 = DOUBLE_00108d58,
       0 < (int)param_2)) {
      param_1 = param_1 + 1;
      do {
        sVar1 = *param_3;
        param_3 = param_3 + 1;
        *param_1 = (float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) - dVar2) * fVar3 +
                   fVar4;
        param_1 = param_1 + 1;
        param_2 = GH_U2F((unsigned int)(((int)param_2 + -1)));
      } while (param_2 != 0.0);
    }
  }
  else if (param_1[0x1d5d] == 0.0) {
    param_1[0x1d5d] = 1.79506e-42;
  }
  return param_1;
}

/* _glWeightsvARB_CompExec @ 0xab1ec (64 bytes) */
int _glWeightsvARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((float * (*)())_glWeightsvARB_Comp)(param_1,param_2,param_3);
  ((int (*)())_glWeightsvARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glWeightivARB_Exec @ 0xab22c (188 bytes) */
int _glWeightivARB_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint *param_3;
{
  int iVar1;
  double dVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  float *pfVar6;
  int iVar7;
  
  fVar4 = FLOAT_00108e6c;
  fVar3 = FLOAT_00108e68;
  dVar2 = DOUBLE_00108d58;
  if (4 < param_2) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x501;
      return;
    }
    return;
  }
  iVar7 = 0;
  if (0 < param_2) {
    pfVar6 = (float *)(param_1 + 0x2d0);
    do {
      uVar5 = *param_3;
      iVar7 = iVar7 + 1;
      param_3 = param_3 + 1;
      *pfVar6 = (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - dVar2) * fVar3 + fVar4;
      pfVar6 = pfVar6 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    if (3 < iVar7) {
      return;
    }
  }
  do {
    iVar1 = iVar7 * 4;
    iVar7 = iVar7 + 1;
    *(undefined4 *)(iVar1 + param_1 + 0x2d0) = 0;
  } while (iVar7 < 4);
  return;
}

/* _glWeightivARB_Comp @ 0xab2e8 (212 bytes) */
float * _glWeightivARB_Comp(float *param_1,float param_2,uint *param_3)
{
  double dVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  
  if ((int)param_2 < 5) {
    param_1 = (float *)_gleAddListItem(param_1,PTR__glWeightARB_ListExec_0011045c,
                                       (int)param_2 * 4 + 4);
    if ((param_1 != (float *)0x0) &&
       (*param_1 = param_2, fVar3 = FLOAT_00108e6c, fVar2 = FLOAT_00108e68, dVar1 = DOUBLE_00108d58,
       0 < (int)param_2)) {
      param_1 = param_1 + 1;
      do {
        uVar4 = *param_3;
        param_3 = param_3 + 1;
        *param_1 = (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
        param_1 = param_1 + 1;
        param_2 = GH_U2F((unsigned int)(((int)param_2 + -1)));
      } while (param_2 != 0.0);
    }
  }
  else if (param_1[0x1d5d] == 0.0) {
    param_1[0x1d5d] = 1.79506e-42;
  }
  return param_1;
}

/* _glWeightivARB_CompExec @ 0xab3bc (64 bytes) */
int _glWeightivARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((float * (*)())_glWeightivARB_Comp)(param_1,param_2,param_3);
  ((int (*)())_glWeightivARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glWeightfvARB_Exec @ 0xab3fc (116 bytes) */
int _glWeightfvARB_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (4 < param_2) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x501;
      return;
    }
    return;
  }
  iVar4 = 0;
  if (0 < param_2) {
    puVar3 = (undefined4 *)(param_1 + 0x2d0);
    do {
      uVar1 = *param_3;
      iVar4 = iVar4 + 1;
      param_3 = param_3 + 1;
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    if (3 < iVar4) {
      return;
    }
  }
  do {
    iVar2 = iVar4 * 4;
    iVar4 = iVar4 + 1;
    *(undefined4 *)(iVar2 + param_1 + 0x2d0) = 0;
  } while (iVar4 < 4);
  return;
}

/* _glWeightfvARB_Comp @ 0xab470 (156 bytes) */
int _glWeightfvARB_Comp(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int *param_3;
{
  int iVar1;
  
  if (param_2 < 5) {
    param_1 = (int *)_gleAddListItem(param_1,PTR__glWeightARB_ListExec_0011045c,param_2 * 4 + 4);
    if ((param_1 != (int *)0x0) && (*param_1 = param_2, 0 < param_2)) {
      param_1 = param_1 + 1;
      do {
        iVar1 = *param_3;
        param_3 = param_3 + 1;
        *param_1 = iVar1;
        param_1 = param_1 + 1;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
  }
  else if (param_1[0x1d5d] == 0) {
    param_1[0x1d5d] = 0x501;
  }
  return param_1;
}

/* _glWeightfvARB_CompExec @ 0xab50c (64 bytes) */
int _glWeightfvARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glWeightfvARB_Comp)(param_1,param_2,param_3);
  ((int (*)())_glWeightfvARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glWeightdvARB_Exec @ 0xab54c (120 bytes) */
int _glWeightdvARB_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  double *param_3;
{
  int iVar1;
  float *pfVar2;
  int iVar3;
  double dVar4;
  
  if (4 < param_2) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x501;
      return;
    }
    return;
  }
  iVar3 = 0;
  if (0 < param_2) {
    pfVar2 = (float *)(param_1 + 0x2d0);
    iVar3 = param_2;
    do {
      dVar4 = *param_3;
      param_3 = param_3 + 1;
      *pfVar2 = (float)dVar4;
      pfVar2 = pfVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar3 = param_2;
    if (3 < param_2) {
      return;
    }
  }
  do {
    iVar1 = iVar3 * 4;
    iVar3 = iVar3 + 1;
    *(undefined4 *)(iVar1 + param_1 + 0x2d0) = 0;
  } while (iVar3 < 4);
  return;
}

/* _glWeightdvARB_Comp @ 0xab5c4 (160 bytes) */
float * _glWeightdvARB_Comp(float *param_1,float param_2,double *param_3)
{
  double dVar1;
  
  if ((int)param_2 < 5) {
    param_1 = (float *)_gleAddListItem(param_1,PTR__glWeightARB_ListExec_0011045c,
                                       (int)param_2 * 4 + 4);
    if ((param_1 != (float *)0x0) && (*param_1 = param_2, 0 < (int)param_2)) {
      param_1 = param_1 + 1;
      do {
        dVar1 = *param_3;
        param_3 = param_3 + 1;
        *param_1 = (float)dVar1;
        param_1 = param_1 + 1;
        param_2 = GH_U2F((unsigned int)(((int)param_2 + -1)));
      } while (param_2 != 0.0);
    }
  }
  else if (param_1[0x1d5d] == 0.0) {
    param_1[0x1d5d] = 1.79506e-42;
  }
  return param_1;
}

/* _glWeightdvARB_CompExec @ 0xab664 (64 bytes) */
int _glWeightdvARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((float * (*)())_glWeightdvARB_Comp)(param_1,param_2,param_3);
  ((int (*)())_glWeightdvARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glWeightubvARB_Exec @ 0xab6a4 (172 bytes) */
int _glWeightubvARB_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  byte *pbVar1;
  int iVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  
  fVar3 = FLOAT_00108e78;
  if (4 < param_2) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x501;
      return;
    }
    return;
  }
  iVar5 = 0;
  if (0 < param_2) {
    pfVar4 = (float *)(param_1 + 0x2d0);
    do {
      pbVar1 = (byte *)(param_3 + iVar5);
      iVar5 = iVar5 + 1;
      *pfVar4 = (GH_U2F((unsigned int)((*pbVar1 | 0x4b000000))) - 8388608.0) * fVar3;
      pfVar4 = pfVar4 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    if (3 < iVar5) {
      return;
    }
  }
  do {
    iVar2 = iVar5 * 4;
    iVar5 = iVar5 + 1;
    *(undefined4 *)(iVar2 + param_1 + 0x2d0) = 0;
  } while (iVar5 < 4);
  return;
}

