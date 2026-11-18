#include "decls.h"

/* _glFogf_Comp @ 0x67598 (92 bytes) */
undefined4 * _glFogf_Comp(undefined4 glContext,undefined4 pname,float param)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glFogf_ListExec_001100f8,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = (float)param;
    *listRecord = pname;
  }
  return listRecord;
}

/* _glFogf_CompExec @ 0x675f4 (72 bytes) */
void _glFogf_CompExec(undefined4 glContext,undefined4 pname,float param)
{
  ((undefined4 * (*)())_glFogf_Comp)(glContext,pname,param);
  ((void (*)())_glFogf_Exec)(glContext,pname,param);
  return;
}

/* _glFogfv_ListExec @ 0x6763c (48 bytes) */
int _glFogfv_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glFogfv_Exec(glContext,*recordedArgs,recordedArgs + 1);
  return 0x14;
}

/* _glFogfv_Comp @ 0x6766c (112 bytes) */
int _glFogfv_Comp(glContext, pname, params)
  undefined4 glContext;
  undefined4 pname;
  undefined4 *params;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glFogfv_ListExec_001100f4,0x14);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = pname;
    listRecord[1] = *params;
    listRecord[2] = params[1];
    listRecord[3] = params[2];
    listRecord[4] = params[3];
  }
  return listRecord;
}

/* _glFogfv_CompExec @ 0x676dc (64 bytes) */
void _glFogfv_CompExec(glContext, pname, params)
  undefined4 glContext;
  undefined4 pname;
  undefined4 params;
{
  ((int (*)())_glFogfv_Comp)(glContext,pname,params);
  _glFogfv_Exec(glContext,pname,params);
  return;
}

/* _glFogi_ListExec @ 0x6771c (44 bytes) */
int _glFogi_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glFogi_Exec(glContext,*recordedArgs,recordedArgs[1]);
  return 8;
}

/* _glFogi_Comp @ 0x67748 (84 bytes) */
void _glFogi_Comp(glContext, pname, param)
  undefined4 glContext;
  undefined4 pname;
  undefined4 param;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glFogi_ListExec_001100f0,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = param;
    *listRecord = pname;
  }
  return;
}

/* _glFogi_CompExec @ 0x6779c (64 bytes) */
void _glFogi_CompExec(glContext, pname, param)
  undefined4 glContext;
  undefined4 pname;
  undefined4 param;
{
  _glFogi_Exec(glContext,pname,param);
  ((void (*)())_glFogi_Comp)(glContext,pname,param);
  return;
}

/* _glFogiv_ListExec @ 0x677dc (48 bytes) */
int _glFogiv_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glFogiv_Exec)(glContext,*recordedArgs,recordedArgs + 1);
  return 0x14;
}

/* _glFogiv_Comp @ 0x6780c (112 bytes) */
int _glFogiv_Comp(glContext, pname, params)
  undefined4 glContext;
  undefined4 pname;
  undefined4 *params;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glFogiv_ListExec_001100ec,0x14);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = pname;
    listRecord[1] = *params;
    listRecord[2] = params[1];
    listRecord[3] = params[2];
    listRecord[4] = params[3];
  }
  return listRecord;
}

/* _glFogiv_Exec @ 0x6787c (1096 bytes) */
void _glFogiv_Exec(glContext, pname, params)
  int glContext;
  uint pname;
  uint *params;
{
  bool bVar1;
  byte bVar2;
  float fVar3;
  float floatZero;
  undefined4 glErrorCode;
  uint uVar6;
  int iVar7;
  int glContextPtr5424;
  int iVar8;
  
  floatZero = FLOAT_00108e50;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_00067b44:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  if (pname == 0xb64) {
    bVar1 = *(int *)(glContext + 0x5434) == 0;
    *(float *)(glContext + 0x3158) =
         (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
LAB_00067bec:
    if (bVar1) {
      bVar2 = *(byte *)(*(int *)(glContext + 0x5420) + 0x323);
    }
    else {
      bVar2 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x357);
    }
    iVar8 = (bVar2 >> 3 & 0x1c) + glContext;
    glContextPtr5424 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar8 + 0x324) = *(uint *)(iVar8 + 0x324) | 1 << (bVar2 & 0x1f);
    bVar2 = *(byte *)(glContextPtr5424 + 0x323);
  }
  else {
    if (pname < 0xb65) {
      if (pname == 0xb62) {
        if (-1 < (int)*params) {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x501;
          goto LAB_00067b44;
        }
        bVar1 = *(int *)(glContext + 0x5434) == 0;
        *(float *)(glContext + 0x3150) =
             (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
      }
      else {
        if (pname < 0xb63) {
          if (pname == 0xb61) {
            *(float *)(glContext + 0x3160) =
                 (float)((double)CONCAT44(0x43300000,*params * 0x101 ^ 0x80000000) -
                        DOUBLE_00108d58);
            goto LAB_00067c9c;
          }
          goto LAB_00067c88;
        }
        bVar1 = *(int *)(glContext + 0x5434) == 0;
        *(float *)(glContext + 0x3154) =
             (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
      }
      goto LAB_00067bec;
    }
    if (pname != 0xb66) {
      if (pname < 0xb66) {
        uVar6 = *params;
        if ((0x7ff < (int)uVar6) && (((int)uVar6 < 0x802 || (uVar6 == 0x2601)))) {
          *(short *)(glContext + 0x3164) = (short)*params;
          goto LAB_00067c9c;
        }
      }
      else if (pname == 0x8450) {
        if (*params - 0x8451 < 2) {
          *(short *)(glContext + 0x3166) = (short)*params;
          _gleSelectVertexSubmitFunc(glContext);
          goto LAB_00067c9c;
        }
      }
      else if (pname == 0x855a) {
        uVar6 = *params;
        if ((uVar6 == 0x2502) || ((0x2501 < (int)uVar6 && (uVar6 - 0x855b < 2)))) {
          *(short *)(glContext + 0x3168) = (short)*params;
          goto LAB_00067c9c;
        }
      }
LAB_00067c88:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x500;
      }
      goto LAB_00067c9c;
    }
    fVar3 = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58) *
            FLOAT_00108e68 + FLOAT_00108e6c;
    if (fVar3 < FLOAT_00108e50) {
      *(float *)(glContext + 0x3140) = FLOAT_00108e50;
    }
    else {
      *(float *)(glContext + 0x3140) = fVar3;
    }
    fVar3 = (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - DOUBLE_00108d58) *
            FLOAT_00108e68 + FLOAT_00108e6c;
    if (fVar3 < floatZero) {
      *(float *)(glContext + 0x3144) = floatZero;
    }
    else {
      *(float *)(glContext + 0x3144) = fVar3;
    }
    fVar3 = (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - DOUBLE_00108d58) *
            FLOAT_00108e68 + FLOAT_00108e6c;
    if (fVar3 < floatZero) {
      *(float *)(glContext + 0x3148) = floatZero;
    }
    else {
      *(float *)(glContext + 0x3148) = fVar3;
    }
    fVar3 = (float)((double)CONCAT44(0x43300000,params[3] ^ 0x80000000) - DOUBLE_00108d58) *
            FLOAT_00108e68 + FLOAT_00108e6c;
    if (fVar3 < floatZero) {
      *(float *)(glContext + 0x314c) = floatZero;
    }
    else {
      *(float *)(glContext + 0x314c) = fVar3;
    }
    if (*(int *)(glContext + 0x5434) == 0) {
      bVar2 = *(byte *)(*(int *)(glContext + 0x5420) + 0x322);
    }
    else {
      bVar2 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x356);
    }
    iVar8 = (bVar2 >> 3 & 0x1c) + glContext;
    glContextPtr5424 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar8 + 0x324) = *(uint *)(iVar8 + 0x324) | 1 << (bVar2 & 0x1f);
    bVar2 = *(byte *)(glContextPtr5424 + 0x322);
  }
  iVar7 = (bVar2 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar7 + 0x348) = *(uint *)(iVar7 + 0x348) | 1 << (bVar2 & 0x1f);
LAB_00067c9c:
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800;
  ((double (*)())_gleUpdateFogData)(glContext);
  return;
}

/* _glFogiv_CompExec @ 0x67cc4 (64 bytes) */
void _glFogiv_CompExec(glContext, pname, params)
  undefined4 glContext;
  undefined4 pname;
  undefined4 params;
{
  ((int (*)())_glFogiv_Comp)(glContext,pname,params);
  ((void (*)())_glFogiv_Exec)(glContext,pname,params);
  return;
}

/* _glFogCoord_ListExec @ 0x67d04 (16 bytes) */
int _glFogCoord_ListExec(glContext, recordedArgs)
  int glContext;
  undefined4 *recordedArgs;
{
  *(undefined4 *)(glContext + 0x2cc) = *recordedArgs;
  return 4;
}

/* _glFogCoordf_Comp @ 0x67d14 (84 bytes) */
float * _glFogCoordf_Comp(undefined4 glContext,float coord)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glFogCoord_ListExec_001100fc,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)coord;
  }
  return listRecord;
}

/* _glFogCoordfv_Comp @ 0x67d68 (80 bytes) */
int _glFogCoordfv_Comp(glContext, coord)
  undefined4 glContext;
  undefined4 *coord;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glFogCoord_ListExec_001100fc,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = *coord;
  }
  return listRecord;
}

/* _glFogCoordd_Comp @ 0x67db8 (88 bytes) */
float * _glFogCoordd_Comp(undefined4 glContext,double coord)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glFogCoord_ListExec_001100fc,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)coord;
  }
  return listRecord;
}

/* _glFogCoorddv_Comp @ 0x67e10 (84 bytes) */
int _glFogCoorddv_Comp(glContext, coord)
  undefined4 glContext;
  double *coord;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glFogCoord_ListExec_001100fc,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)*coord;
  }
  return listRecord;
}

/* _glFogCoordf_Exec @ 0x67e64 (8 bytes) */
void _glFogCoordf_Exec(int glContext,float coord)
{
  *(float *)(glContext + 0x2cc) = (float)coord;
  return;
}

/* _glFogCoordfv_Exec @ 0x67e6c (12 bytes) */
double _glFogCoordfv_Exec(glContext, coord)
  int glContext;
  undefined4 *coord;
{
  *(undefined4 *)(glContext + 0x2cc) = *coord;
  return;
}

/* _glFogCoordd_Exec @ 0x67e78 (12 bytes) */
void _glFogCoordd_Exec(int glContext,double coord)
{
  *(float *)(glContext + 0x2cc) = (float)coord;
  return;
}

/* _glFogCoorddv_Exec @ 0x67e84 (16 bytes) */
double _glFogCoorddv_Exec(glContext, coord)
  int glContext;
  double *coord;
{
  *(float *)(glContext + 0x2cc) = (float)*coord;
  return;
}

/* _glFogCoordf_CompExec @ 0x67e94 (64 bytes) */
void _glFogCoordf_CompExec(undefined4 glContext,float coord)
{
  ((float * (*)())_glFogCoordf_Comp)(glContext,coord);
  ((void (*)())_glFogCoordf_Exec)(glContext,coord);
  return;
}

/* _glFogCoordfv_CompExec @ 0x67ed4 (56 bytes) */
void _glFogCoordfv_CompExec(glContext, coord)
  undefined4 glContext;
  undefined4 coord;
{
  ((int (*)())_glFogCoordfv_Comp)(glContext,coord);
  ((double (*)())_glFogCoordfv_Exec)(glContext,coord);
  return;
}

/* _glFogCoordd_CompExec @ 0x67f0c (64 bytes) */
void _glFogCoordd_CompExec(undefined4 glContext,double coord)
{
  ((float * (*)())_glFogCoordd_Comp)(glContext,coord);
  ((void (*)())_glFogCoordd_Exec)(glContext,coord);
  return;
}

/* _glFogCoorddv_CompExec @ 0x67f4c (56 bytes) */
void _glFogCoorddv_CompExec(glContext, coord)
  undefined4 glContext;
  undefined4 coord;
{
  ((int (*)())_glFogCoorddv_Comp)(glContext,coord);
  ((double (*)())_glFogCoorddv_Exec)(glContext,coord);
  return;
}

/* _glFrontFace_ListExec @ 0x67f84 (40 bytes) */
int _glFrontFace_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glFrontFace_Exec(glContext,*recordedArgs);
  return 4;
}

/* _glFrontFace_Comp @ 0x67fac (76 bytes) */
int _glFrontFace_Comp(glContext, mode)
  undefined4 glContext;
  undefined4 mode;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glFrontFace_ListExec_00110100,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = mode;
  }
  return listRecord;
}

/* _glFrontFace_CompExec @ 0x67ff8 (56 bytes) */
void _glFrontFace_CompExec(glContext, mode)
  undefined4 glContext;
  undefined4 mode;
{
  ((int (*)())_glFrontFace_Comp)(glContext,mode);
  _glFrontFace_Exec(glContext,mode);
  return;
}

/* _glFrustum_ListExec @ 0x68030 (360 bytes) */
undefined4 _glFrustum_ListExec(int glContext,float *recordedArgs,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float *currentMatrix;
  
  currentMatrix = *(float **)(glContext + 0x4fec);
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    fVar1 = recordedArgs[3];
    fVar2 = recordedArgs[2];
    fVar3 = recordedArgs[4];
    fVar4 = currentMatrix[8];
    fVar5 = currentMatrix[9];
    fVar6 = currentMatrix[10];
    fVar7 = recordedArgs[5];
    fVar8 = *recordedArgs;
    fVar9 = recordedArgs[1];
    fVar10 = currentMatrix[0xf];
    currentMatrix[8] = (fVar4 * fVar3 + (*currentMatrix * fVar2 + currentMatrix[4] * fVar1)) - currentMatrix[0xc];
    currentMatrix[9] = (fVar5 * fVar3 + (currentMatrix[1] * fVar2 + currentMatrix[5] * fVar1)) - currentMatrix[0xd];
    currentMatrix[10] = (fVar6 * fVar3 + (currentMatrix[2] * fVar2 + currentMatrix[6] * fVar1)) - currentMatrix[0xe];
    currentMatrix[4] = currentMatrix[4] * fVar9;
    *currentMatrix = *currentMatrix * fVar8;
    currentMatrix[5] = currentMatrix[5] * fVar9;
    currentMatrix[1] = currentMatrix[1] * fVar8;
    currentMatrix[6] = currentMatrix[6] * fVar9;
    currentMatrix[0xc] = fVar4 * fVar7;
    currentMatrix[0xd] = fVar5 * fVar7;
    currentMatrix[0xe] = fVar6 * fVar7;
    currentMatrix[2] = currentMatrix[2] * fVar8;
    currentMatrix[0xf] = currentMatrix[0xb] * fVar7;
    currentMatrix[0xb] = (currentMatrix[0xb] * fVar3 + (currentMatrix[3] * fVar2 + currentMatrix[7] * fVar1)) - fVar10;
    currentMatrix[3] = currentMatrix[3] * fVar8;
    currentMatrix[7] = currentMatrix[7] * fVar9;
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | *(uint *)(glContext + 0x50a8);
    *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) | *(uint *)(glContext + 0x50a8);
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return 0x18;
}

/* _glFrustum_Comp @ 0x68198 (408 bytes) */
int _glFrustum_Comp(int glContext,double left,double right,double bottom,double top,double zNear,double zFar,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float rightMinusLeft;
  float topMinusBottom;
  float nearMinusFar;
  float deltaMagnitude;
  float *listRecord;
  float twoNear;
  
  if ((!(zNear <= DOUBLE_00108d60)) && (!(zFar <= DOUBLE_00108d60))) {
    rightMinusLeft = (float)(right - left);
    topMinusBottom = (float)(top - bottom);
    nearMinusFar = (float)(zNear - zFar);
    deltaMagnitude = rightMinusLeft;
    if (!(0.0 <= rightMinusLeft)) {
      deltaMagnitude = -rightMinusLeft;
    }
    if (!(deltaMagnitude < FLOAT_00108e80)) {
      deltaMagnitude = topMinusBottom;
      if (!(FLOAT_00108e50 <= topMinusBottom)) {
        deltaMagnitude = -topMinusBottom;
      }
      if (!(deltaMagnitude < FLOAT_00108e80)) {
        deltaMagnitude = nearMinusFar;
        if (!(FLOAT_00108e50 <= nearMinusFar)) {
          deltaMagnitude = -nearMinusFar;
        }
        if (!(deltaMagnitude < FLOAT_00108e80)) {
          listRecord = (float *)_gleAddListItem(glContext,PTR__glFrustum_ListExec_00110104,0x18);
          if (listRecord == (float *)0x0) {
            return 0;
          }
          twoNear = (double)(float)(zNear + zNear);
          *listRecord = (float)((double)twoNear * (double)(1.0 / rightMinusLeft));
          listRecord[2] = (float)((right + left) * (double)(1.0 / rightMinusLeft));
          listRecord[3] = (float)((top + bottom) * (double)(1.0 / topMinusBottom));
          listRecord[4] = (float)((zFar + zNear) * (double)(1.0 / nearMinusFar));
          listRecord[5] = (float)(zFar * (double)twoNear * (double)(1.0 / nearMinusFar));
          listRecord[1] = (float)((double)twoNear * (double)(1.0 / topMinusBottom));
          return (int)listRecord;
        }
      }
    }
  }
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return glContext;
}

/* _glFrustum_CompExec @ 0x68330 (120 bytes) */
void _glFrustum_CompExec(undefined4 glContext,double left,double right,double bottom,double top,float zNear,double zFar,double forwardedFloatArg7,double forwardedFloatArg8,double forwardedFloatArg9,double forwardedFloatArg10,double forwardedFloatArg11,double forwardedFloatArg12,double forwardedFloatArg13)
{
  double incomingStackWord_ffffff68;
  double incomingStackWord_ffffff70;
  double incomingStackWord_ffffff78;
  double incomingStackWord_ffffff80;
  double incomingStackWord_ffffff88;
  
  ((int (*)())_glFrustum_Comp)(glContext,left,right,bottom,top,zNear,zFar,forwardedFloatArg7,forwardedFloatArg8,
                  incomingStackWord_ffffff68,incomingStackWord_ffffff70,incomingStackWord_ffffff78,incomingStackWord_ffffff80,
                  incomingStackWord_ffffff88);
  ((void (*)())_glFrustum_Exec)(glContext,left,right,bottom,top,zNear,zFar,forwardedFloatArg7,forwardedFloatArg8,
                  forwardedFloatArg9,forwardedFloatArg10,forwardedFloatArg11,forwardedFloatArg12,forwardedFloatArg13);
  return;
}

/* _glHint_ListExec @ 0x683a8 (44 bytes) */
int _glHint_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glHint_Exec(glContext,*recordedArgs,recordedArgs[1]);
  return 8;
}

/* _glHint_Comp @ 0x683d4 (84 bytes) */
int _glHint_Comp(glContext, target, mode)
  undefined4 glContext;
  undefined4 target;
  undefined4 mode;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glHint_ListExec_00110108,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = mode;
    *listRecord = target;
  }
  return listRecord;
}

/* _glHint_CompExec @ 0x68428 (64 bytes) */
void _glHint_CompExec(glContext, target, mode)
  undefined4 glContext;
  undefined4 target;
  undefined4 mode;
{
  ((int (*)())_glHint_Comp)(glContext,target,mode);
  _glHint_Exec(glContext,target,mode);
  return;
}

/* _CheckInternalFormat @ 0x68468 (76 bytes) */
int _CheckInternalFormat(internalformat)
  uint internalformat;
{
  if (internalformat < 0x8049) {
    if ((internalformat < 0x803b) && ((internalformat < 0x1906 || ((0x190a < internalformat && (internalformat != 0x2a10)))))) {
      return 0;
    }
  }
  else if (0xc < internalformat - 0x804f) {
    return 0;
  }
  return 1;
}

/* _CheckTypeFormat @ 0x684b4 (184 bytes) */
int _CheckTypeFormat(type, format)
  uint type;
  uint format;
{
  bool formatAllowed;
  
  if (type < 0x8037) {
    if (0x8032 < type) {
LAB_00068548:
      if (format == 0x1908) {
        return 1;
      }
      formatAllowed = format == 0x80e1;
      goto LAB_0006855c;
    }
    if (type < 0x1400) {
      return 1;
    }
    if (type < 0x1407) {
      if (format == 0x8000) {
        return 1;
      }
      if (format < 0x8001) {
        formatAllowed = 7 < format - 0x1903;
      }
      else {
        formatAllowed = 1 < format - 0x80e0;
      }
      if (!formatAllowed) {
        return 1;
      }
      return 0;
    }
    if (type != 0x8032) {
      return 1;
    }
  }
  else {
    if (type < 0x8362) {
      return 1;
    }
    if (0x8364 < type) {
      if (0x8368 < type) {
        return 1;
      }
      goto LAB_00068548;
    }
  }
  formatAllowed = format == 0x1907;
LAB_0006855c:
  if (formatAllowed) {
    return 1;
  }
  return 0;
}

/* _glConvolutionFilter1D_ListExec @ 0x6856c (72 bytes) */
int _glConvolutionFilter1D_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glConvolutionFilter1D_Exec
            (glContext,*recordedArgs,recordedArgs[1],recordedArgs[2],recordedArgs[3],recordedArgs[4],recordedArgs + 6);
  return recordedArgs[5];
}

/* _glConvolutionFilter2D_ListExec @ 0x685b4 (76 bytes) */
int _glConvolutionFilter2D_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glConvolutionFilter2D_Exec
            (glContext,*recordedArgs,recordedArgs[1],recordedArgs[2],recordedArgs[3],recordedArgs[4],recordedArgs[5],recordedArgs + 7);
  return recordedArgs[6];
}

/* _glSeparableFilter2D_ListExec @ 0x68600 (120 bytes) */
int _glSeparableFilter2D_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  int rowBytes;
  
  rowBytes = _gleRowBytes(recordedArgs[4],recordedArgs[5],recordedArgs[2]);
  _glSeparableFilter2D_Exec
            (glContext,*recordedArgs,recordedArgs[1],recordedArgs[2],recordedArgs[3],recordedArgs[4],recordedArgs[5],recordedArgs + 7,
             (int)(recordedArgs + 7) + (rowBytes + 3U & 0xfffffffc));
  return recordedArgs[6];
}

/* _glConvolutionParameterf_ListExec @ 0x68678 (52 bytes) */
int _glConvolutionParameterf_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glConvolutionParameterf_Exec)(glContext,*recordedArgs,recordedArgs[1],(double)GH_U2F((unsigned int)(recordedArgs[2])));
  return 0x18;
}

/* _glConvolutionParameterfv_ListExec @ 0x686ac (52 bytes) */
int _glConvolutionParameterfv_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glConvolutionParameterfv_Exec(glContext,*recordedArgs,recordedArgs[1],recordedArgs + 2);
  return 0x18;
}

/* _glConvolutionParameteri_ListExec @ 0x686e0 (52 bytes) */
int _glConvolutionParameteri_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glConvolutionParameteri_Exec(glContext,*recordedArgs,recordedArgs[1],recordedArgs[2]);
  return 0x18;
}

/* _glConvolutionParameteriv_ListExec @ 0x68714 (52 bytes) */
int _glConvolutionParameteriv_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glConvolutionParameteriv_Exec(glContext,*recordedArgs,recordedArgs[1],recordedArgs + 2);
  return 0x18;
}

/* _glCopyConvolutionFilter1D_ListExec @ 0x68748 (60 bytes) */
int _glCopyConvolutionFilter1D_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glCopyConvolutionFilter1D_Exec(glContext,*recordedArgs,recordedArgs[1],recordedArgs[2],recordedArgs[3],recordedArgs[4]);
  return 0x18;
}

/* _glCopyConvolutionFilter2D_ListExec @ 0x68784 (64 bytes) */
int _glCopyConvolutionFilter2D_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glCopyConvolutionFilter2D_Exec
            (glContext,*recordedArgs,recordedArgs[1],recordedArgs[2],recordedArgs[3],recordedArgs[4],recordedArgs[5]);
  return 0x18;
}

/* _glHistogram_ListExec @ 0x687c4 (56 bytes) */
int _glHistogram_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glHistogram_Exec(glContext,*recordedArgs,recordedArgs[2],recordedArgs[1],(uint)*(byte *)(recordedArgs + 3));
  return 0x10;
}

/* _glMinmax_ListExec @ 0x687fc (52 bytes) */
int _glMinmax_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glMinmax_Exec(glContext,*recordedArgs,recordedArgs[1],(uint)*(byte *)(recordedArgs + 2));
  return 0xc;
}

/* _glResetHistogram_ListExec @ 0x68830 (40 bytes) */
int _glResetHistogram_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glResetHistogram_Exec(glContext,*recordedArgs);
  return 0x10;
}

/* _glResetMinmax_ListExec @ 0x68858 (40 bytes) */
int _glResetMinmax_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glResetMinmax_Exec(glContext,*recordedArgs);
  return 0xc;
}

/* _glConvolutionFilter1D_Comp @ 0x68880 (372 bytes) */
int _glConvolutionFilter1D_Comp(glContext, target, internalformat, width, format, type, image)
  int glContext;
  undefined4 target;
  undefined4 internalformat;
  undefined4 width;
  undefined4 format;
  undefined4 type;
  int image;
{
  int rowBytesThenRecordSize;
  int imageEndOffset;
  undefined4 *elementSizeThenListRecordThenFillResult;
  int pixelUnpackBuffer;
  int unpackBufferSize;
  double bytesPerElement;
  
  rowBytesThenRecordSize = _gleRowBytes(format,type,width);
  if (rowBytesThenRecordSize < 1) {
    return (undefined4 *)rowBytesThenRecordSize;
  }
  pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
  if (pixelUnpackBuffer == 0) {
LAB_0006897c:
    rowBytesThenRecordSize = (rowBytesThenRecordSize + 3U & 0xfffffffc) + 0x18;
    elementSizeThenListRecordThenFillResult = (undefined4 *)
             _gleAddListItem(glContext,PTR__glConvolutionFilter1D_ListExec_00110134,rowBytesThenRecordSize);
    if (elementSizeThenListRecordThenFillResult != (undefined4 *)0x0) {
      *elementSizeThenListRecordThenFillResult = target;
      elementSizeThenListRecordThenFillResult[1] = internalformat;
      elementSizeThenListRecordThenFillResult[5] = rowBytesThenRecordSize;
      elementSizeThenListRecordThenFillResult[2] = width;
      elementSizeThenListRecordThenFillResult[3] = format;
      elementSizeThenListRecordThenFillResult[4] = type;
      if (image != 0) {
        elementSizeThenListRecordThenFillResult = (undefined4 *)_gleFillImage(glContext,width,1,1,format,type,image,elementSizeThenListRecordThenFillResult + 6)
        ;
      }
    }
  }
  else {
    imageEndOffset = _gleOffsetLimitImage(glContext + 0x31cc,width,1,format,type,image);
    unpackBufferSize = *(int *)(pixelUnpackBuffer + 0x38);
    bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
    elementSizeThenListRecordThenFillResult = (undefined4 *)(int)bytesPerElement;
    if (imageEndOffset <= unpackBufferSize) {
      if (elementSizeThenListRecordThenFillResult == (undefined4 *)0x0) {
        elementSizeThenListRecordThenFillResult = (undefined4 *)_glePixelBytes(format,type);
      }
      if (image == (image / (int)elementSizeThenListRecordThenFillResult) * (int)elementSizeThenListRecordThenFillResult) {
        if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
        }
        image = image + *(int *)(pixelUnpackBuffer + 0x30);
        goto LAB_0006897c;
      }
    }
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return elementSizeThenListRecordThenFillResult;
}

/* _glConvolutionFilter2D_Comp @ 0x689f4 (384 bytes) */
int _glConvolutionFilter2D_Comp(glContext, target, internalformat, width, height, format, type, image)
  int glContext;
  undefined4 target;
  undefined4 internalformat;
  undefined4 width;
  undefined4 height;
  undefined4 format;
  undefined4 type;
  int image;
{
  int imageSizeThenRecordSize;
  int imageEndOffset;
  undefined4 *elementSizeThenListRecordThenFillResult;
  int pixelUnpackBuffer;
  int unpackBufferSize;
  double bytesPerElement;
  
  imageSizeThenRecordSize = _gleImageSize(format,type,width,height);
  if (imageSizeThenRecordSize < 1) {
    return (undefined4 *)imageSizeThenRecordSize;
  }
  pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
  if (pixelUnpackBuffer == 0) {
LAB_00068af8:
    imageSizeThenRecordSize = (imageSizeThenRecordSize + 3U & 0xfffffffc) + 0x1c;
    elementSizeThenListRecordThenFillResult = (undefined4 *)
             _gleAddListItem(glContext,PTR__glConvolutionFilter2D_ListExec_00110130,imageSizeThenRecordSize);
    if (elementSizeThenListRecordThenFillResult != (undefined4 *)0x0) {
      *elementSizeThenListRecordThenFillResult = target;
      elementSizeThenListRecordThenFillResult[1] = internalformat;
      elementSizeThenListRecordThenFillResult[6] = imageSizeThenRecordSize;
      elementSizeThenListRecordThenFillResult[2] = width;
      elementSizeThenListRecordThenFillResult[3] = height;
      elementSizeThenListRecordThenFillResult[4] = format;
      elementSizeThenListRecordThenFillResult[5] = type;
      if (image != 0) {
        elementSizeThenListRecordThenFillResult = (undefined4 *)
                 _gleFillImage(glContext,width,height,1,format,type,image,elementSizeThenListRecordThenFillResult + 7);
      }
    }
  }
  else {
    imageEndOffset = _gleOffsetLimitImage(glContext + 0x31cc,width,height,format,type,image);
    unpackBufferSize = *(int *)(pixelUnpackBuffer + 0x38);
    bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
    elementSizeThenListRecordThenFillResult = (undefined4 *)(int)bytesPerElement;
    if (imageEndOffset <= unpackBufferSize) {
      if (elementSizeThenListRecordThenFillResult == (undefined4 *)0x0) {
        elementSizeThenListRecordThenFillResult = (undefined4 *)_glePixelBytes(format,type);
      }
      if (image == (image / (int)elementSizeThenListRecordThenFillResult) * (int)elementSizeThenListRecordThenFillResult) {
        if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
        }
        image = image + *(int *)(pixelUnpackBuffer + 0x30);
        goto LAB_00068af8;
      }
    }
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return elementSizeThenListRecordThenFillResult;
}

/* _glSeparableFilter2D_Comp @ 0x68b74 (536 bytes) */
int _glSeparableFilter2D_Comp(glContext, target, internalformat, width, height, format, type, row, column)
  int glContext;
  undefined4 target;
  undefined4 internalformat;
  undefined4 width;
  undefined4 height;
  undefined4 format;
  undefined4 type;
  int row;
  int column;
{
  uint paddedRowBytes;
  int imageEndOffset;
  int recordSize;
  int rowBytes;
  int rowBytes2;
  int imageEndOffset2;
  undefined4 *elementBytesThenListRecord;
  int pixelUnpackBuffer;
  int bufferSize;
  double bytesPerElement;
  
  rowBytes = _gleRowBytes(format,type,width);
  rowBytes2 = _gleRowBytes(format,type,height);
  if (rowBytes < 1) {
    return (undefined4 *)rowBytes2;
  }
  if (rowBytes2 < 1) {
    return (undefined4 *)rowBytes2;
  }
  pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
  paddedRowBytes = rowBytes + 3U & 0xfffffffc;
  if (pixelUnpackBuffer == 0) {
LAB_00068cdc:
    recordSize = paddedRowBytes + (rowBytes2 + 3U & 0xfffffffc) + 0x1c;
    elementBytesThenListRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glSeparableFilter2D_ListExec_0011012c,recordSize)
    ;
    if (elementBytesThenListRecord != (undefined4 *)0x0) {
      *elementBytesThenListRecord = target;
      elementBytesThenListRecord[1] = internalformat;
      elementBytesThenListRecord[6] = recordSize;
      elementBytesThenListRecord[2] = width;
      elementBytesThenListRecord[3] = height;
      elementBytesThenListRecord[4] = format;
      elementBytesThenListRecord[5] = type;
      if ((row != 0) && (column != 0)) {
        _gleFillImage(glContext,width,1,1,format,type,row,elementBytesThenListRecord + 7);
        elementBytesThenListRecord = (undefined4 *)
                 _gleFillImage(glContext,height,1,1,format,type,column,(int)(elementBytesThenListRecord + 7) + paddedRowBytes
                              );
      }
    }
  }
  else {
    imageEndOffset = _gleOffsetLimitImage(glContext + 0x31cc,width,1,format,type,row);
    imageEndOffset2 = _gleOffsetLimitImage(glContext + 0x31cc,height,1,format,type,column);
    bufferSize = *(int *)(pixelUnpackBuffer + 0x38);
    bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
    elementBytesThenListRecord = (undefined4 *)(int)bytesPerElement;
    if ((imageEndOffset <= bufferSize) && (imageEndOffset2 <= bufferSize)) {
      if (elementBytesThenListRecord == (undefined4 *)0x0) {
        elementBytesThenListRecord = (undefined4 *)_glePixelBytes(format,type);
      }
      if ((row == (row / (int)elementBytesThenListRecord) * (int)elementBytesThenListRecord) &&
         (column == (column / (int)elementBytesThenListRecord) * (int)elementBytesThenListRecord)) {
        if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
        }
        column = column + *(int *)(pixelUnpackBuffer + 0x30);
        row = row + *(int *)(pixelUnpackBuffer + 0x30);
        goto LAB_00068cdc;
      }
    }
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return elementBytesThenListRecord;
}

/* _glConvolutionParameterF_Comp @ 0x68d8c (188 bytes) */
int _glConvolutionParameterF_Comp(glContext, target, pname, params)
  undefined4 glContext;
  undefined4 target;
  uint pname;
  undefined4 *params;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)
           _gleAddListItem(glContext,PTR__glConvolutionParameterf_ListExec_00110128,0x18);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = target;
    listRecord[1] = pname;
    if (pname < 0x8016) {
      if (pname < 0x8014) {
        if (pname != 0x8013) {
          return listRecord;
        }
        listRecord[2] = *params;
        return listRecord;
      }
    }
    else if (pname != 0x8154) {
      return listRecord;
    }
    listRecord[2] = *params;
    listRecord[3] = params[1];
    listRecord[4] = params[2];
    listRecord[5] = params[3];
  }
  return listRecord;
}

/* _glConvolutionParameterf_Comp @ 0x68e48 (40 bytes) */
undefined4 _glConvolutionParameterf_Comp(undefined4 glContext,undefined4 target,undefined4 pname,float params)
{
  undefined4 calleeResult;
  float fStack00000024;
  
  fStack00000024 = (float)params;
  calleeResult = ((int (*)())_glConvolutionParameterF_Comp)(glContext,target,pname,&STACKARG(0x24));
  return calleeResult;
}

/* _glConvolutionParameterI_Comp @ 0x68e74 (168 bytes) */
int _glConvolutionParameterI_Comp(glContext, target, pname, params)
  undefined4 glContext;
  undefined4 target;
  uint pname;
  undefined4 *params;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)
           _gleAddListItem(glContext,PTR__glConvolutionParameteri_ListExec_00110124,0x18);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = target;
    listRecord[1] = pname;
    if (0x8012 < pname) {
      if (pname < 0x8016) {
        listRecord[2] = *params;
      }
      else if (pname == 0x8154) {
        listRecord[2] = *params;
        listRecord[3] = params[1];
        listRecord[4] = params[2];
        listRecord[5] = params[3];
      }
    }
  }
  return listRecord;
}

/* _glConvolutionParameteri_Comp @ 0x68f1c (40 bytes) */
int _glConvolutionParameteri_Comp(glContext, target, pname, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 pname;
  undefined4 params;
{
  unsigned int ghidra_home[8] = { glContext, target, pname, params, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 listRecord;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = params;
  listRecord = ((int (*)())_glConvolutionParameterI_Comp)(glContext,target,pname,&(*(unsigned int *)((unsigned char *)ghidra_home + 12)));
  return listRecord;
}

/* _glCopyConvolutionFilter1D_Comp @ 0x68f48 (116 bytes) */
int _glCopyConvolutionFilter1D_Comp(glContext, target, internalformat, x, y, width)
  undefined4 glContext;
  undefined4 target;
  undefined4 internalformat;
  undefined4 x;
  undefined4 y;
  undefined4 width;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)
           _gleAddListItem(glContext,PTR__glCopyConvolutionFilter1D_ListExec_00110120,0x18);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = target;
    listRecord[5] = 1;
    listRecord[1] = internalformat;
    listRecord[2] = x;
    listRecord[3] = y;
    listRecord[4] = width;
  }
  return listRecord;
}

/* _glCopyConvolutionFilter2D_Comp @ 0x68fbc (116 bytes) */
int _glCopyConvolutionFilter2D_Comp(glContext, target, internalformat, x, y, width, height)
  undefined4 glContext;
  undefined4 target;
  undefined4 internalformat;
  undefined4 x;
  undefined4 y;
  undefined4 width;
  undefined4 height;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)
           _gleAddListItem(glContext,PTR__glCopyConvolutionFilter2D_ListExec_0011011c,0x18);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[5] = height;
    *listRecord = target;
    listRecord[1] = internalformat;
    listRecord[2] = x;
    listRecord[3] = y;
    listRecord[4] = width;
  }
  return listRecord;
}

/* _glHistogram_Comp @ 0x69030 (100 bytes) */
int _glHistogram_Comp(glContext, target, width, internalformat, sink)
  undefined4 glContext;
  undefined4 target;
  undefined4 width;
  undefined4 internalformat;
  undefined4 sink;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glHistogram_ListExec_00110118,0x10);
  if (listRecord != (undefined4 *)0x0) {
    *(undefined1 *)(listRecord + 3) = (undefined1)sink;
    *listRecord = target;
    listRecord[2] = width;
    listRecord[1] = internalformat;
  }
  return listRecord;
}

/* _glMinmax_Comp @ 0x69094 (92 bytes) */
int _glMinmax_Comp(glContext, target, internalformat, sink)
  undefined4 glContext;
  undefined4 target;
  undefined4 internalformat;
  undefined4 sink;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glMinmax_ListExec_00110114,0xc);
  if (listRecord != (undefined4 *)0x0) {
    *(undefined1 *)(listRecord + 2) = (undefined1)sink;
    *listRecord = target;
    listRecord[1] = internalformat;
  }
  return listRecord;
}

