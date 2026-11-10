#include "decls.h"

/* _gleBeginLinesRenderTCLRDirty @ 0xd78f4 (60 bytes) */
void _gleBeginLinesRenderTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR__gleRenderLinesTCLFunc_00112214;
  puVar1 = PTR__gleFlushAtomicTCLRDirtyFunc_00112210;
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = puVar2;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleBeginLinesSelectFeedback @ 0xd7930 (76 bytes) */
void _gleBeginLinesSelectFeedback(param_1)
  int param_1;
{
  undefined *puVar1;
  
  *(undefined **)(param_1 + 0x4a0c) = PTR__gleFlushAtomicFunc_00112224;
  puVar1 = PTR__gleFeedbackLinesFunc_00112208;
  if (*(int *)(param_1 + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectLinesFunc_0011220c;
  }
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleBeginLineStripRenderSmooth @ 0xd797c (60 bytes) */
void _gleBeginLineStripRenderSmooth(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleFlushLineStripFunc_00112204;
  puVar1 = PTR__gleRenderSmoothLineStripFunc_00112200;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar2;
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  return;
}

/* _gleBeginLineStripRenderFlat @ 0xd79b8 (60 bytes) */
void _gleBeginLineStripRenderFlat(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleFlushLineStripFunc_00112204;
  puVar1 = PTR__gleRenderFlatLineStripFunc_001121fc;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar2;
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  return;
}

/* _gleBeginLineStripRenderTCLRDirty @ 0xd79f4 (68 bytes) */
void _gleBeginLineStripRenderTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleRenderLineStripTCLFunc_001121f4;
  puVar1 = PTR__gleFlushLineStripTCLRDirtyFunc_001121f0;
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = puVar2;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleBeginLineStripSelectFeedback @ 0xd7a38 (76 bytes) */
void _gleBeginLineStripSelectFeedback(param_1)
  int param_1;
{
  undefined *puVar1;
  
  *(undefined **)(param_1 + 0x4a0c) = PTR__gleFlushLineStripFunc_00112204;
  puVar1 = PTR__gleFeedbackLineStripFunc_001121e8;
  if (*(int *)(param_1 + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectLineStripFunc_001121ec;
  }
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleBeginLineLoopRenderSmooth @ 0xd7a84 (60 bytes) */
void _gleBeginLineLoopRenderSmooth(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleFlushLineLoopFunc_001121e4;
  puVar1 = PTR__gleRenderSmoothLineLoopFunc_001121e0;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar2;
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  return;
}

/* _gleBeginLineLoopRenderFlat @ 0xd7ac0 (60 bytes) */
void _gleBeginLineLoopRenderFlat(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleFlushLineLoopFunc_001121e4;
  puVar1 = PTR__gleRenderFlatLineLoopFunc_001121dc;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar2;
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  return;
}

/* _gleBeginLineLoopRenderTCLRDirty @ 0xd7afc (68 bytes) */
void _gleBeginLineLoopRenderTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  puVar2 = PTR__gleRenderLineLoopTCLFunc_001121d4;
  puVar1 = PTR__gleFlushLineLoopTCLRDirtyFunc_001121d0;
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = puVar2;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleBeginLineLoopSelectFeedback @ 0xd7b40 (84 bytes) */
void _gleBeginLineLoopSelectFeedback(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushLineLoopFunc_001121e4;
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  puVar1 = PTR__gleFeedbackLineLoopFunc_001121c8;
  if (*(int *)(param_1 + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectLineLoopFunc_001121cc;
  }
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
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
int _gleClipLinesPlane(int param_1,int *param_2,int param_3,double fparam_1)
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
        if (fVar7 <= fVar6) {
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
        else if (fVar7 <= fVar5) {
          fVar5 = fVar6 / (fVar6 - fVar5);
          iVar8 = iVar10;
          iVar9 = iVar16;
LAB_000d7dc4:
          (**(int ( **)(int,int,int,int,double))(param_1 + 0x49c8))(param_1, iVar9, iVar8, iVar9, (double)fVar5);
          goto LAB_000d7dd0;
        }
      }
      param_3 = (int)piVar14 - (int)param_2 >> 2;
      iVar10 = 0;
    } while ((1 < param_3) && (iVar12 = iVar12 + 1, iVar10 = param_3, iVar12 < iVar11));
  }
  return iVar10;
}

/* FUN_000d7e1c @ 0xd7e1c (776 bytes) */
void FUN_000d7e1c(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
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
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar2 = true;
  }
  uVar8 = *(uint *)(param_1 + 0x4854);
  if (((int)*(short *)(param_1 + 0x487c) != 0) &&
     (uVar7 = (*(int *)(param_1 + 0x4858) - uVar8) / (uint)(int)*(short *)(param_1 + 0x487c),
     1 < (int)uVar7)) {
    bVar2 = !bVar2;
    if (bVar2) {
      uVar4 = (**(code **)(param_1 + 0x5060))(param_1,uVar8,uVar7);
    }
    else {
      uVar4 = _gleVPEmulate(param_1,uVar7);
    }
    if ((uVar4 & 0xff00) == 0) {
      if (bVar2) {
        if (*(char *)(param_1 + 0x53e4) != '\0') {
          (**(code **)(param_1 + 0x53dc))(param_1,uVar8,uVar7);
        }
        if (*(char *)(param_1 + 0x50b4) != '\0') {
          (**(code **)(param_1 + 0x5064))(param_1,uVar8,uVar7);
        }
        if ((*(char *)(param_1 + 0x30aa) != '\0') || (*(char *)(param_1 + 0x53e6) != '\0')) {
          (**(code **)(param_1 + 0x5068))(param_1,uVar8,uVar7);
        }
      }
      else {
        uVar8 = *(uint *)(param_1 + 0x4864);
      }
      if (((uVar4 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
        if ((bVar2) && (*(char *)(param_1 + 0x53e5) != '\0')) {
          (**(code **)(param_1 + 0x53e0))(param_1,uVar8,uVar7);
        }
        (**(code **)(param_1 + 0x506c))(param_1,uVar8,uVar7,0);
        if ((bVar2) && (*(char *)(param_1 + 0x30aa) != '\0')) {
          (**(code **)(param_1 + 0x4de8))(param_1,uVar8,uVar7);
        }
        iVar5 = uVar8 + uVar7 * 0x100;
        for (; uVar8 < iVar5 - 0x100U; uVar8 = uVar8 + 0x200) {
          ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f2c);
          _gleFeedbackHitRecord(param_1,uVar8);
          _gleFeedbackHitRecord(param_1,uVar8 + 0x100);
        }
        return;
      }
      if ((bVar2) && (*(char *)(param_1 + 0x53e5) != '\0')) {
        (**(code **)(param_1 + 0x53e0))(param_1,uVar8,uVar7);
      }
      dVar10 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, uVar8, uVar7, 0);
      uVar3 = uVar8 + uVar7 * 0x100;
      puVar9 = *(uint **)(param_1 + 0x4870);
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
      if (((*(char *)(param_1 + 0x4e18) == '\0') ||
          (uVar7 = ((int (*)())_gleClipLinesPlane)(param_1,puVar9,uVar7,dVar10), uVar7 != 0)) &&
         (((uVar4 & 0xff) == 0 ||
          (uVar7 = ((int (*)())_gleClipLines)(param_1,puVar9,uVar7,uVar4 & 0xff), uVar7 != 0)))) {
        if ((bVar2) && (*(char *)(param_1 + 0x30aa) != '\0')) {
          (**(code **)(param_1 + 0x4df0))(param_1,puVar9,uVar7);
        }
        dVar10 = DOUBLE_00108d70;
        if (1 < (int)uVar7) {
          puVar6 = puVar9 + 2;
          ((void (*)())_gleFeedbackToken)(param_1,(double)(float)(4503599627372295.0 - DOUBLE_00108d70));
          _gleFeedbackHitRecord(param_1,*puVar9);
          _gleFeedbackHitRecord(param_1,puVar9[1]);
          if (puVar6 < puVar9 + (uVar7 - 1)) {
            do {
              ((void (*)())_gleFeedbackToken)(param_1,(double)(float)(4503599627372295.0 - dVar10));
              _gleFeedbackHitRecord(param_1,*puVar6);
              puVar1 = puVar6 + 1;
              puVar6 = puVar6 + 2;
              _gleFeedbackHitRecord(param_1,*puVar1);
            } while (puVar6 < puVar9 + (uVar7 - 1));
          }
        }
        return;
      }
    }
  }
  return;
}

/* FUN_000d811c @ 0xd811c (828 bytes) */
void FUN_000d811c(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
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
  double extraout_f1;
  
  bVar5 = false;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar5 = true;
  }
  uVar9 = *(uint *)(param_1 + 0x4854);
  if (((int)*(short *)(param_1 + 0x487c) != 0) &&
     (uVar8 = (*(int *)(param_1 + 0x4858) - uVar9) / (uint)(int)*(short *)(param_1 + 0x487c),
     1 < (int)uVar8)) {
    bVar5 = !bVar5;
    if (bVar5) {
      uVar4 = (**(code **)(param_1 + 0x5060))(param_1,uVar9,uVar8);
    }
    else {
      uVar4 = _gleVPEmulate(param_1,uVar8);
    }
    if ((uVar4 & 0xff00) == 0) {
      if (bVar5) {
        if (*(char *)(param_1 + 0x53e4) != '\0') {
          (**(code **)(param_1 + 0x53dc))(param_1,uVar9,uVar8);
        }
        if (*(char *)(param_1 + 0x50b4) != '\0') {
          (**(code **)(param_1 + 0x5064))(param_1,uVar9,uVar8);
        }
        if ((*(char *)(param_1 + 0x30aa) != '\0') || (*(char *)(param_1 + 0x53e6) != '\0')) {
          (**(code **)(param_1 + 0x5068))(param_1,uVar9,uVar8);
        }
      }
      else {
        uVar9 = *(uint *)(param_1 + 0x4864);
      }
      if (((uVar4 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
        if ((bVar5) && (*(char *)(param_1 + 0x53e5) != '\0')) {
          (**(code **)(param_1 + 0x53e0))(param_1,uVar9,uVar8);
        }
        (**(code **)(param_1 + 0x506c))(param_1,uVar9,uVar8,0);
        if ((bVar5) && (*(char *)(param_1 + 0x30aa) != '\0')) {
          (**(code **)(param_1 + 0x4de8))(param_1,uVar9,uVar8);
        }
        dVar11 = DOUBLE_00108d70;
        bVar5 = *(char *)(param_1 + 0x4a18) == '\0';
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
          ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar2) -
                                                   DOUBLE_00108d70));
          _gleFeedbackHitRecord(param_1,uVar9);
          _gleFeedbackHitRecord(param_1,uVar4);
          uVar9 = (uVar9 + uVar8 * 0x100) - 0x100;
          if (uVar4 < uVar9) {
            do {
              uVar8 = uVar4 + 0x100;
              ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar6) - dVar11)
                               );
              _gleFeedbackHitRecord(param_1,uVar4);
              _gleFeedbackHitRecord(param_1,uVar8);
              uVar4 = uVar8;
            } while (uVar8 < uVar9);
          }
        }
        return;
      }
      if ((bVar5) && (*(char *)(param_1 + 0x53e5) != '\0')) {
        (**(code **)(param_1 + 0x53e0))(param_1,uVar9,uVar8);
      }
      dVar11 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, uVar9, uVar8, 0);
      puVar7 = *(uint **)(param_1 + 0x4870);
      iVar3 = uVar9 + uVar8 * 0x100;
      puVar10 = puVar7;
      if (bVar5) {
        uVar8 = *(uint *)(param_1 + 0x4858);
      }
      else {
        uVar8 = *(uint *)(param_1 + 0x4854);
      }
      while (uVar9 < iVar3 - 0x100U) {
        *puVar10 = uVar9;
        _memcpy(uVar8,uVar9 + 0x100,0x100);
        puVar10[1] = uVar8;
        uVar8 = uVar8 + 0x100;
        puVar10 = puVar10 + 2;
        uVar9 = uVar9 + 0x100;
        dVar11 = extraout_f1;
      }
      iVar3 = (int)puVar10 - (int)puVar7 >> 2;
      if (((*(char *)(param_1 + 0x4e18) == '\0') ||
          (iVar3 = ((int (*)())_gleClipLinesPlane)(param_1,puVar7,iVar3,dVar11), iVar3 != 0)) &&
         (((uVar4 & 0xff) == 0 ||
          (iVar3 = ((int (*)())_gleClipLines)(param_1,puVar7,iVar3,uVar4 & 0xff), iVar3 != 0)))) {
        if ((bVar5) && (*(char *)(param_1 + 0x30aa) != '\0')) {
          (**(code **)(param_1 + 0x4df0))(param_1,puVar7,iVar3);
        }
        dVar11 = DOUBLE_00108d70;
        bVar5 = *(char *)(param_1 + 0x4a18) == '\0';
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
          ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar2) -
                                                   DOUBLE_00108d70));
          _gleFeedbackHitRecord(param_1,*puVar7);
          _gleFeedbackHitRecord(param_1,puVar7[1]);
          if (puVar10 < puVar7 + iVar3 + -1) {
            do {
              ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar6) - dVar11)
                               );
              _gleFeedbackHitRecord(param_1,*puVar10);
              puVar1 = puVar10 + 1;
              puVar10 = puVar10 + 2;
              _gleFeedbackHitRecord(param_1,*puVar1);
            } while (puVar10 < puVar7 + iVar3 + -1);
          }
        }
        return;
      }
    }
  }
  return;
}

/* FUN_000d845c @ 0xd845c (932 bytes) */
void FUN_000d845c(param_1)
  int param_1;
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
  double extraout_f1;
  
  bVar6 = false;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar6 = true;
  }
  sVar9 = *(short *)(param_1 + 0x487c);
  uVar12 = *(uint *)(param_1 + 0x4854);
  if ((int)sVar9 != 0) {
    iVar7 = *(int *)(param_1 + 0x4858);
    uVar14 = (iVar7 - uVar12) / (uint)(int)sVar9;
    if (*(short *)(param_1 + 0x4a10) < 0) {
      if ((int)uVar14 < 1) {
        return;
      }
      uVar5 = uVar12 - 0x100;
      if (*(char *)(param_1 + 0x4a18) == '\0') {
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
        sVar9 = *(short *)(param_1 + 0x487c);
      }
      uVar14 = uVar14 + 1;
      *(int *)(param_1 + 0x4858) = iVar7 + sVar9;
    }
    bVar6 = !bVar6;
    if (bVar6) {
      uVar5 = (**(code **)(param_1 + 0x5060))(param_1,uVar12,uVar14);
    }
    else {
      uVar5 = _gleVPEmulate(param_1,uVar14);
    }
    if ((uVar5 & 0xff00) == 0) {
      if (bVar6) {
        if (*(char *)(param_1 + 0x53e4) != '\0') {
          (**(code **)(param_1 + 0x53dc))(param_1,uVar12,uVar14);
        }
        if (*(char *)(param_1 + 0x50b4) != '\0') {
          (**(code **)(param_1 + 0x5064))(param_1,uVar12,uVar14);
        }
        if ((*(char *)(param_1 + 0x30aa) != '\0') || (*(char *)(param_1 + 0x53e6) != '\0')) {
          (**(code **)(param_1 + 0x5068))(param_1,uVar12,uVar14);
        }
      }
      else {
        uVar12 = *(uint *)(param_1 + 0x4864);
      }
      if (((uVar5 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
        if ((bVar6) && (*(char *)(param_1 + 0x53e5) != '\0')) {
          (**(code **)(param_1 + 0x53e0))(param_1,uVar12,uVar14);
        }
        (**(code **)(param_1 + 0x506c))(param_1,uVar12,uVar14,0);
        if ((bVar6) && (*(char *)(param_1 + 0x30aa) != '\0')) {
          (**(code **)(param_1 + 0x4de8))(param_1,uVar12,uVar14);
        }
        dVar15 = DOUBLE_00108d70;
        bVar6 = *(char *)(param_1 + 0x4a18) == '\0';
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
          ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar3) -
                                                   DOUBLE_00108d70));
          _gleFeedbackHitRecord(param_1,uVar12);
          _gleFeedbackHitRecord(param_1,uVar5);
          uVar12 = (uVar12 + uVar14 * 0x100) - 0x100;
          if (uVar5 < uVar12) {
            do {
              uVar14 = uVar5 + 0x100;
              ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar10) - dVar15
                                                       ));
              _gleFeedbackHitRecord(param_1,uVar5);
              _gleFeedbackHitRecord(param_1,uVar14);
              uVar5 = uVar14;
            } while (uVar14 < uVar12);
          }
        }
        return;
      }
      if ((bVar6) && (*(char *)(param_1 + 0x53e5) != '\0')) {
        (**(code **)(param_1 + 0x53e0))(param_1,uVar12,uVar14);
      }
      dVar15 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, uVar12, uVar14, 0);
      puVar11 = *(uint **)(param_1 + 0x4870);
      iVar7 = uVar12 + uVar14 * 0x100;
      puVar13 = puVar11;
      if (bVar6) {
        uVar14 = *(uint *)(param_1 + 0x4858);
      }
      else {
        uVar14 = *(uint *)(param_1 + 0x4854);
      }
      while (uVar12 < iVar7 - 0x100U) {
        *puVar13 = uVar12;
        _memcpy(uVar14,uVar12 + 0x100,0x100);
        puVar13[1] = uVar14;
        uVar14 = uVar14 + 0x100;
        puVar13 = puVar13 + 2;
        uVar12 = uVar12 + 0x100;
        dVar15 = extraout_f1;
      }
      iVar7 = (int)puVar13 - (int)puVar11 >> 2;
      if (((*(char *)(param_1 + 0x4e18) == '\0') ||
          (iVar7 = ((int (*)())_gleClipLinesPlane)(param_1,puVar11,iVar7,dVar15), iVar7 != 0)) &&
         (((uVar5 & 0xff) == 0 ||
          (iVar7 = ((int (*)())_gleClipLines)(param_1,puVar11,iVar7,uVar5 & 0xff), iVar7 != 0)))) {
        if ((bVar6) && (*(char *)(param_1 + 0x30aa) != '\0')) {
          (**(code **)(param_1 + 0x4df0))(param_1,puVar11,iVar7);
        }
        dVar15 = DOUBLE_00108d70;
        bVar6 = *(char *)(param_1 + 0x4a18) == '\0';
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
          ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar3) -
                                                   DOUBLE_00108d70));
          _gleFeedbackHitRecord(param_1,*puVar11);
          _gleFeedbackHitRecord(param_1,puVar11[1]);
          if (puVar13 < puVar11 + iVar7 + -1) {
            do {
              ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar10) - dVar15
                                                       ));
              _gleFeedbackHitRecord(param_1,*puVar13);
              puVar1 = puVar13 + 1;
              puVar13 = puVar13 + 2;
              _gleFeedbackHitRecord(param_1,*puVar1);
            } while (puVar13 < puVar11 + iVar7 + -1);
          }
        }
        return;
      }
    }
  }
  return;
}

/* FUN_000d8828 @ 0xd8828 (716 bytes) */
void FUN_000d8828(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  double extraout_f1;
  double fparam_1;
  
  iVar3 = _gleTexEnableBits(param_1);
  uVar6 = *(uint *)(param_1 + 0x4854);
  iVar8 = (int)(*(int *)(param_1 + 0x4858) - uVar6) >> 8;
  if ((1 < iVar8) &&
     (uVar4 = (**(code **)(param_1 + 0x5060))(param_1,uVar6,iVar8), (uVar4 & 0xff00) == 0)) {
    bVar1 = iVar3 != 0;
    fparam_1 = extraout_f1;
    if ((bVar1) && (*(char *)(param_1 + 0x53e4) != '\0')) {
      fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53dc))(param_1, uVar6, iVar8);
    }
    if (*(char *)(param_1 + 0x50b4) != '\0') {
      fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, uVar6, iVar8);
    }
    if ((*(char *)(param_1 + 0x30aa) != '\0') || ((bVar1 && (*(char *)(param_1 + 0x53e6) != '\0'))))
    {
      fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, uVar6, iVar8);
    }
    if (((uVar4 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      if (bVar1) {
        if (*(char *)(param_1 + 0x53e5) != '\0') {
          (**(code **)(param_1 + 0x53e0))(param_1,uVar6,iVar8);
        }
        (**(code **)(param_1 + 0x506c))(param_1,uVar6,iVar8,0);
      }
      if (*(char *)(param_1 + 0x30aa) != '\0') {
        (**(code **)(param_1 + 0x4de8))(param_1,uVar6,iVar8);
      }
                    
                    
      (**(code **)(param_1 + 0x46b4))(*(undefined4 *)(param_1 + 0x4688),uVar6,iVar8);
      return;
    }
    if (bVar1) {
      if (*(char *)(param_1 + 0x53e5) != '\0') {
        (**(code **)(param_1 + 0x53e0))(param_1,uVar6,iVar8);
      }
      fparam_1 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, uVar6, iVar8, 0);
    }
    uVar2 = uVar6 + iVar8 * 0x100;
    puVar7 = *(uint **)(param_1 + 0x4870);
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
    if ((*(char *)(param_1 + 0x4e18) != '\0') &&
       (iVar8 = ((int (*)())_gleClipLinesPlane)(param_1,puVar7,iVar8,fparam_1), iVar8 == 0)) {
      return;
    }
    if (((uVar4 & 0xff) == 0) ||
       (iVar8 = ((int (*)())_gleClipLines)(param_1,puVar7,iVar8,uVar4 & 0xff), iVar8 != 0)) {
      if (*(char *)(param_1 + 0x30aa) != '\0') {
        (**(code **)(param_1 + 0x4df0))(param_1,puVar7,iVar8);
      }
                    
                    
      (**(code **)(param_1 + 0x46dc))(*(undefined4 *)(param_1 + 0x4688),puVar7,iVar8,2);
      return;
    }
  }
  return;
}

/* FUN_000d8af8 @ 0xd8af8 (728 bytes) */
void FUN_000d8af8(param_1)
  int param_1;
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
  double extraout_f1;
  double fparam_1;
  double extraout_f1_00;
  
  iVar4 = _gleTexEnableBits(param_1);
  puVar8 = *(uint **)(param_1 + 0x4854);
  iVar9 = *(int *)(param_1 + 0x4858) - (int)puVar8 >> 8;
  if ((iVar9 < 2) ||
     (uVar5 = (**(code **)(param_1 + 0x5060))(param_1,puVar8,iVar9), (uVar5 & 0xff00) != 0)) {
    return;
  }
  bVar1 = iVar4 != 0;
  fparam_1 = extraout_f1;
  if ((bVar1) && (*(char *)(param_1 + 0x53e4) != '\0')) {
    fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53dc))(param_1, puVar8, iVar9);
  }
  if (*(char *)(param_1 + 0x50b4) != '\0') {
    fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, puVar8, iVar9);
  }
  if ((*(char *)(param_1 + 0x30aa) != '\0') || ((bVar1 && (*(char *)(param_1 + 0x53e6) != '\0')))) {
    fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, puVar8, iVar9);
  }
  if (((uVar5 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
    if (bVar1) {
      if (*(char *)(param_1 + 0x53e5) != '\0') {
        (**(code **)(param_1 + 0x53e0))(param_1,puVar8,iVar9);
      }
      (**(code **)(param_1 + 0x506c))(param_1,puVar8,iVar9,0);
    }
    if (*(char *)(param_1 + 0x30aa) != '\0') {
      (**(code **)(param_1 + 0x4de8))(param_1,puVar8,iVar9);
    }
    cVar2 = *(char *)(param_1 + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x46b8);
    puVar6 = puVar8;
  }
  else {
    if (bVar1) {
      if (*(char *)(param_1 + 0x53e5) != '\0') {
        (**(code **)(param_1 + 0x53e0))(param_1,puVar8,iVar9);
      }
      fparam_1 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, puVar8, iVar9, 0);
    }
    puVar6 = *(uint **)(param_1 + 0x4870);
    uVar10 = *(uint *)(param_1 + 0x4858);
    puVar3 = puVar8;
    puVar7 = puVar6;
    while (puVar3 < puVar8 + iVar9 * 0x40 + -0x40) {
      *puVar7 = (uint)puVar3;
      _memcpy(uVar10,puVar3 + 0x40,0x100);
      puVar7[1] = uVar10;
      uVar10 = uVar10 + 0x100;
      puVar7 = puVar7 + 2;
      puVar3 = puVar3 + 0x40;
      fparam_1 = extraout_f1_00;
    }
    iVar9 = (int)puVar7 - (int)puVar6 >> 2;
    if ((*(char *)(param_1 + 0x4e18) != '\0') &&
       (iVar9 = ((int (*)())_gleClipLinesPlane)(param_1,puVar6,iVar9,fparam_1), iVar9 == 0)) {
      return;
    }
    if (((uVar5 & 0xff) != 0) &&
       (iVar9 = ((int (*)())_gleClipLines)(param_1,puVar6,iVar9,uVar5 & 0xff), iVar9 == 0)) {
      return;
    }
    if (*(char *)(param_1 + 0x30aa) != '\0') {
      (**(code **)(param_1 + 0x4df0))(param_1,puVar6,iVar9);
    }
    cVar2 = *(char *)(param_1 + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x46dc);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(param_1 + 0x4688),puVar6,iVar9,cVar2 == '\0');
  return;
}

/* FUN_000d8dd4 @ 0xd8dd4 (824 bytes) */
void FUN_000d8dd4(param_1)
  int param_1;
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
  double extraout_f1;
  double fparam_1;
  double extraout_f1_00;
  
  iVar5 = _gleTexEnableBits(param_1);
  puVar12 = *(uint **)(param_1 + 0x4854);
  iVar8 = *(int *)(param_1 + 0x4858);
  iVar13 = iVar8 - (int)puVar12 >> 8;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (iVar13 < 1) {
      return;
    }
    puVar7 = puVar12 + -0x40;
    if (*(char *)(param_1 + 0x4a18) == '\0') {
      puVar7 = puVar12;
    }
    sVar4 = *(short *)(param_1 + 0x487c);
    iVar9 = 0;
    iVar3 = (int)sVar4 >> 3;
    if (0 < iVar3) {
      do {
        *(undefined8 *)(iVar9 * 8 + iVar8) = *(undefined8 *)(puVar7 + iVar9 * 2);
        iVar3 = iVar3 + -1;
        iVar9 = iVar9 + 1;
      } while (iVar3 != 0);
      sVar4 = *(short *)(param_1 + 0x487c);
    }
    iVar13 = iVar13 + 1;
    *(int *)(param_1 + 0x4858) = iVar8 + sVar4;
  }
  uVar6 = (**(code **)(param_1 + 0x5060))(param_1,puVar12,iVar13);
  if ((uVar6 & 0xff00) != 0) {
    return;
  }
  bVar1 = iVar5 != 0;
  fparam_1 = extraout_f1;
  if ((bVar1) && (*(char *)(param_1 + 0x53e4) != '\0')) {
    fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53dc))(param_1, puVar12, iVar13);
  }
  if (*(char *)(param_1 + 0x50b4) != '\0') {
    fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, puVar12, iVar13);
  }
  if ((*(char *)(param_1 + 0x30aa) != '\0') || ((bVar1 && (*(char *)(param_1 + 0x53e6) != '\0')))) {
    fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, puVar12, iVar13);
  }
  if (((uVar6 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
    if (bVar1) {
      if (*(char *)(param_1 + 0x53e5) != '\0') {
        (**(code **)(param_1 + 0x53e0))(param_1,puVar12,iVar13);
      }
      (**(code **)(param_1 + 0x506c))(param_1,puVar12,iVar13,0);
    }
    if (*(char *)(param_1 + 0x30aa) != '\0') {
      (**(code **)(param_1 + 0x4de8))(param_1,puVar12,iVar13);
    }
    cVar2 = *(char *)(param_1 + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x46b8);
    puVar10 = puVar12;
  }
  else {
    if (bVar1) {
      if (*(char *)(param_1 + 0x53e5) != '\0') {
        (**(code **)(param_1 + 0x53e0))(param_1,puVar12,iVar13);
      }
      fparam_1 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, puVar12, iVar13, 0);
    }
    puVar10 = *(uint **)(param_1 + 0x4870);
    uVar14 = *(uint *)(param_1 + 0x4858);
    puVar7 = puVar12;
    puVar11 = puVar10;
    while (puVar7 < puVar12 + iVar13 * 0x40 + -0x40) {
      *puVar11 = (uint)puVar7;
      _memcpy(uVar14,puVar7 + 0x40,0x100);
      puVar11[1] = uVar14;
      uVar14 = uVar14 + 0x100;
      puVar11 = puVar11 + 2;
      puVar7 = puVar7 + 0x40;
      fparam_1 = extraout_f1_00;
    }
    iVar13 = (int)puVar11 - (int)puVar10 >> 2;
    if ((*(char *)(param_1 + 0x4e18) != '\0') &&
       (iVar13 = ((int (*)())_gleClipLinesPlane)(param_1,puVar10,iVar13,fparam_1), iVar13 == 0)) {
      return;
    }
    if (((uVar6 & 0xff) != 0) &&
       (iVar13 = ((int (*)())_gleClipLines)(param_1,puVar10,iVar13,uVar6 & 0xff), iVar13 == 0)) {
      return;
    }
    if (*(char *)(param_1 + 0x30aa) != '\0') {
      (**(code **)(param_1 + 0x4df0))(param_1,puVar10,iVar13);
    }
    cVar2 = *(char *)(param_1 + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x46dc);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(param_1 + 0x4688),puVar10,iVar13,cVar2 == '\0');
  return;
}

/* FUN_000d9110 @ 0xd9110 (780 bytes) */
void FUN_000d9110(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  double extraout_f1;
  double fparam_1;
  
  iVar2 = _gleTexEnableBits(param_1);
  uVar7 = *(uint *)(param_1 + 0x4854);
  iVar6 = (int)(*(int *)(param_1 + 0x4858) - uVar7) >> 8;
  if ((1 < iVar6) &&
     (uVar3 = (**(code **)(param_1 + 0x5060))(param_1,uVar7,iVar6), (uVar3 & 0xff00) == 0)) {
    bVar1 = iVar2 != 0;
    fparam_1 = extraout_f1;
    if ((bVar1) && (*(char *)(param_1 + 0x53e4) != '\0')) {
      fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53dc))(param_1, uVar7, iVar6);
    }
    if (*(char *)(param_1 + 0x50b4) != '\0') {
      fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, uVar7, iVar6);
    }
    if ((*(char *)(param_1 + 0x30aa) != '\0') || ((bVar1 && (*(char *)(param_1 + 0x53e6) != '\0'))))
    {
      fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, uVar7, iVar6);
    }
    if (((uVar3 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      if (bVar1) {
        if (*(char *)(param_1 + 0x53e5) != '\0') {
          (**(code **)(param_1 + 0x53e0))(param_1,uVar7,iVar6);
        }
        (**(code **)(param_1 + 0x506c))(param_1,uVar7,iVar6,0);
      }
      if (*(char *)(param_1 + 0x30aa) != '\0') {
        for (uVar3 = uVar7 + 0x100; uVar3 < uVar7 + iVar6 * 0x100; uVar3 = uVar3 + 0x200) {
          (**(code **)(param_1 + 0x4de8))(param_1,uVar3,1);
        }
      }
                    
                    
      (**(code **)(param_1 + 0x46b4))(*(undefined4 *)(param_1 + 0x4688),uVar7,iVar6);
      return;
    }
    if (bVar1) {
      if (*(char *)(param_1 + 0x53e5) != '\0') {
        (**(code **)(param_1 + 0x53e0))(param_1,uVar7,iVar6);
      }
      fparam_1 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, uVar7, iVar6, 0);
    }
    puVar4 = *(uint **)(param_1 + 0x4870);
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
    if (((*(char *)(param_1 + 0x4e18) == '\0') ||
        (iVar6 = ((int (*)())_gleClipLinesPlane)(param_1,puVar4,iVar6,fparam_1), iVar6 != 0)) &&
       (((uVar3 & 0xff) == 0 ||
        (iVar6 = ((int (*)())_gleClipLines)(param_1,puVar4,iVar6,uVar3 & 0xff), iVar6 != 0)))) {
      if (*(char *)(param_1 + 0x30aa) != '\0') {
        for (puVar8 = puVar4 + 1; puVar8 < puVar4 + iVar6; puVar8 = puVar8 + 2) {
          (**(code **)(param_1 + 0x4df0))(param_1,puVar8,1);
        }
      }
                    
                    
      (**(code **)(param_1 + 0x46dc))(*(undefined4 *)(param_1 + 0x4688),puVar4,iVar6,2);
      return;
    }
  }
  return;
}

/* FUN_000d9420 @ 0xd9420 (760 bytes) */
void FUN_000d9420(param_1)
  int param_1;
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
  double extraout_f1;
  double fparam_1;
  double extraout_f1_00;
  
  iVar4 = _gleTexEnableBits(param_1);
  puVar9 = *(uint **)(param_1 + 0x4854);
  iVar7 = *(int *)(param_1 + 0x4858) - (int)puVar9 >> 8;
  if ((iVar7 < 2) ||
     (uVar5 = (**(code **)(param_1 + 0x5060))(param_1,puVar9,iVar7), (uVar5 & 0xff00) != 0)) {
    return;
  }
  bVar1 = iVar4 != 0;
  fparam_1 = extraout_f1;
  if ((bVar1) && (*(char *)(param_1 + 0x53e4) != '\0')) {
    fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53dc))(param_1, puVar9, iVar7);
  }
  if (*(char *)(param_1 + 0x50b4) != '\0') {
    fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, puVar9, iVar7);
  }
  if ((*(char *)(param_1 + 0x30aa) != '\0') || ((bVar1 && (*(char *)(param_1 + 0x53e6) != '\0')))) {
    fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, puVar9, iVar7);
  }
  if (((uVar5 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
    if (bVar1) {
      if (*(char *)(param_1 + 0x53e5) != '\0') {
        (**(code **)(param_1 + 0x53e0))(param_1,puVar9,iVar7);
      }
      (**(code **)(param_1 + 0x506c))(param_1,puVar9,iVar7,0);
    }
    if (*(char *)(param_1 + 0x30aa) != '\0') {
      (**(code **)(param_1 + 0x4de8))(param_1,puVar9 + 0x40,iVar7 + -1);
    }
    cVar2 = *(char *)(param_1 + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x46b8);
    puVar6 = puVar9;
  }
  else {
    if (bVar1) {
      if (*(char *)(param_1 + 0x53e5) != '\0') {
        (**(code **)(param_1 + 0x53e0))(param_1,puVar9,iVar7);
      }
      fparam_1 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, puVar9, iVar7, 0);
    }
    puVar6 = *(uint **)(param_1 + 0x4870);
    uVar8 = *(uint *)(param_1 + 0x4858);
    puVar3 = puVar9;
    puVar10 = puVar6;
    while (puVar3 < puVar9 + iVar7 * 0x40 + -0x40) {
      *puVar10 = (uint)puVar3;
      _memcpy(uVar8,puVar3 + 0x40,0x100);
      puVar10[1] = uVar8;
      uVar8 = uVar8 + 0x100;
      puVar10 = puVar10 + 2;
      puVar3 = puVar3 + 0x40;
      fparam_1 = extraout_f1_00;
    }
    iVar7 = (int)puVar10 - (int)puVar6 >> 2;
    if ((*(char *)(param_1 + 0x4e18) != '\0') &&
       (iVar7 = ((int (*)())_gleClipLinesPlane)(param_1,puVar6,iVar7,fparam_1), iVar7 == 0)) {
      return;
    }
    if (((uVar5 & 0xff) != 0) &&
       (iVar7 = ((int (*)())_gleClipLines)(param_1,puVar6,iVar7,uVar5 & 0xff), iVar7 == 0)) {
      return;
    }
    if (*(char *)(param_1 + 0x30aa) != '\0') {
      for (puVar9 = puVar6 + 1; puVar9 < puVar6 + iVar7; puVar9 = puVar9 + 2) {
        (**(code **)(param_1 + 0x4df0))(param_1,puVar9,1);
      }
    }
    cVar2 = *(char *)(param_1 + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x46dc);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(param_1 + 0x4688),puVar6,iVar7,cVar2 == '\0');
  return;
}

/* FUN_000d971c @ 0xd971c (856 bytes) */
void FUN_000d971c(param_1)
  int param_1;
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
  double extraout_f1;
  double fparam_1;
  double extraout_f1_00;
  
  iVar5 = _gleTexEnableBits(param_1);
  puVar13 = *(uint **)(param_1 + 0x4854);
  iVar8 = *(int *)(param_1 + 0x4858);
  iVar12 = iVar8 - (int)puVar13 >> 8;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (iVar12 < 1) {
      return;
    }
    puVar7 = puVar13 + -0x40;
    if (*(char *)(param_1 + 0x4a18) == '\0') {
      puVar7 = puVar13;
    }
    sVar4 = *(short *)(param_1 + 0x487c);
    iVar9 = 0;
    iVar3 = (int)sVar4 >> 3;
    if (0 < iVar3) {
      do {
        *(undefined8 *)(iVar9 * 8 + iVar8) = *(undefined8 *)(puVar7 + iVar9 * 2);
        iVar3 = iVar3 + -1;
        iVar9 = iVar9 + 1;
      } while (iVar3 != 0);
      sVar4 = *(short *)(param_1 + 0x487c);
    }
    iVar12 = iVar12 + 1;
    *(int *)(param_1 + 0x4858) = iVar8 + sVar4;
  }
  uVar6 = (**(code **)(param_1 + 0x5060))(param_1,puVar13,iVar12);
  if ((uVar6 & 0xff00) != 0) {
    return;
  }
  bVar1 = iVar5 != 0;
  fparam_1 = extraout_f1;
  if ((bVar1) && (*(char *)(param_1 + 0x53e4) != '\0')) {
    fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x53dc))(param_1, puVar13, iVar12);
  }
  if (*(char *)(param_1 + 0x50b4) != '\0') {
    fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, puVar13, iVar12);
  }
  if ((*(char *)(param_1 + 0x30aa) != '\0') || ((bVar1 && (*(char *)(param_1 + 0x53e6) != '\0')))) {
    fparam_1 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5068))(param_1, puVar13, iVar12);
  }
  if (((uVar6 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
    if (bVar1) {
      if (*(char *)(param_1 + 0x53e5) != '\0') {
        (**(code **)(param_1 + 0x53e0))(param_1,puVar13,iVar12);
      }
      (**(code **)(param_1 + 0x506c))(param_1,puVar13,iVar12,0);
    }
    if (*(char *)(param_1 + 0x30aa) != '\0') {
      (**(code **)(param_1 + 0x4de8))(param_1,puVar13 + 0x40,iVar12 + -1);
    }
    cVar2 = *(char *)(param_1 + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x46b8);
    puVar10 = puVar13;
  }
  else {
    if (bVar1) {
      if (*(char *)(param_1 + 0x53e5) != '\0') {
        (**(code **)(param_1 + 0x53e0))(param_1,puVar13,iVar12);
      }
      fparam_1 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, puVar13, iVar12, 0);
    }
    puVar10 = *(uint **)(param_1 + 0x4870);
    uVar11 = *(uint *)(param_1 + 0x4858);
    puVar7 = puVar13;
    puVar14 = puVar10;
    while (puVar7 < puVar13 + iVar12 * 0x40 + -0x40) {
      *puVar14 = (uint)puVar7;
      _memcpy(uVar11,puVar7 + 0x40,0x100);
      puVar14[1] = uVar11;
      uVar11 = uVar11 + 0x100;
      puVar14 = puVar14 + 2;
      puVar7 = puVar7 + 0x40;
      fparam_1 = extraout_f1_00;
    }
    iVar12 = (int)puVar14 - (int)puVar10 >> 2;
    if ((*(char *)(param_1 + 0x4e18) != '\0') &&
       (iVar12 = ((int (*)())_gleClipLinesPlane)(param_1,puVar10,iVar12,fparam_1), iVar12 == 0)) {
      return;
    }
    if (((uVar6 & 0xff) != 0) &&
       (iVar12 = ((int (*)())_gleClipLines)(param_1,puVar10,iVar12,uVar6 & 0xff), iVar12 == 0)) {
      return;
    }
    if (*(char *)(param_1 + 0x30aa) != '\0') {
      for (puVar13 = puVar10 + 1; puVar13 < puVar10 + iVar12; puVar13 = puVar13 + 2) {
        (**(code **)(param_1 + 0x4df0))(param_1,puVar13,1);
      }
    }
    cVar2 = *(char *)(param_1 + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x46dc);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(param_1 + 0x4688),puVar10,iVar12,cVar2 == '\0');
  return;
}

/* _gleSelectLinesFunc @ 0xd9a74 (412 bytes) */
void _gleSelectLinesFunc(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  double extraout_f1;
  double dVar8;
  
  bVar1 = false;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar1 = true;
  }
  uVar6 = *(uint *)(param_1 + 0x4854);
  if ((((int)*(short *)(param_1 + 0x487c) != 0) &&
      (uVar5 = (*(int *)(param_1 + 0x4858) - uVar6) / (uint)(int)*(short *)(param_1 + 0x487c),
      1 < (int)uVar5)) &&
     (uVar3 = (**(code **)(param_1 + 0x5060))(param_1,uVar6,uVar5), (uVar3 & 0xff00) == 0)) {
    dVar8 = extraout_f1;
    if (bVar1) {
      uVar6 = *(uint *)(param_1 + 0x4864);
    }
    else if (*(char *)(param_1 + 0x4e18) != '\0') {
      dVar8 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, uVar6, uVar5);
    }
    if (((uVar3 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      _gleSelectLines(param_1,uVar6,uVar5);
      return;
    }
    uVar2 = uVar6 + uVar5 * 0x100;
    puVar7 = *(uint **)(param_1 + 0x4870);
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
    if ((*(char *)(param_1 + 0x4e18) != '\0') &&
       (uVar5 = ((int (*)())_gleClipLinesPlane)(param_1,puVar7,uVar5,dVar8), uVar5 == 0)) {
      return;
    }
    if (((uVar3 & 0xff) == 0) ||
       (uVar5 = ((int (*)())_gleClipLines)(param_1,puVar7,uVar5,uVar3 & 0xff), uVar5 != 0)) {
      _gleSelectLinesPtr(param_1,puVar7,uVar5);
      return;
    }
  }
  return;
}

/* FUN_000d9c14 @ 0xd9c14 (484 bytes) */
void FUN_000d9c14(param_1)
  int param_1;
{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  double extraout_f1;
  double dVar8;
  double extraout_f1_00;
  
  bVar1 = false;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar1 = true;
  }
  uVar7 = *(uint *)(param_1 + 0x4854);
  if ((((int)*(short *)(param_1 + 0x487c) != 0) &&
      (uVar6 = (*(int *)(param_1 + 0x4858) - uVar7) / (uint)(int)*(short *)(param_1 + 0x487c),
      1 < (int)uVar6)) &&
     (uVar4 = (**(code **)(param_1 + 0x5060))(param_1,uVar7,uVar6), (uVar4 & 0xff00) == 0)) {
    dVar8 = extraout_f1;
    if (bVar1) {
      uVar7 = *(uint *)(param_1 + 0x4864);
    }
    else if (*(char *)(param_1 + 0x4e18) != '\0') {
      dVar8 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, uVar7, uVar6);
    }
    if (((uVar4 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
      _gleSelectLineStrip(param_1,uVar7,uVar6);
      return;
    }
    puVar5 = *(uint **)(param_1 + 0x4870);
    iVar3 = uVar7 + uVar6 * 0x100;
    puVar2 = puVar5;
    if (bVar1) {
      uVar6 = *(uint *)(param_1 + 0x4854);
    }
    else {
      uVar6 = *(uint *)(param_1 + 0x4858);
    }
    while (uVar7 < iVar3 - 0x100U) {
      *puVar2 = uVar7;
      _memcpy(uVar6,uVar7 + 0x100,0x100);
      puVar2[1] = uVar6;
      uVar6 = uVar6 + 0x100;
      puVar2 = puVar2 + 2;
      uVar7 = uVar7 + 0x100;
      dVar8 = extraout_f1_00;
    }
    iVar3 = (int)puVar2 - (int)puVar5 >> 2;
    if (((*(char *)(param_1 + 0x4e18) == '\0') ||
        (iVar3 = ((int (*)())_gleClipLinesPlane)(param_1,puVar5,iVar3,dVar8), iVar3 != 0)) &&
       (((uVar4 & 0xff) == 0 ||
        (iVar3 = ((int (*)())_gleClipLines)(param_1,puVar5,iVar3,uVar4 & 0xff), iVar3 != 0)))) {
      _gleSelectLinesPtr(param_1,puVar5,iVar3);
      return;
    }
  }
  return;
}

/* FUN_000d9dfc @ 0xd9dfc (588 bytes) */
void FUN_000d9dfc(param_1)
  int param_1;
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
  double extraout_f1;
  double dVar12;
  double extraout_f1_00;
  
  bVar2 = false;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar2 = true;
  }
  sVar7 = *(short *)(param_1 + 0x487c);
  uVar10 = *(uint *)(param_1 + 0x4854);
  if ((int)sVar7 != 0) {
    iVar6 = *(int *)(param_1 + 0x4858);
    uVar11 = (iVar6 - uVar10) / (uint)(int)sVar7;
    if (*(short *)(param_1 + 0x4a10) < 0) {
      if ((int)uVar11 < 1) {
        return;
      }
      uVar5 = uVar10 - 0x100;
      if (*(char *)(param_1 + 0x4a18) == '\0') {
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
        sVar7 = *(short *)(param_1 + 0x487c);
      }
      uVar11 = uVar11 + 1;
      *(int *)(param_1 + 0x4858) = iVar6 + sVar7;
    }
    uVar5 = (**(code **)(param_1 + 0x5060))(param_1,uVar10,uVar11);
    if ((uVar5 & 0xff00) == 0) {
      dVar12 = extraout_f1;
      if (bVar2) {
        uVar10 = *(uint *)(param_1 + 0x4864);
      }
      else if (*(char *)(param_1 + 0x4e18) != '\0') {
        dVar12 = (double)(**(double ( **)(int,int,int))(param_1 + 0x5064))(param_1, uVar10, uVar11);
      }
      if (((uVar5 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
        _gleSelectLineStrip(param_1,uVar10,uVar11);
        return;
      }
      puVar9 = *(uint **)(param_1 + 0x4870);
      iVar6 = uVar10 + uVar11 * 0x100;
      puVar3 = puVar9;
      if (bVar2) {
        uVar11 = *(uint *)(param_1 + 0x4854);
      }
      else {
        uVar11 = *(uint *)(param_1 + 0x4858);
      }
      while (uVar10 < iVar6 - 0x100U) {
        *puVar3 = uVar10;
        _memcpy(uVar11,uVar10 + 0x100,0x100);
        puVar3[1] = uVar11;
        uVar11 = uVar11 + 0x100;
        puVar3 = puVar3 + 2;
        uVar10 = uVar10 + 0x100;
        dVar12 = extraout_f1_00;
      }
      iVar6 = (int)puVar3 - (int)puVar9 >> 2;
      if (((*(char *)(param_1 + 0x4e18) == '\0') ||
          (iVar6 = ((int (*)())_gleClipLinesPlane)(param_1,puVar9,iVar6,dVar12), iVar6 != 0)) &&
         (((uVar5 & 0xff) == 0 ||
          (iVar6 = ((int (*)())_gleClipLines)(param_1,puVar9,iVar6,uVar5 & 0xff), iVar6 != 0)))) {
        _gleSelectLinesPtr(param_1,puVar9,iVar6);
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
int _gleCompileTCLVertexArray(param_1)
  int param_1;
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
  if (*(int *)(param_1 + 0x49ac) == 0) {
    return param_1;
  }
  iVar16 = *(int *)(param_1 + 0x4988);
  uVar14 = *(undefined4 *)(param_1 + 0x49a4);
  uVar2 = *(ushort *)(param_1 + 0x4990);
  uVar18 = *(uint *)(param_1 + 0x4980);
  if (*(short *)(param_1 + 0x4992) == 0) {
    uVar18 = uVar18 & 0xffff;
    *(undefined2 *)(param_1 + 0x4992) = 1;
  }
  iVar11 = *(int *)(param_1 + 0x49a0);
  uVar7 = *(uint *)(param_1 + 0x49b0);
  iVar6 = *(int *)(param_1 + 0x4994) + (*(int *)(param_1 + 0x499c) - iVar11 >> 2);
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
    iVar3 = *(int *)(param_1 + 0x4998) - iVar6;
    uVar17 = (uint)uVar2;
    goto LAB_000da680;
  }
  uVar17 = uVar18 & 4;
  if (uVar17 != (uVar18 >> 0x10 & 4)) {
    *(uint *)(param_1 + 0x497c) = *(uint *)(param_1 + 0x497c) | uVar18 & 0x1f;
  }
  if ((uVar18 & 0x10) == 0) {
    if ((uVar18 & 8) == 0) {
      if (uVar17 == 0) {
        uVar17 = 0x10;
        uVar12 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x7c);
      }
      else {
        uVar17 = 0x14;
        uVar12 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x82);
      }
    }
    else {
      if (uVar17 != 0) {
        uVar17 = 0x24;
        *(uint *)(param_1 + 0x498c) = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x84);
        if ((*(uint *)(*(int *)(param_1 + 0x468c) + 0x94) & 8) == 0) {
          uVar17 = 0x20;
        }
        goto LAB_000da61c;
      }
      uVar17 = 0x18;
      uVar12 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x7e);
    }
LAB_000da658:
    *(short *)(param_1 + 0x4990) = (short)uVar17;
    *(uint *)(param_1 + 0x498c) = uVar12;
  }
  else {
    if (uVar17 == 0) {
      uVar17 = 0x20;
      uVar12 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x80);
      goto LAB_000da658;
    }
    uVar17 = 0x34;
    *(uint *)(param_1 + 0x498c) = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x86);
    if ((*(uint *)(*(int *)(param_1 + 0x468c) + 0x94) & 8) == 0) {
      uVar17 = 0x2c;
    }
LAB_000da61c:
    *(short *)(param_1 + 0x4990) = (short)uVar17;
  }
  iVar3 = 0;
  *(uint *)(param_1 + 0x4980) = uVar9 | uVar18 << 0x10;
LAB_000da680:
  local_40[0] = iVar16 + 8;
  if (iVar3 < local_40[0]) {
    iVar15 = *(int *)(param_1 + 0x49a8);
    bVar1 = iVar15 == 0;
    if (!bVar1) {
      (**(code **)(param_1 + 0x47c8))(*(undefined4 *)(param_1 + 0x4688),iVar15);
    }
    iVar6 = (**(code **)(param_1 + 0x47c4))
                      (*(undefined4 *)(param_1 + 0x4688),*(undefined4 *)(param_1 + 0x498c),local_40)
    ;
    if (iVar6 == 0) {
      *(uint *)(param_1 + 0x4980) = uVar9;
      *(undefined4 *)(param_1 + 0x4998) = 0;
      *(undefined4 *)(param_1 + 0x4994) = 0;
      *(undefined4 *)(param_1 + 0x49a4) = 0;
      if (bVar1) {
        return 0;
      }
      uVar14 = (**(code **)(param_1 + 0x47cc))(*(undefined4 *)(param_1 + 0x4688),iVar15);
      *(undefined4 *)(param_1 + 0x49a8) = 0;
      return uVar14;
    }
    *(undefined4 *)(param_1 + 0x4994) = 0;
    *(int *)(param_1 + 0x4998) = local_40[0];
    *(int *)(param_1 + 0x49a8) = iVar6;
    *(int *)(param_1 + 0x49a4) = iVar6;
    iVar11 = *(int *)(param_1 + 0x49a0);
    uVar7 = *(uint *)(param_1 + 0x49b0);
  }
  else {
    bVar1 = true;
    *(int *)(param_1 + 0x4994) = iVar6;
    iVar6 = *(int *)(param_1 + 0x49a8) + iVar6 * uVar17;
    *(int *)(param_1 + 0x49a4) = iVar6;
  }
  *(int *)(param_1 + 0x499c) = iVar11 + iVar16 * 4;
  uVar12 = 0;
  uVar9 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x334);
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
  piVar10 = *(int **)(param_1 + 0x49b4);
  uVar18 = (uVar18 & uVar12) << 0x15 |
           (uVar18 & (*(uint *)(param_1 + 0x497c) | ~uVar12) & 0x1f) << 0x10 | uVar7 | 0x30000000;
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
        *(int **)(param_1 + 0x49b4) = piVar4;
      }
      pcVar5 = (code *)(piVar4 + 8);
      goto LAB_000da850;
    }
    piVar4 = (int *)*piVar4;
  } while (piVar4 != piVar10);
  if ((*(uint *)PTR__gle_processor_0011204c & 0x10) == 0) {
    pcVar5 = (code *)_gleBuildCompileFuncTCLNO(param_1,uVar18);
  }
  else {
    pcVar5 = (code *)_gleBuildCompileFuncTCLAV(param_1,uVar18);
  }
LAB_000da850:
  uVar14 = (*pcVar5)(param_1,iVar6,uVar14,uVar17,(uint)uVar2);
  *(uint *)(param_1 + 0x497c) = ~*(uint *)(param_1 + 0x4980) & 0x1f;
  if (!bVar1) {
    uVar14 = (**(code **)(param_1 + 0x47cc))(*(undefined4 *)(param_1 + 0x4688),iVar15);
  }
  return uVar14;
}

/* _gleCompileClippedVertexArray @ 0xda8b4 (1136 bytes) */
int _gleCompileClippedVertexArray(param_1)
  int param_1;
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
  iVar14 = param_1;
  if (*(int *)(param_1 + 0x49ac) != 0) {
    iVar14 = *(int *)(param_1 + 0x4988);
    uVar13 = *(undefined4 *)(param_1 + 0x49a4);
    uVar2 = *(ushort *)(param_1 + 0x4990);
    uVar17 = *(uint *)(param_1 + 0x4980);
    if (*(short *)(param_1 + 0x4992) == 0) {
      iVar10 = *(int *)(param_1 + 0x49a0);
    }
    else {
      uVar17 = uVar17 & 0xffff;
      *(undefined2 *)(param_1 + 0x4992) = 0;
      iVar10 = *(int *)(param_1 + 0x49a0);
      *(int *)(param_1 + 0x499c) = iVar10 + *(int *)(*(int *)(param_1 + 0x468c) + 0x88) * 4;
    }
    piVar6 = *(int **)(param_1 + 0x499c) + 0x11;
    iVar8 = (int)piVar6 - iVar10;
    for (iVar18 = *(int *)(param_1 + 0x4984) + (iVar8 >> 2);
        (*(int **)(param_1 + 0x499c) <= piVar6 && (iVar8 = (int)piVar6 - iVar10, *piVar6 == iVar18))
        ; iVar18 = iVar18 + -1) {
      piVar6 = piVar6 + -1;
      iVar8 = (int)piVar6 - iVar10;
    }
    uVar19 = uVar17 & 0xffff;
    iVar10 = *(int *)(param_1 + 0x4994) + (iVar8 >> 2) + 1;
    if (uVar19 == uVar17 >> 0x10) {
      iVar8 = *(int *)(param_1 + 0x4998) - iVar10;
      uVar15 = (uint)uVar2;
    }
    else {
      *(uint *)(param_1 + 0x4980) = uVar19 | uVar17 << 0x10;
      if ((uVar17 & 0x10) == 0) {
        if ((uVar17 & 8) == 0) {
          if ((uVar17 & 4) == 0) {
            uVar15 = 0x14;
            uVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x7c);
          }
          else {
            uVar15 = 0x18;
            uVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x82);
          }
        }
        else if ((uVar17 & 4) == 0) {
          uVar15 = 0x1c;
          uVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x7e);
        }
        else {
          uVar15 = 0x20;
          uVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x84);
        }
      }
      else if ((uVar17 & 4) == 0) {
        uVar15 = 0x28;
        uVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x80);
      }
      else {
        uVar15 = 0x2c;
        uVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0x86);
      }
      piVar11 = *(int **)(param_1 + 0x49b8);
      *(short *)(param_1 + 0x4990) = (short)uVar15;
      *(uint *)(param_1 + 0x498c) = uVar3;
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
            *(int **)(param_1 + 0x49b8) = piVar4;
          }
          *(int **)(param_1 + 0x49c4) = piVar4 + 8;
          goto LAB_000daa98;
        }
        piVar4 = (int *)*piVar4;
      } while (piVar4 != piVar11);
      uVar5 = _gleBuildInterpFunc(param_1,uVar19);
      *(undefined4 *)(param_1 + 0x49c4) = uVar5;
LAB_000daa98:
      iVar8 = 0;
    }
    local_40[0] = iVar14 * 2 + 0x12;
    if (local_40[0] < iVar8) {
      bVar1 = true;
      *(int *)(param_1 + 0x4994) = iVar10;
      iVar10 = *(int *)(param_1 + 0x49a8) + iVar10 * uVar15;
    }
    else {
      iVar16 = *(int *)(param_1 + 0x49a8);
      bVar1 = iVar16 == 0;
      if (!bVar1) {
        (**(code **)(param_1 + 0x47c8))(*(undefined4 *)(param_1 + 0x4688),iVar16,iVar10);
      }
      iVar10 = (**(code **)(param_1 + 0x47c4))
                         (*(undefined4 *)(param_1 + 0x4688),*(undefined4 *)(param_1 + 0x498c),
                          local_40);
      if (iVar10 == 0) {
        *(uint *)(param_1 + 0x4980) = uVar19;
        *(undefined4 *)(param_1 + 0x4998) = 0;
        *(undefined4 *)(param_1 + 0x4994) = 0;
        *(undefined4 *)(param_1 + 0x49a4) = 0;
        if (bVar1) {
          return 0;
        }
        uVar13 = (**(code **)(param_1 + 0x47cc))(*(undefined4 *)(param_1 + 0x4688),iVar16);
        *(undefined4 *)(param_1 + 0x49a8) = 0;
        return uVar13;
      }
      *(undefined4 *)(param_1 + 0x4994) = 0;
      *(int *)(param_1 + 0x4998) = local_40[0];
      *(int *)(param_1 + 0x49a8) = iVar10;
    }
    *(int *)(param_1 + 0x49a4) = iVar10;
    piVar4 = (int *)(*(int *)(param_1 + 0x49a0) + iVar14 * 4);
    if (piVar4 <= piVar6) {
      uVar19 = (uint)((int)piVar6 + (4 - (int)piVar4)) >> 2;
      do {
        *piVar6 = iVar18;
        piVar6 = piVar6 + -1;
        iVar18 = iVar18 + -1;
        uVar19 = uVar19 - 1;
      } while (uVar19 != 0);
    }
    *(int **)(param_1 + 0x499c) = piVar4;
    uVar3 = *(uint *)(*(int *)(param_1 + 0x4a60) + 0x334);
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
             (uVar17 & (*(uint *)(param_1 + 0x497c) | ~uVar19) & 0x1f) << 0x10 |
             *(uint *)(param_1 + 0x49b0) | (uint)*(ushort *)(param_1 + 0x4fe8) << 0x18;
    if (*(undefined **)(param_1 + 0x5080) == ((unsigned char *)0x00001101)) {
      uVar17 = uVar17 | 0x10000000;
    }
    piVar4 = *(int **)(param_1 + 0x49b4);
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
          *(int **)(param_1 + 0x49b4) = piVar6;
        }
        pcVar7 = (code *)(piVar6 + 8);
        goto LAB_000dacc0;
      }
      piVar6 = (int *)*piVar6;
    } while (piVar6 != piVar4);
    if ((*(uint *)PTR__gle_processor_0011204c & 0x10) == 0) {
      pcVar7 = (code *)_gleBuildCompileFuncNO(param_1,uVar17);
    }
    else {
      pcVar7 = (code *)_gleBuildCompileFuncAV(param_1,uVar17);
    }
LAB_000dacc0:
    iVar14 = (*pcVar7)(param_1,iVar10,uVar13,uVar15,(uint)uVar2);
    *(uint *)(param_1 + 0x497c) = ~*(uint *)(param_1 + 0x4980) & 0x1f;
    if (!bVar1) {
      iVar14 = (**(code **)(param_1 + 0x47cc))(*(undefined4 *)(param_1 + 0x4688),iVar16);
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
void _gleExecuteTCLVertexArray(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
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
                    
                    
    (**(code **)(param_1 + 0x46e4))
              (*(undefined4 *)(param_1 + 0x4688),*(undefined4 *)(param_1 + 0x49a8),param_2,
               *(int *)(param_1 + 0x4984) - *(int *)(param_1 + 0x4994),param_4,param_5,
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
        (**(code **)(param_1 + 0x46e4))
                  (*(undefined4 *)(param_1 + 0x4688),*(undefined4 *)(param_1 + 0x49a8),param_2,
                   *(int *)(param_1 + 0x4984) - *(int *)(param_1 + 0x4994),param_4,0x1405,piVar4);
        _free(piVar4);
        return;
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar2 = 0x505;
      goto LAB_000dae80;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar2 = 0x500;
LAB_000dae80:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
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
  undefined4 extraout_r3;
  dword *pdVar5;
  dword *extraout_r3_00;
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
    return (dword *)extraout_r3;
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
    pdVar5 = extraout_r3_00;
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
void _gleLightMaterialRGBAChange_F_A(param_1, param_2)
  int param_1;
  undefined8 *param_2;
{
  byte bVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  puVar2 = (undefined8 *)_glePushMaterial(param_1,0);
  *puVar2 = *param_2;
  uVar5 = param_2[1];
  *(ushort *)((int)puVar2 + 0x234) = *(ushort *)((int)puVar2 + 0x234) | 0x404;
  puVar2[1] = uVar5;
  if (*(int *)(param_1 + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x2c0);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2f4);
  }
  iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
  iVar3 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar3 + 0x2c0);
  iVar3 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar3 + 0x348) = *(uint *)(iVar3 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_F_D @ 0xdc158 (184 bytes) */
void _gleLightMaterialRGBAChange_F_D(param_1, param_2)
  int param_1;
  undefined8 *param_2;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar2 = _glePushMaterial(param_1,0);
  *(undefined8 *)(iVar2 + 0x10) = *param_2;
  uVar4 = param_2[1];
  *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x808;
  *(undefined8 *)(iVar2 + 0x18) = uVar4;
  if (*(int *)(param_1 + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x2c1);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2f5);
  }
  iVar3 = (bVar1 >> 3 & 0x1c) + param_1;
  iVar2 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar3 + 0x324) = *(uint *)(iVar3 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar2 + 0x2c1);
  iVar2 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialShineChange_B @ 0xdc210 (180 bytes) */
void _gleLightMaterialShineChange_B(int param_1,double fparam_1)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _glePushMaterial(param_1,1);
  *(float *)(iVar2 + 0x40) = (float)fparam_1;
  *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x101;
  if (*(int *)(param_1 + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x2ca);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2fe);
  }
  iVar3 = (bVar1 >> 3 & 0x1c) + param_1;
  iVar2 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar3 + 0x324) = *(uint *)(iVar3 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar2 + 0x2ca);
  iVar2 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_B_E @ 0xdc2c4 (184 bytes) */
void _gleLightMaterialRGBAChange_B_E(param_1, param_2)
  int param_1;
  undefined8 *param_2;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar2 = _glePushMaterial(param_1,1);
  *(undefined8 *)(iVar2 + 0x30) = *param_2;
  uVar4 = param_2[1];
  *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x202;
  *(undefined8 *)(iVar2 + 0x38) = uVar4;
  if (*(int *)(param_1 + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x2c9);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2fd);
  }
  iVar3 = (bVar1 >> 3 & 0x1c) + param_1;
  iVar2 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar3 + 0x324) = *(uint *)(iVar3 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar2 + 0x2c9);
  iVar2 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_B_A @ 0xdc37c (184 bytes) */
void _gleLightMaterialRGBAChange_B_A(param_1, param_2)
  int param_1;
  undefined8 *param_2;
{
  byte bVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  puVar2 = (undefined8 *)_glePushMaterial(param_1,1);
  *puVar2 = *param_2;
  uVar5 = param_2[1];
  *(ushort *)((int)puVar2 + 0x234) = *(ushort *)((int)puVar2 + 0x234) | 0x404;
  puVar2[1] = uVar5;
  if (*(int *)(param_1 + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x2c6);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2fa);
  }
  iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
  iVar3 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar3 + 0x2c6);
  iVar3 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar3 + 0x348) = *(uint *)(iVar3 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_B_D @ 0xdc434 (184 bytes) */
void _gleLightMaterialRGBAChange_B_D(param_1, param_2)
  int param_1;
  undefined8 *param_2;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar2 = _glePushMaterial(param_1,1);
  *(undefined8 *)(iVar2 + 0x10) = *param_2;
  uVar4 = param_2[1];
  *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x808;
  *(undefined8 *)(iVar2 + 0x18) = uVar4;
  if (*(int *)(param_1 + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x2c7);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2fb);
  }
  iVar3 = (bVar1 >> 3 & 0x1c) + param_1;
  iVar2 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar3 + 0x324) = *(uint *)(iVar3 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar2 + 0x2c7);
  iVar2 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_B_S @ 0xdc4ec (184 bytes) */
void _gleLightMaterialRGBAChange_B_S(param_1, param_2)
  int param_1;
  undefined8 *param_2;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar2 = _glePushMaterial(param_1,1);
  *(undefined8 *)(iVar2 + 0x20) = *param_2;
  uVar4 = param_2[1];
  *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x1010;
  *(undefined8 *)(iVar2 + 0x28) = uVar4;
  if (*(int *)(param_1 + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x2c8);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2fc);
  }
  iVar3 = (bVar1 >> 3 & 0x1c) + param_1;
  iVar2 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar3 + 0x324) = *(uint *)(iVar3 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar2 + 0x2c8);
  iVar2 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_B_AD @ 0xdc5a4 (296 bytes) */
void _gleLightMaterialRGBAChange_B_AD(param_1, param_2)
  int param_1;
  undefined8 *param_2;
{
  byte bVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  
  puVar2 = (undefined8 *)_glePushMaterial(param_1,1);
  *puVar2 = *param_2;
  puVar2[1] = param_2[1];
  puVar2[2] = *param_2;
  uVar6 = param_2[1];
  *(ushort *)((int)puVar2 + 0x234) = *(ushort *)((int)puVar2 + 0x234) | 0xc0c;
  puVar2[3] = uVar6;
  iVar4 = *(int *)(param_1 + 0x5434);
  if (iVar4 == 0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x2c6);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2fa);
  }
  iVar5 = (bVar1 >> 3 & 0x1c) + param_1;
  iVar3 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar3 + 0x2c6);
  iVar5 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar5 + 0x348) = *(uint *)(iVar5 + 0x348) | 1 << (bVar1 & 0x1f);
  if (iVar4 == 0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x2c7);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2fb);
  }
  iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar3 + 0x2c7);
  iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar4 + 0x348) = *(uint *)(iVar4 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_FB_E @ 0xdc6cc (224 bytes) */
void _gleLightMaterialRGBAChange_FB_E(param_1, param_2)
  int param_1;
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
    iVar2 = _glePushMaterial(param_1,iVar5);
    *(undefined8 *)(iVar2 + 0x30) = *param_2;
    uVar6 = param_2[1];
    *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x202;
    *(undefined8 *)(iVar2 + 0x38) = uVar6;
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar1 = *(byte *)(iVar5 * 6 + *(int *)(param_1 + 0x5420) + 0x2c3);
    }
    else {
      bVar1 = *(byte *)(iVar5 * 6 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2f7);
    }
    iVar3 = iVar5 * 6;
    iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
    iVar5 = iVar5 + 1;
    iVar2 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
    bVar1 = *(byte *)(iVar3 + iVar2 + 0x2c3);
    iVar2 = (bVar1 >> 3 & 0x1c) + param_1;
    *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  } while (iVar5 < 2);
  return;
}

/* FUN_000dc7b8 @ 0xdc7b8 (1320 bytes) */
void FUN_000dc7b8(param_1)
  int param_1;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  float *pfVar13;
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
  
  fVar4 = FLOAT_00108e54;
  fVar3 = FLOAT_00108e50;
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
  pfVar13 = (float *)(param_1 + 0x21c0);
  local_14 = *(float *)(param_1 + 0x1bfc);
  *(float *)(param_1 + 0x21c0) = FLOAT_00108e54;
  *(float *)(param_1 + 0x21c4) = fVar3;
  *(float *)(param_1 + 0x21c8) = fVar3;
  *(float *)(param_1 + 0x21cc) = fVar3;
  *(float *)(param_1 + 0x21d0) = fVar3;
  *(float *)(param_1 + 0x21d4) = fVar4;
  *(float *)(param_1 + 0x21d8) = fVar3;
  *(float *)(param_1 + 0x21dc) = fVar3;
  *(float *)(param_1 + 0x21e0) = fVar3;
  *(float *)(param_1 + 0x21e4) = fVar3;
  *(float *)(param_1 + 0x21e8) = fVar4;
  *(float *)(param_1 + 0x21ec) = fVar3;
  *(float *)(param_1 + 0x21f0) = fVar3;
  *(float *)(param_1 + 0x21f4) = fVar3;
  *(float *)(param_1 + 0x21f8) = fVar3;
  *(float *)(param_1 + 0x21fc) = fVar4;
  iVar9 = 0;
  while( true ) {
    iVar8 = iVar9 + 1;
    fVar2 = local_50[iVar9 * 5];
    iVar7 = iVar9 + 4;
    iVar14 = iVar9 + 8;
    iVar15 = iVar9 + 0xc;
    iVar10 = iVar9;
    if (iVar8 != 4) {
      pfVar6 = local_50 + iVar9 * 4 + iVar8;
      iVar5 = 4 - iVar8;
      iVar12 = iVar8;
      do {
        fVar1 = *pfVar6;
        pfVar6 = pfVar6 + 1;
        if (ABS(fVar2) < ABS(fVar1)) {
          iVar10 = iVar12;
          fVar2 = fVar1;
        }
        iVar12 = iVar12 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    if (iVar10 != iVar9) {
      fVar1 = pfVar13[iVar9];
      iVar12 = iVar10 + 4;
      pfVar13[iVar9] = pfVar13[iVar10];
      iVar5 = iVar10 + 8;
      pfVar13[iVar10] = fVar1;
      iVar11 = iVar10 + 0xc;
      fVar1 = local_50[iVar9];
      local_50[iVar9] = local_50[iVar10];
      local_50[iVar10] = fVar1;
      fVar1 = pfVar13[iVar7];
      pfVar13[iVar7] = pfVar13[iVar12];
      pfVar13[iVar12] = fVar1;
      fVar1 = local_50[iVar7];
      local_50[iVar7] = local_50[iVar12];
      local_50[iVar12] = fVar1;
      fVar1 = pfVar13[iVar14];
      pfVar13[iVar14] = pfVar13[iVar5];
      pfVar13[iVar5] = fVar1;
      fVar1 = local_50[iVar14];
      local_50[iVar14] = local_50[iVar5];
      local_50[iVar5] = fVar1;
      fVar1 = pfVar13[iVar15];
      pfVar13[iVar15] = pfVar13[iVar11];
      pfVar13[iVar11] = fVar1;
      fVar1 = local_50[iVar15];
      local_50[iVar15] = local_50[iVar11];
      local_50[iVar11] = fVar1;
    }
    if (fVar2 == fVar3) break;
    fVar2 = fVar4 / fVar2;
    local_50[iVar9] = local_50[iVar9] * fVar2;
    pfVar13[iVar9] = pfVar13[iVar9] * fVar2;
    local_50[iVar7] = local_50[iVar7] * fVar2;
    pfVar13[iVar7] = pfVar13[iVar7] * fVar2;
    local_50[iVar14] = local_50[iVar14] * fVar2;
    pfVar13[iVar14] = pfVar13[iVar14] * fVar2;
    local_50[iVar15] = local_50[iVar15] * fVar2;
    pfVar13[iVar15] = pfVar13[iVar15] * fVar2;
    if (iVar9 != 0) {
      fVar2 = local_50[iVar9 * 4];
      local_50[0] = -(local_50[iVar9] * fVar2 - local_50[0]);
      *pfVar13 = -(pfVar13[iVar9] * fVar2 - *pfVar13);
      local_40 = -(local_50[iVar7] * fVar2 - local_40);
      *(float *)(param_1 + 0x21d0) = -(pfVar13[iVar7] * fVar2 - *(float *)(param_1 + 0x21d0));
      local_30 = -(local_50[iVar14] * fVar2 - local_30);
      *(float *)(param_1 + 0x21e0) = -(pfVar13[iVar14] * fVar2 - *(float *)(param_1 + 0x21e0));
      local_20 = -(local_50[iVar15] * fVar2 - local_20);
      *(float *)(param_1 + 0x21f0) = -(pfVar13[iVar15] * fVar2 - *(float *)(param_1 + 0x21f0));
    }
    if (iVar9 != 1) {
      fVar2 = local_50[iVar9 * 4 + 1];
      local_50[1] = -(local_50[iVar9] * fVar2 - local_50[1]);
      *(float *)(param_1 + 0x21c4) = -(pfVar13[iVar9] * fVar2 - *(float *)(param_1 + 0x21c4));
      local_3c = -(local_50[iVar7] * fVar2 - local_3c);
      *(float *)(param_1 + 0x21d4) = -(pfVar13[iVar7] * fVar2 - *(float *)(param_1 + 0x21d4));
      local_2c = -(local_50[iVar14] * fVar2 - local_2c);
      *(float *)(param_1 + 0x21e4) = -(pfVar13[iVar14] * fVar2 - *(float *)(param_1 + 0x21e4));
      local_1c = -(local_50[iVar15] * fVar2 - local_1c);
      *(float *)(param_1 + 0x21f4) = -(pfVar13[iVar15] * fVar2 - *(float *)(param_1 + 0x21f4));
    }
    if (iVar9 != 2) {
      fVar2 = local_50[iVar9 * 4 + 2];
      local_50[2] = -(local_50[iVar9] * fVar2 - local_50[2]);
      *(float *)(param_1 + 0x21c8) = -(pfVar13[iVar9] * fVar2 - *(float *)(param_1 + 0x21c8));
      local_38 = -(local_50[iVar7] * fVar2 - local_38);
      *(float *)(param_1 + 0x21d8) = -(pfVar13[iVar7] * fVar2 - *(float *)(param_1 + 0x21d8));
      local_28 = -(local_50[iVar14] * fVar2 - local_28);
      *(float *)(param_1 + 0x21e8) = -(pfVar13[iVar14] * fVar2 - *(float *)(param_1 + 0x21e8));
      local_18 = -(local_50[iVar15] * fVar2 - local_18);
      *(float *)(param_1 + 0x21f8) = -(pfVar13[iVar15] * fVar2 - *(float *)(param_1 + 0x21f8));
    }
    if (iVar9 != 3) {
      fVar2 = local_50[iVar9 * 4 + 3];
      local_50[3] = -(local_50[iVar9] * fVar2 - local_50[3]);
      *(float *)(param_1 + 0x21cc) = -(pfVar13[iVar9] * fVar2 - *(float *)(param_1 + 0x21cc));
      local_34 = -(local_50[iVar7] * fVar2 - local_34);
      *(float *)(param_1 + 0x21dc) = -(pfVar13[iVar7] * fVar2 - *(float *)(param_1 + 0x21dc));
      local_24 = -(local_50[iVar14] * fVar2 - local_24);
      *(float *)(param_1 + 0x21ec) = -(pfVar13[iVar14] * fVar2 - *(float *)(param_1 + 0x21ec));
      local_14 = -(local_50[iVar15] * fVar2 - local_14);
      *(float *)(param_1 + 0x21fc) = -(pfVar13[iVar15] * fVar2 - *(float *)(param_1 + 0x21fc));
    }
    iVar9 = iVar8;
    if (iVar8 == 4) {
      return;
    }
  }
  *(float *)(param_1 + 0x21fc) = fVar4;
  *(float *)(param_1 + 0x21f8) = fVar3;
  *pfVar13 = fVar4;
  *(float *)(param_1 + 0x21c4) = fVar3;
  *(float *)(param_1 + 0x21c8) = fVar3;
  *(float *)(param_1 + 0x21cc) = fVar3;
  *(float *)(param_1 + 0x21d0) = fVar3;
  *(float *)(param_1 + 0x21d4) = fVar4;
  *(float *)(param_1 + 0x21d8) = fVar3;
  *(float *)(param_1 + 0x21dc) = fVar3;
  *(float *)(param_1 + 0x21e0) = fVar3;
  *(float *)(param_1 + 0x21e4) = fVar3;
  *(float *)(param_1 + 0x21e8) = fVar4;
  *(float *)(param_1 + 0x21ec) = fVar3;
  *(float *)(param_1 + 0x21f0) = fVar3;
  *(float *)(param_1 + 0x21f4) = fVar3;
  return;
}

/* _gleLoadTransposeMatrixf @ 0xdcce0 (132 bytes) */
int _gleLoadTransposeMatrixf(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  *param_2 = *param_1;
  param_2[1] = param_1[4];
  param_2[2] = param_1[8];
  param_2[3] = param_1[0xc];
  param_2[4] = param_1[1];
  param_2[5] = param_1[5];
  param_2[6] = param_1[9];
  param_2[7] = param_1[0xd];
  param_2[8] = param_1[2];
  param_2[9] = param_1[6];
  param_2[10] = param_1[10];
  param_2[0xb] = param_1[0xe];
  param_2[0xc] = param_1[3];
  param_2[0xd] = param_1[7];
  param_2[0xe] = param_1[0xb];
  param_2[0xf] = param_1[0xf];
  return;
}

/* _gleLoadTransposeMatrixd @ 0xdcd64 (196 bytes) */
int _gleLoadTransposeMatrixd(param_1, param_2)
  double *param_1;
  float *param_2;
{
  *param_2 = (float)*param_1;
  param_2[1] = (float)param_1[4];
  param_2[2] = (float)param_1[8];
  param_2[3] = (float)param_1[0xc];
  param_2[4] = (float)param_1[1];
  param_2[5] = (float)param_1[5];
  param_2[6] = (float)param_1[9];
  param_2[7] = (float)param_1[0xd];
  param_2[8] = (float)param_1[2];
  param_2[9] = (float)param_1[6];
  param_2[10] = (float)param_1[10];
  param_2[0xb] = (float)param_1[0xe];
  param_2[0xc] = (float)param_1[3];
  param_2[0xd] = (float)param_1[7];
  param_2[0xe] = (float)param_1[0xb];
  param_2[0xf] = (float)param_1[0xf];
  return;
}

/* _gleGetMatrixf @ 0xdce28 (132 bytes) */
void _gleGetMatrixf(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  param_2[4] = param_1[4];
  param_2[5] = param_1[5];
  param_2[6] = param_1[6];
  param_2[7] = param_1[7];
  param_2[8] = param_1[8];
  param_2[9] = param_1[9];
  param_2[10] = param_1[10];
  param_2[0xb] = param_1[0xb];
  param_2[0xc] = param_1[0xc];
  param_2[0xd] = param_1[0xd];
  param_2[0xe] = param_1[0xe];
  param_2[0xf] = param_1[0xf];
  return;
}

/* _gleGetTransposeMatrixf @ 0xdceac (132 bytes) */
void _gleGetTransposeMatrixf(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  *param_2 = *param_1;
  param_2[1] = param_1[4];
  param_2[2] = param_1[8];
  param_2[3] = param_1[0xc];
  param_2[4] = param_1[1];
  param_2[5] = param_1[5];
  param_2[6] = param_1[9];
  param_2[7] = param_1[0xd];
  param_2[8] = param_1[2];
  param_2[9] = param_1[6];
  param_2[10] = param_1[10];
  param_2[0xb] = param_1[0xe];
  param_2[0xc] = param_1[3];
  param_2[0xd] = param_1[7];
  param_2[0xe] = param_1[0xb];
  param_2[0xf] = param_1[0xf];
  return;
}

/* _gleGetTransposeMatrixd @ 0xdcf30 (132 bytes) */
void _gleGetTransposeMatrixd(param_1, param_2)
  float *param_1;
  double *param_2;
{
  *param_2 = (double)*param_1;
  param_2[1] = (double)param_1[4];
  param_2[2] = (double)param_1[8];
  param_2[3] = (double)param_1[0xc];
  param_2[4] = (double)param_1[1];
  param_2[5] = (double)param_1[5];
  param_2[6] = (double)param_1[9];
  param_2[7] = (double)param_1[0xd];
  param_2[8] = (double)param_1[2];
  param_2[9] = (double)param_1[6];
  param_2[10] = (double)param_1[10];
  param_2[0xb] = (double)param_1[0xe];
  param_2[0xc] = (double)param_1[3];
  param_2[0xd] = (double)param_1[7];
  param_2[0xe] = (double)param_1[0xb];
  param_2[0xf] = (double)param_1[0xf];
  return;
}

/* _gleMultTransposeMatrixf @ 0xdcfb4 (836 bytes) */
void _gleMultTransposeMatrixf(param_1, param_2, param_3)
  float *param_1;
  float *param_2;
  float *param_3;
{
  *param_3 = param_1[0xc] * param_2[0xc] +
             (param_1[8] * param_2[8] + (*param_1 * *param_2 + param_1[4] * param_2[4]));
  param_3[4] = param_1[0xc] * param_2[0xd] +
               (param_1[8] * param_2[9] + (*param_1 * param_2[1] + param_1[4] * param_2[5]));
  param_3[8] = param_1[0xc] * param_2[0xe] +
               (param_1[8] * param_2[10] + (*param_1 * param_2[2] + param_1[4] * param_2[6]));
  param_3[0xc] = param_1[0xc] * param_2[0xf] +
                 (param_1[8] * param_2[0xb] + (*param_1 * param_2[3] + param_1[4] * param_2[7]));
  param_3[1] = param_1[0xd] * param_2[0xc] +
               (param_1[9] * param_2[8] + (param_1[1] * *param_2 + param_1[5] * param_2[4]));
  param_3[5] = param_1[0xd] * param_2[0xd] +
               (param_1[9] * param_2[9] + (param_1[1] * param_2[1] + param_1[5] * param_2[5]));
  param_3[9] = param_1[0xd] * param_2[0xe] +
               (param_1[9] * param_2[10] + (param_1[1] * param_2[2] + param_1[5] * param_2[6]));
  param_3[0xd] = param_1[0xd] * param_2[0xf] +
                 (param_1[9] * param_2[0xb] + (param_1[1] * param_2[3] + param_1[5] * param_2[7]));
  param_3[2] = param_1[0xe] * param_2[0xc] +
               (param_1[10] * param_2[8] + (param_1[2] * *param_2 + param_1[6] * param_2[4]));
  param_3[6] = param_1[0xe] * param_2[0xd] +
               (param_1[10] * param_2[9] + (param_1[2] * param_2[1] + param_1[6] * param_2[5]));
  param_3[10] = param_1[0xe] * param_2[0xe] +
                (param_1[10] * param_2[10] + (param_1[2] * param_2[2] + param_1[6] * param_2[6]));
  param_3[0xe] = param_1[0xe] * param_2[0xf] +
                 (param_1[10] * param_2[0xb] + (param_1[2] * param_2[3] + param_1[6] * param_2[7]));
  param_3[3] = param_1[0xf] * param_2[0xc] +
               (param_1[0xb] * param_2[8] + (param_1[3] * *param_2 + param_1[7] * param_2[4]));
  param_3[7] = param_1[0xf] * param_2[0xd] +
               (param_1[0xb] * param_2[9] + (param_1[3] * param_2[1] + param_1[7] * param_2[5]));
  param_3[0xb] = param_1[0xf] * param_2[0xe] +
                 (param_1[0xb] * param_2[10] + (param_1[3] * param_2[2] + param_1[7] * param_2[6]));
  param_3[0xf] = param_1[0xf] * param_2[0xf] +
                 (param_1[0xb] * param_2[0xb] + (param_1[3] * param_2[3] + param_1[7] * param_2[7]));
  return;
}

/* _gleMultTransposeMatrixd @ 0xdd2f8 (900 bytes) */
void _gleMultTransposeMatrixd(param_1, param_2, param_3)
  float *param_1;
  double *param_2;
  float *param_3;
{
  *param_3 = (float)((double)param_1[0xc] * param_2[0xc] +
                    ((double)param_1[8] * param_2[8] +
                    ((double)*param_1 * *param_2 + (double)param_1[4] * param_2[4])));
  param_3[4] = (float)((double)param_1[0xc] * param_2[0xd] +
                      ((double)param_1[8] * param_2[9] +
                      ((double)*param_1 * param_2[1] + (double)param_1[4] * param_2[5])));
  param_3[8] = (float)((double)param_1[0xc] * param_2[0xe] +
                      ((double)param_1[8] * param_2[10] +
                      ((double)*param_1 * param_2[2] + (double)param_1[4] * param_2[6])));
  param_3[0xc] = (float)((double)param_1[0xc] * param_2[0xf] +
                        ((double)param_1[8] * param_2[0xb] +
                        ((double)*param_1 * param_2[3] + (double)param_1[4] * param_2[7])));
  param_3[1] = (float)((double)param_1[0xd] * param_2[0xc] +
                      ((double)param_1[9] * param_2[8] +
                      ((double)param_1[1] * *param_2 + (double)param_1[5] * param_2[4])));
  param_3[5] = (float)((double)param_1[0xd] * param_2[0xd] +
                      ((double)param_1[9] * param_2[9] +
                      ((double)param_1[1] * param_2[1] + (double)param_1[5] * param_2[5])));
  param_3[9] = (float)((double)param_1[0xd] * param_2[0xe] +
                      ((double)param_1[9] * param_2[10] +
                      ((double)param_1[1] * param_2[2] + (double)param_1[5] * param_2[6])));
  param_3[0xd] = (float)((double)param_1[0xd] * param_2[0xf] +
                        ((double)param_1[9] * param_2[0xb] +
                        ((double)param_1[1] * param_2[3] + (double)param_1[5] * param_2[7])));
  param_3[2] = (float)((double)param_1[0xe] * param_2[0xc] +
                      ((double)param_1[10] * param_2[8] +
                      ((double)param_1[2] * *param_2 + (double)param_1[6] * param_2[4])));
  param_3[6] = (float)((double)param_1[0xe] * param_2[0xd] +
                      ((double)param_1[10] * param_2[9] +
                      ((double)param_1[2] * param_2[1] + (double)param_1[6] * param_2[5])));
  param_3[10] = (float)((double)param_1[0xe] * param_2[0xe] +
                       ((double)param_1[10] * param_2[10] +
                       ((double)param_1[2] * param_2[2] + (double)param_1[6] * param_2[6])));
  param_3[0xe] = (float)((double)param_1[0xe] * param_2[0xf] +
                        ((double)param_1[10] * param_2[0xb] +
                        ((double)param_1[2] * param_2[3] + (double)param_1[6] * param_2[7])));
  param_3[3] = (float)((double)param_1[0xf] * param_2[0xc] +
                      ((double)param_1[0xb] * param_2[8] +
                      ((double)param_1[3] * *param_2 + (double)param_1[7] * param_2[4])));
  param_3[7] = (float)((double)param_1[0xf] * param_2[0xd] +
                      ((double)param_1[0xb] * param_2[9] +
                      ((double)param_1[3] * param_2[1] + (double)param_1[7] * param_2[5])));
  param_3[0xb] = (float)((double)param_1[0xf] * param_2[0xe] +
                        ((double)param_1[0xb] * param_2[10] +
                        ((double)param_1[3] * param_2[2] + (double)param_1[7] * param_2[6])));
  param_3[0xf] = (float)((double)param_1[0xf] * param_2[0xf] +
                        ((double)param_1[0xb] * param_2[0xb] +
                        ((double)param_1[3] * param_2[3] + (double)param_1[7] * param_2[7])));
  return;
}

/* _gleMultTransposeMatrix @ 0xdd67c (836 bytes) */
void _gleMultTransposeMatrix(param_1, param_2, param_3)
  float *param_1;
  float *param_2;
  float *param_3;
{
  *param_3 = param_1[0xc] * param_2[0xc] +
             (param_1[8] * param_2[8] + (*param_1 * *param_2 + param_1[4] * param_2[4]));
  param_3[4] = param_1[0xc] * param_2[0xd] +
               (param_1[8] * param_2[9] + (*param_1 * param_2[1] + param_1[4] * param_2[5]));
  param_3[8] = param_1[0xc] * param_2[0xe] +
               (param_1[8] * param_2[10] + (*param_1 * param_2[2] + param_1[4] * param_2[6]));
  param_3[0xc] = param_1[0xc] * param_2[0xf] +
                 (param_1[8] * param_2[0xb] + (*param_1 * param_2[3] + param_1[4] * param_2[7]));
  param_3[1] = param_1[0xd] * param_2[0xc] +
               (param_1[9] * param_2[8] + (param_1[1] * *param_2 + param_1[5] * param_2[4]));
  param_3[5] = param_1[0xd] * param_2[0xd] +
               (param_1[9] * param_2[9] + (param_1[1] * param_2[1] + param_1[5] * param_2[5]));
  param_3[9] = param_1[0xd] * param_2[0xe] +
               (param_1[9] * param_2[10] + (param_1[1] * param_2[2] + param_1[5] * param_2[6]));
  param_3[0xd] = param_1[0xd] * param_2[0xf] +
                 (param_1[9] * param_2[0xb] + (param_1[1] * param_2[3] + param_1[5] * param_2[7]));
  param_3[2] = param_1[0xe] * param_2[0xc] +
               (param_1[10] * param_2[8] + (param_1[2] * *param_2 + param_1[6] * param_2[4]));
  param_3[6] = param_1[0xe] * param_2[0xd] +
               (param_1[10] * param_2[9] + (param_1[2] * param_2[1] + param_1[6] * param_2[5]));
  param_3[10] = param_1[0xe] * param_2[0xe] +
                (param_1[10] * param_2[10] + (param_1[2] * param_2[2] + param_1[6] * param_2[6]));
  param_3[0xe] = param_1[0xe] * param_2[0xf] +
                 (param_1[10] * param_2[0xb] + (param_1[2] * param_2[3] + param_1[6] * param_2[7]));
  param_3[3] = param_1[0xf] * param_2[0xc] +
               (param_1[0xb] * param_2[8] + (param_1[3] * *param_2 + param_1[7] * param_2[4]));
  param_3[7] = param_1[0xf] * param_2[0xd] +
               (param_1[0xb] * param_2[9] + (param_1[3] * param_2[1] + param_1[7] * param_2[5]));
  param_3[0xb] = param_1[0xf] * param_2[0xe] +
                 (param_1[0xb] * param_2[10] + (param_1[3] * param_2[2] + param_1[7] * param_2[6]));
  param_3[0xf] = param_1[0xf] * param_2[0xf] +
                 (param_1[0xb] * param_2[0xb] + (param_1[3] * param_2[3] + param_1[7] * param_2[7]));
  return;
}

/* _glePreEvaluate @ 0xdd9cc (164 bytes) */
void _glePreEvaluate(undefined4 param_1,int param_2,undefined4 param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float dVar6;
  float dVar7;
  
  if (param_2 == 1) {
    *param_4 = 1.0;
    return;
  }
  dVar6 = (double)FLOAT_00108e54;
  param_4[1] = (float)fparam_1;
  dVar7 = (double)(dVar6 - fparam_1);
  *param_4 = (dVar6 - fparam_1);
  if (param_2 != 2) {
    iVar5 = 2;
    if (2 < param_2) {
      do {
        iVar3 = 1;
        dVar6 = (double)(*param_4 * fparam_1);
        *param_4 = (dVar7 * *param_4);
        if (1 < iVar5) {
          iVar2 = iVar5 + -1;
          iVar4 = iVar3;
          do {
            iVar3 = iVar4 + 1;
            dVar1 = (double)dVar7 * (double)param_4[iVar4] + (double)dVar6;
            dVar6 = (double)(param_4[iVar4] * fparam_1);
            param_4[iVar4] = (float)dVar1;
            iVar2 = iVar2 + -1;
            iVar4 = iVar3;
          } while (iVar2 != 0);
        }
        iVar5 = iVar5 + 1;
        param_4[iVar3] = (float)(double)dVar6;
      } while (iVar5 < param_2);
      return;
    }
    return;
  }
  return;
}

/* _glePreEvaluateWithDeriv @ 0xdda70 (356 bytes) */
void _glePreEvaluateWithDeriv(undefined4 param_1,int param_2,undefined4 param_3,float *param_4,float *param_5,float fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
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
  
  fVar2 = (FLOAT_00108e54 - fparam_1);
  dVar9 = (double)fVar2;
  if (param_2 == 1) {
    *param_4 = FLOAT_00108e54;
    *param_5 = 0.0;
    return;
  }
  if (param_2 == 2) {
    param_5[1] = FLOAT_00108e54;
    *param_5 = -1.0;
    param_4[1] = (float)fparam_1;
    *param_4 = fVar2;
    return;
  }
  iVar5 = param_2 + -1;
  iVar8 = 2;
  *param_4 = fVar2;
  param_4[1] = (float)fparam_1;
  if (2 < iVar5) {
    do {
      iVar4 = 1;
      dVar10 = (double)(*param_4 * fparam_1);
      *param_4 = (dVar9 * *param_4);
      if (1 < iVar8) {
        iVar3 = iVar8 + -1;
        iVar6 = iVar4;
        do {
          iVar4 = iVar6 + 1;
          dVar1 = (double)dVar9 * (double)param_4[iVar6] + (double)dVar10;
          dVar10 = (double)(param_4[iVar6] * fparam_1);
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
  dVar10 = (double)(*param_4 * fparam_1);
  *param_4 = (dVar9 * *param_4);
  if (1 < iVar8) {
    iVar8 = iVar8 + -1;
    iVar5 = iVar4;
    do {
      iVar4 = iVar5 + 1;
      dVar1 = (double)dVar9 * (double)param_4[iVar5] + (double)dVar10;
      dVar10 = (double)(param_4[iVar5] * fparam_1);
      param_4[iVar5] = (float)dVar1;
      iVar8 = iVar8 + -1;
      iVar5 = iVar4;
    } while (iVar8 != 0);
  }
  param_4[iVar4] = (float)(double)dVar10;
  return;
}

/* _gleEvalDomain1Color @ 0xddbd4 (244 bytes) */
void _gleEvalDomain1Color(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  double in_stack_ffffff98;
  double in_stack_ffffffa0;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  
  if (((double)_uvalue_c != fparam_1) || (_uorder_c != param_3)) {
    ((void (*)())_glePreEvaluate)(param_1,param_3,param_3,&_ucoeff_c,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                    fparam_6,fparam_7,fparam_8,in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8
                    ,in_stack_ffffffb0,in_stack_ffffffb8);
    _uvalue_c = (float)fparam_1;
    _utype_c = 2;
    _uorder_c = param_3;
  }
  iVar6 = 0;
  if (0 < param_5) {
    do {
      iVar3 = iVar6 * 4;
      *(undefined4 *)(param_6 + iVar3) = 0;
      pfVar4 = (float *)(param_2 + iVar3);
      if (0 < param_3) {
        pfVar5 = (float *)&_ucoeff_c;
        iVar7 = param_3;
        do {
          fVar1 = *pfVar5;
          pfVar5 = pfVar5 + 1;
          fVar2 = *pfVar4;
          pfVar4 = pfVar4 + param_5;
          *(float *)(param_6 + iVar3) = fVar1 * fVar2 + *(float *)(param_6 + iVar3);
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_5);
  }
  return;
}

/* _gleEvalDomain1Coord @ 0xddcc8 (244 bytes) */
void _gleEvalDomain1Coord(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  double in_stack_ffffff98;
  double in_stack_ffffffa0;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  
  if (((double)_uvalue_c != fparam_1) || (_uorder_c != param_3)) {
    ((void (*)())_glePreEvaluate)(param_1,param_3,param_3,&_ucoeff_c,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                    fparam_6,fparam_7,fparam_8,in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8
                    ,in_stack_ffffffb0,in_stack_ffffffb8);
    _uvalue_c = (float)fparam_1;
    _utype_c = 2;
    _uorder_c = param_3;
  }
  iVar6 = 0;
  if (0 < param_5) {
    do {
      iVar3 = iVar6 * 4;
      *(undefined4 *)(param_6 + iVar3) = 0;
      pfVar4 = (float *)(param_2 + iVar3);
      if (0 < param_3) {
        pfVar5 = (float *)&_ucoeff_c;
        iVar7 = param_3;
        do {
          fVar1 = *pfVar5;
          pfVar5 = pfVar5 + 1;
          fVar2 = *pfVar4;
          pfVar4 = pfVar4 + param_5;
          *(float *)(param_6 + iVar3) = fVar1 * fVar2 + *(float *)(param_6 + iVar3);
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_5);
  }
  return;
}

/* _gleEvalDomain2Color @ 0xdddbc (420 bytes) */
void _gleEvalDomain2Color(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6,int param_7,int param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  int iVar9;
  double dVar10;
  double in_stack_ffffff88;
  double in_stack_ffffff90;
  double in_stack_ffffff98;
  double in_stack_ffffffa0;
  double in_stack_ffffffa8;
  
  iVar6 = param_3;
  dVar10 = fparam_2;
  if (((double)_uvalue_c != fparam_1) || (_uorder_c != param_3)) {
    ((void (*)())_glePreEvaluate)(param_1,param_3,param_3,&_ucoeff_c,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                    fparam_6,fparam_7,fparam_8,in_stack_ffffff88,in_stack_ffffff90,in_stack_ffffff98
                    ,in_stack_ffffffa0,in_stack_ffffffa8);
    _uvalue_c = (float)fparam_1;
    _utype_c = 2;
    _uorder_c = param_3;
  }
  if (((double)_vvalue_c != fparam_2) || (_vorder_c != param_4)) {
    ((void (*)())_glePreEvaluate)(param_1,param_4,iVar6,&_vcoeff_c,fparam_2,dVar10,fparam_3,fparam_4,fparam_5,
                    fparam_6,fparam_7,fparam_8,in_stack_ffffff88,in_stack_ffffff90,in_stack_ffffff98
                    ,in_stack_ffffffa0,in_stack_ffffffa8);
    _vvalue_c = (float)fparam_2;
    _vtype_c = 2;
    _vorder_c = param_4;
  }
  iVar6 = 0;
  if (0 < param_7) {
    do {
      iVar3 = iVar6 * 4;
      *(undefined4 *)(iVar3 + param_8) = 0;
      pfVar8 = (float *)(param_2 + iVar3);
      if (0 < param_3) {
        pfVar7 = (float *)&_ucoeff_c;
        iVar4 = param_3;
        do {
          fVar1 = *pfVar8;
          pfVar8 = pfVar8 + param_7;
          fVar1 = _vcoeff_c * fVar1;
          if (1 < param_4) {
            iVar9 = param_4 + -1;
            pfVar5 = &_vcoeff_c;
            do {
              pfVar5 = pfVar5 + 1;
              fVar2 = *pfVar8;
              pfVar8 = pfVar8 + param_7;
              fVar1 = *pfVar5 * fVar2 + fVar1;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
          fVar2 = *pfVar7;
          iVar4 = iVar4 + -1;
          pfVar7 = pfVar7 + 1;
          *(float *)(iVar3 + param_8) = fVar2 * fVar1 + *(float *)(iVar3 + param_8);
        } while (iVar4 != 0);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_7);
  }
  return;
}

/* _gleEvalDomain2Coord @ 0xddf60 (420 bytes) */
void _gleEvalDomain2Coord(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6,int param_7,int param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  int iVar9;
  double dVar10;
  double in_stack_ffffff88;
  double in_stack_ffffff90;
  double in_stack_ffffff98;
  double in_stack_ffffffa0;
  double in_stack_ffffffa8;
  
  iVar6 = param_3;
  dVar10 = fparam_2;
  if (((double)_uvalue_c != fparam_1) || (_uorder_c != param_3)) {
    ((void (*)())_glePreEvaluate)(param_1,param_3,param_3,&_ucoeff_c,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                    fparam_6,fparam_7,fparam_8,in_stack_ffffff88,in_stack_ffffff90,in_stack_ffffff98
                    ,in_stack_ffffffa0,in_stack_ffffffa8);
    _uvalue_c = (float)fparam_1;
    _utype_c = 2;
    _uorder_c = param_3;
  }
  if (((double)_vvalue_c != fparam_2) || (_vorder_c != param_4)) {
    ((void (*)())_glePreEvaluate)(param_1,param_4,iVar6,&_vcoeff_c,fparam_2,dVar10,fparam_3,fparam_4,fparam_5,
                    fparam_6,fparam_7,fparam_8,in_stack_ffffff88,in_stack_ffffff90,in_stack_ffffff98
                    ,in_stack_ffffffa0,in_stack_ffffffa8);
    _vvalue_c = (float)fparam_2;
    _vtype_c = 2;
    _vorder_c = param_4;
  }
  iVar6 = 0;
  if (0 < param_7) {
    do {
      iVar3 = iVar6 * 4;
      *(undefined4 *)(iVar3 + param_8) = 0;
      pfVar8 = (float *)(param_2 + iVar3);
      if (0 < param_3) {
        pfVar7 = (float *)&_ucoeff_c;
        iVar4 = param_3;
        do {
          fVar1 = *pfVar8;
          pfVar8 = pfVar8 + param_7;
          fVar1 = _vcoeff_c * fVar1;
          if (1 < param_4) {
            iVar9 = param_4 + -1;
            pfVar5 = &_vcoeff_c;
            do {
              pfVar5 = pfVar5 + 1;
              fVar2 = *pfVar8;
              pfVar8 = pfVar8 + param_7;
              fVar1 = *pfVar5 * fVar2 + fVar1;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
          fVar2 = *pfVar7;
          iVar4 = iVar4 + -1;
          pfVar7 = pfVar7 + 1;
          *(float *)(iVar3 + param_8) = fVar2 * fVar1 + *(float *)(iVar3 + param_8);
        } while (iVar4 != 0);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_7);
  }
  return;
}

/* _gleEvalDomainDeriv2Coord @ 0xde104 (572 bytes) */
void _gleEvalDomainDeriv2Coord(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6,int param_7,int param_8,int param_9,int param_10,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
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
  double dVar13;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  double in_stack_ffffff88;
  double in_stack_ffffff90;
  double in_stack_ffffff98;
  
  iVar12 = param_3;
  dVar13 = fparam_2;
  if ((((double)_uvalue_c != fparam_1) || (_utype_c != 1)) || (_uorder_c != param_3)) {
    ((void (*)())_glePreEvaluateWithDeriv)(param_1,param_3,param_3,&_ucoeff_c,&_ucoeffDeriv_c,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff78,in_stack_ffffff80,
               in_stack_ffffff88,in_stack_ffffff90,in_stack_ffffff98);
    _utype_c = 1;
    _uvalue_c = (float)fparam_1;
    _uorder_c = param_3;
  }
  if ((((double)_vvalue_c != fparam_2) || (_vtype_c != 1)) || (_vorder_c != param_4)) {
    ((void (*)())_glePreEvaluateWithDeriv)(param_1,param_4,iVar12,&_vcoeff_c,&_vcoeffDeriv_c,fparam_2,dVar13,fparam_3,fparam_4,
               fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff78,in_stack_ffffff80,
               in_stack_ffffff88,in_stack_ffffff90,in_stack_ffffff98);
    _vtype_c = 1;
    _vvalue_c = (float)fparam_2;
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
          fVar5 = _vcoeffDeriv_c * fVar1;
          fVar1 = _vcoeff_c * fVar1;
          if (1 < param_4) {
            do {
              iVar11 = iVar10 + 1;
              fVar2 = *pfVar9;
              pfVar9 = pfVar9 + param_7;
              fVar5 = (&_vcoeffDeriv_c)[iVar10] * fVar2 + fVar5;
              fVar1 = (&_vcoeff_c)[iVar10] * fVar2 + fVar1;
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
void _gleMap1Vertex3dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,int param_8,int *param_9,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  
  iVar2 = 0;
  dVar4 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_9 = param_7;
  param_9[1] = (int)GH_F2U((float)fparam_1);
  param_9[3] = (int)GH_F2U((float)dVar4);
  param_9[2] = (int)GH_F2U((float)fparam_2);
  if (0 < param_7) {
    do {
      iVar1 = iVar2 * 8;
      iVar2 = iVar2 + param_6;
      iVar3 = iVar1 + param_8;
      param_9[4] = (int)GH_F2U((float)*(double *)(iVar1 + param_8));
      param_9[5] = (int)GH_F2U((float)*(double *)(iVar3 + 8));
      param_9[6] = (int)GH_F2U((float)*(double *)(iVar3 + 0x10));
      param_9 = param_9 + 3;
      param_7 = param_7 + -1;
    } while (param_7 != 0);
    return;
  }
  return;
}

