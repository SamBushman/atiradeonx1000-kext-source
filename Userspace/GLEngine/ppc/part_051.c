#include "decls.h"

/* _gleInsertPixel_A_Short @ 0xea224 (52 bytes) */
void _gleInsertPixel_A_Short(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  *param_2 = (short)(int)(*(float *)(param_1 + 0x10) * FLOAT_00108f74);
  return;
}

/* _gleInsertPixel_A_Ushort @ 0xea258 (52 bytes) */
void _gleInsertPixel_A_Ushort(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  *param_2 = (short)(int)(*(float *)(param_1 + 0x10) * FLOAT_00108ea0);
  return;
}

/* _gleInsertPixel_A_Int @ 0xea28c (52 bytes) */
void _gleInsertPixel_A_Int(param_1, param_2)
  int param_1;
  int *param_2;
{
  *param_2 = (int)((double)*(float *)(param_1 + 0x10) * DOUBLE_00108d90);
  return;
}

/* _gleInsertPixel_A_Uint @ 0xea2c0 (96 bytes) */
void _gleInsertPixel_A_Uint(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  double dVar2;
  
  dVar2 = (double)*(float *)(param_1 + 0x10) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar2) {
    uVar1 = (int)(dVar2 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar1 = (uint)(int)dVar2;
  }
  *param_2 = uVar1;
  return;
}

/* _gleInsertPixel_A_Float @ 0xea320 (12 bytes) */
void _gleInsertPixel_A_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *param_2 = *(undefined4 *)(param_1 + 0x10);
  return;
}

/* _gleInsertPixel_L_Byte @ 0xea32c (52 bytes) */
void _gleInsertPixel_L_Byte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  *param_2 = (char)(int)(*(float *)(param_1 + 4) * FLOAT_00108f6c);
  return;
}

/* _gleInsertPixel_L_Ubyte @ 0xea360 (52 bytes) */
void _gleInsertPixel_L_Ubyte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  *param_2 = (char)(int)(*(float *)(param_1 + 4) * FLOAT_00108f70);
  return;
}

/* _gleInsertPixel_L_Short @ 0xea394 (52 bytes) */
void _gleInsertPixel_L_Short(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  *param_2 = (short)(int)(*(float *)(param_1 + 4) * FLOAT_00108f74);
  return;
}

/* _gleInsertPixel_L_Ushort @ 0xea3c8 (52 bytes) */
void _gleInsertPixel_L_Ushort(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  *param_2 = (short)(int)(*(float *)(param_1 + 4) * FLOAT_00108ea0);
  return;
}

/* _gleInsertPixel_L_Int @ 0xea3fc (52 bytes) */
void _gleInsertPixel_L_Int(param_1, param_2)
  int param_1;
  int *param_2;
{
  *param_2 = (int)((double)*(float *)(param_1 + 4) * DOUBLE_00108d90);
  return;
}

/* _gleInsertPixel_L_Uint @ 0xea430 (96 bytes) */
void _gleInsertPixel_L_Uint(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  double dVar2;
  
  dVar2 = (double)*(float *)(param_1 + 4) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar2) {
    uVar1 = (int)(dVar2 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar1 = (uint)(int)dVar2;
  }
  *param_2 = uVar1;
  return;
}

/* _gleInsertPixel_L_Float @ 0xea490 (12 bytes) */
void _gleInsertPixel_L_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *param_2 = *(undefined4 *)(param_1 + 4);
  return;
}

/* _gleInsertPixel_LA_Byte @ 0xea49c (76 bytes) */
void _gleInsertPixel_LA_Byte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f6c;
  *param_2 = (char)(int)(*(float *)(param_1 + 4) * FLOAT_00108f6c);
  param_2[1] = (char)(int)(*(float *)(param_1 + 0x10) * fVar1);
  return;
}

/* _gleInsertPixel_LA_Ubyte @ 0xea4e8 (76 bytes) */
void _gleInsertPixel_LA_Ubyte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f70;
  *param_2 = (char)(int)(*(float *)(param_1 + 4) * FLOAT_00108f70);
  param_2[1] = (char)(int)(*(float *)(param_1 + 0x10) * fVar1);
  return;
}

/* _gleInsertPixel_LA_Short @ 0xea534 (76 bytes) */
void _gleInsertPixel_LA_Short(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f74;
  *param_2 = (short)(int)(*(float *)(param_1 + 4) * FLOAT_00108f74);
  param_2[1] = (short)(int)(*(float *)(param_1 + 0x10) * fVar1);
  return;
}

/* _gleInsertPixel_LA_Ushort @ 0xea580 (76 bytes) */
void _gleInsertPixel_LA_Ushort(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108ea0;
  *param_2 = (short)(int)(*(float *)(param_1 + 4) * FLOAT_00108ea0);
  param_2[1] = (short)(int)(*(float *)(param_1 + 0x10) * fVar1);
  return;
}

/* _gleInsertPixel_LA_Int @ 0xea5cc (76 bytes) */
void _gleInsertPixel_LA_Int(param_1, param_2)
  int param_1;
  int *param_2;
{
  double dVar1;
  
  dVar1 = DOUBLE_00108d90;
  *param_2 = (int)((double)*(float *)(param_1 + 4) * DOUBLE_00108d90);
  param_2[1] = (int)((double)*(float *)(param_1 + 0x10) * dVar1);
  return;
}

/* _gleInsertPixel_LA_Uint @ 0xea618 (168 bytes) */
void _gleInsertPixel_LA_Uint(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  double dVar2;
  
  dVar2 = (double)*(float *)(param_1 + 4) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar2) {
    uVar1 = (int)(dVar2 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar1 = (uint)(int)dVar2;
  }
  *param_2 = uVar1;
  dVar2 = (double)*(float *)(param_1 + 0x10) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar2) {
    uVar1 = (int)(dVar2 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar1 = (uint)(int)dVar2;
  }
  param_2[1] = uVar1;
  return;
}

/* _gleInsertPixel_LA_Float @ 0xea6c0 (20 bytes) */
void _gleInsertPixel_LA_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *param_2 = *(undefined4 *)(param_1 + 4);
  param_2[1] = *(undefined4 *)(param_1 + 0x10);
  return;
}

/* _gleInsertPixel_Index_Byte @ 0xea6d4 (12 bytes) */
void _gleInsertPixel_Index_Byte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  *param_2 = *(undefined1 *)(param_1 + 0x1b);
  return;
}

/* _gleInsertPixel_Index_Ubyte @ 0xea6e0 (12 bytes) */
void _gleInsertPixel_Index_Ubyte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  *param_2 = *(undefined1 *)(param_1 + 0x1b);
  return;
}

/* _gleInsertPixel_Index_Short @ 0xea6ec (12 bytes) */
void _gleInsertPixel_Index_Short(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  *param_2 = *(undefined2 *)(param_1 + 0x1a);
  return;
}

/* _gleInsertPixel_Index_Ushort @ 0xea6f8 (12 bytes) */
void _gleInsertPixel_Index_Ushort(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  *param_2 = *(undefined2 *)(param_1 + 0x1a);
  return;
}

/* _gleInsertPixel_Index_Int @ 0xea704 (12 bytes) */
void _gleInsertPixel_Index_Int(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *param_2 = *(undefined4 *)(param_1 + 0x18);
  return;
}

/* _gleInsertPixel_Index_Uint @ 0xea710 (12 bytes) */
void _gleInsertPixel_Index_Uint(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *param_2 = *(undefined4 *)(param_1 + 0x18);
  return;
}

/* _gleInsertPixel_Index_Float @ 0xea71c (104 bytes) */
void _gleInsertPixel_Index_Float(param_1, param_2)
  int param_1;
  float *param_2;
{
  *param_2 = (float)((double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x1c) ^ 0x80000000) -
                    DOUBLE_00108d58) * FLOAT_00108f78 +
             (float)((double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x18) ^ 0x80000000) -
                    DOUBLE_00108d58);
  return;
}

/* _gleInsertPixel_Depth_Byte @ 0xea784 (52 bytes) */
void _gleInsertPixel_Depth_Byte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  *param_2 = (char)(int)(*(float *)(param_1 + 0x14) * FLOAT_00108f6c);
  return;
}

/* _gleInsertPixel_Depth_Ubyte @ 0xea7b8 (52 bytes) */
void _gleInsertPixel_Depth_Ubyte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  *param_2 = (char)(int)(*(float *)(param_1 + 0x14) * FLOAT_00108f70);
  return;
}

/* _gleInsertPixel_Depth_Short @ 0xea7ec (52 bytes) */
void _gleInsertPixel_Depth_Short(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  *param_2 = (short)(int)(*(float *)(param_1 + 0x14) * FLOAT_00108f74);
  return;
}

/* _gleInsertPixel_Depth_Ushort @ 0xea820 (52 bytes) */
void _gleInsertPixel_Depth_Ushort(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  *param_2 = (short)(int)(*(float *)(param_1 + 0x14) * FLOAT_00108ea0);
  return;
}

/* _gleInsertPixel_Depth_Int @ 0xea854 (52 bytes) */
void _gleInsertPixel_Depth_Int(param_1, param_2)
  int param_1;
  int *param_2;
{
  *param_2 = (int)((double)*(float *)(param_1 + 0x14) * DOUBLE_00108d90);
  return;
}

/* _gleInsertPixel_Depth_Uint @ 0xea888 (96 bytes) */
void _gleInsertPixel_Depth_Uint(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  double dVar2;
  
  dVar2 = (double)*(float *)(param_1 + 0x14) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar2) {
    uVar1 = (int)(dVar2 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar1 = (uint)(int)dVar2;
  }
  *param_2 = uVar1;
  return;
}

/* _gleInsertPixel_Depth_Float @ 0xea8e8 (12 bytes) */
void _gleInsertPixel_Depth_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *param_2 = *(undefined4 *)(param_1 + 0x14);
  return;
}

/* _gleBeginPointsRender @ 0xea8f4 (52 bytes) */
void _gleBeginPointsRender(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushAtomicFunc_00112224;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderPointsFunc_00112240;
  return;
}

/* _gleBeginPointsRenderTCL @ 0xea928 (52 bytes) */
void _gleBeginPointsRenderTCL(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushAtomicTCLFunc_00112218;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderPointsTCLFunc_0011223c;
  return;
}

/* _gleBeginPointsRenderTCLRDirty @ 0xea95c (60 bytes) */
void _gleBeginPointsRenderTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR__gleRenderPointsTCLFunc_0011223c;
  puVar1 = PTR__gleFlushAtomicTCLRDirtyFunc_00112210;
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = puVar2;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleBeginPointsSelectFeedback @ 0xea998 (76 bytes) */
void _gleBeginPointsSelectFeedback(param_1)
  int param_1;
{
  undefined *puVar1;
  
  *(undefined **)(param_1 + 0x4a0c) = PTR__gleFlushAtomicFunc_00112224;
  puVar1 = PTR__gleFeedbackPointsFunc_00112234;
  if (*(int *)(param_1 + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectPointsFunc_00112238;
  }
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleClipPoints @ 0xea9e4 (76 bytes) */
int _gleClipPoints(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  int param_3;
  uint *param_4;
{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = param_2 + param_3 * 0x100;
  puVar2 = param_4;
  if (param_2 < uVar1) {
    uVar1 = (uVar1 - param_2) + 0xff >> 8;
    do {
      if (*(char *)(param_2 + 0x7f) == '\0') {
        *puVar2 = param_2;
        puVar2 = puVar2 + 1;
      }
      param_2 = param_2 + 0x100;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return (int)puVar2 - (int)param_4 >> 2;
}

/* _gleClipPointsPlane @ 0xeaa30 (244 bytes) */
int _gleClipPointsPlane(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  
  fVar5 = FLOAT_00108e50;
  iVar7 = 0;
  iVar11 = *(int *)(param_1 + 0x4dfc);
  if ((0 < iVar11) && (0 < param_3)) {
    piVar8 = (int *)(param_1 + 0x4e00);
    do {
      iVar6 = *piVar8;
      piVar8 = piVar8 + 1;
      iVar6 = param_1 + iVar6 * 0x10;
      fVar1 = *(float *)(iVar6 + 0x418c);
      fVar2 = *(float *)(iVar6 + 0x4198);
      fVar3 = *(float *)(iVar6 + 0x4190);
      fVar4 = *(float *)(iVar6 + 0x4194);
      piVar9 = param_2;
      if (param_2 < param_2 + param_3) {
        uVar12 = (uint)((int)(param_2 + param_3) + (3 - (int)param_2)) >> 2;
        piVar10 = param_2;
        do {
          iVar6 = *piVar10;
          if (fVar5 <= *(float *)(iVar6 + 0x2c) * fVar2 +
                       (*(float *)(iVar6 + 0x28) * fVar4 +
                       (*(float *)(iVar6 + 0x20) * fVar1 + *(float *)(iVar6 + 0x24) * fVar3))) {
            *piVar9 = iVar6;
            piVar9 = piVar9 + 1;
          }
          piVar10 = piVar10 + 1;
          uVar12 = uVar12 - 1;
        } while (uVar12 != 0);
      }
      iVar7 = iVar7 + 1;
      param_3 = (int)piVar9 - (int)param_2 >> 2;
    } while ((iVar7 < iVar11) && (0 < param_3));
  }
  return param_3;
}

/* FUN_000eab28 @ 0xeab28 (700 bytes) */
void FUN_000eab28(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  
  bVar1 = false;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar1 = true;
  }
  uVar6 = *(uint *)(param_1 + 0x4854);
  if (((int)*(short *)(param_1 + 0x487c) != 0) &&
     (uVar7 = (*(int *)(param_1 + 0x4858) - uVar6) / (uint)(int)*(short *)(param_1 + 0x487c),
     0 < (int)uVar7)) {
    bVar1 = !bVar1;
    if (bVar1) {
      uVar2 = (**(code **)(param_1 + 0x5060))(param_1,uVar6,uVar7);
    }
    else {
      uVar2 = _gleVPEmulate(param_1,uVar7);
    }
    if ((uVar2 & 0xff00) == 0) {
      if (bVar1) {
        if (*(char *)(param_1 + 0x53e4) != '\0') {
          (**(code **)(param_1 + 0x53dc))(param_1,uVar6,uVar7);
        }
        if (*(char *)(param_1 + 0x50b4) != '\0') {
          (**(code **)(param_1 + 0x5064))(param_1,uVar6,uVar7);
        }
        if ((*(char *)(param_1 + 0x30aa) != '\0') || (*(char *)(param_1 + 0x53e6) != '\0')) {
          (**(code **)(param_1 + 0x5068))(param_1,uVar6,uVar7);
        }
      }
      else {
        uVar6 = *(uint *)(param_1 + 0x4864);
      }
      if (((uVar2 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
        if ((bVar1) && (*(char *)(param_1 + 0x53e5) != '\0')) {
          (**(code **)(param_1 + 0x53e0))(param_1,uVar6,uVar7);
        }
        (**(code **)(param_1 + 0x506c))(param_1,uVar6,uVar7,0);
        if ((bVar1) && (*(char *)(param_1 + 0x30aa) != '\0')) {
          (**(code **)(param_1 + 0x4de8))(param_1,uVar6,uVar7);
        }
        uVar7 = uVar6 + uVar7 * 0x100;
        for (; uVar6 < uVar7; uVar6 = uVar6 + 0x100) {
          ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f28);
          _gleFeedbackHitRecord(param_1,uVar6);
        }
        return;
      }
      if ((bVar1) && (*(char *)(param_1 + 0x53e5) != '\0')) {
        (**(code **)(param_1 + 0x53e0))(param_1,uVar6,uVar7);
      }
      (**(code **)(param_1 + 0x5074))(param_1,uVar6,uVar7,0);
      puVar4 = *(undefined4 **)(param_1 + 0x4870);
      iVar3 = ((int (*)())_gleClipPoints)(param_1,uVar6,uVar7,puVar4);
      if ((iVar3 != 0) &&
         ((*(char *)(param_1 + 0x4e18) == '\0' ||
          (iVar3 = ((int (*)())_gleClipPointsPlane)(param_1,puVar4,iVar3), iVar3 != 0)))) {
        if ((bVar1) && (*(char *)(param_1 + 0x30aa) != '\0')) {
          (**(code **)(param_1 + 0x4df0))(param_1,puVar4,iVar3);
        }
        puVar5 = puVar4 + iVar3;
        for (; puVar4 < puVar5; puVar4 = puVar4 + 1) {
          ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f28);
          _gleFeedbackHitRecord(param_1,*puVar4);
        }
        return;
      }
    }
  }
  return;
}

/* FUN_000eae0c @ 0xeae0c (620 bytes) */
void FUN_000eae0c(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  code *UNRECOVERED_JUMPTABLE;
  int iVar5;
  int iVar6;
  
  iVar2 = _gleTexEnableBits(param_1);
  iVar5 = *(int *)(param_1 + 0x4854);
  iVar6 = *(int *)(param_1 + 0x4858) - iVar5 >> 8;
  if ((iVar6 < 1) ||
     (uVar3 = (**(code **)(param_1 + 0x5060))(param_1,iVar5,iVar6), (uVar3 & 0xff00) != 0)) {
    return;
  }
  bVar1 = iVar2 != 0;
  if ((bVar1) && (*(char *)(param_1 + 0x53e4) != '\0')) {
    (**(code **)(param_1 + 0x53dc))(param_1,iVar5,iVar6);
  }
  if (*(char *)(param_1 + 0x50b4) != '\0') {
    (**(code **)(param_1 + 0x5064))(param_1,iVar5,iVar6);
  }
  if ((*(char *)(param_1 + 0x30aa) != '\0') || (*(char *)(param_1 + 0x53e6) != '\0')) {
    (**(code **)(param_1 + 0x5068))(param_1,iVar5,iVar6);
  }
  if (((uVar3 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
    if (bVar1) {
      if (*(char *)(param_1 + 0x53e5) != '\0') {
        (**(code **)(param_1 + 0x53e0))(param_1,iVar5,iVar6);
      }
      (**(code **)(param_1 + 0x506c))(param_1,iVar5,iVar6,0);
    }
    if (*(char *)(param_1 + 0x30aa) != '\0') {
      (**(code **)(param_1 + 0x4de8))(param_1,iVar5,iVar6);
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x46b0);
    uVar4 = *(undefined4 *)(param_1 + 0x4688);
    iVar2 = iVar5;
  }
  else {
    if (bVar1) {
      if (*(char *)(param_1 + 0x53e5) != '\0') {
        (**(code **)(param_1 + 0x53e0))(param_1,iVar5,iVar6);
      }
      (**(code **)(param_1 + 0x5074))(param_1,iVar5,iVar6,0);
    }
    iVar2 = *(int *)(param_1 + 0x4870);
    iVar6 = ((int (*)())_gleClipPoints)(param_1,iVar5,iVar6,iVar2);
    if (iVar6 == 0) {
      return;
    }
    if ((*(char *)(param_1 + 0x4e18) != '\0') &&
       (iVar6 = ((int (*)())_gleClipPointsPlane)(param_1,iVar2,iVar6), iVar6 == 0)) {
      return;
    }
    if (*(char *)(param_1 + 0x30aa) != '\0') {
      (**(code **)(param_1 + 0x4df0))(param_1,iVar2,iVar6);
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x46d8);
    uVar4 = *(undefined4 *)(param_1 + 0x4688);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(uVar4,iVar2,iVar6);
  return;
}

/* _gleSelectPointsFunc @ 0xeb078 (352 bytes) */
void _gleSelectPointsFunc(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  bVar1 = false;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar1 = true;
  }
  iVar4 = *(int *)(param_1 + 0x4854);
  if (((int)*(short *)(param_1 + 0x487c) != 0) &&
     (uVar5 = (uint)(*(int *)(param_1 + 0x4858) - iVar4) / (uint)(int)*(short *)(param_1 + 0x487c),
     0 < (int)uVar5)) {
    uVar2 = (**(code **)(param_1 + 0x5060))(param_1,iVar4,uVar5);
    if ((uVar2 & 0xff00) == 0) {
      if (bVar1) {
        iVar4 = *(int *)(param_1 + 0x4864);
      }
      else if (*(char *)(param_1 + 0x4e18) != '\0') {
        (**(code **)(param_1 + 0x5064))(param_1,iVar4,uVar5);
      }
      if (((uVar2 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
        _gleSelectPoints(param_1,iVar4,uVar5);
        return;
      }
      uVar3 = *(undefined4 *)(param_1 + 0x4870);
      iVar4 = ((int (*)())_gleClipPoints)(param_1,iVar4,uVar5,uVar3);
      if ((iVar4 != 0) &&
         ((*(char *)(param_1 + 0x4e18) == '\0' ||
          (iVar4 = ((int (*)())_gleClipPointsPlane)(param_1,uVar3,iVar4), iVar4 != 0)))) {
        _gleSelectPointsPtr(param_1,uVar3,iVar4);
        return;
      }
    }
  }
  return;
}

/* _glePolyArea @ 0xeb1d8 (128 bytes) */
double _glePolyArea(undefined4 param_1,float *param_2,int param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  uint uVar9;
  
  pfVar8 = param_2 + 0x40;
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar4 = fVar2;
  fVar3 = fVar1;
  fVar7 = FLOAT_00108e50;
  if (pfVar8 < param_2 + param_3 * 0x40) {
    uVar9 = (uint)((int)(param_2 + param_3 * 0x40) + (0xff - (int)pfVar8)) >> 8;
    fVar5 = fVar2;
    fVar6 = fVar1;
    do {
      fVar3 = *pfVar8;
      fVar4 = pfVar8[1];
      pfVar8 = pfVar8 + 0x40;
      fVar7 = fVar7 + ((fVar6 * fVar4 - fVar3 * fVar5));
      uVar9 = uVar9 - 1;
      fVar5 = fVar4;
      fVar6 = fVar3;
    } while (uVar9 != 0);
  }
  return (double)(fVar7 + ((fVar3 * fVar2 - fVar1 * fVar4)));
}

/* _glePolyAreaPtr @ 0xeb258 (136 bytes) */
double _glePolyAreaPtr(undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  float *pfVar7;
  undefined4 *puVar8;
  uint uVar9;
  
  puVar8 = param_2 + 1;
  pfVar7 = (float *)*param_2;
  fVar1 = *pfVar7;
  fVar2 = pfVar7[1];
  fVar3 = FLOAT_00108e50;
  if (puVar8 < param_2 + param_3) {
    uVar9 = (uint)((int)(param_2 + param_3) + (3 - (int)puVar8)) >> 2;
    fVar4 = fVar1;
    fVar5 = fVar2;
    do {
      pfVar6 = (float *)*puVar8;
      puVar8 = puVar8 + 1;
      fVar1 = *pfVar6;
      fVar2 = pfVar6[1];
      fVar3 = fVar3 + ((fVar4 * fVar2 - fVar1 * fVar5));
      uVar9 = uVar9 - 1;
      fVar4 = fVar1;
      fVar5 = fVar2;
    } while (uVar9 != 0);
  }
  return (double)(fVar3 + ((fVar1 * pfVar7[1] - *pfVar7 * fVar2)));
}

/* _gleBeginTrianglesRenderSmooth @ 0xeb2e0 (52 bytes) */
void _gleBeginTrianglesRenderSmooth(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushAtomicFunc_00112224;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderSmoothTrianglesFunc_001122dc;
  return;
}

/* _gleBeginTrianglesRenderFlat @ 0xeb314 (52 bytes) */
void _gleBeginTrianglesRenderFlat(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushAtomicFunc_00112224;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderFlatTrianglesFunc_001122d8;
  return;
}

/* _gleBeginTrianglesRenderTCL @ 0xeb348 (52 bytes) */
void _gleBeginTrianglesRenderTCL(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushAtomicTCLFunc_00112218;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderTrianglesTCLFunc_001122d4;
  return;
}

/* _gleBeginTrianglesRenderTCLRDirty @ 0xeb37c (60 bytes) */
void _gleBeginTrianglesRenderTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR__gleRenderTrianglesTCLFunc_001122d4;
  puVar1 = PTR__gleFlushAtomicTCLRDirtyFunc_00112210;
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = puVar2;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleBeginTrianglesSelectFeedback @ 0xeb3b8 (76 bytes) */
void _gleBeginTrianglesSelectFeedback(param_1)
  int param_1;
{
  undefined *puVar1;
  
  *(undefined **)(param_1 + 0x4a0c) = PTR__gleFlushAtomicFunc_00112224;
  puVar1 = PTR__gleFeedbackTrianglesFunc_001122cc;
  if (*(int *)(param_1 + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectTrianglesFunc_001122d0;
  }
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleBeginTriangleStripRenderSmooth @ 0xeb404 (52 bytes) */
void _gleBeginTriangleStripRenderSmooth(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushTriQuadStripFunc_001122c8;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderSmoothTriangleStripFunc_001122c4;
  return;
}

/* _gleBeginTriangleStripRenderFlat @ 0xeb438 (52 bytes) */
void _gleBeginTriangleStripRenderFlat(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushTriQuadStripFunc_001122c8;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderFlatTriangleStripFunc_001122c0;
  return;
}

/* _gleBeginTriangleStripRenderTCL @ 0xeb46c (52 bytes) */
void _gleBeginTriangleStripRenderTCL(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushTriQuadStripTCLFunc_001122bc;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderTriangleStripTCLFunc_001122b8;
  return;
}

/* _gleBeginTriangleStripRenderTCLRDirty @ 0xeb4a0 (60 bytes) */
void _gleBeginTriangleStripRenderTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR__gleRenderTriangleStripTCLFunc_001122b8;
  puVar1 = PTR__gleFlushTriQuadStripTCLRDirtyFunc_001122b4;
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = puVar2;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleBeginTriangleStripSelectFeedback @ 0xeb4dc (76 bytes) */
void _gleBeginTriangleStripSelectFeedback(param_1)
  int param_1;
{
  undefined *puVar1;
  
  *(undefined **)(param_1 + 0x4a0c) = PTR__gleFlushTriQuadStripFunc_001122c8;
  puVar1 = PTR__gleFeedbackTriangleStripFunc_001122ac;
  if (*(int *)(param_1 + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectTriangleStripFunc_001122b0;
  }
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleBeginTriangleFanRenderSmooth @ 0xeb528 (52 bytes) */
void _gleBeginTriangleFanRenderSmooth(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushTriangleFanFunc_001122a8;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderSmoothTriangleFanFunc_001122a4;
  return;
}

/* _gleBeginTriangleFanRenderFlat @ 0xeb55c (52 bytes) */
void _gleBeginTriangleFanRenderFlat(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushTriangleFanFunc_001122a8;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderFlatTriangleFanFunc_001122a0;
  return;
}

/* _gleBeginTriangleFanRenderTCL @ 0xeb590 (52 bytes) */
void _gleBeginTriangleFanRenderTCL(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushTriangleFanTCLFunc_0011229c;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderTriangleFanTCLFunc_00112298;
  return;
}

/* _gleBeginTriangleFanRenderTCLRDirty @ 0xeb5c4 (60 bytes) */
void _gleBeginTriangleFanRenderTCLRDirty(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR__gleRenderTriangleFanTCLFunc_00112298;
  puVar1 = PTR__gleFlushTriangleFanTCLRDirtyFunc_00112294;
  *(undefined4 *)(param_1 + 0x486c) = 0;
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = puVar2;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleBeginTriangleFanSelectFeedback @ 0xeb600 (76 bytes) */
void _gleBeginTriangleFanSelectFeedback(param_1)
  int param_1;
{
  undefined *puVar1;
  
  *(undefined **)(param_1 + 0x4a0c) = PTR__gleFlushTriangleFanFunc_001122a8;
  puVar1 = PTR__gleFeedbackTriangleFanFunc_0011228c;
  if (*(int *)(param_1 + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectTriangleFanFunc_00112290;
  }
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* _gleBeginQuadsRenderSmooth @ 0xeb64c (52 bytes) */
void _gleBeginQuadsRenderSmooth(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushAtomicFunc_00112224;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderSmoothQuadsFunc_00112288;
  return;
}

