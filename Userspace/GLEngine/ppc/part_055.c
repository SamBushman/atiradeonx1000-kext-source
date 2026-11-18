#include "decls.h"

/* _gleCreateGlobalLevel @ 0x103534 (64 bytes) */
int _gleCreateGlobalLevel(unusedArg1, param_2, param_3, param_4, param_5, param_6)
  undefined4 unusedArg1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  *(undefined2 *)(param_2 + 0x10) = 0x1908;
  *(undefined2 *)(param_2 + 0xe) = 0;
  *(undefined2 *)(param_2 + 4) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
  *(undefined2 *)(param_2 + 6) = (*(unsigned short *)((unsigned char *)&(param_4) + 2));
  *(undefined2 *)(param_2 + 8) = (*(unsigned short *)((unsigned char *)&(param_5) + 2));
  *(undefined2 *)(param_2 + 0x12) = 0x1401;
  *(undefined1 *)(param_2 + 0xb) = 0x34;
  *(undefined1 *)(param_2 + 10) = (undefined1)param_6;
  *(undefined4 *)(param_2 + 0x14) = 0;
  *(undefined2 *)(param_2 + 0xc) = 0;
  return 0;
}

/* _gleSynchronizePluginTextureLevels @ 0x103574 (308 bytes) */
void _gleSynchronizePluginTextureLevels(glContext, param_2)
  int glContext;
  int param_2;
{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (*(int *)(param_2 + 0x20) != 0) {
    iVar4 = 0;
    bVar1 = *(byte *)(param_2 + 0x90);
    if (*(byte *)(glContext + 0x85a4) != 0) {
      piVar3 = (int *)(*(int *)(glContext + 0x5148) + 0x8054);
      do {
        iVar2 = *piVar3;
        piVar3 = piVar3 + 1;
        if (*(int *)(param_2 + 0x20) == iVar2) break;
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
    iVar2 = 0;
    if (bVar1 != 0) {
      iVar5 = 0;
      do {
        iVar6 = -(uint)(iVar2 == 0);
        iVar7 = (uint)(iVar2 == 0) * -0x18 + param_2 + iVar5 + 0xc4;
        do {
          if ((*(byte *)(iVar7 + 0xb) & 0x50) == 0x40) {
            _gleUploadPluginTextureLevel(glContext,param_2,iVar7,iVar2,iVar6,iVar4);
            _gleModifyPluginTextureLevel
                      (glContext,param_2,iVar7,iVar2,iVar6,0,0,0,(uint)*(ushort *)(iVar7 + 4),
                       (uint)*(ushort *)(iVar7 + 6),(uint)*(ushort *)(iVar7 + 8));
          }
          iVar6 = iVar6 + 1;
          iVar7 = iVar7 + 0x18;
        } while (iVar6 < 0xf);
        iVar2 = iVar2 + 1;
        iVar5 = iVar5 + 0x168;
      } while (iVar2 < (int)(uint)bVar1);
    }
    *(undefined4 *)(param_2 + 0x20) = 0;
  }
  return;
}

/* _gleSynchronizePluginTextures @ 0x1036a8 (108 bytes) */
void _gleSynchronizePluginTextures(glContext)
  int glContext;
{
  int textureObject;
  int unitIndex;
  int unitBase;
  int remaining;
  int *targetCursor;
  
  unitIndex = 0;
  unitBase = glContext;
  do {
    targetCursor = (int *)(unitBase + 0x5154);
    remaining = 4;
    do {
      textureObject = *targetCursor;
      targetCursor = targetCursor + 1;
      if (textureObject != 0) {
        ((void (*)())_gleSynchronizePluginTextureLevels)(glContext,textureObject + 0x10);
      }
      remaining = remaining + -1;
    } while (-1 < remaining);
    unitIndex = unitIndex + 1;
    unitBase = unitBase + 0x14;
  } while (unitIndex < 0x10);
  return;
}

/* _gleTextureTargetExtractor @ 0x103714 (116 bytes) */
int _gleTextureTargetExtractor(unusedArg1, param_2)
  undefined4 unusedArg1;
  int param_2;
{
  switch(*(ushort *)(param_2 + 0x34) & 0xf) {
  case 0:
    return 0x8513;
  case 1:
    return 0x806f;
  case 2:
    return 0x84f5;
  case 3:
    return 0xde1;
  case 4:
    return 0xde0;
  default:
    return 0;
  }
}

/* _gleTexEnableBits @ 0x10379c (192 bytes) */
int _gleTexEnableBits(glContext)
  int glContext;
{
  bool programActive;
  int programRecordThenEntryCount;
  uint *inputEntry;
  uint texEnableBits;
  
  texEnableBits = 0;
  programActive = *(char *)(glContext + 0x466c) != '\0';
  if ((programActive) || (*(int *)(glContext + 0x5438) != 0)) {
    programRecordThenEntryCount = 0;
    if (programActive) {
      programRecordThenEntryCount = *(int *)(glContext + 0x5424);
      if (*(short *)(programRecordThenEntryCount + 0x4c8) == -0x7e00) {
        return (uint)*(byte *)(programRecordThenEntryCount + 0x4eb);
      }
      programRecordThenEntryCount = *(int *)(programRecordThenEntryCount + 0x4cc);
    }
    if (*(int *)(glContext + 0x5438) != 0) {
      programRecordThenEntryCount = *(int *)(*(int *)(*(int *)(glContext + 0x5430) + 0x24) + 0x508);
    }
    if (programRecordThenEntryCount != 0) {
      inputEntry = (uint *)(programRecordThenEntryCount + *(int *)(programRecordThenEntryCount + 0x24) * 8);
      for (programRecordThenEntryCount = *(int *)(programRecordThenEntryCount + 0x20); programRecordThenEntryCount != 0; programRecordThenEntryCount = programRecordThenEntryCount + -1) {
        if ((*inputEntry >> 0x10 & 0xf) == 7) {
          texEnableBits = texEnableBits | 1 << (*inputEntry & 0x1f);
        }
        inputEntry = inputEntry + 2;
      }
    }
  }
  else {
    texEnableBits = *(uint *)(glContext + 0x514c);
  }
  return texEnableBits;
}

/* _gleTextureMatTransDivW_body @ 0x103860 (252 bytes) */
void _gleTextureMatTransDivW_body(int glContext,uint vertexCursor,int vertexBytes,int texUnit,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11)
{
  float textureMatrix0;
  float textureMatrix14;
  float textureMatrix1;
  float textureMatrix3;
  float textureMatrix4;
  float textureMatrix5;
  float textureMatrix7;
  float textureMatrix8;
  float textureMatrix9;
  float textureMatrix11;
  float textureMatrix12;
  float textureMatrix13;
  float textureMatrix15;
  float textureMatrix2;
  float textureMatrix6;
  float textureMatrix10;
  float texCoordSIn;
  float texCoordTIn;
  float texCoordRIn;
  float texCoordQIn;
  float wFactor;
  int matrixBase;
  int texCoordSlot;
  uint remaining;
  
  matrixBase = glContext + texUnit * 0x40;
  textureMatrix0 = *(float *)(matrixBase + 0x1fc0);
  textureMatrix14 = *(float *)(matrixBase + 0x1ff8);
  textureMatrix1 = *(float *)(matrixBase + 0x1fc4);
  textureMatrix3 = *(float *)(0x1fcc + matrixBase);
  textureMatrix4 = *(float *)(matrixBase + 0x1fd0);
  textureMatrix5 = *(float *)(matrixBase + 0x1fd4);
  textureMatrix7 = *(float *)(matrixBase + 0x1fdc);
  textureMatrix8 = *(float *)(matrixBase + 0x1fe0);
  textureMatrix9 = *(float *)(matrixBase + 0x1fe4);
  textureMatrix11 = *(float *)(matrixBase + 0x1fec);
  textureMatrix12 = *(float *)(matrixBase + 0x1ff0);
  textureMatrix13 = *(float *)(matrixBase + 0x1ff4);
  textureMatrix15 = *(float *)(matrixBase + 0x1ffc);
  textureMatrix2 = *(float *)(matrixBase + 0x1fc8);
  textureMatrix6 = *(float *)(matrixBase + 0x1fd8);
  textureMatrix10 = *(float *)(matrixBase + 0x1fe8);
  if (vertexCursor < vertexCursor + vertexBytes) {
    remaining = ((vertexCursor + vertexBytes) - vertexCursor) + 0xff >> 8;
    do {
      texCoordSlot = vertexCursor + texUnit * 0x10;
      texCoordSIn = *(float *)(texCoordSlot + 0x80);
      texCoordTIn = *(float *)(texCoordSlot + 0x84);
      texCoordRIn = *(float *)(texCoordSlot + 0x88);
      texCoordQIn = *(float *)(texCoordSlot + 0x8c);
      wFactor = *(float *)(vertexCursor + 0xc);
      vertexCursor = vertexCursor + 0x100;
      *(float *)(texCoordSlot + 0x8c) =
           (texCoordQIn * textureMatrix15 + (texCoordRIn * textureMatrix11 + (texCoordSIn * textureMatrix3 + texCoordTIn * textureMatrix7))) * wFactor;
      *(float *)(texCoordSlot + 0x80) =
           (texCoordQIn * textureMatrix12 + (texCoordRIn * textureMatrix8 + (texCoordSIn * textureMatrix0 + texCoordTIn * textureMatrix4))) * wFactor;
      *(float *)(texCoordSlot + 0x84) =
           (texCoordQIn * textureMatrix13 + (texCoordRIn * textureMatrix9 + (texCoordSIn * textureMatrix1 + texCoordTIn * textureMatrix5))) * wFactor;
      *(float *)(texCoordSlot + 0x88) =
           (texCoordQIn * textureMatrix14 + (texCoordRIn * textureMatrix10 + (texCoordSIn * textureMatrix2 + texCoordTIn * textureMatrix6))) * wFactor;
      remaining = remaining - 1;
    } while (remaining != 0);
  }
  return;
}

/* _gleTextureMatTransPtrDivW_body @ 0x103960 (264 bytes) */
void _gleTextureMatTransPtrDivW_body(int glContext,uint vertexCursor,int vertexBytes,int texUnit,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11)
{
  float textureMatrix0;
  float textureMatrix14;
  float textureMatrix1;
  float textureMatrix3;
  float textureMatrix4;
  float textureMatrix5;
  float textureMatrix7;
  float textureMatrix8;
  float textureMatrix9;
  float textureMatrix11;
  float textureMatrix12;
  float textureMatrix13;
  float textureMatrix15;
  float textureMatrix2;
  float textureMatrix6;
  float textureMatrix10;
  float texCoordSInThenROut;
  float texCoordTIn;
  float texCoordRIn;
  float texCoordQIn;
  float wFactor;
  float texCoordTOut;
  float texCoordSOut;
  float texCoordQOut;
  int matrixBase;
  int texCoordSlot;
  uint remaining;
  
  matrixBase = glContext + texUnit * 0x40;
  textureMatrix0 = *(float *)(matrixBase + 0x1fc0);
  textureMatrix14 = *(float *)(matrixBase + 0x1ff8);
  textureMatrix1 = *(float *)(matrixBase + 0x1fc4);
  textureMatrix3 = *(float *)(0x1fcc + matrixBase);
  textureMatrix4 = *(float *)(matrixBase + 0x1fd0);
  textureMatrix5 = *(float *)(matrixBase + 0x1fd4);
  textureMatrix7 = *(float *)(matrixBase + 0x1fdc);
  textureMatrix8 = *(float *)(matrixBase + 0x1fe0);
  textureMatrix9 = *(float *)(matrixBase + 0x1fe4);
  textureMatrix11 = *(float *)(matrixBase + 0x1fec);
  textureMatrix12 = *(float *)(matrixBase + 0x1ff0);
  textureMatrix13 = *(float *)(matrixBase + 0x1ff4);
  textureMatrix15 = *(float *)(matrixBase + 0x1ffc);
  textureMatrix2 = *(float *)(matrixBase + 0x1fc8);
  textureMatrix6 = *(float *)(matrixBase + 0x1fd8);
  textureMatrix10 = *(float *)(matrixBase + 0x1fe8);
  if (vertexCursor < vertexCursor + vertexBytes) {
    remaining = ((vertexCursor + vertexBytes) - vertexCursor) + 0xff >> 8;
    do {
      texCoordSlot = vertexCursor + texUnit * 0x10;
      texCoordSInThenROut = *(float *)(texCoordSlot + 0x80);
      texCoordTIn = *(float *)(texCoordSlot + 0x84);
      texCoordRIn = *(float *)(texCoordSlot + 0x88);
      texCoordQIn = *(float *)(texCoordSlot + 0x8c);
      wFactor = *(float *)(vertexCursor + 0xc);
      texCoordQOut = texCoordQIn * textureMatrix15 + (texCoordRIn * textureMatrix11 + (texCoordSInThenROut * textureMatrix3 + texCoordTIn * textureMatrix7));
      texCoordSOut = texCoordQIn * textureMatrix12 + (texCoordRIn * textureMatrix8 + (texCoordSInThenROut * textureMatrix0 + texCoordTIn * textureMatrix4));
      texCoordTOut = texCoordQIn * textureMatrix13 + (texCoordRIn * textureMatrix9 + (texCoordSInThenROut * textureMatrix1 + texCoordTIn * textureMatrix5));
      texCoordSInThenROut = texCoordQIn * textureMatrix14 + (texCoordRIn * textureMatrix10 + (texCoordSInThenROut * textureMatrix2 + texCoordTIn * textureMatrix6));
      if (*(char *)(vertexCursor + 0x7f) == '\0') {
        texCoordQOut = texCoordQOut * wFactor;
        texCoordSOut = texCoordSOut * wFactor;
        texCoordTOut = texCoordTOut * wFactor;
        texCoordSInThenROut = texCoordSInThenROut * wFactor;
      }
      *(float *)(texCoordSlot + 0x80) = texCoordSOut;
      vertexCursor = vertexCursor + 0x100;
      *(float *)(texCoordSlot + 0x8c) = texCoordQOut;
      *(float *)(texCoordSlot + 0x84) = texCoordTOut;
      *(float *)(texCoordSlot + 0x88) = texCoordSInThenROut;
      remaining = remaining - 1;
    } while (remaining != 0);
  }
  return;
}

/* _gleMultiTextureMatTrans @ 0x103a68 (120 bytes) */
void _gleMultiTextureMatTrans(glContext, param_2, param_3)
  int glContext;
  undefined4 param_2;
  undefined4 param_3;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = ((int (*)())_gleTexEnableBits)(glContext);
  uVar3 = 0;
  do {
    uVar1 = uVar2 >> (uVar3 & 0x3f);
    if ((uVar1 & 1) == 0) {
      if (uVar1 == 0) {
        return;
      }
    }
    else {
      (**(code **)(glContext + 0x5070))(glContext,param_2,param_3,uVar3);
    }
    uVar3 = uVar3 + 1;
  } while( true );
}

/* _gleSubmitVertexCopy @ 0x103ae0 (88 bytes) */
int _gleSubmitVertexCopy(glContext, param_2)
  int glContext;
  int param_2;
{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  sVar1 = *(short *)(glContext + 0x487c);
  iVar4 = 0;
  iVar5 = *(int *)(glContext + 0x4858);
  iVar3 = (int)sVar1 >> 3;
  if (0 < iVar3) {
    do {
      iVar2 = iVar4 * 8;
      iVar4 = iVar4 + 1;
      *(undefined8 *)(iVar5 + iVar2) = *(undefined8 *)(param_2 + iVar2);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    sVar1 = *(short *)(glContext + 0x487c);
  }
  *(int *)(glContext + 0x4858) = iVar5 + sVar1;
                    
                    
  (**(code **)(glContext + 0x4de4))(glContext);
  return;
}

/* _gleForceToSoftwareTCL @ 0x103b38 (1520 bytes) */
undefined4 _gleForceToSoftwareTCL(int glContext,double fparam_1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  bool rendererInfoByte79Clear;
  bool stateClean;
  char rendererInfoByte79;
  undefined1 uVar3;
  int *dirtyBitArrayCursor;
  undefined4 drawResult;
  int iVar6;
  int verticesLeft;
  int framebufferObject;
  int dirtyBitArrayWord;
  int incomingR5;
  undefined4 incomingR6;
  int incomingR7;
  undefined1 *puVar7;
  char *incomingR8;
  int iVar8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int vertexCursor;
  int copyVertexCount;
  int iVar11;
  int vertexField30Cursor;
  int vertexCountThenRemaining;
  int copyVertexCursor;
  int lastVertexIndex;
  undefined4 savedWord486c;
  int *dirtyFlagWords;
  int vertexLoopCursor;
  undefined4 savedVertexEnd;
  double f1AfterCall;
  double f1AfterCall1;
  char decomposeResultFlags [16];
  
  decomposeResultFlags[0] = '\0';
  vertexCursor = *(int *)(glContext + 0x4854);
  if (*(int *)(glContext + 0x48d0) == 0) {
    vertexCountThenRemaining = *(int *)(glContext + 0x4858) - vertexCursor >> 8;
  }
  else {
    incomingR8 = decomposeResultFlags;
    vertexCountThenRemaining = (*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4868)) /
             (int)*(short *)(glContext + 0x487c);
    *(int *)(glContext + 0x4858) = vertexCursor + vertexCountThenRemaining * 0x100;
    incomingR7 = vertexCursor;
    _gleDecomposePrimitiveVertices
              (glContext,*(int *)(glContext + 0x48d0),vertexCountThenRemaining,*(int *)(glContext + 0x4868),vertexCursor,incomingR8);
    if (decomposeResultFlags[0] != '\0') {
      vertexCursor = *(int *)(glContext + 0x758c);
    }
    incomingR6 = 0;
    incomingR5 = (int)*(short *)(glContext + 0x4a12);
    (**(code **)(glContext + 0x46ec))(*(undefined4 *)(glContext + 0x4688),2,incomingR5,0);
    fparam_1 = f1AfterCall;
  }
  lastVertexIndex = vertexCountThenRemaining + -1;
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = f1AfterCall1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_00103dec;
  framebufferObject = *(int *)(glContext + 0x744c);
  dirtyFlagWords = (int *)(glContext + 0x310);
  rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1,floatArg2,floatArg3,
               floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00103ce4:
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    dirtyBitArrayCursor = (int *)(glContext + 0x324);
    do {
      dirtyBitArrayWord = *dirtyBitArrayCursor;
      dirtyBitArrayCursor = dirtyBitArrayCursor + 1;
      if (dirtyBitArrayWord != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 9);
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
    if ((dirtyWord3ThenMasked & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_00103ce4;
    }
  }
  rendererInfoByte79Clear = rendererInfoByte79 == '\0';
  if (rendererInfoByte79Clear) {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
  }
  else {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
  }
  if (rendererInfoByte79Clear) {
    stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!stateClean) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      dispatchFlags = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
      if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
          ((dispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
         ((dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if ((dispatchFlags & 4) == 0) {
          dispatchFlags = dispatchFlags & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(glContext,dispatchFlags);
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(glContext);
    }
  }
  remaining = 0x13;
  do {
    *dirtyFlagWords = 0;
    dirtyFlagWords = dirtyFlagWords + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
LAB_00103dec:
  *(undefined4 *)(glContext + 0x4884) = *(undefined4 *)(glContext + 0x4888);
  if (*(char *)(glContext + 0x30aa) == '\0') {
    if (-1 < lastVertexIndex) {
      puVar7 = (undefined1 *)(vertexCursor + 0x7e);
      do {
        puVar7[-1] = *(undefined1 *)(glContext + 0x2ed);
        *puVar7 = *(undefined1 *)(glContext + 0x2ee);
        puVar7 = puVar7 + 0x100;
        vertexCountThenRemaining = vertexCountThenRemaining + -1;
      } while (vertexCountThenRemaining != 0);
    }
  }
  else if (*(char *)(glContext + 0x4df8) == '\0') {
    if (*(char *)(glContext + 0x30ac) == '\0') {
      iVar8 = *(int *)(glContext + 0x4dd0);
      *(undefined4 *)(iVar8 + 0x1e0) = 1;
      if (-1 < lastVertexIndex) {
        do {
          *(undefined1 *)(vertexCursor + 0x7d) = *(undefined1 *)(glContext + 0x2ed);
          uVar3 = *(undefined1 *)(glContext + 0x2ee);
          *(int *)(vertexCursor + 0x74) = iVar8;
          *(undefined1 *)(vertexCursor + 0x7e) = uVar3;
          vertexCursor = vertexCursor + 0x100;
          vertexCountThenRemaining = vertexCountThenRemaining + -1;
        } while (vertexCountThenRemaining != 0);
      }
    }
    else {
      iVar8 = *(int *)(glContext + 0x4dd0);
      iVar6 = *(int *)(glContext + 0x4dd4);
      *(undefined4 *)(iVar8 + 0x1e0) = 1;
      *(undefined4 *)(iVar6 + 0x1e0) = 1;
      if (-1 < lastVertexIndex) {
        do {
          *(undefined1 *)(vertexCursor + 0x7d) = *(undefined1 *)(glContext + 0x2ed);
          uVar3 = *(undefined1 *)(glContext + 0x2ee);
          *(int *)(vertexCursor + 0x74) = iVar8;
          *(undefined1 *)(vertexCursor + 0x7e) = uVar3;
          *(int *)(vertexCursor + 0x78) = iVar6;
          vertexCursor = vertexCursor + 0x100;
          vertexCountThenRemaining = vertexCountThenRemaining + -1;
        } while (vertexCountThenRemaining != 0);
      }
    }
  }
  else {
    vertexField30Cursor = vertexCursor + 0x30;
    (**(code **)(glContext + 0x4de0))(glContext,vertexField30Cursor);
    if (*(char *)(glContext + 0x30ac) == '\0') {
      iVar8 = 0;
      verticesLeft = lastVertexIndex;
      vertexLoopCursor = vertexCursor;
      if (0 < lastVertexIndex) {
        do {
          *(undefined1 *)(vertexLoopCursor + 0x7d) = *(undefined1 *)(glContext + 0x2ed);
          *(undefined1 *)(vertexLoopCursor + 0x7e) = *(undefined1 *)(glContext + 0x2ee);
          iVar8 = *(int *)(glContext + 0x4dd0);
          *(undefined4 *)(iVar8 + 0x1e0) = 1;
          *(int *)(vertexLoopCursor + 0x74) = iVar8;
          if (((*(float *)(vertexLoopCursor + 0x30) != *(float *)(vertexLoopCursor + 0x130)) ||
              (*(float *)(vertexLoopCursor + 0x34) != *(float *)(vertexLoopCursor + 0x134))) ||
             ((*(float *)(vertexLoopCursor + 0x38) != *(float *)(vertexLoopCursor + 0x138) ||
              (*(float *)(vertexLoopCursor + 0x3c) != *(float *)(vertexLoopCursor + 0x13c))))) {
            (**(code **)(glContext + 0x4de0))(glContext,vertexField30Cursor);
          }
          verticesLeft = verticesLeft + -1;
          vertexField30Cursor = vertexField30Cursor + 0x100;
          iVar8 = lastVertexIndex;
          vertexLoopCursor = vertexLoopCursor + 0x100;
        } while (verticesLeft != 0);
      }
      iVar11 = *(int *)(glContext + 0x4dd0);
      *(undefined4 *)(iVar11 + 0x1e0) = 1;
      *(int *)(iVar8 * 0x100 + vertexCursor + 0x74) = iVar11;
    }
    else {
      iVar8 = 0;
      verticesLeft = lastVertexIndex;
      vertexLoopCursor = vertexCursor;
      if (0 < lastVertexIndex) {
        do {
          *(undefined1 *)(vertexLoopCursor + 0x7d) = *(undefined1 *)(glContext + 0x2ed);
          *(undefined1 *)(vertexLoopCursor + 0x7e) = *(undefined1 *)(glContext + 0x2ee);
          iVar8 = *(int *)(glContext + 0x4dd0);
          *(undefined4 *)(iVar8 + 0x1e0) = 1;
          *(int *)(vertexLoopCursor + 0x74) = iVar8;
          iVar8 = *(int *)(glContext + 0x4dd4);
          *(undefined4 *)(iVar8 + 0x1e0) = 1;
          *(int *)(vertexLoopCursor + 0x78) = iVar8;
          if (((*(float *)(vertexLoopCursor + 0x30) != *(float *)(vertexLoopCursor + 0x130)) ||
              (*(float *)(vertexLoopCursor + 0x34) != *(float *)(vertexLoopCursor + 0x134))) ||
             ((*(float *)(vertexLoopCursor + 0x38) != *(float *)(vertexLoopCursor + 0x138) ||
              (*(float *)(vertexLoopCursor + 0x3c) != *(float *)(vertexLoopCursor + 0x13c))))) {
            (**(code **)(glContext + 0x4de0))(glContext,vertexField30Cursor);
          }
          verticesLeft = verticesLeft + -1;
          vertexField30Cursor = vertexField30Cursor + 0x100;
          iVar8 = lastVertexIndex;
          vertexLoopCursor = vertexLoopCursor + 0x100;
        } while (verticesLeft != 0);
      }
      iVar11 = *(int *)(glContext + 0x4dd0);
      vertexCursor = iVar8 * 0x100 + vertexCursor;
      *(undefined4 *)(iVar11 + 0x1e0) = 1;
      *(int *)(vertexCursor + 0x74) = iVar11;
      iVar11 = *(int *)(glContext + 0x4dd4);
      *(undefined4 *)(iVar11 + 0x1e0) = 1;
      *(int *)(vertexCursor + 0x78) = iVar11;
    }
  }
  if (decomposeResultFlags[0] == '\0') {
    savedWord486c = *(undefined4 *)(glContext + 0x486c);
    savedVertexEnd = *(undefined4 *)(glContext + 0x4858);
    drawResult = (**(code **)(*(short *)(glContext + 0x4a10) * 4 + glContext + 0x49e0))(glContext);
    *(undefined4 *)(glContext + 0x4858) = savedVertexEnd;
    *(undefined4 *)(glContext + 0x486c) = savedWord486c;
  }
  else {
    savedWord486c = *(undefined4 *)(glContext + 0x486c);
    drawResult = (**(code **)(*(short *)(glContext + 0x4a10) * 4 + glContext + 0x49e0))(glContext);
    copyVertexCount = *(int *)(glContext + 0x7588);
    *(undefined4 *)(glContext + 0x486c) = savedWord486c;
    copyVertexCursor = *(int *)(glContext + 0x758c);
    for (; copyVertexCount != 0; copyVertexCount = copyVertexCount + -1) {
      drawResult = ((int (*)())_gleSubmitVertexCopy)(glContext,copyVertexCursor);
      copyVertexCursor = copyVertexCursor + 0x100;
    }
  }
  return drawResult;
}

/* _gleTypeSize @ 0x104128 (84 bytes) */
int _gleTypeSize(unusedArg1, type)
  undefined4 unusedArg1;
  undefined4 type;
{
  switch(type) {
  case 0x1400:
  case 0x1401:
    return 1;
  case 0x1402:
  case 0x1403:
    return 2;
  case 0x1404:
  case 0x1405:
  case 0x1406:
    return 4;
  default:
    return 8;
  }
}

/* _gleBindVertexArray @ 0x104198 (200 bytes) */
int _gleBindVertexArray(glContext, id)
  int glContext;
  int id;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(glContext + 0x5148) + 0x5014;
  if (id == 0) {
    iVar1 = *(int *)(glContext + 0x4a64);
  }
  else {
    iVar1 = _gleLookupHashObject(iVar3,id);
    if (iVar1 == 0) {
      iVar1 = _gleCreateVertexArrayObject(glContext,id);
      _gleCreatePluginVertexArray(glContext,iVar1 + 0x10);
      _gleAddHashNameAndObject(glContext,iVar3,iVar1);
    }
  }
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  iVar4 = *(int *)(glContext + 0x4a60);
  uVar2 = _gleSetCurrentVertexObject(glContext,iVar1);
  iVar3 = *(int *)(iVar4 + 8) + -1;
  *(int *)(iVar4 + 8) = iVar3;
  if (iVar3 == 0) {
    uVar2 = _gleFreeVertexArrayObject(glContext,iVar4);
    return uVar2;
  }
  return uVar2;
}

/* _gleReclaimVertexArrayResources @ 0x104260 (352 bytes) */
void _gleReclaimVertexArrayResources(glContext)
  int glContext;
{
  int *rendererFuncs;
  undefined4 *rendererContext;
  int iVar3;
  undefined4 rendererHandle;
  int *nextBucket;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 *handleCursor;
  int rendererBase;
  
  iVar3 = *(int *)(glContext + 0x5148);
  piVar8 = (int *)(iVar3 + 0x5014);
  do {
    nextBucket = piVar8 + 1;
    for (piVar8 = (int *)*piVar8; piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
      if (piVar8[2] == 1) {
        iVar6 = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          iVar7 = (int)(piVar8 + 0x118);
          handleCursor = piVar8 + 4;
          rendererBase = glContext + 0x10000;
          do {
            rendererFuncs = (int *)(rendererBase + -0x777c);
            iVar6 = iVar6 + 1;
            rendererContext = (undefined4 *)(rendererBase + -0x7a54);
            rendererBase = rendererBase + 0x2e0;
            rendererHandle = *handleCursor;
            handleCursor = handleCursor + 1;
            (**(code **)(*rendererFuncs + 0x1b4))(*rendererContext,rendererHandle);
            *(undefined4 *)(iVar7 + 4) = *(undefined4 *)(iVar7 + 4);
            *(uint *)(iVar7 + 8) = *(uint *)(iVar7 + 8) | 1;
            iVar7 = iVar7 + 0x8c;
          } while (iVar6 < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
        piVar8[0xd4] = piVar8[0xd4];
        piVar8[0xd5] = piVar8[0xd5] | 1;
      }
    }
    piVar8 = nextBucket;
  } while ((int)nextBucket <= iVar3 + 0x6010);
  iVar3 = *(int *)(glContext + 0x4a64);
  if (*(int *)(iVar3 + 8) == 1) {
    iVar6 = glContext + 0x10000;
    iVar7 = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      handleCursor = (undefined4 *)(iVar3 + 0x10);
      iVar3 = iVar3 + 0x460;
      do {
        piVar8 = (int *)(iVar6 + -0x777c);
        iVar7 = iVar7 + 1;
        rendererContext = (undefined4 *)(iVar6 + -0x7a54);
        iVar6 = iVar6 + 0x2e0;
        rendererHandle = *handleCursor;
        handleCursor = handleCursor + 1;
        (**(code **)(*piVar8 + 0x1b4))(*rendererContext,rendererHandle);
        *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar3 + 4);
        *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) | 1;
        iVar3 = iVar3 + 0x8c;
      } while (iVar7 < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
  }
  return;
}

/* _gleVPFlipColors @ 0x1043c0 (404 bytes) */
double _gleVPFlipColors(glContext, vertexCursor, vertexCount, facing)
  int glContext;
  uint vertexCursor;
  int vertexCount;
  uint facing;
{
  uint vertexEndThenRemaining;
  undefined4 savedFrontR;
  undefined4 savedFrontASecPath;
  undefined4 savedFrontG;
  undefined4 savedSecondaryBSecPath;
  undefined4 savedFrontB;
  undefined4 savedSecondaryRSecPath;
  undefined4 savedFrontA;
  undefined4 savedSecondaryGSecPath;
  undefined4 savedFrontRSecPath;
  undefined4 savedFrontGSecPath;
  undefined4 savedFrontBSecPath;
  
  vertexEndThenRemaining = vertexCursor + vertexCount * 0x100;
  if (*(char *)(glContext + 0x316b) == '\0') {
    if (vertexCursor < vertexEndThenRemaining) {
      vertexEndThenRemaining = (vertexEndThenRemaining - vertexCursor) + 0xff >> 8;
      do {
        if (facing != *(byte *)(vertexCursor + 0x7e)) {
          savedFrontR = *(undefined4 *)(vertexCursor + 0x30);
          savedFrontG = *(undefined4 *)(vertexCursor + 0x34);
          savedFrontB = *(undefined4 *)(vertexCursor + 0x38);
          savedFrontA = *(undefined4 *)(vertexCursor + 0x3c);
          *(undefined4 *)(vertexCursor + 0x30) = *(undefined4 *)(vertexCursor + 0x20);
          *(undefined4 *)(vertexCursor + 0x34) = *(undefined4 *)(vertexCursor + 0x24);
          *(undefined4 *)(vertexCursor + 0x38) = *(undefined4 *)(vertexCursor + 0x28);
          *(undefined4 *)(vertexCursor + 0x3c) = *(undefined4 *)(vertexCursor + 0x2c);
          *(char *)(vertexCursor + 0x7e) = (char)facing;
          *(undefined4 *)(vertexCursor + 0x20) = savedFrontR;
          *(undefined4 *)(vertexCursor + 0x24) = savedFrontG;
          *(undefined4 *)(vertexCursor + 0x28) = savedFrontB;
          *(undefined4 *)(vertexCursor + 0x2c) = savedFrontA;
        }
        vertexCursor = vertexCursor + 0x100;
        vertexEndThenRemaining = vertexEndThenRemaining - 1;
      } while (vertexEndThenRemaining != 0);
    }
  }
  else if (vertexCursor < vertexEndThenRemaining) {
    vertexEndThenRemaining = (vertexEndThenRemaining - vertexCursor) + 0xff >> 8;
    do {
      if (facing != *(byte *)(vertexCursor + 0x7e)) {
        savedFrontRSecPath = *(undefined4 *)(vertexCursor + 0x30);
        savedFrontGSecPath = *(undefined4 *)(vertexCursor + 0x34);
        savedFrontBSecPath = *(undefined4 *)(vertexCursor + 0x38);
        savedFrontASecPath = *(undefined4 *)(vertexCursor + 0x3c);
        savedSecondaryRSecPath = *(undefined4 *)(vertexCursor + 0x50);
        savedSecondaryGSecPath = *(undefined4 *)(vertexCursor + 0x54);
        savedSecondaryBSecPath = *(undefined4 *)(vertexCursor + 0x58);
        *(undefined4 *)(vertexCursor + 0x30) = *(undefined4 *)(vertexCursor + 0x20);
        *(undefined4 *)(vertexCursor + 0x34) = *(undefined4 *)(vertexCursor + 0x24);
        *(undefined4 *)(vertexCursor + 0x38) = *(undefined4 *)(vertexCursor + 0x28);
        *(undefined4 *)(vertexCursor + 0x3c) = *(undefined4 *)(vertexCursor + 0x2c);
        *(undefined4 *)(vertexCursor + 0x50) = *(undefined4 *)(vertexCursor + 0x40);
        *(undefined4 *)(vertexCursor + 0x54) = *(undefined4 *)(vertexCursor + 0x44);
        *(undefined4 *)(vertexCursor + 0x58) = *(undefined4 *)(vertexCursor + 0x48);
        *(char *)(vertexCursor + 0x7e) = (char)facing;
        *(undefined4 *)(vertexCursor + 0x20) = savedFrontRSecPath;
        *(undefined4 *)(vertexCursor + 0x24) = savedFrontGSecPath;
        *(undefined4 *)(vertexCursor + 0x28) = savedFrontBSecPath;
        *(undefined4 *)(vertexCursor + 0x2c) = savedFrontASecPath;
        *(undefined4 *)(vertexCursor + 0x40) = savedSecondaryRSecPath;
        *(undefined4 *)(vertexCursor + 0x44) = savedSecondaryGSecPath;
        *(undefined4 *)(vertexCursor + 0x48) = savedSecondaryBSecPath;
      }
      vertexCursor = vertexCursor + 0x100;
      vertexEndThenRemaining = vertexEndThenRemaining - 1;
    } while (vertexEndThenRemaining != 0);
  }
  return;
}

/* _gleVPRenderPoints @ 0x104554 (324 bytes) */
void _gleVPRenderPoints(glContext)
  int glContext;
{
  int iVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar1 = ((int (*)())_gleTexEnableBits)(glContext);
  if ((((int)*(short *)(glContext + 0x487c) == 0) ||
      (uVar4 = (uint)(*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4854)) /
               (uint)(int)*(short *)(glContext + 0x487c), (int)uVar4 < 1)) ||
     (uVar2 = _gleVPEmulate(glContext,uVar4), (uVar2 & 0xff00) != 0)) {
    return;
  }
  uVar5 = *(undefined4 *)(glContext + 0x4864);
  if (((uVar2 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
    if (iVar1 != 0) {
      (**(code **)(glContext + 0x506c))(glContext,uVar5,uVar4,0);
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46b0);
    uVar3 = uVar5;
  }
  else {
    if (iVar1 != 0) {
      (**(code **)(glContext + 0x5074))(glContext,uVar5,uVar4,0);
    }
    uVar3 = *(undefined4 *)(glContext + 0x4870);
    uVar4 = _gleClipPoints(glContext,uVar5,uVar4,uVar3);
    if (uVar4 == 0) {
      return;
    }
    if ((*(char *)(glContext + 0x4e18) != '\0') &&
       (uVar4 = _gleClipPointsPlane(glContext,uVar3,uVar4), uVar4 == 0)) {
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46d8);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(glContext + 0x4688),uVar3,uVar4);
  return;
}

/* _gleVPRenderLines @ 0x104698 (420 bytes) */
void _gleVPRenderLines(glContext)
  int glContext;
{
  uint vertexEndThenRemaining;
  int texEnableBits;
  uint batchClipCodes;
  uint *lineListCursor;
  uint drawVertexCount;
  uint vertexCursor;
  uint *lineList;
  double f1AfterCall;
  double fparam_1;
  
  texEnableBits = ((int (*)())_gleTexEnableBits)(glContext);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (drawVertexCount = (uint)(*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4854)) /
               (uint)(int)*(short *)(glContext + 0x487c), 1 < (int)drawVertexCount)) &&
     (batchClipCodes = _gleVPEmulate(glContext,drawVertexCount), (batchClipCodes & 0xff00) == 0)) {
    vertexCursor = *(uint *)(glContext + 0x4864);
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (texEnableBits != 0) {
        (**(code **)(glContext + 0x506c))(glContext,vertexCursor,drawVertexCount,0);
      }
                    
                    
      (**(code **)(glContext + 0x46b4))(*(undefined4 *)(glContext + 0x4688),vertexCursor,drawVertexCount);
      return;
    }
    fparam_1 = f1AfterCall;
    if (texEnableBits != 0) {
      fparam_1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, drawVertexCount, 0);
    }
    vertexEndThenRemaining = vertexCursor + drawVertexCount * 0x100;
    lineList = *(uint **)(glContext + 0x4870);
    if (vertexCursor < vertexEndThenRemaining) {
      vertexEndThenRemaining = (vertexEndThenRemaining - vertexCursor) + 0xff >> 8;
      lineListCursor = lineList;
      do {
        *lineListCursor = vertexCursor;
        vertexCursor = vertexCursor + 0x100;
        lineListCursor = lineListCursor + 1;
        vertexEndThenRemaining = vertexEndThenRemaining - 1;
      } while (vertexEndThenRemaining != 0);
    }
    if ((*(char *)(glContext + 0x4e18) != '\0') &&
       (drawVertexCount = ((int (*)())_gleClipLinesPlane)(glContext,lineList,drawVertexCount,fparam_1), drawVertexCount == 0)) {
      return;
    }
    if (((batchClipCodes & 0xff) == 0) ||
       (drawVertexCount = _gleClipLines(glContext,lineList,drawVertexCount,batchClipCodes & 0xff), drawVertexCount != 0)) {
                    
                    
      (**(code **)(glContext + 0x46dc))(*(undefined4 *)(glContext + 0x4688),lineList,drawVertexCount,2);
      return;
    }
  }
  return;
}

/* _gleVPRenderLineStrip @ 0x10483c (436 bytes) */
void _gleVPRenderLineStrip(glContext)
  int glContext;
{
  char glContextByte4a18;
  uint *lineStart;
  int texEnableBits;
  uint batchClipCodes;
  code *UNRECOVERED_JUMPTABLE;
  uint *drawVertices;
  uint *lineListCursor;
  uint drawVertexCount;
  uint endVertexCopy;
  uint *vertexArrayStart;
  double f1AfterCall;
  double f1AfterHookCall;
  double f1AfterCall1;
  
  texEnableBits = ((int (*)())_gleTexEnableBits)(glContext);
  if ((((int)*(short *)(glContext + 0x487c) == 0) ||
      (drawVertexCount = (uint)(*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4854)) /
               (uint)(int)*(short *)(glContext + 0x487c), (int)drawVertexCount < 2)) ||
     (batchClipCodes = _gleVPEmulate(glContext,drawVertexCount), (batchClipCodes & 0xff00) != 0)) {
    return;
  }
  vertexArrayStart = *(uint **)(glContext + 0x4864);
  if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
    if (texEnableBits != 0) {
      (**(code **)(glContext + 0x506c))(glContext,vertexArrayStart,drawVertexCount,0);
    }
    glContextByte4a18 = *(char *)(glContext + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46b8);
    drawVertices = vertexArrayStart;
  }
  else {
    f1AfterHookCall = f1AfterCall;
    if (texEnableBits != 0) {
      f1AfterHookCall = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexArrayStart, drawVertexCount, 0);
    }
    drawVertices = *(uint **)(glContext + 0x4870);
    endVertexCopy = *(uint *)(glContext + 0x4854);
    lineStart = vertexArrayStart;
    lineListCursor = drawVertices;
    while (lineStart < vertexArrayStart + drawVertexCount * 0x40 + -0x40) {
      *lineListCursor = (uint)lineStart;
      _memcpy(endVertexCopy,lineStart + 0x40,0x100);
      lineListCursor[1] = endVertexCopy;
      endVertexCopy = endVertexCopy + 0x100;
      lineListCursor = lineListCursor + 2;
      lineStart = lineStart + 0x40;
      f1AfterHookCall = f1AfterCall1;
    }
    drawVertexCount = (int)lineListCursor - (int)drawVertices >> 2;
    if ((*(char *)(glContext + 0x4e18) != '\0') &&
       (drawVertexCount = ((int (*)())_gleClipLinesPlane)(glContext,drawVertices,drawVertexCount,f1AfterHookCall), drawVertexCount == 0)) {
      return;
    }
    if (((batchClipCodes & 0xff) != 0) &&
       (drawVertexCount = _gleClipLines(glContext,drawVertices,drawVertexCount,batchClipCodes & 0xff), drawVertexCount == 0)) {
      return;
    }
    glContextByte4a18 = *(char *)(glContext + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46dc);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(glContext + 0x4688),drawVertices,drawVertexCount,glContextByte4a18 == '\0');
  return;
}

/* _gleVPRenderLineLoop @ 0x1049f0 (540 bytes) */
void _gleVPRenderLineLoop(glContext)
  int glContext;
{
  char glContextByte4a18;
  int copyByteOffset;
  uint *lineStart;
  int texEnableBits;
  uint batchClipCodes;
  int vertexEnd;
  int closingVertexSource;
  short vertexSize;
  int copyIndex;
  code *UNRECOVERED_JUMPTABLE;
  uint *drawVertices;
  uint *lineListCursor;
  uint drawVertexCount;
  int vertexStart;
  int remaining;
  uint *vertexArrayStart;
  uint endVertexCopy;
  double f1AfterCall;
  double fparam_1;
  double f1AfterCall1;
  
  texEnableBits = ((int (*)())_gleTexEnableBits)(glContext);
  vertexSize = *(short *)(glContext + 0x487c);
  vertexStart = *(int *)(glContext + 0x4854);
  if ((int)vertexSize != 0) {
    vertexEnd = *(int *)(glContext + 0x4858);
    drawVertexCount = (uint)(vertexEnd - vertexStart) / (uint)(int)vertexSize;
    if (*(short *)(glContext + 0x4a10) < 0) {
      if ((int)drawVertexCount < 1) {
        return;
      }
      closingVertexSource = vertexStart + -0x100;
      if (*(char *)(glContext + 0x4a18) == '\0') {
        closingVertexSource = vertexStart;
      }
      copyIndex = 0;
      remaining = (int)vertexSize >> 3;
      if (0 < remaining) {
        do {
          copyByteOffset = copyIndex * 8;
          copyIndex = copyIndex + 1;
          *(undefined8 *)(copyByteOffset + vertexEnd) = *(undefined8 *)(copyByteOffset + closingVertexSource);
          remaining = remaining + -1;
        } while (remaining != 0);
        vertexSize = *(short *)(glContext + 0x487c);
      }
      drawVertexCount = drawVertexCount + 1;
      *(int *)(glContext + 0x4858) = vertexEnd + vertexSize;
    }
    batchClipCodes = _gleVPEmulate(glContext,drawVertexCount);
    if ((batchClipCodes & 0xff00) == 0) {
      vertexArrayStart = *(uint **)(glContext + 0x4864);
      if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
        if (texEnableBits != 0) {
          (**(code **)(glContext + 0x506c))(glContext,vertexArrayStart,drawVertexCount,0);
        }
        glContextByte4a18 = *(char *)(glContext + 0x4a18);
        UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46b8);
        drawVertices = vertexArrayStart;
      }
      else {
        fparam_1 = f1AfterCall;
        if (texEnableBits != 0) {
          fparam_1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexArrayStart, drawVertexCount, 0);
        }
        drawVertices = *(uint **)(glContext + 0x4870);
        endVertexCopy = *(uint *)(glContext + 0x4854);
        lineStart = vertexArrayStart;
        lineListCursor = drawVertices;
        while (lineStart < vertexArrayStart + drawVertexCount * 0x40 + -0x40) {
          *lineListCursor = (uint)lineStart;
          _memcpy(endVertexCopy,lineStart + 0x40,0x100);
          lineListCursor[1] = endVertexCopy;
          endVertexCopy = endVertexCopy + 0x100;
          lineListCursor = lineListCursor + 2;
          lineStart = lineStart + 0x40;
          fparam_1 = f1AfterCall1;
        }
        drawVertexCount = (int)lineListCursor - (int)drawVertices >> 2;
        if ((*(char *)(glContext + 0x4e18) != '\0') &&
           (drawVertexCount = ((int (*)())_gleClipLinesPlane)(glContext,drawVertices,drawVertexCount,fparam_1), drawVertexCount == 0)) {
          return;
        }
        if (((batchClipCodes & 0xff) != 0) &&
           (drawVertexCount = _gleClipLines(glContext,drawVertices,drawVertexCount,batchClipCodes & 0xff), drawVertexCount == 0)) {
          return;
        }
        glContextByte4a18 = *(char *)(glContext + 0x4a18);
        UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46dc);
      }
                    
                    
      (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(glContext + 0x4688),drawVertices,drawVertexCount,glContextByte4a18 == '\0');
      return;
    }
  }
  return;
}

/* _gleVPRenderTriangles_body @ 0x104c10 (876 bytes) */
void _gleVPRenderTriangles_body(glContext)
  int glContext;
{
  byte vertexProgramTwoSide;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool orientationChanged;
  uint *nextPolygonList;
  int iVar6;
  int runVertexCount;
  uint resumeCursor;
  uint batchClipCodes;
  int cullResult;
  int flipRemaining;
  uint *spareList;
  uint *nextSpareList;
  uint *polygonVertexCursor;
  int iVar11;
  int polygonVertexCount;
  uint *polygonList;
  uint vertexCountThenLastTriangleStart;
  uint nextRunStart;
  uint runStart;
  uint vertexCursor;
  double f1AfterCall;
  double dVar17;
  double extraout_f1_00;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  int backFacing;
  int clippedVertexCount [5];
  
  iVar11 = -1;
  iVar6 = ((int (*)())_gleTexEnableBits)(glContext);
  vertexProgramTwoSide = *(byte *)(glContext + 0x4666);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (vertexCountThenLastTriangleStart = (uint)(*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4854)) /
                (uint)(int)*(short *)(glContext + 0x487c), 2 < (int)vertexCountThenLastTriangleStart)) &&
     (batchClipCodes = _gleVPEmulate(glContext,vertexCountThenLastTriangleStart), (batchClipCodes & 0xff00) == 0)) {
    vertexCursor = *(uint *)(glContext + 0x4864);
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      dVar17 = f1AfterCall;
      if (iVar6 != 0) {
        dVar17 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCountThenLastTriangleStart, 0);
      }
      if (faceTestNeeded == '\0') {
        (**(code **)(glContext + 0x46c4))
                  (*(undefined4 *)(glContext + 0x4688),vertexCursor,vertexCountThenLastTriangleStart,
                   *(ushort *)(glContext + 0x34d0) - 0x1b00);
      }
      else {
        vertexCountThenLastTriangleStart = (vertexCursor + vertexCountThenLastTriangleStart * 0x100) - 0x300;
        do {
          orientationChanged = false;
          runVertexCount = 0;
          resumeCursor = vertexCursor;
          runStart = vertexCursor;
          if (vertexCursor <= vertexCountThenLastTriangleStart) {
            do {
              cullResult = ((undefined4 (*)())_gleCullTriangle)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x200,0,&backFacing,
                                       dVar17,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                       incomingStack_ffffff78,incomingStack_ffffff80);
              dVar17 = dVar17;
              if (cullResult == 0) {
                if (iVar11 != backFacing) {
                  orientationChanged = true;
                }
                if ((orientationChanged) && (resumeCursor = vertexCursor, 0 < runVertexCount)) break;
                runVertexCount = runVertexCount + 3;
                iVar11 = backFacing;
                nextRunStart = runStart;
              }
              else {
                nextRunStart = vertexCursor + 0x300;
                resumeCursor = nextRunStart;
                if (0 < runVertexCount) break;
              }
              vertexCursor = vertexCursor + 0x300;
              resumeCursor = vertexCursor;
              runStart = nextRunStart;
            } while (vertexCursor <= vertexCountThenLastTriangleStart);
            if (2 < runVertexCount) {
              if ((int)-(uint)vertexProgramTwoSide < 0) {
                ((double (*)())_gleVPFlipColors)(glContext,runStart,runVertexCount,iVar11);
              }
              if (iVar11 == 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              dVar17 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46c4))
                                         (*(undefined4 *)(glContext + 0x4688), runStart, runVertexCount, facePolygonMode - 0x1b00);
            }
          }
          vertexCursor = resumeCursor;
        } while (resumeCursor <= vertexCountThenLastTriangleStart);
      }
    }
    else {
      dVar17 = f1AfterCall;
      if (iVar6 != 0) {
        dVar17 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCountThenLastTriangleStart, 0);
      }
      polygonList = *(uint **)(glContext + 0x4870);
      vertexCountThenLastTriangleStart = (vertexCursor + vertexCountThenLastTriangleStart * 0x100) - 0x300;
      spareList = *(uint **)(glContext + 0x4874);
      if (vertexCursor <= vertexCountThenLastTriangleStart) {
        do {
          polygonList[1] = vertexCursor + 0x100;
          polygonList[2] = vertexCursor + 0x200;
          *polygonList = vertexCursor;
          *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
          nextSpareList = spareList;
          nextPolygonList = polygonList;
          iVar11 = 3;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar17 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,3,spareList,clippedVertexCount,dVar17,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             nextSpareList = polygonList, nextPolygonList = spareList, polygonVertexCount = clippedVertexCount[0], clippedVertexCount[0] != 0)) {
            polygonList = nextPolygonList;
            spareList = nextSpareList;
            if ((batchClipCodes & 0xff) != 0) {
              dVar17 = (double)_gleClipPoly(glContext,polygonList,polygonVertexCount,batchClipCodes & 0xff,nextSpareList,clippedVertexCount,1);
              if (clippedVertexCount[0] == 0) goto LAB_00104f54;
              if (0 < clippedVertexCount[0]) {
                spareList = polygonList;
                polygonList = nextSpareList;
                polygonVertexCount = clippedVertexCount[0];
              }
            }
            if ((faceTestNeeded == '\0') ||
               (iVar6 = _gleCullPolygonPtrStack(glContext,polygonList,polygonVertexCount,&backFacing),
               dVar17 = f1AfterCall2, iVar6 == 0)) {
              iVar6 = backFacing;
              if (((int)-(uint)vertexProgramTwoSide < 0) && (polygonVertexCursor = polygonList, flipRemaining = polygonVertexCount, 0 < polygonVertexCount)) {
                do {
                  ((double (*)())_gleVPFlipColors)(glContext,*polygonVertexCursor,1,iVar6);
                  flipRemaining = flipRemaining + -1;
                  polygonVertexCursor = polygonVertexCursor + 1;
                } while (flipRemaining != 0);
              }
              if (iVar6 == 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              dVar17 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                         (*(undefined4 *)(glContext + 0x4688), polygonList, polygonVertexCount, facePolygonMode - 0x1b00);
            }
          }
LAB_00104f54:
          vertexCursor = vertexCursor + 0x300;
        } while (vertexCursor <= vertexCountThenLastTriangleStart);
      }
    }
  }
  return;
}

/* _gleVPRenderTriangleStrip_body @ 0x104f80 (1040 bytes) */
void _gleVPRenderTriangleStrip_body(glContext)
  int glContext;
{
  byte vertexProgramTwoSide;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool facingChanged;
  bool windingFlip;
  uint runStart;
  uint *puVar6;
  int iVar7;
  int runTriangleCount;
  uint uVar8;
  uint batchClipCodes;
  int iVar9;
  int cullResult;
  uint uVar10;
  int iVar11;
  int polygonVertexCount;
  uint uVar12;
  uint *spareList;
  uint *puVar14;
  uint *flipCursor;
  int *triangleVertexList;
  uint newRunStart;
  uint *polygonVertexList;
  uint vertexCountThenLastTriangle;
  uint nextVertex;
  uint vertexCursor;
  double f1AfterCall;
  double dVar21;
  double f1AfterCall1;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  int backFacing;
  int clippedCount [4];
  
  iVar11 = -1;
  iVar7 = ((int (*)())_gleTexEnableBits)(glContext);
  vertexProgramTwoSide = *(byte *)(glContext + 0x4666);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  uVar12 = 0;
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (vertexCountThenLastTriangle = (uint)(*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4854)) /
                (uint)(int)*(short *)(glContext + 0x487c), 2 < (int)vertexCountThenLastTriangle)) &&
     (batchClipCodes = _gleVPEmulate(glContext,vertexCountThenLastTriangle), (batchClipCodes & 0xff00) == 0)) {
    vertexCursor = *(uint *)(glContext + 0x4864);
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      dVar21 = f1AfterCall;
      if (iVar7 != 0) {
        dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCountThenLastTriangle, 0);
      }
      if (faceTestNeeded == '\0') {
        (**(code **)(glContext + 0x46cc))
                  (*(undefined4 *)(glContext + 0x4688),vertexCursor,vertexCountThenLastTriangle,
                   *(ushort *)(glContext + 0x34d0) - 0x1b00);
      }
      else {
        triangleVertexList = *(int **)(glContext + 0x4870);
        uVar8 = 0;
        vertexCountThenLastTriangle = (vertexCursor + vertexCountThenLastTriangle * 0x100) - 0x300;
        do {
          facingChanged = false;
          runTriangleCount = 0;
          uVar10 = uVar8;
          runStart = vertexCursor;
          while (uVar8 = uVar10, vertexCursor <= vertexCountThenLastTriangle) {
            nextVertex = vertexCursor + 0x100;
            cullResult = ((undefined4 (*)())_gleCullTriangle)(glContext,vertexCursor,nextVertex,vertexCursor + 0x200,uVar10,&backFacing,dVar21,
                                     incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78,
                                     incomingStack_ffffff80);
            dVar21 = f1AfterCall1;
            if (cullResult == 0) {
              if (iVar11 != backFacing) {
                facingChanged = true;
              }
              if ((facingChanged) && (0 < runTriangleCount)) break;
              if (runTriangleCount == 0) {
                uVar12 = uVar10;
              }
              runTriangleCount = runTriangleCount + 1;
              iVar11 = backFacing;
              newRunStart = runStart;
            }
            else {
              newRunStart = nextVertex;
              uVar8 = uVar10 ^ 1;
              vertexCursor = nextVertex;
              if (0 < runTriangleCount) break;
            }
            uVar10 = uVar10 ^ 1;
            vertexCursor = nextVertex;
            runStart = newRunStart;
          }
          iVar9 = runTriangleCount + 2;
          if (2 < iVar9) {
            if ((int)-(uint)vertexProgramTwoSide < 0) {
              ((double (*)())_gleVPFlipColors)(glContext,runStart,iVar9,iVar11);
            }
            uVar10 = runStart;
            if (uVar12 != 0) {
              uVar10 = runStart + 0x100;
              *triangleVertexList = runStart + 0x200;
              triangleVertexList[2] = runStart;
              triangleVertexList[1] = uVar10;
              if (iVar11 != 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              iVar9 = runTriangleCount + 1;
              dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                         (*(undefined4 *)(glContext + 0x4688), triangleVertexList, 3, facePolygonMode - 0x1b00);
              if (iVar9 < 3) goto LAB_001051b4;
            }
            if (iVar11 != 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46cc))
                                       (*(undefined4 *)(glContext + 0x4688), uVar10, iVar9, facePolygonMode - 0x1b00);
          }
LAB_001051b4: ;
        } while (vertexCursor <= vertexCountThenLastTriangle);
      }
    }
    else {
      dVar21 = f1AfterCall;
      if (iVar7 != 0) {
        dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCountThenLastTriangle, 0);
      }
      polygonVertexList = *(uint **)(glContext + 0x4870);
      uVar12 = (vertexCursor + vertexCountThenLastTriangle * 0x100) - 0x300;
      spareList = *(uint **)(glContext + 0x4874);
      if (vertexCursor <= uVar12) {
        windingFlip = false;
        do {
          windingFlip = !windingFlip;
          if (windingFlip) {
            polygonVertexList[2] = vertexCursor + 0x200;
            *polygonVertexList = vertexCursor;
          }
          else {
            *polygonVertexList = vertexCursor + 0x200;
            polygonVertexList[2] = vertexCursor;
          }
          vertexCursor = vertexCursor + 0x100;
          polygonVertexList[1] = vertexCursor;
          *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
          puVar14 = spareList;
          puVar6 = polygonVertexList;
          iVar11 = 3;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar21 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonVertexList,3,spareList,clippedCount,dVar21,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             puVar14 = polygonVertexList, puVar6 = spareList, polygonVertexCount = clippedCount[0], clippedCount[0] != 0)) {
            polygonVertexList = puVar6;
            spareList = puVar14;
            if ((batchClipCodes & 0xff) != 0) {
              dVar21 = (double)_gleClipPoly(glContext,polygonVertexList,polygonVertexCount,batchClipCodes & 0xff,puVar14,clippedCount,1);
              if (clippedCount[0] == 0) goto LAB_00105368;
              if (0 < clippedCount[0]) {
                spareList = polygonVertexList;
                polygonVertexList = puVar14;
                polygonVertexCount = clippedCount[0];
              }
            }
            if ((faceTestNeeded == '\0') ||
               (iVar7 = _gleCullPolygonPtrStack(glContext,polygonVertexList,polygonVertexCount,&backFacing),
               dVar21 = f1AfterCall2, iVar7 == 0)) {
              iVar7 = backFacing;
              if (((int)-(uint)vertexProgramTwoSide < 0) && (flipCursor = polygonVertexList, iVar9 = polygonVertexCount, 0 < polygonVertexCount)) {
                do {
                  ((double (*)())_gleVPFlipColors)(glContext,*flipCursor,1,iVar7);
                  iVar9 = iVar9 + -1;
                  flipCursor = flipCursor + 1;
                } while (iVar9 != 0);
              }
              if (iVar7 == 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                         (*(undefined4 *)(glContext + 0x4688), polygonVertexList, polygonVertexCount, facePolygonMode - 0x1b00);
            }
          }
LAB_00105368: ;
        } while (vertexCursor <= uVar12);
      }
    }
  }
  return;
}

/* _gleVPRenderTriangleFan_body @ 0x105394 (888 bytes) */
void _gleVPRenderTriangleFan_body(glContext)
  int glContext;
{
  byte vertexProgramTwoSide;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool facingChanged;
  int *piVar5;
  int iVar6;
  int runTriangleCount;
  uint uVar7;
  uint batchClipCodes;
  int cullResult;
  int remaining;
  int *spareList;
  int *piVar10;
  int *flipCursor;
  int iVar11;
  int polygonVertexCount;
  uint uVar12;
  int fanCenter;
  int *polygonList;
  uint vertexCountThenLastVertex;
  uint uVar16;
  double f1AfterCall;
  double dVar17;
  double f1AfterCall1;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  int backFacing;
  int clippedCount [6];
  
  iVar11 = -1;
  iVar6 = ((int (*)())_gleTexEnableBits)(glContext);
  vertexProgramTwoSide = *(byte *)(glContext + 0x4666);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (vertexCountThenLastVertex = (uint)(*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4854)) /
                (uint)(int)*(short *)(glContext + 0x487c), 2 < (int)vertexCountThenLastVertex)) &&
     (batchClipCodes = _gleVPEmulate(glContext,vertexCountThenLastVertex), (batchClipCodes & 0xff00) == 0)) {
    fanCenter = *(int *)(glContext + 0x4864);
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      dVar17 = f1AfterCall;
      if (iVar6 != 0) {
        dVar17 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, fanCenter, vertexCountThenLastVertex, 0);
      }
      if (faceTestNeeded == '\0') {
        (**(code **)(glContext + 0x46c8))
                  (*(undefined4 *)(glContext + 0x4688),fanCenter,fanCenter + 0x100,vertexCountThenLastVertex - 1,
                   *(ushort *)(glContext + 0x34d0) - 0x1b00);
      }
      else {
        uVar7 = fanCenter + 0x100;
        vertexCountThenLastVertex = (fanCenter + vertexCountThenLastVertex * 0x100) - 0x200;
        do {
          facingChanged = false;
          runTriangleCount = 0;
          uVar16 = uVar7;
          do {
            while( true ) {
              uVar12 = uVar16;
              if (vertexCountThenLastVertex < uVar7) goto LAB_00105508;
              uVar16 = uVar7 + 0x100;
              cullResult = ((undefined4 (*)())_gleCullTriangle)(glContext,fanCenter,uVar7,uVar16,0,&backFacing,dVar17,incomingFpr2,incomingFpr3,
                                       incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78,
                                       incomingStack_ffffff80);
              dVar17 = f1AfterCall1;
              if (cullResult != 0) break;
              if (iVar11 != backFacing) {
                facingChanged = true;
              }
              if ((facingChanged) && (0 < runTriangleCount)) goto LAB_00105508;
              runTriangleCount = runTriangleCount + 1;
              iVar11 = backFacing;
              uVar7 = uVar16;
              uVar16 = uVar12;
            }
            uVar7 = uVar16;
          } while (runTriangleCount < 1);
LAB_00105508:
          runTriangleCount = runTriangleCount + 1;
          if (1 < runTriangleCount) {
            if ((int)-(uint)vertexProgramTwoSide < 0) {
              ((double (*)())_gleVPFlipColors)(glContext,uVar12,runTriangleCount,iVar11);
            }
            if (iVar11 == 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            dVar17 = (double)(**(double ( **)(int,int,int,int,int))(glContext + 0x46c8))
                                       (*(undefined4 *)(glContext + 0x4688), fanCenter, uVar12, runTriangleCount, facePolygonMode - 0x1b00);
          }
        } while (uVar7 <= vertexCountThenLastVertex);
      }
    }
    else {
      dVar17 = f1AfterCall;
      if (iVar6 != 0) {
        dVar17 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, fanCenter, vertexCountThenLastVertex, 0);
      }
      polygonList = *(int **)(glContext + 0x4870);
      vertexCountThenLastVertex = (fanCenter + vertexCountThenLastVertex * 0x100) - 0x200;
      spareList = *(int **)(glContext + 0x4874);
      if (fanCenter + 0x100U <= vertexCountThenLastVertex) {
        uVar16 = fanCenter + 0x100U;
        do {
          uVar12 = uVar16 + 0x100;
          *polygonList = fanCenter;
          polygonList[1] = uVar16;
          polygonList[2] = uVar12;
          *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
          piVar10 = spareList;
          piVar5 = polygonList;
          iVar11 = 3;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar17 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,3,spareList,clippedCount,dVar17,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             piVar10 = polygonList, piVar5 = spareList, polygonVertexCount = clippedCount[0], clippedCount[0] != 0)) {
            polygonList = piVar5;
            spareList = piVar10;
            if ((batchClipCodes & 0xff) != 0) {
              dVar17 = (double)_gleClipPoly(glContext,polygonList,polygonVertexCount,batchClipCodes & 0xff,piVar10,clippedCount,1);
              if (clippedCount[0] == 0) goto LAB_001056e4;
              if (0 < clippedCount[0]) {
                spareList = polygonList;
                polygonList = piVar10;
                polygonVertexCount = clippedCount[0];
              }
            }
            if ((faceTestNeeded == '\0') ||
               (iVar6 = _gleCullPolygonPtrStack(glContext,polygonList,polygonVertexCount,&backFacing),
               dVar17 = f1AfterCall2, iVar6 == 0)) {
              iVar6 = backFacing;
              if (((int)-(uint)vertexProgramTwoSide < 0) && (flipCursor = polygonList, remaining = polygonVertexCount, 0 < polygonVertexCount)) {
                do {
                  ((double (*)())_gleVPFlipColors)(glContext,*flipCursor,1,iVar6);
                  remaining = remaining + -1;
                  flipCursor = flipCursor + 1;
                } while (remaining != 0);
              }
              if (iVar6 == 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              dVar17 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                         (*(undefined4 *)(glContext + 0x4688), polygonList, polygonVertexCount, facePolygonMode - 0x1b00);
            }
          }
LAB_001056e4:
          uVar16 = uVar12;
        } while (uVar12 <= vertexCountThenLastVertex);
      }
    }
  }
  return;
}

/* _gleVPRenderQuads_body @ 0x105710 (884 bytes) */
void _gleVPRenderQuads_body(glContext)
  int glContext;
{
  byte vertexProgramTwoSide;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool facingChanged;
  uint *newPolygonList;
  int texEnableBitsThenRunCountThenCullResultThenBackFacing;
  uint resumeCursor;
  uint batchClipCodes;
  int cullResultThenFlipCount;
  uint *spareList;
  uint *oldPolygonListThenVertexPtrCursor;
  int iVar11;
  int polygonVertexCount;
  uint *polygonList;
  uint vertexCountThenLastQuadStart;
  uint nextRunStart;
  uint runStart;
  uint vertexCursor;
  double f1AfterCall;
  double forwardedFloatArg1;
  double f1AfterCall1;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  double incomingStack_ffffff88;
  int backFacing;
  int clipCount [5];
  
  iVar11 = -1;
  texEnableBitsThenRunCountThenCullResultThenBackFacing = ((int (*)())_gleTexEnableBits)(glContext);
  vertexProgramTwoSide = *(byte *)(glContext + 0x4666);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (vertexCountThenLastQuadStart = (uint)(*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4854)) /
                (uint)(int)*(short *)(glContext + 0x487c), 3 < (int)vertexCountThenLastQuadStart)) &&
     (batchClipCodes = _gleVPEmulate(glContext,vertexCountThenLastQuadStart), (batchClipCodes & 0xff00) == 0)) {
    vertexCursor = *(uint *)(glContext + 0x4864);
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      forwardedFloatArg1 = f1AfterCall;
      if (texEnableBitsThenRunCountThenCullResultThenBackFacing != 0) {
        forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCountThenLastQuadStart, 0);
      }
      if (faceTestNeeded == '\0') {
        (**(code **)(glContext + 0x46d0))
                  (*(undefined4 *)(glContext + 0x4688),vertexCursor,vertexCountThenLastQuadStart,
                   *(ushort *)(glContext + 0x34d0) - 0x1b00);
      }
      else {
        vertexCountThenLastQuadStart = (vertexCursor + vertexCountThenLastQuadStart * 0x100) - 0x400;
        do {
          facingChanged = false;
          texEnableBitsThenRunCountThenCullResultThenBackFacing = 0;
          resumeCursor = vertexCursor;
          runStart = vertexCursor;
          if (vertexCursor <= vertexCountThenLastQuadStart) {
            do {
              cullResultThenFlipCount = ((undefined4 (*)())_gleCullQuad)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x200,vertexCursor + 0x300,
                                   &backFacing,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                   incomingStack_ffffff78,incomingStack_ffffff80,incomingStack_ffffff88);
              forwardedFloatArg1 = forwardedFloatArg1;
              if (cullResultThenFlipCount == 0) {
                if (iVar11 != backFacing) {
                  facingChanged = true;
                }
                if ((facingChanged) && (resumeCursor = vertexCursor, 0 < texEnableBitsThenRunCountThenCullResultThenBackFacing)) break;
                texEnableBitsThenRunCountThenCullResultThenBackFacing = texEnableBitsThenRunCountThenCullResultThenBackFacing + 4;
                iVar11 = backFacing;
                nextRunStart = runStart;
              }
              else {
                nextRunStart = vertexCursor + 0x400;
                resumeCursor = nextRunStart;
                if (0 < texEnableBitsThenRunCountThenCullResultThenBackFacing) break;
              }
              vertexCursor = vertexCursor + 0x400;
              resumeCursor = vertexCursor;
              runStart = nextRunStart;
            } while (vertexCursor <= vertexCountThenLastQuadStart);
            if (3 < texEnableBitsThenRunCountThenCullResultThenBackFacing) {
              if ((int)-(uint)vertexProgramTwoSide < 0) {
                ((double (*)())_gleVPFlipColors)(glContext,runStart,texEnableBitsThenRunCountThenCullResultThenBackFacing,iVar11);
              }
              if (iVar11 == 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46d0))
                                         (*(undefined4 *)(glContext + 0x4688), runStart, texEnableBitsThenRunCountThenCullResultThenBackFacing, facePolygonMode - 0x1b00);
            }
          }
          vertexCursor = resumeCursor;
        } while (resumeCursor <= vertexCountThenLastQuadStart);
      }
    }
    else {
      forwardedFloatArg1 = f1AfterCall;
      if (texEnableBitsThenRunCountThenCullResultThenBackFacing != 0) {
        forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCountThenLastQuadStart, 0);
      }
      polygonList = *(uint **)(glContext + 0x4870);
      vertexCountThenLastQuadStart = (vertexCursor + vertexCountThenLastQuadStart * 0x100) - 0x400;
      spareList = *(uint **)(glContext + 0x4874);
      if (vertexCursor <= vertexCountThenLastQuadStart) {
        do {
          polygonList[1] = vertexCursor + 0x100;
          polygonList[2] = vertexCursor + 0x200;
          polygonList[3] = vertexCursor + 0x300;
          *polygonList = vertexCursor;
          *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
          oldPolygonListThenVertexPtrCursor = spareList;
          newPolygonList = polygonList;
          iVar11 = 4;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (forwardedFloatArg1 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,4,spareList,clipCount,forwardedFloatArg1,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             oldPolygonListThenVertexPtrCursor = polygonList, newPolygonList = spareList, polygonVertexCount = clipCount[0], clipCount[0] != 0)) {
            polygonList = newPolygonList;
            spareList = oldPolygonListThenVertexPtrCursor;
            if ((batchClipCodes & 0xff) != 0) {
              forwardedFloatArg1 = (double)_gleClipPoly(glContext,polygonList,polygonVertexCount,batchClipCodes & 0xff,oldPolygonListThenVertexPtrCursor,clipCount,1);
              if (clipCount[0] == 0) goto LAB_00105a5c;
              if (0 < clipCount[0]) {
                spareList = polygonList;
                polygonList = oldPolygonListThenVertexPtrCursor;
                polygonVertexCount = clipCount[0];
              }
            }
            if ((faceTestNeeded == '\0') ||
               (texEnableBitsThenRunCountThenCullResultThenBackFacing = _gleCullPolygonPtrStack(glContext,polygonList,polygonVertexCount,&backFacing),
               forwardedFloatArg1 = f1AfterCall2, texEnableBitsThenRunCountThenCullResultThenBackFacing == 0)) {
              texEnableBitsThenRunCountThenCullResultThenBackFacing = backFacing;
              if (((int)-(uint)vertexProgramTwoSide < 0) && (oldPolygonListThenVertexPtrCursor = polygonList, cullResultThenFlipCount = polygonVertexCount, 0 < polygonVertexCount)) {
                do {
                  ((double (*)())_gleVPFlipColors)(glContext,*oldPolygonListThenVertexPtrCursor,1,texEnableBitsThenRunCountThenCullResultThenBackFacing);
                  cullResultThenFlipCount = cullResultThenFlipCount + -1;
                  oldPolygonListThenVertexPtrCursor = oldPolygonListThenVertexPtrCursor + 1;
                } while (cullResultThenFlipCount != 0);
              }
              if (texEnableBitsThenRunCountThenCullResultThenBackFacing == 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                         (*(undefined4 *)(glContext + 0x4688), polygonList, polygonVertexCount, facePolygonMode - 0x1b00);
            }
          }
LAB_00105a5c:
          vertexCursor = vertexCursor + 0x400;
        } while (vertexCursor <= vertexCountThenLastQuadStart);
      }
    }
  }
  return;
}

/* _gleVPRenderQuadStrip_body @ 0x105a88 (884 bytes) */
void _gleVPRenderQuadStrip_body(glContext)
  int glContext;
{
  byte vertexProgramTwoSide;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool orientationChanged;
  uint *nextPolygonList;
  int iVar6;
  int runVertexCount;
  uint uVar7;
  uint batchClipCodes;
  int cullResult;
  int flipRemaining;
  uint *spareList;
  uint *nextSpareList;
  uint *polygonVertexCursor;
  int iVar11;
  int polygonVertexCount;
  uint runStart;
  uint clipNextQuadStart;
  uint *polygonList;
  uint vertexCountThenLastQuadStart;
  uint vertexCursor;
  double f1AfterCall;
  double dVar16;
  double f1AfterCall1;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  double incomingStack_ffffff88;
  int backFacing;
  int clippedVertexCount [6];
  
  iVar11 = -1;
  iVar6 = ((int (*)())_gleTexEnableBits)(glContext);
  vertexProgramTwoSide = *(byte *)(glContext + 0x4666);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (vertexCountThenLastQuadStart = (uint)(*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4854)) /
                (uint)(int)*(short *)(glContext + 0x487c), 3 < (int)vertexCountThenLastQuadStart)) &&
     (batchClipCodes = _gleVPEmulate(glContext,vertexCountThenLastQuadStart), (batchClipCodes & 0xff00) == 0)) {
    vertexCursor = *(uint *)(glContext + 0x4864);
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      dVar16 = f1AfterCall;
      if (iVar6 != 0) {
        dVar16 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCountThenLastQuadStart, 0);
      }
      if (faceTestNeeded == '\0') {
        (**(code **)(glContext + 0x46d4))
                  (*(undefined4 *)(glContext + 0x4688),vertexCursor,vertexCountThenLastQuadStart,
                   *(ushort *)(glContext + 0x34d0) - 0x1b00);
      }
      else {
        vertexCountThenLastQuadStart = (vertexCursor + vertexCountThenLastQuadStart * 0x100) - 0x400;
        do {
          orientationChanged = false;
          runVertexCount = 0;
          uVar7 = vertexCursor;
          do {
            while( true ) {
              runStart = uVar7;
              if (vertexCountThenLastQuadStart < vertexCursor) goto LAB_00105bf4;
              uVar7 = vertexCursor + 0x200;
              cullResult = ((undefined4 (*)())_gleCullQuad)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x300,uVar7,&backFacing,
                                   dVar16,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                   incomingStack_ffffff78,incomingStack_ffffff80,incomingStack_ffffff88);
              dVar16 = f1AfterCall1;
              if (cullResult != 0) break;
              if (iVar11 != backFacing) {
                orientationChanged = true;
              }
              if ((orientationChanged) && (0 < runVertexCount)) goto LAB_00105bf4;
              runVertexCount = runVertexCount + 2;
              iVar11 = backFacing;
              vertexCursor = uVar7;
              uVar7 = runStart;
            }
            vertexCursor = uVar7;
          } while (runVertexCount < 1);
LAB_00105bf4:
          runVertexCount = runVertexCount + 2;
          if (3 < runVertexCount) {
            if ((int)-(uint)vertexProgramTwoSide < 0) {
              ((double (*)())_gleVPFlipColors)(glContext,runStart,runVertexCount,iVar11);
            }
            if (iVar11 == 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            dVar16 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46d4))
                                       (*(undefined4 *)(glContext + 0x4688), runStart, runVertexCount, facePolygonMode - 0x1b00);
          }
        } while (vertexCursor <= vertexCountThenLastQuadStart);
      }
    }
    else {
      dVar16 = f1AfterCall;
      if (iVar6 != 0) {
        dVar16 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCountThenLastQuadStart, 0);
      }
      polygonList = *(uint **)(glContext + 0x4870);
      spareList = *(uint **)(glContext + 0x4874);
      vertexCountThenLastQuadStart = (vertexCursor + vertexCountThenLastQuadStart * 0x100) - 0x400;
      if (vertexCursor <= vertexCountThenLastQuadStart) {
        do {
          clipNextQuadStart = vertexCursor + 0x200;
          polygonList[1] = vertexCursor + 0x100;
          polygonList[2] = vertexCursor + 0x300;
          *polygonList = vertexCursor;
          polygonList[3] = clipNextQuadStart;
          *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
          nextSpareList = spareList;
          nextPolygonList = polygonList;
          iVar11 = 4;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar16 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,4,spareList,clippedVertexCount,dVar16,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             nextSpareList = polygonList, nextPolygonList = spareList, polygonVertexCount = clippedVertexCount[0], clippedVertexCount[0] != 0)) {
            polygonList = nextPolygonList;
            spareList = nextSpareList;
            if ((batchClipCodes & 0xff) != 0) {
              dVar16 = (double)_gleClipPoly(glContext,polygonList,polygonVertexCount,batchClipCodes & 0xff,nextSpareList,clippedVertexCount,1);
              if (clippedVertexCount[0] == 0) goto LAB_00105dd4;
              if (0 < clippedVertexCount[0]) {
                spareList = polygonList;
                polygonList = nextSpareList;
                polygonVertexCount = clippedVertexCount[0];
              }
            }
            if ((faceTestNeeded == '\0') ||
               (iVar6 = _gleCullPolygonPtrStack(glContext,polygonList,polygonVertexCount,&backFacing),
               dVar16 = f1AfterCall2, iVar6 == 0)) {
              iVar6 = backFacing;
              if (((int)-(uint)vertexProgramTwoSide < 0) && (polygonVertexCursor = polygonList, flipRemaining = polygonVertexCount, 0 < polygonVertexCount)) {
                do {
                  ((double (*)())_gleVPFlipColors)(glContext,*polygonVertexCursor,1,iVar6);
                  flipRemaining = flipRemaining + -1;
                  polygonVertexCursor = polygonVertexCursor + 1;
                } while (flipRemaining != 0);
              }
              if (iVar6 == 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              dVar16 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                         (*(undefined4 *)(glContext + 0x4688), polygonList, polygonVertexCount, facePolygonMode - 0x1b00);
            }
          }
LAB_00105dd4:
          vertexCursor = clipNextQuadStart;
        } while (clipNextQuadStart <= vertexCountThenLastQuadStart);
      }
    }
  }
  return;
}

/* _gleVPRenderPolygon @ 0x105dfc (728 bytes) */
void _gleVPRenderPolygon(glContext)
  int glContext;
{
  byte vertexProgramTwoSide;
  char faceTestNeeded;
  ushort facePolygonMode;
  int *listCursorThenFlipCursor;
  int texEnableBitsThenPolygonMode;
  uint clipFlagsThenFlipCount;
  int cullResult;
  undefined4 planeClippedFlag;
  code *drawCallback;
  int *polygonList;
  uint vertexCountThenClippedCount;
  int *spareList;
  int *vertexArrayThenPolygonList;
  uint remainingVertices;
  double f1AfterCall;
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  uint clippedCount;
  int backFacing [4];
  
  backFacing[0] = 0;
  texEnableBitsThenPolygonMode = ((int (*)())_gleTexEnableBits)(glContext);
  vertexProgramTwoSide = *(byte *)(glContext + 0x4666);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (vertexCountThenClippedCount = (uint)(*(int *)(glContext + 0x4858) - *(int *)(glContext + 0x4854)) /
                (uint)(int)*(short *)(glContext + 0x487c), 2 < (int)vertexCountThenClippedCount)) &&
     (clipFlagsThenFlipCount = _gleVPEmulate(glContext,vertexCountThenClippedCount), (clipFlagsThenFlipCount & 0xff00) == 0)) {
    vertexArrayThenPolygonList = *(int **)(glContext + 0x4864);
    if (((clipFlagsThenFlipCount & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if ((faceTestNeeded != '\0') &&
         (cullResult = _gleCullPolygonStack(glContext,vertexArrayThenPolygonList,vertexCountThenClippedCount,0,backFacing), cullResult != 0)) {
        return;
      }
      if (texEnableBitsThenPolygonMode != 0) {
        (**(code **)(glContext + 0x506c))(glContext,vertexArrayThenPolygonList,vertexCountThenClippedCount,0);
      }
      if (backFacing[0] == 0) {
        facePolygonMode = *(ushort *)(glContext + 0x34d0);
      }
      else {
        facePolygonMode = *(ushort *)(glContext + 0x34d2);
      }
      texEnableBitsThenPolygonMode = facePolygonMode - 0x1b00;
      if ((*(char *)(glContext + 0x4a18) != '\0') && (texEnableBitsThenPolygonMode == 1)) {
        texEnableBitsThenPolygonMode = 3;
      }
      if ((int)-(uint)vertexProgramTwoSide < 0) {
        ((double (*)())_gleVPFlipColors)(glContext,vertexArrayThenPolygonList,vertexCountThenClippedCount,backFacing[0]);
      }
      drawCallback = *(code **)(glContext + 0x46c0);
    }
    else {
      forwardedFloatArg1 = f1AfterCall;
      if (texEnableBitsThenPolygonMode != 0) {
        forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexArrayThenPolygonList, vertexCountThenClippedCount, 0);
      }
      polygonList = *(int **)(glContext + 0x4870);
      spareList = *(int **)(glContext + 0x4874);
      listCursorThenFlipCursor = polygonList;
      remainingVertices = vertexCountThenClippedCount;
      if (0 < (int)vertexCountThenClippedCount) {
        do {
          *listCursorThenFlipCursor = (int)vertexArrayThenPolygonList;
          vertexArrayThenPolygonList = vertexArrayThenPolygonList + 0x40;
          remainingVertices = remainingVertices - 1;
          listCursorThenFlipCursor = listCursorThenFlipCursor + 1;
        } while (remainingVertices != 0);
      }
      planeClippedFlag = 0;
      *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
      vertexArrayThenPolygonList = polygonList;
      if (*(char *)(glContext + 0x4e18) != '\0') {
        ((double (*)())_gleClipPolyPlane)(glContext,polygonList,vertexCountThenClippedCount,spareList,&clippedCount,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,
                          incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff88,incomingStack_ffffff90);
        if (clippedCount == 0) {
          return;
        }
        planeClippedFlag = 1;
        vertexArrayThenPolygonList = spareList;
        vertexCountThenClippedCount = clippedCount;
        spareList = polygonList;
      }
      if ((clipFlagsThenFlipCount & 0xff) != 0) {
        _gleClipPoly(glContext,vertexArrayThenPolygonList,vertexCountThenClippedCount,clipFlagsThenFlipCount & 0xff,spareList,&clippedCount,planeClippedFlag);
        if (clippedCount == 0) {
          return;
        }
        if (0 < (int)clippedCount) {
          vertexArrayThenPolygonList = spareList;
          vertexCountThenClippedCount = clippedCount;
        }
      }
      if ((faceTestNeeded != '\0') &&
         (texEnableBitsThenPolygonMode = _gleCullPolygonPtrStack(glContext,vertexArrayThenPolygonList,vertexCountThenClippedCount,backFacing), texEnableBitsThenPolygonMode != 0)) {
        return;
      }
      if (backFacing[0] == 0) {
        facePolygonMode = *(ushort *)(glContext + 0x34d0);
      }
      else {
        facePolygonMode = *(ushort *)(glContext + 0x34d2);
      }
      texEnableBitsThenPolygonMode = facePolygonMode - 0x1b00;
      if ((*(char *)(glContext + 0x4a18) != '\0') && (texEnableBitsThenPolygonMode == 1)) {
        texEnableBitsThenPolygonMode = 3;
      }
      if (((int)-(uint)vertexProgramTwoSide < 0) && (listCursorThenFlipCursor = vertexArrayThenPolygonList, clipFlagsThenFlipCount = vertexCountThenClippedCount, 0 < (int)vertexCountThenClippedCount)) {
        do {
          ((double (*)())_gleVPFlipColors)(glContext,*listCursorThenFlipCursor,1,backFacing[0]);
          clipFlagsThenFlipCount = clipFlagsThenFlipCount - 1;
          listCursorThenFlipCursor = listCursorThenFlipCursor + 1;
        } while (clipFlagsThenFlipCount != 0);
      }
      drawCallback = *(code **)(glContext + 0x46e0);
    }
    (*drawCallback)(*(undefined4 *)(glContext + 0x4688),vertexArrayThenPolygonList,vertexCountThenClippedCount,texEnableBitsThenPolygonMode);
  }
  return;
}

/* _gleVPFlushAtomic @ 0x1060d4 (60 bytes) */
void _gleVPFlushAtomic(glContext)
  int glContext;
{
  (**(code **)(glContext + 0x4a08))(glContext);
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleVPFlushAtomicTCL @ 0x106110 (60 bytes) */
void _gleVPFlushAtomicTCL(glContext)
  int glContext;
{
  (**(code **)(glContext + 0x4a08))(glContext);
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleVPFlushAtomicTCLRDirty @ 0x10614c (132 bytes) */
void _gleVPFlushAtomicTCLRDirty(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleVPFlushLineLoop @ 0x1061d0 (228 bytes) */
void _gleVPFlushLineLoop(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined8 local_120 [33];
  
  iVar5 = *(int *)(glContext + 0x4854);
  iVar4 = (int)*(short *)(glContext + 0x487c) >> 3;
  if (*(char *)(glContext + 0x4a18) == '\0') {
    iVar3 = 0;
    for (iVar6 = iVar4; iVar6 != 0; iVar6 = iVar6 + -1) {
      iVar1 = iVar3 * 8;
      iVar3 = iVar3 + 1;
      *(undefined8 *)(iVar5 + -0x100 + iVar1) = *(undefined8 *)(iVar5 + iVar1);
    }
  }
  iVar2 = *(int *)(glContext + 0x4858);
  iVar6 = iVar4 * 8;
  iVar1 = 0;
  for (iVar3 = iVar4; iVar3 != 0; iVar3 = iVar3 + -1) {
    local_120[iVar1] = *(undefined8 *)(iVar2 + iVar4 * -8 + iVar1 * 8);
    iVar1 = iVar1 + 1;
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  iVar3 = 0;
  for (; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined8 *)(iVar5 + iVar3 * 8) = local_120[iVar3];
    iVar3 = iVar3 + 1;
  }
  *(int *)(glContext + 0x4858) = iVar5 + iVar6;
  return;
}

/* _gleVPFlushLineLoopTCL @ 0x1062b4 (180 bytes) */
void _gleVPFlushLineLoopTCL(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar6 = *(int *)(glContext + 0x4854);
  iVar3 = (int)*(short *)(glContext + 0x487c) >> 3;
  if (*(char *)(glContext + 0x4a18) == '\0') {
    iVar4 = 0;
    for (iVar7 = iVar3; iVar7 != 0; iVar7 = iVar7 + -1) {
      iVar5 = iVar4 * 8;
      iVar4 = iVar4 + 1;
      *(undefined8 *)(iVar6 + -0x100 + iVar5) = *(undefined8 *)(iVar6 + iVar5);
    }
    *(undefined1 *)(glContext + 0x4a18) = 1;
  }
  iVar5 = 0;
  iVar2 = *(int *)(glContext + 0x4858);
  iVar7 = iVar3 * 8;
  iVar4 = iVar3 * -8;
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    iVar1 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar6 + iVar1) = *(undefined8 *)(iVar2 + iVar4 + iVar1);
  }
  *(int *)(glContext + 0x4858) = iVar6 + iVar7;
  return;
}

/* _gleVPFlushLineLoopTCLRDirty @ 0x106368 (252 bytes) */
void _gleVPFlushLineLoopTCLRDirty(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar6 = *(int *)(glContext + 0x4854);
  iVar3 = (int)*(short *)(glContext + 0x487c) >> 3;
  if (*(char *)(glContext + 0x4a18) == '\0') {
    iVar4 = 0;
    for (iVar7 = iVar3; iVar7 != 0; iVar7 = iVar7 + -1) {
      iVar5 = iVar4 * 8;
      iVar4 = iVar4 + 1;
      *(undefined8 *)(iVar6 + -0x100 + iVar5) = *(undefined8 *)(iVar6 + iVar5);
    }
    *(undefined1 *)(glContext + 0x4a18) = 1;
  }
  iVar5 = 0;
  iVar2 = *(int *)(glContext + 0x4858);
  iVar7 = iVar3 * 8;
  iVar4 = iVar3 * -8;
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    iVar1 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar6 + iVar1) = *(undefined8 *)(iVar2 + iVar4 + iVar1);
  }
  *(int *)(glContext + 0x4858) = iVar6 + iVar7;
  return;
}

/* _gleVPFlushLineStrip @ 0x106464 (176 bytes) */
void _gleVPFlushLineStrip(glContext)
  int glContext;
{
  int vertexStrideBytes;
  int copyIndex;
  int writeCursor;
  int strideDwordsThenRemaining;
  int remaining;
  int bufferStart;
  undefined8 savedLastVertex [32];
  
  strideDwordsThenRemaining = (int)*(short *)(glContext + 0x487c) >> 3;
  writeCursor = *(int *)(glContext + 0x4858);
  vertexStrideBytes = strideDwordsThenRemaining * 8;
  copyIndex = 0;
  for (remaining = strideDwordsThenRemaining; remaining != 0; remaining = remaining + -1) {
    savedLastVertex[copyIndex] = *(undefined8 *)(writeCursor + strideDwordsThenRemaining * -8 + copyIndex * 8);
    copyIndex = copyIndex + 1;
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  bufferStart = *(int *)(glContext + 0x4854);
  copyIndex = 0;
  for (; strideDwordsThenRemaining != 0; strideDwordsThenRemaining = strideDwordsThenRemaining + -1) {
    *(undefined8 *)(bufferStart + copyIndex * 8) = savedLastVertex[copyIndex];
    copyIndex = copyIndex + 1;
  }
  *(int *)(glContext + 0x4858) = bufferStart + vertexStrideBytes;
  return;
}

/* _gleVPFlushLineStripTCL @ 0x106514 (128 bytes) */
void _gleVPFlushLineStripTCL(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar5 = 0;
  iVar4 = *(int *)(glContext + 0x4858);
  iVar6 = (int)*(short *)(glContext + 0x487c) >> 3;
  iVar1 = iVar6 * 8;
  *(undefined1 *)(glContext + 0x4a18) = 1;
  iVar3 = iVar6 * -8;
  iVar7 = *(int *)(glContext + 0x4854);
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    iVar2 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar7 + iVar2) = *(undefined8 *)(iVar4 + iVar3 + iVar2);
  }
  *(int *)(glContext + 0x4858) = iVar7 + iVar1;
  return;
}

/* _gleVPFlushLineStripTCLRDirty @ 0x106594 (200 bytes) */
void _gleVPFlushLineStripTCLRDirty(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  int vertexStrideBytes;
  int copyByteOffset;
  int lastVertexDelta;
  int writeCursor;
  int copyIndex;
  int strideDwordsThenRemaining;
  int bufferStart;
  
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  copyIndex = 0;
  writeCursor = *(int *)(glContext + 0x4858);
  strideDwordsThenRemaining = (int)*(short *)(glContext + 0x487c) >> 3;
  vertexStrideBytes = strideDwordsThenRemaining * 8;
  *(undefined1 *)(glContext + 0x4a18) = 1;
  lastVertexDelta = strideDwordsThenRemaining * -8;
  bufferStart = *(int *)(glContext + 0x4854);
  for (; strideDwordsThenRemaining != 0; strideDwordsThenRemaining = strideDwordsThenRemaining + -1) {
    copyByteOffset = copyIndex * 8;
    copyIndex = copyIndex + 1;
    *(undefined8 *)(bufferStart + copyByteOffset) = *(undefined8 *)(writeCursor + lastVertexDelta + copyByteOffset);
  }
  *(int *)(glContext + 0x4858) = bufferStart + vertexStrideBytes;
  return;
}

/* _gleVPFlushTriQuadStrip @ 0x10665c (168 bytes) */
void _gleVPFlushTriQuadStrip(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 local_210 [64];
  
  iVar4 = (int)*(short *)(glContext + 0x487c) >> 2;
  iVar3 = *(int *)(glContext + 0x4858);
  iVar1 = iVar4 * 8;
  iVar2 = 0;
  for (iVar5 = iVar4; iVar5 != 0; iVar5 = iVar5 + -1) {
    local_210[iVar2] = *(undefined8 *)(iVar3 + iVar4 * -8 + iVar2 * 8);
    iVar2 = iVar2 + 1;
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar5 = *(int *)(glContext + 0x4854);
  iVar2 = 0;
  for (; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined8 *)(iVar5 + iVar2 * 8) = local_210[iVar2];
    iVar2 = iVar2 + 1;
  }
  *(int *)(glContext + 0x4858) = iVar5 + iVar1;
  return;
}

/* _gleVPFlushTriQuadStripTCL @ 0x106704 (120 bytes) */
void _gleVPFlushTriQuadStripTCL(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar5 = 0;
  iVar7 = *(int *)(glContext + 0x4854);
  iVar6 = (int)*(short *)(glContext + 0x487c) >> 2;
  iVar4 = *(int *)(glContext + 0x4858);
  iVar1 = iVar6 * 8;
  iVar3 = iVar6 * -8;
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    iVar2 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar7 + iVar2) = *(undefined8 *)(iVar4 + iVar3 + iVar2);
  }
  *(int *)(glContext + 0x4858) = iVar7 + iVar1;
  return;
}

/* _gleVPFlushTriQuadStripTCLRDirty @ 0x10677c (192 bytes) */
void _gleVPFlushTriQuadStripTCLRDirty(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar5 = 0;
  iVar7 = *(int *)(glContext + 0x4854);
  iVar6 = (int)*(short *)(glContext + 0x487c) >> 2;
  iVar4 = *(int *)(glContext + 0x4858);
  iVar1 = iVar6 * 8;
  iVar3 = iVar6 * -8;
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    iVar2 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar7 + iVar2) = *(undefined8 *)(iVar4 + iVar3 + iVar2);
  }
  *(int *)(glContext + 0x4858) = iVar7 + iVar1;
  return;
}

/* _gleVPFlushTriangleFan @ 0x10683c (252 bytes) */
void _gleVPFlushTriangleFan(glContext)
  int glContext;
{
  undefined8 *copyDestinationCursor;
  undefined8 *restoreSourceCursor;
  undefined8 *lastVertexSourceThenSecondSlot;
  int doublewordsPerVertex;
  int bufferStart;
  int counterThenCopyIndex;
  int copyIndexThenCounter;
  undefined8 copiedDoubleword;
  undefined8 firstVertexCopy [32];
  undefined8 lastVertexCopy [33];
  
  bufferStart = *(int *)(glContext + 0x4854);
  doublewordsPerVertex = (int)*(short *)(glContext + 0x487c) >> 3;
  lastVertexSourceThenSecondSlot = (undefined8 *)(*(int *)(glContext + 0x4858) + doublewordsPerVertex * -8);
  copyIndexThenCounter = 0;
  for (counterThenCopyIndex = doublewordsPerVertex; counterThenCopyIndex != 0; counterThenCopyIndex = counterThenCopyIndex + -1) {
    firstVertexCopy[copyIndexThenCounter] = *(undefined8 *)(bufferStart + copyIndexThenCounter * 8);
    copyIndexThenCounter = copyIndexThenCounter + 1;
  }
  if (doublewordsPerVertex != 0) {
    copyDestinationCursor = lastVertexCopy;
    copyIndexThenCounter = doublewordsPerVertex;
    do {
      copiedDoubleword = *lastVertexSourceThenSecondSlot;
      lastVertexSourceThenSecondSlot = lastVertexSourceThenSecondSlot + 1;
      *copyDestinationCursor = copiedDoubleword;
      copyDestinationCursor = copyDestinationCursor + 1;
      copyIndexThenCounter = copyIndexThenCounter + -1;
    } while (copyIndexThenCounter != 0);
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  counterThenCopyIndex = 0;
  for (copyIndexThenCounter = doublewordsPerVertex; copyIndexThenCounter != 0; copyIndexThenCounter = copyIndexThenCounter + -1) {
    *(undefined8 *)(bufferStart + counterThenCopyIndex * 8) = firstVertexCopy[counterThenCopyIndex];
    counterThenCopyIndex = counterThenCopyIndex + 1;
  }
  lastVertexSourceThenSecondSlot = (undefined8 *)(bufferStart + doublewordsPerVertex * 8);
  if (doublewordsPerVertex != 0) {
    restoreSourceCursor = lastVertexCopy;
    copyDestinationCursor = lastVertexSourceThenSecondSlot;
    copyIndexThenCounter = doublewordsPerVertex;
    do {
      copiedDoubleword = *restoreSourceCursor;
      restoreSourceCursor = restoreSourceCursor + 1;
      *copyDestinationCursor = copiedDoubleword;
      copyDestinationCursor = copyDestinationCursor + 1;
      copyIndexThenCounter = copyIndexThenCounter + -1;
    } while (copyIndexThenCounter != 0);
  }
  *(undefined8 **)(glContext + 0x4858) = lastVertexSourceThenSecondSlot + doublewordsPerVertex;
  return;
}

/* _gleVPFlushTriangleFanTCL @ 0x106938 (124 bytes) */
void _gleVPFlushTriangleFanTCL(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar6 = 0;
  iVar7 = (int)*(short *)(glContext + 0x487c) >> 3;
  iVar4 = *(int *)(glContext + 0x4858);
  iVar1 = iVar7 * 8;
  iVar3 = iVar7 * -8;
  iVar5 = *(int *)(glContext + 0x4854) + iVar1;
  for (; iVar7 != 0; iVar7 = iVar7 + -1) {
    iVar2 = iVar6 * 8;
    iVar6 = iVar6 + 1;
    *(undefined8 *)(iVar5 + iVar2) = *(undefined8 *)(iVar4 + iVar3 + iVar2);
  }
  *(int *)(glContext + 0x4858) = iVar5 + iVar1;
  return;
}

/* _gleVPFlushTriangleFanTCLRDirty @ 0x1069b4 (196 bytes) */
void _gleVPFlushTriangleFanTCLRDirty(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar6 = 0;
  iVar7 = (int)*(short *)(glContext + 0x487c) >> 3;
  iVar4 = *(int *)(glContext + 0x4858);
  iVar1 = iVar7 * 8;
  iVar3 = iVar7 * -8;
  iVar5 = *(int *)(glContext + 0x4854) + iVar1;
  for (; iVar7 != 0; iVar7 = iVar7 + -1) {
    iVar2 = iVar6 * 8;
    iVar6 = iVar6 + 1;
    *(undefined8 *)(iVar5 + iVar2) = *(undefined8 *)(iVar4 + iVar3 + iVar2);
  }
  *(int *)(glContext + 0x4858) = iVar5 + iVar1;
  return;
}

/* _gleVPFlushPolygon @ 0x106a78 (324 bytes) */
void _gleVPFlushPolygon(glContext)
  int glContext;
{
  uint flagWordOffset;
  undefined8 *puVar2;
  undefined4 incomingR4;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  uint uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  int vertexQwordCount;
  uint *vertexFlagBits;
  uint oldFlagWord;
  int batchStart;
  int iVar10;
  int iVar11;
  undefined8 copyWord;
  undefined8 firstVertexCopy [32];
  undefined8 lastVertexCopy [32];
  
  batchStart = *(int *)(glContext + 0x4854);
  vertexQwordCount = (int)*(short *)(glContext + 0x487c) >> 3;
  puVar5 = (undefined8 *)(*(int *)(glContext + 0x4858) + vertexQwordCount * -8);
  iVar11 = 0;
  for (iVar10 = vertexQwordCount; iVar10 != 0; iVar10 = iVar10 + -1) {
    firstVertexCopy[iVar11] = *(undefined8 *)(batchStart + iVar11 * 8);
    iVar11 = iVar11 + 1;
  }
  if (vertexQwordCount != 0) {
    puVar4 = lastVertexCopy;
    puVar2 = puVar5;
    iVar11 = vertexQwordCount;
    do {
      copyWord = *puVar2;
      puVar2 = puVar2 + 1;
      *puVar4 = copyWord;
      puVar4 = puVar4 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  vertexFlagBits = *(uint **)(glContext + 0x30b0);
  uVar3 = (uint)((int)puVar5 - batchStart) / (uint)(vertexQwordCount * 8);
  flagWordOffset = uVar3 >> 3 & 0x1ffffffc;
  uVar3 = uVar3 & 0x1f;
  oldFlagWord = *(uint *)(flagWordOffset + (int)vertexFlagBits);
  *(uint *)(flagWordOffset + (int)vertexFlagBits) = oldFlagWord & ~(1 << uVar3);
  (**(code **)(glContext + 0x4a08))(glContext,incomingR4,incomingR5,incomingR6,incomingR7,incomingR8,uVar3);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  *vertexFlagBits = *vertexFlagBits & 0xfffffffc | (oldFlagWord >> uVar3 & 1) << 1;
  iVar10 = 0;
  for (iVar11 = vertexQwordCount; iVar11 != 0; iVar11 = iVar11 + -1) {
    *(undefined8 *)(batchStart + iVar10 * 8) = firstVertexCopy[iVar10];
    iVar10 = iVar10 + 1;
  }
  puVar5 = (undefined8 *)(batchStart + vertexQwordCount * 8);
  if (vertexQwordCount != 0) {
    puVar4 = lastVertexCopy;
    puVar2 = puVar5;
    iVar11 = vertexQwordCount;
    do {
      copyWord = *puVar4;
      puVar4 = puVar4 + 1;
      *puVar2 = copyWord;
      puVar2 = puVar2 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  *(undefined8 **)(glContext + 0x4858) = puVar5 + vertexQwordCount;
  return;
}

/* _gleVPFlushPolygonTCL @ 0x106bbc (196 bytes) */
void _gleVPFlushPolygonTCL(glContext)
  int glContext;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 incomingR4;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  
  iVar6 = (int)*(short *)(glContext + 0x487c) >> 3;
  uVar1 = iVar6 * 8;
  puVar8 = *(uint **)(glContext + 0x30b0);
  iVar7 = *(int *)(glContext + 0x4858) + iVar6 * -8;
  iVar10 = *(int *)(glContext + 0x4854) + uVar1;
  uVar4 = (uint)(iVar7 - *(int *)(glContext + 0x4854)) / uVar1;
  uVar3 = uVar4 >> 3 & 0x1ffffffc;
  uVar4 = uVar4 & 0x1f;
  uVar9 = *(uint *)(uVar3 + (int)puVar8);
  *(uint *)(uVar3 + (int)puVar8) = uVar9 & ~(1 << uVar4);
  (**(code **)(glContext + 0x4a08))(glContext,incomingR4,incomingR5,incomingR6,incomingR7,incomingR8,uVar4);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  iVar5 = 0;
  *puVar8 = *puVar8 & 0xfffffffc | (uVar9 >> uVar4 & 1) << 1;
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    iVar2 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar10 + iVar2) = *(undefined8 *)(iVar7 + iVar2);
  }
  *(uint *)(glContext + 0x4858) = iVar10 + uVar1;
  return;
}

/* _gleVPFlushPolygonTCLRDirty @ 0x106c80 (268 bytes) */
void _gleVPFlushPolygonTCLRDirty(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 incomingR4;
  undefined4 r4AfterCall;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
    incomingR4 = r4AfterCall;
  }
  iVar6 = (int)*(short *)(glContext + 0x487c) >> 3;
  uVar1 = iVar6 * 8;
  puVar8 = *(uint **)(glContext + 0x30b0);
  iVar7 = *(int *)(glContext + 0x4858) + iVar6 * -8;
  iVar10 = *(int *)(glContext + 0x4854) + uVar1;
  uVar4 = (uint)(iVar7 - *(int *)(glContext + 0x4854)) / uVar1;
  uVar3 = uVar4 >> 3 & 0x1ffffffc;
  uVar4 = uVar4 & 0x1f;
  uVar9 = *(uint *)(uVar3 + (int)puVar8);
  *(uint *)(uVar3 + (int)puVar8) = uVar9 & ~(1 << uVar4);
  (**(code **)(glContext + 0x4a08))(glContext,incomingR4,incomingR5,incomingR6,incomingR7,incomingR8,uVar4);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  iVar5 = 0;
  *puVar8 = *puVar8 & 0xfffffffc | (uVar9 >> uVar4 & 1) << 1;
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    iVar2 = iVar5 * 8;
    iVar5 = iVar5 + 1;
    *(undefined8 *)(iVar10 + iVar2) = *(undefined8 *)(iVar7 + iVar2);
  }
  *(uint *)(glContext + 0x4858) = iVar10 + uVar1;
  return;
}

/* _gleVPBeginPoints @ 0x106d8c (60 bytes) */
void _gleVPBeginPoints(glContext)
  int glContext;
{
  undefined *vpRenderPoints;
  undefined *vpFlushAtomic;
  
  *(undefined4 *)(glContext + 0x486c) = 0;
  vpFlushAtomic = PTR__gleVPFlushAtomic_00111668;
  vpRenderPoints = PTR__gleVPRenderPoints_00111664;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomic;
  *(undefined **)(glContext + 0x4a08) = vpRenderPoints;
  return;
}

/* _gleVPBeginLines @ 0x106dc8 (60 bytes) */
void _gleVPBeginLines(glContext)
  int glContext;
{
  undefined *vpRenderLines;
  undefined *vpFlushAtomic;
  
  *(undefined4 *)(glContext + 0x486c) = 0;
  vpFlushAtomic = PTR__gleVPFlushAtomic_00111668;
  vpRenderLines = PTR__gleVPRenderLines_00111660;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomic;
  *(undefined **)(glContext + 0x4a08) = vpRenderLines;
  return;
}

/* _gleVPBeginLineLoop @ 0x106e04 (68 bytes) */
void _gleVPBeginLineLoop(glContext)
  int glContext;
{
  undefined *vpRenderLineLoop;
  undefined *vpFlushLineLoop;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  vpFlushLineLoop = PTR__gleVPFlushLineLoop_0011165c;
  vpRenderLineLoop = PTR__gleVPRenderLineLoop_00111658;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined **)(glContext + 0x4a0c) = vpFlushLineLoop;
  *(undefined **)(glContext + 0x4a08) = vpRenderLineLoop;
  return;
}

/* _gleVPBeginLineStrip @ 0x106e48 (68 bytes) */
void _gleVPBeginLineStrip(glContext)
  int glContext;
{
  undefined *vpRenderLineStrip;
  undefined *vpFlushLineStrip;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  vpFlushLineStrip = PTR__gleVPFlushLineStrip_00111654;
  vpRenderLineStrip = PTR__gleVPRenderLineStrip_00111650;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined **)(glContext + 0x4a0c) = vpFlushLineStrip;
  *(undefined **)(glContext + 0x4a08) = vpRenderLineStrip;
  return;
}

/* _gleVPBeginTriangles @ 0x106e8c (60 bytes) */
void _gleVPBeginTriangles(glContext)
  int glContext;
{
  undefined *vpRenderTriangles;
  undefined *vpFlushAtomic;
  
  *(undefined4 *)(glContext + 0x486c) = 0;
  vpFlushAtomic = PTR__gleVPFlushAtomic_00111668;
  vpRenderTriangles = PTR__gleVPRenderTriangles_0011164c;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomic;
  *(undefined **)(glContext + 0x4a08) = vpRenderTriangles;
  return;
}

/* _gleVPBeginTriangleStrip @ 0x106ec8 (60 bytes) */
void _gleVPBeginTriangleStrip(glContext)
  int glContext;
{
  undefined *vpRenderTriangleStrip;
  undefined *vpFlushTriQuadStrip;
  
  *(undefined4 *)(glContext + 0x486c) = 0;
  vpFlushTriQuadStrip = PTR__gleVPFlushTriQuadStrip_00111648;
  vpRenderTriangleStrip = PTR__gleVPRenderTriangleStrip_00111644;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushTriQuadStrip;
  *(undefined **)(glContext + 0x4a08) = vpRenderTriangleStrip;
  return;
}

/* _gleVPBeginTriangleFan @ 0x106f04 (60 bytes) */
void _gleVPBeginTriangleFan(glContext)
  int glContext;
{
  undefined *vpRenderTriangleFan;
  undefined *vpFlushTriangleFan;
  
  *(undefined4 *)(glContext + 0x486c) = 0;
  vpFlushTriangleFan = PTR__gleVPFlushTriangleFan_00111640;
  vpRenderTriangleFan = PTR__gleVPRenderTriangleFan_0011163c;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushTriangleFan;
  *(undefined **)(glContext + 0x4a08) = vpRenderTriangleFan;
  return;
}

/* _gleVPBeginQuads @ 0x106f40 (60 bytes) */
void _gleVPBeginQuads(glContext)
  int glContext;
{
  undefined *vpRenderQuads;
  undefined *vpFlushAtomic;
  
  *(undefined4 *)(glContext + 0x486c) = 0;
  vpFlushAtomic = PTR__gleVPFlushAtomic_00111668;
  vpRenderQuads = PTR__gleVPRenderQuads_00111638;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomic;
  *(undefined **)(glContext + 0x4a08) = vpRenderQuads;
  return;
}

/* _gleVPBeginQuadStrip @ 0x106f7c (60 bytes) */
void _gleVPBeginQuadStrip(glContext)
  int glContext;
{
  undefined *vpRenderQuadStrip;
  undefined *vpFlushTriQuadStrip;
  
  *(undefined4 *)(glContext + 0x486c) = 0;
  vpFlushTriQuadStrip = PTR__gleVPFlushTriQuadStrip_00111648;
  vpRenderQuadStrip = PTR__gleVPRenderQuadStrip_00111634;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushTriQuadStrip;
  *(undefined **)(glContext + 0x4a08) = vpRenderQuadStrip;
  return;
}

/* _gleVPBeginPolygon @ 0x106fb8 (68 bytes) */
void _gleVPBeginPolygon(glContext)
  int glContext;
{
  undefined *vpRenderPolygon;
  undefined *vpFlushPolygon;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  vpFlushPolygon = PTR__gleVPFlushPolygon_00111630;
  vpRenderPolygon = PTR__gleVPRenderPolygon_0011162c;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined **)(glContext + 0x4a0c) = vpFlushPolygon;
  *(undefined **)(glContext + 0x4a08) = vpRenderPolygon;
  return;
}

/* _gleVPBeginPointsTCL @ 0x106ffc (52 bytes) */
void _gleVPBeginPointsTCL(glContext)
  int glContext;
{
  undefined *vpFlushAtomicTCL;
  
  vpFlushAtomicTCL = PTR__gleVPFlushAtomicTCL_00111628;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomicTCL;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderPointsTCLFunc_0011223c;
  return;
}

/* _gleVPBeginLinesTCL @ 0x107030 (52 bytes) */
void _gleVPBeginLinesTCL(glContext)
  int glContext;
{
  undefined *vpFlushAtomicTCL;
  
  vpFlushAtomicTCL = PTR__gleVPFlushAtomicTCL_00111628;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomicTCL;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderLinesTCLFunc_00112214;
  return;
}

/* _gleVPBeginLineLoopTCL @ 0x107064 (60 bytes) */
void _gleVPBeginLineLoopTCL(glContext)
  int glContext;
{
  undefined *vpFlushLineLoopTCL;
  undefined *renderLineLoopTCLFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  renderLineLoopTCLFunc = PTR__gleRenderLineLoopTCLFunc_001121d4;
  vpFlushLineLoopTCL = PTR__gleVPFlushLineLoopTCL_00111624;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushLineLoopTCL;
  *(undefined **)(glContext + 0x4a08) = renderLineLoopTCLFunc;
  return;
}

/* _gleVPBeginLineStripTCL @ 0x1070a0 (60 bytes) */
void _gleVPBeginLineStripTCL(glContext)
  int glContext;
{
  undefined *vpFlushLineStripTCL;
  undefined *renderLineStripTCLFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  renderLineStripTCLFunc = PTR__gleRenderLineStripTCLFunc_001121f4;
  vpFlushLineStripTCL = PTR__gleVPFlushLineStripTCL_00111620;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushLineStripTCL;
  *(undefined **)(glContext + 0x4a08) = renderLineStripTCLFunc;
  return;
}

/* _gleVPBeginTrianglesTCL @ 0x1070dc (52 bytes) */
void _gleVPBeginTrianglesTCL(glContext)
  int glContext;
{
  undefined *vpFlushAtomicTCL;
  
  vpFlushAtomicTCL = PTR__gleVPFlushAtomicTCL_00111628;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomicTCL;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderTrianglesTCLFunc_001122d4;
  return;
}

/* _gleVPBeginTriangleStripTCL @ 0x107110 (52 bytes) */
void _gleVPBeginTriangleStripTCL(glContext)
  int glContext;
{
  undefined *vpFlushTriQuadStripTCL;
  
  vpFlushTriQuadStripTCL = PTR__gleVPFlushTriQuadStripTCL_0011161c;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushTriQuadStripTCL;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderTriangleStripTCLFunc_001122b8;
  return;
}

/* _gleVPBeginTriangleFanTCL @ 0x107144 (52 bytes) */
void _gleVPBeginTriangleFanTCL(glContext)
  int glContext;
{
  undefined *vpFlushTriangleFanTCL;
  
  vpFlushTriangleFanTCL = PTR__gleVPFlushTriangleFanTCL_00111618;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushTriangleFanTCL;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderTriangleFanTCLFunc_00112298;
  return;
}

/* _gleVPBeginQuadsTCL @ 0x107178 (52 bytes) */
void _gleVPBeginQuadsTCL(glContext)
  int glContext;
{
  undefined *vpFlushAtomicTCL;
  
  vpFlushAtomicTCL = PTR__gleVPFlushAtomicTCL_00111628;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = vpFlushAtomicTCL;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderQuadsTCLFunc_00112280;
  return;
}

