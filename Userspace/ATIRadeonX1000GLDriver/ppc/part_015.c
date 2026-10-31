#include "decls.h"

/* gld_setUnitTargetBits @ 0xa1090 (200 bytes) */
int gld_setUnitTargetBits(ctx, unitEnabled, unitTarget)
  int ctx;
  int unitEnabled;
  int *unitTarget;
{
  int programObject;
  int shaderOffset;
  int shaderTable;
  undefined4 unitTargetBits;
  uint loopIndex;
  int unitStatePtr;
  int unitIndex;
  int unitsLeft;
  
  unitIndex = 0;
  unitsLeft = 0x10;
  unitStatePtr = ctx;
  do {
    unitTargetBits = 0;
    if (*(char *)(unitEnabled + unitIndex) != '\0') {
      unitTargetBits = 2;
      if ((*unitTarget != 1) && (unitTargetBits = 1, *unitTarget != 2)) {
        unitTargetBits = 8;
      }
    }
    *(undefined4 *)(unitStatePtr + 0x48) = unitTargetBits;
    unitIndex = unitIndex + 1;
    unitTarget = unitTarget + 1;
    unitStatePtr = unitStatePtr + 4;
    unitsLeft = unitsLeft + -1;
  } while (unitsLeft != 0);
  shaderTable = *(int *)(((unsigned char *)0x00001154) + ctx);
  if (*(int *)(shaderTable + 4) != 0) {
    loopIndex = 0;
    shaderOffset = 0;
    do {
      programObject = *(int *)(*(int *)(((unsigned char *)0x0000113c) + ctx) * 4 +
                      *(int *)(shaderOffset + *(int *)(shaderTable + 0x88) + 0x70));
      if (programObject != 0) {
        *(undefined4 *)(((unsigned char *)0x000015cc) + programObject) = 1;
        shaderTable = *(int *)(((unsigned char *)0x00001154) + ctx);
      }
      loopIndex = loopIndex + 1;
      shaderOffset = shaderOffset + 0x78;
    } while (loopIndex < *(uint *)(shaderTable + 4));
  }
  *(undefined4 *)(ctx + 0x27bc) = 0;
  return;
}

/* gld_getShaderTexUnitMask @ 0xa1160 (48 bytes) */
int gld_getShaderTexUnitMask(ctx)
  int ctx;
{
  if (((ctx != -0x1134) && (*(int *)(((unsigned char *)0x00001144) + ctx) != 0)) &&
     (*(char *)(*(int *)(((unsigned char *)0x00001144) + ctx) + 0x74) != '\0')) {
    return ((unsigned char *)0x00001135)[ctx];
  }
  return 0;
}

/* gld_getFragmentShaderKind @ 0xa11a0 (64 bytes) */
int gld_getFragmentShaderKind(ctx)
  int ctx;
{
  int boundShader;
  
  if (((ctx != -0x1134) && (boundShader = *(int *)(((unsigned char *)0x00001144) + ctx), boundShader != 0)) &&
     (*(char *)(boundShader + 0x74) != '\0')) {
    if (*(char *)(boundShader + 0x6c) != '\0') {
      return 3;
    }
    return 1;
  }
  return 0;
}

/* gld_collectUsedTexCoordUnits @ 0xa11f0 (192 bytes) */
int gld_collectUsedTexCoordUnits(ctx, shader, passCount)
  int ctx;
  int shader;
  int passCount;
{
  ushort regsPerPass;
  int entryOffset;
  uint unitIndex;
  int loopIndex;
  int regIndex;
  uint regsLeft;
  
  ((unsigned char *)0x00001135)[ctx] = 0;
  if (passCount < 1) {
    return;
  }
  regsPerPass = *(ushort *)(((unsigned char *)0x00001148) + ctx);
  loopIndex = 0;
  do {
    regsLeft = (uint)regsPerPass;
    if (regsPerPass != 0) {
      regIndex = 0;
      if ((regsPerPass == 0) || (regsLeft == 0x80000000)) {
        regsLeft = 1;
      }
      do {
        entryOffset = (regIndex + loopIndex * (uint)regsPerPass) * 0xc;
        if ((*(char *)(entryOffset + *(int *)(shader + 0xc)) != '\0') &&
           (unitIndex = *(int *)(entryOffset + *(int *)(shader + 0xc) + 8) - 0x84c0, unitIndex < 8)) {
          ((unsigned char *)0x00001135)[ctx] = (byte)(1 << (unitIndex & 0x3f)) | ((unsigned char *)0x00001135)[ctx];
        }
        regIndex = regIndex + 1;
        regsLeft = regsLeft - 1;
      } while (regsLeft != 0);
    }
    loopIndex = loopIndex + 1;
  } while (passCount != loopIndex);
  return;
}

/* glGenFragmentShadersATI_impl @ 0xa12b0 (52 bytes) */
int glGenFragmentShadersATI_impl(ctx, range)
  int ctx;
  int range;
{
  int firstId;
  
  if ((range != 0) && (((unsigned char *)0x00001134)[ctx] == '\0')) {
    firstId = **(int **)(((unsigned char *)0x00001154) + ctx);
    **(int **)(((unsigned char *)0x00001154) + ctx) = range + firstId;
    return firstId;
  }
  return 0;
}

/* glBindFragmentShaderATI_impl @ 0xa12f0 (612 bytes) */
int glBindFragmentShaderATI_impl(ctx, shaderId)
  int ctx;
  int shaderId;
{
  uint ctxFlags;
  int shaders;
  uint loopIndex;
  bool searching;
  undefined4 newShaders;
  int shaderOffset;
  int nextShaderOffset;
  uint shaderCount;
  uint newCtxFlags;
  int shaderTable;
  
  if (((unsigned char *)0x00001134)[ctx] == '\0') {
    shaderTable = *(int *)(((unsigned char *)0x00001154) + ctx);
    loopIndex = 0;
    nextShaderOffset = 0;
    shaderCount = *(uint *)(shaderTable + 4);
    searching = true;
    shaderOffset = 0;
    while (loopIndex < shaderCount) {
      if (!searching) goto setShaders;
      if (shaderId == *(int *)(shaderOffset + *(int *)(shaderTable + 0x88))) {
        searching = false;
      }
      else {
        nextShaderOffset = nextShaderOffset + 0x78;
        loopIndex = loopIndex + 1;
        shaderOffset = nextShaderOffset;
      }
    }
    if (searching) {
      if ((shaderCount & 7) == 0) {
        newShaders = (**(code **)(ctx + 0x10))(1,shaderCount * 0x78 + 0x3c0);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (newShaders,*(undefined4 *)(shaderTable + 0x88),*(int *)(shaderTable + 4) * 0x78);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(shaderTable + 0x88));
        *(undefined4 *)(shaderTable + 0x88) = newShaders;
        shaderCount = *(uint *)(shaderTable + 4);
      }
      ((int (*)())atifsInitShader)(ctx,shaderCount * 0x78 + *(int *)(shaderTable + 0x88));
      *(int *)(*(int *)(shaderTable + 4) * 0x78 + *(int *)(shaderTable + 0x88)) = shaderId;
      *(int *)(shaderTable + 4) = *(int *)(shaderTable + 4) + 1;
      *(uint *)(((unsigned char *)0x00001140) + ctx) = loopIndex;
      ctxFlags = *(uint *)(ctx + 0x44);
      *(uint *)(ctx + 0x44) = ctxFlags & 0xffffbfff;
      if ((ctxFlags & 0x32000) == 0x30000) {
        *(uint *)(ctx + 0x44) = ctxFlags & 0xfffebfff;
      }
      ((unsigned char *)0x00001136)[ctx] = 1;
    }
    else {
setShaders:
      shaders = *(int *)(shaderTable + 0x88);
      if (loopIndex != *(uint *)(((unsigned char *)0x00001140) + ctx)) {
        ((unsigned char *)0x00001136)[ctx] = 1;
      }
      *(uint *)(((unsigned char *)0x00001140) + ctx) = loopIndex;
      if (*(char *)(shaderOffset + shaders + 0x6c) == '\0') {
        ctxFlags = *(uint *)(ctx + 0x44);
        *(uint *)(ctx + 0x44) = ctxFlags & 0xffffbfff;
        if ((ctxFlags & 0x32000) == 0x30000) {
          *(uint *)(ctx + 0x44) = ctxFlags & 0xfffebfff;
        }
      }
      else {
        ctxFlags = *(uint *)(ctx + 0x44);
        newCtxFlags = ctxFlags >> 1 & 0x4000 | ctxFlags & 0xffffbfff;
        *(uint *)(ctx + 0x44) = newCtxFlags;
        if ((ctxFlags & 0x32000) == 0x20000) {
          *(uint *)(ctx + 0x44) = newCtxFlags | 0x10000;
        }
      }
    }
    shaderOffset = shaderOffset + *(int *)(shaderTable + 0x88);
    *(int *)(((unsigned char *)0x00001144) + ctx) = shaderOffset;
    ((int (*)())gld_collectUsedTexCoordUnits)(ctx,shaderOffset,*(undefined4 *)(shaderOffset + 4));
    if ((*(uint *)(ctx + 0x44) & 0x22000) == 0x20000) {
      *(uint *)(ctx + 0x38) = *(uint *)(ctx + 0x38) | 0x2000;
      *(byte *)(ctx + 0x2e) = *(byte *)(ctx + 0x2e) | 3;
      *(undefined1 *)(ctx + 0x29) = 1;
    }
  }
  return;
}

/* glDeleteFragmentShaderATI_impl @ 0xa1570 (312 bytes) */
int glDeleteFragmentShaderATI_impl(ctx, shaderId)
  int ctx;
  int shaderId;
{
  int loopIndex2;
  bool searching;
  int shaderEntry;
  uint loopIndex;
  int shaderTable;
  
  if ((((unsigned char *)0x00001134)[ctx] == '\0') && (shaderId != 0)) {
    shaderTable = *(int *)(((unsigned char *)0x00001154) + ctx);
    if (shaderId == **(int **)(((unsigned char *)0x00001144) + ctx)) {
      ((int (*)())glBindFragmentShaderATI_impl)(ctx,0);
    }
    loopIndex = 0;
    loopIndex2 = 0;
    searching = true;
    while (loopIndex < *(uint *)(shaderTable + 4)) {
      if (!searching) goto callAtifsFreeShader;
      if (shaderId == *(int *)(loopIndex2 + *(int *)(shaderTable + 0x88))) {
        searching = false;
      }
      else {
        loopIndex = loopIndex + 1;
        loopIndex2 = loopIndex2 + 0x78;
      }
    }
    if (!searching) {
callAtifsFreeShader:
      ((int (*)())atifsFreeShader)(ctx,loopIndex * 0x78 + *(int *)(shaderTable + 0x88));
      shaderEntry = loopIndex * 0x78 + *(int *)(shaderTable + 0x88);
      _memmove(shaderEntry,shaderEntry + 0x78,(*(int *)(shaderTable + 4) - loopIndex) * 0x78 + -0x78);
      *(int *)(shaderTable + 4) = *(int *)(shaderTable + 4) + -1;
      if (loopIndex < *(uint *)(((unsigned char *)0x00001140) + ctx)) {
        shaderEntry = *(uint *)(((unsigned char *)0x00001140) + ctx) - 1;
        *(int *)(((unsigned char *)0x00001140) + ctx) = shaderEntry;
        *(int *)(((unsigned char *)0x00001144) + ctx) = shaderEntry * 0x78 + *(int *)(shaderTable + 0x88);
      }
    }
  }
  return;
}

/* glBeginFragmentShaderATI_impl @ 0xa16b0 (148 bytes) */
int glBeginFragmentShaderATI_impl(ctx)
  int ctx;
{
  if (((unsigned char *)0x00001134)[ctx] == '\0') {
    ((unsigned char *)0x00001134)[ctx] = 1;
    ((int (*)())atifsFreeShader)(ctx,*(undefined4 *)(((unsigned char *)0x00001144) + ctx));
    ((int (*)())atifsInitShader)(ctx,*(undefined4 *)(((unsigned char *)0x00001144) + ctx));
    if ((*(uint *)(ctx + 0x44) & 0x22000) == 0x20000) {
      *(undefined1 *)(ctx + 0x29) = 1;
      *(uint *)(ctx + 0x38) = *(uint *)(ctx + 0x38) | 0x2000;
      *(byte *)(ctx + 0x2e) = *(byte *)(ctx + 0x2e) | 3;
    }
  }
  return;
}

/* glEndFragmentShaderATI_impl @ 0xa1750 (772 bytes) */
int glEndFragmentShaderATI_impl(ctx)
  int ctx;
{
  int validateResult;
  bool colorOpsPending;
  bool usesColorInterpolator;
  int alphaOffset;
  int colorOffset;
  int opOrdinal;
  int loopIndex2;
  int loopIndex;
  int opRecord;
  uint flagsBefore;
  uint flagsAfter;
  int loopIndex3;
  int colorOpsPlaced;
  int shader;
  
  if (((unsigned char *)0x00001134)[ctx] == '\0') {
    return;
  }
  shader = *(int *)(((unsigned char *)0x00001144) + ctx);
  if ((byte)((unsigned char *)0x00001138)[ctx] == 1) {
    usesColorInterpolator = false;
    colorOpsPlaced = 0;
    loopIndex = 0;
    loopIndex2 = 0;
    loopIndex3 = 0;
    opOrdinal = 0;
    alphaOffset = 0;
    colorOffset = 0;
    colorOpsPending = 0 < **(int **)(shader + 0x14);
    while ((colorOpsPending || (loopIndex < **(int **)(shader + 0x20)))) {
      if ((loopIndex2 < *(int *)(shader + 0x18)) &&
         ((colorOpsPending && (opRecord = colorOffset + *(int *)(shader + 0x10), opOrdinal == *(int *)(opRecord + 0x44))))) {
        if (((*(int *)(opRecord + 0x14) == 0x8577) ||
            (((*(int *)(opRecord + 0x14) == 0x896d || (*(int *)(opRecord + 0x24) == 0x8577)) ||
             (*(int *)(opRecord + 0x24) == 0x896d)))) ||
           ((*(int *)(opRecord + 0x34) == 0x8577 || (*(int *)(opRecord + 0x34) == 0x896d)))) {
          usesColorInterpolator = true;
        }
        colorOpsPlaced = colorOpsPlaced + 1;
        loopIndex2 = loopIndex2 + 1;
        colorOffset = colorOffset + 0x4c;
        opOrdinal = opOrdinal + 1;
        colorOpsPending = colorOpsPlaced < **(int **)(shader + 0x14);
      }
      if (((loopIndex3 < *(int *)(shader + 0x24)) && (loopIndex < **(int **)(shader + 0x20))) &&
         (opRecord = alphaOffset + *(int *)(shader + 0x1c), opOrdinal == *(int *)(opRecord + 0x44))) {
        if (((((*(int *)(opRecord + 0x14) == 0x8577) || (*(int *)(opRecord + 0x14) == 0x896d)) ||
             (*(int *)(opRecord + 0x24) == 0x8577)) ||
            ((*(int *)(opRecord + 0x24) == 0x896d || (*(int *)(opRecord + 0x34) == 0x8577)))) ||
           (*(int *)(opRecord + 0x34) == 0x896d)) {
          usesColorInterpolator = true;
        }
        loopIndex3 = loopIndex3 + 1;
        alphaOffset = alphaOffset + 0x4c;
        opOrdinal = opOrdinal + 1;
        loopIndex = loopIndex + 1;
      }
    }
    if (usesColorInterpolator) {
      *(undefined4 *)(shader + 4) = 1;
      ((int (*)())atifsSetShaderValid)(*(undefined4 *)(((unsigned char *)0x00001144) + ctx),0);
      goto callGldCollectUsedTexCoordUnits;
    }
  }
  *(uint *)(shader + 4) = (byte)((unsigned char *)0x00001138)[ctx] + 1;
callGldCollectUsedTexCoordUnits:
  ((int (*)())gld_collectUsedTexCoordUnits)(ctx,*(int *)(((unsigned char *)0x00001144) + ctx),
               *(undefined4 *)(*(int *)(((unsigned char *)0x00001144) + ctx) + 4));
  ((unsigned char *)0x00001136)[ctx] = 1;
  ((unsigned char *)0x00001134)[ctx] = 0;
  validateResult = (**(code **)(((unsigned char *)0x00001164) + ctx))(ctx);
  if (validateResult == 0) {
    ((int (*)())atifsSetShaderValid)(*(undefined4 *)(((unsigned char *)0x00001144) + ctx),0);
  }
  ((unsigned char *)0x00001137)[ctx] = 0;
  ((unsigned char *)0x00001138)[ctx] = 0;
  if (*(char *)(shader + 0x6c) == '\0') {
    flagsBefore = *(uint *)(ctx + 0x44);
    flagsAfter = flagsBefore & 0xffffbfff;
    *(uint *)(ctx + 0x44) = flagsAfter;
    if ((flagsBefore & 0x32000) == 0x30000) {
      flagsAfter = flagsBefore & 0xfffebfff;
      *(undefined1 *)(ctx + 0x29) = 1;
      *(uint *)(ctx + 0x44) = flagsAfter;
      *(uint *)(ctx + 0x38) = *(uint *)(ctx + 0x38) | 0x20;
    }
  }
  else {
    flagsBefore = *(uint *)(ctx + 0x44);
    flagsAfter = flagsBefore >> 1 & 0x4000 | flagsBefore & 0xffffbfff;
    *(uint *)(ctx + 0x44) = flagsAfter;
    if ((flagsBefore & 0x32000) == 0x20000) {
      flagsAfter = flagsAfter | 0x10000;
      *(undefined1 *)(ctx + 0x29) = 1;
      *(uint *)(ctx + 0x44) = flagsAfter;
      *(uint *)(ctx + 0x38) = *(uint *)(ctx + 0x38) | 0x20;
    }
  }
  if ((flagsAfter & 0x22000) == 0x20000) {
    *(uint *)(ctx + 0x38) = *(uint *)(ctx + 0x38) | 0x2000;
    *(byte *)(ctx + 0x2e) = *(byte *)(ctx + 0x2e) | 3;
    *(undefined1 *)(ctx + 0x29) = 1;
  }
  return;
}

/* glPassTexCoordATI_impl @ 0xa1a60 (328 bytes) */
int glPassTexCoordATI_impl(ctx, dst, coord, swizzle)
  int ctx;
  int dst;
  int coord;
  int swizzle;
{
  int addOk;
  uint passIndex;
  
  if (((unsigned char *)0x00001134)[ctx] == '\0') {
    return;
  }
  passIndex = (uint)(byte)((unsigned char *)0x00001138)[ctx] -
          ((int)-(uint)(byte)((unsigned char *)0x00001137)[ctx] >> 0x1f);
  if (((passIndex < (byte)((unsigned char *)0x00001150)[ctx]) && (dst - 0x8921U < 6)) &&
     (swizzle - 0x8976U < 4)) {
    if (coord - 0x84c0U < 0x20) {
      if ((int)(uint)(byte)((unsigned char *)0x000013b2)[ctx] < (int)(coord - 0x84c0U)) goto callAtifsSetShaderValid;
    }
    else if (((5 < coord - 0x8921U) || (passIndex == 0)) ||
            ((swizzle != 0x8976 && (swizzle != 0x8978)))) goto callAtifsSetShaderValid;
    addOk = ((int (*)())atifsAddTextureOp)(ctx,*(undefined4 *)(((unsigned char *)0x00001144) + ctx),passIndex,dst,coord,0,
                         swizzle);
    if (addOk != 0) {
      if (((unsigned char *)0x00001137)[ctx] == '\0') {
        return;
      }
      ((unsigned char *)0x00001137)[ctx] = 0;
      ((unsigned char *)0x00001138)[ctx] = ((unsigned char *)0x00001138)[ctx] + '\x01';
      return;
    }
  }
callAtifsSetShaderValid:
  ((int (*)())atifsSetShaderValid)(*(undefined4 *)(((unsigned char *)0x00001144) + ctx),0);
  return;
}

/* glSampleMapATI_impl @ 0xa1bc0 (328 bytes) */
int glSampleMapATI_impl(ctx, dst, coordSource, swizzle)
  int ctx;
  int dst;
  int coordSource;
  int swizzle;
{
  int addOk;
  uint passIndex;
  
  if (((unsigned char *)0x00001134)[ctx] == '\0') {
    return;
  }
  passIndex = (uint)(byte)((unsigned char *)0x00001138)[ctx] -
          ((int)-(uint)(byte)((unsigned char *)0x00001137)[ctx] >> 0x1f);
  if (((passIndex < (byte)((unsigned char *)0x00001150)[ctx]) && (dst - 0x8921U < 6)) &&
     (swizzle - 0x8976U < 4)) {
    if (coordSource - 0x84c0U < 0x20) {
      if ((int)(uint)(byte)((unsigned char *)0x000013b2)[ctx] < (int)(coordSource - 0x84c0U)) goto callAtifsSetShaderValid;
    }
    else if (((5 < coordSource - 0x8921U) || (passIndex == 0)) ||
            ((swizzle != 0x8976 && (swizzle != 0x8978)))) goto callAtifsSetShaderValid;
    addOk = ((int (*)())atifsAddTextureOp)(ctx,*(undefined4 *)(((unsigned char *)0x00001144) + ctx),passIndex,dst,coordSource,1,
                         swizzle);
    if (addOk != 0) {
      if (((unsigned char *)0x00001137)[ctx] == '\0') {
        return;
      }
      ((unsigned char *)0x00001137)[ctx] = 0;
      ((unsigned char *)0x00001138)[ctx] = ((unsigned char *)0x00001138)[ctx] + '\x01';
      return;
    }
  }
callAtifsSetShaderValid:
  ((int (*)())atifsSetShaderValid)(*(undefined4 *)(((unsigned char *)0x00001144) + ctx),0);
  return;
}

/* glColorFragmentOp1ATI_impl @ 0xa1d20 (156 bytes) */
int glColorFragmentOp1ATI_impl(ctx, op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod)
  int ctx;
  undefined4 op;
  undefined4 dst;
  undefined4 dstMask;
  undefined4 dstMod;
  undefined4 arg1;
  undefined4 arg1Rep;
  undefined4 arg1Mod;
{
  if (((unsigned char *)0x00001134)[ctx] != '\0') {
    ((unsigned char *)0x00001137)[ctx] = 1;
    ((int (*)())atifsAddColorOp)(ctx,*(undefined4 *)(((unsigned char *)0x00001144) + ctx),
                 (uint)(byte)((unsigned char *)0x00001138)[ctx],op,dst,dstMask,dstMod,arg1,
                 arg1Rep,arg1Mod,0,0,0,0,0,0);
  }
  return;
}

/* glColorFragmentOp2ATI_impl @ 0xa1dc0 (168 bytes) */
int glColorFragmentOp2ATI_impl(ctx, op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod)
  int ctx;
  undefined4 op;
  undefined4 dst;
  undefined4 dstMask;
  undefined4 dstMod;
  undefined4 arg1;
  undefined4 arg1Rep;
  undefined4 arg1Mod;
  undefined4 arg2;
  undefined4 arg2Rep;
  undefined4 arg2Mod;
{
  if (((unsigned char *)0x00001134)[ctx] != '\0') {
    ((unsigned char *)0x00001137)[ctx] = 1;
    ((int (*)())atifsAddColorOp)(ctx,*(undefined4 *)(((unsigned char *)0x00001144) + ctx),
                 (uint)(byte)((unsigned char *)0x00001138)[ctx],op,dst,dstMask,dstMod,arg1,
                 arg1Rep,arg1Mod,arg2,arg2Rep,arg2Mod,0,0,0);
  }
  return;
}

/* glColorFragmentOp3ATI_impl @ 0xa1e70 (176 bytes) */
int glColorFragmentOp3ATI_impl(ctx, op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod)
  int ctx;
  undefined4 op;
  undefined4 dst;
  undefined4 dstMask;
  undefined4 dstMod;
  undefined4 arg1;
  undefined4 arg1Rep;
  undefined4 arg1Mod;
  undefined4 arg2;
  undefined4 arg2Rep;
  undefined4 arg2Mod;
  undefined4 arg3;
  undefined4 arg3Rep;
  undefined4 arg3Mod;
{
  if (((unsigned char *)0x00001134)[ctx] != '\0') {
    ((unsigned char *)0x00001137)[ctx] = 1;
    ((int (*)())atifsAddColorOp)(ctx,*(undefined4 *)(((unsigned char *)0x00001144) + ctx),
                 (uint)(byte)((unsigned char *)0x00001138)[ctx],op,dst,dstMask,dstMod,arg1,
                 arg1Rep,arg1Mod,arg2,arg2Rep,arg2Mod,arg3,arg3Rep,arg3Mod);
  }
  return;
}

/* glAlphaFragmentOp1ATI_impl @ 0xa1f20 (144 bytes) */
int glAlphaFragmentOp1ATI_impl(ctx, op, dst, dstMod, arg1, arg1Rep, arg1Mod)
  int ctx;
  undefined4 op;
  undefined4 dst;
  undefined4 dstMod;
  undefined4 arg1;
  undefined4 arg1Rep;
  undefined4 arg1Mod;
{
  if (((unsigned char *)0x00001134)[ctx] != '\0') {
    ((unsigned char *)0x00001137)[ctx] = 1;
    ((int (*)())atifsAddAlphaOp)(ctx,*(undefined4 *)(((unsigned char *)0x00001144) + ctx),
                 (uint)(byte)((unsigned char *)0x00001138)[ctx],op,dst,dstMod,arg1,arg1Rep,
                 arg1Mod,0,0,0,0,0,0);
  }
  return;
}

/* glAlphaFragmentOp2ATI_impl @ 0xa1fb0 (160 bytes) */
int glAlphaFragmentOp2ATI_impl(ctx, op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod)
  int ctx;
  undefined4 op;
  undefined4 dst;
  undefined4 dstMod;
  undefined4 arg1;
  undefined4 arg1Rep;
  undefined4 arg1Mod;
  undefined4 arg2;
  undefined4 arg2Rep;
  undefined4 arg2Mod;
{
  if (((unsigned char *)0x00001134)[ctx] != '\0') {
    ((unsigned char *)0x00001137)[ctx] = 1;
    ((int (*)())atifsAddAlphaOp)(ctx,*(undefined4 *)(((unsigned char *)0x00001144) + ctx),
                 (uint)(byte)((unsigned char *)0x00001138)[ctx],op,dst,dstMod,arg1,arg1Rep,
                 arg1Mod,arg2,arg2Rep,arg2Mod,0,0,0);
  }
  return;
}

/* glAlphaFragmentOp3ATI_impl @ 0xa2050 (168 bytes) */
int glAlphaFragmentOp3ATI_impl(ctx, op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod)
  int ctx;
  undefined4 op;
  undefined4 dst;
  undefined4 dstMod;
  undefined4 arg1;
  undefined4 arg1Rep;
  undefined4 arg1Mod;
  undefined4 arg2;
  undefined4 arg2Rep;
  undefined4 arg2Mod;
  undefined4 arg3;
  undefined4 arg3Rep;
  undefined4 arg3Mod;
{
  if (((unsigned char *)0x00001134)[ctx] != '\0') {
    ((unsigned char *)0x00001137)[ctx] = 1;
    ((int (*)())atifsAddAlphaOp)(ctx,*(undefined4 *)(((unsigned char *)0x00001144) + ctx),
                 (uint)(byte)((unsigned char *)0x00001138)[ctx],op,dst,dstMod,arg1,arg1Rep,
                 arg1Mod,arg2,arg2Rep,arg2Mod,arg3,arg3Rep,arg3Mod);
  }
  return;
}

/* glSetFragmentShaderConstantATI_impl @ 0xa2100 (192 bytes) */
int glSetFragmentShaderConstantATI_impl(ctx, dst, value)
  int ctx;
  int dst;
  undefined4 value;
{
  if (7 < dst - 0x8941U) {
    ((int (*)())atifsSetShaderValid)(*(undefined4 *)(((unsigned char *)0x00001144) + ctx),0);
    return;
  }
  ((int (*)())atifsSetConstant)(ctx,*(undefined4 *)(((unsigned char *)0x00001144) + ctx),dst,value,
               (uint)(byte)((unsigned char *)0x00001134)[ctx]);
  if (((*(uint *)(ctx + 0x44) & 0x22000) == 0x20000) &&
     ((*(uint *)(ctx + 0x38) & 0x2000) != 0)) {
    *(uint *)(ctx + 0x38) = *(uint *)(ctx + 0x38) | 0x2000;
    *(undefined1 *)(ctx + 0x29) = 1;
    *(byte *)(ctx + 0x2e) = *(byte *)(ctx + 0x2e) | 2;
  }
  return;
}

/* atifsResetState @ 0xa21d0 (100 bytes) */
int atifsResetState(ctx)
  int ctx;
{
  (**(code **)(((unsigned char *)0x0000115c) + ctx))(ctx);
  ((unsigned char *)0x00001134)[ctx] = 0;
  ((unsigned char *)0x00001136)[ctx] = 1;
  ((unsigned char *)0x00001138)[ctx] = 0;
  ((unsigned char *)0x00001137)[ctx] = 0;
  *(undefined4 *)(((unsigned char *)0x00001140) + ctx) = 0;
  *(undefined4 *)(((unsigned char *)0x00001144) + ctx) =
       *(undefined4 *)(*(int *)(((unsigned char *)0x00001154) + ctx) + 0x88);
  return;
}

/* atifsFreeShaderTable @ 0xa2240 (232 bytes) */
int atifsFreeShaderTable(ctx)
  int ctx;
{
  int shader;
  uint loopIndex;
  int shaderOffset;
  int shaderTable;
  
  shaderTable = *(int *)(((unsigned char *)0x00001154) + ctx);
  ((int (*)())atifsFreeShader)(ctx,shaderTable + 0x10);
  if (*(int *)(shaderTable + 4) != 0) {
    loopIndex = 0;
    shaderOffset = 0;
    do {
      loopIndex = loopIndex + 1;
      shader = shaderOffset + *(int *)(shaderTable + 0x88);
      shaderOffset = shaderOffset + 0x78;
      ((int (*)())atifsFreeShader)(ctx,shader);
    } while (loopIndex < *(uint *)(shaderTable + 4));
  }
  *(undefined4 *)(shaderTable + 4) = 0;
  if (*(int *)(shaderTable + 0x88) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(shaderTable + 0x88));
    *(undefined4 *)(shaderTable + 0x88) = 0;
  }
  if (*(int *)(shaderTable + 0xc) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(shaderTable + 0xc));
    *(undefined4 *)(shaderTable + 0xc) = 0;
  }
  (**(code **)(ctx + 0x18))(shaderTable);
  *(undefined4 *)(((unsigned char *)0x00001154) + ctx) = 0;
  return;
}

/* atifsReleaseShaderTable @ 0xa2330 (120 bytes) */
int atifsReleaseShaderTable(ctx)
  int ctx;
{
  *(int *)(*(int *)(((unsigned char *)0x00001154) + ctx) + 8) =
       *(int *)(*(int *)(((unsigned char *)0x00001154) + ctx) + 8) + -1;
  if (*(int *)(*(int *)(((unsigned char *)0x00001154) + ctx) + 8) == 0) {
    (**(code **)(((unsigned char *)0x00001160) + ctx))(ctx);
    ((int (*)())atifsFreeShaderTable)(ctx);
    return;
  }
  return;
}

/* atifsUnshareShaderTable @ 0xa23c0 (356 bytes) */
int atifsUnshareShaderTable(ctx, srcCtx)
  int ctx;
  int srcCtx;
{
  int shader;
  undefined4 oldProgramTable;
  undefined4 newProgramTable;
  int shaderOffset;
  int slotIndex;
  undefined4 newSlotTable;
  uint loopIndex;
  undefined4 oldSlotTable;
  int shaderEntry;
  int sharedTable;
  
  *(int *)(*(int *)(((unsigned char *)0x00001154) + ctx) + 8) =
       *(int *)(*(int *)(((unsigned char *)0x00001154) + ctx) + 8) + -1;
  if (*(int *)(*(int *)(((unsigned char *)0x00001154) + ctx) + 8) == 0) {
    ((int (*)())atifsFreeShaderTable)(ctx);
  }
  sharedTable = *(int *)(((unsigned char *)0x00001154) + srcCtx);
  ((unsigned char *)0x00001138)[ctx] = 0;
  ((unsigned char *)0x00001137)[ctx] = 0;
  ((unsigned char *)0x00001134)[ctx] = 0;
  *(undefined4 *)(((unsigned char *)0x00001140) + ctx) = 0;
  *(int *)(((unsigned char *)0x00001154) + ctx) = sharedTable;
  slotIndex = *(int *)(sharedTable + 0x8c);
  *(int *)(((unsigned char *)0x0000113c) + ctx) = slotIndex;
  *(int *)(sharedTable + 0x8c) = slotIndex + 1;
  *(undefined4 *)(((unsigned char *)0x00001144) + ctx) = *(undefined4 *)(sharedTable + 0x88);
  oldSlotTable = *(undefined4 *)(sharedTable + 0x80);
  *(int *)(sharedTable + 8) = *(int *)(sharedTable + 8) + 1;
  newSlotTable = (**(code **)(ctx + 0x10))(*(undefined4 *)(sharedTable + 0x8c),4);
  *(undefined4 *)(sharedTable + 0x80) = newSlotTable;
  _memcpy(newSlotTable,oldSlotTable,*(int *)(sharedTable + 0x8c) * 4 + -4);
  (**(code **)(ctx + 0x18))(oldSlotTable);
  if (*(int *)(sharedTable + 4) != 0) {
    loopIndex = 0;
    shaderOffset = 0;
    do {
      loopIndex = loopIndex + 1;
      shaderEntry = shaderOffset + *(int *)(sharedTable + 0x88);
      oldProgramTable = *(undefined4 *)(shaderEntry + 0x70);
      newProgramTable = (**(code **)(ctx + 0x10))(*(undefined4 *)(sharedTable + 0x8c),4);
      *(undefined4 *)(shaderEntry + 0x70) = newProgramTable;
      shader = *(int *)(sharedTable + 0x88) + shaderOffset;
      shaderOffset = shaderOffset + 0x78;
      _memcpy(*(undefined4 *)(shader + 0x70),oldProgramTable,*(int *)(sharedTable + 0x8c) * 4 + -4);
      (**(code **)(ctx + 0x18))(oldProgramTable);
    } while (loopIndex < *(uint *)(sharedTable + 4));
  }
  return;
}

/* atifsCreateShaderTable @ 0xa2530 (288 bytes) */
int atifsCreateShaderTable(ctx)
  int ctx;
{
  undefined4 *shaders;
  undefined1 *defaultConstants;
  undefined1 *constantCursor;
  int loopIndex;
  
  *(undefined4 *)(((unsigned char *)0x0000113c) + ctx) = 0;
  shaders = (undefined4 *)(**(code **)(ctx + 0xc))(0x3c0);
  defaultConstants = (undefined1 *)
           (**(code **)(ctx + 0xc))((uint)*(ushort *)(((unsigned char *)0x0000114a) + ctx) * 0x14);
  if (defaultConstants != (undefined1 *)0x0) {
    if (*(short *)(((unsigned char *)0x0000114a) + ctx) != 0) {
      loopIndex = 0;
      constantCursor = defaultConstants;
      do {
        loopIndex = loopIndex + 1;
        *(undefined4 *)(constantCursor + 0x10) = 0x3f800000;
        *constantCursor = 0;
        *(undefined4 *)(constantCursor + 4) = 0x3f800000;
        *(undefined4 *)(constantCursor + 8) = 0x3f800000;
        *(undefined4 *)(constantCursor + 0xc) = 0x3f800000;
        constantCursor = constantCursor + 0x14;
      } while (loopIndex < (int)(uint)*(ushort *)(((unsigned char *)0x0000114a) + ctx));
    }
    *(undefined4 *)(*(int *)(((unsigned char *)0x00001154) + ctx) + 8) = 1;
    *(undefined4 **)(*(int *)(((unsigned char *)0x00001154) + ctx) + 0x88) = shaders;
    *(undefined1 **)(*(int *)(((unsigned char *)0x00001154) + ctx) + 0xc) = defaultConstants;
    **(undefined4 **)(((unsigned char *)0x00001154) + ctx) = 1;
    *(undefined4 *)(*(int *)(((unsigned char *)0x00001154) + ctx) + 4) = 1;
    *(undefined4 *)(*(int *)(((unsigned char *)0x00001154) + ctx) + 0x8c) = 1;
    ((int (*)())atifsInitShader)(ctx,shaders);
    *shaders = 0;
    ((int (*)())atifsInitShader)(ctx,*(int *)(((unsigned char *)0x00001154) + ctx) + 0x10);
    *(undefined4 *)(*(int *)(((unsigned char *)0x00001154) + ctx) + 0x10) = 0;
  }
  return;
}

/* atifsPackArgument @ 0xa2660 (392 bytes) */
int atifsPackArgument(ctx, shader, argReg, argRep, argMods, packedArg)
  undefined4 ctx;
  int shader;
  uint argReg;
  uint argRep;
  uint argMods;
  uint *packedArg;
{
  uint modsCompFolded;
  uint modsNormalized;
  
  if (((((((5 < argReg - 0x8921) && (7 < argReg - 0x8941)) && (argReg != 0)) &&
        ((argReg != 1 && (argReg != 0x8577)))) && (argReg != 0x896d)) ||
      (((*packedArg = argReg, argRep != 0 && (argRep != 0x1903)) &&
       ((argRep != 0x1904 && ((argRep != 0x1905 && (argRep != 0x1906)))))))) ||
     (packedArg[3] = argRep, (argMods & 0xfffffff0) != 0)) {
    return 0;
  }
  packedArg[2] = argMods;
  packedArg[1] = 0;
  if (argReg < 2) {
    packedArg[3] = 0;
    if (argReg == 0) {
      if ((argMods & 2) != 0) {
        argMods = argMods & 0xfffffffd;
        argReg = 1;
      }
    }
    else if ((argReg == 1) && ((argMods & 2) != 0)) {
      argMods = argMods & 0xfffffffd;
      argReg = 0;
    }
    modsCompFolded = argMods;
    if ((((argMods & 8) != 0) ||
        ((modsNormalized = argMods, argReg == 0 &&
         (modsCompFolded = argMods & 0xfffffffa, modsNormalized = modsCompFolded, (argMods & 8) != 0)))) &&
       ((modsNormalized = modsCompFolded, (modsCompFolded & 1) != 0 && (modsNormalized = modsCompFolded & 0xfffffff6, argReg == 0)))) {
      if ((modsCompFolded & 4) == 0) {
        modsNormalized = modsNormalized | 4;
        argReg = 1;
      }
      else {
        argReg = 1;
        modsNormalized = modsCompFolded & 0xfffffff2;
      }
    }
    packedArg[2] = modsNormalized;
    *packedArg = argReg;
  }
  if (argReg == 0x896d) {
    *(undefined1 *)(shader + 0x6c) = 1;
    return 1;
  }
  return 1;
}

/* atifsCountPassOps @ 0xa27f0 (272 bytes) */
int atifsCountPassOps(passState, shader, colorOpsInLastPass, alphaOpsInLastPass)
  int passState;
  int shader;
  int *colorOpsInLastPass;
  int *alphaOpsInLastPass;
{
  bool colorOpsPending;
  bool alphaOpsPending;
  int colorOpsPlaced;
  int colorOpsInPass;
  int alphaOpsInPass;
  int alphaOpsPlaced;
  int opOrdinal;
  int loopIndex;
  int loopIndex2;
  int passByteOffset;
  int loopIndex3;
  
  if (*(byte *)(passState + 4) == 0xffffffff) {
    colorOpsPlaced = 0;
    alphaOpsPlaced = 0;
  }
  else {
    loopIndex = 0;
    loopIndex2 = 0;
    opOrdinal = 0;
    loopIndex3 = 0;
    passByteOffset = 0;
    do {
      colorOpsInPass = *(int *)(passByteOffset + *(int *)(shader + 0x14));
      alphaOpsInPass = *(int *)(passByteOffset + *(int *)(shader + 0x20));
      colorOpsPlaced = 0;
      alphaOpsPlaced = 0;
      colorOpsPending = 0 < colorOpsInPass;
      alphaOpsPending = 0 < alphaOpsInPass;
      while ((colorOpsPending || (alphaOpsPending))) {
        if ((loopIndex < *(int *)(shader + 0x18)) &&
           ((colorOpsPending && (opOrdinal == *(int *)(loopIndex * 0x4c + *(int *)(shader + 0x10) + 0x44))))) {
          colorOpsPlaced = colorOpsPlaced + 1;
          loopIndex = loopIndex + 1;
          opOrdinal = opOrdinal + 1;
          colorOpsPending = colorOpsPlaced < colorOpsInPass;
        }
        if (((loopIndex2 < *(int *)(shader + 0x24)) && (alphaOpsPending)) &&
           (opOrdinal == *(int *)(loopIndex2 * 0x4c + *(int *)(shader + 0x1c) + 0x44))) {
          alphaOpsPlaced = alphaOpsPlaced + 1;
          loopIndex2 = loopIndex2 + 1;
          opOrdinal = opOrdinal + 1;
          alphaOpsPending = alphaOpsPlaced < alphaOpsInPass;
        }
      }
      loopIndex3 = loopIndex3 + 1;
      passByteOffset = passByteOffset + 4;
    } while (loopIndex3 != *(byte *)(passState + 4) + 1);
  }
  *colorOpsInLastPass = colorOpsPlaced;
  *alphaOpsInLastPass = alphaOpsPlaced;
  return;
}

/* atifsSetShaderValid @ 0xa2910 (8 bytes) */
int atifsSetShaderValid(shader, valid)
  int shader;
  undefined4 valid;
{
  *(undefined1 *)(shader + 0x74) = (undefined1)valid;
  return;
}

/* atifsInitShader @ 0xa2920 (648 bytes) */
int atifsInitShader(ctx, shader)
  int ctx;
  int shader;
{
  int constantRecord;
  int constantOffset;
  int loopIndex2;
  uint maxPasses;
  uint regsPerPass;
  undefined4 newBuffer;
  int passByteOffset;
  int entryOffset;
  int loopIndex;
  int defaultCoordSource;
  
  *(undefined1 *)(shader + 0x6c) = 0;
  *(undefined4 *)(shader + 8) = 0;
  *(undefined4 *)(shader + 4) = 1;
  *(undefined4 *)(shader + 0x18) = 0;
  newBuffer = (**(code **)(ctx + 0xc))((uint)*(ushort *)(((unsigned char *)0x0000114c) + ctx) * 0x4c,shader);
  *(undefined4 *)(shader + 0x10) = newBuffer;
  newBuffer = (**(code **)(ctx + 0xc))((uint)(byte)((unsigned char *)0x00001150)[ctx] << 2);
  *(undefined4 *)(shader + 0x24) = 0;
  *(undefined4 *)(shader + 0x14) = newBuffer;
  newBuffer = (**(code **)(ctx + 0xc))((uint)*(ushort *)(((unsigned char *)0x0000114c) + ctx) * 0x4c);
  *(undefined4 *)(shader + 0x1c) = newBuffer;
  newBuffer = (**(code **)(ctx + 0xc))((uint)(byte)((unsigned char *)0x00001150)[ctx] << 2);
  *(undefined4 *)(shader + 0x20) = newBuffer;
  maxPasses = 0;
  if (((unsigned char *)0x00001150)[ctx] != '\0') {
    loopIndex = 0;
    do {
      passByteOffset = loopIndex * 4;
      loopIndex = loopIndex + 1;
      *(undefined4 *)(*(int *)(shader + 0x14) + passByteOffset) = 0;
      *(undefined4 *)(*(int *)(shader + 0x20) + passByteOffset) = 0;
      maxPasses = (uint)(byte)((unsigned char *)0x00001150)[ctx];
    } while (loopIndex < (int)maxPasses);
  }
  newBuffer = (**(code **)(ctx + 0xc))(*(ushort *)(((unsigned char *)0x00001148) + ctx) * maxPasses * 0xc);
  *(undefined4 *)(shader + 0xc) = newBuffer;
  maxPasses = (uint)(byte)((unsigned char *)0x00001150)[ctx];
  if (maxPasses != 0) {
    regsPerPass = (uint)*(ushort *)(((unsigned char *)0x00001148) + ctx);
    loopIndex = 0;
    do {
      loopIndex2 = 0;
      if (regsPerPass != 0) {
        do {
          defaultCoordSource = loopIndex2 + 0x84c0;
          entryOffset = loopIndex2 + loopIndex * regsPerPass;
          loopIndex2 = loopIndex2 + 1;
          entryOffset = entryOffset * 0xc;
          *(undefined1 *)(*(int *)(shader + 0xc) + entryOffset) = 0;
          *(undefined1 *)(entryOffset + *(int *)(shader + 0xc) + 1) = 1;
          *(int *)(entryOffset + *(int *)(shader + 0xc) + 8) = defaultCoordSource;
          regsPerPass = (uint)*(ushort *)(((unsigned char *)0x00001148) + ctx);
        } while (loopIndex2 < (int)regsPerPass);
        maxPasses = (uint)(byte)((unsigned char *)0x00001150)[ctx];
        regsPerPass = (uint)*(ushort *)(((unsigned char *)0x00001148) + ctx);
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < (int)maxPasses);
  }
  newBuffer = (**(code **)(ctx + 0xc))((uint)*(ushort *)(((unsigned char *)0x0000114a) + ctx) * 0x14);
  *(undefined4 *)(shader + 0x28) = newBuffer;
  if (*(short *)(((unsigned char *)0x0000114a) + ctx) != 0) {
    loopIndex = 0;
    constantOffset = 0;
    do {
      loopIndex = loopIndex + 1;
      *(undefined1 *)(*(int *)(shader + 0x28) + constantOffset) = 0;
      *(undefined4 *)(*(int *)(shader + 0x28) + constantOffset + 4) = 0x3f800000;
      *(undefined4 *)(*(int *)(shader + 0x28) + constantOffset + 8) = 0x3f800000;
      *(undefined4 *)(*(int *)(shader + 0x28) + constantOffset + 0xc) = 0x3f800000;
      constantRecord = *(int *)(shader + 0x28) + constantOffset;
      constantOffset = constantOffset + 0x14;
      *(undefined4 *)(constantRecord + 0x10) = 0x3f800000;
    } while (loopIndex < (int)(uint)*(ushort *)(((unsigned char *)0x0000114a) + ctx));
  }
  newBuffer = (**(code **)(ctx + 0x10))(*(undefined4 *)(*(int *)(((unsigned char *)0x00001154) + ctx) + 0x8c),4)
  ;
  *(undefined4 *)(shader + 0x70) = newBuffer;
  return ((int (*)())atifsSetShaderValid)(shader,1);
}

/* atifsFreeShader @ 0xa2bb0 (400 bytes) */
int atifsFreeShader(ctx, shader)
  int ctx;
  int shader;
{
  int programTable;
  int shaderTable;
  uint loopIndex;
  
  if (*(int *)(shader + 0x10) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(shader + 0x10));
    *(undefined4 *)(shader + 0x10) = 0;
  }
  if (*(int *)(shader + 0x14) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(shader + 0x14));
    *(undefined4 *)(shader + 0x14) = 0;
  }
  if (*(int *)(shader + 0x1c) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(shader + 0x1c));
    *(undefined4 *)(shader + 0x1c) = 0;
  }
  if (*(int *)(shader + 0x20) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(shader + 0x20));
    *(undefined4 *)(shader + 0x20) = 0;
  }
  if (*(int *)(shader + 0xc) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(shader + 0xc));
    *(undefined4 *)(shader + 0xc) = 0;
  }
  if (*(int *)(shader + 0x28) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(shader + 0x28));
    *(undefined4 *)(shader + 0x28) = 0;
  }
  programTable = *(int *)(shader + 0x70);
  if (programTable != 0) {
    shaderTable = *(int *)(((unsigned char *)0x00001154) + ctx);
    loopIndex = 0;
    if (*(int *)(shaderTable + 0x8c) != 0) {
      do {
        if (*(int *)(loopIndex * 4 + programTable) != 0) {
          *(undefined4 *)(loopIndex * 4 + programTable) = 0;
          (**(code **)(((unsigned char *)0x00001158) + ctx))(ctx);
          programTable = *(int *)(shader + 0x70);
          shaderTable = *(int *)(((unsigned char *)0x00001154) + ctx);
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < *(uint *)(shaderTable + 0x8c));
    }
    (**(code **)(ctx + 0x18))(programTable);
    *(undefined4 *)(shader + 0x70) = 0;
  }
  return;
}

/* atifsAddTextureOp @ 0xa2d60 (276 bytes) */
int atifsAddTextureOp(ctx, shader, passIndex, dst, coordSource, isSampleMap, swizzle)
  int ctx;
  int shader;
  int passIndex;
  int dst;
  int coordSource;
  undefined4 isSampleMap;
  int swizzle;
{
  int entriesLeft;
  int entryOffset;
  char *entry;
  char *scan;
  
  scan = *(char **)(shader + 0xc);
  entryOffset = ((uint)*(ushort *)(((unsigned char *)0x00001148) + ctx) * passIndex + dst + -0x8921) * 0xc;
  entry = scan + entryOffset;
  if (scan[entryOffset] != '\0') {
    return 0;
  }
  entriesLeft = (uint)*(ushort *)(((unsigned char *)0x00001148) + ctx) * (uint)(byte)((unsigned char *)0x00001150)[ctx];
  do {
    if (entriesLeft == 0) {
      *entry = '\x01';
      *(undefined1 *)(entryOffset + *(int *)(shader + 0xc) + 1) = (undefined1)isSampleMap;
      *(int *)(entryOffset + *(int *)(shader + 0xc) + 8) = coordSource;
      *(int *)(entryOffset + *(int *)(shader + 0xc) + 4) = swizzle;
      return 1;
    }
    if ((*scan != '\0') && (*(int *)(scan + 8) == coordSource)) {
      if ((swizzle == 0x8976) || (swizzle == 0x8978)) {
        if (*(int *)(scan + 4) == 0x8977) {
          return 0;
        }
        if (*(int *)(scan + 4) == 0x8979) {
          return 0;
        }
      }
      else {
        if (*(int *)(scan + 4) == 0x8976) {
          return 0;
        }
        if (*(int *)(scan + 4) == 0x8978) {
          return 0;
        }
      }
    }
    scan = scan + 0xc;
    entriesLeft = entriesLeft + -1;
  } while( true );
}

/* atifsAddColorOp @ 0xa2e90 (708 bytes) */
int atifsAddColorOp(ctx, shader, passIndex, op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod)
  int ctx;
  int shader;
  int passIndex;
  int op;
  int dst;
  uint dstMask;
  uint dstMod;
  int arg1;
  int arg1Rep;
  undefined4 arg1Mod;
  int arg2;
  int arg2Rep;
  undefined4 arg2Mod;
  int arg3;
  int arg3Rep;
  undefined4 arg3Mod;
{
  int deadCopyArg4;
  int packOk;
  int arg3PackOk;
  undefined1 *recordArg3Alias;
  int colorOpsInPass;
  undefined1 alphaOpsInPassScratch [4];
  int recordOp;
  int recordDst;
  uint recordDstMask;
  uint recordDstMod;
  undefined4 recordReserved;
  undefined1 recordArg1 [16];
  undefined1 recordArg2 [16];
  undefined1 recordArg3 [16];
  int recordOrdinal;
  int recordPass;
  
  ((int (*)())atifsCountPassOps)(((unsigned char *)0x00001134U) + ctx,shader,&colorOpsInPass,alphaOpsInPassScratch);
  if (((((passIndex < (int)(uint)(byte)((unsigned char *)0x00001150)[ctx]) &&
        (colorOpsInPass < (int)(uint)*(ushort *)(((unsigned char *)0x0000114e) + ctx))) && (op - 0x8961U < 0xc))
      && (((1 << (op - 0x8961U & 0x3f) & 0xffdU) != 0 &&
          (recordOp = op,
          packOk = ((int (*)())atifsPackArgument)(ctx,shader,arg1,arg1Rep,arg1Mod,recordArg1), packOk != 0))))
     && (packOk = ((int (*)())atifsPackArgument)(ctx,shader,arg2,arg2Rep,arg2Mod,recordArg2), packOk != 0)) {
    recordArg3Alias = recordArg3;
    deadCopyArg4 = arg3Rep;
    arg3PackOk = ((int (*)())atifsPackArgument)(ctx,shader,arg3,arg3Rep,arg3Mod,recordArg3Alias);
    if ((((arg3PackOk != 0) && (dst - 0x8921U < 6)) &&
        ((((7 < arg1 - 0x8941U ||
           (((7 < arg2 - 0x8941U || (7 < arg3 - 0x8941U)) || (arg1 == arg2)))) ||
          ((arg1 == arg3 || (arg2 == arg3)))) &&
         (((dstMod & 0xffffffbf & (dstMod & 0xffffffbf) - 1) == 0 &&
          ((((arg1 != 0x896d || (arg1Rep != 0x1906)) &&
            ((arg2 != 0x896d || (arg2Rep != 0x1906)))) &&
           ((arg3 != 0x896d || (arg3Rep != 0x1906)))))))))) &&
       ((op != 0x8967 ||
        (((arg1 != 0x896d || ((arg1Rep != 0 && (arg1Rep != 0x1906)))) &&
         ((arg2 != 0x896d || ((arg2Rep != 0 && (arg2Rep != 0x1906)))))))))) {
      if (7 < dstMask) {
        return 0;
      }
      recordOrdinal = *(int *)(shader + 8);
      *(int *)(shader + 8) = recordOrdinal + 1;
      recordReserved = 0;
      recordDst = dst;
      recordDstMask = dstMask;
      recordDstMod = dstMod;
      recordPass = passIndex;
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (*(int *)(shader + 0x18) * 0x4c + *(int *)(shader + 0x10),&recordOp,0x4c,deadCopyArg4,
                 arg3Mod,recordArg3Alias,*(int *)(shader + 0x10));
      *(int *)(passIndex * 4 + *(int *)(shader + 0x14)) =
           *(int *)(passIndex * 4 + *(int *)(shader + 0x14)) + 1;
      *(int *)(shader + 0x18) = *(int *)(shader + 0x18) + 1;
      return 1;
    }
  }
  ((int (*)())atifsSetShaderValid)(shader,0);
  return 0;
}

/* atifsAddAlphaOp @ 0xa3160 (804 bytes) */
int atifsAddAlphaOp(ctx, shader, passIndex, op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod)
  int ctx;
  int shader;
  int passIndex;
  int op;
  int dst;
  uint dstMod;
  int arg1;
  int arg1Rep;
  undefined4 arg1Mod;
  int arg2;
  int arg2Rep;
  undefined4 arg2Mod;
  int arg3;
  int arg3Rep;
  undefined4 arg3Mod;
{
  int prevColorOpRecord;
  int deadCopyArg4;
  int packOk;
  int arg3PackOk;
  undefined1 *recordArg3Alias;
  undefined1 colorOpsInPassScratch [4];
  int alphaOpsInPass;
  int recordOp;
  int recordDst;
  undefined4 recordDstMask;
  uint recordDstMod;
  undefined4 recordReserved;
  undefined1 recordArg1 [16];
  undefined1 recordArg2 [16];
  undefined1 recordArg3 [16];
  int recordOrdinal;
  int recordPass;
  
  ((int (*)())atifsCountPassOps)(((unsigned char *)0x00001134U) + ctx,shader,colorOpsInPassScratch,&alphaOpsInPass);
  if (((((passIndex < (int)(uint)(byte)((unsigned char *)0x00001150)[ctx]) &&
        (alphaOpsInPass < (int)(uint)*(ushort *)(((unsigned char *)0x0000114e) + ctx))) && (op - 0x8961U < 0xc))
      && (((1 << (op - 0x8961U & 0x3f) & 0xffdU) != 0 &&
          (recordOp = op,
          packOk = ((int (*)())atifsPackArgument)(ctx,shader,arg1,arg1Rep,arg1Mod,recordArg1), packOk != 0))))
     && (packOk = ((int (*)())atifsPackArgument)(ctx,shader,arg2,arg2Rep,arg2Mod,recordArg2), packOk != 0)) {
    recordArg3Alias = recordArg3;
    deadCopyArg4 = arg3Rep;
    arg3PackOk = ((int (*)())atifsPackArgument)(ctx,shader,arg3,arg3Rep,arg3Mod,recordArg3Alias);
    if (((((((arg3PackOk != 0) && (dst - 0x8921U < 6)) &&
           ((((7 < arg1 - 0x8941U ||
              (((7 < arg2 - 0x8941U || (7 < arg3 - 0x8941U)) || (arg1 == arg2)))) ||
             ((arg1 == arg3 || (arg2 == arg3)))) &&
            ((dstMod & 0xffffffbf & (dstMod & 0xffffffbf) - 1) == 0)))) &&
          (((1 < op - 0x8966U && (op != 0x896c)) ||
           ((0 < *(int *)(shader + 0x18) &&
            (((prevColorOpRecord = *(int *)(shader + 0x18) * 0x4c + *(int *)(shader + 0x10),
              *(int *)(prevColorOpRecord + -8) == *(int *)(shader + 8) + -1 &&
              (passIndex == *(int *)(prevColorOpRecord + -4))) && (op == *(int *)(prevColorOpRecord + -0x4c))))))))) &&
         (((op == 0x8967 || (*(int *)(shader + 0x18) < 2)) ||
          ((prevColorOpRecord = *(int *)(shader + 0x18) * 0x4c + *(int *)(shader + 0x10),
           *(int *)(prevColorOpRecord + -8) != *(int *)(shader + 8) + -1 ||
           ((passIndex != *(int *)(prevColorOpRecord + -4) || (*(int *)(prevColorOpRecord + -0x4c) != 0x8967)))))))) &&
        (((arg1 != 0x896d || ((arg1Rep != 0 && (arg1Rep != 0x1906)))) &&
         ((arg2 != 0x896d || ((arg2Rep != 0 && (arg2Rep != 0x1906)))))))) &&
       ((arg3 != 0x896d || ((arg3Rep != 0 && (arg3Rep != 0x1906)))))) {
      recordOrdinal = *(int *)(shader + 8);
      *(int *)(shader + 8) = recordOrdinal + 1;
      recordReserved = 0;
      recordDstMask = 0;
      recordDst = dst;
      recordDstMod = dstMod;
      recordPass = passIndex;
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (*(int *)(shader + 0x24) * 0x4c + *(int *)(shader + 0x1c),&recordOp,0x4c,deadCopyArg4,
                 arg3Mod,recordArg3Alias,*(int *)(shader + 0x1c));
      *(int *)(passIndex * 4 + *(int *)(shader + 0x20)) =
           *(int *)(passIndex * 4 + *(int *)(shader + 0x20)) + 1;
      *(int *)(shader + 0x24) = *(int *)(shader + 0x24) + 1;
      return 1;
    }
  }
  ((int (*)())atifsSetShaderValid)(shader,0);
  return 0;
}

/* atifsSetConstant @ 0xa3490 (196 bytes) */
int atifsSetConstant(ctx, shader, dst, value, inShader)
  int ctx;
  int shader;
  int dst;
  undefined4 *value;
  int inShader;
{
  int constIndex;
  int slot;
  
  constIndex = dst + -0x8941;
  if ((-1 < constIndex) && (constIndex < (int)(uint)*(ushort *)(((unsigned char *)0x0000114a) + ctx))) {
    if (inShader != 0) {
      constIndex = constIndex * 0x14;
      *(undefined1 *)(*(int *)(shader + 0x28) + constIndex) = 1;
      *(undefined4 *)(constIndex + *(int *)(shader + 0x28) + 4) = *value;
      *(undefined4 *)(constIndex + *(int *)(shader + 0x28) + 8) = value[1];
      *(undefined4 *)(constIndex + *(int *)(shader + 0x28) + 0xc) = value[2];
      *(undefined4 *)(constIndex + *(int *)(shader + 0x28) + 0x10) = value[3];
      return 1;
    }
    slot = *(int *)(*(int *)(((unsigned char *)0x00001154) + ctx) + 0xc);
    *(undefined1 *)(constIndex * 0x14 + slot) = 1;
    slot = constIndex * 0x14 + slot;
    *(undefined4 *)(slot + 4) = *value;
    *(undefined4 *)(slot + 8) = value[1];
    *(undefined4 *)(slot + 0xc) = value[2];
    *(undefined4 *)(slot + 0x10) = value[3];
    return 1;
  }
  return 0;
}

/* gld_quantizePointSizeInt @ 0xa3560 (164 bytes) */
uint gld_quantizePointSizeInt(int glContext,double fpPassThrough1)
{
  uint quantizedSize;
  
  quantizedSize = *(uint *)(((unsigned char *)0x000013e0) + glContext);
  if ((double)(float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x000013e0) + glContext) ^ 0x80000000) -
                     DOUBLE_001aa1e0) < fpPassThrough1) {
    quantizedSize = *(uint *)(((unsigned char *)0x000013e4) + glContext);
    if (fpPassThrough1 <
        (double)(float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x000013e4) + glContext) ^ 0x80000000)
                       - DOUBLE_001aa1e0)) {
      quantizedSize = (uint)(int)(fpPassThrough1 + (double)FLOAT_001aa10c);
    }
  }
  return quantizedSize;
}

/* gld_roundUpToPowerOfTwo @ 0xa3610 (88 bytes) */
int gld_roundUpToPowerOfTwo(glContext, value, unusedArgR5, unusedArgR6, unusedArgR7, unusedArgR8, unusedArgR9)
  int glContext;
  uint value;
  undefined4 unusedArgR5;
  undefined4 unusedArgR6;
  undefined4 unusedArgR7;
  undefined4 unusedArgR8;
  undefined4 unusedArgR9;
{
  uint powerOfTwo;
  int bitsLeft;
  uint glContextByte13b7;
  
  glContextByte13b7 = (uint)(byte)((unsigned char *)0x000013b7)[glContext];
  powerOfTwo = 1 << (glContextByte13b7 & 0x3f);
  if ((value & powerOfTwo) == 0) {
    bitsLeft = glContextByte13b7 + 1;
    do {
      glContextByte13b7 = glContextByte13b7 - 1;
      bitsLeft = bitsLeft + -1;
      if (bitsLeft == 0) {
        powerOfTwo = 1 << (glContextByte13b7 & 0x3f);
        break;
      }
      powerOfTwo = 1 << (glContextByte13b7 & 0x3f);
    } while ((value & powerOfTwo) == 0);
  }
  if ((int)value <= (int)powerOfTwo) {
    return powerOfTwo;
  }
  return powerOfTwo << 1;
}

/* gld_isPointAttenuationActive @ 0xa3670 (48 bytes) */
int gld_isPointAttenuationActive(glContext)
  int glContext;
{
  uint attenuationBit;
  
  if ((*(uint *)(glContext + 0x44) & 0x100000) == 0) {
    attenuationBit = *(uint *)(glContext + 0xe8) & 1;
  }
  else {
    attenuationBit = *(uint *)(glContext + 0x44) & 0x80;
  }
  if (attenuationBit == 0) {
    return 0;
  }
  return 1;
}

/* gld_scalePointSizeToPixels @ 0xa36b0 (212 bytes) */
int gld_scalePointSizeToPixels(glContext, addSizeBias)
  int glContext;
  int addSizeBias;
{
  float sizeBias;
  
  if (addSizeBias != 0) {
    sizeBias = FLOAT_001aa0e8;
    if (*(short *)(((unsigned char *)0x00002e0e) + *(int *)(*(int *)(glContext + 4) + 0x10)) == 0x1102) {
      sizeBias = FLOAT_001aa108;
    }
    return (int)((float)((double)CONCAT44(0x43300000,*(undefined4 *)(glContext + 8)) - DOUBLE_001aa250
                        ) * FLOAT_001aa10c * (sizeBias + *(float *)(glContext + 0xe0)));
  }
  return (int)((float)((double)CONCAT44(0x43300000,*(undefined4 *)(glContext + 8)) - DOUBLE_001aa250)
               * FLOAT_001aa10c * *(float *)(glContext + 0xe0));
}

/* gld_buildCoverageByteTable @ 0xa3790 (716 bytes) */
void gld_buildCoverageByteTable(undefined4 glContext,undefined4 unusedArgR4,uint tableSize,int outTable,int *outCount,double fpPassThrough1,double fpPassThrough2,double fpPassThrough3,double fpPassThrough4,double fpPassThrough5,double fpPassThrough6,double fpPassThrough7,double fpPassThrough8,double fpPassThrough9,double fpPassThrough10,double fpPassThrough11,double fpPassThrough12)
{
  double samplePosF2;
  double sampleIndexF2;
  double coverageSum;
  double tableSizeF;
  double sampleWeight;
  uint loopIndex3;
  float coverageValue;
  uint loopIndex2;
  int halfSize;
  int loopIndex;
  double clampedSizeF;
  double clampScratch;
  double filterWidthF;
  double oneF;
  double sampleIndexF;
  double samplePosF;
  char outByte;
  
  clampedSizeF = (double)FLOAT_001aa0e8;
  if (clampedSizeF <= fpPassThrough1) {
    clampedSizeF = (double)(float)((double)CONCAT44(0x43300000,(int)fpPassThrough1 ^ 0x80000000) -
                           DOUBLE_001aa1e0);
  }
  loopIndex = 0;
  oneF = (double)FLOAT_001aa0e8;
  halfSize = ((int)tableSize >> 1) + (uint)((int)tableSize < 0 && (tableSize & 1) != 0);
  clampScratch = oneF;
  if ((float)(fpPassThrough1 - oneF) < 0.0) {
    clampScratch = fpPassThrough1;
  }
  if (-(float)(fpPassThrough1 - oneF) < 0.0) {
    fpPassThrough1 = clampScratch;
  }
  tableSizeF = (double)(float)((double)CONCAT44(0x43300000,tableSize ^ 0x80000000) - DOUBLE_001aa1e0);
  filterWidthF = (double)(float)((double)CONCAT44(0x43300000,
                                           (int)(tableSizeF / (double)(float)(clampedSizeF + (double)
                                                  FLOAT_001aa108)) ^ 0x80000000) - DOUBLE_001aa1e0);
  sampleWeight = (double)(float)(fpPassThrough1 *
                         (double)(float)(oneF / (double)(float)(filterWidthF * (double)(float)(filterWidthF - 
                                                  oneF))));
  if (0 < halfSize) {
    do {
      coverageSum = (double)FLOAT_001aa0d4;
      if (filterWidthF <= coverageSum) {
loopSetCoverageValue:
        coverageValue = (float)(coverageSum * (double)FLOAT_001aa0f0);
      }
      else {
        loopIndex2 = 0;
        sampleIndexF = coverageSum;
        do {
          samplePosF = (double)(float)((double)CONCAT44(0x43300000,
                                                    (int)((double)(float)((double)CONCAT44(
                                                  0x43300000,loopIndex2 + loopIndex ^ 0x80000000) -
                                                  DOUBLE_001aa1e0) - filterWidthF) ^ 0x80000000) -
                                  DOUBLE_001aa1e0);
          if ((filterWidthF <= samplePosF) && (samplePosF < (double)(float)(tableSizeF - filterWidthF))) {
            coverageSum = (double)(float)(sampleWeight * sampleIndexF + coverageSum);
          }
          loopIndex2 = loopIndex2 + 1;
          sampleIndexF = (double)(float)((double)CONCAT44(0x43300000,loopIndex2 ^ 0x80000000) - DOUBLE_001aa1e0)
          ;
        } while (sampleIndexF < filterWidthF);
        loopIndex3 = 0;
        sampleIndexF2 = (double)FLOAT_001aa0d4;
        do {
          samplePosF2 = (double)(float)((double)CONCAT44(0x43300000,loopIndex3 + loopIndex ^ 0x80000000) -
                                  DOUBLE_001aa1e0);
          if ((filterWidthF <= samplePosF2) && (samplePosF2 < (double)(float)(tableSizeF - filterWidthF))) {
            coverageSum = (double)(float)(sampleWeight * (double)((float)(filterWidthF - sampleIndexF2) - FLOAT_001aa0e8) +
                                   coverageSum);
          }
          loopIndex3 = loopIndex3 + 1;
          sampleIndexF2 = (double)(float)((double)CONCAT44(0x43300000,loopIndex3 ^ 0x80000000) - DOUBLE_001aa1e0)
          ;
        } while (sampleIndexF2 < filterWidthF);
        coverageValue = FLOAT_001aa0f0;
        if (coverageSum <= (double)FLOAT_001aa0e8) goto loopSetCoverageValue;
      }
      outByte = (char)(int)(coverageValue + FLOAT_001aa10c);
      *(char *)(loopIndex + outTable) = outByte;
    } while ((outByte != -1) && (loopIndex = loopIndex + 1, halfSize != loopIndex));
  }
  *outCount = loopIndex;
  return;
}

/* gld_buildCoverageRampTable @ 0xa3a60 (372 bytes) */
void gld_buildCoverageRampTable(undefined4 glContext,undefined4 unusedArgR4,uint tableSize,int outTable,uint *outCount,double fpPassThrough1,double fpPassThrough2,double fpPassThrough3,double fpPassThrough4,double fpPassThrough5,double fpPassThrough6,double fpPassThrough7,double fpPassThrough8,double fpPassThrough9,double fpPassThrough10,double fpPassThrough11,double fpPassThrough12,double fpPassThrough13)
{
  float rampLengthF;
  float rampPosF;
  float rampStep;
  float halfF;
  double intConvBias;
  uint loopIndex;
  double clampedSizeF;
  double oneF;
  double clampScratch;
  
  intConvBias = DOUBLE_001aa1e0;
  halfF = FLOAT_001aa10c;
  clampedSizeF = (double)FLOAT_001aa0e8;
  if (clampedSizeF <= fpPassThrough1) {
    clampedSizeF = (double)(float)((double)CONCAT44(0x43300000,(int)fpPassThrough1 ^ 0x80000000) -
                           DOUBLE_001aa1e0);
  }
  oneF = (double)FLOAT_001aa0e8;
  loopIndex = 0;
  clampScratch = oneF;
  if ((float)(fpPassThrough1 - oneF) < 0.0) {
    clampScratch = fpPassThrough1;
  }
  if (-(float)(fpPassThrough1 - oneF) < 0.0) {
    fpPassThrough1 = clampScratch;
  }
  rampLengthF = (float)((double)CONCAT44(0x43300000,
                                   (int)(((float)((double)CONCAT44(0x43300000,tableSize ^ 0x80000000)
                                                 - DOUBLE_001aa1e0) * FLOAT_001aa10c) /
                                        (float)(clampedSizeF + oneF)) ^ 0x80000000) - DOUBLE_001aa1e0);
  rampLengthF = rampLengthF + rampLengthF;
  rampStep = FLOAT_001aa0f0 / rampLengthF;
  rampPosF = FLOAT_001aa0d4;
  while (rampPosF < rampLengthF) {
    *(char *)(outTable + loopIndex) = (char)(int)((float)(fpPassThrough1 * (double)rampStep) * rampPosF + halfF);
    loopIndex = loopIndex + 1;
    rampPosF = (float)((double)CONCAT44(0x43300000,loopIndex ^ 0x80000000) - intConvBias);
  }
  if ((int)loopIndex < (int)(((int)tableSize >> 1) + (uint)((int)tableSize < 0 && (tableSize & 1) != 0))) {
    *(undefined1 *)(loopIndex + outTable) = 0xff;
  }
  *outCount = loopIndex;
  return;
}

/* gld_setPrimitiveInputRegisters @ 0xa3be0 (2056 bytes) */
int gld_setPrimitiveInputRegisters(glContext, primitiveMode, unitCounter, unusedArgR6, tableCursor, extraArg5, staleArgR9)
  uint glContext;
  int primitiveMode;
  uint unitCounter;
  undefined4 unusedArgR6;
  uint tableCursor;
  undefined4 *extraArg5;
  undefined4 staleArgR9;
{
  uint ctxCursorC;
  undefined4 *packetD;
  undefined4 *ctxWordPtrB;
  undefined4 *packetC;
  undefined4 *packetB;
  undefined4 *ctxWordPtrA;
  uint ctxCursorB;
  uint registerCount;
  uint ctxCursorA;
  int streamWritePtrB;
  int streamWritePtr;
  int unitWordCursor;
  int regBaseNextB;
  int regBaseSignedC;
  int unitWordAddrB;
  int regBaseSignedB;
  int unitWordAddr;
  int regBaseNext;
  uint loopIndex9;
  uint loopIndex8;
  uint loopIndex7;
  uint loopIndex6;
  uint loopIndex5;
  int remaining2;
  int remaining;
  int loopIndex3;
  uint glContextPtr13b2;
  uint glContextWordec;
  uint glContextWord44;
  uint glContextWord1ba4;
  undefined4 glContextWord1b68;
  undefined4 glContextWord1b64;
  undefined4 glContextWord1a64;
  undefined4 glContextWord1ba0;
  undefined4 glContextWord1b50;
  uint loopIndex2;
  int loopIndex;
  bool noPrimitiveTable;
  bool bit29Clear;
  byte unitEnableMask;
  uint regField;
  code *UNRECOVERED_JUMPTABLE;
  uint primitiveFlags;
  undefined4 *writePtr;
  uint fieldShift;
  undefined4 *packetA;
  uint bitShift;
  uint baseSelectBits;
  int unitWordAddrA;
  int regBaseSignedD;
  undefined4 glContextWord1f2c;
  uint primitiveTableWord;
  uint loopIndex4;
  int regBaseSigned;
  
  if (*(int *)(glContext + 0x277c) == primitiveMode) {
    return;
  }
  *(int *)(glContext + 0x277c) = primitiveMode;
  noPrimitiveTable = *(int *)(glContext + 0x2768) == 0;
  baseSelectBits = (uint)*(ushort *)(glContext + 0x1b52);
  *(uint *)(glContext + 0x1b50) = baseSelectBits;
  if (noPrimitiveTable) {
    if ((*(uint *)(glContext + 0x44) & 0x20000000) == 0) {
      return;
    }
  }
  else if ((primitiveMode != 0) || ((*(uint *)(glContext + 0x44) & 0x20000000) == 0)) {
    *(uint *)(glContext + 0x1b50) = baseSelectBits;
    tableCursor = primitiveMode * 4 + *(int *)(glContext + 0x2768);
    primitiveTableWord = *(uint *)(&primitiveInputRegisterTable_001aa7a8 + primitiveMode * 4);
    *(uint *)(glContext + 0x1b50) =
         baseSelectBits | *(int *)(tableCursor + 0xe8) << (*(int *)(glContext + 0x276c) * 2 + 0x10U & 0x3f);
    primitiveFlags = *(uint *)(tableCursor + 0x110);
    *(uint *)(glContext + 0x1b64) = primitiveTableWord & 3 | *(uint *)(glContext + 0x1b64) & 0xfffffffc;
    *(undefined4 *)(glContext + 0x1b68) = 0;
    extraArg5 = (undefined4 *)(primitiveFlags & 0x10 | *(uint *)(glContext + 0x1a64) & 0xffffffef);
    *(undefined4 **)(glContext + 0x1a64) = extraArg5;
    gldSetProgramStreamMode(glContext,*(undefined4 *)(tableCursor + 0xc0));
  }
  *(undefined4 *)(glContext + 0x1ba8) = *(undefined4 *)(glContext + 0x1ba0);
  if (!noPrimitiveTable) goto setPacketB;
  if ((*(uint *)(glContext + 0x44) & 0x100000) == 0) {
    ffvpComputeOutputMasks(glContext);
  }
  else {
    gldCopyRouteRegisters(glContext);
  }
  (**(code **)(((unsigned char *)0x00001334) + glContext))(glContext,1);
  glContextWord44 = *(uint *)(glContext + 0x44);
  glContextWord1ba4 = *(uint *)(glContext + 0x1ba4);
  *(uint *)(glContext + 0x1ba0) = glContextWord1ba4;
  bit29Clear = (glContextWord44 >> 0x1d & 1) == 0;
  *(uint *)(glContext + 0x1a64) = *(uint *)(glContext + 0x1a64) & 0xffffffef;
  if ((bit29Clear) || ((*(uint *)(glContext + 0x8c) & 0x40000000) != 0)) {
    if ((glContextWord44 & 0x40000000) == 0) {
      *(uint *)(glContext + 0x1b50) = (uint)*(ushort *)(glContext + 0x1b52);
    }
    else if ((!bit29Clear) && ((*(uint *)(glContext + 0x8c) & 0x40000000) != 0)) {
      *(undefined4 *)(glContext + 0x1bc0) = 0;
      *(uint *)(glContext + 0x1b50) = (uint)*(ushort *)(glContext + 0x1b52);
    }
  }
  else {
    if (primitiveMode == 0) {
      if ((glContextWord44 & 0x20000) == 0) {
        if (((unsigned char *)0x000013b2)[glContext] == '\0') goto loopSetRegisterCount;
        baseSelectBits = 0;
        unitCounter = 0;
        loopIndex4 = 0;
        loopIndex6 = 0x10;
        loopIndex8 = 0;
        ctxCursorA = glContext;
        do {
          if ((((*(uint *)(ctxCursorA + 0x48) & 0x1f) == 0) ||
              ((1 << (unitCounter & 0x3f) & *(uint *)(glContext + 0xec)) == 0)) ||
             (*(int *)(((unsigned char *)0x000013f8) + ctxCursorA) == 0)) {
            regBaseSigned = (int)(char)baseSelectBits;
            unitWordAddrA = unitCounter * 4 + glContext;
            tableCursor = regBaseSigned + 2;
            *(uint *)(unitWordAddrA + 0x1ee8) =
                 (regBaseSigned + 3) * 0x40000 & 0xfc0000U |
                 tableCursor * 0x1000 & 0x3f000 |
                 (regBaseSigned + 1) * 0x40 & 0xfc0U |
                 baseSelectBits & 0x3f | *(uint *)(unitWordAddrA + 0x1ee8) & 0xff000000;
            *(uint *)(glContext + 0x1b50) = *(uint *)(glContext + 0x1b50) & ~(1 << (loopIndex6 & 0x3f));
            *(uint *)(glContext + 0x1bc0) = *(uint *)(glContext + 0x1bc0) & ~(1 << (loopIndex8 & 0x3f));
            baseSelectBits = baseSelectBits + (*(uint *)(glContext + 0x1ba0) >> (loopIndex4 & 0x3f) & 7);
          }
          else {
            regBaseNext = baseSelectBits + 1;
            *(uint *)(glContext + 0x1a64) = *(uint *)(glContext + 0x1a64) | 0x10;
            *(uint *)(glContext + 0x1b50) = 1 << (loopIndex6 & 0x3f) | *(uint *)(glContext + 0x1b50);
            *(uint *)(glContext + 0x1bc0) = 1 << (loopIndex8 & 0x3f) | *(uint *)(glContext + 0x1bc0);
            unitWordAddrB = unitCounter * 4 + glContext;
            glContextWord1ba4 = glContextWord1ba4 & ~(7 << (loopIndex4 & 0x3f));
            regField = baseSelectBits & 0x3f;
            baseSelectBits = baseSelectBits + 2;
            *(uint *)(unitWordAddrB + 0x1ee8) =
                 regBaseNext * 0x40 & 0xfc0U | regField | *(uint *)(unitWordAddrB + 0x1ee8) & 0xff000000 | 0xffe000
            ;
          }
          unitCounter = unitCounter + 1;
          ctxCursorA = ctxCursorA + 4;
          loopIndex4 = loopIndex4 + 3;
          loopIndex6 = loopIndex6 + 2;
          loopIndex8 = loopIndex8 + 2;
        } while ((int)unitCounter < (int)(uint)(byte)((unsigned char *)0x000013b2)[glContext]);
      }
      else {
        if ((glContextWord44 & 0x2000) == 0) {
          unitEnableMask = ((unsigned char *)0x00001135)[glContext];
        }
        else {
          unitEnableMask = ((unsigned char *)0x000011d3)[glContext];
        }
        glContextWordec = *(uint *)(glContext + 0xec);
        if (((unsigned char *)0x000013b2)[glContext] == '\0') {
loopSetRegisterCount:
          registerCount = 0;
          goto storeGlContext;
        }
        baseSelectBits = 0;
        unitCounter = 0;
        loopIndex5 = 0;
        loopIndex7 = 0x10;
        loopIndex9 = 0;
        tableCursor = glContext + 0x1ee0;
        do {
          if (((unitEnableMask & glContextWordec) >> (unitCounter & 0x3f) & 1) == 0) {
            regBaseSignedC = (int)(char)baseSelectBits;
            *(uint *)(tableCursor + 8) =
                 (regBaseSignedC + 3) * 0x40000 & 0xfc0000U |
                 (regBaseSignedC + 2) * 0x1000 & 0x3f000U |
                 (regBaseSignedC + 1) * 0x40 & 0xfc0U | baseSelectBits & 0x3f | *(uint *)(tableCursor + 8) & 0xff000000;
            *(uint *)(glContext + 0x1b50) = *(uint *)(glContext + 0x1b50) & ~(1 << (loopIndex7 & 0x3f));
            *(uint *)(glContext + 0x1bc0) = *(uint *)(glContext + 0x1bc0) & ~(1 << (loopIndex9 & 0x3f));
            baseSelectBits = baseSelectBits + (*(uint *)(glContext + 0x1ba0) >> (loopIndex5 & 0x3f) & 7);
          }
          else {
            *(uint *)(glContext + 0x1a64) = *(uint *)(glContext + 0x1a64) | 0x10;
            *(uint *)(glContext + 0x1b50) = 1 << (loopIndex7 & 0x3f) | *(uint *)(glContext + 0x1b50);
            regBaseNextB = baseSelectBits + 1;
            *(uint *)(glContext + 0x1bc0) = 1 << (loopIndex9 & 0x3f) | *(uint *)(glContext + 0x1bc0);
            glContextWord1ba4 = glContextWord1ba4 & ~(7 << (loopIndex5 & 0x3f));
            regField = baseSelectBits & 0x3f;
            baseSelectBits = baseSelectBits + 2;
            *(uint *)(tableCursor + 8) =
                 regBaseNextB * 0x40 & 0xfc0U | regField | *(uint *)(tableCursor + 8) & 0xff000000 | 0xffe000;
          }
          unitCounter = unitCounter + 1;
          tableCursor = tableCursor + 4;
          loopIndex5 = loopIndex5 + 3;
          loopIndex7 = loopIndex7 + 2;
          loopIndex9 = loopIndex9 + 2;
        } while ((int)unitCounter < (int)(uint)(byte)((unsigned char *)0x000013b2)[glContext]);
      }
      registerCount = baseSelectBits & 0xff;
    }
    else {
      if (*(int *)(glContext + 0x2768) != 0) goto loopSetRegisterCount;
      if ((glContextWord44 & 0x20000) == 0) {
        glContextPtr13b2 = (uint)(byte)((unsigned char *)0x000013b2)[glContext];
        if (glContextPtr13b2 == 0) goto setBaseSelectBits;
        baseSelectBits = 0;
        loopIndex = 0;
        tableCursor = glContext;
        do {
          if (((*(uint *)(tableCursor + 0x48) & 0x1f) != 0) && (*(int *)(((unsigned char *)0x000013f8) + tableCursor) != 0))
          {
            regBaseSignedD = (int)(char)baseSelectBits;
            unitWordAddr = loopIndex * 4 + glContext;
            *(uint *)(unitWordAddr + 0x1ee8) =
                 (regBaseSignedD + 3) * 0x40000 & 0xfc0000U |
                 (regBaseSignedD + 2) * 0x1000 & 0x3f000U |
                 (regBaseSignedD + 1) * 0x40 & 0xfc0U |
                 baseSelectBits & 0x3f | *(uint *)(unitWordAddr + 0x1ee8) & 0xff000000;
            glContextPtr13b2 = (uint)(byte)((unsigned char *)0x000013b2)[glContext];
          }
          fieldShift = loopIndex * 3;
          loopIndex = loopIndex + 1;
          tableCursor = tableCursor + 4;
          baseSelectBits = baseSelectBits + (*(uint *)(glContext + 0x1ba0) >> (fieldShift & 0x3f) & 7);
        } while (loopIndex < (int)glContextPtr13b2);
      }
      else {
        if ((glContextWord44 & 0x2000) == 0) {
          unitEnableMask = ((unsigned char *)0x00001135)[glContext];
        }
        else {
          unitEnableMask = ((unsigned char *)0x000011d3)[glContext];
        }
        unitCounter = (uint)unitEnableMask;
        glContextPtr13b2 = (uint)(byte)((unsigned char *)0x000013b2)[glContext];
        if (glContextPtr13b2 == 0) {
setBaseSelectBits:
          baseSelectBits = 0;
        }
        else {
          baseSelectBits = 0;
          loopIndex2 = 0;
          tableCursor = 0;
          unitWordCursor = glContext + 0x1ee0;
          do {
            if ((unitEnableMask >> (loopIndex2 & 0x3f) & 1) != 0) {
              regBaseSignedB = (int)(char)baseSelectBits;
              *(uint *)(unitWordCursor + 8) =
                   (regBaseSignedB + 3) * 0x40000 & 0xfc0000U |
                   (regBaseSignedB + 2) * 0x1000 & 0x3f000U |
                   (regBaseSignedB + 1) * 0x40 & 0xfc0U | baseSelectBits & 0x3f | *(uint *)(unitWordCursor + 8) & 0xff000000
              ;
              glContextPtr13b2 = (uint)(byte)((unsigned char *)0x000013b2)[glContext];
            }
            loopIndex2 = loopIndex2 + 1;
            unitWordCursor = unitWordCursor + 4;
            bitShift = tableCursor & 0x3f;
            tableCursor = tableCursor + 3;
            baseSelectBits = baseSelectBits + (*(uint *)(glContext + 0x1ba0) >> bitShift & 7);
          } while ((int)loopIndex2 < (int)glContextPtr13b2);
        }
      }
      registerCount = baseSelectBits & 0xff;
      *(undefined4 *)(glContext + 0x1bc0) = 0;
      *(uint *)(glContext + 0x1b50) = (uint)*(ushort *)(glContext + 0x1b52);
    }
storeGlContext:
    *(uint *)(glContext + 0x1f2c) = registerCount & 0x7f | *(uint *)(glContext + 0x1f2c) & 0xffffff80;
    packetA = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,0xd);
    *(undefined4 **)(0x00002748 + glContext + 4) = packetA;
    extraArg5 = packetA + 5;
    loopIndex3 = 0;
    *packetA = ((unsigned char *)0x000010c0U);
    remaining2 = 8;
    glContextWord1f2c = *(undefined4 *)(glContext + 0x1f2c);
    packetA[2] = 0x825;
    packetA[1] = glContextWord1f2c;
    packetA[3] = *(undefined4 *)(glContext + 0x1ba0);
    packetA[4] = *(uint *)(glContext + 0x1f28) | 0x70000;
    ctxCursorB = glContext;
    do {
      ctxWordPtrA = (undefined4 *)(ctxCursorB + 0x1ee8);
      ctxCursorB = ctxCursorB + 4;
      *(undefined4 *)((int)extraArg5 + loopIndex3) = *ctxWordPtrA;
      loopIndex3 = loopIndex3 + 4;
      remaining2 = remaining2 + -1;
    } while (remaining2 != 0);
    streamWritePtr = *(int *)(0x00002748 + glContext + 4);
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x275c);
    *(int *)(0x00002748 + glContext + 4) = streamWritePtr + 0x34;
    (*UNRECOVERED_JUMPTABLE)(glContext,streamWritePtr + 0x34);
  }
  *(uint *)(glContext + 0x1ba8) = glContextWord1ba4;
setPacketB:
  packetB = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,0xc);
  *(undefined4 **)(0x00002748 + glContext + 4) = packetB;
  *packetB = ((unsigned char *)0x00001002U);
  glContextWord1b50 = *(undefined4 *)(glContext + 0x1b50);
  packetB[2] = 0x825;
  packetB[1] = glContextWord1b50;
  glContextWord1ba0 = *(undefined4 *)(glContext + 0x1ba0);
  packetB[4] = ((unsigned char *)0x00001007U);
  packetB[3] = glContextWord1ba0;
  glContextWord1a64 = *(undefined4 *)(glContext + 0x1a64);
  packetB[6] = ((unsigned char *)0x0000108eU);
  packetB[5] = glContextWord1a64;
  glContextWord1b64 = *(undefined4 *)(glContext + 0x1b64);
  packetB[8] = ((unsigned char *)0x00001098U);
  packetB[7] = glContextWord1b64;
  glContextWord1b68 = *(undefined4 *)(glContext + 0x1b68);
  packetB[10] = ((unsigned char *)0x000010c0U);
  packetB[9] = glContextWord1b68;
  packetB[0xb] = *(undefined4 *)(glContext + 0x1f2c);
  streamWritePtrB = *(int *)(0x00002748 + glContext + 4);
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x275c);
  *(int *)(0x00002748 + glContext + 4) = streamWritePtrB + 0x30;
  (*UNRECOVERED_JUMPTABLE)(glContext,streamWritePtrB + 0x30,unitCounter,baseSelectBits,tableCursor,extraArg5,glContextWord1b68);
  if (*(char *)(glContext + 0x1868) != '\0') {
    packetC = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,9);
    *packetC = 0x7101d;
    *(undefined4 **)(0x00002748 + glContext + 4) = packetC + 1;
    remaining = 8;
    ctxCursorC = glContext;
    do {
      writePtr = *(undefined4 **)(0x00002748 + glContext + 4);
      ctxWordPtrB = (undefined4 *)(ctxCursorC + 0x1ee8);
      ctxCursorC = ctxCursorC + 4;
      *writePtr = *ctxWordPtrB;
      *(undefined4 **)(0x00002748 + glContext + 4) = writePtr + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
    /* dropped 2nd arg, same defect class as gld_startPacket (issue #64) - stock stores the
     * just-advanced pointer to +0x274c then loads it right back into r4 before the bctr
     * tail-jump. */
    (**(code **)(glContext + 0x275c))(glContext,writePtr + 1);
  }
  if (noPrimitiveTable) {
    (**(code **)(((unsigned char *)0x00001330) + glContext))(glContext,0xc0100000);
  }
  if (*(int *)(glContext + 0x1ba8) == *(int *)(glContext + 0x1ba0)) {
    return;
  }
  packetD = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,2);
  *(undefined4 **)(0x00002748 + glContext + 4) = packetD;
  *packetD = ((unsigned char *)0x00001001U);
  *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 4) = *(undefined4 *)(glContext + 0x1ba8);
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x275c);
  *(int *)(0x00002748 + glContext + 4) = *(int *)(0x00002748 + glContext + 4) + 8;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(glContext,*(int *)(0x00002748 + glContext + 4));
  return;
}

/* gld_freePointMaskCache @ 0xa43f0 (148 bytes) */
int gld_freePointMaskCache(glContext)
  int glContext;
{
  int cacheEntry;
  int nextEntry;
  
  cacheEntry = *(int *)(glContext + 0x2764);
  while (cacheEntry != 0) {
    if (*(int *)(cacheEntry + 0xbc) != 0) {
      gld_deleteTextureForStream(glContext,*(undefined4 *)(*(int *)(cacheEntry + 0xbc) + 0x7c));
    }
    nextEntry = *(int *)(cacheEntry + 0x138);
    (**(code **)(glContext + 0x18))(cacheEntry);
    cacheEntry = nextEntry;
  }
  *(undefined4 *)(glContext + 0x2778) = 0;
  *(undefined4 *)(glContext + 0x2764) = 0;
  *(undefined4 *)(glContext + 0x2768) = 0;
  return;
}

/* gld_invalidateCachedPointMasks @ 0xa4490 (184 bytes) */
int gld_invalidateCachedPointMasks(glContext)
  int glContext;
{
  int glContextPtr2764;
  
  for (glContextPtr2764 = *(int *)(glContext + 0x2764); glContextPtr2764 != 0; glContextPtr2764 = *(int *)(glContextPtr2764 + 0x138)) {
    if ((*(int *)(glContextPtr2764 + 0xbc) != 0) && (-1 < *(int *)(glContext + 0x276c))) {
      gld_bindUnitObject(glContext,0,*(int *)(glContext + 0x276c));
    }
  }
  *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x200;
  *(ushort *)(glContext + 0x32) =
       (ushort)(1 << (*(uint *)(glContext + 0x276c) & 0x3f)) | *(ushort *)(glContext + 0x32);
  *(ushort *)(glContext + 0x34) =
       (ushort)(1 << (*(uint *)(glContext + 0x276c) & 0x3f)) | *(ushort *)(glContext + 0x34);
  return;
}

/* gld_markBoundObjectsDirty @ 0xa4550 (372 bytes) */
int gld_markBoundObjectsDirty(glContext)
  int glContext;
{
  int shaderSlotRecord;
  int boundSlotRecord;
  int loopIndex3;
  int glContextPtr112c;
  uint objectCount;
  int entryRecord;
  uint loopIndex;
  int loopIndex2;
  int glContextPtr1154;
  
  glContextPtr1154 = *(int *)(((unsigned char *)0x00001154) + glContext);
  objectCount = *(uint *)(glContextPtr1154 + 4);
  if (objectCount != 0) {
    loopIndex = 0;
    loopIndex2 = 0;
    do {
      shaderSlotRecord = *(int *)(*(int *)(((unsigned char *)0x0000113c) + glContext) * 4 +
                      *(int *)(loopIndex2 + *(int *)(glContextPtr1154 + 0x88) + 0x70));
      if (shaderSlotRecord != 0) {
        *(undefined4 *)(((unsigned char *)0x000015cc) + shaderSlotRecord) = 1;
        objectCount = *(uint *)(glContextPtr1154 + 4);
      }
      loopIndex = loopIndex + 1;
      loopIndex2 = loopIndex2 + 0x78;
    } while (loopIndex < objectCount);
  }
  glContextPtr112c = *(int *)(((unsigned char *)0x0000112c) + glContext);
  objectCount = *(uint *)(glContextPtr112c + 4);
  if (objectCount != 0) {
    loopIndex = 0;
    loopIndex3 = 0;
    do {
      entryRecord = loopIndex3 + *(int *)(glContextPtr112c + 8);
      if ((*(int *)(entryRecord + 4) == 0x8804) &&
         (boundSlotRecord = *(int *)(*(int *)(((unsigned char *)0x00001130) + glContext) * 4 +
                          *(int *)(*(int *)(entryRecord + 0x14) + 0x70)), boundSlotRecord != 0)) {
        *(undefined4 *)(((unsigned char *)0x000015cc) + boundSlotRecord) = 1;
        objectCount = *(uint *)(glContextPtr112c + 4);
      }
      loopIndex = loopIndex + 1;
      loopIndex3 = loopIndex3 + 0x18;
    } while (loopIndex < objectCount);
  }
  gldSetProgramStreamMode(glContext,0);
  *(uint *)(glContext + 0x1b50) = (uint)*(ushort *)(glContext + 0x1b52);
  *(uint *)(glContext + 0x1a64) = *(uint *)(glContext + 0x1a64) & 0xffffffef;
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x2000;
  ((int (*)())gld_invalidateCachedPointMasks)(glContext);
  *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x200;
  *(undefined1 *)(glContext + 0x29) = 1;
  *(ushort *)(glContext + 0x34) =
       (ushort)(1 << (*(uint *)(glContext + 0x276c) & 0x3f)) | *(ushort *)(glContext + 0x34);
  *(undefined4 *)(glContext + 0x276c) = 0xffffffff;
  *(undefined4 *)(glContext + 0x2768) = 0;
  return;
}

/* gld_refreshActivePointMask @ 0xa46d0 (144 bytes) */
int gld_refreshActivePointMask(glContext)
  int glContext;
{
  if (*(int *)(glContext + 0x2768) != 0) {
    gld_bindUnitObject(glContext,*(undefined4 *)(*(int *)(*(int *)(glContext + 0x2768) + 0xbc) + 0x7c),
                 *(undefined4 *)(glContext + 0x276c));
    *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x200;
    *(ushort *)(glContext + 0x32) =
         (ushort)(1 << (*(uint *)(glContext + 0x276c) & 0x3f)) | *(ushort *)(glContext + 0x32);
    *(ushort *)(glContext + 0x34) =
         (ushort)(1 << (*(uint *)(glContext + 0x276c) & 0x3f)) | *(ushort *)(glContext + 0x34);
  }
  return 1;
}

/* gld_getActiveSampleIndex @ 0xa4760 (8 bytes) */
int gld_getActiveSampleIndex(ctx)
  int ctx;
{
  return *(undefined4 *)(ctx + 0x29ac);
}

/* gld_computePointSizePixels @ 0xa4770 (504 bytes) */
int gld_computePointSizePixels(glContext, unusedArgR4, staleArgR5, staleArgR6, staleArgR7, staleArgR8, staleArgR9)
  int glContext;
  undefined4 unusedArgR4;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  undefined4 staleArgR9;
{
  float quantizedSize;
  float pointSizeClamped;
  float pointSizeRequestedF;
  float glContextFloat13e8;
  float pointSizeRequested;
  float modeScale;
  uint pixelSize;
  int glContextPtr4;
  int glContextWord8;
  int engineCaps;
  
  glContextPtr4 = *(int *)(glContext + 4);
  glContextWord8 = *(int *)(glContext + 8);
  engineCaps = *(int *)(glContextPtr4 + 0x10);
  if (((((unsigned char *)0x00002e2d)[engineCaps] == '\0') || ((*(uint *)(glContext + 0x44) & 0x20000) != 0)) ||
     (glContextPtr4 = gld_needsMultisampleResolve(glContextPtr4,*(undefined4 *)(glContextPtr4 + 0x26a0),staleArgR5,staleArgR6,staleArgR7,staleArgR8,
                           staleArgR9), glContextPtr4 != 0)) {
    pixelSize = *(uint *)(((unsigned char *)0x000013e0) + glContext);
    pointSizeRequested = *(float *)(((unsigned char *)0x00002e20) + engineCaps);
    if (((float)((double)CONCAT44(0x43300000,pixelSize ^ 0x80000000) - DOUBLE_001aa1e0) < pointSizeRequested) &&
       (pixelSize = *(uint *)(((unsigned char *)0x000013e4) + glContext),
       pointSizeRequested < (float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x000013e4) + glContext) ^ 0x80000000)
                      - DOUBLE_001aa1e0))) {
      pixelSize = (uint)(int)(pointSizeRequested + FLOAT_001aa10c);
    }
    pixelSize = glContextWord8 * pixelSize >> 1;
  }
  else {
    pointSizeRequestedF = *(float *)(((unsigned char *)0x00002e20) + engineCaps);
    glContextFloat13e8 = *(float *)(((unsigned char *)0x000013e8) + glContext);
    quantizedSize = glContextFloat13e8;
    if ((glContextFloat13e8 < pointSizeRequestedF) &&
       (quantizedSize = *(float *)(((unsigned char *)0x000013ec) + glContext), pointSizeRequestedF < *(float *)(((unsigned char *)0x000013ec) + glContext))) {
      quantizedSize = *(float *)(((unsigned char *)0x000013f0) + glContext) *
              (float)((double)CONCAT44(0x43300000,
                                       (int)((pointSizeRequestedF - glContextFloat13e8) / *(float *)(((unsigned char *)0x000013f0) + glContext) +
                                            FLOAT_001aa10c) ^ 0x80000000) - DOUBLE_001aa1e0) + glContextFloat13e8
      ;
    }
    pointSizeClamped = quantizedSize;
    if (quantizedSize - FLOAT_001aa0e8 < 0.0) {
      pointSizeClamped = FLOAT_001aa0e8;
    }
    if (-(quantizedSize - FLOAT_001aa0e8) < 0.0) {
      pointSizeClamped = quantizedSize;
    }
    modeScale = FLOAT_001aa0e8;
    if (*(short *)(((unsigned char *)0x00002e10) + engineCaps) == 0x1102) {
      modeScale = FLOAT_001aa108;
    }
    pixelSize = (uint)(int)((float)((double)CONCAT44(0x43300000,glContextWord8) - DOUBLE_001aa250) * FLOAT_001aa10c *
                  (pointSizeClamped + modeScale));
  }
  return pixelSize;
}

/* gld_buildSmoothPointMask @ 0xa4980 (4768 bytes) */
int gld_buildSmoothPointMask(glContext, unusedArgR4, staleArgR5, staleArgR6, staleArgR7)
  int glContext;
  undefined4 unusedArgR4;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
{
  undefined4 maskLevelWordb4;
  uint loopIndex7;
  uint loopIndex6;
  uint loopIndex5;
  int loopIndex4;
  int loopIndex3;
  int loopIndex2;
  int loopIndex;
  float entryWord4X4F;
  uint entryWord4X4;
  uint entryWord4X2;
  uint flagBits114;
  uint flagBits120;
  uint levelFormat;
  double quantizedValue;
  undefined1 stippleByte;
  float rowCoord2;
  float rowCoord;
  float firstCoord;
  bool notLastPatternCol;
  bool notLastBlock;
  int patternCol;
  int rowsThisBlock;
  int blockRows;
  int blocksLeft;
  int rowsEnd;
  int rampIndex;
  int maskLevel;
  int uploadResult;
  int pixelCursor;
  int maskTexture;
  int rampBuffer;
  uint lastRowPtr;
  undefined4 cacheEntryWordf8;
  uint cacheEntryWordb8;
  uint cacheEntryWordb0;
  undefined4 cacheEntryWordd0;
  int cacheEntryPtrbc;
  int cacheEntryWord18;
  float engineState2Float2e20;
  float engineStateFloat2e20;
  int engineState4;
  uint engineState3;
  int engineState2;
  int engineState;
  uint glContextByte13b2;
  uint glContextWord38;
  uint glContextPtr276c;
  uint glContextWord44;
  int glContextPtr4_5;
  int glContextPtr4_4;
  int glContextPtr4_3;
  int glContextPtr4_2;
  int glContextPtr4;
  float glContextFloat13e8_3;
  float glContextFloat13e8_2;
  bool maskIsHardEdged;
  char glContextByte245b;
  undefined1 *mirrorSrc;
  float entryWord4X2F;
  float innerLimitSq;
  short engineStateShort2e0e;
  short engineStateShort2e10;
  short engineStateShort2e28;
  ushort engineStateShort3172;
  ushort engineStateShort3170;
  float quantizedPointSize;
  float colCoord;
  float colCoord2;
  char sizeAttenuated;
  undefined1 maskValue;
  uint stateDirtyBits;
  uint maskFieldValue;
  uint rampAllocHigh;
  uint allocResultLow;
  uint pointModeBits;
  uint lastActiveUnit;
  uint *unitWordCursor;
  int memcmpResult;
  int minLevelBytes;
  undefined2 maxSizeShort;
  int fillCol;
  undefined4 calleeResultLow;
  uint r4AfterCall;
  undefined4 r4AfterCall2;
  undefined4 r4AfterCall3;
  uint r4AfterCall4;
  uint r4AfterCall5;
  char *negPointMode;
  char *zeroValue;
  int *entryWord14High;
  undefined4 staleArgR8;
  char *dirtyUnitMask;
  char *oneValue;
  uint levelCount;
  uint levelCountClamped;
  undefined4 entryFlag15;
  undefined1 *mirrorDst;
  undefined4 textureFlags;
  uint sizeBytes;
  char sizeClamped;
  char fillPolygonMode;
  uint maskHeight;
  uint ctxStateWord;
  uint maskPitch;
  uint maskWidth;
  int maskPitchCopy;
  undefined4 glContextWord4;
  int levelBytes;
  int maskPitchShift;
  int maskLevelBytes;
  char *cacheEntry;
  int channelCount;
  int pointSizePixelsB;
  int engineCapsB;
  int smoothLevelBytes;
  int allocPairHigh;
  int pointSizePixelsA;
  int levelRows;
  uint colsLeft;
  double engineFloat2e20;
  double contextFloatArg;
  double glContextFloat13e8;
  double staleArgF2;
  double staleArgF3;
  double staleArgF4;
  double staleArgF5;
  double staleArgF6;
  double staleArgF7;
  double staleArgF8;
  undefined8 callResultPair;
  undefined8 callResultPair2;
  ulonglong rampAllocPair;
  float distSq;
  double staleStackArg_fffffeb8;
  double staleStackArg_fffffec0;
  double staleStackArg_fffffec8;
  double staleStackArg_fffffed0;
  double staleStackArg_fffffed8;
  int rampCountWords [4];
  longlong fctiwzSlot0;
  undefined4 i2dHi1;
  uint i2dLo1;
  longlong fctiwzSlot1;
  undefined4 i2dHi2;
  uint i2dLo2;
  undefined4 i2dHi3;
  uint i2dLo3;
  undefined4 i2dHi4;
  uint i2dLo4;
  longlong fctiwzSlot2;
  undefined4 i2dHi5;
  uint i2dLo5;
  undefined4 i2dHi6;
  uint i2dLo6;
  undefined4 i2dHi7;
  uint i2dLo7;
  longlong fctiwzSlot4;
  undefined4 i2dHi9;
  uint i2dLo9;
  longlong fctiwzSlot3;
  undefined4 i2dHi8;
  uint i2dLo8;
  undefined4 i2dHi11;
  uint i2dLo11;
  undefined4 i2dHi10;
  uint i2dLo10;
  
  glContextWord44 = *(uint *)(glContext + 0x44);
  if ((glContextWord44 & 0x60020000) != 0x40000000) {
    glContextPtr4_2 = *(int *)(glContext + 4);
    if ((((unsigned char *)0x00002e2d)[*(int *)(glContextPtr4_2 + 0x10)] != '\0') && ((glContextWord44 & 0x20000) == 0)) {
      glContextPtr4_2 = gld_needsMultisampleResolve(glContextPtr4_2,*(undefined4 *)(glContextPtr4_2 + 0x26a0),staleArgR5,staleArgR6,staleArgR7,staleArgR8,
                            glContextWord44);
      if (glContextPtr4_2 == 0) goto setGlContextPtr276c;
      glContextPtr4_2 = *(int *)(glContext + 4);
    }
    glContextPtr4_2 = *(int *)(glContextPtr4_2 + 0x10);
    if ((((((unsigned char *)0x00002e2c)[glContextPtr4_2] == '\0') || ((*(uint *)(glContext + 0x44) & 0x20000) != 0)) ||
        (*(short *)(((unsigned char *)0x00002e28) + glContextPtr4_2) == -1)) &&
       (((((unsigned char *)0x00003178)[glContextPtr4_2] == '\0' || ((*(uint *)(glContext + 0x44) & 0x20000) != 0)) ||
        ((*(short *)(((unsigned char *)0x00003170) + glContextPtr4_2) != 0x1b02 &&
         (*(short *)(((unsigned char *)0x00003172) + glContextPtr4_2) != 0x1b02)))))) {
      if (*(int *)(glContext + 0x2768) == 0) {
        return 0;
      }
      ((int (*)())gld_markBoundObjectsDirty)(glContext);
      return 0;
    }
  }
setGlContextPtr276c:
  glContextPtr276c = *(uint *)(glContext + 0x276c);
  glContextWord38 = *(uint *)(glContext + 0x38);
  if (-1 < (int)glContextPtr276c) {
    stateDirtyBits = glContextWord38 & 0x10310e | (int)(uint)*(ushort *)(glContext + 0x34) >> (glContextPtr276c & 0x3f) & 1U;
  }
  else {
    stateDirtyBits = 1;
  }
  if (stateDirtyBits == 0 && *(int *)(glContext + 0x2458) == 0) {
    return 0;
  }
  glContextByte13b2 = (uint)(byte)((unsigned char *)0x000013b2)[glContext];
  lastActiveUnit = glContextByte13b2 - 1;
  if (-1 < (int)lastActiveUnit) {
    unitWordCursor = (uint *)(lastActiveUnit * 4 + glContext + 0x48);
    do {
      if ((((*unitWordCursor & 0x1f) == 0) || (unitWordCursor[0x4ec] == 0)) &&
         ((ctxStateWord = *(uint *)(glContext + 0x44), (ctxStateWord & 0x2000) == 0 ||
          (((((int)(uint)(byte)((unsigned char *)0x000011d3)[glContext] >> (lastActiveUnit & 0x3f) & 1U) == 0 &&
            (((ctxStateWord & 0x800) == 0 || ((byte)((unsigned char *)0x000011d1)[glContext] != lastActiveUnit)))) &&
           (((ctxStateWord & 0x400) == 0 || ((byte)((unsigned char *)0x000011d2)[glContext] != lastActiveUnit)))))))) break;
      lastActiveUnit = lastActiveUnit - 1;
      unitWordCursor = unitWordCursor + -1;
      glContextByte13b2 = glContextByte13b2 - 1;
    } while (glContextByte13b2 != 0);
  }
  if (-1 < (int)glContextPtr276c) {
    dirtyUnitMask = (char *)(1 << (glContextPtr276c & 0x3f));
  }
  else {
    dirtyUnitMask = (char *)0x0;
  }
  if (-1 < (int)lastActiveUnit) {
    dirtyUnitMask = (char *)((uint)dirtyUnitMask | 1 << (lastActiveUnit & 0x3f));
  }
  if (dirtyUnitMask != (char *)0x0) {
    glContextWord38 = glContextWord38 | 0x200;
    *(uint *)(glContext + 0x38) = glContextWord38;
    *(ushort *)(glContext + 0x32) = (ushort)dirtyUnitMask | *(ushort *)(glContext + 0x32);
    *(ushort *)(glContext + 0x34) = (ushort)dirtyUnitMask | *(ushort *)(glContext + 0x34);
  }
  *(uint *)(glContext + 0x276c) = lastActiveUnit;
  if ((int)lastActiveUnit < 0) goto callGldMarkBoundObjectsDirty;
  glContextPtr4_3 = *(int *)(glContext + 4);
  glContextByte245b = *(char *)(glContext + 0x245b);
  engineState = *(int *)(glContextPtr4_3 + 0x10);
  pointModeBits = *(uint *)(glContext + 0x44) & 0x60020000 ^ 0x40000000;
  negPointMode = (char *)-pointModeBits;
  glContextPtr4_3 = gld_needsMultisampleResolve(glContextPtr4_3,*(undefined4 *)(glContextPtr4_3 + 0x26a0),staleArgR5,staleArgR6,negPointMode,dirtyUnitMask,
                        glContextWord38);
  callResultPair = ((int (*)())gld_scalePointSizeToPixels)(glContext,(uint)(glContextPtr4_3 == 0));
  calleeResultLow = (undefined4)callResultPair;
  glContextPtr4_4 = *(int *)(glContext + 4);
  engineStateShort2e0e = *(short *)(((unsigned char *)0x00002e0e) + engineState);
  engineState3 = *(uint *)(glContextPtr4_4 + 0x10);
  if ((((unsigned char *)0x00002e2d)[engineState3] == '\0') || ((*(uint *)(glContext + 0x44) & 0x20000) != 0)) {
loopSetSizeAttenuated:
    sizeAttenuated = '\0';
  }
  else {
    callResultPair2 = gld_needsMultisampleResolve(glContextPtr4_4,*(undefined4 *)(glContextPtr4_4 + 0x26a0),staleArgR5,staleArgR6,negPointMode,dirtyUnitMask,
                          engineState3);
    calleeResultLow = (undefined4)callResultPair2;
    if ((int)((ulonglong)callResultPair2 >> 0x20) != 0) {
      glContextPtr4_4 = *(int *)(glContext + 4);
      goto loopSetSizeAttenuated;
    }
    glContextPtr4_4 = *(int *)(glContext + 4);
    sizeAttenuated = '\x01';
  }
  if (((((unsigned char *)0x00002e2c)[*(int *)(glContextPtr4_4 + 0x10)] == '\0') ||
      ((*(uint *)(glContext + 0x44) & 0x20000) != 0)) ||
     (sizeClamped = '\x01', *(short *)(((unsigned char *)0x00002e28) + *(int *)(glContextPtr4_4 + 0x10)) == -1)) {
    sizeClamped = '\0';
  }
  pointSizePixelsB = ((int (*)())gld_computePointSizePixels)(glContext,calleeResultLow,staleArgR5,staleArgR6,negPointMode,dirtyUnitMask,engineState3);
  engineStateFloat2e20 = *(float *)(((unsigned char *)0x00002e20) + engineState);
  glContextFloat13e8_2 = *(float *)(((unsigned char *)0x000013e8) + glContext);
  engineStateShort2e10 = *(short *)(((unsigned char *)0x00002e10) + engineState);
  quantizedPointSize = glContextFloat13e8_2;
  if ((glContextFloat13e8_2 < engineStateFloat2e20) &&
     (quantizedPointSize = *(float *)(((unsigned char *)0x000013ec) + glContext), engineStateFloat2e20 < *(float *)(((unsigned char *)0x000013ec) + glContext))) {
    negPointMode = "ram[";
    dirtyUnitMask = "ram[";
    i2dHi1 = 0x43300000;
    i2dLo1 = (uint)(int)((engineStateFloat2e20 - glContextFloat13e8_2) / *(float *)(((unsigned char *)0x000013f0) + glContext) + 0.5);
    fctiwzSlot0 = (longlong)(int)i2dLo1;
    i2dLo1 = i2dLo1 ^ 0x80000000;
    quantizedPointSize = *(float *)(((unsigned char *)0x000013f0) + glContext) *
             (float)((double)CONCAT44(0x43300000,i2dLo1) - 4503601774854144.0) + glContextFloat13e8_2;
  }
  glContextPtr4_5 = *(int *)(glContext + 4);
  engineStateShort2e28 = *(short *)(((unsigned char *)0x00002e28) + engineState);
  engineState4 = *(int *)(glContextPtr4_5 + 0x10);
  if (((((unsigned char *)0x00003178)[engineState4] == '\0') ||
      (engineState3 = *(uint *)(glContext + 0x44) & 0x20000, engineState3 != 0)) ||
     ((*(short *)(((unsigned char *)0x00003170) + engineState4) != 0x1b02 &&
      (*(short *)(((unsigned char *)0x00003172) + engineState4) != 0x1b02)))) {
    fillPolygonMode = '\0';
  }
  else {
    fillPolygonMode = '\x01';
  }
  engineStateShort3172 = *(ushort *)(((unsigned char *)0x00003172) + engineState);
  engineStateShort3170 = *(ushort *)(((unsigned char *)0x00003170) + engineState);
  if (glContextByte245b != '\0') {
    sizeClamped = '\x01';
    fillPolygonMode = '\x01';
  }
  cacheEntry = *(char **)(glContext + 0x2764);
  if (cacheEntry != (char *)0x0) {
    do {
      if ((((bool)*cacheEntry == (pointModeBits == 0)) &&
          (((pointModeBits != 0 ||
            ((((uint)(byte)cacheEntry[1] == (uint)(glContextPtr4_3 == 0) &&
              ((int)((ulonglong)callResultPair >> 0x20) == *(int *)(cacheEntry + 4))) &&
             ((engineStateShort2e0e == 0x1102) == (bool)cacheEntry[8])))) &&
           ((cacheEntry[0x14] == sizeAttenuated && (cacheEntry[0x15] == sizeClamped)))))) &&
         (((sizeAttenuated == '\0' && (sizeClamped == '\0')) ||
          ((((pointSizePixelsB == *(int *)(cacheEntry + 0x18) && ((engineStateShort2e10 == 0x1102) == (bool)cacheEntry[0x1c])) &&
            ((sizeAttenuated == '\0' ||
             ((2.0 <= *(float *)(cacheEntry + 0x20) || (quantizedPointSize == *(float *)(cacheEntry + 0x20))))))) &&
           ((sizeClamped == '\0' || (*(short *)(cacheEntry + 0x28) == engineStateShort2e28)))))))) {
        if ((uint)engineStateShort3170 == *(uint *)(cacheEntry + 0xb4)) {
          cacheEntryWordb8 = *(uint *)(cacheEntry + 0xb8);
          if (engineStateShort3172 != cacheEntryWordb8) goto checkEngineStateShort3170;
        }
        else {
          cacheEntryWordb8 = *(uint *)(cacheEntry + 0xb8);
checkEngineStateShort3170:
          if ((engineStateShort3170 != cacheEntryWordb8) || ((uint)engineStateShort3172 != *(uint *)(cacheEntry + 0xb4))) goto setCacheEntry;
        }
        if (cacheEntry[0x2a] == fillPolygonMode) {
          if (fillPolygonMode == '\0') goto storeGlContext;
          staleArgR5 = 0x80;
          memcmpResult = _memcmp(cacheEntry + 0x2c,((unsigned char *)0x000030e8) + engineState,0x80);
          if (memcmpResult == 0) goto storeGlContext;
        }
      }
setCacheEntry:
      cacheEntry = *(char **)(cacheEntry + 0x138);
    } while (cacheEntry != (char *)0x0);
  }
  if (*(int *)(glContext + 0x2778) == 0x100) {
    ((int (*)())gld_freePointMaskCache)(glContext);
    glContextPtr4_5 = *(int *)(glContext + 4);
  }
  engineState2 = *(int *)(glContextPtr4_5 + 0x10);
  glContextByte245b = *(char *)(glContext + 0x245b);
  cacheEntry = (char *)(**(code **)(glContext + 0x10))(1,0x13c);
  if (cacheEntry == (char *)0x0) goto callGldMarkBoundObjectsDirty;
  *cacheEntry = (*(uint *)(glContext + 0x44) & 0x60020000) == 0x40000000;
  callResultPair = gld_needsMultisampleResolve(*(int *)(glContext + 4),*(undefined4 *)(*(int *)(glContext + 4) + 0x26a0),
                        staleArgR5,staleArgR6,negPointMode,dirtyUnitMask,engineState3);
  calleeResultLow = (undefined4)callResultPair;
  cacheEntry[1] = (int)((ulonglong)callResultPair >> 0x20) == 0;
  cacheEntry[8] = *(short *)(((unsigned char *)0x00002e0e) + engineState2) == 0x1102;
  glContextPtr4 = *(int *)(glContext + 4);
  if ((((unsigned char *)0x00002e2d)[*(int *)(glContextPtr4 + 0x10)] == '\0') ||
     (negPointMode = (char *)(*(uint *)(glContext + 0x44) & 0x20000), negPointMode != (char *)0x0)) {
loopSetSizeAttenuated2:
    sizeAttenuated = '\0';
  }
  else {
    callResultPair = gld_needsMultisampleResolve(glContextPtr4,*(undefined4 *)(glContextPtr4 + 0x26a0),staleArgR5,staleArgR6,0,dirtyUnitMask,engineState3);
    calleeResultLow = (undefined4)callResultPair;
    sizeAttenuated = '\x01';
    if ((int)((ulonglong)callResultPair >> 0x20) != 0) goto loopSetSizeAttenuated2;
  }
  cacheEntry[0x14] = sizeAttenuated;
  cacheEntry[0x1c] = *(short *)(((unsigned char *)0x00002e10) + engineState2) == 0x1102;
  engineState2Float2e20 = *(float *)(((unsigned char *)0x00002e20) + engineState2);
  glContextFloat13e8_3 = *(float *)(((unsigned char *)0x000013e8) + glContext);
  quantizedPointSize = glContextFloat13e8_3;
  if ((glContextFloat13e8_3 < engineState2Float2e20) &&
     (quantizedPointSize = *(float *)(((unsigned char *)0x000013ec) + glContext), engineState2Float2e20 < *(float *)(((unsigned char *)0x000013ec) + glContext))) {
    negPointMode = "ram[";
    dirtyUnitMask = "ram[";
    i2dHi2 = 0x43300000;
    i2dLo2 = (uint)(int)((engineState2Float2e20 - glContextFloat13e8_3) / *(float *)(((unsigned char *)0x000013f0) + glContext) + 0.5);
    fctiwzSlot1 = (longlong)(int)i2dLo2;
    i2dLo2 = i2dLo2 ^ 0x80000000;
    quantizedPointSize = *(float *)(((unsigned char *)0x000013f0) + glContext) *
             (float)((double)CONCAT44(0x43300000,i2dLo2) - 4503601774854144.0) + glContextFloat13e8_3;
  }
  *(float *)(cacheEntry + 0x20) = quantizedPointSize;
  engineState = *(int *)(*(int *)(glContext + 4) + 0x10);
  if (((((unsigned char *)0x00002e2c)[engineState] == '\0') || ((*(uint *)(glContext + 0x44) & 0x20000) != 0)) ||
     (entryFlag15 = 1, *(short *)(((unsigned char *)0x00002e28) + engineState) == -1)) {
    entryFlag15 = 0;
  }
  cacheEntry[0x15] = (char)entryFlag15;
  engineState = *(int *)(*(int *)(glContext + 4) + 0x10);
  if (((((unsigned char *)0x00003178)[engineState] == '\0') || ((*(uint *)(glContext + 0x44) & 0x20000) != 0)) ||
     ((*(short *)(((unsigned char *)0x00003170) + engineState) != 0x1b02 &&
      (*(short *)(((unsigned char *)0x00003172) + engineState) != 0x1b02)))) {
    sizeAttenuated = '\0';
  }
  else {
    sizeAttenuated = '\x01';
  }
  cacheEntry[0x2a] = sizeAttenuated;
  *(uint *)(cacheEntry + 0xb4) = (uint)*(ushort *)(((unsigned char *)0x00003170) + engineState2);
  *(uint *)(cacheEntry + 0xb8) = (uint)*(ushort *)(((unsigned char *)0x00003172) + engineState2);
  if (glContextByte245b != '\0') {
    cacheEntry[0x2a] = '\x01';
    cacheEntry[0x15] = '\x01';
  }
  if (*cacheEntry == '\0') {
    if ((*(int *)(cacheEntry + 0xb4) == 0x1b00) || (*(int *)(cacheEntry + 0xb8) == 0x1b00))
    goto setLevelBytes;
    levelBytes = 0;
    levelCount = 0;
  }
  else {
    callResultPair = ((int (*)())gld_scalePointSizeToPixels)(glContext,(uint)(byte)cacheEntry[1]);
    allocPairHigh = (int)((ulonglong)callResultPair >> 0x20);
    calleeResultLow = (undefined4)callResultPair;
    levelBytes = allocPairHigh << 2;
    *(int *)(cacheEntry + 4) = allocPairHigh;
    if (levelBytes < 1) {
setLevelBytes:
      levelBytes = 0;
      levelCount = 1;
    }
    else {
      levelCount = 1;
    }
  }
  smoothLevelBytes = levelBytes;
  minLevelBytes = levelBytes;
  if ((*(uint *)(cacheEntry + 0x14) & 0xffff0000) == 0) {
    if ((*(int *)(cacheEntry + 0xb4) == 0x1b01) || (*(int *)(cacheEntry + 0xb8) == 0x1b01))
    goto setLevelCount;
  }
  else {
    maxSizeShort = 0xffff;
    if (((unsigned char *)0x00002e2c)[engineState2] != '\0') {
      maxSizeShort = *(undefined2 *)(((unsigned char *)0x00002e28) + engineState2);
    }
    *(undefined2 *)(cacheEntry + 0x28) = maxSizeShort;
    pointSizePixelsA = ((int (*)())gld_computePointSizePixels)(glContext,calleeResultLow,staleArgR5,staleArgR6,negPointMode,dirtyUnitMask,entryFlag15);
    *(int *)(cacheEntry + 0x18) = pointSizePixelsA;
    if (levelBytes < pointSizePixelsA << 2) {
      smoothLevelBytes = pointSizePixelsA << 2;
    }
    if (levelBytes < 0x10) {
      minLevelBytes = 0x10;
    }
setLevelCount:
    levelCount = levelCount + 1;
    levelBytes = smoothLevelBytes;
  }
  if (cacheEntry[0x2a] != '\0') {
    staleArgR5 = 0x80;
    (**(code **)(((unsigned char *)0x00001344) + glContext))(cacheEntry + 0x2c,((unsigned char *)0x000030e8) + engineState2,0x80);
    *(undefined4 *)(cacheEntry + 0xac) = *(undefined4 *)(glContext + 0x2770);
    *(undefined4 *)(cacheEntry + 0xb0) = *(undefined4 *)(glContext + 0x2774);
    if (levelBytes < 0x20) {
      levelBytes = 0x20;
    }
    if (minLevelBytes < 0x20) {
      minLevelBytes = 0x20;
    }
    levelCount = levelCount + 1;
  }
  calleeResultLow = ((int (*)())gld_roundUpToPowerOfTwo)(glContext,levelBytes,staleArgR5,staleArgR6,negPointMode,dirtyUnitMask,entryFlag15);
  entryFlag15 = ((int (*)())gld_roundUpToPowerOfTwo)(glContext,minLevelBytes,staleArgR5,staleArgR6,negPointMode,dirtyUnitMask,entryFlag15);
  levelCountClamped = levelCount;
  if (1 < levelCount) {
    levelCountClamped = 4;
  }
  glContextWord4 = *(undefined4 *)(glContext + 4);
  if (levelCount < 2) {
    textureFlags = 3;
  }
  else {
    textureFlags = 1;
  }
  oneValue = (char *)0x1;
  callResultPair = gld_createInternalTexture(glContext,calleeResultLow,entryFlag15,levelCountClamped,0x1909,1,((unsigned char *)0x00001401U),textureFlags);
  maskTexture = (int)((ulonglong)callResultPair >> 0x20);
  allocResultLow = (uint)callResultPair;
  maskLevelBytes = 0;
  if (maskTexture != 0) {
    gld_buildTextureHardwareState(glContextWord4,maskTexture);
    maskLevel = *(int *)(maskTexture + 0x30);
    maskLevelBytes = maskTexture + 0x3c;
    oneValue = (char *)0x2600;
    *(undefined1 *)(maskTexture + 0x39) = 0xff;
    *(undefined2 *)(maskTexture + 0x74) = *(undefined2 *)(maskLevel + 0xb0);
    *(undefined2 *)(maskTexture + 0x7c) = *(undefined2 *)(maskLevel + 0xac);
    *(uint *)(maskTexture + 0xc0) = (uint)*(ushort *)(maskLevel + 0xae) * (uint)*(ushort *)(maskLevel + 0xac);
    maskLevelWordb4 = *(undefined4 *)(maskLevel + 0xb4);
    *(undefined2 *)(maskTexture + 0xa2) = 0x2600;
    *(uint *)(maskTexture + 0x50) = *(uint *)(maskTexture + 0x50) & 0xfffe01ff | 0x8a00;
    *(uint *)(maskTexture + 0x54) = *(uint *)(maskTexture + 0x54) & 0xfffffffc | 1;
    *(undefined2 *)(maskTexture + 0xa0) = 0x2600;
    *(undefined4 *)(maskTexture + 0xbc) = maskLevelWordb4;
    allocResultLow = r4AfterCall;
  }
  *(int *)(cacheEntry + 0xbc) = maskLevelBytes;
  if (maskLevelBytes != 0) {
    pixelCursor = *(int *)(maskLevelBytes + 0x80);
    if (*cacheEntry == '\0') {
      if (1 < levelCount) {
        _memset(pixelCursor,0xff,*(undefined4 *)(maskLevelBytes + 0x84));
        allocResultLow = r4AfterCall5;
      }
    }
    else {
      maskHeight = (uint)*(ushort *)(maskLevelBytes + 0x3c);
      maskWidth = (uint)*(ushort *)(maskLevelBytes + 0x3a);
      i2dHi3 = 0x43300000;
      entryWord4X2 = *(int *)(cacheEntry + 4) * 2;
      entryWord4X4 = *(int *)(cacheEntry + 4) << 2;
      i2dLo3 = entryWord4X2 ^ 0x80000000;
      maskIsHardEdged = cacheEntry[1] == '\0';
      entryWord4X2F = (float)((double)CONCAT44(0x43300000,i2dLo3) - 4503601774854144.0);
      if (maskIsHardEdged) {
        rampAllocPair = (ulonglong)allocResultLow;
        innerLimitSq = 0.0;
      }
      else {
        rampAllocPair = (**(code **)(glContext + 0xc))(entryWord4X2);
        rampAllocHigh = (uint)(rampAllocPair >> 0x20);
        maskIsHardEdged = rampAllocHigh == 0;
        if (maskIsHardEdged) {
          innerLimitSq = 0.0;
        }
        else {
          levelCountClamped = rampAllocHigh;
          if ((*(uint *)(glContext + 0xe8) & 1) == 0) {
            contextFloatArg = (double)*(float *)(glContext + 0xe0);
            if (cacheEntry[8] != '\0') goto callGldBuildCoverageByteTable;
            ((void (*)())gld_buildCoverageRampTable)(glContext,(int)rampAllocPair,entryWord4X4,rampAllocHigh,rampCountWords,contextFloatArg,staleArgF2,staleArgF3,staleArgF4,staleArgF5,
                         staleArgF6,staleArgF7,staleArgF8,staleStackArg_fffffeb8,staleStackArg_fffffec0,staleStackArg_fffffec8,
                         staleStackArg_fffffed0,staleStackArg_fffffed8);
            calleeResultLow = r4AfterCall3;
          }
          else {
            contextFloatArg = (double)*(float *)(glContext + 0x104);
callGldBuildCoverageByteTable:
            ((void (*)())gld_buildCoverageByteTable)(glContext,(int)rampAllocPair,entryWord4X4,rampAllocHigh,rampCountWords,contextFloatArg,staleArgF2,staleArgF3,staleArgF4,staleArgF5,
                         staleArgF6,staleArgF7,staleArgF8,staleStackArg_fffffeb8,staleStackArg_fffffec0,staleStackArg_fffffec8,
                         staleStackArg_fffffed0);
            calleeResultLow = r4AfterCall2;
          }
          rampAllocPair = CONCAT44(rampAllocHigh,calleeResultLow);
          i2dHi4 = 0x43300000;
          i2dLo4 = entryWord4X2 - rampCountWords[0] ^ 0x80000000;
          innerLimitSq = (float)((double)CONCAT44(0x43300000,i2dLo4) - 4503601774854144.0) - 0.5;
          innerLimitSq = innerLimitSq * innerLimitSq;
        }
      }
      rampBuffer = (int)(rampAllocPair >> 0x20);
      allocResultLow = (uint)rampAllocPair;
      oneValue = "ram[";
      firstCoord = 0.5 - entryWord4X2F;
      if (maskIsHardEdged) {
        if (maskHeight != 0) {
          loopIndex6 = 0;
          rowCoord2 = firstCoord;
          do {
            if (maskWidth != 0) {
              loopIndex2 = 0;
              colsLeft = maskWidth;
              colCoord = firstCoord;
              do {
                maskValue = 0xff;
                if (entryWord4X2F * entryWord4X2F <= colCoord * colCoord + rowCoord2 * rowCoord2) {
                  maskValue = 0;
                }
                *(undefined1 *)(pixelCursor + loopIndex2) = maskValue;
                loopIndex2 = loopIndex2 + 1;
                colCoord = colCoord + 1.0;
                colsLeft = colsLeft - 1;
              } while (colsLeft != 0);
            }
            oneValue = "ram[";
            loopIndex6 = loopIndex6 + 1;
            pixelCursor = pixelCursor + maskWidth;
            rowCoord2 = rowCoord2 + 1.0;
          } while (maskHeight != loopIndex6);
        }
      }
      else {
        if (maskHeight != 0) {
          loopIndex5 = 0;
          rowCoord = firstCoord;
          do {
            if (maskWidth != 0) {
              loopIndex7 = 0;
              colCoord2 = firstCoord;
              do {
                distSq = colCoord2 * colCoord2 + rowCoord * rowCoord;
                if (innerLimitSq <= distSq) {
                  if (entryWord4X2F * entryWord4X2F <= distSq) {
                    *(undefined1 *)(pixelCursor + loopIndex7) = 0;
                  }
                  else {
                    distSq = _sqrtf(distSq);
                    rampIndex = (int)((entryWord4X2F - distSq) + 0.5);
                    fctiwzSlot2 = (longlong)rampIndex;
                    *(undefined1 *)(pixelCursor + loopIndex7) = *(undefined1 *)(rampBuffer + rampIndex);
                  }
                }
                else {
                  *(undefined1 *)(pixelCursor + loopIndex7) = 0xff;
                }
                loopIndex7 = loopIndex7 + 1;
                colCoord2 = colCoord2 + 1.0;
              } while (maskWidth != loopIndex7);
            }
            loopIndex5 = loopIndex5 + 1;
            pixelCursor = pixelCursor + maskWidth;
            rowCoord = rowCoord + 1.0;
          } while (maskHeight != loopIndex5);
        }
        oneValue = "ram[";
        (**(code **)(glContext + 0x18))(rampBuffer);
        allocResultLow = r4AfterCall4;
      }
      i2dLo5 = entryWord4X4 ^ 0x80000000;
      i2dLo6 = maskWidth ^ 0x80000000;
      i2dHi5 = 0x43300000;
      i2dLo7 = maskHeight ^ 0x80000000;
      i2dHi6 = 0x43300000;
      entryWord4X4F = (float)((double)CONCAT44(0x43300000,i2dLo5) - 4503601774854144.0);
      *(float *)(cacheEntry + 0xc) =
           entryWord4X4F / (float)((double)CONCAT44(0x43300000,i2dLo6) - 4503601774854144.0);
      i2dHi7 = 0x43300000;
      *(float *)(cacheEntry + 0x10) =
           entryWord4X4F / (float)((double)CONCAT44(0x43300000,i2dLo7) - 4503601774854144.0);
    }
    cacheEntryPtrbc = *(int *)(cacheEntry + 0xbc);
    pixelCursor = *(int *)(cacheEntryPtrbc + 0x80);
    if (1 < levelCount) {
      pixelCursor = pixelCursor + *(int *)(cacheEntryPtrbc + 0x84);
    }
    entryWord14High = (int *)(*(uint *)(cacheEntry + 0x14) & 0xffff0000);
    if (entryWord14High == (int *)0x0) {
      if (1 < levelCount) {
        _memset(pixelCursor,0xff,*(undefined4 *)(cacheEntryPtrbc + 0x84));
        goto setCacheEntryPtrbc;
      }
    }
    else {
      maskPitch = (uint)*(ushort *)(cacheEntryPtrbc + 0x3a);
      cacheEntryWord18 = *(int *)(cacheEntry + 0x18);
      blockRows = (int)(uint)*(ushort *)(cacheEntryPtrbc + 0x3c) >> 4;
      engineCapsB = *(int *)(*(int *)(glContext + 4) + 0x10);
      sizeBytes = cacheEntryWord18 * 4;
      lastRowPtr = pixelCursor + maskPitch * (*(ushort *)(cacheEntryPtrbc + 0x3c) - 1);
      if (cacheEntry[0x14] == '\0') {
        _memset(lastRowPtr,0xff,maskPitch);
        cacheEntry[0x24] = '?';
        cacheEntry[0x25] = -0x80;
        cacheEntry[0x26] = '\0';
        cacheEntry[0x27] = '\0';
      }
      else {
        levelCountClamped = lastRowPtr;
        if (cacheEntry[0x1c] == '\0') {
          engineFloat2e20 = (double)*(float *)(((unsigned char *)0x00002e20) + engineCapsB);
          glContextFloat13e8 = (double)*(float *)(((unsigned char *)0x000013e8) + glContext);
          quantizedValue = glContextFloat13e8;
          if ((glContextFloat13e8 < engineFloat2e20) &&
             (quantizedValue = (double)*(float *)(((unsigned char *)0x000013ec) + glContext),
             engineFloat2e20 < (double)*(float *)(((unsigned char *)0x000013ec) + glContext))) {
            i2dHi8 = 0x43300000;
            i2dLo8 = (uint)(int)((float)((double)(float)(engineFloat2e20 - glContextFloat13e8) /
                                      (double)*(float *)(((unsigned char *)0x000013f0) + glContext)) + 0.5);
            fctiwzSlot3 = (longlong)(int)i2dLo8;
            i2dLo8 = i2dLo8 ^ 0x80000000;
            quantizedValue = (double)(float)((double)*(float *)(((unsigned char *)0x000013f0) + glContext) *
                                     (double)(float)((double)CONCAT44(0x43300000,i2dLo8) -
                                                    4503601774854144.0) + glContextFloat13e8);
          }
          entryWord14High = rampCountWords;
          ((void (*)())gld_buildCoverageRampTable)(glContext,allocResultLow,sizeBytes,lastRowPtr,entryWord14High,quantizedValue,staleArgF2,staleArgF3,staleArgF4,staleArgF5,staleArgF6,
                       staleArgF7,staleArgF8,staleStackArg_fffffeb8,staleStackArg_fffffec0,staleStackArg_fffffec8,
                       staleStackArg_fffffed0,staleStackArg_fffffed8);
        }
        else {
          engineFloat2e20 = (double)*(float *)(((unsigned char *)0x00002e20) + engineCapsB);
          glContextFloat13e8 = (double)*(float *)(((unsigned char *)0x000013e8) + glContext);
          quantizedValue = glContextFloat13e8;
          if ((glContextFloat13e8 < engineFloat2e20) &&
             (quantizedValue = (double)*(float *)(((unsigned char *)0x000013ec) + glContext),
             engineFloat2e20 < (double)*(float *)(((unsigned char *)0x000013ec) + glContext))) {
            i2dHi9 = 0x43300000;
            i2dLo9 = (uint)(int)((float)((double)(float)(engineFloat2e20 - glContextFloat13e8) /
                                      (double)*(float *)(((unsigned char *)0x000013f0) + glContext)) + 0.5);
            fctiwzSlot4 = (longlong)(int)i2dLo9;
            i2dLo9 = i2dLo9 ^ 0x80000000;
            quantizedValue = (double)(float)((double)*(float *)(((unsigned char *)0x000013f0) + glContext) *
                                     (double)(float)((double)CONCAT44(0x43300000,i2dLo9) -
                                                    4503601774854144.0) + glContextFloat13e8);
          }
          entryWord14High = rampCountWords;
          ((void (*)())gld_buildCoverageByteTable)(glContext,allocResultLow,sizeBytes,lastRowPtr,entryWord14High,quantizedValue,staleArgF2,staleArgF3,staleArgF4,staleArgF5,staleArgF6,
                       staleArgF7,staleArgF8,staleStackArg_fffffeb8,staleStackArg_fffffec0,staleStackArg_fffffec8,
                       staleStackArg_fffffed0);
        }
        if (0 < rampCountWords[0]) {
          loopIndex3 = 0;
          mirrorDst = (undefined1 *)(lastRowPtr + sizeBytes);
          do {
            mirrorSrc = (undefined1 *)(loopIndex3 + lastRowPtr);
            loopIndex3 = loopIndex3 + 1;
            mirrorDst = mirrorDst + -1;
            *mirrorDst = *mirrorSrc;
          } while (loopIndex3 < rampCountWords[0]);
        }
        _memset(lastRowPtr + rampCountWords[0],0xff,sizeBytes + rampCountWords[0] * -2);
        _memset((undefined1 *)(lastRowPtr + sizeBytes),0,maskPitch + cacheEntryWord18 * -4);
        i2dLo11 = sizeBytes ^ 0x80000000;
        i2dLo10 = maskPitch ^ 0x80000000;
        i2dHi10 = 0x43300000;
        i2dHi11 = 0x43300000;
        *(float *)(cacheEntry + 0x24) =
             (float)((double)CONCAT44(0x43300000,i2dLo11) - 4503601774854144.0) /
             (float)((double)CONCAT44(0x43300000,i2dLo10) - 4503601774854144.0);
      }
      engineState = *(int *)(*(int *)(glContext + 4) + 0x10);
      if (((((unsigned char *)0x00002e2c)[engineState] == '\0') ||
          (entryWord14High = (int *)(*(uint *)(glContext + 0x44) & 0x20000), entryWord14High != (int *)0x0)) ||
         (allocResultLow = (uint)*(ushort *)(((unsigned char *)0x00002e28) + engineState), allocResultLow == 0xffff)) {
        allocResultLow = 0xffff;
      }
      loopIndex4 = 0;
      do {
        oneValue = (char *)(allocResultLow & 1);
        if (oneValue == (char *)0x0) {
          rowsEnd = pixelCursor + maskPitch * blockRows;
          _memset(pixelCursor,0,maskPitch * blockRows);
        }
        else {
          rowsThisBlock = blockRows;
          if (loopIndex4 == 0xf) {
            rowsThisBlock = blockRows + -1;
          }
          rowsEnd = pixelCursor;
          if (0 < rowsThisBlock) {
            loopIndex = 0;
            do {
              loopIndex = loopIndex + 1;
              rowsEnd = pixelCursor + maskPitch;
              (**(code **)(((unsigned char *)0x00001344) + glContext))(pixelCursor,lastRowPtr,maskPitch);
              pixelCursor = rowsEnd;
            } while (rowsThisBlock != loopIndex);
          }
        }
        notLastBlock = loopIndex4 != 0xf;
        allocResultLow = allocResultLow >> 1;
        loopIndex4 = loopIndex4 + 1;
        pixelCursor = rowsEnd;
      } while (notLastBlock);
setCacheEntryPtrbc:
      cacheEntryPtrbc = *(int *)(cacheEntry + 0xbc);
    }
    pixelCursor = *(int *)(cacheEntryPtrbc + 0x80);
    if (1 < levelCount) {
      pixelCursor = pixelCursor + *(int *)(cacheEntryPtrbc + 0x84) * 2;
    }
    if (cacheEntry[0x2a] == '\0') {
      if (1 < levelCount) {
        _memset(pixelCursor,0xff,*(undefined4 *)(cacheEntryPtrbc + 0x84));
        goto setCacheEntryPtrbc2;
      }
    }
    else {
      maskFieldValue = (uint)*(ushort *)(cacheEntryPtrbc + 0x3a);
      blocksLeft = 0x20;
      entryWord14High = *(int **)(cacheEntry + 0xac);
      cacheEntryWordb0 = *(uint *)(cacheEntry + 0xb0);
      oneValue = (char *)((int)(uint)*(ushort *)(cacheEntryPtrbc + 0x3c) >> 5);
      maskPitchShift = (int)maskFieldValue >> 5;
      do {
        patternCol = 0;
        levelCountClamped = 0;
        do {
          stippleByte = 0xff;
          if ((1 << ((uint)entryWord14High & 0x3f) & *(uint *)(cacheEntry + (0x1f - cacheEntryWordb0) * 4 + 0x2c)) == 0)
          {
            stippleByte = 0;
          }
          levelRows = levelCountClamped + pixelCursor;
          if (oneValue != (char *)0x0) {
            zeroValue = (char *)0x0;
            do {
              if (maskPitchShift != 0) {
                fillCol = 0;
                maskPitchCopy = maskPitchShift;
                do {
                  *(undefined1 *)(levelRows + fillCol) = stippleByte;
                  fillCol = fillCol + 1;
                  maskPitchCopy = maskPitchCopy + -1;
                } while (maskPitchCopy != 0);
              }
              zeroValue = zeroValue + 1;
              levelRows = levelRows + maskFieldValue;
            } while (oneValue != zeroValue);
          }
          notLastPatternCol = patternCol != 0x1f;
          levelCountClamped = levelCountClamped + maskPitchShift;
          patternCol = patternCol + 1;
          entryWord14High = (int *)((int)entryWord14High + 1U & 0x1f);
        } while (notLastPatternCol);
        blocksLeft = blocksLeft + -1;
        pixelCursor = pixelCursor + maskFieldValue * (int)oneValue;
        cacheEntryWordb0 = cacheEntryWordb0 + 1 & 0x1f;
      } while (blocksLeft != 0);
setCacheEntryPtrbc2:
      cacheEntryPtrbc = *(int *)(cacheEntry + 0xbc);
    }
    uploadResult = gld_makeTextureResidentOrDelete(glContext,*(undefined4 *)(cacheEntryPtrbc + 0x7c),*(undefined4 *)(glContext + 0x276c),
                          levelCountClamped,entryWord14High,oneValue);
    if (uploadResult != 0) {
      levelFormat = (uint)*(byte *)(*(int *)(cacheEntry + 0xbc) + 0x31);
      cacheEntry[0xf8] = '\0';
      cacheEntry[0xf9] = '\0';
      cacheEntry[0xfa] = '\0';
      cacheEntry[0xfb] = '\0';
      cacheEntry[0xd0] = '\0';
      cacheEntry[0xd1] = '\0';
      cacheEntry[0xd2] = '\0';
      cacheEntry[0xd3] = '\0';
      channelCount = 1 - ((int)-(levelFormat ^ 2) >> 0x1f);
      if ((*cacheEntry == '\0') && (levelFormat != 3)) {
        cacheEntry[0xe8] = '\0';
        cacheEntry[0xe9] = '\0';
        cacheEntry[0xea] = '\0';
        cacheEntry[0xeb] = '\0';
        cacheEntry[0xc0] = '\0';
        cacheEntry[0xc1] = '\0';
        cacheEntry[0xc2] = '\0';
        cacheEntry[0xc3] = '\0';
      }
      else {
        cacheEntry[0xc0] = '\0';
        cacheEntry[0xc1] = '\0';
        cacheEntry[0xc2] = '\0';
        cacheEntry[0xc3] = '\x02';
        cacheEntry[0xe8] = '\0';
        cacheEntry[0xe9] = '\0';
        cacheEntry[0xea] = '\0';
        cacheEntry[0xeb] = '\x01';
        if ((*(int *)(cacheEntry + 0xb4) == 0x1b00) || (*(int *)(cacheEntry + 0xb8) == 0x1b00)) {
          *(uint *)(cacheEntry + 0xd0) = levelFormat;
          *(int *)(cacheEntry + 0xf8) = channelCount;
        }
      }
      if (((*(uint *)(cacheEntry + 0x14) & 0xffff0000) == 0) && (levelFormat != 3)) {
        cacheEntry[0xec] = '\0';
        cacheEntry[0xed] = '\0';
        cacheEntry[0xee] = '\0';
        cacheEntry[0xef] = '\0';
        cacheEntry[0xc4] = '\0';
        cacheEntry[0xc5] = '\0';
        cacheEntry[0xc6] = '\0';
        cacheEntry[199] = '\0';
      }
      else {
        *(uint *)(cacheEntry + 0xc4) = levelFormat;
        *(int *)(cacheEntry + 0xec) = channelCount;
        if ((*(int *)(cacheEntry + 0xb4) == 0x1b01) || (*(int *)(cacheEntry + 0xb8) == 0x1b01)) {
          *(uint *)(cacheEntry + 0xd0) = levelFormat;
          *(int *)(cacheEntry + 0xf8) = channelCount;
        }
      }
      if ((cacheEntry[0x2a] != 0) || (levelFormat == 3)) {
        *(uint *)(cacheEntry + 0xd0) = levelFormat;
        *(int *)(cacheEntry + 0xf8) = channelCount;
      }
      flagBits114 = (uint)((*(uint *)(cacheEntry + 0x14) & 0xffff0000) != 0) * 0x10 |
               *(uint *)(cacheEntry + 0x114) & 0xffffffef;
      cacheEntryWordf8 = *(undefined4 *)(cacheEntry + 0xf8);
      flagBits120 = -(uint)(byte)cacheEntry[0x2a] >> 0x1b & 0x10 | *(uint *)(cacheEntry + 0x120) & 0xffffffef;
      cacheEntryWordd0 = *(undefined4 *)(cacheEntry + 0xd0);
      *(undefined4 *)(cacheEntry + 0xcc) = *(undefined4 *)(cacheEntry + 0xc4);
      *(undefined4 *)(cacheEntry + 200) = *(undefined4 *)(cacheEntry + 0xc4);
      *(undefined4 *)(cacheEntry + 0xf4) = *(undefined4 *)(cacheEntry + 0xec);
      *(undefined4 *)(cacheEntry + 0xf0) = *(undefined4 *)(cacheEntry + 0xec);
      *(undefined4 *)(cacheEntry + 0x10c) = cacheEntryWordf8;
      *(uint *)(cacheEntry + 0x11c) = flagBits114;
      *(uint *)(cacheEntry + 0x134) = flagBits120;
      *(uint *)(cacheEntry + 0x120) = flagBits120;
      *(uint *)(cacheEntry + 0x124) = flagBits120;
      *(uint *)(cacheEntry + 0x128) = flagBits120;
      *(uint *)(cacheEntry + 300) = flagBits120;
      *(uint *)(cacheEntry + 0x130) = flagBits120;
      *(undefined4 *)(cacheEntry + 0xe4) = cacheEntryWordd0;
      *(undefined4 *)(cacheEntry + 0xd4) = cacheEntryWordd0;
      *(undefined4 *)(cacheEntry + 0xfc) = cacheEntryWordf8;
      *(undefined4 *)(cacheEntry + 0xd8) = cacheEntryWordd0;
      *(undefined4 *)(cacheEntry + 0x100) = cacheEntryWordf8;
      *(undefined4 *)(cacheEntry + 0xdc) = cacheEntryWordd0;
      *(undefined4 *)(cacheEntry + 0x104) = cacheEntryWordf8;
      *(undefined4 *)(cacheEntry + 0xe0) = cacheEntryWordd0;
      *(undefined4 *)(cacheEntry + 0x108) = cacheEntryWordf8;
      *(uint *)(cacheEntry + 0x114) = flagBits114;
      *(uint *)(cacheEntry + 0x118) = flagBits114;
      *(uint *)(cacheEntry + 0x110) = *(uint *)(cacheEntry + 0x110) & 0xffffffef;
      *(undefined4 *)(cacheEntry + 0x138) = *(undefined4 *)(glContext + 0x2764);
      *(undefined4 *)(glContext + 0x2764) = cacheEntry;
      *(int *)(glContext + 0x2778) = *(int *)(glContext + 0x2778) + 1;
storeGlContext:
      *(char **)(glContext + 0x2768) = cacheEntry;
      ((int (*)())gld_refreshActivePointMask)(glContext);
      *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x200;
      *(undefined1 *)(glContext + 0x29) = 1;
      *(ushort *)(glContext + 0x34) =
           (ushort)(1 << (*(uint *)(glContext + 0x276c) & 0x3f)) | *(ushort *)(glContext + 0x34);
      *(undefined4 *)(glContext + 0x277c) = 0xffffffff;
      return 0;
    }
  }
  _free(cacheEntry);
callGldMarkBoundObjectsDirty:
  ((int (*)())gld_markBoundObjectsDirty)(glContext);
  return 1;
}

/* gld_emitClearColorPacket @ 0xa5c40 (624 bytes) */
int gld_emitClearColorPacket(glContext)
  int glContext;
{
  float clearGreenScaled;
  float clearRedScaled;
  float clearAlphaScaled;
  int clearGreenByte;
  int glContextPtr4;
  float clearBlueScaled;
  int clearAlphaByte;
  int clearRedByte;
  undefined4 *packet;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  int engineCaps;
  uint *prevPacketLink;
  uint clearBlueByte;
  undefined4 glContextWord1a94;
  
  engineCaps = *(int *)(*(int *)(glContext + 4) + 0x10);
  clearBlueScaled = *(float *)(((unsigned char *)0x00002da8) + engineCaps) * 255.0;
  if (2.1474836e+09 <= clearBlueScaled) {
    clearBlueByte = (int)(clearBlueScaled - 2.1474836e+09) + 0x80000000;
  }
  else {
    clearBlueByte = (uint)(int)clearBlueScaled;
  }
  clearAlphaScaled = *(float *)(((unsigned char *)0x00002dac) + engineCaps) * 255.0;
  if (2.1474836e+09 <= clearAlphaScaled) {
    clearAlphaByte = (int)(clearAlphaScaled - 2.1474836e+09) + -0x80000000;
  }
  else {
    clearAlphaByte = (int)clearAlphaScaled;
  }
  clearRedScaled = *(float *)(((unsigned char *)0x00002da0) + engineCaps) * 255.0;
  if (2.1474836e+09 <= clearRedScaled) {
    clearRedByte = (int)(clearRedScaled - 2.1474836e+09) + -0x80000000;
  }
  else {
    clearRedByte = (int)clearRedScaled;
  }
  clearGreenScaled = *(float *)(((unsigned char *)0x00002da4) + engineCaps) * 255.0;
  if (2.1474836e+09 <= clearGreenScaled) {
    clearGreenByte = (int)(clearGreenScaled - 2.1474836e+09) + -0x80000000;
  }
  else {
    clearGreenByte = (int)clearGreenScaled;
  }
  *(uint *)(glContext + 0x1a94) = clearBlueByte | clearAlphaByte << 0x18 | clearRedByte << 0x10 | clearGreenByte << 8;
  packet = (undefined4 *)
           (**(code **)(glContext + 0x2758))
                     (glContext,0xd,staleArgR5,staleArgR6,staleArgR7,staleArgR8,*(code **)(glContext + 0x2758));
  glContextPtr4 = *(int *)(glContext + 4);
  *(undefined4 **)(0x00002748 + glContext + 4) = packet;
  prevPacketLink = *(uint **)(glContextPtr4 + 0x1d8);
  *prevPacketLink = (int)packet - (int)prevPacketLink >> 2 | *prevPacketLink;
  *(undefined4 **)(glContextPtr4 + 0x1d8) = packet;
  *packet = 0x4000000;
  packet[3] = ((unsigned char *)0x00001393U);
  packet[4] = 10;
  packet[5] = ((unsigned char *)0x00001385U);
  glContextWord1a94 = *(undefined4 *)(glContext + 0x1a94);
  packet[7] = 0xc0023800;
  packet[0xb] = ((unsigned char *)0x00001380U);
  packet[0xc] = 0;
  packet[8] = 0;
  packet[9] = 0;
  packet[10] = 0;
  packet[6] = glContextWord1a94;
  *(undefined4 **)(0x00002748 + glContext + 4) = packet + 0xd;
                    
                    
  (**(code **)(glContext + 0x275c))(glContext,packet + 0xd);
  return;
}

/* gld_updateSampleCoverage @ 0xa5ec0 (620 bytes) */
int gld_updateSampleCoverage(glContext)
  int glContext;
{
  int sampleCountLog;
  uint coverageRemainder;
  uint sampleCoverageEnable;
  uint glContextWord44;
  uint glContextWord1930;
  uint glContextWord1a4c;
  float coverageValue;
  int sampleTableOffset;
  uint samplePatternWord;
  uint sampleCountU;
  undefined4 samplePositionWord;
  int glContextWord1a60;
  uint coverageSamples;
  uint coverageInvertMask;
  char coverageInvert;
  int sampleCountRaw;
  
  glContextWord1a4c = *(uint *)(glContext + 0x1a4c);
  glContextWord1a60 = *(int *)(glContext + 0x1a60);
  *(uint *)(glContext + 0x1a4c) = glContextWord1a4c & 0xfffeffff;
  *(undefined4 *)(glContext + 0x1a60) = 0;
  sampleCountRaw = *(int *)(*(int *)(glContext + 4) + 0x2a50);
  if (sampleCountRaw == 1) {
    glContextWord44 = *(uint *)(glContext + 0x44);
    if ((glContextWord44 & 0x10000000) == 0) {
      *(undefined4 *)(glContext + 0x1a68) = 0x66666666;
      *(undefined4 *)(glContext + 0x1a6c) = 0x6666666;
      *(undefined4 *)(glContext + 0x1b60) = 0xffffff;
      goto setGlContextWord1930;
    }
  }
  else {
    glContextWord44 = *(uint *)(glContext + 0x44);
  }
  sampleCountLog = sampleCountRaw >> 1;
  sampleTableOffset = (sampleCountLog + -1) * 4;
  samplePatternWord = *(uint *)(&samplePatternTable_001aa7e8 + sampleTableOffset);
  *(uint *)(glContext + 0x2354) = *(uint *)(glContext + 0x2354) & 0xfffffffe;
  glContextWord1a4c = (uint)(sampleCountLog == 3) << 0x11 | glContextWord1a4c & 0xfffcffff;
  *(undefined4 *)(glContext + 0x1a6c) = *(undefined4 *)(&sampleCoverageTable_001aa7d0 + sampleTableOffset);
  *(uint *)(glContext + 0x1a4c) = glContextWord1a4c;
  samplePositionWord = *(undefined4 *)(&samplePositionTable_001aa7dc + sampleTableOffset);
  *(uint *)(glContext + 0x1a60) = (samplePatternWord & 3) << 1 | 1;
  *(undefined4 *)(glContext + 0x1a68) = samplePositionWord;
  if ((glContextWord44 & 0x10000000) == 0) {
    coverageInvert = '\0';
    sampleCoverageEnable = 0;
    coverageValue = FLOAT_001aa0e8;
  }
  else {
    coverageValue = *(float *)(glContext + 0x438);
    coverageInvert = *(char *)(glContext + 0x43c);
    sampleCoverageEnable = glContextWord44 >> 0x19 & 1;
    *(uint *)(glContext + 0x1a4c) = glContextWord44 >> 0xb & 0x10000 | glContextWord1a4c;
  }
  sampleCountU = *(uint *)(*(int *)(glContext + 4) + 0x2a50);
  if (sampleCoverageEnable == 0) {
    sampleCountU = (1 << (sampleCountU & 0x3f)) - 1;
    sampleCountU = sampleCountU | sampleCountU * 0x40000 | sampleCountU * 0x1000 | sampleCountU * 0x40;
  }
  else {
    coverageInvertMask = 0;
    coverageSamples = (uint)(int)(coverageValue * FLOAT_001aa104 *
                   (float)((double)CONCAT44(0x43300000,sampleCountU ^ 0x80000000) - DOUBLE_001aa1e0) +
                  FLOAT_001aa10c);
    coverageRemainder = coverageSamples & 3;
    coverageSamples = (int)coverageSamples >> 2;
    if (coverageInvert != '\0') {
      coverageInvertMask = (1 << (sampleCountU & 0x3f)) - 1;
    }
    sampleCountU = coverageInvertMask ^ (1 << (coverageSamples + (coverageRemainder != 0) & 0x3f)) - 1U |
            (coverageInvertMask ^ (1 << (coverageSamples & 0x3f)) - 1U) << 0x12 |
            (coverageInvertMask ^ (1 << (coverageSamples + (1 < coverageRemainder) & 0x3f)) - 1U) << 0xc |
            (coverageInvertMask ^ (1 << (coverageSamples + (2 < coverageRemainder) & 0x3f)) - 1U) << 6;
  }
  *(uint *)(glContext + 0x1b60) = sampleCountU;
setGlContextWord1930:
  glContextWord1930 = *(uint *)(glContext + 0x1930);
  *(uint *)(glContext + 0x1930) = glContextWord1930 | 0x80200;
  if (glContextWord1a60 != *(int *)(glContext + 0x1a60)) {
    *(uint *)(glContext + 0x1930) = glContextWord1930 | 0x2080340;
  }
  return;
}

/* gld_resetRasterStateForInternalDraw @ 0xa6140 (896 bytes) */
int gld_resetRasterStateForInternalDraw(ring, resetFlags, saveArg)
  int ring;
  uint resetFlags;
  undefined4 saveArg;
{
  undefined4 rasterWord2444;
  undefined4 ringWord1bc0;
  undefined4 ringWord1b60;
  undefined4 ringWord1a50;
  undefined4 ringWord248c;
  undefined4 ringWord1ba0;
  undefined4 ringWord1b9c;
  undefined4 ringWord1b50;
  undefined4 ringWord1b30;
  undefined4 ringWord1b84;
  undefined4 ringWord1b74;
  undefined4 *packet;
  uint *a6;
  undefined4 rasterWord2440;
  undefined4 *packetCursor;
  
  gldSaveRasterState(ring,saveArg);
  *(undefined4 *)(ring + 0x1ba0) = 3;
  *(undefined4 *)(ring + 0x1b9c) = 3;
  *(undefined4 *)(ring + 0x1b84) = 0;
  *(undefined4 *)(ring + 0x1b50) = 0;
  *(undefined4 *)(ring + 0x1b60) = 0xffffff;
  *(undefined4 *)(ring + 0x1b30) = 0;
  *(undefined4 *)(ring + 0x1b74) = 0x1c000;
  *(undefined4 *)(ring + 0x248c) = 8;
  if ((resetFlags & 1) == 0) {
    *(undefined4 *)(ring + 0x1a50) = 0;
    *(undefined4 *)(ring + 0x1ab8) = 1;
  }
  else {
    *(undefined4 *)(ring + 0x1ab8) = 0;
  }
  if ((resetFlags & 0x1000) != 0) {
    *(undefined4 *)(ring + 0x1aec) = 0;
  }
  **(undefined4 **)(ring + 0x2440) = 0;
  **(uint **)(ring + 0x2440) = **(uint **)(ring + 0x2440) & 0xfffffff0 | 3;
  **(uint **)(ring + 0x2440) = **(uint **)(ring + 0x2440) & 0xffffff0f;
  **(uint **)(ring + 0x2440) = **(uint **)(ring + 0x2440) & 0xffffe0ff;
  **(uint **)(ring + 0x2440) = **(uint **)(ring + 0x2440) & 0xffffdfff;
  **(uint **)(ring + 0x2440) = **(uint **)(ring + 0x2440) & 0xffffbfff;
  **(uint **)(ring + 0x2440) = **(uint **)(ring + 0x2440) & 0xffff7fff;
  **(uint **)(ring + 0x2440) = **(uint **)(ring + 0x2440) & 0xfff0ffff | 0x30000;
  **(uint **)(ring + 0x2440) = **(uint **)(ring + 0x2440) & 0xff0fffff;
  **(uint **)(ring + 0x2440) = **(uint **)(ring + 0x2440) & 0xe0ffffff | 0x1000000;
  **(uint **)(ring + 0x2440) = **(uint **)(ring + 0x2440) | 0x20000000;
  **(uint **)(ring + 0x2440) = **(uint **)(ring + 0x2440) & 0xbfffffff;
  **(uint **)(ring + 0x2440) = **(uint **)(ring + 0x2440) & 0x7fffffff;
  **(undefined4 **)(ring + 0x2444) = 0;
  **(uint **)(ring + 0x2444) = **(uint **)(ring + 0x2444) & 0xfffffff8;
  **(uint **)(ring + 0x2444) = **(uint **)(ring + 0x2444) & 0xffffffc7 | 8;
  **(uint **)(ring + 0x2444) = **(uint **)(ring + 0x2444) & 0xfffffe3f | 0x80;
  **(uint **)(ring + 0x2444) = **(uint **)(ring + 0x2444) & 0xfffff1ff | 0x600;
  **(uint **)(ring + 0x2444) = **(uint **)(ring + 0x2444) & 0xffff0fff | 0xf000;
  **(uint **)(ring + 0x2444) = **(uint **)(ring + 0x2444) & 0xfff8ffff;
  **(uint **)(ring + 0x2444) = **(uint **)(ring + 0x2444) & 0xffc7ffff | 0x80000;
  **(uint **)(ring + 0x2444) = **(uint **)(ring + 0x2444) & 0xfe3fffff | 0x800000;
  a6 = *(uint **)(ring + 0x2444);
  *a6 = *a6 & 0xf1ffffff | 0x6000000;
  **(uint **)(ring + 0x2444) = **(uint **)(ring + 0x2444) & 0xfffffff | 0xf0000000;
  packet = (undefined4 *)(**(code **)(ring + 0x2758))(ring,0x20,saveArg,0xf,2,1,a6,3);
  *(undefined4 **)(0x00002748 + ring + 4) = packet;
  packetCursor = packet + 0x1a;
  *packet = 0x887;
  ringWord1b74 = *(undefined4 *)(ring + 0x1b74);
  packet[2] = 0x82c;
  packet[1] = ringWord1b74;
  ringWord1b84 = *(undefined4 *)(ring + 0x1b84);
  packet[4] = ((unsigned char *)0x000010aeU);
  packet[3] = ringWord1b84;
  ringWord1b30 = *(undefined4 *)(ring + 0x1b30);
  packet[6] = ((unsigned char *)0x00001002U);
  packet[5] = ringWord1b30;
  ringWord1b50 = *(undefined4 *)(ring + 0x1b50);
  packet[8] = 0x824;
  packet[7] = ringWord1b50;
  ringWord1b9c = *(undefined4 *)(ring + 0x1b9c);
  packet[10] = 0x825;
  packet[9] = ringWord1b9c;
  ringWord1ba0 = *(undefined4 *)(ring + 0x1ba0);
  packet[0xc] = 0x82d;
  packet[0xb] = ringWord1ba0;
  ringWord248c = *(undefined4 *)(ring + 0x248c);
  packet[0xe] = 0x854;
  packet[0xd] = ringWord248c;
  rasterWord2440 = **(undefined4 **)(ring + 0x2440);
  packet[0x10] = 0x878;
  packet[0xf] = rasterWord2440;
  rasterWord2444 = **(undefined4 **)(ring + 0x2444);
  packet[0x12] = ((unsigned char *)0x000012f0U);
  packet[0x11] = rasterWord2444;
  packet[0x13] = *(undefined4 *)(ring + 0x1aec);
  packet[0x14] = ((unsigned char *)0x000012f6U);
  ringWord1a50 = *(undefined4 *)(ring + 0x1a50);
  packet[0x16] = ((unsigned char *)0x000010faU);
  packet[0x15] = ringWord1a50;
  ringWord1b60 = *(undefined4 *)(ring + 0x1b60);
  packet[0x18] = ((unsigned char *)0x000013c5U);
  packet[0x17] = ringWord1b60;
  packet[0x19] = *(undefined4 *)(ring + 0x1ab8);
  if ((*(uint *)(ring + 0x2454) & 0x8000000) != 0) {
    packet[0x1a] = ((unsigned char *)0x000013c5U);
    packetCursor = packet + 0x1c;
    packet[0x1b] = *(undefined4 *)(ring + 0x1ab8);
  }
  *packetCursor = ((unsigned char *)0x00001048U);
  ringWord1bc0 = *(undefined4 *)(ring + 0x1bc0);
  packetCursor[2] = ((unsigned char *)0x00001047U);
  packetCursor[1] = ringWord1bc0;
  packetCursor[3] = *(undefined4 *)(ring + 0x1bb0);
  *(undefined4 **)(0x00002748 + ring + 4) = packetCursor + 4;
                    
                    
  (**(code **)(ring + 0x275c))(ring,packetCursor + 4);
  return;
}

/* gld_markFastClearFlag @ 0xa64d0 (36 bytes) */
int gld_markFastClearFlag(glContext)
  int glContext;
{
  int boundRecord;
  int targetRecord;
  
  boundRecord = *(int *)(*(int *)(glContext + 4) + 0x150);
  targetRecord = *(int *)(glContext + 4) + 0x30;
  if (boundRecord != 0) {
    targetRecord = boundRecord;
  }
  *(undefined1 *)(targetRecord + 0xc5) = 1;
  return;
}

/* gld_emitClearFillPacket @ 0xa6500 (828 bytes) */
int gld_emitClearFillPacket(glContext, emitFill)
  int glContext;
  int emitFill;
{
  uint fillPattern;
  uint surfaceModeWord;
  uint clearByte;
  uint glContextWord1ab8;
  uint *prevPacketLink;
  uint fieldMask;
  uint clearValue;
  undefined4 *packet;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  uint fieldWidth;
  undefined4 staleArgR7;
  uint loopIndex;
  undefined4 staleArgR8;
  undefined4 *writeCursor;
  uint surfaceFormatBits;
  undefined4 *fillCursor;
  int channelBits;
  int engineCaps;
  int glContextPtr4;
  
  glContextPtr4 = *(int *)(glContext + 4);
  engineCaps = *(int *)(glContextPtr4 + 0x10);
  clearValue = gldDepthBiasScaledInt(glContext);
  surfaceFormatBits = *(uint *)(glContextPtr4 + 0x154) & 0x30000;
  if ((surfaceFormatBits == 0x20000) || (surfaceFormatBits == 0x30000)) {
    channelBits = 0x18;
  }
  else {
    if (surfaceFormatBits == 0x10000) {
      channelBits = 0x10;
      *(uint *)(glContext + 0x1ae4) = clearValue | clearValue << 0x10;
      goto setSurfaceModeWord;
    }
    channelBits = 0;
  }
  *(uint *)(glContext + 0x1ae4) = clearValue << 8;
setSurfaceModeWord:
  surfaceModeWord = *(uint *)(((unsigned char *)0x00002db4) + engineCaps);
  *(uint *)(glContext + 0x1ae4) = *(uint *)(glContext + 0x1ae4) | surfaceModeWord;
  packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,0x1a,staleArgR5,staleArgR6,staleArgR7,staleArgR8,surfaceModeWord)
  ;
  *(undefined4 **)(0x00002748 + glContext + 4) = packet;
  writeCursor = packet + 0xc;
  prevPacketLink = *(uint **)(glContextPtr4 + 0x1d8);
  *prevPacketLink = (int)packet - (int)prevPacketLink >> 2 | *prevPacketLink;
  *(undefined4 **)(glContextPtr4 + 0x1d8) = packet;
  packet[8] = 0xc0023200;
  packet[0xb] = 0;
  *packet = 0x5000000;
  packet[6] = ((unsigned char *)0x000013c6U);
  packet[1] = emitFill;
  packet[2] = 0;
  packet[3] = 0;
  packet[4] = 0;
  packet[5] = 0;
  packet[9] = 0;
  packet[10] = 0;
  packet[7] = 3;
  if (emitFill != 0) {
    if (*(char *)(glContext + 0x2451) == '\0') {
      clearValue = clearValue >> (channelBits - 8U & 0x3f);
      fillPattern = clearValue | clearValue << 0x18 | clearValue << 0x10 | clearValue << 8;
    }
    else {
      fillPattern = 0xffffffff;
      if ((clearValue < 0xffffff) && (fillPattern = 0, clearValue != 0)) {
        fillPattern = channelBits - 1;
        fieldWidth = *(uint *)(glContext + 0x1ab0) >> 0xc & 7;
        fieldMask = (1 << fieldWidth) - 1;
        if ((*(uint *)(glContext + 0x1ab0) & 0x8000) == 0) {
          loopIndex = 0;
          for (; (1 << (fillPattern & 0x3f) & clearValue * fieldMask) != 0; fillPattern = fillPattern - 1) {
            loopIndex = loopIndex + 1;
          }
        }
        else {
          loopIndex = 0;
          for (; (clearValue * fieldMask & 1 << (fillPattern & 0x3f)) == 0; fillPattern = fillPattern - 1) {
            loopIndex = loopIndex + 1;
          }
        }
        clearValue = clearValue * fieldMask;
        if (loopIndex < fieldMask) {
          clearValue = clearValue * 2;
          fieldMask = loopIndex;
        }
        fillPattern = (clearValue & ~((1 << (fieldMask & 0x3f)) + -1 << (channelBits - fieldMask & 0x3f))) >>
                ((fieldWidth + (channelBits - fieldMask)) - 8 & 0x3f) | fieldMask << (8 - fieldWidth & 0x3f);
        clearByte = fillPattern & 0xff;
        fillPattern = clearByte | clearByte << 8 | clearByte << 0x10 | fillPattern << 0x18;
      }
    }
    glContextWord1ab8 = *(uint *)(glContext + 0x1ab8);
    fillCursor = packet + 0xe;
    *writeCursor = ((unsigned char *)0x000013c5U);
    glContextWord1ab8 = glContextWord1ab8 | 1;
    packet[0xd] = glContextWord1ab8;
    if ((*(uint *)(glContext + 0x2454) & 0x8000000) != 0) {
      packet[0xf] = glContextWord1ab8;
      packet[0xe] = ((unsigned char *)0x000013c5U);
      fillCursor = packet + 0x10;
    }
    writeCursor = fillCursor + 6;
    packet[2] = (int)fillCursor - (int)packet >> 2;
    *fillCursor = 0xc0023700;
    fillCursor[2] = 0;
    fillCursor[3] = fillPattern;
    fillCursor[1] = 0;
    fillCursor[4] = ((unsigned char *)0x000013c5U);
    fillCursor[5] = *(undefined4 *)(glContext + 0x1ab8);
    if ((*(uint *)(glContext + 0x2454) & 0x8000000) != 0) {
      fillCursor[6] = ((unsigned char *)0x000013c5U);
      writeCursor = fillCursor + 8;
      fillCursor[7] = *(undefined4 *)(glContext + 0x1ab8);
    }
  }
  packet[3] = (int)writeCursor + (4 - (int)packet) >> 2;
  *writeCursor = ((unsigned char *)0x000013caU);
  writeCursor[1] = *(undefined4 *)(glContext + 0x1ae4);
  *(undefined4 **)(0x00002748 + glContext + 4) = writeCursor + 2;
                    
                    
  (**(code **)(glContext + 0x275c))(glContext,writeCursor + 2);
  return;
}

/* gld_emitInternalViewportPacket @ 0xa6860 (1096 bytes) */
int gld_emitInternalViewportPacket(glContext, dirtyMask)
  int glContext;
  uint dirtyMask;
{
  int extentXFixed;
  undefined4 glContextWord1b84;
  uint extentYFixed;
  float rectLeft;
  float rectRight;
  float rectBottom;
  float rectTop;
  float screenScale;
  char glContextByte2802;
  float clipConst0;
  float rectCenterX;
  float rectCenterY;
  undefined4 *packet;
  undefined4 packetWords;
  undefined4 r4AfterCall;
  int drawFlagACopy;
  undefined *staleArgR6;
  undefined4 *packetEnd;
  undefined4 staleArgR7;
  int drawFlagB;
  int drawFlagA;
  double depthValue;
  undefined1 savedDrawState [144];
  undefined4 i2dHi5;
  uint i2dLo1;
  undefined4 i2dHi2;
  uint i2dLo2;
  undefined4 i2dHi1;
  uint rectTopLo;
  undefined4 i2dHi6;
  uint rectBottomLo;
  undefined4 i2dHi3;
  undefined4 i2dLo3;
  longlong fctiwzSlot0;
  longlong fctiwzSlot1;
  undefined4 i2dHi4;
  undefined4 i2dLo4;
  longlong fctiwzSlot2;
  longlong fctiwzSlot3;
  float clipConst1;
  float clipConst2;
  float clipConst3;
  
  i2dHi6 = 0x43300000;
  i2dHi5 = 0x43300000;
  i2dHi2 = 0x43300000;
  i2dHi1 = 0x43300000;
  i2dLo1 = *(int *)(((unsigned char *)0x00001358) + glContext) - *(int *)(((unsigned char *)0x000013d8) + glContext) ^ 0x80000000;
  i2dLo2 = *(int *)(((unsigned char *)0x00001360) + glContext) - *(int *)(((unsigned char *)0x000013d8) + glContext) ^ 0x80000000;
  rectTopLo = *(int *)(((unsigned char *)0x0000135c) + glContext) - *(int *)(((unsigned char *)0x000013dc) + glContext) ^ 0x80000000;
  rectBottomLo = *(int *)(((unsigned char *)0x00001364) + glContext) - *(int *)(((unsigned char *)0x000013dc) + glContext) ^ 0x80000000;
  depthValue = *(double *)(((unsigned char *)0x00002d88) + *(int *)(*(int *)(glContext + 4) + 0x10));
  rectLeft = (float)((double)CONCAT44(0x43300000,i2dLo1) - DOUBLE_001aa1e0);
  rectRight = (float)((double)CONCAT44(0x43300000,i2dLo2) - DOUBLE_001aa1e0);
  rectBottom = (float)((double)CONCAT44(0x43300000,rectBottomLo) - DOUBLE_001aa1e0);
  rectTop = (float)((double)CONCAT44(0x43300000,rectTopLo) - DOUBLE_001aa1e0);
  if (((dirtyMask & 0x400) == 0) || (drawFlagB = 1, ((unsigned char *)0x00001491)[glContext] == '\0')) {
    drawFlagB = 0;
  }
  if (((dirtyMask & 0x100) == 0) || (drawFlagA = 1, ((unsigned char *)0x00001490)[glContext] == '\0')) {
    drawFlagA = 0;
  }
  drawFlagACopy = drawFlagA;
  gldEnterInternalDrawState(glContext,0,drawFlagA,drawFlagB,savedDrawState);
  if ((drawFlagA == 0) && (drawFlagB != 0)) {
    packetWords = 0x25;
    if (*(char *)(glContext + 0x2802) != '\0') {
      packetWords = 0x23;
    }
    packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,packetWords);
    glContextByte2802 = *(char *)(glContext + 0x2802);
    *(undefined4 **)(0x00002748 + glContext + 4) = packet;
    if (glContextByte2802 == '\0') {
      *packet = 0x5c8;
      packet[1] = 0x10000000;
      packet = packet + 2;
      *(undefined1 *)(glContext + 0x2802) = 1;
    }
    packet = (undefined4 *)gldEmitInternalDrawSetupPackets(glContext,packet);
    i2dLo3 = *(undefined4 *)(glContext + 8);
    i2dHi3 = 0x43300000;
    *(undefined4 **)(glContext + 0x2794) = packet;
    clipConst3 = FLOAT_001aa194;
    clipConst2 = FLOAT_001aa190;
    clipConst1 = FLOAT_001aa18c;
    clipConst0 = FLOAT_001aa188;
    rectCenterY = (rectTop + rectBottom) * FLOAT_001aa10c;
    rectCenterX = (rectLeft + rectRight) * FLOAT_001aa10c;
    screenScale = (float)((double)CONCAT44(0x43300000,i2dLo3) - DOUBLE_001aa250);
    extentYFixed = (uint)(int)(*(float *)(glContext + 0x2818) * FLOAT_001aa10c * screenScale * (rectBottom - rectTop));
    fctiwzSlot0 = (longlong)(int)extentYFixed;
    extentXFixed = (int)(screenScale * *(float *)(glContext + 0x2814) * FLOAT_001aa10c * (rectRight - rectLeft));
    fctiwzSlot1 = (longlong)extentXFixed;
    packet[2] = 0x82c;
    *packet = ((unsigned char *)0x00001087U);
    packet[1] = extentXFixed << 0x10 | extentYFixed & 0xffff;
  }
  else {
    packetWords = 0x25;
    if (*(char *)(glContext + 0x2802) != '\0') {
      packetWords = 0x23;
    }
    packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,packetWords);
    glContextByte2802 = *(char *)(glContext + 0x2802);
    *(undefined4 **)(0x00002748 + glContext + 4) = packet;
    if (glContextByte2802 == '\0') {
      *packet = 0x5c8;
      packet[1] = 0x10000000;
      packet = packet + 2;
      *(undefined1 *)(glContext + 0x2802) = 1;
    }
    packet = (undefined4 *)gldEmitInternalDrawSetupPackets(glContext,packet);
    i2dLo4 = *(undefined4 *)(glContext + 8);
    i2dHi4 = 0x43300000;
    *(undefined4 **)(glContext + 0x2794) = packet;
    clipConst3 = FLOAT_001aa194;
    clipConst2 = FLOAT_001aa190;
    clipConst1 = FLOAT_001aa18c;
    clipConst0 = FLOAT_001aa188;
    rectCenterY = (rectTop + rectBottom) * FLOAT_001aa10c;
    rectCenterX = (rectLeft + rectRight) * FLOAT_001aa10c;
    screenScale = (float)((double)CONCAT44(0x43300000,i2dLo4) - DOUBLE_001aa250);
    extentYFixed = (uint)(int)(*(float *)(glContext + 0x2818) * FLOAT_001aa10c * screenScale * (rectBottom - rectTop));
    fctiwzSlot2 = (longlong)(int)extentYFixed;
    extentXFixed = (int)(screenScale * *(float *)(glContext + 0x2814) * FLOAT_001aa10c * (rectRight - rectLeft));
    fctiwzSlot3 = (longlong)extentXFixed;
    packet[2] = 0x82c;
    *packet = ((unsigned char *)0x00001087U);
    packet[1] = extentXFixed << 0x10 | extentYFixed & 0xffff;
  }
  packetEnd = packet + 0x10;
  staleArgR7 = 0xc0083500;
  staleArgR6 = ((unsigned char *)0x00001087U);
  glContextWord1b84 = *(undefined4 *)(glContext + 0x1b84);
  packet[4] = 0xc0083500;
  packet[5] = 0x10031;
  packet[6] = rectCenterX;
  packet[7] = rectCenterY;
  packet[8] = (float)depthValue;
  packet[10] = clipConst0;
  packet[0xb] = clipConst1;
  packet[3] = glContextWord1b84;
  packet[0xc] = clipConst2;
  packet[0xd] = clipConst3;
  packet[0xe] = ((unsigned char *)0x00001087U);
  packet[9] = 0x3f800000;
  packet[0xf] = *(undefined4 *)(glContext + 0x1ccc);
  *(undefined4 **)(0x00002748 + glContext + 4) = packetEnd;
  (**(code **)(glContext + 0x275c))(glContext,packetEnd);
  gldValidateVertexProgramState(glContext,r4AfterCall,drawFlagACopy,staleArgR6,packetEnd,staleArgR7,extentXFixed);
  gldLeaveInternalDrawState(glContext,savedDrawState);
  return;
}

/* gld_clearStreamBuffers @ 0xa6cb0 (656 bytes) */
int gld_clearStreamBuffers(glContext, clearMask)
  int glContext;
  uint clearMask;
{
  int streamStart;
  undefined4 glContextWord1ae0;
  int glContextPtr4;
  bool colorClearNotRequested;
  code *glContextPtr275c;
  uint *prevPacketLink;
  undefined4 *trailerPacket;
  char scissorActive;
  int clearPacketHeader;
  uint surfaceFlags;
  uint depthClearBit;
  undefined4 useFastClear;
  int surfaceRecord;
  
  glContextPtr4 = *(int *)(glContext + 4);
  scissorActive = ((unsigned char *)0x00003190)[*(int *)(glContextPtr4 + 0x10)];
  if (scissorActive != '\0') {
    if ((((*(int *)(glContext + 0x440) == 0) && (*(int *)(glContext + 0x444) == 0)) &&
        (*(int *)(glContextPtr4 + 0x160) == *(int *)(glContext + 0x44c))) &&
       (*(int *)(glContextPtr4 + 0x15c) == *(int *)(glContext + 0x448))) {
      scissorActive = '\0';
    }
  }
  surfaceFlags = *(uint *)(glContextPtr4 + 0x154);
  surfaceRecord = glContextPtr4 + 0x30;
  if (*(int *)(glContextPtr4 + 0x150) != 0) {
    surfaceRecord = *(int *)(glContextPtr4 + 0x150);
  }
  if ((surfaceFlags & 0x40) == 0) {
    colorClearNotRequested = (clearMask >> 8 & 1) == 0;
loopCheckSurfaceFlags:
    if ((surfaceFlags & 0x80) == 0) {
      depthClearBit = clearMask >> 10 & 1;
loopCheckScissorActive:
      if (scissorActive == '\0') {
        if (colorClearNotRequested) {
          useFastClear = 0;
        }
        else if (((*(char *)(glContext + 0x247c) == '\0') || ((surfaceFlags & 0x40) == 0)) ||
                (((surfaceFlags & 0x30000) == 0x10000 && ((surfaceFlags & 0x1000) != 0)))) {
          useFastClear = 0;
          *(undefined1 *)(surfaceRecord + 0xc5) = 1;
        }
        else {
          useFastClear = 1;
          *(undefined1 *)(surfaceRecord + 0xc5) = 0;
          *(undefined1 *)(surfaceRecord + 0xc4) = 1;
        }
        clearPacketHeader = (**(code **)(glContext + 0x2758))(glContext,3000);
        glContextPtr275c = *(code **)(glContext + 0x275c);
        *(int *)(0x00002748 + glContext + 4) = clearPacketHeader;
        (*glContextPtr275c)(glContext,clearPacketHeader);
        streamStart = *(int *)(0x00002748 + glContext + 4);
        ((int (*)())gld_emitClearFillPacket)(glContext,useFastClear);
        *(int *)(clearPacketHeader + 0x10) = *(int *)(0x00002748 + glContext + 4) - streamStart >> 2;
        ((int (*)())gld_emitInternalViewportPacket)(glContext,clearMask);
        *(int *)(clearPacketHeader + 0x14) = *(int *)(glContext + 0x2794) - streamStart >> 2;
        goto checkDepthClearBit;
      }
    }
    else {
      depthClearBit = clearMask >> 10 & 1;
      if ((depthClearBit != 0) || ((*(uint *)(glContext + 0x8c) & 0x20000000) == 0)) goto loopCheckScissorActive;
    }
    if (!colorClearNotRequested) {
      *(undefined1 *)(surfaceRecord + 0xc5) = 1;
    }
  }
  else {
    colorClearNotRequested = (clearMask >> 8 & 1) == 0;
    if (!colorClearNotRequested) goto loopCheckSurfaceFlags;
  }
  depthClearBit = clearMask >> 10 & 1;
  ((int (*)())gld_emitInternalViewportPacket)(glContext,clearMask);
checkDepthClearBit:
  if (depthClearBit != 0) {
    *(uint *)(glContext + 0x8c) = *(uint *)(glContext + 0x8c) | 0x20000000;
  }
  glContextPtr4 = *(int *)(glContext + 4);
  gldValidateHyperZ(glContext);
  trailerPacket = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,5);
  *(undefined4 **)(0x00002748 + glContext + 4) = trailerPacket;
  prevPacketLink = *(uint **)(glContextPtr4 + 0x1d8);
  *prevPacketLink = (int)trailerPacket - (int)prevPacketLink >> 2 | *prevPacketLink;
  *(undefined4 **)(glContextPtr4 + 0x1d8) = trailerPacket;
  *trailerPacket = 0x2f000000;
  trailerPacket[1] = ((unsigned char *)0x000010e9U);
  glContextWord1ae0 = *(undefined4 *)(glContext + 0x1ae0);
  trailerPacket[3] = ((unsigned char *)0x000013c7U);
  trailerPacket[2] = glContextWord1ae0;
  trailerPacket[4] = *(undefined4 *)(glContext + 0x1ab0);
  *(undefined4 **)(0x00002748 + glContext + 4) = trailerPacket + 5;
                    
                    
  (**(code **)(glContext + 0x275c))(glContext,trailerPacket + 5);
  return;
}

/* gld_callocBytes @ 0xa6f70 (8 bytes) */
int gld_callocBytes(byteCount)
  undefined4 byteCount;
{
  return (int)_calloc(byteCount,1);
}

/* noop_a6f80 @ 0xa6f80 (4 bytes) */
int noop_a6f80()
{
  return;
}

/* gld_normalizeVec3 @ 0xa6f90 (168 bytes) */
void gld_normalizeVec3(float *outVector,float *inVector,double fpPassThrough1)
{
  float scale;
  float inX;
  double lengthSquared;
  
  scale = FLOAT_001aa0d4;
  inX = *inVector;
  lengthSquared = (double)(inVector[2] * inVector[2] + inX * inX + inVector[1] * inVector[1]);
  if (lengthSquared <= (double)FLOAT_001aa0d4) {
    outVector[2] = FLOAT_001aa0d4;
    *outVector = scale;
    outVector[1] = scale;
  }
  else {
    lengthSquared = _sqrt(lengthSquared);
    scale = (float)(DOUBLE_001aa200 / lengthSquared);
    *outVector = inX * scale;
    outVector[1] = scale * inVector[1];
    outVector[2] = scale * inVector[2];
  }
  return;
}

/* gld_initContextDispatch @ 0xa7050 (2324 bytes) */
int gld_initContextDispatch(ctx)
  int ctx;
{
  undefined4 idTableWords;
  undefined4 idTableObject;
  undefined4 floatEighthBits;
  undefined4 staleArgR8;
  undefined4 allocResult14;
  int idTableBytes;
  uint ctxWord284;
  uint ctxWord2cc;
  code *ctxPtr250;
  int ctxPtr244;
  char ctxByte1aa8;
  undefined *dispatchEntry;
  undefined *dispatchEntry2;
  code *ctxPtr24c;
  int zeroCursor;
  undefined4 allocResultA8;
  undefined4 staleArgR4;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  code *allocatorFn;
  undefined4 zeroArgForAlloc;
  uint chipClassBits;
  int streamBase;
  int remaining;
  undefined8 allocResult90;
  
  streamBase = ctx + 0x240;
  floatEighthBits = 0x3e000000;
  *(undefined1 *)(ctx + 0x26b) = 0;
  dispatchEntry = ptrTo_realloc_001e8a58;
  allocatorFn = gld_callocBytes;
  *(undefined **)(ctx + 0x250) = ptrTo_calloc_001e8b14;
  *(undefined **)(ctx + 0x254) = dispatchEntry;
  dispatchEntry = ptrTo_memcpy_001e8aa4;
  *(undefined **)(ctx + 600) = ptrTo_free_001e8a3c;
  *(undefined **)(((unsigned char *)0x00001584) + ctx) = dispatchEntry;
  dispatchEntry = ptrTo_gld_setStreamCursor_001e8aa8;
  *(undefined **)(ctx + 0x2998) = ptrTo_gld_ensureRingSpace_001e8ab0;
  *(undefined **)(ctx + 0x299c) = dispatchEntry;
  dispatchEntry = ptrTo_arbfpCompileFragmentProgram_001e8ae0;
  *(undefined **)(((unsigned char *)0x000014c0) + ctx) = ptrTo_gldSetUnitScaleConstants_001e8acc;
  *(undefined **)(((unsigned char *)0x000014c8) + ctx) = dispatchEntry;
  dispatchEntry = ptrTo_arbfpWorkAreaSizeA_001e8ae8;
  *(undefined **)(((unsigned char *)0x000014d0) + ctx) = ptrTo_arbfpBindFragmentProgram_001e8abc;
  *(undefined **)(((unsigned char *)0x000014c4) + ctx) = dispatchEntry;
  dispatchEntry = ptrTo_gld_bindProgramStateAndEmit_001e8b38;
  *(undefined **)(((unsigned char *)0x000014cc) + ctx) = ptrTo_gld_compileFragmentProgramImage_001e8a2c;
  *(undefined **)(((unsigned char *)0x000014d4) + ctx) = dispatchEntry;
  *(undefined4 *)(((unsigned char *)0x00001604) + ctx) = 0x3f800000;
  *(undefined4 *)(((unsigned char *)0x00001628) + ctx) = 0x3e000000;
  dispatchEntry2 = ptrTo_gld_emitProgramStateAndConstants_001e8b28;
  dispatchEntry = ptrTo_gldCurrentAttributePacketHeader_001e8a48;
  *(code **)(ctx + 0x24c) = gld_callocBytes;
  *(int *)(ctx + 0x244) = ctx;
  *(undefined4 *)(((unsigned char *)0x0000162c) + ctx) = 0x42800000;
  *(undefined4 *)(((unsigned char *)0x00001608) + ctx) = 0x42800000;
  *(undefined4 *)((int)((unsigned char *)0x00001624) + ctx) = 0x80;
  *(int *)(ctx + 0x25c) = streamBase;
  *(undefined **)(((unsigned char *)0x000014e8) + ctx) = dispatchEntry;
  *(undefined **)(((unsigned char *)0x000014d8) + ctx) = dispatchEntry2;
  *(undefined4 *)(((unsigned char *)0x0000145c) + ctx) = 0;
  dispatchEntry = ptrTo_gldLoadUnitFlagBits_001e8a18;
  *(undefined **)(((unsigned char *)0x000014dc) + ctx) = ptrTo_gld_emitProgramStateOnly_001e8aa0;
  *(undefined **)(((unsigned char *)0x000014e4) + ctx) = dispatchEntry;
  *(undefined **)(((unsigned char *)0x000014e0) + ctx) = ptrTo_gld_emitProgramConstantsOnly_001e8b00;
  *(undefined **)(((unsigned char *)0x000014ec) + ctx) = ptrTo_gld_freeProgramImage_001e8a08;
  ((unsigned char *)0x000015f4)[ctx] = 4;
  ((unsigned char *)0x000015f5)[ctx] = 8;
  ((unsigned char *)0x000015f7)[ctx] = 0xc;
  *(undefined4 *)(((unsigned char *)0x00001630) + ctx) = 0x3e000000;
  ((unsigned char *)0x000015f3)[ctx] = 1;
  *(undefined4 *)(((unsigned char *)0x00001408) + ctx) = 0xffff;
  *(undefined2 *)(((unsigned char *)0x000015fe) + ctx) = 0x100;
  *(undefined4 *)(((unsigned char *)0x00001614) + ctx) = 0x40;
  ((unsigned char *)0x000015f8)[ctx] = ((unsigned char *)0x00002b7c)[ctx];
  *(undefined4 *)(((unsigned char *)0x00001618U) + ctx) = 0;
  *(undefined4 *)(((unsigned char *)0x0000161c) + ctx) = 0;
  *(undefined4 *)(((unsigned char *)0x0000160c) + ctx) = 0x3e000000;
  *(undefined4 *)(((unsigned char *)0x00001610U) + ctx) = 1;
  *(undefined4 *)(((unsigned char *)0x00001620) + ctx) = 1;
  *(undefined4 *)(((unsigned char *)0x000013f8) + ctx) = 0xffff;
  *(undefined4 *)(((unsigned char *)0x00001400) + ctx) = 0xffff;
  *(undefined4 *)(((unsigned char *)0x00001404) + ctx) = 0xffff;
  *(undefined4 *)(((unsigned char *)0x000013fc) + ctx) = 0x20;
  allocResultA8 = ((int (*)())gld_callocBytes)(0xa8);
  ctxPtr24c = *(code **)(ctx + 0x24c);
  *(undefined4 *)(((unsigned char *)0x000016dc) + ctx) = 0x20;
  *(undefined4 *)(((unsigned char *)0x000013ac) + ctx) = allocResultA8;
  allocResult90 = (*ctxPtr24c)(0x90);
  ctxPtr24c = *(code **)(ctx + 0x24c);
  *(int *)(((unsigned char *)0x00001394) + ctx) = (int)((ulonglong)allocResult90 >> 0x20);
  *(undefined2 *)(((unsigned char *)0x0000138a) + ctx) = 8;
  *(undefined2 *)(((unsigned char *)0x00001388) + ctx) = 6;
  ((unsigned char *)0x00001390)[ctx] = 2;
  *(undefined2 *)(((unsigned char *)0x0000138e) + ctx) = 8;
  *(undefined2 *)(((unsigned char *)0x0000138c) + ctx) = 0x10;
  allocResult14 = (*ctxPtr24c)(0x14,(int)allocResult90,staleArgR5,staleArgR6,allocatorFn,floatEighthBits,ctxPtr24c);
  ctxWord2cc = *(uint *)(ctx + 0x2cc);
  *(undefined4 *)(((unsigned char *)0x0000136c) + ctx) = allocResult14;
  ((unsigned char *)0x000015f0)[ctx] = 8;
  ((unsigned char *)0x000015f6)[ctx] = 0x10;
  *(undefined4 *)(ctx + 0x2d4) = 0;
  ((unsigned char *)0x000015f2)[ctx] = 8;
  ((unsigned char *)0x000015f1)[ctx] = 0x10;
  *(undefined4 *)(ctx + 0x29a8) = 0;
  *(undefined4 *)(ctx + 0x29a4) = 0;
  *(undefined4 *)(ctx + 0x29b0) = 0;
  *(undefined4 *)(ctx + 0x29b4) = 0;
  *(undefined4 *)(ctx + 0x29b8) = 0;
  *(undefined1 *)(ctx + 0x262d) = 0;
  *(undefined1 *)(ctx + 0x2690) = 0;
  *(undefined4 *)(ctx + 0x1a48) = 0;
  *(undefined4 *)(ctx + 0x248) = 0xc;
  *(undefined4 *)(((unsigned char *)0x00001600) + ctx) = 3;
  *(undefined4 *)(ctx + 0x1b74) = 0xffffffff;
  *(undefined4 *)(ctx + 0x29ac) = 0xffffffff;
  *(undefined4 *)(ctx + 0x29bc) = 0xffffffff;
  *(undefined4 *)(ctx + 0x1b70) = 0xffffffff;
  remaining = 0x10;
  staleArgR8 = 0;
  *(uint *)(ctx + 0x2cc) = ctxWord2cc & 0xc02fffff | 0x40200000;
  *(undefined4 *)(ctx + 0x1ef8) = 0xaaaaaaaa;
  zeroCursor = streamBase;
  do {
    *(undefined4 *)(zeroCursor + 0x98) = 0;
    zeroCursor = zeroCursor + 4;
    remaining = remaining + -1;
  } while (remaining != 0);
  *(undefined1 *)(ctx + 0x2d0) = 0;
  *(undefined1 *)(ctx + 0x2d1) = 0;
  ctxWord284 = *(uint *)(ctx + 0x284);
  ctxPtr244 = *(int *)(ctx + 0x244);
  *(uint *)(ctx + 0x1ae4) = *(uint *)(ctx + 0x1ae4) & 0xffffffef;
  *(uint *)(ctx + 0x2cc) = *(uint *)(ctx + 0x2cc) & 0xfff5ffff;
  ((unsigned char *)0x000016d0)[ctx] = (byte)(*(uint *)(ctx + 0x154) >> 6) & 1;
  *(uint *)(ctx + 0x284) = ctxWord284 & 0xff8220ff;
  ((unsigned char *)0x000016d1)[ctx] = (byte)(*(uint *)(ctx + 0x154) >> 7) & 1;
  *(undefined1 *)(ctxPtr244 + 0xf6) = 0;
  *(undefined1 *)(*(int *)(ctx + 0x244) + 0xf4) = 0;
  *(undefined1 *)(*(int *)(ctx + 0x244) + 0xf5) = 1;
  *(undefined1 *)(ctx + 0x269) = 0;
  *(undefined4 *)(((unsigned char *)0x00001634) + ctx) = 0x100;
  *(undefined4 *)(ctx + 0x2694) = 0;
  *(undefined **)(ctx + 0x2168) = ((unsigned char *)0x0000101dU);
  *(undefined4 *)(0x00002688 + ctx) = 0x200;
  *(undefined4 *)(ctx + 0x1e20) = 0x400;
  *(undefined4 *)(ctx + 0x268c) = 0x406;
  ctxPtr244 = *(int *)(ctx + 0x244);
  chipClassBits = *(uint *)(ctxPtr244 + 0x24) & 0x7ff00000;
  if ((((chipClassBits == 0x800000) || (chipClassBits == 0x100000)) || (chipClassBits == 0x200000)) || (chipClassBits == 0x400000))
  {
    *(undefined4 *)(ctx + 0x1e20) = 0x600;
    *(undefined4 *)(0x00002688 + ctx) = 0x400;
    *(undefined4 *)(ctx + 0x268c) = 0x606;
    *(undefined4 *)(((unsigned char *)0x00001634) + ctx) = 0x400;
    *(undefined **)(ctx + 0x2168) = ((unsigned char *)0x0000101dU);
    chipClassBits = *(uint *)(ctxPtr244 + 0x24) & 0x7ff00000;
    if (chipClassBits == 0x800000) {
      *(uint *)(ctx + 0x2694) = *(uint *)(ctx + 0x2694) | 0x80000000;
    }
    else if (chipClassBits == 0x100000) {
      *(uint *)(ctx + 0x2694) = *(uint *)(ctx + 0x2694) | 0x40000000;
    }
    else if (chipClassBits == 0x200000) {
      *(uint *)(ctx + 0x2694) = *(uint *)(ctx + 0x2694) | 0x8000000;
    }
    else if (chipClassBits == 0x400000) {
      *(uint *)(ctx + 0x2694) = *(uint *)(ctx + 0x2694) | 0x2000000;
    }
  }
  zeroArgForAlloc = 0;
  gld_buildUnitSetupCmdList(streamBase,0,0);
  *(undefined1 *)(ctx + 0x1aa9) = 0;
  *(undefined1 *)(ctx + 0x1aa8) = 0;
  *(undefined4 *)(ctx + 0x1aa4) = 0;
  gld_selectProgramCallback(streamBase);
  dispatchEntry = ptrTo_ffvpComputeOutputMasks_001e8b18;
  ctxByte1aa8 = *(char *)(ctx + 0x1aa8);
  *(undefined **)(((unsigned char *)0x000014f0) + ctx) = ptrTo_gldFlushProgramStateForDraw_001e8a20;
  *(undefined **)(((unsigned char *)0x000014f4) + ctx) = dispatchEntry;
  if (ctxByte1aa8 == '\0') {
    *(undefined **)(((unsigned char *)0x000014f8) + ctx) = ptrTo_extvsBuildStreamDescriptors_001e8a60;
  }
  else {
    *(undefined **)(((unsigned char *)0x000014f8) + ctx) = ptrTo_extvsBuildStreamBlock_001e8af4;
  }
  dispatchEntry = ptrTo_gldValidateVertexOutputRouting_001e8ac4;
  *(undefined **)(((unsigned char *)0x0000157c) + ctx) = ptrTo_gldValidateState_001e8a44;
  *(undefined **)(((unsigned char *)0x00001580) + ctx) = dispatchEntry;
  dispatchEntry2 = ptrTo_noop65c80_001e8aac;
  dispatchEntry = ptrTo_ffvpInitBuilderOutputSlots_001e8a38;
  if (ctxByte1aa8 == '\0') {
    *(undefined4 *)(((unsigned char *)0x0000151c) + ctx) = 0;
    *(undefined4 *)(((unsigned char *)0x000014fc) + ctx) = 0;
    *(undefined4 *)(((unsigned char *)0x00001514) + ctx) = 0;
    *(undefined4 *)(((unsigned char *)0x00001518) + ctx) = 0;
    dispatchEntry = ptrTo_gldAllocAndUploadConstants_001e8b20;
    *(undefined **)(((unsigned char *)0x00001500) + ctx) = ptrTo_interpolatorMapInit_001e8a84;
    *(undefined **)(((unsigned char *)0x00001510) + ctx) = dispatchEntry;
    dispatchEntry = ptrTo_arbEmitRecord2Src_op01_001e8a4c;
    *(undefined **)(((unsigned char *)0x00001504) + ctx) = ptrTo_gldEmitProgramConstants_001e8a14;
    *(undefined **)(((unsigned char *)0x00001524) + ctx) = dispatchEntry;
    dispatchEntry = ptrTo_arbEmitRecord2Src_op02_001e8b30;
    *(undefined **)(((unsigned char *)0x00001520) + ctx) = ptrTo_ffvpValidateProgram_001e8b0c;
    *(undefined **)(((unsigned char *)0x0000152c) + ctx) = dispatchEntry;
    dispatchEntry = ptrTo_arbEmitRecord3Src_op04_001e8a30;
    *(undefined **)(((unsigned char *)0x00001528) + ctx) = ptrTo_arbEmitRecord1Src_op02_001e8af8;
    *(undefined **)(((unsigned char *)0x00001534) + ctx) = dispatchEntry;
    dispatchEntry = ptrTo_arbEmitRecord3Src_op0c_001e8a5c;
    *(undefined **)(((unsigned char *)0x00001530) + ctx) = ptrTo_arbEmitRecord2Src_op03_001e8a80;
    *(undefined **)(((unsigned char *)0x0000153c) + ctx) = dispatchEntry;
    dispatchEntry = ptrTo_arbEmitRecord2Src_op07_001e8a28;
    *(undefined **)(((unsigned char *)0x00001538) + ctx) = ptrTo_arbEmitRecord3Src_op0b_001e8aec;
    *(undefined **)(((unsigned char *)0x00001544) + ctx) = dispatchEntry;
    *(undefined **)(((unsigned char *)0x00001540) + ctx) = ptrTo_arbEmitRecord2Src_op08_001e8a90;
    *(undefined **)(((unsigned char *)0x00001548) + ctx) = ptrTo_arbEmitRecord2Src_op0a_001e8a24;
    *(undefined **)(((unsigned char *)0x0000154c) + ctx) = ptrTo_arbEmitRecord2Src_op09_001e8a1c;
    dispatchEntry = ptrTo_arbEmitRecord1Src_op47_001e8a34;
    *(undefined **)(((unsigned char *)0x00001550) + ctx) = ptrTo_arbEmitRecord1Src_op0e_001e8a78;
    *(undefined **)(((unsigned char *)0x00001554) + ctx) = dispatchEntry;
    dispatchEntry = ptrTo_arbEmitRecord1Src_op4b_001e8a00;
    *(undefined **)(((unsigned char *)0x00001558) + ctx) = ptrTo_arbEmitRecord1Src_op49_001e8b2c;
    *(undefined **)(((unsigned char *)0x0000155c) + ctx) = dispatchEntry;
    dispatchEntry = ptrTo_arbEmitRecord2Src_op45_001e8b24;
    *(undefined **)(((unsigned char *)0x00001560) + ctx) = ptrTo_arbEmitRecord1Src_op43_001e8a8c;
    *(undefined **)(((unsigned char *)0x00001564) + ctx) = dispatchEntry;
    dispatchEntry = ptrTo_arbEmitRecord3Src_op44_001e8ad4;
    *(undefined **)(((unsigned char *)0x00001568) + ctx) = ptrTo_arbEmitRecord2Src_op4f_001e89f8;
    *(undefined **)(((unsigned char *)0x0000156c) + ctx) = dispatchEntry;
  }
  else {
    *(undefined4 *)(((unsigned char *)0x00001520) + ctx) = 0;
    *(undefined **)(((unsigned char *)0x000014fc) + ctx) = dispatchEntry2;
    *(undefined **)(((unsigned char *)0x00001500) + ctx) = dispatchEntry;
    dispatchEntry = ptrTo_vpFillConstantBank_001e8a50;
    *(undefined **)(((unsigned char *)0x00001510) + ctx) = ptrTo_ffvpUploadVariantConstants_001e8ad0;
    *(undefined **)(((unsigned char *)0x00001504) + ctx) = dispatchEntry;
    dispatchEntry = ptrTo_arbEmitIlEnd_001e8b34;
    *(undefined **)(((unsigned char *)0x00001514) + ctx) = ptrTo_arbEmitIlHeader_001e8b08;
    *(undefined **)(((unsigned char *)0x00001518) + ctx) = dispatchEntry;
    dispatchEntry = ptrTo_arbEmitIlMov_001e8a64;
    *(undefined **)(((unsigned char *)0x0000151c) + ctx) = ptrTo_gldEmitVertexRoutingPackets_001e8a70;
    *(undefined **)(((unsigned char *)0x00001528) + ctx) = dispatchEntry;
    dispatchEntry = ptrTo_arbEmitIlAdd_001e8ac0;
    *(undefined **)(((unsigned char *)0x00001524) + ctx) = ptrTo_arbEmitIlDp4_001e8a10;
    *(undefined **)(((unsigned char *)0x00001530) + ctx) = dispatchEntry;
    dispatchEntry = ptrTo_arbEmitIlAddMad3Src_001e8a7c;
    *(undefined **)(((unsigned char *)0x0000152c) + ctx) = ptrTo_arbEmitIlMul_001e8a74;
    *(undefined **)(((unsigned char *)0x00001538) + ctx) = dispatchEntry;
    dispatchEntry = ptrTo_arbEmitIlMin_001e8ab4;
    *(undefined **)(((unsigned char *)0x00001534) + ctx) = ptrTo_arbEmitIlMad_001e8af0;
    *(undefined **)(((unsigned char *)0x00001540) + ctx) = dispatchEntry;
    dispatchEntry = ptrTo_arbEmitIlSetCompare5_001e8adc;
    *(undefined **)(((unsigned char *)0x0000153c) + ctx) = ptrTo_arbEmitIlMulMaxMin2Src_001e8a0c;
    *(undefined **)(((unsigned char *)0x00001544) + ctx) = ptrTo_arbEmitIlMax_001e8a40;
    *(undefined **)(((unsigned char *)0x00001548) + ctx) = dispatchEntry;
    dispatchEntry = ptrTo_arbEmitIlRnd_001e8a98;
    *(undefined **)(((unsigned char *)0x0000154c) + ctx) = ptrTo_arbEmitIlSetCompare2_001e8b10;
    *(undefined **)(((unsigned char *)0x00001550) + ctx) = dispatchEntry;
    dispatchEntry = ptrTo_arbEmitIlRsq_001e8a9c;
    *(undefined **)(((unsigned char *)0x00001554) + ctx) = ptrTo_arbEmitIlRcp_001e8a54;
    *(undefined **)(((unsigned char *)0x00001558) + ctx) = dispatchEntry;
    dispatchEntry = ptrTo_arbEmitIlExn_001e8ab8;
    *(undefined **)(((unsigned char *)0x0000155c) + ctx) = ptrTo_arbEmitIlExp_001e8b04;
    *(undefined **)(((unsigned char *)0x00001560) + ctx) = dispatchEntry;
    dispatchEntry = ptrTo_arbEmitIlOp4e_001e8ad8;
    *(undefined **)(((unsigned char *)0x00001564) + ctx) = ptrTo_arbEmitIlPow_001e8a94;
    *(undefined **)(((unsigned char *)0x00001568) + ctx) = dispatchEntry;
    *(undefined **)(((unsigned char *)0x0000156c) + ctx) = ptrTo_arbEmitIlMovMadMov_001e8b1c;
  }
  *(code **)(((unsigned char *)0x00001588) + ctx) = gld_normalizeVec3;
  ffvpInitContextState(streamBase,0x80);
  ctxPtr250 = *(code **)(ctx + 0x250);
  *(undefined1 *)(ctx + 0x2691) = 0;
  *(undefined1 *)(ctx + 0x365) = 0;
  *(undefined1 *)(ctx + 0x36b) = 1;
  *(undefined2 *)(ctx + 0x20ac) = 1;
  *(undefined1 *)(ctx + 0x366) = 1;
  *(undefined1 *)(ctx + 0x364) = 1;
  *(undefined4 *)(ctx + 0x37c) = 1;
  ((unsigned char *)0x00002b81)[ctx] = 1;
  zeroArgForAlloc = (*ctxPtr250)(1,((unsigned char *)0x00003754U),zeroArgForAlloc,staleArgR6,allocatorFn,staleArgR8,0);
  *(undefined4 *)(ctx + 0x20a0) = zeroArgForAlloc;
  gldInitProgramCacheEntry(streamBase);
  *(undefined2 *)(((unsigned char *)0x000015c8) + *(int *)(ctx + 0x20a0)) = 0xffff;
  *(undefined4 *)(((unsigned char *)0x0000135c) + ctx) = 5;
  idTableObject = (**(code **)(ctx + 0x250))(1,0x14);
  ctxPtr24c = *(code **)(ctx + 0x24c);
  *(undefined2 *)(((unsigned char *)0x00001350) + ctx) = 5;
  *(undefined4 *)(((unsigned char *)0x00001358) + ctx) = idTableObject;
  idTableWords = (*ctxPtr24c)(10);
  *(undefined4 *)(((unsigned char *)0x00001354) + ctx) = idTableWords;
  idTableBytes = (uint)*(ushort *)(((unsigned char *)0x00001350) + ctx) << 1;
  _memset(idTableWords,0xff,idTableBytes);
  ctxPtr24c = *(code **)(ctx + 0x24c);
  *(undefined4 *)(0x000020b4 + ctx) = 0;
  *(undefined4 *)(ctx + 0x20b8) = 0x10;
  staleArgR8 = (*ctxPtr24c)(0x40,staleArgR4,idTableBytes,staleArgR6,allocatorFn,staleArgR8,ctxPtr24c);
  *(undefined4 *)(ctx + 0x20bc) = staleArgR8;
  gldInitStateDefaults(streamBase);
  dispatchEntry = ptrTo_arbfpUnbindWorkArea_001e8afc;
  *(undefined **)(((unsigned char *)0x000013e0) + ctx) = ptrTo_gldAllocListNode_001e89c4;
  *(undefined **)(((unsigned char *)0x00001398) + ctx) = dispatchEntry;
  dispatchEntry = ptrTo_arbfpInitResourceLimits_001e89fc;
  *(code **)(((unsigned char *)0x0000139c) + ctx) = noop_a6f80;
  dispatchEntry2 = ptrTo_noop879e0_001e8a6c;
  *(undefined **)(((unsigned char *)0x000014b4) + ctx) = dispatchEntry;
  dispatchEntry = ptrTo_gld_compileFragmentProgram_001e8a68;
  *(undefined **)(((unsigned char *)0x000014b8) + ctx) = dispatchEntry2;
  dispatchEntry2 = ptrTo_arbfpUnbindWorkAreaChecked_001e8a88;
  *(undefined **)(((unsigned char *)0x000014bc) + ctx) = dispatchEntry;
  *(undefined **)(((unsigned char *)0x00001464) + ctx) = dispatchEntry2;
  /* Completed (issue #64): the whole 3-call missing block (stock 0xa7178-0xa72b0ish) is now
   * restored, in stock's real order, sizes and destinations all confirmed directly from
   * disassembly (each call's "li r3,N" immediately precedes its bctrl; each destination is the
   * "stw r3,OFFSET(r30)" immediately after): calloc(0xa8)->+0x116c, calloc(0x90)->+0x1154,
   * calloc(0x14)->+0x112c, all through the same locally-installed gld_callocBytes callback already
   * used elsewhere in this function. The middle call (+0x1154) was the one already fixed and
   * verified to resolve the original atifsCreateShaderTable null-deref crash on this issue. The other two
   * were left as an open follow-up at the time - re-derived and added here after a *different*,
   * later crash (TypedValueArray__createForType, deep in the GLSL shader-compiler call chain) traced back to this
   * same still-missing block. */
  *(int *)(streamBase + 0x116c) = ((int (*)())gld_callocBytes)(0xa8);
  *(int *)(streamBase + 0x1154) = ((int (*)())gld_callocBytes)(0x90);
  *(int *)(streamBase + 0x112c) = ((int (*)())gld_callocBytes)(0x14);
  ((int (*)())atifsCreateShaderTable)(streamBase);
  arbProgramTableInit(streamBase);
  arbfpLoadDefaultProgram(streamBase);
  *(undefined1 *)(ctx + 0x26f) = 1;
  dispatchEntry = ptrTo_gldValidateVertexStreams_001e8a04;
  *(undefined **)(((unsigned char *)0x00001570) + ctx) = ptrTo_noop4c540_001e8ac8;
  *(undefined **)(((unsigned char *)0x00001574) + ctx) = dispatchEntry;
  dispatchEntry = ptrTo_gldSetCurrentProgramObject_001e89f4;
  *(undefined **)(((unsigned char *)0x00001578) + ctx) = PTR_DAT_001e8ae4;
  *(undefined **)(((unsigned char *)0x00002b8c) + ctx) = dispatchEntry;
  return;
}

/* gldFreeEngineState @ 0xa7970 (240 bytes) */
int gldFreeEngineState(ctx)
  int ctx;
{
  int engineState;
  
  engineState = ctx + 0x240;
  ((int (*)())gld_invalidateCachedPointMasks)(engineState);
  ((int (*)())gld_freePointMaskCache)(engineState);
  gld_destroyUnitCmdLists(engineState);
  gldFlushProgramCache(engineState);
  fpVariantCacheFlush(engineState);
  if (*(int *)(((unsigned char *)0x00001358) + ctx) != 0) {
    (**(code **)(ctx + 600))(*(int *)(((unsigned char *)0x00001358) + ctx));
    *(undefined4 *)(((unsigned char *)0x00001358) + ctx) = 0;
  }
  if (*(int *)(((unsigned char *)0x00001354) + ctx) != 0) {
    (**(code **)(ctx + 600))(*(int *)(((unsigned char *)0x00001354) + ctx));
    *(undefined4 *)(((unsigned char *)0x00001354) + ctx) = 0;
  }
  if (*(int *)(ctx + 0x20bc) != 0) {
    (**(code **)(ctx + 600))(*(int *)(ctx + 0x20bc));
    *(undefined4 *)(ctx + 0x20b8) = 0;
    *(undefined4 *)(ctx + 0x20bc) = 0;
    *(undefined4 *)(0x000020b4 + ctx) = 0;
  }
  arbProgramTableRelease(engineState);
  if (*(int *)(ctx + 0x1aa4) != 0) {
    (**(code **)(ctx + 600))(*(int *)(ctx + 0x1aa4));
    *(undefined4 *)(ctx + 0x1aa4) = 0;
  }
  return;
}

/* gld_updateDrawBufferConfig @ 0xa7a60 (496 bytes) */
int gld_updateDrawBufferConfig(ctx)
  int ctx;
{
  int attachmentRegCursorFbo;
  uint drawBufferMask;
  uint packedFormatBits;
  uint loopIndex2;
  uint loopIndex;
  int remaining2;
  uint ctxWord1ae4;
  undefined *formatTable;
  int *drawFramebuffer;
  uint formatWordB;
  uint ctxWord1ae4_2;
  int attachmentRegCursor;
  int streamBase;
  int remaining;
  
  formatTable = ptrTo_textureFormatTable_001e88c8;
  streamBase = ctx + 0x240;
  ((unsigned char *)0x000015f8)[ctx] = ((unsigned char *)0x00002b7c)[ctx];
  ctxWord1ae4_2 = *(uint *)(ctx + 0x1ae4);
  packedFormatBits = *(uint *)(formatTable + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24 + 0x18);
  formatWordB = *(uint *)(formatTable + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24 + 0x1c);
  *(uint *)(ctx + 0x1ae4) = ctxWord1ae4_2 & 0xffc0003f;
  drawFramebuffer = *(int **)(*(int *)(ctx + 0x18) + 0x1a0);
  packedFormatBits = formatWordB >> 0xe & 0xc000 |
          formatWordB >> 0x12 & 0x3000 | (packedFormatBits & 6) << 9 | (packedFormatBits & 0x18) << 5 | packedFormatBits >> 5 & 0x1f;
  if (drawFramebuffer == (int *)0x0) {
    loopIndex = 0;
    remaining = 4;
    attachmentRegCursor = streamBase;
    do {
      if (*(short *)(((unsigned char *)0x00002dba) + loopIndex * 2 + *(int *)(ctx + 0x10)) == 0) {
        *(undefined4 *)(attachmentRegCursor + 0x233c) = 0xf;
      }
      else {
        *(uint *)(attachmentRegCursor + 0x233c) = packedFormatBits;
        *(uint *)(ctx + 0x1ae4) =
             ((*(uint *)(ctx + 0x1ae4) >> 6 | 1 << (loopIndex & 0x3f)) & 0xffff) << 6 |
             *(uint *)(ctx + 0x1ae4) & 0xffc0003f;
      }
      loopIndex = loopIndex + 1;
      attachmentRegCursor = attachmentRegCursor + 4;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  else {
    loopIndex2 = 0;
    remaining2 = 4;
    attachmentRegCursorFbo = streamBase;
    do {
      if (*(short *)(loopIndex2 * 2 + *drawFramebuffer + 0x90) == 0) {
        *(undefined4 *)(attachmentRegCursorFbo + 0x233c) = 0xf;
      }
      else {
        *(uint *)(attachmentRegCursorFbo + 0x233c) = packedFormatBits;
        *(uint *)(ctx + 0x1ae4) =
             ((*(uint *)(ctx + 0x1ae4) >> 6 | 1 << (loopIndex2 & 0x3f)) & 0xffff) << 6 |
             *(uint *)(ctx + 0x1ae4) & 0xffc0003f;
      }
      loopIndex2 = loopIndex2 + 1;
      attachmentRegCursorFbo = attachmentRegCursorFbo + 4;
      remaining2 = remaining2 + -1;
    } while (remaining2 != 0);
  }
  ctxWord1ae4 = *(uint *)(ctx + 0x1ae4);
  drawBufferMask = ctxWord1ae4 >> 6 & 0xffff;
  if (*(int *)(((unsigned char *)0x00001448) + drawBufferMask * 4 + streamBase) == 0) {
    gld_buildUnitSetupCmdList(streamBase,0,drawBufferMask);
    ctxWord1ae4 = *(uint *)(ctx + 0x1ae4);
  }
  if ((((ctxWord1ae4_2 >> 6 & 0xffff) != (ctxWord1ae4 >> 6 & 0xffff)) && ((ctxWord1ae4 & 0x3fffc0) != 0)) &&
     (((unsigned char *)0x0000430c)[*(int *)(ctx + 0x10)] == '\0')) {
    ffpsBuildProgram(streamBase,0);
    (**(code **)(((unsigned char *)0x00002b8c) + ctx))(streamBase,*(undefined4 *)(ctx + 0x209c));
  }
  *(uint *)(ctx + 0x1b70) = *(uint *)(ctx + 0x1b70) | 0x40;
  return;
}

/* gldMarkAllStateDirty @ 0xa7c60 (176 bytes) */
int gldMarkAllStateDirty(glContext)
  int glContext;
{
  int unitCursor;
  uint unitCount;
  
  unitCount = (uint)(byte)((unsigned char *)0x000013b5)[glContext];
  *(undefined1 *)(glContext + 0x2d) = 0xf;
  *(undefined1 *)(glContext + 0x2e) = 3;
  *(undefined1 *)(glContext + 0x30) = 7;
  *(undefined1 *)(glContext + 0x2c) = 0xff;
  *(undefined4 *)(glContext + 0x38) = 0x7ffff;
  *(undefined4 *)(glContext + 0x40) = 0x7ffff;
  *(undefined2 *)(glContext + 0x32) = 0xffff;
  *(undefined2 *)(glContext + 0x34) = 0xffff;
  *(undefined1 *)(glContext + 0x29) = 1;
  *(undefined4 *)(glContext + 0x3c) = 0x800015ff;
  *(undefined4 *)(glContext + 0x180c) = 5;
  *(undefined4 *)(glContext + 0x1810) = 0x1f;
  *(undefined1 *)(glContext + 0x2a) = 1;
  if (unitCount != 0) {
    unitCursor = glContext;
    if (unitCount == 0) {
      unitCount = 1;
    }
    do {
      *(undefined1 *)(unitCursor + 0x1814) = 0x3f;
      *(undefined1 *)(unitCursor + 0x181c) = 3;
      unitCursor = unitCursor + 1;
      unitCount = unitCount - 1;
    } while (unitCount != 0);
  }
  *(undefined1 *)(glContext + 0x29) = 1;
  *(undefined1 *)(glContext + 0x23ec) = 1;
  return;
}


/* issue #75 (follow-up #3): Ghidra recognized this as a THUNK - a pure trampoline stub that
 * just branches straight to the real function below, no different behavior or arguments - but
 * decls.h declares "thunk_FUN_xxx" as its own separate extern function that nothing in this
 * corpus ever DEFINES a body for. The stock ld apparently tolerated the resulting undefined
 * reference (never actually called in a way that mattered, or silently resolved some other
 * way); ld64 leaves it a real unresolved lazy symbol, crashing the moment this call path is
 * first taken. Real fix: alias the thunk name directly onto the real function, so calling
 * "thunk_FUN_xxx" IS calling FUN_xxx - which is exactly what the original binary's trampoline
 * did. */
asm(".globl _thunk_FUN_000a2330");
asm(".set _thunk_FUN_000a2330, _atifsReleaseShaderTable");
