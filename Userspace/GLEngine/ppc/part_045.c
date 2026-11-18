#include "decls.h"

/* _gleBeginLinesRenderTCLRDirty @ 0xd78f4 (60 bytes) */
void _gleBeginLinesRenderTCLRDirty(glContext)
  int glContext;
{
  undefined *flushAtomicTCLRDirtyFunc;
  undefined *renderLinesTCLFunc;
  
  renderLinesTCLFunc = PTR__gleRenderLinesTCLFunc_00112214;
  flushAtomicTCLRDirtyFunc = PTR__gleFlushAtomicTCLRDirtyFunc_00112210;
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined **)(glContext + 0x4a0c) = flushAtomicTCLRDirtyFunc;
  *(undefined **)(glContext + 0x4a08) = renderLinesTCLFunc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginLinesSelectFeedback @ 0xd7930 (76 bytes) */
void _gleBeginLinesSelectFeedback(glContext)
  int glContext;
{
  undefined *puVar1;
  
  *(undefined **)(glContext + 0x4a0c) = PTR__gleFlushAtomicFunc_00112224;
  puVar1 = PTR__gleFeedbackLinesFunc_00112208;
  if (*(int *)(glContext + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectLinesFunc_0011220c;
  }
  *(undefined **)(glContext + 0x4a08) = puVar1;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginLineStripRenderSmooth @ 0xd797c (60 bytes) */
void _gleBeginLineStripRenderSmooth(glContext)
  int glContext;
{
  undefined *renderSmoothLineStripFunc;
  undefined *flushLineStripFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  flushLineStripFunc = PTR__gleFlushLineStripFunc_00112204;
  renderSmoothLineStripFunc = PTR__gleRenderSmoothLineStripFunc_00112200;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushLineStripFunc;
  *(undefined **)(glContext + 0x4a08) = renderSmoothLineStripFunc;
  return;
}

/* _gleBeginLineStripRenderFlat @ 0xd79b8 (60 bytes) */
void _gleBeginLineStripRenderFlat(glContext)
  int glContext;
{
  undefined *renderFlatLineStripFunc;
  undefined *flushLineStripFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  flushLineStripFunc = PTR__gleFlushLineStripFunc_00112204;
  renderFlatLineStripFunc = PTR__gleRenderFlatLineStripFunc_001121fc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushLineStripFunc;
  *(undefined **)(glContext + 0x4a08) = renderFlatLineStripFunc;
  return;
}

/* _gleBeginLineStripRenderTCLRDirty @ 0xd79f4 (68 bytes) */
void _gleBeginLineStripRenderTCLRDirty(glContext)
  int glContext;
{
  undefined *flushLineStripTCLRDirtyFunc;
  undefined *renderLineStripTCLFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  renderLineStripTCLFunc = PTR__gleRenderLineStripTCLFunc_001121f4;
  flushLineStripTCLRDirtyFunc = PTR__gleFlushLineStripTCLRDirtyFunc_001121f0;
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined **)(glContext + 0x4a0c) = flushLineStripTCLRDirtyFunc;
  *(undefined **)(glContext + 0x4a08) = renderLineStripTCLFunc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginLineStripSelectFeedback @ 0xd7a38 (76 bytes) */
void _gleBeginLineStripSelectFeedback(glContext)
  int glContext;
{
  undefined *puVar1;
  
  *(undefined **)(glContext + 0x4a0c) = PTR__gleFlushLineStripFunc_00112204;
  puVar1 = PTR__gleFeedbackLineStripFunc_001121e8;
  if (*(int *)(glContext + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectLineStripFunc_001121ec;
  }
  *(undefined **)(glContext + 0x4a08) = puVar1;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginLineLoopRenderSmooth @ 0xd7a84 (60 bytes) */
void _gleBeginLineLoopRenderSmooth(glContext)
  int glContext;
{
  undefined *renderSmoothLineLoopFunc;
  undefined *flushLineLoopFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  flushLineLoopFunc = PTR__gleFlushLineLoopFunc_001121e4;
  renderSmoothLineLoopFunc = PTR__gleRenderSmoothLineLoopFunc_001121e0;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushLineLoopFunc;
  *(undefined **)(glContext + 0x4a08) = renderSmoothLineLoopFunc;
  return;
}

/* _gleBeginLineLoopRenderFlat @ 0xd7ac0 (60 bytes) */
void _gleBeginLineLoopRenderFlat(glContext)
  int glContext;
{
  undefined *renderFlatLineLoopFunc;
  undefined *flushLineLoopFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  flushLineLoopFunc = PTR__gleFlushLineLoopFunc_001121e4;
  renderFlatLineLoopFunc = PTR__gleRenderFlatLineLoopFunc_001121dc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushLineLoopFunc;
  *(undefined **)(glContext + 0x4a08) = renderFlatLineLoopFunc;
  return;
}

/* _gleBeginLineLoopRenderTCLRDirty @ 0xd7afc (68 bytes) */
void _gleBeginLineLoopRenderTCLRDirty(glContext)
  int glContext;
{
  undefined *flushLineLoopTCLRDirtyFunc;
  undefined *renderLineLoopTCLFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  renderLineLoopTCLFunc = PTR__gleRenderLineLoopTCLFunc_001121d4;
  flushLineLoopTCLRDirtyFunc = PTR__gleFlushLineLoopTCLRDirtyFunc_001121d0;
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined **)(glContext + 0x4a0c) = flushLineLoopTCLRDirtyFunc;
  *(undefined **)(glContext + 0x4a08) = renderLineLoopTCLFunc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginLineLoopSelectFeedback @ 0xd7b40 (84 bytes) */
void _gleBeginLineLoopSelectFeedback(glContext)
  int glContext;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushLineLoopFunc_001121e4;
  *(undefined1 *)(glContext + 0x4a18) = 0;
  *(undefined **)(glContext + 0x4a0c) = puVar1;
  puVar1 = PTR__gleFeedbackLineLoopFunc_001121c8;
  if (*(int *)(glContext + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectLineLoopFunc_001121cc;
  }
  *(undefined **)(glContext + 0x4a08) = puVar1;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleClipLines @ 0xd7b94 (284 bytes) */
int _gleClipLines(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  int param_3;
  undefined4 param_4;
{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  bVar2 = 1;
  do {
    if (((byte)param_4 & bVar2) != 0) {
      piVar4 = param_2;
      for (piVar5 = param_2; piVar5 < param_2 + param_3 + -1; piVar5 = piVar5 + 2) {
        iVar3 = *piVar5;
        iVar6 = piVar5[1];
        if ((bVar2 & *(byte *)(iVar3 + 0x7f)) == 0) {
          if ((bVar2 & *(byte *)(iVar6 + 0x7f)) != 0) {
            bVar1 = (**(code **)(param_1 + 0x49cc))(param_1,iVar6,iVar3,iVar6,bVar2);
            (*(unsigned char *)((unsigned char *)&(param_4) + 3)) = (byte)param_4 | bVar1;
          }
          *piVar4 = iVar3;
          piVar4[1] = iVar6;
LAB_000d7c68:
          piVar4 = piVar4 + 2;
        }
        else if ((bVar2 & *(byte *)(iVar6 + 0x7f)) == 0) {
          bVar1 = (**(code **)(param_1 + 0x49cc))(param_1,iVar3,iVar6,iVar3,bVar2);
          *piVar4 = iVar3;
          (*(unsigned char *)((unsigned char *)&(param_4) + 3)) = (byte)param_4 | bVar1;
          piVar4[1] = iVar6;
          goto LAB_000d7c68;
        }
      }
      param_3 = (int)piVar4 - (int)param_2 >> 2;
      if (param_3 < 2) {
        return 0;
      }
    }
    bVar2 = bVar2 << 1;
    if (0x20 < bVar2) {
      return param_3;
    }
  } while( true );
}

/* _gleClipLinesPlane @ 0xd7cb0 (360 bytes) */
int _gleClipLinesPlane(int param_1,int *param_2,int param_3,double unusedFloatArg1)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  int iVar16;
  
  iVar11 = *(int *)(param_1 + 0x4dfc);
  iVar12 = 0;
  iVar10 = param_3;
  if (0 < iVar11) {
    piVar13 = (int *)(param_1 + 0x4e00);
    do {
      fVar7 = FLOAT_00108e50;
      iVar10 = *piVar13;
      piVar13 = piVar13 + 1;
      iVar10 = param_1 + iVar10 * 0x10;
      fVar1 = *(float *)(iVar10 + 0x418c);
      fVar2 = *(float *)(iVar10 + 0x4198);
      fVar3 = *(float *)(iVar10 + 0x4190);
      fVar4 = *(float *)(iVar10 + 0x4194);
      piVar14 = param_2;
      for (piVar15 = param_2; piVar15 < param_2 + param_3 + -1; piVar15 = piVar15 + 2) {
        iVar16 = *piVar15;
        iVar10 = piVar15[1];
        fVar6 = *(float *)(iVar16 + 0x2c) * fVar2 +
                (*(float *)(iVar16 + 0x28) * fVar4 +
                (*(float *)(iVar16 + 0x20) * fVar1 + *(float *)(iVar16 + 0x24) * fVar3));
        fVar5 = *(float *)(iVar10 + 0x2c) * fVar2 +
                (*(float *)(iVar10 + 0x28) * fVar4 +
                (*(float *)(iVar10 + 0x20) * fVar1 + *(float *)(iVar10 + 0x24) * fVar3));
        if (fVar6 < fVar7) {
          if (fVar7 <= fVar5) {
            fVar5 = fVar6 / (fVar6 - fVar5);
            iVar8 = iVar10;
            iVar9 = iVar16;
LAB_000d7dc4:
            (**(int ( **)(int,int,int,int,double))(param_1 + 0x49c8))(param_1, iVar9, iVar8, iVar9, (double)fVar5);
            goto LAB_000d7dd0;
          }
        }
        else {
          if (fVar5 < fVar7) {
            fVar5 = fVar5 / (fVar5 - fVar6);
            iVar8 = iVar16;
            iVar9 = iVar10;
            goto LAB_000d7dc4;
          }
LAB_000d7dd0:
          *piVar14 = iVar16;
          piVar14[1] = iVar10;
          piVar14 = piVar14 + 2;
        }
      }
      param_3 = (int)piVar14 - (int)param_2 >> 2;
      iVar10 = 0;
    } while ((1 < param_3) && (iVar12 = iVar12 + 1, iVar10 = param_3, iVar12 < iVar11));
  }
  return iVar10;
}

/* _gleFeedbackLinesFunc_body @ 0xd7e1c (776 bytes) */
void _gleFeedbackLinesFunc_body(glContext, unusedArg2, unusedArg3)
  int glContext;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
{
  uint *puVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  double dVar10;
  
  bVar2 = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    bVar2 = true;
  }
  uVar8 = *(uint *)(glContext + 0x4854);
  if (((int)*(short *)(glContext + 0x487c) != 0) &&
     (uVar7 = (*(int *)(glContext + 0x4858) - uVar8) / (uint)(int)*(short *)(glContext + 0x487c),
     1 < (int)uVar7)) {
    bVar2 = !bVar2;
    if (bVar2) {
      uVar4 = (**(code **)(glContext + 0x5060))(glContext,uVar8,uVar7);
    }
    else {
      uVar4 = _gleVPEmulate(glContext,uVar7);
    }
    if ((uVar4 & 0xff00) == 0) {
      if (bVar2) {
        if (*(char *)(glContext + 0x53e4) != '\0') {
          (**(code **)(glContext + 0x53dc))(glContext,uVar8,uVar7);
        }
        if (*(char *)(glContext + 0x50b4) != '\0') {
          (**(code **)(glContext + 0x5064))(glContext,uVar8,uVar7);
        }
        if ((*(char *)(glContext + 0x30aa) != '\0') || (*(char *)(glContext + 0x53e6) != '\0')) {
          (**(code **)(glContext + 0x5068))(glContext,uVar8,uVar7);
        }
      }
      else {
        uVar8 = *(uint *)(glContext + 0x4864);
      }
      if (((uVar4 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
        if ((bVar2) && (*(char *)(glContext + 0x53e5) != '\0')) {
          (**(code **)(glContext + 0x53e0))(glContext,uVar8,uVar7);
        }
        (**(code **)(glContext + 0x506c))(glContext,uVar8,uVar7,0);
        if ((bVar2) && (*(char *)(glContext + 0x30aa) != '\0')) {
          (**(code **)(glContext + 0x4de8))(glContext,uVar8,uVar7);
        }
        iVar5 = uVar8 + uVar7 * 0x100;
        for (; uVar8 < iVar5 - 0x100U; uVar8 = uVar8 + 0x200) {
          ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f2c);
          _gleFeedbackHitRecord(glContext,uVar8);
          _gleFeedbackHitRecord(glContext,uVar8 + 0x100);
        }
        return;
      }
      if ((bVar2) && (*(char *)(glContext + 0x53e5) != '\0')) {
        (**(code **)(glContext + 0x53e0))(glContext,uVar8,uVar7);
      }
      dVar10 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, uVar8, uVar7, 0);
      uVar3 = uVar8 + uVar7 * 0x100;
      puVar9 = *(uint **)(glContext + 0x4870);
      if (uVar8 < uVar3) {
        uVar3 = (uVar3 - uVar8) + 0xff >> 8;
        puVar6 = puVar9;
        do {
          *puVar6 = uVar8;
          uVar8 = uVar8 + 0x100;
          puVar6 = puVar6 + 1;
          uVar3 = uVar3 - 1;
        } while (uVar3 != 0);
      }
      if (((*(char *)(glContext + 0x4e18) == '\0') ||
          (uVar7 = ((int (*)())_gleClipLinesPlane)(glContext,puVar9,uVar7,dVar10), uVar7 != 0)) &&
         (((uVar4 & 0xff) == 0 ||
          (uVar7 = ((int (*)())_gleClipLines)(glContext,puVar9,uVar7,uVar4 & 0xff), uVar7 != 0)))) {
        if ((bVar2) && (*(char *)(glContext + 0x30aa) != '\0')) {
          (**(code **)(glContext + 0x4df0))(glContext,puVar9,uVar7);
        }
        dVar10 = DOUBLE_00108d70;
        if (1 < (int)uVar7) {
          puVar6 = puVar9 + 2;
          ((void (*)())_gleFeedbackToken)(glContext,(double)(float)(4503599627372295.0 - DOUBLE_00108d70));
          _gleFeedbackHitRecord(glContext,*puVar9);
          _gleFeedbackHitRecord(glContext,puVar9[1]);
          if (puVar6 < puVar9 + (uVar7 - 1)) {
            do {
              ((void (*)())_gleFeedbackToken)(glContext,(double)(float)(4503599627372295.0 - dVar10));
              _gleFeedbackHitRecord(glContext,*puVar6);
              puVar1 = puVar6 + 1;
              puVar6 = puVar6 + 2;
              _gleFeedbackHitRecord(glContext,*puVar1);
            } while (puVar6 < puVar9 + (uVar7 - 1));
          }
        }
        return;
      }
    }
  }
  return;
}

/* _gleFeedbackLineStripFunc_body @ 0xd811c (828 bytes) */
void _gleFeedbackLineStripFunc_body(glContext, unusedArg2, unusedArg3)
  int glContext;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  undefined4 uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  double dVar11;
  double f1AfterCall;
  
  bVar5 = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    bVar5 = true;
  }
  uVar9 = *(uint *)(glContext + 0x4854);
  if (((int)*(short *)(glContext + 0x487c) != 0) &&
     (uVar8 = (*(int *)(glContext + 0x4858) - uVar9) / (uint)(int)*(short *)(glContext + 0x487c),
     1 < (int)uVar8)) {
    bVar5 = !bVar5;
    if (bVar5) {
      uVar4 = (**(code **)(glContext + 0x5060))(glContext,uVar9,uVar8);
    }
    else {
      uVar4 = _gleVPEmulate(glContext,uVar8);
    }
    if ((uVar4 & 0xff00) == 0) {
      if (bVar5) {
        if (*(char *)(glContext + 0x53e4) != '\0') {
          (**(code **)(glContext + 0x53dc))(glContext,uVar9,uVar8);
        }
        if (*(char *)(glContext + 0x50b4) != '\0') {
          (**(code **)(glContext + 0x5064))(glContext,uVar9,uVar8);
        }
        if ((*(char *)(glContext + 0x30aa) != '\0') || (*(char *)(glContext + 0x53e6) != '\0')) {
          (**(code **)(glContext + 0x5068))(glContext,uVar9,uVar8);
        }
      }
      else {
        uVar9 = *(uint *)(glContext + 0x4864);
      }
      if (((uVar4 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
        if ((bVar5) && (*(char *)(glContext + 0x53e5) != '\0')) {
          (**(code **)(glContext + 0x53e0))(glContext,uVar9,uVar8);
        }
        (**(code **)(glContext + 0x506c))(glContext,uVar9,uVar8,0);
        if ((bVar5) && (*(char *)(glContext + 0x30aa) != '\0')) {
          (**(code **)(glContext + 0x4de8))(glContext,uVar9,uVar8);
        }
        dVar11 = DOUBLE_00108d70;
        bVar5 = *(char *)(glContext + 0x4a18) == '\0';
        if (1 < (int)uVar8) {
          if (bVar5) {
            if (bVar5) {
              uVar2 = 0x707;
              uVar6 = 0x702;
            }
            else {
              uVar6 = 0x707;
              uVar2 = 0x707;
            }
          }
          else {
            uVar6 = 0x702;
            uVar2 = 0x702;
          }
          uVar4 = uVar9 + 0x100;
          ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,uVar2) -
                                                   DOUBLE_00108d70));
          _gleFeedbackHitRecord(glContext,uVar9);
          _gleFeedbackHitRecord(glContext,uVar4);
          uVar9 = (uVar9 + uVar8 * 0x100) - 0x100;
          if (uVar4 < uVar9) {
            do {
              uVar8 = uVar4 + 0x100;
              ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,uVar6) - dVar11)
                               );
              _gleFeedbackHitRecord(glContext,uVar4);
              _gleFeedbackHitRecord(glContext,uVar8);
              uVar4 = uVar8;
            } while (uVar8 < uVar9);
          }
        }
        return;
      }
      if ((bVar5) && (*(char *)(glContext + 0x53e5) != '\0')) {
        (**(code **)(glContext + 0x53e0))(glContext,uVar9,uVar8);
      }
      dVar11 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, uVar9, uVar8, 0);
      puVar7 = *(uint **)(glContext + 0x4870);
      iVar3 = uVar9 + uVar8 * 0x100;
      puVar10 = puVar7;
      if (bVar5) {
        uVar8 = *(uint *)(glContext + 0x4858);
      }
      else {
        uVar8 = *(uint *)(glContext + 0x4854);
      }
      while (uVar9 < iVar3 - 0x100U) {
        *puVar10 = uVar9;
        _memcpy(uVar8,uVar9 + 0x100,0x100);
        puVar10[1] = uVar8;
        uVar8 = uVar8 + 0x100;
        puVar10 = puVar10 + 2;
        uVar9 = uVar9 + 0x100;
        dVar11 = f1AfterCall;
      }
      iVar3 = (int)puVar10 - (int)puVar7 >> 2;
      if (((*(char *)(glContext + 0x4e18) == '\0') ||
          (iVar3 = ((int (*)())_gleClipLinesPlane)(glContext,puVar7,iVar3,dVar11), iVar3 != 0)) &&
         (((uVar4 & 0xff) == 0 ||
          (iVar3 = ((int (*)())_gleClipLines)(glContext,puVar7,iVar3,uVar4 & 0xff), iVar3 != 0)))) {
        if ((bVar5) && (*(char *)(glContext + 0x30aa) != '\0')) {
          (**(code **)(glContext + 0x4df0))(glContext,puVar7,iVar3);
        }
        dVar11 = DOUBLE_00108d70;
        bVar5 = *(char *)(glContext + 0x4a18) == '\0';
        if (1 < iVar3) {
          if (bVar5) {
            if (bVar5) {
              uVar2 = 0x707;
              uVar6 = 0x702;
            }
            else {
              uVar6 = 0x707;
              uVar2 = 0x707;
            }
          }
          else {
            uVar6 = 0x702;
            uVar2 = 0x702;
          }
          puVar10 = puVar7 + 2;
          ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,uVar2) -
                                                   DOUBLE_00108d70));
          _gleFeedbackHitRecord(glContext,*puVar7);
          _gleFeedbackHitRecord(glContext,puVar7[1]);
          if (puVar10 < puVar7 + iVar3 + -1) {
            do {
              ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,uVar6) - dVar11)
                               );
              _gleFeedbackHitRecord(glContext,*puVar10);
              puVar1 = puVar10 + 1;
              puVar10 = puVar10 + 2;
              _gleFeedbackHitRecord(glContext,*puVar1);
            } while (puVar10 < puVar7 + iVar3 + -1);
          }
        }
        return;
      }
    }
  }
  return;
}

/* _gleFeedbackLineLoopFunc_body @ 0xd845c (932 bytes) */
void _gleFeedbackLineLoopFunc_body(glContext)
  int glContext;
{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  short sVar9;
  undefined4 uVar10;
  uint *puVar11;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  double dVar15;
  double f1AfterCall;
  
  bVar6 = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    bVar6 = true;
  }
  sVar9 = *(short *)(glContext + 0x487c);
  uVar12 = *(uint *)(glContext + 0x4854);
  if ((int)sVar9 != 0) {
    iVar7 = *(int *)(glContext + 0x4858);
    uVar14 = (iVar7 - uVar12) / (uint)(int)sVar9;
    if (*(short *)(glContext + 0x4a10) < 0) {
      if ((int)uVar14 < 1) {
        return;
      }
      uVar5 = uVar12 - 0x100;
      if (*(char *)(glContext + 0x4a18) == '\0') {
        uVar5 = uVar12;
      }
      iVar8 = 0;
      iVar4 = (int)sVar9 >> 3;
      if (0 < iVar4) {
        do {
          iVar2 = iVar8 * 8;
          iVar8 = iVar8 + 1;
          *(undefined8 *)(iVar2 + iVar7) = *(undefined8 *)(iVar2 + uVar5);
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        sVar9 = *(short *)(glContext + 0x487c);
      }
      uVar14 = uVar14 + 1;
      *(int *)(glContext + 0x4858) = iVar7 + sVar9;
    }
    bVar6 = !bVar6;
    if (bVar6) {
      uVar5 = (**(code **)(glContext + 0x5060))(glContext,uVar12,uVar14);
    }
    else {
      uVar5 = _gleVPEmulate(glContext,uVar14);
    }
    if ((uVar5 & 0xff00) == 0) {
      if (bVar6) {
        if (*(char *)(glContext + 0x53e4) != '\0') {
          (**(code **)(glContext + 0x53dc))(glContext,uVar12,uVar14);
        }
        if (*(char *)(glContext + 0x50b4) != '\0') {
          (**(code **)(glContext + 0x5064))(glContext,uVar12,uVar14);
        }
        if ((*(char *)(glContext + 0x30aa) != '\0') || (*(char *)(glContext + 0x53e6) != '\0')) {
          (**(code **)(glContext + 0x5068))(glContext,uVar12,uVar14);
        }
      }
      else {
        uVar12 = *(uint *)(glContext + 0x4864);
      }
      if (((uVar5 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
        if ((bVar6) && (*(char *)(glContext + 0x53e5) != '\0')) {
          (**(code **)(glContext + 0x53e0))(glContext,uVar12,uVar14);
        }
        (**(code **)(glContext + 0x506c))(glContext,uVar12,uVar14,0);
        if ((bVar6) && (*(char *)(glContext + 0x30aa) != '\0')) {
          (**(code **)(glContext + 0x4de8))(glContext,uVar12,uVar14);
        }
        dVar15 = DOUBLE_00108d70;
        bVar6 = *(char *)(glContext + 0x4a18) == '\0';
        if (1 < (int)uVar14) {
          if (bVar6) {
            if (bVar6) {
              uVar3 = 0x707;
              uVar10 = 0x702;
            }
            else {
              uVar10 = 0x707;
              uVar3 = 0x707;
            }
          }
          else {
            uVar10 = 0x702;
            uVar3 = 0x702;
          }
          uVar5 = uVar12 + 0x100;
          ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,uVar3) -
                                                   DOUBLE_00108d70));
          _gleFeedbackHitRecord(glContext,uVar12);
          _gleFeedbackHitRecord(glContext,uVar5);
          uVar12 = (uVar12 + uVar14 * 0x100) - 0x100;
          if (uVar5 < uVar12) {
            do {
              uVar14 = uVar5 + 0x100;
              ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,uVar10) - dVar15
                                                       ));
              _gleFeedbackHitRecord(glContext,uVar5);
              _gleFeedbackHitRecord(glContext,uVar14);
              uVar5 = uVar14;
            } while (uVar14 < uVar12);
          }
        }
        return;
      }
      if ((bVar6) && (*(char *)(glContext + 0x53e5) != '\0')) {
        (**(code **)(glContext + 0x53e0))(glContext,uVar12,uVar14);
      }
      dVar15 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, uVar12, uVar14, 0);
      puVar11 = *(uint **)(glContext + 0x4870);
      iVar7 = uVar12 + uVar14 * 0x100;
      puVar13 = puVar11;
      if (bVar6) {
        uVar14 = *(uint *)(glContext + 0x4858);
      }
      else {
        uVar14 = *(uint *)(glContext + 0x4854);
      }
      while (uVar12 < iVar7 - 0x100U) {
        *puVar13 = uVar12;
        _memcpy(uVar14,uVar12 + 0x100,0x100);
        puVar13[1] = uVar14;
        uVar14 = uVar14 + 0x100;
        puVar13 = puVar13 + 2;
        uVar12 = uVar12 + 0x100;
        dVar15 = f1AfterCall;
      }
      iVar7 = (int)puVar13 - (int)puVar11 >> 2;
      if (((*(char *)(glContext + 0x4e18) == '\0') ||
          (iVar7 = ((int (*)())_gleClipLinesPlane)(glContext,puVar11,iVar7,dVar15), iVar7 != 0)) &&
         (((uVar5 & 0xff) == 0 ||
          (iVar7 = ((int (*)())_gleClipLines)(glContext,puVar11,iVar7,uVar5 & 0xff), iVar7 != 0)))) {
        if ((bVar6) && (*(char *)(glContext + 0x30aa) != '\0')) {
          (**(code **)(glContext + 0x4df0))(glContext,puVar11,iVar7);
        }
        dVar15 = DOUBLE_00108d70;
        bVar6 = *(char *)(glContext + 0x4a18) == '\0';
        if (1 < iVar7) {
          if (bVar6) {
            if (bVar6) {
              uVar3 = 0x707;
              uVar10 = 0x702;
            }
            else {
              uVar10 = 0x707;
              uVar3 = 0x707;
            }
          }
          else {
            uVar10 = 0x702;
            uVar3 = 0x702;
          }
          puVar13 = puVar11 + 2;
          ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,uVar3) -
                                                   DOUBLE_00108d70));
          _gleFeedbackHitRecord(glContext,*puVar11);
          _gleFeedbackHitRecord(glContext,puVar11[1]);
          if (puVar13 < puVar11 + iVar7 + -1) {
            do {
              ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,uVar10) - dVar15
                                                       ));
              _gleFeedbackHitRecord(glContext,*puVar13);
              puVar1 = puVar13 + 1;
              puVar13 = puVar13 + 2;
              _gleFeedbackHitRecord(glContext,*puVar1);
            } while (puVar13 < puVar11 + iVar7 + -1);
          }
        }
        return;
      }
    }
  }
  return;
}

/* _gleRenderSmoothLinesFunc_body @ 0xd8828 (716 bytes) */
void _gleRenderSmoothLinesFunc_body(glContext)
  int glContext;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  double f1AfterCall;
  double fparam_1;
  
  iVar3 = _gleTexEnableBits(glContext);
  uVar6 = *(uint *)(glContext + 0x4854);
  iVar8 = (int)(*(int *)(glContext + 0x4858) - uVar6) >> 8;
  if ((1 < iVar8) &&
     (uVar4 = (**(code **)(glContext + 0x5060))(glContext,uVar6,iVar8), (uVar4 & 0xff00) == 0)) {
    bVar1 = iVar3 != 0;
    fparam_1 = f1AfterCall;
    if ((bVar1) && (*(char *)(glContext + 0x53e4) != '\0')) {
      fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, uVar6, iVar8);
    }
    if (*(char *)(glContext + 0x50b4) != '\0') {
      fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, uVar6, iVar8);
    }
    if ((*(char *)(glContext + 0x30aa) != '\0') || ((bVar1 && (*(char *)(glContext + 0x53e6) != '\0'))))
    {
      fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, uVar6, iVar8);
    }
    if (((uVar4 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (bVar1) {
        if (*(char *)(glContext + 0x53e5) != '\0') {
          (**(code **)(glContext + 0x53e0))(glContext,uVar6,iVar8);
        }
        (**(code **)(glContext + 0x506c))(glContext,uVar6,iVar8,0);
      }
      if (*(char *)(glContext + 0x30aa) != '\0') {
        (**(code **)(glContext + 0x4de8))(glContext,uVar6,iVar8);
      }
                    
                    
      (**(code **)(glContext + 0x46b4))(*(undefined4 *)(glContext + 0x4688),uVar6,iVar8);
      return;
    }
    if (bVar1) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,uVar6,iVar8);
      }
      fparam_1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, uVar6, iVar8, 0);
    }
    uVar2 = uVar6 + iVar8 * 0x100;
    puVar7 = *(uint **)(glContext + 0x4870);
    if (uVar6 < uVar2) {
      uVar2 = (uVar2 - uVar6) + 0xff >> 8;
      puVar5 = puVar7;
      do {
        *puVar5 = uVar6;
        uVar6 = uVar6 + 0x100;
        puVar5 = puVar5 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    if ((*(char *)(glContext + 0x4e18) != '\0') &&
       (iVar8 = ((int (*)())_gleClipLinesPlane)(glContext,puVar7,iVar8,fparam_1), iVar8 == 0)) {
      return;
    }
    if (((uVar4 & 0xff) == 0) ||
       (iVar8 = ((int (*)())_gleClipLines)(glContext,puVar7,iVar8,uVar4 & 0xff), iVar8 != 0)) {
      if (*(char *)(glContext + 0x30aa) != '\0') {
        (**(code **)(glContext + 0x4df0))(glContext,puVar7,iVar8);
      }
                    
                    
      (**(code **)(glContext + 0x46dc))(*(undefined4 *)(glContext + 0x4688),puVar7,iVar8,2);
      return;
    }
  }
  return;
}

/* _gleRenderSmoothLineStripFunc_body @ 0xd8af8 (728 bytes) */
void _gleRenderSmoothLineStripFunc_body(glContext)
  int glContext;
{
  bool bVar1;
  char cVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  double f1AfterCall;
  double fparam_1;
  double f1AfterCall1;
  
  iVar4 = _gleTexEnableBits(glContext);
  puVar8 = *(uint **)(glContext + 0x4854);
  iVar9 = *(int *)(glContext + 0x4858) - (int)puVar8 >> 8;
  if ((iVar9 < 2) ||
     (uVar5 = (**(code **)(glContext + 0x5060))(glContext,puVar8,iVar9), (uVar5 & 0xff00) != 0)) {
    return;
  }
  bVar1 = iVar4 != 0;
  fparam_1 = f1AfterCall;
  if ((bVar1) && (*(char *)(glContext + 0x53e4) != '\0')) {
    fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, puVar8, iVar9);
  }
  if (*(char *)(glContext + 0x50b4) != '\0') {
    fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, puVar8, iVar9);
  }
  if ((*(char *)(glContext + 0x30aa) != '\0') || ((bVar1 && (*(char *)(glContext + 0x53e6) != '\0')))) {
    fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, puVar8, iVar9);
  }
  if (((uVar5 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
    if (bVar1) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,puVar8,iVar9);
      }
      (**(code **)(glContext + 0x506c))(glContext,puVar8,iVar9,0);
    }
    if (*(char *)(glContext + 0x30aa) != '\0') {
      (**(code **)(glContext + 0x4de8))(glContext,puVar8,iVar9);
    }
    cVar2 = *(char *)(glContext + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46b8);
    puVar6 = puVar8;
  }
  else {
    if (bVar1) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,puVar8,iVar9);
      }
      fparam_1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, puVar8, iVar9, 0);
    }
    puVar6 = *(uint **)(glContext + 0x4870);
    uVar10 = *(uint *)(glContext + 0x4858);
    puVar3 = puVar8;
    puVar7 = puVar6;
    while (puVar3 < puVar8 + iVar9 * 0x40 + -0x40) {
      *puVar7 = (uint)puVar3;
      _memcpy(uVar10,puVar3 + 0x40,0x100);
      puVar7[1] = uVar10;
      uVar10 = uVar10 + 0x100;
      puVar7 = puVar7 + 2;
      puVar3 = puVar3 + 0x40;
      fparam_1 = f1AfterCall1;
    }
    iVar9 = (int)puVar7 - (int)puVar6 >> 2;
    if ((*(char *)(glContext + 0x4e18) != '\0') &&
       (iVar9 = ((int (*)())_gleClipLinesPlane)(glContext,puVar6,iVar9,fparam_1), iVar9 == 0)) {
      return;
    }
    if (((uVar5 & 0xff) != 0) &&
       (iVar9 = ((int (*)())_gleClipLines)(glContext,puVar6,iVar9,uVar5 & 0xff), iVar9 == 0)) {
      return;
    }
    if (*(char *)(glContext + 0x30aa) != '\0') {
      (**(code **)(glContext + 0x4df0))(glContext,puVar6,iVar9);
    }
    cVar2 = *(char *)(glContext + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46dc);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(glContext + 0x4688),puVar6,iVar9,cVar2 == '\0');
  return;
}

/* _gleRenderSmoothLineLoopFunc_body @ 0xd8dd4 (824 bytes) */
void _gleRenderSmoothLineLoopFunc_body(glContext)
  int glContext;
{
  bool bVar1;
  char cVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  code *UNRECOVERED_JUMPTABLE;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  int iVar13;
  uint uVar14;
  double f1AfterCall;
  double fparam_1;
  double f1AfterCall1;
  
  iVar5 = _gleTexEnableBits(glContext);
  puVar12 = *(uint **)(glContext + 0x4854);
  iVar8 = *(int *)(glContext + 0x4858);
  iVar13 = iVar8 - (int)puVar12 >> 8;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (iVar13 < 1) {
      return;
    }
    puVar7 = puVar12 + -0x40;
    if (*(char *)(glContext + 0x4a18) == '\0') {
      puVar7 = puVar12;
    }
    sVar4 = *(short *)(glContext + 0x487c);
    iVar9 = 0;
    iVar3 = (int)sVar4 >> 3;
    if (0 < iVar3) {
      do {
        *(undefined8 *)(iVar9 * 8 + iVar8) = *(undefined8 *)(puVar7 + iVar9 * 2);
        iVar3 = iVar3 + -1;
        iVar9 = iVar9 + 1;
      } while (iVar3 != 0);
      sVar4 = *(short *)(glContext + 0x487c);
    }
    iVar13 = iVar13 + 1;
    *(int *)(glContext + 0x4858) = iVar8 + sVar4;
  }
  uVar6 = (**(code **)(glContext + 0x5060))(glContext,puVar12,iVar13);
  if ((uVar6 & 0xff00) != 0) {
    return;
  }
  bVar1 = iVar5 != 0;
  fparam_1 = f1AfterCall;
  if ((bVar1) && (*(char *)(glContext + 0x53e4) != '\0')) {
    fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, puVar12, iVar13);
  }
  if (*(char *)(glContext + 0x50b4) != '\0') {
    fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, puVar12, iVar13);
  }
  if ((*(char *)(glContext + 0x30aa) != '\0') || ((bVar1 && (*(char *)(glContext + 0x53e6) != '\0')))) {
    fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, puVar12, iVar13);
  }
  if (((uVar6 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
    if (bVar1) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,puVar12,iVar13);
      }
      (**(code **)(glContext + 0x506c))(glContext,puVar12,iVar13,0);
    }
    if (*(char *)(glContext + 0x30aa) != '\0') {
      (**(code **)(glContext + 0x4de8))(glContext,puVar12,iVar13);
    }
    cVar2 = *(char *)(glContext + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46b8);
    puVar10 = puVar12;
  }
  else {
    if (bVar1) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,puVar12,iVar13);
      }
      fparam_1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, puVar12, iVar13, 0);
    }
    puVar10 = *(uint **)(glContext + 0x4870);
    uVar14 = *(uint *)(glContext + 0x4858);
    puVar7 = puVar12;
    puVar11 = puVar10;
    while (puVar7 < puVar12 + iVar13 * 0x40 + -0x40) {
      *puVar11 = (uint)puVar7;
      _memcpy(uVar14,puVar7 + 0x40,0x100);
      puVar11[1] = uVar14;
      uVar14 = uVar14 + 0x100;
      puVar11 = puVar11 + 2;
      puVar7 = puVar7 + 0x40;
      fparam_1 = f1AfterCall1;
    }
    iVar13 = (int)puVar11 - (int)puVar10 >> 2;
    if ((*(char *)(glContext + 0x4e18) != '\0') &&
       (iVar13 = ((int (*)())_gleClipLinesPlane)(glContext,puVar10,iVar13,fparam_1), iVar13 == 0)) {
      return;
    }
    if (((uVar6 & 0xff) != 0) &&
       (iVar13 = ((int (*)())_gleClipLines)(glContext,puVar10,iVar13,uVar6 & 0xff), iVar13 == 0)) {
      return;
    }
    if (*(char *)(glContext + 0x30aa) != '\0') {
      (**(code **)(glContext + 0x4df0))(glContext,puVar10,iVar13);
    }
    cVar2 = *(char *)(glContext + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46dc);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(glContext + 0x4688),puVar10,iVar13,cVar2 == '\0');
  return;
}

/* _gleRenderFlatLinesFunc_body @ 0xd9110 (780 bytes) */
void _gleRenderFlatLinesFunc_body(glContext)
  int glContext;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  double f1AfterCall;
  double fparam_1;
  
  iVar2 = _gleTexEnableBits(glContext);
  uVar7 = *(uint *)(glContext + 0x4854);
  iVar6 = (int)(*(int *)(glContext + 0x4858) - uVar7) >> 8;
  if ((1 < iVar6) &&
     (uVar3 = (**(code **)(glContext + 0x5060))(glContext,uVar7,iVar6), (uVar3 & 0xff00) == 0)) {
    bVar1 = iVar2 != 0;
    fparam_1 = f1AfterCall;
    if ((bVar1) && (*(char *)(glContext + 0x53e4) != '\0')) {
      fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, uVar7, iVar6);
    }
    if (*(char *)(glContext + 0x50b4) != '\0') {
      fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, uVar7, iVar6);
    }
    if ((*(char *)(glContext + 0x30aa) != '\0') || ((bVar1 && (*(char *)(glContext + 0x53e6) != '\0'))))
    {
      fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, uVar7, iVar6);
    }
    if (((uVar3 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (bVar1) {
        if (*(char *)(glContext + 0x53e5) != '\0') {
          (**(code **)(glContext + 0x53e0))(glContext,uVar7,iVar6);
        }
        (**(code **)(glContext + 0x506c))(glContext,uVar7,iVar6,0);
      }
      if (*(char *)(glContext + 0x30aa) != '\0') {
        for (uVar3 = uVar7 + 0x100; uVar3 < uVar7 + iVar6 * 0x100; uVar3 = uVar3 + 0x200) {
          (**(code **)(glContext + 0x4de8))(glContext,uVar3,1);
        }
      }
                    
                    
      (**(code **)(glContext + 0x46b4))(*(undefined4 *)(glContext + 0x4688),uVar7,iVar6);
      return;
    }
    if (bVar1) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,uVar7,iVar6);
      }
      fparam_1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, uVar7, iVar6, 0);
    }
    puVar4 = *(uint **)(glContext + 0x4870);
    uVar5 = uVar7 + iVar6 * 0x100;
    if (uVar7 < uVar5) {
      uVar5 = (uVar5 - uVar7) + 0xff >> 8;
      puVar8 = puVar4;
      do {
        *puVar8 = uVar7;
        uVar7 = uVar7 + 0x100;
        puVar8 = puVar8 + 1;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    if (((*(char *)(glContext + 0x4e18) == '\0') ||
        (iVar6 = ((int (*)())_gleClipLinesPlane)(glContext,puVar4,iVar6,fparam_1), iVar6 != 0)) &&
       (((uVar3 & 0xff) == 0 ||
        (iVar6 = ((int (*)())_gleClipLines)(glContext,puVar4,iVar6,uVar3 & 0xff), iVar6 != 0)))) {
      if (*(char *)(glContext + 0x30aa) != '\0') {
        for (puVar8 = puVar4 + 1; puVar8 < puVar4 + iVar6; puVar8 = puVar8 + 2) {
          (**(code **)(glContext + 0x4df0))(glContext,puVar8,1);
        }
      }
                    
                    
      (**(code **)(glContext + 0x46dc))(*(undefined4 *)(glContext + 0x4688),puVar4,iVar6,2);
      return;
    }
  }
  return;
}

/* _gleRenderFlatLineStripFunc_body @ 0xd9420 (760 bytes) */
void _gleRenderFlatLineStripFunc_body(glContext)
  int glContext;
{
  bool bVar1;
  char cVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  double f1AfterCall;
  double fparam_1;
  double f1AfterCall1;
  
  iVar4 = _gleTexEnableBits(glContext);
  puVar9 = *(uint **)(glContext + 0x4854);
  iVar7 = *(int *)(glContext + 0x4858) - (int)puVar9 >> 8;
  if ((iVar7 < 2) ||
     (uVar5 = (**(code **)(glContext + 0x5060))(glContext,puVar9,iVar7), (uVar5 & 0xff00) != 0)) {
    return;
  }
  bVar1 = iVar4 != 0;
  fparam_1 = f1AfterCall;
  if ((bVar1) && (*(char *)(glContext + 0x53e4) != '\0')) {
    fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, puVar9, iVar7);
  }
  if (*(char *)(glContext + 0x50b4) != '\0') {
    fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, puVar9, iVar7);
  }
  if ((*(char *)(glContext + 0x30aa) != '\0') || ((bVar1 && (*(char *)(glContext + 0x53e6) != '\0')))) {
    fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, puVar9, iVar7);
  }
  if (((uVar5 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
    if (bVar1) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,puVar9,iVar7);
      }
      (**(code **)(glContext + 0x506c))(glContext,puVar9,iVar7,0);
    }
    if (*(char *)(glContext + 0x30aa) != '\0') {
      (**(code **)(glContext + 0x4de8))(glContext,puVar9 + 0x40,iVar7 + -1);
    }
    cVar2 = *(char *)(glContext + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46b8);
    puVar6 = puVar9;
  }
  else {
    if (bVar1) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,puVar9,iVar7);
      }
      fparam_1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, puVar9, iVar7, 0);
    }
    puVar6 = *(uint **)(glContext + 0x4870);
    uVar8 = *(uint *)(glContext + 0x4858);
    puVar3 = puVar9;
    puVar10 = puVar6;
    while (puVar3 < puVar9 + iVar7 * 0x40 + -0x40) {
      *puVar10 = (uint)puVar3;
      _memcpy(uVar8,puVar3 + 0x40,0x100);
      puVar10[1] = uVar8;
      uVar8 = uVar8 + 0x100;
      puVar10 = puVar10 + 2;
      puVar3 = puVar3 + 0x40;
      fparam_1 = f1AfterCall1;
    }
    iVar7 = (int)puVar10 - (int)puVar6 >> 2;
    if ((*(char *)(glContext + 0x4e18) != '\0') &&
       (iVar7 = ((int (*)())_gleClipLinesPlane)(glContext,puVar6,iVar7,fparam_1), iVar7 == 0)) {
      return;
    }
    if (((uVar5 & 0xff) != 0) &&
       (iVar7 = ((int (*)())_gleClipLines)(glContext,puVar6,iVar7,uVar5 & 0xff), iVar7 == 0)) {
      return;
    }
    if (*(char *)(glContext + 0x30aa) != '\0') {
      for (puVar9 = puVar6 + 1; puVar9 < puVar6 + iVar7; puVar9 = puVar9 + 2) {
        (**(code **)(glContext + 0x4df0))(glContext,puVar9,1);
      }
    }
    cVar2 = *(char *)(glContext + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46dc);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(glContext + 0x4688),puVar6,iVar7,cVar2 == '\0');
  return;
}

/* _gleRenderFlatLineLoopFunc_body @ 0xd971c (856 bytes) */
void _gleRenderFlatLineLoopFunc_body(glContext)
  int glContext;
{
  bool bVar1;
  char cVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  code *UNRECOVERED_JUMPTABLE;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  double f1AfterCall;
  double fparam_1;
  double f1AfterCall1;
  
  iVar5 = _gleTexEnableBits(glContext);
  puVar13 = *(uint **)(glContext + 0x4854);
  iVar8 = *(int *)(glContext + 0x4858);
  iVar12 = iVar8 - (int)puVar13 >> 8;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (iVar12 < 1) {
      return;
    }
    puVar7 = puVar13 + -0x40;
    if (*(char *)(glContext + 0x4a18) == '\0') {
      puVar7 = puVar13;
    }
    sVar4 = *(short *)(glContext + 0x487c);
    iVar9 = 0;
    iVar3 = (int)sVar4 >> 3;
    if (0 < iVar3) {
      do {
        *(undefined8 *)(iVar9 * 8 + iVar8) = *(undefined8 *)(puVar7 + iVar9 * 2);
        iVar3 = iVar3 + -1;
        iVar9 = iVar9 + 1;
      } while (iVar3 != 0);
      sVar4 = *(short *)(glContext + 0x487c);
    }
    iVar12 = iVar12 + 1;
    *(int *)(glContext + 0x4858) = iVar8 + sVar4;
  }
  uVar6 = (**(code **)(glContext + 0x5060))(glContext,puVar13,iVar12);
  if ((uVar6 & 0xff00) != 0) {
    return;
  }
  bVar1 = iVar5 != 0;
  fparam_1 = f1AfterCall;
  if ((bVar1) && (*(char *)(glContext + 0x53e4) != '\0')) {
    fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, puVar13, iVar12);
  }
  if (*(char *)(glContext + 0x50b4) != '\0') {
    fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, puVar13, iVar12);
  }
  if ((*(char *)(glContext + 0x30aa) != '\0') || ((bVar1 && (*(char *)(glContext + 0x53e6) != '\0')))) {
    fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, puVar13, iVar12);
  }
  if (((uVar6 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
    if (bVar1) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,puVar13,iVar12);
      }
      (**(code **)(glContext + 0x506c))(glContext,puVar13,iVar12,0);
    }
    if (*(char *)(glContext + 0x30aa) != '\0') {
      (**(code **)(glContext + 0x4de8))(glContext,puVar13 + 0x40,iVar12 + -1);
    }
    cVar2 = *(char *)(glContext + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46b8);
    puVar10 = puVar13;
  }
  else {
    if (bVar1) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,puVar13,iVar12);
      }
      fparam_1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, puVar13, iVar12, 0);
    }
    puVar10 = *(uint **)(glContext + 0x4870);
    uVar11 = *(uint *)(glContext + 0x4858);
    puVar7 = puVar13;
    puVar14 = puVar10;
    while (puVar7 < puVar13 + iVar12 * 0x40 + -0x40) {
      *puVar14 = (uint)puVar7;
      _memcpy(uVar11,puVar7 + 0x40,0x100);
      puVar14[1] = uVar11;
      uVar11 = uVar11 + 0x100;
      puVar14 = puVar14 + 2;
      puVar7 = puVar7 + 0x40;
      fparam_1 = f1AfterCall1;
    }
    iVar12 = (int)puVar14 - (int)puVar10 >> 2;
    if ((*(char *)(glContext + 0x4e18) != '\0') &&
       (iVar12 = ((int (*)())_gleClipLinesPlane)(glContext,puVar10,iVar12,fparam_1), iVar12 == 0)) {
      return;
    }
    if (((uVar6 & 0xff) != 0) &&
       (iVar12 = ((int (*)())_gleClipLines)(glContext,puVar10,iVar12,uVar6 & 0xff), iVar12 == 0)) {
      return;
    }
    if (*(char *)(glContext + 0x30aa) != '\0') {
      for (puVar13 = puVar10 + 1; puVar13 < puVar10 + iVar12; puVar13 = puVar13 + 2) {
        (**(code **)(glContext + 0x4df0))(glContext,puVar13,1);
      }
    }
    cVar2 = *(char *)(glContext + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46dc);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(glContext + 0x4688),puVar10,iVar12,cVar2 == '\0');
  return;
}

/* _gleSelectLinesFunc @ 0xd9a74 (412 bytes) */
void _gleSelectLinesFunc(glContext)
  int glContext;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  double f1AfterCall;
  double dVar8;
  
  bVar1 = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    bVar1 = true;
  }
  uVar6 = *(uint *)(glContext + 0x4854);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (uVar5 = (*(int *)(glContext + 0x4858) - uVar6) / (uint)(int)*(short *)(glContext + 0x487c),
      1 < (int)uVar5)) &&
     (uVar3 = (**(code **)(glContext + 0x5060))(glContext,uVar6,uVar5), (uVar3 & 0xff00) == 0)) {
    dVar8 = f1AfterCall;
    if (bVar1) {
      uVar6 = *(uint *)(glContext + 0x4864);
    }
    else if (*(char *)(glContext + 0x4e18) != '\0') {
      dVar8 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, uVar6, uVar5);
    }
    if (((uVar3 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      _gleSelectLines(glContext,uVar6,uVar5);
      return;
    }
    uVar2 = uVar6 + uVar5 * 0x100;
    puVar7 = *(uint **)(glContext + 0x4870);
    if (uVar6 < uVar2) {
      uVar2 = (uVar2 - uVar6) + 0xff >> 8;
      puVar4 = puVar7;
      do {
        *puVar4 = uVar6;
        uVar6 = uVar6 + 0x100;
        puVar4 = puVar4 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    if ((*(char *)(glContext + 0x4e18) != '\0') &&
       (uVar5 = ((int (*)())_gleClipLinesPlane)(glContext,puVar7,uVar5,dVar8), uVar5 == 0)) {
      return;
    }
    if (((uVar3 & 0xff) == 0) ||
       (uVar5 = ((int (*)())_gleClipLines)(glContext,puVar7,uVar5,uVar3 & 0xff), uVar5 != 0)) {
      _gleSelectLinesPtr(glContext,puVar7,uVar5);
      return;
    }
  }
  return;
}

/* _gleSelectLineStripFunc_body @ 0xd9c14 (484 bytes) */
void _gleSelectLineStripFunc_body(glContext)
  int glContext;
{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  double f1AfterCall;
  double dVar8;
  double f1AfterCall1;
  
  bVar1 = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    bVar1 = true;
  }
  uVar7 = *(uint *)(glContext + 0x4854);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (uVar6 = (*(int *)(glContext + 0x4858) - uVar7) / (uint)(int)*(short *)(glContext + 0x487c),
      1 < (int)uVar6)) &&
     (uVar4 = (**(code **)(glContext + 0x5060))(glContext,uVar7,uVar6), (uVar4 & 0xff00) == 0)) {
    dVar8 = f1AfterCall;
    if (bVar1) {
      uVar7 = *(uint *)(glContext + 0x4864);
    }
    else if (*(char *)(glContext + 0x4e18) != '\0') {
      dVar8 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, uVar7, uVar6);
    }
    if (((uVar4 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      _gleSelectLineStrip(glContext,uVar7,uVar6);
      return;
    }
    puVar5 = *(uint **)(glContext + 0x4870);
    iVar3 = uVar7 + uVar6 * 0x100;
    puVar2 = puVar5;
    if (bVar1) {
      uVar6 = *(uint *)(glContext + 0x4854);
    }
    else {
      uVar6 = *(uint *)(glContext + 0x4858);
    }
    while (uVar7 < iVar3 - 0x100U) {
      *puVar2 = uVar7;
      _memcpy(uVar6,uVar7 + 0x100,0x100);
      puVar2[1] = uVar6;
      uVar6 = uVar6 + 0x100;
      puVar2 = puVar2 + 2;
      uVar7 = uVar7 + 0x100;
      dVar8 = f1AfterCall1;
    }
    iVar3 = (int)puVar2 - (int)puVar5 >> 2;
    if (((*(char *)(glContext + 0x4e18) == '\0') ||
        (iVar3 = ((int (*)())_gleClipLinesPlane)(glContext,puVar5,iVar3,dVar8), iVar3 != 0)) &&
       (((uVar4 & 0xff) == 0 ||
        (iVar3 = ((int (*)())_gleClipLines)(glContext,puVar5,iVar3,uVar4 & 0xff), iVar3 != 0)))) {
      _gleSelectLinesPtr(glContext,puVar5,iVar3);
      return;
    }
  }
  return;
}

/* _gleSelectLineLoopFunc_body @ 0xd9dfc (588 bytes) */
void _gleSelectLineLoopFunc_body(glContext)
  int glContext;
{
  int iVar1;
  bool bVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  short sVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  double f1AfterCall;
  double dVar12;
  double f1AfterCall1;
  
  bVar2 = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    bVar2 = true;
  }
  sVar7 = *(short *)(glContext + 0x487c);
  uVar10 = *(uint *)(glContext + 0x4854);
  if ((int)sVar7 != 0) {
    iVar6 = *(int *)(glContext + 0x4858);
    uVar11 = (iVar6 - uVar10) / (uint)(int)sVar7;
    if (*(short *)(glContext + 0x4a10) < 0) {
      if ((int)uVar11 < 1) {
        return;
      }
      uVar5 = uVar10 - 0x100;
      if (*(char *)(glContext + 0x4a18) == '\0') {
        uVar5 = uVar10;
      }
      iVar8 = 0;
      iVar4 = (int)sVar7 >> 3;
      if (0 < iVar4) {
        do {
          iVar1 = iVar8 * 8;
          iVar8 = iVar8 + 1;
          *(undefined8 *)(iVar1 + iVar6) = *(undefined8 *)(iVar1 + uVar5);
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        sVar7 = *(short *)(glContext + 0x487c);
      }
      uVar11 = uVar11 + 1;
      *(int *)(glContext + 0x4858) = iVar6 + sVar7;
    }
    uVar5 = (**(code **)(glContext + 0x5060))(glContext,uVar10,uVar11);
    if ((uVar5 & 0xff00) == 0) {
      dVar12 = f1AfterCall;
      if (bVar2) {
        uVar10 = *(uint *)(glContext + 0x4864);
      }
      else if (*(char *)(glContext + 0x4e18) != '\0') {
        dVar12 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, uVar10, uVar11);
      }
      if (((uVar5 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
        _gleSelectLineStrip(glContext,uVar10,uVar11);
        return;
      }
      puVar9 = *(uint **)(glContext + 0x4870);
      iVar6 = uVar10 + uVar11 * 0x100;
      puVar3 = puVar9;
      if (bVar2) {
        uVar11 = *(uint *)(glContext + 0x4854);
      }
      else {
        uVar11 = *(uint *)(glContext + 0x4858);
      }
      while (uVar10 < iVar6 - 0x100U) {
        *puVar3 = uVar10;
        _memcpy(uVar11,uVar10 + 0x100,0x100);
        puVar3[1] = uVar11;
        uVar11 = uVar11 + 0x100;
        puVar3 = puVar3 + 2;
        uVar10 = uVar10 + 0x100;
        dVar12 = f1AfterCall1;
      }
      iVar6 = (int)puVar3 - (int)puVar9 >> 2;
      if (((*(char *)(glContext + 0x4e18) == '\0') ||
          (iVar6 = ((int (*)())_gleClipLinesPlane)(glContext,puVar9,iVar6,dVar12), iVar6 != 0)) &&
         (((uVar5 & 0xff) == 0 ||
          (iVar6 = ((int (*)())_gleClipLines)(glContext,puVar9,iVar6,uVar5 & 0xff), iVar6 != 0)))) {
        _gleSelectLinesPtr(glContext,puVar9,iVar6);
        return;
      }
    }
  }
  return;
}

/* _gleVAClipLine @ 0xda048 (320 bytes) */
int _gleVAClipLine(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int *param_4;
{
  byte bVar2;
  int *piVar1;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  
  iVar6 = *param_4;
  iVar8 = param_4[1];
  bVar10 = *(byte *)(param_3 + iVar6) & 0x3f;
  piVar7 = *(int **)(param_1 + 0x499c);
  bVar9 = *(byte *)(param_3 + iVar8) & 0x3f;
  uVar3 = 0;
  iVar5 = *piVar7;
  iVar4 = piVar7[1];
  if ((bVar10 & bVar9) == 0) {
    bVar2 = bVar10 | bVar9;
    uVar3 = 2;
    if (bVar2 != 0) {
      bVar11 = 1;
      do {
        if ((bVar2 & bVar11) != 0) {
          if ((bVar10 & bVar11) == 0) {
            (**(code **)(param_1 + 0x49c4))(param_1,param_2,param_3,iVar8,iVar6,iVar4,bVar11);
            bVar9 = *(byte *)(param_3 + iVar4);
            iVar8 = iVar4;
          }
          else {
            (**(code **)(param_1 + 0x49c4))(param_1,param_2,param_3,iVar6,iVar8,iVar5,bVar11);
            bVar10 = *(byte *)(param_3 + iVar5);
            iVar6 = iVar5;
          }
          if ((bVar10 & bVar9) != 0) {
            return 0;
          }
          bVar2 = bVar10 | bVar9;
          if (bVar2 == 0) break;
        }
        bVar11 = bVar11 << 1;
      } while (bVar11 < 0x21);
      if (iVar6 == iVar5) {
        piVar1 = piVar7 + 1;
        *param_4 = iVar5;
        if (iVar8 == iVar4) {
          piVar1 = piVar7 + 2;
          param_4[1] = iVar8;
        }
        *(int **)(param_1 + 0x499c) = piVar1;
      }
      else {
        param_4[1] = iVar8;
        piVar7[1] = iVar5;
        *(int **)(param_1 + 0x499c) = piVar7 + 1;
      }
      uVar3 = 2;
    }
  }
  return uVar3;
}

/* _gleVAClipPoly @ 0xda188 (692 bytes) */
int _gleVAClipPoly(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  uint *param_5;
{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  int iVar10;
  byte bVar11;
  uint *puVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  int iVar16;
  undefined4 uStack0000001c;
  uint local_f0 [20];
  uint local_a0 [21];
  
  uVar5 = *(int *)(param_1 + 0x4988) + *(int *)(param_1 + 0x4984);
  bVar11 = 0;
  bVar3 = 0xff;
  puVar12 = *(uint **)(param_1 + 0x499c);
  if (param_5 < param_5 + param_4) {
    uVar15 = (uint)((int)(param_5 + param_4) + (3 - (int)param_5)) >> 2;
    puVar9 = param_5;
    do {
      uVar2 = *puVar9;
      puVar9 = puVar9 + 1;
      bVar3 = bVar3 & *(byte *)(param_3 + uVar2);
      bVar11 = bVar11 | *(byte *)(param_3 + uVar2);
      uVar15 = uVar15 - 1;
    } while (uVar15 != 0);
  }
  iVar4 = 0;
  if (((bVar3 & 0x3f) == 0) && (iVar4 = param_4, (bVar11 & 0xc3) != 0)) {
    puVar13 = param_5 + param_4;
    iVar4 = 0;
    iVar10 = 0;
    bVar3 = 1;
    puVar6 = local_f0;
    puVar8 = param_5;
    puVar9 = local_a0;
    uStack0000001c = param_2;
    do {
      puVar7 = puVar6;
      if ((bVar11 & bVar3) != 0) {
        *puVar13 = *puVar8;
        puVar7 = puVar8 + 1;
        puVar13[1] = *puVar7;
        puVar14 = puVar6;
        for (; puVar7 <= puVar13; puVar7 = puVar7 + 1) {
          uVar15 = *puVar7;
          if (((&_out_codes)[iVar10] & ~*(byte *)(param_3 + uVar15)) == 0) {
            if ((bVar3 & *(byte *)(param_3 + puVar7[1])) == 0) {
              uVar2 = *puVar12;
              puVar12 = puVar12 + 1;
              (**(code **)(param_1 + 0x49c4))
                        (param_1,uStack0000001c,param_3,uVar15,puVar7[1],uVar2,bVar3);
              bVar1 = *(byte *)(param_3 + uVar2);
              *puVar14 = uVar2;
              puVar14 = puVar14 + 1;
              uVar15 = *puVar7;
              bVar11 = bVar11 | bVar1;
            }
            if (uVar5 <= uVar15) {
              *puVar9 = uVar15;
LAB_000da318:
              puVar9 = puVar9 + 1;
            }
          }
          else if ((bVar3 & *(byte *)(param_3 + uVar15)) == 0) {
            *puVar14 = uVar15;
            puVar14 = puVar14 + 1;
            uVar15 = puVar7[1];
            if (((&_out_codes)[iVar10] & ~*(byte *)(param_3 + uVar15)) == 0) {
              uVar2 = *puVar12;
              puVar12 = puVar12 + 1;
              (**(code **)(param_1 + 0x49c4))
                        (param_1,uStack0000001c,param_3,uVar15,*puVar7,uVar2,bVar3);
              bVar1 = *(byte *)(param_3 + uVar2);
              *puVar14 = uVar2;
              bVar11 = bVar11 | bVar1;
LAB_000da384:
              puVar14 = puVar14 + 1;
            }
            else if ((bVar3 & *(byte *)(param_3 + uVar15)) != 0) goto LAB_000da380;
          }
          else if ((bVar3 & *(byte *)(param_3 + puVar7[-1])) != 0) {
            if ((bVar3 & *(byte *)(param_3 + puVar7[1])) == 0) {
LAB_000da380:
              *puVar14 = uVar15;
              goto LAB_000da384;
            }
            if (uVar5 <= uVar15) {
              *puVar9 = uVar15;
              goto LAB_000da318;
            }
          }
        }
        iVar4 = (int)puVar14 - (int)puVar6 >> 2;
        if (local_a0 < puVar9) {
          uVar15 = (uint)((int)puVar9 + (3 - (int)local_a0)) >> 2;
          do {
            puVar9 = puVar9 + -1;
            puVar12 = puVar12 + -1;
            *puVar12 = *puVar9;
            uVar15 = uVar15 - 1;
          } while (uVar15 != 0);
        }
        if (iVar4 < 3) {
          return 0;
        }
        puVar13 = puVar6 + iVar4;
        puVar7 = puVar8;
        puVar8 = puVar6;
      }
      iVar10 = iVar10 + 1;
      bVar3 = bVar3 << 1;
      puVar6 = puVar7;
    } while (iVar10 < 6);
    if ((puVar8 != param_5) && (iVar10 = 0, iVar16 = iVar4, 0 < iVar4)) {
      do {
        param_5[iVar10] = puVar8[iVar10];
        iVar16 = iVar16 + -1;
        iVar10 = iVar10 + 1;
      } while (iVar16 != 0);
    }
    *(uint **)(param_1 + 0x499c) = puVar12;
  }
  return iVar4;
}

/* _gleFlushIndexStack @ 0xda43c (92 bytes) */
void _gleFlushIndexStack(param_1)
  int param_1;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  piVar2 = (int *)(*(int *)(param_1 + 0x49a0) + *(int *)(param_1 + 0x4988) * 4);
  piVar1 = (int *)(*(int *)(param_1 + 0x499c) + 0x48);
  *(int **)(param_1 + 0x499c) = piVar2;
  iVar3 = *(int *)(param_1 + 0x4984) + *(int *)(param_1 + 0x4988);
  if (piVar2 < piVar1) {
    uVar4 = (uint)((int)piVar1 + (3 - (int)piVar2)) >> 2;
    do {
      *piVar2 = iVar3;
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
                    
                    
  (**(code **)(param_1 + 0x47b8))(*(undefined4 *)(param_1 + 0x4688));
  return;
}

/* _gleCompileTCLVertexArray @ 0xda498 (1052 bytes) */
int _gleCompileTCLVertexArray(glContext)
  int glContext;
{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  int *piVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int local_40 [6];
  
  iVar15 = 0;
  if (*(int *)(glContext + 0x49ac) == 0) {
    return glContext;
  }
  iVar16 = *(int *)(glContext + 0x4988);
  uVar14 = *(undefined4 *)(glContext + 0x49a4);
  uVar2 = *(ushort *)(glContext + 0x4990);
  uVar18 = *(uint *)(glContext + 0x4980);
  if (*(short *)(glContext + 0x4992) == 0) {
    uVar18 = uVar18 & 0xffff;
    *(undefined2 *)(glContext + 0x4992) = 1;
  }
  iVar11 = *(int *)(glContext + 0x49a0);
  uVar7 = *(uint *)(glContext + 0x49b0);
  iVar6 = *(int *)(glContext + 0x4994) + (*(int *)(glContext + 0x499c) - iVar11 >> 2);
  if ((uVar18 & 0x10) == 0) {
    if ((uVar18 & 8) == 0) {
      bVar1 = 7 < (uVar7 >> 0xc & 0xf);
    }
    else {
      if (7 < (uVar7 >> 0xc & 0xf)) goto LAB_000da56c;
      bVar1 = 0xb < (uVar7 >> 4 & 0xf);
    }
    if (bVar1) goto LAB_000da56c;
LAB_000da574:
    uVar18 = uVar18 & 0xfffffffb;
  }
  else {
    if ((((uVar7 >> 0xc & 0xf) < 8) && ((uVar7 >> 4 & 0xf) < 0xc)) && ((uVar7 & 0xf) < 0xc))
    goto LAB_000da574;
LAB_000da56c:
    uVar18 = uVar18 | 4;
  }
  uVar9 = uVar18 & 0xffff;
  if (uVar9 == uVar18 >> 0x10) {
    iVar3 = *(int *)(glContext + 0x4998) - iVar6;
    uVar17 = (uint)uVar2;
    goto LAB_000da680;
  }
  uVar17 = uVar18 & 4;
  if (uVar17 != (uVar18 >> 0x10 & 4)) {
    *(uint *)(glContext + 0x497c) = *(uint *)(glContext + 0x497c) | uVar18 & 0x1f;
  }
  if ((uVar18 & 0x10) == 0) {
    if ((uVar18 & 8) == 0) {
      if (uVar17 == 0) {
        uVar17 = 0x10;
        uVar12 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x7c);
      }
      else {
        uVar17 = 0x14;
        uVar12 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x82);
      }
    }
    else {
      if (uVar17 != 0) {
        uVar17 = 0x24;
        *(uint *)(glContext + 0x498c) = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x84);
        if ((*(uint *)(*(int *)(glContext + 0x468c) + 0x94) & 8) == 0) {
          uVar17 = 0x20;
        }
        goto LAB_000da61c;
      }
      uVar17 = 0x18;
      uVar12 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x7e);
    }
LAB_000da658:
    *(short *)(glContext + 0x4990) = (short)uVar17;
    *(uint *)(glContext + 0x498c) = uVar12;
  }
  else {
    if (uVar17 == 0) {
      uVar17 = 0x20;
      uVar12 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x80);
      goto LAB_000da658;
    }
    uVar17 = 0x34;
    *(uint *)(glContext + 0x498c) = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x86);
    if ((*(uint *)(*(int *)(glContext + 0x468c) + 0x94) & 8) == 0) {
      uVar17 = 0x2c;
    }
LAB_000da61c:
    *(short *)(glContext + 0x4990) = (short)uVar17;
  }
  iVar3 = 0;
  *(uint *)(glContext + 0x4980) = uVar9 | uVar18 << 0x10;
LAB_000da680:
  local_40[0] = iVar16 + 8;
  if (iVar3 < local_40[0]) {
    iVar15 = *(int *)(glContext + 0x49a8);
    bVar1 = iVar15 == 0;
    if (!bVar1) {
      (**(code **)(glContext + 0x47c8))(*(undefined4 *)(glContext + 0x4688),iVar15);
    }
    iVar6 = (**(code **)(glContext + 0x47c4))
                      (*(undefined4 *)(glContext + 0x4688),*(undefined4 *)(glContext + 0x498c),local_40)
    ;
    if (iVar6 == 0) {
      *(uint *)(glContext + 0x4980) = uVar9;
      *(undefined4 *)(glContext + 0x4998) = 0;
      *(undefined4 *)(glContext + 0x4994) = 0;
      *(undefined4 *)(glContext + 0x49a4) = 0;
      if (bVar1) {
        return 0;
      }
      uVar14 = (**(code **)(glContext + 0x47cc))(*(undefined4 *)(glContext + 0x4688),iVar15);
      *(undefined4 *)(glContext + 0x49a8) = 0;
      return uVar14;
    }
    *(undefined4 *)(glContext + 0x4994) = 0;
    *(int *)(glContext + 0x4998) = local_40[0];
    *(int *)(glContext + 0x49a8) = iVar6;
    *(int *)(glContext + 0x49a4) = iVar6;
    iVar11 = *(int *)(glContext + 0x49a0);
    uVar7 = *(uint *)(glContext + 0x49b0);
  }
  else {
    bVar1 = true;
    *(int *)(glContext + 0x4994) = iVar6;
    iVar6 = *(int *)(glContext + 0x49a8) + iVar6 * uVar17;
    *(int *)(glContext + 0x49a4) = iVar6;
  }
  *(int *)(glContext + 0x499c) = iVar11 + iVar16 * 4;
  uVar12 = 0;
  uVar9 = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334);
  if ((uVar9 & 0x10000) != 0) {
    uVar12 = 5;
  }
  if ((uVar9 & 0x40000) != 0) {
    uVar12 = uVar12 | 2;
  }
  if ((uVar9 & 0x1000000) != 0) {
    uVar12 = uVar12 | 8;
  }
  if ((uVar9 & 0x2000000) != 0) {
    uVar12 = uVar12 | 0x10;
  }
  piVar10 = *(int **)(glContext + 0x49b4);
  uVar18 = (uVar18 & uVar12) << 0x15 |
           (uVar18 & (*(uint *)(glContext + 0x497c) | ~uVar12) & 0x1f) << 0x10 | uVar7 | 0x30000000;
  piVar4 = piVar10;
  do {
    if (uVar18 == piVar4[2]) {
      if (piVar4 != piVar10) {
        piVar13 = (int *)piVar4[1];
        *piVar13 = *piVar4;
        *(int **)(*piVar4 + 4) = piVar13;
        puVar8 = (undefined4 *)piVar10[1];
        *puVar8 = piVar4;
        piVar4[1] = (int)puVar8;
        *piVar4 = (int)piVar10;
        piVar10[1] = (int)piVar4;
        *(int **)(glContext + 0x49b4) = piVar4;
      }
      pcVar5 = (code *)(piVar4 + 8);
      goto LAB_000da850;
    }
    piVar4 = (int *)*piVar4;
  } while (piVar4 != piVar10);
  if ((*(uint *)PTR__gle_processor_0011204c & 0x10) == 0) {
    pcVar5 = (code *)_gleBuildCompileFuncTCLNO(glContext,uVar18);
  }
  else {
    pcVar5 = (code *)_gleBuildCompileFuncTCLAV(glContext,uVar18);
  }
LAB_000da850:
  uVar14 = (*pcVar5)(glContext,iVar6,uVar14,uVar17,(uint)uVar2);
  *(uint *)(glContext + 0x497c) = ~*(uint *)(glContext + 0x4980) & 0x1f;
  if (!bVar1) {
    uVar14 = (**(code **)(glContext + 0x47cc))(*(undefined4 *)(glContext + 0x4688),iVar15);
  }
  return uVar14;
}

/* _gleCompileClippedVertexArray @ 0xda8b4 (1136 bytes) */
int _gleCompileClippedVertexArray(glContext)
  int glContext;
{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  code *pcVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  undefined4 uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  int local_40 [4];
  
  iVar16 = 0;
  iVar14 = glContext;
  if (*(int *)(glContext + 0x49ac) != 0) {
    iVar14 = *(int *)(glContext + 0x4988);
    uVar13 = *(undefined4 *)(glContext + 0x49a4);
    uVar2 = *(ushort *)(glContext + 0x4990);
    uVar17 = *(uint *)(glContext + 0x4980);
    if (*(short *)(glContext + 0x4992) == 0) {
      iVar10 = *(int *)(glContext + 0x49a0);
    }
    else {
      uVar17 = uVar17 & 0xffff;
      *(undefined2 *)(glContext + 0x4992) = 0;
      iVar10 = *(int *)(glContext + 0x49a0);
      *(int *)(glContext + 0x499c) = iVar10 + *(int *)(*(int *)(glContext + 0x468c) + 0x88) * 4;
    }
    piVar6 = *(int **)(glContext + 0x499c) + 0x11;
    iVar8 = (int)piVar6 - iVar10;
    for (iVar18 = *(int *)(glContext + 0x4984) + (iVar8 >> 2);
        (*(int **)(glContext + 0x499c) <= piVar6 && (iVar8 = (int)piVar6 - iVar10, *piVar6 == iVar18))
        ; iVar18 = iVar18 + -1) {
      piVar6 = piVar6 + -1;
      iVar8 = (int)piVar6 - iVar10;
    }
    uVar19 = uVar17 & 0xffff;
    iVar10 = *(int *)(glContext + 0x4994) + (iVar8 >> 2) + 1;
    if (uVar19 == uVar17 >> 0x10) {
      iVar8 = *(int *)(glContext + 0x4998) - iVar10;
      uVar15 = (uint)uVar2;
    }
    else {
      *(uint *)(glContext + 0x4980) = uVar19 | uVar17 << 0x10;
      if ((uVar17 & 0x10) == 0) {
        if ((uVar17 & 8) == 0) {
          if ((uVar17 & 4) == 0) {
            uVar15 = 0x14;
            uVar3 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x7c);
          }
          else {
            uVar15 = 0x18;
            uVar3 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x82);
          }
        }
        else if ((uVar17 & 4) == 0) {
          uVar15 = 0x1c;
          uVar3 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x7e);
        }
        else {
          uVar15 = 0x20;
          uVar3 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x84);
        }
      }
      else if ((uVar17 & 4) == 0) {
        uVar15 = 0x28;
        uVar3 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x80);
      }
      else {
        uVar15 = 0x2c;
        uVar3 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x86);
      }
      piVar11 = *(int **)(glContext + 0x49b8);
      *(short *)(glContext + 0x4990) = (short)uVar15;
      *(uint *)(glContext + 0x498c) = uVar3;
      piVar4 = piVar11;
      do {
        if (uVar19 == piVar4[2]) {
          if (piVar4 != piVar11) {
            piVar12 = (int *)piVar4[1];
            *piVar12 = *piVar4;
            *(int **)(*piVar4 + 4) = piVar12;
            puVar9 = (undefined4 *)piVar11[1];
            *puVar9 = piVar4;
            piVar4[1] = (int)puVar9;
            *piVar4 = (int)piVar11;
            piVar11[1] = (int)piVar4;
            *(int **)(glContext + 0x49b8) = piVar4;
          }
          *(int **)(glContext + 0x49c4) = piVar4 + 8;
          goto LAB_000daa98;
        }
        piVar4 = (int *)*piVar4;
      } while (piVar4 != piVar11);
      uVar5 = _gleBuildInterpFunc(glContext,uVar19);
      *(undefined4 *)(glContext + 0x49c4) = uVar5;
LAB_000daa98:
      iVar8 = 0;
    }
    local_40[0] = iVar14 * 2 + 0x12;
    if (local_40[0] < iVar8) {
      bVar1 = true;
      *(int *)(glContext + 0x4994) = iVar10;
      iVar10 = *(int *)(glContext + 0x49a8) + iVar10 * uVar15;
    }
    else {
      iVar16 = *(int *)(glContext + 0x49a8);
      bVar1 = iVar16 == 0;
      if (!bVar1) {
        (**(code **)(glContext + 0x47c8))(*(undefined4 *)(glContext + 0x4688),iVar16,iVar10);
      }
      iVar10 = (**(code **)(glContext + 0x47c4))
                         (*(undefined4 *)(glContext + 0x4688),*(undefined4 *)(glContext + 0x498c),
                          local_40);
      if (iVar10 == 0) {
        *(uint *)(glContext + 0x4980) = uVar19;
        *(undefined4 *)(glContext + 0x4998) = 0;
        *(undefined4 *)(glContext + 0x4994) = 0;
        *(undefined4 *)(glContext + 0x49a4) = 0;
        if (bVar1) {
          return 0;
        }
        uVar13 = (**(code **)(glContext + 0x47cc))(*(undefined4 *)(glContext + 0x4688),iVar16);
        *(undefined4 *)(glContext + 0x49a8) = 0;
        return uVar13;
      }
      *(undefined4 *)(glContext + 0x4994) = 0;
      *(int *)(glContext + 0x4998) = local_40[0];
      *(int *)(glContext + 0x49a8) = iVar10;
    }
    *(int *)(glContext + 0x49a4) = iVar10;
    piVar4 = (int *)(*(int *)(glContext + 0x49a0) + iVar14 * 4);
    if (piVar4 <= piVar6) {
      uVar19 = (uint)((int)piVar6 + (4 - (int)piVar4)) >> 2;
      do {
        *piVar6 = iVar18;
        piVar6 = piVar6 + -1;
        iVar18 = iVar18 + -1;
        uVar19 = uVar19 - 1;
      } while (uVar19 != 0);
    }
    *(int **)(glContext + 0x499c) = piVar4;
    uVar3 = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334);
    uVar19 = 0;
    if ((uVar3 & 0x10000) != 0) {
      uVar19 = 5;
    }
    if ((uVar3 & 0x40000) != 0) {
      uVar19 = uVar19 | 2;
    }
    if ((uVar3 & 0x1000000) != 0) {
      uVar19 = uVar19 | 8;
    }
    if ((uVar3 & 0x2000000) != 0) {
      uVar19 = uVar19 | 0x10;
    }
    uVar17 = (uVar17 & uVar19) << 0x15 |
             (uVar17 & (*(uint *)(glContext + 0x497c) | ~uVar19) & 0x1f) << 0x10 |
             *(uint *)(glContext + 0x49b0) | (uint)*(ushort *)(glContext + 0x4fe8) << 0x18;
    if (*(undefined **)(glContext + 0x5080) == ((unsigned char *)0x00001101)) {
      uVar17 = uVar17 | 0x10000000;
    }
    piVar4 = *(int **)(glContext + 0x49b4);
    piVar6 = piVar4;
    do {
      if (uVar17 == piVar6[2]) {
        if (piVar6 != piVar4) {
          piVar11 = (int *)piVar6[1];
          *piVar11 = *piVar6;
          *(int **)(*piVar6 + 4) = piVar11;
          puVar9 = (undefined4 *)piVar4[1];
          *puVar9 = piVar6;
          piVar6[1] = (int)puVar9;
          *piVar6 = (int)piVar4;
          piVar4[1] = (int)piVar6;
          *(int **)(glContext + 0x49b4) = piVar6;
        }
        pcVar7 = (code *)(piVar6 + 8);
        goto LAB_000dacc0;
      }
      piVar6 = (int *)*piVar6;
    } while (piVar6 != piVar4);
    if ((*(uint *)PTR__gle_processor_0011204c & 0x10) == 0) {
      pcVar7 = (code *)_gleBuildCompileFuncNO(glContext,uVar17);
    }
    else {
      pcVar7 = (code *)_gleBuildCompileFuncAV(glContext,uVar17);
    }
LAB_000dacc0:
    iVar14 = (*pcVar7)(glContext,iVar10,uVar13,uVar15,(uint)uVar2);
    *(uint *)(glContext + 0x497c) = ~*(uint *)(glContext + 0x4980) & 0x1f;
    if (!bVar1) {
      iVar14 = (**(code **)(glContext + 0x47cc))(*(undefined4 *)(glContext + 0x4688),iVar16);
    }
  }
  return iVar14;
}

/* _gleCompileVertexArray @ 0xdad24 (20 bytes) */
double _gleCompileVertexArray(param_1)
  int param_1;
{
  if (*(char *)(param_1 + 0x7580) != '\0') {
    ((int (*)())_gleCompileTCLVertexArray)(param_1);
    return;
  }
  ((int (*)())_gleCompileClippedVertexArray)(param_1);
  return;
}

/* _gleExecuteTCLVertexArray @ 0xdad38 (352 bytes) */
void _gleExecuteTCLVertexArray(glContext, param_2, param_3, param_4, param_5, param_6)
  int glContext;
  undefined4 param_2;
  int param_3;
  int param_4;
  uint param_5;
  int param_6;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_5 == 0x1403) {
LAB_000dad94:
    param_6 = param_6 + param_3;
LAB_000dad98:
                    
                    
    (**(code **)(glContext + 0x46e4))
              (*(undefined4 *)(glContext + 0x4688),*(undefined4 *)(glContext + 0x49a8),param_2,
               *(int *)(glContext + 0x4984) - *(int *)(glContext + 0x4994),param_4,param_5,
               param_6 + param_3);
    return;
  }
  if (param_5 < 0x1404) {
    if (param_5 == 0x1401) goto LAB_000dad98;
  }
  else {
    if (param_5 == 0x1405) {
      param_6 = param_6 + param_3 * 2;
      goto LAB_000dad94;
    }
    if (param_5 == 0x14ff) {
      piVar4 = (int *)_malloc(param_4 << 2);
      if (piVar4 != (int *)0x0) {
        if (param_3 < param_3 + param_4) {
          iVar1 = (param_3 + param_4) - param_3;
          piVar3 = piVar4;
          do {
            *piVar3 = param_3;
            piVar3 = piVar3 + 1;
            param_3 = param_3 + 1;
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
        }
        (**(code **)(glContext + 0x46e4))
                  (*(undefined4 *)(glContext + 0x4688),*(undefined4 *)(glContext + 0x49a8),param_2,
                   *(int *)(glContext + 0x4984) - *(int *)(glContext + 0x4994),param_4,0x1405,piVar4);
        _free(piVar4);
        return;
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      uVar2 = 0x505;
      goto LAB_000dae80;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  uVar2 = 0x500;
LAB_000dae80:
  *(undefined4 *)(glContext + 0x7574) = uVar2;
  return;
}

/* _gleExecuteClippedVertexArray @ 0xdae98 (4556 bytes) */
int _gleExecuteClippedVertexArray(param_1, param_2, param_3, param_4, param_5, param_6)
  dword *param_1;
  uint param_2;
  uint param_3;
  int param_4;
  uint param_5;
  dword *param_6;
{
  bool bVar1;
  uint uVar2;
  byte bVar4;
  uint uVar3;
  undefined4 r3AfterCall;
  dword *pdVar5;
  dword *r3AfterCall1;
  uint uVar6;
  uint uVar7;
  dword *pdVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  dword *pdVar20;
  uint *puVar21;
  uint *puVar22;
  int iVar23;
  uint uStack0000001c;
  int iStack00000024;
  dword *pdStack0000002c;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  uint local_d4;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84 [5];
  uint local_70;
  int local_6c;
  code *local_68;
  int local_64;
  uint local_60;
  int local_5c;
  
  local_68 = (code *)param_1[0x11b9];
  uStack0000001c = param_2;
  iStack00000024 = param_4;
  pdStack0000002c = param_6;
  if ((undefined *)param_1[0x1420] == ((unsigned char *)0x00001101)) {
    ((void (*)())_gleExecuteTCLVertexArray)(param_1,param_2,param_3,param_4,param_5,param_6);
    return (dword *)r3AfterCall;
  }
  if ((*(short *)((int)param_1 + 0x34d6) == 0x408) && (3 < param_2)) {
    return param_1;
  }
  if (param_5 == 0x1403) {
    local_70 = 0xffff;
    pdVar20 = (dword *)((int)param_6 + param_3 * 2 + -2);
    iVar9 = 2;
LAB_000daf8c:
    local_6c = 0;
    pdVar5 = param_1;
    pdStack0000002c = param_6;
  }
  else {
    if (param_5 < 0x1404) {
      if (param_5 != 0x1401) {
LAB_000db014:
        if (param_1[0x1d5d] != 0) {
          return param_1;
        }
        uVar2 = 0x500;
        pdVar20 = param_1;
LAB_000db024:
        param_1[0x1d5d] = uVar2;
        return pdVar20;
      }
      local_70 = 0xff;
      iVar9 = 1;
      pdVar20 = (dword *)((int)param_6 + (param_3 - 3));
      goto LAB_000daf8c;
    }
    if (param_5 == 0x1405) {
      iVar9 = 4;
      pdVar20 = param_6 + param_3;
      local_70 = 0xffffffff;
      goto LAB_000daf8c;
    }
    if (param_5 != 0x14ff) goto LAB_000db014;
    param_5 = 0x1405;
    pdVar5 = (dword *)_malloc(param_4 << 2);
    if (pdVar5 == (dword *)0x0) {
      if (param_1[0x1d5d] != 0) {
        return (dword *)0;
      }
      uVar2 = 0x505;
      pdVar20 = (dword *)0x0;
      goto LAB_000db024;
    }
    local_70 = 0xffffffff;
    iVar9 = 4;
    local_6c = 1;
    pdVar20 = pdVar5;
    pdStack0000002c = pdVar5;
    if ((int)param_3 < (int)(param_3 + iStack00000024)) {
      iVar10 = (param_3 + iStack00000024) - param_3;
      pdVar8 = pdVar5;
      do {
        *pdVar8 = param_3;
        param_3 = param_3 + 1;
        pdVar8 = pdVar8 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
  }
  uVar2 = param_1[0x1261];
  iVar11 = param_1[0x126b] - uVar2;
  local_64 = param_1[0x1269] - uVar2 * *(ushort *)(param_1 + 0x1264);
  local_60 = (param_1[0x1268] + param_1[0x1266] * 4 + param_1[0x1265] * -4) - 0x48;
  iVar10 = uVar2 - param_1[0x1265];
  pdVar8 = pdStack0000002c;
  switch(uStack0000001c) {
  case 0:
    iVar19 = 0;
    iVar18 = iStack00000024;
    if (iStack00000024 < 1) goto switchD_000db0a0_default;
    do {
      uVar2 = *pdVar20;
      pdVar20 = (dword *)((int)pdVar20 + iVar9);
      if (*(char *)(iVar11 + (uVar2 & local_70)) == '\0') {
        iVar19 = iVar19 + 1;
      }
      else if (iVar19 == 0) {
        pdVar8 = (dword *)((int)pdVar8 + iVar9);
      }
      else {
        pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],uStack0000001c,iVar10,iVar19,
                                      param_5,pdVar8);
        iVar23 = iVar19 + 1;
        iVar19 = 0;
        pdVar8 = (dword *)((int)pdVar8 + iVar23 * iVar9);
      }
      iVar18 = iVar18 + -1;
    } while (iVar18 != 0);
    break;
  case 1:
    iVar18 = 1;
    iVar19 = 0;
    if (iStack00000024 < 2) goto switchD_000db0a0_default;
    do {
      uVar12 = *pdVar20 & local_70;
      uVar2 = *(uint *)((int)pdVar20 + iVar9) & local_70;
      bVar15 = *(byte *)(iVar11 + uVar12);
      bVar14 = *(byte *)(iVar11 + uVar2);
      pdVar20 = (dword *)((int)pdVar20 + iVar9 + iVar9);
      if (((bVar15 | bVar14) & 0xc3) == 0) {
        iVar19 = iVar19 + 2;
      }
      else {
        iVar23 = iVar9 << 1;
        if (iVar19 != 0) {
          pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],uStack0000001c,iVar10,iVar19
                                        ,param_5,pdVar8);
          iVar23 = iVar19 + 2;
          iVar19 = 0;
          iVar23 = iVar23 * iVar9;
        }
        pdVar8 = (dword *)((int)pdVar8 + iVar23);
        if ((bVar15 & bVar14 & 0x3f) == 0) {
          local_e0 = uVar12;
          local_dc = uVar2;
          if (local_60 <= param_1[0x1267]) {
            ((void (*)())_gleFlushIndexStack)(param_1);
          }
          pdVar5 = (dword *)((int (*)())_gleVAClipLine)(param_1,local_64,iVar11,&local_e0);
          if (pdVar5 != (dword *)0x0) {
            pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],uStack0000001c,iVar10,2,
                                          0x1405,&local_e0);
          }
        }
      }
      iVar18 = iVar18 + 2;
    } while (iVar18 < iStack00000024);
    break;
  case 2:
    iVar19 = 0;
    uVar12 = *pdVar20 & local_70;
    bVar15 = *(byte *)(iVar11 + uVar12);
    uVar2 = uVar12;
    bVar14 = bVar15;
    if (1 < iStack00000024) {
      iVar18 = iStack00000024 + -1;
      uVar16 = uVar12;
      bVar13 = bVar15;
      do {
        pdVar20 = (dword *)((int)pdVar20 + iVar9);
        uVar2 = *pdVar20 & local_70;
        bVar14 = *(byte *)(iVar11 + uVar2);
        if (((bVar13 | bVar14) & 0xc3) == 0) {
          iVar19 = iVar19 + 1;
        }
        else {
          iVar23 = iVar9;
          if (iVar19 != 0) {
            iVar23 = iVar19 + 1;
            iVar19 = 0;
            pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],3,iVar10,iVar23,param_5,
                                          pdVar8);
            iVar23 = iVar23 * iVar9;
          }
          pdVar8 = (dword *)((int)pdVar8 + iVar23);
          if ((bVar13 & bVar14 & 0x3f) == 0) {
            local_e0 = uVar16;
            local_dc = uVar2;
            if (local_60 <= param_1[0x1267]) {
              ((void (*)())_gleFlushIndexStack)(param_1);
            }
            pdVar5 = (dword *)((int (*)())_gleVAClipLine)(param_1,local_64,iVar11,&local_e0);
            if (pdVar5 != (dword *)0x0) {
              pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],3,iVar10,2,0x1405,
                                            &local_e0);
            }
          }
        }
        iVar18 = iVar18 + -1;
        uVar16 = uVar2;
        bVar13 = bVar14;
      } while (iVar18 != 0);
    }
    if (iVar19 == iStack00000024 + -1) {
      uVar2 = param_1[0x126a];
      iVar19 = iStack00000024;
      goto LAB_000dbe34;
    }
    if (iVar19 != 0) {
      pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],3,iVar10,iVar19 + 1,param_5,
                                    pdVar8);
    }
    local_e0 = uVar2;
    local_dc = uVar12;
    if (((bVar15 | bVar14) & 0xc3) != 0) {
      if ((bVar15 & bVar14 & 0x3f) != 0) goto switchD_000db0a0_default;
      iVar9 = ((int (*)())_gleVAClipLine)(param_1,local_64,iVar11,&local_e0);
      pdVar5 = (dword *)0x0;
      if (iVar9 == 0) goto switchD_000db0a0_default;
    }
    uVar2 = param_1[0x126a];
    uVar12 = 3;
    uVar16 = param_1[0x11a2];
    iVar19 = 2;
    param_5 = 0x1405;
    pdVar8 = &local_e0;
    goto LAB_000dbe44;
  case 3:
    iVar19 = 0;
    if (iStack00000024 < 2) goto switchD_000db0a0_default;
    iVar18 = iStack00000024 + -1;
    uVar2 = *pdVar20 & local_70;
    bVar15 = *(byte *)(iVar11 + (*pdVar20 & local_70));
    do {
      pdVar20 = (dword *)((int)pdVar20 + iVar9);
      uVar12 = *pdVar20 & local_70;
      bVar14 = *(byte *)(iVar11 + uVar12);
      if (((bVar15 | bVar14) & 0xc3) == 0) {
        iVar19 = iVar19 + 1;
      }
      else {
        iVar23 = iVar9;
        if (iVar19 != 0) {
          iVar23 = iVar19 + 1;
          iVar19 = 0;
          pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],uStack0000001c,iVar10,iVar23
                                        ,param_5,pdVar8);
          iVar23 = iVar23 * iVar9;
        }
        pdVar8 = (dword *)((int)pdVar8 + iVar23);
        if ((bVar15 & bVar14 & 0x3f) == 0) {
          local_e0 = uVar2;
          local_dc = uVar12;
          if (local_60 <= param_1[0x1267]) {
            ((void (*)())_gleFlushIndexStack)(param_1);
          }
          pdVar5 = (dword *)((int (*)())_gleVAClipLine)(param_1,local_64,iVar11,&local_e0);
          if (pdVar5 != (dword *)0x0) {
            pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],uStack0000001c,iVar10,2,
                                          0x1405,&local_e0);
          }
        }
      }
      iVar18 = iVar18 + -1;
      uVar2 = uVar12;
      bVar15 = bVar14;
    } while (iVar18 != 0);
    if (iVar19 == 0) goto switchD_000db0a0_default;
    uVar2 = param_1[0x126a];
    iVar19 = iVar19 + 1;
    goto LAB_000dbe34;
  case 4:
    if ((param_5 == 0x1403) || (param_5 == 0x1401)) {
      iVar18 = 2;
      iVar19 = 0;
      if (iStack00000024 < 3) goto switchD_000db0a0_default;
      do {
        puVar22 = (uint *)((int)pdVar20 + iVar9 + iVar9);
        uVar16 = *pdVar20 & local_70;
        uVar12 = *(uint *)((int)pdVar20 + iVar9) & local_70;
        uVar2 = *puVar22 & local_70;
        bVar15 = *(byte *)(iVar11 + uVar16);
        bVar14 = *(byte *)(iVar11 + uVar12);
        pdVar20 = (dword *)((int)puVar22 + iVar9);
        bVar13 = *(byte *)(iVar11 + uVar2);
        if (((bVar15 | bVar14 | bVar13) & 0xc3) == 0) {
          iVar19 = iVar19 + 3;
        }
        else {
          iVar23 = iVar9 * 3;
          if (iVar19 != 0) {
            pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],uStack0000001c,iVar10,
                                          iVar19,param_5,pdVar8);
            iVar23 = iVar19 + 3;
            iVar19 = 0;
            iVar23 = iVar23 * iVar9;
          }
          pdVar8 = (dword *)((int)pdVar8 + iVar23);
          if ((bVar15 & bVar14 & bVar13 & 0x3f) == 0) {
            local_e0 = uVar16;
            local_dc = uVar12;
            local_d8 = uVar2;
            if (local_60 <= param_1[0x1267]) {
              ((void (*)())_gleFlushIndexStack)(param_1);
            }
            pdVar5 = (dword *)((int (*)())_gleVAClipPoly)(param_1,local_64,iVar11,3,&local_e0);
            if (pdVar5 != (dword *)0x0) {
              pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],9,iVar10,pdVar5,0x1405,
                                            &local_e0);
            }
          }
        }
        iVar18 = iVar18 + 3;
      } while (iVar18 < iStack00000024);
    }
    else {
      iVar9 = 2;
      iVar19 = 0;
      if (iStack00000024 < 3) goto switchD_000db0a0_default;
      do {
        bVar15 = *(byte *)(iVar11 + *pdVar20);
        bVar14 = *(byte *)(iVar11 + pdVar20[1]);
        bVar13 = *(byte *)(iVar11 + pdVar20[2]);
        if (((bVar15 | bVar14 | bVar13) & 0xc3) == 0) {
          iVar19 = iVar19 + 3;
        }
        else {
          if (iVar19 == 0) {
            pdVar8 = pdVar8 + 3;
          }
          else {
            pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],uStack0000001c,iVar10,
                                          iVar19,param_5,pdVar8);
            iVar18 = iVar19 + 3;
            iVar19 = 0;
            pdVar8 = pdVar8 + iVar18;
          }
          if ((bVar15 & bVar14 & bVar13 & 0x3f) == 0) {
            local_e0 = *pdVar20;
            local_dc = pdVar20[1];
            local_d8 = pdVar20[2];
            if (local_60 <= param_1[0x1267]) {
              ((void (*)())_gleFlushIndexStack)(param_1);
            }
            pdVar5 = (dword *)((int (*)())_gleVAClipPoly)(param_1,local_64,iVar11,3,&local_e0);
            if (pdVar5 != (dword *)0x0) {
              pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],9,iVar10,pdVar5,0x1405,
                                            &local_e0);
            }
          }
        }
        iVar9 = iVar9 + 3;
        pdVar20 = pdVar20 + 3;
      } while (iVar9 < iStack00000024);
    }
    break;
  case 5:
    uVar16 = 2;
    iVar19 = 0;
    puVar22 = (uint *)((int)pdVar20 + iVar9);
    bVar15 = *(byte *)(iVar11 + (*pdVar20 & local_70));
    uVar2 = *puVar22 & local_70;
    uVar12 = *pdVar20 & local_70;
    bVar14 = *(byte *)(iVar11 + (*puVar22 & local_70));
    if (iStack00000024 < 3) goto switchD_000db0a0_default;
    do {
      uVar3 = uVar2;
      puVar22 = (uint *)((int)puVar22 + iVar9);
      uVar2 = *puVar22 & local_70;
      bVar13 = *(byte *)(iVar11 + uVar2);
      if (((bVar15 | bVar14 | bVar13) & 0xc3) == 0) {
        iVar19 = iVar19 + 1;
        bVar15 = bVar14;
      }
      else {
        iVar18 = iVar9;
        if (iVar19 != 0) {
          pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],uStack0000001c,iVar10,
                                        iVar19 + 2,param_5,pdVar8);
          iVar18 = iVar19 + 1;
          iVar19 = 0;
          iVar18 = iVar18 * iVar9;
        }
        pdVar8 = (dword *)((int)pdVar8 + iVar18);
        if ((uVar16 & 1) == 0) {
          bVar14 = bVar14 | 0xc3;
        }
        bVar4 = bVar15 & bVar14;
        bVar15 = bVar14;
        if ((bVar4 & bVar13 & 0x3f) == 0) {
          local_e0 = uVar12;
          local_dc = uVar3;
          local_d8 = uVar2;
          if (local_60 <= param_1[0x1267]) {
            ((void (*)())_gleFlushIndexStack)(param_1);
          }
          pdVar5 = (dword *)((int (*)())_gleVAClipPoly)(param_1,local_64,iVar11,3,&local_e0);
          if (pdVar5 != (dword *)0x0) {
            pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],9,iVar10,pdVar5,0x1405,
                                          &local_e0);
          }
        }
      }
      uVar16 = uVar16 + 1;
      uVar12 = uVar3;
      bVar14 = bVar13;
    } while ((int)uVar16 < iStack00000024);
    goto LAB_000dbe1c;
  case 6:
    uVar12 = *pdVar20 & local_70;
    uVar2 = *(uint *)((int)pdVar20 + iVar9) & local_70;
    bVar15 = *(byte *)(iVar11 + uVar12);
    bVar14 = *(byte *)(iVar11 + uVar2);
    puVar22 = (uint *)((int)pdVar20 + iVar9 + iVar9);
    if (((bVar15 | bVar14) & 0xc3) == 0) {
      iVar19 = 2;
      bVar13 = 0;
      uVar16 = 0;
      bVar1 = 2 < iStack00000024;
      if (bVar1) {
        do {
          bVar13 = bVar14;
          uVar16 = uVar2;
          uVar2 = *puVar22;
          bVar14 = *(byte *)(iVar11 + (uVar2 & local_70));
          if ((bVar14 & 0xc3) != 0) break;
          iVar19 = iVar19 + 1;
          puVar22 = (uint *)((int)puVar22 + iVar9);
          bVar1 = iVar19 < iStack00000024;
          uVar2 = uVar2 & local_70;
        } while (bVar1);
        if (2 < iVar19) {
          pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],uStack0000001c,iVar10,iVar19
                                        ,param_5,pdStack0000002c);
        }
      }
    }
    else {
      iVar19 = 2;
      bVar1 = 2 < iStack00000024;
      uVar16 = uVar2;
      bVar13 = bVar14;
    }
    if (bVar1) {
      do {
        uVar3 = *puVar22;
        iVar19 = iVar19 + 1;
        puVar22 = (uint *)((int)puVar22 + iVar9);
        uVar3 = uVar3 & local_70;
        bVar14 = *(byte *)(iVar11 + uVar3);
        uVar2 = uVar3;
        if (((bVar15 | bVar13 | bVar14) & 0xc3) == 0) {
          pdVar5 = (dword *)((int)((unsigned char *)0x0) + 3);
          bVar1 = iVar19 < iStack00000024;
          if (bVar1) {
            puVar21 = local_84;
            while( true ) {
              uVar17 = *puVar22 & local_70;
              bVar13 = *(byte *)(iVar11 + uVar17);
              if ((bVar13 & 0xc3) != 0) break;
              iVar19 = iVar19 + 1;
              *puVar21 = uVar17;
              puVar22 = (uint *)((int)puVar22 + iVar9);
              bVar1 = iVar19 < iStack00000024;
              puVar21 = puVar21 + 1;
              pdVar5 = (dword *)((int)pdVar5 + 1);
              uVar2 = uVar17;
              bVar14 = bVar13;
              if ((!bVar1) || (7 < (int)pdVar5)) break;
            }
          }
          uVar7 = param_1[0x11a2];
          uVar6 = param_1[0x126a];
          puVar21 = &local_90;
          uVar17 = uStack0000001c;
          local_90 = uVar12;
          local_8c = uVar16;
          local_88 = uVar3;
LAB_000dbb38:
          pdVar5 = (dword *)(*local_68)(uVar7,uVar6,uVar17,iVar10,pdVar5,0x1405,puVar21);
          uVar3 = uVar2;
        }
        else {
          bVar1 = iVar19 < iStack00000024;
          if ((bVar15 & bVar13 & bVar14 & 0x3f) == 0) {
            local_e0 = uVar12;
            local_dc = uVar16;
            local_d8 = uVar3;
            if (local_60 <= param_1[0x1267]) {
              ((void (*)())_gleFlushIndexStack)(param_1);
            }
            pdVar5 = (dword *)((int (*)())_gleVAClipPoly)(param_1,local_64,iVar11,3,&local_e0);
            bVar1 = iVar19 < iStack00000024;
            if (pdVar5 != (dword *)0x0) {
              uVar6 = param_1[0x126a];
              uVar7 = param_1[0x11a2];
              uVar17 = 9;
              puVar21 = &local_e0;
              goto LAB_000dbb38;
            }
          }
        }
        uVar16 = uVar3;
        bVar13 = bVar14;
      } while (bVar1);
    }
    goto switchD_000db0a0_default;
  case 7:
    iVar18 = 3;
    iVar19 = 0;
    if (iStack00000024 < 4) goto switchD_000db0a0_default;
    do {
      uVar3 = *pdVar20 & local_70;
      puVar22 = (uint *)((int)pdVar20 + iVar9 + iVar9);
      uVar16 = *(uint *)((int)pdVar20 + iVar9) & local_70;
      bVar15 = *(byte *)(iVar11 + uVar3);
      puVar21 = (uint *)((int)puVar22 + iVar9);
      uVar12 = *puVar22 & local_70;
      bVar14 = *(byte *)(iVar11 + uVar16);
      uVar2 = *puVar21 & local_70;
      bVar13 = *(byte *)(iVar11 + uVar12);
      bVar4 = *(byte *)(iVar11 + uVar2);
      pdVar20 = (dword *)((int)puVar21 + iVar9);
      if (((bVar15 | bVar14 | bVar13 | bVar4) & 0xc3) == 0) {
        iVar19 = iVar19 + 4;
      }
      else {
        iVar23 = iVar9 << 2;
        if (iVar19 != 0) {
          pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],uStack0000001c,iVar10,iVar19
                                        ,param_5,pdVar8);
          iVar23 = iVar19 + 4;
          iVar19 = 0;
          iVar23 = iVar23 * iVar9;
        }
        pdVar8 = (dword *)((int)pdVar8 + iVar23);
        if ((bVar15 & bVar14 & bVar13 & bVar4 & 0x3f) == 0) {
          local_e0 = uVar3;
          local_dc = uVar16;
          local_d8 = uVar12;
          local_d4 = uVar2;
          if (local_60 <= param_1[0x1267]) {
            ((void (*)())_gleFlushIndexStack)(param_1);
          }
          pdVar5 = (dword *)((int (*)())_gleVAClipPoly)(param_1,local_64,iVar11,4,&local_e0);
          if (pdVar5 != (dword *)0x0) {
            pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],9,iVar10,pdVar5,0x1405,
                                          &local_e0);
          }
        }
      }
      iVar18 = iVar18 + 4;
    } while (iVar18 < iStack00000024);
    break;
  case 8:
    iVar18 = 3;
    iVar19 = 0;
    puVar22 = (uint *)((int)pdVar20 + iVar9);
    if (iStack00000024 < 4) goto switchD_000db0a0_default;
    local_5c = iVar9 << 1;
    uVar2 = *puVar22 & local_70;
    uVar12 = *pdVar20 & local_70;
    bVar15 = *(byte *)(iVar11 + (*pdVar20 & local_70));
    bVar14 = *(byte *)(iVar11 + (*puVar22 & local_70));
    do {
      puVar21 = (uint *)((int)puVar22 + iVar9);
      puVar22 = (uint *)((int)puVar21 + iVar9);
      uVar3 = *puVar21 & local_70;
      bVar13 = *(byte *)(iVar11 + uVar3);
      uVar16 = *puVar22 & local_70;
      bVar4 = *(byte *)(iVar11 + uVar16);
      if (((bVar15 | bVar14 | bVar13 | bVar4) & 0xc3) == 0) {
        iVar19 = iVar19 + 2;
      }
      else {
        iVar23 = local_5c;
        if (iVar19 != 0) {
          iVar23 = iVar19 + 2;
          iVar19 = 0;
          pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],uStack0000001c,iVar10,iVar23
                                        ,param_5,pdVar8);
          iVar23 = iVar23 * iVar9;
        }
        pdVar8 = (dword *)((int)pdVar8 + iVar23);
        if ((bVar15 & bVar14 & bVar13 & bVar4 & 0x3f) == 0) {
          local_e0 = uVar12;
          local_dc = uVar2;
          local_d8 = uVar16;
          local_d4 = uVar3;
          if (local_60 <= param_1[0x1267]) {
            ((void (*)())_gleFlushIndexStack)(param_1);
          }
          pdVar5 = (dword *)((int (*)())_gleVAClipPoly)(param_1,local_64,iVar11,4,&local_e0);
          if (pdVar5 != (dword *)0x0) {
            pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],9,iVar10,pdVar5,0x1405,
                                          &local_e0);
          }
        }
      }
      iVar18 = iVar18 + 2;
      uVar2 = uVar16;
      uVar12 = uVar3;
      bVar15 = bVar13;
      bVar14 = bVar4;
    } while (iVar18 < iStack00000024);
LAB_000dbe1c:
    if (iVar19 == 0) goto switchD_000db0a0_default;
    uVar2 = param_1[0x126a];
    iVar19 = iVar19 + 2;
    goto LAB_000dbe34;
  case 9:
    uVar12 = *pdVar20 & local_70;
    uVar2 = *(uint *)((int)pdVar20 + iVar9) & local_70;
    bVar15 = *(byte *)(iVar11 + uVar12);
    bVar14 = *(byte *)(iVar11 + uVar2);
    puVar22 = (uint *)((int)pdVar20 + iVar9 + iVar9);
    if (((bVar15 | bVar14) & 0xc3) == 0) {
      iVar19 = 2;
      bVar13 = 0;
      uVar16 = 0;
      bVar1 = 2 < iStack00000024;
      if (bVar1) {
        do {
          bVar13 = bVar14;
          uVar16 = uVar2;
          uVar2 = *puVar22;
          bVar14 = *(byte *)(iVar11 + (uVar2 & local_70));
          if ((bVar14 & 0xc3) != 0) break;
          iVar19 = iVar19 + 1;
          puVar22 = (uint *)((int)puVar22 + iVar9);
          bVar1 = iVar19 < iStack00000024;
          uVar2 = uVar2 & local_70;
        } while (bVar1);
        if (2 < iVar19) {
          pdVar5 = (dword *)(*local_68)(param_1[0x11a2],param_1[0x126a],uStack0000001c,iVar10,iVar19
                                        ,param_5,pdStack0000002c);
        }
      }
    }
    else {
      iVar19 = 2;
      bVar1 = 2 < iStack00000024;
      uVar16 = uVar2;
      bVar13 = bVar14;
    }
    if (bVar1) {
      do {
        uVar3 = *puVar22;
        iVar19 = iVar19 + 1;
        puVar22 = (uint *)((int)puVar22 + iVar9);
        uVar3 = uVar3 & local_70;
        bVar14 = *(byte *)(iVar11 + uVar3);
        uVar2 = uVar3;
        if (((bVar15 | bVar13 | bVar14) & 0xc3) == 0) {
          pdVar5 = (dword *)((int)((unsigned char *)0x0) + 3);
          bVar1 = iVar19 < iStack00000024;
          if (bVar1) {
            puVar21 = local_84;
            while( true ) {
              uVar17 = *puVar22 & local_70;
              bVar13 = *(byte *)(iVar11 + uVar17);
              if ((bVar13 & 0xc3) != 0) break;
              iVar19 = iVar19 + 1;
              *puVar21 = uVar17;
              puVar22 = (uint *)((int)puVar22 + iVar9);
              bVar1 = iVar19 < iStack00000024;
              puVar21 = puVar21 + 1;
              pdVar5 = (dword *)((int)pdVar5 + 1);
              uVar2 = uVar17;
              bVar14 = bVar13;
              if ((!bVar1) || (7 < (int)pdVar5)) break;
            }
          }
          uVar17 = param_1[0x11a2];
          uVar7 = param_1[0x126a];
          puVar21 = &local_90;
          local_90 = uVar12;
          local_8c = uVar16;
          local_88 = uVar3;
LAB_000dc04c:
          pdVar5 = (dword *)(*local_68)(uVar17,uVar7,uStack0000001c,iVar10,pdVar5,0x1405,puVar21);
          uVar3 = uVar2;
        }
        else {
          bVar1 = iVar19 < iStack00000024;
          if ((bVar15 & bVar13 & bVar14 & 0x3f) == 0) {
            local_e0 = uVar12;
            local_dc = uVar16;
            local_d8 = uVar3;
            if (local_60 <= param_1[0x1267]) {
              ((void (*)())_gleFlushIndexStack)(param_1);
            }
            pdVar5 = (dword *)((int (*)())_gleVAClipPoly)(param_1,local_64,iVar11,3,&local_e0);
            bVar1 = iVar19 < iStack00000024;
            if (pdVar5 != (dword *)0x0) {
              uVar7 = param_1[0x126a];
              uVar17 = param_1[0x11a2];
              puVar21 = &local_e0;
              goto LAB_000dc04c;
            }
          }
        }
        uVar16 = uVar3;
        bVar13 = bVar14;
      } while (bVar1);
    }
  default:
    goto switchD_000db0a0_default;
  }
  if (iVar19 != 0) {
    uVar2 = param_1[0x126a];
LAB_000dbe34:
    uVar16 = param_1[0x11a2];
    uVar12 = uStack0000001c;
LAB_000dbe44:
    pdVar5 = (dword *)(*local_68)(uVar16,uVar2,uVar12,iVar10,iVar19,param_5,pdVar8);
  }
switchD_000db0a0_default:
  if (local_6c != 0) {
    _free(pdStack0000002c);
    pdVar5 = r3AfterCall1;
  }
  return pdVar5;
}

/* _gleExecuteVertexArray @ 0xdc08c (20 bytes) */
void _gleExecuteVertexArray(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  if (*(char *)(param_1 + 0x7580) != '\0') {
    ((void (*)())_gleExecuteTCLVertexArray)(param_1,param_2,param_3,param_4,param_5,param_6);
    return;
  }
  ((int (*)())_gleExecuteClippedVertexArray)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

/* _gleLightMaterialRGBAChange_F_A @ 0xdc0a0 (184 bytes) */
void _gleLightMaterialRGBAChange_F_A(glContext, param_2)
  int glContext;
  undefined8 *param_2;
{
  byte bVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  puVar2 = (undefined8 *)_glePushMaterial(glContext,0);
  *puVar2 = *param_2;
  uVar5 = param_2[1];
  *(ushort *)((int)puVar2 + 0x234) = *(ushort *)((int)puVar2 + 0x234) | 0x404;
  puVar2[1] = uVar5;
  if (*(int *)(glContext + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(glContext + 0x5420) + 0x2c0);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2f4);
  }
  iVar4 = (bVar1 >> 3 & 0x1c) + glContext;
  iVar3 = *(int *)(glContext + 0x5424);
  *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar3 + 0x2c0);
  iVar3 = (bVar1 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar3 + 0x348) = *(uint *)(iVar3 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_F_D @ 0xdc158 (184 bytes) */
void _gleLightMaterialRGBAChange_F_D(glContext, param_2)
  int glContext;
  undefined8 *param_2;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar2 = _glePushMaterial(glContext,0);
  *(undefined8 *)(iVar2 + 0x10) = *param_2;
  uVar4 = param_2[1];
  *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x808;
  *(undefined8 *)(iVar2 + 0x18) = uVar4;
  if (*(int *)(glContext + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(glContext + 0x5420) + 0x2c1);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2f5);
  }
  iVar3 = (bVar1 >> 3 & 0x1c) + glContext;
  iVar2 = *(int *)(glContext + 0x5424);
  *(uint *)(iVar3 + 0x324) = *(uint *)(iVar3 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar2 + 0x2c1);
  iVar2 = (bVar1 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialShineChange_B @ 0xdc210 (180 bytes) */
void _gleLightMaterialShineChange_B(int glContext,float floatArg1)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _glePushMaterial(glContext,1);
  *(float *)(iVar2 + 0x40) = (float)floatArg1;
  *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x101;
  if (*(int *)(glContext + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(glContext + 0x5420) + 0x2ca);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2fe);
  }
  iVar3 = (bVar1 >> 3 & 0x1c) + glContext;
  iVar2 = *(int *)(glContext + 0x5424);
  *(uint *)(iVar3 + 0x324) = *(uint *)(iVar3 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar2 + 0x2ca);
  iVar2 = (bVar1 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_B_E @ 0xdc2c4 (184 bytes) */
void _gleLightMaterialRGBAChange_B_E(glContext, param_2)
  int glContext;
  undefined8 *param_2;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar2 = _glePushMaterial(glContext,1);
  *(undefined8 *)(iVar2 + 0x30) = *param_2;
  uVar4 = param_2[1];
  *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x202;
  *(undefined8 *)(iVar2 + 0x38) = uVar4;
  if (*(int *)(glContext + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(glContext + 0x5420) + 0x2c9);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2fd);
  }
  iVar3 = (bVar1 >> 3 & 0x1c) + glContext;
  iVar2 = *(int *)(glContext + 0x5424);
  *(uint *)(iVar3 + 0x324) = *(uint *)(iVar3 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar2 + 0x2c9);
  iVar2 = (bVar1 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_B_A @ 0xdc37c (184 bytes) */
void _gleLightMaterialRGBAChange_B_A(glContext, param_2)
  int glContext;
  undefined8 *param_2;
{
  byte bVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  puVar2 = (undefined8 *)_glePushMaterial(glContext,1);
  *puVar2 = *param_2;
  uVar5 = param_2[1];
  *(ushort *)((int)puVar2 + 0x234) = *(ushort *)((int)puVar2 + 0x234) | 0x404;
  puVar2[1] = uVar5;
  if (*(int *)(glContext + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(glContext + 0x5420) + 0x2c6);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2fa);
  }
  iVar4 = (bVar1 >> 3 & 0x1c) + glContext;
  iVar3 = *(int *)(glContext + 0x5424);
  *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar3 + 0x2c6);
  iVar3 = (bVar1 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar3 + 0x348) = *(uint *)(iVar3 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_B_D @ 0xdc434 (184 bytes) */
void _gleLightMaterialRGBAChange_B_D(glContext, param_2)
  int glContext;
  undefined8 *param_2;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar2 = _glePushMaterial(glContext,1);
  *(undefined8 *)(iVar2 + 0x10) = *param_2;
  uVar4 = param_2[1];
  *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x808;
  *(undefined8 *)(iVar2 + 0x18) = uVar4;
  if (*(int *)(glContext + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(glContext + 0x5420) + 0x2c7);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2fb);
  }
  iVar3 = (bVar1 >> 3 & 0x1c) + glContext;
  iVar2 = *(int *)(glContext + 0x5424);
  *(uint *)(iVar3 + 0x324) = *(uint *)(iVar3 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar2 + 0x2c7);
  iVar2 = (bVar1 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_B_S @ 0xdc4ec (184 bytes) */
void _gleLightMaterialRGBAChange_B_S(glContext, param_2)
  int glContext;
  undefined8 *param_2;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar2 = _glePushMaterial(glContext,1);
  *(undefined8 *)(iVar2 + 0x20) = *param_2;
  uVar4 = param_2[1];
  *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x1010;
  *(undefined8 *)(iVar2 + 0x28) = uVar4;
  if (*(int *)(glContext + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(glContext + 0x5420) + 0x2c8);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2fc);
  }
  iVar3 = (bVar1 >> 3 & 0x1c) + glContext;
  iVar2 = *(int *)(glContext + 0x5424);
  *(uint *)(iVar3 + 0x324) = *(uint *)(iVar3 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar2 + 0x2c8);
  iVar2 = (bVar1 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_B_AD @ 0xdc5a4 (296 bytes) */
void _gleLightMaterialRGBAChange_B_AD(glContext, param_2)
  int glContext;
  undefined8 *param_2;
{
  byte bVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  
  puVar2 = (undefined8 *)_glePushMaterial(glContext,1);
  *puVar2 = *param_2;
  puVar2[1] = param_2[1];
  puVar2[2] = *param_2;
  uVar6 = param_2[1];
  *(ushort *)((int)puVar2 + 0x234) = *(ushort *)((int)puVar2 + 0x234) | 0xc0c;
  puVar2[3] = uVar6;
  iVar4 = *(int *)(glContext + 0x5434);
  if (iVar4 == 0) {
    bVar1 = *(byte *)(*(int *)(glContext + 0x5420) + 0x2c6);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2fa);
  }
  iVar5 = (bVar1 >> 3 & 0x1c) + glContext;
  iVar3 = *(int *)(glContext + 0x5424);
  *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar3 + 0x2c6);
  iVar5 = (bVar1 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar5 + 0x348) = *(uint *)(iVar5 + 0x348) | 1 << (bVar1 & 0x1f);
  if (iVar4 == 0) {
    bVar1 = *(byte *)(*(int *)(glContext + 0x5420) + 0x2c7);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2fb);
  }
  iVar4 = (bVar1 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar3 + 0x2c7);
  iVar4 = (bVar1 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar4 + 0x348) = *(uint *)(iVar4 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_FB_E @ 0xdc6cc (224 bytes) */
void _gleLightMaterialRGBAChange_FB_E(glContext, param_2)
  int glContext;
  undefined8 *param_2;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  
  iVar5 = 0;
  do {
    iVar2 = _glePushMaterial(glContext,iVar5);
    *(undefined8 *)(iVar2 + 0x30) = *param_2;
    uVar6 = param_2[1];
    *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x202;
    *(undefined8 *)(iVar2 + 0x38) = uVar6;
    if (*(int *)(glContext + 0x5434) == 0) {
      bVar1 = *(byte *)(iVar5 * 6 + *(int *)(glContext + 0x5420) + 0x2c3);
    }
    else {
      bVar1 = *(byte *)(iVar5 * 6 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2f7);
    }
    iVar3 = iVar5 * 6;
    iVar4 = (bVar1 >> 3 & 0x1c) + glContext;
    iVar5 = iVar5 + 1;
    iVar2 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
    bVar1 = *(byte *)(iVar3 + iVar2 + 0x2c3);
    iVar2 = (bVar1 >> 3 & 0x1c) + glContext;
    *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  } while (iVar5 < 2);
  return;
}

/* _gleInvertMatrix_601_body @ 0xdc7b8 (1320 bytes) */
void _gleInvertMatrix_601_body(param_1)
  int param_1;
{
  float fVar1;
  float fVar2;
  float zero;
  float one;
  int iVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  int pivotIndex;
  int maxIndex;
  int iVar11;
  int iVar12;
  float *inverseMatrix;
  int iVar14;
  int iVar15;
  float local_50 [4];
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  
  one = FLOAT_00108e54;
  zero = FLOAT_00108e50;
  local_50[0] = *(float *)(param_1 + 0x1bc0);
  local_40 = *(float *)(param_1 + 0x1bc4);
  local_30 = *(float *)(param_1 + 0x1bc8);
  local_20 = *(float *)(param_1 + 0x1bcc);
  local_50[1] = *(float *)(param_1 + 0x1bd0);
  local_3c = *(float *)(param_1 + 0x1bd4);
  local_2c = *(float *)(param_1 + 0x1bd8);
  local_1c = *(float *)(param_1 + 0x1bdc);
  local_50[2] = *(float *)(param_1 + 0x1be0);
  local_38 = *(float *)(param_1 + 0x1be4);
  local_28 = *(float *)(param_1 + 0x1be8);
  local_18 = *(float *)(param_1 + 0x1bec);
  local_50[3] = *(float *)(param_1 + 0x1bf0);
  local_34 = *(float *)(param_1 + 0x1bf4);
  local_24 = *(float *)(param_1 + 0x1bf8);
  inverseMatrix = (float *)(param_1 + 0x21c0);
  local_14 = *(float *)(param_1 + 0x1bfc);
  *(float *)(param_1 + 0x21c0) = FLOAT_00108e54;
  *(float *)(param_1 + 0x21c4) = zero;
  *(float *)(param_1 + 0x21c8) = zero;
  *(float *)(param_1 + 0x21cc) = zero;
  *(float *)(param_1 + 0x21d0) = zero;
  *(float *)(param_1 + 0x21d4) = one;
  *(float *)(param_1 + 0x21d8) = zero;
  *(float *)(param_1 + 0x21dc) = zero;
  *(float *)(param_1 + 0x21e0) = zero;
  *(float *)(param_1 + 0x21e4) = zero;
  *(float *)(param_1 + 0x21e8) = one;
  *(float *)(param_1 + 0x21ec) = zero;
  *(float *)(param_1 + 0x21f0) = zero;
  *(float *)(param_1 + 0x21f4) = zero;
  *(float *)(param_1 + 0x21f8) = zero;
  *(float *)(param_1 + 0x21fc) = one;
  pivotIndex = 0;
  while( true ) {
    iVar8 = pivotIndex + 1;
    fVar2 = local_50[pivotIndex * 5];
    iVar7 = pivotIndex + 4;
    iVar14 = pivotIndex + 8;
    iVar15 = pivotIndex + 0xc;
    maxIndex = pivotIndex;
    if (iVar8 != 4) {
      pfVar6 = local_50 + pivotIndex * 4 + iVar8;
      iVar5 = 4 - iVar8;
      iVar12 = iVar8;
      do {
        fVar1 = *pfVar6;
        pfVar6 = pfVar6 + 1;
        if (ABS(fVar2) < ABS(fVar1)) {
          maxIndex = iVar12;
          fVar2 = fVar1;
        }
        iVar12 = iVar12 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    if (maxIndex != pivotIndex) {
      fVar1 = inverseMatrix[pivotIndex];
      iVar12 = maxIndex + 4;
      inverseMatrix[pivotIndex] = inverseMatrix[maxIndex];
      iVar5 = maxIndex + 8;
      inverseMatrix[maxIndex] = fVar1;
      iVar11 = maxIndex + 0xc;
      fVar1 = local_50[pivotIndex];
      local_50[pivotIndex] = local_50[maxIndex];
      local_50[maxIndex] = fVar1;
      fVar1 = inverseMatrix[iVar7];
      inverseMatrix[iVar7] = inverseMatrix[iVar12];
      inverseMatrix[iVar12] = fVar1;
      fVar1 = local_50[iVar7];
      local_50[iVar7] = local_50[iVar12];
      local_50[iVar12] = fVar1;
      fVar1 = inverseMatrix[iVar14];
      inverseMatrix[iVar14] = inverseMatrix[iVar5];
      inverseMatrix[iVar5] = fVar1;
      fVar1 = local_50[iVar14];
      local_50[iVar14] = local_50[iVar5];
      local_50[iVar5] = fVar1;
      fVar1 = inverseMatrix[iVar15];
      inverseMatrix[iVar15] = inverseMatrix[iVar11];
      inverseMatrix[iVar11] = fVar1;
      fVar1 = local_50[iVar15];
      local_50[iVar15] = local_50[iVar11];
      local_50[iVar11] = fVar1;
    }
    if (fVar2 == zero) break;
    fVar2 = one / fVar2;
    local_50[pivotIndex] = local_50[pivotIndex] * fVar2;
    inverseMatrix[pivotIndex] = inverseMatrix[pivotIndex] * fVar2;
    local_50[iVar7] = local_50[iVar7] * fVar2;
    inverseMatrix[iVar7] = inverseMatrix[iVar7] * fVar2;
    local_50[iVar14] = local_50[iVar14] * fVar2;
    inverseMatrix[iVar14] = inverseMatrix[iVar14] * fVar2;
    local_50[iVar15] = local_50[iVar15] * fVar2;
    inverseMatrix[iVar15] = inverseMatrix[iVar15] * fVar2;
    if (pivotIndex != 0) {
      fVar2 = local_50[pivotIndex * 4];
      local_50[0] = -(local_50[pivotIndex] * fVar2 - local_50[0]);
      *inverseMatrix = -(inverseMatrix[pivotIndex] * fVar2 - *inverseMatrix);
      local_40 = -(local_50[iVar7] * fVar2 - local_40);
      *(float *)(param_1 + 0x21d0) = -(inverseMatrix[iVar7] * fVar2 - *(float *)(param_1 + 0x21d0));
      local_30 = -(local_50[iVar14] * fVar2 - local_30);
      *(float *)(param_1 + 0x21e0) = -(inverseMatrix[iVar14] * fVar2 - *(float *)(param_1 + 0x21e0));
      local_20 = -(local_50[iVar15] * fVar2 - local_20);
      *(float *)(param_1 + 0x21f0) = -(inverseMatrix[iVar15] * fVar2 - *(float *)(param_1 + 0x21f0));
    }
    if (pivotIndex != 1) {
      fVar2 = local_50[pivotIndex * 4 + 1];
      local_50[1] = -(local_50[pivotIndex] * fVar2 - local_50[1]);
      *(float *)(param_1 + 0x21c4) = -(inverseMatrix[pivotIndex] * fVar2 - *(float *)(param_1 + 0x21c4));
      local_3c = -(local_50[iVar7] * fVar2 - local_3c);
      *(float *)(param_1 + 0x21d4) = -(inverseMatrix[iVar7] * fVar2 - *(float *)(param_1 + 0x21d4));
      local_2c = -(local_50[iVar14] * fVar2 - local_2c);
      *(float *)(param_1 + 0x21e4) = -(inverseMatrix[iVar14] * fVar2 - *(float *)(param_1 + 0x21e4));
      local_1c = -(local_50[iVar15] * fVar2 - local_1c);
      *(float *)(param_1 + 0x21f4) = -(inverseMatrix[iVar15] * fVar2 - *(float *)(param_1 + 0x21f4));
    }
    if (pivotIndex != 2) {
      fVar2 = local_50[pivotIndex * 4 + 2];
      local_50[2] = -(local_50[pivotIndex] * fVar2 - local_50[2]);
      *(float *)(param_1 + 0x21c8) = -(inverseMatrix[pivotIndex] * fVar2 - *(float *)(param_1 + 0x21c8));
      local_38 = -(local_50[iVar7] * fVar2 - local_38);
      *(float *)(param_1 + 0x21d8) = -(inverseMatrix[iVar7] * fVar2 - *(float *)(param_1 + 0x21d8));
      local_28 = -(local_50[iVar14] * fVar2 - local_28);
      *(float *)(param_1 + 0x21e8) = -(inverseMatrix[iVar14] * fVar2 - *(float *)(param_1 + 0x21e8));
      local_18 = -(local_50[iVar15] * fVar2 - local_18);
      *(float *)(param_1 + 0x21f8) = -(inverseMatrix[iVar15] * fVar2 - *(float *)(param_1 + 0x21f8));
    }
    if (pivotIndex != 3) {
      fVar2 = local_50[pivotIndex * 4 + 3];
      local_50[3] = -(local_50[pivotIndex] * fVar2 - local_50[3]);
      *(float *)(param_1 + 0x21cc) = -(inverseMatrix[pivotIndex] * fVar2 - *(float *)(param_1 + 0x21cc));
      local_34 = -(local_50[iVar7] * fVar2 - local_34);
      *(float *)(param_1 + 0x21dc) = -(inverseMatrix[iVar7] * fVar2 - *(float *)(param_1 + 0x21dc));
      local_24 = -(local_50[iVar14] * fVar2 - local_24);
      *(float *)(param_1 + 0x21ec) = -(inverseMatrix[iVar14] * fVar2 - *(float *)(param_1 + 0x21ec));
      local_14 = -(local_50[iVar15] * fVar2 - local_14);
      *(float *)(param_1 + 0x21fc) = -(inverseMatrix[iVar15] * fVar2 - *(float *)(param_1 + 0x21fc));
    }
    pivotIndex = iVar8;
    if (iVar8 == 4) {
      return;
    }
  }
  *(float *)(param_1 + 0x21fc) = one;
  *(float *)(param_1 + 0x21f8) = zero;
  *inverseMatrix = one;
  *(float *)(param_1 + 0x21c4) = zero;
  *(float *)(param_1 + 0x21c8) = zero;
  *(float *)(param_1 + 0x21cc) = zero;
  *(float *)(param_1 + 0x21d0) = zero;
  *(float *)(param_1 + 0x21d4) = one;
  *(float *)(param_1 + 0x21d8) = zero;
  *(float *)(param_1 + 0x21dc) = zero;
  *(float *)(param_1 + 0x21e0) = zero;
  *(float *)(param_1 + 0x21e4) = zero;
  *(float *)(param_1 + 0x21e8) = one;
  *(float *)(param_1 + 0x21ec) = zero;
  *(float *)(param_1 + 0x21f0) = zero;
  *(float *)(param_1 + 0x21f4) = zero;
  return;
}

/* _gleLoadTransposeMatrixf @ 0xdcce0 (132 bytes) */
int _gleLoadTransposeMatrixf(srcMatrix, dstMatrix)
  undefined4 *srcMatrix;
  undefined4 *dstMatrix;
{
  *dstMatrix = *srcMatrix;
  dstMatrix[1] = srcMatrix[4];
  dstMatrix[2] = srcMatrix[8];
  dstMatrix[3] = srcMatrix[0xc];
  dstMatrix[4] = srcMatrix[1];
  dstMatrix[5] = srcMatrix[5];
  dstMatrix[6] = srcMatrix[9];
  dstMatrix[7] = srcMatrix[0xd];
  dstMatrix[8] = srcMatrix[2];
  dstMatrix[9] = srcMatrix[6];
  dstMatrix[10] = srcMatrix[10];
  dstMatrix[0xb] = srcMatrix[0xe];
  dstMatrix[0xc] = srcMatrix[3];
  dstMatrix[0xd] = srcMatrix[7];
  dstMatrix[0xe] = srcMatrix[0xb];
  dstMatrix[0xf] = srcMatrix[0xf];
  return;
}

/* _gleLoadTransposeMatrixd @ 0xdcd64 (196 bytes) */
int _gleLoadTransposeMatrixd(srcMatrix, dstMatrix)
  double *srcMatrix;
  float *dstMatrix;
{
  *dstMatrix = (float)*srcMatrix;
  dstMatrix[1] = (float)srcMatrix[4];
  dstMatrix[2] = (float)srcMatrix[8];
  dstMatrix[3] = (float)srcMatrix[0xc];
  dstMatrix[4] = (float)srcMatrix[1];
  dstMatrix[5] = (float)srcMatrix[5];
  dstMatrix[6] = (float)srcMatrix[9];
  dstMatrix[7] = (float)srcMatrix[0xd];
  dstMatrix[8] = (float)srcMatrix[2];
  dstMatrix[9] = (float)srcMatrix[6];
  dstMatrix[10] = (float)srcMatrix[10];
  dstMatrix[0xb] = (float)srcMatrix[0xe];
  dstMatrix[0xc] = (float)srcMatrix[3];
  dstMatrix[0xd] = (float)srcMatrix[7];
  dstMatrix[0xe] = (float)srcMatrix[0xb];
  dstMatrix[0xf] = (float)srcMatrix[0xf];
  return;
}

/* _gleGetMatrixf @ 0xdce28 (132 bytes) */
void _gleGetMatrixf(srcMatrix, dstMatrix)
  undefined4 *srcMatrix;
  undefined4 *dstMatrix;
{
  *dstMatrix = *srcMatrix;
  dstMatrix[1] = srcMatrix[1];
  dstMatrix[2] = srcMatrix[2];
  dstMatrix[3] = srcMatrix[3];
  dstMatrix[4] = srcMatrix[4];
  dstMatrix[5] = srcMatrix[5];
  dstMatrix[6] = srcMatrix[6];
  dstMatrix[7] = srcMatrix[7];
  dstMatrix[8] = srcMatrix[8];
  dstMatrix[9] = srcMatrix[9];
  dstMatrix[10] = srcMatrix[10];
  dstMatrix[0xb] = srcMatrix[0xb];
  dstMatrix[0xc] = srcMatrix[0xc];
  dstMatrix[0xd] = srcMatrix[0xd];
  dstMatrix[0xe] = srcMatrix[0xe];
  dstMatrix[0xf] = srcMatrix[0xf];
  return;
}

/* _gleGetTransposeMatrixf @ 0xdceac (132 bytes) */
void _gleGetTransposeMatrixf(srcMatrix, dstMatrix)
  undefined4 *srcMatrix;
  undefined4 *dstMatrix;
{
  *dstMatrix = *srcMatrix;
  dstMatrix[1] = srcMatrix[4];
  dstMatrix[2] = srcMatrix[8];
  dstMatrix[3] = srcMatrix[0xc];
  dstMatrix[4] = srcMatrix[1];
  dstMatrix[5] = srcMatrix[5];
  dstMatrix[6] = srcMatrix[9];
  dstMatrix[7] = srcMatrix[0xd];
  dstMatrix[8] = srcMatrix[2];
  dstMatrix[9] = srcMatrix[6];
  dstMatrix[10] = srcMatrix[10];
  dstMatrix[0xb] = srcMatrix[0xe];
  dstMatrix[0xc] = srcMatrix[3];
  dstMatrix[0xd] = srcMatrix[7];
  dstMatrix[0xe] = srcMatrix[0xb];
  dstMatrix[0xf] = srcMatrix[0xf];
  return;
}

/* _gleGetTransposeMatrixd @ 0xdcf30 (132 bytes) */
void _gleGetTransposeMatrixd(srcMatrix, dstMatrix)
  float *srcMatrix;
  double *dstMatrix;
{
  *dstMatrix = (double)*srcMatrix;
  dstMatrix[1] = (double)srcMatrix[4];
  dstMatrix[2] = (double)srcMatrix[8];
  dstMatrix[3] = (double)srcMatrix[0xc];
  dstMatrix[4] = (double)srcMatrix[1];
  dstMatrix[5] = (double)srcMatrix[5];
  dstMatrix[6] = (double)srcMatrix[9];
  dstMatrix[7] = (double)srcMatrix[0xd];
  dstMatrix[8] = (double)srcMatrix[2];
  dstMatrix[9] = (double)srcMatrix[6];
  dstMatrix[10] = (double)srcMatrix[10];
  dstMatrix[0xb] = (double)srcMatrix[0xe];
  dstMatrix[0xc] = (double)srcMatrix[3];
  dstMatrix[0xd] = (double)srcMatrix[7];
  dstMatrix[0xe] = (double)srcMatrix[0xb];
  dstMatrix[0xf] = (double)srcMatrix[0xf];
  return;
}

/* _gleMultTransposeMatrixf @ 0xdcfb4 (836 bytes) */
void _gleMultTransposeMatrixf(leftMatrix, rightMatrix, productMatrix)
  float *leftMatrix;
  float *rightMatrix;
  float *productMatrix;
{
  *productMatrix = leftMatrix[0xc] * rightMatrix[0xc] +
             (leftMatrix[8] * rightMatrix[8] + (*leftMatrix * *rightMatrix + leftMatrix[4] * rightMatrix[4]));
  productMatrix[4] = leftMatrix[0xc] * rightMatrix[0xd] +
               (leftMatrix[8] * rightMatrix[9] + (*leftMatrix * rightMatrix[1] + leftMatrix[4] * rightMatrix[5]));
  productMatrix[8] = leftMatrix[0xc] * rightMatrix[0xe] +
               (leftMatrix[8] * rightMatrix[10] + (*leftMatrix * rightMatrix[2] + leftMatrix[4] * rightMatrix[6]));
  productMatrix[0xc] = leftMatrix[0xc] * rightMatrix[0xf] +
                 (leftMatrix[8] * rightMatrix[0xb] + (*leftMatrix * rightMatrix[3] + leftMatrix[4] * rightMatrix[7]));
  productMatrix[1] = leftMatrix[0xd] * rightMatrix[0xc] +
               (leftMatrix[9] * rightMatrix[8] + (leftMatrix[1] * *rightMatrix + leftMatrix[5] * rightMatrix[4]));
  productMatrix[5] = leftMatrix[0xd] * rightMatrix[0xd] +
               (leftMatrix[9] * rightMatrix[9] + (leftMatrix[1] * rightMatrix[1] + leftMatrix[5] * rightMatrix[5]));
  productMatrix[9] = leftMatrix[0xd] * rightMatrix[0xe] +
               (leftMatrix[9] * rightMatrix[10] + (leftMatrix[1] * rightMatrix[2] + leftMatrix[5] * rightMatrix[6]));
  productMatrix[0xd] = leftMatrix[0xd] * rightMatrix[0xf] +
                 (leftMatrix[9] * rightMatrix[0xb] + (leftMatrix[1] * rightMatrix[3] + leftMatrix[5] * rightMatrix[7]));
  productMatrix[2] = leftMatrix[0xe] * rightMatrix[0xc] +
               (leftMatrix[10] * rightMatrix[8] + (leftMatrix[2] * *rightMatrix + leftMatrix[6] * rightMatrix[4]));
  productMatrix[6] = leftMatrix[0xe] * rightMatrix[0xd] +
               (leftMatrix[10] * rightMatrix[9] + (leftMatrix[2] * rightMatrix[1] + leftMatrix[6] * rightMatrix[5]));
  productMatrix[10] = leftMatrix[0xe] * rightMatrix[0xe] +
                (leftMatrix[10] * rightMatrix[10] + (leftMatrix[2] * rightMatrix[2] + leftMatrix[6] * rightMatrix[6]));
  productMatrix[0xe] = leftMatrix[0xe] * rightMatrix[0xf] +
                 (leftMatrix[10] * rightMatrix[0xb] + (leftMatrix[2] * rightMatrix[3] + leftMatrix[6] * rightMatrix[7]));
  productMatrix[3] = leftMatrix[0xf] * rightMatrix[0xc] +
               (leftMatrix[0xb] * rightMatrix[8] + (leftMatrix[3] * *rightMatrix + leftMatrix[7] * rightMatrix[4]));
  productMatrix[7] = leftMatrix[0xf] * rightMatrix[0xd] +
               (leftMatrix[0xb] * rightMatrix[9] + (leftMatrix[3] * rightMatrix[1] + leftMatrix[7] * rightMatrix[5]));
  productMatrix[0xb] = leftMatrix[0xf] * rightMatrix[0xe] +
                 (leftMatrix[0xb] * rightMatrix[10] + (leftMatrix[3] * rightMatrix[2] + leftMatrix[7] * rightMatrix[6]));
  productMatrix[0xf] = leftMatrix[0xf] * rightMatrix[0xf] +
                 (leftMatrix[0xb] * rightMatrix[0xb] + (leftMatrix[3] * rightMatrix[3] + leftMatrix[7] * rightMatrix[7]));
  return;
}

/* _gleMultTransposeMatrixd @ 0xdd2f8 (900 bytes) */
void _gleMultTransposeMatrixd(leftMatrix, rightMatrix, productMatrix)
  float *leftMatrix;
  double *rightMatrix;
  float *productMatrix;
{
  *productMatrix = (float)((double)leftMatrix[0xc] * rightMatrix[0xc] +
                    ((double)leftMatrix[8] * rightMatrix[8] +
                    ((double)*leftMatrix * *rightMatrix + (double)leftMatrix[4] * rightMatrix[4])));
  productMatrix[4] = (float)((double)leftMatrix[0xc] * rightMatrix[0xd] +
                      ((double)leftMatrix[8] * rightMatrix[9] +
                      ((double)*leftMatrix * rightMatrix[1] + (double)leftMatrix[4] * rightMatrix[5])));
  productMatrix[8] = (float)((double)leftMatrix[0xc] * rightMatrix[0xe] +
                      ((double)leftMatrix[8] * rightMatrix[10] +
                      ((double)*leftMatrix * rightMatrix[2] + (double)leftMatrix[4] * rightMatrix[6])));
  productMatrix[0xc] = (float)((double)leftMatrix[0xc] * rightMatrix[0xf] +
                        ((double)leftMatrix[8] * rightMatrix[0xb] +
                        ((double)*leftMatrix * rightMatrix[3] + (double)leftMatrix[4] * rightMatrix[7])));
  productMatrix[1] = (float)((double)leftMatrix[0xd] * rightMatrix[0xc] +
                      ((double)leftMatrix[9] * rightMatrix[8] +
                      ((double)leftMatrix[1] * *rightMatrix + (double)leftMatrix[5] * rightMatrix[4])));
  productMatrix[5] = (float)((double)leftMatrix[0xd] * rightMatrix[0xd] +
                      ((double)leftMatrix[9] * rightMatrix[9] +
                      ((double)leftMatrix[1] * rightMatrix[1] + (double)leftMatrix[5] * rightMatrix[5])));
  productMatrix[9] = (float)((double)leftMatrix[0xd] * rightMatrix[0xe] +
                      ((double)leftMatrix[9] * rightMatrix[10] +
                      ((double)leftMatrix[1] * rightMatrix[2] + (double)leftMatrix[5] * rightMatrix[6])));
  productMatrix[0xd] = (float)((double)leftMatrix[0xd] * rightMatrix[0xf] +
                        ((double)leftMatrix[9] * rightMatrix[0xb] +
                        ((double)leftMatrix[1] * rightMatrix[3] + (double)leftMatrix[5] * rightMatrix[7])));
  productMatrix[2] = (float)((double)leftMatrix[0xe] * rightMatrix[0xc] +
                      ((double)leftMatrix[10] * rightMatrix[8] +
                      ((double)leftMatrix[2] * *rightMatrix + (double)leftMatrix[6] * rightMatrix[4])));
  productMatrix[6] = (float)((double)leftMatrix[0xe] * rightMatrix[0xd] +
                      ((double)leftMatrix[10] * rightMatrix[9] +
                      ((double)leftMatrix[2] * rightMatrix[1] + (double)leftMatrix[6] * rightMatrix[5])));
  productMatrix[10] = (float)((double)leftMatrix[0xe] * rightMatrix[0xe] +
                       ((double)leftMatrix[10] * rightMatrix[10] +
                       ((double)leftMatrix[2] * rightMatrix[2] + (double)leftMatrix[6] * rightMatrix[6])));
  productMatrix[0xe] = (float)((double)leftMatrix[0xe] * rightMatrix[0xf] +
                        ((double)leftMatrix[10] * rightMatrix[0xb] +
                        ((double)leftMatrix[2] * rightMatrix[3] + (double)leftMatrix[6] * rightMatrix[7])));
  productMatrix[3] = (float)((double)leftMatrix[0xf] * rightMatrix[0xc] +
                      ((double)leftMatrix[0xb] * rightMatrix[8] +
                      ((double)leftMatrix[3] * *rightMatrix + (double)leftMatrix[7] * rightMatrix[4])));
  productMatrix[7] = (float)((double)leftMatrix[0xf] * rightMatrix[0xd] +
                      ((double)leftMatrix[0xb] * rightMatrix[9] +
                      ((double)leftMatrix[3] * rightMatrix[1] + (double)leftMatrix[7] * rightMatrix[5])));
  productMatrix[0xb] = (float)((double)leftMatrix[0xf] * rightMatrix[0xe] +
                        ((double)leftMatrix[0xb] * rightMatrix[10] +
                        ((double)leftMatrix[3] * rightMatrix[2] + (double)leftMatrix[7] * rightMatrix[6])));
  productMatrix[0xf] = (float)((double)leftMatrix[0xf] * rightMatrix[0xf] +
                        ((double)leftMatrix[0xb] * rightMatrix[0xb] +
                        ((double)leftMatrix[3] * rightMatrix[3] + (double)leftMatrix[7] * rightMatrix[7])));
  return;
}

/* _gleMultTransposeMatrix @ 0xdd67c (836 bytes) */
void _gleMultTransposeMatrix(leftMatrix, rightMatrix, productMatrix)
  float *leftMatrix;
  float *rightMatrix;
  float *productMatrix;
{
  *productMatrix = leftMatrix[0xc] * rightMatrix[0xc] +
             (leftMatrix[8] * rightMatrix[8] + (*leftMatrix * *rightMatrix + leftMatrix[4] * rightMatrix[4]));
  productMatrix[4] = leftMatrix[0xc] * rightMatrix[0xd] +
               (leftMatrix[8] * rightMatrix[9] + (*leftMatrix * rightMatrix[1] + leftMatrix[4] * rightMatrix[5]));
  productMatrix[8] = leftMatrix[0xc] * rightMatrix[0xe] +
               (leftMatrix[8] * rightMatrix[10] + (*leftMatrix * rightMatrix[2] + leftMatrix[4] * rightMatrix[6]));
  productMatrix[0xc] = leftMatrix[0xc] * rightMatrix[0xf] +
                 (leftMatrix[8] * rightMatrix[0xb] + (*leftMatrix * rightMatrix[3] + leftMatrix[4] * rightMatrix[7]));
  productMatrix[1] = leftMatrix[0xd] * rightMatrix[0xc] +
               (leftMatrix[9] * rightMatrix[8] + (leftMatrix[1] * *rightMatrix + leftMatrix[5] * rightMatrix[4]));
  productMatrix[5] = leftMatrix[0xd] * rightMatrix[0xd] +
               (leftMatrix[9] * rightMatrix[9] + (leftMatrix[1] * rightMatrix[1] + leftMatrix[5] * rightMatrix[5]));
  productMatrix[9] = leftMatrix[0xd] * rightMatrix[0xe] +
               (leftMatrix[9] * rightMatrix[10] + (leftMatrix[1] * rightMatrix[2] + leftMatrix[5] * rightMatrix[6]));
  productMatrix[0xd] = leftMatrix[0xd] * rightMatrix[0xf] +
                 (leftMatrix[9] * rightMatrix[0xb] + (leftMatrix[1] * rightMatrix[3] + leftMatrix[5] * rightMatrix[7]));
  productMatrix[2] = leftMatrix[0xe] * rightMatrix[0xc] +
               (leftMatrix[10] * rightMatrix[8] + (leftMatrix[2] * *rightMatrix + leftMatrix[6] * rightMatrix[4]));
  productMatrix[6] = leftMatrix[0xe] * rightMatrix[0xd] +
               (leftMatrix[10] * rightMatrix[9] + (leftMatrix[2] * rightMatrix[1] + leftMatrix[6] * rightMatrix[5]));
  productMatrix[10] = leftMatrix[0xe] * rightMatrix[0xe] +
                (leftMatrix[10] * rightMatrix[10] + (leftMatrix[2] * rightMatrix[2] + leftMatrix[6] * rightMatrix[6]));
  productMatrix[0xe] = leftMatrix[0xe] * rightMatrix[0xf] +
                 (leftMatrix[10] * rightMatrix[0xb] + (leftMatrix[2] * rightMatrix[3] + leftMatrix[6] * rightMatrix[7]));
  productMatrix[3] = leftMatrix[0xf] * rightMatrix[0xc] +
               (leftMatrix[0xb] * rightMatrix[8] + (leftMatrix[3] * *rightMatrix + leftMatrix[7] * rightMatrix[4]));
  productMatrix[7] = leftMatrix[0xf] * rightMatrix[0xd] +
               (leftMatrix[0xb] * rightMatrix[9] + (leftMatrix[3] * rightMatrix[1] + leftMatrix[7] * rightMatrix[5]));
  productMatrix[0xb] = leftMatrix[0xf] * rightMatrix[0xe] +
                 (leftMatrix[0xb] * rightMatrix[10] + (leftMatrix[3] * rightMatrix[2] + leftMatrix[7] * rightMatrix[6]));
  productMatrix[0xf] = leftMatrix[0xf] * rightMatrix[0xf] +
                 (leftMatrix[0xb] * rightMatrix[0xb] + (leftMatrix[3] * rightMatrix[3] + leftMatrix[7] * rightMatrix[7]));
  return;
}

/* _glePreEvaluate @ 0xdd9cc (164 bytes) */
void _glePreEvaluate(undefined4 unusedArg1,int order,undefined4 unusedArg3,float *coeffs,float u,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double newCoeff;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float dVar6;
  float oneMinusU;
  
  if (order == 1) {
    *coeffs = 1.0;
    return;
  }
  dVar6 = (double)FLOAT_00108e54;
  coeffs[1] = (float)u;
  oneMinusU = (double)(dVar6 - u);
  *coeffs = (dVar6 - u);
  if (order != 2) {
    iVar5 = 2;
    if (2 < order) {
      do {
        iVar3 = 1;
        dVar6 = (double)(*coeffs * u);
        *coeffs = (oneMinusU * *coeffs);
        if (1 < iVar5) {
          iVar2 = iVar5 + -1;
          iVar4 = iVar3;
          do {
            iVar3 = iVar4 + 1;
            newCoeff = (double)oneMinusU * (double)coeffs[iVar4] + (double)dVar6;
            dVar6 = (double)(coeffs[iVar4] * u);
            coeffs[iVar4] = (float)newCoeff;
            iVar2 = iVar2 + -1;
            iVar4 = iVar3;
          } while (iVar2 != 0);
        }
        iVar5 = iVar5 + 1;
        coeffs[iVar3] = (float)(double)dVar6;
      } while (iVar5 < order);
      return;
    }
    return;
  }
  return;
}

/* _glePreEvaluateWithDeriv @ 0xdda70 (356 bytes) */
void _glePreEvaluateWithDeriv(undefined4 unusedArg1,int param_2,undefined4 unusedArg3,float *param_4,float *param_5,float floatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double dVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  float dVar9;
  float dVar10;
  
  fVar2 = (FLOAT_00108e54 - floatArg1);
  dVar9 = (double)fVar2;
  if (param_2 == 1) {
    *param_4 = FLOAT_00108e54;
    *param_5 = 0.0;
    return;
  }
  if (param_2 == 2) {
    param_5[1] = FLOAT_00108e54;
    *param_5 = -1.0;
    param_4[1] = (float)floatArg1;
    *param_4 = fVar2;
    return;
  }
  iVar5 = param_2 + -1;
  iVar8 = 2;
  *param_4 = fVar2;
  param_4[1] = (float)floatArg1;
  if (2 < iVar5) {
    do {
      iVar4 = 1;
      dVar10 = (double)(*param_4 * floatArg1);
      *param_4 = (dVar9 * *param_4);
      if (1 < iVar8) {
        iVar3 = iVar8 + -1;
        iVar6 = iVar4;
        do {
          iVar4 = iVar6 + 1;
          dVar1 = (double)dVar9 * (double)param_4[iVar6] + (double)dVar10;
          dVar10 = (double)(param_4[iVar6] * floatArg1);
          param_4[iVar6] = (float)dVar1;
          iVar3 = iVar3 + -1;
          iVar6 = iVar4;
        } while (iVar3 != 0);
      }
      iVar8 = iVar8 + 1;
      param_4[iVar4] = (float)(double)dVar10;
    } while (iVar8 < iVar5);
  }
  iVar6 = param_2 + -2;
  *param_5 = -*param_4;
  iVar4 = 1;
  pfVar7 = param_4;
  if (iVar5 < 2) {
    iVar6 = 1;
  }
  do {
    iVar5 = iVar4;
    fVar2 = *pfVar7;
    pfVar7 = pfVar7 + 1;
    param_5[iVar5] = fVar2 - param_4[iVar5];
    iVar6 = iVar6 + -1;
    iVar4 = iVar5 + 1;
  } while (iVar6 != 0);
  iVar4 = 1;
  param_5[iVar5 + 1] = param_4[iVar5];
  dVar10 = (double)(*param_4 * floatArg1);
  *param_4 = (dVar9 * *param_4);
  if (1 < iVar8) {
    iVar8 = iVar8 + -1;
    iVar5 = iVar4;
    do {
      iVar4 = iVar5 + 1;
      dVar1 = (double)dVar9 * (double)param_4[iVar5] + (double)dVar10;
      dVar10 = (double)(param_4[iVar5] * floatArg1);
      param_4[iVar5] = (float)dVar1;
      iVar8 = iVar8 + -1;
      iVar5 = iVar4;
    } while (iVar8 != 0);
  }
  param_4[iVar4] = (float)(double)dVar10;
  return;
}

/* _gleEvalDomain1Color @ 0xddbd4 (244 bytes) */
void _gleEvalDomain1Color(undefined4 param_1,int points,int order,undefined4 unusedArg4,int components,int out,float u,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,float unusedFloatArg12,float unusedFloatArg13)
{
  float coeff;
  float controlValue;
  int componentByteOffset;
  float *pointPtr;
  float *coeffPtr;
  int component;
  int pointsRemaining;
  double incomingStack_ffffff98;
  double incomingStack_ffffffa0;
  double incomingStack_ffffffa8;
  double incomingStack_ffffffb0;
  double incomingStack_ffffffb8;
  
  if (((double)GH_U2F((unsigned int)_uvalue_c) != u) || (_uorder_c != order)) {
    ((void (*)())_glePreEvaluate)(param_1,order,order,&_ucoeff_c,u,floatArg2,floatArg3,floatArg4,floatArg5,
                    floatArg6,floatArg7,floatArg8,incomingStack_ffffff98,incomingStack_ffffffa0,incomingStack_ffffffa8
                    ,incomingStack_ffffffb0,incomingStack_ffffffb8);
    _uvalue_c = GH_F2U((float)u);
    _utype_c = 2;
    _uorder_c = order;
  }
  component = 0;
  if (0 < components) {
    do {
      componentByteOffset = component * 4;
      *(undefined4 *)(out + componentByteOffset) = 0;
      pointPtr = (float *)(points + componentByteOffset);
      if (0 < order) {
        coeffPtr = (float *)&_ucoeff_c;
        pointsRemaining = order;
        do {
          coeff = *coeffPtr;
          coeffPtr = coeffPtr + 1;
          controlValue = *pointPtr;
          pointPtr = pointPtr + components;
          *(float *)(out + componentByteOffset) = coeff * controlValue + *(float *)(out + componentByteOffset);
          pointsRemaining = pointsRemaining + -1;
        } while (pointsRemaining != 0);
      }
      component = component + 1;
    } while (component < components);
  }
  return;
}

/* _gleEvalDomain1Coord @ 0xddcc8 (244 bytes) */
void _gleEvalDomain1Coord(undefined4 param_1,int points,int order,undefined4 unusedArg4,int components,int out,float u,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,float unusedFloatArg12,float unusedFloatArg13)
{
  float coeff;
  float controlValue;
  int componentByteOffset;
  float *pointPtr;
  float *coeffPtr;
  int component;
  int pointsRemaining;
  double incomingStack_ffffff98;
  double incomingStack_ffffffa0;
  double incomingStack_ffffffa8;
  double incomingStack_ffffffb0;
  double incomingStack_ffffffb8;
  
  if (((double)GH_U2F((unsigned int)_uvalue_c) != u) || (_uorder_c != order)) {
    ((void (*)())_glePreEvaluate)(param_1,order,order,&_ucoeff_c,u,floatArg2,floatArg3,floatArg4,floatArg5,
                    floatArg6,floatArg7,floatArg8,incomingStack_ffffff98,incomingStack_ffffffa0,incomingStack_ffffffa8
                    ,incomingStack_ffffffb0,incomingStack_ffffffb8);
    _uvalue_c = GH_F2U((float)u);
    _utype_c = 2;
    _uorder_c = order;
  }
  component = 0;
  if (0 < components) {
    do {
      componentByteOffset = component * 4;
      *(undefined4 *)(out + componentByteOffset) = 0;
      pointPtr = (float *)(points + componentByteOffset);
      if (0 < order) {
        coeffPtr = (float *)&_ucoeff_c;
        pointsRemaining = order;
        do {
          coeff = *coeffPtr;
          coeffPtr = coeffPtr + 1;
          controlValue = *pointPtr;
          pointPtr = pointPtr + components;
          *(float *)(out + componentByteOffset) = coeff * controlValue + *(float *)(out + componentByteOffset);
          pointsRemaining = pointsRemaining + -1;
        } while (pointsRemaining != 0);
      }
      component = component + 1;
    } while (component < components);
  }
  return;
}

/* _gleEvalDomain2Color @ 0xdddbc (420 bytes) */
void _gleEvalDomain2Color(undefined4 param_1,int points,int uorder,int vorder,undefined4 unusedArg5,undefined4 unusedArg6,int components,int out,float u,float v,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,float unusedFloatArg12,float unusedFloatArg13)
{
  float vSum;
  float controlValue;
  int componentByteOffset;
  int uRemaining;
  float *vCoeffPtr;
  int iVar6;
  float *uCoeffPtr;
  float *pointPtr;
  int vRemaining;
  float dVar10;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  double incomingStack_ffffff98;
  double incomingStack_ffffffa0;
  double incomingStack_ffffffa8;
  
  iVar6 = uorder;
  dVar10 = v;
  if (((double)GH_U2F((unsigned int)_uvalue_c) != u) || (_uorder_c != uorder)) {
    ((void (*)())_glePreEvaluate)(param_1,uorder,uorder,&_ucoeff_c,u,v,floatArg3,floatArg4,floatArg5,
                    floatArg6,floatArg7,floatArg8,incomingStack_ffffff88,incomingStack_ffffff90,incomingStack_ffffff98
                    ,incomingStack_ffffffa0,incomingStack_ffffffa8);
    _uvalue_c = GH_F2U((float)u);
    _utype_c = 2;
    _uorder_c = uorder;
  }
  if (((double)GH_U2F((unsigned int)_vvalue_c) != v) || (_vorder_c != vorder)) {
    ((void (*)())_glePreEvaluate)(param_1,vorder,iVar6,&_vcoeff_c,v,(double)dVar10,floatArg3,floatArg4,floatArg5,
                    floatArg6,floatArg7,floatArg8,incomingStack_ffffff88,incomingStack_ffffff90,incomingStack_ffffff98
                    ,incomingStack_ffffffa0,incomingStack_ffffffa8);
    _vvalue_c = GH_F2U((float)v);
    _vtype_c = 2;
    _vorder_c = vorder;
  }
  iVar6 = 0;
  if (0 < components) {
    do {
      componentByteOffset = iVar6 * 4;
      *(undefined4 *)(componentByteOffset + out) = 0;
      pointPtr = (float *)(points + componentByteOffset);
      if (0 < uorder) {
        uCoeffPtr = (float *)&_ucoeff_c;
        uRemaining = uorder;
        do {
          vSum = *pointPtr;
          pointPtr = pointPtr + components;
          vSum = GH_U2F((unsigned int)_vcoeff_c) * vSum;
          if (1 < vorder) {
            vRemaining = vorder + -1;
            vCoeffPtr = &_vcoeff_c;
            do {
              vCoeffPtr = vCoeffPtr + 1;
              controlValue = *pointPtr;
              pointPtr = pointPtr + components;
              vSum = *vCoeffPtr * controlValue + vSum;
              vRemaining = vRemaining + -1;
            } while (vRemaining != 0);
          }
          controlValue = *uCoeffPtr;
          uRemaining = uRemaining + -1;
          uCoeffPtr = uCoeffPtr + 1;
          *(float *)(componentByteOffset + out) = controlValue * vSum + *(float *)(componentByteOffset + out);
        } while (uRemaining != 0);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < components);
  }
  return;
}

/* _gleEvalDomain2Coord @ 0xddf60 (420 bytes) */
void _gleEvalDomain2Coord(undefined4 param_1,int points,int uorder,int vorder,undefined4 unusedArg5,undefined4 unusedArg6,int components,int out,float u,float v,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,float unusedFloatArg12,float unusedFloatArg13)
{
  float vSum;
  float controlValue;
  int componentByteOffset;
  int uRemaining;
  float *vCoeffPtr;
  int iVar6;
  float *uCoeffPtr;
  float *pointPtr;
  int vRemaining;
  float dVar10;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  double incomingStack_ffffff98;
  double incomingStack_ffffffa0;
  double incomingStack_ffffffa8;
  
  iVar6 = uorder;
  dVar10 = v;
  if (((double)GH_U2F((unsigned int)_uvalue_c) != u) || (_uorder_c != uorder)) {
    ((void (*)())_glePreEvaluate)(param_1,uorder,uorder,&_ucoeff_c,u,v,floatArg3,floatArg4,floatArg5,
                    floatArg6,floatArg7,floatArg8,incomingStack_ffffff88,incomingStack_ffffff90,incomingStack_ffffff98
                    ,incomingStack_ffffffa0,incomingStack_ffffffa8);
    _uvalue_c = GH_F2U((float)u);
    _utype_c = 2;
    _uorder_c = uorder;
  }
  if (((double)GH_U2F((unsigned int)_vvalue_c) != v) || (_vorder_c != vorder)) {
    ((void (*)())_glePreEvaluate)(param_1,vorder,iVar6,&_vcoeff_c,v,(double)dVar10,floatArg3,floatArg4,floatArg5,
                    floatArg6,floatArg7,floatArg8,incomingStack_ffffff88,incomingStack_ffffff90,incomingStack_ffffff98
                    ,incomingStack_ffffffa0,incomingStack_ffffffa8);
    _vvalue_c = GH_F2U((float)v);
    _vtype_c = 2;
    _vorder_c = vorder;
  }
  iVar6 = 0;
  if (0 < components) {
    do {
      componentByteOffset = iVar6 * 4;
      *(undefined4 *)(componentByteOffset + out) = 0;
      pointPtr = (float *)(points + componentByteOffset);
      if (0 < uorder) {
        uCoeffPtr = (float *)&_ucoeff_c;
        uRemaining = uorder;
        do {
          vSum = *pointPtr;
          pointPtr = pointPtr + components;
          vSum = GH_U2F((unsigned int)_vcoeff_c) * vSum;
          if (1 < vorder) {
            vRemaining = vorder + -1;
            vCoeffPtr = &_vcoeff_c;
            do {
              vCoeffPtr = vCoeffPtr + 1;
              controlValue = *pointPtr;
              pointPtr = pointPtr + components;
              vSum = *vCoeffPtr * controlValue + vSum;
              vRemaining = vRemaining + -1;
            } while (vRemaining != 0);
          }
          controlValue = *uCoeffPtr;
          uRemaining = uRemaining + -1;
          uCoeffPtr = uCoeffPtr + 1;
          *(float *)(componentByteOffset + out) = controlValue * vSum + *(float *)(componentByteOffset + out);
        } while (uRemaining != 0);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < components);
  }
  return;
}

/* _gleEvalDomainDeriv2Coord @ 0xde104 (572 bytes) */
void _gleEvalDomainDeriv2Coord(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 unusedArg5,undefined4 unusedArg6,int param_7,int param_8,int param_9,int param_10,float floatArg1,float floatArg2,double floatArg3,double floatArg4,float floatArg5,float floatArg6,float floatArg7,float floatArg8,float unusedFloatArg9,float unusedFloatArg10,float unusedFloatArg11,float unusedFloatArg12,float unusedFloatArg13)
{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  float dVar13;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  double incomingStack_ffffff98;
  
  iVar12 = param_3;
  dVar13 = floatArg2;
  if ((((double)GH_U2F((unsigned int)_uvalue_c) != floatArg1) || (_utype_c != 1)) || (_uorder_c != param_3)) {
    ((void (*)())_glePreEvaluateWithDeriv)(param_1,param_3,param_3,&_ucoeff_c,&_ucoeffDeriv_c,floatArg1,floatArg2,floatArg3,
               floatArg4,floatArg5,floatArg6,floatArg7,floatArg8,incomingStack_ffffff78,incomingStack_ffffff80,
               incomingStack_ffffff88,incomingStack_ffffff90,incomingStack_ffffff98);
    _utype_c = 1;
    _uvalue_c = GH_F2U((float)floatArg1);
    _uorder_c = param_3;
  }
  if ((((double)GH_U2F((unsigned int)_vvalue_c) != floatArg2) || (_vtype_c != 1)) || (_vorder_c != param_4)) {
    ((void (*)())_glePreEvaluateWithDeriv)(param_1,param_4,iVar12,&_vcoeff_c,&_vcoeffDeriv_c,floatArg2,(double)dVar13,floatArg3,floatArg4,
               floatArg5,floatArg6,floatArg7,floatArg8,incomingStack_ffffff78,incomingStack_ffffff80,
               incomingStack_ffffff88,incomingStack_ffffff90,incomingStack_ffffff98);
    _vtype_c = 1;
    _vvalue_c = GH_F2U((float)floatArg2);
    _vorder_c = param_4;
  }
  iVar12 = 0;
  if (0 < param_7) {
    do {
      iVar8 = 0;
      iVar3 = iVar12 * 4;
      pfVar9 = (float *)(param_2 + iVar3);
      fVar4 = FLOAT_00108e50;
      fVar6 = FLOAT_00108e50;
      fVar7 = FLOAT_00108e50;
      if (0 < param_3) {
        do {
          iVar10 = 1;
          fVar1 = *pfVar9;
          pfVar9 = pfVar9 + param_7;
          fVar5 = GH_U2F((unsigned int)_vcoeffDeriv_c) * fVar1;
          fVar1 = GH_U2F((unsigned int)_vcoeff_c) * fVar1;
          if (1 < param_4) {
            do {
              iVar11 = iVar10 + 1;
              fVar2 = *pfVar9;
              pfVar9 = pfVar9 + param_7;
              fVar5 = GH_U2F((unsigned int)((&_vcoeffDeriv_c)[iVar10])) * fVar2 + fVar5;
              fVar1 = GH_U2F((unsigned int)((&_vcoeff_c)[iVar10])) * fVar2 + fVar1;
              iVar10 = iVar11;
            } while (iVar11 < param_4);
          }
          iVar10 = iVar8 + 1;
          fVar4 = GH_U2F((unsigned int)((&_ucoeff_c)[iVar8])) * fVar5 + fVar4;
          fVar7 = GH_U2F((unsigned int)((&_ucoeffDeriv_c)[iVar8])) * fVar1 + fVar7;
          fVar6 = GH_U2F((unsigned int)((&_ucoeff_c)[iVar8])) * fVar1 + fVar6;
          iVar8 = iVar10;
        } while (iVar10 < param_3);
      }
      iVar12 = iVar12 + 1;
      *(float *)(iVar3 + param_10) = fVar6;
      *(float *)(iVar3 + param_8) = fVar7;
      *(float *)(iVar3 + param_9) = fVar4;
    } while (iVar12 < param_7);
  }
  return;
}

/* _gleInitMap1Data @ 0xde340 (336 bytes) */
void _gleInitMap1Data(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 0x7450);
  iVar3 = 0x10;
  *puVar1 = 1;
  puVar1[1] = 0;
  puVar1[2] = 0x3f800000;
  puVar2 = puVar1 + 0x276a;
  puVar1[3] = 0x3f800000;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[0x22] = 1;
  puVar1[0x23] = 0;
  puVar1[0x24] = 0x3f800000;
  puVar1[0x25] = 0x3f800000;
  puVar1[0x26] = 0;
  puVar1[0x27] = 0;
  puVar1[0x28] = 0;
  puVar1[0x29] = 0x3f800000;
  puVar1[0x4e] = 1;
  puVar1[0x4f] = 0;
  puVar1[0x50] = 0x3f800000;
  puVar1[0x51] = 0x3f800000;
  puVar1[0x52] = 0;
  puVar1[0x53] = 0;
  puVar1[0x54] = 0x3f800000;
  puVar1[0x70] = 1;
  puVar1[0x71] = 0;
  puVar1[0x72] = 0x3f800000;
  puVar1[0x73] = 0x3f800000;
  puVar1[0x74] = 0x3f800000;
  puVar1[0x75] = 0x3f800000;
  puVar1[0x76] = 0x3f800000;
  puVar1[0x77] = 0x3f800000;
  puVar1[0x9c] = 1;
  puVar1[0x9d] = 0;
  puVar1[0x9e] = 0x3f800000;
  puVar1[0xf2] = 1;
  puVar1[0x9f] = 0x3f800000;
  puVar1[0xa0] = 0x3f800000;
  puVar1[0xaa] = 1;
  puVar1[0xab] = 0;
  puVar1[0xac] = 0x3f800000;
  puVar1[0xad] = 0x3f800000;
  puVar1[0xae] = 0;
  puVar1[0xb8] = 1;
  puVar1[0xb9] = 0;
  puVar1[0xba] = 0x3f800000;
  puVar1[0xbb] = 0x3f800000;
  puVar1[0xbc] = 0;
  puVar1[0xbd] = 0;
  puVar1[0xd0] = 1;
  puVar1[0xd1] = 0;
  puVar1[0xd2] = 0x3f800000;
  puVar1[0xd3] = 0x3f800000;
  puVar1[0xd4] = 0;
  puVar1[0xd5] = 0;
  puVar1[0xd6] = 0;
  puVar1[0xf3] = 0;
  puVar1[0xf4] = 0x3f800000;
  puVar1[0xf5] = 0x3f800000;
  puVar1[0xf6] = 0;
  puVar1[0xf7] = 0;
  puVar1[0xf8] = 0;
  puVar1[0xf9] = 0x3f800000;
  do {
    *(undefined1 *)puVar2 = 4;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    puVar1[0xb2a] = 1;
    puVar1[0xb2b] = 0;
    puVar1[0xb2c] = 0x3f800000;
    puVar1[0xb2d] = 0x3f800000;
    puVar1[0xb2e] = 0;
    puVar1[0xb2f] = 0;
    puVar1[0xb30] = 0;
    puVar1[0xb31] = 0x3f800000;
    puVar1 = puVar1 + 0x2c;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

/* _gleMap1Vertex3dLoad @ 0xde490 (144 bytes) */
void _gleMap1Vertex3dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int stride,int order,int points,int *mapData,double u1,double u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int pointByteOffset;
  int pointElementOffset;
  int pointAddr;
  double invUDelta;
  
  pointElementOffset = 0;
  invUDelta = DOUBLE_00108d68 / (u2 - u1);
  *mapData = order;
  mapData[1] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)invUDelta);
  mapData[2] = (int)GH_F2U((float)u2);
  if (0 < order) {
    do {
      pointByteOffset = pointElementOffset * 8;
      pointElementOffset = pointElementOffset + stride;
      pointAddr = pointByteOffset + points;
      mapData[4] = (int)GH_F2U((float)*(double *)(pointByteOffset + points));
      mapData[5] = (int)GH_F2U((float)*(double *)(pointAddr + 8));
      mapData[6] = (int)GH_F2U((float)*(double *)(pointAddr + 0x10));
      mapData = mapData + 3;
      order = order + -1;
    } while (order != 0);
    return;
  }
  return;
}

