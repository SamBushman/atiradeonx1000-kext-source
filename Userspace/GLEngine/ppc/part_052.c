#include "decls.h"

/* _gleBeginQuadsRenderFlat @ 0xeb680 (52 bytes) */
void _gleBeginQuadsRenderFlat(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushAtomicFunc_00112224;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderFlatQuadsFunc_00112284;
  return;
}

/* _gleBeginQuadsRenderTCLRDirty @ 0xeb6b4 (60 bytes) */
void _gleBeginQuadsRenderTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR__gleRenderQuadsTCLFunc_00112280;
  puVar1 = PTR__gleFlushAtomicTCLRDirtyFunc_00112210;
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = puVar2;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleBeginQuadStripRenderSmooth @ 0xeb6f0 (52 bytes) */
void _gleBeginQuadStripRenderSmooth(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushTriQuadStripFunc_001122c8;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderSmoothQuadStripFunc_00112274;
  return;
}

/* _gleBeginQuadStripRenderFlat @ 0xeb724 (52 bytes) */
void _gleBeginQuadStripRenderFlat(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushTriQuadStripFunc_001122c8;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderFlatQuadStripFunc_00112270;
  return;
}

/* _gleBeginQuadStripRenderTCL @ 0xeb758 (52 bytes) */
void _gleBeginQuadStripRenderTCL(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushTriQuadStripTCLFunc_001122bc;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderQuadStripTCLFunc_0011226c;
  return;
}

/* _gleBeginQuadStripRenderTCLRDirty @ 0xeb78c (60 bytes) */
void _gleBeginQuadStripRenderTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR__gleFlushTriQuadStripTCLRDirtyFunc_001122b4;
  puVar1 = PTR__gleRenderQuadStripTCLFunc_0011226c;
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(undefined **)(param_1 + 0x4a0c) = puVar2;
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleBeginQuadStripSelectFeedback @ 0xeb7c8 (76 bytes) */
void _gleBeginQuadStripSelectFeedback(param_1)
  int param_1;
{
  undefined *puVar1;
  
  *(undefined **)(param_1 + 0x4a0c) = PTR__gleFlushTriQuadStripFunc_001122c8;
  puVar1 = PTR__gleFeedbackQuadStripFunc_00112264;
  if (*(int *)(param_1 + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectQuadStripFunc_00112268;
  }
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleBeginPolygonRenderSmooth @ 0xeb814 (60 bytes) */
void _gleBeginPolygonRenderSmooth(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleFlushPolygonFunc_00112260;
  puVar1 = PTR__gleRenderSmoothPolygonFunc_0011225c;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar2;
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  return;
}

/* _gleBeginPolygonRenderFlat @ 0xeb850 (60 bytes) */
void _gleBeginPolygonRenderFlat(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleFlushPolygonFunc_00112260;
  puVar1 = PTR__gleRenderFlatPolygonFunc_00112258;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar2;
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  return;
}

/* _gleBeginPolygonRenderTCLRDirty @ 0xeb88c (68 bytes) */
void _gleBeginPolygonRenderTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleRenderPolygonTCLFunc_00112250;
  puVar1 = PTR__gleFlushPolygonTCLRDirtyFunc_0011224c;
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = puVar2;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleBeginPolygonSelectFeedback @ 0xeb8d0 (76 bytes) */
void _gleBeginPolygonSelectFeedback(param_1)
  int param_1;
{
  undefined *puVar1;
  
  *(undefined **)(param_1 + 0x4a0c) = PTR__gleFlushPolygonFunc_00112260;
  puVar1 = PTR__gleFeedbackPolygonFunc_00112244;
  if (*(int *)(param_1 + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectPolygonFunc_00112248;
  }
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _glePolyCentroid @ 0xeb91c (244 bytes) */
void _glePolyCentroid(undefined4 param_1,float *param_2,int param_3,float *param_4,float *param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  float *pfVar9;
  float *pfVar10;
  
  pfVar10 = param_2;
  fVar4 = FLOAT_00108e50;
  fVar5 = FLOAT_00108e50;
  fVar6 = FLOAT_00108e50;
  if (1 < param_3) {
    iVar8 = param_3 + -1;
    pfVar9 = param_2;
    do {
      pfVar10 = pfVar9 + 0x40;
      fVar1 = *pfVar9 * pfVar9[0x41] - pfVar9[0x40] * pfVar9[1];
      fVar6 = (pfVar9[1] + pfVar9[0x41]) * fVar1 + fVar6;
      fVar5 = (*pfVar9 + pfVar9[0x40]) * fVar1 + fVar5;
      fVar4 = fVar4 + fVar1;
      iVar8 = iVar8 + -1;
      pfVar9 = pfVar10;
    } while (iVar8 != 0);
  }
  fVar1 = pfVar10[1];
  fVar2 = *param_2;
  fVar3 = param_2[1];
  fVar7 = *pfVar10 * fVar3 - fVar2 * fVar1;
  fVar4 = fVar4 + fVar7;
  if ((fVar4 < FLOAT_00108e80) && (FLOAT_00108f3c < fVar4)) {
    *param_4 = fVar2;
    *param_5 = param_2[1];
    return;
  }
  fVar4 = FLOAT_00108e54 / (fVar4 * FLOAT_00108f38);
  *param_4 = ((*pfVar10 + fVar2) * fVar7 + fVar5) * fVar4;
  *param_5 = ((fVar1 + fVar3) * fVar7 + fVar6) * fVar4;
  return;
}

/* _gleClipPolyPlane @ 0xeba10 (496 bytes) */
double _gleClipPolyPlane(int param_1,int *param_2,int param_3,int *param_4,int *param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10)
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
  int iVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  int *piVar17;
  int *piVar18;
  int *piVar19;
  
  iVar12 = *(int *)(param_1 + 0x4dfc);
  iVar10 = 0;
  piVar17 = param_2 + param_3;
  iVar15 = *(int *)(param_1 + 0x4858);
  iVar14 = 0;
  if (0 < iVar12) {
    piVar13 = (int *)(param_1 + 0x4e00);
    piVar18 = param_4;
    piVar16 = param_2;
    do {
      param_2 = piVar18;
      iVar10 = *piVar13;
      iVar11 = *piVar16;
      piVar13 = piVar13 + 1;
      iVar10 = param_1 + iVar10 * 0x10;
      fVar1 = *(float *)(iVar11 + 0x24);
      fVar2 = *(float *)(iVar10 + 0x4190);
      fVar3 = *(float *)(iVar10 + 0x418c);
      fVar4 = *(float *)(iVar11 + 0x20);
      fVar5 = *(float *)(iVar10 + 0x4194);
      fVar6 = *(float *)(iVar11 + 0x28);
      fVar7 = *(float *)(iVar10 + 0x4198);
      fVar8 = *(float *)(iVar11 + 0x2c);
      *piVar17 = iVar11;
      fVar9 = FLOAT_00108e50;
      piVar18 = param_2;
      fVar1 = fVar8 * fVar7 + (fVar6 * fVar5 + (fVar4 * fVar3 + fVar1 * fVar2));
      for (piVar19 = piVar16; piVar19 < piVar17; piVar19 = piVar19 + 1) {
        iVar10 = piVar19[1];
        fVar4 = *(float *)(iVar10 + 0x2c) * fVar7 +
                (*(float *)(iVar10 + 0x28) * fVar5 +
                (*(float *)(iVar10 + 0x20) * fVar3 + *(float *)(iVar10 + 0x24) * fVar2));
        if (fVar9 <= fVar1) {
          *piVar18 = *piVar19;
          piVar18 = piVar18 + 1;
          if (fVar4 < fVar9) {
            fparam_1 = (double)(**(double ( **)(int,int,int,int,double))(param_1 + 0x49c8))
                                         (param_1, piVar19[1], *piVar19, iVar15, (double)(fVar4 / (fVar4 - fVar1)));
            *(undefined1 *)(iVar15 + 0x7c) = 0;
            goto LAB_000ebb68;
          }
        }
        else if (fVar9 <= fVar4) {
          fparam_1 = (double)(**(double ( **)(int,int,int,int,double))(param_1 + 0x49c8))
                                       (param_1, *piVar19, iVar10, iVar15, (double)(fVar1 / (fVar1 - fVar4)));
LAB_000ebb68:
          *piVar18 = iVar15;
          iVar15 = iVar15 + 0x100;
          piVar18 = piVar18 + 1;
        }
        fVar1 = fVar4;
      }
      iVar10 = (int)piVar18 - (int)param_2 >> 2;
      if (iVar10 < 3) {
        *param_5 = 0;
        return fparam_1;
      }
      iVar14 = iVar14 + 1;
      piVar17 = param_2 + iVar10;
      piVar18 = piVar16;
      piVar16 = param_2;
    } while (iVar14 < iVar12);
  }
  if ((param_2 != param_4) && (iVar12 = 0, iVar14 = iVar10, 0 < iVar10)) {
    do {
      param_4[iVar12] = param_2[iVar12];
      iVar14 = iVar14 + -1;
      iVar12 = iVar12 + 1;
    } while (iVar14 != 0);
  }
  *param_5 = iVar10;
  *(int *)(param_1 + 0x4858) = iVar15;
  return fparam_1;
}

/* _gleCullPolygonStack @ 0xebc00 (192 bytes) */
int _gleCullPolygonStack(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  float *param_2;
  int param_3;
  uint param_4;
  uint *param_5;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  int iVar10;
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = fVar2;
  fVar4 = fVar1;
  fVar8 = FLOAT_00108e50;
  if (1 < param_3) {
    iVar9 = param_3 + -1;
    iVar10 = 1;
    fVar7 = fVar1;
    do {
      fVar4 = param_2[iVar10 * 0x40];
      fVar6 = fVar4 * fVar3;
      fVar3 = param_2[iVar10 * 0x40 + 1];
      fVar8 = fVar8 + ((fVar7 * fVar3 - fVar6));
      iVar9 = iVar9 + -1;
      iVar10 = iVar10 + 1;
      fVar7 = fVar4;
    } while (iVar9 != 0);
  }
  uVar5 = -(uint)((bool)*(char *)(param_1 + 0x4fe1) ==
            FLOAT_00108e50 < fVar8 + ((fVar4 * fVar2 - fVar1 * fVar3)) ^ param_4) >> 0x1f;
  if (*(byte *)(param_1 + 0x4fe3) == uVar5) {
    return 1;
  }
  *param_5 = uVar5 ^ 1;
  return 0;
}

/* _gleCullTriangle @ 0xebcc0 (152 bytes) */
undefined4 _gleCullTriangle(int param_1,float *param_2,float *param_3,float *param_4,uint param_5,uint *param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10)
{
  uint uVar1;
  
  uVar1 = -(uint)((bool)*(char *)(param_1 + 0x4fe1) ==
            FLOAT_00108e50 <
            (*param_2 * param_3[1] - *param_3 * param_2[1]) +
            ((*param_3 * param_4[1] - *param_4 * param_3[1])) +
            ((*param_4 * param_2[1] - *param_2 * param_4[1])) ^ param_5) >> 0x1f;
  if (*(byte *)(param_1 + 0x4fe3) == uVar1) {
    return 1;
  }
  *param_6 = uVar1 ^ 1;
  return 0;
}

/* _gleCullQuad @ 0xebd58 (160 bytes) */
undefined4 _gleCullQuad(int param_1,float *param_2,float *param_3,float *param_4,float *param_5,uint *param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11)
{
  uint uVar1;
  
  uVar1 = (uint)((bool)*(char *)(param_1 + 0x4fe1) ==
                FLOAT_00108e50 <
                (*param_2 * param_3[1] - *param_3 * param_2[1]) +
                ((*param_3 * param_4[1] - *param_4 * param_3[1])) +
                ((*param_4 * param_5[1] - *param_5 * param_4[1])) +
                ((*param_5 * param_2[1] - *param_2 * param_5[1])));
  if (*(byte *)(param_1 + 0x4fe3) == uVar1) {
    return 1;
  }
  *param_6 = uVar1 ^ 1;
  return 0;
}

/* _gleCullPolygonPtrStack @ 0xebdf8 (184 bytes) */
int _gleCullPolygonPtrStack(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  int param_3;
  uint *param_4;
{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float *pfVar8;
  
  pfVar8 = (float *)*param_2;
  fVar2 = *pfVar8;
  fVar3 = pfVar8[1];
  fVar6 = FLOAT_00108e50;
  if (1 < param_3) {
    iVar7 = param_3 + -1;
    fVar4 = fVar2;
    fVar5 = fVar3;
    do {
      param_2 = param_2 + 1;
      fVar2 = *(float *)*param_2;
      fVar3 = ((float *)*param_2)[1];
      fVar6 = fVar6 + ((fVar4 * fVar3 - fVar2 * fVar5));
      iVar7 = iVar7 + -1;
      fVar4 = fVar2;
      fVar5 = fVar3;
    } while (iVar7 != 0);
  }
  uVar1 = (uint)((bool)*(char *)(param_1 + 0x4fe1) ==
                FLOAT_00108e50 < fVar6 + ((fVar2 * pfVar8[1] - *pfVar8 * fVar3)));
  if (*(byte *)(param_1 + 0x4fe3) == uVar1) {
    return 1;
  }
  *param_4 = uVar1 ^ 1;
  return 0;
}

/* FUN_000ebeb4 @ 0xebeb4 (1112 bytes) */
void FUN_000ebeb4(param_1)
  int param_1;
{
  char cVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  code *pcVar10;
  int *piVar11;
  int *piVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
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
  uint local_40;
  int local_3c [5];
  
  bVar3 = false;
  local_3c[0] = 0;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar3 = true;
  }
  bVar3 = !bVar3;
  bVar4 = false;
  if ((bVar3) && (*(char *)(param_1 + 0x30aa) != '\0')) {
    bVar4 = true;
  }
  bVar5 = false;
  if ((bVar4) && (*(char *)(param_1 + 0x30ac) != '\0')) {
    bVar5 = true;
  }
  cVar1 = *(char *)(param_1 + 0x4fe0);
  iVar14 = *(int *)(param_1 + 0x4854);
  if ((int)*(short *)(param_1 + 0x487c) == 0) {
    return;
  }
  uVar13 = (uint)(*(int *)(param_1 + 0x4858) - iVar14) / (uint)(int)*(short *)(param_1 + 0x487c);
  if ((int)uVar13 < 3) {
    return;
  }
  if (bVar3) {
    uVar7 = (**(code **)(param_1 + 0x5060))(param_1,iVar14,uVar13);
  }
  else {
    uVar7 = _gleVPEmulate(param_1,uVar13);
  }
  if ((uVar7 & 0xff00) != 0) {
    return;
  }
  if (bVar3) {
    if (*(char *)(param_1 + 0x53e4) != '\0') {
      (**(code **)(param_1 + 0x53dc))(param_1,iVar14,uVar13);
    }
    if (*(char *)(param_1 + 0x50b4) != '\0') {
      (**(code **)(param_1 + 0x5064))(param_1,iVar14,uVar13);
    }
    if ((bVar4) || (*(char *)(param_1 + 0x53e6) != '\0')) {
      (**(code **)(param_1 + 0x5068))(param_1,iVar14,uVar13);
    }
    if (*(char *)(param_1 + 0x53e5) != '\0') {
      (**(code **)(param_1 + 0x53e0))(param_1,iVar14,uVar13);
    }
  }
  else {
    iVar14 = *(int *)(param_1 + 0x4864);
  }
  if (((uVar7 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
    if ((cVar1 != '\0') &&
       (iVar8 = ((int (*)())_gleCullPolygonStack)(param_1,iVar14,uVar13,0,local_3c), iVar8 != 0)) {
      return;
    }
    (**(code **)(param_1 + 0x506c))(param_1,iVar14,uVar13,0);
    if (bVar5) {
      pcVar10 = *(code **)(local_3c[0] * 4 + param_1 + 0x4de8);
    }
    else {
      if (!bVar4) goto LAB_000ec290;
      pcVar10 = *(code **)(param_1 + 0x4de8);
    }
    (*pcVar10)(param_1,iVar14,uVar13);
LAB_000ec290:
    if (local_3c[0] == 0) {
      uVar2 = *(ushort *)(param_1 + 0x34d0);
    }
    else {
      uVar2 = *(ushort *)(param_1 + 0x34d2);
    }
    iVar8 = uVar2 - 0x1b00;
    if ((*(char *)(param_1 + 0x4a18) != '\0') && (iVar8 == 1)) {
      iVar8 = 3;
    }
    if ((!bVar3) && (bVar4)) {
      _gleVPFlipColors(param_1,iVar14,uVar13,local_3c[0]);
    }
    _gleFeedbackPolygon(param_1,iVar14,uVar13,iVar8);
    return;
  }
  fparam_1 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, iVar14, uVar13, 0);
  piVar12 = *(int **)(param_1 + 0x4870);
  piVar11 = *(int **)(param_1 + 0x4874);
  piVar6 = piVar12;
  uVar15 = uVar13;
  if (0 < (int)uVar13) {
    do {
      *piVar6 = iVar14;
      iVar14 = iVar14 + 0x100;
      uVar15 = uVar15 - 1;
      piVar6 = piVar6 + 1;
    } while (uVar15 != 0);
  }
  if (!bVar3) {
    *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  }
  uVar9 = 0;
  piVar6 = piVar11;
  if (*(char *)(param_1 + 0x4e18) != '\0') {
    ((double (*)())_gleClipPolyPlane)(param_1,piVar12,uVar13,piVar11,&local_40,fparam_1,in_f2,in_f3,in_f4,in_f5,
                      in_f6,in_f7,in_f8,in_stack_ffffff88,in_stack_ffffff90);
    if (local_40 == 0) {
      return;
    }
    uVar9 = 1;
    piVar6 = piVar12;
    piVar12 = piVar11;
    uVar13 = local_40;
  }
  if ((uVar7 & 0xff) != 0) {
    _gleClipPoly(param_1,piVar12,uVar13,uVar7 & 0xff,piVar6,&local_40,uVar9);
    if (local_40 == 0) {
      return;
    }
    if (0 < (int)local_40) {
      piVar12 = piVar6;
      uVar13 = local_40;
    }
  }
  if ((cVar1 != '\0') &&
     (iVar14 = ((int (*)())_gleCullPolygonPtrStack)(param_1,piVar12,uVar13,local_3c), iVar14 != 0)) {
    return;
  }
  if (bVar5) {
    pcVar10 = *(code **)(local_3c[0] * 4 + param_1 + 0x4df0);
  }
  else {
    if (!bVar4) goto LAB_000ec180;
    pcVar10 = *(code **)(param_1 + 0x4df0);
  }
  (*pcVar10)(param_1,piVar12,uVar13);
LAB_000ec180:
  if (local_3c[0] == 0) {
    uVar2 = *(ushort *)(param_1 + 0x34d0);
  }
  else {
    uVar2 = *(ushort *)(param_1 + 0x34d2);
  }
  iVar14 = uVar2 - 0x1b00;
  if ((*(char *)(param_1 + 0x4a18) != '\0') && (iVar14 == 1)) {
    iVar14 = 3;
  }
  if (((!bVar3) && (bVar4)) && (piVar6 = piVar12, uVar7 = uVar13, 0 < (int)uVar13)) {
    do {
      iVar8 = *piVar6;
      piVar6 = piVar6 + 1;
      _gleVPFlipColors(param_1,iVar8,1,local_3c[0]);
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  _gleFeedbackPolygonPtr(param_1,piVar12,uVar13,iVar14);
  return;
}

/* FUN_000ec310 @ 0xec310 (1276 bytes) */
void FUN_000ec310(param_1)
  int param_1;
{
  char cVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  code *pcVar11;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  uint *puVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  double dVar22;
  double extraout_f1;
  double extraout_f1_00;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  int local_50;
  int local_4c [4];
  
  iVar12 = -1;
  bVar3 = false;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar3 = true;
  }
  bVar3 = !bVar3;
  bVar5 = false;
  if ((bVar3) && (*(char *)(param_1 + 0x30aa) != '\0')) {
    bVar5 = true;
  }
  bVar6 = false;
  if (((bVar3) && (*(char *)(param_1 + 0x30aa) != '\0')) && (*(char *)(param_1 + 0x30ac) != '\0')) {
    bVar6 = true;
  }
  cVar1 = *(char *)(param_1 + 0x4fe0);
  uVar19 = *(uint *)(param_1 + 0x4854);
  if (((int)*(short *)(param_1 + 0x487c) != 0) &&
     (uVar15 = (*(int *)(param_1 + 0x4858) - uVar19) / (uint)(int)*(short *)(param_1 + 0x487c),
     2 < (int)uVar15)) {
    if (bVar3) {
      uVar9 = (**(code **)(param_1 + 0x5060))(param_1,uVar19,uVar15);
    }
    else {
      uVar9 = _gleVPEmulate(param_1,uVar15);
    }
    if ((uVar9 & 0xff00) == 0) {
      if (bVar3) {
        if (*(char *)(param_1 + 0x53e4) != '\0') {
          (**(code **)(param_1 + 0x53dc))(param_1,uVar19,uVar15);
        }
        if (*(char *)(param_1 + 0x50b4) != '\0') {
          (**(code **)(param_1 + 0x5064))(param_1,uVar19,uVar15);
        }
        if ((bVar5) || (*(char *)(param_1 + 0x53e6) != '\0')) {
          (**(code **)(param_1 + 0x5068))(param_1,uVar19,uVar15);
        }
        if (*(char *)(param_1 + 0x53e5) != '\0') {
          (**(code **)(param_1 + 0x53e0))(param_1,uVar19,uVar15);
        }
      }
      else {
        uVar19 = *(uint *)(param_1 + 0x4864);
      }
      if (((uVar9 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
        dVar22 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x506c))(param_1, uVar19, uVar15, 0);
        if (cVar1 == '\0') {
          if (bVar5) {
            dVar22 = (double)(**(double ( **)(int,int,int))(param_1 + 0x4de8))(param_1, uVar19, uVar15);
          }
          ((double (*)())_gleFeedbackTriangles)(param_1,uVar19,uVar15,*(ushort *)(param_1 + 0x34d0) - 0x1b00,dVar22)
          ;
        }
        else {
          uVar15 = (uVar19 + uVar15 * 0x100) - 0x300;
          do {
            bVar4 = false;
            iVar20 = 0;
            uVar9 = uVar19;
            uVar18 = uVar19;
            if (uVar19 <= uVar15) {
              do {
                iVar10 = ((undefined4 (*)())_gleCullTriangle)(param_1,uVar19,uVar19 + 0x100,uVar19 + 0x200,0,&local_50,
                                          dVar22,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                          in_stack_ffffff78,in_stack_ffffff80);
                dVar22 = dVar22;
                if (iVar10 == 0) {
                  if (iVar12 != local_50) {
                    bVar4 = true;
                  }
                  if ((bVar4) && (uVar9 = uVar19, 0 < iVar20)) break;
                  iVar20 = iVar20 + 3;
                  iVar12 = local_50;
                  uVar17 = uVar18;
                }
                else {
                  uVar17 = uVar19 + 0x300;
                  uVar9 = uVar17;
                  if (0 < iVar20) break;
                }
                uVar19 = uVar19 + 0x300;
                uVar9 = uVar19;
                uVar18 = uVar17;
              } while (uVar19 <= uVar15);
              if (2 < iVar20) {
                if (bVar6) {
                  pcVar11 = *(code **)(iVar12 * 4 + param_1 + 0x4de8);
LAB_000ec5d0:
                  dVar22 = (double)(*((double (*)(int,int,int))pcVar11))(param_1, uVar18, iVar20);
                }
                else if (bVar5) {
                  pcVar11 = *(code **)(param_1 + 0x4de8);
                  goto LAB_000ec5d0;
                }
                if ((!bVar3) && (bVar5)) {
                  dVar22 = (double)_gleVPFlipColors(param_1,uVar18,iVar20,iVar12);
                }
                if (iVar12 == 0) {
                  uVar2 = *(ushort *)(param_1 + 0x34d0);
                }
                else {
                  uVar2 = *(ushort *)(param_1 + 0x34d2);
                }
                dVar22 = (double)((double (*)())_gleFeedbackTriangles)(param_1,uVar18,iVar20,uVar2 - 0x1b00,dVar22);
              }
            }
            uVar19 = uVar9;
          } while (uVar9 <= uVar15);
        }
      }
      else {
        dVar22 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, uVar19, uVar15, 0);
        iVar12 = uVar19 + uVar15 * 0x100;
        puVar16 = *(uint **)(param_1 + 0x4870);
        puVar13 = *(uint **)(param_1 + 0x4874);
        for (; uVar19 <= iVar12 - 0x300U; uVar19 = uVar19 + 0x300) {
          puVar16[1] = uVar19 + 0x100;
          puVar16[2] = uVar19 + 0x200;
          *puVar16 = uVar19;
          if (bVar3) {
            uVar8 = *(undefined4 *)(param_1 + 0x485c);
          }
          else {
            uVar8 = *(undefined4 *)(param_1 + 0x4854);
          }
          *(undefined4 *)(param_1 + 0x4858) = uVar8;
          puVar14 = puVar13;
          iVar20 = 3;
          puVar7 = puVar16;
          if ((*(char *)(param_1 + 0x4e18) == '\0') ||
             (dVar22 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar16,3,puVar13,local_4c,dVar22,in_f2,
                                                 in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                 in_stack_ffffff78,in_stack_ffffff80),
             puVar14 = puVar16, iVar20 = local_4c[0], puVar7 = puVar13, local_4c[0] != 0)) {
            puVar16 = puVar7;
            puVar13 = puVar14;
            if ((uVar9 & 0xff) != 0) {
              dVar22 = (double)_gleClipPoly(param_1,puVar16,iVar20,uVar9 & 0xff,puVar14,local_4c,1);
              if (local_4c[0] == 0) goto LAB_000ec7e4;
              if (0 < local_4c[0]) {
                puVar13 = puVar16;
                iVar20 = local_4c[0];
                puVar16 = puVar14;
              }
            }
            if ((cVar1 == '\0') ||
               (iVar10 = ((int (*)())_gleCullPolygonPtrStack)(param_1,puVar16,iVar20,&local_50),
               dVar22 = extraout_f1_00, iVar10 == 0)) {
              iVar10 = local_50;
              if (bVar6) {
                pcVar11 = *(code **)(local_50 * 4 + param_1 + 0x4df0);
LAB_000ec778:
                (*pcVar11)(param_1,puVar16,iVar20);
              }
              else if (bVar5) {
                pcVar11 = *(code **)(param_1 + 0x4df0);
                goto LAB_000ec778;
              }
              if (((!bVar3) && (bVar5)) && (puVar14 = puVar16, iVar21 = iVar20, 0 < iVar20)) {
                do {
                  _gleVPFlipColors(param_1,*puVar14,1,iVar10);
                  iVar21 = iVar21 + -1;
                  puVar14 = puVar14 + 1;
                } while (iVar21 != 0);
              }
              if (iVar10 == 0) {
                uVar2 = *(ushort *)(param_1 + 0x34d0);
              }
              else {
                uVar2 = *(ushort *)(param_1 + 0x34d2);
              }
              dVar22 = (double)_gleFeedbackPolygonPtr(param_1,puVar16,iVar20,uVar2 - 0x1b00);
            }
          }
LAB_000ec7e4: ;
        }
      }
    }
  }
  return;
}

/* FUN_000ec810 @ 0xec810 (1544 bytes) */
void FUN_000ec810(param_1)
  int param_1;
{
  char cVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  uint uVar8;
  uint *puVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  code *pcVar16;
  int iVar17;
  int *piVar18;
  uint *puVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  uint *puVar24;
  uint uVar25;
  uint uVar26;
  double dVar27;
  double extraout_f1;
  double extraout_f1_00;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  int local_50;
  int local_4c [3];
  
  iVar17 = -1;
  bVar3 = false;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar3 = true;
  }
  bVar3 = !bVar3;
  bVar5 = false;
  if ((bVar3) && (*(char *)(param_1 + 0x30aa) != '\0')) {
    bVar5 = true;
  }
  bVar6 = false;
  if (((bVar3) && (*(char *)(param_1 + 0x30aa) != '\0')) && (*(char *)(param_1 + 0x30ac) != '\0')) {
    bVar6 = true;
  }
  uVar20 = 0;
  cVar1 = *(char *)(param_1 + 0x4fe0);
  uVar26 = *(uint *)(param_1 + 0x4854);
  if (((int)*(short *)(param_1 + 0x487c) != 0) &&
     (uVar21 = (*(int *)(param_1 + 0x4858) - uVar26) / (uint)(int)*(short *)(param_1 + 0x487c),
     2 < (int)uVar21)) {
    if (bVar3) {
      uVar12 = (**(code **)(param_1 + 0x5060))(param_1,uVar26,uVar21);
    }
    else {
      uVar12 = _gleVPEmulate(param_1,uVar21);
    }
    if ((uVar12 & 0xff00) == 0) {
      if (bVar3) {
        if (*(char *)(param_1 + 0x53e4) != '\0') {
          (**(code **)(param_1 + 0x53dc))(param_1,uVar26,uVar21);
        }
        if (*(char *)(param_1 + 0x50b4) != '\0') {
          (**(code **)(param_1 + 0x5064))(param_1,uVar26,uVar21);
        }
        if ((bVar5) || (*(char *)(param_1 + 0x53e6) != '\0')) {
          (**(code **)(param_1 + 0x5068))(param_1,uVar26,uVar21);
        }
        if (*(char *)(param_1 + 0x53e5) != '\0') {
          (**(code **)(param_1 + 0x53e0))(param_1,uVar26,uVar21);
        }
      }
      else {
        uVar26 = *(uint *)(param_1 + 0x4864);
      }
      if (((uVar12 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
        dVar27 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x506c))(param_1, uVar26, uVar21, 0);
        if (cVar1 == '\0') {
          if (bVar5) {
            (**(code **)(param_1 + 0x4de8))(param_1,uVar26,uVar21);
          }
          _gleFeedbackTriangleStrip(param_1,uVar26,uVar21,*(ushort *)(param_1 + 0x34d0) - 0x1b00);
        }
        else {
          piVar18 = *(int **)(param_1 + 0x4870);
          uVar12 = (uVar26 + uVar21 * 0x100) - 0x300;
          uVar21 = 0;
          do {
            bVar4 = false;
            iVar23 = 0;
            uVar11 = uVar21;
            uVar8 = uVar26;
            while (uVar21 = uVar11, uVar26 <= uVar12) {
              uVar25 = uVar26 + 0x100;
              iVar13 = ((undefined4 (*)())_gleCullTriangle)(param_1,uVar26,uVar25,uVar26 + 0x200,uVar11,&local_50,dVar27
                                        ,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff78
                                        ,in_stack_ffffff80);
              dVar27 = extraout_f1;
              if (iVar13 == 0) {
                if (iVar17 != local_50) {
                  bVar4 = true;
                }
                if ((bVar4) && (0 < iVar23)) break;
                if (iVar23 == 0) {
                  uVar20 = uVar11;
                }
                iVar23 = iVar23 + 1;
                iVar17 = local_50;
                uVar22 = uVar8;
              }
              else {
                uVar22 = uVar25;
                uVar21 = uVar11 ^ 1;
                uVar26 = uVar25;
                if (0 < iVar23) break;
              }
              uVar11 = uVar11 ^ 1;
              uVar26 = uVar25;
              uVar8 = uVar22;
            }
            iVar13 = iVar23 + 2;
            if (2 < iVar13) {
              if (bVar6) {
                if (bVar4) {
                  uVar11 = uVar8;
                  do {
                    *(byte *)(uVar11 + 0x7e) = *(byte *)(uVar11 + 0x7e) | 6;
                    uVar11 = uVar11 + 0x100;
                  } while ((int)uVar11 <= (int)(uVar8 + 0x100));
                }
                pcVar16 = *(code **)(iVar17 * 4 + param_1 + 0x4de8);
LAB_000ecb18:
                (*pcVar16)(param_1,uVar8,iVar13);
              }
              else if (bVar5) {
                pcVar16 = *(code **)(param_1 + 0x4de8);
                goto LAB_000ecb18;
              }
              if ((!bVar3) && (bVar5)) {
                _gleVPFlipColors(param_1,uVar8,iVar13,iVar17);
              }
              uVar11 = uVar8;
              if (uVar20 != 0) {
                uVar11 = uVar8 + 0x100;
                *piVar18 = uVar8 + 0x200;
                piVar18[2] = uVar8;
                piVar18[1] = uVar11;
                if (iVar17 != 0) {
                  uVar2 = *(ushort *)(param_1 + 0x34d2);
                }
                else {
                  uVar2 = *(ushort *)(param_1 + 0x34d0);
                }
                iVar13 = iVar23 + 1;
                dVar27 = (double)_gleFeedbackPolygonPtr(param_1,piVar18,3,uVar2 - 0x1b00);
                if (iVar13 < 3) goto LAB_000ecbb8;
              }
              if (iVar17 != 0) {
                uVar2 = *(ushort *)(param_1 + 0x34d2);
              }
              else {
                uVar2 = *(ushort *)(param_1 + 0x34d0);
              }
              dVar27 = (double)_gleFeedbackTriangleStrip(param_1,uVar11,iVar13,uVar2 - 0x1b00);
            }
LAB_000ecbb8: ;
          } while (uVar26 <= uVar12);
        }
      }
      else {
        bVar4 = false;
        dVar27 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, uVar26, uVar21, 0);
        puVar24 = *(uint **)(param_1 + 0x4870);
        uVar20 = (uVar26 + uVar21 * 0x100) - 0x300;
        puVar19 = *(uint **)(param_1 + 0x4874);
        if (uVar26 <= uVar20) {
          bVar7 = false;
          do {
            bVar7 = !bVar7;
            if (bVar7) {
              puVar24[2] = uVar26 + 0x200;
              *puVar24 = uVar26;
            }
            else {
              *puVar24 = uVar26 + 0x200;
              puVar24[2] = uVar26;
            }
            uVar26 = uVar26 + 0x100;
            puVar24[1] = uVar26;
            if (bVar3) {
              uVar10 = *(undefined4 *)(param_1 + 0x485c);
            }
            else {
              uVar10 = *(undefined4 *)(param_1 + 0x4854);
            }
            *(undefined4 *)(param_1 + 0x4858) = uVar10;
            puVar15 = puVar19;
            iVar13 = 3;
            puVar9 = puVar24;
            iVar23 = iVar17;
            if ((*(char *)(param_1 + 0x4e18) == '\0') ||
               (dVar27 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar24,3,puVar19,local_4c,dVar27,in_f2,
                                                   in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                   in_stack_ffffff78,in_stack_ffffff80),
               puVar15 = puVar24, iVar13 = local_4c[0], puVar9 = puVar19, local_4c[0] != 0)) {
              puVar24 = puVar9;
              puVar19 = puVar15;
              if ((uVar12 & 0xff) != 0) {
                dVar27 = (double)_gleClipPoly(param_1,puVar24,iVar13,uVar12 & 0xff,puVar15,local_4c,
                                              1);
                if (local_4c[0] == 0) goto LAB_000ecdf0;
                if (0 < local_4c[0]) {
                  puVar19 = puVar24;
                  iVar13 = local_4c[0];
                  puVar24 = puVar15;
                }
              }
              if ((cVar1 == '\0') ||
                 (iVar14 = ((int (*)())_gleCullPolygonPtrStack)(param_1,puVar24,iVar13,&local_50),
                 dVar27 = extraout_f1_00, iVar14 == 0)) {
                iVar23 = local_50;
                if (iVar17 != local_50) {
                  bVar4 = true;
                }
                if (bVar6) {
                  if (bVar4) {
                    puVar15 = puVar24;
                    iVar17 = iVar13;
                    if (0 < iVar13) {
                      do {
                        *(byte *)(*puVar15 + 0x7e) = *(byte *)(*puVar15 + 0x7e) | 6;
                        iVar17 = iVar17 + -1;
                        puVar15 = puVar15 + 1;
                      } while (iVar17 != 0);
                    }
                    bVar4 = false;
                  }
                  pcVar16 = *(code **)(local_50 * 4 + param_1 + 0x4df0);
LAB_000ecd84:
                  (*pcVar16)(param_1,puVar24,iVar13);
                }
                else if (bVar5) {
                  pcVar16 = *(code **)(param_1 + 0x4df0);
                  goto LAB_000ecd84;
                }
                if (((!bVar3) && (bVar5)) && (puVar15 = puVar24, iVar17 = iVar13, 0 < iVar13)) {
                  do {
                    _gleVPFlipColors(param_1,*puVar15,1,iVar23);
                    iVar17 = iVar17 + -1;
                    puVar15 = puVar15 + 1;
                  } while (iVar17 != 0);
                }
                if (iVar23 == 0) {
                  uVar2 = *(ushort *)(param_1 + 0x34d0);
                }
                else {
                  uVar2 = *(ushort *)(param_1 + 0x34d2);
                }
                dVar27 = (double)_gleFeedbackPolygonPtr(param_1,puVar24,iVar13,uVar2 - 0x1b00);
              }
            }
LAB_000ecdf0:
            iVar17 = iVar23;
          } while (uVar26 <= uVar20);
        }
      }
    }
  }
  return;
}

/* FUN_000ece1c @ 0xece1c (1448 bytes) */
void FUN_000ece1c(param_1)
  int param_1;
{
  char cVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  code *pcVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int *piVar18;
  int *piVar19;
  uint uVar20;
  double dVar21;
  double extraout_f1;
  double extraout_f1_00;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff68;
  double in_stack_ffffff70;
  int local_60;
  int local_5c [6];
  
  iVar12 = -1;
  bVar3 = false;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar3 = true;
  }
  bVar3 = !bVar3;
  bVar5 = false;
  if ((bVar3) && (*(char *)(param_1 + 0x30aa) != '\0')) {
    bVar5 = true;
  }
  bVar6 = false;
  if (((bVar3) && (*(char *)(param_1 + 0x30aa) != '\0')) && (*(char *)(param_1 + 0x30ac) != '\0')) {
    bVar6 = true;
  }
  cVar1 = *(char *)(param_1 + 0x4fe0);
  iVar15 = *(int *)(param_1 + 0x4854);
  if (((int)*(short *)(param_1 + 0x487c) != 0) &&
     (uVar16 = (uint)(*(int *)(param_1 + 0x4858) - iVar15) / (uint)(int)*(short *)(param_1 + 0x487c)
     , 2 < (int)uVar16)) {
    if (bVar3) {
      uVar8 = (**(code **)(param_1 + 0x5060))(param_1,iVar15,uVar16);
    }
    else {
      uVar8 = _gleVPEmulate(param_1,uVar16);
    }
    if ((uVar8 & 0xff00) == 0) {
      if (bVar3) {
        if (*(char *)(param_1 + 0x53e4) != '\0') {
          (**(code **)(param_1 + 0x53dc))(param_1,iVar15,uVar16);
        }
        if (*(char *)(param_1 + 0x50b4) != '\0') {
          (**(code **)(param_1 + 0x5064))(param_1,iVar15,uVar16);
        }
        if ((bVar5) || (*(char *)(param_1 + 0x53e6) != '\0')) {
          (**(code **)(param_1 + 0x5068))(param_1,iVar15,uVar16);
        }
        if (*(char *)(param_1 + 0x53e5) != '\0') {
          (**(code **)(param_1 + 0x53e0))(param_1,iVar15,uVar16);
        }
      }
      else {
        iVar15 = *(int *)(param_1 + 0x4864);
      }
      if (((uVar8 & 0xff) != 0) || (*(char *)(param_1 + 0x4e18) != '\0')) {
        bVar4 = false;
        dVar21 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, iVar15, uVar16, 0);
        uVar20 = iVar15 + 0x100;
        piVar19 = *(int **)(param_1 + 0x4870);
        piVar13 = *(int **)(param_1 + 0x4874);
joined_r0x000ed1dc:
        do {
          if ((iVar15 + uVar16 * 0x100) - 0x200 < uVar20) {
            return;
          }
          uVar14 = uVar20 + 0x100;
          *piVar19 = iVar15;
          piVar19[1] = uVar20;
          piVar19[2] = uVar14;
          if (bVar3) {
            uVar7 = *(undefined4 *)(param_1 + 0x485c);
          }
          else {
            uVar7 = *(undefined4 *)(param_1 + 0x4854);
          }
          *(undefined4 *)(param_1 + 0x4858) = uVar7;
          piVar10 = piVar13;
          iVar17 = 3;
          piVar18 = piVar19;
          uVar20 = uVar14;
        } while ((*(char *)(param_1 + 0x4e18) != '\0') &&
                (dVar21 = (double)((double (*)())_gleClipPolyPlane)(param_1,piVar19,3,piVar13,local_5c,dVar21,in_f2,
                                                    in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                    in_stack_ffffff68,in_stack_ffffff70),
                piVar10 = piVar19, iVar17 = local_5c[0], piVar18 = piVar13, local_5c[0] == 0));
        piVar13 = piVar10;
        piVar19 = piVar18;
        if ((uVar8 & 0xff) != 0) goto code_r0x000ed254;
        goto LAB_000ed294;
      }
      dVar21 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x506c))(param_1, iVar15, uVar16, 0);
      if (cVar1 == '\0') {
        if (bVar5) {
          (**(code **)(param_1 + 0x4de8))(param_1,iVar15,uVar16);
        }
        _gleFeedbackTriangleFan
                  (param_1,iVar15,iVar15 + 0x100,uVar16 - 1,*(ushort *)(param_1 + 0x34d0) - 0x1b00);
      }
      else {
        uVar8 = (iVar15 + uVar16 * 0x100) - 0x200;
        uVar16 = iVar15 + 0x100;
        do {
          bVar4 = false;
          iVar17 = 0;
          uVar20 = uVar16;
          do {
            while( true ) {
              uVar14 = uVar20;
              if (uVar8 < uVar16) goto LAB_000ed0b0;
              uVar20 = uVar16 + 0x100;
              iVar9 = ((undefined4 (*)())_gleCullTriangle)(param_1,iVar15,uVar16,uVar20,0,&local_60,dVar21,in_f2,in_f3,
                                       in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff68,
                                       in_stack_ffffff70);
              dVar21 = extraout_f1;
              if (iVar9 != 0) break;
              if (iVar12 != local_60) {
                bVar4 = true;
              }
              if ((bVar4) && (0 < iVar17)) goto LAB_000ed0b0;
              iVar17 = iVar17 + 1;
              iVar12 = local_60;
              uVar16 = uVar20;
              uVar20 = uVar14;
            }
            uVar16 = uVar20;
          } while (iVar17 < 1);
LAB_000ed0b0:
          iVar17 = iVar17 + 1;
          if (1 < iVar17) {
            if (bVar6) {
              if (bVar4) {
                *(byte *)(iVar15 + 0x7e) = *(byte *)(iVar15 + 0x7e) | 6;
                *(byte *)(uVar14 + 0x7e) = *(byte *)(uVar14 + 0x7e) | 6;
              }
              iVar9 = iVar12 * 4 + param_1;
              (**(code **)(iVar9 + 0x4de8))(param_1,iVar15,1);
              pcVar11 = *(code **)(iVar9 + 0x4de8);
LAB_000ed144:
              (*pcVar11)(param_1,uVar14,iVar17);
            }
            else if (bVar5) {
              (**(code **)(param_1 + 0x4de8))(param_1,iVar15,1);
              pcVar11 = *(code **)(param_1 + 0x4de8);
              goto LAB_000ed144;
            }
            if ((!bVar3) && (bVar5)) {
              _gleVPFlipColors(param_1,uVar14,iVar17,iVar12);
            }
            if (iVar12 == 0) {
              uVar2 = *(ushort *)(param_1 + 0x34d0);
            }
            else {
              uVar2 = *(ushort *)(param_1 + 0x34d2);
            }
            dVar21 = (double)_gleFeedbackTriangleFan(param_1,iVar15,uVar14,iVar17,uVar2 - 0x1b00);
          }
        } while (uVar16 <= uVar8);
      }
    }
  }
  return;
code_r0x000ed254:
  dVar21 = (double)_gleClipPoly(param_1,piVar18,iVar17,uVar8 & 0xff,piVar10,local_5c,1);
  if (local_5c[0] == 0) goto joined_r0x000ed1dc;
  if (0 < local_5c[0]) {
    piVar13 = piVar18;
    iVar17 = local_5c[0];
    piVar19 = piVar10;
  }
LAB_000ed294:
  if ((cVar1 != '\0') &&
     (iVar9 = ((int (*)())_gleCullPolygonPtrStack)(param_1,piVar19,iVar17,&local_60), dVar21 = extraout_f1_00,
     iVar9 != 0)) goto joined_r0x000ed1dc;
  iVar9 = local_60;
  if (iVar12 != local_60) {
    bVar4 = true;
  }
  if (bVar6) {
    if (bVar4) {
      piVar10 = piVar19;
      iVar12 = iVar17;
      if (0 < iVar17) {
        do {
          *(byte *)(*piVar10 + 0x7e) = *(byte *)(*piVar10 + 0x7e) | 6;
          iVar12 = iVar12 + -1;
          piVar10 = piVar10 + 1;
        } while (iVar12 != 0);
      }
      bVar4 = false;
    }
    pcVar11 = *(code **)(local_60 * 4 + param_1 + 0x4df0);
  }
  else {
    if (!bVar5) goto LAB_000ed33c;
    pcVar11 = *(code **)(param_1 + 0x4df0);
  }
  (*pcVar11)(param_1,piVar19,iVar17);
LAB_000ed33c:
  if (((!bVar3) && (bVar5)) && (iVar12 = iVar17, piVar10 = piVar19, 0 < iVar17)) {
    do {
      _gleVPFlipColors(param_1,*piVar10,1,iVar9);
      iVar12 = iVar12 + -1;
      piVar10 = piVar10 + 1;
    } while (iVar12 != 0);
  }
  if (iVar9 == 0) {
    uVar2 = *(ushort *)(param_1 + 0x34d0);
  }
  else {
    uVar2 = *(ushort *)(param_1 + 0x34d2);
  }
  dVar21 = (double)_gleFeedbackPolygonPtr(param_1,piVar19,iVar17,uVar2 - 0x1b00);
  iVar12 = iVar9;
  goto joined_r0x000ed1dc;
}

/* FUN_000ed3c8 @ 0xed3c8 (1396 bytes) */
void FUN_000ed3c8(param_1)
  int param_1;
{
  char cVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  code *pcVar12;
  int iVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint *puVar18;
  uint *puVar19;
  uint uVar20;
  double dVar21;
  double extraout_f1;
  double extraout_f1_00;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  double in_stack_ffffff88;
  int local_50;
  int local_4c [3];
  
  iVar13 = -1;
  bVar3 = false;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar3 = true;
  }
  bVar3 = !bVar3;
  bVar5 = false;
  if ((bVar3) && (*(char *)(param_1 + 0x30aa) != '\0')) {
    bVar5 = true;
  }
  bVar6 = false;
  if (((bVar3) && (*(char *)(param_1 + 0x30aa) != '\0')) && (*(char *)(param_1 + 0x30ac) != '\0')) {
    bVar6 = true;
  }
  cVar1 = *(char *)(param_1 + 0x4fe0);
  uVar20 = *(uint *)(param_1 + 0x4854);
  if (((int)*(short *)(param_1 + 0x487c) != 0) &&
     (uVar16 = (*(int *)(param_1 + 0x4858) - uVar20) / (uint)(int)*(short *)(param_1 + 0x487c),
     3 < (int)uVar16)) {
    if (bVar3) {
      uVar9 = (**(code **)(param_1 + 0x5060))(param_1,uVar20,uVar16);
    }
    else {
      uVar9 = _gleVPEmulate(param_1,uVar16);
    }
    if ((uVar9 & 0xff00) == 0) {
      if (bVar3) {
        if (*(char *)(param_1 + 0x53e4) != '\0') {
          (**(code **)(param_1 + 0x53dc))(param_1,uVar20,uVar16);
        }
        if (*(char *)(param_1 + 0x50b4) != '\0') {
          (**(code **)(param_1 + 0x5064))(param_1,uVar20,uVar16);
        }
        if ((bVar5) || (*(char *)(param_1 + 0x53e6) != '\0')) {
          (**(code **)(param_1 + 0x5068))(param_1,uVar20,uVar16);
        }
        if (*(char *)(param_1 + 0x53e5) != '\0') {
          (**(code **)(param_1 + 0x53e0))(param_1,uVar20,uVar16);
        }
      }
      else {
        uVar20 = *(uint *)(param_1 + 0x4864);
      }
      if (((uVar9 & 0xff) != 0) || (*(char *)(param_1 + 0x4e18) != '\0')) {
        bVar4 = false;
        dVar21 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, uVar20, uVar16, 0);
        puVar19 = *(uint **)(param_1 + 0x4870);
        puVar14 = *(uint **)(param_1 + 0x4874);
        uVar7 = uVar20;
joined_r0x000ed748:
        do {
          if ((uVar20 + uVar16 * 0x100) - 0x400 < uVar7) {
            return;
          }
          uVar15 = uVar7 + 0x200;
          puVar19[1] = uVar7 + 0x100;
          puVar19[2] = uVar7 + 0x300;
          *puVar19 = uVar7;
          puVar19[3] = uVar15;
          if (bVar3) {
            uVar8 = *(undefined4 *)(param_1 + 0x485c);
          }
          else {
            uVar8 = *(undefined4 *)(param_1 + 0x4854);
          }
          *(undefined4 *)(param_1 + 0x4858) = uVar8;
          puVar11 = puVar14;
          iVar17 = 4;
          puVar18 = puVar19;
          uVar7 = uVar15;
        } while ((*(char *)(param_1 + 0x4e18) != '\0') &&
                (dVar21 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar19,4,puVar14,local_4c,dVar21,in_f2,
                                                    in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                    in_stack_ffffff78,in_stack_ffffff80),
                puVar11 = puVar19, iVar17 = local_4c[0], puVar18 = puVar14, local_4c[0] == 0));
        puVar14 = puVar11;
        puVar19 = puVar18;
        if ((uVar9 & 0xff) != 0) goto code_r0x000ed7cc;
        goto LAB_000ed80c;
      }
      dVar21 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x506c))(param_1, uVar20, uVar16, 0);
      if (cVar1 == '\0') {
        if (bVar5) {
          (**(code **)(param_1 + 0x4de8))(param_1,uVar20,uVar16);
        }
        _gleFeedbackQuadStrip(param_1,uVar20,uVar16,*(ushort *)(param_1 + 0x34d0) - 0x1b00);
      }
      else {
        uVar16 = (uVar20 + uVar16 * 0x100) - 0x400;
        do {
          bVar4 = false;
          iVar17 = 0;
          uVar9 = uVar20;
          do {
            while( true ) {
              uVar7 = uVar9;
              if (uVar16 < uVar20) goto LAB_000ed654;
              uVar9 = uVar20 + 0x200;
              iVar10 = ((undefined4 (*)())_gleCullQuad)(param_1,uVar20,uVar20 + 0x100,uVar20 + 0x300,uVar9,&local_50,
                                    dVar21,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                    in_stack_ffffff78,in_stack_ffffff80,in_stack_ffffff88);
              dVar21 = extraout_f1;
              if (iVar10 != 0) break;
              if (iVar13 != local_50) {
                bVar4 = true;
              }
              if ((bVar4) && (0 < iVar17)) goto LAB_000ed654;
              iVar17 = iVar17 + 2;
              iVar13 = local_50;
              uVar20 = uVar9;
              uVar9 = uVar7;
            }
            uVar20 = uVar9;
          } while (iVar17 < 1);
LAB_000ed654:
          iVar17 = iVar17 + 2;
          if (3 < iVar17) {
            if (bVar6) {
              if (bVar4) {
                uVar9 = uVar7;
                do {
                  *(byte *)(uVar9 + 0x7e) = *(byte *)(uVar9 + 0x7e) | 6;
                  uVar9 = uVar9 + 0x100;
                } while ((int)uVar9 <= (int)(uVar7 + 0x100));
              }
              pcVar12 = *(code **)(iVar13 * 4 + param_1 + 0x4de8);
LAB_000ed6b4:
              (*pcVar12)(param_1,uVar7,iVar17);
            }
            else if (bVar5) {
              pcVar12 = *(code **)(param_1 + 0x4de8);
              goto LAB_000ed6b4;
            }
            if ((!bVar3) && (bVar5)) {
              _gleVPFlipColors(param_1,uVar7,iVar17,iVar13);
            }
            if (iVar13 == 0) {
              uVar2 = *(ushort *)(param_1 + 0x34d0);
            }
            else {
              uVar2 = *(ushort *)(param_1 + 0x34d2);
            }
            dVar21 = (double)_gleFeedbackQuadStrip(param_1,uVar7,iVar17,uVar2 - 0x1b00);
          }
        } while (uVar20 <= uVar16);
      }
    }
  }
  return;
code_r0x000ed7cc:
  dVar21 = (double)_gleClipPoly(param_1,puVar18,iVar17,uVar9 & 0xff,puVar11,local_4c,1);
  if (local_4c[0] == 0) goto joined_r0x000ed748;
  if (0 < local_4c[0]) {
    puVar14 = puVar18;
    iVar17 = local_4c[0];
    puVar19 = puVar11;
  }
LAB_000ed80c:
  if ((cVar1 != '\0') &&
     (iVar10 = ((int (*)())_gleCullPolygonPtrStack)(param_1,puVar19,iVar17,&local_50), dVar21 = extraout_f1_00,
     iVar10 != 0)) goto joined_r0x000ed748;
  iVar10 = local_50;
  if (iVar13 != local_50) {
    bVar4 = true;
  }
  if (bVar6) {
    if (bVar4) {
      puVar11 = puVar19;
      iVar13 = iVar17;
      if (0 < iVar17) {
        do {
          *(byte *)(*puVar11 + 0x7e) = *(byte *)(*puVar11 + 0x7e) | 6;
          iVar13 = iVar13 + -1;
          puVar11 = puVar11 + 1;
        } while (iVar13 != 0);
      }
      bVar4 = false;
    }
    pcVar12 = *(code **)(local_50 * 4 + param_1 + 0x4df0);
  }
  else {
    if (!bVar5) goto LAB_000ed8b4;
    pcVar12 = *(code **)(param_1 + 0x4df0);
  }
  (*pcVar12)(param_1,puVar19,iVar17);
LAB_000ed8b4:
  if (((!bVar3) && (bVar5)) && (puVar11 = puVar19, iVar13 = iVar17, 0 < iVar17)) {
    do {
      _gleVPFlipColors(param_1,*puVar11,1,iVar10);
      iVar13 = iVar13 + -1;
      puVar11 = puVar11 + 1;
    } while (iVar13 != 0);
  }
  if (iVar10 == 0) {
    uVar2 = *(ushort *)(param_1 + 0x34d0);
  }
  else {
    uVar2 = *(ushort *)(param_1 + 0x34d2);
  }
  dVar21 = (double)_gleFeedbackPolygonPtr(param_1,puVar19,iVar17,uVar2 - 0x1b00);
  iVar13 = iVar10;
  goto joined_r0x000ed748;
}

/* FUN_000ed940 @ 0xed940 (956 bytes) */
void FUN_000ed940(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  char cVar3;
  ushort uVar4;
  bool bVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  code *pcVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  double extraout_f1;
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
  int local_40;
  int local_3c [4];
  
  local_3c[0] = 0;
  iVar7 = _gleTexEnableBits(param_1);
  bVar5 = false;
  bVar1 = (int)-(uint)*(byte *)(param_1 + 0x30aa) < 0;
  if ((bVar1) && (*(char *)(param_1 + 0x30ac) != '\0')) {
    bVar5 = true;
  }
  piVar13 = *(int **)(param_1 + 0x4854);
  cVar3 = *(char *)(param_1 + 0x34de);
  iVar14 = *(int *)(param_1 + 0x4858) - (int)piVar13 >> 8;
  if (iVar14 < 3) {
    return;
  }
  uVar8 = (**(code **)(param_1 + 0x5060))(param_1,piVar13,iVar14);
  if ((uVar8 & 0xff00) != 0) {
    return;
  }
  bVar2 = iVar7 != 0;
  fparam_1 = extraout_f1;
  if ((bVar2) && (*(char *)(param_1 + 0x53e4) != '\0')) {
    fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53dc))(param_1, piVar13, iVar14);
  }
  if (*(char *)(param_1 + 0x50b4) != '\0') {
    fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, piVar13, iVar14);
  }
  if (bVar1) {
LAB_000eda38:
    fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, piVar13, iVar14);
LAB_000eda50:
    if ((bVar2) && (*(char *)(param_1 + 0x53e5) != '\0')) {
      fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53e0))(param_1, piVar13, iVar14);
    }
  }
  else if (bVar2) {
    if (*(char *)(param_1 + 0x53e6) != '\0') goto LAB_000eda38;
    goto LAB_000eda50;
  }
  if (((uVar8 & 0xff) != 0) || (*(char *)(param_1 + 0x4e18) != '\0')) {
    if (bVar2) {
      fparam_1 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, piVar13, iVar14, 0);
    }
    piVar12 = *(int **)(param_1 + 0x4870);
    piVar11 = *(int **)(param_1 + 0x4874);
    piVar6 = piVar12;
    iVar7 = iVar14;
    if (0 < iVar14) {
      do {
        *piVar6 = (int)piVar13;
        piVar13 = piVar13 + 0x40;
        iVar7 = iVar7 + -1;
        piVar6 = piVar6 + 1;
      } while (iVar7 != 0);
    }
    uVar9 = 0;
    piVar6 = piVar11;
    if (*(char *)(param_1 + 0x4e18) != '\0') {
      ((double (*)())_gleClipPolyPlane)(param_1,piVar12,iVar14,piVar11,&local_40,fparam_1,in_f2,in_f3,in_f4,in_f5,
                        in_f6,in_f7,in_f8,in_stack_ffffff88,in_stack_ffffff90);
      if (local_40 == 0) {
        return;
      }
      uVar9 = 1;
      piVar6 = piVar12;
      iVar14 = local_40;
      piVar12 = piVar11;
    }
    piVar13 = piVar12;
    if ((uVar8 & 0xff) != 0) {
      _gleClipPoly(param_1,piVar12,iVar14,uVar8 & 0xff,piVar6,&local_40,uVar9);
      if (local_40 == 0) {
        return;
      }
      if (0 < local_40) {
        iVar14 = local_40;
        piVar13 = piVar6;
      }
    }
    if ((cVar3 != '\0') &&
       (iVar7 = ((int (*)())_gleCullPolygonPtrStack)(param_1,piVar13,iVar14,local_3c), iVar7 != 0)) {
      return;
    }
    if (bVar5) {
      pcVar10 = *(code **)(local_3c[0] * 4 + param_1 + 0x4df0);
LAB_000edbbc:
      (*pcVar10)(param_1,piVar13,iVar14);
    }
    else if (bVar1) {
      pcVar10 = *(code **)(param_1 + 0x4df0);
      goto LAB_000edbbc;
    }
    if (local_3c[0] == 0) {
      uVar4 = *(ushort *)(param_1 + 0x34d0);
    }
    else {
      uVar4 = *(ushort *)(param_1 + 0x34d2);
    }
    iVar7 = uVar4 - 0x1b00;
    if ((*(char *)(param_1 + 0x4a18) != '\0') && (iVar7 == 1)) {
      iVar7 = 3;
    }
    pcVar10 = *(code **)(param_1 + 0x46e0);
    goto LAB_000edcd4;
  }
  if ((cVar3 != '\0') &&
     (iVar7 = ((int (*)())_gleCullPolygonStack)(param_1,piVar13,iVar14,0,local_3c), iVar7 != 0)) {
    return;
  }
  if (bVar2) {
    (**(code **)(param_1 + 0x506c))(param_1,piVar13,iVar14,0);
  }
  if (bVar5) {
    pcVar10 = *(code **)(local_3c[0] * 4 + param_1 + 0x4de8);
LAB_000edc8c:
    (*pcVar10)(param_1,piVar13,iVar14);
  }
  else if (bVar1) {
    pcVar10 = *(code **)(param_1 + 0x4de8);
    goto LAB_000edc8c;
  }
  if (local_3c[0] == 0) {
    uVar4 = *(ushort *)(param_1 + 0x34d0);
  }
  else {
    uVar4 = *(ushort *)(param_1 + 0x34d2);
  }
  iVar7 = uVar4 - 0x1b00;
  if ((*(char *)(param_1 + 0x4a18) != '\0') && (iVar7 == 1)) {
    iVar7 = 3;
  }
  pcVar10 = *(code **)(param_1 + 0x46c0);
LAB_000edcd4:
  (*pcVar10)(*(undefined4 *)(param_1 + 0x4688),piVar13,iVar14,iVar7);
  return;
}

/* FUN_000edd00 @ 0xedd00 (984 bytes) */
void FUN_000edd00(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  char cVar3;
  ushort uVar4;
  bool bVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  code *pcVar10;
  int *piVar11;
  char cVar12;
  int *piVar13;
  int *piVar14;
  int iVar15;
  double extraout_f1;
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
  int local_40;
  int local_3c [3];
  
  local_3c[0] = 0;
  iVar7 = _gleTexEnableBits(param_1);
  cVar12 = *(char *)(param_1 + 0x30aa);
  bVar5 = false;
  bVar1 = cVar12 != '\0';
  if ((bVar1) && (*(char *)(param_1 + 0x30ac) != '\0')) {
    bVar5 = true;
  }
  piVar14 = *(int **)(param_1 + 0x4854);
  cVar3 = *(char *)(param_1 + 0x34de);
  iVar15 = *(int *)(param_1 + 0x4858) - (int)piVar14 >> 8;
  if ((2 < iVar15) &&
     (uVar8 = (**(code **)(param_1 + 0x5060))(param_1,piVar14,iVar15), (uVar8 & 0xff00) == 0)) {
    bVar2 = iVar7 != 0;
    fparam_1 = extraout_f1;
    if ((bVar2) && (*(char *)(param_1 + 0x53e4) != '\0')) {
      fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53dc))(param_1, piVar14, iVar15);
    }
    if (*(char *)(param_1 + 0x50b4) != '\0') {
      fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, piVar14, iVar15);
    }
    if (bVar2) {
      if (*(char *)(param_1 + 0x53e6) != '\0') {
        cVar12 = '\0';
        fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, piVar14, iVar15);
      }
      if (*(char *)(param_1 + 0x53e5) != '\0') {
        fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53e0))(param_1, piVar14, iVar15);
      }
    }
    if (((uVar8 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      if ((cVar3 != '\0') &&
         (iVar7 = ((int (*)())_gleCullPolygonStack)(param_1,piVar14,iVar15,0,local_3c), iVar7 != 0)) {
        return;
      }
      if (bVar2) {
        (**(code **)(param_1 + 0x506c))(param_1,piVar14,iVar15,0);
      }
      if (cVar12 != '\0') {
        (**(code **)(param_1 + 0x5068))(param_1,piVar14,1);
      }
      if (bVar1) {
        iVar7 = 0x4de0;
        if (bVar5) {
          iVar7 = local_3c[0] * 4 + 0x4de0;
        }
        (**(code **)(param_1 + iVar7 + 8))(param_1,piVar14,1);
      }
      if (local_3c[0] == 0) {
        uVar4 = *(ushort *)(param_1 + 0x34d0);
      }
      else {
        uVar4 = *(ushort *)(param_1 + 0x34d2);
      }
      iVar7 = uVar4 - 0x1b00;
      if ((*(char *)(param_1 + 0x4a18) != '\0') && (iVar7 == 1)) {
        iVar7 = 3;
      }
      pcVar10 = *(code **)(param_1 + 0x46c0);
    }
    else {
      if (bVar2) {
        fparam_1 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, piVar14, iVar15, 0);
      }
      piVar13 = *(int **)(param_1 + 0x4870);
      piVar11 = *(int **)(param_1 + 0x4874);
      piVar6 = piVar13;
      iVar7 = iVar15;
      if (0 < iVar15) {
        do {
          *piVar6 = (int)piVar14;
          piVar14 = piVar14 + 0x40;
          iVar7 = iVar7 + -1;
          piVar6 = piVar6 + 1;
        } while (iVar7 != 0);
      }
      uVar9 = 0;
      piVar6 = piVar11;
      if (*(char *)(param_1 + 0x4e18) != '\0') {
        ((double (*)())_gleClipPolyPlane)(param_1,piVar13,iVar15,piVar11,&local_40,fparam_1,in_f2,in_f3,in_f4,in_f5,
                          in_f6,in_f7,in_f8,in_stack_ffffff88,in_stack_ffffff90);
        if (local_40 == 0) {
          return;
        }
        uVar9 = 1;
        piVar6 = piVar13;
        iVar15 = local_40;
        piVar13 = piVar11;
      }
      piVar14 = piVar13;
      if ((uVar8 & 0xff) != 0) {
        _gleClipPoly(param_1,piVar13,iVar15,uVar8 & 0xff,piVar6,&local_40,uVar9);
        if (local_40 == 0) {
          return;
        }
        if (0 < local_40) {
          iVar15 = local_40;
          piVar14 = piVar6;
        }
      }
      if ((cVar3 != '\0') &&
         (iVar7 = ((int (*)())_gleCullPolygonPtrStack)(param_1,piVar14,iVar15,local_3c), iVar7 != 0)) {
        return;
      }
      if (cVar12 != '\0') {
        (**(code **)(param_1 + 0x5068))(param_1,*piVar14,1);
      }
      if (bVar1) {
        iVar7 = 0x4de0;
        if (bVar5) {
          iVar7 = local_3c[0] * 4 + 0x4de0;
        }
        (**(code **)(param_1 + iVar7 + 8))(param_1,*piVar14,1);
      }
      if (local_3c[0] == 0) {
        uVar4 = *(ushort *)(param_1 + 0x34d0);
      }
      else {
        uVar4 = *(ushort *)(param_1 + 0x34d2);
      }
      iVar7 = uVar4 - 0x1b00;
      if ((*(char *)(param_1 + 0x4a18) != '\0') && (iVar7 == 1)) {
        iVar7 = 3;
      }
      pcVar10 = *(code **)(param_1 + 0x46e0);
    }
    (*pcVar10)(*(undefined4 *)(param_1 + 0x4688),piVar14,iVar15,iVar7);
  }
  return;
}

/* FUN_000ee104 @ 0xee104 (1140 bytes) */
void FUN_000ee104(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  ushort uVar5;
  bool bVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  code *pcVar10;
  int iVar11;
  uint *puVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  double extraout_f1;
  double dVar19;
  double extraout_f1_00;
  double extraout_f1_01;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff88;
  double in_stack_ffffff90;
  int local_40;
  int local_3c [3];
  
  iVar11 = -1;
  iVar8 = _gleTexEnableBits(param_1);
  bVar3 = *(byte *)(param_1 + 0x30aa);
  bVar6 = false;
  if ((bVar3 != 0) && (*(char *)(param_1 + 0x30ac) != '\0')) {
    bVar6 = true;
  }
  uVar16 = *(uint *)(param_1 + 0x4854);
  cVar4 = *(char *)(param_1 + 0x34de);
  iVar18 = (int)(*(int *)(param_1 + 0x4858) - uVar16) >> 8;
  if (iVar18 < 3) {
    return;
  }
  uVar9 = (**(code **)(param_1 + 0x5060))(param_1,uVar16,iVar18);
  if ((uVar9 & 0xff00) != 0) {
    return;
  }
  bVar1 = iVar8 != 0;
  dVar19 = extraout_f1;
  if ((bVar1) && (*(char *)(param_1 + 0x53e4) != '\0')) {
    dVar19 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53dc))(param_1, uVar16, iVar18);
  }
  if (*(char *)(param_1 + 0x50b4) != '\0') {
    dVar19 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, uVar16, iVar18);
  }
  bVar2 = (int)-(uint)bVar3 < 0;
  if (bVar2) {
LAB_000ee1fc:
    dVar19 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, uVar16, iVar18);
  }
  else {
    if (!bVar1) goto LAB_000ee23c;
    if (*(char *)(param_1 + 0x53e6) != '\0') goto LAB_000ee1fc;
  }
  if ((bVar1) && (*(char *)(param_1 + 0x53e5) != '\0')) {
    dVar19 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53e0))(param_1, uVar16, iVar18);
  }
LAB_000ee23c:
  if (((uVar9 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
    if (bVar1) {
      dVar19 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x506c))(param_1, uVar16, iVar18, 0);
    }
    if (cVar4 == '\0') {
      if (bVar2) {
        (**(code **)(param_1 + 0x4de8))(param_1,uVar16,iVar18);
      }
      (**(code **)(param_1 + 0x46c4))
                (*(undefined4 *)(param_1 + 0x4688),uVar16,iVar18,
                 *(ushort *)(param_1 + 0x34d0) - 0x1b00);
    }
    else {
      uVar9 = (uVar16 + iVar18 * 0x100) - 0x300;
      do {
        bVar1 = false;
        iVar8 = 0;
        uVar15 = uVar16;
        uVar17 = uVar16;
        if (uVar16 <= uVar9) {
          do {
            iVar18 = ((undefined4 (*)())_gleCullTriangle)(param_1,uVar16,uVar16 + 0x100,uVar16 + 0x200,0,&local_40,
                                      dVar19,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                      in_stack_ffffff88,in_stack_ffffff90);
            dVar19 = dVar19;
            if (iVar18 == 0) {
              if (iVar11 != local_40) {
                bVar1 = true;
              }
              if ((bVar1) && (uVar17 = uVar16, 0 < iVar8)) break;
              iVar8 = iVar8 + 3;
              iVar11 = local_40;
              uVar17 = uVar15;
            }
            else {
              uVar17 = uVar16 + 0x300;
              if (0 < iVar8) break;
            }
            uVar16 = uVar16 + 0x300;
            uVar15 = uVar17;
            uVar17 = uVar16;
          } while (uVar16 <= uVar9);
          if (2 < iVar8) {
            if (bVar6) {
              pcVar10 = *(code **)(iVar11 * 4 + param_1 + 0x4de8);
LAB_000ee37c:
              (*pcVar10)(param_1,uVar15,iVar8);
            }
            else if (bVar2) {
              pcVar10 = *(code **)(param_1 + 0x4de8);
              goto LAB_000ee37c;
            }
            if (iVar11 == 0) {
              uVar5 = *(ushort *)(param_1 + 0x34d0);
            }
            else {
              uVar5 = *(ushort *)(param_1 + 0x34d2);
            }
            dVar19 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46c4))
                                       (*(undefined4 *)(param_1 + 0x4688), uVar15, iVar8, uVar5 - 0x1b00);
          }
        }
        uVar16 = uVar17;
      } while (uVar17 <= uVar9);
    }
  }
  else {
    if (bVar1) {
      dVar19 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, uVar16, iVar18, 0);
    }
    puVar14 = *(uint **)(param_1 + 0x4870);
    puVar12 = *(uint **)(param_1 + 0x4874);
    uVar17 = (uVar16 + iVar18 * 0x100) - 0x300;
    if (uVar16 <= uVar17) {
      do {
        puVar14[1] = uVar16 + 0x100;
        puVar14[2] = uVar16 + 0x200;
        *puVar14 = uVar16;
        *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x485c);
        puVar13 = puVar12;
        puVar7 = puVar14;
        iVar11 = 3;
        if ((*(char *)(param_1 + 0x4e18) == '\0') ||
           (dVar19 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar14,3,puVar12,local_3c,dVar19,in_f2,in_f3
                                               ,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff88,
                                               in_stack_ffffff90), puVar13 = puVar14,
           puVar7 = puVar12, iVar11 = local_3c[0], local_3c[0] != 0)) {
          puVar14 = puVar7;
          puVar12 = puVar13;
          if ((uVar9 & 0xff) != 0) {
            dVar19 = (double)_gleClipPoly(param_1,puVar14,iVar11,uVar9 & 0xff,puVar13,local_3c,1);
            if (local_3c[0] == 0) goto LAB_000ee550;
            if (0 < local_3c[0]) {
              puVar12 = puVar14;
              puVar14 = puVar13;
              iVar11 = local_3c[0];
            }
          }
          if ((cVar4 == '\0') ||
             (iVar8 = ((int (*)())_gleCullPolygonPtrStack)(param_1,puVar14,iVar11,&local_40),
             dVar19 = extraout_f1_01, iVar8 == 0)) {
            iVar8 = local_40;
            if (bVar6) {
              pcVar10 = *(code **)(local_40 * 4 + param_1 + 0x4df0);
LAB_000ee514:
              (*pcVar10)(param_1,puVar14,iVar11);
            }
            else if (bVar2) {
              pcVar10 = *(code **)(param_1 + 0x4df0);
              goto LAB_000ee514;
            }
            if (iVar8 == 0) {
              uVar5 = *(ushort *)(param_1 + 0x34d0);
            }
            else {
              uVar5 = *(ushort *)(param_1 + 0x34d2);
            }
            dVar19 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46e0))
                                       (*(undefined4 *)(param_1 + 0x4688), puVar14, iVar11, uVar5 - 0x1b00);
          }
        }
LAB_000ee550:
        uVar16 = uVar16 + 0x300;
      } while (uVar16 <= uVar17);
    }
  }
  return;
}

/* FUN_000ee57c @ 0xee57c (1312 bytes) */
void FUN_000ee57c(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  char cVar3;
  ushort uVar4;
  bool bVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  uint *puVar12;
  int iVar13;
  char cVar14;
  uint uVar15;
  uint *puVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  double extraout_f1;
  double dVar20;
  double extraout_f1_00;
  double extraout_f1_01;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  int local_50;
  int local_4c [6];
  
  iVar10 = -1;
  iVar7 = _gleTexEnableBits(param_1);
  cVar14 = *(char *)(param_1 + 0x30aa);
  bVar5 = false;
  bVar1 = cVar14 != '\0';
  if ((bVar1) && (*(char *)(param_1 + 0x30ac) != '\0')) {
    bVar5 = true;
  }
  uVar18 = *(uint *)(param_1 + 0x4854);
  cVar3 = *(char *)(param_1 + 0x34de);
  iVar17 = (int)(*(int *)(param_1 + 0x4858) - uVar18) >> 8;
  if ((2 < iVar17) &&
     (uVar8 = (**(code **)(param_1 + 0x5060))(param_1,uVar18,iVar17), (uVar8 & 0xff00) == 0)) {
    bVar2 = iVar7 != 0;
    dVar20 = extraout_f1;
    if ((bVar2) && (*(char *)(param_1 + 0x53e4) != '\0')) {
      dVar20 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53dc))(param_1, uVar18, iVar17);
    }
    if (*(char *)(param_1 + 0x50b4) != '\0') {
      dVar20 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, uVar18, iVar17);
    }
    if (bVar2) {
      if (*(char *)(param_1 + 0x53e6) != '\0') {
        cVar14 = '\0';
        dVar20 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, uVar18, iVar17);
      }
      if (*(char *)(param_1 + 0x53e5) != '\0') {
        dVar20 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53e0))(param_1, uVar18, iVar17);
      }
    }
    if (((uVar8 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      if (bVar2) {
        dVar20 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x506c))(param_1, uVar18, iVar17, 0);
      }
      if (cVar3 == '\0') {
        if (bVar1) {
          iVar10 = 0;
          if (-1 < iVar17 + -3) {
            iVar7 = uVar18 + 0x200;
            do {
              if (cVar14 != '\0') {
                (**(code **)(param_1 + 0x5068))(param_1,iVar7,1);
              }
              iVar10 = iVar10 + 3;
              (**(code **)(param_1 + 0x4de8))(param_1,iVar7,1);
              iVar7 = iVar7 + 0x300;
            } while (iVar10 <= iVar17 + -3);
          }
        }
        (**(code **)(param_1 + 0x46c4))
                  (*(undefined4 *)(param_1 + 0x4688),uVar18,iVar17,
                   *(ushort *)(param_1 + 0x34d0) - 0x1b00);
      }
      else {
        uVar8 = (uVar18 + iVar17 * 0x100) - 0x300;
        do {
          iVar7 = 0;
          bVar2 = false;
          uVar15 = uVar18;
          uVar19 = uVar18;
          if (uVar18 <= uVar8) {
            do {
              iVar17 = ((undefined4 (*)())_gleCullTriangle)(param_1,uVar18,uVar18 + 0x100,uVar18 + 0x200,0,&local_50,
                                        dVar20,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                        in_stack_ffffff78,in_stack_ffffff80);
              dVar20 = dVar20;
              if (iVar17 == 0) {
                if (iVar10 != local_50) {
                  bVar2 = true;
                }
                if ((bVar2) && (uVar19 = uVar18, 0 < iVar7)) break;
                iVar7 = iVar7 + 3;
                iVar10 = local_50;
                uVar19 = uVar15;
              }
              else {
                uVar19 = uVar18 + 0x300;
                if (0 < iVar7) break;
              }
              uVar18 = uVar18 + 0x300;
              uVar15 = uVar19;
              uVar19 = uVar18;
            } while (uVar18 <= uVar8);
            if (2 < iVar7) {
              if (bVar1) {
                iVar17 = iVar10;
                if (!bVar5) {
                  iVar17 = 0;
                }
                iVar13 = 0;
                if (-1 < iVar7 + -3) {
                  iVar9 = uVar15 + 0x200;
                  do {
                    if (cVar14 != '\0') {
                      (**(code **)(param_1 + 0x5068))(param_1,iVar9,1);
                    }
                    iVar13 = iVar13 + 3;
                    (**(code **)(iVar17 * 4 + param_1 + 0x4de8))(param_1,iVar9,1);
                    iVar9 = iVar9 + 0x300;
                  } while (iVar13 <= iVar7 + -3);
                }
              }
              if (iVar10 == 0) {
                uVar4 = *(ushort *)(param_1 + 0x34d0);
              }
              else {
                uVar4 = *(ushort *)(param_1 + 0x34d2);
              }
              dVar20 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46c4))
                                         (*(undefined4 *)(param_1 + 0x4688), uVar15, iVar7, uVar4 - 0x1b00);
            }
          }
          uVar18 = uVar19;
        } while (uVar19 <= uVar8);
      }
    }
    else {
      if (bVar2) {
        dVar20 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, uVar18, iVar17, 0);
      }
      puVar16 = *(uint **)(param_1 + 0x4870);
      iVar10 = uVar18 + iVar17 * 0x100;
      puVar11 = *(uint **)(param_1 + 0x4874);
      for (; uVar18 <= iVar10 - 0x300U; uVar18 = uVar18 + 0x300) {
        uVar19 = uVar18 + 0x200;
        puVar16[1] = uVar18 + 0x100;
        *puVar16 = uVar18;
        puVar16[2] = uVar19;
        *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x485c);
        puVar12 = puVar11;
        puVar6 = puVar16;
        iVar7 = 3;
        if ((*(char *)(param_1 + 0x4e18) == '\0') ||
           (dVar20 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar16,3,puVar11,local_4c,dVar20,in_f2,in_f3
                                               ,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff78,
                                               in_stack_ffffff80), puVar12 = puVar16,
           puVar6 = puVar11, iVar7 = local_4c[0], local_4c[0] != 0)) {
          puVar16 = puVar6;
          puVar11 = puVar12;
          if ((uVar8 & 0xff) != 0) {
            dVar20 = (double)_gleClipPoly(param_1,puVar16,iVar7,uVar8 & 0xff,puVar12,local_4c,1);
            if (local_4c[0] == 0) goto LAB_000eea74;
            if (0 < local_4c[0]) {
              puVar11 = puVar16;
              puVar16 = puVar12;
              iVar7 = local_4c[0];
            }
          }
          if ((cVar3 == '\0') ||
             (iVar17 = ((int (*)())_gleCullPolygonPtrStack)(param_1,puVar16,iVar7,&local_50),
             dVar20 = extraout_f1_01, iVar17 == 0)) {
            if (cVar14 != '\0') {
              (**(code **)(param_1 + 0x5068))(param_1,uVar19,1);
            }
            if (bVar1) {
              iVar17 = 0x4de0;
              if (bVar5) {
                iVar17 = local_50 * 4 + 0x4de0;
              }
              (**(code **)(param_1 + iVar17 + 8))(param_1,uVar19,1);
            }
            *(undefined8 *)(*puVar16 + 0x30) = *(undefined8 *)(uVar18 + 0x230);
            *(undefined8 *)(*puVar16 + 0x38) = *(undefined8 *)(uVar18 + 0x238);
            if (local_50 == 0) {
              uVar4 = *(ushort *)(param_1 + 0x34d0);
            }
            else {
              uVar4 = *(ushort *)(param_1 + 0x34d2);
            }
            dVar20 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46e0))
                                       (*(undefined4 *)(param_1 + 0x4688), puVar16, iVar7, uVar4 - 0x1b00);
          }
        }
LAB_000eea74: ;
      }
    }
  }
  return;
}

/* FUN_000eeac8 @ 0xeeac8 (1412 bytes) */
void FUN_000eeac8(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  ushort uVar5;
  bool bVar6;
  bool bVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint *puVar14;
  code *pcVar15;
  uint uVar16;
  int *piVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  uint *puVar21;
  uint uVar22;
  uint uVar23;
  uint *puVar24;
  int iVar25;
  double extraout_f1;
  double dVar26;
  double extraout_f1_00;
  double extraout_f1_01;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  int local_50;
  int local_4c [4];
  
  iVar18 = -1;
  iVar11 = _gleTexEnableBits(param_1);
  bVar3 = *(byte *)(param_1 + 0x30aa);
  bVar6 = false;
  if ((bVar3 != 0) && (*(char *)(param_1 + 0x30ac) != '\0')) {
    bVar6 = true;
  }
  uVar22 = *(uint *)(param_1 + 0x4854);
  uVar16 = 0;
  cVar4 = *(char *)(param_1 + 0x34de);
  iVar25 = (int)(*(int *)(param_1 + 0x4858) - uVar22) >> 8;
  if (iVar25 < 3) {
    return;
  }
  uVar12 = (**(code **)(param_1 + 0x5060))(param_1,uVar22,iVar25);
  if ((uVar12 & 0xff00) != 0) {
    return;
  }
  bVar1 = iVar11 != 0;
  dVar26 = extraout_f1;
  if ((bVar1) && (*(char *)(param_1 + 0x53e4) != '\0')) {
    dVar26 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53dc))(param_1, uVar22, iVar25);
  }
  if (*(char *)(param_1 + 0x50b4) != '\0') {
    dVar26 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, uVar22, iVar25);
  }
  bVar2 = (int)-(uint)bVar3 < 0;
  if (bVar2) {
LAB_000eebc4:
    dVar26 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, uVar22, iVar25);
  }
  else {
    if (!bVar1) goto LAB_000eec04;
    if (*(char *)(param_1 + 0x53e6) != '\0') goto LAB_000eebc4;
  }
  if ((bVar1) && (*(char *)(param_1 + 0x53e5) != '\0')) {
    dVar26 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53e0))(param_1, uVar22, iVar25);
  }
LAB_000eec04:
  if (((uVar12 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
    if (bVar1) {
      dVar26 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x506c))(param_1, uVar22, iVar25, 0);
    }
    if (cVar4 == '\0') {
      if (bVar2) {
        (**(code **)(param_1 + 0x4de8))(param_1,uVar22,iVar25);
      }
      (**(code **)(param_1 + 0x46cc))
                (*(undefined4 *)(param_1 + 0x4688),uVar22,iVar25,
                 *(ushort *)(param_1 + 0x34d0) - 0x1b00);
    }
    else {
      piVar17 = *(int **)(param_1 + 0x4870);
      uVar19 = (uVar22 + iVar25 * 0x100) - 0x300;
      uVar12 = 0;
      do {
        bVar1 = false;
        iVar11 = 0;
        uVar10 = uVar12;
        uVar8 = uVar22;
        while (uVar12 = uVar10, uVar22 <= uVar19) {
          uVar23 = uVar22 + 0x100;
          iVar25 = ((undefined4 (*)())_gleCullTriangle)(param_1,uVar22,uVar23,uVar22 + 0x200,uVar10,&local_50,dVar26,
                                    in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff78,
                                    in_stack_ffffff80);
          dVar26 = extraout_f1_00;
          if (iVar25 == 0) {
            if (iVar18 != local_50) {
              bVar1 = true;
            }
            if ((bVar1) && (0 < iVar11)) break;
            if (iVar11 == 0) {
              uVar16 = uVar10;
            }
            iVar11 = iVar11 + 1;
            iVar18 = local_50;
            uVar20 = uVar8;
          }
          else {
            uVar20 = uVar23;
            uVar12 = uVar10 ^ 1;
            uVar22 = uVar23;
            if (0 < iVar11) break;
          }
          uVar10 = uVar10 ^ 1;
          uVar22 = uVar23;
          uVar8 = uVar20;
        }
        iVar25 = iVar11 + 2;
        if (2 < iVar25) {
          if (bVar6) {
            if (bVar1) {
              uVar10 = uVar8;
              do {
                *(byte *)(uVar10 + 0x7e) = *(byte *)(uVar10 + 0x7e) | 6;
                uVar10 = uVar10 + 0x100;
              } while ((int)uVar10 <= (int)(uVar8 + 0x100));
            }
            pcVar15 = *(code **)(iVar18 * 4 + param_1 + 0x4de8);
LAB_000eed90:
            (*pcVar15)(param_1,uVar8,iVar25);
          }
          else if (bVar2) {
            pcVar15 = *(code **)(param_1 + 0x4de8);
            goto LAB_000eed90;
          }
          uVar10 = uVar8;
          if (uVar16 != 0) {
            uVar10 = uVar8 + 0x100;
            *piVar17 = uVar8 + 0x200;
            piVar17[2] = uVar8;
            piVar17[1] = uVar10;
            if (iVar18 != 0) {
              uVar5 = *(ushort *)(param_1 + 0x34d2);
            }
            else {
              uVar5 = *(ushort *)(param_1 + 0x34d0);
            }
            iVar25 = iVar11 + 1;
            dVar26 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46e0))
                                       (*(undefined4 *)(param_1 + 0x4688), piVar17, 3, uVar5 - 0x1b00);
            if (iVar25 < 3) goto LAB_000eee24;
          }
          if (iVar18 != 0) {
            uVar5 = *(ushort *)(param_1 + 0x34d2);
          }
          else {
            uVar5 = *(ushort *)(param_1 + 0x34d0);
          }
          dVar26 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46cc))
                                     (*(undefined4 *)(param_1 + 0x4688), uVar10, iVar25, uVar5 - 0x1b00);
        }
LAB_000eee24: ;
      } while (uVar22 <= uVar19);
    }
  }
  else {
    if (bVar1) {
      dVar26 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, uVar22, iVar25, 0);
    }
    bVar1 = false;
    uVar16 = (uVar22 + iVar25 * 0x100) - 0x300;
    puVar21 = *(uint **)(param_1 + 0x4874);
    puVar24 = *(uint **)(param_1 + 0x4870);
    if (uVar22 <= uVar16) {
      bVar7 = false;
      do {
        bVar7 = !bVar7;
        if (bVar7) {
          puVar24[2] = uVar22 + 0x200;
          *puVar24 = uVar22;
        }
        else {
          *puVar24 = uVar22 + 0x200;
          puVar24[2] = uVar22;
        }
        uVar22 = uVar22 + 0x100;
        puVar24[1] = uVar22;
        *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x485c);
        puVar14 = puVar21;
        puVar9 = puVar24;
        iVar25 = 3;
        iVar11 = iVar18;
        if ((*(char *)(param_1 + 0x4e18) == '\0') ||
           (dVar26 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar24,3,puVar21,local_4c,dVar26,in_f2,in_f3
                                               ,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff78,
                                               in_stack_ffffff80), puVar14 = puVar24,
           puVar9 = puVar21, iVar25 = local_4c[0], local_4c[0] != 0)) {
          puVar24 = puVar9;
          puVar21 = puVar14;
          if ((uVar12 & 0xff) != 0) {
            dVar26 = (double)_gleClipPoly(param_1,puVar24,iVar25,uVar12 & 0xff,puVar14,local_4c,1);
            if (local_4c[0] == 0) goto LAB_000ef024;
            if (0 < local_4c[0]) {
              puVar21 = puVar24;
              puVar24 = puVar14;
              iVar25 = local_4c[0];
            }
          }
          if ((cVar4 == '\0') ||
             (iVar13 = ((int (*)())_gleCullPolygonPtrStack)(param_1,puVar24,iVar25,&local_50),
             dVar26 = extraout_f1_01, iVar13 == 0)) {
            iVar11 = local_50;
            if (iVar18 != local_50) {
              bVar1 = true;
            }
            if (bVar6) {
              if (bVar1) {
                puVar14 = puVar24;
                iVar18 = iVar25;
                if (0 < iVar25) {
                  do {
                    *(byte *)(*puVar14 + 0x7e) = *(byte *)(*puVar14 + 0x7e) | 6;
                    iVar18 = iVar18 + -1;
                    puVar14 = puVar14 + 1;
                  } while (iVar18 != 0);
                }
                bVar1 = false;
              }
              pcVar15 = *(code **)(local_50 * 4 + param_1 + 0x4df0);
LAB_000eefe8:
              (*pcVar15)(param_1,puVar24,iVar25);
            }
            else if (bVar2) {
              pcVar15 = *(code **)(param_1 + 0x4df0);
              goto LAB_000eefe8;
            }
            if (iVar11 == 0) {
              uVar5 = *(ushort *)(param_1 + 0x34d0);
            }
            else {
              uVar5 = *(ushort *)(param_1 + 0x34d2);
            }
            dVar26 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46e0))
                                       (*(undefined4 *)(param_1 + 0x4688), puVar24, iVar25, uVar5 - 0x1b00);
          }
        }
LAB_000ef024:
        iVar18 = iVar11;
      } while (uVar22 <= uVar16);
    }
  }
  return;
}

/* FUN_000ef050 @ 0xef050 (1396 bytes) */
void FUN_000ef050(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  char cVar3;
  ushort uVar4;
  bool bVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  uint *puVar18;
  char cVar20;
  int iVar19;
  uint uVar21;
  uint uVar22;
  int iVar23;
  uint *puVar24;
  int iVar25;
  double extraout_f1;
  double dVar26;
  double extraout_f1_00;
  double extraout_f1_01;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  int local_50;
  int local_4c [5];
  
  iVar14 = -1;
  iVar9 = _gleTexEnableBits(param_1);
  cVar20 = *(char *)(param_1 + 0x30aa);
  bVar5 = false;
  bVar1 = cVar20 != '\0';
  if ((bVar1) && (*(char *)(param_1 + 0x30ac) != '\0')) {
    bVar5 = true;
  }
  uVar21 = *(uint *)(param_1 + 0x4854);
  uVar12 = 0;
  cVar3 = *(char *)(param_1 + 0x34de);
  iVar25 = (int)(*(int *)(param_1 + 0x4858) - uVar21) >> 8;
  if ((2 < iVar25) &&
     (uVar10 = (**(code **)(param_1 + 0x5060))(param_1,uVar21,iVar25), (uVar10 & 0xff00) == 0)) {
    bVar2 = iVar9 != 0;
    dVar26 = extraout_f1;
    if ((bVar2) && (*(char *)(param_1 + 0x53e4) != '\0')) {
      dVar26 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53dc))(param_1, uVar21, iVar25);
    }
    if (*(char *)(param_1 + 0x50b4) != '\0') {
      dVar26 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, uVar21, iVar25);
    }
    if (bVar2) {
      if (*(char *)(param_1 + 0x53e6) != '\0') {
        cVar20 = '\0';
        dVar26 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, uVar21, iVar25);
      }
      if (*(char *)(param_1 + 0x53e5) != '\0') {
        dVar26 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53e0))(param_1, uVar21, iVar25);
      }
    }
    if (cVar20 != '\0') {
      dVar26 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, uVar21 + 0x200, iVar25 + -2);
    }
    if (((uVar10 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      if (bVar2) {
        dVar26 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x506c))(param_1, uVar21, iVar25, 0);
      }
      if (cVar3 == '\0') {
        if ((bVar1) && (-1 < iVar25 + -3)) {
          iVar9 = iVar25 + -2;
          iVar14 = uVar21 + 0x200;
          do {
            (**(code **)(param_1 + 0x4de8))(param_1,iVar14,1);
            iVar9 = iVar9 + -1;
            iVar14 = iVar14 + 0x100;
          } while (iVar9 != 0);
        }
        (**(code **)(param_1 + 0x46cc))
                  (*(undefined4 *)(param_1 + 0x4688),uVar21,iVar25,
                   *(ushort *)(param_1 + 0x34d0) - 0x1b00);
      }
      else {
        piVar13 = *(int **)(param_1 + 0x4870);
        uVar15 = (uVar21 + iVar25 * 0x100) - 0x300;
        uVar10 = 0;
        do {
          iVar9 = 0;
          bVar2 = false;
          uVar11 = uVar10;
          uVar6 = uVar21;
          while (uVar10 = uVar11, uVar21 <= uVar15) {
            uVar22 = uVar21 + 0x100;
            iVar25 = ((undefined4 (*)())_gleCullTriangle)(param_1,uVar21,uVar22,uVar21 + 0x200,uVar11,&local_50,dVar26,
                                      in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff78,
                                      in_stack_ffffff80);
            dVar26 = extraout_f1_00;
            if (iVar25 == 0) {
              if (iVar14 != local_50) {
                bVar2 = true;
              }
              if ((bVar2) && (0 < iVar9)) break;
              if (iVar9 == 0) {
                uVar12 = uVar11;
              }
              iVar9 = iVar9 + 1;
              iVar14 = local_50;
              uVar16 = uVar6;
            }
            else {
              uVar16 = uVar22;
              uVar10 = uVar11 ^ 1;
              uVar21 = uVar22;
              if (0 < iVar9) break;
            }
            uVar11 = uVar11 ^ 1;
            uVar21 = uVar22;
            uVar6 = uVar16;
          }
          iVar25 = iVar9 + 2;
          if (2 < iVar25) {
            if (bVar1) {
              iVar8 = iVar14;
              if (!bVar5) {
                iVar8 = 0;
              }
              if (-1 < iVar9 + -1) {
                iVar19 = iVar9;
                iVar23 = uVar6 + 0x200;
                do {
                  (**(code **)(iVar8 * 4 + param_1 + 0x4de8))(param_1,iVar23,1);
                  iVar19 = iVar19 + -1;
                  iVar23 = iVar23 + 0x100;
                } while (iVar19 != 0);
              }
            }
            uVar11 = uVar6;
            if (uVar12 != 0) {
              uVar11 = uVar6 + 0x100;
              *piVar13 = uVar6 + 0x200;
              piVar13[2] = uVar6;
              piVar13[1] = uVar11;
              if (iVar14 != 0) {
                uVar4 = *(ushort *)(param_1 + 0x34d2);
              }
              else {
                uVar4 = *(ushort *)(param_1 + 0x34d0);
              }
              iVar25 = iVar9 + 1;
              dVar26 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46e0))
                                         (*(undefined4 *)(param_1 + 0x4688), piVar13, 3, uVar4 - 0x1b00);
              if (iVar25 < 3) goto LAB_000ef3cc;
            }
            if (iVar14 != 0) {
              uVar4 = *(ushort *)(param_1 + 0x34d2);
            }
            else {
              uVar4 = *(ushort *)(param_1 + 0x34d0);
            }
            dVar26 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46cc))
                                       (*(undefined4 *)(param_1 + 0x4688), uVar11, iVar25, uVar4 - 0x1b00);
          }
LAB_000ef3cc: ;
        } while (uVar21 <= uVar15);
      }
    }
    else {
      if (bVar2) {
        dVar26 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, uVar21, iVar25, 0);
      }
      uVar12 = (uVar21 + iVar25 * 0x100) - 0x300;
      puVar17 = *(uint **)(param_1 + 0x4874);
      puVar24 = *(uint **)(param_1 + 0x4870);
      if (uVar21 <= uVar12) {
        bVar2 = false;
        do {
          bVar2 = !bVar2;
          if (bVar2) {
            *puVar24 = uVar21;
            puVar24[1] = uVar21 + 0x100;
            puVar24[2] = uVar21 + 0x200;
          }
          else {
            puVar24[2] = uVar21;
            *puVar24 = uVar21 + 0x200;
            puVar24[1] = uVar21 + 0x100;
          }
          uVar15 = uVar21 + 0x100;
          *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x485c);
          puVar18 = puVar17;
          puVar7 = puVar24;
          iVar14 = 3;
          if ((*(char *)(param_1 + 0x4e18) == '\0') ||
             (dVar26 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar24,3,puVar17,local_4c,dVar26,in_f2,
                                                 in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                 in_stack_ffffff78,in_stack_ffffff80),
             puVar18 = puVar24, puVar7 = puVar17, iVar14 = local_4c[0], local_4c[0] != 0)) {
            puVar24 = puVar7;
            puVar17 = puVar18;
            if ((uVar10 & 0xff) != 0) {
              dVar26 = (double)_gleClipPoly(param_1,puVar24,iVar14,uVar10 & 0xff,puVar18,local_4c,1)
              ;
              if (local_4c[0] == 0) goto LAB_000ef59c;
              if (0 < local_4c[0]) {
                puVar17 = puVar24;
                puVar24 = puVar18;
                iVar14 = local_4c[0];
              }
            }
            if ((cVar3 == '\0') ||
               (iVar9 = ((int (*)())_gleCullPolygonPtrStack)(param_1,puVar24,iVar14,&local_50),
               dVar26 = extraout_f1_01, iVar9 == 0)) {
              if (bVar1) {
                iVar9 = 0x4de0;
                if (bVar5) {
                  iVar9 = local_50 * 4 + 0x4de0;
                }
                (**(code **)(param_1 + iVar9 + 8))(param_1,uVar21 + 0x200,1);
              }
              *(undefined8 *)(*puVar24 + 0x30) = *(undefined8 *)(uVar21 + 0x230);
              *(undefined8 *)(*puVar24 + 0x38) = *(undefined8 *)(uVar21 + 0x238);
              if (local_50 == 0) {
                uVar4 = *(ushort *)(param_1 + 0x34d0);
              }
              else {
                uVar4 = *(ushort *)(param_1 + 0x34d2);
              }
              dVar26 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46e0))
                                         (*(undefined4 *)(param_1 + 0x4688), puVar24, iVar14, uVar4 - 0x1b00);
            }
          }
LAB_000ef59c:
          uVar21 = uVar15;
        } while (uVar15 <= uVar12);
      }
    }
  }
  return;
}

/* FUN_000ef5f4 @ 0xef5f4 (1300 bytes) */
void FUN_000ef5f4(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  ushort uVar5;
  bool bVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  code *pcVar12;
  int iVar13;
  int *piVar14;
  uint uVar15;
  int iVar16;
  int *piVar17;
  int *piVar18;
  int iVar19;
  uint uVar20;
  double extraout_f1;
  double dVar21;
  double extraout_f1_00;
  double extraout_f1_01;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  int local_50;
  int local_4c [4];
  
  iVar13 = -1;
  iVar8 = _gleTexEnableBits(param_1);
  bVar3 = *(byte *)(param_1 + 0x30aa);
  bVar6 = false;
  if ((bVar3 != 0) && (*(char *)(param_1 + 0x30ac) != '\0')) {
    bVar6 = true;
  }
  iVar16 = *(int *)(param_1 + 0x4854);
  cVar4 = *(char *)(param_1 + 0x34de);
  iVar19 = *(int *)(param_1 + 0x4858) - iVar16 >> 8;
  if (iVar19 < 3) {
    return;
  }
  uVar9 = (**(code **)(param_1 + 0x5060))(param_1,iVar16,iVar19);
  if ((uVar9 & 0xff00) != 0) {
    return;
  }
  bVar1 = iVar8 != 0;
  dVar21 = extraout_f1;
  if ((bVar1) && (*(char *)(param_1 + 0x53e4) != '\0')) {
    dVar21 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53dc))(param_1, iVar16, iVar19);
  }
  if (*(char *)(param_1 + 0x50b4) != '\0') {
    dVar21 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, iVar16, iVar19);
  }
  bVar2 = (int)-(uint)bVar3 < 0;
  if (bVar2) {
LAB_000ef6ec:
    dVar21 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, iVar16, iVar19);
  }
  else {
    if (!bVar1) goto LAB_000ef72c;
    if (*(char *)(param_1 + 0x53e6) != '\0') goto LAB_000ef6ec;
  }
  if ((bVar1) && (*(char *)(param_1 + 0x53e5) != '\0')) {
    dVar21 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53e0))(param_1, iVar16, iVar19);
  }
LAB_000ef72c:
  if (((uVar9 & 0xff) != 0) || (*(char *)(param_1 + 0x4e18) != '\0')) {
    if (bVar1) {
      dVar21 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, iVar16, iVar19, 0);
    }
    bVar1 = false;
    uVar15 = iVar16 + 0x100;
    piVar18 = *(int **)(param_1 + 0x4870);
    piVar14 = *(int **)(param_1 + 0x4874);
joined_r0x000ef960:
    do {
      if ((iVar16 + iVar19 * 0x100) - 0x200U < uVar15) {
        return;
      }
      uVar20 = uVar15 + 0x100;
      *piVar18 = iVar16;
      piVar18[1] = uVar15;
      piVar18[2] = uVar20;
      *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x485c);
      piVar11 = piVar14;
      piVar17 = piVar18;
      iVar8 = 3;
      uVar15 = uVar20;
    } while ((*(char *)(param_1 + 0x4e18) != '\0') &&
            (dVar21 = (double)((double (*)())_gleClipPolyPlane)(param_1,piVar18,3,piVar14,local_4c,dVar21,in_f2,
                                                in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                in_stack_ffffff78,in_stack_ffffff80),
            piVar11 = piVar18, piVar17 = piVar14, iVar8 = local_4c[0], local_4c[0] == 0));
    piVar14 = piVar11;
    piVar18 = piVar17;
    if ((uVar9 & 0xff) != 0) goto code_r0x000ef9c8;
    goto LAB_000efa08;
  }
  if (bVar1) {
    dVar21 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x506c))(param_1, iVar16, iVar19, 0);
  }
  if (cVar4 == '\0') {
    if (bVar2) {
      (**(code **)(param_1 + 0x4de8))(param_1,iVar16,iVar19);
    }
    (**(code **)(param_1 + 0x46c8))
              (*(undefined4 *)(param_1 + 0x4688),iVar16,iVar16 + 0x100,iVar19 + -1,
               *(ushort *)(param_1 + 0x34d0) - 0x1b00);
  }
  else {
    uVar9 = iVar16 + 0x100;
    uVar15 = (iVar16 + iVar19 * 0x100) - 0x200;
    do {
      bVar1 = false;
      iVar8 = 0;
      uVar20 = uVar9;
      do {
        while( true ) {
          uVar7 = uVar20;
          if (uVar15 < uVar9) goto LAB_000ef844;
          uVar20 = uVar9 + 0x100;
          iVar19 = ((undefined4 (*)())_gleCullTriangle)(param_1,iVar16,uVar9,uVar20,0,&local_50,dVar21,in_f2,in_f3,in_f4
                                    ,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff78,in_stack_ffffff80);
          dVar21 = extraout_f1_00;
          if (iVar19 != 0) break;
          if (iVar13 != local_50) {
            bVar1 = true;
          }
          if ((bVar1) && (0 < iVar8)) goto LAB_000ef844;
          iVar8 = iVar8 + 1;
          iVar13 = local_50;
          uVar9 = uVar20;
          uVar20 = uVar7;
        }
        uVar9 = uVar20;
      } while (iVar8 < 1);
LAB_000ef844:
      iVar8 = iVar8 + 1;
      if (1 < iVar8) {
        if (bVar6) {
          if (bVar1) {
            *(byte *)(iVar16 + 0x7e) = *(byte *)(iVar16 + 0x7e) | 6;
            *(byte *)(uVar7 + 0x7e) = *(byte *)(uVar7 + 0x7e) | 6;
          }
          iVar19 = iVar13 * 4 + param_1;
          (**(code **)(iVar19 + 0x4de8))(param_1,iVar16,1);
          pcVar12 = *(code **)(iVar19 + 0x4de8);
LAB_000ef8d8:
          (*pcVar12)(param_1,uVar7,iVar8);
        }
        else if (bVar2) {
          (**(code **)(param_1 + 0x4de8))(param_1,iVar16,1);
          pcVar12 = *(code **)(param_1 + 0x4de8);
          goto LAB_000ef8d8;
        }
        if (iVar13 == 0) {
          uVar5 = *(ushort *)(param_1 + 0x34d0);
        }
        else {
          uVar5 = *(ushort *)(param_1 + 0x34d2);
        }
        dVar21 = (double)(**(double ( **)(int,int,int,int,int))(param_1 + 0x46c8))
                                   (*(undefined4 *)(param_1 + 0x4688), iVar16, uVar7, iVar8, uVar5 - 0x1b00);
      }
    } while (uVar9 <= uVar15);
  }
  return;
code_r0x000ef9c8:
  dVar21 = (double)_gleClipPoly(param_1,piVar17,iVar8,uVar9 & 0xff,piVar11,local_4c,1);
  if (local_4c[0] == 0) goto joined_r0x000ef960;
  if (0 < local_4c[0]) {
    piVar14 = piVar17;
    piVar18 = piVar11;
    iVar8 = local_4c[0];
  }
LAB_000efa08:
  if ((cVar4 != '\0') &&
     (iVar10 = ((int (*)())_gleCullPolygonPtrStack)(param_1,piVar18,iVar8,&local_50), dVar21 = extraout_f1_01,
     iVar10 != 0)) goto joined_r0x000ef960;
  iVar10 = local_50;
  if (iVar13 != local_50) {
    bVar1 = true;
  }
  if (bVar6) {
    if (bVar1) {
      piVar11 = piVar18;
      iVar13 = iVar8;
      if (0 < iVar8) {
        do {
          *(byte *)(*piVar11 + 0x7e) = *(byte *)(*piVar11 + 0x7e) | 6;
          iVar13 = iVar13 + -1;
          piVar11 = piVar11 + 1;
        } while (iVar13 != 0);
      }
      bVar1 = false;
    }
    pcVar12 = *(code **)(local_50 * 4 + param_1 + 0x4df0);
  }
  else {
    if (!bVar2) goto LAB_000efab0;
    pcVar12 = *(code **)(param_1 + 0x4df0);
  }
  (*pcVar12)(param_1,piVar18,iVar8);
LAB_000efab0:
  if (iVar10 == 0) {
    uVar5 = *(ushort *)(param_1 + 0x34d0);
  }
  else {
    uVar5 = *(ushort *)(param_1 + 0x34d2);
  }
  dVar21 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46e0))
                             (*(undefined4 *)(param_1 + 0x4688), piVar18, iVar8, uVar5 - 0x1b00);
  iVar13 = iVar10;
  goto joined_r0x000ef960;
}

/* FUN_000efb0c @ 0xefb0c (1244 bytes) */
void FUN_000efb0c(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  char cVar3;
  ushort uVar4;
  bool bVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  uint uVar15;
  int *piVar16;
  int iVar17;
  uint uVar18;
  char cVar19;
  double extraout_f1;
  double dVar20;
  double extraout_f1_00;
  double extraout_f1_01;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  int local_50;
  int local_4c [6];
  
  iVar10 = -1;
  iVar8 = _gleTexEnableBits(param_1);
  cVar19 = *(char *)(param_1 + 0x30aa);
  bVar5 = false;
  bVar1 = cVar19 != '\0';
  if ((bVar1) && (*(char *)(param_1 + 0x30ac) != '\0')) {
    bVar5 = true;
  }
  iVar14 = *(int *)(param_1 + 0x4854);
  cVar3 = *(char *)(param_1 + 0x34de);
  iVar17 = *(int *)(param_1 + 0x4858) - iVar14 >> 8;
  if ((2 < iVar17) &&
     (uVar9 = (**(code **)(param_1 + 0x5060))(param_1,iVar14,iVar17), (uVar9 & 0xff00) == 0)) {
    bVar2 = iVar8 != 0;
    dVar20 = extraout_f1;
    if ((bVar2) && (*(char *)(param_1 + 0x53e4) != '\0')) {
      dVar20 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53dc))(param_1, iVar14, iVar17);
    }
    if (*(char *)(param_1 + 0x50b4) != '\0') {
      dVar20 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, iVar14, iVar17);
    }
    if (bVar2) {
      if (*(char *)(param_1 + 0x53e6) != '\0') {
        cVar19 = '\0';
        dVar20 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, iVar14, iVar17);
      }
      if (*(char *)(param_1 + 0x53e5) != '\0') {
        dVar20 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53e0))(param_1, iVar14, iVar17);
      }
    }
    if (cVar19 != '\0') {
      dVar20 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, iVar14 + 0x200, iVar17 + -2);
    }
    if (((uVar9 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      if (bVar2) {
        dVar20 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x506c))(param_1, iVar14, iVar17, 0);
      }
      if (cVar3 == '\0') {
        if ((bVar1) && (iVar10 = iVar17 + -2, 0 < iVar10)) {
          iVar8 = iVar14 + 0x200;
          do {
            (**(code **)(param_1 + 0x4de8))(param_1,iVar8,1);
            iVar10 = iVar10 + -1;
            iVar8 = iVar8 + 0x100;
          } while (iVar10 != 0);
        }
        (**(code **)(param_1 + 0x46c8))
                  (*(undefined4 *)(param_1 + 0x4688),iVar14,iVar14 + 0x100,iVar17 + -1,
                   *(ushort *)(param_1 + 0x34d0) - 0x1b00);
      }
      else {
        uVar9 = iVar14 + 0x100;
        uVar11 = (iVar14 + iVar17 * 0x100) - 0x200;
        do {
          iVar8 = 0;
          bVar2 = false;
          uVar18 = uVar9;
          do {
            while( true ) {
              uVar15 = uVar18;
              if (uVar11 < uVar9) goto LAB_000efd88;
              uVar18 = uVar9 + 0x100;
              iVar17 = ((undefined4 (*)())_gleCullTriangle)(param_1,iVar14,uVar9,uVar18,0,&local_50,dVar20,in_f2,in_f3,
                                        in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff78,
                                        in_stack_ffffff80);
              dVar20 = extraout_f1_00;
              if (iVar17 != 0) break;
              if (iVar10 != local_50) {
                bVar2 = true;
              }
              if ((bVar2) && (0 < iVar8)) goto LAB_000efd88;
              iVar8 = iVar8 + 1;
              iVar10 = local_50;
              uVar9 = uVar18;
              uVar18 = uVar15;
            }
            uVar9 = uVar18;
          } while (iVar8 < 1);
LAB_000efd88:
          iVar17 = iVar8 + 1;
          if (1 < iVar17) {
            if (bVar1) {
              iVar7 = iVar10;
              if (!bVar5) {
                iVar7 = 0;
              }
              if (-1 < iVar8 + -1) {
                uVar18 = uVar15;
                do {
                  uVar18 = uVar18 + 0x100;
                  (**(code **)(iVar7 * 4 + param_1 + 0x4de8))(param_1,uVar18,1);
                  iVar8 = iVar8 + -1;
                } while (iVar8 != 0);
              }
            }
            if (iVar10 == 0) {
              uVar4 = *(ushort *)(param_1 + 0x34d0);
            }
            else {
              uVar4 = *(ushort *)(param_1 + 0x34d2);
            }
            dVar20 = (double)(**(double ( **)(int,int,int,int,int))(param_1 + 0x46c8))
                                       (*(undefined4 *)(param_1 + 0x4688), iVar14, uVar15, iVar17, uVar4 - 0x1b00);
          }
        } while (uVar9 <= uVar11);
      }
    }
    else {
      if (bVar2) {
        dVar20 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, iVar14, iVar17, 0);
      }
      piVar16 = *(int **)(param_1 + 0x4870);
      uVar11 = (iVar14 + iVar17 * 0x100) - 0x200;
      piVar12 = *(int **)(param_1 + 0x4874);
      if (iVar14 + 0x100U <= uVar11) {
        uVar18 = iVar14 + 0x100U;
        do {
          uVar15 = uVar18 + 0x100;
          *piVar16 = iVar14;
          piVar16[1] = uVar18;
          piVar16[2] = uVar15;
          *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x485c);
          piVar13 = piVar12;
          piVar6 = piVar16;
          iVar10 = 3;
          if ((*(char *)(param_1 + 0x4e18) == '\0') ||
             (dVar20 = (double)((double (*)())_gleClipPolyPlane)(param_1,piVar16,3,piVar12,local_4c,dVar20,in_f2,
                                                 in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                 in_stack_ffffff78,in_stack_ffffff80),
             piVar13 = piVar16, piVar6 = piVar12, iVar10 = local_4c[0], local_4c[0] != 0)) {
            piVar16 = piVar6;
            piVar12 = piVar13;
            if ((uVar9 & 0xff) != 0) {
              dVar20 = (double)_gleClipPoly(param_1,piVar16,iVar10,uVar9 & 0xff,piVar13,local_4c,1);
              if (local_4c[0] == 0) goto LAB_000effc0;
              if (0 < local_4c[0]) {
                piVar12 = piVar16;
                piVar16 = piVar13;
                iVar10 = local_4c[0];
              }
            }
            if ((cVar3 == '\0') ||
               (iVar8 = ((int (*)())_gleCullPolygonPtrStack)(param_1,piVar16,iVar10,&local_50),
               dVar20 = extraout_f1_01, iVar8 == 0)) {
              if (bVar1) {
                if (bVar5) {
                  iVar8 = local_50 * 4 + 0x4de0;
                }
                else {
                  iVar8 = 0x4de0;
                }
                (**(code **)(param_1 + iVar8 + 8))(param_1,uVar15,1);
              }
              *(undefined8 *)(*piVar16 + 0x30) = *(undefined8 *)(uVar18 + 0x130);
              *(undefined8 *)(*piVar16 + 0x38) = *(undefined8 *)(uVar18 + 0x138);
              if (local_50 == 0) {
                uVar4 = *(ushort *)(param_1 + 0x34d0);
              }
              else {
                uVar4 = *(ushort *)(param_1 + 0x34d2);
              }
              dVar20 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46e0))
                                         (*(undefined4 *)(param_1 + 0x4688), piVar16, iVar10, uVar4 - 0x1b00);
            }
          }
LAB_000effc0:
          uVar18 = uVar15;
        } while (uVar15 <= uVar11);
      }
    }
  }
  return;
}

/* FUN_000effec @ 0xeffec (1148 bytes) */
void FUN_000effec(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  ushort uVar5;
  bool bVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  code *pcVar10;
  int iVar11;
  uint *puVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  double extraout_f1;
  double dVar19;
  double extraout_f1_00;
  double extraout_f1_01;
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
  int local_40;
  int local_3c [3];
  
  iVar11 = -1;
  iVar8 = _gleTexEnableBits(param_1);
  bVar3 = *(byte *)(param_1 + 0x30aa);
  bVar6 = false;
  if ((bVar3 != 0) && (*(char *)(param_1 + 0x30ac) != '\0')) {
    bVar6 = true;
  }
  uVar17 = *(uint *)(param_1 + 0x4854);
  cVar4 = *(char *)(param_1 + 0x34de);
  iVar16 = (int)(*(int *)(param_1 + 0x4858) - uVar17) >> 8;
  if (iVar16 < 4) {
    return;
  }
  uVar9 = (**(code **)(param_1 + 0x5060))(param_1,uVar17,iVar16);
  if ((uVar9 & 0xff00) != 0) {
    return;
  }
  bVar1 = iVar8 != 0;
  dVar19 = extraout_f1;
  if ((bVar1) && (*(char *)(param_1 + 0x53e4) != '\0')) {
    dVar19 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53dc))(param_1, uVar17, iVar16);
  }
  if (*(char *)(param_1 + 0x50b4) != '\0') {
    dVar19 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, uVar17, iVar16);
  }
  bVar2 = (int)-(uint)bVar3 < 0;
  if (bVar2) {
LAB_000f00e4:
    dVar19 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, uVar17, iVar16);
  }
  else {
    if (!bVar1) goto LAB_000f0124;
    if (*(char *)(param_1 + 0x53e6) != '\0') goto LAB_000f00e4;
  }
  if ((bVar1) && (*(char *)(param_1 + 0x53e5) != '\0')) {
    dVar19 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53e0))(param_1, uVar17, iVar16);
  }
LAB_000f0124:
  if (((uVar9 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
    if (bVar1) {
      dVar19 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x506c))(param_1, uVar17, iVar16, 0);
    }
    if (cVar4 == '\0') {
      if (bVar2) {
        (**(code **)(param_1 + 0x4de8))(param_1,uVar17,iVar16);
      }
      (**(code **)(param_1 + 0x46d0))
                (*(undefined4 *)(param_1 + 0x4688),uVar17,iVar16,
                 *(ushort *)(param_1 + 0x34d0) - 0x1b00);
    }
    else {
      uVar9 = (uVar17 + iVar16 * 0x100) - 0x400;
      do {
        bVar1 = false;
        iVar8 = 0;
        uVar15 = uVar17;
        uVar18 = uVar17;
        if (uVar17 <= uVar9) {
          do {
            iVar16 = ((undefined4 (*)())_gleCullQuad)(param_1,uVar17,uVar17 + 0x100,uVar17 + 0x200,uVar17 + 0x300,
                                  &local_40,dVar19,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                  in_stack_ffffff88,in_stack_ffffff90,in_stack_ffffff98);
            dVar19 = dVar19;
            if (iVar16 == 0) {
              if (iVar11 != local_40) {
                bVar1 = true;
              }
              if ((bVar1) && (uVar18 = uVar17, 0 < iVar8)) break;
              iVar8 = iVar8 + 4;
              iVar11 = local_40;
              uVar18 = uVar15;
            }
            else {
              uVar18 = uVar17 + 0x400;
              if (0 < iVar8) break;
            }
            uVar17 = uVar17 + 0x400;
            uVar15 = uVar18;
            uVar18 = uVar17;
          } while (uVar17 <= uVar9);
          if (3 < iVar8) {
            if (bVar6) {
              pcVar10 = *(code **)(iVar11 * 4 + param_1 + 0x4de8);
LAB_000f0264:
              (*pcVar10)(param_1,uVar15,iVar8);
            }
            else if (bVar2) {
              pcVar10 = *(code **)(param_1 + 0x4de8);
              goto LAB_000f0264;
            }
            if (iVar11 == 0) {
              uVar5 = *(ushort *)(param_1 + 0x34d0);
            }
            else {
              uVar5 = *(ushort *)(param_1 + 0x34d2);
            }
            dVar19 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46d0))
                                       (*(undefined4 *)(param_1 + 0x4688), uVar15, iVar8, uVar5 - 0x1b00);
          }
        }
        uVar17 = uVar18;
      } while (uVar18 <= uVar9);
    }
  }
  else {
    if (bVar1) {
      dVar19 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, uVar17, iVar16, 0);
    }
    puVar14 = *(uint **)(param_1 + 0x4870);
    puVar12 = *(uint **)(param_1 + 0x4874);
    uVar18 = (uVar17 + iVar16 * 0x100) - 0x400;
    if (uVar17 <= uVar18) {
      do {
        puVar14[1] = uVar17 + 0x100;
        puVar14[2] = uVar17 + 0x200;
        puVar14[3] = uVar17 + 0x300;
        *puVar14 = uVar17;
        *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x485c);
        puVar13 = puVar12;
        puVar7 = puVar14;
        iVar11 = 4;
        if ((*(char *)(param_1 + 0x4e18) == '\0') ||
           (dVar19 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar14,4,puVar12,local_3c,dVar19,in_f2,in_f3
                                               ,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff88,
                                               in_stack_ffffff90), puVar13 = puVar14,
           puVar7 = puVar12, iVar11 = local_3c[0], local_3c[0] != 0)) {
          puVar14 = puVar7;
          puVar12 = puVar13;
          if ((uVar9 & 0xff) != 0) {
            dVar19 = (double)_gleClipPoly(param_1,puVar14,iVar11,uVar9 & 0xff,puVar13,local_3c,1);
            if (local_3c[0] == 0) goto LAB_000f0440;
            if (0 < local_3c[0]) {
              puVar12 = puVar14;
              puVar14 = puVar13;
              iVar11 = local_3c[0];
            }
          }
          if ((cVar4 == '\0') ||
             (iVar8 = ((int (*)())_gleCullPolygonPtrStack)(param_1,puVar14,iVar11,&local_40),
             dVar19 = extraout_f1_01, iVar8 == 0)) {
            iVar8 = local_40;
            if (bVar6) {
              pcVar10 = *(code **)(local_40 * 4 + param_1 + 0x4df0);
LAB_000f0404:
              (*pcVar10)(param_1,puVar14,iVar11);
            }
            else if (bVar2) {
              pcVar10 = *(code **)(param_1 + 0x4df0);
              goto LAB_000f0404;
            }
            if (iVar8 == 0) {
              uVar5 = *(ushort *)(param_1 + 0x34d0);
            }
            else {
              uVar5 = *(ushort *)(param_1 + 0x34d2);
            }
            dVar19 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46e0))
                                       (*(undefined4 *)(param_1 + 0x4688), puVar14, iVar11, uVar5 - 0x1b00);
          }
        }
LAB_000f0440:
        uVar17 = uVar17 + 0x400;
      } while (uVar17 <= uVar18);
    }
  }
  return;
}

/* FUN_000f046c @ 0xf046c (1320 bytes) */
void FUN_000f046c(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  char cVar3;
  ushort uVar4;
  bool bVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  uint *puVar12;
  int iVar13;
  char cVar14;
  uint uVar15;
  uint *puVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  double extraout_f1;
  double dVar20;
  double extraout_f1_00;
  double extraout_f1_01;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  double in_stack_ffffff88;
  int local_50;
  int local_4c [6];
  
  iVar10 = -1;
  iVar7 = _gleTexEnableBits(param_1);
  cVar14 = *(char *)(param_1 + 0x30aa);
  bVar5 = false;
  bVar1 = cVar14 != '\0';
  if ((bVar1) && (*(char *)(param_1 + 0x30ac) != '\0')) {
    bVar5 = true;
  }
  uVar18 = *(uint *)(param_1 + 0x4854);
  cVar3 = *(char *)(param_1 + 0x34de);
  iVar17 = (int)(*(int *)(param_1 + 0x4858) - uVar18) >> 8;
  if ((3 < iVar17) &&
     (uVar8 = (**(code **)(param_1 + 0x5060))(param_1,uVar18,iVar17), (uVar8 & 0xff00) == 0)) {
    bVar2 = iVar7 != 0;
    dVar20 = extraout_f1;
    if ((bVar2) && (*(char *)(param_1 + 0x53e4) != '\0')) {
      dVar20 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53dc))(param_1, uVar18, iVar17);
    }
    if (*(char *)(param_1 + 0x50b4) != '\0') {
      dVar20 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, uVar18, iVar17);
    }
    if (bVar2) {
      if (*(char *)(param_1 + 0x53e6) != '\0') {
        cVar14 = '\0';
        dVar20 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, uVar18, iVar17);
      }
      if (*(char *)(param_1 + 0x53e5) != '\0') {
        dVar20 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53e0))(param_1, uVar18, iVar17);
      }
    }
    if (((uVar8 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      if (bVar2) {
        dVar20 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x506c))(param_1, uVar18, iVar17, 0);
      }
      if (cVar3 == '\0') {
        if (bVar1) {
          iVar10 = 0;
          if (-1 < iVar17 + -4) {
            iVar7 = uVar18 + 0x300;
            do {
              if (cVar14 != '\0') {
                (**(code **)(param_1 + 0x5068))(param_1,iVar7,1);
              }
              iVar10 = iVar10 + 4;
              (**(code **)(param_1 + 0x4de8))(param_1,iVar7,1);
              iVar7 = iVar7 + 0x400;
            } while (iVar10 <= iVar17 + -4);
          }
        }
        (**(code **)(param_1 + 0x46d0))
                  (*(undefined4 *)(param_1 + 0x4688),uVar18,iVar17,
                   *(ushort *)(param_1 + 0x34d0) - 0x1b00);
      }
      else {
        uVar8 = (uVar18 + iVar17 * 0x100) - 0x400;
        do {
          iVar7 = 0;
          bVar2 = false;
          uVar15 = uVar18;
          uVar19 = uVar18;
          if (uVar18 <= uVar8) {
            do {
              iVar17 = ((undefined4 (*)())_gleCullQuad)(param_1,uVar18,uVar18 + 0x100,uVar18 + 0x200,uVar18 + 0x300,
                                    &local_50,dVar20,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                    in_stack_ffffff78,in_stack_ffffff80,in_stack_ffffff88);
              dVar20 = dVar20;
              if (iVar17 == 0) {
                if (iVar10 != local_50) {
                  bVar2 = true;
                }
                if ((bVar2) && (uVar19 = uVar18, 0 < iVar7)) break;
                iVar7 = iVar7 + 4;
                iVar10 = local_50;
                uVar19 = uVar15;
              }
              else {
                uVar19 = uVar18 + 0x400;
                if (0 < iVar7) break;
              }
              uVar18 = uVar18 + 0x400;
              uVar15 = uVar19;
              uVar19 = uVar18;
            } while (uVar18 <= uVar8);
            if (3 < iVar7) {
              if (bVar1) {
                iVar17 = iVar10;
                if (!bVar5) {
                  iVar17 = 0;
                }
                iVar13 = 0;
                if (-1 < iVar7 + -4) {
                  iVar9 = uVar15 + 0x300;
                  do {
                    if (cVar14 != '\0') {
                      (**(code **)(param_1 + 0x5068))(param_1,iVar9,1);
                    }
                    iVar13 = iVar13 + 4;
                    (**(code **)(iVar17 * 4 + param_1 + 0x4de8))(param_1,iVar9,1);
                    iVar9 = iVar9 + 0x400;
                  } while (iVar13 <= iVar7 + -4);
                }
              }
              if (iVar10 == 0) {
                uVar4 = *(ushort *)(param_1 + 0x34d0);
              }
              else {
                uVar4 = *(ushort *)(param_1 + 0x34d2);
              }
              dVar20 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46d0))
                                         (*(undefined4 *)(param_1 + 0x4688), uVar15, iVar7, uVar4 - 0x1b00);
            }
          }
          uVar18 = uVar19;
        } while (uVar19 <= uVar8);
      }
    }
    else {
      if (bVar2) {
        dVar20 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, uVar18, iVar17, 0);
      }
      puVar16 = *(uint **)(param_1 + 0x4870);
      iVar10 = uVar18 + iVar17 * 0x100;
      puVar11 = *(uint **)(param_1 + 0x4874);
      for (; uVar18 <= iVar10 - 0x400U; uVar18 = uVar18 + 0x400) {
        uVar19 = uVar18 + 0x300;
        puVar16[1] = uVar18 + 0x100;
        puVar16[2] = uVar18 + 0x200;
        *puVar16 = uVar18;
        puVar16[3] = uVar19;
        *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x485c);
        puVar12 = puVar11;
        puVar6 = puVar16;
        iVar7 = 4;
        if ((*(char *)(param_1 + 0x4e18) == '\0') ||
           (dVar20 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar16,4,puVar11,local_4c,dVar20,in_f2,in_f3
                                               ,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff78,
                                               in_stack_ffffff80), puVar12 = puVar16,
           puVar6 = puVar11, iVar7 = local_4c[0], local_4c[0] != 0)) {
          puVar16 = puVar6;
          puVar11 = puVar12;
          if ((uVar8 & 0xff) != 0) {
            dVar20 = (double)_gleClipPoly(param_1,puVar16,iVar7,uVar8 & 0xff,puVar12,local_4c,1);
            if (local_4c[0] == 0) goto LAB_000f096c;
            if (0 < local_4c[0]) {
              puVar11 = puVar16;
              puVar16 = puVar12;
              iVar7 = local_4c[0];
            }
          }
          if ((cVar3 == '\0') ||
             (iVar17 = ((int (*)())_gleCullPolygonPtrStack)(param_1,puVar16,iVar7,&local_50),
             dVar20 = extraout_f1_01, iVar17 == 0)) {
            if (cVar14 != '\0') {
              (**(code **)(param_1 + 0x5068))(param_1,uVar19,1);
            }
            if (bVar1) {
              iVar17 = 0x4de0;
              if (bVar5) {
                iVar17 = local_50 * 4 + 0x4de0;
              }
              (**(code **)(param_1 + iVar17 + 8))(param_1,uVar19,1);
            }
            *(undefined8 *)(*puVar16 + 0x30) = *(undefined8 *)(uVar18 + 0x330);
            *(undefined8 *)(*puVar16 + 0x38) = *(undefined8 *)(uVar18 + 0x338);
            if (local_50 == 0) {
              uVar4 = *(ushort *)(param_1 + 0x34d0);
            }
            else {
              uVar4 = *(ushort *)(param_1 + 0x34d2);
            }
            dVar20 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46e0))
                                       (*(undefined4 *)(param_1 + 0x4688), puVar16, iVar7, uVar4 - 0x1b00);
          }
        }
LAB_000f096c: ;
      }
    }
  }
  return;
}

/* FUN_000f09c0 @ 0xf09c0 (1256 bytes) */
void FUN_000f09c0(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  ushort uVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  code *pcVar11;
  int iVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  uint *puVar18;
  int iVar19;
  double extraout_f1;
  double dVar20;
  double extraout_f1_00;
  double extraout_f1_01;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  double in_stack_ffffff88;
  int local_50;
  int local_4c [5];
  
  iVar12 = -1;
  iVar7 = _gleTexEnableBits(param_1);
  bVar3 = *(byte *)(param_1 + 0x30aa);
  bVar6 = false;
  if ((bVar3 != 0) && (*(char *)(param_1 + 0x30ac) != '\0')) {
    bVar6 = true;
  }
  uVar15 = *(uint *)(param_1 + 0x4854);
  cVar4 = *(char *)(param_1 + 0x34de);
  iVar19 = (int)(*(int *)(param_1 + 0x4858) - uVar15) >> 8;
  if (iVar19 < 4) {
    return;
  }
  uVar8 = (**(code **)(param_1 + 0x5060))(param_1,uVar15,iVar19);
  if ((uVar8 & 0xff00) != 0) {
    return;
  }
  bVar1 = iVar7 != 0;
  dVar20 = extraout_f1;
  if ((bVar1) && (*(char *)(param_1 + 0x53e4) != '\0')) {
    dVar20 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53dc))(param_1, uVar15, iVar19);
  }
  if (*(char *)(param_1 + 0x50b4) != '\0') {
    dVar20 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, uVar15, iVar19);
  }
  bVar2 = (int)-(uint)bVar3 < 0;
  if (bVar2) {
LAB_000f0ab8:
    dVar20 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, uVar15, iVar19);
  }
  else {
    if (!bVar1) goto LAB_000f0af8;
    if (*(char *)(param_1 + 0x53e6) != '\0') goto LAB_000f0ab8;
  }
  if ((bVar1) && (*(char *)(param_1 + 0x53e5) != '\0')) {
    dVar20 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53e0))(param_1, uVar15, iVar19);
  }
LAB_000f0af8:
  if (((uVar8 & 0xff) != 0) || (*(char *)(param_1 + 0x4e18) != '\0')) {
    if (bVar1) {
      dVar20 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, uVar15, iVar19, 0);
    }
    bVar1 = false;
    uVar16 = uVar15;
    puVar13 = *(uint **)(param_1 + 0x4874);
    puVar18 = *(uint **)(param_1 + 0x4870);
joined_r0x000f0cf4:
    do {
      if ((uVar15 + iVar19 * 0x100) - 0x400 < uVar16) {
        return;
      }
      uVar14 = uVar16 + 0x200;
      *puVar18 = uVar16;
      puVar18[1] = uVar16 + 0x100;
      puVar18[2] = uVar16 + 0x300;
      puVar18[3] = uVar14;
      *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x485c);
      puVar10 = puVar13;
      puVar17 = puVar18;
      iVar7 = 4;
      uVar16 = uVar14;
    } while ((*(char *)(param_1 + 0x4e18) != '\0') &&
            (dVar20 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar18,4,puVar13,local_4c,dVar20,in_f2,
                                                in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                in_stack_ffffff78,in_stack_ffffff80),
            puVar10 = puVar18, puVar17 = puVar13, iVar7 = local_4c[0], local_4c[0] == 0));
    puVar13 = puVar10;
    puVar18 = puVar17;
    if ((uVar8 & 0xff) != 0) goto code_r0x000f0d68;
    goto LAB_000f0da8;
  }
  if (bVar1) {
    dVar20 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x506c))(param_1, uVar15, iVar19, 0);
  }
  if (cVar4 == '\0') {
    if (bVar2) {
      (**(code **)(param_1 + 0x4de8))(param_1,uVar15,iVar19);
    }
    (**(code **)(param_1 + 0x46d4))
              (*(undefined4 *)(param_1 + 0x4688),uVar15,iVar19,
               *(ushort *)(param_1 + 0x34d0) - 0x1b00);
  }
  else {
    uVar8 = (uVar15 + iVar19 * 0x100) - 0x400;
    do {
      bVar1 = false;
      iVar7 = 0;
      uVar16 = uVar15;
      do {
        while( true ) {
          uVar14 = uVar16;
          if (uVar8 < uVar15) goto LAB_000f0c0c;
          uVar16 = uVar15 + 0x200;
          iVar19 = ((undefined4 (*)())_gleCullQuad)(param_1,uVar15,uVar15 + 0x100,uVar15 + 0x300,uVar16,&local_50,dVar20
                                ,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff78,
                                in_stack_ffffff80,in_stack_ffffff88);
          dVar20 = extraout_f1_00;
          if (iVar19 != 0) break;
          if (iVar12 != local_50) {
            bVar1 = true;
          }
          if ((bVar1) && (0 < iVar7)) goto LAB_000f0c0c;
          iVar7 = iVar7 + 2;
          iVar12 = local_50;
          uVar15 = uVar16;
          uVar16 = uVar14;
        }
        uVar15 = uVar16;
      } while (iVar7 < 1);
LAB_000f0c0c:
      iVar7 = iVar7 + 2;
      if (3 < iVar7) {
        if (bVar6) {
          if (bVar1) {
            uVar16 = uVar14;
            do {
              *(byte *)(uVar16 + 0x7e) = *(byte *)(uVar16 + 0x7e) | 6;
              uVar16 = uVar16 + 0x100;
            } while ((int)uVar16 <= (int)(uVar14 + 0x100));
          }
          pcVar11 = *(code **)(iVar12 * 4 + param_1 + 0x4de8);
LAB_000f0c6c:
          (*pcVar11)(param_1,uVar14,iVar7);
        }
        else if (bVar2) {
          pcVar11 = *(code **)(param_1 + 0x4de8);
          goto LAB_000f0c6c;
        }
        if (iVar12 == 0) {
          uVar5 = *(ushort *)(param_1 + 0x34d0);
        }
        else {
          uVar5 = *(ushort *)(param_1 + 0x34d2);
        }
        dVar20 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46d4))
                                   (*(undefined4 *)(param_1 + 0x4688), uVar14, iVar7, uVar5 - 0x1b00);
      }
    } while (uVar15 <= uVar8);
  }
  return;
code_r0x000f0d68:
  dVar20 = (double)_gleClipPoly(param_1,puVar17,iVar7,uVar8 & 0xff,puVar10,local_4c,1);
  if (local_4c[0] == 0) goto joined_r0x000f0cf4;
  if (0 < local_4c[0]) {
    puVar13 = puVar17;
    puVar18 = puVar10;
    iVar7 = local_4c[0];
  }
LAB_000f0da8:
  if ((cVar4 != '\0') &&
     (iVar9 = ((int (*)())_gleCullPolygonPtrStack)(param_1,puVar18,iVar7,&local_50), dVar20 = extraout_f1_01,
     iVar9 != 0)) goto joined_r0x000f0cf4;
  iVar9 = local_50;
  if (iVar12 != local_50) {
    bVar1 = true;
  }
  if (bVar6) {
    if (bVar1) {
      puVar10 = puVar18;
      iVar12 = iVar7;
      if (0 < iVar7) {
        do {
          *(byte *)(*puVar10 + 0x7e) = *(byte *)(*puVar10 + 0x7e) | 6;
          iVar12 = iVar12 + -1;
          puVar10 = puVar10 + 1;
        } while (iVar12 != 0);
      }
      bVar1 = false;
    }
    pcVar11 = *(code **)(local_50 * 4 + param_1 + 0x4df0);
  }
  else {
    if (!bVar2) goto LAB_000f0e50;
    pcVar11 = *(code **)(param_1 + 0x4df0);
  }
  (*pcVar11)(param_1,puVar18,iVar7);
LAB_000f0e50:
  if (iVar9 == 0) {
    uVar5 = *(ushort *)(param_1 + 0x34d0);
  }
  else {
    uVar5 = *(ushort *)(param_1 + 0x34d2);
  }
  dVar20 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46e0))
                             (*(undefined4 *)(param_1 + 0x4688), puVar18, iVar7, uVar5 - 0x1b00);
  iVar12 = iVar9;
  goto joined_r0x000f0cf4;
}

/* FUN_000f0eac @ 0xf0eac (1336 bytes) */
void FUN_000f0eac(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  char cVar3;
  ushort uVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  uint *puVar12;
  char cVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint *puVar18;
  uint *puVar19;
  int iVar20;
  double extraout_f1;
  double dVar21;
  double extraout_f1_00;
  double extraout_f1_01;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  double in_stack_ffffff88;
  int local_50;
  int local_4c [5];
  
  iVar10 = -1;
  iVar7 = _gleTexEnableBits(param_1);
  cVar13 = *(char *)(param_1 + 0x30aa);
  bVar5 = false;
  bVar1 = cVar13 != '\0';
  if ((bVar1) && (*(char *)(param_1 + 0x30ac) != '\0')) {
    bVar5 = true;
  }
  uVar16 = *(uint *)(param_1 + 0x4854);
  cVar3 = *(char *)(param_1 + 0x34de);
  iVar20 = (int)(*(int *)(param_1 + 0x4858) - uVar16) >> 8;
  if ((3 < iVar20) &&
     (uVar8 = (**(code **)(param_1 + 0x5060))(param_1,uVar16,iVar20), (uVar8 & 0xff00) == 0)) {
    bVar2 = iVar7 != 0;
    dVar21 = extraout_f1;
    if ((bVar2) && (*(char *)(param_1 + 0x53e4) != '\0')) {
      dVar21 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53dc))(param_1, uVar16, iVar20);
    }
    if (*(char *)(param_1 + 0x50b4) != '\0') {
      dVar21 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, uVar16, iVar20);
    }
    if (bVar2) {
      if (*(char *)(param_1 + 0x53e6) != '\0') {
        cVar13 = '\0';
        dVar21 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, uVar16, iVar20);
      }
      if (*(char *)(param_1 + 0x53e5) != '\0') {
        dVar21 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53e0))(param_1, uVar16, iVar20);
      }
    }
    if (((uVar8 & 0xff) != 0) || (*(char *)(param_1 + 0x4e18) != '\0')) {
      if (bVar2) {
        dVar21 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, uVar16, iVar20, 0);
      }
      uVar17 = uVar16;
      puVar12 = *(uint **)(param_1 + 0x4874);
      puVar19 = *(uint **)(param_1 + 0x4870);
joined_r0x000f1240:
      do {
        uVar6 = uVar17;
        if ((uVar16 + iVar20 * 0x100) - 0x400 < uVar6) {
          return;
        }
        uVar17 = uVar6 + 0x200;
        uVar15 = uVar6 + 0x300;
        *puVar19 = uVar6;
        puVar19[1] = uVar6 + 0x100;
        puVar19[2] = uVar15;
        puVar19[3] = uVar17;
        *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x485c);
        puVar11 = puVar12;
        puVar18 = puVar19;
        iVar10 = 4;
      } while ((*(char *)(param_1 + 0x4e18) != '\0') &&
              (dVar21 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar19,4,puVar12,local_4c,dVar21,in_f2,
                                                  in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                  in_stack_ffffff78,in_stack_ffffff80),
              puVar11 = puVar19, puVar18 = puVar12, iVar10 = local_4c[0], local_4c[0] == 0));
      puVar12 = puVar11;
      puVar19 = puVar18;
      if ((uVar8 & 0xff) != 0) goto code_r0x000f12b4;
      goto LAB_000f12f4;
    }
    if (bVar2) {
      dVar21 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x506c))(param_1, uVar16, iVar20, 0);
    }
    if (cVar3 == '\0') {
      if (bVar1) {
        iVar10 = 0;
        if (-1 < iVar20 + -4) {
          iVar7 = uVar16 + 0x300;
          do {
            if (cVar13 != '\0') {
              (**(code **)(param_1 + 0x5068))(param_1,iVar7,1);
            }
            iVar10 = iVar10 + 2;
            (**(code **)(param_1 + 0x4de8))(param_1,iVar7,1);
            iVar7 = iVar7 + 0x200;
          } while (iVar10 <= iVar20 + -4);
        }
      }
      (**(code **)(param_1 + 0x46d4))
                (*(undefined4 *)(param_1 + 0x4688),uVar16,iVar20,
                 *(ushort *)(param_1 + 0x34d0) - 0x1b00);
    }
    else {
      uVar8 = (uVar16 + iVar20 * 0x100) - 0x400;
      do {
        iVar7 = 0;
        bVar2 = false;
        uVar17 = uVar16;
        do {
          while( true ) {
            uVar6 = uVar17;
            if (uVar8 < uVar16) goto LAB_000f1138;
            uVar17 = uVar16 + 0x200;
            iVar20 = ((undefined4 (*)())_gleCullQuad)(param_1,uVar16,uVar16 + 0x100,uVar16 + 0x300,uVar17,&local_50,
                                  dVar21,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff78
                                  ,in_stack_ffffff80,in_stack_ffffff88);
            dVar21 = extraout_f1_00;
            if (iVar20 != 0) break;
            if (iVar10 != local_50) {
              bVar2 = true;
            }
            if ((bVar2) && (0 < iVar7)) goto LAB_000f1138;
            iVar7 = iVar7 + 2;
            iVar10 = local_50;
            uVar16 = uVar17;
            uVar17 = uVar6;
          }
          uVar16 = uVar17;
        } while (iVar7 < 1);
LAB_000f1138:
        if (3 < iVar7 + 2) {
          if (bVar1) {
            iVar20 = iVar10;
            if (!bVar5) {
              iVar20 = 0;
            }
            iVar14 = 0;
            if (-1 < iVar7 + -2) {
              iVar9 = uVar6 + 0x300;
              do {
                if (cVar13 != '\0') {
                  (**(code **)(param_1 + 0x5068))(param_1,iVar9,1);
                }
                iVar14 = iVar14 + 2;
                (**(code **)(iVar20 * 4 + param_1 + 0x4de8))(param_1,iVar9,1);
                iVar9 = iVar9 + 0x200;
              } while (iVar14 <= iVar7 + -2);
            }
          }
          if (iVar10 == 0) {
            uVar4 = *(ushort *)(param_1 + 0x34d0);
          }
          else {
            uVar4 = *(ushort *)(param_1 + 0x34d2);
          }
          dVar21 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46d4))
                                     (*(undefined4 *)(param_1 + 0x4688), uVar6, iVar7 + 2, uVar4 - 0x1b00);
        }
      } while (uVar16 <= uVar8);
    }
  }
  return;
code_r0x000f12b4:
  dVar21 = (double)_gleClipPoly(param_1,puVar18,iVar10,uVar8 & 0xff,puVar11,local_4c,1);
  if (local_4c[0] != 0) {
    if (0 < local_4c[0]) {
      puVar12 = puVar18;
      puVar19 = puVar11;
      iVar10 = local_4c[0];
    }
LAB_000f12f4:
    if ((cVar3 == '\0') ||
       (iVar7 = ((int (*)())_gleCullPolygonPtrStack)(param_1,puVar19,iVar10,&local_50), dVar21 = extraout_f1_01,
       iVar7 == 0)) {
      if (cVar13 != '\0') {
        (**(code **)(param_1 + 0x5068))(param_1,uVar15,1);
      }
      if (bVar1) {
        iVar7 = 0x4de0;
        if (bVar5) {
          iVar7 = local_50 * 4 + 0x4de0;
        }
        (**(code **)(param_1 + iVar7 + 8))(param_1,uVar15,1);
      }
      *(undefined8 *)(*puVar19 + 0x30) = *(undefined8 *)(uVar6 + 0x330);
      *(undefined8 *)(*puVar19 + 0x38) = *(undefined8 *)(uVar6 + 0x338);
      if (local_50 == 0) {
        uVar4 = *(ushort *)(param_1 + 0x34d0);
      }
      else {
        uVar4 = *(ushort *)(param_1 + 0x34d2);
      }
      dVar21 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x46e0))
                                 (*(undefined4 *)(param_1 + 0x4688), puVar19, iVar10, uVar4 - 0x1b00);
    }
  }
  goto joined_r0x000f1240;
}

/* FUN_000f13e8 @ 0xf13e8 (664 bytes) */
void FUN_000f13e8(param_1)
  int param_1;
{
  char cVar1;
  bool bVar2;
  bool bVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  double extraout_f1;
  double dVar13;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff88;
  double in_stack_ffffff90;
  uint local_40;
  undefined4 local_3c [5];
  
  bVar2 = false;
  local_3c[0] = 0;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar2 = true;
  }
  bVar3 = false;
  if ((bVar2) && (*(char *)(param_1 + 0x4666) != '\0')) {
    bVar3 = true;
  }
  cVar1 = *(char *)(param_1 + 0x34da);
  iVar11 = *(int *)(param_1 + 0x4854);
  if ((((int)*(short *)(param_1 + 0x487c) != 0) &&
      (uVar10 = (uint)(*(int *)(param_1 + 0x4858) - iVar11) /
                (uint)(int)*(short *)(param_1 + 0x487c), 2 < (int)uVar10)) &&
     (uVar5 = (**(code **)(param_1 + 0x5060))(param_1,iVar11,uVar10), (uVar5 & 0xff00) == 0)) {
    dVar13 = extraout_f1;
    if (bVar2) {
      iVar11 = *(int *)(param_1 + 0x4864);
    }
    else if (*(char *)(param_1 + 0x4e18) != '\0') {
      dVar13 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, iVar11, uVar10);
    }
    if (((uVar5 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      if ((cVar1 == '\0') ||
         (iVar6 = ((int (*)())_gleCullPolygonStack)(param_1,iVar11,uVar10,0,local_3c), iVar6 == 0)) {
        if ((bVar2) && (bVar3)) {
          _gleVPFlipColors(param_1,iVar11,uVar10,local_3c[0]);
        }
        _gleSelectPolygon(param_1,iVar11,uVar10);
      }
    }
    else {
      piVar9 = *(int **)(param_1 + 0x4870);
      piVar8 = *(int **)(param_1 + 0x4874);
      piVar4 = piVar9;
      uVar12 = uVar10;
      if (0 < (int)uVar10) {
        do {
          *piVar4 = iVar11;
          iVar11 = iVar11 + 0x100;
          uVar12 = uVar12 - 1;
          piVar4 = piVar4 + 1;
        } while (uVar12 != 0);
      }
      if (bVar2) {
        *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
      }
      uVar7 = 0;
      piVar4 = piVar8;
      if (*(char *)(param_1 + 0x4e18) != '\0') {
        ((double (*)())_gleClipPolyPlane)(param_1,piVar9,uVar10,piVar8,&local_40,dVar13,in_f2,in_f3,in_f4,in_f5,
                          in_f6,in_f7,in_f8,in_stack_ffffff88,in_stack_ffffff90);
        if (local_40 == 0) {
          return;
        }
        uVar7 = 1;
        piVar4 = piVar9;
        piVar9 = piVar8;
        uVar10 = local_40;
      }
      if ((uVar5 & 0xff) != 0) {
        _gleClipPoly(param_1,piVar9,uVar10,uVar5 & 0xff,piVar4,&local_40,uVar7);
        if (local_40 == 0) {
          return;
        }
        if (0 < (int)local_40) {
          piVar9 = piVar4;
          uVar10 = local_40;
        }
      }
      if ((cVar1 == '\0') ||
         (iVar11 = ((int (*)())_gleCullPolygonPtrStack)(param_1,piVar9,uVar10,local_3c), iVar11 == 0)) {
        if ((bVar2) && ((bVar3 && (piVar4 = piVar9, uVar5 = uVar10, 0 < (int)uVar10)))) {
          do {
            iVar11 = *piVar4;
            piVar4 = piVar4 + 1;
            _gleVPFlipColors(param_1,iVar11,1,local_3c[0]);
            uVar5 = uVar5 - 1;
          } while (uVar5 != 0);
        }
        _gleSelectPolygonPtr(param_1,piVar9,uVar10);
      }
    }
  }
  return;
}

/* FUN_000f1684 @ 0xf1684 (848 bytes) */
void FUN_000f1684(param_1)
  int param_1;
{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint *puVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  double extraout_f1;
  double dVar18;
  double extraout_f1_00;
  double extraout_f1_01;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  int local_50;
  int local_4c [6];
  
  iVar9 = -1;
  bVar2 = false;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar2 = true;
  }
  bVar2 = !bVar2;
  bVar4 = false;
  if ((!bVar2) && (*(char *)(param_1 + 0x4666) != '\0')) {
    bVar4 = true;
  }
  cVar1 = *(char *)(param_1 + 0x34da);
  uVar16 = *(uint *)(param_1 + 0x4854);
  if ((((int)*(short *)(param_1 + 0x487c) != 0) &&
      (uVar13 = (*(int *)(param_1 + 0x4858) - uVar16) / (uint)(int)*(short *)(param_1 + 0x487c),
      2 < (int)uVar13)) &&
     (uVar7 = (**(code **)(param_1 + 0x5060))(param_1,uVar16,uVar13), (uVar7 & 0xff00) == 0)) {
    dVar18 = extraout_f1;
    if (bVar2) {
      if (*(char *)(param_1 + 0x4e18) != '\0') {
        dVar18 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, uVar16, uVar13);
      }
    }
    else {
      uVar16 = *(uint *)(param_1 + 0x4864);
    }
    if (((uVar7 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      if (cVar1 == '\0') {
        _gleSelectTriangles(param_1,uVar16,uVar13);
      }
      else {
        uVar13 = (uVar16 + uVar13 * 0x100) - 0x300;
        do {
          bVar3 = false;
          iVar17 = 0;
          uVar7 = uVar16;
          uVar15 = uVar16;
          if (uVar16 <= uVar13) {
            do {
              iVar8 = ((undefined4 (*)())_gleCullTriangle)(param_1,uVar16,uVar16 + 0x100,uVar16 + 0x200,0,&local_50,
                                       dVar18,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                       in_stack_ffffff78,in_stack_ffffff80);
              dVar18 = dVar18;
              if (iVar8 == 0) {
                if (iVar9 != local_50) {
                  bVar3 = true;
                }
                if ((bVar3) && (uVar7 = uVar16, 0 < iVar17)) break;
                iVar17 = iVar17 + 3;
                iVar9 = local_50;
                uVar14 = uVar15;
              }
              else {
                uVar14 = uVar16 + 0x300;
                uVar7 = uVar14;
                if (0 < iVar17) break;
              }
              uVar16 = uVar16 + 0x300;
              uVar7 = uVar16;
              uVar15 = uVar14;
            } while (uVar16 <= uVar13);
            if (2 < iVar17) {
              if ((!bVar2) && (bVar4)) {
                _gleVPFlipColors(param_1,uVar15,iVar17,iVar9);
              }
              dVar18 = (double)_gleSelectTriangles(param_1,uVar15,iVar17);
            }
          }
          uVar16 = uVar7;
        } while (uVar7 <= uVar13);
      }
    }
    else {
      puVar12 = *(uint **)(param_1 + 0x4870);
      uVar13 = (uVar16 + uVar13 * 0x100) - 0x300;
      puVar10 = *(uint **)(param_1 + 0x4874);
      if (uVar16 <= uVar13) {
        do {
          puVar12[1] = uVar16 + 0x100;
          puVar12[2] = uVar16 + 0x200;
          *puVar12 = uVar16;
          if (bVar2) {
            uVar6 = *(undefined4 *)(param_1 + 0x485c);
          }
          else {
            uVar6 = *(undefined4 *)(param_1 + 0x4854);
          }
          *(undefined4 *)(param_1 + 0x4858) = uVar6;
          puVar11 = puVar10;
          puVar5 = puVar12;
          iVar9 = 3;
          if ((*(char *)(param_1 + 0x4e18) == '\0') ||
             (dVar18 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar12,3,puVar10,local_4c,dVar18,in_f2,
                                                 in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                 in_stack_ffffff78,in_stack_ffffff80),
             puVar11 = puVar12, puVar5 = puVar10, iVar9 = local_4c[0], local_4c[0] != 0)) {
            puVar12 = puVar5;
            puVar10 = puVar11;
            if ((uVar7 & 0xff) != 0) {
              dVar18 = (double)_gleClipPoly(param_1,puVar12,iVar9,uVar7 & 0xff,puVar11,local_4c,1);
              if (local_4c[0] == 0) goto LAB_000f19ac;
              if (0 < local_4c[0]) {
                puVar10 = puVar12;
                puVar12 = puVar11;
                iVar9 = local_4c[0];
              }
            }
            if ((cVar1 == '\0') ||
               (iVar17 = ((int (*)())_gleCullPolygonPtrStack)(param_1,puVar12,iVar9,&local_50),
               dVar18 = extraout_f1_01, iVar17 == 0)) {
              iVar17 = local_50;
              if ((!bVar2) && ((bVar4 && (puVar11 = puVar12, iVar8 = iVar9, 0 < iVar9)))) {
                do {
                  _gleVPFlipColors(param_1,*puVar11,1,iVar17);
                  iVar8 = iVar8 + -1;
                  puVar11 = puVar11 + 1;
                } while (iVar8 != 0);
              }
              dVar18 = (double)_gleSelectPolygonPtr(param_1,puVar12,iVar9);
            }
          }
LAB_000f19ac:
          uVar16 = uVar16 + 0x300;
        } while (uVar16 <= uVar13);
      }
    }
  }
  return;
}

/* FUN_000f19d8 @ 0xf19d8 (996 bytes) */
void FUN_000f19d8(param_1)
  int param_1;
{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  uint *puVar13;
  int *piVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint *puVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  double extraout_f1;
  double dVar22;
  double extraout_f1_00;
  double extraout_f1_01;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  int local_50;
  int local_4c [5];
  
  iVar10 = -1;
  bVar2 = false;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar2 = true;
  }
  bVar2 = !bVar2;
  bVar4 = false;
  if ((!bVar2) && (*(char *)(param_1 + 0x4666) != '\0')) {
    bVar4 = true;
  }
  uVar11 = 0;
  cVar1 = *(char *)(param_1 + 0x34da);
  uVar21 = *(uint *)(param_1 + 0x4854);
  if ((((int)*(short *)(param_1 + 0x487c) != 0) &&
      (uVar16 = (*(int *)(param_1 + 0x4858) - uVar21) / (uint)(int)*(short *)(param_1 + 0x487c),
      2 < (int)uVar16)) &&
     (uVar8 = (**(code **)(param_1 + 0x5060))(param_1,uVar21,uVar16), (uVar8 & 0xff00) == 0)) {
    dVar22 = extraout_f1;
    if (bVar2) {
      if (*(char *)(param_1 + 0x4e18) != '\0') {
        dVar22 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, uVar21, uVar16);
      }
    }
    else {
      uVar21 = *(uint *)(param_1 + 0x4864);
    }
    if (((uVar8 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      if (cVar1 == '\0') {
        _gleSelectTriangleStrip(param_1,uVar21,uVar16);
      }
      else {
        piVar14 = *(int **)(param_1 + 0x4870);
        uVar8 = (uVar21 + uVar16 * 0x100) - 0x300;
        uVar16 = 0;
        do {
          bVar3 = false;
          iVar17 = 0;
          uVar20 = uVar16;
          uVar5 = uVar21;
          while (uVar16 = uVar20, uVar21 <= uVar8) {
            uVar19 = uVar21 + 0x100;
            iVar9 = ((undefined4 (*)())_gleCullTriangle)(param_1,uVar21,uVar19,uVar21 + 0x200,uVar20,&local_50,dVar22,
                                     in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff78,
                                     in_stack_ffffff80);
            dVar22 = extraout_f1_00;
            if (iVar9 == 0) {
              if (iVar10 != local_50) {
                bVar3 = true;
              }
              if ((bVar3) && (0 < iVar17)) break;
              if (iVar17 == 0) {
                uVar11 = uVar20;
              }
              iVar17 = iVar17 + 1;
              iVar10 = local_50;
              uVar15 = uVar5;
            }
            else {
              uVar15 = uVar19;
              uVar16 = uVar20 ^ 1;
              uVar21 = uVar19;
              if (0 < iVar17) break;
            }
            uVar20 = uVar20 ^ 1;
            uVar21 = uVar19;
            uVar5 = uVar15;
          }
          iVar9 = iVar17 + 2;
          if (2 < iVar9) {
            if ((!bVar2) && (bVar4)) {
              _gleVPFlipColors(param_1,uVar5,iVar9,iVar10);
            }
            uVar20 = uVar5;
            if (uVar11 != 0) {
              uVar20 = uVar5 + 0x100;
              piVar14[2] = uVar5;
              iVar9 = iVar17 + 1;
              *piVar14 = uVar5 + 0x200;
              piVar14[1] = uVar20;
              dVar22 = (double)_gleSelectPolygonPtr(param_1,piVar14,3);
              if (iVar9 < 3) goto LAB_000f1c00;
            }
            dVar22 = (double)_gleSelectTriangleStrip(param_1,uVar20,iVar9);
          }
LAB_000f1c00: ;
        } while (uVar21 <= uVar8);
      }
    }
    else {
      puVar18 = *(uint **)(param_1 + 0x4870);
      uVar11 = (uVar21 + uVar16 * 0x100) - 0x300;
      puVar12 = *(uint **)(param_1 + 0x4874);
      if (uVar21 <= uVar11) {
        bVar3 = false;
        do {
          bVar3 = !bVar3;
          if (bVar3) {
            puVar18[2] = uVar21 + 0x200;
            *puVar18 = uVar21;
          }
          else {
            *puVar18 = uVar21 + 0x200;
            puVar18[2] = uVar21;
          }
          uVar21 = uVar21 + 0x100;
          puVar18[1] = uVar21;
          if (bVar2) {
            uVar7 = *(undefined4 *)(param_1 + 0x485c);
          }
          else {
            uVar7 = *(undefined4 *)(param_1 + 0x4854);
          }
          *(undefined4 *)(param_1 + 0x4858) = uVar7;
          puVar13 = puVar12;
          iVar10 = 3;
          puVar6 = puVar18;
          if ((*(char *)(param_1 + 0x4e18) == '\0') ||
             (dVar22 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar18,3,puVar12,local_4c,dVar22,in_f2,
                                                 in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                 in_stack_ffffff78,in_stack_ffffff80),
             puVar13 = puVar18, iVar10 = local_4c[0], puVar6 = puVar12, local_4c[0] != 0)) {
            puVar18 = puVar6;
            puVar12 = puVar13;
            if ((uVar8 & 0xff) != 0) {
              dVar22 = (double)_gleClipPoly(param_1,puVar18,iVar10,uVar8 & 0xff,puVar13,local_4c,1);
              if (local_4c[0] == 0) goto LAB_000f1d94;
              if (0 < local_4c[0]) {
                puVar12 = puVar18;
                iVar10 = local_4c[0];
                puVar18 = puVar13;
              }
            }
            if ((cVar1 == '\0') ||
               (iVar17 = ((int (*)())_gleCullPolygonPtrStack)(param_1,puVar18,iVar10,&local_50),
               dVar22 = extraout_f1_01, iVar17 == 0)) {
              iVar17 = local_50;
              if ((!bVar2) && ((bVar4 && (iVar9 = iVar10, puVar13 = puVar18, 0 < iVar10)))) {
                do {
                  _gleVPFlipColors(param_1,*puVar13,1,iVar17);
                  iVar9 = iVar9 + -1;
                  puVar13 = puVar13 + 1;
                } while (iVar9 != 0);
              }
              dVar22 = (double)_gleSelectPolygonPtr(param_1,puVar18,iVar10);
            }
          }
LAB_000f1d94: ;
        } while (uVar21 <= uVar11);
      }
    }
  }
  return;
}

/* FUN_000f1dc0 @ 0xf1dc0 (860 bytes) */
void FUN_000f1dc0(param_1)
  int param_1;
{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  int iVar13;
  int *piVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  double extraout_f1;
  double dVar18;
  double extraout_f1_00;
  double extraout_f1_01;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  int local_50;
  int local_4c [5];
  
  iVar9 = -1;
  bVar2 = false;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar2 = true;
  }
  bVar2 = !bVar2;
  bVar4 = false;
  if ((!bVar2) && (*(char *)(param_1 + 0x4666) != '\0')) {
    bVar4 = true;
  }
  cVar1 = *(char *)(param_1 + 0x34da);
  iVar13 = *(int *)(param_1 + 0x4854);
  if ((((int)*(short *)(param_1 + 0x487c) != 0) &&
      (uVar15 = (uint)(*(int *)(param_1 + 0x4858) - iVar13) /
                (uint)(int)*(short *)(param_1 + 0x487c), 2 < (int)uVar15)) &&
     (uVar7 = (**(code **)(param_1 + 0x5060))(param_1,iVar13,uVar15), (uVar7 & 0xff00) == 0)) {
    dVar18 = extraout_f1;
    if (bVar2) {
      if (*(char *)(param_1 + 0x4e18) != '\0') {
        dVar18 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, iVar13, uVar15);
      }
    }
    else {
      iVar13 = *(int *)(param_1 + 0x4864);
    }
    if (((uVar7 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      if (cVar1 == '\0') {
        _gleSelectTriangleFan(param_1,iVar13,iVar13 + 0x100,uVar15 - 1);
      }
      else {
        uVar7 = iVar13 + 0x100;
        uVar15 = (iVar13 + uVar15 * 0x100) - 0x200;
        do {
          bVar3 = false;
          iVar16 = 0;
          uVar17 = uVar7;
          do {
            while( true ) {
              uVar12 = uVar17;
              if (uVar15 < uVar7) goto LAB_000f1f60;
              uVar17 = uVar7 + 0x100;
              iVar8 = ((undefined4 (*)())_gleCullTriangle)(param_1,iVar13,uVar7,uVar17,0,&local_50,dVar18,in_f2,in_f3,
                                       in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff78,
                                       in_stack_ffffff80);
              dVar18 = extraout_f1_00;
              if (iVar8 != 0) break;
              if (iVar9 != local_50) {
                bVar3 = true;
              }
              if ((bVar3) && (0 < iVar16)) goto LAB_000f1f60;
              iVar16 = iVar16 + 1;
              iVar9 = local_50;
              uVar7 = uVar17;
              uVar17 = uVar12;
            }
            uVar7 = uVar17;
          } while (iVar16 < 1);
LAB_000f1f60:
          iVar16 = iVar16 + 1;
          if (1 < iVar16) {
            if ((!bVar2) && (bVar4)) {
              _gleVPFlipColors(param_1,uVar12,iVar16,iVar9);
            }
            dVar18 = (double)_gleSelectTriangleFan(param_1,iVar13,uVar12,iVar16);
          }
        } while (uVar7 <= uVar15);
      }
    }
    else {
      piVar14 = *(int **)(param_1 + 0x4870);
      uVar15 = (iVar13 + uVar15 * 0x100) - 0x200;
      piVar10 = *(int **)(param_1 + 0x4874);
      if (iVar13 + 0x100U <= uVar15) {
        uVar17 = iVar13 + 0x100U;
        do {
          uVar12 = uVar17 + 0x100;
          *piVar14 = iVar13;
          piVar14[1] = uVar17;
          piVar14[2] = uVar12;
          if (bVar2) {
            uVar6 = *(undefined4 *)(param_1 + 0x485c);
          }
          else {
            uVar6 = *(undefined4 *)(param_1 + 0x4854);
          }
          *(undefined4 *)(param_1 + 0x4858) = uVar6;
          piVar11 = piVar10;
          piVar5 = piVar14;
          iVar9 = 3;
          if ((*(char *)(param_1 + 0x4e18) == '\0') ||
             (dVar18 = (double)((double (*)())_gleClipPolyPlane)(param_1,piVar14,3,piVar10,local_4c,dVar18,in_f2,
                                                 in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                 in_stack_ffffff78,in_stack_ffffff80),
             piVar11 = piVar14, piVar5 = piVar10, iVar9 = local_4c[0], local_4c[0] != 0)) {
            piVar14 = piVar5;
            piVar10 = piVar11;
            if ((uVar7 & 0xff) != 0) {
              dVar18 = (double)_gleClipPoly(param_1,piVar14,iVar9,uVar7 & 0xff,piVar11,local_4c,1);
              if (local_4c[0] == 0) goto LAB_000f20f4;
              if (0 < local_4c[0]) {
                piVar10 = piVar14;
                piVar14 = piVar11;
                iVar9 = local_4c[0];
              }
            }
            if ((cVar1 == '\0') ||
               (iVar16 = ((int (*)())_gleCullPolygonPtrStack)(param_1,piVar14,iVar9,&local_50),
               dVar18 = extraout_f1_01, iVar16 == 0)) {
              iVar16 = local_50;
              if ((!bVar2) && ((bVar4 && (piVar11 = piVar14, iVar8 = iVar9, 0 < iVar9)))) {
                do {
                  _gleVPFlipColors(param_1,*piVar11,1,iVar16);
                  iVar8 = iVar8 + -1;
                  piVar11 = piVar11 + 1;
                } while (iVar8 != 0);
              }
              dVar18 = (double)_gleSelectPolygonPtr(param_1,piVar14,iVar9);
            }
          }
LAB_000f20f4:
          uVar17 = uVar12;
        } while (uVar12 <= uVar15);
      }
    }
  }
  return;
}

/* FUN_000f2120 @ 0xf2120 (856 bytes) */
void FUN_000f2120(param_1)
  int param_1;
{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint *puVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  double extraout_f1;
  double dVar17;
  double extraout_f1_00;
  double extraout_f1_01;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  double in_stack_ffffff88;
  int local_50;
  int local_4c [6];
  
  iVar9 = -1;
  bVar2 = false;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar2 = true;
  }
  bVar2 = !bVar2;
  bVar4 = false;
  if ((!bVar2) && (*(char *)(param_1 + 0x4666) != '\0')) {
    bVar4 = true;
  }
  cVar1 = *(char *)(param_1 + 0x34da);
  uVar15 = *(uint *)(param_1 + 0x4854);
  if ((((int)*(short *)(param_1 + 0x487c) != 0) &&
      (uVar12 = (*(int *)(param_1 + 0x4858) - uVar15) / (uint)(int)*(short *)(param_1 + 0x487c),
      3 < (int)uVar12)) &&
     (uVar7 = (**(code **)(param_1 + 0x5060))(param_1,uVar15,uVar12), (uVar7 & 0xff00) == 0)) {
    dVar17 = extraout_f1;
    if (bVar2) {
      if (*(char *)(param_1 + 0x4e18) != '\0') {
        dVar17 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, uVar15, uVar12);
      }
    }
    else {
      uVar15 = *(uint *)(param_1 + 0x4864);
    }
    if (((uVar7 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      if (cVar1 == '\0') {
        _gleSelectQuads(param_1,uVar15,uVar12);
      }
      else {
        uVar12 = (uVar15 + uVar12 * 0x100) - 0x400;
        do {
          bVar3 = false;
          iVar16 = 0;
          uVar14 = uVar15;
          uVar7 = uVar15;
          if (uVar15 <= uVar12) {
            do {
              iVar8 = ((undefined4 (*)())_gleCullQuad)(param_1,uVar15,uVar15 + 0x100,uVar15 + 0x200,uVar15 + 0x300,
                                   &local_50,dVar17,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                   in_stack_ffffff78,in_stack_ffffff80,in_stack_ffffff88);
              dVar17 = dVar17;
              if (iVar8 == 0) {
                if (iVar9 != local_50) {
                  bVar3 = true;
                }
                if ((bVar3) && (uVar7 = uVar15, 0 < iVar16)) break;
                iVar16 = iVar16 + 4;
                iVar9 = local_50;
                uVar7 = uVar14;
              }
              else {
                uVar7 = uVar15 + 0x400;
                if (0 < iVar16) break;
              }
              uVar15 = uVar15 + 0x400;
              uVar14 = uVar7;
              uVar7 = uVar15;
            } while (uVar15 <= uVar12);
            if (3 < iVar16) {
              if ((!bVar2) && (bVar4)) {
                _gleVPFlipColors(param_1,uVar14,iVar16,iVar9);
              }
              dVar17 = (double)_gleSelectQuads(param_1,uVar14,iVar16);
            }
          }
          uVar15 = uVar7;
        } while (uVar7 <= uVar12);
      }
    }
    else {
      puVar13 = *(uint **)(param_1 + 0x4870);
      uVar12 = (uVar15 + uVar12 * 0x100) - 0x400;
      puVar10 = *(uint **)(param_1 + 0x4874);
      if (uVar15 <= uVar12) {
        do {
          puVar13[1] = uVar15 + 0x100;
          puVar13[2] = uVar15 + 0x200;
          puVar13[3] = uVar15 + 0x300;
          *puVar13 = uVar15;
          if (bVar2) {
            uVar6 = *(undefined4 *)(param_1 + 0x485c);
          }
          else {
            uVar6 = *(undefined4 *)(param_1 + 0x4854);
          }
          *(undefined4 *)(param_1 + 0x4858) = uVar6;
          puVar11 = puVar10;
          iVar9 = 4;
          puVar5 = puVar13;
          if ((*(char *)(param_1 + 0x4e18) == '\0') ||
             (dVar17 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar13,4,puVar10,local_4c,dVar17,in_f2,
                                                 in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                 in_stack_ffffff78,in_stack_ffffff80),
             puVar11 = puVar13, iVar9 = local_4c[0], puVar5 = puVar10, local_4c[0] != 0)) {
            puVar13 = puVar5;
            puVar10 = puVar11;
            if ((uVar7 & 0xff) != 0) {
              dVar17 = (double)_gleClipPoly(param_1,puVar13,iVar9,uVar7 & 0xff,puVar11,local_4c,1);
              if (local_4c[0] == 0) goto LAB_000f2450;
              if (0 < local_4c[0]) {
                puVar10 = puVar13;
                iVar9 = local_4c[0];
                puVar13 = puVar11;
              }
            }
            if ((cVar1 == '\0') ||
               (iVar16 = ((int (*)())_gleCullPolygonPtrStack)(param_1,puVar13,iVar9,&local_50),
               dVar17 = extraout_f1_01, iVar16 == 0)) {
              iVar16 = local_50;
              if ((!bVar2) && ((bVar4 && (puVar11 = puVar13, iVar8 = iVar9, 0 < iVar9)))) {
                do {
                  _gleVPFlipColors(param_1,*puVar11,1,iVar16);
                  iVar8 = iVar8 + -1;
                  puVar11 = puVar11 + 1;
                } while (iVar8 != 0);
              }
              dVar17 = (double)_gleSelectPolygonPtr(param_1,puVar13,iVar9);
            }
          }
LAB_000f2450:
          uVar15 = uVar15 + 0x400;
        } while (uVar15 <= uVar12);
      }
    }
  }
  return;
}

/* FUN_000f247c @ 0xf247c (856 bytes) */
void FUN_000f247c(param_1)
  int param_1;
{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint *puVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint *puVar15;
  uint uVar16;
  double extraout_f1;
  double dVar17;
  double extraout_f1_00;
  double extraout_f1_01;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  double in_stack_ffffff88;
  int local_50;
  int local_4c [6];
  
  iVar9 = -1;
  bVar2 = false;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar2 = true;
  }
  bVar2 = !bVar2;
  bVar4 = false;
  if ((!bVar2) && (*(char *)(param_1 + 0x4666) != '\0')) {
    bVar4 = true;
  }
  cVar1 = *(char *)(param_1 + 0x34da);
  uVar16 = *(uint *)(param_1 + 0x4854);
  if ((((int)*(short *)(param_1 + 0x487c) != 0) &&
      (uVar13 = (*(int *)(param_1 + 0x4858) - uVar16) / (uint)(int)*(short *)(param_1 + 0x487c),
      3 < (int)uVar13)) &&
     (uVar7 = (**(code **)(param_1 + 0x5060))(param_1,uVar16,uVar13), (uVar7 & 0xff00) == 0)) {
    dVar17 = extraout_f1;
    if (bVar2) {
      if (*(char *)(param_1 + 0x4e18) != '\0') {
        dVar17 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, uVar16, uVar13);
      }
    }
    else {
      uVar16 = *(uint *)(param_1 + 0x4864);
    }
    if (((uVar7 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      if (cVar1 == '\0') {
        _gleSelectQuadStrip(param_1,uVar16,uVar13);
      }
      else {
        uVar13 = (uVar16 + uVar13 * 0x100) - 0x400;
        do {
          bVar3 = false;
          iVar14 = 0;
          uVar7 = uVar16;
          do {
            while( true ) {
              uVar12 = uVar7;
              if (uVar13 < uVar16) goto LAB_000f2614;
              uVar7 = uVar16 + 0x200;
              iVar8 = ((undefined4 (*)())_gleCullQuad)(param_1,uVar16,uVar16 + 0x100,uVar16 + 0x300,uVar7,&local_50,
                                   dVar17,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                   in_stack_ffffff78,in_stack_ffffff80,in_stack_ffffff88);
              dVar17 = extraout_f1_00;
              if (iVar8 != 0) break;
              if (iVar9 != local_50) {
                bVar3 = true;
              }
              if ((bVar3) && (0 < iVar14)) goto LAB_000f2614;
              iVar14 = iVar14 + 2;
              iVar9 = local_50;
              uVar16 = uVar7;
              uVar7 = uVar12;
            }
            uVar16 = uVar7;
          } while (iVar14 < 1);
LAB_000f2614:
          iVar14 = iVar14 + 2;
          if (3 < iVar14) {
            if ((!bVar2) && (bVar4)) {
              _gleVPFlipColors(param_1,uVar12,iVar14,iVar9);
            }
            dVar17 = (double)_gleSelectQuadStrip(param_1,uVar12,iVar14);
          }
        } while (uVar16 <= uVar13);
      }
    }
    else {
      puVar15 = *(uint **)(param_1 + 0x4870);
      puVar10 = *(uint **)(param_1 + 0x4874);
      uVar13 = (uVar16 + uVar13 * 0x100) - 0x400;
      if (uVar16 <= uVar13) {
        do {
          uVar12 = uVar16 + 0x200;
          puVar15[1] = uVar16 + 0x100;
          puVar15[2] = uVar16 + 0x300;
          *puVar15 = uVar16;
          puVar15[3] = uVar12;
          if (bVar2) {
            uVar6 = *(undefined4 *)(param_1 + 0x485c);
          }
          else {
            uVar6 = *(undefined4 *)(param_1 + 0x4854);
          }
          *(undefined4 *)(param_1 + 0x4858) = uVar6;
          puVar11 = puVar10;
          iVar9 = 4;
          puVar5 = puVar15;
          if ((*(char *)(param_1 + 0x4e18) == '\0') ||
             (dVar17 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar15,4,puVar10,local_4c,dVar17,in_f2,
                                                 in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                 in_stack_ffffff78,in_stack_ffffff80),
             puVar11 = puVar15, iVar9 = local_4c[0], puVar5 = puVar10, local_4c[0] != 0)) {
            puVar15 = puVar5;
            puVar10 = puVar11;
            if ((uVar7 & 0xff) != 0) {
              dVar17 = (double)_gleClipPoly(param_1,puVar15,iVar9,uVar7 & 0xff,puVar11,local_4c,1);
              if (local_4c[0] == 0) goto LAB_000f27ac;
              if (0 < local_4c[0]) {
                puVar10 = puVar15;
                iVar9 = local_4c[0];
                puVar15 = puVar11;
              }
            }
            if ((cVar1 == '\0') ||
               (iVar14 = ((int (*)())_gleCullPolygonPtrStack)(param_1,puVar15,iVar9,&local_50),
               dVar17 = extraout_f1_01, iVar14 == 0)) {
              iVar14 = local_50;
              if ((!bVar2) && ((bVar4 && (puVar11 = puVar15, iVar8 = iVar9, 0 < iVar9)))) {
                do {
                  _gleVPFlipColors(param_1,*puVar11,1,iVar14);
                  iVar8 = iVar8 + -1;
                  puVar11 = puVar11 + 1;
                } while (iVar8 != 0);
              }
              dVar17 = (double)_gleSelectPolygonPtr(param_1,puVar15,iVar9);
            }
          }
LAB_000f27ac:
          uVar16 = uVar12;
        } while (uVar12 <= uVar13);
      }
    }
  }
  return;
}

/* _gleFlushAtomicFunc @ 0xf27d4 (64 bytes) */
void _gleFlushAtomicFunc(param_1)
  int param_1;
{
  (**(code **)(param_1 + 0x4a08))(param_1);
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  _glePopMaterials(param_1);
  return;
}

/* _gleFlushAtomicTCLRDirtyFunc @ 0xf2814 (172 bytes) */
void _gleFlushAtomicTCLRDirtyFunc(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  if ((((*(char *)(param_1 + 0x7580) != '\0') && ((*(uint *)(param_1 + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(param_1 + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(param_1 + 0x4664) == '\0' && (*(int *)(param_1 + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
                    
                    
    (**(code **)(param_1 + 0x4a0c))(param_1);
    return;
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleFlushLineLoopFunc @ 0xf28c0 (212 bytes) */
void _gleFlushLineLoopFunc(param_1)
  int param_1;
{
  int iVar1;
  short sVar3;
  undefined8 *puVar2;
  undefined8 *puVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 local_110 [33];
  
  if (*(char *)(param_1 + 0x4a18) == '\0') {
    sVar3 = *(short *)(param_1 + 0x487c);
    iVar5 = 0;
    if ((int)sVar3 >> 3 < 1) goto LAB_000f291c;
    do {
      iVar1 = iVar5 * 8;
      iVar5 = iVar5 + 1;
      *(undefined8 *)(iVar1 + *(int *)(param_1 + 0x4854) + -0x100) =
           *(undefined8 *)(iVar1 + *(int *)(param_1 + 0x4854));
    } while (iVar5 < (int)sVar3 >> 3);
  }
  sVar3 = *(short *)(param_1 + 0x487c);
LAB_000f291c:
  iVar5 = (int)sVar3 >> 3;
  if (0 < iVar5) {
    puVar4 = local_110;
    puVar2 = (undefined8 *)(*(int *)(param_1 + 0x4858) + -0x100);
    do {
      uVar6 = *puVar2;
      puVar2 = puVar2 + 1;
      *puVar4 = uVar6;
      puVar4 = puVar4 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  *(undefined1 *)(param_1 + 0x4a18) = 1;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  _glePopMaterials(param_1);
  _gleSubmitVertexCopy(param_1,local_110);
  return;
}

/* _gleFlushLineLoopTCLFunc @ 0xf2994 (180 bytes) */
void _gleFlushLineLoopTCLFunc(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  (**(code **)(param_1 + 0x4a08))(param_1);
  iVar3 = (int)*(short *)(param_1 + 0x487c);
  iVar4 = *(int *)(param_1 + 0x4854);
  if (*(char *)(param_1 + 0x4a18) == '\0') {
    iVar1 = 0;
    if (0 < iVar3) {
      uVar5 = iVar3 + 7U >> 3;
      do {
        *(undefined8 *)(iVar4 + -0x100 + iVar1) = *(undefined8 *)(iVar4 + iVar1);
        iVar1 = iVar1 + 8;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    *(undefined1 *)(param_1 + 0x4a18) = 1;
  }
  iVar1 = 0;
  iVar2 = *(int *)(param_1 + 0x4858);
  if (0 < iVar3) {
    uVar5 = iVar3 + 7U >> 3;
    do {
      *(undefined8 *)(iVar4 + iVar1) = *(undefined8 *)((iVar2 - iVar3) + iVar1);
      iVar1 = iVar1 + 8;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  *(int *)(param_1 + 0x4858) = iVar4 + iVar3;
  return;
}

/* _gleFlushLineLoopTCLRDirtyFunc @ 0xf2a48 (292 bytes) */
void _gleFlushLineLoopTCLRDirtyFunc(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if ((((*(char *)(param_1 + 0x7580) != '\0') && ((*(uint *)(param_1 + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(param_1 + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(param_1 + 0x4664) == '\0' && (*(int *)(param_1 + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
                    
                    
    (**(code **)(param_1 + 0x4a0c))(param_1);
    return;
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  iVar3 = (int)*(short *)(param_1 + 0x487c);
  iVar1 = *(int *)(param_1 + 0x4854);
  if (*(char *)(param_1 + 0x4a18) == '\0') {
    iVar2 = 0;
    if (0 < iVar3) {
      uVar5 = iVar3 + 7U >> 3;
      do {
        *(undefined8 *)(iVar1 + -0x100 + iVar2) = *(undefined8 *)(iVar1 + iVar2);
        iVar2 = iVar2 + 8;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    *(undefined1 *)(param_1 + 0x4a18) = 1;
  }
  iVar2 = 0;
  iVar4 = *(int *)(param_1 + 0x4858);
  if (0 < iVar3) {
    uVar5 = iVar3 + 7U >> 3;
    do {
      *(undefined8 *)(iVar1 + iVar2) = *(undefined8 *)((iVar4 - iVar3) + iVar2);
      iVar2 = iVar2 + 8;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(int *)(param_1 + 0x4858) = iVar1 + iVar3;
  return;
}

/* _gleFlushLineStripFunc @ 0xf2b6c (140 bytes) */
void _gleFlushLineStripFunc(param_1)
  int param_1;
{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 local_110 [33];
  
  iVar1 = (int)*(short *)(param_1 + 0x487c) >> 3;
  if (0 < iVar1) {
    puVar3 = local_110;
    puVar2 = (undefined8 *)(*(int *)(param_1 + 0x4858) + -0x100);
    do {
      uVar4 = *puVar2;
      puVar2 = puVar2 + 1;
      *puVar3 = uVar4;
      puVar3 = puVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  *(undefined1 *)(param_1 + 0x4a18) = 1;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  _glePopMaterials(param_1);
  _gleSubmitVertexCopy(param_1,local_110);
  return;
}

/* _gleFlushLineStripTCLFunc @ 0xf2bf8 (124 bytes) */
void _gleFlushLineStripTCLFunc(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  (**(code **)(param_1 + 0x4a08))(param_1);
  iVar3 = (int)*(short *)(param_1 + 0x487c);
  iVar1 = 0;
  iVar2 = *(int *)(param_1 + 0x4858);
  *(undefined1 *)(param_1 + 0x4a18) = 1;
  iVar4 = *(int *)(param_1 + 0x4854);
  if (0 < iVar3) {
    uVar5 = iVar3 + 7U >> 3;
    do {
      *(undefined8 *)(iVar4 + iVar1) = *(undefined8 *)((iVar2 - iVar3) + iVar1);
      iVar1 = iVar1 + 8;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  *(int *)(param_1 + 0x4858) = iVar4 + iVar3;
  return;
}

/* _gleFlushLineStripTCLRDirtyFunc @ 0xf2c74 (236 bytes) */
void _gleFlushLineStripTCLRDirtyFunc(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if ((((*(char *)(param_1 + 0x7580) != '\0') && ((*(uint *)(param_1 + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(param_1 + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(param_1 + 0x4664) == '\0' && (*(int *)(param_1 + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
                    
                    
    (**(code **)(param_1 + 0x4a0c))(param_1);
    return;
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  iVar3 = (int)*(short *)(param_1 + 0x487c);
  iVar2 = 0;
  iVar4 = *(int *)(param_1 + 0x4858);
  *(undefined1 *)(param_1 + 0x4a18) = 1;
  iVar1 = *(int *)(param_1 + 0x4854);
  if (0 < iVar3) {
    uVar5 = iVar3 + 7U >> 3;
    do {
      *(undefined8 *)(iVar1 + iVar2) = *(undefined8 *)((iVar4 - iVar3) + iVar2);
      iVar2 = iVar2 + 8;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(int *)(param_1 + 0x4858) = iVar1 + iVar3;
  return;
}

/* _gleFlushTriQuadStripFunc @ 0xf2d60 (196 bytes) */
void _gleFlushTriQuadStripFunc(param_1)
  int param_1;
{
  short sVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 local_210 [32];
  undefined8 local_110 [33];
  
  sVar1 = *(short *)(param_1 + 0x487c);
  iVar2 = (int)sVar1 >> 3;
  if (0 < iVar2) {
    puVar4 = local_210;
    puVar3 = (undefined8 *)(*(int *)(param_1 + 0x4858) + -0x200);
    do {
      uVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      *puVar4 = uVar5;
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iVar2 = (int)sVar1 >> 3;
  if (0 < iVar2) {
    puVar4 = local_110;
    puVar3 = (undefined8 *)(*(int *)(param_1 + 0x4858) + -0x100);
    do {
      uVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      *puVar4 = uVar5;
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  _glePopMaterials(param_1);
  _gleSubmitVertexCopy(param_1,local_210);
  _gleSubmitVertexCopy(param_1,local_110);
  return;
}

/* _gleFlushTriQuadStripTCLFunc @ 0xf2e24 (120 bytes) */
void _gleFlushTriQuadStripTCLFunc(param_1)
  int param_1;
{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  (**(code **)(param_1 + 0x4a08))(param_1);
  sVar1 = *(short *)(param_1 + 0x487c);
  iVar3 = 0;
  iVar4 = *(int *)(param_1 + 0x4858);
  iVar2 = sVar1 * 2;
  iVar5 = *(int *)(param_1 + 0x4854);
  if (0 < iVar2) {
    uVar6 = iVar2 + 7U >> 3;
    do {
      *(undefined8 *)(iVar5 + iVar3) = *(undefined8 *)(iVar4 + sVar1 * -2 + iVar3);
      iVar3 = iVar3 + 8;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  *(int *)(param_1 + 0x4858) = iVar5 + iVar2;
  return;
}

/* _gleFlushTriQuadStripTCLRDirtyFunc @ 0xf2e9c (232 bytes) */
void _gleFlushTriQuadStripTCLRDirtyFunc(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if ((((*(char *)(param_1 + 0x7580) != '\0') && ((*(uint *)(param_1 + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(param_1 + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(param_1 + 0x4664) == '\0' && (*(int *)(param_1 + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
                    
                    
    (**(code **)(param_1 + 0x4a0c))(param_1);
    return;
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  sVar1 = *(short *)(param_1 + 0x487c);
  iVar4 = 0;
  iVar5 = *(int *)(param_1 + 0x4858);
  iVar2 = sVar1 * 2;
  iVar3 = *(int *)(param_1 + 0x4854);
  if (0 < iVar2) {
    uVar6 = iVar2 + 7U >> 3;
    do {
      *(undefined8 *)(iVar3 + iVar4) = *(undefined8 *)(iVar5 + sVar1 * -2 + iVar4);
      iVar4 = iVar4 + 8;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(int *)(param_1 + 0x4858) = iVar3 + iVar2;
  return;
}

/* _gleFlushTriangleFanFunc @ 0xf2f84 (200 bytes) */
void _gleFlushTriangleFanFunc(param_1)
  int param_1;
{
  short sVar1;
  int iVar2;
  undefined8 *puVar3;
  int iVar4;
  undefined8 *puVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 local_210 [32];
  undefined8 local_110 [33];
  
  sVar1 = *(short *)(param_1 + 0x487c);
  iVar2 = (int)sVar1 >> 3;
  if (0 < iVar2) {
    iVar6 = *(int *)(param_1 + 0x4854);
    iVar4 = 0;
    do {
      local_210[iVar4] = *(undefined8 *)(iVar4 * 8 + iVar6);
      iVar2 = iVar2 + -1;
      iVar4 = iVar4 + 1;
    } while (iVar2 != 0);
  }
  iVar2 = (int)sVar1 >> 3;
  if (0 < iVar2) {
    puVar5 = local_110;
    puVar3 = (undefined8 *)(*(int *)(param_1 + 0x4858) + -0x100);
    do {
      uVar7 = *puVar3;
      puVar3 = puVar3 + 1;
      *puVar5 = uVar7;
      puVar5 = puVar5 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  _glePopMaterials(param_1);
  _gleSubmitVertexCopy(param_1,local_210);
  _gleSubmitVertexCopy(param_1,local_110);
  return;
}

/* _gleFlushTriangleFanTCLFunc @ 0xf304c (120 bytes) */
void _gleFlushTriangleFanTCLFunc(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  (**(code **)(param_1 + 0x4a08))(param_1);
  iVar3 = (int)*(short *)(param_1 + 0x487c);
  iVar1 = 0;
  iVar4 = *(int *)(param_1 + 0x4858);
  iVar2 = *(int *)(param_1 + 0x4854) + iVar3;
  if (0 < iVar3) {
    uVar5 = iVar3 + 7U >> 3;
    do {
      *(undefined8 *)(iVar2 + iVar1) = *(undefined8 *)((iVar4 - iVar3) + iVar1);
      iVar1 = iVar1 + 8;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  *(int *)(param_1 + 0x4858) = iVar2 + iVar3;
  return;
}

/* _gleFlushTriangleFanTCLRDirtyFunc @ 0xf30c4 (232 bytes) */
void _gleFlushTriangleFanTCLRDirtyFunc(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if ((((*(char *)(param_1 + 0x7580) != '\0') && ((*(uint *)(param_1 + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(param_1 + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(param_1 + 0x4664) == '\0' && (*(int *)(param_1 + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
                    
                    
    (**(code **)(param_1 + 0x4a0c))(param_1);
    return;
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  iVar3 = (int)*(short *)(param_1 + 0x487c);
  iVar2 = 0;
  iVar4 = *(int *)(param_1 + 0x4858);
  iVar1 = *(int *)(param_1 + 0x4854) + iVar3;
  if (0 < iVar3) {
    uVar5 = iVar3 + 7U >> 3;
    do {
      *(undefined8 *)(iVar1 + iVar2) = *(undefined8 *)((iVar4 - iVar3) + iVar2);
      iVar2 = iVar2 + 8;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(int *)(param_1 + 0x4858) = iVar1 + iVar3;
  return;
}

/* _gleFlushPolygonFunc @ 0xf31ac (240 bytes) */
void _gleFlushPolygonFunc(param_1)
  int param_1;
{
  short sVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 local_210 [15];
  undefined1 local_194;
  undefined8 local_110 [32];
  
  sVar1 = *(short *)(param_1 + 0x487c);
  iVar2 = (int)sVar1 >> 3;
  if (0 < iVar2) {
    iVar5 = *(int *)(param_1 + 0x4854);
    iVar6 = 0;
    do {
      local_210[iVar6] = *(undefined8 *)(iVar6 * 8 + iVar5);
      iVar2 = iVar2 + -1;
      iVar6 = iVar6 + 1;
    } while (iVar2 != 0);
  }
  iVar6 = 0;
  iVar2 = (int)sVar1 >> 3;
  if (iVar2 < 1) {
    iVar5 = *(int *)(param_1 + 0x4858);
  }
  else {
    iVar5 = *(int *)(param_1 + 0x4858);
    puVar4 = local_110;
    puVar3 = (undefined8 *)(iVar5 + -0x100);
    do {
      iVar6 = iVar6 + 1;
      uVar7 = *puVar3;
      puVar3 = puVar3 + 1;
      *puVar4 = uVar7;
      puVar4 = puVar4 + 1;
    } while (iVar6 < iVar2);
  }
  *(undefined1 *)(iVar5 + -0x84) = 0;
  (**(code **)(param_1 + 0x4a08))(param_1);
  *(undefined1 *)(param_1 + 0x4a18) = 1;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  _glePopMaterials(param_1);
  local_194 = 0;
  _gleSubmitVertexCopy(param_1,local_210);
  _gleSubmitVertexCopy(param_1,local_110);
  return;
}

/* _gleFlushPolygonTCLFunc @ 0xf329c (220 bytes) */
void _gleFlushPolygonTCLFunc(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar3 = 0;
  iVar4 = (int)*(short *)(param_1 + 0x487c);
  iVar5 = *(int *)(param_1 + 0x4858) - iVar4;
  if ((*(short *)(param_1 + 0x34d2) == 0x1b01) || (*(short *)(param_1 + 0x34d0) == 0x1b01)) {
    uVar3 = *(undefined1 *)(iVar5 + *(short *)(param_1 + 0x487e));
    *(undefined1 *)(iVar5 + *(short *)(param_1 + 0x487e)) = 0;
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  iVar2 = *(int *)(param_1 + 0x4854);
  *(undefined1 *)(param_1 + 0x4a18) = 1;
  if ((*(short *)(param_1 + 0x34d2) == 0x1b01) || (*(short *)(param_1 + 0x34d0) == 0x1b01)) {
    *(undefined1 *)(iVar5 + *(short *)(param_1 + 0x487e)) = uVar3;
    *(undefined1 *)(iVar2 + *(short *)(param_1 + 0x487e)) = 0;
  }
  iVar1 = 0;
  iVar2 = iVar2 + iVar4;
  if (0 < iVar4) {
    uVar6 = iVar4 + 7U >> 3;
    do {
      *(undefined8 *)(iVar2 + iVar1) = *(undefined8 *)(iVar5 + iVar1);
      iVar1 = iVar1 + 8;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  *(int *)(param_1 + 0x4858) = iVar2 + iVar4;
  return;
}

/* _gleFlushPolygonTCLRDirtyFunc @ 0xf3378 (328 bytes) */
void _gleFlushPolygonTCLRDirtyFunc(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar3 = 0;
  if ((((*(char *)(param_1 + 0x7580) != '\0') && ((*(uint *)(param_1 + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(param_1 + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(param_1 + 0x4664) == '\0' && (*(int *)(param_1 + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
                    
                    
    (**(code **)(param_1 + 0x4a0c))(param_1);
    return;
  }
  iVar4 = (int)*(short *)(param_1 + 0x487c);
  iVar5 = *(int *)(param_1 + 0x4858) - iVar4;
  if ((*(short *)(param_1 + 0x34d2) == 0x1b01) || (*(short *)(param_1 + 0x34d0) == 0x1b01)) {
    uVar3 = *(undefined1 *)(iVar5 + *(short *)(param_1 + 0x487e));
    *(undefined1 *)(iVar5 + *(short *)(param_1 + 0x487e)) = 0;
  }
  (**(code **)(param_1 + 0x4a08))(param_1);
  iVar2 = *(int *)(param_1 + 0x4854);
  *(undefined1 *)(param_1 + 0x4a18) = 1;
  if ((*(short *)(param_1 + 0x34d2) == 0x1b01) || (*(short *)(param_1 + 0x34d0) == 0x1b01)) {
    *(undefined1 *)(iVar5 + *(short *)(param_1 + 0x487e)) = uVar3;
    *(undefined1 *)(iVar2 + *(short *)(param_1 + 0x487e)) = 0;
  }
  iVar1 = 0;
  iVar2 = iVar2 + iVar4;
  if (0 < iVar4) {
    uVar6 = iVar4 + 7U >> 3;
    do {
      *(undefined8 *)(iVar2 + iVar1) = *(undefined8 *)(iVar5 + iVar1);
      iVar1 = iVar1 + 8;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(int *)(param_1 + 0x4858) = iVar2 + iVar4;
  return;
}

/* _gleInitPrimitiveData @ 0xf34c0 (4 bytes) */
void _gleInitPrimitiveData()
{
  return;
}

/* _gleRenderNoop @ 0xf34c4 (4 bytes) */
void _gleRenderNoop()
{
  return;
}

/* _gleFlushNoop @ 0xf34c8 (12 bytes) */
void _gleFlushNoop(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

