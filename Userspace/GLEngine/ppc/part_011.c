#include "decls.h"

/* _glColor3s_Comp @ 0x5af7c (204 bytes) */
int _glColor3s_Comp(glContext, red, green, blue)
  undefined4 glContext;
  uint red;
  uint green;
  uint blue;
{
  double intToDoubleMagic;
  float channelScale;
  float channelBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  channelBias = FLOAT_00108e74;
  channelScale = FLOAT_00108e70;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e70 + FLOAT_00108e74;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,green ^ 0x80000000) - intToDoubleMagic) * channelScale + channelBias;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,blue ^ 0x80000000) - intToDoubleMagic) * channelScale + channelBias;
  }
  return listRecord;
}

/* _glColor3s_Exec @ 0x5b048 (196 bytes) */
void _glColor3s_Exec(glContext, red, green, blue)
  int glContext;
  uint red;
  uint green;
  uint blue;
{
  float redValue;
  float channelScale;
  float channelBias;
  double greenConverted;
  double blueConverted;
  
  channelBias = FLOAT_00108e74;
  channelScale = FLOAT_00108e70;
  blueConverted = (double)CONCAT44(0x43300000,blue ^ 0x80000000) - DOUBLE_00108d58;
  greenConverted = (double)CONCAT44(0x43300000,green ^ 0x80000000) - DOUBLE_00108d58;
  redValue = (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x2a0) = redValue;
  *(float *)(glContext + 0x2a8) = (float)blueConverted * channelScale + channelBias;
  *(float *)(glContext + 0x2a4) = (float)greenConverted * channelScale + channelBias;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  }
  return;
}

/* _glColor3s_CompExec @ 0x5b10c (72 bytes) */
void _glColor3s_CompExec(glContext, red, green, blue)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
{
  ((int (*)())_glColor3s_Comp)(glContext,red,green,blue);
  ((void (*)())_glColor3s_Exec)(glContext,red,green,blue);
  return;
}

/* _glColor3sv_Comp @ 0x5b154 (208 bytes) */
int _glColor3sv_Comp(glContext, v)
  undefined4 glContext;
  short *v;
{
  double intToDoubleMagic;
  float fVar2;
  float fVar3;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  fVar3 = FLOAT_00108e74;
  fVar2 = FLOAT_00108e70;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e70 + FLOAT_00108e74;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - intToDoubleMagic) * fVar2 +
                fVar3;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - intToDoubleMagic) * fVar2 +
                fVar3;
  }
  return listRecord;
}

/* _glColor3sv_Exec @ 0x5b224 (208 bytes) */
double _glColor3sv_Exec(glContext, v)
  int glContext;
  short *v;
{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  double dVar5;
  
  fVar3 = FLOAT_00108e74;
  fVar2 = FLOAT_00108e70;
  dVar5 = (double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - DOUBLE_00108d58;
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x2a0) = fVar1;
  *(float *)(glContext + 0x2a8) = (float)dVar5 * fVar2 + fVar3;
  *(float *)(glContext + 0x2a4) = (float)dVar4 * fVar2 + fVar3;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  }
  return;
}

/* _glColor3sv_CompExec @ 0x5b2f4 (56 bytes) */
void _glColor3sv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glColor3sv_Comp)(glContext,v);
  ((double (*)())_glColor3sv_Exec)(glContext,v);
  return;
}

/* _glColor3ub_Comp @ 0x5b32c (120 bytes) */
int _glColor3ub_Comp(glContext, red, green, blue)
  int glContext;
  int red;
  int green;
  int blue;
{
  undefined4 *listRecord;
  int glContextPtr4674;
  
  glContextPtr4674 = *(int *)(glContext + 0x4674);
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = *(undefined4 *)(glContextPtr4674 + red * 4);
    listRecord[1] = *(undefined4 *)(green * 4 + glContextPtr4674);
    listRecord[2] = *(undefined4 *)(glContextPtr4674 + blue * 4);
  }
  return listRecord;
}

/* _glColor3ub_CompExec @ 0x5b3f0 (148 bytes) */
void _glColor3ub_CompExec(glContext, red, green, blue)
  int glContext;
  int red;
  int green;
  int blue;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int glContextWord4674;
  
  ((int (*)())_glColor3ub_Comp)(glContext,red,green,blue);
  glContextWord4674 = *(int *)(glContext + 0x4674);
  uVar1 = *(undefined4 *)(blue * 4 + glContextWord4674);
  uVar2 = *(undefined4 *)(green * 4 + glContextWord4674);
  *(undefined4 *)(glContext + 0x2a0) = *(undefined4 *)(red * 4 + glContextWord4674);
  *(undefined4 *)(glContext + 0x2a4) = uVar2;
  *(undefined4 *)(glContext + 0x2a8) = uVar1;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  if (*(char *)(glContext + 0x4df8) == '\0') {
    return;
  }
                    
                    
  (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  return;
}

/* _glColor3ubv_Comp @ 0x5b438 (124 bytes) */
int _glColor3ubv_Comp(glContext, v)
  int glContext;
  byte *v;
{
  undefined4 *listRecord;
  int glContextPtr4674;
  
  glContextPtr4674 = *(int *)(glContext + 0x4674);
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = *(undefined4 *)(glContextPtr4674 + (uint)*v * 4);
    listRecord[1] = *(undefined4 *)(glContextPtr4674 + (uint)v[1] * 4);
    listRecord[2] = *(undefined4 *)(glContextPtr4674 + (uint)v[2] * 4);
  }
  return listRecord;
}

/* _glColor3ubv_Exec @ 0x5b4b4 (88 bytes) */
double _glColor3ubv_Exec(glContext, v)
  int glContext;
  byte *v;
{
  undefined4 blueBits;
  undefined4 greenBits;
  int glContextPtr4674;
  
  glContextPtr4674 = *(int *)(glContext + 0x4674);
  blueBits = *(undefined4 *)(glContextPtr4674 + (uint)v[2] * 4);
  greenBits = *(undefined4 *)((uint)v[1] * 4 + glContextPtr4674);
  *(undefined4 *)(glContext + 0x2a0) = *(undefined4 *)((uint)*v * 4 + glContextPtr4674);
  *(undefined4 *)(glContext + 0x2a4) = greenBits;
  *(undefined4 *)(glContext + 0x2a8) = blueBits;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  if (*(char *)(glContext + 0x4df8) == '\0') {
    return;
  }
                    
                    
  (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  return;
}

/* _glColor3ubv_CompExec @ 0x5b50c (56 bytes) */
void _glColor3ubv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glColor3ubv_Comp)(glContext,v);
  ((double (*)())_glColor3ubv_Exec)(glContext,v);
  return;
}

/* _glColor3ui_Comp @ 0x5b544 (184 bytes) */
int _glColor3ui_Comp(glContext, red, green, blue)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
{
  double intToDoubleBias;
  float channelScale;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  channelScale = FLOAT_00108e6c;
  intToDoubleBias = DOUBLE_00108d70;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,red) - DOUBLE_00108d70) * FLOAT_00108e6c;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,green) - intToDoubleBias) * channelScale;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,blue) - intToDoubleBias) * channelScale;
  }
  return listRecord;
}

/* _glColor3ui_Exec @ 0x5b5fc (176 bytes) */
void _glColor3ui_Exec(glContext, red, green, blue)
  int glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
{
  float channelScale;
  double redDouble;
  double greenDouble;
  double blueDouble;
  
  channelScale = FLOAT_00108e6c;
  redDouble = (double)CONCAT44(0x43300000,red) - DOUBLE_00108d70;
  blueDouble = (double)CONCAT44(0x43300000,blue) - DOUBLE_00108d70;
  greenDouble = (double)CONCAT44(0x43300000,green) - DOUBLE_00108d70;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x2a0) = (float)redDouble * channelScale;
  *(float *)(glContext + 0x2a8) = (float)blueDouble * channelScale;
  *(float *)(glContext + 0x2a4) = (float)greenDouble * channelScale;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  }
  return;
}

/* _glColor3ui_CompExec @ 0x5b6ac (72 bytes) */
void _glColor3ui_CompExec(glContext, red, green, blue)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
{
  ((int (*)())_glColor3ui_Comp)(glContext,red,green,blue);
  ((void (*)())_glColor3ui_Exec)(glContext,red,green,blue);
  return;
}

/* _glColor3uiv_Comp @ 0x5b6f4 (188 bytes) */
int _glColor3uiv_Comp(glContext, v)
  undefined4 glContext;
  undefined4 *v;
{
  double intToDoubleBias;
  float channelScale;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  channelScale = FLOAT_00108e6c;
  intToDoubleBias = DOUBLE_00108d70;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,*v) - DOUBLE_00108d70) * FLOAT_00108e6c;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,v[1]) - intToDoubleBias) * channelScale;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,v[2]) - intToDoubleBias) * channelScale;
  }
  return listRecord;
}

/* _glColor3uiv_Exec @ 0x5b7b0 (188 bytes) */
double _glColor3uiv_Exec(glContext, v)
  int glContext;
  undefined4 *v;
{
  float channelScale;
  double redConverted;
  double greenConverted;
  double blueConverted;
  
  channelScale = FLOAT_00108e6c;
  redConverted = (double)CONCAT44(0x43300000,*v) - DOUBLE_00108d70;
  blueConverted = (double)CONCAT44(0x43300000,v[2]) - DOUBLE_00108d70;
  greenConverted = (double)CONCAT44(0x43300000,v[1]) - DOUBLE_00108d70;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x2a0) = (float)redConverted * channelScale;
  *(float *)(glContext + 0x2a8) = (float)blueConverted * channelScale;
  *(float *)(glContext + 0x2a4) = (float)greenConverted * channelScale;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  }
  return;
}

/* _glColor3uiv_CompExec @ 0x5b86c (56 bytes) */
void _glColor3uiv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glColor3uiv_Comp)(glContext,v);
  ((double (*)())_glColor3uiv_Exec)(glContext,v);
  return;
}

/* _glColor3us_Comp @ 0x5b8a4 (192 bytes) */
int _glColor3us_Comp(glContext, red, green, blue)
  undefined4 glContext;
  uint red;
  uint green;
  uint blue;
{
  float channelScale;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  channelScale = FLOAT_00108e74;
  if (listRecord != (float *)0x0) {
    *listRecord = (GH_U2F((unsigned int)((red | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
    listRecord[1] = (GH_U2F((unsigned int)((green | 0x4b000000))) - 8388608.0) * channelScale;
    listRecord[2] = (GH_U2F((unsigned int)((blue | 0x4b000000))) - 8388608.0) * channelScale;
  }
  return listRecord;
}

/* _glColor3us_Exec @ 0x5b964 (184 bytes) */
double _glColor3us_Exec(int glContext,uint red,uint green,uint blue,double forwardedFloatArg1ThenCalleeResult,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float redComponent;
  float blueComponent;
  float channelScale;
  
  channelScale = FLOAT_00108e74;
  redComponent = (GH_U2F((unsigned int)((red | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  blueComponent = (GH_U2F((unsigned int)((blue | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x2a0) = redComponent;
  *(float *)(glContext + 0x2a8) = blueComponent;
  *(float *)(glContext + 0x2a4) = (GH_U2F((unsigned int)((green | 0x4b000000))) - 8388608.0) * channelScale;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    forwardedFloatArg1ThenCalleeResult = (double)(**(double ( **)(int,int))(glContext + 0x4de0))(glContext, glContext + 0x2a0);
  }
  return forwardedFloatArg1ThenCalleeResult;
}

/* _glColor3us_CompExec @ 0x5ba1c (72 bytes) */
void _glColor3us_CompExec(glContext, red, green, blue)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
{
  unsigned int ghidra_home[8] = { glContext, red, green, blue, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double incomingFpr1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double in_f8;
  
  ((int (*)())_glColor3us_Comp)(glContext,red,green,blue);
  ((double (*)())_glColor3us_Exec)(glContext,red,green,blue,incomingFpr1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,
                   in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                   (*(double *)((unsigned char *)ghidra_home + 0)),(*(double *)((unsigned char *)ghidra_home + 8)),(*(double *)((unsigned char *)ghidra_home + 16)));
  return;
}

/* _glColor3usv_Comp @ 0x5ba64 (196 bytes) */
int _glColor3usv_Comp(glContext, v)
  undefined4 glContext;
  ushort *v;
{
  float fVar1;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  fVar1 = FLOAT_00108e74;
  if (listRecord != (float *)0x0) {
    *listRecord = (GH_U2F((unsigned int)((*v | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
    listRecord[1] = (GH_U2F((unsigned int)((v[1] | 0x4b000000))) - 8388608.0) * fVar1;
    listRecord[2] = (GH_U2F((unsigned int)((v[2] | 0x4b000000))) - 8388608.0) * fVar1;
  }
  return listRecord;
}

/* _glColor3usv_Exec @ 0x5bb28 (196 bytes) */
double _glColor3usv_Exec(int glContext,ushort *v,double fparam_1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  ushort uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar4 = FLOAT_00108e74;
  uVar1 = v[1];
  fVar2 = (GH_U2F((unsigned int)((*v | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  fVar3 = (GH_U2F((unsigned int)((v[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x2a0) = fVar2;
  *(float *)(glContext + 0x2a8) = fVar3;
  *(float *)(glContext + 0x2a4) = (GH_U2F((unsigned int)((uVar1 | 0x4b000000))) - 8388608.0) * fVar4;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    fparam_1 = (double)(**(double ( **)(int,int))(glContext + 0x4de0))(glContext, glContext + 0x2a0);
  }
  return fparam_1;
}

/* _glColor3usv_CompExec @ 0x5bbec (56 bytes) */
void _glColor3usv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  unsigned int ghidra_home[8] = { glContext, v, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glColor3usv_Comp)(glContext,v);
  ((double (*)())_glColor3usv_Exec)(glContext,v,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                    (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)((unsigned char *)ghidra_home + 0)),
                    (*(double *)((unsigned char *)ghidra_home + 8)),(*(double *)((unsigned char *)ghidra_home + 16)));
  return;
}

/* _glColor4b_Comp @ 0x5bc24 (240 bytes) */
int _glColor4b_Comp(glContext, red, green, blue, alpha)
  undefined4 glContext;
  uint red;
  uint green;
  uint blue;
  uint alpha;
{
  double intToDoubleMagic;
  float fVar2;
  float fVar3;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor4_ListExec_00110058,0x10);
  fVar3 = FLOAT_00108e64;
  fVar2 = FLOAT_00108e60;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e60 + FLOAT_00108e64;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,green ^ 0x80000000) - intToDoubleMagic) * fVar2 + fVar3;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,blue ^ 0x80000000) - intToDoubleMagic) * fVar2 + fVar3;
    listRecord[3] = (float)((double)CONCAT44(0x43300000,alpha ^ 0x80000000) - intToDoubleMagic) * fVar2 + fVar3;
  }
  return listRecord;
}

/* _glColor4b_Exec @ 0x5bd14 (216 bytes) */
void _glColor4b_Exec(glContext, red, green, blue, alpha)
  int glContext;
  uint red;
  uint green;
  uint blue;
  uint alpha;
{
  float blueFloat;
  float greenFloat;
  float alphaFloat;
  
  greenFloat = (float)((double)CONCAT44(0x43300000,green ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  alphaFloat = (float)((double)CONCAT44(0x43300000,alpha ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  blueFloat = (float)((double)CONCAT44(0x43300000,blue ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  *(float *)(glContext + 0x2a0) =
       (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) * FLOAT_00108e60
       + FLOAT_00108e64;
  *(float *)(glContext + 0x2a4) = greenFloat;
  *(float *)(glContext + 0x2ac) = alphaFloat;
  *(float *)(glContext + 0x2a8) = blueFloat;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  }
  return;
}

/* _glColor4b_CompExec @ 0x5bdec (80 bytes) */
void _glColor4b_CompExec(glContext, red, green, blue, alpha)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
  undefined4 alpha;
{
  ((int (*)())_glColor4b_Comp)(glContext,red,green,blue,alpha);
  ((void (*)())_glColor4b_Exec)(glContext,red,green,blue,alpha);
  return;
}

/* _glColor4bv_Comp @ 0x5be3c (260 bytes) */
int _glColor4bv_Comp(glContext, v)
  undefined4 glContext;
  char *v;
{
  double intToDoubleMagic;
  float channelScale;
  float channelBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor4_ListExec_00110058,0x10);
  channelBias = FLOAT_00108e64;
  channelScale = FLOAT_00108e60;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e60 + FLOAT_00108e64;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - intToDoubleMagic) * channelScale +
                channelBias;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - intToDoubleMagic) * channelScale +
                channelBias;
    listRecord[3] = (float)((double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) - intToDoubleMagic) * channelScale +
                channelBias;
  }
  return listRecord;
}

/* _glColor4bv_Exec @ 0x5bf40 (248 bytes) */
double _glColor4bv_Exec(glContext, v)
  int glContext;
  char *v;
{
  float blueComponent;
  float greenComponent;
  float alphaComponent;
  
  greenComponent = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  alphaComponent = (float)((double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  blueComponent = (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  *(float *)(glContext + 0x2a0) =
       (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e60 + FLOAT_00108e64;
  *(float *)(glContext + 0x2a4) = greenComponent;
  *(float *)(glContext + 0x2ac) = alphaComponent;
  *(float *)(glContext + 0x2a8) = blueComponent;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  }
  return;
}

/* _glColor4bv_CompExec @ 0x5c038 (56 bytes) */
void _glColor4bv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glColor4bv_Comp)(glContext,v);
  ((double (*)())_glColor4bv_Exec)(glContext,v);
  return;
}

/* _glColor4d_Comp @ 0x5c070 (108 bytes) */
void _glColor4d_Comp(undefined4 glContext,double red,double green,double blue,double alpha)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor4_ListExec_00110058,0x10);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)red;
    listRecord[1] = (float)green;
    listRecord[2] = (float)blue;
    listRecord[3] = (float)alpha;
  }
  return;
}

/* _glColor4d_CompExec @ 0x5c0dc (96 bytes) */
void _glColor4d_CompExec(undefined4 glContext,double red,double green,double blue,double alpha)
{
  ((void (*)())_glColor4d_Comp)(glContext,red,green,blue,alpha);
  ((void (*)())_glColor4d_Exec)(glContext,red,green,blue,alpha);
  return;
}

/* _glColor4dv_Comp @ 0x5c13c (120 bytes) */
int _glColor4dv_Comp(glContext, v)
  undefined4 glContext;
  double *v;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor4_ListExec_00110058,0x10);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)*v;
    listRecord[1] = (float)v[1];
    listRecord[2] = (float)v[2];
    listRecord[3] = (float)v[3];
  }
  return listRecord;
}

/* _glColor4dv_Exec @ 0x5c1b4 (76 bytes) */
double _glColor4dv_Exec(glContext, v)
  int glContext;
  double *v;
{
  double dVar1;
  double dVar2;
  double dVar3;
  
  dVar1 = *v;
  dVar3 = v[1];
  dVar2 = v[2];
  *(float *)(glContext + 0x2ac) = (float)v[3];
  *(float *)(glContext + 0x2a0) = (float)dVar1;
  *(float *)(glContext + 0x2a4) = (float)dVar3;
  *(float *)(glContext + 0x2a8) = (float)dVar2;
  if (*(char *)(glContext + 0x4df8) == '\0') {
    return;
  }
                    
                    
  (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  return;
}

/* _glColor4dv_CompExec @ 0x5c200 (56 bytes) */
void _glColor4dv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glColor4dv_Comp)(glContext,v);
  ((double (*)())_glColor4dv_Exec)(glContext,v);
  return;
}

/* _glColor4f_ColorMat_Exec @ 0x5c238 (32 bytes) */
void _glColor4f_ColorMat_Exec(int glContext,float red,float green,float blue,float alpha)
{
  *(float *)(glContext + 0x2a0) = (float)red;
  *(float *)(glContext + 0x2a4) = (float)green;
  *(float *)(glContext + 0x2a8) = (float)blue;
  *(float *)(glContext + 0x2ac) = (float)alpha;
                    
                    
  (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  return;
}

/* _glColor4fv_Comp @ 0x5c258 (104 bytes) */
int _glColor4fv_Comp(glContext, v)
  undefined4 glContext;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glColor4_ListExec_00110058,0x10);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = *v;
    listRecord[1] = v[1];
    listRecord[2] = v[2];
    listRecord[3] = v[3];
  }
  return listRecord;
}

/* _glColor4fv_ColorMat_Exec @ 0x5c2c0 (48 bytes) */
double _glColor4fv_ColorMat_Exec(glContext, v)
  int glContext;
  undefined4 *v;
{
  undefined4 alphaBits;
  undefined4 greenBits;
  undefined4 blueBits;
  
  alphaBits = v[3];
  greenBits = v[1];
  blueBits = v[2];
  *(undefined4 *)(glContext + 0x2a0) = *v;
  *(undefined4 *)(glContext + 0x2a4) = greenBits;
  *(undefined4 *)(glContext + 0x2a8) = blueBits;
  *(undefined4 *)(glContext + 0x2ac) = alphaBits;
                    
                    
  (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  return;
}

/* _glColor4fv_CompExec @ 0x5c2f0 (96 bytes) */
void _glColor4fv_CompExec(glContext, v)
  int glContext;
  undefined4 v;
{
  ((int (*)())_glColor4fv_Comp)(glContext,v);
  if (*(char *)(glContext + 0x4df8) != '\0') {
    ((double (*)())_glColor4fv_ColorMat_Exec)(glContext,v);
    return;
  }
  _glColor4fv_NoColorMat_Exec(glContext,v);
  return;
}

/* _glColor4i_Comp @ 0x5c350 (240 bytes) */
int _glColor4i_Comp(glContext, red, green, blue, alpha)
  undefined4 glContext;
  uint red;
  uint green;
  uint blue;
  uint alpha;
{
  double intToDoubleMagic;
  float channelScale;
  float channelBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor4_ListExec_00110058,0x10);
  channelBias = FLOAT_00108e6c;
  channelScale = FLOAT_00108e68;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e68 + FLOAT_00108e6c;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,green ^ 0x80000000) - intToDoubleMagic) * channelScale + channelBias;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,blue ^ 0x80000000) - intToDoubleMagic) * channelScale + channelBias;
    listRecord[3] = (float)((double)CONCAT44(0x43300000,alpha ^ 0x80000000) - intToDoubleMagic) * channelScale + channelBias;
  }
  return listRecord;
}

/* _glColor4i_Exec @ 0x5c440 (216 bytes) */
void _glColor4i_Exec(glContext, red, green, blue, alpha)
  int glContext;
  uint red;
  uint green;
  uint blue;
  uint alpha;
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)((double)CONCAT44(0x43300000,green ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  fVar3 = (float)((double)CONCAT44(0x43300000,alpha ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  fVar1 = (float)((double)CONCAT44(0x43300000,blue ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  *(float *)(glContext + 0x2a0) =
       (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) * FLOAT_00108e68
       + FLOAT_00108e6c;
  *(float *)(glContext + 0x2a4) = fVar2;
  *(float *)(glContext + 0x2ac) = fVar3;
  *(float *)(glContext + 0x2a8) = fVar1;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  }
  return;
}

/* _glColor4i_CompExec @ 0x5c518 (80 bytes) */
void _glColor4i_CompExec(glContext, red, green, blue, alpha)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
  undefined4 alpha;
{
  ((int (*)())_glColor4i_Comp)(glContext,red,green,blue,alpha);
  ((void (*)())_glColor4i_Exec)(glContext,red,green,blue,alpha);
  return;
}

/* _glColor4iv_Comp @ 0x5c568 (244 bytes) */
int _glColor4iv_Comp(glContext, v)
  undefined4 glContext;
  uint *v;
{
  double intToDoubleMagic;
  float fVar2;
  float fVar3;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor4_ListExec_00110058,0x10);
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
    listRecord[3] = (float)((double)CONCAT44(0x43300000,v[3] ^ 0x80000000) - intToDoubleMagic) * fVar2 +
                fVar3;
  }
  return listRecord;
}

/* _glColor4iv_Exec @ 0x5c65c (232 bytes) */
double _glColor4iv_Exec(glContext, v)
  int glContext;
  uint *v;
{
  float blueFloat;
  float greenFloat;
  float alphaFloat;
  
  greenFloat = (float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  alphaFloat = (float)((double)CONCAT44(0x43300000,v[3] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  blueFloat = (float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  *(float *)(glContext + 0x2a0) =
       (float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e68 + FLOAT_00108e6c;
  *(float *)(glContext + 0x2a4) = greenFloat;
  *(float *)(glContext + 0x2ac) = alphaFloat;
  *(float *)(glContext + 0x2a8) = blueFloat;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  }
  return;
}

/* _glColor4iv_CompExec @ 0x5c744 (56 bytes) */
void _glColor4iv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glColor4iv_Comp)(glContext,v);
  ((double (*)())_glColor4iv_Exec)(glContext,v);
  return;
}

/* _glColor4s_Comp @ 0x5c77c (240 bytes) */
int _glColor4s_Comp(glContext, red, green, blue, alpha)
  undefined4 glContext;
  uint red;
  uint green;
  uint blue;
  uint alpha;
{
  double intToDoubleMagic;
  float channelScale;
  float channelBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor4_ListExec_00110058,0x10);
  channelBias = FLOAT_00108e74;
  channelScale = FLOAT_00108e70;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e70 + FLOAT_00108e74;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,green ^ 0x80000000) - intToDoubleMagic) * channelScale + channelBias;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,blue ^ 0x80000000) - intToDoubleMagic) * channelScale + channelBias;
    listRecord[3] = (float)((double)CONCAT44(0x43300000,alpha ^ 0x80000000) - intToDoubleMagic) * channelScale + channelBias;
  }
  return listRecord;
}

/* _glColor4s_Exec @ 0x5c86c (216 bytes) */
void _glColor4s_Exec(glContext, red, green, blue, alpha)
  int glContext;
  uint red;
  uint green;
  uint blue;
  uint alpha;
{
  float blueComponent;
  float greenComponent;
  float alphaComponent;
  
  greenComponent = (float)((double)CONCAT44(0x43300000,green ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  alphaComponent = (float)((double)CONCAT44(0x43300000,alpha ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  blueComponent = (float)((double)CONCAT44(0x43300000,blue ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  *(float *)(glContext + 0x2a0) =
       (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) * FLOAT_00108e70
       + FLOAT_00108e74;
  *(float *)(glContext + 0x2a4) = greenComponent;
  *(float *)(glContext + 0x2ac) = alphaComponent;
  *(float *)(glContext + 0x2a8) = blueComponent;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  }
  return;
}

/* _glColor4s_CompExec @ 0x5c944 (80 bytes) */
void _glColor4s_CompExec(glContext, red, green, blue, alpha)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
  undefined4 alpha;
{
  ((int (*)())_glColor4s_Comp)(glContext,red,green,blue,alpha);
  ((void (*)())_glColor4s_Exec)(glContext,red,green,blue,alpha);
  return;
}

/* _glColor4sv_Comp @ 0x5c994 (244 bytes) */
int _glColor4sv_Comp(glContext, v)
  undefined4 glContext;
  short *v;
{
  double intToDoubleMagic;
  float channelScale;
  float channelBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor4_ListExec_00110058,0x10);
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
    listRecord[3] = (float)((double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) - intToDoubleMagic) * channelScale +
                channelBias;
  }
  return listRecord;
}

/* _glColor4sv_Exec @ 0x5ca88 (232 bytes) */
double _glColor4sv_Exec(glContext, v)
  int glContext;
  short *v;
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  fVar3 = (float)((double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  *(float *)(glContext + 0x2a0) =
       (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e70 + FLOAT_00108e74;
  *(float *)(glContext + 0x2a4) = fVar2;
  *(float *)(glContext + 0x2ac) = fVar3;
  *(float *)(glContext + 0x2a8) = fVar1;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  }
  return;
}

/* _glColor4sv_CompExec @ 0x5cb70 (56 bytes) */
void _glColor4sv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glColor4sv_Comp)(glContext,v);
  ((double (*)())_glColor4sv_Exec)(glContext,v);
  return;
}

/* _glColor4ub_Comp @ 0x5cba8 (136 bytes) */
int _glColor4ub_Comp(glContext, red, green, blue, alpha)
  int glContext;
  int red;
  int green;
  int blue;
  int alpha;
{
  undefined4 *listRecord;
  int glContextPtr4674;
  
  glContextPtr4674 = *(int *)(glContext + 0x4674);
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glColor4_ListExec_00110058,0x10);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = *(undefined4 *)(glContextPtr4674 + red * 4);
    listRecord[1] = *(undefined4 *)(green * 4 + glContextPtr4674);
    listRecord[2] = *(undefined4 *)(glContextPtr4674 + blue * 4);
    listRecord[3] = *(undefined4 *)(alpha * 4 + glContextPtr4674);
  }
  return listRecord;
}

/* _glColor4ub_CompExec @ 0x5cc30 (80 bytes) */
void _glColor4ub_CompExec(glContext, red, green, blue, alpha)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
  undefined4 alpha;
{
  ((int (*)())_glColor4ub_Comp)(glContext,red,green,blue,alpha);
  _glColor4ub_Exec(glContext,red,green,blue,alpha);
  return;
}

/* _glColor4ubv_Comp @ 0x5cc80 (140 bytes) */
int _glColor4ubv_Comp(glContext, v)
  int glContext;
  byte *v;
{
  undefined4 *listRecord;
  int glContextPtr4674;
  
  glContextPtr4674 = *(int *)(glContext + 0x4674);
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glColor4_ListExec_00110058,0x10);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = *(undefined4 *)(glContextPtr4674 + (uint)*v * 4);
    listRecord[1] = *(undefined4 *)(glContextPtr4674 + (uint)v[1] * 4);
    listRecord[2] = *(undefined4 *)(glContextPtr4674 + (uint)v[2] * 4);
    listRecord[3] = *(undefined4 *)(glContextPtr4674 + (uint)v[3] * 4);
  }
  return listRecord;
}

/* _glColor4ubv_Exec @ 0x5cd0c (96 bytes) */
double _glColor4ubv_Exec(glContext, v)
  int glContext;
  byte *v;
{
  undefined4 alphaValue;
  undefined4 greenValue;
  undefined4 blueValue;
  int glContextPtr4674;
  
  glContextPtr4674 = *(int *)(glContext + 0x4674);
  alphaValue = *(undefined4 *)(glContextPtr4674 + (uint)v[3] * 4);
  greenValue = *(undefined4 *)((uint)v[1] * 4 + glContextPtr4674);
  blueValue = *(undefined4 *)((uint)v[2] * 4 + glContextPtr4674);
  *(undefined4 *)(glContext + 0x2a0) = *(undefined4 *)((uint)*v * 4 + glContextPtr4674);
  *(undefined4 *)(glContext + 0x2a4) = greenValue;
  *(undefined4 *)(glContext + 0x2a8) = blueValue;
  *(undefined4 *)(glContext + 0x2ac) = alphaValue;
  if (*(char *)(glContext + 0x4df8) == '\0') {
    return;
  }
                    
                    
  (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  return;
}

/* _glColor4ubv_CompExec @ 0x5cd6c (56 bytes) */
void _glColor4ubv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glColor4ubv_Comp)(glContext,v);
  ((double (*)())_glColor4ubv_Exec)(glContext,v);
  return;
}

/* _glColor4ui_Comp @ 0x5cda4 (216 bytes) */
int _glColor4ui_Comp(glContext, red, green, blue, alpha)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
  undefined4 alpha;
{
  double dVar1;
  float fVar2;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor4_ListExec_00110058,0x10);
  fVar2 = FLOAT_00108e6c;
  dVar1 = DOUBLE_00108d70;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,red) - DOUBLE_00108d70) * FLOAT_00108e6c;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,green) - dVar1) * fVar2;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,blue) - dVar1) * fVar2;
    listRecord[3] = (float)((double)CONCAT44(0x43300000,alpha) - dVar1) * fVar2;
  }
  return listRecord;
}

/* _glColor4ui_Exec @ 0x5ce7c (192 bytes) */
void _glColor4ui_Exec(glContext, red, green, blue, alpha)
  int glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
  undefined4 alpha;
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,green) - DOUBLE_00108d70) * FLOAT_00108e6c;
  fVar2 = (float)((double)CONCAT44(0x43300000,alpha) - DOUBLE_00108d70) * FLOAT_00108e6c;
  fVar3 = (float)((double)CONCAT44(0x43300000,blue) - DOUBLE_00108d70) * FLOAT_00108e6c;
  *(float *)(glContext + 0x2a0) =
       (float)((double)CONCAT44(0x43300000,red) - DOUBLE_00108d70) * FLOAT_00108e6c;
  *(float *)(glContext + 0x2a4) = fVar1;
  *(float *)(glContext + 0x2ac) = fVar2;
  *(float *)(glContext + 0x2a8) = fVar3;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  }
  return;
}

/* _glColor4ui_CompExec @ 0x5cf3c (80 bytes) */
void _glColor4ui_CompExec(glContext, red, green, blue, alpha)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
  undefined4 alpha;
{
  ((int (*)())_glColor4ui_Comp)(glContext,red,green,blue,alpha);
  ((void (*)())_glColor4ui_Exec)(glContext,red,green,blue,alpha);
  return;
}

/* _glColor4uiv_Comp @ 0x5cf8c (220 bytes) */
int _glColor4uiv_Comp(glContext, v)
  undefined4 glContext;
  undefined4 *v;
{
  double intToDoubleBias;
  float channelScale;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor4_ListExec_00110058,0x10);
  channelScale = FLOAT_00108e6c;
  intToDoubleBias = DOUBLE_00108d70;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,*v) - DOUBLE_00108d70) * FLOAT_00108e6c;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,v[1]) - intToDoubleBias) * channelScale;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,v[2]) - intToDoubleBias) * channelScale;
    listRecord[3] = (float)((double)CONCAT44(0x43300000,v[3]) - intToDoubleBias) * channelScale;
  }
  return listRecord;
}

/* _glColor4uiv_Exec @ 0x5d068 (208 bytes) */
double _glColor4uiv_Exec(glContext, v)
  int glContext;
  undefined4 *v;
{
  float greenComponent;
  float alphaComponent;
  float blueComponent;
  
  greenComponent = (float)((double)CONCAT44(0x43300000,v[1]) - DOUBLE_00108d70) * FLOAT_00108e6c;
  alphaComponent = (float)((double)CONCAT44(0x43300000,v[3]) - DOUBLE_00108d70) * FLOAT_00108e6c;
  blueComponent = (float)((double)CONCAT44(0x43300000,v[2]) - DOUBLE_00108d70) * FLOAT_00108e6c;
  *(float *)(glContext + 0x2a0) =
       (float)((double)CONCAT44(0x43300000,*v) - DOUBLE_00108d70) * FLOAT_00108e6c;
  *(float *)(glContext + 0x2a4) = greenComponent;
  *(float *)(glContext + 0x2ac) = alphaComponent;
  *(float *)(glContext + 0x2a8) = blueComponent;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  }
  return;
}

