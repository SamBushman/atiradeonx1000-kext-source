#include "decls.h"

/* _glEvalCoord2dv_Exec @ 0x64bcc (20 bytes) */
void _glEvalCoord2dv_Exec(undefined4 param_1,double *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  ((void (*)())_gleEvalMap2)(param_1,(double)GH_U2F((unsigned int)(*param_2)),(double)GH_U2F((unsigned int)(param_2[1])),fparam_3,fparam_4,fparam_5,
               fparam_6,fparam_7,fparam_8,fparam_9,fparam_10,fparam_11,fparam_12);
  return;
}

/* _glEvalCoord2dv_CompExec @ 0x64be0 (56 bytes) */
int _glEvalCoord2dv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  unsigned int ghidra_home[8] = { param_1, param_2, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  _glEvalCoord2dv_Comp(param_1,param_2);
  ((void (*)())_glEvalCoord2dv_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)((unsigned char *)ghidra_home + 0)),
             (*(double *)((unsigned char *)ghidra_home + 8)));
  return;
}

/* FUN_00064c1c @ 0x64c1c (48 bytes) */
undefined4 FUN_00064c1c(undefined4 param_1,double *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  double in_stack_ffffffd0;
  
  ((void (*)())_gleEvalMap2)(param_1,(double)GH_U2F((unsigned int)(*param_2)),(double)(float)fparam_2,fparam_3,fparam_4,fparam_5,
               fparam_6,fparam_7,fparam_8,in_stack_ffffffb8,in_stack_ffffffc0,in_stack_ffffffc8,
               in_stack_ffffffd0);
  return 0x10;
}

/* _glEvalCoord2f_Comp @ 0x64c4c (100 bytes) */
double * _glEvalCoord2f_Comp(undefined4 param_1,double fparam_1,double fparam_2)
{
  double *pdVar1;
  
  pdVar1 = (double *)_gleAddListItem(param_1,PTR__glEvalCoord2f_ListExec_001100c4,0x10);
  if (pdVar1 != (double *)0x0) {
    *pdVar1 = fparam_1;
    pdVar1[1] = fparam_2;
  }
  return pdVar1;
}

/* _glEvalCoord2f_CompExec @ 0x64cb4 (84 bytes) */
void _glEvalCoord2f_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  undefined4 in_LR;
  
  ((double * (*)())_glEvalCoord2f_Comp)(param_1,fparam_1,fparam_2);
  ((void (*)())_gleEvalMap2)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
               (double)CONCAT44(in_LR,(*(unsigned int *)((unsigned char *)&(fparam_9) + 4))),fparam_10,fparam_11,fparam_12);
  return;
}

/* _glEvalCoord2fv_Comp @ 0x64d04 (88 bytes) */
int _glEvalCoord2fv_Comp(param_1, param_2)
  undefined4 param_1;
  float *param_2;
{
  double *pdVar1;
  
  pdVar1 = (double *)_gleAddListItem(param_1,PTR__glEvalCoord2f_ListExec_001100c4,0x10);
  if (pdVar1 != (double *)0x0) {
    *pdVar1 = (double)*param_2;
    pdVar1[1] = (double)param_2[1];
  }
  return pdVar1;
}

/* _glEvalCoord2fv_Exec @ 0x64d5c (12 bytes) */
void _glEvalCoord2fv_Exec(undefined4 param_1,float *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  ((void (*)())_gleEvalMap2)(param_1,(double)*param_2,(double)param_2[1],fparam_3,fparam_4,fparam_5,fparam_6,
               fparam_7,fparam_8,fparam_9,fparam_10,fparam_11,fparam_12);
  return;
}

/* _glEvalCoord2fv_CompExec @ 0x64d68 (56 bytes) */
int _glEvalCoord2fv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  unsigned int ghidra_home[8] = { param_1, param_2, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glEvalCoord2fv_Comp)(param_1,param_2);
  ((void (*)())_glEvalCoord2fv_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)((unsigned char *)ghidra_home + 0)),
             (*(double *)((unsigned char *)ghidra_home + 8)));
  return;
}

/* _glEvalMesh1_ListExec @ 0x64da0 (52 bytes) */
undefined4 _glEvalMesh1_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_glEvalMesh1_Exec)(param_1,*param_2,param_2[1],param_2[2],fparam_1,fparam_2,fparam_3,fparam_4,
                    fparam_5,fparam_6,fparam_7,fparam_8);
  return 0xc;
}

/* _glEvalMesh1_Comp @ 0x64dd4 (92 bytes) */
int _glEvalMesh1_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glEvalMesh1_ListExec_001100d0,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = param_4;
    *puVar1 = param_2;
    puVar1[1] = param_3;
  }
  return puVar1;
}

/* _glEvalMesh1_Exec @ 0x64e30 (296 bytes) */
void _glEvalMesh1_Exec(int param_1,int param_2,uint param_3,int param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  undefined4 uVar5;
  double dVar6;
  double fparam_1_00;
  double dVar7;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x1b00) {
      uVar5 = 0;
    }
    else {
      if (param_2 != 0x1b01) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar5 = 0x500;
        goto LAB_00064ea8;
      }
      uVar5 = 3;
    }
    ((void (*)())_glBegin_Exec)(param_1,uVar5,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                  fparam_8);
    dVar4 = DOUBLE_00108d58;
    fVar1 = *(float *)(param_1 + 0x74b4);
    dVar7 = (double)CONCAT44(0x43300000,
                             *(uint *)(0x74a4 + param_1 + 4) ^ 0x80000000) -
            DOUBLE_00108d58;
    fVar2 = *(float *)(param_1 + 0x74ac);
    fVar3 = *(float *)(param_1 + 0x74b0);
    for (; (int)param_3 <= param_4; param_3 = param_3 + 1) {
      fparam_1_00 = (double)fVar2;
      if ((param_3 != 0) &&
         (dVar6 = (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar4),
         fparam_1_00 = (double)fVar3, dVar6 != (double)(float)dVar7)) {
        fparam_1_00 = (double)(float)(dVar6 * (double)fVar1 + (double)fVar2);
      }
      ((void (*)())_gleEvalMap1)(param_1,fparam_1_00);
    }
    _glEnd_Exec(param_1);
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar5 = 0x502;
LAB_00064ea8:
    *(undefined4 *)(param_1 + 0x7574) = uVar5;
  }
  return;
}

/* _glEvalMesh1_CompExec @ 0x64f58 (72 bytes) */
int _glEvalMesh1_CompExec(param_1, param_2, param_3, param_4)
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
  
  ((int (*)())_glEvalMesh1_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glEvalMesh1_Exec)(param_1,param_2,param_3,param_4,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,
                    in_f8);
  return;
}

/* _glEvalMesh2_ListExec @ 0x64fa0 (60 bytes) */
undefined4 _glEvalMesh2_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_glEvalMesh2_Exec)(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],fparam_1,fparam_2,
                    fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return 0x14;
}

/* _glEvalMesh2_Comp @ 0x64fdc (108 bytes) */
int _glEvalMesh2_Comp(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glEvalMesh2_ListExec_001100cc,0x14);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[4] = param_6;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
    puVar1[3] = param_5;
  }
  return puVar1;
}

/* _glEvalMesh2_Exec @ 0x65048 (1248 bytes) */
void _glEvalMesh2_Exec(int param_1,uint param_2,uint param_3,int param_4,uint param_5,int param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double fparam_1_00;
  double in_stack_ffffff48;
  double in_stack_ffffff50;
  double in_stack_ffffff58;
  double in_stack_ffffff60;
  
  dVar11 = DOUBLE_00108d58;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    puVar5 = (uint *)(param_1 + 0x74b8);
    fVar2 = *(float *)(param_1 + 0x74c4);
    fVar3 = *(float *)(param_1 + 0x74d4);
    if (param_2 == 0x1b01) {
      bVar1 = (int)param_5 <= param_6;
      uVar7 = param_5;
      dVar8 = DOUBLE_00108d58;
      while (DOUBLE_00108d58 = dVar8, bVar1) {
        if (uVar7 == 0) {
          dVar8 = (double)*(float *)(param_1 + 0x74cc);
        }
        else if (uVar7 == *(uint *)(param_1 + 0x74c8)) {
          dVar8 = (double)*(float *)(param_1 + 0x74d0);
        }
        else {
          dVar8 = (double)((float)((double)CONCAT44(0x43300000,uVar7 ^ 0x80000000) - dVar11) * fVar3
                          + *(float *)(param_1 + 0x74cc));
        }
        ((void (*)())_glBegin_Exec)(param_1,3,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                      fparam_8);
        dVar9 = DOUBLE_00108d58;
        for (uVar6 = param_3; (int)uVar6 <= param_4; uVar6 = uVar6 + 1) {
          if (uVar6 == 0) {
            dVar10 = (double)*(float *)(param_1 + 0x74bc);
          }
          else if (uVar6 == *puVar5) {
            dVar10 = (double)*(float *)(param_1 + 0x74c0);
          }
          else {
            dVar10 = (double)((float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) - dVar9) *
                              fVar2 + *(float *)(param_1 + 0x74bc));
          }
          fparam_2 = dVar8;
          ((void (*)())_gleEvalMap2)(param_1,dVar10,dVar8,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
                       in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58,in_stack_ffffff60);
        }
        uVar7 = uVar7 + 1;
        fparam_1 = (double)_glEnd_Exec(param_1);
        bVar1 = (int)uVar7 <= param_6;
        dVar8 = DOUBLE_00108d58;
      }
      for (; (int)param_3 <= param_4; param_3 = param_3 + 1) {
        if (param_3 == 0) {
          dVar11 = (double)*(float *)(param_1 + 0x74bc);
        }
        else if (param_3 == *puVar5) {
          dVar11 = (double)*(float *)(param_1 + 0x74c0);
        }
        else {
          dVar11 = (double)((float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar8) *
                            fVar2 + *(float *)(param_1 + 0x74bc));
        }
        ((void (*)())_glBegin_Exec)(param_1,3,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                      fparam_8);
        dVar9 = DOUBLE_00108d58;
        bVar1 = (int)param_5 <= param_6;
        uVar7 = param_5;
        while (bVar1) {
          if (uVar7 == 0) {
            fparam_2 = (double)*(float *)(param_1 + 0x74cc);
          }
          else if (uVar7 == *(uint *)(param_1 + 0x74c8)) {
            fparam_2 = (double)*(float *)(param_1 + 0x74d0);
          }
          else {
            fparam_2 = (double)((float)((double)CONCAT44(0x43300000,uVar7 ^ 0x80000000) - dVar9) *
                                fVar3 + *(float *)(param_1 + 0x74cc));
          }
          uVar7 = uVar7 + 1;
          ((void (*)())_gleEvalMap2)(param_1,dVar11,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8
                       ,in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58,in_stack_ffffff60);
          bVar1 = (int)uVar7 <= param_6;
        }
        fparam_1 = (double)_glEnd_Exec(param_1);
      }
      return;
    }
    if (param_2 < 0x1b02) {
      if (param_2 == 0x1b00) {
        ((void (*)())_glBegin_Exec)(param_1,0,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                      fparam_8);
        dVar8 = DOUBLE_00108d58;
        dVar11 = DOUBLE_00108d58;
        for (; DOUBLE_00108d58 = dVar11, (int)param_5 <= param_6; param_5 = param_5 + 1) {
          uVar7 = param_3;
          if (param_5 == 0) {
            dVar9 = (double)*(float *)(param_1 + 0x74cc);
          }
          else if (param_5 == *(uint *)(param_1 + 0x74c8)) {
            dVar9 = (double)*(float *)(param_1 + 0x74d0);
          }
          else {
            dVar9 = (double)((float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - dVar8) *
                             fVar3 + *(float *)(param_1 + 0x74cc));
          }
          for (; (int)uVar7 <= param_4; uVar7 = uVar7 + 1) {
            if (uVar7 == 0) {
              dVar10 = (double)*(float *)(param_1 + 0x74bc);
            }
            else if (uVar7 == *puVar5) {
              dVar10 = (double)*(float *)(param_1 + 0x74c0);
            }
            else {
              dVar10 = (double)((float)((double)CONCAT44(0x43300000,uVar7 ^ 0x80000000) - dVar11) *
                                fVar2 + *(float *)(param_1 + 0x74bc));
            }
            ((void (*)())_gleEvalMap2)(param_1,dVar10,dVar9,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
                         in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58,in_stack_ffffff60);
          }
          dVar11 = DOUBLE_00108d58;
        }
        _glEnd_Exec(param_1);
        return;
      }
    }
    else if (param_2 == 0x1b02) {
      while ((int)param_5 < param_6) {
        if (param_5 == 0) {
          dVar8 = (double)*(float *)(param_1 + 0x74cc);
        }
        else if (param_5 == *(uint *)(param_1 + 0x74c8)) {
          dVar8 = (double)*(float *)(param_1 + 0x74d0);
        }
        else {
          dVar8 = (double)((float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - dVar11) *
                           fVar3 + *(float *)(param_1 + 0x74cc));
        }
        if (param_5 == 0xffffffff) {
          dVar9 = (double)*(float *)(param_1 + 0x74cc);
          param_5 = 0;
        }
        else {
          param_5 = param_5 + 1;
          if (param_5 == *(uint *)(param_1 + 0x74c8)) {
            dVar9 = (double)*(float *)(param_1 + 0x74d0);
          }
          else {
            dVar9 = (double)((float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - dVar11) *
                             fVar3 + *(float *)(param_1 + 0x74cc));
          }
        }
        ((void (*)())_glBegin_Exec)(param_1,5,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                      fparam_8);
        dVar10 = DOUBLE_00108d58;
        for (uVar7 = param_3; (int)uVar7 <= param_4; uVar7 = uVar7 + 1) {
          if (uVar7 == 0) {
            fparam_1_00 = (double)*(float *)(param_1 + 0x74bc);
          }
          else if (uVar7 == *puVar5) {
            fparam_1_00 = (double)*(float *)(param_1 + 0x74c0);
          }
          else {
            fparam_1_00 = (double)((float)((double)CONCAT44(0x43300000,uVar7 ^ 0x80000000) - dVar10)
                                   * fVar2 + *(float *)(param_1 + 0x74bc));
          }
          ((void (*)())_gleEvalMap2)(param_1,fparam_1_00,dVar8,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                       fparam_8,in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58,
                       in_stack_ffffff60);
          fparam_2 = dVar9;
          ((void (*)())_gleEvalMap2)(param_1,fparam_1_00,dVar9,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                       fparam_8,in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58,
                       in_stack_ffffff60);
        }
        fparam_1 = (double)_glEnd_Exec(param_1);
      }
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar4 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar4 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar4;
  return;
}

/* _glEvalMesh2_CompExec @ 0x65528 (88 bytes) */
int _glEvalMesh2_CompExec(param_1, param_2, param_3, param_4, param_5, param_6)
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
  
  ((int (*)())_glEvalMesh2_Comp)(param_1,param_2,param_3,param_4,param_5,param_6);
  ((void (*)())_glEvalMesh2_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,in_f2,in_f3,in_f4,in_f5
                    ,in_f6,in_f7,in_f8);
  return;
}

/* _glEvalPoint1_ListExec @ 0x65580 (40 bytes) */
undefined4 _glEvalPoint1_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1)
{
  ((void (*)())_glEvalPoint1_Exec)(param_1,*param_2,fparam_1);
  return 4;
}

/* _glEvalPoint1_Comp @ 0x655a8 (76 bytes) */
int _glEvalPoint1_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glEvalPoint1_ListExec_001100d8,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glEvalPoint1_Exec @ 0x655f4 (132 bytes) */
void _glEvalPoint1_Exec(int param_1,uint param_2,double fparam_1)
{
  double fparam_1_00;
  
  if (param_2 == 0) {
    fparam_1_00 = (double)*(float *)(param_1 + 0x74ac);
  }
  else if (param_2 == *(uint *)(0x74a4 + param_1 + 4)) {
    fparam_1_00 = (double)*(float *)(param_1 + 0x74b0);
  }
  else {
    fparam_1_00 = (double)((float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                  DOUBLE_00108d58) * *(float *)(param_1 + 0x74b4) +
                          *(float *)(param_1 + 0x74ac));
  }
  ((void (*)())_gleEvalMap1)(param_1,fparam_1_00);
  return;
}

/* _glEvalPoint1_CompExec @ 0x65678 (56 bytes) */
int _glEvalPoint1_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  double fparam_1;
  
  ((int (*)())_glEvalPoint1_Comp)(param_1,param_2);
  ((void (*)())_glEvalPoint1_Exec)(param_1,param_2,fparam_1);
  return;
}

/* _glEvalPoint2_ListExec @ 0x656b0 (44 bytes) */
undefined4 _glEvalPoint2_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  double in_stack_ffffffd0;
  
  ((void (*)())_glEvalPoint2_Exec)(param_1,*param_2,param_2[1],fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                     fparam_6,fparam_7,fparam_8,in_stack_ffffffb8,in_stack_ffffffc0,
                     in_stack_ffffffc8,in_stack_ffffffd0);
  return 8;
}

/* _glEvalPoint2_Comp @ 0x656dc (84 bytes) */
int _glEvalPoint2_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glEvalPoint2_ListExec_001100d4,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glEvalPoint2_Exec @ 0x65730 (216 bytes) */
void _glEvalPoint2_Exec(int param_1,uint param_2,uint param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  double fparam_1_00;
  double fparam_2_00;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  
  if (param_2 == 0) {
    fparam_1_00 = (double)*(float *)(param_1 + 0x74bc);
  }
  else if (param_2 == *(uint *)(param_1 + 0x74b8)) {
    fparam_1_00 = (double)*(float *)(param_1 + 0x74c0);
  }
  else {
    fparam_1_00 = (double)((float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                  DOUBLE_00108d58) * *(float *)(param_1 + 0x74c4) +
                          *(float *)(param_1 + 0x74bc));
  }
  if (param_3 == 0) {
    fparam_2_00 = (double)*(float *)(param_1 + 0x74cc);
  }
  else if (param_3 == *(uint *)(param_1 + 0x74c8)) {
    fparam_2_00 = (double)*(float *)(param_1 + 0x74d0);
  }
  else {
    fparam_2_00 = (double)((float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) -
                                  DOUBLE_00108d58) * *(float *)(param_1 + 0x74d4) +
                          *(float *)(param_1 + 0x74cc));
  }
  ((void (*)())_gleEvalMap2)(param_1,fparam_1_00,fparam_2_00,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8
               ,in_stack_ffffffa8,in_stack_ffffffb0,in_stack_ffffffb8,in_stack_ffffffc0);
  return;
}

/* _glEvalPoint2_CompExec @ 0x65808 (64 bytes) */
int _glEvalPoint2_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glEvalPoint2_Comp)(param_1,param_2,param_3);
  ((void (*)())_glEvalPoint2_Exec)(param_1,param_2,param_3,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                     (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)((unsigned char *)ghidra_home + 0)),
                     (*(double *)((unsigned char *)ghidra_home + 8)));
  return;
}

/* _glPassThrough_ListExec @ 0x65848 (40 bytes) */
int _glPassThrough_ListExec(param_1, param_2)
  undefined4 param_1;
  float *param_2;
{
  ((void (*)())_glPassThrough_Exec)(param_1,(double)*param_2);
  return 4;
}

/* _glPassThrough_Comp @ 0x65870 (84 bytes) */
float * _glPassThrough_Comp(undefined4 param_1,double fparam_1)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glPassThrough_ListExec_001100dc,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
  }
  return pfVar1;
}

/* _glPassThrough_CompExec @ 0x658c4 (64 bytes) */
void _glPassThrough_CompExec(undefined4 param_1,double fparam_1)
{
  ((float * (*)())_glPassThrough_Comp)(param_1,fparam_1);
  ((void (*)())_glPassThrough_Exec)(param_1,fparam_1);
  return;
}

/* _glDeleteFencesAPPLE_Exec @ 0x65904 (152 bytes) */
int _glDeleteFencesAPPLE_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (-1 < param_2) {
      if (param_2 < 1) {
        return;
      }
      do {
        uVar1 = *param_3;
        param_3 = param_3 + 1;
        _gleDeleteHashNameAndObject(param_1,param_1 + 0x543c,uVar1);
        param_2 = param_2 + -1;
      } while (param_2 != 0);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
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

/* _glTestFenceAPPLE_Exec @ 0x6599c (80 bytes) */
int _glTestFenceAPPLE_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    uVar1 = _gleTestFence(param_1,0,param_2);
  }
  else {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    uVar1 = 1;
  }
  return uVar1;
}

/* _glFinishFenceAPPLE_Exec @ 0x659ec (48 bytes) */
int _glFinishFenceAPPLE_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    _gleFinishFence(param_1,0,param_2);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glIsFenceAPPLE_Exec @ 0x65a1c (76 bytes) */
int _glIsFenceAPPLE_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    uVar1 = _gleIsHashName(param_1 + 0x543c,param_2);
  }
  else {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* _glSetFenceAPPLE_Comp @ 0x65a68 (76 bytes) */
int _glSetFenceAPPLE_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glSetFenceAPPLE_ListExec_001100e8,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glFinishFenceAPPLE_Comp @ 0x65ab4 (76 bytes) */
int _glFinishFenceAPPLE_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glFinishFenceAPPLE_ListExec_001100e4,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glFinishObjectAPPLE_Comp @ 0x65b00 (84 bytes) */
int _glFinishObjectAPPLE_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glFinishObjectAPPLE_ListExec_001100e0,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glSetFenceAPPLE_CompExec @ 0x65b54 (56 bytes) */
int _glSetFenceAPPLE_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glSetFenceAPPLE_Comp)(param_1,param_2);
  _glSetFenceAPPLE_Exec(param_1,param_2);
  return;
}

/* _glFinishFenceAPPLE_CompExec @ 0x65b8c (56 bytes) */
int _glFinishFenceAPPLE_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glFinishFenceAPPLE_Comp)(param_1,param_2);
  ((int (*)())_glFinishFenceAPPLE_Exec)(param_1,param_2);
  return;
}

/* _glFinishObjectAPPLE_CompExec @ 0x65bc4 (64 bytes) */
int _glFinishObjectAPPLE_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glFinishObjectAPPLE_Comp)(param_1,param_2,param_3);
  _glFinishObjectAPPLE_Exec(param_1,param_2,param_3);
  return;
}

/* _glSetFenceAPPLE_ListExec @ 0x65c04 (40 bytes) */
int _glSetFenceAPPLE_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glSetFenceAPPLE_Exec(param_1,*param_2);
  return 4;
}

/* _glFinishFenceAPPLE_ListExec @ 0x65c2c (40 bytes) */
int _glFinishFenceAPPLE_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glFinishFenceAPPLE_Exec)(param_1,*param_2);
  return 4;
}

/* _glFinishObjectAPPLE_ListExec @ 0x65c54 (44 bytes) */
int _glFinishObjectAPPLE_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glFinishObjectAPPLE_Exec(param_1,*param_2,param_2[1]);
  return 8;
}

/* _glFinish_RevertExec @ 0x65c80 (308 bytes) */
int _glFinish_RevertExec(param_1)
  int param_1;
{
  byte bVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  double fparam_1;
  double fparam_1_00;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  
  iVar4 = param_1 + 0x10000;
  bVar1 = *(byte *)(param_1 + 0x85a5);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    _gleRevertSwapToPrimary(param_1);
    uVar3 = 0;
    (**(code **)(param_1 + 0x46f0))(*(undefined4 *)(param_1 + 0x4688));
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      do {
        if (uVar3 != *(byte *)(param_1 + 0x85a8)) {
          (**(code **)(*(int *)(iVar4 + -0x777c) + 0x178))(*(undefined4 *)(iVar4 + -0x7a54));
        }
        uVar3 = uVar3 + 1;
        iVar4 = iVar4 + 0x2e0;
      } while ((int)uVar3 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
    _gleSwitchToRenderer(param_1,(uint)*(byte *)(param_1 + 0x85a5));
    iVar4 = (uint)bVar1 * 0x2e0 + param_1;
    (**(code **)(*(int *)(iVar4 + 0x8884) + 0x138))
              (*(undefined4 *)(iVar4 + 0x85ac),*(undefined4 *)(param_1 + 0x484c),
               *(undefined4 *)(param_1 + 0x4848),0);
    fparam_1 = (double)_gleSwitchToRenderer(param_1,(uint)bVar1);
    ((void (*)())_gleUpdateDepthRangeData)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffffa8,
               in_stack_ffffffb0,in_stack_ffffffb8,in_stack_ffffffc0,in_stack_ffffffc8);
    _gleUpdatePolyMode(param_1);
    ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1_00,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
    _gleUpdateTextureTransform(param_1);
    puVar2 = PTR__gleSetClipInterpFunc_00112038;
    *(undefined **)(param_1 + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
    *(undefined **)(param_1 + 0x49cc) = puVar2;
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _glFlush_RevertExec @ 0x65db4 (224 bytes) */
int _glFlush_RevertExec(param_1)
  int param_1;
{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  double fparam_1;
  double fparam_1_00;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  double in_stack_ffffffd0;
  double in_stack_ffffffd8;
  
  bVar1 = *(byte *)(param_1 + 0x85a5);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    _gleRevertSwapToPrimary(param_1);
    (**(code **)(param_1 + 0x46f4))(*(undefined4 *)(param_1 + 0x4688));
    iVar3 = (uint)bVar1 * 0x2e0 + param_1;
    (**(code **)(*(int *)(iVar3 + 0x8884) + 0x138))
              (*(undefined4 *)(iVar3 + 0x85ac),*(undefined4 *)(param_1 + 0x484c),
               *(undefined4 *)(param_1 + 0x4848),0);
    fparam_1 = (double)_gleSwitchToRenderer(param_1,(uint)bVar1);
    ((void (*)())_gleUpdateDepthRangeData)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffffb8,
               in_stack_ffffffc0,in_stack_ffffffc8,in_stack_ffffffd0,in_stack_ffffffd8);
    _gleUpdatePolyMode(param_1);
    ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1_00,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
    _gleUpdateTextureTransform(param_1);
    puVar2 = PTR__gleSetClipInterpFunc_00112038;
    *(undefined **)(param_1 + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
    *(undefined **)(param_1 + 0x49cc) = puVar2;
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _glGenRenderbuffersEXT_Exec @ 0x65e94 (236 bytes) */
int _glGenRenderbuffersEXT_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (-1 < param_2) {
      iVar4 = *(int *)(param_1 + 0x5148);
      if (*(char *)(iVar4 + 0x8024) != '\0') {
        _pthread_mutex_lock((pthread_mutex_t *)(iVar4 + 0x8028));
        iVar4 = *(int *)(param_1 + 0x5148);
      }
      iVar4 = _gleGenHashNames(((unsigned char *)0x00001004) + iVar4,param_2);
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
      }
      if (iVar4 == 0) {
        return;
      }
      iVar3 = 0;
      if (param_2 < 1) {
        return;
      }
      do {
        iVar2 = iVar3 + iVar4;
        iVar3 = iVar3 + 1;
        *param_3 = iVar2;
        param_3 = param_3 + 1;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
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

/* FUN_00065f84 @ 0x65f84 (440 bytes) */
int FUN_00065f84(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (-1 < param_2) {
      puVar6 = (undefined *)0x0;
      piVar5 = (int *)0x0;
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
      }
      iVar4 = *(int *)(param_1 + 0x744c);
      if (iVar4 != 0) {
        piVar5 = (int *)(iVar4 + 0xd4);
        puVar6 = ((unsigned char *)0x00001004) + *(int *)(param_1 + 0x5148);
      }
      iVar7 = 0;
      if (*(int *)(param_1 + 0x7448) != 0) {
        iVar7 = *(int *)(*(int *)(param_1 + 0x7448) + 4);
      }
      if (0 < param_2) {
        do {
          iVar9 = *param_3;
          param_3 = param_3 + 1;
          if (iVar9 != 0) {
            if (iVar9 == iVar7) {
              _gleBindRenderbuffer(param_1,0);
            }
            if ((iVar4 != 0) && (iVar3 = _gleLookupHashObject(puVar6,iVar9), iVar3 != 0)) {
              uVar8 = 0;
              piVar10 = piVar5;
              do {
                iVar2 = *piVar10;
                piVar10 = piVar10 + 1;
                if (iVar3 == iVar2) {
                  _gleFramebufferTexture(param_1,uVar8,0,0,0,0,0);
                }
                uVar8 = uVar8 + 1;
              } while (uVar8 < 6);
            }
            _gleDeleteHashNameAndObject(param_1,((unsigned char *)0x00001004) + *(int *)(param_1 + 0x5148),iVar9);
          }
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
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

/* _glBindRenderbufferEXT_Exec @ 0x6613c (208 bytes) */
int _glBindRenderbufferEXT_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  pthread_mutex_t *ppVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8d41) {
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        ppVar2 = (pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028);
        _pthread_mutex_lock(ppVar2);
        _gleBindRenderbuffer(param_1,param_3);
        _pthread_mutex_unlock(ppVar2);
        return;
      }
      _gleBindRenderbuffer(param_1,param_3);
      return;
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

/* _glRenderbufferStorageEXT_Exec @ 0x6620c (460 bytes) */
int _glRenderbufferStorageEXT_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  bool bVar1;
  undefined4 uVar2;
  pthread_mutex_t *ppVar3;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 != 0x8d41) goto LAB_00066334;
    if (*(int *)(param_1 + 0x7448) != 0) {
      if (((((int)param_4 < 0) || ((int)param_5 < 0)) ||
          (*(uint *)(*(int *)(param_1 + 0x468c) + 0xc) < param_4)) ||
         (*(uint *)(*(int *)(param_1 + 0x468c) + 0x10) < param_5)) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar2 = 0x501;
        goto LAB_00066344;
      }
      if (param_3 < 0x805c) {
        if (0x804e < param_3) goto LAB_0006634c;
        if (param_3 < 0x1903) {
          if (0x1900 < param_3) goto LAB_0006634c;
          bVar1 = 1 < param_3 - 3;
          goto LAB_00066330;
        }
        if ((0x1906 < param_3) && ((param_3 < 0x1909 || (param_3 == 0x2a10)))) goto LAB_0006634c;
      }
      else {
        if (param_3 < 0x8816) {
          if (0x8813 < param_3) goto LAB_0006634c;
          bVar1 = 2 < param_3 - 0x81a5;
        }
        else {
          if (param_3 < 0x881a) goto LAB_00066334;
          if (param_3 < 0x881c) goto LAB_0006634c;
          bVar1 = 3 < param_3 - 0x8d46;
        }
LAB_00066330:
        if (!bVar1) {
LAB_0006634c:
          if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
            _gleRenderbufferStorage(param_1,0x8d41,param_3,param_4,param_5);
            return;
          }
          ppVar3 = (pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028);
          _pthread_mutex_lock(ppVar3);
          _gleRenderbufferStorage(param_1,0x8d41,param_3,param_4,param_5);
          _pthread_mutex_unlock(ppVar3);
          return;
        }
      }
LAB_00066334:
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar2 = 0x500;
      goto LAB_00066344;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar2 = 0x502;
LAB_00066344:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glIsRenderbufferEXT_Exec @ 0x663d8 (168 bytes) */
int _glIsRenderbufferEXT_Exec(param_1, param_2)
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
    iVar1 = _gleLookupHashObject(((unsigned char *)0x00001004) + iVar1,param_2);
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

/* _glGetRenderbufferParameterivEXT_Exec @ 0x66480 (516 bytes) */
int _glGetRenderbufferParameterivEXT_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint *param_4;
{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint local_20;
  int local_1c [5];
  
  iVar4 = *(int *)(param_1 + 0x7448);
  if (-1 < *(short *)(param_1 + 0x4a10)) {
LAB_000664c4:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
LAB_000666bc:
    *(undefined4 *)(param_1 + 0x7574) = uVar2;
    return;
  }
  if (param_2 != 0x8d41) {
switchD_00066504_caseD_8d45:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x500;
    goto LAB_000666bc;
  }
  if (iVar4 == 0) goto LAB_000664c4;
  switch(param_3) {
  case 0x8d42:
    local_20 = (uint)*(ushort *)(iVar4 + 0xd8);
    break;
  case 0x8d43:
    local_20 = (uint)*(ushort *)(iVar4 + 0xda);
    break;
  case 0x8d44:
    (**(code **)(param_1 + 0x479c))
              (*(undefined4 *)(param_1 + 0x4688),
               *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar4 + 0x10),0,0,
               ((unsigned char *)0x00001003U),&local_20);
    if (local_20 == 0) {
      local_20 = 0x1908;
    }
    break;
  default:
    goto switchD_00066504_caseD_8d45;
  case 0x8d50:
  case 0x8d51:
  case 0x8d52:
  case 0x8d53:
    iVar3 = param_3 + -0xcf4;
    bVar1 = *(byte *)(param_1 + 0x85a8);
    goto LAB_000665d0;
  case 0x8d54:
    bVar1 = *(byte *)(param_1 + 0x85a8);
    iVar3 = 0x884a;
LAB_000665d0:
    (**(code **)(param_1 + 0x479c))
              (*(undefined4 *)(param_1 + 0x4688),*(undefined4 *)((uint)bVar1 * 4 + iVar4 + 0x10),0,0
               ,iVar3,param_4);
    return;
  case 0x8d55:
    (**(code **)(param_1 + 0x479c))
              (*(undefined4 *)(param_1 + 0x4688),
               *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar4 + 0x10),0,0,
               ((unsigned char *)0x00001003U),local_1c);
    if (local_1c[0] == 0x8d47) {
      local_20 = 4;
    }
    else {
      if (local_1c[0] < 0x8d48) {
        if (local_1c[0] == 0x8d46) {
          local_20 = 1;
          break;
        }
      }
      else {
        if (local_1c[0] == 0x8d48) {
          local_20 = 8;
          break;
        }
        if (local_1c[0] == 0x8d49) {
          local_20 = 0x10;
          break;
        }
      }
      local_20 = 0;
    }
  }
  *param_4 = local_20;
  return;
}

/* _glGenFramebuffersEXT_Exec @ 0x666d4 (232 bytes) */
int _glGenFramebuffersEXT_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (-1 < param_2) {
      iVar4 = *(int *)(param_1 + 0x5148);
      if (*(char *)(iVar4 + 0x8024) != '\0') {
        _pthread_mutex_lock((pthread_mutex_t *)(iVar4 + 0x8028));
        iVar4 = *(int *)(param_1 + 0x5148);
      }
      iVar4 = _gleGenHashNames(iVar4,param_2);
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
      }
      if (iVar4 == 0) {
        return;
      }
      iVar3 = 0;
      if (param_2 < 1) {
        return;
      }
      do {
        iVar2 = iVar3 + iVar4;
        iVar3 = iVar3 + 1;
        *param_3 = iVar2;
        param_3 = param_3 + 1;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
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

/* _glDeleteFramebuffersEXT_Exec @ 0x667bc (280 bytes) */
int _glDeleteFramebuffersEXT_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (-1 < param_2) {
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
      }
      iVar2 = 0;
      if (*(int *)(param_1 + 0x744c) != 0) {
        iVar2 = *(int *)(*(int *)(param_1 + 0x744c) + 4);
      }
      if (0 < param_2) {
        do {
          iVar3 = *param_3;
          param_3 = param_3 + 1;
          if (iVar3 != 0) {
            if (iVar3 == iVar2) {
              _gleBindFramebuffer(param_1,0);
            }
            _gleDeleteHashNameAndObject(param_1,*(undefined4 *)(param_1 + 0x5148),iVar3);
          }
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
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

/* _glBindFramebufferEXT_Exec @ 0x668d4 (208 bytes) */
int _glBindFramebufferEXT_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  pthread_mutex_t *ppVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8d40) {
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        ppVar2 = (pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028);
        _pthread_mutex_lock(ppVar2);
        _gleBindFramebuffer(param_1,param_3);
        _pthread_mutex_unlock(ppVar2);
        return;
      }
      _gleBindFramebuffer(param_1,param_3);
      return;
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

/* _glFramebufferTexture1DEXT_Exec @ 0x669a4 (440 bytes) */
int _glFramebufferTexture1DEXT_Exec(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  uint param_6;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = 0;
  uVar3 = 0;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 != 0x8d40) {
LAB_00066a74:
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar3 = 0x500;
      goto LAB_00066af0;
    }
    if (*(int *)(param_1 + 0x744c) != 0) {
      if (param_4 != 0xde0) goto LAB_00066a74;
      if (((int)param_6 < 0) ||
         (0x1fU - LZCOUNT((uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xbc)) < param_6)) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar3 = 0x501;
        goto LAB_00066af0;
      }
      if (param_3 == 0x8d00) {
        uVar1 = 4;
      }
      else if (param_3 == 0x8d20) {
        uVar1 = 5;
      }
      else {
        uVar1 = param_3 - 0x8ce0;
        if (*(uint *)(*(int *)(param_1 + 0x468c) + 0x18) <= uVar1) goto LAB_00066a74;
      }
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
      }
      if (param_5 == 0) {
LAB_00066afc:
        _gleFramebufferTexture(param_1,uVar1,uVar3,iVar2,0,param_6,0);
        if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
          return;
        }
        _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
        return;
      }
      iVar2 = _gleLookupHashObject(*(int *)(param_1 + 0x5148) + 0x2008,param_5);
      if (iVar2 != 0) {
        uVar3 = 4;
        goto LAB_00066afc;
      }
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
      }
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x502;
LAB_00066af0:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glFramebufferTexture2DEXT_Exec @ 0x66b5c (544 bytes) */
int _glFramebufferTexture2DEXT_Exec(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
  uint param_6;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 0;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 != 0x8d40) goto LAB_00066c98;
    if (*(int *)(param_1 + 0x744c) != 0) {
      if (-1 < (int)param_6) {
        if (param_3 == 0x8d00) {
          uVar2 = 4;
        }
        else if (param_3 == 0x8d20) {
          uVar2 = 5;
        }
        else {
          uVar2 = param_3 - 0x8ce0;
          if (*(uint *)(*(int *)(param_1 + 0x468c) + 0x18) <= uVar2) goto LAB_00066c98;
        }
        if (param_4 == 0x84f5) {
          if (param_6 == 0) {
            uVar1 = 2;
LAB_00066cac:
            if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
              _pthread_mutex_lock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
            }
            if ((param_5 == 0) ||
               (iVar3 = _gleLookupHashObject(*(int *)(param_1 + 0x5148) + 0x2008,param_5),
               iVar3 != 0)) {
              _gleFramebufferTexture(param_1,uVar2,uVar1,iVar3,iVar4,param_6,0);
              if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
                return;
              }
              _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
              return;
            }
            if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
              _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
            }
            goto LAB_00066d04;
          }
        }
        else if (param_4 < 0x84f6) {
          if (param_4 != 0xde1) {
LAB_00066c98:
            if (*(int *)(param_1 + 0x7574) != 0) {
              return;
            }
            uVar1 = 0x500;
            goto LAB_00066d14;
          }
          uVar1 = 3;
          if (param_6 <= 0x1fU - LZCOUNT((uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xbc)))
          goto LAB_00066cac;
        }
        else {
          if (5 < param_4 - 0x8515) goto LAB_00066c98;
          if (param_6 <= 0x1fU - LZCOUNT((uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xc2))) {
            iVar4 = param_4 - 0x8515;
            uVar1 = 0;
            goto LAB_00066cac;
          }
        }
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x501;
      goto LAB_00066d14;
    }
  }
LAB_00066d04:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_00066d14:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glFramebufferTexture3DEXT_Exec @ 0x66d7c (460 bytes) */
int _glFramebufferTexture3DEXT_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  uint param_6;
  int param_7;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = 0;
  uVar3 = 0;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8d40) {
      if (*(int *)(param_1 + 0x744c) == 0) goto LAB_00066ecc;
      if (param_4 == 0x806f) {
        if (-1 < (int)param_6) {
          uVar1 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xbe);
          if ((param_6 <= 0x1fU - LZCOUNT(uVar1)) && (param_7 < (int)uVar1)) {
            if (param_3 == 0x8d00) {
              uVar1 = 4;
            }
            else if (param_3 == 0x8d20) {
              uVar1 = 5;
            }
            else {
              uVar1 = param_3 - 0x8ce0;
              if (*(uint *)(*(int *)(param_1 + 0x468c) + 0x18) <= uVar1) goto LAB_00066e60;
            }
            if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
              _pthread_mutex_lock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
            }
            if (param_5 == 0) {
LAB_00066ee8:
              _gleFramebufferTexture(param_1,uVar1,uVar3,iVar2,0,param_6,param_7);
              if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
                return;
              }
              _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
              return;
            }
            iVar2 = _gleLookupHashObject(*(int *)(param_1 + 0x5148) + 0x2008,param_5);
            if (iVar2 != 0) {
              uVar3 = 1;
              goto LAB_00066ee8;
            }
            if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
              _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
            }
            goto LAB_00066ecc;
          }
        }
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar3 = 0x501;
        goto LAB_00066edc;
      }
    }
LAB_00066e60:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
  }
  else {
LAB_00066ecc:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
  }
LAB_00066edc:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* FUN_00066f4c @ 0x66f4c (420 bytes) */
int FUN_00066f4c(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = 0;
  uVar3 = 0;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((param_2 != 0x8d40) || ((param_5 != 0 && (param_4 != 0x8d41)))) {
LAB_00066ffc:
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar3 = 0x500;
      goto LAB_00067074;
    }
    if (*(int *)(param_1 + 0x744c) != 0) {
      if (param_3 == 0x8d00) {
        uVar1 = 4;
      }
      else if (param_3 == 0x8d20) {
        uVar1 = 5;
      }
      else {
        uVar1 = param_3 - 0x8ce0;
        if (*(uint *)(*(int *)(param_1 + 0x468c) + 0x18) <= uVar1) goto LAB_00066ffc;
      }
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
      }
      if (param_5 == 0) {
LAB_00067080:
        _gleFramebufferTexture(param_1,uVar1,uVar3,iVar2,0,0,0);
        if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
          return;
        }
        _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
        return;
      }
      iVar2 = _gleLookupHashObject(((unsigned char *)0x00001004) + *(int *)(param_1 + 0x5148),param_5);
      if (iVar2 != 0) {
        uVar3 = 0x2000;
        goto LAB_00067080;
      }
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
      }
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x502;
LAB_00067074:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glIsFramebufferEXT_Exec @ 0x670f0 (164 bytes) */
int _glIsFramebufferEXT_Exec(param_1, param_2)
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
    iVar1 = _gleLookupHashObject(iVar1,param_2);
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

/* _glCheckFramebufferStatusEXT_Exec @ 0x67194 (216 bytes) */
undefined4 _glCheckFramebufferStatusEXT_Exec(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  undefined4 uVar1;
  int iVar2;
  double extraout_f1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8d40) {
      iVar2 = *(int *)(param_1 + 0x744c);
      if (iVar2 == 0) {
        return 0x8cd5;
      }
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
        iVar2 = *(int *)(param_1 + 0x744c);
        fparam_1 = extraout_f1;
      }
      uVar1 = ((int (*)())_gleCheckFramebufferStatus)(param_1,iVar2 + 0x10,param_3,param_4,param_5,param_6,param_7,fparam_1,
                         fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
        return uVar1;
      }
      return uVar1;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* _glGetFramebufferAttachmentParameterivEXT_Exec @ 0x6726c (452 bytes) */
int _glGetFramebufferAttachmentParameterivEXT_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  int *param_5;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8d40) {
      if (*(int *)(param_1 + 0x744c) == 0) goto LAB_00067294;
      iVar4 = *(int *)(param_1 + 0x744c) + 0x10;
      if (param_3 == 0x8d00) {
        uVar3 = 4;
      }
      else if (param_3 == 0x8d20) {
        uVar3 = 5;
      }
      else {
        uVar3 = param_3 - 0x8ce0;
        if (*(uint *)(*(int *)(param_1 + 0x468c) + 0x18) <= uVar3) goto LAB_00067418;
      }
      iVar2 = *(int *)(uVar3 * 4 + iVar4 + 0xc4);
      if (param_4 == 0x8cd0) {
        if (iVar2 == 0) {
          *param_5 = 0;
          return;
        }
        if ((*(ushort *)(iVar2 + 0x34) & 0x3c00) == 0x2000) {
          iVar4 = 0x8d41;
        }
        else {
          iVar4 = 0x1702;
        }
LAB_00067358:
        *param_5 = iVar4;
        return;
      }
      if (param_4 == 0x8cd1) {
        iVar4 = 0;
        if (iVar2 != 0) {
          iVar4 = *(int *)(iVar2 + 4);
        }
        goto LAB_00067358;
      }
      if ((iVar2 != 0) && ((*(ushort *)(iVar2 + 0x34) & 0x3c00) != 0x2000)) {
        if (param_4 == 0x8cd3) {
          if ((*(ushort *)(iVar2 + 0x34) & 0xf) == 0) {
            *param_5 = *(int *)(uVar3 * 0x18 + iVar4 + 0x24) + 0x8515;
            return;
          }
          iVar4 = 0;
          goto LAB_00067358;
        }
        if (param_4 < 0x8cd4) {
          if (param_4 == 0x8cd2) {
            iVar4 = *(int *)(uVar3 * 0x18 + iVar4 + 0x28);
            goto LAB_00067358;
          }
        }
        else if (param_4 == 0x8cd4) {
          iVar4 = *(int *)(uVar3 * 0x18 + iVar4 + 0x2c);
          goto LAB_00067358;
        }
      }
    }
LAB_00067418:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
  }
  else {
LAB_00067294:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glGenerateMipmapEXT_Exec @ 0x67430 (316 bytes) */
int _glGenerateMipmapEXT_Exec(param_1, param_2)
  int param_1;
  uint param_2;
{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  pthread_mutex_t *ppVar6;
  
  if (param_2 != 0x806f) {
    if (param_2 < 0x8070) {
      if (1 < param_2 - 0xde0) {
LAB_000674d0:
        if (*(int *)(param_1 + 0x7574) == 0) {
          uVar2 = 0x500;
LAB_00067554:
          *(undefined4 *)(param_1 + 0x7574) = uVar2;
        }
        return;
      }
    }
    else {
      if (param_2 != 0x8513) goto LAB_000674d0;
      iVar3 = _gleLookUpTexture2D(param_1,0x8513);
      uVar5 = (int)*(short *)(iVar3 + 0x60);
      if ((int)(uint)*(byte *)(iVar3 + 0x87) < (int)*(short *)(iVar3 + 0x60)) {
        uVar5 = (uint)*(byte *)(iVar3 + 0x87);
      }
      puVar4 = (ushort *)(iVar3 + 0x94);
      iVar3 = 0;
      uVar5 = 1 << (uVar5 & 0x3f) | 1;
      do {
        uVar1 = *puVar4;
        puVar4 = puVar4 + 1;
        if ((uVar1 & uVar5) != uVar5) {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar2 = 0x502;
          goto LAB_00067554;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 6);
    }
  }
  if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
    _gleGenerateMipmap(param_1,param_2);
    return;
  }
  ppVar6 = (pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028);
  _pthread_mutex_lock(ppVar6);
  _gleGenerateMipmap(param_1,param_2);
  _pthread_mutex_unlock(ppVar6);
  return;
}

/* _glFogf_ListExec @ 0x6756c (44 bytes) */
int _glFogf_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glFogf_Exec)(param_1,*param_2,(double)GH_U2F((unsigned int)(param_2[1])));
  return 8;
}

