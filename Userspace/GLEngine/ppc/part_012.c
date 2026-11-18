#include "decls.h"

/* _glColor4uiv_CompExec @ 0x5d138 (56 bytes) */
void _glColor4uiv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  _glColor4uiv_Comp(glContext,v);
  _glColor4uiv_Exec(glContext,v);
  return;
}

/* _glColor4us_Comp @ 0x5d170 (228 bytes) */
int _glColor4us_Comp(glContext, red, green, blue, alpha)
  undefined4 glContext;
  uint red;
  uint green;
  uint blue;
  uint alpha;
{
  float channelScale;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor4_ListExec_00110058,0x10);
  channelScale = FLOAT_00108e74;
  if (listRecord != (float *)0x0) {
    *listRecord = (GH_U2F((unsigned int)((red | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
    listRecord[1] = (GH_U2F((unsigned int)((green | 0x4b000000))) - 8388608.0) * channelScale;
    listRecord[2] = (GH_U2F((unsigned int)((blue | 0x4b000000))) - 8388608.0) * channelScale;
    listRecord[3] = (GH_U2F((unsigned int)((alpha | 0x4b000000))) - 8388608.0) * channelScale;
  }
  return listRecord;
}

/* _glColor4us_Exec @ 0x5d254 (204 bytes) */
double _glColor4us_Exec(int glContext,uint red,uint green,uint blue,uint alpha,double fparam_1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = (GH_U2F((unsigned int)((alpha | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  fVar2 = (GH_U2F((unsigned int)((green | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  fVar3 = (GH_U2F((unsigned int)((blue | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(glContext + 0x2a0) = (GH_U2F((unsigned int)((red | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(glContext + 0x2ac) = fVar1;
  *(float *)(glContext + 0x2a4) = fVar2;
  *(float *)(glContext + 0x2a8) = fVar3;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    fparam_1 = (double)(**(double ( **)(int,int))(glContext + 0x4de0))(glContext, glContext + 0x2a0);
  }
  return fparam_1;
}

/* _glColor4us_CompExec @ 0x5d320 (80 bytes) */
void _glColor4us_CompExec(glContext, red, green, blue, alpha)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
  undefined4 alpha;
{
  unsigned int ghidra_home[8] = { glContext, red, green, blue, alpha, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glColor4us_Comp)(glContext,red,green,blue,alpha);
  ((double (*)())_glColor4us_Exec)(glContext,red,green,blue,alpha,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,
                   incomingFpr7,incomingFpr8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                   (*(double *)((unsigned char *)ghidra_home + 0)),(*(double *)((unsigned char *)ghidra_home + 8)),(*(double *)((unsigned char *)ghidra_home + 16)));
  return;
}

/* _glColor4usv_Comp @ 0x5d370 (232 bytes) */
int _glColor4usv_Comp(glContext, v)
  undefined4 glContext;
  ushort *v;
{
  float fVar1;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor4_ListExec_00110058,0x10);
  fVar1 = FLOAT_00108e74;
  if (listRecord != (float *)0x0) {
    *listRecord = (GH_U2F((unsigned int)((*v | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
    listRecord[1] = (GH_U2F((unsigned int)((v[1] | 0x4b000000))) - 8388608.0) * fVar1;
    listRecord[2] = (GH_U2F((unsigned int)((v[2] | 0x4b000000))) - 8388608.0) * fVar1;
    listRecord[3] = (GH_U2F((unsigned int)((v[3] | 0x4b000000))) - 8388608.0) * fVar1;
  }
  return listRecord;
}

/* _glColor4usv_Exec @ 0x5d458 (220 bytes) */
double _glColor4usv_Exec(int glContext,ushort *v,double forwardedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float alphaConverted;
  float greenConverted;
  float blueConverted;
  
  alphaConverted = (GH_U2F((unsigned int)((v[3] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  greenConverted = (GH_U2F((unsigned int)((v[1] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  blueConverted = (GH_U2F((unsigned int)((v[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(glContext + 0x2a0) = (GH_U2F((unsigned int)((*v | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(glContext + 0x2ac) = alphaConverted;
  *(float *)(glContext + 0x2a4) = greenConverted;
  *(float *)(glContext + 0x2a8) = blueConverted;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    forwardedFloatArg1 = (double)(**(double ( **)(int,int))(glContext + 0x4de0))(glContext, glContext + 0x2a0);
  }
  return forwardedFloatArg1;
}

/* _glColor4usv_CompExec @ 0x5d534 (56 bytes) */
void _glColor4usv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  unsigned int ghidra_home[8] = { glContext, v, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glColor4usv_Comp)(glContext,v);
  ((double (*)())_glColor4usv_Exec)(glContext,v,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                    (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)((unsigned char *)ghidra_home + 0)),
                    (*(double *)((unsigned char *)ghidra_home + 8)),(*(double *)((unsigned char *)ghidra_home + 16)));
  return;
}

/* _gleLightMaterialChangeNoop @ 0x5d56c (4 bytes) */
void _gleLightMaterialChangeNoop()
{
  return;
}

/* _glIndex_ListExec @ 0x5d570 (16 bytes) */
int _glIndex_ListExec(glContext, recordedArgs)
  int glContext;
  undefined4 *recordedArgs;
{
  *(undefined4 *)(glContext + 700) = *recordedArgs;
  return 4;
}

/* _glIndexd_Comp @ 0x5d580 (100 bytes) */
float * _glIndexd_Comp(undefined4 glContext,double c)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glIndex_ListExec_00110054,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)(c * DOUBLE_00108d78);
  }
  return listRecord;
}

/* _glIndexd_Exec @ 0x5d5e4 (40 bytes) */
void _glIndexd_Exec(int glContext,double c)
{
  *(float *)(glContext + 700) = (float)(c * DOUBLE_00108d78);
  return;
}

/* _glIndexd_CompExec @ 0x5d60c (64 bytes) */
void _glIndexd_CompExec(undefined4 glContext,double c)
{
  ((float * (*)())_glIndexd_Comp)(glContext,c);
  ((void (*)())_glIndexd_Exec)(glContext,c);
  return;
}

/* _glIndexdv_Comp @ 0x5d64c (96 bytes) */
int _glIndexdv_Comp(glContext, c)
  undefined4 glContext;
  double *c;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glIndex_ListExec_00110054,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)(*c * DOUBLE_00108d78);
  }
  return listRecord;
}

/* _glIndexdv_Exec @ 0x5d6ac (44 bytes) */
void _glIndexdv_Exec(glContext, c)
  int glContext;
  double *c;
{
  *(float *)(glContext + 700) = (float)(*c * DOUBLE_00108d78);
  return;
}

/* _glIndexdv_CompExec @ 0x5d6d8 (56 bytes) */
void _glIndexdv_CompExec(glContext, c)
  undefined4 glContext;
  undefined4 c;
{
  ((int (*)())_glIndexdv_Comp)(glContext,c);
  ((void (*)())_glIndexdv_Exec)(glContext,c);
  return;
}

/* _glIndexf_Comp @ 0x5d710 (96 bytes) */
float * _glIndexf_Comp(undefined4 glContext,float c)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glIndex_ListExec_00110054,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (c * FLOAT_00108e5c);
  }
  return listRecord;
}

/* _glIndexf_Exec @ 0x5d770 (36 bytes) */
void _glIndexf_Exec(int glContext,float c)
{
  *(float *)(glContext + 700) = (c * FLOAT_00108e5c);
  return;
}

/* _glIndexf_CompExec @ 0x5d794 (64 bytes) */
void _glIndexf_CompExec(undefined4 glContext,float c)
{
  ((float * (*)())_glIndexf_Comp)(glContext,c);
  ((void (*)())_glIndexf_Exec)(glContext,c);
  return;
}

/* _glIndexfv_Comp @ 0x5d7d4 (92 bytes) */
int _glIndexfv_Comp(glContext, c)
  undefined4 glContext;
  float *c;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glIndex_ListExec_00110054,4);
  if (listRecord != (float *)0x0) {
    *listRecord = *c * FLOAT_00108e5c;
  }
  return listRecord;
}

/* _glIndexfv_Exec @ 0x5d830 (40 bytes) */
void _glIndexfv_Exec(glContext, c)
  int glContext;
  float *c;
{
  *(float *)(glContext + 700) = *c * FLOAT_00108e5c;
  return;
}

/* _glIndexfv_CompExec @ 0x5d858 (56 bytes) */
void _glIndexfv_CompExec(glContext, c)
  undefined4 glContext;
  undefined4 c;
{
  ((int (*)())_glIndexfv_Comp)(glContext,c);
  ((void (*)())_glIndexfv_Exec)(glContext,c);
  return;
}

/* _glIndexi_Comp @ 0x5d890 (120 bytes) */
int _glIndexi_Comp(glContext, c)
  undefined4 glContext;
  int c;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glIndex_ListExec_00110054,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,c * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  }
  return listRecord;
}

/* _glIndexi_Exec @ 0x5d908 (68 bytes) */
void _glIndexi_Exec(glContext, c)
  int glContext;
  int c;
{
  *(float *)(glContext + 700) =
       (float)((double)CONCAT44(0x43300000,c * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  return;
}

/* _glIndexi_CompExec @ 0x5d94c (56 bytes) */
void _glIndexi_CompExec(glContext, c)
  undefined4 glContext;
  undefined4 c;
{
  ((int (*)())_glIndexi_Comp)(glContext,c);
  ((void (*)())_glIndexi_Exec)(glContext,c);
  return;
}

/* _glIndexiv_Comp @ 0x5d984 (124 bytes) */
int _glIndexiv_Comp(glContext, c)
  undefined4 glContext;
  int *c;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glIndex_ListExec_00110054,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,*c * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  }
  return listRecord;
}

/* _glIndexiv_CompExec @ 0x5da48 (128 bytes) */
void _glIndexiv_CompExec(glContext, c)
  int glContext;
  int *c;
{
  ((int (*)())_glIndexiv_Comp)(glContext,c);
  *(float *)(glContext + 700) =
       (float)((double)CONCAT44(0x43300000,*c * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  return;
}

/* _glIndexs_Comp @ 0x5da80 (120 bytes) */
int _glIndexs_Comp(glContext, c)
  undefined4 glContext;
  int c;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glIndex_ListExec_00110054,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,c * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  }
  return listRecord;
}

/* _glIndexs_Exec @ 0x5daf8 (68 bytes) */
void _glIndexs_Exec(glContext, c)
  int glContext;
  int c;
{
  *(float *)(glContext + 700) =
       (float)((double)CONCAT44(0x43300000,c * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  return;
}

/* _glIndexs_CompExec @ 0x5db3c (56 bytes) */
void _glIndexs_CompExec(glContext, c)
  undefined4 glContext;
  undefined4 c;
{
  ((int (*)())_glIndexs_Comp)(glContext,c);
  ((void (*)())_glIndexs_Exec)(glContext,c);
  return;
}

/* _glIndexsv_Comp @ 0x5db74 (124 bytes) */
int _glIndexsv_Comp(glContext, c)
  undefined4 glContext;
  short *c;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glIndex_ListExec_00110054,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,*c * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  }
  return listRecord;
}

/* _glIndexsv_CompExec @ 0x5dc38 (128 bytes) */
void _glIndexsv_CompExec(glContext, c)
  int glContext;
  short *c;
{
  ((int (*)())_glIndexsv_Comp)(glContext,c);
  *(float *)(glContext + 700) =
       (float)((double)CONCAT44(0x43300000,*c * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  return;
}

/* _glIndexub_Comp @ 0x5dc70 (120 bytes) */
int _glIndexub_Comp(glContext, c)
  undefined4 glContext;
  int c;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glIndex_ListExec_00110054,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,c * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  }
  return listRecord;
}

/* _glIndexub_Exec @ 0x5dce8 (68 bytes) */
void _glIndexub_Exec(glContext, c)
  int glContext;
  int c;
{
  *(float *)(glContext + 700) =
       (float)((double)CONCAT44(0x43300000,c * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  return;
}

/* _glIndexub_CompExec @ 0x5dd2c (56 bytes) */
void _glIndexub_CompExec(glContext, c)
  undefined4 glContext;
  undefined4 c;
{
  ((int (*)())_glIndexub_Comp)(glContext,c);
  ((void (*)())_glIndexub_Exec)(glContext,c);
  return;
}

/* _glIndexubv_Comp @ 0x5dd64 (124 bytes) */
int _glIndexubv_Comp(glContext, c)
  undefined4 glContext;
  byte *c;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glIndex_ListExec_00110054,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,
                                       (uint)*c * 0x100 + (uint)*c ^ 0x80000000) -
                     DOUBLE_00108d58);
  }
  return listRecord;
}

/* _glIndexubv_Exec @ 0x5dde0 (72 bytes) */
void _glIndexubv_Exec(glContext, c)
  int glContext;
  byte *c;
{
  *(float *)(glContext + 700) =
       (float)((double)CONCAT44(0x43300000,(uint)*c * 0x100 + (uint)*c ^ 0x80000000) -
              DOUBLE_00108d58);
  return;
}

/* _glIndexubv_CompExec @ 0x5de28 (56 bytes) */
void _glIndexubv_CompExec(glContext, c)
  undefined4 glContext;
  undefined4 c;
{
  ((int (*)())_glIndexubv_Comp)(glContext,c);
  ((void (*)())_glIndexubv_Exec)(glContext,c);
  return;
}

/* _glColorMaterial_ListExec @ 0x5de60 (44 bytes) */
int _glColorMaterial_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glColorMaterial_Exec)(glContext,*recordedArgs,recordedArgs[1]);
  return 8;
}

/* _glColorMaterial_Comp @ 0x5de8c (84 bytes) */
int _glColorMaterial_Comp(glContext, face, mode)
  undefined4 glContext;
  undefined4 face;
  undefined4 mode;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glColorMaterial_ListExec_00110060,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = mode;
    *listRecord = face;
  }
  return listRecord;
}

/* _glColorMaterial_Exec @ 0x5dee0 (188 bytes) */
void _glColorMaterial_Exec(glContext, face, mode)
  int glContext;
  uint face;
  uint mode;
{
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((face < 0x404) || ((0x405 < face && (face != 0x408)))) goto LAB_0005df54;
    if (mode != 0x1600) {
      if (mode < 0x1601) {
        if (2 < mode - 0x1200) {
LAB_0005df54:
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x500;
          goto LAB_0005df64;
        }
      }
      else if (mode != 0x1602) goto LAB_0005df54;
    }
    *(short *)(glContext + 0x30a4) = (short)face;
    *(short *)(glContext + 0x30a6) = (short)mode;
    _gleUpdateLightColorChangeFunc(glContext);
    *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x40000;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_0005df64:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glColorMaterial_CompExec @ 0x5df9c (64 bytes) */
void _glColorMaterial_CompExec(glContext, face, mode)
  undefined4 glContext;
  undefined4 face;
  undefined4 mode;
{
  ((int (*)())_glColorMaterial_Comp)(glContext,face,mode);
  ((void (*)())_glColorMaterial_Exec)(glContext,face,mode);
  return;
}

/* _glSecondaryColor3_ListExec @ 0x5dfdc (32 bytes) */
int _glSecondaryColor3_ListExec(glContext, recordedArgs)
  int glContext;
  undefined4 *recordedArgs;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = *recordedArgs;
  uVar2 = recordedArgs[1];
  *(undefined4 *)(glContext + 0x2c8) = recordedArgs[2];
  *(undefined4 *)(glContext + 0x2c0) = uVar1;
  *(undefined4 *)(glContext + 0x2c4) = uVar2;
  return 0xc;
}

/* _glSecondaryColor3b_Exec @ 0x5dffc (136 bytes) */
void _glSecondaryColor3b_Exec(glContext, red, green, blue)
  int glContext;
  uint red;
  uint green;
  uint blue;
{
  float fVar1;
  float fVar2;
  
  fVar2 = (float)((double)CONCAT44(0x43300000,blue ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  fVar1 = (float)((double)CONCAT44(0x43300000,green ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  *(float *)(glContext + 0x2c0) =
       (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) * FLOAT_00108e60
       + FLOAT_00108e64;
  *(float *)(glContext + 0x2c8) = fVar2;
  *(float *)(glContext + 0x2c4) = fVar1;
  return;
}

/* _glSecondaryColor3b_Comp @ 0x5e084 (204 bytes) */
int _glSecondaryColor3b_Comp(glContext, red, green, blue)
  undefined4 glContext;
  uint red;
  uint green;
  uint blue;
{
  double intToDoubleMagic;
  float fVar2;
  float fVar3;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar3 = FLOAT_00108e64;
  fVar2 = FLOAT_00108e60;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e60 + FLOAT_00108e64;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,green ^ 0x80000000) - intToDoubleMagic) * fVar2 + fVar3;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,blue ^ 0x80000000) - intToDoubleMagic) * fVar2 + fVar3;
  }
  return listRecord;
}

/* _glSecondaryColor3b_CompExec @ 0x5e150 (72 bytes) */
void _glSecondaryColor3b_CompExec(glContext, red, green, blue)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
{
  ((int (*)())_glSecondaryColor3b_Comp)(glContext,red,green,blue);
  ((void (*)())_glSecondaryColor3b_Exec)(glContext,red,green,blue);
  return;
}

/* _glSecondaryColor3bv_Exec @ 0x5e198 (160 bytes) */
double _glSecondaryColor3bv_Exec(glContext, v)
  int glContext;
  char *v;
{
  float greenConverted;
  float blueConverted;
  
  blueConverted = (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  greenConverted = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  *(float *)(glContext + 0x2c0) =
       (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e60 + FLOAT_00108e64;
  *(float *)(glContext + 0x2c8) = blueConverted;
  *(float *)(glContext + 0x2c4) = greenConverted;
  return;
}

/* _glSecondaryColor3bv_Comp @ 0x5e238 (220 bytes) */
int _glSecondaryColor3bv_Comp(glContext, v)
  undefined4 glContext;
  char *v;
{
  double intToDoubleMagic;
  float fVar2;
  float fVar3;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar3 = FLOAT_00108e64;
  fVar2 = FLOAT_00108e60;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e60 + FLOAT_00108e64;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - intToDoubleMagic) * fVar2 +
                fVar3;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - intToDoubleMagic) * fVar2 +
                fVar3;
  }
  return listRecord;
}

/* _glSecondaryColor3bv_CompExec @ 0x5e314 (56 bytes) */
void _glSecondaryColor3bv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glSecondaryColor3bv_Comp)(glContext,v);
  ((double (*)())_glSecondaryColor3bv_Exec)(glContext,v);
  return;
}

/* _glSecondaryColor3s_Exec @ 0x5e34c (136 bytes) */
void _glSecondaryColor3s_Exec(glContext, red, green, blue)
  int glContext;
  uint red;
  uint green;
  uint blue;
{
  float fVar1;
  float fVar2;
  
  fVar2 = (float)((double)CONCAT44(0x43300000,blue ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  fVar1 = (float)((double)CONCAT44(0x43300000,green ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  *(float *)(glContext + 0x2c0) =
       (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) * FLOAT_00108e70
       + FLOAT_00108e74;
  *(float *)(glContext + 0x2c8) = fVar2;
  *(float *)(glContext + 0x2c4) = fVar1;
  return;
}

/* _glSecondaryColor3s_Comp @ 0x5e3d4 (204 bytes) */
int _glSecondaryColor3s_Comp(glContext, red, green, blue)
  undefined4 glContext;
  uint red;
  uint green;
  uint blue;
{
  double intToDoubleMagic;
  float fVar2;
  float fVar3;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar3 = FLOAT_00108e74;
  fVar2 = FLOAT_00108e70;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e70 + FLOAT_00108e74;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,green ^ 0x80000000) - intToDoubleMagic) * fVar2 + fVar3;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,blue ^ 0x80000000) - intToDoubleMagic) * fVar2 + fVar3;
  }
  return listRecord;
}

/* _glSecondaryColor3s_CompExec @ 0x5e4a0 (72 bytes) */
void _glSecondaryColor3s_CompExec(glContext, red, green, blue)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
{
  ((int (*)())_glSecondaryColor3s_Comp)(glContext,red,green,blue);
  ((void (*)())_glSecondaryColor3s_Exec)(glContext,red,green,blue);
  return;
}

/* _glSecondaryColor3sv_Exec @ 0x5e4e8 (148 bytes) */
double _glSecondaryColor3sv_Exec(glContext, v)
  int glContext;
  short *v;
{
  float greenConverted;
  float blueConverted;
  
  blueConverted = (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  greenConverted = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  *(float *)(glContext + 0x2c0) =
       (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e70 + FLOAT_00108e74;
  *(float *)(glContext + 0x2c8) = blueConverted;
  *(float *)(glContext + 0x2c4) = greenConverted;
  return;
}

/* _glSecondaryColor3sv_Comp @ 0x5e57c (208 bytes) */
int _glSecondaryColor3sv_Comp(glContext, v)
  undefined4 glContext;
  short *v;
{
  double intToDoubleMagic;
  float channelScale;
  float channelBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  channelBias = FLOAT_00108e74;
  channelScale = FLOAT_00108e70;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e70 + FLOAT_00108e74;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - intToDoubleMagic) * channelScale +
                channelBias;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - intToDoubleMagic) * channelScale +
                channelBias;
  }
  return listRecord;
}

/* _glSecondaryColor3sv_CompExec @ 0x5e64c (56 bytes) */
void _glSecondaryColor3sv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glSecondaryColor3sv_Comp)(glContext,v);
  ((double (*)())_glSecondaryColor3sv_Exec)(glContext,v);
  return;
}

/* _glSecondaryColor3i_Exec @ 0x5e684 (136 bytes) */
void _glSecondaryColor3i_Exec(glContext, red, green, blue)
  int glContext;
  uint red;
  uint green;
  uint blue;
{
  float greenConverted;
  float blueConverted;
  
  blueConverted = (float)((double)CONCAT44(0x43300000,blue ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  greenConverted = (float)((double)CONCAT44(0x43300000,green ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  *(float *)(glContext + 0x2c0) =
       (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) * FLOAT_00108e68
       + FLOAT_00108e6c;
  *(float *)(glContext + 0x2c8) = blueConverted;
  *(float *)(glContext + 0x2c4) = greenConverted;
  return;
}

/* _glSecondaryColor3i_Comp @ 0x5e70c (204 bytes) */
int _glSecondaryColor3i_Comp(glContext, red, green, blue)
  undefined4 glContext;
  uint red;
  uint green;
  uint blue;
{
  double intToDoubleMagic;
  float channelScale;
  float channelBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  channelBias = FLOAT_00108e6c;
  channelScale = FLOAT_00108e68;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e68 + FLOAT_00108e6c;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,green ^ 0x80000000) - intToDoubleMagic) * channelScale + channelBias;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,blue ^ 0x80000000) - intToDoubleMagic) * channelScale + channelBias;
  }
  return listRecord;
}

/* _glSecondaryColor3i_CompExec @ 0x5e7d8 (72 bytes) */
void _glSecondaryColor3i_CompExec(glContext, red, green, blue)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
{
  ((int (*)())_glSecondaryColor3i_Comp)(glContext,red,green,blue);
  ((void (*)())_glSecondaryColor3i_Exec)(glContext,red,green,blue);
  return;
}

/* _glSecondaryColor3iv_Exec @ 0x5e820 (148 bytes) */
double _glSecondaryColor3iv_Exec(glContext, v)
  int glContext;
  uint *v;
{
  float fVar1;
  float fVar2;
  
  fVar2 = (float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  fVar1 = (float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  *(float *)(glContext + 0x2c0) =
       (float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e68 + FLOAT_00108e6c;
  *(float *)(glContext + 0x2c8) = fVar2;
  *(float *)(glContext + 0x2c4) = fVar1;
  return;
}

/* _glSecondaryColor3iv_Comp @ 0x5e8b4 (208 bytes) */
int _glSecondaryColor3iv_Comp(glContext, v)
  undefined4 glContext;
  uint *v;
{
  double intToDoubleMagic;
  float fVar2;
  float fVar3;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar3 = FLOAT_00108e6c;
  fVar2 = FLOAT_00108e68;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e68 + FLOAT_00108e6c;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - intToDoubleMagic) * fVar2 +
                fVar3;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - intToDoubleMagic) * fVar2 +
                fVar3;
  }
  return listRecord;
}

/* _glSecondaryColor3iv_CompExec @ 0x5e984 (56 bytes) */
void _glSecondaryColor3iv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glSecondaryColor3iv_Comp)(glContext,v);
  ((double (*)())_glSecondaryColor3iv_Exec)(glContext,v);
  return;
}

