#include "decls.h"

/* _gleIsIndex @ 0x2f1ac (20 bytes) */
int _gleIsIndex(param_1)
  int param_1;
{
  return param_1 - 0x1900U < 2;
}

/* _gleExtractPixel_RGBA_Ubyte @ 0x2f1c0 (176 bytes) */
void _gleExtractPixel_RGBA_Ubyte(param_1, param_2)
  int param_1;
  byte *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108e78;
  *(float *)(param_1 + 4) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(param_1 + 8) = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0xc) = (GH_U2F((unsigned int)((param_2[2] | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0x10) = (GH_U2F((unsigned int)((param_2[3] | 0x4b000000))) - 8388608.0) * fVar1;
  return;
}

/* _gleUpdateLightRGBASums @ 0x2f270 (1740 bytes) */
double _gleUpdateLightRGBASums(glContext, param_2, param_3)
  int glContext;
  float *param_2;
  int param_3;
{
  float float10;
  uint loopIndex3;
  float *cursor3;
  float *cursor2;
  int remaining2;
  int remaining;
  int loopIndex;
  byte bVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  int iVar6;
  undefined4 uVar7;
  uint loopIndex2;
  float fVar9;
  float fVar10;
  float fVar11;
  float *cursor;
  undefined4 uVar13;
  float fVar14;
  int iVar15;
  float fVar16;
  undefined4 uVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  int iVar22;
  double dVar23;
  double dVar24;
  float dVar25;
  float dVar26;
  float dVar27;
  
  fVar3 = param_2[0x8f];
  bVar2 = *(byte *)((int)param_2 + 0x235) | *(byte *)(param_2 + 0x8d);
  if (fVar3 == 0.0) {
    uVar19 = 0;
    fVar3 = 0.0;
  }
  else {
    uVar19 = 0;
    if (*(char *)((int)GH_F2U(fVar3) + 0x236) == '\0') {
      uVar19 = ~(uint)(*(byte *)((int)param_2 + 0x235) | *(byte *)((int)GH_F2U(fVar3) + 0x234)) & 0xff;
    }
  }
  if ((bVar2 & 0xe) != 0) {
    if ((uVar19 & 0xe) == 0xe) {
      fVar4 = *(float *)((int)GH_F2U(fVar3) + 0x1d4);
      fVar11 = *(float *)((int)GH_F2U(fVar3) + 0x1d8);
      fVar16 = *(float *)((int)GH_F2U(fVar3) + 0x1dc);
      fVar14 = *(float *)((int)GH_F2U(fVar3) + 0x1e8);
      fVar10 = *(float *)((int)GH_F2U(fVar3) + 0x1ec);
      fVar9 = *(float *)((int)GH_F2U(fVar3) + 0x1f0);
      param_2[0x74] = *(float *)((int)GH_F2U(fVar3) + 0x1d0);
      param_2[0x75] = fVar4;
      param_2[0x76] = fVar11;
      param_2[0x77] = fVar16;
      param_2[0x7a] = fVar14;
      param_2[0x7b] = fVar10;
      param_2[0x7c] = fVar9;
    }
    else {
      fVar4 = *(float *)(glContext + 0x2810) * *param_2 + param_2[0xc];
      fVar9 = *(float *)(glContext + 0x2814) * param_2[1] + param_2[0xd];
      fVar10 = *(float *)(glContext + 0x2818) * param_2[2] + param_2[0xe];
      param_2[0x7a] = fVar4;
      param_2[0x77] = param_2[7];
      param_2[0x7b] = fVar9;
      param_2[0x7c] = fVar10;
      param_2[0x74] = fVar4;
      param_2[0x75] = fVar9;
      param_2[0x76] = fVar10;
      if (*(int *)(glContext + 0x5434) == 0) {
        bVar1 = *(byte *)(param_3 * 6 + *(int *)(glContext + 0x5420) + 0x2c5);
      }
      else {
        bVar1 = *(byte *)(param_3 * 6 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2f9);
      }
      iVar21 = (bVar1 >> 3 & 0x1c) + glContext;
      iVar22 = *(int *)(glContext + 0x5424);
      *(uint *)(iVar21 + 0x324) = *(uint *)(iVar21 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(param_3 * 6 + iVar22 + 0x2c5);
      iVar22 = (bVar1 >> 3 & 0x1c) + glContext;
      *(uint *)(iVar22 + 0x348) = *(uint *)(iVar22 + 0x348) | 1 << (bVar1 & 0x1f);
    }
  }
  dVar26 = (double)param_2[0x10];
  if (((bVar2 & 1) != 0) && ((double)dVar26 != (double)param_2[0x7d])) {
    if ((uVar19 & 1) == 0) {
      param_2[0x7d] = param_2[0x10];
      if ((double)FLOAT_00108e80 < (double)dVar26) {
        dVar27 = (double)FLOAT_00108e54;
        loopIndex2 = 0;
        dVar24 = _log(DOUBLE_00108dd8);
        float10 = FLOAT_00108f44;
        cursor2 = param_2 + 0x82;
        dVar24 = _exp(dVar24 / (double)dVar26);
        dVar25 = (double)(float)dVar24;
        dVar23 = (double)FLOAT_00108f40;
        param_2[0x7e] = (float)dVar24;
        dVar24 = DOUBLE_00108de0;
        param_2[0x80] = (float)(dVar23 / (double)dVar25);
        param_2[0x7f] = float10 / (dVar27 - dVar25);
        dVar24 = _pow(dVar24,(double)dVar26);
        fVar4 = param_2[0x7e];
        param_2[0x81] = (float)(dVar24 - DOUBLE_00108d68);
        dVar24 = (double)fVar4;
        do {
          loopIndex2 = loopIndex2 + 1;
          dVar23 = _pow(dVar24,(double)dVar26);
          *cursor2 = (float)dVar23;
          cursor2 = cursor2 + 1;
          dVar24 = (double)(float)(dVar24 + (double)((dVar27 - fVar4) / float10));
        } while (loopIndex2 < 10);
        param_2[0x8c] = 1.0;
      }
      else {
        remaining = 0xb;
        param_2[0x81] = 1.0;
        param_2[0x7e] = 1.0;
        cursor3 = param_2 + 0x82;
        param_2[0x7f] = 1.0;
        param_2[0x80] = 1.0;
        do {
          *cursor3 = 1.0;
          cursor3 = cursor3 + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
      }
    }
    else {
      fVar4 = *(float *)((int)GH_F2U(fVar3) + 0x1f8);
      remaining2 = 0xb;
      fVar9 = *(float *)((int)GH_F2U(fVar3) + 0x1fc);
      cursor = param_2 + 0x82;
      fVar10 = *(float *)((int)GH_F2U(fVar3) + 0x200);
      pfVar5 = (float *)((int)GH_F2U(fVar3) + 0x208);
      fVar11 = *(float *)((int)GH_F2U(fVar3) + 0x204);
      param_2[0x7d] = *(float *)((int)GH_F2U(fVar3) + 500);
      param_2[0x7e] = fVar4;
      param_2[0x7f] = fVar9;
      param_2[0x80] = fVar10;
      param_2[0x81] = fVar11;
      do {
        fVar4 = *pfVar5;
        pfVar5 = pfVar5 + 1;
        *cursor = fVar4;
        cursor = cursor + 1;
        remaining2 = remaining2 + -1;
      } while (remaining2 != 0);
    }
  }
  uVar20 = *(uint *)(glContext + 0x30a0);
  loopIndex3 = 0;
  loopIndex = 0;
  iVar22 = glContext;
  do {
    if ((uVar20 & 1 << (loopIndex3 & 0x3f)) == 0) {
      if (uVar20 >> (loopIndex3 & 0x3f) == 0) {
        *(undefined1 *)(param_2 + 0x8d) = 0;
        return;
      }
    }
    else {
      iVar6 = (int)GH_F2U(fVar3) + loopIndex;
      if ((bVar2 >> 2 & 1) != 0) {
        if ((uVar19 & 4) == 0) {
          fVar4 = param_2[1];
          fVar9 = *(float *)(iVar22 + 0x2824);
          fVar10 = *(float *)(iVar22 + 0x2828);
          fVar11 = param_2[2];
          fVar14 = param_2[3];
          *(float *)((int)param_2 + loopIndex + 0x50) = *(float *)(iVar22 + 0x2820) * *param_2;
          *(float *)((int)param_2 + loopIndex + 0x54) = fVar9 * fVar4;
          *(float *)((int)param_2 + loopIndex + 0x5c) = fVar14;
          *(float *)((int)param_2 + loopIndex + 0x58) = fVar10 * fVar11;
        }
        else {
          uVar13 = *(undefined4 *)(iVar6 + 0x58);
          uVar7 = *(undefined4 *)(iVar6 + 0x54);
          uVar17 = *(undefined4 *)(iVar6 + 0x5c);
          *(undefined4 *)((int)param_2 + loopIndex + 0x50) = *(undefined4 *)(iVar6 + 0x50);
          *(undefined4 *)((int)param_2 + loopIndex + 0x54) = uVar7;
          *(undefined4 *)((int)param_2 + loopIndex + 0x58) = uVar13;
          *(undefined4 *)((int)param_2 + loopIndex + 0x5c) = uVar17;
        }
        if (*(int *)(glContext + 0x5434) == 0) {
          bVar1 = *(byte *)(loopIndex3 * 6 + param_3 * 3 + *(int *)(glContext + 0x5420) + 0x290);
        }
        else {
          bVar1 = *(byte *)(loopIndex3 * 6 + param_3 * 3 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) +
                           0x2c4);
        }
        iVar18 = (bVar1 >> 3 & 0x1c) + glContext;
        iVar15 = *(int *)(glContext + 0x5424);
        *(uint *)(iVar18 + 0x324) = *(uint *)(iVar18 + 0x324) | 1 << (bVar1 & 0x1f);
        bVar1 = *(byte *)(loopIndex3 * 6 + param_3 * 3 + iVar15 + 0x290);
        iVar15 = (bVar1 >> 3 & 0x1c) + glContext;
        *(uint *)(iVar15 + 0x348) = *(uint *)(iVar15 + 0x348) | 1 << (bVar1 & 0x1f);
      }
      if (((bVar2 & 0xe) != 0) && ((uVar19 & 0xe) != 0xe)) {
        param_2[0x7a] = param_2[0x7a] + *(float *)((int)param_2 + loopIndex + 0x50);
        param_2[0x7b] = param_2[0x7b] + *(float *)((int)param_2 + loopIndex + 0x54);
        param_2[0x7c] = param_2[0x7c] + *(float *)((int)param_2 + loopIndex + 0x58);
      }
      if ((bVar2 >> 3 & 1) != 0) {
        if ((uVar19 & 8) == 0) {
          fVar4 = param_2[5];
          fVar9 = *(float *)(iVar22 + 0x2834);
          fVar10 = *(float *)(iVar22 + 0x2838);
          fVar11 = param_2[6];
          fVar14 = param_2[7];
          *(float *)((int)param_2 + loopIndex + 0x60) = *(float *)(iVar22 + 0x2830) * param_2[4];
          *(float *)((int)param_2 + loopIndex + 100) = fVar9 * fVar4;
          *(float *)((int)param_2 + loopIndex + 0x6c) = fVar14;
          *(float *)((int)param_2 + loopIndex + 0x68) = fVar10 * fVar11;
        }
        else {
          uVar7 = *(undefined4 *)(iVar6 + 100);
          uVar13 = *(undefined4 *)(iVar6 + 0x68);
          uVar17 = *(undefined4 *)(iVar6 + 0x6c);
          *(undefined4 *)((int)param_2 + loopIndex + 0x60) = *(undefined4 *)(iVar6 + 0x60);
          *(undefined4 *)((int)param_2 + loopIndex + 100) = uVar7;
          *(undefined4 *)((int)param_2 + loopIndex + 0x68) = uVar13;
          *(undefined4 *)((int)param_2 + loopIndex + 0x6c) = uVar17;
        }
        if (*(int *)(glContext + 0x5434) == 0) {
          bVar1 = *(byte *)(loopIndex3 * 6 + param_3 * 3 + *(int *)(glContext + 0x5420) + 0x291);
        }
        else {
          bVar1 = *(byte *)(loopIndex3 * 6 + param_3 * 3 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) +
                           0x2c5);
        }
        iVar18 = (bVar1 >> 3 & 0x1c) + glContext;
        iVar15 = *(int *)(glContext + 0x5424);
        *(uint *)(iVar18 + 0x324) = *(uint *)(iVar18 + 0x324) | 1 << (bVar1 & 0x1f);
        bVar1 = *(byte *)(loopIndex3 * 6 + param_3 * 3 + iVar15 + 0x291);
        iVar15 = (bVar1 >> 3 & 0x1c) + glContext;
        *(uint *)(iVar15 + 0x348) = *(uint *)(iVar15 + 0x348) | 1 << (bVar1 & 0x1f);
      }
      if ((bVar2 & 0x10) != 0) {
        if ((uVar19 >> 4 & 1) == 0) {
          fVar4 = param_2[9];
          fVar9 = *(float *)(iVar22 + 0x2848);
          fVar10 = *(float *)(iVar22 + 0x2844);
          fVar11 = param_2[10];
          fVar14 = param_2[0xb];
          *(float *)((int)param_2 + loopIndex + 0x70) = *(float *)(iVar22 + 0x2840) * param_2[8];
          *(float *)((int)param_2 + loopIndex + 0x7c) = fVar14;
          *(float *)((int)param_2 + loopIndex + 0x74) = fVar10 * fVar4;
          *(float *)((int)param_2 + loopIndex + 0x78) = fVar9 * fVar11;
        }
        else {
          uVar7 = *(undefined4 *)(iVar6 + 0x70);
          uVar13 = *(undefined4 *)(iVar6 + 0x74);
          uVar17 = *(undefined4 *)(iVar6 + 0x78);
          *(undefined4 *)((int)param_2 + loopIndex + 0x7c) = *(undefined4 *)(iVar6 + 0x7c);
          *(undefined4 *)((int)param_2 + loopIndex + 0x70) = uVar7;
          *(undefined4 *)((int)param_2 + loopIndex + 0x74) = uVar13;
          *(undefined4 *)((int)param_2 + loopIndex + 0x78) = uVar17;
        }
        if (*(int *)(glContext + 0x5434) == 0) {
          bVar1 = *(byte *)(loopIndex3 * 6 + param_3 * 3 + *(int *)(glContext + 0x5420) + 0x292);
        }
        else {
          bVar1 = *(byte *)(loopIndex3 * 6 + param_3 * 3 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) +
                           0x2c6);
        }
        iVar15 = (bVar1 >> 3 & 0x1c) + glContext;
        iVar6 = *(int *)(glContext + 0x5424);
        *(uint *)(iVar15 + 0x324) = *(uint *)(iVar15 + 0x324) | 1 << (bVar1 & 0x1f);
        bVar1 = *(byte *)(loopIndex3 * 6 + param_3 * 3 + iVar6 + 0x292);
        iVar6 = (bVar1 >> 3 & 0x1c) + glContext;
        *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (bVar1 & 0x1f);
      }
    }
    loopIndex3 = loopIndex3 + 1;
    iVar22 = iVar22 + 0x80;
    loopIndex = loopIndex + 0x30;
  } while( true );
}

/* _gliDestroyContext @ 0x2f93c (300 bytes) */
int _gliDestroyContext(glContext)
  int glContext;
{
  int loopIndex;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((glContext == 0) || (*(int *)(glContext + 0x467c) != 0x3463a223)) {
    return 0x2714;
  }
  iVar1 = ((int (*)())_gleTerminateContext)(glContext);
  iVar4 = glContext + 0x10000;
  iVar2 = ((int (*)())_gleReleaseSharedState)(glContext);
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      iVar3 = (**(code **)(*(int *)(iVar4 + -0x777c) + 0x130))(*(undefined4 *)(iVar4 + -0x7a54));
      if (iVar1 == 0) {
        iVar1 = iVar3;
      }
      loopIndex = loopIndex + 1;
      iVar4 = iVar4 + 0x2e0;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  if (iVar2 != 0) {
    ((void (*)())_gleDestroySharedState)(glContext);
  }
  iVar2 = _gl_list;
  iVar4 = 0;
  if (_gl_list != 0) {
    do {
      iVar5 = iVar2;
      if (iVar5 == glContext) break;
      iVar2 = *(int *)(iVar5 + 0x85a0);
      iVar4 = iVar5;
    } while (*(int *)(iVar5 + 0x85a0) != 0);
    if (iVar4 != 0) {
      *(undefined4 *)(iVar4 + 0x85a0) = *(undefined4 *)(glContext + 0x85a0);
      goto LAB_0002fa38;
    }
  }
  _gl_list = *(int *)(glContext + 0x85a0);
LAB_0002fa38:
  if (_gl_list == 0) {
    ((void (*)())_gleDestroyEnableHashTable)();
  }
  ((void (*)())_gleDCBFree)(glContext);
  return iVar1;
}

/* _gleTerminateContext @ 0x2fa68 (192 bytes) */
int _gleTerminateContext(glContext)
  int glContext;
{
  ((int (*)())_gleFreeOrphans)(glContext);
  ((void (*)())_gleFreeVertexMachine)(glContext);
  ((void (*)())_gleFreePixelMap)(glContext);
  ((void (*)())_gleFreeMaterials)(glContext);
  ((void (*)())_gleFreeAllAttrib)(glContext);
  ((void (*)())_gleFreeVertexArrays)(glContext);
  ((void (*)())_gleFreeFunctions)(glContext);
  ((void (*)())_gleFreeQueryMachine)(glContext);
  ((void (*)())_gleFreeFenceMachine)(glContext);
  ((void (*)())_gleFreeVertexArrayState)(glContext);
  ((void (*)())_glePPEmulatorTerminate)(glContext);
  ((void (*)())_gleFreeBufferState)(glContext);
  ((void (*)())_gleFreeShaderState)(glContext);
  ((void (*)())_gleFreePipelineProgramState)(glContext);
  ((void (*)())_gleReclaimDrawPixelResources)(glContext);
  _gleFreeFramebufferState(glContext);
  ((void (*)())_gleFreeMapData)(glContext);
  ((void (*)())_gleFreeTextureState)(glContext);
  _gleVecFree(*(undefined4 *)(glContext + 0x4678));
  return 0;
}

/* _gleFreeOrphans @ 0x2fb28 (264 bytes) */
int _gleFreeOrphans(glContext)
  int glContext;
{
  int *cursor;
  int loopIndex;
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int extraout_r3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  
  iVar3 = glContext;
  if (*(int *)(glContext + 0x7484) != 0) {
    while( true ) {
      piVar5 = *(int **)(glContext + 0x7470);
      piVar6 = (int *)0x0;
      if (piVar5 != (int *)(glContext + 0x7468)) {
        iVar7 = piVar5[3];
        piVar6 = (int *)piVar5[1];
        iVar3 = piVar5[2];
        *piVar6 = *piVar5;
        *(int *)(iVar7 + 8) = iVar3;
        iVar3 = *piVar5;
        *(int *)(piVar5[2] + 0xc) = iVar7;
        *(int **)(iVar3 + 4) = piVar6;
        piVar5[2] = (int)piVar5;
        piVar5[3] = (int)piVar5;
        *piVar5 = (int)piVar5;
        piVar5[1] = (int)piVar5;
        piVar6 = piVar5;
      }
      if (piVar6 == (int *)0x0) break;
      iVar3 = glContext + 0x10000;
      loopIndex = 0;
      if (*(char *)(glContext + 0x85a4) != '\0') {
        cursor = piVar6 + 7;
        do {
          piVar1 = (int *)(iVar3 + -0x777c);
          loopIndex = loopIndex + 1;
          iVar4 = *cursor;
          cursor = cursor + 1;
          puVar2 = (undefined4 *)(iVar3 + -0x7a54);
          iVar3 = iVar3 + 0x2e0;
          (**(code **)(*piVar1 + 0x1f8))(*puVar2,iVar4);
        } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
      }
      _gleVecFree(piVar6);
    }
    _gleVecFree(*(undefined4 *)(glContext + 0x7484));
    *(undefined4 *)(glContext + 0x7484) = 0;
    iVar3 = 0;
    if (*(int *)(glContext + 0x7464) != 0) {
      _gleVecFree(*(int *)(glContext + 0x7464));
      *(undefined4 *)(glContext + 0x7464) = 0;
      iVar3 = extraout_r3;
    }
  }
  return iVar3;
}

/* _gleFreeVertexMachine @ 0x2fc30 (136 bytes) */
void _gleFreeVertexMachine(glContext)
  int glContext;
{
  if (*(int *)(glContext + 0x4854) != 0) {
    ((void (*)())_gleDCBFree)(*(int *)(glContext + 0x4854) + -0x200);
    *(undefined4 *)(glContext + 0x485c) = 0;
    *(undefined4 *)(glContext + 0x4854) = 0;
    *(undefined4 *)(glContext + 0x4860) = 0;
    *(undefined4 *)(glContext + 0x4864) = 0;
    *(undefined4 *)(glContext + 0x4870) = 0;
    *(undefined4 *)(glContext + 0x4874) = 0;
    *(undefined4 *)(glContext + 0x30b0) = 0;
    *(undefined4 *)(glContext + 0x4858) = 0;
  }
  if (*(int *)(glContext + 0x7588) != 0) {
    if (*(int *)(glContext + 0x758c) != 0) {
      _free(*(int *)(glContext + 0x758c));
    }
    *(undefined4 *)(glContext + 0x7588) = 0;
    *(undefined4 *)(glContext + 0x758c) = 0;
  }
  return;
}

/* _gleDCBFree @ 0x2fcb8 (12 bytes) */
void _gleDCBFree(glContext)
  int glContext;
{
  _free(glContext - (uint)*(byte *)(glContext + -1));
  return;
}

/* _gleFreePixelMap @ 0x2fcc4 (268 bytes) */
void _gleFreePixelMap(glContext)
  int glContext;
{
  undefined *puVar1;
  
  puVar1 = PTR__gle_default_pix_map_i_00112044;
  if (*(undefined **)(glContext + 0x3248) != PTR__gle_default_pix_map_i_00112044) {
    _free(*(undefined **)(glContext + 0x3248));
    *(undefined **)(glContext + 0x3248) = puVar1;
  }
  if (*(undefined **)(glContext + 0x326c) != puVar1) {
    _free(*(undefined **)(glContext + 0x326c));
    *(undefined **)(glContext + 0x326c) = puVar1;
  }
  puVar1 = PTR__gle_default_pix_map_f_00112040;
  if (*(undefined **)(glContext + 0x324c) != PTR__gle_default_pix_map_f_00112040) {
    _free(*(undefined **)(glContext + 0x324c));
    *(undefined **)(glContext + 0x324c) = puVar1;
  }
  if (*(undefined **)(glContext + 0x3250) != puVar1) {
    _free(*(undefined **)(glContext + 0x3250));
    *(undefined **)(glContext + 0x3250) = puVar1;
  }
  if (*(undefined **)(glContext + 0x3254) != puVar1) {
    _free(*(undefined **)(glContext + 0x3254));
    *(undefined **)(glContext + 0x3254) = puVar1;
  }
  if (*(undefined **)(glContext + 0x3258) != puVar1) {
    _free(*(undefined **)(glContext + 0x3258));
    *(undefined **)(glContext + 0x3258) = puVar1;
  }
  if (*(undefined **)(glContext + 0x325c) != puVar1) {
    _free(*(undefined **)(glContext + 0x325c));
    *(undefined **)(glContext + 0x325c) = puVar1;
  }
  if (*(undefined **)(glContext + 0x3260) != puVar1) {
    _free(*(undefined **)(glContext + 0x3260));
    *(undefined **)(glContext + 0x3260) = puVar1;
  }
  if (*(undefined **)(glContext + 0x3264) != puVar1) {
    _free(*(undefined **)(glContext + 0x3264));
    *(undefined **)(glContext + 0x3264) = puVar1;
  }
  if (*(undefined **)(glContext + 0x3268) != puVar1) {
    _free(*(undefined **)(glContext + 0x3268));
    *(undefined **)(glContext + 0x3268) = puVar1;
  }
  return;
}

/* _gleFreeMaterials @ 0x2fdd0 (140 bytes) */
void _gleFreeMaterials(glContext)
  int glContext;
{
  int remaining;
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)(glContext + 0x4dd0);
  remaining = 1;
  do {
    iVar4 = *piVar3;
    for (iVar1 = *(int *)(*piVar3 + 0x23c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x23c)) {
      _gleVecFree(iVar4);
      iVar4 = iVar1;
    }
    remaining = remaining + -1;
    *piVar3 = iVar4;
    piVar3 = piVar3 + 1;
  } while (-1 < remaining);
  iVar2 = *(int *)(glContext + 0x4dd8);
  while (iVar2 != 0) {
    iVar4 = *(int *)(iVar2 + 0x23c);
    _gleVecFree(iVar2);
    iVar2 = iVar4;
  }
  *(undefined4 *)(glContext + 0x4dd8) = 0;
  return;
}

/* _gleFreeAllAttrib @ 0x2fe5c (228 bytes) */
void _gleFreeAllAttrib(glContext)
  int glContext;
{
  int loopIndex2;
  int iVar1;
  int iVar2;
  int loopIndex;
  int *piVar4;
  
  loopIndex = 0;
  iVar1 = *(int *)(glContext + 0x50fc);
  if (0 < iVar1) {
    piVar4 = (int *)(glContext + 0x50b8);
    do {
      iVar2 = *piVar4;
      if (*piVar4 != 0) {
        do {
          iVar1 = *(int *)(iVar2 + 0x2c44);
          _free(iVar2);
          iVar2 = iVar1;
        } while (iVar1 != 0);
        iVar1 = *(int *)(glContext + 0x50fc);
      }
      loopIndex = loopIndex + 1;
      *piVar4 = 0;
      piVar4 = piVar4 + 1;
    } while (loopIndex < iVar1);
  }
  iVar1 = *(int *)(glContext + 0x5144);
  loopIndex2 = 0;
  if (0 < iVar1) {
    piVar4 = (int *)(glContext + 0x5100);
    do {
      iVar2 = *piVar4;
      if (*piVar4 != 0) {
        do {
          iVar1 = *(int *)(iVar2 + 700);
          _free(iVar2);
          iVar2 = iVar1;
        } while (iVar1 != 0);
        iVar1 = *(int *)(glContext + 0x5144);
      }
      loopIndex2 = loopIndex2 + 1;
      *piVar4 = 0;
      piVar4 = piVar4 + 1;
    } while (loopIndex2 < iVar1);
  }
  *(int *)(glContext + 0x5140) = glContext + 0x5100;
  *(int *)(glContext + 0x50f8) = glContext + 0x50b8;
  *(undefined4 *)(glContext + 0x5144) = 0;
  *(undefined4 *)(glContext + 0x50fc) = 0;
  return;
}

/* _gleFreeVertexArrays @ 0x2ff40 (68 bytes) */
void _gleFreeVertexArrays(glContext)
  int glContext;
{
  if (*(int *)(glContext + 0x49ac) != 0) {
    _free(*(int *)(glContext + 0x49ac));
  }
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x49b4));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x49b8));
  return;
}

/* _gleFreeFuncCache @ 0x2ff84 (68 bytes) */
void _gleFreeFuncCache(param_1)
  int *param_1;
{
  int *piVar1;
  int *piVar2;
  
  piVar1 = param_1;
  if (param_1 != (int *)0x0) {
    do {
      piVar2 = (int *)*piVar1;
      ((void (*)())_gleDCBFree)(piVar1);
      piVar1 = piVar2;
    } while (piVar2 != param_1);
  }
  return;
}

/* _gleFreeFunctions @ 0x2ffc8 (116 bytes) */
void _gleFreeFunctions(glContext)
  int glContext;
{
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x5088));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x5094));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x50a0));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x49d0));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x49d8));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x48a0));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x48a8));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x48c0));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x48b0));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x48b8));
  return;
}

/* _gleFreeQueryMachine @ 0x3003c (136 bytes) */
void _gleFreeQueryMachine(glContext)
  int glContext;
{
  int remaining;
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  piVar2 = (int *)(glContext + 0x6440);
  remaining = 0x3ff;
  do {
    piVar3 = (int *)*piVar2;
    piVar2 = piVar2 + 1;
    while (piVar3 != (int *)0x0) {
      iVar4 = *piVar3;
      (*(code *)piVar3[3])(glContext,piVar3);
      piVar3 = (int *)iVar4;
    }
    remaining = remaining + -1;
  } while (-1 < remaining);
  piVar2 = (int *)*(int *)(glContext + 0x7440);
  while (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    _free(piVar2);
    piVar2 = (int *)iVar1;
  }
  return;
}

/* _gleFreeFenceMachine @ 0x300c4 (136 bytes) */
void _gleFreeFenceMachine(glContext)
  int glContext;
{
  int remaining;
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  piVar2 = (int *)(glContext + 0x543c);
  remaining = 0x3ff;
  do {
    piVar3 = (int *)*piVar2;
    piVar2 = piVar2 + 1;
    while (piVar3 != (int *)0x0) {
      iVar4 = *piVar3;
      (*(code *)piVar3[3])(glContext,piVar3);
      piVar3 = (int *)iVar4;
    }
    remaining = remaining + -1;
  } while (-1 < remaining);
  piVar2 = (int *)*(int *)(glContext + 0x643c);
  while (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    _free(piVar2);
    piVar2 = (int *)iVar1;
  }
  return;
}

/* _gleFreeVertexArrayState @ 0x3014c (180 bytes) */
void _gleFreeVertexArrayState(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(glContext + 0x4a60);
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 4) != 0) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      iVar1 = *(int *)(iVar2 + 8) + -1;
      *(int *)(iVar2 + 8) = iVar1;
      if (iVar1 == 0) {
        ((int (*)())_gleFreeVertexArrayObject)(glContext,iVar2);
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
    }
    ((int (*)())_gleFreeVertexArrayObject)(glContext,*(undefined4 *)(glContext + 0x4a64));
    return;
  }
  return;
}

/* _gleFreeVertexArrayObject @ 0x30200 (196 bytes) */
int _gleFreeVertexArrayObject(glContext, param_2)
  undefined4 glContext;
  int param_2;
{
  int remaining;
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  ((void (*)())_gleDestroyPluginVertexArray)(glContext,param_2 + 0x10);
  iVar3 = *(int *)(param_2 + 0x358);
  if ((iVar3 != 0) && (iVar1 = *(int *)(iVar3 + 8) + -1, *(int *)(iVar3 + 8) = iVar1, iVar1 == 0)) {
    _gleFreeBufferObject(glContext,iVar3);
  }
  iVar3 = *(int *)(param_2 + 0x35c);
  if ((iVar3 != 0) && (iVar1 = *(int *)(iVar3 + 8) + -1, *(int *)(iVar3 + 8) = iVar1, iVar1 == 0)) {
    _gleFreeBufferObject(glContext,iVar3);
  }
  piVar4 = (int *)(param_2 + 0x360);
  remaining = 0x1f;
  do {
    iVar1 = *piVar4;
    piVar4 = piVar4 + 1;
    if ((iVar1 != 0) && (iVar2 = *(int *)(iVar1 + 8) + -1, *(int *)(iVar1 + 8) = iVar2, iVar2 == 0))
    {
      _gleFreeBufferObject(glContext,iVar1);
    }
    remaining = remaining + -1;
  } while (-1 < remaining);
  _gleVecFree(param_2);
  return;
}

/* _gleDestroyPluginVertexArray @ 0x302c4 (120 bytes) */
void _gleDestroyPluginVertexArray(glContext, param_2)
  int glContext;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int loopIndex;
  
  iVar4 = glContext + 0x10000;
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar4 + -0x777c);
      iVar3 = loopIndex * 4;
      puVar2 = (undefined4 *)(iVar4 + -0x7a54);
      iVar4 = iVar4 + 0x2e0;
      loopIndex = loopIndex + 1;
      (**(code **)(*piVar1 + 0x1b0))(*puVar2,*(undefined4 *)(iVar3 + param_2));
      *(undefined4 *)(iVar3 + param_2) = 0;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return;
}

/* _glePPEmulatorTerminate @ 0x30340 (8 bytes) */
void _glePPEmulatorTerminate(glContext)
  int glContext;
{
  _PPEmulatorFree(*(undefined4 *)(glContext + 0x4a5c));
  return;
}

/* _gleFreeBufferState @ 0x30348 (180 bytes) */
void _gleFreeBufferState(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(glContext + 0x48f4);
  if (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 8) + -1;
    *(int *)(iVar2 + 8) = iVar1;
    if (iVar1 == 0) {
      _gleFreeBufferObject(glContext,iVar2);
    }
    *(undefined4 *)(glContext + 0x48f4) = 0;
  }
  iVar2 = *(int *)(glContext + 0x4a68);
  if ((iVar2 != 0) && (iVar1 = *(int *)(iVar2 + 8) + -1, *(int *)(iVar2 + 8) = iVar1, iVar1 == 0)) {
    _gleFreeBufferObject(glContext,iVar2);
  }
  iVar2 = *(int *)(glContext + 0x4a6c);
  *(undefined4 *)(glContext + 0x4a68) = 0;
  if ((iVar2 != 0) && (iVar1 = *(int *)(iVar2 + 8) + -1, *(int *)(iVar2 + 8) = iVar1, iVar1 == 0)) {
    _gleFreeBufferObject(glContext,iVar2);
  }
  *(undefined4 *)(glContext + 0x4a6c) = 0;
  return;
}

/* _gleFreeShaderState @ 0x303fc (156 bytes) */
void _gleFreeShaderState(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(glContext + 0x5430);
  if (iVar2 != 0) {
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    iVar1 = *(int *)(iVar2 + 8) + -1;
    *(int *)(iVar2 + 8) = iVar1;
    if (iVar1 == 1) {
      ((int (*)())_gleDeleteHashNameAndObject)(glContext,*(int *)(glContext + 0x5148) + 0x6018,*(undefined4 *)(iVar2 + 4));
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    *(undefined4 *)(glContext + 0x5430) = 0;
  }
  return;
}

/* _gleFreePipelineProgramState @ 0x30498 (208 bytes) */
void _gleFreePipelineProgramState(glContext)
  int glContext;
{
  int iVar1;
  int remaining;
  undefined4 *puVar3;
  int iVar4;
  
  if (*(int *)(glContext + 0x5418) != 0) {
    _free(*(int *)(glContext + 0x5418));
    *(undefined4 *)(glContext + 0x5418) = 0;
  }
  puVar3 = (undefined4 *)(glContext + 0x5428);
  remaining = 1;
  do {
    iVar4 = puVar3[-2];
    if (iVar4 != 0) {
      if (*(int *)(iVar4 + 4) != 0) {
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
        }
        iVar1 = *(int *)(iVar4 + 8) + -1;
        *(int *)(iVar4 + 8) = iVar1;
        if (iVar1 == 0) {
          ((void (*)())_gleFreePipelineProgramObject)(glContext,iVar4);
        }
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
        }
      }
      ((void (*)())_gleFreePipelineProgramObject)(glContext,*puVar3);
    }
    remaining = remaining + -1;
    puVar3 = puVar3 + 1;
  } while (-1 < remaining);
  return;
}

/* _gleFreePipelineProgramObject @ 0x30568 (72 bytes) */
void _gleFreePipelineProgramObject(glContext, param_2)
  undefined4 glContext;
  int param_2;
{
  ((void (*)())_gleClearPipelineProgram)(glContext,param_2 + 0x10);
  ((void (*)())_gleDestroyPluginPipelineProgram)(glContext,param_2 + 0x10);
  _gleVecFree(param_2);
  return;
}

/* _gleClearPipelineProgram @ 0x305b0 (364 bytes) */
void _gleClearPipelineProgram(glContext, param_2)
  undefined4 glContext;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int loopIndex;
  int iVar4;
  int remaining;
  
  iVar4 = param_2[0x12f];
  if (param_2[1] != 0) {
    _free(param_2[1]);
    param_2[1] = 0;
  }
  param_2[2] = 0;
  param_2[3] = 0;
  *(undefined2 *)(param_2 + 0x10) = 0;
  *(undefined2 *)((int)param_2 + 0x42) = 0;
  *(undefined2 *)(param_2 + 0x11) = 0;
  *(undefined2 *)((int)param_2 + 0x46) = 0;
  *(undefined2 *)((int)param_2 + 0x3e) = 0;
  if (*param_2 != 0) {
    _PPStreamFree(*param_2);
    *param_2 = 0;
  }
  if (*(short *)((int)param_2 + 0x4ba) == 0) {
    if (param_2[0x135] != 0) {
      _PPEmulatorProgramFree(param_2[0x135]);
      param_2[0x135] = 0;
    }
    remaining = 0x100;
  }
  else if (*(short *)((int)param_2 + 0x4ba) == 1) {
    if (param_2[0x135] != 0) {
      _LFSStreamFree(param_2[0x135]);
      param_2[0x135] = 0;
    }
    *(undefined2 *)(param_2 + 0x138) = 0;
    *(undefined2 *)(param_2 + 0x137) = 0;
    *(undefined2 *)((int)param_2 + 0x4de) = 0;
    remaining = 0x80;
  }
  else {
    remaining = 0;
  }
  if (iVar4 != 0) {
    if (*(short *)(param_2 + 0x12e) != -0x7e00) {
      ((void (*)())_glePPUnlogParameters)(glContext,param_2,*(undefined4 *)(iVar4 + 0x28),iVar4 + *(int *)(iVar4 + 0x2c) * 8);
    }
    _gleVecFree(iVar4);
    param_2[0x12f] = 0;
  }
  iVar4 = param_2[0x134];
  if (iVar4 != 0) {
    loopIndex = 0;
    for (; remaining != 0; remaining = remaining + -1) {
      iVar1 = loopIndex * 0x10;
      loopIndex = loopIndex + 1;
      iVar2 = iVar1 + iVar4;
      *(undefined4 *)(iVar4 + iVar1) = 0;
      *(undefined4 *)(iVar2 + 0xc) = 0x3f800000;
      *(undefined4 *)(iVar2 + 4) = 0;
      *(undefined4 *)(iVar2 + 8) = 0;
    }
  }
  return;
}

/* _gleDestroyPluginPipelineProgram @ 0x3071c (120 bytes) */
void _gleDestroyPluginPipelineProgram(glContext, param_2)
  int glContext;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int loopIndex;
  
  iVar3 = glContext + 0x10000;
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      loopIndex = loopIndex + 1;
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      iVar3 = iVar3 + 0x2e0;
      (**(code **)(*piVar1 + 0x1a0))(*puVar2,*(undefined4 *)(param_2 + 0x498));
      *(undefined4 *)(param_2 + 0x498) = 0;
      param_2 = param_2 + 4;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return;
}

/* _gleReclaimDrawPixelResources @ 0x30794 (184 bytes) */
void _gleReclaimDrawPixelResources(glContext)
  int glContext;
{
  undefined4 *puVar1;
  uint loopIndex;
  
  puVar1 = *(undefined4 **)(glContext + 0x74a0);
  if (puVar1 != (undefined4 *)0x0) {
    loopIndex = 0;
    if (*(int *)(glContext + 0x7490) != 0) {
      while( true ) {
        _gleDeletePluginTexture(glContext,puVar1[loopIndex]);
        if (*(uint *)(glContext + 0x7490) <= loopIndex + 1) break;
        puVar1 = *(undefined4 **)(glContext + 0x74a0);
        loopIndex = loopIndex + 1;
      }
      puVar1 = *(undefined4 **)(glContext + 0x74a0);
    }
    _gleVecFree(*puVar1);
    _gleVecFree(*(undefined4 *)(glContext + 0x74a0));
  }
  if (*(int *)(0x74a4 + glContext) != 0) {
    _gleVecFree(*(int *)(0x74a4 + glContext));
  }
  *(undefined4 *)(0x74a4 + glContext) = 0;
  *(undefined4 *)(glContext + 0x7488) = 0;
  *(undefined4 *)(glContext + 0x7494) = 0;
  *(undefined4 *)(glContext + 0x748c) = 0;
  *(undefined4 *)(glContext + 0x7490) = 0;
  *(undefined4 *)(glContext + 0x7498) = 0;
  *(undefined4 *)(glContext + 0x749c) = 0;
  *(undefined4 *)(glContext + 0x74a0) = 0;
  return;
}

/* _gleFreeMapData @ 0x3084c (16 bytes) */
void _gleFreeMapData(glContext)
  int glContext;
{
  if (*(int *)(glContext + 0x7450) == 0) {
    return;
  }
  _free(*(int *)(glContext + 0x7450));
  return;
}

/* _gleFreeTextureState @ 0x3085c (376 bytes) */
void _gleFreeTextureState(glContext)
  int glContext;
{
  int remaining2;
  int remaining;
  int loopIndex;
  int iVar1;
  int iVar2;
  int iVar3;
  int remaining3;
  int *piVar5;
  int iVar6;
  
  loopIndex = 0;
  iVar3 = glContext;
  do {
    piVar5 = (int *)(iVar3 + 0x5154);
    remaining3 = 4;
    do {
      iVar6 = *piVar5;
      piVar5 = piVar5 + 1;
      if ((iVar6 != 0) && (*(int *)(iVar6 + 4) != 0)) {
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
        }
        iVar1 = *(int *)(iVar6 + 8) + -1;
        *(int *)(iVar6 + 8) = iVar1;
        if (iVar1 == 0) {
          _gleFreeTextureObject(glContext,iVar6);
        }
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
        }
      }
      remaining3 = remaining3 + -1;
    } while (-1 < remaining3);
    loopIndex = loopIndex + 1;
    iVar3 = iVar3 + 0x14;
  } while (loopIndex < 0x10);
  piVar5 = (int *)(glContext + 0x52d4);
  remaining = 0xf;
  do {
    iVar2 = *piVar5;
    piVar5 = piVar5 + 1;
    if (iVar2 != 0) {
      _gleFreeTextureObject(glContext,iVar2);
    }
    remaining = remaining + -1;
  } while (-1 < remaining);
  iVar2 = glContext + 0x52b0;
  remaining2 = 2;
  do {
    if (*(int *)(iVar2 + 0xc) != 0) {
      _gleFreeTextureObject(glContext,*(int *)(iVar2 + 0xc));
    }
    if (*(int *)(iVar2 + 0x18) != 0) {
      _gleFreeTextureObject(glContext,*(int *)(iVar2 + 0x18));
    }
    remaining2 = remaining2 + -1;
    iVar2 = iVar2 + 4;
  } while (-1 < remaining2);
  iVar3 = glContext;
  do {
    if (*(int *)(iVar3 + 0x5294) != 0) {
      _gleFreeTextureObject(glContext,*(int *)(iVar3 + 0x5294));
    }
    if (*(int *)(iVar3 + 0x52a8) != 0) {
      _gleFreeTextureObject(glContext,*(int *)(iVar3 + 0x52a8));
    }
    iVar3 = iVar3 + 4;
  } while (iVar3 <= glContext + 0x10);
  return;
}

/* _gleReleaseSharedState @ 0x309d4 (288 bytes) */
int _gleReleaseSharedState(glContext)
  int glContext;
{
  int remaining;
  int loopIndex;
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int remaining2;
  
  puVar4 = *(undefined **)(glContext + 0x5148);
  _pthread_mutex_lock(puVar4 + 0x8028);
  iVar3 = *(int *)(puVar4 + 0x8020);
  *(int *)(puVar4 + 0x8020) = iVar3 + -1;
  _pthread_mutex_unlock(puVar4 + 0x8028);
  uVar1 = 0;
  if (iVar3 < 2) {
    loopIndex = 0;
    ((void (*)())_gleDetachShaderObjects)(glContext);
    puVar2 = puVar4;
    do {
      remaining2 = 0x3ff;
      iVar5 = loopIndex * 0x1004;
      do {
        piVar6 = *(int **)(puVar4 + iVar5);
        if (piVar6 != (int *)0x0) {
          *(undefined4 *)(puVar4 + iVar5) = 0;
          do {
            piVar7 = (int *)*piVar6;
            (*(code *)piVar6[3])(glContext,piVar6);
            piVar6 = piVar7;
          } while (piVar7 != (int *)0x0);
        }
        remaining2 = remaining2 + -1;
        iVar5 = iVar5 + 4;
      } while (-1 < remaining2);
      piVar6 = *(int **)(puVar2 + 0x1000);
      if (piVar6 != (int *)0x0) {
        *(undefined4 *)(puVar2 + 0x1000) = 0;
        do {
          piVar7 = (int *)*piVar6;
          _free(piVar6);
          piVar6 = piVar7;
        } while (piVar7 != (int *)0x0);
      }
      loopIndex = loopIndex + 1;
      puVar2 = ((unsigned char *)0x00001004) + (int)puVar2;
    } while (loopIndex < 8);
    puVar4 = puVar4 + 0x10000;
    remaining = 1;
    do {
      if (*(int *)(puVar4 + -0x7560) != 0) {
        _free(*(int *)(puVar4 + -0x7560));
      }
      remaining = remaining + -1;
      *(undefined4 *)(puVar4 + -0x7560) = 0;
      puVar4 = puVar4 + 0xa30;
    } while (-1 < remaining);
    uVar1 = 1;
  }
  return uVar1;
}

/* _gleDetachShaderObjects @ 0x30af4 (144 bytes) */
void _gleDetachShaderObjects(glContext)
  int glContext;
{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  puVar1 = PTR__gleDetachShaderObjectIterFunc_001113e8;
  iVar2 = *(int *)(glContext + 0x5148);
  piVar4 = (int *)(iVar2 + 0x6018);
  do {
    piVar3 = piVar4 + 1;
    for (piVar4 = (int *)*piVar4; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
      (*(code *)puVar1)(glContext,piVar4);
    }
    piVar4 = piVar3;
  } while ((int)piVar3 <= iVar2 + 0x7014);
  return;
}

/* _gleDestroySharedState @ 0x30b84 (132 bytes) */
void _gleDestroySharedState(glContext)
  int glContext;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int loopIndex;
  undefined4 *puVar5;
  int *piVar6;
  
  loopIndex = 0;
  iVar3 = *(int *)(glContext + 0x5148);
  if (*(char *)(glContext + 0x85a4) != '\0') {
    piVar6 = (int *)(glContext + 0x8884);
    puVar5 = (undefined4 *)(iVar3 + 0x8054);
    do {
      iVar1 = *piVar6;
      piVar6 = piVar6 + 0xb8;
      uVar2 = *puVar5;
      loopIndex = loopIndex + 1;
      puVar5 = puVar5 + 1;
      (**(code **)(iVar1 + 0x128))(uVar2);
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  _pthread_mutex_destroy(iVar3 + 0x8028);
  _free(iVar3);
  return;
}

/* _glTexCoord2fv_Exec @ 0x30c08 (36 bytes) */
void _glTexCoord2fv_Exec(glContext, v)
  int glContext;
  undefined4 *v;
{
  undefined4 uVar1;
  
  uVar1 = v[1];
  *(undefined4 *)(glContext + 0x120) = *v;
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(glContext + 0x124) = uVar1;
  *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
  return;
}

/* _glVertex2i_Exec @ 0x30c2c (144 bytes) */
void _glVertex2i_Exec(glContext, x, y)
  int glContext;
  uint x;
  uint y;
{
  code *pcVar1;
  
  pcVar1 = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    pcVar1 = *(code **)(glContext + 0x28);
  }
  (*pcVar1)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                   DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - DOUBLE_00108d58),
            (double)*(float *)(glContext + 0x20),(double)*(float *)(glContext + 0x24));
  return;
}

/* _glGetBooleanv_Exec @ 0x30cbc (272 bytes) */
void _glGetBooleanv_Exec(glContext, pname, params)
  int glContext;
  undefined4 pname;
  int params;
{
  int loopIndex2;
  double doubleZero;
  undefined4 glErrorCode;
  int iVar3;
  int iVar4;
  double *cursor;
  int loopIndex;
  double dVar7;
  undefined1 auStack_b0 [16];
  double local_a0 [16];
  int local_20 [4];
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    cursor = local_a0;
    iVar4 = _gleGetState(glContext,pname,cursor,local_20,auStack_b0);
    doubleZero = DOUBLE_00108d60;
    if (iVar4 == 0) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_00030d30;
    }
    if (iVar4 != -1) {
      if (local_20[0] != 0x1404) {
        loopIndex = 0;
        if (iVar4 < 1) {
          return;
        }
        do {
          dVar7 = *cursor;
          cursor = cursor + 1;
          *(bool *)(params + loopIndex) = dVar7 != doubleZero;
          loopIndex = loopIndex + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        return;
      }
      loopIndex2 = 0;
      if (iVar4 < 1) {
        return;
      }
      do {
        iVar3 = *(int *)cursor;
        cursor = cursor + 1;
        *(char *)(params + loopIndex2) = '\x01' - (iVar3 == 0);
        loopIndex2 = loopIndex2 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      return;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00030d30:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glDeleteProgramsARB_Exec @ 0x30dcc (300 bytes) */
void _glDeleteProgramsARB_Exec(glContext, n, programs)
  int glContext;
  int n;
  int *programs;
{
  undefined4 glErrorCode;
  int iVar2;
  uint loopIndex;
  int iVar4;
  int *piVar5;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (0 < n) {
        do {
          iVar4 = *programs;
          programs = programs + 1;
          if (iVar4 != 0) {
            loopIndex = 0;
            piVar5 = (int *)(glContext + 0x5420);
            do {
              iVar2 = *piVar5;
              piVar5 = piVar5 + 1;
              if (iVar4 == *(int *)(iVar2 + 4)) {
                _gleBindPipelineProgram(glContext,loopIndex,0);
              }
              loopIndex = loopIndex + 1;
            } while (loopIndex < 2);
            ((int (*)())_gleDeleteHashNameAndObject)(glContext,*(int *)(glContext + 0x5148) + 0x4010,iVar4);
          }
          n = n + -1;
        } while (n != 0);
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _gleDeleteHashNameAndObject @ 0x30ef8 (136 bytes) */
int _gleDeleteHashNameAndObject(glContext, param_2, param_3)
  undefined4 glContext;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = ((int (*)())_gleRemoveHashName)(param_2,param_3);
  uVar3 = 0;
  if (iVar2 != 0) {
    iVar2 = _gleRemoveHashObject(param_2,param_3);
    if ((iVar2 != 0) && (iVar1 = *(int *)(iVar2 + 8) + -1, *(int *)(iVar2 + 8) = iVar1, iVar1 == 0))
    {
      (**(code **)(iVar2 + 0xc))(glContext);
    }
    uVar3 = 1;
  }
  return uVar3;
}

/* _gleRemoveHashName @ 0x30f80 (228 bytes) */
int _gleRemoveHashName(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (*(undefined4 **)(param_1 + 0x1000) != (undefined4 *)0x0) {
    uVar2 = param_2 + 1;
    puVar3 = (undefined4 *)(param_1 + 0x1000);
    puVar6 = *(undefined4 **)(param_1 + 0x1000);
    do {
      uVar4 = puVar6[1];
      uVar5 = uVar4 + puVar6[2];
      if (param_2 < uVar4) {
        return 0;
      }
      if (param_2 < uVar5) {
        if (uVar4 < param_2) {
          puVar6[2] = param_2 - uVar4;
          if (uVar2 < uVar5) {
            puVar3 = (undefined4 *)_malloc(0xc);
            uVar1 = *puVar6;
            puVar3[1] = uVar2;
            *puVar3 = uVar1;
            puVar3[2] = (uVar5 - param_2) + -1;
            *puVar6 = puVar3;
          }
        }
        else if (uVar2 < uVar5) {
          puVar6[1] = uVar4 + 1;
          puVar6[2] = (uVar5 - uVar4) + -1;
        }
        else {
          *puVar3 = *puVar6;
          _free(puVar6);
        }
        return 1;
      }
      puVar7 = (undefined4 *)*puVar6;
      puVar3 = puVar6;
      puVar6 = puVar7;
    } while (puVar7 != (undefined4 *)0x0);
  }
  return 0;
}

/* _glePPUnlogParameters @ 0x31064 (248 bytes) */
void _glePPUnlogParameters(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int loopIndex;
  uint uVar8;
  int iVar9;
  
  loopIndex = 0;
  uVar3 = (uint)*(ushort *)(param_2 + 0x4ba);
  iVar6 = *(int *)(param_1 + 0x5148);
  iVar4 = uVar3 * 0xa30 + iVar6;
  *(int *)(iVar4 + 0x8a98) = *(int *)(iVar4 + 0x8a98) + 1;
  if (param_3 != 0) {
    do {
      uVar8 = *(uint *)(loopIndex * 8 + param_4 + 4);
      if ((*(uint *)(loopIndex * 8 + param_4) & 0x1f0000) != 0) {
        uVar2 = uVar8 & 0xffff;
        iVar4 = (uVar3 * 0x518 + uVar2) * 2 + iVar6;
        uVar1 = *(ushort *)(iVar4 + 0x8874);
        if (uVar1 == 1) {
          iVar5 = (uVar3 * 0x146 + uVar2) * 8 + iVar6;
          iVar9 = (uVar3 * 0x28c + (uVar2 >> 5)) * 4 + iVar6;
          *(undefined2 *)(iVar4 + 0x8874) = 0;
          *(undefined4 *)(iVar5 + 0x8074) = 0;
          *(undefined4 *)(iVar5 + 0x8078) = 0;
          *(uint *)(iVar9 + 0x8a74) = *(uint *)(iVar9 + 0x8a74) | 1 << (uVar8 & 0x1f);
        }
        else if (1 < uVar1) {
          *(ushort *)(iVar4 + 0x8874) = uVar1 - 1;
        }
      }
      loopIndex = loopIndex + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

/* _gleDestroyEnableHashTable @ 0x3115c (104 bytes) */
void _gleDestroyEnableHashTable()
{
  int iVar1;
  int iVar2;
  int remaining;
  int *piVar4;
  
  iVar1 = _gle_enable_hash_table;
  remaining = 0x3ff;
  piVar4 = (int *)(_gle_enable_hash_table + 8);
  do {
    iVar2 = *piVar4;
    piVar4 = piVar4 + 4;
    if (iVar2 != 0) {
      ((void (*)())_gleFreeEnableHashObject)(iVar2);
    }
    remaining = remaining + -1;
  } while (-1 < remaining);
  _free(iVar1);
  _gle_enable_hash_table = 0;
  return;
}

/* _gleFreeEnableHashObject @ 0x311c4 (60 bytes) */
void _gleFreeEnableHashObject(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 8) != 0) {
    ((void (*)())_gleFreeEnableHashObject)(*(int *)(param_1 + 8));
  }
  _free(param_1);
  return;
}

/* _glVertex4f_Exec @ 0x31200 (32 bytes) */
void _glVertex4f_Exec(glContext)
  int glContext;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x28);
  }
                    
                    
  (*((int (*)(int))UNRECOVERED_JUMPTABLE))(glContext);
  return;
}

/* _glFrustum_Exec @ 0x31220 (660 bytes) */
void _glFrustum_Exec(int glContext,double left,double right,double bottom,double top,float zNear,double zFar,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
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
  undefined4 glErrorCode;
  float *pfVar12;
  float dVar13;
  
  pfVar12 = *(float **)(glContext + 0x4fec);
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    if ((!(zNear <= DOUBLE_00108d60)) && (!(zFar <= DOUBLE_00108d60))) {
      fVar1 = (float)(right - left);
      fVar2 = (float)(top - bottom);
      fVar3 = (float)(zNear - zFar);
      fVar4 = fVar1;
      if (!(0.0 <= fVar1)) {
        fVar4 = -fVar1;
      }
      if (!(fVar4 < FLOAT_00108e80)) {
        fVar4 = fVar2;
        if (!(FLOAT_00108e50 <= fVar2)) {
          fVar4 = -fVar2;
        }
        if (!(fVar4 < FLOAT_00108e80)) {
          fVar4 = fVar3;
          if (!(FLOAT_00108e50 <= fVar3)) {
            fVar4 = -fVar3;
          }
          if (!(fVar4 < FLOAT_00108e80)) {
            fVar7 = pfVar12[8];
            fVar8 = pfVar12[9];
            fVar9 = pfVar12[10];
            fVar10 = pfVar12[0xb];
            fVar4 = (float)((top + bottom) * (double)(1.0 / fVar2));
            fVar5 = (float)((right + left) * (double)(1.0 / fVar1));
            fVar6 = (float)((zFar + zNear) * (double)(1.0 / fVar3));
            dVar13 = (double)(zNear + zNear);
            fVar1 = (float)((double)dVar13 * (double)(1.0 / fVar1));
            pfVar12[8] = (fVar7 * fVar6 + (*pfVar12 * fVar5 + pfVar12[4] * fVar4)) - pfVar12[0xc];
            fVar3 = (float)(zFar * (double)dVar13 * (double)(1.0 / fVar3));
            fVar2 = (float)((double)dVar13 * (double)(1.0 / fVar2));
            pfVar12[9] = (fVar8 * fVar6 + (pfVar12[1] * fVar5 + pfVar12[5] * fVar4)) - pfVar12[0xd];
            pfVar12[10] = (fVar9 * fVar6 + (pfVar12[2] * fVar5 + pfVar12[6] * fVar4)) - pfVar12[0xe];
            pfVar12[0xb] = (fVar10 * fVar6 + (pfVar12[3] * fVar5 + pfVar12[7] * fVar4)) - pfVar12[0xf]
            ;
            pfVar12[3] = pfVar12[3] * fVar1;
            pfVar12[4] = pfVar12[4] * fVar2;
            *pfVar12 = *pfVar12 * fVar1;
            pfVar12[5] = pfVar12[5] * fVar2;
            pfVar12[1] = pfVar12[1] * fVar1;
            pfVar12[6] = pfVar12[6] * fVar2;
            pfVar12[2] = pfVar12[2] * fVar1;
            pfVar12[0xf] = fVar10 * fVar3;
            pfVar12[0xc] = fVar7 * fVar3;
            pfVar12[0xd] = fVar8 * fVar3;
            pfVar12[0xe] = fVar9 * fVar3;
            pfVar12[7] = pfVar12[7] * fVar2;
            *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | *(uint *)(glContext + 0x50a8);
            *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) | *(uint *)(glContext + 0x50a8);
            return;
          }
        }
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glShadeModel_Exec @ 0x314b4 (160 bytes) */
void _glShadeModel_Exec(glContext, mode)
  int glContext;
  int mode;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (mode - 0x1d00U < 2) {
      *(int *)(glContext + 0x34f4) = mode;
      _gleUpdatePrimitiveData(glContext);
      puVar2 = PTR__gleSetEyeInterpFunc_0011203c;
      puVar1 = PTR__gleSetClipInterpFunc_00112038;
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x8000000;
      *(undefined **)(glContext + 0x49c8) = puVar2;
      *(undefined **)(glContext + 0x49cc) = puVar1;
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glClearDepth_Exec @ 0x31554 (140 bytes) */
void _glClearDepth_Exec(int glContext,double depth)
{
  uint uVar1;
  bool bVar2;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
      return;
    }
    return;
  }
  bVar2 = depth < DOUBLE_00108d60;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x10;
  if (bVar2) {
    uVar1 = 0;
  }
  else {
    if (!(DOUBLE_00108d68 < depth)) goto LAB_000315d4;
    uVar1 = 0x3ff00000;
  }
  depth = GH_U2D((unsigned long long)uVar1 << 0x20);
LAB_000315d4:
  *(double *)(glContext + 0x30e8) = depth;
  return;
}

/* _glDepthFunc_Exec @ 0x315e0 (88 bytes) */
void _glDepthFunc_Exec(glContext, func)
  int glContext;
  int func;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((7 < func - 0x200U) && (*(int *)(glContext + 0x7574) == 0)) {
      *(undefined4 *)(glContext + 0x7574) = 0x500;
    }
    *(short *)(glContext + 0x3124) = (short)func;
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x200;
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _gleSetEnable_LINE_SMOOTH @ 0x31638 (32 bytes) */
void _gleSetEnable_LINE_SMOOTH(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x318d) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x318d) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x4000;
  return;
}

/* _glLightfv_Exec @ 0x31658 (1460 bytes) */
void _glLightfv_Exec(int glContext,int light,undefined4 pname,float *params,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10)
{
  byte bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 glErrorCode;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  double dVar11;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00031c00;
  }
  uVar10 = light - 0x4000;
  if (7 < uVar10) {
switchD_000316d0_default:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
    goto LAB_00031c00;
  }
  iVar7 = glContext + uVar10 * 0x80;
  switch(pname) {
  case 0x1200:
    *(float *)(iVar7 + 0x2820) = *params;
    *(float *)(iVar7 + 0x2824) = params[1];
    *(float *)(iVar7 + 0x2828) = params[2];
    *(float *)(iVar7 + 0x282c) = params[3];
    *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) =
         *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) | 0x1e;
    *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) =
         *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) | 0x1e;
    if (*(int *)(glContext + 0x5434) == 0) {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(glContext + 0x5420) + 600);
    }
    else {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x28c);
    }
    iVar9 = (bVar1 >> 3 & 0x1c) + glContext;
    iVar7 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
    uVar8 = (uint)*(byte *)(uVar10 * 7 + iVar7 + 600);
    break;
  case 0x1201:
    *(float *)(iVar7 + 0x2830) = *params;
    *(float *)(iVar7 + 0x2834) = params[1];
    *(float *)(iVar7 + 0x2838) = params[2];
    *(float *)(iVar7 + 0x283c) = params[3];
    *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) =
         *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) | 0x1e;
    *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) =
         *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) | 0x1e;
    if (*(int *)(glContext + 0x5434) == 0) {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(glContext + 0x5420) + 0x259);
    }
    else {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x28d);
    }
    iVar9 = (bVar1 >> 3 & 0x1c) + glContext;
    iVar7 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
    uVar8 = (uint)*(byte *)(uVar10 * 7 + iVar7 + 0x259);
    break;
  case 0x1202:
    *(float *)(iVar7 + 0x2840) = *params;
    *(float *)(iVar7 + 0x2844) = params[1];
    *(float *)(iVar7 + 0x2848) = params[2];
    *(float *)(iVar7 + 0x284c) = params[3];
    *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) =
         *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) | 0x1e;
    *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) =
         *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) | 0x1e;
    if (*(int *)(glContext + 0x5434) == 0) {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(glContext + 0x5420) + 0x25a);
    }
    else {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x28e);
    }
    iVar9 = (bVar1 >> 3 & 0x1c) + glContext;
    iVar7 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
    uVar8 = (uint)*(byte *)(uVar10 * 7 + iVar7 + 0x25a);
    break;
  case 0x1203:
    fVar5 = *params;
    *(float *)(iVar7 + 0x2850) = fVar5;
    fVar2 = params[1];
    *(float *)(iVar7 + 0x2854) = fVar2;
    fVar3 = params[2];
    *(float *)(iVar7 + 0x2858) = fVar3;
    fVar4 = params[3];
    *(float *)(iVar7 + 0x285c) = fVar4;
    *(float *)(iVar7 + 0x2850) =
         fVar4 * *(float *)(glContext + 0x1cf0) +
         (fVar3 * *(float *)(glContext + 0x1ce0) +
         (fVar5 * *(float *)(glContext + 0x1cc0) + fVar2 * *(float *)(glContext + 0x1cd0)));
    *(float *)(iVar7 + 0x2854) =
         fVar4 * *(float *)(glContext + 0x1cf4) +
         (fVar3 * *(float *)(glContext + 0x1ce4) +
         (fVar5 * *(float *)(glContext + 0x1cc4) + fVar2 * *(float *)(glContext + 0x1cd4)));
    *(float *)(iVar7 + 0x2858) =
         fVar4 * *(float *)(glContext + 0x1cf8) +
         (fVar3 * *(float *)(glContext + 0x1ce8) +
         (fVar5 * *(float *)(0x1cc8 + glContext) + fVar2 * *(float *)(glContext + 0x1cd8)));
    *(float *)(iVar7 + 0x285c) =
         fVar4 * *(float *)(glContext + 0x1cfc) +
         (fVar3 * *(float *)(glContext + 0x1cec) +
         (fVar5 * *(float *)(glContext + 0x1ccc) + fVar2 * *(float *)(glContext + 0x1cdc)));
    ((double (*)())_gleUpdateLightPosition)(glContext,uVar10,fparam_1);
    goto LAB_00031c08;
  case 0x1204:
    *(float *)(iVar7 + 0x2860) = *params;
    *(float *)(iVar7 + 0x2864) = params[1];
    *(float *)(iVar7 + 0x2868) = params[2];
    ((void (*)())_gleTransformLightDirection)(glContext,uVar10,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
               fparam_8,in_stack_ffffffa8,in_stack_ffffffb0);
    goto LAB_00031c08;
  case 0x1205:
    fVar5 = *params;
    if ((fVar5 < FLOAT_00108e50) ||
       ((float)((double)CONCAT44(0x43300000,
                                 *(uint *)(*(int *)(glContext + 0x468c) + 0xa4) ^ 0x80000000) -
               DOUBLE_00108d58) < fVar5)) goto LAB_00031bc8;
    *(float *)(iVar7 + 0x287c) = fVar5;
    _gleUpdateLightExponents(glContext,uVar10);
    if (*(int *)(glContext + 0x5434) == 0) {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(glContext + 0x5420) + 0x25d);
    }
    else {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x291);
    }
    iVar9 = (bVar1 >> 3 & 0x1c) + glContext;
    iVar7 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
    uVar8 = (uint)*(byte *)(uVar10 * 7 + iVar7 + 0x25d);
    break;
  case 0x1206:
    fVar5 = *params;
    if ((FLOAT_00108e50 <= fVar5) && (fVar5 <= FLOAT_00108e88)) {
      *(float *)(iVar7 + 0x2890) = fVar5;
      dVar11 = _cos((double)(*params * FLOAT_00108e84));
      *(float *)(iVar7 + 0x286c) = (float)dVar11;
    }
    else {
      if (fVar5 != FLOAT_00108e8c) goto LAB_00031bc8;
      *(undefined4 *)(iVar7 + 0x2890) = 0;
      *(undefined4 *)(iVar7 + 0x286c) = 0xbf800000;
    }
    _gleUpdateLightExponents(glContext,uVar10);
    if (*(int *)(glContext + 0x5434) == 0) {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(glContext + 0x5420) + 0x25c);
    }
    else {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x290);
    }
    iVar9 = (bVar1 >> 3 & 0x1c) + glContext;
    iVar7 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
    uVar8 = (uint)*(byte *)(uVar10 * 7 + iVar7 + 0x25c);
    break;
  case 0x1207:
    if (!(*params < FLOAT_00108e50)) {
      *(float *)(iVar7 + 0x2870) = *params;
LAB_00031be0:
      _gleUpdateLightAttenuation(glContext,uVar10);
      goto LAB_00031c08;
    }
    goto LAB_00031bc8;
  case 0x1208:
    if (!(*params < FLOAT_00108e50)) {
      *(float *)(iVar7 + 0x2874) = *params;
      goto LAB_00031be0;
    }
    goto LAB_00031bc8;
  case 0x1209:
    if (!(*params < FLOAT_00108e50)) {
      *(float *)(iVar7 + 0x2878) = *params;
      goto LAB_00031be0;
    }
LAB_00031bc8:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
LAB_00031c00:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  default:
    goto switchD_000316d0_default;
  }
  iVar7 = (uVar8 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar7 + 0x348) = *(uint *)(iVar7 + 0x348) | 1 << (uVar8 & 0x1f);
LAB_00031c08:
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 4 << (uVar10 * 2 & 0x3e);
  return;
}

/* _gleSetEnable_LIGHT @ 0x31c34 (144 bytes) */
void _gleSetEnable_LIGHT(glContext, param_2, param_3)
  int glContext;
  int param_2;
  int param_3;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_2 - 0x4000;
  uVar1 = *(uint *)(glContext + 0x30a0) &
          (-2 << (uVar2 & 0x1f) | 0xfffffffeU >> 0x20 - (uVar2 & 0x1f)) | param_3 << (uVar2 & 0x3f);
  if (*(uint *)(glContext + 0x30a0) != uVar1) {
    *(uint *)(glContext + 0x30a0) = uVar1;
    *(undefined1 *)(*(int *)(glContext + 0x4dd0) + 0x234) = 0x1f;
    *(undefined1 *)(*(int *)(glContext + 0x4dd4) + 0x234) = 0x1f;
    _gleUpdateLightFast(glContext,uVar2);
    _gleUpdateLightModelFunc(glContext);
    *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 8 << (uVar2 * 2 & 0x3e);
  }
  return;
}

/* _gleSetEnable_LIGHTING @ 0x31cc4 (220 bytes) */
void _gleSetEnable_LIGHTING(glContext, param_2, param_3)
  int glContext;
  undefined4 param_2;
  uint param_3;
{
  undefined *puVar1;
  undefined1 uVar2;
  
  if (*(byte *)(glContext + 0x30aa) != param_3) {
    *(char *)(glContext + 0x30aa) = (char)param_3;
    if (*(char *)(glContext + 0x4664) == '\0') {
      if (param_3 == 0) {
        uVar2 = *(undefined1 *)(glContext + 0x4fea);
      }
      else {
        uVar2 = *(short *)(glContext + 0x30a8) == -0x7e06;
      }
      *(undefined1 *)(glContext + 0x316b) = uVar2;
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800;
    }
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | 1;
    *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 2;
    _gleUpdateInverseNeeds(glContext);
    _gleSelectVertexSubmitFunc(glContext);
    _gleSelectVertexAddMaterialFunc(glContext);
    puVar1 = PTR__gleSetClipInterpFunc_00112038;
    *(undefined **)(glContext + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
    *(undefined **)(glContext + 0x49cc) = puVar1;
    _gleUpdatePolyMode(glContext);
    return;
  }
  return;
}

/* _gleSetEnable_RESCALE_NORMAL_EXT @ 0x31da0 (44 bytes) */
void _gleSetEnable_RESCALE_NORMAL_EXT(glContext, param_2, param_3)
  int glContext;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(glContext + 0x280e) == param_3) {
    return;
  }
  *(char *)(glContext + 0x280e) = (char)param_3;
  *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) | 0x10;
  *(uint *)(glContext + 0x318) = *(uint *)(glContext + 0x318) | 0x80000000;
  return;
}

/* _glClear_Exec @ 0x31dcc (704 bytes) */
void _glClear_Exec(int glContext,uint mask,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  int remaining;
  int loopIndex;
  bool bVar1;
  char cVar2;
  undefined4 glErrorCode;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00032028;
  }
  if ((mask & 0xffffb8ff) != 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_00032028;
  }
  if (*(int *)(glContext + 0x4e1c) != 0x1c00) {
    return;
  }
  iVar6 = *(int *)(glContext + 0x50ac);
  if (iVar6 != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_00032054;
  iVar5 = *(int *)(glContext + 0x744c);
  piVar8 = (int *)(glContext + 0x310);
  cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00031f2c:
    uVar7 = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    piVar4 = (int *)(glContext + 0x324);
    do {
      iVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar5 != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 9);
    uVar7 = *(uint *)(glContext + 0x31c);
    if ((uVar7 & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        ((double (*)())_gleUpdateLightRGBASums)(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        ((double (*)())_gleUpdateLightRGBASums)(glContext,glContext + 0x2e60,1);
      }
      goto LAB_00031f2c;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar7 = uVar7 & 0x17000000;
  }
  else {
    uVar7 = uVar7 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar8 == 0 && *(int *)(glContext + 0x314) == 0) && uVar7 == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    bVar1 = (((*piVar8 == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      uVar7 = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar8);
      if ((((uVar7 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
          ((uVar7 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
         ((uVar7 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if ((uVar7 & 4) == 0) {
          uVar7 = uVar7 & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(glContext,uVar7);
        if (*(char *)(glContext + 0x759d) == '\0') {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x506;
LAB_00032028:
          *(undefined4 *)(glContext + 0x7574) = glErrorCode;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(glContext);
    }
    remaining = 0x13;
    do {
      *piVar8 = 0;
      piVar8 = piVar8 + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
LAB_00032054:
                    
                    
  (**(code **)(glContext + 0x469c))(*(undefined4 *)(glContext + 0x4688),mask);
  return;
}

/* _gliDispatchNoop @ 0x3208c (8 bytes) */
int _gliDispatchNoop()
{
  return 0;
}

/* _glTranslate_Exec @ 0x32098 (448 bytes) */
void _glTranslate_Exec(int glContext,float x,float y,float z)
{
  float *pfVar1;
  uint uVar2;
  uint uVar3;
  float dVar4;
  float dVar5;
  float dVar6;
  float dVar7;
  
  pfVar1 = *(float **)(glContext + 0x4fec);
  uVar3 = *(uint *)(glContext + 0x50a8);
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    pfVar1[0xc] = pfVar1[0xc] +
                  (pfVar1[8] * z + (*pfVar1 * x + (pfVar1[4] * y)));
    pfVar1[0xd] = pfVar1[0xd] +
                  (pfVar1[9] * z + (pfVar1[1] * x + (pfVar1[5] * y)));
    pfVar1[0xe] = pfVar1[0xe] +
                  (pfVar1[10] * z + (pfVar1[2] * x + (pfVar1[6] * y)));
    pfVar1[0xf] = pfVar1[0xf] +
                  (pfVar1[0xb] * z + (pfVar1[3] * x + (pfVar1[7] * y)));
    uVar2 = *(uint *)(glContext + 0x50b0);
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | uVar3;
    if ((uVar3 & ~uVar2 & *(uint *)(glContext + 0x505c) & 0xfffffc) != 0) {
      pfVar1 = *(float **)(glContext + 0x4ff0);
      uVar3 = uVar3 & 0xff000003;
      dVar4 = (double)pfVar1[0xc];
      dVar5 = (double)pfVar1[0xd];
      dVar6 = (double)pfVar1[0xe];
      dVar7 = (double)pfVar1[0xf];
      *pfVar1 = -(x * dVar4 - *pfVar1);
      pfVar1[4] = -(y * dVar4 - pfVar1[4]);
      pfVar1[8] = -(z * dVar4 - pfVar1[8]);
      pfVar1[1] = -(x * dVar5 - pfVar1[1]);
      pfVar1[5] = -(y * dVar5 - pfVar1[5]);
      pfVar1[0xb] = -(z * dVar7 - pfVar1[0xb]);
      pfVar1[9] = -(z * dVar5 - pfVar1[9]);
      pfVar1[2] = -(x * dVar6 - pfVar1[2]);
      pfVar1[6] = -(y * dVar6 - pfVar1[6]);
      pfVar1[10] = -(z * dVar6 - pfVar1[10]);
      pfVar1[3] = -(x * dVar7 - pfVar1[3]);
      pfVar1[7] = -(y * dVar7 - pfVar1[7]);
      uVar2 = *(uint *)(glContext + 0x50b0);
    }
    *(uint *)(glContext + 0x50b0) = uVar2 | uVar3;
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _glPolygonMode_Exec @ 0x32258 (216 bytes) */
void _glPolygonMode_Exec(glContext, face, mode)
  int glContext;
  uint face;
  int mode;
{
  undefined4 glErrorCode;
  undefined2 uVar2;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_000322a8:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  if (2 < mode - 0x1b00U) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
    goto LAB_000322a8;
  }
  uVar2 = (undefined2)mode;
  if (face == 0x405) {
    *(undefined2 *)(glContext + 0x34d2) = uVar2;
    goto LAB_000322fc;
  }
  if (face < 0x406) {
    if (face == 0x404) {
LAB_000322d8:
      *(undefined2 *)(glContext + 0x34d0) = uVar2;
      goto LAB_000322fc;
    }
  }
  else if (face == 0x408) {
    *(undefined2 *)(glContext + 0x34d2) = uVar2;
    goto LAB_000322d8;
  }
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x500;
  }
LAB_000322fc:
  _gleUpdatePolyMode(glContext);
  _gleSelectVertexSubmitFunc(glContext);
  return;
}

/* _glRotatef_Exec @ 0x32330 (404 bytes) */
void _glRotatef_Exec(int glContext,double angle,double x,double y,double z)
{
  float fVar1;
  undefined4 in_LR;
  double dVar2;
  double dVar3;
  double fparam_3_00;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  fparam_3_00 = (double)*(float *)(glContext + 0x20);
  if ((y == fparam_3_00) && (z == fparam_3_00)) {
    fVar1 = FLOAT_00108e84;
    if (x < fparam_3_00) {
      fVar1 = FLOAT_00108eb0;
    }
    dVar2 = _sin((double)(float)(angle * (double)fVar1));
    dVar3 = _cos((double)(float)(angle * (double)fVar1));
    ((void (*)())_glRotateX_Exec)(glContext,(double)(float)dVar2,(double)(float)dVar3,fparam_3_00,z,in_f5,
                    in_f6,in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  if ((x == fparam_3_00) && (z == fparam_3_00)) {
    fVar1 = FLOAT_00108e84;
    if (y < fparam_3_00) {
      fVar1 = FLOAT_00108eb0;
    }
    dVar2 = _sin((double)(float)(angle * (double)fVar1));
    dVar3 = _cos((double)(float)(angle * (double)fVar1));
    ((void (*)())_glRotateY_Exec)(glContext,(double)(float)dVar2,(double)(float)dVar3,fparam_3_00,z,in_f5,
                    in_f6,in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  if ((x == fparam_3_00) && (y == fparam_3_00)) {
    fVar1 = FLOAT_00108e84;
    if (z < fparam_3_00) {
      fVar1 = FLOAT_00108eb0;
    }
    dVar2 = _sin((double)(float)(angle * (double)fVar1));
    dVar3 = _cos((double)(float)(angle * (double)fVar1));
    ((void (*)())_glRotateZ_Exec)(glContext,(double)(float)dVar2,(double)(float)dVar3,fparam_3_00,z,in_f5,
                    in_f6,in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  ((void (*)())_glRotateXYZ_Exec)(glContext,angle,x,y,z);
  return;
}

/* _glRotateZ_Exec @ 0x324c4 (372 bytes) */
void _glRotateZ_Exec(int glContext,float fparam_1,float fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  float *pfVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(glContext + 0x50a8);
  pfVar3 = *(float **)(glContext + 0x4fec);
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    fVar1 = pfVar3[4];
    fVar2 = pfVar3[1];
    pfVar3[4] = (fVar1 * fparam_2 - (*pfVar3 * fparam_1));
    *pfVar3 = (*pfVar3 * fparam_2 + (fVar1 * fparam_1));
    fVar1 = pfVar3[6];
    pfVar3[1] = (fVar2 * fparam_2 + (pfVar3[5] * fparam_1));
    pfVar3[5] = (pfVar3[5] * fparam_2 - (fVar2 * fparam_1));
    fVar2 = pfVar3[3];
    pfVar3[6] = (fVar1 * fparam_2 - (pfVar3[2] * fparam_1));
    pfVar3[2] = (pfVar3[2] * fparam_2 + (fVar1 * fparam_1));
    pfVar3[3] = (fVar2 * fparam_2 + (pfVar3[7] * fparam_1));
    pfVar3[7] = (pfVar3[7] * fparam_2 - (fVar2 * fparam_1));
    uVar4 = *(uint *)(glContext + 0x50b0);
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | uVar5;
    if ((uVar5 & ~uVar4 & *(uint *)(glContext + 0x505c) & 0xfffffc) != 0) {
      pfVar3 = *(float **)(glContext + 0x4ff0);
      uVar5 = uVar5 & 0xff000003;
      fVar1 = pfVar3[4];
      fVar2 = pfVar3[1];
      pfVar3[4] = (fVar1 * fparam_2 - (*pfVar3 * fparam_1));
      *pfVar3 = (*pfVar3 * fparam_2 + (fVar1 * fparam_1));
      fVar1 = pfVar3[6];
      pfVar3[1] = (fVar2 * fparam_2 + (pfVar3[5] * fparam_1));
      pfVar3[5] = (pfVar3[5] * fparam_2 - (fVar2 * fparam_1));
      fVar2 = pfVar3[3];
      pfVar3[6] = (fVar1 * fparam_2 - (pfVar3[2] * fparam_1));
      pfVar3[2] = (pfVar3[2] * fparam_2 + (fVar1 * fparam_1));
      pfVar3[3] = (fVar2 * fparam_2 + (pfVar3[7] * fparam_1));
      pfVar3[7] = (pfVar3[7] * fparam_2 - (fVar2 * fparam_1));
      uVar4 = *(uint *)(glContext + 0x50b0);
    }
    *(uint *)(glContext + 0x50b0) = uVar4 | uVar5;
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glRotateY_Exec @ 0x32638 (372 bytes) */
void _glRotateY_Exec(int glContext,float fparam_1,float fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  float *pfVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(glContext + 0x50a8);
  pfVar3 = *(float **)(glContext + 0x4fec);
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    fVar1 = pfVar3[8];
    fVar2 = pfVar3[1];
    pfVar3[8] = (fVar1 * fparam_2 + (*pfVar3 * fparam_1));
    *pfVar3 = (*pfVar3 * fparam_2 - (fVar1 * fparam_1));
    fVar1 = pfVar3[10];
    pfVar3[1] = (fVar2 * fparam_2 - (pfVar3[9] * fparam_1));
    pfVar3[9] = (pfVar3[9] * fparam_2 + (fVar2 * fparam_1));
    fVar2 = pfVar3[3];
    pfVar3[10] = (fVar1 * fparam_2 + (pfVar3[2] * fparam_1));
    pfVar3[2] = (pfVar3[2] * fparam_2 - (fVar1 * fparam_1));
    pfVar3[3] = (fVar2 * fparam_2 - (pfVar3[0xb] * fparam_1));
    pfVar3[0xb] = (pfVar3[0xb] * fparam_2 + (fVar2 * fparam_1));
    uVar4 = *(uint *)(glContext + 0x50b0);
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | uVar5;
    if ((uVar5 & ~uVar4 & *(uint *)(glContext + 0x505c) & 0xfffffc) != 0) {
      pfVar3 = *(float **)(glContext + 0x4ff0);
      uVar5 = uVar5 & 0xff000003;
      fVar1 = pfVar3[8];
      fVar2 = pfVar3[1];
      pfVar3[8] = (fVar1 * fparam_2 + (*pfVar3 * fparam_1));
      *pfVar3 = (*pfVar3 * fparam_2 - (fVar1 * fparam_1));
      fVar1 = pfVar3[10];
      pfVar3[1] = (fVar2 * fparam_2 - (pfVar3[9] * fparam_1));
      pfVar3[9] = (pfVar3[9] * fparam_2 + (fVar2 * fparam_1));
      fVar2 = pfVar3[3];
      pfVar3[10] = (fVar1 * fparam_2 + (pfVar3[2] * fparam_1))
      ;
      pfVar3[2] = (pfVar3[2] * fparam_2 - (fVar1 * fparam_1));
      pfVar3[3] = (fVar2 * fparam_2 - (pfVar3[0xb] * fparam_1));
      pfVar3[0xb] = (pfVar3[0xb] * fparam_2 + (fVar2 * fparam_1));
      uVar4 = *(uint *)(glContext + 0x50b0);
    }
    *(uint *)(glContext + 0x50b0) = uVar4 | uVar5;
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glScale_Exec @ 0x327b0 (684 bytes) */
void _glScale_Exec(int glContext,float x,float y,float z)
{
  float fVar1;
  float fVar2;
  float dVar3;
  float *pfVar4;
  uint uVar5;
  uint uVar6;
  float dVar7;
  float dVar8;
  float dVar9;
  float dVar10;
  
  pfVar4 = *(float **)(glContext + 0x4fec);
  uVar6 = *(uint *)(glContext + 0x50a8);
  if ((-1 < *(short *)(glContext + 0x4a10)) || (0x17 < *(int *)(glContext + 0x4ff4))) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(glContext + 0x7574) = 0x502;
    return;
  }
  *pfVar4 = (*pfVar4 * x);
  pfVar4[4] = (pfVar4[4] * y);
  pfVar4[8] = (pfVar4[8] * z);
  pfVar4[1] = (pfVar4[1] * x);
  pfVar4[0xb] = (pfVar4[0xb] * z);
  pfVar4[5] = (pfVar4[5] * y);
  pfVar4[9] = (pfVar4[9] * z);
  pfVar4[2] = (pfVar4[2] * x);
  pfVar4[6] = (pfVar4[6] * y);
  pfVar4[10] = (pfVar4[10] * z);
  pfVar4[3] = (pfVar4[3] * x);
  pfVar4[7] = (pfVar4[7] * y);
  *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | uVar6;
  fVar1 = FLOAT_00108eb4;
  if (*(char *)(glContext + 0x280e) == '\0') {
    uVar5 = *(uint *)(glContext + 0x50b0);
    if ((uVar6 & ~uVar5 & *(uint *)(glContext + 0x505c) & 0xfffffc) == 0) goto LAB_00032a4c;
    dVar8 = (double)FLOAT_00108e50;
    dVar10 = (double)FLOAT_00108e80;
    dVar9 = (double)FLOAT_00108e54;
    pfVar4 = *(float **)(glContext + 0x4ff0);
    dVar3 = x;
    if (!((double)dVar8 <= x)) {
      dVar3 = -x;
    }
    if ((double)dVar10 <= (double)dVar3) {
      fVar2 = (dVar9 / x);
    }
    else {
      fVar2 = FLOAT_00108eb4;
      if (!((double)dVar8 <= x)) {
        fVar2 = -FLOAT_00108eb4;
      }
    }
    dVar7 = (double)FLOAT_00108e50;
    *pfVar4 = *pfVar4 * fVar2;
    pfVar4[2] = pfVar4[2] * fVar2;
    pfVar4[3] = pfVar4[3] * fVar2;
    pfVar4[1] = pfVar4[1] * fVar2;
    dVar3 = y;
    if (!((double)dVar7 <= y)) {
      dVar3 = -y;
    }
    if ((double)dVar10 <= (double)dVar3) {
      fVar2 = (dVar9 / y);
    }
    else {
      fVar2 = fVar1;
      if (!((double)dVar8 <= y)) {
        fVar2 = -fVar1;
      }
    }
    dVar7 = (double)FLOAT_00108e50;
    pfVar4[4] = pfVar4[4] * fVar2;
    pfVar4[6] = pfVar4[6] * fVar2;
    pfVar4[7] = pfVar4[7] * fVar2;
    pfVar4[5] = pfVar4[5] * fVar2;
    dVar3 = z;
    if (!((double)dVar7 <= z)) {
      dVar3 = -z;
    }
    if ((double)dVar10 <= (double)dVar3) {
      fVar1 = (dVar9 / z);
    }
    else if (!((double)dVar8 <= z)) {
      fVar1 = -fVar1;
    }
    uVar6 = uVar6 & 0xff000003;
    pfVar4[8] = pfVar4[8] * fVar1;
    pfVar4[9] = pfVar4[9] * fVar1;
    pfVar4[10] = pfVar4[10] * fVar1;
    pfVar4[0xb] = pfVar4[0xb] * fVar1;
  }
  uVar5 = *(uint *)(glContext + 0x50b0);
LAB_00032a4c:
  *(uint *)(glContext + 0x50b0) = uVar5 | uVar6;
  return;
}

/* _glMaterialfv_Exec @ 0x32a5c (1184 bytes) */
void _glMaterialfv_Exec(int glContext,uint face,undefined *pname,float *params,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 glErrorCode;
  uint uVar6;
  int iVar7;
  uint uVar8;
  double fparam_1_00;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  undefined4 local_30;
  uint uStack_2c;
  
  if (((*(char *)(glContext + 0x7580) != '\0') && (-1 < *(short *)(glContext + 0x4a10))) &&
     (*(char *)(glContext + 0x4664) == '\0')) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  }
  if (pname == (undefined *)0x1600) {
    local_34 = params[3];
    local_40 = *params;
    local_3c = params[1];
    local_38 = params[2];
    if (face == 0x405) {
      _gleLightMaterialRGBAChange_B_E(glContext,&local_40);
      goto LAB_00032eb8;
    }
    if (face < 0x406) {
      if (face == 0x404) {
        _gleLightMaterialRGBAChange_F_E(glContext,&local_40);
        goto LAB_00032eb8;
      }
    }
    else if (face == 0x408) {
      _gleLightMaterialRGBAChange_FB_E(glContext,&local_40);
      goto LAB_00032eb8;
    }
  }
  else if (pname < (undefined *)0x1601) {
    if (pname == ((unsigned char *)0x00001201)) {
      local_34 = params[3];
      local_40 = *params;
      local_3c = params[1];
      local_38 = params[2];
      if (face == 0x405) {
        _gleLightMaterialRGBAChange_B_D(glContext,&local_40);
        goto LAB_00032eb8;
      }
      if (face < 0x406) {
        if (face == 0x404) {
          _gleLightMaterialRGBAChange_F_D(glContext,&local_40);
          goto LAB_00032eb8;
        }
      }
      else if (face == 0x408) {
        _gleLightMaterialRGBAChange_FB_D(glContext,&local_40);
        goto LAB_00032eb8;
      }
    }
    else if (((unsigned char *)0x00001201) < pname) {
      if (pname == ((unsigned char *)0x00001202)) {
        local_34 = params[3];
        local_40 = *params;
        local_3c = params[1];
        local_38 = params[2];
        if (face == 0x405) {
          _gleLightMaterialRGBAChange_B_S(glContext,&local_40);
          goto LAB_00032eb8;
        }
        if (face < 0x406) {
          if (face == 0x404) {
            _gleLightMaterialRGBAChange_F_S(glContext,&local_40);
            goto LAB_00032eb8;
          }
        }
        else if (face == 0x408) {
          _gleLightMaterialRGBAChange_FB_S(glContext,&local_40);
          goto LAB_00032eb8;
        }
      }
    }
    else if (pname == ((unsigned char *)0x00001200)) {
      local_34 = params[3];
      local_40 = *params;
      local_3c = params[1];
      local_38 = params[2];
      if (face == 0x405) {
        _gleLightMaterialRGBAChange_B_A(glContext,&local_40);
        goto LAB_00032eb8;
      }
      if (face < 0x406) {
        if (face == 0x404) {
          _gleLightMaterialRGBAChange_F_A(glContext,&local_40);
          goto LAB_00032eb8;
        }
      }
      else if (face == 0x408) {
        _gleLightMaterialRGBAChange_FB_A(glContext,&local_40);
        goto LAB_00032eb8;
      }
    }
  }
  else if (pname == (undefined *)0x1602) {
    local_34 = params[3];
    local_40 = *params;
    local_3c = params[1];
    local_38 = params[2];
    if (face == 0x405) {
      _gleLightMaterialRGBAChange_B_AD(glContext,&local_40);
      goto LAB_00032eb8;
    }
    if (face < 0x406) {
      if (face == 0x404) {
        _gleLightMaterialRGBAChange_F_AD(glContext,&local_40);
        goto LAB_00032eb8;
      }
    }
    else if (face == 0x408) {
      _gleLightMaterialRGBAChange_FB_AD(glContext,&local_40);
      goto LAB_00032eb8;
    }
  }
  else {
    if (pname < (undefined *)0x1602) {
      fparam_1_00 = (double)*params;
      if (!(fparam_1_00 < (double)FLOAT_00108e50)) {
        local_30 = 0x43300000;
        uStack_2c = *(uint *)(*(int *)(glContext + 0x468c) + 0xa0) ^ 0x80000000;
        if (!((double)(float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58) <
             fparam_1_00)) {
          if (face == 0x405) {
            ((void (*)())_gleLightMaterialShineChange_B)(glContext,fparam_1_00);
            goto LAB_00032eb8;
          }
          if (face < 0x406) {
            if (face == 0x404) {
              ((void (*)())_gleLightMaterialShineChange_F)(glContext,fparam_1_00);
              goto LAB_00032eb8;
            }
          }
          else if (face == 0x408) {
            ((void (*)())_gleLightMaterialShineChange_FB)(glContext,fparam_1_00);
            goto LAB_00032eb8;
          }
          goto LAB_00032ea0;
        }
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_00032eb0;
    }
    if (pname == (undefined *)0x1603) {
      fVar1 = params[2] * FLOAT_00108e5c;
      fVar2 = *params * FLOAT_00108e5c;
      fVar3 = params[1] * FLOAT_00108e5c;
      if (face == 0x405) {
        uVar8 = 1;
        uVar6 = 1;
LAB_00032e68:
        if (uVar6 <= uVar8) {
          iVar4 = (uVar8 + 1) - uVar6;
          iVar7 = uVar6 * 0x10 + glContext;
          do {
            *(float *)(iVar7 + 0x2f0) = fVar2;
            *(float *)(iVar7 + 0x2f4) = fVar3;
            *(float *)(iVar7 + 0x2f8) = fVar1;
            iVar7 = iVar7 + 0x10;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
LAB_00032eb8:
        if (((*(char *)(glContext + 0x4df8) != '\0') && (pname != (undefined *)0x1601)) &&
           (pname != (undefined *)0x1603)) {
          (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
        }
        return;
      }
      if (face < 0x406) {
        if (face == 0x404) {
          uVar8 = 0;
          uVar6 = 0;
          goto LAB_00032e68;
        }
      }
      else if (face == 0x408) {
        uVar6 = 0;
        uVar8 = 1;
        goto LAB_00032e68;
      }
    }
  }
LAB_00032ea0:
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_00032eb0:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

