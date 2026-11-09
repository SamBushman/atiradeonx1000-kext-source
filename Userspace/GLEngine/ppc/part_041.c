#include "decls.h"

/* _gleRTCBuildABranch_c5274 @ 0xc5274 (12 bytes) */
int _gleRTCBuildABranch_c5274(param_1, param_2)
  uint param_1;
  uint param_2;
{
  return (param_2 & 0x3fff) << 2 | param_1 & 0xffff0003;
}

/* _gleRTCAddAChunk_c5280 @ 0xc5280 (48 bytes) */
int _gleRTCAddAChunk_c5280(param_1, param_2)
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

/* _gleSetNormalFunc @ 0xc52b0 (96 bytes) */
int _gleSetNormalFunc(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)(*_gleBuildNormalTransformFunc)();
  *(code **)(param_1 + 0x5068) = UNRECOVERED_JUMPTABLE;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3);
  return;
}

/* FUN_000c531c @ 0xc531c (456 bytes) */
void FUN_000c531c(int param_1,uint param_2,int param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  byte bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  undefined *puVar13;
  int iVar14;
  int iVar15;
  uint unaff_r29;
  uint uVar16;
  uint uVar17;
  double dVar18;
  
  bVar1 = *(byte *)(param_1 + 0x4660);
  if (param_2 < unaff_r29) {
    uVar17 = (unaff_r29 - param_2) + 0xff >> 8;
    uVar16 = param_2;
    do {
      *(undefined4 *)(uVar16 + 0xf0) = 0;
      *(undefined4 *)(uVar16 + 0xf4) = 0;
      *(undefined4 *)(uVar16 + 0xf8) = 0;
      uVar16 = uVar16 + 0x100;
      uVar17 = uVar17 - 1;
    } while (uVar17 != 0);
  }
  iVar15 = 0;
  if (bVar1 != 0) {
    iVar14 = param_1;
    do {
      fVar2 = *(float *)(iVar14 + 0x22c0);
      fVar3 = *(float *)(iVar14 + 0x22c4);
      fparam_1 = (double)*(float *)(iVar14 + 0x22c8);
      fVar4 = *(float *)(iVar14 + 0x22d0);
      fVar5 = *(float *)(iVar14 + 0x22d4);
      fVar6 = *(float *)(iVar14 + 0x22d8);
      fVar7 = *(float *)(iVar14 + 0x22e0);
      fVar8 = *(float *)(iVar14 + 0x22e4);
      fVar9 = *(float *)(iVar14 + 0x22e8);
      if (param_2 < param_2 + param_3) {
        uVar17 = ((param_2 + param_3) - param_2) + 0xff >> 8;
        uVar16 = param_2;
        do {
          fVar10 = *(float *)(uVar16 + 0x44);
          dVar18 = (double)*(float *)(uVar16 + 0x40);
          fVar11 = *(float *)(uVar16 + 0x48);
          fVar12 = *(float *)(iVar15 * 4 + uVar16 + 0x60);
          *(float *)(uVar16 + 0xf0) =
               fVar12 * (fVar11 * fVar7 + (float)(dVar18 * (double)fVar2 + (double)(fVar10 * fVar4))
                        ) + *(float *)(uVar16 + 0xf0);
          *(float *)(uVar16 + 0xf8) =
               fVar12 * (fVar11 * fVar9 + (float)(dVar18 * fparam_1 + (double)(fVar10 * fVar6))) +
               *(float *)(uVar16 + 0xf8);
          *(float *)(uVar16 + 0xf4) =
               fVar12 * (fVar11 * fVar8 + (float)(dVar18 * (double)fVar3 + (double)(fVar10 * fVar5))
                        ) + *(float *)(uVar16 + 0xf4);
          uVar16 = uVar16 + 0x100;
          uVar17 = uVar17 - 1;
        } while (uVar17 != 0);
      }
      iVar15 = iVar15 + 1;
      iVar14 = iVar14 + 0x40;
    } while (iVar15 < (int)(uint)bVar1);
  }
  puVar13 = PTR__gleVectorNormalize_00112064;
  uVar17 = param_2 + param_3;
  if (*(char *)(param_1 + 0x280d) == '\0') {
    if (param_2 < uVar17) {
      uVar17 = (uVar17 - param_2) + 0xff >> 8;
      do {
        *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(param_2 + 0xf0);
        *(undefined4 *)(param_2 + 0x44) = *(undefined4 *)(param_2 + 0xf4);
        *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(param_2 + 0xf8);
        param_2 = param_2 + 0x100;
        uVar17 = uVar17 - 1;
      } while (uVar17 != 0);
    }
  }
  else {
    for (; param_2 < uVar17; param_2 = param_2 + 0x100) {
      fparam_1 = (double)(**(double ( **)(int,int,int,double))puVar13)(param_1, param_2 + 0xf0, param_2 + 0x40, fparam_1);
    }
  }
  return;
}

/* FUN_000c54e8 @ 0xc54e8 (852 bytes) */
int FUN_000c54e8(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  int *piVar12;
  int *piVar13;
  
  piVar13 = (int *)PTR__gleTransformNormalBlend_00110a04;
  if (*(char *)(param_1 + 0x4661) == '\0') {
    uVar1 = (**(code **)PTR__gleGenerateMatrixIdentifier_00112060)(param_1,param_1 + 0x22c0);
    *(uint *)(param_1 + 0x509c) = uVar1;
    uVar8 = (uint)*(byte *)(param_1 + 0x280d);
    if ((uVar1 & 0x3cccf000) == 0x3cccf000) {
      iVar10 = 0x3fcff3ff;
      if ((uVar1 & 0xfcfcfc00) == 0xbcecf800) {
        iVar10 = -0x40100401;
      }
    }
    else {
      iVar10 = 0x30303ff;
    }
    piVar12 = *(int **)(param_1 + 0x50a0);
    piVar13 = piVar12;
    do {
      if (iVar10 == piVar13[2] && uVar8 == piVar13[3]) {
        if (piVar13 != piVar12) {
          _gleMoveFuncCacheElem(piVar12,piVar13);
          *(int **)(param_1 + 0x50a0) = piVar13;
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
      if (*(short *)(param_1 + 0x50a6) == *(short *)(param_1 + 0x50a4)) {
        _gleDeleteFuncCacheElem(*(undefined4 *)(iVar2 + 4));
      }
      else {
        *(short *)(param_1 + 0x50a6) = *(short *)(param_1 + 0x50a6) + 1;
      }
      puVar9 = (undefined4 *)(iVar2 + 0x20);
      if ((uVar8 != 0) || (iVar10 != -0x40100401)) {
        iVar3 = ((int (*)())_gleRTCAddAChunk_c5280)(&_glePrologAVRTC,puVar9);
        puVar7 = puVar9 + iVar3;
        if (iVar10 != -0x40100401) {
          iVar3 = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleLoadMatrixPtrRTC,puVar7);
          iVar4 = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleLoadMatrixVectorsRTC,puVar7 + iVar3);
          puVar7 = puVar7 + iVar3 + iVar4;
        }
        if (iVar10 == 0x30303ff) {
          iVar10 = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleLoadVectorsRTC,puVar7);
          puVar9 = puVar7 + iVar10;
          puVar5 = &_gleFullMatrixMultRTC;
        }
        else if (iVar10 == 0x3fcff3ff) {
          iVar10 = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleDiagMatrixSetupRTC,puVar7);
          puVar7 = puVar7 + iVar10;
          iVar10 = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleLoadVectorsRTC,puVar7);
          puVar9 = puVar7 + iVar10;
          puVar5 = &_gleDiagMatrixMultRTC;
        }
        else {
          iVar10 = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleLoadVectorsRTC,puVar7);
          puVar9 = puVar7 + iVar10;
          puVar5 = &_gleIdentityMatrixMultRTC;
        }
        iVar10 = ((int (*)())_gleRTCAddAChunk_c5280)(puVar5,puVar9);
        puVar9 = puVar9 + iVar10;
        if (uVar8 != 0) {
          iVar10 = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleNormalizeAVRTC,puVar9);
          puVar9 = puVar9 + iVar10;
        }
        iVar10 = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleStoreVectorsRTC,puVar9);
        puVar9 = puVar9 + iVar10;
        iVar10 = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleEpilogAVRTC,puVar9);
        puVar11 = puVar9 + -1;
        puVar9 = puVar9 + iVar10;
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
      *(int *)(param_1 + 0x50a0) = iVar2;
      (**(code **)puVar5)(iVar10,(int *)(iVar2 + 0x20));
      piVar13 = (int *)(iVar2 + 0x20);
    }
  }
  return piVar13;
}

/* FUN_000c5840 @ 0xc5840 (1424 bytes) */
int FUN_000c5840(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  int *piVar13;
  uint uVar14;
  uint *puVar15;
  uint uVar16;
  uint *puVar17;
  uint *puVar18;
  int iVar19;
  int local_50 [13];
  
  if (*(char *)(param_1 + 0x4661) != '\0') {
    return (int *)PTR__gleTransformNormalBlend_00110a04;
  }
  uVar4 = (**(code **)PTR__gleGenerateMatrixIdentifier_00112060)(param_1,param_1 + 0x22c0);
  piVar12 = *(int **)(param_1 + 0x50a0);
  uVar16 = (uint)*(byte *)(param_1 + 0x280d);
  *(uint *)(param_1 + 0x509c) = uVar4;
  uVar14 = uVar4 | 0x30303ff;
  piVar13 = piVar12;
  do {
    if (uVar14 == piVar13[2] && uVar16 == piVar13[3]) {
      if (piVar13 != piVar12) {
        _gleMoveFuncCacheElem(piVar12,piVar13);
        *(int **)(param_1 + 0x50a0) = piVar13;
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
  if (*(short *)(param_1 + 0x50a6) == *(short *)(param_1 + 0x50a4)) {
    _gleDeleteFuncCacheElem(*(undefined4 *)(iVar5 + 4));
  }
  else {
    *(short *)(param_1 + 0x50a6) = *(short *)(param_1 + 0x50a6) + 1;
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
  iVar19 = 0xb;
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
    iVar19 = iVar19 + -1;
  } while (iVar19 != 0);
  if (bVar2) {
    iVar10 = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleLoadMatrixPtrRTC,puVar17);
    puVar17 = puVar17 + iVar10;
  }
  iVar10 = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleLoadCounterRTC,puVar17);
  puVar18 = puVar17 + iVar10;
  uVar16 = 0;
  uVar4 = 0;
  iVar10 = 0xb;
  do {
    if ((uVar14 << (uVar4 & 0x3f) & 0xc0000000) == 0) {
      *puVar18 = *(int *)((int)local_50 + uVar16) << 0x15 | uVar16 & 0xffff | 0xc0060000;
      puVar18 = puVar18 + 1;
    }
    uVar4 = uVar4 + 2;
    uVar16 = uVar16 + 4;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  iVar10 = 3;
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
      *puVar18 = uVar3;
      puVar18 = puVar18 + 1;
    }
    uVar8 = uVar8 - 1;
    uVar16 = uVar16 - 0x200000;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  if (!bVar1) {
    if ((*(uint *)PTR__gle_processor_0011204c & 1) == 0) {
      puVar6 = &_gleNormalizeInitNORTC;
    }
    else {
      puVar6 = &_gleNormalizeInitGRRTC;
    }
    iVar10 = ((int (*)())_gleRTCAddAChunk_c5280)(puVar6,puVar18);
    puVar18 = puVar18 + iVar10;
  }
  iVar10 = 3;
  uVar9 = 2;
  uVar3 = 0x48;
  uVar16 = 0x48;
  uVar8 = 0xa00000;
  uVar7 = 0x14;
  uVar4 = uVar14;
  puVar17 = puVar18;
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
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  puVar17 = (uint *)_gleEmitTransformInstructions(puVar17,uVar4,local_50,0,3,0);
  if (!bVar1) {
    if ((*(uint *)PTR__gle_processor_0011204c & 1) == 0) {
      puVar6 = &_gleNormalizeNORTC;
    }
    else {
      puVar6 = &_gleNormalizeGRRTC;
    }
    iVar10 = ((int (*)())_gleRTCAddAChunk_c5280)(puVar6,puVar17);
    puVar17 = puVar17 + iVar10;
  }
  iVar10 = 3;
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
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  iVar10 = ((int (*)())_gleRTCAddAChunk_c5280)(&_gleEndLoopRTC,puVar17);
  puVar17 = puVar17 + iVar10;
  puVar15 = puVar17 + -1;
  if ((bVar1) || (uVar4 = 0xfffffff8, (*(uint *)PTR__gle_processor_0011204c & 1) != 0)) {
    uVar4 = 0;
  }
  uVar16 = 0;
  iVar10 = 0xb;
  piVar13 = local_50;
  do {
    if (((uVar14 << ((uVar16 & 0x1f) << 1) & 0xc0000000) == 0) && (0xd < *piVar13)) {
      uVar4 = uVar4 - 8;
      *puVar17 = *piVar13 << 0x15 | uVar4 & 0xffff | 0xc8010000;
      puVar17 = puVar17 + 1;
    }
    uVar16 = uVar16 + 1;
    piVar13 = piVar13 + 1;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  uVar4 = ((int (*)())_gleRTCBuildABranch_c5274)(*puVar15,(int)puVar18 - (int)puVar15 >> 2);
  *puVar15 = uVar4;
LAB_000c5d58:
  iVar10 = (int)puVar17 + (-0x1c - iVar5) >> 2;
  *puVar17 = 0x4e800020;
  if (iVar10 < 0x51) {
    iVar5 = _gleShrinkFuncCacheElem(iVar5,iVar10);
    puVar6 = PTR__glePushInstructions_00112054;
    *(int *)(param_1 + 0x50a0) = iVar5;
    (**(code **)puVar6)(iVar10,(int *)(iVar5 + 0x20));
    return (int *)(iVar5 + 0x20);
  }
                    
  _exit(1);
}

/* _gleRTCBuildABranch_c5dd0 @ 0xc5dd0 (12 bytes) */
int _gleRTCBuildABranch_c5dd0(param_1, param_2)
  uint param_1;
  uint param_2;
{
  return (param_2 & 0x3fff) << 2 | param_1 & 0xffff0003;
}

/* _gleRTCAddAChunk_c5ddc @ 0xc5ddc (48 bytes) */
int _gleRTCAddAChunk_c5ddc(param_1, param_2)
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

/* _gleSetProjectionFuncW1 @ 0xc5e0c (104 bytes) */
int _gleSetProjectionFuncW1(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  code *pcVar1;
  
  pcVar1 = (code *)(*_gleBuildProjectionTransformFunc)(param_1,1);
  *(code **)(param_1 + 0x5060) = pcVar1;
  (*pcVar1)(param_1,param_2,param_3);
  return;
}

/* _gleSetProjectionFuncZ0W1 @ 0xc5e74 (104 bytes) */
int _gleSetProjectionFuncZ0W1(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  code *pcVar1;
  
  pcVar1 = (code *)(*_gleBuildProjectionTransformFunc)(param_1,3);
  *(code **)(param_1 + 0x5060) = pcVar1;
  (*pcVar1)(param_1,param_2,param_3);
  return;
}

/* _gleTransformProjectionBlend @ 0xc5edc (1264 bytes) */
void _gleTransformProjectionBlend(int param_1,float *param_2,int param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
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
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  int iVar36;
  float *pfVar37;
  float *pfVar38;
  uint uVar39;
  int iVar40;
  uint uVar41;
  float *pfVar42;
  int iVar43;
  uint uVar44;
  double dVar45;
  
  fVar35 = FLOAT_00108e50;
  uVar39 = (uint)*(byte *)(param_1 + 0x4660);
  pfVar38 = param_2 + param_3 * 0x40;
  if (*(char *)(param_1 + 0x4662) == '\0') {
    if (param_2 < pfVar38) {
      uVar44 = (uint)((int)pfVar38 + (0xff - (int)param_2)) >> 8;
      pfVar38 = param_2;
      do {
        pfVar38[0x3c] = fVar35;
        pfVar38[0x3d] = fVar35;
        pfVar38[0x3e] = fVar35;
        pfVar38[0x3f] = fVar35;
        pfVar38 = pfVar38 + 0x40;
        uVar44 = uVar44 - 1;
      } while (uVar44 != 0);
    }
  }
  else if (param_2 < pfVar38) {
    iVar36 = uVar39 - 1;
    pfVar42 = param_2;
    do {
      pfVar42[0x3c] = fVar35;
      pfVar42[0x3d] = fVar35;
      pfVar42[0x3e] = fVar35;
      pfVar42[0x3f] = fVar35;
      iVar40 = 0;
      fVar3 = FLOAT_00108e54;
      if (0 < iVar36) {
        pfVar37 = pfVar42 + 0x18;
        iVar43 = iVar36;
        do {
          fVar2 = *pfVar37;
          pfVar37 = pfVar37 + 1;
          fVar3 = fVar3 - fVar2;
          iVar43 = iVar43 + -1;
          iVar40 = iVar36;
        } while (iVar43 != 0);
      }
      pfVar37 = pfVar42 + 0x40;
      pfVar42[iVar40 + 0x18] = fVar3;
      pfVar42 = pfVar37;
    } while (pfVar37 < pfVar38);
  }
  iVar36 = 0;
  if (uVar39 != 0) {
    pfVar38 = (float *)(param_1 + 0x1cc0);
    do {
      fVar3 = *pfVar38;
      fVar2 = pfVar38[1];
      fVar4 = pfVar38[2];
      fVar5 = pfVar38[3];
      fVar6 = pfVar38[4];
      fVar7 = pfVar38[5];
      fVar8 = pfVar38[6];
      fVar9 = pfVar38[7];
      fVar10 = pfVar38[8];
      fVar11 = pfVar38[9];
      fVar12 = pfVar38[10];
      fVar13 = pfVar38[0xb];
      fVar14 = pfVar38[0xc];
      fVar15 = pfVar38[0xd];
      fVar16 = pfVar38[0xe];
      fVar17 = pfVar38[0xf];
      if (param_2 < param_2 + param_3 * 0x40) {
        uVar44 = (uint)((int)(param_2 + param_3 * 0x40) + (0xff - (int)param_2)) >> 8;
        pfVar42 = param_2;
        do {
          fVar18 = pfVar42[9];
          fVar19 = pfVar42[8];
          fVar20 = pfVar42[10];
          fVar21 = pfVar42[0xb];
          fVar22 = pfVar42[iVar36 + 0x18];
          pfVar42[0x3c] =
               fVar22 * (fVar21 * fVar14 + (fVar20 * fVar10 + (fVar19 * fVar3 + fVar18 * fVar6))) +
               pfVar42[0x3c];
          pfVar42[0x3f] =
               fVar22 * (fVar21 * fVar17 + (fVar20 * fVar13 + (fVar19 * fVar5 + fVar18 * fVar9))) +
               pfVar42[0x3f];
          pfVar42[0x3d] =
               fVar22 * (fVar21 * fVar15 + (fVar20 * fVar11 + (fVar19 * fVar2 + fVar18 * fVar7))) +
               pfVar42[0x3d];
          pfVar42[0x3e] =
               fVar22 * (fVar21 * fVar16 + (fVar20 * fVar12 + (fVar19 * fVar4 + fVar18 * fVar8))) +
               pfVar42[0x3e];
          pfVar42 = pfVar42 + 0x40;
          uVar44 = uVar44 - 1;
        } while (uVar44 != 0);
      }
      iVar36 = iVar36 + 1;
      pfVar38 = pfVar38 + 0x10;
    } while (iVar36 < (int)uVar39);
  }
  fVar3 = *(float *)(param_1 + 0x4a20);
  fVar2 = *(float *)(param_1 + 0x1c8c);
  pfVar38 = param_2 + param_3 * 0x40;
  fVar4 = *(float *)(param_1 + 0x4a28);
  fVar5 = *(float *)(param_1 + 0x1c9c);
  uVar39 = 0;
  fVar6 = *(float *)(param_1 + 0x1cac);
  uVar44 = 0xff;
  fVar7 = *(float *)(param_1 + 0x1cbc);
  fVar8 = *(float *)(param_1 + 0x4a1c);
  fVar9 = *(float *)(param_1 + 0x4a24);
  fVar10 = *(float *)(param_1 + 0x1ca0);
  fVar11 = *(float *)(param_1 + 0x1cb0);
  fVar12 = *(float *)(param_1 + 0x1b70);
  fVar13 = *(float *)(param_1 + 0x1c94);
  fVar14 = *(float *)(param_1 + 0x1c80);
  fVar15 = *(float *)(param_1 + 0x1c84);
  fVar16 = *(float *)(param_1 + 0x1c90);
  fVar17 = *(float *)(param_1 + 0x1ca4);
  fVar18 = *(float *)(param_1 + 0x1cb4);
  fVar19 = *(float *)(param_1 + 0x1cb8);
  fVar20 = *(float *)(param_1 + 0x1c88);
  fVar21 = *(float *)(param_1 + 0x1c98);
  fVar22 = *(float *)(param_1 + 0x1ca8);
  fVar23 = *(float *)(param_1 + 0x1b74);
  fVar24 = *(float *)(param_1 + 0x1b78);
  fVar25 = *(float *)(param_1 + 0x1b84);
  fVar26 = *(float *)(param_1 + 0x1b80);
  fVar27 = *(float *)(param_1 + 0x1b88);
  do {
    if (pfVar38 <= param_2) {
      restFP(uVar44 << 8 | uVar39);
      return;
    }
    uVar41 = 0;
    fVar28 = param_2[0x3c];
    fVar29 = param_2[0x3d];
    fVar30 = param_2[0x3e];
    fVar31 = param_2[0x3f];
    if ((*(byte *)(param_1 + 0x50b4) & 2) != 0) {
      fVar32 = fVar30;
      if (*(short *)(param_1 + 0x3166) == -0x7baf) {
        fVar32 = param_2[0x17];
      }
      if (fVar35 < fVar32) {
        fVar32 = -fVar32;
      }
      fVar1 = FLOAT_00108e54;
      if (*(short *)(param_1 + 0x3164) == 0x800) {
        if (fVar32 < fVar35) {
          fVar32 = *(float *)(param_1 + 0x3150) * fVar32;
          goto LAB_000c628c;
        }
      }
      else if (*(short *)(param_1 + 0x3164) == 0x2601) {
        fVar32 = (*(float *)(param_1 + 0x3158) + fVar32) * *(float *)(param_1 + 0x315c);
        if ((fVar32 <= FLOAT_00108e54) && (fVar1 = fVar32, fVar32 < fVar35)) {
          fVar1 = FLOAT_00108e50;
        }
      }
      else {
        fVar32 = *(float *)(param_1 + 0x3150) * fVar32;
        fVar32 = -fVar32 * fVar32;
LAB_000c628c:
        dVar45 = (double)_exp((double)fVar32);
        fVar1 = (float)dVar45;
      }
      param_2[0x13] = fVar1;
    }
    fVar33 = fVar31 * fVar7 + (fVar30 * fVar6 + (fVar28 * fVar2 + fVar29 * fVar5));
    fVar32 = fVar31 * (fVar8 * fVar11 + fVar3 * fVar7) +
             (fVar30 * (fVar8 * fVar10 + fVar3 * fVar6) +
             (fVar28 * (fVar8 * fVar14 + fVar3 * fVar2) + fVar29 * (fVar8 * fVar16 + fVar3 * fVar5)));
    fVar34 = -fVar33;
    fVar1 = fVar31 * fVar19 + (fVar30 * fVar22 + (fVar28 * fVar20 + fVar29 * fVar21));
    fVar28 = fVar31 * (fVar9 * fVar18 + fVar4 * fVar7) +
             (fVar30 * (fVar9 * fVar17 + fVar4 * fVar6) +
             (fVar28 * (fVar9 * fVar15 + fVar4 * fVar2) + fVar29 * (fVar9 * fVar13 + fVar4 * fVar5)));
    if (fVar32 < fVar34) {
      uVar41 = 0x10;
    }
    if (fVar33 <= fVar32) {
      uVar41 = uVar41 | 0x20;
    }
    if (fVar28 < fVar34) {
      uVar41 = uVar41 | 4;
    }
    if (fVar33 <= fVar28) {
      uVar41 = uVar41 | 8;
    }
    if (fVar1 < fVar34) {
      uVar41 = uVar41 | 1;
    }
    if (fVar33 < fVar1) {
      uVar41 = uVar41 | 2;
    }
    param_2[4] = fVar32;
    param_2[5] = fVar28;
    param_2[6] = fVar1;
    param_2[7] = fVar33;
    *(char *)((int)param_2 + 0x7f) = (char)uVar41;
    if (uVar41 == 0) {
      fVar33 = FLOAT_00108e54 / fVar33;
      param_2[3] = fVar33;
      *param_2 = fVar32 * fVar33 * fVar12 + fVar26;
      param_2[1] = fVar28 * fVar33 * fVar23 + fVar25;
      param_2[2] = fVar1 * fVar33 * fVar24 + fVar27;
    }
    param_2 = param_2 + 0x40;
    uVar44 = uVar44 & uVar41;
    uVar39 = uVar39 | uVar41;
  } while( true );
}

/* _gleBuildProjectionTransformFuncNO @ 0xc63cc (1544 bytes) */
int _gleBuildProjectionTransformFuncNO(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int *piVar15;
  int *piVar16;
  uint *puVar17;
  uint *puVar18;
  uint *puVar19;
  int iVar20;
  int local_70 [15];
  int local_34;
  
  if (*(char *)(param_1 + 0x4661) != '\0') {
    return (int *)PTR__gleTransformProjectionBlend_00110a10;
  }
  uVar3 = (**(code **)PTR__gleGenerateMatrixIdentifier_00112060)(param_1,param_1 + 0x27c0);
  *(uint *)(param_1 + 0x5084) = uVar3;
  if ((param_2 & 2) != 0) {
    uVar3 = uVar3 | 0xff00;
  }
  if ((*(undefined **)(param_1 + 0x5080) == ((unsigned char *)0x00001101)) && (*(int *)(param_1 + 0x4e1c) == 0x1c00)
     ) {
    param_2 = param_2 | 8;
  }
  piVar15 = *(int **)(param_1 + 0x5088);
  piVar16 = piVar15;
  do {
    if (uVar3 == piVar16[2] && param_2 == piVar16[3]) {
      if (piVar16 != piVar15) {
        _gleMoveFuncCacheElem(piVar15,piVar16);
        *(int **)(param_1 + 0x5088) = piVar16;
      }
      return piVar16 + 8;
    }
    piVar16 = (int *)*piVar16;
  } while (piVar16 != piVar15);
  iVar4 = _gleCreateFuncCacheElem(piVar16,0x90);
  if (iVar4 == 0) {
    return (int *)PTR__gleRTCNoop_00112058;
  }
  *(uint *)(iVar4 + 8) = uVar3;
  *(uint *)(iVar4 + 0xc) = param_2;
  if (*(short *)(param_1 + 0x508e) == *(short *)(param_1 + 0x508c)) {
    _gleDeleteFuncCacheElem(*(undefined4 *)(iVar4 + 4));
  }
  else {
    *(short *)(param_1 + 0x508e) = *(short *)(param_1 + 0x508e) + 1;
  }
  iVar11 = 0x10;
  iVar20 = 0x10;
  *(undefined4 *)(iVar4 + 0x20) = 0xd9c1fff8;
  *(undefined4 *)(iVar4 + 0x24) = 0xd9e1fff0;
  puVar17 = (uint *)(iVar4 + 0x28);
  uVar8 = 0xfffffff0;
  bVar1 = false;
  uVar13 = 0;
  piVar16 = local_70;
  do {
    if ((uVar3 << ((uVar13 & 0x1f) << 1) & 0xc0000000) == 0) {
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
    iVar20 = iVar20 + -1;
  } while (iVar20 != 0);
  iVar11 = ((int (*)())_gleRTCAddAChunk_c5ddc)(&_glePrologNORTC,puVar17);
  puVar17[iVar11] = 0xc1230024;
  puVar17 = puVar17 + iVar11 + 1;
  if (bVar1) {
    iVar11 = ((int (*)())_gleRTCAddAChunk_c5ddc)(&_gleLoadMatrixPtrRTC,puVar17);
    puVar17 = puVar17 + iVar11;
  }
  iVar11 = ((int (*)())_gleRTCAddAChunk_c5ddc)(&_gleLoadViewportRTC,puVar17);
  puVar17 = puVar17 + iVar11;
  uVar13 = 0;
  uVar8 = 0;
  iVar11 = 0x10;
  do {
    if ((uVar3 << (uVar8 & 0x3f) & 0xc0000000) == 0) {
      *puVar17 = *(int *)((int)local_70 + uVar13) << 0x15 | uVar13 & 0xffff | 0xc0060000;
      puVar17 = puVar17 + 1;
    }
    uVar8 = uVar8 + 2;
    uVar13 = uVar13 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  iVar11 = 4;
  uVar8 = 0;
  uVar14 = 3;
  uVar13 = 0xe00000;
  do {
    if ((uVar3 << ((uVar14 & 0x1f) << 1) & 0xc0c0c0c0) == 0xc0c0c0c0) {
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
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  uVar8 = param_2;
  uVar13 = uVar3;
  if ((param_2 & 1) == 0) {
    uVar14 = 3;
    goto LAB_000c6778;
  }
  uVar14 = uVar3 & 0x3030303;
  if (uVar14 == 0x3030302) {
    *puVar17 = 0xfce04890;
    puVar17 = puVar17 + 1;
    *puVar17 = 0xfd003850;
    uVar8 = param_2 | 4;
LAB_000c6720:
    puVar17 = puVar17 + 1;
    uVar2 = 1;
    uVar13 = uVar3 | 0x3030303;
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
      iVar11 = _gleEmitTransformInstructions(puVar18,uVar13,local_70,0,4,param_2 & 1);
      if ((uVar8 & 8) == 0) {
        if ((uVar8 & 4) == 0) {
          puVar5 = &_gleCalcClipCodeNORTC;
        }
        else {
          puVar5 = &_gleCalcClipCodeW1NORTC;
        }
      }
      else if ((uVar8 & 4) == 0) {
        puVar5 = &_gleNoClipCodeNORTC;
      }
      else {
        puVar5 = &_gleNoClipCodeW1NORTC;
      }
      iVar20 = ((int (*)())_gleRTCAddAChunk_c5ddc)(puVar5,iVar11);
      iVar11 = iVar11 + iVar20 * 4;
      iVar20 = ((int (*)())_gleRTCAddAChunk_c5ddc)(&_gleClipSumsAndEndLoopRTC,iVar11);
      uVar8 = 0xfffffff0;
      puVar19 = (uint *)(iVar11 + iVar20 * 4);
      uVar13 = 0;
      puVar18 = puVar19 + -1;
      piVar16 = local_70;
      iVar11 = 0x10;
      do {
        if ((uVar3 << ((uVar13 & 0x1f) << 1) & 0xc0000000) == 0) {
          uVar8 = uVar8 - 8;
          *puVar19 = *piVar16 << 0x15 | uVar8 & 0xffff | 0xc8010000;
          puVar19 = puVar19 + 1;
        }
        uVar13 = uVar13 + 1;
        piVar16 = piVar16 + 1;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      *puVar19 = 0xc9e1fff0;
      puVar19[1] = 0xc9c1fff8;
      puVar19 = puVar19 + 2;
      iVar11 = ((int (*)())_gleRTCAddAChunk_c5ddc)(&_gleCombineClipSumsNORTC,puVar19);
      puVar19 = puVar19 + iVar11;
      iVar11 = ((int (*)())_gleRTCAddAChunk_c5ddc)(&_gleEpilogNORTC,puVar19);
      uVar3 = ((int (*)())_gleRTCBuildABranch_c5dd0)(*puVar18,(int)puVar17 - (int)puVar18 >> 2);
      iVar20 = (int)(puVar19 + iVar11) + (-0x1c - iVar4) >> 2;
      *puVar18 = uVar3;
      puVar19[iVar11] = 0x4e800020;
      if (iVar20 < 0x91) {
        iVar4 = _gleShrinkFuncCacheElem(iVar4,iVar20);
        puVar5 = PTR__glePushInstructions_00112054;
        *(int *)(param_1 + 0x5088) = iVar4;
        (**(code **)puVar5)(iVar20,(int *)(iVar4 + 0x20));
        return (int *)(iVar4 + 0x20);
      }
                    
      _exit(1);
    }
  } while( true );
}

/* _gleGetClientAttrib @ 0xc69d4 (460 bytes) */
int _gleGetClientAttrib(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  
  if (param_2 == 1) {
    *param_3 = *(undefined4 *)(param_1 + 0x31b0);
    param_3[2] = *(undefined4 *)(param_1 + 0x31b8);
    param_3[3] = *(undefined4 *)(param_1 + 0x31bc);
    param_3[5] = *(undefined4 *)(param_1 + 0x31c4);
    *(undefined1 *)(param_3 + 6) = *(undefined1 *)(param_1 + 0x31c8);
    *(undefined1 *)((int)param_3 + 0x19) = *(undefined1 *)(param_1 + 0x31c9);
    param_3[1] = *(undefined4 *)(0x31b4 + param_1);
    param_3[4] = *(undefined4 *)(param_1 + 0x31c0);
    param_3[7] = *(undefined4 *)(param_1 + 0x31cc);
    param_3[9] = *(undefined4 *)(param_1 + 0x31d4);
    param_3[10] = *(undefined4 *)(param_1 + 0x31d8);
    param_3[0xc] = *(undefined4 *)(param_1 + 0x31e0);
    *(undefined1 *)(param_3 + 0xd) = *(undefined1 *)(param_1 + 0x31e4);
    *(undefined1 *)((int)param_3 + 0x35) = *(undefined1 *)(param_1 + 0x31e5);
    *(undefined1 *)((int)param_3 + 0x36) = *(undefined1 *)(param_1 + 0x31e6);
    param_3[8] = *(undefined4 *)(param_1 + 0x31d0);
    param_3[0xb] = *(undefined4 *)(param_1 + 0x31dc);
    return;
  }
  iVar2 = *(int *)(param_1 + 0x4a60);
  iVar5 = iVar2 + 0x10;
  *param_3 = *(undefined4 *)(iVar2 + 4);
  *(undefined2 *)((int)param_3 + 0x206) = *(undefined2 *)(param_1 + 0x48ea);
  iVar7 = 0x20;
  param_3[0xa7] = *(undefined4 *)(iVar2 + 0x334);
  puVar6 = param_3;
  do {
    puVar6[1] = (int)*(short *)(iVar5 + 0x2a);
    puVar6[2] = (uint)*(ushort *)(iVar5 + 0x28);
    puVar6[3] = *(undefined4 *)(iVar5 + 0x24);
    puVar1 = (undefined4 *)(iVar5 + 0x20);
    iVar5 = iVar5 + 0x18;
    puVar6[4] = *puVar1;
    puVar6 = puVar6 + 4;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uVar4 = 0;
  *(undefined2 *)(param_3 + 0x81) = *(undefined2 *)(param_1 + 0x48e8);
  param_3[0x82] = *(undefined4 *)(param_1 + 0x48e4);
  param_3[0x83] = *(undefined4 *)(param_1 + 0x48e0);
  param_3[0xa8] = *(undefined4 *)(iVar2 + 0x330);
  if (*(int *)(iVar2 + 0x358) != 0) {
    uVar4 = *(undefined4 *)(*(int *)(iVar2 + 0x358) + 4);
  }
  param_3[0x84] = uVar4;
  uVar4 = 0;
  if (*(int *)(iVar2 + 0x35c) != 0) {
    uVar4 = *(undefined4 *)(*(int *)(iVar2 + 0x35c) + 4);
  }
  param_3[0x85] = uVar4;
  iVar5 = 0x20;
  puVar6 = param_3 + 0x86;
  piVar3 = (int *)(iVar2 + 0x360);
  do {
    iVar7 = *piVar3;
    uVar4 = 0;
    piVar3 = piVar3 + 1;
    if (iVar7 != 0) {
      uVar4 = *(undefined4 *)(iVar7 + 4);
    }
    *puVar6 = uVar4;
    puVar6 = puVar6 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  uVar4 = 0;
  if (*(int *)(param_1 + 0x48f4) != 0) {
    uVar4 = *(undefined4 *)(*(int *)(param_1 + 0x48f4) + 4);
  }
  param_3[0xa6] = uVar4;
  param_3[0xaa] = *(undefined4 *)(iVar2 + 0x344);
  param_3[0xa9] = *(undefined4 *)(iVar2 + 0x348);
  param_3[0xab] = *(undefined4 *)(param_1 + 0x4984);
  param_3[0xac] = *(undefined4 *)(param_1 + 0x4988);
  param_3[0xad] = *(int *)(param_1 + 0x53d8) + 0x84c0;
  return;
}

/* _gleSetClientAttrib @ 0xc6ba0 (1172 bytes) */
int _gleSetClientAttrib(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  
  if (param_2 == 1) {
    *(int *)(param_1 + 0x31b0) = *param_3;
    *(int *)(param_1 + 0x31b8) = param_3[2];
    *(int *)(param_1 + 0x31bc) = param_3[3];
    *(int *)(param_1 + 0x31c4) = param_3[5];
    *(undefined1 *)(param_1 + 0x31c8) = *(undefined1 *)(param_3 + 6);
    *(undefined1 *)(param_1 + 0x31c9) = *(undefined1 *)((int)param_3 + 0x19);
    *(int *)(0x31b4 + param_1) = param_3[1];
    *(int *)(param_1 + 0x31c0) = param_3[4];
    *(int *)(param_1 + 0x31cc) = param_3[7];
    *(int *)(param_1 + 0x31d4) = param_3[9];
    *(int *)(param_1 + 0x31d8) = param_3[10];
    *(int *)(param_1 + 0x31e0) = param_3[0xc];
    *(undefined1 *)(param_1 + 0x31e4) = *(undefined1 *)(param_3 + 0xd);
    *(undefined1 *)(param_1 + 0x31e5) = *(undefined1 *)((int)param_3 + 0x35);
    *(undefined1 *)(param_1 + 0x31e6) = *(undefined1 *)((int)param_3 + 0x36);
    *(int *)(param_1 + 0x31d0) = param_3[8];
    *(int *)(param_1 + 0x31dc) = param_3[0xb];
  }
  else {
    iVar2 = *(int *)(param_1 + 0x4a60);
    if (*(int *)(iVar2 + 4) != *param_3) {
      _gleBindVertexArray(param_1,*param_3);
      iVar2 = *(int *)(param_1 + 0x4a60);
    }
    iVar4 = 0;
    if (*(int *)(iVar2 + 0x358) != 0) {
      iVar4 = *(int *)(*(int *)(iVar2 + 0x358) + 4);
    }
    *(undefined2 *)(param_1 + 0x48ea) = *(undefined2 *)((int)param_3 + 0x206);
    iVar3 = param_3[0xa7];
    *(undefined4 *)(iVar2 + 0x330) = 0;
    *(int *)(iVar2 + 0x334) = iVar3;
    *(int *)(iVar2 + 0x330) = param_3[0xa8];
    *(int *)(iVar2 + 0x334) = iVar3;
    iVar3 = param_3[0x86];
    if (iVar4 != iVar3) {
      _glBindBuffer_Exec(param_1,0x8892,iVar3);
      iVar4 = iVar3;
    }
    _glVertexPointer_Exec(param_1,param_3[1],param_3[2],param_3[3],param_3[4]);
    iVar3 = param_3[0x87];
    if (iVar4 != iVar3) {
      _glBindBuffer_Exec(param_1,0x8892,iVar3);
      iVar4 = iVar3;
    }
    _glNormalPointer_Exec(param_1,param_3[6] & 0xffff7fff,param_3[7],param_3[8]);
    iVar3 = param_3[0x88];
    if (iVar4 != iVar3) {
      _glBindBuffer_Exec(param_1,0x8892,iVar3);
      iVar4 = iVar3;
    }
    _glColorPointer_Exec(param_1,param_3[9],param_3[10] & 0xffff7fff,param_3[0xb],param_3[0xc]);
    iVar3 = param_3[0x8a];
    if (iVar4 != iVar3) {
      _glBindBuffer_Exec(param_1,0x8892,iVar3);
      iVar4 = iVar3;
    }
    _glFogCoordPointer_Exec(param_1,param_3[0xe],param_3[0xf],param_3[0x10]);
    iVar3 = param_3[0x8b];
    if (iVar4 != iVar3) {
      _glBindBuffer_Exec(param_1,0x8892,iVar3);
      iVar4 = iVar3;
    }
    _glSecondaryColorPointer_Exec
              (param_1,param_3[0x11],param_3[0x12] & 0xffff7fff,param_3[0x13],param_3[0x14]);
    iVar3 = param_3[0x89];
    if (iVar4 != iVar3) {
      _glBindBuffer_Exec(param_1,0x8892,iVar3);
      iVar4 = iVar3;
    }
    _glWeightPointerARB_Exec
              (param_1,param_3[0x15],param_3[0x16] & 0xffff7fff,param_3[0x17],param_3[0x18]);
    iVar3 = param_3[0x8c];
    if (iVar4 != iVar3) {
      _glBindBuffer_Exec(param_1,0x8892,iVar3);
      iVar4 = iVar3;
    }
    _glEdgeFlagPointer_Exec(param_1,param_3[0x1b],param_3[0x1c]);
    iVar3 = param_3[0x8d];
    if (iVar4 != iVar3) {
      _glBindBuffer_Exec(param_1,0x8892,iVar3);
      iVar4 = iVar3;
    }
    iVar3 = 0;
    piVar5 = param_3 + 0x8e;
    _glElementPointerAPPLE_Exec(param_1,param_3[0x1e],param_3[0x20]);
    piVar6 = param_3;
    do {
      iVar1 = *piVar5;
      piVar5 = piVar5 + 1;
      if (iVar4 != iVar1) {
        _glBindBuffer_Exec(param_1,0x8892,iVar1);
        iVar4 = iVar1;
      }
      *(int *)(param_1 + 0x53d8) = iVar3;
      iVar3 = iVar3 + 1;
      _glTexCoordPointer_Exec(param_1,piVar6[0x21],piVar6[0x22],piVar6[0x23],piVar6[0x24]);
      piVar6 = piVar6 + 4;
    } while (iVar3 < 8);
    piVar5 = param_3 + 0x96;
    iVar3 = 0;
    piVar6 = param_3;
    do {
      iVar1 = *piVar5;
      piVar5 = piVar5 + 1;
      if (iVar4 != iVar1) {
        _glBindBuffer_Exec(param_1,0x8892,iVar1);
        iVar4 = iVar1;
      }
      iVar1 = iVar3 + 1;
      _glVertexAttribPointerARB_Exec
                (param_1,iVar3,piVar6[0x41],piVar6[0x42] & 0xffff7fff,(uint)piVar6[0x42] >> 0xf & 1,
                 piVar6[0x43],piVar6[0x44]);
      piVar6 = piVar6 + 4;
      iVar3 = iVar1;
    } while (iVar1 < 0x10);
    iVar3 = param_3[0xa6];
    if (iVar4 != iVar3) {
      _glBindBuffer_Exec(param_1,0x8892,iVar3);
      iVar4 = iVar3;
    }
    _glIndexPointer_Exec(param_1,(uint)*(ushort *)(param_3 + 0x81),param_3[0x82],param_3[0x83]);
    if (iVar4 != param_3[0x84]) {
      _glBindBuffer_Exec(param_1,0x8892,param_3[0x84]);
    }
    iVar4 = 0;
    if (*(int *)(iVar2 + 0x35c) != 0) {
      iVar4 = *(int *)(*(int *)(iVar2 + 0x35c) + 4);
    }
    if (iVar4 != param_3[0x85]) {
      _glBindBuffer_Exec(param_1,0x8893,param_3[0x85]);
    }
    _glVertexArrayRangeEXT_Exec(param_1,param_3[0xa9],param_3[0xaa]);
    *(int *)(param_1 + 0x53d8) = param_3[0xad] + -0x84c0;
    if (*(int *)(param_1 + 0x4988) != 0) {
      _glUnlockArraysEXT_Exec(param_1);
    }
    if (param_3[0xac] != 0) {
      _glLockArraysEXT_Exec(param_1,param_3[0xab],param_3[0xac]);
    }
  }
  return;
}

/* _gleAddClientAttribElem @ 0xc7034 (120 bytes) */
int _gleAddClientAttribElem(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = _malloc(0x2c0);
  if (puVar2 == (undefined4 *)0x0) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x505;
    }
  }
  else {
    *puVar2 = param_2;
    ((int (*)())_gleGetClientAttrib)(param_1,param_2,puVar2 + 1);
    puVar1 = *(undefined4 **)(param_1 + 0x5140);
    puVar2[0xaf] = *puVar1;
    *puVar1 = puVar2;
  }
  return;
}

/* _gleRemoveClientAttribElem @ 0xc70ac (56 bytes) */
int _gleRemoveClientAttribElem(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_gleSetClientAttrib)(param_1,*param_2,param_2 + 1);
  _free(param_2);
  return;
}

/* _gleCreatePluginBuffer @ 0xc70e4 (124 bytes) */
int _gleCreatePluginBuffer(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = param_1 + 0x10000;
  iVar4 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    iVar5 = param_2;
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      iVar3 = iVar3 + 0x2e0;
      iVar4 = iVar4 + 1;
      (**(code **)(*piVar1 + 0x1d4))(*puVar2,iVar5,param_2 + 0x20,iVar5 + 0x38);
      iVar5 = iVar5 + 4;
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  return;
}

/* _gleFreeBufferObject @ 0xc7160 (168 bytes) */
int _gleFreeBufferObject(param_1, param_2)
  int param_1;
  void *param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 extraout_r3;
  int iVar3;
  int iVar4;
  void *pvVar5;
  
  iVar3 = param_1 + 0x10000;
  iVar4 = 0;
  pvVar5 = param_2;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      iVar4 = iVar4 + 1;
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      iVar3 = iVar3 + 0x2e0;
      (**(code **)(*piVar1 + 0x1d8))(*puVar2,*(undefined4 *)((int)pvVar5 + 0x10));
      *(undefined4 *)((int)pvVar5 + 0x10) = 0;
      pvVar5 = (void *)((int)pvVar5 + 4);
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  if (*(unsigned char *)((int)param_2 + 0x30) != 0) {
    _vm_deallocate(*(unsigned char *)PTR_00112034,*(unsigned char *)((int)param_2 + 0x30),
                   *(unsigned char *)((int)param_2 + 0x38));
  }
  _gleVecFree(param_2);
  return extraout_r3;
}

/* _gleCreateBufferObject @ 0xc7208 (212 bytes) */
int _gleCreateBufferObject(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar3 = (undefined4 *)_gleVecAlloc((uint)*(byte *)(param_1 + 0x85a4) * 4 + 0x48);
  puVar1 = PTR__gleFreeBufferObject_00110a1c;
  puVar3[0xd] = 0;
  puVar3[2] = 1;
  puVar3[3] = puVar1;
  *puVar3 = 0;
  *(undefined1 *)(puVar3 + 0x11) = 0;
  puVar3[0x10] = 0;
  puVar3[0xc] = 0;
  puVar3[0xe] = 0;
  *(undefined2 *)(puVar3 + 0xf) = 0x88e4;
  iVar4 = 8;
  *(undefined2 *)((int)puVar3 + 0x3e) = 0x88ba;
  puVar3[1] = param_2;
  puVar2 = puVar3 + 4;
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    puVar3 = puVar3 + 0x12;
    do {
      *puVar3 = 0xffffffff;
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  return;
}

/* _gleBindBufferObject @ 0xc72dc (460 bytes) */
int _gleBindBufferObject(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  
  iVar4 = *(int *)(param_1 + 0x4a60);
  iVar8 = *(int *)(param_1 + 0x5148) + 0x701c;
  if (param_3 == 0) {
    iVar3 = 0;
    bVar1 = true;
  }
  else {
    iVar3 = _gleLookupHashObject(iVar8,param_3);
    bVar1 = false;
    if (iVar3 == 0) {
      iVar3 = ((int (*)())_gleCreateBufferObject)(param_1,param_3);
      ((int (*)())_gleCreatePluginBuffer)(param_1,iVar3 + 0x10);
      _gleAddHashNameAndObject(param_1,iVar8,iVar3);
      bVar1 = iVar3 == 0;
    }
    *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;
  }
  if (param_2 == 0x8893) {
    iVar8 = *(int *)(iVar4 + 0x35c);
    *(int *)(iVar4 + 0x35c) = iVar3;
    if (bVar1) {
      iVar6 = 0;
      if (iVar3 < (int)(uint)*(byte *)(param_1 + 0x85a4)) {
        puVar5 = (undefined4 *)(iVar4 + 0x460);
        do {
          *puVar5 = 0;
          iVar6 = iVar6 + 1;
          puVar5 = puVar5 + 0x23;
        } while (iVar6 < (int)(uint)*(byte *)(param_1 + 0x85a4));
      }
    }
    else {
      iVar6 = 0;
      if (*(char *)(param_1 + 0x85a4) != '\0') {
        puVar5 = (undefined4 *)(iVar4 + 0x460);
        puVar7 = (undefined4 *)(iVar3 + 0x10);
        do {
          uVar2 = *puVar7;
          iVar6 = iVar6 + 1;
          puVar7 = puVar7 + 1;
          *puVar5 = uVar2;
          puVar5 = puVar5 + 0x23;
        } while (iVar6 < (int)(uint)*(byte *)(param_1 + 0x85a4));
      }
    }
    goto LAB_000c7440;
  }
  if (0x8893 < param_2) {
    if (param_2 == 0x88eb) {
      iVar8 = *(int *)(param_1 + 0x4a68);
      *(int *)(param_1 + 0x4a68) = iVar3;
      goto LAB_000c7440;
    }
    if (param_2 == 0x88ec) {
      iVar8 = *(int *)(param_1 + 0x4a6c);
      *(int *)(param_1 + 0x4a6c) = iVar3;
      goto LAB_000c7440;
    }
  }
  iVar8 = *(int *)(iVar4 + 0x358);
  *(int *)(iVar4 + 0x358) = iVar3;
LAB_000c7440:
  if ((!bVar1) && (*(int *)(iVar3 + 0x40) != 0)) {
    ((int (*)())_gleSynchronizePluginBuffer)(param_1,iVar3 + 0x10);
  }
  if ((iVar8 != 0) && (iVar4 = *(int *)(iVar8 + 8) + -1, *(int *)(iVar8 + 8) = iVar4, iVar4 == 0)) {
    ((int (*)())_gleFreeBufferObject)(param_1,iVar8);
    return;
  }
  return;
}

/* _gleOrphanBufferData @ 0xc74a8 (1088 bytes) */
int _gleOrphanBufferData(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  int param_3;
  uint param_4;
{
  int *piVar1;
  undefined4 *puVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  
  if (*(int *)(param_1 + 0x7484) == 0) {
    uVar6 = _gleVecAlloc(0x1800);
    iVar14 = 0x80;
    *(undefined4 *)(param_1 + 0x7484) = uVar6;
    iVar10 = 0;
    do {
      iVar13 = *(int *)(param_1 + 0x7484);
      iVar9 = iVar13 + iVar10;
      iVar5 = iVar9 + 0x14;
      *(undefined4 *)(iVar9 + 0x28) = 0;
      *(int *)(iVar9 + 0x20) = iVar5;
      *(int *)(iVar9 + 0x1c) = iVar5;
      *(int *)(iVar9 + 0x18) = iVar5;
      *(undefined4 *)(iVar9 + 0x24) = 0;
      *(int *)(iVar9 + 0x14) = iVar5;
      *(undefined4 *)(iVar9 + 0x10) = 0;
      *(undefined4 *)(iVar13 + iVar10) = 0;
      iVar10 = iVar10 + 0x30;
      *(undefined4 *)(iVar9 + 4) = 0;
      *(undefined4 *)(iVar9 + 8) = 0;
      *(undefined4 *)(iVar9 + 0xc) = 0;
      iVar14 = iVar14 + -1;
    } while (iVar14 != 0);
    uVar6 = _gleVecAlloc((uint)*(byte *)(param_1 + 0x85a4) * 4 + 0x1c);
    *(undefined4 *)(param_1 + 0x7464) = uVar6;
  }
  if (param_2[8] != 0) {
    piVar7 = *(int **)(param_1 + 0x7464);
    if (piVar7 == (int *)0x0) {
      piVar7 = (int *)_gleVecAlloc((uint)*(byte *)(param_1 + 0x85a4) * 4 + 0x1c);
    }
    else {
      *(undefined4 *)(param_1 + 0x7464) = 0;
    }
    iVar10 = 0;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      iVar14 = param_1 + 0x10000;
      piVar12 = piVar7 + 7;
      puVar11 = param_2;
      do {
        piVar1 = (int *)(iVar14 + -0x777c);
        uVar6 = *puVar11;
        iVar10 = iVar10 + 1;
        puVar11 = puVar11 + 1;
        puVar2 = (undefined4 *)(iVar14 + -0x7a54);
        iVar14 = iVar14 + 0x2e0;
        (**(code **)(*piVar1 + 0x1e8))(*puVar2,uVar6,piVar12);
        piVar12 = piVar12 + 1;
      } while (iVar10 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
    piVar7[4] = param_2[8];
    piVar7[5] = param_2[9];
    *(undefined2 *)(piVar7 + 6) = *(undefined2 *)(param_2 + 0xb);
    param_2[9] = 0;
    param_2[8] = 0;
    uVar8 = piVar7[5];
    iVar9 = (uVar8 >> 0xc & 0x7f) * 0x30;
    iVar10 = *(int *)(param_1 + 0x7474);
    iVar5 = *(int *)(param_1 + 0x7484) + iVar9;
    piVar7[3] = iVar10;
    puVar11 = *(undefined4 **)(iVar5 + 0x18);
    *(int **)(iVar10 + 8) = piVar7;
    piVar7[1] = (int)puVar11;
    *puVar11 = piVar7;
    piVar7[2] = param_1 + 0x7468;
    *piVar7 = iVar5 + 0x14;
    iVar10 = *(int *)(param_1 + 0x7454);
    iVar14 = *(int *)(param_1 + 0x7458);
    *(int **)(iVar5 + 0x18) = piVar7;
    *(int **)(param_1 + 0x7474) = piVar7;
    *(uint *)(param_1 + 0x7454) = iVar10 + uVar8;
    *(int *)(param_1 + 0x7458) = iVar14 + 1;
    *(int *)(iVar9 + *(int *)(param_1 + 0x7484)) =
         *(int *)(iVar9 + *(int *)(param_1 + 0x7484)) + piVar7[5];
    iVar9 = iVar9 + *(int *)(param_1 + 0x7484);
    *(int *)(iVar9 + 4) = *(int *)(iVar9 + 4) + 1;
  }
  iVar14 = (param_3 + 0xfffU >> 0xc & 0x7f) * 0x30;
  iVar10 = iVar14 + *(int *)(param_1 + 0x7484);
  piVar7 = *(int **)(iVar10 + 0x14);
  while( true ) {
    if (piVar7 == (int *)(iVar10 + 0x14)) goto LAB_000c7884;
    if ((*(ushort *)(piVar7 + 6) == param_4) && ((param_3 + 0xfffU & 0xfffff000) == piVar7[5]))
    break;
    piVar7 = (int *)*piVar7;
  }
  iVar10 = 0;
  if (*(char *)(param_1 + 0x85a4) == '\0') goto LAB_000c7744;
  piVar12 = piVar7 + 7;
  puVar11 = (undefined4 *)(param_1 + 0x85ac);
  bVar4 = true;
  do {
    bVar3 = false;
    if ((bVar4) && (iVar5 = (**(code **)(param_1 + 0x4834))(*puVar11,*piVar12), iVar5 != 0)) {
      bVar3 = true;
    }
    iVar10 = iVar10 + 1;
    puVar11 = puVar11 + 0xb8;
    piVar12 = piVar12 + 1;
    bVar4 = bVar3;
  } while (iVar10 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  if (bVar3) {
LAB_000c7744:
    iVar9 = piVar7[3];
    piVar12 = (int *)piVar7[1];
    iVar10 = *piVar7;
    *(int *)(iVar9 + 8) = piVar7[2];
    *piVar12 = iVar10;
    iVar5 = piVar7[2];
    iVar10 = piVar7[4];
    *(int **)(*piVar7 + 4) = piVar12;
    *(int *)(iVar5 + 0xc) = iVar9;
    piVar7[2] = (int)piVar7;
    piVar7[3] = (int)piVar7;
    *piVar7 = (int)piVar7;
    piVar7[1] = (int)piVar7;
    param_2[8] = iVar10;
    param_2[9] = piVar7[5];
    *(undefined2 *)(param_2 + 0xb) = *(undefined2 *)(piVar7 + 6);
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      piVar12 = piVar7 + 7;
      iVar5 = param_1 + 0x10000;
      iVar10 = 0;
      do {
        iVar13 = iVar10 + 1;
        param_2[iVar10 + 0xe] = param_2[iVar10 + 0xe] | 3;
        piVar1 = (int *)(iVar5 + -0x777c);
        iVar9 = *piVar12;
        piVar12 = piVar12 + 1;
        puVar11 = (undefined4 *)(iVar5 + -0x7a54);
        iVar5 = iVar5 + 0x2e0;
        (**(code **)(*piVar1 + 0x1ec))(*puVar11,param_2[iVar10],iVar9);
        iVar10 = iVar13;
      } while (iVar13 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
    *(int *)(param_1 + 0x7454) = *(int *)(param_1 + 0x7454) - piVar7[5];
    *(int *)(param_1 + 0x745c) = *(int *)(param_1 + 0x745c) + 1;
    *(int *)(param_1 + 0x7458) = *(int *)(param_1 + 0x7458) + -1;
    iVar10 = *(int *)(param_1 + 0x7464);
    *(int *)(iVar14 + *(int *)(param_1 + 0x7484)) =
         *(int *)(iVar14 + *(int *)(param_1 + 0x7484)) - piVar7[5];
    iVar5 = iVar14 + *(int *)(param_1 + 0x7484);
    *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + -1;
    iVar14 = iVar14 + *(int *)(param_1 + 0x7484);
    *(int *)(iVar14 + 8) = *(int *)(iVar14 + 8) + 1;
    if (iVar10 == 0) {
      *(int **)(param_1 + 0x7464) = piVar7;
    }
    else {
      _gleVecFree(piVar7);
    }
  }
  else {
LAB_000c7884:
    if (piVar7 != (int *)0x0) {
      iVar14 = iVar14 + *(int *)(param_1 + 0x7484);
      *(int *)(iVar14 + 0xc) = *(int *)(iVar14 + 0xc) + 1;
      *(int *)(param_1 + 0x7460) = *(int *)(param_1 + 0x7460) + 1;
    }
  }
  if (0x4000000 < *(int *)(param_1 + 0x7454)) {
    ((int (*)())_gleCleanupOrphans)(param_1);
    return;
  }
  return;
}

/* _gleCleanupOrphans @ 0xc78e8 (300 bytes) */
int _gleCleanupOrphans(param_1)
  int param_1;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  
  piVar7 = *(int **)(param_1 + 0x7470);
  iVar4 = *(int *)(param_1 + 0x7454);
  while (0x4000000 < iVar4) {
    iVar6 = 0;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      piVar5 = piVar7 + 7;
      iVar4 = param_1 + 0x10000;
      do {
        piVar1 = (int *)(iVar4 + -0x777c);
        iVar6 = iVar6 + 1;
        iVar3 = *piVar5;
        piVar5 = piVar5 + 1;
        puVar2 = (undefined4 *)(iVar4 + -0x7a54);
        iVar4 = iVar4 + 0x2e0;
        (**(code **)(*piVar1 + 0x1f8))(*puVar2,iVar3);
      } while (iVar6 < (int)(uint)*(byte *)(param_1 + 0x85a4));
      iVar4 = *(int *)(param_1 + 0x7454);
    }
    iVar6 = piVar7[5];
    *(int *)(param_1 + 0x7458) = *(int *)(param_1 + 0x7458) + -1;
    *(int *)(param_1 + 0x7454) = iVar4 - iVar6;
    iVar4 = ((uint)piVar7[5] >> 0xc & 0x7f) * 0x30;
    *(int *)(iVar4 + *(int *)(param_1 + 0x7484)) =
         *(int *)(iVar4 + *(int *)(param_1 + 0x7484)) - piVar7[5];
    iVar4 = iVar4 + *(int *)(param_1 + 0x7484);
    *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) + -1;
    iVar6 = piVar7[3];
    piVar5 = (int *)piVar7[1];
    iVar4 = *piVar7;
    *(int *)(iVar6 + 8) = piVar7[2];
    *piVar5 = iVar4;
    iVar4 = *piVar7;
    *(int *)(piVar7[2] + 0xc) = iVar6;
    *(int **)(iVar4 + 4) = piVar5;
    piVar7[2] = (int)piVar7;
    piVar7[3] = (int)piVar7;
    *piVar7 = (int)piVar7;
    piVar7[1] = (int)piVar7;
    _gleVecFree(piVar7);
    piVar7 = *(int **)(param_1 + 0x7470);
    iVar4 = *(int *)(param_1 + 0x7454);
  }
  return;
}

/* _gleSynchronizePluginBuffers @ 0xc7a14 (204 bytes) */
int _gleSynchronizePluginBuffers(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x4a60);
  iVar2 = *(int *)(iVar1 + 0x358);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x40) != 0)) {
    ((int (*)())_gleSynchronizePluginBuffer)(param_1,iVar2 + 0x10);
  }
  iVar1 = *(int *)(iVar1 + 0x35c);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x40) != 0)) {
    ((int (*)())_gleSynchronizePluginBuffer)(param_1,iVar1 + 0x10);
  }
  iVar1 = *(int *)(param_1 + 0x4a68);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x40) != 0)) {
    ((int (*)())_gleSynchronizePluginBuffer)(param_1,iVar1 + 0x10);
  }
  iVar1 = *(int *)(param_1 + 0x4a6c);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x40) != 0)) {
    ((int (*)())_gleSynchronizePluginBuffer)(param_1,iVar1 + 0x10);
    return;
  }
  return;
}

/* _gleSynchronizePluginBuffer @ 0xc7ae0 (160 bytes) */
int _gleSynchronizePluginBuffer(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar3 = 0;
  if (*(byte *)(param_1 + 0x85a4) != 0) {
    do {
      iVar3 = uVar2 * 4;
      if (*(int *)(param_2 + 0x30) == *(int *)(iVar3 + *(int *)(param_1 + 0x5148) + 0x8054)) break;
      uVar2 = uVar2 + 1;
      iVar3 = uVar2 * 4;
    } while (uVar2 < *(byte *)(param_1 + 0x85a4));
  }
  iVar1 = uVar2 * 0x2e0 + param_1;
  (**(code **)(*(int *)(iVar1 + 0x8884) + 0x1e4))
            (*(undefined4 *)(iVar1 + 0x85ac),*(undefined4 *)(iVar3 + param_2));
  *(undefined4 *)(param_2 + 0x30) = 0;
  return;
}

/* _gleReclaimBufferObjectResources @ 0xc7b80 (248 bytes) */
int _gleReclaimBufferObjectResources(param_1)
  int param_1;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  
  iVar3 = *(int *)(param_1 + 0x5148);
  piVar6 = (int *)(iVar3 + 0x701c);
  do {
    piVar4 = piVar6 + 1;
    for (piVar6 = (int *)*piVar6; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
      if (piVar6[2] == 1) {
        if (piVar6[0x10] != 0) {
          ((int (*)())_gleSynchronizePluginBuffer)(param_1,piVar6 + 4);
        }
        uVar5 = 0;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          iVar7 = param_1 + 0x10000;
          piVar8 = piVar6;
          do {
            piVar1 = (int *)(iVar7 + -0x777c);
            uVar5 = uVar5 + 1;
            puVar2 = (undefined4 *)(iVar7 + -0x7a54);
            iVar7 = iVar7 + 0x2e0;
            (**(code **)(*piVar1 + 0x1e0))(*puVar2,*(undefined4 *)((int)piVar8 + 0x10));
            *(uint *)((int)piVar8 + 0x48) = *(uint *)((int)piVar8 + 0x48) | 1;
            piVar8 = (int *)((int)piVar8 + 4);
          } while (uVar5 < *(byte *)(param_1 + 0x85a4));
        }
      }
    }
    piVar6 = piVar4;
  } while (piVar4 <= (int *)(iVar3 + 0x8018));
  iVar3 = *(int *)(param_1 + 0x4a60);
  *(undefined4 *)(iVar3 + 0x350) = *(undefined4 *)(iVar3 + 0x350);
  *(uint *)(iVar3 + 0x354) = *(uint *)(iVar3 + 0x354) | 0x10;
  return;
}

/* _OffsetLimitImage3D @ 0xc7c78 (408 bytes) */
int _OffsetLimitImage3D(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  int param_6;
  int param_7;
  int param_8;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar3 = param_1[2];
  iVar8 = *param_1;
  iVar6 = param_1[1];
  iVar4 = param_1[5];
  iVar5 = param_1[3];
  if (param_6 == 0x1a00) {
    if (iVar8 < 1) {
      iVar8 = param_2;
    }
    if (iVar6 < 1) {
      iVar6 = param_3;
    }
    uVar1 = iVar8 + 7;
    uVar2 = ((int)uVar1 >> 3) + (uint)((int)uVar1 < 0 && (uVar1 & 7) != 0);
    uVar1 = uVar2 & iVar4 - 1U;
    if (uVar1 != 0) {
      uVar2 = uVar2 + (iVar4 - uVar1);
    }
    uVar1 = iVar5 + param_2 + 7;
    iVar7 = param_7 + iVar6 * uVar2 * (param_8 + param_4 + -1) + uVar2 * (iVar3 + param_3 + -1) +
            ((int)uVar1 >> 3) + (uint)((int)uVar1 < 0 && (uVar1 & 7) != 0);
  }
  else {
    iVar7 = _glePixelBytes(param_5,param_6);
    if ((((iVar8 == 0 && iVar6 == 0) && iVar5 == 0) && iVar3 == 0) && iVar5 == 0) {
      uVar2 = _gleRowBytes(param_5,param_6,param_2);
      uVar1 = uVar2 & iVar4 - 1U;
      if (uVar1 != 0) {
        uVar2 = uVar2 + (iVar4 - uVar1);
      }
      iVar7 = param_4 * param_3 * uVar2;
    }
    else {
      if (iVar8 < 1) {
        iVar8 = param_2;
      }
      if (iVar6 < 1) {
        iVar6 = param_3;
      }
      uVar2 = _gleRowBytes(param_5,param_6,iVar8);
      uVar1 = uVar2 & iVar4 - 1U;
      if (uVar1 != 0) {
        uVar2 = uVar2 + (iVar4 - uVar1);
      }
      iVar7 = iVar7 * (iVar5 + param_2);
      param_7 = param_7 + iVar6 * uVar2 * (param_8 + param_4 + -1) + uVar2 * (iVar3 + param_3 + -1);
    }
    iVar7 = param_7 + iVar7;
  }
  return iVar7;
}

/* _gleOffsetLimitImage3D @ 0xc7e10 (8 bytes) */
int _gleOffsetLimitImage3D(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  ((int (*)())_OffsetLimitImage3D)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,
                      *(undefined4 *)(param_1 + 0x10));
  return;
}

/* _gleOffsetLimitImage @ 0xc7e18 (28 bytes) */
int _gleOffsetLimitImage(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  ((int (*)())_OffsetLimitImage3D)(param_1,param_2,param_3,1,param_4,param_5,param_6,0);
  return;
}

/* _gleFreeCopyContextData @ 0xc7e38 (104 bytes) */
int _gleFreeCopyContextData(param_1)
  int param_1;
{
  if (*(void **)(param_1 + 8) != (void *)0x0) {
    _free(*(void **)(param_1 + 8));
  }
  if (*(void **)(param_1 + 0xc) != (void *)0x0) {
    _free(*(void **)(param_1 + 0xc));
  }
  if (*(void **)(param_1 + 0x10) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x10));
    return;
  }
  return;
}

/* _gleSwitchToRenderer @ 0xc7ea0 (564 bytes) */
int _gleSwitchToRenderer(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  iVar3 = param_2 * 0x2e0 + param_1;
  uVar1 = *(undefined4 *)(iVar3 + 0x85ac);
  *(int *)(param_1 + 0x468c) = iVar3 + 0x85b0;
  *(undefined4 *)(param_1 + 0x4688) = uVar1;
  puVar7 = (undefined4 *)(param_1 + 0x310);
  _memcpy((void *)(param_1 + 0x4754),(void *)(*(int *)(iVar3 + 0x8884) + 0x114),0xf4);
  (**(code **)(param_1 + 0x4784))
            (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,param_1 + 0x471c);
  *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x3ffffff;
  *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 0xfffffffd;
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x7ffffff;
  *(undefined4 *)(param_1 + 800) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x310) = 0xffffffff;
  uVar5 = (**(code **)(param_1 + 0x4788))(*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,puVar7)
  ;
  iVar3 = 0x13;
  do {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar2 = (uVar5 ^ 8) >> 3 & 1;
  if (uVar2 != *(byte *)(param_1 + 0x759d)) {
    *(char *)(param_1 + 0x759d) = (char)uVar2;
    ((int (*)())_gleUpdateFramebufferOperationFuncs)(param_1);
  }
  if ((uVar5 & 4) == 0) {
    uVar5 = uVar5 & 0xfffffffe;
  }
  if ((param_2 == *(byte *)(param_1 + 0x85a5)) && (*(char *)(param_1 + 0x85a7) != '\x01')) {
    uVar2 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x938) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar2 | *(uint *)(param_1 + 0x4684) & ~uVar2) + 0x938) =
         PTR__glSwap_RevertExec_00112128;
    uVar2 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x168) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar2 | *(uint *)(param_1 + 0x4684) & ~uVar2) + 0x168) =
         PTR__glFlush_RevertExec_00112124;
    uVar6 = *(uint *)(param_1 + 0x4684);
    uVar2 = *(uint *)(param_1 + 0x4680);
    iVar3 = *(int *)(uVar6 + 0x164);
    puVar4 = PTR__glFinish_RevertExec_00112120;
  }
  else {
    uVar2 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x938) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar2 | *(uint *)(param_1 + 0x4684) & ~uVar2) + 0x938) =
         PTR__glSwap_Exec_0011211c;
    uVar2 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x168) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar2 | *(uint *)(param_1 + 0x4684) & ~uVar2) + 0x168) =
         PTR__glFlush_Exec_00112118;
    uVar6 = *(uint *)(param_1 + 0x4684);
    uVar2 = *(uint *)(param_1 + 0x4680);
    iVar3 = *(int *)(uVar6 + 0x164);
    puVar4 = PTR__glFinish_Exec_00112114;
  }
  *(undefined **)((uVar2 & -(uint)(iVar3 == 0) | uVar6 & ~-(uint)(iVar3 == 0)) + 0x164) = puVar4;
  return uVar5;
}

/* _gleRecoverySaveState @ 0xc80d4 (280 bytes) */
int _gleRecoverySaveState(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  *(undefined1 *)(param_2 + 0x12) = *(undefined1 *)(param_1 + 0x3128);
  if (*(char *)(param_2 + 0x12) != '\0') {
    _glDisable_Exec(param_1,0xb71);
  }
  *(undefined1 *)((int)param_2 + 0x4a) = *(undefined1 *)(param_1 + 0x30c6);
  if (*(char *)((int)param_2 + 0x4a) != '\0') {
    _glDisable_Exec(param_1,0xbc0);
  }
  iVar2 = 0;
  if (*(short *)(*(int *)(param_1 + 0x468c) + 0xb4) != 0) {
    iVar4 = param_1 + 0x3530;
    piVar3 = param_2;
    do {
      iVar1 = *(int *)(iVar4 + 4);
      *piVar3 = iVar1;
      piVar3 = piVar3 + 1;
      if (iVar1 != 0) {
        *(undefined4 *)(iVar4 + 4) = 0;
        _gleUpdateTextureParams(param_1,iVar2);
      }
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 0x7c;
    } while (iVar2 < (int)(uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xb4));
  }
  param_2[0x10] = (uint)*(byte *)(param_1 + 0x466c);
  fparam_1 = (double)_glDisable_Exec(param_1,0x8804);
  if (*(int *)(param_1 + 0x5430) == 0) {
    param_2[0x11] = 0;
  }
  else {
    param_2[0x11] = *(int *)(*(int *)(param_1 + 0x5430) + 4);
    ((void (*)())_glUseProgramObjectARB_Exec)(param_1,0,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  }
                    
                    
  (**(code **)(param_1 + 0x4788))
            (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,param_1 + 0x310);
  return;
}

/* _gleRecoveryRestoreState @ 0xc81ec (276 bytes) */
void _gleRecoveryRestoreState(int param_1,int *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  double extraout_f1;
  
  if (*(char *)(param_2 + 0x12) != '\0') {
    fparam_1 = (double)_glEnable_Exec(param_1,0xb71);
  }
  if (*(char *)((int)param_2 + 0x4a) != '\0') {
    fparam_1 = (double)_glEnable_Exec(param_1,0xbc0);
  }
  iVar2 = *(int *)(param_1 + 0x468c);
  iVar3 = 0;
  if (*(short *)(iVar2 + 0xb4) != 0) {
    iVar5 = param_1 + 0x3530;
    piVar4 = param_2;
    do {
      iVar1 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar1 != *(int *)(iVar5 + 4)) {
        *(int *)(iVar5 + 4) = iVar1;
        _gleUpdateTextureParams(param_1,iVar3);
        iVar2 = *(int *)(param_1 + 0x468c);
        fparam_1 = extraout_f1;
      }
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x7c;
    } while (iVar3 < (int)(uint)*(ushort *)(iVar2 + 0xb4));
  }
  if (param_2[0x10] != (uint)*(byte *)(param_1 + 0x466c)) {
    if (param_2[0x10] == 0) {
      fparam_1 = (double)_glDisable_Exec(param_1,0x8804);
    }
    else {
      fparam_1 = (double)_glEnable_Exec(param_1,0x8804);
    }
  }
  if (param_2[0x11] != 0) {
    ((void (*)())_glUseProgramObjectARB_Exec)(param_1,param_2[0x11],fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
               fparam_8);
  }
                    
                    
  (**(code **)(param_1 + 0x4788))
            (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,param_1 + 0x310);
  return;
}

/* _gleToggleScissorEnableState @ 0xc8300 (88 bytes) */
undefined4 _gleToggleScissorEnableState(int param_1,undefined4 param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  *(undefined1 *)(param_1 + 0x34f0) = (undefined1)param_2;
  ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x4000000;
  (**(code **)(param_1 + 0x4788))
            (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,param_1 + 0x310);
  return 0;
}

/* _gleSwitchRenderersReadBuffers @ 0xc8358 (452 bytes) */
int _gleSwitchRenderersReadBuffers(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  undefined1 auStack_90 [80];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_40 = *(undefined4 *)(param_1 + 0x31b0);
  local_3c = *(undefined4 *)(0x31b4 + param_1);
  local_38 = *(undefined4 *)(param_1 + 0x31b8);
  local_34 = *(undefined4 *)(param_1 + 0x31bc);
  local_30 = *(undefined4 *)(param_1 + 0x31c0);
  local_2c = *(undefined4 *)(param_1 + 0x31c4);
  local_28 = *(undefined4 *)(param_1 + 0x31c8);
  if (*(char *)(param_1 + 0x759d) != '\0') {
    *(undefined4 *)(param_1 + 0x31c4) = 1;
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x200000;
    *(undefined4 *)(param_1 + 0x31b0) = 0;
    *(undefined4 *)(0x31b4 + param_1) = 0;
    *(undefined4 *)(param_1 + 0x31b8) = 0;
    *(undefined4 *)(param_1 + 0x31bc) = 0;
    *(undefined4 *)(param_1 + 0x31c0) = 0;
    *(undefined1 *)(param_1 + 0x31c8) = 0;
    *(undefined1 *)(param_1 + 0x31c9) = 0;
    *(undefined1 *)(param_1 + 0x31ca) = 0;
    ((int (*)())_gleRecoverySaveState)(param_1,auStack_90);
    iVar3 = *(int *)(param_1 + 0x1ba8);
    param_3[1] = iVar3;
    iVar1 = *(int *)(param_1 + 0x1bac);
    *param_3 = iVar1;
    pvVar4 = _malloc(iVar3 * iVar1 * 4);
    param_3[2] = (int)pvVar4;
    fparam_1 = (double)(**(double ( **)(int,int,int,int,int,int,int,int))(param_1 + 0x46a0))
                                 (*(undefined4 *)(param_1 + 0x4688), 0, 0, param_3[1], *param_3, 0x80e1, 0x8367, pvVar4);
    if (*(int *)(param_2 * 0x2e0 + param_1 + 0x85ec) != 0) {
      pvVar4 = _malloc(param_3[1] * *param_3 * 4);
      param_3[4] = (int)pvVar4;
      fparam_1 = (double)(**(double ( **)(int,int,int,int,int,int,int,int))(param_1 + 0x46a0))
                                   (*(undefined4 *)(param_1 + 0x4688), 0, 0, param_3[1], *param_3, 0x1902, 0x1406, pvVar4);
    }
    uVar2 = *(uint *)(param_1 + 0x310);
    *(undefined4 *)(0x31b4 + param_1) = local_3c;
    *(undefined4 *)(param_1 + 0x31b0) = local_40;
    *(undefined4 *)(param_1 + 0x31b8) = local_38;
    *(undefined4 *)(param_1 + 0x31bc) = local_34;
    *(undefined4 *)(param_1 + 0x31c0) = local_30;
    *(undefined4 *)(param_1 + 0x31c4) = local_2c;
    *(undefined4 *)(param_1 + 0x31c8) = local_28;
    *(uint *)(param_1 + 0x310) = uVar2 | 0x200000;
    ((void (*)())_gleRecoveryRestoreState)(param_1,auStack_90,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  }
  return;
}

/* _gleSwitchRenderersWriteBuffers @ 0xc851c (616 bytes) */
int _gleSwitchRenderersWriteBuffers(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  bool bVar1;
  ushort uVar2;
  double dVar3;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  float local_1a0;
  float local_19c;
  float local_198;
  undefined1 auStack_a0 [80];
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  
  local_50 = *(undefined4 *)(param_1 + 0x31cc);
  local_4c = *(undefined4 *)(param_1 + 0x31d0);
  local_48 = *(undefined4 *)(param_1 + 0x31d4);
  local_44 = *(undefined4 *)(param_1 + 0x31d8);
  local_40 = *(undefined4 *)(param_1 + 0x31dc);
  local_3c = *(undefined4 *)(param_1 + 0x31e0);
  local_38 = *(undefined4 *)(param_1 + 0x31e4);
  if (*(char *)(param_1 + 0x759d) != '\0') {
    bVar1 = *(char *)(param_1 + 0x34f0) != '\0';
    *(undefined4 *)(param_1 + 0x31e0) = 1;
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x200000;
    *(undefined4 *)(param_1 + 0x31cc) = 0;
    *(undefined4 *)(param_1 + 0x31d0) = 0;
    *(undefined4 *)(param_1 + 0x31d4) = 0;
    *(undefined4 *)(param_1 + 0x31d8) = 0;
    *(undefined4 *)(param_1 + 0x31dc) = 0;
    *(undefined1 *)(param_1 + 0x31e4) = 0;
    *(undefined1 *)(param_1 + 0x31e5) = 0;
    *(undefined1 *)(param_1 + 0x31e6) = 0;
    dVar3 = (double)((int (*)())_gleRecoverySaveState)(param_1,auStack_a0);
    if (bVar1) {
      ((undefined4 (*)())_gleToggleScissorEnableState)(param_1,0,dVar3,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
    }
    _memset(&local_1a0,0,0x100);
    local_1a0 = *(float *)(param_1 + 0x4a44) * local_1a0 + *(float *)(param_1 + 0x4a48);
    dVar3 = (double)*(float *)(param_1 + 0x4a50);
    local_19c = (float)((double)*(float *)(param_1 + 0x4a4c) * (double)local_19c + dVar3);
    local_198 = *(float *)(param_1 + 0x4a54) * local_198;
    if (param_3[4] != 0) {
      uVar2 = *(ushort *)(param_1 + 0x3124);
      _glEnable_Exec(param_1,0xb71);
      _glDepthFunc_Exec(param_1,0x207);
      (**(code **)(param_1 + 0x4788))
                (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,param_1 + 0x310);
      (**(code **)(param_1 + 0x46a4))
                (*(undefined4 *)(param_1 + 0x4688),&local_1a0,param_3[1],*param_3,0x1902,0x1406,
                 param_3[4],0);
      _glDisable_Exec(param_1,0xb71);
      _glDepthFunc_Exec(param_1,(uint)uVar2);
      (**(code **)(param_1 + 0x4788))
                (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,param_1 + 0x310);
    }
    fparam_1 = (double)(**(double ( **)(int,int,int,int,int,int,int,int))(param_1 + 0x46a4))
                                 (*(undefined4 *)(param_1 + 0x4688), &local_1a0, param_3[1], *param_3, 0x80e1, 0x8367, param_3[2], 0);
    if (bVar1) {
      fparam_1 = (double)((undefined4 (*)())_gleToggleScissorEnableState)(param_1,1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,dVar3);
    }
    *(undefined4 *)(param_1 + 0x31d0) = local_4c;
    *(undefined4 *)(param_1 + 0x31cc) = local_50;
    *(undefined4 *)(param_1 + 0x31d4) = local_48;
    *(undefined4 *)(param_1 + 0x31d8) = local_44;
    *(undefined4 *)(param_1 + 0x31dc) = local_40;
    *(undefined4 *)(param_1 + 0x31e0) = local_3c;
    *(undefined4 *)(param_1 + 0x31e4) = local_38;
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x200000;
    ((void (*)())_gleRecoveryRestoreState)(param_1,auStack_a0,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,dVar3);
  }
  return;
}

/* _gleRevertSwapToPrimary @ 0xc8784 (172 bytes) */
int _gleRevertSwapToPrimary(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  uVar3 = (uint)*(byte *)(param_1 + 0x85a6);
  local_20 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  ((int (*)())_gleSwitchRenderersReadBuffers)(param_1,(uint)*(byte *)(param_1 + 0x85a5),&local_30);
  iVar1 = uVar3 * 0x2e0 + param_1;
  (**(code **)(*(int *)(iVar1 + 0x8884) + 0x138))
            (*(undefined4 *)(iVar1 + 0x85ac),*(undefined4 *)(param_1 + 0x484c),
             *(undefined4 *)(param_1 + 0x4848),0);
  fparam_1 = (double)((int (*)())_gleSwitchToRenderer)(param_1,uVar3);
  ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  ((int (*)())_gleSwitchRenderersWriteBuffers)(param_1,uVar3,&local_30);
  uVar2 = ((int (*)())_gleFreeCopyContextData)(&local_30);
  return uVar2;
}

/* _gleGetMapData @ 0xc8830 (88 bytes) */
int _gleGetMapData(param_1)
  int param_1;
{
  int iVar1;
  void *pvVar2;
  
  iVar1 = *(int *)(param_1 + 0x7450);
  if (iVar1 == 0) {
    pvVar2 = _malloc(0x9dcc);
    *(void **)(param_1 + 0x7450) = pvVar2;
    _gleInitMap1Data(param_1);
    _gleInitMap2Data(param_1);
    iVar1 = *(int *)(param_1 + 0x7450);
  }
  return iVar1;
}

/* _gleReclaimContextResources @ 0xc8888 (276 bytes) */
int _gleReclaimContextResources(param_1)
  int param_1;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  
  if (*(int *)(param_1 + 0x7484) != 0) {
    _gleFreeOrphans(param_1);
  }
  _gleReclaimDrawPixelResources(param_1);
  if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
    _pthread_mutex_lock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
  }
  ((int (*)())_gleReclaimDisplayListResources)(param_1);
  _gleReclaimTextureObjectResources(param_1);
  ((int (*)())_gleReclaimBufferObjectResources)(param_1);
  _gleReclaimVertexArrayResources(param_1);
  if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
    _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
  }
  iVar3 = param_1 + 0x10000;
  uVar4 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      uVar4 = uVar4 + 1;
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      iVar3 = iVar3 + 0x2e0;
      (**(code **)(*piVar1 + 0x134))(*puVar2);
    } while (uVar4 < *(byte *)(param_1 + 0x85a4));
  }
  *(undefined4 *)(param_1 + 800) = 0xffffffff;
  *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x3ffffff;
  *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 0xfffffffd;
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x7ffffff;
  *(undefined4 *)(param_1 + 0x310) = 0xffffffff;
  return;
}

/* _gleSwitchToNonRevertRenderer @ 0xc899c (516 bytes) */
int _gleSwitchToNonRevertRenderer(param_1)
  int param_1;
{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  double fparam_1;
  double fparam_1_00;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff88;
  double in_stack_ffffff90;
  double in_stack_ffffff98;
  double in_stack_ffffffa0;
  double in_stack_ffffffa8;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  bVar1 = *(byte *)(param_1 + 0x85a6);
  uVar6 = (uint)bVar1;
  iVar3 = uVar6 * 0x2e0 + param_1;
  uVar4 = (**(code **)(*(int *)(iVar3 + 0x8884) + 0x138))
                    (*(undefined4 *)(iVar3 + 0x85ac),*(undefined4 *)(param_1 + 0x484c),
                     *(undefined4 *)(param_1 + 0x4848),0);
  if (uVar4 < 5) {
    _gleSynchronizePluginFramebuffer(param_1);
    _gleSynchronizePluginTextures(param_1);
    ((int (*)())_gleSynchronizePluginBuffers)(param_1);
    uVar4 = ((int (*)())_gleSwitchToRenderer)(param_1,uVar6);
    if ((uVar4 & 4) == 0) {
      bVar1 = *(byte *)(param_1 + 0x85a5);
      iVar3 = (uint)bVar1 * 0x2e0 + param_1;
      (**(code **)(*(int *)(iVar3 + 0x8884) + 0x138))
                (*(undefined4 *)(iVar3 + 0x85ac),*(undefined4 *)(param_1 + 0x484c),
                 *(undefined4 *)(param_1 + 0x4848),0);
      ((int (*)())_gleSwitchToRenderer)(param_1,(uint)bVar1);
    }
    else {
      ((int (*)())_gleSwitchToRenderer)(param_1,(uint)*(byte *)(param_1 + 0x85a5));
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      ((int (*)())_gleSwitchRenderersReadBuffers)(param_1,(uint)*(byte *)(param_1 + 0x85a5),&local_40);
      fparam_1 = (double)((int (*)())_gleSwitchToRenderer)(param_1,uVar6);
      *(byte *)(param_1 + 0x85a8) = bVar1;
      ((void (*)())_gleUpdateDepthRangeData)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff88,
                 in_stack_ffffff90,in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8);
      _gleUpdatePolyMode(param_1);
      ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1_00,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
      _gleUpdateTextureTransform(param_1);
      puVar2 = PTR__gleSetClipInterpFunc_00112038;
      *(undefined **)(param_1 + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
      *(undefined **)(param_1 + 0x49cc) = puVar2;
      _gleSetColorMaterialEnable(param_1);
      *(undefined4 *)(param_1 + 0x48d0) = 0;
      *(undefined4 *)(param_1 + 0x48d4) = 0;
      _gleUpdatePrimitiveData(param_1);
      _gleUpdateDrawArraysFuncs(param_1);
      _gleSelectVertexSubmitFunc(param_1);
      *(undefined4 *)(param_1 + 0x488c) = 0;
      *(undefined4 *)(param_1 + 0x4890) = 0;
      *(undefined4 *)(param_1 + 0x4894) = 0;
      ((int (*)())_gleSwitchRenderersWriteBuffers)(param_1,uVar6,&local_40);
      ((int (*)())_gleFreeCopyContextData)(&local_40);
    }
    bVar1 = (byte)uVar4;
    *(uint *)(param_1 + 0x757c) = uVar4;
    *(char *)(param_1 + 0x7581) = (char)(uVar4 & 4);
  }
  else {
    if (uVar4 != 0x2720) {
      return;
    }
    bVar1 = *(byte *)(param_1 + 0x85a5);
    iVar3 = (uint)bVar1 * 0x2e0 + param_1;
    (**(code **)(*(int *)(iVar3 + 0x8884) + 0x138))
              (*(undefined4 *)(iVar3 + 0x85ac),*(undefined4 *)(param_1 + 0x484c),
               *(undefined4 *)(param_1 + 0x4848),1);
    uVar5 = ((int (*)())_gleSwitchToRenderer)(param_1,(uint)bVar1);
    bVar1 = (byte)uVar5;
    *(undefined4 *)(param_1 + 0x757c) = uVar5;
  }
  *(byte *)(param_1 + 0x7580) = bVar1 & 1;
  return;
}

/* _gleUpdateDispatchCodeChange @ 0xc8ba0 (528 bytes) */
int _gleUpdateDispatchCodeChange(param_1, param_2)
  int param_1;
  uint param_2;
{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  double fparam_1;
  double fparam_1_00;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff88;
  double in_stack_ffffff90;
  double in_stack_ffffff98;
  double in_stack_ffffffa0;
  double in_stack_ffffffa8;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  
  if ((param_2 & 4) != (uint)*(byte *)(param_1 + 0x7581)) {
    *(char *)(param_1 + 0x7581) = (char)(param_2 & 4);
    uVar4 = (uint)*(byte *)(param_1 + 0x7581);
    if (uVar4 == 0) {
      bVar1 = *(byte *)(param_1 + 0x85a5);
      uVar6 = (uint)bVar1;
      if (uVar6 != 0xff) {
        local_40 = uVar4;
        local_3c = uVar4;
        local_38 = uVar4;
        local_34 = uVar4;
        local_30 = uVar4;
        ((int (*)())_gleSwitchRenderersReadBuffers)(param_1,(uint)*(byte *)(param_1 + 0x85a6),&local_40);
        iVar5 = uVar6 * 0x2e0 + param_1;
        uVar4 = (**(code **)(*(int *)(iVar5 + 0x8884) + 0x138))
                          (*(undefined4 *)(iVar5 + 0x85ac),*(undefined4 *)(param_1 + 0x484c),
                           *(undefined4 *)(param_1 + 0x4848),0);
        if ((uVar4 < 5) && (uVar6 != *(byte *)(param_1 + 0x85a8))) {
          _gleSynchronizePluginTextures(param_1);
          ((int (*)())_gleSynchronizePluginBuffers)(param_1);
          *(byte *)(param_1 + 0x85a8) = bVar1;
          fparam_1 = (double)((int (*)())_gleSwitchToRenderer)(param_1,(uint)*(byte *)(param_1 + 0x85a5));
          ((void (*)())_gleUpdateDepthRangeData)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff88,
                     in_stack_ffffff90,in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8);
          _gleUpdatePolyMode(param_1);
          ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1_00,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
          _gleUpdateTextureTransform(param_1);
          puVar3 = PTR__gleSetEyeInterpFunc_0011203c;
          puVar2 = PTR__gleSetClipInterpFunc_00112038;
          *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x3ffffff;
          *(undefined **)(param_1 + 0x49c8) = puVar3;
          *(undefined **)(param_1 + 0x49cc) = puVar2;
          *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 0xfffffffd;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x7ffffff;
          *(undefined4 *)(param_1 + 800) = 0xffffffff;
          *(undefined4 *)(param_1 + 0x310) = 0xffffffff;
          uVar4 = (**(code **)(param_1 + 0x4788))
                            (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,param_1 + 0x310);
          if ((uVar4 & 8) == 0) {
            ((int (*)())_gleSwitchRenderersWriteBuffers)(param_1,(uint)*(byte *)(param_1 + 0x85a5),&local_40);
          }
          param_2 = 0;
        }
        ((int (*)())_gleFreeCopyContextData)(&local_40);
      }
    }
  }
  if ((param_2 & 3) != (uint)*(byte *)(param_1 + 0x7580)) {
    *(byte *)(param_1 + 0x7580) = (byte)param_2 & 1;
    _gleSetColorMaterialEnable(param_1);
    *(undefined4 *)(param_1 + 0x48d0) = *(undefined4 *)(*(int *)(param_1 + 0x468c) + 0x11c);
    *(undefined4 *)(param_1 + 0x48d4) = *(undefined4 *)(*(int *)(param_1 + 0x468c) + 0x120);
    _gleUpdatePrimitiveData(param_1);
    _gleUpdateDrawArraysFuncs(param_1);
    _gleSelectVertexSubmitFunc(param_1);
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
    *(undefined4 *)(param_1 + 0x4894) = 0;
  }
  uVar4 = (param_2 ^ 8) >> 3 & 1;
  if (uVar4 != *(byte *)(param_1 + 0x759d)) {
    *(char *)(param_1 + 0x759d) = (char)uVar4;
    ((int (*)())_gleUpdateFramebufferOperationFuncs)(param_1);
  }
  return;
}

/* _gleUpdateFramebufferOperationFuncs @ 0xc8db0 (928 bytes) */
int _gleUpdateFramebufferOperationFuncs(param_1)
  int param_1;
{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  
  if (*(int *)(param_1 + 0x5408) == 0) {
    if (*(char *)(param_1 + 0x759d) == '\0') {
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x28) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x28) =
           PTR__glClear_NoopExec_001120c0;
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xd0) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xd0) =
           PTR__glCopyPixels_NoopExec_001120bc;
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xd4) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xd4) =
           PTR__glCopyTexImage1D_NoopExec_001120b8;
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xd8) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xd8) =
           PTR__glCopyTexImage2D_NoopExec_001120b4;
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xdc) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xdc) =
           PTR__glCopyTexSubImage1D_NoopExec_001120b0;
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xe0) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xe0) =
           PTR__glCopyTexSubImage2D_NoopExec_001120ac;
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6e0) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x6e0) =
           PTR__glCopyTexSubImage3D_NoopExec_001120a8;
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x110) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x110) =
           PTR__glDrawPixels_NoopExec_001120a4;
      uVar4 = *(uint *)(param_1 + 0x4684);
      uVar3 = *(uint *)(param_1 + 0x4680);
      iVar1 = *(int *)(uVar4 + 0x18);
      puVar2 = PTR__glBitmap_NoopExec_001120a0;
    }
    else {
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x28) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x28) =
           PTR__glClear_Exec_0011209c;
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xd0) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xd0) =
           PTR__glCopyPixels_Exec_00112098;
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xd4) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xd4) =
           PTR__glCopyTexImage1D_Exec_00112094;
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xd8) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xd8) =
           PTR__glCopyTexImage2D_Exec_00112090;
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xdc) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xdc) =
           PTR__glCopyTexSubImage1D_Exec_0011208c;
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xe0) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xe0) =
           PTR__glCopyTexSubImage2D_Exec_00112088;
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x6e0) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x6e0) =
           PTR__glCopyTexSubImage3D_Exec_00112084;
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x110) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x110) =
           PTR__glDrawPixels_Exec_00112080;
      uVar4 = *(uint *)(param_1 + 0x4684);
      uVar3 = *(uint *)(param_1 + 0x4680);
      iVar1 = *(int *)(uVar4 + 0x18);
      puVar2 = PTR__glBitmap_Exec_0011207c;
    }
    *(undefined **)((uVar3 & -(uint)(iVar1 == 0) | uVar4 & ~-(uint)(iVar1 == 0)) + 0x18) = puVar2;
    if ((*(char *)(param_1 + 0x759c) == '\0') || (*(char *)(param_1 + 0x759d) == '\0')) {
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x10) == 0);
      uVar3 = *(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3;
      puVar2 = PTR__glBegin_NoopExec_00112078;
    }
    else {
      uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x10) == 0);
      uVar3 = *(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3;
      puVar2 = PTR__glBegin_Exec_00112074;
    }
    *(undefined **)(uVar3 + 0x10) = puVar2;
  }
  _gleUpdateDrawArraysFuncs(param_1);
  return;
}

/* _gleReclaimDisplayListResources @ 0xc9150 (4 bytes) */
int _gleReclaimDisplayListResources()
{
  return;
}

/* _gleQuickOptimizeDisplayList @ 0xc9154 (1292 bytes) */
int _gleQuickOptimizeDisplayList(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  void *pvVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  void *local_60;
  int local_5c [4];
  
  uVar12 = *(uint *)(param_3 + 0x10);
  puVar15 = (undefined4 *)(param_3 + 0x2c);
  piVar8 = *(int **)(param_3 + 0x14);
  uVar14 = 0;
  piVar2 = piVar8;
  puVar16 = puVar15;
  if (uVar12 == 0) {
    return;
  }
  while( true ) {
    puVar1 = (undefined *)*puVar16;
    iVar4 = 0;
    iVar10 = *(int *)(((uint)puVar1 & 0x7c) + _gleDisplayListFunctionHash);
    while ((iVar10 != 0 && (iVar4 = iVar10, puVar1 != *(undefined **)(iVar10 + 4)))) {
      iVar4 = *(int *)(iVar10 + 0xc);
      iVar10 = iVar4;
    }
    if ((puVar1 == PTR__glDrawArraysOrElements_ListExec_00112144) && (0x20 < (int)puVar16[7]))
    break;
    if ((iVar4 == 0) || (*(undefined **)(iVar4 + 4) != PTR__glWeightARB_ListExec_0011214c)) {
      puVar16 = (undefined4 *)((int)puVar16 + *piVar2);
    }
    else {
      puVar16 = puVar16 + puVar16[1] + 2;
    }
    uVar14 = uVar14 + 1;
    piVar2 = piVar2 + 1;
    if (uVar12 <= uVar14) {
      return;
    }
  }
  pvVar6 = (void *)0x0;
  iVar4 = 0;
  _gleNewList(param_1,param_2,((unsigned char *)0x00001300U));
  puVar1 = PTR__glWeightARB_ListExec_0011214c;
  local_5c[0] = 0;
  local_60 = (void *)0x0;
  uVar14 = 0;
  if (uVar12 != 0) {
    iVar10 = 0;
    do {
      puVar3 = (undefined *)*puVar15;
      iVar11 = 0;
      iVar5 = *(int *)(((uint)puVar3 & 0x7c) + _gleDisplayListFunctionHash);
      while ((iVar5 != 0 && (iVar11 = iVar5, puVar3 != *(undefined **)(iVar5 + 4)))) {
        iVar11 = *(int *)(iVar5 + 0xc);
        iVar5 = iVar11;
      }
      if (puVar3 == PTR__glDrawArraysOrElements_ListExec_00112144) {
        iVar5 = 0x2c;
        iVar9 = puVar15[7] * puVar15[8];
        if (local_5c[0] < (int)(iVar9 + 0x2cU)) {
          iVar5 = 0x40;
          if (local_60 != (void *)0x0) {
            _CloseCurrentVAR(param_1,iVar4,pvVar6,&local_60,local_5c);
          }
          piVar2 = (int *)_gleAddListItemWithFree
                                    (param_1,
                                     PTR__gleSetupAndDrawArraysOrElementsOutOfLine_ListExec_00112140
                                     ,0x10,PTR__gleOptimizedListFreeFunc_00110ccc,4);
          local_5c[0] = iVar9 + 0x40;
          iVar4 = (int)piVar2 - *(int *)(param_1 + 0x53e8);
          if (local_5c[0] < 0x100001) {
            local_5c[0] = 0x100000;
            uVar13 = 0x100000;
          }
          else {
            uVar13 = (uint)(((unsigned char *)0x0000103f) + iVar9) & 0xfffff000;
          }
          _vm_allocate(*(unsigned char *)PTR_00112034,(unsigned char *)&local_60,uVar13,1);
          *piVar2 = (int)local_60;
          *(uint *)((int)local_60 + 0xc) = uVar13;
          *(undefined4 *)*piVar2 = 4;
          *(uint *)*piVar2 = *(uint *)*piVar2 | 2;
          pvVar6 = (void *)(*piVar2 + 0x14);
          pvVar7 = local_60;
        }
        else {
          piVar2 = (int *)_gleAddListItem(param_1,
                                          PTR__gleDrawArraysOrElementsOutOfLine_ListExec_0011213c,8)
          ;
          *piVar2 = (int)piVar2 + (-iVar4 - *(int *)(param_1 + 0x53e8));
          piVar2[1] = (int)pvVar6 - (int)local_60;
          pvVar7 = pvVar6;
        }
        local_5c[0] = local_5c[0] - (iVar9 + iVar5);
        pvVar7 = (void *)((int)pvVar7 + iVar9 + iVar5);
        _memcpy(pvVar6,puVar15 + 6,iVar9 + 0x2cU);
        pvVar6 = pvVar7;
        if ((iVar11 == 0) || (*(undefined **)(iVar11 + 4) != puVar1)) {
          iVar11 = *(int *)(iVar10 + (int)piVar8);
          goto LAB_000c9558;
        }
LAB_000c9540:
        puVar15 = puVar15 + puVar15[1] + 2;
      }
      else {
        if (((puVar3 == PTR__glCallList_ListExec_00112138) ||
            (puVar3 == PTR__glBindVertexArrayEXT_ListExec_00112134)) ||
           (puVar3 == PTR__glVertexArrayParameteriEXT_ListExec_00112130)) {
          if (local_60 != (void *)0x0) {
            _CloseCurrentVAR(param_1,iVar4,pvVar6,&local_60,local_5c);
            puVar3 = (undefined *)*puVar15;
          }
          uVar13 = *(int *)(iVar10 + (int)piVar8) - 4;
          iVar9 = _gleAddListItem(param_1,puVar3,uVar13);
          iVar5 = 0;
          for (uVar13 = uVar13 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
            *(undefined4 *)(iVar9 + iVar5 * 4) = puVar15[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
        }
        else {
          uVar13 = *(int *)(iVar10 + (int)piVar8) - 4;
          iVar9 = _gleAddListItem(param_1,puVar3,uVar13);
          iVar5 = 0;
          for (uVar13 = uVar13 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
            *(undefined4 *)(iVar9 + iVar5 * 4) = puVar15[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
        }
        if ((iVar11 != 0) && (*(undefined **)(iVar11 + 4) == puVar1)) goto LAB_000c9540;
        iVar11 = *(int *)(iVar10 + (int)piVar8);
LAB_000c9558:
        puVar15 = (undefined4 *)((int)puVar15 + iVar11);
      }
      uVar14 = uVar14 + 1;
      iVar10 = iVar10 + 4;
    } while (uVar14 < uVar12);
  }
  if (local_60 != (void *)0x0) {
    _CloseCurrentVAR(param_1,iVar4,pvVar6,&local_60,local_5c);
  }
  iVar4 = *(int *)(param_1 + 0x5148);
  *(undefined4 *)(param_1 + 0x5408) = 0;
  iVar10 = iVar4 + 0x300c;
  if (*(char *)(iVar4 + 0x8024) != '\0') {
    _pthread_mutex_lock((pthread_mutex_t *)(iVar4 + 0x8028));
  }
  iVar11 = *(int *)(param_1 + 0x53e8);
  iVar4 = _gleIsHashName(iVar10,*(undefined4 *)(iVar11 + 4));
  if (iVar4 == 0) {
    _gleAddHashNameAndObject(param_1,iVar10,iVar11);
  }
  else {
    pvVar6 = (void *)_gleRemoveHashObject(iVar10,*(undefined4 *)(iVar11 + 4));
    if ((pvVar6 != (void *)0x0) &&
       (iVar4 = *(int *)((int)pvVar6 + 8) + -1, *(int *)((int)pvVar6 + 8) = iVar4, iVar4 == 0)) {
      if (*(void **)((int)pvVar6 + 0x14) != (void *)0x0) {
        _free(*(void **)((int)pvVar6 + 0x14));
      }
      _free(pvVar6);
    }
    _gleAddHashObject(iVar10,iVar11);
  }
  if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
    _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
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
int _gleDrawPixelsFastLoadColorTables(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = _gleLookUpColorTable(param_1,0x80d0);
  if ((iVar1 != 0) && (iVar1 != -0xac)) {
    *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(iVar1 + 0xc0);
    *(uint *)(param_2 + 0x3c) = (uint)*(ushort *)(iVar1 + 0xbc);
    *(uint *)(param_2 + 0x40) = (uint)*(ushort *)(iVar1 + 0xbe);
    *(uint *)(param_2 + 0x44) = (uint)*(ushort *)(iVar1 + 0xb0);
  }
  iVar1 = _gleLookUpColorTable(param_1,0x80d2);
  if ((iVar1 != 0) && (iVar1 != -0xac)) {
    *(undefined4 *)(param_2 + 0x58) = *(undefined4 *)(iVar1 + 0xc0);
    *(uint *)(param_2 + 0x4c) = (uint)*(ushort *)(iVar1 + 0xbc);
    *(uint *)(param_2 + 0x50) = (uint)*(ushort *)(iVar1 + 0xbe);
    *(uint *)(param_2 + 0x54) = (uint)*(ushort *)(iVar1 + 0xb0);
  }
  iVar1 = _gleLookUpColorTable(param_1,0x80d1);
  if ((iVar1 != 0) && (iVar1 != -0xac)) {
    *(undefined4 *)(param_2 + 0x68) = *(undefined4 *)(iVar1 + 0xc0);
    *(uint *)(param_2 + 0x5c) = (uint)*(ushort *)(iVar1 + 0xbc);
    *(uint *)(param_2 + 0x60) = (uint)*(ushort *)(iVar1 + 0xbe);
    *(uint *)(param_2 + 100) = (uint)*(ushort *)(iVar1 + 0xb0);
  }
  return;
}

/* _CopySourceSubImageToTexture @ 0xc97a4 (568 bytes) */
void _CopySourceSubImageToTexture(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16,undefined4 param_17,undefined4 param_18,undefined4 param_19,undefined4 param_20,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  int local_e0;
  int local_dc;
  undefined1 auStack_d8 [4];
  undefined1 auStack_d4 [12];
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
  
  _glePixelPackSettings
            (param_1,param_4,param_5,param_2,param_3,(*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x60)),&local_60,local_5c,&local_70,
             auStack_6c,auStack_68,auStack_64);
  local_dc = local_70;
  local_e0 = (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x48)) * local_60 + (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x4c)) * local_70 + param_6 + local_5c[0];
  _glgConvertType(param_4,param_5,auStack_d8,auStack_d4);
  _glgConvertType((*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c)),(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)),auStack_c8,auStack_c4);
  dVar3 = (double)*(float *)(param_1 + 0x31ac);
  local_c0 = 2;
  local_bc = 0;
  if ((dVar3 <= DOUBLE_00108dc8) || (DOUBLE_00108d68 <= dVar3)) {
    local_b8 = 0x6efff;
  }
  else {
    local_b8 = 0x6ffff;
  }
  if ((*(char *)(*(unsigned int *)__builtin_frame_address(0) + 0x67)) != '\0') {
    local_b8 = local_b8 | 0x10000;
    ((int (*)())_gleDrawPixelsFastLoadColorTables)(param_1,&local_e0);
    dVar3 = (double)*(float *)(param_1 + 0x31ac);
  }
  local_ac = (float)fparam_1;
  local_74 = 1;
  local_a8 = (float)fparam_2;
  if ((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x60)) != 0) {
    if (*(char *)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x60)) + 0x18) != '\0') {
      local_bc = local_bc | 1;
    }
    if (*(char *)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x60)) + 0x19) != '\0') {
      local_bc = local_bc | 4;
    }
  }
  dVar2 = (double)FLOAT_00108e50;
  uVar1 = *(undefined4 *)(param_1 + 0x31a8);
  *(undefined4 *)(param_1 + 0x31a8) = 0x3f800000;
  if (dVar2 <= dVar3) {
    local_50 = 0x3f800000;
    if (1.0 < dVar3) goto LAB_000c99b8;
  }
  else if (dVar3 < (double)FLOAT_00108e58) goto LAB_000c99b8;
  if ((double)FLOAT_00108e50 <= dVar3) {
    fparam_4 = (double)(float)(fparam_4 * dVar3);
  }
  else {
    fparam_4 = (double)(float)(fparam_4 * -dVar3);
  }
LAB_000c99b8:
  *(float *)(param_1 + 0x31ac) = (float)fparam_4;
  local_b4 = param_7;
  local_b0 = param_8;
  _glgProcessPixels(param_1 + 0x31a8,&local_e0);
  *(float *)(param_1 + 0x31ac) = (float)dVar3;
  *(undefined4 *)(param_1 + 0x31a8) = uVar1;
  FUN_00008b68();
  return;
}

/* _gleInitDrawPixelsShareObject @ 0xc99dc (1036 bytes) */
int _gleInitDrawPixelsShareObject(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  bool bVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int *piVar14;
  double extraout_f1;
  double extraout_f1_00;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  uVar2 = *(undefined1 *)(param_1 + 0x31e6);
  *param_2 = 0;
  param_2[3] = 0x40000;
  param_2[2] = 2;
  param_2[1] = 0x100000;
  param_2[4] = 0x8035;
  puVar8 = (undefined4 *)_gleVecAlloc(8);
  param_2[6] = puVar8;
  uVar9 = _gleVecAlloc(param_2[2] * 0xa9c);
  *puVar8 = uVar9;
  uVar5 = 0;
  if (param_2[2] != 0) {
    iVar11 = 0;
    uVar10 = 0;
    do {
      uVar13 = uVar10 + 1;
      iVar4 = *(int *)param_2[6] + iVar11;
      iVar11 = iVar11 + 0xa9c;
      ((int *)param_2[6])[uVar10] = iVar4;
      uVar5 = param_2[2];
      uVar10 = uVar13;
    } while (uVar13 < uVar5);
  }
  param_2[5] = uVar5 * param_2[1];
  uVar9 = _gleVecAlloc(uVar5 * param_2[1]);
  param_2[7] = uVar9;
  *(undefined1 *)(param_1 + 0x31e6) = 1;
  uVar5 = *(uint *)(param_1 + 0x314) | 1;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x200000;
  *(uint *)(param_1 + 0x314) = uVar5;
  fparam_1 = extraout_f1;
  if (*(int *)(param_1 + 0x50ac) != 0 ||
      (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1_00;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_000c9cc0;
  iVar11 = *(int *)(param_1 + 0x744c);
  piVar14 = (int *)(param_1 + 0x310);
  cVar3 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar11 != 0) && (*(int *)(iVar11 + 0xec) != 0)) {
    ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar11 + 0x10,in_r5,in_r6,in_r7,in_r8,uVar5,fparam_1,in_f2,in_f3,in_f4,in_f5,
               in_f6,in_f7,in_f8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000c9bb8:
    uVar10 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar11 = 0;
    piVar6 = (int *)(param_1 + 0x324);
    do {
      iVar4 = *piVar6;
      piVar6 = piVar6 + 1;
      if (iVar4 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < 9);
    uVar10 = *(uint *)(param_1 + 0x31c);
    if ((uVar10 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_000c9bb8;
    }
  }
  bVar1 = cVar3 == '\0';
  if (bVar1) {
    uVar10 = uVar10 & 0x17000000;
  }
  else {
    uVar10 = uVar10 & 0x17ffffff;
  }
  uVar5 = *(uint *)(param_1 + 800);
  if (bVar1) {
    bVar1 = ((*piVar14 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar10 == 0) && uVar5 == 0;
  }
  else {
    bVar1 = (((*piVar14 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar10 == 0) && uVar5 == 0;
  }
  if (!bVar1) {
    uVar5 = (uint)*(byte *)(param_1 + 0x85a6);
    if (*(byte *)(param_1 + 0x85a8) == uVar5) {
      uVar10 = (**(code **)(param_1 + 0x4788))
                         (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar14);
      uVar5 = uVar10 & 4;
      if ((((uVar10 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          (uVar5 != *(byte *)(param_1 + 0x7581))) ||
         ((uVar10 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if (uVar5 == 0) {
          uVar10 = uVar10 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        ((int (*)())_gleUpdateDispatchCodeChange)(param_1,uVar10);
      }
    }
    else {
      ((int (*)())_gleSwitchToNonRevertRenderer)(param_1);
    }
  }
  iVar11 = 0x13;
  do {
    *piVar14 = 0;
    piVar14 = piVar14 + 1;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
LAB_000c9cc0:
  uVar10 = 0;
  if (param_2[2] != 0) {
    do {
      iVar11 = uVar10 * 4;
      iVar12 = *(int *)(iVar11 + param_2[6]);
      _gleInitializeGLTexture(2,1,iVar12,in_r6,in_r7,in_r8,uVar5);
      *(undefined2 *)(iVar12 + 0x3e) = 0x85be;
      *(undefined2 *)(iVar12 + 0x34) = 0x812f;
      *(undefined2 *)(iVar12 + 0x36) = 0x812f;
      *(undefined2 *)(iVar12 + 0x38) = 0x812f;
      *(undefined2 *)(iVar12 + 0x3a) = 0x2600;
      *(undefined2 *)(iVar12 + 0x3c) = 0x2600;
      *(undefined4 *)(iVar12 + 0x70) = param_2[5];
      *(undefined4 *)(iVar12 + 0x74) = param_2[7];
      _gleCreatePluginTexture(param_1,*(undefined4 *)(iVar11 + param_2[6]));
      *(undefined1 *)(iVar12 + 0xcf) = 0x11;
      *(undefined2 *)(iVar12 + 0xd0) = 0x40;
      *(undefined2 *)(iVar12 + 0xd2) = 0x40;
      *(undefined2 *)(iVar12 + 0xd4) = 0x80e1;
      in_r8 = 0x8058;
      *(undefined2 *)(iVar12 + 0xd6) = 0x8035;
      iVar4 = param_2[1];
      in_r6 = 0;
      iVar7 = param_2[7];
      in_r7 = 0;
      *(undefined2 *)(iVar12 + 200) = 0x40;
      *(undefined2 *)(iVar12 + 0xca) = 0x40;
      *(undefined2 *)(iVar12 + 0xcc) = 1;
      *(undefined1 *)(iVar12 + 0xce) = 0;
      *(uint *)(iVar12 + 0xd8) = iVar7 + uVar10 * iVar4;
      _gleCreatePluginTextureLevel
                (param_1,*(undefined4 *)(iVar11 + param_2[6]),iVar12 + 0xc4,0,0,0x8058);
      uVar10 = uVar10 + 1;
    } while (uVar10 < (uint)param_2[2]);
  }
  *(undefined1 *)(param_1 + 0x31e6) = uVar2;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x200000;
  *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 1;
  return;
}

/* _gleDrawPixelsSaveState @ 0xc9de8 (756 bytes) */
int _gleDrawPixelsSaveState(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff88;
  double in_stack_ffffff90;
  double in_stack_ffffff98;
  double in_stack_ffffffa0;
  double in_stack_ffffffa8;
  
  bVar4 = *(ushort *)(param_1 + 0x3538) != 0x1e01;
  if ((bool)bVar4) {
    *param_2 = (uint)*(ushort *)(param_1 + 0x3538);
    *(undefined2 *)(param_1 + 0x3538) = 0x1e01;
    *(uint *)(param_1 + 800) = *(uint *)(param_1 + 800) | 1;
  }
  *(undefined4 *)(param_1 + 0x3534) = 4;
  _gleUpdateTextureParams(param_1,0);
  fparam_1 = extraout_f1;
  if (*(byte *)(param_1 + 0x34da) != 0) {
    param_2[1] = (uint)*(byte *)(param_1 + 0x34da);
    *(undefined1 *)(param_1 + 0x34da) = 0;
    _gleUpdatePolyMode(param_1);
    bVar4 = bVar4 | 2;
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800000;
    fparam_1 = extraout_f1_00;
  }
  if (*(byte *)(param_1 + 0x34d8) != 0) {
    param_2[2] = (uint)*(byte *)(param_1 + 0x34d8);
    bVar4 = bVar4 | 4;
    *(undefined1 *)(param_1 + 0x34d8) = 0;
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x2000000;
  }
  if (*(byte *)(param_1 + 0x34dd) != 0) {
    param_2[3] = (uint)*(byte *)(param_1 + 0x34dd);
    bVar4 = bVar4 | 8;
    *(undefined1 *)(param_1 + 0x34dd) = 0;
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800000;
  }
  if (*(byte *)(param_1 + 0x34d9) != 0) {
    param_2[4] = (uint)*(byte *)(param_1 + 0x34d9);
    bVar4 = bVar4 | 0x10;
    *(undefined1 *)(param_1 + 0x34d9) = 0;
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800000;
  }
  if (*(byte *)(param_1 + 0x4664) != 0) {
    param_2[6] = (uint)*(byte *)(param_1 + 0x4664);
    *(undefined1 *)(param_1 + 0x4664) = 0;
    bVar4 = bVar4 | 0x40;
    _gleVPDisable(param_1);
    fparam_1 = extraout_f1_01;
  }
  if (*(uint *)(param_1 + 0x5430) != 0) {
    param_2[7] = *(uint *)(param_1 + 0x5430);
    *(undefined4 *)(param_1 + 0x5430) = 0;
    bVar4 = bVar4 | 0x80;
    _gleVPDisable(param_1);
    fparam_1 = extraout_f1_02;
  }
  param_2[5] = *(uint *)(param_1 + 0x4ff4);
  param_2[8] = *(uint *)(param_1 + 0x1ba0);
  param_2[9] = *(uint *)(param_1 + 0x1ba4);
  param_2[10] = *(uint *)(param_1 + 0x1ba8);
  param_2[0xb] = *(uint *)(param_1 + 0x1bac);
  iVar3 = *(int *)(param_1 + 0x744c);
  *(undefined4 *)(param_1 + 0x1ba4) = 0;
  *(undefined4 *)(param_1 + 0x1ba0) = 0;
  if (iVar3 == 0) {
    uVar1 = *(uint *)(param_1 + 0x471c);
  }
  else {
    uVar1 = (uint)*(ushort *)(iVar3 + 0xca);
  }
  *(uint *)(param_1 + 0x1ba8) = uVar1;
  if (iVar3 == 0) {
    uVar1 = *(uint *)(param_1 + 0x4720);
  }
  else {
    uVar1 = (uint)*(ushort *)(iVar3 + 0xcc);
  }
  *(uint *)(param_1 + 0x1bac) = uVar1;
  ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  _gleCopyMatrix(param_1 + 0x1c80,param_2 + 0xc);
  _gleCopyMatrix(param_1 + 0x1cc0,param_2 + 0x1c);
  _gleCopyMatrix(param_1 + *(int *)(param_1 + 0x53d4) * 0x40 + 0x1fc0,param_2 + 0x2c);
  _glMatrixMode_Exec(param_1,0x1701);
  _glLoadIdentity_Exec(param_1);
  iVar3 = *(int *)(param_1 + 0x744c);
  if (iVar3 == 0) {
    uVar1 = *(uint *)(param_1 + 0x471c);
  }
  else {
    uVar1 = (uint)*(ushort *)(iVar3 + 0xca);
  }
  if (iVar3 == 0) {
    uVar2 = *(uint *)(param_1 + 0x4720);
  }
  else {
    uVar2 = (uint)*(ushort *)(iVar3 + 0xcc);
  }
  ((void (*)())_glOrtho_Exec)(param_1,DOUBLE_00108d60,
                (double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - DOUBLE_00108d58,DOUBLE_00108d60,
                (double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - DOUBLE_00108d58,DOUBLE_00108d60,
                DOUBLE_00108dc8,in_f7,in_f8,in_stack_ffffff88,in_stack_ffffff90,in_stack_ffffff98,
                in_stack_ffffffa0,in_stack_ffffffa8);
  _glMatrixMode_Exec(param_1,0x1700);
  _glLoadIdentity_Exec(param_1);
  _glMatrixMode_Exec(param_1,0x1702);
  _glLoadIdentity_Exec(param_1);
  return bVar4;
}

/* _gleDrawPixelsRestoreState @ 0xca0dc (408 bytes) */
int _gleDrawPixelsRestoreState(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  double extraout_f1;
  double extraout_f1_00;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  if ((param_3 & 1) != 0) {
    *(undefined2 *)(param_1 + 0x3538) = *(undefined2 *)(param_2 + 2);
    *(uint *)(param_1 + 800) = *(uint *)(param_1 + 800) | 1;
  }
  *(undefined4 *)(param_1 + 0x3534) = 0;
  _gleUpdateTextureParams(param_1,0);
  fparam_1 = extraout_f1;
  if ((param_3 & 2) != 0) {
    *(undefined1 *)(param_1 + 0x34da) = *(undefined1 *)(param_2 + 7);
    _gleUpdatePolyMode(param_1);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800000;
    fparam_1 = extraout_f1_00;
  }
  if ((param_3 & 4) != 0) {
    *(undefined1 *)(param_1 + 0x34d8) = *(undefined1 *)(param_2 + 0xb);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x2000000;
  }
  if ((param_3 & 8) != 0) {
    *(undefined1 *)(param_1 + 0x34dd) = *(undefined1 *)(param_2 + 0xf);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800000;
  }
  if ((param_3 & 0x10) != 0) {
    *(undefined1 *)(param_1 + 0x34d9) = *(undefined1 *)(param_2 + 0x13);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800000;
  }
  if (((param_3 & 0x40) != 0) &&
     (*(undefined1 *)(param_1 + 0x4664) = *(undefined1 *)(param_2 + 0x1b),
     *(int *)(param_2 + 0x18) != 0)) {
    fparam_1 = (double)((double (*)())_gleVPEnable)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  }
  if (((param_3 & 0x80) != 0) &&
     (*(undefined4 *)(param_1 + 0x5430) = *(undefined4 *)(param_2 + 0x1c),
     *(int *)(param_2 + 0x1c) != 0)) {
    fparam_1 = (double)((double (*)())_gleVPEnable)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  }
  *(undefined4 *)(param_1 + 0x1ba0) = *(undefined4 *)(param_2 + 0x20);
  *(undefined4 *)(param_1 + 0x1ba4) = *(undefined4 *)(param_2 + 0x24);
  *(undefined4 *)(param_1 + 0x1ba8) = *(undefined4 *)(param_2 + 0x28);
  *(undefined4 *)(param_1 + 0x1bac) = *(undefined4 *)(param_2 + 0x2c);
  ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  _glMatrixMode_Exec(param_1,0x1701);
  _glLoadMatrixf_Exec(param_1,param_2 + 0x30);
  _glMatrixMode_Exec(param_1,0x1700);
  _glLoadMatrixf_Exec(param_1,param_2 + 0x70);
  _glMatrixMode_Exec(param_1,0x1702);
  _glLoadMatrixf_Exec(param_1,param_2 + 0xb0);
  *(undefined4 *)(param_1 + 0x4ff4) = *(undefined4 *)(param_2 + 0x14);
  _gleUpdateMatrixMode(param_1);
  return;
}

/* _pixelBoundaryBottomLeft @ 0xca274 (100 bytes) */
uint _pixelBoundaryBottomLeft(double fparam_1)
{
  uint uVar1;
  
  uVar1 = (uint)(int)fparam_1;
  if ((float)(fparam_1 -
             (double)(float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - DOUBLE_00108d58)) <=
      FLOAT_00108e90) {
    return uVar1;
  }
  return uVar1 + 1;
}

/* _pixelBoundaryTopRight @ 0xca2d8 (92 bytes) */
uint _pixelBoundaryTopRight(double fparam_1)
{
  uint uVar1;
  
  uVar1 = (uint)(int)fparam_1;
  if ((float)(fparam_1 -
             (double)(float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - DOUBLE_00108d58)) <=
      FLOAT_00108e90) {
    return uVar1;
  }
  return uVar1 + 1;
}

/* _pixelCenters @ 0xca334 (160 bytes) */
int _pixelCenters(double fparam_1,double fparam_2,double fparam_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (fparam_3 < (double)FLOAT_00108e50) {
    iVar2 = ((uint (*)())_pixelBoundaryTopRight)(fparam_1);
    iVar3 = ((uint (*)())_pixelBoundaryBottomLeft)(fparam_2);
  }
  else {
    iVar2 = ((uint (*)())_pixelBoundaryBottomLeft)(fparam_1);
    iVar3 = ((uint (*)())_pixelBoundaryTopRight)(fparam_2);
  }
  iVar1 = iVar2 - iVar3;
  if (iVar2 <= iVar3) {
    iVar1 = iVar3 - iVar2;
  }
  return iVar1;
}

/* _gleDrawPixelsFast @ 0xca3d4 (3376 bytes) */
int _gleDrawPixelsFast(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint param_2;
  uint param_3;
  int param_4;
  int param_5;
  void *param_6;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  char cVar6;
  float fVar7;
  double dVar8;
  double dVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int iVar19;
  undefined2 uVar21;
  undefined4 *puVar20;
  uint uVar22;
  uint uVar23;
  uint *puVar24;
  int iVar25;
  uint uVar26;
  uint uVar27;
  int iVar28;
  double dVar29;
  double fparam_1;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double dVar30;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double dVar31;
  double dVar32;
  double fparam_3;
  double fparam_1_00;
  double dVar33;
  double fparam_3_00;
  double dVar34;
  double fparam_4;
  double fparam_3_01;
  double dVar35;
  double fparam_2;
  double dVar36;
  undefined4 in_stack_fffffd48;
  undefined4 in_stack_fffffd4c;
  undefined4 in_stack_fffffd50;
  undefined4 in_stack_fffffd54;
  undefined4 in_stack_fffffd58;
  undefined4 in_stack_fffffd5c;
  undefined4 in_stack_fffffd60;
  undefined4 in_stack_fffffd64;
  undefined4 in_stack_fffffd68;
  undefined4 in_stack_fffffd6c;
  undefined4 in_stack_fffffd70;
  undefined4 in_stack_fffffd74;
  float local_24c;
  float local_244;
  float local_23c;
  float local_234;
  uint local_22c;
  uint local_224;
  undefined1 auStack_210 [240];
  undefined4 local_120;
  uint uStack_11c;
  undefined4 local_118;
  uint uStack_114;
  undefined4 local_110;
  uint uStack_10c;
  longlong local_108;
  undefined8 local_100;
  longlong local_f8;
  undefined4 local_f0;
  void *local_ec;
  void *local_e8;
  int local_e4;
  int *local_e0;
  int local_dc;
  int *local_d8;
  
  fparam_3_01 = (double)*(float *)(param_1 + 0x31ac);
  local_ec = (void *)0x0;
  fparam_3_00 = (double)*(float *)(param_1 + 0x31a8);
  local_234 = *(float *)(param_1 + 0x2e0);
  dVar36 = (double)local_234;
  fVar7 = *(float *)(param_1 + 0x2e4);
  fparam_1_00 = (double)fVar7;
  dVar34 = (double)*(float *)(param_1 + 0x2e8);
  dVar33 = fparam_3_01;
  if (fparam_3_01 < (double)FLOAT_00108e50) {
    dVar33 = -fparam_3_01;
  }
  fVar2 = FLOAT_00108e54;
  dVar8 = fparam_3_00;
  if (fparam_3_00 < (double)FLOAT_00108e50) {
    fVar2 = FLOAT_00108e58;
    dVar8 = -fparam_3_00;
  }
  fparam_3 = (double)fVar2;
  fVar2 = FLOAT_00108e54;
  if (fparam_3_01 < (double)FLOAT_00108e50) {
    fVar2 = FLOAT_00108e58;
  }
  fparam_4 = (double)fVar2;
  if ((((((fparam_3_00 == (double)FLOAT_00108e54) && (fparam_3_01 == (double)FLOAT_00108e54)) &&
        ((int)param_2 < 0x201)) &&
       ((((int)param_3 < 0x201 && (*(char *)(param_1 + 0x30c6) == '\0')) &&
        ((*(char *)(param_1 + 0x30e4) == '\0' &&
         ((*(char *)(param_1 + 0x3128) == '\0' && ((*(uint *)(param_1 + 0x3520) & 3) == 0)))))))) &&
      ((*(char *)(param_1 + 0x3ce4) == '\0' &&
       (((*(char *)(param_1 + 0x41f8) == '\0' && (*(char *)(param_1 + 0x316a) == '\0')) &&
        (*(char *)(param_1 + 0x3193) == '\0')))))) &&
     (((*(char *)(param_1 + 0x313c) == '\0' && (*(char *)(param_1 + 0x31a0) != '\0')) &&
      (((*(char *)(param_1 + 0x31a1) != '\0' &&
        ((*(char *)(param_1 + 0x31a2) != '\0' && (*(char *)(param_1 + 0x31a3) != '\0')))) &&
       (*(char *)(param_1 + 0x466c) == '\0')))))) {
    return 0;
  }
  uVar26 = 0;
  uVar10 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xb4);
  if (uVar10 != 0) {
    piVar12 = (int *)(param_1 + 0x3534);
    do {
      iVar11 = *piVar12;
      piVar12 = piVar12 + 0x1f;
      if (iVar11 != 0) {
        return 0;
      }
      uVar26 = uVar26 + 1;
    } while (uVar26 < uVar10);
  }
  if (param_4 - 0x1901U < 2) {
    return 0;
  }
  local_e8 = param_6;
  iVar11 = ((int (*)())_gleDrawPixelsFastPickTextureType)(param_5);
  uVar26 = param_2;
  uVar10 = param_3;
  if (((*(uint *)(param_1 + 0x3410) & 0x1ff) == 0) &&
     (iVar13 = param_4, (*(uint *)(param_1 + 0x3414) & 0xff0000) == 0)) goto LAB_000ca704;
  if (((*(uint *)(param_1 + 0x3410) & 2) == 0) || (*(short *)(param_1 + 0x3308) != -0x7fea)) {
    if (((*(uint *)(param_1 + 0x3410) & 4) != 0) && (*(short *)(param_1 + 0x3348) == -0x7fea)) {
      iVar19 = *(int *)(param_1 + 0x3354);
      iVar13 = *(int *)(param_1 + 0x3350);
      goto LAB_000ca634;
    }
  }
  else {
    iVar19 = *(int *)(param_1 + 0x3314);
    iVar13 = *(int *)(param_1 + 0x3310);
LAB_000ca634:
    uVar10 = (param_3 - iVar19) + 1;
    uVar26 = (param_2 - iVar13) + 1;
  }
  iVar13 = _glePixelBytes(0x80e1,iVar11);
  local_ec = (void *)_gleVecAlloc(iVar13 * uVar26 * uVar10);
  _glePixelBytes(0x80e1,iVar11);
  iVar13 = 0x80e1;
  ((void (*)())_CopySourceSubImageToTexture)(param_1,param_2,param_3,param_4,param_5,param_6,param_2,param_3,in_stack_fffffd48,
             in_stack_fffffd4c,in_stack_fffffd50,in_stack_fffffd54,in_stack_fffffd58,
             in_stack_fffffd5c,in_stack_fffffd60,in_stack_fffffd64,in_stack_fffffd68,
             in_stack_fffffd6c,in_stack_fffffd70,in_stack_fffffd74,(double)FLOAT_00108e50,
             (double)FLOAT_00108e50,fparam_3,fparam_4);
  local_e8 = local_ec;
  param_5 = iVar11;
LAB_000ca704:
  puVar24 = (uint *)(param_1 + 0x7488);
  if (*(int *)(param_1 + 0x74a0) == 0) {
    ((int (*)())_gleInitDrawPixelsShareObject)(param_1,puVar24);
  }
  uVar27 = 0;
  *(int *)(param_1 + 0x7498) = iVar11;
  if (*(int *)(param_1 + 0x7490) != 0) {
    do {
      iVar19 = uVar27 * 4;
      uVar27 = uVar27 + 1;
      *(short *)(*(int *)(iVar19 + *(int *)(param_1 + 0x74a0)) + 0xd6) = (short)iVar11;
    } while (uVar27 < *(uint *)(param_1 + 0x7490));
  }
  local_f0 = ((int (*)())_gleDrawPixelsSaveState)(param_1,auStack_210);
  local_224 = 0;
  dVar35 = (double)FLOAT_00108f18;
  if (fparam_3 == (double)FLOAT_00108e54) {
    uStack_11c = ((uint (*)())_pixelBoundaryTopRight)(dVar36);
    uStack_11c = uStack_11c ^ 0x80000000;
    local_120 = 0x43300000;
    uVar27 = uStack_11c;
  }
  else {
    uStack_114 = ((uint (*)())_pixelBoundaryBottomLeft)(dVar36);
    uStack_114 = uStack_114 ^ 0x80000000;
    local_118 = 0x43300000;
    uVar27 = uStack_114;
  }
  dVar36 = DOUBLE_00108d58;
  uVar22 = 0;
  if (0 < (int)uVar26) {
    local_dc = param_1 + 0x10000;
    local_d8 = (int *)(param_1 + 0x310);
    local_244 = (float)((double)CONCAT44(0x43300000,uVar27) - DOUBLE_00108d58);
    do {
      uStack_11c = uVar26 ^ 0x80000000;
      local_118 = 0x43300000;
      uStack_114 = local_224 ^ 0x80000000;
      local_120 = 0x43300000;
      dVar31 = (double)(float)((double)CONCAT44(0x43300000,uStack_114) - dVar36);
      fVar2 = (float)(dVar31 + dVar35);
      if ((float)((double)CONCAT44(0x43300000,uStack_11c) - dVar36) < fVar2) {
        local_110 = 0x43300000;
        uStack_10c = uVar26 - local_224 ^ 0x80000000;
        dVar35 = (double)(float)((double)CONCAT44(0x43300000,uStack_10c) - dVar36);
        fVar2 = (float)(dVar31 + dVar35);
      }
      dVar31 = (double)FLOAT_00108f18;
      fVar4 = (float)((double)(float)(dVar35 * dVar8) * fparam_3 + (double)local_234);
      uStack_10c = ((int (*)())_pixelCenters)((double)local_234,(double)fVar4,fparam_3_00);
      local_110 = 0x43300000;
      uStack_10c = uStack_10c ^ 0x80000000;
      local_224 = (uint)fVar2;
      local_108 = (longlong)(int)local_224;
      local_22c = 0;
      fVar2 = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_10c) - dVar36) * fparam_3 +
                     (double)local_244);
      if (fparam_4 == (double)FLOAT_00108e54) {
        uVar27 = ((uint (*)())_pixelBoundaryTopRight)(fparam_1_00);
        uVar27 = uVar27 ^ 0x80000000;
      }
      else {
        uStack_114 = ((uint (*)())_pixelBoundaryBottomLeft)(fparam_1_00);
        local_118 = 0x43300000;
        uStack_114 = uStack_114 ^ 0x80000000;
        uVar27 = uStack_114;
      }
      dVar9 = DOUBLE_00108d58;
      uVar23 = 0;
      if (0 < (int)uVar10) {
        local_e4 = local_dc;
        local_e0 = local_d8;
        local_24c = (float)((double)CONCAT44(0x43300000,uVar27) - dVar36);
        local_23c = fVar7;
        do {
          uStack_114 = uVar10 ^ 0x80000000;
          local_110 = 0x43300000;
          uStack_10c = local_22c ^ 0x80000000;
          local_118 = 0x43300000;
          dVar32 = (double)(float)((double)CONCAT44(0x43300000,uStack_10c) - dVar9);
          fVar3 = (float)(dVar32 + dVar31);
          if ((float)((double)CONCAT44(0x43300000,uStack_114) - dVar9) < fVar3) {
            local_120 = 0x43300000;
            uStack_11c = uVar10 - local_22c ^ 0x80000000;
            dVar31 = (double)(float)((double)CONCAT44(0x43300000,uStack_11c) - dVar9);
            fVar3 = (float)(dVar32 + dVar31);
          }
          dVar32 = (double)(float)(dVar31 * dVar33);
          fVar5 = (float)(dVar32 * fparam_4 + (double)local_23c);
          uStack_10c = ((int (*)())_pixelCenters)((double)local_23c,(double)fVar5,fparam_3_01);
          iVar19 = local_e4;
          local_110 = 0x43300000;
          uStack_10c = uStack_10c ^ 0x80000000;
          local_22c = (uint)fVar3;
          local_108 = (longlong)(int)local_22c;
          fVar3 = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_10c) - dVar9) *
                          fparam_4 + (double)local_24c);
          if ((double)FLOAT_00108e54 <= dVar35) {
            dVar30 = dVar32;
            if (dVar31 < dVar32) {
              dVar30 = dVar31;
            }
            if ((double)FLOAT_00108e54 <= dVar30) {
              uVar27 = 0;
              if (*(char *)(local_e4 + -0x7a5c) != '\0') {
                iVar25 = param_1 + 0x10000;
                do {
                  iVar15 = uVar27 * 4;
                  piVar12 = (int *)(iVar25 + -0x777c);
                  uVar27 = uVar27 + 1;
                  puVar20 = (undefined4 *)(iVar25 + -0x7a54);
                  iVar25 = iVar25 + 0x2e0;
                  (**(code **)(*piVar12 + 0x1c4))
                            (*puVar20,1,
                             *(undefined4 *)
                              (*(int *)(*puVar24 * 4 + *(int *)(param_1 + 0x74a0)) + iVar15));
                } while (uVar27 < *(byte *)(iVar19 + -0x7a5c));
              }
              local_110 = 0x43300000;
              local_108 = (longlong)(int)local_23c;
              uStack_10c = (int)local_23c ^ 0x80000000;
              fparam_2 = (double)(local_23c -
                                 (float)((double)CONCAT44(0x43300000,uStack_10c) - dVar9));
              uStack_10c = _glePixelBytes(0x80e1,iVar11);
              uStack_10c = uStack_10c ^ 0x80000000;
              local_110 = 0x43300000;
              dVar30 = dVar35 * (double)(float)((double)CONCAT44(0x43300000,uStack_10c) - dVar9);
              dVar29 = (double)(float)dVar30;
              if (DOUBLE_00108d80 <= dVar29) {
                local_100 = (longlong)(int)(dVar29 - DOUBLE_00108d80);
              }
              else {
                local_108 = (longlong)(int)dVar30;
              }
              iVar25 = (int)dVar31;
              local_f8 = (longlong)iVar25;
              dVar30 = fparam_3;
              dVar29 = fparam_4;
              ((void (*)())_CopySourceSubImageToTexture)(param_1,uVar26,uVar10,iVar13,param_5,local_e8,(int)dVar35,iVar25,
                         in_stack_fffffd48,in_stack_fffffd4c,in_stack_fffffd50,in_stack_fffffd54,
                         in_stack_fffffd58,in_stack_fffffd5c,in_stack_fffffd60,in_stack_fffffd64,
                         in_stack_fffffd68,in_stack_fffffd6c,in_stack_fffffd70,in_stack_fffffd74,
                         (double)(local_234 -
                                 (float)((double)CONCAT44(0x43300000,(int)local_234 ^ 0x80000000) -
                                        dVar9)),fparam_2,fparam_3,fparam_4);
              iVar15 = *(int *)(*puVar24 * 4 + *(int *)(param_1 + 0x74a0));
              iVar28 = iVar15 + 0xc4;
              _gleDeletePluginTextureLevel(param_1,iVar15,iVar28,0,0);
              *(short *)(iVar15 + 0xd0) = (short)(int)dVar35;
              if (dVar32 <= dVar31) {
                iVar25 = (int)(dVar31 * dVar33);
                (*(unsigned short *)((unsigned char *)&(local_100) + 6)) = (undefined2)iVar25;
                uVar21 = (*(unsigned short *)((unsigned char *)&(local_100) + 6));
                local_100 = (longlong)iVar25;
              }
              else {
                uVar21 = (short)iVar25;
              }
              *(undefined2 *)(iVar15 + 0xd2) = uVar21;
              *(undefined2 *)(iVar15 + 200) = *(undefined2 *)(iVar15 + 0xd0);
              *(undefined2 *)(iVar15 + 0xca) = *(undefined2 *)(iVar15 + 0xd2);
              uVar18 = 0x8058;
              if (iVar11 != 0x8367) {
                uVar18 = 0x8057;
              }
              uVar16 = 0;
              uVar17 = 0;
              fparam_1 = (double)_gleCreatePluginTextureLevel
                                           (param_1,*(undefined4 *)
                                                     (*puVar24 * 4 + *(int *)(param_1 + 0x74a0)),
                                            iVar28,0,0,uVar18);
              uVar27 = 0;
              if (*(char *)(iVar19 + -0x7a5c) != '\0') {
                puVar20 = (undefined4 *)(param_1 + 0x86e8);
                do {
                  iVar25 = uVar27 * 4;
                  uVar27 = uVar27 + 1;
                  *puVar20 = *(undefined4 *)
                              (*(int *)(*puVar24 * 4 + *(int *)(param_1 + 0x74a0)) + iVar25);
                  puVar20 = puVar20 + 0xb8;
                } while (uVar27 < *(byte *)(iVar19 + -0x7a5c));
              }
              iVar25 = *(int *)(param_1 + 0x50ac);
              *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 1;
              if (iVar25 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
                _gleUpdateMatrixFunc(param_1);
                fparam_1 = extraout_f1;
              }
              piVar12 = local_e0;
              if (*(char *)(param_1 + 0x4691) != '\0') {
                iVar15 = *(int *)(param_1 + 0x744c);
                cVar6 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
                if ((iVar15 != 0) && (*(int *)(iVar15 + 0xec) != 0)) {
                  ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar15 + 0x10,iVar28,uVar16,uVar17,uVar18,iVar25,fparam_1,
                             fparam_2,dVar30,dVar29,in_f5,in_f6,in_f7,in_f8);
                  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
                  fparam_1 = extraout_f1_00;
                }
                if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000cae0c:
                  uVar27 = piVar12[3];
                }
                else {
                  iVar25 = 0;
                  piVar14 = piVar12 + 5;
                  do {
                    iVar15 = *piVar14;
                    piVar14 = piVar14 + 1;
                    if (iVar15 != 0) {
                      piVar12[3] = piVar12[3] | 0x800000;
                      break;
                    }
                    iVar25 = iVar25 + 1;
                  } while (iVar25 < 9);
                  uVar27 = piVar12[3];
                  if ((uVar27 & 0x15555) != 0) {
                    if (*(char *)(param_1 + 0x2e54) != '\0') {
                      fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
                    }
                    if (*(char *)(param_1 + 0x3094) != '\0') {
                      fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
                    }
                    goto LAB_000cae0c;
                  }
                }
                bVar1 = cVar6 == '\0';
                if (bVar1) {
                  uVar27 = uVar27 & 0x17000000;
                }
                else {
                  uVar27 = uVar27 & 0x17ffffff;
                }
                if (bVar1) {
                  bVar1 = ((*piVar12 == 0 && piVar12[1] == 0) && uVar27 == 0) && piVar12[4] == 0;
                }
                else {
                  bVar1 = (((*piVar12 == 0 && piVar12[1] == 0) && (piVar12[2] & 0xfffffffdU) == 0)
                          && uVar27 == 0) && piVar12[4] == 0;
                }
                if (!bVar1) {
                  if (*(char *)(iVar19 + -0x7a58) == *(char *)(iVar19 + -0x7a5a)) {
                    uVar27 = (**(code **)(param_1 + 0x4788))
                                       (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar12);
                    if ((((uVar27 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
                        ((uVar27 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
                       (fparam_1 = extraout_f1_01,
                       (uVar27 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
                      if ((uVar27 & 4) == 0) {
                        uVar27 = uVar27 & 0xfffffffe;
                        piVar12[3] = piVar12[3] | 0x10000000;
                      }
                      fparam_1 = (double)((int (*)())_gleUpdateDispatchCodeChange)(param_1,uVar27);
                      if (*(char *)(param_1 + 0x759d) == '\0') {
                        if (*(int *)(param_1 + 0x7574) != 0) {
                          return 1;
                        }
                        *(undefined4 *)(param_1 + 0x7574) = 0x506;
                        return 1;
                      }
                    }
                  }
                  else {
                    fparam_1 = (double)((int (*)())_gleSwitchToNonRevertRenderer)(param_1);
                  }
                  iVar19 = 0x13;
                  do {
                    *piVar12 = 0;
                    piVar12 = piVar12 + 1;
                    iVar19 = iVar19 + -1;
                  } while (iVar19 != 0);
                }
              }
              ((void (*)())_glBegin_Exec)(param_1,7,fparam_1,fparam_2,dVar30,dVar29,in_f5,in_f6,in_f7,in_f8);
              *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
              *(float *)(param_1 + 300) = *(float *)(param_1 + 0x24);
              *(undefined4 *)(param_1 + 0x120) = 0;
              *(undefined4 *)(param_1 + 0x124) = 0;
              (**(int ( **)(int,double,double,double,double))(param_1 + 0x4884))
                        (param_1, (double)local_244, (double)local_24c, dVar34, (double)*(float *)(param_1 + 0x24));
              *(float *)(param_1 + 0x120) = (float)dVar35;
              *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
              *(undefined4 *)(param_1 + 0x124) = 0;
              *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
              (**(int ( **)(int,double,double,double))(param_1 + 0x4884))(param_1, (double)fVar2, (double)local_24c, dVar34);
              *(float *)(param_1 + 0x120) = (float)dVar35;
              dVar30 = dVar32;
              if (dVar31 < dVar32) {
                dVar30 = dVar31;
              }
              *(float *)(param_1 + 0x124) = (float)dVar30;
              *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
              *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
              (**(int ( **)(int,double,double,double))(param_1 + 0x4884))(param_1, (double)fVar2, (double)fVar3, dVar34);
              *(undefined4 *)(param_1 + 0x120) = 0;
              if (dVar31 < dVar32) {
                dVar32 = dVar31;
              }
              *(float *)(param_1 + 0x124) = (float)dVar32;
              *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
              *(float *)(param_1 + 300) = *(float *)(param_1 + 0x24);
              (**(int ( **)(int,double,double,double,double))(param_1 + 0x4884))
                        (param_1, (double)local_244, (double)fVar3, dVar34, (double)*(float *)(param_1 + 0x24));
              _glEnd_Exec(param_1);
              uVar27 = *puVar24;
              *puVar24 = uVar27 + 1;
              if (*(uint *)(param_1 + 0x7490) <= uVar27 + 1) {
                *puVar24 = 0;
              }
            }
          }
          uVar23 = (uint)(int)((double)(float)((double)CONCAT44(0x43300000,uVar23 ^ 0x80000000) - dVar9)
                         + dVar31);
          local_f8 = (longlong)(int)uVar23;
          local_24c = fVar3;
          local_23c = fVar5;
        } while ((int)uVar23 < (int)uVar10);
      }
      uStack_10c = uVar22 ^ 0x80000000;
      local_110 = 0x43300000;
      uVar22 = (uint)(int)((double)(float)((double)CONCAT44(0x43300000,uStack_10c) - dVar36) + dVar35);
      local_f8 = (longlong)(int)uVar22;
      local_244 = fVar2;
      local_234 = fVar4;
    } while ((int)uVar22 < (int)uVar26);
  }
  ((int (*)())_gleDrawPixelsRestoreState)(param_1,auStack_210,local_f0);
  if (local_ec != (void *)0x0) {
    _gleVecFree(local_ec);
  }
  return 1;
}

/* _gleSetEnable_TEXTURE_1D @ 0xcb104 (80 bytes) */
int _gleSetEnable_TEXTURE_1D(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)(param_1 + 0x53d4);
  if (uVar3 < 8) {
    iVar2 = uVar3 * 0x7c + param_1;
    uVar4 = *(uint *)(iVar2 + 0x3534);
    uVar1 = uVar4 & 0xffffffef | param_3 << 4;
    if (uVar4 == uVar1) {
      return;
    }
    *(uint *)(iVar2 + 0x3534) = uVar1;
    _gleUpdateTextureParams(param_1,uVar3);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _gleSetEnable_TEXTURE_CUBE_MAP @ 0xcb154 (76 bytes) */
int _gleSetEnable_TEXTURE_CUBE_MAP(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)(param_1 + 0x53d4);
  if (uVar3 < 8) {
    iVar2 = uVar3 * 0x7c + param_1;
    uVar4 = *(uint *)(iVar2 + 0x3534);
    uVar1 = uVar4 & 0xfffffffe | param_3;
    if (uVar4 == uVar1) {
      return;
    }
    *(uint *)(iVar2 + 0x3534) = uVar1;
    _gleUpdateTextureParams(param_1,uVar3);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _gleSetEnable_SHARED_TEXTURE_PALETTE_EXT @ 0xcb1a0 (100 bytes) */
int _gleSetEnable_SHARED_TEXTURE_PALETTE_EXT(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 0x53d4);
  if (uVar4 < 8) {
    iVar2 = uVar4 * 0x7c + param_1;
    uVar3 = *(uint *)(iVar2 + 0x3534);
    uVar1 = uVar3 & 0xfffffeff | param_3 << 8;
    if (uVar3 == uVar1) {
      return;
    }
    *(uint *)(iVar2 + 0x3534) = uVar1;
    *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 1 << (uVar4 & 0x3f);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _gleSetEnable_LINE_STIPPLE @ 0xcb204 (32 bytes) */
int _gleSetEnable_LINE_STIPPLE(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x318c) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x318c) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x10000;
  return;
}

/* _gleSetEnable_POLYGON_STIPPLE @ 0xcb224 (32 bytes) */
int _gleSetEnable_POLYGON_STIPPLE(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x34d8) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x34d8) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x2000000;
  return;
}

/* _gleSetEnable_INDEX_LOGIC_OP @ 0xcb244 (32 bytes) */
int _gleSetEnable_INDEX_LOGIC_OP(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x3192) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x3192) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x20000;
  return;
}

/* _gleSetEnable_COLOR_LOGIC_OP @ 0xcb264 (32 bytes) */
int _gleSetEnable_COLOR_LOGIC_OP(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x3193) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x3193) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x20000;
  return;
}

