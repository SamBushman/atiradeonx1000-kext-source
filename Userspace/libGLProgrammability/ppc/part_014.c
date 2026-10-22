#include "decls.h"

/* _InterpreterTextureSamplerAttachDerivatives @ 0x97bd3614 (12 bytes) */
void _InterpreterTextureSamplerAttachDerivatives(int param_1,undefined4 param_2,double fparam_1)
{
  *(float *)(param_1 + 0x10) = (float)fparam_1;
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}

/* _InterpreterTextureSamplerSampleTexel1D @ 0x97bd3620 (512 bytes) */
void _InterpreterTextureSamplerSampleTexel1D(int *sampler,int textureUnit,undefined4 unusedArg3,undefined4 texCoord,float *texelOut,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  double lodOrFrac;
  float oneMinusLodFrac;
  int *textureObject;
  uint baseLevel;
  double lambda;
  double levelSampleResult;
  double in_stack_ffffff48;
  double in_stack_ffffff50;
  double in_stack_ffffff58;
  double in_stack_ffffff60;
  float texelBaseLevelr;
  float texelBaseLevelg;
  float texelBaseLevelb;
  float texelBaseLevela;
  float texelNextLevelr;
  float texelNextLevelg;
  float texelNextLevelb;
  float texelNextLevela;
  longlong intCastScratchA;
  longlong intCastScratchB;
  float lodBiasedClamped;
  
  textureObject = *(int **)(*sampler + textureUnit * 4);
  if ((uint)(*(ushort *)(*textureObject + 0x16) - 0x2700) < 4) {
    sampler[10] = 1;
    lambda = (double)((double (*)())_InterpreterTextureSamplerCalculateLambda1D)(sampler,texCoord,textureUnit,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                               fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,
                               in_stack_ffffff58,in_stack_ffffff60);
    lodBiasedClamped = (float)((double)(float)(lambda + (double)GH_U2F((unsigned int)(textureObject[0x10]))) + fparam_1);
    if (lodBiasedClamped < GH_U2F((unsigned int)(textureObject[0xc]))) {
      lodBiasedClamped = GH_U2F((unsigned int)(textureObject[0xc]));
    }
    fparam_1 = (double)lodBiasedClamped;
    lodOrFrac = fparam_1;
    if ((double)GH_U2F((unsigned int)(textureObject[8])) < fparam_1) {
      lodOrFrac = (double)GH_U2F((unsigned int)(textureObject[8]));
    }
    if (DOUBLE_97c30a78 <= lodOrFrac) {
      intCastScratchB = (longlong)(int)(lodOrFrac - DOUBLE_97c30a78);
      baseLevel = (int)(lodOrFrac - DOUBLE_97c30a78) ^ 0x80000000;
    }
    else {
      baseLevel = (uint)(int)lodOrFrac;
      intCastScratchA = (longlong)(int)baseLevel;
    }
    if (1 < *(ushort *)(*textureObject + 0x16) - 0x2700) {
      levelSampleResult = (double)((double (*)())_InterpreterTextureSamplerSampleTexel1DFromLevel)(sampler,textureUnit,baseLevel,texCoord,&texelBaseLevelr,fparam_1,fparam_2,
                                       fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
                                       in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58);
      ((double (*)())_InterpreterTextureSamplerSampleTexel1DFromLevel)(sampler,textureUnit,baseLevel + 1,texCoord,&texelNextLevelr,levelSampleResult,fparam_2,fparam_3,fparam_4,
                 fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,
                 in_stack_ffffff58);
      lodOrFrac = (double)(float)(lodOrFrac - (double)(float)((double)CONCAT44(0x43300000,baseLevel) -
                                                     DOUBLE_97c30a68));
      oneMinusLodFrac = (float)(DOUBLE_97c30a60 - lodOrFrac);
      *texelOut = oneMinusLodFrac * texelBaseLevelr + (float)(lodOrFrac * (double)texelNextLevelr);
      texelOut[3] = oneMinusLodFrac * texelBaseLevela + (float)(lodOrFrac * (double)texelNextLevela);
      texelOut[1] = oneMinusLodFrac * texelBaseLevelg + (float)(lodOrFrac * (double)texelNextLevelg);
      texelOut[2] = oneMinusLodFrac * texelBaseLevelb + (float)(lodOrFrac * (double)texelNextLevelb);
      return;
    }
  }
  else {
    baseLevel = 0;
    sampler[10] = 0;
  }
  ((double (*)())_InterpreterTextureSamplerSampleTexel1DFromLevel)(sampler,textureUnit,baseLevel,texCoord,texelOut,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
             fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58);
  return;
}

/* _InterpreterTextureSamplerSampleTexel2D @ 0x97bd3820 (512 bytes) */
void _InterpreterTextureSamplerSampleTexel2D(int *sampler,int textureUnit,undefined4 unusedArg3,undefined4 texCoord,float *texelOut,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double lodOrFrac;
  float oneMinusLodFrac;
  int *textureObject;
  uint baseLevel;
  double lambda;
  double levelSampleResult;
  double in_stack_ffffff48;
  double in_stack_ffffff50;
  double in_stack_ffffff58;
  double in_stack_ffffff60;
  double in_stack_ffffff68;
  float texelBaseLevelr;
  float texelBaseLevelg;
  float texelBaseLevelb;
  float texelBaseLevela;
  float texelNextLevelr;
  float texelNextLevelg;
  float texelNextLevelb;
  float texelNextLevela;
  longlong intCastScratchA;
  longlong intCastScratchB;
  float lodBiasedClamped;
  
  textureObject = *(int **)(*sampler + textureUnit * 4);
  if ((uint)(*(ushort *)(*textureObject + 0x16) - 0x2700) < 4) {
    sampler[10] = 1;
    lambda = (double)((double (*)())_InterpreterTextureSamplerCalculateLambda2D)(sampler,texCoord,textureUnit,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                               fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,
                               in_stack_ffffff58,in_stack_ffffff60);
    lodBiasedClamped = (float)((double)(float)(lambda + (double)GH_U2F((unsigned int)(textureObject[0x10]))) + fparam_1);
    if (lodBiasedClamped < GH_U2F((unsigned int)(textureObject[0xc]))) {
      lodBiasedClamped = GH_U2F((unsigned int)(textureObject[0xc]));
    }
    fparam_1 = (double)lodBiasedClamped;
    lodOrFrac = fparam_1;
    if ((double)GH_U2F((unsigned int)(textureObject[8])) < fparam_1) {
      lodOrFrac = (double)GH_U2F((unsigned int)(textureObject[8]));
    }
    if (DOUBLE_97c30a78 <= lodOrFrac) {
      intCastScratchB = (longlong)(int)(lodOrFrac - DOUBLE_97c30a78);
      baseLevel = (int)(lodOrFrac - DOUBLE_97c30a78) ^ 0x80000000;
    }
    else {
      baseLevel = (uint)(int)lodOrFrac;
      intCastScratchA = (longlong)(int)baseLevel;
    }
    if (1 < *(ushort *)(*textureObject + 0x16) - 0x2700) {
      levelSampleResult = (double)((double (*)())_InterpreterTextureSamplerSampleTexel2DFromLevel)(sampler,textureUnit,baseLevel,texCoord,&texelBaseLevelr,fparam_1,fparam_2,
                                       fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
                                       in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58,
                                       in_stack_ffffff60,in_stack_ffffff68);
      ((double (*)())_InterpreterTextureSamplerSampleTexel2DFromLevel)(sampler,textureUnit,baseLevel + 1,texCoord,&texelNextLevelr,levelSampleResult,fparam_2,fparam_3,fparam_4,
                 fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,
                 in_stack_ffffff58,in_stack_ffffff60,in_stack_ffffff68);
      lodOrFrac = (double)(float)(lodOrFrac - (double)(float)((double)CONCAT44(0x43300000,baseLevel) -
                                                     DOUBLE_97c30a68));
      oneMinusLodFrac = (float)(DOUBLE_97c30a60 - lodOrFrac);
      *texelOut = oneMinusLodFrac * texelBaseLevelr + (float)(lodOrFrac * (double)texelNextLevelr);
      texelOut[3] = oneMinusLodFrac * texelBaseLevela + (float)(lodOrFrac * (double)texelNextLevela);
      texelOut[1] = oneMinusLodFrac * texelBaseLevelg + (float)(lodOrFrac * (double)texelNextLevelg);
      texelOut[2] = oneMinusLodFrac * texelBaseLevelb + (float)(lodOrFrac * (double)texelNextLevelb);
      return;
    }
  }
  else {
    baseLevel = 0;
    sampler[10] = 0;
  }
  ((double (*)())_InterpreterTextureSamplerSampleTexel2DFromLevel)(sampler,textureUnit,baseLevel,texCoord,texelOut,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
             fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58,
             in_stack_ffffff60,in_stack_ffffff68);
  return;
}

/* _InterpreterTextureSamplerSampleTexel3D @ 0x97bd3a20 (512 bytes) */
void _InterpreterTextureSamplerSampleTexel3D(int *sampler,int textureUnit,undefined4 unusedArg3,undefined4 texCoord,float *texelOut,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  double lodOrFrac;
  float oneMinusLodFrac;
  int *textureObject;
  uint baseLevel;
  double lambda;
  double levelSampleResult;
  double in_stack_ffffff48;
  double in_stack_ffffff50;
  double in_stack_ffffff58;
  double in_stack_ffffff60;
  float texelBaseLevelr;
  float texelBaseLevelg;
  float texelBaseLevelb;
  float texelBaseLevela;
  float texelNextLevelr;
  float texelNextLevelg;
  float texelNextLevelb;
  float texelNextLevela;
  longlong intCastScratchA;
  longlong intCastScratchB;
  float lodBiasedClamped;
  
  textureObject = *(int **)(*sampler + textureUnit * 4);
  if ((uint)(*(ushort *)(*textureObject + 0x16) - 0x2700) < 4) {
    sampler[10] = 1;
    lambda = (double)((double (*)())_InterpreterTextureSamplerCalculateLambda3D)(sampler,texCoord,textureUnit,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                               fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,
                               in_stack_ffffff58,in_stack_ffffff60);
    lodBiasedClamped = (float)((double)(float)(lambda + (double)GH_U2F((unsigned int)(textureObject[0x10]))) + fparam_1);
    if (lodBiasedClamped < GH_U2F((unsigned int)(textureObject[0xc]))) {
      lodBiasedClamped = GH_U2F((unsigned int)(textureObject[0xc]));
    }
    fparam_1 = (double)lodBiasedClamped;
    lodOrFrac = fparam_1;
    if ((double)GH_U2F((unsigned int)(textureObject[8])) < fparam_1) {
      lodOrFrac = (double)GH_U2F((unsigned int)(textureObject[8]));
    }
    if (DOUBLE_97c30a78 <= lodOrFrac) {
      intCastScratchB = (longlong)(int)(lodOrFrac - DOUBLE_97c30a78);
      baseLevel = (int)(lodOrFrac - DOUBLE_97c30a78) ^ 0x80000000;
    }
    else {
      baseLevel = (uint)(int)lodOrFrac;
      intCastScratchA = (longlong)(int)baseLevel;
    }
    if (1 < *(ushort *)(*textureObject + 0x16) - 0x2700) {
      levelSampleResult = (double)((double (*)())_InterpreterTextureSamplerSampleTexel3DFromLevel)(sampler,textureUnit,baseLevel,texCoord,&texelBaseLevelr,fparam_1,fparam_2,
                                       fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
                                       in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58);
      ((double (*)())_InterpreterTextureSamplerSampleTexel3DFromLevel)(sampler,textureUnit,baseLevel + 1,texCoord,&texelNextLevelr,levelSampleResult,fparam_2,fparam_3,fparam_4,
                 fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,
                 in_stack_ffffff58);
      lodOrFrac = (double)(float)(lodOrFrac - (double)(float)((double)CONCAT44(0x43300000,baseLevel) -
                                                     DOUBLE_97c30a68));
      oneMinusLodFrac = (float)(DOUBLE_97c30a60 - lodOrFrac);
      *texelOut = oneMinusLodFrac * texelBaseLevelr + (float)(lodOrFrac * (double)texelNextLevelr);
      texelOut[3] = oneMinusLodFrac * texelBaseLevela + (float)(lodOrFrac * (double)texelNextLevela);
      texelOut[1] = oneMinusLodFrac * texelBaseLevelg + (float)(lodOrFrac * (double)texelNextLevelg);
      texelOut[2] = oneMinusLodFrac * texelBaseLevelb + (float)(lodOrFrac * (double)texelNextLevelb);
      return;
    }
  }
  else {
    baseLevel = 0;
    sampler[10] = 0;
  }
  ((double (*)())_InterpreterTextureSamplerSampleTexel3DFromLevel)(sampler,textureUnit,baseLevel,texCoord,texelOut,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
             fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58);
  return;
}

/* _InterpreterTextureSamplerWrapCoordinate @ 0x97bd3c28 (528 bytes) */
int _InterpreterTextureSamplerWrapCoordinate(sampler, texelCoord)
  int sampler;
  uint *texelCoord;
{
  uint clampLimitR;
  uint clampLimitT;
  uint wrappedR;
  uint wrappedT;
  uint wrappedS;
  int textureState;
  uint clampLimitS;
  int levelRecord;
  ushort wrapModeS;
  ushort wrapModeR;
  ushort wrapModeT;
  
  levelRecord = *(int *)(sampler + 8);
  textureState = **(int **)(sampler + 4);
  wrapModeS = *(ushort *)(textureState + 0x10);
  wrapModeT = *(ushort *)(textureState + 0x12);
  wrapModeR = *(ushort *)(textureState + 0x14);
  if ((*(short *)(textureState + 0x16) == 0x2600) || (*(short *)(textureState + 0x16) == 0x2700)) {
    if (wrapModeS == 0x2900) {
      wrapModeS = 0x812f;
    }
    if (wrapModeT == 0x2900) {
      wrapModeT = 0x812f;
    }
    if (wrapModeR == 0x2900) {
      wrapModeR = 0x812f;
    }
  }
  if (wrapModeS == 0x2901) {
    wrappedS = *texelCoord & *(uint *)(levelRecord + 0x40);
LAB_97bd3d20:
    *texelCoord = wrappedS;
  }
  else {
    if (wrapModeS < 0x2902) {
      if (wrapModeS != 0x2900) goto LAB_97bd3d24;
LAB_97bd3cec:
      wrappedS = *texelCoord;
      if ((int)wrappedS < 0) {
LAB_97bd3cf8:
        wrappedS = 0;
        goto LAB_97bd3d20;
      }
      clampLimitS = *(uint *)(levelRecord + 0x80);
    }
    else {
      if (wrapModeS == 0x812d) goto LAB_97bd3cec;
      if (wrapModeS != 0x812f) goto LAB_97bd3d24;
      wrappedS = *texelCoord;
      if ((int)wrappedS < 0) goto LAB_97bd3cf8;
      clampLimitS = *(uint *)(levelRecord + 0x30);
    }
    if (clampLimitS < wrappedS) {
      *texelCoord = clampLimitS;
    }
  }
LAB_97bd3d24:
  if (wrapModeT == 0x2901) {
    wrappedT = texelCoord[1] & *(uint *)(levelRecord + 0x44);
LAB_97bd3da8:
    texelCoord[1] = wrappedT;
  }
  else {
    if (wrapModeT < 0x2902) {
      if (wrapModeT != 0x2900) goto LAB_97bd3dac;
LAB_97bd3d74:
      wrappedT = texelCoord[1];
      if ((int)wrappedT < 0) {
LAB_97bd3d80:
        wrappedT = 0;
        goto LAB_97bd3da8;
      }
      clampLimitT = *(uint *)(levelRecord + 0x84);
    }
    else {
      if (wrapModeT == 0x812d) goto LAB_97bd3d74;
      if (wrapModeT != 0x812f) goto LAB_97bd3dac;
      wrappedT = texelCoord[1];
      if ((int)wrappedT < 0) goto LAB_97bd3d80;
      clampLimitT = *(uint *)(levelRecord + 0x34);
    }
    if (clampLimitT < wrappedT) {
      texelCoord[1] = clampLimitT;
    }
  }
LAB_97bd3dac:
  if (wrapModeR == 0x2901) {
    wrappedR = texelCoord[2] & *(uint *)(levelRecord + 0x48);
    goto LAB_97bd3e30;
  }
  if (wrapModeR < 0x2902) {
    if (wrapModeR != 0x2900) {
      return;
    }
LAB_97bd3dfc:
    wrappedR = texelCoord[2];
    if (-1 < (int)wrappedR) {
      clampLimitR = *(uint *)(levelRecord + 0x88);
LAB_97bd3e14:
      if (clampLimitR < wrappedR) {
        texelCoord[2] = clampLimitR;
        return;
      }
      return;
    }
  }
  else {
    if (wrapModeR == 0x812d) goto LAB_97bd3dfc;
    if (wrapModeR != 0x812f) {
      return;
    }
    wrappedR = texelCoord[2];
    if (-1 < (int)wrappedR) {
      clampLimitR = *(uint *)(levelRecord + 0x38);
      goto LAB_97bd3e14;
    }
  }
  wrappedR = 0;
LAB_97bd3e30:
  texelCoord[2] = wrappedR;
  return;
}

/* _InterpreterTextureSamplerCalculateLambda1D @ 0x97bd3e38 (276 bytes) */
double _InterpreterTextureSamplerCalculateLambda1D(int *sampler,float *texCoord,int textureUnit,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  float maxGradientLength;
  double lambda;
  float q;
  float neighbourXQOrDsdx;
  float neighbourYQOrDsdy;
  float coordS;
  float neighbourXS;
  float neighbourYS;
  float baseWidthOrDsdy;
  int neighbourY;
  int neighbourX;
  double gradientLengthX;
  double gradientLengthY;
  
  q = texCoord[3];
  neighbourX = textureUnit * 0x10 + sampler[3];
  neighbourXQOrDsdx = *(float *)(neighbourX + 0x4c);
  neighbourY = textureUnit * 0x10 + sampler[3] + 0xc0;
  neighbourYQOrDsdy = *(float *)(neighbourY + 0x4c);
  coordS = *texCoord;
  neighbourXS = *(float *)(neighbourX + 0x40);
  neighbourYS = *(float *)(neighbourY + 0x40);
  baseWidthOrDsdy = *(float *)(*(int *)(textureUnit * 4 + *sampler) + 0x120);
  neighbourXQOrDsdx = -((coordS - neighbourXS) * (float)(DOUBLE_97c30a60 / (double)(q - neighbourXQOrDsdx)) -
           (coordS + neighbourXS) * (float)(DOUBLE_97c30a60 / (double)(q + neighbourXQOrDsdx))) * baseWidthOrDsdy;
  baseWidthOrDsdy = -((coordS - neighbourYS) * (float)(DOUBLE_97c30a60 / (double)(q - neighbourYQOrDsdy)) -
           (coordS + neighbourYS) * (float)(DOUBLE_97c30a60 / (double)(q + neighbourYQOrDsdy))) * baseWidthOrDsdy;
  gradientLengthX = _sqrt((double)(neighbourXQOrDsdx * neighbourXQOrDsdx));
  gradientLengthY = _sqrt((double)(baseWidthOrDsdy * baseWidthOrDsdy));
  maxGradientLength = (float)gradientLengthY;
  if ((float)gradientLengthY < (float)gradientLengthX) {
    maxGradientLength = (float)gradientLengthX;
  }
  lambda = _log2((double)(maxGradientLength * GH_U2F((unsigned int)(sampler[4]))));
  return (double)(float)lambda;
}

/* _InterpreterTextureSamplerCalculateLambda2D @ 0x97bd3f4c (348 bytes) */
double _InterpreterTextureSamplerCalculateLambda2D(int *sampler,float *texCoord,int textureUnit,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  float maxGradientLength;
  double lambda;
  float invQPlusXOrDsdx;
  float invQMinusX;
  float invQPlusY;
  float qOrInvQMinusY;
  float coordS;
  float coordT;
  float baseHeightOrDtdy;
  float baseWidthOrDsdy;
  float dtdx;
  int textureObject;
  int neighbourX;
  int neighbourY;
  double gradientLengthX;
  double gradientLengthY;
  
  qOrInvQMinusY = texCoord[3];
  neighbourX = textureUnit * 0x10 + sampler[3];
  neighbourY = textureUnit * 0x10 + sampler[3] + 0xc0;
  coordS = *texCoord;
  coordT = texCoord[1];
  textureObject = *(int *)(textureUnit * 4 + *sampler);
  baseHeightOrDtdy = *(float *)(textureObject + 0x124);
  baseWidthOrDsdy = *(float *)(textureObject + 0x120);
  invQPlusXOrDsdx = (float)(DOUBLE_97c30a60 / (double)(qOrInvQMinusY + *(float *)(neighbourX + 0x4c)));
  invQMinusX = (float)(DOUBLE_97c30a60 / (double)(qOrInvQMinusY - *(float *)(neighbourX + 0x4c)));
  invQPlusY = (float)(DOUBLE_97c30a60 / (double)(qOrInvQMinusY + *(float *)(neighbourY + 0x4c)));
  qOrInvQMinusY = (float)(DOUBLE_97c30a60 / (double)(qOrInvQMinusY - *(float *)(neighbourY + 0x4c)));
  dtdx = -((coordT - *(float *)(neighbourX + 0x44)) * invQMinusX -
           (coordT + *(float *)(neighbourX + 0x44)) * invQPlusXOrDsdx) * baseHeightOrDtdy;
  invQPlusXOrDsdx = -((coordS - *(float *)(neighbourX + 0x40)) * invQMinusX -
           (coordS + *(float *)(neighbourX + 0x40)) * invQPlusXOrDsdx) * baseWidthOrDsdy;
  baseWidthOrDsdy = -((coordS - *(float *)(neighbourY + 0x40)) * qOrInvQMinusY -
           (coordS + *(float *)(neighbourY + 0x40)) * invQPlusY) * baseWidthOrDsdy;
  baseHeightOrDtdy = -((coordT - *(float *)(neighbourY + 0x44)) * qOrInvQMinusY -
           (coordT + *(float *)(neighbourY + 0x44)) * invQPlusY) * baseHeightOrDtdy;
  gradientLengthX = _sqrt((double)(invQPlusXOrDsdx * invQPlusXOrDsdx + dtdx * dtdx));
  gradientLengthY = _sqrt((double)(baseWidthOrDsdy * baseWidthOrDsdy + baseHeightOrDtdy * baseHeightOrDtdy));
  maxGradientLength = (float)gradientLengthY;
  if ((float)gradientLengthY < (float)gradientLengthX) {
    maxGradientLength = (float)gradientLengthX;
  }
  lambda = _log2((double)(maxGradientLength * GH_U2F((unsigned int)(sampler[4]))));
  return (double)(float)lambda;
}

/* _InterpreterTextureSamplerCalculateLambda3D @ 0x97bd40a8 (360 bytes) */
double _InterpreterTextureSamplerCalculateLambda3D(int *sampler,float *texCoord,int textureUnit,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  float maxGradientLength;
  float dtdy;
  double lambda;
  float invQPlusX;
  float invQMinusXOrDsdx;
  float invQPlusYOrDsdy;
  float qOrInvQMinusY;
  float coordS;
  float coordT;
  float dtdx;
  float drdxOrDrdxSquared;
  int textureObject;
  int neighbourX;
  int neighbourY;
  double gradientLengthX;
  double gradientLengthY;
  
  qOrInvQMinusY = texCoord[3];
  neighbourX = textureUnit * 0x10 + sampler[3];
  neighbourY = textureUnit * 0x10 + sampler[3] + 0xc0;
  coordS = *texCoord;
  coordT = texCoord[1];
  textureObject = *(int *)(textureUnit * 4 + *sampler);
  invQPlusX = (float)(DOUBLE_97c30a60 / (double)(qOrInvQMinusY + *(float *)(neighbourX + 0x4c)));
  invQMinusXOrDsdx = (float)(DOUBLE_97c30a60 / (double)(qOrInvQMinusY - *(float *)(neighbourX + 0x4c)));
  invQPlusYOrDsdy = (float)(DOUBLE_97c30a60 / (double)(qOrInvQMinusY + *(float *)(neighbourY + 0x4c)));
  qOrInvQMinusY = (float)(DOUBLE_97c30a60 / (double)(qOrInvQMinusY - *(float *)(neighbourY + 0x4c)));
  dtdx = -((coordT - *(float *)(neighbourX + 0x44)) * invQMinusXOrDsdx -
           (coordT + *(float *)(neighbourX + 0x44)) * invQPlusX) * *(float *)(textureObject + 0x124);
  drdxOrDrdxSquared = -((texCoord[2] - *(float *)(neighbourX + 0x48)) * invQMinusXOrDsdx -
           (texCoord[2] + *(float *)(neighbourX + 0x48)) * invQPlusX) * *(float *)(textureObject + 0x128);
  invQMinusXOrDsdx = -((coordS - *(float *)(neighbourX + 0x40)) * invQMinusXOrDsdx -
           (coordS + *(float *)(neighbourX + 0x40)) * invQPlusX) * *(float *)(textureObject + 0x120);
  drdxOrDrdxSquared = drdxOrDrdxSquared * drdxOrDrdxSquared;
  dtdy = -((coordT - *(float *)(neighbourY + 0x44)) * qOrInvQMinusY -
           (coordT + *(float *)(neighbourY + 0x44)) * invQPlusYOrDsdy) * *(float *)(textureObject + 0x124);
  invQPlusYOrDsdy = -((coordS - *(float *)(neighbourY + 0x40)) * qOrInvQMinusY -
           (coordS + *(float *)(neighbourY + 0x40)) * invQPlusYOrDsdy) * *(float *)(textureObject + 0x120);
  gradientLengthX = _sqrt((double)(invQMinusXOrDsdx * invQMinusXOrDsdx + dtdx * dtdx + drdxOrDrdxSquared));
  gradientLengthY = _sqrt((double)(invQPlusYOrDsdy * invQPlusYOrDsdy + dtdy * dtdy + drdxOrDrdxSquared));
  maxGradientLength = (float)gradientLengthY;
  if ((float)gradientLengthY < (float)gradientLengthX) {
    maxGradientLength = (float)gradientLengthX;
  }
  lambda = _log2((double)(maxGradientLength * GH_U2F((unsigned int)(sampler[4]))));
  return (double)(float)lambda;
}

/* _InterpreterTextureSamplerSampleTexel1DFromLevel @ 0x97bd4210 (876 bytes) */
double _InterpreterTextureSamplerSampleTexel1DFromLevel(int *sampler,uint textureUnit,int level,float *texCoord,float *texelOut,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11)
{
  int linearRecordIndex;
  int linearTexelData;
  int nearestRecordIndex;
  double loadTexelResult;
  double oneConst;
  float weightL;
  double floorResult;
  bool isLinearFilterCode;
  float coordS;
  float levelWidthF;
  ushort minFilter;
  int textureState;
  int *textureObject;
  float *levelInfo;
  int nearestTexelData;
  double scaledR;
  double fracS;
  double scaledT;
  uint texelCoordS;
  int texelCoordT;
  int texelCoordR;
  longlong intCastScratch;
  float texelHr;
  float texelHg;
  float texelHb;
  float texelHa;
  float texelLr;
  float texelLg;
  float texelLb;
  float texelLa;
  uint sampleCoordS;
  int sampleCoordT;
  int sampleCoordR;
  undefined4 i2dHi1;
  uint i2dLo1;
  
  if (7 < textureUnit) {
    textureUnit = 7;
  }
  textureObject = *(int **)(*sampler + textureUnit * 4);
  if (textureObject == (int *)0x0) {
    return fparam_1;
  }
  sampler[1] = (int)textureObject;
  levelInfo = (float *)(textureObject + level * 0x34 + 0x48);
  sampler[2] = (int)levelInfo;
  if (sampler[8] == 0) {
    coordS = *texCoord;
  }
  else {
    coordS = *texCoord / texCoord[3];
  }
  textureState = *textureObject;
  minFilter = *(ushort *)(textureState + 0x16);
  if (minFilter == 0x2700) {
LAB_97bd42d8:
    if (*(short *)(textureState + 0x10) == -0x7ed3) {
      levelWidthF = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x5c]));
      nearestRecordIndex = level * 0x34 + 100;
      nearestTexelData = textureObject[level * 0x34 + 0x71];
    }
    else {
      levelWidthF = *levelInfo;
      nearestRecordIndex = level * 0x34 + 0x50;
      nearestTexelData = textureObject[level * 0x34 + 0x70];
    }
    texelCoordS = (uint)(coordS * levelWidthF);
    intCastScratch = 0;
    texelCoordT = 0;
    texelCoordR = 0;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&texelCoordS);
    loadTexelResult = (double)((int (*)())_InterpreterTextureSamplerLoadTexel1D)(sampler,nearestTexelData,textureObject + nearestRecordIndex,&texelCoordS,texelOut);
    return loadTexelResult;
  }
  if (minFilter < 0x2701) {
    if (minFilter == 0x2600) goto LAB_97bd42d8;
    isLinearFilterCode = minFilter == 0x2601;
LAB_97bd42d0:
    if (!isLinearFilterCode) {
      return fparam_1;
    }
  }
  else {
    if (minFilter == 0x2702) goto LAB_97bd42d8;
    if (0x2701 < minFilter) {
      isLinearFilterCode = minFilter == 0x2703;
      goto LAB_97bd42d0;
    }
  }
  if (*(short *)(textureState + 0x10) == -0x7ed3) {
    levelWidthF = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x5c]));
    linearTexelData = textureObject[level * 0x34 + 0x71];
  }
  else {
    if (*(short *)(textureState + 0x10) != 0x2900) {
      levelWidthF = *levelInfo;
      linearRecordIndex = level * 0x34 + 0x50;
      linearTexelData = textureObject[level * 0x34 + 0x70];
      goto LAB_97bd43d4;
    }
    levelWidthF = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x5c]));
    linearTexelData = textureObject[level * 0x34 + 0x72];
  }
  linearRecordIndex = level * 0x34 + 100;
LAB_97bd43d4:
  coordS = (float)((double)(coordS * levelWidthF) + DOUBLE_97c30a88);
  scaledT = DOUBLE_97c30a88 + 0.0;
  scaledR = DOUBLE_97c30a88 + 0.0;
  floorResult = _floor((double)coordS);
  texelCoordS = (uint)(int)floorResult;
  intCastScratch = (longlong)(int)texelCoordS;
  floorResult = _floor((double)(float)scaledT);
  texelCoordT = (int)floorResult;
  intCastScratch = (longlong)texelCoordT;
  floorResult = _floor((double)(float)scaledR);
  oneConst = DOUBLE_97c30a60;
  i2dHi1 = 0x43300000;
  texelCoordR = (int)floorResult;
  intCastScratch = (longlong)texelCoordR;
  i2dLo1 = texelCoordS ^ 0x80000000;
  sampleCoordS = texelCoordS;
  sampleCoordT = texelCoordT;
  fracS = (double)(coordS - (float)((double)CONCAT44(0x43300000,i2dLo1) - DOUBLE_97c30a58));
  sampleCoordR = texelCoordR;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&sampleCoordS);
  ((int (*)())_InterpreterTextureSamplerLoadTexel1D)(sampler,linearTexelData,textureObject + linearRecordIndex,&sampleCoordS,&texelHr);
  sampleCoordS = texelCoordS - 1;
  weightL = (float)(oneConst - fracS);
  sampleCoordT = texelCoordT;
  sampleCoordR = texelCoordR;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&sampleCoordS);
  loadTexelResult = (double)((int (*)())_InterpreterTextureSamplerLoadTexel1D)(sampler,linearTexelData,textureObject + linearRecordIndex,&sampleCoordS,&texelLr);
  *texelOut = (float)(fracS * (double)texelHr + (double)(weightL * texelLr));
  texelOut[3] = (float)(fracS * (double)texelHa + (double)(weightL * texelLa));
  texelOut[1] = (float)(fracS * (double)texelHg + (double)(weightL * texelLg));
  texelOut[2] = (float)(fracS * (double)texelHb + (double)(weightL * texelLb));
  return loadTexelResult;
}

/* _InterpreterTextureSamplerSampleTexel2DFromLevel @ 0x97bd457c (1196 bytes) */
double _InterpreterTextureSamplerSampleTexel2DFromLevel(int *sampler,uint textureUnit,int level,float *texCoord,float *texelOut,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int linearRecordIndex;
  int linearTexelData;
  int nearestRecordIndex;
  double loadTexelResult;
  float linearWidthF;
  float nearestWidthF;
  float weightHH;
  float weightLH;
  float linearHeightF;
  float nearestHeightF;
  double floorResult;
  double floorResult2;
  bool isLinearFilterCode;
  float coordS;
  float coordT;
  float weightHL;
  float weightLL;
  ushort minFilter;
  int *textureObject;
  int textureState;
  float *levelInfo;
  int nearestTexelData;
  double scaledR;
  double fracT;
  double fracS;
  uint texelCoordS;
  uint texelCoordT;
  int texelCoordR;
  longlong intCastScratch;
  float texelHHr;
  float texelHHg;
  float texelHHb;
  float texelHHa;
  float texelHLr;
  float texelHLg;
  float texelHLb;
  float texelHLa;
  float texelLHr;
  float texelLHg;
  float texelLHb;
  float texelLHa;
  float texelLLr;
  float texelLLg;
  float texelLLb;
  float texelLLa;
  uint sampleCoordS;
  uint sampleCoordT;
  int sampleCoordR;
  undefined4 i2dHi1;
  uint i2dLo1;
  
  if (7 < textureUnit) {
    textureUnit = 7;
  }
  textureObject = *(int **)(*sampler + textureUnit * 4);
  if (textureObject == (int *)0x0) {
    return fparam_1;
  }
  sampler[1] = (int)textureObject;
  levelInfo = (float *)(textureObject + level * 0x34 + 0x48);
  sampler[2] = (int)levelInfo;
  if (sampler[8] == 0) {
    coordT = texCoord[1];
    coordS = *texCoord;
  }
  else {
    coordT = texCoord[1] / texCoord[3];
    coordS = *texCoord / texCoord[3];
  }
  textureState = *textureObject;
  minFilter = *(ushort *)(textureState + 0x16);
  if (minFilter == 0x2700) {
LAB_97bd4648:
    if ((*(short *)(textureState + 0x10) == -0x7ed3) || (*(short *)(textureState + 0x12) == -0x7ed3)) {
      nearestWidthF = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x5c]));
      nearestRecordIndex = level * 0x34 + 100;
      nearestTexelData = textureObject[level * 0x34 + 0x71];
      nearestHeightF = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x5d]));
    }
    else {
      nearestWidthF = *levelInfo;
      nearestRecordIndex = level * 0x34 + 0x50;
      nearestTexelData = textureObject[level * 0x34 + 0x70];
      nearestHeightF = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x49]));
    }
    texelCoordS = (uint)(coordS * nearestWidthF);
    texelCoordT = (uint)(int)(coordT * nearestHeightF);
    intCastScratch = 0;
    texelCoordR = 0;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&texelCoordS);
    loadTexelResult = (double)((int (*)())_InterpreterTextureSamplerLoadTexel2D)(sampler,nearestTexelData,textureObject + nearestRecordIndex,&texelCoordS,texelOut);
    return loadTexelResult;
  }
  if (minFilter < 0x2701) {
    if (minFilter == 0x2600) goto LAB_97bd4648;
    isLinearFilterCode = minFilter == 0x2601;
LAB_97bd4640:
    if (!isLinearFilterCode) {
      return fparam_1;
    }
  }
  else {
    if (minFilter == 0x2702) goto LAB_97bd4648;
    if (0x2701 < minFilter) {
      isLinearFilterCode = minFilter == 0x2703;
      goto LAB_97bd4640;
    }
  }
  if ((*(short *)(textureState + 0x10) == -0x7ed3) || (*(short *)(textureState + 0x12) == -0x7ed3)) {
    linearWidthF = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x5c]));
    linearTexelData = textureObject[level * 0x34 + 0x71];
  }
  else {
    if ((*(short *)(textureState + 0x10) != 0x2900) && (*(short *)(textureState + 0x12) != 0x2900)) {
      linearWidthF = *levelInfo;
      linearRecordIndex = level * 0x34 + 0x50;
      linearTexelData = textureObject[level * 0x34 + 0x70];
      linearHeightF = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x49]));
      goto LAB_97bd479c;
    }
    linearWidthF = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x5c]));
    linearTexelData = textureObject[level * 0x34 + 0x72];
  }
  linearRecordIndex = level * 0x34 + 100;
  linearHeightF = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x5d]));
LAB_97bd479c:
  textureObject = textureObject + linearRecordIndex;
  coordS = (float)((double)(coordS * linearWidthF) + DOUBLE_97c30a88);
  scaledR = DOUBLE_97c30a88 + 0.0;
  coordT = (float)((double)(coordT * linearHeightF) + DOUBLE_97c30a88);
  floorResult = _floor((double)coordS);
  texelCoordS = (uint)(int)floorResult;
  intCastScratch = (longlong)(int)texelCoordS;
  floorResult = _floor((double)coordT);
  texelCoordT = (uint)(int)floorResult;
  intCastScratch = (longlong)(int)texelCoordT;
  floorResult2 = _floor((double)(float)scaledR);
  i2dHi1 = 0x43300000;
  i2dLo1 = texelCoordT ^ 0x80000000;
  sampleCoordT = texelCoordT;
  sampleCoordS = texelCoordS;
  fracS = (double)(coordS - (float)((double)CONCAT44(0x43300000,texelCoordS ^ 0x80000000) -
                                   DOUBLE_97c30a58));
  fracT = (double)(coordT - (float)((double)CONCAT44(0x43300000,i2dLo1) - DOUBLE_97c30a58));
  texelCoordR = (int)floorResult2;
  intCastScratch = (longlong)texelCoordR;
  weightHH = (float)(fracS * fracT);
  weightLH = (float)((double)(float)(DOUBLE_97c30a60 - fracS) * fracT);
  weightHL = (float)(fracS * (double)(float)(DOUBLE_97c30a60 - fracT));
  weightLL = (float)((double)(float)(DOUBLE_97c30a60 - fracS) *
                 (double)(float)(DOUBLE_97c30a60 - fracT));
  sampleCoordR = texelCoordR;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&sampleCoordS);
  ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(sampler,linearTexelData,textureObject,&sampleCoordS,&texelHHr);
  sampleCoordS = texelCoordS;
  sampleCoordT = texelCoordT - 1;
  sampleCoordR = texelCoordR;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&sampleCoordS);
  ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(sampler,linearTexelData,textureObject,&sampleCoordS,&texelHLr);
  sampleCoordS = texelCoordS - 1;
  sampleCoordT = texelCoordT - 1;
  sampleCoordR = texelCoordR;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&sampleCoordS);
  ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(sampler,linearTexelData,textureObject,&sampleCoordS,&texelLLr);
  sampleCoordS = texelCoordS - 1;
  sampleCoordT = texelCoordT;
  sampleCoordR = texelCoordR;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&sampleCoordS);
  loadTexelResult = (double)((int (*)())_InterpreterTextureSamplerLoadTexel2D)(sampler,linearTexelData,textureObject,&sampleCoordS,&texelLHr);
  *texelOut = weightLL * texelLLr + weightLH * texelLHr + weightHH * texelHHr + weightHL * texelHLr;
  texelOut[3] = weightLL * texelLLa + weightLH * texelLHa + weightHH * texelHHa + weightHL * texelHLa;
  texelOut[1] = weightLL * texelLLg + weightLH * texelLHg + weightHH * texelHHg + weightHL * texelHLg;
  texelOut[2] = weightLL * texelLLb + weightLH * texelLHb + weightHH * texelHHb + weightHL * texelHLb;
  return loadTexelResult;
}

/* _InterpreterTextureSamplerSampleTexel3DFromLevel @ 0x97bd4a28 (1768 bytes) */
double _InterpreterTextureSamplerSampleTexel3DFromLevel(int *sampler,uint textureUnit,int level,float *texCoord,float *texelOut,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11)
{
  float scaledR;
  float scaledT;
  float levelWidthOrScaledS;
  float nearestWidthF;
  int linearRecordIndex;
  int linearTexelData;
  int nearestRecordIndex;
  double fracR;
  float floatValue;
  float linearHeightF;
  float nearestDepthF;
  double floorResult;
  bool isLinearFilterCode;
  float weightLHH;
  float weightLLL;
  float weightLLH;
  float weightHLL;
  float weightHLH;
  float weightHHL;
  float weightHHH;
  float weightLHL;
  ushort minFilter;
  int textureState;
  int *textureObject;
  float *levelInfo;
  int nearestTexelData;
  double dVar15;
  double fracT;
  double weight2dLH;
  double fracS;
  double weight2dHL;
  double oneMinusFracR;
  double weight2dLL;
  float coordS;
  float coordT;
  float coordR;
  uint texelCoordS;
  uint texelCoordT;
  uint texelCoordR;
  longlong intCastScratch;
  float texelHHHr;
  float texelHHHg;
  float texelHHHb;
  float texelHHHa;
  float texelHLHr;
  float texelHLHg;
  float texelHLHb;
  float texelHLHa;
  float texelLHHr;
  float texelLHHg;
  float texelLHHb;
  float texelLHHa;
  float texelLLHr;
  float texelLLHg;
  float texelLLHb;
  float texelLLHa;
  float texelHHLr;
  float texelHHLg;
  float texelHHLb;
  float texelHHLa;
  float texelHLLr;
  float texelHLLg;
  float texelHLLb;
  float texelHLLa;
  float texelLHLr;
  float texelLHLg;
  float texelLHLb;
  float texelLHLa;
  float texelLLLr;
  float texelLLLg;
  float texelLLLb;
  float texelLLLa;
  uint sampleCoordS;
  uint sampleCoordT;
  uint sampleCoordR;
  undefined4 i2dHi1;
  uint i2dLo1;
  
  if (7 < textureUnit) {
    textureUnit = 7;
  }
  textureObject = *(int **)(*sampler + textureUnit * 4);
  if (textureObject == (int *)0x0) {
    return fparam_1;
  }
  sampler[1] = (int)textureObject;
  levelInfo = (float *)(textureObject + level * 0x34 + 0x48);
  sampler[2] = (int)levelInfo;
  if (sampler[8] == 0) {
    coordR = texCoord[2];
    coordS = *texCoord;
    coordT = texCoord[1];
  }
  else {
    coordT = texCoord[3];
    coordS = *texCoord / coordT;
    coordR = texCoord[2] / coordT;
    coordT = texCoord[1] / coordT;
  }
  textureState = *textureObject;
  minFilter = *(ushort *)(textureState + 0x16);
  if (minFilter == 0x2700) {
LAB_97bd4b08:
    if (((*(short *)(textureState + 0x10) == -0x7ed3) || (*(short *)(textureState + 0x12) == -0x7ed3)) ||
       (*(short *)(textureState + 0x14) == -0x7ed3)) {
      nearestWidthF = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x5c]));
      nearestRecordIndex = level * 0x34 + 100;
      nearestTexelData = textureObject[level * 0x34 + 0x71];
      floatValue = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x5d]));
      nearestDepthF = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x5e]));
    }
    else {
      nearestWidthF = *levelInfo;
      nearestRecordIndex = level * 0x34 + 0x50;
      nearestTexelData = textureObject[level * 0x34 + 0x70];
      floatValue = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x49]));
      nearestDepthF = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x4a]));
    }
    texelCoordS = (uint)(int)(coordS * nearestWidthF);
    texelCoordT = (uint)(int)(coordT * floatValue);
    texelCoordR = (uint)(int)(coordR * nearestDepthF);
    intCastScratch = (longlong)(int)texelCoordR;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&texelCoordS);
    dVar15 = (double)((int (*)())_InterpreterTextureSamplerLoadTexel3D)(sampler,nearestTexelData,textureObject + nearestRecordIndex,&texelCoordS,texelOut);
    return dVar15;
  }
  if (minFilter < 0x2701) {
    if (minFilter == 0x2600) goto LAB_97bd4b08;
    isLinearFilterCode = minFilter == 0x2601;
LAB_97bd4b00:
    if (!isLinearFilterCode) {
      return fparam_1;
    }
  }
  else {
    if (minFilter == 0x2702) goto LAB_97bd4b08;
    if (0x2701 < minFilter) {
      isLinearFilterCode = minFilter == 0x2703;
      goto LAB_97bd4b00;
    }
  }
  if (((*(short *)(textureState + 0x10) == -0x7ed3) || (*(short *)(textureState + 0x12) == -0x7ed3)) ||
     (*(short *)(textureState + 0x14) == -0x7ed3)) {
    levelWidthOrScaledS = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x5c]));
    linearTexelData = textureObject[level * 0x34 + 0x71];
  }
  else {
    if (((*(short *)(textureState + 0x10) != 0x2900) && (*(short *)(textureState + 0x12) != 0x2900)) &&
       (*(short *)(textureState + 0x14) != 0x2900)) {
      levelWidthOrScaledS = *levelInfo;
      linearRecordIndex = level * 0x34 + 0x50;
      linearTexelData = textureObject[level * 0x34 + 0x70];
      linearHeightF = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x49]));
      floatValue = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x4a]));
      goto LAB_97bd4cb4;
    }
    levelWidthOrScaledS = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x5c]));
    linearTexelData = textureObject[level * 0x34 + 0x72];
  }
  linearRecordIndex = level * 0x34 + 100;
  linearHeightF = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x5d]));
  floatValue = GH_U2F((unsigned int)(textureObject[level * 0x34 + 0x5e]));
LAB_97bd4cb4:
  textureObject = textureObject + linearRecordIndex;
  levelWidthOrScaledS = (float)((double)(coordS * levelWidthOrScaledS) + DOUBLE_97c30a88);
  scaledT = (float)((double)(coordT * linearHeightF) + DOUBLE_97c30a88);
  scaledR = (float)((double)(coordR * floatValue) + DOUBLE_97c30a88);
  floorResult = _floor((double)levelWidthOrScaledS);
  texelCoordS = (uint)(int)floorResult;
  intCastScratch = (longlong)(int)texelCoordS;
  floorResult = _floor((double)scaledT);
  texelCoordT = (uint)(int)floorResult;
  intCastScratch = (longlong)(int)texelCoordT;
  floorResult = _floor((double)scaledR);
  texelCoordR = (uint)(int)floorResult;
  intCastScratch = (longlong)(int)texelCoordR;
  i2dHi1 = 0x43300000;
  i2dLo1 = texelCoordR ^ 0x80000000;
  sampleCoordT = texelCoordT;
  fracS = (double)(levelWidthOrScaledS - (float)((double)CONCAT44(0x43300000,texelCoordS ^ 0x80000000) -
                                   DOUBLE_97c30a58));
  sampleCoordS = texelCoordS;
  fracT = (double)(scaledT - (float)((double)CONCAT44(0x43300000,texelCoordT ^ 0x80000000) -
                                   DOUBLE_97c30a58));
  fracR = (double)(scaledR - (float)((double)CONCAT44(0x43300000,i2dLo1) - DOUBLE_97c30a58));
  oneMinusFracR = (double)(float)(DOUBLE_97c30a60 - fracR);
  weight2dHL = (double)(float)(fracS * (double)(float)(DOUBLE_97c30a60 - fracT));
  weight2dLH = (double)(float)((double)(float)(DOUBLE_97c30a60 - fracS) * fracT);
  weight2dLL = (double)(float)((double)(float)(DOUBLE_97c30a60 - fracS) *
                          (double)(float)(DOUBLE_97c30a60 - fracT));
  weightHHL = (float)((double)(float)(fracS * fracT) * oneMinusFracR);
  weightLHL = (float)(weight2dLH * oneMinusFracR);
  weightHHH = (float)((double)(float)(fracS * fracT) * fracR);
  weightLHH = (float)(weight2dLH * fracR);
  weightLLL = (float)(weight2dLL * oneMinusFracR);
  weightLLH = (float)(weight2dLL * fracR);
  weightHLL = (float)(weight2dHL * oneMinusFracR);
  weightHLH = (float)(weight2dHL * fracR);
  sampleCoordR = texelCoordR;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&sampleCoordS);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(sampler,linearTexelData,textureObject,&sampleCoordS,&texelHHHr);
  sampleCoordS = texelCoordS;
  sampleCoordT = texelCoordT - 1;
  sampleCoordR = texelCoordR;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&sampleCoordS);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(sampler,linearTexelData,textureObject,&sampleCoordS,&texelHLHr);
  sampleCoordS = texelCoordS - 1;
  sampleCoordT = texelCoordT - 1;
  sampleCoordR = texelCoordR;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&sampleCoordS);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(sampler,linearTexelData,textureObject,&sampleCoordS,&texelLLHr);
  sampleCoordS = texelCoordS - 1;
  sampleCoordT = texelCoordT;
  sampleCoordR = texelCoordR;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&sampleCoordS);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(sampler,linearTexelData,textureObject,&sampleCoordS,&texelLHHr);
  sampleCoordR = texelCoordR - 1;
  sampleCoordS = texelCoordS;
  sampleCoordT = texelCoordT;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&sampleCoordS);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(sampler,linearTexelData,textureObject,&sampleCoordS,&texelHHLr);
  sampleCoordT = texelCoordT - 1;
  sampleCoordR = texelCoordR - 1;
  sampleCoordS = texelCoordS;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&sampleCoordS);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(sampler,linearTexelData,textureObject,&sampleCoordS,&texelHLLr);
  sampleCoordS = texelCoordS - 1;
  sampleCoordT = texelCoordT - 1;
  sampleCoordR = texelCoordR - 1;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&sampleCoordS);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(sampler,linearTexelData,textureObject,&sampleCoordS,&texelLLLr);
  sampleCoordS = texelCoordS - 1;
  sampleCoordR = texelCoordR - 1;
  sampleCoordT = texelCoordT;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&sampleCoordS);
  dVar15 = (double)((int (*)())_InterpreterTextureSamplerLoadTexel3D)(sampler,linearTexelData,textureObject,&sampleCoordS,&texelLHLr)
  ;
  *texelOut = weightLLL * texelLLLr +
             weightLHL * texelLHLr +
             weightHLL * texelHLLr +
             weightHHL * texelHHLr +
             weightLLH * texelLLHr + weightLHH * texelLHHr + weightHHH * texelHHHr + weightHLH * texelHLHr;
  texelOut[1] = weightLLL * texelLLLg +
               weightLHL * texelLHLg +
               weightHLL * texelHLLg +
               weightHHL * texelHHLg +
               weightLLH * texelLLHg + weightLHH * texelLHHg + weightHHH * texelHHHg + weightHLH * texelHLHg;
  texelOut[2] = weightLLL * texelLLLb +
               weightLHL * texelLHLb +
               weightHLL * texelHLLb +
               weightHHL * texelHHLb +
               weightLLH * texelLLHb + weightLHH * texelLHHb + weightHHH * texelHHHb + weightHLH * texelHLHb;
  texelOut[3] = weightLLL * texelLLLa +
               weightLHL * texelLHLa +
               weightHLL * texelHLLa +
               weightHHL * texelHHLa +
               weightLLH * texelLLHa + weightLHH * texelLHHa + weightHHH * texelHHHa + weightHLH * texelHLHa;
  return dVar15;
}

/* _InterpreterTextureSamplerSampleTexelRECTFromLevel @ 0x97bd5110 (1056 bytes) */
int _InterpreterTextureSamplerSampleTexelRECTFromLevel(sampler, textureUnit, level, texCoord, texelOut)
  int *sampler;
  uint textureUnit;
  int level;
  float *texCoord;
  float *texelOut;
{
  int linearTexelData;
  int nearestRecordIndex;
  float weightLH;
  float weightHH;
  double floorResult;
  double floorResult2;
  bool isLinearFilterCode;
  float weightHL;
  float weightLL;
  float scaledS;
  float scaledT;
  ushort minFilter;
  int *textureObject;
  int textureState;
  int *linearRecord;
  int nearestTexelData;
  double scaledR;
  double fracT;
  double fracS;
  uint texelCoordS;
  uint texelCoordT;
  int texelCoordR;
  longlong intCastScratch;
  float texelHHr;
  float texelHHg;
  float texelHHb;
  float texelHHa;
  float texelHLr;
  float texelHLg;
  float texelHLb;
  float texelHLa;
  float texelLHr;
  float texelLHg;
  float texelLHb;
  float texelLHa;
  float texelLLr;
  float texelLLg;
  float texelLLb;
  float texelLLa;
  uint sampleCoordS;
  uint sampleCoordT;
  int sampleCoordR;
  undefined4 i2dHi1;
  uint i2dLo1;
  
  if (7 < textureUnit) {
    textureUnit = 7;
  }
  textureObject = *(int **)(*sampler + textureUnit * 4);
  if (textureObject == (int *)0x0) {
    return;
  }
  sampler[1] = (int)textureObject;
  sampler[2] = (int)(textureObject + level * 0x34 + 0x48);
  textureState = *textureObject;
  minFilter = *(ushort *)(textureState + 0x16);
  if (minFilter == 0x2700) {
LAB_97bd51b8:
    if ((*(short *)(textureState + 0x10) == -0x7ed3) || (*(short *)(textureState + 0x12) == -0x7ed3)) {
      nearestRecordIndex = level * 0x34 + 100;
      nearestTexelData = textureObject[level * 0x34 + 0x71];
    }
    else {
      nearestTexelData = textureObject[level * 0x34 + 0x70];
      nearestRecordIndex = level * 0x34 + 0x50;
    }
    texelCoordS = (uint)*texCoord;
    texelCoordT = (uint)(int)texCoord[1];
    intCastScratch = 0;
    texelCoordR = 0;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&texelCoordS);
    ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(sampler,nearestTexelData,textureObject + nearestRecordIndex,&texelCoordS,texelOut);
  }
  else {
    if (minFilter < 0x2701) {
      if (minFilter == 0x2600) goto LAB_97bd51b8;
      isLinearFilterCode = minFilter == 0x2601;
LAB_97bd51b0:
      if (!isLinearFilterCode) {
        return;
      }
    }
    else {
      if (minFilter == 0x2702) goto LAB_97bd51b8;
      if (0x2701 < minFilter) {
        isLinearFilterCode = minFilter == 0x2703;
        goto LAB_97bd51b0;
      }
    }
    if ((*(short *)(textureState + 0x10) == -0x7ed3) || (*(short *)(textureState + 0x12) == -0x7ed3)) {
      linearRecord = textureObject + level * 0x34 + 100;
      linearTexelData = textureObject[level * 0x34 + 0x71];
    }
    else if ((*(short *)(textureState + 0x10) == 0x2900) || (*(short *)(textureState + 0x12) == 0x2900)) {
      linearRecord = textureObject + level * 0x34 + 100;
      linearTexelData = textureObject[level * 0x34 + 0x72];
    }
    else {
      linearTexelData = textureObject[level * 0x34 + 0x70];
      linearRecord = textureObject + level * 0x34 + 0x50;
    }
    scaledS = (float)((double)*texCoord + DOUBLE_97c30a88);
    scaledR = DOUBLE_97c30a88 + 0.0;
    scaledT = (float)((double)texCoord[1] + DOUBLE_97c30a88);
    floorResult = _floor((double)scaledS);
    texelCoordS = (uint)(int)floorResult;
    intCastScratch = (longlong)(int)texelCoordS;
    floorResult = _floor((double)scaledT);
    texelCoordT = (uint)(int)floorResult;
    intCastScratch = (longlong)(int)texelCoordT;
    floorResult2 = _floor((double)(float)scaledR);
    i2dHi1 = 0x43300000;
    i2dLo1 = texelCoordT ^ 0x80000000;
    sampleCoordT = texelCoordT;
    sampleCoordS = texelCoordS;
    fracS = (double)(scaledS - (float)((double)CONCAT44(0x43300000,texelCoordS ^ 0x80000000) -
                                     DOUBLE_97c30a58));
    fracT = (double)(scaledT - (float)((double)CONCAT44(0x43300000,i2dLo1) - DOUBLE_97c30a58));
    texelCoordR = (int)floorResult2;
    intCastScratch = (longlong)texelCoordR;
    weightHH = (float)(fracS * fracT);
    weightLH = (float)((double)(float)(DOUBLE_97c30a60 - fracS) * fracT);
    weightHL = (float)(fracS * (double)(float)(DOUBLE_97c30a60 - fracT));
    weightLL = (float)((double)(float)(DOUBLE_97c30a60 - fracS) *
                   (double)(float)(DOUBLE_97c30a60 - fracT));
    sampleCoordR = texelCoordR;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&sampleCoordS);
    ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(sampler,linearTexelData,linearRecord,&sampleCoordS,&texelHHr);
    sampleCoordS = texelCoordS;
    sampleCoordT = texelCoordT - 1;
    sampleCoordR = texelCoordR;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&sampleCoordS);
    ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(sampler,linearTexelData,linearRecord,&sampleCoordS,&texelHLr);
    sampleCoordS = texelCoordS - 1;
    sampleCoordT = texelCoordT - 1;
    sampleCoordR = texelCoordR;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&sampleCoordS);
    ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(sampler,linearTexelData,linearRecord,&sampleCoordS,&texelLLr);
    sampleCoordS = texelCoordS - 1;
    sampleCoordT = texelCoordT;
    sampleCoordR = texelCoordR;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(sampler,&sampleCoordS);
    ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(sampler,linearTexelData,linearRecord,&sampleCoordS,&texelLHr);
    *texelOut = weightLL * texelLLr + weightLH * texelLHr + weightHH * texelHHr + weightHL * texelHLr;
    texelOut[3] = weightLL * texelLLa + weightLH * texelLHa + weightHH * texelHHa + weightHL * texelHLa;
    texelOut[1] = weightLL * texelLLg + weightLH * texelLHg + weightHH * texelHHg + weightHL * texelHLg;
    texelOut[2] = weightLL * texelLLb + weightLH * texelLHb + weightHH * texelHHb + weightHL * texelHLb;
  }
  return;
}

/* _InterpreterTextureSamplerLoadTexel1D @ 0x97bd5530 (172 bytes) */
int _InterpreterTextureSamplerLoadTexel1D(sampler, texelData, unusedLevelRecord, texelCoord, texelOut)
  int sampler;
  int texelData;
  undefined4 unusedLevelRecord;
  int *texelCoord;
  undefined4 *texelOut;
{
  undefined4 *texelPtr;
  uint texelType;
  
  texelType = *(uint *)(*(int *)(sampler + 4) + 0xae4);
  if (texelType < 0x8368) {
    if (0x8365 < texelType) {
      return;
    }
    if (texelType != 0x1406) {
      if (texelType < 0x1407) {
        if (texelType == 0x1401) {
          return;
        }
      }
      else {
        if (texelType == 0x8033) {
          return;
        }
        if (texelType == 0x8363) {
          return;
        }
      }
    }
  }
  else {
    if (texelType == 0x8815) {
      return;
    }
    if ((0x8815 < texelType) && (texelType - 0x881a < 2)) {
      return;
    }
  }
  texelPtr = (undefined4 *)(texelData + *texelCoord * 0x10);
  *texelOut = *texelPtr;
  texelOut[1] = texelPtr[1];
  texelOut[2] = texelPtr[2];
  texelOut[3] = texelPtr[3];
  return;
}

/* _InterpreterTextureSamplerLoadTexel2D @ 0x97bd55dc (188 bytes) */
int _InterpreterTextureSamplerLoadTexel2D(sampler, texelData, levelRecord, texelCoord, texelOut)
  int sampler;
  int texelData;
  int *levelRecord;
  int *texelCoord;
  undefined4 *texelOut;
{
  undefined4 *texelPtr;
  uint texelType;
  
  texelType = *(uint *)(*(int *)(sampler + 4) + 0xae4);
  if (texelType < 0x8368) {
    if (0x8365 < texelType) {
      return;
    }
    if (texelType != 0x1406) {
      if (texelType < 0x1407) {
        if (texelType == 0x1401) {
          return;
        }
      }
      else {
        if (texelType == 0x8033) {
          return;
        }
        if (texelType == 0x8363) {
          return;
        }
      }
    }
  }
  else {
    if (texelType == 0x8815) {
      return;
    }
    if ((0x8815 < texelType) && (texelType - 0x881a < 2)) {
      return;
    }
  }
  texelPtr = (undefined4 *)(texelData + (texelCoord[1] * *levelRecord + *texelCoord) * 0x10);
  *texelOut = *texelPtr;
  texelOut[1] = texelPtr[1];
  texelOut[2] = texelPtr[2];
  texelOut[3] = texelPtr[3];
  return;
}

/* _InterpreterTextureSamplerLoadTexel3D @ 0x97bd5698 (204 bytes) */
int _InterpreterTextureSamplerLoadTexel3D(sampler, texelData, levelRecord, texelCoord, texelOut)
  int sampler;
  int texelData;
  int *levelRecord;
  int *texelCoord;
  undefined4 *texelOut;
{
  undefined4 *texelPtr;
  uint texelType;
  
  texelType = *(uint *)(*(int *)(sampler + 4) + 0xae4);
  if (texelType < 0x8368) {
    if (0x8365 < texelType) {
      return;
    }
    if (texelType != 0x1406) {
      if (texelType < 0x1407) {
        if (texelType == 0x1401) {
          return;
        }
      }
      else {
        if (texelType == 0x8033) {
          return;
        }
        if (texelType == 0x8363) {
          return;
        }
      }
    }
  }
  else {
    if (texelType == 0x8815) {
      return;
    }
    if ((0x8815 < texelType) && (texelType - 0x881a < 2)) {
      return;
    }
  }
  texelPtr = (undefined4 *)
           (texelData + ((texelCoord[2] * levelRecord[1] + texelCoord[1]) * *levelRecord + *texelCoord) * 0x10);
  *texelOut = *texelPtr;
  texelOut[1] = texelPtr[1];
  texelOut[2] = texelPtr[2];
  texelOut[3] = texelPtr[3];
  return;
}

/* _InterpreterNoiseGeneratorCreate @ 0x97bd5764 (60 bytes) */
int _InterpreterNoiseGeneratorCreate()
{
  undefined4 allocation;
  
  allocation = _calloc(0xa20,1);
  ((int (*)())_InterpreterNoiseGeneratorInitialise)(allocation);
  return allocation;
}

/* _InterpreterNoiseGeneratorInitialise @ 0x97bd57a0 (280 bytes) */
int _InterpreterNoiseGeneratorInitialise(noise)
  undefined1 *noise;
{
  uint loopIndex;
  undefined1 swapTemp;
  undefined4 gradientCopy;
  uint randomValue;
  int swapIndex;
  float *gradientPtr;
  uint shuffleRandom;
  undefined1 *permPtr;
  
  _memset(noise,0,0xa20);
  loopIndex = 0;
  gradientPtr = (float *)(noise + 0x210);
  do {
    noise[loopIndex] = (char)loopIndex;
    randomValue = _random();
    loopIndex = loopIndex + 1;
    *gradientPtr = (float)(((double)CONCAT44(0x43300000,
                                        (randomValue + (((int)randomValue >> 9) +
                                                 (uint)((int)randomValue < 0 && (randomValue & 0x1ff) != 0)) *
                                                 -0x200) - 0x100 ^ 0x80000000) - 4503601774854144.0)
                     * 0.00390625);
    gradientPtr = gradientPtr + 1;
  } while (loopIndex < 0x100);
  permPtr = noise + 0xff;
  do {
    swapTemp = *permPtr;
    shuffleRandom = _random();
    swapIndex = shuffleRandom + (((int)shuffleRandom >> 8) + (uint)((int)shuffleRandom < 0 && (shuffleRandom & 0xff) != 0)) * -0x100;
    *permPtr = noise[swapIndex];
    permPtr = permPtr + -1;
    noise[swapIndex] = swapTemp;
  } while (permPtr != noise);
  swapIndex = 0x102;
  permPtr = noise;
  do {
    gradientCopy = *(undefined4 *)(permPtr + 0x210);
    noise[0x100] = *noise;
    noise = noise + 1;
    *(undefined4 *)(permPtr + 0x610) = gradientCopy;
    permPtr = permPtr + 4;
    swapIndex = swapIndex + -1;
  } while (swapIndex != 0);
  return permPtr;
}

/* _InterpreterNoiseGeneratorSmoothHermiteCurve @ 0x97bd58bc (156 bytes) */
int _InterpreterNoiseGeneratorSmoothHermiteCurve(noise, fraction, curve)
  undefined4 noise;
  float *fraction;
  float *curve;
{
  double threeConst;
  double fractionD;
  
  threeConst = DOUBLE_97c30a80;
  fractionD = (double)*fraction;
  *curve = (float)((double)(float)(fractionD * fractionD) * (DOUBLE_97c30a80 - (fractionD + fractionD)));
  fractionD = (double)fraction[1];
  curve[1] = (float)((double)(float)(fractionD * fractionD) * (threeConst - (fractionD + fractionD)));
  fractionD = (double)fraction[2];
  curve[2] = (float)((double)(float)(fractionD * fractionD) * (threeConst - (fractionD + fractionD)));
  fractionD = (double)fraction[3];
  curve[3] = (float)((double)(float)(fractionD * fractionD) * (threeConst - (fractionD + fractionD)));
  return;
}

/* _InterpreterNoiseGeneratorInterpolate @ 0x97bd5958 (100 bytes) */
int _InterpreterNoiseGeneratorInterpolate(noise, vecA, vecB, weight, result)
  undefined4 noise;
  float *vecA;
  float *vecB;
  float *weight;
  float *result;
{
  *result = *weight * (*vecB - *vecA) + *vecA;
  result[1] = weight[1] * (vecB[1] - vecA[1]) + vecA[1];
  result[2] = weight[2] * (vecB[2] - vecA[2]) + vecA[2];
  result[3] = weight[3] * (vecB[3] - vecA[3]) + vecA[3];
  return;
}

/* _InterpreterNoiseGeneratorInterpolatedNoise1D @ 0x97bd59bc (476 bytes) */
double _InterpreterNoiseGeneratorInterpolatedNoise1D(int noise,float *point)
{
  uint cellX;
  double floorResult;
  double floorResult2;
  float fracX;
  float fracY;
  float fracZ;
  undefined4 fracPad;
  undefined4 smooth [4];
  undefined4 lerpWeight0;
  undefined4 lerpWeight1;
  undefined4 lerpWeight2;
  undefined4 lerpWeight3;
  float lerpA0;
  undefined4 lerpA1;
  undefined4 lerpA2;
  undefined4 lerpA3;
  undefined4 lerpB0;
  undefined4 lerpB1;
  undefined4 lerpB2;
  float lerpB3;
  longlong intCastScratch;
  undefined4 i2dHi1;
  uint i2dLo1;
  
  floorResult = _floor((double)*point);
  cellX = (uint)(int)floorResult;
  intCastScratch = (longlong)(int)cellX;
  floorResult = _floor((double)point[1]);
  intCastScratch = (longlong)(int)floorResult;
  floorResult2 = _floor((double)point[2]);
  intCastScratch = (longlong)(int)floorResult2;
  i2dHi1 = 0x43300000;
  i2dLo1 = (int)floorResult2 ^ 0x80000000;
  fracX = *point - (float)((double)CONCAT44(0x43300000,cellX ^ 0x80000000) - DOUBLE_97c30a58);
  fracZ = point[2] - (float)((double)CONCAT44(0x43300000,i2dLo1) - DOUBLE_97c30a58);
  fracY = point[1] -
             (float)((double)CONCAT44(0x43300000,(int)floorResult ^ 0x80000000) - DOUBLE_97c30a58);
  fracPad = 0;
  ((int (*)())_InterpreterNoiseGeneratorSmoothHermiteCurve)(noise,&fracX,smooth);
  lerpA0 = *(float *)((uint)*(byte *)(noise + (cellX & 0xff)) * 4 + noise + 0x210);
  lerpA1 = *(undefined4 *)
              ((uint)*(byte *)(noise + ((cellX & 0xff) + 1 & 0xff)) * 4 + noise + 0x210);
  lerpB2 = 0;
  lerpA2 = 0;
  lerpA3 = 0;
  lerpB1 = 0;
  lerpWeight3 = smooth[0];
  lerpWeight0 = smooth[0];
  lerpWeight1 = smooth[0];
  lerpWeight2 = smooth[0];
  lerpB0 = lerpA1;
  lerpB3 = lerpA0;
  ((int (*)())_InterpreterNoiseGeneratorInterpolate)(noise,&lerpA0,&lerpB0,&lerpWeight0,&lerpA0);
  return (double)lerpA0;
}

/* _InterpreterNoiseGeneratorInterpolatedNoise2D @ 0x97bd5b98 (544 bytes) */
double _InterpreterNoiseGeneratorInterpolatedNoise2D(int noise,float *point)
{
  uint cellY1;
  uint cellX;
  uint cellY;
  uint permX0;
  uint permX1;
  double floorResult;
  float fracX;
  float fracY;
  undefined4 fracPad2;
  undefined4 fracPad;
  undefined4 smoothX;
  undefined4 smoothY;
  undefined4 lerpWeight0;
  undefined4 lerpWeight1;
  undefined4 lerpWeight2;
  undefined4 lerpWeight3;
  float lerpA0;
  undefined4 lerpA1;
  undefined4 lerpA2;
  undefined4 lerpA3;
  undefined4 lerpB0;
  undefined4 lerpB1;
  float lerpB2;
  float lerpB3;
  longlong intCastScratch;
  undefined4 i2dHi1;
  uint i2dLo1;
  
  floorResult = _floor((double)*point);
  cellX = (uint)(int)floorResult;
  intCastScratch = (longlong)(int)cellX;
  floorResult = _floor((double)point[1]);
  cellY = (uint)(int)floorResult;
  intCastScratch = (longlong)(int)cellY;
  i2dHi1 = 0x43300000;
  i2dLo1 = cellY ^ 0x80000000;
  cellY = cellY & 0xff;
  fracPad = 0;
  fracX = *point - (float)((double)CONCAT44(0x43300000,cellX ^ 0x80000000) - DOUBLE_97c30a58);
  fracY = point[1] - (float)((double)CONCAT44(0x43300000,i2dLo1) - DOUBLE_97c30a58);
  fracPad2 = 0;
  ((int (*)())_InterpreterNoiseGeneratorSmoothHermiteCurve)(noise,&fracX,&smoothX);
  permX0 = (uint)*(byte *)(noise + (cellX & 0xff));
  permX1 = (uint)*(byte *)(noise + ((cellX & 0xff) + 1 & 0xff));
  cellY1 = cellY + 1 & 0xff;
  lerpA0 = *(float *)(((permX0 + cellY) * 4 & 0x3fc) + noise + 0x210);
  lerpA1 = *(undefined4 *)(((permX1 + cellY) * 4 & 0x3fc) + noise + 0x210);
  lerpA2 = *(undefined4 *)(((permX0 + cellY1) * 4 & 0x3fc) + noise + 0x210);
  lerpA3 = *(undefined4 *)(((permX1 + cellY1) * 4 & 0x3fc) + noise + 0x210);
  lerpWeight3 = smoothX;
  lerpWeight0 = smoothX;
  lerpWeight1 = smoothX;
  lerpWeight2 = smoothX;
  lerpB0 = lerpA1;
  lerpB1 = lerpA2;
  lerpB2 = GH_U2F((unsigned int)(lerpA3));
  lerpB3 = lerpA0;
  ((int (*)())_InterpreterNoiseGeneratorInterpolate)(noise,&lerpA0,&lerpB0,&lerpWeight0,&lerpA0);
  lerpB0 = lerpA2;
  lerpB1 = lerpA3;
  lerpB2 = lerpA0;
  lerpB3 = GH_U2F((unsigned int)(lerpA1));
  lerpWeight3 = smoothY;
  lerpWeight0 = smoothY;
  lerpWeight1 = smoothY;
  lerpWeight2 = smoothY;
  ((int (*)())_InterpreterNoiseGeneratorInterpolate)(noise,&lerpA0,&lerpB0,&lerpWeight0,&lerpA0);
  return (double)lerpA0;
}

/* _InterpreterNoiseGeneratorInterpolatedNoise3D @ 0x97bd5db8 (784 bytes) */
double _InterpreterNoiseGeneratorInterpolatedNoise3D(int noise,float *point)
{
  int permRow1;
  uint cellY1OrPermX1Y1;
  uint permX1Y0;
  uint cellZ;
  uint cellY0;
  uint cellZ1;
  uint permX0Y0;
  uint cellX;
  uint permX0Y1;
  uint cellY;
  int permRow0;
  double floorResult;
  float fracX;
  float fracY;
  float fracZ;
  undefined4 fracPad;
  undefined4 smoothX;
  undefined4 smoothY;
  undefined4 smoothZ;
  undefined4 lerpWeight0;
  undefined4 lerpWeight1;
  undefined4 lerpWeight2;
  undefined4 lerpWeight3;
  float lerpA0;
  undefined4 lerpA1;
  undefined4 lerpA2;
  undefined4 lerpA3;
  undefined4 lerpB0;
  undefined4 lerpB1;
  float lerpB2;
  float lerpB3;
  longlong intCastScratch;
  undefined4 i2dHi1;
  uint i2dLo1;
  
  floorResult = _floor((double)*point);
  cellX = (uint)(int)floorResult;
  intCastScratch = (longlong)(int)cellX;
  floorResult = _floor((double)point[1]);
  cellY = (uint)(int)floorResult;
  intCastScratch = (longlong)(int)cellY;
  floorResult = _floor((double)point[2]);
  cellZ = (uint)(int)floorResult;
  intCastScratch = (longlong)(int)cellZ;
  i2dHi1 = 0x43300000;
  i2dLo1 = cellZ ^ 0x80000000;
  cellZ = cellZ & 0xff;
  cellY0 = cellY & 0xff;
  fracX = *point - (float)((double)CONCAT44(0x43300000,cellX ^ 0x80000000) - DOUBLE_97c30a58);
  fracZ = point[2] - (float)((double)CONCAT44(0x43300000,i2dLo1) - DOUBLE_97c30a58);
  fracPad = 0;
  fracY = point[1] - (float)((double)CONCAT44(0x43300000,cellY ^ 0x80000000) - DOUBLE_97c30a58)
  ;
  ((int (*)())_InterpreterNoiseGeneratorSmoothHermiteCurve)(noise,&fracX,&smoothX);
  cellY1OrPermX1Y1 = cellY0 + 1 & 0xff;
  cellZ1 = cellZ + 1 & 0xff;
  permRow0 = (uint)*(byte *)(noise + (cellX & 0xff)) + noise;
  permX0Y0 = (uint)*(byte *)(permRow0 + cellY0);
  permX0Y1 = (uint)*(byte *)(permRow0 + cellY1OrPermX1Y1);
  lerpA0 = *(float *)(((permX0Y0 + cellZ) * 4 & 0x3fc) + noise + 0x210);
  lerpA1 = *(undefined4 *)(((permX0Y1 + cellZ) * 4 & 0x3fc) + noise + 0x210);
  lerpA2 = *(undefined4 *)(((permX0Y0 + cellZ1) * 4 & 0x3fc) + noise + 0x210);
  lerpA3 = *(undefined4 *)(((permX0Y1 + cellZ1) * 4 & 0x3fc) + noise + 0x210);
  permRow1 = (uint)*(byte *)(noise + ((cellX & 0xff) + 1 & 0xff)) + noise;
  permX1Y0 = (uint)*(byte *)(permRow1 + cellY0);
  cellY1OrPermX1Y1 = (uint)*(byte *)(permRow1 + cellY1OrPermX1Y1);
  lerpB0 = *(undefined4 *)(((permX1Y0 + cellZ) * 4 & 0x3fc) + noise + 0x210);
  lerpB1 = *(undefined4 *)(((cellY1OrPermX1Y1 + cellZ) * 4 & 0x3fc) + noise + 0x210);
  lerpB2 = *(float *)(((permX1Y0 + cellZ1) * 4 & 0x3fc) + noise + 0x210);
  lerpB3 = *(float *)(((cellY1OrPermX1Y1 + cellZ1) * 4 & 0x3fc) + noise + 0x210);
  lerpWeight3 = smoothX;
  lerpWeight0 = smoothX;
  lerpWeight1 = smoothX;
  lerpWeight2 = smoothX;
  ((int (*)())_InterpreterNoiseGeneratorInterpolate)(noise,&lerpA0,&lerpB0,&lerpWeight0,&lerpA0);
  lerpB0 = lerpA1;
  lerpB1 = lerpA2;
  lerpWeight3 = smoothY;
  lerpB2 = GH_U2F((unsigned int)(lerpA3));
  lerpB3 = lerpA0;
  lerpWeight0 = smoothY;
  lerpWeight1 = smoothY;
  lerpWeight2 = smoothY;
  ((int (*)())_InterpreterNoiseGeneratorInterpolate)(noise,&lerpA0,&lerpB0,&lerpWeight0,&lerpA0);
  lerpB0 = lerpA2;
  lerpB1 = lerpA3;
  lerpWeight3 = smoothZ;
  lerpB2 = lerpA0;
  lerpB3 = GH_U2F((unsigned int)(lerpA1));
  lerpWeight0 = smoothZ;
  lerpWeight1 = smoothZ;
  lerpWeight2 = smoothZ;
  ((int (*)())_InterpreterNoiseGeneratorInterpolate)(noise,&lerpA0,&lerpB0,&lerpWeight0,&lerpA0);
  return (double)lerpA0;
}

/* _InterpreterNoiseGeneratorCalculate1D @ 0x97bd60c8 (240 bytes) */
int _InterpreterNoiseGeneratorCalculate1D(noise, point, result)
  undefined4 noise;
  float *point;
  float *result;
{
  uint loopIndex;
  double frequency;
  float noiseSum;
  double i2dBias;
  uint nextOctave;
  double octaveNoise;
  double amplitude;
  float samplePoint [5];
  uint i2dLo1;
  
  i2dBias = DOUBLE_97c30a68;
  loopIndex = 0;
  noiseSum = TAllocation__guardBlockSize;
  do {
    nextOctave = loopIndex + 1;
    samplePoint[4] = 176.0;
    frequency = _exp2((double)(float)((double)CONCAT44(0x43300000,loopIndex) - i2dBias));
    samplePoint[4] = 176.0;
    i2dLo1 = nextOctave;
    amplitude = _pow(DOUBLE_97c30a88,(double)CONCAT44(0x43300000,nextOctave) - i2dBias);
    samplePoint[0] = *point * (float)frequency;
    samplePoint[1] = 0.0;
    samplePoint[2] = 0.0;
    samplePoint[3] = 0.0;
    octaveNoise = (double)((double (*)())_InterpreterNoiseGeneratorInterpolatedNoise1D)(noise,samplePoint);
    noiseSum = (float)(octaveNoise * (double)(float)amplitude + (double)noiseSum);
    loopIndex = nextOctave;
  } while (nextOctave < 8);
  result[3] = noiseSum;
  *result = noiseSum;
  result[1] = noiseSum;
  result[2] = noiseSum;
  return;
}

/* _InterpreterNoiseGeneratorCalculate2D @ 0x97bd61b8 (248 bytes) */
int _InterpreterNoiseGeneratorCalculate2D(noise, point, result)
  undefined4 noise;
  float *point;
  float *result;
{
  uint loopIndex;
  double frequency;
  float noiseSum;
  double i2dBias;
  uint nextOctave;
  double octaveNoise;
  double amplitude;
  float samplePointX;
  float samplePointY;
  undefined4 samplePointZ;
  undefined4 samplePointW;
  undefined4 i2dHi1;
  uint i2dLo1;
  
  i2dBias = DOUBLE_97c30a68;
  loopIndex = 0;
  noiseSum = TAllocation__guardBlockSize;
  do {
    nextOctave = loopIndex + 1;
    i2dHi1 = 0x43300000;
    frequency = _exp2((double)(float)((double)CONCAT44(0x43300000,loopIndex) - i2dBias));
    i2dHi1 = 0x43300000;
    i2dLo1 = nextOctave;
    amplitude = _pow(DOUBLE_97c30a88,(double)CONCAT44(0x43300000,nextOctave) - i2dBias);
    samplePointX = *point * (float)frequency;
    samplePointY = point[1] * (float)frequency;
    samplePointZ = 0;
    samplePointW = 0;
    octaveNoise = (double)((double (*)())_InterpreterNoiseGeneratorInterpolatedNoise2D)(noise,&samplePointX);
    noiseSum = (float)(octaveNoise * (double)(float)amplitude + (double)noiseSum);
    loopIndex = nextOctave;
  } while (nextOctave < 8);
  result[3] = noiseSum;
  *result = noiseSum;
  result[1] = noiseSum;
  result[2] = noiseSum;
  return;
}

/* _InterpreterNoiseGeneratorCalculate3D @ 0x97bd62b0 (256 bytes) */
int _InterpreterNoiseGeneratorCalculate3D(noise, point, result)
  undefined4 noise;
  float *point;
  float *result;
{
  uint loopIndex;
  double amplitude;
  float noiseSum;
  float frequencyF;
  double i2dBias;
  uint nextOctave;
  double frequency;
  double octaveNoise;
  float samplePointX;
  float samplePointY;
  float samplePointZ;
  undefined4 samplePointW;
  undefined4 i2dHi1;
  uint i2dLo1;
  
  i2dBias = DOUBLE_97c30a68;
  loopIndex = 0;
  noiseSum = TAllocation__guardBlockSize;
  do {
    nextOctave = loopIndex + 1;
    i2dHi1 = 0x43300000;
    frequency = _exp2((double)(float)((double)CONCAT44(0x43300000,loopIndex) - i2dBias));
    i2dHi1 = 0x43300000;
    frequencyF = (float)frequency;
    i2dLo1 = nextOctave;
    amplitude = _pow(DOUBLE_97c30a88,(double)CONCAT44(0x43300000,nextOctave) - i2dBias);
    samplePointX = *point * frequencyF;
    samplePointY = point[1] * frequencyF;
    samplePointZ = point[2] * frequencyF;
    samplePointW = 0;
    octaveNoise = (double)((double (*)())_InterpreterNoiseGeneratorInterpolatedNoise3D)(noise,&samplePointX);
    noiseSum = (float)(octaveNoise * (double)(float)amplitude + (double)noiseSum);
    loopIndex = nextOctave;
  } while (nextOctave < 8);
  result[3] = noiseSum;
  *result = noiseSum;
  result[1] = noiseSum;
  result[2] = noiseSum;
  return;
}

/* _InterpreterRasterOpMachineCreate @ 0x97bd63b4 (60 bytes) */
int _InterpreterRasterOpMachineCreate()
{
  undefined4 allocation;
  
  allocation = _calloc(8,1);
  ((int (*)())_InterpreterRasterOpMachineInitialise)(allocation);
  return allocation;
}

/* _InterpreterRasterOpMachineInitialise @ 0x97bd63f0 (16 bytes) */
int _InterpreterRasterOpMachineInitialise(param_1)
  undefined4 *param_1;
{
  param_1[1] = 0;
  *param_1 = 0;
  return;
}

/* _InterpreterRasterOpMachineAttachEmulatorContext @ 0x97bd6404 (8 bytes) */
int _InterpreterRasterOpMachineAttachEmulatorContext(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  return;
}

/* _InterpreterRasterOpMachineAttachRuntimeCompiler @ 0x97bd640c (8 bytes) */
int _InterpreterRasterOpMachineAttachRuntimeCompiler(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}

/* _InterpreterRasterOpMachine_DepthTest @ 0x97bd6414 (236 bytes) */
int _InterpreterRasterOpMachine_DepthTest(machine)
  int *machine;
{
  float fragDepth;
  int emulator;
  float *depthBufferPtr;
  bool passed;
  
  emulator = *machine;
  fragDepth = *(float *)(*(int *)(emulator + 0xdf0) + 0xa38);
  depthBufferPtr = *(float **)(emulator + 0xda8);
  switch(*(uint *)(*(int *)(emulator + 0xd80) + 0x50) & 7) {
  case 0:
    return true;
  case 1:
    passed = fragDepth < *depthBufferPtr;
    break;
  case 2:
    return fragDepth != *depthBufferPtr;
  case 3:
    passed = fragDepth <= *depthBufferPtr;
    break;
  case 4:
    passed = *depthBufferPtr < fragDepth;
    break;
  case 5:
    return fragDepth == *depthBufferPtr;
  case 6:
    passed = *depthBufferPtr <= fragDepth;
    break;
  default:
    return false;
  }
  return (bool)(passed ^ 1);
}

/* _InterpreterRasterOpMachine_DepthAndStencilTest @ 0x97bd6520 (732 bytes) */
int _InterpreterRasterOpMachine_DepthAndStencilTest(machine)
  int *machine;
{
  bool writeMasksUnrestricted;
  bool depthLessOrEqual;
  float fragDepth;
  uint stencilRef;
  bool stencilEnabled;
  uint stencilFuncAndOps;
  int state;
  byte *stencilBufferPtr;
  uint stencilWriteMask;
  uint stencilCompareMask;
  uint writeMaskWord;
  uint stateFlags;
  int emulator;
  float *depthBufferPtr;
  uint testPassed;
  
  testPassed = 0;
  emulator = *machine;
  state = *(int *)(emulator + 0xd80);
  stencilFuncAndOps = *(uint *)(state + 0x48);
  stateFlags = *(uint *)(state + 0x3c);
  stencilRef = *(uint *)(state + 0x4c) >> 0x18;
  fragDepth = *(float *)(*(int *)(emulator + 0xdf0) + 0xa38);
  depthBufferPtr = *(float **)(emulator + 0xda8);
  stencilBufferPtr = *(byte **)(emulator + 0xdac);
  writeMasksUnrestricted = (stateFlags >> 6 & 1) == 0;
  stencilCompareMask = *(uint *)(state + 0x4c) >> 8 & 0xff;
  writeMaskWord = *(uint *)(*(int *)(emulator + 0xd80) + 0x70);
  if (writeMasksUnrestricted) {
    stencilWriteMask = 0xff;
  }
  else {
    stencilWriteMask = writeMaskWord >> 8 & 0xff;
  }
  stencilEnabled = (stateFlags & 2) != 0;
  if (stencilEnabled) {
    switch(stencilFuncAndOps >> 0xc & 7) {
    case 0:
      testPassed = 0;
      break;
    case 1:
      testPassed = (uint)((stencilRef & stencilCompareMask) < (stencilCompareMask & *stencilBufferPtr));
      break;
    case 2:
      testPassed = (uint)((stencilRef & stencilCompareMask) == (stencilCompareMask & *stencilBufferPtr));
      break;
    case 3:
      testPassed = (uint)((stencilRef & stencilCompareMask) <= (stencilCompareMask & *stencilBufferPtr));
      break;
    case 4:
      testPassed = (uint)((stencilCompareMask & *stencilBufferPtr) < (stencilRef & stencilCompareMask));
      break;
    case 5:
      testPassed = -(uint)((*stencilBufferPtr ^ stencilRef) & stencilCompareMask) >> 0x1f;
      break;
    case 6:
      testPassed = (uint)((stencilCompareMask & *stencilBufferPtr) <= (stencilRef & stencilCompareMask));
      break;
    case 7:
      testPassed = 1;
    }
    if (testPassed == 0) {
      ((int (*)())_InterpreterRasterOpMachineUpdateStencilBuffer)(stencilFuncAndOps >> 0xf & 7,stencilRef,stencilBufferPtr,stencilWriteMask);
      return true;
    }
  }
  if ((stateFlags & 4) == 0) {
    if (stencilEnabled) {
      ((int (*)())_InterpreterRasterOpMachineUpdateStencilBuffer)(stencilFuncAndOps >> 0x15 & 7,stencilRef,stencilBufferPtr,stencilWriteMask);
    }
    return testPassed == 0;
  }
  switch(*(uint *)(*(int *)(emulator + 0xd80) + 0x50) & 7) {
  case 0:
    testPassed = 0;
    break;
  case 1:
    testPassed = (uint)(fragDepth < *depthBufferPtr);
    break;
  case 2:
    testPassed = (uint)(fragDepth == *depthBufferPtr);
    break;
  case 3:
    depthLessOrEqual = fragDepth <= *depthBufferPtr;
    goto LAB_97bd67ac;
  case 4:
    testPassed = (uint)(*depthBufferPtr < fragDepth);
    break;
  case 5:
    testPassed = (uint)(fragDepth != *depthBufferPtr);
    break;
  case 6:
    depthLessOrEqual = *depthBufferPtr <= fragDepth;
LAB_97bd67ac:
    testPassed = (uint)depthLessOrEqual;
    break;
  case 7:
    testPassed = 1;
  }
  if (testPassed == 0) {
    if (stencilEnabled) {
      ((int (*)())_InterpreterRasterOpMachineUpdateStencilBuffer)(stencilFuncAndOps >> 0x12 & 7,stencilRef,stencilBufferPtr,stencilWriteMask);
    }
  }
  else {
    if (stencilEnabled) {
      ((int (*)())_InterpreterRasterOpMachineUpdateStencilBuffer)(stencilFuncAndOps >> 0x15 & 7,stencilRef,stencilBufferPtr,stencilWriteMask);
    }
    if ((writeMasksUnrestricted) || ((writeMaskWord & 0x10000) != 0)) {
      *depthBufferPtr = fragDepth;
    }
  }
  return testPassed == 0;
}

/* _InterpreterRasterOpMachine_AlphaTest @ 0x97bd683c (1548 bytes) */
int _InterpreterRasterOpMachine_AlphaTest(machine, fragment)
  int *machine;
  int fragment;
{
  uint alphaRefFixed;
  uint framebufferFormat;
  float alphaRef;
  int state;
  uint fragAlphaFixed;
  float fragAlpha;
  uint alphaFunc;
  bool passed;
  double fixedScratch;
  
  state = *(int *)(*machine + 0xd80);
  alphaRef = *(float *)(state + 0x44);
  alphaFunc = *(uint *)(state + 0x40);
  framebufferFormat = _PPEmulatorFramebufferFormat(*machine);
  passed = false;
  if ((framebufferFormat & 0x1c000) == 0) {
    switch(alphaFunc & 7) {
    case 0:
switchD_97bd6924_caseD_0:
      passed = false;
      break;
    case 1:
      passed = *(float *)(fragment + 0xc) < alphaRef;
      break;
    case 2:
      passed = *(float *)(fragment + 0xc) == alphaRef;
      break;
    case 3:
      passed = *(float *)(fragment + 0xc) <= alphaRef;
      break;
    case 4:
      passed = alphaRef < *(float *)(fragment + 0xc);
      break;
    case 5:
      passed = *(float *)(fragment + 0xc) != alphaRef;
      break;
    case 6:
      passed = alphaRef <= *(float *)(fragment + 0xc);
      break;
    case 7:
switchD_97bd6924_caseD_7:
      passed = true;
    }
  }
  else {
    fragAlpha = *(float *)(fragment + 0xc);
    if (TAllocation__guardBlockSize <= fragAlpha) {
      if (FLOAT_97c3acd8 < fragAlpha) {
        fragAlpha = 1.0;
      }
    }
    else {
      fragAlpha = 0.0;
    }
    if (TAllocation__guardBlockSize <= alphaRef) {
      if (FLOAT_97c3acd8 < alphaRef) {
        alphaRef = 1.0;
      }
    }
    else {
      alphaRef = 0.0;
    }
    switch(alphaFunc & 7) {
    case 0:
      goto switchD_97bd6924_caseD_0;
    case 1:
      fragAlpha = fragAlpha * FLOAT_97c3acbc + FLOAT_97c3acc0;
      fixedScratch = (double)fragAlpha;
      if (DOUBLE_97c30a78 <= fixedScratch) {
        fragAlphaFixed = (int)(fixedScratch - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        fragAlphaFixed = (uint)(int)fragAlpha;
      }
      alphaRef = alphaRef * FLOAT_97c3acbc + FLOAT_97c3acc0;
      fixedScratch = (double)alphaRef;
      if (DOUBLE_97c30a78 <= fixedScratch) {
        alphaRefFixed = (int)(fixedScratch - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        alphaRefFixed = (uint)(int)alphaRef;
      }
      passed = fragAlphaFixed < alphaRefFixed;
      break;
    case 2:
      fragAlpha = fragAlpha * FLOAT_97c3acbc + FLOAT_97c3acc0;
      fixedScratch = (double)fragAlpha;
      if (DOUBLE_97c30a78 <= fixedScratch) {
        fragAlphaFixed = (int)(fixedScratch - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        fragAlphaFixed = (uint)(int)fragAlpha;
      }
      alphaRef = alphaRef * FLOAT_97c3acbc + FLOAT_97c3acc0;
      fixedScratch = (double)alphaRef;
      if (DOUBLE_97c30a78 <= fixedScratch) {
        alphaRefFixed = (int)(fixedScratch - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        alphaRefFixed = (uint)(int)alphaRef;
      }
      passed = fragAlphaFixed == alphaRefFixed;
      break;
    case 3:
      fragAlpha = fragAlpha * FLOAT_97c3acbc + FLOAT_97c3acc0;
      fixedScratch = (double)fragAlpha;
      if (DOUBLE_97c30a78 <= fixedScratch) {
        fragAlphaFixed = (int)(fixedScratch - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        fragAlphaFixed = (uint)(int)fragAlpha;
      }
      alphaRef = alphaRef * FLOAT_97c3acbc + FLOAT_97c3acc0;
      fixedScratch = (double)alphaRef;
      if (DOUBLE_97c30a78 <= fixedScratch) {
        alphaRefFixed = (int)(fixedScratch - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        alphaRefFixed = (uint)(int)alphaRef;
      }
      passed = fragAlphaFixed <= alphaRefFixed;
      break;
    case 4:
      fragAlpha = fragAlpha * FLOAT_97c3acbc + FLOAT_97c3acc0;
      fixedScratch = (double)fragAlpha;
      if (DOUBLE_97c30a78 <= fixedScratch) {
        fragAlphaFixed = (int)(fixedScratch - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        fragAlphaFixed = (uint)(int)fragAlpha;
      }
      alphaRef = alphaRef * FLOAT_97c3acbc + FLOAT_97c3acc0;
      fixedScratch = (double)alphaRef;
      if (DOUBLE_97c30a78 <= fixedScratch) {
        alphaRefFixed = (int)(fixedScratch - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        alphaRefFixed = (uint)(int)alphaRef;
      }
      passed = alphaRefFixed < fragAlphaFixed;
      break;
    case 5:
      fragAlpha = fragAlpha * FLOAT_97c3acbc + FLOAT_97c3acc0;
      fixedScratch = (double)fragAlpha;
      if (DOUBLE_97c30a78 <= fixedScratch) {
        fragAlphaFixed = (int)(fixedScratch - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        fragAlphaFixed = (uint)(int)fragAlpha;
      }
      alphaRef = alphaRef * FLOAT_97c3acbc + FLOAT_97c3acc0;
      fixedScratch = (double)alphaRef;
      if (DOUBLE_97c30a78 <= fixedScratch) {
        alphaRefFixed = (int)(fixedScratch - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        alphaRefFixed = (uint)(int)alphaRef;
      }
      passed = fragAlphaFixed != alphaRefFixed;
      break;
    case 6:
      fragAlpha = fragAlpha * FLOAT_97c3acbc + FLOAT_97c3acc0;
      fixedScratch = (double)fragAlpha;
      if (DOUBLE_97c30a78 <= fixedScratch) {
        fragAlphaFixed = (int)(fixedScratch - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        fragAlphaFixed = (uint)(int)fragAlpha;
      }
      alphaRef = alphaRef * FLOAT_97c3acbc + FLOAT_97c3acc0;
      fixedScratch = (double)alphaRef;
      if (DOUBLE_97c30a78 <= fixedScratch) {
        alphaRefFixed = (int)(fixedScratch - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        alphaRefFixed = (uint)(int)alphaRef;
      }
      passed = alphaRefFixed <= fragAlphaFixed;
      break;
    case 7:
      goto switchD_97bd6924_caseD_7;
    }
  }
  return passed ^ 1;
}

/* _InterpreterRasterOpMachine_Blending @ 0x97bd6e88 (1252 bytes) */
int _InterpreterRasterOpMachine_Blending(machine, srcColor, dstColor, result)
  int *machine;
  float *srcColor;
  float *dstColor;
  float *result;
{
  float srcComponent3;
  float srcComponent2;
  float srcComponent;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int emulator;
  uint framebufferFormat;
  uint blendState;
  int blendConstant;
  float srcFactorR;
  float srcFactorG;
  float srcFactorB;
  float srcFactorA;
  float dstFactorR;
  float dstFactorG;
  float dstFactorB;
  float dstFactorA;
  undefined1 auStack_40 [12];
  float factorAlphaScratch;
  float local_30;
  
  emulator = *machine;
  blendState = *(uint *)(*(int *)(emulator + 0xd80) + 0x58);
  blendConstant = *(int *)(*(int *)(emulator + 0xd9c) + 0xd8) + 0x2d70;
  framebufferFormat = _PPEmulatorFramebufferFormat(emulator);
  fVar2 = FLOAT_97c3acd8;
  if ((framebufferFormat & 0x8000000) == 0) {
    srcComponent2 = *srcColor;
    fVar4 = srcComponent2;
    if (FLOAT_97c3acd8 <= srcComponent2) {
      srcComponent2 = 1.0;
      fVar4 = local_30;
    }
    local_30 = fVar4;
    srcComponent3 = srcColor[1];
    *srcColor = srcComponent2;
    fVar3 = FLOAT_97c3acd8;
    fVar1 = srcComponent3;
    if (fVar2 <= srcComponent3) {
      srcComponent3 = 1.0;
      fVar1 = local_30;
    }
    local_30 = fVar1;
    srcComponent = srcColor[2];
    srcColor[1] = srcComponent3;
    fVar4 = FLOAT_97c3acd8;
    fVar1 = srcComponent;
    if (fVar3 <= srcComponent) {
      srcComponent = 1.0;
      fVar1 = local_30;
    }
    local_30 = fVar1;
    srcComponent2 = srcColor[3];
    srcColor[2] = srcComponent;
    fVar2 = TAllocation__guardBlockSize;
    fVar1 = srcComponent2;
    if (fVar4 <= srcComponent2) {
      srcComponent2 = 1.0;
      fVar1 = local_30;
    }
    local_30 = fVar1;
    srcComponent3 = *srcColor;
    srcColor[3] = srcComponent2;
    fVar3 = TAllocation__guardBlockSize;
    fVar1 = srcComponent3;
    if (srcComponent3 <= fVar2) {
      srcComponent3 = 0.0;
      fVar1 = local_30;
    }
    local_30 = fVar1;
    srcComponent = srcColor[1];
    *srcColor = srcComponent3;
    fVar4 = TAllocation__guardBlockSize;
    fVar1 = srcComponent;
    if (srcComponent <= fVar3) {
      srcComponent = 0.0;
      fVar1 = local_30;
    }
    local_30 = fVar1;
    srcComponent2 = srcColor[2];
    srcColor[1] = srcComponent;
    fVar2 = TAllocation__guardBlockSize;
    fVar1 = srcComponent2;
    if (srcComponent2 <= fVar4) {
      srcComponent2 = 0.0;
      fVar1 = local_30;
    }
    local_30 = fVar1;
    srcComponent3 = srcColor[3];
    srcColor[2] = srcComponent2;
    fVar3 = srcComponent3;
    if (srcComponent3 <= fVar2) {
      srcComponent3 = 0.0;
      fVar3 = local_30;
    }
    local_30 = fVar3;
    srcColor[3] = srcComponent3;
  }
  if ((1 < (blendState >> 0x10 & 7) - 3) || (1 < (blendState >> 0x13 & 7) - 3)) {
    ((int (*)())_InterpreterRasterOpMachineCalculateBlendingFactors)(blendState & 0xf,srcColor,dstColor,blendConstant,&srcFactorR)
    ;
    ((int (*)())_InterpreterRasterOpMachineCalculateBlendingFactors)(blendState >> 8 & 0xf,srcColor,dstColor,blendConstant,&dstFactorR);
    if ((blendState & 0xf) != (blendState >> 4 & 0xf)) {
      ((int (*)())_InterpreterRasterOpMachineCalculateBlendingFactors)(blendState >> 4 & 0xf,srcColor,dstColor,blendConstant,auStack_40);
      srcFactorA = factorAlphaScratch;
    }
    if ((blendState >> 8 & 0xf) != (blendState >> 0xc & 0xf)) {
      ((int (*)())_InterpreterRasterOpMachineCalculateBlendingFactors)(blendState >> 0xc & 0xf,srcColor,dstColor,blendConstant,auStack_40);
      dstFactorA = factorAlphaScratch;
    }
  }
  switch(blendState >> 0x10 & 7) {
  case 0:
    *result = *srcColor * srcFactorR + *dstColor * dstFactorR;
    result[1] = srcColor[1] * srcFactorG + dstColor[1] * dstFactorG;
    srcComponent = srcColor[2] * srcFactorB + dstColor[2] * dstFactorB;
    goto LAB_97bd7230;
  case 1:
    *result = *srcColor * srcFactorR - *dstColor * dstFactorR;
    result[1] = srcColor[1] * srcFactorG - dstColor[1] * dstFactorG;
    srcComponent = dstColor[2];
    srcComponent2 = srcColor[2];
    fVar4 = dstFactorB;
    dstFactorB = srcFactorB;
    break;
  case 2:
    *result = *dstColor * dstFactorR - *srcColor * srcFactorR;
    result[1] = dstColor[1] * dstFactorG - srcColor[1] * srcFactorG;
    srcComponent = srcColor[2];
    srcComponent2 = dstColor[2];
    fVar4 = srcFactorB;
    break;
  case 3:
    srcComponent = *dstColor;
    if (*srcColor < *dstColor) {
      srcComponent = *srcColor;
    }
    *result = srcComponent;
    srcComponent = dstColor[1];
    if (srcColor[1] < dstColor[1]) {
      srcComponent = srcColor[1];
    }
    result[1] = srcComponent;
    srcComponent2 = srcColor[2];
    fVar2 = dstColor[2];
    if (srcComponent2 < fVar2) {
LAB_97bd72bc:
      fVar2 = srcComponent2;
    }
    goto LAB_97bd72c0;
  case 4:
    srcComponent = *dstColor;
    if (*dstColor < *srcColor) {
      srcComponent = *srcColor;
    }
    *result = srcComponent;
    srcComponent = dstColor[1];
    if (dstColor[1] < srcColor[1]) {
      srcComponent = srcColor[1];
    }
    result[1] = srcComponent;
    srcComponent2 = srcColor[2];
    fVar2 = dstColor[2];
    if (dstColor[2] < srcComponent2) goto LAB_97bd72bc;
LAB_97bd72c0:
    result[2] = fVar2;
  default:
    goto switchD_97bd7128_default;
  }
  srcComponent = srcComponent2 * dstFactorB - srcComponent * fVar4;
LAB_97bd7230:
  result[2] = srcComponent;
switchD_97bd7128_default:
  switch(blendState >> 0x13 & 7) {
  case 0:
    fVar3 = srcColor[3] * srcFactorA + dstColor[3] * dstFactorA;
    goto LAB_97bd734c;
  case 1:
    srcComponent = srcColor[3];
    fVar3 = dstColor[3] * dstFactorA;
    dstFactorA = srcFactorA;
    break;
  case 2:
    srcComponent = dstColor[3];
    fVar3 = srcColor[3] * srcFactorA;
    break;
  case 3:
    srcComponent2 = srcColor[3];
    fVar2 = dstColor[3];
    if (srcComponent2 < fVar2) {
LAB_97bd7378:
      fVar2 = srcComponent2;
    }
    goto LAB_97bd737c;
  case 4:
    srcComponent2 = srcColor[3];
    fVar2 = dstColor[3];
    if (dstColor[3] < srcComponent2) goto LAB_97bd7378;
LAB_97bd737c:
    result[3] = fVar2;
  default:
    goto switchD_97bd72e8_default;
  }
  fVar3 = srcComponent * dstFactorA - fVar3;
LAB_97bd734c:
  result[3] = fVar3;
switchD_97bd72e8_default:
  return;
}

/* _InterpreterRasterOpMachine_LogicOp @ 0x97bd7394 (1208 bytes) */
int _InterpreterRasterOpMachine_LogicOp(machine, srcColor, dstColor, outColor)
  int *machine;
  float *srcColor;
  float *dstColor;
  float *outColor;
{
  float unpackedA;
  float unpackedB;
  float unpackedG;
  float colorR;
  float copiedAlpha;
  uint resultPacked;
  uint resultShiftedLane;
  uint resultWord;
  uint resultAlphaLane;
  float colorG;
  float colorB;
  float colorA;
  float fillValue;
  uint dstRedByte;
  uint logicOp;
  uint packedSrcRG;
  uint packedSrcRGB;
  uint packedSrc;
  uint srcRedByte;
  uint packedDstRG;
  uint packedDstRGB;
  uint packedDst;
  
  logicOp = *(uint *)(*(int *)(*machine + 0xd80) + 0x68) & 0xf;
  if ((logicOp < 3) || (logicOp == 4)) {
    if (logicOp == 1) {
      fillValue = 1.0;
    }
    else {
      if (1 < logicOp) {
        if (logicOp == 2) {
          *outColor = *srcColor;
          outColor[1] = srcColor[1];
          outColor[2] = srcColor[2];
          copiedAlpha = srcColor[3];
        }
        else {
          if (logicOp != 4) {
            return;
          }
          *outColor = *dstColor;
          outColor[1] = dstColor[1];
          outColor[2] = dstColor[2];
          copiedAlpha = dstColor[3];
        }
        outColor[3] = copiedAlpha;
        return;
      }
      fillValue = 0.0;
      if (logicOp != 0) {
        return;
      }
    }
    outColor[3] = fillValue;
    *outColor = fillValue;
    outColor[1] = fillValue;
    outColor[2] = fillValue;
    return;
  }
  if (logicOp == 5) {
    colorR = *dstColor;
    colorG = dstColor[1];
    colorB = dstColor[2];
    colorA = dstColor[3];
LAB_97bd74b4:
    resultPacked = ~(int)((double)colorA * DOUBLE_97c30a98) & 0xffU |
            (~(int)((double)colorB * DOUBLE_97c30a98) & 0xffU) << 8 |
            (~(int)((double)colorG * DOUBLE_97c30a98) & 0xffU) << 0x10 |
            ~(int)((double)colorR * DOUBLE_97c30a98) << 0x18;
    goto LAB_97bd77d8;
  }
  if (logicOp == 3) {
    colorR = *srcColor;
    colorG = srcColor[1];
    colorB = srcColor[2];
    colorA = srcColor[3];
    goto LAB_97bd74b4;
  }
  srcRedByte = (uint)(int)((double)*srcColor * DOUBLE_97c30a98);
  dstRedByte = (uint)(int)((double)*dstColor * DOUBLE_97c30a98);
  packedSrcRG = ((int)((double)srcColor[1] * DOUBLE_97c30a98) & 0xffU) << 0x10 | srcRedByte << 0x18;
  packedSrcRGB = ((int)((double)srcColor[2] * DOUBLE_97c30a98) & 0xffU) << 8 | packedSrcRG;
  packedDstRG = ((int)((double)dstColor[1] * DOUBLE_97c30a98) & 0xffU) << 0x10 | dstRedByte << 0x18;
  packedSrc = (int)((double)srcColor[3] * DOUBLE_97c30a98) & 0xffU | packedSrcRGB;
  packedDstRGB = ((int)((double)dstColor[2] * DOUBLE_97c30a98) & 0xffU) << 8 | packedDstRG;
  packedDst = (int)((double)dstColor[3] * DOUBLE_97c30a98) & 0xffU | packedDstRGB;
  switch(logicOp) {
  case 6:
    resultWord = packedDst & packedSrc;
    resultAlphaLane = packedSrc & packedDst;
    resultPacked = resultWord >> 8;
    resultShiftedLane = resultWord >> 0x10;
    goto LAB_97bd7670;
  case 7:
    resultPacked = packedDst & packedSrc;
    resultAlphaLane = ~(packedSrc & packedDst);
    resultWord = resultPacked ^ 0xff000000;
    resultShiftedLane = ~(resultPacked >> 0x10);
    resultPacked = ~(resultPacked >> 8);
LAB_97bd7670:
    resultPacked = (resultPacked & 0xff) << 8 | (resultShiftedLane & 0xff) << 0x10 | resultWord & 0xff000000;
    goto LAB_97bd770c;
  case 8:
    resultShiftedLane = packedDst | packedSrc;
    resultAlphaLane = packedSrc | packedDst;
    resultWord = packedDst | packedSrc;
    goto LAB_97bd76cc;
  case 9:
    resultAlphaLane = ~(packedSrc | packedDst);
    resultWord = (packedDst | packedSrc) ^ 0xff000000;
    resultPacked = ~((packedDst | packedSrc) >> 0x10);
    resultShiftedLane = ~((packedDst | packedSrc) >> 8);
    goto LAB_97bd7700;
  case 10:
    resultShiftedLane = packedDst ^ packedSrc;
    resultAlphaLane = packedSrc ^ packedDst;
    resultWord = packedDst ^ packedSrc;
LAB_97bd76cc:
    resultPacked = resultShiftedLane >> 0x10;
    resultShiftedLane = resultShiftedLane >> 8;
    goto LAB_97bd7700;
  case 0xb:
    resultWord = packedDst ^ packedSrc ^ 0xff000000;
    resultPacked = ~((packedDst ^ packedSrc) >> 0x10);
    resultShiftedLane = ~((packedDst ^ packedSrc) >> 8);
    resultAlphaLane = ~(packedSrc ^ packedDst);
LAB_97bd7700:
    resultPacked = (resultShiftedLane & 0xff) << 8 | (resultPacked & 0xff) << 0x10 | resultWord & 0xff000000;
LAB_97bd770c:
    resultPacked = resultAlphaLane & 0xff | resultPacked;
    goto LAB_97bd77d8;
  case 0xc:
    packedSrcRG = packedSrcRG >> 0x10 & ~(packedDstRG >> 0x10);
    srcRedByte = srcRedByte & 0xff & ~(dstRedByte & 0xff);
    resultPacked = packedSrcRGB >> 8 & ~(packedDstRGB >> 8);
    packedDst = packedSrc & ~packedDst;
    break;
  case 0xd:
    packedSrcRG = packedDstRG >> 0x10 & ~(packedSrcRG >> 0x10);
    srcRedByte = dstRedByte & 0xff & ~(srcRedByte & 0xff);
    resultPacked = packedDstRGB >> 8 & ~(packedSrcRGB >> 8);
    packedDst = packedDst & ~packedSrc;
    break;
  case 0xe:
    packedSrcRG = packedSrcRG >> 0x10 | ~(packedDstRG >> 0x10);
    srcRedByte = srcRedByte & 0xff | ~(dstRedByte & 0xff);
    resultPacked = packedSrcRGB >> 8 | ~(packedDstRGB >> 8);
    packedDst = packedSrc | ~packedDst;
    break;
  case 0xf:
    packedSrcRG = packedDstRG >> 0x10 | ~(packedSrcRG >> 0x10);
    srcRedByte = dstRedByte & 0xff | ~(srcRedByte & 0xff);
    resultPacked = packedDstRGB >> 8 | ~(packedSrcRGB >> 8);
    packedDst = packedDst | ~packedSrc;
    break;
  default:
    resultPacked = 0;
    goto LAB_97bd77d8;
  }
  resultPacked = packedDst & 0xff | (resultPacked & 0xff) << 8 | (packedSrcRG & 0xff) << 0x10 | srcRedByte << 0x18;
LAB_97bd77d8:
  unpackedA = (GH_U2F((unsigned int)((resultPacked & 0xff | 0x4b000000))) - 8388608.0) * FLOAT_97c3acc8;
  unpackedG = (GH_U2F((unsigned int)((resultPacked >> 0x10 & 0xff | 0x4b000000))) - 8388608.0) * FLOAT_97c3acc8;
  unpackedB = (GH_U2F((unsigned int)((resultPacked >> 8 & 0xff | 0x4b000000))) - 8388608.0) * FLOAT_97c3acc8;
  *outColor = (GH_U2F((unsigned int)((resultPacked >> 0x18 | 0x4b000000))) - 8388608.0) * FLOAT_97c3acc8;
  outColor[3] = unpackedA;
  outColor[1] = unpackedG;
  outColor[2] = unpackedB;
  return;
}

/* _InterpreterRasterOpMachine_BufferMask @ 0x97bd7874 (128 bytes) */
int _InterpreterRasterOpMachine_BufferMask(machine, newColor, oldColor, outColor)
  int *machine;
  undefined4 *newColor;
  undefined4 *oldColor;
  undefined4 *outColor;
{
  undefined4 selectedChannel;
  uint writeMaskWord;
  
  writeMaskWord = *(uint *)(*(int *)(*machine + 0xd80) + 0x70);
  if ((writeMaskWord & 0x20000) == 0) {
    selectedChannel = *oldColor;
  }
  else {
    selectedChannel = *newColor;
  }
  *outColor = selectedChannel;
  if ((writeMaskWord & 0x40000) == 0) {
    selectedChannel = oldColor[1];
  }
  else {
    selectedChannel = newColor[1];
  }
  outColor[1] = selectedChannel;
  if ((writeMaskWord & 0x80000) == 0) {
    selectedChannel = oldColor[2];
  }
  else {
    selectedChannel = newColor[2];
  }
  outColor[2] = selectedChannel;
  if ((writeMaskWord & 0x100000) == 0) {
    selectedChannel = oldColor[3];
  }
  else {
    selectedChannel = newColor[3];
  }
  outColor[3] = selectedChannel;
  return;
}

/* _InterpreterRasterOpMachineCalculateBlendingFactors @ 0x97bd78f4 (664 bytes) */
int _InterpreterRasterOpMachineCalculateBlendingFactors(factorMode, srcColor, dstColor, constantColor, factorOut)
  undefined4 factorMode;
  float *srcColor;
  float *dstColor;
  float *constantColor;
  float *factorOut;
{
  double oneConst;
  float factorValue;
  double alphaForComplement;
  
  oneConst = DOUBLE_97c30a60;
  switch(factorMode) {
  case 0:
    factorValue = 0.0;
    goto LAB_97bd7970;
  case 1:
    factorValue = 1.0;
LAB_97bd7970:
    factorOut[3] = factorValue;
    *factorOut = factorValue;
    factorOut[1] = factorValue;
    factorOut[2] = factorValue;
    return;
  case 2:
    *factorOut = *srcColor;
    factorOut[1] = srcColor[1];
    factorValue = srcColor[2];
    break;
  case 3:
    *factorOut = (float)(DOUBLE_97c30a60 - (double)*srcColor);
    factorOut[1] = (float)(oneConst - (double)srcColor[1]);
    factorValue = srcColor[2];
    goto LAB_97bd7a1c;
  case 4:
    *factorOut = srcColor[3];
    factorOut[1] = srcColor[3];
    factorValue = srcColor[3];
    break;
  case 5:
    *factorOut = (float)(DOUBLE_97c30a60 - (double)srcColor[3]);
    factorOut[1] = (float)(oneConst - (double)srcColor[3]);
    factorValue = srcColor[3];
LAB_97bd7a1c:
    factorOut[2] = (float)(oneConst - (double)factorValue);
    alphaForComplement = (double)srcColor[3];
LAB_97bd7a2c:
    factorOut[3] = (float)(oneConst - alphaForComplement);
    return;
  case 6:
    *factorOut = dstColor[3];
    factorOut[1] = dstColor[3];
    factorValue = dstColor[3];
    goto LAB_97bd7b40;
  case 7:
    *factorOut = (float)(DOUBLE_97c30a60 - (double)dstColor[3]);
    factorOut[1] = (float)(oneConst - (double)dstColor[3]);
    factorValue = dstColor[3];
    goto LAB_97bd7b78;
  case 8:
    *factorOut = *constantColor;
    factorOut[1] = constantColor[1];
    factorValue = constantColor[2];
    goto LAB_97bd7ae0;
  case 9:
    *factorOut = (float)(DOUBLE_97c30a60 - (double)*constantColor);
    factorOut[1] = (float)(oneConst - (double)constantColor[1]);
    factorValue = constantColor[2];
    goto LAB_97bd7b18;
  case 10:
    *factorOut = constantColor[3];
    factorOut[1] = constantColor[3];
    factorValue = constantColor[3];
LAB_97bd7ae0:
    factorOut[2] = factorValue;
    factorValue = constantColor[3];
    goto LAB_97bd79e8;
  case 0xb:
    *factorOut = (float)(DOUBLE_97c30a60 - (double)constantColor[3]);
    factorOut[1] = (float)(oneConst - (double)constantColor[3]);
    factorValue = constantColor[3];
LAB_97bd7b18:
    factorOut[2] = (float)(oneConst - (double)factorValue);
    alphaForComplement = (double)constantColor[3];
    goto LAB_97bd7a2c;
  case 0xc:
    *factorOut = *dstColor;
    factorOut[1] = dstColor[1];
    factorValue = dstColor[2];
LAB_97bd7b40:
    factorOut[2] = factorValue;
    factorValue = dstColor[3];
    goto LAB_97bd79e8;
  case 0xd:
    *factorOut = (float)(DOUBLE_97c30a60 - (double)*dstColor);
    factorOut[1] = (float)(oneConst - (double)dstColor[1]);
    factorValue = dstColor[2];
LAB_97bd7b78:
    factorOut[2] = (float)(oneConst - (double)factorValue);
    alphaForComplement = (double)dstColor[3];
    goto LAB_97bd7a2c;
  case 0xe:
    factorValue = (float)(DOUBLE_97c30a60 - (double)dstColor[3]);
    if (srcColor[3] < (float)(DOUBLE_97c30a60 - (double)dstColor[3])) {
      factorValue = srcColor[3];
    }
    factorOut[2] = factorValue;
    factorOut[3] = 1.0;
    *factorOut = factorValue;
    factorOut[1] = factorValue;
    return;
  default:
    return;
  }
  factorOut[2] = factorValue;
  factorValue = srcColor[3];
LAB_97bd79e8:
  factorOut[3] = factorValue;
  return;
}

/* _InterpreterRasterOpMachineUpdateStencilBuffer @ 0x97bd7bc8 (212 bytes) */
int _InterpreterRasterOpMachineUpdateStencilBuffer(stencilOp, referenceValue, stencilPtr, writeMask)
  undefined4 stencilOp;
  undefined4 referenceValue;
  byte *stencilPtr;
  undefined4 writeMask;
{
  byte wrappedValue;
  byte newValue;
  
  switch(stencilOp) {
  case 0:
    newValue = *stencilPtr & ~(byte)writeMask;
    goto LAB_97bd7c38;
  case 1:
    return;
  case 2:
    newValue = *stencilPtr & ~(byte)writeMask;
    goto LAB_97bd7c34;
  case 3:
    newValue = *stencilPtr;
    (*(unsigned char *)((unsigned char *)&(referenceValue) + 3)) = 0xff;
    if (newValue != 0xff) {
      (*(unsigned char *)((unsigned char *)&(referenceValue) + 3)) = newValue + 1;
    }
    break;
  case 4:
    newValue = *stencilPtr;
    (*(unsigned char *)((unsigned char *)&(referenceValue) + 3)) = 0;
    if (newValue != 0) {
      (*(unsigned char *)((unsigned char *)&(referenceValue) + 3)) = newValue - 1;
    }
    break;
  case 5:
    *stencilPtr = *stencilPtr & ~(byte)writeMask | (byte)writeMask & ~*stencilPtr;
    return;
  case 6:
    newValue = *stencilPtr;
    wrappedValue = newValue + 1;
    goto LAB_97bd7c90;
  case 7:
    newValue = *stencilPtr;
    wrappedValue = newValue - 1;
LAB_97bd7c90:
    *stencilPtr = newValue & ~(byte)writeMask | wrappedValue & (byte)writeMask;
    return;
  default:
    return;
  }
  newValue = newValue & ~(byte)writeMask;
LAB_97bd7c34:
  newValue = newValue | (byte)referenceValue & (byte)writeMask;
LAB_97bd7c38:
  *stencilPtr = newValue;
  return;
}

/* _glpRTCAddAChunk_97bd7cbc @ 0x97bd7cbc (48 bytes) */
int _glpRTCAddAChunk_97bd7cbc(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = *param_1;
  while (iVar1 != 0) {
    *param_2 = iVar1;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    iVar1 = *param_1;
  }
  return iVar2;
}

/* _PPCRuntimeCompilerCreate @ 0x97bd7cec (88 bytes) */
int _PPCRuntimeCompilerCreate()
{
  int allocation;
  undefined4 uVar2;
  
  allocation = _calloc(0xe54,1);
  uVar2 = _PPCTextureSamplerCreate();
  *(undefined4 *)(allocation + 0xe1c) = uVar2;
  _PPCRasterOpMachineInitialise(allocation + 0xe14);
  _PPCRasterOpMachineAttachRuntimeCompiler(allocation + 0xe14,allocation);
  return allocation;
}

/* _PPCRuntimeCompilerInitialise @ 0x97bd7d44 (76 bytes) */
int _PPCRuntimeCompilerInitialise(compiler, param_2)
  int compiler;
  undefined4 param_2;
{
  *(undefined4 *)(compiler + 0xe0c) = 0xffffffff;
  *(undefined4 *)(compiler + 0xe08) = 0xffffffff;
  *(undefined4 *)(compiler + 0xe4c) = param_2;
  _PPCTextureSamplerInitialise(*(undefined4 *)(compiler + 0xe1c));
  ((int (*)())_PPCRuntimeCompilerInitialiseRegisterAllocator)(compiler);
  return ((int (*)())_PPCRuntimeCompilerInitialiseVariableInfo)(compiler);
}

/* _PPCRuntimeCompilerInitialiseRegisterAllocator @ 0x97bd7d90 (156 bytes) */
int _PPCRuntimeCompilerInitialiseRegisterAllocator(compiler)
  int compiler;
{
  uint loopIndex;
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  
  *(undefined4 *)(compiler + 0xe44) = 0;
  loopIndex = 0;
  do {
    uVar3 = loopIndex + 1;
    ((int (*)())_PPCRuntimeCompilerDirtyRegister)(compiler,loopIndex);
    loopIndex = uVar3;
  } while (uVar3 < 0x20);
  uVar1 = *(uint *)(compiler + 0xe50);
  if ((uVar1 & 1) != 0) {
    iVar4 = 0xc;
    puVar2 = (undefined4 *)(compiler + 0x48c);
    do {
      *puVar2 = 1;
      puVar2 = puVar2 + 0xe;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    uVar1 = *(uint *)(compiler + 0xe50);
  }
  if ((uVar1 & 2) != 0) {
    puVar2 = (undefined4 *)(compiler + 0xbc4);
    iVar4 = 0xb;
    do {
      *puVar2 = 1;
      puVar2 = puVar2 + 0xe;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}

/* _PPCRuntimeCompilerInitialiseVariableInfo @ 0x97bd7e2c (224 bytes) */
int _PPCRuntimeCompilerInitialiseVariableInfo(compiler)
  int compiler;
{
  int remaining;
  int allocation2;
  undefined4 allocation;
  uint loopIndex2;
  int *piVar4;
  uint loopIndex;
  int iVar6;
  int loopIndex3;
  int iVar8;
  
  if (*(int *)(compiler + 0xe00) != 0) {
    _free(*(int *)(compiler + 0xe00));
    *(undefined4 *)(compiler + 0xe04) = 0;
    *(undefined4 *)(compiler + 0xe00) = 0;
  }
  iVar6 = *(int *)(compiler + 0xe24);
  if (iVar6 != 0) {
    loopIndex3 = 0;
    remaining = 4;
    *(undefined4 *)(compiler + 0xe04) = 0;
    piVar4 = (int *)(iVar6 + 0x84);
    do {
      allocation2 = *piVar4;
      piVar4 = piVar4 + 3;
      allocation2 = *(int *)(compiler + 0xe04) + allocation2;
      *(int *)(compiler + 0xe04) = allocation2;
      remaining = remaining + -1;
    } while (remaining != 0);
    allocation = _calloc(allocation2,8);
    *(undefined4 *)(compiler + 0xe00) = allocation;
    loopIndex2 = 0;
    do {
      loopIndex = 0;
      if (*(int *)(iVar6 + 0x84) != 0) {
        do {
          iVar8 = loopIndex * 0x10;
          loopIndex = loopIndex + 1;
          *(int *)(loopIndex3 * 8 + *(int *)(compiler + 0xe00)) = *(int *)(iVar6 + 0x80) + iVar8;
          loopIndex3 = loopIndex3 + 1;
        } while (loopIndex < *(uint *)(iVar6 + 0x84));
      }
      loopIndex2 = loopIndex2 + 1;
      iVar6 = iVar6 + 0xc;
    } while (loopIndex2 < 4);
  }
  return;
}

/* _PPCRuntimeCompilerFree @ 0x97bd7f0c (80 bytes) */
int _PPCRuntimeCompilerFree(compiler)
  int compiler;
{
  if (*(int *)(compiler + 0xe00) != 0) {
    _free(*(int *)(compiler + 0xe00));
    *(undefined4 *)(compiler + 0xe04) = 0;
    *(undefined4 *)(compiler + 0xe00) = 0;
  }
  _PPCTextureSamplerFree(*(undefined4 *)(compiler + 0xe1c));
  return _free(compiler);
}

/* _PPCRuntimeCompilerOutputAllRegisters @ 0x97bd7f5c (4 bytes) */
int _PPCRuntimeCompilerOutputAllRegisters()
{
  return;
}

/* _PPCRuntimeCompilerAttachEmulatorContext @ 0x97bd7f60 (12 bytes) */
int _PPCRuntimeCompilerAttachEmulatorContext(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0xe20) = param_2;
  return _PPCRasterOpMachineAttachEmulatorContext(param_1 + 0xe14,param_2);
}

/* _PPCRuntimeCompilerAttachEmulatorProgram @ 0x97bd7f6c (8 bytes) */
int _PPCRuntimeCompilerAttachEmulatorProgram(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0xe24) = param_2;
  return;
}

/* _PPCRuntimeCompilerSetOptionFlags @ 0x97bd7f74 (16 bytes) */
int _PPCRuntimeCompilerSetOptionFlags(compiler, param_2)
  int compiler;
  uint param_2;
{
  *(uint *)(compiler + 0xe50) = *(uint *)(compiler + 0xe50) | param_2;
  return;
}

/* _PPCRuntimeCompilerCalculateIndirectAddress @ 0x97bd7f84 (224 bytes) */
int _PPCRuntimeCompilerCalculateIndirectAddress(compiler, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int compiler;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  ushort uVar1;
  uint *codeCursor;
  short sStack00000028;
  
  sStack00000028 = (short)((uint)param_5 >> 0x10);
  codeCursor = *(uint **)(compiler + 0xe30);
  *codeCursor = ((uint)(param_2 - *(int *)(param_3 * 0xc + *(int *)(compiler + 0xe24) + 0x80)) >> 4) +
            (int)sStack00000028 & 0xffff | 0x39f00000;
  *(uint **)(compiler + 0xe30) = codeCursor + 1;
  uVar1 = *(ushort *)(param_3 * 0xc + *(int *)(compiler + 0xe24) + 0x8a);
  codeCursor[2] = 0x1def0010;
  codeCursor[1] = uVar1 | 0x71ef0000;
  *(uint **)(compiler + 0xe30) = codeCursor + 3;
  codeCursor[3] = *(ushort *)(param_3 * 0xc + *(int *)(compiler + 0xe24) + 0x80) | 0x3ee00000;
  *(uint **)(compiler + 0xe30) = codeCursor + 4;
  codeCursor[4] = *(ushort *)(param_3 * 0xc + *(int *)(compiler + 0xe24) + 0x82) | 0x62f70000;
  codeCursor[5] = 0x7defba14;
  *(uint **)(compiler + 0xe30) = codeCursor + 6;
  return;
}

/* _PPCRuntimeCompilerLoadRegister @ 0x97bd8064 (2736 bytes) */
int _PPCRuntimeCompilerLoadRegister(compiler, regIndex, opOffsets, opBank, opSwizzle, opIndexInfo, opStorage, opFlags5, opType, opWord7, opWord8, element)
  int *compiler;
  uint regIndex;
  uint *opOffsets;
  undefined4 opBank;
  undefined4 opSwizzle;
  undefined4 opIndexInfo;
  uint opStorage;
  undefined4 opFlags5;
  int opType;
  undefined4 opWord7;
  undefined4 opWord8;
  int element;
{
  unsigned int ghidra_home[8] = { compiler, regIndex, opOffsets, opBank, opSwizzle, opIndexInfo, opStorage, opFlags5 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  byte bVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  undefined1 auStack_40 [28];
  
  iVar4 = element;
  uVar8 = 0;
  uVar9 = 0;
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = opSwizzle;
  iVar11 = 0;
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = opIndexInfo;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = opStorage;
  (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = opFlags5;
  if (compiler[0x393] != 0) {
    regIndex = regIndex + 0x20;
  }
  compiler[regIndex * 0xe + 0xc] = compiler[0x391];
  uVar5 = compiler[0x394];
  compiler[0x391] = compiler[0x391] + 1;
  (*(uint * *)((unsigned char *)ghidra_home + 8)) = opOffsets;
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = opBank;
  if ((uVar5 & 4) != 0) {
    uVar5 = regIndex;
    if (compiler[0x393] != 0) {
      uVar5 = regIndex - 0x20;
    }
    iVar3 = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(compiler,uVar5,opOffsets,opBank,opSwizzle,opIndexInfo,opStorage,opFlags5,opType,
                       opWord7,opWord8,element);
    if (iVar3 == 1) {
      return;
    }
    uVar5 = compiler[0x394];
  }
  if (compiler[0x393] == 0) {
    if ((uVar5 & 4) != 0) {
      uVar9 = 0;
      piVar12 = compiler;
      do {
        if ((*piVar12 == 0) &&
           (iVar11 = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(compiler,uVar9,(*(uint * *)((unsigned char *)ghidra_home + 8)),(*(unsigned int *)((unsigned char *)ghidra_home + 12)),(*(unsigned int *)((unsigned char *)ghidra_home + 16)),
                                (*(unsigned int *)((unsigned char *)ghidra_home + 20)),(*(unsigned int *)((unsigned char *)ghidra_home + 24)),(*(unsigned int *)((unsigned char *)ghidra_home + 28)),opType,opWord7,
                                opWord8,iVar4), iVar11 == 1)) {
          if (uVar9 != regIndex) {
            puVar2 = (uint *)compiler[0x38c];
            *puVar2 = regIndex << 0x15 | uVar9 << 0xb | 0xfc000090;
            compiler[0x38c] = (int)(puVar2 + 1);
            ((int (*)())_PPCRuntimeCompilerSetRegister)(compiler,regIndex,(*(uint * *)((unsigned char *)ghidra_home + 8)),(*(unsigned int *)((unsigned char *)ghidra_home + 12)),(*(unsigned int *)((unsigned char *)ghidra_home + 16)),(*(unsigned int *)((unsigned char *)ghidra_home + 20)),
                       (*(unsigned int *)((unsigned char *)ghidra_home + 24)),(*(unsigned int *)((unsigned char *)ghidra_home + 28)),opType,opWord7,opWord8,0,iVar4);
            piVar12[0xc] = compiler[0x391];
            goto LAB_97bd8938;
          }
          if (*(char *)((int)piVar12 + 0x1a) == (*(char *)((unsigned char *)ghidra_home + 26))) {
            return;
          }
        }
        uVar9 = uVar9 + 1;
        piVar12 = piVar12 + 0xe;
      } while (uVar9 < 0x20);
    }
    if ((*(char *)((unsigned char *)ghidra_home + 27)) == '\0') {
      if (((*(int *)(compiler[0x389] + 0x38) == 0x8804) ||
          (*(int *)(compiler[0x389] + 0x38) == 0x8b30)) && ((*(ushort *)((unsigned char *)ghidra_home + 24)) == 2)) {
        puVar7 = (uint *)compiler[0x38c];
        *puVar7 = (*(uint * *)((unsigned char *)ghidra_home + 8))[*(byte *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 16)) + iVar4)] & 0xffff | 0xc10d0000;
        bVar1 = *(byte *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 16)) + iVar4);
        compiler[0x38c] = (int)(puVar7 + 1);
        uVar9 = (*(uint * *)((unsigned char *)ghidra_home + 8))[bVar1];
        puVar2 = puVar7 + 3;
        puVar7[2] = regIndex << 0x15 | 0xec09433a;
        puVar7[1] = uVar9 & 0xffff | 0xc12c0000;
      }
      else {
        puVar2 = (uint *)compiler[0x38c];
        *puVar2 = regIndex << 0x15 | ((*(ushort *)((unsigned char *)ghidra_home + 24)) + 5) * 0x10000 |
                  (*(uint * *)((unsigned char *)ghidra_home + 8))[*(byte *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 16)) + iVar4)] & 0xffff | 0xc0000000;
        puVar2 = puVar2 + 1;
      }
      compiler[0x38c] = (int)puVar2;
    }
    else {
      ((int (*)())_PPCRuntimeCompilerCalculateIndirectAddress)(compiler,(*(uint * *)((unsigned char *)ghidra_home + 8)),(*(unsigned int *)((unsigned char *)ghidra_home + 12)),(*(unsigned int *)((unsigned char *)ghidra_home + 16)),(*(unsigned int *)((unsigned char *)ghidra_home + 20)),
                 (*(unsigned int *)((unsigned char *)ghidra_home + 24)),(*(unsigned int *)((unsigned char *)ghidra_home + 28)),opType);
      puVar2 = (uint *)compiler[0x38c];
      *puVar2 = (uint)*(byte *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 16)) + iVar4) << 2 | 0x82ef0000;
      puVar2[1] = regIndex << 0x15 | (((*(unsigned int *)((unsigned char *)ghidra_home + 24)) >> 0x10) + 5) * 0x10000 | 0x7c00bc2e;
      compiler[0x38c] = (int)(puVar2 + 2);
    }
    ((int (*)())_PPCRuntimeCompilerSetRegister)(compiler,regIndex,(*(uint * *)((unsigned char *)ghidra_home + 8)),(*(unsigned int *)((unsigned char *)ghidra_home + 12)),(*(unsigned int *)((unsigned char *)ghidra_home + 16)),(*(unsigned int *)((unsigned char *)ghidra_home + 20)),
               (*(unsigned int *)((unsigned char *)ghidra_home + 24)),(*(unsigned int *)((unsigned char *)ghidra_home + 28)),opType,opWord7,opWord8,0,iVar4);
    return;
  }
  if ((uVar5 & 4) != 0) {
    piVar12 = compiler + 0x1c0;
    uVar5 = 0;
    do {
      uVar10 = uVar5;
      iVar3 = *piVar12;
      piVar12 = piVar12 + 0xe;
      if (iVar3 == 0) {
        iVar3 = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(compiler,uVar10,(*(uint * *)((unsigned char *)ghidra_home + 8)),(*(unsigned int *)((unsigned char *)ghidra_home + 12)),(*(unsigned int *)((unsigned char *)ghidra_home + 16)),
                           (*(unsigned int *)((unsigned char *)ghidra_home + 20)),(*(unsigned int *)((unsigned char *)ghidra_home + 24)),(*(unsigned int *)((unsigned char *)ghidra_home + 28)),opType,opWord7,opWord8,
                           iVar4);
        if ((iVar3 == 3) && ((*(ushort *)((unsigned char *)ghidra_home + 24)) == 0)) {
          iVar11 = 3;
          uVar9 = uVar10;
        }
        else if (iVar3 - 1U < 2) break;
      }
      uVar5 = uVar10 + 1;
      uVar10 = uVar9;
      iVar3 = iVar11;
    } while (uVar5 < 0x20);
    if (iVar3 != 0) {
      iVar3 = regIndex - 0x20;
      puVar2 = (uint *)compiler[0x38c];
      *puVar2 = iVar3 * 0x200000 | uVar10 << 0x10 | uVar10 << 0xb | 0x10000484;
      compiler[0x38c] = (int)(puVar2 + 1);
      iVar11 = _memcmp(compiler + uVar10 * 0xe + 0x1c4,&(*(unsigned int *)((unsigned char *)ghidra_home + 16)),4);
      if (iVar11 != 0) {
        _PPCRuntimeCompilerBuildTransferSwizzle
                  (auStack_40,compiler + uVar10 * 0xe + 0x1c4,&(*(unsigned int *)((unsigned char *)ghidra_home + 16)));
        _PPCRuntimeCompilerSwizzleRegisterAV(compiler,iVar3,auStack_40);
      }
      ((int (*)())_PPCRuntimeCompilerSetRegister)(compiler,iVar3,(*(uint * *)((unsigned char *)ghidra_home + 8)),(*(unsigned int *)((unsigned char *)ghidra_home + 12)),(*(unsigned int *)((unsigned char *)ghidra_home + 16)),(*(unsigned int *)((unsigned char *)ghidra_home + 20)),
                 (*(unsigned int *)((unsigned char *)ghidra_home + 24)),(*(unsigned int *)((unsigned char *)ghidra_home + 28)),opType,opWord7,opWord8,0,iVar4);
      compiler[uVar10 * 0xe + 0x1cc] = compiler[0x391];
LAB_97bd8938:
      compiler[0x391] = compiler[0x391] + 1;
      return;
    }
  }
  puVar2 = (*(uint * *)((unsigned char *)ghidra_home + 8));
  if (((*(int *)(compiler[0x389] + 0x38) == 0x8804) || (*(int *)(compiler[0x389] + 0x38) == 0x8b30))
     && ((*(ushort *)((unsigned char *)ghidra_home + 24)) == 2)) {
    if ((compiler[0x394] & 8U) == 0) {
      uVar9 = *(*(uint * *)((unsigned char *)ghidra_home + 8));
    }
    else {
      uVar9 = 0;
      if (*(*(uint * *)((unsigned char *)ghidra_home + 8)) != 0) {
        puVar2 = (uint *)compiler[0x38c];
        *puVar2 = *(*(uint * *)((unsigned char *)ghidra_home + 8)) & 0xffff | 0x39e00000;
        puVar2[1] = 0x10c0728c;
        uVar9 = (regIndex - 0x20) * 0x200000;
        puVar2[2] = 0x7c6d78ce;
        puVar2[3] = 0x10a3728c;
        puVar2[4] = 0x7c8c78ce;
        puVar2[5] = uVar9 | 0x100419ae;
        puVar2[6] = uVar9 | (regIndex - 0x20) * 0x10000 | 0x1000396e;
        compiler[0x38c] = (int)(puVar2 + 7);
        goto LAB_97bd87b4;
      }
    }
    puVar2 = (uint *)compiler[0x38c];
    *puVar2 = uVar9 & 0xffff | 0x39e00000;
    puVar2[1] = 0x7c6d78ce;
    puVar2[2] = 0x7c8c78ce;
    puVar2[3] = 0x10c0728c;
    puVar2[4] = (regIndex - 0x20) * 0x200000 | 0x100419ae;
    compiler[0x38c] = (int)(puVar2 + 5);
    goto LAB_97bd87b4;
  }
  if ((*(char *)((unsigned char *)ghidra_home + 27)) == '\0') {
    uVar9 = *(*(uint * *)((unsigned char *)ghidra_home + 8));
    if (((((uVar9 & 0xf) != 0) || ((*(uint * *)((unsigned char *)ghidra_home + 8))[1] != uVar9 + 4)) ||
        ((*(uint * *)((unsigned char *)ghidra_home + 8))[2] != uVar9 + 8)) || ((*(uint * *)((unsigned char *)ghidra_home + 8))[3] != uVar9 + 0xc)) {
      puVar2 = (uint *)compiler[0x38c];
      *puVar2 = ((*(ushort *)((unsigned char *)ghidra_home + 24)) + 5) * 0x10000 | uVar9 & 0xffff | 0xc0000000;
      compiler[0x38c] = (int)(puVar2 + 1);
      puVar2[1] = ((*(ushort *)((unsigned char *)ghidra_home + 24)) + 5) * 0x10000 | (uint)*(ushort *)((int)(*(uint * *)((unsigned char *)ghidra_home + 8)) + 6) |
                  0xc0200000;
      compiler[0x38c] = (int)(puVar2 + 2);
      puVar2[2] = ((*(ushort *)((unsigned char *)ghidra_home + 24)) + 5) * 0x10000 | (uint)*(ushort *)((int)(*(uint * *)((unsigned char *)ghidra_home + 8)) + 10) |
                  0xc0400000;
      compiler[0x38c] = (int)(puVar2 + 3);
      puVar2[3] = ((*(ushort *)((unsigned char *)ghidra_home + 24)) + 5) * 0x10000 | (uint)*(ushort *)((int)(*(uint * *)((unsigned char *)ghidra_home + 8)) + 0xe) |
                  0xc0600000;
      puVar2[4] = 0xd0030200;
      puVar2[5] = 0xd0230204;
      puVar2[6] = 0xd0430208;
      puVar2[7] = 0xd063020c;
      puVar2[8] = 0x39e00200;
      puVar2[9] = (regIndex - 0x20) * 0x200000 | 0x7c0378ce;
      compiler[0x38c] = (int)(puVar2 + 10);
      goto LAB_97bd877c;
    }
    if (uVar9 != 0) {
      puVar2 = (uint *)compiler[0x38c];
      *puVar2 = uVar9 & 0xffff | 0x39e00000;
      uVar9 = (regIndex - 0x20) * 0x200000 | ((*(ushort *)((unsigned char *)ghidra_home + 24)) + 5) * 0x10000 | 0x7c0078ce;
      goto LAB_97bd8640;
    }
    puVar2 = (uint *)compiler[0x38c];
    *puVar2 = (regIndex - 0x20) * 0x200000 | ((*(ushort *)((unsigned char *)ghidra_home + 24)) + 5) * 0x800 | 0x7c0000ce;
    compiler[0x38c] = (int)(puVar2 + 1);
  }
  else {
    if ((*(ushort *)((unsigned char *)ghidra_home + 24)) == 0) {
      ((int (*)())_PPCRuntimeCompilerSaveAllTemporariesToMemory)(compiler);
    }
    ((int (*)())_PPCRuntimeCompilerCalculateIndirectAddress)(compiler,(*(uint * *)((unsigned char *)ghidra_home + 8)),(*(unsigned int *)((unsigned char *)ghidra_home + 12)),(*(unsigned int *)((unsigned char *)ghidra_home + 16)),(*(unsigned int *)((unsigned char *)ghidra_home + 20)),(*(unsigned int *)((unsigned char *)ghidra_home + 24)),
               (*(unsigned int *)((unsigned char *)ghidra_home + 28)),opType);
    uVar9 = *puVar2;
    if ((((uVar9 & 0xf) == 0) && (puVar2[1] == uVar9 + 4)) &&
       ((puVar2[2] == uVar9 + 8 && (puVar2[3] == uVar9 + 0xc)))) {
      puVar2 = (uint *)compiler[0x38c];
      *puVar2 = 0x82ef0000;
      uVar9 = (regIndex - 0x20) * 0x200000 | ((*(ushort *)((unsigned char *)ghidra_home + 24)) + 5) * 0x10000 | 0x7c00b8ce;
LAB_97bd8640:
      puVar2[1] = uVar9;
      compiler[0x38c] = (int)(puVar2 + 2);
    }
    else {
      puVar6 = (undefined4 *)compiler[0x38c];
      *puVar6 = 0x82ef0000;
      puVar6[1] = ((*(ushort *)((unsigned char *)ghidra_home + 24)) + 5) * 0x10000 | 0x7c00bc2e;
      puVar6[2] = 0x82ef0004;
      puVar6[3] = ((*(ushort *)((unsigned char *)ghidra_home + 24)) + 5) * 0x10000 | 0x7c20bc2e;
      puVar6[4] = 0x82ef0008;
      puVar6[5] = ((*(ushort *)((unsigned char *)ghidra_home + 24)) + 5) * 0x10000 | 0x7c40bc2e;
      puVar6[6] = 0x82ef000c;
      puVar6[7] = ((*(ushort *)((unsigned char *)ghidra_home + 24)) + 5) * 0x10000 | 0x7c60bc2e;
      puVar6[8] = 0xd0030200;
      puVar6[9] = 0xd0230204;
      puVar6[10] = 0xd0430208;
      puVar6[0xb] = 0xd063020c;
      puVar6[0xc] = 0x39e00200;
      puVar6[0xd] = (regIndex - 0x20) * 0x200000 | 0x7c0378ce;
      compiler[0x38c] = (int)(puVar6 + 0xe);
LAB_97bd877c:
      uVar8 = 1;
    }
  }
  if (opType - 3U < 2) {
    puVar2 = (uint *)compiler[0x38c];
    *puVar2 = (regIndex - 0x20) * 0x200000 | (regIndex - 0x20) * 0x800 | 0x1000034a;
    compiler[0x38c] = (int)(puVar2 + 1);
  }
LAB_97bd87b4:
  _PPCRuntimeCompilerSwizzleRegisterAV(compiler,regIndex - 0x20,&(*(unsigned int *)((unsigned char *)ghidra_home + 16)));
  ((int (*)())_PPCRuntimeCompilerSetRegister)(compiler,regIndex - 0x20,(*(uint * *)((unsigned char *)ghidra_home + 8)),(*(unsigned int *)((unsigned char *)ghidra_home + 12)),(*(unsigned int *)((unsigned char *)ghidra_home + 16)),(*(unsigned int *)((unsigned char *)ghidra_home + 20)),
             (*(unsigned int *)((unsigned char *)ghidra_home + 24)),(*(unsigned int *)((unsigned char *)ghidra_home + 28)),opType,opWord7,opWord8,uVar8,iVar4);
  iVar4 = _PPCRuntimeCompilerFindVariableInfo
                    (compiler,(*(uint * *)((unsigned char *)ghidra_home + 8)),(*(unsigned int *)((unsigned char *)ghidra_home + 12)),(*(unsigned int *)((unsigned char *)ghidra_home + 16)),(*(unsigned int *)((unsigned char *)ghidra_home + 20)),
                     (*(unsigned int *)((unsigned char *)ghidra_home + 24)),(*(unsigned int *)((unsigned char *)ghidra_home + 28)),opType);
  *(undefined4 *)(iVar4 + 4) = 0;
  return;
}

/* _PPCRuntimeCompilerBackupRegister @ 0x97bd8b14 (2144 bytes) */
int _PPCRuntimeCompilerBackupRegister(compiler, regIndex)
  int *compiler;
  uint regIndex;
{
  uint loopIndex3;
  uint *vectorInstWord2;
  undefined4 *vectorInstWord;
  uint registerLimit;
  int recordWord7;
  int variableInfo2;
  int componentSlot;
  int componentsRemaining;
  uint targetReg;
  uint bankFirstReg;
  int variableInfo;
  int componentUsed;
  int vectorRecordOffset;
  int containsResult;
  int vectorMode;
  uint loopIndex2;
  uint loopIndex;
  char cVar1;
  byte bVar2;
  bool bVar3;
  undefined4 vectorInstWord4;
  byte *pbVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint *puVar8;
  int *piVar9;
  int iVar10;
  int *regRecord;
  uint nextComponent;
  int *piVar13;
  uint vectorInstWord3;
  int iVar15;
  int bestAge;
  uint candidateReg;
  int iVar18;
  uint vectorRegIndex;
  uint uVar20;
  int local_60 [4];
  byte local_50;
  byte local_4f;
  byte local_4e;
  byte local_4d;
  undefined4 local_4c;
  undefined4 local_48;
  
  vectorMode = compiler[0x393];
  candidateReg = 0;
  bestAge = 0;
  bVar3 = false;
  if (vectorMode != 0) {
    regIndex = regIndex + 0x20;
  }
  iVar18 = regIndex * 0x38;
  if (compiler[regIndex * 0xe] == 0) {
    loopIndex = 0;
    regRecord = compiler;
    do {
      if (vectorMode == 0) {
        if (((loopIndex != regIndex) && (*regRecord == 0)) && (regRecord[0xb] != 0)) {
          containsResult = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(compiler,loopIndex,compiler[regIndex * 0xe + 2],compiler[regIndex * 0xe + 3],
                              compiler[regIndex * 0xe + 4],compiler[regIndex * 0xe + 5],
                              compiler[regIndex * 0xe + 6],compiler[regIndex * 0xe + 7],
                              compiler[regIndex * 0xe + 8],compiler[regIndex * 0xe + 9],
                              compiler[regIndex * 0xe + 10],compiler[regIndex * 0xe + 1]);
          if (containsResult == 1) {
            return;
          }
          goto LAB_97bd8c50;
        }
      }
      else if (((loopIndex != regIndex - 0x20) && (regRecord[0x1c0] == 0)) && (regRecord[0x1cb] != 0)) {
        containsResult = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(compiler,loopIndex,compiler[regIndex * 0xe + 2],compiler[regIndex * 0xe + 3],
                            compiler[regIndex * 0xe + 4],compiler[regIndex * 0xe + 5],
                            compiler[regIndex * 0xe + 6],compiler[regIndex * 0xe + 7],
                            compiler[regIndex * 0xe + 8],compiler[regIndex * 0xe + 9],
                            compiler[regIndex * 0xe + 10],compiler[regIndex * 0xe + 1]);
        if (containsResult - 1U < 2) {
          return;
        }
LAB_97bd8c50:
        vectorMode = compiler[0x393];
      }
      loopIndex = loopIndex + 1;
      regRecord = regRecord + 0xe;
    } while (loopIndex < 0x20);
    iVar10 = 0;
    if (vectorMode != 0) {
      vectorRegIndex = regIndex - 0x20;
      loopIndex2 = 0;
      vectorRecordOffset = vectorRegIndex * 0x38 + 0x708;
      regRecord = compiler;
      do {
        if (((loopIndex2 != vectorRegIndex) && (regRecord[0x1c0] == 0)) &&
           ((regRecord[0x1cb] != 0 &&
            ((iVar10 = _memcmp(regRecord[0x1c2],compiler[regIndex * 0xe + 2],0x10), iVar10 == 0 &&
             (*(short *)(regRecord + 0x1c6) == *(short *)(compiler + regIndex * 0xe + 6))))))) {
          local_4c = 0x10203;
          if (((uint)compiler[vectorRegIndex * 0xe + 0x1c4] >> 8 !=
               (compiler[vectorRegIndex * 0xe + 0x1c4] & 0xffffffU)) &&
             (((*(char *)(compiler + vectorRegIndex * 0xe + 0x1c4) != '\0' &&
               (*(char *)(compiler + vectorRegIndex * 0xe + 0x1c4) != -1)) ||
              ((((cVar1 = *(char *)((int)compiler + vectorRegIndex * 0x38 + 0x711), cVar1 != '\x01' &&
                 (cVar1 != -1)) ||
                ((cVar1 = *(char *)((int)compiler + vectorRegIndex * 0x38 + 0x712), cVar1 != '\x02' &&
                 (cVar1 != -1)))) ||
               ((cVar1 = *(char *)((int)compiler + vectorRegIndex * 0x38 + 0x713), cVar1 != '\x03' &&
                (cVar1 != -1)))))))) {
            _PPCRuntimeCompilerBuildTransferSwizzle
                      (&local_50,compiler + vectorRegIndex * 0xe + 0x1c4,&local_4c);
            _PPCRuntimeCompilerSwizzleRegisterAV(compiler,vectorRegIndex,&local_50);
            local_48 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)
                                                   ((int)compiler + (uint)local_50 + vectorRecordOffset + 8),
                                                  *(undefined1 *)
                                                   ((int)compiler + (uint)local_4f + vectorRecordOffset + 8)),
                                         *(undefined1 *)((int)compiler + (uint)local_4e + vectorRecordOffset + 8)
                                        ),
                                *(undefined1 *)((int)compiler + (uint)local_4d + vectorRecordOffset + 8));
            compiler[vectorRegIndex * 0xe + 0x1c4] = local_48;
          }
          if (((uint)regRecord[0x1c4] >> 8 != (regRecord[0x1c4] & 0xffffffU)) &&
             (((((*(char *)(regRecord + 0x1c4) != '\0' && (*(char *)(regRecord + 0x1c4) != -1)) ||
                ((*(char *)((int)regRecord + 0x711) != '\x01' &&
                 (*(char *)((int)regRecord + 0x711) != -1)))) ||
               ((*(char *)((int)regRecord + 0x712) != '\x02' &&
                (*(char *)((int)regRecord + 0x712) != -1)))) ||
              ((*(char *)((int)regRecord + 0x713) != '\x03' && (*(char *)((int)regRecord + 0x713) != -1)
               ))))) {
            _PPCRuntimeCompilerBuildTransferSwizzle(&local_50,regRecord + 0x1c4,&local_4c);
            _PPCRuntimeCompilerSwizzleRegisterAV(compiler,loopIndex2,&local_50);
            local_48 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)((int)regRecord + local_50 + 0x710),
                                                  *(undefined1 *)((int)regRecord + local_4f + 0x710)),
                                         *(undefined1 *)((int)regRecord + local_4e + 0x710)),
                                *(undefined1 *)((int)regRecord + local_4d + 0x710));
            regRecord[0x1c4] = local_48;
          }
          local_60[3] = 0;
          componentsRemaining = 4;
          local_60[0] = 0;
          local_60[1] = 0;
          piVar13 = local_60;
          local_60[2] = 0;
          pbVar5 = (byte *)(compiler + vectorRegIndex * 0xe + 0x1c4);
          do {
            bVar2 = *pbVar5;
            pbVar5 = pbVar5 + 1;
            if (bVar2 < 4) {
              piVar13[bVar2] = 1;
            }
            componentsRemaining = componentsRemaining + -1;
          } while (componentsRemaining != 0);
          if (local_60[0] + local_60[1] + local_60[2] + local_60[3] == 1) {
            if (local_60[0] == 0) {
              if (local_60[1] == 0) {
                if (local_60[2] == 0) {
                  if (local_60[3] == 0) goto LAB_97bd9024;
                  puVar6 = (undefined4 *)compiler[0x38c];
                  vectorInstWord4 = 0x106d6c84;
                }
                else {
                  puVar6 = (undefined4 *)compiler[0x38c];
                  vectorInstWord4 = 0x106d492c;
                }
              }
              else {
                puVar6 = (undefined4 *)compiler[0x38c];
                vectorInstWord4 = 0x106d4a2c;
              }
            }
            else {
              puVar6 = (undefined4 *)compiler[0x38c];
              vectorInstWord4 = 0x106d4b2c;
            }
            *puVar6 = vectorInstWord4;
            compiler[0x38c] = (int)(puVar6 + 1);
          }
          else {
            vectorInstWord = (undefined4 *)compiler[0x38c];
            *vectorInstWord = 0x10836a8c;
            vectorInstWord[1] = 0x10694c84;
            compiler[0x38c] = (int)(vectorInstWord + 2);
            loopIndex3 = 0;
            do {
              nextComponent = loopIndex3 + 1;
              if (piVar13[loopIndex3] != 0) {
                vectorInstWord3 = 3 - loopIndex3;
                if (nextComponent < 4) {
                  piVar9 = piVar13 + nextComponent;
                  uVar7 = nextComponent;
                  do {
                    componentSlot = *piVar9;
                    piVar9 = piVar9 + 1;
                    if (componentSlot != 0) {
                      vectorInstWord3 = (uVar7 - loopIndex3) - 1;
                      break;
                    }
                    uVar7 = uVar7 + 1;
                  } while (uVar7 < 4);
                }
                vectorInstWord = (undefined4 *)compiler[0x38c];
                *vectorInstWord = 0x1063212c;
                compiler[0x38c] = (int)(vectorInstWord + 1);
                if (vectorInstWord3 != 0) {
                  vectorInstWord[1] = (vectorInstWord3 & 3) << 8 | 0x1063482c;
                  compiler[0x38c] = (int)(vectorInstWord + 2);
                }
              }
              loopIndex3 = nextComponent;
            } while (nextComponent < 4);
          }
LAB_97bd9024:
          vectorInstWord2 = (uint *)compiler[0x38c];
          regRecord = regRecord + 0x1c4;
          *vectorInstWord2 = loopIndex2 << 0x15 | loopIndex2 << 0x10 | vectorRegIndex * 0x800 | 0x100000ea;
          componentsRemaining = 4;
          compiler[0x38c] = (int)(vectorInstWord2 + 1);
          piVar9 = compiler + vectorRegIndex * 0xe + 0x1c4;
          do {
            componentUsed = *piVar13;
            piVar13 = piVar13 + 1;
            if (componentUsed != 0) {
              *(undefined1 *)regRecord = *(undefined1 *)piVar9;
            }
            piVar9 = (int *)((int)piVar9 + 1);
            regRecord = (int *)((int)regRecord + 1);
            componentsRemaining = componentsRemaining + -1;
          } while (componentsRemaining != 0);
          return;
        }
        loopIndex2 = loopIndex2 + 1;
        regRecord = regRecord + 0xe;
      } while (loopIndex2 < 0x20);
      iVar10 = compiler[0x393];
    }
    if (((iVar10 != 0) && (*(short *)(compiler + regIndex * 0xe + 6) == 0)) &&
       ((*(char *)(compiler + regIndex * 0xe + 4) == -1 ||
        (((*(char *)((int)compiler + iVar18 + 0x11) == -1 ||
          (*(char *)((int)compiler + iVar18 + 0x12) == -1)) ||
         (*(char *)((int)compiler + iVar18 + 0x13) == -1)))))) {
      variableInfo = _PPCRuntimeCompilerFindVariableInfo
                         (compiler,compiler[regIndex * 0xe + 2],compiler[regIndex * 0xe + 3],
                          compiler[regIndex * 0xe + 4],compiler[regIndex * 0xe + 5],
                          compiler[regIndex * 0xe + 6],compiler[regIndex * 0xe + 7],
                          compiler[regIndex * 0xe + 8]);
      if (*(int *)(variableInfo + 4) != 0) {
        ((int (*)())_PPCRuntimeCompilerSaveRegisterToMemory)(compiler,regIndex - 0x20);
        ((int (*)())_PPCRuntimeCompilerDirtyRegister)(compiler,regIndex - 0x20);
        return;
      }
      iVar10 = compiler[0x393];
    }
    uVar20 = (uint)(iVar10 != 0);
    bankFirstReg = uVar20 * 0x20;
    if (iVar10 == 0) {
      registerLimit = 0x20;
    }
    else {
      registerLimit = 0x40;
    }
    if (bankFirstReg < registerLimit) {
      iVar15 = registerLimit + uVar20 * -0x20;
      regRecord = compiler + uVar20 * 0x1c0;
      do {
        if (((bankFirstReg != regIndex) && (regRecord[0xb] != 0)) &&
           ((bestAge <= compiler[0x391] - regRecord[0xc] && (regRecord[0xd] == 0)))) {
          bVar3 = true;
          bestAge = compiler[0x391] - regRecord[0xc];
          candidateReg = bankFirstReg;
        }
        bankFirstReg = bankFirstReg + 1;
        regRecord = regRecord + 0xe;
        iVar15 = iVar15 + -1;
      } while (iVar15 != 0);
      if (bVar3) {
        if ((*(short *)(compiler + candidateReg * 0xe + 6) == 0) && (compiler[candidateReg * 0xe] == 0)) {
          if (iVar10 == 0) {
            ((int (*)())_PPCRuntimeCompilerSaveRegisterToMemory)(compiler,candidateReg);
          }
          else {
            ((int (*)())_PPCRuntimeCompilerSaveRegisterToMemory)(compiler,candidateReg - 0x20);
            variableInfo2 = _PPCRuntimeCompilerFindVariableInfo
                               (compiler,compiler[candidateReg * 0xe + 2],compiler[candidateReg * 0xe + 3],
                                compiler[candidateReg * 0xe + 4],compiler[candidateReg * 0xe + 5],
                                compiler[candidateReg * 0xe + 6],compiler[candidateReg * 0xe + 7],
                                compiler[candidateReg * 0xe + 8]);
            *(undefined4 *)(variableInfo2 + 4) = 1;
          }
          iVar10 = compiler[0x393];
        }
        if (iVar10 == 0) {
          recordWord7 = compiler[regIndex * 0xe + 7];
          targetReg = candidateReg;
        }
        else {
          recordWord7 = compiler[regIndex * 0xe + 7];
          targetReg = candidateReg - 0x20;
        }
        ((int (*)())_PPCRuntimeCompilerSetRegister)(compiler,targetReg,compiler[regIndex * 0xe + 2],compiler[regIndex * 0xe + 3],
                   compiler[regIndex * 0xe + 4],compiler[regIndex * 0xe + 5],compiler[regIndex * 0xe + 6],
                   recordWord7,compiler[regIndex * 0xe + 8],compiler[regIndex * 0xe + 9],
                   compiler[regIndex * 0xe + 10],compiler[regIndex * 0xe + 0xd],
                   compiler[regIndex * 0xe + 1]);
        if (compiler[0x393] == 0) {
          puVar8 = (uint *)compiler[0x38c];
          candidateReg = candidateReg << 0x15 | regIndex << 0xb | 0xfc000090;
        }
        else {
          puVar8 = (uint *)compiler[0x38c];
          candidateReg = (candidateReg - 0x20) * 0x200000 | (regIndex - 0x20) * 0x10000 |
                   (regIndex - 0x20) * 0x800 | 0x10000484;
        }
        *puVar8 = candidateReg;
        compiler[0x38c] = (int)(puVar8 + 1);
        return;
      }
    }
    if (*(short *)(compiler + regIndex * 0xe + 6) == 0) {
      if (iVar10 != 0) {
        regIndex = regIndex - 0x20;
      }
      ((int (*)())_PPCRuntimeCompilerSaveRegisterToMemory)(compiler,regIndex);
    }
  }
  return;
}

/* _PPCRuntimeCompilerSaveAllTemporariesToMemory @ 0x97bd9374 (120 bytes) */
int _PPCRuntimeCompilerSaveAllTemporariesToMemory(param_1)
  int param_1;
{
  uint uVar1;
  uint loopIndex;
  
  loopIndex = 0;
  do {
    uVar1 = loopIndex;
    if (*(int *)(param_1 + 0xe4c) != 0) {
      uVar1 = loopIndex + 0x20;
    }
    if (*(short *)(uVar1 * 0x38 + param_1 + 0x18) == 0) {
      ((int (*)())_PPCRuntimeCompilerSaveRegisterToMemory)(param_1,loopIndex);
      ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,loopIndex);
    }
    loopIndex = loopIndex + 1;
  } while (loopIndex < 0x20);
  return;
}

/* _PPCRuntimeCompilerSaveRegisterToMemory @ 0x97bd93ec (1400 bytes) */
int _PPCRuntimeCompilerSaveRegisterToMemory(compiler, regIndex)
  int compiler;
  int regIndex;
{
  uint fieldInstWord2;
  int fieldInstWord;
  uint *codeCursor2;
  uint *puVar1;
  uint vectorInstWord;
  undefined4 vectorInstWord2;
  int iVar4;
  undefined4 *codeCursor;
  uint *codeWritePtr;
  uint ppcInstWord;
  int iVar8;
  uint *local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  
  if (*(int *)(compiler + 0xe4c) == 0) {
    iVar8 = regIndex * 0x38 + compiler;
    if (*(int *)(compiler + regIndex * 0x38) != 0) {
      return;
    }
    codeWritePtr = *(uint **)(compiler + 0xe30);
    vectorInstWord = regIndex << 0x15 | (*(ushort *)(iVar8 + 0x18) + 5) * 0x10000 |
            *(uint *)((uint)*(byte *)(iVar8 + *(int *)(iVar8 + 4) + 0x10) * 4 + *(int *)(iVar8 + 8))
            & 0xffff | 0xd0000000;
LAB_97bd9944:
    *codeWritePtr = vectorInstWord;
  }
  else {
    fieldInstWord = regIndex * 0x38 + compiler;
    if (*(int *)(fieldInstWord + 0x700) != 0) {
      return;
    }
    _memcpy(&local_50,fieldInstWord + 0x708,0x24);
    puVar1 = local_50;
    fieldInstWord = *(ushort *)(fieldInstWord + 0x718) + 5;
    _PPEmulatorVariableMaskFromSwizzle(&local_50);
    if ((*(unsigned char *)((unsigned char *)&(local_34) + 0)) == '\x0f') {
      iVar4 = *(int *)(*(int *)(compiler + 0xe24) + 0x38);
      if ((((iVar4 == 0x8804) || (iVar4 == 0x8b30)) && ((*(unsigned short *)((unsigned char *)&(local_40) + 0)) == 1)) && (*puVar1 == 0)) {
        codeCursor2 = *(uint **)(compiler + 0xe30);
        *codeCursor2 = regIndex << 0x10 | regIndex << 0xb | 0x12600484;
        *(uint **)(compiler + 0xe30) = codeCursor2 + 1;
        return;
      }
      if ((char)local_40 == '\0') {
        if (*puVar1 == 0) {
          codeWritePtr = *(uint **)(compiler + 0xe30);
          vectorInstWord = regIndex << 0x15 | fieldInstWord * 0x800 | 0x7c0001ce;
          goto LAB_97bd9944;
        }
        codeCursor2 = *(uint **)(compiler + 0xe30);
        ppcInstWord = *puVar1 & 0xffff | 0x39e00000;
        fieldInstWord2 = regIndex << 0x15 | fieldInstWord * 0x10000 | 0x7c0079ce;
      }
      else {
        ((int (*)())_PPCRuntimeCompilerCalculateIndirectAddress)(compiler,local_50,local_4c,local_48,local_44,local_40,local_3c,local_38);
        ppcInstWord = 0x82ef0000;
        codeCursor2 = *(uint **)(compiler + 0xe30);
        fieldInstWord2 = regIndex << 0x15 | fieldInstWord * 0x10000 | 0x7c00b9ce;
      }
    }
    else {
      iVar4 = *(int *)(*(int *)(compiler + 0xe24) + 0x38);
      if (((iVar4 == 0x8804) || (iVar4 == 0x8b30)) && ((*(unsigned short *)((unsigned char *)&(local_40) + 0)) == 1)) {
        codeCursor = *(undefined4 **)(compiler + 0xe30);
        codeCursor[1] = 0x10836a8c;
        *codeCursor = 0x10694c84;
        *(undefined4 **)(compiler + 0xe30) = codeCursor + 3;
        vectorInstWord2 = 0x1063212c;
        if ((local_34 & 0x1000000) == 0) {
          vectorInstWord2 = 0x1063492c;
        }
        codeCursor[2] = vectorInstWord2;
        codeCursor = *(undefined4 **)(compiler + 0xe30);
        vectorInstWord2 = 0x1063212c;
        *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
        if ((local_34 & 0x2000000) == 0) {
          vectorInstWord2 = 0x1063492c;
        }
        *codeCursor = vectorInstWord2;
        codeCursor = *(undefined4 **)(compiler + 0xe30);
        vectorInstWord2 = 0x1063212c;
        *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
        if ((local_34 & 0x4000000) == 0) {
          vectorInstWord2 = 0x1063492c;
        }
        *codeCursor = vectorInstWord2;
        codeCursor = *(undefined4 **)(compiler + 0xe30);
        vectorInstWord2 = 0x1063212c;
        *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
        if ((local_34 & 0x8000000) == 0) {
          vectorInstWord2 = 0x1063492c;
        }
        *codeCursor = vectorInstWord2;
        codeWritePtr = *(uint **)(compiler + 0xe30);
        vectorInstWord = regIndex << 0xb | 0x127300ea;
        goto LAB_97bd9944;
      }
      iVar4 = *(int *)(*(int *)(compiler + 0xe24) + 0x38);
      if (((iVar4 == 0x8804) || (iVar4 == 0x8b30)) && ((*(unsigned short *)((unsigned char *)&(local_40) + 0)) == 9)) {
        codeCursor = *(undefined4 **)(compiler + 0xe30);
        *codeCursor = 0x39e00210;
        codeCursor[1] = regIndex << 0x15 | 0x7c0379ce;
        codeWritePtr = codeCursor + 3;
        codeCursor[2] = 0xc1a30218;
        goto LAB_97bd994c;
      }
      if ((char)local_40 == '\0') {
        if ((local_34 & 0x1000000) != 0) {
          codeCursor2 = *(uint **)(compiler + 0xe30);
          *codeCursor2 = (ushort)*puVar1 | 0x39e00000;
          codeCursor2[1] = regIndex << 0x15 | fieldInstWord * 0x10000 | 0x7c00798e;
          *(uint **)(compiler + 0xe30) = codeCursor2 + 2;
        }
        if ((local_34 & 0x2000000) != 0) {
          codeCursor2 = *(uint **)(compiler + 0xe30);
          *codeCursor2 = *(ushort *)((int)puVar1 + 6) | 0x39e00000;
          codeCursor2[1] = regIndex << 0x15 | fieldInstWord * 0x10000 | 0x7c00798e;
          *(uint **)(compiler + 0xe30) = codeCursor2 + 2;
        }
        if ((local_34 & 0x4000000) != 0) {
          codeCursor2 = *(uint **)(compiler + 0xe30);
          *codeCursor2 = *(ushort *)((int)puVar1 + 10) | 0x39e00000;
          codeCursor2[1] = regIndex << 0x15 | fieldInstWord * 0x10000 | 0x7c00798e;
          *(uint **)(compiler + 0xe30) = codeCursor2 + 2;
        }
        if ((local_34 & 0x8000000) == 0) {
          return;
        }
        codeCursor2 = *(uint **)(compiler + 0xe30);
        ppcInstWord = *(ushort *)((int)puVar1 + 0xe) | 0x39e00000;
        fieldInstWord2 = regIndex << 0x15 | fieldInstWord * 0x10000 | 0x7c00798e;
      }
      else {
        ((int (*)())_PPCRuntimeCompilerCalculateIndirectAddress)(compiler,local_50,local_4c,local_48,local_44,local_40,local_3c,local_38);
        if ((local_34 & 0x1000000) != 0) {
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x82ef0000;
          codeCursor[1] = regIndex << 0x15 | fieldInstWord * 0x10000 | 0x7c00b98e;
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
        }
        if ((local_34 & 0x2000000) != 0) {
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x82ef0004;
          codeCursor[1] = regIndex << 0x15 | fieldInstWord * 0x10000 | 0x7c00b98e;
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
        }
        if ((local_34 & 0x4000000) != 0) {
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x82ef0008;
          codeCursor[1] = regIndex << 0x15 | fieldInstWord * 0x10000 | 0x7c00b98e;
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
        }
        if ((local_34 & 0x8000000) == 0) {
          return;
        }
        codeCursor2 = *(uint **)(compiler + 0xe30);
        ppcInstWord = 0x82ef000c;
        fieldInstWord2 = regIndex << 0x15 | fieldInstWord * 0x10000 | 0x7c00b98e;
      }
    }
    *codeCursor2 = ppcInstWord;
    codeWritePtr = codeCursor2 + 1;
    *codeWritePtr = fieldInstWord2;
  }
  codeWritePtr = codeWritePtr + 1;
LAB_97bd994c:
  *(uint **)(compiler + 0xe30) = codeWritePtr;
  return;
}

/* _PPCRuntimeCompilerDirtyRegister @ 0x97bd9964 (112 bytes) */
int _PPCRuntimeCompilerDirtyRegister(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if (*(int *)(param_1 + 0xe4c) != 0) {
    param_2 = param_2 + 0x20;
  }
  iVar1 = param_2 * 0x38 + param_1;
  *(undefined4 *)(param_2 * 0x38 + param_1) = 1;
  *(undefined4 *)(iVar1 + 4) = 0;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  *(undefined1 *)(iVar1 + 0x13) = 0xff;
  *(undefined1 *)(iVar1 + 0x10) = 0xff;
  *(undefined1 *)(iVar1 + 0x11) = 0xff;
  *(undefined1 *)(iVar1 + 0x12) = 0xff;
  *(undefined4 *)(iVar1 + 0x30) = 0;
  return;
}

/* _PPCRuntimeCompilerDirtyRegistersWithData @ 0x97bd99d4 (436 bytes) */
int _PPCRuntimeCompilerDirtyRegistersWithData(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  uVar2 = param_11;
  uVar7 = 0;
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = param_2;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = param_4;
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = param_5;
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = param_6;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = param_7;
  (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = param_8;
  if (*(int *)(param_1 + 0xe4c) == 0) {
    do {
      iVar6 = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(param_1,uVar7,(*(unsigned int *)((unsigned char *)ghidra_home + 4)),(*(unsigned int *)((unsigned char *)ghidra_home + 8)),(*(unsigned int *)((unsigned char *)ghidra_home + 12)),(*(unsigned int *)((unsigned char *)ghidra_home + 16)),
                         (*(unsigned int *)((unsigned char *)ghidra_home + 20)),(*(unsigned int *)((unsigned char *)ghidra_home + 24)),(*(unsigned int *)((unsigned char *)ghidra_home + 28)),param_9,param_10,uVar2);
      if (iVar6 == 1) {
        ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,uVar7);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 0x20);
  }
  else {
    iVar6 = 0;
    do {
      iVar3 = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(param_1,uVar7,(*(unsigned int *)((unsigned char *)ghidra_home + 4)),(*(unsigned int *)((unsigned char *)ghidra_home + 8)),(*(unsigned int *)((unsigned char *)ghidra_home + 12)),(*(unsigned int *)((unsigned char *)ghidra_home + 16)),
                         (*(unsigned int *)((unsigned char *)ghidra_home + 20)),(*(unsigned int *)((unsigned char *)ghidra_home + 24)),(*(unsigned int *)((unsigned char *)ghidra_home + 28)),param_9,param_10,uVar2);
      if (iVar3 - 1U < 3) {
        uVar4 = 0;
        iVar3 = iVar6 + param_1 + 0x700;
        do {
          iVar8 = 4;
          pcVar5 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 12));
          do {
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
            if (*(char *)(iVar3 + 0x10) == cVar1) {
              *(undefined1 *)(iVar3 + 0x10) = 0xff;
            }
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
          uVar4 = uVar4 + 1;
          iVar3 = iVar3 + 1;
        } while (uVar4 < 4);
        iVar3 = iVar6 + param_1;
        if ((((*(char *)(iVar3 + 0x710) == -1) && (*(char *)(iVar3 + 0x711) == -1)) &&
            (*(char *)(iVar3 + 0x712) == -1)) && (*(char *)(iVar3 + 0x713) == -1)) {
          ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,uVar7);
        }
      }
      uVar7 = uVar7 + 1;
      iVar6 = iVar6 + 0x38;
    } while (uVar7 < 0x20);
  }
  return;
}

/* _PPCRuntimeCompilerDirtyRegistersWithIndirectData @ 0x97bd9b88 (136 bytes) */
int _PPCRuntimeCompilerDirtyRegistersWithIndirectData(param_1)
  int param_1;
{
  int iVar1;
  uint loopIndex;
  char *pcVar3;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0xe4c) != 0) {
    iVar1 = 0x20;
  }
  iVar1 = iVar1 * 0x38;
  loopIndex = 0;
  pcVar3 = (char *)(iVar1 + param_1 + 0x1b);
  do {
    if ((*(int *)(iVar1 + param_1) == 0) && (*pcVar3 != '\0')) {
      ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,loopIndex);
    }
    loopIndex = loopIndex + 1;
    iVar1 = iVar1 + 0x38;
    pcVar3 = pcVar3 + 0x38;
  } while (loopIndex < 0x20);
  return;
}

/* _PPCRuntimeCompilerDirtyRegistersContainingAttributes @ 0x97bd9c10 (136 bytes) */
int _PPCRuntimeCompilerDirtyRegistersContainingAttributes(param_1)
  int param_1;
{
  int iVar1;
  uint loopIndex;
  short *psVar3;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0xe4c) != 0) {
    iVar1 = 0x20;
  }
  iVar1 = iVar1 * 0x38;
  loopIndex = 0;
  psVar3 = (short *)(iVar1 + param_1 + 0x18);
  do {
    if ((*(int *)(iVar1 + param_1) == 0) && (*psVar3 == 2)) {
      ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,loopIndex);
    }
    loopIndex = loopIndex + 1;
    iVar1 = iVar1 + 0x38;
    psVar3 = psVar3 + 0x1c;
  } while (loopIndex < 0x20);
  return;
}

/* _PPCRuntimeCompilerDirtyRegistersContainingTemps @ 0x97bd9c98 (136 bytes) */
int _PPCRuntimeCompilerDirtyRegistersContainingTemps(param_1)
  int param_1;
{
  int iVar1;
  uint loopIndex;
  short *psVar3;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0xe4c) != 0) {
    iVar1 = 0x20;
  }
  iVar1 = iVar1 * 0x38;
  loopIndex = 0;
  psVar3 = (short *)(iVar1 + param_1 + 0x18);
  do {
    if ((*(int *)(iVar1 + param_1) == 0) && (*psVar3 == 0)) {
      ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,loopIndex);
    }
    loopIndex = loopIndex + 1;
    iVar1 = iVar1 + 0x38;
    psVar3 = psVar3 + 0x1c;
  } while (loopIndex < 0x20);
  return;
}

/* _PPCRuntimeCompilerDirtyRegistersContainingParams @ 0x97bd9d20 (136 bytes) */
int _PPCRuntimeCompilerDirtyRegistersContainingParams(param_1)
  int param_1;
{
  int iVar1;
  uint loopIndex;
  int *piVar3;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0xe4c) != 0) {
    iVar1 = 0x20;
  }
  loopIndex = 0;
  piVar3 = (int *)(iVar1 * 0x38 + param_1);
  do {
    if (((*piVar3 == 0) && (piVar3[3] == 3)) && (piVar3[0xd] == 0)) {
      ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,loopIndex);
    }
    loopIndex = loopIndex + 1;
    piVar3 = piVar3 + 0xe;
  } while (loopIndex < 0x20);
  return;
}

/* _PPCRuntimeCompilerSetRegister @ 0x97bd9da8 (148 bytes) */
int _PPCRuntimeCompilerSetRegister(compiler, regIndex, opOffsets, opBank, opSwizzle, opIndexInfo, opStorage, opFlags5, opType, opWord7, opWord8, recordFlag, element)
  int compiler;
  int regIndex;
  undefined4 opOffsets;
  undefined4 opBank;
  undefined4 opSwizzle;
  undefined4 opIndexInfo;
  undefined4 opStorage;
  undefined4 opFlags5;
  undefined4 opType;
  undefined4 opWord7;
  undefined4 opWord8;
  undefined4 recordFlag;
  undefined4 element;
{
  unsigned int ghidra_home[8] = { compiler, regIndex, opOffsets, opBank, opSwizzle, opIndexInfo, opStorage, opFlags5 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  int iVar1;
  
  if (*(int *)(compiler + 0xe4c) != 0) {
    regIndex = regIndex + 0x20;
  }
  *(undefined4 *)(regIndex * 0x38 + compiler) = 0;
  iVar1 = regIndex * 0x38 + compiler;
  *(undefined4 *)(iVar1 + 4) = element;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = opOffsets;
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = opBank;
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = opSwizzle;
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = opIndexInfo;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = opStorage;
  (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = opFlags5;
  _memcpy(iVar1 + 8,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)),0x24);
  *(undefined4 *)(iVar1 + 0x34) = recordFlag;
  *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(compiler + 0xe44);
  *(int *)(compiler + 0xe44) = *(int *)(compiler + 0xe44) + 1;
  return;
}

/* _PPCRuntimeCompilerRegisterContainsData @ 0x97bd9e3c (560 bytes) */
int _PPCRuntimeCompilerRegisterContainsData(compiler, regIndex, opOffsets, opBank, opSwizzle, opIndexInfo, opStorage, opFlags5, opType, opWord7, opWord8, element)
  int compiler;
  int regIndex;
  undefined4 opOffsets;
  undefined4 opBank;
  undefined4 opSwizzle;
  undefined4 opIndexInfo;
  undefined4 opStorage;
  uint opFlags5;
  undefined4 opType;
  undefined4 opWord7;
  undefined4 opWord8;
  int element;
{
  unsigned int ghidra_home[8] = { compiler, regIndex, opOffsets, opBank, opSwizzle, opIndexInfo, opStorage, opFlags5 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int local_20 [6];
  
  local_20[3] = 0;
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = opOffsets;
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = opBank;
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = opSwizzle;
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = opIndexInfo;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = opStorage;
  (*(uint *)((unsigned char *)ghidra_home + 28)) = opFlags5;
  if (*(int *)(compiler + 0xe4c) == 0) {
    iVar2 = regIndex * 0x38 + compiler;
    if ((((*(int *)(compiler + regIndex * 0x38) == 0) &&
         (iVar7 = _memcmp(*(undefined4 *)(iVar2 + 8),opOffsets,0x10), iVar7 == 0)) &&
        (*(short *)(iVar2 + 0x18) == (*(short *)((unsigned char *)ghidra_home + 24)))) &&
       (((*(char *)(iVar2 + *(int *)(iVar2 + 4) + 0x10) ==
          *(char *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 16)) + element) && ((*(char *)((unsigned char *)ghidra_home + 27)) == '\0')) &&
        (*(char *)(iVar2 + 0x1b) == '\0')))) {
      return 1;
    }
  }
  else {
    iVar2 = (regIndex + 0x20) * 0x38;
    iVar7 = iVar2 + compiler;
    if ((*(int *)(compiler + iVar2) == 0) &&
       (iVar2 = _memcmp(*(undefined4 *)(iVar7 + 8),opOffsets,0x10), iVar2 == 0)) {
      if ((*(short *)(iVar7 + 0x18) == (*(short *)((unsigned char *)ghidra_home + 24))) &&
         (((*(char *)((unsigned char *)ghidra_home + 27)) == '\0' && (*(char *)(iVar7 + 0x1b) == '\0')))) {
        iVar2 = _memcmp(iVar7 + 0x10,&(*(unsigned int *)((unsigned char *)ghidra_home + 16)),(*(uint *)((unsigned char *)ghidra_home + 28)) >> 0x10 & 0xff);
        if (iVar2 == 0) {
          return 1;
        }
        uVar6 = 0;
        piVar4 = local_20;
        do {
          if ((uVar6 < ((*(uint *)((unsigned char *)ghidra_home + 28)) >> 0x10 & 0xff)) &&
             (*(byte *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 16)) + uVar6) < 4)) {
            uVar5 = 0;
            pbVar3 = (byte *)(iVar7 + 0x10);
            do {
              bVar1 = *pbVar3;
              pbVar3 = pbVar3 + 1;
              if (bVar1 == *(byte *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 16)) + uVar6)) goto LAB_97bd9f54;
              uVar5 = uVar5 + 1;
            } while (uVar5 < 4);
          }
          else {
LAB_97bd9f54:
            *piVar4 = 1;
          }
          uVar6 = uVar6 + 1;
          piVar4 = piVar4 + 1;
          if (3 < uVar6) {
            if ((((local_20[0] != 0) && (local_20[1] != 0)) && (local_20[2] != 0)) &&
               (local_20[3] != 0)) {
              return 2;
            }
            if (((local_20[0] == 0) && (local_20[1] == 0)) &&
               ((local_20[2] == 0 && (local_20[3] == 0)))) {
              return 0;
            }
            return 3;
          }
        } while( true );
      }
    }
  }
  return 0;
}

