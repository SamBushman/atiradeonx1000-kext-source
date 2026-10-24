#include "decls.h"

/* FUN_00053dc0 @ 0x53dc0 (20 bytes) */
int FUN_00053dc0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 8);
  *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 8) = iVar1 + param_2;
  return iVar1;
}

/* extvsDeleteShaderObject @ 0x53de0 (268 bytes) */
int extvsDeleteShaderObject(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint loopIndex;
  
  iVar3 = *(int *)(((unsigned char *)0x0000116c) + param_1);
  if (*(int *)(*(int *)(((unsigned char *)0x00001168) + param_1) + 8) == param_2) {
    extvsBindShader(param_1,0);
  }
  loopIndex = 0;
  iVar2 = 0;
  bVar1 = true;
  while (loopIndex < *(uint *)(iVar3 + 4)) {
    if (!bVar1) goto LAB_00053e6c;
    if (param_2 == *(int *)(iVar2 + *(int *)(iVar3 + 0xc) + 8)) {
      bVar1 = false;
    }
    else {
      loopIndex = loopIndex + 1;
      iVar2 = iVar2 + 0x7c;
    }
  }
  if (!bVar1) {
LAB_00053e6c:
    iVar2 = loopIndex * 0x7c + *(int *)(iVar3 + 0xc);
    if (*(int *)(iVar2 + 0xc) == 0) {
      ((int (*)())extvsFreeShaderObject)(param_1,iVar2);
      iVar2 = loopIndex * 0x7c + *(int *)(iVar3 + 0xc);
      _memmove(iVar2,iVar2 + 0x7c,(*(int *)(iVar3 + 4) - loopIndex) * 0x7c + -0x7c);
      *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) + -1;
      if (loopIndex < *(uint *)(((unsigned char *)0x00001188) + param_1)) {
        iVar2 = *(uint *)(((unsigned char *)0x00001188) + param_1) - 1;
        *(int *)(((unsigned char *)0x00001188) + param_1) = iVar2;
        *(int *)(((unsigned char *)0x00001168) + param_1) = iVar2 * 0x7c + *(int *)(iVar3 + 0xc);
      }
    }
  }
  return;
}

/* glDeleteVertexShaderEXT_impl @ 0x53ef0 (12 bytes) */
int glDeleteVertexShaderEXT_impl(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if (param_2 == 0) {
    return;
  }
  return ((int (*)())extvsDeleteShaderObject)(param_1,param_2);
}

/* glShaderOp1EXT_impl @ 0x53f00 (124 bytes) */
int glShaderOp1EXT_impl(ctx, op, resultId, arg1)
  int ctx;
  undefined4 op;
  undefined4 resultId;
  undefined4 arg1;
{
  if (((unsigned char *)0x00001170)[ctx] != '\0') {
    ((int (*)())extvsAppendInstruction)(ctx,*(undefined4 *)(((unsigned char *)0x00001168) + ctx),op,resultId,&DAT_001db9a8,
                 arg1,&DAT_001db998,0,&DAT_001db998,0,&DAT_001db998);
  }
  return;
}

/* glShaderOp2EXT_impl @ 0x53f80 (124 bytes) */
int glShaderOp2EXT_impl(ctx, op, resultId, arg1, arg2)
  int ctx;
  undefined4 op;
  undefined4 resultId;
  undefined4 arg1;
  undefined4 arg2;
{
  if (((unsigned char *)0x00001170)[ctx] != '\0') {
    ((int (*)())extvsAppendInstruction)(ctx,*(undefined4 *)(((unsigned char *)0x00001168) + ctx),op,resultId,&DAT_001db9a8,
                 arg1,&DAT_001db998,arg2,&DAT_001db998,0,&DAT_001db998);
  }
  return;
}

/* glShaderOp3EXT_impl @ 0x54000 (128 bytes) */
int glShaderOp3EXT_impl(ctx, op, resultId, arg1, arg2, arg3)
  int ctx;
  undefined4 op;
  undefined4 resultId;
  undefined4 arg1;
  undefined4 arg2;
  undefined4 arg3;
{
  if (((unsigned char *)0x00001170)[ctx] != '\0') {
    ((int (*)())extvsAppendInstruction)(ctx,*(undefined4 *)(((unsigned char *)0x00001168) + ctx),op,resultId,&DAT_001db9a8,
                 arg1,&DAT_001db998,arg2,&DAT_001db998,arg3,&DAT_001db998);
  }
  return;
}

/* FUN_00054080 @ 0x54080 (276 bytes) */
int FUN_00054080(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  uint param_5;
  uint param_6;
  uint param_7;
{
  int iVar1;
  int iVar2;
  int local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  if (((((((unsigned char *)0x00001170)[param_1] != '\0') && (param_4 - 0x87d5U < 0xb)) && (0x87d4 < param_5)) &&
      ((param_5 < 0x87e0 && (0x87d4 < param_6)))) &&
     ((param_6 < 0x87e0 && ((0x87d4 < param_7 && (param_7 < 0x87e0)))))) {
    iVar2 = *(int *)(((unsigned char *)0x00001168) + param_1);
    local_28 = param_4;
    local_24 = param_5;
    local_20 = param_6;
    local_1c = param_7;
    iVar1 = ((int (*)())extvsAppendInstruction)(param_1,iVar2,0x879a,param_2,&DAT_001db9a8,param_3,&local_28,0,
                         &DAT_001db998,0,&DAT_001db998);
    if ((iVar1 != 0) && (param_2 - 0x879dU < 0x10)) {
      *(undefined1 *)((param_2 - 0x879dU) + iVar2 + 0x44) = 1;
    }
  }
  return;
}

/* glWriteMaskEXT_impl @ 0x541a0 (196 bytes) */
int glWriteMaskEXT_impl(ctx, resultId, sourceId, enableX, enableY, enableZ, enableW)
  int ctx;
  undefined4 resultId;
  undefined4 sourceId;
  uint enableX;
  uint enableY;
  uint enableZ;
  uint enableW;
{
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  if ((((((unsigned char *)0x00001170)[ctx] != '\0') && (enableX < 2)) && (enableY < 2)) &&
     ((enableZ < 2 && (enableW < 2)))) {
    local_28 = enableX;
    local_24 = enableY;
    local_20 = enableZ;
    local_1c = enableW;
    ((int (*)())extvsAppendInstruction)(ctx,*(undefined4 *)(((unsigned char *)0x00001168) + ctx),0x879b,resultId,&local_28,sourceId,
                 &DAT_001db998,0,&DAT_001db998,0,&DAT_001db998);
  }
  return;
}

/* glInsertComponentEXT_impl @ 0x54270 (308 bytes) */
int glInsertComponentEXT_impl(ctx, resultId, sourceId, componentIndex)
  int ctx;
  undefined4 resultId;
  undefined4 sourceId;
  uint componentIndex;
{
  int extvsOperandDataTypeResult;
  int iVar1;
  int iVar2;
  
  if ((((unsigned char *)0x00001170)[ctx] != '\0') && (componentIndex < 4)) {
    iVar2 = *(int *)(((unsigned char *)0x00001168) + ctx);
    iVar1 = ((int (*)())extvsAppendInstruction)(ctx,iVar2,0x879c,resultId,&DAT_001db9a8,sourceId,&DAT_001db998,0,
                         &DAT_001db998,0,&DAT_001db998);
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar2 + 0x14) * 0x74 + *(int *)(iVar2 + 0x18);
      extvsOperandDataTypeResult = ((int (*)())extvsOperandDataType)(iVar2 + 0x1c,iVar1 + -0x70);
      if (extvsOperandDataTypeResult == 0x87bf) {
        if (componentIndex == 1) {
          *(undefined4 *)(iVar1 + -0x5c) = 0;
          *(undefined4 *)(iVar1 + -0x68) = 0;
          *(undefined4 *)(iVar1 + -0x60) = 0;
        }
        else if (componentIndex == 0) {
          *(undefined4 *)(iVar1 + -0x5c) = 0;
          *(undefined4 *)(iVar1 + -100) = 0;
          *(undefined4 *)(iVar1 + -0x60) = 0;
        }
        else if (componentIndex == 2) {
          *(undefined4 *)(iVar1 + -0x5c) = 0;
          *(undefined4 *)(iVar1 + -0x68) = 0;
          *(undefined4 *)(iVar1 + -100) = 0;
        }
        else if (componentIndex == 3) {
          *(undefined4 *)(iVar1 + -0x60) = 0;
          *(undefined4 *)(iVar1 + -0x68) = 0;
          *(undefined4 *)(iVar1 + -100) = 0;
        }
      }
      *(uint *)(iVar1 + -0x34) = componentIndex;
    }
  }
  return;
}

/* glExtractComponentEXT_impl @ 0x543b0 (164 bytes) */
int glExtractComponentEXT_impl(ctx, resultId, sourceId, componentIndex)
  int ctx;
  undefined4 resultId;
  undefined4 sourceId;
  uint componentIndex;
{
  int iVar1;
  int iVar2;
  
  if ((((unsigned char *)0x00001170)[ctx] != '\0') && (componentIndex < 4)) {
    iVar2 = *(int *)(((unsigned char *)0x00001168) + ctx);
    iVar1 = ((int (*)())extvsAppendInstruction)(ctx,iVar2,0x879d,resultId,&DAT_001db9a8,sourceId,&DAT_001db998,0,
                         &DAT_001db998,0,&DAT_001db998);
    if (iVar1 != 0) {
      *(uint *)(*(int *)(iVar2 + 0x14) * 0x74 + *(int *)(iVar2 + 0x18) + -0x34) = componentIndex;
    }
  }
  return;
}

/* FUN_00054460 @ 0x54460 (8 bytes) */
int FUN_00054460(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 uVar1;
  
  uVar1 = glGenSymbolsEXT_impl(param_1,param_2,param_3,param_4,param_5,0);
  return uVar1;
}

/* FUN_00054470 @ 0x54470 (272 bytes) */
int FUN_00054470(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  int *param_3;
  int *param_4;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0x1868) == '\0') {
    piVar2 = *(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + **(int **)(((unsigned char *)0x00001168) + param_1));
    iVar3 = *piVar2;
    *param_3 = piVar2[0x22];
    *param_4 = *(int *)(param_1 + 0x2448) + *(int *)(iVar3 + 0x14);
    iVar1 = *(int *)(iVar3 + 0x2b8);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(param_1 + 0xc))(0x80c);
      *(int *)(iVar3 + 0x2b8) = iVar1;
      *param_2 = iVar1;
      return 1;
    }
  }
  else {
    piVar2 = (int *)**(undefined4 **)
                      (*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + **(int **)(((unsigned char *)0x00001168) + param_1));
    *param_3 = piVar2[0x49];
    *param_4 = *(int *)(param_1 + 0x2448) + *piVar2;
    iVar1 = piVar2[0x4f6];
    if (iVar1 == 0) {
      iVar1 = (**(code **)(param_1 + 0xc))(0x80c);
      piVar2[0x4f6] = iVar1;
      *param_2 = iVar1;
      return 1;
    }
  }
  *param_2 = iVar1;
  return 0;
}

/* FUN_00054590 @ 0x54590 (288 bytes) */
int FUN_00054590(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int *param_4;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int loopIndex;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar1 = *(int *)(((unsigned char *)0x00001168) + param_1);
  if (param_3 == 0) {
    iVar9 = 0;
    iVar8 = 0;
    iVar7 = 0;
  }
  else {
    iVar4 = 0;
    loopIndex = 0;
    iVar7 = 0;
    iVar9 = 0;
    iVar8 = 0;
    puVar6 = param_2;
    do {
      iVar2 = *param_4;
      param_4 = param_4 + 1;
      iVar2 = *(int *)(iVar2 * 4 + *(int *)(iVar1 + 0x24)) * 0x54 + *(int *)(iVar1 + 0x20);
      if (*(char *)(iVar2 + 0x3d) == '\0') {
        if (loopIndex < (int)param_2[0x200]) {
          iVar9 = iVar9 + 1;
        }
        else if (loopIndex < (int)param_2[0x201]) {
          iVar7 = iVar7 + 1;
        }
        else {
          iVar8 = iVar8 + 1;
        }
      }
      else {
        uVar3 = puVar6[1];
        param_2[iVar4 * 2] = *puVar6;
        param_2[iVar4 * 2 + 1] = uVar3;
        *(char *)(param_2 + iVar4 * 2) = (char)*(undefined4 *)(iVar2 + 4);
        param_2[iVar4 * 2 + 1] = *(undefined4 *)(iVar2 + 0x38);
        iVar4 = iVar4 + 1;
      }
      loopIndex = loopIndex + 1;
      puVar6 = puVar6 + 2;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
    iVar7 = iVar7 + iVar9;
  }
  param_2[0x200] = param_2[0x200] - iVar9;
  param_2[0x201] = param_2[0x201] - iVar7;
  param_2[0x202] = param_2[0x202] - (iVar8 + iVar7);
  return;
}

/* FUN_000546d0 @ 0x546d0 (284 bytes) */
int FUN_000546d0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar2;
  uint loopIndex;
  
  (**(code **)(((unsigned char *)0x000011ac) + param_1))(param_1,param_2,0);
  (**(code **)(((unsigned char *)0x000011a4) + param_1))
            (param_1,param_2,*(undefined4 *)(((unsigned char *)0x0000118c) + param_1),in_r6,in_r7,in_r8,
             *(code **)(((unsigned char *)0x000011a4) + param_1));
  *(undefined4 *)(param_2 + 100) = 0;
  *(undefined4 *)(param_2 + 0x54) = 0;
  *(undefined4 *)(param_2 + 0x58) = 0;
  *(undefined4 *)(param_2 + 0x5c) = 0;
  *(undefined4 *)(param_2 + 0x60) = 0;
  if (*(int *)(param_2 + 0x1c) != 0) {
    loopIndex = 0;
    iVar2 = 0;
    do {
      loopIndex = loopIndex + 1;
      iVar1 = iVar2 + *(int *)(param_2 + 0x20);
      iVar2 = iVar2 + 0x54;
      *(undefined1 *)(iVar1 + 0x3d) = 0;
    } while (loopIndex < *(uint *)(param_2 + 0x1c));
  }
  (**(code **)(((unsigned char *)0x00001194) + param_1))(param_1,param_2);
  (**(code **)(((unsigned char *)0x0000119c) + param_1))(param_1,param_2);
  *(undefined4 *)(((unsigned char *)0x00001174) + param_1) = *(undefined4 *)(param_2 + 0x54);
  *(undefined4 *)(((unsigned char *)0x0000117c) + param_1) = *(undefined4 *)(param_2 + 0x58);
  *(undefined4 *)(((unsigned char *)0x00001178) + param_1) = *(undefined4 *)(param_2 + 0x5c);
  *(undefined4 *)(((unsigned char *)0x00001180) + param_1) = *(undefined4 *)(param_2 + 0x60);
  *(undefined4 *)(((unsigned char *)0x00001184) + param_1) = *(undefined4 *)(param_2 + 100);
  return;
}

/* glSetLocalConstantEXT_impl @ 0x547f0 (324 bytes) */
int glSetLocalConstantEXT_impl(ctx, symbolId, dataType, values)
  int ctx;
  undefined4 symbolId;
  int dataType;
  undefined4 *values;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (dataType - 0x1400U < 0xb) {
    iVar3 = *(int *)(((unsigned char *)0x00001168) + ctx);
    if ((*(char *)(ctx + 0x31) != '\0') &&
       (*(char *)(*(int *)(iVar3 + 4) + *(int *)(((unsigned char *)0x0000118c) + ctx)) != '\0')) {
      ((int (*)())FUN_000546d0)(ctx,iVar3);
    }
    iVar2 = ((int (*)())extvsSymbolListGetSymbol)(iVar3 + 0x1c,symbolId);
    if (((iVar2 != 0) && (*(int *)(iVar2 + 0x28) == 0x87c3)) && (*(char *)(iVar2 + 0x44) == '\0')) {
      puVar1 = *(undefined4 **)(iVar2 + 0x38);
      *puVar1 = *values;
      puVar1[1] = values[1];
      puVar1[2] = values[2];
      puVar1[3] = values[3];
      *(undefined1 *)(iVar2 + 0x44) = 1;
      iVar2 = ((int (*)())extvsSymbolListGetSymbol)(iVar3 + 0x1c,symbolId);
      if ((iVar2 != 0) && (*(char *)(iVar2 + 0x3d) != '\0')) {
        (**(code **)(*(int *)(iVar2 + 0x24) * 4 + ctx + -0x20bac))(ctx,iVar3,iVar2);
      }
      *(uint *)(ctx + 0x38) = *(uint *)(ctx + 0x38) | 0x1000;
      *(byte *)(ctx + 0x2d) = *(byte *)(ctx + 0x2d) | 1;
      *(undefined1 *)(ctx + 0x29) = 1;
    }
  }
  return;
}

/* extvsBindCurrentVertexParameter @ 0x54940 (56 bytes) */
int extvsBindCurrentVertexParameter(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  
  if (param_2 == 0x87e2) {
    uVar1 = extvsGetOrCreateStateSymbol(param_1,0,0,0x87bf,0x87c1,0);
    return uVar1;
  }
  return 0;
}

/* extvsFreeAllShaders @ 0x54980 (260 bytes) */
int extvsFreeAllShaders(param_1)
  int param_1;
{
  bool bVar1;
  int a0;
  int iVar2;
  int iVar3;
  uint loopIndex;
  int iVar5;
  
  iVar3 = *(int *)(((unsigned char *)0x0000116c) + param_1);
  if (*(int *)(iVar3 + 4) != 0) {
    loopIndex = 0;
    iVar5 = 0;
    do {
      loopIndex = loopIndex + 1;
      iVar2 = iVar5 + *(int *)(iVar3 + 0xc);
      iVar5 = iVar5 + 0x7c;
      ((int (*)())extvsFreeShaderObject)(param_1,iVar2);
    } while (loopIndex < *(uint *)(iVar3 + 4));
  }
  iVar2 = 0;
  (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0xc));
  *(undefined4 *)(iVar3 + 4) = 0;
  ((int (*)())extvsFreeSymbolData)(param_1,iVar3 + 0x14);
  iVar5 = iVar3;
  do {
    a0 = *(int *)(iVar5 + 0x28);
    while (a0 != 0) {
      *(int *)(iVar5 + 0x28) = *(int *)(a0 + 0xc);
      (**(code **)(param_1 + 0x18))(a0);
      a0 = *(int *)(iVar5 + 0x28);
    }
    bVar1 = iVar2 != 0x1f;
    iVar5 = iVar5 + 4;
    iVar2 = iVar2 + 1;
  } while (bVar1);
  (**(code **)(param_1 + 0x18))(iVar3);
  *(undefined4 *)(((unsigned char *)0x0000116c) + param_1) = 0;
  return;
}

/* extvsReleaseState @ 0x54a90 (120 bytes) */
int extvsReleaseState(param_1)
  int param_1;
{
  (**(code **)(((unsigned char *)0x000011a8) + param_1))(param_1);
  **(int **)(((unsigned char *)0x0000116c) + param_1) = **(int **)(((unsigned char *)0x0000116c) + param_1) + -1;
  if (**(int **)(((unsigned char *)0x0000116c) + param_1) == 0) {
    ((int (*)())extvsFreeAllShaders)(param_1);
    return;
  }
  return;
}

/* extvsInitState @ 0x54b20 (240 bytes) */
int extvsInitState(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = *(undefined4 **)(((unsigned char *)0x0000116c) + param_1);
  uVar1 = (**(code **)(param_1 + 0xc))(0x7c0);
  puVar2[9] = 0;
  puVar2[3] = uVar1;
  *puVar2 = 1;
  puVar2[1] = 1;
  puVar2[2] = 1;
  puVar2[4] = 1;
  ((int (*)())extvsInitShaderObject)(param_1,uVar1);
  *(undefined4 *)(puVar2[3] + 8) = 0;
  ((unsigned char *)0x00001170)[param_1] = 0;
  *(undefined4 *)(((unsigned char *)0x000011b4) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001188) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001174) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x0000117c) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001178) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001180) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001184) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x0000118c) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001168) + param_1) = puVar2[3];
  (**(code **)(((unsigned char *)0x000011a0) + param_1))(param_1);
  puVar2[9] = 0;
  ((int (*)())extvsInitSymbolListWithMVP)(param_1,puVar2 + 5);
  iVar3 = 0x20;
  do {
    puVar2[10] = 0;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

/* extvsAttachSharedState @ 0x54c10 (388 bytes) */
int extvsAttachSharedState(ctx, sourceCtx)
  int ctx;
  int sourceCtx;
{
  undefined4 oldByteArray;
  undefined4 newByteArray;
  int shaderEntry;
  int shaderOffset;
  int contextSlot;
  undefined4 newWordArray;
  uint loopIndex;
  undefined4 oldWordArray;
  int shaderArray;
  int *sharedState;
  
  **(int **)(((unsigned char *)0x0000116c) + ctx) = **(int **)(((unsigned char *)0x0000116c) + ctx) + -1;
  if (**(int **)(((unsigned char *)0x0000116c) + ctx) == 0) {
    ((int (*)())extvsFreeAllShaders)(ctx);
  }
  sharedState = *(int **)(((unsigned char *)0x0000116c) + sourceCtx);
  contextSlot = sharedState[4];
  *(int *)(((unsigned char *)0x0000118c) + ctx) = contextSlot;
  sharedState[4] = contextSlot + 1;
  ((unsigned char *)0x00001170)[ctx] = 0;
  *(undefined4 *)(((unsigned char *)0x00001188) + ctx) = 0;
  *(int **)(((unsigned char *)0x0000116c) + ctx) = sharedState;
  *(int *)(((unsigned char *)0x00001168) + ctx) = sharedState[3];
  *sharedState = *sharedState + 1;
  if (sharedState[1] != 0) {
    loopIndex = 0;
    shaderOffset = 0;
    do {
      shaderArray = sharedState[3];
      loopIndex = loopIndex + 1;
      oldWordArray = *(undefined4 *)(shaderOffset + shaderArray);
      newWordArray = (**(code **)(ctx + 0x10))(sharedState[4],4);
      *(undefined4 *)(shaderOffset + shaderArray) = newWordArray;
      _memcpy(*(undefined4 *)(sharedState[3] + shaderOffset),oldWordArray,sharedState[4] * 4 + -4);
      (**(code **)(ctx + 0x18))(oldWordArray);
      (**(code **)(((unsigned char *)0x000011a4) + ctx))
                (ctx,shaderOffset + sharedState[3],*(undefined4 *)(((unsigned char *)0x0000118c) + ctx));
      shaderArray = sharedState[3];
      oldByteArray = *(undefined4 *)(shaderOffset + shaderArray + 4);
      newByteArray = (**(code **)(ctx + 0x10))(sharedState[4],1);
      *(undefined4 *)(shaderOffset + shaderArray + 4) = newByteArray;
      shaderEntry = sharedState[3] + shaderOffset;
      shaderOffset = shaderOffset + 0x7c;
      _memcpy(*(undefined4 *)(shaderEntry + 4),oldByteArray,sharedState[4] + -1);
      (**(code **)(ctx + 0x18))(oldByteArray);
    } while (loopIndex < (uint)sharedState[1]);
  }
  return;
}

/* extvsSymbolListGetIndex @ 0x54da0 (36 bytes) */
int extvsSymbolListGetIndex(symbolList, position)
  int symbolList;
  uint position;
{
  if (*(uint *)(symbolList + 0xc) <= position) {
    return 0;
  }
  return *(undefined4 *)(position * 4 + *(int *)(symbolList + 8));
}

/* extvsAppendSymbol @ 0x54dd0 (376 bytes) */
int extvsAppendSymbol(ctx, symbolList, symbol)
  int ctx;
  uint *symbolList;
  int symbol;
{
  uint newIdIndex;
  uint newEntries;
  uint symbolId;
  uint entryIndex;
  
  entryIndex = *symbolList;
  if ((entryIndex & 0x3f) == 0) {
    newEntries = (**(code **)(ctx + 0xc))(((unsigned char *)0x00001500) + entryIndex * 0x54);
    if (newEntries != 0) {
      if (symbolList[1] != 0) {
        (**(code **)(((unsigned char *)0x00001344) + ctx))(newEntries,symbolList[1],*symbolList * 0x54);
        (**(code **)(ctx + 0x18))(symbolList[1]);
      }
      symbolList[1] = newEntries;
      entryIndex = *symbolList;
      goto LAB_00054e60;
    }
LAB_00054f2c:
    entryIndex = 0;
  }
  else {
LAB_00054e60:
    _memcpy(symbolList[1] + entryIndex * 0x54,symbol,0x54);
    symbolId = *(uint *)(symbol + 0x20);
    *(undefined1 *)(entryIndex * 0x54 + symbolList[1] + 0x3c) = 0;
    if (symbolList[3] <= symbolId) {
      newIdIndex = (**(code **)(ctx + 0x10))(symbolId + 0x40,4);
      if (newIdIndex == 0) goto LAB_00054f2c;
      if (symbolList[2] != 0) {
        (**(code **)(((unsigned char *)0x00001344) + ctx))(newIdIndex,symbolList[2],symbolList[3] << 2);
        (**(code **)(ctx + 0x18))(symbolList[2]);
      }
      symbolList[2] = newIdIndex;
      symbolList[3] = *(int *)(symbol + 0x20) + 0x40;
      symbolId = *(uint *)(symbol + 0x20);
    }
    *(uint *)(symbolId * 4 + symbolList[2]) = entryIndex;
    *symbolList = *symbolList + 1;
  }
  return entryIndex;
}

/* FUN_00054f50 @ 0x54f50 (380 bytes) */
int FUN_00054f50(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  uint param_3;
  undefined4 *param_4;
  undefined4 *param_5;
{
  uint loopIndex;
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  if (param_3 == 0) {
    param_5[1] = 0;
    *param_5 = 0;
    goto LAB_000550a0;
  }
  iVar10 = *(int *)(((unsigned char *)0x0000116c) + param_1);
  uVar1 = param_3 & 0x7fffffff;
  *(byte *)(param_5 + 6) = (byte)(param_3 >> 0x1f);
  iVar4 = ((int (*)())extvsSymbolListGetIndex)(iVar10 + 0x14,uVar1);
  if (iVar4 == 0) {
    iVar5 = ((int (*)())extvsSymbolListGetIndex)(param_2 + 0x1c,uVar1);
    if (iVar5 == 0) {
      return 0;
    }
  }
  else {
    iVar8 = param_2 + 0x1c;
    iVar5 = ((int (*)())extvsSymbolListGetIndex)(iVar8,uVar1);
    if (iVar5 == 0) {
      iVar11 = *(int *)(iVar10 + 0x18);
      iVar9 = iVar4 * 0x54;
      iVar5 = iVar11 + iVar9;
      if (*(int *)(iVar5 + 0x30) == 0) {
        uVar2 = *(uint *)(iVar5 + 0x34);
        if (uVar2 < 2) {
          iVar5 = ((int (*)())extvsAppendSymbol)(param_1,iVar8,iVar5);
          goto LAB_00055088;
        }
      }
      else {
        iVar4 = ((int (*)())extvsSymbolListGetIndex)(iVar10 + 0x14,*(int *)(iVar5 + 0x30));
        iVar9 = iVar4 * 0x54;
        uVar2 = *(uint *)(iVar11 + iVar9 + 0x34);
      }
      if (uVar2 != 0) {
        iVar4 = iVar4 * 0x54;
        loopIndex = 0;
        do {
          iVar11 = iVar4 + iVar11;
          loopIndex = loopIndex + 1;
          iVar4 = iVar4 + 0x54;
          ((int (*)())extvsAppendSymbol)(param_1,iVar8,iVar11);
          iVar11 = *(int *)(iVar10 + 0x18);
        } while (loopIndex < *(uint *)(iVar9 + iVar11 + 0x34));
      }
      iVar5 = ((int (*)())extvsSymbolListGetIndex)(iVar8,uVar1);
    }
  }
LAB_00055088:
  param_5[1] = iVar5;
  *param_5 = 2;
LAB_000550a0:
  uVar6 = param_4[1];
  uVar7 = param_4[2];
  uVar3 = param_4[3];
  param_5[2] = *param_4;
  param_5[3] = uVar6;
  param_5[4] = uVar7;
  param_5[5] = uVar3;
  return 1;
}

/* extvsOperandDataType @ 0x550e0 (244 bytes) */
int extvsOperandDataType(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (*param_2 == 1) {
    uVar1 = param_2[1];
    if (uVar1 < 0x6111) {
      if (0x610e < uVar1) {
        return 0x87bf;
      }
      if (uVar1 == 0x610e) {
        return 0x87be;
      }
    }
    else if (0x8799 < uVar1) {
      if (uVar1 < 0x87a5) {
        return 0x87bf;
      }
      if (uVar1 == 0x87bd) {
        return 0x87be;
      }
    }
  }
  else if (*param_2 == 2) {
    iVar3 = param_2[1] * 0x54 + *(int *)(param_1 + 4);
    uVar1 = *(uint *)(iVar3 + 0x28);
    if ((0x87c0 < uVar1) && ((uVar1 < 0x87c5 || (uVar1 == 0xffffffff)))) {
      iVar2 = *(int *)(iVar3 + 0x24);
      if (iVar2 != 0x87bf) {
        if (iVar2 == 0x87c0) {
          return 0x87c0;
        }
        if (iVar2 != 0x87be) {
          return 0;
        }
        if (*(char *)(iVar3 + 0x44) == '\0') {
          return 0x87be;
        }
        if (*(int *)(iVar3 + 0x48) != 0xf) {
          return 0x87be;
        }
      }
      return 0x87bf;
    }
  }
  return 0;
}

/* extvsFreeSymbolData @ 0x551f0 (244 bytes) */
int extvsFreeSymbolData(param_1, param_2)
  int param_1;
  uint *param_2;
{
  int iVar1;
  int a0;
  uint uVar2;
  uint uVar3;
  uint loopIndex;
  
  uVar2 = param_2[1];
  if (uVar2 != 0) {
    uVar3 = *param_2;
    loopIndex = 0;
    if (uVar3 != 0) {
      do {
        iVar1 = loopIndex * 0x54 + uVar2;
        a0 = *(int *)(iVar1 + 0x38);
        if ((a0 != 0) && (*(char *)(iVar1 + 0x3c) != '\0')) {
          (**(code **)(param_1 + 0x18))(a0);
          *(undefined4 *)(loopIndex * 0x54 + param_2[1] + 0x38) = 0;
          uVar2 = param_2[1];
          uVar3 = *param_2;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < uVar3);
    }
    (**(code **)(param_1 + 0x18))(uVar2);
    *param_2 = 0;
    param_2[1] = 0;
    (**(code **)(param_1 + 0x18))(param_2[2]);
    param_2[3] = 0;
    param_2[2] = 0;
  }
  return;
}

/* extvsFreeShaderObject @ 0x55300 (184 bytes) */
int extvsFreeShaderObject(param_1, param_2)
  int param_1;
  int *param_2;
{
  (**(code **)(((unsigned char *)0x000011ac) + param_1))(param_1,param_2,1);
  if (*param_2 != 0) {
    (**(code **)(param_1 + 0x18))(*param_2);
    *param_2 = 0;
  }
  if (param_2[1] != 0) {
    (**(code **)(param_1 + 0x18))(param_2[1]);
    param_2[1] = 0;
  }
  if (param_2[6] != 0) {
    (**(code **)(param_1 + 0x18))(param_2[6]);
    param_2[6] = 0;
    param_2[5] = 0;
  }
  return ((int (*)())extvsFreeSymbolData)(param_1,param_2 + 7);
}

/* extvsAppendInstruction @ 0x553c0 (556 bytes) */
int extvsAppendInstruction(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  undefined4 *param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar2 = *(uint *)(param_2 + 0x14);
  if ((uVar2 & 0x3f) == 0) {
    iVar3 = (**(code **)(param_1 + 0xc))(uVar2 * 0x74 + 0x1d00);
    if (iVar3 == 0) {
      return 0;
    }
    if (*(int *)(param_2 + 0x18) != 0) {
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (iVar3,*(int *)(param_2 + 0x18),*(int *)(param_2 + 0x14) * 0x74);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0x18));
    }
    *(int *)(param_2 + 0x18) = iVar3;
    uVar2 = *(uint *)(param_2 + 0x14);
  }
  iVar3 = uVar2 * 0x74 + *(int *)(param_2 + 0x18);
  if (0x20 < param_3 - 0x8782U) {
    return 0;
  }
  *(int *)(uVar2 * 0x74 + *(int *)(param_2 + 0x18)) = param_3;
  if (param_4 < 0x879d) {
    if ((param_4 < 0x879a) && (2 < param_4 - 0x610e)) {
LAB_00055500:
      iVar5 = ((int (*)())extvsSymbolListGetIndex)(param_2 + 0x1c,param_4);
      if (iVar5 == 0) {
        return 0;
      }
      iVar4 = *(int *)(iVar5 * 0x54 + *(int *)(param_2 + 0x20) + 0x28);
      if ((iVar4 != 0x87c4) && (iVar4 != -1)) {
        return 0;
      }
      *(int *)(iVar3 + 8) = iVar5;
      *(undefined4 *)(iVar3 + 4) = 2;
      goto LAB_00055550;
    }
  }
  else if (param_4 < 0x87a5) {
    if ((int)(uint)(byte)((unsigned char *)0x000013b0)[param_1] <= (int)(param_4 - 0x879d)) {
      return 0;
    }
  }
  else if (param_4 != 0x87bd) goto LAB_00055500;
  *(uint *)(iVar3 + 8) = param_4;
  *(undefined4 *)(iVar3 + 4) = 1;
LAB_00055550:
  uVar1 = *param_5;
  uVar6 = param_5[1];
  uVar7 = param_5[2];
  *(undefined4 *)(iVar3 + 0x18) = param_5[3];
  *(undefined4 *)(iVar3 + 0xc) = uVar1;
  *(undefined4 *)(iVar3 + 0x10) = uVar6;
  *(undefined4 *)(iVar3 + 0x14) = uVar7;
  iVar5 = ((int (*)())FUN_00054f50)(param_1,param_2,param_6,param_7,iVar3 + 0x20);
  if (((iVar5 != 0) &&
      (iVar5 = ((int (*)())FUN_00054f50)(param_1,param_2,param_8,param_9,iVar3 + 0x3c), iVar5 != 0)) &&
     (iVar3 = ((int (*)())FUN_00054f50)(param_1,param_2,param_10,param_11,iVar3 + 0x58), iVar3 != 0)) {
    *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + 1;
    return 1;
  }
  return 0;
}

/* extvsCreateSymbol @ 0x55610 (1008 bytes) */
int extvsCreateSymbol(ctx, symbolList, dataType, storageClass, entryWord2c, baseId, elementCount, constantIndex)
  int ctx;
  uint *symbolList;
  int dataType;
  int storageClass;
  undefined4 entryWord2c;
  int baseId;
  uint elementCount;
  int constantIndex;
{
  uint symbolId;
  int iVar1;
  uint entriesBase;
  undefined4 uVar3;
  uint entryIndex;
  int symbolIdState;
  int entryOffset;
  
  symbolIdState = *(int *)(((unsigned char *)0x0000116c) + ctx);
  if (*(int *)(symbolIdState + 0x24) < 0) {
LAB_00055a00:
    uVar3 = 0;
  }
  else {
    entryIndex = *symbolList;
    if ((entryIndex & 0x3f) == 0) {
      entryIndex = (**(code **)(ctx + 0xc))(((unsigned char *)0x00001500) + entryIndex * 0x54);
      if (entryIndex == 0) goto LAB_00055a00;
      if (symbolList[1] != 0) {
        (**(code **)(((unsigned char *)0x00001344) + ctx))(entryIndex,symbolList[1],*symbolList * 0x54);
        (**(code **)(ctx + 0x18))(symbolList[1]);
      }
      symbolList[1] = entryIndex;
      entryIndex = *symbolList;
    }
    if (storageClass == -4) {
      *(undefined4 *)(symbolList[1] + entryIndex * 0x54 + 0x28) = 0x87c1;
      *(undefined1 *)(entryIndex * 0x54 + symbolList[1] + 0x3c) = 0;
    }
    else if (storageClass == -3) {
      entryOffset = entryIndex * 0x54;
      *(undefined4 *)(symbolList[1] + entryOffset + 0x28) = 0x87c2;
      *(int *)(entryOffset + symbolList[1] + 0x38) =
           constantIndex * 0x10 + *(int *)(((unsigned char *)0x00004308) + *(int *)(*(int *)(ctx + 4) + 0x10));
      *(undefined1 *)(entryOffset + symbolList[1] + 0x3c) = 0;
    }
    else if (storageClass == -2) {
      entryOffset = entryIndex * 0x54;
      *(undefined4 *)(symbolList[1] + entryOffset + 0x28) = 0x87c2;
      *(int *)(entryOffset + symbolList[1] + 0x38) =
           constantIndex * 0x10 +
           *(int *)(**(int **)(*(int *)(*(int *)(ctx + 4) + 0x18) + 0x18c) + 0x18);
      *(undefined1 *)(entryOffset + symbolList[1] + 0x3c) = 0;
    }
    else {
      entryOffset = entryIndex * 0x54;
      *(int *)(symbolList[1] + entryOffset + 0x28) = storageClass;
      if (dataType == 0x87bf) {
        uVar3 = 0x10;
      }
      else if (dataType == 0x87c0) {
        uVar3 = 0x40;
      }
      else {
        if (dataType != 0x87be) {
          *(undefined4 *)(entryOffset + symbolList[1] + 0x38) = 0;
          *(undefined1 *)(entryOffset + symbolList[1] + 0x3c) = 0;
          goto LAB_00055870;
        }
        uVar3 = 4;
      }
      entriesBase = symbolList[1];
      uVar3 = (**(code **)(ctx + 0xc))(uVar3);
      *(undefined4 *)(entryOffset + entriesBase + 0x38) = uVar3;
      *(undefined1 *)(entryOffset + symbolList[1] + 0x3c) = 1;
    }
LAB_00055870:
    entryOffset = entryIndex * 0x54;
    *(undefined4 *)(symbolList[1] + entryOffset + 0x20) = *(undefined4 *)(symbolIdState + 0x24);
    *(int *)(symbolList[1] + entryOffset + 0x24) = dataType;
    *(undefined4 *)(symbolList[1] + entryOffset + 0x2c) = entryWord2c;
    if ((baseId != 0) || (1 < elementCount)) {
      iVar1 = entryOffset + symbolList[1];
      if (baseId == 0) {
        baseId = *(int *)(iVar1 + 0x20);
      }
    }
    else {
      iVar1 = symbolList[1] + entryOffset;
    }
    *(int *)(iVar1 + 0x30) = baseId;
    *(uint *)(symbolList[1] + entryOffset + 0x34) = elementCount;
    *(undefined1 *)(symbolList[1] + entryOffset + 0x3d) = 0;
    *(undefined4 *)(symbolList[1] + entryOffset + 0x40) = 0xffffffff;
    *(undefined1 *)(symbolList[1] + entryOffset + 0x44) = 0;
    symbolId = *(uint *)(symbolIdState + 0x24);
    if (symbolList[3] <= symbolId) {
      symbolId = (**(code **)(ctx + 0x10))(symbolId + 0x40,4);
      if (symbolId == 0) goto LAB_00055a00;
      if (symbolList[2] != 0) {
        (**(code **)(((unsigned char *)0x00001344) + ctx))(symbolId,symbolList[2],symbolList[3] << 2);
        (**(code **)(ctx + 0x18))(symbolList[2]);
      }
      symbolList[2] = symbolId;
      symbolList[3] = *(int *)(symbolIdState + 0x24) + 0x40;
      symbolId = *(uint *)(symbolIdState + 0x24);
    }
    *(uint *)(symbolId * 4 + symbolList[2]) = entryIndex;
    *symbolList = *symbolList + 1;
    iVar1 = *(int *)(symbolIdState + 0x24) + 1;
    *(int *)(symbolIdState + 0x24) = iVar1;
    if (iVar1 == 0x610e) {
      *(undefined4 *)(symbolIdState + 0x24) = 0x6111;
    }
    else if (iVar1 == 0x879a) {
      *(undefined4 *)(symbolIdState + 0x24) = 0x87be;
    }
    uVar3 = *(undefined4 *)(symbolList[1] + entryOffset + 0x20);
  }
  return uVar3;
}

/* extvsSymbolListGetSymbol @ 0x55a30 (48 bytes) */
int extvsSymbolListGetSymbol(symbolList, position)
  int symbolList;
  uint position;
{
  int iVar1;
  
  iVar1 = 0;
  if (position < *(uint *)(symbolList + 0xc)) {
    iVar1 = *(int *)(position * 4 + *(int *)(symbolList + 8)) * 0x54 + *(int *)(symbolList + 4);
  }
  return iVar1;
}

/* extvsInitSymbolListWithMVP @ 0x55a60 (220 bytes) */
int extvsInitSymbolListWithMVP(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  iVar2 = *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x24);
  if (iVar2 == 0) {
    uVar1 = ((int (*)())extvsCreateSymbol)(param_1,param_2,0x87c0,0x87c2,0x87e1,0,0,0);
    iVar2 = ((int (*)())extvsSymbolListGetSymbol)(param_2,uVar1);
    *(undefined4 *)(iVar2 + 0x4c) = 0;
    *(undefined1 *)(iVar2 + 0x44) = 1;
    *(undefined4 *)(iVar2 + 0x48) = 0x87e3;
    *(undefined4 *)(iVar2 + 0x50) = 0x80;
  }
  else {
    *(undefined4 *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x24) = 0;
    ((int (*)())extvsCreateSymbol)(param_1,param_2,0x87be,0x87c1,0x87e1,0,0,0);
    *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x24) = iVar2;
  }
  return;
}

/* extvsInitShaderObject @ 0x55b50 (428 bytes) */
int extvsInitShaderObject(ctx, shader)
  int ctx;
  undefined4 *shader;
{
  int loopIndex;
  undefined4 *byteCursor;
  undefined4 allocatedArray;
  int remaining;
  
  allocatedArray = (**(code **)(ctx + 0x10))(*(undefined4 *)(*(int *)(((unsigned char *)0x0000116c) + ctx) + 0x10),4)
  ;
  *shader = allocatedArray;
  (**(code **)(((unsigned char *)0x000011a4) + ctx))(ctx,shader,0xffffffff);
  allocatedArray = (**(code **)(ctx + 0x10))(*(undefined4 *)(*(int *)(((unsigned char *)0x0000116c) + ctx) + 0x10),1)
  ;
  shader[1] = allocatedArray;
  if (0 < *(int *)(*(int *)(((unsigned char *)0x0000116c) + ctx) + 0x10)) {
    loopIndex = 0;
    do {
      *(undefined1 *)(shader[1] + loopIndex) = 0;
      loopIndex = loopIndex + 1;
    } while (loopIndex < *(int *)(*(int *)(((unsigned char *)0x0000116c) + ctx) + 0x10));
  }
  *(undefined1 *)(shader + 4) = 0;
  shader[5] = 0;
  shader[6] = 0;
  ((int (*)())extvsInitSymbolListWithMVP)(ctx,shader + 7);
  shader[0xc] = 0;
  shader[0xb] = 0;
  if (((unsigned char *)0x000013b0)[ctx] != '\0') {
    loopIndex = 0;
    byteCursor = shader;
    do {
      *(undefined1 *)(byteCursor + 0xd) = 0;
      *(undefined1 *)(byteCursor + 0x11) = 1;
      loopIndex = loopIndex + 1;
      byteCursor = (undefined4 *)((int)byteCursor + 1);
    } while (loopIndex < (int)(uint)(byte)((unsigned char *)0x000013b0)[ctx]);
  }
  remaining = 4;
  *(undefined1 *)(shader + 0x1b) = 0;
  shader[0x15] = 0;
  shader[0x16] = 0;
  shader[0x17] = 0;
  shader[0x18] = 0;
  shader[0x19] = 0;
  shader[0x1a] = 0;
  byteCursor = shader;
  do {
    *(undefined1 *)((int)byteCursor + 0x6d) = 0;
    byteCursor = (undefined4 *)((int)byteCursor + 1);
    remaining = remaining + -1;
  } while (remaining != 0);
  remaining = 8;
  byteCursor = shader;
  do {
    *(undefined1 *)((int)byteCursor + 0x71) = 0;
    byteCursor = (undefined4 *)((int)byteCursor + 1);
    remaining = remaining + -1;
  } while (remaining != 0);
  *(undefined1 *)((int)shader + 0x7b) = 0;
  *(undefined1 *)((int)shader + 0x79) = 0;
  *(undefined1 *)((int)shader + 0x7a) = 0;
  return;
}

/* extvsRefreshBoundVertexPrograms @ 0x55d00 (148 bytes) */
int extvsRefreshBoundVertexPrograms(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint loopIndex;
  undefined4 *puVar6;
  int iVar7;
  
  iVar4 = *(int *)(((unsigned char *)0x0000112c) + param_1);
  uVar3 = *(uint *)(iVar4 + 4);
  if (uVar3 != 0) {
    loopIndex = 0;
    iVar7 = 0;
    do {
      iVar2 = iVar7 + *(int *)(iVar4 + 8);
      if (*(int *)(iVar2 + 4) == 0x8620) {
        puVar6 = *(undefined4 **)(iVar2 + 0x14);
        uVar1 = extvsGetShaderById(param_1,*puVar6);
        puVar6[0x2a] = uVar1;
        uVar3 = *(uint *)(iVar4 + 4);
      }
      loopIndex = loopIndex + 1;
      iVar7 = iVar7 + 0x18;
    } while (loopIndex < uVar3);
  }
  return;
}

/* extvsAllocConstantRegisters @ 0x55da0 (1756 bytes) */
int extvsAllocConstantRegisters(ctx, shader, programState, symbol)
  int ctx;
  int shader;
  int programState;
  int symbol;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  uint slotIndex;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  
  if (*(int *)(symbol + 0x28) == 0x87c2) {
    *(int *)(shader + 0x5c) = *(int *)(shader + 0x5c) + 1;
    if (*(char *)(symbol + 0x44) == '\0') {
      *(int *)(programState + 0x224) = *(int *)(programState + 0x224) + 1;
    }
    else {
      *(int *)(programState + 0x22c) = *(int *)(programState + 0x22c) + 1;
    }
    iVar4 = *(int *)(symbol + 0x24);
    *(undefined1 *)(symbol + 0x3d) = 1;
    if (iVar4 == 0x87bf) {
      uVar6 = 0;
      slotIndex = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
      while (slotIndex < *(uint *)(programState + 0x58)) {
        if (!bVar1) goto LAB_00055f2c;
        if (*(char *)(iVar4 + *(int *)(programState + 0x54) + 0x10) == '\0') {
          uVar6 = 1;
          bVar1 = false;
        }
        else {
          slotIndex = slotIndex + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
      goto LAB_00055f28;
    }
    if (iVar4 == 0x87c0) {
      slotIndex = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 4;
      while (slotIndex < *(int *)(programState + 0x58) - 3U) {
        if (!bVar1) goto LAB_00055fac;
        if (*(char *)(iVar4 + *(int *)(programState + 0x54) + 0x10) == '\0') {
          bVar1 = false;
        }
        else {
          slotIndex = slotIndex + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
      if (!bVar1) {
LAB_00055fac:
        iVar8 = slotIndex * 0x28;
        iVar4 = iVar8 + *(int *)(programState + 0x54);
        if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
           (*(char *)(iVar4 + 0x88) == '\0')) {
          iVar4 = 0;
          iVar10 = 4;
          do {
            iVar2 = slotIndex + iVar4;
            iVar4 = iVar4 + 1;
            *(int *)(symbol + 0x10) = iVar2;
            symbol = symbol + 4;
            iVar2 = *(int *)(programState + 0x54) + iVar8;
            iVar8 = iVar8 + 0x28;
            *(undefined1 *)(iVar2 + 0x10) = 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
          return;
        }
      }
      *(undefined1 *)(shader + 0x10) = 0;
      iVar10 = *(int *)(programState + 0x58);
      uVar9 = (**(code **)(ctx + 0x10))(iVar10 + 0x10,0x28);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (uVar9,*(undefined4 *)(programState + 0x54),*(int *)(programState + 0x58) * 0x28);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
      *(undefined4 *)(programState + 0x54) = uVar9;
      iVar4 = iVar10 * 0x28;
      iVar2 = 4;
      iVar8 = 0;
      *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
      do {
        iVar3 = iVar10 + iVar8;
        iVar8 = iVar8 + 1;
        *(int *)(symbol + 0x10) = iVar3;
        symbol = symbol + 4;
        iVar3 = *(int *)(programState + 0x54) + iVar4;
        iVar4 = iVar4 + 0x28;
        *(undefined1 *)(iVar3 + 0x10) = 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      return;
    }
    if (iVar4 != 0x87be) {
      return;
    }
    uVar9 = 0;
    slotIndex = 0;
    iVar4 = 0;
    bVar1 = true;
    *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
    while (slotIndex < *(uint *)(programState + 0x58)) {
      if (!bVar1) goto LAB_0005618c;
      if (*(char *)(iVar4 + *(int *)(programState + 0x54) + 0x10) == '\0') {
        uVar9 = 1;
        bVar1 = false;
      }
      else {
        slotIndex = slotIndex + 1;
        iVar4 = iVar4 + 0x28;
      }
    }
  }
  else {
    if (*(int *)(symbol + 0x28) != 0x87c3) {
      return;
    }
    *(int *)(shader + 0x60) = *(int *)(shader + 0x60) + 1;
    *(undefined1 *)(symbol + 0x3d) = 1;
    iVar4 = *(int *)(symbol + 0x24);
    if (iVar4 == 0x87bf) {
      uVar6 = 0;
      slotIndex = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
      while (slotIndex < *(uint *)(programState + 0x58)) {
        if (!bVar1) goto LAB_00055f2c;
        if (*(char *)(iVar4 + *(int *)(programState + 0x54) + 0x10) == '\0') {
          uVar6 = 1;
          bVar1 = false;
        }
        else {
          slotIndex = slotIndex + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
LAB_00055f28:
      if (bVar1) {
        *(undefined1 *)(shader + 0x10) = uVar6;
        iVar4 = *(int *)(programState + 0x58);
        uVar9 = (**(code **)(ctx + 0x10))(iVar4 + 0x10,0x28);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar9,*(undefined4 *)(programState + 0x54),*(int *)(programState + 0x58) * 0x28);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
        *(undefined4 *)(programState + 0x54) = uVar9;
        *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
        goto LAB_000562e8;
      }
LAB_00055f2c:
      *(uint *)(symbol + 4) = slotIndex;
      goto LAB_00055f30;
    }
    if (iVar4 == 0x87c0) {
      slotIndex = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 4;
      while (slotIndex < *(int *)(programState + 0x58) - 3U) {
        if (!bVar1) goto LAB_0005636c;
        if (*(char *)(iVar4 + *(int *)(programState + 0x54) + 0x10) == '\0') {
          bVar1 = false;
        }
        else {
          slotIndex = slotIndex + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
      if (!bVar1) {
LAB_0005636c:
        iVar8 = slotIndex * 0x28;
        iVar4 = iVar8 + *(int *)(programState + 0x54);
        if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
           (*(char *)(iVar4 + 0x88) == '\0')) {
          iVar4 = 0;
          iVar10 = 4;
          do {
            iVar2 = slotIndex + iVar4;
            iVar4 = iVar4 + 1;
            *(int *)(symbol + 0x10) = iVar2;
            symbol = symbol + 4;
            iVar2 = *(int *)(programState + 0x54) + iVar8;
            iVar8 = iVar8 + 0x28;
            *(undefined1 *)(iVar2 + 0x10) = 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
          return;
        }
      }
      *(undefined1 *)(shader + 0x10) = 0;
      iVar10 = *(int *)(programState + 0x58);
      uVar9 = (**(code **)(ctx + 0x10))(iVar10 + 0x10,0x28);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (uVar9,*(undefined4 *)(programState + 0x54),*(int *)(programState + 0x58) * 0x28);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
      *(undefined4 *)(programState + 0x54) = uVar9;
      iVar4 = iVar10 * 0x28;
      iVar2 = 4;
      iVar8 = 0;
      *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
      do {
        iVar3 = iVar10 + iVar8;
        iVar8 = iVar8 + 1;
        *(int *)(symbol + 0x10) = iVar3;
        symbol = symbol + 4;
        iVar3 = *(int *)(programState + 0x54) + iVar4;
        iVar4 = iVar4 + 0x28;
        *(undefined1 *)(iVar3 + 0x10) = 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      return;
    }
    if (iVar4 != 0x87be) {
      return;
    }
    uVar9 = 0;
    slotIndex = 0;
    iVar4 = 0;
    bVar1 = true;
    *(int *)(programState + 0x5c) = *(int *)(programState + 0x5c) + 1;
    while (slotIndex < *(uint *)(programState + 0x58)) {
      if (!bVar1) goto LAB_0005618c;
      if (*(char *)(iVar4 + *(int *)(programState + 0x54) + 0x10) == '\0') {
        uVar9 = 1;
        bVar1 = false;
      }
      else {
        slotIndex = slotIndex + 1;
        iVar4 = iVar4 + 0x28;
      }
    }
  }
  if (bVar1) {
    *(char *)(shader + 0x10) = (char)uVar9;
    iVar4 = *(int *)(programState + 0x58);
    uVar5 = (**(code **)(ctx + 0x10))(iVar4 + 0x10,0x28);
    (**(code **)(((unsigned char *)0x00001344) + ctx))
              (uVar5,*(undefined4 *)(programState + 0x54),*(int *)(programState + 0x58) * 0x28);
    (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x54));
    *(undefined4 *)(programState + 0x54) = uVar5;
    *(int *)(programState + 0x58) = *(int *)(programState + 0x58) + 0x10;
    *(undefined4 *)(symbol + 8) = uVar9;
LAB_000562e8:
    *(int *)(symbol + 4) = iVar4;
    *(undefined1 *)(iVar4 * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
    return;
  }
LAB_0005618c:
  *(uint *)(symbol + 4) = slotIndex;
  *(undefined4 *)(symbol + 8) = 0;
LAB_00055f30:
  *(undefined1 *)(slotIndex * 0x28 + *(int *)(programState + 0x54) + 0x10) = 1;
  return;
}

/* extvsAllocTempRegisters @ 0x564c0 (1668 bytes) */
int extvsAllocTempRegisters(ctx, shader, programState, operand)
  int ctx;
  int shader;
  int programState;
  int *operand;
{
  uint slotIndex;
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 uVar6;
  int dataType;
  int iVar8;
  uint uVar9;
  int symbolIndex;
  int symbol;
  int iVar12;
  
  if (*operand != 2) {
    return;
  }
  symbolIndex = operand[1];
  symbol = symbolIndex * 0x54 + *(int *)(shader + 0x20);
  if (*(int *)(symbol + 0x28) != 0x87c4) {
    return;
  }
  bVar1 = *(char *)(symbol + 0x3d) == '\0';
  if (!bVar1) {
    return;
  }
  *(undefined1 *)(symbol + 0x3d) = 1;
  *(int *)(shader + 100) = *(int *)(shader + 100) + 1;
  dataType = *(int *)(symbolIndex * 0x54 + *(int *)(shader + 0x20) + 0x24);
  if (dataType == 0x87bf) {
    slotIndex = 0;
    uVar6 = 0;
    while (slotIndex < *(uint *)(programState + 0x50)) {
      if (!bVar1) goto LAB_000567d8;
      if (*(char *)(slotIndex * 0x28 + *(int *)(programState + 0x4c) + 0x10) == '\0') {
        uVar6 = 1;
        bVar1 = false;
      }
      else {
        slotIndex = slotIndex + 1;
      }
    }
    if (bVar1) {
      *(undefined1 *)(shader + 0x10) = uVar6;
      uVar9 = *(uint *)(programState + 0x50);
      uVar4 = (**(code **)(ctx + 0x10))(uVar9 + 0x10,0x28);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (uVar4,*(undefined4 *)(programState + 0x4c),*(int *)(programState + 0x50) * 0x28);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x4c));
      *(undefined4 *)(programState + 0x4c) = uVar4;
      dataType = uVar9 * 0x28;
      *(int *)(programState + 0x50) = *(int *)(programState + 0x50) + 0x10;
      *(uint *)(symbol + 4) = uVar9;
      *(undefined1 *)(*(int *)(programState + 0x4c) + dataType + 0x10) = 1;
      *(undefined4 *)(dataType + *(int *)(programState + 0x4c) + 0x14) = 4;
      *(int *)(dataType + *(int *)(programState + 0x4c) + 0x18) = symbolIndex;
      *(int *)(dataType + *(int *)(programState + 0x4c) + 0x1c) = symbolIndex;
      *(int *)(dataType + *(int *)(programState + 0x4c) + 0x20) = symbolIndex;
      *(int *)(dataType + *(int *)(programState + 0x4c) + 0x24) = symbolIndex;
      if (uVar9 < *(uint *)(programState + 0x2ac)) {
        return;
      }
LAB_00056918:
      *(uint *)(programState + 0x2ac) = uVar9 + 1;
      return;
    }
LAB_000567d8:
    *(uint *)(symbol + 4) = slotIndex;
    symbol = slotIndex * 0x28;
    *(undefined1 *)(*(int *)(programState + 0x4c) + symbol + 0x10) = 1;
    *(undefined4 *)(symbol + *(int *)(programState + 0x4c) + 0x14) = 4;
    *(int *)(symbol + *(int *)(programState + 0x4c) + 0x18) = symbolIndex;
    *(int *)(symbol + *(int *)(programState + 0x4c) + 0x1c) = symbolIndex;
    *(int *)(symbol + *(int *)(programState + 0x4c) + 0x20) = symbolIndex;
    *(int *)(symbol + *(int *)(programState + 0x4c) + 0x24) = symbolIndex;
    if (slotIndex < *(uint *)(programState + 0x2ac)) {
      return;
    }
  }
  else {
    if (dataType == 0x87c0) {
      slotIndex = 0;
      while (slotIndex < *(int *)(programState + 0x50) - 3U) {
        if (!bVar1) goto LAB_00056978;
        if (*(char *)(slotIndex * 0x28 + *(int *)(programState + 0x4c) + 0x10) == '\0') {
          bVar1 = false;
        }
        else {
          slotIndex = slotIndex + 1;
        }
      }
      if (!bVar1) {
LAB_00056978:
        dataType = slotIndex * 0x28;
        iVar8 = dataType + *(int *)(programState + 0x4c);
        if (((*(char *)(iVar8 + 0x38) == '\0') && (*(char *)(iVar8 + 0x60) == '\0')) &&
           (*(char *)(iVar8 + 0x88) == '\0')) {
          iVar8 = 0;
          iVar12 = 4;
          do {
            iVar2 = slotIndex + iVar8;
            iVar8 = iVar8 + 1;
            *(int *)(symbol + 0x10) = iVar2;
            symbol = symbol + 4;
            *(undefined1 *)(dataType + *(int *)(programState + 0x4c) + 0x10) = 1;
            *(undefined4 *)(dataType + *(int *)(programState + 0x4c) + 0x14) = 4;
            *(int *)(dataType + *(int *)(programState + 0x4c) + 0x18) = symbolIndex;
            *(int *)(dataType + *(int *)(programState + 0x4c) + 0x1c) = symbolIndex;
            *(int *)(dataType + *(int *)(programState + 0x4c) + 0x20) = symbolIndex;
            iVar2 = dataType + *(int *)(programState + 0x4c);
            dataType = dataType + 0x28;
            *(int *)(iVar2 + 0x24) = symbolIndex;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
          if (slotIndex + 3 < *(uint *)(programState + 0x2ac)) {
            return;
          }
          *(uint *)(programState + 0x2ac) = slotIndex + 4;
          return;
        }
      }
      *(undefined1 *)(shader + 0x10) = 0;
      iVar12 = *(int *)(programState + 0x50);
      uVar4 = (**(code **)(ctx + 0x10))(iVar12 + 0x10,0x28);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (uVar4,*(undefined4 *)(programState + 0x4c),*(int *)(programState + 0x50) * 0x28);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x4c));
      *(undefined4 *)(programState + 0x4c) = uVar4;
      iVar8 = iVar12 * 0x28;
      iVar2 = 4;
      dataType = 0;
      *(int *)(programState + 0x50) = *(int *)(programState + 0x50) + 0x10;
      do {
        iVar3 = iVar12 + dataType;
        dataType = dataType + 1;
        *(int *)(symbol + 0x10) = iVar3;
        symbol = symbol + 4;
        *(undefined1 *)(*(int *)(programState + 0x4c) + iVar8 + 0x10) = 1;
        *(undefined4 *)(*(int *)(programState + 0x4c) + iVar8 + 0x14) = 4;
        *(int *)(*(int *)(programState + 0x4c) + iVar8 + 0x18) = symbolIndex;
        *(int *)(*(int *)(programState + 0x4c) + iVar8 + 0x1c) = symbolIndex;
        *(int *)(*(int *)(programState + 0x4c) + iVar8 + 0x20) = symbolIndex;
        iVar3 = *(int *)(programState + 0x4c) + iVar8;
        iVar8 = iVar8 + 0x28;
        *(int *)(iVar3 + 0x24) = symbolIndex;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      if (iVar12 + 3U < *(uint *)(programState + 0x2ac)) {
        return;
      }
      *(int *)(programState + 0x2ac) = iVar12 + 4;
      return;
    }
    if (dataType != 0x87be) {
      return;
    }
    uVar5 = *(uint *)(programState + 0x50);
    slotIndex = 0;
    bVar1 = false;
    dataType = 0;
    while (slotIndex < uVar5) {
      if (bVar1) goto LAB_000565ec;
      iVar8 = dataType + *(int *)(programState + 0x4c);
      if ((*(char *)(iVar8 + 0x10) == '\0') || (bVar1 = true, 3 < *(uint *)(iVar8 + 0x14))) {
        slotIndex = slotIndex + 1;
        dataType = dataType + 0x28;
        bVar1 = false;
      }
    }
    if (bVar1) {
LAB_000565ec:
      *(uint *)(symbol + 4) = slotIndex;
      dataType = slotIndex * 0x28;
      *(undefined4 *)(symbol + 8) = *(undefined4 *)(*(int *)(programState + 0x4c) + dataType + 0x14);
      symbol = dataType + *(int *)(programState + 0x4c);
      *(int *)(*(int *)(symbol + 0x14) * 4 + symbol + 0x18) = symbolIndex;
      dataType = dataType + *(int *)(programState + 0x4c);
      *(int *)(dataType + 0x14) = *(int *)(dataType + 0x14) + 1;
      if (slotIndex < *(uint *)(programState + 0x2ac)) {
        return;
      }
    }
    else {
      if (uVar5 == 0) {
LAB_000566c8:
        *(undefined1 *)(shader + 0x10) = 0;
        uVar9 = *(uint *)(programState + 0x50);
        uVar4 = (**(code **)(ctx + 0x10))(uVar9 + 0x10,0x28);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar4,*(undefined4 *)(programState + 0x4c),*(int *)(programState + 0x50) * 0x28);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x4c));
        *(undefined4 *)(programState + 0x4c) = uVar4;
        dataType = uVar9 * 0x28;
        *(int *)(programState + 0x50) = *(int *)(programState + 0x50) + 0x10;
        *(undefined4 *)(symbol + 8) = 0;
        *(uint *)(symbol + 4) = uVar9;
        *(undefined1 *)(*(int *)(programState + 0x4c) + dataType + 0x10) = 1;
        *(undefined4 *)(dataType + *(int *)(programState + 0x4c) + 0x14) = 1;
        *(int *)(dataType + *(int *)(programState + 0x4c) + 0x18) = symbolIndex;
        if (uVar9 < *(uint *)(programState + 0x2ac)) {
          return;
        }
        goto LAB_00056918;
      }
      slotIndex = 0;
      do {
        bVar1 = *(char *)(slotIndex * 0x28 + *(int *)(programState + 0x4c) + 0x10) != '\0';
        if (bVar1) {
          slotIndex = slotIndex + 1;
        }
        if (uVar5 <= slotIndex) {
          if (bVar1) goto LAB_000566c8;
          break;
        }
      } while (bVar1);
      *(uint *)(symbol + 4) = slotIndex;
      dataType = slotIndex * 0x28;
      *(undefined4 *)(symbol + 8) = 0;
      *(undefined1 *)(*(int *)(programState + 0x4c) + dataType + 0x10) = 1;
      *(undefined4 *)(dataType + *(int *)(programState + 0x4c) + 0x14) = 1;
      *(int *)(dataType + *(int *)(programState + 0x4c) + 0x18) = symbolIndex;
      if (slotIndex < *(uint *)(programState + 0x2ac)) {
        return;
      }
    }
  }
  *(uint *)(programState + 0x2ac) = slotIndex + 1;
  return;
}

/* extvsOperandUsesTempSlot @ 0x56b80 (80 bytes) */
int extvsOperandUsesTempSlot(operand, slot)
  int *operand;
  int slot;
{
  int operandIndex;
  
  if ((*operand == 2) &&
     ((((operandIndex = operand[1], operandIndex == *(int *)(slot + 0x18) ||
        (operandIndex == *(int *)(slot + 0x1c))) || (operandIndex == *(int *)(slot + 0x20))) ||
      (operandIndex == *(int *)(slot + 0x24))))) {
    return 1;
  }
  return 0;
}

/* extvsFreeDeadTempSlots @ 0x56be0 (816 bytes) */
int extvsFreeDeadTempSlots(ctx, shader, instIndex)
  int ctx;
  int *shader;
  int instIndex;
{
  byte writesX;
  byte writesY;
  byte writesZ;
  byte writesW;
  bool noLaterRead;
  int iVar6;
  uint instCount;
  byte writtenX;
  byte writtenY;
  byte writtenZ;
  byte writtenW;
  uint slotIndex;
  int slotRegX;
  uint tempSlotCount;
  uint nextInstIndex;
  int slotOffset;
  int programState;
  uint scanIndex;
  int slot;
  int inst;
  bool stopScan;
  
  programState = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  tempSlotCount = *(uint *)(programState + 0x50);
  if (tempSlotCount != 0) {
    nextInstIndex = instIndex + 1;
    slotIndex = 0;
    slotOffset = 0;
    do {
      slot = slotOffset + *(int *)(programState + 0x4c);
      if (*(char *)(slot + 0x10) != '\0') {
        slotRegX = *(int *)(slot + 0x18);
        if (((((slotRegX != 0) || (*(int *)(slot + 0x1c) != 0)) || (*(int *)(slot + 0x20) != 0))
            || (*(int *)(slot + 0x24) != 0)) && (instCount = shader[5], nextInstIndex < instCount)) {
          writtenX = 0;
          writtenY = 0;
          writtenZ = 0;
          inst = nextInstIndex * 0x74 + shader[6];
          writtenW = 0;
          noLaterRead = true;
          scanIndex = nextInstIndex;
          do {
            iVar6 = ((int (*)())extvsOperandUsesTempSlot)(inst + 0x20,slot);
            if (((iVar6 == 0) && (iVar6 = ((int (*)())extvsOperandUsesTempSlot)(inst + 0x3c,slot), iVar6 == 0)) &&
               (iVar6 = ((int (*)())extvsOperandUsesTempSlot)(inst + 0x58,slot), iVar6 == 0)) {
              iVar6 = ((int (*)())extvsOperandUsesTempSlot)(inst + 4,slot);
              if (iVar6 != 0) {
                iVar6 = *(int *)(inst + 8);
                if (*(int *)(iVar6 * 0x54 + shader[8] + 0x24) == 0x87be) {
                  writesX = slotRegX == iVar6;
                  writesY = iVar6 == *(int *)(slot + 0x1c);
                  writesZ = iVar6 == *(int *)(slot + 0x20);
                  writesW = iVar6 == *(int *)(slot + 0x24);
                }
                else {
                  writesX = *(byte *)(inst + 0xf);
                  writesY = *(byte *)(inst + 0x13);
                  writesZ = *(byte *)(inst + 0x17);
                  writesW = *(byte *)(inst + 0x1b);
                }
                writtenW = writtenW | writesW;
                writtenZ = writtenZ | writesZ;
                writtenY = writtenY | writesY;
                writtenX = writtenX | writesX;
                if (((writtenX != 0) && (writtenY != 0)) && (writtenZ != 0)) {
                  stopScan = writtenW != 0;
                  goto LAB_00056e00;
                }
              }
              stopScan = false;
            }
            else {
              noLaterRead = false;
              stopScan = true;
            }
LAB_00056e00:
            scanIndex = scanIndex + 1;
          } while ((scanIndex != instCount) && (inst = inst + 0x74, !stopScan));
          if (!noLaterRead) goto LAB_00056ef0;
        }
        *(undefined1 *)(slotRegX * 0x54 + shader[8] + 0x3d) = 0;
        *(undefined1 *)
         (*(int *)(slotOffset + *(int *)(programState + 0x4c) + 0x1c) * 0x54 + shader[8] + 0x3d) = 0;
        *(undefined1 *)
         (*(int *)(slotOffset + *(int *)(programState + 0x4c) + 0x20) * 0x54 + shader[8] + 0x3d) = 0;
        *(undefined1 *)
         (*(int *)(slotOffset + *(int *)(programState + 0x4c) + 0x24) * 0x54 + shader[8] + 0x3d) = 0;
        *(undefined1 *)(slotOffset + *(int *)(programState + 0x4c) + 0x10) = 0;
        *(undefined4 *)(slotOffset + *(int *)(programState + 0x4c) + 0x14) = 0;
        *(undefined4 *)(slotOffset + *(int *)(programState + 0x4c) + 0x18) = 0;
        *(undefined4 *)(slotOffset + *(int *)(programState + 0x4c) + 0x1c) = 0;
        *(undefined4 *)(slotOffset + *(int *)(programState + 0x4c) + 0x20) = 0;
        *(undefined4 *)(slotOffset + *(int *)(programState + 0x4c) + 0x24) = 0;
        shader[0x19] = shader[0x19] + -1;
        tempSlotCount = *(uint *)(programState + 0x50);
      }
LAB_00056ef0:
      slotIndex = slotIndex + 1;
      slotOffset = slotOffset + 0x28;
    } while (slotIndex < tempSlotCount);
  }
  return;
}

/* extvsEncodeSourceOperand @ 0x56f20 (988 bytes) */
int extvsEncodeSourceOperand(ctx, shader, operand, outWord, registerSelect, selectFlag, matrixRow)
  int ctx;
  int *shader;
  uint *operand;
  uint *outWord;
  uint registerSelect;
  uint selectFlag;
  int matrixRow;
{
  int symbolEntry;
  uint encodedWord;
  uint stateIndexBits;
  uint selectFlagBit6;
  uint flagBit20;
  uint flagBit21;
  uint flagBit22;
  uint flagBit23;
  uint registerBits;
  uint oldWord;
  uint operandKind;
  int symbolDataType;
  int programState;
  
  oldWord = *outWord;
  registerBits = registerSelect & 0x3f;
  selectFlagBit6 = (selectFlag & 1) << 6;
  programState = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  *outWord = selectFlagBit6 | registerBits | oldWord & 0xefffff00;
  flagBit20 = (operand[2] & 1) << 0x14;
  *outWord = flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xefefff00;
  flagBit21 = (operand[3] & 1) << 0x15;
  *outWord = flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xefcfff00;
  flagBit22 = (operand[4] & 1) << 0x16;
  *outWord = flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef8fff00;
  flagBit23 = (operand[5] & 1) << 0x17;
  *outWord = flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef0fff00;
  operandKind = *operand;
  if (operandKind == 2) {
    symbolEntry = operand[1] * 0x54 + shader[8];
    if (*(int *)(symbolEntry + 0x28) == 0x87c4) {
      symbolDataType = *(int *)(symbolEntry + 0x24);
      if (symbolDataType == 0x87bf) {
        *outWord = flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef0ff000;
        encodedWord = (*(uint *)(symbolEntry + 4) & 0x7f) << 0xd |
                flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef001000;
        *outWord = encodedWord;
      }
      else if (symbolDataType == 0x87c0) {
        *outWord = flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef0ff000;
        encodedWord = (*(uint *)(matrixRow * 4 + symbolEntry + 0x10) & 0x7f) << 0xd |
                flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef001000;
        *outWord = encodedWord;
      }
      else {
        if (symbolDataType != 0x87be) {
          return 0;
        }
        *outWord = flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef0ff000;
        encodedWord = (*(uint *)(symbolEntry + 4) & 0x7f) << 0xd;
        registerBits = registerBits | oldWord & 0xef001000;
        *outWord = encodedWord | flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits;
        symbolEntry = *(int *)(symbolEntry + 8);
        if (symbolEntry == 1) {
          encodedWord = encodedWord | flagBit21 | selectFlagBit6 | registerBits;
          *outWord = encodedWord;
        }
        else if (symbolEntry == 0) {
          encodedWord = encodedWord | flagBit20 | selectFlagBit6 | registerBits;
          *outWord = encodedWord;
        }
        else if (symbolEntry == 2) {
          encodedWord = encodedWord | flagBit22 | selectFlagBit6 | registerBits;
          *outWord = encodedWord;
        }
        else {
          if (symbolEntry != 3) {
            return 0;
          }
          encodedWord = encodedWord | flagBit23 | selectFlagBit6 | registerBits;
          *outWord = encodedWord;
        }
      }
    }
    else {
      if (*(int *)(symbolEntry + 0x28) != -1) {
        return 0;
      }
      encodedWord = flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef001000 | 0x100;
      *outWord = encodedWord;
    }
  }
  else if (operandKind < 3) {
    if (operandKind != 1) {
      return 0;
    }
    *outWord = flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef0ff000 | 0x200;
    encodedWord = operand[1];
    if (encodedWord == 0x879b) {
      encodedWord = (*(uint *)(programState + 0x1ec) & 0x7f) << 0xd |
              flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef001000 | 0x200;
      *outWord = encodedWord;
    }
    else if (encodedWord < 0x879c) {
      if (encodedWord == 0x610f) {
        if (*(char *)((int)shader + 0x6f) != '\0') {
          encodedWord = (*(uint *)(programState + 500) & 0x7f) << 0xd |
                  flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef001000 | 0x200;
          *outWord = encodedWord;
          goto LAB_00057320;
        }
      }
      else {
        if (encodedWord < 0x6110) {
          if (encodedWord != 0x610e) {
            return 0;
          }
          if (*(char *)((int)shader + 0x79) == '\0') {
            *outWord = flagBit23 | flagBit22 | flagBit21 | selectFlagBit6 | registerBits | oldWord & 0xef001000 | 0x200;
          }
          else {
            *outWord = (*(uint *)(programState + 0x1fc) & 0x7f) << 0xd |
                       flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef001000 | 0x200;
          }
          encodedWord = *outWord & 0xff1fffff;
          *outWord = encodedWord;
          goto LAB_00057320;
        }
        if (encodedWord != 0x6110) {
          if (encodedWord != 0x879a) {
            return 0;
          }
          encodedWord = (*(uint *)(programState + 0x1e8) & 0x7f) << 0xd |
                  flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef001000 | 0x200;
          *outWord = encodedWord;
          goto LAB_00057320;
        }
        if (*(char *)(shader + 0x1c) != '\0') {
          encodedWord = (*(uint *)(programState + 0x1f8) & 0x7f) << 0xd |
                  flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef001000 | 0x200;
          *outWord = encodedWord;
          goto LAB_00057320;
        }
      }
      encodedWord = selectFlagBit6 | registerBits | oldWord & 0xef001000 | 0x200;
      *outWord = encodedWord;
    }
    else if (encodedWord < 0x87a5) {
      if (encodedWord < 0x879d) {
        encodedWord = (*(uint *)(programState + 0x1f0) & 0x7f) << 0xd |
                flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef001000 | 0x200;
        *outWord = encodedWord;
        if (*(char *)(programState + 0x42) != '\0') {
          encodedWord = *outWord & 0xff7fffff;
          *outWord = encodedWord;
        }
      }
      else {
        encodedWord = (*(uint *)(encodedWord * 4 + programState + -0x21c74) & 0x7f) << 0xd |
                flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef001000 | 0x200;
        *outWord = encodedWord;
      }
    }
    else {
      if (encodedWord != 0x87bd) {
        return 0;
      }
      *outWord = flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef0ff000 | 0x300;
      stateIndexBits = (*(uint *)(programState + 0x1f0) & 0x7f) << 0xd;
      registerBits = registerBits | oldWord & 0xef001000;
      *outWord = stateIndexBits | flagBit23 | selectFlagBit6 | registerBits | 0x300;
      encodedWord = (*(byte *)(programState + 0x42) & 1) << 0x17 | stateIndexBits | selectFlagBit6 | registerBits | 0x300;
      *outWord = encodedWord;
    }
  }
  else if (operandKind == 3) {
    *outWord = flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef0ff000;
    encodedWord = (operand[1] & 0x7f) << 0xd |
            flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef001000;
    *outWord = encodedWord;
  }
  else {
    if (operandKind != 5) {
      return 0;
    }
    *outWord = flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef0ff000 | 0x100;
    encodedWord = (operand[1] & 0x7f) << 0xd |
            flagBit23 | flagBit22 | flagBit21 | flagBit20 | selectFlagBit6 | registerBits | oldWord & 0xef001000 | 0x100;
    *outWord = encodedWord;
  }
LAB_00057320:
  *outWord = encodedWord & 0x1fffefff;
  return 1;
}

/* extvsEncodeSourceSwizzle @ 0x57340 (1768 bytes) */
int extvsEncodeSourceSwizzle(shader, symbolList, operand, outWord, matrixRow)
  undefined4 shader;
  int symbolList;
  uint *operand;
  uint *outWord;
  int matrixRow;
{
  int entryDataType;
  uint broadcastX;
  uint symbolStorage;
  uint finalWord;
  uint operandKind;
  uint registerIndexBits;
  uint broadcastY;
  uint broadcastZ;
  uint swizzleWord;
  uint componentClassBit;
  int symbolDataType;
  int symbolOffset;
  int symbolEntry;
  
  switch(operand[2]) {
  case 0x87d5:
  case 0x87d9:
    swizzleWord = *outWord & 0xffff1fff;
    *outWord = swizzleWord;
    break;
  case 0x87d6:
  case 0x87da:
    swizzleWord = *outWord & 0xffff1fff | 0x2000;
    *outWord = swizzleWord;
    break;
  case 0x87d7:
  case 0x87db:
    swizzleWord = *outWord & 0xffff1fff | 0x4000;
    *outWord = swizzleWord;
    break;
  case 0x87d8:
  case 0x87dc:
    swizzleWord = *outWord & 0xffff1fff | 0x6000;
    *outWord = swizzleWord;
    break;
  case 0x87dd:
    swizzleWord = *outWord & 0xffff1fff | 0x8000;
    *outWord = swizzleWord;
    break;
  case 0x87de:
  case 0x87df:
    swizzleWord = *outWord & 0xffff1fff | 0xa000;
    *outWord = swizzleWord;
    break;
  default:
    goto LAB_00057ae0;
  }
  if (10 < operand[2] - 0x87d5) {
LAB_00057ae0:
    return 0;
  }
  componentClassBit = 1 << (operand[2] - 0x87d5 & 0x3f);
  if ((componentClassBit & 0x30f) == 0) {
    if ((componentClassBit & 0x4f0) == 0) {
      return 0;
    }
    swizzleWord = swizzleWord | 0x2000000;
    *outWord = swizzleWord;
  }
  else {
    swizzleWord = swizzleWord & 0xfdffffff;
    *outWord = swizzleWord;
  }
  switch(operand[3]) {
  case 0x87d5:
  case 0x87d9:
    swizzleWord = swizzleWord & 0xfff8ffff;
    *outWord = swizzleWord;
    break;
  case 0x87d6:
  case 0x87da:
    swizzleWord = swizzleWord & 0xfff8ffff | 0x10000;
    *outWord = swizzleWord;
    break;
  case 0x87d7:
  case 0x87db:
    swizzleWord = swizzleWord & 0xfff8ffff | 0x20000;
    *outWord = swizzleWord;
    break;
  case 0x87d8:
  case 0x87dc:
    swizzleWord = swizzleWord & 0xfff8ffff | 0x30000;
    *outWord = swizzleWord;
    break;
  case 0x87dd:
    swizzleWord = swizzleWord & 0xfff8ffff | 0x40000;
    *outWord = swizzleWord;
    break;
  case 0x87de:
  case 0x87df:
    swizzleWord = swizzleWord & 0xfff8ffff | 0x50000;
    *outWord = swizzleWord;
    break;
  default:
    return 0;
  }
  if (10 < operand[3] - 0x87d5) {
    return 0;
  }
  componentClassBit = 1 << (operand[3] - 0x87d5 & 0x3f);
  if ((componentClassBit & 0x30f) == 0) {
    if ((componentClassBit & 0x4f0) == 0) {
      return 0;
    }
    swizzleWord = swizzleWord | 0x4000000;
    *outWord = swizzleWord;
  }
  else {
    swizzleWord = swizzleWord & 0xfbffffff;
    *outWord = swizzleWord;
  }
  switch(operand[4]) {
  case 0x87d5:
  case 0x87d9:
    swizzleWord = swizzleWord & 0xffc7ffff;
    *outWord = swizzleWord;
    break;
  case 0x87d6:
  case 0x87da:
    swizzleWord = swizzleWord & 0xffc7ffff | 0x80000;
    *outWord = swizzleWord;
    break;
  case 0x87d7:
  case 0x87db:
    swizzleWord = swizzleWord & 0xffc7ffff | 0x100000;
    *outWord = swizzleWord;
    break;
  case 0x87d8:
  case 0x87dc:
    swizzleWord = swizzleWord & 0xffc7ffff | 0x180000;
    *outWord = swizzleWord;
    break;
  case 0x87dd:
    swizzleWord = swizzleWord & 0xffc7ffff | 0x200000;
    *outWord = swizzleWord;
    break;
  case 0x87de:
  case 0x87df:
    swizzleWord = swizzleWord & 0xffc7ffff | 0x280000;
    *outWord = swizzleWord;
    break;
  default:
    return 0;
  }
  if (10 < operand[4] - 0x87d5) {
    return 0;
  }
  componentClassBit = 1 << (operand[4] - 0x87d5 & 0x3f);
  if ((componentClassBit & 0x30f) == 0) {
    if ((componentClassBit & 0x4f0) == 0) {
      return 0;
    }
    swizzleWord = swizzleWord | 0x8000000;
    *outWord = swizzleWord;
  }
  else {
    swizzleWord = swizzleWord & 0xf7ffffff;
    *outWord = swizzleWord;
  }
  switch(operand[5]) {
  case 0x87d5:
  case 0x87d9:
    swizzleWord = swizzleWord & 0xfe3fffff;
    *outWord = swizzleWord;
    break;
  case 0x87d6:
  case 0x87da:
    swizzleWord = swizzleWord & 0xfe3fffff | 0x400000;
    *outWord = swizzleWord;
    break;
  case 0x87d7:
  case 0x87db:
    swizzleWord = swizzleWord & 0xfe3fffff | 0x800000;
    *outWord = swizzleWord;
    break;
  case 0x87d8:
  case 0x87dc:
    swizzleWord = swizzleWord & 0xfe3fffff | 0xc00000;
    *outWord = swizzleWord;
    break;
  case 0x87dd:
    swizzleWord = swizzleWord & 0xfe3fffff | 0x1000000;
    *outWord = swizzleWord;
    break;
  case 0x87de:
  case 0x87df:
    swizzleWord = swizzleWord & 0xfe3fffff | 0x1400000;
    *outWord = swizzleWord;
    break;
  default:
    return 0;
  }
  if (10 < operand[5] - 0x87d5) {
    return 0;
  }
  componentClassBit = 1 << (operand[5] - 0x87d5 & 0x3f);
  if ((componentClassBit & 0x30f) == 0) {
    if ((componentClassBit & 0x4f0) == 0) {
      return 0;
    }
    swizzleWord = swizzleWord | 0x10000000;
    *outWord = swizzleWord;
  }
  else {
    swizzleWord = swizzleWord & 0xefffffff;
    *outWord = swizzleWord;
  }
  operandKind = *operand;
  if (operandKind != 2) {
    if (operandKind < 3) {
      if (operandKind != 0) {
        return 0;
      }
      finalWord = swizzleWord & 0xffffe018;
      *outWord = finalWord;
    }
    else if (operandKind == 3) {
      *outWord = swizzleWord & 0xfffffff8;
      finalWord = (operand[1] & 0xff) << 5 | swizzleWord & 0xffffe018;
      *outWord = finalWord;
    }
    else {
      if (operandKind != 4) {
        return 0;
      }
      *outWord = swizzleWord & 0xfffffff8 | 2;
      finalWord = (operand[1] & 0xff) << 5 | swizzleWord & 0xffffe018 | 2;
      *outWord = finalWord;
    }
    goto LAB_00057aa0;
  }
  symbolOffset = operand[1] * 0x54;
  symbolEntry = symbolOffset + *(int *)(symbolList + 4);
  symbolStorage = *(uint *)(symbolEntry + 0x28);
  if (symbolStorage < 0x87c4) {
    if (symbolStorage < 0x87c2) {
      if (symbolStorage != 0x87c1) {
        return 0;
      }
      symbolDataType = *(int *)(symbolEntry + 0x24);
      if (symbolDataType == 0x87bf) {
        *outWord = swizzleWord & 0xfffffff8 | 1;
        registerIndexBits = (*(uint *)(symbolEntry + 4) & 0xff) << 5;
        finalWord = registerIndexBits | swizzleWord & 0xffffe018 | 1;
        *outWord = finalWord;
        symbolOffset = symbolOffset + *(int *)(symbolList + 4);
        if ((*(char *)(symbolOffset + 0x44) != '\0') && (*(int *)(symbolOffset + 0x48) == 1)) {
          finalWord = registerIndexBits | swizzleWord & 0xfe3fe018 | 1 | 0x1000000;
          *outWord = finalWord;
        }
        goto LAB_00057aa0;
      }
      if (symbolDataType != 0x87c0) {
        if (symbolDataType != 0x87be) {
          return 0;
        }
        *outWord = swizzleWord & 0xfffffff8 | 1;
        finalWord = (*(uint *)(symbolEntry + 4) & 0xff) << 5;
        *outWord = finalWord | swizzleWord & 0xffffe018 | 1;
        broadcastX = (*(uint *)(symbolEntry + 8) & 7) << 0xd;
        *outWord = broadcastX | finalWord | swizzleWord & 0xffff0018 | 1;
        symbolOffset = symbolOffset + *(int *)(symbolList + 4);
        if ((*(char *)(symbolOffset + 0x44) == '\0') || (*(int *)(symbolOffset + 0x48) != 0xf)) {
          broadcastY = (*(uint *)(symbolEntry + 8) & 7) << 0x10;
          *outWord = broadcastY | broadcastX | finalWord | swizzleWord & 0xfff80018 | 1;
          broadcastZ = (*(uint *)(symbolEntry + 8) & 7) << 0x13;
          *outWord = broadcastZ | broadcastY | broadcastX | finalWord | swizzleWord & 0xffc00018 | 1;
          finalWord = (*(uint *)(symbolEntry + 8) & 7) << 0x16 |
                  broadcastZ | broadcastY | broadcastX | finalWord | swizzleWord & 0xfe000018 | 1;
          *outWord = finalWord;
        }
        else {
          finalWord = broadcastX | finalWord | swizzleWord & 0xfe000018 | 1 | 0x1640000;
          *outWord = finalWord;
        }
        finalWord = finalWord & 0xe1ffffff;
        *outWord = finalWord;
        goto LAB_00057aa0;
      }
      swizzleWord = swizzleWord & 0xfffffff8 | 1;
    }
    else {
      entryDataType = *(int *)(symbolEntry + 0x24);
      if (entryDataType == 0x87bf) {
        *outWord = swizzleWord & 0xfffffff8 | 2;
        finalWord = (*(uint *)(symbolEntry + 4) & 0xff) << 5 | swizzleWord & 0xffffe018 | 2;
        *outWord = finalWord;
        goto LAB_00057aa0;
      }
      if (entryDataType != 0x87c0) {
        swizzleWord = swizzleWord & 0xfffffff8 | 2;
        if (entryDataType != 0x87be) {
          return 0;
        }
        goto LAB_000579dc;
      }
      swizzleWord = swizzleWord & 0xfffffff8 | 2;
    }
    *outWord = swizzleWord;
    finalWord = (*(uint *)(matrixRow * 4 + symbolEntry + 0x10) & 0xff) << 5 | swizzleWord & 0xffffe01f;
    *outWord = finalWord;
  }
  else {
    if (symbolStorage != 0x87c4) {
      return 0;
    }
    entryDataType = *(int *)(symbolEntry + 0x24);
    if (entryDataType == 0x87bf) {
      *outWord = swizzleWord & 0xfffffff8;
      finalWord = (*(uint *)(symbolEntry + 4) & 0xff) << 5 | swizzleWord & 0xffffe018;
      *outWord = finalWord;
      goto LAB_00057aa0;
    }
    if (entryDataType == 0x87c0) {
      *outWord = swizzleWord & 0xfffffff8;
      finalWord = (*(uint *)(matrixRow * 4 + symbolEntry + 0x10) & 0xff) << 5 | swizzleWord & 0xffffe018;
      *outWord = finalWord;
      goto LAB_00057aa0;
    }
    if (entryDataType != 0x87be) {
      return 0;
    }
    swizzleWord = swizzleWord & 0xfffffff8;
LAB_000579dc:
    *outWord = swizzleWord;
    finalWord = (*(uint *)(symbolEntry + 4) & 0xff) << 5;
    *outWord = finalWord | swizzleWord & 0xffffe01f;
    broadcastX = (*(uint *)(symbolEntry + 8) & 7) << 0xd;
    *outWord = broadcastX | finalWord | swizzleWord & 0xffff001f;
    broadcastY = (*(uint *)(symbolEntry + 8) & 7) << 0x10;
    *outWord = broadcastY | broadcastX | finalWord | swizzleWord & 0xfff8001f;
    broadcastZ = (*(uint *)(symbolEntry + 8) & 7) << 0x13;
    *outWord = broadcastZ | broadcastY | broadcastX | finalWord | swizzleWord & 0xffc0001f;
    finalWord = (*(uint *)(symbolEntry + 8) & 7) << 0x16 | broadcastZ | broadcastY | broadcastX | finalWord | swizzleWord & 0xe000001f;
    *outWord = finalWord;
  }
LAB_00057aa0:
  if (*(char *)(operand + 6) == '\0') {
    finalWord = finalWord & 0x9fffffef;
    *outWord = finalWord;
  }
  else {
    finalWord = finalWord & 0x9fffffff | 0x10;
    *outWord = finalWord;
  }
  *outWord = finalWord & 0x7fffffff;
  return 1;
}

/* extvsOperandsConflictInBank @ 0x57af0 (144 bytes) */
int extvsOperandsConflictInBank(symbolList, operandA, operandB)
  int symbolList;
  int *operandA;
  int *operandB;
{
  int storageA;
  int storageB;
  
  if ((*operandA == 2) && (*operandB == 2)) {
    if (operandA[1] != operandB[1]) {
      storageA = *(int *)(operandA[1] * 0x54 + *(int *)(symbolList + 4) + 0x28);
      storageB = *(int *)(operandB[1] * 0x54 + *(int *)(symbolList + 4) + 0x28);
      if (((storageA == 0x87c1) && (storageB == 0x87c1)) ||
         ((storageA - 0x87c2U < 2 && (storageB - 0x87c2U < 2)))) {
        return 1;
      }
    }
  }
  return 0;
}

/* extvsAllocTempSlot @ 0x57b80 (360 bytes) */
int extvsAllocTempSlot(ctx, shader)
  int ctx;
  int *shader;
{
  bool searching;
  int iVar2;
  int newSlotOffset;
  undefined4 foundFree;
  uint slotIndex;
  int programState;
  
  slotIndex = 0;
  searching = true;
  foundFree = 0;
  iVar2 = 0;
  programState = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  while( true ) {
    if (*(uint *)(programState + 0x50) <= slotIndex) {
      if (searching) {
        *(char *)(shader + 4) = (char)foundFree;
        slotIndex = *(uint *)(programState + 0x50);
        iVar2 = (**(code **)(ctx + 0x10))(slotIndex + 0x10,0x28);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (iVar2,*(undefined4 *)(programState + 0x4c),*(int *)(programState + 0x50) * 0x28);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x4c));
        newSlotOffset = slotIndex * 0x28;
        *(int *)(programState + 0x4c) = iVar2;
        *(int *)(programState + 0x50) = *(int *)(programState + 0x50) + 0x10;
        *(undefined1 *)(iVar2 + newSlotOffset + 0x10) = 1;
        *(undefined4 *)(newSlotOffset + *(int *)(programState + 0x4c) + 0x14) = 4;
        *(undefined4 *)(newSlotOffset + *(int *)(programState + 0x4c) + 0x18) = foundFree;
        *(undefined4 *)(newSlotOffset + *(int *)(programState + 0x4c) + 0x1c) = foundFree;
        *(undefined4 *)(newSlotOffset + *(int *)(programState + 0x4c) + 0x20) = foundFree;
        *(undefined4 *)(newSlotOffset + *(int *)(programState + 0x4c) + 0x24) = foundFree;
        shader[0x19] = shader[0x19] + 1;
      }
      return slotIndex;
    }
    if (!searching) break;
    if (*(char *)(iVar2 + *(int *)(programState + 0x4c) + 0x10) == '\0') {
      foundFree = 1;
      searching = false;
    }
    else {
      slotIndex = slotIndex + 1;
      iVar2 = iVar2 + 0x28;
    }
  }
  return slotIndex;
}

/* extvsEmitIndex @ 0x57cf0 (1532 bytes) */
int extvsEmitIndex(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int src1Operand;
  int instCount;
  int instSlot;
  undefined4 tempIndex;
  uint extvsOperandDataTypeResult;
  uint uVar1;
  undefined4 newInstArray;
  int hwProgram;
  int dstOperand;
  int *symbolList;
  int iVar6;
  undefined4 tmpOperand0Kind;
  undefined4 tmpOperand0Index;
  undefined4 tmpOperand0Comp0;
  undefined4 tmpOperand0Comp1;
  undefined4 tmpOperand0Comp2;
  undefined4 tmpOperand0Comp3;
  undefined1 tmpOperand0Flag;
  undefined4 tmpOperand1Kind;
  undefined4 tmpOperand1Index;
  undefined4 tmpOperand1Comp0;
  undefined4 tmpOperand1Comp1;
  undefined4 tmpOperand1Comp2;
  undefined4 tmpOperand1Comp3;
  undefined1 tmpOperand1Flag;
  
  symbolList = shader + 7;
  dstOperand = instRecord + 4;
  extvsOperandDataTypeResult = ((int (*)())extvsOperandDataType)(symbolList,dstOperand);
  if (0x87bd < extvsOperandDataTypeResult) {
    if (extvsOperandDataTypeResult < 0x87c0) {
      hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
      iVar6 = *(int *)(hwProgram + 0x18);
      if (0x100 < iVar6 + 2U) {
        *(undefined1 *)(shader + 4) = 0;
        iVar6 = *(int *)(hwProgram + 0x18);
        if (*(uint *)(hwProgram + 0x20) < iVar6 + 2U) {
          newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
          (**(code **)(((unsigned char *)0x00001344) + ctx))
                    (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
          *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
          iVar6 = *(int *)(hwProgram + 0x18);
          *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
        }
      }
      tmpOperand0Index = 0;
      tmpOperand0Comp1 = 0;
      tmpOperand0Comp0 = 1;
      tmpOperand0Comp2 = 0;
      tmpOperand0Comp3 = 0;
      tmpOperand0Flag = 0;
      instSlot = iVar6 * 0x10 + *(int *)(hwProgram + 0x1c);
      tmpOperand0Kind = 5;
      ((int (*)())extvsEncodeSourceOperand)(ctx,shader,&tmpOperand0Kind,instSlot,0xd,0,0);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,instRecord + 0x20,instSlot + 4,0);
      *(undefined4 *)(instSlot + 0xc) = *(undefined4 *)(instSlot + 4);
      *(undefined4 *)(instSlot + 8) = *(undefined4 *)(instSlot + 4);
      ((int (*)())extvsEncodeSourceOperand)(ctx,shader,dstOperand,instSlot + 0x10,3,0,0);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,instRecord + 0x3c,instSlot + 0x14,0);
      uVar1 = *(uint *)(instSlot + 0x14);
      if ((uVar1 & 7) != 2) {
        *(undefined1 *)(shader + 4) = 0;
        uVar1 = *(uint *)(instSlot + 0x14);
      }
      *(uint *)(instSlot + 0x14) = uVar1 & 0x9fffffff | 0x10;
      uVar1 = uVar1 & 0x9e001fff | 0x1248010;
      *(uint *)(instSlot + 0x1c) = uVar1;
      *(uint *)(instSlot + 0x18) = uVar1;
      return 2;
    }
    if (extvsOperandDataTypeResult == 0x87c0) {
      iVar6 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
      instCount = *(int *)(iVar6 + 0x18);
      if (0x100 < instCount + 7U) {
        *(undefined1 *)(shader + 4) = 0;
        instCount = *(int *)(iVar6 + 0x18);
        if (*(uint *)(iVar6 + 0x20) < instCount + 7U) {
          newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(iVar6 + 0x20) * 0x10 + 0x100);
          (**(code **)(((unsigned char *)0x00001344) + ctx))
                    (newInstArray,*(undefined4 *)(iVar6 + 0x1c),*(int *)(iVar6 + 0x20) << 4);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(iVar6 + 0x1c));
          *(undefined4 *)(iVar6 + 0x1c) = newInstArray;
          instCount = *(int *)(iVar6 + 0x18);
          *(int *)(iVar6 + 0x20) = *(int *)(iVar6 + 0x20) + 0x10;
        }
      }
      iVar6 = instCount * 0x10 + *(int *)(iVar6 + 0x1c);
      src1Operand = instRecord + 0x3c;
      tempIndex = ((int (*)())extvsAllocTempSlot)(ctx,shader);
      tmpOperand0Kind = 3;
      tmpOperand0Comp0 = 1;
      tmpOperand0Comp1 = 0;
      tmpOperand0Comp2 = 0;
      tmpOperand0Comp3 = 0;
      tmpOperand0Flag = 0;
      tmpOperand0Index = tempIndex;
      ((int (*)())extvsEncodeSourceOperand)(ctx,shader,&tmpOperand0Kind,iVar6,1,0,0);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,instRecord + 0x20,iVar6 + 4,0);
      uVar1 = *(uint *)(iVar6 + 4) & 0xfe001fff | 0x16da000;
      *(uint *)(iVar6 + 4) = uVar1;
      *(uint *)(iVar6 + 0xc) = uVar1;
      *(uint *)(iVar6 + 8) = uVar1;
      ((int (*)())extvsEncodeSourceOperand)(ctx,shader,&tmpOperand0Kind,iVar6 + 0x10,2,0,0);
      tmpOperand1Kind = 3;
      tmpOperand1Flag = 0;
      tmpOperand1Comp3 = 0x87d5;
      tmpOperand1Comp0 = 0x87d5;
      tmpOperand1Comp1 = 0x87d5;
      tmpOperand1Comp2 = 0x87d5;
      tmpOperand1Index = tempIndex;
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,&tmpOperand1Kind,iVar6 + 0x14,0);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,instRecord + 0x20,iVar6 + 0x18,0);
      *(undefined4 *)(iVar6 + 0x1c) = *(undefined4 *)(iVar6 + 0x18);
      tmpOperand0Kind = 5;
      tmpOperand0Comp0 = 1;
      tmpOperand0Index = 0;
      tmpOperand0Comp1 = 0;
      tmpOperand0Comp2 = 0;
      tmpOperand0Comp3 = 0;
      tmpOperand0Flag = 0;
      ((int (*)())extvsEncodeSourceOperand)(ctx,shader,&tmpOperand0Kind,iVar6 + 0x20,0xd,0,0);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,&tmpOperand1Kind,iVar6 + 0x24,0);
      *(undefined4 *)(iVar6 + 0x2c) = *(undefined4 *)(iVar6 + 0x24);
      *(undefined4 *)(iVar6 + 0x28) = *(undefined4 *)(iVar6 + 0x24);
      ((int (*)())extvsEncodeSourceOperand)(ctx,shader,dstOperand,iVar6 + 0x30,3,0,0);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src1Operand,iVar6 + 0x34,0);
      uVar1 = *(uint *)(iVar6 + 0x34);
      if ((uVar1 & 7) != 2) {
        *(undefined1 *)(shader + 4) = 0;
        uVar1 = *(uint *)(iVar6 + 0x34);
      }
      *(uint *)(iVar6 + 0x34) = uVar1 & 0x9fffffff | 0x10;
      uVar1 = uVar1 & 0x9e001fff | 0x1248010;
      *(uint *)(iVar6 + 0x3c) = uVar1;
      *(uint *)(iVar6 + 0x38) = uVar1;
      ((int (*)())extvsEncodeSourceOperand)(ctx,shader,dstOperand,iVar6 + 0x40,3,0,1);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src1Operand,iVar6 + 0x44,1);
      uVar1 = *(uint *)(iVar6 + 0x44);
      *(uint *)(iVar6 + 0x44) = uVar1 & 0x9fffffff | 0x10;
      uVar1 = uVar1 & 0x9e001fff | 0x1248010;
      *(uint *)(iVar6 + 0x4c) = uVar1;
      *(uint *)(iVar6 + 0x48) = uVar1;
      ((int (*)())extvsEncodeSourceOperand)(ctx,shader,dstOperand,iVar6 + 0x50,3,0,2);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src1Operand,iVar6 + 0x54,2);
      uVar1 = *(uint *)(iVar6 + 0x54);
      *(uint *)(iVar6 + 0x54) = uVar1 & 0x9fffffff | 0x10;
      uVar1 = uVar1 & 0x9e001fff | 0x1248010;
      *(uint *)(iVar6 + 0x5c) = uVar1;
      *(uint *)(iVar6 + 0x58) = uVar1;
      ((int (*)())extvsEncodeSourceOperand)(ctx,shader,dstOperand,iVar6 + 0x60,3,0,3);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src1Operand,iVar6 + 100,3);
      uVar1 = *(uint *)(iVar6 + 100);
      *(uint *)(iVar6 + 100) = uVar1 & 0x9fffffff | 0x10;
      uVar1 = uVar1 & 0x9e001fff | 0x1248010;
      *(uint *)(iVar6 + 0x6c) = uVar1;
      *(uint *)(iVar6 + 0x68) = uVar1;
      return 7;
    }
  }
  return 0xffffffff;
}

/* extvsEmitSingleSourceInstruction @ 0x58300 (332 bytes) */
int extvsEmitSingleSourceInstruction(ctx, shader, inst)
  int ctx;
  int *shader;
  int inst;
{
  uint uVar1;
  undefined4 uVar2;
  int outInst;
  int programState;
  
  programState = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  outInst = *(int *)(programState + 0x18);
  if (0x100 < outInst + 1U) {
    *(undefined1 *)(shader + 4) = 0;
    outInst = *(int *)(programState + 0x18);
    if (*(uint *)(programState + 0x20) < outInst + 1U) {
      uVar2 = (**(code **)(ctx + 0xc))(*(uint *)(programState + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (uVar2,*(undefined4 *)(programState + 0x1c),*(int *)(programState + 0x20) << 4);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x1c));
      *(undefined4 *)(programState + 0x1c) = uVar2;
      outInst = *(int *)(programState + 0x18);
      *(int *)(programState + 0x20) = *(int *)(programState + 0x20) + 0x10;
    }
  }
  outInst = outInst * 0x10 + *(int *)(programState + 0x1c);
  ((int (*)())extvsEncodeSourceOperand)(ctx,shader,inst + 4,outInst,3,0,0);
  ((int (*)())extvsEncodeSourceSwizzle)(shader,shader + 7,inst + 0x20,outInst + 4,0);
  uVar1 = *(uint *)(outInst + 4);
  *(uint *)(outInst + 4) = uVar1 | 0x1e000000;
  uVar1 = uVar1 & 0xe0001fff | 0x1248000;
  *(uint *)(outInst + 0xc) = uVar1;
  *(uint *)(outInst + 8) = uVar1;
  return 1;
}

/* extvsEmitDot3 @ 0x58450 (872 bytes) */
int extvsEmitDot3(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  int hwProgram;
  uint uVar1;
  int conflict;
  undefined4 uVar3;
  int src1Operand;
  int dstOperand;
  int src0Operand;
  int instCount;
  int *symbolList;
  undefined4 tmpOperand0Kind;
  undefined4 tmpOperand0Index;
  undefined4 tmpOperand0Comp0;
  undefined4 tmpOperand0Comp1;
  undefined4 tmpOperand0Comp2;
  undefined4 tmpOperand0Comp3;
  undefined1 tmpOperand0Flag;
  undefined4 tmpOperand1Kind;
  undefined4 tmpOperand1Index;
  undefined4 tmpOperand1Comp0;
  undefined4 tmpOperand1Comp1;
  undefined4 tmpOperand1Comp2;
  undefined4 tmpOperand1Comp3;
  undefined1 tmpOperand1Flag;
  
  symbolList = shader + 7;
  dstOperand = instRecord + 4;
  src0Operand = instRecord + 0x20;
  src1Operand = instRecord + 0x3c;
  ((int (*)())extvsOperandDataType)(symbolList,dstOperand);
  conflict = ((int (*)())extvsOperandsConflictInBank)(symbolList,src0Operand,src1Operand);
  if (conflict == 0) {
    hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(hwProgram + 0x18);
    if (0x100 < instCount + 1U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(hwProgram + 0x18);
      if (*(uint *)(hwProgram + 0x20) < instCount + 1U) {
        uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar3,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
        *(undefined4 *)(hwProgram + 0x1c) = uVar3;
        instCount = *(int *)(hwProgram + 0x18);
        *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
      }
    }
    instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
    ((int (*)())extvsEncodeSourceOperand)(ctx,shader,dstOperand,instSlot,1,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src0Operand,instSlot + 4,0);
    *(uint *)(instSlot + 4) = *(uint *)(instSlot + 4) & 0xfe3fffff | 0x1000000;
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src1Operand,instSlot + 8,0);
    uVar3 = 1;
    uVar1 = *(uint *)(instSlot + 8) & 0xfe3fffff | 0x1000000;
    *(uint *)(instSlot + 0xc) = uVar1;
    *(uint *)(instSlot + 8) = uVar1;
  }
  else {
    hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(hwProgram + 0x18);
    if (0x100 < instCount + 2U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(hwProgram + 0x18);
      if (*(uint *)(hwProgram + 0x20) < instCount + 2U) {
        uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar3,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
        *(undefined4 *)(hwProgram + 0x1c) = uVar3;
        instCount = *(int *)(hwProgram + 0x18);
        *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
      }
    }
    instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
    uVar3 = ((int (*)())extvsAllocTempSlot)(ctx,shader);
    tmpOperand0Kind = 3;
    tmpOperand0Flag = 0;
    tmpOperand0Comp3 = 1;
    tmpOperand0Comp0 = 1;
    tmpOperand0Comp1 = 1;
    tmpOperand0Comp2 = 1;
    tmpOperand0Index = uVar3;
    ((int (*)())extvsEncodeSourceOperand)(ctx,shader,&tmpOperand0Kind,instSlot,3,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src0Operand,instSlot + 4,0);
    uVar1 = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(instSlot + 0xc) = uVar1;
    *(uint *)(instSlot + 8) = uVar1;
    ((int (*)())extvsEncodeSourceOperand)(ctx,shader,dstOperand,instSlot + 0x10,1,0,0);
    tmpOperand1Kind = 3;
    tmpOperand1Flag = 0;
    tmpOperand1Comp0 = 0x87d5;
    tmpOperand1Comp1 = 0x87d6;
    tmpOperand1Comp2 = 0x87d7;
    tmpOperand1Comp3 = 0x87dd;
    tmpOperand1Index = uVar3;
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,&tmpOperand1Kind,instSlot + 0x14,0);
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src1Operand,instSlot + 0x18,0);
    uVar3 = 2;
    uVar1 = *(uint *)(instSlot + 0x18) & 0xfe3fffff | 0x1000000;
    *(uint *)(instSlot + 0x1c) = uVar1;
    *(uint *)(instSlot + 0x18) = uVar1;
  }
  return uVar3;
}

/* extvsEmitDot4 @ 0x587d0 (824 bytes) */
int extvsEmitDot4(compiler, program, irInstruction)
  int compiler;
  int *program;
  int irInstruction;
{
  uint packedWord;
  int block;
  undefined4 emitResult;
  int src1Operand;
  int src0Operand;
  int *operandState;
  int instrCount;
  undefined4 tempDstFile;
  undefined4 tempDstIndex;
  undefined4 tempDstMask0;
  undefined4 tempDstMask1;
  undefined4 tempDstMask2;
  undefined4 tempDstMask3;
  undefined1 tempDstFlag;
  undefined4 tempSrcFile;
  undefined4 tempSrcIndex;
  undefined4 tempSrcSel0;
  undefined4 tempSrcSel1;
  undefined4 tempSrcSel2;
  undefined4 tempSrcSel3;
  undefined1 tempSrcFlag;
  
  src0Operand = irInstruction + 0x20;
  operandState = program + 7;
  src1Operand = irInstruction + 0x3c;
  block = ((int (*)())extvsOperandsConflictInBank)(operandState,src0Operand,src1Operand);
  if (block == 0) {
    block = **(int **)(*(int *)(((unsigned char *)0x0000118c) + compiler) * 4 + *program);
    instrCount = *(int *)(block + 0x18);
    if (0x100 < instrCount + 1U) {
      *(undefined1 *)(program + 4) = 0;
      instrCount = *(int *)(block + 0x18);
      if (*(uint *)(block + 0x20) < instrCount + 1U) {
        emitResult = (**(code **)(compiler + 0xc))(*(uint *)(block + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + compiler))
                  (emitResult,*(undefined4 *)(block + 0x1c),*(int *)(block + 0x20) << 4);
        (**(code **)(compiler + 0x18))(*(undefined4 *)(block + 0x1c));
        *(undefined4 *)(block + 0x1c) = emitResult;
        instrCount = *(int *)(block + 0x18);
        *(int *)(block + 0x20) = *(int *)(block + 0x20) + 0x10;
      }
    }
    block = instrCount * 0x10 + *(int *)(block + 0x1c);
    ((int (*)())extvsEncodeSourceOperand)(compiler,program,irInstruction + 4,block,1,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src0Operand,block + 4,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src1Operand,block + 8,0);
    emitResult = 1;
    *(undefined4 *)(block + 0xc) = *(undefined4 *)(block + 8);
  }
  else {
    block = **(int **)(*(int *)(((unsigned char *)0x0000118c) + compiler) * 4 + *program);
    instrCount = *(int *)(block + 0x18);
    if (0x100 < instrCount + 2U) {
      *(undefined1 *)(program + 4) = 0;
      instrCount = *(int *)(block + 0x18);
      if (*(uint *)(block + 0x20) < instrCount + 2U) {
        emitResult = (**(code **)(compiler + 0xc))(*(uint *)(block + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + compiler))
                  (emitResult,*(undefined4 *)(block + 0x1c),*(int *)(block + 0x20) << 4);
        (**(code **)(compiler + 0x18))(*(undefined4 *)(block + 0x1c));
        *(undefined4 *)(block + 0x1c) = emitResult;
        instrCount = *(int *)(block + 0x18);
        *(int *)(block + 0x20) = *(int *)(block + 0x20) + 0x10;
      }
    }
    block = instrCount * 0x10 + *(int *)(block + 0x1c);
    emitResult = ((int (*)())extvsAllocTempSlot)(compiler,program);
    tempDstFile = 3;
    tempDstFlag = 0;
    tempDstMask3 = 1;
    tempDstMask0 = 1;
    tempDstMask1 = 1;
    tempDstMask2 = 1;
    tempDstIndex = emitResult;
    ((int (*)())extvsEncodeSourceOperand)(compiler,program,&tempDstFile,block,3,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src0Operand,block + 4,0);
    packedWord = *(uint *)(block + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(block + 0xc) = packedWord;
    *(uint *)(block + 8) = packedWord;
    ((int (*)())extvsEncodeSourceOperand)(compiler,program,irInstruction + 4,block + 0x10,1,0,0);
    tempSrcFile = 3;
    tempSrcFlag = 0;
    tempSrcSel0 = 0x87d5;
    tempSrcSel1 = 0x87d6;
    tempSrcSel2 = 0x87d7;
    tempSrcSel3 = 0x87d8;
    tempSrcIndex = emitResult;
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,&tempSrcFile,block + 0x14,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src1Operand,block + 0x18,0);
    emitResult = 2;
    *(undefined4 *)(block + 0x1c) = *(undefined4 *)(block + 0x18);
  }
  return emitResult;
}

/* extvsEmitMul @ 0x58b10 (824 bytes) */
int extvsEmitMul(compiler, program, irInstruction)
  int compiler;
  int *program;
  int irInstruction;
{
  uint packedWord;
  int block;
  undefined4 emitResult;
  int src1Operand;
  int src0Operand;
  int *operandState;
  int instrCount;
  undefined4 tempDstFile;
  undefined4 tempDstIndex;
  undefined4 tempDstMask0;
  undefined4 tempDstMask1;
  undefined4 tempDstMask2;
  undefined4 tempDstMask3;
  undefined1 tempDstFlag;
  undefined4 tempSrcFile;
  undefined4 tempSrcIndex;
  undefined4 tempSrcSel0;
  undefined4 tempSrcSel1;
  undefined4 tempSrcSel2;
  undefined4 tempSrcSel3;
  undefined1 tempSrcFlag;
  
  src0Operand = irInstruction + 0x20;
  operandState = program + 7;
  src1Operand = irInstruction + 0x3c;
  block = ((int (*)())extvsOperandsConflictInBank)(operandState,src0Operand,src1Operand);
  if (block == 0) {
    block = **(int **)(*(int *)(((unsigned char *)0x0000118c) + compiler) * 4 + *program);
    instrCount = *(int *)(block + 0x18);
    if (0x100 < instrCount + 1U) {
      *(undefined1 *)(program + 4) = 0;
      instrCount = *(int *)(block + 0x18);
      if (*(uint *)(block + 0x20) < instrCount + 1U) {
        emitResult = (**(code **)(compiler + 0xc))(*(uint *)(block + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + compiler))
                  (emitResult,*(undefined4 *)(block + 0x1c),*(int *)(block + 0x20) << 4);
        (**(code **)(compiler + 0x18))(*(undefined4 *)(block + 0x1c));
        *(undefined4 *)(block + 0x1c) = emitResult;
        instrCount = *(int *)(block + 0x18);
        *(int *)(block + 0x20) = *(int *)(block + 0x20) + 0x10;
      }
    }
    block = instrCount * 0x10 + *(int *)(block + 0x1c);
    ((int (*)())extvsEncodeSourceOperand)(compiler,program,irInstruction + 4,block,2,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src0Operand,block + 4,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src1Operand,block + 8,0);
    emitResult = 1;
    *(undefined4 *)(block + 0xc) = *(undefined4 *)(block + 8);
  }
  else {
    block = **(int **)(*(int *)(((unsigned char *)0x0000118c) + compiler) * 4 + *program);
    instrCount = *(int *)(block + 0x18);
    if (0x100 < instrCount + 2U) {
      *(undefined1 *)(program + 4) = 0;
      instrCount = *(int *)(block + 0x18);
      if (*(uint *)(block + 0x20) < instrCount + 2U) {
        emitResult = (**(code **)(compiler + 0xc))(*(uint *)(block + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + compiler))
                  (emitResult,*(undefined4 *)(block + 0x1c),*(int *)(block + 0x20) << 4);
        (**(code **)(compiler + 0x18))(*(undefined4 *)(block + 0x1c));
        *(undefined4 *)(block + 0x1c) = emitResult;
        instrCount = *(int *)(block + 0x18);
        *(int *)(block + 0x20) = *(int *)(block + 0x20) + 0x10;
      }
    }
    block = instrCount * 0x10 + *(int *)(block + 0x1c);
    emitResult = ((int (*)())extvsAllocTempSlot)(compiler,program);
    tempDstFile = 3;
    tempDstFlag = 0;
    tempDstMask3 = 1;
    tempDstMask0 = 1;
    tempDstMask1 = 1;
    tempDstMask2 = 1;
    tempDstIndex = emitResult;
    ((int (*)())extvsEncodeSourceOperand)(compiler,program,&tempDstFile,block,3,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src0Operand,block + 4,0);
    packedWord = *(uint *)(block + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(block + 0xc) = packedWord;
    *(uint *)(block + 8) = packedWord;
    ((int (*)())extvsEncodeSourceOperand)(compiler,program,irInstruction + 4,block + 0x10,2,0,0);
    tempSrcFile = 3;
    tempSrcFlag = 0;
    tempSrcSel0 = 0x87d5;
    tempSrcSel1 = 0x87d6;
    tempSrcSel2 = 0x87d7;
    tempSrcSel3 = 0x87d8;
    tempSrcIndex = emitResult;
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,&tempSrcFile,block + 0x14,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src1Operand,block + 0x18,0);
    emitResult = 2;
    *(undefined4 *)(block + 0x1c) = *(undefined4 *)(block + 0x18);
  }
  return emitResult;
}

/* extvsEmitAdd @ 0x58e50 (824 bytes) */
int extvsEmitAdd(compiler, program, irInstruction)
  int compiler;
  int *program;
  int irInstruction;
{
  uint packedWord;
  int block;
  undefined4 emitResult;
  int src1Operand;
  int src0Operand;
  int *operandState;
  int instrCount;
  undefined4 tempDstFile;
  undefined4 tempDstIndex;
  undefined4 tempDstMask0;
  undefined4 tempDstMask1;
  undefined4 tempDstMask2;
  undefined4 tempDstMask3;
  undefined1 tempDstFlag;
  undefined4 tempSrcFile;
  undefined4 tempSrcIndex;
  undefined4 tempSrcSel0;
  undefined4 tempSrcSel1;
  undefined4 tempSrcSel2;
  undefined4 tempSrcSel3;
  undefined1 tempSrcFlag;
  
  src0Operand = irInstruction + 0x20;
  operandState = program + 7;
  src1Operand = irInstruction + 0x3c;
  block = ((int (*)())extvsOperandsConflictInBank)(operandState,src0Operand,src1Operand);
  if (block == 0) {
    block = **(int **)(*(int *)(((unsigned char *)0x0000118c) + compiler) * 4 + *program);
    instrCount = *(int *)(block + 0x18);
    if (0x100 < instrCount + 1U) {
      *(undefined1 *)(program + 4) = 0;
      instrCount = *(int *)(block + 0x18);
      if (*(uint *)(block + 0x20) < instrCount + 1U) {
        emitResult = (**(code **)(compiler + 0xc))(*(uint *)(block + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + compiler))
                  (emitResult,*(undefined4 *)(block + 0x1c),*(int *)(block + 0x20) << 4);
        (**(code **)(compiler + 0x18))(*(undefined4 *)(block + 0x1c));
        *(undefined4 *)(block + 0x1c) = emitResult;
        instrCount = *(int *)(block + 0x18);
        *(int *)(block + 0x20) = *(int *)(block + 0x20) + 0x10;
      }
    }
    block = instrCount * 0x10 + *(int *)(block + 0x1c);
    ((int (*)())extvsEncodeSourceOperand)(compiler,program,irInstruction + 4,block,3,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src0Operand,block + 4,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src1Operand,block + 8,0);
    emitResult = 1;
    *(undefined4 *)(block + 0xc) = *(undefined4 *)(block + 8);
  }
  else {
    block = **(int **)(*(int *)(((unsigned char *)0x0000118c) + compiler) * 4 + *program);
    instrCount = *(int *)(block + 0x18);
    if (0x100 < instrCount + 2U) {
      *(undefined1 *)(program + 4) = 0;
      instrCount = *(int *)(block + 0x18);
      if (*(uint *)(block + 0x20) < instrCount + 2U) {
        emitResult = (**(code **)(compiler + 0xc))(*(uint *)(block + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + compiler))
                  (emitResult,*(undefined4 *)(block + 0x1c),*(int *)(block + 0x20) << 4);
        (**(code **)(compiler + 0x18))(*(undefined4 *)(block + 0x1c));
        *(undefined4 *)(block + 0x1c) = emitResult;
        instrCount = *(int *)(block + 0x18);
        *(int *)(block + 0x20) = *(int *)(block + 0x20) + 0x10;
      }
    }
    block = instrCount * 0x10 + *(int *)(block + 0x1c);
    emitResult = ((int (*)())extvsAllocTempSlot)(compiler,program);
    tempDstFile = 3;
    tempDstFlag = 0;
    tempDstMask3 = 1;
    tempDstMask0 = 1;
    tempDstMask1 = 1;
    tempDstMask2 = 1;
    tempDstIndex = emitResult;
    ((int (*)())extvsEncodeSourceOperand)(compiler,program,&tempDstFile,block,3,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src0Operand,block + 4,0);
    packedWord = *(uint *)(block + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(block + 0xc) = packedWord;
    *(uint *)(block + 8) = packedWord;
    ((int (*)())extvsEncodeSourceOperand)(compiler,program,irInstruction + 4,block + 0x10,3,0,0);
    tempSrcFile = 3;
    tempSrcFlag = 0;
    tempSrcSel0 = 0x87d5;
    tempSrcSel1 = 0x87d6;
    tempSrcSel2 = 0x87d7;
    tempSrcSel3 = 0x87d8;
    tempSrcIndex = emitResult;
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,&tempSrcFile,block + 0x14,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src1Operand,block + 0x18,0);
    emitResult = 2;
    *(undefined4 *)(block + 0x1c) = *(undefined4 *)(block + 0x18);
  }
  return emitResult;
}

/* extvsEmitMad @ 0x59190 (2512 bytes) */
int extvsEmitMad(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  int hwProgram;
  undefined4 slotsEmitted;
  undefined4 tempIndex;
  uint swizzleWord;
  int conflict;
  undefined4 newInstArray;
  int src2Operand;
  undefined4 *src1Operand;
  int src0Operand;
  int instCount;
  int *symbolList;
  undefined4 tmpOperandAKind;
  undefined4 tmpOperandAIndex;
  undefined4 tmpOperandAComp0;
  undefined4 tmpOperandAComp1;
  undefined4 tmpOperandAComp2;
  undefined4 tmpOperandAComp3;
  undefined1 tmpOperandAFlag;
  undefined4 tmpOperandBKind;
  undefined4 tmpOperandBIndex;
  undefined4 tmpOperandBComp0;
  undefined4 tmpOperandBComp1;
  undefined4 tmpOperandBComp2;
  undefined4 tmpOperandBComp3;
  undefined1 tmpOperandBFlag;
  undefined4 tmpOperandCKind;
  undefined4 tmpOperandCIndex;
  undefined4 tmpOperandCComp0;
  undefined4 tmpOperandCComp1;
  undefined4 tmpOperandCComp2;
  undefined4 tmpOperandCComp3;
  undefined1 tmpOperandCFlag;
  undefined4 tmpOperandDKind;
  undefined4 tmpOperandDIndex;
  undefined4 tmpOperandDComp0;
  undefined4 tmpOperandDComp1;
  undefined4 tmpOperandDComp2;
  undefined4 tmpOperandDComp3;
  undefined1 tmpOperandDFlag;
  
  symbolList = shader + 7;
  src0Operand = instRecord + 0x20;
  src1Operand = (undefined4 *)(instRecord + 0x3c);
  conflict = ((int (*)())extvsOperandsConflictInBank)(symbolList,src0Operand,src1Operand);
  if (conflict == 0) {
    src2Operand = instRecord + 0x58;
    conflict = ((int (*)())extvsOperandsConflictInBank)(symbolList,src0Operand,src2Operand);
    if ((conflict == 0) && (conflict = ((int (*)())extvsOperandsConflictInBank)(symbolList,src1Operand,src2Operand), conflict == 0)) {
      hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
      instCount = *(int *)(hwProgram + 0x18);
      if (0x100 < instCount + 1U) {
        *(undefined1 *)(shader + 4) = 0;
        instCount = *(int *)(hwProgram + 0x18);
        if (*(uint *)(hwProgram + 0x20) < instCount + 1U) {
          newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
          (**(code **)(((unsigned char *)0x00001344) + ctx))
                    (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
          *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
          instCount = *(int *)(hwProgram + 0x18);
          *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
        }
      }
      instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
      ((int (*)())extvsEncodeSourceOperand)(ctx,shader,instRecord + 4,instSlot,4,0,0);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src0Operand,instSlot + 4,0);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src1Operand,instSlot + 8,0);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src2Operand,instSlot + 0xc,0);
      slotsEmitted = 1;
    }
    else {
      hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
      instCount = *(int *)(hwProgram + 0x18);
      if (0x100 < instCount + 2U) {
        *(undefined1 *)(shader + 4) = 0;
        instCount = *(int *)(hwProgram + 0x18);
        if (*(uint *)(hwProgram + 0x20) < instCount + 2U) {
          newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
          (**(code **)(((unsigned char *)0x00001344) + ctx))
                    (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
          *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
          instCount = *(int *)(hwProgram + 0x18);
          *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
        }
      }
      instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
      tempIndex = ((int (*)())extvsAllocTempSlot)(ctx,shader);
      tmpOperandCKind = 3;
      tmpOperandCFlag = 0;
      tmpOperandCComp3 = 1;
      tmpOperandCComp0 = 1;
      tmpOperandCComp1 = 1;
      tmpOperandCComp2 = 1;
      tmpOperandCIndex = tempIndex;
      ((int (*)())extvsEncodeSourceOperand)(ctx,shader,&tmpOperandCKind,instSlot,2,0,0);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src0Operand,instSlot + 4,0);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src1Operand,instSlot + 8,0);
      *(undefined4 *)(instSlot + 0xc) = *(undefined4 *)(instSlot + 8);
      ((int (*)())extvsEncodeSourceOperand)(ctx,shader,instRecord + 4,instSlot + 0x10,3,0,0);
      tmpOperandDKind = 3;
      tmpOperandDFlag = 0;
      tmpOperandDComp0 = 0x87d5;
      tmpOperandDComp1 = 0x87d6;
      tmpOperandDComp2 = 0x87d7;
      tmpOperandDComp3 = 0x87d8;
      tmpOperandDIndex = tempIndex;
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,&tmpOperandDKind,instSlot + 0x14,0);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src2Operand,instSlot + 0x18,0);
      slotsEmitted = 2;
      *(undefined4 *)(instSlot + 0x1c) = *(undefined4 *)(instSlot + 0x18);
    }
  }
  else {
    src2Operand = instRecord + 0x58;
    conflict = ((int (*)())extvsOperandsConflictInBank)(symbolList,src0Operand,src2Operand);
    if ((conflict == 0) || (conflict = ((int (*)())extvsOperandsConflictInBank)(symbolList,src1Operand,src2Operand), conflict == 0)) {
      conflict = ((int (*)())extvsOperandsConflictInBank)(symbolList,src1Operand,src2Operand);
      if (conflict == 0) {
        hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
        instCount = *(int *)(hwProgram + 0x18);
        if (0x100 < instCount + 2U) {
          *(undefined1 *)(shader + 4) = 0;
          instCount = *(int *)(hwProgram + 0x18);
          if (*(uint *)(hwProgram + 0x20) < instCount + 2U) {
            newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
            (**(code **)(((unsigned char *)0x00001344) + ctx))
                      (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
            *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
            instCount = *(int *)(hwProgram + 0x18);
            *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
          }
        }
        instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
        tempIndex = ((int (*)())extvsAllocTempSlot)(ctx,shader);
        tmpOperandDKind = 3;
        tmpOperandDFlag = 0;
        tmpOperandDComp3 = 1;
        tmpOperandDComp0 = 1;
        tmpOperandDComp1 = 1;
        tmpOperandDComp2 = 1;
        tmpOperandDIndex = tempIndex;
        ((int (*)())extvsEncodeSourceOperand)(ctx,shader,&tmpOperandDKind,instSlot,3,0,0);
        ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src0Operand,instSlot + 4,0);
        swizzleWord = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
        *(uint *)(instSlot + 0xc) = swizzleWord;
        *(uint *)(instSlot + 8) = swizzleWord;
        ((int (*)())extvsEncodeSourceOperand)(ctx,shader,instRecord + 4,instSlot + 0x10,4,0,0);
        tmpOperandCKind = 3;
        tmpOperandCFlag = 0;
        tmpOperandCComp0 = 0x87d5;
        tmpOperandCComp1 = 0x87d6;
        tmpOperandCComp2 = 0x87d7;
        tmpOperandCComp3 = 0x87d8;
        tmpOperandCIndex = tempIndex;
        ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,&tmpOperandCKind,instSlot + 0x14,0);
      }
      else {
        hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
        instCount = *(int *)(hwProgram + 0x18);
        if (0x100 < instCount + 2U) {
          *(undefined1 *)(shader + 4) = 0;
          instCount = *(int *)(hwProgram + 0x18);
          if (*(uint *)(hwProgram + 0x20) < instCount + 2U) {
            newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
            (**(code **)(((unsigned char *)0x00001344) + ctx))
                      (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
            *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
            instCount = *(int *)(hwProgram + 0x18);
            *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
          }
        }
        instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
        tempIndex = ((int (*)())extvsAllocTempSlot)(ctx,shader);
        tmpOperandAKind = 3;
        tmpOperandAFlag = 0;
        tmpOperandAComp3 = 1;
        tmpOperandAComp0 = 1;
        tmpOperandAComp1 = 1;
        tmpOperandAComp2 = 1;
        tmpOperandAIndex = tempIndex;
        ((int (*)())extvsEncodeSourceOperand)(ctx,shader,&tmpOperandAKind,instSlot,3,0,0);
        ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src1Operand,instSlot + 4,0);
        swizzleWord = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
        *(uint *)(instSlot + 0xc) = swizzleWord;
        *(uint *)(instSlot + 8) = swizzleWord;
        ((int (*)())extvsEncodeSourceOperand)(ctx,shader,instRecord + 4,instSlot + 0x10,4,0,0);
        ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src0Operand,instSlot + 0x14,0);
        tmpOperandBKind = 3;
        tmpOperandBFlag = 0;
        tmpOperandBComp0 = 0x87d5;
        tmpOperandBComp1 = 0x87d6;
        tmpOperandBComp2 = 0x87d7;
        tmpOperandBComp3 = 0x87d8;
        src1Operand = &tmpOperandBKind;
        tmpOperandBIndex = tempIndex;
      }
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src1Operand,instSlot + 0x18,0);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src2Operand,instSlot + 0x1c,0);
      slotsEmitted = 2;
    }
    else {
      hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
      instCount = *(int *)(hwProgram + 0x18);
      if (0x100 < instCount + 3U) {
        *(undefined1 *)(shader + 4) = 0;
        instCount = *(int *)(hwProgram + 0x18);
        if (*(uint *)(hwProgram + 0x20) < instCount + 3U) {
          newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
          (**(code **)(((unsigned char *)0x00001344) + ctx))
                    (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
          *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
          instCount = *(int *)(hwProgram + 0x18);
          *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
        }
      }
      instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
      tempIndex = ((int (*)())extvsAllocTempSlot)(ctx,shader);
      tmpOperandAKind = 3;
      tmpOperandAFlag = 0;
      tmpOperandAComp3 = 1;
      tmpOperandAComp0 = 1;
      tmpOperandAComp1 = 1;
      tmpOperandAComp2 = 1;
      tmpOperandAIndex = tempIndex;
      ((int (*)())extvsEncodeSourceOperand)(ctx,shader,&tmpOperandAKind,instSlot,3,0,0);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src0Operand,instSlot + 4,0);
      swizzleWord = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
      *(uint *)(instSlot + 0xc) = swizzleWord;
      *(uint *)(instSlot + 8) = swizzleWord;
      ((int (*)())extvsEncodeSourceOperand)(ctx,shader,&tmpOperandAKind,instSlot + 0x10,2,0,0);
      tmpOperandBKind = 3;
      tmpOperandBFlag = 0;
      tmpOperandBComp1 = 0x87d6;
      tmpOperandBComp0 = 0x87d5;
      tmpOperandBComp2 = 0x87d7;
      tmpOperandBComp3 = 0x87d8;
      tmpOperandBIndex = tempIndex;
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,&tmpOperandBKind,instSlot + 0x14,0);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src1Operand,instSlot + 0x18,0);
      *(undefined4 *)(instSlot + 0x1c) = *(undefined4 *)(instSlot + 0x18);
      ((int (*)())extvsEncodeSourceOperand)(ctx,shader,instRecord + 4,instSlot + 0x20,3,0,0);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,&tmpOperandBKind,instSlot + 0x24,0);
      ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src2Operand,instSlot + 0x28,0);
      slotsEmitted = 3;
      *(undefined4 *)(instSlot + 0x2c) = *(undefined4 *)(instSlot + 0x28);
    }
  }
  return slotsEmitted;
}

/* extvsEmitFrc @ 0x59b80 (304 bytes) */
int extvsEmitFrc(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  undefined4 newInstArray;
  int instCount;
  int hwProgram;
  
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  instCount = *(int *)(hwProgram + 0x18);
  if (0x100 < instCount + 1U) {
    *(undefined1 *)(shader + 4) = 0;
    instCount = *(int *)(hwProgram + 0x18);
    if (*(uint *)(hwProgram + 0x20) < instCount + 1U) {
      newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
      *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
      instCount = *(int *)(hwProgram + 0x18);
      *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
    }
  }
  instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
  ((int (*)())extvsEncodeSourceOperand)(ctx,shader,instRecord + 4,instSlot,6,0,0);
  ((int (*)())extvsEncodeSourceSwizzle)(shader,shader + 7,instRecord + 0x20,instSlot + 4,0);
  *(undefined4 *)(instSlot + 0xc) = *(undefined4 *)(instSlot + 4);
  *(undefined4 *)(instSlot + 8) = *(undefined4 *)(instSlot + 4);
  return 1;
}

/* extvsEmitMax @ 0x59cb0 (824 bytes) */
int extvsEmitMax(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  int hwProgram;
  uint uVar1;
  int conflict;
  undefined4 uVar3;
  int src1Operand;
  int src0Operand;
  int *symbolList;
  int instCount;
  undefined4 tmpOperand0Kind;
  undefined4 tmpOperand0Index;
  undefined4 tmpOperand0Comp0;
  undefined4 tmpOperand0Comp1;
  undefined4 tmpOperand0Comp2;
  undefined4 tmpOperand0Comp3;
  undefined1 tmpOperand0Flag;
  undefined4 tmpOperand1Kind;
  undefined4 tmpOperand1Index;
  undefined4 tmpOperand1Comp0;
  undefined4 tmpOperand1Comp1;
  undefined4 tmpOperand1Comp2;
  undefined4 tmpOperand1Comp3;
  undefined1 tmpOperand1Flag;
  
  src0Operand = instRecord + 0x20;
  symbolList = shader + 7;
  src1Operand = instRecord + 0x3c;
  conflict = ((int (*)())extvsOperandsConflictInBank)(symbolList,src0Operand,src1Operand);
  if (conflict == 0) {
    hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(hwProgram + 0x18);
    if (0x100 < instCount + 1U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(hwProgram + 0x18);
      if (*(uint *)(hwProgram + 0x20) < instCount + 1U) {
        uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar3,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
        *(undefined4 *)(hwProgram + 0x1c) = uVar3;
        instCount = *(int *)(hwProgram + 0x18);
        *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
      }
    }
    instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
    ((int (*)())extvsEncodeSourceOperand)(ctx,shader,instRecord + 4,instSlot,7,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src0Operand,instSlot + 4,0);
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src1Operand,instSlot + 8,0);
    uVar3 = 1;
    *(undefined4 *)(instSlot + 0xc) = *(undefined4 *)(instSlot + 8);
  }
  else {
    hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(hwProgram + 0x18);
    if (0x100 < instCount + 2U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(hwProgram + 0x18);
      if (*(uint *)(hwProgram + 0x20) < instCount + 2U) {
        uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar3,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
        *(undefined4 *)(hwProgram + 0x1c) = uVar3;
        instCount = *(int *)(hwProgram + 0x18);
        *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
      }
    }
    instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
    uVar3 = ((int (*)())extvsAllocTempSlot)(ctx,shader);
    tmpOperand0Kind = 3;
    tmpOperand0Flag = 0;
    tmpOperand0Comp3 = 1;
    tmpOperand0Comp0 = 1;
    tmpOperand0Comp1 = 1;
    tmpOperand0Comp2 = 1;
    tmpOperand0Index = uVar3;
    ((int (*)())extvsEncodeSourceOperand)(ctx,shader,&tmpOperand0Kind,instSlot,3,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src0Operand,instSlot + 4,0);
    uVar1 = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(instSlot + 0xc) = uVar1;
    *(uint *)(instSlot + 8) = uVar1;
    ((int (*)())extvsEncodeSourceOperand)(ctx,shader,instRecord + 4,instSlot + 0x10,7,0,0);
    tmpOperand1Kind = 3;
    tmpOperand1Flag = 0;
    tmpOperand1Comp0 = 0x87d5;
    tmpOperand1Comp1 = 0x87d6;
    tmpOperand1Comp2 = 0x87d7;
    tmpOperand1Comp3 = 0x87d8;
    tmpOperand1Index = uVar3;
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,&tmpOperand1Kind,instSlot + 0x14,0);
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src1Operand,instSlot + 0x18,0);
    uVar3 = 2;
    *(undefined4 *)(instSlot + 0x1c) = *(undefined4 *)(instSlot + 0x18);
  }
  return uVar3;
}

/* extvsEmitMin @ 0x59ff0 (824 bytes) */
int extvsEmitMin(compiler, program, irInstruction)
  int compiler;
  int *program;
  int irInstruction;
{
  uint packedWord;
  int block;
  undefined4 emitResult;
  int src1Operand;
  int src0Operand;
  int *operandState;
  int instrCount;
  undefined4 tempDstFile;
  undefined4 tempDstIndex;
  undefined4 tempDstMask0;
  undefined4 tempDstMask1;
  undefined4 tempDstMask2;
  undefined4 tempDstMask3;
  undefined1 tempDstFlag;
  undefined4 tempSrcFile;
  undefined4 tempSrcIndex;
  undefined4 tempSrcSel0;
  undefined4 tempSrcSel1;
  undefined4 tempSrcSel2;
  undefined4 tempSrcSel3;
  undefined1 tempSrcFlag;
  
  src0Operand = irInstruction + 0x20;
  operandState = program + 7;
  src1Operand = irInstruction + 0x3c;
  block = ((int (*)())extvsOperandsConflictInBank)(operandState,src0Operand,src1Operand);
  if (block == 0) {
    block = **(int **)(*(int *)(((unsigned char *)0x0000118c) + compiler) * 4 + *program);
    instrCount = *(int *)(block + 0x18);
    if (0x100 < instrCount + 1U) {
      *(undefined1 *)(program + 4) = 0;
      instrCount = *(int *)(block + 0x18);
      if (*(uint *)(block + 0x20) < instrCount + 1U) {
        emitResult = (**(code **)(compiler + 0xc))(*(uint *)(block + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + compiler))
                  (emitResult,*(undefined4 *)(block + 0x1c),*(int *)(block + 0x20) << 4);
        (**(code **)(compiler + 0x18))(*(undefined4 *)(block + 0x1c));
        *(undefined4 *)(block + 0x1c) = emitResult;
        instrCount = *(int *)(block + 0x18);
        *(int *)(block + 0x20) = *(int *)(block + 0x20) + 0x10;
      }
    }
    block = instrCount * 0x10 + *(int *)(block + 0x1c);
    ((int (*)())extvsEncodeSourceOperand)(compiler,program,irInstruction + 4,block,8,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src0Operand,block + 4,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src1Operand,block + 8,0);
    emitResult = 1;
    *(undefined4 *)(block + 0xc) = *(undefined4 *)(block + 8);
  }
  else {
    block = **(int **)(*(int *)(((unsigned char *)0x0000118c) + compiler) * 4 + *program);
    instrCount = *(int *)(block + 0x18);
    if (0x100 < instrCount + 2U) {
      *(undefined1 *)(program + 4) = 0;
      instrCount = *(int *)(block + 0x18);
      if (*(uint *)(block + 0x20) < instrCount + 2U) {
        emitResult = (**(code **)(compiler + 0xc))(*(uint *)(block + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + compiler))
                  (emitResult,*(undefined4 *)(block + 0x1c),*(int *)(block + 0x20) << 4);
        (**(code **)(compiler + 0x18))(*(undefined4 *)(block + 0x1c));
        *(undefined4 *)(block + 0x1c) = emitResult;
        instrCount = *(int *)(block + 0x18);
        *(int *)(block + 0x20) = *(int *)(block + 0x20) + 0x10;
      }
    }
    block = instrCount * 0x10 + *(int *)(block + 0x1c);
    emitResult = ((int (*)())extvsAllocTempSlot)(compiler,program);
    tempDstFile = 3;
    tempDstFlag = 0;
    tempDstMask3 = 1;
    tempDstMask0 = 1;
    tempDstMask1 = 1;
    tempDstMask2 = 1;
    tempDstIndex = emitResult;
    ((int (*)())extvsEncodeSourceOperand)(compiler,program,&tempDstFile,block,3,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src0Operand,block + 4,0);
    packedWord = *(uint *)(block + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(block + 0xc) = packedWord;
    *(uint *)(block + 8) = packedWord;
    ((int (*)())extvsEncodeSourceOperand)(compiler,program,irInstruction + 4,block + 0x10,8,0,0);
    tempSrcFile = 3;
    tempSrcFlag = 0;
    tempSrcSel0 = 0x87d5;
    tempSrcSel1 = 0x87d6;
    tempSrcSel2 = 0x87d7;
    tempSrcSel3 = 0x87d8;
    tempSrcIndex = emitResult;
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,&tempSrcFile,block + 0x14,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src1Operand,block + 0x18,0);
    emitResult = 2;
    *(undefined4 *)(block + 0x1c) = *(undefined4 *)(block + 0x18);
  }
  return emitResult;
}

/* extvsEmitSetGreaterEqual @ 0x5a330 (824 bytes) */
int extvsEmitSetGreaterEqual(compiler, program, irInstruction)
  int compiler;
  int *program;
  int irInstruction;
{
  uint packedWord;
  int block;
  undefined4 emitResult;
  int src1Operand;
  int src0Operand;
  int *operandState;
  int instrCount;
  undefined4 tempDstFile;
  undefined4 tempDstIndex;
  undefined4 tempDstMask0;
  undefined4 tempDstMask1;
  undefined4 tempDstMask2;
  undefined4 tempDstMask3;
  undefined1 tempDstFlag;
  undefined4 tempSrcFile;
  undefined4 tempSrcIndex;
  undefined4 tempSrcSel0;
  undefined4 tempSrcSel1;
  undefined4 tempSrcSel2;
  undefined4 tempSrcSel3;
  undefined1 tempSrcFlag;
  
  src0Operand = irInstruction + 0x20;
  operandState = program + 7;
  src1Operand = irInstruction + 0x3c;
  block = ((int (*)())extvsOperandsConflictInBank)(operandState,src0Operand,src1Operand);
  if (block == 0) {
    block = **(int **)(*(int *)(((unsigned char *)0x0000118c) + compiler) * 4 + *program);
    instrCount = *(int *)(block + 0x18);
    if (0x100 < instrCount + 1U) {
      *(undefined1 *)(program + 4) = 0;
      instrCount = *(int *)(block + 0x18);
      if (*(uint *)(block + 0x20) < instrCount + 1U) {
        emitResult = (**(code **)(compiler + 0xc))(*(uint *)(block + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + compiler))
                  (emitResult,*(undefined4 *)(block + 0x1c),*(int *)(block + 0x20) << 4);
        (**(code **)(compiler + 0x18))(*(undefined4 *)(block + 0x1c));
        *(undefined4 *)(block + 0x1c) = emitResult;
        instrCount = *(int *)(block + 0x18);
        *(int *)(block + 0x20) = *(int *)(block + 0x20) + 0x10;
      }
    }
    block = instrCount * 0x10 + *(int *)(block + 0x1c);
    ((int (*)())extvsEncodeSourceOperand)(compiler,program,irInstruction + 4,block,9,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src0Operand,block + 4,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src1Operand,block + 8,0);
    emitResult = 1;
    *(undefined4 *)(block + 0xc) = *(undefined4 *)(block + 8);
  }
  else {
    block = **(int **)(*(int *)(((unsigned char *)0x0000118c) + compiler) * 4 + *program);
    instrCount = *(int *)(block + 0x18);
    if (0x100 < instrCount + 2U) {
      *(undefined1 *)(program + 4) = 0;
      instrCount = *(int *)(block + 0x18);
      if (*(uint *)(block + 0x20) < instrCount + 2U) {
        emitResult = (**(code **)(compiler + 0xc))(*(uint *)(block + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + compiler))
                  (emitResult,*(undefined4 *)(block + 0x1c),*(int *)(block + 0x20) << 4);
        (**(code **)(compiler + 0x18))(*(undefined4 *)(block + 0x1c));
        *(undefined4 *)(block + 0x1c) = emitResult;
        instrCount = *(int *)(block + 0x18);
        *(int *)(block + 0x20) = *(int *)(block + 0x20) + 0x10;
      }
    }
    block = instrCount * 0x10 + *(int *)(block + 0x1c);
    emitResult = ((int (*)())extvsAllocTempSlot)(compiler,program);
    tempDstFile = 3;
    tempDstFlag = 0;
    tempDstMask3 = 1;
    tempDstMask0 = 1;
    tempDstMask1 = 1;
    tempDstMask2 = 1;
    tempDstIndex = emitResult;
    ((int (*)())extvsEncodeSourceOperand)(compiler,program,&tempDstFile,block,3,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src0Operand,block + 4,0);
    packedWord = *(uint *)(block + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(block + 0xc) = packedWord;
    *(uint *)(block + 8) = packedWord;
    ((int (*)())extvsEncodeSourceOperand)(compiler,program,irInstruction + 4,block + 0x10,9,0,0);
    tempSrcFile = 3;
    tempSrcFlag = 0;
    tempSrcSel0 = 0x87d5;
    tempSrcSel1 = 0x87d6;
    tempSrcSel2 = 0x87d7;
    tempSrcSel3 = 0x87d8;
    tempSrcIndex = emitResult;
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,&tempSrcFile,block + 0x14,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src1Operand,block + 0x18,0);
    emitResult = 2;
    *(undefined4 *)(block + 0x1c) = *(undefined4 *)(block + 0x18);
  }
  return emitResult;
}

/* extvsEmitSetLessThan @ 0x5a670 (824 bytes) */
int extvsEmitSetLessThan(compiler, program, irInstruction)
  int compiler;
  int *program;
  int irInstruction;
{
  uint packedWord;
  int block;
  undefined4 emitResult;
  int src1Operand;
  int src0Operand;
  int *operandState;
  int instrCount;
  undefined4 tempDstFile;
  undefined4 tempDstIndex;
  undefined4 tempDstMask0;
  undefined4 tempDstMask1;
  undefined4 tempDstMask2;
  undefined4 tempDstMask3;
  undefined1 tempDstFlag;
  undefined4 tempSrcFile;
  undefined4 tempSrcIndex;
  undefined4 tempSrcSel0;
  undefined4 tempSrcSel1;
  undefined4 tempSrcSel2;
  undefined4 tempSrcSel3;
  undefined1 tempSrcFlag;
  
  src0Operand = irInstruction + 0x20;
  operandState = program + 7;
  src1Operand = irInstruction + 0x3c;
  block = ((int (*)())extvsOperandsConflictInBank)(operandState,src0Operand,src1Operand);
  if (block == 0) {
    block = **(int **)(*(int *)(((unsigned char *)0x0000118c) + compiler) * 4 + *program);
    instrCount = *(int *)(block + 0x18);
    if (0x100 < instrCount + 1U) {
      *(undefined1 *)(program + 4) = 0;
      instrCount = *(int *)(block + 0x18);
      if (*(uint *)(block + 0x20) < instrCount + 1U) {
        emitResult = (**(code **)(compiler + 0xc))(*(uint *)(block + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + compiler))
                  (emitResult,*(undefined4 *)(block + 0x1c),*(int *)(block + 0x20) << 4);
        (**(code **)(compiler + 0x18))(*(undefined4 *)(block + 0x1c));
        *(undefined4 *)(block + 0x1c) = emitResult;
        instrCount = *(int *)(block + 0x18);
        *(int *)(block + 0x20) = *(int *)(block + 0x20) + 0x10;
      }
    }
    block = instrCount * 0x10 + *(int *)(block + 0x1c);
    ((int (*)())extvsEncodeSourceOperand)(compiler,program,irInstruction + 4,block,10,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src0Operand,block + 4,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src1Operand,block + 8,0);
    emitResult = 1;
    *(undefined4 *)(block + 0xc) = *(undefined4 *)(block + 8);
  }
  else {
    block = **(int **)(*(int *)(((unsigned char *)0x0000118c) + compiler) * 4 + *program);
    instrCount = *(int *)(block + 0x18);
    if (0x100 < instrCount + 2U) {
      *(undefined1 *)(program + 4) = 0;
      instrCount = *(int *)(block + 0x18);
      if (*(uint *)(block + 0x20) < instrCount + 2U) {
        emitResult = (**(code **)(compiler + 0xc))(*(uint *)(block + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + compiler))
                  (emitResult,*(undefined4 *)(block + 0x1c),*(int *)(block + 0x20) << 4);
        (**(code **)(compiler + 0x18))(*(undefined4 *)(block + 0x1c));
        *(undefined4 *)(block + 0x1c) = emitResult;
        instrCount = *(int *)(block + 0x18);
        *(int *)(block + 0x20) = *(int *)(block + 0x20) + 0x10;
      }
    }
    block = instrCount * 0x10 + *(int *)(block + 0x1c);
    emitResult = ((int (*)())extvsAllocTempSlot)(compiler,program);
    tempDstFile = 3;
    tempDstFlag = 0;
    tempDstMask3 = 1;
    tempDstMask0 = 1;
    tempDstMask1 = 1;
    tempDstMask2 = 1;
    tempDstIndex = emitResult;
    ((int (*)())extvsEncodeSourceOperand)(compiler,program,&tempDstFile,block,3,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src0Operand,block + 4,0);
    packedWord = *(uint *)(block + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(block + 0xc) = packedWord;
    *(uint *)(block + 8) = packedWord;
    ((int (*)())extvsEncodeSourceOperand)(compiler,program,irInstruction + 4,block + 0x10,10,0,0);
    tempSrcFile = 3;
    tempSrcFlag = 0;
    tempSrcSel0 = 0x87d5;
    tempSrcSel1 = 0x87d6;
    tempSrcSel2 = 0x87d7;
    tempSrcSel3 = 0x87d8;
    tempSrcIndex = emitResult;
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,&tempSrcFile,block + 0x14,0);
    ((int (*)())extvsEncodeSourceSwizzle)(program,operandState,src1Operand,block + 0x18,0);
    emitResult = 2;
    *(undefined4 *)(block + 0x1c) = *(undefined4 *)(block + 0x18);
  }
  return emitResult;
}

/* extvsEmitClamp @ 0x5a9b0 (1112 bytes) */
int extvsEmitClamp(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  int hwProgram;
  uint uVar1;
  undefined4 uVar2;
  int conflict;
  int src1Operand;
  int src0Operand;
  int *symbolList;
  int instCount;
  undefined4 tmpOperand0Kind;
  undefined4 tmpOperand0Index;
  undefined4 tmpOperand0Comp0;
  undefined4 tmpOperand0Comp1;
  undefined4 tmpOperand0Comp2;
  undefined4 tmpOperand0Comp3;
  undefined1 tmpOperand0Flag;
  undefined4 tmpOperand1Kind;
  undefined4 tmpOperand1Index;
  undefined4 tmpOperand1Comp0;
  undefined4 tmpOperand1Comp1;
  undefined4 tmpOperand1Comp2;
  undefined4 tmpOperand1Comp3;
  undefined1 tmpOperand1Flag;
  
  src0Operand = instRecord + 0x20;
  symbolList = shader + 7;
  src1Operand = instRecord + 0x3c;
  uVar2 = ((int (*)())extvsAllocTempSlot)(ctx,shader);
  conflict = ((int (*)())extvsOperandsConflictInBank)(symbolList,src0Operand,src1Operand);
  tmpOperand0Index = uVar2;
  tmpOperand1Index = uVar2;
  if (conflict == 0) {
    hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(hwProgram + 0x18);
    if (0x100 < instCount + 2U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(hwProgram + 0x18);
      if (*(uint *)(hwProgram + 0x20) < instCount + 2U) {
        uVar2 = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar2,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
        *(undefined4 *)(hwProgram + 0x1c) = uVar2;
        instCount = *(int *)(hwProgram + 0x18);
        *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
      }
    }
    tmpOperand0Comp3 = 1;
    tmpOperand0Comp0 = 1;
    tmpOperand0Comp1 = 1;
    tmpOperand0Comp2 = 1;
    tmpOperand0Kind = 3;
    instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
    tmpOperand0Flag = 0;
    ((int (*)())extvsEncodeSourceOperand)(ctx,shader,&tmpOperand0Kind,instSlot,7,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src0Operand,instSlot + 4,0);
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src1Operand,instSlot + 8,0);
    *(undefined4 *)(instSlot + 0xc) = *(undefined4 *)(instSlot + 8);
    ((int (*)())extvsEncodeSourceOperand)(ctx,shader,instRecord + 4,instSlot + 0x10,8,0,0);
    tmpOperand1Kind = 3;
    tmpOperand1Flag = 0;
    tmpOperand1Comp0 = 0x87d5;
    tmpOperand1Comp1 = 0x87d6;
    tmpOperand1Comp2 = 0x87d7;
    tmpOperand1Comp3 = 0x87d8;
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,&tmpOperand1Kind,instSlot + 0x14,0);
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,instRecord + 0x58,instSlot + 0x18,0);
    uVar2 = 2;
    *(undefined4 *)(instSlot + 0x1c) = *(undefined4 *)(instSlot + 0x18);
  }
  else {
    hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(hwProgram + 0x18);
    if (0x100 < instCount + 3U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(hwProgram + 0x18);
      if (*(uint *)(hwProgram + 0x20) < instCount + 3U) {
        uVar2 = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar2,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
        *(undefined4 *)(hwProgram + 0x1c) = uVar2;
        instCount = *(int *)(hwProgram + 0x18);
        *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
      }
    }
    tmpOperand0Comp3 = 1;
    tmpOperand0Comp0 = 1;
    tmpOperand0Comp1 = 1;
    tmpOperand0Comp2 = 1;
    tmpOperand0Kind = 3;
    instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
    tmpOperand0Flag = 0;
    ((int (*)())extvsEncodeSourceOperand)(ctx,shader,&tmpOperand0Kind,instSlot,3,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src0Operand,instSlot + 4,0);
    uVar1 = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(instSlot + 0xc) = uVar1;
    *(uint *)(instSlot + 8) = uVar1;
    ((int (*)())extvsEncodeSourceOperand)(ctx,shader,&tmpOperand0Kind,instSlot + 0x10,7,0,0);
    tmpOperand1Kind = 3;
    tmpOperand1Flag = 0;
    tmpOperand1Comp1 = 0x87d6;
    tmpOperand1Comp0 = 0x87d5;
    tmpOperand1Comp2 = 0x87d7;
    tmpOperand1Comp3 = 0x87d8;
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,&tmpOperand1Kind,instSlot + 0x14,0);
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src1Operand,instSlot + 0x18,0);
    *(undefined4 *)(instSlot + 0x1c) = *(undefined4 *)(instSlot + 0x18);
    ((int (*)())extvsEncodeSourceOperand)(ctx,shader,instRecord + 4,instSlot + 0x20,8,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,&tmpOperand1Kind,instSlot + 0x24,0);
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,instRecord + 0x58,instSlot + 0x28,0);
    uVar2 = 3;
    *(undefined4 *)(instSlot + 0x2c) = *(undefined4 *)(instSlot + 0x28);
  }
  return uVar2;
}

/* extvsEmitFlr @ 0x5ae10 (512 bytes) */
int extvsEmitFlr(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  undefined4 tempIndex;
  undefined4 newInstArray;
  int *symbolList;
  int hwProgram;
  int instCount;
  undefined4 tmpOperand0Kind;
  undefined4 tmpOperand0Index;
  undefined4 tmpOperand0Comp0;
  undefined4 tmpOperand0Comp1;
  undefined4 tmpOperand0Comp2;
  undefined4 tmpOperand0Comp3;
  undefined1 tmpOperand0Flag;
  undefined4 tmpOperand1Kind;
  undefined4 tmpOperand1Index;
  undefined4 tmpOperand1Comp0;
  undefined4 tmpOperand1Comp1;
  undefined4 tmpOperand1Comp2;
  undefined4 tmpOperand1Comp3;
  undefined1 tmpOperand1Flag;
  
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  instCount = *(int *)(hwProgram + 0x18);
  if (0x100 < instCount + 2U) {
    *(undefined1 *)(shader + 4) = 0;
    instCount = *(int *)(hwProgram + 0x18);
    if (*(uint *)(hwProgram + 0x20) < instCount + 2U) {
      newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
      *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
      instCount = *(int *)(hwProgram + 0x18);
      *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
    }
  }
  symbolList = shader + 7;
  instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
  tempIndex = ((int (*)())extvsAllocTempSlot)(ctx,shader);
  tmpOperand0Kind = 3;
  tmpOperand0Flag = 0;
  tmpOperand0Comp3 = 1;
  tmpOperand0Comp0 = 1;
  tmpOperand0Comp1 = 1;
  tmpOperand0Comp2 = 1;
  tmpOperand0Index = tempIndex;
  ((int (*)())extvsEncodeSourceOperand)(ctx,shader,&tmpOperand0Kind,instSlot,6,0,0);
  ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,instRecord + 0x20,instSlot + 4,0);
  *(undefined4 *)(instSlot + 0xc) = *(undefined4 *)(instSlot + 4);
  *(undefined4 *)(instSlot + 8) = *(undefined4 *)(instSlot + 4);
  ((int (*)())extvsEncodeSourceOperand)(ctx,shader,instRecord + 4,instSlot + 0x10,3,0,0);
  ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,instRecord + 0x20,instSlot + 0x14,0);
  tmpOperand1Kind = 3;
  tmpOperand1Flag = 0;
  tmpOperand1Comp0 = 0x87d9;
  tmpOperand1Comp1 = 0x87da;
  tmpOperand1Comp2 = 0x87db;
  tmpOperand1Comp3 = 0x87dc;
  tmpOperand1Index = tempIndex;
  ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,&tmpOperand1Kind,instSlot + 0x18,0);
  *(undefined4 *)(instSlot + 0x1c) = *(undefined4 *)(instSlot + 0x18);
  return 2;
}

/* extvsEmitRnd @ 0x5b010 (932 bytes) */
int extvsEmitRnd(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instCount;
  undefined4 tempIndex;
  undefined1 uVar1;
  uint uVar2;
  undefined4 newInstArray;
  int iVar4;
  int *symbolList;
  int hwProgram;
  int iVar7;
  int iVar8;
  int instSlot;
  int iStack00000020;
  undefined4 tmpOperand0Kind;
  int tmpOperand0Index;
  undefined4 tmpOperand0Comp0;
  undefined4 tmpOperand0Comp1;
  undefined4 tmpOperand0Comp2;
  undefined4 tmpOperand0Comp3;
  undefined1 tmpOperand0Flag;
  undefined4 tmpOperand1Kind;
  int tmpOperand1Index;
  undefined4 tmpOperand1Comp0;
  undefined4 tmpOperand1Comp1;
  undefined4 tmpOperand1Comp2;
  undefined4 tmpOperand1Comp3;
  undefined1 tmpOperand1Flag;
  
  iVar7 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  instCount = *(int *)(iVar7 + 0x18);
  iStack00000020 = instRecord;
  if (0x100 < instCount + 4U) {
    *(undefined1 *)(shader + 4) = 0;
    instCount = *(int *)(iVar7 + 0x18);
    if (*(uint *)(iVar7 + 0x20) < instCount + 4U) {
      newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(iVar7 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (newInstArray,*(undefined4 *)(iVar7 + 0x1c),*(int *)(iVar7 + 0x20) << 4);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(iVar7 + 0x1c));
      *(undefined4 *)(iVar7 + 0x1c) = newInstArray;
      instCount = *(int *)(iVar7 + 0x18);
      *(int *)(iVar7 + 0x20) = *(int *)(iVar7 + 0x20) + 0x10;
    }
  }
  symbolList = shader + 7;
  instSlot = instCount * 0x10 + *(int *)(iVar7 + 0x1c);
  iVar8 = ((int (*)())extvsAllocTempSlot)(ctx,shader);
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  iVar4 = iStack00000020 + 0x20;
  iVar7 = iVar8 * 0x28 + *(int *)(hwProgram + 0x4c);
  uVar1 = *(undefined1 *)(iVar7 + 0x10);
  *(undefined1 *)(iVar7 + 0x10) = 1;
  tempIndex = ((int (*)())extvsAllocTempSlot)(ctx,shader);
  *(undefined1 *)(iVar8 * 0x28 + *(int *)(hwProgram + 0x4c) + 0x10) = uVar1;
  tmpOperand0Kind = 3;
  tmpOperand0Comp0 = 1;
  tmpOperand0Comp1 = 0;
  tmpOperand0Comp2 = 0;
  tmpOperand0Comp3 = 0;
  tmpOperand0Flag = 0;
  tmpOperand0Index = iVar8;
  ((int (*)())extvsEncodeSourceOperand)(ctx,shader,&tmpOperand0Kind,instSlot,0xb,1,0);
  ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,iVar4,instSlot + 4,0);
  uVar2 = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1f6da000;
  *(uint *)(instSlot + 0xc) = uVar2;
  *(uint *)(instSlot + 4) = uVar2;
  *(uint *)(instSlot + 8) = uVar2;
  tmpOperand0Kind = 3;
  tmpOperand0Comp0 = 1;
  tmpOperand0Comp1 = 1;
  tmpOperand0Comp2 = 1;
  tmpOperand0Comp3 = 1;
  tmpOperand0Flag = 0;
  tmpOperand0Index = iVar8;
  ((int (*)())extvsEncodeSourceOperand)(ctx,shader,&tmpOperand0Kind,instSlot + 0x10,3,0,0);
  tmpOperand1Kind = 3;
  tmpOperand1Comp0 = 0x87d5;
  tmpOperand1Comp1 = 0x87d5;
  tmpOperand1Comp2 = 0x87d5;
  tmpOperand1Comp3 = 0x87d5;
  tmpOperand1Flag = 0;
  tmpOperand1Index = iVar8;
  ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,&tmpOperand1Kind,instSlot + 0x14,0);
  ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,iVar4,instSlot + 0x18,0);
  *(undefined4 *)(instSlot + 0x1c) = *(undefined4 *)(instSlot + 0x18);
  tmpOperand0Comp3 = 1;
  tmpOperand0Kind = 3;
  tmpOperand0Comp0 = 1;
  tmpOperand0Comp1 = 1;
  tmpOperand0Comp2 = 1;
  tmpOperand0Flag = 0;
  tmpOperand0Index = tempIndex;
  ((int (*)())extvsEncodeSourceOperand)(ctx,shader,&tmpOperand0Kind,instSlot + 0x20,6,0,0);
  tmpOperand1Comp0 = 0x87d5;
  tmpOperand1Kind = 3;
  tmpOperand1Flag = 0;
  tmpOperand1Comp1 = 0x87d6;
  tmpOperand1Comp2 = 0x87d7;
  tmpOperand1Comp3 = 0x87d8;
  tmpOperand1Index = iVar8;
  ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,&tmpOperand1Kind,instSlot + 0x24,0);
  *(undefined4 *)(instSlot + 0x2c) = *(undefined4 *)(instSlot + 0x24);
  *(undefined4 *)(instSlot + 0x28) = *(undefined4 *)(instSlot + 0x24);
  ((int (*)())extvsEncodeSourceOperand)(ctx,shader,iStack00000020 + 4,instSlot + 0x30,3,0,0);
  ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,&tmpOperand1Kind,instSlot + 0x34,0);
  tmpOperand1Kind = 3;
  tmpOperand1Flag = 0;
  tmpOperand1Comp0 = 0x87d9;
  tmpOperand1Comp1 = 0x87da;
  tmpOperand1Comp2 = 0x87db;
  tmpOperand1Comp3 = 0x87dc;
  tmpOperand1Index = tempIndex;
  ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,&tmpOperand1Kind,instSlot + 0x38,0);
  *(undefined4 *)(instSlot + 0x3c) = *(undefined4 *)(instSlot + 0x38);
  return 4;
}

/* extvsEmitExp @ 0x5b3c0 (304 bytes) */
int extvsEmitExp(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  undefined4 newInstArray;
  int instCount;
  int hwProgram;
  
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  instCount = *(int *)(hwProgram + 0x18);
  if (0x100 < instCount + 1U) {
    *(undefined1 *)(shader + 4) = 0;
    instCount = *(int *)(hwProgram + 0x18);
    if (*(uint *)(hwProgram + 0x20) < instCount + 1U) {
      newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
      *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
      instCount = *(int *)(hwProgram + 0x18);
      *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
    }
  }
  instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
  ((int (*)())extvsEncodeSourceOperand)(ctx,shader,instRecord + 4,instSlot,0xb,1,0);
  ((int (*)())extvsEncodeSourceSwizzle)(shader,shader + 7,instRecord + 0x20,instSlot + 4,0);
  *(undefined4 *)(instSlot + 0xc) = *(undefined4 *)(instSlot + 4);
  *(undefined4 *)(instSlot + 8) = *(undefined4 *)(instSlot + 4);
  return 1;
}

/* extvsEmitLog @ 0x5b4f0 (304 bytes) */
int extvsEmitLog(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  undefined4 newInstArray;
  int instCount;
  int hwProgram;
  
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  instCount = *(int *)(hwProgram + 0x18);
  if (0x100 < instCount + 1U) {
    *(undefined1 *)(shader + 4) = 0;
    instCount = *(int *)(hwProgram + 0x18);
    if (*(uint *)(hwProgram + 0x20) < instCount + 1U) {
      newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
      *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
      instCount = *(int *)(hwProgram + 0x18);
      *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
    }
  }
  instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
  ((int (*)())extvsEncodeSourceOperand)(ctx,shader,instRecord + 4,instSlot,0xc,1,0);
  ((int (*)())extvsEncodeSourceSwizzle)(shader,shader + 7,instRecord + 0x20,instSlot + 4,0);
  *(undefined4 *)(instSlot + 0xc) = *(undefined4 *)(instSlot + 4);
  *(undefined4 *)(instSlot + 8) = *(undefined4 *)(instSlot + 4);
  return 1;
}

/* extvsEmitPow @ 0x5b620 (824 bytes) */
int extvsEmitPow(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  int hwProgram;
  uint uVar1;
  int conflict;
  undefined4 uVar3;
  int src1Operand;
  int *symbolList;
  int src0Operand;
  int instCount;
  undefined4 tmpOperand0Kind;
  undefined4 tmpOperand0Index;
  undefined4 tmpOperand0Comp0;
  undefined4 tmpOperand0Comp1;
  undefined4 tmpOperand0Comp2;
  undefined4 tmpOperand0Comp3;
  undefined1 tmpOperand0Flag;
  undefined4 tmpOperand1Kind;
  undefined4 tmpOperand1Index;
  undefined4 tmpOperand1Comp0;
  undefined4 tmpOperand1Comp1;
  undefined4 tmpOperand1Comp2;
  undefined4 tmpOperand1Comp3;
  undefined1 tmpOperand1Flag;
  
  src0Operand = instRecord + 0x20;
  symbolList = shader + 7;
  src1Operand = instRecord + 0x3c;
  conflict = ((int (*)())extvsOperandsConflictInBank)(symbolList,src0Operand,src1Operand);
  if (conflict == 0) {
    hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(hwProgram + 0x18);
    if (0x100 < instCount + 1U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(hwProgram + 0x18);
      if (*(uint *)(hwProgram + 0x20) < instCount + 1U) {
        uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar3,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
        *(undefined4 *)(hwProgram + 0x1c) = uVar3;
        instCount = *(int *)(hwProgram + 0x18);
        *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
      }
    }
    instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
    ((int (*)())extvsEncodeSourceOperand)(ctx,shader,instRecord + 4,instSlot,5,1,0);
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src0Operand,instSlot + 4,0);
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src1Operand,instSlot + 8,0);
    uVar3 = 1;
    *(undefined4 *)(instSlot + 0xc) = *(undefined4 *)(instSlot + 8);
  }
  else {
    hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
    instCount = *(int *)(hwProgram + 0x18);
    if (0x100 < instCount + 2U) {
      *(undefined1 *)(shader + 4) = 0;
      instCount = *(int *)(hwProgram + 0x18);
      if (*(uint *)(hwProgram + 0x20) < instCount + 2U) {
        uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar3,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
        *(undefined4 *)(hwProgram + 0x1c) = uVar3;
        instCount = *(int *)(hwProgram + 0x18);
        *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
      }
    }
    instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
    uVar3 = ((int (*)())extvsAllocTempSlot)(ctx,shader);
    tmpOperand0Kind = 3;
    tmpOperand0Comp0 = 0;
    tmpOperand0Comp1 = 0;
    tmpOperand0Comp2 = 0;
    tmpOperand0Comp3 = 1;
    tmpOperand0Flag = 0;
    tmpOperand0Index = uVar3;
    ((int (*)())extvsEncodeSourceOperand)(ctx,shader,&tmpOperand0Kind,instSlot,3,0,0);
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src0Operand,instSlot + 4,0);
    uVar1 = *(uint *)(instSlot + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(instSlot + 0xc) = uVar1;
    *(uint *)(instSlot + 8) = uVar1;
    ((int (*)())extvsEncodeSourceOperand)(ctx,shader,instRecord + 4,instSlot + 0x10,5,1,0);
    tmpOperand1Kind = 3;
    tmpOperand1Flag = 0;
    tmpOperand1Comp0 = 0x87d5;
    tmpOperand1Comp1 = 0x87d6;
    tmpOperand1Comp2 = 0x87d7;
    tmpOperand1Comp3 = 0x87d8;
    tmpOperand1Index = uVar3;
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,&tmpOperand1Kind,instSlot + 0x14,0);
    ((int (*)())extvsEncodeSourceSwizzle)(shader,symbolList,src1Operand,instSlot + 0x18,0);
    uVar3 = 2;
    *(undefined4 *)(instSlot + 0x1c) = *(undefined4 *)(instSlot + 0x18);
  }
  return uVar3;
}

/* extvsEmitRcp @ 0x5b960 (304 bytes) */
int extvsEmitRcp(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  undefined4 newInstArray;
  int instCount;
  int hwProgram;
  
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  instCount = *(int *)(hwProgram + 0x18);
  if (0x100 < instCount + 1U) {
    *(undefined1 *)(shader + 4) = 0;
    instCount = *(int *)(hwProgram + 0x18);
    if (*(uint *)(hwProgram + 0x20) < instCount + 1U) {
      newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
      *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
      instCount = *(int *)(hwProgram + 0x18);
      *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
    }
  }
  instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
  ((int (*)())extvsEncodeSourceOperand)(ctx,shader,instRecord + 4,instSlot,6,1,0);
  ((int (*)())extvsEncodeSourceSwizzle)(shader,shader + 7,instRecord + 0x20,instSlot + 4,0);
  *(undefined4 *)(instSlot + 0xc) = *(undefined4 *)(instSlot + 4);
  *(undefined4 *)(instSlot + 8) = *(undefined4 *)(instSlot + 4);
  return 1;
}

/* extvsEmitRsq @ 0x5ba90 (304 bytes) */
int extvsEmitRsq(ctx, shader, instRecord)
  int ctx;
  int *shader;
  int instRecord;
{
  int instSlot;
  undefined4 newInstArray;
  int instCount;
  int hwProgram;
  
  hwProgram = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  instCount = *(int *)(hwProgram + 0x18);
  if (0x100 < instCount + 1U) {
    *(undefined1 *)(shader + 4) = 0;
    instCount = *(int *)(hwProgram + 0x18);
    if (*(uint *)(hwProgram + 0x20) < instCount + 1U) {
      newInstArray = (**(code **)(ctx + 0xc))(*(uint *)(hwProgram + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (newInstArray,*(undefined4 *)(hwProgram + 0x1c),*(int *)(hwProgram + 0x20) << 4);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(hwProgram + 0x1c));
      *(undefined4 *)(hwProgram + 0x1c) = newInstArray;
      instCount = *(int *)(hwProgram + 0x18);
      *(int *)(hwProgram + 0x20) = *(int *)(hwProgram + 0x20) + 0x10;
    }
  }
  instSlot = instCount * 0x10 + *(int *)(hwProgram + 0x1c);
  ((int (*)())extvsEncodeSourceOperand)(ctx,shader,instRecord + 4,instSlot,8,1,0);
  ((int (*)())extvsEncodeSourceSwizzle)(shader,shader + 7,instRecord + 0x20,instSlot + 4,0);
  *(undefined4 *)(instSlot + 0xc) = *(undefined4 *)(instSlot + 4);
  *(undefined4 *)(instSlot + 8) = *(undefined4 *)(instSlot + 4);
  return 1;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_00057cf0");
asm(".set FUN_00057cf0, _extvsEmitIndex");
asm(".globl FUN_00058300");
asm(".set FUN_00058300, _extvsEmitSingleSourceInstruction");
asm(".globl FUN_00058450");
asm(".set FUN_00058450, _extvsEmitDot3");
asm(".globl FUN_000587d0");
asm(".set FUN_000587d0, _extvsEmitDot4");
asm(".globl FUN_00058b10");
asm(".set FUN_00058b10, _extvsEmitMul");
asm(".globl FUN_00058e50");
asm(".set FUN_00058e50, _extvsEmitAdd");
asm(".globl FUN_00059190");
asm(".set FUN_00059190, _extvsEmitMad");
asm(".globl FUN_00059b80");
asm(".set FUN_00059b80, _extvsEmitFrc");
asm(".globl FUN_00059cb0");
asm(".set FUN_00059cb0, _extvsEmitMax");
asm(".globl FUN_00059ff0");
asm(".set FUN_00059ff0, _extvsEmitMin");
asm(".globl FUN_0005a330");
asm(".set FUN_0005a330, _extvsEmitSetGreaterEqual");
asm(".globl FUN_0005a670");
asm(".set FUN_0005a670, _extvsEmitSetLessThan");
asm(".globl FUN_0005a9b0");
asm(".set FUN_0005a9b0, _extvsEmitClamp");
asm(".globl FUN_0005ae10");
asm(".set FUN_0005ae10, _extvsEmitFlr");
asm(".globl FUN_0005b010");
asm(".set FUN_0005b010, _extvsEmitRnd");
asm(".globl FUN_0005b3c0");
asm(".set FUN_0005b3c0, _extvsEmitExp");
asm(".globl FUN_0005b4f0");
asm(".set FUN_0005b4f0, _extvsEmitLog");
asm(".globl FUN_0005b620");
asm(".set FUN_0005b620, _extvsEmitPow");
asm(".globl FUN_0005b960");
asm(".set FUN_0005b960, _extvsEmitRcp");
asm(".globl FUN_0005ba90");
asm(".set FUN_0005ba90, _extvsEmitRsq");

/* issue #75 (follow-up #3): Ghidra recognized this as a THUNK - a pure trampoline stub that
 * just branches straight to the real function below, no different behavior or arguments - but
 * decls.h declares "thunk_FUN_xxx" as its own separate extern function that nothing in this
 * corpus ever DEFINES a body for. The stock ld apparently tolerated the resulting undefined
 * reference (never actually called in a way that mattered, or silently resolved some other
 * way); ld64 leaves it a real unresolved lazy symbol, crashing the moment this call path is
 * first taken. Real fix: alias the thunk name directly onto the real function, so calling
 * "thunk_FUN_xxx" IS calling FUN_xxx - which is exactly what the original binary's trampoline
 * did. */
asm(".globl _thunk_FUN_00054a90");
asm(".set _thunk_FUN_00054a90, _extvsReleaseState");
