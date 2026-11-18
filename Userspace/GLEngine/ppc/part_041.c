#include "decls.h"

/* _gleRTCBuildABranch_c5274 @ 0xc5274 (12 bytes) */
int _gleRTCBuildABranch_c5274(branchInstruction, branchWordOffset)
  uint branchInstruction;
  uint branchWordOffset;
{
  return (branchWordOffset & 0x3fff) << 2 | branchInstruction & 0xffff0003;
}

/* _gleRTCAddAChunk_c5280 @ 0xc5280 (48 bytes) */
int _gleRTCAddAChunk_c5280(srcCursor, dstCursor)
  int *srcCursor;
  int *dstCursor;
{
  int word;
  int copiedWords;
  
  copiedWords = 0;
  word = *srcCursor;
  while (word != 0) {
    *dstCursor = word;
    copiedWords = copiedWords + 1;
    srcCursor = srcCursor + 1;
    dstCursor = dstCursor + 1;
    word = *srcCursor;
  }
  return copiedWords;
}

/* _gleSetNormalFunc @ 0xc52b0 (96 bytes) */
void _gleSetNormalFunc(glContext, param_2, param_3)
  int glContext;
  undefined4 param_2;
  undefined4 param_3;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)(*_gleBuildNormalTransformFunc)(glContext,param_2,param_3);
  *(code **)(glContext + 0x5068) = UNRECOVERED_JUMPTABLE;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(glContext,param_2,param_3);
  return;
}

/* _gleTransformNormalBlend @ 0xc5310 (468 bytes) */
void _gleTransformNormalBlend(int glContext,uint vertexArrayThenCursor,int vertexCount,double fparam_1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  byte blendUnitCount;
  float matrix00;
  float matrix01;
  float matrix10;
  float matrix11;
  float matrix12;
  float matrix20;
  float matrix21;
  float matrix22;
  float normalY;
  float normalZ;
  float blendWeight;
  int vertexBytes;
  undefined *vectorNormalize;
  int blendMatrixCursor;
  int loopIndex;
  uint vertexCursor;
  uint verticesLeft;
  float normalX;
  
  vertexBytes = vertexCount * 0x100;
  blendUnitCount = *(byte *)(glContext + 0x4660);
  if (vertexArrayThenCursor < vertexArrayThenCursor + vertexBytes) {
    verticesLeft = ((vertexArrayThenCursor + vertexBytes) - vertexArrayThenCursor) + 0xff >> 8;
    vertexCursor = vertexArrayThenCursor;
    do {
      *(undefined4 *)(vertexCursor + 0xf0) = 0;
      *(undefined4 *)(vertexCursor + 0xf4) = 0;
      *(undefined4 *)(vertexCursor + 0xf8) = 0;
      vertexCursor = vertexCursor + 0x100;
      verticesLeft = verticesLeft - 1;
    } while (verticesLeft != 0);
  }
  loopIndex = 0;
  if (blendUnitCount != 0) {
    blendMatrixCursor = glContext;
    do {
      matrix00 = *(float *)(blendMatrixCursor + 0x22c0);
      matrix01 = *(float *)(blendMatrixCursor + 0x22c4);
      fparam_1 = (double)*(float *)(blendMatrixCursor + 0x22c8);
      matrix10 = *(float *)(blendMatrixCursor + 0x22d0);
      matrix11 = *(float *)(blendMatrixCursor + 0x22d4);
      matrix12 = *(float *)(blendMatrixCursor + 0x22d8);
      matrix20 = *(float *)(blendMatrixCursor + 0x22e0);
      matrix21 = *(float *)(blendMatrixCursor + 0x22e4);
      matrix22 = *(float *)(blendMatrixCursor + 0x22e8);
      if (vertexArrayThenCursor < vertexArrayThenCursor + vertexBytes) {
        verticesLeft = ((vertexArrayThenCursor + vertexBytes) - vertexArrayThenCursor) + 0xff >> 8;
        vertexCursor = vertexArrayThenCursor;
        do {
          normalY = *(float *)(vertexCursor + 0x44);
          normalX = (double)*(float *)(vertexCursor + 0x40);
          normalZ = *(float *)(vertexCursor + 0x48);
          blendWeight = *(float *)(loopIndex * 4 + vertexCursor + 0x60);
          *(float *)(vertexCursor + 0xf0) =
               blendWeight * (normalZ * matrix20 + (normalX * matrix00 + (normalY * matrix10))
                        ) + *(float *)(vertexCursor + 0xf0);
          *(float *)(vertexCursor + 0xf8) =
               blendWeight * (normalZ * matrix22 + (float)((double)normalX * fparam_1 + (double)(normalY * matrix12))) +
               *(float *)(vertexCursor + 0xf8);
          *(float *)(vertexCursor + 0xf4) =
               blendWeight * (normalZ * matrix21 + (normalX * matrix01 + (normalY * matrix11))
                        ) + *(float *)(vertexCursor + 0xf4);
          vertexCursor = vertexCursor + 0x100;
          verticesLeft = verticesLeft - 1;
        } while (verticesLeft != 0);
      }
      loopIndex = loopIndex + 1;
      blendMatrixCursor = blendMatrixCursor + 0x40;
    } while (loopIndex < (int)(uint)blendUnitCount);
  }
  vectorNormalize = PTR__gleVectorNormalize_00112064;
  verticesLeft = vertexArrayThenCursor + vertexBytes;
  if (*(char *)(glContext + 0x280d) == '\0') {
    if (vertexArrayThenCursor < verticesLeft) {
      verticesLeft = (verticesLeft - vertexArrayThenCursor) + 0xff >> 8;
      do {
        *(undefined4 *)(vertexArrayThenCursor + 0x40) = *(undefined4 *)(vertexArrayThenCursor + 0xf0);
        *(undefined4 *)(vertexArrayThenCursor + 0x44) = *(undefined4 *)(vertexArrayThenCursor + 0xf4);
        *(undefined4 *)(vertexArrayThenCursor + 0x48) = *(undefined4 *)(vertexArrayThenCursor + 0xf8);
        vertexArrayThenCursor = vertexArrayThenCursor + 0x100;
        verticesLeft = verticesLeft - 1;
      } while (verticesLeft != 0);
    }
  }
  else {
    for (; vertexArrayThenCursor < verticesLeft; vertexArrayThenCursor = vertexArrayThenCursor + 0x100) {
      fparam_1 = (double)(**(double ( **)(int,int,int,double))vectorNormalize)(glContext, vertexArrayThenCursor + 0xf0, vertexArrayThenCursor + 0x40, fparam_1);
    }
  }
  return;
}

/* _gleBuildNormalTransformFuncAV_body @ 0xc54e8 (852 bytes) */
int _gleBuildNormalTransformFuncAV_body(glContext)
  int glContext;
{
  uint uVar1;
  int iVar2;
  int chunkWordCount2;
  int chunkWordCount3;
  undefined *puVar5;
  undefined *codeChunk;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  int iVar10;
  int chunkWordCount;
  undefined4 *puVar11;
  int *piVar12;
  int *piVar13;
  
  piVar13 = (int *)PTR__gleTransformNormalBlend_00110a04;
  if (*(char *)(glContext + 0x4661) == '\0') {
    uVar1 = (**(code **)PTR__gleGenerateMatrixIdentifier_00112060)(glContext,glContext + 0x22c0);
    *(uint *)(glContext + 0x509c) = uVar1;
    uVar8 = (uint)*(byte *)(glContext + 0x280d);
    if ((uVar1 & 0x3cccf000) == 0x3cccf000) {
      iVar10 = 0x3fcff3ff;
      if ((uVar1 & 0xfcfcfc00) == 0xbcecf800) {
        iVar10 = -0x40100401;
      }
    }
    else {
      iVar10 = 0x30303ff;
    }
    piVar12 = *(int **)(glContext + 0x50a0);
    piVar13 = piVar12;
    do {
      if (iVar10 == piVar13[2] && uVar8 == piVar13[3]) {
        if (piVar13 != piVar12) {
          _gleMoveFuncCacheElem(piVar12,piVar13);
          *(int **)(glContext + 0x50a0) = piVar13;
        }
        return piVar13 + 8;
      }
      piVar13 = (int *)*piVar13;
    } while (piVar13 != piVar12);
    iVar2 = _gleCreateFuncCacheElem(piVar13,0x78);
    piVar13 = (int *)PTR__gleRTCNoop_00112058;
    if (iVar2 != 0) {
      *(int *)(iVar2 + 8) = iVar10;
      *(uint *)(iVar2 + 0xc) = uVar8;
      if (*(short *)(glContext + 0x50a6) == *(short *)(glContext + 0x50a4)) {
        _gleDeleteFuncCacheElem(*(undefined4 *)(iVar2 + 4));
      }
      else {
        *(short *)(glContext + 0x50a6) = *(short *)(glContext + 0x50a6) + 1;
      }
      puVar9 = (undefined4 *)(iVar2 + 0x20);
      if ((uVar8 != 0) || (iVar10 != -0x40100401)) {
        chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c5280)(&_glePrologAVRTC_10f4e8,puVar9);
        puVar7 = puVar9 + chunkWordCount2;
        if (iVar10 != -0x40100401) {
          chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleLoadMatrixPtrRTC_10f4cc,puVar7);
          chunkWordCount3 = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleLoadMatrixVectorsRTC_10f540,puVar7 + chunkWordCount2);
          puVar7 = puVar7 + chunkWordCount2 + chunkWordCount3;
        }
        if (iVar10 == 0x30303ff) {
          chunkWordCount = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleLoadVectorsRTC_10f5c4,puVar7);
          puVar9 = puVar7 + chunkWordCount;
          codeChunk = &_gleFullMatrixMultRTC_10f564;
        }
        else if (iVar10 == 0x3fcff3ff) {
          chunkWordCount = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleDiagMatrixSetupRTC_10f598,puVar7);
          puVar7 = puVar7 + chunkWordCount;
          chunkWordCount = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleLoadVectorsRTC_10f5c4,puVar7);
          puVar9 = puVar7 + chunkWordCount;
          codeChunk = &_gleDiagMatrixMultRTC_10f5ac;
        }
        else {
          chunkWordCount = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleLoadVectorsRTC_10f5c4,puVar7);
          puVar9 = puVar7 + chunkWordCount;
          codeChunk = &_gleIdentityMatrixMultRTC_10f5b8;
        }
        chunkWordCount = ((int (*)())_gleRTCAddAChunk_c5280)(codeChunk,puVar9);
        puVar9 = puVar9 + chunkWordCount;
        if (uVar8 != 0) {
          chunkWordCount = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleNormalizeAVRTC,puVar9);
          puVar9 = puVar9 + chunkWordCount;
        }
        chunkWordCount = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleStoreVectorsRTC_10f5d0,puVar9);
        puVar9 = puVar9 + chunkWordCount;
        chunkWordCount = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleEpilogAVRTC_10f534,puVar9);
        puVar11 = puVar9 + -1;
        puVar9 = puVar9 + chunkWordCount;
        uVar6 = ((int (*)())_gleRTCBuildABranch_c5274)(*puVar11,(int)puVar7 - (int)puVar11 >> 2);
        *puVar11 = uVar6;
      }
      iVar10 = (int)puVar9 + (-0x1c - iVar2) >> 2;
      *puVar9 = 0x4e800020;
      if (0x78 < iVar10) {
                    
        _exit(1);
      }
      iVar2 = _gleShrinkFuncCacheElem(iVar2,iVar10);
      puVar5 = PTR__glePushInstructions_00112054;
      *(int *)(glContext + 0x50a0) = iVar2;
      (**(code **)puVar5)(iVar10,(int *)(iVar2 + 0x20));
      piVar13 = (int *)(iVar2 + 0x20);
    }
  }
  return piVar13;
}

/* _gleBuildNormalTransformFuncNO_body @ 0xc5840 (1424 bytes) */
int _gleBuildNormalTransformFuncNO_body(glContext)
  int glContext;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  undefined *codeChunk;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int remaining;
  int chunkWordCount;
  uint uVar11;
  int *piVar12;
  int *piVar13;
  uint uVar14;
  uint *puVar15;
  uint uVar16;
  uint *puVar17;
  uint *codeCursor;
  int remaining2;
  int local_50 [13];
  
  if (*(char *)(glContext + 0x4661) != '\0') {
    return (int *)PTR__gleTransformNormalBlend_00110a04;
  }
  uVar4 = (**(code **)PTR__gleGenerateMatrixIdentifier_00112060)(glContext,glContext + 0x22c0);
  piVar12 = *(int **)(glContext + 0x50a0);
  uVar16 = (uint)*(byte *)(glContext + 0x280d);
  *(uint *)(glContext + 0x509c) = uVar4;
  uVar14 = uVar4 | 0x30303ff;
  piVar13 = piVar12;
  do {
    if (uVar14 == piVar13[2] && uVar16 == piVar13[3]) {
      if (piVar13 != piVar12) {
        _gleMoveFuncCacheElem(piVar12,piVar13);
        *(int **)(glContext + 0x50a0) = piVar13;
      }
      return piVar13 + 8;
    }
    piVar13 = (int *)*piVar13;
  } while (piVar13 != piVar12);
  iVar5 = _gleCreateFuncCacheElem(piVar13,0x50);
  if (iVar5 == 0) {
    return (int *)PTR__gleRTCNoop_00112058;
  }
  *(uint *)(iVar5 + 8) = uVar14;
  *(uint *)(iVar5 + 0xc) = uVar16;
  if (*(short *)(glContext + 0x50a6) == *(short *)(glContext + 0x50a4)) {
    _gleDeleteFuncCacheElem(*(undefined4 *)(iVar5 + 4));
  }
  else {
    *(short *)(glContext + 0x50a6) = *(short *)(glContext + 0x50a6) + 1;
  }
  bVar1 = uVar16 == 0;
  puVar17 = (uint *)(iVar5 + 0x20);
  if (bVar1) {
    if ((uVar4 & 0xfcfcfc00) == 0xbcecf800) goto LAB_000c5d58;
    iVar10 = 6;
  }
  else {
    iVar10 = 10;
  }
  if ((bVar1) || (uVar4 = 0xfffffff8, (*(uint *)PTR__gle_processor_0011204c & 1) != 0)) {
    uVar4 = 0;
  }
  bVar2 = false;
  remaining2 = 0xb;
  uVar16 = 0;
  piVar13 = local_50;
  do {
    if ((uVar14 << ((uVar16 & 0x1f) << 1) & 0xc0000000) == 0) {
      *piVar13 = iVar10;
      bVar2 = true;
      if (0xd < iVar10) {
        uVar4 = uVar4 - 8;
        *puVar17 = iVar10 << 0x15 | uVar4 & 0xffff | 0xd8010000;
        puVar17 = puVar17 + 1;
      }
      iVar10 = iVar10 + 1;
    }
    uVar16 = uVar16 + 1;
    piVar13 = piVar13 + 1;
    remaining2 = remaining2 + -1;
  } while (remaining2 != 0);
  if (bVar2) {
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleLoadMatrixPtrRTC_10f4cc,puVar17);
    puVar17 = puVar17 + chunkWordCount;
  }
  chunkWordCount = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleLoadCounterRTC_10f4e0,puVar17);
  codeCursor = puVar17 + chunkWordCount;
  uVar16 = 0;
  uVar4 = 0;
  remaining = 0xb;
  do {
    if ((uVar14 << (uVar4 & 0x3f) & 0xc0000000) == 0) {
      *codeCursor = *(int *)((int)local_50 + uVar16) << 0x15 | uVar16 & 0xffff | 0xc0060000;
      codeCursor = codeCursor + 1;
    }
    uVar4 = uVar4 + 2;
    uVar16 = uVar16 + 4;
    remaining = remaining + -1;
  } while (remaining != 0);
  remaining = 3;
  uVar4 = 0;
  uVar8 = 2;
  uVar16 = 0xa00000;
  do {
    if ((uVar14 << ((uVar8 & 0x1f) << 1) & 0xc0c0c0c0) == 0xc0c0c0c0) {
      if (uVar4 == 0) {
        uVar3 = uVar16 | 0xc0030020;
        uVar4 = uVar8;
      }
      else {
        uVar3 = uVar16 | (uVar4 + 3) * 0x800 | 0xfc000090;
      }
      *codeCursor = uVar3;
      codeCursor = codeCursor + 1;
    }
    uVar8 = uVar8 - 1;
    uVar16 = uVar16 - 0x200000;
    remaining = remaining + -1;
  } while (remaining != 0);
  if (!bVar1) {
    if ((*(uint *)PTR__gle_processor_0011204c & 1) == 0) {
      codeChunk = &_gleNormalizeInitNORTC;
    }
    else {
      codeChunk = &_gleNormalizeInitGRRTC;
    }
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c5280)(codeChunk,codeCursor);
    codeCursor = codeCursor + chunkWordCount;
  }
  remaining = 3;
  uVar9 = 2;
  uVar3 = 0x48;
  uVar16 = 0x48;
  uVar8 = 0xa00000;
  uVar7 = 0x14;
  uVar4 = uVar14;
  puVar17 = codeCursor;
  do {
    uVar11 = 0xc0c0c0c0 >> ((uVar9 & 0x1f) << 1);
    if (!bVar1) {
      uVar11 = uVar11 | 0xff000000U >> ((uVar9 & 7) << 3);
    }
    if (((uVar4 & uVar11) == (uVar11 & ~(0x40000000 >> (uVar7 & 0x3f)))) &&
       (uVar4 = uVar4 | uVar11, !bVar1)) {
      *puVar17 = uVar8 | uVar16 & 0xffff | 0xc0040000;
      puVar17 = puVar17 + 1;
    }
    uVar11 = 0xff000000 >> ((uVar9 & 7) << 3);
    if ((uVar4 & uVar11) != uVar11) {
      *puVar17 = uVar9 << 0x15 | uVar3 & 0xffff | 0xc0040000;
      puVar17 = puVar17 + 1;
    }
    uVar9 = uVar9 - 1;
    uVar7 = uVar7 - 10;
    uVar8 = uVar8 - 0x200000;
    uVar16 = uVar16 - 4;
    uVar3 = uVar3 - 4;
    remaining = remaining + -1;
  } while (remaining != 0);
  puVar17 = (uint *)_gleEmitTransformInstructions(puVar17,uVar4,local_50,0,3,0);
  if (!bVar1) {
    if ((*(uint *)PTR__gle_processor_0011204c & 1) == 0) {
      codeChunk = &_gleNormalizeNORTC;
    }
    else {
      codeChunk = &_gleNormalizeGRRTC;
    }
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c5280)(codeChunk,puVar17);
    puVar17 = puVar17 + chunkWordCount;
  }
  remaining = 3;
  uVar8 = 2;
  uVar16 = 0x48;
  uVar3 = 0xa00000;
  uVar4 = 0x14;
  do {
    uVar7 = 0xc0c0c0c0 >> ((uVar8 & 0x1f) << 1);
    if ((!bVar1) || ((uVar14 & uVar7) != (uVar7 & ~(0x40000000 >> (uVar4 & 0x3f))))) {
      *puVar17 = uVar3 | uVar16 & 0xffff | 0xd0040000;
      puVar17 = puVar17 + 1;
    }
    uVar8 = uVar8 - 1;
    uVar4 = uVar4 - 10;
    uVar3 = uVar3 - 0x200000;
    uVar16 = uVar16 - 4;
    remaining = remaining + -1;
  } while (remaining != 0);
  chunkWordCount = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleEndLoopRTC_10f4d4,puVar17);
  puVar17 = puVar17 + chunkWordCount;
  puVar15 = puVar17 + -1;
  if ((bVar1) || (uVar4 = 0xfffffff8, (*(uint *)PTR__gle_processor_0011204c & 1) != 0)) {
    uVar4 = 0;
  }
  uVar16 = 0;
  remaining = 0xb;
  piVar13 = local_50;
  do {
    if (((uVar14 << ((uVar16 & 0x1f) << 1) & 0xc0000000) == 0) && (0xd < *piVar13)) {
      uVar4 = uVar4 - 8;
      *puVar17 = *piVar13 << 0x15 | uVar4 & 0xffff | 0xc8010000;
      puVar17 = puVar17 + 1;
    }
    uVar16 = uVar16 + 1;
    piVar13 = piVar13 + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  uVar4 = ((int (*)())_gleRTCBuildABranch_c5274)(*puVar15,(int)codeCursor - (int)puVar15 >> 2);
  *puVar15 = uVar4;
LAB_000c5d58:
  iVar10 = (int)puVar17 + (-0x1c - iVar5) >> 2;
  *puVar17 = 0x4e800020;
  if (iVar10 < 0x51) {
    iVar5 = _gleShrinkFuncCacheElem(iVar5,iVar10);
    puVar6 = PTR__glePushInstructions_00112054;
    *(int *)(glContext + 0x50a0) = iVar5;
    (**(code **)puVar6)(iVar10,(int *)(iVar5 + 0x20));
    return (int *)(iVar5 + 0x20);
  }
                    
  _exit(1);
}

/* _gleRTCBuildABranch_c5dd0 @ 0xc5dd0 (12 bytes) */
int _gleRTCBuildABranch_c5dd0(branchInstruction, branchWordOffset)
  uint branchInstruction;
  uint branchWordOffset;
{
  return (branchWordOffset & 0x3fff) << 2 | branchInstruction & 0xffff0003;
}

/* _gleRTCAddAChunk_c5ddc @ 0xc5ddc (48 bytes) */
int _gleRTCAddAChunk_c5ddc(srcCursor, dstCursor)
  int *srcCursor;
  int *dstCursor;
{
  int word;
  int copiedWords;
  
  copiedWords = 0;
  word = *srcCursor;
  while (word != 0) {
    *dstCursor = word;
    copiedWords = copiedWords + 1;
    srcCursor = srcCursor + 1;
    dstCursor = dstCursor + 1;
    word = *srcCursor;
  }
  return copiedWords;
}

/* _gleSetProjectionFuncW1 @ 0xc5e0c (104 bytes) */
void _gleSetProjectionFuncW1(glContext, param_2, param_3)
  int glContext;
  undefined4 param_2;
  undefined4 param_3;
{
  code *pcVar1;
  
  pcVar1 = (code *)(*_gleBuildProjectionTransformFunc)(glContext,1,param_3);
  *(code **)(glContext + 0x5060) = pcVar1;
  (*pcVar1)(glContext,param_2,param_3);
  return;
}

/* _gleSetProjectionFuncZ0W1 @ 0xc5e74 (104 bytes) */
void _gleSetProjectionFuncZ0W1(glContext, param_2, param_3)
  int glContext;
  undefined4 param_2;
  undefined4 param_3;
{
  code *pcVar1;
  
  pcVar1 = (code *)(*_gleBuildProjectionTransformFunc)(glContext,3,param_3);
  *(code **)(glContext + 0x5060) = pcVar1;
  (*pcVar1)(glContext,param_2,param_3);
  return;
}

/* _gleTransformProjectionBlend @ 0xc5edc (1264 bytes) */
void _gleTransformProjectionBlend(int glContext,float *vertices,int vertexCount,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float weightOrBlendM1OrProjM3;
  float remainingWeightOrBlendM0OrClipBiasX;
  float blendM2OrClipBiasY;
  float blendM3OrProjM7;
  float blendM4OrProjM11;
  float blendM5OrProjM15;
  float blendM6OrClipScaleX;
  float blendM7OrClipScaleY;
  float blendM8OrProjM8;
  float blendM9OrProjM12;
  float blendM10OrViewportScaleX;
  float blendM11OrProjM5;
  float blendM12OrProjM0;
  float blendM13OrProjM1;
  float blendM14OrProjM4;
  float blendM15OrProjM9;
  float objectYOrProjM13;
  float objectXOrProjM14;
  float objectZOrProjM2;
  float objectWOrProjM6;
  float blendWeightOrProjM10;
  float viewportScaleY;
  float viewportScaleZ;
  float viewportOffsetY;
  float viewportOffsetX;
  float viewportOffsetZ;
  float eyeXThenClipY;
  float blendedEyeY;
  float blendedEyeZ;
  float blendedEyeW;
  float fogValueThenClipX;
  float fogFactorThenClipZ;
  float clipW;
  float negClipW;
  float floatZero;
  int lastWeightIndex;
  int loopIndex;
  float *weightCursor;
  float *nextVertex;
  float *vertexEnd;
  float *blendMatrix;
  float *zeroCursor;
  uint weightCount;
  uint clipCodeOr;
  int lastWeightSlot;
  uint clipCode;
  float *vertexCursor;
  int remaining;
  uint vertexIterations;
  uint clipCodeAnd;
  double fogExpResult;
  
  floatZero = FLOAT_00108e50;
  weightCount = (uint)*(byte *)(glContext + 0x4660);
  vertexEnd = vertices + vertexCount * 0x40;
  if (*(char *)(glContext + 0x4662) == '\0') {
    if (vertices < vertexEnd) {
      vertexIterations = (uint)((int)vertexEnd + (0xff - (int)vertices)) >> 8;
      zeroCursor = vertices;
      do {
        zeroCursor[0x3c] = floatZero;
        zeroCursor[0x3d] = floatZero;
        zeroCursor[0x3e] = floatZero;
        zeroCursor[0x3f] = floatZero;
        zeroCursor = zeroCursor + 0x40;
        vertexIterations = vertexIterations - 1;
      } while (vertexIterations != 0);
    }
  }
  else if (vertices < vertexEnd) {
    lastWeightIndex = weightCount - 1;
    vertexCursor = vertices;
    do {
      vertexCursor[0x3c] = floatZero;
      vertexCursor[0x3d] = floatZero;
      vertexCursor[0x3e] = floatZero;
      vertexCursor[0x3f] = floatZero;
      lastWeightSlot = 0;
      remainingWeightOrBlendM0OrClipBiasX = FLOAT_00108e54;
      if (0 < lastWeightIndex) {
        weightCursor = vertexCursor + 0x18;
        remaining = lastWeightIndex;
        do {
          weightOrBlendM1OrProjM3 = *weightCursor;
          weightCursor = weightCursor + 1;
          remainingWeightOrBlendM0OrClipBiasX = remainingWeightOrBlendM0OrClipBiasX - weightOrBlendM1OrProjM3;
          remaining = remaining + -1;
          lastWeightSlot = lastWeightIndex;
        } while (remaining != 0);
      }
      nextVertex = vertexCursor + 0x40;
      vertexCursor[lastWeightSlot + 0x18] = remainingWeightOrBlendM0OrClipBiasX;
      vertexCursor = nextVertex;
    } while (nextVertex < vertexEnd);
  }
  loopIndex = 0;
  if (weightCount != 0) {
    blendMatrix = (float *)(glContext + 0x1cc0);
    do {
      remainingWeightOrBlendM0OrClipBiasX = *blendMatrix;
      weightOrBlendM1OrProjM3 = blendMatrix[1];
      blendM2OrClipBiasY = blendMatrix[2];
      blendM3OrProjM7 = blendMatrix[3];
      blendM4OrProjM11 = blendMatrix[4];
      blendM5OrProjM15 = blendMatrix[5];
      blendM6OrClipScaleX = blendMatrix[6];
      blendM7OrClipScaleY = blendMatrix[7];
      blendM8OrProjM8 = blendMatrix[8];
      blendM9OrProjM12 = blendMatrix[9];
      blendM10OrViewportScaleX = blendMatrix[10];
      blendM11OrProjM5 = blendMatrix[0xb];
      blendM12OrProjM0 = blendMatrix[0xc];
      blendM13OrProjM1 = blendMatrix[0xd];
      blendM14OrProjM4 = blendMatrix[0xe];
      blendM15OrProjM9 = blendMatrix[0xf];
      if (vertices < vertices + vertexCount * 0x40) {
        vertexIterations = (uint)((int)(vertices + vertexCount * 0x40) + (0xff - (int)vertices)) >> 8;
        vertexCursor = vertices;
        do {
          objectYOrProjM13 = vertexCursor[9];
          objectXOrProjM14 = vertexCursor[8];
          objectZOrProjM2 = vertexCursor[10];
          objectWOrProjM6 = vertexCursor[0xb];
          blendWeightOrProjM10 = vertexCursor[loopIndex + 0x18];
          vertexCursor[0x3c] =
               blendWeightOrProjM10 * (objectWOrProjM6 * blendM12OrProjM0 + (objectZOrProjM2 * blendM8OrProjM8 + (objectXOrProjM14 * remainingWeightOrBlendM0OrClipBiasX + objectYOrProjM13 * blendM4OrProjM11))) +
               vertexCursor[0x3c];
          vertexCursor[0x3f] =
               blendWeightOrProjM10 * (objectWOrProjM6 * blendM15OrProjM9 + (objectZOrProjM2 * blendM11OrProjM5 + (objectXOrProjM14 * blendM3OrProjM7 + objectYOrProjM13 * blendM7OrClipScaleY))) +
               vertexCursor[0x3f];
          vertexCursor[0x3d] =
               blendWeightOrProjM10 * (objectWOrProjM6 * blendM13OrProjM1 + (objectZOrProjM2 * blendM9OrProjM12 + (objectXOrProjM14 * weightOrBlendM1OrProjM3 + objectYOrProjM13 * blendM5OrProjM15))) +
               vertexCursor[0x3d];
          vertexCursor[0x3e] =
               blendWeightOrProjM10 * (objectWOrProjM6 * blendM14OrProjM4 + (objectZOrProjM2 * blendM10OrViewportScaleX + (objectXOrProjM14 * blendM2OrClipBiasY + objectYOrProjM13 * blendM6OrClipScaleX))) +
               vertexCursor[0x3e];
          vertexCursor = vertexCursor + 0x40;
          vertexIterations = vertexIterations - 1;
        } while (vertexIterations != 0);
      }
      loopIndex = loopIndex + 1;
      blendMatrix = blendMatrix + 0x10;
    } while (loopIndex < (int)weightCount);
  }
  remainingWeightOrBlendM0OrClipBiasX = *(float *)(glContext + 0x4a20);
  weightOrBlendM1OrProjM3 = *(float *)(glContext + 0x1c8c);
  vertexEnd = vertices + vertexCount * 0x40;
  blendM2OrClipBiasY = *(float *)(glContext + 0x4a28);
  blendM3OrProjM7 = *(float *)(glContext + 0x1c9c);
  clipCodeOr = 0;
  blendM4OrProjM11 = *(float *)(glContext + 0x1cac);
  clipCodeAnd = 0xff;
  blendM5OrProjM15 = *(float *)(glContext + 0x1cbc);
  blendM6OrClipScaleX = *(float *)(glContext + 0x4a1c);
  blendM7OrClipScaleY = *(float *)(glContext + 0x4a24);
  blendM8OrProjM8 = *(float *)(glContext + 0x1ca0);
  blendM9OrProjM12 = *(float *)(glContext + 0x1cb0);
  blendM10OrViewportScaleX = *(float *)(glContext + 0x1b70);
  blendM11OrProjM5 = *(float *)(glContext + 0x1c94);
  blendM12OrProjM0 = *(float *)(glContext + 0x1c80);
  blendM13OrProjM1 = *(float *)(glContext + 0x1c84);
  blendM14OrProjM4 = *(float *)(glContext + 0x1c90);
  blendM15OrProjM9 = *(float *)(glContext + 0x1ca4);
  objectYOrProjM13 = *(float *)(glContext + 0x1cb4);
  objectXOrProjM14 = *(float *)(glContext + 0x1cb8);
  objectZOrProjM2 = *(float *)(glContext + 0x1c88);
  objectWOrProjM6 = *(float *)(glContext + 0x1c98);
  blendWeightOrProjM10 = *(float *)(glContext + 0x1ca8);
  viewportScaleY = *(float *)(glContext + 0x1b74);
  viewportScaleZ = *(float *)(glContext + 0x1b78);
  viewportOffsetY = *(float *)(glContext + 0x1b84);
  viewportOffsetX = *(float *)(glContext + 0x1b80);
  viewportOffsetZ = *(float *)(glContext + 0x1b88);
  do {
    if (vertexEnd <= vertices) {
      return;
    }
    clipCode = 0;
    eyeXThenClipY = vertices[0x3c];
    blendedEyeY = vertices[0x3d];
    blendedEyeZ = vertices[0x3e];
    blendedEyeW = vertices[0x3f];
    if ((*(byte *)(glContext + 0x50b4) & 2) != 0) {
      fogValueThenClipX = blendedEyeZ;
      if (*(short *)(glContext + 0x3166) == -0x7baf) {
        fogValueThenClipX = vertices[0x17];
      }
      if (floatZero < fogValueThenClipX) {
        fogValueThenClipX = -fogValueThenClipX;
      }
      fogFactorThenClipZ = FLOAT_00108e54;
      if (*(short *)(glContext + 0x3164) == 0x800) {
        if (!(floatZero <= fogValueThenClipX)) {
          fogValueThenClipX = *(float *)(glContext + 0x3150) * fogValueThenClipX;
          goto LAB_000c628c;
        }
      }
      else if (*(short *)(glContext + 0x3164) == 0x2601) {
        fogValueThenClipX = (*(float *)(glContext + 0x3158) + fogValueThenClipX) * *(float *)(glContext + 0x315c);
        if ((!(FLOAT_00108e54 < fogValueThenClipX)) && (fogFactorThenClipZ = fogValueThenClipX, fogValueThenClipX < floatZero)) {
          fogFactorThenClipZ = FLOAT_00108e50;
        }
      }
      else {
        fogValueThenClipX = *(float *)(glContext + 0x3150) * fogValueThenClipX;
        fogValueThenClipX = -fogValueThenClipX * fogValueThenClipX;
LAB_000c628c:
        fogExpResult = _exp((double)fogValueThenClipX);
        fogFactorThenClipZ = (float)fogExpResult;
      }
      vertices[0x13] = fogFactorThenClipZ;
    }
    clipW = blendedEyeW * blendM5OrProjM15 + (blendedEyeZ * blendM4OrProjM11 + (eyeXThenClipY * weightOrBlendM1OrProjM3 + blendedEyeY * blendM3OrProjM7));
    fogValueThenClipX = blendedEyeW * (blendM6OrClipScaleX * blendM9OrProjM12 + remainingWeightOrBlendM0OrClipBiasX * blendM5OrProjM15) +
             (blendedEyeZ * (blendM6OrClipScaleX * blendM8OrProjM8 + remainingWeightOrBlendM0OrClipBiasX * blendM4OrProjM11) +
             (eyeXThenClipY * (blendM6OrClipScaleX * blendM12OrProjM0 + remainingWeightOrBlendM0OrClipBiasX * weightOrBlendM1OrProjM3) + blendedEyeY * (blendM6OrClipScaleX * blendM14OrProjM4 + remainingWeightOrBlendM0OrClipBiasX * blendM3OrProjM7)));
    negClipW = -clipW;
    fogFactorThenClipZ = blendedEyeW * objectXOrProjM14 + (blendedEyeZ * blendWeightOrProjM10 + (eyeXThenClipY * objectZOrProjM2 + blendedEyeY * objectWOrProjM6));
    eyeXThenClipY = blendedEyeW * (blendM7OrClipScaleY * objectYOrProjM13 + blendM2OrClipBiasY * blendM5OrProjM15) +
             (blendedEyeZ * (blendM7OrClipScaleY * blendM15OrProjM9 + blendM2OrClipBiasY * blendM4OrProjM11) +
             (eyeXThenClipY * (blendM7OrClipScaleY * blendM13OrProjM1 + blendM2OrClipBiasY * weightOrBlendM1OrProjM3) + blendedEyeY * (blendM7OrClipScaleY * blendM11OrProjM5 + blendM2OrClipBiasY * blendM3OrProjM7)));
    if (fogValueThenClipX < negClipW) {
      clipCode = 0x10;
    }
    if (clipW <= fogValueThenClipX) {
      clipCode = clipCode | 0x20;
    }
    if (eyeXThenClipY < negClipW) {
      clipCode = clipCode | 4;
    }
    if (clipW <= eyeXThenClipY) {
      clipCode = clipCode | 8;
    }
    if (fogFactorThenClipZ < negClipW) {
      clipCode = clipCode | 1;
    }
    if (clipW < fogFactorThenClipZ) {
      clipCode = clipCode | 2;
    }
    vertices[4] = fogValueThenClipX;
    vertices[5] = eyeXThenClipY;
    vertices[6] = fogFactorThenClipZ;
    vertices[7] = clipW;
    *(char *)((int)vertices + 0x7f) = (char)clipCode;
    if (clipCode == 0) {
      clipW = FLOAT_00108e54 / clipW;
      vertices[3] = clipW;
      *vertices = fogValueThenClipX * clipW * blendM10OrViewportScaleX + viewportOffsetX;
      vertices[1] = eyeXThenClipY * clipW * viewportScaleY + viewportOffsetY;
      vertices[2] = fogFactorThenClipZ * clipW * viewportScaleZ + viewportOffsetZ;
    }
    vertices = vertices + 0x40;
    clipCodeAnd = clipCodeAnd & clipCode;
    clipCodeOr = clipCodeOr | clipCode;
  } while( true );
}

/* _gleBuildProjectionTransformFuncNO @ 0xc63cc (1544 bytes) */
int _gleBuildProjectionTransformFuncNO(glContext, optionBits)
  int glContext;
  uint optionBits;
{
  bool bVar1;
  uint uVar2;
  uint matrixIdentifierThenCacheKey;
  int cacheElem;
  undefined *puVar5;
  undefined *codeChunk;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int remaining;
  int chunkWordCount;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int *cacheListHead;
  int *piVar16;
  uint *puVar17;
  uint *puVar18;
  uint *puVar19;
  int iVar20;
  int remaining2;
  int chunkWordCount2;
  int local_70 [15];
  int local_34;
  
  if (*(char *)(glContext + 0x4661) != '\0') {
    return (int *)PTR__gleTransformProjectionBlend_00110a10;
  }
  matrixIdentifierThenCacheKey = (**(code **)PTR__gleGenerateMatrixIdentifier_00112060)(glContext,glContext + 0x27c0);
  *(uint *)(glContext + 0x5084) = matrixIdentifierThenCacheKey;
  if ((optionBits & 2) != 0) {
    matrixIdentifierThenCacheKey = matrixIdentifierThenCacheKey | 0xff00;
  }
  if ((*(undefined **)(glContext + 0x5080) == ((unsigned char *)0x00001101)) && (*(int *)(glContext + 0x4e1c) == 0x1c00)
     ) {
    optionBits = optionBits | 8;
  }
  cacheListHead = *(int **)(glContext + 0x5088);
  piVar16 = cacheListHead;
  do {
    if (matrixIdentifierThenCacheKey == piVar16[2] && optionBits == piVar16[3]) {
      if (piVar16 != cacheListHead) {
        _gleMoveFuncCacheElem(cacheListHead,piVar16);
        *(int **)(glContext + 0x5088) = piVar16;
      }
      return piVar16 + 8;
    }
    piVar16 = (int *)*piVar16;
  } while (piVar16 != cacheListHead);
  cacheElem = _gleCreateFuncCacheElem(piVar16,0x90);
  if (cacheElem == 0) {
    return (int *)PTR__gleRTCNoop_00112058;
  }
  *(uint *)(cacheElem + 8) = matrixIdentifierThenCacheKey;
  *(uint *)(cacheElem + 0xc) = optionBits;
  if (*(short *)(glContext + 0x508e) == *(short *)(glContext + 0x508c)) {
    _gleDeleteFuncCacheElem(*(undefined4 *)(cacheElem + 4));
  }
  else {
    *(short *)(glContext + 0x508e) = *(short *)(glContext + 0x508e) + 1;
  }
  iVar11 = 0x10;
  remaining2 = 0x10;
  *(undefined4 *)(cacheElem + 0x20) = 0xd9c1fff8;
  *(undefined4 *)(cacheElem + 0x24) = 0xd9e1fff0;
  puVar17 = (uint *)(cacheElem + 0x28);
  uVar8 = 0xfffffff0;
  bVar1 = false;
  uVar13 = 0;
  piVar16 = local_70;
  do {
    if ((matrixIdentifierThenCacheKey << ((uVar13 & 0x1f) << 1) & 0xc0000000) == 0) {
      uVar8 = uVar8 - 8;
      uVar14 = iVar11 << 0x15;
      *piVar16 = iVar11;
      iVar11 = iVar11 + 1;
      bVar1 = true;
      *puVar17 = uVar14 | uVar8 & 0xffff | 0xd8010000;
      puVar17 = puVar17 + 1;
    }
    uVar13 = uVar13 + 1;
    piVar16 = piVar16 + 1;
    remaining2 = remaining2 + -1;
  } while (remaining2 != 0);
  chunkWordCount = ((int (*)())_gleRTCAddAChunk_c5ddc)(&_glePrologNORTC,puVar17);
  puVar17[chunkWordCount] = 0xc1230024;
  puVar17 = puVar17 + chunkWordCount + 1;
  if (bVar1) {
    chunkWordCount = ((int (*)())_gleRTCAddAChunk_c5ddc)(&_gleLoadMatrixPtrRTC_10f758,puVar17);
    puVar17 = puVar17 + chunkWordCount;
  }
  chunkWordCount = ((int (*)())_gleRTCAddAChunk_c5ddc)(&_gleLoadViewportRTC,puVar17);
  puVar17 = puVar17 + chunkWordCount;
  uVar13 = 0;
  uVar8 = 0;
  remaining = 0x10;
  do {
    if ((matrixIdentifierThenCacheKey << (uVar8 & 0x3f) & 0xc0000000) == 0) {
      *puVar17 = *(int *)((int)local_70 + uVar13) << 0x15 | uVar13 & 0xffff | 0xc0060000;
      puVar17 = puVar17 + 1;
    }
    uVar8 = uVar8 + 2;
    uVar13 = uVar13 + 4;
    remaining = remaining + -1;
  } while (remaining != 0);
  remaining = 4;
  uVar8 = 0;
  uVar14 = 3;
  uVar13 = 0xe00000;
  do {
    if ((matrixIdentifierThenCacheKey << ((uVar14 & 0x1f) << 1) & 0xc0c0c0c0) == 0xc0c0c0c0) {
      if (uVar8 == 0) {
        uVar2 = uVar13 | 0xc0030020;
        uVar8 = uVar14;
      }
      else {
        uVar2 = uVar13 | (uVar8 + 4) * 0x800 | 0xfc000090;
      }
      *puVar17 = uVar2;
      puVar17 = puVar17 + 1;
    }
    uVar14 = uVar14 - 1;
    uVar13 = uVar13 - 0x200000;
    remaining = remaining + -1;
  } while (remaining != 0);
  uVar8 = optionBits;
  uVar13 = matrixIdentifierThenCacheKey;
  if ((optionBits & 1) == 0) {
    uVar14 = 3;
    goto LAB_000c6778;
  }
  uVar14 = matrixIdentifierThenCacheKey & 0x3030303;
  if (uVar14 == 0x3030302) {
    *puVar17 = 0xfce04890;
    puVar17 = puVar17 + 1;
    *puVar17 = 0xfd003850;
    uVar8 = optionBits | 4;
LAB_000c6720:
    puVar17 = puVar17 + 1;
    uVar2 = 1;
    uVar13 = matrixIdentifierThenCacheKey | 0x3030303;
  }
  else {
    if (uVar14 == 0x3030301) {
      uVar13 = 0xfce04850;
LAB_000c6718:
      *puVar17 = uVar13;
      goto LAB_000c6720;
    }
    uVar2 = 0;
    if (uVar14 == 0x3030300) {
      uVar13 = local_34 << 0xb | 0xfce00090;
      goto LAB_000c6718;
    }
  }
  if (uVar2 < 4) {
    do {
      if ((uVar13 >> ((uVar2 & 0x1f) << 1) & 3) - 1 < 2) {
        *puVar17 = 0xfc604890;
        puVar17 = puVar17 + 1;
        break;
      }
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < 4);
  }
  uVar14 = 2;
LAB_000c6778:
  iVar11 = uVar14 + 1;
  uVar7 = uVar14 * 4 + 0x20;
  uVar12 = uVar14 * 10;
  uVar6 = uVar14 * 0x200000 + 0x800000;
  uVar2 = uVar7;
  puVar18 = puVar17;
  do {
    uVar10 = 0xff000000 >> ((uVar14 & 7) << 3);
    uVar9 = 0xc0c0c0c0U >> ((uVar14 & 0x1f) << 1) | uVar10;
    if ((uVar13 & uVar9) == (uVar9 & ~(0x40000000 >> (uVar12 & 0x3f)))) {
      uVar13 = uVar13 | uVar9;
      uVar9 = uVar6 | uVar2 & 0xffff;
LAB_000c6804:
      *puVar18 = uVar9 | 0xc0040000;
      puVar18 = puVar18 + 1;
    }
    else if ((uVar13 & uVar10) != uVar10) {
      uVar9 = uVar14 << 0x15 | uVar7 & 0xffff;
      goto LAB_000c6804;
    }
    uVar14 = uVar14 - 1;
    uVar12 = uVar12 - 10;
    uVar6 = uVar6 - 0x200000;
    uVar2 = uVar2 - 4;
    uVar7 = uVar7 - 4;
    iVar11 = iVar11 + -1;
    if (iVar11 == 0) {
      iVar11 = _gleEmitTransformInstructions(puVar18,uVar13,local_70,0,4,optionBits & 1);
      if ((uVar8 & 8) == 0) {
        if ((uVar8 & 4) == 0) {
          codeChunk = &_gleCalcClipCodeNORTC;
        }
        else {
          codeChunk = &_gleCalcClipCodeW1NORTC;
        }
      }
      else if ((uVar8 & 4) == 0) {
        codeChunk = &_gleNoClipCodeNORTC;
      }
      else {
        codeChunk = &_gleNoClipCodeW1NORTC;
      }
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c5ddc)(codeChunk,iVar11);
      iVar11 = iVar11 + chunkWordCount2 * 4;
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_c5ddc)(&_gleClipSumsAndEndLoopRTC,iVar11);
      uVar8 = 0xfffffff0;
      puVar19 = (uint *)(iVar11 + chunkWordCount2 * 4);
      uVar13 = 0;
      puVar18 = puVar19 + -1;
      piVar16 = local_70;
      remaining = 0x10;
      do {
        if ((matrixIdentifierThenCacheKey << ((uVar13 & 0x1f) << 1) & 0xc0000000) == 0) {
          uVar8 = uVar8 - 8;
          *puVar19 = *piVar16 << 0x15 | uVar8 & 0xffff | 0xc8010000;
          puVar19 = puVar19 + 1;
        }
        uVar13 = uVar13 + 1;
        piVar16 = piVar16 + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      *puVar19 = 0xc9e1fff0;
      puVar19[1] = 0xc9c1fff8;
      puVar19 = puVar19 + 2;
      chunkWordCount = ((int (*)())_gleRTCAddAChunk_c5ddc)(&_gleCombineClipSumsNORTC,puVar19);
      puVar19 = puVar19 + chunkWordCount;
      iVar11 = ((int (*)())_gleRTCAddAChunk_c5ddc)(&_gleEpilogNORTC,puVar19);
      matrixIdentifierThenCacheKey = ((int (*)())_gleRTCBuildABranch_c5dd0)(*puVar18,(int)puVar17 - (int)puVar18 >> 2);
      iVar20 = (int)(puVar19 + iVar11) + (-0x1c - cacheElem) >> 2;
      *puVar18 = matrixIdentifierThenCacheKey;
      puVar19[iVar11] = 0x4e800020;
      if (iVar20 < 0x91) {
        cacheElem = _gleShrinkFuncCacheElem(cacheElem,iVar20);
        puVar5 = PTR__glePushInstructions_00112054;
        *(int *)(glContext + 0x5088) = cacheElem;
        (**(code **)puVar5)(iVar20,(int *)(cacheElem + 0x20));
        return (int *)(cacheElem + 0x20);
      }
                    
      _exit(1);
    }
  } while( true );
}

/* _gleGetClientAttrib @ 0xc69d4 (460 bytes) */
void _gleGetClientAttrib(glContext, clientAttribBit, savedState)
  int glContext;
  int clientAttribBit;
  undefined4 *savedState;
{
  undefined4 *recordPointerSlot;
  int clientArrays;
  int *bufferObjectSlot;
  undefined4 bufferName;
  int arrayRecord;
  int remaining;
  undefined4 *savedEntryThenBufferNameCursor;
  int bufferObject;
  int remaining2;
  
  if (clientAttribBit == 1) {
    *savedState = *(undefined4 *)(glContext + 0x31b0);
    savedState[2] = *(undefined4 *)(glContext + 0x31b8);
    savedState[3] = *(undefined4 *)(glContext + 0x31bc);
    savedState[5] = *(undefined4 *)(glContext + 0x31c4);
    *(undefined1 *)(savedState + 6) = *(undefined1 *)(glContext + 0x31c8);
    *(undefined1 *)((int)savedState + 0x19) = *(undefined1 *)(glContext + 0x31c9);
    savedState[1] = *(undefined4 *)(0x31b4 + glContext);
    savedState[4] = *(undefined4 *)(glContext + 0x31c0);
    savedState[7] = *(undefined4 *)(glContext + 0x31cc);
    savedState[9] = *(undefined4 *)(glContext + 0x31d4);
    savedState[10] = *(undefined4 *)(glContext + 0x31d8);
    savedState[0xc] = *(undefined4 *)(glContext + 0x31e0);
    *(undefined1 *)(savedState + 0xd) = *(undefined1 *)(glContext + 0x31e4);
    *(undefined1 *)((int)savedState + 0x35) = *(undefined1 *)(glContext + 0x31e5);
    *(undefined1 *)((int)savedState + 0x36) = *(undefined1 *)(glContext + 0x31e6);
    savedState[8] = *(undefined4 *)(glContext + 0x31d0);
    savedState[0xb] = *(undefined4 *)(glContext + 0x31dc);
    return;
  }
  clientArrays = *(int *)(glContext + 0x4a60);
  arrayRecord = clientArrays + 0x10;
  *savedState = *(undefined4 *)(clientArrays + 4);
  *(undefined2 *)((int)savedState + 0x206) = *(undefined2 *)(glContext + 0x48ea);
  remaining2 = 0x20;
  savedState[0xa7] = *(undefined4 *)(clientArrays + 0x334);
  savedEntryThenBufferNameCursor = savedState;
  do {
    savedEntryThenBufferNameCursor[1] = (int)*(short *)(arrayRecord + 0x2a);
    savedEntryThenBufferNameCursor[2] = (uint)*(ushort *)(arrayRecord + 0x28);
    savedEntryThenBufferNameCursor[3] = *(undefined4 *)(arrayRecord + 0x24);
    recordPointerSlot = (undefined4 *)(arrayRecord + 0x20);
    arrayRecord = arrayRecord + 0x18;
    savedEntryThenBufferNameCursor[4] = *recordPointerSlot;
    savedEntryThenBufferNameCursor = savedEntryThenBufferNameCursor + 4;
    remaining2 = remaining2 + -1;
  } while (remaining2 != 0);
  bufferName = 0;
  *(undefined2 *)(savedState + 0x81) = *(undefined2 *)(glContext + 0x48e8);
  savedState[0x82] = *(undefined4 *)(glContext + 0x48e4);
  savedState[0x83] = *(undefined4 *)(glContext + 0x48e0);
  savedState[0xa8] = *(undefined4 *)(clientArrays + 0x330);
  if (*(int *)(clientArrays + 0x358) != 0) {
    bufferName = *(undefined4 *)(*(int *)(clientArrays + 0x358) + 4);
  }
  savedState[0x84] = bufferName;
  bufferName = 0;
  if (*(int *)(clientArrays + 0x35c) != 0) {
    bufferName = *(undefined4 *)(*(int *)(clientArrays + 0x35c) + 4);
  }
  savedState[0x85] = bufferName;
  remaining = 0x20;
  savedEntryThenBufferNameCursor = savedState + 0x86;
  bufferObjectSlot = (int *)(clientArrays + 0x360);
  do {
    bufferObject = *bufferObjectSlot;
    bufferName = 0;
    bufferObjectSlot = bufferObjectSlot + 1;
    if (bufferObject != 0) {
      bufferName = *(undefined4 *)(bufferObject + 4);
    }
    *savedEntryThenBufferNameCursor = bufferName;
    savedEntryThenBufferNameCursor = savedEntryThenBufferNameCursor + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  bufferName = 0;
  if (*(int *)(glContext + 0x48f4) != 0) {
    bufferName = *(undefined4 *)(*(int *)(glContext + 0x48f4) + 4);
  }
  savedState[0xa6] = bufferName;
  savedState[0xaa] = *(undefined4 *)(clientArrays + 0x344);
  savedState[0xa9] = *(undefined4 *)(clientArrays + 0x348);
  savedState[0xab] = *(undefined4 *)(glContext + 0x4984);
  savedState[0xac] = *(undefined4 *)(glContext + 0x4988);
  savedState[0xad] = *(int *)(glContext + 0x53d8) + 0x84c0;
  return;
}

/* _gleSetClientAttrib @ 0xc6ba0 (1172 bytes) */
void _gleSetClientAttrib(glContext, clientAttribBit, savedState)
  int glContext;
  int clientAttribBit;
  int *savedState;
{
  int unitBufferName;
  int nextAttribIndex;
  int vertexArrayState;
  int pointerBufferName;
  int attribIndex;
  int loopIndex;
  int boundArrayBuffer;
  int boundElementBuffer;
  int *bufferNameCursor;
  int *pointerStateCursor;
  
  if (clientAttribBit == 1) {
    *(int *)(glContext + 0x31b0) = *savedState;
    *(int *)(glContext + 0x31b8) = savedState[2];
    *(int *)(glContext + 0x31bc) = savedState[3];
    *(int *)(glContext + 0x31c4) = savedState[5];
    *(undefined1 *)(glContext + 0x31c8) = *(undefined1 *)(savedState + 6);
    *(undefined1 *)(glContext + 0x31c9) = *(undefined1 *)((int)savedState + 0x19);
    *(int *)(0x31b4 + glContext) = savedState[1];
    *(int *)(glContext + 0x31c0) = savedState[4];
    *(int *)(glContext + 0x31cc) = savedState[7];
    *(int *)(glContext + 0x31d4) = savedState[9];
    *(int *)(glContext + 0x31d8) = savedState[10];
    *(int *)(glContext + 0x31e0) = savedState[0xc];
    *(undefined1 *)(glContext + 0x31e4) = *(undefined1 *)(savedState + 0xd);
    *(undefined1 *)(glContext + 0x31e5) = *(undefined1 *)((int)savedState + 0x35);
    *(undefined1 *)(glContext + 0x31e6) = *(undefined1 *)((int)savedState + 0x36);
    *(int *)(glContext + 0x31d0) = savedState[8];
    *(int *)(glContext + 0x31dc) = savedState[0xb];
  }
  else {
    vertexArrayState = *(int *)(glContext + 0x4a60);
    if (*(int *)(vertexArrayState + 4) != *savedState) {
      _gleBindVertexArray(glContext,*savedState);
      vertexArrayState = *(int *)(glContext + 0x4a60);
    }
    boundArrayBuffer = 0;
    if (*(int *)(vertexArrayState + 0x358) != 0) {
      boundArrayBuffer = *(int *)(*(int *)(vertexArrayState + 0x358) + 4);
    }
    *(undefined2 *)(glContext + 0x48ea) = *(undefined2 *)((int)savedState + 0x206);
    pointerBufferName = savedState[0xa7];
    *(undefined4 *)(vertexArrayState + 0x330) = 0;
    *(int *)(vertexArrayState + 0x334) = pointerBufferName;
    *(int *)(vertexArrayState + 0x330) = savedState[0xa8];
    *(int *)(vertexArrayState + 0x334) = pointerBufferName;
    pointerBufferName = savedState[0x86];
    if (boundArrayBuffer != pointerBufferName) {
      _glBindBuffer_Exec(glContext,0x8892,pointerBufferName);
      boundArrayBuffer = pointerBufferName;
    }
    _glVertexPointer_Exec(glContext,savedState[1],savedState[2],savedState[3],savedState[4]);
    pointerBufferName = savedState[0x87];
    if (boundArrayBuffer != pointerBufferName) {
      _glBindBuffer_Exec(glContext,0x8892,pointerBufferName);
      boundArrayBuffer = pointerBufferName;
    }
    _glNormalPointer_Exec(glContext,savedState[6] & 0xffff7fff,savedState[7],savedState[8]);
    pointerBufferName = savedState[0x88];
    if (boundArrayBuffer != pointerBufferName) {
      _glBindBuffer_Exec(glContext,0x8892,pointerBufferName);
      boundArrayBuffer = pointerBufferName;
    }
    _glColorPointer_Exec(glContext,savedState[9],savedState[10] & 0xffff7fff,savedState[0xb],savedState[0xc]);
    pointerBufferName = savedState[0x8a];
    if (boundArrayBuffer != pointerBufferName) {
      _glBindBuffer_Exec(glContext,0x8892,pointerBufferName);
      boundArrayBuffer = pointerBufferName;
    }
    _glFogCoordPointer_Exec(glContext,savedState[0xe],savedState[0xf],savedState[0x10]);
    pointerBufferName = savedState[0x8b];
    if (boundArrayBuffer != pointerBufferName) {
      _glBindBuffer_Exec(glContext,0x8892,pointerBufferName);
      boundArrayBuffer = pointerBufferName;
    }
    _glSecondaryColorPointer_Exec
              (glContext,savedState[0x11],savedState[0x12] & 0xffff7fff,savedState[0x13],savedState[0x14]);
    pointerBufferName = savedState[0x89];
    if (boundArrayBuffer != pointerBufferName) {
      _glBindBuffer_Exec(glContext,0x8892,pointerBufferName);
      boundArrayBuffer = pointerBufferName;
    }
    _glWeightPointerARB_Exec
              (glContext,savedState[0x15],savedState[0x16] & 0xffff7fff,savedState[0x17],savedState[0x18]);
    pointerBufferName = savedState[0x8c];
    if (boundArrayBuffer != pointerBufferName) {
      _glBindBuffer_Exec(glContext,0x8892,pointerBufferName);
      boundArrayBuffer = pointerBufferName;
    }
    _glEdgeFlagPointer_Exec(glContext,savedState[0x1b],savedState[0x1c]);
    pointerBufferName = savedState[0x8d];
    if (boundArrayBuffer != pointerBufferName) {
      _glBindBuffer_Exec(glContext,0x8892,pointerBufferName);
      boundArrayBuffer = pointerBufferName;
    }
    loopIndex = 0;
    bufferNameCursor = savedState + 0x8e;
    _glElementPointerAPPLE_Exec(glContext,savedState[0x1e],savedState[0x20]);
    pointerStateCursor = savedState;
    do {
      unitBufferName = *bufferNameCursor;
      bufferNameCursor = bufferNameCursor + 1;
      if (boundArrayBuffer != unitBufferName) {
        _glBindBuffer_Exec(glContext,0x8892,unitBufferName);
        boundArrayBuffer = unitBufferName;
      }
      *(int *)(glContext + 0x53d8) = loopIndex;
      loopIndex = loopIndex + 1;
      _glTexCoordPointer_Exec(glContext,pointerStateCursor[0x21],pointerStateCursor[0x22],pointerStateCursor[0x23],pointerStateCursor[0x24]);
      pointerStateCursor = pointerStateCursor + 4;
    } while (loopIndex < 8);
    bufferNameCursor = savedState + 0x96;
    attribIndex = 0;
    pointerStateCursor = savedState;
    do {
      unitBufferName = *bufferNameCursor;
      bufferNameCursor = bufferNameCursor + 1;
      if (boundArrayBuffer != unitBufferName) {
        _glBindBuffer_Exec(glContext,0x8892,unitBufferName);
        boundArrayBuffer = unitBufferName;
      }
      nextAttribIndex = attribIndex + 1;
      _glVertexAttribPointerARB_Exec
                (glContext,attribIndex,pointerStateCursor[0x41],pointerStateCursor[0x42] & 0xffff7fff,(uint)pointerStateCursor[0x42] >> 0xf & 1,
                 pointerStateCursor[0x43],pointerStateCursor[0x44]);
      pointerStateCursor = pointerStateCursor + 4;
      attribIndex = nextAttribIndex;
    } while (nextAttribIndex < 0x10);
    pointerBufferName = savedState[0xa6];
    if (boundArrayBuffer != pointerBufferName) {
      _glBindBuffer_Exec(glContext,0x8892,pointerBufferName);
      boundArrayBuffer = pointerBufferName;
    }
    _glIndexPointer_Exec(glContext,(uint)*(ushort *)(savedState + 0x81),savedState[0x82],savedState[0x83]);
    if (boundArrayBuffer != savedState[0x84]) {
      _glBindBuffer_Exec(glContext,0x8892,savedState[0x84]);
    }
    boundElementBuffer = 0;
    if (*(int *)(vertexArrayState + 0x35c) != 0) {
      boundElementBuffer = *(int *)(*(int *)(vertexArrayState + 0x35c) + 4);
    }
    if (boundElementBuffer != savedState[0x85]) {
      _glBindBuffer_Exec(glContext,0x8893,savedState[0x85]);
    }
    _glVertexArrayRangeEXT_Exec(glContext,savedState[0xa9],savedState[0xaa]);
    *(int *)(glContext + 0x53d8) = savedState[0xad] + -0x84c0;
    if (*(int *)(glContext + 0x4988) != 0) {
      _glUnlockArraysEXT_Exec(glContext);
    }
    if (savedState[0xac] != 0) {
      _glLockArraysEXT_Exec(glContext,savedState[0xab],savedState[0xac]);
    }
  }
  return;
}

/* _gleAddClientAttribElem @ 0xc7034 (120 bytes) */
void _gleAddClientAttribElem(glContext, clientAttribBit)
  int glContext;
  undefined4 clientAttribBit;
{
  int *piVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)_malloc(0x2c0);
  if (puVar2 == (undefined4 *)0x0) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x505;
    }
  }
  else {
    *puVar2 = clientAttribBit;
    ((void (*)())_gleGetClientAttrib)(glContext,clientAttribBit,puVar2 + 1);
    piVar1 = *(int **)(glContext + 0x5140);
    puVar2[0xaf] = *piVar1;
    *piVar1 = (int)puVar2;
  }
  return;
}

/* _gleRemoveClientAttribElem @ 0xc70ac (56 bytes) */
void _gleRemoveClientAttribElem(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_gleSetClientAttrib)(param_1,*param_2,param_2 + 1);
  _free(param_2);
  return;
}

/* _gleCreatePluginBuffer @ 0xc70e4 (124 bytes) */
void _gleCreatePluginBuffer(glContext, param_2)
  int glContext;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int loopIndex;
  int iVar5;
  
  iVar3 = glContext + 0x10000;
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    iVar5 = param_2;
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      iVar3 = iVar3 + 0x2e0;
      loopIndex = loopIndex + 1;
      (**(code **)(*piVar1 + 0x1d4))(*puVar2,iVar5,param_2 + 0x20,iVar5 + 0x38);
      iVar5 = iVar5 + 4;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return;
}

/* _gleFreeBufferObject @ 0xc7160 (168 bytes) */
void _gleFreeBufferObject(glContext, param_2)
  int glContext;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int loopIndex;
  int iVar5;
  
  iVar3 = glContext + 0x10000;
  loopIndex = 0;
  iVar5 = param_2;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      loopIndex = loopIndex + 1;
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      iVar3 = iVar3 + 0x2e0;
      (**(code **)(*piVar1 + 0x1d8))(*puVar2,*(undefined4 *)(iVar5 + 0x10));
      *(undefined4 *)(iVar5 + 0x10) = 0;
      iVar5 = iVar5 + 4;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  if (*(vm_address_t *)(param_2 + 0x30) != 0) {
    _vm_deallocate(*(vm_map_t *)PTR_00112034,*(vm_address_t *)(param_2 + 0x30),
                   *(vm_size_t *)(param_2 + 0x38));
  }
  _gleVecFree(param_2);
  return;
}

/* _gleCreateBufferObject @ 0xc7208 (212 bytes) */
int _gleCreateBufferObject(glContext, param_2)
  int glContext;
  undefined4 param_2;
{
  undefined *freeBufferObject;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int remaining;
  int loopIndex;
  
  puVar3 = (undefined4 *)_gleVecAlloc((uint)*(byte *)(glContext + 0x85a4) * 4 + 0x48);
  freeBufferObject = PTR__gleFreeBufferObject_00110a1c;
  puVar3[0xd] = 0;
  puVar3[2] = 1;
  puVar3[3] = freeBufferObject;
  *puVar3 = 0;
  *(undefined1 *)(puVar3 + 0x11) = 0;
  puVar3[0x10] = 0;
  puVar3[0xc] = 0;
  puVar3[0xe] = 0;
  *(undefined2 *)(puVar3 + 0xf) = 0x88e4;
  remaining = 8;
  *(undefined2 *)((int)puVar3 + 0x3e) = 0x88ba;
  puVar3[1] = param_2;
  puVar2 = puVar3 + 4;
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    puVar2 = puVar3 + 0x12;
    do {
      *puVar2 = 0xffffffff;
      loopIndex = loopIndex + 1;
      puVar2 = puVar2 + 1;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return (int)puVar3;
}

/* _gleBindBufferObject @ 0xc72dc (460 bytes) */
void _gleBindBufferObject(glContext, target, bufferName)
  int glContext;
  uint target;
  int bufferName;
{
  bool noBuffer;
  undefined4 copiedWord;
  int bufferObject;
  int clientState;
  undefined4 *dstCursor;
  undefined4 *dstCursor2;
  int loopIndex;
  undefined4 *srcCursor;
  int bufferHashTable;
  int oldBufferObject;
  
  clientState = *(int *)(glContext + 0x4a60);
  bufferHashTable = *(int *)(glContext + 0x5148) + 0x701c;
  if (bufferName == 0) {
    bufferObject = 0;
    noBuffer = true;
  }
  else {
    bufferObject = _gleLookupHashObject(bufferHashTable,bufferName);
    noBuffer = false;
    if (bufferObject == 0) {
      bufferObject = ((int (*)())_gleCreateBufferObject)(glContext,bufferName);
      ((void (*)())_gleCreatePluginBuffer)(glContext,bufferObject + 0x10);
      _gleAddHashNameAndObject(glContext,bufferHashTable,bufferObject);
      noBuffer = bufferObject == 0;
    }
    *(int *)(bufferObject + 8) = *(int *)(bufferObject + 8) + 1;
  }
  if (target == 0x8893) {
    oldBufferObject = *(int *)(clientState + 0x35c);
    *(int *)(clientState + 0x35c) = bufferObject;
    if (noBuffer) {
      loopIndex = 0;
      if (bufferObject < (int)(uint)*(byte *)(glContext + 0x85a4)) {
        dstCursor = (undefined4 *)(clientState + 0x460);
        do {
          *dstCursor = 0;
          loopIndex = loopIndex + 1;
          dstCursor = dstCursor + 0x23;
        } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
      }
    }
    else {
      loopIndex = 0;
      if (*(char *)(glContext + 0x85a4) != '\0') {
        dstCursor2 = (undefined4 *)(clientState + 0x460);
        srcCursor = (undefined4 *)(bufferObject + 0x10);
        do {
          copiedWord = *srcCursor;
          loopIndex = loopIndex + 1;
          srcCursor = srcCursor + 1;
          *dstCursor2 = copiedWord;
          dstCursor2 = dstCursor2 + 0x23;
        } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
      }
    }
    goto LAB_000c7440;
  }
  if (0x8893 < target) {
    if (target == 0x88eb) {
      oldBufferObject = *(int *)(glContext + 0x4a68);
      *(int *)(glContext + 0x4a68) = bufferObject;
      goto LAB_000c7440;
    }
    if (target == 0x88ec) {
      oldBufferObject = *(int *)(glContext + 0x4a6c);
      *(int *)(glContext + 0x4a6c) = bufferObject;
      goto LAB_000c7440;
    }
  }
  oldBufferObject = *(int *)(clientState + 0x358);
  *(int *)(clientState + 0x358) = bufferObject;
LAB_000c7440:
  if ((!noBuffer) && (*(int *)(bufferObject + 0x40) != 0)) {
    ((double (*)())_gleSynchronizePluginBuffer)(glContext,bufferObject + 0x10);
  }
  if ((oldBufferObject != 0) && (clientState = *(int *)(oldBufferObject + 8) + -1, *(int *)(oldBufferObject + 8) = clientState, clientState == 0)) {
    ((void (*)())_gleFreeBufferObject)(glContext,oldBufferObject);
    return;
  }
  return;
}

/* _gleOrphanBufferData @ 0xc74a8 (1088 bytes) */
void _gleOrphanBufferData(glContext, bufferObject, size, usage)
  int glContext;
  undefined4 *bufferObject;
  int size;
  uint usage;
{
  int *rendererDispatch;
  bool allIdle;
  bool previousIdle;
  int bucketSentinel;
  int bucketNode;
  int rendererCursor;
  int listPrev;
  undefined4 orphanTable;
  undefined4 rendererName;
  undefined4 storagePtr;
  undefined4 nodeNext;
  undefined4 copiedWord;
  undefined4 spareNode;
  int *newNode;
  int *candidateNode;
  uint orphanSize;
  int bucketEntry;
  int nextIndex;
  int bucketOffset;
  int initOffset;
  int spareNodeSlot;
  int loopIndex2;
  int listHead;
  int bucket;
  int cachedBytes;
  int newestOrphan;
  int loopIndex;
  undefined4 *srcCursor;
  undefined4 *nameCursor;
  undefined4 *prevNode;
  undefined4 *rendererStateCursor;
  undefined4 *bucketTail;
  int tableBase;
  int *nameDstCursor;
  int *rendererDispatch2;
  undefined4 *rendererHandlePtr;
  undefined4 *rendererHandlePtr2;
  undefined4 *nameCursor2;
  int rendererCursorBase;
  int sizeBucketOffset;
  int orphanCount;
  int remaining;
  
  if (*(int *)(glContext + 0x7484) == 0) {
    orphanTable = _gleVecAlloc(0x1800);
    remaining = 0x80;
    *(undefined4 *)(glContext + 0x7484) = orphanTable;
    initOffset = 0;
    do {
      tableBase = *(int *)(glContext + 0x7484);
      bucketEntry = tableBase + initOffset;
      bucketSentinel = bucketEntry + 0x14;
      *(undefined4 *)(bucketEntry + 0x28) = 0;
      *(int *)(bucketEntry + 0x20) = bucketSentinel;
      *(int *)(bucketEntry + 0x1c) = bucketSentinel;
      *(int *)(bucketEntry + 0x18) = bucketSentinel;
      *(undefined4 *)(bucketEntry + 0x24) = 0;
      *(int *)(bucketEntry + 0x14) = bucketSentinel;
      *(undefined4 *)(bucketEntry + 0x10) = 0;
      *(undefined4 *)(tableBase + initOffset) = 0;
      initOffset = initOffset + 0x30;
      *(undefined4 *)(bucketEntry + 4) = 0;
      *(undefined4 *)(bucketEntry + 8) = 0;
      *(undefined4 *)(bucketEntry + 0xc) = 0;
      remaining = remaining + -1;
    } while (remaining != 0);
    spareNode = _gleVecAlloc((uint)*(byte *)(glContext + 0x85a4) * 4 + 0x1c);
    *(undefined4 *)(glContext + 0x7464) = spareNode;
  }
  if (bufferObject[8] != 0) {
    newNode = *(int **)(glContext + 0x7464);
    if (newNode == (int *)0x0) {
      newNode = (int *)_gleVecAlloc((uint)*(byte *)(glContext + 0x85a4) * 4 + 0x1c);
    }
    else {
      *(undefined4 *)(glContext + 0x7464) = 0;
    }
    loopIndex = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      rendererCursorBase = glContext + 0x10000;
      nameDstCursor = newNode + 7;
      srcCursor = bufferObject;
      do {
        rendererDispatch = (int *)(rendererCursorBase + -0x777c);
        copiedWord = *srcCursor;
        loopIndex = loopIndex + 1;
        srcCursor = srcCursor + 1;
        rendererHandlePtr = (undefined4 *)(rendererCursorBase + -0x7a54);
        rendererCursorBase = rendererCursorBase + 0x2e0;
        (**(code **)(*rendererDispatch + 0x1e8))(*rendererHandlePtr,copiedWord,nameDstCursor);
        nameDstCursor = nameDstCursor + 1;
      } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
    newNode[4] = bufferObject[8];
    newNode[5] = bufferObject[9];
    *(undefined2 *)(newNode + 6) = *(undefined2 *)(bufferObject + 0xb);
    bufferObject[9] = 0;
    bufferObject[8] = 0;
    orphanSize = newNode[5];
    bucketOffset = (orphanSize >> 0xc & 0x7f) * 0x30;
    newestOrphan = *(int *)(glContext + 0x7474);
    bucketSentinel = *(int *)(glContext + 0x7484) + bucketOffset;
    newNode[3] = newestOrphan;
    bucketTail = *(undefined4 **)(bucketSentinel + 0x18);
    *(int **)(newestOrphan + 8) = newNode;
    newNode[1] = (int)bucketTail;
    *bucketTail = newNode;
    newNode[2] = glContext + 0x7468;
    *newNode = bucketSentinel + 0x14;
    cachedBytes = *(int *)(glContext + 0x7454);
    orphanCount = *(int *)(glContext + 0x7458);
    *(int **)(bucketSentinel + 0x18) = newNode;
    *(int **)(glContext + 0x7474) = newNode;
    *(uint *)(glContext + 0x7454) = cachedBytes + orphanSize;
    *(int *)(glContext + 0x7458) = orphanCount + 1;
    *(int *)(bucketOffset + *(int *)(glContext + 0x7484)) =
         *(int *)(bucketOffset + *(int *)(glContext + 0x7484)) + newNode[5];
    bucketOffset = bucketOffset + *(int *)(glContext + 0x7484);
    *(int *)(bucketOffset + 4) = *(int *)(bucketOffset + 4) + 1;
  }
  sizeBucketOffset = (size + 0xfffU >> 0xc & 0x7f) * 0x30;
  bucket = sizeBucketOffset + *(int *)(glContext + 0x7484);
  candidateNode = *(int **)(bucket + 0x14);
  while( true ) {
    if (candidateNode == (int *)(bucket + 0x14)) goto LAB_000c7884;
    if ((*(ushort *)(candidateNode + 6) == usage) && ((size + 0xfffU & 0xfffff000) == candidateNode[5]))
    break;
    candidateNode = (int *)*candidateNode;
  }
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) == '\0') goto LAB_000c7744;
  nameCursor2 = candidateNode + 7;
  rendererStateCursor = (undefined4 *)(glContext + 0x85ac);
  previousIdle = true;
  do {
    allIdle = false;
    if ((previousIdle) && (bucketSentinel = (**(code **)(glContext + 0x4834))(*rendererStateCursor,*nameCursor2), bucketSentinel != 0)) {
      allIdle = true;
    }
    loopIndex = loopIndex + 1;
    rendererStateCursor = rendererStateCursor + 0xb8;
    nameCursor2 = nameCursor2 + 1;
    previousIdle = allIdle;
  } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  if (allIdle) {
LAB_000c7744:
    listPrev = candidateNode[3];
    prevNode = (undefined4 *)candidateNode[1];
    nodeNext = *candidateNode;
    *(int *)(listPrev + 8) = candidateNode[2];
    *prevNode = nodeNext;
    listHead = candidateNode[2];
    storagePtr = candidateNode[4];
    *(undefined4 **)(*candidateNode + 4) = prevNode;
    *(int *)(listHead + 0xc) = listPrev;
    candidateNode[2] = (int)candidateNode;
    candidateNode[3] = (int)candidateNode;
    *candidateNode = (int)candidateNode;
    candidateNode[1] = (int)candidateNode;
    bufferObject[8] = storagePtr;
    bufferObject[9] = candidateNode[5];
    *(undefined2 *)(bufferObject + 0xb) = *(undefined2 *)(candidateNode + 6);
    if (*(char *)(glContext + 0x85a4) != '\0') {
      nameCursor = candidateNode + 7;
      rendererCursor = glContext + 0x10000;
      loopIndex2 = 0;
      do {
        nextIndex = loopIndex2 + 1;
        bufferObject[loopIndex2 + 0xe] = bufferObject[loopIndex2 + 0xe] | 3;
        rendererDispatch2 = (int *)(rendererCursor + -0x777c);
        rendererName = *nameCursor;
        nameCursor = nameCursor + 1;
        rendererHandlePtr2 = (undefined4 *)(rendererCursor + -0x7a54);
        rendererCursor = rendererCursor + 0x2e0;
        (**(code **)(*rendererDispatch2 + 0x1ec))(*rendererHandlePtr2,bufferObject[loopIndex2],rendererName);
        loopIndex2 = nextIndex;
      } while (nextIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
    *(int *)(glContext + 0x7454) = *(int *)(glContext + 0x7454) - candidateNode[5];
    *(int *)(glContext + 0x745c) = *(int *)(glContext + 0x745c) + 1;
    *(int *)(glContext + 0x7458) = *(int *)(glContext + 0x7458) + -1;
    spareNodeSlot = *(int *)(glContext + 0x7464);
    *(int *)(sizeBucketOffset + *(int *)(glContext + 0x7484)) =
         *(int *)(sizeBucketOffset + *(int *)(glContext + 0x7484)) - candidateNode[5];
    bucketNode = sizeBucketOffset + *(int *)(glContext + 0x7484);
    *(int *)(bucketNode + 4) = *(int *)(bucketNode + 4) + -1;
    sizeBucketOffset = sizeBucketOffset + *(int *)(glContext + 0x7484);
    *(int *)(sizeBucketOffset + 8) = *(int *)(sizeBucketOffset + 8) + 1;
    if (spareNodeSlot == 0) {
      *(int **)(glContext + 0x7464) = candidateNode;
    }
    else {
      _gleVecFree(candidateNode);
    }
  }
  else {
LAB_000c7884:
    if (candidateNode != (int *)0x0) {
      sizeBucketOffset = sizeBucketOffset + *(int *)(glContext + 0x7484);
      *(int *)(sizeBucketOffset + 0xc) = *(int *)(sizeBucketOffset + 0xc) + 1;
      *(int *)(glContext + 0x7460) = *(int *)(glContext + 0x7460) + 1;
    }
  }
  if (0x4000000 < *(int *)(glContext + 0x7454)) {
    ((void (*)())_gleCleanupOrphans)(glContext);
    return;
  }
  return;
}

/* _gleCleanupOrphans @ 0xc78e8 (300 bytes) */
void _gleCleanupOrphans(glContext)
  int glContext;
{
  int *rendererDispatch;
  undefined4 *rendererHandlePtr;
  int rendererName;
  int cachedBytes;
  int nodeLink;
  int bucketOffset;
  int rendererCursor;
  int *nameCursor;
  int *nodePrev;
  int orphanSize;
  int nodeListHead;
  int loopIndex;
  int *oldestOrphan;
  
  oldestOrphan = *(int **)(glContext + 0x7470);
  cachedBytes = *(int *)(glContext + 0x7454);
  while (0x4000000 < cachedBytes) {
    loopIndex = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      nameCursor = oldestOrphan + 7;
      rendererCursor = glContext + 0x10000;
      do {
        rendererDispatch = (int *)(rendererCursor + -0x777c);
        loopIndex = loopIndex + 1;
        rendererName = *nameCursor;
        nameCursor = nameCursor + 1;
        rendererHandlePtr = (undefined4 *)(rendererCursor + -0x7a54);
        rendererCursor = rendererCursor + 0x2e0;
        (**(code **)(*rendererDispatch + 0x1f8))(*rendererHandlePtr,rendererName);
      } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
      cachedBytes = *(int *)(glContext + 0x7454);
    }
    orphanSize = oldestOrphan[5];
    *(int *)(glContext + 0x7458) = *(int *)(glContext + 0x7458) + -1;
    *(int *)(glContext + 0x7454) = cachedBytes - orphanSize;
    bucketOffset = ((uint)oldestOrphan[5] >> 0xc & 0x7f) * 0x30;
    *(int *)(bucketOffset + *(int *)(glContext + 0x7484)) =
         *(int *)(bucketOffset + *(int *)(glContext + 0x7484)) - oldestOrphan[5];
    bucketOffset = bucketOffset + *(int *)(glContext + 0x7484);
    *(int *)(bucketOffset + 4) = *(int *)(bucketOffset + 4) + -1;
    nodeListHead = oldestOrphan[3];
    nodePrev = (int *)oldestOrphan[1];
    nodeLink = *oldestOrphan;
    *(int *)(nodeListHead + 8) = oldestOrphan[2];
    *nodePrev = nodeLink;
    nodeLink = *oldestOrphan;
    *(int *)(oldestOrphan[2] + 0xc) = nodeListHead;
    *(int **)(nodeLink + 4) = nodePrev;
    oldestOrphan[2] = (int)oldestOrphan;
    oldestOrphan[3] = (int)oldestOrphan;
    *oldestOrphan = (int)oldestOrphan;
    oldestOrphan[1] = (int)oldestOrphan;
    _gleVecFree(oldestOrphan);
    oldestOrphan = *(int **)(glContext + 0x7470);
    cachedBytes = *(int *)(glContext + 0x7454);
  }
  return;
}

/* _gleSynchronizePluginBuffers @ 0xc7a14 (204 bytes) */
void _gleSynchronizePluginBuffers(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(glContext + 0x4a60);
  iVar2 = *(int *)(iVar1 + 0x358);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x40) != 0)) {
    ((double (*)())_gleSynchronizePluginBuffer)(glContext,iVar2 + 0x10);
  }
  iVar1 = *(int *)(iVar1 + 0x35c);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x40) != 0)) {
    ((double (*)())_gleSynchronizePluginBuffer)(glContext,iVar1 + 0x10);
  }
  iVar1 = *(int *)(glContext + 0x4a68);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x40) != 0)) {
    ((double (*)())_gleSynchronizePluginBuffer)(glContext,iVar1 + 0x10);
  }
  iVar1 = *(int *)(glContext + 0x4a6c);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x40) != 0)) {
    ((double (*)())_gleSynchronizePluginBuffer)(glContext,iVar1 + 0x10);
    return;
  }
  return;
}

/* _gleSynchronizePluginBuffer @ 0xc7ae0 (160 bytes) */
double _gleSynchronizePluginBuffer(glContext, param_2)
  int glContext;
  int param_2;
{
  int iVar1;
  uint loopIndex;
  int iVar3;
  
  loopIndex = 0;
  iVar3 = 0;
  if (*(byte *)(glContext + 0x85a4) != 0) {
    do {
      iVar3 = loopIndex * 4;
      if (*(int *)(param_2 + 0x30) == *(int *)(iVar3 + *(int *)(glContext + 0x5148) + 0x8054)) break;
      loopIndex = loopIndex + 1;
      iVar3 = loopIndex * 4;
    } while (loopIndex < *(byte *)(glContext + 0x85a4));
  }
  iVar1 = loopIndex * 0x2e0 + glContext;
  (**(code **)(*(int *)(iVar1 + 0x8884) + 0x1e4))
            (*(undefined4 *)(iVar1 + 0x85ac),*(undefined4 *)(iVar3 + param_2));
  *(undefined4 *)(param_2 + 0x30) = 0;
  return;
}

/* _gleReclaimBufferObjectResources @ 0xc7b80 (248 bytes) */
void _gleReclaimBufferObjectResources(glContext)
  int glContext;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  uint loopIndex;
  int *piVar6;
  int iVar7;
  int *piVar8;
  
  iVar3 = *(int *)(glContext + 0x5148);
  piVar6 = (int *)(iVar3 + 0x701c);
  do {
    piVar4 = piVar6 + 1;
    for (piVar6 = (int *)*piVar6; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
      if (piVar6[2] == 1) {
        if (piVar6[0x10] != 0) {
          ((double (*)())_gleSynchronizePluginBuffer)(glContext,piVar6 + 4);
        }
        loopIndex = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          iVar7 = glContext + 0x10000;
          piVar8 = piVar6;
          do {
            piVar1 = (int *)(iVar7 + -0x777c);
            loopIndex = loopIndex + 1;
            puVar2 = (undefined4 *)(iVar7 + -0x7a54);
            iVar7 = iVar7 + 0x2e0;
            (**(code **)(*piVar1 + 0x1e0))(*puVar2,*(undefined4 *)((int)piVar8 + 0x10));
            *(uint *)((int)piVar8 + 0x48) = *(uint *)((int)piVar8 + 0x48) | 1;
            piVar8 = (int *)((int)piVar8 + 4);
          } while (loopIndex < *(byte *)(glContext + 0x85a4));
        }
      }
    }
    piVar6 = piVar4;
  } while (piVar4 <= (int *)(iVar3 + 0x8018));
  iVar3 = *(int *)(glContext + 0x4a60);
  *(undefined4 *)(iVar3 + 0x350) = *(undefined4 *)(iVar3 + 0x350);
  *(uint *)(iVar3 + 0x354) = *(uint *)(iVar3 + 0x354) | 0x10;
  return;
}

/* _OffsetLimitImage3D @ 0xc7c78 (408 bytes) */
int _OffsetLimitImage3D(pixelStore, width, height, depth, format, type, baseOffset, skipImages)
  int *pixelStore;
  int width;
  int height;
  int depth;
  undefined4 format;
  int type;
  int baseOffset;
  int skipImages;
{
  uint uVar1;
  uint rowStride;
  int skipRows;
  int alignment;
  int skipPixels;
  int imageHeight;
  int iVar7;
  int rowLength;
  
  skipRows = pixelStore[2];
  rowLength = *pixelStore;
  imageHeight = pixelStore[1];
  alignment = pixelStore[5];
  skipPixels = pixelStore[3];
  if (type == 0x1a00) {
    if (rowLength < 1) {
      rowLength = width;
    }
    if (imageHeight < 1) {
      imageHeight = height;
    }
    uVar1 = rowLength + 7;
    rowStride = ((int)uVar1 >> 3) + (uint)((int)uVar1 < 0 && (uVar1 & 7) != 0);
    uVar1 = rowStride & alignment - 1U;
    if (uVar1 != 0) {
      rowStride = rowStride + (alignment - uVar1);
    }
    uVar1 = skipPixels + width + 7;
    iVar7 = baseOffset + imageHeight * rowStride * (skipImages + depth + -1) + rowStride * (skipRows + height + -1) +
            ((int)uVar1 >> 3) + (uint)((int)uVar1 < 0 && (uVar1 & 7) != 0);
  }
  else {
    iVar7 = _glePixelBytes(format,type);
    if ((((rowLength == 0 && imageHeight == 0) && skipPixels == 0) && skipRows == 0) && skipPixels == 0) {
      rowStride = _gleRowBytes(format,type,width);
      uVar1 = rowStride & alignment - 1U;
      if (uVar1 != 0) {
        rowStride = rowStride + (alignment - uVar1);
      }
      iVar7 = depth * height * rowStride;
    }
    else {
      if (rowLength < 1) {
        rowLength = width;
      }
      if (imageHeight < 1) {
        imageHeight = height;
      }
      rowStride = _gleRowBytes(format,type,rowLength);
      uVar1 = rowStride & alignment - 1U;
      if (uVar1 != 0) {
        rowStride = rowStride + (alignment - uVar1);
      }
      iVar7 = iVar7 * (skipPixels + width);
      baseOffset = baseOffset + imageHeight * rowStride * (skipImages + depth + -1) + rowStride * (skipRows + height + -1);
    }
    iVar7 = baseOffset + iVar7;
  }
  return iVar7;
}

/* _gleOffsetLimitImage3D @ 0xc7e10 (8 bytes) */
int _gleOffsetLimitImage3D(pixelStore, width, height, depth, format, type, offset)
  int pixelStore;
  undefined4 width;
  undefined4 height;
  undefined4 depth;
  undefined4 format;
  undefined4 type;
  undefined4 offset;
{
  return ((int (*)())_OffsetLimitImage3D)(pixelStore,width,height,depth,format,type,offset,
                      *(undefined4 *)(pixelStore + 0x10));
}

/* _gleOffsetLimitImage @ 0xc7e18 (28 bytes) */
int _gleOffsetLimitImage(pixelStore, width, height, format, type, offset)
  undefined4 pixelStore;
  undefined4 width;
  undefined4 height;
  undefined4 format;
  undefined4 type;
  undefined4 offset;
{
  return ((int (*)())_OffsetLimitImage3D)(pixelStore,width,height,1,format,type,offset,0);
}

/* _gleFreeCopyContextData @ 0xc7e38 (104 bytes) */
int _gleFreeCopyContextData(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 8) != 0) {
    _free(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    _free(*(int *)(param_1 + 0xc));
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    _free(*(int *)(param_1 + 0x10));
    return;
  }
  return;
}

/* _gleSwitchToRenderer @ 0xc7ea0 (564 bytes) */
int _gleSwitchToRenderer(glContext, param_2)
  int glContext;
  uint param_2;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int remaining;
  undefined *puVar4;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  uint uVar5;
  uint dispatchFlags;
  uint uVar6;
  undefined4 *a2;
  
  iVar3 = param_2 * 0x2e0 + glContext;
  uVar1 = *(undefined4 *)(iVar3 + 0x85ac);
  *(int *)(glContext + 0x468c) = iVar3 + 0x85b0;
  *(undefined4 *)(glContext + 0x4688) = uVar1;
  a2 = (undefined4 *)(glContext + 0x310);
  _memcpy(glContext + 0x4754,*(int *)(iVar3 + 0x8884) + 0x114,0xf4);
  (**(code **)(glContext + 0x4784))
            (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,glContext + 0x471c);
  uVar5 = *(uint *)(glContext + 0x31c) | 0x7ffffff;
  *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x3ffffff;
  *(uint *)(glContext + 0x318) = *(uint *)(glContext + 0x318) | 0xfffffffd;
  *(uint *)(glContext + 0x31c) = uVar5;
  *(undefined4 *)(glContext + 800) = 0xffffffff;
  *(undefined4 *)(glContext + 0x310) = 0xffffffff;
  dispatchFlags = (**(code **)(glContext + 0x4788))
                    (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,a2,incomingR6,incomingR7,incomingR8,dispatchFlags);
  remaining = 0x13;
  do {
    *a2 = 0;
    a2 = a2 + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  uVar2 = (dispatchFlags ^ 8) >> 3 & 1;
  if (uVar2 != *(byte *)(glContext + 0x759d)) {
    *(char *)(glContext + 0x759d) = (char)uVar2;
    ((void (*)())_gleUpdateFramebufferOperationFuncs)(glContext);
  }
  if ((dispatchFlags & 4) == 0) {
    dispatchFlags = dispatchFlags & 0xfffffffe;
  }
  if ((param_2 == *(byte *)(glContext + 0x85a5)) && (*(char *)(glContext + 0x85a7) != '\x01')) {
    uVar2 = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x938) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & uVar2 | *(uint *)(glContext + 0x4684) & ~uVar2) + 0x938) =
         PTR__glSwap_RevertExec_00112128;
    uVar2 = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x168) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & uVar2 | *(uint *)(glContext + 0x4684) & ~uVar2) + 0x168) =
         PTR__glFlush_RevertExec_00112124;
    uVar6 = *(uint *)(glContext + 0x4684);
    uVar2 = *(uint *)(glContext + 0x4680);
    iVar3 = *(int *)(uVar6 + 0x164);
    puVar4 = PTR__glFinish_RevertExec_00112120;
  }
  else {
    uVar2 = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x938) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & uVar2 | *(uint *)(glContext + 0x4684) & ~uVar2) + 0x938) =
         PTR__glSwap_Exec_0011211c;
    uVar2 = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x168) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & uVar2 | *(uint *)(glContext + 0x4684) & ~uVar2) + 0x168) =
         PTR__glFlush_Exec_00112118;
    uVar6 = *(uint *)(glContext + 0x4684);
    uVar2 = *(uint *)(glContext + 0x4680);
    iVar3 = *(int *)(uVar6 + 0x164);
    puVar4 = PTR__glFinish_Exec_00112114;
  }
  *(undefined **)((uVar2 & -(uint)(iVar3 == 0) | uVar6 & ~-(uint)(iVar3 == 0)) + 0x164) = puVar4;
  return dispatchFlags;
}

/* _gleRecoverySaveState @ 0xc80d4 (280 bytes) */
double _gleRecoverySaveState(glContext, recoveryStateBuffer)
  int glContext;
  int *recoveryStateBuffer;
{
  int savedUnitWord;
  int loopIndex;
  int *saveCursor;
  int unitState;
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  *(undefined1 *)(recoveryStateBuffer + 0x12) = *(undefined1 *)(glContext + 0x3128);
  if (*(char *)(recoveryStateBuffer + 0x12) != '\0') {
    _glDisable_Exec(glContext,0xb71);
  }
  *(undefined1 *)((int)recoveryStateBuffer + 0x4a) = *(undefined1 *)(glContext + 0x30c6);
  if (*(char *)((int)recoveryStateBuffer + 0x4a) != '\0') {
    _glDisable_Exec(glContext,0xbc0);
  }
  loopIndex = 0;
  if (*(short *)(*(int *)(glContext + 0x468c) + 0xb4) != 0) {
    unitState = glContext + 0x3530;
    saveCursor = recoveryStateBuffer;
    do {
      savedUnitWord = *(int *)(unitState + 4);
      *saveCursor = savedUnitWord;
      saveCursor = saveCursor + 1;
      if (savedUnitWord != 0) {
        *(undefined4 *)(unitState + 4) = 0;
        _gleUpdateTextureParams(glContext,loopIndex);
      }
      loopIndex = loopIndex + 1;
      unitState = unitState + 0x7c;
    } while (loopIndex < (int)(uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xb4));
  }
  recoveryStateBuffer[0x10] = (uint)*(byte *)(glContext + 0x466c);
  forwardedFloatArg1 = (double)_glDisable_Exec(glContext,0x8804);
  if (*(int *)(glContext + 0x5430) == 0) {
    recoveryStateBuffer[0x11] = 0;
  }
  else {
    recoveryStateBuffer[0x11] = *(int *)(*(int *)(glContext + 0x5430) + 4);
    ((void (*)())_glUseProgramObjectARB_Exec)(glContext,0,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  }
                    
                    
  (**(code **)(glContext + 0x4788))
            (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,glContext + 0x310);
  return;
}

/* _gleRecoveryRestoreState @ 0xc81ec (276 bytes) */
void _gleRecoveryRestoreState(int glContext,int *param_2,double fparam_1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  int iVar1;
  int iVar2;
  int loopIndex;
  int *piVar4;
  int iVar5;
  double f1AfterCall;
  
  if (*(char *)(param_2 + 0x12) != '\0') {
    fparam_1 = (double)_glEnable_Exec(glContext,0xb71);
  }
  if (*(char *)((int)param_2 + 0x4a) != '\0') {
    fparam_1 = (double)_glEnable_Exec(glContext,0xbc0);
  }
  iVar2 = *(int *)(glContext + 0x468c);
  loopIndex = 0;
  if (*(short *)(iVar2 + 0xb4) != 0) {
    iVar5 = glContext + 0x3530;
    piVar4 = param_2;
    do {
      iVar1 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar1 != *(int *)(iVar5 + 4)) {
        *(int *)(iVar5 + 4) = iVar1;
        _gleUpdateTextureParams(glContext,loopIndex);
        iVar2 = *(int *)(glContext + 0x468c);
        fparam_1 = f1AfterCall;
      }
      loopIndex = loopIndex + 1;
      iVar5 = iVar5 + 0x7c;
    } while (loopIndex < (int)(uint)*(ushort *)(iVar2 + 0xb4));
  }
  if (param_2[0x10] != (uint)*(byte *)(glContext + 0x466c)) {
    if (param_2[0x10] == 0) {
      fparam_1 = (double)_glDisable_Exec(glContext,0x8804);
    }
    else {
      fparam_1 = (double)_glEnable_Exec(glContext,0x8804);
    }
  }
  if (param_2[0x11] != 0) {
    ((void (*)())_glUseProgramObjectARB_Exec)(glContext,param_2[0x11],fparam_1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,
               floatArg8);
  }
                    
                    
  (**(code **)(glContext + 0x4788))
            (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,glContext + 0x310);
  return;
}

/* _gleToggleScissorEnableState @ 0xc8300 (88 bytes) */
undefined4 _gleToggleScissorEnableState(int glContext,undefined4 param_2,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  *(undefined1 *)(glContext + 0x34f0) = (undefined1)param_2;
  ((void (*)())_gleUpdateViewScissorData)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x4000000;
  (**(code **)(glContext + 0x4788))
            (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,glContext + 0x310);
  return 0;
}

/* _gleSwitchRenderersReadBuffers @ 0xc8358 (452 bytes) */
void _gleSwitchRenderersReadBuffers(glContext, rendererIndex, copyContextData)
  int glContext;
  int rendererIndex;
  int *copyContextData;
{
  int iVar1;
  uint dirtyBitsAfterRead;
  int readWidth;
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  undefined1 recoveryStateBuffer [80];
  undefined4 savedWord0;
  undefined4 savedWord1;
  undefined4 savedWord2;
  undefined4 savedWord3;
  undefined4 savedWord4;
  undefined4 savedWord5;
  undefined4 savedWord6;
  
  savedWord0 = *(undefined4 *)(glContext + 0x31b0);
  savedWord1 = *(undefined4 *)(0x31b4 + glContext);
  savedWord2 = *(undefined4 *)(glContext + 0x31b8);
  savedWord3 = *(undefined4 *)(glContext + 0x31bc);
  savedWord4 = *(undefined4 *)(glContext + 0x31c0);
  savedWord5 = *(undefined4 *)(glContext + 0x31c4);
  savedWord6 = *(undefined4 *)(glContext + 0x31c8);
  if (*(char *)(glContext + 0x759d) != '\0') {
    *(undefined4 *)(glContext + 0x31c4) = 1;
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x200000;
    *(undefined4 *)(glContext + 0x31b0) = 0;
    *(undefined4 *)(0x31b4 + glContext) = 0;
    *(undefined4 *)(glContext + 0x31b8) = 0;
    *(undefined4 *)(glContext + 0x31bc) = 0;
    *(undefined4 *)(glContext + 0x31c0) = 0;
    *(undefined1 *)(glContext + 0x31c8) = 0;
    *(undefined1 *)(glContext + 0x31c9) = 0;
    *(undefined1 *)(glContext + 0x31ca) = 0;
    ((double (*)())_gleRecoverySaveState)(glContext,recoveryStateBuffer);
    readWidth = *(int *)(glContext + 0x1ba8);
    copyContextData[1] = readWidth;
    iVar1 = *(int *)(glContext + 0x1bac);
    *copyContextData = iVar1;
    iVar1 = _malloc(readWidth * iVar1 * 4);
    copyContextData[2] = iVar1;
    fparam_1 = (double)(**(double ( **)(int,int,int,int,int,int,int,int))(glContext + 0x46a0))
                                 (*(undefined4 *)(glContext + 0x4688), 0, 0, copyContextData[1], *copyContextData, 0x80e1, 0x8367, iVar1);
    if (*(int *)(rendererIndex * 0x2e0 + glContext + 0x85ec) != 0) {
      iVar1 = _malloc(copyContextData[1] * *copyContextData * 4);
      copyContextData[4] = iVar1;
      fparam_1 = (double)(**(double ( **)(int,int,int,int,int,int,int,int))(glContext + 0x46a0))
                                   (*(undefined4 *)(glContext + 0x4688), 0, 0, copyContextData[1], *copyContextData, 0x1902, 0x1406, iVar1);
    }
    dirtyBitsAfterRead = *(uint *)(glContext + 0x310);
    *(undefined4 *)(0x31b4 + glContext) = savedWord1;
    *(undefined4 *)(glContext + 0x31b0) = savedWord0;
    *(undefined4 *)(glContext + 0x31b8) = savedWord2;
    *(undefined4 *)(glContext + 0x31bc) = savedWord3;
    *(undefined4 *)(glContext + 0x31c0) = savedWord4;
    *(undefined4 *)(glContext + 0x31c4) = savedWord5;
    *(undefined4 *)(glContext + 0x31c8) = savedWord6;
    *(uint *)(glContext + 0x310) = dirtyBitsAfterRead | 0x200000;
    ((void (*)())_gleRecoveryRestoreState)(glContext,recoveryStateBuffer,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  }
  return;
}

/* _gleSwitchRenderersWriteBuffers @ 0xc851c (616 bytes) */
void _gleSwitchRenderersWriteBuffers(glContext, unusedArg2, copyContextData)
  int glContext;
  undefined4 unusedArg2;
  undefined4 *copyContextData;
{
  bool scissorWasEnabled;
  ushort savedDepthFunc;
  double saveStateResult;
  double viewportOffsetY;
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  float local_1a0;
  float scaledVertexY;
  float scaledVertexZ;
  undefined1 auStack_a0 [80];
  undefined4 savedWord0;
  undefined4 savedWord1;
  undefined4 savedWord2;
  undefined4 savedWord3;
  undefined4 savedWord4;
  undefined4 savedWord5;
  undefined4 savedWord6;
  
  savedWord0 = *(undefined4 *)(glContext + 0x31cc);
  savedWord1 = *(undefined4 *)(glContext + 0x31d0);
  savedWord2 = *(undefined4 *)(glContext + 0x31d4);
  savedWord3 = *(undefined4 *)(glContext + 0x31d8);
  savedWord4 = *(undefined4 *)(glContext + 0x31dc);
  savedWord5 = *(undefined4 *)(glContext + 0x31e0);
  savedWord6 = *(undefined4 *)(glContext + 0x31e4);
  if (*(char *)(glContext + 0x759d) != '\0') {
    scissorWasEnabled = *(char *)(glContext + 0x34f0) != '\0';
    *(undefined4 *)(glContext + 0x31e0) = 1;
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x200000;
    *(undefined4 *)(glContext + 0x31cc) = 0;
    *(undefined4 *)(glContext + 0x31d0) = 0;
    *(undefined4 *)(glContext + 0x31d4) = 0;
    *(undefined4 *)(glContext + 0x31d8) = 0;
    *(undefined4 *)(glContext + 0x31dc) = 0;
    *(undefined1 *)(glContext + 0x31e4) = 0;
    *(undefined1 *)(glContext + 0x31e5) = 0;
    *(undefined1 *)(glContext + 0x31e6) = 0;
    saveStateResult = (double)((double (*)())_gleRecoverySaveState)(glContext,auStack_a0);
    if (scissorWasEnabled) {
      ((undefined4 (*)())_gleToggleScissorEnableState)(glContext,0,saveStateResult,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
    }
    _memset(&local_1a0,0,0x100);
    local_1a0 = *(float *)(glContext + 0x4a44) * local_1a0 + *(float *)(glContext + 0x4a48);
    viewportOffsetY = (double)*(float *)(glContext + 0x4a50);
    scaledVertexY = (float)((double)*(float *)(glContext + 0x4a4c) * (double)scaledVertexY + viewportOffsetY);
    scaledVertexZ = *(float *)(glContext + 0x4a54) * scaledVertexZ;
    if (copyContextData[4] != 0) {
      savedDepthFunc = *(ushort *)(glContext + 0x3124);
      _glEnable_Exec(glContext,0xb71);
      _glDepthFunc_Exec(glContext,0x207);
      (**(code **)(glContext + 0x4788))
                (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,glContext + 0x310);
      (**(code **)(glContext + 0x46a4))
                (*(undefined4 *)(glContext + 0x4688),&local_1a0,copyContextData[1],*copyContextData,0x1902,0x1406,
                 copyContextData[4],0);
      _glDisable_Exec(glContext,0xb71);
      _glDepthFunc_Exec(glContext,(uint)savedDepthFunc);
      (**(code **)(glContext + 0x4788))
                (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,glContext + 0x310);
    }
    fparam_1 = (double)(**(double ( **)(int,int,int,int,int,int,int,int))(glContext + 0x46a4))
                                 (*(undefined4 *)(glContext + 0x4688), &local_1a0, copyContextData[1], *copyContextData, 0x80e1, 0x8367, copyContextData[2], 0);
    if (scissorWasEnabled) {
      fparam_1 = (double)((undefined4 (*)())_gleToggleScissorEnableState)(glContext,1,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,viewportOffsetY);
    }
    *(undefined4 *)(glContext + 0x31d0) = savedWord1;
    *(undefined4 *)(glContext + 0x31cc) = savedWord0;
    *(undefined4 *)(glContext + 0x31d4) = savedWord2;
    *(undefined4 *)(glContext + 0x31d8) = savedWord3;
    *(undefined4 *)(glContext + 0x31dc) = savedWord4;
    *(undefined4 *)(glContext + 0x31e0) = savedWord5;
    *(undefined4 *)(glContext + 0x31e4) = savedWord6;
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x200000;
    ((void (*)())_gleRecoveryRestoreState)(glContext,auStack_a0,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,viewportOffsetY);
  }
  return;
}

/* _gleRevertSwapToPrimary @ 0xc8784 (172 bytes) */
int _gleRevertSwapToPrimary(glContext)
  int glContext;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  uVar3 = (uint)*(byte *)(glContext + 0x85a6);
  local_20 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  ((void (*)())_gleSwitchRenderersReadBuffers)(glContext,(uint)*(byte *)(glContext + 0x85a5),&local_30);
  iVar1 = uVar3 * 0x2e0 + glContext;
  (**(code **)(*(int *)(iVar1 + 0x8884) + 0x138))
            (*(undefined4 *)(iVar1 + 0x85ac),*(undefined4 *)(glContext + 0x484c),
             *(undefined4 *)(glContext + 0x4848),0);
  fparam_1 = (double)((int (*)())_gleSwitchToRenderer)(glContext,uVar3);
  ((void (*)())_gleUpdateViewScissorData)(glContext,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  ((void (*)())_gleSwitchRenderersWriteBuffers)(glContext,uVar3,&local_30);
  uVar2 = ((int (*)())_gleFreeCopyContextData)(&local_30);
  return uVar2;
}

/* _gleGetMapData @ 0xc8830 (88 bytes) */
int _gleGetMapData(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x7450);
  if (iVar1 == 0) {
    uVar2 = _malloc(0x9dcc);
    *(undefined4 *)(param_1 + 0x7450) = uVar2;
    _gleInitMap1Data(param_1);
    _gleInitMap2Data(param_1);
    iVar1 = *(int *)(param_1 + 0x7450);
  }
  return iVar1;
}

/* _gleReclaimContextResources @ 0xc8888 (276 bytes) */
void _gleReclaimContextResources(glContext)
  int glContext;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  uint loopIndex;
  
  if (*(int *)(glContext + 0x7484) != 0) {
    _gleFreeOrphans(glContext);
  }
  _gleReclaimDrawPixelResources(glContext);
  if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
    _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
  }
  ((void (*)())_gleReclaimDisplayListResources)(glContext);
  _gleReclaimTextureObjectResources(glContext);
  ((void (*)())_gleReclaimBufferObjectResources)(glContext);
  _gleReclaimVertexArrayResources(glContext);
  if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
    _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
  }
  iVar3 = glContext + 0x10000;
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      loopIndex = loopIndex + 1;
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      iVar3 = iVar3 + 0x2e0;
      (**(code **)(*piVar1 + 0x134))(*puVar2);
    } while (loopIndex < *(byte *)(glContext + 0x85a4));
  }
  *(undefined4 *)(glContext + 800) = 0xffffffff;
  *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x3ffffff;
  *(uint *)(glContext + 0x318) = *(uint *)(glContext + 0x318) | 0xfffffffd;
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x7ffffff;
  *(undefined4 *)(glContext + 0x310) = 0xffffffff;
  return;
}

/* _gleSwitchToNonRevertRenderer @ 0xc899c (516 bytes) */
double _gleSwitchToNonRevertRenderer(glContext)
  int glContext;
{
  byte currentRenderer;
  byte switchFlags;
  byte alternateRenderer;
  undefined *setClipInterpFunc;
  int rendererSlot;
  uint validateResult;
  uint switchResult;
  undefined4 switchResult2;
  uint currentRendererIndex;
  double fparam_1;
  double fparam_1_00;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  double incomingStack_ffffff98;
  double incomingStack_ffffffa0;
  double incomingStack_ffffffa8;
  undefined4 copyContextData;
  undefined4 copyContextData1;
  undefined4 copyContextData2;
  undefined4 copyContextData3;
  undefined4 copyContextData4;
  
  currentRenderer = *(byte *)(glContext + 0x85a6);
  currentRendererIndex = (uint)currentRenderer;
  rendererSlot = currentRendererIndex * 0x2e0 + glContext;
  validateResult = (**(code **)(*(int *)(rendererSlot + 0x8884) + 0x138))
                    (*(undefined4 *)(rendererSlot + 0x85ac),*(undefined4 *)(glContext + 0x484c),
                     *(undefined4 *)(glContext + 0x4848),0);
  if (validateResult < 5) {
    _gleSynchronizePluginFramebuffer(glContext);
    _gleSynchronizePluginTextures(glContext);
    ((void (*)())_gleSynchronizePluginBuffers)(glContext);
    switchResult = ((int (*)())_gleSwitchToRenderer)(glContext,currentRendererIndex);
    if ((switchResult & 4) == 0) {
      alternateRenderer = *(byte *)(glContext + 0x85a5);
      rendererSlot = (uint)alternateRenderer * 0x2e0 + glContext;
      (**(code **)(*(int *)(rendererSlot + 0x8884) + 0x138))
                (*(undefined4 *)(rendererSlot + 0x85ac),*(undefined4 *)(glContext + 0x484c),
                 *(undefined4 *)(glContext + 0x4848),0);
      ((int (*)())_gleSwitchToRenderer)(glContext,(uint)alternateRenderer);
    }
    else {
      ((int (*)())_gleSwitchToRenderer)(glContext,(uint)*(byte *)(glContext + 0x85a5));
      copyContextData = 0;
      copyContextData1 = 0;
      copyContextData2 = 0;
      copyContextData3 = 0;
      copyContextData4 = 0;
      ((void (*)())_gleSwitchRenderersReadBuffers)(glContext,(uint)*(byte *)(glContext + 0x85a5),&copyContextData);
      fparam_1 = (double)((int (*)())_gleSwitchToRenderer)(glContext,currentRendererIndex);
      *(byte *)(glContext + 0x85a8) = currentRenderer;
      ((void (*)())_gleUpdateDepthRangeData)(glContext,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff88,
                 incomingStack_ffffff90,incomingStack_ffffff98,incomingStack_ffffffa0,incomingStack_ffffffa8);
      _gleUpdatePolyMode(glContext);
      ((void (*)())_gleUpdateViewScissorData)(glContext,fparam_1_00,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
      _gleUpdateTextureTransform(glContext);
      setClipInterpFunc = PTR__gleSetClipInterpFunc_00112038;
      *(undefined **)(glContext + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
      *(undefined **)(glContext + 0x49cc) = setClipInterpFunc;
      _gleSetColorMaterialEnable(glContext);
      *(undefined4 *)(glContext + 0x48d0) = 0;
      *(undefined4 *)(glContext + 0x48d4) = 0;
      _gleUpdatePrimitiveData(glContext);
      _gleUpdateDrawArraysFuncs(glContext);
      _gleSelectVertexSubmitFunc(glContext);
      *(undefined4 *)(glContext + 0x488c) = 0;
      *(undefined4 *)(glContext + 0x4890) = 0;
      *(undefined4 *)(glContext + 0x4894) = 0;
      ((void (*)())_gleSwitchRenderersWriteBuffers)(glContext,currentRendererIndex,&copyContextData);
      ((int (*)())_gleFreeCopyContextData)(&copyContextData);
    }
    switchFlags = (byte)switchResult;
    *(uint *)(glContext + 0x757c) = switchResult;
    *(char *)(glContext + 0x7581) = (char)(switchResult & 4);
  }
  else {
    if (validateResult != 0x2720) {
      return;
    }
    alternateRenderer = *(byte *)(glContext + 0x85a5);
    rendererSlot = (uint)alternateRenderer * 0x2e0 + glContext;
    (**(code **)(*(int *)(rendererSlot + 0x8884) + 0x138))
              (*(undefined4 *)(rendererSlot + 0x85ac),*(undefined4 *)(glContext + 0x484c),
               *(undefined4 *)(glContext + 0x4848),1);
    switchResult2 = ((int (*)())_gleSwitchToRenderer)(glContext,(uint)alternateRenderer);
    switchFlags = (byte)switchResult2;
    *(undefined4 *)(glContext + 0x757c) = switchResult2;
  }
  *(byte *)(glContext + 0x7580) = switchFlags & 1;
  return;
}

/* _gleUpdateDispatchCodeChange @ 0xc8ba0 (528 bytes) */
double _gleUpdateDispatchCodeChange(glContext, dispatchModeBits)
  int glContext;
  uint dispatchModeBits;
{
  byte rendererIndexByte;
  undefined *a6;
  undefined *setEyeInterpFunc;
  uint uVar3;
  uint dispatchFlags;
  int rendererRecord;
  undefined4 a3;
  undefined4 incomingR7;
  uint rendererIndex;
  double fparam_1;
  double fparam_1_00;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  double incomingStack_ffffff98;
  double incomingStack_ffffffa0;
  double incomingStack_ffffffa8;
  uint copyContextWord0;
  uint copyContextWord1;
  uint copyContextWord2;
  uint copyContextWord3;
  uint copyContextWord4;
  
  if ((dispatchModeBits & 4) != (uint)*(byte *)(glContext + 0x7581)) {
    *(char *)(glContext + 0x7581) = (char)(dispatchModeBits & 4);
    uVar3 = (uint)*(byte *)(glContext + 0x7581);
    if (uVar3 == 0) {
      rendererIndexByte = *(byte *)(glContext + 0x85a5);
      rendererIndex = (uint)rendererIndexByte;
      if (rendererIndex != 0xff) {
        copyContextWord0 = uVar3;
        copyContextWord1 = uVar3;
        copyContextWord2 = uVar3;
        copyContextWord3 = uVar3;
        copyContextWord4 = uVar3;
        ((void (*)())_gleSwitchRenderersReadBuffers)(glContext,(uint)*(byte *)(glContext + 0x85a6),&copyContextWord0);
        a3 = 0;
        rendererRecord = rendererIndex * 0x2e0 + glContext;
        uVar3 = (**(code **)(*(int *)(rendererRecord + 0x8884) + 0x138))
                          (*(undefined4 *)(rendererRecord + 0x85ac),*(undefined4 *)(glContext + 0x484c),
                           *(undefined4 *)(glContext + 0x4848));
        if ((uVar3 < 5) && (rendererIndex != *(byte *)(glContext + 0x85a8))) {
          _gleSynchronizePluginTextures(glContext);
          ((void (*)())_gleSynchronizePluginBuffers)(glContext);
          *(byte *)(glContext + 0x85a8) = rendererIndexByte;
          fparam_1 = (double)((int (*)())_gleSwitchToRenderer)(glContext,(uint)*(byte *)(glContext + 0x85a5));
          ((void (*)())_gleUpdateDepthRangeData)(glContext,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff88,
                     incomingStack_ffffff90,incomingStack_ffffff98,incomingStack_ffffffa0,incomingStack_ffffffa8);
          _gleUpdatePolyMode(glContext);
          ((void (*)())_gleUpdateViewScissorData)(glContext,fparam_1_00,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
          _gleUpdateTextureTransform(glContext);
          setEyeInterpFunc = PTR__gleSetEyeInterpFunc_0011203c;
          a6 = PTR__gleSetClipInterpFunc_00112038;
          uVar3 = *(uint *)(glContext + 0x31c) | 0x7ffffff;
          *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x3ffffff;
          *(undefined **)(glContext + 0x49c8) = setEyeInterpFunc;
          *(undefined **)(glContext + 0x49cc) = a6;
          *(uint *)(glContext + 0x318) = *(uint *)(glContext + 0x318) | 0xfffffffd;
          *(uint *)(glContext + 0x31c) = uVar3;
          *(undefined4 *)(glContext + 800) = 0xffffffff;
          *(undefined4 *)(glContext + 0x310) = 0xffffffff;
          dispatchFlags = (**(code **)(glContext + 0x4788))
                            (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,glContext + 0x310,a3,
                             incomingR7,0xffffffff,a6,dispatchFlags);
          if ((dispatchFlags & 8) == 0) {
            ((void (*)())_gleSwitchRenderersWriteBuffers)(glContext,(uint)*(byte *)(glContext + 0x85a5),&copyContextWord0);
          }
          dispatchModeBits = 0;
        }
        ((int (*)())_gleFreeCopyContextData)(&copyContextWord0);
      }
    }
  }
  if ((dispatchModeBits & 3) != (uint)*(byte *)(glContext + 0x7580)) {
    *(byte *)(glContext + 0x7580) = (byte)dispatchModeBits & 1;
    _gleSetColorMaterialEnable(glContext);
    *(undefined4 *)(glContext + 0x48d0) = *(undefined4 *)(*(int *)(glContext + 0x468c) + 0x11c);
    *(undefined4 *)(glContext + 0x48d4) = *(undefined4 *)(*(int *)(glContext + 0x468c) + 0x120);
    _gleUpdatePrimitiveData(glContext);
    _gleUpdateDrawArraysFuncs(glContext);
    _gleSelectVertexSubmitFunc(glContext);
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
    *(undefined4 *)(glContext + 0x4894) = 0;
  }
  uVar3 = (dispatchModeBits ^ 8) >> 3 & 1;
  if (uVar3 != *(byte *)(glContext + 0x759d)) {
    *(char *)(glContext + 0x759d) = (char)uVar3;
    ((void (*)())_gleUpdateFramebufferOperationFuncs)(glContext);
  }
  return;
}

/* _gleUpdateFramebufferOperationFuncs @ 0xc8db0 (928 bytes) */
void _gleUpdateFramebufferOperationFuncs(glContext)
  int glContext;
{
  int entry;
  undefined *bitmapHandler;
  undefined *beginHandler;
  uint emptyMask;
  uint maskThenTable;
  uint primaryTable;
  uint secondaryTable;
  
  if (*(int *)(glContext + 0x5408) == 0) {
    if (*(char *)(glContext + 0x759d) == '\0') {
      emptyMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x28) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & emptyMask | *(uint *)(glContext + 0x4684) & ~emptyMask) + 0x28) =
           PTR__glClear_NoopExec_001120c0;
      emptyMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xd0) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & emptyMask | *(uint *)(glContext + 0x4684) & ~emptyMask) + 0xd0) =
           PTR__glCopyPixels_NoopExec_001120bc;
      emptyMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xd4) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & emptyMask | *(uint *)(glContext + 0x4684) & ~emptyMask) + 0xd4) =
           PTR__glCopyTexImage1D_NoopExec_001120b8;
      emptyMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xd8) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & emptyMask | *(uint *)(glContext + 0x4684) & ~emptyMask) + 0xd8) =
           PTR__glCopyTexImage2D_NoopExec_001120b4;
      emptyMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xdc) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & emptyMask | *(uint *)(glContext + 0x4684) & ~emptyMask) + 0xdc) =
           PTR__glCopyTexSubImage1D_NoopExec_001120b0;
      emptyMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xe0) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & emptyMask | *(uint *)(glContext + 0x4684) & ~emptyMask) + 0xe0) =
           PTR__glCopyTexSubImage2D_NoopExec_001120ac;
      emptyMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6e0) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & emptyMask | *(uint *)(glContext + 0x4684) & ~emptyMask) + 0x6e0) =
           PTR__glCopyTexSubImage3D_NoopExec_001120a8;
      emptyMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x110) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & emptyMask | *(uint *)(glContext + 0x4684) & ~emptyMask) + 0x110) =
           PTR__glDrawPixels_NoopExec_001120a4;
      secondaryTable = *(uint *)(glContext + 0x4684);
      primaryTable = *(uint *)(glContext + 0x4680);
      entry = *(int *)(secondaryTable + 0x18);
      bitmapHandler = PTR__glBitmap_NoopExec_001120a0;
    }
    else {
      emptyMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x28) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & emptyMask | *(uint *)(glContext + 0x4684) & ~emptyMask) + 0x28) =
           PTR__glClear_Exec_0011209c;
      emptyMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xd0) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & emptyMask | *(uint *)(glContext + 0x4684) & ~emptyMask) + 0xd0) =
           PTR__glCopyPixels_Exec_00112098;
      emptyMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xd4) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & emptyMask | *(uint *)(glContext + 0x4684) & ~emptyMask) + 0xd4) =
           PTR__glCopyTexImage1D_Exec_00112094;
      emptyMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xd8) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & emptyMask | *(uint *)(glContext + 0x4684) & ~emptyMask) + 0xd8) =
           PTR__glCopyTexImage2D_Exec_00112090;
      emptyMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xdc) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & emptyMask | *(uint *)(glContext + 0x4684) & ~emptyMask) + 0xdc) =
           PTR__glCopyTexSubImage1D_Exec_0011208c;
      emptyMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xe0) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & emptyMask | *(uint *)(glContext + 0x4684) & ~emptyMask) + 0xe0) =
           PTR__glCopyTexSubImage2D_Exec_00112088;
      emptyMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6e0) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & emptyMask | *(uint *)(glContext + 0x4684) & ~emptyMask) + 0x6e0) =
           PTR__glCopyTexSubImage3D_Exec_00112084;
      emptyMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x110) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & emptyMask | *(uint *)(glContext + 0x4684) & ~emptyMask) + 0x110) =
           PTR__glDrawPixels_Exec_00112080;
      secondaryTable = *(uint *)(glContext + 0x4684);
      primaryTable = *(uint *)(glContext + 0x4680);
      entry = *(int *)(secondaryTable + 0x18);
      bitmapHandler = PTR__glBitmap_Exec_0011207c;
    }
    *(undefined **)((primaryTable & -(uint)(entry == 0) | secondaryTable & ~-(uint)(entry == 0)) + 0x18) = bitmapHandler;
    if ((*(char *)(glContext + 0x759c) == '\0') || (*(char *)(glContext + 0x759d) == '\0')) {
      maskThenTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x10) == 0);
      maskThenTable = *(uint *)(glContext + 0x4680) & maskThenTable | *(uint *)(glContext + 0x4684) & ~maskThenTable;
      beginHandler = PTR__glBegin_NoopExec_00112078;
    }
    else {
      maskThenTable = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x10) == 0);
      maskThenTable = *(uint *)(glContext + 0x4680) & maskThenTable | *(uint *)(glContext + 0x4684) & ~maskThenTable;
      beginHandler = PTR__glBegin_Exec_00112074;
    }
    *(undefined **)(maskThenTable + 0x10) = beginHandler;
  }
  _gleUpdateDrawArraysFuncs(glContext);
  return;
}

/* _gleReclaimDisplayListResources @ 0xc9150 (4 bytes) */
void _gleReclaimDisplayListResources()
{
  return;
}

/* _gleQuickOptimizeDisplayList @ 0xc9154 (1292 bytes) */
void _gleQuickOptimizeDisplayList(glContext, list, recordedList)
  int glContext;
  undefined4 list;
  int recordedList;
{
  undefined *puVar1;
  vm_address_t *varItem;
  int *piVar3;
  undefined *entryFunc;
  int iVar5;
  int iVar6;
  vm_address_t varWriteCursor;
  vm_address_t varNextCursor;
  int *entrySizes;
  int iVar10;
  int iVar11;
  int byteOffset;
  int iVar12;
  uint entryCount;
  uint uVar14;
  uint loopIndex;
  undefined4 *entryCursor;
  undefined4 *scanCursor;
  vm_address_t varBlockBase;
  int varBytesLeft [4];
  
  entryCount = *(uint *)(recordedList + 0x10);
  entryCursor = (undefined4 *)(recordedList + 0x2c);
  entrySizes = *(int **)(recordedList + 0x14);
  loopIndex = 0;
  piVar3 = entrySizes;
  scanCursor = entryCursor;
  if (entryCount == 0) {
    return;
  }
  while( true ) {
    puVar1 = (undefined *)*scanCursor;
    iVar5 = 0;
    iVar11 = *(int *)(((uint)puVar1 & 0x7c) + _gleDisplayListFunctionHash);
    while ((iVar11 != 0 && (iVar5 = iVar11, puVar1 != *(undefined **)(iVar11 + 4)))) {
      iVar5 = *(int *)(iVar11 + 0xc);
      iVar11 = iVar5;
    }
    if ((puVar1 == PTR__glDrawArraysOrElements_ListExec_00112144) && (0x20 < (int)scanCursor[7]))
    break;
    if ((iVar5 == 0) || (*(undefined **)(iVar5 + 4) != PTR__glWeightARB_ListExec_0011214c)) {
      scanCursor = (undefined4 *)((int)scanCursor + *piVar3);
    }
    else {
      scanCursor = scanCursor + scanCursor[1] + 2;
    }
    loopIndex = loopIndex + 1;
    piVar3 = piVar3 + 1;
    if (entryCount <= loopIndex) {
      return;
    }
  }
  varWriteCursor = 0;
  iVar5 = 0;
  _gleNewList(glContext,list,((unsigned char *)0x00001300U));
  puVar1 = PTR__glWeightARB_ListExec_0011214c;
  varBytesLeft[0] = 0;
  varBlockBase = 0;
  loopIndex = 0;
  if (entryCount != 0) {
    byteOffset = 0;
    do {
      entryFunc = (undefined *)*entryCursor;
      iVar12 = 0;
      iVar6 = *(int *)(((uint)entryFunc & 0x7c) + _gleDisplayListFunctionHash);
      while ((iVar6 != 0 && (iVar12 = iVar6, entryFunc != *(undefined **)(iVar6 + 4)))) {
        iVar12 = *(int *)(iVar6 + 0xc);
        iVar6 = iVar12;
      }
      if (entryFunc == PTR__glDrawArraysOrElements_ListExec_00112144) {
        iVar6 = 0x2c;
        iVar10 = entryCursor[7] * entryCursor[8];
        if (varBytesLeft[0] < iVar10 + 0x2c) {
          iVar6 = 0x40;
          if (varBlockBase != 0) {
            _CloseCurrentVAR(glContext,iVar5,varWriteCursor,&varBlockBase,varBytesLeft);
          }
          varItem = (vm_address_t *)
                   _gleAddListItemWithFree
                             (glContext,
                              PTR__gleSetupAndDrawArraysOrElementsOutOfLine_ListExec_00112140,0x10,
                              PTR__gleOptimizedListFreeFunc_00110ccc,4);
          varBytesLeft[0] = iVar10 + 0x40;
          iVar5 = (int)varItem - *(int *)(glContext + 0x53e8);
          if (varBytesLeft[0] < 0x100001) {
            varBytesLeft[0] = 0x100000;
            uVar14 = 0x100000;
          }
          else {
            uVar14 = (uint)(((unsigned char *)0x0000103f) + iVar10) & 0xfffff000;
          }
          _vm_allocate(*(vm_map_t *)PTR_00112034,&varBlockBase,uVar14,1);
          *varItem = varBlockBase;
          *(uint *)(varBlockBase + 0xc) = uVar14;
          *(undefined4 *)*varItem = 4;
          *(uint *)*varItem = *(uint *)*varItem | 2;
          varWriteCursor = *varItem + 0x14;
          varNextCursor = varBlockBase;
        }
        else {
          piVar3 = (int *)_gleAddListItem(glContext,
                                          PTR__gleDrawArraysOrElementsOutOfLine_ListExec_0011213c,8)
          ;
          *piVar3 = (int)piVar3 + (-iVar5 - *(int *)(glContext + 0x53e8));
          piVar3[1] = varWriteCursor - varBlockBase;
          varNextCursor = varWriteCursor;
        }
        varBytesLeft[0] = varBytesLeft[0] - (iVar10 + iVar6);
        varNextCursor = varNextCursor + iVar10 + iVar6;
        _memcpy(varWriteCursor,entryCursor + 6,iVar10 + 0x2c);
        varWriteCursor = varNextCursor;
        if ((iVar12 == 0) || (*(undefined **)(iVar12 + 4) != puVar1)) {
          iVar12 = *(int *)(byteOffset + (int)entrySizes);
          goto LAB_000c9558;
        }
LAB_000c9540:
        entryCursor = entryCursor + entryCursor[1] + 2;
      }
      else {
        if (((entryFunc == PTR__glCallList_ListExec_00112138) ||
            (entryFunc == PTR__glBindVertexArrayEXT_ListExec_00112134)) ||
           (entryFunc == PTR__glVertexArrayParameteriEXT_ListExec_00112130)) {
          if (varBlockBase != 0) {
            _CloseCurrentVAR(glContext,iVar5,varWriteCursor,&varBlockBase,varBytesLeft);
            entryFunc = (undefined *)*entryCursor;
          }
          uVar14 = *(int *)(byteOffset + (int)entrySizes) - 4;
          iVar10 = _gleAddListItem(glContext,entryFunc,uVar14);
          iVar6 = 0;
          for (uVar14 = uVar14 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
            *(undefined4 *)(iVar10 + iVar6 * 4) = entryCursor[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
        }
        else {
          uVar14 = *(int *)(byteOffset + (int)entrySizes) - 4;
          iVar10 = _gleAddListItem(glContext,entryFunc,uVar14);
          iVar6 = 0;
          for (uVar14 = uVar14 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
            *(undefined4 *)(iVar10 + iVar6 * 4) = entryCursor[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
        }
        if ((iVar12 != 0) && (*(undefined **)(iVar12 + 4) == puVar1)) goto LAB_000c9540;
        iVar12 = *(int *)(byteOffset + (int)entrySizes);
LAB_000c9558:
        entryCursor = (undefined4 *)((int)entryCursor + iVar12);
      }
      loopIndex = loopIndex + 1;
      byteOffset = byteOffset + 4;
    } while (loopIndex < entryCount);
  }
  if (varBlockBase != 0) {
    _CloseCurrentVAR(glContext,iVar5,varWriteCursor,&varBlockBase,varBytesLeft);
  }
  iVar5 = *(int *)(glContext + 0x5148);
  *(undefined4 *)(glContext + 0x5408) = 0;
  iVar11 = iVar5 + 0x300c;
  if (*(char *)(iVar5 + 0x8024) != '\0') {
    _pthread_mutex_lock(iVar5 + 0x8028);
  }
  iVar12 = *(int *)(glContext + 0x53e8);
  iVar5 = _gleIsHashName(iVar11,*(undefined4 *)(iVar12 + 4));
  if (iVar5 == 0) {
    _gleAddHashNameAndObject(glContext,iVar11,iVar12);
  }
  else {
    iVar5 = _gleRemoveHashObject(iVar11,*(undefined4 *)(iVar12 + 4));
    if ((iVar5 != 0) && (iVar6 = *(int *)(iVar5 + 8) + -1, *(int *)(iVar5 + 8) = iVar6, iVar6 == 0))
    {
      if (*(int *)(iVar5 + 0x14) != 0) {
        _free(*(int *)(iVar5 + 0x14));
      }
      _free(iVar5);
    }
    _gleAddHashObject(iVar11,iVar12);
  }
  if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
    _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
  }
  return;
}

/* _gleDrawPixelsFastPickTextureType @ 0xc9660 (92 bytes) */
int _gleDrawPixelsFastPickTextureType(param_1)
  uint param_1;
{
  uint uVar1;
  
  if (param_1 != 0x8034) {
    if (param_1 < 0x8035) {
      uVar1 = 0x8032;
    }
    else {
      if (param_1 == 0x8362) {
        return 0x8366;
      }
      uVar1 = 0x8366;
    }
    if (param_1 != uVar1) {
      return 0x8367;
    }
  }
  return 0x8366;
}

/* _gleDrawPixelsFastLoadColorTables @ 0xc96bc (232 bytes) */
void _gleDrawPixelsFastLoadColorTables(glContext, param_2)
  undefined4 glContext;
  int param_2;
{
  int iVar1;
  
  iVar1 = _gleLookUpColorTable(glContext,0x80d0);
  if ((iVar1 != 0) && (iVar1 != -0xac)) {
    *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(iVar1 + 0xc0);
    *(uint *)(param_2 + 0x3c) = (uint)*(ushort *)(iVar1 + 0xbc);
    *(uint *)(param_2 + 0x40) = (uint)*(ushort *)(iVar1 + 0xbe);
    *(uint *)(param_2 + 0x44) = (uint)*(ushort *)(iVar1 + 0xb0);
  }
  iVar1 = _gleLookUpColorTable(glContext,0x80d2);
  if ((iVar1 != 0) && (iVar1 != -0xac)) {
    *(undefined4 *)(param_2 + 0x58) = *(undefined4 *)(iVar1 + 0xc0);
    *(uint *)(param_2 + 0x4c) = (uint)*(ushort *)(iVar1 + 0xbc);
    *(uint *)(param_2 + 0x50) = (uint)*(ushort *)(iVar1 + 0xbe);
    *(uint *)(param_2 + 0x54) = (uint)*(ushort *)(iVar1 + 0xb0);
  }
  iVar1 = _gleLookUpColorTable(glContext,0x80d1);
  if ((iVar1 != 0) && (iVar1 != -0xac)) {
    *(undefined4 *)(param_2 + 0x68) = *(undefined4 *)(iVar1 + 0xc0);
    *(uint *)(param_2 + 0x5c) = (uint)*(ushort *)(iVar1 + 0xbc);
    *(uint *)(param_2 + 0x60) = (uint)*(ushort *)(iVar1 + 0xbe);
    *(uint *)(param_2 + 100) = (uint)*(ushort *)(iVar1 + 0xb0);
  }
  return;
}

/* _CopySourceSubImageToTexture @ 0xc97a4 (568 bytes) */
void _CopySourceSubImageToTexture(int glContext,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,int param_13,int param_14,undefined4 unusedArg15,undefined4 unusedArg16,undefined4 unusedArg17,undefined4 unusedArg18,int param_19,undefined4 param_20,float floatArg1,float floatArg2,double unusedFloatArg3,float fparam_4)
{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  float doubleZero;
  float dVar8;
  int local_e0;
  int local_dc;
  undefined1 auStack_d8 [4];
  undefined1 auStack_d4 [4];
  undefined4 local_d0;
  undefined4 local_cc;
  undefined1 auStack_c8 [4];
  undefined1 auStack_c4 [4];
  undefined4 local_c0;
  uint local_bc;
  uint local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  float local_ac;
  float local_a8;
  undefined1 local_74;
  int local_70;
  undefined1 auStack_6c [4];
  undefined1 auStack_68 [4];
  undefined1 auStack_64 [4];
  int local_60;
  int local_5c [3];
  undefined4 local_50;
  
  piVar5 = local_5c;
  iVar3 = param_19;
  _glePixelPackSettings
            (glContext,param_4,param_5,param_2,param_3,param_19,&local_60,piVar5,&local_70,auStack_6c,
             auStack_68,auStack_64);
  iVar4 = param_14 * local_70;
  local_dc = local_70;
  local_e0 = param_13 * local_60 + iVar4 + param_6 + local_5c[0];
  _glgConvertType(param_4,param_5,auStack_d8,auStack_d4,param_3,iVar3,iVar4,piVar5);
  puVar1 = auStack_c8;
  puVar2 = auStack_c4;
  local_d0 = param_12;
  local_cc = param_9;
  _glgConvertType(param_10,param_11,puVar1,puVar2,param_3,iVar3,iVar4,piVar5);
  dVar8 = (double)*(float *)(glContext + 0x31ac);
  local_c0 = 2;
  local_bc = 0;
  if ((DOUBLE_00108dc8 < (double)dVar8) && ((double)dVar8 < DOUBLE_00108d68)) {
    local_b8 = 0x6ffff;
  }
  else {
    local_b8 = 0x6efff;
  }
  if ((char)param_20 != '\0') {
    local_b8 = local_b8 | 0x10000;
    ((void (*)())_gleDrawPixelsFastLoadColorTables)(glContext,&local_e0);
    dVar8 = (double)*(float *)(glContext + 0x31ac);
  }
  local_ac = (float)floatArg1;
  local_74 = 1;
  local_a8 = (float)floatArg2;
  if (param_19 != 0) {
    if (*(char *)(param_19 + 0x18) != '\0') {
      local_bc = local_bc | 1;
    }
    if (*(char *)(param_19 + 0x19) != '\0') {
      local_bc = local_bc | 4;
    }
  }
  doubleZero = (double)FLOAT_00108e50;
  uVar6 = *(undefined4 *)(glContext + 0x31a8);
  *(undefined4 *)(glContext + 0x31a8) = 0x3f800000;
  if ((double)dVar8 < (double)doubleZero) {
    if ((double)dVar8 < (double)FLOAT_00108e58) goto LAB_000c99b8;
  }
  else {
    local_50 = 0x3f800000;
    if (1.0 < (double)dVar8) goto LAB_000c99b8;
  }
  if ((double)dVar8 < (double)FLOAT_00108e50) {
    fparam_4 = (double)(fparam_4 * -dVar8);
  }
  else {
    fparam_4 = (double)(fparam_4 * dVar8);
  }
LAB_000c99b8:
  *(float *)(glContext + 0x31ac) = (float)fparam_4;
  local_b4 = param_7;
  local_b0 = param_8;
  _glgProcessPixels(glContext + 0x31a8,&local_e0,puVar1,puVar2,param_3,iVar3,iVar4,piVar5);
  *(float *)(glContext + 0x31ac) = (float)(double)dVar8;
  *(undefined4 *)(glContext + 0x31a8) = uVar6;
  return;
}

/* _gleInitDrawPixelsShareObject @ 0xc99dc (1036 bytes) */
void _gleInitDrawPixelsShareObject(glContext, shareObject)
  int glContext;
  undefined4 *shareObject;
{
  bool rendererInfoByte79Clear;
  bool stateClean;
  undefined1 savedByte31e6;
  char rendererInfoByte79;
  int textureAddress;
  int dataStride;
  int dirtyBitArrayWord;
  uint uVar5;
  uint textureCount;
  int *dirtyBitArrayCursor;
  int dataBlock;
  undefined4 *textureTable;
  undefined4 textureStorage;
  undefined4 dataBlockHandle;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  uint textureIndex;
  uint loopIndex2;
  uint dispatchFlags;
  uint dirtyWord3ThenMasked;
  int textureOffset;
  int slotByteOffset;
  int framebufferObject;
  int remaining;
  int loopIndex;
  int textureObject;
  uint nextTextureIndex;
  int *dirtyFlagWords;
  double f1AfterCall;
  double f1AfterCall1;
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  savedByte31e6 = *(undefined1 *)(glContext + 0x31e6);
  *shareObject = 0;
  shareObject[3] = 0x40000;
  shareObject[2] = 2;
  shareObject[1] = 0x100000;
  shareObject[4] = 0x8035;
  textureTable = (undefined4 *)_gleVecAlloc(8);
  shareObject[6] = textureTable;
  textureStorage = _gleVecAlloc(shareObject[2] * 0xa9c);
  *textureTable = textureStorage;
  textureCount = 0;
  if (shareObject[2] != 0) {
    textureOffset = 0;
    textureIndex = 0;
    do {
      nextTextureIndex = textureIndex + 1;
      textureAddress = *(int *)shareObject[6] + textureOffset;
      textureOffset = textureOffset + 0xa9c;
      ((int *)shareObject[6])[textureIndex] = textureAddress;
      textureCount = shareObject[2];
      textureIndex = nextTextureIndex;
    } while (nextTextureIndex < textureCount);
  }
  shareObject[5] = textureCount * shareObject[1];
  dataBlockHandle = _gleVecAlloc(textureCount * shareObject[1]);
  shareObject[7] = dataBlockHandle;
  *(undefined1 *)(glContext + 0x31e6) = 1;
  uVar5 = *(uint *)(glContext + 0x314) | 1;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x200000;
  *(uint *)(glContext + 0x314) = uVar5;
  fparam_1 = f1AfterCall;
  if (*(int *)(glContext + 0x50ac) != 0 ||
      (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = f1AfterCall1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_000c9cc0;
  framebufferObject = *(int *)(glContext + 0x744c);
  dirtyFlagWords = (int *)(glContext + 0x310);
  rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,uVar5,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,
               incomingFpr6,incomingFpr7,incomingFpr8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000c9bb8:
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
      goto LAB_000c9bb8;
    }
  }
  rendererInfoByte79Clear = rendererInfoByte79 == '\0';
  if (rendererInfoByte79Clear) {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
  }
  else {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
  }
  uVar5 = *(uint *)(glContext + 800);
  if (rendererInfoByte79Clear) {
    stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) && uVar5 == 0;
  }
  else {
    stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) && uVar5 == 0;
  }
  if (!stateClean) {
    uVar5 = (uint)*(byte *)(glContext + 0x85a6);
    if (*(byte *)(glContext + 0x85a8) == uVar5) {
      dispatchFlags = (**(code **)(glContext + 0x4788))
                         (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
      uVar5 = dispatchFlags & 4;
      if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
          (uVar5 != *(byte *)(glContext + 0x7581))) ||
         ((dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if (uVar5 == 0) {
          dispatchFlags = dispatchFlags & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        ((double (*)())_gleUpdateDispatchCodeChange)(glContext,dispatchFlags);
      }
    }
    else {
      ((double (*)())_gleSwitchToNonRevertRenderer)(glContext);
    }
  }
  remaining = 0x13;
  do {
    *dirtyFlagWords = 0;
    dirtyFlagWords = dirtyFlagWords + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
LAB_000c9cc0:
  loopIndex2 = 0;
  if (shareObject[2] != 0) {
    do {
      slotByteOffset = loopIndex2 * 4;
      textureObject = *(int *)(slotByteOffset + shareObject[6]);
      _gleInitializeGLTexture(2,1,textureObject,incomingR6,incomingR7,incomingR8,uVar5);
      *(undefined2 *)(textureObject + 0x3e) = 0x85be;
      *(undefined2 *)(textureObject + 0x34) = 0x812f;
      *(undefined2 *)(textureObject + 0x36) = 0x812f;
      *(undefined2 *)(textureObject + 0x38) = 0x812f;
      *(undefined2 *)(textureObject + 0x3a) = 0x2600;
      *(undefined2 *)(textureObject + 0x3c) = 0x2600;
      *(undefined4 *)(textureObject + 0x70) = shareObject[5];
      *(undefined4 *)(textureObject + 0x74) = shareObject[7];
      _gleCreatePluginTexture(glContext,*(undefined4 *)(slotByteOffset + shareObject[6]));
      *(undefined1 *)(textureObject + 0xcf) = 0x11;
      *(undefined2 *)(textureObject + 0xd0) = 0x40;
      *(undefined2 *)(textureObject + 0xd2) = 0x40;
      *(undefined2 *)(textureObject + 0xd4) = 0x80e1;
      incomingR8 = 0x8058;
      *(undefined2 *)(textureObject + 0xd6) = 0x8035;
      dataStride = shareObject[1];
      incomingR6 = 0;
      dataBlock = shareObject[7];
      incomingR7 = 0;
      *(undefined2 *)(textureObject + 200) = 0x40;
      *(undefined2 *)(textureObject + 0xca) = 0x40;
      *(undefined2 *)(textureObject + 0xcc) = 1;
      *(undefined1 *)(textureObject + 0xce) = 0;
      *(uint *)(textureObject + 0xd8) = dataBlock + loopIndex2 * dataStride;
      _gleCreatePluginTextureLevel
                (glContext,*(undefined4 *)(slotByteOffset + shareObject[6]),textureObject + 0xc4,0,0,0x8058);
      loopIndex2 = loopIndex2 + 1;
    } while (loopIndex2 < (uint)shareObject[2]);
  }
  *(undefined1 *)(glContext + 0x31e6) = savedByte31e6;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x200000;
  *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 1;
  return;
}

/* _gleDrawPixelsSaveState @ 0xc9de8 (756 bytes) */
int _gleDrawPixelsSaveState(glContext, param_2)
  int glContext;
  uint *param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  double f1AfterCall;
  double f1AfterCall1;
  double f1AfterCall2;
  double f1AfterCall3;
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  double incomingStack_ffffff98;
  double incomingStack_ffffffa0;
  double incomingStack_ffffffa8;
  
  bVar4 = *(ushort *)(glContext + 0x3538) != 0x1e01;
  if ((bool)bVar4) {
    *param_2 = (uint)*(ushort *)(glContext + 0x3538);
    *(undefined2 *)(glContext + 0x3538) = 0x1e01;
    *(uint *)(glContext + 800) = *(uint *)(glContext + 800) | 1;
  }
  *(undefined4 *)(glContext + 0x3534) = 4;
  _gleUpdateTextureParams(glContext,0);
  fparam_1 = f1AfterCall;
  if (*(byte *)(glContext + 0x34da) != 0) {
    param_2[1] = (uint)*(byte *)(glContext + 0x34da);
    *(undefined1 *)(glContext + 0x34da) = 0;
    _gleUpdatePolyMode(glContext);
    bVar4 = bVar4 | 2;
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800000;
    fparam_1 = f1AfterCall1;
  }
  if (*(byte *)(glContext + 0x34d8) != 0) {
    param_2[2] = (uint)*(byte *)(glContext + 0x34d8);
    bVar4 = bVar4 | 4;
    *(undefined1 *)(glContext + 0x34d8) = 0;
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x2000000;
  }
  if (*(byte *)(glContext + 0x34dd) != 0) {
    param_2[3] = (uint)*(byte *)(glContext + 0x34dd);
    bVar4 = bVar4 | 8;
    *(undefined1 *)(glContext + 0x34dd) = 0;
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800000;
  }
  if (*(byte *)(glContext + 0x34d9) != 0) {
    param_2[4] = (uint)*(byte *)(glContext + 0x34d9);
    bVar4 = bVar4 | 0x10;
    *(undefined1 *)(glContext + 0x34d9) = 0;
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800000;
  }
  if (*(byte *)(glContext + 0x4664) != 0) {
    param_2[6] = (uint)*(byte *)(glContext + 0x4664);
    *(undefined1 *)(glContext + 0x4664) = 0;
    bVar4 = bVar4 | 0x40;
    _gleVPDisable(glContext);
    fparam_1 = f1AfterCall2;
  }
  if (*(uint *)(glContext + 0x5430) != 0) {
    param_2[7] = *(uint *)(glContext + 0x5430);
    *(undefined4 *)(glContext + 0x5430) = 0;
    bVar4 = bVar4 | 0x80;
    _gleVPDisable(glContext);
    fparam_1 = f1AfterCall3;
  }
  param_2[5] = *(uint *)(glContext + 0x4ff4);
  param_2[8] = *(uint *)(glContext + 0x1ba0);
  param_2[9] = *(uint *)(glContext + 0x1ba4);
  param_2[10] = *(uint *)(glContext + 0x1ba8);
  param_2[0xb] = *(uint *)(glContext + 0x1bac);
  iVar3 = *(int *)(glContext + 0x744c);
  *(undefined4 *)(glContext + 0x1ba4) = 0;
  *(undefined4 *)(glContext + 0x1ba0) = 0;
  if (iVar3 == 0) {
    uVar1 = *(uint *)(glContext + 0x471c);
  }
  else {
    uVar1 = (uint)*(ushort *)(iVar3 + 0xca);
  }
  *(uint *)(glContext + 0x1ba8) = uVar1;
  if (iVar3 == 0) {
    uVar1 = *(uint *)(glContext + 0x4720);
  }
  else {
    uVar1 = (uint)*(ushort *)(iVar3 + 0xcc);
  }
  *(uint *)(glContext + 0x1bac) = uVar1;
  ((void (*)())_gleUpdateViewScissorData)(glContext,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  _gleCopyMatrix(glContext + 0x1c80,param_2 + 0xc);
  _gleCopyMatrix(glContext + 0x1cc0,param_2 + 0x1c);
  _gleCopyMatrix(glContext + *(int *)(glContext + 0x53d4) * 0x40 + 0x1fc0,param_2 + 0x2c);
  _glMatrixMode_Exec(glContext,0x1701);
  _glLoadIdentity_Exec(glContext);
  iVar3 = *(int *)(glContext + 0x744c);
  if (iVar3 == 0) {
    uVar1 = *(uint *)(glContext + 0x471c);
  }
  else {
    uVar1 = (uint)*(ushort *)(iVar3 + 0xca);
  }
  if (iVar3 == 0) {
    uVar2 = *(uint *)(glContext + 0x4720);
  }
  else {
    uVar2 = (uint)*(ushort *)(iVar3 + 0xcc);
  }
  ((void (*)())_glOrtho_Exec)(glContext,DOUBLE_00108d60,
                (double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - DOUBLE_00108d58,DOUBLE_00108d60,
                (double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - DOUBLE_00108d58,DOUBLE_00108d60,
                DOUBLE_00108dc8,incomingFpr7,incomingFpr8,incomingStack_ffffff88,incomingStack_ffffff90,incomingStack_ffffff98,
                incomingStack_ffffffa0,incomingStack_ffffffa8);
  _glMatrixMode_Exec(glContext,0x1700);
  _glLoadIdentity_Exec(glContext);
  _glMatrixMode_Exec(glContext,0x1702);
  _glLoadIdentity_Exec(glContext);
  return bVar4;
}

/* _gleDrawPixelsRestoreState @ 0xca0dc (408 bytes) */
void _gleDrawPixelsRestoreState(glContext, savedDrawState, savedStateMask)
  int glContext;
  int savedDrawState;
  uint savedStateMask;
{
  double f1AfterCall;
  double f1AfterCall1;
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  if ((savedStateMask & 1) != 0) {
    *(undefined2 *)(glContext + 0x3538) = *(undefined2 *)(savedDrawState + 2);
    *(uint *)(glContext + 800) = *(uint *)(glContext + 800) | 1;
  }
  *(undefined4 *)(glContext + 0x3534) = 0;
  _gleUpdateTextureParams(glContext,0);
  forwardedFloatArg1 = f1AfterCall;
  if ((savedStateMask & 2) != 0) {
    *(undefined1 *)(glContext + 0x34da) = *(undefined1 *)(savedDrawState + 7);
    _gleUpdatePolyMode(glContext);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800000;
    forwardedFloatArg1 = f1AfterCall1;
  }
  if ((savedStateMask & 4) != 0) {
    *(undefined1 *)(glContext + 0x34d8) = *(undefined1 *)(savedDrawState + 0xb);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x2000000;
  }
  if ((savedStateMask & 8) != 0) {
    *(undefined1 *)(glContext + 0x34dd) = *(undefined1 *)(savedDrawState + 0xf);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800000;
  }
  if ((savedStateMask & 0x10) != 0) {
    *(undefined1 *)(glContext + 0x34d9) = *(undefined1 *)(savedDrawState + 0x13);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800000;
  }
  if (((savedStateMask & 0x40) != 0) &&
     (*(undefined1 *)(glContext + 0x4664) = *(undefined1 *)(savedDrawState + 0x1b),
     *(int *)(savedDrawState + 0x18) != 0)) {
    forwardedFloatArg1 = (double)((double (*)())_gleVPEnable)(glContext,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  }
  if (((savedStateMask & 0x80) != 0) &&
     (*(undefined4 *)(glContext + 0x5430) = *(undefined4 *)(savedDrawState + 0x1c),
     *(int *)(savedDrawState + 0x1c) != 0)) {
    forwardedFloatArg1 = (double)((double (*)())_gleVPEnable)(glContext,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  }
  *(undefined4 *)(glContext + 0x1ba0) = *(undefined4 *)(savedDrawState + 0x20);
  *(undefined4 *)(glContext + 0x1ba4) = *(undefined4 *)(savedDrawState + 0x24);
  *(undefined4 *)(glContext + 0x1ba8) = *(undefined4 *)(savedDrawState + 0x28);
  *(undefined4 *)(glContext + 0x1bac) = *(undefined4 *)(savedDrawState + 0x2c);
  ((void (*)())_gleUpdateViewScissorData)(glContext,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  _glMatrixMode_Exec(glContext,0x1701);
  _glLoadMatrixf_Exec(glContext,savedDrawState + 0x30);
  _glMatrixMode_Exec(glContext,0x1700);
  _glLoadMatrixf_Exec(glContext,savedDrawState + 0x70);
  _glMatrixMode_Exec(glContext,0x1702);
  _glLoadMatrixf_Exec(glContext,savedDrawState + 0xb0);
  *(undefined4 *)(glContext + 0x4ff4) = *(undefined4 *)(savedDrawState + 0x14);
  _gleUpdateMatrixMode(glContext);
  return;
}

/* _pixelBoundaryBottomLeft @ 0xca274 (100 bytes) */
uint _pixelBoundaryBottomLeft(float floatArg1)
{
  uint uVar1;
  
  uVar1 = (uint)(int)floatArg1;
  if ((floatArg1 - (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - DOUBLE_00108d58)) <=
      FLOAT_00108e90) {
    return uVar1;
  }
  return uVar1 + 1;
}

/* _pixelBoundaryTopRight @ 0xca2d8 (92 bytes) */
uint _pixelBoundaryTopRight(float floatArg1)
{
  uint uVar1;
  
  uVar1 = (uint)(int)floatArg1;
  if (!(FLOAT_00108e90 <
       (floatArg1 - (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - DOUBLE_00108d58))))
  {
    return uVar1;
  }
  return uVar1 + 1;
}

/* _pixelCenters @ 0xca334 (160 bytes) */
int _pixelCenters(float floatArg1,float floatArg2,double floatArg3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((double)FLOAT_00108e50 <= floatArg3) {
    iVar2 = ((uint (*)())_pixelBoundaryBottomLeft)(floatArg1);
    iVar3 = ((uint (*)())_pixelBoundaryTopRight)(floatArg2);
  }
  else {
    iVar2 = ((uint (*)())_pixelBoundaryTopRight)(floatArg1);
    iVar3 = ((uint (*)())_pixelBoundaryBottomLeft)(floatArg2);
  }
  iVar1 = iVar2 - iVar3;
  if (iVar2 <= iVar3) {
    iVar1 = iVar3 - iVar2;
  }
  return iVar1;
}

/* _gleDrawPixelsFast @ 0xca3d4 (3376 bytes) */
int _gleDrawPixelsFast(glContext, width, height, format, typeThenTextureType, pixels)
  int glContext;
  uint width;
  uint height;
  int format;
  int typeThenTextureType;
  int pixels;
{
  bool bVar1;
  float zoomXSignF;
  float nextTileXOffsetF;
  float zoomYSignF;
  float nextTileYOffsetF;
  float nextTileDestX;
  float quadX1;
  float nextTileDestY;
  float quadY1;
  char cVar8;
  float rasterPosY;
  int slotOffset;
  int glContextPlus10000Copy2;
  int slotOffset2;
  double intToDoubleBias2;
  int *dirtyFlagWords3;
  uint texUnitCount;
  uint imageHeight;
  int iVar15;
  int tileQuadHeightInt;
  int tileHeightInt;
  int *piVar16;
  int *textureLevel;
  int *texUnitStateCursor;
  int *dirtyFlagWordsCursor;
  int textureType;
  undefined4 a1;
  undefined4 a1_00;
  undefined4 a1_01;
  undefined4 a1_02;
  undefined4 textureInternalFormat;
  int iVar20;
  int drawTexture;
  int iVar21;
  int slotOffset3;
  int remaining;
  int loopIndex;
  int matrixFuncDirty;
  undefined2 levelHeight;
  undefined4 *puVar22;
  int transferState;
  uint tileXCounter;
  int sourceFormat;
  uint tileYCounter;
  uint *drawPixelsShare;
  int iVar29;
  int glContextPlus10000Copy3;
  int dirtyWordValue;
  uint imageWidth;
  uint loopIndex2;
  uint boundaryX;
  uint slotIndex;
  uint dirtyWord3ThenMasked;
  uint tileRowBytes;
  uint boundaryY;
  uint loopIndex3;
  uint dispatchFlags;
  float zoomXSign;
  float doubleZero;
  double dVar33;
  double tileRowBytesD;
  double forwardedFpr1;
  double f1AfterCall;
  double extraout_f1_00;
  double f1AfterCall2;
  double dVar34;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  float tileXOffsetF;
  float tileHeight;
  float dVar36;
  float tileYOffsetF;
  double absZoomX;
  double rasterPosYDouble;
  double absZoomY;
  double zoomX;
  double f2;
  double zoomYSign;
  double zoomY;
  float tileWidth;
  double destYFraction;
  double rasterPosXDouble;
  double intToDoubleBias;
  undefined4 incomingStack_fffffd90;
  undefined4 incomingStack_fffffd94;
  undefined4 incomingStack_fffffd98;
  undefined4 incomingStack_fffffd9c;
  float quadY0;
  float quadX0;
  float tileDestY;
  float tileDestX;
  uint tileYOffset;
  uint tileXOffset;
  undefined1 savedDrawState [240];
  undefined4 intToDoubleHigh1;
  uint intToDoubleLow1;
  undefined4 intToDoubleHigh2;
  uint intToDoubleLow2;
  undefined4 intToDoubleHigh3;
  uint intToDoubleLow3;
  longlong doubleToIntScratch1;
  undefined8 doubleToIntScratch2;
  longlong doubleToIntScratch3;
  undefined4 savedDrawStateToken;
  int convertedPixels;
  int sourcePixels;
  int glContextPlus10000Copy;
  int *dirtyFlagWords2;
  int glContextPlus10000;
  int *dirtyFlagWords;
  
  zoomY = (double)*(float *)(glContext + 0x31ac);
  convertedPixels = 0;
  doubleZero = (double)FLOAT_00108e50;
  zoomX = (double)*(float *)(glContext + 0x31a8);
  tileDestX = *(float *)(glContext + 0x2e0);
  rasterPosXDouble = (double)tileDestX;
  rasterPosY = *(float *)(glContext + 0x2e4);
  rasterPosYDouble = (double)rasterPosY;
  f2 = (double)*(float *)(glContext + 0x2e8);
  absZoomY = zoomY;
  if (!((double)doubleZero <= zoomY)) {
    absZoomY = -zoomY;
  }
  absZoomX = zoomX;
  if (!((double)doubleZero <= zoomX)) {
    absZoomX = -zoomX;
  }
  zoomXSignF = FLOAT_00108e54;
  if (zoomX < (double)doubleZero) {
    zoomXSignF = FLOAT_00108e58;
  }
  zoomXSign = (double)zoomXSignF;
  zoomYSignF = FLOAT_00108e54;
  if (zoomY < (double)FLOAT_00108e50) {
    zoomYSignF = FLOAT_00108e58;
  }
  zoomYSign = (double)zoomYSignF;
  if ((((((zoomX == (double)FLOAT_00108e54) && (zoomY == (double)FLOAT_00108e54)) &&
        ((int)width < 0x201)) &&
       ((((int)height < 0x201 && (*(char *)(glContext + 0x30c6) == '\0')) &&
        ((*(char *)(glContext + 0x30e4) == '\0' &&
         ((*(char *)(glContext + 0x3128) == '\0' && ((*(uint *)(glContext + 0x3520) & 3) == 0)))))))) &&
      ((*(char *)(glContext + 0x3ce4) == '\0' &&
       (((*(char *)(glContext + 0x41f8) == '\0' && (*(char *)(glContext + 0x316a) == '\0')) &&
        (*(char *)(glContext + 0x3193) == '\0')))))) &&
     (((*(char *)(glContext + 0x313c) == '\0' && (*(char *)(glContext + 0x31a0) != '\0')) &&
      (((*(char *)(glContext + 0x31a1) != '\0' &&
        ((*(char *)(glContext + 0x31a2) != '\0' && (*(char *)(glContext + 0x31a3) != '\0')))) &&
       (*(char *)(glContext + 0x466c) == '\0')))))) {
    return 0;
  }
  loopIndex2 = 0;
  texUnitCount = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xb4);
  if (texUnitCount != 0) {
    texUnitStateCursor = (int *)(glContext + 0x3534);
    do {
      iVar15 = *texUnitStateCursor;
      texUnitStateCursor = texUnitStateCursor + 0x1f;
      if (iVar15 != 0) {
        return 0;
      }
      loopIndex2 = loopIndex2 + 1;
    } while (loopIndex2 < texUnitCount);
  }
  if (format - 0x1901U < 2) {
    return 0;
  }
  iVar15 = format;
  iVar20 = typeThenTextureType;
  iVar21 = pixels;
  sourcePixels = pixels;
  textureType = ((int (*)())_gleDrawPixelsFastPickTextureType)(typeThenTextureType);
  imageWidth = width;
  imageHeight = height;
  if (((*(uint *)(glContext + 0x3410) & 0x1ff) == 0) &&
     (transferState = glContext + 0x31cc, sourceFormat = format, (*(uint *)(glContext + 0x3414) & 0xff0000) == 0))
  goto LAB_000ca704;
  if (((*(uint *)(glContext + 0x3410) & 2) == 0) || (*(short *)(glContext + 0x3308) != -0x7fea)) {
    if (((*(uint *)(glContext + 0x3410) & 4) != 0) && (*(short *)(glContext + 0x3348) == -0x7fea)) {
      iVar20 = *(int *)(glContext + 0x3354);
      iVar15 = *(int *)(glContext + 0x3350);
      goto LAB_000ca634;
    }
  }
  else {
    iVar20 = *(int *)(glContext + 0x3314);
    iVar15 = *(int *)(glContext + 0x3310);
LAB_000ca634:
    imageHeight = (height - iVar20) + 1;
    imageWidth = (width - iVar15) + 1;
  }
  iVar15 = _glePixelBytes(0x80e1,textureType);
  convertedPixels = _gleVecAlloc(iVar15 * imageWidth * imageHeight);
  iVar15 = _glePixelBytes(0x80e1,textureType);
  sourceFormat = 0x80e1;
  transferState = 0;
  ((void (*)())_CopySourceSubImageToTexture)(glContext,width,height,format,typeThenTextureType,pixels,width,height,imageWidth * iVar15,0x80e1,
             textureType,convertedPixels,0,0,incomingStack_fffffd90,incomingStack_fffffd94,incomingStack_fffffd98,
             incomingStack_fffffd9c,glContext + 0x31cc,1,(double)FLOAT_00108e50,(double)FLOAT_00108e50,
             (double)zoomXSign,zoomYSign);
  sourcePixels = convertedPixels;
  iVar15 = format;
  iVar20 = typeThenTextureType;
  iVar21 = pixels;
  typeThenTextureType = textureType;
LAB_000ca704:
  drawPixelsShare = (uint *)(glContext + 0x7488);
  if (*(int *)(glContext + 0x74a0) == 0) {
    ((void (*)())_gleInitDrawPixelsShareObject)(glContext,drawPixelsShare);
  }
  loopIndex3 = 0;
  *(int *)(glContext + 0x7498) = textureType;
  if (*(int *)(glContext + 0x7490) != 0) {
    do {
      slotOffset = loopIndex3 * 4;
      loopIndex3 = loopIndex3 + 1;
      *(short *)(*(int *)(slotOffset + *(int *)(glContext + 0x74a0)) + 0xd6) = (short)textureType;
    } while (loopIndex3 < *(uint *)(glContext + 0x7490));
  }
  savedDrawStateToken = ((int (*)())_gleDrawPixelsSaveState)(glContext,savedDrawState);
  tileXOffset = 0;
  tileWidth = (double)FLOAT_00108f18;
  if ((double)zoomXSign == (double)FLOAT_00108e54) {
    intToDoubleLow1 = ((uint (*)())_pixelBoundaryTopRight)(rasterPosXDouble);
    intToDoubleLow1 = intToDoubleLow1 ^ 0x80000000;
    intToDoubleHigh1 = 0x43300000;
    boundaryX = intToDoubleLow1;
  }
  else {
    intToDoubleLow2 = ((uint (*)())_pixelBoundaryBottomLeft)(rasterPosXDouble);
    intToDoubleLow2 = intToDoubleLow2 ^ 0x80000000;
    intToDoubleHigh2 = 0x43300000;
    boundaryX = intToDoubleLow2;
  }
  intToDoubleBias = DOUBLE_00108d58;
  tileXCounter = 0;
  if (0 < (int)imageWidth) {
    glContextPlus10000 = glContext + 0x10000;
    dirtyFlagWords = (int *)(glContext + 0x310);
    quadX0 = (float)((double)CONCAT44(0x43300000,boundaryX) - DOUBLE_00108d58);
    do {
      intToDoubleLow1 = imageWidth ^ 0x80000000;
      intToDoubleHigh2 = 0x43300000;
      intToDoubleLow2 = tileXOffset ^ 0x80000000;
      intToDoubleHigh1 = 0x43300000;
      tileXOffsetF = (double)(float)((double)CONCAT44(0x43300000,intToDoubleLow2) - intToDoubleBias);
      nextTileXOffsetF = (tileXOffsetF + tileWidth);
      if ((float)((double)CONCAT44(0x43300000,intToDoubleLow1) - intToDoubleBias) < nextTileXOffsetF) {
        intToDoubleHigh3 = 0x43300000;
        intToDoubleLow3 = imageWidth - tileXOffset ^ 0x80000000;
        tileWidth = (double)(float)((double)CONCAT44(0x43300000,intToDoubleLow3) - intToDoubleBias);
        nextTileXOffsetF = (tileXOffsetF + tileWidth);
      }
      tileHeight = (double)FLOAT_00108f18;
      nextTileDestX = ((float)((double)tileWidth * absZoomX) * zoomXSign + tileDestX);
      intToDoubleLow3 = ((int (*)())_pixelCenters)((double)tileDestX,(double)nextTileDestX,zoomX);
      intToDoubleHigh3 = 0x43300000;
      intToDoubleLow3 = intToDoubleLow3 ^ 0x80000000;
      doubleToIntScratch1 = (longlong)(int)nextTileXOffsetF;
      tileYOffset = 0;
      quadX1 = ((float)((double)CONCAT44(0x43300000,intToDoubleLow3) - intToDoubleBias) * zoomXSign + quadX0);
      if (zoomYSign == (double)FLOAT_00108e54) {
        boundaryY = ((uint (*)())_pixelBoundaryTopRight)(rasterPosYDouble);
        boundaryY = boundaryY ^ 0x80000000;
      }
      else {
        intToDoubleLow2 = ((uint (*)())_pixelBoundaryBottomLeft)(rasterPosYDouble);
        intToDoubleHigh2 = 0x43300000;
        intToDoubleLow2 = intToDoubleLow2 ^ 0x80000000;
        boundaryY = intToDoubleLow2;
      }
      intToDoubleBias2 = DOUBLE_00108d58;
      tileYCounter = 0;
      if (0 < (int)imageHeight) {
        glContextPlus10000Copy = glContextPlus10000;
        dirtyFlagWords2 = dirtyFlagWords;
        quadY0 = (float)((double)CONCAT44(0x43300000,boundaryY) - intToDoubleBias);
        tileDestY = rasterPosY;
        do {
          intToDoubleLow2 = imageHeight ^ 0x80000000;
          intToDoubleHigh3 = 0x43300000;
          intToDoubleLow3 = tileYOffset ^ 0x80000000;
          intToDoubleHigh2 = 0x43300000;
          tileYOffsetF = (double)(float)((double)CONCAT44(0x43300000,intToDoubleLow3) - intToDoubleBias2);
          nextTileYOffsetF = (tileYOffsetF + tileHeight);
          if ((float)((double)CONCAT44(0x43300000,intToDoubleLow2) - intToDoubleBias2) < nextTileYOffsetF) {
            intToDoubleHigh1 = 0x43300000;
            intToDoubleLow1 = imageHeight - tileYOffset ^ 0x80000000;
            tileHeight = (double)(float)((double)CONCAT44(0x43300000,intToDoubleLow1) - intToDoubleBias2);
            nextTileYOffsetF = (tileYOffsetF + tileHeight);
          }
          dVar36 = (double)(float)((double)tileHeight * absZoomY);
          nextTileDestY = (float)((double)dVar36 * zoomYSign + (double)tileDestY);
          intToDoubleLow3 = ((int (*)())_pixelCenters)((double)tileDestY,(double)nextTileDestY,zoomY);
          glContextPlus10000Copy2 = glContextPlus10000Copy;
          intToDoubleHigh3 = 0x43300000;
          intToDoubleLow3 = intToDoubleLow3 ^ 0x80000000;
          doubleToIntScratch1 = (longlong)(int)nextTileYOffsetF;
          quadY1 = (float)((double)(float)((double)CONCAT44(0x43300000,intToDoubleLow3) - intToDoubleBias2) *
                          zoomYSign + (double)quadY0);
          if (!((double)tileWidth < (double)FLOAT_00108e54)) {
            dVar34 = (double)dVar36;
            if ((double)tileHeight < (double)dVar36) {
              dVar34 = (double)tileHeight;
            }
            if (!(dVar34 < (double)FLOAT_00108e54)) {
              loopIndex3 = 0;
              if (*(char *)(glContextPlus10000Copy + -0x7a5c) != '\0') {
                glContextPlus10000Copy3 = glContext + 0x10000;
                do {
                  slotOffset2 = loopIndex3 * 4;
                  piVar16 = (int *)(glContextPlus10000Copy3 + -0x777c);
                  loopIndex3 = loopIndex3 + 1;
                  puVar22 = (undefined4 *)(glContextPlus10000Copy3 + -0x7a54);
                  glContextPlus10000Copy3 = glContextPlus10000Copy3 + 0x2e0;
                  (**(code **)(*piVar16 + 0x1c4))
                            (*puVar22,1,
                             *(undefined4 *)
                              (*(int *)(*drawPixelsShare * 4 + *(int *)(glContext + 0x74a0)) + slotOffset2),iVar15,
                             iVar20,iVar21,*(int *)(glContext + 0x74a0));
                } while (loopIndex3 < *(byte *)(glContextPlus10000Copy2 + -0x7a5c));
              }
              intToDoubleHigh3 = 0x43300000;
              doubleToIntScratch1 = (longlong)(int)tileDestY;
              intToDoubleLow3 = (int)tileDestY ^ 0x80000000;
              destYFraction = (double)(tileDestY -
                                 (float)((double)CONCAT44(0x43300000,intToDoubleLow3) - intToDoubleBias2));
              intToDoubleLow3 = _glePixelBytes(0x80e1,textureType);
              intToDoubleLow3 = intToDoubleLow3 ^ 0x80000000;
              intToDoubleHigh3 = 0x43300000;
              dVar34 = (double)tileWidth * (double)(float)((double)CONCAT44(0x43300000,intToDoubleLow3) - intToDoubleBias2);
              tileRowBytesD = (double)(float)dVar34;
              if (DOUBLE_00108d80 <= tileRowBytesD) {
                tileRowBytes = (uint)(int)(tileRowBytesD - DOUBLE_00108d80);
                doubleToIntScratch2 = (longlong)(int)tileRowBytes;
                tileRowBytes = tileRowBytes ^ 0x80000000;
              }
              else {
                tileRowBytes = (uint)(int)dVar34;
                doubleToIntScratch1 = (longlong)(int)tileRowBytes;
              }
              tileHeightInt = (int)(double)tileHeight;
              doubleToIntScratch3 = (longlong)tileHeightInt;
              dVar34 = (double)zoomXSign;
              dVar33 = zoomYSign;
              ((void (*)())_CopySourceSubImageToTexture)(glContext,imageWidth,imageHeight,sourceFormat,typeThenTextureType,sourcePixels,(int)(double)tileWidth,tileHeightInt,tileRowBytes,
                         0x80e1,textureType,
                         *(int *)(0x74a4 + glContext) +
                         *drawPixelsShare * *(int *)(glContext + 0x748c),tileXOffset,tileYOffset,incomingStack_fffffd90
                         ,incomingStack_fffffd94,incomingStack_fffffd98,incomingStack_fffffd9c,transferState,0,
                         (double)(tileDestX -
                                 (float)((double)CONCAT44(0x43300000,(int)tileDestX ^ 0x80000000) -
                                        intToDoubleBias2)),destYFraction,(double)zoomXSign,zoomYSign);
              drawTexture = *(int *)(*drawPixelsShare * 4 + *(int *)(glContext + 0x74a0));
              textureLevel = (int *)(drawTexture + 0xc4);
              _gleDeletePluginTextureLevel(glContext,drawTexture,textureLevel,0,0);
              *(short *)(drawTexture + 0xd0) = (short)(int)(double)tileWidth;
              if ((double)tileHeight < (double)dVar36) {
                levelHeight = (short)tileHeightInt;
              }
              else {
                tileQuadHeightInt = (int)((double)tileHeight * absZoomY);
                (*(unsigned short *)((unsigned char *)&(doubleToIntScratch2) + 6)) = (undefined2)tileQuadHeightInt;
                levelHeight = (*(unsigned short *)((unsigned char *)&(doubleToIntScratch2) + 6));
                doubleToIntScratch2 = (longlong)tileQuadHeightInt;
              }
              *(undefined2 *)(drawTexture + 0xd2) = levelHeight;
              *(undefined2 *)(drawTexture + 200) = *(undefined2 *)(drawTexture + 0xd0);
              *(undefined2 *)(drawTexture + 0xca) = *(undefined2 *)(drawTexture + 0xd2);
              textureInternalFormat = 0x8058;
              if (textureType != 0x8367) {
                textureInternalFormat = 0x8057;
              }
              iVar15 = 0;
              iVar20 = 0;
              forwardedFpr1 = (double)_gleCreatePluginTextureLevel
                                           (glContext,*(undefined4 *)
                                                     (*drawPixelsShare * 4 + *(int *)(glContext + 0x74a0)),
                                            textureLevel,0,0,textureInternalFormat);
              loopIndex3 = 0;
              if (*(char *)(glContextPlus10000Copy2 + -0x7a5c) != '\0') {
                puVar22 = (undefined4 *)(glContext + 0x86e8);
                do {
                  slotOffset3 = loopIndex3 * 4;
                  loopIndex3 = loopIndex3 + 1;
                  *puVar22 = *(undefined4 *)
                              (*(int *)(*drawPixelsShare * 4 + *(int *)(glContext + 0x74a0)) + slotOffset3);
                  puVar22 = puVar22 + 0xb8;
                } while (loopIndex3 < *(byte *)(glContextPlus10000Copy2 + -0x7a5c));
              }
              matrixFuncDirty = *(int *)(glContext + 0x50ac);
              *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 1;
              if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
                _gleUpdateMatrixFunc(glContext);
                forwardedFpr1 = f1AfterCall;
              }
              dirtyFlagWords3 = dirtyFlagWords2;
              if (*(char *)(glContext + 0x4691) != '\0') {
                iVar29 = *(int *)(glContext + 0x744c);
                cVar8 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
                if ((iVar29 != 0) && (*(int *)(iVar29 + 0xec) != 0)) {
                  ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,iVar29 + 0x10,textureLevel,iVar15,iVar20,textureInternalFormat,matrixFuncDirty,forwardedFpr1,
                             destYFraction,dVar34,dVar33,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
                  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
                  forwardedFpr1 = forwardedFpr1;
                }
                if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000cae0c:
                  dirtyWord3ThenMasked = dirtyFlagWords3[3];
                }
                else {
                  loopIndex = 0;
                  dirtyFlagWordsCursor = dirtyFlagWords3 + 5;
                  do {
                    dirtyWordValue = *dirtyFlagWordsCursor;
                    dirtyFlagWordsCursor = dirtyFlagWordsCursor + 1;
                    if (dirtyWordValue != 0) {
                      dirtyFlagWords3[3] = dirtyFlagWords3[3] | 0x800000;
                      break;
                    }
                    loopIndex = loopIndex + 1;
                  } while (loopIndex < 9);
                  dirtyWord3ThenMasked = dirtyFlagWords3[3];
                  if ((dirtyWord3ThenMasked & 0x15555) != 0) {
                    if (*(char *)(glContext + 0x2e54) != '\0') {
                      textureLevel = (int *)0x0;
                      forwardedFpr1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
                    }
                    if (*(char *)(glContext + 0x3094) != '\0') {
                      textureLevel = (int *)((int)((unsigned char *)0x0) + 1);
                      forwardedFpr1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
                    }
                    goto LAB_000cae0c;
                  }
                }
                bVar1 = cVar8 == '\0';
                if (bVar1) {
                  dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
                }
                else {
                  dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
                }
                if (bVar1) {
                  bVar1 = ((*dirtyFlagWords3 == 0 && dirtyFlagWords3[1] == 0) && dirtyWord3ThenMasked == 0) && dirtyFlagWords3[4] == 0;
                }
                else {
                  bVar1 = (((*dirtyFlagWords3 == 0 && dirtyFlagWords3[1] == 0) && (dirtyFlagWords3[2] & 0xfffffffdU) == 0)
                          && dirtyWord3ThenMasked == 0) && dirtyFlagWords3[4] == 0;
                }
                if (!bVar1) {
                  if (*(char *)(glContextPlus10000Copy2 + -0x7a58) == *(char *)(glContextPlus10000Copy2 + -0x7a5a)) {
                    dispatchFlags = (**(code **)(glContext + 0x4788))
                                       (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords3);
                    if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
                        ((dispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
                       (forwardedFpr1 = f1AfterCall2,
                       (dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
                      if ((dispatchFlags & 4) == 0) {
                        dispatchFlags = dispatchFlags & 0xfffffffe;
                        dirtyFlagWords3[3] = dirtyFlagWords3[3] | 0x10000000;
                      }
                      forwardedFpr1 = (double)((double (*)())_gleUpdateDispatchCodeChange)(glContext,dispatchFlags);
                      if (*(char *)(glContext + 0x759d) == '\0') {
                        if (*(int *)(glContext + 0x7574) != 0) {
                          return 1;
                        }
                        *(undefined4 *)(glContext + 0x7574) = 0x506;
                        return 1;
                      }
                    }
                  }
                  else {
                    forwardedFpr1 = (double)((double (*)())_gleSwitchToNonRevertRenderer)(glContext);
                  }
                  remaining = 0x13;
                  textureLevel = dirtyFlagWords3;
                  do {
                    *textureLevel = 0;
                    textureLevel = textureLevel + 1;
                    remaining = remaining + -1;
                  } while (remaining != 0);
                }
              }
              ((void (*)())_glBegin_Exec)(glContext,7,forwardedFpr1,destYFraction,dVar34,dVar33,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
              *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
              *(float *)(glContext + 300) = *(float *)(glContext + 0x24);
              *(undefined4 *)(glContext + 0x120) = 0;
              *(undefined4 *)(glContext + 0x124) = 0;
              (**(code **)(glContext + 0x4884))
                        (glContext,a1,textureLevel,iVar15,iVar20,*(undefined4 *)(glContext + 0x4858),
                         (double)quadX0,(double)quadY0,f2,(double)*(float *)(glContext + 0x24));
              *(float *)(glContext + 0x120) = (float)(double)tileWidth;
              *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
              *(undefined4 *)(glContext + 0x124) = 0;
              *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
              (**(code **)(glContext + 0x4884))
                        (glContext,a1_00,textureLevel,iVar15,iVar20,*(undefined4 *)(glContext + 0x4858),
                         (double)quadX1,(double)quadY0,f2);
              *(float *)(glContext + 0x120) = (float)(double)tileWidth;
              dVar34 = (double)dVar36;
              if ((double)tileHeight < (double)dVar36) {
                dVar34 = (double)tileHeight;
              }
              *(float *)(glContext + 0x124) = (float)dVar34;
              *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
              *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
              (**(code **)(glContext + 0x4884))
                        (glContext,a1_01,textureLevel,iVar15,iVar20,*(undefined4 *)(glContext + 0x4858),
                         (double)quadX1,(double)quadY1,f2);
              *(undefined4 *)(glContext + 0x120) = 0;
              if ((double)tileHeight < (double)dVar36) {
                dVar36 = (double)tileHeight;
              }
              *(float *)(glContext + 0x124) = (float)(double)dVar36;
              *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
              *(float *)(glContext + 300) = *(float *)(glContext + 0x24);
              iVar21 = *(int *)(glContext + 0x4858);
              (**(code **)(glContext + 0x4884))
                        (glContext,a1_02,textureLevel,iVar15,iVar20,iVar21,(double)quadX0,(double)quadY1,
                         f2,(double)*(float *)(glContext + 0x24));
              _glEnd_Exec(glContext);
              slotIndex = *drawPixelsShare;
              *drawPixelsShare = slotIndex + 1;
              if (*(uint *)(glContext + 0x7490) <= slotIndex + 1) {
                *drawPixelsShare = 0;
              }
            }
          }
          tileYCounter = (uint)(int)((double)(float)((double)CONCAT44(0x43300000,tileYCounter ^ 0x80000000) - intToDoubleBias2)
                         + (double)tileHeight);
          doubleToIntScratch3 = (longlong)(int)tileYCounter;
          quadY0 = quadY1;
          tileDestY = nextTileDestY;
          tileYOffset = (int)nextTileYOffsetF;
        } while ((int)tileYCounter < (int)imageHeight);
      }
      intToDoubleLow3 = tileXCounter ^ 0x80000000;
      intToDoubleHigh3 = 0x43300000;
      tileXCounter = (uint)(int)((double)(float)((double)CONCAT44(0x43300000,intToDoubleLow3) - intToDoubleBias) + (double)tileWidth);
      doubleToIntScratch3 = (longlong)(int)tileXCounter;
      quadX0 = quadX1;
      tileDestX = nextTileDestX;
      tileXOffset = (int)nextTileXOffsetF;
    } while ((int)tileXCounter < (int)imageWidth);
  }
  ((void (*)())_gleDrawPixelsRestoreState)(glContext,savedDrawState,savedDrawStateToken);
  if (convertedPixels != 0) {
    _gleVecFree(convertedPixels);
  }
  return 1;
}

/* _gleSetEnable_TEXTURE_1D @ 0xcb104 (80 bytes) */
void _gleSetEnable_TEXTURE_1D(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  int enable;
{
  uint newBits;
  int texUnitState;
  uint texUnit;
  uint oldBits;
  
  texUnit = *(uint *)(glContext + 0x53d4);
  if (texUnit < 8) {
    texUnitState = texUnit * 0x7c + glContext;
    oldBits = *(uint *)(texUnitState + 0x3534);
    newBits = oldBits & 0xffffffef | enable << 4;
    if (oldBits == newBits) {
      return;
    }
    *(uint *)(texUnitState + 0x3534) = newBits;
    _gleUpdateTextureParams(glContext,texUnit);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _gleSetEnable_TEXTURE_CUBE_MAP @ 0xcb154 (76 bytes) */
void _gleSetEnable_TEXTURE_CUBE_MAP(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  uint newBits;
  int texUnitState;
  uint texUnit;
  uint oldBits;
  
  texUnit = *(uint *)(glContext + 0x53d4);
  if (texUnit < 8) {
    texUnitState = texUnit * 0x7c + glContext;
    oldBits = *(uint *)(texUnitState + 0x3534);
    newBits = oldBits & 0xfffffffe | enable;
    if (oldBits == newBits) {
      return;
    }
    *(uint *)(texUnitState + 0x3534) = newBits;
    _gleUpdateTextureParams(glContext,texUnit);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _gleSetEnable_SHARED_TEXTURE_PALETTE_EXT @ 0xcb1a0 (100 bytes) */
void _gleSetEnable_SHARED_TEXTURE_PALETTE_EXT(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  int enable;
{
  uint newBits;
  int texUnitState;
  uint oldBits;
  uint texUnit;
  
  texUnit = *(uint *)(glContext + 0x53d4);
  if (texUnit < 8) {
    texUnitState = texUnit * 0x7c + glContext;
    oldBits = *(uint *)(texUnitState + 0x3534);
    newBits = oldBits & 0xfffffeff | enable << 8;
    if (oldBits == newBits) {
      return;
    }
    *(uint *)(texUnitState + 0x3534) = newBits;
    *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 1 << (texUnit & 0x3f);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _gleSetEnable_LINE_STIPPLE @ 0xcb204 (32 bytes) */
void _gleSetEnable_LINE_STIPPLE(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x318c) == enable) {
    return;
  }
  *(char *)(glContext + 0x318c) = (char)enable;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x10000;
  return;
}

/* _gleSetEnable_POLYGON_STIPPLE @ 0xcb224 (32 bytes) */
void _gleSetEnable_POLYGON_STIPPLE(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x34d8) == enable) {
    return;
  }
  *(char *)(glContext + 0x34d8) = (char)enable;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x2000000;
  return;
}

/* _gleSetEnable_INDEX_LOGIC_OP @ 0xcb244 (32 bytes) */
void _gleSetEnable_INDEX_LOGIC_OP(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x3192) == enable) {
    return;
  }
  *(char *)(glContext + 0x3192) = (char)enable;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x20000;
  return;
}

/* _gleSetEnable_COLOR_LOGIC_OP @ 0xcb264 (32 bytes) */
void _gleSetEnable_COLOR_LOGIC_OP(glContext, cap, enable)
  int glContext;
  undefined4 cap;
  uint enable;
{
  if (*(byte *)(glContext + 0x3193) == enable) {
    return;
  }
  *(char *)(glContext + 0x3193) = (char)enable;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x20000;
  return;
}

