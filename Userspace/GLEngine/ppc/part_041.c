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
void _gleSetNormalFunc(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)(*_gleBuildNormalTransformFunc)(param_1,param_2,param_3);
  *(code **)(param_1 + 0x5068) = UNRECOVERED_JUMPTABLE;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3);
  return;
}

/* _gleTransformNormalBlend @ 0xc5310 (468 bytes) */
void _gleTransformNormalBlend(int param_1,uint param_2,int param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
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
  int iVar13;
  undefined *puVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  float dVar19;
  
  iVar13 = param_3 * 0x100;
  bVar1 = *(byte *)(param_1 + 0x4660);
  if (param_2 < param_2 + iVar13) {
    uVar18 = ((param_2 + iVar13) - param_2) + 0xff >> 8;
    uVar17 = param_2;
    do {
      *(undefined4 *)(uVar17 + 0xf0) = 0;
      *(undefined4 *)(uVar17 + 0xf4) = 0;
      *(undefined4 *)(uVar17 + 0xf8) = 0;
      uVar17 = uVar17 + 0x100;
      uVar18 = uVar18 - 1;
    } while (uVar18 != 0);
  }
  iVar16 = 0;
  if (bVar1 != 0) {
    iVar15 = param_1;
    do {
      fVar2 = *(float *)(iVar15 + 0x22c0);
      fVar3 = *(float *)(iVar15 + 0x22c4);
      fparam_1 = (double)*(float *)(iVar15 + 0x22c8);
      fVar4 = *(float *)(iVar15 + 0x22d0);
      fVar5 = *(float *)(iVar15 + 0x22d4);
      fVar6 = *(float *)(iVar15 + 0x22d8);
      fVar7 = *(float *)(iVar15 + 0x22e0);
      fVar8 = *(float *)(iVar15 + 0x22e4);
      fVar9 = *(float *)(iVar15 + 0x22e8);
      if (param_2 < param_2 + iVar13) {
        uVar18 = ((param_2 + iVar13) - param_2) + 0xff >> 8;
        uVar17 = param_2;
        do {
          fVar10 = *(float *)(uVar17 + 0x44);
          dVar19 = (double)*(float *)(uVar17 + 0x40);
          fVar11 = *(float *)(uVar17 + 0x48);
          fVar12 = *(float *)(iVar16 * 4 + uVar17 + 0x60);
          *(float *)(uVar17 + 0xf0) =
               fVar12 * (fVar11 * fVar7 + (dVar19 * fVar2 + (fVar10 * fVar4))
                        ) + *(float *)(uVar17 + 0xf0);
          *(float *)(uVar17 + 0xf8) =
               fVar12 * (fVar11 * fVar9 + (float)((double)dVar19 * fparam_1 + (double)(fVar10 * fVar6))) +
               *(float *)(uVar17 + 0xf8);
          *(float *)(uVar17 + 0xf4) =
               fVar12 * (fVar11 * fVar8 + (dVar19 * fVar3 + (fVar10 * fVar5))
                        ) + *(float *)(uVar17 + 0xf4);
          uVar17 = uVar17 + 0x100;
          uVar18 = uVar18 - 1;
        } while (uVar18 != 0);
      }
      iVar16 = iVar16 + 1;
      iVar15 = iVar15 + 0x40;
    } while (iVar16 < (int)(uint)bVar1);
  }
  puVar14 = PTR__gleVectorNormalize_00112064;
  uVar18 = param_2 + iVar13;
  if (*(char *)(param_1 + 0x280d) == '\0') {
    if (param_2 < uVar18) {
      uVar18 = (uVar18 - param_2) + 0xff >> 8;
      do {
        *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(param_2 + 0xf0);
        *(undefined4 *)(param_2 + 0x44) = *(undefined4 *)(param_2 + 0xf4);
        *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(param_2 + 0xf8);
        param_2 = param_2 + 0x100;
        uVar18 = uVar18 - 1;
      } while (uVar18 != 0);
    }
  }
  else {
    for (; param_2 < uVar18; param_2 = param_2 + 0x100) {
      fparam_1 = (double)(**(double ( **)(int,int,int,double))puVar14)(param_1, param_2 + 0xf0, param_2 + 0x40, fparam_1);
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
void _gleSetProjectionFuncW1(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  code *pcVar1;
  
  pcVar1 = (code *)(*_gleBuildProjectionTransformFunc)(param_1,1,param_3);
  *(code **)(param_1 + 0x5060) = pcVar1;
  (*pcVar1)(param_1,param_2,param_3);
  return;
}

/* _gleSetProjectionFuncZ0W1 @ 0xc5e74 (104 bytes) */
void _gleSetProjectionFuncZ0W1(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  code *pcVar1;
  
  pcVar1 = (code *)(*_gleBuildProjectionTransformFunc)(param_1,3,param_3);
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
      fVar2 = FLOAT_00108e54;
      if (0 < iVar36) {
        pfVar37 = pfVar42 + 0x18;
        iVar43 = iVar36;
        do {
          fVar1 = *pfVar37;
          pfVar37 = pfVar37 + 1;
          fVar2 = fVar2 - fVar1;
          iVar43 = iVar43 + -1;
          iVar40 = iVar36;
        } while (iVar43 != 0);
      }
      pfVar37 = pfVar42 + 0x40;
      pfVar42[iVar40 + 0x18] = fVar2;
      pfVar42 = pfVar37;
    } while (pfVar37 < pfVar38);
  }
  iVar36 = 0;
  if (uVar39 != 0) {
    pfVar38 = (float *)(param_1 + 0x1cc0);
    do {
      fVar2 = *pfVar38;
      fVar1 = pfVar38[1];
      fVar3 = pfVar38[2];
      fVar4 = pfVar38[3];
      fVar5 = pfVar38[4];
      fVar6 = pfVar38[5];
      fVar7 = pfVar38[6];
      fVar8 = pfVar38[7];
      fVar9 = pfVar38[8];
      fVar10 = pfVar38[9];
      fVar11 = pfVar38[10];
      fVar12 = pfVar38[0xb];
      fVar13 = pfVar38[0xc];
      fVar14 = pfVar38[0xd];
      fVar15 = pfVar38[0xe];
      fVar16 = pfVar38[0xf];
      if (param_2 < param_2 + param_3 * 0x40) {
        uVar44 = (uint)((int)(param_2 + param_3 * 0x40) + (0xff - (int)param_2)) >> 8;
        pfVar42 = param_2;
        do {
          fVar17 = pfVar42[9];
          fVar18 = pfVar42[8];
          fVar19 = pfVar42[10];
          fVar20 = pfVar42[0xb];
          fVar21 = pfVar42[iVar36 + 0x18];
          pfVar42[0x3c] =
               fVar21 * (fVar20 * fVar13 + (fVar19 * fVar9 + (fVar18 * fVar2 + fVar17 * fVar5))) +
               pfVar42[0x3c];
          pfVar42[0x3f] =
               fVar21 * (fVar20 * fVar16 + (fVar19 * fVar12 + (fVar18 * fVar4 + fVar17 * fVar8))) +
               pfVar42[0x3f];
          pfVar42[0x3d] =
               fVar21 * (fVar20 * fVar14 + (fVar19 * fVar10 + (fVar18 * fVar1 + fVar17 * fVar6))) +
               pfVar42[0x3d];
          pfVar42[0x3e] =
               fVar21 * (fVar20 * fVar15 + (fVar19 * fVar11 + (fVar18 * fVar3 + fVar17 * fVar7))) +
               pfVar42[0x3e];
          pfVar42 = pfVar42 + 0x40;
          uVar44 = uVar44 - 1;
        } while (uVar44 != 0);
      }
      iVar36 = iVar36 + 1;
      pfVar38 = pfVar38 + 0x10;
    } while (iVar36 < (int)uVar39);
  }
  fVar2 = *(float *)(param_1 + 0x4a20);
  fVar1 = *(float *)(param_1 + 0x1c8c);
  pfVar38 = param_2 + param_3 * 0x40;
  fVar3 = *(float *)(param_1 + 0x4a28);
  fVar4 = *(float *)(param_1 + 0x1c9c);
  uVar39 = 0;
  fVar5 = *(float *)(param_1 + 0x1cac);
  uVar44 = 0xff;
  fVar6 = *(float *)(param_1 + 0x1cbc);
  fVar7 = *(float *)(param_1 + 0x4a1c);
  fVar8 = *(float *)(param_1 + 0x4a24);
  fVar9 = *(float *)(param_1 + 0x1ca0);
  fVar10 = *(float *)(param_1 + 0x1cb0);
  fVar11 = *(float *)(param_1 + 0x1b70);
  fVar12 = *(float *)(param_1 + 0x1c94);
  fVar13 = *(float *)(param_1 + 0x1c80);
  fVar14 = *(float *)(param_1 + 0x1c84);
  fVar15 = *(float *)(param_1 + 0x1c90);
  fVar16 = *(float *)(param_1 + 0x1ca4);
  fVar17 = *(float *)(param_1 + 0x1cb4);
  fVar18 = *(float *)(param_1 + 0x1cb8);
  fVar19 = *(float *)(param_1 + 0x1c88);
  fVar20 = *(float *)(param_1 + 0x1c98);
  fVar21 = *(float *)(param_1 + 0x1ca8);
  fVar22 = *(float *)(param_1 + 0x1b74);
  fVar23 = *(float *)(param_1 + 0x1b78);
  fVar24 = *(float *)(param_1 + 0x1b84);
  fVar25 = *(float *)(param_1 + 0x1b80);
  fVar26 = *(float *)(param_1 + 0x1b88);
  do {
    if (pfVar38 <= param_2) {
      restFP(uVar44 << 8 | uVar39);
      return;
    }
    uVar41 = 0;
    fVar27 = param_2[0x3c];
    fVar28 = param_2[0x3d];
    fVar29 = param_2[0x3e];
    fVar30 = param_2[0x3f];
    if ((*(byte *)(param_1 + 0x50b4) & 2) != 0) {
      fVar31 = fVar29;
      if (*(short *)(param_1 + 0x3166) == -0x7baf) {
        fVar31 = param_2[0x17];
      }
      if (fVar35 < fVar31) {
        fVar31 = -fVar31;
      }
      fVar32 = FLOAT_00108e54;
      if (*(short *)(param_1 + 0x3164) == 0x800) {
        if (fVar31 < fVar35) {
          fVar31 = *(float *)(param_1 + 0x3150) * fVar31;
          goto LAB_000c628c;
        }
      }
      else if (*(short *)(param_1 + 0x3164) == 0x2601) {
        fVar31 = (*(float *)(param_1 + 0x3158) + fVar31) * *(float *)(param_1 + 0x315c);
        if ((fVar31 <= FLOAT_00108e54) && (fVar32 = fVar31, fVar31 < fVar35)) {
          fVar32 = FLOAT_00108e50;
        }
      }
      else {
        fVar31 = *(float *)(param_1 + 0x3150) * fVar31;
        fVar31 = -fVar31 * fVar31;
LAB_000c628c:
        dVar45 = _exp((double)fVar31);
        fVar32 = (float)dVar45;
      }
      param_2[0x13] = fVar32;
    }
    fVar33 = fVar30 * fVar6 + (fVar29 * fVar5 + (fVar27 * fVar1 + fVar28 * fVar4));
    fVar31 = fVar30 * (fVar7 * fVar10 + fVar2 * fVar6) +
             (fVar29 * (fVar7 * fVar9 + fVar2 * fVar5) +
             (fVar27 * (fVar7 * fVar13 + fVar2 * fVar1) + fVar28 * (fVar7 * fVar15 + fVar2 * fVar4)));
    fVar34 = -fVar33;
    fVar32 = fVar30 * fVar18 + (fVar29 * fVar21 + (fVar27 * fVar19 + fVar28 * fVar20));
    fVar27 = fVar30 * (fVar8 * fVar17 + fVar3 * fVar6) +
             (fVar29 * (fVar8 * fVar16 + fVar3 * fVar5) +
             (fVar27 * (fVar8 * fVar14 + fVar3 * fVar1) + fVar28 * (fVar8 * fVar12 + fVar3 * fVar4)));
    if (fVar31 < fVar34) {
      uVar41 = 0x10;
    }
    if (fVar33 <= fVar31) {
      uVar41 = uVar41 | 0x20;
    }
    if (fVar27 < fVar34) {
      uVar41 = uVar41 | 4;
    }
    if (fVar33 <= fVar27) {
      uVar41 = uVar41 | 8;
    }
    if (fVar32 < fVar34) {
      uVar41 = uVar41 | 1;
    }
    if (fVar33 < fVar32) {
      uVar41 = uVar41 | 2;
    }
    param_2[4] = fVar31;
    param_2[5] = fVar27;
    param_2[6] = fVar32;
    param_2[7] = fVar33;
    *(char *)((int)param_2 + 0x7f) = (char)uVar41;
    if (uVar41 == 0) {
      fVar33 = FLOAT_00108e54 / fVar33;
      param_2[3] = fVar33;
      *param_2 = fVar31 * fVar33 * fVar11 + fVar25;
      param_2[1] = fVar27 * fVar33 * fVar22 + fVar24;
      param_2[2] = fVar32 * fVar33 * fVar23 + fVar26;
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
void _gleGetClientAttrib(param_1, param_2, param_3)
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
void _gleSetClientAttrib(param_1, param_2, param_3)
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
void _gleAddClientAttribElem(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)_malloc(0x2c0);
  if (puVar2 == (undefined4 *)0x0) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x505;
    }
  }
  else {
    *puVar2 = param_2;
    ((void (*)())_gleGetClientAttrib)(param_1,param_2,puVar2 + 1);
    piVar1 = *(int **)(param_1 + 0x5140);
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
void _gleCreatePluginBuffer(param_1, param_2)
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
void _gleFreeBufferObject(param_1, param_2)
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
  iVar5 = param_2;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      iVar4 = iVar4 + 1;
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      iVar3 = iVar3 + 0x2e0;
      (**(code **)(*piVar1 + 0x1d8))(*puVar2,*(undefined4 *)(iVar5 + 0x10));
      *(undefined4 *)(iVar5 + 0x10) = 0;
      iVar5 = iVar5 + 4;
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  if (*(vm_address_t *)(param_2 + 0x30) != 0) {
    _vm_deallocate(*(vm_map_t *)PTR_00112034,*(vm_address_t *)(param_2 + 0x30),
                   *(vm_size_t *)(param_2 + 0x38));
  }
  _gleVecFree(param_2);
  return;
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
void _gleBindBufferObject(param_1, param_2, param_3)
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
      ((void (*)())_gleCreatePluginBuffer)(param_1,iVar3 + 0x10);
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
    ((double (*)())_gleSynchronizePluginBuffer)(param_1,iVar3 + 0x10);
  }
  if ((iVar8 != 0) && (iVar4 = *(int *)(iVar8 + 8) + -1, *(int *)(iVar8 + 8) = iVar4, iVar4 == 0)) {
    ((void (*)())_gleFreeBufferObject)(param_1,iVar8);
    return;
  }
  return;
}

/* _gleOrphanBufferData @ 0xc74a8 (1088 bytes) */
void _gleOrphanBufferData(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  int param_3;
  uint param_4;
{
  int *piVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  int *piVar12;
  undefined4 *puVar13;
  int iVar14;
  
  if (*(int *)(param_1 + 0x7484) == 0) {
    uVar5 = _gleVecAlloc(0x1800);
    iVar14 = 0x80;
    *(undefined4 *)(param_1 + 0x7484) = uVar5;
    iVar9 = 0;
    do {
      iVar11 = *(int *)(param_1 + 0x7484);
      iVar8 = iVar11 + iVar9;
      iVar4 = iVar8 + 0x14;
      *(undefined4 *)(iVar8 + 0x28) = 0;
      *(int *)(iVar8 + 0x20) = iVar4;
      *(int *)(iVar8 + 0x1c) = iVar4;
      *(int *)(iVar8 + 0x18) = iVar4;
      *(undefined4 *)(iVar8 + 0x24) = 0;
      *(int *)(iVar8 + 0x14) = iVar4;
      *(undefined4 *)(iVar8 + 0x10) = 0;
      *(undefined4 *)(iVar11 + iVar9) = 0;
      iVar9 = iVar9 + 0x30;
      *(undefined4 *)(iVar8 + 4) = 0;
      *(undefined4 *)(iVar8 + 8) = 0;
      *(undefined4 *)(iVar8 + 0xc) = 0;
      iVar14 = iVar14 + -1;
    } while (iVar14 != 0);
    uVar5 = _gleVecAlloc((uint)*(byte *)(param_1 + 0x85a4) * 4 + 0x1c);
    *(undefined4 *)(param_1 + 0x7464) = uVar5;
  }
  if (param_2[8] != 0) {
    piVar6 = *(int **)(param_1 + 0x7464);
    if (piVar6 == (int *)0x0) {
      piVar6 = (int *)_gleVecAlloc((uint)*(byte *)(param_1 + 0x85a4) * 4 + 0x1c);
    }
    else {
      *(undefined4 *)(param_1 + 0x7464) = 0;
    }
    iVar9 = 0;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      iVar14 = param_1 + 0x10000;
      piVar12 = piVar6 + 7;
      puVar10 = param_2;
      do {
        piVar1 = (int *)(iVar14 + -0x777c);
        uVar5 = *puVar10;
        iVar9 = iVar9 + 1;
        puVar10 = puVar10 + 1;
        puVar13 = (undefined4 *)(iVar14 + -0x7a54);
        iVar14 = iVar14 + 0x2e0;
        (**(code **)(*piVar1 + 0x1e8))(*puVar13,uVar5,piVar12);
        piVar12 = piVar12 + 1;
      } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
    piVar6[4] = param_2[8];
    piVar6[5] = param_2[9];
    *(undefined2 *)(piVar6 + 6) = *(undefined2 *)(param_2 + 0xb);
    param_2[9] = 0;
    param_2[8] = 0;
    uVar7 = piVar6[5];
    iVar8 = (uVar7 >> 0xc & 0x7f) * 0x30;
    iVar9 = *(int *)(param_1 + 0x7474);
    iVar4 = *(int *)(param_1 + 0x7484) + iVar8;
    piVar6[3] = iVar9;
    puVar10 = *(undefined4 **)(iVar4 + 0x18);
    *(int **)(iVar9 + 8) = piVar6;
    piVar6[1] = (int)puVar10;
    *puVar10 = piVar6;
    piVar6[2] = param_1 + 0x7468;
    *piVar6 = iVar4 + 0x14;
    iVar9 = *(int *)(param_1 + 0x7454);
    iVar14 = *(int *)(param_1 + 0x7458);
    *(int **)(iVar4 + 0x18) = piVar6;
    *(int **)(param_1 + 0x7474) = piVar6;
    *(uint *)(param_1 + 0x7454) = iVar9 + uVar7;
    *(int *)(param_1 + 0x7458) = iVar14 + 1;
    *(int *)(iVar8 + *(int *)(param_1 + 0x7484)) =
         *(int *)(iVar8 + *(int *)(param_1 + 0x7484)) + piVar6[5];
    iVar8 = iVar8 + *(int *)(param_1 + 0x7484);
    *(int *)(iVar8 + 4) = *(int *)(iVar8 + 4) + 1;
  }
  iVar14 = (param_3 + 0xfffU >> 0xc & 0x7f) * 0x30;
  iVar9 = iVar14 + *(int *)(param_1 + 0x7484);
  piVar6 = *(int **)(iVar9 + 0x14);
  while( true ) {
    if (piVar6 == (int *)(iVar9 + 0x14)) goto LAB_000c7884;
    if ((*(ushort *)(piVar6 + 6) == param_4) && ((param_3 + 0xfffU & 0xfffff000) == piVar6[5]))
    break;
    piVar6 = (int *)*piVar6;
  }
  iVar9 = 0;
  if (*(char *)(param_1 + 0x85a4) == '\0') goto LAB_000c7744;
  puVar13 = piVar6 + 7;
  puVar10 = (undefined4 *)(param_1 + 0x85ac);
  bVar3 = true;
  do {
    bVar2 = false;
    if ((bVar3) && (iVar4 = (**(code **)(param_1 + 0x4834))(*puVar10,*puVar13), iVar4 != 0)) {
      bVar2 = true;
    }
    iVar9 = iVar9 + 1;
    puVar10 = puVar10 + 0xb8;
    puVar13 = puVar13 + 1;
    bVar3 = bVar2;
  } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  if (bVar2) {
LAB_000c7744:
    iVar4 = piVar6[3];
    puVar10 = (undefined4 *)piVar6[1];
    uVar5 = *piVar6;
    *(int *)(iVar4 + 8) = piVar6[2];
    *puVar10 = uVar5;
    iVar9 = piVar6[2];
    uVar5 = piVar6[4];
    *(undefined4 **)(*piVar6 + 4) = puVar10;
    *(int *)(iVar9 + 0xc) = iVar4;
    piVar6[2] = (int)piVar6;
    piVar6[3] = (int)piVar6;
    *piVar6 = (int)piVar6;
    piVar6[1] = (int)piVar6;
    param_2[8] = uVar5;
    param_2[9] = piVar6[5];
    *(undefined2 *)(param_2 + 0xb) = *(undefined2 *)(piVar6 + 6);
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      puVar10 = piVar6 + 7;
      iVar4 = param_1 + 0x10000;
      iVar9 = 0;
      do {
        iVar8 = iVar9 + 1;
        param_2[iVar9 + 0xe] = param_2[iVar9 + 0xe] | 3;
        piVar12 = (int *)(iVar4 + -0x777c);
        uVar5 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar13 = (undefined4 *)(iVar4 + -0x7a54);
        iVar4 = iVar4 + 0x2e0;
        (**(code **)(*piVar12 + 0x1ec))(*puVar13,param_2[iVar9],uVar5);
        iVar9 = iVar8;
      } while (iVar8 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
    *(int *)(param_1 + 0x7454) = *(int *)(param_1 + 0x7454) - piVar6[5];
    *(int *)(param_1 + 0x745c) = *(int *)(param_1 + 0x745c) + 1;
    *(int *)(param_1 + 0x7458) = *(int *)(param_1 + 0x7458) + -1;
    iVar9 = *(int *)(param_1 + 0x7464);
    *(int *)(iVar14 + *(int *)(param_1 + 0x7484)) =
         *(int *)(iVar14 + *(int *)(param_1 + 0x7484)) - piVar6[5];
    iVar4 = iVar14 + *(int *)(param_1 + 0x7484);
    *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) + -1;
    iVar14 = iVar14 + *(int *)(param_1 + 0x7484);
    *(int *)(iVar14 + 8) = *(int *)(iVar14 + 8) + 1;
    if (iVar9 == 0) {
      *(int **)(param_1 + 0x7464) = piVar6;
    }
    else {
      _gleVecFree(piVar6);
    }
  }
  else {
LAB_000c7884:
    if (piVar6 != (int *)0x0) {
      iVar14 = iVar14 + *(int *)(param_1 + 0x7484);
      *(int *)(iVar14 + 0xc) = *(int *)(iVar14 + 0xc) + 1;
      *(int *)(param_1 + 0x7460) = *(int *)(param_1 + 0x7460) + 1;
    }
  }
  if (0x4000000 < *(int *)(param_1 + 0x7454)) {
    ((void (*)())_gleCleanupOrphans)(param_1);
    return;
  }
  return;
}

/* _gleCleanupOrphans @ 0xc78e8 (300 bytes) */
void _gleCleanupOrphans(param_1)
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
void _gleSynchronizePluginBuffers(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x4a60);
  iVar2 = *(int *)(iVar1 + 0x358);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x40) != 0)) {
    ((double (*)())_gleSynchronizePluginBuffer)(param_1,iVar2 + 0x10);
  }
  iVar1 = *(int *)(iVar1 + 0x35c);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x40) != 0)) {
    ((double (*)())_gleSynchronizePluginBuffer)(param_1,iVar1 + 0x10);
  }
  iVar1 = *(int *)(param_1 + 0x4a68);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x40) != 0)) {
    ((double (*)())_gleSynchronizePluginBuffer)(param_1,iVar1 + 0x10);
  }
  iVar1 = *(int *)(param_1 + 0x4a6c);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x40) != 0)) {
    ((double (*)())_gleSynchronizePluginBuffer)(param_1,iVar1 + 0x10);
    return;
  }
  return;
}

/* _gleSynchronizePluginBuffer @ 0xc7ae0 (160 bytes) */
double _gleSynchronizePluginBuffer(param_1, param_2)
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
void _gleReclaimBufferObjectResources(param_1)
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
          ((double (*)())_gleSynchronizePluginBuffer)(param_1,piVar6 + 4);
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
int _gleSwitchToRenderer(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar5;
  uint uVar6;
  undefined4 *a2;
  
  iVar3 = param_2 * 0x2e0 + param_1;
  uVar1 = *(undefined4 *)(iVar3 + 0x85ac);
  *(int *)(param_1 + 0x468c) = iVar3 + 0x85b0;
  *(undefined4 *)(param_1 + 0x4688) = uVar1;
  a2 = (undefined4 *)(param_1 + 0x310);
  _memcpy(param_1 + 0x4754,*(int *)(iVar3 + 0x8884) + 0x114,0xf4);
  (**(code **)(param_1 + 0x4784))
            (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,param_1 + 0x471c);
  uVar5 = *(uint *)(param_1 + 0x31c) | 0x7ffffff;
  *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x3ffffff;
  *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 0xfffffffd;
  *(uint *)(param_1 + 0x31c) = uVar5;
  *(undefined4 *)(param_1 + 800) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x310) = 0xffffffff;
  uVar5 = (**(code **)(param_1 + 0x4788))
                    (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,a2,in_r6,in_r7,in_r8,uVar5);
  iVar3 = 0x13;
  do {
    *a2 = 0;
    a2 = a2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar2 = (uVar5 ^ 8) >> 3 & 1;
  if (uVar2 != *(byte *)(param_1 + 0x759d)) {
    *(char *)(param_1 + 0x759d) = (char)uVar2;
    ((void (*)())_gleUpdateFramebufferOperationFuncs)(param_1);
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
double _gleRecoverySaveState(param_1, param_2)
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
void _gleSwitchRenderersReadBuffers(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  int iVar1;
  uint uVar2;
  int iVar3;
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
    ((double (*)())_gleRecoverySaveState)(param_1,auStack_90);
    iVar3 = *(int *)(param_1 + 0x1ba8);
    param_3[1] = iVar3;
    iVar1 = *(int *)(param_1 + 0x1bac);
    *param_3 = iVar1;
    iVar1 = _malloc(iVar3 * iVar1 * 4);
    param_3[2] = iVar1;
    fparam_1 = (double)(**(double ( **)(int,int,int,int,int,int,int,int))(param_1 + 0x46a0))
                                 (*(undefined4 *)(param_1 + 0x4688), 0, 0, param_3[1], *param_3, 0x80e1, 0x8367, iVar1);
    if (*(int *)(param_2 * 0x2e0 + param_1 + 0x85ec) != 0) {
      iVar1 = _malloc(param_3[1] * *param_3 * 4);
      param_3[4] = iVar1;
      fparam_1 = (double)(**(double ( **)(int,int,int,int,int,int,int,int))(param_1 + 0x46a0))
                                   (*(undefined4 *)(param_1 + 0x4688), 0, 0, param_3[1], *param_3, 0x1902, 0x1406, iVar1);
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
void _gleSwitchRenderersWriteBuffers(param_1, param_2, param_3)
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
    dVar3 = (double)((double (*)())_gleRecoverySaveState)(param_1,auStack_a0);
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
  ((void (*)())_gleSwitchRenderersReadBuffers)(param_1,(uint)*(byte *)(param_1 + 0x85a5),&local_30);
  iVar1 = uVar3 * 0x2e0 + param_1;
  (**(code **)(*(int *)(iVar1 + 0x8884) + 0x138))
            (*(undefined4 *)(iVar1 + 0x85ac),*(undefined4 *)(param_1 + 0x484c),
             *(undefined4 *)(param_1 + 0x4848),0);
  fparam_1 = (double)((int (*)())_gleSwitchToRenderer)(param_1,uVar3);
  ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  ((void (*)())_gleSwitchRenderersWriteBuffers)(param_1,uVar3,&local_30);
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
void _gleReclaimContextResources(param_1)
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
    _pthread_mutex_lock(*(int *)(param_1 + 0x5148) + 0x8028);
  }
  ((void (*)())_gleReclaimDisplayListResources)(param_1);
  _gleReclaimTextureObjectResources(param_1);
  ((void (*)())_gleReclaimBufferObjectResources)(param_1);
  _gleReclaimVertexArrayResources(param_1);
  if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
    _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
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
double _gleSwitchToNonRevertRenderer(param_1)
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
    ((void (*)())_gleSynchronizePluginBuffers)(param_1);
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
      ((void (*)())_gleSwitchRenderersReadBuffers)(param_1,(uint)*(byte *)(param_1 + 0x85a5),&local_40);
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
      ((void (*)())_gleSwitchRenderersWriteBuffers)(param_1,uVar6,&local_40);
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
double _gleUpdateDispatchCodeChange(param_1, param_2)
  int param_1;
  uint param_2;
{
  byte bVar1;
  undefined *a6;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 a3;
  undefined4 in_r7;
  uint uVar5;
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
    uVar3 = (uint)*(byte *)(param_1 + 0x7581);
    if (uVar3 == 0) {
      bVar1 = *(byte *)(param_1 + 0x85a5);
      uVar5 = (uint)bVar1;
      if (uVar5 != 0xff) {
        local_40 = uVar3;
        local_3c = uVar3;
        local_38 = uVar3;
        local_34 = uVar3;
        local_30 = uVar3;
        ((void (*)())_gleSwitchRenderersReadBuffers)(param_1,(uint)*(byte *)(param_1 + 0x85a6),&local_40);
        a3 = 0;
        iVar4 = uVar5 * 0x2e0 + param_1;
        uVar3 = (**(code **)(*(int *)(iVar4 + 0x8884) + 0x138))
                          (*(undefined4 *)(iVar4 + 0x85ac),*(undefined4 *)(param_1 + 0x484c),
                           *(undefined4 *)(param_1 + 0x4848));
        if ((uVar3 < 5) && (uVar5 != *(byte *)(param_1 + 0x85a8))) {
          _gleSynchronizePluginTextures(param_1);
          ((void (*)())_gleSynchronizePluginBuffers)(param_1);
          *(byte *)(param_1 + 0x85a8) = bVar1;
          fparam_1 = (double)((int (*)())_gleSwitchToRenderer)(param_1,(uint)*(byte *)(param_1 + 0x85a5));
          ((void (*)())_gleUpdateDepthRangeData)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff88,
                     in_stack_ffffff90,in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8);
          _gleUpdatePolyMode(param_1);
          ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1_00,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
          _gleUpdateTextureTransform(param_1);
          puVar2 = PTR__gleSetEyeInterpFunc_0011203c;
          a6 = PTR__gleSetClipInterpFunc_00112038;
          uVar3 = *(uint *)(param_1 + 0x31c) | 0x7ffffff;
          *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x3ffffff;
          *(undefined **)(param_1 + 0x49c8) = puVar2;
          *(undefined **)(param_1 + 0x49cc) = a6;
          *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 0xfffffffd;
          *(uint *)(param_1 + 0x31c) = uVar3;
          *(undefined4 *)(param_1 + 800) = 0xffffffff;
          *(undefined4 *)(param_1 + 0x310) = 0xffffffff;
          uVar3 = (**(code **)(param_1 + 0x4788))
                            (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,param_1 + 0x310,a3,
                             in_r7,0xffffffff,a6,uVar3);
          if ((uVar3 & 8) == 0) {
            ((void (*)())_gleSwitchRenderersWriteBuffers)(param_1,(uint)*(byte *)(param_1 + 0x85a5),&local_40);
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
  uVar3 = (param_2 ^ 8) >> 3 & 1;
  if (uVar3 != *(byte *)(param_1 + 0x759d)) {
    *(char *)(param_1 + 0x759d) = (char)uVar3;
    ((void (*)())_gleUpdateFramebufferOperationFuncs)(param_1);
  }
  return;
}

/* _gleUpdateFramebufferOperationFuncs @ 0xc8db0 (928 bytes) */
void _gleUpdateFramebufferOperationFuncs(param_1)
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
void _gleReclaimDisplayListResources()
{
  return;
}

/* _gleQuickOptimizeDisplayList @ 0xc9154 (1292 bytes) */
void _gleQuickOptimizeDisplayList(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  vm_address_t *pvVar2;
  int *piVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  vm_address_t vVar7;
  vm_address_t vVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  vm_address_t local_60;
  int local_5c [4];
  
  uVar13 = *(uint *)(param_3 + 0x10);
  puVar16 = (undefined4 *)(param_3 + 0x2c);
  piVar9 = *(int **)(param_3 + 0x14);
  uVar15 = 0;
  piVar3 = piVar9;
  puVar17 = puVar16;
  if (uVar13 == 0) {
    return;
  }
  while( true ) {
    puVar1 = (undefined *)*puVar17;
    iVar5 = 0;
    iVar11 = *(int *)(((uint)puVar1 & 0x7c) + _gleDisplayListFunctionHash);
    while ((iVar11 != 0 && (iVar5 = iVar11, puVar1 != *(undefined **)(iVar11 + 4)))) {
      iVar5 = *(int *)(iVar11 + 0xc);
      iVar11 = iVar5;
    }
    if ((puVar1 == PTR__glDrawArraysOrElements_ListExec_00112144) && (0x20 < (int)puVar17[7]))
    break;
    if ((iVar5 == 0) || (*(undefined **)(iVar5 + 4) != PTR__glWeightARB_ListExec_0011214c)) {
      puVar17 = (undefined4 *)((int)puVar17 + *piVar3);
    }
    else {
      puVar17 = puVar17 + puVar17[1] + 2;
    }
    uVar15 = uVar15 + 1;
    piVar3 = piVar3 + 1;
    if (uVar13 <= uVar15) {
      return;
    }
  }
  vVar7 = 0;
  iVar5 = 0;
  _gleNewList(param_1,param_2,((unsigned char *)0x00001300U));
  puVar1 = PTR__glWeightARB_ListExec_0011214c;
  local_5c[0] = 0;
  local_60 = 0;
  uVar15 = 0;
  if (uVar13 != 0) {
    iVar11 = 0;
    do {
      puVar4 = (undefined *)*puVar16;
      iVar12 = 0;
      iVar6 = *(int *)(((uint)puVar4 & 0x7c) + _gleDisplayListFunctionHash);
      while ((iVar6 != 0 && (iVar12 = iVar6, puVar4 != *(undefined **)(iVar6 + 4)))) {
        iVar12 = *(int *)(iVar6 + 0xc);
        iVar6 = iVar12;
      }
      if (puVar4 == PTR__glDrawArraysOrElements_ListExec_00112144) {
        iVar6 = 0x2c;
        iVar10 = puVar16[7] * puVar16[8];
        if (local_5c[0] < iVar10 + 0x2c) {
          iVar6 = 0x40;
          if (local_60 != 0) {
            _CloseCurrentVAR(param_1,iVar5,vVar7,&local_60,local_5c);
          }
          pvVar2 = (vm_address_t *)
                   _gleAddListItemWithFree
                             (param_1,
                              PTR__gleSetupAndDrawArraysOrElementsOutOfLine_ListExec_00112140,0x10,
                              PTR__gleOptimizedListFreeFunc_00110ccc,4);
          local_5c[0] = iVar10 + 0x40;
          iVar5 = (int)pvVar2 - *(int *)(param_1 + 0x53e8);
          if (local_5c[0] < 0x100001) {
            local_5c[0] = 0x100000;
            uVar14 = 0x100000;
          }
          else {
            uVar14 = (uint)(((unsigned char *)0x0000103f) + iVar10) & 0xfffff000;
          }
          _vm_allocate(*(vm_map_t *)PTR_00112034,&local_60,uVar14,1);
          *pvVar2 = local_60;
          *(uint *)(local_60 + 0xc) = uVar14;
          *(undefined4 *)*pvVar2 = 4;
          *(uint *)*pvVar2 = *(uint *)*pvVar2 | 2;
          vVar7 = *pvVar2 + 0x14;
          vVar8 = local_60;
        }
        else {
          piVar3 = (int *)_gleAddListItem(param_1,
                                          PTR__gleDrawArraysOrElementsOutOfLine_ListExec_0011213c,8)
          ;
          *piVar3 = (int)piVar3 + (-iVar5 - *(int *)(param_1 + 0x53e8));
          piVar3[1] = vVar7 - local_60;
          vVar8 = vVar7;
        }
        local_5c[0] = local_5c[0] - (iVar10 + iVar6);
        vVar8 = vVar8 + iVar10 + iVar6;
        _memcpy(vVar7,puVar16 + 6,iVar10 + 0x2c);
        vVar7 = vVar8;
        if ((iVar12 == 0) || (*(undefined **)(iVar12 + 4) != puVar1)) {
          iVar12 = *(int *)(iVar11 + (int)piVar9);
          goto LAB_000c9558;
        }
LAB_000c9540:
        puVar16 = puVar16 + puVar16[1] + 2;
      }
      else {
        if (((puVar4 == PTR__glCallList_ListExec_00112138) ||
            (puVar4 == PTR__glBindVertexArrayEXT_ListExec_00112134)) ||
           (puVar4 == PTR__glVertexArrayParameteriEXT_ListExec_00112130)) {
          if (local_60 != 0) {
            _CloseCurrentVAR(param_1,iVar5,vVar7,&local_60,local_5c);
            puVar4 = (undefined *)*puVar16;
          }
          uVar14 = *(int *)(iVar11 + (int)piVar9) - 4;
          iVar10 = _gleAddListItem(param_1,puVar4,uVar14);
          iVar6 = 0;
          for (uVar14 = uVar14 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
            *(undefined4 *)(iVar10 + iVar6 * 4) = puVar16[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
        }
        else {
          uVar14 = *(int *)(iVar11 + (int)piVar9) - 4;
          iVar10 = _gleAddListItem(param_1,puVar4,uVar14);
          iVar6 = 0;
          for (uVar14 = uVar14 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
            *(undefined4 *)(iVar10 + iVar6 * 4) = puVar16[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
        }
        if ((iVar12 != 0) && (*(undefined **)(iVar12 + 4) == puVar1)) goto LAB_000c9540;
        iVar12 = *(int *)(iVar11 + (int)piVar9);
LAB_000c9558:
        puVar16 = (undefined4 *)((int)puVar16 + iVar12);
      }
      uVar15 = uVar15 + 1;
      iVar11 = iVar11 + 4;
    } while (uVar15 < uVar13);
  }
  if (local_60 != 0) {
    _CloseCurrentVAR(param_1,iVar5,vVar7,&local_60,local_5c);
  }
  iVar5 = *(int *)(param_1 + 0x5148);
  *(undefined4 *)(param_1 + 0x5408) = 0;
  iVar11 = iVar5 + 0x300c;
  if (*(char *)(iVar5 + 0x8024) != '\0') {
    _pthread_mutex_lock(iVar5 + 0x8028);
  }
  iVar12 = *(int *)(param_1 + 0x53e8);
  iVar5 = _gleIsHashName(iVar11,*(undefined4 *)(iVar12 + 4));
  if (iVar5 == 0) {
    _gleAddHashNameAndObject(param_1,iVar11,iVar12);
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
  if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
    _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
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
void _gleDrawPixelsFastLoadColorTables(param_1, param_2)
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
void _CopySourceSubImageToTexture(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,int param_13,int param_14,undefined4 param_15,undefined4 param_16,undefined4 param_17,undefined4 param_18,int param_19,undefined4 param_20,float fparam_1,float fparam_2,double fparam_3,float fparam_4)
{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  float dVar7;
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
            (param_1,param_4,param_5,param_2,param_3,param_19,&local_60,piVar5,&local_70,auStack_6c,
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
  dVar8 = (double)*(float *)(param_1 + 0x31ac);
  local_c0 = 2;
  local_bc = 0;
  if (((double)dVar8 <= DOUBLE_00108dc8) || (DOUBLE_00108d68 <= (double)dVar8)) {
    local_b8 = 0x6efff;
  }
  else {
    local_b8 = 0x6ffff;
  }
  if ((char)param_20 != '\0') {
    local_b8 = local_b8 | 0x10000;
    ((void (*)())_gleDrawPixelsFastLoadColorTables)(param_1,&local_e0);
    dVar8 = (double)*(float *)(param_1 + 0x31ac);
  }
  local_ac = (float)fparam_1;
  local_74 = 1;
  local_a8 = (float)fparam_2;
  if (param_19 != 0) {
    if (*(char *)(param_19 + 0x18) != '\0') {
      local_bc = local_bc | 1;
    }
    if (*(char *)(param_19 + 0x19) != '\0') {
      local_bc = local_bc | 4;
    }
  }
  dVar7 = (double)FLOAT_00108e50;
  uVar6 = *(undefined4 *)(param_1 + 0x31a8);
  *(undefined4 *)(param_1 + 0x31a8) = 0x3f800000;
  if ((double)dVar7 <= (double)dVar8) {
    local_50 = 0x3f800000;
    if (1.0 < (double)dVar8) goto LAB_000c99b8;
  }
  else if ((double)dVar8 < (double)FLOAT_00108e58) goto LAB_000c99b8;
  if ((double)FLOAT_00108e50 <= (double)dVar8) {
    fparam_4 = (double)(fparam_4 * dVar8);
  }
  else {
    fparam_4 = (double)(fparam_4 * -dVar8);
  }
LAB_000c99b8:
  *(float *)(param_1 + 0x31ac) = (float)fparam_4;
  local_b4 = param_7;
  local_b0 = param_8;
  _glgProcessPixels(param_1 + 0x31a8,&local_e0,puVar1,puVar2,param_3,iVar3,iVar4,piVar5);
  *(float *)(param_1 + 0x31ac) = (float)(double)dVar8;
  *(undefined4 *)(param_1 + 0x31a8) = uVar6;
  FUN_00008b68();
  return;
}

/* _gleInitDrawPixelsShareObject @ 0xc99dc (1036 bytes) */
void _gleInitDrawPixelsShareObject(param_1, param_2)
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
    ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar11 + 0x10,in_r5,in_r6,in_r7,in_r8,uVar5,fparam_1,in_f2,in_f3,in_f4,in_f5,
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
        ((double (*)())_gleUpdateDispatchCodeChange)(param_1,uVar10);
      }
    }
    else {
      ((double (*)())_gleSwitchToNonRevertRenderer)(param_1);
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
void _gleDrawPixelsRestoreState(param_1, param_2, param_3)
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
uint _pixelBoundaryBottomLeft(float fparam_1)
{
  uint uVar1;
  
  uVar1 = (uint)(int)fparam_1;
  if ((fparam_1 - (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - DOUBLE_00108d58)) <=
      FLOAT_00108e90) {
    return uVar1;
  }
  return uVar1 + 1;
}

/* _pixelBoundaryTopRight @ 0xca2d8 (92 bytes) */
uint _pixelBoundaryTopRight(float fparam_1)
{
  uint uVar1;
  
  uVar1 = (uint)(int)fparam_1;
  if ((fparam_1 - (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - DOUBLE_00108d58)) <=
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
  int param_6;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  char cVar8;
  float fVar9;
  int iVar10;
  int iVar11;
  double dVar12;
  double dVar13;
  int *piVar14;
  uint uVar15;
  int iVar16;
  int *piVar17;
  int *piVar18;
  int iVar19;
  undefined4 a1;
  undefined4 a1_00;
  undefined4 a1_01;
  undefined4 a1_02;
  undefined4 uVar20;
  int iVar21;
  int iVar22;
  undefined2 uVar24;
  undefined4 *puVar23;
  int iVar25;
  uint uVar26;
  int iVar27;
  uint uVar28;
  uint *puVar29;
  int iVar30;
  uint uVar31;
  uint uVar32;
  double dVar33;
  double fparam_1;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double dVar34;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  float dVar35;
  float dVar36;
  double fparam_3;
  double fparam_1_00;
  double dVar37;
  double fparam_3_00;
  double f2;
  double fparam_4;
  double fparam_3_01;
  float dVar38;
  double fparam_2;
  double dVar39;
  undefined4 in_stack_fffffd90;
  undefined4 in_stack_fffffd94;
  undefined4 in_stack_fffffd98;
  undefined4 in_stack_fffffd9c;
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
  int local_ec;
  int local_e8;
  int local_e4;
  int *local_e0;
  int local_dc;
  int *local_d8;
  
  fparam_3_01 = (double)*(float *)(param_1 + 0x31ac);
  local_ec = 0;
  fparam_3_00 = (double)*(float *)(param_1 + 0x31a8);
  local_234 = *(float *)(param_1 + 0x2e0);
  dVar39 = (double)local_234;
  fVar9 = *(float *)(param_1 + 0x2e4);
  fparam_1_00 = (double)fVar9;
  f2 = (double)*(float *)(param_1 + 0x2e8);
  dVar37 = fparam_3_01;
  if (fparam_3_01 < (double)FLOAT_00108e50) {
    dVar37 = -fparam_3_01;
  }
  fVar2 = FLOAT_00108e54;
  dVar12 = fparam_3_00;
  if (fparam_3_00 < (double)FLOAT_00108e50) {
    fVar2 = FLOAT_00108e58;
    dVar12 = -fparam_3_00;
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
  uVar31 = 0;
  uVar15 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xb4);
  if (uVar15 != 0) {
    piVar17 = (int *)(param_1 + 0x3534);
    do {
      iVar16 = *piVar17;
      piVar17 = piVar17 + 0x1f;
      if (iVar16 != 0) {
        return 0;
      }
      uVar31 = uVar31 + 1;
    } while (uVar31 < uVar15);
  }
  if (param_4 - 0x1901U < 2) {
    return 0;
  }
  iVar16 = param_4;
  iVar21 = param_5;
  iVar22 = param_6;
  local_e8 = param_6;
  iVar19 = ((int (*)())_gleDrawPixelsFastPickTextureType)(param_5);
  uVar31 = param_2;
  uVar15 = param_3;
  if (((*(uint *)(param_1 + 0x3410) & 0x1ff) == 0) &&
     (iVar25 = param_1 + 0x31cc, iVar27 = param_4, (*(uint *)(param_1 + 0x3414) & 0xff0000) == 0))
  goto LAB_000ca704;
  if (((*(uint *)(param_1 + 0x3410) & 2) == 0) || (*(short *)(param_1 + 0x3308) != -0x7fea)) {
    if (((*(uint *)(param_1 + 0x3410) & 4) != 0) && (*(short *)(param_1 + 0x3348) == -0x7fea)) {
      iVar21 = *(int *)(param_1 + 0x3354);
      iVar16 = *(int *)(param_1 + 0x3350);
      goto LAB_000ca634;
    }
  }
  else {
    iVar21 = *(int *)(param_1 + 0x3314);
    iVar16 = *(int *)(param_1 + 0x3310);
LAB_000ca634:
    uVar15 = (param_3 - iVar21) + 1;
    uVar31 = (param_2 - iVar16) + 1;
  }
  iVar16 = _glePixelBytes(0x80e1,iVar19);
  local_ec = _gleVecAlloc(iVar16 * uVar31 * uVar15);
  iVar16 = _glePixelBytes(0x80e1,iVar19);
  iVar27 = 0x80e1;
  iVar25 = 0;
  ((void (*)())_CopySourceSubImageToTexture)(param_1,param_2,param_3,param_4,param_5,param_6,param_2,param_3,uVar31 * iVar16,0x80e1,
             iVar19,local_ec,0,0,in_stack_fffffd90,in_stack_fffffd94,in_stack_fffffd98,
             in_stack_fffffd9c,param_1 + 0x31cc,1,(double)FLOAT_00108e50,(double)FLOAT_00108e50,
             fparam_3,fparam_4);
  local_e8 = local_ec;
  iVar16 = param_4;
  iVar21 = param_5;
  iVar22 = param_6;
  param_5 = iVar19;
LAB_000ca704:
  puVar29 = (uint *)(param_1 + 0x7488);
  if (*(int *)(param_1 + 0x74a0) == 0) {
    ((void (*)())_gleInitDrawPixelsShareObject)(param_1,puVar29);
  }
  uVar32 = 0;
  *(int *)(param_1 + 0x7498) = iVar19;
  if (*(int *)(param_1 + 0x7490) != 0) {
    do {
      iVar10 = uVar32 * 4;
      uVar32 = uVar32 + 1;
      *(short *)(*(int *)(iVar10 + *(int *)(param_1 + 0x74a0)) + 0xd6) = (short)iVar19;
    } while (uVar32 < *(uint *)(param_1 + 0x7490));
  }
  local_f0 = ((int (*)())_gleDrawPixelsSaveState)(param_1,auStack_210);
  local_224 = 0;
  dVar38 = (double)FLOAT_00108f18;
  if (fparam_3 == (double)FLOAT_00108e54) {
    uStack_11c = ((uint (*)())_pixelBoundaryTopRight)(dVar39);
    uStack_11c = uStack_11c ^ 0x80000000;
    local_120 = 0x43300000;
    uVar32 = uStack_11c;
  }
  else {
    uStack_114 = ((uint (*)())_pixelBoundaryBottomLeft)(dVar39);
    uStack_114 = uStack_114 ^ 0x80000000;
    local_118 = 0x43300000;
    uVar32 = uStack_114;
  }
  dVar39 = DOUBLE_00108d58;
  uVar26 = 0;
  if (0 < (int)uVar31) {
    local_dc = param_1 + 0x10000;
    local_d8 = (int *)(param_1 + 0x310);
    local_244 = (float)((double)CONCAT44(0x43300000,uVar32) - DOUBLE_00108d58);
    do {
      uStack_11c = uVar31 ^ 0x80000000;
      local_118 = 0x43300000;
      uStack_114 = local_224 ^ 0x80000000;
      local_120 = 0x43300000;
      dVar35 = (double)(float)((double)CONCAT44(0x43300000,uStack_114) - dVar39);
      fVar2 = (dVar35 + dVar38);
      if ((float)((double)CONCAT44(0x43300000,uStack_11c) - dVar39) < fVar2) {
        local_110 = 0x43300000;
        uStack_10c = uVar31 - local_224 ^ 0x80000000;
        dVar38 = (double)(float)((double)CONCAT44(0x43300000,uStack_10c) - dVar39);
        fVar2 = (dVar35 + dVar38);
      }
      dVar35 = (double)FLOAT_00108f18;
      fVar4 = (float)((double)(float)((double)dVar38 * dVar12) * fparam_3 + (double)local_234);
      uStack_10c = ((int (*)())_pixelCenters)((double)local_234,(double)fVar4,fparam_3_00);
      local_110 = 0x43300000;
      uStack_10c = uStack_10c ^ 0x80000000;
      local_108 = (longlong)(int)fVar2;
      local_22c = 0;
      fVar5 = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_10c) - dVar39) * fparam_3 +
                     (double)local_244);
      if (fparam_4 == (double)FLOAT_00108e54) {
        uVar32 = ((uint (*)())_pixelBoundaryTopRight)(fparam_1_00);
        uVar32 = uVar32 ^ 0x80000000;
      }
      else {
        uStack_114 = ((uint (*)())_pixelBoundaryBottomLeft)(fparam_1_00);
        local_118 = 0x43300000;
        uStack_114 = uStack_114 ^ 0x80000000;
        uVar32 = uStack_114;
      }
      dVar13 = DOUBLE_00108d58;
      uVar28 = 0;
      if (0 < (int)uVar15) {
        local_e4 = local_dc;
        local_e0 = local_d8;
        local_24c = (float)((double)CONCAT44(0x43300000,uVar32) - dVar39);
        local_23c = fVar9;
        do {
          uStack_114 = uVar15 ^ 0x80000000;
          local_110 = 0x43300000;
          uStack_10c = local_22c ^ 0x80000000;
          local_118 = 0x43300000;
          dVar36 = (double)(float)((double)CONCAT44(0x43300000,uStack_10c) - dVar13);
          fVar3 = (dVar36 + dVar35);
          if ((float)((double)CONCAT44(0x43300000,uStack_114) - dVar13) < fVar3) {
            local_120 = 0x43300000;
            uStack_11c = uVar15 - local_22c ^ 0x80000000;
            dVar35 = (double)(float)((double)CONCAT44(0x43300000,uStack_11c) - dVar13);
            fVar3 = (dVar36 + dVar35);
          }
          dVar36 = (double)(float)((double)dVar35 * dVar37);
          fVar6 = (float)((double)dVar36 * fparam_4 + (double)local_23c);
          uStack_10c = ((int (*)())_pixelCenters)((double)local_23c,(double)fVar6,fparam_3_01);
          iVar10 = local_e4;
          local_110 = 0x43300000;
          uStack_10c = uStack_10c ^ 0x80000000;
          local_108 = (longlong)(int)fVar3;
          fVar7 = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_10c) - dVar13) *
                          fparam_4 + (double)local_24c);
          if ((double)FLOAT_00108e54 <= (double)dVar38) {
            dVar34 = (double)dVar36;
            if ((double)dVar35 < (double)dVar36) {
              dVar34 = (double)dVar35;
            }
            if ((double)FLOAT_00108e54 <= dVar34) {
              uVar32 = 0;
              if (*(char *)(local_e4 + -0x7a5c) != '\0') {
                iVar30 = param_1 + 0x10000;
                do {
                  iVar11 = uVar32 * 4;
                  piVar17 = (int *)(iVar30 + -0x777c);
                  uVar32 = uVar32 + 1;
                  puVar23 = (undefined4 *)(iVar30 + -0x7a54);
                  iVar30 = iVar30 + 0x2e0;
                  (**(code **)(*piVar17 + 0x1c4))
                            (*puVar23,1,
                             *(undefined4 *)
                              (*(int *)(*puVar29 * 4 + *(int *)(param_1 + 0x74a0)) + iVar11),iVar16,
                             iVar21,iVar22,*(int *)(param_1 + 0x74a0));
                } while (uVar32 < *(byte *)(iVar10 + -0x7a5c));
              }
              local_110 = 0x43300000;
              local_108 = (longlong)(int)local_23c;
              uStack_10c = (int)local_23c ^ 0x80000000;
              fparam_2 = (double)(local_23c -
                                 (float)((double)CONCAT44(0x43300000,uStack_10c) - dVar13));
              uStack_10c = _glePixelBytes(0x80e1,iVar19);
              uStack_10c = uStack_10c ^ 0x80000000;
              local_110 = 0x43300000;
              dVar34 = (double)dVar38 * (double)(float)((double)CONCAT44(0x43300000,uStack_10c) - dVar13);
              dVar33 = (double)(float)dVar34;
              if (DOUBLE_00108d80 <= dVar33) {
                uVar32 = (uint)(int)(dVar33 - DOUBLE_00108d80);
                local_100 = (longlong)(int)uVar32;
                uVar32 = uVar32 ^ 0x80000000;
              }
              else {
                uVar32 = (uint)(int)dVar34;
                local_108 = (longlong)(int)uVar32;
              }
              iVar16 = (int)(double)dVar35;
              local_f8 = (longlong)iVar16;
              dVar34 = fparam_3;
              dVar33 = fparam_4;
              ((void (*)())_CopySourceSubImageToTexture)(param_1,uVar31,uVar15,iVar27,param_5,local_e8,(int)(double)dVar38,iVar16,uVar32,
                         0x80e1,iVar19,
                         *(int *)(0x74a4 + param_1) +
                         *puVar29 * *(int *)(param_1 + 0x748c),local_224,local_22c,in_stack_fffffd90
                         ,in_stack_fffffd94,in_stack_fffffd98,in_stack_fffffd9c,iVar25,0,
                         (double)(local_234 -
                                 (float)((double)CONCAT44(0x43300000,(int)local_234 ^ 0x80000000) -
                                        dVar13)),fparam_2,fparam_3,fparam_4);
              iVar21 = *(int *)(*puVar29 * 4 + *(int *)(param_1 + 0x74a0));
              piVar17 = (int *)(iVar21 + 0xc4);
              _gleDeletePluginTextureLevel(param_1,iVar21,piVar17,0,0);
              *(short *)(iVar21 + 0xd0) = (short)(int)(double)dVar38;
              if ((double)dVar36 <= (double)dVar35) {
                iVar16 = (int)((double)dVar35 * dVar37);
                (*(unsigned short *)((unsigned char *)&(local_100) + 6)) = (undefined2)iVar16;
                uVar24 = (*(unsigned short *)((unsigned char *)&(local_100) + 6));
                local_100 = (longlong)iVar16;
              }
              else {
                uVar24 = (short)iVar16;
              }
              *(undefined2 *)(iVar21 + 0xd2) = uVar24;
              *(undefined2 *)(iVar21 + 200) = *(undefined2 *)(iVar21 + 0xd0);
              *(undefined2 *)(iVar21 + 0xca) = *(undefined2 *)(iVar21 + 0xd2);
              uVar20 = 0x8058;
              if (iVar19 != 0x8367) {
                uVar20 = 0x8057;
              }
              iVar16 = 0;
              iVar21 = 0;
              fparam_1 = (double)_gleCreatePluginTextureLevel
                                           (param_1,*(undefined4 *)
                                                     (*puVar29 * 4 + *(int *)(param_1 + 0x74a0)),
                                            piVar17,0,0,uVar20);
              uVar32 = 0;
              if (*(char *)(iVar10 + -0x7a5c) != '\0') {
                puVar23 = (undefined4 *)(param_1 + 0x86e8);
                do {
                  iVar22 = uVar32 * 4;
                  uVar32 = uVar32 + 1;
                  *puVar23 = *(undefined4 *)
                              (*(int *)(*puVar29 * 4 + *(int *)(param_1 + 0x74a0)) + iVar22);
                  puVar23 = puVar23 + 0xb8;
                } while (uVar32 < *(byte *)(iVar10 + -0x7a5c));
              }
              iVar22 = *(int *)(param_1 + 0x50ac);
              *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 1;
              if (iVar22 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
                _gleUpdateMatrixFunc(param_1);
                fparam_1 = extraout_f1;
              }
              piVar14 = local_e0;
              if (*(char *)(param_1 + 0x4691) != '\0') {
                iVar30 = *(int *)(param_1 + 0x744c);
                cVar8 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
                if ((iVar30 != 0) && (*(int *)(iVar30 + 0xec) != 0)) {
                  ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar30 + 0x10,piVar17,iVar16,iVar21,uVar20,iVar22,fparam_1,
                             fparam_2,dVar34,dVar33,in_f5,in_f6,in_f7,in_f8);
                  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
                  fparam_1 = fparam_1;
                }
                if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000cae0c:
                  uVar32 = piVar14[3];
                }
                else {
                  iVar22 = 0;
                  piVar18 = piVar14 + 5;
                  do {
                    iVar30 = *piVar18;
                    piVar18 = piVar18 + 1;
                    if (iVar30 != 0) {
                      piVar14[3] = piVar14[3] | 0x800000;
                      break;
                    }
                    iVar22 = iVar22 + 1;
                  } while (iVar22 < 9);
                  uVar32 = piVar14[3];
                  if ((uVar32 & 0x15555) != 0) {
                    if (*(char *)(param_1 + 0x2e54) != '\0') {
                      piVar17 = (int *)0x0;
                      fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
                    }
                    if (*(char *)(param_1 + 0x3094) != '\0') {
                      piVar17 = (int *)((int)((unsigned char *)0x0) + 1);
                      fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
                    }
                    goto LAB_000cae0c;
                  }
                }
                bVar1 = cVar8 == '\0';
                if (bVar1) {
                  uVar32 = uVar32 & 0x17000000;
                }
                else {
                  uVar32 = uVar32 & 0x17ffffff;
                }
                if (bVar1) {
                  bVar1 = ((*piVar14 == 0 && piVar14[1] == 0) && uVar32 == 0) && piVar14[4] == 0;
                }
                else {
                  bVar1 = (((*piVar14 == 0 && piVar14[1] == 0) && (piVar14[2] & 0xfffffffdU) == 0)
                          && uVar32 == 0) && piVar14[4] == 0;
                }
                if (!bVar1) {
                  if (*(char *)(iVar10 + -0x7a58) == *(char *)(iVar10 + -0x7a5a)) {
                    uVar32 = (**(code **)(param_1 + 0x4788))
                                       (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar14);
                    if ((((uVar32 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
                        ((uVar32 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
                       (fparam_1 = extraout_f1_01,
                       (uVar32 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
                      if ((uVar32 & 4) == 0) {
                        uVar32 = uVar32 & 0xfffffffe;
                        piVar14[3] = piVar14[3] | 0x10000000;
                      }
                      fparam_1 = (double)((double (*)())_gleUpdateDispatchCodeChange)(param_1,uVar32);
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
                    fparam_1 = (double)((double (*)())_gleSwitchToNonRevertRenderer)(param_1);
                  }
                  iVar22 = 0x13;
                  piVar17 = piVar14;
                  do {
                    *piVar17 = 0;
                    piVar17 = piVar17 + 1;
                    iVar22 = iVar22 + -1;
                  } while (iVar22 != 0);
                }
              }
              ((void (*)())_glBegin_Exec)(param_1,7,fparam_1,fparam_2,dVar34,dVar33,in_f5,in_f6,in_f7,in_f8);
              *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
              *(float *)(param_1 + 300) = *(float *)(param_1 + 0x24);
              *(undefined4 *)(param_1 + 0x120) = 0;
              *(undefined4 *)(param_1 + 0x124) = 0;
              (**(code **)(param_1 + 0x4884))
                        (param_1,a1,piVar17,iVar16,iVar21,*(undefined4 *)(param_1 + 0x4858),
                         (double)local_244,(double)local_24c,f2,(double)*(float *)(param_1 + 0x24));
              *(float *)(param_1 + 0x120) = (float)(double)dVar38;
              *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
              *(undefined4 *)(param_1 + 0x124) = 0;
              *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
              (**(code **)(param_1 + 0x4884))
                        (param_1,a1_00,piVar17,iVar16,iVar21,*(undefined4 *)(param_1 + 0x4858),
                         (double)fVar5,(double)local_24c,f2);
              *(float *)(param_1 + 0x120) = (float)(double)dVar38;
              dVar34 = (double)dVar36;
              if ((double)dVar35 < (double)dVar36) {
                dVar34 = (double)dVar35;
              }
              *(float *)(param_1 + 0x124) = (float)dVar34;
              *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
              *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
              (**(code **)(param_1 + 0x4884))
                        (param_1,a1_01,piVar17,iVar16,iVar21,*(undefined4 *)(param_1 + 0x4858),
                         (double)fVar5,(double)fVar7,f2);
              *(undefined4 *)(param_1 + 0x120) = 0;
              if ((double)dVar35 < (double)dVar36) {
                dVar36 = (double)dVar35;
              }
              *(float *)(param_1 + 0x124) = (float)(double)dVar36;
              *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
              *(float *)(param_1 + 300) = *(float *)(param_1 + 0x24);
              iVar22 = *(int *)(param_1 + 0x4858);
              (**(code **)(param_1 + 0x4884))
                        (param_1,a1_02,piVar17,iVar16,iVar21,iVar22,(double)local_244,(double)fVar7,
                         f2,(double)*(float *)(param_1 + 0x24));
              _glEnd_Exec(param_1);
              uVar32 = *puVar29;
              *puVar29 = uVar32 + 1;
              if (*(uint *)(param_1 + 0x7490) <= uVar32 + 1) {
                *puVar29 = 0;
              }
            }
          }
          uVar28 = (uint)(int)((double)(float)((double)CONCAT44(0x43300000,uVar28 ^ 0x80000000) - dVar13)
                         + (double)dVar35);
          local_f8 = (longlong)(int)uVar28;
          local_24c = fVar7;
          local_23c = fVar6;
          local_22c = (int)fVar3;
        } while ((int)uVar28 < (int)uVar15);
      }
      uStack_10c = uVar26 ^ 0x80000000;
      local_110 = 0x43300000;
      uVar26 = (uint)(int)((double)(float)((double)CONCAT44(0x43300000,uStack_10c) - dVar39) + (double)dVar38);
      local_f8 = (longlong)(int)uVar26;
      local_244 = fVar5;
      local_234 = fVar4;
      local_224 = (int)fVar2;
    } while ((int)uVar26 < (int)uVar31);
  }
  ((void (*)())_gleDrawPixelsRestoreState)(param_1,auStack_210,local_f0);
  if (local_ec != 0) {
    _gleVecFree(local_ec);
  }
  return 1;
}

/* _gleSetEnable_TEXTURE_1D @ 0xcb104 (80 bytes) */
void _gleSetEnable_TEXTURE_1D(param_1, param_2, param_3)
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
void _gleSetEnable_TEXTURE_CUBE_MAP(param_1, param_2, param_3)
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
void _gleSetEnable_SHARED_TEXTURE_PALETTE_EXT(param_1, param_2, param_3)
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
void _gleSetEnable_LINE_STIPPLE(param_1, param_2, param_3)
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
void _gleSetEnable_POLYGON_STIPPLE(param_1, param_2, param_3)
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
void _gleSetEnable_INDEX_LOGIC_OP(param_1, param_2, param_3)
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
void _gleSetEnable_COLOR_LOGIC_OP(param_1, param_2, param_3)
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

