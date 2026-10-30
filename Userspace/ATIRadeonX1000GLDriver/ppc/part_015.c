#include "decls.h"

/* FUN_000a1090 @ 0xa1090 (200 bytes) */
int FUN_000a1090(ctx, unitEnabled, unitTarget)
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

/* FUN_000a1160 @ 0xa1160 (48 bytes) */
int FUN_000a1160(ctx)
  int ctx;
{
  if (((ctx != -0x1134) && (*(int *)(((unsigned char *)0x00001144) + ctx) != 0)) &&
     (*(char *)(*(int *)(((unsigned char *)0x00001144) + ctx) + 0x74) != '\0')) {
    return ((unsigned char *)0x00001135)[ctx];
  }
  return 0;
}

/* FUN_000a11a0 @ 0xa11a0 (64 bytes) */
int FUN_000a11a0(ctx)
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

/* FUN_000a11f0 @ 0xa11f0 (192 bytes) */
int FUN_000a11f0(ctx, shader, passCount)
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
  int iVar1;
  
  if ((range != 0) && (((unsigned char *)0x00001134)[ctx] == '\0')) {
    iVar1 = **(int **)(((unsigned char *)0x00001154) + ctx);
    **(int **)(((unsigned char *)0x00001154) + ctx) = range + iVar1;
    return iVar1;
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
      if (!searching) goto LAB_000a1378;
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
LAB_000a1378:
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
    ((int (*)())FUN_000a11f0)(ctx,shaderOffset,*(undefined4 *)(shaderOffset + 4));
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
  int iVar2;
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
      if (!searching) goto LAB_000a161c;
      if (shaderId == *(int *)(loopIndex2 + *(int *)(shaderTable + 0x88))) {
        searching = false;
      }
      else {
        loopIndex = loopIndex + 1;
        loopIndex2 = loopIndex2 + 0x78;
      }
    }
    if (!searching) {
LAB_000a161c:
      ((int (*)())atifsFreeShader)(ctx,loopIndex * 0x78 + *(int *)(shaderTable + 0x88));
      iVar2 = loopIndex * 0x78 + *(int *)(shaderTable + 0x88);
      _memmove(iVar2,iVar2 + 0x78,(*(int *)(shaderTable + 4) - loopIndex) * 0x78 + -0x78);
      *(int *)(shaderTable + 4) = *(int *)(shaderTable + 4) + -1;
      if (loopIndex < *(uint *)(((unsigned char *)0x00001140) + ctx)) {
        iVar2 = *(uint *)(((unsigned char *)0x00001140) + ctx) - 1;
        *(int *)(((unsigned char *)0x00001140) + ctx) = iVar2;
        *(int *)(((unsigned char *)0x00001144) + ctx) = iVar2 * 0x78 + *(int *)(shaderTable + 0x88);
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
      goto LAB_000a1914;
    }
  }
  *(uint *)(shader + 4) = (byte)((unsigned char *)0x00001138)[ctx] + 1;
LAB_000a1914:
  ((int (*)())FUN_000a11f0)(ctx,*(int *)(((unsigned char *)0x00001144) + ctx),
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
      if ((int)(uint)(byte)((unsigned char *)0x000013b2)[ctx] < (int)(coord - 0x84c0U)) goto LAB_000a1b60;
    }
    else if (((5 < coord - 0x8921U) || (passIndex == 0)) ||
            ((swizzle != 0x8976 && (swizzle != 0x8978)))) goto LAB_000a1b60;
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
LAB_000a1b60:
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
      if ((int)(uint)(byte)((unsigned char *)0x000013b2)[ctx] < (int)(coordSource - 0x84c0U)) goto LAB_000a1cc0;
    }
    else if (((5 < coordSource - 0x8921U) || (passIndex == 0)) ||
            ((swizzle != 0x8976 && (swizzle != 0x8978)))) goto LAB_000a1cc0;
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
LAB_000a1cc0:
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
  int iVar5;
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
      iVar5 = shaderOffset + *(int *)(sharedTable + 0x88);
      oldProgramTable = *(undefined4 *)(iVar5 + 0x70);
      newProgramTable = (**(code **)(ctx + 0x10))(*(undefined4 *)(sharedTable + 0x8c),4);
      *(undefined4 *)(iVar5 + 0x70) = newProgramTable;
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

/* FUN_000a3560 @ 0xa3560 (164 bytes) */
uint FUN_000a3560(int glContext,double fpPassThrough1)
{
  uint uVar1;
  
  uVar1 = *(uint *)(((unsigned char *)0x000013e0) + glContext);
  if ((double)(float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x000013e0) + glContext) ^ 0x80000000) -
                     DOUBLE_001aa1e0) < fpPassThrough1) {
    uVar1 = *(uint *)(((unsigned char *)0x000013e4) + glContext);
    if (fpPassThrough1 <
        (double)(float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x000013e4) + glContext) ^ 0x80000000)
                       - DOUBLE_001aa1e0)) {
      uVar1 = (uint)(int)(fpPassThrough1 + (double)FLOAT_001aa10c);
    }
  }
  return uVar1;
}

/* FUN_000a3610 @ 0xa3610 (88 bytes) */
int FUN_000a3610(glContext, param_2, unusedArgR5, unusedArgR6, unusedArgR7, unusedArgR8, unusedArgR9)
  int glContext;
  uint param_2;
  undefined4 unusedArgR5;
  undefined4 unusedArgR6;
  undefined4 unusedArgR7;
  undefined4 unusedArgR8;
  undefined4 unusedArgR9;
{
  uint uVar1;
  int iVar2;
  uint glContextByte13b7;
  
  glContextByte13b7 = (uint)(byte)((unsigned char *)0x000013b7)[glContext];
  uVar1 = 1 << (glContextByte13b7 & 0x3f);
  if ((param_2 & uVar1) == 0) {
    iVar2 = glContextByte13b7 + 1;
    do {
      glContextByte13b7 = glContextByte13b7 - 1;
      iVar2 = iVar2 + -1;
      if (iVar2 == 0) {
        uVar1 = 1 << (glContextByte13b7 & 0x3f);
        break;
      }
      uVar1 = 1 << (glContextByte13b7 & 0x3f);
    } while ((param_2 & uVar1) == 0);
  }
  if ((int)param_2 <= (int)uVar1) {
    return uVar1;
  }
  return uVar1 << 1;
}

/* FUN_000a3670 @ 0xa3670 (48 bytes) */
int FUN_000a3670(glContext)
  int glContext;
{
  uint uVar1;
  
  if ((*(uint *)(glContext + 0x44) & 0x100000) == 0) {
    uVar1 = *(uint *)(glContext + 0xe8) & 1;
  }
  else {
    uVar1 = *(uint *)(glContext + 0x44) & 0x80;
  }
  if (uVar1 == 0) {
    return 0;
  }
  return 1;
}

/* FUN_000a36b0 @ 0xa36b0 (212 bytes) */
int FUN_000a36b0(glContext, param_2)
  int glContext;
  int param_2;
{
  float fVar1;
  
  if (param_2 != 0) {
    fVar1 = FLOAT_001aa0e8;
    if (*(short *)(((unsigned char *)0x00002e0e) + *(int *)(*(int *)(glContext + 4) + 0x10)) == 0x1102) {
      fVar1 = FLOAT_001aa108;
    }
    return (int)((float)((double)CONCAT44(0x43300000,*(undefined4 *)(glContext + 8)) - DOUBLE_001aa250
                        ) * FLOAT_001aa10c * (fVar1 + *(float *)(glContext + 0xe0)));
  }
  return (int)((float)((double)CONCAT44(0x43300000,*(undefined4 *)(glContext + 8)) - DOUBLE_001aa250)
               * FLOAT_001aa10c * *(float *)(glContext + 0xe0));
}

/* FUN_000a3790 @ 0xa3790 (716 bytes) */
void FUN_000a3790(undefined4 glContext,undefined4 unusedArgR4,uint param_3,int param_4,int *param_5,double fpPassThrough1,double fpPassThrough2,double fpPassThrough3,double fpPassThrough4,double fpPassThrough5,double fpPassThrough6,double fpPassThrough7,double fpPassThrough8,double fpPassThrough9,double fpPassThrough10,double fpPassThrough11,double fpPassThrough12)
{
  uint loopIndex3;
  float fVar1;
  uint loopIndex2;
  int iVar3;
  int loopIndex;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  char cStack_19;
  
  dVar5 = (double)FLOAT_001aa0e8;
  if (dVar5 <= fpPassThrough1) {
    dVar5 = (double)(float)((double)CONCAT44(0x43300000,(int)fpPassThrough1 ^ 0x80000000) -
                           DOUBLE_001aa1e0);
  }
  loopIndex = 0;
  dVar8 = (double)FLOAT_001aa0e8;
  iVar3 = ((int)param_3 >> 1) + (uint)((int)param_3 < 0 && (param_3 & 1) != 0);
  dVar6 = dVar8;
  if ((float)(fpPassThrough1 - dVar8) < 0.0) {
    dVar6 = fpPassThrough1;
  }
  if (-(float)(fpPassThrough1 - dVar8) < 0.0) {
    fpPassThrough1 = dVar6;
  }
  dVar6 = (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_001aa1e0);
  dVar7 = (double)(float)((double)CONCAT44(0x43300000,
                                           (int)(dVar6 / (double)(float)(dVar5 + (double)
                                                  FLOAT_001aa108)) ^ 0x80000000) - DOUBLE_001aa1e0);
  dVar5 = (double)(float)(fpPassThrough1 *
                         (double)(float)(dVar8 / (double)(float)(dVar7 * (double)(float)(dVar7 - 
                                                  dVar8))));
  if (0 < iVar3) {
    do {
      dVar8 = (double)FLOAT_001aa0d4;
      if (dVar7 <= dVar8) {
LAB_000a39f0:
        fVar1 = (float)(dVar8 * (double)FLOAT_001aa0f0);
      }
      else {
        loopIndex2 = 0;
        dVar9 = dVar8;
        do {
          dVar10 = (double)(float)((double)CONCAT44(0x43300000,
                                                    (int)((double)(float)((double)CONCAT44(
                                                  0x43300000,loopIndex2 + loopIndex ^ 0x80000000) -
                                                  DOUBLE_001aa1e0) - dVar7) ^ 0x80000000) -
                                  DOUBLE_001aa1e0);
          if ((dVar7 <= dVar10) && (dVar10 < (double)(float)(dVar6 - dVar7))) {
            dVar8 = (double)(float)(dVar5 * dVar9 + dVar8);
          }
          loopIndex2 = loopIndex2 + 1;
          dVar9 = (double)(float)((double)CONCAT44(0x43300000,loopIndex2 ^ 0x80000000) - DOUBLE_001aa1e0)
          ;
        } while (dVar9 < dVar7);
        loopIndex3 = 0;
        dVar9 = (double)FLOAT_001aa0d4;
        do {
          dVar10 = (double)(float)((double)CONCAT44(0x43300000,loopIndex3 + loopIndex ^ 0x80000000) -
                                  DOUBLE_001aa1e0);
          if ((dVar7 <= dVar10) && (dVar10 < (double)(float)(dVar6 - dVar7))) {
            dVar8 = (double)(float)(dVar5 * (double)((float)(dVar7 - dVar9) - FLOAT_001aa0e8) +
                                   dVar8);
          }
          loopIndex3 = loopIndex3 + 1;
          dVar9 = (double)(float)((double)CONCAT44(0x43300000,loopIndex3 ^ 0x80000000) - DOUBLE_001aa1e0)
          ;
        } while (dVar9 < dVar7);
        fVar1 = FLOAT_001aa0f0;
        if (dVar8 <= (double)FLOAT_001aa0e8) goto LAB_000a39f0;
      }
      cStack_19 = (char)(int)(fVar1 + FLOAT_001aa10c);
      *(char *)(loopIndex + param_4) = cStack_19;
    } while ((cStack_19 != -1) && (loopIndex = loopIndex + 1, iVar3 != loopIndex));
  }
  *param_5 = loopIndex;
  return;
}

/* FUN_000a3a60 @ 0xa3a60 (372 bytes) */
void FUN_000a3a60(undefined4 glContext,undefined4 unusedArgR4,uint param_3,int param_4,uint *param_5,double fpPassThrough1,double fpPassThrough2,double fpPassThrough3,double fpPassThrough4,double fpPassThrough5,double fpPassThrough6,double fpPassThrough7,double fpPassThrough8,double fpPassThrough9,double fpPassThrough10,double fpPassThrough11,double fpPassThrough12,double fpPassThrough13)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  uint loopIndex;
  double dVar7;
  double dVar8;
  double dVar9;
  
  dVar5 = DOUBLE_001aa1e0;
  fVar4 = FLOAT_001aa10c;
  dVar7 = (double)FLOAT_001aa0e8;
  if (dVar7 <= fpPassThrough1) {
    dVar7 = (double)(float)((double)CONCAT44(0x43300000,(int)fpPassThrough1 ^ 0x80000000) -
                           DOUBLE_001aa1e0);
  }
  dVar8 = (double)FLOAT_001aa0e8;
  loopIndex = 0;
  dVar9 = dVar8;
  if ((float)(fpPassThrough1 - dVar8) < 0.0) {
    dVar9 = fpPassThrough1;
  }
  if (-(float)(fpPassThrough1 - dVar8) < 0.0) {
    fpPassThrough1 = dVar9;
  }
  fVar1 = (float)((double)CONCAT44(0x43300000,
                                   (int)(((float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000)
                                                 - DOUBLE_001aa1e0) * FLOAT_001aa10c) /
                                        (float)(dVar7 + dVar8)) ^ 0x80000000) - DOUBLE_001aa1e0);
  fVar1 = fVar1 + fVar1;
  fVar3 = FLOAT_001aa0f0 / fVar1;
  fVar2 = FLOAT_001aa0d4;
  while (fVar2 < fVar1) {
    *(char *)(param_4 + loopIndex) = (char)(int)((float)(fpPassThrough1 * (double)fVar3) * fVar2 + fVar4);
    loopIndex = loopIndex + 1;
    fVar2 = (float)((double)CONCAT44(0x43300000,loopIndex ^ 0x80000000) - dVar5);
  }
  if ((int)loopIndex < (int)(((int)param_3 >> 1) + (uint)((int)param_3 < 0 && (param_3 & 1) != 0))) {
    *(undefined1 *)(loopIndex + param_4) = 0xff;
  }
  *param_5 = loopIndex;
  return;
}

/* FUN_000a3be0 @ 0xa3be0 (2056 bytes) */
int FUN_000a3be0(glContext, primitiveMode, param_3, unusedArgR6, param_5, extraArg5, staleArgR9)
  uint glContext;
  int primitiveMode;
  uint param_3;
  undefined4 unusedArgR6;
  uint param_5;
  undefined4 *extraArg5;
  undefined4 staleArgR9;
{
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
  bool bVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined4 glContextWord1f2c;
  uint uVar14;
  uint loopIndex4;
  int iVar16;
  
  if (*(int *)(glContext + 0x277c) == primitiveMode) {
    return;
  }
  *(int *)(glContext + 0x277c) = primitiveMode;
  bVar1 = *(int *)(glContext + 0x2768) == 0;
  uVar10 = (uint)*(ushort *)(glContext + 0x1b52);
  *(uint *)(glContext + 0x1b50) = uVar10;
  if (bVar1) {
    if ((*(uint *)(glContext + 0x44) & 0x20000000) == 0) {
      return;
    }
  }
  else if ((primitiveMode != 0) || ((*(uint *)(glContext + 0x44) & 0x20000000) == 0)) {
    *(uint *)(glContext + 0x1b50) = uVar10;
    param_5 = primitiveMode * 4 + *(int *)(glContext + 0x2768);
    uVar14 = *(uint *)(&DAT_001aa7a8 + primitiveMode * 4);
    *(uint *)(glContext + 0x1b50) =
         uVar10 | *(int *)(param_5 + 0xe8) << (*(int *)(glContext + 0x276c) * 2 + 0x10U & 0x3f);
    uVar5 = *(uint *)(param_5 + 0x110);
    *(uint *)(glContext + 0x1b64) = uVar14 & 3 | *(uint *)(glContext + 0x1b64) & 0xfffffffc;
    *(undefined4 *)(glContext + 0x1b68) = 0;
    extraArg5 = (undefined4 *)(uVar5 & 0x10 | *(uint *)(glContext + 0x1a64) & 0xffffffef);
    *(undefined4 **)(glContext + 0x1a64) = extraArg5;
    FUN_0004b190(glContext,*(undefined4 *)(param_5 + 0xc0));
  }
  *(undefined4 *)(glContext + 0x1ba8) = *(undefined4 *)(glContext + 0x1ba0);
  if (!bVar1) goto LAB_000a41d0;
  if ((*(uint *)(glContext + 0x44) & 0x100000) == 0) {
    ffvpComputeOutputMasks(glContext);
  }
  else {
    FUN_00064720(glContext);
  }
  (**(code **)(((unsigned char *)0x00001334) + glContext))(glContext,1);
  glContextWord44 = *(uint *)(glContext + 0x44);
  glContextWord1ba4 = *(uint *)(glContext + 0x1ba4);
  *(uint *)(glContext + 0x1ba0) = glContextWord1ba4;
  bVar2 = (glContextWord44 >> 0x1d & 1) == 0;
  *(uint *)(glContext + 0x1a64) = *(uint *)(glContext + 0x1a64) & 0xffffffef;
  if ((bVar2) || ((*(uint *)(glContext + 0x8c) & 0x40000000) != 0)) {
    if ((glContextWord44 & 0x40000000) == 0) {
      *(uint *)(glContext + 0x1b50) = (uint)*(ushort *)(glContext + 0x1b52);
    }
    else if ((!bVar2) && ((*(uint *)(glContext + 0x8c) & 0x40000000) != 0)) {
      *(undefined4 *)(glContext + 0x1bc0) = 0;
      *(uint *)(glContext + 0x1b50) = (uint)*(ushort *)(glContext + 0x1b52);
    }
  }
  else {
    if (primitiveMode == 0) {
      if ((glContextWord44 & 0x20000) == 0) {
        if (((unsigned char *)0x000013b2)[glContext] == '\0') goto LAB_000a40f0;
        uVar10 = 0;
        param_3 = 0;
        loopIndex4 = 0;
        loopIndex6 = 0x10;
        loopIndex8 = 0;
        uVar5 = glContext;
        do {
          if ((((*(uint *)(uVar5 + 0x48) & 0x1f) == 0) ||
              ((1 << (param_3 & 0x3f) & *(uint *)(glContext + 0xec)) == 0)) ||
             (*(int *)(((unsigned char *)0x000013f8) + uVar5) == 0)) {
            iVar16 = (int)(char)uVar10;
            iVar11 = param_3 * 4 + glContext;
            param_5 = iVar16 + 2;
            *(uint *)(iVar11 + 0x1ee8) =
                 (iVar16 + 3) * 0x40000 & 0xfc0000U |
                 param_5 * 0x1000 & 0x3f000 |
                 (iVar16 + 1) * 0x40 & 0xfc0U |
                 uVar10 & 0x3f | *(uint *)(iVar11 + 0x1ee8) & 0xff000000;
            *(uint *)(glContext + 0x1b50) = *(uint *)(glContext + 0x1b50) & ~(1 << (loopIndex6 & 0x3f));
            *(uint *)(glContext + 0x1bc0) = *(uint *)(glContext + 0x1bc0) & ~(1 << (loopIndex8 & 0x3f));
            uVar10 = uVar10 + (*(uint *)(glContext + 0x1ba0) >> (loopIndex4 & 0x3f) & 7);
          }
          else {
            iVar16 = uVar10 + 1;
            *(uint *)(glContext + 0x1a64) = *(uint *)(glContext + 0x1a64) | 0x10;
            *(uint *)(glContext + 0x1b50) = 1 << (loopIndex6 & 0x3f) | *(uint *)(glContext + 0x1b50);
            *(uint *)(glContext + 0x1bc0) = 1 << (loopIndex8 & 0x3f) | *(uint *)(glContext + 0x1bc0);
            iVar11 = param_3 * 4 + glContext;
            glContextWord1ba4 = glContextWord1ba4 & ~(7 << (loopIndex4 & 0x3f));
            uVar4 = uVar10 & 0x3f;
            uVar10 = uVar10 + 2;
            *(uint *)(iVar11 + 0x1ee8) =
                 iVar16 * 0x40 & 0xfc0U | uVar4 | *(uint *)(iVar11 + 0x1ee8) & 0xff000000 | 0xffe000
            ;
          }
          param_3 = param_3 + 1;
          uVar5 = uVar5 + 4;
          loopIndex4 = loopIndex4 + 3;
          loopIndex6 = loopIndex6 + 2;
          loopIndex8 = loopIndex8 + 2;
        } while ((int)param_3 < (int)(uint)(byte)((unsigned char *)0x000013b2)[glContext]);
      }
      else {
        if ((glContextWord44 & 0x2000) == 0) {
          bVar3 = ((unsigned char *)0x00001135)[glContext];
        }
        else {
          bVar3 = ((unsigned char *)0x000011d3)[glContext];
        }
        glContextWordec = *(uint *)(glContext + 0xec);
        if (((unsigned char *)0x000013b2)[glContext] == '\0') {
LAB_000a40f0:
          uVar5 = 0;
          goto LAB_000a40f4;
        }
        uVar10 = 0;
        param_3 = 0;
        loopIndex5 = 0;
        loopIndex7 = 0x10;
        loopIndex9 = 0;
        param_5 = glContext + 0x1ee0;
        do {
          if (((bVar3 & glContextWordec) >> (param_3 & 0x3f) & 1) == 0) {
            iVar11 = (int)(char)uVar10;
            *(uint *)(param_5 + 8) =
                 (iVar11 + 3) * 0x40000 & 0xfc0000U |
                 (iVar11 + 2) * 0x1000 & 0x3f000U |
                 (iVar11 + 1) * 0x40 & 0xfc0U | uVar10 & 0x3f | *(uint *)(param_5 + 8) & 0xff000000;
            *(uint *)(glContext + 0x1b50) = *(uint *)(glContext + 0x1b50) & ~(1 << (loopIndex7 & 0x3f));
            *(uint *)(glContext + 0x1bc0) = *(uint *)(glContext + 0x1bc0) & ~(1 << (loopIndex9 & 0x3f));
            uVar10 = uVar10 + (*(uint *)(glContext + 0x1ba0) >> (loopIndex5 & 0x3f) & 7);
          }
          else {
            *(uint *)(glContext + 0x1a64) = *(uint *)(glContext + 0x1a64) | 0x10;
            *(uint *)(glContext + 0x1b50) = 1 << (loopIndex7 & 0x3f) | *(uint *)(glContext + 0x1b50);
            iVar11 = uVar10 + 1;
            *(uint *)(glContext + 0x1bc0) = 1 << (loopIndex9 & 0x3f) | *(uint *)(glContext + 0x1bc0);
            glContextWord1ba4 = glContextWord1ba4 & ~(7 << (loopIndex5 & 0x3f));
            uVar4 = uVar10 & 0x3f;
            uVar10 = uVar10 + 2;
            *(uint *)(param_5 + 8) =
                 iVar11 * 0x40 & 0xfc0U | uVar4 | *(uint *)(param_5 + 8) & 0xff000000 | 0xffe000;
          }
          param_3 = param_3 + 1;
          param_5 = param_5 + 4;
          loopIndex5 = loopIndex5 + 3;
          loopIndex7 = loopIndex7 + 2;
          loopIndex9 = loopIndex9 + 2;
        } while ((int)param_3 < (int)(uint)(byte)((unsigned char *)0x000013b2)[glContext]);
      }
      uVar5 = uVar10 & 0xff;
    }
    else {
      if (*(int *)(glContext + 0x2768) != 0) goto LAB_000a40f0;
      if ((glContextWord44 & 0x20000) == 0) {
        glContextPtr13b2 = (uint)(byte)((unsigned char *)0x000013b2)[glContext];
        if (glContextPtr13b2 == 0) goto LAB_000a40d4;
        uVar10 = 0;
        loopIndex = 0;
        param_5 = glContext;
        do {
          if (((*(uint *)(param_5 + 0x48) & 0x1f) != 0) && (*(int *)(((unsigned char *)0x000013f8) + param_5) != 0))
          {
            iVar12 = (int)(char)uVar10;
            iVar16 = loopIndex * 4 + glContext;
            *(uint *)(iVar16 + 0x1ee8) =
                 (iVar12 + 3) * 0x40000 & 0xfc0000U |
                 (iVar12 + 2) * 0x1000 & 0x3f000U |
                 (iVar12 + 1) * 0x40 & 0xfc0U |
                 uVar10 & 0x3f | *(uint *)(iVar16 + 0x1ee8) & 0xff000000;
            glContextPtr13b2 = (uint)(byte)((unsigned char *)0x000013b2)[glContext];
          }
          uVar7 = loopIndex * 3;
          loopIndex = loopIndex + 1;
          param_5 = param_5 + 4;
          uVar10 = uVar10 + (*(uint *)(glContext + 0x1ba0) >> (uVar7 & 0x3f) & 7);
        } while (loopIndex < (int)glContextPtr13b2);
      }
      else {
        if ((glContextWord44 & 0x2000) == 0) {
          bVar3 = ((unsigned char *)0x00001135)[glContext];
        }
        else {
          bVar3 = ((unsigned char *)0x000011d3)[glContext];
        }
        param_3 = (uint)bVar3;
        glContextPtr13b2 = (uint)(byte)((unsigned char *)0x000013b2)[glContext];
        if (glContextPtr13b2 == 0) {
LAB_000a40d4:
          uVar10 = 0;
        }
        else {
          uVar10 = 0;
          loopIndex2 = 0;
          param_5 = 0;
          iVar11 = glContext + 0x1ee0;
          do {
            if ((bVar3 >> (loopIndex2 & 0x3f) & 1) != 0) {
              iVar16 = (int)(char)uVar10;
              *(uint *)(iVar11 + 8) =
                   (iVar16 + 3) * 0x40000 & 0xfc0000U |
                   (iVar16 + 2) * 0x1000 & 0x3f000U |
                   (iVar16 + 1) * 0x40 & 0xfc0U | uVar10 & 0x3f | *(uint *)(iVar11 + 8) & 0xff000000
              ;
              glContextPtr13b2 = (uint)(byte)((unsigned char *)0x000013b2)[glContext];
            }
            loopIndex2 = loopIndex2 + 1;
            iVar11 = iVar11 + 4;
            uVar9 = param_5 & 0x3f;
            param_5 = param_5 + 3;
            uVar10 = uVar10 + (*(uint *)(glContext + 0x1ba0) >> uVar9 & 7);
          } while ((int)loopIndex2 < (int)glContextPtr13b2);
        }
      }
      uVar5 = uVar10 & 0xff;
      *(undefined4 *)(glContext + 0x1bc0) = 0;
      *(uint *)(glContext + 0x1b50) = (uint)*(ushort *)(glContext + 0x1b52);
    }
LAB_000a40f4:
    *(uint *)(glContext + 0x1f2c) = uVar5 & 0x7f | *(uint *)(glContext + 0x1f2c) & 0xffffff80;
    puVar8 = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,0xd);
    *(undefined4 **)(0x00002748 + glContext + 4) = puVar8;
    extraArg5 = puVar8 + 5;
    loopIndex3 = 0;
    *puVar8 = ((unsigned char *)0x000010c0U);
    remaining2 = 8;
    glContextWord1f2c = *(undefined4 *)(glContext + 0x1f2c);
    puVar8[2] = 0x825;
    puVar8[1] = glContextWord1f2c;
    puVar8[3] = *(undefined4 *)(glContext + 0x1ba0);
    puVar8[4] = *(uint *)(glContext + 0x1f28) | 0x70000;
    uVar5 = glContext;
    do {
      puVar8 = (undefined4 *)(uVar5 + 0x1ee8);
      uVar5 = uVar5 + 4;
      *(undefined4 *)((int)extraArg5 + loopIndex3) = *puVar8;
      loopIndex3 = loopIndex3 + 4;
      remaining2 = remaining2 + -1;
    } while (remaining2 != 0);
    iVar11 = *(int *)(0x00002748 + glContext + 4);
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x275c);
    *(int *)(0x00002748 + glContext + 4) = iVar11 + 0x34;
    (*UNRECOVERED_JUMPTABLE)(glContext,iVar11 + 0x34);
  }
  *(uint *)(glContext + 0x1ba8) = glContextWord1ba4;
LAB_000a41d0:
  puVar8 = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,0xc);
  *(undefined4 **)(0x00002748 + glContext + 4) = puVar8;
  *puVar8 = ((unsigned char *)0x00001002U);
  glContextWord1b50 = *(undefined4 *)(glContext + 0x1b50);
  puVar8[2] = 0x825;
  puVar8[1] = glContextWord1b50;
  glContextWord1ba0 = *(undefined4 *)(glContext + 0x1ba0);
  puVar8[4] = ((unsigned char *)0x00001007U);
  puVar8[3] = glContextWord1ba0;
  glContextWord1a64 = *(undefined4 *)(glContext + 0x1a64);
  puVar8[6] = ((unsigned char *)0x0000108eU);
  puVar8[5] = glContextWord1a64;
  glContextWord1b64 = *(undefined4 *)(glContext + 0x1b64);
  puVar8[8] = ((unsigned char *)0x00001098U);
  puVar8[7] = glContextWord1b64;
  glContextWord1b68 = *(undefined4 *)(glContext + 0x1b68);
  puVar8[10] = ((unsigned char *)0x000010c0U);
  puVar8[9] = glContextWord1b68;
  puVar8[0xb] = *(undefined4 *)(glContext + 0x1f2c);
  iVar11 = *(int *)(0x00002748 + glContext + 4);
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x275c);
  *(int *)(0x00002748 + glContext + 4) = iVar11 + 0x30;
  (*UNRECOVERED_JUMPTABLE)(glContext,iVar11 + 0x30,param_3,uVar10,param_5,extraArg5,glContextWord1b68);
  if (*(char *)(glContext + 0x1868) != '\0') {
    puVar8 = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,9);
    *puVar8 = 0x7101d;
    *(undefined4 **)(0x00002748 + glContext + 4) = puVar8 + 1;
    remaining = 8;
    uVar10 = glContext;
    do {
      puVar6 = *(undefined4 **)(0x00002748 + glContext + 4);
      puVar8 = (undefined4 *)(uVar10 + 0x1ee8);
      uVar10 = uVar10 + 4;
      *puVar6 = *puVar8;
      *(undefined4 **)(0x00002748 + glContext + 4) = puVar6 + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
    /* dropped 2nd arg, same defect class as gld_startPacket (issue #64) - stock stores the
     * just-advanced pointer to +0x274c then loads it right back into r4 before the bctr
     * tail-jump. */
    (**(code **)(glContext + 0x275c))(glContext,puVar6 + 1);
  }
  if (bVar1) {
    (**(code **)(((unsigned char *)0x00001330) + glContext))(glContext,0xc0100000);
  }
  if (*(int *)(glContext + 0x1ba8) == *(int *)(glContext + 0x1ba0)) {
    return;
  }
  puVar8 = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,2);
  *(undefined4 **)(0x00002748 + glContext + 4) = puVar8;
  *puVar8 = ((unsigned char *)0x00001001U);
  *(undefined4 *)(*(int *)(0x00002748 + glContext + 4) + 4) = *(undefined4 *)(glContext + 0x1ba8);
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x275c);
  *(int *)(0x00002748 + glContext + 4) = *(int *)(0x00002748 + glContext + 4) + 8;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(glContext,*(int *)(0x00002748 + glContext + 4));
  return;
}

/* FUN_000a43f0 @ 0xa43f0 (148 bytes) */
int FUN_000a43f0(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(glContext + 0x2764);
  while (iVar1 != 0) {
    if (*(int *)(iVar1 + 0xbc) != 0) {
      FUN_00030a50(glContext,*(undefined4 *)(*(int *)(iVar1 + 0xbc) + 0x7c));
    }
    iVar2 = *(int *)(iVar1 + 0x138);
    (**(code **)(glContext + 0x18))(iVar1);
    iVar1 = iVar2;
  }
  *(undefined4 *)(glContext + 0x2778) = 0;
  *(undefined4 *)(glContext + 0x2764) = 0;
  *(undefined4 *)(glContext + 0x2768) = 0;
  return;
}

/* FUN_000a4490 @ 0xa4490 (184 bytes) */
int FUN_000a4490(glContext)
  int glContext;
{
  int glContextPtr2764;
  
  for (glContextPtr2764 = *(int *)(glContext + 0x2764); glContextPtr2764 != 0; glContextPtr2764 = *(int *)(glContextPtr2764 + 0x138)) {
    if ((*(int *)(glContextPtr2764 + 0xbc) != 0) && (-1 < *(int *)(glContext + 0x276c))) {
      FUN_000309c0(glContext,0,*(int *)(glContext + 0x276c));
    }
  }
  *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x200;
  *(ushort *)(glContext + 0x32) =
       (ushort)(1 << (*(uint *)(glContext + 0x276c) & 0x3f)) | *(ushort *)(glContext + 0x32);
  *(ushort *)(glContext + 0x34) =
       (ushort)(1 << (*(uint *)(glContext + 0x276c) & 0x3f)) | *(ushort *)(glContext + 0x34);
  return;
}

/* FUN_000a4550 @ 0xa4550 (372 bytes) */
int FUN_000a4550(glContext)
  int glContext;
{
  int loopIndex3;
  int glContextPtr112c;
  uint uVar1;
  int iVar2;
  uint loopIndex;
  int loopIndex2;
  int glContextPtr1154;
  
  glContextPtr1154 = *(int *)(((unsigned char *)0x00001154) + glContext);
  uVar1 = *(uint *)(glContextPtr1154 + 4);
  if (uVar1 != 0) {
    loopIndex = 0;
    loopIndex2 = 0;
    do {
      iVar2 = *(int *)(*(int *)(((unsigned char *)0x0000113c) + glContext) * 4 +
                      *(int *)(loopIndex2 + *(int *)(glContextPtr1154 + 0x88) + 0x70));
      if (iVar2 != 0) {
        *(undefined4 *)(((unsigned char *)0x000015cc) + iVar2) = 1;
        uVar1 = *(uint *)(glContextPtr1154 + 4);
      }
      loopIndex = loopIndex + 1;
      loopIndex2 = loopIndex2 + 0x78;
    } while (loopIndex < uVar1);
  }
  glContextPtr112c = *(int *)(((unsigned char *)0x0000112c) + glContext);
  uVar1 = *(uint *)(glContextPtr112c + 4);
  if (uVar1 != 0) {
    loopIndex = 0;
    loopIndex3 = 0;
    do {
      iVar2 = loopIndex3 + *(int *)(glContextPtr112c + 8);
      if ((*(int *)(iVar2 + 4) == 0x8804) &&
         (iVar2 = *(int *)(*(int *)(((unsigned char *)0x00001130) + glContext) * 4 +
                          *(int *)(*(int *)(iVar2 + 0x14) + 0x70)), iVar2 != 0)) {
        *(undefined4 *)(((unsigned char *)0x000015cc) + iVar2) = 1;
        uVar1 = *(uint *)(glContextPtr112c + 4);
      }
      loopIndex = loopIndex + 1;
      loopIndex3 = loopIndex3 + 0x18;
    } while (loopIndex < uVar1);
  }
  FUN_0004b190(glContext,0);
  *(uint *)(glContext + 0x1b50) = (uint)*(ushort *)(glContext + 0x1b52);
  *(uint *)(glContext + 0x1a64) = *(uint *)(glContext + 0x1a64) & 0xffffffef;
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x2000;
  ((int (*)())FUN_000a4490)(glContext);
  *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x200;
  *(undefined1 *)(glContext + 0x29) = 1;
  *(ushort *)(glContext + 0x34) =
       (ushort)(1 << (*(uint *)(glContext + 0x276c) & 0x3f)) | *(ushort *)(glContext + 0x34);
  *(undefined4 *)(glContext + 0x276c) = 0xffffffff;
  *(undefined4 *)(glContext + 0x2768) = 0;
  return;
}

/* FUN_000a46d0 @ 0xa46d0 (144 bytes) */
int FUN_000a46d0(glContext)
  int glContext;
{
  if (*(int *)(glContext + 0x2768) != 0) {
    FUN_000309c0(glContext,*(undefined4 *)(*(int *)(*(int *)(glContext + 0x2768) + 0xbc) + 0x7c),
                 *(undefined4 *)(glContext + 0x276c));
    *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x200;
    *(ushort *)(glContext + 0x32) =
         (ushort)(1 << (*(uint *)(glContext + 0x276c) & 0x3f)) | *(ushort *)(glContext + 0x32);
    *(ushort *)(glContext + 0x34) =
         (ushort)(1 << (*(uint *)(glContext + 0x276c) & 0x3f)) | *(ushort *)(glContext + 0x34);
  }
  return 1;
}

/* FUN_000a4760 @ 0xa4760 (8 bytes) */
int FUN_000a4760(ctx)
  int ctx;
{
  return *(undefined4 *)(ctx + 0x29ac);
}

/* FUN_000a4770 @ 0xa4770 (504 bytes) */
int FUN_000a4770(glContext, unusedArgR4, staleArgR5, staleArgR6, staleArgR7, staleArgR8, staleArgR9)
  int glContext;
  undefined4 unusedArgR4;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  undefined4 staleArgR9;
{
  float glContextFloat13e8;
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int glContextPtr4;
  int glContextWord8;
  int iVar7;
  
  glContextPtr4 = *(int *)(glContext + 4);
  glContextWord8 = *(int *)(glContext + 8);
  iVar7 = *(int *)(glContextPtr4 + 0x10);
  if (((((unsigned char *)0x00002e2d)[iVar7] == '\0') || ((*(uint *)(glContext + 0x44) & 0x20000) != 0)) ||
     (glContextPtr4 = FUN_0001a010(glContextPtr4,*(undefined4 *)(glContextPtr4 + 0x26a0),staleArgR5,staleArgR6,staleArgR7,staleArgR8,
                           staleArgR9), glContextPtr4 != 0)) {
    uVar4 = *(uint *)(((unsigned char *)0x000013e0) + glContext);
    fVar1 = *(float *)(((unsigned char *)0x00002e20) + iVar7);
    if (((float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - DOUBLE_001aa1e0) < fVar1) &&
       (uVar4 = *(uint *)(((unsigned char *)0x000013e4) + glContext),
       fVar1 < (float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x000013e4) + glContext) ^ 0x80000000)
                      - DOUBLE_001aa1e0))) {
      uVar4 = (uint)(int)(fVar1 + FLOAT_001aa10c);
    }
    uVar4 = glContextWord8 * uVar4 >> 1;
  }
  else {
    fVar1 = *(float *)(((unsigned char *)0x00002e20) + iVar7);
    glContextFloat13e8 = *(float *)(((unsigned char *)0x000013e8) + glContext);
    fVar3 = glContextFloat13e8;
    if ((glContextFloat13e8 < fVar1) &&
       (fVar3 = *(float *)(((unsigned char *)0x000013ec) + glContext), fVar1 < *(float *)(((unsigned char *)0x000013ec) + glContext))) {
      fVar3 = *(float *)(((unsigned char *)0x000013f0) + glContext) *
              (float)((double)CONCAT44(0x43300000,
                                       (int)((fVar1 - glContextFloat13e8) / *(float *)(((unsigned char *)0x000013f0) + glContext) +
                                            FLOAT_001aa10c) ^ 0x80000000) - DOUBLE_001aa1e0) + glContextFloat13e8
      ;
    }
    fVar1 = fVar3;
    if (fVar3 - FLOAT_001aa0e8 < 0.0) {
      fVar1 = FLOAT_001aa0e8;
    }
    if (-(fVar3 - FLOAT_001aa0e8) < 0.0) {
      fVar1 = fVar3;
    }
    fVar2 = FLOAT_001aa0e8;
    if (*(short *)(((unsigned char *)0x00002e10) + iVar7) == 0x1102) {
      fVar2 = FLOAT_001aa108;
    }
    uVar4 = (uint)(int)((float)((double)CONCAT44(0x43300000,glContextWord8) - DOUBLE_001aa250) * FLOAT_001aa10c *
                  (fVar1 + fVar2));
  }
  return uVar4;
}

/* FUN_000a4980 @ 0xa4980 (4768 bytes) */
int FUN_000a4980(glContext, unusedArgR4, staleArgR5, staleArgR6, staleArgR7)
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
  float fVar11;
  float colCoord;
  float colCoord2;
  char cVar14;
  undefined1 maskValue;
  uint uVar16;
  uint *puVar17;
  int iVar18;
  undefined2 uVar20;
  int fillCol;
  undefined4 uVar21;
  uint r4AfterCall;
  undefined4 r4AfterCall2;
  undefined4 r4AfterCall3;
  uint r4AfterCall4;
  uint r4AfterCall5;
  char *pcVar22;
  int *entryWord14High;
  undefined4 staleArgR8;
  char *pcVar24;
  uint levelCount;
  uint levelCountClamped;
  undefined4 entryFlag15;
  undefined1 *mirrorDst;
  undefined4 uVar29;
  uint uVar30;
  char cVar31;
  char cVar32;
  uint maskHeight;
  uint uVar34;
  uint maskWidth;
  int iVar36;
  undefined4 glContextWord4;
  int iVar38;
  char *cacheEntry;
  int iVar40;
  int iVar41;
  int iVar42;
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
  undefined8 uVar47;
  undefined8 uVar48;
  ulonglong uVar49;
  float distSq;
  double staleStackArg_fffffeb8;
  double staleStackArg_fffffec0;
  double staleStackArg_fffffec8;
  double staleStackArg_fffffed0;
  double staleStackArg_fffffed8;
  int local_118 [4];
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
      glContextPtr4_2 = FUN_0001a010(glContextPtr4_2,*(undefined4 *)(glContextPtr4_2 + 0x26a0),staleArgR5,staleArgR6,staleArgR7,staleArgR8,
                            glContextWord44);
      if (glContextPtr4_2 == 0) goto LAB_000a4a50;
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
      ((int (*)())FUN_000a4550)(glContext);
      return 0;
    }
  }
LAB_000a4a50:
  glContextPtr276c = *(uint *)(glContext + 0x276c);
  glContextWord38 = *(uint *)(glContext + 0x38);
  if (-1 < (int)glContextPtr276c) {
    uVar16 = glContextWord38 & 0x10310e | (int)(uint)*(ushort *)(glContext + 0x34) >> (glContextPtr276c & 0x3f) & 1U;
  }
  else {
    uVar16 = 1;
  }
  if (uVar16 == 0 && *(int *)(glContext + 0x2458) == 0) {
    return 0;
  }
  glContextByte13b2 = (uint)(byte)((unsigned char *)0x000013b2)[glContext];
  uVar16 = glContextByte13b2 - 1;
  if (-1 < (int)uVar16) {
    puVar17 = (uint *)(uVar16 * 4 + glContext + 0x48);
    do {
      if ((((*puVar17 & 0x1f) == 0) || (puVar17[0x4ec] == 0)) &&
         ((uVar34 = *(uint *)(glContext + 0x44), (uVar34 & 0x2000) == 0 ||
          (((((int)(uint)(byte)((unsigned char *)0x000011d3)[glContext] >> (uVar16 & 0x3f) & 1U) == 0 &&
            (((uVar34 & 0x800) == 0 || ((byte)((unsigned char *)0x000011d1)[glContext] != uVar16)))) &&
           (((uVar34 & 0x400) == 0 || ((byte)((unsigned char *)0x000011d2)[glContext] != uVar16)))))))) break;
      uVar16 = uVar16 - 1;
      puVar17 = puVar17 + -1;
      glContextByte13b2 = glContextByte13b2 - 1;
    } while (glContextByte13b2 != 0);
  }
  if (-1 < (int)glContextPtr276c) {
    pcVar24 = (char *)(1 << (glContextPtr276c & 0x3f));
  }
  else {
    pcVar24 = (char *)0x0;
  }
  if (-1 < (int)uVar16) {
    pcVar24 = (char *)((uint)pcVar24 | 1 << (uVar16 & 0x3f));
  }
  if (pcVar24 != (char *)0x0) {
    glContextWord38 = glContextWord38 | 0x200;
    *(uint *)(glContext + 0x38) = glContextWord38;
    *(ushort *)(glContext + 0x32) = (ushort)pcVar24 | *(ushort *)(glContext + 0x32);
    *(ushort *)(glContext + 0x34) = (ushort)pcVar24 | *(ushort *)(glContext + 0x34);
  }
  *(uint *)(glContext + 0x276c) = uVar16;
  if ((int)uVar16 < 0) goto LAB_000a52dc;
  glContextPtr4_3 = *(int *)(glContext + 4);
  glContextByte245b = *(char *)(glContext + 0x245b);
  engineState = *(int *)(glContextPtr4_3 + 0x10);
  uVar16 = *(uint *)(glContext + 0x44) & 0x60020000 ^ 0x40000000;
  pcVar22 = (char *)-uVar16;
  glContextPtr4_3 = FUN_0001a010(glContextPtr4_3,*(undefined4 *)(glContextPtr4_3 + 0x26a0),staleArgR5,staleArgR6,pcVar22,pcVar24,
                        glContextWord38);
  uVar47 = ((int (*)())FUN_000a36b0)(glContext,(uint)(glContextPtr4_3 == 0));
  uVar21 = (undefined4)uVar47;
  glContextPtr4_4 = *(int *)(glContext + 4);
  engineStateShort2e0e = *(short *)(((unsigned char *)0x00002e0e) + engineState);
  engineState3 = *(uint *)(glContextPtr4_4 + 0x10);
  if ((((unsigned char *)0x00002e2d)[engineState3] == '\0') || ((*(uint *)(glContext + 0x44) & 0x20000) != 0)) {
LAB_000a4c38:
    cVar14 = '\0';
  }
  else {
    uVar48 = FUN_0001a010(glContextPtr4_4,*(undefined4 *)(glContextPtr4_4 + 0x26a0),staleArgR5,staleArgR6,pcVar22,pcVar24,
                          engineState3);
    uVar21 = (undefined4)uVar48;
    if ((int)((ulonglong)uVar48 >> 0x20) != 0) {
      glContextPtr4_4 = *(int *)(glContext + 4);
      goto LAB_000a4c38;
    }
    glContextPtr4_4 = *(int *)(glContext + 4);
    cVar14 = '\x01';
  }
  if (((((unsigned char *)0x00002e2c)[*(int *)(glContextPtr4_4 + 0x10)] == '\0') ||
      ((*(uint *)(glContext + 0x44) & 0x20000) != 0)) ||
     (cVar31 = '\x01', *(short *)(((unsigned char *)0x00002e28) + *(int *)(glContextPtr4_4 + 0x10)) == -1)) {
    cVar31 = '\0';
  }
  iVar41 = ((int (*)())FUN_000a4770)(glContext,uVar21,staleArgR5,staleArgR6,pcVar22,pcVar24,engineState3);
  engineStateFloat2e20 = *(float *)(((unsigned char *)0x00002e20) + engineState);
  glContextFloat13e8_2 = *(float *)(((unsigned char *)0x000013e8) + glContext);
  engineStateShort2e10 = *(short *)(((unsigned char *)0x00002e10) + engineState);
  fVar11 = glContextFloat13e8_2;
  if ((glContextFloat13e8_2 < engineStateFloat2e20) &&
     (fVar11 = *(float *)(((unsigned char *)0x000013ec) + glContext), engineStateFloat2e20 < *(float *)(((unsigned char *)0x000013ec) + glContext))) {
    pcVar22 = "ram[";
    pcVar24 = "ram[";
    i2dHi1 = 0x43300000;
    i2dLo1 = (uint)(int)((engineStateFloat2e20 - glContextFloat13e8_2) / *(float *)(((unsigned char *)0x000013f0) + glContext) + 0.5);
    fctiwzSlot0 = (longlong)(int)i2dLo1;
    i2dLo1 = i2dLo1 ^ 0x80000000;
    fVar11 = *(float *)(((unsigned char *)0x000013f0) + glContext) *
             (float)((double)CONCAT44(0x43300000,i2dLo1) - 4503601774854144.0) + glContextFloat13e8_2;
  }
  glContextPtr4_5 = *(int *)(glContext + 4);
  engineStateShort2e28 = *(short *)(((unsigned char *)0x00002e28) + engineState);
  engineState4 = *(int *)(glContextPtr4_5 + 0x10);
  if (((((unsigned char *)0x00003178)[engineState4] == '\0') ||
      (engineState3 = *(uint *)(glContext + 0x44) & 0x20000, engineState3 != 0)) ||
     ((*(short *)(((unsigned char *)0x00003170) + engineState4) != 0x1b02 &&
      (*(short *)(((unsigned char *)0x00003172) + engineState4) != 0x1b02)))) {
    cVar32 = '\0';
  }
  else {
    cVar32 = '\x01';
  }
  engineStateShort3172 = *(ushort *)(((unsigned char *)0x00003172) + engineState);
  engineStateShort3170 = *(ushort *)(((unsigned char *)0x00003170) + engineState);
  if (glContextByte245b != '\0') {
    cVar31 = '\x01';
    cVar32 = '\x01';
  }
  cacheEntry = *(char **)(glContext + 0x2764);
  if (cacheEntry != (char *)0x0) {
    do {
      if ((((bool)*cacheEntry == (uVar16 == 0)) &&
          (((uVar16 != 0 ||
            ((((uint)(byte)cacheEntry[1] == (uint)(glContextPtr4_3 == 0) &&
              ((int)((ulonglong)uVar47 >> 0x20) == *(int *)(cacheEntry + 4))) &&
             ((engineStateShort2e0e == 0x1102) == (bool)cacheEntry[8])))) &&
           ((cacheEntry[0x14] == cVar14 && (cacheEntry[0x15] == cVar31)))))) &&
         (((cVar14 == '\0' && (cVar31 == '\0')) ||
          ((((iVar41 == *(int *)(cacheEntry + 0x18) && ((engineStateShort2e10 == 0x1102) == (bool)cacheEntry[0x1c])) &&
            ((cVar14 == '\0' ||
             ((2.0 <= *(float *)(cacheEntry + 0x20) || (fVar11 == *(float *)(cacheEntry + 0x20))))))) &&
           ((cVar31 == '\0' || (*(short *)(cacheEntry + 0x28) == engineStateShort2e28)))))))) {
        if ((uint)engineStateShort3170 == *(uint *)(cacheEntry + 0xb4)) {
          cacheEntryWordb8 = *(uint *)(cacheEntry + 0xb8);
          if (engineStateShort3172 != cacheEntryWordb8) goto LAB_000a4e54;
        }
        else {
          cacheEntryWordb8 = *(uint *)(cacheEntry + 0xb8);
LAB_000a4e54:
          if ((engineStateShort3170 != cacheEntryWordb8) || ((uint)engineStateShort3172 != *(uint *)(cacheEntry + 0xb4))) goto LAB_000a4e90;
        }
        if (cacheEntry[0x2a] == cVar32) {
          if (cVar32 == '\0') goto LAB_000a5b9c;
          staleArgR5 = 0x80;
          iVar18 = _memcmp(cacheEntry + 0x2c,((unsigned char *)0x000030e8) + engineState,0x80);
          if (iVar18 == 0) goto LAB_000a5b9c;
        }
      }
LAB_000a4e90:
      cacheEntry = *(char **)(cacheEntry + 0x138);
    } while (cacheEntry != (char *)0x0);
  }
  if (*(int *)(glContext + 0x2778) == 0x100) {
    ((int (*)())FUN_000a43f0)(glContext);
    glContextPtr4_5 = *(int *)(glContext + 4);
  }
  engineState2 = *(int *)(glContextPtr4_5 + 0x10);
  glContextByte245b = *(char *)(glContext + 0x245b);
  cacheEntry = (char *)(**(code **)(glContext + 0x10))(1,0x13c);
  if (cacheEntry == (char *)0x0) goto LAB_000a52dc;
  *cacheEntry = (*(uint *)(glContext + 0x44) & 0x60020000) == 0x40000000;
  uVar47 = FUN_0001a010(*(int *)(glContext + 4),*(undefined4 *)(*(int *)(glContext + 4) + 0x26a0),
                        staleArgR5,staleArgR6,pcVar22,pcVar24,engineState3);
  uVar21 = (undefined4)uVar47;
  cacheEntry[1] = (int)((ulonglong)uVar47 >> 0x20) == 0;
  cacheEntry[8] = *(short *)(((unsigned char *)0x00002e0e) + engineState2) == 0x1102;
  glContextPtr4 = *(int *)(glContext + 4);
  if ((((unsigned char *)0x00002e2d)[*(int *)(glContextPtr4 + 0x10)] == '\0') ||
     (pcVar22 = (char *)(*(uint *)(glContext + 0x44) & 0x20000), pcVar22 != (char *)0x0)) {
LAB_000a4f50:
    cVar14 = '\0';
  }
  else {
    uVar47 = FUN_0001a010(glContextPtr4,*(undefined4 *)(glContextPtr4 + 0x26a0),staleArgR5,staleArgR6,0,pcVar24,engineState3);
    uVar21 = (undefined4)uVar47;
    cVar14 = '\x01';
    if ((int)((ulonglong)uVar47 >> 0x20) != 0) goto LAB_000a4f50;
  }
  cacheEntry[0x14] = cVar14;
  cacheEntry[0x1c] = *(short *)(((unsigned char *)0x00002e10) + engineState2) == 0x1102;
  engineState2Float2e20 = *(float *)(((unsigned char *)0x00002e20) + engineState2);
  glContextFloat13e8_3 = *(float *)(((unsigned char *)0x000013e8) + glContext);
  fVar11 = glContextFloat13e8_3;
  if ((glContextFloat13e8_3 < engineState2Float2e20) &&
     (fVar11 = *(float *)(((unsigned char *)0x000013ec) + glContext), engineState2Float2e20 < *(float *)(((unsigned char *)0x000013ec) + glContext))) {
    pcVar22 = "ram[";
    pcVar24 = "ram[";
    i2dHi2 = 0x43300000;
    i2dLo2 = (uint)(int)((engineState2Float2e20 - glContextFloat13e8_3) / *(float *)(((unsigned char *)0x000013f0) + glContext) + 0.5);
    fctiwzSlot1 = (longlong)(int)i2dLo2;
    i2dLo2 = i2dLo2 ^ 0x80000000;
    fVar11 = *(float *)(((unsigned char *)0x000013f0) + glContext) *
             (float)((double)CONCAT44(0x43300000,i2dLo2) - 4503601774854144.0) + glContextFloat13e8_3;
  }
  *(float *)(cacheEntry + 0x20) = fVar11;
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
    cVar14 = '\0';
  }
  else {
    cVar14 = '\x01';
  }
  cacheEntry[0x2a] = cVar14;
  *(uint *)(cacheEntry + 0xb4) = (uint)*(ushort *)(((unsigned char *)0x00003170) + engineState2);
  *(uint *)(cacheEntry + 0xb8) = (uint)*(ushort *)(((unsigned char *)0x00003172) + engineState2);
  if (glContextByte245b != '\0') {
    cacheEntry[0x2a] = '\x01';
    cacheEntry[0x15] = '\x01';
  }
  if (*cacheEntry == '\0') {
    if ((*(int *)(cacheEntry + 0xb4) == 0x1b00) || (*(int *)(cacheEntry + 0xb8) == 0x1b00))
    goto LAB_000a5108;
    iVar38 = 0;
    levelCount = 0;
  }
  else {
    uVar47 = ((int (*)())FUN_000a36b0)(glContext,(uint)(byte)cacheEntry[1]);
    iVar41 = (int)((ulonglong)uVar47 >> 0x20);
    uVar21 = (undefined4)uVar47;
    iVar38 = iVar41 << 2;
    *(int *)(cacheEntry + 4) = iVar41;
    if (iVar38 < 1) {
LAB_000a5108:
      iVar38 = 0;
      levelCount = 1;
    }
    else {
      levelCount = 1;
    }
  }
  iVar41 = iVar38;
  iVar18 = iVar38;
  if ((*(uint *)(cacheEntry + 0x14) & 0xffff0000) == 0) {
    if ((*(int *)(cacheEntry + 0xb4) == 0x1b01) || (*(int *)(cacheEntry + 0xb8) == 0x1b01))
    goto LAB_000a5188;
  }
  else {
    uVar20 = 0xffff;
    if (((unsigned char *)0x00002e2c)[engineState2] != '\0') {
      uVar20 = *(undefined2 *)(((unsigned char *)0x00002e28) + engineState2);
    }
    *(undefined2 *)(cacheEntry + 0x28) = uVar20;
    iVar42 = ((int (*)())FUN_000a4770)(glContext,uVar21,staleArgR5,staleArgR6,pcVar22,pcVar24,entryFlag15);
    *(int *)(cacheEntry + 0x18) = iVar42;
    if (iVar38 < iVar42 << 2) {
      iVar41 = iVar42 << 2;
    }
    if (iVar38 < 0x10) {
      iVar18 = 0x10;
    }
LAB_000a5188:
    levelCount = levelCount + 1;
    iVar38 = iVar41;
  }
  if (cacheEntry[0x2a] != '\0') {
    staleArgR5 = 0x80;
    (**(code **)(((unsigned char *)0x00001344) + glContext))(cacheEntry + 0x2c,((unsigned char *)0x000030e8) + engineState2,0x80);
    *(undefined4 *)(cacheEntry + 0xac) = *(undefined4 *)(glContext + 0x2770);
    *(undefined4 *)(cacheEntry + 0xb0) = *(undefined4 *)(glContext + 0x2774);
    if (iVar38 < 0x20) {
      iVar38 = 0x20;
    }
    if (iVar18 < 0x20) {
      iVar18 = 0x20;
    }
    levelCount = levelCount + 1;
  }
  uVar21 = ((int (*)())FUN_000a3610)(glContext,iVar38,staleArgR5,staleArgR6,pcVar22,pcVar24,entryFlag15);
  entryFlag15 = ((int (*)())FUN_000a3610)(glContext,iVar18,staleArgR5,staleArgR6,pcVar22,pcVar24,entryFlag15);
  levelCountClamped = levelCount;
  if (1 < levelCount) {
    levelCountClamped = 4;
  }
  glContextWord4 = *(undefined4 *)(glContext + 4);
  if (levelCount < 2) {
    uVar29 = 3;
  }
  else {
    uVar29 = 1;
  }
  pcVar24 = (char *)0x1;
  uVar47 = FUN_00030c50(glContext,uVar21,entryFlag15,levelCountClamped,0x1909,1,((unsigned char *)0x00001401U),uVar29);
  maskTexture = (int)((ulonglong)uVar47 >> 0x20);
  uVar16 = (uint)uVar47;
  iVar38 = 0;
  if (maskTexture != 0) {
    FUN_0002ddf0(glContextWord4,maskTexture);
    maskLevel = *(int *)(maskTexture + 0x30);
    iVar38 = maskTexture + 0x3c;
    pcVar24 = (char *)0x2600;
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
    uVar16 = r4AfterCall;
  }
  *(int *)(cacheEntry + 0xbc) = iVar38;
  if (iVar38 != 0) {
    pixelCursor = *(int *)(iVar38 + 0x80);
    if (*cacheEntry == '\0') {
      if (1 < levelCount) {
        _memset(pixelCursor,0xff,*(undefined4 *)(iVar38 + 0x84));
        uVar16 = r4AfterCall5;
      }
    }
    else {
      maskHeight = (uint)*(ushort *)(iVar38 + 0x3c);
      maskWidth = (uint)*(ushort *)(iVar38 + 0x3a);
      i2dHi3 = 0x43300000;
      entryWord4X2 = *(int *)(cacheEntry + 4) * 2;
      entryWord4X4 = *(int *)(cacheEntry + 4) << 2;
      i2dLo3 = entryWord4X2 ^ 0x80000000;
      maskIsHardEdged = cacheEntry[1] == '\0';
      entryWord4X2F = (float)((double)CONCAT44(0x43300000,i2dLo3) - 4503601774854144.0);
      if (maskIsHardEdged) {
        uVar49 = (ulonglong)uVar16;
        innerLimitSq = 0.0;
      }
      else {
        uVar49 = (**(code **)(glContext + 0xc))(entryWord4X2);
        uVar16 = (uint)(uVar49 >> 0x20);
        maskIsHardEdged = uVar16 == 0;
        if (maskIsHardEdged) {
          innerLimitSq = 0.0;
        }
        else {
          levelCountClamped = uVar16;
          if ((*(uint *)(glContext + 0xe8) & 1) == 0) {
            contextFloatArg = (double)*(float *)(glContext + 0xe0);
            if (cacheEntry[8] != '\0') goto LAB_000a53ac;
            ((void (*)())FUN_000a3a60)(glContext,(int)uVar49,entryWord4X4,uVar16,local_118,contextFloatArg,staleArgF2,staleArgF3,staleArgF4,staleArgF5,
                         staleArgF6,staleArgF7,staleArgF8,staleStackArg_fffffeb8,staleStackArg_fffffec0,staleStackArg_fffffec8,
                         staleStackArg_fffffed0,staleStackArg_fffffed8);
            uVar21 = r4AfterCall3;
          }
          else {
            contextFloatArg = (double)*(float *)(glContext + 0x104);
LAB_000a53ac:
            ((void (*)())FUN_000a3790)(glContext,(int)uVar49,entryWord4X4,uVar16,local_118,contextFloatArg,staleArgF2,staleArgF3,staleArgF4,staleArgF5,
                         staleArgF6,staleArgF7,staleArgF8,staleStackArg_fffffeb8,staleStackArg_fffffec0,staleStackArg_fffffec8,
                         staleStackArg_fffffed0);
            uVar21 = r4AfterCall2;
          }
          uVar49 = CONCAT44(uVar16,uVar21);
          i2dHi4 = 0x43300000;
          i2dLo4 = entryWord4X2 - local_118[0] ^ 0x80000000;
          innerLimitSq = (float)((double)CONCAT44(0x43300000,i2dLo4) - 4503601774854144.0) - 0.5;
          innerLimitSq = innerLimitSq * innerLimitSq;
        }
      }
      rampBuffer = (int)(uVar49 >> 0x20);
      uVar16 = (uint)uVar49;
      pcVar24 = "ram[";
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
            pcVar24 = "ram[";
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
        pcVar24 = "ram[";
        (**(code **)(glContext + 0x18))(rampBuffer);
        uVar16 = r4AfterCall4;
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
        goto LAB_000a58ec;
      }
    }
    else {
      uVar34 = (uint)*(ushort *)(cacheEntryPtrbc + 0x3a);
      cacheEntryWord18 = *(int *)(cacheEntry + 0x18);
      blockRows = (int)(uint)*(ushort *)(cacheEntryPtrbc + 0x3c) >> 4;
      iVar41 = *(int *)(*(int *)(glContext + 4) + 0x10);
      uVar30 = cacheEntryWord18 * 4;
      lastRowPtr = pixelCursor + uVar34 * (*(ushort *)(cacheEntryPtrbc + 0x3c) - 1);
      if (cacheEntry[0x14] == '\0') {
        _memset(lastRowPtr,0xff,uVar34);
        cacheEntry[0x24] = '?';
        cacheEntry[0x25] = -0x80;
        cacheEntry[0x26] = '\0';
        cacheEntry[0x27] = '\0';
      }
      else {
        levelCountClamped = lastRowPtr;
        if (cacheEntry[0x1c] == '\0') {
          engineFloat2e20 = (double)*(float *)(((unsigned char *)0x00002e20) + iVar41);
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
          entryWord14High = local_118;
          ((void (*)())FUN_000a3a60)(glContext,uVar16,uVar30,lastRowPtr,entryWord14High,quantizedValue,staleArgF2,staleArgF3,staleArgF4,staleArgF5,staleArgF6,
                       staleArgF7,staleArgF8,staleStackArg_fffffeb8,staleStackArg_fffffec0,staleStackArg_fffffec8,
                       staleStackArg_fffffed0,staleStackArg_fffffed8);
        }
        else {
          engineFloat2e20 = (double)*(float *)(((unsigned char *)0x00002e20) + iVar41);
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
          entryWord14High = local_118;
          ((void (*)())FUN_000a3790)(glContext,uVar16,uVar30,lastRowPtr,entryWord14High,quantizedValue,staleArgF2,staleArgF3,staleArgF4,staleArgF5,staleArgF6,
                       staleArgF7,staleArgF8,staleStackArg_fffffeb8,staleStackArg_fffffec0,staleStackArg_fffffec8,
                       staleStackArg_fffffed0);
        }
        if (0 < local_118[0]) {
          loopIndex3 = 0;
          mirrorDst = (undefined1 *)(lastRowPtr + uVar30);
          do {
            mirrorSrc = (undefined1 *)(loopIndex3 + lastRowPtr);
            loopIndex3 = loopIndex3 + 1;
            mirrorDst = mirrorDst + -1;
            *mirrorDst = *mirrorSrc;
          } while (loopIndex3 < local_118[0]);
        }
        _memset(lastRowPtr + local_118[0],0xff,uVar30 + local_118[0] * -2);
        _memset((undefined1 *)(lastRowPtr + uVar30),0,uVar34 + cacheEntryWord18 * -4);
        i2dLo11 = uVar30 ^ 0x80000000;
        i2dLo10 = uVar34 ^ 0x80000000;
        i2dHi10 = 0x43300000;
        i2dHi11 = 0x43300000;
        *(float *)(cacheEntry + 0x24) =
             (float)((double)CONCAT44(0x43300000,i2dLo11) - 4503601774854144.0) /
             (float)((double)CONCAT44(0x43300000,i2dLo10) - 4503601774854144.0);
      }
      engineState = *(int *)(*(int *)(glContext + 4) + 0x10);
      if (((((unsigned char *)0x00002e2c)[engineState] == '\0') ||
          (entryWord14High = (int *)(*(uint *)(glContext + 0x44) & 0x20000), entryWord14High != (int *)0x0)) ||
         (uVar16 = (uint)*(ushort *)(((unsigned char *)0x00002e28) + engineState), uVar16 == 0xffff)) {
        uVar16 = 0xffff;
      }
      loopIndex4 = 0;
      do {
        pcVar24 = (char *)(uVar16 & 1);
        if (pcVar24 == (char *)0x0) {
          rowsEnd = pixelCursor + uVar34 * blockRows;
          _memset(pixelCursor,0,uVar34 * blockRows);
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
              rowsEnd = pixelCursor + uVar34;
              (**(code **)(((unsigned char *)0x00001344) + glContext))(pixelCursor,lastRowPtr,uVar34);
              pixelCursor = rowsEnd;
            } while (rowsThisBlock != loopIndex);
          }
        }
        notLastBlock = loopIndex4 != 0xf;
        uVar16 = uVar16 >> 1;
        loopIndex4 = loopIndex4 + 1;
        pixelCursor = rowsEnd;
      } while (notLastBlock);
LAB_000a58ec:
      cacheEntryPtrbc = *(int *)(cacheEntry + 0xbc);
    }
    pixelCursor = *(int *)(cacheEntryPtrbc + 0x80);
    if (1 < levelCount) {
      pixelCursor = pixelCursor + *(int *)(cacheEntryPtrbc + 0x84) * 2;
    }
    if (cacheEntry[0x2a] == '\0') {
      if (1 < levelCount) {
        _memset(pixelCursor,0xff,*(undefined4 *)(cacheEntryPtrbc + 0x84));
        goto LAB_000a59f4;
      }
    }
    else {
      uVar16 = (uint)*(ushort *)(cacheEntryPtrbc + 0x3a);
      blocksLeft = 0x20;
      entryWord14High = *(int **)(cacheEntry + 0xac);
      cacheEntryWordb0 = *(uint *)(cacheEntry + 0xb0);
      pcVar24 = (char *)((int)(uint)*(ushort *)(cacheEntryPtrbc + 0x3c) >> 5);
      iVar38 = (int)uVar16 >> 5;
      do {
        patternCol = 0;
        levelCountClamped = 0;
        do {
          stippleByte = 0xff;
          if ((1 << ((uint)entryWord14High & 0x3f) & *(uint *)(cacheEntry + (0x1f - cacheEntryWordb0) * 4 + 0x2c)) == 0)
          {
            stippleByte = 0;
          }
          iVar42 = levelCountClamped + pixelCursor;
          if (pcVar24 != (char *)0x0) {
            pcVar22 = (char *)0x0;
            do {
              if (iVar38 != 0) {
                fillCol = 0;
                iVar36 = iVar38;
                do {
                  *(undefined1 *)(iVar42 + fillCol) = stippleByte;
                  fillCol = fillCol + 1;
                  iVar36 = iVar36 + -1;
                } while (iVar36 != 0);
              }
              pcVar22 = pcVar22 + 1;
              iVar42 = iVar42 + uVar16;
            } while (pcVar24 != pcVar22);
          }
          notLastPatternCol = patternCol != 0x1f;
          levelCountClamped = levelCountClamped + iVar38;
          patternCol = patternCol + 1;
          entryWord14High = (int *)((int)entryWord14High + 1U & 0x1f);
        } while (notLastPatternCol);
        blocksLeft = blocksLeft + -1;
        pixelCursor = pixelCursor + uVar16 * (int)pcVar24;
        cacheEntryWordb0 = cacheEntryWordb0 + 1 & 0x1f;
      } while (blocksLeft != 0);
LAB_000a59f4:
      cacheEntryPtrbc = *(int *)(cacheEntry + 0xbc);
    }
    uploadResult = FUN_000341a0(glContext,*(undefined4 *)(cacheEntryPtrbc + 0x7c),*(undefined4 *)(glContext + 0x276c),
                          levelCountClamped,entryWord14High,pcVar24);
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
      iVar40 = 1 - ((int)-(levelFormat ^ 2) >> 0x1f);
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
          *(int *)(cacheEntry + 0xf8) = iVar40;
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
        *(int *)(cacheEntry + 0xec) = iVar40;
        if ((*(int *)(cacheEntry + 0xb4) == 0x1b01) || (*(int *)(cacheEntry + 0xb8) == 0x1b01)) {
          *(uint *)(cacheEntry + 0xd0) = levelFormat;
          *(int *)(cacheEntry + 0xf8) = iVar40;
        }
      }
      if ((cacheEntry[0x2a] != 0) || (levelFormat == 3)) {
        *(uint *)(cacheEntry + 0xd0) = levelFormat;
        *(int *)(cacheEntry + 0xf8) = iVar40;
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
LAB_000a5b9c:
      *(char **)(glContext + 0x2768) = cacheEntry;
      ((int (*)())FUN_000a46d0)(glContext);
      *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x200;
      *(undefined1 *)(glContext + 0x29) = 1;
      *(ushort *)(glContext + 0x34) =
           (ushort)(1 << (*(uint *)(glContext + 0x276c) & 0x3f)) | *(ushort *)(glContext + 0x34);
      *(undefined4 *)(glContext + 0x277c) = 0xffffffff;
      return 0;
    }
  }
  _free(cacheEntry);
LAB_000a52dc:
  ((int (*)())FUN_000a4550)(glContext);
  return 1;
}

/* FUN_000a5c40 @ 0xa5c40 (624 bytes) */
int FUN_000a5c40(glContext)
  int glContext;
{
  int glContextPtr4;
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 glContextWord1a94;
  
  iVar5 = *(int *)(*(int *)(glContext + 4) + 0x10);
  fVar1 = *(float *)(((unsigned char *)0x00002da8) + iVar5) * 255.0;
  if (2.1474836e+09 <= fVar1) {
    uVar7 = (int)(fVar1 - 2.1474836e+09) + 0x80000000;
  }
  else {
    uVar7 = (uint)(int)fVar1;
  }
  fVar1 = *(float *)(((unsigned char *)0x00002dac) + iVar5) * 255.0;
  if (2.1474836e+09 <= fVar1) {
    iVar2 = (int)(fVar1 - 2.1474836e+09) + -0x80000000;
  }
  else {
    iVar2 = (int)fVar1;
  }
  fVar1 = *(float *)(((unsigned char *)0x00002da0) + iVar5) * 255.0;
  if (2.1474836e+09 <= fVar1) {
    iVar3 = (int)(fVar1 - 2.1474836e+09) + -0x80000000;
  }
  else {
    iVar3 = (int)fVar1;
  }
  fVar1 = *(float *)(((unsigned char *)0x00002da4) + iVar5) * 255.0;
  if (2.1474836e+09 <= fVar1) {
    iVar5 = (int)(fVar1 - 2.1474836e+09) + -0x80000000;
  }
  else {
    iVar5 = (int)fVar1;
  }
  *(uint *)(glContext + 0x1a94) = uVar7 | iVar2 << 0x18 | iVar3 << 0x10 | iVar5 << 8;
  puVar4 = (undefined4 *)
           (**(code **)(glContext + 0x2758))
                     (glContext,0xd,staleArgR5,staleArgR6,staleArgR7,staleArgR8,*(code **)(glContext + 0x2758));
  glContextPtr4 = *(int *)(glContext + 4);
  *(undefined4 **)(0x00002748 + glContext + 4) = puVar4;
  puVar6 = *(uint **)(glContextPtr4 + 0x1d8);
  *puVar6 = (int)puVar4 - (int)puVar6 >> 2 | *puVar6;
  *(undefined4 **)(glContextPtr4 + 0x1d8) = puVar4;
  *puVar4 = 0x4000000;
  puVar4[3] = ((unsigned char *)0x00001393U);
  puVar4[4] = 10;
  puVar4[5] = ((unsigned char *)0x00001385U);
  glContextWord1a94 = *(undefined4 *)(glContext + 0x1a94);
  puVar4[7] = 0xc0023800;
  puVar4[0xb] = ((unsigned char *)0x00001380U);
  puVar4[0xc] = 0;
  puVar4[8] = 0;
  puVar4[9] = 0;
  puVar4[10] = 0;
  puVar4[6] = glContextWord1a94;
  *(undefined4 **)(0x00002748 + glContext + 4) = puVar4 + 0xd;
                    
                    
  (**(code **)(glContext + 0x275c))(glContext,puVar4 + 0xd);
  return;
}

/* FUN_000a5ec0 @ 0xa5ec0 (620 bytes) */
int FUN_000a5ec0(glContext)
  int glContext;
{
  uint glContextWord44;
  uint glContextWord1930;
  uint glContextWord1a4c;
  float fVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int glContextWord1a60;
  uint uVar7;
  uint uVar8;
  char cVar9;
  int iVar10;
  
  glContextWord1a4c = *(uint *)(glContext + 0x1a4c);
  glContextWord1a60 = *(int *)(glContext + 0x1a60);
  *(uint *)(glContext + 0x1a4c) = glContextWord1a4c & 0xfffeffff;
  *(undefined4 *)(glContext + 0x1a60) = 0;
  iVar10 = *(int *)(*(int *)(glContext + 4) + 0x2a50);
  if (iVar10 == 1) {
    glContextWord44 = *(uint *)(glContext + 0x44);
    if ((glContextWord44 & 0x10000000) == 0) {
      *(undefined4 *)(glContext + 0x1a68) = 0x66666666;
      *(undefined4 *)(glContext + 0x1a6c) = 0x6666666;
      *(undefined4 *)(glContext + 0x1b60) = 0xffffff;
      goto LAB_000a6110;
    }
  }
  else {
    glContextWord44 = *(uint *)(glContext + 0x44);
  }
  iVar10 = iVar10 >> 1;
  iVar2 = (iVar10 + -1) * 4;
  uVar3 = *(uint *)(&DAT_001aa7e8 + iVar2);
  *(uint *)(glContext + 0x2354) = *(uint *)(glContext + 0x2354) & 0xfffffffe;
  glContextWord1a4c = (uint)(iVar10 == 3) << 0x11 | glContextWord1a4c & 0xfffcffff;
  *(undefined4 *)(glContext + 0x1a6c) = *(undefined4 *)(&DAT_001aa7d0 + iVar2);
  *(uint *)(glContext + 0x1a4c) = glContextWord1a4c;
  uVar5 = *(undefined4 *)(&DAT_001aa7dc + iVar2);
  *(uint *)(glContext + 0x1a60) = (uVar3 & 3) << 1 | 1;
  *(undefined4 *)(glContext + 0x1a68) = uVar5;
  if ((glContextWord44 & 0x10000000) == 0) {
    cVar9 = '\0';
    uVar3 = 0;
    fVar1 = FLOAT_001aa0e8;
  }
  else {
    fVar1 = *(float *)(glContext + 0x438);
    cVar9 = *(char *)(glContext + 0x43c);
    uVar3 = glContextWord44 >> 0x19 & 1;
    *(uint *)(glContext + 0x1a4c) = glContextWord44 >> 0xb & 0x10000 | glContextWord1a4c;
  }
  uVar4 = *(uint *)(*(int *)(glContext + 4) + 0x2a50);
  if (uVar3 == 0) {
    uVar4 = (1 << (uVar4 & 0x3f)) - 1;
    uVar4 = uVar4 | uVar4 * 0x40000 | uVar4 * 0x1000 | uVar4 * 0x40;
  }
  else {
    uVar8 = 0;
    uVar7 = (uint)(int)(fVar1 * FLOAT_001aa104 *
                   (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - DOUBLE_001aa1e0) +
                  FLOAT_001aa10c);
    uVar3 = uVar7 & 3;
    uVar7 = (int)uVar7 >> 2;
    if (cVar9 != '\0') {
      uVar8 = (1 << (uVar4 & 0x3f)) - 1;
    }
    uVar4 = uVar8 ^ (1 << (uVar7 + (uVar3 != 0) & 0x3f)) - 1U |
            (uVar8 ^ (1 << (uVar7 & 0x3f)) - 1U) << 0x12 |
            (uVar8 ^ (1 << (uVar7 + (1 < uVar3) & 0x3f)) - 1U) << 0xc |
            (uVar8 ^ (1 << (uVar7 + (2 < uVar3) & 0x3f)) - 1U) << 6;
  }
  *(uint *)(glContext + 0x1b60) = uVar4;
LAB_000a6110:
  glContextWord1930 = *(uint *)(glContext + 0x1930);
  *(uint *)(glContext + 0x1930) = glContextWord1930 | 0x80200;
  if (glContextWord1a60 != *(int *)(glContext + 0x1a60)) {
    *(uint *)(glContext + 0x1930) = glContextWord1930 | 0x2080340;
  }
  return;
}

/* FUN_000a6140 @ 0xa6140 (896 bytes) */
int FUN_000a6140(ring, param_2, param_3)
  int ring;
  uint param_2;
  undefined4 param_3;
{
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
  undefined4 *puVar1;
  uint *a6;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  gldSaveRasterState(ring,param_3);
  *(undefined4 *)(ring + 0x1ba0) = 3;
  *(undefined4 *)(ring + 0x1b9c) = 3;
  *(undefined4 *)(ring + 0x1b84) = 0;
  *(undefined4 *)(ring + 0x1b50) = 0;
  *(undefined4 *)(ring + 0x1b60) = 0xffffff;
  *(undefined4 *)(ring + 0x1b30) = 0;
  *(undefined4 *)(ring + 0x1b74) = 0x1c000;
  *(undefined4 *)(ring + 0x248c) = 8;
  if ((param_2 & 1) == 0) {
    *(undefined4 *)(ring + 0x1a50) = 0;
    *(undefined4 *)(ring + 0x1ab8) = 1;
  }
  else {
    *(undefined4 *)(ring + 0x1ab8) = 0;
  }
  if ((param_2 & 0x1000) != 0) {
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
  puVar1 = (undefined4 *)(**(code **)(ring + 0x2758))(ring,0x20,param_3,0xf,2,1,a6,3);
  *(undefined4 **)(0x00002748 + ring + 4) = puVar1;
  puVar3 = puVar1 + 0x1a;
  *puVar1 = 0x887;
  ringWord1b74 = *(undefined4 *)(ring + 0x1b74);
  puVar1[2] = 0x82c;
  puVar1[1] = ringWord1b74;
  ringWord1b84 = *(undefined4 *)(ring + 0x1b84);
  puVar1[4] = ((unsigned char *)0x000010aeU);
  puVar1[3] = ringWord1b84;
  ringWord1b30 = *(undefined4 *)(ring + 0x1b30);
  puVar1[6] = ((unsigned char *)0x00001002U);
  puVar1[5] = ringWord1b30;
  ringWord1b50 = *(undefined4 *)(ring + 0x1b50);
  puVar1[8] = 0x824;
  puVar1[7] = ringWord1b50;
  ringWord1b9c = *(undefined4 *)(ring + 0x1b9c);
  puVar1[10] = 0x825;
  puVar1[9] = ringWord1b9c;
  ringWord1ba0 = *(undefined4 *)(ring + 0x1ba0);
  puVar1[0xc] = 0x82d;
  puVar1[0xb] = ringWord1ba0;
  ringWord248c = *(undefined4 *)(ring + 0x248c);
  puVar1[0xe] = 0x854;
  puVar1[0xd] = ringWord248c;
  uVar2 = **(undefined4 **)(ring + 0x2440);
  puVar1[0x10] = 0x878;
  puVar1[0xf] = uVar2;
  uVar2 = **(undefined4 **)(ring + 0x2444);
  puVar1[0x12] = ((unsigned char *)0x000012f0U);
  puVar1[0x11] = uVar2;
  puVar1[0x13] = *(undefined4 *)(ring + 0x1aec);
  puVar1[0x14] = ((unsigned char *)0x000012f6U);
  ringWord1a50 = *(undefined4 *)(ring + 0x1a50);
  puVar1[0x16] = ((unsigned char *)0x000010faU);
  puVar1[0x15] = ringWord1a50;
  ringWord1b60 = *(undefined4 *)(ring + 0x1b60);
  puVar1[0x18] = ((unsigned char *)0x000013c5U);
  puVar1[0x17] = ringWord1b60;
  puVar1[0x19] = *(undefined4 *)(ring + 0x1ab8);
  if ((*(uint *)(ring + 0x2454) & 0x8000000) != 0) {
    puVar1[0x1a] = ((unsigned char *)0x000013c5U);
    puVar3 = puVar1 + 0x1c;
    puVar1[0x1b] = *(undefined4 *)(ring + 0x1ab8);
  }
  *puVar3 = ((unsigned char *)0x00001048U);
  ringWord1bc0 = *(undefined4 *)(ring + 0x1bc0);
  puVar3[2] = ((unsigned char *)0x00001047U);
  puVar3[1] = ringWord1bc0;
  puVar3[3] = *(undefined4 *)(ring + 0x1bb0);
  *(undefined4 **)(0x00002748 + ring + 4) = puVar3 + 4;
                    
                    
  (**(code **)(ring + 0x275c))(ring,puVar3 + 4);
  return;
}

/* FUN_000a64d0 @ 0xa64d0 (36 bytes) */
int FUN_000a64d0(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x150);
  iVar2 = *(int *)(param_1 + 4) + 0x30;
  if (iVar1 != 0) {
    iVar2 = iVar1;
  }
  *(undefined1 *)(iVar2 + 0xc5) = 1;
  return;
}

/* FUN_000a6500 @ 0xa6500 (828 bytes) */
int FUN_000a6500(glContext, param_2)
  int glContext;
  int param_2;
{
  uint glContextWord1ab8;
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  uint uVar5;
  undefined4 staleArgR7;
  uint loopIndex;
  undefined4 staleArgR8;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  int glContextPtr4;
  
  glContextPtr4 = *(int *)(glContext + 4);
  iVar11 = *(int *)(glContextPtr4 + 0x10);
  uVar3 = FUN_0004e990(glContext);
  uVar8 = *(uint *)(glContextPtr4 + 0x154) & 0x30000;
  if ((uVar8 == 0x20000) || (uVar8 == 0x30000)) {
    iVar10 = 0x18;
  }
  else {
    if (uVar8 == 0x10000) {
      iVar10 = 0x10;
      *(uint *)(glContext + 0x1ae4) = uVar3 | uVar3 << 0x10;
      goto LAB_000a6564;
    }
    iVar10 = 0;
  }
  *(uint *)(glContext + 0x1ae4) = uVar3 << 8;
LAB_000a6564:
  uVar8 = *(uint *)(((unsigned char *)0x00002db4) + iVar11);
  *(uint *)(glContext + 0x1ae4) = *(uint *)(glContext + 0x1ae4) | uVar8;
  puVar4 = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,0x1a,staleArgR5,staleArgR6,staleArgR7,staleArgR8,uVar8)
  ;
  *(undefined4 **)(0x00002748 + glContext + 4) = puVar4;
  puVar7 = puVar4 + 0xc;
  puVar1 = *(uint **)(glContextPtr4 + 0x1d8);
  *puVar1 = (int)puVar4 - (int)puVar1 >> 2 | *puVar1;
  *(undefined4 **)(glContextPtr4 + 0x1d8) = puVar4;
  puVar4[8] = 0xc0023200;
  puVar4[0xb] = 0;
  *puVar4 = 0x5000000;
  puVar4[6] = ((unsigned char *)0x000013c6U);
  puVar4[1] = param_2;
  puVar4[2] = 0;
  puVar4[3] = 0;
  puVar4[4] = 0;
  puVar4[5] = 0;
  puVar4[9] = 0;
  puVar4[10] = 0;
  puVar4[7] = 3;
  if (param_2 != 0) {
    if (*(char *)(glContext + 0x2451) == '\0') {
      uVar3 = uVar3 >> (iVar10 - 8U & 0x3f);
      uVar8 = uVar3 | uVar3 << 0x18 | uVar3 << 0x10 | uVar3 << 8;
    }
    else {
      uVar8 = 0xffffffff;
      if ((uVar3 < 0xffffff) && (uVar8 = 0, uVar3 != 0)) {
        uVar8 = iVar10 - 1;
        uVar5 = *(uint *)(glContext + 0x1ab0) >> 0xc & 7;
        uVar2 = (1 << uVar5) - 1;
        if ((*(uint *)(glContext + 0x1ab0) & 0x8000) == 0) {
          loopIndex = 0;
          for (; (1 << (uVar8 & 0x3f) & uVar3 * uVar2) != 0; uVar8 = uVar8 - 1) {
            loopIndex = loopIndex + 1;
          }
        }
        else {
          loopIndex = 0;
          for (; (uVar3 * uVar2 & 1 << (uVar8 & 0x3f)) == 0; uVar8 = uVar8 - 1) {
            loopIndex = loopIndex + 1;
          }
        }
        uVar3 = uVar3 * uVar2;
        if (loopIndex < uVar2) {
          uVar3 = uVar3 * 2;
          uVar2 = loopIndex;
        }
        uVar8 = (uVar3 & ~((1 << (uVar2 & 0x3f)) + -1 << (iVar10 - uVar2 & 0x3f))) >>
                ((uVar5 + (iVar10 - uVar2)) - 8 & 0x3f) | uVar2 << (8 - uVar5 & 0x3f);
        uVar3 = uVar8 & 0xff;
        uVar8 = uVar3 | uVar3 << 8 | uVar3 << 0x10 | uVar8 << 0x18;
      }
    }
    glContextWord1ab8 = *(uint *)(glContext + 0x1ab8);
    puVar9 = puVar4 + 0xe;
    *puVar7 = ((unsigned char *)0x000013c5U);
    glContextWord1ab8 = glContextWord1ab8 | 1;
    puVar4[0xd] = glContextWord1ab8;
    if ((*(uint *)(glContext + 0x2454) & 0x8000000) != 0) {
      puVar4[0xf] = glContextWord1ab8;
      puVar4[0xe] = ((unsigned char *)0x000013c5U);
      puVar9 = puVar4 + 0x10;
    }
    puVar7 = puVar9 + 6;
    puVar4[2] = (int)puVar9 - (int)puVar4 >> 2;
    *puVar9 = 0xc0023700;
    puVar9[2] = 0;
    puVar9[3] = uVar8;
    puVar9[1] = 0;
    puVar9[4] = ((unsigned char *)0x000013c5U);
    puVar9[5] = *(undefined4 *)(glContext + 0x1ab8);
    if ((*(uint *)(glContext + 0x2454) & 0x8000000) != 0) {
      puVar9[6] = ((unsigned char *)0x000013c5U);
      puVar7 = puVar9 + 8;
      puVar9[7] = *(undefined4 *)(glContext + 0x1ab8);
    }
  }
  puVar4[3] = (int)puVar7 + (4 - (int)puVar4) >> 2;
  *puVar7 = ((unsigned char *)0x000013caU);
  puVar7[1] = *(undefined4 *)(glContext + 0x1ae4);
  *(undefined4 **)(0x00002748 + glContext + 4) = puVar7 + 2;
                    
                    
  (**(code **)(glContext + 0x275c))(glContext,puVar7 + 2);
  return;
}

/* FUN_000a6860 @ 0xa6860 (1096 bytes) */
int FUN_000a6860(glContext, dirtyMask)
  int glContext;
  uint dirtyMask;
{
  undefined4 glContextWord1b84;
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char glContextByte2802;
  float fVar8;
  float fVar12;
  float fVar13;
  undefined4 *puVar14;
  undefined4 uVar15;
  undefined4 r4AfterCall;
  int iVar16;
  undefined *puVar17;
  undefined4 *puVar18;
  undefined4 uVar19;
  int iVar20;
  int iVar21;
  double dVar22;
  undefined1 auStack_128 [144];
  undefined4 local_98;
  uint i2dLo1;
  undefined4 i2dHi2;
  uint i2dLo2;
  undefined4 i2dHi1;
  uint uStack_84;
  undefined4 local_80;
  uint uStack_7c;
  undefined4 i2dHi3;
  undefined4 i2dLo3;
  longlong fctiwzSlot0;
  longlong fctiwzSlot1;
  undefined4 i2dHi4;
  undefined4 i2dLo4;
  longlong fctiwzSlot2;
  longlong fctiwzSlot3;
  float fVar9;
  float fVar10;
  float fVar11;
  
  local_80 = 0x43300000;
  local_98 = 0x43300000;
  i2dHi2 = 0x43300000;
  i2dHi1 = 0x43300000;
  i2dLo1 = *(int *)(((unsigned char *)0x00001358) + glContext) - *(int *)(((unsigned char *)0x000013d8) + glContext) ^ 0x80000000;
  i2dLo2 = *(int *)(((unsigned char *)0x00001360) + glContext) - *(int *)(((unsigned char *)0x000013d8) + glContext) ^ 0x80000000;
  uStack_84 = *(int *)(((unsigned char *)0x0000135c) + glContext) - *(int *)(((unsigned char *)0x000013dc) + glContext) ^ 0x80000000;
  uStack_7c = *(int *)(((unsigned char *)0x00001364) + glContext) - *(int *)(((unsigned char *)0x000013dc) + glContext) ^ 0x80000000;
  dVar22 = *(double *)(((unsigned char *)0x00002d88) + *(int *)(*(int *)(glContext + 4) + 0x10));
  fVar2 = (float)((double)CONCAT44(0x43300000,i2dLo1) - DOUBLE_001aa1e0);
  fVar3 = (float)((double)CONCAT44(0x43300000,i2dLo2) - DOUBLE_001aa1e0);
  fVar4 = (float)((double)CONCAT44(0x43300000,uStack_7c) - DOUBLE_001aa1e0);
  fVar5 = (float)((double)CONCAT44(0x43300000,uStack_84) - DOUBLE_001aa1e0);
  if (((dirtyMask & 0x400) == 0) || (iVar20 = 1, ((unsigned char *)0x00001491)[glContext] == '\0')) {
    iVar20 = 0;
  }
  if (((dirtyMask & 0x100) == 0) || (iVar21 = 1, ((unsigned char *)0x00001490)[glContext] == '\0')) {
    iVar21 = 0;
  }
  iVar16 = iVar21;
  gldEnterInternalDrawState(glContext,0,iVar21,iVar20,auStack_128);
  if ((iVar21 == 0) && (iVar20 != 0)) {
    uVar15 = 0x25;
    if (*(char *)(glContext + 0x2802) != '\0') {
      uVar15 = 0x23;
    }
    puVar14 = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,uVar15);
    glContextByte2802 = *(char *)(glContext + 0x2802);
    *(undefined4 **)(0x00002748 + glContext + 4) = puVar14;
    if (glContextByte2802 == '\0') {
      *puVar14 = 0x5c8;
      puVar14[1] = 0x10000000;
      puVar14 = puVar14 + 2;
      *(undefined1 *)(glContext + 0x2802) = 1;
    }
    puVar14 = (undefined4 *)gldEmitInternalDrawSetupPackets(glContext,puVar14);
    i2dLo3 = *(undefined4 *)(glContext + 8);
    i2dHi3 = 0x43300000;
    *(undefined4 **)(glContext + 0x2794) = puVar14;
    fVar11 = FLOAT_001aa194;
    fVar10 = FLOAT_001aa190;
    fVar9 = FLOAT_001aa18c;
    fVar8 = FLOAT_001aa188;
    fVar13 = (fVar5 + fVar4) * FLOAT_001aa10c;
    fVar12 = (fVar2 + fVar3) * FLOAT_001aa10c;
    fVar6 = (float)((double)CONCAT44(0x43300000,i2dLo3) - DOUBLE_001aa250);
    uVar1 = (uint)(int)(*(float *)(glContext + 0x2818) * FLOAT_001aa10c * fVar6 * (fVar4 - fVar5));
    fctiwzSlot0 = (longlong)(int)uVar1;
    iVar20 = (int)(fVar6 * *(float *)(glContext + 0x2814) * FLOAT_001aa10c * (fVar3 - fVar2));
    fctiwzSlot1 = (longlong)iVar20;
    puVar14[2] = 0x82c;
    *puVar14 = ((unsigned char *)0x00001087U);
    puVar14[1] = iVar20 << 0x10 | uVar1 & 0xffff;
  }
  else {
    uVar15 = 0x25;
    if (*(char *)(glContext + 0x2802) != '\0') {
      uVar15 = 0x23;
    }
    puVar14 = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,uVar15);
    glContextByte2802 = *(char *)(glContext + 0x2802);
    *(undefined4 **)(0x00002748 + glContext + 4) = puVar14;
    if (glContextByte2802 == '\0') {
      *puVar14 = 0x5c8;
      puVar14[1] = 0x10000000;
      puVar14 = puVar14 + 2;
      *(undefined1 *)(glContext + 0x2802) = 1;
    }
    puVar14 = (undefined4 *)gldEmitInternalDrawSetupPackets(glContext,puVar14);
    i2dLo4 = *(undefined4 *)(glContext + 8);
    i2dHi4 = 0x43300000;
    *(undefined4 **)(glContext + 0x2794) = puVar14;
    fVar11 = FLOAT_001aa194;
    fVar10 = FLOAT_001aa190;
    fVar9 = FLOAT_001aa18c;
    fVar8 = FLOAT_001aa188;
    fVar13 = (fVar5 + fVar4) * FLOAT_001aa10c;
    fVar12 = (fVar2 + fVar3) * FLOAT_001aa10c;
    fVar6 = (float)((double)CONCAT44(0x43300000,i2dLo4) - DOUBLE_001aa250);
    uVar1 = (uint)(int)(*(float *)(glContext + 0x2818) * FLOAT_001aa10c * fVar6 * (fVar4 - fVar5));
    fctiwzSlot2 = (longlong)(int)uVar1;
    iVar20 = (int)(fVar6 * *(float *)(glContext + 0x2814) * FLOAT_001aa10c * (fVar3 - fVar2));
    fctiwzSlot3 = (longlong)iVar20;
    puVar14[2] = 0x82c;
    *puVar14 = ((unsigned char *)0x00001087U);
    puVar14[1] = iVar20 << 0x10 | uVar1 & 0xffff;
  }
  puVar18 = puVar14 + 0x10;
  uVar19 = 0xc0083500;
  puVar17 = ((unsigned char *)0x00001087U);
  glContextWord1b84 = *(undefined4 *)(glContext + 0x1b84);
  puVar14[4] = 0xc0083500;
  puVar14[5] = 0x10031;
  puVar14[6] = fVar12;
  puVar14[7] = fVar13;
  puVar14[8] = (float)dVar22;
  puVar14[10] = fVar8;
  puVar14[0xb] = fVar9;
  puVar14[3] = glContextWord1b84;
  puVar14[0xc] = fVar10;
  puVar14[0xd] = fVar11;
  puVar14[0xe] = ((unsigned char *)0x00001087U);
  puVar14[9] = 0x3f800000;
  puVar14[0xf] = *(undefined4 *)(glContext + 0x1ccc);
  *(undefined4 **)(0x00002748 + glContext + 4) = puVar18;
  (**(code **)(glContext + 0x275c))(glContext,puVar18);
  gldValidateVertexProgramState(glContext,r4AfterCall,iVar16,puVar17,puVar18,uVar19,iVar20);
  gldLeaveInternalDrawState(glContext,auStack_128);
  return;
}

/* FUN_000a6cb0 @ 0xa6cb0 (656 bytes) */
int FUN_000a6cb0(glContext, param_2)
  int glContext;
  uint param_2;
{
  undefined4 glContextWord1ae0;
  int glContextPtr4;
  bool bVar1;
  code *glContextPtr275c;
  uint *puVar3;
  undefined4 *puVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  
  glContextPtr4 = *(int *)(glContext + 4);
  cVar5 = ((unsigned char *)0x00003190)[*(int *)(glContextPtr4 + 0x10)];
  if (cVar5 != '\0') {
    if ((((*(int *)(glContext + 0x440) == 0) && (*(int *)(glContext + 0x444) == 0)) &&
        (*(int *)(glContextPtr4 + 0x160) == *(int *)(glContext + 0x44c))) &&
       (*(int *)(glContextPtr4 + 0x15c) == *(int *)(glContext + 0x448))) {
      cVar5 = '\0';
    }
  }
  uVar7 = *(uint *)(glContextPtr4 + 0x154);
  iVar10 = glContextPtr4 + 0x30;
  if (*(int *)(glContextPtr4 + 0x150) != 0) {
    iVar10 = *(int *)(glContextPtr4 + 0x150);
  }
  if ((uVar7 & 0x40) == 0) {
    bVar1 = (param_2 >> 8 & 1) == 0;
LAB_000a6d70:
    if ((uVar7 & 0x80) == 0) {
      uVar8 = param_2 >> 10 & 1;
LAB_000a6db0:
      if (cVar5 == '\0') {
        if (bVar1) {
          uVar9 = 0;
        }
        else if (((*(char *)(glContext + 0x247c) == '\0') || ((uVar7 & 0x40) == 0)) ||
                (((uVar7 & 0x30000) == 0x10000 && ((uVar7 & 0x1000) != 0)))) {
          uVar9 = 0;
          *(undefined1 *)(iVar10 + 0xc5) = 1;
        }
        else {
          uVar9 = 1;
          *(undefined1 *)(iVar10 + 0xc5) = 0;
          *(undefined1 *)(iVar10 + 0xc4) = 1;
        }
        iVar6 = (**(code **)(glContext + 0x2758))(glContext,3000);
        glContextPtr275c = *(code **)(glContext + 0x275c);
        *(int *)(0x00002748 + glContext + 4) = iVar6;
        (*glContextPtr275c)(glContext,iVar6);
        iVar10 = *(int *)(0x00002748 + glContext + 4);
        ((int (*)())FUN_000a6500)(glContext,uVar9);
        *(int *)(iVar6 + 0x10) = *(int *)(0x00002748 + glContext + 4) - iVar10 >> 2;
        ((int (*)())FUN_000a6860)(glContext,param_2);
        *(int *)(iVar6 + 0x14) = *(int *)(glContext + 0x2794) - iVar10 >> 2;
        goto LAB_000a6ebc;
      }
    }
    else {
      uVar8 = param_2 >> 10 & 1;
      if ((uVar8 != 0) || ((*(uint *)(glContext + 0x8c) & 0x20000000) == 0)) goto LAB_000a6db0;
    }
    if (!bVar1) {
      *(undefined1 *)(iVar10 + 0xc5) = 1;
    }
  }
  else {
    bVar1 = (param_2 >> 8 & 1) == 0;
    if (!bVar1) goto LAB_000a6d70;
  }
  uVar8 = param_2 >> 10 & 1;
  ((int (*)())FUN_000a6860)(glContext,param_2);
LAB_000a6ebc:
  if (uVar8 != 0) {
    *(uint *)(glContext + 0x8c) = *(uint *)(glContext + 0x8c) | 0x20000000;
  }
  glContextPtr4 = *(int *)(glContext + 4);
  FUN_0004ce30(glContext);
  puVar4 = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,5);
  *(undefined4 **)(0x00002748 + glContext + 4) = puVar4;
  puVar3 = *(uint **)(glContextPtr4 + 0x1d8);
  *puVar3 = (int)puVar4 - (int)puVar3 >> 2 | *puVar3;
  *(undefined4 **)(glContextPtr4 + 0x1d8) = puVar4;
  *puVar4 = 0x2f000000;
  puVar4[1] = ((unsigned char *)0x000010e9U);
  glContextWord1ae0 = *(undefined4 *)(glContext + 0x1ae0);
  puVar4[3] = ((unsigned char *)0x000013c7U);
  puVar4[2] = glContextWord1ae0;
  puVar4[4] = *(undefined4 *)(glContext + 0x1ab0);
  *(undefined4 **)(0x00002748 + glContext + 4) = puVar4 + 5;
                    
                    
  (**(code **)(glContext + 0x275c))(glContext,puVar4 + 5);
  return;
}

/* FUN_000a6f70 @ 0xa6f70 (8 bytes) */
int FUN_000a6f70(param_1)
  undefined4 param_1;
{
  return (int)_calloc(param_1,1);
}

/* noop_a6f80 @ 0xa6f80 (4 bytes) */
int noop_a6f80()
{
  return;
}

/* FUN_000a6f90 @ 0xa6f90 (168 bytes) */
void FUN_000a6f90(float *outVector,float *inVector,double fpPassThrough1)
{
  float fVar1;
  float fVar2;
  double dVar3;
  
  fVar1 = FLOAT_001aa0d4;
  fVar2 = *inVector;
  dVar3 = (double)(inVector[2] * inVector[2] + fVar2 * fVar2 + inVector[1] * inVector[1]);
  if (dVar3 <= (double)FLOAT_001aa0d4) {
    outVector[2] = FLOAT_001aa0d4;
    *outVector = fVar1;
    outVector[1] = fVar1;
  }
  else {
    dVar3 = _sqrt(dVar3);
    fVar1 = (float)(DOUBLE_001aa200 / dVar3);
    *outVector = fVar2 * fVar1;
    outVector[1] = fVar1 * inVector[1];
    outVector[2] = fVar1 * inVector[2];
  }
  return;
}

/* FUN_000a7050 @ 0xa7050 (2324 bytes) */
int FUN_000a7050(ctx)
  int ctx;
{
  uint ctxWord284;
  uint ctxWord2cc;
  code *ctxPtr250;
  int ctxPtr244;
  char ctxByte1aa8;
  undefined *puVar2;
  undefined *puVar3;
  code *ctxPtr24c;
  int iVar5;
  undefined4 uVar6;
  undefined4 a1;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  code *a4;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int remaining;
  undefined8 uVar11;
  
  iVar9 = ctx + 0x240;
  uVar7 = 0x3e000000;
  *(undefined1 *)(ctx + 0x26b) = 0;
  puVar2 = PTR_001e8a58;
  a4 = FUN_000a6f70;
  *(undefined **)(ctx + 0x250) = PTR_001e8b14;
  *(undefined **)(ctx + 0x254) = puVar2;
  puVar2 = PTR_001e8aa4;
  *(undefined **)(ctx + 600) = PTR_001e8a3c;
  *(undefined **)(((unsigned char *)0x00001584) + ctx) = puVar2;
  puVar2 = PTR_FUN_001e8aa8;
  *(undefined **)(ctx + 0x2998) = PTR_FUN_001e8ab0;
  *(undefined **)(ctx + 0x299c) = puVar2;
  puVar2 = PTR_FUN_001e8ae0;
  *(undefined **)(((unsigned char *)0x000014c0) + ctx) = PTR_FUN_001e8acc;
  *(undefined **)(((unsigned char *)0x000014c8) + ctx) = puVar2;
  puVar2 = PTR_FUN_001e8ae8;
  *(undefined **)(((unsigned char *)0x000014d0) + ctx) = PTR_FUN_001e8abc;
  *(undefined **)(((unsigned char *)0x000014c4) + ctx) = puVar2;
  puVar2 = PTR_FUN_001e8b38;
  *(undefined **)(((unsigned char *)0x000014cc) + ctx) = PTR_FUN_001e8a2c;
  *(undefined **)(((unsigned char *)0x000014d4) + ctx) = puVar2;
  *(undefined4 *)(((unsigned char *)0x00001604) + ctx) = 0x3f800000;
  *(undefined4 *)(((unsigned char *)0x00001628) + ctx) = 0x3e000000;
  puVar3 = PTR_FUN_001e8b28;
  puVar2 = PTR_FUN_001e8a48;
  *(code **)(ctx + 0x24c) = FUN_000a6f70;
  *(int *)(ctx + 0x244) = ctx;
  *(undefined4 *)(((unsigned char *)0x0000162c) + ctx) = 0x42800000;
  *(undefined4 *)(((unsigned char *)0x00001608) + ctx) = 0x42800000;
  *(undefined4 *)((int)((unsigned char *)0x00001624) + ctx) = 0x80;
  *(int *)(ctx + 0x25c) = iVar9;
  *(undefined **)(((unsigned char *)0x000014e8) + ctx) = puVar2;
  *(undefined **)(((unsigned char *)0x000014d8) + ctx) = puVar3;
  *(undefined4 *)(((unsigned char *)0x0000145c) + ctx) = 0;
  puVar2 = PTR_FUN_001e8a18;
  *(undefined **)(((unsigned char *)0x000014dc) + ctx) = PTR_FUN_001e8aa0;
  *(undefined **)(((unsigned char *)0x000014e4) + ctx) = puVar2;
  *(undefined **)(((unsigned char *)0x000014e0) + ctx) = PTR_FUN_001e8b00;
  *(undefined **)(((unsigned char *)0x000014ec) + ctx) = PTR_FUN_001e8a08;
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
  uVar6 = ((int (*)())FUN_000a6f70)(0xa8);
  ctxPtr24c = *(code **)(ctx + 0x24c);
  *(undefined4 *)(((unsigned char *)0x000016dc) + ctx) = 0x20;
  *(undefined4 *)(((unsigned char *)0x000013ac) + ctx) = uVar6;
  uVar11 = (*ctxPtr24c)(0x90);
  ctxPtr24c = *(code **)(ctx + 0x24c);
  *(int *)(((unsigned char *)0x00001394) + ctx) = (int)((ulonglong)uVar11 >> 0x20);
  *(undefined2 *)(((unsigned char *)0x0000138a) + ctx) = 8;
  *(undefined2 *)(((unsigned char *)0x00001388) + ctx) = 6;
  ((unsigned char *)0x00001390)[ctx] = 2;
  *(undefined2 *)(((unsigned char *)0x0000138e) + ctx) = 8;
  *(undefined2 *)(((unsigned char *)0x0000138c) + ctx) = 0x10;
  uVar6 = (*ctxPtr24c)(0x14,(int)uVar11,staleArgR5,staleArgR6,a4,uVar7,ctxPtr24c);
  ctxWord2cc = *(uint *)(ctx + 0x2cc);
  *(undefined4 *)(((unsigned char *)0x0000136c) + ctx) = uVar6;
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
  uVar6 = 0;
  *(uint *)(ctx + 0x2cc) = ctxWord2cc & 0xc02fffff | 0x40200000;
  *(undefined4 *)(ctx + 0x1ef8) = 0xaaaaaaaa;
  iVar5 = iVar9;
  do {
    *(undefined4 *)(iVar5 + 0x98) = 0;
    iVar5 = iVar5 + 4;
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
  uVar8 = *(uint *)(ctxPtr244 + 0x24) & 0x7ff00000;
  if ((((uVar8 == 0x800000) || (uVar8 == 0x100000)) || (uVar8 == 0x200000)) || (uVar8 == 0x400000))
  {
    *(undefined4 *)(ctx + 0x1e20) = 0x600;
    *(undefined4 *)(0x00002688 + ctx) = 0x400;
    *(undefined4 *)(ctx + 0x268c) = 0x606;
    *(undefined4 *)(((unsigned char *)0x00001634) + ctx) = 0x400;
    *(undefined **)(ctx + 0x2168) = ((unsigned char *)0x0000101dU);
    uVar8 = *(uint *)(ctxPtr244 + 0x24) & 0x7ff00000;
    if (uVar8 == 0x800000) {
      *(uint *)(ctx + 0x2694) = *(uint *)(ctx + 0x2694) | 0x80000000;
    }
    else if (uVar8 == 0x100000) {
      *(uint *)(ctx + 0x2694) = *(uint *)(ctx + 0x2694) | 0x40000000;
    }
    else if (uVar8 == 0x200000) {
      *(uint *)(ctx + 0x2694) = *(uint *)(ctx + 0x2694) | 0x8000000;
    }
    else if (uVar8 == 0x400000) {
      *(uint *)(ctx + 0x2694) = *(uint *)(ctx + 0x2694) | 0x2000000;
    }
  }
  uVar7 = 0;
  FUN_000b6020(iVar9,0,0);
  *(undefined1 *)(ctx + 0x1aa9) = 0;
  *(undefined1 *)(ctx + 0x1aa8) = 0;
  *(undefined4 *)(ctx + 0x1aa4) = 0;
  FUN_000ab900(iVar9);
  puVar2 = PTR_FUN_001e8b18;
  ctxByte1aa8 = *(char *)(ctx + 0x1aa8);
  *(undefined **)(((unsigned char *)0x000014f0) + ctx) = PTR_FUN_001e8a20;
  *(undefined **)(((unsigned char *)0x000014f4) + ctx) = puVar2;
  if (ctxByte1aa8 == '\0') {
    *(undefined **)(((unsigned char *)0x000014f8) + ctx) = PTR_FUN_001e8a60;
  }
  else {
    *(undefined **)(((unsigned char *)0x000014f8) + ctx) = PTR_FUN_001e8af4;
  }
  puVar2 = PTR_FUN_001e8ac4;
  *(undefined **)(((unsigned char *)0x0000157c) + ctx) = PTR_FUN_001e8a44;
  *(undefined **)(((unsigned char *)0x00001580) + ctx) = puVar2;
  puVar3 = PTR_FUN_001e8aac;
  puVar2 = PTR_FUN_001e8a38;
  if (ctxByte1aa8 == '\0') {
    *(undefined4 *)(((unsigned char *)0x0000151c) + ctx) = 0;
    *(undefined4 *)(((unsigned char *)0x000014fc) + ctx) = 0;
    *(undefined4 *)(((unsigned char *)0x00001514) + ctx) = 0;
    *(undefined4 *)(((unsigned char *)0x00001518) + ctx) = 0;
    puVar2 = PTR_FUN_001e8b20;
    *(undefined **)(((unsigned char *)0x00001500) + ctx) = PTR_FUN_001e8a84;
    *(undefined **)(((unsigned char *)0x00001510) + ctx) = puVar2;
    puVar2 = PTR_FUN_001e8a4c;
    *(undefined **)(((unsigned char *)0x00001504) + ctx) = PTR_FUN_001e8a14;
    *(undefined **)(((unsigned char *)0x00001524) + ctx) = puVar2;
    puVar2 = PTR_FUN_001e8b30;
    *(undefined **)(((unsigned char *)0x00001520) + ctx) = PTR_FUN_001e8b0c;
    *(undefined **)(((unsigned char *)0x0000152c) + ctx) = puVar2;
    puVar2 = PTR_FUN_001e8a30;
    *(undefined **)(((unsigned char *)0x00001528) + ctx) = PTR_FUN_001e8af8;
    *(undefined **)(((unsigned char *)0x00001534) + ctx) = puVar2;
    puVar2 = PTR_FUN_001e8a5c;
    *(undefined **)(((unsigned char *)0x00001530) + ctx) = PTR_FUN_001e8a80;
    *(undefined **)(((unsigned char *)0x0000153c) + ctx) = puVar2;
    puVar2 = PTR_FUN_001e8a28;
    *(undefined **)(((unsigned char *)0x00001538) + ctx) = PTR_FUN_001e8aec;
    *(undefined **)(((unsigned char *)0x00001544) + ctx) = puVar2;
    *(undefined **)(((unsigned char *)0x00001540) + ctx) = PTR_FUN_001e8a90;
    *(undefined **)(((unsigned char *)0x00001548) + ctx) = PTR_FUN_001e8a24;
    *(undefined **)(((unsigned char *)0x0000154c) + ctx) = PTR_FUN_001e8a1c;
    puVar2 = PTR_FUN_001e8a34;
    *(undefined **)(((unsigned char *)0x00001550) + ctx) = PTR_FUN_001e8a78;
    *(undefined **)(((unsigned char *)0x00001554) + ctx) = puVar2;
    puVar2 = PTR_FUN_001e8a00;
    *(undefined **)(((unsigned char *)0x00001558) + ctx) = PTR_FUN_001e8b2c;
    *(undefined **)(((unsigned char *)0x0000155c) + ctx) = puVar2;
    puVar2 = PTR_FUN_001e8b24;
    *(undefined **)(((unsigned char *)0x00001560) + ctx) = PTR_FUN_001e8a8c;
    *(undefined **)(((unsigned char *)0x00001564) + ctx) = puVar2;
    puVar2 = PTR_FUN_001e8ad4;
    *(undefined **)(((unsigned char *)0x00001568) + ctx) = PTR_FUN_001e89f8;
    *(undefined **)(((unsigned char *)0x0000156c) + ctx) = puVar2;
  }
  else {
    *(undefined4 *)(((unsigned char *)0x00001520) + ctx) = 0;
    *(undefined **)(((unsigned char *)0x000014fc) + ctx) = puVar3;
    *(undefined **)(((unsigned char *)0x00001500) + ctx) = puVar2;
    puVar2 = PTR_FUN_001e8a50;
    *(undefined **)(((unsigned char *)0x00001510) + ctx) = PTR_FUN_001e8ad0;
    *(undefined **)(((unsigned char *)0x00001504) + ctx) = puVar2;
    puVar2 = PTR_FUN_001e8b34;
    *(undefined **)(((unsigned char *)0x00001514) + ctx) = PTR_FUN_001e8b08;
    *(undefined **)(((unsigned char *)0x00001518) + ctx) = puVar2;
    puVar2 = PTR_FUN_001e8a64;
    *(undefined **)(((unsigned char *)0x0000151c) + ctx) = PTR_FUN_001e8a70;
    *(undefined **)(((unsigned char *)0x00001528) + ctx) = puVar2;
    puVar2 = PTR_FUN_001e8ac0;
    *(undefined **)(((unsigned char *)0x00001524) + ctx) = PTR_FUN_001e8a10;
    *(undefined **)(((unsigned char *)0x00001530) + ctx) = puVar2;
    puVar2 = PTR_FUN_001e8a7c;
    *(undefined **)(((unsigned char *)0x0000152c) + ctx) = PTR_FUN_001e8a74;
    *(undefined **)(((unsigned char *)0x00001538) + ctx) = puVar2;
    puVar2 = PTR_FUN_001e8ab4;
    *(undefined **)(((unsigned char *)0x00001534) + ctx) = PTR_FUN_001e8af0;
    *(undefined **)(((unsigned char *)0x00001540) + ctx) = puVar2;
    puVar2 = PTR_FUN_001e8adc;
    *(undefined **)(((unsigned char *)0x0000153c) + ctx) = PTR_FUN_001e8a0c;
    *(undefined **)(((unsigned char *)0x00001544) + ctx) = PTR_FUN_001e8a40;
    *(undefined **)(((unsigned char *)0x00001548) + ctx) = puVar2;
    puVar2 = PTR_FUN_001e8a98;
    *(undefined **)(((unsigned char *)0x0000154c) + ctx) = PTR_FUN_001e8b10;
    *(undefined **)(((unsigned char *)0x00001550) + ctx) = puVar2;
    puVar2 = PTR_FUN_001e8a9c;
    *(undefined **)(((unsigned char *)0x00001554) + ctx) = PTR_FUN_001e8a54;
    *(undefined **)(((unsigned char *)0x00001558) + ctx) = puVar2;
    puVar2 = PTR_FUN_001e8ab8;
    *(undefined **)(((unsigned char *)0x0000155c) + ctx) = PTR_FUN_001e8b04;
    *(undefined **)(((unsigned char *)0x00001560) + ctx) = puVar2;
    puVar2 = PTR_FUN_001e8ad8;
    *(undefined **)(((unsigned char *)0x00001564) + ctx) = PTR_FUN_001e8a94;
    *(undefined **)(((unsigned char *)0x00001568) + ctx) = puVar2;
    *(undefined **)(((unsigned char *)0x0000156c) + ctx) = PTR_FUN_001e8b1c;
  }
  *(code **)(((unsigned char *)0x00001588) + ctx) = FUN_000a6f90;
  ffvpInitContextState(iVar9,0x80);
  ctxPtr250 = *(code **)(ctx + 0x250);
  *(undefined1 *)(ctx + 0x2691) = 0;
  *(undefined1 *)(ctx + 0x365) = 0;
  *(undefined1 *)(ctx + 0x36b) = 1;
  *(undefined2 *)(ctx + 0x20ac) = 1;
  *(undefined1 *)(ctx + 0x366) = 1;
  *(undefined1 *)(ctx + 0x364) = 1;
  *(undefined4 *)(ctx + 0x37c) = 1;
  ((unsigned char *)0x00002b81)[ctx] = 1;
  uVar7 = (*ctxPtr250)(1,((unsigned char *)0x00003754U),uVar7,staleArgR6,a4,uVar6,0);
  *(undefined4 *)(ctx + 0x20a0) = uVar7;
  FUN_0004ab60(iVar9);
  *(undefined2 *)(((unsigned char *)0x000015c8) + *(int *)(ctx + 0x20a0)) = 0xffff;
  *(undefined4 *)(((unsigned char *)0x0000135c) + ctx) = 5;
  uVar7 = (**(code **)(ctx + 0x250))(1,0x14);
  ctxPtr24c = *(code **)(ctx + 0x24c);
  *(undefined2 *)(((unsigned char *)0x00001350) + ctx) = 5;
  *(undefined4 *)(((unsigned char *)0x00001358) + ctx) = uVar7;
  uVar7 = (*ctxPtr24c)(10);
  *(undefined4 *)(((unsigned char *)0x00001354) + ctx) = uVar7;
  iVar5 = (uint)*(ushort *)(((unsigned char *)0x00001350) + ctx) << 1;
  _memset(uVar7,0xff,iVar5);
  ctxPtr24c = *(code **)(ctx + 0x24c);
  *(undefined4 *)(0x000020b4 + ctx) = 0;
  *(undefined4 *)(ctx + 0x20b8) = 0x10;
  uVar6 = (*ctxPtr24c)(0x40,a1,iVar5,staleArgR6,a4,uVar6,ctxPtr24c);
  *(undefined4 *)(ctx + 0x20bc) = uVar6;
  gldInitStateDefaults(iVar9);
  puVar2 = PTR_FUN_001e8afc;
  *(undefined **)(((unsigned char *)0x000013e0) + ctx) = PTR_FUN_001e89c4;
  *(undefined **)(((unsigned char *)0x00001398) + ctx) = puVar2;
  puVar2 = PTR_FUN_001e89fc;
  *(code **)(((unsigned char *)0x0000139c) + ctx) = noop_a6f80;
  puVar3 = PTR_FUN_001e8a6c;
  *(undefined **)(((unsigned char *)0x000014b4) + ctx) = puVar2;
  puVar2 = PTR_FUN_001e8a68;
  *(undefined **)(((unsigned char *)0x000014b8) + ctx) = puVar3;
  puVar3 = PTR_FUN_001e8a88;
  *(undefined **)(((unsigned char *)0x000014bc) + ctx) = puVar2;
  *(undefined **)(((unsigned char *)0x00001464) + ctx) = puVar3;
  /* Completed (issue #64): the whole 3-call missing block (stock 0xa7178-0xa72b0ish) is now
   * restored, in stock's real order, sizes and destinations all confirmed directly from
   * disassembly (each call's "li r3,N" immediately precedes its bctrl; each destination is the
   * "stw r3,OFFSET(r30)" immediately after): calloc(0xa8)->+0x116c, calloc(0x90)->+0x1154,
   * calloc(0x14)->+0x112c, all through the same locally-installed FUN_000a6f70 callback already
   * used elsewhere in this function. The middle call (+0x1154) was the one already fixed and
   * verified to resolve the original atifsCreateShaderTable null-deref crash on this issue. The other two
   * were left as an open follow-up at the time - re-derived and added here after a *different*,
   * later crash (FUN_00193c00, deep in the GLSL shader-compiler call chain) traced back to this
   * same still-missing block. */
  *(int *)(iVar9 + 0x116c) = ((int (*)())FUN_000a6f70)(0xa8);
  *(int *)(iVar9 + 0x1154) = ((int (*)())FUN_000a6f70)(0x90);
  *(int *)(iVar9 + 0x112c) = ((int (*)())FUN_000a6f70)(0x14);
  ((int (*)())atifsCreateShaderTable)(iVar9);
  arbProgramTableInit(iVar9);
  arbfpLoadDefaultProgram(iVar9);
  *(undefined1 *)(ctx + 0x26f) = 1;
  puVar2 = PTR_FUN_001e8a04;
  *(undefined **)(((unsigned char *)0x00001570) + ctx) = PTR_FUN_001e8ac8;
  *(undefined **)(((unsigned char *)0x00001574) + ctx) = puVar2;
  puVar2 = PTR_FUN_001e89f4;
  *(undefined **)(((unsigned char *)0x00001578) + ctx) = PTR_DAT_001e8ae4;
  *(undefined **)(((unsigned char *)0x00002b8c) + ctx) = puVar2;
  return;
}

/* gldFreeEngineState @ 0xa7970 (240 bytes) */
int gldFreeEngineState(ctx)
  int ctx;
{
  int iVar1;
  
  iVar1 = ctx + 0x240;
  ((int (*)())FUN_000a4490)(iVar1);
  ((int (*)())FUN_000a43f0)(iVar1);
  FUN_000b5fb0(iVar1);
  FUN_0004b710(iVar1);
  fpVariantCacheFlush(iVar1);
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
  arbProgramTableRelease(iVar1);
  if (*(int *)(ctx + 0x1aa4) != 0) {
    (**(code **)(ctx + 600))(*(int *)(ctx + 0x1aa4));
    *(undefined4 *)(ctx + 0x1aa4) = 0;
  }
  return;
}

/* FUN_000a7a60 @ 0xa7a60 (496 bytes) */
int FUN_000a7a60(ctx)
  int ctx;
{
  uint loopIndex2;
  uint loopIndex;
  int remaining2;
  uint ctxWord1ae4;
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  uint ctxWord1ae4_2;
  int iVar6;
  int iVar7;
  int remaining;
  
  puVar1 = PTR_DAT_001e88c8;
  iVar7 = ctx + 0x240;
  ((unsigned char *)0x000015f8)[ctx] = ((unsigned char *)0x00002b7c)[ctx];
  ctxWord1ae4_2 = *(uint *)(ctx + 0x1ae4);
  uVar2 = *(uint *)(puVar1 + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24 + 0x18);
  uVar4 = *(uint *)(puVar1 + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24 + 0x1c);
  *(uint *)(ctx + 0x1ae4) = ctxWord1ae4_2 & 0xffc0003f;
  piVar3 = *(int **)(*(int *)(ctx + 0x18) + 0x1a0);
  uVar2 = uVar4 >> 0xe & 0xc000 |
          uVar4 >> 0x12 & 0x3000 | (uVar2 & 6) << 9 | (uVar2 & 0x18) << 5 | uVar2 >> 5 & 0x1f;
  if (piVar3 == (int *)0x0) {
    loopIndex = 0;
    remaining = 4;
    iVar6 = iVar7;
    do {
      if (*(short *)(((unsigned char *)0x00002dba) + loopIndex * 2 + *(int *)(ctx + 0x10)) == 0) {
        *(undefined4 *)(iVar6 + 0x233c) = 0xf;
      }
      else {
        *(uint *)(iVar6 + 0x233c) = uVar2;
        *(uint *)(ctx + 0x1ae4) =
             ((*(uint *)(ctx + 0x1ae4) >> 6 | 1 << (loopIndex & 0x3f)) & 0xffff) << 6 |
             *(uint *)(ctx + 0x1ae4) & 0xffc0003f;
      }
      loopIndex = loopIndex + 1;
      iVar6 = iVar6 + 4;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  else {
    loopIndex2 = 0;
    remaining2 = 4;
    iVar6 = iVar7;
    do {
      if (*(short *)(loopIndex2 * 2 + *piVar3 + 0x90) == 0) {
        *(undefined4 *)(iVar6 + 0x233c) = 0xf;
      }
      else {
        *(uint *)(iVar6 + 0x233c) = uVar2;
        *(uint *)(ctx + 0x1ae4) =
             ((*(uint *)(ctx + 0x1ae4) >> 6 | 1 << (loopIndex2 & 0x3f)) & 0xffff) << 6 |
             *(uint *)(ctx + 0x1ae4) & 0xffc0003f;
      }
      loopIndex2 = loopIndex2 + 1;
      iVar6 = iVar6 + 4;
      remaining2 = remaining2 + -1;
    } while (remaining2 != 0);
  }
  ctxWord1ae4 = *(uint *)(ctx + 0x1ae4);
  uVar2 = ctxWord1ae4 >> 6 & 0xffff;
  if (*(int *)(((unsigned char *)0x00001448) + uVar2 * 4 + iVar7) == 0) {
    FUN_000b6020(iVar7,0,uVar2);
    ctxWord1ae4 = *(uint *)(ctx + 0x1ae4);
  }
  if ((((ctxWord1ae4_2 >> 6 & 0xffff) != (ctxWord1ae4 >> 6 & 0xffff)) && ((ctxWord1ae4 & 0x3fffc0) != 0)) &&
     (((unsigned char *)0x0000430c)[*(int *)(ctx + 0x10)] == '\0')) {
    FUN_000b6580(iVar7,0);
    (**(code **)(((unsigned char *)0x00002b8c) + ctx))(iVar7,*(undefined4 *)(ctx + 0x209c));
  }
  *(uint *)(ctx + 0x1b70) = *(uint *)(ctx + 0x1b70) | 0x40;
  return;
}

/* gldMarkAllStateDirty @ 0xa7c60 (176 bytes) */
int gldMarkAllStateDirty(glContext)
  int glContext;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)(byte)((unsigned char *)0x000013b5)[glContext];
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
  if (uVar2 != 0) {
    iVar1 = glContext;
    if (uVar2 == 0) {
      uVar2 = 1;
    }
    do {
      *(undefined1 *)(iVar1 + 0x1814) = 0x3f;
      *(undefined1 *)(iVar1 + 0x181c) = 3;
      iVar1 = iVar1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
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
