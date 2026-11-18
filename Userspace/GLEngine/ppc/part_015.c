#include "decls.h"

/* _glEvalCoord2dv_Exec @ 0x64bcc (20 bytes) */
void _glEvalCoord2dv_Exec(undefined4 glContext,double *u,double unusedFloatArg1,double unusedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double forwardedFloatArg9,double forwardedFloatArg10,double forwardedFloatArg11,double forwardedFloatArg12)
{
  ((void (*)())_gleEvalMap2)(glContext,(double)(float)(*u),(double)(float)(u[1]),forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,
               forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,forwardedFloatArg9,forwardedFloatArg10,forwardedFloatArg11,forwardedFloatArg12);
  return;
}

/* _glEvalCoord2dv_CompExec @ 0x64be0 (56 bytes) */
void _glEvalCoord2dv_CompExec(glContext, u)
  undefined4 glContext;
  undefined4 u;
{
  unsigned int ghidra_home[8] = { glContext, u, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  _glEvalCoord2dv_Comp(glContext,u);
  ((void (*)())_glEvalCoord2dv_Exec)(glContext,u,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)((unsigned char *)ghidra_home + 0)),
             (*(double *)((unsigned char *)ghidra_home + 8)));
  return;
}

/* _glEvalCoord2f_ListExec_body @ 0x64c1c (48 bytes) */
undefined4 _glEvalCoord2f_ListExec_body(undefined4 glContext,double *recordedArgs,double unusedFloatArg1,double fparam_2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12)
{
  double incomingStack_ffffffb8;
  double incomingStack_ffffffc0;
  double incomingStack_ffffffc8;
  double incomingStack_ffffffd0;
  
  ((void (*)())_gleEvalMap2)(glContext,(double)(float)(*recordedArgs),(double)(float)fparam_2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,
               forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,incomingStack_ffffffb8,incomingStack_ffffffc0,incomingStack_ffffffc8,
               incomingStack_ffffffd0);
  return 0x10;
}

/* _glEvalCoord2f_Comp @ 0x64c4c (100 bytes) */
double * _glEvalCoord2f_Comp(undefined4 glContext,double u,double v)
{
  double *listRecord;
  
  listRecord = (double *)_gleAddListItem(glContext,PTR__glEvalCoord2f_ListExec_001100c4,0x10);
  if (listRecord != (double *)0x0) {
    *listRecord = u;
    listRecord[1] = v;
  }
  return listRecord;
}

/* _glEvalCoord2f_CompExec @ 0x64cb4 (84 bytes) */
void _glEvalCoord2f_CompExec(undefined4 glContext,float u,float v,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double fparam_9,double forwardedFloatArg10,double forwardedFloatArg11,double forwardedFloatArg12)
{
  undefined4 in_LR;
  
  ((double * (*)())_glEvalCoord2f_Comp)(glContext,u,v);
  ((void (*)())_gleEvalMap2)(glContext,u,v,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,
               (double)CONCAT44(in_LR,(*(unsigned int *)((unsigned char *)&(fparam_9) + 4))),forwardedFloatArg10,forwardedFloatArg11,forwardedFloatArg12);
  return;
}

/* _glEvalCoord2fv_Comp @ 0x64d04 (88 bytes) */
int _glEvalCoord2fv_Comp(glContext, u)
  undefined4 glContext;
  float *u;
{
  double *listRecord;
  
  listRecord = (double *)_gleAddListItem(glContext,PTR__glEvalCoord2f_ListExec_001100c4,0x10);
  if (listRecord != (double *)0x0) {
    *listRecord = (double)*u;
    listRecord[1] = (double)u[1];
  }
  return listRecord;
}

/* _glEvalCoord2fv_Exec @ 0x64d5c (12 bytes) */
void _glEvalCoord2fv_Exec(undefined4 glContext,float *u,double unusedFloatArg1,double unusedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double forwardedFloatArg9,double forwardedFloatArg10,double forwardedFloatArg11,double forwardedFloatArg12)
{
  ((void (*)())_gleEvalMap2)(glContext,(double)*u,(double)u[1],forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,
               forwardedFloatArg7,forwardedFloatArg8,forwardedFloatArg9,forwardedFloatArg10,forwardedFloatArg11,forwardedFloatArg12);
  return;
}

/* _glEvalCoord2fv_CompExec @ 0x64d68 (56 bytes) */
void _glEvalCoord2fv_CompExec(glContext, u)
  undefined4 glContext;
  undefined4 u;
{
  unsigned int ghidra_home[8] = { glContext, u, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glEvalCoord2fv_Comp)(glContext,u);
  ((void (*)())_glEvalCoord2fv_Exec)(glContext,u,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)((unsigned char *)ghidra_home + 0)),
             (*(double *)((unsigned char *)ghidra_home + 8)));
  return;
}

/* _glEvalMesh1_ListExec @ 0x64da0 (52 bytes) */
undefined4 _glEvalMesh1_ListExec(undefined4 glContext,undefined4 *recordedArgs,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glEvalMesh1_Exec)(glContext,*recordedArgs,recordedArgs[1],recordedArgs[2],forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,
                    forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return 0xc;
}

/* _glEvalMesh1_Comp @ 0x64dd4 (92 bytes) */
int _glEvalMesh1_Comp(glContext, mode, i1, i2)
  undefined4 glContext;
  undefined4 mode;
  undefined4 i1;
  undefined4 i2;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glEvalMesh1_ListExec_001100d0,0xc);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[2] = i2;
    *listRecord = mode;
    listRecord[1] = i1;
  }
  return listRecord;
}

/* _glEvalMesh1_Exec @ 0x64e30 (296 bytes) */
void _glEvalMesh1_Exec(int glContext,int mode,uint i1,int i2,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  undefined4 glErrorCode;
  float glContextFloat74b4;
  float glContextFloat74ac;
  float glContextFloat74b0;
  double intToDoubleMagic;
  undefined4 uVar5;
  double dVar6;
  double fparam_1_00;
  double dVar7;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (mode == 0x1b00) {
      uVar5 = 0;
    }
    else {
      if (mode != 0x1b01) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_00064ea8;
      }
      uVar5 = 3;
    }
    ((void (*)())_glBegin_Exec)(glContext,uVar5,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
                  forwardedFloatArg8);
    intToDoubleMagic = DOUBLE_00108d58;
    glContextFloat74b4 = *(float *)(glContext + 0x74b4);
    dVar7 = (double)CONCAT44(0x43300000,
                             *(uint *)(0x74a4 + glContext + 4) ^ 0x80000000) -
            DOUBLE_00108d58;
    glContextFloat74ac = *(float *)(glContext + 0x74ac);
    glContextFloat74b0 = *(float *)(glContext + 0x74b0);
    for (; (int)i1 <= i2; i1 = i1 + 1) {
      fparam_1_00 = (double)glContextFloat74ac;
      if ((i1 != 0) &&
         (dVar6 = (double)(float)((double)CONCAT44(0x43300000,i1 ^ 0x80000000) - intToDoubleMagic),
         fparam_1_00 = (double)glContextFloat74b0, dVar6 != (double)(float)dVar7)) {
        fparam_1_00 = (double)(float)(dVar6 * (double)glContextFloat74b4 + (double)glContextFloat74ac);
      }
      ((void (*)())_gleEvalMap1)(glContext,fparam_1_00);
    }
    _glEnd_Exec(glContext);
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_00064ea8:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glEvalMesh1_CompExec @ 0x64f58 (72 bytes) */
void _glEvalMesh1_CompExec(glContext, mode, i1, i2)
  undefined4 glContext;
  undefined4 mode;
  undefined4 i1;
  undefined4 i2;
{
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glEvalMesh1_Comp)(glContext,mode,i1,i2);
  ((void (*)())_glEvalMesh1_Exec)(glContext,mode,i1,i2,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,
                    incomingFpr8);
  return;
}

/* _glEvalMesh2_ListExec @ 0x64fa0 (60 bytes) */
undefined4 _glEvalMesh2_ListExec(undefined4 glContext,undefined4 *recordedArgs,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glEvalMesh2_Exec)(glContext,*recordedArgs,recordedArgs[1],recordedArgs[2],recordedArgs[3],recordedArgs[4],forwardedFloatArg1,forwardedFloatArg2,
                    forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return 0x14;
}

/* _glEvalMesh2_Comp @ 0x64fdc (108 bytes) */
int _glEvalMesh2_Comp(glContext, mode, i1, i2, j1, j2)
  undefined4 glContext;
  undefined4 mode;
  undefined4 i1;
  undefined4 i2;
  undefined4 j1;
  undefined4 j2;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glEvalMesh2_ListExec_001100cc,0x14);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[4] = j2;
    *listRecord = mode;
    listRecord[1] = i1;
    listRecord[2] = i2;
    listRecord[3] = j1;
  }
  return listRecord;
}

/* _glEvalMesh2_Exec @ 0x65048 (1248 bytes) */
void _glEvalMesh2_Exec(int glContext,uint mode,uint i1,int i2,uint j1,int j2,double fparam_1,double fparam_2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  double intToDoubleMagic4;
  double intToDoubleMagic3;
  double intToDoubleMagic2;
  double intToDoubleMagic;
  bool vIndexInRange;
  float glContextPtr74c4;
  float glContextPtr74d4;
  undefined4 glErrorCode;
  uint *gridDivisionsUPtr;
  uint lineUIndex;
  uint vIndex;
  uint uIndex;
  double vCoord;
  double pointVCoord;
  double nextVCoord;
  double uCoord;
  double lineUCoord;
  double fparam_1_00;
  double incomingStack_ffffff48;
  double incomingStack_ffffff50;
  double incomingStack_ffffff58;
  double incomingStack_ffffff60;
  
  intToDoubleMagic2 = DOUBLE_00108d58;
  if (*(short *)(glContext + 0x4a10) < 0) {
    gridDivisionsUPtr = (uint *)(glContext + 0x74b8);
    glContextPtr74c4 = *(float *)(glContext + 0x74c4);
    glContextPtr74d4 = *(float *)(glContext + 0x74d4);
    if (mode == 0x1b01) {
      vIndexInRange = (int)j1 <= j2;
      vIndex = j1;
      intToDoubleMagic3 = DOUBLE_00108d58;
      while (DOUBLE_00108d58 = intToDoubleMagic3, vIndexInRange) {
        if (vIndex == 0) {
          vCoord = (double)*(float *)(glContext + 0x74cc);
        }
        else if (vIndex == *(uint *)(glContext + 0x74c8)) {
          vCoord = (double)*(float *)(glContext + 0x74d0);
        }
        else {
          vCoord = (double)((float)((double)CONCAT44(0x43300000,vIndex ^ 0x80000000) - intToDoubleMagic2) * glContextPtr74d4
                          + *(float *)(glContext + 0x74cc));
        }
        ((void (*)())_glBegin_Exec)(glContext,3,fparam_1,fparam_2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
                      forwardedFloatArg8);
        intToDoubleMagic4 = DOUBLE_00108d58;
        for (lineUIndex = i1; (int)lineUIndex <= i2; lineUIndex = lineUIndex + 1) {
          if (lineUIndex == 0) {
            uCoord = (double)*(float *)(glContext + 0x74bc);
          }
          else if (lineUIndex == *gridDivisionsUPtr) {
            uCoord = (double)*(float *)(glContext + 0x74c0);
          }
          else {
            uCoord = (double)((float)((double)CONCAT44(0x43300000,lineUIndex ^ 0x80000000) - intToDoubleMagic4) *
                              glContextPtr74c4 + *(float *)(glContext + 0x74bc));
          }
          fparam_2 = vCoord;
          ((void (*)())_gleEvalMap2)(glContext,uCoord,vCoord,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,
                       incomingStack_ffffff48,incomingStack_ffffff50,incomingStack_ffffff58,incomingStack_ffffff60);
        }
        vIndex = vIndex + 1;
        fparam_1 = (double)_glEnd_Exec(glContext);
        vIndexInRange = (int)vIndex <= j2;
        intToDoubleMagic3 = DOUBLE_00108d58;
      }
      for (; (int)i1 <= i2; i1 = i1 + 1) {
        if (i1 == 0) {
          lineUCoord = (double)*(float *)(glContext + 0x74bc);
        }
        else if (i1 == *gridDivisionsUPtr) {
          lineUCoord = (double)*(float *)(glContext + 0x74c0);
        }
        else {
          lineUCoord = (double)((float)((double)CONCAT44(0x43300000,i1 ^ 0x80000000) - intToDoubleMagic3) *
                            glContextPtr74c4 + *(float *)(glContext + 0x74bc));
        }
        ((void (*)())_glBegin_Exec)(glContext,3,fparam_1,fparam_2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
                      forwardedFloatArg8);
        intToDoubleMagic4 = DOUBLE_00108d58;
        vIndexInRange = (int)j1 <= j2;
        vIndex = j1;
        while (vIndexInRange) {
          if (vIndex == 0) {
            fparam_2 = (double)*(float *)(glContext + 0x74cc);
          }
          else if (vIndex == *(uint *)(glContext + 0x74c8)) {
            fparam_2 = (double)*(float *)(glContext + 0x74d0);
          }
          else {
            fparam_2 = (double)((float)((double)CONCAT44(0x43300000,vIndex ^ 0x80000000) - intToDoubleMagic4) *
                                glContextPtr74d4 + *(float *)(glContext + 0x74cc));
          }
          vIndex = vIndex + 1;
          ((void (*)())_gleEvalMap2)(glContext,lineUCoord,fparam_2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8
                       ,incomingStack_ffffff48,incomingStack_ffffff50,incomingStack_ffffff58,incomingStack_ffffff60);
          vIndexInRange = (int)vIndex <= j2;
        }
        fparam_1 = (double)_glEnd_Exec(glContext);
      }
      return;
    }
    if (mode < 0x1b02) {
      if (mode == 0x1b00) {
        ((void (*)())_glBegin_Exec)(glContext,0,fparam_1,fparam_2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
                      forwardedFloatArg8);
        intToDoubleMagic3 = DOUBLE_00108d58;
        intToDoubleMagic2 = DOUBLE_00108d58;
        for (; DOUBLE_00108d58 = intToDoubleMagic2, (int)j1 <= j2; j1 = j1 + 1) {
          uIndex = i1;
          if (j1 == 0) {
            pointVCoord = (double)*(float *)(glContext + 0x74cc);
          }
          else if (j1 == *(uint *)(glContext + 0x74c8)) {
            pointVCoord = (double)*(float *)(glContext + 0x74d0);
          }
          else {
            pointVCoord = (double)((float)((double)CONCAT44(0x43300000,j1 ^ 0x80000000) - intToDoubleMagic3) *
                             glContextPtr74d4 + *(float *)(glContext + 0x74cc));
          }
          for (; (int)uIndex <= i2; uIndex = uIndex + 1) {
            if (uIndex == 0) {
              uCoord = (double)*(float *)(glContext + 0x74bc);
            }
            else if (uIndex == *gridDivisionsUPtr) {
              uCoord = (double)*(float *)(glContext + 0x74c0);
            }
            else {
              uCoord = (double)((float)((double)CONCAT44(0x43300000,uIndex ^ 0x80000000) - intToDoubleMagic2) *
                                glContextPtr74c4 + *(float *)(glContext + 0x74bc));
            }
            ((void (*)())_gleEvalMap2)(glContext,uCoord,pointVCoord,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,
                         incomingStack_ffffff48,incomingStack_ffffff50,incomingStack_ffffff58,incomingStack_ffffff60);
          }
          intToDoubleMagic2 = DOUBLE_00108d58;
        }
        _glEnd_Exec(glContext);
        return;
      }
    }
    else if (mode == 0x1b02) {
      while ((int)j1 < j2) {
        if (j1 == 0) {
          vCoord = (double)*(float *)(glContext + 0x74cc);
        }
        else if (j1 == *(uint *)(glContext + 0x74c8)) {
          vCoord = (double)*(float *)(glContext + 0x74d0);
        }
        else {
          vCoord = (double)((float)((double)CONCAT44(0x43300000,j1 ^ 0x80000000) - intToDoubleMagic2) *
                           glContextPtr74d4 + *(float *)(glContext + 0x74cc));
        }
        if (j1 == 0xffffffff) {
          nextVCoord = (double)*(float *)(glContext + 0x74cc);
          j1 = 0;
        }
        else {
          j1 = j1 + 1;
          if (j1 == *(uint *)(glContext + 0x74c8)) {
            nextVCoord = (double)*(float *)(glContext + 0x74d0);
          }
          else {
            nextVCoord = (double)((float)((double)CONCAT44(0x43300000,j1 ^ 0x80000000) - intToDoubleMagic2) *
                             glContextPtr74d4 + *(float *)(glContext + 0x74cc));
          }
        }
        ((void (*)())_glBegin_Exec)(glContext,5,fparam_1,fparam_2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
                      forwardedFloatArg8);
        intToDoubleMagic = DOUBLE_00108d58;
        for (uIndex = i1; (int)uIndex <= i2; uIndex = uIndex + 1) {
          if (uIndex == 0) {
            fparam_1_00 = (double)*(float *)(glContext + 0x74bc);
          }
          else if (uIndex == *gridDivisionsUPtr) {
            fparam_1_00 = (double)*(float *)(glContext + 0x74c0);
          }
          else {
            fparam_1_00 = (double)((float)((double)CONCAT44(0x43300000,uIndex ^ 0x80000000) - intToDoubleMagic)
                                   * glContextPtr74c4 + *(float *)(glContext + 0x74bc));
          }
          ((void (*)())_gleEvalMap2)(glContext,fparam_1_00,vCoord,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
                       forwardedFloatArg8,incomingStack_ffffff48,incomingStack_ffffff50,incomingStack_ffffff58,
                       incomingStack_ffffff60);
          fparam_2 = nextVCoord;
          ((void (*)())_gleEvalMap2)(glContext,fparam_1_00,nextVCoord,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
                       forwardedFloatArg8,incomingStack_ffffff48,incomingStack_ffffff50,incomingStack_ffffff58,
                       incomingStack_ffffff60);
        }
        fparam_1 = (double)_glEnd_Exec(glContext);
      }
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glEvalMesh2_CompExec @ 0x65528 (88 bytes) */
void _glEvalMesh2_CompExec(glContext, mode, i1, i2, j1, j2)
  undefined4 glContext;
  undefined4 mode;
  undefined4 i1;
  undefined4 i2;
  undefined4 j1;
  undefined4 j2;
{
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glEvalMesh2_Comp)(glContext,mode,i1,i2,j1,j2);
  ((void (*)())_glEvalMesh2_Exec)(glContext,mode,i1,i2,j1,j2,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5
                    ,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glEvalPoint1_ListExec @ 0x65580 (40 bytes) */
undefined4 _glEvalPoint1_ListExec(undefined4 glContext,undefined4 *recordedArgs,double forwardedFloatArg1)
{
  ((void (*)())_glEvalPoint1_Exec)(glContext,*recordedArgs,forwardedFloatArg1);
  return 4;
}

/* _glEvalPoint1_Comp @ 0x655a8 (76 bytes) */
int _glEvalPoint1_Comp(glContext, i)
  undefined4 glContext;
  undefined4 i;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glEvalPoint1_ListExec_001100d8,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = i;
  }
  return listRecord;
}

/* _glEvalPoint1_Exec @ 0x655f4 (132 bytes) */
void _glEvalPoint1_Exec(int glContext,uint i,double unusedFloatArg1)
{
  double fparam_1_00;
  
  if (i == 0) {
    fparam_1_00 = (double)*(float *)(glContext + 0x74ac);
  }
  else if (i == *(uint *)(0x74a4 + glContext + 4)) {
    fparam_1_00 = (double)*(float *)(glContext + 0x74b0);
  }
  else {
    fparam_1_00 = (double)((float)((double)CONCAT44(0x43300000,i ^ 0x80000000) -
                                  DOUBLE_00108d58) * *(float *)(glContext + 0x74b4) +
                          *(float *)(glContext + 0x74ac));
  }
  ((void (*)())_gleEvalMap1)(glContext,fparam_1_00);
  return;
}

/* _glEvalPoint1_CompExec @ 0x65678 (56 bytes) */
void _glEvalPoint1_CompExec(glContext, i)
  undefined4 glContext;
  undefined4 i;
{
  double forwardedFloatArg1;
  
  ((int (*)())_glEvalPoint1_Comp)(glContext,i);
  ((void (*)())_glEvalPoint1_Exec)(glContext,i,forwardedFloatArg1);
  return;
}

/* _glEvalPoint2_ListExec @ 0x656b0 (44 bytes) */
undefined4 _glEvalPoint2_ListExec(undefined4 glContext,undefined4 *recordedArgs,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12)
{
  double incomingStack_ffffffb8;
  double incomingStack_ffffffc0;
  double incomingStack_ffffffc8;
  double incomingStack_ffffffd0;
  
  ((void (*)())_glEvalPoint2_Exec)(glContext,*recordedArgs,recordedArgs[1],forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,
                     forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,incomingStack_ffffffb8,incomingStack_ffffffc0,
                     incomingStack_ffffffc8,incomingStack_ffffffd0);
  return 8;
}

/* _glEvalPoint2_Comp @ 0x656dc (84 bytes) */
int _glEvalPoint2_Comp(glContext, i, j)
  undefined4 glContext;
  undefined4 i;
  undefined4 j;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glEvalPoint2_ListExec_001100d4,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = j;
    *listRecord = i;
  }
  return listRecord;
}

/* _glEvalPoint2_Exec @ 0x65730 (216 bytes) */
void _glEvalPoint2_Exec(int glContext,uint i,uint j,double unusedFloatArg1,double unusedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12)
{
  double fparam_1_00;
  double fparam_2_00;
  double incomingStack_ffffffa8;
  double incomingStack_ffffffb0;
  double incomingStack_ffffffb8;
  double incomingStack_ffffffc0;
  
  if (i == 0) {
    fparam_1_00 = (double)*(float *)(glContext + 0x74bc);
  }
  else if (i == *(uint *)(glContext + 0x74b8)) {
    fparam_1_00 = (double)*(float *)(glContext + 0x74c0);
  }
  else {
    fparam_1_00 = (double)((float)((double)CONCAT44(0x43300000,i ^ 0x80000000) -
                                  DOUBLE_00108d58) * *(float *)(glContext + 0x74c4) +
                          *(float *)(glContext + 0x74bc));
  }
  if (j == 0) {
    fparam_2_00 = (double)*(float *)(glContext + 0x74cc);
  }
  else if (j == *(uint *)(glContext + 0x74c8)) {
    fparam_2_00 = (double)*(float *)(glContext + 0x74d0);
  }
  else {
    fparam_2_00 = (double)((float)((double)CONCAT44(0x43300000,j ^ 0x80000000) -
                                  DOUBLE_00108d58) * *(float *)(glContext + 0x74d4) +
                          *(float *)(glContext + 0x74cc));
  }
  ((void (*)())_gleEvalMap2)(glContext,fparam_1_00,fparam_2_00,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8
               ,incomingStack_ffffffa8,incomingStack_ffffffb0,incomingStack_ffffffb8,incomingStack_ffffffc0);
  return;
}

/* _glEvalPoint2_CompExec @ 0x65808 (64 bytes) */
void _glEvalPoint2_CompExec(glContext, i, j)
  undefined4 glContext;
  undefined4 i;
  undefined4 j;
{
  unsigned int ghidra_home[8] = { glContext, i, j, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glEvalPoint2_Comp)(glContext,i,j);
  ((void (*)())_glEvalPoint2_Exec)(glContext,i,j,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                     (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)((unsigned char *)ghidra_home + 0)),
                     (*(double *)((unsigned char *)ghidra_home + 8)));
  return;
}

/* _glPassThrough_ListExec @ 0x65848 (40 bytes) */
int _glPassThrough_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  float *recordedArgs;
{
  ((void (*)())_glPassThrough_Exec)(glContext,(double)*recordedArgs);
  return 4;
}

/* _glPassThrough_Comp @ 0x65870 (84 bytes) */
float * _glPassThrough_Comp(undefined4 glContext,float token)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glPassThrough_ListExec_001100dc,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)token;
  }
  return listRecord;
}

/* _glPassThrough_CompExec @ 0x658c4 (64 bytes) */
void _glPassThrough_CompExec(undefined4 glContext,float token)
{
  ((float * (*)())_glPassThrough_Comp)(glContext,token);
  ((void (*)())_glPassThrough_Exec)(glContext,token);
  return;
}

/* _glDeleteFencesAPPLE_Exec @ 0x65904 (152 bytes) */
void _glDeleteFencesAPPLE_Exec(glContext, n, fences)
  int glContext;
  int n;
  undefined4 *fences;
{
  undefined4 glErrorCode;
  undefined4 uVar1;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      if (n < 1) {
        return;
      }
      do {
        uVar1 = *fences;
        fences = fences + 1;
        _gleDeleteHashNameAndObject(glContext,glContext + 0x543c,uVar1);
        n = n + -1;
      } while (n != 0);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glTestFenceAPPLE_Exec @ 0x6599c (80 bytes) */
int _glTestFenceAPPLE_Exec(glContext, fence)
  int glContext;
  undefined4 fence;
{
  undefined4 testResult;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    testResult = _gleTestFence(glContext,0,fence);
  }
  else {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    testResult = 1;
  }
  return testResult;
}

/* _glFinishFenceAPPLE_Exec @ 0x659ec (48 bytes) */
void _glFinishFenceAPPLE_Exec(glContext, fence)
  int glContext;
  undefined4 fence;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    _gleFinishFence(glContext,0,fence);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glIsFenceAPPLE_Exec @ 0x65a1c (76 bytes) */
int _glIsFenceAPPLE_Exec(glContext, fence)
  int glContext;
  undefined4 fence;
{
  undefined4 uVar1;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    uVar1 = _gleIsHashName(glContext + 0x543c,fence);
  }
  else {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* _glSetFenceAPPLE_Comp @ 0x65a68 (76 bytes) */
int _glSetFenceAPPLE_Comp(glContext, fence)
  undefined4 glContext;
  undefined4 fence;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glSetFenceAPPLE_ListExec_001100e8,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = fence;
  }
  return listRecord;
}

/* _glFinishFenceAPPLE_Comp @ 0x65ab4 (76 bytes) */
int _glFinishFenceAPPLE_Comp(glContext, fence)
  undefined4 glContext;
  undefined4 fence;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glFinishFenceAPPLE_ListExec_001100e4,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = fence;
  }
  return listRecord;
}

/* _glFinishObjectAPPLE_Comp @ 0x65b00 (84 bytes) */
int _glFinishObjectAPPLE_Comp(glContext, object, name)
  undefined4 glContext;
  undefined4 object;
  undefined4 name;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glFinishObjectAPPLE_ListExec_001100e0,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = name;
    *listRecord = object;
  }
  return listRecord;
}

/* _glSetFenceAPPLE_CompExec @ 0x65b54 (56 bytes) */
void _glSetFenceAPPLE_CompExec(glContext, fence)
  undefined4 glContext;
  undefined4 fence;
{
  ((int (*)())_glSetFenceAPPLE_Comp)(glContext,fence);
  _glSetFenceAPPLE_Exec(glContext,fence);
  return;
}

/* _glFinishFenceAPPLE_CompExec @ 0x65b8c (56 bytes) */
void _glFinishFenceAPPLE_CompExec(glContext, fence)
  undefined4 glContext;
  undefined4 fence;
{
  ((int (*)())_glFinishFenceAPPLE_Comp)(glContext,fence);
  ((void (*)())_glFinishFenceAPPLE_Exec)(glContext,fence);
  return;
}

/* _glFinishObjectAPPLE_CompExec @ 0x65bc4 (64 bytes) */
void _glFinishObjectAPPLE_CompExec(glContext, object, name)
  undefined4 glContext;
  undefined4 object;
  undefined4 name;
{
  ((int (*)())_glFinishObjectAPPLE_Comp)(glContext,object,name);
  _glFinishObjectAPPLE_Exec(glContext,object,name);
  return;
}

/* _glSetFenceAPPLE_ListExec @ 0x65c04 (40 bytes) */
int _glSetFenceAPPLE_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glSetFenceAPPLE_Exec(glContext,*recordedArgs);
  return 4;
}

/* _glFinishFenceAPPLE_ListExec @ 0x65c2c (40 bytes) */
int _glFinishFenceAPPLE_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glFinishFenceAPPLE_Exec)(glContext,*recordedArgs);
  return 4;
}

/* _glFinishObjectAPPLE_ListExec @ 0x65c54 (44 bytes) */
int _glFinishObjectAPPLE_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glFinishObjectAPPLE_Exec(glContext,*recordedArgs,recordedArgs[1]);
  return 8;
}

/* _glFinish_RevertExec @ 0x65c80 (308 bytes) */
void _glFinish_RevertExec(glContext)
  int glContext;
{
  byte glContextByte85a5;
  undefined *puVar2;
  uint loopIndex;
  int iVar4;
  double fparam_1;
  double fparam_1_00;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffffa8;
  double incomingStack_ffffffb0;
  double incomingStack_ffffffb8;
  double incomingStack_ffffffc0;
  double incomingStack_ffffffc8;
  
  iVar4 = glContext + 0x10000;
  glContextByte85a5 = *(byte *)(glContext + 0x85a5);
  if (*(short *)(glContext + 0x4a10) < 0) {
    _gleRevertSwapToPrimary(glContext);
    loopIndex = 0;
    (**(code **)(glContext + 0x46f0))(*(undefined4 *)(glContext + 0x4688));
    if (*(char *)(glContext + 0x85a4) != '\0') {
      do {
        if (loopIndex != *(byte *)(glContext + 0x85a8)) {
          (**(code **)(*(int *)(iVar4 + -0x777c) + 0x178))(*(undefined4 *)(iVar4 + -0x7a54));
        }
        loopIndex = loopIndex + 1;
        iVar4 = iVar4 + 0x2e0;
      } while ((int)loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
    _gleSwitchToRenderer(glContext,(uint)*(byte *)(glContext + 0x85a5));
    iVar4 = (uint)glContextByte85a5 * 0x2e0 + glContext;
    (**(code **)(*(int *)(iVar4 + 0x8884) + 0x138))
              (*(undefined4 *)(iVar4 + 0x85ac),*(undefined4 *)(glContext + 0x484c),
               *(undefined4 *)(glContext + 0x4848),0);
    fparam_1 = (double)_gleSwitchToRenderer(glContext,(uint)glContextByte85a5);
    ((void (*)())_gleUpdateDepthRangeData)(glContext,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffffa8,
               incomingStack_ffffffb0,incomingStack_ffffffb8,incomingStack_ffffffc0,incomingStack_ffffffc8);
    _gleUpdatePolyMode(glContext);
    ((void (*)())_gleUpdateViewScissorData)(glContext,fparam_1_00,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
    _gleUpdateTextureTransform(glContext);
    puVar2 = PTR__gleSetClipInterpFunc_00112038;
    *(undefined **)(glContext + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
    *(undefined **)(glContext + 0x49cc) = puVar2;
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _glFlush_RevertExec @ 0x65db4 (224 bytes) */
void _glFlush_RevertExec(glContext)
  int glContext;
{
  byte glContextByte85a5;
  undefined *puVar2;
  int iVar3;
  double fparam_1;
  double fparam_1_00;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffffb8;
  double incomingStack_ffffffc0;
  double incomingStack_ffffffc8;
  double incomingStack_ffffffd0;
  double incomingStack_ffffffd8;
  
  glContextByte85a5 = *(byte *)(glContext + 0x85a5);
  if (*(short *)(glContext + 0x4a10) < 0) {
    _gleRevertSwapToPrimary(glContext);
    (**(code **)(glContext + 0x46f4))(*(undefined4 *)(glContext + 0x4688));
    iVar3 = (uint)glContextByte85a5 * 0x2e0 + glContext;
    (**(code **)(*(int *)(iVar3 + 0x8884) + 0x138))
              (*(undefined4 *)(iVar3 + 0x85ac),*(undefined4 *)(glContext + 0x484c),
               *(undefined4 *)(glContext + 0x4848),0);
    fparam_1 = (double)_gleSwitchToRenderer(glContext,(uint)glContextByte85a5);
    ((void (*)())_gleUpdateDepthRangeData)(glContext,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffffb8,
               incomingStack_ffffffc0,incomingStack_ffffffc8,incomingStack_ffffffd0,incomingStack_ffffffd8);
    _gleUpdatePolyMode(glContext);
    ((void (*)())_gleUpdateViewScissorData)(glContext,fparam_1_00,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
    _gleUpdateTextureTransform(glContext);
    puVar2 = PTR__gleSetClipInterpFunc_00112038;
    *(undefined **)(glContext + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
    *(undefined **)(glContext + 0x49cc) = puVar2;
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _glGenRenderbuffersEXT_Exec @ 0x65e94 (236 bytes) */
void _glGenRenderbuffersEXT_Exec(glContext, n, renderbuffers)
  int glContext;
  int n;
  int *renderbuffers;
{
  undefined4 glErrorCode;
  int nameValue;
  int loopIndex;
  int sharedStateThenFirstName;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      sharedStateThenFirstName = *(int *)(glContext + 0x5148);
      if (*(char *)(sharedStateThenFirstName + 0x8024) != '\0') {
        _pthread_mutex_lock(sharedStateThenFirstName + 0x8028);
        sharedStateThenFirstName = *(int *)(glContext + 0x5148);
      }
      sharedStateThenFirstName = _gleGenHashNames(((unsigned char *)0x00001004) + sharedStateThenFirstName,n);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (sharedStateThenFirstName == 0) {
        return;
      }
      loopIndex = 0;
      if (n < 1) {
        return;
      }
      do {
        nameValue = loopIndex + sharedStateThenFirstName;
        loopIndex = loopIndex + 1;
        *renderbuffers = nameValue;
        renderbuffers = renderbuffers + 1;
        n = n + -1;
      } while (n != 0);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glDeleteRenderbuffersEXT_Exec_body @ 0x65f84 (440 bytes) */
void _glDeleteRenderbuffersEXT_Exec_body(glContext, n, renderbuffers)
  int glContext;
  int n;
  int *renderbuffers;
{
  undefined4 glErrorCode;
  int iVar2;
  int hashObject;
  int framebufferObject;
  int *piVar5;
  undefined *puVar6;
  int iVar7;
  uint loopIndex;
  int iVar9;
  int *cursor;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      puVar6 = (undefined *)0x0;
      piVar5 = (int *)0x0;
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      framebufferObject = *(int *)(glContext + 0x744c);
      if (framebufferObject != 0) {
        piVar5 = (int *)(framebufferObject + 0xd4);
        puVar6 = ((unsigned char *)0x00001004) + *(int *)(glContext + 0x5148);
      }
      iVar7 = 0;
      if (*(int *)(glContext + 0x7448) != 0) {
        iVar7 = *(int *)(*(int *)(glContext + 0x7448) + 4);
      }
      if (0 < n) {
        do {
          iVar9 = *renderbuffers;
          renderbuffers = renderbuffers + 1;
          if (iVar9 != 0) {
            if (iVar9 == iVar7) {
              _gleBindRenderbuffer(glContext,0);
            }
            if ((framebufferObject != 0) && (hashObject = _gleLookupHashObject(puVar6,iVar9), hashObject != 0)) {
              loopIndex = 0;
              cursor = piVar5;
              do {
                iVar2 = *cursor;
                cursor = cursor + 1;
                if (hashObject == iVar2) {
                  _gleFramebufferTexture(glContext,loopIndex,0,0,0,0,0);
                }
                loopIndex = loopIndex + 1;
              } while (loopIndex < 6);
            }
            _gleDeleteHashNameAndObject(glContext,((unsigned char *)0x00001004) + *(int *)(glContext + 0x5148),iVar9);
          }
          n = n + -1;
        } while (n != 0);
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glBindRenderbufferEXT_Exec @ 0x6613c (208 bytes) */
void _glBindRenderbufferEXT_Exec(glContext, target, renderbuffer)
  int glContext;
  int target;
  undefined4 renderbuffer;
{
  undefined4 glErrorCode;
  int sharedMutex;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8d41) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        sharedMutex = *(int *)(glContext + 0x5148) + 0x8028;
        _pthread_mutex_lock(sharedMutex);
        _gleBindRenderbuffer(glContext,renderbuffer);
        _pthread_mutex_unlock(sharedMutex);
        return;
      }
      _gleBindRenderbuffer(glContext,renderbuffer);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glRenderbufferStorageEXT_Exec @ 0x6620c (460 bytes) */
void _glRenderbufferStorageEXT_Exec(glContext, target, internalformat, width, height)
  int glContext;
  int target;
  uint internalformat;
  uint width;
  uint height;
{
  bool bVar1;
  undefined4 glErrorCode;
  int iVar3;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target != 0x8d41) goto LAB_00066334;
    if (*(int *)(glContext + 0x7448) != 0) {
      if (((((int)width < 0) || ((int)height < 0)) ||
          (*(uint *)(*(int *)(glContext + 0x468c) + 0xc) < width)) ||
         (*(uint *)(*(int *)(glContext + 0x468c) + 0x10) < height)) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x501;
        goto LAB_00066344;
      }
      if (internalformat < 0x805c) {
        if (0x804e < internalformat) goto LAB_0006634c;
        if (internalformat < 0x1903) {
          if (0x1900 < internalformat) goto LAB_0006634c;
          bVar1 = 1 < internalformat - 3;
          goto LAB_00066330;
        }
        if ((0x1906 < internalformat) && ((internalformat < 0x1909 || (internalformat == 0x2a10)))) goto LAB_0006634c;
      }
      else {
        if (internalformat < 0x8816) {
          if (0x8813 < internalformat) goto LAB_0006634c;
          bVar1 = 2 < internalformat - 0x81a5;
        }
        else {
          if (internalformat < 0x881a) goto LAB_00066334;
          if (internalformat < 0x881c) goto LAB_0006634c;
          bVar1 = 3 < internalformat - 0x8d46;
        }
LAB_00066330:
        if (!bVar1) {
LAB_0006634c:
          if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
            _gleRenderbufferStorage(glContext,0x8d41,internalformat,width,height);
            return;
          }
          iVar3 = *(int *)(glContext + 0x5148) + 0x8028;
          _pthread_mutex_lock(iVar3);
          _gleRenderbufferStorage(glContext,0x8d41,internalformat,width,height);
          _pthread_mutex_unlock(iVar3);
          return;
        }
      }
LAB_00066334:
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_00066344;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00066344:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glIsRenderbufferEXT_Exec @ 0x663d8 (168 bytes) */
int _glIsRenderbufferEXT_Exec(glContext, renderbuffer)
  int glContext;
  undefined4 renderbuffer;
{
  int sharedStateThenRenderbufferObject;
  bool isRenderbuffer;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    sharedStateThenRenderbufferObject = *(int *)(glContext + 0x5148);
    if (*(char *)(sharedStateThenRenderbufferObject + 0x8024) != '\0') {
      _pthread_mutex_lock(sharedStateThenRenderbufferObject + 0x8028);
      sharedStateThenRenderbufferObject = *(int *)(glContext + 0x5148);
    }
    sharedStateThenRenderbufferObject = _gleLookupHashObject(((unsigned char *)0x00001004) + sharedStateThenRenderbufferObject,renderbuffer);
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    isRenderbuffer = sharedStateThenRenderbufferObject != 0;
  }
  else {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    isRenderbuffer = false;
  }
  return isRenderbuffer;
}

/* _glGetRenderbufferParameterivEXT_Exec @ 0x66480 (516 bytes) */
void _glGetRenderbufferParameterivEXT_Exec(glContext, target, pname, params)
  int glContext;
  int target;
  int pname;
  uint *params;
{
  byte glContextByte85a8;
  undefined4 glErrorCode;
  int iVar3;
  int iVar4;
  uint local_20;
  int local_1c [5];
  
  iVar4 = *(int *)(glContext + 0x7448);
  if (-1 < *(short *)(glContext + 0x4a10)) {
LAB_000664c4:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_000666bc:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  if (target != 0x8d41) {
switchD_00066504_caseD_8d45:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
    goto LAB_000666bc;
  }
  if (iVar4 == 0) goto LAB_000664c4;
  switch(pname) {
  case 0x8d42:
    local_20 = (uint)*(ushort *)(iVar4 + 0xd8);
    break;
  case 0x8d43:
    local_20 = (uint)*(ushort *)(iVar4 + 0xda);
    break;
  case 0x8d44:
    iVar4 = (uint)*(byte *)(glContext + 0x85a8) * 4 + iVar4;
    (**(code **)(glContext + 0x479c))
              (*(undefined4 *)(glContext + 0x4688),*(undefined4 *)(iVar4 + 0x10),0,0,((unsigned char *)0x00001003U),
               &local_20,iVar4);
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
    iVar3 = pname + -0xcf4;
    glContextByte85a8 = *(byte *)(glContext + 0x85a8);
    goto LAB_000665d0;
  case 0x8d54:
    glContextByte85a8 = *(byte *)(glContext + 0x85a8);
    iVar3 = 0x884a;
LAB_000665d0:
    (**(code **)(glContext + 0x479c))
              (*(undefined4 *)(glContext + 0x4688),*(undefined4 *)((uint)glContextByte85a8 * 4 + iVar4 + 0x10),0,0
               ,iVar3,params);
    return;
  case 0x8d55:
    iVar4 = (uint)*(byte *)(glContext + 0x85a8) * 4 + iVar4;
    (**(code **)(glContext + 0x479c))
              (*(undefined4 *)(glContext + 0x4688),*(undefined4 *)(iVar4 + 0x10),0,0,((unsigned char *)0x00001003U),
               local_1c,iVar4);
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
  *params = local_20;
  return;
}

/* _glGenFramebuffersEXT_Exec @ 0x666d4 (232 bytes) */
void _glGenFramebuffersEXT_Exec(glContext, n, framebuffers)
  int glContext;
  int n;
  int *framebuffers;
{
  undefined4 glErrorCode;
  int nameValue;
  int loopIndex;
  int sharedStateThenFirstName;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      sharedStateThenFirstName = *(int *)(glContext + 0x5148);
      if (*(char *)(sharedStateThenFirstName + 0x8024) != '\0') {
        _pthread_mutex_lock(sharedStateThenFirstName + 0x8028);
        sharedStateThenFirstName = *(int *)(glContext + 0x5148);
      }
      sharedStateThenFirstName = _gleGenHashNames(sharedStateThenFirstName,n);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (sharedStateThenFirstName == 0) {
        return;
      }
      loopIndex = 0;
      if (n < 1) {
        return;
      }
      do {
        nameValue = loopIndex + sharedStateThenFirstName;
        loopIndex = loopIndex + 1;
        *framebuffers = nameValue;
        framebuffers = framebuffers + 1;
        n = n + -1;
      } while (n != 0);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glDeleteFramebuffersEXT_Exec @ 0x667bc (280 bytes) */
void _glDeleteFramebuffersEXT_Exec(glContext, n, framebuffers)
  int glContext;
  int n;
  int *framebuffers;
{
  undefined4 glErrorCode;
  int boundFramebufferName;
  int framebufferName;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      boundFramebufferName = 0;
      if (*(int *)(glContext + 0x744c) != 0) {
        boundFramebufferName = *(int *)(*(int *)(glContext + 0x744c) + 4);
      }
      if (0 < n) {
        do {
          framebufferName = *framebuffers;
          framebuffers = framebuffers + 1;
          if (framebufferName != 0) {
            if (framebufferName == boundFramebufferName) {
              _gleBindFramebuffer(glContext,0);
            }
            _gleDeleteHashNameAndObject(glContext,*(undefined4 *)(glContext + 0x5148),framebufferName);
          }
          n = n + -1;
        } while (n != 0);
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glBindFramebufferEXT_Exec @ 0x668d4 (208 bytes) */
void _glBindFramebufferEXT_Exec(glContext, target, framebuffer)
  int glContext;
  int target;
  undefined4 framebuffer;
{
  undefined4 glErrorCode;
  int iVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8d40) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        iVar2 = *(int *)(glContext + 0x5148) + 0x8028;
        _pthread_mutex_lock(iVar2);
        _gleBindFramebuffer(glContext,framebuffer);
        _pthread_mutex_unlock(iVar2);
        return;
      }
      _gleBindFramebuffer(glContext,framebuffer);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glFramebufferTexture1DEXT_Exec @ 0x669a4 (440 bytes) */
void _glFramebufferTexture1DEXT_Exec(glContext, target, attachment, textarget, texture, level)
  int glContext;
  int target;
  int attachment;
  int textarget;
  int texture;
  uint level;
{
  undefined4 glErrorCode;
  uint attachmentIndex;
  int textureObject;
  undefined4 attachmentType;
  
  textureObject = 0;
  attachmentType = 0;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target != 0x8d40) {
LAB_00066a74:
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_00066af0;
    }
    if (*(int *)(glContext + 0x744c) != 0) {
      if (textarget != 0xde0) goto LAB_00066a74;
      if (((int)level < 0) ||
         (0x1fU - LZCOUNT((uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xbc)) < level)) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x501;
        goto LAB_00066af0;
      }
      if (attachment == 0x8d00) {
        attachmentIndex = 4;
      }
      else if (attachment == 0x8d20) {
        attachmentIndex = 5;
      }
      else {
        attachmentIndex = attachment - 0x8ce0;
        if (*(uint *)(*(int *)(glContext + 0x468c) + 0x18) <= attachmentIndex) goto LAB_00066a74;
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (texture == 0) {
LAB_00066afc:
        _gleFramebufferTexture(glContext,attachmentIndex,attachmentType,textureObject,0,level,0);
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
          return;
        }
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
        return;
      }
      textureObject = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x2008,texture);
      if (textureObject != 0) {
        attachmentType = 4;
        goto LAB_00066afc;
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00066af0:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glFramebufferTexture2DEXT_Exec @ 0x66b5c (544 bytes) */
void _glFramebufferTexture2DEXT_Exec(glContext, target, attachment, textarget, texture, level)
  int glContext;
  int target;
  int attachment;
  uint textarget;
  int texture;
  uint level;
{
  undefined4 glErrorCode;
  undefined4 uVar1;
  uint attachmentIndex;
  int textureObject;
  int face;
  
  textureObject = 0;
  face = 0;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target != 0x8d40) goto LAB_00066c98;
    if (*(int *)(glContext + 0x744c) != 0) {
      if (-1 < (int)level) {
        if (attachment == 0x8d00) {
          attachmentIndex = 4;
        }
        else if (attachment == 0x8d20) {
          attachmentIndex = 5;
        }
        else {
          attachmentIndex = attachment - 0x8ce0;
          if (*(uint *)(*(int *)(glContext + 0x468c) + 0x18) <= attachmentIndex) goto LAB_00066c98;
        }
        if (textarget == 0x84f5) {
          if (level == 0) {
            uVar1 = 2;
LAB_00066cac:
            if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
              _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
            }
            if ((texture == 0) ||
               (textureObject = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x2008,texture),
               textureObject != 0)) {
              _gleFramebufferTexture(glContext,attachmentIndex,uVar1,textureObject,face,level,0);
              if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
                return;
              }
              _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
              return;
            }
            if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
              _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
            }
            goto LAB_00066d04;
          }
        }
        else if (textarget < 0x84f6) {
          if (textarget != 0xde1) {
LAB_00066c98:
            if (*(int *)(glContext + 0x7574) != 0) {
              return;
            }
            glErrorCode = 0x500;
            goto LAB_00066d14;
          }
          uVar1 = 3;
          if (level <= 0x1fU - LZCOUNT((uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xbc)))
          goto LAB_00066cac;
        }
        else {
          if (5 < textarget - 0x8515) goto LAB_00066c98;
          if (level <= 0x1fU - LZCOUNT((uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xc2))) {
            face = textarget - 0x8515;
            uVar1 = 0;
            goto LAB_00066cac;
          }
        }
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_00066d14;
    }
  }
LAB_00066d04:
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00066d14:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glFramebufferTexture3DEXT_Exec @ 0x66d7c (460 bytes) */
void _glFramebufferTexture3DEXT_Exec(glContext, target, attachment, textarget, texture, level, zoffset)
  int glContext;
  int target;
  int attachment;
  int textarget;
  int texture;
  uint level;
  int zoffset;
{
  undefined4 glErrorCode;
  uint uVar1;
  int textureObject;
  undefined4 uVar3;
  
  textureObject = 0;
  uVar3 = 0;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8d40) {
      if (*(int *)(glContext + 0x744c) == 0) goto LAB_00066ecc;
      if (textarget == 0x806f) {
        if (-1 < (int)level) {
          uVar1 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xbe);
          if ((level <= 0x1fU - LZCOUNT(uVar1)) && (zoffset < (int)uVar1)) {
            if (attachment == 0x8d00) {
              uVar1 = 4;
            }
            else if (attachment == 0x8d20) {
              uVar1 = 5;
            }
            else {
              uVar1 = attachment - 0x8ce0;
              if (*(uint *)(*(int *)(glContext + 0x468c) + 0x18) <= uVar1) goto LAB_00066e60;
            }
            if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
              _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
            }
            if (texture == 0) {
LAB_00066ee8:
              _gleFramebufferTexture(glContext,uVar1,uVar3,textureObject,0,level,zoffset);
              if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
                return;
              }
              _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
              return;
            }
            textureObject = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x2008,texture);
            if (textureObject != 0) {
              uVar3 = 1;
              goto LAB_00066ee8;
            }
            if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
              _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
            }
            goto LAB_00066ecc;
          }
        }
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x501;
        goto LAB_00066edc;
      }
    }
LAB_00066e60:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  else {
LAB_00066ecc:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
LAB_00066edc:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glFramebufferRenderbufferEXT_Exec_body @ 0x66f4c (420 bytes) */
void _glFramebufferRenderbufferEXT_Exec_body(glContext, target, attachment, renderbuffertarget, renderbuffer)
  int glContext;
  int target;
  int attachment;
  int renderbuffertarget;
  int renderbuffer;
{
  undefined4 glErrorCode;
  uint attachmentIndex;
  int textureObject;
  undefined4 uVar3;
  
  textureObject = 0;
  uVar3 = 0;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((target != 0x8d40) || ((renderbuffer != 0 && (renderbuffertarget != 0x8d41)))) {
LAB_00066ffc:
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_00067074;
    }
    if (*(int *)(glContext + 0x744c) != 0) {
      if (attachment == 0x8d00) {
        attachmentIndex = 4;
      }
      else if (attachment == 0x8d20) {
        attachmentIndex = 5;
      }
      else {
        attachmentIndex = attachment - 0x8ce0;
        if (*(uint *)(*(int *)(glContext + 0x468c) + 0x18) <= attachmentIndex) goto LAB_00066ffc;
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (renderbuffer == 0) {
LAB_00067080:
        _gleFramebufferTexture(glContext,attachmentIndex,uVar3,textureObject,0,0,0);
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
          return;
        }
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
        return;
      }
      textureObject = _gleLookupHashObject(((unsigned char *)0x00001004) + *(int *)(glContext + 0x5148),renderbuffer);
      if (textureObject != 0) {
        uVar3 = 0x2000;
        goto LAB_00067080;
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00067074:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glIsFramebufferEXT_Exec @ 0x670f0 (164 bytes) */
int _glIsFramebufferEXT_Exec(glContext, framebuffer)
  int glContext;
  undefined4 framebuffer;
{
  int iVar1;
  bool bVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar1 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar1 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar1 + 0x8028);
      iVar1 = *(int *)(glContext + 0x5148);
    }
    iVar1 = _gleLookupHashObject(iVar1,framebuffer);
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    bVar2 = iVar1 != 0;
  }
  else {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    bVar2 = false;
  }
  return bVar2;
}

/* _glCheckFramebufferStatusEXT_Exec @ 0x67194 (216 bytes) */
undefined4 _glCheckFramebufferStatusEXT_Exec(int glContext,int target,undefined4 forwardedArg3,undefined4 forwardedArg4,undefined4 forwardedArg5,undefined4 forwardedArg6,undefined4 forwardedArg7,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  undefined4 glErrorCode;
  undefined4 framebufferStatus;
  int framebufferObject;
  double f1AfterCall;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8d40) {
      framebufferObject = *(int *)(glContext + 0x744c);
      if (framebufferObject == 0) {
        return 0x8cd5;
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
        framebufferObject = *(int *)(glContext + 0x744c);
        forwardedFloatArg1 = f1AfterCall;
      }
      framebufferStatus = ((int (*)())_gleCheckFramebufferStatus)(glContext,framebufferObject + 0x10,forwardedArg3,forwardedArg4,forwardedArg5,forwardedArg6,forwardedArg7,forwardedFloatArg1,
                         forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
        return framebufferStatus;
      }
      return framebufferStatus;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x500;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return 0;
}

/* _glGetFramebufferAttachmentParameterivEXT_Exec @ 0x6726c (452 bytes) */
void _glGetFramebufferAttachmentParameterivEXT_Exec(glContext, target, attachment, pname, params)
  int glContext;
  int target;
  int attachment;
  uint pname;
  int *params;
{
  undefined4 glErrorCode;
  int attachedObject;
  uint attachmentIndex;
  int framebufferStateThenParamValue;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8d40) {
      if (*(int *)(glContext + 0x744c) == 0) goto LAB_00067294;
      framebufferStateThenParamValue = *(int *)(glContext + 0x744c) + 0x10;
      if (attachment == 0x8d00) {
        attachmentIndex = 4;
      }
      else if (attachment == 0x8d20) {
        attachmentIndex = 5;
      }
      else {
        attachmentIndex = attachment - 0x8ce0;
        if (*(uint *)(*(int *)(glContext + 0x468c) + 0x18) <= attachmentIndex) goto LAB_00067418;
      }
      attachedObject = *(int *)(attachmentIndex * 4 + framebufferStateThenParamValue + 0xc4);
      if (pname == 0x8cd0) {
        if (attachedObject == 0) {
          *params = 0;
          return;
        }
        if ((*(ushort *)(attachedObject + 0x34) & 0x3c00) == 0x2000) {
          framebufferStateThenParamValue = 0x8d41;
        }
        else {
          framebufferStateThenParamValue = 0x1702;
        }
LAB_00067358:
        *params = framebufferStateThenParamValue;
        return;
      }
      if (pname == 0x8cd1) {
        framebufferStateThenParamValue = 0;
        if (attachedObject != 0) {
          framebufferStateThenParamValue = *(int *)(attachedObject + 4);
        }
        goto LAB_00067358;
      }
      if ((attachedObject != 0) && ((*(ushort *)(attachedObject + 0x34) & 0x3c00) != 0x2000)) {
        if (pname == 0x8cd3) {
          if ((*(ushort *)(attachedObject + 0x34) & 0xf) == 0) {
            *params = *(int *)(attachmentIndex * 0x18 + framebufferStateThenParamValue + 0x24) + 0x8515;
            return;
          }
          framebufferStateThenParamValue = 0;
          goto LAB_00067358;
        }
        if (pname < 0x8cd4) {
          if (pname == 0x8cd2) {
            framebufferStateThenParamValue = *(int *)(attachmentIndex * 0x18 + framebufferStateThenParamValue + 0x28);
            goto LAB_00067358;
          }
        }
        else if (pname == 0x8cd4) {
          framebufferStateThenParamValue = *(int *)(attachmentIndex * 0x18 + framebufferStateThenParamValue + 0x2c);
          goto LAB_00067358;
        }
      }
    }
LAB_00067418:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  else {
LAB_00067294:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGenerateMipmapEXT_Exec @ 0x67430 (316 bytes) */
void _glGenerateMipmapEXT_Exec(glContext, target)
  int glContext;
  uint target;
{
  int loopIndex;
  ushort uVar1;
  undefined4 glErrorCode;
  ushort *srcCursor;
  uint uVar4;
  int iVar5;
  int textureObject;
  
  if (target != 0x806f) {
    if (target < 0x8070) {
      if (1 < target - 0xde0) {
LAB_000674d0:
        if (*(int *)(glContext + 0x7574) == 0) {
          glErrorCode = 0x500;
LAB_00067554:
          *(undefined4 *)(glContext + 0x7574) = glErrorCode;
        }
        return;
      }
    }
    else {
      if (target != 0x8513) goto LAB_000674d0;
      textureObject = _gleLookUpTexture2D(glContext,0x8513);
      uVar4 = (int)*(short *)(textureObject + 0x60);
      if ((int)(uint)*(byte *)(textureObject + 0x87) < (int)*(short *)(textureObject + 0x60)) {
        uVar4 = (uint)*(byte *)(textureObject + 0x87);
      }
      srcCursor = (ushort *)(textureObject + 0x94);
      loopIndex = 0;
      uVar4 = 1 << (uVar4 & 0x3f) | 1;
      do {
        uVar1 = *srcCursor;
        srcCursor = srcCursor + 1;
        if ((uVar1 & uVar4) != uVar4) {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x502;
          goto LAB_00067554;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < 6);
    }
  }
  if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
    _gleGenerateMipmap(glContext,target);
    return;
  }
  iVar5 = *(int *)(glContext + 0x5148) + 0x8028;
  _pthread_mutex_lock(iVar5);
  _gleGenerateMipmap(glContext,target);
  _pthread_mutex_unlock(iVar5);
  return;
}

/* _glFogf_ListExec @ 0x6756c (44 bytes) */
int _glFogf_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glFogf_Exec)(glContext,*recordedArgs,(double)GH_U2F((unsigned int)(recordedArgs[1])));
  return 8;
}

