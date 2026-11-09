#include "decls.h"

/* _glOrtho_ListExec @ 0x793f0 (360 bytes) */
undefined4 _glOrtho_ListExec(int param_1,float *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  
  pfVar8 = *(float **)(param_1 + 0x4fec);
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4ff4) < 0x18)) {
    fVar1 = param_2[4];
    fVar2 = param_2[3];
    fVar3 = pfVar8[3];
    fVar4 = param_2[5];
    fVar5 = *param_2;
    fVar6 = param_2[2];
    fVar7 = param_2[1];
    pfVar8[0xc] = pfVar8[0xc] + pfVar8[8] * fVar4 + *pfVar8 * fVar2 + pfVar8[4] * fVar1;
    pfVar8[3] = fVar3 * fVar5;
    pfVar8[0xd] = pfVar8[0xd] + pfVar8[9] * fVar4 + pfVar8[1] * fVar2 + pfVar8[5] * fVar1;
    pfVar8[0xe] = pfVar8[0xe] + pfVar8[10] * fVar4 + pfVar8[2] * fVar2 + pfVar8[6] * fVar1;
    pfVar8[0xf] = pfVar8[0xf] + pfVar8[0xb] * fVar4 + fVar3 * fVar2 + pfVar8[7] * fVar1;
    *pfVar8 = *pfVar8 * fVar5;
    pfVar8[1] = pfVar8[1] * fVar5;
    pfVar8[2] = pfVar8[2] * fVar5;
    pfVar8[4] = pfVar8[4] * fVar7;
    pfVar8[5] = pfVar8[5] * fVar7;
    pfVar8[6] = pfVar8[6] * fVar7;
    pfVar8[7] = pfVar8[7] * fVar7;
    pfVar8[0xb] = pfVar8[0xb] * fVar6;
    pfVar8[8] = pfVar8[8] * fVar6;
    pfVar8[9] = pfVar8[9] * fVar6;
    pfVar8[10] = pfVar8[10] * fVar6;
    *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | *(uint *)(param_1 + 0x50a8);
    *(uint *)(param_1 + 0x50b0) = *(uint *)(param_1 + 0x50b0) | *(uint *)(param_1 + 0x50a8);
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return 0x18;
}

/* _glOrtho_Comp @ 0x79558 (364 bytes) */
int _glOrtho_Comp(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  fVar1 = (float)(fparam_2 - fparam_1);
  fVar2 = (float)(fparam_5 - fparam_6);
  fVar3 = (float)(fparam_4 - fparam_3);
  fVar4 = fVar1;
  if (fVar1 < FLOAT_00108e50) {
    fVar4 = -fVar1;
  }
  if (FLOAT_00108e80 <= fVar4) {
    fVar4 = fVar3;
    if (fVar3 < FLOAT_00108e50) {
      fVar4 = -fVar3;
    }
    if (FLOAT_00108e80 <= fVar4) {
      fVar4 = fVar2;
      if (fVar2 < FLOAT_00108e50) {
        fVar4 = -fVar2;
      }
      if (FLOAT_00108e80 <= fVar4) {
        pfVar5 = (float *)_gleAddListItem(param_1,PTR__glOrtho_ListExec_00110230,0x18);
        if (pfVar5 == (float *)0x0) {
          return 0;
        }
        dVar6 = (double)(1.0 / fVar2);
        dVar8 = (double)(1.0 / fVar1);
        dVar7 = (double)(1.0 / fVar3);
        pfVar5[5] = (float)((fparam_6 + fparam_5) * dVar6);
        pfVar5[4] = (float)(-(fparam_4 + fparam_3) * dVar7);
        *pfVar5 = (float)(dVar8 + dVar8);
        pfVar5[3] = (float)(-(fparam_2 + fparam_1) * dVar8);
        pfVar5[1] = (float)(dVar7 + dVar7);
        pfVar5[2] = (float)(dVar6 + dVar6);
        return (int)pfVar5;
      }
    }
  }
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return param_1;
}

/* _glOrtho_CompExec @ 0x796c4 (120 bytes) */
void _glOrtho_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double in_stack_ffffff68;
  double in_stack_ffffff70;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  double in_stack_ffffff88;
  
  ((int (*)())_glOrtho_Comp)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
                in_stack_ffffff68,in_stack_ffffff70,in_stack_ffffff78,in_stack_ffffff80,
                in_stack_ffffff88);
  ((void (*)())_glOrtho_Exec)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
                fparam_9,fparam_10,fparam_11,fparam_12,fparam_13);
  return;
}

/* _glBindProgramARB_Comp @ 0x7973c (84 bytes) */
int _glBindProgramARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glBindProgramARB_ListExec_00110240,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glBindProgramARB_CompExec @ 0x79790 (64 bytes) */
int _glBindProgramARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glBindProgramARB_Comp)(param_1,param_2,param_3);
  _glBindProgramARB_Exec(param_1,param_2,param_3);
  return;
}

/* _glBindProgramARB_ListExec @ 0x797d0 (44 bytes) */
int _glBindProgramARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glBindProgramARB_Exec(param_1,*param_2,param_2[1]);
  return 8;
}

/* _glIsProgramARB_Exec @ 0x797fc (168 bytes) */
int _glIsProgramARB_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  bool bVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar1 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar1 + 0x8024) != '\0') {
      _pthread_mutex_lock((pthread_mutex_t *)(iVar1 + 0x8028));
      iVar1 = *(int *)(param_1 + 0x5148);
    }
    iVar1 = _gleLookupHashObject(iVar1 + 0x4010,param_2);
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
    }
    bVar2 = iVar1 != 0;
  }
  else {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    bVar2 = false;
  }
  return bVar2;
}

/* _glProgramEnvParameter4dARB_Exec @ 0x798a4 (324 bytes) */
void _glProgramEnvParameter4dARB_Exec(int param_1,uint param_2,uint param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_2 == 0x8620) {
    iVar5 = 0;
    if (param_3 < 0x100) {
      uVar2 = *(uint *)(param_1 + 0x31c) | 0x800000;
LAB_00079938:
      *(uint *)(param_1 + 0x31c) = uVar2;
      if (*(int *)(param_1 + 0x5434) == 0) {
        bVar1 = *(byte *)(param_3 + *(int *)(param_1 + 0x5420) + 0x158);
      }
      else {
        bVar1 = *(byte *)(param_3 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x18c);
      }
      iVar6 = (bVar1 >> 3 & 0x1c) + param_1;
      iVar4 = *(int *)(param_1 + 0x5424);
      *(uint *)(iVar6 + 0x324) = *(uint *)(iVar6 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(param_3 + iVar4 + 0x158);
      iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
      *(uint *)(iVar4 + 0x348) = *(uint *)(iVar4 + 0x348) | 1 << (bVar1 & 0x1f);
      iVar4 = *(int *)(iVar5 * 8 + param_1 + 0x4668);
      iVar5 = iVar4 + param_3 * 0x10;
      *(float *)(iVar4 + param_3 * 0x10) = (float)fparam_1;
      *(float *)(iVar5 + 0xc) = (float)fparam_4;
      *(float *)(iVar5 + 4) = (float)fparam_2;
      *(float *)(iVar5 + 8) = (float)fparam_3;
      return;
    }
  }
  else {
    if (param_2 < 0x8621) {
      uVar2 = 0x8200;
    }
    else {
      uVar2 = 0x8804;
    }
    if (param_2 != uVar2) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar3 = 0x500;
      goto LAB_00079930;
    }
    iVar5 = 1;
    if (param_3 < 0x80) {
      uVar2 = *(uint *)(param_1 + 0x31c) | 0x2000000;
      goto LAB_00079938;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x501;
LAB_00079930:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glProgramEnvParameter4dvARB_Exec @ 0x799e8 (340 bytes) */
int _glProgramEnvParameter4dvARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  double *param_4;
{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_2 == 0x8620) {
    iVar5 = 0;
    if (param_3 < 0x100) {
      uVar2 = *(uint *)(param_1 + 0x31c) | 0x800000;
LAB_00079a7c:
      *(uint *)(param_1 + 0x31c) = uVar2;
      if (*(int *)(param_1 + 0x5434) == 0) {
        bVar1 = *(byte *)(param_3 + *(int *)(param_1 + 0x5420) + 0x158);
      }
      else {
        bVar1 = *(byte *)(param_3 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x18c);
      }
      iVar6 = (bVar1 >> 3 & 0x1c) + param_1;
      iVar4 = *(int *)(param_1 + 0x5424);
      *(uint *)(iVar6 + 0x324) = *(uint *)(iVar6 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(param_3 + iVar4 + 0x158);
      iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
      *(uint *)(iVar4 + 0x348) = *(uint *)(iVar4 + 0x348) | 1 << (bVar1 & 0x1f);
      iVar5 = *(int *)(iVar5 * 8 + param_1 + 0x4668);
      *(float *)(iVar5 + param_3 * 0x10) = GH_U2F((unsigned int)(*param_4));
      iVar5 = iVar5 + param_3 * 0x10;
      *(float *)(iVar5 + 4) = GH_U2F((unsigned int)(param_4[1]));
      *(float *)(iVar5 + 8) = GH_U2F((unsigned int)(param_4[2]));
      *(float *)(iVar5 + 0xc) = GH_U2F((unsigned int)(param_4[3]));
      return;
    }
  }
  else {
    if (param_2 < 0x8621) {
      uVar2 = 0x8200;
    }
    else {
      uVar2 = 0x8804;
    }
    if (param_2 != uVar2) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar3 = 0x500;
      goto LAB_00079a74;
    }
    iVar5 = 1;
    if (param_3 < 0x80) {
      uVar2 = *(uint *)(param_1 + 0x31c) | 0x2000000;
      goto LAB_00079a7c;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x501;
LAB_00079a74:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glProgramEnvParameter4fARB_Exec @ 0x79b3c (308 bytes) */
void _glProgramEnvParameter4fARB_Exec(int param_1,uint param_2,uint param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_2 == 0x8620) {
    iVar5 = 0;
    if (param_3 < 0x100) {
      uVar2 = *(uint *)(param_1 + 0x31c) | 0x800000;
LAB_00079bd0:
      *(uint *)(param_1 + 0x31c) = uVar2;
      if (*(int *)(param_1 + 0x5434) == 0) {
        bVar1 = *(byte *)(param_3 + *(int *)(param_1 + 0x5420) + 0x158);
      }
      else {
        bVar1 = *(byte *)(param_3 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x18c);
      }
      iVar6 = (bVar1 >> 3 & 0x1c) + param_1;
      iVar4 = *(int *)(param_1 + 0x5424);
      *(uint *)(iVar6 + 0x324) = *(uint *)(iVar6 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(param_3 + iVar4 + 0x158);
      iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
      *(uint *)(iVar4 + 0x348) = *(uint *)(iVar4 + 0x348) | 1 << (bVar1 & 0x1f);
      iVar4 = *(int *)(iVar5 * 8 + param_1 + 0x4668);
      iVar5 = iVar4 + param_3 * 0x10;
      *(float *)(iVar4 + param_3 * 0x10) = (float)fparam_1;
      *(float *)(iVar5 + 0xc) = (float)fparam_4;
      *(float *)(iVar5 + 4) = (float)fparam_2;
      *(float *)(iVar5 + 8) = (float)fparam_3;
      return;
    }
  }
  else {
    if (param_2 < 0x8621) {
      uVar2 = 0x8200;
    }
    else {
      uVar2 = 0x8804;
    }
    if (param_2 != uVar2) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar3 = 0x500;
      goto LAB_00079bc8;
    }
    iVar5 = 1;
    if (param_3 < 0x80) {
      uVar2 = *(uint *)(param_1 + 0x31c) | 0x2000000;
      goto LAB_00079bd0;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x501;
LAB_00079bc8:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glProgramEnvParameter4dARB_Comp @ 0x79c70 (124 bytes) */
void _glProgramEnvParameter4dARB_Comp(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glProgramEnvParameter4fvARB_ListExec_0011023c,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = (float)fparam_1;
    puVar1[3] = (float)fparam_2;
    puVar1[4] = (float)fparam_3;
    puVar1[5] = (float)fparam_4;
  }
  FUN_00008b68();
  return;
}

/* _glProgramEnvParameter4dvARB_Comp @ 0x79cec (136 bytes) */
int _glProgramEnvParameter4dvARB_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  double *param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glProgramEnvParameter4fvARB_ListExec_0011023c,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = GH_U2F((unsigned int)(*param_4));
    puVar1[3] = GH_U2F((unsigned int)(param_4[1]));
    puVar1[4] = GH_U2F((unsigned int)(param_4[2]));
    puVar1[5] = GH_U2F((unsigned int)(param_4[3]));
  }
  return puVar1;
}

/* _glProgramEnvParameter4fARB_Comp @ 0x79d74 (108 bytes) */
void _glProgramEnvParameter4fARB_Comp(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glProgramEnvParameter4fvARB_ListExec_0011023c,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[5] = (float)fparam_4;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = (float)fparam_1;
    puVar1[3] = (float)fparam_2;
    puVar1[4] = (float)fparam_3;
  }
  FUN_00008b68();
  return;
}

/* _glProgramEnvParameter4fvARB_Comp @ 0x79de0 (120 bytes) */
int _glProgramEnvParameter4fvARB_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 *param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glProgramEnvParameter4fvARB_ListExec_0011023c,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = *param_4;
    puVar1[3] = param_4[1];
    puVar1[4] = param_4[2];
    puVar1[5] = param_4[3];
  }
  return puVar1;
}

/* _glProgramEnvParameter4dARB_CompExec @ 0x79e58 (112 bytes) */
void _glProgramEnvParameter4dARB_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((void (*)())_glProgramEnvParameter4dARB_Comp)(param_1,param_2,param_3,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glProgramEnvParameter4dARB_Exec)(param_1,param_2,param_3,fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,
             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),
             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
  return;
}

/* _glProgramEnvParameter4dvARB_CompExec @ 0x79ec8 (72 bytes) */
int _glProgramEnvParameter4dvARB_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glProgramEnvParameter4dvARB_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glProgramEnvParameter4dvARB_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glProgramEnvParameter4fARB_CompExec @ 0x79f10 (112 bytes) */
void _glProgramEnvParameter4fARB_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  ((void (*)())_glProgramEnvParameter4fARB_Comp)(param_1,param_2,param_3,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glProgramEnvParameter4fARB_Exec)(param_1,param_2,param_3,fparam_1,fparam_2,fparam_3,fparam_4);
  return;
}

/* _glProgramEnvParameter4fvARB_CompExec @ 0x79f80 (72 bytes) */
int _glProgramEnvParameter4fvARB_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glProgramEnvParameter4fvARB_Comp)(param_1,param_2,param_3,param_4);
  _glProgramEnvParameter4fvARB_Exec(param_1,param_2,param_3,param_4);
  return;
}

/* _glProgramEnvParameter4fvARB_ListExec @ 0x79fc8 (52 bytes) */
int _glProgramEnvParameter4fvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glProgramEnvParameter4fvARB_Exec(param_1,*param_2,param_2[1],param_2 + 2);
  return 0x18;
}

/* _glProgramLocalParameter4dARB_Exec @ 0x79ffc (344 bytes) */
void _glProgramLocalParameter4dARB_Exec(int param_1,uint param_2,uint param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_2 == 0x8620) {
    iVar5 = 0;
    if (param_3 < 0x100) {
      uVar2 = *(uint *)(param_1 + 0x31c) | 0x400000;
LAB_0007a090:
      *(uint *)(param_1 + 0x31c) = uVar2;
      if (*(int *)(param_1 + 0x5434) == 0) {
        bVar1 = *(byte *)(param_3 + *(int *)(param_1 + 0x5420) + 0x58);
      }
      else {
        bVar1 = *(byte *)(param_3 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x8c);
      }
      iVar6 = (bVar1 >> 3 & 0x1c) + param_1;
      iVar4 = *(int *)(param_1 + 0x5424);
      *(uint *)(iVar6 + 0x324) = *(uint *)(iVar6 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(param_3 + iVar4 + 0x58);
      iVar6 = iVar5 * 4 + param_1;
      iVar5 = (bVar1 >> 3 & 0x1c) + param_1;
      iVar4 = *(int *)(iVar6 + 0x5420);
      *(uint *)(iVar5 + 0x348) = *(uint *)(iVar5 + 0x348) | 1 << (bVar1 & 0x1f);
      iVar4 = *(int *)(iVar4 + 0x4e0);
      iVar5 = iVar4 + param_3 * 0x10;
      *(float *)(iVar4 + param_3 * 0x10) = (float)fparam_1;
      *(float *)(iVar5 + 0xc) = (float)fparam_4;
      *(float *)(iVar5 + 4) = (float)fparam_2;
      *(float *)(iVar5 + 8) = (float)fparam_3;
      _gleModifyPluginPipelineProgram(param_1,*(int *)(iVar6 + 0x5420) + 0x10,2);
      return;
    }
  }
  else {
    if (param_2 < 0x8621) {
      uVar2 = 0x8200;
    }
    else {
      uVar2 = 0x8804;
    }
    if (param_2 != uVar2) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar3 = 0x500;
      goto LAB_0007a088;
    }
    iVar5 = 1;
    if (param_3 < 0x80) {
      uVar2 = *(uint *)(param_1 + 0x31c) | 0x1000000;
      goto LAB_0007a090;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x501;
LAB_0007a088:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glProgramLocalParameter4dvARB_Exec @ 0x7a154 (360 bytes) */
int _glProgramLocalParameter4dvARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  double *param_4;
{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (param_2 == 0x8620) {
    iVar5 = 0;
    if (param_3 < 0x100) {
      uVar2 = *(uint *)(param_1 + 0x31c) | 0x400000;
LAB_0007a1e8:
      *(uint *)(param_1 + 0x31c) = uVar2;
      if (*(int *)(param_1 + 0x5434) == 0) {
        bVar1 = *(byte *)(param_3 + *(int *)(param_1 + 0x5420) + 0x58);
      }
      else {
        bVar1 = *(byte *)(param_3 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x8c);
      }
      iVar7 = (bVar1 >> 3 & 0x1c) + param_1;
      iVar4 = *(int *)(param_1 + 0x5424);
      iVar6 = iVar5 * 4 + param_1;
      *(uint *)(iVar7 + 0x324) = *(uint *)(iVar7 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(param_3 + iVar4 + 0x58);
      iVar5 = (bVar1 >> 3 & 0x1c) + param_1;
      *(uint *)(iVar5 + 0x348) = *(uint *)(iVar5 + 0x348) | 1 << (bVar1 & 0x1f);
      iVar5 = *(int *)(*(int *)(iVar6 + 0x5420) + 0x4e0);
      *(float *)(iVar5 + param_3 * 0x10) = GH_U2F((unsigned int)(*param_4));
      iVar5 = iVar5 + param_3 * 0x10;
      *(float *)(iVar5 + 4) = GH_U2F((unsigned int)(param_4[1]));
      *(float *)(iVar5 + 8) = GH_U2F((unsigned int)(param_4[2]));
      *(float *)(iVar5 + 0xc) = GH_U2F((unsigned int)(param_4[3]));
      _gleModifyPluginPipelineProgram(param_1,*(int *)(iVar6 + 0x5420) + 0x10,2);
      return;
    }
  }
  else {
    if (param_2 < 0x8621) {
      uVar2 = 0x8200;
    }
    else {
      uVar2 = 0x8804;
    }
    if (param_2 != uVar2) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar3 = 0x500;
      goto LAB_0007a1e0;
    }
    iVar5 = 1;
    if (param_3 < 0x80) {
      uVar2 = *(uint *)(param_1 + 0x31c) | 0x1000000;
      goto LAB_0007a1e8;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x501;
LAB_0007a1e0:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glProgramLocalParameter4dARB_Comp @ 0x7a2bc (124 bytes) */
void _glProgramLocalParameter4dARB_Comp(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glProgramLocalParameter4fvARB_ListExec_00110238,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = (float)fparam_1;
    puVar1[3] = (float)fparam_2;
    puVar1[4] = (float)fparam_3;
    puVar1[5] = (float)fparam_4;
  }
  FUN_00008b68();
  return;
}

/* _glProgramLocalParameter4dvARB_Comp @ 0x7a338 (136 bytes) */
int _glProgramLocalParameter4dvARB_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  double *param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glProgramLocalParameter4fvARB_ListExec_00110238,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = GH_U2F((unsigned int)(*param_4));
    puVar1[3] = GH_U2F((unsigned int)(param_4[1]));
    puVar1[4] = GH_U2F((unsigned int)(param_4[2]));
    puVar1[5] = GH_U2F((unsigned int)(param_4[3]));
  }
  return puVar1;
}

/* _glProgramLocalParameter4fARB_Comp @ 0x7a3c0 (108 bytes) */
void _glProgramLocalParameter4fARB_Comp(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glProgramLocalParameter4fvARB_ListExec_00110238,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[5] = (float)fparam_4;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = (float)fparam_1;
    puVar1[3] = (float)fparam_2;
    puVar1[4] = (float)fparam_3;
  }
  FUN_00008b68();
  return;
}

/* _glProgramLocalParameter4fvARB_Comp @ 0x7a42c (120 bytes) */
int _glProgramLocalParameter4fvARB_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 *param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glProgramLocalParameter4fvARB_ListExec_00110238,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = *param_4;
    puVar1[3] = param_4[1];
    puVar1[4] = param_4[2];
    puVar1[5] = param_4[3];
  }
  return puVar1;
}

/* _glProgramLocalParameter4dARB_CompExec @ 0x7a4a4 (112 bytes) */
void _glProgramLocalParameter4dARB_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((void (*)())_glProgramLocalParameter4dARB_Comp)(param_1,param_2,param_3,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glProgramLocalParameter4dARB_Exec)(param_1,param_2,param_3,fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,
             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),
             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
  return;
}

/* _glProgramLocalParameter4dvARB_CompExec @ 0x7a514 (72 bytes) */
int _glProgramLocalParameter4dvARB_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glProgramLocalParameter4dvARB_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glProgramLocalParameter4dvARB_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glProgramLocalParameter4fARB_CompExec @ 0x7a55c (112 bytes) */
void _glProgramLocalParameter4fARB_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  ((void (*)())_glProgramLocalParameter4fARB_Comp)(param_1,param_2,param_3,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glProgramLocalParameter4fARB_Exec)(param_1,param_2,param_3,fparam_1,fparam_2,fparam_3,fparam_4);
  return;
}

/* _glProgramLocalParameter4fvARB_CompExec @ 0x7a5cc (72 bytes) */
int _glProgramLocalParameter4fvARB_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glProgramLocalParameter4fvARB_Comp)(param_1,param_2,param_3,param_4);
  _glProgramLocalParameter4fvARB_Exec(param_1,param_2,param_3,param_4);
  return;
}

/* _glProgramLocalParameter4fvARB_ListExec @ 0x7a614 (52 bytes) */
int _glProgramLocalParameter4fvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glProgramLocalParameter4fvARB_Exec(param_1,*param_2,param_2[1],param_2 + 2);
  return 0x18;
}

/* _glProgramStringARB_ListExec @ 0x7a648 (68 bytes) */
int _glProgramStringARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glProgramStringARB_Exec(param_1,*param_2,param_2[1],param_2[2],param_2 + 3);
  return param_2[2] + 0xc;
}

/* _glProgramStringARB_Comp @ 0x7a68c (164 bytes) */
int _glProgramStringARB_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  size_t param_4;
  void *param_5;
{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  void *pvVar5;
  
  uVar1 = param_4 + 3 & 0xfffffffc;
  puVar4 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glProgramStringARB_ListExec_00110234,uVar1 + 0xc);
  pvVar5 = (void *)0x0;
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = param_2;
    puVar4[1] = param_3;
    puVar4[2] = uVar1;
    pvVar5 = _memcpy(puVar4 + 3,param_5,param_4);
    if ((int)param_4 <= (int)uVar1) {
      iVar2 = (uVar1 + 1) - param_4;
      puVar3 = (undefined1 *)((int)puVar4 + param_4 + 0xc);
      do {
        *puVar3 = 0x20;
        puVar3 = puVar3 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  return pvVar5;
}

/* _glProgramStringARB_CompExec @ 0x7a730 (80 bytes) */
int _glProgramStringARB_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glProgramStringARB_Comp)(param_1,param_2,param_3,param_4,param_5);
  _glProgramStringARB_Exec(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glGetProgramStringARB_Exec @ 0x7a780 (196 bytes) */
int _glGetProgramStringARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  int param_3;
  int param_4;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_3 == 0x8628) {
      if (param_2 == 0x8620) {
        iVar3 = 0;
LAB_0007a80c:
        iVar5 = 0;
        iVar4 = *(int *)(iVar3 * 4 + param_1 + 0x5420);
        iVar3 = *(int *)(iVar4 + 0x18);
        iVar4 = *(int *)(iVar4 + 0x14);
        if (iVar3 != 0) {
          do {
            *(undefined1 *)(param_4 + iVar5) = *(undefined1 *)(iVar4 + iVar5);
            iVar5 = iVar5 + 1;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          return;
        }
        return;
      }
      if (param_2 < 0x8621) {
        uVar2 = 0x8200;
      }
      else {
        uVar2 = 0x8804;
      }
      if (param_2 == uVar2) {
        iVar3 = 1;
        goto LAB_0007a80c;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glGetProgramEnvParameterdvARB_Exec @ 0x7a844 (212 bytes) */
int _glGetProgramEnvParameterdvARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  double *param_4;
{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8620) {
      bVar1 = 0xff < param_3;
      iVar4 = 0;
    }
    else {
      if (param_2 < 0x8621) {
        uVar3 = 0x8200;
      }
      else {
        uVar3 = 0x8804;
      }
      if (param_2 != uVar3) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar2 = 0x500;
        goto LAB_0007a8b8;
      }
      bVar1 = 0x7f < param_3;
      iVar4 = 1;
    }
    if (!bVar1) {
      iVar4 = *(int *)(iVar4 * 8 + param_1 + 0x4668);
      iVar5 = iVar4 + param_3 * 0x10;
      *param_4 = (double)*(float *)(iVar4 + param_3 * 0x10);
      param_4[1] = (double)*(float *)(iVar5 + 4);
      param_4[2] = (double)*(float *)(iVar5 + 8);
      param_4[3] = (double)*(float *)(iVar5 + 0xc);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
  }
LAB_0007a8b8:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glGetProgramEnvParameterfvARB_Exec @ 0x7a918 (212 bytes) */
int _glGetProgramEnvParameterfvARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  undefined4 *param_4;
{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8620) {
      bVar1 = 0xff < param_3;
      iVar4 = 0;
    }
    else {
      if (param_2 < 0x8621) {
        uVar3 = 0x8200;
      }
      else {
        uVar3 = 0x8804;
      }
      if (param_2 != uVar3) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar2 = 0x500;
        goto LAB_0007a98c;
      }
      bVar1 = 0x7f < param_3;
      iVar4 = 1;
    }
    if (!bVar1) {
      iVar4 = *(int *)(iVar4 * 8 + param_1 + 0x4668);
      iVar5 = iVar4 + param_3 * 0x10;
      *param_4 = *(undefined4 *)(iVar4 + param_3 * 0x10);
      param_4[1] = *(undefined4 *)(iVar5 + 4);
      param_4[2] = *(undefined4 *)(iVar5 + 8);
      param_4[3] = *(undefined4 *)(iVar5 + 0xc);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
  }
LAB_0007a98c:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glGetProgramLocalParameterdvARB_Exec @ 0x7a9ec (216 bytes) */
int _glGetProgramLocalParameterdvARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  double *param_4;
{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8620) {
      bVar1 = 0xff < param_3;
      iVar4 = 0;
    }
    else {
      if (param_2 < 0x8621) {
        uVar3 = 0x8200;
      }
      else {
        uVar3 = 0x8804;
      }
      if (param_2 != uVar3) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar2 = 0x500;
        goto LAB_0007aa60;
      }
      bVar1 = 0x7f < param_3;
      iVar4 = 1;
    }
    if (!bVar1) {
      iVar4 = *(int *)(*(int *)(iVar4 * 4 + param_1 + 0x5420) + 0x4e0);
      iVar5 = iVar4 + param_3 * 0x10;
      *param_4 = (double)*(float *)(iVar4 + param_3 * 0x10);
      param_4[1] = (double)*(float *)(iVar5 + 4);
      param_4[2] = (double)*(float *)(iVar5 + 8);
      param_4[3] = (double)*(float *)(iVar5 + 0xc);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
  }
LAB_0007aa60:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glGetProgramLocalParameterfvARB_Exec @ 0x7aac4 (216 bytes) */
int _glGetProgramLocalParameterfvARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  undefined4 *param_4;
{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8620) {
      bVar1 = 0xff < param_3;
      iVar4 = 0;
    }
    else {
      if (param_2 < 0x8621) {
        uVar3 = 0x8200;
      }
      else {
        uVar3 = 0x8804;
      }
      if (param_2 != uVar3) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar2 = 0x500;
        goto LAB_0007ab38;
      }
      bVar1 = 0x7f < param_3;
      iVar4 = 1;
    }
    if (!bVar1) {
      iVar4 = *(int *)(*(int *)(iVar4 * 4 + param_1 + 0x5420) + 0x4e0);
      iVar5 = iVar4 + param_3 * 0x10;
      *param_4 = *(undefined4 *)(iVar4 + param_3 * 0x10);
      param_4[1] = *(undefined4 *)(iVar5 + 4);
      param_4[2] = *(undefined4 *)(iVar5 + 8);
      param_4[3] = *(undefined4 *)(iVar5 + 0xc);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
  }
LAB_0007ab38:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glPixelMapfv_ListExec @ 0x7ab9c (68 bytes) */
int _glPixelMapfv_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glPixelMapfv_Exec)(param_1,*param_2,param_2[1],param_2 + 2);
  return param_2[1] * 4 + 8;
}

/* _glPixelMapfv_Comp @ 0x7abe0 (236 bytes) */
int _glPixelMapfv_Comp(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  uint param_4;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x4a6c);
  if (iVar3 == 0) {
    iVar2 = param_3 << 2;
  }
  else {
    iVar2 = param_3 * 4;
    if ((*(int *)(iVar3 + 0x38) < (int)(iVar2 + param_4)) || ((param_4 & 3) != 0)) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return (undefined4 *)param_1;
      }
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
      return (undefined4 *)param_1;
    }
    if (*(int *)(iVar3 + 0x40) != 0) {
      _gleSynchronizePluginBuffer(param_1,iVar3 + 0x10);
    }
    param_4 = param_4 + *(int *)(iVar3 + 0x30);
  }
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glPixelMapfv_ListExec_0011024c,iVar2 + 8);
  if (puVar1 != (undefined4 *)0x0) {
    iVar3 = 0;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1 = puVar1 + 2;
    if (0 < param_3) {
      do {
        puVar1[iVar3] = *(undefined4 *)(param_4 + iVar3 * 4);
        param_3 = param_3 + -1;
        iVar3 = iVar3 + 1;
      } while (param_3 != 0);
    }
  }
  return puVar1;
}

/* _glPixelMapfv_Exec @ 0x7accc (1760 bytes) */
int _glPixelMapfv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  uint param_3;
  uint param_4;
{
  int iVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  float fVar5;
  void *pvVar6;
  uint uVar7;
  int iVar8;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
LAB_0007ad34:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar4 = 0x502;
    goto LAB_0007b32c;
  }
  uVar7 = param_3 - 1;
  if (uVar7 < 0x100) {
    iVar8 = *(int *)(param_1 + 0x4a6c);
    if (iVar8 != 0) {
      if ((*(int *)(iVar8 + 0x38) < (int)(param_3 * 4 + param_4)) || ((param_4 & 3) != 0))
      goto LAB_0007ad34;
      if (*(int *)(iVar8 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(param_1,iVar8 + 0x10);
      }
      param_4 = param_4 + *(int *)(iVar8 + 0x30);
    }
    switch(param_2) {
    case 0xc70:
      if ((param_3 & uVar7) != 0) goto LAB_0007b07c;
      if (*(undefined **)(param_1 + 0x3248) != PTR__gle_default_pix_map_i_00112044) {
        _free(*(undefined **)(param_1 + 0x3248));
      }
      pvVar6 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3248) = pvVar6;
      if (pvVar6 != (void *)0x0) {
        iVar8 = 0;
        *(uint *)(param_1 + 0x3270) = param_3;
        if (0 < (int)param_3) {
          do {
            iVar1 = iVar8 * 4;
            iVar8 = iVar8 + 1;
            *(int *)(iVar1 + *(int *)(param_1 + 0x3248)) = (int)GH_F2U(*(float *)(iVar1 + param_4));
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    case 0xc71:
      if ((param_3 & uVar7) != 0) goto LAB_0007b07c;
      if (*(undefined **)(param_1 + 0x326c) != PTR__gle_default_pix_map_i_00112044) {
        _free(*(undefined **)(param_1 + 0x326c));
      }
      pvVar6 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x326c) = pvVar6;
      if (pvVar6 != (void *)0x0) {
        iVar8 = 0;
        *(uint *)(param_1 + 0x3274) = param_3;
        if (0 < (int)param_3) {
          do {
            iVar1 = iVar8 * 4;
            iVar8 = iVar8 + 1;
            *(int *)(iVar1 + *(int *)(param_1 + 0x326c)) = (int)GH_F2U(*(float *)(iVar1 + param_4));
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    case 0xc72:
      if ((param_3 & uVar7) != 0) goto LAB_0007b07c;
      if (*(undefined **)(param_1 + 0x324c) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x324c));
      }
      pvVar6 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x324c) = pvVar6;
      if (pvVar6 != (void *)0x0) {
        iVar8 = 0;
        *(uint *)(param_1 + 0x3278) = param_3;
        fVar3 = FLOAT_00108e54;
        fVar2 = FLOAT_00108e50;
        if (0 < (int)param_3) {
          do {
            fVar5 = *(float *)(param_4 + iVar8 * 4);
            if (fVar2 <= fVar5) {
              if (fVar3 < fVar5) {
                fVar5 = 1.0;
              }
            }
            else {
              fVar5 = 0.0;
            }
            *(float *)(iVar8 * 4 + *(int *)(param_1 + 0x324c)) = fVar5;
            iVar8 = iVar8 + 1;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    case 0xc73:
      if ((param_3 & uVar7) != 0) goto LAB_0007b07c;
      if (*(undefined **)(param_1 + 0x3250) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x3250));
      }
      pvVar6 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3250) = pvVar6;
      if (pvVar6 != (void *)0x0) {
        iVar8 = 0;
        *(uint *)(param_1 + 0x327c) = param_3;
        fVar3 = FLOAT_00108e54;
        fVar2 = FLOAT_00108e50;
        if (0 < (int)param_3) {
          do {
            fVar5 = *(float *)(param_4 + iVar8 * 4);
            if (fVar2 <= fVar5) {
              if (fVar3 < fVar5) {
                fVar5 = 1.0;
              }
            }
            else {
              fVar5 = 0.0;
            }
            *(float *)(iVar8 * 4 + *(int *)(param_1 + 0x3250)) = fVar5;
            iVar8 = iVar8 + 1;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    case 0xc74:
      if ((param_3 & uVar7) != 0) goto LAB_0007b07c;
      if (*(undefined **)(param_1 + 0x3254) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x3254));
      }
      pvVar6 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3254) = pvVar6;
      if (pvVar6 != (void *)0x0) {
        iVar8 = 0;
        *(uint *)(param_1 + 0x3280) = param_3;
        fVar3 = FLOAT_00108e54;
        fVar2 = FLOAT_00108e50;
        if (0 < (int)param_3) {
          do {
            fVar5 = *(float *)(param_4 + iVar8 * 4);
            if (fVar2 <= fVar5) {
              if (fVar3 < fVar5) {
                fVar5 = 1.0;
              }
            }
            else {
              fVar5 = 0.0;
            }
            *(float *)(iVar8 * 4 + *(int *)(param_1 + 0x3254)) = fVar5;
            iVar8 = iVar8 + 1;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    case 0xc75:
      if ((param_3 & uVar7) != 0) goto LAB_0007b07c;
      if (*(undefined **)(param_1 + 0x3258) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x3258));
      }
      pvVar6 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3258) = pvVar6;
      if (pvVar6 != (void *)0x0) {
        iVar8 = 0;
        *(uint *)(param_1 + 0x3284) = param_3;
        fVar3 = FLOAT_00108e54;
        fVar2 = FLOAT_00108e50;
        if (0 < (int)param_3) {
          do {
            fVar5 = *(float *)(param_4 + iVar8 * 4);
            if (fVar2 <= fVar5) {
              if (fVar3 < fVar5) {
                fVar5 = 1.0;
              }
            }
            else {
              fVar5 = 0.0;
            }
            *(float *)(iVar8 * 4 + *(int *)(param_1 + 0x3258)) = fVar5;
            iVar8 = iVar8 + 1;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    case 0xc76:
      if (*(undefined **)(param_1 + 0x325c) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x325c));
      }
      pvVar6 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x325c) = pvVar6;
      if (pvVar6 != (void *)0x0) {
        iVar8 = 0;
        *(uint *)(param_1 + 0x3288) = param_3;
        fVar3 = FLOAT_00108e54;
        fVar2 = FLOAT_00108e50;
        if (0 < (int)param_3) {
          do {
            fVar5 = *(float *)(param_4 + iVar8 * 4);
            if (fVar2 <= fVar5) {
              if (fVar3 < fVar5) {
                fVar5 = 1.0;
              }
            }
            else {
              fVar5 = 0.0;
            }
            *(float *)(iVar8 * 4 + *(int *)(param_1 + 0x325c)) = fVar5;
            iVar8 = iVar8 + 1;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    case 0xc77:
      if (*(undefined **)(param_1 + 0x3260) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x3260));
      }
      pvVar6 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3260) = pvVar6;
      if (pvVar6 != (void *)0x0) {
        iVar8 = 0;
        *(uint *)(param_1 + 0x328c) = param_3;
        fVar3 = FLOAT_00108e54;
        fVar2 = FLOAT_00108e50;
        if (0 < (int)param_3) {
          do {
            fVar5 = *(float *)(param_4 + iVar8 * 4);
            if (fVar2 <= fVar5) {
              if (fVar3 < fVar5) {
                fVar5 = 1.0;
              }
            }
            else {
              fVar5 = 0.0;
            }
            *(float *)(iVar8 * 4 + *(int *)(param_1 + 0x3260)) = fVar5;
            iVar8 = iVar8 + 1;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    case 0xc78:
      if (*(undefined **)(param_1 + 0x3264) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x3264));
      }
      pvVar6 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3264) = pvVar6;
      if (pvVar6 != (void *)0x0) {
        iVar8 = 0;
        *(uint *)(param_1 + 0x3290) = param_3;
        fVar3 = FLOAT_00108e54;
        fVar2 = FLOAT_00108e50;
        if (0 < (int)param_3) {
          do {
            fVar5 = *(float *)(param_4 + iVar8 * 4);
            if (fVar2 <= fVar5) {
              if (fVar3 < fVar5) {
                fVar5 = 1.0;
              }
            }
            else {
              fVar5 = 0.0;
            }
            *(float *)(iVar8 * 4 + *(int *)(param_1 + 0x3264)) = fVar5;
            iVar8 = iVar8 + 1;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    case 0xc79:
      if (*(undefined **)(param_1 + 0x3268) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x3268));
      }
      pvVar6 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3268) = pvVar6;
      if (pvVar6 != (void *)0x0) {
        iVar8 = 0;
        *(uint *)(param_1 + 0x3294) = param_3;
        fVar3 = FLOAT_00108e54;
        fVar2 = FLOAT_00108e50;
        if (0 < (int)param_3) {
          do {
            fVar5 = *(float *)(param_4 + iVar8 * 4);
            if (fVar2 <= fVar5) {
              if (fVar3 < fVar5) {
                fVar5 = 1.0;
              }
            }
            else {
              fVar5 = 0.0;
            }
            *(float *)(iVar8 * 4 + *(int *)(param_1 + 0x3268)) = fVar5;
            iVar8 = iVar8 + 1;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    default:
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x500;
      }
LAB_0007b3b4:
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x200000;
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar4 = 0x505;
  }
  else {
LAB_0007b07c:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar4 = 0x501;
  }
LAB_0007b32c:
  *(undefined4 *)(param_1 + 0x7574) = uVar4;
  return;
}

/* _glPixelMapfv_CompExec @ 0x7b3d4 (72 bytes) */
int _glPixelMapfv_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glPixelMapfv_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glPixelMapfv_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glPixelMapuiv_ListExec @ 0x7b41c (68 bytes) */
int _glPixelMapuiv_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glPixelMapuiv_Exec)(param_1,*param_2,param_2[1],param_2 + 2);
  return param_2[1] * 4 + 8;
}

/* _glPixelMapuiv_Comp @ 0x7b460 (236 bytes) */
int _glPixelMapuiv_Comp(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  uint param_4;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x4a6c);
  if (iVar3 == 0) {
    iVar2 = param_3 << 2;
  }
  else {
    iVar2 = param_3 * 4;
    if ((*(int *)(iVar3 + 0x38) < (int)(iVar2 + param_4)) || ((param_4 & 3) != 0)) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return (undefined4 *)param_1;
      }
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
      return (undefined4 *)param_1;
    }
    if (*(int *)(iVar3 + 0x40) != 0) {
      _gleSynchronizePluginBuffer(param_1,iVar3 + 0x10);
    }
    param_4 = param_4 + *(int *)(iVar3 + 0x30);
  }
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glPixelMapuiv_ListExec_00110248,iVar2 + 8);
  if (puVar1 != (undefined4 *)0x0) {
    iVar3 = 0;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1 = puVar1 + 2;
    if (0 < param_3) {
      do {
        puVar1[iVar3] = *(undefined4 *)(param_4 + iVar3 * 4);
        param_3 = param_3 + -1;
        iVar3 = iVar3 + 1;
      } while (param_3 != 0);
    }
  }
  return puVar1;
}

/* _glPixelMapuiv_Exec @ 0x7b54c (1640 bytes) */
int _glPixelMapuiv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  uint param_3;
  uint param_4;
{
  int iVar1;
  double dVar2;
  double dVar3;
  undefined4 uVar4;
  void *pvVar5;
  uint uVar6;
  int iVar7;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
LAB_0007b5b4:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar4 = 0x502;
    goto LAB_0007bb40;
  }
  uVar6 = param_3 - 1;
  if (uVar6 < 0x100) {
    iVar7 = *(int *)(param_1 + 0x4a6c);
    if (iVar7 != 0) {
      if ((*(int *)(iVar7 + 0x38) < (int)(param_3 * 4 + param_4)) || ((param_4 & 3) != 0))
      goto LAB_0007b5b4;
      if (*(int *)(iVar7 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(param_1,iVar7 + 0x10);
      }
      param_4 = param_4 + *(int *)(iVar7 + 0x30);
    }
    switch(param_2) {
    case 0xc70:
      if ((param_3 & uVar6) != 0) goto LAB_0007b8c0;
      if (*(undefined **)(param_1 + 0x3248) != PTR__gle_default_pix_map_i_00112044) {
        _free(*(undefined **)(param_1 + 0x3248));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3248) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x3270) = param_3;
        if (0 < (int)param_3) {
          do {
            iVar1 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x3248)) = *(undefined4 *)(iVar1 + param_4);
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    case 0xc71:
      if ((param_3 & uVar6) != 0) goto LAB_0007b8c0;
      if (*(undefined **)(param_1 + 0x326c) != PTR__gle_default_pix_map_i_00112044) {
        _free(*(undefined **)(param_1 + 0x326c));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x326c) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x3274) = param_3;
        if (0 < (int)param_3) {
          do {
            iVar1 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x326c)) = *(undefined4 *)(iVar1 + param_4);
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    case 0xc72:
      if ((param_3 & uVar6) != 0) goto LAB_0007b8c0;
      if (*(undefined **)(param_1 + 0x324c) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x324c));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x324c) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x3278) = param_3;
        dVar3 = DOUBLE_00108da0;
        dVar2 = DOUBLE_00108d70;
        if (0 < (int)param_3) {
          do {
            iVar1 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(float *)(iVar1 + *(int *)(param_1 + 0x324c)) =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          *(undefined4 *)(iVar1 + param_4)) - dVar2)
                        * dVar3);
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    case 0xc73:
      if ((param_3 & uVar6) != 0) goto LAB_0007b8c0;
      if (*(undefined **)(param_1 + 0x3250) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x3250));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3250) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x327c) = param_3;
        dVar3 = DOUBLE_00108da0;
        dVar2 = DOUBLE_00108d70;
        if (0 < (int)param_3) {
          do {
            iVar1 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(float *)(iVar1 + *(int *)(param_1 + 0x3250)) =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          *(undefined4 *)(iVar1 + param_4)) - dVar2)
                        * dVar3);
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    case 0xc74:
      if ((param_3 & uVar6) != 0) goto LAB_0007b8c0;
      if (*(undefined **)(param_1 + 0x3254) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x3254));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3254) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x3280) = param_3;
        dVar3 = DOUBLE_00108da0;
        dVar2 = DOUBLE_00108d70;
        if (0 < (int)param_3) {
          do {
            iVar1 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(float *)(iVar1 + *(int *)(param_1 + 0x3254)) =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          *(undefined4 *)(iVar1 + param_4)) - dVar2)
                        * dVar3);
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    case 0xc75:
      if ((param_3 & uVar6) != 0) goto LAB_0007b8c0;
      if (*(undefined **)(param_1 + 0x3258) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x3258));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3258) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x3284) = param_3;
        dVar3 = DOUBLE_00108da0;
        dVar2 = DOUBLE_00108d70;
        if (0 < (int)param_3) {
          do {
            iVar1 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(float *)(iVar1 + *(int *)(param_1 + 0x3258)) =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          *(undefined4 *)(iVar1 + param_4)) - dVar2)
                        * dVar3);
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    case 0xc76:
      if (*(undefined **)(param_1 + 0x325c) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x325c));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x325c) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x3288) = param_3;
        dVar3 = DOUBLE_00108da0;
        dVar2 = DOUBLE_00108d70;
        if (0 < (int)param_3) {
          do {
            iVar1 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(float *)(iVar1 + *(int *)(param_1 + 0x325c)) =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          *(undefined4 *)(iVar1 + param_4)) - dVar2)
                        * dVar3);
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    case 0xc77:
      if (*(undefined **)(param_1 + 0x3260) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x3260));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3260) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x328c) = param_3;
        dVar3 = DOUBLE_00108da0;
        dVar2 = DOUBLE_00108d70;
        if (0 < (int)param_3) {
          do {
            iVar1 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(float *)(iVar1 + *(int *)(param_1 + 0x3260)) =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          *(undefined4 *)(iVar1 + param_4)) - dVar2)
                        * dVar3);
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    case 0xc78:
      if (*(undefined **)(param_1 + 0x3264) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x3264));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3264) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x3290) = param_3;
        dVar3 = DOUBLE_00108da0;
        dVar2 = DOUBLE_00108d70;
        if (0 < (int)param_3) {
          do {
            iVar1 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(float *)(iVar1 + *(int *)(param_1 + 0x3264)) =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          *(undefined4 *)(iVar1 + param_4)) - dVar2)
                        * dVar3);
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    case 0xc79:
      if (*(undefined **)(param_1 + 0x3268) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x3268));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3268) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x3294) = param_3;
        dVar3 = DOUBLE_00108da0;
        dVar2 = DOUBLE_00108d70;
        if (0 < (int)param_3) {
          do {
            iVar1 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(float *)(iVar1 + *(int *)(param_1 + 0x3268)) =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          *(undefined4 *)(iVar1 + param_4)) - dVar2)
                        * dVar3);
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    default:
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x500;
      }
LAB_0007bbbc:
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x200000;
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar4 = 0x505;
  }
  else {
LAB_0007b8c0:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar4 = 0x501;
  }
LAB_0007bb40:
  *(undefined4 *)(param_1 + 0x7574) = uVar4;
  return;
}

/* _glPixelMapuiv_CompExec @ 0x7bbdc (72 bytes) */
int _glPixelMapuiv_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glPixelMapuiv_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glPixelMapuiv_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glPixelMapusv_ListExec @ 0x7bc24 (76 bytes) */
int _glPixelMapusv_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glPixelMapusv_Exec)(param_1,*param_2,param_2[1],param_2 + 2);
  return (param_2[1] + (param_2[1] & 1)) * 2 + 8;
}

/* _glPixelMapusv_Comp @ 0x7bc70 (240 bytes) */
int _glPixelMapusv_Comp(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  uint param_3;
  uint param_4;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x4a6c);
  if (iVar3 != 0) {
    if ((*(int *)(iVar3 + 0x38) < (int)(param_3 * 2 + param_4)) || ((param_4 & 1) != 0)) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return (undefined4 *)param_1;
      }
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
      return (undefined4 *)param_1;
    }
    if (*(int *)(iVar3 + 0x40) != 0) {
      _gleSynchronizePluginBuffer(param_1,iVar3 + 0x10);
    }
    param_4 = param_4 + *(int *)(iVar3 + 0x30);
  }
  puVar2 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glPixelMapusv_ListExec_00110244,
                           (param_3 + (param_3 & 1)) * 2 + 8);
  if (puVar2 != (undefined4 *)0x0) {
    iVar3 = 0;
    *puVar2 = param_2;
    puVar2[1] = param_3;
    puVar2 = puVar2 + 2;
    if (0 < (int)param_3) {
      do {
        iVar1 = iVar3 * 2;
        iVar3 = iVar3 + 1;
        *(undefined2 *)((int)puVar2 + iVar1) = *(undefined2 *)(param_4 + iVar1);
        param_3 = param_3 - 1;
      } while (param_3 != 0);
    }
  }
  return puVar2;
}

/* _glPixelMapusv_Exec @ 0x7bd60 (1688 bytes) */
int _glPixelMapusv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  uint param_3;
  ushort *param_4;
{
  ushort uVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  void *pvVar5;
  uint uVar6;
  int iVar7;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
LAB_0007bdc8:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar4 = 0x502;
    goto LAB_0007c380;
  }
  uVar6 = param_3 - 1;
  if (uVar6 < 0x100) {
    iVar7 = *(int *)(param_1 + 0x4a6c);
    if (iVar7 != 0) {
      if ((*(int *)(iVar7 + 0x38) < (int)(param_4 + param_3)) || (((uint)param_4 & 1) != 0))
      goto LAB_0007bdc8;
      if (*(int *)(iVar7 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(param_1,iVar7 + 0x10);
      }
      param_4 = (ushort *)((int)param_4 + *(int *)(iVar7 + 0x30));
    }
    switch(param_2) {
    case 0xc70:
      if ((param_3 & uVar6) != 0) goto LAB_0007c0f0;
      if (*(undefined **)(param_1 + 0x3248) != PTR__gle_default_pix_map_i_00112044) {
        _free(*(undefined **)(param_1 + 0x3248));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3248) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x3270) = param_3;
        if (0 < (int)param_3) {
          do {
            uVar1 = *param_4;
            iVar2 = iVar7 * 4;
            param_4 = param_4 + 1;
            iVar7 = iVar7 + 1;
            *(uint *)(iVar2 + *(int *)(param_1 + 0x3248)) = (uint)uVar1;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007c400;
      }
      break;
    case 0xc71:
      if ((param_3 & uVar6) != 0) goto LAB_0007c0f0;
      if (*(undefined **)(param_1 + 0x326c) != PTR__gle_default_pix_map_i_00112044) {
        _free(*(undefined **)(param_1 + 0x326c));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x326c) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x3274) = param_3;
        if (0 < (int)param_3) {
          do {
            uVar1 = *param_4;
            iVar2 = iVar7 * 4;
            param_4 = param_4 + 1;
            iVar7 = iVar7 + 1;
            *(uint *)(iVar2 + *(int *)(param_1 + 0x326c)) = (uint)uVar1;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007c400;
      }
      break;
    case 0xc72:
      if ((param_3 & uVar6) != 0) goto LAB_0007c0f0;
      if (*(undefined **)(param_1 + 0x324c) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x324c));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x324c) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x3278) = param_3;
        fVar3 = FLOAT_00108e74;
        if (0 < (int)param_3) {
          do {
            uVar1 = *param_4;
            param_4 = param_4 + 1;
            iVar2 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(float *)(iVar2 + *(int *)(param_1 + 0x324c)) =
                 (GH_U2F((unsigned int)((uVar1 | 0x4b000000))) - 8388608.0) * fVar3;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007c400;
      }
      break;
    case 0xc73:
      if ((param_3 & uVar6) != 0) goto LAB_0007c0f0;
      if (*(undefined **)(param_1 + 0x3250) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x3250));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3250) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x327c) = param_3;
        fVar3 = FLOAT_00108e74;
        if (0 < (int)param_3) {
          do {
            uVar1 = *param_4;
            param_4 = param_4 + 1;
            iVar2 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(float *)(iVar2 + *(int *)(param_1 + 0x3250)) =
                 (GH_U2F((unsigned int)((uVar1 | 0x4b000000))) - 8388608.0) * fVar3;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007c400;
      }
      break;
    case 0xc74:
      if ((param_3 & uVar6) != 0) goto LAB_0007c0f0;
      if (*(undefined **)(param_1 + 0x3254) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x3254));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3254) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x3280) = param_3;
        fVar3 = FLOAT_00108e74;
        if (0 < (int)param_3) {
          do {
            uVar1 = *param_4;
            param_4 = param_4 + 1;
            iVar2 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(float *)(iVar2 + *(int *)(param_1 + 0x3254)) =
                 (GH_U2F((unsigned int)((uVar1 | 0x4b000000))) - 8388608.0) * fVar3;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007c400;
      }
      break;
    case 0xc75:
      if ((param_3 & uVar6) != 0) goto LAB_0007c0f0;
      if (*(undefined **)(param_1 + 0x3258) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x3258));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3258) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x3284) = param_3;
        fVar3 = FLOAT_00108e74;
        if (0 < (int)param_3) {
          do {
            uVar1 = *param_4;
            param_4 = param_4 + 1;
            iVar2 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(float *)(iVar2 + *(int *)(param_1 + 0x3258)) =
                 (GH_U2F((unsigned int)((uVar1 | 0x4b000000))) - 8388608.0) * fVar3;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007c400;
      }
      break;
    case 0xc76:
      if (*(undefined **)(param_1 + 0x325c) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x325c));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x325c) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x3288) = param_3;
        fVar3 = FLOAT_00108e74;
        if (0 < (int)param_3) {
          do {
            uVar1 = *param_4;
            param_4 = param_4 + 1;
            iVar2 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(float *)(iVar2 + *(int *)(param_1 + 0x325c)) =
                 (GH_U2F((unsigned int)((uVar1 | 0x4b000000))) - 8388608.0) * fVar3;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007c400;
      }
      break;
    case 0xc77:
      if (*(undefined **)(param_1 + 0x3260) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x3260));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3260) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x328c) = param_3;
        fVar3 = FLOAT_00108e74;
        if (0 < (int)param_3) {
          do {
            uVar1 = *param_4;
            param_4 = param_4 + 1;
            iVar2 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(float *)(iVar2 + *(int *)(param_1 + 0x3260)) =
                 (GH_U2F((unsigned int)((uVar1 | 0x4b000000))) - 8388608.0) * fVar3;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007c400;
      }
      break;
    case 0xc78:
      if (*(undefined **)(param_1 + 0x3264) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x3264));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3264) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x3290) = param_3;
        fVar3 = FLOAT_00108e74;
        if (0 < (int)param_3) {
          do {
            uVar1 = *param_4;
            param_4 = param_4 + 1;
            iVar2 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(float *)(iVar2 + *(int *)(param_1 + 0x3264)) =
                 (GH_U2F((unsigned int)((uVar1 | 0x4b000000))) - 8388608.0) * fVar3;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007c400;
      }
      break;
    case 0xc79:
      if (*(undefined **)(param_1 + 0x3268) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(param_1 + 0x3268));
      }
      pvVar5 = _malloc(param_3 << 2);
      *(void **)(param_1 + 0x3268) = pvVar5;
      if (pvVar5 != (void *)0x0) {
        iVar7 = 0;
        *(uint *)(param_1 + 0x3294) = param_3;
        fVar3 = FLOAT_00108e74;
        if (0 < (int)param_3) {
          do {
            uVar1 = *param_4;
            param_4 = param_4 + 1;
            iVar2 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(float *)(iVar2 + *(int *)(param_1 + 0x3268)) =
                 (GH_U2F((unsigned int)((uVar1 | 0x4b000000))) - 8388608.0) * fVar3;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
        goto LAB_0007c400;
      }
      break;
    default:
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x500;
      }
LAB_0007c400:
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x200000;
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar4 = 0x505;
  }
  else {
LAB_0007c0f0:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar4 = 0x501;
  }
LAB_0007c380:
  *(undefined4 *)(param_1 + 0x7574) = uVar4;
  return;
}

/* _glPixelMapusv_CompExec @ 0x7c420 (72 bytes) */
int _glPixelMapusv_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glPixelMapusv_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glPixelMapusv_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glGetPixelMapfv_Exec @ 0x7c468 (932 bytes) */
int _glGetPixelMapfv_Exec(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  double dVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar4 = *(int *)(param_1 + 0x4a68);
    if (iVar4 != 0) {
      switch(param_2) {
      case 0xc70:
        iVar2 = *(int *)(param_1 + 0x3270);
        break;
      case 0xc71:
        iVar2 = *(int *)(param_1 + 0x3274);
        break;
      case 0xc72:
        iVar2 = *(int *)(param_1 + 0x3278);
        break;
      case 0xc73:
        iVar2 = *(int *)(param_1 + 0x327c);
        break;
      case 0xc74:
        iVar2 = *(int *)(param_1 + 0x3280);
        break;
      case 0xc75:
        iVar2 = *(int *)(param_1 + 0x3284);
        break;
      case 0xc76:
        iVar2 = *(int *)(param_1 + 0x3288);
        break;
      case 0xc77:
        iVar2 = *(int *)(param_1 + 0x328c);
        break;
      case 0xc78:
        iVar2 = *(int *)(param_1 + 0x3290);
        break;
      case 0xc79:
        iVar2 = *(int *)(param_1 + 0x3294);
        break;
      default:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar3 = 0x500;
        goto LAB_0007c580;
      }
      if ((*(int *)(iVar4 + 0x38) < (int)(iVar2 * 4 + param_3)) || ((param_3 & 3) != 0))
      goto LAB_0007c570;
      if (*(int *)(iVar4 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(param_1,iVar4 + 0x10);
      }
      param_3 = param_3 + *(int *)(iVar4 + 0x30);
    }
    dVar1 = DOUBLE_00108d58;
    switch(param_2) {
    case 0xc70:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x3270)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *(float *)(iVar2 + param_3) =
               (float)((double)CONCAT44(0x43300000,
                                        *(uint *)(iVar2 + *(int *)(param_1 + 0x3248)) ^ 0x80000000)
                      - dVar1);
        } while (iVar4 < *(int *)(param_1 + 0x3270));
      }
      break;
    case 0xc71:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x3274)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *(float *)(iVar2 + param_3) =
               (float)((double)CONCAT44(0x43300000,
                                        *(uint *)(iVar2 + *(int *)(param_1 + 0x326c)) ^ 0x80000000)
                      - dVar1);
        } while (iVar4 < *(int *)(param_1 + 0x3274));
      }
      break;
    case 0xc72:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x3278)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *(undefined4 *)(iVar2 + param_3) = *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x324c));
        } while (iVar4 < *(int *)(param_1 + 0x3278));
      }
      break;
    case 0xc73:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x327c)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *(undefined4 *)(iVar2 + param_3) = *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x3250));
        } while (iVar4 < *(int *)(param_1 + 0x327c));
      }
      break;
    case 0xc74:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x3280)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *(undefined4 *)(iVar2 + param_3) = *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x3254));
        } while (iVar4 < *(int *)(param_1 + 0x3280));
      }
      break;
    case 0xc75:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x3284)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *(undefined4 *)(iVar2 + param_3) = *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x3258));
        } while (iVar4 < *(int *)(param_1 + 0x3284));
      }
      break;
    case 0xc76:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x3288)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *(undefined4 *)(iVar2 + param_3) = *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x325c));
        } while (iVar4 < *(int *)(param_1 + 0x3288));
      }
      break;
    case 0xc77:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x328c)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *(undefined4 *)(iVar2 + param_3) = *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x3260));
        } while (iVar4 < *(int *)(param_1 + 0x328c));
      }
      break;
    case 0xc78:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x3290)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *(undefined4 *)(iVar2 + param_3) = *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x3264));
        } while (iVar4 < *(int *)(param_1 + 0x3290));
      }
      break;
    case 0xc79:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x3294)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *(undefined4 *)(iVar2 + param_3) = *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x3268));
        } while (iVar4 < *(int *)(param_1 + 0x3294));
      }
    }
  }
  else {
LAB_0007c570:
    if (*(int *)(param_1 + 0x7574) == 0) {
      uVar3 = 0x502;
LAB_0007c580:
      *(undefined4 *)(param_1 + 0x7574) = uVar3;
    }
  }
  return;
}

/* _glGetPixelMapuiv_Exec @ 0x7c85c (1436 bytes) */
int _glGetPixelMapuiv_Exec(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  double dVar1;
  double dVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  double dVar7;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar6 = *(int *)(param_1 + 0x4a68);
    if (iVar6 != 0) {
      switch(param_2) {
      case 0xc70:
        iVar3 = *(int *)(param_1 + 0x3270);
        break;
      case 0xc71:
        iVar3 = *(int *)(param_1 + 0x3274);
        break;
      case 0xc72:
        iVar3 = *(int *)(param_1 + 0x3278);
        break;
      case 0xc73:
        iVar3 = *(int *)(param_1 + 0x327c);
        break;
      case 0xc74:
        iVar3 = *(int *)(param_1 + 0x3280);
        break;
      case 0xc75:
        iVar3 = *(int *)(param_1 + 0x3284);
        break;
      case 0xc76:
        iVar3 = *(int *)(param_1 + 0x3288);
        break;
      case 0xc77:
        iVar3 = *(int *)(param_1 + 0x328c);
        break;
      case 0xc78:
        iVar3 = *(int *)(param_1 + 0x3290);
        break;
      case 0xc79:
        iVar3 = *(int *)(param_1 + 0x3294);
        break;
      default:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar4 = 0x500;
        goto LAB_0007c974;
      }
      if ((*(int *)(iVar6 + 0x38) < (int)(iVar3 * 4 + param_3)) || ((param_3 & 3) != 0))
      goto LAB_0007c964;
      if (*(int *)(iVar6 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(param_1,iVar6 + 0x10);
      }
      param_3 = param_3 + *(int *)(iVar6 + 0x30);
    }
    dVar2 = DOUBLE_00108da8;
    dVar1 = DOUBLE_00108d80;
    switch(param_2) {
    case 0xc70:
      iVar6 = 0;
      if (0 < *(int *)(param_1 + 0x3270)) {
        do {
          iVar3 = iVar6 * 4;
          iVar6 = iVar6 + 1;
          *(undefined4 *)(iVar3 + param_3) = *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x3248));
        } while (iVar6 < *(int *)(param_1 + 0x3270));
      }
      break;
    case 0xc71:
      iVar6 = 0;
      if (0 < *(int *)(param_1 + 0x3274)) {
        do {
          iVar3 = iVar6 * 4;
          iVar6 = iVar6 + 1;
          *(undefined4 *)(iVar3 + param_3) = *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x326c));
        } while (iVar6 < *(int *)(param_1 + 0x3274));
      }
      break;
    case 0xc72:
      iVar6 = 0;
      if (0 < *(int *)(param_1 + 0x3278)) {
        iVar3 = 0;
        do {
          dVar7 = (double)*(float *)(iVar3 + *(int *)(param_1 + 0x324c)) * dVar2;
          if (dVar1 <= dVar7) {
            uVar5 = (int)(dVar7 - dVar1) ^ 0x80000000;
          }
          else {
            uVar5 = (uint)(int)dVar7;
          }
          *(uint *)(iVar3 + param_3) = uVar5;
          iVar6 = iVar6 + 1;
          iVar3 = iVar3 + 4;
        } while (iVar6 < *(int *)(param_1 + 0x3278));
      }
      break;
    case 0xc73:
      iVar6 = 0;
      if (0 < *(int *)(param_1 + 0x327c)) {
        iVar3 = 0;
        do {
          dVar7 = (double)*(float *)(iVar3 + *(int *)(param_1 + 0x3250)) * dVar2;
          if (dVar1 <= dVar7) {
            uVar5 = (int)(dVar7 - dVar1) ^ 0x80000000;
          }
          else {
            uVar5 = (uint)(int)dVar7;
          }
          *(uint *)(iVar3 + param_3) = uVar5;
          iVar6 = iVar6 + 1;
          iVar3 = iVar3 + 4;
        } while (iVar6 < *(int *)(param_1 + 0x327c));
      }
      break;
    case 0xc74:
      iVar6 = 0;
      if (0 < *(int *)(param_1 + 0x3280)) {
        iVar3 = 0;
        do {
          dVar7 = (double)*(float *)(iVar3 + *(int *)(param_1 + 0x3254)) * dVar2;
          if (dVar1 <= dVar7) {
            uVar5 = (int)(dVar7 - dVar1) ^ 0x80000000;
          }
          else {
            uVar5 = (uint)(int)dVar7;
          }
          *(uint *)(iVar3 + param_3) = uVar5;
          iVar6 = iVar6 + 1;
          iVar3 = iVar3 + 4;
        } while (iVar6 < *(int *)(param_1 + 0x3280));
      }
      break;
    case 0xc75:
      iVar6 = 0;
      if (0 < *(int *)(param_1 + 0x3284)) {
        iVar3 = 0;
        do {
          dVar7 = (double)*(float *)(iVar3 + *(int *)(param_1 + 0x3258)) * dVar2;
          if (dVar1 <= dVar7) {
            uVar5 = (int)(dVar7 - dVar1) ^ 0x80000000;
          }
          else {
            uVar5 = (uint)(int)dVar7;
          }
          *(uint *)(iVar3 + param_3) = uVar5;
          iVar6 = iVar6 + 1;
          iVar3 = iVar3 + 4;
        } while (iVar6 < *(int *)(param_1 + 0x3284));
      }
      break;
    case 0xc76:
      iVar6 = 0;
      if (0 < *(int *)(param_1 + 0x3288)) {
        iVar3 = 0;
        do {
          dVar7 = (double)*(float *)(iVar3 + *(int *)(param_1 + 0x325c)) * dVar2;
          if (dVar1 <= dVar7) {
            uVar5 = (int)(dVar7 - dVar1) ^ 0x80000000;
          }
          else {
            uVar5 = (uint)(int)dVar7;
          }
          *(uint *)(iVar3 + param_3) = uVar5;
          iVar6 = iVar6 + 1;
          iVar3 = iVar3 + 4;
        } while (iVar6 < *(int *)(param_1 + 0x3288));
      }
      break;
    case 0xc77:
      iVar6 = 0;
      if (0 < *(int *)(param_1 + 0x328c)) {
        iVar3 = 0;
        do {
          dVar7 = (double)*(float *)(iVar3 + *(int *)(param_1 + 0x3260)) * dVar2;
          if (dVar1 <= dVar7) {
            uVar5 = (int)(dVar7 - dVar1) ^ 0x80000000;
          }
          else {
            uVar5 = (uint)(int)dVar7;
          }
          *(uint *)(iVar3 + param_3) = uVar5;
          iVar6 = iVar6 + 1;
          iVar3 = iVar3 + 4;
        } while (iVar6 < *(int *)(param_1 + 0x328c));
      }
      break;
    case 0xc78:
      iVar6 = 0;
      if (0 < *(int *)(param_1 + 0x3290)) {
        iVar3 = 0;
        do {
          dVar7 = (double)*(float *)(iVar3 + *(int *)(param_1 + 0x3264)) * dVar2;
          if (dVar1 <= dVar7) {
            uVar5 = (int)(dVar7 - dVar1) ^ 0x80000000;
          }
          else {
            uVar5 = (uint)(int)dVar7;
          }
          *(uint *)(iVar3 + param_3) = uVar5;
          iVar6 = iVar6 + 1;
          iVar3 = iVar3 + 4;
        } while (iVar6 < *(int *)(param_1 + 0x3290));
      }
      break;
    case 0xc79:
      iVar6 = 0;
      if (0 < *(int *)(param_1 + 0x3294)) {
        iVar3 = 0;
        do {
          dVar7 = (double)*(float *)(iVar3 + *(int *)(param_1 + 0x3268)) * dVar2;
          if (dVar1 <= dVar7) {
            uVar5 = (int)(dVar7 - dVar1) ^ 0x80000000;
          }
          else {
            uVar5 = (uint)(int)dVar7;
          }
          *(uint *)(iVar3 + param_3) = uVar5;
          iVar6 = iVar6 + 1;
          iVar3 = iVar3 + 4;
        } while (iVar6 < *(int *)(param_1 + 0x3294));
      }
    }
  }
  else {
LAB_0007c964:
    if (*(int *)(param_1 + 0x7574) == 0) {
      uVar4 = 0x502;
LAB_0007c974:
      *(undefined4 *)(param_1 + 0x7574) = uVar4;
    }
  }
  return;
}

/* _glGetPixelMapusv_Exec @ 0x7ce48 (1136 bytes) */
int _glGetPixelMapusv_Exec(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined2 *param_3;
{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar4 = *(int *)(param_1 + 0x4a68);
    if (iVar4 != 0) {
      switch(param_2) {
      case 0xc70:
        iVar2 = *(int *)(param_1 + 0x3270);
        break;
      case 0xc71:
        iVar2 = *(int *)(param_1 + 0x3274);
        break;
      case 0xc72:
        iVar2 = *(int *)(param_1 + 0x3278);
        break;
      case 0xc73:
        iVar2 = *(int *)(param_1 + 0x327c);
        break;
      case 0xc74:
        iVar2 = *(int *)(param_1 + 0x3280);
        break;
      case 0xc75:
        iVar2 = *(int *)(param_1 + 0x3284);
        break;
      case 0xc76:
        iVar2 = *(int *)(param_1 + 0x3288);
        break;
      case 0xc77:
        iVar2 = *(int *)(param_1 + 0x328c);
        break;
      case 0xc78:
        iVar2 = *(int *)(param_1 + 0x3290);
        break;
      case 0xc79:
        iVar2 = *(int *)(param_1 + 0x3294);
        break;
      default:
        goto switchD_0007cea8_default;
      }
      if ((*(int *)(iVar4 + 0x38) < (int)(param_3 + iVar2)) || (((uint)param_3 & 1) != 0))
      goto LAB_0007cf38;
      if (*(int *)(iVar4 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(param_1,iVar4 + 0x10);
      }
      param_3 = (undefined2 *)((int)param_3 + *(int *)(iVar4 + 0x30));
    }
    fVar1 = FLOAT_00108ea0;
    switch(param_2) {
    case 0xc70:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x3270)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *param_3 = *(undefined2 *)(iVar2 + *(int *)(param_1 + 0x3248) + 2);
          param_3 = param_3 + 1;
        } while (iVar4 < *(int *)(param_1 + 0x3270));
      }
      break;
    case 0xc71:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x3274)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *param_3 = *(undefined2 *)(iVar2 + *(int *)(param_1 + 0x326c) + 2);
          param_3 = param_3 + 1;
        } while (iVar4 < *(int *)(param_1 + 0x3274));
      }
      break;
    case 0xc72:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x3278)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *param_3 = (short)(int)(*(float *)(iVar2 + *(int *)(param_1 + 0x324c)) * fVar1);
          param_3 = param_3 + 1;
        } while (iVar4 < *(int *)(param_1 + 0x3278));
      }
      break;
    case 0xc73:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x327c)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *param_3 = (short)(int)(*(float *)(iVar2 + *(int *)(param_1 + 0x3250)) * fVar1);
          param_3 = param_3 + 1;
        } while (iVar4 < *(int *)(param_1 + 0x327c));
      }
      break;
    case 0xc74:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x3280)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *param_3 = (short)(int)(*(float *)(iVar2 + *(int *)(param_1 + 0x3254)) * fVar1);
          param_3 = param_3 + 1;
        } while (iVar4 < *(int *)(param_1 + 0x3280));
      }
      break;
    case 0xc75:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x3284)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *param_3 = (short)(int)(*(float *)(iVar2 + *(int *)(param_1 + 0x3258)) * fVar1);
          param_3 = param_3 + 1;
        } while (iVar4 < *(int *)(param_1 + 0x3284));
      }
      break;
    case 0xc76:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x3288)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *param_3 = (short)(int)(*(float *)(iVar2 + *(int *)(param_1 + 0x325c)) * fVar1);
          param_3 = param_3 + 1;
        } while (iVar4 < *(int *)(param_1 + 0x3288));
      }
      break;
    case 0xc77:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x328c)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *param_3 = (short)(int)(*(float *)(iVar2 + *(int *)(param_1 + 0x3260)) * fVar1);
          param_3 = param_3 + 1;
        } while (iVar4 < *(int *)(param_1 + 0x328c));
      }
      break;
    case 0xc78:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x3290)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *param_3 = (short)(int)(*(float *)(iVar2 + *(int *)(param_1 + 0x3264)) * fVar1);
          param_3 = param_3 + 1;
        } while (iVar4 < *(int *)(param_1 + 0x3290));
      }
      break;
    case 0xc79:
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x3294)) {
        do {
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *param_3 = (short)(int)(*(float *)(iVar2 + *(int *)(param_1 + 0x3268)) * fVar1);
          param_3 = param_3 + 1;
        } while (iVar4 < *(int *)(param_1 + 0x3294));
      }
      break;
    default:
switchD_0007cea8_default:
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar3 = 0x500;
      goto LAB_0007d2f0;
    }
  }
  else {
LAB_0007cf38:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
LAB_0007d2f0:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
  }
  return;
}

/* _glPixelStoref_Exec @ 0x7d308 (1156 bytes) */
void _glPixelStoref_Exec(int param_1,uint param_2,double fparam_1)
{
  undefined4 uVar1;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
    return;
  }
  if (param_2 == 0xd02) {
    if ((double)FLOAT_00108e50 <= fparam_1) {
      *(int *)(param_1 + 0x31b0) = (int)(fparam_1 + (double)FLOAT_00108e90);
      goto LAB_0007d77c;
    }
LAB_0007d734:
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_0007d77c;
    uVar1 = 0x501;
  }
  else {
    if (param_2 < 0xd03) {
      if (param_2 == 0xcf3) {
        if ((double)FLOAT_00108e50 <= fparam_1) {
          *(int *)(param_1 + 0x31d4) = (int)(fparam_1 + (double)FLOAT_00108e90);
          goto LAB_0007d77c;
        }
      }
      else if (param_2 < 0xcf4) {
        if (param_2 == 0xcf1) {
          *(bool *)(param_1 + 0x31e5) = fparam_1 != (double)FLOAT_00108e50;
          goto LAB_0007d77c;
        }
        if (param_2 < 0xcf2) {
          if (param_2 == 0xcf0) {
            *(bool *)(param_1 + 0x31e4) = fparam_1 != (double)FLOAT_00108e50;
            goto LAB_0007d77c;
          }
          goto LAB_0007d768;
        }
        if ((double)FLOAT_00108e50 <= fparam_1) {
          *(int *)(param_1 + 0x31cc) = (int)(fparam_1 + (double)FLOAT_00108e90);
          goto LAB_0007d77c;
        }
      }
      else if (param_2 == 0xcf5) {
        if ((((fparam_1 == (double)FLOAT_00108e54) || (fparam_1 == (double)FLOAT_00108ea4)) ||
            (fparam_1 == (double)FLOAT_00108ea8)) || (fparam_1 == (double)FLOAT_00108eac)) {
          *(int *)(param_1 + 0x31e0) = (int)(fparam_1 + (double)FLOAT_00108e90);
          goto LAB_0007d77c;
        }
      }
      else if (param_2 < 0xcf5) {
        if ((double)FLOAT_00108e50 <= fparam_1) {
          *(int *)(param_1 + 0x31d8) = (int)(fparam_1 + (double)FLOAT_00108e90);
          goto LAB_0007d77c;
        }
      }
      else if (param_2 == 0xd00) {
        if ((double)FLOAT_00108e50 <= fparam_1) {
          *(bool *)(param_1 + 0x31c8) = fparam_1 != (double)FLOAT_00108e50;
          goto LAB_0007d77c;
        }
      }
      else {
        if (param_2 != 0xd01) goto LAB_0007d768;
        if ((double)FLOAT_00108e50 <= fparam_1) {
          *(bool *)(param_1 + 0x31c9) = fparam_1 != (double)FLOAT_00108e50;
          goto LAB_0007d77c;
        }
      }
      goto LAB_0007d734;
    }
    if (param_2 == 0x806b) {
      if ((double)FLOAT_00108e50 <= fparam_1) {
        *(int *)(param_1 + 0x31c0) = (int)(fparam_1 + (double)FLOAT_00108e90);
        goto LAB_0007d77c;
      }
      goto LAB_0007d734;
    }
    if (0x806b < param_2) {
      if (param_2 == 0x806d) {
        if ((double)FLOAT_00108e50 <= fparam_1) {
          *(int *)(param_1 + 0x31dc) = (int)(fparam_1 + (double)FLOAT_00108e90);
          goto LAB_0007d77c;
        }
      }
      else if (param_2 < 0x806d) {
        if ((double)FLOAT_00108e50 <= fparam_1) {
          *(int *)(_gleCreateSharedState + param_1) = (int)(fparam_1 + (double)FLOAT_00108e90);
          goto LAB_0007d77c;
        }
      }
      else {
        if (param_2 != 0x806e) {
          if (param_2 == 0x85b2) {
            *(bool *)(param_1 + 0x31e6) = fparam_1 != (double)FLOAT_00108e50;
            goto LAB_0007d77c;
          }
          goto LAB_0007d768;
        }
        if ((double)FLOAT_00108e50 <= fparam_1) {
          *(int *)(param_1 + 0x31d0) = (int)(fparam_1 + (double)FLOAT_00108e90);
          goto LAB_0007d77c;
        }
      }
      goto LAB_0007d734;
    }
    if (param_2 == 0xd04) {
      if ((double)FLOAT_00108e50 <= fparam_1) {
        *(int *)(param_1 + 0x31bc) = (int)(fparam_1 + (double)FLOAT_00108e90);
        goto LAB_0007d77c;
      }
      goto LAB_0007d734;
    }
    if (param_2 < 0xd04) {
      if ((double)FLOAT_00108e50 <= fparam_1) {
        *(int *)(param_1 + 0x31b8) = (int)(fparam_1 + (double)FLOAT_00108e90);
        goto LAB_0007d77c;
      }
      goto LAB_0007d734;
    }
    if (param_2 == 0xd05) {
      if (((fparam_1 == (double)FLOAT_00108e54) || (fparam_1 == (double)FLOAT_00108ea4)) ||
         ((fparam_1 == (double)FLOAT_00108ea8 || (fparam_1 == (double)FLOAT_00108eac)))) {
        *(int *)(param_1 + 0x31c4) = (int)(fparam_1 + (double)FLOAT_00108e90);
        goto LAB_0007d77c;
      }
      goto LAB_0007d734;
    }
LAB_0007d768:
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_0007d77c;
    uVar1 = 0x500;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
LAB_0007d77c:
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x200000;
  return;
}

/* _glPixelTransferf_ListExec @ 0x7d78c (44 bytes) */
int _glPixelTransferf_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glPixelTransferf_Exec)(param_1,*param_2,(double)GH_U2F((unsigned int)(param_2[1])));
  return 8;
}

/* _glPixelTransferf_Comp @ 0x7d7b8 (92 bytes) */
undefined4 * _glPixelTransferf_Comp(undefined4 param_1,undefined4 param_2,double fparam_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glPixelTransferf_ListExec_00110254,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = (float)fparam_1;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glPixelTransferf_Exec @ 0x7d814 (1740 bytes) */
void _glPixelTransferf_Exec(int param_1,uint param_2,double fparam_1)
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  double dVar4;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
    goto LAB_0007de90;
  }
  if (param_2 == 0x8022) {
    *(float *)(param_1 + 0x33a4) = (float)fparam_1;
    dVar4 = (double)FLOAT_00108e50;
    uVar3 = 0x40000000;
  }
  else {
    if (0x8022 < param_2) {
      if (param_2 == 0x870f) {
        *(float *)(param_1 + 0x3224) = (float)fparam_1;
        dVar4 = (double)FLOAT_00108e54;
        uVar3 = 4;
      }
      else {
        if (param_2 < 0x8710) {
          if (param_2 == 0x80b7) {
            *(float *)(param_1 + 0x3374) = (float)fparam_1;
            dVar4 = (double)FLOAT_00108e54;
            uVar3 = 0x80000;
          }
          else if (param_2 < 0x80b8) {
            if (param_2 == 0x80b4) {
              *(float *)(param_1 + 0x335c) = (float)fparam_1;
              dVar4 = (double)FLOAT_00108e54;
              uVar3 = 0x10000;
            }
            else if (param_2 < 0x80b5) {
              if (param_2 != 0x8023) goto LAB_0007de80;
              *(float *)(param_1 + 0x33ac) = (float)fparam_1;
              dVar4 = (double)FLOAT_00108e50;
              uVar3 = 0x80000000;
            }
            else if (param_2 == 0x80b5) {
              *(float *)(param_1 + 0x336c) = (float)fparam_1;
              dVar4 = (double)FLOAT_00108e54;
              uVar3 = 0x20000;
            }
            else {
              if (param_2 != 0x80b6) goto LAB_0007de80;
              *(float *)(param_1 + 0x3364) = (float)fparam_1;
              dVar4 = (double)FLOAT_00108e54;
              uVar3 = 0x40000;
            }
          }
          else if (param_2 == 0x80ba) {
            *(float *)(param_1 + 0x3370) = (float)fparam_1;
            dVar4 = (double)FLOAT_00108e50;
            uVar3 = 0x400000;
          }
          else if (param_2 < 0x80bb) {
            if (param_2 == 0x80b8) {
              *(float *)(param_1 + 0x3360) = (float)fparam_1;
              dVar4 = (double)FLOAT_00108e50;
              uVar3 = 0x100000;
            }
            else {
              if (param_2 != 0x80b9) goto LAB_0007de80;
              *(float *)(param_1 + 0x3368) = (float)fparam_1;
              dVar4 = (double)FLOAT_00108e50;
              uVar3 = 0x200000;
            }
          }
          else {
            if (param_2 != 0x80bb) {
              if (param_2 == 0x870e) {
                *(float *)(param_1 + 0x321c) = (float)fparam_1;
                dVar4 = (double)FLOAT_00108e54;
                uVar3 = 1;
                goto LAB_0007deb8;
              }
              goto LAB_0007de80;
            }
            *(float *)(param_1 + 0x3378) = (float)fparam_1;
            dVar4 = (double)FLOAT_00108e50;
            uVar3 = 0x800000;
          }
          goto LAB_0007de98;
        }
        if (param_2 == 0x8714) {
          *(float *)(param_1 + 0x3218) = (float)fparam_1;
          dVar4 = (double)FLOAT_00108e50;
          uVar3 = 2;
        }
        else if (param_2 < 0x8715) {
          if (param_2 == 0x8711) {
            *(float *)(param_1 + 0x3234) = (float)fparam_1;
            dVar4 = (double)FLOAT_00108e54;
            uVar3 = 0x40;
          }
          else if (param_2 < 0x8711) {
            *(float *)(param_1 + 0x322c) = (float)fparam_1;
            dVar4 = (double)FLOAT_00108e54;
            uVar3 = 0x10;
          }
          else if (param_2 == 0x8712) {
            *(float *)(param_1 + 0x323c) = (float)fparam_1;
            dVar4 = (double)FLOAT_00108e54;
            uVar3 = 0x100;
          }
          else {
            if (param_2 != 0x8713) goto LAB_0007de80;
            *(float *)(param_1 + 0x3244) = (float)fparam_1;
            dVar4 = (double)FLOAT_00108e54;
            uVar3 = 0x400;
          }
        }
        else if (param_2 == 0x8717) {
          *(float *)(param_1 + 0x3230) = (float)fparam_1;
          dVar4 = (double)FLOAT_00108e50;
          uVar3 = 0x80;
        }
        else if (param_2 < 0x8718) {
          if (param_2 == 0x8715) {
            *(float *)(param_1 + 0x3220) = (float)fparam_1;
            dVar4 = (double)FLOAT_00108e50;
            uVar3 = 8;
          }
          else {
            if (param_2 != 0x8716) goto LAB_0007de80;
            *(float *)(param_1 + 0x3228) = (float)fparam_1;
            dVar4 = (double)FLOAT_00108e50;
            uVar3 = 0x20;
          }
        }
        else if (param_2 == 0x8718) {
          *(float *)(param_1 + 0x3238) = (float)fparam_1;
          dVar4 = (double)FLOAT_00108e50;
          uVar3 = 0x200;
        }
        else {
          if (param_2 != 0x8719) goto LAB_0007de80;
          *(float *)(param_1 + 0x3240) = (float)fparam_1;
          dVar4 = (double)FLOAT_00108e50;
          uVar3 = 0x800;
        }
      }
LAB_0007deb8:
      uVar2 = *(uint *)(param_1 + 0x3418) & ~uVar3;
      if (fparam_1 != dVar4) {
        uVar2 = uVar2 | uVar3;
      }
      *(uint *)(param_1 + 0x3418) = uVar2;
      goto LAB_0007ded0;
    }
    if (param_2 == 0xd1b) {
      *(float *)(param_1 + 0x31f8) = (float)fparam_1;
      dVar4 = (double)FLOAT_00108e50;
      uVar3 = 0x400;
    }
    else if (param_2 < 0xd1c) {
      if (param_2 == 0xd14) {
        *(float *)(param_1 + 0x31ec) = (float)fparam_1;
        dVar4 = (double)FLOAT_00108e54;
        uVar3 = 0x10;
      }
      else if (param_2 < 0xd15) {
        if (param_2 == 0xd11) {
          dVar4 = (double)FLOAT_00108e50;
          uVar3 = 2;
        }
        else if (param_2 < 0xd12) {
          if (param_2 != 0xd10) {
LAB_0007de80:
            if (*(int *)(param_1 + 0x7574) != 0) {
              return;
            }
            uVar1 = 0x500;
LAB_0007de90:
            *(undefined4 *)(param_1 + 0x7574) = uVar1;
            return;
          }
          dVar4 = (double)FLOAT_00108e50;
          uVar3 = 1;
        }
        else if (param_2 == 0xd12) {
          dVar4 = (double)FLOAT_00108e50;
          uVar3 = 4;
          *(int *)(param_1 + 0x3214) = (int)(fparam_1 + (double)FLOAT_00108e90);
        }
        else {
          if (param_2 != 0xd13) goto LAB_0007de80;
          dVar4 = (double)FLOAT_00108e50;
          uVar3 = 8;
          *(int *)(param_1 + 0x3210) = (int)(fparam_1 + (double)FLOAT_00108e90);
        }
      }
      else if (param_2 == 0xd18) {
        *(float *)(param_1 + 0x31f4) = (float)fparam_1;
        dVar4 = (double)FLOAT_00108e54;
        uVar3 = 0x20;
      }
      else if (param_2 < 0xd19) {
        if (param_2 != 0xd15) goto LAB_0007de80;
        *(float *)(param_1 + 0x31e8) = (float)fparam_1;
        dVar4 = (double)FLOAT_00108e50;
        uVar3 = 0x100;
      }
      else if (param_2 == 0xd19) {
        *(float *)(param_1 + 0x31f0) = (float)fparam_1;
        dVar4 = (double)FLOAT_00108e50;
        uVar3 = 0x200;
      }
      else {
        if (param_2 != 0xd1a) goto LAB_0007de80;
        *(float *)(param_1 + 0x31fc) = (float)fparam_1;
        dVar4 = (double)FLOAT_00108e54;
        uVar3 = 0x40;
      }
    }
    else if (param_2 == 0x801c) {
      *(float *)(param_1 + 0x3390) = (float)fparam_1;
      dVar4 = (double)FLOAT_00108e54;
      uVar3 = 0x1000000;
    }
    else if (param_2 < 0x801d) {
      if (param_2 == 0xd1d) {
        *(float *)(param_1 + 0x3200) = (float)fparam_1;
        dVar4 = (double)FLOAT_00108e50;
        uVar3 = 0x800;
      }
      else if (param_2 < 0xd1d) {
        *(float *)(param_1 + 0x3204) = (float)fparam_1;
        dVar4 = (double)FLOAT_00108e54;
        uVar3 = 0x80;
      }
      else if (param_2 == 0xd1e) {
        *(float *)(param_1 + 0x320c) = (float)fparam_1;
        dVar4 = (double)FLOAT_00108e54;
        uVar3 = 0x1000;
      }
      else {
        if (param_2 != 0xd1f) goto LAB_0007de80;
        *(float *)(param_1 + 0x3208) = (float)fparam_1;
        dVar4 = (double)FLOAT_00108e50;
        uVar3 = 0x2000;
      }
    }
    else if (param_2 == 0x801f) {
      *(float *)(param_1 + 0x33a8) = (float)fparam_1;
      dVar4 = (double)FLOAT_00108e54;
      uVar3 = 0x8000000;
    }
    else if (param_2 < 0x8020) {
      if (param_2 == 0x801d) {
        *(float *)(param_1 + 0x33a0) = (float)fparam_1;
        dVar4 = (double)FLOAT_00108e54;
        uVar3 = 0x2000000;
      }
      else {
        if (param_2 != 0x801e) goto LAB_0007de80;
        *(float *)(param_1 + 0x3398) = (float)fparam_1;
        dVar4 = (double)FLOAT_00108e54;
        uVar3 = 0x4000000;
      }
    }
    else if (param_2 == 0x8020) {
      *(float *)(param_1 + 0x3394) = (float)fparam_1;
      dVar4 = (double)FLOAT_00108e50;
      uVar3 = 0x10000000;
    }
    else {
      if (param_2 != 0x8021) goto LAB_0007de80;
      *(float *)(param_1 + 0x339c) = (float)fparam_1;
      dVar4 = (double)FLOAT_00108e50;
      uVar3 = 0x20000000;
    }
  }
LAB_0007de98:
  uVar2 = *(uint *)(param_1 + 0x3414) & ~uVar3;
  if (fparam_1 != dVar4) {
    uVar2 = uVar2 | uVar3;
  }
  *(uint *)(param_1 + 0x3414) = uVar2;
LAB_0007ded0:
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x200000;
  return;
}

/* _glPixelTransferf_CompExec @ 0x7dee0 (72 bytes) */
void _glPixelTransferf_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1)
{
  ((undefined4 * (*)())_glPixelTransferf_Comp)(param_1,param_2,fparam_1);
  ((void (*)())_glPixelTransferf_Exec)(param_1,param_2,fparam_1);
  return;
}

/* _glPixelTransferi_ListExec @ 0x7df28 (44 bytes) */
int _glPixelTransferi_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glPixelTransferi_Exec(param_1,*param_2,param_2[1]);
  return 8;
}

/* _glPixelTransferi_Comp @ 0x7df54 (84 bytes) */
int _glPixelTransferi_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glPixelTransferi_ListExec_00110250,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

