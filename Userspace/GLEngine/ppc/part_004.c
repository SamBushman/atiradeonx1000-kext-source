#include "decls.h"

/* _gleIsIndex @ 0x2f1ac (20 bytes) */
int _gleIsIndex(param_1)
  int param_1;
{
  return param_1 - 0x1900U < 2;
}

/* FUN_0002f1c4 @ 0x2f1c4 (172 bytes) */
int FUN_0002f1c4(param_1, param_2)
  int param_1;
  int param_2;
{
  float fVar1;
  uint unaff_r2;
  
  fVar1 = FLOAT_00108e78;
  *(float *)(param_1 + 4) = (GH_U2F((unsigned int)((unaff_r2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(param_1 + 8) = (GH_U2F((unsigned int)((*(byte *)(param_2 + 1) | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0xc) = (GH_U2F((unsigned int)((*(byte *)(param_2 + 2) | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0x10) = (GH_U2F((unsigned int)((*(byte *)(param_2 + 3) | 0x4b000000))) - 8388608.0) * fVar1;
  return;
}

/* _gleUpdateLightRGBASums @ 0x2f270 (1740 bytes) */
int _gleUpdateLightRGBASums(param_1, param_2, param_3)
  int param_1;
  float *param_2;
  int param_3;
{
  byte bVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float *pfVar12;
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
  double dVar25;
  double dVar26;
  double dVar27;
  
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
      fVar4 = *(float *)(param_1 + 0x2810) * *param_2 + param_2[0xc];
      fVar9 = *(float *)(param_1 + 0x2814) * param_2[1] + param_2[0xd];
      fVar10 = *(float *)(param_1 + 0x2818) * param_2[2] + param_2[0xe];
      param_2[0x7a] = fVar4;
      param_2[0x77] = param_2[7];
      param_2[0x7b] = fVar9;
      param_2[0x7c] = fVar10;
      param_2[0x74] = fVar4;
      param_2[0x75] = fVar9;
      param_2[0x76] = fVar10;
      if (*(int *)(param_1 + 0x5434) == 0) {
        bVar1 = *(byte *)(param_3 * 6 + *(int *)(param_1 + 0x5420) + 0x2c5);
      }
      else {
        bVar1 = *(byte *)(param_3 * 6 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2f9);
      }
      iVar21 = (bVar1 >> 3 & 0x1c) + param_1;
      iVar22 = *(int *)(param_1 + 0x5424);
      *(uint *)(iVar21 + 0x324) = *(uint *)(iVar21 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(param_3 * 6 + iVar22 + 0x2c5);
      iVar22 = (bVar1 >> 3 & 0x1c) + param_1;
      *(uint *)(iVar22 + 0x348) = *(uint *)(iVar22 + 0x348) | 1 << (bVar1 & 0x1f);
    }
  }
  dVar26 = (double)param_2[0x10];
  if (((bVar2 & 1) != 0) && (dVar26 != (double)param_2[0x7d])) {
    if ((uVar19 & 1) == 0) {
      param_2[0x7d] = param_2[0x10];
      if (dVar26 <= (double)FLOAT_00108e80) {
        iVar22 = 0xb;
        param_2[0x81] = 1.0;
        param_2[0x7e] = 1.0;
        pfVar5 = param_2 + 0x82;
        param_2[0x7f] = 1.0;
        param_2[0x80] = 1.0;
        do {
          *pfVar5 = 1.0;
          pfVar5 = pfVar5 + 1;
          iVar22 = iVar22 + -1;
        } while (iVar22 != 0);
      }
      else {
        dVar27 = (double)FLOAT_00108e54;
        uVar8 = 0;
        dVar24 = (double)_log(DOUBLE_00108dd8);
        fVar9 = FLOAT_00108f44;
        pfVar5 = param_2 + 0x82;
        dVar24 = (double)_exp(dVar24 / dVar26);
        dVar25 = (double)(float)dVar24;
        dVar23 = (double)FLOAT_00108f40;
        param_2[0x7e] = (float)dVar24;
        dVar24 = DOUBLE_00108de0;
        param_2[0x80] = (float)(dVar23 / dVar25);
        param_2[0x7f] = fVar9 / (float)(dVar27 - dVar25);
        dVar24 = (double)_pow(dVar24,dVar26);
        fVar4 = param_2[0x7e];
        param_2[0x81] = (float)(dVar24 - DOUBLE_00108d68);
        dVar24 = (double)fVar4;
        do {
          uVar8 = uVar8 + 1;
          dVar23 = (double)_pow(dVar24,dVar26);
          *pfVar5 = (float)dVar23;
          pfVar5 = pfVar5 + 1;
          dVar24 = (double)(float)(dVar24 + (double)((float)(dVar27 - (double)fVar4) / fVar9));
        } while (uVar8 < 10);
        param_2[0x8c] = 1.0;
      }
    }
    else {
      fVar4 = *(float *)((int)GH_F2U(fVar3) + 0x1f8);
      iVar22 = 0xb;
      fVar9 = *(float *)((int)GH_F2U(fVar3) + 0x1fc);
      pfVar12 = param_2 + 0x82;
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
        *pfVar12 = fVar4;
        pfVar12 = pfVar12 + 1;
        iVar22 = iVar22 + -1;
      } while (iVar22 != 0);
    }
  }
  uVar20 = *(uint *)(param_1 + 0x30a0);
  uVar8 = 0;
  iVar21 = 0;
  iVar22 = param_1;
  do {
    if ((uVar20 & 1 << (uVar8 & 0x3f)) == 0) {
      if (uVar20 >> (uVar8 & 0x3f) == 0) {
        *(undefined1 *)(param_2 + 0x8d) = 0;
        FUN_00008b68();
        return;
      }
    }
    else {
      iVar6 = (int)GH_F2U(fVar3) + iVar21;
      if ((bVar2 >> 2 & 1) != 0) {
        if ((uVar19 & 4) == 0) {
          fVar4 = param_2[1];
          fVar9 = *(float *)(iVar22 + 0x2824);
          fVar10 = *(float *)(iVar22 + 0x2828);
          fVar11 = param_2[2];
          fVar14 = param_2[3];
          *(float *)((int)param_2 + iVar21 + 0x50) = *(float *)(iVar22 + 0x2820) * *param_2;
          *(float *)((int)param_2 + iVar21 + 0x54) = fVar9 * fVar4;
          *(float *)((int)param_2 + iVar21 + 0x5c) = fVar14;
          *(float *)((int)param_2 + iVar21 + 0x58) = fVar10 * fVar11;
        }
        else {
          uVar13 = *(undefined4 *)(iVar6 + 0x58);
          uVar7 = *(undefined4 *)(iVar6 + 0x54);
          uVar17 = *(undefined4 *)(iVar6 + 0x5c);
          *(undefined4 *)((int)param_2 + iVar21 + 0x50) = *(undefined4 *)(iVar6 + 0x50);
          *(undefined4 *)((int)param_2 + iVar21 + 0x54) = uVar7;
          *(undefined4 *)((int)param_2 + iVar21 + 0x58) = uVar13;
          *(undefined4 *)((int)param_2 + iVar21 + 0x5c) = uVar17;
        }
        if (*(int *)(param_1 + 0x5434) == 0) {
          bVar1 = *(byte *)(uVar8 * 6 + param_3 * 3 + *(int *)(param_1 + 0x5420) + 0x290);
        }
        else {
          bVar1 = *(byte *)(uVar8 * 6 + param_3 * 3 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) +
                           0x2c4);
        }
        iVar18 = (bVar1 >> 3 & 0x1c) + param_1;
        iVar15 = *(int *)(param_1 + 0x5424);
        *(uint *)(iVar18 + 0x324) = *(uint *)(iVar18 + 0x324) | 1 << (bVar1 & 0x1f);
        bVar1 = *(byte *)(uVar8 * 6 + param_3 * 3 + iVar15 + 0x290);
        iVar15 = (bVar1 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar15 + 0x348) = *(uint *)(iVar15 + 0x348) | 1 << (bVar1 & 0x1f);
      }
      if (((bVar2 & 0xe) != 0) && ((uVar19 & 0xe) != 0xe)) {
        param_2[0x7a] = param_2[0x7a] + *(float *)((int)param_2 + iVar21 + 0x50);
        param_2[0x7b] = param_2[0x7b] + *(float *)((int)param_2 + iVar21 + 0x54);
        param_2[0x7c] = param_2[0x7c] + *(float *)((int)param_2 + iVar21 + 0x58);
      }
      if ((bVar2 >> 3 & 1) != 0) {
        if ((uVar19 & 8) == 0) {
          fVar4 = param_2[5];
          fVar9 = *(float *)(iVar22 + 0x2834);
          fVar10 = *(float *)(iVar22 + 0x2838);
          fVar11 = param_2[6];
          fVar14 = param_2[7];
          *(float *)((int)param_2 + iVar21 + 0x60) = *(float *)(iVar22 + 0x2830) * param_2[4];
          *(float *)((int)param_2 + iVar21 + 100) = fVar9 * fVar4;
          *(float *)((int)param_2 + iVar21 + 0x6c) = fVar14;
          *(float *)((int)param_2 + iVar21 + 0x68) = fVar10 * fVar11;
        }
        else {
          uVar7 = *(undefined4 *)(iVar6 + 100);
          uVar13 = *(undefined4 *)(iVar6 + 0x68);
          uVar17 = *(undefined4 *)(iVar6 + 0x6c);
          *(undefined4 *)((int)param_2 + iVar21 + 0x60) = *(undefined4 *)(iVar6 + 0x60);
          *(undefined4 *)((int)param_2 + iVar21 + 100) = uVar7;
          *(undefined4 *)((int)param_2 + iVar21 + 0x68) = uVar13;
          *(undefined4 *)((int)param_2 + iVar21 + 0x6c) = uVar17;
        }
        if (*(int *)(param_1 + 0x5434) == 0) {
          bVar1 = *(byte *)(uVar8 * 6 + param_3 * 3 + *(int *)(param_1 + 0x5420) + 0x291);
        }
        else {
          bVar1 = *(byte *)(uVar8 * 6 + param_3 * 3 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) +
                           0x2c5);
        }
        iVar18 = (bVar1 >> 3 & 0x1c) + param_1;
        iVar15 = *(int *)(param_1 + 0x5424);
        *(uint *)(iVar18 + 0x324) = *(uint *)(iVar18 + 0x324) | 1 << (bVar1 & 0x1f);
        bVar1 = *(byte *)(uVar8 * 6 + param_3 * 3 + iVar15 + 0x291);
        iVar15 = (bVar1 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar15 + 0x348) = *(uint *)(iVar15 + 0x348) | 1 << (bVar1 & 0x1f);
      }
      if ((bVar2 & 0x10) != 0) {
        if ((uVar19 >> 4 & 1) == 0) {
          fVar4 = param_2[9];
          fVar9 = *(float *)(iVar22 + 0x2848);
          fVar10 = *(float *)(iVar22 + 0x2844);
          fVar11 = param_2[10];
          fVar14 = param_2[0xb];
          *(float *)((int)param_2 + iVar21 + 0x70) = *(float *)(iVar22 + 0x2840) * param_2[8];
          *(float *)((int)param_2 + iVar21 + 0x7c) = fVar14;
          *(float *)((int)param_2 + iVar21 + 0x74) = fVar10 * fVar4;
          *(float *)((int)param_2 + iVar21 + 0x78) = fVar9 * fVar11;
        }
        else {
          uVar7 = *(undefined4 *)(iVar6 + 0x70);
          uVar13 = *(undefined4 *)(iVar6 + 0x74);
          uVar17 = *(undefined4 *)(iVar6 + 0x78);
          *(undefined4 *)((int)param_2 + iVar21 + 0x7c) = *(undefined4 *)(iVar6 + 0x7c);
          *(undefined4 *)((int)param_2 + iVar21 + 0x70) = uVar7;
          *(undefined4 *)((int)param_2 + iVar21 + 0x74) = uVar13;
          *(undefined4 *)((int)param_2 + iVar21 + 0x78) = uVar17;
        }
        if (*(int *)(param_1 + 0x5434) == 0) {
          bVar1 = *(byte *)(uVar8 * 6 + param_3 * 3 + *(int *)(param_1 + 0x5420) + 0x292);
        }
        else {
          bVar1 = *(byte *)(uVar8 * 6 + param_3 * 3 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) +
                           0x2c6);
        }
        iVar15 = (bVar1 >> 3 & 0x1c) + param_1;
        iVar6 = *(int *)(param_1 + 0x5424);
        *(uint *)(iVar15 + 0x324) = *(uint *)(iVar15 + 0x324) | 1 << (bVar1 & 0x1f);
        bVar1 = *(byte *)(uVar8 * 6 + param_3 * 3 + iVar6 + 0x292);
        iVar6 = (bVar1 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (bVar1 & 0x1f);
      }
    }
    uVar8 = uVar8 + 1;
    iVar22 = iVar22 + 0x80;
    iVar21 = iVar21 + 0x30;
  } while( true );
}

/* _gliDestroyContext @ 0x2f93c (300 bytes) */
int _gliDestroyContext(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x467c) != 0x3463a223)) {
    return 0x2714;
  }
  iVar1 = ((int (*)())_gleTerminateContext)(param_1);
  iVar4 = param_1 + 0x10000;
  iVar2 = ((int (*)())_gleReleaseSharedState)(param_1);
  iVar5 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    do {
      iVar3 = (**(code **)(*(int *)(iVar4 + -0x777c) + 0x130))(*(undefined4 *)(iVar4 + -0x7a54));
      if (iVar1 == 0) {
        iVar1 = iVar3;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x2e0;
    } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  if (iVar2 != 0) {
    ((int (*)())_gleDestroySharedState)(param_1);
  }
  iVar2 = _gl_list;
  iVar4 = 0;
  if (_gl_list != 0) {
    do {
      iVar5 = iVar2;
      if (iVar5 == param_1) break;
      iVar2 = *(int *)(iVar5 + 0x85a0);
      iVar4 = iVar5;
    } while (*(int *)(iVar5 + 0x85a0) != 0);
    if (iVar4 != 0) {
      *(undefined4 *)(iVar4 + 0x85a0) = *(undefined4 *)(param_1 + 0x85a0);
      goto LAB_0002fa38;
    }
  }
  _gl_list = *(int *)(param_1 + 0x85a0);
LAB_0002fa38:
  if (_gl_list == 0) {
    ((int (*)())_gleDestroyEnableHashTable)();
  }
  ((int (*)())_gleDCBFree)(param_1);
  return iVar1;
}

/* _gleTerminateContext @ 0x2fa68 (192 bytes) */
int _gleTerminateContext(param_1)
  int param_1;
{
  ((int (*)())_gleFreeOrphans)(param_1);
  ((int (*)())_gleFreeVertexMachine)(param_1);
  ((int (*)())_gleFreePixelMap)(param_1);
  ((int (*)())_gleFreeMaterials)(param_1);
  ((int (*)())_gleFreeAllAttrib)(param_1);
  ((int (*)())_gleFreeVertexArrays)(param_1);
  ((int (*)())_gleFreeFunctions)(param_1);
  ((int (*)())_gleFreeQueryMachine)(param_1);
  ((int (*)())_gleFreeFenceMachine)(param_1);
  ((int (*)())_gleFreeVertexArrayState)(param_1);
  ((int (*)())_glePPEmulatorTerminate)(param_1);
  ((int (*)())_gleFreeBufferState)(param_1);
  ((int (*)())_gleFreeShaderState)(param_1);
  ((int (*)())_gleFreePipelineProgramState)(param_1);
  ((int (*)())_gleReclaimDrawPixelResources)(param_1);
  _gleFreeFramebufferState(param_1);
  ((int (*)())_gleFreeMapData)(param_1);
  ((int (*)())_gleFreeTextureState)(param_1);
  _gleVecFree(*(void **)(param_1 + 0x4678));
  return 0;
}

/* _gleFreeOrphans @ 0x2fb28 (264 bytes) */
int _gleFreeOrphans(param_1)
  int param_1;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int extraout_r3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  
  iVar3 = param_1;
  if (*(int *)(param_1 + 0x7484) != 0) {
    while( true ) {
      piVar5 = *(int **)(param_1 + 0x7470);
      piVar6 = (int *)0x0;
      if (piVar5 != (int *)(param_1 + 0x7468)) {
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
      iVar3 = param_1 + 0x10000;
      iVar7 = 0;
      if (*(char *)(param_1 + 0x85a4) != '\0') {
        piVar5 = piVar6 + 7;
        do {
          piVar1 = (int *)(iVar3 + -0x777c);
          iVar7 = iVar7 + 1;
          iVar4 = *piVar5;
          piVar5 = piVar5 + 1;
          puVar2 = (undefined4 *)(iVar3 + -0x7a54);
          iVar3 = iVar3 + 0x2e0;
          (**(code **)(*piVar1 + 0x1f8))(*puVar2,iVar4);
        } while (iVar7 < (int)(uint)*(byte *)(param_1 + 0x85a4));
      }
      _gleVecFree(piVar6);
    }
    _gleVecFree(*(void **)(param_1 + 0x7484));
    *(undefined4 *)(param_1 + 0x7484) = 0;
    iVar3 = 0;
    if (*(void **)(param_1 + 0x7464) != (void *)0x0) {
      _gleVecFree(*(void **)(param_1 + 0x7464));
      *(undefined4 *)(param_1 + 0x7464) = 0;
      iVar3 = extraout_r3;
    }
  }
  return iVar3;
}

/* _gleFreeVertexMachine @ 0x2fc30 (136 bytes) */
int _gleFreeVertexMachine(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x4854) != 0) {
    ((int (*)())_gleDCBFree)(*(int *)(param_1 + 0x4854) + -0x200);
    *(undefined4 *)(param_1 + 0x485c) = 0;
    *(undefined4 *)(param_1 + 0x4854) = 0;
    *(undefined4 *)(param_1 + 0x4860) = 0;
    *(undefined4 *)(param_1 + 0x4864) = 0;
    *(undefined4 *)(param_1 + 0x4870) = 0;
    *(undefined4 *)(param_1 + 0x4874) = 0;
    *(undefined4 *)(param_1 + 0x30b0) = 0;
    *(undefined4 *)(param_1 + 0x4858) = 0;
  }
  if (*(int *)(param_1 + 0x7588) != 0) {
    if (*(void **)(param_1 + 0x758c) != (void *)0x0) {
      _free(*(void **)(param_1 + 0x758c));
    }
    *(undefined4 *)(param_1 + 0x7588) = 0;
    *(undefined4 *)(param_1 + 0x758c) = 0;
  }
  return;
}

/* _gleDCBFree @ 0x2fcb8 (12 bytes) */
int _gleDCBFree(param_1)
  int param_1;
{
  undefined4 extraout_r3;
  
  _free((void *)(param_1 - (uint)*(byte *)(param_1 + -1)));
  return extraout_r3;
}

/* _gleFreePixelMap @ 0x2fcc4 (268 bytes) */
int _gleFreePixelMap(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gle_default_pix_map_i_00112044;
  if (*(undefined **)(param_1 + 0x3248) != PTR__gle_default_pix_map_i_00112044) {
    _free(*(undefined **)(param_1 + 0x3248));
    *(undefined **)(param_1 + 0x3248) = puVar1;
  }
  if (*(undefined **)(param_1 + 0x326c) != puVar1) {
    _free(*(undefined **)(param_1 + 0x326c));
    *(undefined **)(param_1 + 0x326c) = puVar1;
  }
  puVar1 = PTR__gle_default_pix_map_f_00112040;
  if (*(undefined **)(param_1 + 0x324c) != PTR__gle_default_pix_map_f_00112040) {
    _free(*(undefined **)(param_1 + 0x324c));
    *(undefined **)(param_1 + 0x324c) = puVar1;
  }
  if (*(undefined **)(param_1 + 0x3250) != puVar1) {
    _free(*(undefined **)(param_1 + 0x3250));
    *(undefined **)(param_1 + 0x3250) = puVar1;
  }
  if (*(undefined **)(param_1 + 0x3254) != puVar1) {
    _free(*(undefined **)(param_1 + 0x3254));
    *(undefined **)(param_1 + 0x3254) = puVar1;
  }
  if (*(undefined **)(param_1 + 0x3258) != puVar1) {
    _free(*(undefined **)(param_1 + 0x3258));
    *(undefined **)(param_1 + 0x3258) = puVar1;
  }
  if (*(undefined **)(param_1 + 0x325c) != puVar1) {
    _free(*(undefined **)(param_1 + 0x325c));
    *(undefined **)(param_1 + 0x325c) = puVar1;
  }
  if (*(undefined **)(param_1 + 0x3260) != puVar1) {
    _free(*(undefined **)(param_1 + 0x3260));
    *(undefined **)(param_1 + 0x3260) = puVar1;
  }
  if (*(undefined **)(param_1 + 0x3264) != puVar1) {
    _free(*(undefined **)(param_1 + 0x3264));
    *(undefined **)(param_1 + 0x3264) = puVar1;
  }
  if (*(undefined **)(param_1 + 0x3268) != puVar1) {
    _free(*(undefined **)(param_1 + 0x3268));
    *(undefined **)(param_1 + 0x3268) = puVar1;
  }
  return;
}

/* _gleFreeMaterials @ 0x2fdd0 (140 bytes) */
int _gleFreeMaterials(param_1)
  int param_1;
{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  void *pvVar4;
  
  puVar3 = (undefined4 *)(param_1 + 0x4dd0);
  iVar2 = 1;
  do {
    pvVar1 = (void *)*puVar3;
    for (pvVar4 = *(void **)((int)*puVar3 + 0x23c); pvVar4 != (void *)0x0;
        pvVar4 = *(void **)((int)pvVar4 + 0x23c)) {
      _gleVecFree(pvVar1);
      pvVar1 = pvVar4;
    }
    iVar2 = iVar2 + -1;
    *puVar3 = pvVar1;
    puVar3 = puVar3 + 1;
  } while (-1 < iVar2);
  pvVar1 = *(void **)(param_1 + 0x4dd8);
  while (pvVar1 != (void *)0x0) {
    pvVar4 = *(void **)((int)pvVar1 + 0x23c);
    _gleVecFree(pvVar1);
    pvVar1 = pvVar4;
  }
  *(undefined4 *)(param_1 + 0x4dd8) = 0;
  return;
}

/* _gleFreeAllAttrib @ 0x2fe5c (228 bytes) */
int _gleFreeAllAttrib(param_1)
  int param_1;
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  
  iVar3 = 0;
  iVar1 = *(int *)(param_1 + 0x50fc);
  if (0 < iVar1) {
    piVar5 = (int *)(param_1 + 0x50b8);
    do {
      pvVar2 = (void *)*piVar5;
      if ((void *)*piVar5 != (void *)0x0) {
        do {
          pvVar4 = *(void **)((int)pvVar2 + 0x2c44);
          _free(pvVar2);
          pvVar2 = pvVar4;
        } while (pvVar4 != (void *)0x0);
        iVar1 = *(int *)(param_1 + 0x50fc);
      }
      iVar3 = iVar3 + 1;
      *piVar5 = 0;
      piVar5 = piVar5 + 1;
    } while (iVar3 < iVar1);
  }
  iVar1 = *(int *)(param_1 + 0x5144);
  iVar3 = 0;
  if (0 < iVar1) {
    piVar5 = (int *)(param_1 + 0x5100);
    do {
      pvVar2 = (void *)*piVar5;
      if ((void *)*piVar5 != (void *)0x0) {
        do {
          pvVar4 = *(void **)((int)pvVar2 + 700);
          _free(pvVar2);
          pvVar2 = pvVar4;
        } while (pvVar4 != (void *)0x0);
        iVar1 = *(int *)(param_1 + 0x5144);
      }
      iVar3 = iVar3 + 1;
      *piVar5 = 0;
      piVar5 = piVar5 + 1;
    } while (iVar3 < iVar1);
  }
  *(int *)(param_1 + 0x5140) = param_1 + 0x5100;
  *(int *)(param_1 + 0x50f8) = param_1 + 0x50b8;
  *(undefined4 *)(param_1 + 0x5144) = 0;
  *(undefined4 *)(param_1 + 0x50fc) = 0;
  return;
}

/* _gleFreeVertexArrays @ 0x2ff40 (68 bytes) */
int _gleFreeVertexArrays(param_1)
  int param_1;
{
  if (*(void **)(param_1 + 0x49ac) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x49ac));
  }
  ((int (*)())_gleFreeFuncCache)(*(undefined4 *)(param_1 + 0x49b4));
  ((int (*)())_gleFreeFuncCache)(*(undefined4 *)(param_1 + 0x49b8));
  return;
}

/* _gleFreeFuncCache @ 0x2ff84 (68 bytes) */
int _gleFreeFuncCache(param_1)
  int *param_1;
{
  int *piVar1;
  int *piVar2;
  
  piVar1 = param_1;
  if (param_1 != (int *)0x0) {
    do {
      piVar2 = (int *)*piVar1;
      ((int (*)())_gleDCBFree)(piVar1);
      piVar1 = piVar2;
    } while (piVar2 != param_1);
  }
  return;
}

/* _gleFreeFunctions @ 0x2ffc8 (116 bytes) */
int _gleFreeFunctions(param_1)
  int param_1;
{
  ((int (*)())_gleFreeFuncCache)(*(undefined4 *)(param_1 + 0x5088));
  ((int (*)())_gleFreeFuncCache)(*(undefined4 *)(param_1 + 0x5094));
  ((int (*)())_gleFreeFuncCache)(*(undefined4 *)(param_1 + 0x50a0));
  ((int (*)())_gleFreeFuncCache)(*(undefined4 *)(param_1 + 0x49d0));
  ((int (*)())_gleFreeFuncCache)(*(undefined4 *)(param_1 + 0x49d8));
  ((int (*)())_gleFreeFuncCache)(*(undefined4 *)(param_1 + 0x48a0));
  ((int (*)())_gleFreeFuncCache)(*(undefined4 *)(param_1 + 0x48a8));
  ((int (*)())_gleFreeFuncCache)(*(undefined4 *)(param_1 + 0x48c0));
  ((int (*)())_gleFreeFuncCache)(*(undefined4 *)(param_1 + 0x48b0));
  ((int (*)())_gleFreeFuncCache)(*(undefined4 *)(param_1 + 0x48b8));
  return;
}

/* _gleFreeQueryMachine @ 0x3003c (136 bytes) */
int _gleFreeQueryMachine(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  void *pvVar6;
  
  piVar3 = (int *)(param_1 + 0x6440);
  iVar2 = 0x3ff;
  do {
    piVar4 = (int *)*piVar3;
    piVar3 = piVar3 + 1;
    while (piVar4 != (int *)0x0) {
      iVar5 = *piVar4;
      (*(code *)piVar4[3])(param_1,piVar4);
      piVar4 = (int *)iVar5;
    }
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  puVar1 = *(void **)(param_1 + 0x7440);
  while (puVar1 != (void *)0x0) {
    pvVar6 = (void *)*puVar1;
    _free(puVar1);
    puVar1 = pvVar6;
  }
  return;
}

/* _gleFreeFenceMachine @ 0x300c4 (136 bytes) */
int _gleFreeFenceMachine(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  void *pvVar6;
  
  piVar3 = (int *)(param_1 + 0x543c);
  iVar2 = 0x3ff;
  do {
    piVar4 = (int *)*piVar3;
    piVar3 = piVar3 + 1;
    while (piVar4 != (int *)0x0) {
      iVar5 = *piVar4;
      (*(code *)piVar4[3])(param_1,piVar4);
      piVar4 = (int *)iVar5;
    }
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  puVar1 = *(void **)(param_1 + 0x643c);
  while (puVar1 != (void *)0x0) {
    pvVar6 = (void *)*puVar1;
    _free(puVar1);
    puVar1 = pvVar6;
  }
  return;
}

/* _gleFreeVertexArrayState @ 0x3014c (180 bytes) */
int _gleFreeVertexArrayState(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x4a60);
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 4) != 0) {
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
      }
      iVar1 = *(int *)(iVar2 + 8) + -1;
      *(int *)(iVar2 + 8) = iVar1;
      if (iVar1 == 0) {
        ((int (*)())_gleFreeVertexArrayObject)(param_1,iVar2);
      }
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
      }
    }
    ((int (*)())_gleFreeVertexArrayObject)(param_1,*(undefined4 *)(param_1 + 0x4a64));
    return;
  }
  return;
}

/* _gleFreeVertexArrayObject @ 0x30200 (196 bytes) */
int _gleFreeVertexArrayObject(param_1, param_2)
  undefined4 param_1;
  void *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  ((int (*)())_gleDestroyPluginVertexArray)(param_1,(int)param_2 + 0x10);
  iVar3 = *(int *)((int)param_2 + 0x358);
  if ((iVar3 != 0) && (iVar1 = *(int *)(iVar3 + 8) + -1, *(int *)(iVar3 + 8) = iVar1, iVar1 == 0)) {
    _gleFreeBufferObject(param_1,iVar3);
  }
  iVar3 = *(int *)((int)param_2 + 0x35c);
  if ((iVar3 != 0) && (iVar1 = *(int *)(iVar3 + 8) + -1, *(int *)(iVar3 + 8) = iVar1, iVar1 == 0)) {
    _gleFreeBufferObject(param_1,iVar3);
  }
  piVar4 = (int *)((int)param_2 + 0x360);
  iVar3 = 0x1f;
  do {
    iVar1 = *piVar4;
    piVar4 = piVar4 + 1;
    if ((iVar1 != 0) && (iVar2 = *(int *)(iVar1 + 8) + -1, *(int *)(iVar1 + 8) = iVar2, iVar2 == 0))
    {
      _gleFreeBufferObject(param_1,iVar1);
    }
    iVar3 = iVar3 + -1;
  } while (-1 < iVar3);
  _gleVecFree(param_2);
  return;
}

/* _gleDestroyPluginVertexArray @ 0x302c4 (120 bytes) */
int _gleDestroyPluginVertexArray(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_1 + 0x10000;
  iVar5 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar4 + -0x777c);
      iVar3 = iVar5 * 4;
      puVar2 = (undefined4 *)(iVar4 + -0x7a54);
      iVar4 = iVar4 + 0x2e0;
      iVar5 = iVar5 + 1;
      (**(code **)(*piVar1 + 0x1b0))(*puVar2,*(undefined4 *)(iVar3 + param_2));
      *(undefined4 *)(iVar3 + param_2) = 0;
    } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  return;
}

/* _glePPEmulatorTerminate @ 0x30340 (8 bytes) */
int _glePPEmulatorTerminate(param_1)
  int param_1;
{
  _PPEmulatorFree(*(undefined4 *)(param_1 + 0x4a5c));
  return;
}

/* _gleFreeBufferState @ 0x30348 (180 bytes) */
int _gleFreeBufferState(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x48f4);
  if (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 8) + -1;
    *(int *)(iVar2 + 8) = iVar1;
    if (iVar1 == 0) {
      _gleFreeBufferObject(param_1,iVar2);
    }
    *(undefined4 *)(param_1 + 0x48f4) = 0;
  }
  iVar2 = *(int *)(param_1 + 0x4a68);
  if ((iVar2 != 0) && (iVar1 = *(int *)(iVar2 + 8) + -1, *(int *)(iVar2 + 8) = iVar1, iVar1 == 0)) {
    _gleFreeBufferObject(param_1,iVar2);
  }
  iVar2 = *(int *)(param_1 + 0x4a6c);
  *(undefined4 *)(param_1 + 0x4a68) = 0;
  if ((iVar2 != 0) && (iVar1 = *(int *)(iVar2 + 8) + -1, *(int *)(iVar2 + 8) = iVar1, iVar1 == 0)) {
    _gleFreeBufferObject(param_1,iVar2);
  }
  *(undefined4 *)(param_1 + 0x4a6c) = 0;
  return;
}

/* _gleFreeShaderState @ 0x303fc (156 bytes) */
int _gleFreeShaderState(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x5430);
  if (iVar2 != 0) {
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_lock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
    }
    iVar1 = *(int *)(iVar2 + 8) + -1;
    *(int *)(iVar2 + 8) = iVar1;
    if (iVar1 == 1) {
      ((int (*)())_gleDeleteHashNameAndObject)(param_1,*(int *)(param_1 + 0x5148) + 0x6018,*(undefined4 *)(iVar2 + 4));
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
    }
    *(undefined4 *)(param_1 + 0x5430) = 0;
  }
  return;
}

/* _gleFreePipelineProgramState @ 0x30498 (208 bytes) */
int _gleFreePipelineProgramState(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (*(void **)(param_1 + 0x5418) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x5418));
    *(undefined4 *)(param_1 + 0x5418) = 0;
  }
  puVar3 = (undefined4 *)(param_1 + 0x5428);
  iVar2 = 1;
  do {
    iVar4 = puVar3[-2];
    if (iVar4 != 0) {
      if (*(int *)(iVar4 + 4) != 0) {
        if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_lock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
        }
        iVar1 = *(int *)(iVar4 + 8) + -1;
        *(int *)(iVar4 + 8) = iVar1;
        if (iVar1 == 0) {
          ((int (*)())_gleFreePipelineProgramObject)(param_1,iVar4);
        }
        if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
        }
      }
      ((int (*)())_gleFreePipelineProgramObject)(param_1,*puVar3);
    }
    iVar2 = iVar2 + -1;
    puVar3 = puVar3 + 1;
  } while (-1 < iVar2);
  return;
}

/* _gleFreePipelineProgramObject @ 0x30568 (72 bytes) */
int _gleFreePipelineProgramObject(param_1, param_2)
  undefined4 param_1;
  void *param_2;
{
  ((int (*)())_gleClearPipelineProgram)(param_1,(int)param_2 + 0x10);
  ((int (*)())_gleDestroyPluginPipelineProgram)(param_1,(int)param_2 + 0x10);
  _gleVecFree(param_2);
  return;
}

/* _gleClearPipelineProgram @ 0x305b0 (364 bytes) */
int _gleClearPipelineProgram(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  
  pvVar5 = (void *)param_2[0x12f];
  if ((void *)param_2[1] != (void *)0x0) {
    _free((void *)param_2[1]);
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
    _PPStreamFree();
    *param_2 = 0;
  }
  if (*(short *)((int)param_2 + 0x4ba) == 0) {
    if (param_2[0x135] != 0) {
      _PPEmulatorProgramFree();
      param_2[0x135] = 0;
    }
    iVar6 = 0x100;
  }
  else if (*(short *)((int)param_2 + 0x4ba) == 1) {
    if (param_2[0x135] != 0) {
      _LFSStreamFree(param_2[0x135]);
      param_2[0x135] = 0;
    }
    *(undefined2 *)(param_2 + 0x138) = 0;
    *(undefined2 *)(param_2 + 0x137) = 0;
    *(undefined2 *)((int)param_2 + 0x4de) = 0;
    iVar6 = 0x80;
  }
  else {
    iVar6 = 0;
  }
  if (pvVar5 != (void *)0x0) {
    if (*(short *)(param_2 + 0x12e) != -0x7e00) {
      ((int (*)())_glePPUnlogParameters)(param_1,param_2,*(undefined4 *)((int)pvVar5 + 0x28),
                 (void *)((int)pvVar5 + *(int *)((int)pvVar5 + 0x2c) * 8));
    }
    _gleVecFree(pvVar5);
    param_2[0x12f] = 0;
  }
  iVar3 = param_2[0x134];
  if (iVar3 != 0) {
    iVar4 = 0;
    for (; iVar6 != 0; iVar6 = iVar6 + -1) {
      iVar1 = iVar4 * 0x10;
      iVar4 = iVar4 + 1;
      iVar2 = iVar1 + iVar3;
      *(undefined4 *)(iVar3 + iVar1) = 0;
      *(undefined4 *)(iVar2 + 0xc) = 0x3f800000;
      *(undefined4 *)(iVar2 + 4) = 0;
      *(undefined4 *)(iVar2 + 8) = 0;
    }
  }
  return;
}

/* _gleDestroyPluginPipelineProgram @ 0x3071c (120 bytes) */
int _gleDestroyPluginPipelineProgram(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1 + 0x10000;
  iVar4 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      iVar4 = iVar4 + 1;
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      iVar3 = iVar3 + 0x2e0;
      (**(code **)(*piVar1 + 0x1a0))(*puVar2,*(undefined4 *)(param_2 + 0x498));
      *(undefined4 *)(param_2 + 0x498) = 0;
      param_2 = param_2 + 4;
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  return;
}

/* _gleReclaimDrawPixelResources @ 0x30794 (184 bytes) */
int _gleReclaimDrawPixelResources(param_1)
  int param_1;
{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x74a0);
  if (puVar1 != (undefined4 *)0x0) {
    uVar2 = 0;
    if (*(int *)(param_1 + 0x7490) != 0) {
      while( true ) {
        _gleDeletePluginTexture(param_1,puVar1[uVar2]);
        if (*(uint *)(param_1 + 0x7490) <= uVar2 + 1) break;
        puVar1 = *(undefined4 **)(param_1 + 0x74a0);
        uVar2 = uVar2 + 1;
      }
      puVar1 = *(undefined4 **)(param_1 + 0x74a0);
    }
    _gleVecFree((void *)*puVar1);
    _gleVecFree(*(void **)(param_1 + 0x74a0));
  }
  if (*(void **)(0x74a4 + param_1) != (void *)0x0) {
    _gleVecFree(*(void **)(0x74a4 + param_1));
  }
  *(undefined4 *)(0x74a4 + param_1) = 0;
  *(undefined4 *)(param_1 + 0x7488) = 0;
  *(undefined4 *)(param_1 + 0x7494) = 0;
  *(undefined4 *)(param_1 + 0x748c) = 0;
  *(undefined4 *)(param_1 + 0x7490) = 0;
  *(undefined4 *)(param_1 + 0x7498) = 0;
  *(undefined4 *)(param_1 + 0x749c) = 0;
  *(undefined4 *)(param_1 + 0x74a0) = 0;
  return;
}

/* _gleFreeMapData @ 0x3084c (16 bytes) */
int _gleFreeMapData(param_1)
  int param_1;
{
  if (*(void **)(param_1 + 0x7450) == (void *)0x0) {
    return;
  }
  _free(*(void **)(param_1 + 0x7450));
  return;
}

/* _gleFreeTextureState @ 0x3085c (376 bytes) */
int _gleFreeTextureState(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  iVar2 = 0;
  iVar3 = param_1;
  do {
    piVar5 = (int *)(iVar3 + 0x5154);
    iVar4 = 4;
    do {
      iVar6 = *piVar5;
      piVar5 = piVar5 + 1;
      if ((iVar6 != 0) && (*(int *)(iVar6 + 4) != 0)) {
        if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_lock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
        }
        iVar1 = *(int *)(iVar6 + 8) + -1;
        *(int *)(iVar6 + 8) = iVar1;
        if (iVar1 == 0) {
          _gleFreeTextureObject(param_1,iVar6);
        }
        if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
        }
      }
      iVar4 = iVar4 + -1;
    } while (-1 < iVar4);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x14;
  } while (iVar2 < 0x10);
  piVar5 = (int *)(param_1 + 0x52d4);
  iVar3 = 0xf;
  do {
    iVar2 = *piVar5;
    piVar5 = piVar5 + 1;
    if (iVar2 != 0) {
      _gleFreeTextureObject(param_1,iVar2);
    }
    iVar3 = iVar3 + -1;
  } while (-1 < iVar3);
  iVar2 = param_1 + 0x52b0;
  iVar3 = 2;
  do {
    if (*(int *)(iVar2 + 0xc) != 0) {
      _gleFreeTextureObject(param_1,*(int *)(iVar2 + 0xc));
    }
    if (*(int *)(iVar2 + 0x18) != 0) {
      _gleFreeTextureObject(param_1,*(int *)(iVar2 + 0x18));
    }
    iVar3 = iVar3 + -1;
    iVar2 = iVar2 + 4;
  } while (-1 < iVar3);
  iVar3 = param_1;
  do {
    if (*(int *)(iVar3 + 0x5294) != 0) {
      _gleFreeTextureObject(param_1,*(int *)(iVar3 + 0x5294));
    }
    if (*(int *)(iVar3 + 0x52a8) != 0) {
      _gleFreeTextureObject(param_1,*(int *)(iVar3 + 0x52a8));
    }
    iVar3 = iVar3 + 4;
  } while (iVar3 <= param_1 + 0x10);
  return;
}

/* _gleReleaseSharedState @ 0x309d4 (288 bytes) */
int _gleReleaseSharedState(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  void *pvVar9;
  int iVar10;
  
  puVar5 = *(undefined **)(param_1 + 0x5148);
  _pthread_mutex_lock((pthread_mutex_t *)(puVar5 + 0x8028));
  iVar4 = *(int *)(puVar5 + 0x8020);
  *(int *)(puVar5 + 0x8020) = iVar4 + -1;
  _pthread_mutex_unlock((pthread_mutex_t *)(puVar5 + 0x8028));
  uVar1 = 0;
  if (iVar4 < 2) {
    iVar4 = 0;
    ((int (*)())_gleDetachShaderObjects)(param_1);
    puVar3 = puVar5;
    do {
      iVar10 = 0x3ff;
      iVar6 = iVar4 * 0x1004;
      do {
        piVar7 = *(int **)(puVar5 + iVar6);
        if (piVar7 != (int *)0x0) {
          *(undefined4 *)(puVar5 + iVar6) = 0;
          do {
            piVar8 = (int *)*piVar7;
            (*(code *)piVar7[3])(param_1,piVar7);
            piVar7 = piVar8;
          } while (piVar8 != (int *)0x0);
        }
        iVar10 = iVar10 + -1;
        iVar6 = iVar6 + 4;
      } while (-1 < iVar10);
      puVar2 = *(undefined4 **)(puVar3 + 0x1000);
      if (puVar2 != (void *)0x0) {
        *(undefined4 *)(puVar3 + 0x1000) = 0;
        do {
          pvVar9 = (void *)*puVar2;
          _free(puVar2);
          puVar2 = pvVar9;
        } while (pvVar9 != (void *)0x0);
      }
      iVar4 = iVar4 + 1;
      puVar3 = ((unsigned char *)0x00001004) + (int)puVar3;
    } while (iVar4 < 8);
    puVar5 = puVar5 + 0x10000;
    iVar4 = 1;
    do {
      if (*(void **)(puVar5 + -0x7560) != (void *)0x0) {
        _free(*(void **)(puVar5 + -0x7560));
      }
      iVar4 = iVar4 + -1;
      *(undefined4 *)(puVar5 + -0x7560) = 0;
      puVar5 = puVar5 + 0xa30;
    } while (-1 < iVar4);
    uVar1 = 1;
  }
  return uVar1;
}

/* _gleDetachShaderObjects @ 0x30af4 (144 bytes) */
int _gleDetachShaderObjects(param_1)
  int param_1;
{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  puVar1 = PTR__gleDetachShaderObjectIterFunc_001113e8;
  iVar2 = *(int *)(param_1 + 0x5148);
  piVar4 = (int *)(iVar2 + 0x6018);
  do {
    piVar3 = piVar4 + 1;
    for (piVar4 = (int *)*piVar4; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
      (*(code *)puVar1)(param_1,piVar4);
    }
    piVar4 = piVar3;
  } while ((int)piVar3 <= iVar2 + 0x7014);
  return;
}

/* _gleDestroySharedState @ 0x30b84 (132 bytes) */
int _gleDestroySharedState(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  iVar4 = 0;
  pvVar3 = *(void **)(param_1 + 0x5148);
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    piVar6 = (int *)(param_1 + 0x8884);
    puVar5 = (undefined4 *)((int)pvVar3 + 0x8054);
    do {
      iVar1 = *piVar6;
      piVar6 = piVar6 + 0xb8;
      uVar2 = *puVar5;
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 1;
      (**(code **)(iVar1 + 0x128))(uVar2);
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  _pthread_mutex_destroy((pthread_mutex_t *)((int)pvVar3 + 0x8028));
  _free(pvVar3);
  return;
}

/* _glTexCoord2fv_Exec @ 0x30c08 (36 bytes) */
int _glTexCoord2fv_Exec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  *(undefined4 *)(param_1 + 0x120) = *param_2;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x124) = uVar1;
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  return;
}

/* _glVertex2i_Exec @ 0x30c2c (144 bytes) */
int _glVertex2i_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    pcVar1 = *(code **)(param_1 + 0x28);
  }
  (*((int (*)(int,int,int,double,double,double,double))pcVar1))(param_1, param_2, param_3, (double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58), (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58), (double)*(float *)(param_1 + 0x20), (double)*(float *)(param_1 + 0x24));
  return;
}

/* _glGetBooleanv_Exec @ 0x30cbc (272 bytes) */
int _glGetBooleanv_Exec(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  double dVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  double *pdVar5;
  int iVar6;
  double dVar7;
  undefined1 auStack_b0 [16];
  double local_a0 [16];
  int local_20 [4];
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    pdVar5 = local_a0;
    iVar4 = _gleGetState(param_1,param_2,pdVar5,local_20,auStack_b0);
    dVar1 = DOUBLE_00108d60;
    if (iVar4 == 0) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar2 = 0x500;
      goto LAB_00030d30;
    }
    if (iVar4 != -1) {
      if (local_20[0] != 0x1404) {
        iVar6 = 0;
        if (iVar4 < 1) {
          return;
        }
        do {
          dVar7 = *pdVar5;
          pdVar5 = pdVar5 + 1;
          *(bool *)(param_3 + iVar6) = dVar7 != dVar1;
          iVar6 = iVar6 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        return;
      }
      iVar6 = 0;
      if (iVar4 < 1) {
        return;
      }
      do {
        iVar3 = *(int *)pdVar5;
        pdVar5 = pdVar5 + 1;
        *(char *)(param_3 + iVar6) = '\x01' - (iVar3 == 0);
        iVar6 = iVar6 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      return;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar2 = 0x502;
LAB_00030d30:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glDeleteProgramsARB_Exec @ 0x30dcc (300 bytes) */
int _glDeleteProgramsARB_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (-1 < param_2) {
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
      }
      if (0 < param_2) {
        do {
          iVar4 = *param_3;
          param_3 = param_3 + 1;
          if (iVar4 != 0) {
            uVar3 = 0;
            piVar5 = (int *)(param_1 + 0x5420);
            do {
              iVar2 = *piVar5;
              piVar5 = piVar5 + 1;
              if (iVar4 == *(int *)(iVar2 + 4)) {
                _gleBindPipelineProgram(param_1,uVar3,0);
              }
              uVar3 = uVar3 + 1;
            } while (uVar3 < 2);
            ((int (*)())_gleDeleteHashNameAndObject)(param_1,*(int *)(param_1 + 0x5148) + 0x4010,iVar4);
          }
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock((pthread_mutex_t *)(*(int *)(param_1 + 0x5148) + 0x8028));
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _gleDeleteHashNameAndObject @ 0x30ef8 (136 bytes) */
int _gleDeleteHashNameAndObject(param_1, param_2, param_3)
  undefined4 param_1;
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
      (**(code **)(iVar2 + 0xc))(param_1);
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
            puVar3 = _malloc(0xc);
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
int _glePPUnlogParameters(param_1, param_2, param_3, param_4)
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
  int iVar7;
  uint uVar8;
  int iVar9;
  
  iVar7 = 0;
  uVar3 = (uint)*(ushort *)(param_2 + 0x4ba);
  iVar6 = *(int *)(param_1 + 0x5148);
  iVar4 = uVar3 * 0xa30 + iVar6;
  *(int *)(iVar4 + 0x8a98) = *(int *)(iVar4 + 0x8a98) + 1;
  if (param_3 != 0) {
    do {
      uVar8 = *(uint *)(iVar7 * 8 + param_4 + 4);
      if ((*(uint *)(iVar7 * 8 + param_4) & 0x1f0000) != 0) {
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
      iVar7 = iVar7 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

/* _gleDestroyEnableHashTable @ 0x3115c (104 bytes) */
int _gleDestroyEnableHashTable()
{
  void *pvVar1;
  int iVar2;
  undefined4 extraout_r3;
  int iVar3;
  int *piVar4;
  
  pvVar1 = _gle_enable_hash_table;
  iVar3 = 0x3ff;
  piVar4 = (int *)((int)_gle_enable_hash_table + 8);
  do {
    iVar2 = *piVar4;
    piVar4 = piVar4 + 4;
    if (iVar2 != 0) {
      ((int (*)())_gleFreeEnableHashObject)(iVar2);
    }
    iVar3 = iVar3 + -1;
  } while (-1 < iVar3);
  _free(pvVar1);
  _gle_enable_hash_table = (void *)0x0;
  return extraout_r3;
}

/* _gleFreeEnableHashObject @ 0x311c4 (60 bytes) */
int _gleFreeEnableHashObject(param_1)
  void *param_1;
{
  undefined4 extraout_r3;
  
  if (*(int *)((int)param_1 + 8) != 0) {
    ((int (*)())_gleFreeEnableHashObject)((void *)*(int *)((int)param_1 + 8));
  }
  _free(param_1);
  return extraout_r3;
}

/* _glVertex4f_Exec @ 0x31200 (32 bytes) */
int _glVertex4f_Exec(param_1)
  int param_1;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x28);
  }
                    
                    
  (*((int (*)(int))UNRECOVERED_JUMPTABLE))(param_1);
  return;
}

/* _glFrustum_Exec @ 0x31220 (660 bytes) */
void _glFrustum_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
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
  undefined4 uVar11;
  float *pfVar12;
  double dVar13;
  
  pfVar12 = *(float **)(param_1 + 0x4fec);
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4ff4) < 0x18)) {
    if ((DOUBLE_00108d60 < fparam_5) && (DOUBLE_00108d60 < fparam_6)) {
      fVar1 = (float)(fparam_2 - fparam_1);
      fVar2 = (float)(fparam_4 - fparam_3);
      fVar3 = (float)(fparam_5 - fparam_6);
      fVar4 = fVar1;
      if (fVar1 < 0.0) {
        fVar4 = -fVar1;
      }
      if (FLOAT_00108e80 <= fVar4) {
        fVar4 = fVar2;
        if (fVar2 < FLOAT_00108e50) {
          fVar4 = -fVar2;
        }
        if (FLOAT_00108e80 <= fVar4) {
          fVar4 = fVar3;
          if (fVar3 < FLOAT_00108e50) {
            fVar4 = -fVar3;
          }
          if (FLOAT_00108e80 <= fVar4) {
            fVar7 = pfVar12[8];
            fVar8 = pfVar12[9];
            fVar9 = pfVar12[10];
            fVar10 = pfVar12[0xb];
            fVar4 = (float)((fparam_4 + fparam_3) * (double)(1.0 / fVar2));
            fVar5 = (float)((fparam_2 + fparam_1) * (double)(1.0 / fVar1));
            fVar6 = (float)((fparam_6 + fparam_5) * (double)(1.0 / fVar3));
            dVar13 = (double)(float)(fparam_5 + fparam_5);
            fVar1 = (float)(dVar13 * (double)(1.0 / fVar1));
            pfVar12[8] = (fVar7 * fVar6 + (*pfVar12 * fVar5 + pfVar12[4] * fVar4)) - pfVar12[0xc];
            fVar3 = (float)(fparam_6 * dVar13 * (double)(1.0 / fVar3));
            fVar2 = (float)(dVar13 * (double)(1.0 / fVar2));
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
            *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | *(uint *)(param_1 + 0x50a8);
            *(uint *)(param_1 + 0x50b0) = *(uint *)(param_1 + 0x50b0) | *(uint *)(param_1 + 0x50a8);
            return;
          }
        }
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar11 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar11 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar11;
  return;
}

/* _glShadeModel_Exec @ 0x314b4 (160 bytes) */
int _glShadeModel_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 - 0x1d00U < 2) {
      *(int *)(param_1 + 0x34f4) = param_2;
      _gleUpdatePrimitiveData(param_1);
      puVar2 = PTR__gleSetEyeInterpFunc_0011203c;
      puVar1 = PTR__gleSetClipInterpFunc_00112038;
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x8000000;
      *(undefined **)(param_1 + 0x49c8) = puVar2;
      *(undefined **)(param_1 + 0x49cc) = puVar1;
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glClearDepth_Exec @ 0x31554 (140 bytes) */
void _glClearDepth_Exec(int param_1,double fparam_1)
{
  uint uVar1;
  bool bVar2;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
      return;
    }
    return;
  }
  bVar2 = DOUBLE_00108d60 <= fparam_1;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x10;
  if (bVar2) {
    if (fparam_1 <= DOUBLE_00108d68) goto LAB_000315d4;
    uVar1 = 0x3ff00000;
  }
  else {
    uVar1 = 0;
  }
  fparam_1 = (double)((ulonglong)uVar1 << 0x20);
LAB_000315d4:
  *(double *)(param_1 + 0x30e8) = fparam_1;
  return;
}

/* _glDepthFunc_Exec @ 0x315e0 (88 bytes) */
int _glDepthFunc_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((7 < param_2 - 0x200U) && (*(int *)(param_1 + 0x7574) == 0)) {
      *(undefined4 *)(param_1 + 0x7574) = 0x500;
    }
    *(short *)(param_1 + 0x3124) = (short)param_2;
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x200;
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _gleSetEnable_LINE_SMOOTH @ 0x31638 (32 bytes) */
int _gleSetEnable_LINE_SMOOTH(param_1, param_2, param_3)
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
void _glLightfv_Exec(int param_1,int param_2,undefined4 param_3,float *param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10)
{
  byte bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  double dVar11;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar6 = 0x502;
    goto LAB_00031c00;
  }
  uVar10 = param_2 - 0x4000;
  if (7 < uVar10) {
switchD_000316d0_default:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar6 = 0x500;
    goto LAB_00031c00;
  }
  iVar7 = param_1 + uVar10 * 0x80;
  switch(param_3) {
  case 0x1200:
    *(float *)(iVar7 + 0x2820) = *param_4;
    *(float *)(iVar7 + 0x2824) = param_4[1];
    *(float *)(iVar7 + 0x2828) = param_4[2];
    *(float *)(iVar7 + 0x282c) = param_4[3];
    *(byte *)(*(int *)(param_1 + 0x4dd0) + 0x234) =
         *(byte *)(*(int *)(param_1 + 0x4dd0) + 0x234) | 0x1e;
    *(byte *)(*(int *)(param_1 + 0x4dd4) + 0x234) =
         *(byte *)(*(int *)(param_1 + 0x4dd4) + 0x234) | 0x1e;
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(param_1 + 0x5420) + 600);
    }
    else {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x28c);
    }
    iVar9 = (bVar1 >> 3 & 0x1c) + param_1;
    iVar7 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
    uVar8 = (uint)*(byte *)(uVar10 * 7 + iVar7 + 600);
    break;
  case 0x1201:
    *(float *)(iVar7 + 0x2830) = *param_4;
    *(float *)(iVar7 + 0x2834) = param_4[1];
    *(float *)(iVar7 + 0x2838) = param_4[2];
    *(float *)(iVar7 + 0x283c) = param_4[3];
    *(byte *)(*(int *)(param_1 + 0x4dd0) + 0x234) =
         *(byte *)(*(int *)(param_1 + 0x4dd0) + 0x234) | 0x1e;
    *(byte *)(*(int *)(param_1 + 0x4dd4) + 0x234) =
         *(byte *)(*(int *)(param_1 + 0x4dd4) + 0x234) | 0x1e;
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(param_1 + 0x5420) + 0x259);
    }
    else {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x28d);
    }
    iVar9 = (bVar1 >> 3 & 0x1c) + param_1;
    iVar7 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
    uVar8 = (uint)*(byte *)(uVar10 * 7 + iVar7 + 0x259);
    break;
  case 0x1202:
    *(float *)(iVar7 + 0x2840) = *param_4;
    *(float *)(iVar7 + 0x2844) = param_4[1];
    *(float *)(iVar7 + 0x2848) = param_4[2];
    *(float *)(iVar7 + 0x284c) = param_4[3];
    *(byte *)(*(int *)(param_1 + 0x4dd0) + 0x234) =
         *(byte *)(*(int *)(param_1 + 0x4dd0) + 0x234) | 0x1e;
    *(byte *)(*(int *)(param_1 + 0x4dd4) + 0x234) =
         *(byte *)(*(int *)(param_1 + 0x4dd4) + 0x234) | 0x1e;
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(param_1 + 0x5420) + 0x25a);
    }
    else {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x28e);
    }
    iVar9 = (bVar1 >> 3 & 0x1c) + param_1;
    iVar7 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
    uVar8 = (uint)*(byte *)(uVar10 * 7 + iVar7 + 0x25a);
    break;
  case 0x1203:
    fVar5 = *param_4;
    *(float *)(iVar7 + 0x2850) = fVar5;
    fVar2 = param_4[1];
    *(float *)(iVar7 + 0x2854) = fVar2;
    fVar3 = param_4[2];
    *(float *)(iVar7 + 0x2858) = fVar3;
    fVar4 = param_4[3];
    *(float *)(iVar7 + 0x285c) = fVar4;
    *(float *)(iVar7 + 0x2850) =
         fVar4 * *(float *)(param_1 + 0x1cf0) +
         (fVar3 * *(float *)(param_1 + 0x1ce0) +
         (fVar5 * *(float *)(param_1 + 0x1cc0) + fVar2 * *(float *)(param_1 + 0x1cd0)));
    *(float *)(iVar7 + 0x2854) =
         fVar4 * *(float *)(param_1 + 0x1cf4) +
         (fVar3 * *(float *)(param_1 + 0x1ce4) +
         (fVar5 * *(float *)(param_1 + 0x1cc4) + fVar2 * *(float *)(param_1 + 0x1cd4)));
    *(float *)(iVar7 + 0x2858) =
         fVar4 * *(float *)(param_1 + 0x1cf8) +
         (fVar3 * *(float *)(param_1 + 0x1ce8) +
         (fVar5 * *(float *)(0x1cc8 + param_1) + fVar2 * *(float *)(param_1 + 0x1cd8)));
    *(float *)(iVar7 + 0x285c) =
         fVar4 * *(float *)(param_1 + 0x1cfc) +
         (fVar3 * *(float *)(param_1 + 0x1cec) +
         (fVar5 * *(float *)(param_1 + 0x1ccc) + fVar2 * *(float *)(param_1 + 0x1cdc)));
    ((double (*)())_gleUpdateLightPosition)(param_1,uVar10,fparam_1);
    goto LAB_00031c08;
  case 0x1204:
    *(float *)(iVar7 + 0x2860) = *param_4;
    *(float *)(iVar7 + 0x2864) = param_4[1];
    *(float *)(iVar7 + 0x2868) = param_4[2];
    ((void (*)())_gleTransformLightDirection)(param_1,uVar10,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
               fparam_8,in_stack_ffffffa8,in_stack_ffffffb0);
    goto LAB_00031c08;
  case 0x1205:
    fVar5 = *param_4;
    if ((fVar5 < FLOAT_00108e50) ||
       ((float)((double)CONCAT44(0x43300000,
                                 *(uint *)(*(int *)(param_1 + 0x468c) + 0xa4) ^ 0x80000000) -
               DOUBLE_00108d58) < fVar5)) goto LAB_00031bc8;
    *(float *)(iVar7 + 0x287c) = fVar5;
    _gleUpdateLightExponents(param_1,uVar10);
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(param_1 + 0x5420) + 0x25d);
    }
    else {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x291);
    }
    iVar9 = (bVar1 >> 3 & 0x1c) + param_1;
    iVar7 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
    uVar8 = (uint)*(byte *)(uVar10 * 7 + iVar7 + 0x25d);
    break;
  case 0x1206:
    fVar5 = *param_4;
    if ((fVar5 < FLOAT_00108e50) || (FLOAT_00108e88 < fVar5)) {
      if (fVar5 != FLOAT_00108e8c) goto LAB_00031bc8;
      *(undefined4 *)(iVar7 + 0x2890) = 0;
      *(undefined4 *)(iVar7 + 0x286c) = 0xbf800000;
    }
    else {
      *(float *)(iVar7 + 0x2890) = fVar5;
      dVar11 = (double)_cos((double)(*param_4 * FLOAT_00108e84));
      *(float *)(iVar7 + 0x286c) = (float)dVar11;
    }
    _gleUpdateLightExponents(param_1,uVar10);
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(param_1 + 0x5420) + 0x25c);
    }
    else {
      bVar1 = *(byte *)(uVar10 * 7 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x290);
    }
    iVar9 = (bVar1 >> 3 & 0x1c) + param_1;
    iVar7 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar9 + 0x324) = *(uint *)(iVar9 + 0x324) | 1 << (bVar1 & 0x1f);
    uVar8 = (uint)*(byte *)(uVar10 * 7 + iVar7 + 0x25c);
    break;
  case 0x1207:
    if (FLOAT_00108e50 <= *param_4) {
      *(float *)(iVar7 + 0x2870) = *param_4;
LAB_00031be0:
      _gleUpdateLightAttenuation(param_1,uVar10);
      goto LAB_00031c08;
    }
    goto LAB_00031bc8;
  case 0x1208:
    if (FLOAT_00108e50 <= *param_4) {
      *(float *)(iVar7 + 0x2874) = *param_4;
      goto LAB_00031be0;
    }
    goto LAB_00031bc8;
  case 0x1209:
    if (FLOAT_00108e50 <= *param_4) {
      *(float *)(iVar7 + 0x2878) = *param_4;
      goto LAB_00031be0;
    }
LAB_00031bc8:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar6 = 0x501;
LAB_00031c00:
    *(undefined4 *)(param_1 + 0x7574) = uVar6;
    return;
  default:
    goto switchD_000316d0_default;
  }
  iVar7 = (uVar8 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar7 + 0x348) = *(uint *)(iVar7 + 0x348) | 1 << (uVar8 & 0x1f);
LAB_00031c08:
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 4 << (uVar10 * 2 & 0x3e);
  return;
}

/* _gleSetEnable_LIGHT @ 0x31c34 (144 bytes) */
int _gleSetEnable_LIGHT(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_2 - 0x4000;
  uVar1 = *(uint *)(param_1 + 0x30a0) &
          (-2 << (uVar2 & 0x1f) | 0xfffffffeU >> 0x20 - (uVar2 & 0x1f)) | param_3 << (uVar2 & 0x3f);
  if (*(uint *)(param_1 + 0x30a0) != uVar1) {
    *(uint *)(param_1 + 0x30a0) = uVar1;
    *(undefined1 *)(*(int *)(param_1 + 0x4dd0) + 0x234) = 0x1f;
    *(undefined1 *)(*(int *)(param_1 + 0x4dd4) + 0x234) = 0x1f;
    _gleUpdateLightFast(param_1,uVar2);
    _gleUpdateLightModelFunc(param_1);
    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 8 << (uVar2 * 2 & 0x3e);
  }
  return;
}

/* _gleSetEnable_LIGHTING @ 0x31cc4 (220 bytes) */
int _gleSetEnable_LIGHTING(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  undefined *puVar1;
  undefined1 uVar2;
  
  if (*(byte *)(param_1 + 0x30aa) != param_3) {
    *(char *)(param_1 + 0x30aa) = (char)param_3;
    if (*(char *)(param_1 + 0x4664) == '\0') {
      if (param_3 == 0) {
        uVar2 = *(undefined1 *)(param_1 + 0x4fea);
      }
      else {
        uVar2 = *(short *)(param_1 + 0x30a8) == -0x7e06;
      }
      *(undefined1 *)(param_1 + 0x316b) = uVar2;
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800;
    }
    *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | 1;
    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 2;
    _gleUpdateInverseNeeds(param_1);
    _gleSelectVertexSubmitFunc(param_1);
    _gleSelectVertexAddMaterialFunc(param_1);
    puVar1 = PTR__gleSetClipInterpFunc_00112038;
    *(undefined **)(param_1 + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
    *(undefined **)(param_1 + 0x49cc) = puVar1;
    _gleUpdatePolyMode(param_1);
    return;
  }
  return;
}

/* _gleSetEnable_RESCALE_NORMAL_EXT @ 0x31da0 (44 bytes) */
int _gleSetEnable_RESCALE_NORMAL_EXT(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x280e) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x280e) = (char)param_3;
  *(uint *)(param_1 + 0x50b0) = *(uint *)(param_1 + 0x50b0) | 0x10;
  *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 0x80000000;
  return;
}

/* _glClear_Exec @ 0x31dcc (704 bytes) */
void _glClear_Exec(int param_1,uint param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
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
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_00032028;
  }
  if ((param_2 & 0xffffb8ff) != 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x501;
    goto LAB_00032028;
  }
  if (*(int *)(param_1 + 0x4e1c) != 0x1c00) {
    return;
  }
  iVar6 = *(int *)(param_1 + 0x50ac);
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_00032054;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar8 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00031f2c:
    uVar7 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar6 = 0;
    piVar4 = (int *)(param_1 + 0x324);
    do {
      iVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar5 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 9);
    uVar7 = *(uint *)(param_1 + 0x31c);
    if ((uVar7 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        ((int (*)())_gleUpdateLightRGBASums)(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        ((int (*)())_gleUpdateLightRGBASums)(param_1,param_1 + 0x2e60,1);
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
    bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
      uVar7 = (**(code **)(param_1 + 0x4788))
                        (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
      if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
         ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if ((uVar7 & 4) == 0) {
          uVar7 = uVar7 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(param_1,uVar7);
        if (*(char *)(param_1 + 0x759d) == '\0') {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar3 = 0x506;
LAB_00032028:
          *(undefined4 *)(param_1 + 0x7574) = uVar3;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(param_1);
    }
    iVar6 = 0x13;
    do {
      *piVar8 = 0;
      piVar8 = piVar8 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
LAB_00032054:
                    
                    
  (**(code **)(param_1 + 0x469c))(*(undefined4 *)(param_1 + 0x4688),param_2);
  return;
}

/* _gliDispatchNoop @ 0x3208c (8 bytes) */
int _gliDispatchNoop()
{
  return 0;
}

/* _glTranslate_Exec @ 0x32098 (448 bytes) */
void _glTranslate_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3)
{
  float *pfVar1;
  uint uVar2;
  uint uVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  
  pfVar1 = *(float **)(param_1 + 0x4fec);
  uVar3 = *(uint *)(param_1 + 0x50a8);
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4ff4) < 0x18)) {
    pfVar1[0xc] = pfVar1[0xc] +
                  (float)((double)pfVar1[8] * fparam_3 +
                         (double)(float)((double)*pfVar1 * fparam_1 +
                                        (double)(float)((double)pfVar1[4] * fparam_2)));
    pfVar1[0xd] = pfVar1[0xd] +
                  (float)((double)pfVar1[9] * fparam_3 +
                         (double)(float)((double)pfVar1[1] * fparam_1 +
                                        (double)(float)((double)pfVar1[5] * fparam_2)));
    pfVar1[0xe] = pfVar1[0xe] +
                  (float)((double)pfVar1[10] * fparam_3 +
                         (double)(float)((double)pfVar1[2] * fparam_1 +
                                        (double)(float)((double)pfVar1[6] * fparam_2)));
    pfVar1[0xf] = pfVar1[0xf] +
                  (float)((double)pfVar1[0xb] * fparam_3 +
                         (double)(float)((double)pfVar1[3] * fparam_1 +
                                        (double)(float)((double)pfVar1[7] * fparam_2)));
    uVar2 = *(uint *)(param_1 + 0x50b0);
    *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | uVar3;
    if ((uVar3 & ~uVar2 & *(uint *)(param_1 + 0x505c) & 0xfffffc) != 0) {
      pfVar1 = *(float **)(param_1 + 0x4ff0);
      uVar3 = uVar3 & 0xff000003;
      dVar4 = (double)pfVar1[0xc];
      dVar5 = (double)pfVar1[0xd];
      dVar6 = (double)pfVar1[0xe];
      dVar7 = (double)pfVar1[0xf];
      *pfVar1 = -(float)(fparam_1 * dVar4 - (double)*pfVar1);
      pfVar1[4] = -(float)(fparam_2 * dVar4 - (double)pfVar1[4]);
      pfVar1[8] = -(float)(fparam_3 * dVar4 - (double)pfVar1[8]);
      pfVar1[1] = -(float)(fparam_1 * dVar5 - (double)pfVar1[1]);
      pfVar1[5] = -(float)(fparam_2 * dVar5 - (double)pfVar1[5]);
      pfVar1[0xb] = -(float)(fparam_3 * dVar7 - (double)pfVar1[0xb]);
      pfVar1[9] = -(float)(fparam_3 * dVar5 - (double)pfVar1[9]);
      pfVar1[2] = -(float)(fparam_1 * dVar6 - (double)pfVar1[2]);
      pfVar1[6] = -(float)(fparam_2 * dVar6 - (double)pfVar1[6]);
      pfVar1[10] = -(float)(fparam_3 * dVar6 - (double)pfVar1[10]);
      pfVar1[3] = -(float)(fparam_1 * dVar7 - (double)pfVar1[3]);
      pfVar1[7] = -(float)(fparam_2 * dVar7 - (double)pfVar1[7]);
      uVar2 = *(uint *)(param_1 + 0x50b0);
    }
    *(uint *)(param_1 + 0x50b0) = uVar2 | uVar3;
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _glPolygonMode_Exec @ 0x32258 (216 bytes) */
int _glPolygonMode_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  undefined4 uVar1;
  undefined2 uVar2;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
LAB_000322a8:
    *(undefined4 *)(param_1 + 0x7574) = uVar1;
    return;
  }
  if (2 < param_3 - 0x1b00U) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
    goto LAB_000322a8;
  }
  uVar2 = (undefined2)param_3;
  if (param_2 == 0x405) {
    *(undefined2 *)(param_1 + 0x34d2) = uVar2;
    goto LAB_000322fc;
  }
  if (param_2 < 0x406) {
    if (param_2 == 0x404) {
LAB_000322d8:
      *(undefined2 *)(param_1 + 0x34d0) = uVar2;
      goto LAB_000322fc;
    }
  }
  else if (param_2 == 0x408) {
    *(undefined2 *)(param_1 + 0x34d2) = uVar2;
    goto LAB_000322d8;
  }
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x500;
  }
LAB_000322fc:
  _gleUpdatePolyMode(param_1);
  _gleSelectVertexSubmitFunc(param_1);
  return;
}

/* _glRotatef_Exec @ 0x32330 (404 bytes) */
void _glRotatef_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
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
  
  fparam_3_00 = (double)*(float *)(param_1 + 0x20);
  if ((fparam_3 == fparam_3_00) && (fparam_4 == fparam_3_00)) {
    fVar1 = FLOAT_00108e84;
    if (fparam_2 < fparam_3_00) {
      fVar1 = FLOAT_00108eb0;
    }
    dVar2 = (double)_sin();
    dVar3 = (double)_cos((double)(float)(fparam_1 * (double)fVar1));
    ((void (*)())_glRotateX_Exec)(param_1,(double)(float)dVar2,(double)(float)dVar3,fparam_3_00,fparam_4,in_f5,
                    in_f6,in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  if ((fparam_2 == fparam_3_00) && (fparam_4 == fparam_3_00)) {
    fVar1 = FLOAT_00108e84;
    if (fparam_3 < fparam_3_00) {
      fVar1 = FLOAT_00108eb0;
    }
    dVar2 = (double)_sin();
    dVar3 = (double)_cos((double)(float)(fparam_1 * (double)fVar1));
    ((void (*)())_glRotateY_Exec)(param_1,(double)(float)dVar2,(double)(float)dVar3,fparam_3_00,fparam_4,in_f5,
                    in_f6,in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  if ((fparam_2 == fparam_3_00) && (fparam_3 == fparam_3_00)) {
    fVar1 = FLOAT_00108e84;
    if (fparam_4 < fparam_3_00) {
      fVar1 = FLOAT_00108eb0;
    }
    dVar2 = (double)_sin();
    dVar3 = (double)_cos((double)(float)(fparam_1 * (double)fVar1));
    ((void (*)())_glRotateZ_Exec)(param_1,(double)(float)dVar2,(double)(float)dVar3,fparam_3_00,fparam_4,in_f5,
                    in_f6,in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  ((void (*)())_glRotateXYZ_Exec)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  return;
}

/* _glRotateZ_Exec @ 0x324c4 (372 bytes) */
void _glRotateZ_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  float *pfVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_1 + 0x50a8);
  pfVar3 = *(float **)(param_1 + 0x4fec);
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4ff4) < 0x18)) {
    fVar1 = pfVar3[4];
    fVar2 = pfVar3[1];
    pfVar3[4] = (float)((double)fVar1 * fparam_2 - (double)(float)((double)*pfVar3 * fparam_1));
    *pfVar3 = (float)((double)*pfVar3 * fparam_2 + (double)(float)((double)fVar1 * fparam_1));
    fVar1 = pfVar3[6];
    pfVar3[1] = (float)((double)fVar2 * fparam_2 + (double)(float)((double)pfVar3[5] * fparam_1));
    pfVar3[5] = (float)((double)pfVar3[5] * fparam_2 - (double)(float)((double)fVar2 * fparam_1));
    fVar2 = pfVar3[3];
    pfVar3[6] = (float)((double)fVar1 * fparam_2 - (double)(float)((double)pfVar3[2] * fparam_1));
    pfVar3[2] = (float)((double)pfVar3[2] * fparam_2 + (double)(float)((double)fVar1 * fparam_1));
    pfVar3[3] = (float)((double)fVar2 * fparam_2 + (double)(float)((double)pfVar3[7] * fparam_1));
    pfVar3[7] = (float)((double)pfVar3[7] * fparam_2 - (double)(float)((double)fVar2 * fparam_1));
    uVar4 = *(uint *)(param_1 + 0x50b0);
    *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | uVar5;
    if ((uVar5 & ~uVar4 & *(uint *)(param_1 + 0x505c) & 0xfffffc) != 0) {
      pfVar3 = *(float **)(param_1 + 0x4ff0);
      uVar5 = uVar5 & 0xff000003;
      fVar1 = pfVar3[4];
      fVar2 = pfVar3[1];
      pfVar3[4] = (float)((double)fVar1 * fparam_2 - (double)(float)((double)*pfVar3 * fparam_1));
      *pfVar3 = (float)((double)*pfVar3 * fparam_2 + (double)(float)((double)fVar1 * fparam_1));
      fVar1 = pfVar3[6];
      pfVar3[1] = (float)((double)fVar2 * fparam_2 + (double)(float)((double)pfVar3[5] * fparam_1));
      pfVar3[5] = (float)((double)pfVar3[5] * fparam_2 - (double)(float)((double)fVar2 * fparam_1));
      fVar2 = pfVar3[3];
      pfVar3[6] = (float)((double)fVar1 * fparam_2 - (double)(float)((double)pfVar3[2] * fparam_1));
      pfVar3[2] = (float)((double)pfVar3[2] * fparam_2 + (double)(float)((double)fVar1 * fparam_1));
      pfVar3[3] = (float)((double)fVar2 * fparam_2 + (double)(float)((double)pfVar3[7] * fparam_1));
      pfVar3[7] = (float)((double)pfVar3[7] * fparam_2 - (double)(float)((double)fVar2 * fparam_1));
      uVar4 = *(uint *)(param_1 + 0x50b0);
    }
    *(uint *)(param_1 + 0x50b0) = uVar4 | uVar5;
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glRotateY_Exec @ 0x32638 (372 bytes) */
void _glRotateY_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  float *pfVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_1 + 0x50a8);
  pfVar3 = *(float **)(param_1 + 0x4fec);
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4ff4) < 0x18)) {
    fVar1 = pfVar3[8];
    fVar2 = pfVar3[1];
    pfVar3[8] = (float)((double)fVar1 * fparam_2 + (double)(float)((double)*pfVar3 * fparam_1));
    *pfVar3 = (float)((double)*pfVar3 * fparam_2 - (double)(float)((double)fVar1 * fparam_1));
    fVar1 = pfVar3[10];
    pfVar3[1] = (float)((double)fVar2 * fparam_2 - (double)(float)((double)pfVar3[9] * fparam_1));
    pfVar3[9] = (float)((double)pfVar3[9] * fparam_2 + (double)(float)((double)fVar2 * fparam_1));
    fVar2 = pfVar3[3];
    pfVar3[10] = (float)((double)fVar1 * fparam_2 + (double)(float)((double)pfVar3[2] * fparam_1));
    pfVar3[2] = (float)((double)pfVar3[2] * fparam_2 - (double)(float)((double)fVar1 * fparam_1));
    pfVar3[3] = (float)((double)fVar2 * fparam_2 - (double)(float)((double)pfVar3[0xb] * fparam_1));
    pfVar3[0xb] = (float)((double)pfVar3[0xb] * fparam_2 + (double)(float)((double)fVar2 * fparam_1)
                         );
    uVar4 = *(uint *)(param_1 + 0x50b0);
    *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | uVar5;
    if ((uVar5 & ~uVar4 & *(uint *)(param_1 + 0x505c) & 0xfffffc) != 0) {
      pfVar3 = *(float **)(param_1 + 0x4ff0);
      uVar5 = uVar5 & 0xff000003;
      fVar1 = pfVar3[8];
      fVar2 = pfVar3[1];
      pfVar3[8] = (float)((double)fVar1 * fparam_2 + (double)(float)((double)*pfVar3 * fparam_1));
      *pfVar3 = (float)((double)*pfVar3 * fparam_2 - (double)(float)((double)fVar1 * fparam_1));
      fVar1 = pfVar3[10];
      pfVar3[1] = (float)((double)fVar2 * fparam_2 - (double)(float)((double)pfVar3[9] * fparam_1));
      pfVar3[9] = (float)((double)pfVar3[9] * fparam_2 + (double)(float)((double)fVar2 * fparam_1));
      fVar2 = pfVar3[3];
      pfVar3[10] = (float)((double)fVar1 * fparam_2 + (double)(float)((double)pfVar3[2] * fparam_1))
      ;
      pfVar3[2] = (float)((double)pfVar3[2] * fparam_2 - (double)(float)((double)fVar1 * fparam_1));
      pfVar3[3] = (float)((double)fVar2 * fparam_2 - (double)(float)((double)pfVar3[0xb] * fparam_1)
                         );
      pfVar3[0xb] = (float)((double)pfVar3[0xb] * fparam_2 +
                           (double)(float)((double)fVar2 * fparam_1));
      uVar4 = *(uint *)(param_1 + 0x50b0);
    }
    *(uint *)(param_1 + 0x50b0) = uVar4 | uVar5;
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glScale_Exec @ 0x327b0 (684 bytes) */
void _glScale_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3)
{
  float fVar1;
  float fVar2;
  double dVar3;
  float *pfVar4;
  uint uVar5;
  uint uVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  
  pfVar4 = *(float **)(param_1 + 0x4fec);
  uVar6 = *(uint *)(param_1 + 0x50a8);
  if ((-1 < *(short *)(param_1 + 0x4a10)) || (0x17 < *(int *)(param_1 + 0x4ff4))) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
    return;
  }
  *pfVar4 = (float)((double)*pfVar4 * fparam_1);
  pfVar4[4] = (float)((double)pfVar4[4] * fparam_2);
  pfVar4[8] = (float)((double)pfVar4[8] * fparam_3);
  pfVar4[1] = (float)((double)pfVar4[1] * fparam_1);
  pfVar4[0xb] = (float)((double)pfVar4[0xb] * fparam_3);
  pfVar4[5] = (float)((double)pfVar4[5] * fparam_2);
  pfVar4[9] = (float)((double)pfVar4[9] * fparam_3);
  pfVar4[2] = (float)((double)pfVar4[2] * fparam_1);
  pfVar4[6] = (float)((double)pfVar4[6] * fparam_2);
  pfVar4[10] = (float)((double)pfVar4[10] * fparam_3);
  pfVar4[3] = (float)((double)pfVar4[3] * fparam_1);
  pfVar4[7] = (float)((double)pfVar4[7] * fparam_2);
  *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | uVar6;
  fVar1 = FLOAT_00108eb4;
  if (*(char *)(param_1 + 0x280e) == '\0') {
    uVar5 = *(uint *)(param_1 + 0x50b0);
    if ((uVar6 & ~uVar5 & *(uint *)(param_1 + 0x505c) & 0xfffffc) == 0) goto LAB_00032a4c;
    dVar8 = (double)FLOAT_00108e50;
    dVar10 = (double)FLOAT_00108e80;
    dVar9 = (double)FLOAT_00108e54;
    pfVar4 = *(float **)(param_1 + 0x4ff0);
    dVar3 = fparam_1;
    if (fparam_1 < dVar8) {
      dVar3 = -fparam_1;
    }
    if (dVar3 < dVar10) {
      fVar2 = FLOAT_00108eb4;
      if (fparam_1 < dVar8) {
        fVar2 = -FLOAT_00108eb4;
      }
    }
    else {
      fVar2 = (float)(dVar9 / fparam_1);
    }
    dVar7 = (double)FLOAT_00108e50;
    *pfVar4 = *pfVar4 * fVar2;
    pfVar4[2] = pfVar4[2] * fVar2;
    pfVar4[3] = pfVar4[3] * fVar2;
    pfVar4[1] = pfVar4[1] * fVar2;
    dVar3 = fparam_2;
    if (fparam_2 < dVar7) {
      dVar3 = -fparam_2;
    }
    if (dVar3 < dVar10) {
      fVar2 = fVar1;
      if (fparam_2 < dVar8) {
        fVar2 = -fVar1;
      }
    }
    else {
      fVar2 = (float)(dVar9 / fparam_2);
    }
    dVar7 = (double)FLOAT_00108e50;
    pfVar4[4] = pfVar4[4] * fVar2;
    pfVar4[6] = pfVar4[6] * fVar2;
    pfVar4[7] = pfVar4[7] * fVar2;
    pfVar4[5] = pfVar4[5] * fVar2;
    dVar3 = fparam_3;
    if (fparam_3 < dVar7) {
      dVar3 = -fparam_3;
    }
    if (dVar3 < dVar10) {
      if (fparam_3 < dVar8) {
        fVar1 = -fVar1;
      }
    }
    else {
      fVar1 = (float)(dVar9 / fparam_3);
    }
    uVar6 = uVar6 & 0xff000003;
    pfVar4[8] = pfVar4[8] * fVar1;
    pfVar4[9] = pfVar4[9] * fVar1;
    pfVar4[10] = pfVar4[10] * fVar1;
    pfVar4[0xb] = pfVar4[0xb] * fVar1;
  }
  uVar5 = *(uint *)(param_1 + 0x50b0);
LAB_00032a4c:
  *(uint *)(param_1 + 0x50b0) = uVar5 | uVar6;
  return;
}

/* _glMaterialfv_Exec @ 0x32a5c (1184 bytes) */
void _glMaterialfv_Exec(int param_1,uint param_2,undefined *param_3,float *param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
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
  
  if (((*(char *)(param_1 + 0x7580) != '\0') && (-1 < *(short *)(param_1 + 0x4a10))) &&
     (*(char *)(param_1 + 0x4664) == '\0')) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  }
  if (param_3 == (undefined *)0x1600) {
    local_34 = param_4[3];
    local_40 = *param_4;
    local_3c = param_4[1];
    local_38 = param_4[2];
    if (param_2 == 0x405) {
      _gleLightMaterialRGBAChange_B_E(param_1,&local_40);
      goto LAB_00032eb8;
    }
    if (param_2 < 0x406) {
      if (param_2 == 0x404) {
        _gleLightMaterialRGBAChange_F_E(param_1,&local_40);
        goto LAB_00032eb8;
      }
    }
    else if (param_2 == 0x408) {
      _gleLightMaterialRGBAChange_FB_E(param_1,&local_40);
      goto LAB_00032eb8;
    }
  }
  else if (param_3 < (undefined *)0x1601) {
    if (param_3 == ((unsigned char *)0x00001201)) {
      local_34 = param_4[3];
      local_40 = *param_4;
      local_3c = param_4[1];
      local_38 = param_4[2];
      if (param_2 == 0x405) {
        _gleLightMaterialRGBAChange_B_D(param_1,&local_40);
        goto LAB_00032eb8;
      }
      if (param_2 < 0x406) {
        if (param_2 == 0x404) {
          _gleLightMaterialRGBAChange_F_D(param_1,&local_40);
          goto LAB_00032eb8;
        }
      }
      else if (param_2 == 0x408) {
        _gleLightMaterialRGBAChange_FB_D(param_1,&local_40);
        goto LAB_00032eb8;
      }
    }
    else if (((unsigned char *)0x00001201) < param_3) {
      if (param_3 == ((unsigned char *)0x00001202)) {
        local_34 = param_4[3];
        local_40 = *param_4;
        local_3c = param_4[1];
        local_38 = param_4[2];
        if (param_2 == 0x405) {
          _gleLightMaterialRGBAChange_B_S(param_1,&local_40);
          goto LAB_00032eb8;
        }
        if (param_2 < 0x406) {
          if (param_2 == 0x404) {
            _gleLightMaterialRGBAChange_F_S(param_1,&local_40);
            goto LAB_00032eb8;
          }
        }
        else if (param_2 == 0x408) {
          _gleLightMaterialRGBAChange_FB_S(param_1,&local_40);
          goto LAB_00032eb8;
        }
      }
    }
    else if (param_3 == ((unsigned char *)0x00001200)) {
      local_34 = param_4[3];
      local_40 = *param_4;
      local_3c = param_4[1];
      local_38 = param_4[2];
      if (param_2 == 0x405) {
        _gleLightMaterialRGBAChange_B_A(param_1,&local_40);
        goto LAB_00032eb8;
      }
      if (param_2 < 0x406) {
        if (param_2 == 0x404) {
          _gleLightMaterialRGBAChange_F_A(param_1,&local_40);
          goto LAB_00032eb8;
        }
      }
      else if (param_2 == 0x408) {
        _gleLightMaterialRGBAChange_FB_A(param_1,&local_40);
        goto LAB_00032eb8;
      }
    }
  }
  else if (param_3 == (undefined *)0x1602) {
    local_34 = param_4[3];
    local_40 = *param_4;
    local_3c = param_4[1];
    local_38 = param_4[2];
    if (param_2 == 0x405) {
      _gleLightMaterialRGBAChange_B_AD(param_1,&local_40);
      goto LAB_00032eb8;
    }
    if (param_2 < 0x406) {
      if (param_2 == 0x404) {
        _gleLightMaterialRGBAChange_F_AD(param_1,&local_40);
        goto LAB_00032eb8;
      }
    }
    else if (param_2 == 0x408) {
      _gleLightMaterialRGBAChange_FB_AD(param_1,&local_40);
      goto LAB_00032eb8;
    }
  }
  else {
    if (param_3 < (undefined *)0x1602) {
      fparam_1_00 = (double)*param_4;
      if ((double)FLOAT_00108e50 <= fparam_1_00) {
        local_30 = 0x43300000;
        uStack_2c = *(uint *)(*(int *)(param_1 + 0x468c) + 0xa0) ^ 0x80000000;
        if (fparam_1_00 <= (double)(float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58)
           ) {
          if (param_2 == 0x405) {
            ((void (*)())_gleLightMaterialShineChange_B)(param_1,fparam_1_00);
            goto LAB_00032eb8;
          }
          if (param_2 < 0x406) {
            if (param_2 == 0x404) {
              ((void (*)())_gleLightMaterialShineChange_F)(param_1,fparam_1_00);
              goto LAB_00032eb8;
            }
          }
          else if (param_2 == 0x408) {
            ((void (*)())_gleLightMaterialShineChange_FB)(param_1,fparam_1_00);
            goto LAB_00032eb8;
          }
          goto LAB_00032ea0;
        }
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar5 = 0x501;
      goto LAB_00032eb0;
    }
    if (param_3 == (undefined *)0x1603) {
      fVar1 = param_4[2] * FLOAT_00108e5c;
      fVar2 = *param_4 * FLOAT_00108e5c;
      fVar3 = param_4[1] * FLOAT_00108e5c;
      if (param_2 == 0x405) {
        uVar8 = 1;
        uVar6 = 1;
LAB_00032e68:
        if (uVar6 <= uVar8) {
          iVar4 = (uVar8 + 1) - uVar6;
          iVar7 = uVar6 * 0x10 + param_1;
          do {
            *(float *)(iVar7 + 0x2f0) = fVar2;
            *(float *)(iVar7 + 0x2f4) = fVar3;
            *(float *)(iVar7 + 0x2f8) = fVar1;
            iVar7 = iVar7 + 0x10;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
LAB_00032eb8:
        if (((*(char *)(param_1 + 0x4df8) != '\0') && (param_3 != (undefined *)0x1601)) &&
           (param_3 != (undefined *)0x1603)) {
          (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
        }
        return;
      }
      if (param_2 < 0x406) {
        if (param_2 == 0x404) {
          uVar8 = 0;
          uVar6 = 0;
          goto LAB_00032e68;
        }
      }
      else if (param_2 == 0x408) {
        uVar6 = 0;
        uVar8 = 1;
        goto LAB_00032e68;
      }
    }
  }
LAB_00032ea0:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar5 = 0x500;
LAB_00032eb0:
  *(undefined4 *)(param_1 + 0x7574) = uVar5;
  return;
}

